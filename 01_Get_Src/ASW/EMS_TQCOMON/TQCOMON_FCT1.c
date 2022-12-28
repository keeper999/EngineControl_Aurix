/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCOMON                                                 */
/* !Description     : TQCOMON Component.                                      */
/*                                                                            */
/* !Module          : TQCOMON                                                 */
/* !Description     : Safety TMS : Coordonner les Couples.                    */
/*                                                                            */
/* !File            : TQCOMON_FCT1.C                                          */
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
/*   1 / TQCOMON_vidInitOutput                                                */
/*   2 / TQCOMON_vidCoordonner_XVV                                            */
/*   3 / TQCOMON_vidCoordonner_Agrement                                       */
/*   4 / TQCOMON_vidCoordonner_Couple_ESP                                     */
/*   5 / TQCOMON_vidCoordonner_Couple_BV                                      */
/*   6 / TQCOMON_vidConversion_CME_CMI                                        */
/*   7 / TQCOMON_vidCoordRelanceRegimeBV                                      */
/*   8 / TQCOMON_vidCoordonnerLimRalenti                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 01231 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#062959                                         */
/* !OtherRefs   : CSCT_CGMT09_1791 / 1.2                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMON/TQCOMON_FCT1.C$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQCOMON.h"
#include "TQCOMON_L.h"
#include "TQCOMON_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidInitOutput                                      */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDgoCoCha;                                         */
/*  output sint16 SftyMgt_tqCkEfcFilCo;                                       */
/*  output sint16 SftyMgt_tqEfcCoGBx;                                         */
/*  output sint16 SftyMgt_tqEfcReqCoCha;                                      */
/*  output sint16 SftyMgt_tqEfcReqCoVSCtl;                                    */
/*  output sint16 SftyMgt_tqIdcCoGBx;                                         */
/*  output sint16 SftyMgt_tqIdcCoNReg;                                        */
/*  output sint16 SftyMgt_tqIdcEngLimCo;                                      */
/*  output boolean TQCOMON_bDebounceInputPrev;                                */
/*  output uint16 TQCOMON_u16TiDlyCounter;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bDgoCoCha, 0);
   VEMS_vidSET(SftyMgt_tqCkEfcFilCo, 0);
   VEMS_vidSET(SftyMgt_tqEfcCoGBx, 0);
   VEMS_vidSET(SftyMgt_tqEfcReqCoCha, 0);
   VEMS_vidSET(SftyMgt_tqEfcReqCoVSCtl, 0);
   VEMS_vidSET(SftyMgt_tqIdcCoGBx, 0);
   VEMS_vidSET(SftyMgt_tqIdcCoNReg, 0);
   VEMS_vidSET(SftyMgt_tqIdcEngLimCo, 0);

   TQCOMON_bDebounceInputPrev = 0;
   TQCOMON_u16TiDlyCounter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidCoordonner_XVV                                  */
/* !Description :  Cette fonction intègre la consigne de couple RVV dans la   */
/*                 chaîne en couple en appliquant un max entre la couple      */
/*                 conducteur issue du bloc amont et la consigne de couple    */
/*                 RVV.                                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 SftyMgt_tqCkEfcMinVSCtl;                                     */
/*  input sint16 SftyMgt_tqCkEfc;                                             */
/*  input sint16 SftyMgt_tqCkEfcMaxVSCtl;                                     */
/*  input sint16 SftyMgt_tqLimEM;                                             */
/*  output sint16 SftyMgt_tqEfcReqCoVSCtl;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidCoordonner_XVV(void)
{
   sint16 s16LocalSftyMgt_tqCkEfcMinVSCtl;
   sint16 s16LocalSftyMgt_tqCkEfc;
   sint16 s16LocalSftyMgt_tqCkEfcMaxVSCtl;
   sint16 s16LocalSftyMgt_tqLimEM;
   sint16 s16LocalSftyMgt_tqEfcReqCoVSCtl;
   sint16 s16LocalCmpMax;
   sint16 s16LocalCmpMin;


   VEMS_vidGET(SftyMgt_tqCkEfcMinVSCtl, s16LocalSftyMgt_tqCkEfcMinVSCtl);
   VEMS_vidGET(SftyMgt_tqCkEfc, s16LocalSftyMgt_tqCkEfc);
   VEMS_vidGET(SftyMgt_tqCkEfcMaxVSCtl, s16LocalSftyMgt_tqCkEfcMaxVSCtl);
   VEMS_vidGET(SftyMgt_tqLimEM, s16LocalSftyMgt_tqLimEM);

   s16LocalCmpMax = (sint16)MATHSRV_udtMAX(s16LocalSftyMgt_tqCkEfcMinVSCtl,
                                           s16LocalSftyMgt_tqCkEfc);

   s16LocalCmpMin = (sint16)MATHSRV_udtMIN(s16LocalCmpMax,
                                           s16LocalSftyMgt_tqCkEfcMaxVSCtl);

   s16LocalCmpMin = (sint16)MATHSRV_udtMIN(s16LocalCmpMin,
                                           s16LocalSftyMgt_tqLimEM);

   s16LocalSftyMgt_tqEfcReqCoVSCtl = (sint16)MATHSRV_udtCLAMP(s16LocalCmpMin,
                                                              -32000,
                                                              32000);
   VEMS_vidSET(SftyMgt_tqEfcReqCoVSCtl, s16LocalSftyMgt_tqEfcReqCoVSCtl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidCoordonner_Agrement                             */
/* !Description :  Cette fonction intègre le filtrage de l’agrément préventif.*/
/*                 Par calibration on peut choisir l’application ou non de ce */
/*                 filtrage.                                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bTqCkEfcFilCf_C;                                    */
/*  input sint16 SftyMgt_tqCkEfcFil;                                          */
/*  input sint16 SftyMgt_tqEfcReqCoVSCtl;                                     */
/*  output sint16 SftyMgt_tqCkEfcFilCo;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidCoordonner_Agrement(void)
{
   sint16 s16LocalSftyMgt_tqCkEfcFil;
   sint16 s16LocalSftyMgt_tqEfcReqCoVSCtl;
   sint16 s16LocalCkEfcFilCo;


   if (SftyMgt_bTqCkEfcFilCf_C != 0)
   {
      VEMS_vidGET(SftyMgt_tqCkEfcFil, s16LocalSftyMgt_tqCkEfcFil);
      s16LocalCkEfcFilCo = (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqCkEfcFil,
                                                    -32000,
                                                    32000);
   }
   else
   {
      VEMS_vidGET(SftyMgt_tqEfcReqCoVSCtl, s16LocalSftyMgt_tqEfcReqCoVSCtl);
      s16LocalCkEfcFilCo =
         (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqEfcReqCoVSCtl,
                                  -32000,
                                  32000);
   }

   VEMS_vidSET(SftyMgt_tqCkEfcFilCo, s16LocalCkEfcFilCo);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidCoordonner_Couple_ESP                           */
/* !Description :  Cette fonction est composée de deux sous fonctions: La     */
/*                 première permet de déterminer le déclenchement d’une       */
/*                 demande MSR. La seconde intègre les consignes de couples   */
/*                 ESP dans la chaîne en couple.                              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st76 SftyMgt_stTqReqCha;                                            */
/*  input sint16 SftyMgt_tqCkEfcFilCo;                                        */
/*  input sint16 SftyMgt_tqEfcReqCoChaUnChkBuf;                               */
/*  input boolean SftyMgt_bDgoCoCha;                                          */
/*  input sint16 SftyMgt_tqMSRReqCha;                                         */
/*  input uint16 SftyMgt_tqErrThdSftyTqCoCha_C;                               */
/*  input sint16 SftyMgt_tqCoCha_MP;                                          */
/*  input boolean TQCOMON_bDebounceInputPrev;                                 */
/*  input uint16 SftyMgt_tiDlyTqCoChaDftOn_C;                                 */
/*  input uint16 TQCOMON_u16TiDlyCounter;                                     */
/*  input uint16 SftyMgt_tiDlyTqCoChaDftOff_C;                                */
/*  output sint16 SftyMgt_tqCoCha_MP;                                         */
/*  output sint16 SftyMgt_tqEfcReqCoCha;                                      */
/*  output uint16 TQCOMON_u16TiDlyCounter;                                    */
/*  output boolean TQCOMON_bDebounceInputPrev;                                */
/*  output boolean SftyMgt_bDgoCoCha;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidCoordonner_Couple_ESP(void)
{
   boolean bLocalFlipFlopRstInput;
   boolean bLocalFlipFlopSetInput;
   boolean bLocalSftyMgt_bDgoCoCha;
   uint8   u8LocalSftyMgt_stTqReqCha;
   sint16  s16LocalSftyMgt_tqCkEfcFilCo;
   sint16  s16LocalSftyMgt_tqMSRReqCha;
   sint16  s16LocalSftyMgt_tqEfcReqCoCha;
   sint16  s16LocalSftyMgt_tqEfcReqCoChaUn;
   sint16  s16LocalComp;
   sint32  s32LocalSum;
   sint32  s32LocalCount;


   VEMS_vidGET(SftyMgt_stTqReqCha, u8LocalSftyMgt_stTqReqCha);
   VEMS_vidGET(SftyMgt_tqCkEfcFilCo, s16LocalSftyMgt_tqCkEfcFilCo);
   VEMS_vidGET(SftyMgt_tqEfcReqCoChaUnChkBuf, s16LocalSftyMgt_tqEfcReqCoChaUn);
   VEMS_vidGET(SftyMgt_bDgoCoCha, bLocalSftyMgt_bDgoCoCha);

   if (u8LocalSftyMgt_stTqReqCha == 6)
   {
      VEMS_vidGET (SftyMgt_tqMSRReqCha, s16LocalSftyMgt_tqMSRReqCha);
      s16LocalComp = (sint16)MATHSRV_udtMAX(s16LocalSftyMgt_tqMSRReqCha,
                                            s16LocalSftyMgt_tqCkEfcFilCo);
      s32LocalSum = s16LocalComp + SftyMgt_tqErrThdSftyTqCoCha_C;

   }
   else
   {
      s32LocalSum = s16LocalSftyMgt_tqCkEfcFilCo
                  + SftyMgt_tqErrThdSftyTqCoCha_C;
   }
   SftyMgt_tqCoCha_MP = (sint16)MATHSRV_udtCLAMP(s32LocalSum, -32000, 32000);

   s16LocalSftyMgt_tqEfcReqCoCha =
      (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqEfcReqCoChaUn, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqEfcReqCoCha, s16LocalSftyMgt_tqEfcReqCoCha);

   /*Fonction_Debounce*/
   if (SftyMgt_tqCoCha_MP < s16LocalSftyMgt_tqEfcReqCoChaUn)
   {
      bLocalFlipFlopRstInput = 0;

      if (TQCOMON_bDebounceInputPrev == 0)
      {
         TQCOMON_u16TiDlyCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyTqCoChaDftOn_C, 65500);
      }
      else
      {
         if (TQCOMON_u16TiDlyCounter > 0)
         {
            s32LocalCount = (sint32)(TQCOMON_u16TiDlyCounter - 4);
            TQCOMON_u16TiDlyCounter = (uint16)MATHSRV_udtCLAMP(s32LocalCount,
                                                               0,
                                                               65500);
         }
      }
      if (TQCOMON_u16TiDlyCounter == 0)
      {
         bLocalFlipFlopSetInput = 1;
      }
      else
      {
         bLocalFlipFlopSetInput = 0;
      }
      TQCOMON_bDebounceInputPrev = 1;
   }
   else
   {
      bLocalFlipFlopSetInput = 0;
      if (TQCOMON_bDebounceInputPrev != 0)
      {
         TQCOMON_u16TiDlyCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyTqCoChaDftOff_C, 65500);
      }
      else
      {
         if (TQCOMON_u16TiDlyCounter > 0)
         {
            s32LocalCount = (sint32)(TQCOMON_u16TiDlyCounter - 4);
            TQCOMON_u16TiDlyCounter = (uint16)MATHSRV_udtCLAMP(s32LocalCount,
                                                               0,
                                                               65500);
         }
      }
      if (TQCOMON_u16TiDlyCounter == 0)
      {
         bLocalFlipFlopRstInput = 1;
      }
      else
      {
         bLocalFlipFlopRstInput = 0;
      }
      TQCOMON_bDebounceInputPrev = 0;
   }

   if (  (bLocalFlipFlopRstInput == 0)
      && (  (bLocalFlipFlopSetInput != 0)
         || (bLocalSftyMgt_bDgoCoCha != 0)))
   {
      VEMS_vidSET(SftyMgt_bDgoCoCha, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoCoCha, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidCoordonner_Couple_BV                            */
/* !Description :  Cette fonction injecte la consigne de couple des boites de */
/*                 vitesse pilotées dans la chaîne en couple. Une calibration */
/*                 permet la prise en compte ou non de la consigne boite.     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bTqGBxCf_C;                                         */
/*  input sint16 SftyMgt_tqGBx;                                               */
/*  input sint16 SftyMgt_tqEfcReqCoCha;                                       */
/*  output sint16 SftyMgt_tqEfcCoGBx;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidCoordonner_Couple_BV(void)
{
   sint16 s16LocalSftyMgt_tqGBx;
   sint16 s16LocalSftyMgt_tqEfcCoGBx;
   sint16 s16LocalSftyMgt_tqEfcReqCoCha;


   if (SftyMgt_bTqGBxCf_C != 0)
   {
      VEMS_vidGET(SftyMgt_tqGBx, s16LocalSftyMgt_tqGBx);
      s16LocalSftyMgt_tqEfcCoGBx =
         (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqGBx, -32000, 32000);
      VEMS_vidSET(SftyMgt_tqEfcCoGBx, s16LocalSftyMgt_tqEfcCoGBx);
   }
   else
   {
      VEMS_vidGET(SftyMgt_tqEfcReqCoCha, s16LocalSftyMgt_tqEfcReqCoCha);
      s16LocalSftyMgt_tqEfcCoGBx =
         (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqEfcReqCoCha, -32000, 32000);
      VEMS_vidSET(SftyMgt_tqEfcCoGBx, s16LocalSftyMgt_tqEfcCoGBx);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidConversion_CME_CMI                              */
/* !Description :  Cette fonction permet de convertir les labels relevés de   */
/*                 CME en CMI par ajout des pertes totales aux couples CME.   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 SftyMgt_tqEfcCoGBx;                                          */
/*  input sint16 SftyMgt_tqSumLossCmp;                                        */
/*  output sint16 SftyMgt_tqIdcCoGBx;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidConversion_CME_CMI(void)
{
   sint16 s16LocalSftyMgt_tqEfcCoGBx;
   sint16 s16LocalSftyMgt_tqSumLossCmp;
   sint16 s16LocalSftyMgt_tqIdcCoGBx;
   sint32 s32LocalSftyMgt_tqIdcCoGBx;


   VEMS_vidGET(SftyMgt_tqEfcCoGBx, s16LocalSftyMgt_tqEfcCoGBx);
   VEMS_vidGET(SftyMgt_tqSumLossCmp, s16LocalSftyMgt_tqSumLossCmp);
   s32LocalSftyMgt_tqIdcCoGBx = (sint32)( s16LocalSftyMgt_tqEfcCoGBx
                                        + s16LocalSftyMgt_tqSumLossCmp);

   s16LocalSftyMgt_tqIdcCoGBx =
      (sint16)MATHSRV_udtCLAMP(s32LocalSftyMgt_tqIdcCoGBx, -32000, 32000);

   VEMS_vidSET(SftyMgt_tqIdcCoGBx, s16LocalSftyMgt_tqIdcCoGBx);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidCoordRelanceRegimeBV                            */
/* !Description :  Cette fonction assure la coordination avec le couple de    */
/*                 régulation de régime pour la relance en régime des boites  */
/*                 de vitesse. Par calibration, on choisi ou non de prendre en*/
/*                 compte le couple de relance.                               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bNRegGBxCf_C;                                       */
/*  input sint16 SftyMgt_tqIdcNReg;                                           */
/*  input sint16 SftyMgt_tqIdcCoGBx;                                          */
/*  output sint16 SftyMgt_tqIdcCoNReg;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidCoordRelanceRegimeBV(void)
{
   sint16 s16LocalSftyMgt_tqIdcNReg;
   sint16 s16LocalSftyMgt_tqIdcCoNReg;
   sint16 s16LocalSftyMgt_tqIdcCoGBx;


   if (SftyMgt_bNRegGBxCf_C != 0)
   {
      VEMS_vidGET(SftyMgt_tqIdcNReg, s16LocalSftyMgt_tqIdcNReg);
      s16LocalSftyMgt_tqIdcCoNReg =
         (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqIdcNReg, -32000, 32000);
      VEMS_vidSET(SftyMgt_tqIdcCoNReg, s16LocalSftyMgt_tqIdcCoNReg);
   }
   else
   {
      VEMS_vidGET(SftyMgt_tqIdcCoGBx, s16LocalSftyMgt_tqIdcCoGBx);
      s16LocalSftyMgt_tqIdcCoNReg =
         (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqIdcCoGBx, -32000, 32000);
      VEMS_vidSET(SftyMgt_tqIdcCoNReg, s16LocalSftyMgt_tqIdcCoNReg);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidCoordonnerLimRalenti                            */
/* !Description :  Cette fonction permet la prise en compte des couples de    */
/*                 limitations safety ainsi que le couple de consigne issu de */
/*                 la régulation ralenti.                                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 SftyMgt_tqIdcCoNReg;                                         */
/*  input sint16 SftyMgt_tqIdcRedEngLim;                                      */
/*  input sint16 SftyMgt_tqIdcIdl;                                            */
/*  input sint16 SftyMgt_tqIdcSysEngLim;                                      */
/*  output sint16 SftyMgt_tqIdcEngLimCo;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidCoordonnerLimRalenti(void)
{
   sint16 s16LocalSftyMgt_tqIdcCoNReg;
   sint16 s16LocalSftyMgt_tqIdcRedEngLim;
   sint16 s16LocalSftyMgt_tqIdcIdl;
   sint16 s16LocalSftyMgt_tqIdcSysEngLim;
   sint16 s16LocalSftyMgt_tqIdcEngLimCo;
   sint16 s16LocalMin;
   sint16 s16LocalMax;


   VEMS_vidGET(SftyMgt_tqIdcCoNReg, s16LocalSftyMgt_tqIdcCoNReg);
   VEMS_vidGET(SftyMgt_tqIdcRedEngLim, s16LocalSftyMgt_tqIdcRedEngLim);
   VEMS_vidGET(SftyMgt_tqIdcIdl, s16LocalSftyMgt_tqIdcIdl);
   VEMS_vidGET(SftyMgt_tqIdcSysEngLim, s16LocalSftyMgt_tqIdcSysEngLim);

   s16LocalMin = (sint16)MATHSRV_udtMIN(s16LocalSftyMgt_tqIdcCoNReg,
                                        s16LocalSftyMgt_tqIdcRedEngLim);

   s16LocalMax = (sint16)MATHSRV_udtMAX(s16LocalMin, s16LocalSftyMgt_tqIdcIdl);

   s16LocalMin = (sint16)MATHSRV_udtMIN(s16LocalMax,
                                        s16LocalSftyMgt_tqIdcSysEngLim);

   s16LocalSftyMgt_tqIdcEngLimCo = (sint16)MATHSRV_udtCLAMP(s16LocalMin,
                                                            -32000,
                                                            32000);

   VEMS_vidSET(SftyMgt_tqIdcEngLimCo, s16LocalSftyMgt_tqIdcEngLimCo);
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/