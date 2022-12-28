/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL_I.h                                              */
/* !Description     : Internal Macros of the INJHAL Component                 */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A26595.A-SRC;7 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef INJHAL_I_H
#define INJHAL_I_H

#include "Std_Types.h"
#include "Std_Limits.h"

#include "IfxGtm_Ccu.h"
#include "IfxGtm_Def.h"
#include "IfxGtm_Typ.h"
#include "INJHAL.h"
#include "INJHAL_CFG_I.h"
#include "INJHAL_HOOK.h"
#include "INJHAL_L.h"
#include "SchM_INJHAL.h"

/******************************************************************************/
/* !FuncName    : INJHAL_vidSEQ_INJ_TIME_NOTIF                                */
/* !Description : Macro to handle End of Pulse in sequential injections       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidSEQ_INJ_TIME_NOTIF( \
\
   snChannel \
\
) \
   M1_INJHAL_vidSEQ_INJ_TIME_NOTIF( \
      snChannel, \
      INJHAL_bfGET_INJECTOR_MASK(snChannel), \
      INJHAL_u8GET_INSTANCE_ID(snChannel), \
      INJHAL_u8GET_CHANNEL_ID(snChannel), \
      INJHAL_u8GET_CRKHAL_CH(snChannel), \
      INJHAL_u16GET_CYCLE_START_ANGLE(snChannel))

   #define M1_INJHAL_vidSEQ_INJ_TIME_NOTIF(snChannel, \
                                           bfInjectorMask, \
                                           u8InstanceId, \
                                           u8Channel, \
                                           u8CrkChannel, \
                                           u16CycleAngleStart) \
      M2_INJHAL_vidSEQ_INJ_TIME_NOTIF(snChannel, \
                                      bfInjectorMask, \
                                      u8InstanceId, \
                                      u8Channel, \
                                      u8CrkChannel, \
                                      u16CycleAngleStart)

   #define M2_INJHAL_vidSEQ_INJ_TIME_NOTIF(snChannel, \
                                           bfInjectorMask, \
                                           u8InstanceId, \
                                           u8Channel, \
                                           u8CrkChannel, \
                                           u16CycleAngleStart) \
   do \
   { \
      uint32 u32LocalCurrentPhase; \
      uint32 u32LocalInjAngle; \
      uint32 u32LocalTbu_Data_3; \
      \
      INJHAL_au16NoOverLap[u8Channel] = (boolean)TRUE; \
      INJHAL_au16TimerRunning[u8Channel] = (uint16)UINT16_MIN; \
      \
      IfxGtm_vidAtomDisableNotification(INJHAL_pstr##snChannel, \
                                        (uint8)IfxGtm_Compare_Unit_0); \
      u32LocalTbu_Data_3 = IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel); \
      IfxGtm_vidAtomSetCond_Immediate (INJHAL_pstr##snChannel, \
                             INACTIVE_CCU1, \
                             u32LocalTbu_Data_3, \
                             (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                             CCU0_ONLY_OUT_INACT); \
      IfxGtm_vidAtomClearInterrupt(INJHAL_pstr##snChannel, \
                                   (uint8)IfxGtm_Compare_Unit_0); \
      IfxGtm_vidAtomEnableNotif(INJHAL_pstr##snChannel, \
                                (uint8)IfxGtm_Compare_Unit_0); \
      \
      u32LocalCurrentPhase = \
         (uint32)INJHAL_audtCurrentInjectorPhase[u8Channel]; \
      if (u32LocalCurrentPhase >= (uint32)INJHAL_au8InjectionMode[u8Channel]) \
      { \
         u32LocalInjAngle = (uint32)u16CycleAngleStart; \
      } \
      else \
      { \
         u32LocalInjAngle = (uint32) \
            ((uint32)INJHAL_au16InjectionAngle[u32LocalCurrentPhase][u8Channel] \
                + (uint32)u16CycleAngleStart); \
      } \
      if (u32LocalInjAngle >= (uint32)(INJHAL_u16ENGINE_CYCLE)) \
      { \
         u32LocalInjAngle -= (uint32)(INJHAL_u16ENGINE_CYCLE); \
      } \
      IfxGtm_vidAtomSetCond (INJHAL_pstr##snChannel, \
                             (u32LocalInjAngle + CRKHAL_u16OffsetInjDriver), \
                             INACTIVE_CCU0, \
                             (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                             CCU1_ONLY_OUT_NO_CHANGE); \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : M1_INJHAL_vidWRITE_ANGLE_NOTIF                              */
/* !Description : Macro to handle Angle condition sequential injections       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidWRITE_ANGLE_NOTIF( \
\
   snChannel \
\
) \
   M1_INJHAL_vidWRITE_ANGLE_NOTIF( \
      snChannel, \
      INJHAL_bfGET_INJECTOR_MASK(snChannel), \
      INJHAL_u8GET_INSTANCE_ID(snChannel), \
      INJHAL_u8GET_CHANNEL_ID(snChannel), \
      INJHAL_u8GET_CRKHAL_CH(snChannel), \
      INJHAL_u16GET_CYCLE_START_ANGLE(snChannel))

   #define M1_INJHAL_vidWRITE_ANGLE_NOTIF(snChannel, \
                                          bfInjectorMask, \
                                          u8InstanceId, \
                                          u8Channel, \
                                          u8CrkChannel, \
                                          u16CycleAngleStart) \
      M2_INJHAL_vidWRITE_ANGLE_NOTIF(snChannel, \
                                     bfInjectorMask, \
                                     u8InstanceId, \
                                     u8Channel, \
                                     u8CrkChannel, \
                                     u16CycleAngleStart)

   #define M2_INJHAL_vidWRITE_ANGLE_NOTIF(snChannel, \
                                          bfInjectorMask, \
                                          u8InstanceId, \
                                          u8Channel, \
                                          u8CrkChannel, \
                                          u16CycleAngleStart) \
   do \
   { \
      uint32 u32LocalInjTime; \
      uint32 u32LocalProlongInjTime; \
      sint32 s32LocalNewInjAngle; \
      sint32 s32LocalNewAlarmAngle; \
      INJHAL_tudtInjectorPhase udtLocalCurrentInjectorPhase; \
      uint32 u32LocalremainingTimePrevInj; \
      uint32 u32LocalTbu_Data_4; \
      \
      \
      /* below line is take care of the warning */\
      u32LocalProlongInjTime = (uint32)UINT32_MIN; \
      INJHAL_abInjectionTimeUpdated[u8Channel] = (boolean)FALSE; \
      udtLocalCurrentInjectorPhase = \
         INJHAL_audtCurrentInjectorPhase[u8Channel]; \
      \
      INJHAL_au8AngleMatch[u8Channel] = 0U; \
      INJHAL_vidCfgInjectorPhaseMgmt(snChannel, \
                                     &s32LocalNewInjAngle, \
                                     &u32LocalInjTime); \
      \
      if (  (INJHAL_abfInjectionCut[u8InstanceId] & bfInjectorMask) \
         != (uint8)INJHAL_bfENABLE_ALL_INJ) \
      { \
         \
         IfxGtm_vidAtomDisableNotification(INJHAL_pstr##snChannel, \
                                           (uint8)IfxGtm_Compare_Unit_0); \
         /* set the signal low */ \
         u32LocalTbu_Data_4 = IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel); \
         IfxGtm_vidAtomSetCond_Immediate (INJHAL_pstr##snChannel,  \
                                INACTIVE_CCU1, \
                                u32LocalTbu_Data_4, \
                                (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                                CCU0_ONLY_OUT_INACT); \
         /* clear the interrupt notify in the register */\
         IfxGtm_vidAtomClearInterrupt(INJHAL_pstr##snChannel, \
                                      (uint8)IfxGtm_Compare_Unit_0); \
         IfxGtm_vidAtomEnableNotif(INJHAL_pstr##snChannel, \
                                   (uint8)IfxGtm_Compare_Unit_0); \
         u32LocalInjTime = (uint32)UINT32_MIN; \
      } \
      else \
      { \
         INJHAL_vidCHECK_OVERLAP(snChannel, &u32LocalInjTime); \
         INJHAL_au32PrevInjectionTime[u8Channel] = u32LocalInjTime; \
         if (u32LocalInjTime != (uint32)UINT32_MIN) \
         { \
            SchM_Enter_INJHAL_ACCESS_002( ); \
            /* check if Time has come before Angle */ \
            if (INJHAL_au16NoOverLap[u8Channel] != (boolean)FALSE) \
            { \
               INJHAL_au16NoOverLap[u8Channel] = (boolean)FALSE; \
               u32LocalremainingTimePrevInj    = (uint32)UINT32_MIN; \
            } \
            else \
            { \
               u32LocalTbu_Data_4 = TBU_READ_TIME(); \
               /*IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel);*/ \
               u32LocalremainingTimePrevInj = \
                  ( IfxGtm_u32AtomCcu0Read(INJHAL_pstr##snChannel) \
                  - u32LocalTbu_Data_4) & GTM_TBU_TIMER_MAX_LIMIT; \
            } \
            u32LocalProlongInjTime = \
               (uint32)(u32LocalInjTime + u32LocalremainingTimePrevInj); \
            \
            if (u32LocalProlongInjTime > INJHAL_u32MAX_TIME_DYNAMIC) \
            { \
               u32LocalProlongInjTime = INJHAL_u32MAX_TIME_DYNAMIC; \
            } \
            \
            INJHAL_vidINJECTON_PRESTART_HOOK(snChannel, \
                                             udtLocalCurrentInjectorPhase, \
                                             u32LocalProlongInjTime); \
            IfxGtm_vidAtomDisableNotification(INJHAL_pstr##snChannel, \
                                              (uint8)IfxGtm_Compare_Unit_0); \
            /* set the signal High */ \
            u32LocalTbu_Data_4 = IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel); \
            IfxGtm_vidAtomSetCond_Immediate(INJHAL_pstr##snChannel, \
                                  INACTIVE_CCU1, \
                                  u32LocalTbu_Data_4, \
                                  (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                                  CCU0_ONLY_OUT_ACTIVE); \
            /* clear the interrupt notify in the register */ \
            IfxGtm_vidAtomClearInterrupt(INJHAL_pstr##snChannel, \
                                         (uint8)IfxGtm_Compare_Unit_0); \
            IfxGtm_vidAtomEnableNotif(INJHAL_pstr##snChannel, \
                                      (uint8)IfxGtm_Compare_Unit_0); \
            SchM_Exit_INJHAL_ACCESS_002(); \
            INJHAL_vidINJECTON_START_HOOK(snChannel); \
            INJHAL_abInjStarted[u8InstanceId] = (boolean)TRUE; \
         } \
      } \
      \
      s32LocalNewAlarmAngle = \
         (sint32)(s32LocalNewInjAngle + (sint32)(u16CycleAngleStart)); \
      \
      if (s32LocalNewAlarmAngle >= (sint32)(INJHAL_u16ENGINE_CYCLE)) \
      { \
         s32LocalNewAlarmAngle -= (sint32)(INJHAL_u16ENGINE_CYCLE); \
      } \
      \
      if (u32LocalInjTime != (uint32)UINT32_MIN) \
      { \
         CRKHAL_vidSetAbsAlarm(u8CrkChannel, \
                               (uint16)(s32LocalNewAlarmAngle)); \
         u32LocalProlongInjTime = (u32LocalProlongInjTime + \
                                  /*TBU_READ_TIME()*/ \
                                  IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel))\
                                  & GTM_TBU_TIMER_MAX_LIMIT; \
         IfxGtm_vidAtomSetCond(INJHAL_pstr##snChannel, \
                               INACTIVE_CCU1, \
                               u32LocalProlongInjTime, \
                               (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                               SERVE_FIRST_OUT_NO_CHANGE); \
         INJHAL_au16TimerRunning[u8Channel] = 1u; \
        \
      } \
      else \
      { \
         if (s32LocalNewInjAngle <= (sint32) INJHAL_u16_1_DEG_FOR_PRE_INJ)\
         { \
            /* Local Angle almost same as the angle to be programmed */ \
            INJHAL_au16TimerRunning[u8Channel] = (uint16)UINT16_MIN; \
            /* set a global variable here which can be checked and the API */ \
            /* will be called again */ \
            INJHAL_au8AngleMatch[u8Channel] = 1U; \
         } \
         else \
         { \
            CRKHAL_vidActivateAlarmMode(u8CrkChannel, MODE_NO_ACTION); \
            CRKHAL_vidSetAbsAlarm(u8CrkChannel, (uint16)(s32LocalNewAlarmAngle)); \
            INJHAL_au16TimerRunning[u8Channel] = (uint16)UINT16_MIN; \
         } \
      } \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidWRITE_INIT_VALUE                                  */
/* !Description : Macro to initialise the Alarms                              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCANCELALARM( \
\
   snChannel \
\
) \
do \
{ \
   IfxGtm_vidDISABLE_ATOM_COMPARISION(INJHAL_pstr##snChannel); \
} \
while(0)


/******************************************************************************/
/* !FuncName    : INJHAL_vidWRITE_INIT_VALUE                                  */
/* !Description : Macro to initialise the Alarms                              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidWRITE_INIT_VALUE( \
\
   snChannel \
\
) \
   M1_INJHAL_vidWRITE_INIT_VALUE(snChannel, \
                                 INJHAL_u8GET_CRKHAL_CH(snChannel)) \

   #define M1_INJHAL_vidWRITE_INIT_VALUE(snChannel, \
                                         u8CrkChannel) \
      M2_INJHAL_vidWRITE_INIT_VALUE(snChannel, \
                                    u8CrkChannel) \

   #define M2_INJHAL_vidWRITE_INIT_VALUE(snChannel, \
                                         u8CrkChannel) \
   do \
   { \
      INJHAL_vidINJECTON_STOP_HOOK(snChannel); \
      CRKHAL_vidDeactivateAlarmMode(u8CrkChannel); \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidINIT_INJECTOR                                     */
/* !Description : Macro to initialise the Alarms                              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidINIT_INJECTOR( \
\
   snChannel \
\
) \
   M1_INJHAL_vidINIT_INJECTOR(snChannel, \
                              INJHAL_u8GET_CRKHAL_CH(snChannel), \
                              INJHAL_u8GET_CHANNEL_ID(snChannel)) \

   #define M1_INJHAL_vidINIT_INJECTOR(snChannel, \
                                      u8CrkChannel, \
                                      u8Channel) \
      M2_INJHAL_vidINIT_INJECTOR(snChannel, \
                                 u8CrkChannel, \
                                 u8Channel) \

   #define M2_INJHAL_vidINIT_INJECTOR(snChannel, \
                                      u8CrkChannel, \
                                      u8Channel) \
   do \
   { \
      uint32 u32LocalTbu_Data_1; \
      CRKHAL_vidDeactivateAlarmMode(u8CrkChannel); \
      CRKHAL_vidDisableAlarmNotif(u8CrkChannel); \
      IfxGtm_vidAtomDisableNotification(INJHAL_pstr##snChannel, \
                                        (uint8)IfxGtm_Compare_Unit_0); \
      /* set the signal low */ \
      u32LocalTbu_Data_1 = IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel); \
      IfxGtm_vidAtomSetCond_Immediate (INJHAL_pstr##snChannel, \
                             INACTIVE_CCU1, \
                             u32LocalTbu_Data_1, \
                             (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                             CCU0_ONLY_OUT_INACT); \
      INJHAL_vidINJECTON_STOP_HOOK(snChannel); \
      /* clear the interrupt notify in the register */ \
      IfxGtm_vidAtomClearInterrupt(INJHAL_pstr##snChannel, \
                                   (uint8)IfxGtm_Compare_Unit_0); \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidINIT_WAIT_SYNCHRO                                 */
/* !Description : Macro to initialize and wait for Crank synch                */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidINIT_WAIT_SYNCHRO( \
\
   snChannel \
\
) \
   M1_INJHAL_vidINIT_WAIT_SYNCHRO(snChannel, INJHAL_u8GET_CRKHAL_CH(snChannel))

   #define M1_INJHAL_vidINIT_WAIT_SYNCHRO(snChannel, u8CrkChannel) \
      M2_INJHAL_vidINIT_WAIT_SYNCHRO(snChannel, u8CrkChannel)

   #define M2_INJHAL_vidINIT_WAIT_SYNCHRO(snChannel, u8CrkChannel) \
   do \
   { \
      CRKHAL_vidEnableAlarmNotif(u8CrkChannel); \
      IfxGtm_vidAtomEnableNotif(INJHAL_pstr##snChannel, \
                                (uint8)IfxGtm_Compare_Unit_0); \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidUPDATE_INJ_ANGLE                                  */
/* !Description : dummy for future                                            */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidUPDATE_INJ_ANGLE( \
\
   snChannel \
\
) \
do \
{ \
} \
while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidUPDATE_INJ_TIME                                   */
/* !Description : Macro for updating injection time                           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidUPDATE_INJ_TIME( \
\
   snChannel \
\
) \
   M1_INJHAL_vidUPDATE_INJ_TIME(snChannel, \
                                INJHAL_u8GET_INSTANCE_ID(snChannel), \
                                INJHAL_u8GET_CHANNEL_ID(snChannel), \
                                INJHAL_bfGET_INJECTOR_MASK(snChannel), \
                                INJHAL_u8GET_CRKHAL_CH(snChannel)) \

   #define M1_INJHAL_vidUPDATE_INJ_TIME(snChannel, \
                                        u8InstanceId, \
                                        u8Channel, \
                                        bfInjectorMask, \
                                        u8CrkChannel) \
      M2_INJHAL_vidUPDATE_INJ_TIME(snChannel, \
                                   u8InstanceId, \
                                   u8Channel, \
                                   bfInjectorMask, \
                                   u8CrkChannel) \

   #define M2_INJHAL_vidUPDATE_INJ_TIME(snChannel, \
                                        u8InstanceId, \
                                        u8Channel, \
                                        bfInjectorMask, \
                                        u8CrkChannel) \
   do \
   { \
      uint32 u32LocalInjTime; \
      sint32 s32LocalInjectionTimeDelta; \
      uint32 u32LocalDownCnt; \
      uint8  u8LocalInjCompStatus; \
      uint32 u32LocalNewAlarmAngle; \
      uint32 u32LocalTbu_Data_2; \
      uint32 u32LocalTime; \
      uint32 u32LocalInjectionTimeDelta ;\
      \
      \
      u8LocalInjCompStatus = INJHAL_aenuInjComponentStatus[u8InstanceId]; \
      \
      if (  (u8LocalInjCompStatus == INJHAL_enuCOMP_SEQ_INJ) \
         || (  (u8LocalInjCompStatus == INJHAL_enuCOMP_SEQ_PRE_INJ) \
            && (  INJHAL_aenuInjectorMode[u8Channel] \
               == INJHAL_enuINJ_MODE_NORMAL))) \
      { \
         /*if (INJHAL_bCHECK_INJECTOR_COND(snChannel)) */ \
         { \
            INJHAL_abInjectionTimeUpdated[u8Channel] = (boolean)TRUE; \
            if (INJHAL_au16TimerRunning[u8Channel] != (uint16)UINT16_MIN) \
            { \
               INJHAL_vidCfgInjTimeUpdateMgmt(u8Channel, &u32LocalInjTime); \
               \
               /*New injection time value - programmed injector value*/ \
               s32LocalInjectionTimeDelta = \
                  (sint32)( (sint32)u32LocalInjTime \
                          - (sint32)(INJHAL_au32PrevInjectionTime[u8Channel])); \
               if (s32LocalInjectionTimeDelta != (sint32)UINT32_MIN) \
               \
               { \
                  /* + injection time remaining     */ \
                  /* (on the injection in progress) */ \
                  u32LocalTbu_Data_2 = (uint32)((TBU_READ_TIME()) & GTM_TBU_TIMER_MAX_LIMIT); \
                  u32LocalTime = \
                     IfxGtm_u32AtomCcu0Read(INJHAL_pstr##snChannel); \
                  u32LocalDownCnt = (uint32)(( u32LocalTime \
                                            - u32LocalTbu_Data_2) \
                                            & GTM_TBU_TIMER_MAX_LIMIT); \
                  /* New = New - programmed + remaining*/ \
                  s32LocalInjectionTimeDelta = \
                  (sint32)((sint32)u32LocalDownCnt + (sint32)s32LocalInjectionTimeDelta); \
                  \
                  if (s32LocalInjectionTimeDelta < (sint32)UINT32_MIN) \
                  { \
                     s32LocalInjectionTimeDelta = (sint32)UINT32_MIN; \
                  } \
                  \
                  SchM_Enter_INJHAL_ACCESS_003(); \
                  \
                  if ((INJHAL_abInjectionTimeUpdated[u8Channel]) != \
                         (boolean)FALSE) \
                  { \
                     u32LocalNewAlarmAngle = \
                     IfxGtm_u32AtomCcu1Read(INJHAL_pstr##snChannel); \
                     CRKHAL_vidSetAbsAlarm(u8CrkChannel, \
                                           (uint16)u32LocalNewAlarmAngle); \
                     u32LocalInjectionTimeDelta = (uint32)s32LocalInjectionTimeDelta ;\
                     u32LocalInjectionTimeDelta = ( (u32LocalInjectionTimeDelta \
                                                  + (TBU_READ_TIME())) \
                                                  & GTM_TBU_TIMER_MAX_LIMIT); \
                     IfxGtm_vidAtomSetCond(INJHAL_pstr##snChannel, \
                                           INACTIVE_CCU1, \
                                           (uint32)u32LocalInjectionTimeDelta, \
                                           (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                                           SERVE_FIRST_OUT_NO_CHANGE); \
                     INJHAL_au32PrevInjectionTime[u8Channel] = u32LocalInjTime;\
                     INJHAL_abfTimeUpdate[u8InstanceId] |= bfInjectorMask; \
                  } \
                  SchM_Exit_INJHAL_ACCESS_003(); \
               } \
            } \
         } \
      } \
   } \
   while(0)
/******************************************************************************/
/* !FuncName    : INJHAL_vidPROG_NEXT_INJ                                     */
/* !Description : Macro for handling injections                               */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidPROG_NEXT_INJ( \
\
   snChannel \
\
) \
   M1_INJHAL_vidPROG_NEXT_INJ(INJHAL_u8GET_INSTANCE_ID(snChannel), \
                              INJHAL_u8GET_CHANNEL_ID(snChannel), \
                              INJHAL_u16GET_CYCLE_START_ANGLE(snChannel), \
                              INJHAL_u8GET_CRKHAL_CH(snChannel))

   #define M1_INJHAL_vidPROG_NEXT_INJ(u8InstanceId, \
                                      u8Channel, \
                                      u16CycleAngleStart, \
                                      u8CrkChannel) \
         M2_INJHAL_vidPROG_NEXT_INJ(u8InstanceId, \
                                    u8Channel, \
                                    u16CycleAngleStart, \
                                    u8CrkChannel)

   #define M2_INJHAL_vidPROG_NEXT_INJ(u8InstanceId, \
                                      u8Channel, \
                                      u16CycleAngleStart, \
                                      u8CrkChannel) \
   do \
   { \
      sint32  s32LocalCurrentEngAngle; \
      uint32  u32LocalInjAngle; \
      boolean bLocalCondition; \
      uint8   u8LocalInjectionPulseIndex; \
      \
      \
      bLocalCondition             = (boolean)FALSE; \
      u8LocalInjectionPulseIndex  = (uint8)UINT8_MIN; \
      s32LocalCurrentEngAngle     = (sint32)CRKHAL_u16ReadCounter(u8CrkChannel); \
      s32LocalCurrentEngAngle     = \
         (sint32)(s32LocalCurrentEngAngle - (sint32)(u16CycleAngleStart)); \
      u32LocalInjAngle            = (uint32)UINT32_MIN; \
      \
      if (s32LocalCurrentEngAngle < (sint32)UINT32_MIN) \
      { \
         s32LocalCurrentEngAngle += (sint32)INJHAL_u16ENGINE_CYCLE; \
      } \
      \
      do \
      { \
         if ( (sint32)INJHAL_au16InjectionAngle \
                 [u8LocalInjectionPulseIndex][u8Channel] \
            > s32LocalCurrentEngAngle) \
         { \
            u32LocalInjAngle = \
               (uint32)((uint32)INJHAL_au16InjectionAngle \
                  [u8LocalInjectionPulseIndex][u8Channel] \
               + (uint32)(u16CycleAngleStart)); \
            \
            bLocalCondition = (boolean)TRUE; \
            \
            if (u32LocalInjAngle >= (uint32)INJHAL_u16ENGINE_CYCLE) \
            { \
               u32LocalInjAngle -= (uint32)INJHAL_u16ENGINE_CYCLE; \
            } \
            \
         } \
         \
         u8LocalInjectionPulseIndex++; \
      } \
      while(  (bLocalCondition == (boolean)FALSE) \
           && ( (u8LocalInjectionPulseIndex) \
              < INJHAL_au8InjectionMode[u8InstanceId])); \
      \
      if (bLocalCondition != (boolean)FALSE) \
      { \
         INJHAL_audtCurrentInjectorPhase[u8Channel] = \
            (INJHAL_tudtInjectorPhase)INJHAL_kaudtCorrespInjectorPhase \
               [u8LocalInjectionPulseIndex - 1u]; \
         CRKHAL_vidEnableAlarmNotif(u8CrkChannel); \
         CRKHAL_vidActivateAlarmMode(u8CrkChannel, MODE_NO_ACTION); \
         CRKHAL_vidSetAbsAlarm(u8CrkChannel, (uint16)u32LocalInjAngle); \
      } \
      else \
      { \
         INJHAL_audtCurrentInjectorPhase[u8Channel] = \
            INJHAL_udtBEFORE_END_OF_CYCLE; \
         CRKHAL_vidEnableAlarmNotif(u8CrkChannel); \
         CRKHAL_vidActivateAlarmMode(u8CrkChannel, MODE_NO_ACTION); \
         CRKHAL_vidSetAbsAlarm(u8CrkChannel, u16CycleAngleStart); \
      } \
      INJHAL_au16NoOverLap[u8Channel] = (boolean)TRUE; \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidEND_OF_PULSE_NOTIF                                */
/* !Description : Macro for handling end of injections                        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidEND_OF_PULSE_NOTIF( \
\
   snChannel \
\
) \
    M1_INJHAL_vidEND_OF_PULSE_NOTIF(snChannel, \
                                    INJHAL_u8GET_INSTANCE_ID(snChannel), \
                                    INJHAL_u8GET_CHANNEL_ID(snChannel), \
                                    INJHAL_u8GET_CRKHAL_CH(snChannel))

   #define M1_INJHAL_vidEND_OF_PULSE_NOTIF(snChannel, \
                                           u8InstanceId, \
                                           u8Channel, \
                                           u8CrkChannel) \
         M2_INJHAL_vidEND_OF_PULSE_NOTIF(snChannel, \
                                         u8InstanceId, \
                                         u8Channel, \
                                         u8CrkChannel)

   #define M2_INJHAL_vidEND_OF_PULSE_NOTIF(snChannel, \
                                           u8InstanceId, \
                                           u8Channel, \
                                           u8CrkChannel) \
   do \
   { \
      boolean        bLocalChannelStatus; \
      boolean        bLocalIsSynchronized; \
      Std_ReturnType udtLocalStatus; \
      uint8          u8LocalChannelIndex; \
      uint8          u8LocalChannelForLoopStart; \
      uint8          u8LocalChannelForLoopEnd; \
      uint8          u8LocalInjCompStatus; \
      \
      bLocalIsSynchronized = (boolean)FALSE; \
      \
      u8LocalInjCompStatus = INJHAL_aenuInjComponentStatus[u8InstanceId]; \
      INJHAL_abInjectionTimeUpdated[u8InstanceId] = (boolean)FALSE; \
      \
      INJHAL_vidGetForLoopConditions(u8InstanceId, \
                                     &u8LocalChannelForLoopStart, \
                                     &u8LocalChannelForLoopEnd); \
      \
      INJHAL_vidSTART_OVLP_MGMT_TIMER(snChannel); \
      \
      INJHAL_vidINJECTON_STOP_HOOK(snChannel); \
      \
      if (  (u8LocalInjCompStatus  == (uint8)INJHAL_enuCOMP_FG_PRE_INJ) \
         || (  (u8LocalInjCompStatus == (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ) \
            && (  INJHAL_aenuInjectorMode[u8Channel] \
               == (uint8)INJHAL_enuINJ_MODE_INIT))) \
      { \
         udtLocalStatus = CRKHAL_udtReadStatus((uint8)CRKHAL_u8SYNCHRONISED, \
                                               &bLocalIsSynchronized); \
         if (udtLocalStatus != (Std_ReturnType)E_OK) \
         { \
           udtLocalStatus = \
              INJHAL_udtCAM_READ_SYNC_STATUS(&bLocalIsSynchronized); \
         } \
         \
         if (  (bLocalIsSynchronized != (boolean)FALSE) \
            && (udtLocalStatus       != (Std_ReturnType)E_NOT_OK)) \
         { \
            if (  (INJHAL_abEnableSeqPreInj[u8InstanceId] != (boolean)FALSE) \
               && (INJHAL_au32SeqPreInjTime[u8Channel] != (uint32)UINT32_MIN)) \
            { \
               INJHAL_aenuInjComponentStatus[u8InstanceId] = \
                  (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ; \
              INJHAL_vidWRITE_SEQ_PREINJ_NOTIF(snChannel); \
            } \
            else \
            { \
               INJHAL_aenuInjectorMode[u8Channel] = \
                  (uint8)INJHAL_enuINJ_MODE_NORMAL; \
               bLocalChannelStatus = (boolean)FALSE; \
               for (u8LocalChannelIndex = 0U/*u8LocalChannelForLoopStart*/; \
                    u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/; \
                    u8LocalChannelIndex ++) \
               { \
                  if (  (  INJHAL_aenuInjectorMode[u8LocalChannelIndex] \
                        != (uint8)INJHAL_enuINJ_MODE_NORMAL) \
                     && (  INJHAL_aenuInjectorMode[u8LocalChannelIndex] \
                        != (uint8)INJHAL_enuINJ_MODE_DISABLED)) \
                  { \
                     bLocalChannelStatus = (boolean)TRUE; \
                  } \
               } \
               if (bLocalChannelStatus == (boolean)FALSE) \
               { \
                  INJHAL_aenuInjComponentStatus[u8InstanceId] = \
                     (uint8)INJHAL_enuCOMP_SEQ_INJ; \
               } \
               INJHAL_vidPROG_NEXT_INJ(snChannel); \
            } \
         } \
         else \
         { \
            bLocalIsSynchronized = (boolean)FALSE; \
            INJHAL_aenuInjComponentStatus[u8InstanceId] = \
               (uint8)INJHAL_enuCOMP_WAITING_SYNCHRO; \
         } \
      } \
      else \
      { \
         if (  (u8LocalInjCompStatus == (uint8)INJHAL_enuCOMP_SEQ_INJ) \
            || (  (u8LocalInjCompStatus == (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ) \
               && (INJHAL_aenuInjectorMode[u8Channel] == \
                  (uint8)INJHAL_enuINJ_MODE_NORMAL))) \
         { \
            INJHAL_vidSEQ_INJ_TIME_NOTIF(snChannel); \
         } \
         else \
         { \
            if (  (u8LocalInjCompStatus == (uint8)INJHAL_enuCOMP_SEQ_PRE_INJ) \
               && (  INJHAL_aenuInjectorMode[u8Channel] \
                  == (uint8)INJHAL_enuINJ_MODE_PREINJ_SEQ)) \
            { \
               INJHAL_aenuInjectorMode[u8Channel] = \
                          (uint8)INJHAL_enuINJ_MODE_NORMAL; \
               bLocalChannelStatus = (boolean)FALSE; \
               \
               for (u8LocalChannelIndex = 0U/*u8LocalChannelForLoopStart*/; \
                    u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/; \
                    u8LocalChannelIndex ++) \
               { \
                  if (  (  INJHAL_aenuInjectorMode[u8LocalChannelIndex] \
                        != (uint8)INJHAL_enuINJ_MODE_NORMAL) \
                     && (  INJHAL_aenuInjectorMode[u8LocalChannelIndex] \
                        != (uint8)INJHAL_enuINJ_MODE_DISABLED)) \
                  { \
                     bLocalChannelStatus = (boolean)TRUE; \
                  } \
               } \
               if (bLocalChannelStatus == (boolean)FALSE) \
               { \
                  INJHAL_aenuInjComponentStatus[u8InstanceId] = \
                     (uint8)INJHAL_enuCOMP_SEQ_INJ; \
               } \
               INJHAL_vidPROG_NEXT_INJ(snChannel); \
            } \
         } \
      } \
      if (u8LocalInjCompStatus  == (uint8)INJHAL_enuCOMP_FG_PRE_INJ) \
      { \
         if (INJHAL_abEndOfPreInjTreated[u8InstanceId] == (boolean)FALSE) \
         { \
            INJHAL_abEndOfPreInjTreated[u8InstanceId] = (boolean)TRUE; \
            INJHAL_au16FGPreInjEndAngle[u8InstanceId] = \
               CRKHAL_u16ReadCounter(u8CrkChannel); \
            INJHAL_abFGPreInjEndAngReady[u8InstanceId] = \
               bLocalIsSynchronized; \
         } \
      } \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidGetForLoopConditions                              */
/* !Description : Macro for handling seq pre-injections                       */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidWRITE_SEQ_PREINJ_NOTIF( \
\
   snChannel \
\
) \
   M1_INJHAL_vidWRITE_SEQ_PREINJ_NOTIF( \
      INJHAL_u8GET_CRKHAL_CH(snChannel), \
      INJHAL_u8GET_CHANNEL_ID(snChannel), \
      INJHAL_u16GET_CYCLE_START_ANGLE(snChannel))

   #define M1_INJHAL_vidWRITE_SEQ_PREINJ_NOTIF(u8CrkChannel, \
                                               u8Channel, \
                                               u16CycleAngleStart) \
         M2_INJHAL_vidWRITE_SEQ_PREINJ_NOTIF(u8CrkChannel, \
                                             u8Channel, \
                                             u16CycleAngleStart)

   #define M2_INJHAL_vidWRITE_SEQ_PREINJ_NOTIF(u8CrkChannel, \
                                               u8Channel, \
                                               u16CycleAngleStart) \
   do \
   { \
      sint32 s32LocalSeqPreInjAngle; \
      \
      \
      s32LocalSeqPreInjAngle = \
         (sint32)( (sint32)INJHAL_au16SeqPreInjAngle[u8Channel] \
                 + (sint32)u16CycleAngleStart); \
      if (s32LocalSeqPreInjAngle >= (sint32)INJHAL_u16ENGINE_CYCLE) \
      { \
         s32LocalSeqPreInjAngle -= (sint32)(INJHAL_u16ENGINE_CYCLE); \
      } \
      CRKHAL_vidEnableAlarmNotif(u8CrkChannel);\
      CRKHAL_vidActivateAlarmMode(u8CrkChannel, MODE_NO_ACTION); \
      CRKHAL_vidSetAbsAlarm(u8CrkChannel, \
                            (uint16)(s32LocalSeqPreInjAngle)); \
   } \
   while(0)

/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      : i.0x09                                                      */
/* !Reference   : V03 NT 12 03716 / 1                                         */
/*                                                                            */
/*                                                                            */
/* !LastAuthor  : P.Y. CLERC                                                  */
/************************** </AUTO_MACRO_HEADER> ******************************/
#define INJHAL_vidSEQ_PREINJ_MANAGEMENT( \
\
   snChannel \
\
) \
    M1_INJHAL_vidSEQ_PREINJ_MANAGEMENT(snChannel, \
                                       INJHAL_u8GET_CHANNEL_ID(snChannel), \
                                       INJHAL_u8GET_INSTANCE_ID(snChannel))

   #define M1_INJHAL_vidSEQ_PREINJ_MANAGEMENT(snChannel, \
                                              u8Channel, \
                                              u8InstanceId) \
         M2_INJHAL_vidSEQ_PREINJ_MANAGEMENT(snChannel, \
                                            u8Channel, \
                                            u8InstanceId) \

   #define M2_INJHAL_vidSEQ_PREINJ_MANAGEMENT(snChannel, \
                                              u8Channel, \
                                              u8InstanceId) \
   do \
   { \
      boolean bLocalCondition_1; \
      uint8   u8LocalChannelIndex; \
      uint8   u8LocalChannelForLoopStart; \
      uint8   u8LocalChannelForLoopEnd; \
      uint32 pulseWidth;\
      uint32 u32LocalTbu_Data;\
      \
      \
      INJHAL_vidGetForLoopConditions(u8InstanceId, \
                                     &u8LocalChannelForLoopStart, \
                                     &u8LocalChannelForLoopEnd); \
      \
      if (  (INJHAL_au32SeqPreInjTime[u8Channel]    != (uint32)UINT32_MIN) \
         && (INJHAL_abEnableSeqPreInj[u8InstanceId] != (boolean)FALSE)) \
      { \
            /* set the signal High */ \
            IfxGtm_vidAtomDisableNotification(INJHAL_pstr##snChannel, \
                                              (uint8)IfxGtm_Compare_Unit_0); \
            u32LocalTbu_Data = IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel); \
            IfxGtm_vidAtomSetCond_Immediate(INJHAL_pstr##snChannel, \
                                  INACTIVE_CCU1, \
                                  u32LocalTbu_Data, \
                                  (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                                  CCU0_ONLY_OUT_ACTIVE); \
            /* clear the interrupt notify in the register */ \
            IfxGtm_vidAtomClearInterrupt(INJHAL_pstr##snChannel, \
                                         (uint8)IfxGtm_Compare_Unit_0); \
            IfxGtm_vidAtomEnableNotif(INJHAL_pstr##snChannel, \
                                      (uint8)IfxGtm_Compare_Unit_0); \
            /* Get the pulsewidth */\
            pulseWidth = (INJHAL_au32SeqPreInjTime[u8Channel] + \
                  IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel)) & GTM_TBU_TIMER_MAX_LIMIT; \
            /* program the CM0 register with duration */\
            IfxGtm_vidAtomSetCond(INJHAL_pstr##snChannel, \
                                  INACTIVE_CCU1, \
                                  pulseWidth, \
                                  (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                                  CCU0_ONLY_OUT_INACT); \
         INJHAL_aenuInjectorMode[u8Channel] = \
            INJHAL_enuINJ_MODE_PREINJ_SEQ; \
         INJHAL_vidINJECTON_START_HOOK(snChannel); \
         \
         INJHAL_abInjStarted[u8InstanceId] = (boolean)TRUE; \
      } \
      else \
      { \
         INJHAL_aenuInjectorMode[u8Channel] = INJHAL_enuINJ_MODE_NORMAL; \
         bLocalCondition_1 = (boolean)FALSE; \
         \
         for (u8LocalChannelIndex = 0U/*u8LocalChannelForLoopStart*/; \
              u8LocalChannelIndex < INJHAL_u8NB_INJECTORS/*u8LocalChannelForLoopEnd*/; \
              u8LocalChannelIndex++) \
         { \
            if (  (  INJHAL_aenuInjectorMode[u8LocalChannelIndex] \
                  != INJHAL_enuINJ_MODE_NORMAL) \
               && (  INJHAL_aenuInjectorMode[u8LocalChannelIndex] \
                  != INJHAL_enuINJ_MODE_DISABLED)) \
            { \
               bLocalCondition_1 = (boolean)TRUE; \
            } \
         } \
         if (bLocalCondition_1 == (boolean)FALSE) \
         { \
            INJHAL_aenuInjComponentStatus[u8InstanceId] = \
               INJHAL_enuCOMP_SEQ_INJ; \
         } \
         INJHAL_vidPROG_NEXT_INJ(snChannel); \
      } \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCHECK_OVERLAP                                     */
/* !Description : Macro to check if the overlap timer is running / not        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCHECK_OVERLAP( \
\
   snChannel, \
   pu32InjectionTime \
\
) \
   M1_INJHAL_vidCHECK_OVERLAP(INJHAL_snGET_OVERLAP_MANAGEMENT(snChannel), \
                              INJHAL_snGET_TOM_OVLP_CH(snChannel), \
                              pu32InjectionTime)

   #define M1_INJHAL_vidCHECK_OVERLAP(snOvlpMgmt, \
                                      snOvlpMgmtTimer, \
                                      pu32InjectionTime) \
      M2_INJHAL_vidCHECK_OVERLAP(snOvlpMgmt, \
                                 snOvlpMgmtTimer, \
                                 pu32InjectionTime)

   #define M2_INJHAL_vidCHECK_OVERLAP(snOvlpMgmt, \
                                      snOvlpMgmtTimer, \
                                      pu32InjectionTime) \
      M3_INJHAL_vidCHECK_OVERLAP_##snOvlpMgmt( snOvlpMgmtTimer, \
                                                pu32InjectionTime)

   #define M3_INJHAL_vidCHECK_OVERLAP_OVLP_OFF(snOvlpMgmtTimer, \
                                          pu32InjectionTime)



   #define M3_INJHAL_vidCHECK_OVERLAP_OVLP_ON(snOvlpMgmtTimer, \
                                          pu32InjectionTime)\
   do \
   { \
      uint32  u32LocalDownCounter; \
      \
      \
       u32LocalDownCounter   =  (uint32)Gpt_GetTimeRemaining(snOvlpMgmtTimer); \
         if (  (u32LocalDownCounter > 0x00000000) \
            || (*(pu32InjectionTime) == 0x00000000)) \
         { \
            *(pu32InjectionTime) = 0x00000000; \
         } \
         else \
         { \
            /*DioBSLWrite(snInjectorSelectDioPin, bInjectorSelectDioLevel);*/ \
         /*IfxGtm_vidTomWrite(snOvlpMgmtTimer, */\
                        /*INJHAL_kau32OverlapMgmtDuration[u8BankId]); */\
         } \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidEND_OF_CYCLE_OVLP_MGMT                            */
/* !Description : Macro to find over lap management                           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidEND_OF_CYCLE_OVLP_MGMT( \
\
   snChannel \
\
) \
   M1_INJHAL_vidEND_OF_CYCLE_OVLP_MGMT( \
      INJHAL_snGET_OVERLAP_MANAGEMENT(snChannel), \
      INJHAL_u8GET_CHANNEL_ID(snChannel),\
      INJHAL_snGET_TOM_OVLP_CH(snChannel))

   #define M1_INJHAL_vidEND_OF_CYCLE_OVLP_MGMT(snOvlpMgmt, \
                                               u8Channel, \
                                               snOvlpMgmtTimer \
                                               ) \
      M2_INJHAL_vidEND_OF_CYCLE_OVLP_MGMT(snOvlpMgmt, \
                                          u8Channel, \
                                          snOvlpMgmtTimer)

   #define M2_INJHAL_vidEND_OF_CYCLE_OVLP_MGMT(snOvlpMgmt, \
                                               u8Channel, \
                                               snOvlpMgmtTimer) \
      M3_INJHAL_vidEND_OF_CYCLE_OVLP_MGMT_##snOvlpMgmt( \
         u8Channel, \
         snOvlpMgmtTimer)

   #define M3_INJHAL_vidEND_OF_CYCLE_OVLP_MGMT_OVLP_OFF(u8Channel, \
                                                   snOvlpMgmtTimer) \
   do \
   { \
      \
   } \
   while(0)

  #define M3_INJHAL_vidEND_OF_CYCLE_OVLP_MGMT_OVLP_ON(u8Channel,snOvlpMgmtTimer ) \
   do \
   { \
      if (INJHAL_au16NoOverLap[u8Channel] == (boolean)FALSE) \
      { \
        Gpt_StartTimer(snOvlpMgmtTimer, (Gpt_ValueType)(INJHAL_kau32OverlapMgmtDuration));\
      } \
   } \
   while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidSTART_OVLP_MGMT_TIMER                             */
/* !Description : Macro for starting the injector over lap timer              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidSTART_OVLP_MGMT_TIMER( \
\
   snChannel \
\
) \
   M1_INJHAL_vidSTART_OVLP_MGMT_TIMER( \
      INJHAL_snGET_OVERLAP_MANAGEMENT(snChannel), \
      INJHAL_u8GET_CHANNEL_ID(snChannel),\
      INJHAL_snGET_TOM_OVLP_CH(snChannel))

   #define M1_INJHAL_vidSTART_OVLP_MGMT_TIMER(snOvlpMgmt, u8Channel,snOvlpMgmtTimer) \
      M2_INJHAL_vidSTART_OVLP_MGMT_TIMER(snOvlpMgmt, u8Channel,snOvlpMgmtTimer)

   #define M2_INJHAL_vidSTART_OVLP_MGMT_TIMER(snOvlpMgmt, u8Channel,snOvlpMgmtTimer) \
      M3_INJHAL_vidSTART_OVLP_MGMT_TIMER_##snOvlpMgmt(u8Channel,snOvlpMgmtTimer)

   #define M3_INJHAL_vidSTART_OVLP_MGMT_TIMER_OVLP_OFF(u8Channel,snOvlpMgmtTimer)

   #define M3_INJHAL_vidSTART_OVLP_MGMT_TIMER_OVLP_ON(u8Channel,snOvlpMgmtTimer) \
     do \
    { \
      Gpt_StartTimer(snOvlpMgmtTimer, (Gpt_ValueType)(INJHAL_kau32OverlapMgmtDuration));\
    } \
    while(0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidGetForLoopConditions                              */
/* !Description : Macro for getting number of injectors                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidGetForLoopConditions( \
\
   u8InstanceId, \
   pu8ForLoopStart, \
   pu8ForLoopEnd \
\
) \
do \
{ \
   *(pu8ForLoopStart) = INJHAL_kau8InstanceOffset[u8InstanceId]; \
   *(pu8ForLoopEnd) = \
      (uint8)((*(pu8ForLoopStart)) + INJHAL_kau8NbInjectors[u8InstanceId]); \
} \
while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgWriteTestTimeChannel                           */
/* !Description : Macro for writting the test Time                            */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgWriteTestTimeChannel( \
\
   snChannel \
\
) \
do \
{ \
   uint32 u32LocalTbu_Data_5 ; \
   /* if channel is enabled, API returns  1 */\
   if( 0U == IfxGtm_u8AtomIsChannelEnabled( INJHAL_pstrAgc##snChannel , \
                               INJHAL_snGET_ATOM_CH(snChannel)) ) \
   {\
     /* Enable ATOM channel here and connect the ATOM output pin */\
     IfxGtm_vidAtomEnableChannel(INJHAL_pstr##snChannel,\
                                 INJHAL_pstrAgc##snChannel,  \
                                 INJHAL_snGET_ATOM_CH(snChannel),\
                                 IfxGtm_Atom_Level_Low);\
                                 \
     IfxGtm_vidAtomToPin(INJHAL_##snChannel##_TOUT_REG, \
                      INJHAL_##snChannel##_TOUT_SEL, \
                      (Ifx_P *)INJHAL_##snChannel##_PORT, \
                      INJHAL_##snChannel##_PIN, \
                      (IfxGtmToutSel)INJHAL_##snChannel##_GTM_TIMER); \
     \
     IfxGtm_vidAtomEnableNotif(INJHAL_pstr##snChannel, \
                                   (uint8)IfxGtm_Compare_Unit_0); \
   }\
   \
   /* set the signal High */ \
   u32LocalTbu_Data_5 = TBU_READ_TIME(); \
   IfxGtm_vidAtomSetCond_Immediate(INJHAL_pstr##snChannel, \
                         INACTIVE_CCU1, \
                         u32LocalTbu_Data_5, \
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                         CCU0_ONLY_OUT_ACTIVE); \
   IfxGtm_vidAtomSetCond(INJHAL_pstr##snChannel, \
                               INACTIVE_CCU1, \
                               pulseWidth, \
                               (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                               CCU0_ONLY_OUT_INACT); \
   INJHAL_vidINJECTON_START_HOOK(snChannel); \
} \
while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidGET_ANGLE_NOTIF_FUNC                              */
/* !Description : Macro for getting angle notification fucntions              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidGET_ANGLE_NOTIF_FUNC( \
\
   snChannel \
\
) \
   INJHAL_vid##snChannel##_ANGLE_NOTIF

/******************************************************************************/
/* !FuncName    : INJHAL_snGET_ATOM                                           */
/* !Description : Macro for getting ATOM channel associated                   */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_snGET_ATOM(snChannel)   INJHAL_snALARM_##snChannel

/******************************************************************************/
/* !FuncName    : INJHAL_snGET_ATOM_CH                                        */
/* !Description : Macro for getting ATOM channel associated                   */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_snGET_ATOM_CH(snChannel)   INJHAL_snALARM_##snChannel##_CH

/******************************************************************************/
/* !FuncName    : INJHAL_bfGET_INJECTOR_MASK                                  */
/* !Description : Macro for getting injector mask                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_bfGET_INJECTOR_MASK( \
\
   snChannel \
\
) \
   INJHAL_bf##snChannel##_MASK

/******************************************************************************/
/* !FuncName    : INJHAL_u8GET_INSTANCE_ID                                    */
/* !Description : Macro for getting injector instance id                      */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_u8GET_INSTANCE_ID( \
\
   snChannel \
\
) \
   INJHAL_u8##snChannel##_INSTANCE_ID

/******************************************************************************/
/* !FuncName    : INJHAL_u8GET_CHANNEL_ID                                     */
/* !Description : Macro for getting injector channel id                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_u8GET_CHANNEL_ID( \
\
   snChannel \
\
) \
   INJHAL_u8##snChannel##_CHANNEL_ID

/******************************************************************************/
/* !FuncName    : INJHAL_u8GET_BANK_ID                                        */
/* !Description : Macro for getting injector Bank id                          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_u8GET_BANK_ID( \
\
   snChannel \
\
) \
   INJHAL_u8##snChannel##_BANK_ID

/******************************************************************************/
/* !FuncName    : INJHAL_u8GET_CRKHAL_CH                                      */
/* !Description : Macro for getting crankhal channel id                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_u8GET_CRKHAL_CH( \
\
   snChannel \
\
) \
   INJHAL_u8CRKHAL_##snChannel##_CH

/******************************************************************************/
/* !FuncName    : INJHAL_u16GET_CYCLE_START_ANGLE                             */
/* !Description : Macro for getting injector reference angle                  */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_u16GET_CYCLE_START_ANGLE( \
\
   snChannel \
\
) \
   INJHAL_u16##snChannel##_CYCLE_REF

/******************************************************************************/
/* !FuncName    : INJHAL_snGET_OVERLAP_MANAGEMENT                             */
/* !Description : Macro for getting injector over lap management shceme       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_snGET_OVERLAP_MANAGEMENT( \
\
   snChannel \
\
) \
   INJHAL_sn##snChannel##_OVLP_MANAGEMENT

/******************************************************************************/
/* !FuncName    : INJHAL_snGET_TOM_OVLP_CH                                    */
/* !Description : Macro for getting injector over lap management Channel      */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_snGET_TOM_OVLP_CH( \
\
   snChannel \
\
) \
   INJHAL_snTOM_##snChannel##_OVLP_CH

#endif /* INJHAL_I_H */

/*-------------------------------- end of file -------------------------------*/
