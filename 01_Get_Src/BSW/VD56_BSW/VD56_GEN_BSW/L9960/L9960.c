/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960.c                                                                                         */
/* !Description     : Main file                                                                                       */
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
 * %PID: LIBEMB:A6072.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Pwm.h"
#include "L9960.h"
#include "L9960_Private.h"
#include "L9960_SpiM.h"
#include "L9960_Spi.h"
#include "L9960_Types.h"
#include "L9960_Cfg.h"
#include "HBHAL.h"


#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidInit                                                                                       */
/* !Description : Initialize all internal variables                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidInit(void)
{
   uint8_least u8LocChannel;

   L9960_strData *pLocStrData;

   for (u8LocChannel = 0; u8LocChannel < L9960_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData = &L9960_astrData[u8LocChannel];

      /*************************************************/
      /* reset all data                                */
      /*************************************************/
      L9960_vidSpiM_Init(&L9960_akstrConfig[u8LocChannel], pLocStrData);
      L9960_vidSpiInit(&L9960_akstrConfig[u8LocChannel], pLocStrData);
      
      pLocStrData->enuHBridgeState = L9960_STATE_HWSC_START;
      pLocStrData->bEnableSetpoint = FALSE; /* Don't enable H bridge until L9960_vidEnable call */
      
      pLocStrData->u16LastRequestedDirDutyCycle = 0;   /* Duty Cycle = 0% */
      pLocStrData->u16LastRequestedPwmDutyCycle = 0;   /* Duty Cycle = 0% */
      
      /* We are not entering in tristate mode, so timer is disable      */
      /* And it is not allowed to leave tristate mode (safety position) */
      pLocStrData->u8TristateModeTimer       = 0;
      pLocStrData->bLeaveTristateModeAllowed = FALSE;
      
      pLocStrData->u8RegisterCheckCounter    = 0; /* Don t care as it is initialized before each use */
      pLocStrData->u8RegisterInitCounter     = L9960_u8REGISTER_INIT_NUMBER_OF_TRY;

      /* By default, diag are not done */
      pLocStrData->bOnDiagnosticIsAvailable  = FALSE;
      pLocStrData->bOffDiagnosticIsAvailable = FALSE;
      
      /* HW Self check not yet passed */
      pLocStrData->bHWSCPassed = FALSE;
      
      /* By default, we have no reported fault */
      pLocStrData->bSupplyVoltageFault      = FALSE;
      pLocStrData->bILimitFault             = FALSE;
      pLocStrData->bOverCurrentFault        = FALSE;
      pLocStrData->bOffDiagOverCurrentFault = FALSE;
      pLocStrData->bOverLoadFault           = FALSE;
      pLocStrData->bOverTemperatureFault    = FALSE;
      pLocStrData->bOpenLoadLastState       = FALSE;
      pLocStrData->bOpenLoadDiagDone        = FALSE;
      pLocStrData->bOffDiagOpenLoadFault    = FALSE;
      pLocStrData->bCCFault                 = FALSE;
      pLocStrData->bHwscNotDoneFault        = FALSE;
      pLocStrData->bNDISPinFault            = FALSE;
      pLocStrData->bHBridgeDisableFault     = TRUE;  /* The bridge is disable on reset */
      pLocStrData->bNgFailFault             = FALSE; /* NGFAIL=0 => no fault */
   }

      /* TODO: The PWM notification is not handled, so OIL configuration is not taken into account */
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidEnable                                                                                     */
/* !Description : Enable the L9960 chip by seting to low the DIS pin                                                  */
/*                We enable the chip only when its register as well configured                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidEnable(uint8 u8Channel)
{
   L9960_strData *pLocStrData;



   /************************************************************************************************/
   /* Errors checking                                                                              */
   /************************************************************************************************/
   if (u8Channel >= L9960_u8NB_OF_DEVICE)
   {
      SWFAIL_vidSoftwareErrorHook();
      return;
   }
   /************************************************************************************************/
   /* End of Errors checking                                                                       */
   /************************************************************************************************/

   pLocStrData = &L9960_astrData[u8Channel];

   pLocStrData->bEnableSetpoint = TRUE;

   /* If not DISABLE, the enable will be done after the init */ 
   /* If L9960_STATE_HW_FAILURE, the enable is not allowed   */ 
   if(pLocStrData->enuHBridgeState == L9960_STATE_DISABLE)
   {
      L9960_vidEnterInEnableState(&L9960_akstrConfig[u8Channel], pLocStrData);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidDisable                                                                                    */
/* !Description : Enable the L9960 chip by seting to low the DIS pin                                                  */
/*                We enable the chip only when its registers are well configured                                      */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidDisable(uint8 u8Channel)
{
   L9960_strData    *pLocStrData;
   L9960_tstrConfig const * pkstrLocConfig;


   /************************************************************************************************/
   /* Errors checking                                                                              */
   /************************************************************************************************/
   if (u8Channel >= L9960_u8NB_OF_DEVICE)
   {
      SWFAIL_vidSoftwareErrorHook();
      return;
   }
   /************************************************************************************************/
   /* End of Errors checking                                                                       */
   /************************************************************************************************/
   pLocStrData = &L9960_astrData[u8Channel];

   pLocStrData->bEnableSetpoint = FALSE;

   if(pLocStrData->enuHBridgeState == L9960_STATE_ENABLE)
   {
      pkstrLocConfig = &L9960_akstrConfig[u8Channel];
      /* We pass through a callout, because the DIS pin must be handled by a safety component for the throtle */
      pkstrLocConfig->pfvidSetDisPinToHigh();
   
      /* We don't set output to idle, to still have Pwm interrupts                                */
      /* For HW, it is not needed to cut DIS and PWM, but to have a nice re-enable without glitch */
      /* we need to set pwm duty cycle to 0%                                                      */
      Pwm_SetDutyCycle(pkstrLocConfig->udtDirChannel, 0);
      Pwm_SetDutyCycle(pkstrLocConfig->udtPwmChannel, 0);
      pLocStrData->enuHBridgeState = L9960_STATE_DISABLE;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidWrite                                                                                      */
/* !Description : It is expected that this function is not called under ISR (no shared data protection)               */
/*                It is expected that no pwm end of period occurs during execution of this function to have           */
/*                consistent duty cycle on PWM and DIS pin                                                            */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidWrite(uint8  u8Channel,
                    sint32 s32SetPoint)
{
   uint16          u16LocDIRDutyCycle;
   Pwm_ChannelType udtLocPWMOutputChannel;
   Pwm_ChannelType udtLocDIROutputChannel;


   /************************************************************************************************/
   /* Errors checking                                                                              */
   /************************************************************************************************/
   if (u8Channel >= L9960_u8NB_OF_DEVICE)
   {
      SWFAIL_vidSoftwareErrorHook();
      return;
   }
   
   if(L9960_astrData[u8Channel].enuHBridgeState == L9960_STATE_HW_FAILURE)
   {
      /* bridge in HW failure means that it keeps disable until next reset, and so all commands are ignored */ 
      return;
   }
   /************************************************************************************************/
   /* End of Errors checking                                                                       */
   /************************************************************************************************/


   /* Even if Pwm Driver do a clamp, Duty Cycle must be tested in this level because of the (uint16) cast */
   /* Which may result to a wrap-around, and so a set point corruption.                                   */
   if (s32SetPoint > L9960_MAX_DUTY_CYCLE)
   {
      /* Duty Cycle out of range */
      s32SetPoint        = L9960_MAX_DUTY_CYCLE;
      u16LocDIRDutyCycle = L9960_FORWARD_DIR_DUTYCYCLE;
   }
   else if (s32SetPoint < L9960_MIN_DUTY_CYCLE)
   {
      /* Duty Cycle out of range in reverse mode: set PWM to max, and DIR to reverse direction */
      s32SetPoint        = L9960_MAX_DUTY_CYCLE;
      u16LocDIRDutyCycle = L9960_REVERSE_DIR_DUTYCYCLE;
   }
   else if (s32SetPoint < 0)
   {
      /* Duty Cycle is in range and negative : reverse mode */
      s32SetPoint        = -s32SetPoint;
      u16LocDIRDutyCycle = L9960_REVERSE_DIR_DUTYCYCLE;
   }
   else
   {
      /* Duty Cycle is in range and positive : normal mode, s32SetPoint ahs already the good value */
      u16LocDIRDutyCycle = L9960_FORWARD_DIR_DUTYCYCLE;
   }


   /* we apply the pwm only when H Bridge is enable */
   /* because, to prevent any glitch, we must have 0% duty cycle when transition disable->enable occurs */
   if (L9960_astrData[u8Channel].enuHBridgeState == L9960_STATE_ENABLE)
   {
      udtLocPWMOutputChannel = L9960_akstrConfig[u8Channel].udtPwmChannel;
      udtLocDIROutputChannel = L9960_akstrConfig[u8Channel].udtDirChannel;
      Pwm_SetDutyCycle(udtLocPWMOutputChannel, (uint16)s32SetPoint);
      Pwm_SetDutyCycle(udtLocDIROutputChannel, u16LocDIRDutyCycle);
   }

   L9960_astrData[u8Channel].u16LastRequestedDirDutyCycle = u16LocDIRDutyCycle;
   L9960_astrData[u8Channel].u16LastRequestedPwmDutyCycle = (uint16)s32SetPoint;

}


/**********************************************************************************************************************/
/* !FuncName    : L9960_enuReadStatus                                                                                 */
/* !Description : Return the status of the chip (tristate or running)                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
HBHAL_tenuStatus L9960_enuReadStatus(uint8 u8Channel)
{
   HBHAL_tenuStatus enuLocalReturnedStatus;

   enuLocalReturnedStatus = HBHAL_H_BRIDGE_DISABLED;

   if (u8Channel < L9960_u8NB_OF_DEVICE)
   {
      if(L9960_astrData[u8Channel].enuHBridgeState == L9960_STATE_ENABLE)
      {
         enuLocalReturnedStatus = HBHAL_H_BRIDGE_DISABLED;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   return(enuLocalReturnedStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidEnableNotification                                                                         */
/* !Description : Enable the notification on beginning of each PWM period.                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidEnableNotification(uint8 u8Channel)
{
   if (u8Channel < L9960_u8NB_OF_DEVICE)
   {
      /* bridge in HW failure means that it keeps disable until next reset, and so all command are ignored */ 
      if(L9960_astrData[u8Channel].enuHBridgeState != L9960_STATE_HW_FAILURE)
      {
         Pwm_EnableNotification(L9960_akstrConfig[u8Channel].udtPwmChannel, PWM_RISING_EDGE);
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidDisableNotification                                                                        */
/* !Description : Disable the notification on beginning of each PWM period.                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidDisableNotification(uint8 u8Channel)
{
   if (u8Channel < L9960_u8NB_OF_DEVICE)
   {
      /* bridge in HW failure means that it keeps disable until next reset, and so all command are ignored */ 
      if(L9960_astrData[u8Channel].enuHBridgeState != L9960_STATE_HW_FAILURE)
      {
         Pwm_DisableNotification(L9960_akstrConfig[u8Channel].udtPwmChannel);
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}


#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
