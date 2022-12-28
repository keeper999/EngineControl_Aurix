/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQLOSSMON                                               */
/* !Description     : TQLOSSMON component.                                    */
/*                                                                            */
/* !Module          : TQLOSSMON                                               */
/* !Description     : Safety TMS : Valider Pertes Globales                    */
/*                                                                            */
/* !File            : TQLOSSMON_FCT3.C                                        */
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
/*   1 / TQLOSSMON_vidDet_Pertes_DA                                           */
/*   2 / TQLOSSMON_vidTraiter_Vveh                                            */
/*   3 / TQLOSSMON_vidDet_Pertes_DA_OnOff                                     */
/*   4 / TQLOSSMON_vidDet_Pertes_DA_Lin                                       */
/*   5 / TQLOSSMON_vidSelectioner_Type_DA                                     */
/*   6 / TQLOSSMON_vidFiltrer_Pertes_DA                                       */
/*   7 / TQLOSSMON_vidValider_signal_ACS                                      */
/*   8 / TQLOSSMON_vidDet_Pertes_BVM                                          */
/*   9 / TQLOSSMON_vidCoord_Pertes_Access                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 01233 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_1793 / 1.5                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQLOSSMON/TQLOSSMON_FC$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   28 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQLOSSMON.h"
#include "TQLOSSMON_L.h"
#include "TQLOSSMON_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_DA                                 */
/* !Description :  Cette fonction permet  de valider que le couple prélevée   */
/*                 calculé par l’ACS est inférieur au couple maximal que peut */
/*                 demander la DA raffiné en fonction de la vitesse et du     */
/*                 régime.                                                    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLOSSMON_vidTraiter_Vveh();                             */
/*  extf argret void TQLOSSMON_vidDet_Pertes_DA_OnOff();                      */
/*  extf argret void TQLOSSMON_vidDet_Pertes_DA_Lin();                        */
/*  extf argret void TQLOSSMON_vidSelectioner_Type_DA();                      */
/*  extf argret void TQLOSSMON_vidFiltrer_Pertes_DA();                        */
/*  extf argret void TQLOSSMON_vidValider_signal_ACS();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_DA(void)
{
   TQLOSSMON_vidTraiter_Vveh();
   TQLOSSMON_vidDet_Pertes_DA_OnOff();
   TQLOSSMON_vidDet_Pertes_DA_Lin();
   TQLOSSMON_vidSelectioner_Type_DA();
   TQLOSSMON_vidFiltrer_Pertes_DA();
   TQLOSSMON_vidValider_signal_ACS();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidTraiter_Vveh                                  */
/* !Description :  Cette sous fonction réalise le traitement de la vitesse    */
/*                 véhicule en cas de défaut de signal.                       */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bInhStgPmpLoss_FRM;                                 */
/*  input uint16 SftyMgt_spdVehBuf;                                           */
/*  input uint16 SftyMgt_spdDftStgPmp_C;                                      */
/*  output uint16 SftyMgt_spdVehSel;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidTraiter_Vveh(void)
{
   boolean bLocalSftyMgt_bInhStgPmpLoss_FRM;
   uint16  u16LocalspdVehSel;
   uint16  u16LocalSftyMgt_spdVehBuf;


   VEMS_vidGET(SftyMgt_bInhStgPmpLoss_FRM, bLocalSftyMgt_bInhStgPmpLoss_FRM);
   VEMS_vidGET(SftyMgt_spdVehBuf, u16LocalSftyMgt_spdVehBuf);

   if (bLocalSftyMgt_bInhStgPmpLoss_FRM != 0)
   {
      u16LocalspdVehSel = (uint16)((SftyMgt_spdDftStgPmp_C * 25) / 32);
   }
   else
   {
      u16LocalspdVehSel = (uint16)((u16LocalSftyMgt_spdVehBuf * 25) / 32);
   }
   SftyMgt_spdVehSel = (uint16)MATHSRV_udtMIN(u16LocalspdVehSel, 50000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_DA_OnOff                           */
/* !Description :  Cette sous fonction détermine l’enveloppe max de la DA de  */
/*                 type On-Off principalement en fonction du régime moteur.   */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_nCkStgPmp_A[5];                                      */
/*  input uint8 SftyMgt_facStgPmpThdLossNCk_T[5];                             */
/*  input uint16 SftyMgt_spdVehSel;                                           */
/*  input uint16 SftyMgt_spdTqCmp_A[5];                                       */
/*  input uint8 SftyMgt_facStgThdLossSpd_T[5];                                */
/*  input uint16 SftyMgt_tqStgPmpThdLossMax_C;                                */
/*  output uint16 SftyMgt_tqStgPmpThdLoss;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_DA_OnOff(void)
{
   uint8  u8LocalCalcInterpLossNCk;
   uint8  u8LocalCalcInterpLossSpd;
   uint16 u16LocalSftyMgt_spdVehSel;
   uint16 u16LocalCalcPara;
   uint16 u16LocalSftyMgt_nCkFilBuf;
   uint32 u32LocalStgPmpThdLoss;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkStgPmp_A,
                                                   u16LocalSftyMgt_nCkFilBuf,
                                                   5);
   u8LocalCalcInterpLossNCk = MATHSRV_u8Interp1d(SftyMgt_facStgPmpThdLossNCk_T,
                                                 u16LocalCalcPara);

   u16LocalSftyMgt_spdVehSel = (uint16)((SftyMgt_spdVehSel * 4) / 25);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_spdTqCmp_A,
                                                   u16LocalSftyMgt_spdVehSel,
                                                   5);
   u8LocalCalcInterpLossSpd = MATHSRV_u8Interp1d(SftyMgt_facStgThdLossSpd_T,
                                                 u16LocalCalcPara);

   u32LocalStgPmpThdLoss = (uint32)( ( u8LocalCalcInterpLossNCk
                                     * u8LocalCalcInterpLossSpd)
                                   * SftyMgt_tqStgPmpThdLossMax_C);

   u32LocalStgPmpThdLoss = ((u32LocalStgPmpThdLoss + 8192) / 16384);

   SftyMgt_tqStgPmpThdLoss = (uint16)MATHSRV_udtMIN(u32LocalStgPmpThdLoss,
                                                    8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_DA_Lin                             */
/* !Description :  Cette sous fonction permet de déterminer l’enveloppe max de*/
/*                 la DA de type linéaire.                                    */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_nCkStgPmp_A[5];                                      */
/*  input uint8 SftyMgt_facStgLnrLossNCk_T[5];                                */
/*  input uint16 SftyMgt_spdVehSel;                                           */
/*  input uint16 SftyMgt_spdTqCmp_A[5];                                       */
/*  input uint8 SftyMgt_facStgLnrLossSpd_T[5];                                */
/*  input uint16 SftyMgt_tqStgPmpLnrLossMax_C;                                */
/*  output uint16 SftyMgt_tqStgPmpLnrLoss;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_DA_Lin(void)
{
   uint8  u8LocalCalcInterpLnrLossNCk;
   uint8  u8LocalCalcInterpLnrLossSpd;
   uint16 u16LocalSftyMgt_spdVehSel;
   uint16 u16LocalCalcPara;
   uint16 u16LocalSftyMgt_nCkFilBuf;
   uint32 u32LocalStgPmpLnrLoss;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkStgPmp_A,
                                                   u16LocalSftyMgt_nCkFilBuf,
                                                   5);
   u8LocalCalcInterpLnrLossNCk = MATHSRV_u8Interp1d(SftyMgt_facStgLnrLossNCk_T,
                                                    u16LocalCalcPara);

   u16LocalSftyMgt_spdVehSel = (uint16)((SftyMgt_spdVehSel * 4) / 25);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_spdTqCmp_A,
                                                   u16LocalSftyMgt_spdVehSel,
                                                   5);
   u8LocalCalcInterpLnrLossSpd = MATHSRV_u8Interp1d(SftyMgt_facStgLnrLossSpd_T,
                                                    u16LocalCalcPara);

   u32LocalStgPmpLnrLoss = (uint32)( ( u8LocalCalcInterpLnrLossNCk
                                     * u8LocalCalcInterpLnrLossSpd)
                                   * SftyMgt_tqStgPmpLnrLossMax_C);

   u32LocalStgPmpLnrLoss = ((u32LocalStgPmpLnrLoss + 8192) / 16384);

   SftyMgt_tqStgPmpLnrLoss = (uint16)MATHSRV_udtMIN(u32LocalStgPmpLnrLoss,
                                                    8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidSelectioner_Type_DA                           */
/* !Description :  Cette sous fonction permet de déterminer le signal à       */
/*                 utiliser en fonction du type de DA.                        */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 SftyMgt_idxStgPmpTyp_C;                                       */
/*  input uint16 SftyMgt_tqStgPmpLnrLoss;                                     */
/*  input uint16 SftyMgt_tqStgPmpThdLoss;                                     */
/*  output uint16 SftyMgt_tqStgPmpLossNotFil;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidSelectioner_Type_DA(void)
{
   uint16 u16LocalPmpLossNotFil;


   switch (SftyMgt_idxStgPmpTyp_C)
   {
      case 0:
         u16LocalPmpLossNotFil = 0;
         break;
      case 1:
         u16LocalPmpLossNotFil = SftyMgt_tqStgPmpLnrLoss;
         break;
      case 2:
         u16LocalPmpLossNotFil = SftyMgt_tqStgPmpThdLoss;
         break;
      default:
         u16LocalPmpLossNotFil = SftyMgt_tqStgPmpThdLoss;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   SftyMgt_tqStgPmpLossNotFil = (uint16)MATHSRV_udtMIN(u16LocalPmpLossNotFil,
                                                       8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidFiltrer_Pertes_DA                             */
/* !Description :  Cette sous fonction redonde le filtrage des pertes DA      */
/*                 effectué dans l’ACS.                                       */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bTqGrdLimBuf;                                       */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_nCkStgPmp_A[5];                                      */
/*  input uint16 SftyMgt_facFilTqStgLossUp_T[5];                              */
/*  input uint16 SftyMgt_facFilTqStgDown_T[5];                                */
/*  input uint16 SftyMgt_facFilTqStgPmpLoss_C;                                */
/*  input uint16 SftyMgt_tqStgPmpLossSum_MP;                                  */
/*  input uint16 SftyMgt_tqStgPmpLossNotFil;                                  */
/*  input uint16 SftyMgt_facFilTqStgLossUp_MP;                                */
/*  input uint16 SftyMgt_facFilTqStgDown_MP;                                  */
/*  input uint16 SftyMgt_facFilTqStgPmpLoss_MP;                               */
/*  input uint16 SftyMgt_tqStgPmpLossMin_C;                                   */
/*  input uint16 SftyMgt_tqStgPmpLossMax_C;                                   */
/*  output uint16 SftyMgt_facFilTqStgLossUp_MP;                               */
/*  output uint16 SftyMgt_facFilTqStgDown_MP;                                 */
/*  output uint16 SftyMgt_facFilTqStgPmpLoss_MP;                              */
/*  output uint16 SftyMgt_tqStgPmpLossSum_MP;                                 */
/*  output uint16 SftyMgt_tqStgPmpLoss;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidFiltrer_Pertes_DA(void)
{
   boolean bLocalSftyMgt_bTqGrdLimBuf;
   uint16  u16LocalCalcParaCkStgPmp;
   uint16  u16LocalSftyMgt_tqStgPmpLoss;
   uint16  u16LocalSftyMgt_nCkFilBuf;
   uint32  u32LocalUnsignedDiff;
   uint32  u32LocalModifCoeff;
   sint32  s32LocalSignedDiff;
   sint32  s32LocaltqStgPmpLossSum;


   VEMS_vidGET(SftyMgt_bTqGrdLimBuf, bLocalSftyMgt_bTqGrdLimBuf);
   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);

   u16LocalCalcParaCkStgPmp =
      MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkStgPmp_A,
                                   u16LocalSftyMgt_nCkFilBuf,
                                   5);

   /* Calc of SftyMgt_facFilTqStgLossUp_MP */
   SftyMgt_facFilTqStgLossUp_MP =
      MATHSRV_u16Interp1d(SftyMgt_facFilTqStgLossUp_T,
                          u16LocalCalcParaCkStgPmp);

   /* Calc of SftyMgt_facFilTqStgDown_MP */
   SftyMgt_facFilTqStgDown_MP = MATHSRV_u16Interp1d(SftyMgt_facFilTqStgDown_T,
                                                    u16LocalCalcParaCkStgPmp);

   if (bLocalSftyMgt_bTqGrdLimBuf != 0)
   {
      u32LocalModifCoeff = (uint32)(SftyMgt_facFilTqStgPmpLoss_C);
   }
   else
   {
      if (SftyMgt_tqStgPmpLossSum_MP <= SftyMgt_tqStgPmpLossNotFil)
      {
         u32LocalModifCoeff = (uint32)(SftyMgt_facFilTqStgLossUp_MP + 1);
      }
      else
      {
         u32LocalModifCoeff = (uint32)(SftyMgt_facFilTqStgDown_MP + 1);
      }
   }

   if (u32LocalModifCoeff != 0)
   {
      u32LocalModifCoeff = (1000000 / u32LocalModifCoeff);
      u32LocalModifCoeff = (u32LocalModifCoeff + 3000);
      u32LocalModifCoeff = (4000000000uL / u32LocalModifCoeff);
      u32LocalModifCoeff = (u32LocalModifCoeff - 1000);
      u32LocalModifCoeff = (u32LocalModifCoeff / 1000);
      SftyMgt_facFilTqStgPmpLoss_MP =
         (uint16)MATHSRV_udtMIN(u32LocalModifCoeff, 999);
   }
   else
   {
      SftyMgt_facFilTqStgPmpLoss_MP = 0;
   }

   s32LocalSignedDiff = (sint32)( SftyMgt_tqStgPmpLossNotFil
                                - SftyMgt_tqStgPmpLossSum_MP);

   u32LocalUnsignedDiff = (uint32)(SftyMgt_facFilTqStgPmpLoss_MP + 1);

   s32LocaltqStgPmpLossSum = s32LocalSignedDiff * (sint32)u32LocalUnsignedDiff;

   s32LocaltqStgPmpLossSum = s32LocaltqStgPmpLossSum
                           + (SftyMgt_tqStgPmpLossSum_MP * 1000);
   s32LocaltqStgPmpLossSum = (s32LocaltqStgPmpLossSum / 1000);

   SftyMgt_tqStgPmpLossSum_MP =
      (uint16)MATHSRV_udtMIN(s32LocaltqStgPmpLossSum, 8000);

   u16LocalSftyMgt_tqStgPmpLoss =
      (uint16)MATHSRV_udtCLAMP(SftyMgt_tqStgPmpLossSum_MP,
                               SftyMgt_tqStgPmpLossMin_C,
                               SftyMgt_tqStgPmpLossMax_C);
   SftyMgt_tqStgPmpLoss = (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_tqStgPmpLoss,
                                                 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidValider_signal_ACS                            */
/* !Description :  Cette sous fonction permet de valider le signal de l’ACS en*/
/*                 fonction de l’enveloppe max calculée dans la TMS.          */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_tqErrThdSftyLossAux_C;                               */
/*  input uint16 SftyMgt_tqStgPmpLoss;                                        */
/*  input uint16 SftyMgt_tqStgPmpLossUnChkBuf;                                */
/*  input uint16 SftyMgt_tqStgPmpLoss_MP;                                     */
/*  output uint16 SftyMgt_tqStgPmpLoss_MP;                                    */
/*  output boolean SftyMgt_bDgoTqStg;                                         */
/*  output uint16 SftyMgt_tqStgPmpLossChkBuf;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidValider_signal_ACS(void)
{
   uint16 u16LocaltqStgPmpLossUnChkBuf;
   uint32 u32LocalStgPmpLoss;


   u32LocalStgPmpLoss = (uint32)( SftyMgt_tqErrThdSftyLossAux_C
                                + SftyMgt_tqStgPmpLoss);
   SftyMgt_tqStgPmpLoss_MP = (uint16)MATHSRV_udtMIN(u32LocalStgPmpLoss, 8000);

   VEMS_vidGET(SftyMgt_tqStgPmpLossUnChkBuf, u16LocaltqStgPmpLossUnChkBuf);
   if (SftyMgt_tqStgPmpLoss_MP < u16LocaltqStgPmpLossUnChkBuf)
   {
      SftyMgt_bDgoTqStg = 1;
   }
   else
   {
      SftyMgt_bDgoTqStg = 0;
   }
   SftyMgt_tqStgPmpLossChkBuf =
      (uint16)MATHSRV_udtMIN(u16LocaltqStgPmpLossUnChkBuf, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_BVM                                */
/* !Description :  Cette fonction fait la synthèse des levées de défauts et   */
/*                 valide le couple final des pertes.                         */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_038.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_tqAuxLossTqCmp;                                      */
/*  input sint16 SftyMgt_tqErrThdTqAuxLoss_C;                                 */
/*  output boolean SftyMgt_bDgoTqAuxLoss;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_BVM(void)
{
   uint16 u16LocaltqAuxLossTqCmp;


   VEMS_vidGET(SftyMgt_tqAuxLossTqCmp, u16LocaltqAuxLossTqCmp);
   if (SftyMgt_tqErrThdTqAuxLoss_C < u16LocaltqAuxLossTqCmp)
   {
      SftyMgt_bDgoTqAuxLoss = 1;
   }
   else
   {
      SftyMgt_bDgoTqAuxLoss = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidCoord_Pertes_Access                           */
/* !Description :  Cette fonction somme les contributions des différents blocs*/
/*                 de pertes accessoires.                                     */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_022.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bInhTqManGBxLoss_C;                                 */
/*  input uint16 SftyMgt_tqAuxLossTqCmp;                                      */
/*  input uint16 SftyMgt_tqAltLossChkBuf;                                     */
/*  input uint16 SftyMgt_tqACLossChkBuf;                                      */
/*  input uint16 SftyMgt_tqStgPmpLossChkBuf;                                  */
/*  output uint16 SftyMgt_tqAuxSumLossCmp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidCoord_Pertes_Access(void)
{
   uint16 u16LocaltqAuxLossTqCmp;
   uint32 u32LocalTqAuxSumLossCmp;


   if (SftyMgt_bInhTqManGBxLoss_C != 0)
   {
      u16LocaltqAuxLossTqCmp = 0;
   }
   else
   {
      VEMS_vidGET(SftyMgt_tqAuxLossTqCmp, u16LocaltqAuxLossTqCmp);
   }
   u32LocalTqAuxSumLossCmp = (uint32)( SftyMgt_tqAltLossChkBuf
                                     + SftyMgt_tqACLossChkBuf
                                     + SftyMgt_tqStgPmpLossChkBuf
                                     + u16LocaltqAuxLossTqCmp);
   SftyMgt_tqAuxSumLossCmp = (uint16)MATHSRV_udtMIN(u32LocalTqAuxSumLossCmp,
                                                    8000);
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*---------------------------- end of file -----------------------------------*/