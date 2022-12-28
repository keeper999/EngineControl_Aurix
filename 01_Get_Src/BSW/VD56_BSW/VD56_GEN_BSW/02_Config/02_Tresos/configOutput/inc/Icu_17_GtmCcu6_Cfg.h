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
**  FILENAME  : Icu_17_GtmCcu6_PBCfg.h                                        **
**                                                                            **
**  $CC VERSION : \main\30 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:25                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Icu configuration generated out of ECU configuration       **
**                 file  (Icu_17_GtmCcu6.bmd)                                 **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


#ifndef ICUCFG_H
#define ICUCFG_H




/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*Section to Generate Autosar Specific Version Information*/

#define ICU_17_GTMCCU6_AR_RELEASE_MAJOR_VERSION  (4U)
#define ICU_17_GTMCCU6_AR_RELEASE_MINOR_VERSION  (0U)
#define ICU_17_GTMCCU6_AR_RELEASE_REVISION_VERSION  (3U)

/*Section to Generate Vendor Specific Version Information*/
/* Vendor specific implementation version information */
#define ICU_17_GTMCCU6_SW_MAJOR_VERSION   (3U)
#define ICU_17_GTMCCU6_SW_MINOR_VERSION   (3U)
#define ICU_17_GTMCCU6_SW_PATCH_VERSION   (0U)




#define ICU_DEBUG_SUPPORT (STD_OFF)


/*
    Configuration : ICU_SAFETY_ENABLE
    Pre-processor switch to enable/disable the ICU driver safety features.
*/
#define ICU_SAFETY_ENABLE (STD_OFF)

#define ICU_INITCHECK_API (STD_OFF)

#define ICU_GETMODE_API (STD_OFF)





/* ICU026: General Configuration */
/*
Configuration: ICU_DEV_ERROR_DETECT
Adds/removes the Development Error Detection 
from the code 
- if STD_ON, Development error detection is enabled
- if STD_OFF, Development error detection is disabled
*/
/* ICU111: Development error detection  */
#define ICU_DEV_ERROR_DETECT           (STD_ON)

/*
Configuration: ICU_REPORT_WAKEUP_SOURCE
Preprocessor switch to enable/disable the wakeup source reporting
- if STD_ON, Reports wakeup to higher layer
- if STD_OFF, Reporting is switched off
*/
/* ICU055: Report Wakeup source to the higher layer */
#define ICU_REPORT_WAKEUP_SOURCE       (STD_OFF)

/*
Configuration: ICU_PB_FIXEDADDR
This parameter enables the user to switch STD_ON/STD_OFF 
the PostBuild Fixed Address Feature
- if STD_ON, PostBuild Fixed Address Feature is enabled
- if STD_OFF,PostBuild Fixed Address Feature is disabled
*/
#define ICU_PB_FIXEDADDR               (STD_OFF)

/*
Configuration: ICU_DE_INIT_API
Adds/removes Icu_DeInit API 
from the code 
- if STD_ON, Icu_DeInit is enabled
- if STD_OFF, Icu_DeInit is disabled
*/
/* ICU114: Configuration Icu_DeInit API*/
#define ICU_DE_INIT_API                (STD_OFF)

/*
Configuration: ICU_DISABLE_WAKEUP_API
Adds/removes Icu_DisableWakeup API 
from the code 
- if STD_ON, Icu_DisableWakeup is enabled
- if STD_OFF, Icu_DisableWakeup is disabled
*/
/* ICU114:Configuration Icu_DisableWakeup API */
#define ICU_DISABLE_WAKEUP_API         (STD_OFF)

/*
Configuration: ICU_ENABLE_WAKEUP_API
Adds/removes Icu_EnableWakeup API 
from the code 
- if STD_ON, Icu_EnableWakeup is enabled
- if STD_OFF, Icu_EnableWakeup is disabled
*/
/* ICU114:Configuration Icu_EnableWakeup API */
#define ICU_ENABLE_WAKEUP_API          (STD_OFF)

/*
Configuration: ICU_EDGE_COUNT_API
Adds/removes Edge Count Measurement APIs 
from the code 
- if STD_ON, Icu_EnableEdgeCount, Icu_DisableEdgeCount
         Icu_ResetEdgeCount, Icu_GetEdgeNumbers is enabled
- if STD_OFF, Icu_EnableEdgeCount, Icu_DisableEdgeCount
         Icu_ResetEdgeCount, Icu_GetEdgeNumbers is disabled
*/
/* ICU124:Configuration Icu_EdgeCount API */
#define ICU_EDGE_COUNT_API             (STD_OFF)

/*
Configuration: ICU_GET_DUTY_CYCLE_VALUES_API
Adds/removes Icu_GetDutyCycleValues API 
from the code 
- if STD_ON, Icu_GetDutyCycleValues is enabled
- if STD_OFF, Icu_GetDutyCycleValues is disabled
*/
/* ICU114:Configuration Icu_GetDutyCycleValues API */
#define ICU_GET_DUTY_CYCLE_VALUES_API  (STD_ON)

/*
Configuration: ICU_GET_INPUT_STATE_API
Adds/removes Icu_GetInputState API 
from the code 
- if STD_ON, Icu_GetInputState is enabled
- if STD_OFF, Icu_GetInputState is disabled
*/
/* ICU114:Configuration Icu_GetInputState API */
#define ICU_GET_INPUT_STATE_API        (STD_ON)

/*
Configuration: ICU_GET_TIME_ELAPSED_API
Adds/removes Icu_GetTimeElapsed API 
from the code 
- if STD_ON, Icu_GetTimeElapsed is enabled
- if STD_OFF, Icu_GetTimeElapsed is disabled
*/
/* ICU114:Configuration Icu_GetTimeElapsed API */
#define ICU_GET_TIME_ELAPSED_API       (STD_ON)

/*
Configuration: ICU_GET_VERSION_INFO_API
Adds/removes Icu_GetVersionInfo API 
from the code 
- if STD_ON, Icu_GetVersionInfo is enabled
- if STD_OFF, Icu_GetVersionInfo is disabled
*/
/* ICU114:Configuration Icu_GetVersionInfo API */
#define ICU_GET_VERSION_INFO_API       (STD_OFF)

/*
Configuration: ICU_SET_MODE_API
Adds/removes Icu_SetMode API 
from the code 
- if STD_ON, Icu_SetMode is enabled
- if STD_OFF, Icu_SetMode is disabled
*/
/* ICU114:Configuration Icu_SetMode API */
#define ICU_SET_MODE_API               (STD_ON)

/*
Configuration: ICU_TIMESTAMP_API
Adds/removes Edge Count Measurement APIs 
from the code 
- if STD_ON, Icu_StartTimestamp, Icu_StopTimestamp
         Icu_GetTimestampIndex is enabled
- if STD_OFF, Icu_StartTimestamp, Icu_StopTimestamp
         Icu_GetTimestampIndex is disabled
*/
/* ICU123: configuration of timestamp API */
#define ICU_TIMESTAMP_API              (STD_OFF)


/*
Configuration: ICU_SIGNAL_MEASUREMENT_API
Adds/removes Signal Measurement APIs 
from the code 
- if STD_ON, Icu_StartSignalMeasurement, Icu_StopSignalMeasurement
         Icu_GetTimeElapsed, Icu_GetDutyCycleValues is enabled
- if STD_OFF, Icu_StartSignalMeasurement, Icu_StopSignalMeasurement
         Icu_GetTimeElapsed, Icu_GetDutyCycleValues is disabled
*/
/* ICU123: configuration of timestamp API */
#define ICU_SIGNAL_MEASUREMENT_API              (STD_ON)



/*
Configuration: ICU_EDGE_DETECT_API
Adds/removes Signal Measurement APIs 
from the code 
- if STD_ON, Edge Detection functionality is enabled
- if STD_OFF, Edge Detection functionality is disabled
*/
/* ICU123: configuration of timestamp API */
#define ICU_EDGE_DETECT_API                     (STD_ON)


/*
Configuration: ICU_NO_OF_CCU6_MODULES
Number of CCU6 modules present in the device
*/
#define ICU_NO_OF_CCU6_MODULES       2

/*
Configuration: ICU_NO_OF_CCU6_CHANNELS
Number of CCU6 channels present in 1 CCU6 Kernal
*/
#define ICU_NO_OF_CCU6_CHANNELS       3


/*
Configuration: ICU_WAKEUP_FUNCTIONALITY_API
Adds/removes the service Icu_CheckWakeup() 
from the code 
- if ON, the service Icu_CheckWakeup() is enabled
- if OFF, the service Icu_CheckWakeup() is disabled
*/
/* ICU355_Conf: Adds / removes the service Icu_CheckWakeup() from the code */
#define ICU_WAKEUP_FUNCTIONALITY_API        (STD_OFF)
 

/*
Configuration: ICU_17_GTMCCU6_INSTANCE_ID
InstanceId of ICU module
*/
/* InstanceId of ICU module  */
#define ICU_17_GTMCCU6_INSTANCE_ID       ((uint8)0)


















/********************************************************************
LIST OF ALL CONFIGURED QM CHANNELS  
*********************************************************************/
#define ICU_MAX_EDGE_DETECT_QM_GTM_CHANNELS  (4U)
#define ICU_MAX_EDGE_DETECT_QM_CCU6_CHANNELS  (0U)
#define ICU_MAX_EDGE_DETECT_QM_ERU_CHANNELS  (0U)
 
#define ICU_MAX_SIGNAL_MEASURE_QM_GTM_CHANNELS  (18U)
#define ICU_MAX_SIGNAL_MEASURE_QM_CCU6_CHANNELS  (0U)

#define ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS   (18U)   

#define ICU_MAX_EDGE_COUNT_QM_CHANNELS (0U)
#define ICU_MAX_TIMESTAMP_QM_CHANNELS (0U)
            
#define ICU_MAX_QM_GTM_CHANNELS   (22U)
 
#define ICU_MAX_QM_CCU6_CHANNELS          (0U)

#define ICU_MAX_QM_ERU_CHANNELS          (0U)
    
#define ICU_MAX_QM_CHANNELS          (22U)

#define ICU_MAX_ASIL_GTM_CHANNELS      (0U)   
                      
#define ICU_MAX_ASIL_CCU6_CHANNELS     (0U)   


/***************************************************************************
TOTAL NUMBER OF CONFIGURED CHANNELS  : All channels are QM as safety is OFF
****************************************************************************/
#define ICU_MAX_CHANNELS    (22U)


/*
Configuration: ICU_ECUM_WAKEUP_USED (Vendor Specific)
Indication of using wakeup concept to higher layer 
- if STD_ON, atleast one wakeup capable channel is
         configured to call Ecum layer.
- if STD_OFF, Ecum wakeup is not used.
*/
#define ICU_ECUM_WAKEUP_USED                        (STD_OFF)





#ifndef IcuConf_IcuChannel_M_SEC_BRK_PED_SWITCH
#define IcuConf_IcuChannel_M_SEC_BRK_PED_SWITCH          ((Icu_17_GtmCcu6_ChannelType)0)
#endif

#ifndef IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_4
#define IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_4          ((Icu_17_GtmCcu6_ChannelType)1)
#endif

#ifndef IcuConf_IcuChannel_M_MANUAL_GEARBOX_NEUTRAL_POS
#define IcuConf_IcuChannel_M_MANUAL_GEARBOX_NEUTRAL_POS          ((Icu_17_GtmCcu6_ChannelType)2)
#endif

#ifndef IcuConf_IcuChannel_M_LOW_PRES_FUEL_PUMP_VAR_INPUT
#define IcuConf_IcuChannel_M_LOW_PRES_FUEL_PUMP_VAR_INPUT          ((Icu_17_GtmCcu6_ChannelType)3)
#endif

#ifndef IcuConf_IcuChannel_M_STARTER_CMD_DIAG_INPUT
#define IcuConf_IcuChannel_M_STARTER_CMD_DIAG_INPUT          ((Icu_17_GtmCcu6_ChannelType)4)
#endif

#ifndef IcuConf_IcuChannel_M_UEGO_PWMEN
#define IcuConf_IcuChannel_M_UEGO_PWMEN          ((Icu_17_GtmCcu6_ChannelType)5)
#endif

#ifndef IcuConf_IcuChannel_M_FLEXRAY_RXEN
#define IcuConf_IcuChannel_M_FLEXRAY_RXEN          ((Icu_17_GtmCcu6_ChannelType)6)
#endif

#ifndef IcuConf_IcuChannel_M_CLUTCH_PED_POS_OR_STARTLOCK
#define IcuConf_IcuChannel_M_CLUTCH_PED_POS_OR_STARTLOCK          ((Icu_17_GtmCcu6_ChannelType)7)
#endif

#ifndef IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_3
#define IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_3          ((Icu_17_GtmCcu6_ChannelType)8)
#endif

#ifndef IcuConf_IcuChannel_M_SPARE_OUT_LSD_1_DIAG
#define IcuConf_IcuChannel_M_SPARE_OUT_LSD_1_DIAG          ((Icu_17_GtmCcu6_ChannelType)9)
#endif

#ifndef IcuConf_IcuChannel_M_UEGO_IRQ
#define IcuConf_IcuChannel_M_UEGO_IRQ          ((Icu_17_GtmCcu6_ChannelType)10)
#endif

#ifndef IcuConf_IcuChannel_M_INTK_VVT_DIAG
#define IcuConf_IcuChannel_M_INTK_VVT_DIAG          ((Icu_17_GtmCcu6_ChannelType)11)
#endif

#ifndef IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_5
#define IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_5          ((Icu_17_GtmCcu6_ChannelType)12)
#endif

#ifndef IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_1
#define IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_1          ((Icu_17_GtmCcu6_ChannelType)13)
#endif

#ifndef IcuConf_IcuChannel_M_VEHICLE_SPD_INFO
#define IcuConf_IcuChannel_M_VEHICLE_SPD_INFO          ((Icu_17_GtmCcu6_ChannelType)14)
#endif

#ifndef IcuConf_IcuChannel_M_FAN1_DIAG_INPUT
#define IcuConf_IcuChannel_M_FAN1_DIAG_INPUT          ((Icu_17_GtmCcu6_ChannelType)15)
#endif

#ifndef IcuConf_IcuChannel_M_ETHANOL_RATE_FLEXFUEL
#define IcuConf_IcuChannel_M_ETHANOL_RATE_FLEXFUEL          ((Icu_17_GtmCcu6_ChannelType)16)
#endif

#ifndef IcuConf_IcuChannel_M_FLEXRAY_ERR
#define IcuConf_IcuChannel_M_FLEXRAY_ERR          ((Icu_17_GtmCcu6_ChannelType)17)
#endif

#ifndef IcuConf_IcuChannel_M_TURBO_ENG_COOL_WAT_PUMP_DIAG
#define IcuConf_IcuChannel_M_TURBO_ENG_COOL_WAT_PUMP_DIAG          ((Icu_17_GtmCcu6_ChannelType)18)
#endif

#ifndef IcuConf_IcuChannel_M_CTRL_THERMOSTAT_VALVE_DIAG
#define IcuConf_IcuChannel_M_CTRL_THERMOSTAT_VALVE_DIAG          ((Icu_17_GtmCcu6_ChannelType)19)
#endif

#ifndef IcuConf_IcuChannel_M_EXH_VVT_DIAG
#define IcuConf_IcuChannel_M_EXH_VVT_DIAG          ((Icu_17_GtmCcu6_ChannelType)20)
#endif

#ifndef IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_2
#define IcuConf_IcuChannel_M_INPUT_DIGITAL_SPARE_2          ((Icu_17_GtmCcu6_ChannelType)21)
#endif







/*
Derived parameters
Vendor specific configuration switches
Format
ICU_RES_MODE_USED
RES : TIM, ERU
MODE: SIGMEAS, SIGEDGE, EDGECNT, TIMSTMP
*/
/*
Configuration:ICU_TIM_SIGMEAS_USED (Vendor Specific)
DCM resource used in Signal measurement:
STD_ON: TIM cells are used in Signal measurement mode.
STD_OFF: TIM cells are not used in Signal measurement mode.
*/


#define ICU_ASIL_TIM_SIGMEAS_USED     (STD_OFF)
#define ICU_QM_TIM_SIGMEAS_USED     (STD_ON)
#if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON) || (ICU_QM_TIM_SIGMEAS_USED == STD_ON)
#define ICU_TIM_SIGMEAS_USED    (STD_ON)
#else
#define ICU_TIM_SIGMEAS_USED    (STD_OFF)
#endif

#define ICU_ASIL_TIM_SIGEDGE_USED     (STD_OFF) 
#define ICU_QM_TIM_SIGEDGE_USED     (STD_ON)
#if (ICU_ASIL_TIM_SIGEDGE_USED == STD_ON) || (ICU_QM_TIM_SIGEDGE_USED == STD_ON)
#define ICU_TIM_SIGEDGE_USED     (STD_ON)
#else
#define ICU_TIM_SIGEDGE_USED    (STD_OFF)
#endif

#define ICU_ASIL_TIM_EDGECNT_USED     (STD_OFF)  
#define ICU_QM_TIM_EDGECNT_USED     (STD_OFF)   
#if (ICU_ASIL_TIM_EDGECNT_USED == STD_ON) || (ICU_QM_TIM_EDGECNT_USED == STD_ON)
#define ICU_TIM_EDGECNT_USED     (STD_ON) 
#else
#define ICU_TIM_EDGECNT_USED     (STD_OFF) 
#endif

#define ICU_ASIL_TIM_TIMESTAMP_USED     (STD_OFF)
#define ICU_QM_TIM_TIMESTAMP_USED    (STD_OFF)
#if (ICU_ASIL_TIM_TIMESTAMP_USED == STD_ON) || (ICU_QM_TIM_TIMESTAMP_USED == STD_ON)
#define ICU_TIM_TIMSTMP_USED     (STD_ON)
#else
#define ICU_TIM_TIMSTMP_USED     (STD_OFF)
#endif
 
#define ICU_ASIL_CCU6_SIGMEAS_USED     (STD_OFF)
#define ICU_QM_CCU6_SIGMEAS_USED     (STD_OFF)
#if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON) || (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
#define ICU_CCU6_SIGMEAS_USED     (STD_ON)
#else
#define ICU_CCU6_SIGMEAS_USED     (STD_OFF)
#endif

#define ICU_ASIL_CCU6_SIGEDGE_USED     (STD_OFF)
#define ICU_QM_CCU6_SIGEDGE_USED     (STD_OFF)
#if (ICU_ASIL_CCU6_SIGEDGE_USED == STD_ON) || (ICU_QM_CCU6_SIGEDGE_USED == STD_ON)
#define ICU_CCU6_SIGEDGE_USED     (STD_ON)
#else
#define ICU_CCU6_SIGEDGE_USED     (STD_OFF)
#endif


/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU resource used in Signal edge detection or not.
STD_ON: ERUs are used in Signal edge detection mode.
STD_OFF: ERUs are not used in Signal edge detection mode.
*/
#define ICU_ERU_SIGEDGE_USED     (STD_OFF)
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU0 resource used in Signal edge detection or not.
STD_ON: ERU0 is used in Signal edge detection mode.
STD_OFF: ERU0 is not used in Signal edge detection mode.
*/
#define ICU_ERU0_USED (STD_OFF)
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU1 resource used in Signal edge detection or not.
STD_ON: ERU1 is used in Signal edge detection mode.
STD_OFF: ERU1 is not used in Signal edge detection mode.
*/
#define ICU_ERU1_USED (STD_OFF)
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU2 resource used in Signal edge detection or not.
STD_ON: ERU2 is used in Signal edge detection mode.
STD_OFF: ERU2 is not used in Signal edge detection mode.
*/
#define ICU_ERU2_USED (STD_OFF)
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU3 resource used in Signal edge detection or not.
STD_ON: ERU3 is used in Signal edge detection mode.
STD_OFF: ERU3 is not used in Signal edge detection mode.
*/
#define ICU_ERU3_USED (STD_OFF)
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU4 resource used in Signal edge detection or not.
STD_ON: ERU4 is used in Signal edge detection mode.
STD_OFF: ERU4 is not used in Signal edge detection mode.
*/
#define ICU_ERU4_USED (STD_OFF)
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU5 resource used in Signal edge detection or not.
STD_ON: ERU5 is used in Signal edge detection mode.
STD_OFF: ERU5 is not used in Signal edge detection mode.
*/
#define ICU_ERU5_USED (STD_OFF)
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU6 resource used in Signal edge detection or not.
STD_ON: ERU6 is used in Signal edge detection mode.
STD_OFF: ERU6 is not used in Signal edge detection mode.
*/
#define ICU_ERU6_USED (STD_OFF)
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU7 resource used in Signal edge detection or not.
STD_ON: ERU7 is used in Signal edge detection mode.
STD_OFF: ERU7 is not used in Signal edge detection mode.
*/
#define ICU_ERU7_USED (STD_OFF)


/*******************************************************************************
**                      Global constant declarations                          **
*******************************************************************************/


#endif


