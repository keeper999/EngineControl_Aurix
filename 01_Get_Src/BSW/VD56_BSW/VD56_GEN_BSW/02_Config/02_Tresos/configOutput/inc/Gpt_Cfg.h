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
**  FILENAME  : Gpt_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\28 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:20                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  BSW MODULE DESCRIPTION : Gpt.xdm                                          **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GPT configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_GPT_Driver, Release-4.0                    **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/******************************************************************************/
#ifndef  GPT_CFG_H
#define  GPT_CFG_H



/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*Section to Generate Autosar Specific Version Information*/


#define GPT_AR_RELEASE_MAJOR_VERSION  (4U)
#define GPT_AR_RELEASE_MINOR_VERSION  (0U)
#define GPT_AR_RELEASE_REVISION_VERSION  (3U)

/*Section to Generate Vendor Specific Version Information*/
/* Vendor specific implementation version information */
#define GPT_SW_MAJOR_VERSION   (3U)
#define GPT_SW_MINOR_VERSION   (1U)
#define GPT_SW_PATCH_VERSION   (1U)






/*
Container : GptDriverConfiguration - GPT183:
This container contains the channel-wide configuration (parameters) of
the GPT Driver.
*/

/*
Configuration: GPT_DEV_ERROR_DETECT
Preprocessor switch to enable/disable the development error detection and 
reporting. ( GPT183:,GPT175:,GPT176:,GPT177:,GPT178: )
- if STD_ON, Enable development error detection 
- if STD_OFF, Disable development error detection
*/
#define GPT_DEV_ERROR_DETECT                  (STD_ON)

/*
Configuration: GPT_REPORT_WAKEUP_SOURCE
Preprocessor switch to enable/disable the wakeup source reporting - GPT183:
- if STD_ON, Report wakeup source 
- if STD_OFF, Dont report wakeup source
*/
#define GPT_REPORT_WAKEUP_SOURCE              (STD_OFF)

/*
Configuration: GPT_DEBUG_SUPPORT
Preprocessor switch to enable/disable the Debug Support
which is applicable to AS402	 - GPT333,GPT334,GPT337:
- if STD_ON, Debug Support Enabled 
- if STD_OFF, Debug Support Disabled 
(Always STD_OFF for versions other than AS402)
*/



#define GPT_DEBUG_SUPPORT              (STD_OFF)




#define GPT_MAX_CHANNELS  (6U)


#define GPT_MAX_ASIL_CHANNELS  (0U)



#define GPT_MAX_QM_CHANNELS  (6U)


#define GPT_TOM_USED              (STD_ON)

#define GPT_ATOM_USED              (STD_ON)

/*
Container : Configuration of optional API services - GPT193:
This container contains all configuration switches for configuring
optional API services of the GPT driver.
*/


/*
Configuration: GPT_VERSION_INFO_API
Adds/removes the service Gpt_GetVersionInfo() from the code 
- if STD_ON, Gpt_GetVersionInfo() can be used
- if STD_OFF, Gpt_GetVersionInfo() can not be used
*/
#define GPT_VERSION_INFO_API                  (STD_OFF)

/*
Configuration: GPT_DEINIT_API
Adds/removes the service Gpt_DeInit() from the code 
- if STD_ON, Gpt_DeInit() can be used
- if STD_OFF, Gpt_DeInit() can not be used
*/
#define GPT_DEINIT_API                        (STD_OFF)

/*
Configuration: GPT_TIME_ELAPSED_API
Adds/removes the service Gpt_GetTimeElapsed() from the code 
- if STD_ON, Gpt_GetTimeElapsed() can be used
- if STD_OFF, Gpt_GetTimeElapsed() can not be used
*/
#define GPT_TIME_ELAPSED_API                  (STD_ON)

/*
Configuration: GPT_TIME_REMAINING_API
Adds/removes the service Gpt_GetTimeRemaining() from the code 
- if STD_ON, Gpt_GetTimeRemaining() can be used
- if STD_OFF, Gpt_GetTimeRemaining() can not be used
*/
#define GPT_TIME_REMAINING_API                (STD_OFF)

/*
Configuration: GPT_ENABLE_DISABLE_NOTIFICATION_API
Adds/removes the service Gpt_EnableNotification() and Gpt_DisableNotification 
from the code 
- if STD_ON, Gpt_EnableNotification() and Gpt_DisableNotification  can be used
- if STD_OFF, Gpt_EnableNotification() and Gpt_DisableNotification  can not be
  used
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API   (STD_ON)

/*
Configuration: GPT_WAKEUP_FUNCTIONALITY_API
Adds/removes the service Gpt_SetMode(), Gpt_EnableWakeup(),
Gpt_DisableWakeup() and Gpt_CheckWakeup() from the code 
- if STD_ON, Gpt_SetMode(), Gpt_EnableWakeup(), Gpt_DisableWakeup() and 
  Gpt_CheckWakeup() can be used
- if STD_OFF, Gpt_SetMode(), Gpt_EnableWakeup(), Gpt_DisableWakeup() and 
  Gpt_CheckWakeup() can not be used
*/
#define GPT_WAKEUP_FUNCTIONALITY_API          (STD_OFF)




/*
Configuration: GPT_SAFETY_ENABLE
Preprocessor switch to enable/disable the GPT Safety features.
- if STD_ON, GPT Safety Enabled 
- if STD_OFF, GPT Safety Disabled
*/
#define GPT_SAFETY_ENABLE          (STD_OFF)


/*
Configuration: GPT_INITCHECK_API
Preprocessor switch to enable/disable the GPT InitCheck API.
- if STD_ON, GPT InitCheck API Enabled 
- if STD_OFF, GPT InitCheck API Disabled
*/
#define GPT_INITCHECK_API              (STD_OFF)

/*
Configuration: GPT_GETMODE_API
Preprocessor switch to enable/disable the GPT GetMode API.
- if STD_ON, GPT GetMode API Enabled 
- if STD_OFF, GPT GetMode API Disabled
*/
#define GPT_GETMODE_API              (STD_OFF)


/* 
   Gpt Channel ID Enumerations for Channel Configuration Instance 
   GptChannelConfigSet_0
*/
#ifndef GptConf_GptChannel_MOS_TIMER
#define GptConf_GptChannel_MOS_TIMER  ((Gpt_ChannelType)0U)
#endif
#ifndef GptConf_GptChannel_L9781_STARTUP_SEQUENCE
#define GptConf_GptChannel_L9781_STARTUP_SEQUENCE  ((Gpt_ChannelType)1U)
#endif
#ifndef GptConf_GptChannel_PWL_TIMER
#define GptConf_GptChannel_PWL_TIMER  ((Gpt_ChannelType)2U)
#endif
#ifndef GptConf_GptChannel_PMP_DELAY
#define GptConf_GptChannel_PMP_DELAY  ((Gpt_ChannelType)3U)
#endif
#ifndef GptConf_GptChannel_APPLICATIVE_500NS
#define GptConf_GptChannel_APPLICATIVE_500NS  ((Gpt_ChannelType)4U)
#endif
#ifndef GptConf_GptChannel_CJ135_IRQ_TIMER
#define GptConf_GptChannel_CJ135_IRQ_TIMER  ((Gpt_ChannelType)5U)
#endif





/*******************************************************************************
**                      Derived Configuration Parameters                      **
*******************************************************************************/

/*
Configuration: GPT_ONESHOT_USED
The configuration contains oneshot mode channels
*/
#define GPT_ONESHOT_USED                      (STD_ON)


/*
Configuration: GPT_PB_FIXEDADDR
   This parameter enables the user to fix the PB config pointer to first 
   instance of configuration
*/
#define GPT_PB_FIXEDADDR                      (STD_OFF)

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

#endif /* GPT_CFG_H */
