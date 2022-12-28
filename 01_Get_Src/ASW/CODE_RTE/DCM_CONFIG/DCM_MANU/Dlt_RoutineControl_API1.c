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
/* !File            : Dlt_RoutineControl_API1.c                               */
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
/*   1 / DLT_RequestResult_DFD2                                               */
/*   2 / DLT_StartRoutine_DFD2                                                */
/*   3 / DLT_StopRoutine_DFD2                                                 */
/*   4 / DLT_RequestResult_DFDE                                               */
/*   5 / DLT_StartRoutine_DFDE                                                */
/*   6 / DLT_StopRoutine_DFDE                                                 */
/*   7 / DLT_RequestResult_DFDF                                               */
/*   8 / DLT_StartRoutine_DFDF                                                */
/*   9 / DLT_StopRoutine_DFDF                                                 */
/*   10 / DLT_RequestResult_DFE1                                              */
/*   11 / DLT_StartRoutine_DFE1                                               */
/*   12 / DLT_StopRoutine_DFE1                                                */
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


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFD2                                     */
/* !Description :  Is called from Dcm when RID DFD2 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.1                                                  */
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
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFD2
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
                              ( CODE_TEST_FUPMP,
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
/* !Function    :  DLT_StartRoutine_DFD2                                      */
/* !Description :  Is called from Dcm when RID DFD2 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.2                                                  */
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
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFD2
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
                              ( CODE_TEST_FUPMP,
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
/* !Function    :  DLT_StopRoutine_DFD2                                       */
/* !Description :  Is called from Dcm when RID DFD2 service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.3                                                  */
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
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DFD2
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
                           ( CODE_TEST_FUPMP,
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
/* !Function    :  DLT_RequestResult_DFDE                                     */
/* !Description :  Is called from Dcm when RID DFDE service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.4                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestVVT_prev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFDE
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
                                          ( DCM_MANU_CodeTestVVT_prev,
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
/* !Function    :  DLT_StartRoutine_DFDE                                      */
/* !Description :  Is called from Dcm when RID DFDE service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.5                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestVVT_prev;                                    */
/*  output uint8 DCM_MANU_CodeTestVVT_prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFDE
(
   uint8* Choix_Actionneur,
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
      /* *currentDataLength nous informe de la taille
      du dernier input param en bits */
      if( 8 == *currentDataLength )
      {
         if( ( *Choix_Actionneur > -1 ) &&
             ( *Choix_Actionneur < 2 ) )
         {
            if( 0x00 == *Choix_Actionneur )
            {
               DCM_MANU_CodeTestVVT_prev = CODE_TEST_VVT_ADM;
            }
            else /* 0x01 == *Choix_Actionneur */
            {
               DCM_MANU_CodeTestVVT_prev = CODE_TEST_VVT_ECH;
            }

            u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                                                   ( DCM_MANU_CodeTestVVT_prev,
                                                     &u8LocalRoutineStatus,
                                                     &u16LocalCurrentDataLgth,
                                                     &u8LocalErrorCode );
         }
         else
         {
            /* RoutineOptionRecord Incorrect */
            u8LocalReturn = E_NOT_OK;
            u8LocalRoutineStatus = 0x00;
            u16LocalCurrentDataLgth = 0;
            u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
         }
      }
      else
      {
         /* Taille du parametre incorrect */
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0x00;
         u16LocalCurrentDataLgth = 0;
         u8LocalErrorCode = DCM_E_INCORRECTLENGTH;
      }
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
/* !Function    :  DLT_StopRoutine_DFDE                                       */
/* !Description :  Is called from Dcm when RID DFDE service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.6                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestVVT_prev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DFDE
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
                           ( DCM_MANU_CodeTestVVT_prev,
                             &u8LocalRoutineStatus,
                             &u16LocalCurrentDataLgth,
                             &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0;
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
/* !Function    :  DLT_RequestResult_DFDF                                     */
/* !Description :  Is called from Dcm when RID DFDF service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.7                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestBobine_prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFDF
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
                              ( DCM_MANU_CodeTestBobine_prev,
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
      u16LocalCurrentDataLgth = 0x0000;
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
/* !Function    :  DLT_StartRoutine_DFDF                                      */
/* !Description :  Is called from Dcm when RID DFDF service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.8                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestBobine_prev;                                 */
/*  output uint8 DCM_MANU_CodeTestBobine_prev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFDF
(
   uint8* Choix_Bobinne,
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
      /* *currentDataLength nous informe de la taille
      du dernier input param en bits */
      if( 8 == *currentDataLength )
      {
         if( ( *Choix_Bobinne >= 1 ) &&
             ( *Choix_Bobinne < 4  ) )
         {
            if( 0x01 == *Choix_Bobinne )
            {
               DCM_MANU_CodeTestBobine_prev = CODE_TEST_BOBINE_1;
            }
            else if( 0x02 == *Choix_Bobinne )
            {
               DCM_MANU_CodeTestBobine_prev = CODE_TEST_BOBINE_2;
            }
            else /* 0x03 == *Choix_Bobinne */
            {
               DCM_MANU_CodeTestBobine_prev = CODE_TEST_BOBINE_3;
            }

            u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                                                ( DCM_MANU_CodeTestBobine_prev,
                                                  &u8LocalRoutineStatus,
                                                  &u16LocalCurrentDataLgth,
                                                  &u8LocalErrorCode );
         }
         else
         {
            /* RoutineOptionRecord Incorrect */
            u8LocalReturn = E_NOT_OK;
            u8LocalRoutineStatus = 0x00;
            u16LocalCurrentDataLgth = 0x0000;
            u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
         }
      }
      else
      {
         /* Taille du parametre incorrect */
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0x00;
         u16LocalCurrentDataLgth = 0x0000;
         u8LocalErrorCode = DCM_E_INCORRECTLENGTH;
      }
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0x0000;
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
/* !Function    :  DLT_StopRoutine_DFDF                                       */
/* !Description :  Is called from Dcm when RID DFDF service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.9                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestBobine_prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DFDF
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
                           ( DCM_MANU_CodeTestBobine_prev,
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
      u16LocalCurrentDataLgth = 0x0000;
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
/* !Function    :  DLT_RequestResult_DFE1                                     */
/* !Description :  Is called from Dcm when RID DFE1 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.10                                                 */
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
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFE1
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
                              ( CODE_TEST_OILPMP,
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
      u16LocalCurrentDataLgth = 0x0000;
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
/* !Function    :  DLT_StartRoutine_DFE1                                      */
/* !Description :  Is called from Dcm when RID DFE1 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.11                                                 */
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
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFE1
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
                                             ( CODE_TEST_OILPMP,
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
      u16LocalCurrentDataLgth = 0x0000;
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
/* !Function    :  DLT_StopRoutine_DFE1                                       */
/* !Description :  Is called from Dcm when RID DFE1 service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API1.12                                                 */
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
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DFE1
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
                           ( CODE_TEST_OILPMP,
                             &u8LocalRoutineStatus,
                             &u16LocalCurrentDataLgth,
                             &u8LocalErrorCode );
   }
   else
   {
      /* Si nous sommes appelé avec un paramêtre différent,
      c'est qu'il y a un problème */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0;
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