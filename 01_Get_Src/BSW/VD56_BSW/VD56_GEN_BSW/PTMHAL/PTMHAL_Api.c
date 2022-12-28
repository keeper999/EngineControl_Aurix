/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PTMHAL                                                  */
/* !Description     : Precise Teeth Measurement HAL Service Layer             */
/*                                                                            */
/* !File            : PTMHAL_Api.c                                            */
/* !Description     : API of the PTMHAL Component                             */
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
 * %PID: P2017_BSW:0A149689.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CRKHAL.h"
#include "PTMHAL_I.h"
#include "SWFAIL.h"
#include "PTMHAL.h"
#include "PTMHAL_l.h"

#define PTMHAL_START_SEC_CODE
#include "PTMHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : PTMHAL_vidInit                                              */
/* !Description : Initialize all internal variables of the component PTMHAL   */
/*                After initialization, PTMHAL is in disabled state           */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/
void PTMHAL_vidInit(void)
{
   PTMHAL_vidGeneralInitialization();
}

/******************************************************************************/
/* !FuncName    : PTMHAL_udtEnable                                            */
/* !Description : Start any hardware or software resources needed for precise */
/*                tooth measurement                                           */
/*                PTMHAL is successfully enabled if angular reference is      */
/*                available and based on real crankshaft signal               */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/
Std_ReturnType PTMHAL_udtEnable(void)
{
   uint8          u8LocalCounter;
   uint8          u8LocalInit;
   uint16         u16LocalFirstAlarm;
   Std_ReturnType udtLocalStatus;
   boolean        bLocalSynchronised;


   if (PTMHAL_bEnabled != FALSE)
   {
      udtLocalStatus = E_OK;
   }
   else
   {
      udtLocalStatus = CRKHAL_udtReadStatus(CRKHAL_u8SYNCHRONISED,
                                            &bLocalSynchronised);
      if (  (udtLocalStatus == E_OK)
         && (bLocalSynchronised == TRUE) )
      {
         u16LocalFirstAlarm = CRKHAL_u16ReadCounter(CRKHAL_u8ALARM_PTMHAL);
         u16LocalFirstAlarm = PTMHAL_u16ANGULAR_MARGIN + u16LocalFirstAlarm;
         if ( ( (sint32)u16LocalFirstAlarm) >= PTMHAL_u16ENGINE_CYCLE)
         {
            u16LocalFirstAlarm = u16LocalFirstAlarm - PTMHAL_u16ENGINE_CYCLE;
         }
         if (  (u16LocalFirstAlarm < (PTMHAL_kau16AlarmAngle[UINT8_MIN + 1]) )
            && ((PTMHAL_kau16AlarmAngle[UINT8_MIN]) < (PTMHAL_kau16AlarmAngle[UINT8_MIN + 1]) ) )
         {
            u8LocalInit = UINT8_MIN;
         }
         else
         {
            u8LocalInit = UINT8_MIN + 1;
         }
         u8LocalCounter = u8LocalInit;
         while (  (u8LocalCounter < PTMHAL_ku8AlarmNbPerCycle)
               && (u16LocalFirstAlarm >= (PTMHAL_kau16AlarmAngle[u8LocalCounter])))
         {
            u8LocalCounter++;
         }
         if ( ( (sint32)u8LocalCounter) >= ( (sint32)PTMHAL_ku8AlarmNbPerCycle) )
         {
            if (  (u16LocalFirstAlarm >= (PTMHAL_kau16AlarmAngle[UINT8_MIN]) )
               && ((PTMHAL_kau16AlarmAngle[UINT8_MIN]) >= (PTMHAL_kau16AlarmAngle[UINT8_MIN + 1]) ) )
            {
               u8LocalCounter = UINT8_MIN + 1;
            }
            else
            {
               u8LocalCounter = UINT8_MIN;
            }
         }
         PTMHAL_u8CycleIndex = u8LocalCounter;
         u16LocalFirstAlarm  = PTMHAL_kau16AlarmAngle[u8LocalCounter];
         CRKHAL_vidActivateAlarmMode(CRKHAL_u8ALARM_PTMHAL, MODE_NO_ACTION);
         CRKHAL_vidSetAbsAlarm(CRKHAL_u8ALARM_PTMHAL, u16LocalFirstAlarm);
         CRKHAL_vidEnableAlarmNotif(CRKHAL_u8ALARM_PTMHAL);
         PTMHAL_bEnabled = TRUE;
      }
      else
      {
         udtLocalStatus  = E_NOT_OK;
         PTMHAL_bEnabled = FALSE;
      }
   }
   return(udtLocalStatus);
}

/******************************************************************************/
/* !FuncName    : PTMHAL_udtDisable                                           */
/* !Description : Stop all hardware and software resources in order to avoid: */
/*                - CPU load consumption.                                     */
/*                - Improper information processing.                          */
/*                - Incorrect event generation.                               */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/
Std_ReturnType PTMHAL_udtDisable(void)
{
   CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_PTMHAL);
   CRKHAL_vidDeactivateAlarmMode(CRKHAL_u8ALARM_PTMHAL);
   PTMHAL_vidGeneralInitialization();
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : PTMHAL_u8GetAllPacksDuration                                */
/* !Description : Fill the table pointed by the parameter                     */
/*                “pau32PacksDurationTable” with duration values of teeth */
/*                package                                                     */
/*                The number of elements in the table shall be determined     */
/*                by configuration                                            */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/
uint8 PTMHAL_u8GetAllPacksDuration(uint8   u8MaxTableSize,
                                   uint32 *pau32PacksDurationTable)
{
   uint8 u8LocalCounter;

   if (PTMHAL_bEnabled != FALSE)
   {
      if ( ( (sint32)PTMHAL_u8NbDurationPacksValid) <= ( (sint32)u8MaxTableSize) )
      {
         for ( u8LocalCounter = UINT8_MIN;
             ( (sint32)u8LocalCounter) < ( (sint32)PTMHAL_u8NbDurationPacksValid);
               u8LocalCounter++)
         {
            pau32PacksDurationTable[u8LocalCounter] = ( (uint32)( PTMHAL_au32DurationPack[u8LocalCounter] 
                                                                * PTMHAL_u16COEF_TIMER_RESOL))
                                                      / PTMHAL_u16COEF_DESIRED_RESOL;
         }
         u8LocalCounter = PTMHAL_u8NbDurationPacksValid;
      }
      else
      {
         u8LocalCounter = UINT8_MIN;
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      u8LocalCounter = UINT8_MIN;
   }
   return(u8LocalCounter);
}

/******************************************************************************/
/* !FuncName    : PTMHAL_udtGetFirstPackDuration                              */
/* !Description : return the duration of the first element of the teeth       */
/*                package duration table                                      */
/*                                                                            */
/* !LastAuthor  : B. Fourmestraux                                             */
/******************************************************************************/
Std_ReturnType PTMHAL_udtGetFirstPackDuration(uint32 *pu32FirstPackDuration)
{
   uint8 u8LocalReturn;


   if (PTMHAL_bEnabled != FALSE)
   {
      *pu32FirstPackDuration = ( (uint32)( PTMHAL_au32DurationPack[0]
                                         * PTMHAL_u16COEF_TIMER_RESOL))
                               / PTMHAL_u16COEF_DESIRED_RESOL;
      u8LocalReturn = E_OK;
   }
   else
   {
      u8LocalReturn = E_NOT_OK;
   }
   return(u8LocalReturn);
}

#define PTMHAL_STOP_SEC_CODE
#include "PTMHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
