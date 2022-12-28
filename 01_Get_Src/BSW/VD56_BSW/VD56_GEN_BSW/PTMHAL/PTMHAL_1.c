/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PTMHAL                                                  */
/* !Description     : Precise Teeth Measurement HAL Service Layer             */
/*                                                                            */
/* !File            : PTMHAL_1.c                                              */
/* !Description     : General sub-functions of the PTMHAL Component           */
/*                                                                            */
/* !Reference       : V03 NT 11 07330 / 02                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A149688.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CRKHAL.h"
#include "PTMHAL_I.h"
#include "TSKSRV.h"
#include "SWFAIL.h"
#include "PTMHAL.h"
#include "PTMHAL_l.h"

#define PTMHAL_START_SEC_CODE
#include "PTMHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : PTMHAL_vidGeneralInitialization                             */
/* !Description : Initialization of PTMHAL component                          */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/
void PTMHAL_vidGeneralInitialization(void)
{
   uint8 Local_u8Index;


   PTMHAL_bEnabled               = FALSE;
   PTMHAL_u8CycleIndex           = UINT8_MIN;
   PTMHAL_bFirstCalculEvtOccured = FALSE;
   PTMHAL_u8NbDurationPacksValid = UINT8_MIN;

   for (Local_u8Index = UINT8_MIN; Local_u8Index < PTMHAL_u8MAX_NB_PACKS;
        Local_u8Index++)
   {
      PTMHAL_au32DurationPack[Local_u8Index] = UINT32_MIN;
   }
}

/******************************************************************************/
/* !FuncName    : PTMHAL_vidAlarmManagement                                   */
/* !Description : Manage the alarms                                           */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/
void PTMHAL_vidAlarmManagement(void)
{
   TSKSRV_vidActivateTask(PTMHAL_EVENT);
}

/******************************************************************************/
/* !FuncName    : PTMHAL_vidPacksDurationCalc                                 */
/* !Description : Calculate the duration packs                                */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/
void PTMHAL_vidPacksDurationCalc
(
   uint8 u8CallingConditions
)
{
   uint8 Local_u8Index;
   uint16 Local_u16NextAlarm;


   if (PTMHAL_bEnabled != FALSE)
   {
      switch (PTMHAL_ku16DurationsAlgo)
      {

         #ifndef PTMHAL_bPSA_3CYL_CFG_EN
         #error PTMHAL_bPSA_3CYL_CFG_EN not defined
         #elif (PTMHAL_bPSA_3CYL_CFG_EN)
         case PTMHAL_u16PSA_3CYL_CFG:
            if (u8CallingConditions == PTMHAL_u8PTMHAL_EVT_CALL)
            {
               PTMHAL_vidPSA3CylCfgManager();
            }
            else
            {
               SWFAIL_vidSoftwareErrorHook();
            }
            break;
         #endif /* ifndef PTMHAL_bPSA_3CYL_CFG_EN */

         #ifndef PTMHAL_bPSA_4CYL_CFG1_EN
         #error PTMHAL_bPSA_4CYL_CFG1_EN not defined
         #elif (PTMHAL_bPSA_4CYL_CFG1_EN)
         case PTMHAL_u16PSA_4CYL_CFG1:
            if (u8CallingConditions == PTMHAL_u8PTMHAL_EVT_CALL)
            {
               PTMHAL_vidPSA4CylCfg1Manager();
            }
            else
            {
               SWFAIL_vidSoftwareErrorHook();
            }
            break;
         #endif /* ifndef PTMHAL_bPSA_4CYL_CFG1_EN */

         #ifndef PTMHAL_bPSA_4CYL_CFG2_EN
         #error PTMHAL_bPSA_4CYL_CFG2_EN not defined
         #elif (PTMHAL_bPSA_4CYL_CFG2_EN)
         case PTMHAL_u16PSA_4CYL_CFG2:
            if (u8CallingConditions == PTMHAL_u8PTMHAL_EVT_CALL)
            {
               PTMHAL_vidPSA4CylCfg2Manager();
            }
            else
            {
               SWFAIL_vidSoftwareErrorHook();
            }
            break;
         #endif /* ifndef PTMHAL_bPSA_4CYL_CFG2_EN */

         #ifndef PTMHAL_bEVLV_CFG_EN
         #error PTMHAL_bEVLV_CFG_EN not defined
         #elif (PTMHAL_bEVLV_CFG_EN)
         case PTMHAL_u16EVLV_CFG:
            if (u8CallingConditions == PTMHAL_u8PTMHAL_EVT_CALL)
            {
               PTMHAL_vidEvlvCfgManager();
            }
            else
            {
               SWFAIL_vidSoftwareErrorHook();
            }
            break;
         #endif /* ifndef PTMHAL_bEVLV_CFG_EN */

         #ifndef PTMHAL_bRSA_3CYL_CFG_EN
         #error PTMHAL_bRSA_3CYL_CFG_EN not defined
         #elif (PTMHAL_bRSA_3CYL_CFG_EN)
         case PTMHAL_u16RSA_3CYL_CFG:
            PTMHAL_vidRSA3CylCfgManager(u8CallingConditions);
            break;
         #endif /* ifndef PTMHAL_bRSA_3CYL_CFG_EN */

         default:
            for (Local_u8Index = UINT8_MIN;
                 Local_u8Index < PTMHAL_u8MAX_NB_PACKS;
                 Local_u8Index++)
            {
               PTMHAL_au32DurationPack[Local_u8Index] = UINT32_MIN;
            }
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
      if (PTMHAL_u8CycleIndex >= (PTMHAL_ku8AlarmNbPerCycle - 1))
      {
         /* !Comment: End of Table -> Beginning of new round                  */
         PTMHAL_u8CycleIndex = UINT8_MIN;
      }
      else
      {
         PTMHAL_u8CycleIndex++;
      }

      /* !Comment: Program the next alarm                                     */
      Local_u16NextAlarm = PTMHAL_kau16AlarmAngle[PTMHAL_u8CycleIndex];
      CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_PTMHAL, Local_u16NextAlarm);
   }
}

#define PTMHAL_STOP_SEC_CODE
#include "PTMHAL_MemMap.h"


/*------------------------------ end of file -----------------------------*/
