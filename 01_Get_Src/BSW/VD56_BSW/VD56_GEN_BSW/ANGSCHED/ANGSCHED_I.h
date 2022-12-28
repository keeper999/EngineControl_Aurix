/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : ANGSCHED                                                */
/* !Description     : Angular scheduler Component                             */
/*                                                                            */
/* !File            : ANGSCHED_I.h                                            */
/* !Description     : Internal Macros                                         */
/*                                                                            */
/* !Reference       : V03 NT 10 08984                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A30426.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#ifndef ANGSCHED_I_H
#define ANGSCHED_I_H

#include "Std_Types.h"
#include "Std_Limits.h"
#include "ANGSCHED.h"
#include "ANGSCHED_L.h"
#include "ANGSCHED_CFG.h"
#include "ANGSCHED_TYPES.h"
#include "CRKHAL.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/* !Description: Init angsched alarm variables                                */
/* !Number     : 1                                                            */
/*                                                                            */
/* !LastAuthor : Y. Badr                                                      */
/******************************************************************************/
#define ANGSCHED_vidINIT_ALARM(snAngschedAlarm) \
do \
{ \
   CRKHAL_vidDisableAlarmNotif(ANGSCHED_CRKHAL_CH_##snAngschedAlarm); \
   CRKHAL_vidDeactivateAlarmMode(ANGSCHED_CRKHAL_CH_##snAngschedAlarm);\
   ANGSCHED_bEnabled_##snAngschedAlarm = FALSE; \
   ANGSCHED_u8NextAngleIdx_##snAngschedAlarm = UINT8_MIN; \
} \
while(0)

/******************************************************************************/
/*                                                                            */
/* !Description: Find the nearest next angle in the angle table of            */
/*               snAngschedAlarm.                                             */
/* !Number     : 2                                                            */
/*                                                                            */
/* !LastAuthor : Y. Badr                                                      */
/******************************************************************************/
#define ANGSCHED_vidFIND_NEAREST_ANGLE(snAngschedAlarm) \
do \
{ \
   uint16 u16LocalPosition; \
   uint8  u8LocalAngleIndex;  \
   \
   u16LocalPosition = \
      CRKHAL_u16ReadCounter(ANGSCHED_CRKHAL_CH_##snAngschedAlarm); \
   u8LocalAngleIndex = UINT8_MIN; \
   \
   while ( (u16LocalPosition >= \
              ANGSCHED_kau16Angles_##snAngschedAlarm[u8LocalAngleIndex]) \
           && (u8LocalAngleIndex < ANGSCHED_ku8AnglesNum_##snAngschedAlarm)) \
   { \
      u8LocalAngleIndex++; \
   } \
   if(u8LocalAngleIndex == ANGSCHED_ku8AnglesNum_##snAngschedAlarm) \
   { \
      u8LocalAngleIndex = 0; \
   } \
   ANGSCHED_u8NextAngleIdx_##snAngschedAlarm = u8LocalAngleIndex; \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !Description: Program snAngschedAlarm with the next angle.                 */
/* !Number     : 3                                                            */
/*                                                                            */
/* !LastAuthor : Y. Badr                                                      */
/******************************************************************************/
#define ANGSCHED_vidPROGRAM_NEXT_ANGLE(snAngschedAlarm) \
do \
{ \
   if(ANGSCHED_u8NextAngleIdx_##snAngschedAlarm < \
        ANGSCHED_ku8AnglesNum_##snAngschedAlarm) \
   { \
      CRKHAL_vidSetAbsAlarm(ANGSCHED_CRKHAL_CH_##snAngschedAlarm, \
           ANGSCHED_kau16Angles_##snAngschedAlarm \
             [ANGSCHED_u8NextAngleIdx_##snAngschedAlarm]); \
   } \
   else \
   { \
      ANGSCHED_u8NextAngleIdx_##snAngschedAlarm = UINT8_MIN; \
      SWFAIL_vidSoftwareErrorHook(); \
   } \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !Description: Increment next angle index.                                  */
/* !Number     : 4                                                            */
/*                                                                            */
/* !LastAuthor : Y. Badr                                                      */
/******************************************************************************/
#define ANGSCHED_vidINC_NEXT_ANGLE_INDEX(snAngschedAlarm) \
do \
{\
   ANGSCHED_u8NextAngleIdx_##snAngschedAlarm++; \
   if(ANGSCHED_u8NextAngleIdx_##snAngschedAlarm >= \
        ANGSCHED_ku8AnglesNum_##snAngschedAlarm) \
   { \
      ANGSCHED_u8NextAngleIdx_##snAngschedAlarm = UINT8_MIN; \
   } \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !Description: Call callback functions for the current angle.               */
/* !Number     : 5                                                            */
/*                                                                            */
/* !LastAuthor : Y. Badr                                                      */
/******************************************************************************/
#define ANGSCHED_vidCALL_EVENT_CALLBACKS(snAngschedAlarm) \
do \
{ \
   uint32         u32LocalEdgeTime; \
   uint8          u8LocalCounter; \
   \
   /* The returned status is not checked because some events should still   */ \
   /* be working in back-up mode */                                            \
   (void) CRKHAL_udtReadToothEdgeDate(&u32LocalEdgeTime); \
   for(u8LocalCounter = 0; \
       u8LocalCounter < ANGSCHED_u8CALLBACKS_NUMBER; \
       u8LocalCounter++) \
   { \
      if(ANGSCHED_bIS_BIT_SET(u8LocalCounter, \
                              ANGSCHED_kaudtEvtMsk_##snAngschedAlarm \
                              [ANGSCHED_u8NextAngleIdx_##snAngschedAlarm])) \
      { \
         ANGSCHED_kapfvidCallbacks[u8LocalCounter](u32LocalEdgeTime); \
      } \
   } \
} \
while (0)

/******************************************************************************/
/*                                                                            */
/* !Description: Return true if Bit number 'bitNum' is set in the mask        */
/*               'bitMask'. Else return FALSE                                 */
/* !Number     : 6                                                            */
/*                                                                            */
/* !LastAuthor : Y. Badr                                                      */
/******************************************************************************/
#define ANGSCHED_bIS_BIT_SET(bitNum, bitMask) \
   ((((ANGSCHED_tudtCallbackMask)(1 << (bitNum))) & (bitMask)) != 0)


/******************************************************************************/
/*                                                                            */
/* !Description: Activate CRKHAL alarm associated with snAngschedAlarm        */
/* !Number     : 7                                                            */
/*                                                                            */
/* !LastAuthor : G. Mostafa                                                   */
/******************************************************************************/
#define ANGSCHED_vidACTIVATE_ALARM(snAngschedAlarm) \
do \
{ \
   CRKHAL_vidActivateAlarmMode(ANGSCHED_CRKHAL_CH_##snAngschedAlarm, \
                                MODE_NO_ACTION); \
} \
while(0)

/******************************************************************************/
/*                                                                            */
/* !Description: Enable CRKHAL alarm associated with snAngschedAlarm          */
/* !Number     : 8                                                            */
/*                                                                            */
/* !LastAuthor : G. Mostafa                                                   */
/******************************************************************************/
#define ANGSCHED_vidENABLE_ALARM_NOTIF(snAngschedAlarm) \
do \
{ \
   CRKHAL_vidEnableAlarmNotif(ANGSCHED_CRKHAL_CH_##snAngschedAlarm); \
} \
while(0)

#endif /* ANGSCHED_I_H */

/*------------------------------ end of file ---------------------------------*/
