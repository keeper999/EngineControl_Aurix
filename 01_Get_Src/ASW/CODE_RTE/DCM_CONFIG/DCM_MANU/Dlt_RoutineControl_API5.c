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
/* !File            : Dlt_RoutineControl_API5.c                               */
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
/*   1 / DLT_RequestResult_DF22                                               */
/*   2 / DLT_StartRoutine_DF22                                                */
/*   3 / DLT_StopRoutine_DF22                                                 */
/*   4 / DLT_StartRoutine_F000                                                */
/*   5 / DLT_StartRoutine_DFA1                                                */
/*   6 / DLT_StartRoutine_DF20                                                */
/*   7 / DLT_RequestResult_DF20                                               */
/*   8 / DLT_StartRoutine_DF28                                                */
/*   9 / DLT_RequestResult_DF28                                               */
/*   10 / DLT_StartRoutine_DF2A                                               */
/*   11 / DLT_RequestResult_DF2A                                              */
/*   12 / DLT_StartRoutine_DF2C                                               */
/*   13 / DLT_RequestResult_DF2C                                              */
/*   14 / DLT_StartRoutine_DF2D                                               */
/*   15 / DLT_RequestResult_DF2D                                              */
/*   16 / DLT_StartRoutine_DFCA                                               */
/*   17 / DLT_RequestResult_DFCA                                              */
/*   18 / DLT_StartRoutine_DFDC                                               */
/*   19 / DLT_RequestResult_DFDC                                              */
/*   20 / DLT_StopRoutine_DFDC                                                */
/*   21 / DLT_StartRoutine_DFE2                                               */
/*   22 / DLT_RequestResult_DFE2                                              */
/*   23 / DLT_StopRoutine_DFE2                                                */
/*   24 / DLT_StartRoutine_DFAE                                               */
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
/* !Function    :  DLT_RequestResult_DF22                                     */
/* !Description :  Is called from Dcm when RID DF22 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.1                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf argret uint8  DCM_MANU_IuprResponseConcat(argout uint8 *au8IUPR,     */
/* argout uint16 *u16Size);                                                   */
/*  input boolean DCM_MANU_ReqIuprReceived;                                   */
/*  output boolean DCM_MANU_ReqIuprReceived;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_RequestResult_DF22
(
   Dcm_OpStatusType OpStatus,
   uint8* Statut_Lecture,
   uint8* Tab_IUPR,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLength;
   uint16                       u16LocalSize;
   uint8                        u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalStatutLecture;



   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         /* On check si la routine de lecture des IUPRs est déjà en cours */
         if( TRUE == DCM_MANU_ReqIuprReceived )
         {
            u8LocalStatutLecture =
               DCM_MANU_IuprResponseConcat(Tab_IUPR, &u16LocalSize);
            u8LocalReturn = E_OK;
            u8LocalErrorCode = 0x00;
            /* Taille de dernier output parameter en bits */
            u16LocalCurrentDataLength = (uint16)(u16LocalSize*8);
            DCM_MANU_ReqIuprReceived = (boolean)
               ((0xFF == u8LocalStatutLecture) ? TRUE : FALSE);
         }
         else
         {
            u8LocalReturn = E_NOT_OK;
            u8LocalStatutLecture = 0x00;
            u16LocalCurrentDataLength = 0x0000;
            u8LocalErrorCode = DCM_E_REQUESTSEQUENCEERROR;
         }
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalStatutLecture = 0x00;
         u16LocalCurrentDataLength = 0x0000;
      }
   }
   else
   {
      u8LocalReturn = E_NOT_OK;
      u8LocalStatutLecture = 0x00;
      u16LocalCurrentDataLength = 0x0000;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
   }

   *Statut_Lecture = u8LocalStatutLecture;
   /* Taille en byte du dernier parametre (Tab_IUPR) */
   *currentDataLength = u16LocalCurrentDataLength;
   *ErrorCode = u8LocalErrorCode;



   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DF22                                      */
/* !Description :  Is called from Dcm when RID DF22 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.2                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf argret void DCM_MANU_IuprResponseCreate();                           */
/*  extf argret uint8  DCM_MANU_IuprResponseConcat(argout uint8 *au8IUPR,     */
/* argout uint16 *u16Size);                                                   */
/*  input boolean DCM_MANU_ReqIuprReceived;                                   */
/*  output uint16 DCM_MANU_UdsIuprFrameSize;                                  */
/*  output uint16 DCM_MANU_UdsIuprNbByteSent;                                 */
/*  output uint16 DCM_MANU_UdsIuprIndexToSend;                                */
/*  output boolean DCM_MANU_ReqIuprReceived;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DF22
(
   Dcm_OpStatusType OpStatus,
   uint8* Statut_Lecture,
   uint8* Tab_IUPR,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLength;
   uint16                       u16LocalSize;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalStatutLecture;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         /* On check si la routine de lecture des IUPRs
         n'est pas déjà en cours */
         if( FALSE == DCM_MANU_ReqIuprReceived )
         {
            DCM_MANU_UdsIuprFrameSize = 0;
            DCM_MANU_UdsIuprNbByteSent = 0;
            DCM_MANU_UdsIuprIndexToSend = 0;
            DCM_MANU_IuprResponseCreate();
            u8LocalStatutLecture =
               DCM_MANU_IuprResponseConcat(Tab_IUPR, &u16LocalSize);
            DCM_MANU_ReqIuprReceived = (boolean)
               ((0xFF == u8LocalStatutLecture) ? TRUE : FALSE);
            u8LocalReturn = E_OK;
            u8LocalErrorCode = 0x00;
            /* Taille du dernier ouput parameter en bits */
            u16LocalCurrentDataLength = (uint16)(u16LocalSize*8);
         }
         else
         {
            u8LocalReturn = E_NOT_OK;
            u8LocalStatutLecture = 0;
            u16LocalCurrentDataLength = 0;
            u8LocalErrorCode = DCM_E_REQUESTSEQUENCEERROR;
         }
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalStatutLecture = 0;
         u16LocalCurrentDataLength = 0;
      }
   }
   else
   {
      u8LocalReturn = E_NOT_OK;
      u8LocalStatutLecture = 0;
      u16LocalCurrentDataLength = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
   }

   *Statut_Lecture = u8LocalStatutLecture;
   /* Taille en byte du dernier parametre (Tab_IUPR) */
   *currentDataLength = u16LocalCurrentDataLength;
   *ErrorCode = u8LocalErrorCode;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StopRoutine_DF22                                       */
/* !Description :  Is called from Dcm when RID DF22 service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.3                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  input boolean DCM_MANU_ReqIuprReceived;                                   */
/*  output boolean DCM_MANU_ReqIuprReceived;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_ConditionCheckRead_D422                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StopRoutine_DF22
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLength;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &u8LocalErrorCode );

      if( E_OK == u8LocalReturn )
      {
         /* Si nous avons déjà reçue une routine de lecture des IUPRs
         et que celle-ci n'est pas terminée */
         if( TRUE == DCM_MANU_ReqIuprReceived )
         {
            u8LocalReturn = E_OK;
            u8LocalErrorCode = 0;
            u8LocalRoutineStatus = 0x04;
            /* Taille du dernier output parameter en bits */
            u16LocalCurrentDataLength = 8;
            /* On rabaisse le flag */
            DCM_MANU_ReqIuprReceived = FALSE;
         }
         else
         {
            u8LocalReturn = E_NOT_OK;
            u8LocalRoutineStatus = 0;
            u16LocalCurrentDataLength = 0;
            u8LocalErrorCode = DCM_E_REQUESTSEQUENCEERROR;
         }
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         u8LocalRoutineStatus = 0;
         u16LocalCurrentDataLength = 0;
      }
   }
   else
   {
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0;
      u16LocalCurrentDataLength = 0;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
   }

   *State_Routine = u8LocalRoutineStatus;
   /* Taille en byte du dernier parametre (State_Routine) */
   *currentDataLength = u16LocalCurrentDataLength;
   *ErrorCode = u8LocalErrorCode;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_F000                                      */
/* !Description :  Fonction appelée sur réception de la requête de saut en    */
/*                 test en prod.                                              */
/* !Number      :  RC_API5.4                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_ProdTest;                                            */
/*  input boolean Srv_bRcStart_ProdTest;                                      */
/*  input uint8 Srv_stRcEnd_ProdTest;                                         */
/*  input boolean Srv_bRcCondOk_ProdTest;                                     */
/*  input boolean Srv_bRcCom_ProdTest;                                        */
/*  input boolean Srv_bRcCdnOk_ProdTest;                                      */
/*  input boolean Srv_bRcCdnNok_ProdTest;                                     */
/*  input boolean Srv_bRcReq_ProdTest;                                        */
/*  input boolean Srv_bRcStop_ProdTest;                                       */
/*  input ???? DCM_MANU_RcAcv_ProdTest;                                       */
/*  input ???? DCM_MANU_CheckCond4ProdTest;                                   */
/*  input ???? DCM_MANU_RcCdn_ProdTest;                                       */
/*  output uint16 DCM_MANU_TestProdParam;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DLT_StartRoutine_F000                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_F000
(
   uint8 Param_1,
   uint8 Param_2,
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint8                        u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      DCM_MANU_TestProdParam = (uint16)(((uint32)Param_1 << 8) |
                                 (uint32)Param_2);
      u8LocalReturn =
         DCM_MANU_StartRoutineDmnd( &Srv_stRc_ProdTest,
                                    &Srv_bRcStart_ProdTest,
                                    &Srv_stRcEnd_ProdTest,
                                    &Srv_bRcCondOk_ProdTest,
                                    /* Srv_bRcSho_ProdTest */
                                    TRUE,
                                    &Srv_bRcCom_ProdTest,
                                    &Srv_bRcCdnOk_ProdTest,
                                    &Srv_bRcCdnNok_ProdTest,
                                    &Srv_bRcReq_ProdTest,
                                    &Srv_bRcStop_ProdTest,
                                    &u8LocalErrorCode,
                                    &u8LocalRoutineStatus,
                                    DCM_MANU_RcAcv_ProdTest,
                                    DCM_MANU_CheckCond4ProdTest,
                                    DCM_MANU_RcCdn_ProdTest );

   }
   else
   {
      /* GeneralReject */
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   return u8LocalReturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_StartRoutine_DFA1                                      */
/* !Description :  Is called from Dcm when RID DFA1 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.5                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_ThrInh;                                              */
/*  input boolean Srv_bRcStart_ThrInh;                                        */
/*  input uint8 Srv_stRcEnd_ThrInh;                                           */
/*  input boolean Srv_bRcCondOk_ThrInh;                                       */
/*  input boolean Srv_bRcCom_ThrInh;                                          */
/*  input boolean Srv_bRcCdnOk_ThrInh;                                        */
/*  input boolean Srv_bRcCdnNok_ThrInh;                                       */
/*  input boolean Srv_bRcReq_ThrInh;                                          */
/*  input boolean Srv_bRcStop_ThrInh;                                         */
/*  input ???? DCM_MANU_RcAcv_ThrInh;                                         */
/*  input ???? DCM_MANU_CheckCond4ThrInh;                                     */
/*  input ???? DCM_MANU_RcCdn_ThrInh;                                         */
/*  output uint8 DCM_MANU_Cntrl_Inhibition;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFA1
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
                  DCM_MANU_StartRoutineDmnd( &Srv_stRc_ThrInh,
                                             &Srv_bRcStart_ThrInh,
                                             &Srv_stRcEnd_ThrInh,
                                             &Srv_bRcCondOk_ThrInh,
                                             /* Srv_bRcSho_ThrInh */
                                             TRUE,
                                             &Srv_bRcCom_ThrInh,
                                             &Srv_bRcCdnOk_ThrInh,
                                             &Srv_bRcCdnNok_ThrInh,
                                             &Srv_bRcReq_ThrInh,
                                             &Srv_bRcStop_ThrInh,
                                             &u8LocalErrorCode,
                                             &u8LocalRoutineStatus,
                                             DCM_MANU_RcAcv_ThrInh,
                                             DCM_MANU_CheckCond4ThrInh,
                                             DCM_MANU_RcCdn_ThrInh );
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
/* !Function    :  DLT_StartRoutine_DF20                                      */
/* !Description :  Is called from Dcm when RID DF20 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.6                                                  */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_009.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_BattChg;                                             */
/*  input boolean Srv_bRcStart_BattChg;                                       */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input boolean Srv_bRcCondOk_BattChg;                                      */
/*  input boolean Srv_bRcCom_BattChg;                                         */
/*  input boolean Srv_bRcCdnOk_BattChg;                                       */
/*  input boolean Srv_bRcCdnNok_BattChg;                                      */
/*  input boolean Srv_bRcReq_BattChg;                                         */
/*  input boolean Srv_bRcStop_BattChg;                                        */
/*  input ???? DCM_MANU_RcAcv_BattChg;                                        */
/*  input ???? DCM_MANU_CheckCond4BattChg;                                    */
/*  input ???? DCM_MANU_CheckRcCdn_BattChg;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF20
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_BattChg,
                                       &Srv_bRcStart_BattChg,
                                       &Srv_stRcEnd_BattChg,
                                       &Srv_bRcCondOk_BattChg,
                                       /* Srv_bRcSho_BattChg */
                                       FALSE,
                                       &Srv_bRcCom_BattChg,
                                       &Srv_bRcCdnOk_BattChg,
                                       &Srv_bRcCdnNok_BattChg,
                                       &Srv_bRcReq_BattChg,
                                       &Srv_bRcStop_BattChg,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_BattChg,
                                       DCM_MANU_CheckCond4BattChg,
                                       DCM_MANU_CheckRcCdn_BattChg );
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
/* !Function    :  DLT_RequestResult_DF20                                     */
/* !Description :  Is called from Dcm when RID DF20 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.7                                                  */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_009.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_BattChg;                                             */
/*  input boolean Srv_bRcStart_BattChg;                                       */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input boolean Srv_bRcCondOk_BattChg;                                      */
/*  input boolean Srv_bRcCom_BattChg;                                         */
/*  input boolean Srv_bRcCdnOk_BattChg;                                       */
/*  input boolean Srv_bRcCdnNok_BattChg;                                      */
/*  input boolean Srv_bRcReq_BattChg;                                         */
/*  input boolean Srv_bRcStop_BattChg;                                        */
/*  input ???? DCM_MANU_RcAcv_BattChg;                                        */
/*  input ???? DCM_MANU_CheckCond4BattChg;                                    */
/*  input ???? DCM_MANU_CheckRcCdn_BattChg;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF20
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_BattChg,
                                       &Srv_bRcStart_BattChg,
                                       &Srv_stRcEnd_BattChg,
                                       &Srv_bRcCondOk_BattChg,
                                       /* Srv_bRcSho_MkdPwrl */
                                       FALSE,
                                       &Srv_bRcCom_BattChg,
                                       &Srv_bRcCdnOk_BattChg,
                                       &Srv_bRcCdnNok_BattChg,
                                       &Srv_bRcReq_BattChg,
                                       &Srv_bRcStop_BattChg,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_BattChg,
                                       DCM_MANU_CheckCond4BattChg,
                                       DCM_MANU_CheckRcCdn_BattChg );
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
/* !Function    :  DLT_StartRoutine_DF28                                      */
/* !Description :  Is called from Dcm when RID DF28 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.8                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstCurRdB;                                           */
/*  input boolean Srv_bRcStart_RstCurRdB;                                     */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input boolean Srv_bRcCondOk_RstCurRdB;                                    */
/*  input boolean Srv_bRcCom_RstCurRdB;                                       */
/*  input boolean Srv_bRcCdnOk_RstCurRdB;                                     */
/*  input boolean Srv_bRcCdnNok_RstCurRdB;                                    */
/*  input boolean Srv_bRcReq_RstCurRdB;                                       */
/*  input boolean Srv_bRcStop_RstCurRdB;                                      */
/*  input ???? DCM_MANU_RcAcv_RstCurRdB;                                      */
/*  input ???? DCM_MANU_CheckCond4RstCurRdB;                                  */
/*  input ???? DCM_MANU_CheckRcCdn_RstCurRdB;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF28
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstCurRdB,
                                       &Srv_bRcStart_RstCurRdB,
                                       &Srv_stRcEnd_RstCurRdB,
                                       &Srv_bRcCondOk_RstCurRdB,
                                       /* Srv_bRcSho_RstCurRdB */
                                       FALSE,
                                       &Srv_bRcCom_RstCurRdB,
                                       &Srv_bRcCdnOk_RstCurRdB,
                                       &Srv_bRcCdnNok_RstCurRdB,
                                       &Srv_bRcReq_RstCurRdB,
                                       &Srv_bRcStop_RstCurRdB,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCurRdB,
                                       DCM_MANU_CheckCond4RstCurRdB,
                                       DCM_MANU_CheckRcCdn_RstCurRdB );
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
/* !Function    :  DLT_RequestResult_DF28                                     */
/* !Description :  Is called from Dcm when RID DF28 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.9                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstCurRdB;                                           */
/*  input boolean Srv_bRcStart_RstCurRdB;                                     */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input boolean Srv_bRcCondOk_RstCurRdB;                                    */
/*  input boolean Srv_bRcCom_RstCurRdB;                                       */
/*  input boolean Srv_bRcCdnOk_RstCurRdB;                                     */
/*  input boolean Srv_bRcCdnNok_RstCurRdB;                                    */
/*  input boolean Srv_bRcReq_RstCurRdB;                                       */
/*  input boolean Srv_bRcStop_RstCurRdB;                                      */
/*  input ???? DCM_MANU_RcAcv_RstCurRdB;                                      */
/*  input ???? DCM_MANU_CheckCond4RstCurRdB;                                  */
/*  input ???? DCM_MANU_CheckRcCdn_RstCurRdB;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF28
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstCurRdB,
                                       &Srv_bRcStart_RstCurRdB,
                                       &Srv_stRcEnd_RstCurRdB,
                                       &Srv_bRcCondOk_RstCurRdB,
                                       /* Srv_bRcSho_RstCurRdB */
                                       FALSE,
                                       &Srv_bRcCom_RstCurRdB,
                                       &Srv_bRcCdnOk_RstCurRdB,
                                       &Srv_bRcCdnNok_RstCurRdB,
                                       &Srv_bRcReq_RstCurRdB,
                                       &Srv_bRcStop_RstCurRdB,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCurRdB,
                                       DCM_MANU_CheckCond4RstCurRdB,
                                       DCM_MANU_CheckRcCdn_RstCurRdB );
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
/* !Function    :  DLT_StartRoutine_DF2A                                      */
/* !Description :  Is called from Dcm when RID DF2A service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.10                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstCoReqRStrt;                                       */
/*  input boolean Srv_bRcStart_RstCoReqRStrt;                                 */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input boolean Srv_bRcCondOk_RstCoReqRStrt;                                */
/*  input boolean Srv_bRcCom_RstCoReqRStrt;                                   */
/*  input boolean Srv_bRcCdnOk_RstCoReqRStrt;                                 */
/*  input boolean Srv_bRcCdnNok_RstCoReqRStrt;                                */
/*  input boolean Srv_bRcReq_RstCoReqRStrt;                                   */
/*  input boolean Srv_bRcStop_RstCoReqRStrt;                                  */
/*  input ???? DCM_MANU_RcAcv_RstCoReqRStrt;                                  */
/*  input ???? DCM_MANU_CheckCond4RstCoReqRStrt;                              */
/*  input ???? DCM_MANU_CheckRcCdn_RstCoReqRStrt;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF2A
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstCoReqRStrt,
                                       &Srv_bRcStart_RstCoReqRStrt,
                                       &Srv_stRcEnd_RstCoReqRStrt,
                                       &Srv_bRcCondOk_RstCoReqRStrt,
                                       /* Srv_bRcSho_RstCoReqRStrt */
                                       FALSE,
                                       &Srv_bRcCom_RstCoReqRStrt,
                                       &Srv_bRcCdnOk_RstCoReqRStrt,
                                       &Srv_bRcCdnNok_RstCoReqRStrt,
                                       &Srv_bRcReq_RstCoReqRStrt,
                                       &Srv_bRcStop_RstCoReqRStrt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCoReqRStrt,
                                       DCM_MANU_CheckCond4RstCoReqRStrt,
                                       DCM_MANU_CheckRcCdn_RstCoReqRStrt );
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
/* !Function    :  DLT_RequestResult_DF2A                                     */
/* !Description :  Is called from Dcm when RID DF2A service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.11                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstCoReqRStrt;                                       */
/*  input boolean Srv_bRcStart_RstCoReqRStrt;                                 */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input boolean Srv_bRcCondOk_RstCoReqRStrt;                                */
/*  input boolean Srv_bRcCom_RstCoReqRStrt;                                   */
/*  input boolean Srv_bRcCdnOk_RstCoReqRStrt;                                 */
/*  input boolean Srv_bRcCdnNok_RstCoReqRStrt;                                */
/*  input boolean Srv_bRcReq_RstCoReqRStrt;                                   */
/*  input boolean Srv_bRcStop_RstCoReqRStrt;                                  */
/*  input ???? DCM_MANU_RcAcv_RstCoReqRStrt;                                  */
/*  input ???? DCM_MANU_CheckCond4RstCoReqRStrt;                              */
/*  input ???? DCM_MANU_CheckRcCdn_RstCoReqRStrt;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF2A
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstCoReqRStrt,
                                       &Srv_bRcStart_RstCoReqRStrt,
                                       &Srv_stRcEnd_RstCoReqRStrt,
                                       &Srv_bRcCondOk_RstCoReqRStrt,
                                       /* Srv_bRcSho_RstCoReqRStrt */
                                       FALSE,
                                       &Srv_bRcCom_RstCoReqRStrt,
                                       &Srv_bRcCdnOk_RstCoReqRStrt,
                                       &Srv_bRcCdnNok_RstCoReqRStrt,
                                       &Srv_bRcReq_RstCoReqRStrt,
                                       &Srv_bRcStop_RstCoReqRStrt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCoReqRStrt,
                                       DCM_MANU_CheckCond4RstCoReqRStrt,
                                       DCM_MANU_CheckRcCdn_RstCoReqRStrt );
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
/* !Function    :  DLT_StartRoutine_DF2C                                      */
/* !Description :  Is called from Dcm when RID DF2C service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.12                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstStaCnt;                                           */
/*  input boolean Srv_bRcStart_RstStaCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input boolean Srv_bRcCondOk_RstStaCnt;                                    */
/*  input boolean Srv_bRcCom_RstStaCnt;                                       */
/*  input boolean Srv_bRcCdnOk_RstStaCnt;                                     */
/*  input boolean Srv_bRcCdnNok_RstStaCnt;                                    */
/*  input boolean Srv_bRcReq_RstStaCnt;                                       */
/*  input boolean Srv_bRcStop_RstStaCnt;                                      */
/*  input ???? DCM_MANU_RcAcv_RstStaCnt;                                      */
/*  input ???? DCM_MANU_CheckCond4RstStaCnt;                                  */
/*  input ???? DCM_MANU_CheckRcCdn_RstStaCnt;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF2C
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstStaCnt,
                                       &Srv_bRcStart_RstStaCnt,
                                       &Srv_stRcEnd_RstStaCnt,
                                       &Srv_bRcCondOk_RstStaCnt,
                                       /* Srv_bRcSho_RstStaCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstStaCnt,
                                       &Srv_bRcCdnOk_RstStaCnt,
                                       &Srv_bRcCdnNok_RstStaCnt,
                                       &Srv_bRcReq_RstStaCnt,
                                       &Srv_bRcStop_RstStaCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstStaCnt,
                                       DCM_MANU_CheckCond4RstStaCnt,
                                       DCM_MANU_CheckRcCdn_RstStaCnt );
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
/* !Function    :  DLT_RequestResult_DF2C                                     */
/* !Description :  Is called from Dcm when RID DF2C service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.13                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstStaCnt;                                           */
/*  input boolean Srv_bRcStart_RstStaCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input boolean Srv_bRcCondOk_RstStaCnt;                                    */
/*  input boolean Srv_bRcCom_RstStaCnt;                                       */
/*  input boolean Srv_bRcCdnOk_RstStaCnt;                                     */
/*  input boolean Srv_bRcCdnNok_RstStaCnt;                                    */
/*  input boolean Srv_bRcReq_RstStaCnt;                                       */
/*  input boolean Srv_bRcStop_RstStaCnt;                                      */
/*  input ???? DCM_MANU_RcAcv_RstStaCnt;                                      */
/*  input ???? DCM_MANU_CheckCond4RstStaCnt;                                  */
/*  input ???? DCM_MANU_CheckRcCdn_RstStaCnt;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF2C
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstStaCnt,
                                       &Srv_bRcStart_RstStaCnt,
                                       &Srv_stRcEnd_RstStaCnt,
                                       &Srv_bRcCondOk_RstStaCnt,
                                       /* Srv_bRcSho_RstStaCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstStaCnt,
                                       &Srv_bRcCdnOk_RstStaCnt,
                                       &Srv_bRcCdnNok_RstStaCnt,
                                       &Srv_bRcReq_RstStaCnt,
                                       &Srv_bRcStop_RstStaCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstStaCnt,
                                       DCM_MANU_CheckCond4RstStaCnt,
                                       DCM_MANU_CheckRcCdn_RstStaCnt );
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
/* !Function    :  DLT_StartRoutine_DF2D                                      */
/* !Description :  Is called from Dcm when RID DF2D service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.14                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstCluDftCnt;                                        */
/*  input boolean Srv_bRcStart_RstCluDftCnt;                                  */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input boolean Srv_bRcCondOk_RstCluDftCnt;                                 */
/*  input boolean Srv_bRcCom_RstCluDftCnt;                                    */
/*  input boolean Srv_bRcCdnOk_RstCluDftCnt;                                  */
/*  input boolean Srv_bRcCdnNok_RstCluDftCnt;                                 */
/*  input boolean Srv_bRcReq_RstCluDftCnt;                                    */
/*  input boolean Srv_bRcStop_RstCluDftCnt;                                   */
/*  input ???? DCM_MANU_RcAcv_RstCluDftCnt;                                   */
/*  input ???? DCM_MANU_CheckCond4RstCluDftCnt;                               */
/*  input ???? DCM_MANU_CheckRcCdn_RstCluDftCnt;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF2D
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstCluDftCnt,
                                       &Srv_bRcStart_RstCluDftCnt,
                                       &Srv_stRcEnd_RstCluDftCnt,
                                       &Srv_bRcCondOk_RstCluDftCnt,
                                       /* Srv_bRcSho_RstStaCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstCluDftCnt,
                                       &Srv_bRcCdnOk_RstCluDftCnt,
                                       &Srv_bRcCdnNok_RstCluDftCnt,
                                       &Srv_bRcReq_RstCluDftCnt,
                                       &Srv_bRcStop_RstCluDftCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCluDftCnt,
                                       DCM_MANU_CheckCond4RstCluDftCnt,
                                       DCM_MANU_CheckRcCdn_RstCluDftCnt );
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
/* !Function    :  DLT_RequestResult_DF2D                                     */
/* !Description :  Is called from Dcm when RID DF2D service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.15                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstCluDftCnt;                                        */
/*  input boolean Srv_bRcStart_RstCluDftCnt;                                  */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input boolean Srv_bRcCondOk_RstCluDftCnt;                                 */
/*  input boolean Srv_bRcCom_RstCluDftCnt;                                    */
/*  input boolean Srv_bRcCdnOk_RstCluDftCnt;                                  */
/*  input boolean Srv_bRcCdnNok_RstCluDftCnt;                                 */
/*  input boolean Srv_bRcReq_RstCluDftCnt;                                    */
/*  input boolean Srv_bRcStop_RstCluDftCnt;                                   */
/*  input ???? DCM_MANU_RcAcv_RstCluDftCnt;                                   */
/*  input ???? DCM_MANU_CheckCond4RstCluDftCnt;                               */
/*  input ???? DCM_MANU_CheckRcCdn_RstCluDftCnt;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF2D
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstCluDftCnt,
                                       &Srv_bRcStart_RstCluDftCnt,
                                       &Srv_stRcEnd_RstCluDftCnt,
                                       &Srv_bRcCondOk_RstCluDftCnt,
                                       /* Srv_bRcSho_RstCluDftCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstCluDftCnt,
                                       &Srv_bRcCdnOk_RstCluDftCnt,
                                       &Srv_bRcCdnNok_RstCluDftCnt,
                                       &Srv_bRcReq_RstCluDftCnt,
                                       &Srv_bRcStop_RstCluDftCnt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstCluDftCnt,
                                       DCM_MANU_CheckCond4RstCluDftCnt,
                                       DCM_MANU_CheckRcCdn_RstCluDftCnt );
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
/* !Function    :  DLT_StartRoutine_DFCA                                      */
/* !Description :  Is called from Dcm when RID DFCA service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.16                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_ModeSTTBatt;                                         */
/*  input boolean Srv_bRcStart_ModeSTTBatt;                                   */
/*  input uint8 Srv_stRcEnd_ModeSTTBatt;                                      */
/*  input boolean Srv_bRcCondOk_ModeSTTBatt;                                  */
/*  input boolean Srv_bRcCom_ModeSTTBatt;                                     */
/*  input boolean Srv_bRcCdnOk_ModeSTTBatt;                                   */
/*  input boolean Srv_bRcCdnNok_ModeSTTBatt;                                  */
/*  input boolean Srv_bRcReq_ModeSTTBatt;                                     */
/*  input boolean Srv_bRcStop_ModeSTTBatt;                                    */
/*  input ???? DCM_MANU_RcAcv_ModeSTTBatt;                                    */
/*  input ???? DCM_MANU_CheckCond4ModeSTTBatt;                                */
/*  input ???? DCM_MANU_CheckRcCdn_ModeSTTBatt;                               */
/*  output uint8 DCM_MANU_Cntrl_ModeSTT;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFCA
(
   uint8 Cntrl_ModeSTT,
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
      if( ( 0x00 == Cntrl_ModeSTT ) ||
          ( 0x01 == Cntrl_ModeSTT )) 
      {
         u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                     &u8LocalErrorCode );

         if( E_OK == u8LocalReturn )
         {
            DCM_MANU_Cntrl_ModeSTT = Cntrl_ModeSTT;
            u8LocalReturn =
               DCM_MANU_StartRoutineDmnd( &Srv_stRc_ModeSTTBatt,
                                       &Srv_bRcStart_ModeSTTBatt,
                                       &Srv_stRcEnd_ModeSTTBatt,
                                       &Srv_bRcCondOk_ModeSTTBatt,
                                       /* Srv_bRcSho_ModeSTTBatt */
                                       FALSE,
                                       &Srv_bRcCom_ModeSTTBatt,
                                       &Srv_bRcCdnOk_ModeSTTBatt,
                                       &Srv_bRcCdnNok_ModeSTTBatt,
                                       &Srv_bRcReq_ModeSTTBatt,
                                       &Srv_bRcStop_ModeSTTBatt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_ModeSTTBatt,
                                       DCM_MANU_CheckCond4ModeSTTBatt,
                                       DCM_MANU_CheckRcCdn_ModeSTTBatt );
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
/* !Function    :  DLT_RequestResult_DFCA                                     */
/* !Description :  Is called from Dcm when RID DFCA service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.17                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_01688_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_ModeSTTBatt;                                         */
/*  input boolean Srv_bRcStart_ModeSTTBatt;                                   */
/*  input uint8 Srv_stRcEnd_ModeSTTBatt;                                      */
/*  input boolean Srv_bRcCondOk_ModeSTTBatt;                                  */
/*  input boolean Srv_bRcCom_ModeSTTBatt;                                     */
/*  input boolean Srv_bRcCdnOk_ModeSTTBatt;                                   */
/*  input boolean Srv_bRcCdnNok_ModeSTTBatt;                                  */
/*  input boolean Srv_bRcReq_ModeSTTBatt;                                     */
/*  input boolean Srv_bRcStop_ModeSTTBatt;                                    */
/*  input ???? DCM_MANU_RcAcv_ModeSTTBatt;                                    */
/*  input ???? DCM_MANU_CheckCond4ModeSTTBatt;                                */
/*  input ???? DCM_MANU_CheckRcCdn_ModeSTTBatt;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DFCA
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_ModeSTTBatt,
                                       &Srv_bRcStart_ModeSTTBatt,
                                       &Srv_stRcEnd_ModeSTTBatt,
                                       &Srv_bRcCondOk_ModeSTTBatt,
                                       /* Srv_bRcSho_ModeSTTBatt */
                                       FALSE,
                                       &Srv_bRcCom_ModeSTTBatt,
                                       &Srv_bRcCdnOk_ModeSTTBatt,
                                       &Srv_bRcCdnNok_ModeSTTBatt,
                                       &Srv_bRcReq_ModeSTTBatt,
                                       &Srv_bRcStop_ModeSTTBatt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_ModeSTTBatt,
                                       DCM_MANU_CheckCond4ModeSTTBatt,
                                       DCM_MANU_CheckRcCdn_ModeSTTBatt );
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
/* !Function    :  DLT_StartRoutine_DFDC                                      */
/* !Description :  Is called from Dcm when RID DFDC service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.18                                                 */
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
Std_ReturnType DLT_StartRoutine_DFDC
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
                              ( CODE_TEST_HPPMP,
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
/* !Function    :  DLT_RequestResult_DFDC                                     */
/* !Description :  Is called from Dcm when RID DFDC service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.19                                                 */
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
Std_ReturnType DLT_RequestResult_DFDC
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
                              ( CODE_TEST_HPPMP,
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
/* !Function    :  DLT_StopRoutine_DFDC                                       */
/* !Description :  Is called from Dcm when RID DFDC service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.20                                                 */
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
Std_ReturnType DLT_StopRoutine_DFDC
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
                           ( CODE_TEST_HPPMP,
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
/* !Function    :  DLT_StartRoutine_DFE2                                      */
/* !Description :  Is called from Dcm when RID DFE2 service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.21                                                 */
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
Std_ReturnType DLT_StartRoutine_DFE2
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
                              ( CODE_TEST_CTRLTHER,
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
/* !Function    :  DLT_RequestResult_DFE2                                     */
/* !Description :  Is called from Dcm when RID DFE2 service sub function 03 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.22                                                 */
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
Std_ReturnType DLT_RequestResult_DFE2
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
                              ( CODE_TEST_CTRLTHER,
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
/* !Function    :  DLT_StopRoutine_DFE2                                       */
/* !Description :  Is called from Dcm when RID DFE2 service sub function 02 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.23                                                 */
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
Std_ReturnType DLT_StopRoutine_DFE2
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
                           ( CODE_TEST_CTRLTHER,
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
/* !Function    :  DLT_StartRoutine_DFAE                                      */
/* !Description :  Is called from Dcm when RID DFAE service sub function 01 is*/
/*                 received.                                                  */
/* !Number      :  RC_API5.24                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Srv_EveRcChkCodProg();                                   */
/*  extf argret Std_ReturnType  DCM_MANU_Checking_Result_Analyse(argin uint8  */
/* *u8LocalRoutineStatus, argout uint8 *u8LocalErrorCode, argout uint8        */
/* *u8LocalOutputParam, argout uint16 *u16LocalCurrentDataLength);            */
/*  output uint32 DCM_MANU_Code_Antidemarrage;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_StartRoutine_DFAE
(
   uint8* Code_Antidemarrage,
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Problem_Value,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLength;
   uint32                       u32LocalCode;
   uint8                        u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   if( DCM_INITIAL == OpStatus )
   {
      /* Taille utile en bits du paramêtre "Code_Antidemarrage" */
      if( 32 == *currentDataLength )
      {
         u8LocalReturn = DCM_MANU_CheckADCCondition( SRV_CODCHK,
                                                     &u8LocalErrorCode );
         if( E_OK == u8LocalReturn )
         {
            u32LocalCode = (((uint32)Code_Antidemarrage[0]) << 24) |
                           (((uint32)Code_Antidemarrage[1]) << 16) |
                           (((uint32)Code_Antidemarrage[2]) << 8) |
                           ((uint32)Code_Antidemarrage[3]);

            VEMS_vidSET(DCM_MANU_Code_Antidemarrage, u32LocalCode);
            /* Traitement de la demane par le module SAIMMO */
            Srv_EveRcChkCodProg();

            /* Analyse des résultats */
            u8LocalReturn =
               DCM_MANU_Checking_Result_Analyse( &u8LocalRoutineStatus,
                                                 &u8LocalErrorCode,
                                                 &u8LocalOutputParam,
                                                 &u16LocalCurrentDataLength );
         }
         else
         {
            /* Les conditions ADC ne sont pas bonnes */
            u8LocalOutputParam = 0x00;
            u8LocalRoutineStatus = 0x00;
            u16LocalCurrentDataLength = 0x0000;
         }
      }
      else
      {
         u8LocalErrorCode = DCM_E_INCORRECTLENGTH;
         u8LocalReturn = E_NOT_OK;
         u8LocalOutputParam = 0x00;
         u8LocalRoutineStatus = 0x00;
         u16LocalCurrentDataLength = 0x0000;
      }
   }
   else if( DCM_PENDING == OpStatus )
   {
      /* Analyse des résultats */
      u8LocalReturn =
         DCM_MANU_Checking_Result_Analyse( &u8LocalRoutineStatus,
                                           &u8LocalErrorCode,
                                           &u8LocalOutputParam,
                                           &u16LocalCurrentDataLength );
   }
   else /* DCM_CANCEL == OpStatus */
   {
      u8LocalErrorCode = 0x00;
      u8LocalReturn = E_OK;
      u8LocalRoutineStatus = 0x00;
      u8LocalOutputParam = 0x00;
      u16LocalCurrentDataLength = 0x0000;
   }

   *ErrorCode = u8LocalErrorCode;
   *State_Routine = u8LocalRoutineStatus;
   *Problem_Value = u8LocalOutputParam;
   *currentDataLength = u16LocalCurrentDataLength;

   return u8LocalReturn;
}