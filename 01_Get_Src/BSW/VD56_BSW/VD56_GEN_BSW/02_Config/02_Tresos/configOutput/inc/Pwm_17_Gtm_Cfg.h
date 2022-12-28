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
**  $FILENAME  : Pwm_17_Gtm_Cfg.h  $                                          **
**                                                                            **
**   $CC VERSION : \main\26 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:18                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**  DESCRIPTION  : PWM configuration generated out of ECU configuration       **
**                   file                                                     **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                     **
**                                                                            **
*******************************************************************************/

#ifndef PWMCFG_H
#define PWMCFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define PWM_17_GTM_AR_RELEASE_MAJOR_VERSION  (4U)
#define PWM_17_GTM_AR_RELEASE_MINOR_VERSION  (0U)
#define PWM_17_GTM_AR_RELEASE_REVISION_VERSION  (3U)

#define PWM_17_GTM_SW_MAJOR_VERSION  (3U)
#define PWM_17_GTM_SW_MINOR_VERSION  (0U)
#define PWM_17_GTM_SW_PATCH_VERSION  (3U)


/*
                    Container:PwmGeneral
*/
/* Instance ID for PWM_17_Gtm module */
#define PWM_17_GTM_INSTANCE_ID         ((uint8)0U)

/*
PWM075: Pre Compile time parameters are placed in Pwm_Cfg.h
*/
/*
  Configuration: PWM_DEV_ERROR_DETECT : PWM064 PWM078
  Configuration of Development Error Detection 
  PWM064: API Parameter Checking is enabled if this compiler
  switch is STD_ON.
  PWM078: All errors are reported to Det_ReportError if the
  switch is STD_ON.
  Adds/removes the Development error detection 
  from the code 
  - if STD_ON, Development error detection is enabled
  - if STD_OFF, Development error detection is disabled
*/
#define PWM_DEV_ERROR_DETECT                 (STD_ON)


/*
  Configuration: PWM_DE_INIT_API
  Configuration of Pwm_DeInit API
  Adds/removes the service Pwm_DeInit() 
  from the code 
  - if STD_ON, Pwm_DeInit() can be used
  - if STD_OFF, Pwm_DeInit() cannot be used
*/
#define PWM_DE_INIT_API                      (STD_OFF)


/*
  Configuration: PWM_GET_OUTPUT_STATE_API
  Configuration of Pwm_Get_Output_State_Api
  Adds/removes the service Pwm_GetOutputState() 
  from the code 
  - if STD_ON, Pwm_GetOutputState() can be used
  - if STD_OFF, Pwm_GetOutputState() cannot be used
*/
#define PWM_GET_OUTPUT_STATE_API                       (STD_ON)


/*
  Configuration: PWM_SET_DUTY_CYCLE_API
  Configuration of Pwm_Set_Duty_Cycle_Api
  Adds/removes the service Pwm_GetOutputState() 
  from the code 
  - if STD_ON, Pwm_SetDutyCycle() can be used
  - if STD_OFF,Pwm_SetDutyCycle() cannot be used
*/
#define PWM_SET_DUTY_CYCLE_API                       (STD_ON)


/*
  Configuration: PWM_SET_OUTPUT_TO_IDLE_API
  Configuration of Pwm_Set_Output_To_Idle_Api
  Adds/removes the service Pwm_SetOutputToIdle() 
  from the code 
  - if STD_ON, Pwm_SetOutputToIdle() can be used
  - if STD_OFF,Pwm_SetOutputToIdle() cannot be used
*/
#define PWM_SET_OUTPUT_TO_IDLE_API                       (STD_ON)


/*
  Configuration: PWM_SET_PERIOD_AND_DUTY_API
  Configuration of Pwm_Set_Period_And_Duty_Api
  Adds/removes the service Pwm_SetPeriodAndDuty() 
  from the code 
  - if STD_ON, Pwm_SetPeriodAndDuty() can be used
  - if STD_OFF,Pwm_SetPeriodAndDuty() cannot be used
*/
#define PWM_SET_PERIOD_AND_DUTY_API                       (STD_ON)


/*
  Enables/Disables the Safety features 
  - if STD_ON, Safety features are enabled
  - if STD_OFF, Safety features are disabled
*/

#define PWM_SAFETY_ENABLE                 (STD_OFF)

/*
  Configuration: PWM_NOTIFICATION_SUPPORTED
  Adds/removes the service Pwm_EnableNotification()
  and Pwm_DisableNotification() from the code 
  - if STD_ON, Notification API's can be used
  - if STD_OFF, Notification API's cannot be used
*/
#define PWM_NOTIFICATION_SUPPORTED           (STD_ON)



#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD      (STD_OFF)


#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD    (STD_OFF)

/*
  Configuration: PWM_VERSION_INFO_API
  Adds/removes the service Pwm_GetVersionInfo() 
  from the code 
  - if STD_ON, Pwm_GetVersionInfo() can be used
  - if STD_OFF, Pwm_GetVersionInfo() cannot be used
*/
#define PWM_VERSION_INFO_API                 (STD_OFF)


/* Configuration : PwmPBFixedAddress
   This parameter enables the user to switch STD_ON/STD_OFF the
   PostBuild Fixed Address Feature  
*/
#define PWM_PB_FIXEDADDR           (STD_OFF)


/* Configuration : PwmDutyShiftInTicks
   This parameter enables the user to enter the duty cycle and 
   shift value in absolute ticks, instead of percentage
*/
#define PWM_DUTY_SHIFT_IN_TICKS     (STD_OFF)


/* Configured PWM Channels Symbolic Names */
#ifndef Pwm_17_GtmConf_PwmChannel_M_INTK_VVT
#define Pwm_17_GtmConf_PwmChannel_M_INTK_VVT          ((Pwm_17_Gtm_ChannelType)0)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_LOW_PRES_FUEL_PUMP_VAR_SPD
#define Pwm_17_GtmConf_PwmChannel_M_LOW_PRES_FUEL_PUMP_VAR_SPD          ((Pwm_17_Gtm_ChannelType)1)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_OIL_LEVEL_PWM_CMD
#define Pwm_17_GtmConf_PwmChannel_M_OIL_LEVEL_PWM_CMD          ((Pwm_17_Gtm_ChannelType)2)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_EXH_VVT
#define Pwm_17_GtmConf_PwmChannel_M_EXH_VVT          ((Pwm_17_Gtm_ChannelType)3)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_FLEXRAY_EN
#define Pwm_17_GtmConf_PwmChannel_M_FLEXRAY_EN          ((Pwm_17_Gtm_ChannelType)4)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_MAIN_DWN_LBDA_SNS_HEAT
#define Pwm_17_GtmConf_PwmChannel_M_MAIN_DWN_LBDA_SNS_HEAT          ((Pwm_17_Gtm_ChannelType)5)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_4
#define Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_4          ((Pwm_17_Gtm_ChannelType)6)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_MAIN_UPS_LBDA_SNS_HEAT
#define Pwm_17_GtmConf_PwmChannel_M_MAIN_UPS_LBDA_SNS_HEAT          ((Pwm_17_Gtm_ChannelType)7)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_CANISTER_PURGE_VALVE
#define Pwm_17_GtmConf_PwmChannel_M_CANISTER_PURGE_VALVE          ((Pwm_17_Gtm_ChannelType)8)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_CTRL_THERMOSTAT_VALVE
#define Pwm_17_GtmConf_PwmChannel_M_CTRL_THERMOSTAT_VALVE          ((Pwm_17_Gtm_ChannelType)9)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_COOLANT_FAN_1
#define Pwm_17_GtmConf_PwmChannel_M_COOLANT_FAN_1          ((Pwm_17_Gtm_ChannelType)10)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_COOLANT_FAN_2
#define Pwm_17_GtmConf_PwmChannel_M_COOLANT_FAN_2          ((Pwm_17_Gtm_ChannelType)11)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_TURBO_COOLING_PUMP
#define Pwm_17_GtmConf_PwmChannel_M_TURBO_COOLING_PUMP          ((Pwm_17_Gtm_ChannelType)12)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_ASIC_GDI_CLK_EXT
#define Pwm_17_GtmConf_PwmChannel_M_ASIC_GDI_CLK_EXT          ((Pwm_17_Gtm_ChannelType)13)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_1
#define Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_1          ((Pwm_17_Gtm_ChannelType)14)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_2
#define Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_2          ((Pwm_17_Gtm_ChannelType)15)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_SUPPLY_WDI
#define Pwm_17_GtmConf_PwmChannel_M_SUPPLY_WDI          ((Pwm_17_Gtm_ChannelType)16)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_3
#define Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_3          ((Pwm_17_Gtm_ChannelType)17)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_OIL_VAR_PUMP_VALVE
#define Pwm_17_GtmConf_PwmChannel_M_OIL_VAR_PUMP_VALVE          ((Pwm_17_Gtm_ChannelType)18)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_DUMP_VALVE
#define Pwm_17_GtmConf_PwmChannel_M_DUMP_VALVE          ((Pwm_17_Gtm_ChannelType)19)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_UPS_LBDA_SNS_1
#define Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_UPS_LBDA_SNS_1          ((Pwm_17_Gtm_ChannelType)20)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_UPS_LBDA_SNS_2
#define Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_UPS_LBDA_SNS_2          ((Pwm_17_Gtm_ChannelType)21)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_DWN_LBDA_SNS_1
#define Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_DWN_LBDA_SNS_1          ((Pwm_17_Gtm_ChannelType)22)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_DWN_LBDA_SNS_2
#define Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_DWN_LBDA_SNS_2          ((Pwm_17_Gtm_ChannelType)23)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_INTK_THR_MOT_PWM
#define Pwm_17_GtmConf_PwmChannel_M_INTK_THR_MOT_PWM          ((Pwm_17_Gtm_ChannelType)24)
#endif
#ifndef Pwm_17_GtmConf_PwmChannel_M_INTK_THR_MOT_DIR
#define Pwm_17_GtmConf_PwmChannel_M_INTK_THR_MOT_DIR          ((Pwm_17_Gtm_ChannelType)25)
#endif

/*
   Configuration:Max channels configured for Pwm
   Maximum Channels is calculated based on the number of channels configured for each configuration.
   For instance if configuration set 1 has 5 channels and configuration set 2 has
   7 channels then the Maxchannels is 7.
*/


#define PWM_MAX_CHANNELS           ((Pwm_17_Gtm_ChannelType)26)

#define PWM_MAX_QM_CHANNELS    (26)

/*
   Derived pre compile switches for optimization
   purpose
*/

#define PWM_VARIABLE_PERIOD_USED                     (STD_ON)
#define PWM_FIXED_PERIOD_USED                        (STD_OFF)
#define PWM_FIXED_PERIOD_SHIFTED_USED                (STD_OFF)
#define PWM_USED_FIXED_PERIOD_CENTER_ALIGNED         (STD_OFF)

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

#endif
