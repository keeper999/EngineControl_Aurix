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
/* !File            : Dlt_RoutineControl_API9.C                               */
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
/*   1 / DLT_StartRoutine_DF36                                                */
/*   2 / DLT_RequestResult_DF36                                               */
/*   3 / DLT_StartRoutine_DF37                                                */
/*   4 / DLT_RequestResult_DF37                                               */
/*   5 / DLT_StartRoutine_DFA2                                                */
/*   6 / DLT_StartRoutine_DF38                                                */
/*   7 / DLT_RequestResult_DF38                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5074350 / 5                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dlt$*/
/* $Revision::   1.1      $$Author::   pbakabad       $$Date::   27 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   27 May 2014 $*/
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
/* !Function    :  DLT_StartRoutine_DF36                                      */
/* !Description :  Is called from Dcm when RID service sub function 01 is     */
/*                 received.                                                  */
/* !Number      :  RC_API10.1                                                 */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstReqStcBatt;                                       */
/*  input boolean Srv_bRcStart_RstReqStcBatt;                                 */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input boolean Srv_bRcCondOk_RstReqStcBatt;                                */
/*  input boolean Srv_bRcCom_RstReqStcBatt;                                   */
/*  input boolean Srv_bRcCdnOk_RstReqStcBatt;                                 */
/*  input boolean Srv_bRcCdnNok_RstReqStcBatt;                                */
/*  input boolean Srv_bRcReq_RstReqStcBatt;                                   */
/*  input boolean Srv_bRcStop_RstReqStcBatt;                                  */
/*  input ???? DCM_MANU_RcAcv_RstReqStcBatt;                                  */
/*  input ???? DCM_MANU_CheckCond4RstReqStcBatt;                              */
/*  input ???? DCM_MANU_RcCdn_RstReqStcBatt;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF36
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstReqStcBatt,
                                       &Srv_bRcStart_RstReqStcBatt,
                                       &Srv_stRcEnd_RstReqStcBatt,
                                       &Srv_bRcCondOk_RstReqStcBatt,
                                       /* Srv_bRcSho_IniRealTiTroCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstReqStcBatt,
                                       &Srv_bRcCdnOk_RstReqStcBatt,
                                       &Srv_bRcCdnNok_RstReqStcBatt,
                                       &Srv_bRcReq_RstReqStcBatt,
                                       &Srv_bRcStop_RstReqStcBatt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstReqStcBatt,
                                       DCM_MANU_CheckCond4RstReqStcBatt,
                                       DCM_MANU_RcCdn_RstReqStcBatt);
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
/* !Function    :  DLT_RequestResult_DF36                                     */
/* !Description :  Is called from Dcm when RID service sub function 03 is     */
/*                 received.                                                  */
/* !Number      :  RC_API10.2                                                 */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstReqStcBatt;                                       */
/*  input boolean Srv_bRcStart_RstReqStcBatt;                                 */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input boolean Srv_bRcCondOk_RstReqStcBatt;                                */
/*  input boolean Srv_bRcCom_RstReqStcBatt;                                   */
/*  input boolean Srv_bRcCdnOk_RstReqStcBatt;                                 */
/*  input boolean Srv_bRcCdnNok_RstReqStcBatt;                                */
/*  input boolean Srv_bRcReq_RstReqStcBatt;                                   */
/*  input boolean Srv_bRcStop_RstReqStcBatt;                                  */
/*  input ???? DCM_MANU_RcAcv_RstReqStcBatt;                                  */
/*  input ???? DCM_MANU_CheckCond4RstReqStcBatt;                              */
/*  input ???? DCM_MANU_RcCdn_RstReqStcBatt;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF36
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstReqStcBatt,
                                       &Srv_bRcStart_RstReqStcBatt,
                                       &Srv_stRcEnd_RstReqStcBatt,
                                       &Srv_bRcCondOk_RstReqStcBatt,
                                       /* Srv_bRcSho_IniRealTiTroCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstReqStcBatt,
                                       &Srv_bRcCdnOk_RstReqStcBatt,
                                       &Srv_bRcCdnNok_RstReqStcBatt,
                                       &Srv_bRcReq_RstReqStcBatt,
                                       &Srv_bRcStop_RstReqStcBatt,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstReqStcBatt,
                                       DCM_MANU_CheckCond4RstReqStcBatt,
                                       DCM_MANU_RcCdn_RstReqStcBatt);
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
/* !Function    :  DLT_StartRoutine_DF37                                      */
/* !Description :  Is called from Dcm when RID service sub function 01 is     */
/*                 received.                                                  */
/* !Number      :  RC_API10.3                                                 */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  input uint8 Srv_stRc_RstLrn_Misf;                                         */
/*  input boolean Srv_bRcStart_RstLrn_Misf;                                   */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*  input boolean Srv_bRcCondOk_RstLrn_Misf;                                  */
/*  input boolean Srv_bRcCom_RstLrn_Misf;                                     */
/*  input boolean Srv_bRcCdnOk_RstLrn_Misf;                                   */
/*  input boolean Srv_bRcCdnNok_RstLrn_Misf;                                  */
/*  input boolean Srv_bRcReq_RstLrn_Misf;                                     */
/*  input boolean Srv_bRcStop_RstLrn_Misf;                                    */
/*  input ???? DCM_MANU_RcAcv_RstLrn_Misf;                                    */
/*  input ???? DCM_MANU_CheckCond4RstLrn_Misf;                                */
/*  input ???? DCM_MANU_RcCdn_RstLrn_Misf;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DF37
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
            DCM_MANU_StartRoutineDmnd( &Srv_stRc_RstLrn_Misf,
                                       &Srv_bRcStart_RstLrn_Misf,
                                       &Srv_stRcEnd_RstLrn_Misf,
                                       &Srv_bRcCondOk_RstLrn_Misf,
                                       /* Srv_bRcSho_IniRealTiTroCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstLrn_Misf,
                                       &Srv_bRcCdnOk_RstLrn_Misf,
                                       &Srv_bRcCdnNok_RstLrn_Misf,
                                       &Srv_bRcReq_RstLrn_Misf,
                                       &Srv_bRcStop_RstLrn_Misf,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstLrn_Misf,
                                       DCM_MANU_CheckCond4RstLrn_Misf,
                                       DCM_MANU_RcCdn_RstLrn_Misf);
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
/* !Function    :  DLT_RequestResult_DF37                                     */
/* !Description :  Is called from Dcm when RID service sub function 03 is     */
/*                 received.                                                  */
/* !Number      :  RC_API10.4                                                 */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_ReqResRoutineDmnd(????);                                    */
/*  input uint8 Srv_stRc_RstLrn_Misf;                                         */
/*  input boolean Srv_bRcStart_RstLrn_Misf;                                   */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*  input boolean Srv_bRcCondOk_RstLrn_Misf;                                  */
/*  input boolean Srv_bRcCom_RstLrn_Misf;                                     */
/*  input boolean Srv_bRcCdnOk_RstLrn_Misf;                                   */
/*  input boolean Srv_bRcCdnNok_RstLrn_Misf;                                  */
/*  input boolean Srv_bRcReq_RstLrn_Misf;                                     */
/*  input boolean Srv_bRcStop_RstLrn_Misf;                                    */
/*  input ???? DCM_MANU_RcAcv_RstLrn_Misf;                                    */
/*  input ???? DCM_MANU_CheckCond4RstLrn_Misf;                                */
/*  input ???? DCM_MANU_RcCdn_RstLrn_Misf;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_RequestResult_DF37
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
            DCM_MANU_ReqResRoutineDmnd( &Srv_stRc_RstLrn_Misf,
                                       &Srv_bRcStart_RstLrn_Misf,
                                       &Srv_stRcEnd_RstLrn_Misf,
                                       &Srv_bRcCondOk_RstLrn_Misf,
                                       /* Srv_bRcSho_IniRealTiTroCnt */
                                       FALSE,
                                       &Srv_bRcCom_RstLrn_Misf,
                                       &Srv_bRcCdnOk_RstLrn_Misf,
                                       &Srv_bRcCdnNok_RstLrn_Misf,
                                       &Srv_bRcReq_RstLrn_Misf,
                                       &Srv_bRcStop_RstLrn_Misf,
                                       &u8LocalErrorCode,
                                       &u8LocalRoutineStatus,
                                       DCM_MANU_RcAcv_RstLrn_Misf,
                                       DCM_MANU_CheckCond4RstLrn_Misf,
                                       DCM_MANU_RcCdn_RstLrn_Misf);
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
/* !Function    :  DLT_StartRoutine_DFA2                                      */
/* !Description :  Is called from Dcm when RID service sub function 01 is     */
/*                 received.                                                  */
/* !Number      :  RC_API9.5                                                  */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf DCM_MANU_StartRoutineDmnd(????);                                     */
/*  extf argret void DCM_MANU_EveRC_SdlMid();                                 */
/*  input uint8 Srv_stRc_InhBoostGDI;                                         */
/*  input boolean Srv_bRcStart_InhBoostGDI;                                   */
/*  input uint8 Srv_stRcEnd_InhBoostGDI;                                      */
/*  input boolean Srv_bRcCondOk_InhBoostGDI;                                  */
/*  input boolean Srv_bRcCom_InhBoostGDI;                                     */
/*  input boolean Srv_bRcCdnOk_InhBoostGDI;                                   */
/*  input boolean Srv_bRcCdnNok_InhBoostGDI;                                  */
/*  input boolean Srv_bRcReq_InhBoostGDI;                                     */
/*  input boolean Srv_bRcStop_InhBoostGDI;                                    */
/*  input ???? DCM_MANU_RcAcv_InhBoostGDI;                                    */
/*  input ???? DCM_MANU_CheckCond4InhBoostGDI;                                */
/*  input ???? DCM_MANU_RcCdn_InhBoostGDI;                                    */
/*  output uint8 DCM_MANU_Cntrl_Inhibition;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
Std_ReturnType DLT_StartRoutine_DFA2
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
                  DCM_MANU_StartRoutineDmnd( &Srv_stRc_InhBoostGDI,
                                             &Srv_bRcStart_InhBoostGDI,
                                             &Srv_stRcEnd_InhBoostGDI,
                                             &Srv_bRcCondOk_InhBoostGDI,
                                             /* Srv_bRcSho_InhBoostGDI */
                                             TRUE,
                                             &Srv_bRcCom_InhBoostGDI,
                                             &Srv_bRcCdnOk_InhBoostGDI,
                                             &Srv_bRcCdnNok_InhBoostGDI,
                                             &Srv_bRcReq_InhBoostGDI,
                                             &Srv_bRcStop_InhBoostGDI,
                                             &u8LocalErrorCode,
                                             &u8LocalRoutineStatus,
                                             DCM_MANU_RcAcv_InhBoostGDI,
                                             DCM_MANU_CheckCond4InhBoostGDI,
                                             DCM_MANU_RcCdn_InhBoostGDI);
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
   *State_Routine= u8LocalRoutineStatus;

   /* F12_Gene_event_InhBoostGDI */
   DCM_MANU_EveRC_SdlMid();

   return u8LocalReturn;
}


