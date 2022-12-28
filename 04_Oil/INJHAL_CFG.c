/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : Injection Hardware Abstraction Layer                    */
/*                                                                            */
/* !File            : INJHAL_CFG.c                                            */
/* !Description     : Configuration of the INJHAL Component                   */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/

#include "Std_Limits.h"
#include "Std_Types.h"

#include "INJHAL.h"
#include "INJHAL_CFG_I.h"
#include "INJHAL_TYP.h"
#include "INJHAL_L.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/*************************************************************************/
/* Boolean Calibrations                                                  */
/*************************************************************************/
#define INJHAL_START_SEC_CALIB_BOOLEAN
#include "INJHAL_MemMap.h"
/*lint -esym(960,8.7) */
CONST(boolean, INJHAL_CALIB)
   INJHAL_kabEnableAngleUpdate[INJHAL_u8NB_INSTANCES] =
   {
      (boolean)FALSE
   };


#define INJHAL_STOP_SEC_CALIB_BOOLEAN
#include "INJHAL_MemMap.h"


/*************************************************************************/
/* uint16 Calibrations                                                   */
/*************************************************************************/
#define INJHAL_START_SEC_CALIB_16BIT
#include "INJHAL_MemMap.h"

CONST(uint16, INJHAL_CALIB) INJHAL_ku16CM_66_CycleRef = (uint16)UINT16_MIN;
CONST(uint16, INJHAL_CALIB) INJHAL_ku16CM_45_CycleRef = (uint16)UINT16_MIN;
CONST(uint16, INJHAL_CALIB) INJHAL_ku16CM_24_CycleRef = (uint16)UINT16_MIN;

#define INJHAL_STOP_SEC_CALIB_16BIT
#include "INJHAL_MemMap.h"


/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/
/*************************************************************************/
/* boolean Const                                                         */
/*************************************************************************/
#define INJHAL_START_SEC_CONST_BOOLEAN
#include "INJHAL_MemMap.h"

CONST(boolean, INJHAL_CONST)
   INJHAL_kabPreInjAuthorization[INJHAL_u8NB_INSTANCES] =
   {
      (boolean)INJHAL_bPRE_INJ_AUTHORIZED,
   };

#define INJHAL_STOP_SEC_CONST_BOOLEAN
#include "INJHAL_MemMap.h"


/*************************************************************************/
/* 8 Bits Const                                                          */
/*************************************************************************/
#define INJHAL_START_SEC_CONST_8BIT
#include "INJHAL_MemMap.h"

CONST(uint8, INJHAL_CONST)
   INJHAL_kau8InstanceOffset[INJHAL_u8NB_INSTANCES] =
   {
      CM_66,
   };

CONST(uint8, INJHAL_CONST)
   INJHAL_kau8NbInjectors[INJHAL_u8NB_INSTANCES] =
   {
      3u,
   };

CONST(uint8, INJHAL_CONST)
   INJHAL_kau8CrkhalChannel[INJHAL_u8NB_INJECTORS] =
   {
      INJHAL_u8CRKHAL_SN_CM_66_CH,
      INJHAL_u8CRKHAL_SN_CM_45_CH,
      INJHAL_u8CRKHAL_SN_CM_24_CH,
   };

CONST(uint8, INJHAL_CONST)
   INJHAL_kau8ChannelForPreInj[INJHAL_u8NB_INSTANCES] =
   {
      CM_66,
   };

#define INJHAL_STOP_SEC_CONST_8BIT
#include "INJHAL_MemMap.h"


/*************************************************************************/
/* User Defined Const (Unspecified)                                      */
/*************************************************************************/
#define INJHAL_START_SEC_CONST_UNSPECIFIED
#include "INJHAL_MemMap.h"

CONST(INJHAL_tudtInjectorPhase, INJHAL_CONST)
   INJHAL_kaudtCorrespInjectorPhase[INJHAL_u8NB_INJ_PULSES] =
   {
      INJHAL_udtBEFORE_PULSE_1,
      INJHAL_udtBEFORE_PULSE_2,
      INJHAL_udtBEFORE_PULSE_3,
      INJHAL_udtBEFORE_PULSE_4,
      INJHAL_udtBEFORE_PULSE_5,
   };

CONST(INJHAL_tpfvidAngleNotifFunction, INJHAL_CODE)
   INJHAL_kapfvidAngleNotifFunction[INJHAL_u8NB_INJECTORS] =
   {
      &INJHAL_vidSN_CM_66_ANGLE_NOTIF,
      &INJHAL_vidSN_CM_45_ANGLE_NOTIF,
      &INJHAL_vidSN_CM_24_ANGLE_NOTIF,
   };

#define INJHAL_STOP_SEC_CONST_UNSPECIFIED
#include "INJHAL_MemMap.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/*************************************************************************/
/* Boolean Variables                                                     */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "INJHAL_MemMap.h"

VAR(boolean, INJHAL_VAR) INJHAL_abEnable[INJHAL_u8NB_INSTANCES];
VAR(boolean, INJHAL_VAR) INJHAL_abEnableFGPreInj[INJHAL_u8NB_INSTANCES];
VAR(boolean, INJHAL_VAR) INJHAL_abEnableSeqPreInj[INJHAL_u8NB_INSTANCES];
VAR(boolean, INJHAL_VAR) INJHAL_abInjectionTimeUpdated[INJHAL_u8NB_INJECTORS];
VAR(boolean, INJHAL_VAR) INJHAL_abInjStarted[INJHAL_u8NB_INSTANCES];

VAR(boolean, INJHAL_VAR) INJHAL_abEndOfPreInjTreated[INJHAL_u8NB_INSTANCES];
VAR(boolean, INJHAL_VAR) INJHAL_abFGPreInjEndAngReady[INJHAL_u8NB_INSTANCES];
VAR(boolean, INJHAL_VAR) INJHAL_abFGPreInjStartAngReady[INJHAL_u8NB_INSTANCES];

#define INJHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* 8 Bit Variables                                                       */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_8BIT
#include "INJHAL_MemMap.h"

VAR(uint8, INJHAL_VAR) INJHAL_aenuInjectorMode[INJHAL_u8NB_INJECTORS];
VAR(uint8, INJHAL_VAR) INJHAL_au8AngleMatch[INJHAL_u8NB_INJECTORS];
VAR(uint8, INJHAL_VAR) INJHAL_aenuInjComponentStatus[INJHAL_u8NB_INSTANCES];
VAR(uint8, INJHAL_VAR) INJHAL_au8InjectionMode[INJHAL_u8NB_INJECTORS];

#define INJHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* 16 Bit Variables                                                      */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_16BIT
#include "INJHAL_MemMap.h"

VAR(uint16, INJHAL_VAR) INJHAL_u16CM_66_CycleRef;
VAR(uint16, INJHAL_VAR) INJHAL_u16CM_45_CycleRef;
VAR(uint16, INJHAL_VAR) INJHAL_u16CM_24_CycleRef;

VAR(uint16, INJHAL_VAR) INJHAL_au16AngleForPreInj[INJHAL_u8NB_INSTANCES];
VAR(uint16, INJHAL_VAR) INJHAL_au16FGPreInjEndAngle[INJHAL_u8NB_INSTANCES];
VAR(uint16, INJHAL_VAR)
   INJHAL_au16InjectionAngle[INJHAL_u8NB_INJ_PULSES][INJHAL_u8NB_INJECTORS];
VAR(uint16, INJHAL_VAR) INJHAL_au16NoOverLap[INJHAL_u8NB_INJECTORS];
VAR(uint16, INJHAL_VAR)
   INJHAL_au16ProgAngleForPreInj[INJHAL_u8NB_INSTANCES];
VAR(uint16, INJHAL_VAR) INJHAL_au16SeqPreInjAngle[INJHAL_u8NB_INJECTORS];
VAR(uint16, INJHAL_VAR) INJHAL_au16TimerRunning[INJHAL_u8NB_INJECTORS];

#define INJHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* 32 Bit Variables                                                      */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_32BIT
#include "INJHAL_MemMap.h"

VAR(uint32, INJHAL_VAR) INJHAL_au32FGPreInjTime[INJHAL_u8NB_INSTANCES];
VAR(uint32, INJHAL_VAR)
   INJHAL_au32InjectionTime[INJHAL_u8NB_INJ_PULSES][INJHAL_u8NB_INJECTORS];
VAR(uint32, INJHAL_VAR) INJHAL_au32PrevInjectionTime[INJHAL_u8NB_INJECTORS];
VAR(uint32, INJHAL_VAR) INJHAL_au32SeqPreInjTime[INJHAL_u8NB_INJECTORS];

#define INJHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* User Defined Variables (Unspecified)                                  */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "INJHAL_MemMap.h"

VAR(INJHAL_tbfAngleUpdate, INJHAL_VAR)
   INJHAL_abfAngleUpdate[INJHAL_u8NB_INSTANCES];
VAR(INJHAL_tbfInhibitMask, INJHAL_VAR)
   INJHAL_abfInjectionCut[INJHAL_u8NB_INSTANCES];
VAR(INJHAL_tbfTimeUpdate, INJHAL_VAR)
   INJHAL_abfTimeUpdate[INJHAL_u8NB_INSTANCES];
VAR(INJHAL_tudtInjectorPhase, INJHAL_VAR)
   INJHAL_audtCurrentInjectorPhase[INJHAL_u8NB_INJECTORS];

volatile Ifx_GTM_ATOM_CH* INJHAL_pstrSN_CM_66;
volatile Ifx_GTM_ATOM_AGC* INJHAL_pstrAgcSN_CM_66;
volatile Ifx_GTM_ATOM_CH* INJHAL_pstrSN_CM_45;
volatile Ifx_GTM_ATOM_AGC* INJHAL_pstrAgcSN_CM_45;
volatile Ifx_GTM_ATOM_CH* INJHAL_pstrSN_CM_24;
volatile Ifx_GTM_ATOM_AGC* INJHAL_pstrAgcSN_CM_24;


#define INJHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "INJHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
