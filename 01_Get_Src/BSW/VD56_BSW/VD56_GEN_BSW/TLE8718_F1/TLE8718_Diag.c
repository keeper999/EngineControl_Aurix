/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Diag.c                                                                                  */
/* !Description     : Diagnosis Functions of TLE8718 Component                                                        */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A133946.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Limits.h"
#include "Std_Types.h"

#include "DGOHAL.h"
#include "HOD.h"
#include "Msc_Add_On.h"
#include "SchM_TLE8718.h"
#include "SWFAIL.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

/* !MComment: Check of defines declaration */
#ifndef HOD_coNOTIF_DURING_OVER_CURRENT
   #error The macro-constant HOD_coNOTIF_DURING_OVER_CURRENT shall be defined
#endif
#ifndef TRUE
   #error The macro-constant TRUE shall be defined
#endif

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDiagReqStart                                                                             */
/* !Description : Function to Manage a Tx Request of Diag Sequence                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDiagReqStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_audtMscM_SeqStatus and TLE8718_abMscM_SeqRequest are shared with TLE8718 MscM Layer */
   SchM_Enter_TLE8718_StartDIAG();
   if (  (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_DIAG] == TLE8718_udtSEQ_IDLE)
      && (TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_DIAG]  == FALSE))
   {
      TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_DIAG] = TRUE;
   }
   SchM_Exit_TLE8718_StartDIAG();
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDiagReqNotif                                                                             */
/* !Description : Function Managing Tx Notification of Diag Sequence                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDiagReqNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: Here, it is considered that DIAG sequence is already ended.                                            */ 
   /*          Case MscM_SeqStatus = TLE8718_udtSEQ_RUNNING is not possible.                                          */
   if (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_DIAG] == TLE8718_udtSEQ_SENT_OK)
   {
      /* Decode Diagnosis Registers */
      TLE8718_vidDecodeAllDiagnosisReg(udtInstance);
      /* Update DGOHAL Failures */
      TLE8718_vidUpdateDiagFailures(udtInstance);
   }
   else /* MscM_SeqStatus = TLE8718_udtSEQ_SENT_NOK */
   {
      TLE8718_abMscFailure[udtInstance] = TRUE;
   }

   /* Warning: TLE8718_audtMscM_SeqStatus is shared with TLE8718 MscM Layer                                           */
   /* Protected because this variable is only written if it takes a value different to TLE8718_udtSEQ_IDLE            */
   /* But this case can happen only when the sequence is already ended so the MscM layer will not update again        */
   /* this variable.                                                                                                  */
   TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_DIAG] = TLE8718_udtSEQ_IDLE;
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidReactivationDelayMng                                                                     */
/* !Description : Function to Manage Reactivation Delay Strategies                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidReactivationDelayMng
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   boolean bLocalDataFrameBit;
   uint8   u8LocalBitPosition;
   uint8   u8LocalOutputMode;
   uint8   u8LocalReactivationRemainDelay;
   DGOHAL_tudtChannel udtLocalDgohalChannel;
   HOD_tudtChannel    udtLocalOutCh;

   for (udtLocalOutCh = UINT8_MIN; udtLocalOutCh < TLE8718_udtCHANNEL_NB; udtLocalOutCh ++)
   {
      u8LocalReactivationRemainDelay = TLE8718_au8ReactivRemainDelay[udtInstance][udtLocalOutCh];

      /* !Comment: Reactivation section */
      if (u8LocalReactivationRemainDelay != UINT8_MIN)
      {
         if (u8LocalReactivationRemainDelay != 1u)
         {
            u8LocalReactivationRemainDelay--;
            /* !Comment: The new value of the counter is saved */
            TLE8718_au8ReactivRemainDelay[udtInstance][udtLocalOutCh] = (uint8)u8LocalReactivationRemainDelay;

            #if (HOD_coNOTIF_DURING_OVER_CURRENT == TRUE)
            udtLocalDgohalChannel = TLE8718_kaudtDgohalChannel[udtInstance][udtLocalOutCh];
            DGOHAL_vidWrite(udtLocalDgohalChannel, DGOHAL_bfVALID_SUPPLY, DGOHAL_bfFAULT_SUPPLY);
            #endif /* if (HOD_coNOTIF_DURING_OVER_CURRENT == TRUE) */
         }
         else /* !Comment: Output has to be reactivated */
         {
            if (  TLE8718_au8CmdAuthorized[udtInstance][udtLocalOutCh] == TLE8718_u8CMD_ENABLED)
            {
               u8LocalOutputMode = TLE8718_au8OutputMode[udtInstance][udtLocalOutCh];
               if (u8LocalOutputMode == TLE8718_u8PWM_MODE)
               {
                  TLE8718_audtAppliedDutyCycle[udtInstance][udtLocalOutCh] =
                     TLE8718_audtDutyCycleLastCommand[udtInstance][udtLocalOutCh];
                  u8LocalBitPosition = TLE8718_kau8MscBitPosition[udtLocalOutCh];
                  Msc_vidCfgDataRegBitSrc(TLE8718_kau8Module[udtInstance],
                                          u8LocalBitPosition,
                                          MSC_udtALTINL_INVERTED_SRC);
               }
               else
               {
                  if (u8LocalOutputMode == TLE8718_u8DIO_MODE)
                  {
                     if (TLE8718_abDioLastCommand[udtInstance][udtLocalOutCh] == STD_ON)
                     {
                        TLE8718_abDioAppliedState[udtInstance][udtLocalOutCh] = STD_ON;
                        bLocalDataFrameBit = TLE8718_kabDataFrameBit[udtLocalOutCh];
                        if (bLocalDataFrameBit != FALSE) /* channel in data frame */
                        {
                           TLE8718_vidSetDataOutputState(udtInstance, udtLocalOutCh, STD_ON);
                        }
                        else /* channel in command frame */
                        {
                           TLE8718_abWrOut1516ReqStartEvent[udtInstance] = TRUE;
                        }
                     }
                  }
                  else /* (TLE8718_au8OutputMode[udtInstance][udtLocalOutCh] == TLE8718_u8CDD_MODE) */
                  {
                     u8LocalBitPosition = TLE8718_kau8MscBitPosition[udtLocalOutCh];
                     Msc_vidCfgDataRegBitSrc(TLE8718_kau8Module[udtInstance],
                                             u8LocalBitPosition,
                                             MSC_udtALTINL_INVERTED_SRC);
                  }
               }
               TLE8718_au8ReactivRemainDelay[udtInstance][udtLocalOutCh] = UINT8_MIN;
            }
            else
            {
               /* !Comment: When the command is cut off from a destructive fault, a SCW failure is raised whatever    */
               /*           the last command is.                                                                      */
               if (  (TLE8718_au8CmdAuthorized[udtInstance][udtLocalOutCh] & TLE8718_u8CMD_DISA_DESTRUCT_FLT)
                  == TLE8718_u8CMD_DISA_DESTRUCT_FLT)
               {
                  udtLocalDgohalChannel = TLE8718_kaudtDgohalChannel[udtInstance][udtLocalOutCh];
                  DGOHAL_vidWrite(udtLocalDgohalChannel, DGOHAL_bfVALID_SUPPLY, DGOHAL_bfFAULT_SUPPLY);
                  /* !Comment: The counter is rearmed with TLE8718_kau8ReactivationDelay[udtInstance][udtChannel] + 1 */
                  /*           to raise the failure as if the signal is restarted                                     */
                  TLE8718_au8ReactivRemainDelay[udtInstance][udtLocalOutCh]
                     = TLE8718_kau8ReactivationDelay[udtInstance][udtLocalOutCh] + 1u;
               }
               else
               {
                  TLE8718_au8ReactivRemainDelay[udtInstance][udtLocalOutCh] = UINT8_MIN;
               }
            }
         }
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidShortCircProtection                                                                      */
/* !Description : Short Circuit Proptection                                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidShortCircProtection
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel    /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
)
{
   boolean bLocalDataFrameBit;
   uint8   u8LocalBitPosition;
   uint8   u8LocalOutputMode;
   uint8   u8LocalShortCircuitCounter;

   u8LocalShortCircuitCounter = TLE8718_au8ShortCircuitCounter[udtInstance][udtChannel];

   if (u8LocalShortCircuitCounter == UINT8_MIN)
   {
      u8LocalShortCircuitCounter = TLE8718_kau8ShortCircuitDetectNb[udtInstance][udtChannel];
   }
   else
   {
      u8LocalShortCircuitCounter--;
   }

   if (u8LocalShortCircuitCounter == UINT8_MIN)
   {
      TLE8718_au8ReactivRemainDelay[udtInstance][udtChannel] = TLE8718_kau8ReactivationDelay[udtInstance][udtChannel];

      u8LocalOutputMode = TLE8718_au8OutputMode[udtInstance][udtChannel];
      if (u8LocalOutputMode == TLE8718_u8DIO_MODE)
      {
         bLocalDataFrameBit = TLE8718_kabDataFrameBit[udtChannel];
         TLE8718_abDioAppliedState[udtInstance][udtChannel] = STD_OFF;

         if (bLocalDataFrameBit != FALSE) /* channel commanded in data frame */
         {
            TLE8718_vidSetDataOutputState(udtInstance, udtChannel, STD_OFF);
         }
         else /* channel commanded in command frame */
         {
            TLE8718_abWrOut1516ReqStartEvent[udtInstance] = TRUE;
         }
      }
      else
      {
         if (u8LocalOutputMode == TLE8718_u8PWM_MODE)
         {
            TLE8718_audtAppliedDutyCycle[udtInstance][udtChannel] = TLE8718_udtDUTY_MIN;
         }
         else /* (TLE8718_au8OutputMode[udtInstance][udtChannel] == TLE8718_u8CDD_MODE) */
         {
            TLE8718_abDioAppliedState[udtInstance][udtChannel] = STD_OFF;
         }
         TLE8718_vidSetDataOutputState(udtInstance, udtChannel, STD_OFF);
         u8LocalBitPosition = TLE8718_kau8MscBitPosition[udtChannel];
         Msc_vidCfgDataRegBitSrc(TLE8718_kau8Module[udtInstance], u8LocalBitPosition, MSC_udtDATA_REG_SRC);
      }
   }
   TLE8718_au8ShortCircuitCounter[udtInstance][udtChannel] = (uint8)u8LocalShortCircuitCounter;
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidUpdateDiagFailures                                                                       */
/* !Description : Update of Diagnosis Failures                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidUpdateDiagFailures
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   uint8              u8LocalDiagOutput;
   HOD_tudtChannel    udtLocalChannel;
   DGOHAL_tudtChannel udtLocalDgohalChannel;

   if (  (  (TLE8718_abOutputStandByActive[udtInstance] != FALSE)
         && (TLE8718_aenuState[udtInstance] == TLE8718_STATE_RUNNING)) /* Stand By Mode is allowed in INIT phase */
      || (TLE8718_abMscMonTimeoutDetected[udtInstance] != FALSE)
      || (TLE8718_abPowerOnResetDetected[udtInstance]  != FALSE)
      || (TLE8718_abAbeInactive[udtInstance]           == FALSE))
   {
      TLE8718_abMajorFailureDetected[udtInstance] = TRUE;
   }

   for (udtLocalChannel = 0u; udtLocalChannel < TLE8718_udtCHANNEL_NB; udtLocalChannel++)
   {
      udtLocalDgohalChannel = TLE8718_kaudtDgohalChannel[udtInstance][udtLocalChannel];
      u8LocalDiagOutput     = TLE8718_au8DiagOutput[udtInstance][udtLocalChannel];

      if (u8LocalDiagOutput == TLE8718_u8POWER_STAGE_OK)
      {
/*       u8LocalOutputMode = TLE8718_au8OutputMode[udtInstance][udtLocalChannel];
         if (u8LocalOutputMode == TLE8718_u8PWM_MODE)
         {
            if (TLE8718_audtAppliedDutyCycle[udtInstance][udtLocalChannel] < TLE8718_udtDUTY_DIAG_MIN)
            {
               DGOHAL_vidWrite(udtLocalDgohalChannel,
                               DGOHAL_bfVALID_OPEN    | DGOHAL_bfVALID_GROUND,
                               DGOHAL_bfNO_FAULT_OPEN | DGOHAL_bfNO_FAULT_GROUND);
            }
            else
            {
               if (TLE8718_audtAppliedDutyCycle[udtInstance][udtLocalChannel] > TLE8718_udtDUTY_DIAG_MAX)
               {
                  DGOHAL_vidWrite(udtLocalDgohalChannel,
                                  DGOHAL_bfVALID_SUPPLY,
                                  DGOHAL_bfNO_FAULT_SUPPLY);
               }
               else
               {*/
                  /* We consider that Diagnosis period is greater than all PWM periods */
                  DGOHAL_vidWrite(udtLocalDgohalChannel,
                                  DGOHAL_bfVALID_SUPPLY    | DGOHAL_bfVALID_OPEN    | DGOHAL_bfVALID_GROUND,
                                  DGOHAL_bfNO_FAULT_SUPPLY | DGOHAL_bfNO_FAULT_OPEN | DGOHAL_bfNO_FAULT_GROUND);
/*               }
            }
         }
         else*/ /* TLE8718_au8OutputMode[udtInstance][udtLocalChannel] = TLE8718_u8DIO_MODE or TLE8718_u8CDD_MODE */
/*       {
            if (TLE8718_abDioAppliedState[udtInstance][udtLocalChannel] == STD_OFF)
            {
               DGOHAL_vidWrite(udtLocalDgohalChannel,
                               DGOHAL_bfVALID_OPEN    | DGOHAL_bfVALID_GROUND,
                               DGOHAL_bfNO_FAULT_OPEN | DGOHAL_bfNO_FAULT_GROUND);
            }
            else
            {
               DGOHAL_vidWrite(udtLocalDgohalChannel,
                               DGOHAL_bfVALID_SUPPLY,
                               DGOHAL_bfNO_FAULT_SUPPLY);
            }
         }*/
      }
      else
      {
         switch (u8LocalDiagOutput)
         {
            case TLE8718_u8SCB_OR_DOT:
               TLE8718_vidShortCircProtection(udtInstance, udtLocalChannel);
               DGOHAL_vidWrite(udtLocalDgohalChannel,
                               DGOHAL_bfVALID_SUPPLY,
                               DGOHAL_bfFAULT_SUPPLY);
               break;

            case TLE8718_u8OL:
               DGOHAL_vidWrite(udtLocalDgohalChannel,
                               DGOHAL_bfVALID_OPEN,
                               DGOHAL_bfFAULT_OPEN);
               break;

            case TLE8718_u8SCG:
               DGOHAL_vidWrite(udtLocalDgohalChannel,
                               DGOHAL_bfVALID_GROUND,
                               DGOHAL_bfFAULT_GROUND);
               break;

            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
      }
   }
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
