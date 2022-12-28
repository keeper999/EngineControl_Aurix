/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !File            : Dlt_RoutineControl_API6.c                               */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DLT_RequestResult_DF15                                               */
/*   2 / DLT_StartRoutine_DF15                                                */
/*   3 / DLT_RequestResult_DF1C                                               */
/*   4 / DLT_StartRoutine_DF1C                                                */
/*   5 / DLT_RequestResult_DF0D                                               */
/*   6 / DLT_StartRoutine_DF0D                                                */
/*   7 / DLT_RequestResult_DF34                                               */
/*   8 / DLT_StartRoutine_DF34                                                */
/*   9 / DLT_RequestResult_DF08                                               */
/*   10 / DLT_StartRoutine_DF08                                               */
/*   11 / DLT_RequestResult_DF10                                              */
/*   12 / DLT_StartRoutine_DF10                                               */
/*   13 / DLT_RequestResult_DF11                                              */
/*   14 / DLT_StartRoutine_DF11                                               */
/*   15 / DLT_RequestResult_DF35                                              */
/*   16 / DLT_StartRoutine_DF35                                               */
/*   17 / DLT_RequestResult_DFC7                                              */
/*   18 / DLT_StartRoutine_DFC7                                               */
/*   19 / DLT_RequestResult_DFC8                                              */
/*   20 / DLT_StartRoutine_DFC8                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5074350 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dlt$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "Dlt.h"
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF15                                     */
/* !Description :  Is called from Dcm when RID DF15 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.1                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstDfwChg;                                           */
/*  input boolean Srv_bRcStart_RstDfwChg;                                     */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input boolean Srv_bRcCondOk_RstDfwChg;                                    */
/*  input boolean Srv_bRcCom_RstDfwChg;                                       */
/*  input boolean Srv_bRcCdnOk_RstDfwChg;                                     */
/*  input boolean Srv_bRcCdnNok_RstDfwChg;                                    */
/*  input boolean Srv_bRcReq_RstDfwChg;                                       */
/*  input boolean Srv_bRcStop_RstDfwChg;                                      */
/*  input ???? DCM_MANU_RcAcv_RstDfwChg;                                      */
/*  input ???? DCM_MANU_CheckCond4RstDfwChg;                                  */
/*  input ???? DCM_MANU_CheckRcCdn_RstDfwChg;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF15
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstDfwChg,
                                       &Srv_bRcStart_RstDfwChg,
                                       &Srv_stRcEnd_RstDfwChg,
                                       &Srv_bRcCondOk_RstDfwChg,
                                       /* Srv_bRcSho_MkdPwrl */
                                       FALSE,
                                       &Srv_bRcCom_RstDfwChg,
                                       &Srv_bRcCdnOk_RstDfwChg,
                                       &Srv_bRcCdnNok_RstDfwChg,
                                       &Srv_bRcReq_RstDfwChg,
                                       &Srv_bRcStop_RstDfwChg,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstDfwChg,
                                       DCM_MANU_CheckCond4RstDfwChg,
                                       DCM_MANU_CheckRcCdn_RstDfwChg);
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF15                                      */
/* !Description :  Is called from Dcm when RID DF15 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.2                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstDfwChg;                                           */
/*  input boolean Srv_bRcStart_RstDfwChg;                                     */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input boolean Srv_bRcCondOk_RstDfwChg;                                    */
/*  input boolean Srv_bRcCom_RstDfwChg;                                       */
/*  input boolean Srv_bRcCdnOk_RstDfwChg;                                     */
/*  input boolean Srv_bRcCdnNok_RstDfwChg;                                    */
/*  input boolean Srv_bRcReq_RstDfwChg;                                       */
/*  input boolean Srv_bRcStop_RstDfwChg;                                      */
/*  input ???? DCM_MANU_RcAcv_RstDfwChg;                                      */
/*  input ???? DCM_MANU_CheckCond4RstDfwChg;                                  */
/*  input ???? DCM_MANU_CheckRcCdn_RstDfwChg;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF15
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstDfwChg,
                                       &Srv_bRcStart_RstDfwChg,
                                       &Srv_stRcEnd_RstDfwChg,
                                       &Srv_bRcCondOk_RstDfwChg,
                                       /* Srv_bRcSho_MkdPwrl */
                                       FALSE,
                                       &Srv_bRcCom_RstDfwChg,
                                       &Srv_bRcCdnOk_RstDfwChg,
                                       &Srv_bRcCdnNok_RstDfwChg,
                                       &Srv_bRcReq_RstDfwChg,
                                       &Srv_bRcStop_RstDfwChg,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstDfwChg,
                                       DCM_MANU_CheckCond4RstDfwChg,
                                       DCM_MANU_CheckRcCdn_RstDfwChg);
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF1C                                     */
/* !Description :  Is called from Dcm when RID DF1C service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.3                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstAFAMgtT;                                          */
/*  input boolean Srv_bRcStart_RstAFAMgtT;                                    */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input boolean Srv_bRcCondOk_RstAFAMgtT;                                   */
/*  input boolean Srv_bRcCom_RstAFAMgtT;                                      */
/*  input boolean Srv_bRcCdnOk_RstAFAMgtT;                                    */
/*  input boolean Srv_bRcCdnNok_RstAFAMgtT;                                   */
/*  input boolean Srv_bRcReq_RstAFAMgtT;                                      */
/*  input boolean Srv_bRcStop_RstAFAMgtT;                                     */
/*  input ???? DCM_MANU_RcAcv_RstAFAMgtT;                                     */
/*  input ???? DCM_MANU_CheckCond4RstAFAMgtT;                                 */
/*  input ???? DCM_MANU_CheckRcCdn_RstAFAMgtT;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF1C
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstAFAMgtT,
                                       &Srv_bRcStart_RstAFAMgtT,
                                       &Srv_stRcEnd_RstAFAMgtT,
                                       &Srv_bRcCondOk_RstAFAMgtT,
                                       /* Srv_bRcSho_MkdPwrl */
                                       FALSE,
                                       &Srv_bRcCom_RstAFAMgtT,
                                       &Srv_bRcCdnOk_RstAFAMgtT,
                                       &Srv_bRcCdnNok_RstAFAMgtT,
                                       &Srv_bRcReq_RstAFAMgtT,
                                       &Srv_bRcStop_RstAFAMgtT,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstAFAMgtT,
                                       DCM_MANU_CheckCond4RstAFAMgtT,
                                       DCM_MANU_CheckRcCdn_RstAFAMgtT );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF1C                                      */
/* !Description :  Is called from Dcm when RID DF1C service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.4                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstAFAMgtT;                                          */
/*  input boolean Srv_bRcStart_RstAFAMgtT;                                    */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input boolean Srv_bRcCondOk_RstAFAMgtT;                                   */
/*  input boolean Srv_bRcCom_RstAFAMgtT;                                      */
/*  input boolean Srv_bRcCdnOk_RstAFAMgtT;                                    */
/*  input boolean Srv_bRcCdnNok_RstAFAMgtT;                                   */
/*  input boolean Srv_bRcReq_RstAFAMgtT;                                      */
/*  input boolean Srv_bRcStop_RstAFAMgtT;                                     */
/*  input ???? DCM_MANU_RcAcv_RstAFAMgtT;                                     */
/*  input ???? DCM_MANU_CheckCond4RstAFAMgtT;                                 */
/*  input ???? DCM_MANU_CheckRcCdn_RstAFAMgtT;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF1C
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstAFAMgtT,
                                       &Srv_bRcStart_RstAFAMgtT,
                                       &Srv_stRcEnd_RstAFAMgtT,
                                       &Srv_bRcCondOk_RstAFAMgtT,
                                       /* Srv_bRcSho_MkdPwrl */
                                       FALSE,
                                       &Srv_bRcCom_RstAFAMgtT,
                                       &Srv_bRcCdnOk_RstAFAMgtT,
                                       &Srv_bRcCdnNok_RstAFAMgtT,
                                       &Srv_bRcReq_RstAFAMgtT,
                                       &Srv_bRcStop_RstAFAMgtT,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstAFAMgtT,
                                       DCM_MANU_CheckCond4RstAFAMgtT,
                                       DCM_MANU_CheckRcCdn_RstAFAMgtT );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF0D                                     */
/* !Description :  Is called from Dcm when RID DF0D service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.5                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstTrbActSys;                                        */
/*  input boolean Srv_bRcStart_RstTrbActSys;                                  */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input boolean Srv_bRcCondOk_RstTrbActSys;                                 */
/*  input boolean Srv_bRcCom_RstTrbActSys;                                    */
/*  input boolean Srv_bRcCdnOk_RstTrbActSys;                                  */
/*  input boolean Srv_bRcCdnNok_RstTrbActSys;                                 */
/*  input boolean Srv_bRcReq_RstTrbActSys;                                    */
/*  input boolean Srv_bRcStop_RstTrbActSys;                                   */
/*  input ???? DCM_MANU_RcAcv_RstTrbActSys;                                   */
/*  input ???? DCM_MANU_CheckCond4RstTrbActSys;                               */
/*  input ???? DCM_MANU_CheckRcCdn_RstTrbActSys;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF0D
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstTrbActSys,
                                       &Srv_bRcStart_RstTrbActSys,
                                       &Srv_stRcEnd_RstTrbActSys,
                                       &Srv_bRcCondOk_RstTrbActSys,
                                       /* Srv_bRcSho_RstCurRdB */
                                       FALSE,
                                       &Srv_bRcCom_RstTrbActSys,
                                       &Srv_bRcCdnOk_RstTrbActSys,
                                       &Srv_bRcCdnNok_RstTrbActSys,
                                       &Srv_bRcReq_RstTrbActSys,
                                       &Srv_bRcStop_RstTrbActSys,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstTrbActSys,
                                       DCM_MANU_CheckCond4RstTrbActSys,
                                       DCM_MANU_CheckRcCdn_RstTrbActSys);
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF0D                                      */
/* !Description :  Is called from Dcm when RID DF0D service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.6                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstTrbActSys;                                        */
/*  input boolean Srv_bRcStart_RstTrbActSys;                                  */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input boolean Srv_bRcCondOk_RstTrbActSys;                                 */
/*  input boolean Srv_bRcCom_RstTrbActSys;                                    */
/*  input boolean Srv_bRcCdnOk_RstTrbActSys;                                  */
/*  input boolean Srv_bRcCdnNok_RstTrbActSys;                                 */
/*  input boolean Srv_bRcReq_RstTrbActSys;                                    */
/*  input boolean Srv_bRcStop_RstTrbActSys;                                   */
/*  input ???? DCM_MANU_RcAcv_RstTrbActSys;                                   */
/*  input ???? DCM_MANU_CheckCond4RstTrbActSys;                               */
/*  input ???? DCM_MANU_CheckRcCdn_RstTrbActSys;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF0D
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstTrbActSys,
                                       &Srv_bRcStart_RstTrbActSys,
                                       &Srv_stRcEnd_RstTrbActSys,
                                       &Srv_bRcCondOk_RstTrbActSys,
                                       /* Srv_bRcSho_RstCurRdB */
                                       FALSE,
                                       &Srv_bRcCom_RstTrbActSys,
                                       &Srv_bRcCdnOk_RstTrbActSys,
                                       &Srv_bRcCdnNok_RstTrbActSys,
                                       &Srv_bRcReq_RstTrbActSys,
                                       &Srv_bRcStop_RstTrbActSys,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstTrbActSys,
                                       DCM_MANU_CheckCond4RstTrbActSys,
                                       DCM_MANU_CheckRcCdn_RstTrbActSys);
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF34                                     */
/* !Description :  Is called from Dcm when RID DF34 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.7                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstESLim;                                            */
/*  input boolean Srv_bRcStart_RstESLim;                                      */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input boolean Srv_bRcCondOk_RstESLim;                                     */
/*  input boolean Srv_bRcCom_RstESLim;                                        */
/*  input boolean Srv_bRcCdnOk_RstESLim;                                      */
/*  input boolean Srv_bRcCdnNok_RstESLim;                                     */
/*  input boolean Srv_bRcReq_RstESLim;                                        */
/*  input boolean Srv_bRcStop_RstESLim;                                       */
/*  input ???? DCM_MANU_RcAcv_RstESLim;                                       */
/*  input ???? DCM_MANU_CheckCond4RstESLim;                                   */
/*  input ???? DCM_MANU_CheckRcCdn_RstESLim;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF34
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstESLim,
                                       &Srv_bRcStart_RstESLim,
                                       &Srv_stRcEnd_RstESLim,
                                       &Srv_bRcCondOk_RstESLim,
                                       /* Srv_bRcSho_RstCoReqRStrt */
                                       FALSE,
                                       &Srv_bRcCom_RstESLim,
                                       &Srv_bRcCdnOk_RstESLim,
                                       &Srv_bRcCdnNok_RstESLim,
                                       &Srv_bRcReq_RstESLim,
                                       &Srv_bRcStop_RstESLim,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstESLim,
                                       DCM_MANU_CheckCond4RstESLim,
                                       DCM_MANU_CheckRcCdn_RstESLim );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF34                                      */
/* !Description :  Is called from Dcm when RID DF34 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.8                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstESLim;                                            */
/*  input boolean Srv_bRcStart_RstESLim;                                      */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input boolean Srv_bRcCondOk_RstESLim;                                     */
/*  input boolean Srv_bRcCom_RstESLim;                                        */
/*  input boolean Srv_bRcCdnOk_RstESLim;                                      */
/*  input boolean Srv_bRcCdnNok_RstESLim;                                     */
/*  input boolean Srv_bRcReq_RstESLim;                                        */
/*  input boolean Srv_bRcStop_RstESLim;                                       */
/*  input ???? DCM_MANU_RcAcv_RstESLim;                                       */
/*  input ???? DCM_MANU_CheckCond4RstESLim;                                   */
/*  input ???? DCM_MANU_CheckRcCdn_RstESLim;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF34
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstESLim,
                                       &Srv_bRcStart_RstESLim,
                                       &Srv_stRcEnd_RstESLim,
                                       &Srv_bRcCondOk_RstESLim,
                                       /* Srv_bRcSho_RstCoReqRStrt */
                                       FALSE,
                                       &Srv_bRcCom_RstESLim,
                                       &Srv_bRcCdnOk_RstESLim,
                                       &Srv_bRcCdnNok_RstESLim,
                                       &Srv_bRcReq_RstESLim,
                                       &Srv_bRcStop_RstESLim,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstESLim,
                                       DCM_MANU_CheckCond4RstESLim,
                                       DCM_MANU_CheckRcCdn_RstESLim );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF08                                     */
/* !Description :  Is called from Dcm when RID DF08 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.9                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstCylHdDmgCnt;                                      */
/*  input boolean Srv_bRcStart_RstCylHdDmgCnt;                                */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input boolean Srv_bRcCondOk_RstCylHdDmgCnt;                               */
/*  input boolean Srv_bRcCom_RstCylHdDmgCnt;                                  */
/*  input boolean Srv_bRcCdnOk_RstCylHdDmgCnt;                                */
/*  input boolean Srv_bRcCdnNok_RstCylHdDmgCnt;                               */
/*  input boolean Srv_bRcReq_RstCylHdDmgCnt;                                  */
/*  input boolean Srv_bRcStop_RstCylHdDmgCnt;                                 */
/*  input ???? DCM_MANU_RcAcv_RstCylHdDmgCnt;                                 */
/*  input ???? DCM_MANU_CheckCond4RstCylHdDmgCnt;                             */
/*  input ???? DCM_MANU_CheckRcCdn_RstCylHdDmgCnt;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF08
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstCylHdDmgCnt,
                                       &Srv_bRcStart_RstCylHdDmgCnt,
                                       &Srv_stRcEnd_RstCylHdDmgCnt,
                                       &Srv_bRcCondOk_RstCylHdDmgCnt,
                                       /* Srv_bRcSho_RstStaCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstCylHdDmgCnt,
                                       &Srv_bRcCdnOk_RstCylHdDmgCnt,
                                       &Srv_bRcCdnNok_RstCylHdDmgCnt,
                                       &Srv_bRcReq_RstCylHdDmgCnt,
                                       &Srv_bRcStop_RstCylHdDmgCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCylHdDmgCnt,
                                       DCM_MANU_CheckCond4RstCylHdDmgCnt,
                                       DCM_MANU_CheckRcCdn_RstCylHdDmgCnt );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF08                                      */
/* !Description :  Is called from Dcm when RID DF08 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.10                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstCylHdDmgCnt;                                      */
/*  input boolean Srv_bRcStart_RstCylHdDmgCnt;                                */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input boolean Srv_bRcCondOk_RstCylHdDmgCnt;                               */
/*  input boolean Srv_bRcCom_RstCylHdDmgCnt;                                  */
/*  input boolean Srv_bRcCdnOk_RstCylHdDmgCnt;                                */
/*  input boolean Srv_bRcCdnNok_RstCylHdDmgCnt;                               */
/*  input boolean Srv_bRcReq_RstCylHdDmgCnt;                                  */
/*  input boolean Srv_bRcStop_RstCylHdDmgCnt;                                 */
/*  input ???? DCM_MANU_RcAcv_RstCylHdDmgCnt;                                 */
/*  input ???? DCM_MANU_CheckCond4RstCylHdDmgCnt;                             */
/*  input ???? DCM_MANU_CheckRcCdn_RstCylHdDmgCnt;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF08
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstCylHdDmgCnt,
                                       &Srv_bRcStart_RstCylHdDmgCnt,
                                       &Srv_stRcEnd_RstCylHdDmgCnt,
                                       &Srv_bRcCondOk_RstCylHdDmgCnt,
                                       /* Srv_bRcSho_RstStaCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstCylHdDmgCnt,
                                       &Srv_bRcCdnOk_RstCylHdDmgCnt,
                                       &Srv_bRcCdnNok_RstCylHdDmgCnt,
                                       &Srv_bRcReq_RstCylHdDmgCnt,
                                       &Srv_bRcStop_RstCylHdDmgCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCylHdDmgCnt,
                                       DCM_MANU_CheckCond4RstCylHdDmgCnt,
                                       DCM_MANU_CheckRcCdn_RstCylHdDmgCnt );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF10                                     */
/* !Description :  Is called from Dcm when RID DF10 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.11                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstMnfDmgCnt;                                        */
/*  input boolean Srv_bRcStart_RstMnfDmgCnt;                                  */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input boolean Srv_bRcCondOk_RstMnfDmgCnt;                                 */
/*  input boolean Srv_bRcCom_RstMnfDmgCnt;                                    */
/*  input boolean Srv_bRcCdnOk_RstMnfDmgCnt;                                  */
/*  input boolean Srv_bRcCdnNok_RstMnfDmgCnt;                                 */
/*  input boolean Srv_bRcReq_RstMnfDmgCnt;                                    */
/*  input boolean Srv_bRcStop_RstMnfDmgCnt;                                   */
/*  input ???? DCM_MANU_RcAcv_RstMnfDmgCnt;                                   */
/*  input ???? DCM_MANU_CheckCond4RstMnfDmgCnt;                               */
/*  input ???? DCM_MANU_CheckRcCdn_RstMnfDmgCnt;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF10
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstMnfDmgCnt,
                                       &Srv_bRcStart_RstMnfDmgCnt,
                                       &Srv_stRcEnd_RstMnfDmgCnt,
                                       &Srv_bRcCondOk_RstMnfDmgCnt,
                                       /* Srv_bRcSho_RstStaCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstMnfDmgCnt,
                                       &Srv_bRcCdnOk_RstMnfDmgCnt,
                                       &Srv_bRcCdnNok_RstMnfDmgCnt,
                                       &Srv_bRcReq_RstMnfDmgCnt,
                                       &Srv_bRcStop_RstMnfDmgCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstMnfDmgCnt,
                                       DCM_MANU_CheckCond4RstMnfDmgCnt,
                                       DCM_MANU_CheckRcCdn_RstMnfDmgCnt );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF10                                      */
/* !Description :  Is called from Dcm when RID DF10 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.12                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstMnfDmgCnt;                                        */
/*  input boolean Srv_bRcStart_RstMnfDmgCnt;                                  */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input boolean Srv_bRcCondOk_RstMnfDmgCnt;                                 */
/*  input boolean Srv_bRcCom_RstMnfDmgCnt;                                    */
/*  input boolean Srv_bRcCdnOk_RstMnfDmgCnt;                                  */
/*  input boolean Srv_bRcCdnNok_RstMnfDmgCnt;                                 */
/*  input boolean Srv_bRcReq_RstMnfDmgCnt;                                    */
/*  input boolean Srv_bRcStop_RstMnfDmgCnt;                                   */
/*  input ???? DCM_MANU_RcAcv_RstMnfDmgCnt;                                   */
/*  input ???? DCM_MANU_CheckCond4RstMnfDmgCnt;                               */
/*  input ???? DCM_MANU_CheckRcCdn_RstMnfDmgCnt;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF10
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstMnfDmgCnt,
                                       &Srv_bRcStart_RstMnfDmgCnt,
                                       &Srv_stRcEnd_RstMnfDmgCnt,
                                       &Srv_bRcCondOk_RstMnfDmgCnt,
                                       /* Srv_bRcSho_RstStaCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstMnfDmgCnt,
                                       &Srv_bRcCdnOk_RstMnfDmgCnt,
                                       &Srv_bRcCdnNok_RstMnfDmgCnt,
                                       &Srv_bRcReq_RstMnfDmgCnt,
                                       &Srv_bRcStop_RstMnfDmgCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstMnfDmgCnt,
                                       DCM_MANU_CheckCond4RstMnfDmgCnt,
                                       DCM_MANU_CheckRcCdn_RstMnfDmgCnt );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF11                                     */
/* !Description :  Is called from Dcm when RID DF11 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.13                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstTrbDmgCnt;                                        */
/*  input boolean Srv_bRcStart_RstTrbDmgCnt;                                  */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input boolean Srv_bRcCondOk_RstTrbDmgCnt;                                 */
/*  input boolean Srv_bRcCom_RstTrbDmgCnt;                                    */
/*  input boolean Srv_bRcCdnOk_RstTrbDmgCnt;                                  */
/*  input boolean Srv_bRcCdnNok_RstTrbDmgCnt;                                 */
/*  input boolean Srv_bRcReq_RstTrbDmgCnt;                                    */
/*  input boolean Srv_bRcStop_RstTrbDmgCnt;                                   */
/*  input ???? DCM_MANU_RcAcv_RstTrbDmgCnt;                                   */
/*  input ???? DCM_MANU_CheckCond4RstTrbDmgCnt;                               */
/*  input ???? DCM_MANU_CheckRcCdn_RstTrbDmgCnt;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF11
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstTrbDmgCnt,
                                       &Srv_bRcStart_RstTrbDmgCnt,
                                       &Srv_stRcEnd_RstTrbDmgCnt,
                                       &Srv_bRcCondOk_RstTrbDmgCnt,
                                       /* Srv_bRcSho_RstCluDftCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstTrbDmgCnt,
                                       &Srv_bRcCdnOk_RstTrbDmgCnt,
                                       &Srv_bRcCdnNok_RstTrbDmgCnt,
                                       &Srv_bRcReq_RstTrbDmgCnt,
                                       &Srv_bRcStop_RstTrbDmgCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstTrbDmgCnt,
                                       DCM_MANU_CheckCond4RstTrbDmgCnt,
                                       DCM_MANU_CheckRcCdn_RstTrbDmgCnt );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF11                                      */
/* !Description :  Is called from Dcm when RID DF11 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.14                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstTrbDmgCnt;                                        */
/*  input boolean Srv_bRcStart_RstTrbDmgCnt;                                  */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input boolean Srv_bRcCondOk_RstTrbDmgCnt;                                 */
/*  input boolean Srv_bRcCom_RstTrbDmgCnt;                                    */
/*  input boolean Srv_bRcCdnOk_RstTrbDmgCnt;                                  */
/*  input boolean Srv_bRcCdnNok_RstTrbDmgCnt;                                 */
/*  input boolean Srv_bRcReq_RstTrbDmgCnt;                                    */
/*  input boolean Srv_bRcStop_RstTrbDmgCnt;                                   */
/*  input ???? DCM_MANU_RcAcv_RstTrbDmgCnt;                                   */
/*  input ???? DCM_MANU_CheckCond4RstTrbDmgCnt;                               */
/*  input ???? DCM_MANU_CheckRcCdn_RstTrbDmgCnt;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF11
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstTrbDmgCnt,
                                       &Srv_bRcStart_RstTrbDmgCnt,
                                       &Srv_stRcEnd_RstTrbDmgCnt,
                                       &Srv_bRcCondOk_RstTrbDmgCnt,
                                       /* Srv_bRcSho_RstCluDftCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstTrbDmgCnt,
                                       &Srv_bRcCdnOk_RstTrbDmgCnt,
                                       &Srv_bRcCdnNok_RstTrbDmgCnt,
                                       &Srv_bRcReq_RstTrbDmgCnt,
                                       &Srv_bRcStop_RstTrbDmgCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstTrbDmgCnt,
                                       DCM_MANU_CheckCond4RstTrbDmgCnt,
                                       DCM_MANU_CheckRcCdn_RstTrbDmgCnt );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF35                                     */
/* !Description :  Is called from Dcm when RID DF35 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.15                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstCylHdDmgCplmCnt;                                  */
/*  input boolean Srv_bRcStart_RstCylHdDmgCplmCnt;                            */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input boolean Srv_bRcCondOk_RstCylHdDmgCplmCnt;                           */
/*  input boolean Srv_bRcCom_RstCylHdDmgCplmCnt;                              */
/*  input boolean Srv_bRcCdnOk_RstCylHdDmgCplmCnt;                            */
/*  input boolean Srv_bRcCdnNok_RstCylHdDmgCplmCnt;                           */
/*  input boolean Srv_bRcReq_RstCylHdDmgCplmCnt;                              */
/*  input boolean Srv_bRcStop_RstCylHdDmgCplmCnt;                             */
/*  input ???? DCM_MANU_RcAcv_RstCylHdDmgCplmCnt;                             */
/*  input ???? DCM_MANU_CheckCond4RstCylHdDmgCplmCnt;                         */
/*  input ???? DCM_MANU_CheckRcCdn_RstCylHdDmgCplmCnt;                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF35
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstCylHdDmgCplmCnt,
                                       &Srv_bRcStart_RstCylHdDmgCplmCnt,
                                       &Srv_stRcEnd_RstCylHdDmgCplmCnt,
                                       &Srv_bRcCondOk_RstCylHdDmgCplmCnt,
                                       /* Srv_bRcSho_RstCluDftCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstCylHdDmgCplmCnt,
                                       &Srv_bRcCdnOk_RstCylHdDmgCplmCnt,
                                       &Srv_bRcCdnNok_RstCylHdDmgCplmCnt,
                                       &Srv_bRcReq_RstCylHdDmgCplmCnt,
                                       &Srv_bRcStop_RstCylHdDmgCplmCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCylHdDmgCplmCnt,
                                       DCM_MANU_CheckCond4RstCylHdDmgCplmCnt,
                                       DCM_MANU_CheckRcCdn_RstCylHdDmgCplmCnt );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF35                                      */
/* !Description :  Is called from Dcm when RID DF35 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.16                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstCylHdDmgCplmCnt;                                  */
/*  input boolean Srv_bRcStart_RstCylHdDmgCplmCnt;                            */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input boolean Srv_bRcCondOk_RstCylHdDmgCplmCnt;                           */
/*  input boolean Srv_bRcCom_RstCylHdDmgCplmCnt;                              */
/*  input boolean Srv_bRcCdnOk_RstCylHdDmgCplmCnt;                            */
/*  input boolean Srv_bRcCdnNok_RstCylHdDmgCplmCnt;                           */
/*  input boolean Srv_bRcReq_RstCylHdDmgCplmCnt;                              */
/*  input boolean Srv_bRcStop_RstCylHdDmgCplmCnt;                             */
/*  input ???? DCM_MANU_RcAcv_RstCylHdDmgCplmCnt;                             */
/*  input ???? DCM_MANU_CheckCond4RstCylHdDmgCplmCnt;                         */
/*  input ???? DCM_MANU_CheckRcCdn_RstCylHdDmgCplmCnt;                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF35
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstCylHdDmgCplmCnt,
                                       &Srv_bRcStart_RstCylHdDmgCplmCnt,
                                       &Srv_stRcEnd_RstCylHdDmgCplmCnt,
                                       &Srv_bRcCondOk_RstCylHdDmgCplmCnt,
                                       /* Srv_bRcSho_RstCluDftCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstCylHdDmgCplmCnt,
                                       &Srv_bRcCdnOk_RstCylHdDmgCplmCnt,
                                       &Srv_bRcCdnNok_RstCylHdDmgCplmCnt,
                                       &Srv_bRcReq_RstCylHdDmgCplmCnt,
                                       &Srv_bRcStop_RstCylHdDmgCplmCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCylHdDmgCplmCnt,
                                       DCM_MANU_CheckCond4RstCylHdDmgCplmCnt,
                                       DCM_MANU_CheckRcCdn_RstCylHdDmgCplmCnt );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFC7                                     */
/* !Description :  Is called from Dcm when RID DFC7 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.17                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_010.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_ModeSTTFactReq;                                      */
/*  input boolean Srv_bRcStart_ModeSTTFactReq;                                */
/*  input uint8 Srv_stRcEnd_ModeSTTFactReq;                                   */
/*  input boolean Srv_bRcCondOk_ModeSTTFactReq;                               */
/*  input boolean Srv_bRcCom_ModeSTTFactReq;                                  */
/*  input boolean Srv_bRcCdnOk_ModeSTTFactReq;                                */
/*  input boolean Srv_bRcCdnNok_ModeSTTFactReq;                               */
/*  input boolean Srv_bRcReq_ModeSTTFactReq;                                  */
/*  input boolean Srv_bRcStop_ModeSTTFactReq;                                 */
/*  input ???? DCM_MANU_RcAcv_ModeSTTFactReq;                                 */
/*  input ???? DCM_MANU_CheckCond4ModeSTTFactReq;                             */
/*  input ???? DCM_MANU_CheckRcCdn_ModeSTTFactReq;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DFC7
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd(&Srv_stRc_ModeSTTFactReq,
                                       &Srv_bRcStart_ModeSTTFactReq,
                                       &Srv_stRcEnd_ModeSTTFactReq,
                                       &Srv_bRcCondOk_ModeSTTFactReq,
                                       /* Srv_bRcSho_RstStaCnt */
                                       FALSE,
                                       &Srv_bRcCom_ModeSTTFactReq,
                                       &Srv_bRcCdnOk_ModeSTTFactReq,
                                       &Srv_bRcCdnNok_ModeSTTFactReq,
                                       &Srv_bRcReq_ModeSTTFactReq,
                                       &Srv_bRcStop_ModeSTTFactReq,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_ModeSTTFactReq,
                                       DCM_MANU_CheckCond4ModeSTTFactReq,
                                       DCM_MANU_CheckRcCdn_ModeSTTFactReq );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DFC7                                      */
/* !Description :  Is called from Dcm when RID DFC7 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.18                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_010.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_ModeSTTFactReq;                                      */
/*  input boolean Srv_bRcStart_ModeSTTFactReq;                                */
/*  input uint8 Srv_stRcEnd_ModeSTTFactReq;                                   */
/*  input boolean Srv_bRcCondOk_ModeSTTFactReq;                               */
/*  input boolean Srv_bRcCom_ModeSTTFactReq;                                  */
/*  input boolean Srv_bRcCdnOk_ModeSTTFactReq;                                */
/*  input boolean Srv_bRcCdnNok_ModeSTTFactReq;                               */
/*  input boolean Srv_bRcReq_ModeSTTFactReq;                                  */
/*  input boolean Srv_bRcStop_ModeSTTFactReq;                                 */
/*  input ???? DCM_MANU_RcAcv_ModeSTTFactReq;                                 */
/*  input ???? DCM_MANU_CheckCond4ModeSTTFactReq;                             */
/*  input ???? DCM_MANU_CheckRcCdn_ModeSTTFactReq;                            */
/*  output uint8 DCM_MANU_Cntrl_ModeSTT;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFC7
(
   uint8 Cntrl_ModeSTT,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( 0x00 == Cntrl_ModeSTT ) ||
          ( 0x01 == Cntrl_ModeSTT ) ||
          ( 0x02 == Cntrl_ModeSTT ))
      {
         u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                     &u8LocalErrorCode );

         if( E_OK == u8LocalReturn )
         {
            DCM_MANU_Cntrl_ModeSTT = Cntrl_ModeSTT;
            u8LocalReturn =
               DCM_MANU_StartRoutineDmnd( &Srv_stRc_ModeSTTFactReq,
                                          &Srv_bRcStart_ModeSTTFactReq,
                                          &Srv_stRcEnd_ModeSTTFactReq,
                                          &Srv_bRcCondOk_ModeSTTFactReq,
                                          /* Srv_bRcSho_RstStaCnt */
                                          FALSE,
                                          &Srv_bRcCom_ModeSTTFactReq,
                                          &Srv_bRcCdnOk_ModeSTTFactReq,
                                          &Srv_bRcCdnNok_ModeSTTFactReq,
                                          &Srv_bRcReq_ModeSTTFactReq,
                                          &Srv_bRcStop_ModeSTTFactReq,
                                          &u8LocalErrorCode,
                                          &u8LocalRoutineStatus,
                                          DCM_MANU_RcAcv_ModeSTTFactReq,
                                          DCM_MANU_CheckCond4ModeSTTFactReq,
                                          DCM_MANU_CheckRcCdn_ModeSTTFactReq );
         }
         else
         {
            /* Les conditions ADC ne sont pas bonnes */
            u8LocalRoutineStatus = 0x00;
         }
      }
      else
      {
         u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0x00;
         /* On utilise pas u8LocalOutputParam dans les start routines */
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFC8                                     */
/* !Description :  Is called from Dcm when RID DFC8 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.19                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_ModeSTTAftsReq;                                      */
/*  input boolean Srv_bRcStart_ModeSTTAftsReq;                                */
/*  input uint8 Srv_stRcEnd_ModeSTTAftsReq;                                   */
/*  input boolean Srv_bRcCondOk_ModeSTTAftsReq;                               */
/*  input boolean Srv_bRcCom_ModeSTTAftsReq;                                  */
/*  input boolean Srv_bRcCdnOk_ModeSTTAftsReq;                                */
/*  input boolean Srv_bRcCdnNok_ModeSTTAftsReq;                               */
/*  input boolean Srv_bRcReq_ModeSTTAftsReq;                                  */
/*  input boolean Srv_bRcStop_ModeSTTAftsReq;                                 */
/*  input ???? DCM_MANU_RcAcv_ModeSTTAftsReq;                                 */
/*  input ???? DCM_MANU_CheckCond4ModeSTTAftsReq;                             */
/*  input ???? DCM_MANU_CheckRcCdn_ModeSTTAftsReq;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DFC8
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         u8LocalReturn =
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_ModeSTTAftsReq,
                                       &Srv_bRcStart_ModeSTTAftsReq,
                                       &Srv_stRcEnd_ModeSTTAftsReq,
                                       &Srv_bRcCondOk_ModeSTTAftsReq,
                                       /* Srv_bRcSho_ModeSTTAftsReq */
                                       FALSE,
                                       &Srv_bRcCom_ModeSTTAftsReq,
                                       &Srv_bRcCdnOk_ModeSTTAftsReq,
                                       &Srv_bRcCdnNok_ModeSTTAftsReq,
                                       &Srv_bRcReq_ModeSTTAftsReq,
                                       &Srv_bRcStop_ModeSTTAftsReq,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_ModeSTTAftsReq,
                                       DCM_MANU_CheckCond4ModeSTTAftsReq,
                                       DCM_MANU_CheckRcCdn_ModeSTTAftsReq );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0x00;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DFC8                                      */
/* !Description :  Is called from Dcm when RID DFC8 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API6.20                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_ModeSTTAftsReq;                                      */
/*  input boolean Srv_bRcStart_ModeSTTAftsReq;                                */
/*  input uint8 Srv_stRcEnd_ModeSTTAftsReq;                                   */
/*  input boolean Srv_bRcCondOk_ModeSTTAftsReq;                               */
/*  input boolean Srv_bRcCom_ModeSTTAftsReq;                                  */
/*  input boolean Srv_bRcCdnOk_ModeSTTAftsReq;                                */
/*  input boolean Srv_bRcCdnNok_ModeSTTAftsReq;                               */
/*  input boolean Srv_bRcReq_ModeSTTAftsReq;                                  */
/*  input boolean Srv_bRcStop_ModeSTTAftsReq;                                 */
/*  input ???? DCM_MANU_RcAcv_ModeSTTAftsReq;                                 */
/*  input ???? DCM_MANU_CheckCond4ModeSTTAftsReq;                             */
/*  input ???? DCM_MANU_CheckRcCdn_ModeSTTAftsReq;                            */
/*  output uint8 DCM_MANU_Cntrl_ModeSTT;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFC8
(
   uint8 Cntrl_ModeSTT,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( 0x00 == Cntrl_ModeSTT ) ||
          ( 0x01 == Cntrl_ModeSTT ))
      {
         u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                     &u8LocalErrorCode );

         if( E_OK == u8LocalReturn )
         {
            DCM_MANU_Cntrl_ModeSTT = Cntrl_ModeSTT;
            u8LocalReturn =
               DCM_MANU_StartRoutineDmnd( &Srv_stRc_ModeSTTAftsReq,
                                          &Srv_bRcStart_ModeSTTAftsReq,
                                          &Srv_stRcEnd_ModeSTTAftsReq,
                                          &Srv_bRcCondOk_ModeSTTAftsReq,
                                          /* Srv_bRcSho_ModeSTTAftsReq */
                                          FALSE,
                                          &Srv_bRcCom_ModeSTTAftsReq,
                                          &Srv_bRcCdnOk_ModeSTTAftsReq,
                                          &Srv_bRcCdnNok_ModeSTTAftsReq,
                                          &Srv_bRcReq_ModeSTTAftsReq,
                                          &Srv_bRcStop_ModeSTTAftsReq,
                                          &u8LocalErrorCode,
                                          &u8LocalRoutineStatus,
                                          DCM_MANU_RcAcv_ModeSTTAftsReq,
                                          DCM_MANU_CheckCond4ModeSTTAftsReq,
                                          DCM_MANU_CheckRcCdn_ModeSTTAftsReq );
         }
         else
         {
            /* Les conditions ADC ne sont pas bonnes */
            u8LocalRoutineStatus = 0x00;
         }
      }
      else
      {
         u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0x00;
         /* On utilise pas u8LocalOutputParam dans les start routines */
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;

   return u8LocalReturn;
}



















