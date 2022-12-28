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
**  $FILENAME   : Gpt_Local.h $                                              **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  $DATE       : 2013-10-22 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains local functionality of GPT driver.      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef GPT_LOCAL_H
#define GPT_LOCAL_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/

/* To set the error flag */
#define GPT_ERROR_SET          (1U)

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

#if(GPT_PB_FIXEDADDR == STD_OFF)
/* Start 32 bit variable section */
#define GPT_START_SEC_VAR_32BIT
#include "MemMap.h"
/* To store the Gpt driver configuration pointer */
extern const Gpt_ConfigType* Gpt_kConfigPtr;
/* Stop 32 bit variable section */
#define GPT_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#endif /* #if(GPT_PB_FIXEDADDR == STD_OFF) */

#if(GPT_PB_FIXEDADDR == STD_ON)
#define GPT_START_SEC_CONST_32BIT
#include "MemMap.h"
/* The config pointer is initialised to first instance of configuration */
extern const Gpt_ConfigType* const Gpt_kConfigPtr;
#define GPT_STOP_SEC_CONST_32BIT
#include "MemMap.h"
#endif /* #if(GPT_PB_FIXEDADDR == STD_ON) */

/* Start 8 bit variable section */
#define GPT_START_SEC_VAR_8BIT
#include "MemMap.h"

extern volatile uint8 Gpt_DriverMode;

extern uint8 Gpt_ChannelIndex[GPT_MAX_CHANNELS];

extern Gpt_ChannelIdentifierType Gpt_ChannelIdentifier[GPT_MAX_CHANNELS];

#define GPT_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#if( GPT_SAFETY_ENABLE == STD_ON)
#if (GPT_MAX_ASIL_CHANNELS != 0U)

#define GPT_START_SEC_ASIL0_VAR_8BIT
#include "MemMap.h"
extern uint8 Gpt_AsilChannelStatus[GPT_MAX_ASIL_CHANNELS];
#define GPT_STOP_SEC_ASIL0_VAR_8BIT
#include "MemMap.h"

#endif
#endif
#if (GPT_MAX_QM_CHANNELS != 0U)

#define GPT_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 Gpt_QMChannelStatus[GPT_MAX_QM_CHANNELS];
#define GPT_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif


#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||            \
                                  (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) )
/* Variable to store Notification and WakeUp Flag for all channels 
                                                     (Max number is 32) */
/* Bit 1 gives Notification flag info and Bit 2 gives WakeUp flag info */
#if( GPT_SAFETY_ENABLE == STD_ON)
#if (GPT_MAX_ASIL_CHANNELS != 0U)

#define GPT_START_SEC_ASIL0_VAR_8BIT
#include "MemMap.h"
extern uint8 Gpt_AsilFlag[GPT_MAX_ASIL_CHANNELS];
#define GPT_STOP_SEC_ASIL0_VAR_8BIT
#include "MemMap.h"

#endif
#endif

#if (GPT_MAX_QM_CHANNELS != 0U)

#define GPT_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 Gpt_QMFlag[GPT_MAX_QM_CHANNELS];
#define GPT_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif

#endif /*End of #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || 
                                  (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)) */



/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define GPT_START_SEC_CODE
#include "MemMap.h"

#if (GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON)

extern boolean Gpt_lCheckChannelStatus (Gpt_ChannelType Channel);

#endif /* #if (GPT_TIME_REMAINING_API == STD_ON)   \
                                      || (GPT_TIME_ELAPSED_API == STD_ON) */

#if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )
#if ( (GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON) )
/* To check DET and Safety check errors in Gpt_GetTimeElapsed and 
                                                 Gpt_GetTimeRemaining API's */
extern uint32 Gpt_lGetTimeDetSafetyCheck(Gpt_ChannelType Channel, 
                                                             uint8 Gpt_Sid);
#endif
/* ( (GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON) )*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
extern uint32 Gpt_lNotifDetSafetyCheck(Gpt_ChannelType Channel,
                                                             uint8 Gpt_Sid);
#endif
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON ) */

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||            \
                                  (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) )
/*******************************************************************************
** Syntax           : _IFXEXTERN_ _INLINE_ uint8 *Gpt_lGetDataAddress         **
**                    (                                                       **
**                       Gpt_ChannelType Channel                              **
**                    )                                                       **
** Traceability     : [cover parentID=DS_MCAL_SWSC_GPT503,
DS_MCAL_SWSC_GPT506]                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       :  Reentrant                                              **
**                                                                            **
** Parameters(in)   : Channel - Gpt channel number                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint8*                                                  **
**                                                                            **
** Description      : Is called to Get Address of the channel variable        **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 *Gpt_lGetDataAddress(Gpt_ChannelType Channel)
{
  uint8 *DataPtr = NULL_PTR;
  uint8 ChannelIndex;
  #if ( GPT_SAFETY_ENABLE == STD_ON )
  #if (GPT_MAX_ASIL_CHANNELS != 0U)
  const Gpt_ChannelConfigType* LocalGptChannelPtr;

  LocalGptChannelPtr = ( (Gpt_kConfigPtr->ChannelConfigPtr) + Channel);

  /* ChannelIndex is fetched from the index array based on ASIL or QM signal
  and the appropriate address of the channel flag variable is returned from the 
  NotifFlag array */

  if( (LocalGptChannelPtr->SignalType) == GPT_ASIL_SIGNAL )
  {
    ChannelIndex = Gpt_ChannelIndex[Channel];
    DataPtr = &Gpt_AsilFlag[ChannelIndex];
  }
  else
  #endif /* ( GPT_MAX_ASIL_CHANNELS == STD_ON ) */
  #endif /* ( GPT_SAFETY_ENABLE == STD_ON ) */
  {
  #if (GPT_MAX_QM_CHANNELS != 0U)
    ChannelIndex = Gpt_ChannelIndex[Channel];
    DataPtr = &Gpt_QMFlag[ChannelIndex];
  #endif /* ( GPT_MAX_QM_CHANNELS == STD_ON ) */
  }

  
  return(DataPtr);
} 

#endif /* #if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||      \
                                  (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)) */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ _INLINE_ uint8 *Gpt_lGetStatusVarAddr       **
**                    (                                                       **
**                       Gpt_ChannelType Channel                              **
**                    )                                                       **
** Traceability     : [cover parentID=DS_MCAL_SWSC_GPT503,
DS_MCAL_SWSC_GPT506]                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       :  Reentrant                                              **
**                                                                            **
** Parameters(in)   : Channel - Gpt channel number                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint8*                                                  **
**                                                                            **
** Description      : Is called to Get Address of the channel status variable **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 *Gpt_lGetStatusVarAddr(Gpt_ChannelType Channel)
{
  uint8 *DataPtr = NULL_PTR;
  uint8 ChannelIndex;
  #if ( GPT_SAFETY_ENABLE == STD_ON )
  #if (GPT_MAX_ASIL_CHANNELS != 0U)
  const Gpt_ChannelConfigType* LocalGptChannelPtr;

  LocalGptChannelPtr = ( (Gpt_kConfigPtr->ChannelConfigPtr) + Channel);

  /* ChannelIndex is fetched from the index array based on ASIL or QM signal
  and the appropriate address of the channel status variable is returned from 
  the ChannelStatus array */

  if( (LocalGptChannelPtr->SignalType) == GPT_ASIL_SIGNAL )
  {
    ChannelIndex = Gpt_ChannelIndex[Channel];
    DataPtr = &Gpt_AsilChannelStatus[ChannelIndex];
  }
  else
  #endif /* ( GPT_MAX_ASIL_CHANNELS == STD_ON ) */
  #endif /* ( GPT_SAFETY_ENABLE == STD_ON ) */
  {
  #if (GPT_MAX_QM_CHANNELS != 0U)
    ChannelIndex = Gpt_ChannelIndex[Channel];
    DataPtr = &Gpt_QMChannelStatus[ChannelIndex];
  #endif /* ( GPT_MAX_QM_CHANNELS == STD_ON ) */
  }
  return(DataPtr);
} 

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/* Gets the Wakeup Notification Flag for the given Channel */
/* Second bit in the variable corresponding to the channel gives the WakeUp 
flag value */
_IFXEXTERN_ _INLINE_ uint8 Gpt_lGetWakeupNotifFlag(Gpt_ChannelType Channel)
{
  uint8 *DataPtr;
  DataPtr = Gpt_lGetDataAddress(Channel);
  
  return(((*DataPtr) >> 1U) & 0x1U);
}

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
/* Checks if wakeup event if GPT_REPORT_WAKEUP_SOURCE is configured STD_ON,
   wakeup is enabled and Driver mode is GPT_MODE_SLEEP */
_IFXEXTERN_ _INLINE_ boolean Gpt_lCheckForSetWakeupEvent(uint8 WakeupFlag)
{
  return(((Gpt_DriverMode == GPT_MODE_SLEEP) && \
                         (WakeupFlag == 1U))?(boolean)TRUE:(boolean)FALSE);
}
#endif

#endif /* #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) */

/* Gpt channel mode of operation continuous */
_IFXEXTERN_ _INLINE_ boolean Gpt_lModeCont(Gpt_ModeType ChannelMode)
{
  return((GPT_MODE_CONTINUOUS == ChannelMode)?(boolean)TRUE:(boolean)FALSE);
}

#define GPT_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End of GPT_LOCAL_H */