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
/* !File            : DCM_MANU_SCH.C                                          */
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
/*   1 / DCM_MANU_Reset                                                       */
/*   2 / DCM_MANU_EveSessChg                                                  */
/*   3 / Srv_EveAckActrTstDmd_ActrTstMng                                      */
/*   4 / SrvRc_SdlMid_RcRst                                                   */
/*   5 / SrvRc_SdlFast_DiagSrv                                                */
/*   6 / Srv_EvePwrl_SrvRc                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/* !Reference   : PTS_DOC_5074350 / 4                                         */
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
/* !Function    :  DCM_MANU_Reset                                             */
/* !Description :  Evènement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_01688_002.01                                     */
/*                 VEMS_R_11_01688_003.01                                     */
/*                 VEMS_R_11_01688_004.01                                     */
/*                 VEMS_R_11_01688_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_SecurityAcessReqInit();                         */
/*  extf argret void DCM_MANU_TelecodageWriteReqInit();                       */
/*  extf argret void DCM_MANU_CaracInjWriteReqInit();                         */
/*  extf argret void DCM_MANU_EveRst_ActrTstRc();                             */
/*  extf argret void DCM_MANU_EveRst_RC();                                    */
/*  extf argret void DCM_MANU_ResetInit();                                    */
/*  extf argret void DCM_MANU_vidEveRst();                                    */
/*  extf argret void DCM_MANU_vidEveRst_SrvDiagConst();                       */
/*  extf argret void DCM_MANU_PostEquipementWriteReqInit();                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DCM_MANU_Reset                                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_Reset(void)
{
   DCM_MANU_SecurityAcessReqInit();
   DCM_MANU_TelecodageWriteReqInit();
   DCM_MANU_CaracInjWriteReqInit();
   DCM_MANU_EveRst_ActrTstRc();
   DCM_MANU_EveRst_RC();
   DCM_MANU_ResetInit();
   DCM_MANU_vidEveRst();
   DCM_MANU_vidEveRst_SrvDiagConst();
   DCM_MANU_PostEquipementWriteReqInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveSessChg                                        */
/* !Description :  Evènement appelé lorsque le DCM change de session.         */
/*                 (Evènement interne au DCM_MANU)                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_EveSessChg_ActrTstRc();                         */
/*  extf argret void DCM_MANU_EveSessChg_RC();                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input bool SRV_TELEACCESS_IDLE;                                           */
/*  output st58 Srv_stTeleAccessStatus;                                       */
/*  output bool SRV_TELEACCESS_IDLE;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DCM_MANU_EveSessChg                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveSessChg(void)
{
   DCM_MANU_EveSessChg_ActrTstRc();
   DCM_MANU_EveSessChg_RC();
   VEMS_vidSET(Srv_stTeleAccessStatus,SRV_TELEACCESS_IDLE);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveAckActrTstDmd_ActrTstMng                            */
/* !Description :  Fonction appelée par le Manager des test actionneurs pour  */
/*                 initialiser certaines variables.                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_EveAckActrTstDmd();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveAckActrTstDmd_ActrTstMng(void)
{
   DCM_MANU_EveAckActrTstDmd();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SrvRc_SdlMid_RcRst                                         */
/* !Description :  Scheduler Mid for the service Routine Control reset of     */
/*                 adaptatives                                                */
/* !Number      :  SCH.4                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_01688_001.01                                     */
/*                 VEMS_R_11_01688_002.01                                     */
/*                 VEMS_R_11_01688_003.01                                     */
/*                 VEMS_R_11_01688_004.01                                     */
/*                 VEMS_R_11_01688_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_EveRcRst1();                                    */
/*  extf argret void DCM_MANU_EveRcRst2();                                    */
/*  extf argret void DCM_MANU_EveRC_SdlMid();                                 */
/*  extf argret void DCM_MANU_EveRcRst4();                                    */
/*  extf argret void DCM_MANU_EveRcStt();                                     */
/*  extf argret void DCM_MANU_vidSdlMid_SrvDiagConst();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SrvRc_SdlMid_RcRst(void)
{
   DCM_MANU_EveRcRst1();
   DCM_MANU_EveRcRst2();
   DCM_MANU_EveRC_SdlMid(); /* F12_Gene_event_InhBoostGDI */
   DCM_MANU_EveRcRst4();
   DCM_MANU_EveRcStt();
   DCM_MANU_vidSdlMid_SrvDiagConst();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SrvRc_SdlFast_DiagSrv                                      */
/* !Description :  Moniteur rapide de la fonction Srv                         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_02667_023.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_vidSdlFast();                                   */
/*  extf argret void DCM_MANU_vidSdlFast_DiagSrvSA();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SrvRc_SdlFast_DiagSrv(void)
{
   DCM_MANU_vidSdlFast();
   DCM_MANU_vidSdlFast_DiagSrvSA();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EvePwrl_SrvRc                                          */
/* !Description :  Powerlatch event for the SRV function                      */
/* !Number      :  SCH.6                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_vidPwrl_SrvRc();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EvePwrl_SrvRc(void)
{
   DCM_MANU_vidPwrl_SrvRc();
}
