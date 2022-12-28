/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : Injection Hardware Abstraction Layer                    */
/*                                                                            */
/* !File            : INJHAL_CFG_I.h                                          */
/* !Description     : Configuration of the INJHAL Component                   */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/

#ifndef INJHAL_CFG_I_H
#define INJHAL_CFG_I_H

#include "Std_Types.h"

#include "INJHAL_TYP.h"
#include "INJHAL_HOOK.h"
#include "INJHAL_I.h"
#include "CAMHAL.h"
#include "CRKHAL_Cfg.h"
#include "SWFAIL.h"
#include "Gpt_Cfg.h"
#include "Gpt.h"
#include "injhal_gtm_cfg.h"
#include "L9781.h"
/*lint -esym(960,5.1) */
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*************************************************************************/
/* INJHAL General Configuration                                          */
/*************************************************************************/
#define INJHAL_u32MAX_TIME_DYNAMIC        (0x7FFFFFu)
#define INJHAL_u8DCNT_RESOL_IN_100_NS     (1u)
#define INJHAL_u8NB_INJ_PULSES            (5u)
#define INJHAL_u8NB_INJECTORS             (3u)
#define INJHAL_u8NB_INSTANCES             (1u)
#define INJHAL_udtBEFORE_PULSE_1          (INJHAL_tudtInjectorPhase)0u
#define INJHAL_udtBEFORE_PULSE_2          (INJHAL_tudtInjectorPhase)1u
#define INJHAL_udtBEFORE_PULSE_3          (INJHAL_tudtInjectorPhase)2u
#define INJHAL_udtBEFORE_PULSE_4          (INJHAL_tudtInjectorPhase)3u
#define INJHAL_udtBEFORE_PULSE_5          (INJHAL_tudtInjectorPhase)4u
#define INJHAL_u8INJECTION_PULSE_1        (0u)
#define INJHAL_u8INJECTION_PULSE_2        (1u)
#define INJHAL_u8INJECTION_PULSE_3        (2u)
#define INJHAL_u8INJECTION_PULSE_4        (3u)
#define INJHAL_u8INJECTION_PULSE_5        (4u)
#define INJHAL_u8MODE_1_INJECTION         (1u)
#define INJHAL_u8MODE_2_INJECTIONS        (2u)
#define INJHAL_u8MODE_3_INJECTIONS        (3u)
#define INJHAL_u8MODE_4_INJECTIONS        (4u)
#define INJHAL_u8MODE_5_INJECTIONS        (5u)


/*************************************************************************/
/* INJHAL Angle Notification Functions                                   */
/*************************************************************************/
#define INJHAL_vidSN_CM_66_ANGLE_NOTIF INJHAL_vidAngleTimeNotif_CM_66
#define INJHAL_vidSN_CM_45_ANGLE_NOTIF INJHAL_vidAngleTimeNotif_CM_45
#define INJHAL_vidSN_CM_24_ANGLE_NOTIF INJHAL_vidAngleTimeNotif_CM_24


/*************************************************************************/
/* INJHAL Cycle Angle References                                         */
/*************************************************************************/
#define INJHAL_u16SN_CM_66_CYCLE_REF INJHAL_u16CM_66_CycleRef
#define INJHAL_u16SN_CM_45_CYCLE_REF INJHAL_u16CM_45_CycleRef
#define INJHAL_u16SN_CM_24_CYCLE_REF INJHAL_u16CM_24_CycleRef


/*************************************************************************/
/* (ATOM)  Channels                                                      */
/*************************************************************************/
#define INJHAL_snALARM_SN_CM_66      CRKHAL_snINJ_1_ANGLE_ATOM
#define INJHAL_snALARM_SN_CM_66_CH   CRKHAL_snINJ_1_ANGLE_CHANNEL
#define INJHAL_snALARM_SN_CM_45      CRKHAL_snINJ_2_ANGLE_ATOM
#define INJHAL_snALARM_SN_CM_45_CH   CRKHAL_snINJ_2_ANGLE_CHANNEL
#define INJHAL_snALARM_SN_CM_24      CRKHAL_snINJ_3_ANGLE_ATOM
#define INJHAL_snALARM_SN_CM_24_CH   CRKHAL_snINJ_3_ANGLE_CHANNEL


/*************************************************************************/
/* CRKHAL Channels                                                       */
/*************************************************************************/
#define INJHAL_u8CRKHAL_SN_CM_66_CH CRKHAL_u8ALARM_INJ_1_ANGLE
#define INJHAL_u8CRKHAL_SN_CM_45_CH CRKHAL_u8ALARM_INJ_2_ANGLE
#define INJHAL_u8CRKHAL_SN_CM_24_CH CRKHAL_u8ALARM_INJ_3_ANGLE


/*************************************************************************/
/* INJHAL Overlap Management Feature                                     */
/*************************************************************************/
#define INJHAL_snSN_CM_66_OVLP_MANAGEMENT OVLP_OFF
#define INJHAL_snSN_CM_45_OVLP_MANAGEMENT OVLP_OFF
#define INJHAL_snSN_CM_24_OVLP_MANAGEMENT OVLP_OFF


/*************************************************************************/
/* INJHAL Injector / Bank Instance IDs                                   */
/*************************************************************************/
#define GDI_1_TO_3 0u

#define INJHAL_u8SN_CM_66_INSTANCE_ID GDI_1_TO_3
#define INJHAL_u8SN_CM_45_INSTANCE_ID GDI_1_TO_3
#define INJHAL_u8SN_CM_24_INSTANCE_ID GDI_1_TO_3


/*************************************************************************/
/* INJHAL Injector Channel IDs                                           */
/*************************************************************************/
#define CM_66 0u
#define CM_45 1u
#define CM_24 2u

#define INJHAL_u8SN_CM_66_CHANNEL_ID CM_66
#define INJHAL_u8SN_CM_45_CHANNEL_ID CM_45
#define INJHAL_u8SN_CM_24_CHANNEL_ID CM_24


/*************************************************************************/
/* INJHAL Injector Masks                                                 */
/*************************************************************************/
#define CM_66_MASK (0x01u)
#define CM_45_MASK (0x02u)
#define CM_24_MASK (0x04u)

#define INJHAL_bfSN_CM_66_MASK CM_66_MASK
#define INJHAL_bfSN_CM_45_MASK CM_45_MASK
#define INJHAL_bfSN_CM_24_MASK CM_24_MASK


/*************************************************************************/
/* INJHAL GDI Profiles List                                              */
/*************************************************************************/
#define INJHAL_u8HP_PROFILE L9781_u8PROF_HIGH_PRESS_INJ
#define INJHAL_u8LP_PROFILE L9781_u8PROF_LOW_PRESS_INJ
#define INJHAL_u8NP_PROFILE L9781_u8PROF_NOM_PRESS_INJ
#define INJHAL_u8OP_PROFILE L9781_u8PROF_OVER_PRESS_INJ


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgWriteInitValues                                */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgWriteInitValues( \
\
   u8InstanceId \
\
) \
   do \
   { \
      \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidWRITE_INIT_VALUE(SN_CM_66); \
            INJHAL_u16CM_66_CycleRef = (uint16)INJHAL_ku16CM_66_CycleRef; \
            INJHAL_vidWRITE_INIT_VALUE(SN_CM_45); \
            INJHAL_u16CM_45_CycleRef = (uint16)INJHAL_ku16CM_45_CycleRef; \
            INJHAL_vidWRITE_INIT_VALUE(SN_CM_24); \
            INJHAL_u16CM_24_CycleRef = (uint16)INJHAL_ku16CM_24_CycleRef; \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgUpdateInjAngles                                */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgUpdateInjAngles( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidUPDATE_INJ_ANGLE(SN_CM_66); \
            INJHAL_vidUPDATE_INJ_ANGLE(SN_CM_45); \
            INJHAL_vidUPDATE_INJ_ANGLE(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgUpdateInjTimes                                 */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgUpdateInjTimes( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidUPDATE_INJ_TIME(SN_CM_66); \
            INJHAL_vidUPDATE_INJ_TIME(SN_CM_45); \
            INJHAL_vidUPDATE_INJ_TIME(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgInitWaitSynchro                                */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgInitWaitSynchro( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidINIT_WAIT_SYNCHRO(SN_CM_66); \
            INJHAL_vidINIT_WAIT_SYNCHRO(SN_CM_45); \
            INJHAL_vidINIT_WAIT_SYNCHRO(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgInitAllInjectors                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgInitAllInjectors( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidINIT_INJECTOR(SN_CM_66); \
            INJHAL_vidINIT_INJECTOR(SN_CM_45); \
            INJHAL_vidINIT_INJECTOR(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgWritePreInjSeqNotif                            */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgWritePreInjSeqNotif( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidWRITE_SEQ_PREINJ_NOTIF(SN_CM_66); \
            INJHAL_vidWRITE_SEQ_PREINJ_NOTIF(SN_CM_45); \
            INJHAL_vidWRITE_SEQ_PREINJ_NOTIF(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgProgNextInjections                             */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgProgNextInjections( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidPROG_NEXT_INJ(SN_CM_66); \
            INJHAL_vidPROG_NEXT_INJ(SN_CM_45); \
            INJHAL_vidPROG_NEXT_INJ(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgStartFGPreInj                                  */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgStartFGPreInj( \
\
   u8InstanceId, \
   u32FGPreInjTime \
\
) \
   do \
   { \
      uint32 pulseWidth; \
      \
      \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            pulseWidth = (u32FGPreInjTime + IfxGtm_u32ReadCapTime(INJHAL_pstrSN_CM_66)) & GTM_TBU_TIMER_MAX_LIMIT; \
            IfxGtm_vidAtomEnableNotif(INJHAL_pstrSN_CM_66, \
                                      (uint8)IfxGtm_Compare_Unit_0); \
            IfxGtm_vidAtomSetCond(INJHAL_pstrSN_CM_66, \
                                  INACTIVE_CCU1, \
                                  pulseWidth, \
                                  (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                                  CCU0_ONLY_OUT_INACT); \
            INJHAL_vidINJECTON_START_HOOK(SN_CM_66); \
            IfxGtm_vidAtomEnableNotif(INJHAL_pstrSN_CM_45, \
                                      (uint8)IfxGtm_Compare_Unit_0); \
            IfxGtm_vidAtomSetCond(INJHAL_pstrSN_CM_45, \
                                  INACTIVE_CCU1, \
                                  pulseWidth, \
                                  (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                                  CCU0_ONLY_OUT_INACT); \
            INJHAL_vidINJECTON_START_HOOK(SN_CM_45); \
            IfxGtm_vidAtomEnableNotif(INJHAL_pstrSN_CM_24, \
                                      (uint8)IfxGtm_Compare_Unit_0); \
            IfxGtm_vidAtomSetCond(INJHAL_pstrSN_CM_24, \
                                  INACTIVE_CCU1, \
                                  pulseWidth, \
                                  (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe, \
                                  CCU0_ONLY_OUT_INACT); \
            INJHAL_vidINJECTON_START_HOOK(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgInjectorPhaseMgmt                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgInjectorPhaseMgmt( \
\
   snChannel, \
   ps32NewInjectionAngle, \
   pu32InjectionTime \
\
) \
   M1_INJHAL_vidCfgInjectorPhaseMgmt(snChannel, \
                                     INJHAL_u8GET_CHANNEL_ID(snChannel), \
                                     ps32NewInjectionAngle, \
                                     pu32InjectionTime)

   #define M1_INJHAL_vidCfgInjectorPhaseMgmt(snChannel, \
                                             u8Channel, \
                                             ps32NewInjectionAngle, \
                                             pu32InjectionTime) \
      M2_INJHAL_vidCfgInjectorPhaseMgmt(snChannel, \
                                        u8Channel, \
                                        ps32NewInjectionAngle, \
                                        pu32InjectionTime)

   #define M2_INJHAL_vidCfgInjectorPhaseMgmt(snChannel, \
                                             u8Channel, \
                                             ps32NewInjectionAngle, \
                                             pu32InjectionTime) \
   do \
   { \
      uint32 u32LocalTbu_Data ;\
      switch (INJHAL_audtCurrentInjectorPhase[u8Channel]) \
      { \
         case INJHAL_udtBEFORE_END_OF_CYCLE: \
            INJHAL_vidEND_OF_CYCLE_OVLP_MGMT(snChannel);\
            /* Pull the signal low : */ \
            IfxGtm_vidAtomDisableNotification(INJHAL_pstr##snChannel, \
                                             (uint8)IfxGtm_Compare_Unit_0); \
            u32LocalTbu_Data = IfxGtm_u32ReadCapTime(INJHAL_pstr##snChannel);\
            IfxGtm_vidAtomSetCond (INJHAL_pstr##snChannel,  \
                                   INACTIVE_CCU1, \
                                   u32LocalTbu_Data, \
                                   (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe , \
                                   CCU0_ONLY_OUT_INACT);\
            /* clear the interrupt notify in the register */\
            IfxGtm_vidAtomClearInterrupt(INJHAL_pstr##snChannel , \
                    (uint8)IfxGtm_Compare_Unit_0);\
            IfxGtm_vidAtomEnableNotif(INJHAL_pstr##snChannel , \
                    (uint8)IfxGtm_Compare_Unit_0 );\
            \
            INJHAL_audtCurrentInjectorPhase[u8Channel] = \
               INJHAL_udtBEFORE_PULSE_1; \
            *(ps32NewInjectionAngle) = \
               (sint32)(INJHAL_au16InjectionAngle[INJHAL_u8INJECTION_PULSE_1][u8Channel]); \
            *(pu32InjectionTime) = (uint32)UINT32_MIN; \
            INJHAL_au16NoOverLap[u8Channel] = 1u;\
            break; \
            \
         case INJHAL_udtBEFORE_PULSE_1: \
            if ( INJHAL_au8InjectionMode[u8Channel] \
               > INJHAL_u8MODE_1_INJECTION) \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_PULSE_2; \
               *(ps32NewInjectionAngle) = \
                  (sint32)(INJHAL_au16InjectionAngle[INJHAL_u8INJECTION_PULSE_2]\
                          [u8Channel]); \
            } \
            else \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_END_OF_CYCLE; \
               *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
            } \
            *(pu32InjectionTime) = \
               INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_1]\
               [u8Channel]; \
            break; \
            \
         case INJHAL_udtBEFORE_PULSE_2: \
            if ( INJHAL_au8InjectionMode[u8Channel] \
               > INJHAL_u8MODE_2_INJECTIONS) \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_PULSE_3; \
               *(ps32NewInjectionAngle) = \
                  (sint32)(INJHAL_au16InjectionAngle[INJHAL_u8INJECTION_PULSE_3][u8Channel]); \
               *(pu32InjectionTime) = \
                  INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_2][u8Channel]; \
            } \
            else if (   INJHAL_au8InjectionMode[u8Channel] \
                     == INJHAL_u8MODE_2_INJECTIONS) \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_END_OF_CYCLE; \
               *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
               *(pu32InjectionTime) = \
                  INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_2][u8Channel]; \
            } \
            else \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_END_OF_CYCLE; \
               *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
               *(pu32InjectionTime) = 0u; \
               SWFAIL_vidSoftwareErrorHook();\
            } \
            break; \
            \
         case INJHAL_udtBEFORE_PULSE_3: \
            if ( INJHAL_au8InjectionMode[u8Channel] \
               > INJHAL_u8MODE_3_INJECTIONS) \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_PULSE_4; \
               *(ps32NewInjectionAngle) = \
                  (sint32)(INJHAL_au16InjectionAngle[INJHAL_u8INJECTION_PULSE_4][u8Channel]); \
               *(pu32InjectionTime) = \
                  INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_3][u8Channel]; \
            } \
            else if (   INJHAL_au8InjectionMode[u8Channel] \
                     == INJHAL_u8MODE_3_INJECTIONS) \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_END_OF_CYCLE; \
               *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
               *(pu32InjectionTime) = \
                  INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_3][u8Channel]; \
            } \
            else \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_END_OF_CYCLE; \
               *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
               *(pu32InjectionTime) = 0u; \
               SWFAIL_vidSoftwareErrorHook();\
            } \
            break; \
            \
         case INJHAL_udtBEFORE_PULSE_4: \
            if ( INJHAL_au8InjectionMode[u8Channel] \
               > INJHAL_u8MODE_4_INJECTIONS) \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_PULSE_5; \
               *(ps32NewInjectionAngle) = \
                  (sint32)(INJHAL_au16InjectionAngle[INJHAL_u8INJECTION_PULSE_5][u8Channel]); \
               *(pu32InjectionTime) = \
                  INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_4][u8Channel]; \
            } \
            else if (   INJHAL_au8InjectionMode[u8Channel] \
                     == INJHAL_u8MODE_4_INJECTIONS) \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_END_OF_CYCLE; \
               *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
               *(pu32InjectionTime) = \
                  INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_4][u8Channel]; \
            } \
            else \
            { \
               INJHAL_audtCurrentInjectorPhase[u8Channel] = \
                  INJHAL_udtBEFORE_END_OF_CYCLE; \
               *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
               *(pu32InjectionTime) = 0u; \
               SWFAIL_vidSoftwareErrorHook();\
            } \
            break; \
            \
         case INJHAL_udtBEFORE_PULSE_5: \
            INJHAL_audtCurrentInjectorPhase[u8Channel] = \
               INJHAL_udtBEFORE_END_OF_CYCLE; \
            *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
            if (  INJHAL_au8InjectionMode[u8Channel] \
               == INJHAL_u8MODE_5_INJECTIONS) \
            { \
               *(pu32InjectionTime) = \
                  INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_5][u8Channel]; \
            } \
            else \
            { \
               *(pu32InjectionTime) = (uint32)UINT32_MIN; \
            } \
            break; \
            \
         default: \
            INJHAL_audtCurrentInjectorPhase[u8Channel] = \
               INJHAL_udtBEFORE_END_OF_CYCLE; \
            *(ps32NewInjectionAngle) = (sint32)(INJHAL_u16ENGINE_CYCLE); \
            *(pu32InjectionTime) = (uint32)UINT32_MIN; \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgInjTimeUpdateMgmt                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgInjTimeUpdateMgmt( \
\
   u8Channel, \
   pu32InjectionTime \
\
) \
   do \
   { \
      switch (INJHAL_audtCurrentInjectorPhase[u8Channel]) \
      { \
         case INJHAL_udtBEFORE_PULSE_1: \
            *(pu32InjectionTime) = (uint32)UINT32_MIN; \
            break; \
         \
         case INJHAL_udtBEFORE_PULSE_2: \
            *(pu32InjectionTime) = \
               INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_1][u8Channel]; \
            break; \
         \
         case INJHAL_udtBEFORE_PULSE_3: \
            *(pu32InjectionTime) = \
               INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_2][u8Channel]; \
            break; \
         \
         case INJHAL_udtBEFORE_PULSE_4: \
            *(pu32InjectionTime) = \
               INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_3][u8Channel]; \
            break; \
         \
         case INJHAL_udtBEFORE_PULSE_5: \
            *(pu32InjectionTime) = \
               INJHAL_au32InjectionTime[INJHAL_u8INJECTION_PULSE_4][u8Channel]; \
            break; \
         \
         case INJHAL_udtBEFORE_END_OF_CYCLE: \
            *(pu32InjectionTime) = \
               INJHAL_au32InjectionTime[INJHAL_au8InjectionMode[u8Channel] - 1][u8Channel]; \
            break; \
         \
         default: \
            *(pu32InjectionTime) = (uint32)UINT32_MIN; \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgTimeNotifFunctions                             */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgTimeNotifFunctions( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidEND_OF_PULSE_NOTIF(SN_CM_66); \
            INJHAL_vidEND_OF_PULSE_NOTIF(SN_CM_45); \
            INJHAL_vidEND_OF_PULSE_NOTIF(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgWriteTestTime                                  */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgWriteTestTime( \
\
   u8Channel, \
   u32InjTestTime \
\
) \
   do \
   { \
      uint32  pulseWidth;\
	   pulseWidth = (u32InjTestTime + TBU_READ_TIME()) & GTM_TBU_TIMER_MAX_LIMIT; \
      switch(u8Channel) \
      { \
         case CM_66: \
            INJHAL_vidCfgWriteTestTimeChannel(SN_CM_66); \
            break; \
         \
         case CM_45: \
            INJHAL_vidCfgWriteTestTimeChannel(SN_CM_45); \
            break; \
         \
         case CM_24: \
            INJHAL_vidCfgWriteTestTimeChannel(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
         break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_udtCAM_READ_SYNC_STATUS                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_udtCAM_READ_SYNC_STATUS( \
\
   pbStatus \
\
) \
   CAMHAL_udtReadStatus(CAMHAL_udtCH_CM_81, CAMHAL_u8SYNCHRONISED, pbStatus)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgInjTimeRescale                                 */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgInjTimeRescale( \
\
   pu32InjectionTime \
\
) \
   do \
   { \
      ; \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCancelInjAlarm                                    */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCancelInjAlarm( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            INJHAL_vidCANCELALARM(SN_CM_66); \
            INJHAL_vidCANCELALARM(SN_CM_45); \
            INJHAL_vidCANCELALARM(SN_CM_24); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidclearFGAngIrq                                     */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidclearFGAngIrq( \
\
   u8InstanceId \
\
) \
   do \
   { \
      switch (u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            IfxGtm_vidAtomClearInterrupt(INJHAL_pstrSN_CM_66,1U); \
            IfxGtm_vidAtomClearInterrupt(INJHAL_pstrSN_CM_45,1U); \
            IfxGtm_vidAtomClearInterrupt(INJHAL_pstrSN_CM_24,1U); \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)


/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgSwitchGdiProfile                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgSwitchGdiProfile( \
\
   u8InstanceId, \
   u8GdiProfileId, \
   pudtStatus \
\
) \
   do \
   { \
      Std_ReturnType udtLocalMacroStatus; \
      \
      \
      udtLocalMacroStatus = E_OK; \
      \
      switch(u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            switch(u8GdiProfileId) \
            { \
               case INJHAL_u8LP_PROFILE: \
               case INJHAL_u8NP_PROFILE: \
               case INJHAL_u8HP_PROFILE: \
               case INJHAL_u8OP_PROFILE: \
                  if (udtLocalMacroStatus != E_NOT_OK) \
                  { \
                     udtLocalMacroStatus = \
                        L9781_udtLoadInjectorProfile(L9781_u8ASIC_1_CH, \
                                                     u8GdiProfileId); \
                  } \
                  if (udtLocalMacroStatus != E_NOT_OK) \
                  { \
                     udtLocalMacroStatus = \
                        L9781_udtLoadInjectorProfile(L9781_u8ASIC_2_CH, \
                                                     u8GdiProfileId); \
                  } \
                  break; \
               \
               default: \
                  udtLocalMacroStatus = E_NOT_OK; \
                  break; \
            } \
            break; \
            \
         default: \
            udtLocalMacroStatus = E_NOT_OK; \
            break; \
      } \
      \
      *pudtStatus = udtLocalMacroStatus; \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgStopGdiHw                                      */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgStopGdiHw( \
\
   u8InstanceId, \
   pudtStatus \
\
) \
   do \
   { \
      Std_ReturnType udtLocalMacroStatus; \
      \
      \
      switch(u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            udtLocalMacroStatus = L9781_udtFullStop(); \
            break; \
            \
         default: \
            udtLocalMacroStatus = E_NOT_OK; \
            break; \
      } \
      \
      *pudtStatus = udtLocalMacroStatus; \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : INJHAL_vidCfgRestartGdiHw                                   */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define INJHAL_vidCfgRestartGdiHw( \
\
   u8InstanceId, \
   pudtStatus \
\
) \
   do \
   { \
      Std_ReturnType udtLocalMacroStatus; \
      \
      \
      switch(u8InstanceId) \
      { \
         case GDI_1_TO_3: \
            udtLocalMacroStatus = L9781_udtReInitialize(); \
            break; \
            \
         default: \
            udtLocalMacroStatus = E_NOT_OK; \
            break; \
      } \
      \
      *pudtStatus = udtLocalMacroStatus; \
   } \
   while (0)


/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/*************************************************************************/
/* boolean Calibrations                                                  */
/*************************************************************************/
#define INJHAL_START_SEC_CALIB_BOOLEAN
#include "INJHAL_MemMap.h"
/*lint -esym(960,8.7) */
extern CONST(boolean, INJHAL_CALIB)
          INJHAL_kabEnableAngleUpdate[INJHAL_u8NB_INSTANCES];

#define INJHAL_STOP_SEC_CALIB_BOOLEAN
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* uint32 Calibrations                                                   */
/*************************************************************************/


/*************************************************************************/
/* uint16 Calibrations                                                   */
/*************************************************************************/
#define INJHAL_START_SEC_CALIB_16BIT
#include "INJHAL_MemMap.h"

extern CONST(uint16, INJHAL_CALIB) INJHAL_ku16CM_66_CycleRef;
extern CONST(uint16, INJHAL_CALIB) INJHAL_ku16CM_45_CycleRef;
extern CONST(uint16, INJHAL_CALIB) INJHAL_ku16CM_24_CycleRef;


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

extern CONST(boolean, INJHAL_CONST)
   INJHAL_kabPreInjAuthorization[INJHAL_u8NB_INSTANCES];

#define INJHAL_STOP_SEC_CONST_BOOLEAN
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* 8 Bits Const                                                          */
/*************************************************************************/
#define INJHAL_START_SEC_CONST_8BIT
#include "INJHAL_MemMap.h"

extern CONST(uint8, INJHAL_CONST)
   INJHAL_kau8InstanceOffset[INJHAL_u8NB_INSTANCES];
extern CONST(uint8, INJHAL_CONST)
   INJHAL_kau8NbInjectors[INJHAL_u8NB_INSTANCES];
extern CONST(uint8, INJHAL_CONST)
   INJHAL_kau8CrkhalChannel[INJHAL_u8NB_INJECTORS];
extern CONST(uint8, INJHAL_CONST)
   INJHAL_kau8ChannelForPreInj[INJHAL_u8NB_INSTANCES];

#define INJHAL_STOP_SEC_CONST_8BIT
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* User Defined Const (Unspecified)                                      */
/*************************************************************************/
#define INJHAL_START_SEC_CONST_UNSPECIFIED
#include "INJHAL_MemMap.h"

extern CONST(INJHAL_tudtInjectorPhase, INJHAL_CONST)
   INJHAL_kaudtCorrespInjectorPhase[INJHAL_u8NB_INJ_PULSES];

#define INJHAL_STOP_SEC_CONST_UNSPECIFIED
#include "INJHAL_MemMap.h"

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/*************************************************************************/
/* boolean Variables                                                     */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "INJHAL_MemMap.h"

extern VAR(boolean, INJHAL_VAR) INJHAL_abEnable[INJHAL_u8NB_INSTANCES];
extern VAR(boolean, INJHAL_VAR) INJHAL_abEnableFGPreInj[INJHAL_u8NB_INSTANCES];
extern VAR(boolean, INJHAL_VAR)
   INJHAL_abEnableSeqPreInj[INJHAL_u8NB_INSTANCES];
extern VAR(boolean, INJHAL_VAR)
   INJHAL_abInjectionTimeUpdated[INJHAL_u8NB_INJECTORS];
extern VAR(boolean, INJHAL_VAR) INJHAL_abInjStarted[INJHAL_u8NB_INSTANCES];

extern VAR(boolean, INJHAL_VAR)
   INJHAL_abFGPreInjStartAngReady[INJHAL_u8NB_INSTANCES];
extern VAR(boolean, INJHAL_VAR)
   INJHAL_abFGPreInjEndAngReady[INJHAL_u8NB_INSTANCES];
extern VAR(boolean, INJHAL_VAR)
   INJHAL_abEndOfPreInjTreated[INJHAL_u8NB_INSTANCES];

#define INJHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* 8 Bit Variables                                                       */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_8BIT
#include "INJHAL_MemMap.h"

extern VAR(uint8, INJHAL_VAR) INJHAL_aenuInjectorMode[INJHAL_u8NB_INJECTORS];
extern VAR(uint8, INJHAL_VAR) INJHAL_aenuInjComponentStatus[INJHAL_u8NB_INSTANCES];
extern VAR(uint8, INJHAL_VAR) INJHAL_au8AngleMatch[INJHAL_u8NB_INJECTORS];
extern VAR(uint8, INJHAL_VAR) INJHAL_au8InjectionMode[INJHAL_u8NB_INJECTORS];

#define INJHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* 16 Bit Variables                                                      */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_16BIT
#include "INJHAL_MemMap.h"

extern VAR(uint16, INJHAL_VAR) INJHAL_u16CM_66_CycleRef;
extern VAR(uint16, INJHAL_VAR) INJHAL_u16CM_45_CycleRef;
extern VAR(uint16, INJHAL_VAR) INJHAL_u16CM_24_CycleRef;

extern VAR(uint16, INJHAL_VAR)
   INJHAL_au16AngleForPreInj[INJHAL_u8NB_INSTANCES];
extern VAR(uint16, INJHAL_VAR)
   INJHAL_au16InjectionAngle[INJHAL_u8NB_INJ_PULSES][INJHAL_u8NB_INJECTORS];
extern VAR(uint16, INJHAL_VAR)
   INJHAL_au16ProgAngleForPreInj[INJHAL_u8NB_INSTANCES];
extern VAR(uint16, INJHAL_VAR)
   INJHAL_au16SeqPreInjAngle[INJHAL_u8NB_INJECTORS];
extern VAR(uint16, INJHAL_VAR)
   INJHAL_au16FGPreInjEndAngle[INJHAL_u8NB_INSTANCES];
extern VAR(uint16, INJHAL_VAR) INJHAL_au16NoOverLap[INJHAL_u8NB_INJECTORS];
extern VAR(uint16, INJHAL_VAR)
   INJHAL_au16TimerRunning[INJHAL_u8NB_INJECTORS];

#define INJHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* 32 Bit Variables                                                      */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_32BIT
#include "INJHAL_MemMap.h"

extern VAR(uint32, INJHAL_VAR) INJHAL_au32FGPreInjTime[INJHAL_u8NB_INSTANCES];
extern VAR(uint32, INJHAL_VAR)
   INJHAL_au32InjectionTime[INJHAL_u8NB_INJ_PULSES][INJHAL_u8NB_INJECTORS];
extern VAR(uint32, INJHAL_VAR)
   INJHAL_au32PrevInjectionTime[INJHAL_u8NB_INJECTORS];
extern VAR(uint32, INJHAL_VAR) INJHAL_au32SeqPreInjTime[INJHAL_u8NB_INJECTORS];

#define INJHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "INJHAL_MemMap.h"

/*************************************************************************/
/* User Defined Variables (Unspecified)                                  */
/*************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "INJHAL_MemMap.h"

extern VAR(INJHAL_tbfAngleUpdate, INJHAL_VAR)
   INJHAL_abfAngleUpdate[INJHAL_u8NB_INSTANCES];
extern VAR(INJHAL_tbfInhibitMask, INJHAL_VAR)
   INJHAL_abfInjectionCut[INJHAL_u8NB_INSTANCES];
extern VAR(INJHAL_tbfTimeUpdate, INJHAL_VAR)
   INJHAL_abfTimeUpdate[INJHAL_u8NB_INSTANCES];
extern VAR(INJHAL_tudtInjectorPhase, INJHAL_VAR)
   INJHAL_audtCurrentInjectorPhase[INJHAL_u8NB_INJECTORS];

extern volatile Ifx_GTM_ATOM_CH* INJHAL_pstrSN_CM_66;
extern volatile Ifx_GTM_ATOM_AGC* INJHAL_pstrAgcSN_CM_66;
extern volatile Ifx_GTM_ATOM_CH* INJHAL_pstrSN_CM_45;
extern volatile Ifx_GTM_ATOM_AGC* INJHAL_pstrAgcSN_CM_45;
extern volatile Ifx_GTM_ATOM_CH* INJHAL_pstrSN_CM_24;
extern volatile Ifx_GTM_ATOM_AGC* INJHAL_pstrAgcSN_CM_24;


#define INJHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "INJHAL_MemMap.h"

#endif /* INJHAL_CFG_I_H */

/*------------------------------- end of file --------------------------------*/
