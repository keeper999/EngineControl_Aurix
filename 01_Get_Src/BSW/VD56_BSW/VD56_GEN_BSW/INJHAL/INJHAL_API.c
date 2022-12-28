/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL_API.c                                            */
/* !Description     : API of the INJHAL Component                             */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A26596.A-SRC;9 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"

#include "INJHAL.h"
#include "INJHAL_CFG_I.h"
#include "INJHAL_co_Cfg.h"

#include "MATHSRV.h"
#include "SchM_INJHAL.h"
/*lint -esym(960,5.1) */

#ifndef INJHAL_coGDI_MODE_INJ_SUPPORTED
   #error The macro-constant INJHAL_coGDI_MODE_INJ_SUPPORTED shall be defined
#endif
#ifndef INJHAL_coSEQ_PRE_INJ_SUPPORTED
   #error The macro-constant INJHAL_coSEQ_PRE_INJ_SUPPORTED shall be defined
#endif
#ifndef INJHAL_coTEST_MODE_INJ_SUPPORTED
   #error The macro-constant INJHAL_coTEST_MODE_INJ_SUPPORTED shall be defined
#endif
#ifndef INJHAL_coENABLED
   #error The macro-constant INJHAL_coENABLED shall be defined
#endif


#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"

/*lint -save -e934 */
/******************************************************************************/
/* !FuncName    : INJHAL_vidInit                                              */
/* !Description : INJHAL_vidInit shall initialize all internal variables of   */
/*                the INJHAL component.                                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidInit(void)
{
   uint8 u8LocalChannelIndex;
   uint8 u8LocalInstanceIdIndex;
   uint8 u8LocalInjPulseIndex;


   INJHAL_bTestMode = (boolean)FALSE;

   for (u8LocalInstanceIdIndex = 0U;
        u8LocalInstanceIdIndex < INJHAL_u8NB_INSTANCES;
        u8LocalInstanceIdIndex ++)
   {
      /* INJection driver enabled */
      INJHAL_abEnable[u8LocalInstanceIdIndex]                = (boolean)FALSE;

      /* Variable indicating Injection has started */
      INJHAL_abInjStarted[u8LocalInstanceIdIndex]            = (boolean)FALSE;

      /* FG Pre Injection is enabled */
      INJHAL_abEnableFGPreInj[u8LocalInstanceIdIndex]        = (boolean)FALSE;

      /* Sequential pre injection is enabled ?*/
      INJHAL_abEnableSeqPreInj[u8LocalInstanceIdIndex]       = (boolean)FALSE;

      /* Flag which indicates if the Start Angle is ready or not */
      INJHAL_abFGPreInjStartAngReady[u8LocalInstanceIdIndex] = (boolean)FALSE;

      /* Flag which indicates if the End Angle is ready or not */
      INJHAL_abFGPreInjEndAngReady[u8LocalInstanceIdIndex]   = (boolean)FALSE;

      /* End of Pre injection has taken care */
      INJHAL_abEndOfPreInjTreated[u8LocalInstanceIdIndex]    = (boolean)FALSE;

      /* Mask indicating the Injectors to Cut */
      INJHAL_abfInjectionCut[u8LocalInstanceIdIndex] = INJHAL_bfINHIB_ALL_INJ;

      /* FG end Angle */
      INJHAL_au16FGPreInjEndAngle[u8LocalInstanceIdIndex]  = (uint16)UINT16_MIN;

      /* ref Angle for starting the pre injection */
      INJHAL_au16AngleForPreInj[u8LocalInstanceIdIndex]    = (uint16)UINT16_MIN;

      INJHAL_au16ProgAngleForPreInj[u8LocalInstanceIdIndex]= (uint16)UINT16_MIN;

      /* FG Injection Time */
      INJHAL_au32FGPreInjTime[u8LocalInstanceIdIndex]      = (uint32)UINT32_MIN;

      /* Injector Driver Status */
      INJHAL_aenuInjComponentStatus[u8LocalInstanceIdIndex] =
         INJHAL_enuCOMP_INIT;
   }

   for (u8LocalChannelIndex = 0u;
        u8LocalChannelIndex < INJHAL_u8NB_INJECTORS;
        u8LocalChannelIndex ++)
   {
      for (u8LocalInjPulseIndex = 0u;
           u8LocalInjPulseIndex < INJHAL_u8NB_INJ_PULSES;
           u8LocalInjPulseIndex ++)
      {
         INJHAL_au16InjectionAngle[u8LocalInjPulseIndex][u8LocalChannelIndex] =
             (uint16)UINT16_MIN;
         INJHAL_au32InjectionTime[u8LocalInjPulseIndex][u8LocalChannelIndex]  =
             (uint32)UINT32_MIN;
      }
      /* Mode - N */
      INJHAL_au8InjectionMode[u8LocalChannelIndex] = INJHAL_u8MODE_1_INJECTION;

      INJHAL_au16SeqPreInjAngle[u8LocalChannelIndex]    = (uint16)UINT16_MIN;
      INJHAL_au32PrevInjectionTime[u8LocalChannelIndex] = (uint32)UINT32_MIN;
      INJHAL_au32SeqPreInjTime[u8LocalChannelIndex]     = (uint32)UINT32_MIN;

      INJHAL_audtCurrentInjectorPhase[u8LocalChannelIndex] =
         (INJHAL_tudtInjectorPhase)INJHAL_udtINVALID_PULSE;

      /* Injector Status */
      INJHAL_aenuInjectorMode[u8LocalChannelIndex] = INJHAL_enuINJ_MODE_INIT;
   }

   /* Initialise the GTM ATOM channel associated with the injectors */
   INJHAL_vidGtmInit();
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidEnable                                            */
/* !Description : INJHAL_vidEnable shall activate the INJHAL component and    */
/*                start the pre-injection stage.                              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidEnable
(
   uint8 u8InstanceId
)
{
   boolean        bLocalIsSynchronized_api;
   uint8          u8LocalCrkhalMasterChannel;
   uint8          u8LocalPreInjChannel;
   uint16         u16LocalAngleCounter;
   uint32         u32LocalAngle;
   Std_ReturnType udtLocalCrkStatus;


   if (  (u8InstanceId < INJHAL_u8NB_INSTANCES)
      && (INJHAL_abEnable[u8InstanceId] == (boolean)FALSE))
   {
      if (INJHAL_bTestMode == (boolean)FALSE)
      {
         INJHAL_abEnable[u8InstanceId] = (boolean)TRUE;

         INJHAL_vidENABLE_HOOK(u8InstanceId);

         /* Enable GTM channels */
         INJHAL_GtmEnable();

         /* All Injectors are enabled */
         INJHAL_abfInjectionCut[u8InstanceId] =
             (INJHAL_tbfInhibitMask)INJHAL_bfENABLE_ALL_INJ;

         /* Alarm for Injectors are enabled and a stop hook is given */
         INJHAL_vidCfgWriteInitValues(u8InstanceId);

         /* Status before Pre-injection */
         INJHAL_aenuInjComponentStatus[u8InstanceId] =
            INJHAL_enuCOMP_BEFORE_PRE_INJ;

         /* Pre injection Channel and get the Crkhal master Channel  */
         u8LocalPreInjChannel = INJHAL_kau8ChannelForPreInj[u8InstanceId];
         u8LocalCrkhalMasterChannel =
            INJHAL_kau8CrkhalChannel[u8LocalPreInjChannel];

         SchM_Enter_INJHAL_ACCESS_001();
         u16LocalAngleCounter =
            CRKHAL_u16ReadCounter(u8LocalCrkhalMasterChannel);

         udtLocalCrkStatus = CRKHAL_udtReadStatus((uint8)CRKHAL_u8SYNCHRONISED,
                                                  &bLocalIsSynchronized_api);
         if (udtLocalCrkStatus != E_OK)
         {
            udtLocalCrkStatus = INJHAL_udtCAM_READ_SYNC_STATUS(
                                   &bLocalIsSynchronized_api);
         }
         SchM_Exit_INJHAL_ACCESS_001();

         /* If synchronized and used only  If the engine is not synchronized, */
         /* the API INJHAL_udtGetFGPreInjStartAngle will not change the value */
         /* of *pu16FGPreInjStartAngle                                        */

         if (  (udtLocalCrkStatus == E_OK)
            && (bLocalIsSynchronized_api != (boolean)FALSE))
         {
            INJHAL_abFGPreInjStartAngReady[u8InstanceId] = (boolean)TRUE;
         }
         else
         {
            INJHAL_abFGPreInjStartAngReady[u8InstanceId] = (boolean)FALSE;
         }

         if (  INJHAL_au16AngleForPreInj[u8InstanceId]
            <= INJHAL_u16_1_DEG_FOR_PRE_INJ)
         {
            /* Start Immediately */
            u32LocalAngle = u16LocalAngleCounter;
         }
         else
         {
            u32LocalAngle = (uint32)( (uint32)(u16LocalAngleCounter)
                          + (uint32)(INJHAL_au16AngleForPreInj[u8InstanceId]));

            if (u32LocalAngle >= INJHAL_u16ENGINE_CYCLE)
            {
               u32LocalAngle -= INJHAL_u16ENGINE_CYCLE;
            }
         }
         INJHAL_au16ProgAngleForPreInj[u8InstanceId] = (uint16)(u32LocalAngle);

         if (  (INJHAL_abEnableFGPreInj[u8InstanceId] != (boolean)FALSE)
            && (INJHAL_au32FGPreInjTime[u8InstanceId] != (uint32)UINT32_MIN))
         {
            if(u32LocalAngle == u16LocalAngleCounter)
            {
               CRKHAL_vidEnableAlarmNotif(u8LocalCrkhalMasterChannel);
               INJHAL_vidEnableFGImmediate();
            }
            else
            {
               /* Configure the CM registers in the ATOM */
               CRKHAL_vidEnableAlarmNotif(u8LocalCrkhalMasterChannel);
               INJHAL_vidEnableFG(u32LocalAngle);
            }
         }
         else
         {
            INJHAL_aenuInjComponentStatus[u8InstanceId] =
            INJHAL_enuCOMP_FG_PRE_INJ;
            INJHAL_vidCfgTimeNotifFunctions(u8InstanceId);
         }
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidDisable                                           */
/* !Description : INJHAL_vidDisable shall disable the INJHAL component.       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidDisable
(
   uint8 u8InstanceId
)
{
   uint8 u8LocalChannelIndex;
   uint8 u8LocalChannelForLoopStart;
   uint8 u8LocalChannelForLoopEnd;


   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (INJHAL_bTestMode == (boolean)FALSE)
      {
         INJHAL_vidDISABLE_HOOK(u8InstanceId);

         INJHAL_vidGetForLoopConditions(u8InstanceId,
                                        &u8LocalChannelForLoopStart,
                                        &u8LocalChannelForLoopEnd);

         INJHAL_abFGPreInjStartAngReady[u8InstanceId] = (boolean)FALSE;
         INJHAL_abFGPreInjEndAngReady[u8InstanceId]   = (boolean)FALSE;
         INJHAL_abEndOfPreInjTreated[u8InstanceId]    = (boolean)FALSE;

         INJHAL_aenuInjComponentStatus[u8InstanceId] = INJHAL_enuCOMP_INIT;

         INJHAL_vidCfgInitAllInjectors(u8InstanceId);

         for (u8LocalChannelIndex = 0U /*u8LocalChannelForLoopStart*/;
              u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/;
              u8LocalChannelIndex ++)
         {
            if (  INJHAL_aenuInjectorMode[u8LocalChannelIndex]
               != INJHAL_enuINJ_MODE_DISABLED)
            {
               INJHAL_aenuInjectorMode[u8LocalChannelIndex] =
                  INJHAL_enuINJ_MODE_INIT;
            }
         }

         INJHAL_GtmDisable();
         INJHAL_abEnable[u8InstanceId] = (boolean)FALSE;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_bfUpdate                                             */
/* !Description : INJHAL_bfUpdate shall force the update of injection times   */
/*                (previously changed by INJHAL_vidWriteTime DEV_REQ:         */
/*                VEES_R_12_03716_027.01 and angles (INJHAL_vidWriteAngle     */
/*                DEV_REQ: VEES_R_12_03716_034.01).                           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
INJHAL_tbfUpdateStatus INJHAL_bfUpdate
(
   uint8 u8InstanceId
)
{
   INJHAL_tbfUpdateStatus bfLocalInjUpdateStatus;


   bfLocalInjUpdateStatus = 0u;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_abfTimeUpdate[u8InstanceId]  = 0u;
      INJHAL_abfAngleUpdate[u8InstanceId] = (INJHAL_tbfAngleUpdate)0;

      INJHAL_vidCfgUpdateInjTimes(u8InstanceId);
      if (INJHAL_kabEnableAngleUpdate[u8InstanceId] != (boolean)FALSE)
      {
         INJHAL_vidCfgUpdateInjAngles(u8InstanceId);
      }
      bfLocalInjUpdateStatus =
         (INJHAL_tbfUpdateStatus)
            ( ((INJHAL_tbfUpdateStatus)(
                  (INJHAL_tbfUpdateStatus)INJHAL_abfAngleUpdate[u8InstanceId]
                    << (INJHAL_tbfUpdateStatus)INJHAL_u8BF_UPDT_ANGLE_SHIFT))
            | ((INJHAL_tbfUpdateStatus)(INJHAL_abfTimeUpdate[u8InstanceId])));
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   return (bfLocalInjUpdateStatus);
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidWriteTime                                         */
/* !Description : INJHAL_vidWriteTime shall update injection times.           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidWriteTime
(
   uint8 u8Channel,
   uint8 u8PulseNumber,
   uint32 u32InjectionTime
)
{
   uint32 u32LocalInjectionTime;


   if (u8Channel < INJHAL_u8NB_INJECTORS)
   {
      if (u8PulseNumber < INJHAL_u8NB_INJ_PULSES)
      {
         u32LocalInjectionTime = u32InjectionTime;
         INJHAL_vidCfgInjTimeRescale(&u32LocalInjectionTime);

         if (u32LocalInjectionTime > INJHAL_u32MAX_TIME_DYNAMIC)
         {
            INJHAL_au32InjectionTime[u8PulseNumber][u8Channel] =
               INJHAL_u32MAX_TIME_DYNAMIC;
            SWFAIL_vidSoftwareErrorHook();
         }
         else
         {
            INJHAL_au32InjectionTime[u8PulseNumber][u8Channel] =
               u32LocalInjectionTime;
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidWriteAngle                                        */
/* !Description : INJHAL_vidWriteAngle shall update injection phases.         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidWriteAngle
(
   uint8 u8Channel,
   uint8 u8PulseNumber,
   uint16 u16InjectionAngle
)
{
   if (u8Channel < INJHAL_u8NB_INJECTORS)
   {
      if (u8PulseNumber < INJHAL_u8NB_INJ_PULSES)
      {
        INJHAL_au16InjectionAngle[u8PulseNumber][u8Channel] =
           (uint16)(MATHSRV_udtMIN(u16InjectionAngle, INJHAL_u16_715_DEGREES));
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidInhibit                                           */
/* !Description : INJHAL_vidInhibit shall authorize or not injections on the  */
/*                selected cylinder.                                          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidInhibit
(
   uint8 u8InstanceId,
   INJHAL_tbfInhibitMask bfInhibitMask
)
{
   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_abfInjectionCut[u8InstanceId] = bfInhibitMask;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_bInjectionStarted                                    */
/* !Description : INJHAL_bInjectionStarted shall return TRUE if at least one  */
/*                injector have been opened since the last reset or the last  */
/*                call to INJHAL_vidResetInjectionStarted else FALSE.         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
boolean INJHAL_bInjectionStarted
(
   uint8 u8InstanceId
)
{
   boolean RetVal;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      RetVal = INJHAL_abInjStarted[u8InstanceId];
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      RetVal = (boolean)FALSE;
   }
  return(RetVal);
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidWriteMode                                         */
/* !Description : INJHAL_vidWriteMode shall change the number of pulses by    */
/*                cycle on the considered injector channel "u8Channel".       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidWriteMode
(
   uint8 u8InstanceId,
   uint8 u8Channel,
   uint8 u8InjectionMode
)
{
   uint8 u8LocalChannelIndex;
   uint8 u8LocalChannelForLoopStart;
   uint8 u8LocalChannelForLoopEnd;


   if (  (u8InjectionMode <= INJHAL_u8NB_INJ_PULSES)
      && (u8InjectionMode >= INJHAL_u8MODE_1_INJECTION))
   {
      if (u8InstanceId < INJHAL_u8NB_INSTANCES)
      {
         INJHAL_vidGetForLoopConditions(u8InstanceId,
                                        &u8LocalChannelForLoopStart,
                                        &u8LocalChannelForLoopEnd);
         /*if (  (u8Channel >= u8LocalChannelForLoopStart)
            && (u8Channel < u8LocalChannelForLoopEnd))*/
         if(u8Channel < INJHAL_u8NB_INJECTORS)
         {
            if (  INJHAL_aenuInjectorMode[u8Channel]
               != INJHAL_enuINJ_MODE_DISABLED)
            {
               INJHAL_au8InjectionMode[u8Channel] = u8InjectionMode;
            }
         }
         else
         {
            if (u8Channel == INJHAL_u8ALL_CYLINDERS)
            {

               for (u8LocalChannelIndex = 0U/*u8LocalChannelForLoopStart*/;
                    u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/;
                    u8LocalChannelIndex ++)
               {
                  INJHAL_au8InjectionMode[u8LocalChannelIndex] =
                     u8InjectionMode;
               }
            }
            else
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidWriteFGPreInjTime                                 */
/* !Description : INJHAL_vidWriteFGPreInjTime shall provide the full group    */
/*                pre-injection time, applied to all injectors of the         */
/*                considered instance.                                        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidWriteFGPreInjTime
(
   uint8 u8InstanceId,
   uint32 u32InjectionTime
)
{
   uint32 u32LocalInjectionTime;


   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         u32LocalInjectionTime = u32InjectionTime;
         INJHAL_vidCfgInjTimeRescale(&u32LocalInjectionTime);

         if (u32LocalInjectionTime > INJHAL_u32MAX_TIME_DYNAMIC)
         {
            INJHAL_au32FGPreInjTime[u8InstanceId] = INJHAL_u32MAX_TIME_DYNAMIC;
            SWFAIL_vidSoftwareErrorHook();
         }
         else
         {
            INJHAL_au32FGPreInjTime[u8InstanceId] = u32LocalInjectionTime;
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidEnableFGPreInj                                    */
/* !Description : INJHAL_vidEnableFGPreInj shall authorize the full group     */
/*                pre-injection on the considered injector’s instance.        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidEnableFGPreInj
(
   uint8 u8InstanceId
)
{
   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         INJHAL_abEnableFGPreInj[u8InstanceId] = (boolean)TRUE;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidDisableFGPreInj                                   */
/* !Description : INJHAL_vidDisableFGPreInj shall disable the full group      */
/*                pre-injection on the considered injector’s instance.        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidDisableFGPreInj
(
   uint8 u8InstanceId
)
{
   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         INJHAL_abEnableFGPreInj[u8InstanceId] = (boolean)FALSE;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_enuReadFGPreInjStatus                                */
/* !Description : INJHAL_enuReadFGPreInjStatus shall return the full group    */
/*                pre-injection status.                                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
INJHAL_tenuFGPreInjStatus INJHAL_enuReadFGPreInjStatus
(
   uint8 u8InstanceId
)
{
   uint8                     u8LocalInjCompStatus;
   INJHAL_tenuFGPreInjStatus enuLocalFGPreInjStatus;

   enuLocalFGPreInjStatus = INJHAL_enuPREINJ_NONE;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      u8LocalInjCompStatus   = INJHAL_aenuInjComponentStatus[u8InstanceId];
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         if (u8LocalInjCompStatus == INJHAL_enuCOMP_FG_PRE_INJ)
         {
            enuLocalFGPreInjStatus = INJHAL_enuPREINJ_ACT;
         }
         else
         {
            if (  (u8LocalInjCompStatus == INJHAL_enuCOMP_SEQ_INJ)
               || (u8LocalInjCompStatus == INJHAL_enuCOMP_WAITING_SYNCHRO)
               || (u8LocalInjCompStatus == INJHAL_enuCOMP_SEQ_PRE_INJ))
            {
               enuLocalFGPreInjStatus = INJHAL_enuPREINJ_END;
            }
            else
            {
               enuLocalFGPreInjStatus = INJHAL_enuPREINJ_NONE;
            }
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
   return(enuLocalFGPreInjStatus);
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidWriteAngleBeforePreInj                            */
/* !Description : INJHAL_vidWriteAngleBeforePreInj shall provide the          */
/*                pre-injection waiting angle (the same for full group and    */
/*                sequential), applied to all injectors of the considered     */
/*                instance.                                                   */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidWriteAngleBeforePreInj
(
   uint8 u8InstanceId,
   uint16 u16InjectionAngle
)
{
   uint16         u16LocalInjectionAngle;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         u16LocalInjectionAngle =
            (uint16)(MATHSRV_udtMIN(u16InjectionAngle,
                                    (uint16)(INJHAL_u16ENGINE_CYCLE - 1u)));
         INJHAL_au16AngleForPreInj[u8InstanceId] = u16LocalInjectionAngle;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidCancelInjGroupAlarms                              */
/* !Description : INJHAL_vidCancelInjGroupAlarms shall cancel the injectors’  */
/*                group angular alarms of the considered instance to avoid    */
/*                phase problems when the synchronisation is found while the  */
/*                pre-injection waiting angle has not been reached yet.       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidCancelInjGroupAlarms
(
   uint8 u8InstanceId
)
{
   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         /*CRKHAL_vidDeactivateAlarmMode(u8LocalChannelIndex);*/
         INJHAL_vidCancelInjAlarm(u8InstanceId);
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidEnableSeqPreInj                                   */
/* !Description : INJHAL_vidEnableSeqPreInj shall authorize the sequential    */
/*                pre-injection on the considered injectors’ instance.        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidEnableSeqPreInj
(
   uint8 u8InstanceId
)
{
#if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED)
   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         INJHAL_abEnableSeqPreInj[u8InstanceId] = (boolean)TRUE;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
#else  /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8InstanceId);
#endif /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidDisableSeqPreInj                                  */
/* !Description : INJHAL_vidDisableSeqPreInj shall disable the sequential     */
/*                pre-injection on the considered injectors’ instance.        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidDisableSeqPreInj
(
   uint8 u8InstanceId
)
{
#if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED)

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         INJHAL_abEnableSeqPreInj[u8InstanceId] = (boolean)FALSE;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
#else  /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8InstanceId);
#endif /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidWriteSeqPreInjAngle                               */
/* !Description : INJHAL_vidWriteSeqPreInjAngle shall provide the waiting     */
/*                angle before starting the sequential pre-injection to a     */
/*                given cylinder.                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidWriteSeqPreInjAngle
(
   uint8 u8InstanceId,
   uint8 u8Channel,
   uint16 u16InjectionAngle
)
{
#if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED)
   uint16         u16LocalInjectionAngle;
   uint8          u8LocalChannelIndex;
   uint8          u8LocalChannelForLoopStart;
   uint8          u8LocalChannelForLoopEnd;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_vidGetForLoopConditions(u8InstanceId,
                                     &u8LocalChannelForLoopStart,
                                     &u8LocalChannelForLoopEnd);

      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         u16LocalInjectionAngle =
            (uint16)(MATHSRV_udtMIN(u16InjectionAngle,
                                    (uint16)(INJHAL_u16ENGINE_CYCLE - 1U)));

         if(u8Channel < INJHAL_u8NB_INJECTORS)
         {
           /*if (  (u8Channel >= u8LocalChannelForLoopStart)
            && (u8Channel < u8LocalChannelForLoopEnd))*/
           { 
             INJHAL_au16SeqPreInjAngle[u8Channel] = u16LocalInjectionAngle;
           }
         }
         else
         {
            if (u8Channel == INJHAL_u8ALL_CYLINDERS)
            {
               for (u8LocalChannelIndex = 0U;/*u8LocalChannelForLoopStart;*/
                    u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/;
                    u8LocalChannelIndex ++)
               {
                  INJHAL_au16SeqPreInjAngle[u8LocalChannelIndex] =
                     u16LocalInjectionAngle;
               }
            }
            else
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
#else  /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8InstanceId);
   COMPILER_UNUSED_PARAMETER(u8Channel);
   COMPILER_UNUSED_PARAMETER(u16InjectionAngle);
#endif /*  #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidWriteSeqPreInjTime                                */
/* !Description : The API shall provide the time for the                      */
/*                the sequential pre-injection to a given cylinder.           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidWriteSeqPreInjTime
(
   uint8 u8InstanceId,
   uint8 u8Channel,
   uint32 u32InjectionTime
)
{
#if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED)
   uint8  u8LocalChannelIndex;
   uint8  u8LocalChannelForLoopStart;
   uint8  u8LocalChannelForLoopEnd;
   uint32 u32LocalInjectionTime;


   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_vidGetForLoopConditions(u8InstanceId,
                                     &u8LocalChannelForLoopStart,
                                     &u8LocalChannelForLoopEnd);

      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         u32LocalInjectionTime = u32InjectionTime;
            INJHAL_vidCfgInjTimeRescale(&u32LocalInjectionTime);

         if (u32LocalInjectionTime > INJHAL_u32MAX_TIME_DYNAMIC)
         {
            u32LocalInjectionTime = INJHAL_u32MAX_TIME_DYNAMIC;
            SWFAIL_vidSoftwareErrorHook();
         }

         /*if (  (u8Channel >= u8LocalChannelForLoopStart)
            && (u8Channel < u8LocalChannelForLoopEnd))*/
         if(u8Channel < INJHAL_u8NB_INJECTORS)        
         {
            INJHAL_au32SeqPreInjTime[u8Channel] = u32LocalInjectionTime;
         }
         else
         {
            if (u8Channel == INJHAL_u8ALL_CYLINDERS)
            {

               for (u8LocalChannelIndex = 0U/*u8LocalChannelForLoopStart*/;
                    u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/;
                    u8LocalChannelIndex ++)
               {
                  INJHAL_au32SeqPreInjTime[u8LocalChannelIndex] =
                     u32LocalInjectionTime;
               }
            }
            else
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
#else  /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8InstanceId);
   COMPILER_UNUSED_PARAMETER(u8Channel);
   COMPILER_UNUSED_PARAMETER(u32InjectionTime);
#endif /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_bfReadSeqPreInjStatus                                */
/* !Description : INJHAL_bfReadSeqPreInjStatus shall return the sequential    */
/*                pre-injection status of all injectors on the considered     */
/*                instance.                                                   */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
INJHAL_tbfSeqPreInjStatus INJHAL_bfReadSeqPreInjStatus
(
   uint8 u8InstanceId
)
{
#if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED)
   INJHAL_tbfSeqPreInjStatus bfLocalSeqPreInjStatus;
   uint16                    bfLocalSeqPreInjStatus_1;
   uint8                     u8LocalChannelIndex;
   uint8                     u8LocalChannelForLoopStart;
   uint8                     u8LocalChannelForLoopEnd;
   uint16                    u16Localvalue ; 
   volatile uint8            u8LocalVal ;
   
   bfLocalSeqPreInjStatus = (INJHAL_tbfSeqPreInjStatus)0;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      if (  INJHAL_kabPreInjAuthorization[u8InstanceId]
         != INJHAL_bPRE_INJ_UNAUTHORIZED)
      {
         INJHAL_vidGetForLoopConditions(u8InstanceId,
                                        &u8LocalChannelForLoopStart,
                                        &u8LocalChannelForLoopEnd);

         if (INJHAL_abEnableSeqPreInj[u8InstanceId] != (boolean)FALSE)
         {
            for(u8LocalChannelIndex = 0U; /*u8LocalChannelForLoopStart;*/
                u8LocalChannelIndex < INJHAL_u8NB_INJECTORS ;/*u8LocalChannelForLoopEnd;*/
                u8LocalChannelIndex ++)
            {
               /*SchM_Enter_INJHAL_ACCESS_008(); Useless critical section */
               u8LocalVal = INJHAL_aenuInjectorMode[u8LocalChannelIndex];
               /*SchM_Exit_INJHAL_ACCESS_008(); */
               switch (u8LocalVal)
               {
                  case INJHAL_enuINJ_MODE_INIT:
                     u16Localvalue = (uint16)( (uint16)u8LocalChannelIndex - (uint16)u8LocalChannelForLoopStart) ;
                     u16Localvalue = u16Localvalue * 2U ; 
                     bfLocalSeqPreInjStatus_1 = (uint16)((uint32)(INJHAL_bfSEQ_PRE_INJ_NOT_DONE) << (u16Localvalue));
                     bfLocalSeqPreInjStatus |= bfLocalSeqPreInjStatus_1 ;
                     break;

                  case INJHAL_enuINJ_MODE_PREINJ_SEQ:
                     u16Localvalue = (uint16)( (uint16)u8LocalChannelIndex - (uint16)u8LocalChannelForLoopStart) ;
                     u16Localvalue = u16Localvalue * 2U ; 
                     bfLocalSeqPreInjStatus_1 = (uint16)((uint32)(INJHAL_bfSEQ_PRE_INJ_RUNNING) << (u16Localvalue));
                     bfLocalSeqPreInjStatus |= bfLocalSeqPreInjStatus_1 ; 
                     break;

                  case INJHAL_enuINJ_MODE_NORMAL:
                     u16Localvalue = (uint16)( (uint16)u8LocalChannelIndex - (uint16)u8LocalChannelForLoopStart) ;
                     u16Localvalue = u16Localvalue * 2U ; 
                     bfLocalSeqPreInjStatus_1 = (uint16)((uint32)(INJHAL_bfSEQ_PRE_INJ_DONE) << (u16Localvalue));
                     bfLocalSeqPreInjStatus |= bfLocalSeqPreInjStatus_1 ;
                     break;

                  case INJHAL_enuINJ_MODE_DISABLED:
                     break;

                  default:
                     SWFAIL_vidSoftwareErrorHook();
                     break;
               }
            }
         }
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   return (bfLocalSeqPreInjStatus);
#else  /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8InstanceId);
   return (INJHAL_bfSEQ_PRE_INJ_NOT_DONE);
#endif /* #if (INJHAL_coSEQ_PRE_INJ_SUPPORTED == INJHAL_coENABLED) */
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidResetInjectionStarted                             */
/* !Description : INJHAL_vidResetInjectionStarted shall reset the variable    */
/*                describing if at least one injection has been done during   */
/*                the trip so the INJHAL_bInjectionStarted API returns FALSE  */
/*                if called just after INJHAL_vidResetInjectionStarted.       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidResetInjectionStarted
(
   uint8 u8InstanceId
)
{
   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_abInjStarted[u8InstanceId] = (boolean)FALSE;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidTestModeEntry                                     */
/* !Description : INJHAL_vidTestModeEntry shall allow entering the INJHAL     */
/*                component test mode.                                        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidTestModeEntry(void)
{
#if (INJHAL_coTEST_MODE_INJ_SUPPORTED == INJHAL_coENABLED)
   uint8 u8LocalInstanceId;


   if (INJHAL_bTestMode == (boolean)FALSE)
   {
      for (u8LocalInstanceId = 0U;
           u8LocalInstanceId < INJHAL_u8NB_INSTANCES;
           u8LocalInstanceId ++)
      {
         INJHAL_vidDisable(u8LocalInstanceId);
         INJHAL_vidTEST_MODE_ENTRY_HOOK(u8LocalInstanceId);
      }
   }
   INJHAL_bTestMode = (boolean)TRUE;
#endif /*  #if (INJHAL_coTEST_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidTestModeExit                                      */
/* !Description : INJHAL_vidTestModeExit shall allow exiting the INJHAL       */
/*                component test mode.                                        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidTestModeExit(void)
{
#if (INJHAL_coTEST_MODE_INJ_SUPPORTED == INJHAL_coENABLED)
   uint8 u8LocalInstanceId;


   if (INJHAL_bTestMode != (boolean)FALSE)
   {
      INJHAL_bTestMode = (boolean)FALSE;
      for (u8LocalInstanceId = 0U;
           u8LocalInstanceId < INJHAL_u8NB_INSTANCES;
           u8LocalInstanceId ++)
      {
         INJHAL_vidDisable(u8LocalInstanceId);
         INJHAL_vidTEST_MODE_EXIT_HOOK(u8LocalInstanceId);
      }
   }
#endif /* #if (INJHAL_coTEST_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidWriteTestTime                                     */
/* !Description : If the INJHAL component is in test mode,                    */
/*                INJHAL_vidWriteTestTime shall start injecting immediately   */
/*                on injector designed by "u8Channel" during the time given by*/
/*                "u32InjTestTime" parameter.                                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidWriteTestTime
(
   uint8 u8Channel,
   uint32 u32InjTestTime
)
{
#if (INJHAL_coTEST_MODE_INJ_SUPPORTED == INJHAL_coENABLED)
   uint32 u32LocalInjTestTime;


   if (u8Channel < INJHAL_u8NB_INJECTORS)
   {
      if (  (INJHAL_bTestMode != (boolean)FALSE)
         && (u32InjTestTime   != (uint32)UINT32_MIN))
      {
         u32LocalInjTestTime = u32InjTestTime;
            INJHAL_vidCfgInjTimeRescale(&u32LocalInjTestTime);

         if (u32LocalInjTestTime > INJHAL_u32MAX_TIME_DYNAMIC)
         {
            u32LocalInjTestTime = INJHAL_u32MAX_TIME_DYNAMIC;
            SWFAIL_vidSoftwareErrorHook();
         }

         INJHAL_vidCfgWriteTestTime(u8Channel, u32LocalInjTestTime);
      }
   }
   else
#else /* #if (INJHAL_coTEST_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8Channel);
   COMPILER_UNUSED_PARAMETER(u32InjTestTime);
#endif /* #if (INJHAL_coTEST_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : INJHAL_udtGetFGPreInjStartAngle                             */
/* !Description : Gets the starting angle of full group pre-injection pulse.  */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType INJHAL_udtGetFGPreInjStartAngle
(
   uint8 u8InstanceId,
   uint16* pu16FGPreInjStartAngle
)
{
   boolean        bLocalFGPreInjStartAngReady;
   uint16         u16LocalFGPreInjStartAngle;
   Std_ReturnType udtLocalRetVal;


   udtLocalRetVal = E_NOT_OK;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      SchM_Enter_INJHAL_ACCESS_005();
      u16LocalFGPreInjStartAngle = INJHAL_au16ProgAngleForPreInj[u8InstanceId];
      bLocalFGPreInjStartAngReady =
         INJHAL_abFGPreInjStartAngReady[u8InstanceId];
      SchM_Exit_INJHAL_ACCESS_005();

      if (bLocalFGPreInjStartAngReady != (boolean)FALSE)
      {
         *pu16FGPreInjStartAngle = u16LocalFGPreInjStartAngle;
         udtLocalRetVal          = E_OK;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   return (udtLocalRetVal);
}

/******************************************************************************/
/* !FuncName    : INJHAL_udtGetFGPreInjEndAngle                               */
/* !Description : Gets the angle at which full group pre-injection pulse has  */
/*                ended.                                                      */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType INJHAL_udtGetFGPreInjEndAngle
(
   uint8 u8InstanceId,
   uint16* pu16FGPreInjEndAngle
)
{
   boolean        bLocalFGPreInjEndAngReady;
   uint16         u16LocalFGPreInjEndAngle;
   Std_ReturnType udtLocalRetVal;


   udtLocalRetVal = E_NOT_OK;

   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      SchM_Enter_INJHAL_ACCESS_004();
      u16LocalFGPreInjEndAngle  = INJHAL_au16FGPreInjEndAngle[u8InstanceId];
      bLocalFGPreInjEndAngReady = INJHAL_abFGPreInjEndAngReady[u8InstanceId];
      SchM_Exit_INJHAL_ACCESS_004();

      if (bLocalFGPreInjEndAngReady != (boolean)FALSE)
      {
         *pu16FGPreInjEndAngle = u16LocalFGPreInjEndAngle;
         udtLocalRetVal        = E_OK;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   return (udtLocalRetVal);
}

/******************************************************************************/
/* !FuncName    : INJHAL_udtSwitchGdiProfile                                  */
/*                                                                            */
/* !Description : INJHAL_udtSwitchGdiProfile shall apply to the considered    */
/*                "u8InstanceId"  instance of injectors the new               */
/*                "u8GdiProfileId" GDI profile requested                      */
/*                ended.                                                      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType INJHAL_udtSwitchGdiProfile
(
   uint8 u8InstanceId,
   uint8 u8GdiProfileId
)
{
#if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED)
   Std_ReturnType udtLocalStatus;


   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_vidCfgSwitchGdiProfile(u8InstanceId,
                                    u8GdiProfileId,
                                    &udtLocalStatus);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      udtLocalStatus = E_NOT_OK;
   }

   return(udtLocalStatus);
#else /* #if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8InstanceId);
   COMPILER_UNUSED_PARAMETER(u8GdiProfileId);
   return(E_NOT_OK);
#endif /* #if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
}

/******************************************************************************/
/* !FuncName    : INJHAL_udtStopGdiHw                                         */
/*                                                                            */
/* !Description : Requests a stop of the ASIC GDI Controller                  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType INJHAL_udtStopGdiHw
(
   uint8 u8InstanceId
)
{
#if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED)
   Std_ReturnType udtLocalStatus;


   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_vidCfgStopGdiHw(u8InstanceId, &udtLocalStatus);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      udtLocalStatus = E_NOT_OK;
   }

   return(udtLocalStatus);
#else /* #if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8InstanceId);
   return(E_NOT_OK);
#endif /* #if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
}

/******************************************************************************/
/* !FuncName    : INJHAL_udtRestartGdiHw                                      */
/*                                                                            */
/* !Description : Requests a restart of the ASIC GDI Controller               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType INJHAL_udtRestartGdiHw
(
   uint8 u8InstanceId
)
{
#if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED)
   Std_ReturnType udtLocalStatus;


   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_vidCfgRestartGdiHw(u8InstanceId, &udtLocalStatus);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      udtLocalStatus = E_NOT_OK;
   }

   return(udtLocalStatus);
#else /* #if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
   COMPILER_UNUSED_PARAMETER(u8InstanceId);
   return(E_NOT_OK);
#endif /* #if (INJHAL_coGDI_MODE_INJ_SUPPORTED == INJHAL_coENABLED) */
}

#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"
/*lint -restore */
/*------------------------------ end of file ------------------------------*/
