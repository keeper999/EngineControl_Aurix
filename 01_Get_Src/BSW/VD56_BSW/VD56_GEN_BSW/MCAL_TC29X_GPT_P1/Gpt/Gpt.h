/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Gpt.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\38 $                                                 **
**                                                                           **
**  $DATE       : 2013-09-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of GPT driver.            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/


#ifndef  GPT_H
#define  GPT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Gtm.h"
/* GPT259: GPT Pre-compile/static configuration file */
#include "Gpt_Cfg.h"
/* Type definition of EcuM_WakeupSourceType */
/* GPT271: The inclusion of EcuM_Cbk.h is required, if wakeup functionality is
   configured. */
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#include "EcuM_Cbk.h"
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/* Import of DET functionality. This is needed for GetVersionInfo Macro */
#include "Det.h"
#endif

#if(GPT_SAFETY_ENABLE == STD_ON)
#include "SafetyReport.h"
#endif
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#if ( GPT_DEV_ERROR_DETECT  == STD_ON) || (GPT_SAFETY_ENABLE == STD_ON)
/*
  Development Error (DET) values - GPT174:, GPT001:, GPT204:,GPT001:,GPT175:,
  GPT176:,GPT178:
*/
/* [cover parentID=DS_AS_GPT174,DS_AS_GPT345] */
/* Operational function called prior to Init function */
#define GPT_E_UNINIT              ((uint8)10)
/* [/cover] */
/* [cover parentID=DS_AS_GPT346] */
/* Function ‘StartTimer’ or 'DeInit called while timer is already running */
/* [cover parentID=DS_AS_GPT174,DS_AS_GPT345] */
#define GPT_E_BUSY                ((uint8)11)
/* [/cover] */
/* [cover parentID=DS_AS_GPT347] */
/* Init function: Gpt_Init called while driver already initialized */
#define GPT_E_ALREADY_INITIALIZED ((uint8)13)
/* [/cover] */
/* [cover parentID=DS_AS_GPT348] */
/* Operational function called with invalid channel ID */
#define GPT_E_PARAM_CHANNEL       ((uint8)20)
/* [/cover] */
/* [cover parentID=DS_AS_GPT349] */
/* Function ‘Gpt_StartTimer’ called with invalid value */
#define GPT_E_PARAM_VALUE         ((uint8)21)
/* [/cover] */

/* [cover parentID=DS_AS_GPT350] */
/* Function "Gpt_GetVersionInfo & Gpt_Init" called with invalid pointer */
#define GPT_E_PARAM_POINTER       ((uint8)22)
/* [/cover] */

/* [cover parentID=DS_AS_GPT351] */
/* Function 'Gpt_SetMode' Parameter mode is invalid mode */
#define GPT_E_PARAM_MODE          ((uint8)31)
/* [/cover] */

#if ( GPT_SAFETY_ENABLE  == STD_ON)
/* Function 'Gpt_SetMode' called to SLEEP without IRQ enabled for any
wakeup channel. This is added as Safety measure before putting GPT to 
SLEEP */
#define GPT_E_NO_WAKEUP           ((uint8)32) 

#endif
/*
   API Service ID's
*/
/* API Service ID for Gpt_GetVersionInfo() */
#define GPT_SID_GETVERSIONINFO       ((uint8)0x00)
/* API Service ID for Gpt_Init() */
#define GPT_SID_INIT                 ((uint8)0x01)
/* API Service ID for Gpt_DeInit() */
#define GPT_SID_DEINIT               ((uint8)0x02)
/* API Service ID for Gpt_GetTimeElapsed() */
#define GPT_SID_GET_TIMEELAPSED      ((uint8)0x03)
/* API Service ID for Gpt_GetTimeRemaining() */
#define GPT_SID_GET_TIMEREMAINING    ((uint8)0x04)
/* API Service ID for Gpt_StartTimer()*/
#define GPT_SID_STARTTIMER           ((uint8)0x05)
/* API Service ID for Gpt_StopTimer() */
#define GPT_SID_STOPTIMER            ((uint8)0x06)
/* API Service ID for Gpt_EnableNotification() */
#define GPT_SID_ENABLE_NOTIFICATION  ((uint8)0x07)
/* API Service ID for Gpt_DisableNotification() */
#define GPT_SID_DISABLE_NOTIFICATION ((uint8)0x08)
/* API Service ID for Gpt_SetMode() */
#define GPT_SID_SET_MODE             ((uint8)0x09)
/* API Service ID for Gpt_DisableWakeup() */
#define GPT_SID_DISABLE_WAKEUP       ((uint8)0x0A)
/* API Service ID for Gpt_EnableWakeup() */
#define GPT_SID_ENABLE_WAKEUP        ((uint8)0x0B)
/* API Service ID for Gpt_CheckWakeup() */
#define GPT_SID_CHECK_WAKEUP         ((uint8)0x0C)
/* API Service ID for Gpt_Isr() */
#define GPT_SID_ISR                  ((uint8)0x0D)

#endif /* End of #if ( GPT_DEV_ERROR_DETECT  == STD_ON) 
                                     || (GPT_SAFETY_ENABLE == STD_ON) */



/*
  Published parameters (Vendor ID, Module ID and File version info) - GPT256:,
  GPT189:
*/
/* [cover parentID=DS_AS40X_GPT001_PI] */
/* GPT Vendor ID - Vendor ID of the dedicated implementation of this
module according to the AUTOSAR vendor list */
#define GPT_VENDOR_ID     ((uint16)17)
/*GPT Module ID - Module ID of this module from Module List */
#define GPT_MODULE_ID     ((uint16)100)
/*
Configuration: GPT_INSTANCE_ID
InstanceId of GPT module
*/
/* InstanceId of GPT module  */
#define GPT_INSTANCE_ID              ((uint8)0)

/* [/cover] */

/* Users can make use of these #defines while configuring GPT driver */

/* Gpt Channel Mode */
/* Timer channel stops after reaching its end value - GPT186:*/
#define GPT_MODE_CONTINUOUS ((Gpt_ModeType)0x0U)

/* Timer channel is restarted automatically after reaching its
end value - GPT185:*/
#define GPT_MODE_ONESHOT    ((Gpt_ModeType)0x4U)

/* Different Power modes */
/* [cover parentID=DS_AS_GPT360] */
/* Uninitialized operation mode of the GPT,Refer BugZilla 51410 */
#define GPT_MODE_UNINITIALIZED   ((Gpt_ModeType)0)
/* Normal operation mode of the GPT */
#define GPT_MODE_NORMAL   ((Gpt_ModeType)1)
/* Operation for the reduced power operation mode */
#define GPT_MODE_SLEEP    ((Gpt_ModeType)2)
/* [/cover] */

/*
   If the parameter GPT_PB_FIXEDADDR is not defined it will be defined
   with default value.
*/
#ifndef GPT_PB_FIXEDADDR
#define GPT_PB_FIXEDADDR     (STD_OFF)
#endif

/*
   If the parameter GPT_ONESHOT_USED is not defined it will be defined
   with default value.
*/
#ifndef GPT_ONESHOT_USED
#define GPT_ONESHOT_USED     (STD_ON)
#endif

/* Configurable Clocks */
#define GTM_CONFIGURABLE_CLOCK_0   (0U)
#define GTM_CONFIGURABLE_CLOCK_1   (1U)
#define GTM_CONFIGURABLE_CLOCK_2   (2U)
#define GTM_CONFIGURABLE_CLOCK_3   (3U)
#define GTM_CONFIGURABLE_CLOCK_4   (4U)
#define GTM_CONFIGURABLE_CLOCK_5   (5U)
#define GTM_CONFIGURABLE_CLOCK_6   (6U)
#define GTM_CONFIGURABLE_CLOCK_7   (7U)

/* Fixed Clock */
#define GTM_FIXED_CLOCK_0 (0U)
#define GTM_FIXED_CLOCK_1 (1U)
#define GTM_FIXED_CLOCK_2 (2U)
#define GTM_FIXED_CLOCK_3 (3U)
#define GTM_FIXED_CLOCK_4 (4U)

/*Gpt Channel Signal Types */
#define GPT_QM_SIGNAL (0U) /* QM Signal */

#define GPT_ASIL_SIGNAL (1U)  /* ASIL B Signal */

/* MISRA Rule Violation 19.7:Function-like macro defined.this can not be avoided
*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT279,DS_AS_GPT273,DS_AS40X_GPT181,
   DS_AS_GPT176_1_GPT178_1,DS_AS_GPT338_GPT332_1,SAS_AS_GPT182]

** Syntax : void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)      **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): versioninfo (Pointer to where to store the version       **
**                                information of this module )                **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service returns the version information of this module. **
**               The version information includes:                            **
**               - Module Id                                                  **
**               - Vendor Id                                                  **
**               - Vendor specific version numbers (BSW00407)                 **
*******************************************************************************/
#if ((GPT_VERSION_INFO_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
#define Gpt_GetVersionInfo(VersionInfoPtr)                                     \
{                                                                              \
                                                                               \
  /* Check if the passed parameter is a NULL_PTR.*/                            \
  /*If so,escalate it with GPT_E_PARAM_POINTER... */                           \
  if(VersionInfoPtr == NULL_PTR)                                               \
  {                                                                            \
    Det_ReportError(                                                           \
                     (uint16)GPT_MODULE_ID,                                    \
                     GPT_INSTANCE_ID,                                          \
                     GPT_SID_GETVERSIONINFO,                                   \
                     GPT_E_PARAM_POINTER                                       \
                   );/* End of report to  DET */                               \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    /* (pointer VersionInfoPtr is not checked for NULL pointer) */             \
    /* return version information GPT181: */                                   \
    /* Get GPT Vendor ID */                                                    \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = GPT_VENDOR_ID;        \
    /* Get GPT Module ID */                                                    \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = GPT_MODULE_ID;        \
    /* Get GPT module Software major version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                       (uint8)GPT_SW_MAJOR_VERSION;            \
    /* Get GPT module Software minor version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                       (uint8)GPT_SW_MINOR_VERSION;            \
    /* Get GPT module Software patch version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                       (uint8)GPT_SW_PATCH_VERSION;            \
  }                                                                            \
}/* end of Gpt_GetVersionInfo() */
#elif ((GPT_VERSION_INFO_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_OFF))
#define Gpt_GetVersionInfo(VersionInfoPtr)                                     \
{                                                                              \
  /* (pointer VersionInfoPtr is not checked for NULL pointer) */               \
  /* return version information GPT181: */                                     \
  /* Get GPT Vendor ID */                                                      \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = GPT_VENDOR_ID;          \
  /* Get GPT Module ID */                                                      \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = GPT_MODULE_ID;          \
  /* Get GPT module Software major version */                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =                 \
                                       (uint8)GPT_SW_MAJOR_VERSION;            \
  /* Get GPT module Software minor version */                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =                 \
                                       (uint8)GPT_SW_MINOR_VERSION;            \
  /* Get GPT module Software patch version */                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =                 \
                                       (uint8)GPT_SW_PATCH_VERSION;            \
}/* end of Gpt_GetVersionInfo() */
#else
#define Gpt_GetVersionInfo(VersionInfoPtr) ERROR_Gpt_GetVersionInfo_NOT_SELECTED
#endif

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* GPT262: The Type definitions for Gpt_PBcfg.c */
/* Timer Channel notification function pointer type in normal mode */
/* GPT232, GPT087:, GPT207: */
typedef void(*Gpt_NotificationPtrType)(void);

/* Channel wakeup TRUE/FALSE */
typedef boolean Gpt_EnableWakeupType;

/* [cover parentID=DS_AS_GPT358] */
/* Numeric ID of a GPT Channel */
typedef uint8 Gpt_ChannelType;


/* [cover parentID=DS_AS_GPT359] */
/* The timeout value given in timer ticks. Used for reading the current timer
value/setting periodic timer values (in number of ticks) up to hours */
typedef uint32 Gpt_ValueType;
/* [/cover] */


/* [cover parentID=DS_AS_GPT360,DS_NAS_PR643] */
/* Allows selection of different power modes Normal/sleep */
typedef uint8 Gpt_ModeType;
/* [/cover] */

/*Allows selection of different Clock Types */
typedef uint8 Gpt_ClockType;

/*Allows selection of Channel Sginal Type */
typedef uint8 Gpt_SignalType;

/* Type to specify a Unique Number for TOM/ATOM channel
   among all GTM channels. */
typedef uint8 Gpt_GtmGlobalChannelNoType;

/* Channel Status indicators*/
#define GPT_CHANNEL_UNINITIALIZED (uint8)0
#define GPT_CHANNEL_INITIALIZED (uint8)1
#define GPT_CHANNEL_STARTED     (uint8)2
#define GPT_CHANNEL_STOPPED     (uint8)3
#define GPT_CHANNEL_EXPIRED     (uint8)4


/* Channel specific configuration type of GPT driver - GPT184: */
typedef struct Gpt_ChannelConfig
{
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  Gpt_NotificationPtrType GptNotificationPtr;
#endif

#if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
      && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
  /* Wakeup information to EcuM_SetWakeupEvent - GPT235: */
  EcuM_WakeupSourceType GptChannelWakeupInfo;
#endif

  /* The AssignedHwUnit is packed data containing TOM/ATOM channel used */
    Gpt_GtmGlobalChannelNoType AssignedHwUnit;

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
  /* Channel wakeup capability TRUE/FALSE - GPT188: */
  Gpt_EnableWakeupType GptEnableWakeupState;
#endif

  /* Channel mode - GPT_MODE_CONTINUOUS/GPT_MODE_ONESHOT - GPT185:, GPT186: */
  Gpt_ModeType GptChannelMode;
  
#if (GPT_SAFETY_ENABLE == STD_ON)
  Gpt_SignalType SignalType; /*Channel Signal Type */
#endif
  
  Gpt_ClockType ClockSelect;  /*Channel Clock Select */
  
} Gpt_ChannelConfigType;

/* Module specific configuration type of GPT Driver - GPT183: */
/* [cover parentID=DS_AS_GPT357] */
typedef struct Gpt_ConfigType
{
#if (GPT_SAFETY_ENABLE == STD_ON)
  const uint32 Marker; /* Start Marker for GptConfigPtr */
#endif
  /* Pointer to set of channel specific configuration */
  const Gpt_ChannelConfigType* ChannelConfigPtr;

  /* Maximum number of channels in the given set of Configuration */
  Gpt_ChannelType GptMaxChannels;

} Gpt_ConfigType;
/* [/cover] */
/* [/cover] */

/* To find GPT channel from Global channel number, used by
Gpt_lGtmChannelIdentifier */
typedef struct
{
  uint8 ModuleId;
  uint8 ModuleNo;
  uint8 ChannelNo;
  uint8 GroupNo; 
}Gpt_ChannelIdentifierType;
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define GPT_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of Gpt Post Build Configuration */
extern const struct  Gpt_ConfigType Gpt_ConfigRoot[];
#define GPT_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/



/******************************************************************************/
#define GPT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : void Gpt_Init(const Gpt_ConfigType *ConfigPtr)                    **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in): ConfigPtr (Pointer to a selected configuration structure) **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Driver Module Initialization function.Service for            **
**               initializing the hardware timer module according to          **
**               a configuration set referenced by ConfigPtr.                 **
**                                                                            **
*******************************************************************************/

extern void Gpt_Init(const Gpt_ConfigType *ConfigPtr);

/******************************************************************************/
#if (GPT_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
**                                                                            **
** Syntax          : void Gpt_InitCheck (const Gpt_ConfigType* ConfigPtr)     **
**                                                                            **
** Service ID      :    None                                                  **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    ConfigPtr - Pointer to GPT Driver configuration set   **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    None                                                  **
**                                                                            **
** Description     : This routine verifies the initialization the GPT driver. **
**                   Note: The sequence should be                             **
**                    1)Call Gpt_Init                                         **
**                    2)Call Gpt_InitCheck                                    **
**                                                                            **
*******************************************************************************/


#if (GPT_INITCHECK_API == STD_ON)
extern Std_ReturnType Gpt_InitCheck (const Gpt_ConfigType* ConfigPtr);
#else
#define Gpt_InitCheck(ConfigPtr)  ERROR_Gpt_InitCheck_NOT_SELECTED
#endif /* (GPT_INIT_CHECK_API == STD_ON) */

/*******************************************************************************
** Traceability    :    [cover parentID=]                                     **
**                                                                            **
** Syntax          :    Gpt_ModeType Gpt_GetMode()                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :    None                                                  **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    None                                                  **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    GPT_MODE_UNINITIALIZED - GPT driver not initialised   **
**                      GPT_MODE_NORMAL - GPT in Normal Mode                  **
**                      GPT_MODE_SLEEP - GPT in Sleep Mode                    **
**                                                                            **
** Description     :    To ascertain the Mode of the GPT driver.              **
**                                                                            **
*******************************************************************************/
#if (GPT_GETMODE_API == STD_ON)
extern Gpt_ModeType Gpt_GetMode(void);
#else
#define Gpt_GetMode()  ERROR_Gpt_GetMode_NOT_SELECTED
#endif /* (GPT_GETMODE_API == STD_ON) */

#endif /* (GPT_SAFETY_ENABLE == STD_ON) */

/******************************************************************************/

/*******************************************************************************
** Syntax : void Gpt_DeInit(void)                                             **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Driver Module Deinitialization function.Service for          **
**               deinitializing all hardware timer channels to their          **
**               power on reset state.                                        **
**                                                                            **
*******************************************************************************/
#if (GPT_DEINIT_API == STD_ON)
extern void Gpt_DeInit(void);
#else
#define Gpt_DeInit()  ERROR_Gpt_DeInit_NOT_SELECTED
#endif

/******************************************************************************/


/*******************************************************************************
** Syntax : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)         **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Channel: Numeric identifier of the GPT channel            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: Gpt_ValueType (Elapsed timer value in number of ticks )      **
**                                                                            **
** Description : Service for querying the time already elapsed. In one shot   **
**               mode, this is the value relative to the point in time,       **
**               the channel has been started with Gpt_StartTimer             **
**               (calculated by the normal operation function by subtracting  **
**               the current minus the initial timer value and returning the  **
**               absolute value). In continuous mode, the function returns    **
**               the timer value relative to the last notification /the start **
**               of the channel.                                              **
**                                                                            **
*******************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)
extern Gpt_ValueType Gpt_GetTimeElapsed
(
  Gpt_ChannelType Channel
);
#else
#define Gpt_GetTimeElapsed(Channel)  ERROR_Gpt_GetTimeElapsed_NOT_SELECTED
#endif

/******************************************************************************/


/*******************************************************************************
** Syntax : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)       **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Channel: Numeric identifier of the GPT channel            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: Gpt_ValueType (Remaining timer value in number of ticks )    **
**                                                                            **
** Description : This function returns the timer value remaining until the    **
**               next timeout period will expire (calculated by the normal    **
**               operation function by subtracting the timeout minus the      **
**               current timer value and returning the absolute value).       **
**                                                                            **
*******************************************************************************/
#if (GPT_TIME_REMAINING_API == STD_ON)
extern Gpt_ValueType Gpt_GetTimeRemaining
(
  Gpt_ChannelType Channel
);
#else
#define Gpt_GetTimeRemaining(Channel)  ERROR_Gpt_GetTimeRemaining_NOT_SELECTED
#endif

/******************************************************************************/


/*******************************************************************************
** Syntax : Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value)       **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Channel :Numeric identifier of the GPT channel            **
**                  Value   :Timeout period (in number of ticks) after a      **
**                           notification shall occur.                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Service for starting the selected timer channel with a       **
**               defined timeout period. After this timeout period, a         **
**               notification can be invoked (if enabled).                    **
*******************************************************************************/
extern void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value);

/******************************************************************************/


/*******************************************************************************
** Syntax : void Gpt_StopTimer(Gpt_ChannelType Channel)                       **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Channel: Numeric identifier of the GPT channel            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Service for stopping the selected timer channel.             **
**                                                                            **
*******************************************************************************/
extern void Gpt_StopTimer(Gpt_ChannelType Channel);

/******************************************************************************/

/*******************************************************************************
** Syntax : void Gpt_EnableNotification(Gpt_ChannelType Channel)              **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Channel: Numeric identifier of the GPT channel            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Service for enabling the notification for a channel during   **
**               runtime.                                                     **
**                                                                            **
*******************************************************************************/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)

extern void Gpt_EnableNotification
(
  Gpt_ChannelType Channel
);
#else
#define Gpt_EnableNotification(Channel) \
  ERROR_Gpt_EnableNotification_NOT_SELECTED

#endif

/******************************************************************************/


/*******************************************************************************
** Syntax : void Gpt_DisableNotification(Gpt_ChannelType Channel)             **
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in):   Channel: Numeric identifier of the GPT channel          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Service for disabling the notification for a channel during  **
**               runtime. Note, that stopping a timer automatically disables  **
**               notification on this channel.                                **
**                                                                            **
*******************************************************************************/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)

extern void Gpt_DisableNotification
(
  Gpt_ChannelType Channel
);
#else
#define Gpt_DisableNotification(Channel) \
        ERROR_Gpt_DisableNotification_NOT_SELECTED

#endif

/******************************************************************************/


/*******************************************************************************
** Syntax : void Gpt_SetMode(Gpt_ModeType mode)                               **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in): mode (GPT_MODE_NORMAL/GPT_MODE_SLEEP)                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Service for GPT mode selection. This service shall set the   **
**               operation mode to the given mode parameter.                  **
**                                                                            **
*******************************************************************************/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)

extern void Gpt_SetMode
(
  Gpt_ModeType Mode
);
#else
#define Gpt_SetMode(Mode) ERROR_Gpt_SetMode_NOT_SELECTED
#endif

/******************************************************************************/


/*******************************************************************************
** Syntax : void Gpt_DisableWakeup( Gpt_ChannelType channel)                  **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Channel: Numeric identifier of the GPT channel            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service shall disable the wakeup notification of a      **
**               single GPT channel.                                          **
**                                                                            **
*******************************************************************************/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)

extern void Gpt_DisableWakeup
(
  Gpt_ChannelType Channel
);
#else
#define Gpt_DisableWakeup(Channel) ERROR_Gpt_DisableWakeup_NOT_SELECTED
#endif

/******************************************************************************/


/*******************************************************************************
** Syntax : void Gpt_EnableWakeup ( Gpt_ChannelType channel)                  **
**                                                                            **
** Service ID:  0x0B                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Channel: Numeric identifier of the GPT channel            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service shall Enable the wakeup notification of a       **
**               single GPT channel.                                          **
**                                                                            **
*******************************************************************************/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)

extern void Gpt_EnableWakeup
(
  Gpt_ChannelType Channel
);
#else
#define Gpt_EnableWakeup(Channel) ERROR_Gpt_EnableWakeup_NOT_SELECTED
#endif

/******************************************************************************/

/*******************************************************************************
** Syntax : void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)          **
**                                                                            **
** Service ID:  0x0C                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): wakeupSource                                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Checks if a wakeup capable GPT channel is the source for a   **
** wakeup event and calls the ECU state manager service EcuM_SetWakeupEvent   **
** in case of a valid GPT channel wakeup event.                               **
**                                                                            **
*******************************************************************************/
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)                                 \
  && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
extern void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#else
#define Gpt_CheckWakeup(wakeupSource) ERROR_Gpt_CheckWakeup_NOT_SELECTED
#endif

#define GPT_STOP_SEC_CODE
#include "MemMap.h"

#define GPT_START_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax : void Gpt_Isr(uint8 ChannelNo)                                     **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): ChannelNo - GPT Channel Number                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Interrupt service routine called on any timer event.         **
**                                                                            **
*******************************************************************************/
extern void Gpt_Isr(uint8 ChannelNo);
#define GPT_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/******************************************************************************/


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* GPT_H */
