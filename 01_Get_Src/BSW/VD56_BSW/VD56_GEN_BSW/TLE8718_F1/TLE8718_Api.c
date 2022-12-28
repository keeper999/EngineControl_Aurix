/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_API.c                                                                                   */
/* !Description     : APIs of TLE8718 Component                                                                       */
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
 * %PID: P2017_BSW:0A133950.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"

#include "Dio.h"
#include "HOD.h"
#include "Msc.h"
#include "Msc_Add_On.h"
#include "Pwm.h"
#include "SchM_TLE8718.h"
#include "SWFAIL.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidInit                                                                                     */
/* !Description : Initializes all internal TLE8718 variables.                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidInit(void)
{
   HOD_tudtInstance udtLocalInstance;
   HOD_tudtChannel  udtLocalChannel;

   for (udtLocalInstance = 0u; udtLocalInstance < TLE8718_udtINSTANCE_NB; udtLocalInstance++)
   {
      TLE8718_vidDISA_TLE8718(udtLocalInstance);

      TLE8718_abAbeInactive[udtLocalInstance]            = FALSE;
      TLE8718_abBattOverVoltDetected[udtLocalInstance]   = FALSE;
      TLE8718_abDelayInActive[udtLocalInstance]          = FALSE;
      TLE8718_abDiagReqStartEvent[udtLocalInstance]      = FALSE;
      TLE8718_abDisOutputs5_10_Active[udtLocalInstance]  = FALSE;
      TLE8718_abDisOutputs15_16_Active[udtLocalInstance] = FALSE;
      TLE8718_abFactoryTestDisabled[udtLocalInstance]    = FALSE;
      TLE8718_abFailureDetected[udtLocalInstance]        = FALSE;
      TLE8718_abIdentRegAvailable[udtLocalInstance]      = FALSE;
      TLE8718_abMajorFailureDetected[udtLocalInstance]   = FALSE;
      TLE8718_abMscMonTimeoutDetected[udtLocalInstance]  = FALSE;
      TLE8718_abOut15LevelOnApplied[udtLocalInstance]    = FALSE;
      TLE8718_abOut16LevelOnApplied[udtLocalInstance]    = FALSE;
      TLE8718_abOutputStandByActive[udtLocalInstance]    = FALSE;
      TLE8718_abOverTempDetected[udtLocalInstance]       = FALSE;
      TLE8718_abPowerOnResetDetected[udtLocalInstance]   = FALSE;
      TLE8718_abReactDelayMngEvent[udtLocalInstance]     = FALSE;
      TLE8718_abReverseCurrentDetected[udtLocalInstance] = FALSE;
      TLE8718_abSafetyReqStartEvent[udtLocalInstance]    = FALSE;
      TLE8718_abVDD_MonitorTestActive[udtLocalInstance]  = FALSE;
      TLE8718_abVDD_OverVoltDetected[udtLocalInstance]   = FALSE;
      TLE8718_abVDD_UnderVoltDetected[udtLocalInstance]  = FALSE;
      TLE8718_abWrOut1516ReqStartEvent[udtLocalInstance] = FALSE;

      TLE8718_aenuState[udtLocalInstance]      = TLE8718_STATE_UNINIT;
      TLE8718_au32DataOutput[udtLocalInstance] = UINT32_MAX;

      for (udtLocalChannel = 0u; udtLocalChannel < TLE8718_udtCHANNEL_NB; udtLocalChannel++)
      {
         TLE8718_abDioAppliedState[udtLocalInstance][udtLocalChannel]        = STD_OFF;
         TLE8718_abDioLastCommand[udtLocalInstance][udtLocalChannel]         = STD_OFF;
         TLE8718_audtAppliedDutyCycle[udtLocalInstance][udtLocalChannel]     = TLE8718_udtDUTY_MIN;
         TLE8718_audtDutyCycleLastCommand[udtLocalInstance][udtLocalChannel] = TLE8718_udtDUTY_MIN;
         TLE8718_audtRequestedPeriod[udtLocalInstance][udtLocalChannel]      = UINT8_MIN;
         TLE8718_au8ReactivRemainDelay[udtLocalInstance][udtLocalChannel]    = UINT8_MIN;
         TLE8718_au8ShortCircuitCounter[udtLocalInstance][udtLocalChannel]   = UINT8_MIN;
         TLE8718_au8CmdAuthorized[udtLocalInstance][udtLocalChannel]         = TLE8718_u8CMD_DISA_WITHOUT_FLT;
         TLE8718_au8DiagOutput[udtLocalInstance][udtLocalChannel]            = TLE8718_u8POWER_STAGE_OK;
         TLE8718_au8OutputMode[udtLocalInstance][udtLocalChannel] =
            TLE8718_kau8OutputMode[udtLocalInstance][udtLocalChannel];              
      }
      TLE8718_au8ConReg1[udtLocalInstance]    = UINT8_MIN;
      TLE8718_au8ConReg2[udtLocalInstance]    = UINT8_MIN;
      TLE8718_au8ConReg3[udtLocalInstance]    = UINT8_MIN;
      TLE8718_au8ConReg4[udtLocalInstance]    = UINT8_MIN;
      TLE8718_au8DiagReg1[udtLocalInstance]   = UINT8_MIN;
      TLE8718_au8DiagReg2[udtLocalInstance]   = UINT8_MIN;
      TLE8718_au8DiagReg3[udtLocalInstance]   = UINT8_MIN;
      TLE8718_au8DiagReg4[udtLocalInstance]   = UINT8_MIN;
      TLE8718_au8DiagReg5[udtLocalInstance]   = UINT8_MIN;
      TLE8718_au8DiagReg6[udtLocalInstance]   = UINT8_MIN;
      TLE8718_au8DiagReg7[udtLocalInstance]   = UINT8_MIN;
      TLE8718_au8IdentReg[udtLocalInstance]   = UINT8_MIN;
      TLE8718_au8Out1516Reg[udtLocalInstance] = UINT8_MIN;
   }
   TLE8718_vidMscM_Init();
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnable                                                                                   */
/* !Description : Function to Enable TLE8718 component                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidEnable
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   if (udtInstance < TLE8718_udtINSTANCE_NB)
   {
      if (TLE8718_aenuState[udtInstance] == TLE8718_STATE_UNINIT)
      {
         Msc_SelectRxDevice(TLE8718_kau8Module[udtInstance], TLE8718_kaudtRxDevice[udtInstance]);
         Msc_ChangeTxState(TLE8718_kau8Module[udtInstance], MSC_TX_ON);
         Msc_TxDataFrame(TLE8718_kau8Module[udtInstance],
                         TLE8718_kaudtTxDevice[udtInstance],
                         TLE8718_kaudtTxDevice[udtInstance],
                         &TLE8718_au32DataOutput[udtInstance]);

         TLE8718_vidENA_TLE8718(udtInstance);

         TLE8718_vidEnterInInitReadyState(udtInstance);
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnableCmd                                                                                */
/* !Description : Function to Enable the Command of Channel                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidEnableCmd
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel,   /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
   HOD_tenuCutMode  enuCutMode   /* !Comment: Mode available                                */
                                 /* !Range  : List of the enum mode                         */
)
{
   boolean bLocalDataFrameBit;
   boolean bLocalState;
   uint8   u8LocalBitPosition;
   uint8   u8LocalOutputMode;
   uint32  u32LocalDataOutput;

   if ((udtInstance < TLE8718_udtINSTANCE_NB) && (udtChannel < TLE8718_udtCHANNEL_NB))
   {
      switch (enuCutMode)
      {
         case HOD_CUT_OFF_WITHOUT_FAULT:
            TLE8718_au8CmdAuthorized[udtInstance][udtChannel] =
               (uint8)( TLE8718_au8CmdAuthorized[udtInstance][udtChannel]
                      & (~TLE8718_u8CMD_DISA_WITHOUT_FLT));
            break;

         case HOD_CUT_OFF_WITH_DESTRUCTIVE_FAULT:
            TLE8718_au8CmdAuthorized[udtInstance][udtChannel] =
               (uint8)( TLE8718_au8CmdAuthorized[udtInstance][udtChannel]
                      & (~TLE8718_u8CMD_DISA_DESTRUCT_FLT));
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }

      if (  (TLE8718_au8ReactivRemainDelay[udtInstance][udtChannel] == UINT8_MIN)
         && (TLE8718_au8CmdAuthorized[udtInstance][udtChannel] == TLE8718_u8CMD_ENABLED))
      {
         u8LocalBitPosition = TLE8718_kau8MscBitPosition[udtChannel];
         u8LocalOutputMode  = TLE8718_au8OutputMode[udtInstance][udtChannel];
         if (u8LocalOutputMode == TLE8718_u8PWM_MODE)
         {
            TLE8718_audtAppliedDutyCycle[udtInstance][udtChannel] =
               TLE8718_audtDutyCycleLastCommand[udtInstance][udtChannel];
            Msc_vidCfgDataRegBitSrc(TLE8718_kau8Module[udtInstance],
                                    u8LocalBitPosition,
                                    MSC_udtALTINL_INVERTED_SRC);
         }
         else
         {
            bLocalState = TLE8718_abDioLastCommand[udtInstance][udtChannel];
            TLE8718_abDioAppliedState[udtInstance][udtChannel] = bLocalState;

            if (u8LocalOutputMode == TLE8718_u8CDD_MODE)
            {
               Msc_vidCfgDataRegBitSrc(TLE8718_kau8Module[udtInstance],
                                       u8LocalBitPosition,
                                       MSC_udtALTINL_INVERTED_SRC);
            }
            else /* TLE8718_au8OutputMode[udtInstance][udtChannel] == TLE8718_u8DIO_MODE */
            {
               bLocalDataFrameBit = TLE8718_kabDataFrameBit[udtChannel];

               if (bLocalDataFrameBit != FALSE) /* channel commanded in data frame */
               {
                  SchM_Enter_TLE8718_WriteDataReg();
                  u32LocalDataOutput = TLE8718_au32DataOutput[udtInstance] & (~(1u << u8LocalBitPosition));
                  TLE8718_au32DataOutput[udtInstance] = u32LocalDataOutput | ((!bLocalState) << u8LocalBitPosition);
                  SchM_Exit_TLE8718_WriteDataReg();
                  /* If MSC API is called whereas MSC Tx is not initialized (in TLE8718_vidEnable API) then a Det error is raised */
                  if (TLE8718_aenuState[udtInstance] != TLE8718_STATE_UNINIT)
                  {
                     Msc_TxDataFrame(TLE8718_kau8Module[udtInstance],
                                     TLE8718_kaudtTxDevice[udtInstance],
                                     TLE8718_kaudtTxDevice[udtInstance],
                                     &TLE8718_au32DataOutput[udtInstance]);
                  }
               }
               else /* channel commanded in command frame */
               {
                  TLE8718_abWrOut1516ReqStartEvent[udtInstance] = TRUE;
               }
            }
         }
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDisableCmd                                                                               */
/* !Description : Function to Disable the Command of Channel                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDisableCmd
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel,   /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
   HOD_tenuCutMode  enuCutMode   /* !Comment: Mode available                                */
                                 /* !Range  : List of the enum mode                         */
)
{
   boolean bLocalDataFrameBit;
   uint8   u8LocalBitPosition;
   uint8   u8LocalOutputMode;

   if ((udtInstance < TLE8718_udtINSTANCE_NB) && (udtChannel < TLE8718_udtCHANNEL_NB))
   {
      switch (enuCutMode)
      {
         case HOD_CUT_OFF_WITHOUT_FAULT:
            TLE8718_au8CmdAuthorized[udtInstance][udtChannel] =
               (uint8)( TLE8718_au8CmdAuthorized[udtInstance][udtChannel] | TLE8718_u8CMD_DISA_WITHOUT_FLT);
            break;

         case HOD_CUT_OFF_WITH_DESTRUCTIVE_FAULT:
            TLE8718_au8CmdAuthorized[udtInstance][udtChannel] =
               (uint8)( TLE8718_au8CmdAuthorized[udtInstance][udtChannel] | TLE8718_u8CMD_DISA_DESTRUCT_FLT);

            if (  TLE8718_au8ReactivRemainDelay[udtInstance][udtChannel] == UINT8_MIN)
            {
               TLE8718_au8ReactivRemainDelay[udtInstance][udtChannel] =
                  (uint8)(TLE8718_kau8ReactivationDelay[udtInstance][udtChannel] + 1u);
            }
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }

      u8LocalOutputMode = TLE8718_au8OutputMode[udtInstance][udtChannel];

      if ((u8LocalOutputMode == TLE8718_u8PWM_MODE) || (u8LocalOutputMode == TLE8718_u8CDD_MODE))
      {
         /* !Comment: No need to clear output state in Data Frame Register because it was already cleared in init and */
         /*           was never set.                                                                                  */
         u8LocalBitPosition = TLE8718_kau8MscBitPosition[udtChannel];
         Msc_vidCfgDataRegBitSrc(TLE8718_kau8Module[udtInstance],
                                 u8LocalBitPosition,
                                 MSC_udtDATA_REG_SRC);
         TLE8718_audtAppliedDutyCycle[udtInstance][udtChannel] = TLE8718_udtDUTY_MIN;
      }
      else /* TLE8718_au8OutputMode[udtInstance][udtChannel] = TLE8718_u8DIO_MODE */
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
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead                                                                                    */
/* !Description : Function to Read the State of Specified DIO Channel                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel    /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
)
{
   boolean bLocalState;

   if (  (udtInstance < TLE8718_udtINSTANCE_NB)
      && (udtChannel < TLE8718_udtCHANNEL_NB)
      && (TLE8718_au8OutputMode[udtInstance][udtChannel] == TLE8718_u8DIO_MODE))
   {
      bLocalState = TLE8718_abDioAppliedState[udtInstance][udtChannel];
   }
   else
   {
      bLocalState = STD_OFF;
      SWFAIL_vidSoftwareErrorHook();
   }

   return(bLocalState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite                                                                                 */
/* !Description : Function to Write the State of Specified DIO Channel                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel,   /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
   boolean bState                /* !Comment: command to apply to the channel               */
                                 /* !Range  : STD_ON / STD_OFF                              */
)
{
   boolean bLocalDataFrameBit;
   uint8   u8LocalReactivationRemainDelay;

   if (  (udtInstance < TLE8718_udtINSTANCE_NB)
      && (udtChannel < TLE8718_udtCHANNEL_NB)
      && (TLE8718_au8OutputMode[udtInstance][udtChannel] == TLE8718_u8DIO_MODE))
   {
      SchM_Enter_TLE8718_DioWrite();
      u8LocalReactivationRemainDelay = TLE8718_au8ReactivRemainDelay[udtInstance][udtChannel];

      if (  (u8LocalReactivationRemainDelay == UINT8_MIN)
         && (TLE8718_au8CmdAuthorized[udtInstance][udtChannel] == TLE8718_u8CMD_ENABLED))
      {
         bLocalDataFrameBit = TLE8718_kabDataFrameBit[udtChannel];
         TLE8718_abDioAppliedState[udtInstance][udtChannel] = bState;

         if (bLocalDataFrameBit != FALSE) /* channel commanded in data frame */
         {
            TLE8718_vidSetDataOutputState(udtInstance, udtChannel, bState);
         }
         else /* channel commanded in command frame */
         {
            TLE8718_abWrOut1516ReqStartEvent[udtInstance] = TRUE;
         }
         SchM_Exit_TLE8718_DioWrite();
      }
      else
      {
         SchM_Exit_TLE8718_DioWrite();
      }
      TLE8718_abDioLastCommand[udtInstance][udtChannel] = bState;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidPwmWriteDutyCycle                                                                        */
/* !Description : Function to Write Duty Cycle of Specified PWM Channel                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidPwmWriteDutyCycle
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel,   /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
   HOD_tudtDutyCycle udtDutyCycle
)
{
   Pwm_ChannelType udtLocalPwmChannel;
   uint8 u8LocalReactivationRemainDelay;

   if (  (udtInstance < TLE8718_udtINSTANCE_NB)
      && (udtChannel < TLE8718_udtCHANNEL_NB)
      && (TLE8718_au8OutputMode[udtInstance][udtChannel] == TLE8718_u8PWM_MODE))
   {
      udtLocalPwmChannel = TLE8718_kaudtPwmChannel[udtInstance][udtChannel];
      Pwm_SetDutyCycle(udtLocalPwmChannel, (uint32)udtDutyCycle);
      u8LocalReactivationRemainDelay = TLE8718_au8ReactivRemainDelay[udtInstance][udtChannel];
      if (  (u8LocalReactivationRemainDelay == UINT8_MIN)
         && (TLE8718_au8CmdAuthorized[udtInstance][udtChannel] == TLE8718_u8CMD_ENABLED))
      {
         TLE8718_audtAppliedDutyCycle[udtInstance][udtChannel]  = udtDutyCycle;
      }
      TLE8718_audtDutyCycleLastCommand[udtInstance][udtChannel] = udtDutyCycle;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidPwmWritePeriodAndDuty                                                                    */
/* !Description : Function to Write Period and Duty of Specified PWM Channel                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidPwmWritePeriodAndDuty
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel,   /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
   HOD_tudtPeriod    udtPeriod,
   HOD_tudtDutyCycle udtDutyCycle
)
{
   Pwm_ChannelType udtLocalPwmChannel;
   uint8 u8LocalReactivationRemainDelay;

   if (  (udtInstance < TLE8718_udtINSTANCE_NB)
      && (udtChannel < TLE8718_udtCHANNEL_NB)
      && (TLE8718_au8OutputMode[udtInstance][udtChannel] == TLE8718_u8PWM_MODE))
   {
      udtLocalPwmChannel = TLE8718_kaudtPwmChannel[udtInstance][udtChannel];
      Pwm_SetPeriodAndDuty(udtLocalPwmChannel, (Pwm_PeriodType)udtPeriod, (uint32)udtDutyCycle);
      u8LocalReactivationRemainDelay = TLE8718_au8ReactivRemainDelay[udtInstance][udtChannel];
      if (  (u8LocalReactivationRemainDelay == UINT8_MIN)
         && (TLE8718_au8CmdAuthorized[udtInstance][udtChannel] == TLE8718_u8CMD_ENABLED))
      {
         TLE8718_audtAppliedDutyCycle[udtInstance][udtChannel]  = udtDutyCycle;
      }
      TLE8718_audtDutyCycleLastCommand[udtInstance][udtChannel] = udtDutyCycle;
      TLE8718_audtRequestedPeriod[udtInstance][udtChannel]      = udtPeriod;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidPwmSetOutputToIdle                                                                       */
/* !Description : Function to Set the Specified PWM Channel to Idle State                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidPwmSetOutputToIdle
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel    /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
)
{
   Pwm_ChannelType udtLocalPwmChannel;

   if (  (udtInstance < TLE8718_udtINSTANCE_NB)
      && (udtChannel < TLE8718_udtCHANNEL_NB)
      && (TLE8718_au8OutputMode[udtInstance][udtChannel] == TLE8718_u8PWM_MODE))
   {
      udtLocalPwmChannel = TLE8718_kaudtPwmChannel[udtInstance][udtChannel];
      Pwm_SetDutyCycle(udtLocalPwmChannel, TLE8718_udtDUTY_MIN);
      TLE8718_audtDutyCycleLastCommand[udtInstance][udtChannel] = TLE8718_udtDUTY_MIN;
      TLE8718_audtAppliedDutyCycle[udtInstance][udtChannel]     = TLE8718_udtDUTY_MIN;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidSetMode                                                                                  */
/* !Description : Function to Set the Mode of TLE8718 Output                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidSetMode
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel,   /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
   HOD_tenuMode     enuMode      /* !Comment: Mode available                  */
                                 /* !Range  : List of the enum mode           */
)
{
   boolean u8LocalBitPosition;
   uint8   u8LocalMscSrcResource;
   uint8   u8LocalOutputMode;

   if ((udtInstance < TLE8718_udtINSTANCE_NB) && (udtChannel < TLE8718_udtCHANNEL_NB))
   {
      u8LocalBitPosition = TLE8718_kau8MscBitPosition[udtChannel];
      switch (enuMode)
      {
         case HOD_MODE_DIO:
            u8LocalOutputMode     = TLE8718_u8DIO_MODE;
            u8LocalMscSrcResource = MSC_udtDATA_REG_SRC;
            break;

         case HOD_MODE_PWM:
            u8LocalOutputMode     = TLE8718_u8PWM_MODE;
            u8LocalMscSrcResource = MSC_udtALTINL_INVERTED_SRC;
            break;

         case HOD_MODE_CDD:
            u8LocalOutputMode     = TLE8718_u8CDD_MODE;
            u8LocalMscSrcResource = MSC_udtALTINL_INVERTED_SRC;
            break;

         default:
            u8LocalOutputMode     = TLE8718_u8DIO_MODE;
            u8LocalMscSrcResource = MSC_udtDATA_REG_SRC;
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
      TLE8718_au8OutputMode[udtInstance][udtChannel] = u8LocalOutputMode;
      /* As this function can be only called at init, there is no need to reset variables of Dio State and PWM Duty */
      /* No need to Reset bit in Data Register to be sure */
      Msc_vidCfgDataRegBitSrc(TLE8718_kau8Module[udtInstance], u8LocalBitPosition, u8LocalMscSrcResource);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidCpxOutStateChangeHook                                                                    */
/* !Description : Function to inform TLE8718 component that the state of complex driver output has changed            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidCpxOutStateChangeHook
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel,   /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
   boolean bState                /* !Comment: command to apply to the channel               */
                                 /* !Range  : STD_ON / STD_OFF                              */
)
{
   uint8 u8LocalReactivationRemainDelay;

   if (  (udtInstance < TLE8718_udtINSTANCE_NB)
      && (udtChannel < TLE8718_udtCHANNEL_NB)
      && (TLE8718_au8OutputMode[udtInstance][udtChannel] == TLE8718_u8CDD_MODE))
   {
      TLE8718_abDioLastCommand[udtInstance][udtChannel] = bState;

      u8LocalReactivationRemainDelay = TLE8718_au8ReactivRemainDelay[udtInstance][udtChannel];
      if (  (u8LocalReactivationRemainDelay == UINT8_MIN)
         && (TLE8718_au8CmdAuthorized[udtInstance][udtChannel] == TLE8718_u8CMD_ENABLED))
      {
         TLE8718_abDioAppliedState[udtInstance][udtChannel] = bState;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_udtGetComponentVersion                                                                      */
/* !Description : Function to Get the Hardware Version of TLE8718 Componant                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType TLE8718_udtGetComponentVersion
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   uint8 *pu8Tle8718HwVersion
)
{
   Std_ReturnType ustLocalStatus;

   if (udtInstance < TLE8718_udtINSTANCE_NB)
   {
      if (TLE8718_abIdentRegAvailable[udtInstance] != FALSE)
      {
         ustLocalStatus       = E_OK;
         *pu8Tle8718HwVersion = TLE8718_au8IdentReg[udtInstance];
      }
      else
      {
         ustLocalStatus = E_NOT_OK;
      }
   }
   else
   {
      ustLocalStatus = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return (ustLocalStatus);
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
