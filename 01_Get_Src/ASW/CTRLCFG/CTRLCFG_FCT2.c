/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CTRLCFG                                                 */
/* !Description     : CTRLCFG Component                                       */
/*                                                                            */
/* !Module          : CTRLCFG                                                 */
/* !Description     : CONFIGURATION FLOW MANAGEMENT                           */
/*                                                                            */
/* !File            : CTRLCFG_FCT2.C                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CTRLCFG_vidBSIFrame3                                                 */
/*   2 / CTRLCFG_vidBSIFrame4                                                 */
/*   3 / CTRLCFG_vidBSIFrame5                                                 */
/*   4 / CTRLCFG_vidECUFrames                                                 */
/*   5 / CTRLCFG_vidECUFrames2                                                */
/*   6 / CTRLCFG_vidECUFrames3                                                */
/*   7 / CTRLCFG_vidPSFrames                                                  */
/*   8 / CTRLCFG_vidOther_Frames_Param                                        */
/*   9 / CTRLCFG_vidCluFrames                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5068500 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CTRLCFG/CTRLCFG_FCT2.C_v        $*/
/* $Revision::   1.15     $$Author::   pbakabad       $$Date::   Jul 01 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 01 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CTRLCFG.h"
#include "CTRLCFG_L.h"
#include "CTRLCFG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidBSIFrame3                                       */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the BSI are activated or not.          */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_005.05                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Ext_bPACKDYNCf;                                             */
/*  output boolean Ctrl_bDgoBody;                                             */
/*  output boolean Ctrl_bPush;                                                */
/*  output boolean Ctrl_bVSSNwAcvSt;                                          */
/*  output boolean Ctrl_bEngStrtReq;                                          */
/*  output boolean Ctrl_stEngStopAuth;                                        */
/*  output boolean Ctrl_stEngRStrtReq;                                        */
/*  output boolean Ctrl_stDrvAvl;                                             */
/*  output boolean Ctrl_bAcv_bModSptReq;                                      */
/*  output boolean Ctrl_bDynFctAcvSec;                                        */
/*  output boolean Ctrl_bDynFctAcvCplm;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidBSIFrame3(void)
{
   boolean bLocalExt_bSTTCf;
   boolean bLocalExt_bArchiCf;
   boolean bLocalExt_bPACKDYNCf;


   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_bPACKDYNCf, bLocalExt_bPACKDYNCf);
   if (bLocalExt_bSTTCf != 0)
   {
      VEMS_vidSET(Ctrl_bDgoBody, 1);
      VEMS_vidSET(Ctrl_bPush, 1);
      VEMS_vidSET(Ctrl_bVSSNwAcvSt, 1);
      VEMS_vidSET(Ctrl_bEngStrtReq, 1);
      VEMS_vidSET(Ctrl_stEngStopAuth, 1);
      VEMS_vidSET(Ctrl_stEngRStrtReq, 1);
      VEMS_vidSET(Ctrl_stDrvAvl, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bDgoBody, 0);
      VEMS_vidSET(Ctrl_bPush, 0);
      VEMS_vidSET(Ctrl_bVSSNwAcvSt, 0);
      VEMS_vidSET(Ctrl_bEngStrtReq, 0);
      VEMS_vidSET(Ctrl_stEngStopAuth, 0);
      VEMS_vidSET(Ctrl_stEngRStrtReq, 0);
      VEMS_vidSET(Ctrl_stDrvAvl, 0);
   }

   if (  (bLocalExt_bArchiCf != 0)
      && (bLocalExt_bPACKDYNCf != 0))
   {
      VEMS_vidSET(Ctrl_bAcv_bModSptReq, 1);
      VEMS_vidSET(Ctrl_bDynFctAcvSec, 1);
      VEMS_vidSET(Ctrl_bDynFctAcvCplm, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bAcv_bModSptReq, 0);
      VEMS_vidSET(Ctrl_bDynFctAcvSec, 0);
      VEMS_vidSET(Ctrl_bDynFctAcvCplm, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidBSIFrame4                                       */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the BSI are activated or not.          */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_005.05                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Ext_bFSFCf;                                                 */
/*  input uint8 Ext_stElEMgtCf;                                               */
/*  input uint8 Ext_stACTypCf;                                                */
/*  output boolean Ctrl_bOpFSFReq;                                            */
/*  output boolean Ctrl_uReqProdMin;                                          */
/*  output boolean Ctrl_stPrioVoltMin;                                        */
/*  output boolean Ctrl_uReqProdMax;                                          */
/*  output boolean Ctrl_stPrioVoltMax;                                        */
/*  output boolean Ctrl_uReqProdSlope;                                        */
/*  output boolean Ctrl_DAT_BSI_532;                                          */
/*  output boolean Ctrl_BSI_572;                                              */
/*  output boolean Ctrl_uBattClc;                                             */
/*  output boolean Ctrl_stPosn;                                               */
/*  output boolean Ctrl_NEW_JDD_CMM_768;                                      */
/*  output boolean Ctrl_CONTEXTE_1_7F2;                                       */
/*  output boolean Ctrl_JDD_CAN_CMM_768;                                      */
/*  output boolean Ctrl_BSI_552;                                              */
/*  output boolean Ctrl_bEngStrtReq2;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidBSIFrame4(void)
{
   boolean bLocalExt_bArchiCf;
   boolean bLocalExt_bFSFCf;
   uint8   u8LocalExt_stElEMgtCf;
   uint8   u8LocalExt_stACTypCf;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_bFSFCf, bLocalExt_bFSFCf);
   VEMS_vidGET(Ext_stElEMgtCf, u8LocalExt_stElEMgtCf);
   VEMS_vidGET(Ext_stACTypCf, u8LocalExt_stACTypCf);


   if (  (bLocalExt_bFSFCf == 0)
      && (u8LocalExt_stACTypCf != 0) )
   {
      VEMS_vidSET(Ctrl_bOpFSFReq, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bOpFSFReq, 0);
   }

   if (u8LocalExt_stElEMgtCf == 5)
   {
      VEMS_vidSET(Ctrl_uReqProdMin, 1);
      VEMS_vidSET(Ctrl_stPrioVoltMin, 1);
      VEMS_vidSET(Ctrl_uReqProdMax, 1);
      VEMS_vidSET(Ctrl_stPrioVoltMax, 1);
      VEMS_vidSET(Ctrl_uReqProdSlope, 1);
      VEMS_vidSET(Ctrl_DAT_BSI_532, 1);
      VEMS_vidSET(Ctrl_BSI_572, 1);
      VEMS_vidSET(Ctrl_uBattClc, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_uReqProdMin, 0);
      VEMS_vidSET(Ctrl_stPrioVoltMin, 0);
      VEMS_vidSET(Ctrl_uReqProdMax, 0);
      VEMS_vidSET(Ctrl_stPrioVoltMax, 0);
      VEMS_vidSET(Ctrl_uReqProdSlope, 0);
      VEMS_vidSET(Ctrl_DAT_BSI_532, 0);
      VEMS_vidSET(Ctrl_BSI_572, 0);
      VEMS_vidSET(Ctrl_uBattClc, 0);
   }

   if (bLocalExt_bFSFCf != 0)
   {
      VEMS_vidSET(Ctrl_stPosn, 0);
   }
   else
   {
      VEMS_vidSET(Ctrl_stPosn, 1);
   }

   if (bLocalExt_bArchiCf == 0)
   {
      VEMS_vidSET(Ctrl_NEW_JDD_CMM_768, 0);
      VEMS_vidSET(Ctrl_CONTEXTE_1_7F2, 1);
      VEMS_vidSET(Ctrl_JDD_CAN_CMM_768, 1);
      VEMS_vidSET(Ctrl_BSI_552, 1);
      VEMS_vidSET(Ctrl_bEngStrtReq2, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_NEW_JDD_CMM_768, 1);
      VEMS_vidSET(Ctrl_CONTEXTE_1_7F2, 0);
      VEMS_vidSET(Ctrl_JDD_CAN_CMM_768, 0);
      VEMS_vidSET(Ctrl_BSI_552, 0);
      VEMS_vidSET(Ctrl_bEngStrtReq2, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidBSIFrame5                                       */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the BSI are activated or not.          */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_005.05                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 Ext_stACTypCf;                                                */
/*  input boolean Ext_bPACKDYNCf;                                             */
/*  output boolean Ctrl_CMM_438;                                              */
/*  output boolean Ctrl_bACClu;                                               */
/*  output boolean Ctrl_pwrAC;                                                */
/*  output boolean Ctrl_bAcv_rBoostPresSndModSpt;                             */
/*  output boolean Ctrl_bAcv_pwrEngSndModSpt;                                 */
/*  output boolean Ctrl_bAcv_rPwrEngSndModSpt;                                */
/*  output boolean Ctrl_bAcv_tqEfcSndModSpt;                                  */
/*  output boolean Ctrl_bAcv_rTqEfcSndModSpt;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidBSIFrame5(void)
{
   boolean bLocalExt_bArchiCf;
   boolean bLocalExt_bPACKDYNCf;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalExt_stACTypCf;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Ext_stACTypCf, u8LocalExt_stACTypCf);
   VEMS_vidGET(Ext_bPACKDYNCf, bLocalExt_bPACKDYNCf);
   if (  (u8LocalExt_stGBxCf == 1)
      || (bLocalExt_bPACKDYNCf != 0))
   {
      VEMS_vidSET(Ctrl_CMM_438, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_CMM_438, 0);
   }

   if (u8LocalExt_stACTypCf != 0)
   {
      VEMS_vidSET(Ctrl_bACClu, 1);
      VEMS_vidSET(Ctrl_pwrAC, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bACClu, 0);
      VEMS_vidSET(Ctrl_pwrAC, 0);
   }

   if (  (bLocalExt_bArchiCf != 0)
      && (bLocalExt_bPACKDYNCf != 0))
   {
      VEMS_vidSET(Ctrl_bAcv_rBoostPresSndModSpt, 1);
      VEMS_vidSET(Ctrl_bAcv_pwrEngSndModSpt, 1);
      VEMS_vidSET(Ctrl_bAcv_rPwrEngSndModSpt, 1);
      VEMS_vidSET(Ctrl_bAcv_tqEfcSndModSpt, 1);
      VEMS_vidSET(Ctrl_bAcv_rTqEfcSndModSpt, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bAcv_rBoostPresSndModSpt, 0);
      VEMS_vidSET(Ctrl_bAcv_pwrEngSndModSpt, 0);
      VEMS_vidSET(Ctrl_bAcv_rPwrEngSndModSpt, 0);
      VEMS_vidSET(Ctrl_bAcv_tqEfcSndModSpt, 0);
      VEMS_vidSET(Ctrl_bAcv_rTqEfcSndModSpt, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidECUFrames                                       */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the ECU are activated or not.          */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_006.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bFSFCf;                                                 */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input boolean Ext_bG3G4Cf;                                                */
/*  input boolean Ctrl_CMM_208_C;                                             */
/*  input boolean Ctrl_CMM_228_C;                                             */
/*  input boolean Ctrl_CMM_348_C;                                             */
/*  input boolean Ctrl_CMM_468_C;                                             */
/*  input boolean Ctrl_CMM_588_C;                                             */
/*  output boolean Ctrl_CMM_1E8;                                              */
/*  output boolean Ctrl_bRStrtAnt;                                            */
/*  output boolean Ctrl_stTypEmPredRstrt;                                     */
/*  output boolean Ctrl_noEngStrt;                                            */
/*  output boolean Ctrl_uEmPredRstrt;                                         */
/*  output boolean Ctrl_facSen_uEmPredRstrt;                                  */
/*  output boolean Ctrl_bChaTqCrt;                                            */
/*  output boolean Ctrl_bChaTqAvl;                                            */
/*  output boolean Ctrl_STT_CMM_3C8;                                          */
/*  output boolean Ctrl_bInfoRdy;                                             */
/*  output boolean Ctrl_bInfoAcvCluPed;                                       */
/*  output boolean Ctrl_stSTTLightAcv;                                        */
/*  output boolean Ctrl_bRecNotStop;                                          */
/*  output boolean Ctrl_bWaitStrtReq;                                         */
/*  output boolean Ctrl_bAcv_ctStaAcv;                                        */
/*  output boolean Ctrl_stAcvWarn;                                            */
/*  output boolean Ctrl_CMM_208;                                              */
/*  output boolean Ctrl_CMM_208_C;                                            */
/*  output boolean Ctrl_CMM_228;                                              */
/*  output boolean Ctrl_CMM_228_C;                                            */
/*  output boolean Ctrl_CMM_348;                                              */
/*  output boolean Ctrl_CMM_348_C;                                            */
/*  output boolean Ctrl_CMM_468;                                              */
/*  output boolean Ctrl_CMM_468_C;                                            */
/*  output boolean Ctrl_CMM_588;                                              */
/*  output boolean Ctrl_CMM_588_C;                                            */
/*  output boolean Ctrl_stPosnFSFReq;                                         */
/*  output boolean Ctrl_bPosnFSF;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidECUFrames(void)
{
   boolean bLocalExt_bFSFCf;
   boolean bLocalExt_bSTTCf;
   boolean bLocalExt_bG3G4Cf;


   VEMS_vidGET(Ext_bFSFCf, bLocalExt_bFSFCf);
   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_bG3G4Cf, bLocalExt_bG3G4Cf);

   if (  (bLocalExt_bFSFCf == 0)
      || (bLocalExt_bSTTCf != 0) )
   {
      VEMS_vidSET(Ctrl_CMM_1E8, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_CMM_1E8, 0);
   }

   if (bLocalExt_bSTTCf != 0)
   {
      VEMS_vidSET(Ctrl_bRStrtAnt, 1);
      VEMS_vidSET(Ctrl_stTypEmPredRstrt, 1);
      VEMS_vidSET(Ctrl_noEngStrt, 1);
      VEMS_vidSET(Ctrl_uEmPredRstrt, 1);
      VEMS_vidSET(Ctrl_facSen_uEmPredRstrt, 1);
      VEMS_vidSET(Ctrl_bChaTqCrt, 1);
      VEMS_vidSET(Ctrl_bChaTqAvl, 1);
      VEMS_vidSET(Ctrl_STT_CMM_3C8, 1);
      VEMS_vidSET(Ctrl_bInfoRdy, 1);
      VEMS_vidSET(Ctrl_bInfoAcvCluPed, 1);
      VEMS_vidSET(Ctrl_stSTTLightAcv, 1);
      VEMS_vidSET(Ctrl_bRecNotStop, 1);
      VEMS_vidSET(Ctrl_bWaitStrtReq, 1);
      VEMS_vidSET(Ctrl_bAcv_ctStaAcv, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bRStrtAnt, 0);
      VEMS_vidSET(Ctrl_stTypEmPredRstrt, 0);
      VEMS_vidSET(Ctrl_noEngStrt, 0);
      VEMS_vidSET(Ctrl_uEmPredRstrt, 0);
      VEMS_vidSET(Ctrl_facSen_uEmPredRstrt, 0);
      VEMS_vidSET(Ctrl_bChaTqCrt, 0);
      VEMS_vidSET(Ctrl_bChaTqAvl, 0);
      VEMS_vidSET(Ctrl_STT_CMM_3C8, 0);
      VEMS_vidSET(Ctrl_bInfoRdy, 0);
      VEMS_vidSET(Ctrl_bInfoAcvCluPed, 0);
      VEMS_vidSET(Ctrl_stSTTLightAcv, 0);
      VEMS_vidSET(Ctrl_bRecNotStop, 0);
      VEMS_vidSET(Ctrl_bWaitStrtReq, 0);
      VEMS_vidSET(Ctrl_bAcv_ctStaAcv, 0);
   }

   if (  (  (bLocalExt_bSTTCf != 0)
         && (bLocalExt_bG3G4Cf != 0) )
      || (bLocalExt_bG3G4Cf == 0) )
   {
      VEMS_vidSET(Ctrl_stAcvWarn, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_stAcvWarn, 0);
   }
   VEMS_vidSET(Ctrl_CMM_208, Ctrl_CMM_208_C);
   VEMS_vidSET(Ctrl_CMM_228, Ctrl_CMM_228_C);
   VEMS_vidSET(Ctrl_CMM_348, Ctrl_CMM_348_C);
   VEMS_vidSET(Ctrl_CMM_468, Ctrl_CMM_468_C);
   VEMS_vidSET(Ctrl_CMM_588, Ctrl_CMM_588_C);

   if (bLocalExt_bFSFCf != 0)
   {
      VEMS_vidSET(Ctrl_stPosnFSFReq, 0);
      VEMS_vidSET(Ctrl_bPosnFSF, 0);
   }
   else
   {
      VEMS_vidSET(Ctrl_stPosnFSFReq, 1);
      VEMS_vidSET(Ctrl_bPosnFSF, 1);
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidECUFrames2                                      */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the ECU are activated or not.          */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_006.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input uint8 Ext_stDVSRegCf;                                               */
/*  input boolean Ext_bVSLimCf;                                               */
/*  input boolean Ext_bEasyMoveCf;                                            */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  output boolean Ctrl_bStopIp;                                              */
/*  output boolean Ctrl_bNeut;                                                */
/*  output boolean Ctrl_bUncrt_tqCkEngReal;                                   */
/*  output boolean Ctrl_CMM_3B8;                                              */
/*  output boolean Ctrl_tqEM;                                                 */
/*  output boolean Ctrl_bUncrt_tqEM;                                          */
/*  output boolean Ctrl_rCluP;                                                */
/*  output boolean Ctrl_bCluPedPrss;                                          */
/*  output boolean Ctrl_stGearShiftReq;                                       */
/*  output boolean Ctrl_stGSIEna;                                             */
/*  output boolean Ctrl_CMM_BV_2E8;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidECUFrames2(void)
{
   boolean bLocalExt_bVSLimCf;
   boolean bLocalExt_bEasyMoveCf;
   boolean bLocalExt_bSTTCf;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalExt_stDVSRegCf;


   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_stDVSRegCf, u8LocalExt_stDVSRegCf);
   VEMS_vidGET(Ext_bVSLimCf, bLocalExt_bVSLimCf);
   VEMS_vidGET(Ext_bEasyMoveCf, bLocalExt_bEasyMoveCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);

   if (  (bLocalExt_bSTTCf != 0)
      && (u8LocalExt_stGBxCf == 1))
   {
      VEMS_vidSET(Ctrl_bStopIp, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bStopIp, 0);
   }

   if (  (bLocalExt_bSTTCf != 0)
      && (u8LocalExt_stGBxCf == 0))
   {
      VEMS_vidSET(Ctrl_bNeut, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bNeut, 0);
   }

   if (  (u8LocalExt_stGBxCf == 1)
      || (u8LocalExt_stGBxCf == 2) )
   {
      VEMS_vidSET(Ctrl_bUncrt_tqCkEngReal, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bUncrt_tqCkEngReal, 0);
   }

   if (u8LocalExt_stGBxCf == 1)
   {
      VEMS_vidSET(Ctrl_CMM_3B8, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_CMM_3B8, 0);
   }

   if (bLocalExt_bEasyMoveCf != 0)
   {
      VEMS_vidSET(Ctrl_tqEM, 1);
      VEMS_vidSET(Ctrl_bUncrt_tqEM, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_tqEM, 0);
      VEMS_vidSET(Ctrl_bUncrt_tqEM, 0);
   }

   if (u8LocalExt_stGBxCf == 0)
   {
      VEMS_vidSET(Ctrl_rCluP, 1);
      VEMS_vidSET(Ctrl_bCluPedPrss, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_rCluP, 0);
      VEMS_vidSET(Ctrl_bCluPedPrss, 0);
   }

   if (  (u8LocalExt_stGBxCf == 0)
      || (u8LocalExt_stGBxCf == 1)
      || (u8LocalExt_stGBxCf == 2))
   {
      VEMS_vidSET(Ctrl_stGearShiftReq, 1);
      VEMS_vidSET(Ctrl_stGSIEna, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_stGearShiftReq, 0);
      VEMS_vidSET(Ctrl_stGSIEna, 0);
   }

   if (  (u8LocalExt_stGBxCf == 1)
      && (  (u8LocalExt_stDVSRegCf == 1)
         || (bLocalExt_bVSLimCf != 0)))
   {
      VEMS_vidSET(Ctrl_CMM_BV_2E8, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_CMM_BV_2E8, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidECUFrames3                                      */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the ECU are activated or not.          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_006.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bASRESPCf;                                              */
/*  input boolean Ext_bABSCf;                                                 */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Ext_stACTypCf;                                                */
/*  input uint8 Ext_stElEMgtCf;                                               */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean Ctrl_stPwt_C;                                               */
/*  input boolean Ctrl_rAccP_C;                                               */
/*  input boolean Ctrl_ctClcProc228_C;                                        */
/*  input boolean Ctrl_noCks228_C;                                            */
/*  output boolean Ctrl_pAC;                                                  */
/*  output boolean Ctrl_stReq;                                                */
/*  output boolean Ctrl_CMM_5F8;                                              */
/*  output boolean Ctrl_stElEProv;                                            */
/*  output boolean Ctrl_bWupAcv;                                              */
/*  output boolean Ctrl_stReqBlsVoltCtl;                                      */
/*  output boolean Ctrl_stDiagESPReq;                                         */
/*  output boolean Ctrl_bInhAcqESPFrnt;                                       */
/*  output boolean Ctrl_CMM_388;                                              */
/*  output boolean Ctrl_bAcvStaReq;                                           */
/*  output boolean Ctrl_stStaAuth;                                            */
/*  output boolean Ctrl_bAcv_stModSpt;                                        */
/*  output boolean Ctrl_pBoostSndModSpt;                                      */
/*  output boolean Ctrl_noCalCurBattMes;                                      */
/*  output boolean Ctrl_bTraTqAuthRaw;                                        */
/*  output boolean Ctrl_bRvs;                                                 */
/*  output boolean Ctrl_stPwt;                                                */
/*  output boolean Ctrl_stPwt_C;                                              */
/*  output boolean Ctrl_rAccP;                                                */
/*  output boolean Ctrl_rAccP_C;                                              */
/*  output boolean Ctrl_ctClcProc228;                                         */
/*  output boolean Ctrl_ctClcProc228_C;                                       */
/*  output boolean Ctrl_noCks228;                                             */
/*  output boolean Ctrl_noCks228_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidECUFrames3(void)
{
   boolean bLocalExt_bASRESPCf;
   boolean bLocalExt_bABSCf;
   boolean bLocalExt_bArchiCf;
   boolean bLocalExt_bSTTCf;
   uint8   u8LocalExt_stACTypCf;
   uint8   u8LocalExt_stElEMgtCf;
   uint8   u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_bASRESPCf, bLocalExt_bASRESPCf);
   VEMS_vidGET(Ext_bABSCf, bLocalExt_bABSCf);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_stACTypCf, u8LocalExt_stACTypCf);
   VEMS_vidGET(Ext_stElEMgtCf, u8LocalExt_stElEMgtCf);
   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);

   if (u8LocalExt_stACTypCf != 0)
   {
      VEMS_vidSET(Ctrl_pAC, 1);
      VEMS_vidSET(Ctrl_stReq, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_pAC, 0);
      VEMS_vidSET(Ctrl_stReq, 0);
   }

   if (u8LocalExt_stElEMgtCf == 5)
   {
      VEMS_vidSET(Ctrl_CMM_5F8, 1);
      VEMS_vidSET(Ctrl_stElEProv, 1);
      VEMS_vidSET(Ctrl_bWupAcv, 1);
      VEMS_vidSET(Ctrl_stReqBlsVoltCtl, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_CMM_5F8, 0);
      VEMS_vidSET(Ctrl_stElEProv, 0);
      VEMS_vidSET(Ctrl_bWupAcv, 0);
      VEMS_vidSET(Ctrl_stReqBlsVoltCtl, 0);
   }

   if (bLocalExt_bASRESPCf != 0)
   {
      VEMS_vidSET(Ctrl_stDiagESPReq, 1);
      VEMS_vidSET(Ctrl_bInhAcqESPFrnt, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_stDiagESPReq, 0);
      VEMS_vidSET(Ctrl_bInhAcqESPFrnt, 0);
   }

   if (  (bLocalExt_bASRESPCf == 0)
      && (bLocalExt_bABSCf == 0) )
   {
      VEMS_vidSET(Ctrl_CMM_388, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_CMM_388, 0);
   }

   if (bLocalExt_bArchiCf == 0)
   {
      VEMS_vidSET(Ctrl_bAcvStaReq, 1);
      VEMS_vidSET(Ctrl_stStaAuth, 0);
      VEMS_vidSET(Ctrl_bAcv_stModSpt, 0);
      VEMS_vidSET(Ctrl_pBoostSndModSpt, 0);
   }
   else
   {
      VEMS_vidSET(Ctrl_bAcvStaReq, 0);
      VEMS_vidSET(Ctrl_stStaAuth, 1);
      VEMS_vidSET(Ctrl_bAcv_stModSpt, 1);
      VEMS_vidSET(Ctrl_pBoostSndModSpt, 1);
   }

   if (  (u8LocalExt_stElEMgtCf == 5)
      || (bLocalExt_bSTTCf != 0))
   {
      VEMS_vidSET(Ctrl_noCalCurBattMes, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_noCalCurBattMes, 0);
   }

   if (  (bLocalExt_bSTTCf != 0)
      && (  (u8LocalExt_stGBxCf == 1)
         || (u8LocalExt_stGBxCf == 2)))
   {
      VEMS_vidSET(Ctrl_bTraTqAuthRaw, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bTraTqAuthRaw, 0);
   }

   if (  (u8LocalExt_stGBxCf == 0)
      || (bLocalExt_bArchiCf != 0))
   {
      VEMS_vidSET(Ctrl_bRvs, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bRvs, 0);
   }

   VEMS_vidSET(Ctrl_stPwt, Ctrl_stPwt_C);
   VEMS_vidSET(Ctrl_rAccP, Ctrl_rAccP_C);
   VEMS_vidSET(Ctrl_ctClcProc228, Ctrl_ctClcProc228_C);
   VEMS_vidSET(Ctrl_noCks228, Ctrl_noCks228_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidPSFrames                                        */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the power steering are activated or    */
/*                 not.                                                       */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input boolean Ext_bDAE_DAEHCf;                                            */
/*  input boolean Ext_bFSFCf;                                                 */
/*  output boolean Ctrl_DIRA_495;                                             */
/*  output boolean Ctrl_VOL_305;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidPSFrames(void)
{
   boolean bLocalExt_bSTTCf;
   boolean bLocalExt_bDAE_DAEHCf;
   boolean bLocalExt_bFSFCf;

   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_bDAE_DAEHCf, bLocalExt_bDAE_DAEHCf);
   VEMS_vidGET(Ext_bFSFCf, bLocalExt_bFSFCf);

   if (bLocalExt_bSTTCf != 0)
   {
      VEMS_vidSET(Ctrl_DIRA_495, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_DIRA_495, 0);
   }

   if (  (bLocalExt_bDAE_DAEHCf != 0)
      && (bLocalExt_bFSFCf == 0))
   {
      VEMS_vidSET(Ctrl_VOL_305, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_VOL_305, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidOther_Frames_Param                              */
/* !Description :  Other frames or parameters are always activated.           */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ctrl_BSI_CMM_0A8_C;                                         */
/*  input boolean Ctrl_CMM_608_C;                                             */
/*  input boolean Ctrl_CMM_788_C;                                             */
/*  input boolean Ctrl_CRASH_4C8_C;                                           */
/*  input boolean Ctrl_DIAG_ON_CAN_688_C;                                     */
/*  input boolean Ctrl_DIAG_ON_CAN_6A8_C;                                     */
/*  input boolean Ctrl_EAC_CMM_BSI_072_C;                                     */
/*  input boolean Ctrl_EAC_CMM_UCC_0E8_C;                                     */
/*  input boolean Ctrl_ELECTRON_BSI_092_C;                                    */
/*  input boolean Ctrl_EOBD_ON_CAN_7DF_C;                                     */
/*  input boolean Ctrl_EOBD_ON_CAN_7E0_C;                                     */
/*  input boolean Ctrl_EOBD_ON_CAN_7E8_C;                                     */
/*  input boolean Ctrl_EOBD_ON_CAN_7ED_C;                                     */
/*  input boolean Ctrl_OUTIL_PRTCLE_CCP_7CC_C;                                */
/*  input boolean Ctrl_OUTIL_PRTCLE_CCP_7CD_C;                                */
/*  input boolean Ctrl_OUTIL_PRTCLE_CCP_7CE_C;                                */
/*  input boolean Ctrl_OUTIL_PRTCLE_CCP_7CF_C;                                */
/*  input boolean Ctrl_RQD_CMM_BSI_072_C;                                     */
/*  input boolean Ctrl_RQD_CMM_UCC_0E8_C;                                     */
/*  input boolean Ctrl_StRlyR3_C;                                             */
/*  input boolean Ctrl_UCC_CMM_0E0_C;                                         */
/*  input boolean Ctrl_bfSlavePtlWkuSt_C;                                     */
/*  input boolean Ctrl_stECUMiss_C;                                           */
/*  input boolean Ctrl_stJDD2Answ_C;                                          */
/*  input boolean Ctrl_stJDDAnsw_C;                                           */
/*  input boolean Ctrl_stSt_C;                                                */
/*  input boolean Ctrl_tCoMes_C;                                              */
/*  input boolean Ctrl_bFuTnkEmp_C;                                           */
/*  input boolean Ctrl_noSupvDTC_C;                                           */
/*  input boolean Ctrl_bVehCollWarn_C;                                        */
/*  input boolean Ctrl_bAcv_pDsThr_C;                                         */
/*  input boolean Ctrl_bAcv_pAirExtMes_C;                                     */
/*  input boolean Ctrl_bfAcvConstEm2_C;                                       */
/*  input boolean Ctrl_spdVeh_C;                                              */
/*  input boolean Ctrl_iBattMes_C;                                            */
/*  input boolean Ctrl_CMM_108_C;                                             */
/*  input boolean Ctrl_DMTR_57C_C;                                            */
/*  input boolean Ctrl_UDS_ON_CAN_7FF_C;                                      */
/*  input boolean Ctrl_SecBrkPedPrss_C;                                       */
/*  input boolean Ctrl_bAvc_BlowBy2_C;                                        */
/*  input boolean Ctrl_tqDrvFil_C;                                            */
/*  input boolean Ctrl_resBattIt_C;                                           */
/*  input boolean Ctrl_uBattOc_C;                                             */
/*  input boolean Ctrl_uBattStrt_C;                                           */
/*  output boolean Ctrl_BSI_CMM_0A8;                                          */
/*  output boolean Ctrl_BSI_CMM_0A8_C;                                        */
/*  output boolean Ctrl_CMM_608;                                              */
/*  output boolean Ctrl_CMM_608_C;                                            */
/*  output boolean Ctrl_CMM_788;                                              */
/*  output boolean Ctrl_CMM_788_C;                                            */
/*  output boolean Ctrl_CRASH_4C8;                                            */
/*  output boolean Ctrl_CRASH_4C8_C;                                          */
/*  output boolean Ctrl_DIAG_ON_CAN_688;                                      */
/*  output boolean Ctrl_DIAG_ON_CAN_688_C;                                    */
/*  output boolean Ctrl_DIAG_ON_CAN_6A8;                                      */
/*  output boolean Ctrl_DIAG_ON_CAN_6A8_C;                                    */
/*  output boolean Ctrl_EAC_CMM_BSI_072;                                      */
/*  output boolean Ctrl_EAC_CMM_BSI_072_C;                                    */
/*  output boolean Ctrl_EAC_CMM_UCC_0E8;                                      */
/*  output boolean Ctrl_EAC_CMM_UCC_0E8_C;                                    */
/*  output boolean Ctrl_ELECTRON_BSI_092;                                     */
/*  output boolean Ctrl_ELECTRON_BSI_092_C;                                   */
/*  output boolean Ctrl_EOBD_ON_CAN_7DF;                                      */
/*  output boolean Ctrl_EOBD_ON_CAN_7DF_C;                                    */
/*  output boolean Ctrl_EOBD_ON_CAN_7E0;                                      */
/*  output boolean Ctrl_EOBD_ON_CAN_7E0_C;                                    */
/*  output boolean Ctrl_EOBD_ON_CAN_7E8;                                      */
/*  output boolean Ctrl_EOBD_ON_CAN_7E8_C;                                    */
/*  output boolean Ctrl_EOBD_ON_CAN_7ED;                                      */
/*  output boolean Ctrl_EOBD_ON_CAN_7ED_C;                                    */
/*  output boolean Ctrl_OUTIL_PRTCLE_CCP_7CC;                                 */
/*  output boolean Ctrl_OUTIL_PRTCLE_CCP_7CC_C;                               */
/*  output boolean Ctrl_OUTIL_PRTCLE_CCP_7CD;                                 */
/*  output boolean Ctrl_OUTIL_PRTCLE_CCP_7CD_C;                               */
/*  output boolean Ctrl_OUTIL_PRTCLE_CCP_7CE;                                 */
/*  output boolean Ctrl_OUTIL_PRTCLE_CCP_7CE_C;                               */
/*  output boolean Ctrl_OUTIL_PRTCLE_CCP_7CF;                                 */
/*  output boolean Ctrl_OUTIL_PRTCLE_CCP_7CF_C;                               */
/*  output boolean Ctrl_RQD_CMM_BSI_072;                                      */
/*  output boolean Ctrl_RQD_CMM_BSI_072_C;                                    */
/*  output boolean Ctrl_RQD_CMM_UCC_0E8;                                      */
/*  output boolean Ctrl_RQD_CMM_UCC_0E8_C;                                    */
/*  output boolean Ctrl_StRlyR3;                                              */
/*  output boolean Ctrl_StRlyR3_C;                                            */
/*  output boolean Ctrl_UCC_CMM_0E0;                                          */
/*  output boolean Ctrl_UCC_CMM_0E0_C;                                        */
/*  output boolean Ctrl_bfSlavePtlWkuSt;                                      */
/*  output boolean Ctrl_bfSlavePtlWkuSt_C;                                    */
/*  output boolean Ctrl_stECUMiss;                                            */
/*  output boolean Ctrl_stECUMiss_C;                                          */
/*  output boolean Ctrl_stJDD2Answ;                                           */
/*  output boolean Ctrl_stJDD2Answ_C;                                         */
/*  output boolean Ctrl_stJDDAnsw;                                            */
/*  output boolean Ctrl_stJDDAnsw_C;                                          */
/*  output boolean Ctrl_stSt;                                                 */
/*  output boolean Ctrl_stSt_C;                                               */
/*  output boolean Ctrl_tCoMes;                                               */
/*  output boolean Ctrl_tCoMes_C;                                             */
/*  output boolean Ctrl_bFuTnkEmp;                                            */
/*  output boolean Ctrl_bFuTnkEmp_C;                                          */
/*  output boolean Ctrl_noSupvDTC;                                            */
/*  output boolean Ctrl_noSupvDTC_C;                                          */
/*  output boolean Ctrl_bVehCollWarn;                                         */
/*  output boolean Ctrl_bVehCollWarn_C;                                       */
/*  output boolean Ctrl_bAcv_pDsThr;                                          */
/*  output boolean Ctrl_bAcv_pDsThr_C;                                        */
/*  output boolean Ctrl_bAcv_pAirExtMes;                                      */
/*  output boolean Ctrl_bAcv_pAirExtMes_C;                                    */
/*  output boolean Ctrl_bfAcvConstEm2;                                        */
/*  output boolean Ctrl_bfAcvConstEm2_C;                                      */
/*  output boolean Ctrl_spdVeh;                                               */
/*  output boolean Ctrl_spdVeh_C;                                             */
/*  output boolean Ctrl_iBattMes;                                             */
/*  output boolean Ctrl_iBattMes_C;                                           */
/*  output boolean Ctrl_CMM_108;                                              */
/*  output boolean Ctrl_CMM_108_C;                                            */
/*  output boolean Ctrl_DMTR_57C;                                             */
/*  output boolean Ctrl_DMTR_57C_C;                                           */
/*  output boolean Ctrl_UDS_ON_CAN_7FF;                                       */
/*  output boolean Ctrl_UDS_ON_CAN_7FF_C;                                     */
/*  output boolean Ctrl_SecBrkPedPrss;                                        */
/*  output boolean Ctrl_SecBrkPedPrss_C;                                      */
/*  output boolean Ctrl_bAvc_BlowBy2;                                         */
/*  output boolean Ctrl_bAvc_BlowBy2_C;                                       */
/*  output boolean Ctrl_tqDrvFil;                                             */
/*  output boolean Ctrl_tqDrvFil_C;                                           */
/*  output boolean Ctrl_resBattIt;                                            */
/*  output boolean Ctrl_resBattIt_C;                                          */
/*  output boolean Ctrl_uBattOc;                                              */
/*  output boolean Ctrl_uBattOc_C;                                            */
/*  output boolean Ctrl_uBattStrt;                                            */
/*  output boolean Ctrl_uBattStrt_C;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidOther_Frames_Param(void)
{
   VEMS_vidSET(Ctrl_BSI_CMM_0A8, Ctrl_BSI_CMM_0A8_C);
   VEMS_vidSET(Ctrl_CMM_608, Ctrl_CMM_608_C);
   VEMS_vidSET(Ctrl_CMM_788, Ctrl_CMM_788_C);
   VEMS_vidSET(Ctrl_CRASH_4C8, Ctrl_CRASH_4C8_C);
   VEMS_vidSET(Ctrl_DIAG_ON_CAN_688, Ctrl_DIAG_ON_CAN_688_C);
   VEMS_vidSET(Ctrl_DIAG_ON_CAN_6A8, Ctrl_DIAG_ON_CAN_6A8_C);
   VEMS_vidSET(Ctrl_EAC_CMM_BSI_072, Ctrl_EAC_CMM_BSI_072_C);
   VEMS_vidSET(Ctrl_EAC_CMM_UCC_0E8, Ctrl_EAC_CMM_UCC_0E8_C);
   VEMS_vidSET(Ctrl_ELECTRON_BSI_092, Ctrl_ELECTRON_BSI_092_C);
   VEMS_vidSET(Ctrl_EOBD_ON_CAN_7DF, Ctrl_EOBD_ON_CAN_7DF_C);
   VEMS_vidSET(Ctrl_EOBD_ON_CAN_7E0, Ctrl_EOBD_ON_CAN_7E0_C);
   VEMS_vidSET(Ctrl_EOBD_ON_CAN_7E8, Ctrl_EOBD_ON_CAN_7E8_C);
   VEMS_vidSET(Ctrl_EOBD_ON_CAN_7ED, Ctrl_EOBD_ON_CAN_7ED_C);
   VEMS_vidSET(Ctrl_OUTIL_PRTCLE_CCP_7CC, Ctrl_OUTIL_PRTCLE_CCP_7CC_C);
   VEMS_vidSET(Ctrl_OUTIL_PRTCLE_CCP_7CD, Ctrl_OUTIL_PRTCLE_CCP_7CD_C);
   VEMS_vidSET(Ctrl_OUTIL_PRTCLE_CCP_7CE, Ctrl_OUTIL_PRTCLE_CCP_7CE_C);
   VEMS_vidSET(Ctrl_OUTIL_PRTCLE_CCP_7CF, Ctrl_OUTIL_PRTCLE_CCP_7CF_C);
   VEMS_vidSET(Ctrl_RQD_CMM_BSI_072, Ctrl_RQD_CMM_BSI_072_C);
   VEMS_vidSET(Ctrl_RQD_CMM_UCC_0E8, Ctrl_RQD_CMM_UCC_0E8_C);
   VEMS_vidSET(Ctrl_StRlyR3, Ctrl_StRlyR3_C);
   VEMS_vidSET(Ctrl_UCC_CMM_0E0, Ctrl_UCC_CMM_0E0_C);
   VEMS_vidSET(Ctrl_bfSlavePtlWkuSt, Ctrl_bfSlavePtlWkuSt_C);
   VEMS_vidSET(Ctrl_stECUMiss, Ctrl_stECUMiss_C);
   VEMS_vidSET(Ctrl_stJDD2Answ, Ctrl_stJDD2Answ_C);
   VEMS_vidSET(Ctrl_stJDDAnsw, Ctrl_stJDDAnsw_C);
   VEMS_vidSET(Ctrl_stSt, Ctrl_stSt_C);
   VEMS_vidSET(Ctrl_tCoMes, Ctrl_tCoMes_C);
   VEMS_vidSET(Ctrl_bFuTnkEmp, Ctrl_bFuTnkEmp_C);
   VEMS_vidSET(Ctrl_noSupvDTC, Ctrl_noSupvDTC_C);
   VEMS_vidSET(Ctrl_bVehCollWarn, Ctrl_bVehCollWarn_C);
   VEMS_vidSET(Ctrl_bAcv_pDsThr, Ctrl_bAcv_pDsThr_C);
   VEMS_vidSET(Ctrl_bAcv_pAirExtMes, Ctrl_bAcv_pAirExtMes_C);
   VEMS_vidSET(Ctrl_bfAcvConstEm2, Ctrl_bfAcvConstEm2_C);
   VEMS_vidSET(Ctrl_spdVeh, Ctrl_spdVeh_C);
   VEMS_vidSET(Ctrl_iBattMes, Ctrl_iBattMes_C);
   VEMS_vidSET(Ctrl_CMM_108, Ctrl_CMM_108_C);
   VEMS_vidSET(Ctrl_DMTR_57C, Ctrl_DMTR_57C_C);
   VEMS_vidSET(Ctrl_UDS_ON_CAN_7FF, Ctrl_UDS_ON_CAN_7FF_C);
   VEMS_vidSET(Ctrl_SecBrkPedPrss, Ctrl_SecBrkPedPrss_C);
   VEMS_vidSET(Ctrl_bAvc_BlowBy2, Ctrl_bAvc_BlowBy2_C);
   VEMS_vidSET(Ctrl_tqDrvFil, Ctrl_tqDrvFil_C);
   VEMS_vidSET(Ctrl_resBattIt, Ctrl_resBattIt_C);
   VEMS_vidSET(Ctrl_uBattOc, Ctrl_uBattOc_C);
   VEMS_vidSET(Ctrl_uBattStrt, Ctrl_uBattStrt_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidCluFrames                                       */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the power steering are activated or    */
/*                 not.                                                       */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bTTCf;                                                  */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Ext_bEasyMoveCf;                                            */
/*  input boolean Ext_bStrtDrvIfCf;                                           */
/*  input boolean Ext_bStrtDrvIfTypCf;                                        */
/*  output boolean Ctrl_bCluPedPrssSen;                                       */
/*  output boolean Ctrl_rCluPedPrssMes;                                       */
/*  output boolean Ctrl_ESPPropSnsr_CMMPropSnsr;                              */
/*  output boolean Ctrl_CMMPropSnsrOnly_PTT;                                  */
/*  output boolean Ctrl_ESPPropSnsr_CMMSwt;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidCluFrames(void)
{
   boolean bLocalExt_bTTCf;
   boolean bLocalExt_bSTTCf;
   boolean bLocalExt_bArchiCf;
   boolean bLocalExt_bEasyMoveCf;
   boolean bLocalExt_bStrtDrvIfCf;
   boolean bLocalExt_bStrtDrvIfTypCf;
   uint8   u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_bTTCf, bLocalExt_bTTCf);
   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_bEasyMoveCf, bLocalExt_bEasyMoveCf);
   VEMS_vidGET(Ext_bStrtDrvIfCf, bLocalExt_bStrtDrvIfCf);
   VEMS_vidGET(Ext_bStrtDrvIfTypCf, bLocalExt_bStrtDrvIfTypCf);

   if (  (u8LocalExt_stGBxCf == 0)
      && (bLocalExt_bTTCf == 0)
      && ( (  (bLocalExt_bSTTCf == 0)
           && (bLocalExt_bEasyMoveCf == 0)
           && (bLocalExt_bArchiCf == 0))
         || (  (  (bLocalExt_bArchiCf != 0)
               && (bLocalExt_bEasyMoveCf == 0)
               && (bLocalExt_bSTTCf == 0))
            && ( (  (bLocalExt_bStrtDrvIfTypCf != 0)
                 && (bLocalExt_bStrtDrvIfCf != 0))
                 || (bLocalExt_bStrtDrvIfCf == 0)))))
   {
      VEMS_vidSET(Ctrl_bCluPedPrssSen, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bCluPedPrssSen, 0);
   }
   if (  (u8LocalExt_stGBxCf == 0)
      && (bLocalExt_bTTCf != 0)
      && ( (  (bLocalExt_bSTTCf != 0)
           && (bLocalExt_bEasyMoveCf == 0)
           && (bLocalExt_bArchiCf == 0))
           || (bLocalExt_bArchiCf != 0)))
   {
      VEMS_vidSET(Ctrl_rCluPedPrssMes, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_rCluPedPrssMes, 0);
   }
   if (  (u8LocalExt_stGBxCf == 0)
      && (bLocalExt_bTTCf == 0)
      && (bLocalExt_bSTTCf != 0)
      && (bLocalExt_bEasyMoveCf != 0)
      && (bLocalExt_bArchiCf == 0))
   {
      VEMS_vidSET(Ctrl_ESPPropSnsr_CMMPropSnsr, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_ESPPropSnsr_CMMPropSnsr, 0);
   }
   if (  (u8LocalExt_stGBxCf == 0)
      && (bLocalExt_bTTCf == 0)
      && (  (  (bLocalExt_bSTTCf != 0)
            && (bLocalExt_bEasyMoveCf == 0)
            && (bLocalExt_bArchiCf == 0))
         || (  (bLocalExt_bArchiCf != 0)
            && (  (bLocalExt_bEasyMoveCf != 0)
               || (bLocalExt_bSTTCf != 0)
               || (  (bLocalExt_bStrtDrvIfTypCf == 0)
                  && (bLocalExt_bStrtDrvIfCf != 0))))))
   {
      VEMS_vidSET(Ctrl_CMMPropSnsrOnly_PTT, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_CMMPropSnsrOnly_PTT, 0);
   }
   if (  (u8LocalExt_stGBxCf == 0)
      && (bLocalExt_bSTTCf == 0)
      && (bLocalExt_bEasyMoveCf != 0)
      && (bLocalExt_bArchiCf == 0))
   {
      VEMS_vidSET(Ctrl_ESPPropSnsr_CMMSwt, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_ESPPropSnsr_CMMSwt, 0);
   }
}
/*------------------------------- end of file --------------------------------*/