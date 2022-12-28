/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYMGTIFTQ                                             */
/* !Description     : SFTYMGTIFTQ component.                                  */
/*                                                                            */
/* !Module          : SFTYMGTIFTQ                                             */
/* !Description     : SAFETY TMS: interface avec LDA/LDB de la structure      */
/*                    d'accueil                                               */
/*                                                                            */
/* !File            : SFTYMGTIFTQ_FCT3.C                                      */
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
/*   1 / SFTYMGTIFTQ_vidAccPAcquiSftyLvl2                                     */
/*   2 / SFTYMGTIFTQ_vidBrkAcquiSftyLvl2                                      */
/*   3 / SFTYMGTIFTQ_vidThrAcquiSftyLvl2                                      */
/*   4 / SFTYMGTIFTQ_vidCluAcquiSftyLvl2                                      */
/*   5 / SFTYMGTIFTQ_vidNeutPosnAqSftLvl2                                     */
/*   6 / SFTYMGTIFTQ_vidFstftLvl3                                             */
/*   7 / SFTYMGTIFTQ_vidRam_uncleared                                         */
/*   8 / SFTYMGTIFTQ_vidRst                                                   */
/*   9 / SFTYMGTIFTQ_vidRstHw                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5147394 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SFTYMGTIFTQ.h"
#include "SFTYMGTIFTQ_L.h"
#include "SFTYMGTIFTQ_IM.h"
#include "LIBSFTYLVL2.h"
#include "ADCHAL.h"
#include "PWDHAL.h"
#include "DGOHAL.h"
#include "RSTSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidAccPAcquiSftyLvl2                           */
/* !Description :  Ce bloc décrit l’acquisition sans filtrage de l’information*/
/*                 des capteurs de la pédale d’accélération.                  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint16 SftyMgt_uAccPSen1Min_C;                                      */
/*  input uint16 SftyMgt_uAccPSen2Min_C;                                      */
/*  input uint16 SftyMgt_rAccPMax_C;                                          */
/*  input boolean SftyMgt_bDftStuckAccP;                                      */
/*  input uint8 SftyMgt_nUpThd_StuckAccP_C;                                   */
/*  input uint8 SftyMgt_nDownThd_StuckAccP_C;                                 */
/*  input uint8 SftyMgt_nInitCpt_StuckAccP_C;                                 */
/*  input uint8 SftyMgt_nDecCpt_StuckAccP_C;                                  */
/*  input uint8 SFTYMGTIFTQ_u8CntFilt_1;                                      */
/*  input boolean SFTYMGTIFTQ_bFilSig_1;                                      */
/*  input uint8 SFTYMGTIFTQ_CtDftSftyStuckAccP;                               */
/*  input boolean SFTYMGTIFTQ_bStuckAccP;                                     */
/*  output uint16 SftyMgt_uAccPSen1;                                          */
/*  output uint16 SftyMgt_uAccPSen2;                                          */
/*  output boolean SftyMgt_bDftStuckAccP;                                     */
/*  output uint16 SftyMgt_rAccP;                                              */
/*  output boolean SftyMgt_bDftSftyStuckAccP;                                 */
/*  output boolean SFTYMGTIFTQ_bStuckAccP;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidAccPAcquiSftyLvl2(void)
{
   uint16               u16LocalAccP_rAccP;
   uint16               u16LocalSftyMgt_rAccP;
   uint16               u16LocalSftyMgt_uAccPSen_1;
   uint16               u16LocalSftyMgt_uAccPSen_2;
   ADCHAL_tudtAdcResult u16LocalSftyMgt_uAccPSen1;
   ADCHAL_tudtAdcResult u16LocalSftyMgt_uAccPSen2;


   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);

   u16LocalSftyMgt_uAccPSen1 = ADCHAL_udtRead(CH_ADC_PDL_V_1);
   u16LocalSftyMgt_uAccPSen1 =
      (uint16)(((u16LocalSftyMgt_uAccPSen1 * 125) + 256) / 512);
   u16LocalSftyMgt_uAccPSen_1 =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_uAccPSen1, 1000);
   VEMS_vidSET(SftyMgt_uAccPSen1, u16LocalSftyMgt_uAccPSen_1);

   u16LocalSftyMgt_uAccPSen2 = ADCHAL_udtRead(CH_ADC_PDL_V_2);
   u16LocalSftyMgt_uAccPSen2 =
      (uint16)(((u16LocalSftyMgt_uAccPSen2 * 125) + 256) / 512);
   u16LocalSftyMgt_uAccPSen_2 =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_uAccPSen2, 1000);
   VEMS_vidSET(SftyMgt_uAccPSen2, u16LocalSftyMgt_uAccPSen_2);

   if (  (u16LocalSftyMgt_uAccPSen1 < SftyMgt_uAccPSen1Min_C)
      && (u16LocalSftyMgt_uAccPSen2 < SftyMgt_uAccPSen2Min_C)
      && (u16LocalAccP_rAccP > SftyMgt_rAccPMax_C))
   {
      SftyMgt_bDftStuckAccP = 1;
      u16LocalSftyMgt_rAccP = 0;
   }
   else
   {
      SftyMgt_bDftStuckAccP = 0;
      u16LocalSftyMgt_rAccP =
         (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccP, 12800);
   }
   VEMS_vidSET(SftyMgt_rAccP, u16LocalSftyMgt_rAccP);

   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftStuckAccP,
                                SftyMgt_nUpThd_StuckAccP_C,
                                SftyMgt_nDownThd_StuckAccP_C,
                                SftyMgt_nInitCpt_StuckAccP_C,
                                SftyMgt_nDecCpt_StuckAccP_C,
                                &SFTYMGTIFTQ_u8CntFilt_1,
                                &SFTYMGTIFTQ_bFilSig_1,
                                &SFTYMGTIFTQ_CtDftSftyStuckAccP,
                                &SFTYMGTIFTQ_bStuckAccP);
   VEMS_vidSET(SftyMgt_bDftSftyStuckAccP, SFTYMGTIFTQ_bStuckAccP);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidBrkAcquiSftyLvl2                            */
/* !Description :  Ce bloc décrit l’acquisition sans filtrage de l’information*/
/*                 des capteurs de la pédale de frein.                        */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bBrkPedPrss;                                            */
/*  output boolean SftyMgt_bBrkPedPrss;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidBrkAcquiSftyLvl2(void)
{
   boolean bLocalExt_bBrkPedPrss;


   VEMS_vidGET(Ext_bBrkPedPrss, bLocalExt_bBrkPedPrss);
   VEMS_vidSET(SftyMgt_bBrkPedPrss, bLocalExt_bBrkPedPrss);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidThrAcquiSftyLvl2                            */
/* !Description :  Ce bloc décrit l’acquisition sans filtrage de l’information*/
/*                 des capteurs du papillon.                                  */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rOpThr;                                                  */
/*  output uint16 SftyMgt_uThrSen1;                                           */
/*  output uint16 SftyMgt_uThrSen2;                                           */
/*  output uint16 SftyMgt_posnThr;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidThrAcquiSftyLvl2(void)
{
   uint16               u16LocalExt_rOpThr;
   uint16               u16LocalSftyMgt_posnThr;
   ADCHAL_tudtAdcResult u16LocalSftyMgt_uThrSen1;
   ADCHAL_tudtAdcResult u16LocalSftyMgt_uThrSen2;


   u16LocalSftyMgt_uThrSen1 = ADCHAL_udtRead(CH_ADC_THR_V_1);
   u16LocalSftyMgt_uThrSen1 =
      (uint16)(((u16LocalSftyMgt_uThrSen1 * 125) + 256) / 512);
   u16LocalSftyMgt_uThrSen1 =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_uThrSen1, 1000);
   VEMS_vidSET(SftyMgt_uThrSen1, u16LocalSftyMgt_uThrSen1);

   u16LocalSftyMgt_uThrSen2 = ADCHAL_udtRead(CH_ADC_THR_V_2);
   u16LocalSftyMgt_uThrSen2 =
      (uint16)(((u16LocalSftyMgt_uThrSen2 * 125) + 256) / 512);
   u16LocalSftyMgt_uThrSen2 =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_uThrSen2, 1000);
   VEMS_vidSET(SftyMgt_uThrSen2, u16LocalSftyMgt_uThrSen2);

   VEMS_vidGET(Ext_rOpThr, u16LocalExt_rOpThr);
   u16LocalSftyMgt_posnThr =
      (uint16)MATHSRV_udtMIN(u16LocalExt_rOpThr, 1000);
   VEMS_vidSET(SftyMgt_posnThr, u16LocalSftyMgt_posnThr);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidCluAcquiSftyLvl2                            */
/* !Description :  Ce bloc décrit l’acquisition sans filtrage de l’information*/
/*                 des capteurs de la pédale d’embrayage                      */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_vidGetSignalInfo(uint8 u8Channel, uint32          */
/*  *pu32Period, uint16 *pu16DutyCycle);                                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rCluPHiFreq;                                             */
/*  output uint16 SftyMgt_rCluPedSen;                                         */
/*  output uint16 SftyMgt_rCluPedPHiFreq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidCluAcquiSftyLvl2(void)
{
   uint16  u16LocalExt_rCluPHiFreq;
   uint16  u16LocalDutyCycle;
   uint32  u32LocalPeriod;


   PWDHAL_vidGetSignalInfo(CH_PWD_CLUTCH, &u32LocalPeriod, &u16LocalDutyCycle);
   u16LocalDutyCycle = (uint16)(u16LocalDutyCycle / 32);
   u16LocalDutyCycle = (uint16)MATHSRV_udtMIN(u16LocalDutyCycle, 1024);
   VEMS_vidSET(SftyMgt_rCluPedSen, u16LocalDutyCycle);

   VEMS_vidGET(Ext_rCluPHiFreq, u16LocalExt_rCluPHiFreq);
   u16LocalExt_rCluPHiFreq = (uint16)((u16LocalExt_rCluPHiFreq * 5) / 8);
   u16LocalExt_rCluPHiFreq =
      (uint16)MATHSRV_udtMIN(u16LocalExt_rCluPHiFreq, 1000);
   VEMS_vidSET(SftyMgt_rCluPedPHiFreq, u16LocalExt_rCluPHiFreq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidNeutPosnAqSftLvl2                           */
/* !Description :  Ce bloc décrit l’acquisition sans filtrage de l’information*/
/*                 des capteurs de la position point mort.                    */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWDHAL_vidGetSignalInfo(uint8 u8Channel, uint32          */
/*  *pu32Period, uint16 *pu16DutyCycle);                                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bNeut;                                                  */
/*  output uint16 SftyMgt_rNeutSen;                                           */
/*  output boolean SftyMgt_bNeut;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidNeutPosnAqSftLvl2(void)
{
   boolean bLocalExt_bNeut;
   uint16  u16LocalDutyCycle;
   uint32  u32LocalPeriod;


   PWDHAL_vidGetSignalInfo(CH_PWD_CAPTEUR_NEUTRE,
                           &u32LocalPeriod,
                           &u16LocalDutyCycle);
   u16LocalDutyCycle = (uint16)(((u16LocalDutyCycle * 625) + 1024) / 2048);
   u16LocalDutyCycle = (uint16)MATHSRV_udtMIN(u16LocalDutyCycle, 10000);
   VEMS_vidSET(SftyMgt_rNeutSen, u16LocalDutyCycle);

   VEMS_vidGET(Ext_bNeut, bLocalExt_bNeut);
   VEMS_vidSET(SftyMgt_bNeut, bLocalExt_bNeut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidFstftLvl3                                   */
/* !Description :  Panne relative au code et à la calibration de la TMS       */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/* udtChannel);                                                               */
/*  input boolean SftyMgt_bRstThrReq_C;                                       */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Tpim_filtered_inhibit_input;                                */
/*  input boolean SftyMgt_bDgoCalChk;                                         */
/*  input boolean SftyMgt_bDgoSwChk;                                          */
/*  input boolean Sfty_bDgoSftyChkPt_PfcMng;                                  */
/*  input boolean SftyMgt_bDgoALUChk;                                         */
/*  input boolean SftyMgt_bDgoClkChk;                                         */
/*  input boolean SftyMgt_bDgoThrChk;                                         */
/*  input boolean SftyMgt_bDgoAccPChk;                                        */
/*  output boolean Sfty3_bThrReq;                                             */
/*  output boolean SftyMgt_bDgoCalChk;                                        */
/*  output boolean SftyMgt_bDgoSwChk;                                         */
/*  output boolean SftyMgt_bDgoRAMChk;                                        */
/*  output boolean SftyMgt_bDgoRAMChk2;                                       */
/*  output boolean SftyMgt_bDftAutChk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidFstftLvl3(void)
{
   boolean          bLocalTpim_filtered_inhibit_inpu;
   boolean          bLocalSftyMgt_bDgoCalChk;
   boolean          bLocalSftyMgt_bDgoSwChk;
   boolean          bLocalSfty_bDgoSftyChkPt_PfcMng;
   boolean          bLocalSftyMgt_bDgoALUChk;
   boolean          bLocalSftyMgt_bDgoClkChk;
   boolean          bLocalSftyMgt_bDgoThrChk;
   boolean          bLocalSftyMgt_bDgoAccPChk;
   DGOHAL_tbfStatus bfLocalFault;
   uint8            u8LocalTpac_throttle_control_sta;


   if (SftyMgt_bRstThrReq_C != 0)
   {
      VEMS_vidSET(Sfty3_bThrReq, 0);
   }
   else
   {
      VEMS_vidGET(Tpac_throttle_control_state,
                  u8LocalTpac_throttle_control_sta);
      VEMS_vidGET(Tpim_filtered_inhibit_input,
                  bLocalTpim_filtered_inhibit_inpu);
      if (  (u8LocalTpac_throttle_control_sta != TPAC_MCW_INHIBIT_TEST)
         && (bLocalTpim_filtered_inhibit_inpu != 0))
      {
         VEMS_vidSET(Sfty3_bThrReq, 1);
      }
      else
      {
         VEMS_vidSET(Sfty3_bThrReq, 0);
      }
   }

   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtRTMCKS_TMS);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_TMS_CALIB) != 0)
   {
      /* NS_bMonRun1 = 1; */
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_TMS_CALIB) != 0)
      {
         /* NS_bDgo1 = 1; */
         bLocalSftyMgt_bDgoCalChk = 1;
      }
      else
      {
         /* NS_bDgo1 = 0; */
         bLocalSftyMgt_bDgoCalChk = 0;
      }
   }
   else
   {
      VEMS_vidGET(SftyMgt_bDgoCalChk, bLocalSftyMgt_bDgoCalChk);
   }

   VEMS_vidSET(SftyMgt_bDgoCalChk, bLocalSftyMgt_bDgoCalChk);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_TMS_CODE) != 0)
   {
      /* NS_bMonRun2 = 1; */
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_TMS_CODE) != 0)
      {
         /* NS_bDgo2 = 1; */
         bLocalSftyMgt_bDgoSwChk = 1;
      }
      else
      {
         /* NS_bDgo2 = 0; */
         bLocalSftyMgt_bDgoSwChk = 0;
      }
   }
   else
   {
      VEMS_vidGET(SftyMgt_bDgoSwChk, bLocalSftyMgt_bDgoSwChk);
   }

   VEMS_vidSET(SftyMgt_bDgoSwChk, bLocalSftyMgt_bDgoSwChk);

   VEMS_vidSET(SftyMgt_bDgoRAMChk, 0);
   VEMS_vidSET(SftyMgt_bDgoRAMChk2, 0);

   VEMS_vidGET(Sfty_bDgoSftyChkPt_PfcMng, bLocalSfty_bDgoSftyChkPt_PfcMng);
   VEMS_vidGET(SftyMgt_bDgoALUChk, bLocalSftyMgt_bDgoALUChk);
   VEMS_vidGET(SftyMgt_bDgoClkChk, bLocalSftyMgt_bDgoClkChk);
   VEMS_vidGET(SftyMgt_bDgoThrChk, bLocalSftyMgt_bDgoThrChk);
   VEMS_vidGET(SftyMgt_bDgoAccPChk, bLocalSftyMgt_bDgoAccPChk);

   if (  (bLocalSftyMgt_bDgoCalChk != 0)
      || (bLocalSftyMgt_bDgoSwChk != 0)
      || (bLocalSfty_bDgoSftyChkPt_PfcMng != 0)
      || (bLocalSftyMgt_bDgoALUChk != 0)
      || (bLocalSftyMgt_bDgoClkChk != 0)
      || (bLocalSftyMgt_bDgoThrChk != 0)
      || (bLocalSftyMgt_bDgoAccPChk != 0))
   {
      VEMS_vidSET(SftyMgt_bDftAutChk, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDftAutChk, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidRam_uncleared                               */
/* !Description :  Mettre a jour les variables prev de bDgo                   */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SFTYMGTIFTQ_bDgoIrvEMPrev1;                                 */
/*  input boolean SFTYMGTIFTQ_bDgoIrvSTTPrev1;                                */
/*  input boolean SFTYMGTIFTQ_bDgoIrvVSCtlPrev1;                              */
/*  input uint8 SFTYMGTIFTQ_u8ctDftLaddPrev1;                                 */
/*  input boolean SftyMgt_bDgoIrvEM;                                          */
/*  input boolean SftyMgt_bDgoIrvSTT;                                         */
/*  input boolean SftyMgt_bDgoIrvVSCtl;                                       */
/*  input uint8 SftyMgt_ctDftLadd;                                            */
/*  output boolean SftyMgt_bDgoIrvEMPrev;                                     */
/*  output boolean SFTYMGTIFTQ_bDgoIrvEMPrev1;                                */
/*  output boolean SftyMgt_bDgoIrvSTTPrev;                                    */
/*  output boolean SFTYMGTIFTQ_bDgoIrvSTTPrev1;                               */
/*  output boolean SftyMgt_bDgoIrvVSCtlPrev;                                  */
/*  output boolean SFTYMGTIFTQ_bDgoIrvVSCtlPrev1;                             */
/*  output uint8 SftyMgt_ctDftLaddPrev;                                       */
/*  output uint8 SFTYMGTIFTQ_u8ctDftLaddPrev1;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidRam_uncleared(void)
{
   uint8 u8LocalctDftLaddPrev;


   VEMS_vidSET(SftyMgt_bDgoIrvEMPrev, SFTYMGTIFTQ_bDgoIrvEMPrev1);
   VEMS_vidSET(SftyMgt_bDgoIrvSTTPrev, SFTYMGTIFTQ_bDgoIrvSTTPrev1);
   VEMS_vidSET(SftyMgt_bDgoIrvVSCtlPrev, SFTYMGTIFTQ_bDgoIrvVSCtlPrev1);
   u8LocalctDftLaddPrev = SFTYMGTIFTQ_u8ctDftLaddPrev1;
   u8LocalctDftLaddPrev =
      (uint8)MATHSRV_udtMIN(u8LocalctDftLaddPrev, 9);
   VEMS_vidSET(SftyMgt_ctDftLaddPrev, u8LocalctDftLaddPrev);

   VEMS_vidGET(SftyMgt_bDgoIrvEM, SFTYMGTIFTQ_bDgoIrvEMPrev1);
   VEMS_vidGET(SftyMgt_bDgoIrvSTT, SFTYMGTIFTQ_bDgoIrvSTTPrev1);
   VEMS_vidGET(SftyMgt_bDgoIrvVSCtl, SFTYMGTIFTQ_bDgoIrvVSCtlPrev1);
   VEMS_vidGET(SftyMgt_ctDftLadd, SFTYMGTIFTQ_u8ctDftLaddPrev1);
   SFTYMGTIFTQ_u8ctDftLaddPrev1 =
      (uint8)MATHSRV_udtMIN(SFTYMGTIFTQ_u8ctDftLaddPrev1, 9);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidRst                                         */
/* !Description :  Ce module fait le lien entre les booléens de demande de    */
/*                 reset et les services correspondant (les APIs) au niveau du*/
/*                 LDB.                                                       */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_007.01                                     */
/*                 VEMS_R_11_05663_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SFTYMGTIFTQ_vidRstHw();                                  */
/*  extf argret void SFTYMGTIFTQ_vidRstSw();                                  */
/*  extf argret void SFTYMGTIFTQ_vidInerface();                               */
/*  input boolean SftyMgt_bRstHwReq;                                          */
/*  input boolean SftyMgt_bRstSwReq;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidRst(void)
{
   boolean bLocalSftyMgt_bRstHwReq;
   boolean bLocalSftyMgt_bRstSwReq;


   VEMS_vidGET(SftyMgt_bRstHwReq, bLocalSftyMgt_bRstHwReq);
   VEMS_vidGET(SftyMgt_bRstSwReq, bLocalSftyMgt_bRstSwReq);

   if (bLocalSftyMgt_bRstHwReq != 0)
   {
      SFTYMGTIFTQ_vidRstHw();
   }
   if (bLocalSftyMgt_bRstSwReq != 0)
   {
      SFTYMGTIFTQ_vidRstSw();
   }

   SFTYMGTIFTQ_vidInerface();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidRstHw                                       */
/* !Description :  Reset du hard                                              */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RSTSRV_vidPerformReset(argin RSTSRV_tudtResetType        */
/*  udtRequestedResetType);                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidRstHw(void)
{
   RSTSRV_vidPerformReset(RSTSRV_udtHARDWARE_RESET);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/