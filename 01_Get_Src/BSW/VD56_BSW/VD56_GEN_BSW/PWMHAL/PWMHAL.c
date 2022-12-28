/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : HAL                                                                                             */
/*                                                                                                                    */
/* !Component       : PWMHAL                                                                                          */
/* !Description     : Pulse Width Modulation Hardware Abstraction Layer.                                              */
/*                                                                                                                    */
/* !Module          : PWMHAL                                                                                          */
/* !Description     : Pulse Width Modulation Hardware Abstraction Layer.                                              */
/*                                                                                                                    */
/* !File            : PWMHAL.C                                                                                        */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* 1 / PWMHAL_vidInit                                                                                                 */
/* 2 / PWMHAL_udtWriteDutyCycle                                                                                       */
/* 3 / PWMHAL_udtWriteFrequency                                                                                       */
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A371.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/



#include "Std_Limits.h"
#include "Std_Types.h"
#include "SWFAIL.h"

#include "PWMHAL.h"
#include "PWMHAL_Cfg.h"
#include "PWMHAL_Co.h"
#include "PWMHAL_Def.h"
#include "PWMHAL_Types.h"


/**********************************************************************************************************************/
/* Check that Conditionnal Compilation define are defined                                                             */
/**********************************************************************************************************************/
#ifndef PWMHAL_coHOD_CHANNEL_EXIST
   #error "Define PWMHAL_coHOD_CHANNEL_EXIST is undefined"
#endif

#ifndef PWMHAL_coPWM_CHANNEL_EXIST
   #error "Define PWMHAL_coPWM_CHANNEL_EXIST is undefined"
#endif

#ifndef PWMHAL_coSPECIFIC_CHANNEL_EXIST
   #error "Define PWMHAL_coSPECIFIC_CHANNEL_EXIST is undefined"
#endif

#ifndef PWMHAL_coSINGLE_LOWER_LAYER
   #error "Define PWMHAL_coSINGLE_LOWER_LAYER is undefined"
#endif

#ifndef PWMHAL_coYES
   #error "Define PWMHAL_coYES is undefined"
#endif

#if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
   #include "Hod.h"
#endif

#if PWMHAL_coPWM_CHANNEL_EXIST == PWMHAL_coYES
   #include "Pwm.h"
#endif

#define PWMHAL_START_SEC_VAR_16BIT
#include "PWMHAL_MemMap.h"

STATIC uint16 PWMHAL_au16Period[PWMHAL_u8NB_CHANNEL];
STATIC uint16 PWMHAL_au16DutyCycle[PWMHAL_u8NB_CHANNEL];

#define PWMHAL_STOP_SEC_VAR_16BIT
#include "PWMHAL_MemMap.h"

#define PWMHAL_START_SEC_CODE
#include "PWMHAL_MemMap.h"

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : PWMHAL_vidInit                                                                                      */
/*                                                                                                                    */
/* !Description : Initialization of PWMHAL internal variables and commanding of PWM output using initial settings     */
/* !Number      : 0x00                                                                                                */
/* !Reference   : PTS_DOC_5139092 / 1                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : PTS_R_5139092_003                                                                                   */
/* !Trace_To    : PTS_R_5139092_004                                                                                   */
/* !Trace_To    : PTS_R_5139092_005                                                                                   */
/* !Trace_To    : PTS_R_5139092_006                                                                                   */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Task     : PWMHAL_vidInit                                                                                         */
/* !Trigger  : INIT                                                                                                   */
/* !Runnable : PWMHAL_vidInit                                                                                         */
/*                                                                                                                    */
/* !LastAuthor  :  M.ELShamaa                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
void PWMHAL_vidInit(void)
{
   uint8 u8LocalIndex;


   for (u8LocalIndex = 0;
        u8LocalIndex < PWMHAL_u8NB_CHANNEL;
        u8LocalIndex++)
   {
      PWMHAL_au16Period[u8LocalIndex] = 0;
      PWMHAL_au16DutyCycle[u8LocalIndex] = 0;
   }
}


/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : PWMHAL_udtWriteDutyCycle                                                                            */
/*                                                                                                                    */
/* !Description : Set duty cycle to the value set by upper layer.                                                     */
/* !Number      : 0x01                                                                                                */
/* !Reference   : PTS_DOC_5139092 / 1                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : PTS_R_5139092_007                                                                                   */
/* !Trace_To    : PTS_R_5139092_008                                                                                   */
/* !Trace_To    : PTS_R_5139092_012                                                                                   */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Task     : PWMHAL_udtWriteDutyCycle                                                                               */
/* !Trigger  : NONE                                                                                                   */
/* !Runnable : PWMHAL_udtWriteDutyCycle                                                                               */
/*                                                                                                                    */
/* !LastAuthor  :  M.ELShamaa                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
Std_ReturnType PWMHAL_udtWriteDutyCycle
(
   PWMHAL_tudtChannel udtChannel,
   PWMHAL_tudtDutyCycle udtDutyCycle
)
{
   Std_ReturnType udtLocalRet;
   uint8          u8LocalChannelId;
   #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
   uint8          u8LocalHodInstance;
   #endif
   const PWMHAL_tstrConfig *pudtLocalConfig;


   udtLocalRet = E_NOT_OK;

   if(udtChannel < PWMHAL_u8NB_CHANNEL)
   {
      pudtLocalConfig = &PWMHAL_akudtConfig[udtChannel];

      if(udtDutyCycle <= 32768)
      {
         PWMHAL_au16DutyCycle[udtChannel] = (uint16)udtDutyCycle;
         udtLocalRet = E_OK;
      }
      else
      {
         PWMHAL_au16DutyCycle[udtChannel] = 32768;
      }

      u8LocalChannelId = (uint8)(pudtLocalConfig->u16ChannelId);

      #if PWMHAL_coSINGLE_LOWER_LAYER == PWMHAL_coYES
         #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
         u8LocalHodInstance = (uint8)(pudtLocalConfig->u16ChannelId >> 8);

         pudtLocalConfig->kpfvidHodWrDuty((HOD_tudtInstance)u8LocalHodInstance,
                                          (HOD_tudtChannel)u8LocalChannelId,
                                          (HOD_tudtDutycycle)PWMHAL_au16DutyCycle[udtChannel]);
         #endif
         #if PWMHAL_coPWM_CHANNEL_EXIST == PWMHAL_coYES
         Pwm_SetDutyCycle((Pwm_ChannelType)u8LocalChannelId,
                          PWMHAL_au16DutyCycle[udtChannel]);
         #endif
         #if PWMHAL_coSPECIFIC_CHANNEL_EXIST == PWMHAL_coYES
         pudtLocalConfig->kpfvidSpecificWrDuty(u8LocalChannelId,
                                               PWMHAL_au16DutyCycle[udtChannel]);
         #endif
      #else
      switch(pudtLocalConfig->u8LinkType)
      {
         #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
         case PWMHAL_u8HOD_LINK:
            u8LocalHodInstance = (uint8)(pudtLocalConfig->u16ChannelId >> 8);

            pudtLocalConfig->kpfvidHodWrDuty((HOD_tudtInstance)u8LocalHodInstance,
                                             (HOD_tudtChannel)u8LocalChannelId,
                                             (HOD_tudtDutycycle)PWMHAL_au16DutyCycle[udtChannel]);
         break;
         #endif
         #if PWMHAL_coPWM_CHANNEL_EXIST == PWMHAL_coYES
         case PWMHAL_u8PWM_LINK:
            Pwm_SetDutyCycle((Pwm_ChannelType)u8LocalChannelId,
                             PWMHAL_au16DutyCycle[udtChannel]);
         break;
         #endif
         #if PWMHAL_coSPECIFIC_CHANNEL_EXIST == PWMHAL_coYES
         case PWMHAL_u8SPECIFIC_LINK:
            pudtLocalConfig->kpfvidSpecificWrDuty(u8LocalChannelId,
                                                  PWMHAL_au16DutyCycle[udtChannel]);
         break;
         #endif
         default:
         SWFAIL_vidSoftwareErrorHook();
         break;
      }
      #endif
   }
   if (udtLocalRet != E_OK)
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   return udtLocalRet;
}


/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : PWMHAL_udtWriteFrequency                                                                            */
/*                                                                                                                    */
/* !Description : Set frequency to the value set by upper layer.                                                      */
/* !Number      : 0x02                                                                                                */
/* !Reference   : PTS_DOC_5139092 / 1                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : PTS_R_5139092_009                                                                                   */
/* !Trace_To    : PTS_R_5139092_010                                                                                   */
/* !Trace_To    : PTS_R_5139092_011                                                                                   */
/* !Trace_To    : PTS_R_5139092_013                                                                                   */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Task     : PWMHAL_udtWriteFrequency                                                                               */
/* !Trigger  : NONE                                                                                                   */
/* !Runnable : PWMHAL_udtWriteFrequency                                                                               */
/*                                                                                                                    */
/* !LastAuthor  :  M.ELShamaa                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
Std_ReturnType PWMHAL_udtWriteFrequency
(
   PWMHAL_tudtChannel udtChannel,
   PWMHAL_tudtFrequency udtFrequency
)
{
   Std_ReturnType udtLocalRet;
   uint8          u8LocalChannelId;
   #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
   uint8          u8LocalHodInstance;
   #endif
   const PWMHAL_tstrConfig *pudtLocalConfig;


   udtLocalRet = E_OK;

   if(udtChannel < PWMHAL_u8NB_CHANNEL)
   {
      pudtLocalConfig = &PWMHAL_akudtConfig[udtChannel];
      u8LocalChannelId = (uint8)(pudtLocalConfig->u16ChannelId);
      #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
      u8LocalHodInstance = (uint8)(pudtLocalConfig->u16ChannelId >> 8);
      #endif

      if (udtFrequency == 0)
      {
         #if PWMHAL_coSINGLE_LOWER_LAYER == PWMHAL_coYES
            #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
            pudtLocalConfig->kpfvidHodSetOutputToIdle((HOD_tudtInstance)u8LocalHodInstance,
                                                      (HOD_tudtChannel)u8LocalChannelId);
            #endif
            #if PWMHAL_coPWM_CHANNEL_EXIST == PWMHAL_coYES
            Pwm_SetOutputToIdle((Pwm_ChannelType)u8LocalChannelId);
            #endif
            #if PWMHAL_coSPECIFIC_CHANNEL_EXIST == PWMHAL_coYES
            pudtLocalConfig->kpfvidSpecificSetOutputToIdle(u8LocalChannelId);
            #endif
         #else
         switch(pudtLocalConfig->u8LinkType)
         {
            #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
            case PWMHAL_u8HOD_LINK:
               pudtLocalConfig->kpfvidHodSetOutputToIdle((HOD_tudtInstance)u8LocalHodInstance,
                                                         (HOD_tudtChannel)u8LocalChannelId);
               break;
            #endif
            #if PWMHAL_coPWM_CHANNEL_EXIST == PWMHAL_coYES
            case PWMHAL_u8PWM_LINK:
               Pwm_SetOutputToIdle((Pwm_ChannelType)u8LocalChannelId);
               break;
            #endif
            #if PWMHAL_coSPECIFIC_CHANNEL_EXIST == PWMHAL_coYES
            case PWMHAL_u8SPECIFIC_LINK:
               pudtLocalConfig->kpfvidSpecificSetOutputToIdle(u8LocalChannelId);
               break;
            #endif
            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         #endif
      }
      else
      {
         if (udtFrequency <= (pudtLocalConfig->udtMinFreq))
         {
            PWMHAL_au16Period[udtChannel] = 65535;
            udtLocalRet = E_NOT_OK;
         }
         else
         {
            PWMHAL_au16Period[udtChannel] = (uint16)((pudtLocalConfig->u32FreqToPer) / udtFrequency);
         }

         #if PWMHAL_coSINGLE_LOWER_LAYER == PWMHAL_coYES
            #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
            pudtLocalConfig->kpfvidHodWrPeriodDuty((HOD_tudtInstance)u8LocalHodInstance,
                                                   (HOD_tudtChannel)u8LocalChannelId,
                                                   (HOD_tudtPeriod)PWMHAL_au16Period[udtChannel],
                                                   (HOD_tudtDutycycle)PWMHAL_au16DutyCycle[udtChannel]);
            #endif
            #if PWMHAL_coPWM_CHANNEL_EXIST == PWMHAL_coYES
            Pwm_SetPeriodAndDuty((Pwm_ChannelType)u8LocalChannelId,
                                 (Pwm_PeriodType)PWMHAL_au16Period[udtChannel],
                                 PWMHAL_au16DutyCycle[udtChannel]);
            #endif
            #if PWMHAL_coSPECIFIC_CHANNEL_EXIST == PWMHAL_coYES
            pudtLocalConfig->kpfvidSpecificWrPeriodDuty(u8LocalChannelId,
                                                        PWMHAL_au16Period[udtChannel],
                                                        PWMHAL_au16DutyCycle[udtChannel]);
            #endif
         #else
         switch(pudtLocalConfig->u8LinkType)
         {
            #if PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
            case PWMHAL_u8HOD_LINK:
               pudtLocalConfig->kpfvidHodWrPeriodDuty((HOD_tudtInstance)u8LocalHodInstance,
                                                      (HOD_tudtChannel)u8LocalChannelId,
                                                      (HOD_tudtPeriod)PWMHAL_au16Period[udtChannel],
                                                      (HOD_tudtDutycycle)PWMHAL_au16DutyCycle[udtChannel]);
            break;
            #endif
            #if PWMHAL_coPWM_CHANNEL_EXIST == PWMHAL_coYES
            case PWMHAL_u8PWM_LINK:
               Pwm_SetPeriodAndDuty((Pwm_ChannelType)u8LocalChannelId,
                                    (Pwm_PeriodType)PWMHAL_au16Period[udtChannel],
                                    PWMHAL_au16DutyCycle[udtChannel]);
               break;
            #endif
            #if PWMHAL_coSPECIFIC_CHANNEL_EXIST == PWMHAL_coYES
            case PWMHAL_u8SPECIFIC_LINK:
               pudtLocalConfig->kpfvidSpecificWrPeriodDuty(u8LocalChannelId,
                                                           PWMHAL_au16Period[udtChannel],
                                                           PWMHAL_au16DutyCycle[udtChannel]);
               break;
            #endif
            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         #endif
      }
   }
   else
   {
      udtLocalRet = E_NOT_OK;
   }

   if (udtLocalRet != E_OK)
   {
      SWFAIL_vidSoftwareErrorHook();
   }
   return udtLocalRet;
}


#define PWMHAL_STOP_SEC_CODE
#include "PWMHAL_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
