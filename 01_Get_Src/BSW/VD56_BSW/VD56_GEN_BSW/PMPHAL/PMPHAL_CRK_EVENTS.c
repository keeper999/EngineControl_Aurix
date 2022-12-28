/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_CRK_EVENTS.c                                                                             */
/* !Description     : Management Crankshaft Events                                                                    */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A189069.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"

#include "PMPHAL.h"
#include "PMPHAL_CFG_I.h"
#include "PMPHAL_I.h"
#include "PMPHAL_L.h"

#include "CRKHAL.h"
#include "Gpt.h"
#include "SchM_PMPHAL.h"
#include "SWFAIL.h"

/**********************************************************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                                                         */
/**********************************************************************************************************************/

#define PMPHAL_START_SEC_CODE
#include "PMPHAL_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidCrkSyncFoundEntry                                                                         */
/* !Description : This public service disables the continuous mode and enables the sequential mode on crankshaft      */
/*                synchronization event.                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidCrkSyncFoundEntry(void)
{
   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuINIT_STATE:
      case PMPHAL_enuDISABLED:
      case PMPHAL_enuEVENT_ON_CMD_ON:
      case PMPHAL_enuEVENT_ON_CMD_OFF:
         break;

      case PMPHAL_enuEVENT_OFF_CMD_ON:
         PMPHAL_enuComponentStatus = PMPHAL_enuEVENT_ON_CMD_ON;
         PMPHAL_vidENABLE_SEQUENTIAL_MODE();
         break;

      case PMPHAL_enuEVENT_OFF_CMD_OFF:
         PMPHAL_enuComponentStatus = PMPHAL_enuEVENT_ON_CMD_OFF;
         PMPHAL_vidENABLE_SEQUENTIAL_MODE();
         break;

      default:
         PMPHAL_vidDisable();
#ifdef PROFILES_MGMT_ON
         PMPHAL_u8CmdPulseProfileId = PMPHAL_u8DEFAULT_PROFILE;

         PMPHAL_vidCfgSwitchCmdProfile(PMPHAL_u8CMD_PULSE_ID, &PMPHAL_udtProfileSwitchRqstStatus);
#endif
         SWFAIL_vidSoftwareErrorHook();
      }
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidCrkSyncLostEntry                                                                          */
/* !Description : This public service disables the sequential mode and enables the continuous mode on crankshaft      */
/*                desynchronization event.                                                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidCrkSyncLostEntry(void)
{
/* !Comment: All ITs shall be disabled before reinitializing the component,   */
/*           So, the 3 following functions are called into a protected section*/
/*           even if the interrupts are disabled into the next macros.        */
   SchM_Enter_PMPHAL_ACCESS_002();
   CRKHAL_vidDisableAlarmNotif(PMPHAL_u8CRKHAL_SPILL_CMD_CH);
   CRKHAL_vidDisableAlarmNotif(PMPHAL_u8CRKHAL_SPILL_EVENT_CH);
   Gpt_StopTimer(PMPHAL_snGPT_PMP_DELAY_CH);
   Gpt_DisableNotification(PMPHAL_snGPT_PMP_DELAY_CH);
   SchM_Exit_PMPHAL_ACCESS_002();

   PMPHAL_bFirstSpillEventOk = FALSE;

   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuINIT_STATE:
      case PMPHAL_enuDISABLED:
         break;

      case PMPHAL_enuEVENT_ON_CMD_OFF:
         PMPHAL_enuComponentStatus  = PMPHAL_enuEVENT_OFF_CMD_OFF;
         PMPHAL_vidENABLE_CONTINUOUS_MODE();
#ifdef PROFILES_MGMT_ON
         PMPHAL_u8CmdPulseProfileId = PMPHAL_u8DEFAULT_PROFILE;

         PMPHAL_vidCfgSwitchCmdProfile(PMPHAL_u8CMD_PULSE_ID, &PMPHAL_udtProfileSwitchRqstStatus);
#endif
         break;

      case PMPHAL_enuEVENT_ON_CMD_ON:
         PMPHAL_enuComponentStatus  = PMPHAL_enuEVENT_OFF_CMD_ON;
         PMPHAL_vidENABLE_CONTINUOUS_MODE();
#ifdef PROFILES_MGMT_ON
         PMPHAL_u8CmdPulseProfileId = PMPHAL_u8DEFAULT_PROFILE;

         PMPHAL_vidCfgSwitchCmdProfile(PMPHAL_u8CMD_PULSE_ID, &PMPHAL_udtProfileSwitchRqstStatus);
#endif
         break;

      case PMPHAL_enuEVENT_OFF_CMD_OFF:
      case PMPHAL_enuEVENT_OFF_CMD_ON:
      default:
         PMPHAL_vidDisable();
         SWFAIL_vidSoftwareErrorHook();
   }
}


#define PMPHAL_STOP_SEC_CODE
#include "PMPHAL_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
