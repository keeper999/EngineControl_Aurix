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
**  $FILENAME  : Pwm_17_Gtm.h  $                                              **
**                                                                            **
**   $CC VERSION : \main\31 $                                                 **
**                                                                            **
**   $DATE       : 2013-09-25 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file contains export declarations of Pwm driver       **
**                                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
** [cover parentID=DS_AS_PWM094] [/cover]                                     **
** [cover parentID=DS_AS40X_PWM001_PI] [/cover]                               **
** [cover parentID=DS_NAS_PR746] [/cover]                                     **
**                                                                            **
*******************************************************************************/

#ifndef PWM_H
#define PWM_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
/* configuration data for PWM module */
#include "Pwm_17_Gtm_Cfg.h"
#if (PWM_DEV_ERROR_DETECT == STD_ON) /* PWM003: */
/* Import of DET functionality */
#include "Det.h"
#endif

#if(PWM_SAFETY_ENABLE == STD_ON)
#include "SafetyReport.h"
#endif
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
  /*
    Published parameters
  */
#define PWM_17_GTM_VENDOR_ID                   ((uint16)(17U))
  /* Pwm Module ID */
#define PWM_17_GTM_MODULE_ID                   ((uint16)(121U))
  
/*
  Development error values
*/
#if (PWM_DEV_ERROR_DETECT == STD_ON||PWM_SAFETY_ENABLE==STD_ON)

/* API service called with wrong parameter */
#define PWM_E_PARAM_CONFIG         ((uint8)0x10)
/* API service used without module initialization */
#define PWM_E_UNINIT               ((uint8)0x11)
/* API service used with an invalid channel Identifier  */
#define PWM_E_PARAM_CHANNEL        ((uint8)0x12)
/* Usage of Pwm_SetPeriodAndDuty on PWM channel
   with class other than VARIABLE_PERIOD*/
#define PWM_E_PERIOD_UNCHANGEABLE  ((uint8)0x13)
/* Init API service is already called */
#define PWM_E_ALREADY_INITIALIZED  ((uint8)0x14)
/* Function ‘Pwm_GetVersionInfo’ called with invalid pointer */
#define PWM_E_PARAM_POINTER        ((uint8)0x15)
/* API service called with wrong Edge */
#define PWM_E_PARAM_EDGE           ((uint8)0x16)
/* API service called with Period out of range */
#define PWM_E_PERIOD_OUT_OF_RANGE           ((uint8)0x17)
/* API service called with Duty out of range */
#define PWM_E_DUTY_OUT_OF_RANGE           ((uint8)0x18)
/*ISR called for channel which was not configured to have notification*/
#define PWM_E_WRONG_NOTIF                 ((uint8)0x19)


/*
 * PWM Service Id's
*/
/* Pwm_Init() Service ID */
#define PWM_SID_INIT                 ((uint8)0x00)
/* Pwm_DeInit() Service ID */
#define PWM_SID_DEINIT               ((uint8)0x01)
/* Pwm_SetDuty() Service ID */
#define PWM_SID_SETDUTY              ((uint8)0x02)
/* Pwm_SetPeriodAndDuty() Service ID */
#define PWM_SID_SET_PERIOD_DUTY      ((uint8)0x03)
/* Pwm_SetOutputToIdle() Service ID */
#define PWM_SID_SETOP2IDLE           ((uint8)0x04)
/* Pwm_GetOutputState() Service ID */
#define PWM_SID_GETOPSTATE           ((uint8)0x05)
/* Pwm_DisableNotification() Service ID */
#define PWM_SID_DISABLENOTIFI        ((uint8)0x06)
/* Pwm_EnableNotification() Service ID */
#define PWM_SID_ENABLENOTIFI         ((uint8)0x07)
/* Pwm_GetVersionInfo() Service ID */
#define PWM_SID_GETVERSIONINFO       ((uint8)0x08)
/*Pwm ISR service ID*/
#define PWM_SID_ISR                  ((uint8)0x09)
#endif /* PWM_DEV_ERROR_DETECT */



/* To indicate not referenced to other channel  */
#define PWM_NOT_REFERENCED           (0x1FU)

/* PWM Channel class types */
#define PWM_FIXED_PERIOD                   ((Pwm_17_Gtm_ChannelClassType)(0x0))
#define PWM_FIXED_PERIOD_SHIFTED           ((Pwm_17_Gtm_ChannelClassType)(0x1))
#define PWM_FIXED_PERIOD_CENTER_ALIGNED    ((Pwm_17_Gtm_ChannelClassType)(0x2))
#define PWM_VARIABLE_PERIOD                ((Pwm_17_Gtm_ChannelClassType)(0x3))

/* The PWM channel is in low state.*/
#define PWM_LOW   ((Pwm_17_Gtm_OutputStateType)(0))
/* The PWM channel is in High state.*/
#define PWM_HIGH  ((Pwm_17_Gtm_OutputStateType)(1))

#if (PWM_SAFETY_ENABLE == STD_ON)

/* The PWM channel is of type ASIL */
#define PWM_ASIL_TYPE                ((uint8)(0x1))
/* The PWM channel is of type QM */
#define PWM_QM_TYPE                   ((uint8)(0x0))

#endif /* PWM_SAFETY_SUPPORTED */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/* Notification will be called when a rising edge occurs on the PWM Output
     signal.*/
#define PWM_RISING_EDGE     ((Pwm_17_Gtm_EdgeNotificationType)(1))
/* Notification will be called when a falling edge occurs on the PWM
   output signal */
#define PWM_FALLING_EDGE    ((Pwm_17_Gtm_EdgeNotificationType)(2))
/* Notification will be called when both a rising edge or falling edge
   (means any edge) occurs on the PWM output signal */
#define PWM_BOTH_EDGES      ((Pwm_17_Gtm_EdgeNotificationType)(3))

#endif /* PWM_NOTIFICATION_SUPPORTED */


/*******************************************************************************
**                      Functions like Macro                                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
** [cover parentID=DS_AS_PWM111] [/cover]                                     **
** [cover parentID=DS_AS_PWM061] [/cover]                                     **
** [cover parentID=DS_AS_PWM107] [/cover]                                     **
** [cover parentID=DS_AS_PWM108] [/cover]                                     **
** [cover parentID=DS_AS_PWM109] [/cover]                                     **
** [cover parentID=DS_AS_PWM110] [/cover]                                     **
** [cover parentID=DS_AS_PWM106] [/cover]                                     **
** [cover parentID=DS_AS_PWM077] [/cover]                                     **
** [cover parentID=DS_MCAL_SWSC_PWM_0901] [/cover]                           **
**                                                                            **
*******************************************************************************/
/* PWM027: */
/* Output state of a PWM channel. Note that this will be read from the output
   state on the LTC cell (Assigned_HwUnit) connected to the port pin.
   This will not be read directly from the Port Pin. However both will be
   the same. */
typedef uint8 Pwm_17_Gtm_OutputStateType;

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

/* Definition of the type of notification of a PWM channel */
typedef uint8 Pwm_17_Gtm_EdgeNotificationType;

#endif /* PWM_NOTIFICATION_SUPPORTED */

typedef uint8 Pwm_GlobalChannelNumberType;

/* Numeric identifier of a PWM channel */
typedef uint32 Pwm_17_Gtm_ChannelType; /* Maximum 32 channels can be supported.
                                   If proper configuration setup made by user */

/* Type definition of the period of a PWM channel.*/
typedef uint32 Pwm_17_Gtm_PeriodType;

/* Type to denote the class of PWM */
typedef uint8 Pwm_17_Gtm_ChannelClassType;

/* To provide Notification the following type will be used */
typedef void (*Pwm_17_Gtm_NotifiPtrType)(void);
/* The following struct type is a channel dependent configuration */
/*
   All the member names are given as per bmd file to maintain
   consistency
*/
typedef struct Pwm_17_Gtm_ChannelConfigType
{
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

  /* The following parameter is a function pointer to provide notification */
  Pwm_17_Gtm_NotifiPtrType Notification;
  #endif /* PWM_NOTIFICATION_SUPPORTED */

  /* This Pwm_ChannelInfo constitutes
      Reference_Channel, Pwm_ChannelMode, Pwm_IdleState and
      Assigned_HwUnit.
      While forming the variable, user has to form this in the following
      manner. [Note : Use macro Pwm_lConfigChannel() for configuration ]
      PwmChannelInfo =
            ((ReferenceChannel << 13) |
              (PwmChannelClass << 9)    |
              (PwmIdleState << 8)      |
              (PwmPolarity << 7)       |
              (AssignedHwUnit)
            )

     Where :
            bit 12-17:
            Reference_Channel used for Grouping.
            (Shift or Center aligned )
            [Range: 0 to 63]
            Valid only for FIXED_PERIOD_SHIFTED and FIXED_PERIOD_CENTER_ALIGNED

            bit 10-11:
            PwmChannelClass :  Used to indicate whether channel is
                                FIXED_PERIOD
                                FIXED_PERIOD_SHIFTED
                                FIXED_PERIOD_CENTER_ALIGNED
                                VARIABLE_PERIOD
            bit 9:
            PwmCoherency   : Informs the channel wise Coherency Selection.
                              1 - Coherent or 0 - non Coherent.
            bit 8:
            PwmIdleState   : Informs the channel Idle State.
                              PWM_HIGH or PWM_LOW

            bit 7:
            PwmPolarity    : Informs the channels start state
                              PWM_HIGH Or PWM_LOW
            bits 0 - 6
            PwmAssignedHwUnit : Hardware resource : TOM and ATOM
                               Value Range : TOM0 - Channel0 to Channel 15
                                             TOM1 - Channel0 to Channel 15
                                             TOM2 - Channel0 to Channel 15
                                             ATOM0 - Channel0 to Channel 7
                                             ATOM1 - Channel0 to Channel 7
                                             ATOM2 - Channel0 to Channel 7
                                             ATOM3 - Channel0 to Channel 7
                                             ATOM4 - Channel0 to Channel 7
  */
  uint32 ChannelInfo;

  /* Default period of PWM channel. This value is fixed permanently for a PWM
      channel configured with Fixed Period Type. */
  Pwm_17_Gtm_PeriodType PeriodDefault;

  /* Default Duty Cycle of a PWM channel */
  uint32 DutycycleDefault;

  /* The following parameter informs the % of shift required.
      The range will be from 0x0000 to 0x8000.
      For 0% shift : value=0x0000, for 100% shift : value=0x8000 */
  uint32 ShiftValue;

  #if (PWM_SAFETY_ENABLE == STD_ON)
  /* The following parameter specifies if the channel is ASIL or QM */
  uint8 SafetyChannelSignal;
  #endif /* PWM_SAFETY_SUPPORTED */
  uint8 SafetyChannelIndex;

}Pwm_17_Gtm_ChannelConfigType;

/* PWM061: The following struct type is utilized to configure PWM module */
typedef struct Pwm_17_Gtm_ConfigType
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  /* Marker to check the config pointer */
  uint32 Marker;
  #endif /* PWM_SAFETY_SUPPORTED */
  const Pwm_17_Gtm_ChannelConfigType *ChannelConfigPtr;
  Pwm_17_Gtm_ChannelType             MaxChannels;
}Pwm_17_Gtm_ConfigType;

/*Structure to hold the different details of a channel*/
typedef struct
{
  uint8 ModuleId;
  uint8 ModuleNo;
  uint8 ChannelNo; /* Specifies the Channel Number       */
  uint8 GroupNo; 
}Pwm_ChannelIdentifierType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define PWM_17_GTM_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of Pwm Post Build Configuration */
extern const Pwm_17_Gtm_ConfigType Pwm_ConfigRoot[];

#define PWM_17_GTM_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_Init(const Pwm_17_Gtm_ConfigType *ConfigPtr)      **
**                                                                            **
** Service ID:  0x0                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): Config - Pointer to configuration set                     **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Driver Module Initialization                                 **
**               1.This function will initialize all relevant registers of the**
**                 configured hardware (Assigned_HW_Unit) with the values of  **
**                 structure given by user in Pwm_Configuration[].            **
**               2. This service will disable all notifications.              **
**               3. Resources that are not configured in the configuration    **
**                  file will not be changed.                                 **
**               4. This function shall initialize all internals variables    **
**               5. After initialization the PWM driver will start to generate**
**                  PWM signal(s) with the configured default values          **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_Gtm_Init
(
  const Pwm_17_Gtm_ConfigType *ConfigPtr
);

#if (PWM_DE_INIT_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_DeInit(void)                                      **
**                                                                            **
** Service ID:  0x1                                                           **
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
** Description : Service for PWM De-Initialization                            **
**               1.After the call of this service, the state of the used      **
**                 peripherals/registers will set to power on reset state.    **
**               2.This service will disable all used interrupts and          **
**                  notifications.                                            **
**               3.This service clear all pending interrupt flags             **
**               4.All global variables will get reset                        **
**               5.All channel output signal state will set to Idle State     **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_Gtm_DeInit
(
  void
);

#else

#define Pwm_17_Gtm_DeInit() \
ERROR_Pwm_17_Gtm_DeInit_NOT_SELECTED;

#endif /* PWM_DE_INIT_API */

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_SetDutyCycle(                                     **
**                                Pwm_17_Gtm_ChannelType ChannelNumber,       **
**                                uint16          DutyCycle                   **
**               )                                                            **
**                                                                            **
** Service ID:  0x2                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                   DutyCycle     : To set Duty Cycle for a PWM channel      **
**                                   Min=0x0000 Max=0x8000                    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : Service to set Duty cycle                                    **
**               1.This service will allow to set the duty cycle of the PWM   **
**                 channel.                                                   **
**               2.If the duty cycle = 0% (value=0x0000), then the PWM output **
**                 state will set to Idle level.                              **
**               3.If the duty cycle=100% (value=0x8000), then the PWM output **
**                 state will set to Active level.                            **
**               4.If the duty cycle>100%(value>0x8000), then the PWM output  **
**                 will be undefined behavior (recommended that, user not to  **
**                 provide this range of value)                               **
**               5 If the duty cycle >0% and <100%,then the PWM output will   **
**                 set to active state according to duty cycle and period     **
**                 parameters and then to idle state.                         **
**               6.Dependency on PWM_DUTYCYCLE_UPDATED_ENDPERIOD configuration**
**                 parameter.                                                 **
**                                                                            **
*******************************************************************************/

#if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)    
extern void Pwm_17_Gtm_SetDutyCycle
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  uint16          DutyCycle
);
#else
extern void Pwm_17_Gtm_SetDutyCycle
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  uint32          DutyCycle
);
#endif
#else

#define Pwm_17_Gtm_SetDutyCycle(ChannelNumber, DutyCycle) \
ERROR_Pwm_17_Gtm_SetDutyCycle_NOT_SELECTED

#endif /* PWM_SET_DUTY_CYCLE_API */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_SetPeriodAndDuty(                                 **
**                                    Pwm_17_Gtm_ChannelType ChannelNumber,   **
**                                    Pwm_17_Gtm_PeriodType  Period,          **
**                                           uint16          DutyCycle        **
**                                    )                                       **
**                                                                            **
** Service ID:  0x3                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                   Period        : Period of the PWM signal                 **
**                   DutyCycle     : To set Duty Cycle for a PWM channel      **
**                                   Min=0x0000 Max=0x8000                    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : Service to set period and Duty cycle                         **
**               1.This service will allow to set the duty cycle of the PWM   **
**                 channel.                                                   **
**               2.Valid only for variable period                             **
**               3.If the duty cycle=0% (value=0x8000), then the PWM output   **
**                 state will set to Idle level.                              **
**               4.If the duty cycle=100% (value=0x8000), then the PWM output **
**                 state will set to Active level.                            **
**               5.If the duty cycle>100%(value>0x8000), then the PWM output  **
**                 will be undefined behavior (recommended that, user not to  **
**                 provide this range of value)                               **
**               6 If the duty cycle >0% and <100%,then the PWM output will   **
**                 set to active state according to duty cycle and period     **
**                 parameters and then to idle state.                         **
**               7.To scale the duty cycle passed period  will be used        **
**                                                                            **
*******************************************************************************/
#if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)    
extern void Pwm_17_Gtm_SetPeriodAndDuty
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  Pwm_17_Gtm_PeriodType  Period,
  uint16          DutyCycle
);
#else
extern void Pwm_17_Gtm_SetPeriodAndDuty
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  Pwm_17_Gtm_PeriodType  Period,
  uint32          DutyCycle
);
#endif
#else

#define Pwm_17_Gtm_SetPeriodAndDuty(ChannelNumber, Period, DutyCycle) \
ERROR_Pwm_17_Gtm_SetPeriodAndDuty_NOT_SELECTED

#endif /* PWM_SET_PERIOD_AND_DUTY_API */

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_SetOutputToIdle                                   **
**                              (Pwm_17_Gtm_ChannelType ChannelNumber)        **
**                                                                            **
** Service ID:  0x4                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : Service for to set PWM output to Idle State                  **
**               1.This API will be useful to set output to Idle immediately  **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_Gtm_SetOutputToIdle
(
  Pwm_17_Gtm_ChannelType ChannelNumber
);
#else

#define Pwm_17_Gtm_SetOutputToIdle(ChannelNumber) \
ERROR_Pwm_17_Gtm_SetOutputToIdle_NOT_SELECTED

#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/*******************************************************************************
** Syntax : Pwm_17_Gtm_OutputStateType Pwm_17_Gtm_GetOutputState              **
**                                    (Pwm_17_Gtm_ChannelType ChannelNumber)  **
**                                                                            **
** Service ID:  0x5                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     Pwm_17_Gtm_OutputStateType                               **
**                                                                            **
** Description : Service to read the PWM output state                         **
**               1.If development error detection is enabled and an error is  **
**                  detected the service returns PWM_LOW.                     **
**               2.Output state of a PWM channel. Note that this will be read **
**                 from the output state on the LTC cell (Assigned_HwUnit)    **
**                 connected to the port pin. This will not be read directly  **
**                 from the Port Pin. However both will be the same           **
**                                                                            **
*******************************************************************************/
extern Pwm_17_Gtm_OutputStateType Pwm_17_Gtm_GetOutputState
(
  Pwm_17_Gtm_ChannelType ChannelNumber
);
#else

#define Pwm_17_Gtm_GetOutputState(ChannelNumber) \
ERROR_Pwm_17_Gtm_GetOutputState_NOT_SELECTED

#endif /* PWM_GET_OUTPUT_STATE_API */


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_DisableNotification                               **
**                                  (Pwm_17_Gtm_ChannelType ChannelNumber)    **
**                                                                            **
** Service ID: 0x6                                                            **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: reentrant                                                      **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : This service will disable all PWM signal notifications of    **
**               this channel. (PWM023:)                                      **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_Gtm_DisableNotification
(
  Pwm_17_Gtm_ChannelType ChannelNumber
);
#else

#define Pwm_17_Gtm_DisableNotification(ChannelNumber) \
ERROR_Pwm_17_Gtm_DisableNotification_NOT_SELECTED

#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_EnableNotification(                               **
**                                Pwm_17_Gtm_ChannelType   ChannelNumber,     **
**                                Pwm_17_Gtm_EdgeNotificationType Notification**
**                                     )                                      **
** Service ID: 0x7                                                            **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: reentrant                                                      **
**                                                                            **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel    **
**                   Notification  : PWM_RISING_EDGE or                       **
**                                   PWM_FALLING_EDGE or                      **
**                                   PWM_BOTH_EDGES                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : This service will enable the PWM signal notification         **
**               according to notification parameter. PWM024:                 **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_Gtm_EnableNotification
(
  Pwm_17_Gtm_ChannelType          ChannelNumber,
  Pwm_17_Gtm_EdgeNotificationType Notification
);
#else

#define Pwm_17_Gtm_EnableNotification(ChannelNumber) \
ERROR_Pwm_17_Gtm_EnableNotification_NOT_SELECTED

#endif /* PWM_NOTIFICATION_SUPPORTED */

/*******************************************************************************
** Syntax :          void Pwm_17_Gtm_GetVersionInfo( Std_VersionInfoType      **
**                                            *VersionInfoPtr)                **
**                                                                            **
** Service ID:       0x8                                                      **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): versioninfo : Pointer to hold the version values         **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will return the version infos of PWM driver  **
**                                                                            **
** Traceabilty      :                                                         **
** [cover parentID=DS_AS_PWM103] [/cover]                                     **
** [cover parentID=DS_AS_PWM068] [/cover]                                     **
** [cover parentID=DS_AS_PWM069a_PWM069b] [/cover]                            **
** [cover parentID=DS_AS_PWM064_9] [/cover]                                   **
** [cover parentID=DS_AS_PWM114] [/cover]                                     **
** [cover parentID=DS_AS_PWM151] [/cover]                                     **
** [cover parentID=DS_AS_PWM051b_9] [/cover]                                  **
** [cover parentID=DS_AS_PWM051a_PWM078_9] [/cover]                           **
**                                                                            **
*******************************************************************************/
#if ( (PWM_VERSION_INFO_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) )
#define Pwm_17_Gtm_GetVersionInfo(VersionInfoPtr)                              \
{                                                                              \
  /* Check for DET: PWM_E_PARAM_POINTER */                                     \
  if ((VersionInfoPtr) == NULL_PTR)                                            \
  {                                                                            \
    /* Report PWM_E_PARAM_POINTER DET if service called with                   \
       NULL_PTR                                                                \
    */                                                                         \
    Det_ReportError(                                                           \
      PWM_17_GTM_MODULE_ID,                                                    \
      PWM_17_GTM_INSTANCE_ID,                                                  \
      PWM_SID_GETVERSIONINFO,                                                  \
      PWM_E_PARAM_POINTER);                                                    \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    /* Vendor ID information */                                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = PWM_17_GTM_VENDOR_ID; \
    /* Pwm module ID information */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = PWM_17_GTM_MODULE_ID; \
    /* Pwm module Software major version information */                        \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                       (uint8)PWM_17_GTM_SW_MAJOR_VERSION;     \
    /* Pwm module Software minor version information */                        \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                       (uint8)PWM_17_GTM_SW_MINOR_VERSION;     \
    /* Pwm module Software patch version information */                        \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                       (uint8)PWM_17_GTM_SW_PATCH_VERSION;     \
  }                                                                            \
}
#elif((PWM_VERSION_INFO_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_OFF))
#define Pwm_17_Gtm_GetVersionInfo(VersionInfoPtr)                              \
{                                                                              \
  /* Vendor ID information */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = PWM_17_GTM_VENDOR_ID;   \
  /* Pwm module ID information */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = PWM_17_GTM_MODULE_ID;   \
  /* Pwm module Software major version information */                          \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =                 \
                                     (uint8)PWM_17_GTM_SW_MAJOR_VERSION;       \
  /* Pwm module Software minor version information */                          \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =                 \
                                     (uint8)PWM_17_GTM_SW_MINOR_VERSION;       \
  /* Pwm module Software patch version information */                          \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =                 \
                                     (uint8)PWM_17_GTM_SW_PATCH_VERSION;       \
}/* Pwm_17_Gtm_GetVersionInfo */
#else /*(PWM_VERSION_INFO_API == STD_OFF)&&(PWM_DEV_ERROR_DETECT == STD_OFF)*/
#define Pwm_17_Gtm_GetVersionInfo(VersionInfoPtr)                              \
  ERROR_Pwm_17_Gtm_GetVersionInfo_NOT_SELECTED

#endif /* (PWM_VERSION_INFO_API) */

#define PWM_17_GTM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax :          void Pwm_17_Gtm_Isr                                      **
**                   ( uint8 ModuleType, uint8 ModuleNo,                      **
**                    uint8 ChannelNo, uint8 IrqSrc )                         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  TomAtomChannelNumber : Numeric identifier of TOM/ATOM    **
**                                          channel                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : 1. This service will be used only in an interrupt            **
**               2. In this service, Call back Notification will be provided  **
**                                                                            **
*******************************************************************************/
extern void Pwm_17_Gtm_Isr
(
  Pwm_17_Gtm_ChannelType          ChannelNumber
);
#define PWM_17_GTM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /* PWM_H */
