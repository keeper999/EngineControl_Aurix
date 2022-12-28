/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_3.c                                              */
/* !Description     : Standard camshaft sub-functions                         */
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
 * %PID: P2017_BSW:A81079.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CAMHAL_Cfg.h"
#include "CAMHAL_I.h"
#include "CRKHAL.h"
#include "SWFAIL.h"
#include "CAMHAL.h"
#include "CAMHAL_L.h"

#define CAMHAL_START_SEC_CODE
#include "CAMHAL_MemMap.h"

#if (CAMHAL_bSTANDARD_ALLOWED == 1)

/******************************************************************************/
/* !FuncName    : CAMHAL_vidSTANDARD_SetMode / E                              */
/* !Description : The function sets the Mode for Std CAMHAL input             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidSTANDARD_SetMode(CAMHAL_tudtChannel udtChannelName)
{
   CRKHAL_vidActivateAlarmMode(CAMHAL_kau8CrkAlarm[udtChannelName],
   MODE_CAP_BOTH_EDGES);
   CRKHAL_vidEnableAlarmNotif(CAMHAL_kau8CrkAlarm[udtChannelName]);
   CAMHAL_aenuMode[udtChannelName] = CAMHAL_udtNORMAL_MODE;
   CAMHAL_vidNormalModeEntry(udtChannelName);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtSTANDARD_ReadCylNum / E                           */
/* !Description : The reads cycle number for Std CAMHAL input                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtSTANDARD_ReadCylNum(CAMHAL_tudtChannel udtChannelName,
CAMHAL_tenuCylinderNumber *penuCylinderNumber)
{
   Std_ReturnType udtLocalRetValue;

   *penuCylinderNumber = CAMHAL_enuGetCylinder(udtChannelName);
   udtLocalRetValue = E_OK;
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtSTANDARD_ReadSigLvl / E                           */
/* !Description : The reads signal level for Std CAMHAL input                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtSTANDARD_ReadSigLvl(CAMHAL_tudtChannel udtChannelName,
boolean *pbLevel)
{
   Std_ReturnType udtLocalRetValue;

   *pbLevel = CAMHAL_bDioRead(udtChannelName);
   udtLocalRetValue = E_OK;
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidSTANDARD_CaptureMng / D                           */
/* !Description : The does the pattern capture for Std CAMHAL input           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidSTANDARD_CaptureMng(CAMHAL_tudtChannel udtChannelName,
uint32 u32EdgeTime)
{
   uint32 u32LocalLastToothDuration;
   boolean bLocalInputCamshaftLevel;
   boolean bLocalCrkSynchronised;
   uint32 M2C_uint32_2;
   uint32 M2C_uint32_3;

   /* read the Level at the CAMHAL input */
   bLocalInputCamshaftLevel = CAMHAL_bDioRead(udtChannelName);
   if (bLocalInputCamshaftLevel != (CAMHAL_kabSynchroSigLvlType[udtChannelName]))
   {
     CAMHAL_au32FirstToothDuration[udtChannelName] =
                  ((u32EdgeTime)
                  - (CAMHAL_au32PreviousEdgeTime[udtChannelName]))
                    & CAMHAL_u32TIMER_MAX_LIMIT;

   }
   else
   {
      CAMHAL_au8RunningTimeoutCnt[udtChannelName] = CAMHAL_kau8RunningThreshold[
                                                    udtChannelName];
      u32LocalLastToothDuration = (uint32)(((u32EdgeTime) - (CAMHAL_au32PreviousEdgeTime[
      udtChannelName])) & CAMHAL_u32TIMER_MAX_LIMIT);
      if ((CAMHAL_abFirstCamPeriod[udtChannelName]) == (boolean)TRUE)
      {
         CAMHAL_abFirstCamPeriod[udtChannelName] = (boolean)FALSE;
      }
      else
      {
       /* Tooth duration is duration of low and high pulse */
         M2C_uint32_2 = CAMHAL_au32FirstToothDuration[udtChannelName];
         M2C_uint32_3 = u32LocalLastToothDuration;
         if ((((sint32)M2C_uint32_2) < 0) && (((sint32)M2C_uint32_3) < 0))
         {
            u32LocalLastToothDuration = (uint32)UINT32_MAX;
         }
         else
         {
            u32LocalLastToothDuration = M2C_uint32_2 + M2C_uint32_3;
            if (((((sint32)M2C_uint32_2) < 0) || (((sint32)M2C_uint32_3) < 0))
            && (((sint32)u32LocalLastToothDuration) >= 0))
            {
               u32LocalLastToothDuration = (uint32)UINT32_MAX;
            }
         }
         CAMHAL_au32CamToothPeriod[udtChannelName] = (u32LocalLastToothDuration *
                                                 CAMHAL_u16COEF_TIMER_RESOL) /
                                                 CAMHAL_u16COEF_DESIRED_RESOL;
         /* Set detected and running */
         if ((CAMHAL_abDetected[udtChannelName]) == (boolean)FALSE)
         {
            CAMHAL_abDetected[udtChannelName] = (boolean)TRUE;
         }
         if (((CAMHAL_au32CamToothPeriod[udtChannelName]) <= ((
         CAMHAL_kau8RunningThreshold[udtChannelName]) * CAMHAL_u16TIMEOUT_DETECT_RESOL))
         && ((CAMHAL_abRunning[udtChannelName]) == (boolean)FALSE))
         {
            CAMHAL_abRunning[udtChannelName] = (boolean)TRUE;
         }
         if ((CAMHAL_abRunning[udtChannelName]) != (boolean)FALSE)
         {
            CAMHAL_vidActivateCamEvent(udtChannelName);
         }
         (void)CRKHAL_udtReadStatus(CRKHAL_u8SYNCHRONISED, &bLocalCrkSynchronised);
         if (bLocalCrkSynchronised == (boolean)TRUE)
         {
            CAMHAL_abEvtPositionAvailable[udtChannelName] = (boolean)TRUE;
         }
         else
         {
            CAMHAL_abEvtPositionAvailable[udtChannelName] = (boolean)FALSE;
         }
       CAMHAL_au16EngineAngle[udtChannelName] =
               CRKHAL_u16ReadAlarm(CAMHAL_kau8CrkAlarm[udtChannelName]);
      }
   }
   CAMHAL_au32PreviousEdgeTime[udtChannelName] = u32EdgeTime;
}

#endif /* (CAMHAL_bSTANDARD_ALLOWED == 1) */

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
