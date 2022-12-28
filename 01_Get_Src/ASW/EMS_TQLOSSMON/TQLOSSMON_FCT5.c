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
/* !File            : TQLOSSMON_FCT5.C                                        */
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
/*   1 / TQLOSSMON_vidDet_Pertes_BVA                                          */
/*   2 / TQLOSSMON_vidTraiter_entrees                                         */
/*   3 / TQLOSSMON_vidDet_Consigne_Couple                                     */
/*   4 / TQLOSSMON_vidDet_Coef_Filtre                                         */
/*   5 / TQLOSSMON_vidFiltrer_consigne                                        */
/*   6 / TQLOSSMON_vidValider_consigne                                        */
/*   7 / TQLOSSMON_vidCoordonner_pertes                                       */
/*   8 / TQLOSSMON_vidValider_Pertes_Glob                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 01233 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_1793 / 1.5                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQLOSSMON/TQLOSSMON_FC$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   28 Jun 2013 $*/
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
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_BVA                                */
/* !Description :  Cette fonction calcule une enveloppe max des pertes BVA.   */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLOSSMON_vidTraiter_entrees();                          */
/*  extf argret void TQLOSSMON_vidDet_Consigne_Couple();                      */
/*  extf argret void TQLOSSMON_vidDet_Coef_Filtre();                          */
/*  extf argret void TQLOSSMON_vidFiltrer_consigne();                         */
/*  extf argret void TQLOSSMON_vidValider_consigne();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_BVA(void)
{
   TQLOSSMON_vidTraiter_entrees();
   TQLOSSMON_vidDet_Consigne_Couple();
   TQLOSSMON_vidDet_Coef_Filtre();
   TQLOSSMON_vidFiltrer_consigne();
   TQLOSSMON_vidValider_consigne();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidTraiter_entrees                               */
/* !Description :  Cette fonction réalise le traitement de l’info vitesse     */
/*                 véhicule. En cas de défaut de cette  vitesse, elle passe à */
/*                 une valeur refuge.                                         */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_031.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bInhCnvLossMdl_FRM;                                 */
/*  input uint16 SftyMgt_spdVehBuf;                                           */
/*  input uint16 SftyMgt_spdDftCnvLoss_C;                                     */
/*  output uint16 SftyMgt_spdSel;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidTraiter_entrees(void)
{
   boolean bLocalSftyMgt_bInhCnvLossMdl_FRM;
   uint16  u16LocalSftyMgt_spdSel;
   uint16  u16LocalSftyMgt_spdVehBuf;


   VEMS_vidGET(SftyMgt_bInhCnvLossMdl_FRM, bLocalSftyMgt_bInhCnvLossMdl_FRM);
   VEMS_vidGET(SftyMgt_spdVehBuf, u16LocalSftyMgt_spdVehBuf);

   if (bLocalSftyMgt_bInhCnvLossMdl_FRM != 0)
   {
      u16LocalSftyMgt_spdSel = (uint16)((SftyMgt_spdDftCnvLoss_C * 25) / 32);
   }
   else
   {
      u16LocalSftyMgt_spdSel = (uint16)((u16LocalSftyMgt_spdVehBuf * 25) / 32);
   }
   SftyMgt_spdSel = (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_spdSel, 50000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Consigne_Couple                           */
/* !Description :  La valeur max du couple prélevé par le convertisseur est   */
/*                 pondérée par la vitesse.                                   */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_032.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_spdSel;                                              */
/*  input uint16 SftyMgt_spdTqCmp_A[5];                                       */
/*  input uint8 SftyMgt_facCnvLoss_Spd_T[5];                                  */
/*  input uint16 SftyMgt_tqCnvLossMax_C;                                      */
/*  output uint16 SftyMgt_tqCnvLossNotFilNotSat;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Consigne_Couple(void)
{
   uint8  u8LocalCkFricLoss;
   uint16 u16LocalSftyMgt_spdSel;
   uint16 u16LocalCalcPara;
   uint32 u32LocalCnvLossNotFilNotSat;


   u16LocalSftyMgt_spdSel = (uint16)((SftyMgt_spdSel * 4) / 25);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_spdTqCmp_A,
                                                   u16LocalSftyMgt_spdSel,
                                                   5);
   u8LocalCkFricLoss = MATHSRV_u8Interp1d(SftyMgt_facCnvLoss_Spd_T,
                                           u16LocalCalcPara);

   u32LocalCnvLossNotFilNotSat = (uint32)( ( u8LocalCkFricLoss
                                           * SftyMgt_tqCnvLossMax_C)
                                         / 128);
   SftyMgt_tqCnvLossNotFilNotSat =
      (uint16)MATHSRV_udtMIN(u32LocalCnvLossNotFilNotSat, 8000);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Coef_Filtre                               */
/* !Description :  Cette fonction permet de déterminer l e coefficient de     */
/*                 filtrage du couple en fonction du régime moteur et de      */
/*                 l’estimation du couple prélevé.                            */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_nCk_X_A[16];                                         */
/*  input uint16 SftyMgt_facFilTqCnvLossUp_T[16];                             */
/*  input uint16 SftyMgt_facFilTqCnvLossDown_T[16];                           */
/*  input boolean TQLOSSMON_bCnvLossSat;                                      */
/*  input uint16 SftyMgt_facFilTqCnvLossUp_MP;                                */
/*  input uint16 SftyMgt_facFilTqCnvLossDown_MP;                              */
/*  input uint16 SftyMgt_tqCnvLossNotSat;                                     */
/*  input uint16 SftyMgt_tqCnvLossNotFilNotSat;                               */
/*  output uint16 SftyMgt_facFilTqCnvLossUp_MP;                               */
/*  output uint16 SftyMgt_facFilTqCnvLossDown_MP;                             */
/*  output uint16 SftyMgt_facFilTqCnvLoss;                                    */
/*  output boolean TQLOSSMON_bCnvLossSat;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Coef_Filtre(void)
{
   uint16 u16LocalCalcPara;
   uint16 u16LocalSftyMgt_nCkFilBuf;
   uint16 u16LocalSftyMgtFacTqCnvLossUp;
   uint16 u16LocalSftyMgtFacTqCnvLossDown;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCk_X_A,
                                                   u16LocalSftyMgt_nCkFilBuf,
                                                   16);
   u16LocalSftyMgtFacTqCnvLossUp =
      MATHSRV_u16Interp1d(SftyMgt_facFilTqCnvLossUp_T, u16LocalCalcPara);

   SftyMgt_facFilTqCnvLossUp_MP =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgtFacTqCnvLossUp, 999);

   u16LocalSftyMgtFacTqCnvLossDown =
      MATHSRV_u16Interp1d(SftyMgt_facFilTqCnvLossDown_T, u16LocalCalcPara);

   SftyMgt_facFilTqCnvLossDown_MP =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgtFacTqCnvLossDown, 999);

   if (TQLOSSMON_bCnvLossSat != 0)
   {
      SftyMgt_facFilTqCnvLoss = SftyMgt_facFilTqCnvLossUp_MP;
   }
   else
   {
      SftyMgt_facFilTqCnvLoss = SftyMgt_facFilTqCnvLossDown_MP;
   }

   if (SftyMgt_tqCnvLossNotSat <= SftyMgt_tqCnvLossNotFilNotSat)
   {
      TQLOSSMON_bCnvLossSat = 1;
   }
   else
   {
      TQLOSSMON_bCnvLossSat = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidFiltrer_consigne                              */
/* !Description :  Cette fonction filtre le couple prélevé estimé.            */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_034.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_facFilTqCnvLoss;                                     */
/*  input uint16 SftyMgt_tqCnvLossNotFilNotSat;                               */
/*  input uint16 SftyMgt_tqCnvLossSum_MP;                                     */
/*  input uint16 SftyMgt_facFilTqCnvLossFil_MP;                               */
/*  input uint16 SftyMgt_tqCnvLossNotSat;                                     */
/*  input uint16 SftyMgt_tqCnvLossMin_C;                                      */
/*  input uint16 SftyMgt_tqCnvLossMax_C;                                      */
/*  output uint16 SftyMgt_facFilTqCnvLossFil_MP;                              */
/*  output uint16 SftyMgt_tqCnvLossSum_MP;                                    */
/*  output uint16 SftyMgt_tqCnvLossNotSat;                                    */
/*  output uint16 SftyMgt_tqCnvLossEstimMax;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidFiltrer_consigne(void)
{
   uint16 u16LocalCnvLossEstim;
   uint32 u32LocalUnsignedDiff;
   uint32 u32LocalModifCoeff;
   sint32 s32LocalSignedDiff;
   sint32 s32LocaltqStgPmpLossSum;


   u32LocalModifCoeff = (uint32)(1000000 / (SftyMgt_facFilTqCnvLoss + 1));
   u32LocalModifCoeff = (u32LocalModifCoeff + 3000);
   u32LocalModifCoeff = (4000000000uL / u32LocalModifCoeff);
   u32LocalModifCoeff = (u32LocalModifCoeff - 1000);
   u32LocalModifCoeff = (u32LocalModifCoeff / 1000);

   SftyMgt_facFilTqCnvLossFil_MP =
      (uint16)MATHSRV_udtMIN(u32LocalModifCoeff, 999);

   s32LocalSignedDiff = (sint32)( SftyMgt_tqCnvLossNotFilNotSat
                                - SftyMgt_tqCnvLossSum_MP);

   u32LocalUnsignedDiff = (uint32)(SftyMgt_facFilTqCnvLossFil_MP + 1);

   s32LocaltqStgPmpLossSum = s32LocalSignedDiff * (sint32)u32LocalUnsignedDiff;

   s32LocaltqStgPmpLossSum = ( s32LocaltqStgPmpLossSum
                             + (SftyMgt_tqCnvLossSum_MP * 1000));
   s32LocaltqStgPmpLossSum = (s32LocaltqStgPmpLossSum / 1000);

   SftyMgt_tqCnvLossSum_MP =
      (uint16)MATHSRV_udtMIN(s32LocaltqStgPmpLossSum, 8000);

   if (SftyMgt_facFilTqCnvLoss == 999)
   {
      SftyMgt_tqCnvLossNotSat = SftyMgt_tqCnvLossNotFilNotSat;
   }
   else
   {
      SftyMgt_tqCnvLossNotSat = SftyMgt_tqCnvLossSum_MP;
   }

   u16LocalCnvLossEstim = (uint16)MATHSRV_udtCLAMP(SftyMgt_tqCnvLossNotSat,
                                                   SftyMgt_tqCnvLossMin_C,
                                                   SftyMgt_tqCnvLossMax_C);

   SftyMgt_tqCnvLossEstimMax = (uint16)MATHSRV_udtMIN(u16LocalCnvLossEstim,
                                                      8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidValider_consigne                              */
/* !Description :  Cette fonction valide l’estimation du couple prélevé par le*/
/*                 convertisseur.                                             */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_035.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_tqCnvLossUnChkBuf;                                   */
/*  input uint16 SftyMgt_tqErrThdSftyLossBVA_C;                               */
/*  input uint16 SftyMgt_tqCnvLossEstimMax;                                   */
/*  input uint16 SftyMgt_tqCnvLoss_MP;                                        */
/*  output uint16 SftyMgt_tqCnvLoss_MP;                                       */
/*  output boolean SftyMgt_bDgoEngLossBVA;                                    */
/*  output uint16 SftyMgt_tqCnvLossChkBuf;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidValider_consigne(void)
{
   uint16 u16LocalSftyMgt_tqCnvLosUnChkBuf;
   uint32 u32LocaltqCnvLoss;


   VEMS_vidGET(SftyMgt_tqCnvLossUnChkBuf, u16LocalSftyMgt_tqCnvLosUnChkBuf);

   u32LocaltqCnvLoss = (uint32)( SftyMgt_tqErrThdSftyLossBVA_C
                               + SftyMgt_tqCnvLossEstimMax);

   SftyMgt_tqCnvLoss_MP = (uint16)MATHSRV_udtMIN(u32LocaltqCnvLoss, 8000);

   if (SftyMgt_tqCnvLoss_MP < u16LocalSftyMgt_tqCnvLosUnChkBuf)
   {
      SftyMgt_bDgoEngLossBVA = 1;
   }
   else
   {
      SftyMgt_bDgoEngLossBVA = 0;
   }

   SftyMgt_tqCnvLossChkBuf =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_tqCnvLosUnChkBuf, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidCoordonner_pertes                             */
/* !Description :  Cette fonction somme les contributions des différentes sous*/
/*                 fonctions de calcul des pertes.                            */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_036.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bSumLossCmpCnv_C;                                   */
/*  input uint16 SftyMgt_tqCnvLossChkBuf;                                     */
/*  input uint16 SftyMgt_tqAuxSumLossCmp;                                     */
/*  input uint16 SftyMgt_tqCkEngLossChkBuf;                                   */
/*  input uint16 SftyMgt_tqCkEngLossAdpChkBuf;                                */
/*  output uint16 SftyMgt_tqSumLossCmpEstim;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidCoordonner_pertes(void)
{
   uint16 u16LocalSwitchOutput;
   uint32 u32LocaltqSumLossCmpEstim;


   if (SftyMgt_bSumLossCmpCnv_C != 0)
   {
      u16LocalSwitchOutput = SftyMgt_tqCnvLossChkBuf;
   }
   else
   {
      u16LocalSwitchOutput = 0;
   }

   u32LocaltqSumLossCmpEstim = (uint32)( ( ( SftyMgt_tqAuxSumLossCmp
                                           + SftyMgt_tqCkEngLossChkBuf)
                                         + SftyMgt_tqCkEngLossAdpChkBuf)
                                       + u16LocalSwitchOutput);

   SftyMgt_tqSumLossCmpEstim =
      (uint16)MATHSRV_udtMIN(u32LocaltqSumLossCmpEstim, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidValider_Pertes_Glob                           */
/* !Description :  Cette fonction fait la synthèse des levées de défauts et   */
/*                 valide le couple final des pertes.                         */
/* !Number      :  FCT5.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_037.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoTqStg;                                          */
/*  input boolean SftyMgt_bDgoTqAC;                                           */
/*  input boolean SftyMgt_bDgoTqFanRes;                                       */
/*  input boolean SftyMgt_bDgoTqAltLoss;                                      */
/*  input boolean SftyMgt_bDgoTqAuxLoss;                                      */
/*  input boolean TQLOSSMON_bFstFunctDebTODInPrev;                            */
/*  input uint16 SftyMgt_tiDlyLossAuxDftOn_C;                                 */
/*  input uint16 TQLOSSMON_u16FirstDebFctCounter;                             */
/*  input uint16 SftyMgt_tiDlyLossAuxDftOff_C;                                */
/*  input boolean TQLOSSMON_bFstDebOutput;                                    */
/*  input boolean SftyMgt_bDgoTqCkEngLoss;                                    */
/*  input boolean TQLOSSMON_bDgoTqCkEngLossPrev;                              */
/*  input uint16 SftyMgt_tiDlyEngLossDftOn_C;                                 */
/*  input uint16 TQLOSSMON_u16SecondDebFctCounter;                            */
/*  input uint16 SftyMgt_tiDlyEngLossDftOff_C;                                */
/*  input boolean TQLOSSMON_bSndDebOutput;                                    */
/*  input boolean SftyMgt_bDgoEngLossBVA;                                     */
/*  input boolean TQLOSSMON_bDgoEngLossBVAPrev;                               */
/*  input uint16 SftyMgt_tiDlyLossBVADftOn_C;                                 */
/*  input uint16 TQLOSSMON_u16ThirdDebFctCounter;                             */
/*  input uint16 SftyMgt_tiDlyLossBVADftOff_C;                                */
/*  input boolean TQLOSSMON_bThdDebOutput;                                    */
/*  input sint16 SftyMgt_tqSumLossCmpUnChkBuf;                                */
/*  input uint16 SftyMgt_tqSumLossCmpEstim;                                   */
/*  input boolean TQLOSSMON_bSumLossCmpPrev;                                  */
/*  input uint16 SftyMgt_tiDlySumLossDftOn_C;                                 */
/*  input uint16 TQLOSSMON_u16FourthDebFctCounter;                            */
/*  input uint16 SftyMgt_tiDlySumLossDftOff_C;                                */
/*  input boolean TQLOSSMON_bForDebOutput;                                    */
/*  input boolean SftyMgt_bDgoEngLossAdp;                                     */
/*  output uint16 TQLOSSMON_u16FirstDebFctCounter;                            */
/*  output boolean TQLOSSMON_bFstFunctDebTODInPrev;                           */
/*  output boolean TQLOSSMON_bFstDebOutput;                                   */
/*  output uint16 TQLOSSMON_u16SecondDebFctCounter;                           */
/*  output boolean TQLOSSMON_bSndDebOutput;                                   */
/*  output boolean TQLOSSMON_bDgoTqCkEngLossPrev;                             */
/*  output uint16 TQLOSSMON_u16ThirdDebFctCounter;                            */
/*  output boolean TQLOSSMON_bThdDebOutput;                                   */
/*  output boolean TQLOSSMON_bDgoEngLossBVAPrev;                              */
/*  output uint16 SftyMgt_tqSumLossCmpChkBuf;                                 */
/*  output uint16 TQLOSSMON_u16FourthDebFctCounter;                           */
/*  output boolean TQLOSSMON_bSumLossCmpPrev;                                 */
/*  output boolean TQLOSSMON_bForDebOutput;                                   */
/*  output boolean SftyMgt_bDgoTqSumLossCmp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidValider_Pertes_Glob(void)
{
   boolean bLocalFlipFlopSetInput;
   boolean bLocalFlipFlopRstInput;
   sint16  s16LocaltqSumLossCmpUnChkBuf;
   uint16  u16LocalSftyMgt_tqSumLossCmpChkB;
   sint32  s32LocalCounter;


   /* Fonction_Debounce */
   if (  (SftyMgt_bDgoTqStg != 0)
      || (SftyMgt_bDgoTqAC != 0)
      || (SftyMgt_bDgoTqFanRes != 0)
      || (SftyMgt_bDgoTqAltLoss != 0)
      || (SftyMgt_bDgoTqAuxLoss != 0))
   {
      bLocalFlipFlopRstInput = 0;

      if (TQLOSSMON_bFstFunctDebTODInPrev == 0)
      {
         TQLOSSMON_u16FirstDebFctCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyLossAuxDftOn_C, 65500);
      }
      else
      {
         if (TQLOSSMON_u16FirstDebFctCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16FirstDebFctCounter - 4);
            TQLOSSMON_u16FirstDebFctCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 65500);
         }
      }

      if (TQLOSSMON_u16FirstDebFctCounter == 0)
      {
         bLocalFlipFlopSetInput = 1;
      }
      else
      {
         bLocalFlipFlopSetInput = 0;
      }
      TQLOSSMON_bFstFunctDebTODInPrev = 1;
   }
   else
   {
      bLocalFlipFlopSetInput = 0;

      if (TQLOSSMON_bFstFunctDebTODInPrev != 0)
      {
         TQLOSSMON_u16FirstDebFctCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyLossAuxDftOff_C, 65500);
      }
      else
      {
         if (TQLOSSMON_u16FirstDebFctCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16FirstDebFctCounter - 4);
            TQLOSSMON_u16FirstDebFctCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 65500);
         }
      }

      if (TQLOSSMON_u16FirstDebFctCounter == 0)
      {
         bLocalFlipFlopRstInput = 1;
      }
      else
      {
         bLocalFlipFlopRstInput = 0;
      }
      TQLOSSMON_bFstFunctDebTODInPrev = 0;
   }

   if (  (bLocalFlipFlopRstInput == 0)
      && (  (bLocalFlipFlopSetInput != 0)
         || (TQLOSSMON_bFstDebOutput != 0)))
   {
      TQLOSSMON_bFstDebOutput = 1;
   }
   else
   {
      TQLOSSMON_bFstDebOutput = 0;
   }

   /* Fonction_Debounce1 */
   if (SftyMgt_bDgoTqCkEngLoss != 0)
   {
      bLocalFlipFlopRstInput = 0;

      if (TQLOSSMON_bDgoTqCkEngLossPrev == 0)
      {
         TQLOSSMON_u16SecondDebFctCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyEngLossDftOn_C, 65500);
      }
      else
      {
         if (TQLOSSMON_u16SecondDebFctCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16SecondDebFctCounter - 4);
            TQLOSSMON_u16SecondDebFctCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 65500);
         }
      }

      if (TQLOSSMON_u16SecondDebFctCounter == 0)
      {
         bLocalFlipFlopSetInput = 1;
      }
      else
      {
         bLocalFlipFlopSetInput = 0;
      }
   }
   else
   {
      bLocalFlipFlopSetInput = 0;

      if (TQLOSSMON_bDgoTqCkEngLossPrev != 0)
      {
         TQLOSSMON_u16SecondDebFctCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyEngLossDftOff_C, 65500);
      }
      else
      {
         if (TQLOSSMON_u16SecondDebFctCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16SecondDebFctCounter - 4);
            TQLOSSMON_u16SecondDebFctCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 65500);
         }
      }

      if (TQLOSSMON_u16SecondDebFctCounter == 0)
      {
         bLocalFlipFlopRstInput = 1;
      }
      else
      {
         bLocalFlipFlopRstInput = 0;
      }
   }

   if (  (bLocalFlipFlopRstInput == 0)
      && (  (bLocalFlipFlopSetInput != 0)
         || (TQLOSSMON_bSndDebOutput != 0)))
   {
      TQLOSSMON_bSndDebOutput = 1;
   }
   else
   {
      TQLOSSMON_bSndDebOutput = 0;
   }

   /* Calcul of the previous value of SftyMgt_bDgoTqCkEngLoss */
   TQLOSSMON_bDgoTqCkEngLossPrev = SftyMgt_bDgoTqCkEngLoss;

   /* Fonction_Debounce2 */
   if (SftyMgt_bDgoEngLossBVA != 0)
   {
      bLocalFlipFlopRstInput = 0;

      if (TQLOSSMON_bDgoEngLossBVAPrev == 0)
      {
         TQLOSSMON_u16ThirdDebFctCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyLossBVADftOn_C, 65500);
      }
      else
      {
         if (TQLOSSMON_u16ThirdDebFctCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16ThirdDebFctCounter - 4);
            TQLOSSMON_u16ThirdDebFctCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 65500);
         }
      }

      if (TQLOSSMON_u16ThirdDebFctCounter == 0)
      {
         bLocalFlipFlopSetInput = 1;
      }
      else
      {
         bLocalFlipFlopSetInput = 0;
      }
   }
   else
   {
      bLocalFlipFlopSetInput = 0;

      if (TQLOSSMON_bDgoEngLossBVAPrev != 0)
      {
         TQLOSSMON_u16ThirdDebFctCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyLossBVADftOff_C, 65500);
      }
      else
      {
         if (TQLOSSMON_u16ThirdDebFctCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16ThirdDebFctCounter - 4);
            TQLOSSMON_u16ThirdDebFctCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 65500);
         }
      }

      if (TQLOSSMON_u16ThirdDebFctCounter == 0)
      {
         bLocalFlipFlopRstInput = 1;
      }
      else
      {
         bLocalFlipFlopRstInput = 0;
      }
   }

   if (  (bLocalFlipFlopRstInput == 0)
      && (  (bLocalFlipFlopSetInput != 0)
         || (TQLOSSMON_bThdDebOutput != 0)))
   {
      TQLOSSMON_bThdDebOutput = 1;
   }
   else
   {
      TQLOSSMON_bThdDebOutput = 0;
   }

   /* Calcul of the previous value of SftyMgt_bDgoEngLossBVA */
   TQLOSSMON_bDgoEngLossBVAPrev = SftyMgt_bDgoEngLossBVA;

   VEMS_vidGET(SftyMgt_tqSumLossCmpUnChkBuf, s16LocaltqSumLossCmpUnChkBuf);
   u16LocalSftyMgt_tqSumLossCmpChkB =
      (uint16)MATHSRV_udtCLAMP(s16LocaltqSumLossCmpUnChkBuf, 0, 8000);
   VEMS_vidSET(SftyMgt_tqSumLossCmpChkBuf, u16LocalSftyMgt_tqSumLossCmpChkB);

   /* Fonction_Debounce3 */
   if (SftyMgt_tqSumLossCmpEstim < s16LocaltqSumLossCmpUnChkBuf)
   {
      bLocalFlipFlopRstInput = 0;

      if (TQLOSSMON_bSumLossCmpPrev == 0)
      {
         TQLOSSMON_u16FourthDebFctCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlySumLossDftOn_C, 65500);
      }
      else
      {
         if (TQLOSSMON_u16FourthDebFctCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16FourthDebFctCounter - 4);
            TQLOSSMON_u16FourthDebFctCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 65500);
         }
      }

      if (TQLOSSMON_u16FourthDebFctCounter == 0)
      {
         bLocalFlipFlopSetInput = 1;
      }
      else
      {
         bLocalFlipFlopSetInput = 0;
      }
      TQLOSSMON_bSumLossCmpPrev = 1;
   }
   else
   {
      bLocalFlipFlopSetInput = 0;

      if (TQLOSSMON_bSumLossCmpPrev != 0)
      {
         TQLOSSMON_u16FourthDebFctCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlySumLossDftOff_C, 65500);
      }
      else
      {
         if (TQLOSSMON_u16FourthDebFctCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16FourthDebFctCounter - 4);
            TQLOSSMON_u16FourthDebFctCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 65500);
         }
      }

      if (TQLOSSMON_u16FourthDebFctCounter == 0)
      {
         bLocalFlipFlopRstInput = 1;
      }
      else
      {
         bLocalFlipFlopRstInput = 0;
      }
      TQLOSSMON_bSumLossCmpPrev = 0;
   }

   if (  (bLocalFlipFlopRstInput == 0)
      && (  (bLocalFlipFlopSetInput != 0)
         || (TQLOSSMON_bForDebOutput != 0)))
   {
      TQLOSSMON_bForDebOutput = 1;
   }
   else
   {
      TQLOSSMON_bForDebOutput = 0;
   }

   if (  (TQLOSSMON_bFstDebOutput != 0)
      || (TQLOSSMON_bSndDebOutput != 0)
      || (TQLOSSMON_bThdDebOutput != 0)
      || (TQLOSSMON_bForDebOutput != 0)
      || (SftyMgt_bDgoEngLossAdp != 0))
   {
      VEMS_vidSET(SftyMgt_bDgoTqSumLossCmp, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoTqSumLossCmp, 0);
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*---------------------------- end of file -----------------------------------*/