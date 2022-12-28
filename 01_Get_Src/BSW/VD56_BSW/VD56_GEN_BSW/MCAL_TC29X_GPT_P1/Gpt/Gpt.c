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
**  $FILENAME   : Gpt.c $                                                    **
**                                                                           **
**  $CC VERSION : \main\71 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-20 $                                               **
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
/*  TRACEABILITY: [cover parentID=DS_AS_GPT278,
    DS_NAS_PR912_1,DS_NAS_PR912_2,DS_NAS_PR912_3,
    DS_NAS_PR624_PR759_PR760_PR761,DS_AS_HisGen0001]
**                                                                            **
**                                                                            **
**  [/cover]                                                                  */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* GPT293: Gpt.c shall include Gpt.h,
   GPT260: Gpt.c has access to the Gpt_Cfg.h through the Gpt.h file. */
#include "Gpt.h"

#include "Gpt_Local.h"




/* MISRA Rule Violation 19.1,17.4:
   a) Declaration before #include. Because of Memmap.h inclusion, this cannot
      be avoided.
   b) Header file 'MemMap.h' repeatedly included but does not have a standard
      include guard. Memmap.h file is prepared according to Autosar rules and
      this cannot be avoided.
   c) pointer arithmetic other than array indexing used. this cannot be avoided.
*/




/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* Integer Constants */
/* To set the bit */
#define GPT_BIT_SET            (1U)
/* To reset the bit */
#define GPT_BIT_RESET          (0U)
/* To clear the variable */
#define GPT_CLEAR_VARIABLE     (0U)
/* Clock divider Position */
#define CLOCK_DIV_POS          (12U)
/* SOMP bit position */
#define SOMP_BIT_POS           (2U)

/* TOM Bit positions */
#define GPT_GTM_CTRL_OSM      (26U)
/* Value to be written onto the notify register to clear the interrupts */
#define GPT_CLEAR_INTERRUPTS (0x00000003U)

#define GPT_BITS_PER_CHANNEL (2U)
#define GPT_GTM_CHANNEL_ENABLE (2U)
#define GPT_GTM_CHANNEL_ENABLE_UL (2UL)


#define GPT_SETNOTIF_FLAG (1U)

#define GPT_SETWAKEUP_FLAG  (2U)


/* Timer Parameter */
#define GPT_GTM_TOM_TIMER_MAX (0xFFFFU)
#define GPT_GTM_ATOM_TIMER_MAX (0xFFFFFFU)

#define GPT_GTM_INVALID_NUMBER (0xFFU)



/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define GPT_START_SEC_CODE
#include "MemMap.h"


#if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )

#if (GPT_DEV_ERROR_DETECT == STD_ON)
#if (GPT_DEINIT_API == STD_ON)
/* To check DET errors in Gpt_DeInit API */
static uint32 Gpt_lDeInitDetCheck(void);
#endif 
/* End of (GPT_DEINIT_API == STD_ON) */
#endif

#if ( GPT_WAKEUP_FUNCTIONALITY_API == STD_ON )
/* To check DET and Safety errors in Gpt_EnableWakeup & 
Gpt_DisableWakeup APIs */
static uint32 Gpt_lWakeupDetSafetyCheck( Gpt_ChannelType Channel,
                                            uint8 Gpt_Sid );
#if ( GPT_SAFETY_ENABLE == STD_ON )
static void Gpt_lSafeCheckMode(
                         Gpt_ChannelType Channel);
#endif
#endif 
 /*End of #if ( GPT_WAKEUP_FUNCTIONALITY_API == STD_ON ) */

#if ( GPT_SAFETY_ENABLE == STD_ON )
#if (GPT_INITCHECK_API == STD_ON)
static uint32 Gpt_lCheckChannelIdentifier(
                                Gpt_GtmGlobalChannelNoType GlobalChannelNumber,
                                Gpt_ChannelType Channel
                                          );
#endif
#endif

#endif 
/* End of #if (GPT_DEV_ERROR_DETECT == STD_ON) || 
                                   ( GPT_SAFETY_ENABLE == STD_ON )*/



static void Gpt_lChannelInit(void);

#if (GPT_ONESHOT_USED == STD_ON)
static void Gpt_lGtmSetOsm(Gpt_ChannelType Channel);
#endif 
/*End of #if (GPT_ONESHOT_USED == STD_ON)*/

static void Gpt_lGtmStopTimer(Gpt_ChannelType Channel);


static Gtm_GptChannelStatusType Gpt_lGtmStartTimer(
                                Gpt_ChannelType Channel,
                                uint32 TimeOutVal
                                          );

static void Gpt_lSetChannelIdentifier(
                                Gpt_GtmGlobalChannelNoType GlobalChannelNumber,
                                Gpt_ChannelType Channel
                                          );

#if (GPT_DEINIT_API == STD_ON)
static void Gpt_lResetChannels(void);
#endif 
/* #if (GPT_DEINIT_API == STD_ON) */


#if (GPT_ONESHOT_USED == STD_ON)
static _INLINE_ void Gpt_lGtmHandleOsm(
                               Gpt_ChannelType Channel);
#endif 
/*End of #if (GPT_ONESHOT_USED == STD_ON)*/



#if (GPT_ONESHOT_USED == STD_ON)
static _INLINE_ boolean Gpt_lModeOsm(Gpt_ModeType ChannelMode);
#endif 
/*End of #if (GPT_ONESHOT_USED == STD_ON)*/

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
static _INLINE_ uint8 Gpt_lGetNotifFlag(Gpt_ChannelType Channel);
static _INLINE_ boolean Gpt_lCheckForNotifCall(uint8 NotifFlag);
#endif 
/*End of #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)*/

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) ||    \
     (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON))
static void Gpt_lGtmIrqModify(Gpt_ChannelType Channel,
                         uint8 InterruptFlag);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
static uint32 Gpt_lGtmGetTimeRemaining(Gpt_ChannelType Channel);
#endif 
/* #if (GPT_TIME_REMAINING_API == STD_ON) */

#if (GPT_TIME_ELAPSED_API == STD_ON)
static uint32 Gpt_lGtmGetTimeElapsed(Gpt_ChannelType Channel);
#endif 
/* #if (GPT_TIME_ELAPSED_API == STD_ON) */

#define GPT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


#if(GPT_PB_FIXEDADDR == STD_OFF)
/* Start 32 bit variable section */
#define GPT_START_SEC_VAR_32BIT
#include "MemMap.h"
/* To store the Gpt driver configuration pointer */
const Gpt_ConfigType* Gpt_kConfigPtr;
/* Stop 32 bit variable section */
#define GPT_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#endif 
/* #if(GPT_PB_FIXEDADDR == STD_OFF) */

#if(GPT_PB_FIXEDADDR == STD_ON)
#define GPT_START_SEC_CONST_32BIT
#include "MemMap.h"
/* The config pointer is initialised to first instance of configuration */
const Gpt_ConfigType* const Gpt_kConfigPtr = &Gpt_ConfigRoot[0];
#define GPT_STOP_SEC_CONST_32BIT
#include "MemMap.h"
#endif 
/* #if(GPT_PB_FIXEDADDR == STD_ON) */

/* Start 8 bit variable section */
#define GPT_START_SEC_VAR_8BIT
#include "MemMap.h"

/* Driver current mode (GPT_MODE_SLEEP/GPT_MODE_NORMAL) */
/* Variable to store channel status i.e. Channel Initialized/started/stopped/
expired/Uninitialized */
/* Exporting Global variables for Debug module */
/* [cover parentID=DS_AS40X_GPT337,DS_AS40X_GPT334_GPT335,DS_AS40X_GPT336] */

volatile uint8 Gpt_DriverMode;

uint8 Gpt_ChannelIndex[GPT_MAX_CHANNELS];

Gpt_ChannelIdentifierType Gpt_ChannelIdentifier[GPT_MAX_CHANNELS];

/* Stop 8 bit variable section */
#define GPT_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#if( GPT_SAFETY_ENABLE == STD_ON)
/* Status variable for ASIL channels */
#if (GPT_MAX_ASIL_CHANNELS != 0U)

#define GPT_START_SEC_ASIL0_VAR_8BIT
#include "MemMap.h"
uint8 Gpt_AsilChannelStatus[GPT_MAX_ASIL_CHANNELS];
#define GPT_STOP_SEC_ASIL0_VAR_8BIT
#include "MemMap.h"

#endif
#endif
/* Status variable for QM channels */
#if (GPT_MAX_QM_CHANNELS != 0U)

/* Start 8 bit variable section */
#define GPT_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 Gpt_QMChannelStatus[GPT_MAX_QM_CHANNELS];
/* Stop 8 bit variable section */
#define GPT_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif

/* [/cover]  */




#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || \
                                    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/* Variable to store Notification and WakeUp Flag for all channels*/
/* Bit 1 gives Notification flag info and Bit 2 gives WakeUp flag info */
#if( GPT_SAFETY_ENABLE == STD_ON)
/* Flag for ASIL channels */
#if (GPT_MAX_ASIL_CHANNELS != 0U)

#define GPT_START_SEC_ASIL0_VAR_8BIT
#include "MemMap.h"
uint8 Gpt_AsilFlag[GPT_MAX_ASIL_CHANNELS];

#define GPT_STOP_SEC_ASIL0_VAR_8BIT
#include "MemMap.h"

#endif
#endif
/* Flag for QM channels */
#if (GPT_MAX_QM_CHANNELS != 0U)

#define GPT_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 Gpt_QMFlag[GPT_MAX_QM_CHANNELS];

#define GPT_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif

#endif 
/*End of #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
                           || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)) */



/* Start 32 bit fast variable section */
#define GPT_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
/* Variable to store the channel wakeup info due to which GPT woke up */
static EcuM_WakeupSourceType Gpt_WakeupChannelInfo;
#endif
#endif 
/*End of #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)*/

/* Stop 32 bit fast variable section */
#define GPT_STOP_SEC_VAR_FAST_32BIT
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* Start GPT code section */
#define GPT_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT280_GPT257,DS_AS_GPT006_GPT068,
   DS_AS_GPT185_REQ1_REQ2,DS_AS_GPT176_3_GPT294_GPT178_3,
   DS_AS_GPT294_GPT332_2,DS_AS_GPT107_GPT339_GPT258,DS_AS_GPT307,DS_AS_GPT309,
   DS_AS_GPT352_GPT353_GPT354_GPT355_GPT356,DS_AS_GPT176_2_GPT178_2,
   DS_MCAL_SWSC_GPT500,DS_MCAL_SWSC_GPT502_1]

** Syntax : void Gpt_Init(const Gpt_ConfigType *ConfigPtr)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): ConfigPtr - Pointer to a selected configuration structure **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : GPT Driver Module Initialization function.Service for        **
**               initializing the hardware timer module according to          **
**               a configuration set referenced by ConfigPtr                  **
** Implementation Note: There is no separate interrupt invocation for         **
** notification and Wakeup functionality both are handled in a single         **
** interrupt handler                                                          **
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
  #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||    \
                                     (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
  uint8 counter;
  #endif
  uint8 Channel;
  Gpt_ChannelType MaxChannels;
  #if (GPT_ONESHOT_USED == STD_ON)
  Gpt_ModeType ChannelMode;
  #endif
  const Gpt_ChannelConfigType* LocalGptChannelPtr;
  Gpt_GtmGlobalChannelNoType HwUnit;
  uint8 *DataPtr;


  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;

  ErrorFlag = 0U;
  /* GPT294: Det Check for a NULL pointer - GPT257: For PB variant The
  initialization function shall always have a pointer as a parameter, for PC
  variant no configuration set shall be given. Instead a NULL pointer is passed
  to the initialization function. Ref: GPT219 */
  #if(GPT_PB_FIXEDADDR == STD_OFF)
  if (ConfigPtr == NULL_PTR)
  #else
  /* The config pointer is initialised to first instance of configuration */
  if ( ConfigPtr != Gpt_kConfigPtr )
  #endif 
  /* #if(GPT_PB_FIXEDADDR == STD_OFF) */
  {
    #if (GPT_DEV_ERROR_DETECT == STD_ON)  
    Det_ReportError(GPT_MODULE_ID,GPT_INSTANCE_ID,
                     GPT_SID_INIT,GPT_E_PARAM_POINTER );
    #endif
    
    #if (GPT_SAFETY_ENABLE == STD_ON)
    /* Report Safety Error */
    SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                     GPT_SID_INIT, GPT_E_PARAM_POINTER);
    #endif
    /*Error flag is set*/
    ErrorFlag = GPT_ERROR_SET;
  }
  #if (GPT_DEV_ERROR_DETECT == STD_ON)  
  /* GPT307: If DET is enabled: if called when the GPT driver already
  initialized, raise the DET GPT_E_ALREADY_INITIALIZED and return without
  any action. */
  if (Gpt_DriverMode != GPT_MODE_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     GPT_SID_INIT, GPT_E_ALREADY_INITIALIZED );
    ErrorFlag = GPT_ERROR_SET; 
    /* Set ErrorFlag */
  }
  #endif
  #if (GPT_SAFETY_ENABLE == STD_ON)
  if ((ErrorFlag != GPT_ERROR_SET) &&
      (ConfigPtr->Marker != ((uint32)GPT_MODULE_ID << 16U)))
  {
    /* Report Safety Error */
    SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                     GPT_SID_INIT, GPT_E_PARAM_POINTER);
    ErrorFlag = GPT_ERROR_SET;
  }
  #endif 
  /*End Of MCU_SAFETY_ENABLE*/
  if(GPT_ERROR_SET != ErrorFlag )
  #endif
  /*(GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )*/
  {
    /* Initialization of global variables ( local to Gpt.c ) */
    #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||   \
                                (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
    /* GPT107: The function Gpt_Init shall disable all notifications */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    #if (GPT_MAX_ASIL_CHANNELS != 0U)
    for(counter=0U; counter<GPT_MAX_ASIL_CHANNELS; counter++)
    {
        Gpt_AsilFlag[counter] = GPT_CLEAR_VARIABLE;
    }
    #endif
    #endif
    #if (GPT_MAX_QM_CHANNELS != 0U)
    for(counter=0U; counter<GPT_MAX_QM_CHANNELS; counter++)
    {
        Gpt_QMFlag[counter] = GPT_CLEAR_VARIABLE;
    }
    #endif
    #endif 
    /* ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||   \
                                (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)) */

    /*
    GPT006:The function Gpt_Init shall initialize the hardware timer module
           according to a configuration set referenced by ConfigPtr.
    GPT068:The function Gpt_Init shall only initialize the configured resources.
           Resources that are not configured in the configuration file shall
           not be touched.
    */
    #if(GPT_PB_FIXEDADDR == STD_OFF)
    Gpt_kConfigPtr = ConfigPtr;
    #endif



    /* Get pointer to channel config */
    LocalGptChannelPtr = (ConfigPtr->ChannelConfigPtr);


    /* Get the maximum number of channels */
    MaxChannels = ConfigPtr->GptMaxChannels;

    for ( Channel = 0U; Channel < MaxChannels; Channel++ )
    {
      /* The AssignedHwUnit contains TOM/ATOM channel used */
      HwUnit = (LocalGptChannelPtr->AssignedHwUnit);
      
      /* Set GPT channel identifier in global variable */
      Gpt_lSetChannelIdentifier(HwUnit, Channel);
      
      /* Increment Channel pointer */
      LocalGptChannelPtr++ ;
    }

    Gpt_lChannelInit();
    
    #if (GPT_ONESHOT_USED == STD_ON)
    /* Get pointer to channel config */
    LocalGptChannelPtr = (ConfigPtr->ChannelConfigPtr);
    #endif

    /* Initialize all channels */
    for ( Channel = 0U; Channel < MaxChannels; Channel++ )
    {
      /*If Any channel is configured for Oneshot mode,then configure it*/
      #if (GPT_ONESHOT_USED == STD_ON)

      /* Get Channel Mode*/
      ChannelMode = LocalGptChannelPtr->GptChannelMode;

      /*
      GPT205:[1] If the hardware allows for only one usage of the register,the
      driver module implementing that functionality is responsible for
      initializing the register
      GPT205:[3] The MCU Driver initializes the registers which affect other
      Drivers like PWM, ICU etc
      */
      
      /* Is channel is One shot Mode */
      if (Gpt_lModeOsm(ChannelMode))
      {
        Gpt_lGtmSetOsm(Channel);
      }

      /* Increment Channel pointer */
      LocalGptChannelPtr++ ;
      #endif 
      /*End of #if (GPT_ONESHOT_USED == STD_ON)*/
      
      
      /* Initialize Channel Status Flags */
      DataPtr = Gpt_lGetStatusVarAddr(Channel);
      *DataPtr = GPT_CHANNEL_INITIALIZED;

    }
    /*End of for loop*/
    /* Default mode is GPT_MODE_NORMAL Refer Bugzilla 24191 */
    Gpt_DriverMode = GPT_MODE_NORMAL;
  } /*End of if(GPT_ERROR_SET != ErrorFlag )*/

}/* End of Gpt_Init */
/******************************************************************************/



#if (GPT_DEINIT_API == STD_ON) 
/* GPT194: */
/*******************************************************************************
** Traceability :[cover parentID=DS_AS_GPT281,DS_AS_GPT162_GPT308,
   DS_AS40X_GPT363,DS_AS_GPT105,DS_AS_GPT220_1_GPT234_GPT332_3,
   DS_AS_GPT176_4_GPT178_4]
** Syntax : void Gpt_DeInit(void)                                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Driver Module De initialization function.Service for         **
**               deinitializing all hardware timer channels to their          **
**               power on reset state.                                        **
**                                                                            **
*******************************************************************************/
void Gpt_DeInit(void)
{
  #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||   \
                                    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
  uint8 counter;
  #endif
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  uint32 ErrorFlag;

  /* GPT220: & GPT234: Call DET check,If DET occurred then return without
     executing the routine */
  ErrorFlag = Gpt_lDeInitDetCheck();

  if(GPT_ERROR_SET != ErrorFlag )
  #endif 
  /*(GPT_DEV_ERROR_DETECT == STD_ON)*/
  {
    #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||          \
                                    (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
    /* GPT105: The function Gpt_DeInit shall disable all notifications */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    #if (GPT_MAX_ASIL_CHANNELS != 0U)
    for(counter=0U; counter<GPT_MAX_ASIL_CHANNELS; counter++)
    {
        Gpt_AsilFlag[counter] = GPT_CLEAR_VARIABLE;
    }
    #endif
    #endif
    #if (GPT_MAX_QM_CHANNELS != 0U)
    for(counter=0U; counter<GPT_MAX_QM_CHANNELS; counter++)
    {
        Gpt_QMFlag[counter] = GPT_CLEAR_VARIABLE;
    }
    #endif
    #endif 
    /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */


    /* GPT008,GPT088,GPT105,GPT161 & GPT162,Call to deinitialize the driver*/
    Gpt_lResetChannels();

    /* Mode is set to uninitialized */
    Gpt_DriverMode = GPT_MODE_UNINITIALIZED;
  } /* if(GPT_ERROR_SET != ErrorFlag ) */
}/* End of Gpt_DeInit */

/******************************************************************************/
#endif 
/*(GPT_DEINIT_API == STD_ON)*/



/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT284,DS_AS_GPT115,DS_AS_GPT224_1,
   DS_AS_GPT218_1,DS_AS_GPT176_7_GPT212_1_GPT178_7,DS_AS_GPT084_1,
   ,DS_AS_GPT274_1,DS_AS_GPT176_8_GPT212_2_GPT178_8,DS_AS40X_GPT332_6,
   DS_AS40X_GPT364_GPT274_2,DS_AS_GPT218_2,DS_AS_GPT224_2,DS_AS_GPT084_2,
   DS_MCAL_SWSC_GPT502_4]

** Syntax : Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value)       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:    reentrant                                                   **
**                                                                            **
** Parameters (in): Channel :Channel ID                                       **
**                  Value   :Timeout period (in number of ticks) after a      **
**                           notification shall occur if Enabled.             **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Service for starting the selected timer channel with a       **
**               defined Timeout period. After this Timeout period, a         **
**               notification can be invoked (if enabled)                     **
** Implementation Notes:                                                      **
** 1) GPT115: Re-entrant capability is only allowed if the caller take care   **
**    that there is no simultaneous usage of the same channel.                **
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel /* GPT059: */,
                     Gpt_ValueType Value /* GPT060: */)
{
  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32  ErrorFlag1;
  #endif
  Gtm_GptChannelStatusType ErrorFlag2;
  uint8 *DataPtr;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  uint8 ChannelStatus;
  #endif

  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  ErrorFlag1 = 0U;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* DET check for Init not done - GPT224: */
  if (Gpt_DriverMode == GPT_MODE_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     GPT_SID_STARTTIMER, GPT_E_UNINIT );
    ErrorFlag1 = GPT_ERROR_SET; /* Set Error Flag */
  }
  else
  #endif
  {
    /* GPT module is Initialized */
    /* Check for channel within range - GPT212: */
    if( Channel >= (Gpt_kConfigPtr->GptMaxChannels))
    {
      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                       GPT_SID_STARTTIMER, GPT_E_PARAM_CHANNEL);
      #endif
      #if (GPT_SAFETY_ENABLE == STD_ON)
      /* Report Safety Error */
      SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                       GPT_SID_STARTTIMER, GPT_E_PARAM_CHANNEL);
      #endif 
      ErrorFlag1 = GPT_ERROR_SET; /* Set Error Flag */
    }
    else
    {
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
      DataPtr = Gpt_lGetStatusVarAddr(Channel);
      ChannelStatus = *DataPtr;
      if( ChannelStatus == GPT_CHANNEL_STARTED)
      {
        /* Report to DET */
        Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                         GPT_SID_STARTTIMER, GPT_E_BUSY);
        ErrorFlag1 = GPT_ERROR_SET; /* Set Error Flag */
      }
    #endif 
    }
  }
  if(ErrorFlag1 != GPT_ERROR_SET)
  #endif 
  /* #if (GPT_DEV_ERROR_DETECT == STD_ON) ||   \
                                    ( GPT_SAFETY_ENABLE == STD_ON )*/
  {
    ErrorFlag2 = (Gtm_GptChannelStatusType)Gpt_lGtmStartTimer(Channel,Value);
    if(ErrorFlag2 == GTM_GPT_WRONG_PARAM)
    {
        #if (GPT_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                       GPT_SID_STARTTIMER, GPT_E_PARAM_VALUE);
        #endif 
        /* #if (GPT_DEV_ERROR_DETECT == STD_ON) */
        #if (GPT_SAFETY_ENABLE == STD_ON)
        SafeMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
                       GPT_SID_STARTTIMER, GPT_E_PARAM_VALUE);
        #endif
    }

    if(ErrorFlag2 == GTM_GPT_CHANNEL_STARTED)
    {
      DataPtr = Gpt_lGetStatusVarAddr(Channel);
      /* Set channel started */
      *DataPtr = GPT_CHANNEL_STARTED;
    }
  }
}/* End of Gpt_StartTimer */
/******************************************************************************/


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT285,DS_AS_GPT116,
   DS_AS_GPT176_9_GPT213_GPT178_9,DS_AS_GPT225_GPT178,DS_AS_GPT099_1,
   DS_AS_GPT013,DS_AS40X_GPT332_7,DS_AS40X_GPT343,DS_AS40X_GPT344,
   DS_MCAL_SWSC_GPT502_5]
** Syntax : void Gpt_StopTimer(Gpt_ChannelType Channel)                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:    reentrant - GPT116                                          **
**                                                                            **
** Parameters (in): Channel :Channel ID                                       **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Service for stopping the selected timer channel.             **
**               GPT013: , GPT099:, GPT103:, GPT116:                          **
*******************************************************************************/
void Gpt_StopTimer (Gpt_ChannelType Channel)
{

  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  #endif
  uint8 *DataPtr;
  uint8 ChannelStatus;
  


  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  ErrorFlag = 0U;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* DET check for Init is done - GPT225:*/
  if (Gpt_DriverMode == GPT_MODE_UNINITIALIZED)
  {
    /* Report to  DET */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     GPT_SID_STOPTIMER, GPT_E_UNINIT);
    ErrorFlag = GPT_ERROR_SET; /* Set ErrorFlag */
  }
  else
  #endif
  {
    /* Check for channel out of range - GPT213: */
    if ( Channel >= (Gpt_kConfigPtr->GptMaxChannels))
    { 
      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to  DET */
      Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                       GPT_SID_STOPTIMER, GPT_E_PARAM_CHANNEL);
      #endif
      #if (GPT_SAFETY_ENABLE == STD_ON)
      /* Report Safety Error */
      SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                       GPT_SID_STOPTIMER, GPT_E_PARAM_CHANNEL);
      #endif
      ErrorFlag = GPT_ERROR_SET;  /* Set ErrorFlag */
    }
    else
    {
      /*Do Nothing*/
    }
    /* GPT099: No DET if stopping a channel which is not started */
  }
  if ( GPT_ERROR_SET != ErrorFlag )
  #endif 
  /*(GPT_DEV_ERROR_DETECT == STD_ON)*/

  {
    DataPtr = Gpt_lGetStatusVarAddr(Channel);
    ChannelStatus = *DataPtr;
    if ( ChannelStatus == GPT_CHANNEL_STARTED )
    {
      /* Stop the required timer channel */
      Gpt_lGtmStopTimer(Channel);
      /* Set status to channel Stopped */
      *DataPtr = GPT_CHANNEL_STOPPED;
    }/* End of if ( ChannelStatus == GPT_CHANNEL_STARTED ) */
  }

}/* End of Gpt_StopTimer */
/******************************************************************************/

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) 
/* GPT199:, GPT200:*/
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT286,DS_AS_GPT117,
   DS_AS_GPT176_10_GPT214_GPT178_10,DS_AS_GPT226_GPT178,DS_AS40X_GPT377_GPT178,
   DS_AS40X_GPT332_8,DS_AS_GPT275_1_GPT014,DS_MCAL_SWSC_GPT502_6]

** Syntax : void Gpt_EnableNotification(Gpt_ChannelType Channel)              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:    reentrant - GPT117                                          **
**                                                                            **
** Parameters (in): Channel :Channel ID                                       **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Service for enabling the notification for a channel during   **
**               runtime - GPT014:,GPT091:,GPT117                             **
**                                                                            **
*******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
  const Gpt_ChannelConfigType* LocalGptChannelPtr;
  uint8 *DataPtr;
  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  
  ErrorFlag = Gpt_lNotifDetSafetyCheck(Channel,GPT_SID_ENABLE_NOTIFICATION);
  
  if ( GPT_ERROR_SET != ErrorFlag )
  #endif 
  /*(GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_SAFETY_ENABLE == STD_ON)*/
  {
    /* Get pointer to channel config */
    LocalGptChannelPtr = ( (Gpt_kConfigPtr->ChannelConfigPtr) + Channel);
    /* GPT208: If Notification pointer is NULL then don't Enable the 
       Notification.
      Rationale - no need call notification if function is not configured */
    if ((LocalGptChannelPtr->GptNotificationPtr) != NULL_PTR)
    {
      DataPtr = Gpt_lGetDataAddress(Channel);
      /* Set the Notification flag */
      *DataPtr = *DataPtr | GPT_SETNOTIF_FLAG;

      #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
      if (Gpt_lGetWakeupNotifFlag(Channel) == 0UL)
      #endif
      {
        Gpt_lGtmIrqModify(Channel,1U);
      }
    }
  }/*End of if ( GPT_ERROR_SET != ErrorFlag )*/
}/* End of Gpt_EnableNotification */


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT287,DS_AS_GPT118,
   DS_AS_GPT176_11_GPT217_GPT178_11,DS_AS_GPT227_GPT178,DS_AS40X_GPT379_GPT178,
   DS_AS_GPT015,DS_AS40X_GPT332_9,DS_MCAL_SWSC_GPT502_7]

** Syntax : void Gpt_DisableNotification(Gpt_ChannelType Channel)             **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  reentrant - GPT118                                            **
**                                                                            **
** Parameters (in):   Channel :Channel ID                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Service for disabling the notification for a channel during  **
**               runtime. Note, that stopping a timer automatically disables  **
**               notification on this channel - GPT015:,GPT092:,GPT118:       **
**                                                                            **
*******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel) /* GPT015 */
{
  Gpt_ModeType ChannelMode;
  uint8 *DataPtr;

  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  
  ErrorFlag = Gpt_lNotifDetSafetyCheck(Channel,GPT_SID_DISABLE_NOTIFICATION);
  
  if ( GPT_ERROR_SET != ErrorFlag )
  #endif 
  /*(GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )*/
  {
    DataPtr = Gpt_lGetDataAddress(Channel);
    /* Clear the Notification flag */
    *DataPtr = *DataPtr & (uint8)(~GPT_SETNOTIF_FLAG);

    /* Get pointer to channel config */
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    if (Gpt_lGetWakeupNotifFlag(Channel) == 0UL)
    #endif
    {
      /* Get Channel Mode*/
      ChannelMode = \
       (((Gpt_kConfigPtr->ChannelConfigPtr)+Channel)->GptChannelMode);
      if(Gpt_lModeCont(ChannelMode))
      {
        Gpt_lGtmIrqModify(Channel,0U);
      }
    }
  }
}/* End of the function Gpt_DisableNotification */
#endif 
/*(GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)*/

#if (GPT_TIME_ELAPSED_API == STD_ON) 
/* GPT195:*/
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT282,DS_AS_GPT113,
   DS_AS_GPT176_5_GPT178_5,DS_AS_GPT222,DS_AS_GPT210,DS_AS_GPT361,
   DS_AS_GPT010_1,DS_AS40X_GPT295,
   DS_AS40X_GPT332_4,DS_AS40X_GPT297_1,DS_AS40X_GPT299_1,DS_MCAL_SWSC_GPT502_2,
   DS_AS321_GPT296_1,DS_AS321_GPT298_1,DS_AS321_GPT295,
   DS_AS321_GPT297_2,DS_AS321_GPT299_2,DS_AS321_GPT303]
** Syntax : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)         **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:    reentrant                                                   **
**                                                                            **
** Parameters (in): Channel ID                                                **
**                                                                            **
** Parameters (out): none                                                     **
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
** Implementation Notes:                                                      **
** 1) In Production mode, when called before Initialization it will return 0  **
** 2) GPT113: Re-entrant capability is only allowed if the caller take care   **
**    that there is no simultaneous usage of the same channel.                **
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
  uint32 TimeElapsed;
  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  #endif 
  /* #if (GPT_DEV_ERROR_DETECT == STD_ON) */

  TimeElapsed = 0U;

  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )

  /* DET Check function GPT210:,GPT097:,GPT222:,GPT267: and GPT100: */
  ErrorFlag = Gpt_lGetTimeDetSafetyCheck(Channel,GPT_SID_GET_TIMEELAPSED);
  /* Initialize TimeElapsed - GPT097: GPT222: GPT267: GPT100: */
  if ( ErrorFlag != GPT_ERROR_SET )
  #endif 
  /*(GPT_DEV_ERROR_DETECT == STD_ON)*/
  {
    /*Get TimeElapsed if timer Started/Stopped/Expired else return '0' */
    if(Gpt_lCheckChannelStatus(Channel))
    {
      /* Read current Timer value */
      TimeElapsed = Gpt_lGtmGetTimeElapsed(Channel);
    }
  }

  return ((Gpt_ValueType)TimeElapsed); /* Return TimeElapsed value - GPT167: */

}/* End of Gpt_GetTimeElapsed */

/******************************************************************************/
#endif 
/*(GPT_TIME_ELAPSED_API == STD_ON)*/

#if (GPT_TIME_REMAINING_API == STD_ON) 
/* GPT196:*/
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT283,DS_AS_GPT114,
   DS_AS_GPT176_6_GPT178_6,DS_AS_GPT211,DS_AS_GPT083,
   DS_AS_GPT305,DS_AS_GPT301_1,DS_AS40X_GPT303_1,
   DS_AS40X_GPT211_GPT223_GPT332_5,DS_MCAL_SWSC_GPT502_3,DS_AS321_GPT302,
   DS_AS321_GPT303_2,DS_AS321_GPT304]

** Syntax : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:    reentrant - GPT114                                          **
**                                                                            **
** Parameters (in): Channel ID                                                **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: Gpt_ValueType (Remaining timer value in number of ticks)     **
**                                                                            **
** Description : This function returns the timer value remaining until the    **
**               next Timeout period will expire (calculated by the normal    **
**               operation function by subtracting the Timeout minus the      **
**               current timer value and returning the absolute value).       **
** Implementation Notes:                                                      **
** 1) In Production mode, when called before Initialization it will return 0  **
** 2) GPT101:In production mode, when reading a timer channel, prior to       **
**    starting it will return 0.                                              **
** 3) GPT114: Re-entrant capability is only allowed if the caller take care   **
**    that there is no simultaneous usage of the same channel.                **
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
  uint32 ReadTimer;
  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  #endif
   /*  #if (GPT_DEV_ERROR_DETECT == STD_ON)*/
  
  ReadTimer = 0U;

  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  /* DET Check for GPT211:,GPT223:,GPT101:,GPT102: and GPT268:
     If error flag is set then return without executing the routine */
  ErrorFlag = Gpt_lGetTimeDetSafetyCheck(Channel,GPT_SID_GET_TIMEREMAINING) ;

  if(ErrorFlag != GPT_ERROR_SET)
  #endif 
  /* (GPT_DEV_ERROR_DETECT == STD_ON)*/
  {
    /*Get TimeRemaining if timer started/Stopped/Elapsed else return '0' */
    if(Gpt_lCheckChannelStatus(Channel))
    {
      /* Read current Timer value */
      ReadTimer = Gpt_lGtmGetTimeRemaining(Channel);

    }
  }
  /* GPT168: Remaining timer value in ticks */
  return ((Gpt_ValueType)(ReadTimer));

}/* End of Gpt_GetTimeRemaining */

#endif 
/*(GPT_TIME_REMAINING_API == STD_ON)*/

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/* GPT201: ,GPT202: ,GPT203: */
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT288,DS_AS_GPT176_12_GPT231_GPT178_12,
   DS_AS_GPT228_GPT178,DS_AS_GPT164_GPT153,DS_AS_GPT152,DS_AS_GPT165,
   DS_AS_GPT341,DS_AS40X_GPT332_10,DS_AS_GPT151,DS_AS_GPT255,
   DS_MCAL_SWSC_GPT502_8,DS_MCAL_SWSC_GPT504]

** Syntax : void Gpt_SetMode(Gpt_ModeType Mode)                               **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in):   Mode: GPT_MODE_NORMAL (normal operation mode) or        **
**                          GPT_MODE_SLEEP (mode for reduced power)           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Service for setting the mode of the operation. Mode can be   **
**               normal operation mode or it can be of sleep mode.            **
** Implementation Notes:                                                      **
** 1) If the module wakes up from sleep, user need to set the mode to         **
** GPT_MODE_NORMAL, all the notifications and wakeup capabilities will remain **
** same as before entering to GPT_MODE_SLEEP.                                 **
** 2) GPT255: This service is only feasible, if GPT_REPORT_WAKEUP_SOURCE      **
      is statically configured available.Refer Bugzilla Number 17946.         **
**                                                                            **
*******************************************************************************/
void Gpt_SetMode(Gpt_ModeType Mode)
{
  uint32 WakeupFlag;
  Gpt_ChannelType Channel;
  Gpt_ChannelType MaxChannels;
  #if ( GPT_DEV_ERROR_DETECT == STD_ON ) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  #endif
  uint8 *DataPtr;
  uint8 ChannelStatus;
  

  
  #if ( GPT_DEV_ERROR_DETECT == STD_ON ) || ( GPT_SAFETY_ENABLE == STD_ON )
  ErrorFlag = 0U;
  #if ( GPT_DEV_ERROR_DETECT == STD_ON )
  /* DET check for Init not done - GPT228: */
  if (Gpt_DriverMode == GPT_MODE_UNINITIALIZED)
  {
    /* Report to DET - GPT230: */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     GPT_SID_SET_MODE, GPT_E_UNINIT );
    ErrorFlag = GPT_ERROR_SET; /* Set ErrorFlag */
  }
  else
  #endif
  {
    /* DET check for invalid mode - GPT231: */
    if ( !((Mode == GPT_MODE_NORMAL) || (Mode == GPT_MODE_SLEEP)) )
    {
        #if ( GPT_DEV_ERROR_DETECT == STD_ON )
        /* Report to  DET */
        Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                       GPT_SID_SET_MODE, GPT_E_PARAM_MODE );
        #endif
        #if (GPT_SAFETY_ENABLE == STD_ON)
        /* Report Safety Error */
        SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                       GPT_SID_SET_MODE, GPT_E_PARAM_MODE);
        #endif
        ErrorFlag = GPT_ERROR_SET;
    }
  }
  if (ErrorFlag != GPT_ERROR_SET)
  #endif 
  /*( GPT_DEV_ERROR_DETECT == STD_ON )*/
  {
    /* Check the Mode - GPT127:, GPT128:*/
    if ( GPT_MODE_SLEEP == Mode)
    {
      /* Get the maximum number of channels */
      MaxChannels = Gpt_kConfigPtr->GptMaxChannels;

      /* Initialize all channels */
      for ( Channel = 0U; Channel < MaxChannels; Channel++ )
      {
        DataPtr = Gpt_lGetStatusVarAddr(Channel);
        ChannelStatus = *DataPtr;
        /* Check channel wakeup capability, if not stop the running timer
           - GPT153: */
        WakeupFlag = Gpt_lGetWakeupNotifFlag(Channel);
        if ((ChannelStatus == GPT_CHANNEL_STARTED)\
        && (WakeupFlag == 0U))
        {
          /* Stop the required timer channel */
          Gpt_lGtmStopTimer(Channel);
          *DataPtr = GPT_CHANNEL_STOPPED;
        }
        /* If the function is called to SLEEP without IRQ enabled for any
        wakeup channel then it should report a Safety Error. This is added 
        as Safety measure before putting GPT to SLEEP */
        #if (GPT_SAFETY_ENABLE == STD_ON)
        else if((ChannelStatus == GPT_CHANNEL_STARTED)\
        && (WakeupFlag == 1U))
        {
          Gpt_lSafeCheckMode(Channel);
        }
        #endif
        else
        {
        /* Do Nothing */
        }
      } /* For loop ends */

      /* Update the driver state to GPT_MODE_SLEEP - GPT151 */
      Gpt_DriverMode = GPT_MODE_SLEEP;

    }
    else /* If Mode is GPT_MODE_NORMAL */
    {
      /* Update the driver state to GPT_MODE_NORMAL
         GPT150:, GPT151, GPT152: & GPT165: */
      Gpt_DriverMode = GPT_MODE_NORMAL;
    }
  }
}/* Gpt_SetMode ends */
/******************************************************************************/


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT289,DS_AS_GPT155,,
   DS_AS_GPT176_13_GPT215_GPT178_13,DS_AS_GPT229_GPT178,DS_AS_GPT159,
   DS_AS40X_GPT332_11,DS_AS_GPT157,DS_AS_GPT158,DS_MCAL_SWSC_GPT502_9]
** Syntax : void Gpt_DisableWakeup(Gpt_ChannelType Channel)                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant - GPT155                                            **
**                                                                            **
** Parameters (in):   Channel :Channel ID                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Service for disabling the wake up notification for a single  **
**               channel during runtime.- GPT159:, GPT157:, GPT155:           **
**               For GPT157, Refer Bugzilla Number 17946                      **
*******************************************************************************/
void Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
  Gpt_ModeType ChannelMode;
  uint8 *DataPtr;

  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;

  /* Call DET check,If DET occurred then return without executing the routine*/
  ErrorFlag = Gpt_lWakeupDetSafetyCheck(Channel,GPT_SID_DISABLE_WAKEUP);

  if(ErrorFlag != GPT_ERROR_SET)
  #endif 
  /*(GPT_DEV_ERROR_DETECT == STD_ON)*/

  {
    /* Clear the flag for that channel - GPT159: */
    DataPtr = Gpt_lGetDataAddress(Channel);

    *DataPtr = *DataPtr & (uint8)(~GPT_SETWAKEUP_FLAG);

    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    if (Gpt_lGetNotifFlag(Channel) == 0U)
    #endif
    {
      /* Get Channel Mode*/
      ChannelMode =\
                 (((Gpt_kConfigPtr->ChannelConfigPtr)+Channel)->GptChannelMode);
      if(Gpt_lModeCont(ChannelMode))
      {
        Gpt_lGtmIrqModify(Channel,0U);
      }
    }
  }
}/* End of Gpt_DisableWakeup */
/******************************************************************************/


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT290,DS_AS_GPT156,
   DS_AS_GPT176_14_GPT216_1_GPT178_14,DS_AS_GPT230_1_GPT178,
   DS_AS_GPT275_2_GPT160,DS_AS_GPT176_15_GPT216_2_GPT178_15,
   DS_AS_GPT230_2_GPT178,DS_AS40X_GPT332_12,DS_MCAL_SWSC_GPT502_10]

** Syntax : void Gpt_EnableWakeup(Gpt_ChannelType Channel)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x0B                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant - GPT156                                            **
**                                                                            **
** Parameters (in):   Channel :Channel ID                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Service for Enabling the wake up notification for a single   **
**               channel during runtime.- GPT160:, GPT158:,GPT156:            **
**               For GPT158, Refer Bugzilla Number 17946                      **
*******************************************************************************/
void Gpt_EnableWakeup(Gpt_ChannelType Channel)
{

  const Gpt_ChannelConfigType* LocalGptChannelPtr;
  uint8 *DataPtr;

  #if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;

  /* Call DET check,If DET occurred then return without executing the routine*/
  ErrorFlag = Gpt_lWakeupDetSafetyCheck(Channel,GPT_SID_ENABLE_WAKEUP);

  if(ErrorFlag != GPT_ERROR_SET)
  #endif /*(GPT_DEV_ERROR_DETECT == STD_ON)*/
  {  
    /* Get pointer to channel config */
    LocalGptChannelPtr = ( (Gpt_kConfigPtr->ChannelConfigPtr) + Channel);

    /* If wakeup capability of a channel is true only then enable the wakeup
       Rationale - no need enable wakeup on a non-wakeup capable channel */
    if (LocalGptChannelPtr->GptEnableWakeupState == (boolean)TRUE)
    {
      /* Set the wakeup notification flag - GPT160:*/
      DataPtr = Gpt_lGetDataAddress(Channel);

      *DataPtr = *DataPtr | GPT_SETWAKEUP_FLAG;
   
      #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      if (Gpt_lGetNotifFlag(Channel) == 0U)
      #endif
      {
        Gpt_lGtmIrqModify(Channel,1U);
      }
    }
  }
}/* End of Gpt_EnableWakeup*/

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT328,DS_AS_GPT323,DS_AS_GPT321,
   DS_AS_GPT325_GPT178,DS_AS_GPT325,DS_AS_GPT332_13]

** Syntax : void Gpt_CheckWakeup(EcuM_WakeupSourceType wakeupSource)          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x0C                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant - GPT323                                            **
**                                                                            **
** Parameters (in): wakeupSource                                              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Checks if a wakeup capable GPT channel is the source for a   **
** wakeup event and calls the ECU state manager service EcuM_SetWakeupEvent   **
** in case of a valid GPT channel wakeup event.                               **
**                                                                            **
*******************************************************************************/
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  uint32 ErrorFlag;

  ErrorFlag = 0U;

  /* DET check for Init not done - GPT325:*/
  if (Gpt_DriverMode == GPT_MODE_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     GPT_SID_CHECK_WAKEUP, GPT_E_UNINIT );
    ErrorFlag = GPT_ERROR_SET;
  }

  if(ErrorFlag != GPT_ERROR_SET)
  #endif
   /*(GPT_DEV_ERROR_DETECT == STD_ON)*/
  {
    /* Wakeup info stored matches with WakeupSource */
    if (Gpt_WakeupChannelInfo == WakeupSource)
    {
      EcuM_SetWakeupEvent(WakeupSource);
    }
  }
}/* End of Gpt_CheckWakeup*/

/******************************************************************************/
#endif 
/* #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */
#endif 
/* (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) */


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#if (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_SAFETY_ENABLE == STD_ON)

#if (GPT_DEV_ERROR_DETECT == STD_ON)
#if (GPT_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT176_16_GPT178_16,
   DS_AS_GPT220_2,DS_AS_GPT234]

** Syntax : static uint32 Gpt_lDeInitDetCheck(void)                           **
** [/cover]                                                                   **
**                                                                            **
** Sync/Async:S Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: ErrorFlag (uint32)                                           **
**                                                                            **
** Description : Service for DET check in Gpt_DeInit Function                 **
**                                                                            **
*******************************************************************************/
static uint32 Gpt_lDeInitDetCheck(void)
{
  uint32 ErrorFlag;
  uint8 Channel;
  
  uint8 *DataPtr;
  uint8 ChannelStatus;
  


  ErrorFlag = 0U;
  /* DET check for Init not done - GPT220: */
  if (Gpt_DriverMode == GPT_MODE_UNINITIALIZED)
  {
    /* Report to  DET */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     GPT_SID_DEINIT, GPT_E_UNINIT);
    ErrorFlag = GPT_ERROR_SET; /* Set Error Flag */
  }
  else
  {
    for ( Channel = 0U; (Channel < Gpt_kConfigPtr->GptMaxChannels) &&
          (ErrorFlag != GPT_ERROR_SET); Channel++ )
    {
      DataPtr = Gpt_lGetStatusVarAddr(Channel);
      ChannelStatus = *DataPtr;
      if(ChannelStatus == GPT_CHANNEL_STARTED)
      {
        ErrorFlag = GPT_ERROR_SET;
      }
    }
    /* Error Flag set */
    if (ErrorFlag == GPT_ERROR_SET)
    {
      /* Report to  DET - GPT234: */
      Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                       GPT_SID_DEINIT, GPT_E_BUSY );
    }
  }

  return (ErrorFlag);

}/* End of Gpt_lDeInitDetCheck */

#endif 
/* End of #if (GPT_DEINIT_API == STD_ON) */
#endif 
/* End of #if (GPT_DEV_ERROR_DETECT == STD_ON)  */

#if ( GPT_WAKEUP_FUNCTIONALITY_API == STD_ON )
/*******************************************************************************
** Syntax : static uint32  Gpt_lWakeupDetSafetyCheck(                      **
**                                              Gpt_ChannelType Channel)      **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel and Sid                                          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: ErrorFlag (uint32)                                           **
**                                                                            **
** Description : Service to check DET errors in Gpt_EnableWakeup and          **
**               Gpt_DisableWakeup API's                                      **
**                                                                            **
*******************************************************************************/
static uint32 Gpt_lWakeupDetSafetyCheck(Gpt_ChannelType Channel,
                                           uint8 Gpt_Sid)
{
  const Gpt_ChannelConfigType* LocalGptChannelPtr;
  uint32 ErrorFlag;
  Gpt_ChannelType MaxChannels;
  ErrorFlag = 0U;  /* Initialize error flag */
  #if (GPT_DEV_ERROR_DETECT == STD_ON) 
  /* DET check for Init not done - GPT222:*/
  if (Gpt_DriverMode == GPT_MODE_UNINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     Gpt_Sid, GPT_E_UNINIT );
    ErrorFlag = GPT_ERROR_SET;
  }
  else
  #endif
  {
    /* Check channel out of range */
    /* Get the maximum number of channels */
    MaxChannels = Gpt_kConfigPtr->GptMaxChannels;

    /* Channel number is invalid */
    if ( Channel >= MaxChannels )
    {
        #if (GPT_DEV_ERROR_DETECT == STD_ON)
        /* Report to  DET - GPT210:*/
        Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                        Gpt_Sid, GPT_E_PARAM_CHANNEL);
        #endif
        #if (GPT_SAFETY_ENABLE == STD_ON)
         /* Report Safety Error */
        SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                        Gpt_Sid, GPT_E_PARAM_CHANNEL);
        #endif 
        ErrorFlag = GPT_ERROR_SET;
    }

    /* Check for Channel for Wakeup Capability */
    else
    {
      /* Get pointer to channel config */
      LocalGptChannelPtr = ( (Gpt_kConfigPtr->ChannelConfigPtr) + Channel);

      /* Channel is not wakeup capable */
      if (LocalGptChannelPtr->GptEnableWakeupState == (boolean)FALSE )
      {
        #if (GPT_DEV_ERROR_DETECT == STD_ON)        
        /* Report to DET */
        Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                         Gpt_Sid,GPT_E_PARAM_CHANNEL);
        #endif
        #if (GPT_SAFETY_ENABLE == STD_ON)
         /* Report Safety Error */
        SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                        Gpt_Sid, GPT_E_PARAM_CHANNEL);
        #endif         
        ErrorFlag = GPT_ERROR_SET;
      }
    }
  }
  return (ErrorFlag);

}/* End of Gpt_lWakeupDetSafetyCheck */

#endif 
/* End of #if ( GPT_WAKEUP_FUNCTIONALITY_API == STD_ON )*/

#endif 
/* End of #if (GPT_DEV_ERROR_DETECT == STD_ON) ||   \
                                               (GPT_SAFETY_ENABLE == STD_ON)*/


#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) ||    \
     (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON))
/*******************************************************************************
** Syntax :static void Gpt_lGtmIrqModify   (                                  **
**                           Gpt_ChannelType Channel                          **
**                           uint8 InterruptFlag                              **
**                                    )                                       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  Channel :Channel ID                                      **
**                   InterruptFlag - Interrupt bits to set/reset              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Enable/Disable CCU0/CCU1 Interrupt           **
**                                                                            **
*******************************************************************************/
static void Gpt_lGtmIrqModify(Gpt_ChannelType Channel,
                         uint8 InterruptFlag)
{
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;   /* Ptr to TOM Channel Register   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; /* Ptr to ATOM Channel Register  */
  uint8 ModuleNumber;                        /* Holds the module number */
  uint8 ChannelNumber;                       /* Holds the channel number */

  ModuleNumber = Gpt_ChannelIdentifier[Channel].ModuleNo;
  ChannelNumber = Gpt_ChannelIdentifier[Channel].ChannelNo;


  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
  {
    /*Misra Violation:MISRA rule 11.4 & 1.2,
    cast from pointer to pointer & Unusual Pointer cast */


    TomChannelRegPtr = \
    &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber]).\
    CH[ChannelNumber]);



    /* Clear all Pending Interrupts */
    /* Interrupts are disabled before clearing the notify bits so that any
    interruption after clearing the notify doesn't set the notify bits again*/
    TomChannelRegPtr->IRQ_EN.U = 0UL;
    TomChannelRegPtr->IRQ_NOTIFY.U = GPT_CLEAR_INTERRUPTS;
    TomChannelRegPtr->IRQ_EN.U = InterruptFlag;
  }


  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr =    \
                 &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                               ATOM_CH[ModuleNumber].CH[ChannelNumber]);
    /* Clear all Pending Interrupts */
    /* Interrupts are disabled before clearing the notify bits so that any
    interruption after clearing the notify doesn't set the notify bits again*/
    AtomChannelRegPtr->IRQ_EN.U = 0UL;
    AtomChannelRegPtr->IRQ_NOTIFY.U = GPT_CLEAR_INTERRUPTS;
    AtomChannelRegPtr->IRQ_EN.U = InterruptFlag;
  }

}
#endif
/* #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) ||    \
     (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)) */

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Syntax :void Gpt_lSafeCheckMode(Gpt_ChannelType Channel)                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Non Reentrant                                            **
**                                                                            **
** Parameters (in):  Channel - Channel ID                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description : This function is used to ensure Safe SetMode by ensuring that**
**               for any running GPT channel configured for WakeUp with       **
**               Gpt_EnableWakeup the IRQ bits for the channel are enabled    **
**               before going to SLEEP                                        **
*******************************************************************************/
static void Gpt_lSafeCheckMode(Gpt_ChannelType Channel)
{
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;   /* Ptr to TOM Channel Register   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; 
  uint32 InterruptFlag = 0U;  
  uint8 ModuleNumber;                        /* Holds the module number */
  uint8 ChannelNumber;  
  
    ModuleNumber = Gpt_ChannelIdentifier[Channel].ModuleNo;
    ChannelNumber = Gpt_ChannelIdentifier[Channel].ChannelNo;
    if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
    {
        TomChannelRegPtr = \
        &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber]).\
                                         CH[ChannelNumber]);
        /* Check if the IRQ bit is set */
        InterruptFlag = (uint32)(TomChannelRegPtr->IRQ_EN.U & 1U);
        if( InterruptFlag != 1U)
        {
            /* Report Safety Error */
            SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                                GPT_SID_SET_MODE, GPT_E_NO_WAKEUP);
        }
    } 
    if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
    {
        AtomChannelRegPtr =    \
              &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                               ATOM_CH[ModuleNumber].CH[ChannelNumber]);
        /* Check if the IRQ bit is set */
        InterruptFlag = (uint32)(AtomChannelRegPtr->IRQ_EN.U & 1U);
        if( InterruptFlag != 1U)
        {
            /* Report Safety Error */
            SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                               GPT_SID_SET_MODE, GPT_E_NO_WAKEUP);
        }
    }
  
}
#endif  
/*(GPT_SAFETY_ENABLE == STD_ON)*/
#endif   
/*(GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)*/
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT186_GPT330]                        **
** Syntax : void Gpt_lChannelInit()                                           **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function parses through all the GPT channels        **
**                   and sets the indices of all global variables based on    **
**                   ASIL or QM signal                                        **
*******************************************************************************/
static void Gpt_lChannelInit(void)
{

const Gpt_ChannelConfigType* LocalGptChannelPtr;
Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;
Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr;   
uint8 ModuleNumber;                   
uint8 ChannelNumber; 
Gpt_ChannelType Channel; 

#if (GPT_SAFETY_ENABLE == STD_ON)
#if (GPT_MAX_ASIL_CHANNELS != 0U)
uint8 AsilIndex=0U;
#endif
#endif
#if (GPT_MAX_QM_CHANNELS != 0U)
uint8 QMIndex=0U; 
#endif

for(Channel = 0U; Channel < Gpt_kConfigPtr->GptMaxChannels; Channel++)
{

    LocalGptChannelPtr = ((Gpt_kConfigPtr->ChannelConfigPtr) + Channel);
    ModuleNumber = Gpt_ChannelIdentifier[Channel].ModuleNo;
    ChannelNumber = Gpt_ChannelIdentifier[Channel].ChannelNo;

    if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
    {
        TomChannelRegPtr = \
           &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber]).\
                                                         CH[ChannelNumber]);
        /* Clock initialization of GPT channel is already done in Gtm_Init, 
        this code is present to avoid failure of Gpt_InitCheck after Gpt_DeInit
        and re-initialization with Gpt_Init without Gtm_Init called again */
        TomChannelRegPtr->CTRL.U = 
         (uint32_t)((uint32)(LocalGptChannelPtr->ClockSelect) << CLOCK_DIV_POS);
    }

    if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
    {
        AtomChannelRegPtr =
           &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                               ATOM_CH[ModuleNumber].CH[ChannelNumber]);
        /* Clock initialization of GPT channel is already done in Gtm_Init, 
        this code is present to avoid failure of Gpt_InitCheck after Gpt_DeInit
        and re-initialization with Gpt_Init without Gtm_Init called again */
        /* ATOM is configured in SOMP mode */
        AtomChannelRegPtr->CTRL.U = (uint32_t)
        (((uint32)(LocalGptChannelPtr->ClockSelect) << CLOCK_DIV_POS) | 
                                                                SOMP_BIT_POS);
    }
    /* Initialize the channel indices based on the signal type(ASIL or QM) */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    #if (GPT_MAX_ASIL_CHANNELS != 0U)
    if(LocalGptChannelPtr->SignalType == GPT_ASIL_SIGNAL)
    {
        Gpt_ChannelIndex[Channel] = AsilIndex;
        AsilIndex++;
    }
    else
    #endif
    #endif
    {
    #if (GPT_MAX_QM_CHANNELS != 0U)
        Gpt_ChannelIndex[Channel] = QMIndex;
        QMIndex++;
    #endif
    }


}

}
/*If Any channel is configured for Oneshot mode, Then Configure it*/
#if (GPT_ONESHOT_USED == STD_ON)
/*******************************************************************************
** Syntax:void Gpt_lGtmSetOsm(Gpt_ChannelType Channel)                        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  Channel :Channel ID                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to enable the channel in One Shot Mode          **
**                                                                            **
*******************************************************************************/
static void Gpt_lGtmSetOsm(Gpt_ChannelType Channel)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;          /* Ptr to TOM Channel Reg */
  uint8 ModuleNo;                            /* Holds the TIM module Number*/
  uint8 ChannelNo;                           /* Holds the TIM Channel Number*/



  /* Extract Module Number and Channel Number */
  ModuleNo  = Gpt_ChannelIdentifier[Channel].ModuleNo;
  ChannelNo = Gpt_ChannelIdentifier[Channel].ChannelNo;

  /* Check the Module Type */
  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
  {
    /*Misra Violation:MISRA rule 11.4 & 1.2,
          cast from pointer to pointer & Unusual Pointer cast */


    TomChannelRegPtr = \
          &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNo]).\
          CH[ChannelNo]);


    /* Set the One Shot Mode bit */
    TomChannelRegPtr->CTRL.U |= (uint32_t)(1UL << GPT_GTM_CTRL_OSM);
    /* Clear any pending interrupt */
    TomChannelRegPtr->IRQ_NOTIFY.U = GPT_CLEAR_INTERRUPTS;
    /* Enable CCU0 Interrupt */
    TomChannelRegPtr->IRQ_EN.U = 1UL;
  }

  /* Check the Module Type */
  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
  {
    /* Set the One Shot Mode bit */
    (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                          ATOM_CH[ModuleNo].CH[ChannelNo].CTRL.U
                                    |= (uint32_t)(1UL << GPT_GTM_CTRL_OSM);

    (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                          ATOM_CH[ModuleNo].CH[ChannelNo].IRQ_NOTIFY.U
                                                         = GPT_CLEAR_INTERRUPTS;
    (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                          ATOM_CH[ModuleNo].CH[ChannelNo].IRQ_EN.U = 1UL;
  }

}
#endif 
/*End of #if (GPT_ONESHOT_USED == STD_ON)*/
/*******************************************************************************
** Syntax :void Gpt_lGtmStopTimer (                                           **
**                           Gpt_ChannelType Channel                          **
**                               )                                            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  Channel :Channel ID                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to stop a GPT Timer from counting               **
**                                                                            **
*******************************************************************************/
static void Gpt_lGtmStopTimer(Gpt_ChannelType Channel)
{
  uint32 RegVal;                             /* For temp reg value storage*/
  uint32 RegValForCtrl;                      /* For temp reg value storage*/
  uint8 ModuleNo;                            /* Holds the module Number */
  uint8 ChannelNo;                           /* Holds the Channel Number*/
  uint8 GroupNo;                             /* Holds the Channel Number*/

  ModuleNo  = Gpt_ChannelIdentifier[Channel].ModuleNo;
  ChannelNo = Gpt_ChannelIdentifier[Channel].ChannelNo;
  GroupNo   = Gpt_ChannelIdentifier[Channel].GroupNo;

  /* Check the Module Type */
  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
  {
    /* Clear the Endis bits corresponding to the channel */
    RegVal =  ((uint32)1U << (GPT_BITS_PER_CHANNEL * \
                              (ChannelNo % GTM_TOM_CHANNELS_PER_TGC))) ;
    RegValForCtrl =((uint32)GPT_GTM_CHANNEL_ENABLE <<  \
               (GPT_BITS_PER_CHANNEL *(ChannelNo % GTM_TOM_CHANNELS_PER_TGC)));
    ((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).
                    TOM_TGC[ModuleNo]).TGC[GroupNo].ENDIS_STAT.U = RegVal;
    ((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).
                      TOM_TGC[ModuleNo]).TGC[GroupNo].ENDIS_CTRL.U = \
                                  (uint32_t)(~(RegValForCtrl));

  }

  /* Check the Module Type */
  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
  {
    /* Clear the Endis bits corresponding to the channel */
    RegVal =  ((uint32)1U << (GPT_BITS_PER_CHANNEL * \
                              (ChannelNo  % GTM_ATOM_CHANNELS_PER_AGC))) ;
    RegValForCtrl = ((uint32)GPT_GTM_CHANNEL_ENABLE << \
               (GPT_BITS_PER_CHANNEL *(ChannelNo %GTM_ATOM_CHANNELS_PER_AGC)));
    (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                          ATOM_AGC[ModuleNo].AGC_ENDIS_STAT.U = RegVal;
    (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                          ATOM_AGC[ModuleNo].AGC_ENDIS_CTRL.U=  \
                                                 (uint32_t)(~(RegValForCtrl));
  }

}

#if (GPT_TIME_REMAINING_API == STD_ON)
/*******************************************************************************
** Syntax :uint32 Gpt_lGtmGetTimeRemaining (                                  **
**                           Gpt_ChannelType Channel                          **
**                                        )                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  Channel :Channel ID                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     RetVal - Time Remaining for Timeout                      **
**                                                                            **
** Description :     Function to get the Time Remaining for a GPT channel to  **
**                   complete counting                                        **
**                                                                            **
*******************************************************************************/
static uint32 Gpt_lGtmGetTimeRemaining(
                            Gpt_ChannelType Channel)
{
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;   /* Ptr to TOM Channel Register    */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; /* Ptr to ATOM Channel Register   */
  uint32 Cm0Val;                             /* Holds the CM0 value     */
  uint32 Cn0Val;                             /* Holds the CN0 value     */
  uint32 RetVal;                             /* Holds the Return value  */
  uint8 ModuleNumber;                        /* Holds the module number */
  uint8 ChannelNumber;                       /* Holds the channel number*/
  #if (GPT_ONESHOT_USED == STD_ON)
  boolean OneShotModeStatus;                 /* Holds OSM status        */
  uint8 NotifyStatus;                        /* Status of CCU0 Interrupt*/
  #endif /*End of #if (GPT_ONESHOT_USED == STD_ON)*/

  ModuleNumber = Gpt_ChannelIdentifier[Channel].ModuleNo;
  ChannelNumber = Gpt_ChannelIdentifier[Channel].ChannelNo;

  /*Misra Violation:MISRA rule 11.4 & 1.2,
          cast from pointer to pointer & Unusual Pointer cast */


  TomChannelRegPtr =\
          &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber]).\
          CH[ChannelNumber]);



  AtomChannelRegPtr =   \
                 &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                                  ATOM_CH[ModuleNumber].CH[ChannelNumber]);

  RetVal = 0U;

  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
  {

    Cm0Val = TomChannelRegPtr->CM0.U;
    Cn0Val = TomChannelRegPtr->CN0.U;
    /* CN0 continues to count after reaching CM0. This is
       handled in the ISR. To avoid corner cases, due to ISR latency, the
       notify bit is also checked, and if it is set it would indicate the
       Timer count is complete */
    #if (GPT_ONESHOT_USED == STD_ON)
    
   
    NotifyStatus =  (uint8)(TomChannelRegPtr->IRQ_NOTIFY.U & 1U);
   

   
    OneShotModeStatus =((((uint32)TomChannelRegPtr->CTRL.U &         \
               (1UL << GPT_GTM_CTRL_OSM)) > 0UL)? (boolean)TRUE:(boolean)FALSE);
             

    if((OneShotModeStatus == (boolean)TRUE) && (NotifyStatus == 1U))
    {
      RetVal = 0U;
    }
    else
    #endif /*End of #if (GPT_ONESHOT_USED == STD_ON)*/
    {
      /* Return the difference between CM0 and CN0 value */
      RetVal = Cm0Val - Cn0Val;
    }

  }

  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
  {
    Cm0Val = AtomChannelRegPtr->CM0.U;
    Cn0Val = AtomChannelRegPtr->CN0.U;
    /* CN0 continues to count after reaching CM0. This is
       handled in the ISR. To avoid corner cases, due to ISR latency, the
       notify bit is also checked, and if it is set it would indicate the
       Timer count is complete */
    #if (GPT_ONESHOT_USED == STD_ON)
  
    NotifyStatus =  (uint8)(AtomChannelRegPtr->IRQ_NOTIFY.U & 1U);
  
  
    OneShotModeStatus = ((((uint32)AtomChannelRegPtr->CTRL.U & \
               (1UL << GPT_GTM_CTRL_OSM)) > 0UL )?(boolean)TRUE:(boolean)FALSE);
             

    if((OneShotModeStatus == (boolean)TRUE) && (NotifyStatus == 1U))
    {
      RetVal = 0U;
    }
    else
    #endif /*End of #if (GPT_ONESHOT_USED == STD_ON)*/
    {
      /* Return the difference between CM0 and CN0 value */
      RetVal = Cm0Val - Cn0Val;
    }
    
  }
  return (RetVal);

}
#endif
/* #if (GPT_TIME_REMAINING_API == STD_ON)  */

#if (GPT_TIME_ELAPSED_API == STD_ON)
/*******************************************************************************
** Syntax :uint32 Gpt_lGtmGetTimeElapsed   (                                  **
**                           Gpt_ChannelType Channel                          **
**                                      )                                     **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  Channel :Channel ID                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     RetVal - Time Elapsed so far                             **
**                                                                            **
** Description :     Function to get the Time Elapsed for a GPT channel.      **
**                                                                            **
*******************************************************************************/
static uint32 Gpt_lGtmGetTimeElapsed(
                           Gpt_ChannelType Channel)
{
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;   /* Ptr to TOM Channel Register   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; /* Ptr to ATOM Channel Register  */
  uint32 RetVal;                             /* Holds the Return value */
  uint8 ModuleNumber;                        /* Holds the module number*/
  uint8 ChannelNumber;                       /* Holds the channel number */

  #if (GPT_ONESHOT_USED == STD_ON)
  boolean OneShotModeStatus;                 /* Holds OSM status         */
  uint8 NotifyStatus;                        /* Status of CCU0 Interrupt */
  #endif /*End of #if (GPT_ONESHOT_USED == STD_ON)*/

  ModuleNumber = Gpt_ChannelIdentifier[Channel].ModuleNo;
  ChannelNumber = Gpt_ChannelIdentifier[Channel].ChannelNo;

  /* Get reference to the module Channel Register */
  /*Misra Violation:MISRA rule 11.4 & 1.2,
          cast from pointer to pointer & Unusual Pointer cast */


  TomChannelRegPtr = \
            &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber]).\
                CH[ChannelNumber]);



  AtomChannelRegPtr =
                 &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                                  ATOM_CH[ModuleNumber].CH[ChannelNumber]);


  RetVal = 0U;
  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
  {

    #if (GPT_ONESHOT_USED == STD_ON)
    
    OneShotModeStatus = ((((uint32)TomChannelRegPtr->CTRL.U &  \
               (1UL << GPT_GTM_CTRL_OSM)) > 0UL )?(boolean)TRUE:(boolean)FALSE);
            

    /* CN0 continues to count after reaching CM0. This is
       handled in the ISR. To avoid corner cases, due to ISR latency, the
       notify bit is also checked, and if it is set it would indicate the
       Timer count is complete */
       
      
    NotifyStatus =  (uint8)(TomChannelRegPtr->IRQ_NOTIFY.U & 1U);
 
    if((OneShotModeStatus == (boolean)TRUE) && (NotifyStatus == 1U))
    {
      RetVal = TomChannelRegPtr->CM0.U;
    }
    else
    #endif 
    /*End of #if (GPT_ONESHOT_USED == STD_ON)*/
    {
      /* Return CN0 value */
      RetVal = TomChannelRegPtr->CN0.U;
    }

  }

  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
  {
    #if (GPT_ONESHOT_USED == STD_ON)
 
    OneShotModeStatus = ((((uint32)AtomChannelRegPtr->CTRL.U & \
               (1UL << GPT_GTM_CTRL_OSM)) > 0UL )?(boolean)TRUE:(boolean)FALSE);
         

    /* CN0 continues to count after reaching CM0. This is
       handled in the ISR. To avoid corner cases, due to ISR latency, the
       notify bit is also checked, and if it is set it would indicate the
       Timer count is complete */
      
    NotifyStatus =  (uint8)(AtomChannelRegPtr->IRQ_NOTIFY.U & 1U);

     if((OneShotModeStatus == (boolean)TRUE) && (NotifyStatus == 1U))
    {
      RetVal = AtomChannelRegPtr->CM0.U;
    }
    else
    #endif
    {
      /* Return CN0 value */
      RetVal = AtomChannelRegPtr->CN0.U;
    }

  }
  return (RetVal);

}
#endif 
/* #if (GPT_TIME_ELAPSED_API == STD_ON) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT329]

** Syntax :Gtm_GptChannelStatusType Gpt_lGtmStartTimer (                      **
**                           Gpt_ChannelType Channel                          **
**                           uint32 TimeOutVal                                **
**                                                    )                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  Channel :Channel ID                                      **
**                   TimeOutVal - Timeout value to which the GPT timer has to **
**                                count                                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     RetVal - Returns the status of starting the channel.     **
**                            GTM_GPT_CHANNEL_STARTED - Channel has been      **
**                                                      successfully started. **
**                            GTM_GPT_CHANNEL_BUSY - Channel is already       **
**                                                   running.                 **
**                            GTM_GPT_WRONG_PARAM - If the Timeout value is   **
**                                                  not within range          **
**                                                                            **
** Description :     Function to start the GPT timer to count till TimeOutVal **
**                                                                            **
*******************************************************************************/
static Gtm_GptChannelStatusType Gpt_lGtmStartTimer(
                                Gpt_ChannelType Channel,
                                uint32 TimeOutVal
                                          )
{
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;   /* Ptr to TOM Channel Register   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; /* Ptr to ATOM Channel Register  */
  Gtm_GptChannelStatusType RetVal;           /* Channel Status              */
  Ifx_GTM_TOM_TGC_TYPE  *TomTgcRegPtr;          /* Ptr to TGC register      */
  volatile uint32_t *EndisPtr;               /* Holds Endis Register address*/
  #if (GPT_ONESHOT_USED == STD_ON)
  boolean OneShotModeStatus;                 /* Holds OSM status            */
  #endif
  uint8 ModuleNumber;                        /* Holds the module number     */
  uint8 ChannelNumber;                       /* Holds the channel number    */
  uint8 GroupNumber;                         /* Holds the group number      */

  ModuleNumber = Gpt_ChannelIdentifier[Channel].ModuleNo;
  ChannelNumber = Gpt_ChannelIdentifier[Channel].ChannelNo;
  GroupNumber = Gpt_ChannelIdentifier[Channel].GroupNo;
  RetVal = (Gtm_GptChannelStatusType)0;

  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
  {
    if((TimeOutVal <= GPT_GTM_TOM_TIMER_MAX) && (TimeOutVal > 0U))
    {
      TomTgcRegPtr = &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).
                                       TOM_TGC[ModuleNumber]).TGC[GroupNumber]);
      EndisPtr = &(TomTgcRegPtr->ENDIS_STAT.U);
      /*Misra Violation:MISRA rule 11.4 & 1.2,
          cast from pointer to pointer & Unusual Pointer cast */


      TomChannelRegPtr = \
          &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber]).\
                CH[ChannelNumber]);


      #if (GPT_ONESHOT_USED == STD_ON)
      OneShotModeStatus = ((((uint32)TomChannelRegPtr->CTRL.U & \
               (1UL << GPT_GTM_CTRL_OSM)) > 0UL )?(boolean)TRUE:(boolean)FALSE);
      #endif  /*End of #if (GPT_ONESHOT_USED == STD_ON)*/


      TomChannelRegPtr->CN0.U = 0U;           /* Clear CN0 register */
      /* Set CM0 with the Timeout value */
      TomChannelRegPtr->CM0.U = TimeOutVal;
      /* Set Shadow register also with same TimeOut Value, this is a safety
      measure to avoid unintended update from shadow registers */
      TomChannelRegPtr->SR0.U = TimeOutVal;  
      /* Enable the Channel by setting the EndisStat and EndisCtrl register */
      *EndisPtr = (uint32_t)(GPT_GTM_CHANNEL_ENABLE_UL <<  \
          (GPT_BITS_PER_CHANNEL * (ChannelNumber % GTM_TOM_CHANNELS_PER_TGC)));
      EndisPtr = &(TomTgcRegPtr->ENDIS_CTRL.U);
      *EndisPtr = (uint32_t)~(1UL <<  \
          (GPT_BITS_PER_CHANNEL * (ChannelNumber % GTM_TOM_CHANNELS_PER_TGC)));

      #if (GPT_ONESHOT_USED == STD_ON)
      if(OneShotModeStatus == (boolean)TRUE)
      {
        /* Clear Notify */
        TomChannelRegPtr->IRQ_NOTIFY.U = GPT_CLEAR_INTERRUPTS;
        /* Write CN0 again to start the channel */
        TomChannelRegPtr->CN0.U = 0U;
      }
      #endif 
      /*End of #if (GPT_ONESHOT_USED == STD_ON)*/
      RetVal = GTM_GPT_CHANNEL_STARTED;

    }
    else  /* If timeout value is not within limits */
    {
      RetVal = GTM_GPT_WRONG_PARAM;
    }
  }

  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
  {
    if((TimeOutVal <= GPT_GTM_ATOM_TIMER_MAX) && (TimeOutVal > 0U))
    {
      EndisPtr = &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                                  ATOM_AGC[ModuleNumber].AGC_ENDIS_STAT.U);

     AtomChannelRegPtr =
                 &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                                  ATOM_CH[ModuleNumber].CH[ChannelNumber]);
      #if (GPT_ONESHOT_USED == STD_ON)
      OneShotModeStatus = ((((uint32)AtomChannelRegPtr->CTRL.U &  \
               (1UL << GPT_GTM_CTRL_OSM)) > 0UL )?(boolean)TRUE:(boolean)FALSE);
      #endif /*End of #if (GPT_ONESHOT_USED == STD_ON)*/

      AtomChannelRegPtr->CN0.U = 0U;/* Clear the CN0 register  */
      /* Set CM0 with the Timeout value */
      AtomChannelRegPtr->CM0.U = TimeOutVal;
      /* Set Shadow register also with same TimeOut Value, this is a safety
      measure to avoid unintended update from shadow registers */
      AtomChannelRegPtr->SR0.U = TimeOutVal;          
      /* Enable the Channel by setting the EndisStat and EndisCtrl register*/
      *EndisPtr = (uint32_t)(GPT_GTM_CHANNEL_ENABLE_UL << \
      (GPT_BITS_PER_CHANNEL *(ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC)));
      EndisPtr = &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                                  ATOM_AGC[ModuleNumber].AGC_ENDIS_CTRL.U);
      *EndisPtr = (uint32_t)~(1UL <<  \
      (GPT_BITS_PER_CHANNEL *(ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC)));

      #if (GPT_ONESHOT_USED == STD_ON)
      if(OneShotModeStatus == (boolean)TRUE)
      {
        /* Clear Notify */
        AtomChannelRegPtr->IRQ_NOTIFY.U = GPT_CLEAR_INTERRUPTS;

        /* Write CN0 again to start the channel */
        AtomChannelRegPtr->CN0.U = 0U;
      }
      #endif 
      /*End of #if (GPT_ONESHOT_USED == STD_ON)*/
      RetVal = GTM_GPT_CHANNEL_STARTED;

    }
    else   /* If timeout value is not within limits */
    {
      RetVal = GTM_GPT_WRONG_PARAM;
    }
  }
  return (RetVal);
}

#if (GPT_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT008]

** Syntax :void Gpt_lResetChannels (void)                                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to reset the channels configured for GPT back to**
**                   their Power On reset state                               **
**                                                                            **
*******************************************************************************/
static void Gpt_lResetChannels(void)
{

Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;
Ifx_GTM_TOM_TGC_TYPE  *TomTgcRegPtr;
Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr;   


uint8 ModuleNumber;                   
uint8 ChannelNumber; 
uint8 GroupNumber;    
Gpt_ChannelType Channel;
uint8 *DataPtr;

    for(Channel = 0U; Channel < Gpt_kConfigPtr->GptMaxChannels; Channel++)
   {
        DataPtr = Gpt_lGetStatusVarAddr(Channel);

        ModuleNumber = Gpt_ChannelIdentifier[Channel].ModuleNo;
        ChannelNumber = Gpt_ChannelIdentifier[Channel].ChannelNo;
        GroupNumber = Gpt_ChannelIdentifier[Channel].GroupNo;

        if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
        {
          TomChannelRegPtr = \
          &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber]).\
                            CH[ChannelNumber]);
          TomTgcRegPtr = &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).
                                     TOM_TGC[ModuleNumber]).TGC[GroupNumber]);
          /* Configure the channel parameters with Power on reset values*/
          TomTgcRegPtr->ENDIS_STAT.U = \
                  (uint32_t)(1UL << (GPT_BITS_PER_CHANNEL * \
                              (ChannelNumber % GTM_TOM_CHANNELS_PER_TGC)));
          TomTgcRegPtr->ENDIS_CTRL.U =  \
                          (uint32_t)(~(GPT_GTM_CHANNEL_ENABLE_UL << \
                         (2U * (ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))));
          TomChannelRegPtr->CN0.U = 0U;
          TomChannelRegPtr->CM0.U  = 0U;
          /* Set Shadow register also with same value, this is a safety
          measure to avoid unintended update from shadow registers */
          TomChannelRegPtr->SR0.U = 0U;
          TomChannelRegPtr->CTRL.U = 0U;
          TomChannelRegPtr->IRQ_EN.U = 0U;
          TomChannelRegPtr->IRQ_NOTIFY.U = 0U;
        }

        if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
        {
          AtomChannelRegPtr =
                 &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                               ATOM_CH[ModuleNumber].CH[ChannelNumber]);
          /* Configure the channel parameters with Power on reset values*/
         (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                              ATOM_AGC[ModuleNumber].AGC_ENDIS_STAT.U = \
                                  (uint32_t)(1UL << (GPT_BITS_PER_CHANNEL * \
                                (ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC)));
         (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                               ATOM_AGC[ModuleNumber].AGC_ENDIS_CTRL.U = \
                                    (uint32_t)~(GPT_GTM_CHANNEL_ENABLE_UL << \
         (GPT_BITS_PER_CHANNEL * (ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC)));
          AtomChannelRegPtr->CM0.U = 0U;
          /* Set Shadow register also with same TimeOut Value, this is a safety
          measure to avoid unintended update from shadow registers */
          AtomChannelRegPtr->SR0.U = 0U;  
          AtomChannelRegPtr->CN0.U = 0U;
          AtomChannelRegPtr->CTRL.U = 0U;
          AtomChannelRegPtr->IRQ_NOTIFY.U = 0U;
        }
        *DataPtr = GPT_CHANNEL_UNINITIALIZED;
    }
}
#endif
/* #if (GPT_DEINIT_API == STD_ON) */

/*******************************************************************************
** Traceability : NA                                                          **
**                                                                            **
** Syntax : void Gpt_lSetChannelIdentifier                                    **
**   (Gpt_GtmGlobalChannelNoType GlobalChannelNumber, Gpt_ChannelType Channel)**
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-Reentrant                                               **
**                                                                            **
** Parameters (in):    GlobalChannelNumber - Channel Number                   **
**                     Channel :Channel ID                                    **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:  Structure which gives Module Number, Channel Number etc     **
**                                                                            **
** Description :  This routine converts the Global Channel Number to its      **
**                corresponding Channel Number, Module Number, TGC/AGC number.**
**                                                                            **
*******************************************************************************/
static void Gpt_lSetChannelIdentifier(
     Gpt_GtmGlobalChannelNoType GlobalChannelNumber, Gpt_ChannelType Channel )
{
  Gpt_GtmGlobalChannelNoType TempChannelNumber;


  Gpt_ChannelIdentifier[Channel].ChannelNo = GPT_GTM_INVALID_NUMBER;
  Gpt_ChannelIdentifier[Channel].ModuleId = GPT_GTM_INVALID_NUMBER;
  Gpt_ChannelIdentifier[Channel].ModuleNo = GPT_GTM_INVALID_NUMBER;
  Gpt_ChannelIdentifier[Channel].GroupNo = GPT_GTM_INVALID_NUMBER;
  

  #if(GPT_TOM_USED == STD_ON)
  /* Check if its a TOM channel */
  if((GlobalChannelNumber >= GTM_MAX_TIM_CHANNELS)  &&
      (GlobalChannelNumber < (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS)))
  {
    TempChannelNumber = GlobalChannelNumber - GTM_MAX_TIM_CHANNELS;
    /* Calculate Module Id of the TOM channel */
    Gpt_ChannelIdentifier[Channel].ModuleId = GTM_TOM_MODULE;
    Gpt_ChannelIdentifier[Channel].ModuleNo  =                    \
                 (uint8)(TempChannelNumber / GTM_CHANNELS_PER_TOM_MODULE);

    /* Calculate Channel number of the TOM channel */
    Gpt_ChannelIdentifier[Channel].ChannelNo = 
                    TempChannelNumber %GTM_CHANNELS_PER_TOM_MODULE;
    Gpt_ChannelIdentifier[Channel].GroupNo = 
       (Gpt_ChannelIdentifier[Channel].ChannelNo)/GTM_TOM_CHANNELS_PER_TGC;

  }
  #endif 
  /*   #if(GPT_TOM_USED == STD_ON)   */

  #if(GPT_ATOM_USED == STD_ON)
  /* Check if its a ATOM channel */
  if((GlobalChannelNumber >= (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS))
    && (GlobalChannelNumber <                                             \
       (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS + GTM_MAX_ATOM_CHANNELS)))
  {

    TempChannelNumber =
            GlobalChannelNumber - (GTM_MAX_TIM_CHANNELS + GTM_MAX_TOM_CHANNELS);
    /* Calculate Module Id of the ATOM channel */
    Gpt_ChannelIdentifier[Channel].ModuleId = GTM_ATOM_MODULE;
    Gpt_ChannelIdentifier[Channel].ModuleNo  =                             \
                    (uint8)(TempChannelNumber / GTM_CHANNELS_PER_ATOM_MODULE);

    /* Calculate Channel number of the ATOM channel */
    Gpt_ChannelIdentifier[Channel].ChannelNo = 
                            TempChannelNumber%GTM_CHANNELS_PER_ATOM_MODULE;
  }
  #endif 
  /*   #if(GPT_ATOM_USED == STD_ON)   */
}


#if (GPT_ONESHOT_USED == STD_ON)
/*******************************************************************************
** Syntax :void Gpt_lGtmHandleOsm(                                            **
**                            Gpt_ChannelType Channel)                        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  Channel :Channel ID                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to handle channels configured for One shot mode **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Gpt_lGtmHandleOsm(
                                Gpt_ChannelType Channel)
{
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;          /* Ptr to TOM Channel Reg   */
  uint32 RegVal;                             /* For temp reg value storage    */
  uint8 ModuleNo;                            /* Holds the module Number       */
  uint8 ChannelNo;                           /* Holds the Channel Number      */
  uint8 GroupNo;                             /* Holds the Channel Number      */

  /* Extract Module Number and Channel Number */
  ModuleNo  = Gpt_ChannelIdentifier[Channel].ModuleNo;
  ChannelNo = Gpt_ChannelIdentifier[Channel].ChannelNo;
  GroupNo   = Gpt_ChannelIdentifier[Channel].GroupNo;

  /* Check the Module Type */
  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
  {

    /*Misra Violation:MISRA rule 11.4 & 1.2,
    cast from pointer to pointer & Unusual Pointer cast */


    TomChannelRegPtr = \
    &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).TOM_CH[ModuleNo]).\
    CH[ChannelNo]);


    /* Clear the Endis bits corresponding to the channel */
    RegVal =  ((uint32)1U << \
    (GPT_BITS_PER_CHANNEL * (ChannelNo % GTM_TOM_CHANNELS_PER_TGC)));
    (((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).
                       TOM_TGC[ModuleNo]).TGC[GroupNo]).ENDIS_STAT.U= RegVal;

    TomChannelRegPtr->CN0.U = TomChannelRegPtr->CM0.U;
  }

  /* Check the Module Type */
  if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
  {
    /* Clear the Endis bits corresponding to the channel */
    RegVal =  ((uint32)1U << \
    (GPT_BITS_PER_CHANNEL * (ChannelNo  % GTM_ATOM_CHANNELS_PER_AGC))) ;
    (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                             ATOM_AGC[ModuleNo].AGC_ENDIS_STAT.U= RegVal;

    (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                           ATOM_CH[ModuleNo].CH[ChannelNo].CN0.U =     \
           (*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                                  ATOM_CH[ModuleNo].CH[ChannelNo].CM0.U;
  }

}

#endif 
/*#if (GPT_ONESHOT_USED == STD_ON)*/





#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*******************************************************************************
** Syntax :uint8 Gpt_lGetNotifFlag(Gpt_ChannelType Channel)                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Reentrant                                                **
**                                                                            **
** Parameters (in):  Channel :Channel ID                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     Flag value                                               **
**                                                                            **
** Description :     Gets the Notification Flag for the given Channel. First  **
**                   bit in the variable corresponding to the channel gives   **
**                   the Notification flag value                              **
**                                                                            **
*******************************************************************************/
static _INLINE_ uint8 Gpt_lGetNotifFlag(Gpt_ChannelType Channel)
{
  uint8 *DataPtr;
  DataPtr = Gpt_lGetDataAddress(Channel);
  
  return((*DataPtr) & 0x1U);
}

/*******************************************************************************
** Syntax :boolean Gpt_lCheckForNotifCall(uint8 NotifFlag)                    **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Reentrant                                                **
**                                                                            **
** Parameters (in):  NotifFlag :Notification flag value                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     True/False                                               **
**                                                                            **
** Description :     Checks if notification is enabled and Driver mode is     **
**                   GPT_MODE_NORMAL                                          **
**                                                                            **
*******************************************************************************/
static _INLINE_ boolean Gpt_lCheckForNotifCall(uint8 NotifFlag)
{
  return(((Gpt_DriverMode == GPT_MODE_NORMAL) && \
                           (NotifFlag == 1U))?(boolean)TRUE:(boolean)FALSE);

}

#endif 
/* #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)  */


#if (GPT_ONESHOT_USED == STD_ON)
/*******************************************************************************
** Syntax :boolean Gpt_lModeOsm(Gpt_ModeType ChannelMode)                     **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelMode :One shot or Continous                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     True/False                                               **
**                                                                            **
** Description :     Checks if the Gpt channel mode of operation is  one shot **
**                                                                            **
*******************************************************************************/
static _INLINE_ boolean Gpt_lModeOsm(Gpt_ModeType ChannelMode)
{
  return((GPT_MODE_ONESHOT == ChannelMode)?(boolean)TRUE:(boolean)FALSE);
}
#endif 
/*End of #if (GPT_ONESHOT_USED == STD_ON)*/



#if (GPT_SAFETY_ENABLE == STD_ON)

#if (GPT_INITCHECK_API == STD_ON)
/*******************************************************************************
** Traceability    :   [cover parentID=DS_MCAL_SWSC_GPT501,
DS_MCAL_SWSC_GPT502_11]                                                       **
**                                                                            **
** Syntax          :    void Gpt_InitCheck (const Gpt_ConfigType* ConfigPtr)  **
** [/cover]                                                                   **
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
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description     : This routine verifies the initialization the GPT driver. **
**                   Note: The sequence should be                             **
**                    1)Call Gpt_Init                                         **
**                    2)Call Gpt_InitCheck                                    **
**                                                                            **
*******************************************************************************/
Std_ReturnType Gpt_InitCheck (const Gpt_ConfigType* ConfigPtr)
{
  Std_ReturnType ErrorFlag;
  uint32         TempFlag;

  #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || \
                                     (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
  uint8 counter;
  #endif
  uint8 Channel;
  
  const Gpt_ChannelConfigType* LocalGptChannelPtr;
  Gpt_GtmGlobalChannelNoType HwUnit;
  #if (GPT_ONESHOT_USED == STD_ON)
  Gpt_ModeType ChannelMode;
  #endif
  
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; 
  uint8 ModuleNumber;                   
  uint8 ChannelNumber; 
  
  uint8 *DataPtr;
  uint8 ChannelStatus;
  
  #if (GPT_MAX_ASIL_CHANNELS != 0U)
  uint8 AsilIndex=0U;
  #endif
  #if (GPT_MAX_QM_CHANNELS != 0U)
  uint8 QMIndex=0U; 
  #endif
  
  /* To avoid multiple if conditions, storing in CompareFlag */
  /* Comparison to be done for initialization done by Gpt_Init() */   
  uint32 CompareFlag = 0xFFFFFFFFU;  
  
  ErrorFlag = E_NOT_OK;

  if (Gpt_kConfigPtr == ConfigPtr)
  {
    #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || \
                                 (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
    TempFlag = 0U;
    #if (GPT_MAX_ASIL_CHANNELS != 0U)
    for(counter = 0U; counter < GPT_MAX_ASIL_CHANNELS; counter++)
    {
    /* Check if all notifications are disabled for ASIL B channels*/
        CompareFlag &= (~TempFlag ^ ((uint32)Gpt_AsilFlag[counter]));
    }
    #endif
    #if (GPT_MAX_QM_CHANNELS != 0U)
    for(counter = 0U; counter < GPT_MAX_QM_CHANNELS; counter++)
    {
    /* Check if all notifications are disabled for QM channels*/
        CompareFlag &= (~TempFlag ^ ((uint32)Gpt_QMFlag[counter]));
    }
    #endif

    #endif 
    /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

    for(Channel = 0U; Channel < Gpt_kConfigPtr->GptMaxChannels; Channel++)
    {
        LocalGptChannelPtr = ((Gpt_kConfigPtr->ChannelConfigPtr) + Channel);
        /* The AssignedHwUnit contains TOM/ATOM channel used */
        HwUnit = (LocalGptChannelPtr->AssignedHwUnit);
  
        CompareFlag &= Gpt_lCheckChannelIdentifier(HwUnit, Channel);
        /* This if condition is added to make sure the global variable 
        Gpt_ChannelIdentifier is initialized properly, if not exit from loop
        is done immediately to avoid any trap occurings further in the loop */
        if (CompareFlag != 0xFFFFFFFFU)
        {
          break;
        }
        
        TempFlag = 0U;

        #if (GPT_ONESHOT_USED == STD_ON)
        ChannelMode = LocalGptChannelPtr->GptChannelMode;
        #endif

        ModuleNumber = Gpt_ChannelIdentifier[Channel].ModuleNo;
        ChannelNumber = Gpt_ChannelIdentifier[Channel].ChannelNo;

        DataPtr = Gpt_lGetStatusVarAddr(Channel);
        ChannelStatus = *DataPtr;

        if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_TOM_MODULE)
        {
            TomChannelRegPtr = \
               &(((*(Ifx_GTM_TOMx*)(void*)(MODULE_GTM.TOM)).
                                 TOM_CH[ModuleNumber]).CH[ChannelNumber]);
            #if (GPT_ONESHOT_USED == STD_ON)
            if (Gpt_lModeOsm(ChannelMode))
            {
              TempFlag = (uint32_t)(1UL << GPT_GTM_CTRL_OSM);
            }
            #endif
            TempFlag |= (uint32)
            ((uint32)(LocalGptChannelPtr->ClockSelect) << CLOCK_DIV_POS);
            /* Check for proper initialization of channel control register
            with configured clock values and OSM mode */
            /* Clock configuration of GPT channel is done in Gtm_Init and 
            has to be verified in Gpt_InitCheck */
            CompareFlag &= ((~TempFlag) ^ (uint32)(TomChannelRegPtr->CTRL.U));
            #if (GPT_ONESHOT_USED == STD_ON)
            if (Gpt_lModeOsm(ChannelMode))
            {
              TempFlag = 0UL;
            /* Check to verify clear of channel Notify bits */
              CompareFlag &= ((~TempFlag) ^ (uint32)(TomChannelRegPtr->
                                                           IRQ_NOTIFY.U));
              TempFlag = 1UL;
            /* Check to verify interrupt enable for the channel */
              CompareFlag &= ((~TempFlag) ^ (uint32)(TomChannelRegPtr->
                                                               IRQ_EN.U));
            }
            #endif
        }

        if(Gpt_ChannelIdentifier[Channel].ModuleId == GTM_ATOM_MODULE)
        {
            AtomChannelRegPtr =
                 &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).
                               ATOM_CH[ModuleNumber].CH[ChannelNumber]);
            #if (GPT_ONESHOT_USED == STD_ON)
            if (Gpt_lModeOsm(ChannelMode))
            {
              TempFlag = (uint32_t)(1UL << GPT_GTM_CTRL_OSM);
            }
            #endif
            TempFlag |= ((uint32)
            ((uint32)(LocalGptChannelPtr->ClockSelect) << CLOCK_DIV_POS) | 
                                                                SOMP_BIT_POS);
            /* Check for proper initialization of channel control register
            with configured clock values and OSM mode */
            /* Clock configuration of GPT channel is done in Gtm_Init and 
            has to be verified in Gpt_InitCheck */
            CompareFlag &= ((~TempFlag) ^ (uint32)(AtomChannelRegPtr->CTRL.U));
            #if (GPT_ONESHOT_USED == STD_ON)
            if (Gpt_lModeOsm(ChannelMode))
            {
              TempFlag = 0UL;
            /* Check to verify clear of channel Notify bits */
              CompareFlag &= ((~TempFlag) ^ (uint32)(AtomChannelRegPtr->
                                                          IRQ_NOTIFY.U));
              TempFlag = 1UL;
            /* Check to verify interrupt enable for the channel */
              CompareFlag &= ((~TempFlag) ^ (uint32)(AtomChannelRegPtr->
                                                             IRQ_EN.U));
            }
            #endif
        }
        /* Check to verify proper intialization of indices for all 
        configured GPT channels */
        #if (GPT_MAX_ASIL_CHANNELS != 0U)
        if(LocalGptChannelPtr->SignalType == GPT_ASIL_SIGNAL)
        {
            TempFlag = AsilIndex;
            CompareFlag &= ((~TempFlag) ^ (uint32)Gpt_ChannelIndex[Channel]);
            AsilIndex++;
            /* Verification of ChannelStatus */
            TempFlag = GPT_CHANNEL_INITIALIZED;
            CompareFlag &= ((~TempFlag) ^ (uint32)(ChannelStatus));
        }
        #endif
        #if (GPT_MAX_QM_CHANNELS != 0U)
        if(LocalGptChannelPtr->SignalType == GPT_QM_SIGNAL)
        {
            TempFlag = QMIndex;
            CompareFlag &= ((~TempFlag) ^ (uint32)Gpt_ChannelIndex[Channel]);
            QMIndex++;
            /* Verification of ChannelStatus */
            TempFlag = GPT_CHANNEL_INITIALIZED;
            CompareFlag &= ((~TempFlag) ^ (uint32)(ChannelStatus));
        }
        #endif
    }
 
    TempFlag = GPT_MODE_NORMAL;
    /* Check to verify proper initialization of global variable 
    Gpt_DriverMode for the GPT driver*/
    CompareFlag &= ((~TempFlag) ^ (uint32)Gpt_DriverMode);

    /* If all intializations by Gpt_Init are fine CompareFlag value 
    will remain 0xFFFFFFFFU */
    if (CompareFlag == 0xFFFFFFFFU)
    {
      ErrorFlag = E_OK;
    }
  }

  return (ErrorFlag);
}/* End of Gpt_InitCheck() */

/*******************************************************************************
** Syntax : static uint32 Gpt_lCheckChannelIdentifier(HwUnit, Channel)        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non - reentrant                                          **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   Channel :Channel ID                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    :    uint32 - value of CompareFlag                         **
**                                                                            **
** Description :     Function to check correct initialization of global       **
**                                     variable Gpt_ChannelIdentifier         **
**                                                                            **
*******************************************************************************/
static uint32 Gpt_lCheckChannelIdentifier(
     Gpt_GtmGlobalChannelNoType GlobalChannelNumber, Gpt_ChannelType Channel )
{
  Gpt_GtmGlobalChannelNoType TempChannelNumber;
  Gpt_ChannelIdentifierType TempIdentifier;
  uint32 TempFlag;
  uint32 CompareFlag = 0xFFFFFFFFU; 


  #if(GPT_TOM_USED == STD_ON)
  /* Check if its a TOM channel */
  if((GlobalChannelNumber >= GTM_MAX_TIM_CHANNELS)  &&
      (GlobalChannelNumber < (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS)))
  {
    TempChannelNumber = GlobalChannelNumber - GTM_MAX_TIM_CHANNELS;
    /* Calculate Module Id of the TOM channel */
    TempIdentifier.ModuleId = GTM_TOM_MODULE;
    TempFlag = (uint32)TempIdentifier.ModuleId;
    CompareFlag &= 
              (~TempFlag ^ ((uint32)Gpt_ChannelIdentifier[Channel].ModuleId));

    TempIdentifier.ModuleNo  =                    \
                 (uint8)(TempChannelNumber / GTM_CHANNELS_PER_TOM_MODULE);
    TempFlag = (uint32)TempIdentifier.ModuleNo;
    CompareFlag &= 
              (~TempFlag ^ ((uint32)Gpt_ChannelIdentifier[Channel].ModuleNo));

    /* Calculate Channel number of the TOM channel */
    TempIdentifier.ChannelNo = 
                    TempChannelNumber %GTM_CHANNELS_PER_TOM_MODULE;
    TempFlag = (uint32)TempIdentifier.ChannelNo;
    CompareFlag &= 
             (~TempFlag ^ ((uint32)Gpt_ChannelIdentifier[Channel].ChannelNo));

    TempIdentifier.GroupNo = 
           (Gpt_ChannelIdentifier[Channel].ChannelNo)/GTM_TOM_CHANNELS_PER_TGC;
    TempFlag = (uint32)TempIdentifier.GroupNo;
    CompareFlag &= 
             (~TempFlag ^ ((uint32)Gpt_ChannelIdentifier[Channel].GroupNo));

  }
  #endif 
  /*   #if(GPT_TOM_USED == STD_ON)   */

  #if(GPT_ATOM_USED == STD_ON)
  /* Check if its a ATOM channel */
  if((GlobalChannelNumber >= (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS))
    && (GlobalChannelNumber <                                             \
       (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS + GTM_MAX_ATOM_CHANNELS)))
  {

    TempChannelNumber =
            GlobalChannelNumber - (GTM_MAX_TIM_CHANNELS + GTM_MAX_TOM_CHANNELS);
    /* Calculate Module Id of the ATOM channel */
    TempIdentifier.ModuleId = GTM_ATOM_MODULE;
    TempFlag = (uint32)TempIdentifier.ModuleId;
    CompareFlag &= 
             (~TempFlag ^ ((uint32)Gpt_ChannelIdentifier[Channel].ModuleId));

    TempIdentifier.ModuleNo  =                             \
                    (uint8)(TempChannelNumber / GTM_CHANNELS_PER_ATOM_MODULE);
    TempFlag = (uint32)TempIdentifier.ModuleNo;
    CompareFlag &= 
             (~TempFlag ^ ((uint32)Gpt_ChannelIdentifier[Channel].ModuleNo));

    /* Calculate Channel number of the ATOM channel */
    TempIdentifier.ChannelNo = 
                            TempChannelNumber%GTM_CHANNELS_PER_ATOM_MODULE;
    TempFlag = (uint32)TempIdentifier.ChannelNo;
    CompareFlag &= 
             (~TempFlag ^ ((uint32)Gpt_ChannelIdentifier[Channel].ChannelNo));
    TempFlag = (uint32)GPT_GTM_INVALID_NUMBER;
    CompareFlag &= 
             (~TempFlag ^ ((uint32)Gpt_ChannelIdentifier[Channel].GroupNo));
  }
  #endif 
  /*   #if(GPT_ATOM_USED == STD_ON)   */

  return (CompareFlag);
}

#endif 
/* End of GPT_INITCHECK_API == STD_ON */

#if (GPT_GETMODE_API == STD_ON)
/*******************************************************************************
** Traceability    :    [cover parentID=DS_MCAL_SWSC_GPT505]                  **
**                                                                            **
** Syntax          :    Gpt_ModeType Gpt_GetMode(void)                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :    None                                                  **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Reentrant                                             **
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
Gpt_ModeType Gpt_GetMode(void)
{
  return Gpt_DriverMode;
}
#endif  
/* End of GPT_GETMODE_API == STD_ON */

#endif  
/* End of GPT_SAFETY_ENABLE == STD_ON */

/* Stop GPT code section */
#define GPT_STOP_SEC_CODE
#include "MemMap.h"

#define GPT_START_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT185_REQ3,DS_AS_GPT326,
   DS_AS_GPT206_GPT233,DS_AS_GPT093,DS_AS40X_GPT331,DS_AS_GPT127,DS_AS_GPT208,
   DS_AS321_GPT207,DS_AS321_GPT103]

** Syntax : void Gpt_Isr(uint8 ChannelNo)                                     **
** [/cover]                                                                   **
**                                                                            **
** Sync/Async:S Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNo - GPT Channel Number                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Interrupt service routine called on any timer event.         **
*******************************************************************************/
void Gpt_Isr(uint8 ChannelNo)
{
  const Gpt_ChannelConfigType* LocalGptChannelPtr;
  #if (GPT_ONESHOT_USED == STD_ON)
  Gpt_ModeType ChannelMode;
  #endif
  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  uint8 NotifFlag;
  #endif
  #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
  uint8 WakeupFlag;
  #endif
  #if (GPT_ONESHOT_USED == STD_ON)
  uint8 *DataPtr;
  #endif
  #if (GPT_SAFETY_ENABLE == STD_ON)
  uint8 Flag = 0U;
  if( ChannelNo > Gpt_kConfigPtr->GptMaxChannels)
  { 
    /* Report Safety Error */
    SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
          GPT_SID_ISR, GPT_E_PARAM_CHANNEL);
    Flag = 1U;
  }
  if(Flag == 0U)
  #endif
  {
  LocalGptChannelPtr = ( (Gpt_kConfigPtr->ChannelConfigPtr) + ChannelNo);

  /*If this interrupt is triggered by a channel configured
                                     for One shot mode,then process it*/
  #if (GPT_ONESHOT_USED == STD_ON)
  ChannelMode = LocalGptChannelPtr->GptChannelMode;
  DataPtr = Gpt_lGetStatusVarAddr(ChannelNo);
  if (Gpt_lModeOsm(ChannelMode))
  {
    Gpt_lGtmHandleOsm(ChannelNo);
    /* Set the status to expired in case of Timer 
                                         completion in One Shot Mode*/
    *DataPtr = GPT_CHANNEL_EXPIRED;
  }
  #endif 
  /*End of #if (GPT_ONESHOT_USED == STD_ON)*/

  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  NotifFlag = Gpt_lGetNotifFlag(ChannelNo);
  if ( Gpt_lCheckForNotifCall(NotifFlag) )/* GPT093: */
  {
    /* Call Notification if in normal mode and enabled -
       GPT012:, GPT086:, GPT206:,GPT207:, GPT208:,GPT209:, GPT233: */
    ( LocalGptChannelPtr->GptNotificationPtr )();
  }
  #endif
   /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

  #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)

  #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON) /* Report wakeup event */
  /* Check for Wakeup Event */
  WakeupFlag = Gpt_lGetWakeupNotifFlag(ChannelNo);
  if (Gpt_lCheckForSetWakeupEvent(WakeupFlag))
  {
    Gpt_WakeupChannelInfo = 1UL << (LocalGptChannelPtr->GptChannelWakeupInfo);
    EcuM_CheckWakeup(1UL << (LocalGptChannelPtr->GptChannelWakeupInfo));
  }
  #endif 
  /* ( GPT_REPORT_WAKEUP_SOURCE == STD_ON) */

  #endif 
  /* (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) */
  }
}


#define GPT_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"






/*******************************************************************************
**                               End of File                                  **
*******************************************************************************/
