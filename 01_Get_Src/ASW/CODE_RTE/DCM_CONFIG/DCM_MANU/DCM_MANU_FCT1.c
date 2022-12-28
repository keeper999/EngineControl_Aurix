/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : DCM_MANU_FCT1.C                                         */
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
/*   1 / DCM_MANU_EveRcRst1                                                   */
/*   2 / DCM_MANU_EveRcStt                                                    */
/*   3 / DCM_MANU_EveRcRst4                                                   */
/*   4 / DCM_MANU_EveRcRst2                                                   */
/*   5 / DCM_MANU_VidReinitAftsVariables                                      */
/*   6 / DCM_MANU_vidSdlFast                                                  */
/*   7 / DCM_MANU_vidEveRst                                                   */
/*   8 / DCM_MANU_vidEveRst_SrvDiagConst                                      */
/*   9 / DCM_MANU_vidSdlMid_SrvDiagConst                                      */
/*   10 / DCM_MANU_vidSdlFast_DiagSrvSA                                       */
/*   11 / DCM_MANU_vidChgSesType                                              */
/*   12 / DCM_MANU_vidPwrl_SrvRc                                              */
/*   13 / DCM_MANU_EveRC_SdlMid                                               */
/*   14 / DCM_MANU_vidSetAftsVariables                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5074350 / 4                                         */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DCM$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveRcRst1                                         */
/* !Description :  Function about timer_adaptative                            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_VidReinitAftsVariables();                       */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveRcRst1(void)
{

   if(   (Srv_stRcEnd_BattChg == RC_RUNNING) ||
         (Srv_stRcEnd_RstCoReqRStrt == RC_RUNNING) ||
         (Srv_stRcEnd_RstStaCnt == RC_RUNNING) ||
         (Srv_stRcEnd_RstCluDftCnt == RC_RUNNING) ||
         (Srv_stRcEnd_RstCurRdB == RC_RUNNING) ||
         (Srv_stRcEnd_RstCylHdDmgCnt == RC_RUNNING) ||
         (Srv_stRcEnd_RstMnfDmgCnt == RC_RUNNING) ||
         (Srv_stRcEnd_RstTrbDmgCnt == RC_RUNNING) ||
         (Srv_stRcEnd_RstCylHdDmgCplmCnt == RC_RUNNING) ||
         (Srv_stRcEnd_RstDfwChg == RC_RUNNING) ||
         (Srv_stRcEnd_RstAFAMgtT == RC_RUNNING) ||
         (Srv_stRcEnd_RstTrbActSys == RC_RUNNING) ||
         (Srv_stRcEnd_RstESLim == RC_RUNNING) ||
         (Srv_stRcEnd_RstPed == RC_RUNNING) ||
         (Srv_stRcEnd_RstReqStcBatt == RC_RUNNING) ||
         (Srv_stRcEnd_RstLrn_Misf == RC_RUNNING)
      )
   {
      DCM_MANU_VidReinitAftsVariables();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveRcStt                                          */
/* !Description :  Function about timer_adaptative                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Srv_stRcEnd_ModeSTTFactReq;                                   */
/*  input uint8 Srv_stRcEnd_ModeSTTAftsReq;                                   */
/*  input uint8 Srv_stRcEnd_ModeSTTBatt;                                      */
/*  input uint16 Srv_tiRcSttEnd;                                              */
/*  input uint16 Srv_tiRcSttEnd_C;                                            */
/*  output uint16 Srv_tiRcSttEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveRcStt(void)
{
   if(   (Srv_stRcEnd_ModeSTTFactReq == RC_RUNNING) ||
         (Srv_stRcEnd_ModeSTTAftsReq == RC_RUNNING) ||
         (Srv_stRcEnd_ModeSTTBatt == RC_RUNNING)
      )
   {
      if( Srv_tiRcSttEnd >= Srv_tiRcSttEnd_C)
      {
         Srv_tiRcSttEnd = Srv_tiRcSttEnd_C;
      }
      else
      {
         Srv_tiRcSttEnd++;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveRcRst4                                         */
/* !Description :  Function about timer_adaptative                            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ECU_bWkuMain;                                               */
/*  output boolean Srv_bInhSftyLvl2;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveRcRst4(void)
{
   boolean bLocalECU_bWkuMain;

   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   if(bLocalECU_bWkuMain == FALSE)
   {
      VEMS_vidSET(Srv_bInhSftyLvl2, FALSE);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveRcRst2                                         */
/* !Description :  Function about timer_adaptative                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  output boolean Srv_bInhThr;                                               */
/*  output boolean Srv_bInhBoostGDI;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveRcRst2(void)
{
   uint8    u8LocalCoPTSt_stEng;
   boolean  bLocalExt_bRun;
   uint16   u16localspdveh;
   boolean  bLocalECU_bWkuMain;

   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Ext_bRun, bLocalExt_bRun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdveh = (uint16)(u16localspdveh / 128);

   if( (u8LocalCoPTSt_stEng != 1) ||
       (bLocalExt_bRun == TRUE) ||
       (u16localspdveh > (uint16)Diag_seuil_vit_veh) ||
       (bLocalECU_bWkuMain == FALSE)
      )
   {
      VEMS_vidSET(Srv_bInhThr, FALSE);
      VEMS_vidSET(Srv_bInhBoostGDI, FALSE);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_VidReinitAftsVariables                            */
/* !Description :  Function about timer_adaptative                            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Srv_tiRcRstEnd;                                              */
/*  input uint16 Srv_tiRcRstEnd_C;                                            */
/*  output boolean Afts_bLrnRstReq_rOfsSoC;                                   */
/*  output boolean Afts_bRstReqStcBatt;                                       */
/*  output boolean Afts_bLrnRstReq_uEmPredRstrt;                              */
/*  output boolean Afts_bLrnRstReq_iElNwStop;                                 */
/*  output boolean Afts_bRstMemCoReqRStrt;                                    */
/*  output boolean Afts_bRstReq_ctStaAcv;                                     */
/*  output boolean Afts_bRstCntDiagCluP;                                      */
/*  output boolean Afts_bRstDfwChg;                                           */
/*  output boolean Afts_bRstESLim;                                            */
/*  output boolean Afts_bRstReq_stSoHBatt;                                    */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_VidReinitAftsVariables(void)
{

   if(Srv_tiRcRstEnd >= Srv_tiRcRstEnd_C)
   {
      VEMS_vidSET(Afts_bLrnRstReq_rOfsSoC, FALSE);
      VEMS_vidSET(Afts_bRstReqStcBatt, FALSE);
      VEMS_vidSET(Afts_bLrnRstReq_uEmPredRstrt, FALSE);
      VEMS_vidSET(Afts_bLrnRstReq_iElNwStop, FALSE);
      VEMS_vidSET(Afts_bRstMemCoReqRStrt, FALSE);
      VEMS_vidSET(Afts_bRstReq_ctStaAcv, FALSE);
      VEMS_vidSET(Afts_bRstCntDiagCluP, FALSE);
      VEMS_vidSET(Afts_bRstDfwChg, FALSE);
      VEMS_vidSET(Afts_bRstESLim, FALSE);
      VEMS_vidSET(Afts_bRstReq_stSoHBatt, FALSE);

      Srv_tiRcRstEnd = Srv_tiRcRstEnd_C;
   }
   else
   {
      Srv_tiRcRstEnd++;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_vidSdlFast                                        */
/* !Description :  Fonction liée au fast du DCM                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dcm_GetSesCtrlType(argout uint8 *Data);       */
/*  extf argret void DCM_MANU_vidSetAftsVariables(argin boolean aftsValue);   */
/*  input boolean Srv_bReqDSCDiagReceived;                                    */
/*  output boolean Srv_bReqDSCDiagReceived;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_vidSdlFast(void)
{
   Std_ReturnType     LocalDcm_GetSesCtrlType;
   uint8              u8LocalSesCtrlType;

   LocalDcm_GetSesCtrlType = Dcm_GetSesCtrlType(&u8LocalSesCtrlType);

   if(LocalDcm_GetSesCtrlType == E_OK)
   {
      if(u8LocalSesCtrlType == DCM_EXTENDED_DIAGNOSTIC_SESSION)
      {
         DCM_MANU_vidSetAftsVariables(TRUE);
      }
      else
      {
         if(Srv_bReqDSCDiagReceived == FALSE)
         {
            DCM_MANU_vidSetAftsVariables(FALSE);
         }
      }
   }

   Srv_bReqDSCDiagReceived = FALSE;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_vidEveRst                                         */
/* !Description :  Fonction liée au Reset du DCM                              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_vidSetAftsVariables(argin boolean aftsValue);   */
/*  output boolean Srv_bReqDSCDiagReceived;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_vidEveRst(void)
{
   DCM_MANU_vidSetAftsVariables(FALSE);
   Srv_bReqDSCDiagReceived = FALSE;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_vidEveRst_SrvDiagConst                            */
/* !Description :  Evenement Reset                                            */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Srv_tiBypCntOverNEngMax_C;                                    */
/*  output uint8 Srv_tiBypCntOverNEngMax;                                     */
/*  output boolean Srv_bBypCntOverNEngMax;                                    */
/*  output uint16 Srv_tiCntOverNEngMax;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_vidEveRst_SrvDiagConst(void)
{
   Srv_tiBypCntOverNEngMax = Srv_tiBypCntOverNEngMax_C;
   VEMS_vidSET(Srv_bBypCntOverNEngMax,0);
   VEMS_vidSET(Srv_tiCntOverNEngMax,0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_vidSdlMid_SrvDiagConst                            */
/* !Description :  Scheduler Mid                                              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Srv_tiBypCntOverNEngMax;                                      */
/*  input uint8 Srv_tiBypCntOverNEngMax_C;                                    */
/*  output uint8 Srv_tiBypCntOverNEngMax;                                     */
/*  output boolean Srv_bBypCntOverNEngMax;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_vidSdlMid_SrvDiagConst(void)
{
   if(Srv_tiBypCntOverNEngMax >= Srv_tiBypCntOverNEngMax_C)
   {
      Srv_tiBypCntOverNEngMax = Srv_tiBypCntOverNEngMax_C;
      VEMS_vidSET(Srv_bBypCntOverNEngMax,0);
   }
   else
   {
      Srv_tiBypCntOverNEngMax++;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_vidSdlFast_DiagSrvSA                              */
/* !Description :  Fonction Fast liée au SA du DCM                            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dcm_GetSesCtrlType(argout uint8 *Data);       */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DCM_MANU_vidChgSesType();                                */
/*  input boolean ECU_bWkuMain;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_vidSdlFast_DiagSrvSA(void)
{
   Std_ReturnType     LocalDcm_GetSesCtrlType;
   uint8              u8LocalSesCtrlType;
   boolean            bLocalECU_bWkuMain;

   LocalDcm_GetSesCtrlType = Dcm_GetSesCtrlType(&u8LocalSesCtrlType);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   if(LocalDcm_GetSesCtrlType == E_OK)
   {

      if((u8LocalSesCtrlType != DCM_EXTENDED_DIAGNOSTIC_SESSION)
         || (bLocalECU_bWkuMain == FALSE))
      {
         DCM_MANU_vidChgSesType();
      }
   }
   else
   {
      DCM_MANU_vidChgSesType();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_vidChgSesType                                     */
/* !Description :  Fonction liée au changement de session                     */
/* !Number      :  FCT1.11                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input bool SRV_TELEACCESS_IDLE;                                           */
/*  output st58 Srv_stTeleAccessStatus;                                       */
/*  output bool SRV_TELEACCESS_IDLE;                                          */
/*  output boolean DCM_MANU_bSaEnable;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_vidChgSesType(void)
{
   VEMS_vidSET(Srv_stTeleAccessStatus,SRV_TELEACCESS_IDLE);
   DCM_MANU_bSaEnable = FALSE;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_vidPwrl_SrvRc                                     */
/* !Description :  Fonction liée au PowerLatch                                */
/* !Number      :  FCT1.12                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Afts_stSpcFactSTTReq;                                         */
/*  input boolean Afts_bInhIniRunReq;                                         */
/*  input boolean Afts_bInhStSoCBatt;                                         */
/*  output uint8 Afts_stSpcFactSTTReq_eep;                                    */
/*  output boolean Afts_bInhIniRunReq_eep;                                    */
/*  output boolean Afts_bInhStSoCBatt_eep;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_vidPwrl_SrvRc(void)
{
   uint8 u8LocalVar1;
   uint8 u8LocalVar2;
   uint8 u8LocalVar3;

   VEMS_vidGET(Afts_stSpcFactSTTReq, u8LocalVar1);
   VEMS_vidGET(Afts_bInhIniRunReq, u8LocalVar2);
   VEMS_vidGET(Afts_bInhStSoCBatt, u8LocalVar3);

   Afts_stSpcFactSTTReq_eep = u8LocalVar1;
   Afts_bInhIniRunReq_eep = u8LocalVar2;
   Afts_bInhStSoCBatt_eep = u8LocalVar3;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveRC_SdlMid                                      */
/* !Description :  The Boost GDI inhibition Boolean behaviour generates two   */
/*                 events that will enable or disable the boost GDI           */
/* !Number      :  FCT1.13                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DCM_MANU_EveInhBoostGDI_SrvRc();                         */
/*  extf argret void DCM_MANU_EveAcvBoostGDI_SrvRc();                         */
/*  input boolean Srv_bInhBoostGDI;                                           */
/*  input boolean DCM_MANU_Srv_bInhBoostGDI_prev;                             */
/*  output boolean DCM_MANU_Srv_bInhBoostGDI_prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveRC_SdlMid(void)
{
   boolean   bLocalSrv_bInhBoostGDI;

   VEMS_vidGET(Srv_bInhBoostGDI,bLocalSrv_bInhBoostGDI);

   if (DCM_MANU_Srv_bInhBoostGDI_prev != bLocalSrv_bInhBoostGDI)
   {
      if (bLocalSrv_bInhBoostGDI == 1)
      {
         DCM_MANU_EveInhBoostGDI_SrvRc(); /* Srv_EveInhBoostGDI_SrvRc */
      }
      else
      {
         DCM_MANU_EveAcvBoostGDI_SrvRc(); /* Srv_EveAcvBoostGDI_SrvRc */
      }
   }

   DCM_MANU_Srv_bInhBoostGDI_prev = bLocalSrv_bInhBoostGDI;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_vidSetAftsVariables                               */
/* !Description :  Function modifying AfterSales Datas                        */
/* !Number      :  FCT1.14                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bAcvModAfts;                                          */
/*  output boolean Afts_bEngCtlDiagRun;                                       */
/*  output boolean Afts_bDiagToolReq;                                         */
/*  output boolean Afts_bEnaTestAftsDiag;                                     */
/*  output boolean Srv_bStartDiag;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_vidSetAftsVariables
(
   boolean aftsValue
)
{
   VEMS_vidSET(Afts_bAcvModAfts,aftsValue);
   VEMS_vidSET(Afts_bEngCtlDiagRun,aftsValue);
   VEMS_vidSET(Afts_bDiagToolReq,aftsValue);
   VEMS_vidSET(Afts_bEnaTestAftsDiag,aftsValue);
   VEMS_vidSET(Srv_bStartDiag,aftsValue);
}