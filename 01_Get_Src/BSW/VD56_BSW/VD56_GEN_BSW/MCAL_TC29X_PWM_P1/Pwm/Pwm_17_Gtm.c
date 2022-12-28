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
**  $FILENAME  : Pwm_17_Gtm.c $                                              **
**                                                                           **
**  $CC VERSION : \main\66 $                                                 **
**                                                                           **
**   $DATE       : 2014-01-25 $                                               **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : This file contains functionality of Pwm driver            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=SAS_MCAL_SWSC_0108] [/cover]                              **
** [cover parentID=DS_MCAL_SWSC_PWM_0912] [/cover]                           **
** [cover parentID=SAS_AS_PWM075a] [/cover]                                  **
** [cover parentID=SAS_AS_PWM075b] [/cover]                                  **
** [cover parentID=SAS_AS_PWM075c] [/cover]                                  **
** [cover parentID=SAS_AS_PWM075e] [/cover]                                  **
** [cover parentID=SAS_AS_PWM075f] [/cover]                                  **
** [cover parentID=DS_NAS_PR912] [/cover]                                    **
** [cover parentID=DS_NAS_PR69_PR469] [/cover]                               **
** [cover parentID=DS_NAS_PR734] [/cover]                                    **
** [cover parentID=SAS_MCAL_SWSC_PWM_0900] [/cover]                          **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
/* Inclusion of Tasking sfr file */
#include "IfxGtm_reg.h"
/* Include Mcal.h to import the library functions */
#include "Mcal.h"
/* GTM Header file */
#include "Gtm.h" 
/* Pwm Module header file, this includes Pwm Static configuration file also */
#include "Pwm_17_Gtm.h"
/*Pwm module's version details */
#include "Pwm_17_Gtm_Ver.h"
/* Coding Guideline violation */
/* 
Brackets are not used in case of Mcal_SetAtomic.
This is mainly due to the usage of inline assembly statement
for ldmst. Also the last parameter will not have U subscript
or any specific typecast, as the generated assembly statement
would not compile.
*/

/******************************************************************************
**                      Imported Compiler Switch Check                       **
******************************************************************************/
/******************************************************************************
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS40X_PWM029] [/cover]                                 **
** [cover parentID=DS_AS_PWM104] [/cover]                                    **
** [cover parentID=DS_NAS_PR730] [/cover]                                    **
** [cover parentID=DS_NAS_PR915] [/cover]                                    **
**                                                                           **
******************************************************************************/
/* General Notes on Requirments:
PWM077: PWM module supports Variant PB delivery.
PWM079: Variant PC is limited to pre-compile configuration parameters only.
        This delivery deals with Variant PB.
PWM001: PWM Driver doesnt cover a PWM emulation on a general purpose I/O.
PWM073: Lower level interfaces are not required in PWM.
PWM065: Code file structure shall not be defined within specification.
PWM066: Inclusion of Dem.h file, as there are no run time errors, the
        file need not be included.
PWM067: Production of DEM Error Codes cannot be switched off. Not Applicable
        here.
PWM005: Reporting of DEM. NA here.
PWM006: Additional errors to be documented. No additional errors in this
        delivery.
PWM074: Calling of Optional Interfaces like Det_ReportError.
*/


/******************************************************************************
**                      Private Macro Definitions                            **
******************************************************************************/
#if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
  /* To shift by 15 */
#define PWM_SHIFT_BY15             ((uint32)(15))
#endif

#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || \
                                    (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/* To Enable any bit of register */
#define PWM_BIT_SET                (1U)
#endif

/* To Disable any bit of register */
#define PWM_BIT_RESET              (0U)

/* if DET enabled */
#if  ((PWM_DEV_ERROR_DETECT == STD_ON)|| (PWM_SAFETY_ENABLE == STD_ON)) 
/* PWM003: */
/* To indicate error found or not */
#define PWM_ERROR_FOUND            ((uint32)1)
#endif /* PWM_DEV_ERROR_DETECT */

#if ( (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF) || \
                                   (PWM_NOTIFICATION_SUPPORTED == STD_ON)) 
/* Maximum Duty Cycle value  PWM059: */
#define PWM_MAX_DUTY               ((uint16)0x8000)
#endif 
/* ( (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF) || 
                                   (PWM_NOTIFICATION_SUPPORTED == STD_ON)) */

/*Pwm Channel Info has the following positions */
/* Channel Mode Positions */
#define PWM_CHANNEL_MODE_POS          ((uint32)0xA)
#define PWM_CHANNEL_MODE_MAX          ((uint32)0x3)
/* Idle state  Position */
#define PWM_IDLESTATE_POS             (0x8U)
#define PWM_IDLESTATE_MAX             ((uint32)0x1)
/* Polarity Position */
#define PWM_POLSTATE_POS              (0x7U)
#define PWM_POLSTATE_MAX              ((uint32)0x1)
/* Idle state  Position */
#define PWM_COHERENCY_POS             (0x9U)
#define PWM_COHERENCY_MAX             ((uint32)0x1)

#if ( (PWM_FIXED_PERIOD_USED == STD_ON) || (PWM_SET_DUTY_CYCLE_API == STD_ON) )
/* Reference state Position */
#define PWM_ISREFERENCE_POS           (0x13U)

#define PWM_ISREFERENCE_MAX           ((uint32)0x1)

#endif /* (PWM_FIXED_PERIOD_USED == STD_ON) */

#if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
                              (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
/* Reference Channel Position */
#define PWM_REFERENCE_CHAN_POS        (12U)
/* lower 6-Bit mask to get the channel ID */
#define PWM_6BIT_MASK                 (0x3FU)

#endif

/* Assigned Hw unit Position */
#define PWM_HWUNIT_POS                ((uint8)(0x7f))

/* Not required for ChannelKind as it will be asserted during
   call of Pwm_Init() and Pwm_DeInit() functions */
#if  (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/* The following flags are used within
   Pwm_GlobChn variable, each bit position signifies
   a specific property
   */

/* Position of Notification Status Bit */
#define PWM_NOTIFI_STATUS_POS                 (4U)
/* Position of Notification edges */
#define PWM_NOTIFI_EDGE_POS                   (5)
/* Duty update Flag position */
#define PWM_DUTY_0_OR_100_UPDATE_FLGPOS     (7U)
/* No of Notification edge bits 
Value should not have subscript 'U' as it is used
in Mcal_SetAtomic.*/
#define PWM_NOTIFI_EDGE_BITS                  (2)
/*  Mask to obtain Notification Edge Position */
#define PWM_NOTIFICATION_EDGE_MASK            ((uint32)(0x00000060))
/* Mask to obtain Duty Update bit */
#define PWM_DUTY_0_OR_100_UPDATE_MASK         ((uint32)(0x00000080))
/* Mask to obtain Notification Status bit */
#define PWM_NOTIFI_STATUS_MASK                ((uint32)(0x00000010))

#define PWM_NO_NOTIFICATION             ((Pwm_17_Gtm_EdgeNotificationType)0)
/* Clear all pending interrupts */
#define PWM_CLR_PENDING_INTERRUPTS            (0x00000003UL)

#endif /* PWM_NOTIFICATION_SUPPORTED */

/* Duty update Flag position */
#define PWM_IDLE_CHANNEL_FLAG_POS             (8U)
/*  Mask to obtain Idle Status Position */
#define PWM_IDLE_STATUS_MASK                  ((uint32)(0x00000100))

#if ( (PWM_DUTY_SHIFT_IN_TICKS == STD_ON) ||  \
      (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
      (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON) \
    )
/* Maximum Timer Value */
#define PWM_MAX_TIMER          ((uint32)0xFFFFFE)
#define PWM_MAX_TIMER_TOM          ((uint32)0xFFFE)
#endif 
/* ( (PWM_DUTY_SHIFT_IN_TICKS == STD_ON) ||   
            (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || 
            (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
           ) */

#if ( (PWM_PB_FIXEDADDR == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) )
/* Status to indicate that PWM is initialized */
#define PWM_INITIALIZED                ((uint8)1)

#if (PWM_DE_INIT_API == STD_ON)
/* Status to indicate that PWM is de-initailized */
#define PWM_DEINITIALIZED              ((uint8)0)
#endif /* (PWM_DE_INIT_API == STD_ON) */

#endif /* (PWM_PB_FIXEDADDR == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) */

/* TOM Bit positions */
#define PWM_GTM_CTRL_SL             ((uint32)11)
#define PWM_GTM_CTRL_TRIGOUT        (24U)
#define PWM_GTM_CTRL_RST_CCU0       (20U)

/* Used for referring Pwm_17_Gtm_PropertyType */
#define PWM_SHIFTED_CHANNEL         (1U)
#define PWM_NORMAL_CHANNEL          (0U)  

#define PWM_IDLE_CHANNEL            (1U)

#define PWM_NON_COHERENT            (0U)
#define PWM_COHERENT                (1U)

/* PWM Channel ID's status bits, used to change the status os the channel */
#define PWM_CHAN_ID_STAT_BITS       (1)

#define PWM_CONST_32                (32U)
#define PWM_CONST_16                (16U)

#if  (PWM_NOTIFICATION_SUPPORTED == STD_ON)
#define PWM_CONST_3                 (3U)
#endif

#define PWM_CONST_2                 (2U)

#define PWM_INVALID_NUMBER (0xFFU)

/* Tgc global control register mask for Update Enable for Coherant update */
#define PWM_TGC_GLB_CTRL_MASK       (0x0000FFFFUL)

/******************************************************************************
**                      Private Macro like functions                         **
******************************************************************************/
/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/
/* Type for PwmPropery */
typedef struct 
  {
    unsigned_int Polarity:1;     /* PWM_POLARITY_HIGH or PWM_POLARITY_LOW */
    unsigned_int Coherency:1;    /* PWM_NON_COHERENT or PWM_COHERENT  */
    unsigned_int ChannelType:1;  /* PWM_SHIFTED_CHANNEL or PWM_NORMAL_CHANNEL*/
    unsigned_int IsReference:1;  /* PWM_REFERENCE_CHANNEL or 
                                    PWM_NOT_REFERENCE_CHANNEL */
    unsigned_int PreviousState:1;/* PWM_IDLE_CHANNEL or PWM_ACTIVE_CHANNEL  */
    unsigned_int Padding:3; 
    unsigned_int RefChannelId:8;
    unsigned_int Reserved:16;
  }Pwm_17_Gtm_PropertyType;

/******************************************************************************
**                      Private Function Declarations                        **
******************************************************************************/

#define PWM_17_GTM_START_SEC_CODE
#include "MemMap.h"


#if ((PWM_DEV_ERROR_DETECT == STD_ON)|| (PWM_SAFETY_ENABLE == STD_ON))
/* PWM003: */

/* To check DET errors in Pwm_Init API */
static uint32 Pwm_lInitDetCheck
(
  const Pwm_17_Gtm_ConfigType *DetConfigPtr
);

/* To verify on channel number passed */
static _INLINE_ uint32 Pwm_lVerChannel
(
  uint8 ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
);
/* To verify whether Init has been called or not */
static _INLINE_ uint32 Pwm_lVerUnInit
(
  uint8 ServiceID
);
/* To verify whether Init has been called or not and channel number passed */
static _INLINE_ uint32 Pwm_lVerUnInitAndChannel
(
  uint8 ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
);

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/* To verify Init called or not and whether proper period type */
static _INLINE_ uint32 Pwm_lVerUnInitChanAndPer
(
  uint8 ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
);
#endif 
/* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

#endif 
/* PWM_DEV_ERROR_DETECT */

/* To get absolute value as per period (used for edge aligned type ) */
static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalEdge
(
  Pwm_17_Gtm_PeriodType Period,
  uint32 Value
);

#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
/* To get absolute value as per period (used for Center and Shift Type) */
static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalShCen
(
  Pwm_17_Gtm_PeriodType Period,
  Pwm_17_Gtm_PeriodType Value
);
#endif 
/* Center and Shift type cells */


#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
/* To get scaled Shift Lead value */
static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetShiftLead
(
  Pwm_17_Gtm_PeriodType Period,
  Pwm_17_Gtm_PeriodType Shift
);
#endif

#if (PWM_VARIABLE_PERIOD_USED == STD_ON)
static void Pwm_lInitVariablePeriod
(
  uint8 CellUsed,
  uint32 ChannelNumber
);
#endif

#if (PWM_FIXED_PERIOD_USED == STD_ON)
static void Pwm_lInitFixedPeriod
(
  uint8 CellUsed,
  uint32 ChannelNumber
);
#endif
#if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
static void Pwm_lInitCentreAligned
(
  uint8 CellUsed,
  uint32 ChannelNumber
);
#endif
#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
static void Pwm_lInitFixedPeriodShifted
(
  uint8 CellUsed,
  uint32 ChannelNumber
);
#endif

#if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
/* To get Center Lead value */
static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetCenterLead
(
  Pwm_17_Gtm_PeriodType Period,
  Pwm_17_Gtm_PeriodType ScaledDuty
);
#endif


#if((PWM_DE_INIT_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || \
   (PWM_SET_DUTY_CYCLE_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
static void Pwm_lGtmStartChannel
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber, 
  uint32 Period, 
  uint32 Dutycycle, 
  uint32 Shift, 
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmStartTomChannel
(
  Pwm_ChannelIdentifierType GlobalChannelId, 
  uint32 Period, 
  uint32 Dutycycle, 
  uint32 Shift, 
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmStartAtomChannel
(
  Pwm_ChannelIdentifierType GlobalChannelId, 
  uint32 Period, 
  uint32 Dutycycle, 
  uint32 Shift, 
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmSLBitConfigStart
(
  Pwm_ChannelIdentifierType GlobalChannelId, 
  Pwm_17_Gtm_PropertyType PwmProperty
);
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
static boolean Pwm_lGtmGetOutputState
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber
);
#endif 
/* (PWM_GET_OUTPUT_STATE_API == STD_ON) */
static void Pwm_lGtmStartChannelsInit
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber, 
  uint32 Period, 
  uint32 Dutycycle, 
  uint32 Shift, 
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmTomChannelsInit
(
   Pwm_ChannelIdentifierType GlobalChannelId, 
   uint32 Period, 
   uint32 Dutycycle, 
   uint32 Shift, 
   Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmAtomChannelsInit
(
   Pwm_ChannelIdentifierType GlobalChannelId, 
   uint32 Period, 
   uint32 Dutycycle, 
   uint32 Shift, 
   Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmSLBitConfigInit
(
  Pwm_ChannelIdentifierType GlobalChannelId, 
  uint32 Dutycycle, 
  Pwm_17_Gtm_PropertyType PwmProperty
);

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

static void Pwm_lGtmIrqModify(Pwm_GlobalChannelNumberType GlobalChannelNumber, 
                         uint8 InterruptFlag);

#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

/* INLINE function to obtain the channel class */
static _INLINE_ Pwm_17_Gtm_ChannelClassType Pwm_lChanClass(uint32 Value);

/*
INLINE function to obtain the Idle state from PwmChannelInfo
*/
static _INLINE_ Pwm_17_Gtm_OutputStateType Pwm_lIdle(uint32 Value);

/*
INLINE function to obtain the Polarity from PwmChannelInfo
*/
static _INLINE_ uint8 Pwm_lPolarity(uint32  Value);

/*
INLINE function to obtain the Coherency from PwmChannelInfo
*/
static _INLINE_  Pwm_17_Gtm_OutputStateType Pwm_lCoherency(uint32 Value);

#if ((PWM_FIXED_PERIOD_USED == STD_ON)|| (PWM_SET_DUTY_CYCLE_API == STD_ON) )
/*
INLINE function to obtain the weather channel is being refered from 
PwmChannelInfo
*/
static _INLINE_ Pwm_17_Gtm_OutputStateType Pwm_lIsReference(uint32 Value);

#endif

/*
INLINE function to obtain the Assigned HW Unit from PwmChannelInfo
*/
static _INLINE_ uint8 Pwm_lAssignedHW(uint32 Value);

#if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
                             (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
/*
INLINE function to obtain the Reference channel Number from PwmChannelInfo
*/
static _INLINE_ Pwm_17_Gtm_ChannelType Pwm_lReferChan(uint32 Value);
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*
function to to Set the Notification status in the global channel variable.
*/
static _INLINE_ void Pwm_lSetNotificationStatus(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
function to Clear the Notification status in the global channel variable.
*/
static _INLINE_ void Pwm_lClearNotificationStatus(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
function to Set the Duty Notification status in the global channel variable.
*/
static _INLINE_ void Pwm_lSetDuty_0_Or_100_Status(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
function to clear the Duty Notification status in the global channel variable.
*/
static _INLINE_ void Pwm_lClearDuty_0_Or_100_Status(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
function to clear the Notification edges in the global channel variable.
*/
static _INLINE_ void Pwm_lClearNotificationEdges(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
function to set the Notification edges in the global channel variable.
*/
static _INLINE_ void Pwm_lSetNotificationEdges(
                                     Pwm_17_Gtm_ChannelType Channel,
                                     Pwm_17_Gtm_EdgeNotificationType Edge
                                     );
                                         
/*
function to get the Notification kind in the global channel variable.
*/
static _INLINE_ Pwm_17_Gtm_EdgeNotificationType 
                Pwm_lGetNotificationKind(Pwm_17_Gtm_ChannelType Channel);
                
#endif /* PWM_NOTIFICATION_SUPPORTED == STD_ON */

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/*
INLINE function to Set the idle status in the global channel variable.
*/
static _INLINE_ void Pwm_lSetChannelIdleStatus(Pwm_17_Gtm_ChannelType Channel);

#endif /* (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) */

#if((PWM_SET_DUTY_CYCLE_API == STD_ON)||(PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
/*
INLINE function to clear the Notification edges in the global channel variable.
*/
static _INLINE_ void Pwm_lClearIdleStatus(
                                     Pwm_17_Gtm_ChannelType Channel
                                     );

#endif
/*
INLINE function to get the idle status  from the global channel variable.
*/
static _INLINE_ uint32 Pwm_lGetChannelIdleStatus(
                                     Pwm_17_Gtm_ChannelType Channel
                                     );
                

static _INLINE_ uint32 Pwm_lGtmCounterVal
(
  uint32 Shift, 
  uint32 Period, 
  uint32 DutyCycle
);

/*Function to extract details like module number,module type...*/
static Pwm_ChannelIdentifierType Pwm_lGtmChannelIdentifier(
                               Pwm_GlobalChannelNumberType GlobalChannelNumber
                               );

#if (PWM_SAFETY_ENABLE == STD_ON)
/*Function to check the range of Duty cycle parameter passed*/
static _INLINE_ uint32 Pwm_lSafetyDutyRangeCheck(uint8           ServiceID,\
                                 Pwm_17_Gtm_ChannelType ChannelNumber,
                                 uint32          Duty
                                 );
/*Function to check the range of Period parameter passed*/
static _INLINE_ uint32 Pwm_lSafetyPeriodRangeCheck(
                             uint8           ServiceID,
                             Pwm_17_Gtm_ChannelType ChannelNumber,
                             Pwm_17_Gtm_PeriodType Period
                            );
/*Function to extract the channel type corresponding to channel number passed*/
static _INLINE_ uint8 Pwm_lFindChannelSignal (
                                      Pwm_17_Gtm_ChannelType ChannelNumber);
#endif

/*Function to extract the channel index corresponding to channel number passed*/
static _INLINE_ Pwm_17_Gtm_ChannelType Pwm_lFindChannelIndex (
                                      Pwm_17_Gtm_ChannelType ChannelNumber);


#define PWM_17_GTM_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************
**                      Global Constant Definitions                          **
******************************************************************************/
/******************************************************************************
**                      Global Variable Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Private Constant Definitions                         **
******************************************************************************/

/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/
/* To store the PWM driver configuration pointer */
#if (PWM_PB_FIXEDADDR == STD_OFF)
#define PWM_17_GTM_START_SEC_VAR_32BIT
#include "MemMap.h"
static const Pwm_17_Gtm_ConfigType *Pwm_kConfigPtr;
#define PWM_17_GTM_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#endif 
/* (PWM_PB_FIXEDADDR == STD_OFF)*/

#if (PWM_PB_FIXEDADDR == STD_ON)
#define PWM_17_GTM_START_SEC_CONST_32BIT
#include "MemMap.h"
static const Pwm_17_Gtm_ConfigType * const Pwm_kConfigPtr = &Pwm_ConfigRoot[0];
#define PWM_17_GTM_STOP_SEC_CONST_32BIT
#include "MemMap.h"

#if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
#define PWM_17_GTM_START_SEC_VAR_8BIT
#include "MemMap.h"
/* Driver Init Status Variable */
static uint8 Pwm_InitStatus;
#define PWM_17_GTM_STOP_SEC_VAR_8BIT
#include "MemMap.h"
#endif 
/* (PWM_DEV_ERROR_DETECT == STD_ON) */
#endif 
/* (PWM_PB_FIXEDADDR == STD_ON)*/


/*
 * Pwm_GlobChn is array of uint32 variable the length of this array depends on
 * the configured Maximum number of PWM channels.
 */
 /* To store or read Private PWM channel information */
/*
Bit 0,1,2 Pwm_Channelkind.
Bit 3   PWM_NOTIFICATION_STATUS (Notification is enabled Or Disable)
Bit 4,5 Pwm_NotificationAsked
( Edges configured by the user , Rising / Falling / Both)
Bit 6   Pwm_DutyNotifyFlag
( when user sets a duty of 0 % or 100 % , then calls
  Enable Notification, the notification should not be set
)
rest    reserved
*/
/* To store or read Private PWM channel information */
/* [cover parentID=DS_MCAL_SWSC_PWM_0910] [/cover]  */
#if (PWM_SAFETY_ENABLE == STD_ON)
#if (PWM_MAX_ASIL_CHANNELS != 0)
#define PWM_17_GTM_START_SEC_ASIL0_VAR_32BIT
#include "MemMap.h"
static uint32  Pwm_GlobChn_Asil[PWM_MAX_ASIL_CHANNELS];
#define PWM_17_GTM_STOP_SEC_ASIL0_VAR_32BIT
#include "MemMap.h"
#endif
#endif

#if (PWM_MAX_QM_CHANNELS != 0)

#define PWM_17_GTM_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"
static uint32  Pwm_GlobChn_Qm[PWM_MAX_QM_CHANNELS];
#define PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT
#include "MemMap.h"
#endif

#if (PWM_SAFETY_ENABLE == STD_ON)
#if (PWM_MAX_ASIL_CHANNELS != 0)
#define PWM_17_GTM_START_SEC_ASIL0_VAR_32BIT
#include "MemMap.h"
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
static uint32  Pwm_CurrentPeriodVal_Asil[PWM_MAX_ASIL_CHANNELS];
#endif 
/* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */
#define PWM_17_GTM_STOP_SEC_ASIL0_VAR_32BIT
#include "MemMap.h"
#endif
#endif

#if (PWM_MAX_QM_CHANNELS != 0)
#define PWM_17_GTM_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
static uint32  Pwm_CurrentPeriodVal_Qm[PWM_MAX_QM_CHANNELS];
#endif 
/* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */
#define PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT
#include "MemMap.h"
#endif
/******************************************************************************
**                      Global Function Definitions                          **
******************************************************************************/
#define PWM_17_GTM_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************
** Syntax : void Pwm_17_Gtm_Init(const Pwm_17_Gtm_ConfigType *ConfigPtr)     **
**                                                                           **
** Service ID:      0x00                                                     **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      non reentrant (PWM034:)                                  **
**                                                                           **
** Parameters (in): ConfigPtr - Expected valid address pointing to config    **
**                                                                           **
** Parameters (out):none                                                     **
**                                                                           **
** Return value:    none                                                     **
**                                                                           **
** Description : Driver Module Initialization (PWM007:)                      **
**               1.This function will initialize all relevant registers of   **
**                 configured hardware (Assigned_HW_Unit) with the values of **
**                 structure given by ConfigPtr.                             **
**               2. This service will disable all notifications.             **
**               3. Resources that are not configured in the configuration   **
**                  file will not be changed.                                **
**               4. This function shall initialize all internals variables   **
**               5. After initialization the PWM driver will start generate  **
**                  PWM signal(s) with the configured default values         **
**               6. Service should not be called during a running operation. **
**                REQ ID : PWM007, PWM062, PWM009, PWM052 PWM046, PWM051     **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM095] [/cover]                                    **
** [cover parentID=DS_AS_PWM007_PWM062] [/cover]                             **
** [cover parentID=DS_AS_PWM009a] [/cover]                                   **
** [cover parentID=DS_AS_PWM009b] [/cover]                                   **
** [cover parentID=DS_AS_PWM009c] [/cover]                                   **
** [cover parentID=DS_AS_PWM052] [/cover]                                    **
** [cover parentID=DS_AS_PWM064_1] [/cover]                                  **
** [cover parentID=DS_AS_PWM002a_PWM046] [/cover]                            **
** [cover parentID=DS_AS_PWM002e_PWM118_PWM121] [/cover]                     **
** [cover parentID=DS_AS_PWM051b_1] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_1] [/cover]                          **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_Init
(
  const Pwm_17_Gtm_ConfigType *ConfigPtr
)
{
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))

  /*Error flag is set*/
  uint8                              ErrStatus;
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  uint8                              CellUsed;
  Pwm_17_Gtm_ChannelType             ChannelNumber;
  Pwm_17_Gtm_ChannelClassType        ChannelKind;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; 
  /* ROM pointer */
  Pwm_17_Gtm_ChannelType             ChIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8                              ChSignal;
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif 
  /* PWM_DEV_ERROR_DETECT */

   #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: */
  /* PWM046 check for the validity of configPtr */
  if(PWM_ERROR_FOUND == (Pwm_lInitDetCheck(ConfigPtr)))
  {
    /* Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif 
  /* PWM_DEV_ERROR_DETECT */

  #if (PWM_SAFETY_ENABLE == STD_ON)
  /* Marker check for safety */
  if ((ErrStatus != E_NOT_OK) &&\
      (ConfigPtr->Marker != ((uint32)PWM_17_GTM_MODULE_ID << 16U)))
  {
    /* report to upper layer */
    ErrStatus = E_NOT_OK;
    SafeMcal_ReportError( 
                          PWM_17_GTM_MODULE_ID,
                          PWM_17_GTM_INSTANCE_ID, 
                          PWM_SID_INIT,
                          PWM_E_PARAM_CONFIG
                        );

  }
  #endif /*End Of PWM_SAFETY_ENABLE*/

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  
  if(ErrStatus == (uint8)E_OK)
    
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  {
    /* As per caveat Pwm_Init should not be called during running operation. */
    /* PWM007: Initialize all registers as per the configuration data. */
    #if (PWM_PB_FIXEDADDR == STD_OFF)
    /*PWM_PB_FIXEDADDR is STD_OFF : Assign ConfigPtr to the global variable*/
    Pwm_kConfigPtr = ConfigPtr;
    #endif 
    /* (PWM_PB_FIXEDADDR == STD_OFF) */
    /* Initialize PWM configured channel ROM pointer */
    LocalPwmChanPtr = Pwm_kConfigPtr->ChannelConfigPtr;
    /* Verify for the configured channels */
    for (
         ChannelNumber = (Pwm_17_Gtm_ChannelType)0;
         ChannelNumber < Pwm_kConfigPtr->MaxChannels;
         ChannelNumber++
        )
    {
      /* Extract Cell Number */
      CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
      /* Get the type of channel used */
      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
      ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
      #if (PWM_SAFETY_ENABLE == STD_ON)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      if (ChSignal == PWM_ASIL_TYPE)
      {
        #if (PWM_MAX_ASIL_CHANNELS != 0)

        Pwm_GlobChn_Asil[ChIndex]=(uint32)0U;
        Pwm_GlobChn_Asil[ChIndex] |= (uint32)ChannelKind;
        #endif
      }
      else 
      #endif
      {
        /* PWM012: Reset Notifications */
        /* Notification and status goes to zero */
      #if (PWM_MAX_QM_CHANNELS != 0)
        
        Pwm_GlobChn_Qm[ChIndex]=0U;
        /* PWM007: Store the type of channel used */
        Pwm_GlobChn_Qm[ChIndex] |= (uint32)ChannelKind;
        #endif
      }
      /* Requirements on PWM062: , PWM009:, PWM052: are taking care in the
         below
         calling local functions */
      switch (ChannelKind)
      {
        #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
        case PWM_VARIABLE_PERIOD:
        /* Variable Period */
          Pwm_lInitVariablePeriod(CellUsed,ChannelNumber);
          break;
        #endif
        #if (PWM_FIXED_PERIOD_USED == STD_ON)
        case PWM_FIXED_PERIOD:
          /* Fixed Period */
          Pwm_lInitFixedPeriod(CellUsed,ChannelNumber);
          break;
        #endif
        #if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
        case PWM_FIXED_PERIOD_SHIFTED:
          Pwm_lInitFixedPeriodShifted(CellUsed,ChannelNumber);
          break;
        #endif
        default:
        #if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
          /* Fixed Period shifted : Additional 3 cells :
              reference to a 4 cell fixed period solution*/
          Pwm_lInitCentreAligned(CellUsed,ChannelNumber);
        #endif
        break;
      }
      /* End of Switch condition */
      
      /* Setup Output to LOW or High Depending on Polarity (Duty start)
        for timer cell */
      /* Increase the Pwm channel pointer */
      LocalPwmChanPtr++;
    }
    /* End of for loop in Pwm_Init() function */
    #if ( (PWM_PB_FIXEDADDR == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) )
    /* Set Status to indicate that initialization is done */
    Pwm_InitStatus = PWM_INITIALIZED;
    #endif 
    /*(PWM_PB_FIXEDADDR == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON)*/
  }
  return;
} /* End of Pwm_17_Init API */

/* Bugzilla 11769 , configuration for Pwm_DeInit API */
#if (PWM_DE_INIT_API == STD_ON) /* PWM080 */
/******************************************************************************
** Syntax : void Pwm_17_Gtm_DeInit(void)                                     **
**                                                                           **
** Service ID: 0x01                                                          **
**                                                                           **
** Sync/Async:Synchronous                                                    **
**                                                                           **
** Reentrancy:non reentrant (PWM034:)                                        **
**                                                                           **
** Parameters (in): none                                                     **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:none                                                         **
**                                                                           **
** Description : Service for PWM De-Initialization PWM010:                   **
**               1.After the call of this service, the state of the used     **
**                 peripherals/registers will set to power on reset state.   **
**               2.This service will disable all used interrupts and         **
**                  notifications.                                           **
**               3.This service clear all pending interrupt flags            **
**               4.All global variables will get reset                       **
**               5.All channel output signal state will set to Idle State    **
**               Req Id's: PWM010, PWM011, PWM012 , PWM044, PWM051           **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM096] [/cover]                                    **
** [cover parentID=DS_AS_PWM010] [/cover]                                    **
** [cover parentID=DS_AS_PWM011] [/cover]                                    **
** [cover parentID=DS_AS_PWM012] [/cover]                                    **
** [cover parentID=DS_AS_PWM080a_PWM080b] [/cover]                           **
** [cover parentID=DS_AS_PWM064_2] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_1] [/cover]                          **
** [cover parentID=DS_AS_PWM051b_2] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_2] [/cover]                          **
**                                                                           **
******************************************************************************/
/*PWM010 Service for Pwm_Deinitialization */
void Pwm_17_Gtm_DeInit(void)
{
  /* Local variables */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  uint8                       ErrStatus;
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  uint8               CellUsed;
  Pwm_17_Gtm_ChannelType      ChannelNumber;
  Pwm_17_Gtm_OutputStateType  IdleState;
  uint32               Duty;
  Pwm_17_Gtm_PeriodType               Period;
  Pwm_17_Gtm_PeriodType               ScaledDuty;
  Pwm_17_Gtm_PeriodType               ScaledShiftVal;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; 
  /* ROM pointer */
  Pwm_17_Gtm_PropertyType PwmProperty;

  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
       (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
  Pwm_17_Gtm_ChannelClassType ChannelKind;
  Pwm_17_Gtm_ChannelType     MainChannel;
  #endif
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  Pwm_ChannelIdentifierType GlobalChannelId;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  ErrStatus = (uint8)E_OK;
  #endif 
  /* PWM_DEV_ERROR_DETECT */

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* PWM003: */
  if (PWM_ERROR_FOUND == Pwm_lVerUnInit(PWM_SID_DEINIT))
  {
    /* PWM051: Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  if(ErrStatus == (uint8)E_OK)
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize PWM configured channel ROM pointer */
    LocalPwmChanPtr = Pwm_kConfigPtr->ChannelConfigPtr;
    /* Verify for the configured channels */
    for ( ChannelNumber = (Pwm_17_Gtm_ChannelType)0;
          ChannelNumber < Pwm_kConfigPtr->MaxChannels;
          ChannelNumber++
        )
    {
      ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
      #if (PWM_SAFETY_ENABLE == STD_ON)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      if (ChSignal == PWM_ASIL_TYPE)
      {
        #if (PWM_MAX_ASIL_CHANNELS != 0)

        Pwm_GlobChn_Asil[ChIndex]=(uint32)0;

        #endif
      }
      else
      #endif
      {
        /* Reset all used global variable to zero */
        /* PWM012 : Notification should be cleared */
      #if (PWM_MAX_QM_CHANNELS != 0)

        Pwm_GlobChn_Qm[ChIndex]=(uint32)0;

        #endif
      }
      #if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
      /* Clear all the previous period values */
      ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
      #if (PWM_SAFETY_ENABLE == STD_ON)
      #if (PWM_MAX_ASIL_CHANNELS != 0)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      if (ChSignal == PWM_ASIL_TYPE)
      {
        Pwm_CurrentPeriodVal_Asil[ChIndex] = 0UL;
      }
      else
      #endif
      #endif
      {
        #if (PWM_MAX_QM_CHANNELS != 0)
        Pwm_CurrentPeriodVal_Qm[ChIndex] = 0UL;
        #endif
      }
      #endif /* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */
      /* Extract Cell Number */
      CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);

      /* PWM011: Make output immediate to Idle state */
      /* 100% duty with Polarity and 0 % duty with opposite of polarity
         will make the output to given Idlestate */
      PwmProperty.Coherency = 0x0U;
      PwmProperty.ChannelType = 0x0U;
      PwmProperty.IsReference = 0x0U;
      PwmProperty.PreviousState = 0x0U;
      PwmProperty.RefChannelId = 0x0U;

      /* Extract IdleState */
      IdleState = Pwm_lIdle(LocalPwmChanPtr->ChannelInfo);
      PwmProperty.Polarity  = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
      
      #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
           (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
      if ((ChannelKind == PWM_FIXED_PERIOD_SHIFTED) || \
           (ChannelKind == PWM_FIXED_PERIOD_CENTER_ALIGNED))
      {
        MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
        /* Get main period */
        Period =((Pwm_kConfigPtr->ChannelConfigPtr)+MainChannel)->PeriodDefault;
      }
      else
      #endif
      {
        /* Get period and duty cycles */
        Period = LocalPwmChanPtr->PeriodDefault;
      }
      
      /* Initialize  Duty as 100 % */
      #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
       GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
      if(GlobalChannelId.ModuleId==GTM_TOM_MODULE)
      Duty = (uint32)PWM_MAX_TIMER_TOM;
      else
      Duty = (uint32)PWM_MAX_TIMER;
      #else
      Duty = PWM_MAX_DUTY;
      #endif
      if (IdleState != PwmProperty.Polarity)
      {
        /* Idlestate and Polarity mismatches then 0 % duty desired */
        Duty = 0U;
      }
      /* Get Scale value of Duty according to period */
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)Duty);
      ScaledShiftVal = 0U;
      Pwm_lGtmStartChannel
                   (CellUsed,Period,ScaledDuty,ScaledShiftVal,PwmProperty);

      /* Increment Global channel ROM pointer */
      LocalPwmChanPtr++;
    }
    /* End of for loop in Pwm_DeInit() function */
    #if (PWM_PB_FIXEDADDR == STD_OFF)
    /*PWM_PB_FIXEDADDR is STD_OFF : Clear ConfigPtr */
    Pwm_kConfigPtr = NULL_PTR;
    #else
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Clear the Status to indicate that Deinitialization is done */
    Pwm_InitStatus = PWM_DEINITIALIZED;
    #endif 
    /* (PWM_DEV_ERROR_DETECT == STD_ON */
    #endif 
    /* (PWM_PB_FIXEDADDR == STD_OFF) */
    }
  return;
}
/* End of Pwm_17_Gtm_DeInit API */
#endif 
/* PWM_DE_INIT_API */

#if (PWM_SET_DUTY_CYCLE_API == STD_ON) /* PWM082 */
/******************************************************************************
** Syntax : void Pwm_17_Gtm_SetDutyCycle(                                    **
**                            Pwm_17_Gtm_ChannelType ChannelNumber,          **
**                                uint16*             DutyCycle)             **
**    *Duty cycle is uint32 if DutyCycle is given in ticks                   **
** Service ID:0x02                                                           **
**                                                                           **
** Sync/Async:Synchronous                                                    **
**                                                                           **
** Reentrancy:reentrant                                                      **
**                                                                           **
** Parameters (in): ChannelNumber : Numeric identifier of the PWM channel    **
**                   DutyCycle     : To set Duty Cycle for a PWM channel     **
**                                   PWM059:Min=0x0000 Max=0x8000            **
**                                                                           **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value: none                                                        **
**                                                                           **
** Description : Service to set Duty cycle PWM013:                           **
**               1.This service will allow to set the duty cycle of the PWM  **
**                 channel.                                                  **
**               2.If the duty cycle = 0% (value=0x0000), then the PWM output**
**                 state will set to opposite level of polarity.             **
**               3.If the duty cycle=100% (value=0x8000), then the PWM output**
**                 state will set to polarity level.                         **
**               4.If the duty cycle>100%(value>0x8000), then the PWM output **
**                 will be undefined behavior (recommended that, user not to **
**                 provide this range of value)                              **
**               5 If the duty cycle >0% and <100%,then the PWM output will  **
**                 set to active state according to duty cycle and period    **
**                 parameters , polarity state.                              **
**               6.Dependency on PWM_DUTYCYCLE_UPDATED_ENDPERIOD config      **
**                 parameter.                                                **
**                 REq's: PWM013, PWm014, PWM016, PWm017, PWM058, PWM059     **
**                        PWM018, PWM044, PWM047, PWM051                     **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM097_PWM058] [/cover]                             **
** [cover parentID=DS_AS_PWM013] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_1] [/cover]                                  **
** [cover parentID=DS_AS_PWM014] [/cover]                                    **
** [cover parentID=DS_AS_PWM016] [/cover]                                    **
** [cover parentID=DS_AS_PWM017] [/cover]                                    **
** [cover parentID=DS_AS_PWM018] [/cover]                                    **
** [cover parentID=DS_AS_PWM064_3] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_2] [/cover]                          **
** [cover parentID=DS_AS_PWM051b_3] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_3] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_1] [/cover]                          **
** [cover parentID=DS_AS_PWM082a_PWM082b] [/cover]                           **
** [cover parentID=DS_MCAL_SWSC_PWM_0911_a] [/cover]                         **
**                                                                           **
******************************************************************************/
#if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
void Pwm_17_Gtm_SetDutyCycle
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  uint16          DutyCycle
)
#else
void Pwm_17_Gtm_SetDutyCycle
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  uint32          DutyCycle
)
#endif
{

  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  uint8                       CellUsed;
  Pwm_17_Gtm_ChannelClassType        ChannelKind;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; 
  /* ROM pointer */
  Pwm_17_Gtm_PropertyType PwmProperty; 
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  uint32                      Maxtime;
  #endif
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON) 
  Pwm_ChannelIdentifierType GlobalChannelId;
  #endif/* Structure to get Module info  */
  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
       (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
  Pwm_17_Gtm_ChannelType             MainChannel;
  #endif
  
        #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
    Pwm_17_Gtm_ChannelType             ChIndex;
        #endif
  
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  uint8                              ChSignal;
  #endif
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif /* PWM_DEV_ERROR_DETECT */
   /* PWM013: Service to Set the Duty Cycle */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON)) 
  /* PWM003: */
  if (PWM_ERROR_FOUND == 
            Pwm_lVerUnInitAndChannel(PWM_SID_SETDUTY, ChannelNumber))
  {
    /* Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif 
  /* PWM_DEV_ERROR_DETECT */

  #if (PWM_SAFETY_ENABLE == STD_ON)
  if(ErrStatus == (uint8)E_OK)
  {
    if (PWM_ERROR_FOUND == Pwm_lSafetyDutyRangeCheck(
              PWM_SID_SETDUTY,ChannelNumber,(uint32)DutyCycle))
    {
      /* Return without executing any of functionality */
      ErrStatus = (uint8)E_NOT_OK;
    }
  }
  #endif 
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif 
  /* PWM_DEV_ERROR_DETECT and PWM_SAFETY_ENABLE*/

  {
    /* Initialize PWM configured channel ROM pointer */
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Don't provide notification, if Duty asked for 0% or 100% */

    #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
    GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
    if (GlobalChannelId.ModuleId==GTM_TOM_MODULE)
    {
      Maxtime = PWM_MAX_TIMER_TOM;
    }
    else
    {
      Maxtime = PWM_MAX_TIMER;
    }
    #else
    Maxtime = PWM_MAX_DUTY;
    #endif
    if ( (DutyCycle == 0U) || (DutyCycle == Maxtime) )
    {
      Pwm_lClearNotificationStatus(ChannelNumber);
      Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
    }
    else
    {
      /* See whether notification was asked earlier */
      if ( Pwm_lGetNotificationKind(ChannelNumber) != PWM_NO_NOTIFICATION )
      {
        Pwm_lSetNotificationStatus(ChannelNumber);
      }
      Pwm_lClearDuty_0_Or_100_Status(ChannelNumber);
    }
    #endif 
    /* PWM_NOTIFICATION_SUPPORTED */
    
    ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
   
    /* Setup Output to LOW or HIGH Depending on Polarity (Duty start)
       for timer cell */
    PwmProperty.Coherency = 0x0U;
    PwmProperty.ChannelType = 0x0U;
    PwmProperty.PreviousState = 0x0U;
    PwmProperty.RefChannelId = 0x0U;
    PwmProperty.Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
    PwmProperty.IsReference  = Pwm_lIsReference(LocalPwmChanPtr->ChannelInfo);
    
    /* Get the coherency */
    #if(PWM_DUTYCYCLE_UPDATED_ENDPERIOD == STD_OFF)
    PwmProperty.Coherency = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
    #else
    PwmProperty.Coherency = PWM_COHERENT;
    #endif
    ShiftVal = 0U;
    #if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_OFF)
    ScaledDuty = 0U;
    Period = 0U;
    #endif 
 
    #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
    #if (PWM_SAFETY_ENABLE == STD_ON)
    #if ((PWM_MAX_ASIL_CHANNELS == 0) || (PWM_MAX_QM_CHANNELS == 0))
    Period = LocalPwmChanPtr->PeriodDefault;
    #endif
    #endif
    #endif
    
    /* (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_OFF) */
    switch (ChannelKind)
    {
      #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
      case PWM_VARIABLE_PERIOD:
      ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
      #if (PWM_SAFETY_ENABLE == STD_ON)
      #if (PWM_MAX_ASIL_CHANNELS != 0)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      if (ChSignal == PWM_ASIL_TYPE)
      {
        Period = Pwm_CurrentPeriodVal_Asil[ChIndex] ;
      }
      else
      #endif
      #endif
      {
        #if (PWM_MAX_QM_CHANNELS != 0)
        Period = Pwm_CurrentPeriodVal_Qm[ChIndex];
        #endif
      }
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
      break;
      #endif
      #if (PWM_FIXED_PERIOD_USED == STD_ON)
      case PWM_FIXED_PERIOD:
       /* Variable Period */
      Period = LocalPwmChanPtr->PeriodDefault;
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
      break;
      #endif
      #if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
      case PWM_FIXED_PERIOD_SHIFTED:
      PwmProperty.ChannelType = PWM_SHIFTED_CHANNEL;
      MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
      /* Get main period */
      Period = 
             ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;
      /* Get Scale value of Duty according to period */
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
      /* Get the Shift lead value */
      ShiftVal = 
        (uint32)Pwm_lGetShiftLead(Period, 
                         (Pwm_17_Gtm_PeriodType)(LocalPwmChanPtr->ShiftValue));
      break;
      #endif
      default:
      #if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
       /* Fixed Period shifted : Additional 3 cells :
           reference to a 4 cell fixed period solution*/
      PwmProperty.ChannelType = PWM_SHIFTED_CHANNEL;
      MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
      /* Get main period */
      Period = 
           ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;
      /* Get Scale value of Duty according to period */
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
      /* Get the Shift lead value */
      ShiftVal = (uint32)Pwm_lGetCenterLead(Period, ScaledDuty);
      #endif
      break;
    }/* End of Switch condition */
    /* Updated the previous state */
    if(Pwm_lGetChannelIdleStatus(ChannelNumber) != 0U)
    {
      PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
      /* Set the Channel Status to Idle */
      Pwm_lClearIdleStatus(ChannelNumber);
    }
    Pwm_lGtmStartChannel(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);
  }
  return;
}
/* End of Pwm_17_Gtm_SetDutyCycle() function */
#endif 
/* PWM_SET_DUTY_CYCLE_API */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) 
 /* PWM083 */
/******************************************************************************
** Syntax : void Pwm_17_Gtm_SetPeriodAndDuty(                                **
**                                   Pwm_17_Gtm_ChannelType ChannelNumber,   **
**                                    Pwm_17_Gtm_PeriodType  Period,         **
**                                    uint16*             DutyCycle)         **
**               *DutyCycle is uint32 if DutyCycle is given in ticks         **
**                                                                           **
** Service ID: 0x03                                                          **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: reentrant                                                     **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                   Period        : Period of the PWM signal                **
**                   DutyCycle     : To set Duty Cycle for a PWM channel     **
**                                  PWM059:Min=0x0000 Max=0x8000             **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : Service to set period and Duty cycle (PWM019:)              **
**               1.This service will allow to set the Period and duty cycle  **
**                 of the PWM channel.                                       **
**               2.Valid only for variable period                            **
**               3.If the duty cycle=0% (value=0x8000), then the PWM output  **
**                 state will set to opposite of Polarity level.             **
**               4.If the duty cycle=100% (value=0x8000), then the PWM       **
**                 output state will set to Polarity level.                  **
**               5.If the duty cycle>100%(value>0x8000), then the PWM output **
**                 will be undefined behavior (recommended that, user not to **
**                 provide this range of value)                              **
**               6 If the duty cycle >0% and <100%,then the PWM output will  **
**                 set to active state according to duty cycle and period    **
**                 parameters Polarity state.                                **
**               7.To scale the duty cycle passed period  will be used       **
**                 Req's: PWM019, PWM076, PWM020, PWM041, PWM060             **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM098] [/cover]                                    **
** [cover parentID=DS_AS_PWM019] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_2] [/cover]                                  **
** [cover parentID=DS_AS_PWM076] [/cover]                                    **
** [cover parentID=DS_AS_PWM020] [/cover]                                    **
** [cover parentID=DS_AS_PWM064_4] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_3] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_2] [/cover]                          **
** [cover parentID=DS_AS_PWM002d_PWM045] [/cover]                            **
** [cover parentID=DS_AS_PWM041] [/cover]                                    **
** [cover parentID=DS_AS_PWM083a_PWM083b] [/cover]                           **
** [cover parentID=DS_AS_PWM051b_4] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_4] [/cover]                          **
** [cover parentID=DS_MCAL_SWSC_PWM_0911_b] [/cover]                         **
**                                                                           **
******************************************************************************/
#if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
void Pwm_17_Gtm_SetPeriodAndDuty
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  Pwm_17_Gtm_PeriodType  Period,
  uint16    DutyCycle
)
#else
/*Duty cycle is uint32 when duty is given in ticks*/
void Pwm_17_Gtm_SetPeriodAndDuty
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  Pwm_17_Gtm_PeriodType  Period,
  uint32    DutyCycle
)
#endif
{
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  uint8                       CellUsed;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
   /* ROM pointer */
  Pwm_17_Gtm_PropertyType            PwmProperty; 
  uint32                      ScaledDuty;
  uint32                      ScaledShiftValue;
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  uint32                      Maxtime;
  #endif
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON) 
  Pwm_ChannelIdentifierType GlobalChannelId;
  #endif
  Pwm_17_Gtm_ChannelType             ChIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  uint8                              ChSignal;
  #endif
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif 
  /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON)) 
  /* PWM003: PWM041: */
  if (PWM_ERROR_FOUND ==
        ( Pwm_lVerUnInitChanAndPer( PWM_SID_SET_PERIOD_DUTY,ChannelNumber ))
     )
  {
    /* PWM051: Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #if (PWM_SAFETY_ENABLE == STD_ON)
  if (ErrStatus == (uint8)E_OK)
  {
    if (PWM_ERROR_FOUND == Pwm_lSafetyDutyRangeCheck(
                      PWM_SID_SET_PERIOD_DUTY,ChannelNumber,(uint32)DutyCycle))
    {
      /* PWM051: Return without executing any of functionality */
      ErrStatus = (uint8)E_NOT_OK;
    }
    else if (PWM_ERROR_FOUND ==
      Pwm_lSafetyPeriodRangeCheck(PWM_SID_SET_PERIOD_DUTY,ChannelNumber,Period))
    {
        /* PWM051: Return without executing any of functionality */
        ErrStatus = (uint8)E_NOT_OK;
    }
    else
    {
       ; /*Added to avoid misra warning*/
    }
  }
  #endif 
  #endif 
  /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize PWM configured channel ROM pointer */
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Don't provide notification, if Duty asked for 0% or 100% */
    #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)    
    GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
    if(GlobalChannelId.ModuleNo==GTM_TOM_MODULE)
    Maxtime = PWM_MAX_TIMER_TOM;
    else
    Maxtime = PWM_MAX_TIMER;
    #else
    Maxtime = PWM_MAX_DUTY;
    #endif

    if ( (DutyCycle == 0U) || (DutyCycle == Maxtime) )
    {
      Pwm_lClearNotificationStatus(ChannelNumber);
      Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
    }
    else
    {
      /* See whether notification was asked earlier */
      if ( Pwm_lGetNotificationKind(ChannelNumber) != PWM_NO_NOTIFICATION )
      {
        Pwm_lSetNotificationStatus(ChannelNumber);
      }
      Pwm_lClearDuty_0_Or_100_Status(ChannelNumber);
    }
    #endif/* PWM_NOTIFICATION_SUPPORTED */
    /* Extract Cell number */
    PwmProperty.Coherency = 0x0U;
    PwmProperty.ChannelType = 0x0U;
    PwmProperty.IsReference = 0x0U;
    PwmProperty.PreviousState = 0x0U;
    PwmProperty.RefChannelId = 0x0U;

    PwmProperty.Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
    /* Get the coherency */
    #if(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_OFF)
    PwmProperty.Coherency = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
    #else
    PwmProperty.Coherency = PWM_COHERENT;
    #endif
    /* Get Scale value of Duty according to period */
    ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
    #if (PWM_SAFETY_ENABLE == STD_ON)
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
    if (ChSignal == PWM_ASIL_TYPE)
    {
      Pwm_CurrentPeriodVal_Asil[ChIndex] = Period;
    }
    else
    #endif
    #endif
    {
      #if (PWM_MAX_QM_CHANNELS != 0)
      Pwm_CurrentPeriodVal_Qm[ChIndex] = Period;
      #endif
    }

    ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
    ScaledShiftValue = 0U;

    /* Updated the previous state */
    if(Pwm_lGetChannelIdleStatus(ChannelNumber) != 0U)
    {
      PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
      /* Set the Channel Status to Idle */
      Pwm_lClearIdleStatus(ChannelNumber);
    }
    Pwm_lGtmStartChannel
                      (CellUsed,Period,ScaledDuty,ScaledShiftValue,PwmProperty);
  }
  return;
}
/* End of Pwm_17_Gtm_SetPeriodAndDuty() function */
#endif 
/* PWM_SET_PERIOD_AND_DUTY_API */


#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) 
/* PWM084 */
/******************************************************************************
** Syntax : void Pwm_17_Gtm_SetOutputToIdle                                  **
**                              (Pwm_17_Gtm_ChannelType ChannelNumber)       **
**                                                                           **
** Service ID: 0x04                                                          **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: reentrant                                                     **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : Service for to set PWM output to Idle State PWM021:         **
**               1.This API will be useful to set out to Idle immediately and**
**                 during emergency condition                                **
**               Req: PWM021, PWM048, PWM045, PWM047, PWM044, PWM051         **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM099] [/cover]                                    **
** [cover parentID=DS_AS_PWM021] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_3] [/cover]                                  **
** [cover parentID=DS_AS_PWM064_5] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_4] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_3] [/cover]                          **
** [cover parentID=DS_AS_PWM086a] [/cover]                                   **
** [cover parentID=DS_AS_PWM086b] [/cover]                                   **
** [cover parentID=DS_AS_PWM084a_PWM084b] [/cover]                           **
** [cover parentID=DS_AS_PWM119] [/cover]                                    **
** [cover parentID=DS_AS_PWM051b_5] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_5] [/cover]                          **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_SetOutputToIdle
(
  Pwm_17_Gtm_ChannelType ChannelNumber
)
{
  /*PWM021 : Service to set the Output state */
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  uint8              CellUsed;
  Pwm_17_Gtm_OutputStateType IdleState;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ScaledShiftValue;
  Pwm_17_Gtm_PropertyType     PwmProperty;
  uint32                      Duty;
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  Pwm_ChannelIdentifierType GlobalChannelId;
  #endif
  /* Local pointers */
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; 
  /* ROM pointer */
  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
       (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
  Pwm_17_Gtm_ChannelClassType  ChannelKind;
  Pwm_17_Gtm_ChannelType       MainChannel;
  #endif

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON)) 
  /* PWM003: PWM048: */
  if ( PWM_ERROR_FOUND == 
             Pwm_lVerUnInitAndChannel(PWM_SID_SETOP2IDLE,ChannelNumber) )
  {
    /*PWM051 : return on any errors found */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize ROM pointer */
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;

    /* Extract Cell number */
    CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
    
    /* Store OCM value */
    IdleState = Pwm_lIdle(LocalPwmChanPtr->ChannelInfo);
    
    /* Setup Output to LOW or High Depending on Polarity (Duty start)
       for timer cell */
    PwmProperty.IsReference = 0x0U;
    PwmProperty.RefChannelId = 0x0U;

    PwmProperty.Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
    PwmProperty.Coherency = PWM_NON_COHERENT;
    
    #if (PWM_FIXED_PERIOD_USED == STD_ON)
    PwmProperty.IsReference  = Pwm_lIsReference(LocalPwmChanPtr->ChannelInfo);
    #endif
    
    PwmProperty.PreviousState = 0U;
    PwmProperty.ChannelType  = PWM_NORMAL_CHANNEL;
    
    #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
         (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
    /* Get the type of channel used */
    ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);

    if ((ChannelKind == PWM_FIXED_PERIOD_SHIFTED) || \
        (ChannelKind == PWM_FIXED_PERIOD_CENTER_ALIGNED))
    {
      MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
      /* Get main period */
      Period = ((Pwm_kConfigPtr->ChannelConfigPtr)+MainChannel)->PeriodDefault;
      PwmProperty.ChannelType = PWM_SHIFTED_CHANNEL;
    }
    else
    #endif
    {
      /* Get period and duty cycles */
      Period = LocalPwmChanPtr->PeriodDefault;
    }

    /* Initialize  Duty as 100 % */
    #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)   
    GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
    if(GlobalChannelId.ModuleNo==GTM_TOM_MODULE)
    {
      Duty = (uint32)PWM_MAX_TIMER_TOM;
    }
    else
    {
      Duty = (uint32)PWM_MAX_TIMER;
    }
    #else
    Duty = (uint32)PWM_MAX_DUTY;
    #endif
    if (IdleState != PwmProperty.Polarity)
    {
      /* Idlestate and Polarity mismatches then 0 % duty desired */
      Duty = 0U;
    }

    /* Get Scale value of Duty according to period */
    ScaledDuty = Pwm_lGetAbsvalEdge(Period,(uint32) Duty);
    ScaledShiftValue = 0U;
    Pwm_lGtmStartChannel
                     (CellUsed,Period,ScaledDuty,ScaledShiftValue,PwmProperty);

    /* PWM011: Make output immediate to Idle state */
    /* 100% duty with Polarity and 0 % duty with opposite of polarity
      will make the output to given Idlestate */
    /* Set Duty value to zero %age */
    
    /* Set the Channel Status to Idle */
    Pwm_lSetChannelIdleStatus(ChannelNumber);
  }
  return;
}/* End of Pwm_17_Gtm_SetOutputToIdle() function */
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


#if (PWM_GET_OUTPUT_STATE_API == STD_ON)  /* PWM085 */
/******************************************************************************
** Syntax : Pwm_17_Gtm_OutputStateType Pwm_17_Gtm_GetOutputState             **
**                                    (Pwm_17_Gtm_ChannelType ChannelNumber) **
**                                                                           **
** Service ID:  0x05                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  reentrant                                                    **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     Pwm_17_Gtm_OutputStateType                              **
**                                                                           **
** Description : Service to read the PWM output state                        **
**               1.If development error detection is enabled and an error is **
**                  detected the service returns PWM_LOW.                    **
**               2.Output state of a PWM channel. Note that this will be read**
**            from the output state on the TOM/ATOM Channel (Assigned_HwUnit)**
**                 connected to the port pin. This will not be read directly **
**                 from the Port Pin. However both will be the same          **
**               Req: PWM022, PWM044, PWm047, PWM051                         **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM100] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_4] [/cover]                                  **
** [cover parentID=DS_AS_PWM064_6] [/cover]                                  **
** [cover parentID=DS_AS_PWM051c] [/cover]                                   **
** [cover parentID=DS_AS_PWM002b_PWM117_5] [/cover]                          **
** [cover parentID=DS_AS_PWM022] [/cover]                                    **
** [cover parentID=DS_AS_PWM002c_PWM047_4] [/cover]                          **
** [cover parentID=DS_AS_PWM085a_PWM085b] [/cover]                           **
** [cover parentID=DS_AS_PWM119] [/cover]                                    **
** [cover parentID=DS_AS_PWM051b_6] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_6] [/cover]                          **
**                                                                           **
******************************************************************************/
Pwm_17_Gtm_OutputStateType Pwm_17_Gtm_GetOutputState  
                               (Pwm_17_Gtm_ChannelType ChannelNumber)
{
  /* Local variables */
  /* Service to get the Output State */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif 
  /* PWM_DEV_ERROR_DETECT */
  uint8              CellUsed;
  Pwm_17_Gtm_OutputStateType ReturnState;

  /* Local pointers */
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; 
  /* ROM pointer */

  
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ReturnState = (Pwm_17_Gtm_OutputStateType)STD_LOW;
  ErrStatus = (uint8)E_OK;
  #endif 
  /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
    /* PWM003: */
  if ( PWM_ERROR_FOUND == Pwm_lVerUnInitAndChannel( PWM_SID_GETOPSTATE,
                                                       ChannelNumber )
     )
  {
    /* In this case, we can satisfy returning of
       PWM_LOW as per PWM051: */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize ROM pointer */
    LocalPwmChanPtr =  (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    /* Extract Cell number */
    CellUsed = Pwm_lAssignedHW( LocalPwmChanPtr->ChannelInfo );
  
    ReturnState = Pwm_lGtmGetOutputState(CellUsed);
  }
  /*  Just return the Current State */
  return (ReturnState);
}/* End of Pwm_17_Gtm_GetOutputState API */
#endif /* PWM_GET_OUTPUT_STATE_API */


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/******************************************************************************
** Syntax : void Pwm_17_Gtm_DisableNotification                              **
**                                  (Pwm_17_Gtm_ChannelType ChannelNumber)   **
**                                                                           **
** Service ID: 0x06                                                          **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: reentrant                                                     **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : This service will disable all PWM signal notifications of   **
**               this channel. (PWM023:)                                     **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM101] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_5] [/cover]                                  **
** [cover parentID=DS_AS_PWM023] [/cover]                                    **
** [cover parentID=DS_AS_PWM112a_PWM112b_PWM115b] [/cover]                   **
** [cover parentID=DS_AS_PWM064_7] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_6] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_5] [/cover]                          **
** [cover parentID=DS_AS_PWM051b_7] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_7] [/cover]                          **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_DisableNotification(Pwm_17_Gtm_ChannelType ChannelNumber)
{
  /* PWM023 : Service to disable the notifications */
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif /* PWM_DEV_ERROR_DETECT */
  uint8               CellUsed;
  /* Local pointers */
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
    /* PWM003: */
  if ( PWM_ERROR_FOUND == Pwm_lVerUnInitAndChannel( PWM_SID_DISABLENOTIFI,
                                                      ChannelNumber )
     )
  {
    /* Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize PWM configured channel ROM pointer */
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    /* Extract Cell number */
    CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);

    Pwm_lGtmIrqModify(CellUsed,0U);
    /* Disable Notification */
    Pwm_lClearNotificationStatus(ChannelNumber);
    /* Reset notification edges */
    Pwm_lClearNotificationEdges(ChannelNumber);

  }

}/* End of Pwm_17_Gtm_DisableNotification() function */

/******************************************************************************
** Syntax : void Pwm_17_Gtm_EnableNotification(                              **
**                               Pwm_17_Gtm_ChannelType       ChannelNumber, **
**                               Pwm_17_Gtm_EdgeNotificationType Notification**
**                               )                                           **
** Service ID: 0x07                                                          **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: reentrant                                                     **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                   Notification  : PWM_RISING_EDGE or                      **
**                                   PWM_FALLING_EDGE or                     **
**                                   PWM_BOTH_EDGES                          **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : This service will enable the PWM signal notification        **
**               according to notification parameter. PWM024:                **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM102] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_6] [/cover]                                  **
** [cover parentID=DS_AS_PWM024] [/cover]                                    **
** [cover parentID=DS_AS_PWM113a_PWM113b_PWM115a] [/cover]                   **
** [cover parentID=DS_AS_PWM081] [/cover]                                    **
** [cover parentID=DS_AS_PWM064_8] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_7] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_6] [/cover]                          **
** [cover parentID=DS_AS_PWM051b_8] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_8] [/cover]                          **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_EnableNotification
(
  Pwm_17_Gtm_ChannelType          ChannelNumber,
  Pwm_17_Gtm_EdgeNotificationType Notification
)
{

  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif /* PWM_DEV_ERROR_DETECT */
  uint8 CellUsed;
  uint8 Polarity;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_ChannelType ChIndex;
  #if ((PWM_SAFETY_ENABLE == STD_ON)&&(PWM_MAX_ASIL_CHANNELS != 0))
  uint8 ChSignal;
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: */
  if ( PWM_ERROR_FOUND == Pwm_lVerUnInitAndChannel( PWM_SID_ENABLENOTIFI,
                                                       ChannelNumber )
     )
  {
    /* Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif /* PWM_DEV_ERROR_DETECT */

  #if (PWM_SAFETY_ENABLE == STD_ON)
  if(ErrStatus == (uint8)E_OK)
  {
    if ((Notification < PWM_RISING_EDGE) || (Notification > PWM_BOTH_EDGES))
    {
      /* Report Safety Error */
      SafeMcal_ReportError( 
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID, 
                            PWM_SID_ENABLENOTIFI,
                            PWM_E_PARAM_EDGE
                          );
    }
  }
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
    ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
    /* Initialize PWM configured channel ROM pointer */
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    /* PWM 033 If a callback notification is configured as
    null pointer, no callback shall be executed. */
    if ( ( LocalPwmChanPtr->Notification ) !=  NULL_PTR)
    {
      /* Extract Cell number */
      CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
      Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
      if((Notification == PWM_BOTH_EDGES) || (Polarity == PWM_HIGH))
      {
        Pwm_lGtmIrqModify(CellUsed,Notification);
      }
      else
      {
        Notification = 
           ((Pwm_17_Gtm_EdgeNotificationType)(~Notification) & PWM_CONST_3);
        Pwm_lGtmIrqModify(CellUsed,Notification);
      }
      /* Store notification asked */
      Pwm_lSetNotificationEdges(ChannelNumber,Notification);
      /* Enable notification if Duty is not equal to 0% or 100% */
      #if (PWM_SAFETY_ENABLE == STD_ON)
      #if (PWM_MAX_ASIL_CHANNELS != 0)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      if (ChSignal == PWM_ASIL_TYPE)
      {
       /* Enable notification if Duty is not equal to 0% or 100% */
       if ((Pwm_GlobChn_Asil[ChIndex] & PWM_DUTY_0_OR_100_UPDATE_MASK) == 0U)
       {
         /* Enable Notification */
         Pwm_lSetNotificationStatus(ChannelNumber);
       }
      }
      else
      #endif
      #endif
      {
       #if (PWM_MAX_QM_CHANNELS != 0)

        if ((Pwm_GlobChn_Qm[ChIndex] & PWM_DUTY_0_OR_100_UPDATE_MASK) == 0U)
        {
          /* Enable Notification */
          Pwm_lSetNotificationStatus(ChannelNumber);
        }

       #endif
      }
    }
/* end of if */
  }
}/* End of Pwm_17_Gtm_EnableNotification() function */
#endif /* PWM_NOTIFICATION_SUPPORTED */

/******************************************************************************
**                      Private Function Definitions                         **
******************************************************************************/

/******************************************************************************
** Syntax : static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalEdge(        **
**                                             Pwm_17_Gtm_PeriodType Period, **
**                                                          uint32 Value)    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Period : Period Value in terms of Timer Count          **
**                    Value : Relative Value (0x0000 to 0x8000 ) (PWM059:)   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Absolute Value : Returns the converted value           **
**                                                                           **
** Description :      Local function : This function will convert the passed **
**                                    value to scaled value as per Period    **
**                                    This will be utilized for edge aligned **
**                                    Type PWM channels                      **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS40X_PWM150] [/cover]                                 **
** [cover parentID=DS_AS_PWM070] [/cover]                                    **
** [cover parentID=DS_AS_PWM059] [/cover]                                    **
**                                                                           **
******************************************************************************/
static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalEdge  \
                                   (Pwm_17_Gtm_PeriodType Period, uint32 Value)
{
  Pwm_17_Gtm_PeriodType ScaledValue;
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  /* Dutycycle is in absolute ticks, use this directly */
  ScaledValue = Value;
  #else
  /* Dutycycle is in percentage */
  /* Covert the passed Relative value to absolute value as mentioned in SWS
  (AbsoluteDutyCycle=(((uint32)AbsolutePeriodTime * relativeDutyCycle)))>>15)*/
  ScaledValue = (Pwm_17_Gtm_PeriodType)((Value * Period) >> PWM_SHIFT_BY15);
  #endif /* (PWM_DUTY_SHIFT_IN_TICKS == STD_ON) */

  /* Verify Scaled value is greater or equal to Period? */
  if (Period <= ScaledValue)
  {
    /* Make scaled value with full range of timer max */
    ScaledValue = Period;
  }
  if (Period == 0U)
  {
    /* Make scaled value zero for zero period */
    ScaledValue = 0U;
  }

  return (ScaledValue);
}/* End of Pwm_lGetAbsvalEdge() function */

#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
/******************************************************************************
** Syntax : static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalShCen(       **
**                                            Pwm_17_Gtm_PeriodType Period,  **
**                                            Pwm_17_Gtm_PeriodType Value    **
**                                            )                              **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Period : Period Value in terms of Timer Count          **
**                    Value : Relative Value (0x0000 to 0x8000 ) (PWM059:)   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Absolute Value : Returns the converted value           **
**                                                                           **
** Description :      Local function : This function will convert the passed **
**                                    value to scaled value as per Period    **
**                                    This will be utilized for Shift and    **
**                                    Center aligned Type PWM channels       **
**                                                                           **
******************************************************************************/
static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalShCen
                     (Pwm_17_Gtm_PeriodType Period,Pwm_17_Gtm_PeriodType Value)
{
  Pwm_17_Gtm_PeriodType ScaledValue;

  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  /* Duty and Shift are in absolute ticks, use these directly */
  ScaledValue = Value;
  #else
  /* Duty and Shift are in percentage */
  /* Covert the passed Relative value to absolute value as mentioned in SWS
  (AbsoluteDutyCycle=
   (((uint32)AbsolutePeriodTime * relativeDutyCycle)))>> 15)*/
  ScaledValue = (Pwm_17_Gtm_PeriodType)
                         (((Value * (uint32)Period)) >> PWM_SHIFT_BY15);
  #endif /* (PWM_DUTY_SHIFT_IN_TICKS == STD_ON) */

  /* Verify Scaled value is greater or equal to Period? */
  if (Period <= ScaledValue)
  {
    /* Make scaled value with full range of timer max */
    ScaledValue = PWM_MAX_TIMER;
  }
  if (Period == 0U)
  {
    /* Make scaled value zero for zero period */
    ScaledValue = 0U;
  }

  return (ScaledValue);
}/* End of Pwm_lGetAbsvalShCen() function */

/******************************************************************************
** Syntax : static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetShiftLead(         **
**                                             Pwm_17_Gtm_PeriodType Period, **
**                                             Pwm_17_Gtm_PeriodType Shift)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Period : Period Value in terms of Timer Count          **
**                    Shift : Relative Value (0x0000 to 0x8000 )             **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Absolute Value : Returns the converted value           **
**                                                                           **
** Description :      Local function : This function will convert the passed **
**                                    shift value to Absolute value in scale **
**                                    of Period passed. The value informs    **
**                                    leading timer count to position the    **
**                                    edge                                   **
******************************************************************************/
static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetShiftLead( 
                     Pwm_17_Gtm_PeriodType Period,Pwm_17_Gtm_PeriodType Shift)
{
  Pwm_17_Gtm_PeriodType ScaledShiftLead;

  /* Get Scaled value of Shift */
  ScaledShiftLead = Pwm_lGetAbsvalShCen(Period, Shift);

  /* Verify ScaledShiftLead is greater or equal to Period? */
  if (ScaledShiftLead >= Period)
  {
    /* Make scaled value with 0 */
    ScaledShiftLead = (Pwm_17_Gtm_PeriodType)0;
  }

  return ScaledShiftLead;
}/* End of Pwm_lGetShiftLead() function */
#endif /* (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: */
/*
 * Functions when PWM_DEV_ERROR_DETECT defined
 */
/******************************************************************************
** Syntax : static _INLINE_ uint32 Pwm_lVerChannel( uint8 ServiceID,         **
**                                    Pwm_17_Gtm_ChannelType ChannelNumber ) **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID    : Informs Service ID of an API           **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service to detect whether the passed   **
**                                   channel number is valid or not          **
**                                                                           **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PR127_1] [/cover]                                  **
**                                                                           **
******************************************************************************/
static _INLINE_ uint32 Pwm_lVerChannel
(
  uint8           ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
)
{
  uint32 ErrorFlag;
  ErrorFlag = (uint32)0;

  /* Verify whether Invalid channel number has been sent */
  if ( ChannelNumber >= Pwm_kConfigPtr->MaxChannels )
  {
    /* PWM002: Report to DET upon error */
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,
                     PWM_17_GTM_INSTANCE_ID,
                     ServiceID,
                     PWM_E_PARAM_CHANNEL
                   );/* PWM047: End of report to  DET */
    #endif
    #if (PWM_SAFETY_ENABLE == STD_ON)
    /* Report Safety Error */
    SafeMcal_ReportError( 
                         PWM_17_GTM_MODULE_ID,
                         PWM_17_GTM_INSTANCE_ID, 
                         ServiceID,
                         PWM_E_PARAM_CHANNEL
                         );
    #endif
    ErrorFlag = PWM_ERROR_FOUND; /* Set Error Flag */
  }
  return ErrorFlag;
}/* End of Pwm_lVerChannel() function */

/******************************************************************************
** Syntax : static _INLINE_ uint32 Pwm_lVerUnInit( uint8 ServiceID )         **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID : Informs Service ID of an API              **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service to detect UnInit               **
**                                                                           **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PR127_2] [/cover]                                  **
**                                                                           **
******************************************************************************/
static _INLINE_ uint32 Pwm_lVerUnInit( uint8 ServiceID )
{
  uint32      ErrorFlag;
  ErrorFlag = (uint32)0;

  /* Verify whether Init has been called */
  #if (PWM_PB_FIXEDADDR == STD_OFF)
  if (NULL_PTR == Pwm_kConfigPtr)
  #else
  if (PWM_INITIALIZED != Pwm_InitStatus)
  #endif /* (PWM_PB_FIXEDADDR == STD_OFF) */
  {
    /* PWM002: Report to DET upon error */
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,           
                     PWM_17_GTM_INSTANCE_ID,
                     ServiceID,
                     PWM_E_UNINIT
                   );/* PWM044: End of report to  DET */
    #else
    UNUSED_PARAMETER(ServiceID)
    #endif
    ErrorFlag = PWM_ERROR_FOUND; /* Set Error Flag */
  }
  return ErrorFlag;
}/* End of Pwm_lVerUnInit() function */

/******************************************************************************
** Syntax : static _INLINE_ uint32 Pwm_lVerUnInitAndChannel (                **
**                                      uint8 ServiceID           ,          **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID    : Informs Service ID of an API           **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service to detect UnInit and wrong     **
**                                   channel number                          **
**                                                                           **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PR127_3] [/cover]                                  **
**                                                                           **
******************************************************************************/
static _INLINE_ uint32 Pwm_lVerUnInitAndChannel
(
  uint8           ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
)
{
  uint32      ErrorFlag;
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Verify whether Init has been called */
  ErrorFlag = Pwm_lVerUnInit(ServiceID);
  if (ErrorFlag != PWM_ERROR_FOUND)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON)) 
    /* Verify whether Invalid channel number has been sent */
    ErrorFlag = Pwm_lVerChannel(ServiceID,ChannelNumber);
  #endif 
  }
  return ErrorFlag;
} /* End of Pwm_lVerUnInitAndChannel() function */

/******************************************************************************
** Syntax : static uint32 Pwm_lInitDetCheck                                  **
**                                (const Pwm_17_Gtm_ConfigType *DetConfigPtr)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        non reentrant                                          **
**                                                                           **
** Parameters (in):   DetConfigPtr - Pointer to configuration set            **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service for DET check in Pwm_Init()    **
**                                   function PWM046,PWM002                  **
**                                                                           **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PR127_4] [/cover]                                  **
**                                                                           **
******************************************************************************/
static uint32 Pwm_lInitDetCheck( const Pwm_17_Gtm_ConfigType *DetConfigPtr )
{
  uint32      ErrorFlag;
  ErrorFlag = (uint32)0;

  /* Verify whether Init has already been called */
  #if ( PWM_PB_FIXEDADDR == STD_OFF )
  if (NULL_PTR != Pwm_kConfigPtr)
  #else
  if (PWM_INITIALIZED == Pwm_InitStatus)
  #endif /* End Of PWM_PB_FIXEDADDR */
  {
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* PWM002: Report to DET upon error */
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,
                     PWM_17_GTM_INSTANCE_ID,
                     PWM_SID_INIT,
                     PWM_E_ALREADY_INITIALIZED
                   );/* PWM118: End of report to DET */
   
    /*Error flag is set*/
    ErrorFlag = PWM_ERROR_FOUND; /* Set Error Flag */
    #endif
  }
  /*PWM046:If development error detection is enabled,
           the parameter ConfigPtr shall
            be checked for not being a NULL pointer. */
  /* To verify whether Init has been called with wrong parameter */
  else

  #if ( PWM_PB_FIXEDADDR == STD_OFF )
  /* Det Check for NULL pointer  */
  if ( NULL_PTR == DetConfigPtr ) 
  #else
    /* Passed ConfigPtr and Pwm_kConfigPtr should match*/
    /* Parameter check for init */
  if (Pwm_kConfigPtr != DetConfigPtr)
  #endif  /*End Of PWM_PB_FIXEDADDR */
  {
    /*
     PWM002: Report to DET upon error, Init has been called with wrong
      parameter NULL Config Pointer
    */
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,
                     PWM_17_GTM_INSTANCE_ID,
                     PWM_SID_INIT,
                     PWM_E_PARAM_CONFIG
                   ); /* PWM046: Report to  DET */
    #endif
    #if(PWM_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( 
                          PWM_17_GTM_MODULE_ID,
                          PWM_17_GTM_INSTANCE_ID, 
                          PWM_SID_INIT,
                          PWM_E_PARAM_CONFIG
                        );
   #endif
   ErrorFlag = PWM_ERROR_FOUND;
   }
  else
  {
    /* Do nothing - added for Misra check */
  }
  return (ErrorFlag);
} /* End of Pwm_lInitDetCheck() function */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/******************************************************************************
** Syntax : static _INLINE_ uint32 Pwm_lVerUnInitChanAndPer (                **
**                                     uint8 ServiceID,                      **
**                                     Pwm_17_Gtm_ChannelType ChannelNumber) **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID    : Informs Service ID of an API           **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service to verify DET for UnInit,      **
**                                   channel No and not variable period      **
**                                   [period and duty range checks for asil  **
**                                    signal if safety is enabled ]          **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PR127_5] [/cover]                                  **
**                                                                           **
******************************************************************************/
static _INLINE_ uint32 Pwm_lVerUnInitChanAndPer
(
  uint8           ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
)
{
  uint32          ErrorFlag;
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  Pwm_17_Gtm_ChannelClassType        ChannelKind;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  #endif
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Verify whether Init has been called */
  ErrorFlag = Pwm_lVerUnInit(ServiceID);
  if (ErrorFlag != PWM_ERROR_FOUND)
  #endif
  {
    #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
    /* Verify whether Invalid channel number has been sent */
    ErrorFlag = Pwm_lVerChannel(ServiceID,ChannelNumber);
    #endif
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorFlag != PWM_ERROR_FOUND)
    {
      /* Initialize local config pointer according to channel passed */
      LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
      /* Get the type of channel used */
      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
      /* Verify whether channel provided for not variable period */
      if ( PWM_VARIABLE_PERIOD != ChannelKind )
      {
        /* PWM002: Error Classified to report to DET */
        
        Det_ReportError(
                      PWM_17_GTM_MODULE_ID,
                      PWM_17_GTM_INSTANCE_ID,
                      ServiceID,
                      PWM_E_PERIOD_UNCHANGEABLE
                    );/* PWM045: End of report to  DET */
              
        ErrorFlag = PWM_ERROR_FOUND; /* Set Error Flag */
      }
      /* end of if PWM_VARIABLE_PERIOD != ChannelKind */
    } 
    /* end of if ( ErrorFlag != PWM_ERROR_FOUND) */
    #endif
  } 
  /* end of if ( ErrorFlag != PWM_ERROR_FOUND) */
  return ErrorFlag;

}/* End of function Pwm_lVerUnInitChanAndPer */
#endif /* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

#endif /* PWM_DEV_ERROR_DETECT */

#if (PWM_VARIABLE_PERIOD_USED == STD_ON)
/******************************************************************************
** Syntax : static void Pwm_lInitVariablePeriod (                            **
**                                           uint8 CellUsed,                 **
**                                           uint32 ChannelNumber)           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed    : Used GTM channel                         **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize variable period  **
**                                   channel                                 **
**                                                                           **
******************************************************************************/
static void Pwm_lInitVariablePeriod
(
  uint8 CellUsed,
  uint32 ChannelNumber
)
{
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_PropertyType            PwmProperty;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  uint32                      Duty;
  Pwm_17_Gtm_ChannelType      ChIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  uint8                       ChSignal;
  #endif
  #endif
  /* Initialize PWM configured channel ROM pointer */
  LocalPwmChanPtr          = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  PwmProperty.Polarity     = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.Coherency    = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.IsReference  = PWM_NORMAL_CHANNEL;
  PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
  PwmProperty.ChannelType  = PWM_NORMAL_CHANNEL;
  Period                   = LocalPwmChanPtr->PeriodDefault;
  Duty                     = (uint32)LocalPwmChanPtr->DutycycleDefault;
  /* Get Scale value of Duty according to period */
  ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, Duty);
  ShiftVal = 0U;
  ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    Pwm_CurrentPeriodVal_Asil[ChIndex] = Period;
  }
  else
  #endif
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Pwm_CurrentPeriodVal_Qm[ChIndex] = Period;
    #endif
  }
  Pwm_lGtmStartChannelsInit(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);
  
} /* End of function Pwm_lInitVariablePeriod */
#endif /* PWM_VARIABLE_PERIOD_USED */

#if (PWM_FIXED_PERIOD_USED == STD_ON)
/******************************************************************************
** Syntax : static void Pwm_lInitFixedPeriod (                               **
**                                           uint8 CellUsed,                 **
**                                           uint32 ChannelNumber)           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed    : Used GTM channel                         **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize fixed period     **
**                                   channel                                 **
**                                                                           **
******************************************************************************/
static void Pwm_lInitFixedPeriod
(
  uint8 CellUsed,
  uint32 ChannelNumber
)
{
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_PropertyType         PwmProperty;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  uint32                      Duty;
  
  /* Initialize PWM configured channel ROM pointer */
  LocalPwmChanPtr          = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  PwmProperty.Polarity     = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.Coherency    = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.IsReference  = Pwm_lIsReference(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
  PwmProperty.ChannelType  = PWM_NORMAL_CHANNEL;
  Period                   = LocalPwmChanPtr->PeriodDefault;
  Duty                     = LocalPwmChanPtr->DutycycleDefault;
  /* Get Scale value of Duty according to period */
  ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, Duty);
  ShiftVal = 0U;
  
  Pwm_lGtmStartChannelsInit(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);
  
} /* End of function Pwm_lInitFixedPeriod */
#endif /* PWM_FIXED_PERIOD_USED */

#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
/******************************************************************************
** Syntax : static void Pwm_lInitFixedPeriodShifted (                        **
**                                           uint8 CellUsed,                 **
**                                           uint32 ChannelNumber)           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed    : Used GTM channel                         **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize shifted period   **
**                                   channel                                 **
**                                                                           **
******************************************************************************/
static void Pwm_lInitFixedPeriodShifted
(
  uint8 CellUsed,
  uint32 ChannelNumber
)
{
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_PropertyType         PwmProperty;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  uint32                      MainChannel;
  uint32                      Duty;
  
  /* Initialize PWM configured channel ROM pointer */
  LocalPwmChanPtr          = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  PwmProperty.Polarity     = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.Coherency    = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.IsReference  = PWM_NORMAL_CHANNEL;
  PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
  PwmProperty.ChannelType  = PWM_SHIFTED_CHANNEL;
  Duty                     = LocalPwmChanPtr->DutycycleDefault;
  MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.RefChannelId = Pwm_lAssignedHW
            (((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->ChannelInfo);
  /* Get main period */
  Period = ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;
    
  /* Get Scale value of Duty according to period */
  ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, Duty);
  /* Get the Shift lead value */
  ShiftVal = (uint32)Pwm_lGetShiftLead( Period, 
                      (Pwm_17_Gtm_PeriodType)(LocalPwmChanPtr->ShiftValue) );
  Pwm_lGtmStartChannelsInit(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);
  
} /* End of function Pwm_lInitFixedPeriodShifted */
#endif /* PWM_FIXED_PERIOD_SHIFTED_USED */

#if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
/******************************************************************************
** Syntax : static void Pwm_lInitCentreAligned (                             **
**                                           uint8 CellUsed,                 **
**                                           uint32 ChannelNumber)           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed    : Used GTM channel                         **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize centre aligned   **
**                                   channel                                 **
**                                                                           **
******************************************************************************/
static void Pwm_lInitCentreAligned
(
  uint8 CellUsed,
  uint32 ChannelNumber
)
{
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_PropertyType         PwmProperty;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  uint32                      MainChannel;
  uint32                      Duty;
  
  /* Initialize PWM configured channel ROM pointer */
  LocalPwmChanPtr          = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  PwmProperty.Polarity     = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.Coherency    = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.IsReference  = PWM_NORMAL_CHANNEL;
  PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
  PwmProperty.ChannelType  = PWM_SHIFTED_CHANNEL;
  Duty                     = LocalPwmChanPtr->DutycycleDefault;
  MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
  /* UTP AI00134683 */
  PwmProperty.RefChannelId = Pwm_lAssignedHW
            (((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->ChannelInfo);
  /* Get main period,  */
  Period = ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;

  /* Get Scale value of Duty according to period */
  ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, Duty);
  /* Get Centre Lead value */
  ShiftVal = (uint32)Pwm_lGetCenterLead(Period, ScaledDuty);
  Pwm_lGtmStartChannelsInit(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);
  
} /* End of function Pwm_lInitCentreAligned */
#endif /* PWM_USED_FIXED_PERIOD_CENTER_ALIGNED */

#if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
/******************************************************************************
** Syntax : static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetCenterLead(        **
**                                          Pwm_17_Gtm_PeriodType Period,    **
**                                          Pwm_17_Gtm_PeriodType ScaledDuty)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Period : Period Value in terms of Timer Count          **
**                    ScaledDuty : Duty Value (Scaled as per Period)         **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Absolute Value : Returns the converted lead value      **
**                                                                           **
** Description :      Local function : This function will convert the passed **
**                                    scaled Duty value to Center aligned    **
**                                    Absolute lead value in scale of period **
**                                    passed. The value informs the leading  **
**                                    timer count to position the edge.      **
**                                    To get Scaled Center Lead value as per **
**                                    Period and ScaledDuty                  **
**                                                                           **
******************************************************************************/
static _INLINE_ Pwm_17_Gtm_PeriodType Pwm_lGetCenterLead
(
  Pwm_17_Gtm_PeriodType Period,
  Pwm_17_Gtm_PeriodType ScaledDuty
)
{
  Pwm_17_Gtm_PeriodType ScaledCenterLead;

  /* Initialize local variable with Max Timer Minus  */
  ScaledCenterLead = PWM_MAX_TIMER;

  /* if Duty is less than period -1 */
  if ( ScaledDuty < (Period) )
  {
    /* Calculate the timer count for lead edge */
    ScaledCenterLead =
      (Pwm_17_Gtm_PeriodType)(( ( ((Period) - (ScaledDuty))
                  + ((Pwm_17_Gtm_PeriodType)1)
                 )
                  / ((Pwm_17_Gtm_PeriodType)PWM_CONST_2)
               )
                - ((Pwm_17_Gtm_PeriodType)1)
              );
  }
  return ScaledCenterLead;
}/* End of Pwm_lGetCenterLead() function */

#endif


/*******************************************************************************
** Syntax : void Pwm_lGtmStartChannelsInit(                                   **
**                            Pwm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel number                     **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmStartChannelsInit
(
   Pwm_GlobalChannelNumberType GlobalChannelNumber, 
   uint32 Period, 
   uint32 Dutycycle, 
   uint32 Shift, 
   Pwm_17_Gtm_PropertyType PwmProperty
)
{

  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */

  /* Extract the Module specific information */
  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);

  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    Pwm_lGtmTomChannelsInit(GlobalChannelId,Period,Dutycycle,Shift,PwmProperty);
  }

  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
   Pwm_lGtmAtomChannelsInit(GlobalChannelId,Period,Dutycycle,Shift,PwmProperty);
  }
}

/*******************************************************************************
** Syntax : void Pwm_lGtmTomChannelsInit(                                     **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmTomChannelsInit
(
   Pwm_ChannelIdentifierType GlobalChannelId, 
   uint32 Period, 
   uint32 Dutycycle, 
   uint32 Shift, 
   Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;   /* Ptr to TOM Channel Reg          */
  Ifx_GTM_TOM_CH_TYPE* RefTomChannelRegPtr;   /* Ptr to TOM Channel Reg       */
  Ifx_GTM_TOM_TGC_TYPE* TomTgcRegPtr;           /* Ptr to TOM TGC Reg         */
  Pwm_ChannelIdentifierType RefGlobChanId; /* Structure to get Module info    */
  uint32 RegVal;                             /* For Temp storage of Reg Value */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */
  uint8 GroupNumber;                         /* Holds the group number        */
  uint8 RefModNumber;
  uint8 RefChannelNumber;

  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;
  GroupNumber = GlobalChannelId.GroupNo;

  TomTgcRegPtr = &((*(Ifx_GTM_TOMx*)(void*)\
                    (MODULE_GTM.TOM)).TOM_TGC[ModuleNumber].TGC[GroupNumber]);

  /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */ 
  /* MISRA Rule Violation 11.4 and 1.2
     Unusual pointer cast (incompatible indirect types)
     cast from pointer to pointer
     Casting of TOM to Gtm_TomChannelRegType is done to change the base 
     type of TOM as the type defined in SFR file is not flexible to 
     provide an arrayed approach for accessing the TOM channels. */

 TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(void*) \
                    (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));


  /* Set the property of the PWM signal */
  TomChannelRegPtr->CTRL.U |= (uint32_t)
                (((uint32)PwmProperty.IsReference << PWM_GTM_CTRL_TRIGOUT)  |
                  ((uint32)PwmProperty.ChannelType << PWM_GTM_CTRL_RST_CCU0));

    /* Update Enable for the channel must be enabled if Coherant update is 
       desired */
    if(PwmProperty.Coherency == PWM_COHERENT)
    {
      RegVal = TomTgcRegPtr->GLB_CTRL.U & PWM_TGC_GLB_CTRL_MASK;
      TomTgcRegPtr->GLB_CTRL.U = (uint32_t)
        (((uint32)PWM_CONST_2 << (uint16)(PWM_CONST_16 + (PWM_CONST_2 * 
                  ((uint16)ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))|RegVal);
    }
    
    if((PwmProperty.ChannelType != PWM_SHIFTED_CHANNEL) ||               \
      (Period == Dutycycle) ||                                                 \
      (Dutycycle == 0UL))
    {
      Pwm_lGtmSLBitConfigInit(GlobalChannelId,Dutycycle,PwmProperty);

      if(Dutycycle == 0UL)  /* 0% Duty */
      {
        Dutycycle = Period;
      }
      
      TomChannelRegPtr->CM0.U = Period;    /* Update CM0 with Period*/
      TomChannelRegPtr->CM1.U = Dutycycle;/* Update CM1 with DCycle*/
      
      /* Update CN0 with a value slightly behind CM0 value because if CN0 is 
         configured with 0, then no signal will be present for 1 cycle, now, 
         with this change, there will be no signal for 10 ticks */
      TomChannelRegPtr->CN0.U = Period; 
      
      if(PwmProperty.Coherency == PWM_COHERENT)     
      {
        TomChannelRegPtr->SR0.U = Period;    /* Update SR0 with Period*/
        TomChannelRegPtr->SR1.U = Dutycycle; /* Update SR1 with DCycle*/

      }
    } 
    else
    {
      Pwm_lGtmSLBitConfigInit(GlobalChannelId,Dutycycle,PwmProperty);
      /* If shifted channel is desired */  
      RefGlobChanId = Pwm_lGtmChannelIdentifier
                     ((Pwm_GlobalChannelNumberType)PwmProperty.RefChannelId);
      RefModNumber = RefGlobChanId.ModuleNo;
      RefChannelNumber = RefGlobChanId.ChannelNo;
      RefTomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(void*) \
                (MODULE_GTM.TOM)).TOM_CH[RefModNumber].CH[RefChannelNumber]));
      TomChannelRegPtr->CN0.U = RefTomChannelRegPtr->CN0.U;
      /* Update CM1 with Shift + Dutycycle. To enable automatic wrap around in 
         case if this value goes beyond Period length, this value is mod with 
         Period value */
      TomChannelRegPtr->CM1.U = Pwm_lGtmCounterVal(Shift, Period, Dutycycle);
        
      /* In case of 0 shift, it must be modified to Period to make the behaviour
         similar to a normal PWM */
      if(Shift == 0UL )
      {
        Shift = Period;
      }
      TomChannelRegPtr->CM0.U = Shift;

      /* SR0 and SR1 must be updated if in case coherency is desired. */
      if(PwmProperty.Coherency == PWM_COHERENT)     
      {
        TomChannelRegPtr->SR0.U = Shift;
        TomChannelRegPtr->SR1.U = Pwm_lGtmCounterVal(Shift, Period, Dutycycle);
      }
    }
    /* Enable the channel and its output */
    TomTgcRegPtr->ENDIS_STAT.U = (uint32_t)((uint32)PWM_CONST_2 << 
                      (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC)));
    TomTgcRegPtr->ENDIS_CTRL.U = (uint32_t)
           (~(1UL << (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))));
    TomTgcRegPtr->OUTEN_STAT.U = (uint32_t)((uint32)PWM_CONST_2 << 
                      (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC)));
    TomTgcRegPtr->OUTEN_CTRL.U = (uint32_t)
           (~(1UL << (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))));
}
/*******************************************************************************
** Syntax : void Pwm_lGtmAtomChannelsInit(                                    **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmAtomChannelsInit
(
   Pwm_ChannelIdentifierType GlobalChannelId, 
   uint32 Period, 
   uint32 Dutycycle, 
   uint32 Shift, 
   Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg       */  
  Ifx_GTM_ATOM_CH_TYPE* RefAtomChannelRegPtr; /* Ptr to ATOM Channel Reg    */
  Ifx_GTM_ATOM* AtomRegPtr;           /* Ptr to ATOM AGC Reg           */
  Pwm_ChannelIdentifierType RefGlobChanId; /* Structure to get Module info  */  
  uint32 RegVal;                             /* For Temp storage of Reg Value */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */
  uint8 RefModNumber;
  uint8 RefChannelNumber;
 
  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;
 
  AtomRegPtr = &(MODULE_GTM.ATOM[ModuleNumber]);
  
  AtomChannelRegPtr = &((*(Ifx_GTM_ATOMx*)(void*)  \
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);


  /* Set the property of the PWM signal */    
  AtomChannelRegPtr->CTRL.U |= (uint32_t)                           \
                 (((uint32)PwmProperty.IsReference << PWM_GTM_CTRL_TRIGOUT) |\
                  ((uint32)PwmProperty.ChannelType << PWM_GTM_CTRL_RST_CCU0));
  
  /* Update Enable for the channel must be enabled if Coherant update is 
     desired */
  if(PwmProperty.Coherency == PWM_COHERENT)
  {
    RegVal = ((AtomRegPtr->AGC.GLB_CTRL.U) & PWM_TGC_GLB_CTRL_MASK);
    AtomRegPtr->AGC.GLB_CTRL.U =  (uint32_t)(((uint32)PWM_CONST_2 << 
    (PWM_CONST_16 + (PWM_CONST_2*(ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC))))|
     RegVal);
  }
  
  
  if((PwmProperty.ChannelType != PWM_SHIFTED_CHANNEL) || \
    (Period == Dutycycle) ||  \
    (Dutycycle == 0UL))
  {

    Pwm_lGtmSLBitConfigInit(GlobalChannelId,Dutycycle,PwmProperty);

    if(Dutycycle == 0UL)  /* 0% Duty */
    {
      Dutycycle = Period;
    }
    
    AtomChannelRegPtr->CM0.U = Period;    /* Update CM0 with Period*/
    AtomChannelRegPtr->CM1.U = Dutycycle; /* Update CM1 with DCycle*/

    /* Update CN0 with a value slightly behind CM0 value because if CN0 is 
       configured with 0, then no signal will be present for 1 cycle, now, 
       with this change, there will be no signal for 10 ticks */      
    AtomChannelRegPtr->CN0.U = Period;

    if(PwmProperty.Coherency == PWM_COHERENT)
    {
      AtomChannelRegPtr->SR1.U = Dutycycle;/*Update SR0 with Period*/
      AtomChannelRegPtr->SR0.U = Period;   /*Update SR1 with DCycle*/    
    }
  } 
  else
  {
    Pwm_lGtmSLBitConfigInit(GlobalChannelId,Dutycycle,PwmProperty);
    RefGlobChanId = Pwm_lGtmChannelIdentifier
                     ((Pwm_GlobalChannelNumberType)PwmProperty.RefChannelId);
    RefModNumber = RefGlobChanId.ModuleNo;
    RefChannelNumber = RefGlobChanId.ChannelNo;
    RefAtomChannelRegPtr =&((*(Ifx_GTM_ATOMx*)(void*) \
          (MODULE_GTM.ATOM)).ATOM_CH[RefModNumber].CH[RefChannelNumber]);

    AtomChannelRegPtr->CN0.U = RefAtomChannelRegPtr->CN0.U;

    /* Update CM1 with Shift + Dutycycle. To enable automatic wrap around in 
       case if this value goes beyond Period length, this value is mod with 
       Period value */      
    AtomChannelRegPtr->CM1.U = Pwm_lGtmCounterVal(Shift, Period, Dutycycle);
    /* In case of 0 shift, it must be modified to Period to make the behaviour 
       similar to a normal PWM */     
    if(Shift == 0UL )
    {
      Shift = Period;
    }
    AtomChannelRegPtr->CM0.U = Shift;
  
    /* SR0 and SR1 must be updated if in case coherency is desired. */      
    if(PwmProperty.Coherency == PWM_COHERENT)
    {
      AtomChannelRegPtr->SR1.U = Pwm_lGtmCounterVal(Shift, Period, Dutycycle);
      AtomChannelRegPtr->SR0.U = Shift;                
    }     
  }
  /* Enable the channel and its output */   
  AtomRegPtr->AGC.ENDIS_STAT.U =  (uint32_t)((uint32)PWM_CONST_2 << 
                     (PWM_CONST_2*(ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC)));
  AtomRegPtr->AGC.ENDIS_CTRL.U =  (uint32_t)
          (~(1UL << (PWM_CONST_2*(ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC))));
  AtomRegPtr->AGC.OUTEN_STAT.U =  (uint32_t)((uint32)PWM_CONST_2 << 
                     (PWM_CONST_2*(ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC)));
  AtomRegPtr->AGC.OUTEN_CTRL.U =  (uint32_t)
          (~(1UL << (PWM_CONST_2*(ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC))));
}

/*******************************************************************************
** Syntax : void Pwm_lGtmSLBitConfigInit(                                     **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Dutycycle,                               **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Dutycycle - Dutycycle                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function configure the SL bit of the control        **
**                   register based on the duty cycle and the Idle state.     **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmSLBitConfigInit
(
  Pwm_ChannelIdentifierType GlobalChannelId, 
  uint32 Dutycycle, 
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;   /* Ptr to TOM Channel Reg   */
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg  */  
  uint32 Polarity;
  uint8  ModuleNumber;                       /* Holds the module number  */ 
  uint8  ChannelNumber;                      /* Holds the channel number */ 

  
  /* Extract the Module specific information */   
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  Polarity = (uint32)PwmProperty.Polarity;

  if(Dutycycle == 0UL)  /* 0% Duty */
  {
    if(PwmProperty.Polarity == 0U)
    {
      Polarity= 1UL;        
    }
    else
    {
      Polarity= 0UL;
    }
  }

  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */ 
    /* MISRA Rule Violation 11.4 and 1.2
       Unusual pointer cast (incompatible indirect types)
       cast from pointer to pointer
       Casting of TOM to Gtm_TomChannelRegType is done to change the base 
       type of TOM as the type defined in SFR file is not flexible to 
       provide an arrayed approach for accessing the TOM channels. */
    TomChannelRegPtr =&(((*(Ifx_GTM_TOMx*)(void*)\
                (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));

    TomChannelRegPtr->CTRL.U |= (uint32_t)(Polarity << PWM_GTM_CTRL_SL);  
  }

  
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
   AtomChannelRegPtr =  &((*(Ifx_GTM_ATOMx*)(void*)\
           (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
   
    AtomChannelRegPtr->CTRL.U |= (uint32_t)(Polarity << PWM_GTM_CTRL_SL);  
  }
}

#if( (PWM_DE_INIT_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || \
    (PWM_SET_DUTY_CYCLE_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
/*******************************************************************************
** Syntax : void Pwm_lGtmStartChannel(                                        **
**                            Pwm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel number                     **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmStartChannel
(
 Pwm_GlobalChannelNumberType GlobalChannelNumber,
 uint32 Period, 
 uint32 Dutycycle, 
 uint32 Shift, 
 Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */

  /* Extract the Module specific information */   
  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);

  /* Detect the Sub-Module type */  
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    Pwm_lGtmStartTomChannel(GlobalChannelId,Period,Dutycycle,Shift,PwmProperty);
  }

  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
   Pwm_lGtmStartAtomChannel(GlobalChannelId,Period,Dutycycle,Shift,PwmProperty);
  }
}

/*******************************************************************************
** Syntax : void Pwm_lGtmStartTomChannel(                                     **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmStartTomChannel
(
  Pwm_ChannelIdentifierType GlobalChannelId, 
  uint32 Period, 
  uint32 Dutycycle, 
  uint32 Shift, 
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;   /* Ptr to TOM Channel Reg        */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */

  /* Extract the Module specific information */   
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */ 
  /* MISRA Rule Violation 11.4 and 1.2
     Unusual pointer cast (incompatible indirect types)
     cast from pointer to pointer
     Casting of TOM to Gtm_TomChannelRegType is done to change the base 
     type of TOM as the type defined in SFR file is not flexible to 
     provide an arrayed approach for accessing the TOM channels. */
  TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(void*)\
                    (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));


  if(PwmProperty.ChannelType != PWM_SHIFTED_CHANNEL)
  {
    Pwm_lGtmSLBitConfigStart(GlobalChannelId,PwmProperty);

    TomChannelRegPtr->CTRL.U &= (uint32_t)(~(1UL << PWM_GTM_CTRL_RST_CCU0));

    if(PwmProperty.Coherency == PWM_NON_COHERENT)
    {
      TomChannelRegPtr->CM0.U = Period;
      TomChannelRegPtr->CM1.U = Dutycycle;
      TomChannelRegPtr->SR0.U = Period;
      TomChannelRegPtr->SR1.U = Dutycycle;
      if((Dutycycle == Period) || (Dutycycle == 0U))
      {
        TomChannelRegPtr->CN0.U = Period;
      }
    }
    else
    {
      TomChannelRegPtr->SR0.U = Period;    /* Update SR0 with Period*/
      TomChannelRegPtr->SR1.U = Dutycycle; /* Update SR1 with DCycle*/
    }
    if(PwmProperty.PreviousState == PWM_IDLE_CHANNEL)
    {
      TomChannelRegPtr->CN0.U = Period;
    }
  }
  else
  { /* If shifted channel is desired */

    Pwm_lGtmSLBitConfigStart(GlobalChannelId,PwmProperty);

    TomChannelRegPtr->CTRL.U |= (uint32_t)(1UL << PWM_GTM_CTRL_RST_CCU0);

    if(PwmProperty.Coherency == PWM_NON_COHERENT)
    {
      if((Dutycycle == Period) || (Dutycycle == 0U))
      {
        TomChannelRegPtr->CM0.U = Period;
        TomChannelRegPtr->CM1.U = Dutycycle;
        TomChannelRegPtr->SR0.U = Period;
        TomChannelRegPtr->SR1.U = Dutycycle;
      }
      else
      {
        /* Update CM1 with Shift + Dutycycle. To enable automatic wrap around in 
         case if this value goes beyond Period length, this value is mod with 
         Period value */      
        TomChannelRegPtr->CM1.U = Pwm_lGtmCounterVal(Shift, Period, Dutycycle);
        /* In case of 0 shift, it must be modified to Period to make the 
         behaviour similar to a normal PWM */     
        if(Shift == 0UL)
        {
          Shift = Period;
        }
        TomChannelRegPtr->CM0.U = Shift;
      }
    }
    else
    {
      if (Dutycycle == 0U)
      {
        TomChannelRegPtr->SR1.U = 0U;
        TomChannelRegPtr->SR0.U = Period;
      }
      else if (Dutycycle == Period)
      {
        TomChannelRegPtr->SR1.U = 2U;
        TomChannelRegPtr->SR0.U = 2U;
      }
      else
      {
        TomChannelRegPtr->SR1.U = Pwm_lGtmCounterVal(Shift, Period, Dutycycle);
        if(Shift == 0UL)
        {
          Shift = Period;
        }
        TomChannelRegPtr->SR0.U = Shift;
      }
    }
    /* if the PWM channel's previous state is IDLE,then CN0 is reinitialized*/
    if(PwmProperty.PreviousState == PWM_IDLE_CHANNEL)
    {
      TomChannelRegPtr->CN0.U = Period;
    }
  }
}
/*******************************************************************************
** Syntax : void Pwm_lGtmStartAtomChannel(                                    **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmStartAtomChannel
(
  Pwm_ChannelIdentifierType GlobalChannelId, 
  uint32 Period, 
  uint32 Dutycycle, 
  uint32 Shift, 
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg       */  
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */

  /* Extract the Module specific information */   
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  AtomChannelRegPtr =&((*(Ifx_GTM_ATOMx*)(void*)\
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);

  if(PwmProperty.ChannelType != PWM_SHIFTED_CHANNEL)
  {

    Pwm_lGtmSLBitConfigStart(GlobalChannelId,PwmProperty);

    AtomChannelRegPtr->CTRL.U &= (uint32_t)(~(1UL << PWM_GTM_CTRL_RST_CCU0));

    if(PwmProperty.Coherency == PWM_NON_COHERENT)
    {
      AtomChannelRegPtr->CM0.U = Period;
      AtomChannelRegPtr->CM1.U = Dutycycle;
      AtomChannelRegPtr->SR0.U = Period;
      AtomChannelRegPtr->SR1.U = Dutycycle;
      if((Dutycycle == Period)||(Dutycycle == 0U))
      {
        AtomChannelRegPtr->CN0.U = Period;
      }
    }
    else
    {
      AtomChannelRegPtr->SR0.U = Period;   /*Update SR0 with Period*/
      AtomChannelRegPtr->SR1.U = Dutycycle;/*Update SR1 with DCycle*/
    }
    /* if the PWM channel's previous state is IDLE,then CN0 is reinitialized*/
    if(PwmProperty.PreviousState == PWM_IDLE_CHANNEL)
    {
      AtomChannelRegPtr->CN0.U = Period;
    }
  }
  else
  { /* If shifted channel is desired */

    Pwm_lGtmSLBitConfigStart(GlobalChannelId,PwmProperty);

    AtomChannelRegPtr->CTRL.U |= (uint32_t)(1UL << PWM_GTM_CTRL_RST_CCU0);

    if(PwmProperty.Coherency == PWM_NON_COHERENT)
    {

      if ((Dutycycle == 0U)||(Dutycycle == Period))
      {
        AtomChannelRegPtr->CM0.U = Period;
        AtomChannelRegPtr->CM1.U = Dutycycle;
        AtomChannelRegPtr->SR0.U = Period;
        AtomChannelRegPtr->SR1.U = Dutycycle;
      }
      else
      {
        /* Update CM1 with Shift + Dutycycle. To enable automatic wrap around in 
         case if this value goes beyond Period length, this value is mod with 
         Period value */  
        AtomChannelRegPtr->CM1.U = Pwm_lGtmCounterVal(Shift, Period, Dutycycle);
        /* In case of 0 shift, it must be modified to Period to make the 
         behaviour similar to a normal PWM */     
        if(Shift == 0UL)
        {
          Shift = Period;
        }
        AtomChannelRegPtr->CM0.U = Shift;
      }
    }
    else
    {
      if (Dutycycle == 0U)
      {
        AtomChannelRegPtr->SR1.U = 0U;
        AtomChannelRegPtr->SR0.U = Period;
      }
      else if (Dutycycle == Period)
      {
        AtomChannelRegPtr->SR1.U = 2U;
        AtomChannelRegPtr->SR0.U = 2U;
      }
      else
      {
        AtomChannelRegPtr->SR1.U = Pwm_lGtmCounterVal(Shift, Period, Dutycycle);
        if(Shift == 0UL)
        { 
          Shift = Period;
        }
        AtomChannelRegPtr->SR0.U = Shift;
      }
    }
    /* if the PWM channel's previous state is IDLE,then CN0 is reinitialized*/
    if(PwmProperty.PreviousState == PWM_IDLE_CHANNEL)
    {
      AtomChannelRegPtr->CN0.U = Period;
    }
  }
}
/*******************************************************************************
** Syntax : void Pwm_lGtmSLBitConfigStart(                                    **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function configure the SL bit of the control        **
**                   register based on the duty cycle and the Idle state.     **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmSLBitConfigStart
(
  Pwm_ChannelIdentifierType GlobalChannelId, 
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;   /* Ptr to TOM Channel Reg   */
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg  */  
  uint32 Polarity;
  uint8  ModuleNumber;                       /* Holds the module number  */ 
  uint8  ChannelNumber;                      /* Holds the channel number */ 

  
  /* Extract the Module specific information */   
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  Polarity = (uint32)PwmProperty.Polarity;

  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */ 
    /* MISRA Rule Violation 11.4 and 1.2
       Unusual pointer cast (incompatible indirect types)
       cast from pointer to pointer
       Casting of TOM to Gtm_TomChannelRegType is done to change the base 
       type of TOM as the type defined in SFR file is not flexible to 
       provide an arrayed approach for accessing the TOM channels. */
    TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(void*)\
           (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));

    if(Polarity == 1UL)
    {
      Mcal_SetAtomic((sint32*)(void *)(&TomChannelRegPtr->CTRL.U),
                  (PWM_BIT_SET),
                  (sint32)(PWM_GTM_CTRL_SL),
                  (1)
                  );
    }
    else
    {
      Mcal_SetAtomic((sint32*)(void *)(&TomChannelRegPtr->CTRL.U),
                  (0),
                  (sint32)(PWM_GTM_CTRL_SL),
                  (1)
                  );
    }
  }

  
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr = &((*(Ifx_GTM_ATOMx*)(void*)\
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
           
    if(Polarity == 1UL)
    {
                Mcal_SetAtomic((sint32*)(void *)(&AtomChannelRegPtr->CTRL.U),
                  (PWM_BIT_SET),
                  (sint32)(PWM_GTM_CTRL_SL),
                  (1)
                  );
    }
    else
    {
     Mcal_SetAtomic((sint32*)(void *)(&AtomChannelRegPtr->CTRL.U),
                  (0),
                  (sint32)(PWM_GTM_CTRL_SL),
                  (1)
                  );
    }
  }
}
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/*******************************************************************************
** Syntax : boolean Pwm_lGtmGetOutputState(                                   **
**                            Pwm_GlobalChannelNumberType GlobalChannelNumber **
**                                       )                                    **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel number                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function returns the output state of the channel    **
**                                                                            **
*******************************************************************************/
static boolean Pwm_lGtmGetOutputState
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber
)
{
  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;   /* Ptr to TOM Channel Reg        */
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg       */  
  boolean RetVal;                            /* Stores the output state       */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */


  /* Extract the Module specific information */   
  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  RetVal = 0U; 

  /* Detect the Sub-Module type */  
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */ 
    /* MISRA Rule Violation 11.4 and 1.2
       Unusual pointer cast (incompatible indirect types)
       cast from pointer to pointer
       Casting of TOM to Gtm_TomChannelRegType is done to change the base 
       type of TOM as the type defined in SFR file is not flexible to 
       provide an arrayed approach for accessing the TOM channels. */
    TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(void*)\
                    (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));

    /* Returns the OUT bit of the channel Status register */
    RetVal = (boolean)(((TomChannelRegPtr->STAT.U & 1UL) > 0UL)?TRUE:FALSE);

  }
  
  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr =  &((*(Ifx_GTM_ATOMx*)(void*)\
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
   
    /* Returns the OUT bit of the channel Status register */    
    RetVal = (boolean)(((AtomChannelRegPtr->STAT.U & 1UL) > 0UL)?TRUE:FALSE);
  }

  return (RetVal);
}
#endif /* (PWM_GET_OUTPUT_STATE_API == STD_ON) */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*******************************************************************************
** Syntax :void Pwm_lGtmIrqModify   (                                         **
**                           Pwm_GlobalChannelNumberType GlobalChannelNumber  **
**                           uint8 InterruptFlag                              **
**                                    )                                       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber- Channel Number                      **
**                   InterruptFlag - Interrupt bits to set/reset              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Enable/Disable CCU0/CCU1 Interrupt           **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmIrqModify(Pwm_GlobalChannelNumberType GlobalChannelNumber, 
                         uint8 InterruptFlag)
{
  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;   /* Ptr to TOM Channel Register   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; /* Ptr to ATOM Channel Register  */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */

    
  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */ 
    /* MISRA Rule Violation 11.4 and 1.2
       Unusual pointer cast (incompatible indirect types)
       cast from pointer to pointer
       Casting of TOM to Gtm_TomChannelRegType is done to change the base 
       type of TOM as the type defined in SFR file is not flexible to 
       provide an arrayed approach for accessing the TOM channels. */
    TomChannelRegPtr =   &(((*(Ifx_GTM_TOMx*) (void*)\
         (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));
    /* Clear all Pending Interrupts */
    TomChannelRegPtr->IRQ_NOTIFY.U = PWM_CLR_PENDING_INTERRUPTS;
    TomChannelRegPtr->IRQ_EN.U = InterruptFlag;
  }

  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr =   &((*(Ifx_GTM_ATOMx*)(void*)\
           (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
    /* Clear all Pending Interrupts */
    AtomChannelRegPtr->IRQ_NOTIFY.U = PWM_CLR_PENDING_INTERRUPTS;
    AtomChannelRegPtr->IRQ_EN.U = InterruptFlag;
  }
  
}
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

/******************************************************************************
** Syntax :    static _INLINE_ Pwm_17_Gtm_ChannelClassType Pwm_lChanClass    **
**                                                         (uint32 Value)    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_ChannelClassType                            **
**                                                                           **
** Description :      Local function to obtain the channel class             **
**                                                                           **
*****************************************************************************/
static _INLINE_ Pwm_17_Gtm_ChannelClassType Pwm_lChanClass(uint32 Value)
{
 Pwm_17_Gtm_ChannelClassType RetVal;
 
 RetVal = (Pwm_17_Gtm_ChannelClassType) \
           (((uint32)(Value) >> PWM_CHANNEL_MODE_POS) & (PWM_CHANNEL_MODE_MAX));
 return(RetVal);
}

/******************************************************************************
** Syntax :           static _INLINE_ Pwm_17_Gtm_OutputStateType Pwm_lIdle   **
**                                                          (uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_OutputStateType                             **
**                                                                           **
** Description :      Local function to obtain the Idle state from           **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
static _INLINE_ Pwm_17_Gtm_OutputStateType Pwm_lIdle(uint32 Value)
{
 Pwm_17_Gtm_OutputStateType RetVal;
 
 RetVal = (Pwm_17_Gtm_OutputStateType)(((uint32)(Value) >> PWM_IDLESTATE_POS) & 
                                 (PWM_IDLESTATE_MAX)
                               );
 return(RetVal);
}

/******************************************************************************
** Syntax :           static _INLINE_ uint8 Pwm_lPolarity(uint32  Value)     **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8                                                  **
**                                                                           **
** Description :      Local function to obtain the Polarity from             **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint8 Pwm_lPolarity(uint32  Value)
{
 uint8 RetVal;
 RetVal = (Pwm_17_Gtm_OutputStateType)(((uint32)(Value) >> PWM_POLSTATE_POS) & 
                                  (PWM_POLSTATE_MAX)
                                );
 return(RetVal);
}

/******************************************************************************
** Syntax :     static _INLINE_ Pwm_17_Gtm_OutputStateType Pwm_lCoherency    **
**                                                          (uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_OutputStateType                             **
**                                                                           **
** Description :      Local function to obtain the Coherency from            **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
static _INLINE_  Pwm_17_Gtm_OutputStateType Pwm_lCoherency(uint32 Value)
{
   Pwm_17_Gtm_OutputStateType RetVal;
   
   RetVal = (Pwm_17_Gtm_OutputStateType) \
              ( ((uint32)(Value) >> PWM_COHERENCY_POS) & (PWM_COHERENCY_MAX) );
   return(RetVal);
}

#if ( (PWM_FIXED_PERIOD_USED == STD_ON) || (PWM_SET_DUTY_CYCLE_API == STD_ON) )
/******************************************************************************
** Syntax :    static _INLINE_ Pwm_17_Gtm_OutputStateType Pwm_lIsReference   **
**                                                          (uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_OutputStateType                             **
**                                                                           **
** Description :      Local function to obtain whether channel is being      **
**                                              refered from PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
static _INLINE_ Pwm_17_Gtm_OutputStateType Pwm_lIsReference(uint32 Value)
{
  Pwm_17_Gtm_OutputStateType RetVal;
  
  RetVal = (Pwm_17_Gtm_OutputStateType) \
            (((uint32)(Value) >> PWM_ISREFERENCE_POS) & (PWM_ISREFERENCE_MAX));
  return(RetVal);
}
#endif /* (PWM_FIXED_PERIOD_USED == STD_ON) */
/******************************************************************************
** Syntax :           static _INLINE_ uint8 Pwm_lAssignedHW(uint32 Value)    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8                                                  **
**                                                                           **
** Description :      Local function to obtain the Assigned HW Unit from     **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint8 Pwm_lAssignedHW(uint32 Value)
{
  uint8 RetVal;
  
  RetVal = ((uint8)((Value) & (uint32)PWM_HWUNIT_POS));
  return(RetVal);
}

#if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
                              (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
/******************************************************************************
** Syntax :    static _INLINE_ Pwm_17_Gtm_ChannelType Pwm_lReferChan         **
**                                                          (uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_ChannelType                                 **
**                                                                           **
** Description :      Local function to obtain Reference channel Number from **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
static _INLINE_ Pwm_17_Gtm_ChannelType Pwm_lReferChan(uint32 Value)
{
  Pwm_17_Gtm_ChannelType RetVal;
  
  RetVal = (((uint32)(Value) >> PWM_REFERENCE_CHAN_POS) & (PWM_6BIT_MASK));
  return(RetVal);
}
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/******************************************************************************
** Syntax :       static _INLINE_ void Pwm_lSetNotificationStatus            **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the Notification status in the global  **
**                                                      channel variable     **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Pwm_lSetNotificationStatus \
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  Pwm_17_Gtm_ChannelType ChIndex ;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal ;
  #endif
  ChIndex = Pwm_lFindChannelIndex( Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)

    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                  (PWM_BIT_SET),
                  (sint32)(PWM_NOTIFI_STATUS_POS),
                  (PWM_CHAN_ID_STAT_BITS)
                  );

  #endif  
  }
  else 

  #endif
  {
 #if (PWM_MAX_QM_CHANNELS != 0)

    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                   (PWM_BIT_SET),
                   (sint32)(PWM_NOTIFI_STATUS_POS),
                   (PWM_CHAN_ID_STAT_BITS)
                  );

   #endif
  }
}


/******************************************************************************
** Syntax :     static _INLINE_ void Pwm_lClearNotificationStatus            **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Clear the Notification status in the global**
**                                                      channel variable     **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Pwm_lClearNotificationStatus \
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal ;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex ;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal( Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                 (PWM_BIT_RESET),
                 (sint32)(PWM_NOTIFI_STATUS_POS),
                 (PWM_CHAN_ID_STAT_BITS)
                );

   #endif
  }
  else 
  #endif
  {
#if (PWM_MAX_QM_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                 (PWM_BIT_RESET),
                 (sint32)(PWM_NOTIFI_STATUS_POS),
                 (PWM_CHAN_ID_STAT_BITS)
                );

  #endif
  }

}

/******************************************************************************
** Syntax :     static _INLINE_ void Pwm_lSetDuty_0_Or_100_Status            **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the Duty Notification status in the    **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Pwm_lSetDuty_0_Or_100_Status
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex ;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                 (PWM_BIT_SET),
                 (sint32)(PWM_DUTY_0_OR_100_UPDATE_FLGPOS),
                 (PWM_CHAN_ID_STAT_BITS)
                );
  #endif
  }
  else 
  #endif
  {

#if (PWM_MAX_QM_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                 (PWM_BIT_SET),
                 (sint32)(PWM_DUTY_0_OR_100_UPDATE_FLGPOS),
                 (PWM_CHAN_ID_STAT_BITS)
                );
  #endif
  }
}

/******************************************************************************
** Syntax :     static _INLINE_ void Pwm_lClearDuty_0_Or_100_Status          **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to clear the Duty Notification status in the  **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Pwm_lClearDuty_0_Or_100_Status \
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                 (PWM_BIT_RESET),
                 (sint32)(PWM_DUTY_0_OR_100_UPDATE_FLGPOS),
                 (PWM_CHAN_ID_STAT_BITS)
                );

  #endif
  }
  else

  #endif
  {

#if (PWM_MAX_QM_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                 (PWM_BIT_RESET),
                 (sint32)(PWM_DUTY_0_OR_100_UPDATE_FLGPOS),
                 (PWM_CHAN_ID_STAT_BITS)
                );

  #endif
  }
}

/******************************************************************************
** Syntax :      static _INLINE_ void Pwm_lClearNotificationEdges            **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to clear the Notification edges in the        **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Pwm_lClearNotificationEdges  \
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                 (PWM_BIT_RESET),
                 (sint32)(PWM_NOTIFI_EDGE_POS),
                  PWM_NOTIFI_EDGE_BITS
                );

  #endif
  }
  else

  #endif
  {
#if (PWM_MAX_QM_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                 (PWM_BIT_RESET),
                 (sint32)(PWM_NOTIFI_EDGE_POS),
                  PWM_NOTIFI_EDGE_BITS
                );

  #endif
  }
}

/******************************************************************************
** Syntax :           static _INLINE_ void Pwm_lSetNotificationEdges         **
**                    (                                                      **
**                      Pwm_17_Gtm_ChannelType Channel,                      **
**                      Pwm_17_Gtm_EdgeNotificationType Edge                 **
**                    )                                                      **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to set the Notification edges in the          **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Pwm_lSetNotificationEdges(
                                         Pwm_17_Gtm_ChannelType Channel,\
                                         Pwm_17_Gtm_EdgeNotificationType Edge)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                 (uint32)(Edge),
                 (sint32)(PWM_NOTIFI_EDGE_POS),
                  PWM_NOTIFI_EDGE_BITS
                );

  #endif
  }
  else
  #endif
  {
#if (PWM_MAX_QM_CHANNELS != 0)

  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                 (uint32)(Edge),
                 (sint32)(PWM_NOTIFI_EDGE_POS),
                  PWM_NOTIFI_EDGE_BITS
                );
  
  #endif
  }

}

/******************************************************************************
** Syntax :    static _INLINE_ Pwm_17_Gtm_EdgeNotificationType               **
**                   Pwm_lGetNotificationKind(Pwm_17_Gtm_ChannelType Channel)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to get the Notification kind in the           **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
static _INLINE_ Pwm_17_Gtm_EdgeNotificationType 
                Pwm_lGetNotificationKind(Pwm_17_Gtm_ChannelType Channel)
{
  Pwm_17_Gtm_EdgeNotificationType RetVal;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if ( (PWM_MAX_ASIL_CHANNELS == 0) || (PWM_MAX_QM_CHANNELS == 0) )
  RetVal = 0U;
  #endif
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  
  RetVal = ((Pwm_17_Gtm_EdgeNotificationType)(Pwm_GlobChn_Asil[(ChIndex)] & 
                                       PWM_NOTIFICATION_EDGE_MASK)
           );
  
  #endif
  }
  else
  
  #endif
  {
  
#if (PWM_MAX_QM_CHANNELS != 0)
  
  RetVal = ((Pwm_17_Gtm_EdgeNotificationType)(Pwm_GlobChn_Qm[(ChIndex)] & 
                                       PWM_NOTIFICATION_EDGE_MASK)
           );
  
  #endif
  }
  return(RetVal);
}

#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/******************************************************************************
** Syntax :        static _INLINE_ void Pwm_lSetChannelIdleStatus            **
**                                           (Pwm_17_Gtm_ChannelType Channel)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the idle status in the                 **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Pwm_lSetChannelIdleStatus(
                           Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  
  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                 (PWM_BIT_SET),
                 (sint32)(PWM_IDLE_CHANNEL_FLAG_POS),
                 (PWM_CHAN_ID_STAT_BITS)
                );
  
  #endif
  }
  else
  
  #endif
  {
#if (PWM_MAX_QM_CHANNELS != 0)
  
  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                 (PWM_BIT_SET),
                 (sint32)(PWM_IDLE_CHANNEL_FLAG_POS),
                 (PWM_CHAN_ID_STAT_BITS)
                );
  
  #endif
  }
}
#endif /* (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) */

/******************************************************************************
** Syntax :        static _INLINE_ uint32 Pwm_lGetChannelIdleStatus          **
**                                           (Pwm_17_Gtm_ChannelType Channel)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8                                                  **
**                                                                           **
** Description :      Function to get the idle status  from the              **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Pwm_lGetChannelIdleStatus
                                               (Pwm_17_Gtm_ChannelType Channel)
{
  uint32 RetVal;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);

  #if (PWM_SAFETY_ENABLE == STD_ON)

  #if ( (PWM_MAX_ASIL_CHANNELS == 0) || (PWM_MAX_QM_CHANNELS == 0) )
  RetVal = 0U;
  #endif

  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  
  RetVal = (uint32)(Pwm_GlobChn_Asil[(ChIndex)] & PWM_IDLE_STATUS_MASK );
  
  #endif
  }
  else
  #endif
  {
  
#if (PWM_MAX_QM_CHANNELS != 0)
  
  RetVal = (uint32)(Pwm_GlobChn_Qm[(ChIndex)] & PWM_IDLE_STATUS_MASK );
  
  #endif
  }
  return(RetVal);
}

#if((PWM_SET_DUTY_CYCLE_API == STD_ON)||(PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
/******************************************************************************
** Syntax :           static _INLINE_ void Pwm_lClearIdleStatus              **
**                                           (Pwm_17_Gtm_ChannelType Channel)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to clear the Notification edges in the        **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Pwm_lClearIdleStatus(Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                    (PWM_BIT_RESET),(sint32)(PWM_IDLE_CHANNEL_FLAG_POS),
                    (PWM_CHAN_ID_STAT_BITS)
                   );
    #endif
  }
  else
  #endif
  {
    
  #if (PWM_MAX_QM_CHANNELS != 0)
    
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                    (PWM_BIT_RESET),(sint32)(PWM_IDLE_CHANNEL_FLAG_POS),
                    (PWM_CHAN_ID_STAT_BITS)
                   );
    
    #endif
  }
}
#endif

/******************************************************************************
** Syntax :           static _INLINE_ uint32_t Pwm_lGtmCounterVal            **
**                          (uint32 Shift, uint32 Period, uint32 DutyCycle)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Shift : Channel shift value                            **
**                    Period : Channel period value                          **
**                    DutyCycle : Channel duty value                         **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32                                                 **
**                                                                           **
** Description :      Function to calculate the gtm counter                  **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Pwm_lGtmCounterVal
(
  uint32 Shift, 
  uint32 Period, 
  uint32 DutyCycle
)
{
  uint32 RetVal;

  if((Shift + DutyCycle) == Period)
  {
    RetVal = Period;
  }
  else
  {
    RetVal = (uint32)((Shift + DutyCycle) % Period);
  }

  return(RetVal);

}


/*******************************************************************************
**                                                                            **
** Syntax : Pwm_ChannelIdentifierType Pwm_lGtmChannelIdentifier               **
**                           (Pwm_GlobalChannelNumberType GlobalChannelNumber)**
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    GlobalChannelNumber - Channel Number                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:  Structure which gives Module Number, Channel Number etc     **
**                                                                            **
** Description :  This routine converts the Global Channel Number to its      **
**                corresponding Channel Number, Module Number, TGC/AGC number.**
**                                                                            **
*******************************************************************************/
Pwm_ChannelIdentifierType Pwm_lGtmChannelIdentifier(
                               Pwm_GlobalChannelNumberType GlobalChannelNumber )
{
  Pwm_ChannelIdentifierType ChannelIdentifier;
  Pwm_GlobalChannelNumberType TempChannelNumber;


  ChannelIdentifier.ChannelNo = PWM_INVALID_NUMBER;
  ChannelIdentifier.ModuleId = PWM_INVALID_NUMBER;
  ChannelIdentifier.ModuleNo = PWM_INVALID_NUMBER;
  ChannelIdentifier.GroupNo = PWM_INVALID_NUMBER;
  

  #if(GTM_TOM_USED_BY_OTHER_DRIVERS == STD_ON)
  /* Check if its a TOM channel */
  if((GlobalChannelNumber >= GTM_MAX_TIM_CHANNELS)  &&
      (GlobalChannelNumber < (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS)))
  {
    TempChannelNumber = GlobalChannelNumber - GTM_MAX_TIM_CHANNELS;
    /* Calculate Module Id of the TOM channel */
    ChannelIdentifier.ModuleId = GTM_TOM_MODULE;
    ChannelIdentifier.ModuleNo  =                    \
                 (uint8)(TempChannelNumber / GTM_CHANNELS_PER_TOM_MODULE);

    /* Calculate Channel number of the TOM channel */
    ChannelIdentifier.ChannelNo= TempChannelNumber %GTM_CHANNELS_PER_TOM_MODULE;
    ChannelIdentifier.GroupNo = 
                       (ChannelIdentifier.ChannelNo)/GTM_TOM_CHANNELS_PER_TGC;

  }
  #endif /*   #if(GTM_TOM_USED_BY_OTHER_DRIVERS == STD_ON)   */

  #if(GTM_ATOM_USED_BY_OTHER_DRIVERS == STD_ON)
  /* Check if its a ATOM channel */
  if((GlobalChannelNumber >= (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS))
    && (GlobalChannelNumber <                                                  \
         (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS + GTM_MAX_ATOM_CHANNELS)))
  {

    TempChannelNumber =
            GlobalChannelNumber - (GTM_MAX_TIM_CHANNELS + GTM_MAX_TOM_CHANNELS);
    /* Calculate Module Id of the ATOM channel */
    ChannelIdentifier.ModuleId = GTM_ATOM_MODULE;
    ChannelIdentifier.ModuleNo  =                                   \
                    (uint8)(TempChannelNumber / GTM_CHANNELS_PER_ATOM_MODULE);

    /* Calculate Channel number of the ATOM channel */
    ChannelIdentifier.ChannelNo = 
                               TempChannelNumber%GTM_CHANNELS_PER_ATOM_MODULE;
  }
  #endif 
  /*   #if(GTM_ATOM_USED_BY_OTHER_DRIVERS == STD_ON)   */

  return (ChannelIdentifier);
}


#if (PWM_SAFETY_ENABLE == STD_ON)
/******************************************************************************
** Syntax :           static _INLINE_ uint32 Pwm_lSafetyPeriodRangeCheck     **
**                                    ( uint8           ServiceID,           **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber,**
**                                      Pwm_17_Gtm_PeriodType Period  )      **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceID    : Informs Service ID of an API            **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                    Period       : Channel period value                    **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32  ErrStatus indicates error has occured or not   **
**                                                                           **
** Description :      Function to Check if Period is within specified range  **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Pwm_lSafetyPeriodRangeCheck(
                                   uint8                   ServiceID,
                                   Pwm_17_Gtm_ChannelType  ChannelNumber,
                                   Pwm_17_Gtm_PeriodType   Period
                                 )
{
  Pwm_ChannelIdentifierType GlobalChannelId;
  uint8              CellUsed;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  uint32                       ErrStatus;
  ErrStatus = (uint32)0;
  LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  /* Get the type of channel used */
  CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
  GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    if (Period > (Pwm_17_Gtm_PeriodType)0xFFFE)
    {
      /* Report Safety Error */
      SafeMcal_ReportError( 
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID, 
                            ServiceID,
                            PWM_E_PERIOD_OUT_OF_RANGE
                          );
    ErrStatus = PWM_ERROR_FOUND; 
    }
  }
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    if (Period > (Pwm_17_Gtm_PeriodType)0xFFFFFE)
    {
      SafeMcal_ReportError( 
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID, 
                            ServiceID,
                            PWM_E_PERIOD_OUT_OF_RANGE
                           );
       ErrStatus = PWM_ERROR_FOUND;
    }
  }
  return ErrStatus;
} 
/******************************************************************************
** Syntax :           static _INLINE_ uint32 Pwm_lSafetyDutyRangeCheck       **
**                                    ( uint8           ServiceID,           **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber,**
**                                      Pwm_17_Gtm_DutyType Duty  )          **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceID    : Informs Service ID of an API            **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                    Duty         : Channel Duty cycle value                **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32  ErrStatus indicates error has occured or not   **
**                                                                           **
** Description :      Function to Check if Duty is within specified range    **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Pwm_lSafetyDutyRangeCheck( uint8   ServiceID,\
                                 Pwm_17_Gtm_ChannelType   ChannelNumber,\
                                 uint32                   Duty)
{

  uint32                       ErrStatus;
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  Pwm_ChannelIdentifierType   GlobalChannelId;
  uint8                       CellUsed;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  #endif  
  ErrStatus = (uint32)0;
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
  if (Duty > (uint32)0x8000)
  {
  /* Report Safety Error */
  SafeMcal_ReportError(
                        PWM_17_GTM_MODULE_ID,
                        PWM_17_GTM_INSTANCE_ID,
                        ServiceID,
                        PWM_E_DUTY_OUT_OF_RANGE
                       );
  ErrStatus = PWM_ERROR_FOUND; 
  UNUSED_PARAMETER(ChannelNumber)
  }
  #else
  LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  /* Get the type of channel used */
  CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
  GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    if (Duty > (uint32)0xFFFE)
    {
      /* Report Safety Error */
      SafeMcal_ReportError(
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID,
                            ServiceID,
                            PWM_E_DUTY_OUT_OF_RANGE
                          );
     ErrStatus = PWM_ERROR_FOUND; 
    }
  }
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    if (Duty > (uint32)0xFFFFFE)
    {
      SafeMcal_ReportError( 
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID,
                            ServiceID,
                            PWM_E_DUTY_OUT_OF_RANGE
                           );
       ErrStatus = PWM_ERROR_FOUND;
    }
  }
  #endif
  return ErrStatus;
}

/******************************************************************************
** Syntax :           static _INLINE_ uint8 Pwm_lFindChannelSignal           **
**                                    (                                      **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):                                                          **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                                                                           **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8 ChannelSignal: Returns if channel is ASIL or QM  **
**                                                                           **
** Description :      Function to Find channel Signal Type for safety signals**
**                                                                           **
*****************************************************************************/
static _INLINE_ uint8 Pwm_lFindChannelSignal(
                                          Pwm_17_Gtm_ChannelType ChannelNumber)
{
  uint8 ChannelSignal;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  /* Get the type of channel used */
  ChannelSignal = LocalPwmChanPtr->SafetyChannelSignal;
  return (ChannelSignal); 
}
#endif
/******************************************************************************
** Syntax :           static _INLINE_ Pwm_17_Gtm_ChannelType                 **
**                                        Pwm_lFindChannelIndex             **
**                                    (                                      **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber **
**                                    )                                      **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):                                                          **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                                                                           **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8 ChannelIndex: Channel index to access global     **
**                    variable                                               **
**                                                                           **
** Description :      Function to Find channel Index for safety signals      **
**                                                                           **
*****************************************************************************/
static _INLINE_ Pwm_17_Gtm_ChannelType Pwm_lFindChannelIndex (
                                       Pwm_17_Gtm_ChannelType ChannelNumber)
{
  Pwm_17_Gtm_ChannelType ChannelIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  /* Get the type of channel used */
  ChannelIndex = LocalPwmChanPtr->SafetyChannelIndex;
  #else
  ChannelIndex = ChannelNumber;
  #endif
  return (ChannelIndex); 
}

#define PWM_17_GTM_STOP_SEC_CODE
#include "MemMap.h"

#define PWM_17_GTM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
/******************************************************************************
** Syntax :          void Pwm_17_Gtm_Isr                                     **
**                   ( Pwm_GlobalChannelNumberType TomAtomChannelNumber )    **
**                                                                           **
** Service ID:       none                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       Depends on the implementation of Notification function  **
**                                                                           **
** Parameters (in):  TomAtomChannelNumber : Numeric identifier of TOM/ATOM   **
**                                          channel                          **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service will be used only in an interrupt           **
**               2. In this service depending on conditions Notification will**
**                   be provided                                             **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM025] [/cover]                                    **
** [cover parentID=DS_AS_PWM026_PWM115c] [/cover]                            **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_Isr(Pwm_17_Gtm_ChannelType ChannelNumber)
{
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Even by mistake interrupt occurs for immediate update type,
     don't provide notification */
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  /* Here only notification has to be provided */
  Pwm_17_Gtm_ChannelType ChIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  uint8 ErrorFlag;
  #endif
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ErrorFlag = 0U;
  if( ChannelNumber > Pwm_kConfigPtr->MaxChannels)
  { 
    /* Report Safety Error */
    SafeMcal_ReportError( 
                          PWM_17_GTM_MODULE_ID,
                          PWM_17_GTM_INSTANCE_ID,
                          PWM_SID_ISR,
                          PWM_E_PARAM_CHANNEL
                         );
    ErrorFlag = 1U;
  }
  if(ErrorFlag == 0U)
  #endif
  {
    ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    #if (PWM_SAFETY_ENABLE == STD_ON)
    ChSignal=Pwm_lFindChannelSignal(ChannelNumber);
    if (ChSignal == PWM_ASIL_TYPE)
    {  
      #if (PWM_MAX_ASIL_CHANNELS != 0)
      
      if ((Pwm_GlobChn_Asil[ChIndex] & PWM_NOTIFI_STATUS_MASK) ==
                       PWM_NOTIFI_STATUS_MASK)
      {
        /* PWM025: PWM035: Provide Notification */
        /* PWM032: Call back functions has no parameters */
        (LocalPwmChanPtr->Notification)();
      }
      else
      {
        SafeMcal_ReportError( 
                             PWM_17_GTM_MODULE_ID,
                             PWM_17_GTM_INSTANCE_ID, 
                             PWM_SID_ISR,
                             PWM_E_WRONG_NOTIF
                            );
      }
      
      #endif
    }
    else
    #endif
    {
      #if (PWM_MAX_QM_CHANNELS != 0)
      
      #ifndef VALEO_PATCH_MCAL_PWM_NOTIF_ON_0_AND_100_PERCENT
      if ((Pwm_GlobChn_Qm[ChIndex] & PWM_NOTIFI_STATUS_MASK) ==
                       PWM_NOTIFI_STATUS_MASK)
      #endif /* VALEO_PATCH_MCAL_PWM_NOTIF_ON_0_AND_100_PERCENT */
      {
        /* PWM025: PWM035: Provide Notification */
        /* PWM032: Call back functions has no parameters */
        (LocalPwmChanPtr->Notification)();
      }
      #if (PWM_SAFETY_ENABLE == STD_ON)    
      else 
      {
        SafeMcal_ReportError( 
                             PWM_17_GTM_MODULE_ID,
                             PWM_17_GTM_INSTANCE_ID, 
                             PWM_SID_ISR,
                             PWM_E_WRONG_NOTIF
                            );
      }
      
      #endif
     #endif
    }
  }  /* PWM_NOTIFICATION_SUPPORTED */
  #else
  /* to remove unused param warning in GNU */
  UNUSED_PARAMETER(ChannelNumber)
  #endif 
}

/* End of Pwm_17_Gtm_Isr() function */
#define PWM_17_GTM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/***************** End of PWM driver module **********************************/
