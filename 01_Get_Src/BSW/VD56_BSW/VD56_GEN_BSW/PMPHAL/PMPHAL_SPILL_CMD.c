/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_SPILL_CMD.c                                                                              */
/* !Description     : Management Spill Command                                                                        */
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
 * %PID: P2017_BSW:0A189072.A-SRC;1 %
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
/* !FuncName    : PMPHAL_vidSpillCommandManager                                                                       */
/* !Description : This service shall apply the new parameters set by the ASW at the spill event.                      */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidSpillCommandManager(void)
{
   boolean bLocalActuationCondition;


   bLocalActuationCondition = FALSE;

   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuINIT_STATE:
      case PMPHAL_enuDISABLED:
      case PMPHAL_enuEVENT_OFF_CMD_OFF:
      case PMPHAL_enuEVENT_OFF_CMD_ON:
      case PMPHAL_enuEVENT_ON_CMD_OFF:
         break;

      case PMPHAL_enuEVENT_ON_CMD_ON:
         SchM_Enter_PMPHAL_ACCESS_003();
         bLocalActuationCondition  = PMPHAL_bActuationProgrammed;
         PMPHAL_bSpillCmdRequested = bLocalActuationCondition;
         SchM_Exit_PMPHAL_ACCESS_003();

         if (bLocalActuationCondition == FALSE)
         {
#ifdef PROFILES_MGMT_ON
            if (PMPHAL_bProfSwitchProgrammed == FALSE)
            {
               PMPHAL_vidCfgSwitchCmdProfile(PMPHAL_u8CMD_PULSE_ID, &PMPHAL_udtProfileSwitchRqstStatus);
            }
#endif
            PMPHAL_vidACTUATE_SPILL_CMD();
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidSpillCmdNotification                                                                      */
/* !Description : Callback of the start of command pulse. It occurs at the angles set by PMPHAL_vidWriteSpillCmdAngle.*/
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidSpillCmdNotification(void)
{
   boolean bLocalSpillCmdEndStatus;
   uint32  u32LocalCmdTime;
   uint32  u32LocalDecelTime;
   uint32  u32LocalSwitchToCmdValue;
   uint32  u32LocalSwitchProfileDly;
   Std_ReturnType udtConvStatus;

   CRKHAL_vidDisableAlarmNotif(PMPHAL_u8CRKHAL_SPILL_CMD_CH);

   PMPHAL_u32PrevSwitchDlyTime  = PMPHAL_u32ProfSwitchDlyTime;
   PMPHAL_u32PrevSpillDecelTime = PMPHAL_u32SpillDecelTime;
   
   PMPHAL_bActuationProgrammed  = FALSE;

#ifdef PROFILES_MGMT_ON
   PMPHAL_udtCurrentProfileStatus = PMPHAL_udtCfgGetProfileStatus();

   if (PMPHAL_bProfSwitchProgrammed == FALSE)
   {
      if (  (PMPHAL_udtProfileSwitchRqstStatus == E_OK)
         && (PMPHAL_udtCurrentProfileStatus    == E_OK)
         && (PMPHAL_u8CurrentProfileId         == PMPHAL_u8CmdPulseProfileId))
      {
#endif
         PMPHAL_vidSpillCmdEnded(&bLocalSpillCmdEndStatus);
         if (bLocalSpillCmdEndStatus != FALSE) /* command is already ended */ 
         {
            u32LocalCmdTime = PMPHAL_u32SpillCmdTime;

            PMPHAL_vidCfgCmdTimeRescale(&u32LocalCmdTime, &udtConvStatus);

            if ((u32LocalCmdTime > 0u) && (udtConvStatus == E_OK))
            {
               PMPHAL_vidStartSpillCmd(u32LocalCmdTime);

               u32LocalDecelTime = PMPHAL_u32PrevSpillDecelTime;

               PMPHAL_vidCfgCmdTimeRescale(&u32LocalDecelTime, &udtConvStatus);

               if ((u32LocalDecelTime > 0u) && (udtConvStatus == E_OK))
               {
#ifdef PROFILES_MGMT_ON
                  PMPHAL_u8DecelPulseProfileIdMem = PMPHAL_u8DecelPulseProfileId;

                  if (PMPHAL_u8DecelPulseProfileId != PMPHAL_u8CurrentProfileId)
                  {
                     u32LocalSwitchProfileDly = MATHSRV_udtMIN(PMPHAL_u32SpillCmdTime, PMPHAL_u32PrevSwitchDlyTime);
                     u32LocalSwitchToCmdValue = PMPHAL_u32SpillCmdTime - u32LocalSwitchProfileDly;
                     PMPHAL_u32RelDecelDelayValue = (uint32)(u32LocalSwitchToCmdValue + PMPHAL_u32SpillDecelDelay);

                     if (PMPHAL_u32RelDecelDelayValue >= u32LocalSwitchToCmdValue)
                     {
                        PMPHAL_vidCfgDlyTimeRescale(&u32LocalSwitchProfileDly, &udtConvStatus);

                        if (udtConvStatus == E_OK)
                        {
                           PMPHAL_enuCapcomDelayState   = PMPHAL_enuSWITCH_DECEL_PROFILE;
                           PMPHAL_bProfSwitchProgrammed = TRUE;
                           PMPHAL_bActuationProgrammed  = TRUE;

                           PMPHAL_vidPROG_CAPCOM_DLY(u32LocalSwitchProfileDly);
                        }
                     }
                     else
                     {
                        SWFAIL_vidSoftwareErrorHook();
                     }
                  }
                  else
                  {
#endif
                     PMPHAL_u32RelDecelDelayValue = (uint32)(PMPHAL_u32SpillCmdTime + PMPHAL_u32SpillDecelDelay);

                     if (PMPHAL_u32RelDecelDelayValue >= PMPHAL_u32SpillCmdTime)
                     {
                        PMPHAL_vidCfgDlyTimeRescale(&PMPHAL_u32RelDecelDelayValue, &udtConvStatus);

                        if (udtConvStatus == E_OK)
                        {
                           PMPHAL_enuCapcomDelayState  = PMPHAL_enuDECEL_DELAY_STATE;
                           PMPHAL_bActuationProgrammed = TRUE;

                           PMPHAL_vidPROG_CAPCOM_DLY(PMPHAL_u32RelDecelDelayValue);
                        }
                     }
                     else
                     {
                        SWFAIL_vidSoftwareErrorHook();
                     }
#ifdef PROFILES_MGMT_ON
                  }
#endif
               }
            }
         }
#ifdef PROFILES_MGMT_ON
      }
   }
#endif
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidDelayEndNotification                                                                      */
/* !Description : Callback of the prpgrammed delay. It occurs at the delay set by PMPHAL_vidWriteSpillDecelDelay and  */
/*                PMPHAL_vidWriteDecelHppProfilDly.                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidDelayEndNotification(void)
{
   boolean bLocalSpillCmdEndStatus;
   uint32  u32LocalDecelTime;
   uint32  u32LocalDecelDelay;
   uint32  u32LocalSwitchProfileDly;
   Std_ReturnType udtConvStatus;

   Gpt_StopTimer(PMPHAL_snGPT_PMP_DELAY_CH);
   Gpt_DisableNotification(PMPHAL_snGPT_PMP_DELAY_CH);

#ifdef PROFILES_MGMT_ON
   switch (PMPHAL_enuCapcomDelayState)
   {
      case PMPHAL_enuSWITCH_DECEL_PROFILE:
         PMPHAL_bProfSwitchProgrammed = FALSE;
         u32LocalDecelDelay           = PMPHAL_u32RelDecelDelayValue;

         PMPHAL_vidCfgSwitchCmdProfile(PMPHAL_u8DECEL_PULSE_ID, &PMPHAL_udtProfileSwitchRqstStatus);
         PMPHAL_vidCfgDlyTimeRescale(&u32LocalDecelDelay, &udtConvStatus);

         if (udtConvStatus == E_OK)
         {
            PMPHAL_enuCapcomDelayState = PMPHAL_enuDECEL_DELAY_STATE;

            PMPHAL_vidPROG_CAPCOM_DLY(u32LocalDecelDelay);
         }
         else
         {
            PMPHAL_bActuationProgrammed = FALSE;
         }
         break;

      case PMPHAL_enuDECEL_DELAY_STATE:
         PMPHAL_udtCurrentProfileStatus = PMPHAL_udtCfgGetProfileStatus();
#endif
         PMPHAL_bActuationProgrammed    = FALSE;

#ifdef PROFILES_MGMT_ON
         if (  (PMPHAL_udtProfileSwitchRqstStatus == E_OK)
            && (PMPHAL_udtCurrentProfileStatus    == E_OK)
            && (PMPHAL_u8CurrentProfileId         == PMPHAL_u8DecelPulseProfileIdMem))
         {
#endif
            PMPHAL_vidSpillCmdEnded(&bLocalSpillCmdEndStatus);
            if (bLocalSpillCmdEndStatus != FALSE) /* command is already ended */ 
            {
               u32LocalDecelTime = PMPHAL_u32PrevSpillDecelTime;
               PMPHAL_vidCfgCmdTimeRescale(&u32LocalDecelTime, &udtConvStatus);

               if ((u32LocalDecelTime > 0u) && (udtConvStatus == E_OK))
               {
                  PMPHAL_vidStartSpillCmd(u32LocalDecelTime);
               }
            }
#ifdef PROFILES_MGMT_ON
         }

         if (PMPHAL_u8CmdPulseProfileId != PMPHAL_u8CurrentProfileId)
         {
            u32LocalSwitchProfileDly = MATHSRV_udtMIN(PMPHAL_u32PrevSpillDecelTime, PMPHAL_u32PrevSwitchDlyTime);
            PMPHAL_vidCfgDlyTimeRescale(&u32LocalSwitchProfileDly, &udtConvStatus);

            if (udtConvStatus == E_OK)
            {
               PMPHAL_bProfSwitchProgrammed = TRUE;
               PMPHAL_enuCapcomDelayState   = PMPHAL_enuSWITCH_CMD_PROFILE;

               PMPHAL_vidPROG_CAPCOM_DLY(u32LocalSwitchProfileDly);
            }
         }
#endif

         if (PMPHAL_bSpillCmdRequested != FALSE)
         {
            PMPHAL_bSpillCmdRequested = FALSE;
            PMPHAL_vidACTUATE_SPILL_CMD();
         }
#ifdef PROFILES_MGMT_ON
         break;

      case PMPHAL_enuSWITCH_CMD_PROFILE:
         PMPHAL_bProfSwitchProgrammed = FALSE;

         PMPHAL_vidCfgSwitchCmdProfile(PMPHAL_u8CMD_PULSE_ID, &PMPHAL_udtProfileSwitchRqstStatus);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
   }
#endif
}


#define PMPHAL_STOP_SEC_CODE
#include "PMPHAL_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
