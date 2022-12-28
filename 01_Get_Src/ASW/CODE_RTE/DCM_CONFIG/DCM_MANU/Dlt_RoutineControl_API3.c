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
/* !File            : Dlt_RoutineControl_API3.c                               */
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
/*   1 / DLT_RequestResult_DFEA                                               */
/*   2 / DLT_StartRoutine_DFEA                                                */
/*   3 / DLT_StopRoutine_DFEA                                                 */
/*   4 / DLT_RequestResult_DFEC                                               */
/*   5 / DLT_StartRoutine_DFEC                                                */
/*   6 / DLT_StopRoutine_DFEC                                                 */
/*   7 / DLT_RequestResult_DFED                                               */
/*   8 / DLT_StartRoutine_DFED                                                */
/*   9 / DLT_StopRoutine_DFED                                                 */
/*   10 / DLT_RequestResult_DFEE                                              */
/*   11 / DLT_StartRoutine_DFEE                                               */
/*   12 / DLT_StopRoutine_DFEE                                                */
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
/* !Function    :  DLT_RequestResult_DFEA                                     */
/* !Description :  Is called from Dcm when RID DFEA service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.1                                                  */
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
Std_ReturnType DLT_RequestResult_DFEA
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
                              ( CODE_TEST_WTRPMP,
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
      u8LocalOutputParam = 0;
      u8LocalRoutineStatus = 0;
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
/* !Function    :  DLT_StartRoutine_DFEA                                      */
/* !Description :  Is called from Dcm when RID DFEA service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.2                                                  */
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
Std_ReturnType DLT_StartRoutine_DFEA
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
                           ( CODE_TEST_WTRPMP,
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
/* !Function    :  DLT_StopRoutine_DFEA                                       */
/* !Description :  Is called from Dcm when RID DFEA service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.3                                                  */
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
Std_ReturnType DLT_StopRoutine_DFEA
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
                           ( CODE_TEST_WTRPMP,
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
/* !Function    :  DLT_RequestResult_DFEC                                     */
/* !Description :  Is called from Dcm when RID DFEC service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.4                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixVites_prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFEC
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
                              ( DCM_MANU_CodeTestChoixVites_prev,
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
/* !Function    :  DLT_StartRoutine_DFEC                                      */
/* !Description :  Is called from Dcm when RID DFEC service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.5                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixVites_prev;                             */
/*  output uint8 DCM_MANU_CodeTestChoixVites_prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFEC
(
   uint8* Choix_Vitesse,
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
      /* Test de la taille du parametre d'entrée en bits */
      if( 8 == *currentDataLength )
      {
         if( *Choix_Vitesse < 2 )
         {
            if( 0x00 == *Choix_Vitesse )
            {
               DCM_MANU_CodeTestChoixVites_prev = CODE_TEST_B2FANLOSPD;
            }
            else /* 0x01 == *Choix_Vitesse */
            {
               DCM_MANU_CodeTestChoixVites_prev = CODE_TEST_B2FANHISPD;
            }

            u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                                    ( DCM_MANU_CodeTestChoixVites_prev,
                                      &u8LocalRoutineStatus,
                                      &u16LocalCurrentDataLgth,
                                      &u8LocalErrorCode );
         }
         else
         {
            /* RoutineOptionRecord Incorrect */
            u8LocalReturn = E_NOT_OK;
            u8LocalRoutineStatus = 0;
            u16LocalCurrentDataLgth = 0;
            u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
         }
      }
      else
      {
         /* RoutineOptionRecord de taille Incorrect */
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0;
         u16LocalCurrentDataLgth = 0;
         u8LocalErrorCode = DCM_E_INCORRECTLENGTH;
      }
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
/* !Function    :  DLT_StopRoutine_DFEC                                       */
/* !Description :  Is called from Dcm when RID DFEC service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.6                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixVites_prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DFEC
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
                           ( DCM_MANU_CodeTestChoixVites_prev,
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
/* !Function    :  DLT_RequestResult_DFED                                     */
/* !Description :  Is called from Dcm when RID DFED service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.7                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixCyl_prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFED
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
                              ( DCM_MANU_CodeTestChoixCyl_prev,
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
      u8LocalOutputParam = 0;
      u8LocalRoutineStatus = 0;
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
/* !Function    :  DLT_StartRoutine_DFED                                      */
/* !Description :  Is called from Dcm when RID DFED service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.8                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixCyl_prev;                               */
/*  output uint8 DCM_MANU_CodeTestChoixCyl_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFED
(
   uint8* Choix_Cylindre,
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
      /* Test de la taille du parametre d'entrée en bits */
      if( 8 == *currentDataLength )
      {
         if( ( *Choix_Cylindre > 0 ) &&
             ( *Choix_Cylindre < 4 ) )
         {
            if( 0x01 == *Choix_Cylindre )
            {
               DCM_MANU_CodeTestChoixCyl_prev = CODE_TEST_INJECTEUR_1;
            }
            else if( 0x02 == *Choix_Cylindre )
            {
               DCM_MANU_CodeTestChoixCyl_prev = CODE_TEST_INJECTEUR_2;
            }
            else /* 0x03 == Choix_Cylindre */
            {
               DCM_MANU_CodeTestChoixCyl_prev = CODE_TEST_INJECTEUR_3;
            }

            u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                                    ( DCM_MANU_CodeTestChoixCyl_prev,
                                      &u8LocalRoutineStatus,
                                      &u16LocalCurrentDataLgth,
                                      &u8LocalErrorCode );
         }
         else
         {
            /* RoutineOptionRecord Incorrect */
            u8LocalReturn = E_NOT_OK;
            u8LocalRoutineStatus = 0;
            u16LocalCurrentDataLgth = 0;
            u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
         }
      }
      else
      {
         /* RoutineOptionRecord de taille Incorrect */
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0;
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
/* !Function    :  DLT_StopRoutine_DFED                                       */
/* !Description :  Is called from Dcm when RID DFED service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.9                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixCyl_prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DFED
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
                           ( DCM_MANU_CodeTestChoixCyl_prev,
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
/* !Function    :  DLT_RequestResult_DFEE                                     */
/* !Description :  Is called from Dcm when RID DFEE service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.10                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(argin uint8 code_test,     */
/*  argout uint8 *routine_status, argout uint8 *output_param, argout uint16   */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixSonde_prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFEE
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
                              ( DCM_MANU_CodeTestChoixSonde_prev,
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
      u8LocalOutputParam = 0;
      u8LocalRoutineStatus = 0;
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
/* !Function    :  DLT_StartRoutine_DFEE                                      */
/* !Description :  Is called from Dcm when RID DFEE service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.11                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(argin  */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixSonde_prev;                             */
/*  output uint8 DCM_MANU_CodeTestChoixSonde_prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFEE
(
   uint8* Choix_Sonde,
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
      /* Test de la taille du parametre d'entrée en bits */
      if( 8 == *currentDataLength )
      {
         if( ( *Choix_Sonde > -1 ) &&
             ( *Choix_Sonde < 2 ) )
         {
            if( 0x00 == *Choix_Sonde )
            {
               DCM_MANU_CodeTestChoixSonde_prev = CODE_TEST_SO2_AM;
            }
            else /* 0x01 == *Choix_Sonde */
            {
               DCM_MANU_CodeTestChoixSonde_prev = CODE_TEST_SO2_AV;
            }

            u8LocalReturn = DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
                                    ( DCM_MANU_CodeTestChoixSonde_prev,
                                      &u8LocalRoutineStatus,
                                      &u16LocalCurrentDataLgth,
                                      &u8LocalErrorCode );
         }
         else
         {
            /* RoutineOptionRecord Incorrect */
            u8LocalReturn = E_NOT_OK;
            u8LocalRoutineStatus = 0;
            u16LocalCurrentDataLgth = 0;
            u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
         }
      }
      else
      {
         /* RoutineOptionRecord de taille Incorrect */
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0;
         u16LocalCurrentDataLgth = 0;
         u8LocalErrorCode = DCM_E_INCORRECTLENGTH;
      }
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
/* !Function    :  DLT_StopRoutine_DFEE                                       */
/* !Description :  Is called from Dcm when RID DFEE service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API3.12                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(argin   */
/*  uint8 code_test, argout uint8 *routine_status, argout uint16              */
/*  *last_param_lgth, argout Dcm_NegativeResponseCodeType *ErrorCode);        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_CodeTestChoixSonde_prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DFEE
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
                           ( DCM_MANU_CodeTestChoixSonde_prev,
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