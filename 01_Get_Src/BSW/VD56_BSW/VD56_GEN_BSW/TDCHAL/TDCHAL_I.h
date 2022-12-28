/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TDCHAL                                                  */
/* !Description     : TDCHAL Component                                        */
/*                                                                            */
/* !File            : TDCHAL_I.h                                              */
/* !Description     : Setpoint Management                                     */
/*                                                                            */
/* !Reference       : PTS DOC 5038320                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A276.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef TDCHAL_I_H
#define TDCHAL_I_H

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CRKHAL.h"
#include "SWFAIL.h"
#include "TDCHAL_Cfg.h"
#include "TDCHAL_L.h"

#ifndef TDCHAL_coBDC_ENABLED
   #error "TDCHAL_coBDC should be defined"
#endif

#ifndef TDCHAL_coBDC_CALC_PER_ON_ENABLED
   #error "TDCHAL_coBDC_CALC_PER_ON_ENABLED should be defined"
#endif

#ifndef TRUE
   #error "TRUE should be defined"
#endif

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define TDCHAL_START_SEC_CALIB_8BIT
#include "TDCHAL_MemMap.h"

/* !MComment: TDC counter at each setpoint.                                   */
extern const uint8 TDCHAL_kau8TDCCounter[TDCHAL_u8MAX_NB_SETPOINTS];

/* !MComment: Array of indices to choose which action to take on SetPoint.    */
extern const uint8 TDCHAL_kau8OnSetPointIdx[TDCHAL_u8MAX_NB_SETPOINTS];

#define TDCHAL_STOP_SEC_CALIB_8BIT
#include "TDCHAL_MemMap.h"

#define TDCHAL_START_SEC_CALIB_16BIT
#include "TDCHAL_MemMap.h"

/* !MComment: Setpoints angles                                                */
extern const uint16 TDCHAL_kau16SetPointAngles[TDCHAL_u8MAX_NB_SETPOINTS];

#define TDCHAL_STOP_SEC_CALIB_16BIT
#include "TDCHAL_MemMap.h"

/******************************************************************************/
/* DATA DECLARATIONS                                                          */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : TDCHAL_vidGET_TDC_COUNTER                                   */
/* !Description : Get TDC counter for current setpoint.                       */
/*                                                                            */
/* !LastAuthor  : M. Khalaf-Allah                                             */
/******************************************************************************/
#define TDCHAL_vidGET_TDC_COUNTER( \
   u8Counter      /* !Comment: TDC counter will return in this argout       */ \
) \
do \
{ \
   if(TDCHAL_u8CurrentSetpoint >= TDCHAL_ku8NbSetPoints) \
   { \
      TDCHAL_u8CurrentSetpoint = UINT8_MIN; \
      SWFAIL_vidSoftwareErrorHook(); \
   } \
   (u8Counter) = \
      TDCHAL_kau8TDCCounter[TDCHAL_u8CurrentSetpoint]; \
} \
while (0)

/******************************************************************************/
/* !FuncName    : TDCHAL_vidFIND_LAST_SETPOINT                                */
/* !Description : Find setpoint preceding current angular position.           */
/*                                                                            */
/* !LastAuthor  : M. Khalaf-Allah                                             */
/******************************************************************************/
#define TDCHAL_vidFIND_LAST_SETPOINT() \
do \
{ \
   uint16 u16LocalPosition; \
   uint8  u8LocalSetPoint;  \
   \
   \
   u16LocalPosition = CRKHAL_u16ReadCounter(CRKHAL_u8ALARM_TDC); \
   u16LocalPosition = (uint16)(u16LocalPosition + TDCHAL_u16ANGULAR_MARGIN); \
   if (u16LocalPosition >= TDCHAL_u16ENGINE_CYCLE) \
   { \
      u16LocalPosition = (uint16)(u16LocalPosition - TDCHAL_u16ENGINE_CYCLE); \
   } \
   u8LocalSetPoint = UINT8_MIN; \
   \
   /* !MComment: First, find setpoint following the current position     */ \
   while (  (u16LocalPosition >= TDCHAL_kau16SetPointAngles[u8LocalSetPoint]) \
         && (u8LocalSetPoint < TDCHAL_ku8NbSetPoints)) \
   { \
      u8LocalSetPoint++; \
   } \
   \
   /* !MComment: Then, deduce setpoint preceding the current position    */ \
   if(u8LocalSetPoint != UINT8_MIN) \
   { \
      u8LocalSetPoint--; \
   } \
   else \
   { \
      u8LocalSetPoint = TDCHAL_ku8NbSetPoints - 1; \
   } \
   TDCHAL_u8CurrentSetpoint = u8LocalSetPoint; \
} \
while (0)

/******************************************************************************/
/* !FuncName    : TDCHAL_vidON_SETPOINT                                       */
/* !Description : Calls the callback function associated to current setpoint. */
/*                                                                            */
/* !LastAuthor  : M. Khalaf-Allah                                             */
/******************************************************************************/
#define TDCHAL_vidON_SETPOINT() \
do \
{ \
   uint8 u8LocalActionIdx; \
   if(TDCHAL_u8CurrentSetpoint < TDCHAL_ku8NbSetPoints) \
   { \
      u8LocalActionIdx = TDCHAL_kau8OnSetPointIdx[TDCHAL_u8CurrentSetpoint]; \
      if(u8LocalActionIdx < TDCHAL_u8NB_ACTIONS_ON_SETPOINT) \
      { \
         TDCHAL_kapfvidOnSetPoint[u8LocalActionIdx](); \
      } \
      else \
      { \
         SWFAIL_vidSoftwareErrorHook(); \
      } \
   } \
   else \
   { \
      TDCHAL_u8CurrentSetpoint = UINT8_MIN; \
      SWFAIL_vidSoftwareErrorHook(); \
   } \
} \
while (0)

/******************************************************************************/
/* !FuncName    : TDCHAL_vidNEXT_SETPOINT                                     */
/* !Description : Update the current setpoint to next position.               */
/*                                                                            */
/* !LastAuthor  : M. Khalaf-Allah                                             */
/******************************************************************************/
#define TDCHAL_vidNEXT_SETPOINT() \
do \
{ \
   TDCHAL_u8CurrentSetpoint++; \
   if (TDCHAL_u8CurrentSetpoint >= TDCHAL_ku8NbSetPoints) \
   { \
      TDCHAL_u8CurrentSetpoint = UINT8_MIN; \
   } \
} \
while (0)

/******************************************************************************/
/* !FuncName    : TDCHAL_vidPROGRAM_SETPOINT                                  */
/* !Description : Program crank alarm to match at currently desired setpoint. */
/*                                                                            */
/* !LastAuthor  : M. Khalaf-Allah                                             */
/******************************************************************************/
#define TDCHAL_vidPROGRAM_SETPOINT() \
do \
{ \
   if(TDCHAL_u8CurrentSetpoint < TDCHAL_ku8NbSetPoints) \
   { \
      CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_TDC, \
           TDCHAL_kau16SetPointAngles[TDCHAL_u8CurrentSetpoint]); \
   } \
   else \
   { \
      TDCHAL_u8CurrentSetpoint = UINT8_MIN; \
      SWFAIL_vidSoftwareErrorHook(); \
   } \
} \
while (0)

#endif /* TDCHAL_I_H */

/*-------------------------------- end of file -------------------------------*/
