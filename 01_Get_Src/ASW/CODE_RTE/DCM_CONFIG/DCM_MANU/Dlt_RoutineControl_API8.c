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
/* !File            : Dlt_RoutineControl_API8.c                               */
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
/*   1 / DLT_StartRoutine_DF33                                                */
/*   2 / DLT_RequestResult_DF33                                               */
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
/* !Function    :  DLT_StartRoutine_DF33                                      */
/* !Description :  Is called from Dcm when RID service sub function 01 is     */
/*                 received.                                                  */
/* !Number      :  RC_API9.1                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstPed;                                              */
/*  input boolean Srv_bRcStart_RstPed;                                        */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input boolean Srv_bRcCondOk_RstPed;                                       */
/*  input boolean Srv_bRcCom_RstPed;                                          */
/*  input boolean Srv_bRcCdnOk_RstPed;                                        */
/*  input boolean Srv_bRcCdnNok_RstPed;                                       */
/*  input boolean Srv_bRcReq_RstPed;                                          */
/*  input boolean Srv_bRcStop_RstPed;                                         */
/*  input ???? DCM_MANU_RcAcv_RstPed;                                         */
/*  input ???? DCM_MANU_CheckCond4RstPed;                                     */
/*  input ???? DCM_MANU_RcCdn_RstPed;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF33
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstPed,
                              &Srv_bRcStart_RstPed,
                  &Srv_stRcEnd_RstPed,
                  &Srv_bRcCondOk_RstPed,
                  /* Srv_bRcSho_IniRealTiTroCnt */
                  FALSE,
                  &Srv_bRcCom_RstPed,
                  &Srv_bRcCdnOk_RstPed,
                  &Srv_bRcCdnNok_RstPed,
                  &Srv_bRcReq_RstPed,
                  &Srv_bRcStop_RstPed,
                  &u8LocalErrorCode,
                  &u8LocalRoutineStatus,
                  DCM_MANU_RcAcv_RstPed,
                  DCM_MANU_CheckCond4RstPed,
                  DCM_MANU_RcCdn_RstPed);
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
   *State_Routine= u8LocalRoutineStatus;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DF33                                     */
/* !Description :  Is called from Dcm when RID service sub function 03 is     */
/*                 received.                                                  */
/* !Number      :  RC_API9.2                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstPed;                                              */
/*  input boolean Srv_bRcStart_RstPed;                                        */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input boolean Srv_bRcCondOk_RstPed;                                       */
/*  input boolean Srv_bRcCom_RstPed;                                          */
/*  input boolean Srv_bRcCdnOk_RstPed;                                        */
/*  input boolean Srv_bRcCdnNok_RstPed;                                       */
/*  input boolean Srv_bRcReq_RstPed;                                          */
/*  input boolean Srv_bRcStop_RstPed;                                         */
/*  input ???? DCM_MANU_RcAcv_RstPed;                                         */
/*  input ???? DCM_MANU_CheckCond4RstPed;                                     */
/*  input ???? DCM_MANU_RcCdn_RstPed;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF33
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstPed,
                              &Srv_bRcStart_RstPed,
                  &Srv_stRcEnd_RstPed,
                  &Srv_bRcCondOk_RstPed,
                  /* Srv_bRcSho_IniRealTiTroCnt */
                  FALSE,
                  &Srv_bRcCom_RstPed,
                  &Srv_bRcCdnOk_RstPed,
                  &Srv_bRcCdnNok_RstPed,
                  &Srv_bRcReq_RstPed,
                  &Srv_bRcStop_RstPed,
                  &u8LocalErrorCode,
                  &u8LocalRoutineStatus,
                  DCM_MANU_RcAcv_RstPed,
                  DCM_MANU_CheckCond4RstPed,
                  DCM_MANU_RcCdn_RstPed);
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
   *State_Routine= u8LocalRoutineStatus;

   return u8LocalReturn;
}

