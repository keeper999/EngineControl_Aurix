/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : LBHOT                                                   */
/* !Description     : Oxygen (Lambda) Sensor Heating management               */
/*                                                                            */
/* !File            : LBHOT.c                                                 */
/* !Description     : LBHOT's APIs                                            */
/*                                                                            */
/* !Reference       : V03 NT 06 03885                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A36803.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "SWFAIL.h"
#include "LBHOT.h"
#include "LBHOT_I.h"
#include "LBHOT_Cfg.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/

#define LBHOT_START_SEC_CODE
#include "LBHOT_MemMap.h"

/******************************************************************************/
/* !FuncName    : LBHOT_vidInit                                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M. Sabry                                                   */
/******************************************************************************/
void LBHOT_vidInit(void)
{
   LBHOT_udtPeriod = LBHOT_udtPeriod_MAX;
   LBHOT_u16DutyCycle = LBHOT_udtDuty_MIN;
   if (LBHOT_kbEnableLbupHotPwmMode == FALSE)
   {
      LBHOT_bLbupHotAppliCmd = LBHOT_READ_UPS_DIO();
   }
   LBHOT_bLbdwHotAppliCmd = LBHOT_READ_DWN_DIO();
}

/******************************************************************************/
/* !FuncName    : LBHOT_vidWriteLbupHotState                                  */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M. Sabry                                                   */
/******************************************************************************/
void LBHOT_vidWriteLbupHotState
(
   boolean bState
)
{
   if (LBHOT_kbEnableLbupHotPwmMode == FALSE)
   {
      LBHOT_WRITE_UPS_DIO(bState);
      LBHOT_bLbupHotAppliCmd = bState;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : LBHOT_vidWriteLbdwHotState                                  */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M.ElShamaa                                                 */
/******************************************************************************/
void LBHOT_vidWriteLbdwHotState
(
   boolean bState
)
{
   LBHOT_WRITE_DWN_DIO(bState);
   LBHOT_bLbdwHotAppliCmd = bState;
}

/******************************************************************************/
/* !FuncName    : LBHOT_bReadRawLbupHotState                                  */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M. Sabry                                                   */
/******************************************************************************/
boolean LBHOT_bReadRawLbupHotState(void)
{
   boolean bLocalState;

   if (LBHOT_kbEnableLbupHotPwmMode == FALSE)
   {
      bLocalState = LBHOT_READ_UPS_DIO();
   }
   else
   {
      bLocalState = STD_OFF;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(bLocalState);
}

/******************************************************************************/
/* !FuncName    : LBHOT_bReadRawLbdwHotState                                  */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
boolean LBHOT_bReadRawLbdwHotState(void)
{
   boolean bLocalState;

   bLocalState = LBHOT_READ_DWN_DIO();
   return(bLocalState);
}

/******************************************************************************/
/* !FuncName    : LBHOT_vidSetFrequency                                       */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M. Sabry                                                   */
/******************************************************************************/
void LBHOT_vidSetPeriodAndDuty
(
   uint8  u8ChannelId,
   uint16 u16Period,
   uint16 u16DutyCycle
)
{
   if (LBHOT_kbEnableLbupHotPwmMode != FALSE)
   {
      if (u16Period > (uint16)LBHOT_udtPeriod_MAX)
      {
         LBHOT_udtPeriod = LBHOT_udtPeriod_MAX;
      }
      else
      {
         LBHOT_udtPeriod = u16Period;
      }

      LBHOT_u16DutyCycle = u16DutyCycle;

      LBHOT_SET_PER_DUTY_UPS_PWM(u8ChannelId, LBHOT_udtPeriod, LBHOT_u16DutyCycle);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : LBHOT_vidSetDutyCycle                                       */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M. Sabry                                                   */
/******************************************************************************/
void LBHOT_vidSetDutyCycle
(
   uint8  u8ChannelId,
   uint16 u16DutyCycle
)
{
   if (LBHOT_kbEnableLbupHotPwmMode != FALSE)
   {
      LBHOT_u16DutyCycle = u16DutyCycle;
      LBHOT_SET_DUTY_UPS_PWM(u8ChannelId, LBHOT_u16DutyCycle);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : LBHOT_vidSetUpPwmOutputToIdle                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M. Sabry                                                   */
/******************************************************************************/
void LBHOT_vidSetUpPwmOutputToIdle
(
   uint8  u8ChannelId
)
{

   if (LBHOT_kbEnableLbupHotPwmMode != FALSE)
   {
      LBHOT_SET_OUTPUT_IDLE_UPS_PWM(u8ChannelId);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : LBHOT_vidUpCmdStop                                          */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M. Sabry                                                   */
/******************************************************************************/
void LBHOT_vidUpCmdStop(void)
{

   if (LBHOT_kbEnableLbupHotPwmMode != FALSE)
   {
      LBHOT_vidSetUpPwmOutputToIdle(LBHOT_udtUPS_CMD_PWM_CH);
   }
   else
   {
      LBHOT_WRITE_UPS_DIO(LBHOT_bUPS_CMD_IDLE_LEVEL);
   }
}

/******************************************************************************/
/* !FuncName    : LBHOT_vidUpCmdRestart                                       */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  :  M. Sabry                                                   */
/******************************************************************************/
void LBHOT_vidUpCmdRestart(void)
{
   if (LBHOT_kbEnableLbupHotPwmMode != FALSE)
   {
      LBHOT_SET_DUTY_UPS_PWM(LBHOT_udtUPS_CMD_PWM_CH, LBHOT_u16DutyCycle);
   }
   else
   {
      LBHOT_vidWriteLbupHotState(LBHOT_bLbupHotAppliCmd);
   }
}

#define LBHOT_STOP_SEC_CODE
#include "LBHOT_MemMap.h"


/*------------------------------- end of file --------------------------------*/
