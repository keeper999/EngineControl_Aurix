/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQANTISTALLBVM                                          */
/* !Description     : TQANTISTALLBVM component                                */
/*                                                                            */
/* !Module          : TQANTISTALLBVM                                          */
/* !Description     : Anti-calage BVM                                         */
/*                                                                            */
/* !File            : TQANTISTALLBVM_FCT1.C                                   */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / TQANTISTALLBVM_vidInitOutput                                         */
/*   2 / TQANTISTALLBVM_vidAnticalBVM                                         */
/*   3 / TQANTISTALLBVM_vidActivAntical                                       */
/*   4 / TQANTISTALLBVM_vidGestionAntical                                     */
/*   5 / TQANTISTALLBVM_vidSeuilsActiv                                        */
/*   6 / TQANTISTALLBVM_vidSigActivFrein                                      */
/*   7 / TQANTISTALLBVM_vidAutActAntiCal                                      */
/*   8 / TQANTISTALLBVM_vidConditionActiv                                     */
/*   9 / TQANTISTALLBVM_vidInhibAntical                                       */
/*                                                                            */
/* !Reference   : V02 NT 10 04974 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_2609 / 2.1                                      */
/* !OtherRefs   : VEMS V02 ECU#050078                                         */
/* !OtherRefs   : VEMS V02 ECU#054080                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQANTISTALLBVM/TQ$*/
/* $Revision::   1.6      $$Author::   etsasson       $$Date::   28 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQANTISTALLBVM.h"
#include "TQANTISTALLBVM_L.h"
#include "TQANTISTALLBVM_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidInitOutput                               */
/* !Description :  Fonction qui initialise les sorties                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TreatTDC_nCkGrd;                                             */
/*  input sint16 IdlSys_nGrdAntiStall_MP;                                     */
/*  output boolean IdlSys_bAcvAntiStall;                                      */
/*  output boolean IdlSys_bEnaAntiStall;                                      */
/*  output boolean IdlSys_bAcvAntiStallPrev;                                  */
/*  output boolean TQANTISTALLBVM_bTOffDlyBrkInPrev;                          */
/*  output boolean TQANTISTALLBVM_bTOffDlyAutInPrev;                          */
/*  output uint8 IdlSys_ctTestAcvAntiStall;                                   */
/*  output uint16 IdlSys_nDifAcvAntiStall;                                    */
/*  output sint16 IdlSys_nGrdAntiStall_MP;                                    */
/*  output sint32 TQANTISTALLBVM_s32FilterMem;                                */
/*  output uint16 TQANTISTALLBVM_u16TOffDlyBrkCnt;                            */
/*  output boolean IdlSys_bInhBrkAntiStall;                                   */
/*  output uint16 TQANTISTALLBVM_u16TOffDlyAuthCnt;                           */
/*  output boolean IdlSys_bDlyAuthAntiStall;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidInitOutput(void)
{
   sint16 s16LocalTreatTDC_nCkGrd;


   /* Outputs initialization */
   VEMS_vidSET(IdlSys_bAcvAntiStall, 0);
   VEMS_vidSET(IdlSys_bEnaAntiStall, 0);

   /* Previous values initilaization */
   IdlSys_bAcvAntiStallPrev = 0;
   TQANTISTALLBVM_bTOffDlyBrkInPrev = 0;
   TQANTISTALLBVM_bTOffDlyAutInPrev = 0;

   /* State machine Variables initialization */
   IdlSys_ctTestAcvAntiStall = 0;
   IdlSys_nDifAcvAntiStall = 0;

   /* Filter Output's initialization */
   VEMS_vidGET(TreatTDC_nCkGrd, s16LocalTreatTDC_nCkGrd);
   IdlSys_nGrdAntiStall_MP = (sint16)MATHSRV_udtCLAMP(s16LocalTreatTDC_nCkGrd,
                                                      -32000,
                                                      32000);
   TQANTISTALLBVM_s32FilterMem = (sint32)(IdlSys_nGrdAntiStall_MP * 65536);

   /* Turn_Off_Delay outputs initialization corresponding to the bloc */
   /* F02_02_Determiner_Signal_Activation_Freinage                    */
   TQANTISTALLBVM_u16TOffDlyBrkCnt = 0;
   IdlSys_bInhBrkAntiStall = 0;

   /* Turn_Off_Delay outputs initialization corresponding to the bloc */
   /* F02_03_Autoriser_Activation_Anti_Calage                         */
   TQANTISTALLBVM_u16TOffDlyAuthCnt = 0;
   IdlSys_bDlyAuthAntiStall = 0;

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidAnticalBVM                               */
/* !Description :  La fonction d’anti-calage ralenti envoie un ordre          */
/*                 d’activation à la gestion de richesse qui permet de prendre*/
/*                 en compte une consigne de richesse spécifique à            */
/*                 l’anti-calage.                                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04974_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQANTISTALLBVM_vidActivAntical();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQANTISTALLBVM_vidGestionAntical();                      */
/*  extf argret void TQANTISTALLBVM_vidInhibAntical();                        */
/*  input boolean IdlSys_bEnaAntiStall;                                       */
/*  input boolean IdlSys_bAcvAntiStall;                                       */
/*  output boolean IdlSys_bAcvAntiStallPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidAnticalBVM(void)
{
   boolean bLocalIdlSys_bEnaAntiStall;
   boolean bLocalIdlSys_bAcvAntiStall;


   TQANTISTALLBVM_vidActivAntical();
   VEMS_vidGET(IdlSys_bEnaAntiStall, bLocalIdlSys_bEnaAntiStall);
   VEMS_vidGET(IdlSys_bAcvAntiStall, bLocalIdlSys_bAcvAntiStall);

   if (bLocalIdlSys_bEnaAntiStall != 0)
   {
      TQANTISTALLBVM_vidGestionAntical();
   }
   else
   {
      TQANTISTALLBVM_vidInhibAntical();
   }
   IdlSys_bAcvAntiStallPrev = bLocalIdlSys_bAcvAntiStall;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidActivAntical                             */
/* !Description :  Fonction permettant le calcul des conditions d'autorisation*/
/*                 de la fonction anti-calage                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04974_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean IdlSys_bEnaIdl;                                             */
/*  input boolean EOM_bTWCHeatPha;                                            */
/*  input boolean IdlSys_bEnaAntiStall;                                       */
/*  input boolean IdlSys_bEnaAntiStall_C;                                     */
/*  output boolean IdlSys_bEnaAntiStall;                                      */
/*  output boolean IdlSys_bIniAntiStall;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidActivAntical(void)
{
   boolean bLocalInhAntiStall;
   boolean bLocalIdlSys_bEnaIdl;
   boolean bLocalEOM_bTWCHeatPha;
   boolean bLocalIdlSys_bEnaAntiStall;
   boolean bLocalIdlSys_bEnaAntiStallPrev;


   bLocalInhAntiStall = GDGAR_bGetFRM(FRM_FRM_INHANTISTALL);
   VEMS_vidGET(IdlSys_bEnaIdl, bLocalIdlSys_bEnaIdl);
   VEMS_vidGET(EOM_bTWCHeatPha, bLocalEOM_bTWCHeatPha);
   VEMS_vidGET(IdlSys_bEnaAntiStall, bLocalIdlSys_bEnaAntiStall);
   bLocalIdlSys_bEnaAntiStallPrev = bLocalIdlSys_bEnaAntiStall;

   if (  (IdlSys_bEnaAntiStall_C != 0)
      && (bLocalIdlSys_bEnaIdl != 0)
      && (bLocalInhAntiStall == 0)
      && (bLocalEOM_bTWCHeatPha == 0))
   {
      bLocalIdlSys_bEnaAntiStall = 1;
   }
   else
   {
      bLocalIdlSys_bEnaAntiStall = 0;
   }
   VEMS_vidSET(IdlSys_bEnaAntiStall, bLocalIdlSys_bEnaAntiStall);

   if (  (bLocalIdlSys_bEnaAntiStallPrev == 0)
      && (bLocalIdlSys_bEnaAntiStall != 0))
   {
      IdlSys_bIniAntiStall = 1;
   }
   else
   {
      IdlSys_bIniAntiStall = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidGestionAntical                           */
/* !Description :  Fonction permettant le calcul des conditions d'activation  */
/*                 de la fonction anti-calage                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04974_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQANTISTALLBVM_vidSeuilsActiv();                         */
/*  extf argret void TQANTISTALLBVM_vidSigActivFrein();                       */
/*  extf argret void TQANTISTALLBVM_vidAutActAntiCal();                       */
/*  extf argret void TQANTISTALLBVM_vidConditionActiv();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidGestionAntical(void)
{
   TQANTISTALLBVM_vidSeuilsActiv();
   TQANTISTALLBVM_vidSigActivFrein();
   TQANTISTALLBVM_vidAutActAntiCal();
   TQANTISTALLBVM_vidConditionActiv();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidSeuilsActiv                              */
/* !Description :  Fonction qui calcule l’offset de régime permettant de      */
/*                 déterminer le seuil de régime d’activation de l’anti-calage*/
/*                 et le nombre de PMH à prendre en compte entre              */
/*                 l’initialisation du test et l’instant où l’on doit activer */
/*                 ou non la stratégie anti-calage.                           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04974_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input sint16 TreatTDC_nCkGrd;                                             */
/*  input uint8 IdlSys_tiFilNGrdAntiStall_C;                                  */
/*  input boolean IdlSys_bIniAntiStall;                                       */
/*  input sint32 TQANTISTALLBVM_s32FilterMem;                                 */
/*  input sint16 IdlSys_nGrdAntiStall_MP;                                     */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint16 IdlSys_nGrdAntiStall_A[12];                                  */
/*  input uint16 IdlSys_nOfsAcvAntiStall_M[12][8];                            */
/*  input uint8 IdlSys_noTDCTestAntiStall_T[8];                               */
/*  output sint32 TQANTISTALLBVM_s32FilterMem;                                */
/*  output sint16 IdlSys_nGrdAntiStall_MP;                                    */
/*  output uint16 IdlSys_nOfsAcvAntiStall;                                    */
/*  output uint8 IdlSys_noTDCTestAntiStall;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidSeuilsActiv(void)
{
   uint8  u8LocalNoTDCTest;
   uint8  u8LocalExt_tiTDC;
   uint8  u8LocalCoPt_noEgdGearCord;
   uint16 u16LocalDen;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16IdlSysnOfsAcvAntiStall;
   uint16 u16LocalIdlSys_nGrdAntiStall;
   uint32 u32LocalNum;
   uint32 u32LocalGain;
   sint16 s16LocalFilterOutput;
   sint16 s16LocalTreatTDC_nCkGrd;


   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET(TreatTDC_nCkGrd, s16LocalTreatTDC_nCkGrd);

   u16LocalDen =
      (uint16)((16 * u8LocalExt_tiTDC) + (IdlSys_tiFilNGrdAntiStall_C * 125));
   u32LocalNum = (uint32)(u8LocalExt_tiTDC * 1048576);

   if (u16LocalDen != 0)
   {
      u32LocalGain = u32LocalNum / u16LocalDen;
   }
   else
   {
      u32LocalGain = 65536;
   }

   if (IdlSys_bIniAntiStall == 0)
   {
      if (u32LocalGain < 65536)
      {
         s16LocalFilterOutput =
         MATHSRV_s16FirstOrderFilterGu16((uint16)u32LocalGain,
                                         &TQANTISTALLBVM_s32FilterMem,
                                         s16LocalTreatTDC_nCkGrd);
      }
      else
      {
         s16LocalFilterOutput = s16LocalTreatTDC_nCkGrd;
         TQANTISTALLBVM_s32FilterMem =
            (sint32)(s16LocalTreatTDC_nCkGrd * 65536);
      }
      IdlSys_nGrdAntiStall_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalFilterOutput,
                                  -32000,
                                  32000);
   }
   else
   {

      IdlSys_nGrdAntiStall_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalTreatTDC_nCkGrd,
                                  -32000,
                                  32000);
      TQANTISTALLBVM_s32FilterMem = (sint32)(IdlSys_nGrdAntiStall_MP * 65536);
   }

   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   u8LocalCoPt_noEgdGearCord = (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord,
                                                     7);

   u16LocalCalcParaY = (uint16)(u8LocalCoPt_noEgdGearCord * 256);

   u16LocalIdlSys_nGrdAntiStall =
      (uint16)((IdlSys_nGrdAntiStall_MP + 32000) / 4);

   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(IdlSys_nGrdAntiStall_A,
                                   u16LocalIdlSys_nGrdAntiStall,
                                   12);
   u16IdlSysnOfsAcvAntiStall =
      MATHSRV_u16Interp2d(&IdlSys_nOfsAcvAntiStall_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          8);
   IdlSys_nOfsAcvAntiStall =
      (uint16)MATHSRV_udtMIN(u16IdlSysnOfsAcvAntiStall, 8000);

   u8LocalNoTDCTest = IdlSys_noTDCTestAntiStall_T[u8LocalCoPt_noEgdGearCord];
   IdlSys_noTDCTestAntiStall = (uint8)MATHSRV_udtMIN(u8LocalNoTDCTest, 50);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidSigActivFrein                            */
/* !Description :  Fonction qui retraite le signal d’appui frein afin de tenir*/
/*                 compte d’une volonté de freiner du conducteur lorsque l’on */
/*                 détermine les conditions de calage.                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04974_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input boolean CoBrk_bAcvBrk;                                              */
/*  input uint8 IdlSys_tiInhBrkAntiStall_T[8];                                */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean IdlSys_bAcvBrkAntiStall_MP;                                 */
/*  input boolean TQANTISTALLBVM_bTOffDlyBrkInPrev;                           */
/*  input uint16 TQANTISTALLBVM_u16TOffDlyBrkCnt;                             */
/*  input boolean IdlSys_bAcvBrkCdnAntiStall_C;                               */
/*  output boolean IdlSys_bAcvBrkAntiStall_MP;                                */
/*  output uint16 TQANTISTALLBVM_u16TOffDlyBrkCnt;                            */
/*  output boolean TQANTISTALLBVM_bTOffDlyBrkInPrev;                          */
/*  output boolean IdlSys_bInhBrkAntiStall;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidSigActivFrein(void)
{
   boolean bLocalCoBrk_bAcvBrk;
   boolean bLocalTurnOffDelayOutput;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8localtiInhBrkAntiStall;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalIndex;
   uint16  u16LocalTurnOffDlyCnt;


   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   u8LocalCoPt_noEgdGearCord = (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord,
                                                     7);
   VEMS_vidGET(CoBrk_bAcvBrk, bLocalCoBrk_bAcvBrk);

   if (  (bLocalCoBrk_bAcvBrk != 0)
      && (u8LocalCoPt_noEgdGearCord != 0))
   {
      IdlSys_bAcvBrkAntiStall_MP = 1;
   }
   else
   {
      IdlSys_bAcvBrkAntiStall_MP = 0;
   }

   u16LocalIndex = (uint16)(u8LocalCoPt_noEgdGearCord * 256);
   u8localtiInhBrkAntiStall = MATHSRV_u8Interp1d(IdlSys_tiInhBrkAntiStall_T,
                                                 u16LocalIndex);

   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);

   if (IdlSys_bAcvBrkAntiStall_MP != 0)
   {
      bLocalTurnOffDelayOutput = 1 ;
   }
   else
   {
      if (TQANTISTALLBVM_bTOffDlyBrkInPrev != 0)
      {
         u16LocalTurnOffDlyCnt = (uint16)(u8localtiInhBrkAntiStall * 125);
         TQANTISTALLBVM_u16TOffDlyBrkCnt =
            (uint16)MATHSRV_udtMIN(u16LocalTurnOffDlyCnt, 30000);
      }
      else
      {
         if (TQANTISTALLBVM_u16TOffDlyBrkCnt > u8LocalExt_tiTDC)
         {
            u16LocalTurnOffDlyCnt = (uint16)( TQANTISTALLBVM_u16TOffDlyBrkCnt
                                            - u8LocalExt_tiTDC);
            TQANTISTALLBVM_u16TOffDlyBrkCnt =
               (uint16)MATHSRV_udtMIN(u16LocalTurnOffDlyCnt, 30000);
         }
         else
         {
            TQANTISTALLBVM_u16TOffDlyBrkCnt = 0;
         }
      }
      if (TQANTISTALLBVM_u16TOffDlyBrkCnt != 0)
      {
         bLocalTurnOffDelayOutput = 1;
      }
      else
      {
         bLocalTurnOffDelayOutput = 0;
      }
   }
   TQANTISTALLBVM_bTOffDlyBrkInPrev = IdlSys_bAcvBrkAntiStall_MP;

   if (IdlSys_bAcvBrkCdnAntiStall_C == 0)
   {
      IdlSys_bInhBrkAntiStall = 0;
   }
   else
   {
      IdlSys_bInhBrkAntiStall = bLocalTurnOffDelayOutput;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidAutActAntiCal                            */
/* !Description :  on retraite IdlSys_bAcvAntiStall dans cette fonction afin  */
/*                 d’empêcher une autre activation de l’anti-calage.          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_05599_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean IdlSys_bAcvAntiStallPrev;                                   */
/*  input boolean TQANTISTALLBVM_bTOffDlyAutInPrev;                           */
/*  input uint8 IdlSys_tiInhAntiStall_C;                                      */
/*  input uint16 TQANTISTALLBVM_u16TOffDlyAuthCnt;                            */
/*  output boolean IdlSys_bDlyAuthAntiStall;                                  */
/*  output uint16 TQANTISTALLBVM_u16TOffDlyAuthCnt;                           */
/*  output boolean TQANTISTALLBVM_bTOffDlyAutInPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidAutActAntiCal(void)
{
   uint8  u8LocalExt_tiTDC;
   uint16 u16LocalTurnOffDlyCnt;


   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);

   if (IdlSys_bAcvAntiStallPrev != 0)
   {
      IdlSys_bDlyAuthAntiStall = 1 ;
   }
   else
   {
      if (TQANTISTALLBVM_bTOffDlyAutInPrev != 0)
      {
         u16LocalTurnOffDlyCnt = (uint16)(IdlSys_tiInhAntiStall_C * 125);
         TQANTISTALLBVM_u16TOffDlyAuthCnt =
            (uint16)MATHSRV_udtMIN(u16LocalTurnOffDlyCnt, 30000);
      }
      else
      {
         if (TQANTISTALLBVM_u16TOffDlyAuthCnt > u8LocalExt_tiTDC)
         {
            u16LocalTurnOffDlyCnt = (uint16)( TQANTISTALLBVM_u16TOffDlyAuthCnt
                                            - u8LocalExt_tiTDC);
            TQANTISTALLBVM_u16TOffDlyAuthCnt =
               (uint16)MATHSRV_udtMIN(u16LocalTurnOffDlyCnt, 30000);
         }
         else
         {
            TQANTISTALLBVM_u16TOffDlyAuthCnt = 0;
         }
      }
      if (TQANTISTALLBVM_u16TOffDlyAuthCnt != 0)
      {
         IdlSys_bDlyAuthAntiStall = 1;
      }
      else
      {
         IdlSys_bDlyAuthAntiStall = 0;
      }
   }
   TQANTISTALLBVM_bTOffDlyAutInPrev = IdlSys_bAcvAntiStallPrev;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidConditionActiv                           */
/* !Description :  on fait la synthèse de toutes les informations dans cette  */
/*                 fonction afin de déterminer la demande d’activation de la  */
/*                 stratégie anti-calage.                                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_05599_008.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean FARSp_bDeacAntiStall;                                       */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean CoPt_bAcvAntiStallFil;                                      */
/*  input uint16 IdlSys_nOfsAcvAntiStall;                                     */
/*  input st73 TQANTISTALLBVM_stAcvAntiStall;                                 */
/*  input boolean IdlSys_bDlyAuthAntiStall;                                   */
/*  input boolean IdlSys_bInhBrkAntiStall;                                    */
/*  input uint8 IdlSys_noTDCTestAntiStall;                                    */
/*  input uint8 IdlSys_ctTestAcvAntiStall;                                    */
/*  input uint16 IdlSys_nDifAcvAntiStall;                                     */
/*  output st73 TQANTISTALLBVM_stAcvAntiStall;                                */
/*  output boolean IdlSys_bAcvAntiStall;                                      */
/*  output uint8 IdlSys_ctTestAcvAntiStall;                                   */
/*  output uint16 IdlSys_nDifAcvAntiStall;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidConditionActiv(void)
{
   boolean bLocalIdlSys_bAcvIdlCtl;
   boolean bLocalFARSp_bDeacAntiStall;
   boolean bLocalCoPt_bAcvAntiStallFil;
   uint8   u8LocalCnt;
   sint32  s32LocalEngSpd;
   uint16  u16LocalTqSys_nTarIdl;
   uint16  u16LocalExt_nEng;


   VEMS_vidGET(FARSp_bDeacAntiStall, bLocalFARSp_bDeacAntiStall);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
   VEMS_vidGET(CoPt_bAcvAntiStallFil, bLocalCoPt_bAcvAntiStallFil);


   s32LocalEngSpd = ( (4 * u16LocalExt_nEng)
                    - (u16LocalTqSys_nTarIdl - (4 * IdlSys_nOfsAcvAntiStall)))
                  / 4;

   switch(TQANTISTALLBVM_stAcvAntiStall)
   {
      case TQANTISTALLBVM_bINITIAL_STATE:
         if (IdlSys_bDlyAuthAntiStall == 0)
         {
            if (bLocalCoPt_bAcvAntiStallFil != 0)
            {
               TQANTISTALLBVM_stAcvAntiStall = TQANTISTALLBVM_bACTIV_STATE;
               VEMS_vidSET(IdlSys_bAcvAntiStall, 1);
            }
            else
            {
               if (  (bLocalIdlSys_bAcvIdlCtl != 0)
                  && (s32LocalEngSpd <= 0)
                  && (IdlSys_bInhBrkAntiStall == 0))
               {
                  if (IdlSys_noTDCTestAntiStall == 0)
                  {
                     TQANTISTALLBVM_stAcvAntiStall =
                        TQANTISTALLBVM_bACTIV_STATE;
                     VEMS_vidSET(IdlSys_bAcvAntiStall, 1);
                  }
                  else
                  {
                     TQANTISTALLBVM_stAcvAntiStall =
                        TQANTISTALLBVM_bWAIT_ACTIV_STATE;
                     VEMS_vidSET(IdlSys_bAcvAntiStall, 0);
                     IdlSys_ctTestAcvAntiStall =
                        (uint8)MATHSRV_udtMIN(IdlSys_noTDCTestAntiStall, 50);
                     /* !Deviation: violation of MISRA-C:2004 Rule 13.7       */
                     /* Msg(3:3356) The result of this logical operation is   */
                     /* always 'false'.                                       */
                     /* !justification: The result of this cast is always     */
                     /* equal to 0                                            */
                     IdlSys_nDifAcvAntiStall =
                        (uint16)MATHSRV_udtMAX(s32LocalEngSpd, 0);
                  }
               }
            }
         }
         break;

      case TQANTISTALLBVM_bWAIT_ACTIV_STATE:
         if (  (bLocalCoPt_bAcvAntiStallFil != 0)
            || (  (IdlSys_ctTestAcvAntiStall == 0)
               && (s32LocalEngSpd <= IdlSys_nDifAcvAntiStall)))
         {
            TQANTISTALLBVM_stAcvAntiStall = TQANTISTALLBVM_bACTIV_STATE;
            VEMS_vidSET(IdlSys_bAcvAntiStall, 1);
         }
         else
         {
            if (  (bLocalIdlSys_bAcvIdlCtl == 0)
               || (IdlSys_bInhBrkAntiStall != 0)
               || (  (IdlSys_ctTestAcvAntiStall == 0)
                  && (s32LocalEngSpd > IdlSys_nDifAcvAntiStall)))
            {
               TQANTISTALLBVM_stAcvAntiStall = TQANTISTALLBVM_bINITIAL_STATE;
               VEMS_vidSET(IdlSys_bAcvAntiStall, 0);
            }
            else
            {
               /* !Deviation: violation of MISRA-C:2004 Rule 21.1             */
               /* Msg(3:0291) An integer expression with a value that is      */
               /* apparently negative is being converted to an unsigned type. */
               /* !justification: The variable IdlSys_ctTestAcvAntiStall      */
               /* could never be equal to 0 here so the soustraction could    */
               /* never be negative.                                          */
               u8LocalCnt = (uint8)(IdlSys_ctTestAcvAntiStall - 1);
               IdlSys_ctTestAcvAntiStall = (uint8)MATHSRV_udtMIN(u8LocalCnt,
                                                                 50);
            }
         }
         break;

      case TQANTISTALLBVM_bACTIV_STATE:
         if (bLocalFARSp_bDeacAntiStall != 0)
         {
            TQANTISTALLBVM_stAcvAntiStall = TQANTISTALLBVM_bINITIAL_STATE;
            VEMS_vidSET(IdlSys_bAcvAntiStall, 0);
         }
         break;

      default :
         TQANTISTALLBVM_stAcvAntiStall = TQANTISTALLBVM_bINITIAL_STATE;
         VEMS_vidSET(IdlSys_bAcvAntiStall, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQANTISTALLBVM_vidInhibAntical                             */
/* !Description :  Lorsque IdlSys_bEnaAntiStall = 0, IdlSys_bAcvAntiStall est */
/*                 maintenue à la valeur 0.                                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04974_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean IdlSys_bAcvAntiStall;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQANTISTALLBVM_vidInhibAntical(void)
{
   VEMS_vidSET(IdlSys_bAcvAntiStall, 0);
}

/*------------------------------- end of file --------------------------------*/