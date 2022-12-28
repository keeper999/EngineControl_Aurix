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
/* !File            : Dlt_RoutineControl_API4.c                               */
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
/*   1 / DLT_RequestResult_DFEF                                               */
/*   2 / DLT_StartRoutine_DFEF                                                */
/*   3 / DLT_StopRoutine_DFEF                                                 */
/*   4 / DLT_RequestResult_0302                                               */
/*   5 / DLT_StartRoutine_0302                                                */
/*   6 / DLT_RequestResult_DFAD                                               */
/*   7 / DLT_StartRoutine_DFAD                                                */
/*   8 / DLT_RequestResult_DFDD                                               */
/*   9 / DLT_StartRoutine_DFDD                                                */
/*   10 / DLT_StopRoutine_DFDD                                                */
/*   11 / DLT_StartRoutine_0400                                               */
/*   12 / DLT_StartRoutine_DFA0                                               */
/*   13 / DLT_StartRoutine_DFAC                                               */
/*   14 / DLT_RequestResult_0400                                              */
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

#include "VEMS.H"
#include "STD_TYPES.h"
#include "Dlt.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFEF                                     */
/* !Description :  Is called from Dcm when RID DFEF service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.1                                                  */
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
Std_ReturnType DLT_RequestResult_DFEF
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
                                 ( CODE_TEST_RELAIS_PUISSANCE,
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
/* !Function    :  DLT_StartRoutine_DFEF                                      */
/* !Description :  Is called from Dcm when RID DFEF service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.2                                                  */
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
Std_ReturnType DLT_StartRoutine_DFEF
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
                              ( CODE_TEST_RELAIS_PUISSANCE,
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
/* !Function    :  DLT_StopRoutine_DFEF                                       */
/* !Description :  Is called from Dcm when RID DFEF service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.3                                                  */
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
Std_ReturnType DLT_StopRoutine_DFEF
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
                           ( CODE_TEST_RELAIS_PUISSANCE,
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
/* !Function    :  DLT_RequestResult_0302                                     */
/* !Description :  Is called from Dcm when RID 0302 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.4                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_IniRealTiTroCnt;                                     */
/*  input boolean Srv_bRcStart_IniRealTiTroCnt;                               */
/*  input uint8 Srv_stRcEnd_IniRealTiTroCnt;                                  */
/*  input boolean Srv_bRcCondOk_IniRealTiTroCnt;                              */
/*  input boolean Srv_bRcCom_IniRealTiTroCnt;                                 */
/*  input boolean Srv_bRcCdnOk_IniRealTiTroCnt;                               */
/*  input boolean Srv_bRcCdnNok_IniRealTiTroCnt;                              */
/*  input boolean Srv_bRcReq_IniRealTiTroCnt;                                 */
/*  input boolean Srv_bRcStop_IniRealTiTroCnt;                                */
/*  input ???? DCM_MANU_RcAcv_IniRealTiTroCnt;                                */
/*  input ???? DCM_MANU_CheckCond4IniRealTiTroCnt;                            */
/*  input ???? DCM_MANU_RcCdn_IniRealTiTroCnt;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_0302
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_IniRealTiTroCnt,
                                        &Srv_bRcStart_IniRealTiTroCnt,
                                        &Srv_stRcEnd_IniRealTiTroCnt,
                                        &Srv_bRcCondOk_IniRealTiTroCnt,
                                        /* Srv_bRcSho_IniRealTiTroCnt */
                                        FALSE,
                                        &Srv_bRcCom_IniRealTiTroCnt,
                                        &Srv_bRcCdnOk_IniRealTiTroCnt,
                                        &Srv_bRcCdnNok_IniRealTiTroCnt,
                                        &Srv_bRcReq_IniRealTiTroCnt,
                                        &Srv_bRcStop_IniRealTiTroCnt,
                                        &u8LocalErrorCode,
                                        &u8LocalRoutineStatus,
                                        DCM_MANU_RcAcv_IniRealTiTroCnt,
                                        DCM_MANU_CheckCond4IniRealTiTroCnt,
                                        DCM_MANU_RcCdn_IniRealTiTroCnt);
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
/* !Function    :  DLT_StartRoutine_0302                                      */
/* !Description :  Is called from Dcm when RID 0302 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.5                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_IniRealTiTroCnt;                                     */
/*  input boolean Srv_bRcStart_IniRealTiTroCnt;                               */
/*  input uint8 Srv_stRcEnd_IniRealTiTroCnt;                                  */
/*  input boolean Srv_bRcCondOk_IniRealTiTroCnt;                              */
/*  input boolean Srv_bRcCom_IniRealTiTroCnt;                                 */
/*  input boolean Srv_bRcCdnOk_IniRealTiTroCnt;                               */
/*  input boolean Srv_bRcCdnNok_IniRealTiTroCnt;                              */
/*  input boolean Srv_bRcReq_IniRealTiTroCnt;                                 */
/*  input boolean Srv_bRcStop_IniRealTiTroCnt;                                */
/*  input ???? DCM_MANU_RcAcv_IniRealTiTroCnt;                                */
/*  input ???? DCM_MANU_CheckCond4IniRealTiTroCnt;                            */
/*  input ???? DCM_MANU_RcCdn_IniRealTiTroCnt;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_StartRoutine_0302                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_0302
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_IniRealTiTroCnt,
                                       &Srv_bRcStart_IniRealTiTroCnt,
                                       &Srv_stRcEnd_IniRealTiTroCnt,
                                       &Srv_bRcCondOk_IniRealTiTroCnt,
                                       /* Srv_bRcSho_IniRealTiTroCnt */
                                       FALSE,
                                       &Srv_bRcCom_IniRealTiTroCnt,
                                       &Srv_bRcCdnOk_IniRealTiTroCnt,
                                       &Srv_bRcCdnNok_IniRealTiTroCnt,
                                       &Srv_bRcReq_IniRealTiTroCnt,
                                       &Srv_bRcStop_IniRealTiTroCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_IniRealTiTroCnt,
                                       DCM_MANU_CheckCond4IniRealTiTroCnt,
                                       DCM_MANU_RcCdn_IniRealTiTroCnt );
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
/* !Function    :  DLT_RequestResult_DFAD                                     */
/* !Description :  Is called from Dcm when RID DFAD service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.6                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Srv_EveRcMatch();                                        */
/*  extf argret Std_ReturnType  DCM_MANU_Matching_Result_Analyse(argin uint8  */
/* *u8LocalRoutineStatus, argout uint8 *u8LocalErrorCode, argout uint8        */
/* *u8LocalOutputParam, argout uint16 *u16LocalCurrentDataLength);            */
/*  output uint8 DCM_MANU_Option_Appairage;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFAD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Problem_Value,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLength;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
		u8LocalReturn = E_OK;
      if( E_OK == u8LocalReturn )
      {
         VEMS_vidSET(DCM_MANU_Option_Appairage, 0x03);
         Srv_EveRcMatch();

         u8LocalReturn =
               DCM_MANU_Matching_Result_Analyse( &u8LocalRoutineStatus,
                                                 &u8LocalErrorCode,
                                                 &u8LocalOutputParam,
                                                 &u16LocalCurrentDataLength );
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalOutputParam = 0;
         u8LocalRoutineStatus = 0;
         u16LocalCurrentDataLength = 0;
      }
   }
   else if( DCM_PENDING == OpStatus )
   {
      u8LocalReturn =
            DCM_MANU_Matching_Result_Analyse( &u8LocalRoutineStatus,
                                              &u8LocalErrorCode,
                                              &u8LocalOutputParam,
                                              &u16LocalCurrentDataLength );
   }
   else /* DCM_CANCEL == OpStatus */
   {
      u8LocalErrorCode = 0x00;
      u8LocalReturn = E_OK;
      u8LocalOutputParam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLength = 0;
   }

   *ErrorCode = u8LocalErrorCode;
   *Problem_Value = u8LocalOutputParam;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLength;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DFAD                                      */
/* !Description :  Is called from Dcm when RID DFAD service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.7                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Srv_EveRcMatch();                                        */
/*  extf argret Std_ReturnType  DCM_MANU_Matching_Result_Analyse(argin uint8  */
/* *u8LocalRoutineStatus, argout uint8 *u8LocalErrorCode, argout uint8        */
/* *u8LocalOutputParam, argout uint16 *u16LocalCurrentDataLength);            */
/*  output uint8 DCM_MANU_Option_Appairage;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFAD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Problem_Value,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLength;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_MATCHING,
                                                  &u8LocalErrorCode );
      if( E_OK == u8LocalReturn )
      {
         VEMS_vidSET(DCM_MANU_Option_Appairage, 0x01);
         Srv_EveRcMatch();

         u8LocalReturn =
               DCM_MANU_Matching_Result_Analyse( &u8LocalRoutineStatus,
                                                 &u8LocalErrorCode,
                                                 &u8LocalOutputParam,
                                                 &u16LocalCurrentDataLength );
      }
      else
      {
         /* Les conditions ADCs ne sont pas bonnes */
         u8LocalOutputParam = 0x00;
         u8LocalRoutineStatus = 0x00;
         u16LocalCurrentDataLength = 0;
      }
   }
   else if( DCM_PENDING == OpStatus )
   {
      u8LocalReturn =
            DCM_MANU_Matching_Result_Analyse( &u8LocalRoutineStatus,
                                              &u8LocalErrorCode,
                                              &u8LocalOutputParam,
                                              &u16LocalCurrentDataLength );
   }
   else /* DCM_CANCEL == OpStatus */
   {
      u8LocalErrorCode = 0x00;
      u8LocalReturn = E_OK;
      u8LocalOutputParam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLength = 0;
   }

   *ErrorCode = u8LocalErrorCode;
   *Problem_Value = u8LocalOutputParam;
   *State_Routine = u8LocalRoutineStatus;
   *currentDataLength = u16LocalCurrentDataLength;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_DFDD                                     */
/* !Description :  Is called from Dcm when RID DFDD service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.8                                                  */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_stRc_AcvUnloadRail;                                       */
/*  input boolean Srv_bRcStart_AcvUnloadRail;                                 */
/*  input uint8 Srv_stRcEnd_AcvUnloadRail;                                    */
/*  input boolean Srv_bRcCondOk_AcvUnloadRail;                                */
/*  input boolean Srv_bRcCom_AcvUnloadRail;                                   */
/*  input boolean Srv_bRcCdnOk_AcvUnloadRail;                                 */
/*  input boolean Srv_bRcCdnNok_AcvUnloadRail;                                */
/*  input boolean Srv_bRcReq_AcvUnloadRail;                                   */
/*  input boolean Srv_bRcStop_AcvUnloadRail;                                  */
/*  input ???? DCM_MANU_RcAcv_AcvUnloadRail;                                  */
/*  input ???? DCM_MANU_CheckCond4AcvUnloadRail;                              */
/*  input ???? DCM_MANU_RcCdn_4AcvUnloadRail;                                 */
/*  input uint16 PFuAcq_pFuRailMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DFDD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Pression_Rail,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16Locallength;
   uint16                       u16LocalpFuRailMes;
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_AcvUnloadRail,
                                        &Srv_bRcStart_AcvUnloadRail,
                                        &Srv_stRcEnd_AcvUnloadRail,
                                        &Srv_bRcCondOk_AcvUnloadRail,
                                        /* Srv_bRcSho_AcvUnloadRail */
                                        FALSE,
                                        &Srv_bRcCom_AcvUnloadRail,
                                        &Srv_bRcCdnOk_AcvUnloadRail,
                                        &Srv_bRcCdnNok_AcvUnloadRail,
                                        &Srv_bRcReq_AcvUnloadRail,
                                        &Srv_bRcStop_AcvUnloadRail,
                                        &u8LocalErrorCode,
                                        &u8LocalRoutineStatus,
                                        DCM_MANU_RcAcv_AcvUnloadRail,
                                        DCM_MANU_CheckCond4AcvUnloadRail,
                                        DCM_MANU_RcCdn_4AcvUnloadRail );

         /* Taille du dernier output parameter (Pression_Rail) en bits */
         u16Locallength = 16;
         VEMS_vidGET(PFuAcq_pFuRailMes, u16LocalpFuRailMes);
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u16LocalpFuRailMes = 0x0000;
         u8LocalRoutineStatus = 0x00;
         u16Locallength = 0;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u16LocalpFuRailMes = 0x0000;
      u8LocalRoutineStatus = 0x00;
      u16Locallength = 0;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   Pression_Rail[0] = (uint8)((u16LocalpFuRailMes & 0xFF00) >> 8);
   Pression_Rail[1] = (uint8)(u16LocalpFuRailMes & 0x00FF);
   *State_Routine = u8LocalRoutineStatus;
   /* Taille en bits du dernier parametre (Pression_Rail) */
   *currentDataLength = u16Locallength;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DFDD                                      */
/* !Description :  Is called from Dcm when RID DFDD service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.9                                                  */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_stRc_AcvUnloadRail;                                       */
/*  input boolean Srv_bRcStart_AcvUnloadRail;                                 */
/*  input uint8 Srv_stRcEnd_AcvUnloadRail;                                    */
/*  input boolean Srv_bRcCondOk_AcvUnloadRail;                                */
/*  input boolean Srv_bRcCom_AcvUnloadRail;                                   */
/*  input boolean Srv_bRcCdnOk_AcvUnloadRail;                                 */
/*  input boolean Srv_bRcCdnNok_AcvUnloadRail;                                */
/*  input boolean Srv_bRcReq_AcvUnloadRail;                                   */
/*  input boolean Srv_bRcStop_AcvUnloadRail;                                  */
/*  input ???? DCM_MANU_RcAcv_AcvUnloadRail;                                  */
/*  input ???? DCM_MANU_CheckCond4AcvUnloadRail;                              */
/*  input ???? DCM_MANU_RcCdn_4AcvUnloadRail;                                 */
/*  input uint16 PFuAcq_pFuRailMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFDD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Pression_Rail,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16Locallength;
   uint16                       u16LocalpFuRailMes;
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_AcvUnloadRail,
                                       &Srv_bRcStart_AcvUnloadRail,
                                       &Srv_stRcEnd_AcvUnloadRail,
                                       &Srv_bRcCondOk_AcvUnloadRail,
                                       /* Srv_bRcSho_AcvUnloadRail */
                                       FALSE,
                                       &Srv_bRcCom_AcvUnloadRail,
                                       &Srv_bRcCdnOk_AcvUnloadRail,
                                       &Srv_bRcCdnNok_AcvUnloadRail,
                                       &Srv_bRcReq_AcvUnloadRail,
                                       &Srv_bRcStop_AcvUnloadRail,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_AcvUnloadRail,
                                       DCM_MANU_CheckCond4AcvUnloadRail,
                                       DCM_MANU_RcCdn_4AcvUnloadRail );

         /* Taille du parametre Pression_Rail en bits */
         u16Locallength = 16;
         VEMS_vidGET(PFuAcq_pFuRailMes, u16LocalpFuRailMes);
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u16LocalpFuRailMes = 0x0000;
         u8LocalRoutineStatus = 0x00;
         u16Locallength = 0;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u16LocalpFuRailMes = 0x0000;
      u8LocalRoutineStatus = 0x00;
      u16Locallength = 0;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   Pression_Rail[0] = (uint8)((u16LocalpFuRailMes & 0xFF00) >> 8);
   Pression_Rail[1] = (uint8)(u16LocalpFuRailMes & 0x00FF);
   *State_Routine = u8LocalRoutineStatus;
   /* Taille en byte du dernier parametre (Pression_Rail) */
   *currentDataLength = u16Locallength;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StopRoutine_DFDD                                       */
/* !Description :  Is called from Dcm when RID DFDD service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.10                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StopRoutineDmnd(????);                                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_stRc_AcvUnloadRail;                                       */
/*  input boolean Srv_bRcStart_AcvUnloadRail;                                 */
/*  input uint8 Srv_stRcEnd_AcvUnloadRail;                                    */
/*  input boolean Srv_bRcCondOk_AcvUnloadRail;                                */
/*  input boolean Srv_bRcCom_AcvUnloadRail;                                   */
/*  input boolean Srv_bRcCdnOk_AcvUnloadRail;                                 */
/*  input boolean Srv_bRcCdnNok_AcvUnloadRail;                                */
/*  input boolean Srv_bRcReq_AcvUnloadRail;                                   */
/*  input boolean Srv_bRcStop_AcvUnloadRail;                                  */
/*  input ???? DCM_MANU_RcAcv_AcvUnloadRail;                                  */
/*  input ???? DCM_MANU_CheckCond4AcvUnloadRail;                              */
/*  input ???? DCM_MANU_RcCdn_4AcvUnloadRail;                                 */
/*  input uint16 PFuAcq_pFuRailMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DFDD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Pression_Rail,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16Locallength;
   uint16                       u16LocalpFuRailMes;
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
             DCM_MANU_StopRoutineDmnd( &Srv_stRc_AcvUnloadRail,
                                       &Srv_bRcStart_AcvUnloadRail,
                                       &Srv_stRcEnd_AcvUnloadRail,
                                       &Srv_bRcCondOk_AcvUnloadRail,
                                       /* Srv_bRcSho_AcvUnloadRail */
                                       FALSE,
                                       &Srv_bRcCom_AcvUnloadRail,
                                       &Srv_bRcCdnOk_AcvUnloadRail,
                                       &Srv_bRcCdnNok_AcvUnloadRail,
                                       &Srv_bRcReq_AcvUnloadRail,
                                       &Srv_bRcStop_AcvUnloadRail,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_AcvUnloadRail,
                                       DCM_MANU_CheckCond4AcvUnloadRail,
                                       DCM_MANU_RcCdn_4AcvUnloadRail );

         /* Taille du parametre Pression_Rail en bits */
         u16Locallength = 16;
         VEMS_vidGET(PFuAcq_pFuRailMes, u16LocalpFuRailMes);
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u16LocalpFuRailMes = 0x0000;
         u8LocalRoutineStatus = 0x00;
         u16Locallength = 0;
      }
   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u16LocalpFuRailMes = 0x0000;
      u8LocalRoutineStatus = 0x00;
      u16Locallength = 0;
      /* On utilise pas u8LocalOutputParam dans les start routines */
   }

   *ErrorCode = u8LocalErrorCode;
   Pression_Rail[0] = (uint8)((u16LocalpFuRailMes & 0xFF00) >> 8);
   Pression_Rail[1] = (uint8)(u16LocalpFuRailMes & 0x00FF);
   *State_Routine = u8LocalRoutineStatus;
   /* Taille en byte du dernier parametre (Pression_Rail) */
   *currentDataLength = u16Locallength;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_0400                                      */
/* !Description :  Is called from Dcm when RID 0400 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.11                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_01688_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_MkdPwrl;                                             */
/*  input boolean Srv_bRcStart_MkdPwrl;                                       */
/*  input uint8 Srv_stRcEnd_MkdPwrl;                                          */
/*  input boolean Srv_bRcCondOk_MkdPwrl;                                      */
/*  input boolean Srv_bRcCom_MkdPwrl;                                         */
/*  input boolean Srv_bRcCdnOk_MkdPwrl;                                       */
/*  input boolean Srv_bRcCdnNok_MkdPwrl;                                      */
/*  input boolean Srv_bRcReq_MkdPwrl;                                         */
/*  input boolean Srv_bRcStop_MkdPwrl;                                        */
/*  input ???? DCM_MANU_RcAcv_MkdPwrl;                                        */
/*  input ???? DCM_MANU_CheckCond4MkdPwrl;                                    */
/*  input ???? DCM_MANU_CheckRcCdn_MkdPwrl;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_StartRoutine_0400                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_0400
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_MkdPwrl,
                                       &Srv_bRcStart_MkdPwrl,
                                       &Srv_stRcEnd_MkdPwrl,
                                       &Srv_bRcCondOk_MkdPwrl,
                                       /* Srv_bRcSho_MkdPwrl */
                                       FALSE,
                                       &Srv_bRcCom_MkdPwrl,
                                       &Srv_bRcCdnOk_MkdPwrl,
                                       &Srv_bRcCdnNok_MkdPwrl,
                                       &Srv_bRcReq_MkdPwrl,
                                       &Srv_bRcStop_MkdPwrl,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_MkdPwrl,
                                       DCM_MANU_CheckCond4MkdPwrl,
                                       DCM_MANU_CheckRcCdn_MkdPwrl );
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
/* !Function    :  DLT_StartRoutine_DFA0                                      */
/* !Description :  Is called from Dcm when RID DFA0 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.12                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_SftyLvl2;                                            */
/*  input boolean Srv_bRcStart_SftyLvl2;                                      */
/*  input uint8 Srv_stRcEnd_SftyLvl2;                                         */
/*  input boolean Srv_bRcCondOk_SftyLvl2;                                     */
/*  input boolean Srv_bRcCom_SftyLvl2;                                        */
/*  input boolean Srv_bRcCdnOk_SftyLvl2;                                      */
/*  input boolean Srv_bRcCdnNok_SftyLvl2;                                     */
/*  input boolean Srv_bRcReq_SftyLvl2;                                        */
/*  input boolean Srv_bRcStop_SftyLvl2;                                       */
/*  input ???? DCM_MANU_RcAcv_SftyLvl2;                                       */
/*  input ???? DCM_MANU_CheckCond4SftyLvl2;                                   */
/*  input ???? DCM_MANU_RcCdn_SftyLvl2;                                       */
/*  output uint8 DCM_MANU_Cntrl_Inhibition;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFA0
(
   uint8 Cntrl_Inhibition,
   uint16 Tool_Signature,
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
      if( ( 0xFF == Cntrl_Inhibition ) ||
          ( 0x00 == Cntrl_Inhibition ) )
      {
         u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                     &u8LocalErrorCode );

         if( E_OK == u8LocalReturn )
         {
            if( DCM_MANU_SIGNATURE_OUTILS == Tool_Signature )
            {
               DCM_MANU_Cntrl_Inhibition = Cntrl_Inhibition;
               u8LocalReturn =
                  DCM_MANU_StartRoutineDmnd( &Srv_stRc_SftyLvl2,
                                             &Srv_bRcStart_SftyLvl2,
                                             &Srv_stRcEnd_SftyLvl2,
                                             &Srv_bRcCondOk_SftyLvl2,
                                             /* Srv_bRcSho_SftyLvl2 */
                                             TRUE,
                                             &Srv_bRcCom_SftyLvl2,
                                             &Srv_bRcCdnOk_SftyLvl2,
                                             &Srv_bRcCdnNok_SftyLvl2,
                                             &Srv_bRcReq_SftyLvl2,
                                             &Srv_bRcStop_SftyLvl2,
                                             &u8LocalErrorCode,
                                             &u8LocalRoutineStatus,
                                             DCM_MANU_RcAcv_SftyLvl2,
                                             DCM_MANU_CheckCond4SftyLvl2,
                                             DCM_MANU_RcCdn_SftyLvl2 );
            }
            else
            {
               u8LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
               u8LocalReturn = E_NOT_OK;
               u8LocalRoutineStatus = 0x00;
               /* On utilise pas u8LocalOutputParam dans
               les start routines */
            }
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
/* !Function    :  DLT_StartRoutine_DFAC                                      */
/* !Description :  Is called from Dcm when RID DFAC service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.13                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Srv_EveRcWrCodProg();                                    */
/*  extf argret Std_ReturnType  DCM_MANU_Programming_Result_Analyse(argin     */
/* uint8 *u8LocalRoutineStatus, argout uint8 *u8LocalErrorCode, argout uint8  */
/* *u8LocalOutputParam, argout uint16 *u16LocalCurrentDataLength);            */
/*  output uint32 DCM_MANU_Code_Antidemarrage;                                */
/*  output uint8 DCM_MANU_Option_Appairage;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFAC
(
   uint32 Code_Antidemarrage,
   uint8* Option_Appairage,
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Problem_Value,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   uint8                        u8LocalVar;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      /* Taille utile en bits du paramêtre "Option_Appairage" */
      if( 8 == *currentDataLength )
      {
         u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_CODPROG,
                                                     &u8LocalErrorCode );
         if( E_OK == u8LocalReturn )
         {
            VEMS_vidSET(DCM_MANU_Code_Antidemarrage, Code_Antidemarrage);
            u8LocalVar = *Option_Appairage;
            VEMS_vidSET(DCM_MANU_Option_Appairage, u8LocalVar);
            Srv_EveRcWrCodProg();

            u8LocalReturn =
               DCM_MANU_Programming_Result_Analyse( &u8LocalRoutineStatus,
                                                    &u8LocalErrorCode,
                                                    &u8LocalOutputParam,
                                                    &u16LocalCurrentDataLgth );
         }
         else
         {
            /* Les conditions ADC ne sont pas bonnes */
            u8LocalOutputParam = 0;
            u8LocalRoutineStatus = 0;
            u16LocalCurrentDataLgth = 0;
         }
      }
      else
      {
         u8LocalErrorCode = DCM_E_INCORRECTLENGTH;
         u8LocalReturn = E_NOT_OK;
         u8LocalOutputParam = 0;
         u8LocalRoutineStatus = 0;
         u16LocalCurrentDataLgth = 0;
      }
   }
   else if( DCM_PENDING == OpStatus )
   {
      u8LocalReturn =
            DCM_MANU_Programming_Result_Analyse( &u8LocalRoutineStatus,
                                                 &u8LocalErrorCode,
                                                 &u8LocalOutputParam,
                                                 &u16LocalCurrentDataLgth );
   }
   else /* DCM_CANCEL */
   {
      u8LocalReturn = E_OK;
      u8LocalErrorCode = 0x00;
      u8LocalOutputParam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0x0000;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *Problem_Value = u8LocalOutputParam;
   *currentDataLength = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}




/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_RequestResult_0400                                     */
/* !Description :  Is called from Dcm when RID 0400 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API4.14                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_01688_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_MkdPwrl;                                             */
/*  input boolean Srv_bRcStart_MkdPwrl;                                       */
/*  input uint8 Srv_stRcEnd_MkdPwrl;                                          */
/*  input boolean Srv_bRcCondOk_MkdPwrl;                                      */
/*  input boolean Srv_bRcCom_MkdPwrl;                                         */
/*  input boolean Srv_bRcCdnOk_MkdPwrl;                                       */
/*  input boolean Srv_bRcCdnNok_MkdPwrl;                                      */
/*  input boolean Srv_bRcReq_MkdPwrl;                                         */
/*  input boolean Srv_bRcStop_MkdPwrl;                                        */
/*  input ???? DCM_MANU_RcAcv_MkdPwrl;                                        */
/*  input ???? DCM_MANU_CheckCond4MkdPwrl;                                    */
/*  input ???? DCM_MANU_CheckRcCdn_MkdPwrl;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_0400
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_MkdPwrl,
                                       &Srv_bRcStart_MkdPwrl,
                                       &Srv_stRcEnd_MkdPwrl,
                                       &Srv_bRcCondOk_MkdPwrl,
                                       /* Srv_bRcSho_MkdPwrl */
                                       FALSE,
                                       &Srv_bRcCom_MkdPwrl,
                                       &Srv_bRcCdnOk_MkdPwrl,
                                       &Srv_bRcCdnNok_MkdPwrl,
                                       &Srv_bRcReq_MkdPwrl,
                                       &Srv_bRcStop_MkdPwrl,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_MkdPwrl,
                                       DCM_MANU_CheckCond4MkdPwrl,
                                       DCM_MANU_CheckRcCdn_MkdPwrl );
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



