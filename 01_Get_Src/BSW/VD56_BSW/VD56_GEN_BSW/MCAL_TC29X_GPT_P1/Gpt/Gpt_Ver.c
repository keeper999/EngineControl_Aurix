/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Gpt_Ver.c $                                                **
**                                                                            **
**  $CC VERSION : \main\10 $                                                 **
**                                                                            **
**  $DATE       : 2013-11-06 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains AUTOSAR version specific functionality   **
**                of GPT driver(AS4.0.3)                                      **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Gpt.h"

#include "Gpt_Local.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/* Gpt.c checks if the correct version of Gpt.h is included - GPT0256: */
/* [cover parentID=DS_AS40X_GPT256_1] */



/*Check for Autosar Versions for AS402 & AS403*/
#ifndef GPT_AR_RELEASE_MAJOR_VERSION
  #error "GPT_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef GPT_AR_RELEASE_MINOR_VERSION
  #error "GPT_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef GPT_AR_RELEASE_REVISION_VERSION
  #error "GPT_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( GPT_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "GPT_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( GPT_AR_RELEASE_MINOR_VERSION != 0U )
  #error "GPT_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/* Check for definition of SW version Information */
#ifndef GPT_SW_MAJOR_VERSION
  #error "GPT_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef GPT_SW_MINOR_VERSION
  #error "GPT_SW_MINOR_VERSION is not defined. "
#endif

#ifndef GPT_SW_PATCH_VERSION
  #error "GPT_SW_PATCH_VERSION is not defined. "
#endif

#if ( GPT_SW_MAJOR_VERSION != 3U )
  #error "GPT_SW_MAJOR_VERSION does not match. "
#endif

#if ( GPT_SW_MINOR_VERSION != 1U )
  #error "GPT_SW_MINOR_VERSION does not match. "
#endif

/*
  GPT256: Inter Module Checks to avoid integration of incompatible files
*/
#if (GPT_DEV_ERROR_DETECT == STD_ON)


#ifndef  DET_AR_RELEASE_MAJOR_VERSION
 #error "DET_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#ifndef  DET_AR_RELEASE_MINOR_VERSION
 #error "DET_AR_RELEASE_MINOR_VERSION is not defined."
#endif

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif
/* End Of GPT_DEV_ERROR_DETECT */
/* [/cover] */

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

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

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#define GPT_START_SEC_CODE
#include "MemMap.h"

#if (GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON)
/*******************************************************************************
** Traceability :                                                             **
** Syntax : boolean Gpt_lCheckChannelStatus (Gpt_ChannelType Channel)         **
** [/cover]                                                                   **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel - ID                                             **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: Flag (boolean)                                               **
**                                                                            **
** Description : Service to check the ChannelStatus                           **
**                                                                            **
*******************************************************************************/
boolean Gpt_lCheckChannelStatus (Gpt_ChannelType Channel)
{
  uint8 *DataPtr;
  uint8 ChannelStatus;
  boolean Flag = (boolean)FALSE;
  
  DataPtr = Gpt_lGetStatusVarAddr(Channel);
  ChannelStatus = *DataPtr;
  if((ChannelStatus == GPT_CHANNEL_STARTED) || \
        (ChannelStatus == GPT_CHANNEL_STOPPED) || \
            (ChannelStatus == GPT_CHANNEL_EXPIRED))
  {
    Flag = (boolean)TRUE;
  }
  return Flag;
}
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON) || ( GPT_SAFETY_ENABLE == STD_ON )

#if ( (GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON) )
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_GPT176_17_GPT210_GPT211_GPT178_17,
   DS_AS_GPT222_1_GPT223_1,DS_AS_GPT222_2_GPT223_2,DS_AS_GPT210_1_GPT211_1]

** Syntax : uint32  Gpt_lGetTimeDetSafetyCheck(                               **
**                                     Gpt_ChannelType Channel,uint8 GptSid)  **
** [/cover]                                                                   **
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
** Description : Service to check DET and Safety errors in                    **
**               Gpt_GetTimeElapsed and Gpt_GetTimeRemaining API's            **
**                                                                            **
*******************************************************************************/
uint32 Gpt_lGetTimeDetSafetyCheck(Gpt_ChannelType Channel,
                                            uint8 Gpt_Sid)
{
  uint32 ErrorFlag;
  Gpt_ChannelType MaxChannels;
  ErrorFlag = 0U;  /* Initialize error flag */
  
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* DET check for Init not done - GPT222:*/
  if (Gpt_DriverMode == GPT_MODE_UNINITIALIZED)
  {
    /* Report to  DET */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     Gpt_Sid, GPT_E_UNINIT );
    ErrorFlag = GPT_ERROR_SET;
  }
  else
  #endif
  {
    /* Get the maximum number of channels */
    MaxChannels = Gpt_kConfigPtr->GptMaxChannels;
    /* Check channel out of range */
    if ( Channel >= MaxChannels )
    {
      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to  DET - GPT210:*/
      Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                       Gpt_Sid, GPT_E_PARAM_CHANNEL);
      #endif
      #if (GPT_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                       Gpt_Sid, GPT_E_PARAM_CHANNEL);
      #endif
      ErrorFlag = GPT_ERROR_SET;
    }
  }
  return (ErrorFlag);

}/* End of Gpt_lGetTimeDetSafetyCheck */
/******************************************************************************/
#endif
/* End of #if ( (GPT_TIME_ELAPSED_API == STD_ON)
                || (GPT_TIME_REMAINING_API == STD_ON) )*/

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*******************************************************************************
** Traceability : 

** Syntax : uint32  Gpt_lNotifDetSafetyCheck(                                 **
**                                     Gpt_ChannelType Channel,uint8 GptSid)  **
** [/cover]                                                                   **
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
** Description : Service to check DET and Safety errors in                    **
**               Gpt_EnableNotification and Gpt_DisableNotification API's     **
**                                                                            **
*******************************************************************************/
uint32 Gpt_lNotifDetSafetyCheck(Gpt_ChannelType Channel,
                                            uint8 Gpt_Sid)
{
  uint32 ErrorFlag;
  Gpt_ChannelType MaxChannels;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  const Gpt_ChannelConfigType* LocalGptChannelPtr;
  #endif
  
  ErrorFlag = 0U;  /* Initialize error flag */
  
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* DET check for Init not done - GPT222:*/
  if (Gpt_DriverMode == GPT_MODE_UNINITIALIZED)
  {
    /* Report to  DET */
    Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                     Gpt_Sid, GPT_E_UNINIT );
    ErrorFlag = GPT_ERROR_SET;
  }
  else
  #endif
  {
    /* Get the maximum number of channels */
    MaxChannels = Gpt_kConfigPtr->GptMaxChannels;
    /* Check channel out of range */
    if ( Channel >= MaxChannels )
    {
      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to  DET - GPT210:*/
      Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                       Gpt_Sid, GPT_E_PARAM_CHANNEL);
      #endif
      #if (GPT_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID, 
                       Gpt_Sid, GPT_E_PARAM_CHANNEL);
      #endif
      ErrorFlag = GPT_ERROR_SET;
    }
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /*Report DET if notification function is invalid */
    else
    {
      /* Get pointer to channel config */
      LocalGptChannelPtr = ( (Gpt_kConfigPtr->ChannelConfigPtr) + Channel);
      /* GPT377: Report DET if notification function is invalid */
      if ((LocalGptChannelPtr->GptNotificationPtr) == NULL_PTR)
      {
        /* Report to DET - GPT214: */
        Det_ReportError( GPT_MODULE_ID, GPT_INSTANCE_ID,
                         GPT_SID_ENABLE_NOTIFICATION, GPT_E_PARAM_CHANNEL);

        ErrorFlag = GPT_ERROR_SET; /* Set ErrorFlag */
      }
    }
    #endif
  }
  return (ErrorFlag);

}/* End of Gpt_lNotifDetSafetyCheck */
/******************************************************************************/
#endif
/* End of #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)*/

#endif /* End of (GPT_DEV_ERROR_DETECT == STD_ON) ||    \
                                           ( GPT_SAFETY_ENABLE == STD_ON ) */

#define GPT_STOP_SEC_CODE
#include "MemMap.h"


