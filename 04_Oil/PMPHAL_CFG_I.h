/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_CFG_I.h                                                                                  */
/* !Description     : Configuration of the PMPHAL Component                                                           */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/

#ifndef PMPHAL_CFG_I_H
#define PMPHAL_CFG_I_H

#include "Std_Types.h"

#include "PMPHAL.h"
#include "PMPHAL_L.h"
#include "ADCHAL.h"
#include "L9781.h"
#include "SWFAIL.h"


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/***************************************/
/* PMPHAL General Configuration        */
/***************************************/
#define PMPHAL_u32MAX_CMD_GTM_DYNAMIC  0xFFFFFFu
#define PMPHAL_u32MAX_DLY_GPT_DYNAMIC  0xFFFFFFu


/***************************************/
/* DIO Channels                        */
/***************************************/
#define PMPHAL_snDIO_SPILL_CMD_CH      DioConf_DioChannel_M_CMD_GDI_PMP


/***************************************/
/* CRKHAL Channels                     */
/***************************************/
#define PMPHAL_u8CRKHAL_SPILL_CMD_CH   CRKHAL_u8ALARM_M_CMD_GDI_PMP_ANGLE
#define PMPHAL_u8CRKHAL_SPILL_EVENT_CH CRKHAL_u8ALARM_SPILL_EVENT_ANGLE


/***************************************/
/* Timer / Capcom Configurations       */
/***************************************/
#define PMPHAL_snGPT_PMP_DELAY_CH      GptConf_GptChannel_PMP_DELAY


/***************************************/
/* PORT Configurations                 */
/***************************************/
#define PMPHAL_snPORT_OSP_MODE         PORT_PIN_MODE_ALT1


/***************************************/
/* Profile Management Configuration    */
/***************************************/
/***************************************/
/* Use of Profile Switching Management */
/***************************************/
#define PROFILES_MGMT_ON


/***************************************/
/* Available Profiles List             */
/***************************************/
#define PMPHAL_u8DEFAULT_PROFILE L9781_u8IDX_PMP_PROF_DEF
#define PMPHAL_u8PROF_1 L9781_u8IDX_PROF_01_PMP
#define PMPHAL_u8PROF_10 L9781_u8IDX_PROF_10_PMP
#define PMPHAL_u8PROF_11 L9781_u8IDX_PROF_11_PMP
#define PMPHAL_u8PROF_12 L9781_u8IDX_PROF_12_PMP
#define PMPHAL_u8PROF_13 L9781_u8IDX_PROF_13_PMP
#define PMPHAL_u8PROF_14 L9781_u8IDX_PROF_14_PMP
#define PMPHAL_u8PROF_15 L9781_u8IDX_PROF_15_PMP
#define PMPHAL_u8PROF_16 L9781_u8IDX_PROF_16_PMP
#define PMPHAL_u8PROF_17 L9781_u8IDX_PROF_17_PMP
#define PMPHAL_u8PROF_18 L9781_u8IDX_PROF_18_PMP
#define PMPHAL_u8PROF_19 L9781_u8IDX_PROF_19_PMP
#define PMPHAL_u8PROF_2 L9781_u8IDX_PROF_02_PMP
#define PMPHAL_u8PROF_20 L9781_u8IDX_PROF_20_PMP
#define PMPHAL_u8PROF_21 L9781_u8IDX_PROF_21_PMP
#define PMPHAL_u8PROF_22 L9781_u8IDX_PROF_22_PMP
#define PMPHAL_u8PROF_23 L9781_u8IDX_PROF_23_PMP
#define PMPHAL_u8PROF_24 L9781_u8IDX_PROF_24_PMP
#define PMPHAL_u8PROF_25 L9781_u8IDX_PROF_25_PMP
#define PMPHAL_u8PROF_26 L9781_u8IDX_PROF_26_PMP
#define PMPHAL_u8PROF_3 L9781_u8IDX_PROF_03_PMP
#define PMPHAL_u8PROF_4 L9781_u8IDX_PROF_04_PMP
#define PMPHAL_u8PROF_5 L9781_u8IDX_PROF_05_PMP
#define PMPHAL_u8PROF_6 L9781_u8IDX_PROF_06_PMP
#define PMPHAL_u8PROF_7 L9781_u8IDX_PROF_07_PMP
#define PMPHAL_u8PROF_8 L9781_u8IDX_PROF_08_PMP
#define PMPHAL_u8PROF_9 L9781_u8IDX_PROF_09_PMP


/**********************************************************************************************************************/
/* MACRO FUNCTIONS                                                                                                    */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidSpillEventCallBack                                                                        */
/* !Description : Functions that need to be called on the Spill Event interrupt shall be called by the callback       */
/*                PMPHAL_vidSpillEventCallBack.                                                                       */
/* !Trace_To    : INT REQ: VEES_R_11_06466_040.01                                                                     */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
#define PMPHAL_vidSpillEventCallBack() \
do \
{ \
   PMPHAL_vidSpillEventManager(); \
   ADCHAL_vidEntry_SPILL_EVENT(); \
} \
while (0u);

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidCfgCmdTimeRescale                                                                         */
/* !Description : This private macro rescales the "pu32CommandTime" (Res = 100 ns) to the actual timer resolution     */
/*                depending on  "DCNT_RESOL_IN_NS" OIL resolution value.                                              */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
#define PMPHAL_vidCfgCmdTimeRescale( \
\
   pu32CommandTime, \
   pudtStatus \
\
) \
do \
{ \
   uint32 u32LocalCommandTime = *pu32CommandTime; \
   if (u32LocalCommandTime <= PMPHAL_u32MAX_CMD_GTM_DYNAMIC) \
   { \
      *pu32CommandTime = u32LocalCommandTime; \
      *pudtStatus = E_OK; \
   } \
   else \
   { \
      *pu32CommandTime = 0u; \
      *pudtStatus = E_NOT_OK; \
      SWFAIL_vidSoftwareErrorHook(); \
   } \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidCfgSwitchCmdProfile                                                                       */
/* !Description : This private macro applies the new current profile to the spill valve according to the parameter    */
/*                "u8PmpPulseId".                                                                                     */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
#define PMPHAL_vidCfgSwitchCmdProfile( \
\
   u8HppPulseId, \
   pudtStatus \
\
) \
   do \
   { \
      Std_ReturnType udtLocalStatus; \
      \
      \
      udtLocalStatus = *pudtStatus; \
      \
      switch (u8HppPulseId) \
      { \
         case PMPHAL_u8CMD_PULSE_ID: \
            if ((PMPHAL_u8CurrentProfileId != PMPHAL_u8CmdPulseProfileId) || (udtLocalStatus != E_OK)) \
            { \
               udtLocalStatus = L9781_udtLoadPumpProfile(L9781_u8ASIC_1_CH, PMPHAL_u8CmdPulseProfileId); \
               PMPHAL_u8CurrentProfileId = PMPHAL_u8CmdPulseProfileId; \
            } \
            break; \
         \
         case PMPHAL_u8DECEL_PULSE_ID: \
            if ((PMPHAL_u8CurrentProfileId != PMPHAL_u8DecelPulseProfileIdMem) || (udtLocalStatus != E_OK)) \
            { \
               udtLocalStatus = L9781_udtLoadPumpProfile(L9781_u8ASIC_1_CH, PMPHAL_u8DecelPulseProfileIdMem); \
               PMPHAL_u8CurrentProfileId = PMPHAL_u8DecelPulseProfileIdMem; \
            } \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
      } \
      \
      *pudtStatus = udtLocalStatus; \
   } \
   while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidCfgDlyTimeRescale                                                                         */
/* !Description : This private macro rescales the "pu32DelayTime" (Res = 100 ns) to the actual timer resolution       */
/*                depending on "DCNT_RESOL_IN_NS" OIL resolution value.                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
#define PMPHAL_vidCfgDlyTimeRescale( \
\
   pu32DelayTime, \
   pudtStatus \
\
) \
do \
{ \
   uint32 u32LocalDelayTime = *pu32DelayTime; \
   if (u32LocalDelayTime <= PMPHAL_u32MAX_DLY_GPT_DYNAMIC) \
   { \
      *pu32DelayTime = u32LocalDelayTime; \
      *pudtStatus = E_OK; \
   } \
   else \
   { \
      *pu32DelayTime = 0u; \
      *pudtStatus = E_NOT_OK; \
      SWFAIL_vidSoftwareErrorHook(); \
   } \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_udtCfgGetProfileStatus                                                                       */
/* !Description : This private macro returns the current status of the Spill Valve profile and shall return E_OK when */
/*                the profile has been switched successfully and E_NOT_OK otherwise.                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
#define PMPHAL_udtCfgGetProfileStatus() \
   L9781_udtGetPumpProfileStatus(L9781_u8ASIC_1_CH)


#endif /* PMPHAL_CFG_I_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
