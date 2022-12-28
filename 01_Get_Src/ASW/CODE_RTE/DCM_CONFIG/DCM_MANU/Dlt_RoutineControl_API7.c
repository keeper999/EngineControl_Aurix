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
/* !File            : Dlt_RoutineControl_API7.c                               */
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
/*   1 / DLT_StartRoutine_DFCC                                                */
/*   2 / DLT_StopRoutine_DFCC                                                 */
/*   3 / DLT_RequestResult_DFCC                                               */
/*   4 / DLT_StartRoutine_DFEB                                                */
/*   5 / DLT_StopRoutine_DFEB                                                 */
/*   6 / DLT_RequestResult_DFEB                                               */
/*   7 / DLT_StartRoutine_DFDB                                                */
/*   8 / DLT_StopRoutine_DFDB                                                 */
/*   9 / DLT_RequestResult_DFDB                                               */
/*   10 / DLT_StartRoutine_DFDA                                               */
/*   11 / DLT_StopRoutine_DFDA                                                */
/*   12 / DLT_RequestResult_DFDA                                              */
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
/* !Function    :  DLT_StartRoutine_DFCC                                      */
/* !Description :  Is called from Dcm when RID DFCC service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.1                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFCC
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                              ( CODE_TEST_MEAP,
                                &u8LocalRoutineStatus,
                                &u16LocalCurrentDataLgth,
                                &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StopRoutine_DFCC                                       */
/* !Description :  Is called from Dcm when RID DFCC service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.2                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StopRoutine_DFCC
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt
                           ( CODE_TEST_MEAP,
                             &u8LocalRoutineStatus,
                             &u16LocalCurrentDataLgth,
                             &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFCC                                     */
/* !Description :  Is called from Dcm when RID DFCC service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.3                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DFCC
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Param_Supl,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt
                                          ( CODE_TEST_MEAP,
                                            &u8LocalRoutineStatus,
                                            &u8LocalOutputParam,
                                            &u16LocalCurrentDataLgth,
                                            &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalOutputParam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *Param_Supl = u8LocalOutputParam;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DFEB                                      */
/* !Description :  Is called from Dcm when RID DFEB service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.4                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFEB
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                              ( CODE_TEST_CTP,
                                &u8LocalRoutineStatus,
                                &u16LocalCurrentDataLgth,
                                &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StopRoutine_DFEB                                       */
/* !Description :  Is called from Dcm when RID DFEB service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.5                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StopRoutine_DFEB
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt
                           ( CODE_TEST_CTP,
                             &u8LocalRoutineStatus,
                             &u16LocalCurrentDataLgth,
                             &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFEB                                     */
/* !Description :  Is called from Dcm when RID DFEB service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.6                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DFEB
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Param_Supl,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt
                                          ( CODE_TEST_CTP,
                                            &u8LocalRoutineStatus,
                                            &u8LocalOutputParam,
                                            &u16LocalCurrentDataLgth,
                                            &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalOutputParam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *Param_Supl = u8LocalOutputParam;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DFDB                                      */
/* !Description :  Is called from Dcm when RID DFDB service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.7                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFDB
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                              ( CODE_TEST_FARSP,
                                &u8LocalRoutineStatus,
                                &u16LocalCurrentDataLgth,
                                &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StopRoutine_DFDB                                       */
/* !Description :  Is called from Dcm when RID DFDB service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.8                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StopRoutine_DFDB
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt
                           ( CODE_TEST_FARSP,
                             &u8LocalRoutineStatus,
                             &u16LocalCurrentDataLgth,
                             &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFDB                                     */
/* !Description :  Is called from Dcm when RID DFDB service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.9                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DFDB
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Param_Supl,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt
                                          ( CODE_TEST_FARSP,
                                            &u8LocalRoutineStatus,
                                            &u8LocalOutputParam,
                                            &u16LocalCurrentDataLgth,
                                            &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalOutputParam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *Param_Supl = u8LocalOutputParam;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DFDA                                      */
/* !Description :  Is called from Dcm when RID DFDA service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.10                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFDA
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                              ( CODE_TEST_DUMPVALVE,
                                &u8LocalRoutineStatus,
                                &u16LocalCurrentDataLgth,
                                &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StopRoutine_DFDA                                       */
/* !Description :  Is called from Dcm when RID DFDA service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.11                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StopRoutine_DFDA
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt
                           ( CODE_TEST_DUMPVALVE,
                             &u8LocalRoutineStatus,
                             &u16LocalCurrentDataLgth,
                             &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFDA                                     */
/* !Description :  Is called from Dcm when RID DFDA service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API7.12                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DFDA
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Param_Supl,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt
                                          ( CODE_TEST_DUMPVALVE,
                                            &u8LocalRoutineStatus,
                                            &u8LocalOutputParam,
                                            &u16LocalCurrentDataLgth,
                                            &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalOutputParam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }

   *ErrorCode = u8LocalErrorCode;
   *Param_Supl = u8LocalOutputParam;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}
