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
**  $FILENAME   : Icu_17_GtmCcu6.h $                                         **
**                                                                           **
**  $CC VERSION : \main\61 $                                                 **
**                                                                           **
**  $DATE       : 2013-10-16 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                 - functionality of ICU driver.                            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                     **
**                                                                           **
******************************************************************************/
/*  TRACEABILITY :[cover parentID=DS_AS_ICU038,
                   DS_AS40X_ICU001_PI,DS_AS_ICU275,
                   DS_AS_ICU276,DS_AS_ICU118,DS_AS_ICU001,
                   DS_AS_ICU272,DS_AS_ICU264,DS_AS_ICU265,DS_AS_ICU266,
                   DS_AS_ICU267,DS_AS_ICU269,DS_AS_ICU270,DS_AS_ICU268,
                   DS_AS_ICU271,DS_AS40X_ICU355,DS_AS_ICU357,
                   DS_AS_ICU279,DS_AS_ICU289,
                   DS_AS_ICU294,DS_AS40X_ICU295,DS_AS_ICU296,
                   DS_AS40X_ICU351_ICU352]                
                   [/cover]                                                  */ 
#ifndef ICU_17_GTMCCU6_H
#define ICU_17_GTMCCU6_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* Global functions like Set/Reset END INIT protection bit, 
  Enable/Disable interrupts, Atomic write function */
#include "Mcal.h"

/*Icu Configuration File*/
#include "Icu_17_GtmCcu6_Cfg.h"

#if ( (ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_TIM_SIGEDGE_USED == STD_ON) || \
      (ICU_TIM_EDGECNT_USED == STD_ON) || (ICU_TIM_TIMSTMP_USED == STD_ON))
/* Gtm header file, this includes Gtm configuration file also */
#include "Gtm.h"
#endif
/* Check for Report wakeup Source  */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#if (ICU_ECUM_WAKEUP_USED == STD_ON)
/* Include Ecu State Manager header file */
#include "EcuM_Cbk.h"
#endif
#endif
#if (ICU_DEV_ERROR_DETECT == STD_ON)
/* Import of DET functionality. This is needed for GetVersionInfo Macro */
#include "Det.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


#define ICU_QM_SIGNAL (0U)
#define ICU_ASIL_SIGNAL (1U)
/*
  Published parameters
*/
/* ICU Vendor ID - Vendor ID of the dedicated implementation of this
module according to the AUTOSAR vendor list */
#define ICU_17_GTMCCU6_VENDOR_ID     ((uint16)17)
/*ICU Module ID - Module ID of this module from Module List */
#define ICU_17_GTMCCU6_MODULE_ID     ((uint16)122)


#if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
/*
    Development error values
    ICU118: Development error values are of type uint8
    ICU001: Development error list
*/
/* API service called with wrong parameter */
#define ICU_E_PARAM_CONFIG         ((uint8)0x0A) 
/* API service used with an invalid channel Identifier  */
#define ICU_E_PARAM_CHANNEL        ((uint8)0x0B)
/* API service used with an invalid or not feasible Activation */
#define ICU_E_PARAM_ACTIVATION     ((uint8)0x0C)
/* API Service used with an invalid pointer */ 
#define ICU_E_PARAM_BUFFER_PTR     ((uint8)0x0D)
/* API Service used with an invalid size (size =0) */ 
#define ICU_E_PARAM_BUFFER_SIZE    ((uint8)0x0E)
/* API Service Icu_17_GtmCcu6_SetMode used with an invalid mode value */
#define ICU_E_PARAM_MODE           ((uint8)0x0F)
/* API Service Called to measure when the required service was not started */
#define ICU_E_NOT_STARTED          ((uint8)0x15)
/* API Service Icu_17_GtmCcu6_SetMode is called when an running operation is
 ongoing */
#define ICU_E_BUSY_OPERATION       ((uint8)0x16)   
/* API service used without module initialization */
#define ICU_E_UNINIT               ((uint8)0x14)
/* Init function: Icu_17_GtmCcu6_Init called while driver already initialized */
#define ICU_E_ALREADY_INITIALIZED  ((uint8)0x17)
/* Init function: Icu_17_GtmCcu6_StartTimeStamp called with parameter 
NotifyInterval is invalid (e.g.?? NotifyInterval < 1) */
#define ICU_E_PARAM_NOTIFY_INTERVAL ((uint8)0x18)
/* Init function: Icu_17_GtmCcu6_GetVersionInfo called with a parameter 
NULL_PTR */
#define ICU_E_PARAM_VINFO          ((uint8)0x19)


#if (ICU_SAFETY_ENABLE  == STD_ON)
/* Function 'Gpt_SetMode' called to SLEEP without IRQ enabled for any
wakeup channel. This is added as Safety measure before putting GPT to 
SLEEP */
#define ICU_E_NO_WAKEUP           ((uint8)0x20) 

#endif




/* API Service ID's */
/* API Service ID for Icu_17_GtmCcu6_Init() */
#define ICU_SID_INIT                              ((uint8)0x00)
/* API Service ID for Icu_17_GtmCcu6_DeInit() */
#define ICU_SID_DEINIT                            ((uint8)0x01)
/* API Service ID for Icu_17_GtmCcu6_SetMode() */
#define ICU_SID_SETMODE                           ((uint8)0x02)
/* API Service ID for Icu_17_GtmCcu6_DisableWakeup() */
#define ICU_SID_DISABLEWAKEUP                     ((uint8)0x03)
/* API Service ID for Icu_17_GtmCcu6_EnableWakeup() */
#define ICU_SID_ENABLEWAKEUP                      ((uint8)0x04)
/* API Service ID for Icu_17_GtmCcu6_SetActivationCondition() */
#define ICU_SID_SETACTIVATIONCONDITION            ((uint8)0x05)
/* API Service ID for Icu_17_GtmCcu6_DisableNotification() */
#define ICU_SID_DISABLENOTIFICATION               ((uint8)0x06)
/* API Service ID for Icu_17_GtmCcu6_EnableNotification() */
#define ICU_SID_ENABLENOTIFICATION                ((uint8)0x07)
/* API Service ID for Icu_17_GtmCcu6_GetInputState() */
#define ICU_SID_GETINPUTSTATE                     ((uint8)0x08)
/* API Service ID for Icu_17_GtmCcu6_StartTimestamp() */
#define ICU_SID_STARTTIMESTAMP                    ((uint8)0x09)  
/* API Service ID for Icu_17_GtmCcu6_StopTimestamp() */
#define ICU_SID_STOPTIMESTAMP                     ((uint8)0x0A)
/* API Service ID for Icu_17_GtmCcu6_GetTimestampIndex() */
#define ICU_SID_GETTIMESTAMPINDEX                 ((uint8)0x0B)
/* API Service ID for Icu_17_GtmCcu6_ResetEdgeCount() */
#define ICU_SID_RESETEDGECOUNT                    ((uint8)0x0C)
/* API Service ID for Icu_17_GtmCcu6_EnableEdgeCount() */
#define ICU_SID_ENABLEEDGECOUNT                   ((uint8)0x0D)
/* API Service ID for Icu_17_GtmCcu6_DisableEdgeCount() */
#define ICU_SID_DISABLEEDGECOUNT                  ((uint8)0x0E)
/* API Service ID for Icu_17_GtmCcu6_GetEdgeNumbers() */
#define ICU_SID_GETEDGENUMBERS                    ((uint8)0x0F)
/* API Service ID for Icu_17_GtmCcu6_GetTimeElapsed() */
#define ICU_SID_GETTIMEELAPSED                    ((uint8)0x10)
/* API Service ID for Icu_17_GtmCcu6_GetDutyCycleValues() */
#define ICU_SID_GETDUTYCYCLEVALUES                ((uint8)0x11)
/* API Service ID for Icu_17_GtmCcu6_GetVersionInfo */
#define ICU_SID_GETVERSIONINFO                    ((uint8)0x12)
/* API Service ID for Icu_17_GtmCcu6_StartSignalMeasurement */
#define ICU_SID_STARTSIGNALMEASUREMENT            ((uint8)0x13)
/* API Service ID for Icu_17_GtmCcu6_StopSignalMeasurement */
#define ICU_SID_STOPSIGNALMEASUREMENT             ((uint8)0x14)
/* API Service ID for Icu_17_GtmCcu6_CheckWakeup */
#define ICU_SID_CHECKWAKEUP                       ((uint8)0x15)
/* API Service ID for Icu_17_GtmCcu6_EnableEdgeDetection */
#define ICU_SID_ENABLEEDGEDETECTION               ((uint8)0x16)
/* API Service ID for Icu_17_GtmCcu6_DisableEdgeDetection */
#define ICU_SID_DISABLEEDGEDETECTION              ((uint8)0x17)
/* API Service ID for Gtm/Ccu6/Eru Isr*/
#define ICU_SID_ISR                  ((uint8)0x18)

#endif

/* Users can make use of these #defines while configuring ICU driver */

/* Normal operation, all used interrupts are enabled according to the 
   notification requests */
#define ICU_MODE_NORMAL                  ((Icu_17_GtmCcu6_ModeType)(0))
/* Operation for reduced power operation mode. In Wake-up mode only those 
   notifications are available which are configured as wake-up capable */
#define ICU_MODE_SLEEP                   ((Icu_17_GtmCcu6_ModeType)(1))

/* No activation edge has been detected since the last call of 
   Icu_17_GtmCcu6_GetInputState() or Icu_17_GtmCcu6_Init().*/
#define ICU_IDLE                         ((Icu_17_GtmCcu6_InputStateType)(0))
/* An activation edge has been detected by an ICU*/      
#define ICU_ACTIVE                       ((Icu_17_GtmCcu6_InputStateType)(1))

/* Activation of configuration will be started when a rising edge occurs on the
   ICU input signal.*/
#define ICU_RISING_EDGE                  ((Icu_17_GtmCcu6_ActivationType)(1))

/* Activation of edges  will be started when a falling edge occurs on the 
   ICU input signal */
#define ICU_FALLING_EDGE                 ((Icu_17_GtmCcu6_ActivationType)(0))

/* Activation of configuration on both  rising edge or falling edge occur on 
   the ICU input signal (any kind of edges) */
#define ICU_BOTH_EDGES                   ((Icu_17_GtmCcu6_ActivationType)(2))
#define ICU_NO_EDGE                      ((Icu_17_GtmCcu6_ActivationType)(3))


/* #define for wakeup capable or not */
#define ICU_WAKEUPCAPABLE                ((Icu_17_GtmCcu6_WakeupCapableType)1)
#define ICU_NOT_WAKEUPCAPABLE            ((Icu_17_GtmCcu6_WakeupCapableType)0)

/* Measurement Mode type */
#define ICU_MODE_SIGNAL_EDGE_DETECT      ((Icu_17_GtmCcu6_MeasurementModeType)0)
#define ICU_MODE_SIGNAL_MEASUREMENT      ((Icu_17_GtmCcu6_MeasurementModeType)1)
#define ICU_MODE_TIMESTAMP               ((Icu_17_GtmCcu6_MeasurementModeType)2)
#define ICU_MODE_EDGE_COUNTER            ((Icu_17_GtmCcu6_MeasurementModeType)3)

/*SignalMeasurementPropertyType */

#define ICU_PERIOD_TIME_LOW_DUTY         \
                  ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)1)
#define ICU_ACTIVE_TIME_LOW_DUTY         \
                   ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)2)
#define ICU_HIGH_TIME_GTM                \
                   ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)16)
#define ICU_PERIOD_TIME_HIGH_DUTY        \
                   ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)17)
#define ICU_ACTIVE_TIME_HIGH_DUTY        \
                   ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)18)

#define ICU_LOW_TIME                     \
                   ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)0)
#define ICU_PERIOD_TIME                  \
                   ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)1)

#define ICU_DUTY_CYCLE                   \
                   ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)2)

#define ICU_HIGH_TIME                    \
                   ((Icu_17_GtmCcu6_SignalMeasurementPropertyType)3)

/*TimeStamp Types */
#define ICU_LINEAR_BUFFER                \
                  ((Icu_17_GtmCcu6_TimestampBufferType)0)
#define ICU_CIRCULAR_BUFFER              \
                  ((Icu_17_GtmCcu6_TimestampBufferType)1)

/* If Filter Option not chosen */
#define ICU_FPC_UNUSED           (0x7U)

#define ICU_WAKEUP_NO_CALL       (0U)
/* Define if wakeup call is configured for EcuM module */
#define ICU_WAKEUP_CALL_ECUM     (1U)

/* ICU options chosen */
#define ICU_GTM_OPTION           (0UL)
#define ICU_ERU_OPTION           (1UL)
#define ICU_CCU_OPTION           (2UL)

/* CCU6 Connections */
#define ICU_CCU6_CCINA  (0U)
#define ICU_CCU6_CCINB  (1U)
#define ICU_CCU6_CCINC  (2U)
#define ICU_CCU6_CCIND  (3U)


/* if ICU_PB_FIXEDADDR not defined ,by default make it STD_OFF */
#ifndef ICU_PB_FIXEDADDR
#define ICU_PB_FIXEDADDR         (STD_OFF)
#endif

/*
ICU_CCU6_USED  (Vendor Specific)
Indicates whether CCU6 is used in any of the configurations in ICU.
STD_ON: CCU6 is used in ICU.
STD_OFF: CCU6 not used in ICU.
*/
#if ( (ICU_CCU6_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON))
#define ICU_CCU6_USED         (STD_ON)
#else
#define ICU_CCU6_USED         (STD_OFF)
#endif

/* ICU_CCU6X_UNUSED (Vendor Specific)
Used to signify if the corresponding CCU module has to be initialized by
ICU or not */
#define ICU_CCU6X_UNUSED ((uint8)((uint8)1U << 7))

#define ICU_ACTIVE_TIME   (ICU_DUTY_CYCLE)
  
#define ICU_GTM_INVALID_NUMBER (0xFFU)

/* This structure is required to store the physical channel mapping from 
configuration.
Also the indexed mapping is stored here for optimization on RAM variable
usage */
typedef struct 
{
  /* The configured channel are divided into three groups ASIL - GTM, 
     ASIL - CCU6 and QM. The PhsyicalChannelMap maps the configured
   channel order to either of the three sets */
   uint8 PhysicalChannelMap;
  /* channel indexing for optimized RAM usage */
     uint8 ChannelIndexMap;
  
}Icu_17_GtmCcu6_MapType;

/* Type of Global Channel Number */
typedef uint8 Gtm_GlobalChannelNumberType;

#define GTM_CHAN_ID_MOD_NO_POS (2)

/* MISRA Rule Violation 19.7:Function-like macro defined.this can not be avoided
*/
/*
Icu_lGetEdge
Get the first edge for LowTime / highTime measurement
Input Parameters:
Kind: High Time Or Low Time
*/ 

/*******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU212,DS_AS_ICU050_21_ICU346,
   DS_AS_ICU243_21_ICU112_21_ICU048_21,DS_AS_ICU356,DS_AS_ICU182,
   DS_AS_ICU183,DS_NAS_PR734_21,DS_AS_ICU094_ICU347]

** Syntax :          Icu_17_GtmCcu6_GetVersionInfo (VersionInfoPtr)           **
**                                                                            **
** [/cover]                                                                   **
** Service ID:       0x12                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out):  versioninfo : Pointer to hold the version values        **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will return the version infos of ICU driver  **
*******************************************************************************/
#if ((ICU_GET_VERSION_INFO_API == STD_ON) && (ICU_DEV_ERROR_DETECT == STD_ON))
#define Icu_17_GtmCcu6_GetVersionInfo(VersionInfoPtr)                          \
{                                                                              \
  /* Check if the passed parameter is a NULL_PTR.  If so, escalate... */       \
  if(VersionInfoPtr == NULL_PTR)                                               \
  {                                                                            \
    Det_ReportError(                                                           \
                     ICU_17_GTMCCU6_MODULE_ID,                                 \
                     ICU_17_GTMCCU6_INSTANCE_ID,                               \
                     ICU_SID_GETVERSIONINFO,                                   \
                     ICU_E_PARAM_VINFO                                         \
                   );/* End of report to  DET */                               \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    /* (pointer VersionInfoPtr is not checked for NULL pointer) */             \
    /* Get ICU Vendor ID */                                                    \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID =                       \
                            ICU_17_GTMCCU6_VENDOR_ID;                          \
    /* Get ICU Module ID */                                                    \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID =                       \
                            ICU_17_GTMCCU6_MODULE_ID;                          \
    /* Get ICU module Software major version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                       (uint8)ICU_17_GTMCCU6_SW_MAJOR_VERSION; \
    /* Get ICU module Software minor version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                       (uint8)ICU_17_GTMCCU6_SW_MINOR_VERSION; \
    /* Get ICU module Software patch version */                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                       (uint8)ICU_17_GTMCCU6_SW_PATCH_VERSION; \
  }                                                                            \
}/* end of Icu_17_GtmCcu6_GetVersionInfo() */                                 
#elif ((ICU_GET_VERSION_INFO_API == STD_ON) &&(ICU_DEV_ERROR_DETECT == STD_OFF))
#define Icu_17_GtmCcu6_GetVersionInfo(VersionInfoPtr)                          \
{                                                                              \
  /* (pointer VersionInfoPtr is not checked for NULL pointer) */               \
  /* Get ICU Vendor ID */                                                      \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID =                         \
                                                      ICU_17_GTMCCU6_VENDOR_ID;\
  /* Get ICU Module ID */                                                      \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID =                         \
                                                      ICU_17_GTMCCU6_MODULE_ID;\
  /* Get ICU module Software major version */                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =                 \
                                       (uint8)ICU_17_GTMCCU6_SW_MAJOR_VERSION; \
  /* Get ICU module Software minor version */                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =                 \
                                       (uint8)ICU_17_GTMCCU6_SW_MINOR_VERSION; \
  /* Get ICU module Software patch version */                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =                 \
                                       (uint8)ICU_17_GTMCCU6_SW_PATCH_VERSION; \
}/* end of Icu_17_GtmCcu6_GetVersionInfo() */                                 
#else
#define Icu_17_GtmCcu6_GetVersionInfo(VersionInfoPtr)                          \
                               ERROR_Icu_17_GtmCcu6_GetVersionInfo_NOT_SELECTED
#endif

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* The following type informs the type of measurement mode to be used */
/* 
   The following values are possible 
   ICU_MODE_SIGNAL_EDGE_DETECT,
   ICU_MODE_SIGNAL_MEASUREMENT, 
   ICU_MODE_TIMESTAMP
   ICU_MODE_EDGE_COUNTER
*/

/* [cover parentID=DS_AS_ICU294,DS_NAS_PR643_3] */ 
typedef uint8 Icu_17_GtmCcu6_MeasurementModeType;

typedef uint8 Icu_17_GlobalChannelNumberType;
/* [/cover]  */

/* The following modes are possible 
   if MeasurementModeType is ICU_MODE_SIGNAL_MEASUREMENT 
   ICU_LOW_TIME
   ICU_HIGH_TIMER
   ICU_PERIODTIME
   ICU_ACTIVE_TIME/ICU_DUTY_CYCLE
*/
/* [cover parentID=DS_NAS_PR643_4] */
typedef uint8 Icu_17_GtmCcu6_SignalMeasurementPropertyType;
/* [/cover] */
/* 
 The following modes are possible 
 if MeasurementModeType is ICU_MODE_TIMESTAMP 
 ICU_LINEAR_BUFFER, 
 ICU_CIRCULAR_BUFFER 
*/
/* [cover parentID=DS_AS_ICU296,DS_NAS_PR643_5] */
typedef uint8 Icu_17_GtmCcu6_TimestampBufferType;
/* [/cover] */

/*
  The following type will be used in Icu_17_GtmCcu6_SetMode API.
*/
/* [cover parentID=DS_AS_ICU258_ICU277,DS_NAS_PR643_6] */
typedef uint8 Icu_17_GtmCcu6_ModeType;  
/* [/cover]  */

/* Input state of an ICU channel.  */
/* [cover parentID=DS_AS_ICU279,DS_NAS_PR643_7] */
typedef uint8 Icu_17_GtmCcu6_InputStateType;
/* [/cover] */
/* Numeric identifier of a ICU channel */
/* [cover parentID=DS_AS_ICU278] */
typedef uint8 Icu_17_GtmCcu6_ChannelType;  
/* [/cover] */
/* [cover parentID=DS_NAS_PR643_2] */
/* The following type informs whether the channel is wakeup capable or not*/
typedef uint8 Icu_17_GtmCcu6_WakeupCapableType;
/* [/cover]  */
/* Activations to be used for all kinds of measurement */
/* ICU_FALLING_EDGE, ICU_RISING_EDGE, ICU_BOTH_EDGES are the possible values*/
/* [cover parentID=DS_AS_ICU289,DS_NAS_PR643_1] */
typedef uint8  Icu_17_GtmCcu6_ActivationType;
/* [/cover]  */
/*Icu_17_GtmCcu6_ValueType is used for the widest timer */
/* [cover parentID=DS_AS_ICU290] */
typedef uint32 Icu_17_GtmCcu6_ValueType;
/* [/cover] */
/*
 Icu_Index type is used in Timestamp Measurement . A maximum of 16 bits
 could be used here, as the Buffer size cannot go beyond 65535
*/
/* [cover parentID=DS_AS_ICU292] */
typedef uint16 Icu_17_GtmCcu6_IndexType;
/* [/cover] */
/* Icu_EdgeNumbertype is used in Edge Count API's.
   Value of this type shall be returned to the caller on \
   Icu_17_GtmCcu6_GetEdgeNumbers
*/
/* [cover parentID=DS_AS_ICU293] */
typedef uint32 Icu_17_GtmCcu6_EdgeNumberType;
/* [/cover] */
/* To provide Notification the following type will be used */
typedef void (*Icu_17_GtmCcu6_NotifiPtrType)(void);

typedef uint8 Icu_17_GtmCcu6_ClockType;
/* ICU039: The definition for each Channel  */
/*ICU027: container for channel configuration */
/* The following struct type is channel dependent configuration */
typedef struct Icu_ChannelConfig
{
 
  /* ICU018: The callback notifications shall be configurable as function 
     pointers within the initialization data structure */
  /* The following parameter is a function pointer to provide notification */
  /* This should have a valid function and they make sense for the following 
     modes ICU_MODE_SIGNAL_EDGE_DETECT and ICU_MODE_TIMESTAMP
      The functions will be called from ISR after the following events
      ICU_MODE_SIGNAL_EDGE_DETECT -> after Icu_EnableNotification
      ICU_MODE_TIMESTAMP         -> enabled by Icu_EnableNotification and
      Icu_StartTimeStamp with NotifyInterval more than 0.
  */
  /* [cover parentID=DS_AS_ICU018] */
  Icu_17_GtmCcu6_NotifiPtrType NotificationPointer;
  /* [/cover]   */
  struct
  {
    /* Measurement Mode of the channel */
    unsigned_int      MeasurementMode : 2;
    /* Default start edge, ICU_RISING_EDGE,ICU_FALLING_EDGE and 
     ICU_BOTH_EDGES*/
    unsigned_int      DefaultStartEdge: 2;
    /* Measurement Property for time stamp capture and signal measurement */
    unsigned_int      MeasurementProperty: 2;
    /* The following parameter informs whether the channel is 
      wakeup capable or not */
    unsigned_int      WakeupCapability: 2;
    /* resource number */
    unsigned_int      AssignedHwUnitNumber: 8;
    /*
    * ICU038: MCU dependent properties for used HW units 
      Icu Assigned Hw Unit for the measurement
      0 -> ICU_GTM_OPTION
      1 -> ICU_ERU_OPTION
      2 -> ICU_CCU_OPTION
    */
    unsigned_int      AssignedHwUnit: 2;
    /* CCU6 Port connections */   
    unsigned_int      Ccu6Connections: 2; 
    /* ASIL or QM signal */
    unsigned_int SignalType: 1;
    /* reserved and padded to 32 bits */
    unsigned_int      Reserved: 11;
    #if (ICU_SAFETY_ENABLE == STD_ON)  
    /* Buffer marker for time stamp capture and signal measurement */   
    uint32  BufferMarker; 
    #endif
    /* Filtering time for rising edge */   
    uint16 TimChFilterTimeForRisingEdge;
    /* Filtering time for falling edge */   
    uint16 TimChFilterTimeForFallingEdge;
    /* Filtering time for TIM interrupt mode */   
    uint16 TimInterruptMode;
    /*Channel Clock Select */
    Icu_17_GtmCcu6_ClockType TimChannelClockSelect;  
  }IcuProperties;  
}Icu_17_GtmCcu6_ChannelConfigType;




#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
/*
  Wakeup Capable Channels
*/
/* ICU126: container for wakeup channels */
typedef struct 
{
  /* The following parameter will be used to provide the wakeup reason value.
    The type EcuM_WakeupSourceType should have been declared in Ecum.h      */
  EcuM_WakeupSourceType ChannelWakeupInfo;
}Icu_ChannelWakeupType; 
#endif

/*ICU038: ConfigType for initialization */
/* [cover parentID=DS_AS_ICU280_ICU039] */
typedef struct Icu_17_GtmCcu6_ConfigType
{
  #if (ICU_SAFETY_ENABLE == STD_ON)
  uint32  Marker;
  #endif
  /* Pointer to Channel Configuration structure */
  const Icu_17_GtmCcu6_ChannelConfigType *ChannelConfigPtr;
  /* Pointer to Mapping of configuration channel numbers
    to used numbers based on safety / QM usage and indexing
  for RAM optimization */
  const Icu_17_GtmCcu6_MapType *MappingIndexPtr;
  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  /* Pointer to channel wakeup information */
  const Icu_ChannelWakeupType *WakeupPtr;
  #endif
  #if (ICU_ERU_SIGEDGE_USED == STD_ON)
  /* Interrupt map between ERU resources and ICU channels. */
  uint8              EruChannelMap[8];
  #endif
  #if (ICU_CCU6_USED == STD_ON)
  uint8 T12Parameters[ICU_NO_OF_CCU6_MODULES];
  #endif /* #if (ICU_CCU6_USED == STD_ON) */
  /* Array of 4 elements, each element is configured with 
  the number of QM channels configured for each measurement mode.*/
  uint8              MaxQmChannels[4];
  #if (ICU_SAFETY_ENABLE == STD_ON)
  /* Array of 4 elements, each element is configured with 
  the number of GTM ASIL channels configured for each measurement mode.*/  
  uint8            MaxAsilGtmChannels[4];
  /* Array of 4 elements, each element is configured with 
  the number of CCU6 ASIL channels configured for each measurement mode.*/   
  uint8            MaxAsilCcu6Channels[4];  
  #endif
  
}Icu_17_GtmCcu6_ConfigType;





/* [/cover] */
/*
  The following structure is used in Icu_17_GtmCcu6_GetDutyCycle_Values API.
*/
/* [cover parentID=DS_AS_ICU291] */
typedef struct
{
  /* To store ActiveTime for GetDutyCycles API.*/
  Icu_17_GtmCcu6_ValueType  ActiveTime;
  /* To store PeriodTime for GetDutyCycles API.*/
  Icu_17_GtmCcu6_ValueType  PeriodTime;
  /* Buffer marker value */ 
  Icu_17_GtmCcu6_ValueType BufferMarker; 
}Icu_17_GtmCcu6_DutyCycleType;
/* [/cover] */
/*
  The following structure is used by interrupts to measure the 
  signal high time, low time, duty cycle and period time
*/
typedef struct Icu_SigMeasurementParasType
{
  /* Edge array to store Time value for each edge */
  Icu_17_GtmCcu6_ValueType Edge[4];
  /* Number of interrupts required for Signal Measurement */
  uint8         IntrCounter;
  /* Icu_GetTimeElapsed will be calculated based on Index */
  uint8         Index;
  /* Configured Edge for Start of Signal Measurement */
  uint8         CfgEdge;
  /* Signal Measurement property */
  uint8         SigProp;
  #if (ICU_SAFETY_ENABLE == STD_ON)  
 /* Signal measurement Buffer Marker for validating the correct buffer pointer */
  uint32      DutyCycleBufferMarker;  
#endif  
} Icu_SigMeasurementParasType;

/*
  This structure is used by the driver in interrupt service routines
  to track the memory address ,counter and notification in Timestamp
  measurement. 
*/
typedef struct
{
  /* Time stamping buffer address */
  Icu_17_GtmCcu6_ValueType *Address;
  /* buffer Size */
  uint16 Size;
  /* position of the Time stamp buffer */
  uint16        Counter;
  /* Notification interval */
  uint16        Notify;
   /* Notification interval counter */
  uint16        NotifyCounter;
#if (ICU_SAFETY_ENABLE == STD_ON)    
 /* TimeStamp Buffer Marker for validating the correct buffer pointer */
  uint32      TimeStampBufferMarker;
#endif  
} Icu_TimeCaptureParasType;

typedef struct
{
  uint8 ModuleId;
  uint8 ChannelNo;
  uint8 ModuleNo;
  uint8 GroupNo;
}Icu_17_GtmCcu6_ChannelIdentifierType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#define ICU_17_GTMCCU6_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax:void Icu_17_GtmCcu6_Init(const Icu_17_GtmCcu6_ConfigType *ConfigPtr)**
**                                                                            **
** Service ID:      0                                                         **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      non reentrant                                             **
**                                                                            **
** Parameters (in): Config - Pointer to configuration set                     **
**                                                                            **
** Parameters (out):none                                                      **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description : Driver Module Initialization                                 **
**               1.This function will initialize all relevant registers of the**
**               configured hardware (Assigned_HW_Unit) with the values of the**
**               structure referenced by the parameter ConfigPtr.             **
**               2. This service will disable all notifications.              **
**               3. Resources that are not configured in the configuration    **
**                  file will not be changed.                                 **
**               4. All ICU channel status will set to ICU_IDLE               **
**               5. All used registers used by configuration will be          **
**                  initialized if Reset and Deinit API will not reset the    **
**                  registers                                                 **
**               6. Clearing of pending interrupt flags not done in this      **
**                  function as Reset and Deinit will clear this.             **
**               7. After initialization the mode will set to ICU_MODE_NORMAL **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_Init
(
  const Icu_17_GtmCcu6_ConfigType *ConfigPtr
);

/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_DeInit(void)                                  **
**                                                                            **
** Service ID:  1                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : Service for ICU De-Initialization                            **
**               1.After the call of this service, the state of the used      **
**                 peripherals/registers will set to power on reset state.    **
**               2. This service will disable all used interrupts and         **
**                  notifications.                                            **
**               3. This service clear all pending interrupt flags            **
**               4. All global variables will set to reset value              **
**                                                                            **
*******************************************************************************/
#if (ICU_DE_INIT_API == STD_ON)
extern void Icu_17_GtmCcu6_DeInit
(
  void
);
#else
#define Icu_17_GtmCcu6_DeInit() ERROR_Icu_17_GtmCcu6_DeInit_NOT_SELECTED 
#endif

/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_SetMode(Icu_17_GtmCcu6_ModeType Mode)         **
**                                                                            **
** Service ID:  0x2                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in):  Mode : ICU_MODE_NORMAL or ICU_MODE_WAKEUP                **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description : Service for ICU mode selection                               **
**               1.This service will set the operation mode to the given mode **
**                  parameter.                                                **
**               2.In ICU_MODE_NORMAL mode all notifications are available as **
**         configured and selected by the Icu_17_GtmCcu6_DisableNotification()**
**         and Icu_17_GtmCcu6_EnableNotification() services before or after   **
**         the call of Icu_SetMode.                                           **
**               3.In ICU_MODE_WAKEUP mode only those notifications are       **
**                 available which are configured as wake-up capable and which**
**                 are not disabled via service Icu_DisableWakeup. All other  **
**                 interrupts are disabled                                    **
**                                                                            **
*******************************************************************************/
#if ( ICU_SET_MODE_API == STD_ON)
extern void Icu_17_GtmCcu6_SetMode
(
  Icu_17_GtmCcu6_ModeType Mode
);
#else
#define Icu_17_GtmCcu6_SetMode(Mode) \
                               ERROR_Icu_17_GtmCcu6_SetModeApi_NOT_SELECTED 
#endif

/*******************************************************************************
**Syntax:void Icu_17_GtmCcu6_DisableWakeup(Icu_17_GtmCcu6_ChannelType Channel)**
**                                                                            **
** Service ID:  0x3                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel : Numeric identifier of the ICU channel          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1 This service will disable the wake-up capability of single **
**                 ICU channel for the following ICU mode selection(s).       **
**               2.This service is only feasible for ICU channels configured  **
**                 as wake-up capable true.                                   **
**               3.From the call of Icu_17_GtmCcu6_Init() channel which was   **
**                 configured as wakeup capable by using this service user can**
**                 disable the wakeup capability.                             **
**                                                                            **
*******************************************************************************/
#if (ICU_DISABLE_WAKEUP_API == STD_ON)
extern void Icu_17_GtmCcu6_DisableWakeup
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_DisableWakeup(Channel) \
                    ERROR_Icu_17_GtmCcu6_DisableWakeup_NOT_SELECTED 
#endif

/*******************************************************************************
**Syntax:void Icu_17_GtmCcu6_EnableWakeup(Icu_17_GtmCcu6_ChannelType Channel) **
**                                                                            **
** Service ID:  0x4                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel : Numeric identifier of the ICU channel          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description : 1 This service will re-enable the wake-up capability of ICU  **
**                 channel for the following ICU mode selection(s).           **
**               2.This service is only feasible for ICU channels configured  **
**                 as wake-up capable true.                                   **
**               3.From the call of Icu_17_GtmCcu6_Init() the channel which   **
**                was configured as wakeup capable and the same capability was**
**                 disabled by using service Icu_17_GtmCcu6_DisableWakeup().  **
**                 The user can re-enable the wakeup capability by using      **
**                 Icu_17_GtmCcu6_EnableWakeup() service.                     **
**                                                                            **
*******************************************************************************/
#if ( ICU_ENABLE_WAKEUP_API == STD_ON)
extern void Icu_17_GtmCcu6_EnableWakeup(Icu_17_GtmCcu6_ChannelType Channel);
#else
#define Icu_17_GtmCcu6_EnableWakeup(Channel) \
                             ERROR_Icu_17_GtmCcu6_EnableWakeup_NOT_SELECTED 
#endif

/*******************************************************************************
** Syntax :                                                                   **
void Icu_17_GtmCcu6_SetActivationCondition(Icu_17_GtmCcu6_ChannelType Channel **
**                                 Icu_17_GtmCcu6_ActivationType Activation)  **
**                                                                            **
** Service ID:  0x5                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel : Numeric identifier of the ICU channel          **
** Parameters (in):  Activation : ICU_RISING_EDGE,ICU_FALLING_EDGE,           **
**                                ICU_BOTH_EDGES                              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description : 1 This service will set the required configured edge.        **
**               2.This service is only feasible for ICU channels configured  **
**                 as EdgeDetection,TimeStamp and EdgeCounter.                **
**               3.For Signal Measurement Only DefaultStartEdge to be Used    **
**                                                                            **
*******************************************************************************/

extern void Icu_17_GtmCcu6_SetActivationCondition
(
  Icu_17_GtmCcu6_ChannelType  Channel, 
  Icu_17_GtmCcu6_ActivationType  Activation
);

/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_DisableEdgeDetection                          **
**                               (Icu_17_GtmCcu6_ChannelType Channel)         **
**                                                                            **
** Service ID:  0x17                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel : Numeric identifier of the ICU channel          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : This service will disable the ICU signal edge detection      **
**               channel.                                                     **
**                                                                            **
*******************************************************************************/
#if (ICU_EDGE_DETECT_API == STD_ON)
extern void Icu_17_GtmCcu6_DisableEdgeDetection
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_DisableEdgeDetection(Channel)                           \
                        ERROR_Icu_17_GtmCcu6_DisableEdgeDetection_NOT_SELECTED
#endif
/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_EnableEdgeDetection(                          **
**                                      Icu_17_GtmCcu6_ChannelType Channel    **
**               )                                                            **
**                                                                            **
** Service ID:  0x16                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel : Numeric identifier of the ICU channel          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description : This service will Re enables the ICU signal edge detection   **
**               channel, activation edge depends on either DefaultStartEdge  **
**               Or activation by Icu_17_GtmCcu6_SetActivationCondition API.  **
*******************************************************************************/
#if (ICU_EDGE_DETECT_API == STD_ON)
extern void Icu_17_GtmCcu6_EnableEdgeDetection
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_EnableEdgeDetection(Channel)                           \
                         ERROR_Icu_17_GtmCcu6_EnableEdgeDetection_NOT_SELECTED
#endif
/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_DisableNotification                           **
**                                (Icu_17_GtmCcu6_ChannelType Channel)        **
**                                                                            **
** Service ID:  0x6                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel : Numeric identifier of the ICU channel          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : This service will disable all ICU signal notifications of    **
**               this channel.                                                **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_DisableNotification
(
  Icu_17_GtmCcu6_ChannelType Channel
);

/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_EnableNotification(                           **
**                                      Icu_17_GtmCcu6_ChannelType Channel    **
**               )                                                            **
**                                                                            **
** Service ID:  0x7                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  Channel : Numeric identifier of the ICU channel          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description : This service will enable the ICU signal notification         **
**               according to notification parameter.                         **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_EnableNotification
(
  Icu_17_GtmCcu6_ChannelType Channel
);

/******************************************************************************
** Syntax :Icu_17_GtmCcu6_InputStateType                                     **
           Icu_17_GtmCcu6_GetInputState(Icu_17_GtmCcu6_ChannelType Channel)  **
**                                                                           **
** Service ID:       0x8                                                     **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       ICU050:reentrant                                        **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:Status (Icu_17_GtmCcu6_InputStateType) - Returns the state of**
**                   Channel                                                 **
**                                                                           **
** Description : 1. This service returns the status of the ICU input.        **
**               2. If an activation edge has been detected this service will**
**                  return ICU_ACTIVE.                                       **
**               3. Once the service has returned the status ICU_ACTIVE the  **
**                  stored status will be set to ICU_IDLE until the next     **
**                  edge is detected.                                        **
**               4. If no  edge has been detected this service will          **
**                  return ICU_IDLE.                                         **
**               5. If development error detection is enabled and an error is**
**                  detected the service returns ICU_IDLE.                   **
**               6. Signal edge detection channels                           **
**                  channels status is changed here.                         **
**               7. For a signal measurement channel only the status         **
**                  is returned and its not put to IDLE. A successful read   **
**                  of Icu_17_GtmCcu6_GetTimeElapsed or                      **
**                  Icu_17_GtmCcu6_GetDutyCycleValues                        **
**                  will set the state to ICU_IDLE                           **
**                                                                           **
*****************************************************************************/
#if (ICU_GET_INPUT_STATE_API == STD_ON)
extern Icu_17_GtmCcu6_InputStateType Icu_17_GtmCcu6_GetInputState
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_GetInputState(Channel) \
                            ERROR_Icu_17_GtmCcu6_GetInputState_NOT_SELECTED 
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
/*******************************************************************************
** Syntax :void Icu_17_GtmCcu6_StartTimeStamp                                 **
**                                   ( Icu_17_GtmCcu6_ChannelType Channel ,   **
**                                  Icu_17_GtmCcu6_ValueType *BufferPtr,      **
**                                             uint16         BufferSize,     **
**                                             uint16 NotifyInterval )        **
**                                                                            **
** Service ID:       0x09                                                     **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the ICU channel    **
**                   BufferSize    : Size of the Buffer                       **
**                   NotifyInterval: Interval for Timestamp Notifications     **
**                                                                            **
** Parameters (out):                                                          **
**                   BufferPtr     : Starting address of Buffer, that will    **
**                                   hold the timer capture values            **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will start the TimeStamp Capture.            **
**               2. This service will also set the Notifcation Flag, if       **
**                  NotifyInterval is greater than zero.                      **
**               3. The Notifications will be done in ISR Only.               **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_StartTimestamp
(
  Icu_17_GtmCcu6_ChannelType Channel, 
  Icu_17_GtmCcu6_ValueType *BufferPtr, 
  uint16 BufferSize, 
  uint16 NotifyInterval
);
#else
#define Icu_17_GtmCcu6_StartTimestamp(                                      \
                           Channel,BufferPtr,BufferSize,NotifyInterval)     \
                                          ERROR_IcuTimeStampApi_NOT_SELECTED
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
/*******************************************************************************
** Syntax :           void Icu_17_GtmCcu6_StopTimeStamp                      **
**                                  ( Icu_17_GtmCcu6_ChannelType Channel )    **
**                                                                            **
** Service ID:       0x0A                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the ICU channel    **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will stop the TimeStamp Capture.             **
**               2. This service will also activate the interrupt flags.     **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_StopTimestamp
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_StopTimestamp(Channel) ERROR_IcuTimeStampApi_NOT_SELECTED
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
/*******************************************************************************
** Syntax :         Icu_17_GtmCcu6_IndexType Icu_17_GtmCcu6_GetTimeStampIndex(**
**                                        Icu_17_GtmCcu6_ChannelType Channel  **
                                                        )                     **
**                                                                            **
** Service ID:       0x0B                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the ICU channel    **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value:     Icu_17_GtmCcu6_IndexType                                 **
**                                                                            **
** Description : 1. This service will return the next index of the            **
**                  Buffer that will be written by the ISR.                   **
**               2. In case of a liner buffer and the buffer is filled the    **
**                  service will return zero.                                 **
**                                                                            **
*******************************************************************************/
extern Icu_17_GtmCcu6_IndexType Icu_17_GtmCcu6_GetTimestampIndex
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_GetTimestampIndex(Channel) \
                          ERROR_IcuTimeStampApi_NOT_SELECTED
#endif

#if (ICU_EDGE_COUNT_API ==STD_ON)
/*******************************************************************************
** Syntax:void Icu_17_GtmCcu6_ResetEdgeCount                                  **
**                                  ( Icu_17_GtmCcu6_ChannelType Channel )    **
**                                                                            **
** Service ID:       0x0C                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the ICU channel    **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : This service will set the edge counter variable to zero.     **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_ResetEdgeCount
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_ResetEdgeCount(Channel) \
                           ERROR_IcuEdgeCountApi_NOT_SELECTED
#endif

#if (ICU_EDGE_COUNT_API ==STD_ON)
/*******************************************************************************
** Syntax :          void Icu_17_GtmCcu6_EnableEdgeCount                      **
**                                   ( Icu_17_GtmCcu6_ChannelType Channel )   **
**                                                                            **
** Service ID:       0x0D                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the ICU channel    **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will state the edge count mode.              **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_EnableEdgeCount
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_EnableEdgeCount(Channel) \
                                             ERROR_IcuEdgeCountApi_NOT_SELECTED
#endif

#if (ICU_EDGE_COUNT_API ==STD_ON)
/*******************************************************************************
** Syntax :          void Icu_17_GtmCcu6_DisableEdgeCount                     **
**                                    ( Icu_17_GtmCcu6_ChannelType Channel )  **
**                                                                            **
** Service ID:       0x0E                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the ICU channel    **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will stop the edge counting capability       **
**                  of a channel.                                             **
**                                                                            **
*******************************************************************************/

extern void Icu_17_GtmCcu6_DisableEdgeCount
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_DisableEdgeCount(Channel) \
                            ERROR_IcuEdgeCountApi_NOT_SELECTED
#endif

#if (ICU_EDGE_COUNT_API ==STD_ON)
/*******************************************************************************
** Syntax :       Icu_17_GtmCcu6_EdgeNumberType Icu_17_GtmCcu6_GetEdgeNumbers(**
**                            Icu_17_GtmCcu6_ChannelType Channel )            **
**                                                                            **
** Service ID:       0x0F                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the ICU channel    **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value:     Icu_17_GtmCcu6_EdgeNumberType                            **
**                                                                            **
** Description : 1. This service will return the number of edges counted      **
**                  for the channel specified.                                **
*******************************************************************************/

extern Icu_17_GtmCcu6_EdgeNumberType Icu_17_GtmCcu6_GetEdgeNumbers
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_GetEdgeNumbers(Channel) \
                        ERROR_IcuEdgeCountApi_NOT_SELECTED
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/* ICU142 : Configuration of API Service */
/******************************************************************************
** Syntax :          void Icu_17_GtmCcu6_StartSignalMeasurement (            **
**                                       Icu_17_GtmCcu6_ChannelType Channel) **
**                                                                           **
** Service ID:       0x13                                                    **
**                                                                           **
** Sync/Async:       Asynchronous                                            **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  None                                                    **
**                                                                           **
** Parameters (out):  versioninfo : Pointer to hold the version values       **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service starts the measurement of signals beginning **
**                  with the configured default start edge which occurs first**
**                  after the call of this service.                          **
******************************************************************************/
extern void Icu_17_GtmCcu6_StartSignalMeasurement 
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_StartSignalMeasurement(Channel)                        \
                                      ERROR_IcuSignalMeasurementApi_NOT_SELECTED
#endif


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/* ICU145 : Configuration of API Service */
/******************************************************************************
** Syntax :          void Icu_17_GtmCcu6_StopSignalMeasurement (             **
**                                       Icu_17_GtmCcu6_ChannelType Channel) **
**                                                                           **
** Service ID:       0x14                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  None                                                    **
**                                                                           **
** Parameters (out):  versioninfo : Pointer to hold the version values       **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service stops the measurement of signals of the     **
**                  given channel                                            **
******************************************************************************/
extern void Icu_17_GtmCcu6_StopSignalMeasurement 
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_StopSignalMeasurement(Channel)                      \
                                      ERROR_IcuSignalMeasurementApi_NOT_SELECTED
#endif


#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
/******************************************************************************
** Syntax :          Icu_17_GtmCcu6_ValueType Icu_17_GtmCcu6_GetTimeElapsed (**
**                                       Icu_17_GtmCcu6_ChannelType Channel )**
**                                                                           **
** Service ID:       0x10                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):                                                         **
**                                                                           **
** Return value:     Icu_17_GtmCcu6_ValueType                                **
**                                                                           **
** Description : 1. This service will return the latest time difference value**
**                  measured as per the configured type of measurement.      **
**                  The service shall measure the following measurement types**
**                  High Time, Low Time Or Period Time.                      **
**               2. The service shall return zero if there were no edges     **
**                  captured or the service has already read the same value. **
**               3. For a successful read the service sets the Channel Status**
**                  to ICU_IDLE.                                             **
*****************************************************************************/
extern Icu_17_GtmCcu6_ValueType Icu_17_GtmCcu6_GetTimeElapsed
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#else
#define Icu_17_GtmCcu6_GetTimeElapsed(Channel) \
                                  ERROR_IcuGetTimeElapsedApi_NOT_SELECTED
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/*******************************************************************************
** Syntax :          void Icu_17_GtmCcu6_GetDutyCycleValues (                 **
**                                       Icu_17_GtmCcu6_ChannelType Channel,  **
**                            Icu_17_GtmCcu6_DutyCycleType *DutyCycleValues ) **
**                                                                            **
** Service ID:       0x11                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the ICU channel    **
**                                                                            **
** Parameters (out):  DutyCycleValues : Pointer to structure that could       **
**                                     hold high time and period time.        **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will return the latest high time             **
**                  and period time captured.                                 **
**               2. The service shall write zero in the given address         **
**                  if there were no edges captured or the                    **
**                  has already read the same value.                          **
**               3. A successful read puts the status to ICU_IDLE             **
*******************************************************************************/
extern void Icu_17_GtmCcu6_GetDutyCycleValues
(
  Icu_17_GtmCcu6_ChannelType Channel,
  Icu_17_GtmCcu6_DutyCycleType *DutyCycleValues
);
#else
#define Icu_17_GtmCcu6_GetDutyCycleValues(Channel,DutyCycleValues)      \
                                     ERROR_IcuGetDutyCycleValuesApi_NOT_SELECTED
#endif



/*******************************************************************************
** Syntax: void Icu_17_GtmCcu6_CheckWakeup(EcuM_WakeupSourceType WakeupSource)**
**                                                                            **
** Service ID:  0x15                                                          **
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
** Description : Checks if a wakeup capable ICU channel is the source for a   **
** wakeup event and calls the ECU state manager service EcuM_SetWakeupEvent   **
** in case of a valid ICU channel wakeup event.                               **
**                                                                            **
*******************************************************************************/
/*Applicable to Autosar V 3.2.1 also, based on Bugzilla 25392*/
#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) \
                                        && (ICU_REPORT_WAKEUP_SOURCE == STD_ON))
extern void Icu_17_GtmCcu6_CheckWakeup
(
  EcuM_WakeupSourceType WakeupSource
);
#else
#define Icu_17_GtmCcu6_CheckWakeup(wakeupSource) \
                         ERROR_Icu_17_GtmCcu6_CheckWakeup_NOT_SELECTED
#endif


#if (ICU_GETMODE_API == STD_ON)
extern Icu_17_GtmCcu6_ModeType Icu_17_GtmCcu6_GetMode(void);
#else
#define Icu_17_GtmCcu6_GetMode(void) \
                               ERROR_Icu_17_GtmCcu6_GetModeApi_NOT_SELECTED 
#endif


/*******************************************************************************
** Syntax           : Std_ReturnType Icu_17_GtmCcu6_InitCheck                 **
**                    (                                                       **
**                      ConfigPtr                                             **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : This function checks is the initialization of the       **
**                    ICU driver done according to the                        **
**                    configuration set referenced by ConfigPtr.              **
**                                                                            **
*******************************************************************************/
#if (ICU_INITCHECK_API == STD_ON)
extern Std_ReturnType Icu_17_GtmCcu6_InitCheck 
     (const Icu_17_GtmCcu6_ConfigType* ConfigPtr);
#else
#define Icu_17_GtmCcu6_InitCheck(ConfigPtr) \
                               ERROR_Icu_17_GtmCcu6_InitCheckApi_NOT_SELECTED 
#endif
/*******************************************************************************
** Syntax:           void Icu_17_GtmCcu6_Eru_Isr(void)                        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This is Interrupt Routine Functions for the ERUlines     **
**                   lines. When interrupt occurs corresponding ERU line      **
**                   Service request will be invoked.                         **
*******************************************************************************/
extern void Icu_17_GtmCcu6_Eru_Isr( void );  

/******************************************************************************
** Syntax:           void Icu_17_GtmCcu6_Ccu_Isr(uint8 CcuKernalNumber)      **
**                                                                           **
** Service ID:       none                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  CcuKernalNumber - CCU6x Kernal Number that has triggered**
**                   the interrupt                                           **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     This is Interrupt Routine Functions for the CCU lines   **
**                   lines. When interrupt occurs corresponding CCU line     **
**                   Service request will be invoked.                        **
*****************************************************************************/
void Icu_17_GtmCcu6_Ccu_Isr(uint8 CcuKernalNumber, uint8 CcuChannelNumber);

/* void Icu_17_GtmCcu6_Ccu_Isr(uint8 CcuKernalNumber, uint8 CcuChannelNumber,
                            Icu_17_GtmCcu6_ActivationType EdgeSource);*/
                            
#define ICU_17_GTMCCU6_STOP_SEC_CODE
#include "MemMap.h"

#define ICU_17_GTMCCU6_START_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_Isr(uint8 ModuleType, uint8 ModuleNo,         **
**                          uint8 ChannelNo, uint8 IrqSrc)                    **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in): ModuleType - Identify TIM Module                          **
**                  ModuleNo - TIM Module Number                              **
**                  ChannelNo - TIM Channel number                            **
**                  IrqSrc - Interrup Source CCU0/CCU1                        **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This is Interrupt Routine Functions for the GTM          **
**                   lines.                                                   **
*******************************************************************************/
extern void Icu_17_GtmCcu6_Isr (uint8 Channel);
#define ICU_17_GTMCCU6_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"




_IFXEXTERN_ _INLINE_ uint8 Icu_lGetEdge(
                             Icu_17_GtmCcu6_SignalMeasurementPropertyType Kind)
{
  return( (Kind == ICU_HIGH_TIME)? ICU_RISING_EDGE : ICU_FALLING_EDGE);
}
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#define ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Configuration Struture extern */
extern const Icu_17_GtmCcu6_ConfigType Icu_ConfigRoot[];
#define ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

#endif /* ICU_17_GTMCCU6_H */
