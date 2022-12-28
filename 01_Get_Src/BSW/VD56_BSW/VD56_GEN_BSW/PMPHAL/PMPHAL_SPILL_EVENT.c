/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_SPILL_EVENT.c                                                                            */
/* !Description     : Management Spill Event                                                                          */
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
 * %PID: P2017_BSW:0A189067.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"

#include "PMPHAL.h"
#include "PMPHAL_I.h"
#include "PMPHAL_L.h"

#include "CRKHAL.h"
#include "SWFAIL.h"
#include "TSKSRV.h"

/**********************************************************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                                                         */
/**********************************************************************************************************************/

#define PMPHAL_START_SEC_CODE
#include "PMPHAL_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidSpillEventManager                                                                         */
/* !Description : Management of spill event                                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidSpillEventManager(void)
{
   PMPHAL_u16PrevSpillEventAngle = PMPHAL_u16NextSpillEventAngle;

   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuEVENT_ON_CMD_ON:
      case PMPHAL_enuEVENT_ON_CMD_OFF:
         PMPHAL_u8SpillEventCounter = (uint8)((PMPHAL_u8SpillEventCounter + 1u) % PMPHAL_u8NbSpillEventsRqstd);

         PMPHAL_u16NextSpillEventAngle = (uint16)((PMPHAL_u8SpillEventCounter * PMPHAL_u16InterSpillEventAngle)
                                       + PMPHAL_u16SpillEventAngleRqstd);

         CRKHAL_vidSetAbsAlarm(PMPHAL_u8CRKHAL_SPILL_EVENT_CH, PMPHAL_u16NextSpillEventAngle);
         break;

      case PMPHAL_enuEVENT_OFF_CMD_ON:
      case PMPHAL_enuEVENT_OFF_CMD_OFF:
      case PMPHAL_enuINIT_STATE:
      case PMPHAL_enuDISABLED:
      default:
         SWFAIL_vidSoftwareErrorHook();
   }

   TSKSRV_vidActivateTask(PMPHAL_SPILL_EVENT);
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidSpillEventNotification                                                                    */
/* !Description : Manages the actions to be taken on spill event angle match                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidSpillEventNotification(void)
{
   if (PMPHAL_bFirstSpillEventOk == FALSE)
   {
      PMPHAL_bFirstSpillEventOk = TRUE;

      PMPHAL_vidFIRST_SPILL_EVENT();
   }
   PMPHAL_vidSpillEventCallBack();
}


#define PMPHAL_STOP_SEC_CODE
#include "PMPHAL_MemMap.h"

/*--------------------------------------------------- end of file ----------------------------------------------------*/
