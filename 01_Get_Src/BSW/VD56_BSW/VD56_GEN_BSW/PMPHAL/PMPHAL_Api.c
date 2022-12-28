/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_Api.c                                                                                    */
/* !Description     : API of the PMPHAL Component                                                                     */
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
 * %PID: P2017_BSW:0A189075.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#include "Std_Limits.h"
#include "Std_Types.h"

#include "PMPHAL_CFG_I.h"
#include "PMPHAL_I.h"
#include "PMPHAL.h"
#include "PMPHAL_L.h"

#include "CRKHAL.h"
#include "Dio.h"
#include "SWFAIL.h"

/**********************************************************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                                                         */
/**********************************************************************************************************************/

#define PMPHAL_START_SEC_CODE
#include "PMPHAL_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidInit                                                                                      */
/* !Description : The API PMPHAL_vidInit shall initialize all PMPHAL internal data.                                   */
/* !TraceTo     : DEV REQ:VEES_R_5031545_003.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_004.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_005.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidInit(void)
{
   uint16 u16LocalInterSpillEventAngle;

   /* Initialise the GTM ATOM channel associated with the pump */
   PMPHAL_vidGtmInit();

   PMPHAL_vidENABLE_CONTINUOUS_MODE();

   PMPHAL_bSpillEventParamOk         = FALSE;
   PMPHAL_bFirstSpillEventOk         = FALSE;
#ifdef PROFILES_MGMT_ON
   PMPHAL_u8CmdPulseProfileId        = PMPHAL_u8DEFAULT_PROFILE;
   PMPHAL_u8DecelPulseProfileId      = PMPHAL_u8DEFAULT_PROFILE;
   PMPHAL_u8CurrentProfileId         = PMPHAL_u8DEFAULT_PROFILE;
#endif
#ifdef PROFILES_MGMT_OFF
   PMPHAL_u8CmdPulseProfileId        = UINT8_MAX;
   PMPHAL_u8DecelPulseProfileId      = UINT8_MAX;
   PMPHAL_u8CurrentProfileId         = UINT8_MAX;
#endif
   PMPHAL_u8NbSpillEventsRqstd       = PMPHAL_ku8NbSpillEventsRqstd;
   PMPHAL_u16SpillCmdAngle           = 0u;
   PMPHAL_u32SpillDecelDelay         = 0u;
   PMPHAL_u32SpillCmdTime            = 0u;
   PMPHAL_u32SpillDecelTime          = 0u;
#ifdef PROFILES_MGMT_ON
   PMPHAL_u32ProfSwitchDlyTime       = 0u;
#endif
   PMPHAL_udtCurrentProfileStatus    = E_OK;
   PMPHAL_udtProfileSwitchRqstStatus = E_OK;
   PMPHAL_enuComponentStatus         = PMPHAL_enuINIT_STATE;


   if (PMPHAL_u8NbSpillEventsRqstd > 0u)
   {
      u16LocalInterSpillEventAngle = (uint16)(PMPHAL_u16ENGINE_CYCLE / PMPHAL_u8NbSpillEventsRqstd);
     
      PMPHAL_u16SpillEventAngleRqstd = PMPHAL_ku16SpillEventAngleRqstd;
      PMPHAL_u16InterSpillEventAngle = u16LocalInterSpillEventAngle;

      if (PMPHAL_u16SpillEventAngleRqstd < PMPHAL_u16InterSpillEventAngle)
      {
         PMPHAL_bSpillEventParamOk = TRUE;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidEnable                                                                                    */
/* !Description : The API PMPHAL_vidEnable shall enable the component and the Spill Event generation.                 */
/* !TraceTo     : DEV REQ:VEES_R_5031545_006.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_007.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_008.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidEnable(void)
{
   boolean        bLocalEngineStatus;
   Std_ReturnType udtLocalStatus;


   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuINIT_STATE:
      case PMPHAL_enuDISABLED:
         udtLocalStatus = CRKHAL_udtReadStatus(CRKHAL_u8ENG_SYNCHRONISED, &bLocalEngineStatus);
         if ((bLocalEngineStatus != FALSE) && (udtLocalStatus == E_OK))
         {
            PMPHAL_enuComponentStatus = PMPHAL_enuEVENT_ON_CMD_OFF;
            PMPHAL_vidENABLE_SEQUENTIAL_MODE();
         }
         else
         {
            PMPHAL_enuComponentStatus = PMPHAL_enuEVENT_OFF_CMD_OFF;
            PMPHAL_vidENABLE_CONTINUOUS_MODE();
         }
         break;

      case PMPHAL_enuEVENT_OFF_CMD_OFF:
      case PMPHAL_enuEVENT_ON_CMD_ON:
      case PMPHAL_enuEVENT_ON_CMD_OFF:
      case PMPHAL_enuEVENT_OFF_CMD_ON:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         PMPHAL_enuComponentStatus = PMPHAL_enuDISABLED;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidDisable                                                                                   */
/* !Description : The API PMPHAL_vidDisable shall Disable the component, the Spill Valve Command and the Spill Event  */
/*                generation.                                                                                         */
/* !TraceTo     : DEV REQ:VEES_R_5031545_009.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_010.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidDisable(void)
{
   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuINIT_STATE:
      case PMPHAL_enuDISABLED:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();

      case PMPHAL_enuEVENT_OFF_CMD_OFF:
      case PMPHAL_enuEVENT_ON_CMD_ON:
      case PMPHAL_enuEVENT_ON_CMD_OFF:
      case PMPHAL_enuEVENT_OFF_CMD_ON:
         PMPHAL_bGioCmdLevel       = STD_LOW;
         PMPHAL_enuComponentStatus = PMPHAL_enuDISABLED;

         PMPHAL_vidDISABLE_SPILL_CMD();
         PMPHAL_vidDISABLE_SPILL_EVENT();
         PMPHAL_vidENABLE_CONTINUOUS_MODE();
         PMPHAL_vidDISABLE_CAPCOM_DELAY();

#ifdef PROFILES_MGMT_ON
         PMPHAL_u8CmdPulseProfileId = PMPHAL_u8DEFAULT_PROFILE;

         PMPHAL_vidCfgSwitchCmdProfile(PMPHAL_u8CMD_PULSE_ID, &PMPHAL_udtProfileSwitchRqstStatus);
#endif
         break;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_udtEnableSpillCommand                                                                        */
/* !Description : The API PMPHAL_udtEnableSpillCommand shall enable the Spill Valve Command.                          */
/* !TraceTo     : DEV REQ:VEES_R_5031545_011.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_012.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_013.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType PMPHAL_udtEnableSpillCommand(void)
{
   Std_ReturnType udtLocalRetValue;


   udtLocalRetValue = E_NOT_OK;

   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuEVENT_ON_CMD_ON:
      case PMPHAL_enuEVENT_OFF_CMD_ON:
         udtLocalRetValue = E_OK;
         break;

      case PMPHAL_enuEVENT_ON_CMD_OFF:
         PMPHAL_enuComponentStatus = PMPHAL_enuEVENT_ON_CMD_ON;
         udtLocalRetValue = E_OK;
         break;

      case PMPHAL_enuEVENT_OFF_CMD_OFF:
         PMPHAL_enuComponentStatus = PMPHAL_enuEVENT_OFF_CMD_ON;
         udtLocalRetValue = E_OK;
         break;

      case PMPHAL_enuDISABLED:
      case PMPHAL_enuINIT_STATE:
      default:
         PMPHAL_vidDISABLE_SPILL_CMD();
         SWFAIL_vidSoftwareErrorHook();
   }

   return(udtLocalRetValue);
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_udtDisableSpillCommand                                                                       */
/* !Description : The API PMPHAL_udtDisableSpillCommand shall disable the Spill Valve Command.                        */
/* !TraceTo     : DEV REQ:VEES_R_5031545_014.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_015.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_016.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType PMPHAL_udtDisableSpillCommand(void)
{
   Std_ReturnType udtLocalRetValue;


   udtLocalRetValue = E_NOT_OK;

   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuEVENT_ON_CMD_ON:
         PMPHAL_enuComponentStatus = PMPHAL_enuEVENT_ON_CMD_OFF;
         PMPHAL_vidDISABLE_SPILL_CMD();
         udtLocalRetValue = E_OK;
         break;

      case PMPHAL_enuEVENT_OFF_CMD_ON:
         PMPHAL_enuComponentStatus = PMPHAL_enuEVENT_OFF_CMD_OFF;
         PMPHAL_vidDISABLE_SPILL_CMD();
         udtLocalRetValue = E_OK;
         break;

      case PMPHAL_enuEVENT_OFF_CMD_OFF:
      case PMPHAL_enuEVENT_ON_CMD_OFF:
         udtLocalRetValue = E_OK;
         break;

      case PMPHAL_enuDISABLED:
      case PMPHAL_enuINIT_STATE:
         break;

      default:
         PMPHAL_vidDISABLE_SPILL_CMD();
         SWFAIL_vidSoftwareErrorHook();
   }

   return(udtLocalRetValue);
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidWriteSpillCmdAngle                                                                        */
/* !Description : The API PMPHAL_vidWriteSpillCmdAngle shall update the spill valve relative command angle with the   */
/*                "u16SpillCmdAngle" angle value passed into parameter.                                               */
/* !TraceTo     : DEV REQ:VEES_R_5031545_017.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_018.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_019.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_020.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidWriteSpillCmdAngle
(
   uint16 u16SpillCmdAngle
)
{
   if (u16SpillCmdAngle <= (PMPHAL_u16InterSpillEventAngle - PMPHAL_u16_1_DEGREE))
   {
      PMPHAL_u16SpillCmdAngle = u16SpillCmdAngle;
   }
   else
   {
      PMPHAL_u16SpillCmdAngle = (uint16)(PMPHAL_u16InterSpillEventAngle - PMPHAL_u16_1_DEGREE);
      SWFAIL_vidSoftwareErrorHook();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidWriteSpillCmdTime                                                                         */
/* !Description : The API PMPHAL_vidWriteSpillCmdTime shall update the spill valve command time with the              */
/*                "u32CommandTime" time value passed into parameter.                                                  */
/* !TraceTo     : DEV REQ:VEES_R_5031545_021.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_022.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_023.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidWriteSpillCmdTime
(
   uint32 u32CommandTime
)
{
   PMPHAL_u32SpillCmdTime = u32CommandTime;
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidWriteSpillDecelDly                                                                        */
/* !Description : The API PMPHAL_vidWriteSpillDecelDly shall update the spill valve relative deceleration delay with  */
/*                the "u32SpillDecelDelay" time value passed into parameter.                                          */
/* !TraceTo     : DEV REQ:VEES_R_5031545_024.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_025.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_026.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidWriteSpillDecelDly
(
   uint32 u32SpillDecelDelay
)
{
   PMPHAL_u32SpillDecelDelay = u32SpillDecelDelay;
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidWriteSpillDecelTime                                                                       */
/* !Description : The API PMPHAL_vidWriteSpillDecelTime shall update the spill valve deceleration time with the       */
/*                "u32DecelTime" time value  passed into parameter.                                                   */
/* !TraceTo     : DEV REQ:VEES_R_5031545_027.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_028.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_029.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidWriteSpillDecelTime
(
   uint32 u32DecelTime
)
{
   PMPHAL_u32SpillDecelTime = u32DecelTime;
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_udtSwitchHppProfile                                                                          */
/* !Description : The API PMPHAL_udtSwitchHppProfile shall change the profile of the High Pressure Pump.              */
/* !TraceTo     : DEV REQ:VEES_R_5031545_030.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_031.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_032.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_033.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType PMPHAL_udtSwitchHppProfile
(
   uint8 u8HppPulseId,
   uint8 u8HppProfileId
)
{
#ifdef PROFILES_MGMT_ON
      switch (u8HppPulseId)
      {
         case PMPHAL_u8CMD_PULSE_ID:
            PMPHAL_u8CmdPulseProfileId = u8HppProfileId;
            break;

         case PMPHAL_u8DECEL_PULSE_ID:
            PMPHAL_u8DecelPulseProfileId = u8HppProfileId;
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
      }
      return E_OK;
#endif

#ifdef PROFILES_MGMT_OFF
      SWFAIL_vidSoftwareErrorHook();
      return E_NOT_OK;
#endif
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_vidWriteDecelHppProfilDly                                                                    */
/* !Description : The API PMPHAL_vidWriteDecelHppProfilDly shall update the delay between the start of the command    */
/*                pulse and the switch to the deceleration pulse profile.                                             */
/* !TraceTo     : DEV REQ:VEES_R_5031545_034.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_035.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void PMPHAL_vidWriteDecelHppProfilDly
(
   uint32 u32ProfilSwitchDelay
)
{
#ifdef PROFILES_MGMT_ON
   PMPHAL_u32ProfSwitchDlyTime = u32ProfilSwitchDelay;
#endif

#ifdef PROFILES_MGMT_OFF
   SWFAIL_vidSoftwareErrorHook();
#endif
}

/**********************************************************************************************************************/
/* !FuncName    : PMPHAL_udtWriteSpillCmdLevel                                                                        */
/* !Description : The API PMPHAL_udtWriteSpillCmdLevel shall update the output level of the spill valve command when  */
/*                the engine is not synchronized and is running.                                                      */
/* !TraceTo     : DEV REQ:VEES_R_5031545_035.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_036.01                                                                       */
/* !TraceTo     : DEV REQ:VEES_R_5031545_037.01                                                                       */
/* !TraceTo     : INT REQ:VEES_R_5031545_038.01                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType PMPHAL_udtWriteSpillCmdLevel
(
   boolean bSpillCmdLevel
)
{
   Std_ReturnType udtLocalRetValue;


   udtLocalRetValue    = E_NOT_OK;
   PMPHAL_bGioCmdLevel = STD_LOW;

#ifdef PROFILES_MGMT_ON
   PMPHAL_udtCurrentProfileStatus = PMPHAL_udtCfgGetProfileStatus();
#endif

   switch (PMPHAL_enuComponentStatus)
   {
      case PMPHAL_enuEVENT_ON_CMD_ON:
      case PMPHAL_enuEVENT_OFF_CMD_ON:
         if (PMPHAL_bFirstSpillEventOk == FALSE)
         {
            if (  (PMPHAL_udtCurrentProfileStatus    == E_OK)
               && (PMPHAL_udtProfileSwitchRqstStatus == E_OK)
               && (PMPHAL_u8CurrentProfileId         == PMPHAL_u8DEFAULT_PROFILE))
            {
               PMPHAL_bGioCmdLevel = bSpillCmdLevel;
               udtLocalRetValue    = E_OK;
            }
            else
            {
#ifdef PROFILES_MGMT_ON
               if (PMPHAL_u8CurrentProfileId != PMPHAL_u8DEFAULT_PROFILE)
               {
                  PMPHAL_u8CmdPulseProfileId = PMPHAL_u8DEFAULT_PROFILE;
                  PMPHAL_vidCfgSwitchCmdProfile(PMPHAL_u8CMD_PULSE_ID, &PMPHAL_udtProfileSwitchRqstStatus);
               }
#endif
               PMPHAL_bGioCmdLevel = STD_LOW;
            }
         }
         break;

      case PMPHAL_enuINIT_STATE:
      case PMPHAL_enuDISABLED:
      case PMPHAL_enuEVENT_ON_CMD_OFF:
      case PMPHAL_enuEVENT_OFF_CMD_OFF:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
   }

   Dio_WriteChannel(PMPHAL_snDIO_SPILL_CMD_CH, PMPHAL_bGioCmdLevel);
   return (udtLocalRetValue);
}


#define PMPHAL_STOP_SEC_CODE
#include "PMPHAL_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
