/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PRSHAL                                                  */
/* !Description     : PRSHAL Component                                        */
/*                                                                            */
/* !File            : PRSHAL_API.c                                            */
/* !Description     : APIs of PRSHAL Component                                */
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
 * %PID: P2017_BSW:A245.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CRKHAL.h"
#include "PRSHAL_Cfg.h"
#include "TDCHAL.h"
#include "PRSHAL.h"

#define PRSHAL_START_SEC_CODE
#include "PRSHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : PRSHAL_vidInit                                              */
/* !Description : Initialization of PRSHAL component                          */
/*                                                                            */
/* !LastAuthor  : mkhalaf-allah                                               */
/******************************************************************************/
void PRSHAL_vidInit(void)
{
   uint8 u8LocalTemp;
   uint16 u16LocalTemp;
   Std_ReturnType udtLocalStatus;

   CRKHAL_vidActivateAlarmMode(PRSHAL_u8CRKHAL_CHANNEL, MODE_NO_ACTION);
   udtLocalStatus = TDCHAL_udtReadRawCounter(&u8LocalTemp);
   if (udtLocalStatus != E_NOT_OK)
   {
      u16LocalTemp = PRSHAL_u16OFFSET + (((uint16)u8LocalTemp) * 
TDCHAL_u16TDC_OFFSET);
      CRKHAL_vidSetAbsAlarm(PRSHAL_u8CRKHAL_CHANNEL, u16LocalTemp);
      CRKHAL_vidEnableAlarmNotif(PRSHAL_u8CRKHAL_CHANNEL);
   }
}

/******************************************************************************/
/* !FuncName    : PRSHAL_vidDeInit                                            */
/* !Description : De-initialization of PRSHAL component                       */
/*                                                                            */
/* !LastAuthor  : mkhalaf-allah                                               */
/******************************************************************************/
void PRSHAL_vidDeInit(void)
{

   CRKHAL_vidDisableAlarmNotif(PRSHAL_u8CRKHAL_CHANNEL);
   CRKHAL_vidDeactivateAlarmMode(PRSHAL_u8CRKHAL_CHANNEL);
}

/******************************************************************************/
/* !FuncName    : PRSHAL_vidInterrupt                                         */
/* !Description : Angular alarm of PRSHAL component                           */
/*                                                                            */
/* !LastAuthor  : H. Saidi                                                    */
/******************************************************************************/
void PRSHAL_vidInterrupt(void)
{
   uint16 u16LocalCurrentCounter;

   PRSHAL_vidUPDATE_PRESSURE_HOOK();
   u16LocalCurrentCounter = CRKHAL_u16ReadCounter(PRSHAL_u8CRKHAL_CHANNEL);
   if (((sint32)u16LocalCurrentCounter) < (CRKHAL_u16ENGINE_CYCLE - ((
PRSHAL_u16ERR_ADJUST_FACTOR_N * PRSHAL_u16OFFSET) / 
PRSHAL_u16ERR_ADJUST_FACTOR_D)))
   {
      CRKHAL_vidSetRelAlarm(PRSHAL_u8CRKHAL_CHANNEL, PRSHAL_u16OFFSET);
   }
   else
   {
      CRKHAL_vidSetAbsAlarm(PRSHAL_u8CRKHAL_CHANNEL, UINT16_MIN);
   }
   PRSHAL_vidACTIVATE_TASK();
}

#define PRSHAL_STOP_SEC_CODE
#include "PRSHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
