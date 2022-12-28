/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_5.c                                              */
/* !Description     : RSA standard camshaft sub-functions                     */
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
 * %PID: P2017_BSW:A81080.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CAMHAL_Cfg.h"
#include "CAMHAL_I.h"
#include "CRKHAL.h"
#include "SWFAIL.h"
#include "TSKSRV.h"
#include "CAMHAL.h"
#include "CAMHAL_L.h"

#define CAMHAL_START_SEC_CODE
#include "CAMHAL_MemMap.h"


#if (CAMHAL_bRSA_STD_ALLOWED == 1)

/******************************************************************************/
/* !FuncName    : CAMHAL_vidRSA_STD_SetMode                                   */
/* !Description : The sets mode for RSA CAMHAL input                          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidRSA_STD_SetMode(CAMHAL_tudtChannel udtChannelName)
{
   CRKHAL_vidActivateAlarmMode(CAMHAL_kau8CrkAlarm[udtChannelName],
   MODE_CAP_BOTH_EDGES);
   CRKHAL_vidEnableAlarmNotif(CAMHAL_kau8CrkAlarm[udtChannelName]);
   CAMHAL_aenuMode[udtChannelName] = CAMHAL_udtNORMAL_MODE;
   CAMHAL_vidNormalModeEntry(udtChannelName);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtRSA_STD_ReadCylNum                                */
/* !Description : The reads cycle number for RSA CAMHAL input                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtRSA_STD_ReadCylNum(CAMHAL_tudtChannel udtChannelName,
CAMHAL_tenuCylinderNumber *penuCylinderNumber)
{
   *penuCylinderNumber = CAMHAL_enuGetCylinder(udtChannelName);
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtRSA_STD_ReadSigLvl                                */
/* !Description : The reads signal level for RSA CAMHAL input                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtRSA_STD_ReadSigLvl(CAMHAL_tudtChannel udtChannelName,
boolean *pbLevel)
{
   *pbLevel = CAMHAL_bDioRead(udtChannelName);
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidRSA_STD_CaptureMng                                */
/* !Description : The function runs the capture management for RSA CAMHAL     */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidRSA_STD_CaptureMng(CAMHAL_tudtChannel udtChannelName,
uint32 u32EdgeTime)
{
   uint32 u32LocalLastToothDuration;
   boolean bLocalInputCamshaftLevel;
   boolean bLocalCrkSynchronised;
   Std_ReturnType udtLocalStatus;
   uint32 M2C_uint32_2;
   uint32 M2C_uint32_3;

   bLocalInputCamshaftLevel = CAMHAL_bDioRead(udtChannelName);
   if (bLocalInputCamshaftLevel != STD_LOW)
   {
      CAMHAL_au32FirstToothDuration[udtChannelName] =
            ((u32EdgeTime) - CAMHAL_au32PreviousEdgeTime[udtChannelName])
            & CAMHAL_u32TIMER_MAX_LIMIT;
   }
   else
   {
      CAMHAL_au8RunningTimeoutCnt[udtChannelName] = CAMHAL_kau8RunningThreshold[
      udtChannelName];
      u32LocalLastToothDuration = (((u32EdgeTime) -
                                CAMHAL_au32PreviousEdgeTime[udtChannelName])
                                & CAMHAL_u32TIMER_MAX_LIMIT);

      CAMHAL_vidActivateCamEvent(udtChannelName);
      if ((CAMHAL_abFirstCamPeriod[udtChannelName]) == (boolean)TRUE)
      {
         CAMHAL_abFirstCamPeriod[udtChannelName] = (boolean)FALSE;
         CAMHAL_aenuPatternStatus[udtChannelName] =
               CAMHAL_udtPATTERN_IN_2_PERIOD;
      }
      else
      {
         M2C_uint32_2 = CAMHAL_au32FirstToothDuration[udtChannelName];
         M2C_uint32_3 = u32LocalLastToothDuration;
         if ((((sint32)M2C_uint32_2) < 0) && (((sint32)M2C_uint32_3) < 0))
         {
            u32LocalLastToothDuration = UINT32_MAX;
         }
         else
         {
         /* Addition of Low and High period */
            u32LocalLastToothDuration = M2C_uint32_2 + M2C_uint32_3;
            if (((((sint32)M2C_uint32_2) < 0) || (((sint32)M2C_uint32_3) < 0))
            && (((sint32)u32LocalLastToothDuration) >= 0))
            {
               u32LocalLastToothDuration = (uint32)UINT32_MAX;
            }
         }
         CAMHAL_au32CamToothPeriod[udtChannelName] =((u32LocalLastToothDuration
                                             * CAMHAL_u16COEF_TIMER_RESOL)/
                                             CAMHAL_u16COEF_DESIRED_RESOL);
         if ((CAMHAL_abDetected[udtChannelName]) == (boolean)FALSE)
         {
            CAMHAL_abDetected[udtChannelName] = (boolean)TRUE;
            if ((CAMHAL_abEvtActivationEnabled[udtChannelName]) == (boolean)TRUE)
            {
               /*Start the Angular Clock Generation (before to update the Cyl) */
            /*CAMHAL_vidEnableAngClkGen();*/
            TSKSRV_vidActivateTask(CAMHAL_SIGNAL_DETECTION_EVENT);
            }
         }
         if (((CAMHAL_au32CamToothPeriod[udtChannelName]) <= ((
         CAMHAL_kau8RunningThreshold[udtChannelName]) * CAMHAL_u16TIMEOUT_DETECT_RESOL))
         && ((CAMHAL_abRunning[udtChannelName]) == (boolean)FALSE))
         {
            CAMHAL_abRunning[udtChannelName] = (boolean)TRUE;
            if ((CAMHAL_abEvtActivationEnabled[udtChannelName]) == (boolean)TRUE)
            {
               TSKSRV_vidActivateTask(CAMHAL_STALL_TO_RUN_EVENT);
            }
         }
         if (((uint32)(CAMHAL_u8LONG_TOOTH_RATIO_RESOL * (
         CAMHAL_au32CamToothPeriod[udtChannelName]))) < ((uint32)((
         CAMHAL_kau8LongToothRecoRatio[udtChannelName]) * (CAMHAL_au32FirstToothDuration[
         udtChannelName]))))
         {
            CAMHAL_abToothType[udtChannelName] = CAMHAL_bLONG_TOOTH;
         }
         else
         {
            CAMHAL_abToothType[udtChannelName] = CAMHAL_bSHORT_TOOTH;
         }
         switch(CAMHAL_aenuPatternStatus[udtChannelName])
         {
         case CAMHAL_udtPATTERN_NOT_DETECTED:
            CAMHAL_aenuPatternStatus[udtChannelName] =
            CAMHAL_udtPATTERN_IN_2_PERIOD;
            break;

         case CAMHAL_udtPATTERN_IN_2_PERIOD:
            CAMHAL_aenuPatternStatus[udtChannelName] =
            CAMHAL_udtPATTERN_IN_1_PERIOD;
            break;

         case CAMHAL_udtPATTERN_IN_1_PERIOD:
            CAMHAL_aenuPatternStatus[udtChannelName] =
            CAMHAL_udtPATTERN_DETECTED;

         case CAMHAL_udtPATTERN_DETECTED:
            if ((CAMHAL_abToothType[udtChannelName]) == CAMHAL_bLONG_TOOTH)
            {
               if ((CAMHAL_abPreviousToothType[udtChannelName]) ==
               CAMHAL_bLONG_TOOTH)
               {
                  CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][2];
               }
               else
               {
                  CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][1];
               }
            }
            else
            {
               if ((CAMHAL_abPreviousToothType[udtChannelName]) ==
               CAMHAL_bLONG_TOOTH)
               {
                  CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][3];
               }
               else
               {
                  CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][0];
               }
            }
            CAMHAL_vidPatternManagement(udtChannelName);
            break;
         default:
            CAMHAL_aenuPatternStatus[udtChannelName] =
               CAMHAL_udtPATTERN_NOT_DETECTED;
               SWFAIL_vidSoftwareErrorHook();
            break;
         }
         CAMHAL_abPreviousToothType[udtChannelName] = CAMHAL_abToothType[
         udtChannelName];
         udtLocalStatus = CRKHAL_udtReadStatus(CRKHAL_u8SYNCHRONISED, &
         bLocalCrkSynchronised);
         if ((bLocalCrkSynchronised == (boolean)TRUE) && (udtLocalStatus == E_OK))
         {
            CAMHAL_abEvtPositionAvailable[udtChannelName] = (boolean)TRUE;
         }
         else
         {
            CAMHAL_abEvtPositionAvailable[udtChannelName] = (boolean)FALSE;
         }
           CAMHAL_au16EngineAngle[udtChannelName] =
               CRKHAL_u16ReadAlarm(CAMHAL_kau8CrkAlarm[udtChannelName]);
         if (((CAMHAL_abEvtActivationEnabled[udtChannelName]) == (boolean)TRUE) && ((
         CAMHAL_abDetected[udtChannelName]) == (boolean)TRUE))
         {
            /*CAMHAL_vidAngClkGenManager();*/
         }
      }
   }
   CAMHAL_au32PreviousEdgeTime[udtChannelName] = u32EdgeTime;
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidRSA_STD_PatternMng                                */
/* !Description : The function runs the pattern management for RSA CAMHAL     */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidRSA_STD_PatternMng(CAMHAL_tudtChannel udtChannelName,
boolean *pbFaultExist)
{
   if (((CAMHAL_aenuLastCylinderNumber[udtChannelName]) ==
          CAMHAL_udtUNKNOWN_CYLINDER) || (((CAMHAL_aenuLastCylinderNumber[udtChannelName])
          != (CAMHAL_aenuCylinderNumber[udtChannelName])) && ((CAMHAL_aenuCylinderNumber[
          udtChannelName]) != CAMHAL_udtUNKNOWN_CYLINDER)))
   {
      *pbFaultExist = (boolean)TRUE;
   }
   else
   {
      switch(CAMHAL_u8NUMBER_OF_CYLINDERS)
      {
      case CAMHAL_u8THREE_CYLINDERS:
         CAMHAL_vidGET_NEXT_CYLINDER_3(udtChannelName);
         break;
      case CAMHAL_u8FOUR_CYLINDERS:
         CAMHAL_vidGET_NEXT_CYLINDER_4(udtChannelName);
         break;
      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
      }
      *pbFaultExist = (boolean)FALSE;
   }
}

#endif /* (CAMHAL_bRSA_STD_ALLOWED == 1) */

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
