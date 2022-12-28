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
/* !File            : DCM_MANU_ROUTINE_CNTRL_MNG.C                            */
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
/*   1 / DCM_MANU_EveRst_RC                                                   */
/*   2 / DCM_MANU_EveSessChg_RC                                               */
/*   3 / DCM_MANU_StartRoutineDmnd                                            */
/*   4 / DCM_MANU_StopRoutineDmnd                                             */
/*   5 / DCM_MANU_ReqResRoutineDmnd                                           */
/*   6 / DCM_MANU_RoutineResAnalyse                                           */
/*   7 / DCM_MANU_RoutineCntrlMachineTransition                               */
/*   8 / DCM_MANU_IuprResponseCreate                                          */
/*   9 / DCM_MANU_IuprResponseConcat                                          */
/*   10 / DCM_MANU_Matching_Result_Analyse                                    */
/*   11 / DCM_MANU_Programming_Result_Analyse                                 */
/*   12 / DCM_MANU_Checking_Result_Analyse                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5074350 / 5                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DCM$*/
/* $Revision::   1.3      $$Author::   pbakabad       $$Date::   27 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

#include "VEMS.H"
#include "SUPSRV.H"
#include "SWFAIL.h"

/* patchman */
#include "ISCAN.H"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveRst_RC                                         */
/* !Description :  Evènement appelé par le reset.                             */
/* !Number      :  ROUTINE_CNTRL_MNG.1                                        */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DCM_MANU_EveSessChg_RC();                                */
/*  output boolean Srv_bAcvUnloadRail;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveRst_RC(void)
{
   /* Outputs Variables */
   VEMS_vidSET(Srv_bAcvUnloadRail, FALSE);
   DCM_MANU_EveSessChg_RC();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveSessChg_RC                                     */
/* !Description :  Fonction appelée sur changement de session.                */
/* !Number      :  ROUTINE_CNTRL_MNG.2                                        */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Srv_bRcStart_MkdPwrl;                                      */
/*  output boolean Srv_bRcStop_MkdPwrl;                                       */
/*  output boolean Srv_bRcReq_MkdPwrl;                                        */
/*  output boolean Srv_bRcCom_MkdPwrl;                                        */
/*  output uint8 Srv_stRcEnd_MkdPwrl;                                         */
/*  output uint8 Srv_stRc_MkdPwrl;                                            */
/*  output boolean Srv_bRcCondOk_MkdPwrl;                                     */
/*  output boolean Srv_bRcCdnOk_MkdPwrl;                                      */
/*  output boolean Srv_bRcCdnNok_MkdPwrl;                                     */
/*  output boolean Srv_bRcStart_IniRealTiTroCnt;                              */
/*  output boolean Srv_bRcStop_IniRealTiTroCnt;                               */
/*  output boolean Srv_bRcReq_IniRealTiTroCnt;                                */
/*  output boolean Srv_bRcCom_IniRealTiTroCnt;                                */
/*  output uint8 Srv_stRcEnd_IniRealTiTroCnt;                                 */
/*  output uint8 Srv_stRc_IniRealTiTroCnt;                                    */
/*  output boolean Srv_bRcCondOk_IniRealTiTroCnt;                             */
/*  output boolean Srv_bRcCdnOk_IniRealTiTroCnt;                              */
/*  output boolean Srv_bRcCdnNok_IniRealTiTroCnt;                             */
/*  output boolean Srv_bRcStart_AcvUnloadRail;                                */
/*  output boolean Srv_bRcStop_AcvUnloadRail;                                 */
/*  output boolean Srv_bRcReq_AcvUnloadRail;                                  */
/*  output boolean Srv_bRcCom_AcvUnloadRail;                                  */
/*  output uint8 Srv_stRcEnd_AcvUnloadRail;                                   */
/*  output uint8 Srv_stRc_AcvUnloadRail;                                      */
/*  output boolean Srv_bRcCondOk_AcvUnloadRail;                               */
/*  output boolean Srv_bRcCdnOk_AcvUnloadRail;                                */
/*  output boolean Srv_bRcCdnNok_AcvUnloadRail;                               */
/*  output boolean Srv_bRcStart_ProdTest;                                     */
/*  output boolean Srv_bRcStop_ProdTest;                                      */
/*  output boolean Srv_bRcReq_ProdTest;                                       */
/*  output boolean Srv_bRcCom_ProdTest;                                       */
/*  output uint8 Srv_stRcEnd_ProdTest;                                        */
/*  output uint8 Srv_stRc_ProdTest;                                           */
/*  output boolean Srv_bRcCondOk_ProdTest;                                    */
/*  output boolean Srv_bRcCdnOk_ProdTest;                                     */
/*  output boolean Srv_bRcCdnNok_ProdTest;                                    */
/*  output Std_ReturnType DCM_MANU_TestProdReturnValue;                       */
/*  output boolean Srv_bRcStart_SftyLvl2;                                     */
/*  output boolean Srv_bRcStop_SftyLvl2;                                      */
/*  output boolean Srv_bRcReq_SftyLvl2;                                       */
/*  output boolean Srv_bRcCom_SftyLvl2;                                       */
/*  output uint8 Srv_stRcEnd_SftyLvl2;                                        */
/*  output uint8 Srv_stRc_SftyLvl2;                                           */
/*  output boolean Srv_bRcCondOk_SftyLvl2;                                    */
/*  output boolean Srv_bRcCdnOk_SftyLvl2;                                     */
/*  output boolean Srv_bRcCdnNok_SftyLvl2;                                    */
/*  output boolean Srv_bRcStart_BattChg;                                      */
/*  output boolean Srv_bRcStop_BattChg;                                       */
/*  output boolean Srv_bRcReq_BattChg;                                        */
/*  output boolean Srv_bRcCom_BattChg;                                        */
/*  output uint8 Srv_stRcEnd_BattChg;                                         */
/*  output uint8 Srv_stRc_BattChg;                                            */
/*  output boolean Srv_bRcCondOk_BattChg;                                     */
/*  output boolean Srv_bRcCdnOk_BattChg;                                      */
/*  output boolean Srv_bRcCdnNok_BattChg;                                     */
/*  output boolean Srv_bRcStart_RstESLim;                                     */
/*  output boolean Srv_bRcStop_RstESLim;                                      */
/*  output boolean Srv_bRcReq_RstESLim;                                       */
/*  output boolean Srv_bRcCom_RstESLim;                                       */
/*  output uint8 Srv_stRcEnd_RstESLim;                                        */
/*  output uint8 Srv_stRc_RstESLim;                                           */
/*  output boolean Srv_bRcCondOk_RstESLim;                                    */
/*  output boolean Srv_bRcCdnOk_RstESLim;                                     */
/*  output boolean Srv_bRcCdnNok_RstESLim;                                    */
/*  output boolean Srv_bRcStart_RstAFAMgtT;                                   */
/*  output boolean Srv_bRcStop_RstAFAMgtT;                                    */
/*  output boolean Srv_bRcReq_RstAFAMgtT;                                     */
/*  output boolean Srv_bRcCom_RstAFAMgtT;                                     */
/*  output uint8 Srv_stRcEnd_RstAFAMgtT;                                      */
/*  output uint8 Srv_stRc_RstAFAMgtT;                                         */
/*  output boolean Srv_bRcCondOk_RstAFAMgtT;                                  */
/*  output boolean Srv_bRcCdnOk_RstAFAMgtT;                                   */
/*  output boolean Srv_bRcCdnNok_RstAFAMgtT;                                  */
/*  output boolean Srv_bRcStart_ModeSTTAftsReq;                               */
/*  output boolean Srv_bRcStop_ModeSTTAftsReq;                                */
/*  output boolean Srv_bRcReq_ModeSTTAftsReq;                                 */
/*  output boolean Srv_bRcCom_ModeSTTAftsReq;                                 */
/*  output uint8 Srv_stRcEnd_ModeSTTAftsReq;                                  */
/*  output uint8 Srv_stRc_ModeSTTAftsReq;                                     */
/*  output boolean Srv_bRcCondOk_ModeSTTAftsReq;                              */
/*  output boolean Srv_bRcCdnOk_ModeSTTAftsReq;                               */
/*  output boolean Srv_bRcCdnNok_ModeSTTAftsReq;                              */
/*  output boolean Srv_bRcStart_RstCylHdDmgCnt;                               */
/*  output boolean Srv_bRcStop_RstCylHdDmgCnt;                                */
/*  output boolean Srv_bRcReq_RstCylHdDmgCnt;                                 */
/*  output boolean Srv_bRcCom_RstCylHdDmgCnt;                                 */
/*  output uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                  */
/*  output uint8 Srv_stRc_RstCylHdDmgCnt;                                     */
/*  output boolean Srv_bRcCondOk_RstCylHdDmgCnt;                              */
/*  output boolean Srv_bRcCdnOk_RstCylHdDmgCnt;                               */
/*  output boolean Srv_bRcCdnNok_RstCylHdDmgCnt;                              */
/*  output boolean Srv_bRcStart_ModeSTTFactReq;                               */
/*  output boolean Srv_bRcStop_ModeSTTFactReq;                                */
/*  output boolean Srv_bRcReq_ModeSTTFactReq;                                 */
/*  output boolean Srv_bRcCom_ModeSTTFactReq;                                 */
/*  output uint8 Srv_stRcEnd_ModeSTTFactReq;                                  */
/*  output uint8 Srv_stRc_ModeSTTFactReq;                                     */
/*  output boolean Srv_bRcCondOk_ModeSTTFactReq;                              */
/*  output boolean Srv_bRcCdnOk_ModeSTTFactReq;                               */
/*  output boolean Srv_bRcCdnNok_ModeSTTFactReq;                              */
/*  output boolean Srv_bRcStart_RstMnfDmgCnt;                                 */
/*  output boolean Srv_bRcStop_RstMnfDmgCnt;                                  */
/*  output boolean Srv_bRcReq_RstMnfDmgCnt;                                   */
/*  output boolean Srv_bRcCom_RstMnfDmgCnt;                                   */
/*  output uint8 Srv_stRcEnd_RstMnfDmgCnt;                                    */
/*  output uint8 Srv_stRc_RstMnfDmgCnt;                                       */
/*  output boolean Srv_bRcCondOk_RstMnfDmgCnt;                                */
/*  output boolean Srv_bRcCdnOk_RstMnfDmgCnt;                                 */
/*  output boolean Srv_bRcCdnNok_RstMnfDmgCnt;                                */
/*  output boolean Srv_bRcStart_ModeSTTBatt;                                  */
/*  output boolean Srv_bRcStop_ModeSTTBatt;                                   */
/*  output boolean Srv_bRcReq_ModeSTTBatt;                                    */
/*  output boolean Srv_bRcCom_ModeSTTBatt;                                    */
/*  output uint8 Srv_stRcEnd_ModeSTTBatt;                                     */
/*  output uint8 Srv_stRc_ModeSTTBatt;                                        */
/*  output boolean Srv_bRcCondOk_ModeSTTBatt;                                 */
/*  output boolean Srv_bRcCdnOk_ModeSTTBatt;                                  */
/*  output boolean Srv_bRcCdnNok_ModeSTTBatt;                                 */
/*  output boolean Srv_bRcStart_RstCylHdDmgCplmCnt;                           */
/*  output boolean Srv_bRcStop_RstCylHdDmgCplmCnt;                            */
/*  output boolean Srv_bRcReq_RstCylHdDmgCplmCnt;                             */
/*  output boolean Srv_bRcCom_RstCylHdDmgCplmCnt;                             */
/*  output uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                              */
/*  output uint8 Srv_stRc_RstCylHdDmgCplmCnt;                                 */
/*  output boolean Srv_bRcCondOk_RstCylHdDmgCplmCnt;                          */
/*  output boolean Srv_bRcCdnOk_RstCylHdDmgCplmCnt;                           */
/*  output boolean Srv_bRcCdnNok_RstCylHdDmgCplmCnt;                          */
/*  output boolean Srv_bRcStart_RstTrbActSys;                                 */
/*  output boolean Srv_bRcStop_RstTrbActSys;                                  */
/*  output boolean Srv_bRcReq_RstTrbActSys;                                   */
/*  output boolean Srv_bRcCom_RstTrbActSys;                                   */
/*  output uint8 Srv_stRcEnd_RstTrbActSys;                                    */
/*  output uint8 Srv_stRc_RstTrbActSys;                                       */
/*  output boolean Srv_bRcCondOk_RstTrbActSys;                                */
/*  output boolean Srv_bRcCdnOk_RstTrbActSys;                                 */
/*  output boolean Srv_bRcCdnNok_RstTrbActSys;                                */
/*  output boolean Srv_bRcStart_RstTrbDmgCnt;                                 */
/*  output boolean Srv_bRcStop_RstTrbDmgCnt;                                  */
/*  output boolean Srv_bRcReq_RstTrbDmgCnt;                                   */
/*  output boolean Srv_bRcCom_RstTrbDmgCnt;                                   */
/*  output uint8 Srv_stRcEnd_RstTrbDmgCnt;                                    */
/*  output uint8 Srv_stRc_RstTrbDmgCnt;                                       */
/*  output boolean Srv_bRcCondOk_RstTrbDmgCnt;                                */
/*  output boolean Srv_bRcCdnOk_RstTrbDmgCnt;                                 */
/*  output boolean Srv_bRcCdnNok_RstTrbDmgCnt;                                */
/*  output boolean Srv_bRcStart_RstDfwChg;                                    */
/*  output boolean Srv_bRcStop_RstDfwChg;                                     */
/*  output boolean Srv_bRcReq_RstDfwChg;                                      */
/*  output boolean Srv_bRcCom_RstDfwChg;                                      */
/*  output uint8 Srv_stRcEnd_RstDfwChg;                                       */
/*  output uint8 Srv_stRc_RstDfwChg;                                          */
/*  output boolean Srv_bRcCondOk_RstDfwChg;                                   */
/*  output boolean Srv_bRcCdnOk_RstDfwChg;                                    */
/*  output boolean Srv_bRcCdnNok_RstDfwChg;                                   */
/*  output boolean Srv_bRcStart_ThrInh;                                       */
/*  output boolean Srv_bRcStop_ThrInh;                                        */
/*  output boolean Srv_bRcReq_ThrInh;                                         */
/*  output boolean Srv_bRcCom_ThrInh;                                         */
/*  output uint8 Srv_stRcEnd_ThrInh;                                          */
/*  output uint8 Srv_stRc_ThrInh;                                             */
/*  output boolean Srv_bRcCondOk_ThrInh;                                      */
/*  output boolean Srv_bRcCdnOk_ThrInh;                                       */
/*  output boolean Srv_bRcCdnNok_ThrInh;                                      */
/*  output boolean Srv_bRcStart_RstStaCnt;                                    */
/*  output boolean Srv_bRcStop_RstStaCnt;                                     */
/*  output boolean Srv_bRcReq_RstStaCnt;                                      */
/*  output boolean Srv_bRcCom_RstStaCnt;                                      */
/*  output uint8 Srv_stRcEnd_RstStaCnt;                                       */
/*  output uint8 Srv_stRc_RstStaCnt;                                          */
/*  output boolean Srv_bRcCondOk_RstStaCnt;                                   */
/*  output boolean Srv_bRcCdnOk_RstStaCnt;                                    */
/*  output boolean Srv_bRcCdnNok_RstStaCnt;                                   */
/*  output boolean Srv_bRcStart_RstCurRdB;                                    */
/*  output boolean Srv_bRcStop_RstCurRdB;                                     */
/*  output boolean Srv_bRcReq_RstCurRdB;                                      */
/*  output boolean Srv_bRcCom_RstCurRdB;                                      */
/*  output uint8 Srv_stRcEnd_RstCurRdB;                                       */
/*  output uint8 Srv_stRc_RstCurRdB;                                          */
/*  output boolean Srv_bRcCondOk_RstCurRdB;                                   */
/*  output boolean Srv_bRcCdnOk_RstCurRdB;                                    */
/*  output boolean Srv_bRcCdnNok_RstCurRdB;                                   */
/*  output boolean Srv_bRcStart_RstCoReqRStrt;                                */
/*  output boolean Srv_bRcStop_RstCoReqRStrt;                                 */
/*  output boolean Srv_bRcReq_RstCoReqRStrt;                                  */
/*  output boolean Srv_bRcCom_RstCoReqRStrt;                                  */
/*  output uint8 Srv_stRcEnd_RstCoReqRStrt;                                   */
/*  output uint8 Srv_stRc_RstCoReqRStrt;                                      */
/*  output boolean Srv_bRcCondOk_RstCoReqRStrt;                               */
/*  output boolean Srv_bRcCdnOk_RstCoReqRStrt;                                */
/*  output boolean Srv_bRcCdnNok_RstCoReqRStrt;                               */
/*  output boolean Srv_bRcStart_RstCluDftCnt;                                 */
/*  output boolean Srv_bRcStop_RstCluDftCnt;                                  */
/*  output boolean Srv_bRcReq_RstCluDftCnt;                                   */
/*  output boolean Srv_bRcCom_RstCluDftCnt;                                   */
/*  output uint8 Srv_stRcEnd_RstCluDftCnt;                                    */
/*  output uint8 Srv_stRc_RstCluDftCnt;                                       */
/*  output boolean Srv_bRcCondOk_RstCluDftCnt;                                */
/*  output boolean Srv_bRcCdnOk_RstCluDftCnt;                                 */
/*  output boolean Srv_bRcCdnNok_RstCluDftCnt;                                */
/*  output boolean Srv_bRcStart_RstPed;                                       */
/*  output boolean Srv_bRcStop_RstPed;                                        */
/*  output boolean Srv_bRcReq_RstPed;                                         */
/*  output boolean Srv_bRcCom_RstPed;                                         */
/*  output uint8 Srv_stRcEnd_RstPed;                                          */
/*  output uint8 Srv_stRc_RstPed;                                             */
/*  output boolean Srv_bRcCondOk_RstPed;                                      */
/*  output boolean Srv_bRcCdnOk_RstPed;                                       */
/*  output boolean Srv_bRcCdnNok_RstPed;                                      */
/*  output boolean Srv_bRcStart_RstReqStcBatt;                                */
/*  output boolean Srv_bRcStop_RstReqStcBatt;                                 */
/*  output boolean Srv_bRcReq_RstReqStcBatt;                                  */
/*  output boolean Srv_bRcCom_RstReqStcBatt;                                  */
/*  output uint8 Srv_stRcEnd_RstReqStcBatt;                                   */
/*  output uint8 Srv_stRc_RstReqStcBatt;                                      */
/*  output boolean Srv_bRcCondOk_RstReqStcBatt;                               */
/*  output boolean Srv_bRcCdnOk_RstReqStcBatt;                                */
/*  output boolean Srv_bRcCdnNok_RstReqStcBatt;                               */
/*  output boolean Srv_bRcStart_RstLrn_Misf;                                  */
/*  output boolean Srv_bRcStop_RstLrn_Misf;                                   */
/*  output boolean Srv_bRcReq_RstLrn_Misf;                                    */
/*  output boolean Srv_bRcCom_RstLrn_Misf;                                    */
/*  output uint8 Srv_stRcEnd_RstLrn_Misf;                                     */
/*  output uint8 Srv_stRc_RstLrn_Misf;                                        */
/*  output boolean Srv_bRcCondOk_RstLrn_Misf;                                 */
/*  output boolean Srv_bRcCdnOk_RstLrn_Misf;                                  */
/*  output boolean Srv_bRcCdnNok_RstLrn_Misf;                                 */
/*  output boolean Srv_bRcStart_InhBoostGDI;                                  */
/*  output boolean Srv_bRcStop_InhBoostGDI;                                   */
/*  output boolean Srv_bRcReq_InhBoostGDI;                                    */
/*  output boolean Srv_bRcCom_InhBoostGDI;                                    */
/*  output uint8 Srv_stRcEnd_InhBoostGDI;                                     */
/*  output uint8 Srv_stRc_InhBoostGDI;                                        */
/*  output boolean Srv_bRcCondOk_InhBoostGDI;                                 */
/*  output boolean Srv_bRcCdnOk_InhBoostGDI;                                  */
/*  output boolean Srv_bRcCdnNok_InhBoostGDI;                                 */
/*  output boolean Srv_bRcStart_RstCtAuthCloThr;                              */
/*  output boolean Srv_bRcStop_RstCtAuthCloThr;                               */
/*  output boolean Srv_bRcReq_RstCtAuthCloThr;                                */
/*  output boolean Srv_bRcCom_RstCtAuthCloThr;                                */
/*  output uint8 Srv_stRcEnd_RstCtAuthCloThr;                                 */
/*  output uint8 Srv_stRc_RstCtAuthCloThr;                                    */
/*  output boolean Srv_bRcCondOk_RstCtAuthCloThr;                             */
/*  output boolean Srv_bRcCdnOk_RstCtAuthCloThr;                              */
/*  output boolean Srv_bRcCdnNok_RstCtAuthCloThr;                             */
/*  output uint16 DCM_MANU_UdsIuprFrameSize;                                  */
/*  output uint16 DCM_MANU_UdsIuprNbByteSent;                                 */
/*  output boolean DCM_MANU_ReqIuprReceived;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveSessChg_RC(void)
{
   /* Outputs Variables */
   Srv_bRcStart_MkdPwrl = FALSE;
   Srv_bRcStop_MkdPwrl = FALSE;
   Srv_bRcReq_MkdPwrl = FALSE;
   Srv_bRcCom_MkdPwrl = FALSE;
   Srv_stRcEnd_MkdPwrl = RC_INIT;
   Srv_stRc_MkdPwrl = RC_WAITING;
   Srv_bRcCondOk_MkdPwrl = FALSE;
   Srv_bRcCdnOk_MkdPwrl = FALSE;
   Srv_bRcCdnNok_MkdPwrl = FALSE;

   Srv_bRcStart_IniRealTiTroCnt = FALSE;
   Srv_bRcStop_IniRealTiTroCnt = FALSE;
   Srv_bRcReq_IniRealTiTroCnt = FALSE;
   Srv_bRcCom_IniRealTiTroCnt = FALSE;
   Srv_stRcEnd_IniRealTiTroCnt = RC_INIT;
   Srv_stRc_IniRealTiTroCnt = RC_WAITING;
   Srv_bRcCondOk_IniRealTiTroCnt = FALSE;
   Srv_bRcCdnOk_IniRealTiTroCnt = FALSE;
   Srv_bRcCdnNok_IniRealTiTroCnt = FALSE;

   Srv_bRcStart_AcvUnloadRail = FALSE;
   Srv_bRcStop_AcvUnloadRail = FALSE;
   Srv_bRcReq_AcvUnloadRail = FALSE;
   Srv_bRcCom_AcvUnloadRail = FALSE;
   Srv_stRcEnd_AcvUnloadRail = RC_INIT;
   Srv_stRc_AcvUnloadRail = RC_WAITING;
   Srv_bRcCondOk_AcvUnloadRail = FALSE;
   Srv_bRcCdnOk_AcvUnloadRail = FALSE;
   Srv_bRcCdnNok_AcvUnloadRail = FALSE;

   Srv_bRcStart_ProdTest = FALSE;
   Srv_bRcStop_ProdTest = FALSE;
   Srv_bRcReq_ProdTest = FALSE;
   Srv_bRcCom_ProdTest = FALSE;
   Srv_stRcEnd_ProdTest = RC_INIT;
   Srv_stRc_ProdTest = RC_WAITING;
   Srv_bRcCondOk_ProdTest = FALSE;
   Srv_bRcCdnOk_ProdTest = FALSE;
   Srv_bRcCdnNok_ProdTest = FALSE;
   DCM_MANU_TestProdReturnValue = E_OK;

   Srv_bRcStart_SftyLvl2 = FALSE;
   Srv_bRcStop_SftyLvl2 = FALSE;
   Srv_bRcReq_SftyLvl2 = FALSE;
   Srv_bRcCom_SftyLvl2 = FALSE;
   Srv_stRcEnd_SftyLvl2 = RC_INIT;
   Srv_stRc_SftyLvl2 = RC_WAITING;
   Srv_bRcCondOk_SftyLvl2 = FALSE;
   Srv_bRcCdnOk_SftyLvl2 = FALSE;
   Srv_bRcCdnNok_SftyLvl2 = FALSE;

   Srv_bRcStart_BattChg = FALSE;
   Srv_bRcStop_BattChg = FALSE;
   Srv_bRcReq_BattChg = FALSE;
   Srv_bRcCom_BattChg = FALSE;
   Srv_stRcEnd_BattChg = RC_INIT;
   Srv_stRc_BattChg = RC_WAITING;
   Srv_bRcCondOk_BattChg = FALSE;
   Srv_bRcCdnOk_BattChg = FALSE;
   Srv_bRcCdnNok_BattChg = FALSE;

   /* Reset Routine SC3 */
   Srv_bRcStart_RstESLim = FALSE;
   Srv_bRcStop_RstESLim= FALSE;
   Srv_bRcReq_RstESLim= FALSE;
   Srv_bRcCom_RstESLim= FALSE;
   Srv_stRcEnd_RstESLim= RC_INIT;
   Srv_stRc_RstESLim= RC_WAITING;
   Srv_bRcCondOk_RstESLim= FALSE;
   Srv_bRcCdnOk_RstESLim= FALSE;
   Srv_bRcCdnNok_RstESLim= FALSE;

   Srv_bRcStart_RstAFAMgtT = FALSE;
   Srv_bRcStop_RstAFAMgtT= FALSE;
   Srv_bRcReq_RstAFAMgtT= FALSE;
   Srv_bRcCom_RstAFAMgtT= FALSE;
   Srv_stRcEnd_RstAFAMgtT= RC_INIT;
   Srv_stRc_RstAFAMgtT= RC_WAITING;
   Srv_bRcCondOk_RstAFAMgtT= FALSE;
   Srv_bRcCdnOk_RstAFAMgtT= FALSE;
   Srv_bRcCdnNok_RstAFAMgtT= FALSE;

   Srv_bRcStart_ModeSTTAftsReq = FALSE;
   Srv_bRcStop_ModeSTTAftsReq= FALSE;
   Srv_bRcReq_ModeSTTAftsReq= FALSE;
   Srv_bRcCom_ModeSTTAftsReq= FALSE;
   Srv_stRcEnd_ModeSTTAftsReq= RC_INIT;
   Srv_stRc_ModeSTTAftsReq= RC_WAITING;
   Srv_bRcCondOk_ModeSTTAftsReq= FALSE;
   Srv_bRcCdnOk_ModeSTTAftsReq= FALSE;
   Srv_bRcCdnNok_ModeSTTAftsReq= FALSE;

   Srv_bRcStart_RstCylHdDmgCnt = FALSE;
   Srv_bRcStop_RstCylHdDmgCnt= FALSE;
   Srv_bRcReq_RstCylHdDmgCnt= FALSE;
   Srv_bRcCom_RstCylHdDmgCnt= FALSE;
   Srv_stRcEnd_RstCylHdDmgCnt= RC_INIT;
   Srv_stRc_RstCylHdDmgCnt= RC_WAITING;
   Srv_bRcCondOk_RstCylHdDmgCnt= FALSE;
   Srv_bRcCdnOk_RstCylHdDmgCnt= FALSE;
   Srv_bRcCdnNok_RstCylHdDmgCnt= FALSE;

   Srv_bRcStart_ModeSTTFactReq = FALSE;
   Srv_bRcStop_ModeSTTFactReq= FALSE;
   Srv_bRcReq_ModeSTTFactReq= FALSE;
   Srv_bRcCom_ModeSTTFactReq= FALSE;
   Srv_stRcEnd_ModeSTTFactReq= RC_INIT;
   Srv_stRc_ModeSTTFactReq= RC_WAITING;
   Srv_bRcCondOk_ModeSTTFactReq= FALSE;
   Srv_bRcCdnOk_ModeSTTFactReq= FALSE;
   Srv_bRcCdnNok_ModeSTTFactReq= FALSE;

   Srv_bRcStart_RstMnfDmgCnt = FALSE;
   Srv_bRcStop_RstMnfDmgCnt= FALSE;
   Srv_bRcReq_RstMnfDmgCnt= FALSE;
   Srv_bRcCom_RstMnfDmgCnt= FALSE;
   Srv_stRcEnd_RstMnfDmgCnt= RC_INIT;
   Srv_stRc_RstMnfDmgCnt= RC_WAITING;
   Srv_bRcCondOk_RstMnfDmgCnt= FALSE;
   Srv_bRcCdnOk_RstMnfDmgCnt= FALSE;
   Srv_bRcCdnNok_RstMnfDmgCnt= FALSE;

   Srv_bRcStart_ModeSTTBatt = FALSE;
   Srv_bRcStop_ModeSTTBatt= FALSE;
   Srv_bRcReq_ModeSTTBatt= FALSE;
   Srv_bRcCom_ModeSTTBatt= FALSE;
   Srv_stRcEnd_ModeSTTBatt= RC_INIT;
   Srv_stRc_ModeSTTBatt= RC_WAITING;
   Srv_bRcCondOk_ModeSTTBatt= FALSE;
   Srv_bRcCdnOk_ModeSTTBatt= FALSE;
   Srv_bRcCdnNok_ModeSTTBatt= FALSE;

   Srv_bRcStart_RstCylHdDmgCplmCnt = FALSE;
   Srv_bRcStop_RstCylHdDmgCplmCnt= FALSE;
   Srv_bRcReq_RstCylHdDmgCplmCnt= FALSE;
   Srv_bRcCom_RstCylHdDmgCplmCnt= FALSE;
   Srv_stRcEnd_RstCylHdDmgCplmCnt= RC_INIT;
   Srv_stRc_RstCylHdDmgCplmCnt= RC_WAITING;
   Srv_bRcCondOk_RstCylHdDmgCplmCnt= FALSE;
   Srv_bRcCdnOk_RstCylHdDmgCplmCnt= FALSE;
   Srv_bRcCdnNok_RstCylHdDmgCplmCnt= FALSE;

   Srv_bRcStart_RstTrbActSys = FALSE;
   Srv_bRcStop_RstTrbActSys= FALSE;
   Srv_bRcReq_RstTrbActSys= FALSE;
   Srv_bRcCom_RstTrbActSys= FALSE;
   Srv_stRcEnd_RstTrbActSys= RC_INIT;
   Srv_stRc_RstTrbActSys= RC_WAITING;
   Srv_bRcCondOk_RstTrbActSys= FALSE;
   Srv_bRcCdnOk_RstTrbActSys= FALSE;
   Srv_bRcCdnNok_RstTrbActSys= FALSE;

   Srv_bRcStart_RstTrbDmgCnt = FALSE;
   Srv_bRcStop_RstTrbDmgCnt= FALSE;
   Srv_bRcReq_RstTrbDmgCnt= FALSE;
   Srv_bRcCom_RstTrbDmgCnt= FALSE;
   Srv_stRcEnd_RstTrbDmgCnt= RC_INIT;
   Srv_stRc_RstTrbDmgCnt= RC_WAITING;
   Srv_bRcCondOk_RstTrbDmgCnt= FALSE;
   Srv_bRcCdnOk_RstTrbDmgCnt= FALSE;
   Srv_bRcCdnNok_RstTrbDmgCnt= FALSE;

   Srv_bRcStart_RstDfwChg = FALSE;
   Srv_bRcStop_RstDfwChg= FALSE;
   Srv_bRcReq_RstDfwChg= FALSE;
   Srv_bRcCom_RstDfwChg= FALSE;
   Srv_stRcEnd_RstDfwChg= RC_INIT;
   Srv_stRc_RstDfwChg= RC_WAITING;
   Srv_bRcCondOk_RstDfwChg= FALSE;
   Srv_bRcCdnOk_RstDfwChg= FALSE;
   Srv_bRcCdnNok_RstDfwChg= FALSE;

   Srv_bRcStart_ThrInh = FALSE;
   Srv_bRcStop_ThrInh = FALSE;
   Srv_bRcReq_ThrInh = FALSE;
   Srv_bRcCom_ThrInh = FALSE;
   Srv_stRcEnd_ThrInh = RC_INIT;
   Srv_stRc_ThrInh = RC_WAITING;
   Srv_bRcCondOk_ThrInh = FALSE;
   Srv_bRcCdnOk_ThrInh = FALSE;
   Srv_bRcCdnNok_ThrInh = FALSE;

   Srv_bRcStart_RstStaCnt = FALSE;
   Srv_bRcStop_RstStaCnt = FALSE;
   Srv_bRcReq_RstStaCnt = FALSE;
   Srv_bRcCom_RstStaCnt = FALSE;
   Srv_stRcEnd_RstStaCnt = RC_INIT;
   Srv_stRc_RstStaCnt = RC_WAITING;
   Srv_bRcCondOk_RstStaCnt = FALSE;
   Srv_bRcCdnOk_RstStaCnt = FALSE;
   Srv_bRcCdnNok_RstStaCnt = FALSE;

   Srv_bRcStart_RstCurRdB = FALSE;
   Srv_bRcStop_RstCurRdB = FALSE;
   Srv_bRcReq_RstCurRdB = FALSE;
   Srv_bRcCom_RstCurRdB = FALSE;
   Srv_stRcEnd_RstCurRdB = RC_INIT;
   Srv_stRc_RstCurRdB = RC_WAITING;
   Srv_bRcCondOk_RstCurRdB = FALSE;
   Srv_bRcCdnOk_RstCurRdB = FALSE;
   Srv_bRcCdnNok_RstCurRdB = FALSE;

   Srv_bRcStart_RstCoReqRStrt = FALSE;
   Srv_bRcStop_RstCoReqRStrt = FALSE;
   Srv_bRcReq_RstCoReqRStrt = FALSE;
   Srv_bRcCom_RstCoReqRStrt = FALSE;
   Srv_stRcEnd_RstCoReqRStrt = RC_INIT;
   Srv_stRc_RstCoReqRStrt = RC_WAITING;
   Srv_bRcCondOk_RstCoReqRStrt = FALSE;
   Srv_bRcCdnOk_RstCoReqRStrt = FALSE;
   Srv_bRcCdnNok_RstCoReqRStrt = FALSE;

   Srv_bRcStart_RstCluDftCnt = FALSE;
   Srv_bRcStop_RstCluDftCnt = FALSE;
   Srv_bRcReq_RstCluDftCnt = FALSE;
   Srv_bRcCom_RstCluDftCnt = FALSE;
   Srv_stRcEnd_RstCluDftCnt = RC_INIT;
   Srv_stRc_RstCluDftCnt = RC_WAITING;
   Srv_bRcCondOk_RstCluDftCnt = FALSE;
   Srv_bRcCdnOk_RstCluDftCnt = FALSE;
   Srv_bRcCdnNok_RstCluDftCnt = FALSE;

   Srv_bRcStart_RstPed = FALSE;
   Srv_bRcStop_RstPed = FALSE;
   Srv_bRcReq_RstPed = FALSE;
   Srv_bRcCom_RstPed = FALSE;
   Srv_stRcEnd_RstPed = RC_INIT;
   Srv_stRc_RstPed = RC_WAITING;
   Srv_bRcCondOk_RstPed = FALSE;
   Srv_bRcCdnOk_RstPed = FALSE;
   Srv_bRcCdnNok_RstPed = FALSE;

   Srv_bRcStart_RstReqStcBatt = FALSE;
   Srv_bRcStop_RstReqStcBatt = FALSE;
   Srv_bRcReq_RstReqStcBatt = FALSE;
   Srv_bRcCom_RstReqStcBatt = FALSE;
   Srv_stRcEnd_RstReqStcBatt = RC_INIT;
   Srv_stRc_RstReqStcBatt = RC_WAITING;
   Srv_bRcCondOk_RstReqStcBatt = FALSE;
   Srv_bRcCdnOk_RstReqStcBatt = FALSE;
   Srv_bRcCdnNok_RstReqStcBatt = FALSE;

   Srv_bRcStart_RstLrn_Misf = FALSE;
   Srv_bRcStop_RstLrn_Misf = FALSE;
   Srv_bRcReq_RstLrn_Misf = FALSE;
   Srv_bRcCom_RstLrn_Misf = FALSE;
   Srv_stRcEnd_RstLrn_Misf = RC_INIT;
   Srv_stRc_RstLrn_Misf = RC_WAITING;
   Srv_bRcCondOk_RstLrn_Misf = FALSE;
   Srv_bRcCdnOk_RstLrn_Misf = FALSE;
   Srv_bRcCdnNok_RstLrn_Misf = FALSE;

   Srv_bRcStart_InhBoostGDI = FALSE;
   Srv_bRcStop_InhBoostGDI = FALSE;
   Srv_bRcReq_InhBoostGDI = FALSE;
   Srv_bRcCom_InhBoostGDI = FALSE;
   Srv_stRcEnd_InhBoostGDI = RC_INIT;
   Srv_stRc_InhBoostGDI = RC_WAITING;
   Srv_bRcCondOk_InhBoostGDI = FALSE;
   Srv_bRcCdnOk_InhBoostGDI = FALSE;
   Srv_bRcCdnNok_InhBoostGDI = FALSE;

   DCM_MANU_UdsIuprFrameSize = 0;
   DCM_MANU_UdsIuprNbByteSent = 0;
   DCM_MANU_ReqIuprReceived = FALSE;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf DCM_MANU_RoutineCntrlMachineTransition(????);                        */
/*  extf argret Std_ReturnType  DCM_MANU_RoutineResAnalyse(argin uint8        */
/* Srv_stRc_NameFunc, argin boolean *Srv_bRcCom_NameFunc, argin uint8         */
/* *Srv_stRcEnd_NameFunc, argout Dcm_NegativeResponseCodeType *u8ErrorCode,   */
/* argout uint8 *u8RoutineStatus);                                            */
/*  input ???? CALL_RcAcv_NameFunc;                                           */
/*  input ???? CALL_RcTestCond_NameFunc;                                      */
/*  input ???? CALL_RcCdn_NameFunc;                                           */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Std_ReturnType DCM_MANU_StartRoutineDmnd
(
   uint8 *Srv_stRc_NameFunc,
   boolean *Srv_bRcStart_NameFunc,
   uint8 *Srv_stRcEnd_NameFunc,
   boolean *Srv_bRcCondOk_Namefunc,
   boolean Srv_bRcSho_NameFunc,
   boolean *Srv_bRcCom_NameFunc,
   boolean *Srv_bRcCdnOk_NameFunc,
   boolean *Srv_bRcCdnNok_NameFunc,
   boolean *Srv_bRcReq_NameFunc,
   boolean *Srv_bRcStop_NameFunc,
   Dcm_NegativeResponseCodeType *u8ErrorCode,
   uint8 *u8RoutineStatus,
   void (*CALL_RcAcv_NameFunc)(void),
   void (*CALL_RcTestCond_NameFunc)( boolean *),
   void (*CALL_RcCdn_NameFunc)(boolean *, boolean *)
)
{
   Std_ReturnType u8Localreturn;

   *Srv_bRcStart_NameFunc = TRUE;
   *Srv_bRcStop_NameFunc = FALSE;
   *Srv_bRcReq_NameFunc = FALSE;
   *Srv_stRc_NameFunc = RC_WAITING;

   DCM_MANU_bEnaNack = FALSE;
   DCM_MANU_ErrorCode = 0x00;

   DCM_MANU_RoutineCntrlMachineTransition( Srv_stRc_NameFunc,
                                           *Srv_bRcStart_NameFunc,
                                           Srv_stRcEnd_NameFunc,
                                           Srv_bRcCondOk_Namefunc,
                                           Srv_bRcSho_NameFunc,
                                           Srv_bRcCom_NameFunc,
                                           Srv_bRcCdnOk_NameFunc,
                                           Srv_bRcCdnNok_NameFunc,
                                           *Srv_bRcReq_NameFunc,
                                           *Srv_bRcStop_NameFunc,
                                           CALL_RcAcv_NameFunc,
                                           CALL_RcTestCond_NameFunc,
                                           CALL_RcCdn_NameFunc );

   u8Localreturn = DCM_MANU_RoutineResAnalyse( *Srv_stRc_NameFunc,
                                               Srv_bRcCom_NameFunc,
                                               Srv_stRcEnd_NameFunc,
                                               u8ErrorCode,
                                               u8RoutineStatus );

   return u8Localreturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf DCM_MANU_RoutineCntrlMachineTransition(????);                        */
/*  extf argret Std_ReturnType  DCM_MANU_RoutineResAnalyse(argin uint8        */
/* Srv_stRc_NameFunc, argin boolean *Srv_bRcCom_NameFunc, argin uint8         */
/* *Srv_stRcEnd_NameFunc, argout Dcm_NegativeResponseCodeType *u8ErrorCode,   */
/* argout uint8 *u8RoutineStatus);                                            */
/*  input ???? CALL_RcAcv_NameFunc;                                           */
/*  input ???? CALL_RcTestCond_NameFunc;                                      */
/*  input ???? CALL_RcCdn_NameFunc;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Std_ReturnType DCM_MANU_StopRoutineDmnd
(
   uint8 *Srv_stRc_NameFunc,
   boolean *Srv_bRcStart_NameFunc,
   uint8 *Srv_stRcEnd_NameFunc,
   boolean *Srv_bRcCondOk_Namefunc,
   boolean Srv_bRcSho_NameFunc,
   boolean *Srv_bRcCom_NameFunc,
   boolean *Srv_bRcCdnOk_NameFunc,
   boolean *Srv_bRcCdnNok_NameFunc,
   boolean *Srv_bRcReq_NameFunc,
   boolean *Srv_bRcStop_NameFunc,
   Dcm_NegativeResponseCodeType *u8ErrorCode,
   uint8 *u8RoutineStatus,
   void (*CALL_RcAcv_NameFunc)(void),
   void (*CALL_RcTestCond_NameFunc)( boolean *),
   void (*CALL_RcCdn_NameFunc)(boolean *, boolean *)
)
{
   Std_ReturnType u8Localreturn;

   *Srv_bRcStart_NameFunc = FALSE;
   *Srv_bRcStop_NameFunc = TRUE;
   *Srv_bRcReq_NameFunc = FALSE;
   *Srv_stRc_NameFunc = RC_WAITING;

   DCM_MANU_RoutineCntrlMachineTransition( Srv_stRc_NameFunc,
                                           *Srv_bRcStart_NameFunc,
                                           Srv_stRcEnd_NameFunc,
                                           Srv_bRcCondOk_Namefunc,
                                           Srv_bRcSho_NameFunc,
                                           Srv_bRcCom_NameFunc,
                                           Srv_bRcCdnOk_NameFunc,
                                           Srv_bRcCdnNok_NameFunc,
                                           *Srv_bRcReq_NameFunc,
                                           *Srv_bRcStop_NameFunc,
                                           CALL_RcAcv_NameFunc,
                                           CALL_RcTestCond_NameFunc,
                                           CALL_RcCdn_NameFunc );

   u8Localreturn = DCM_MANU_RoutineResAnalyse( *Srv_stRc_NameFunc,
                                    Srv_bRcCom_NameFunc,
                                    Srv_stRcEnd_NameFunc,
                                               u8ErrorCode,
                                               u8RoutineStatus );

   return u8Localreturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf DCM_MANU_RoutineCntrlMachineTransition(????);                        */
/*  extf argret Std_ReturnType  DCM_MANU_RoutineResAnalyse(argin uint8        */
/* Srv_stRc_NameFunc, argin boolean *Srv_bRcCom_NameFunc, argin uint8         */
/* *Srv_stRcEnd_NameFunc, argout Dcm_NegativeResponseCodeType *u8ErrorCode,   */
/* argout uint8 *u8RoutineStatus);                                            */
/*  input ???? CALL_RcAcv_NameFunc;                                           */
/*  input ???? CALL_RcTestCond_NameFunc;                                      */
/*  input ???? CALL_RcCdn_NameFunc;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Std_ReturnType DCM_MANU_ReqResRoutineDmnd
(
   uint8 *Srv_stRc_NameFunc,
   boolean *Srv_bRcStart_NameFunc,
   uint8 *Srv_stRcEnd_NameFunc,
   boolean *Srv_bRcCondOk_Namefunc,
   boolean Srv_bRcSho_NameFunc,
   boolean *Srv_bRcCom_NameFunc,
   boolean *Srv_bRcCdnOk_NameFunc,
   boolean *Srv_bRcCdnNok_NameFunc,
   boolean *Srv_bRcReq_NameFunc,
   boolean *Srv_bRcStop_NameFunc,
   Dcm_NegativeResponseCodeType *u8ErrorCode,
   uint8 *u8RoutineStatus,
   void (*CALL_RcAcv_NameFunc)(void),
   void (*CALL_RcTestCond_NameFunc)( boolean *),
   void (*CALL_RcCdn_NameFunc)(boolean *, boolean *)
)
{
   Std_ReturnType u8Localreturn;

   *Srv_bRcStart_NameFunc = FALSE;
   *Srv_bRcStop_NameFunc = FALSE;
   *Srv_bRcReq_NameFunc = TRUE;
   *Srv_stRc_NameFunc = RC_WAITING;

   DCM_MANU_RoutineCntrlMachineTransition( Srv_stRc_NameFunc,
                                           *Srv_bRcStart_NameFunc,
                                           Srv_stRcEnd_NameFunc,
                                           Srv_bRcCondOk_Namefunc,
                                           Srv_bRcSho_NameFunc,
                                           Srv_bRcCom_NameFunc,
                                           Srv_bRcCdnOk_NameFunc,
                                           Srv_bRcCdnNok_NameFunc,
                                           *Srv_bRcReq_NameFunc,
                                           *Srv_bRcStop_NameFunc,
                                           CALL_RcAcv_NameFunc,
                                           CALL_RcTestCond_NameFunc,
                                           CALL_RcCdn_NameFunc );

   u8Localreturn = DCM_MANU_RoutineResAnalyse( *Srv_stRc_NameFunc,
                                    Srv_bRcCom_NameFunc,
                                    Srv_stRcEnd_NameFunc,
                                               u8ErrorCode,
                                               u8RoutineStatus );

   return u8Localreturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RoutineResAnalyse                                 */
/* !Description :  Analyse des résultat de la routine.                        */
/* !Number      :  ROUTINE_CNTRL_MNG.6                                        */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_ErrorCode;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_RoutineResAnalyse
(
   uint8 Srv_stRc_NameFunc,
   boolean* Srv_bRcCom_NameFunc,
   uint8* Srv_stRcEnd_NameFunc,
   Dcm_NegativeResponseCodeType* u8ErrorCode,
   uint8* u8RoutineStatus
)
{
   Std_ReturnType u8Localreturn;

   switch( Srv_stRc_NameFunc )
   {
      case RC_COND_NOK:
      case RC_STRT_AFTER_STRT:
      u8Localreturn = E_NOT_OK;
      *u8RoutineStatus = 0x00;
      *u8ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      break;

      case RC_REQ_SEQU_ERROR:
      u8Localreturn = E_NOT_OK;
      *u8ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      *u8RoutineStatus = 0x00;
      break;

      case RC_RUNNING:
      u8Localreturn = E_OK;
      *u8ErrorCode = 0x00;
      *u8RoutineStatus = ROUTINE_EN_COURS;
      break;

      case RC_FINISHED_OK:
      u8Localreturn = E_OK;
      *u8ErrorCode = 0x00;
      *u8RoutineStatus = TERMINE_OK;
      break;

      case RC_FINISHED_NOK:
      u8Localreturn = E_OK;
      *u8ErrorCode = 0x00;
      *u8RoutineStatus = TERMINE_NOK;
      break;

      case RC_STOPPED:
      u8Localreturn = E_OK;
      *u8ErrorCode = 0x00;
      *u8RoutineStatus = 0x04;
      break;

      case RC_REJECT:
      u8Localreturn = E_NOT_OK;
      /* GeneralReject */
      *u8ErrorCode = DCM_E_GENERALREJECT;
      *u8RoutineStatus = 0x00;
      break;

      /* Cas où le T4 renvoie un NACK */
      case RC_WAITING:
      *Srv_bRcCom_NameFunc = FALSE;
      *Srv_stRcEnd_NameFunc = RC_INIT;
      *u8ErrorCode = DCM_MANU_ErrorCode;
      *u8RoutineStatus = 0x00;
      u8Localreturn = E_NOT_OK;
      break;

      /* GeneralReject */
      default:
      u8Localreturn = E_NOT_OK;
      *u8ErrorCode = DCM_E_GENERALREJECT;
      SWFAIL_vidSoftwareErrorHook();
      *u8RoutineStatus = 0x00;
      break;
   }

   return u8Localreturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf CALL_RcTestCond_NameFunc(????);                                      */
/*  extf CALL_RcAcv_NameFunc(????);                                           */
/*  extf CALL_RcCdn_NameFunc(????);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean DCM_MANU_bEnaNack;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
void DCM_MANU_RoutineCntrlMachineTransition
(
   uint8 *Srv_stRc_NameFunc,
   boolean Srv_bRcStart_NameFunc,
   uint8 *Srv_stRcEnd_NameFunc,
   boolean *Srv_bRcCondOk_Namefunc,
   boolean Srv_bRcSho_NameFunc,
   boolean *Srv_bRcCom_NameFunc,
   boolean *Srv_bRcCdnOk_NameFunc,
   boolean *Srv_bRcCdnNok_NameFunc,
   boolean Srv_bRcReq_NameFunc,
   boolean Srv_bRcStop_NameFunc,
   void (*CALL_RcAcv_NameFunc)(void),
   void (*CALL_RcTestCond_NameFunc)( boolean *),
   void (*CALL_RcCdn_NameFunc)(boolean *, boolean *)
)
{
   /* Tests des conditions */
   CALL_RcTestCond_NameFunc( Srv_bRcCondOk_Namefunc );

   if( TRUE == Srv_bRcStart_NameFunc )
   {
      if( RC_RUNNING == *Srv_stRcEnd_NameFunc )
      {
         *Srv_stRc_NameFunc = RC_STRT_AFTER_STRT;
      }
      else if( FALSE == *Srv_bRcCondOk_Namefunc )
      {
         *Srv_stRc_NameFunc = RC_COND_NOK;
      }
      else /* ( TRUE == *Srv_bRcCondOk_Namefunc ) */
      {
         if( FALSE == Srv_bRcSho_NameFunc )
         {
            CALL_RcAcv_NameFunc();
            if ( DCM_MANU_bEnaNack == FALSE)
            {
               *Srv_stRc_NameFunc = RC_RUNNING;
               *Srv_stRcEnd_NameFunc = *Srv_stRc_NameFunc;
               *Srv_bRcCom_NameFunc = TRUE;
            }
            else
            {
               *Srv_stRc_NameFunc = RC_WAITING;
               *Srv_stRcEnd_NameFunc = RC_INIT;
            }
         }
         else /* TRUE == Srv_bRcSho_NameFunc */
         {
            CALL_RcAcv_NameFunc();
            CALL_RcCdn_NameFunc(Srv_bRcCdnOk_NameFunc, Srv_bRcCdnNok_NameFunc);

            if( TRUE == *Srv_bRcCdnNok_NameFunc )
            {
               *Srv_stRc_NameFunc = RC_FINISHED_NOK;
               *Srv_stRcEnd_NameFunc = *Srv_stRc_NameFunc;
            }
            else if( TRUE == *Srv_bRcCdnOk_NameFunc )
            {
               *Srv_stRc_NameFunc = RC_FINISHED_OK;
               *Srv_stRcEnd_NameFunc = *Srv_stRc_NameFunc;
            }
            else if ( DCM_MANU_bEnaNack == TRUE)
            {
               *Srv_stRc_NameFunc = RC_WAITING;
               *Srv_stRcEnd_NameFunc = RC_INIT;
            }
            else /* ( FALSE == *Srv_bRcCdnNok_NameFunc ) &&
                    ( FALSE == *Srv_bRcCdnOk_NameFunc  ) */
            {
               *Srv_stRc_NameFunc = RC_REJECT;
            }
         }
      }
   }
   else if( TRUE == Srv_bRcStop_NameFunc )
   {
      if( FALSE == *Srv_bRcCom_NameFunc )
      {
         *Srv_stRc_NameFunc = RC_REQ_SEQU_ERROR;
      }
      else /* TRUE == *Srv_bRcCom_NameFunc */
      {
         if( ( RC_FINISHED_OK != *Srv_stRcEnd_NameFunc  ) &&
             ( RC_FINISHED_NOK != *Srv_stRcEnd_NameFunc ) )
         {
            *Srv_stRc_NameFunc = RC_STOPPED;
            *Srv_stRcEnd_NameFunc = *Srv_stRc_NameFunc;
         }
         else
         {
            *Srv_stRc_NameFunc = RC_REQ_SEQU_ERROR;
         }
      }
   }
   else if( TRUE == Srv_bRcReq_NameFunc )
   {
      CALL_RcCdn_NameFunc(Srv_bRcCdnOk_NameFunc, Srv_bRcCdnNok_NameFunc);

      if( FALSE == *Srv_bRcCom_NameFunc )
      {
         *Srv_stRc_NameFunc = RC_REQ_SEQU_ERROR;
      }
      else if( ( TRUE == *Srv_bRcCdnNok_NameFunc          ) ||
               ( RC_FINISHED_NOK == *Srv_stRcEnd_NameFunc ) )
      {
         *Srv_stRc_NameFunc = RC_FINISHED_NOK;
         *Srv_stRcEnd_NameFunc = *Srv_stRc_NameFunc;
      }
      else if( ( TRUE == *Srv_bRcCdnOk_NameFunc          ) ||
               ( RC_FINISHED_OK == *Srv_stRcEnd_NameFunc ) )
      {
         *Srv_stRc_NameFunc = RC_FINISHED_OK;
         *Srv_stRcEnd_NameFunc = *Srv_stRc_NameFunc;
      }
      else if( RC_STOPPED == *Srv_stRcEnd_NameFunc )
      {
         *Srv_stRc_NameFunc = RC_STOPPED;
         *Srv_stRcEnd_NameFunc = *Srv_stRc_NameFunc;
      }
      else if (DCM_MANU_bEnaNack == TRUE)
      {
         *Srv_stRc_NameFunc = RC_WAITING;
         *Srv_stRcEnd_NameFunc = RC_INIT;
      }
      else /* ( FALSE == *Srv_bRcCdnNok_NameFunc == 0 ) &&
              ( FALSE == *Srv_bRcCdnOk_NameFunc == 0  ) &&
              ( TRUE == *Srv_bRcCom_NameFunc == 1     ) */
      {
         *Srv_stRc_NameFunc = RC_RUNNING;
         *Srv_stRcEnd_NameFunc = *Srv_stRc_NameFunc;
      }
   }
   else
   {
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_IuprResponseCreate                                */
/* !Description :  Creation des différentes tables IUPR.                      */
/* !Number      :  ROUTINE_CNTRL_MNG.8                                        */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 IUPR_idxGrpRat_C[100];                                        */
/*  input boolean Presence_CAT1;                                              */
/*  input boolean Presence_O2S1;                                              */
/*  input boolean Presence_VVT;                                               */
/*  input boolean Presence_SO2S1;                                             */
/*  input boolean Presence_BP;                                                */
/*  input boolean Presence_EVAP;                                              */
/*  input uint16 IUPR_ctNumGrpRat[12];                                        */
/*  input uint16 IUPR_ctDenGrpRat[12];                                        */
/*  input uint16 IUPR_idxDftRat_C[100];                                       */
/*  input uint16 IUPR_ctNumRat[100];                                          */
/*  input uint16 IUPR_ctDenRat[100];                                          */
/*  output boolean Presence_BP;                                               */
/*  output boolean Presence_VVT;                                              */
/*  output boolean Presence_CAT1;                                             */
/*  output boolean Presence_O2S1;                                             */
/*  output boolean Presence_EVAP;                                             */
/*  output boolean Presence_SO2S1;                                            */
/*  output uint16 DCM_MANU_IuprNum;                                           */
/*  output uint16 DCM_MANU_IuprDen;                                           */
/*  output uint16 DCM_MANU_UdsIuprFrameSize;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_IuprResponseCreate(void)
{
   uint32  u32LocalIndex;
   uint32  u32LocalForIndex;
   uint16  u16LocalValueCopy;
   boolean bLocalLoopEnd;

   Presence_BP = FALSE;
   Presence_VVT = FALSE;
   Presence_CAT1 = FALSE;
   Presence_O2S1 = FALSE;
   Presence_EVAP = FALSE;
   Presence_SO2S1 = FALSE;

   u32LocalForIndex = 0;
   bLocalLoopEnd = FALSE;
   while( ( FALSE == bLocalLoopEnd         ) &&
          ( u32LocalForIndex < IUPR_NB_RAT ) )
   {
      if( 0x01 == IUPR_idxGrpRat_C[u32LocalForIndex] )
      {
         Presence_CAT1 = TRUE;
      }
      if( 0x06 == IUPR_idxGrpRat_C[u32LocalForIndex] )
      {
         Presence_O2S1 = TRUE;
      }
      if( 0x08 == IUPR_idxGrpRat_C[u32LocalForIndex] )
      {
         Presence_VVT = TRUE;
      }
      if( 0x0A == IUPR_idxGrpRat_C[u32LocalForIndex] )
      {
         Presence_BP = TRUE;
      }
      if( 0x0B == IUPR_idxGrpRat_C[u32LocalForIndex] )
      {
         Presence_EVAP = TRUE;
      }
      if( 0x09 == IUPR_idxGrpRat_C[u32LocalForIndex] )
      {
         Presence_SO2S1 = TRUE;
      }

      bLocalLoopEnd = ( ( TRUE == Presence_CAT1  ) &&
                        ( TRUE == Presence_O2S1  ) &&
                        ( TRUE == Presence_VVT   ) &&
                        ( TRUE == Presence_SO2S1 ) &&
                        ( TRUE == Presence_BP    ) &&
                        ( TRUE == Presence_EVAP  ) );
      u32LocalForIndex++;
   }
   u32LocalIndex = 0;
   if( TRUE == Presence_CAT1 )
   {
      VEMS_vidGET1DArrayElement( IUPR_ctNumGrpRat,
                                 (uint32)CAT1_ASW,
                                 u16LocalValueCopy );
      DCM_MANU_IuprNum[u32LocalIndex] = u16LocalValueCopy;

      VEMS_vidGET1DArrayElement( IUPR_ctDenGrpRat,
                                 (uint32)CAT1_ASW,
                                 u16LocalValueCopy );
      DCM_MANU_IuprDen[u32LocalIndex] = u16LocalValueCopy;

      u32LocalIndex++;
   }
   if( TRUE == Presence_O2S1 )
   {
      VEMS_vidGET1DArrayElement( IUPR_ctNumGrpRat,
                                 (uint32)O2S1,
                                 u16LocalValueCopy );
      DCM_MANU_IuprNum[u32LocalIndex] = u16LocalValueCopy;

      VEMS_vidGET1DArrayElement( IUPR_ctDenGrpRat,
                                 (uint32)O2S1,
                                 u16LocalValueCopy );
      DCM_MANU_IuprDen[u32LocalIndex] = u16LocalValueCopy;
      u32LocalIndex++;
   }
   if( TRUE == Presence_VVT )
   {
      VEMS_vidGET1DArrayElement( IUPR_ctNumGrpRat,
                                 (uint32)VVT,
                                 u16LocalValueCopy );
      DCM_MANU_IuprNum[u32LocalIndex] = u16LocalValueCopy;

      VEMS_vidGET1DArrayElement( IUPR_ctDenGrpRat,
                                 (uint32)VVT,
                                 u16LocalValueCopy );
      DCM_MANU_IuprDen[u32LocalIndex] = u16LocalValueCopy;
      u32LocalIndex++;
   }
   if( TRUE == Presence_BP )
   {
      VEMS_vidGET1DArrayElement( IUPR_ctNumGrpRat,
                                 (uint32)BP_DCM,
                                 u16LocalValueCopy );
      DCM_MANU_IuprNum[u32LocalIndex] = u16LocalValueCopy;

      VEMS_vidGET1DArrayElement( IUPR_ctDenGrpRat,
                                 (uint32)BP_DCM,
                                 u16LocalValueCopy );
      DCM_MANU_IuprDen[u32LocalIndex] = u16LocalValueCopy;
      u32LocalIndex++;
   }
   if( TRUE == Presence_EVAP )
   {
      VEMS_vidGET1DArrayElement( IUPR_ctNumGrpRat,
                                 (uint32)EVAP_DCM,
                                 u16LocalValueCopy );
      DCM_MANU_IuprNum[u32LocalIndex] = u16LocalValueCopy;

      VEMS_vidGET1DArrayElement( IUPR_ctDenGrpRat,
                                 (uint32)EVAP_DCM,
                                 u16LocalValueCopy );
      DCM_MANU_IuprDen[u32LocalIndex] = u16LocalValueCopy;
      u32LocalIndex++;
   }
   if( TRUE == Presence_SO2S1 )
   {
      VEMS_vidGET1DArrayElement( IUPR_ctNumGrpRat,
                                 (uint32)SO2S1,
                                 u16LocalValueCopy );
      DCM_MANU_IuprNum[u32LocalIndex] = u16LocalValueCopy;

      VEMS_vidGET1DArrayElement( IUPR_ctDenGrpRat,
                                 (uint32)SO2S1,
                                 u16LocalValueCopy );
      DCM_MANU_IuprDen[u32LocalIndex] = u16LocalValueCopy;
      u32LocalIndex++;
   }

   for( u32LocalForIndex = 0 ;
        u32LocalForIndex < IUPR_NB_RAT ;
        u32LocalForIndex++ )
   {
      if(IUPR_idxDftRat_C[u32LocalForIndex] != 0xFFFF)
      {
         VEMS_vidGET1DArrayElement( IUPR_ctNumRat,
                                 u32LocalForIndex,
                                 u16LocalValueCopy );
         DCM_MANU_IuprNum[u32LocalIndex] = u16LocalValueCopy;

         VEMS_vidGET1DArrayElement( IUPR_ctDenRat,
                                 u32LocalForIndex,
                                 u16LocalValueCopy );
         DCM_MANU_IuprDen[u32LocalIndex] = u16LocalValueCopy;

         u32LocalIndex++;
      }

   }
   DCM_MANU_UdsIuprFrameSize = (uint16)(u32LocalIndex*4);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_IuprResponseConcat                                */
/* !Description :  Concaténation de la réponse aux requêtes IUPR.             */
/* !Number      :  ROUTINE_CNTRL_MNG.9                                        */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 DCM_MANU_UdsIuprFrameSize;                                   */
/*  input uint16 DCM_MANU_UdsIuprNbByteSent;                                  */
/*  input uint16 Iupr_gen_denom_count_eep;                                    */
/*  input uint16 IUPR_ctObdStrt;                                              */
/*  input uint16 DCM_MANU_UdsIuprIndexToSend;                                 */
/*  input uint16 DCM_MANU_IuprNum;                                            */
/*  input uint16 DCM_MANU_IuprDen;                                            */
/*  output uint16 DCM_MANU_UdsIuprNbByteSent;                                 */
/*  output uint16 DCM_MANU_UdsIuprIndexToSend;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
uint8 DCM_MANU_IuprResponseConcat
(
   uint8* au8IUPR,
   uint16* u16Size
)
{
   uint32 u32LocalTmp;
   uint32 u32LocalSize;
   uint32 u32LocalTabIndex;
   uint32 u32LocalForIndex;
   uint32 u32LocalIuprXXXIndex;
   uint8  u8LocalStatutLecture;

   u32LocalTmp = DCM_MANU_UdsIuprFrameSize - DCM_MANU_UdsIuprNbByteSent;

   if( u32LocalTmp <= 244 )
   {
      u32LocalSize = u32LocalTmp;
      u8LocalStatutLecture = 0x00;
   }
   else
   {
      u32LocalSize = 244;
      u8LocalStatutLecture = 0xFF;
   }

   u32LocalTabIndex = 0;
   au8IUPR[u32LocalTabIndex] =
      (uint8)((Iupr_gen_denom_count_eep & 0xFF00) >> 8);
   u32LocalTabIndex++;
   au8IUPR[u32LocalTabIndex] =
      (uint8)(Iupr_gen_denom_count_eep & 0x00FF);
   u32LocalTabIndex++;
   au8IUPR[u32LocalTabIndex] =
      (uint8)((IUPR_ctObdStrt & 0xFF00) >> 8);
   u32LocalTabIndex++;
   au8IUPR[u32LocalTabIndex] =
      (uint8)(IUPR_ctObdStrt & 0x00FF);
   u32LocalTabIndex++;

   for( u32LocalForIndex = 0;
        u32LocalForIndex <= u32LocalSize;
        u32LocalForIndex += 4 )
   {
      u32LocalIuprXXXIndex = (u32LocalForIndex/4)+DCM_MANU_UdsIuprIndexToSend;

      au8IUPR[u32LocalForIndex+u32LocalTabIndex] =
         (uint8)((DCM_MANU_IuprNum[u32LocalIuprXXXIndex] & 0xFF00) >> 8);
      au8IUPR[u32LocalForIndex+u32LocalTabIndex+1] =
         (uint8)(DCM_MANU_IuprNum[u32LocalIuprXXXIndex] & 0x00FF);
      au8IUPR[u32LocalForIndex+u32LocalTabIndex+2] =
         (uint8)((DCM_MANU_IuprDen[u32LocalIuprXXXIndex] & 0xFF00) >> 8);
      au8IUPR[u32LocalForIndex+u32LocalTabIndex+3] =
         (uint8)(DCM_MANU_IuprDen[u32LocalIuprXXXIndex] & 0x00FF);
   }

   *u16Size = (uint16)(u32LocalTabIndex + u32LocalSize);
   DCM_MANU_UdsIuprNbByteSent += (uint16)u32LocalSize;
   DCM_MANU_UdsIuprIndexToSend = (uint16)(u32LocalIuprXXXIndex);

   return u8LocalStatutLecture;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_Matching_Result_Analyse                           */
/* !Description :  Fonction permettant d'analyser le résultat de la requete   */
/*                 Matching ADC                                               */
/* !Number      :  ROUTINE_CNTRL_MNG.10                                       */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_stADCMatch;                                               */
/*  input uint8 Srv_noADCMatchOutpPrm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_Matching_Result_Analyse
(
   uint8* u8LocalRoutineStatus,
   uint8* u8LocalErrorCode,
   uint8* u8LocalOutputParam,
   uint16* u16LocalCurrentDataLength
)
{
   uint8          u8LocalVar;
   uint8          u8LocalADCMatch;
   Std_ReturnType u8LocalNewReturn;

   VEMS_vidGET(Srv_stADCMatch, u8LocalADCMatch);

   switch( u8LocalADCMatch )
   {
      case MATCHING_ADC_ACK:
      /* Pas de réponse du module IMMO */
      *u8LocalOutputParam = 0;
      *u8LocalErrorCode = 0x00;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_PENDING;
      *u16LocalCurrentDataLength = 0;
      break;

      case MATCHING_ADC_IN_PROGRESS:
      /* Traitement en cours */
      u8LocalNewReturn = E_OK;
      *u8LocalErrorCode = 0x00;
      *u16LocalCurrentDataLength = 8;
      VEMS_vidGET(Srv_noADCMatchOutpPrm, u8LocalVar);
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = ROUTINE_EN_COURS;
      break;

      case MATCHING_ADC_OK:
      /* L'opération d'Appairage s'est bien déroulée */
      u8LocalNewReturn = E_OK;
      *u8LocalErrorCode = 0x00;
      *u16LocalCurrentDataLength = 8;
      VEMS_vidGET(Srv_noADCMatchOutpPrm, u8LocalVar);
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = TERMINE_OK;
      break;

      case MATCHING_ADC_NOK:
      /* L'opération d'Appairage ne s'est pas bien déroulée */
      u8LocalNewReturn = E_OK;
      *u8LocalErrorCode = 0x00;
      *u16LocalCurrentDataLength = 8;
      VEMS_vidGET(Srv_noADCMatchOutpPrm, u8LocalVar);
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = TERMINE_NOK;
      break;

      case MATCHING_ADC_IMPOSSIBLE:
      /* La requete a été rejetée par le module IMMO */
      *u8LocalOutputParam = 0;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_NOT_OK;
      *u16LocalCurrentDataLength = 0;
      *u8LocalErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      break;

      default /*MATCHING_ADC_TIMEOUT*/:
      /* Le module IMMO n'a pas répondu dans les temps */
      *u8LocalOutputParam = 0;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_NOT_OK;
      *u16LocalCurrentDataLength = 0;
      *u8LocalErrorCode = DCM_E_BUSYREPEATREQUEST;
      break;
   }

   return u8LocalNewReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_Programming_Result_Analyse                        */
/* !Description :  Fonction permeettant d'analyse le résultat de la requete   */
/*                 Programming ADC                                            */
/* !Number      :  ROUTINE_CNTRL_MNG.11                                       */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_stADCCodWr;                                               */
/*  input uint8 Srv_noADCCodWrOutpPrm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_Programming_Result_Analyse
(
   uint8* u8LocalRoutineStatus,
   uint8* u8LocalErrorCode,
   uint8* u8LocalOutputParam,
   uint16* u16LocalCurrentDataLength
)
{
   uint8          u8LocalVar;
   uint8          u8LocalADCCodWr;
   Std_ReturnType u8LocalNewReturn;

   VEMS_vidGET(Srv_stADCCodWr, u8LocalADCCodWr);
   VEMS_vidGET(Srv_noADCCodWrOutpPrm, u8LocalVar);

   /* Taille utile en bit du paramètre Srv_noADCCodWrOutpPrm */
   *u16LocalCurrentDataLength = 8;

   switch( u8LocalADCCodWr )
   {
      case WRITE_ADC_ACK:
      /* Pas de réponse du module IMMO */
      case WRITE_ADC_IN_PROGRESS:
      /* Traitement par le module IMMO */
      *u8LocalErrorCode = 0;
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_PENDING;

      break;

      case WRITE_ADC_IMPOSSIBLE:
      /* Ecriture rejetée par le module IMMO */
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_NOT_OK;
      *u8LocalErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      break;

      case WRITE_ADC_OK:
      /* l'écriture s'est déroulée correctement */
      *u8LocalErrorCode = 0;
      u8LocalNewReturn = E_OK;
      *u8LocalRoutineStatus = TERMINE_OK;
      *u8LocalOutputParam = u8LocalVar;
      break;

      case WRITE_ADC_NOK:
      /* l'écriture a échouée */
      *u8LocalErrorCode = 0;
      u8LocalNewReturn = E_OK;
      *u8LocalRoutineStatus = TERMINE_NOK;
      *u8LocalOutputParam = u8LocalVar;
      break;

      case WRITE_ADC_OUT_OF_RANGE:
      /* Option d'appairage incorrecte */
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_NOT_OK;
      *u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
      break;

      default /*WRITE_ADC_TIMEOUT*/:
      /* Le module IMMO n'a pas répondu dans les temps */
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_NOT_OK;
      *u8LocalErrorCode = DCM_E_BUSYREPEATREQUEST;
      break;
   }

   return u8LocalNewReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_Checking_Result_Analyse                           */
/* !Description :  Fonction permettant d'analyser le résultat de la requete   */
/*                 Checking ADC                                               */
/* !Number      :  ROUTINE_CNTRL_MNG.12                                       */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_stADCCodChk;                                              */
/*  input uint8 Srv_noADCCodChkOutpPrm;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_Checking_Result_Analyse
(
   uint8* u8LocalRoutineStatus,
   uint8* u8LocalErrorCode,
   uint8* u8LocalOutputParam,
   uint16* u16LocalCurrentDataLength
)
{
   uint8          u8LocalVar;
   uint8          u8LocalADCCodChk;
   Std_ReturnType u8LocalNewReturn;

   VEMS_vidGET(Srv_stADCCodChk, u8LocalADCCodChk);

   switch( u8LocalADCCodChk )
   {
      case CHECK_ADC_ACK:
      /* Pas de réponse du module IMMO */
      case CHECK_ADC_IN_PROGRESS:
      /* Code ADC en cours de vérification par le module IMMO */
      *u8LocalErrorCode = 0;
      *u8LocalOutputParam = 0;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_PENDING;
      *u16LocalCurrentDataLength = 0;
      break;

      case CHECK_ADC_OK:
      /* Le code ADC est OK */
      *u8LocalErrorCode = 0;
      u8LocalNewReturn = E_OK;
      *u16LocalCurrentDataLength = 8;
      VEMS_vidGET(Srv_noADCCodChkOutpPrm, u8LocalVar);
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = TERMINE_OK;
      break;

      case CHECK_ADC_NOK:
      /* Le code ADC est NOK */
      *u8LocalErrorCode = 0;
      u8LocalNewReturn = E_OK;
      *u16LocalCurrentDataLength = 8;
      VEMS_vidGET(Srv_noADCCodChkOutpPrm, u8LocalVar);
      *u8LocalOutputParam = u8LocalVar;
      *u8LocalRoutineStatus = TERMINE_NOK;
      break;

      default /*CHECK_ADC_TIMEOUT*/:
      /* Le module IMMO n'a pas répondu dans les temps */
      *u8LocalOutputParam = 0;
      *u8LocalRoutineStatus = 0;
      u8LocalNewReturn = E_NOT_OK;
      *u16LocalCurrentDataLength = 0;
      *u8LocalErrorCode = DCM_E_BUSYREPEATREQUEST;
      break;
   }

   return u8LocalNewReturn;
}
/*------------------------------ end of file ---------------------------------*/