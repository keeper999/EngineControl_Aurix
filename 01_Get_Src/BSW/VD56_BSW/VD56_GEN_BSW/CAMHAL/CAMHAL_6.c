/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_6.c                                              */
/* !Description     : PSA 3Cyl camshaft sub-functions                         */
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
 * %PID: P2017_BSW:A81082.A-SRC;1 %
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

#if (CAMHAL_bPSA_3CYL_ALLOWED == 1)

/******************************************************************************/
/* !FuncName    : CAMHAL_vidPSA_3CYL_SetMode                                  */
/* !Description : The sets mode for PSA CAMHAL input                          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidPSA_3CYL_SetMode
(
   CAMHAL_tudtChannel udtChannelName
)
{
   /* !Comment: Enable acquisition input                                      */
   CRKHAL_vidActivateAlarmMode(CAMHAL_kau8CrkAlarm[udtChannelName],
                               MODE_CAP_BOTH_EDGES);

   CRKHAL_vidEnableAlarmNotif(CAMHAL_kau8CrkAlarm[udtChannelName]);

   CAMHAL_aenuMode[udtChannelName] = CAMHAL_udtNORMAL_MODE;

   /* !Comment: Callback for Normal Mode Entry                                */
   CAMHAL_vidNormalModeEntry(udtChannelName);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtPSA_ReadCylNum                                    */
/* !Description : The reads cycle number for PSA CAMHAL input                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtPSA_3CYL_ReadCylNum
(
   CAMHAL_tudtChannel udtChannelName,
   CAMHAL_tenuCylinderNumber* penuCylinderNumber
)
{
   *penuCylinderNumber = CAMHAL_enuGetCylinder(udtChannelName);

   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtPSA_3CYL_ReadSigLvl                               */
/* !Description : The reads signal level for PSA CAMHAL input                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtPSA_3CYL_ReadSigLvl
(
   CAMHAL_tudtChannel udtChannelName,
   boolean* pbLevel
)
{
   *pbLevel = CAMHAL_bDioRead(udtChannelName);

   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidRSA_CaptureMng                                    */
/* !Description : The function runs the capture management for PSA CAMHAL     */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidPSA_3CYL_CaptureMng
(
   CAMHAL_tudtChannel udtChannelName,
   uint32 u32EdgeTime
)
{
   uint32         u32LocalToothDuration;
   uint32         u32LocalCamToothPeriod;
   boolean        bLocalInputCamshaftLevel;
   boolean        bLocalCrkSynchronised;
   boolean        bLocalCamPeriodAvailable;
   boolean        bLocalToothDetected;
   Std_ReturnType udtLocalStatus;

   /* !Comment: local init                                                    */
   bLocalCamPeriodAvailable = (boolean)FALSE;
   bLocalToothDetected      = (boolean)FALSE;

   /* !Comment: Physical camshaft level                                       */
   bLocalInputCamshaftLevel = CAMHAL_bDioRead(udtChannelName);

   /* !Comment: Calculate Tooth Duration                                      */
   u32LocalToothDuration = ((u32EdgeTime)- CAMHAL_au32PreviousEdgeTime[udtChannelName])
                     & CAMHAL_u32TIMER_MAX_LIMIT;

   if (CAMHAL_abFirstCamPeriod[udtChannelName] == (boolean)TRUE)
   {
      CAMHAL_abFirstCamPeriod[udtChannelName] = (boolean)FALSE;
   }
   else
   {
      /* !Comment: Edge Detected                                              */
      if (CAMHAL_abDetected[udtChannelName] == (boolean)FALSE)
      {
         CAMHAL_abDetected[udtChannelName] = (boolean)TRUE;
         if (CAMHAL_abEvtActivationEnabled[udtChannelName] == (boolean)TRUE)
         {
            /* !Comment: CAMHAL_vidEnableAngClkGen shall be called            */
            /*            on E_CAMHAL_SIGNAL_DETECTION                        */
            /*CAMHAL_vidEnableAngClkGen();*/
            TSKSRV_vidActivateTask(CAMHAL_SIGNAL_DETECTION_EVENT);
         }
      }

      /* !Comment: Tooth Type Detection                                       */
      if (CAMHAL_au32LastToothDuration[udtChannelName] != (uint32)UINT32_MIN)
      {
         if ( (CAMHAL_u8LONG_TOOTH_RATIO_RESOL * u32LocalToothDuration)
            > ( CAMHAL_kau8LongToothRecoRatio[udtChannelName]
              * CAMHAL_au32LastToothDuration[udtChannelName]))
         {
            CAMHAL_abToothType[udtChannelName] = CAMHAL_bLONG_TOOTH;
            bLocalToothDetected = (boolean)TRUE;
         }
         else
         {
            if ( ( CAMHAL_u8LONG_TOOTH_RATIO_RESOL
                 * CAMHAL_au32LastToothDuration[udtChannelName])
               > ( CAMHAL_kau8LongToothRecoRatio[udtChannelName]
                 * u32LocalToothDuration))
            {
               CAMHAL_abToothType[udtChannelName] = CAMHAL_bSHORT_TOOTH;
               bLocalToothDetected = (boolean)TRUE;
            }
            else
            {
               CAMHAL_abToothType[udtChannelName] =
                  CAMHAL_abPreviousToothType[udtChannelName];
            }
         }
      }

      /* !Comment: Pattern status update                                      */
      if (  CAMHAL_aenuPatternStatus[udtChannelName]
         != CAMHAL_udtPATTERN_DETECTED)
      {
         if (  (bLocalToothDetected == (boolean)TRUE)
            && (bLocalInputCamshaftLevel != STD_LOW))
         {
            if ((CAMHAL_abToothType[udtChannelName]) == CAMHAL_bLONG_TOOTH)
            {
               CAMHAL_au8Position[udtChannelName] = CAMHAL_udtPOSITION_5;
               CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][1];
            }
            else
            {
               CAMHAL_au8Position[udtChannelName] = CAMHAL_udtPOSITION_1;
               CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][2];
            }
            CAMHAL_aenuPatternStatus[udtChannelName] =
               CAMHAL_udtPATTERN_DETECTED;
         }
      }
      else
      {
         CAMHAL_au8Position[udtChannelName] =
            (uint8)CAMHAL_udtCALC_POSITION(CAMHAL_au8Position[udtChannelName],
                                           CAMHAL_abToothType[udtChannelName],
                                           bLocalInputCamshaftLevel);
      }
      if (  CAMHAL_aenuPatternStatus[udtChannelName]
         == CAMHAL_udtPATTERN_DETECTED)
      {
         /* !Comment: Detect Cylinder                                         */
         switch (CAMHAL_au8Position[udtChannelName])
         {
            case CAMHAL_udtPOSITION_4:
               CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][0];
               bLocalCamPeriodAvailable = (boolean)TRUE;
               break;

            case CAMHAL_udtPOSITION_5:
               CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][1];
               bLocalCamPeriodAvailable = (boolean)TRUE;
               break;

            case CAMHAL_udtPOSITION_6:
               CAMHAL_aenuLastCylinderNumber[udtChannelName] =
                  CAMHAL_kau8PatternCylinders[udtChannelName][2];
               bLocalCamPeriodAvailable = (boolean)TRUE;
               break;

            default:
               break;
         }

         if (bLocalCamPeriodAvailable == (boolean)TRUE)
         {
            /* !Comment: Reload of Timeout detection */
            CAMHAL_au8RunningTimeoutCnt[udtChannelName] =
               CAMHAL_kau8RunningThreshold[udtChannelName];

            /* !Comment: Camshaft Period computation                          */
            if ((CAMHAL_au32LastEventTime[udtChannelName]) != UINT32_MIN)
            {
               u32LocalCamToothPeriod =
                  (uint32)(((u32EdgeTime) - CAMHAL_au32LastEventTime[udtChannelName]) & CAMHAL_u32TIMER_MAX_LIMIT);
               /*CAMHAL_au32CamToothPeriod[udtChannelName] =   (uint32) (u32LocalCamToothPeriod);*/
               CAMHAL_au32CamToothPeriod[udtChannelName] =
                     (uint32) ((u32LocalCamToothPeriod * CAMHAL_u16COEF_TIMER_RESOL)
                              / CAMHAL_u16COEF_DESIRED_RESOL);
            }

            CAMHAL_au32LastEventTime[udtChannelName] = u32EdgeTime;

            /* !Comment: Detection of CAM Running                             */
            if (  (  CAMHAL_au32CamToothPeriod[udtChannelName]
                  <= ((uint32)( CAMHAL_kau8RunningThreshold[udtChannelName]
                              * CAMHAL_u16TIMEOUT_DETECT_RESOL)))
               && (CAMHAL_abRunning[udtChannelName] == (boolean)FALSE))
            {
               CAMHAL_abRunning[udtChannelName] = (boolean)TRUE;
               if ((CAMHAL_abEvtActivationEnabled[udtChannelName]) == (boolean)TRUE)
               {
                  TSKSRV_vidActivateTask(CAMHAL_STALL_TO_RUN_EVENT);
               }
            }

            /* !Comment: Event CAM                                            */
            if ((CAMHAL_abRunning[udtChannelName]) != (boolean)FALSE)
            {
               CAMHAL_vidActivateCamEvent(udtChannelName);
            }

            /* !Comment: Angle Position of teeth package starts               */
            udtLocalStatus = CRKHAL_udtReadStatus(CRKHAL_u8SYNCHRONISED,
                                                  &bLocalCrkSynchronised);
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
            /* !Comment: Check pattern coherency */
            CAMHAL_vidPatternManagement(udtChannelName);

            if (CAMHAL_abEvtActivationEnabled[udtChannelName] == (boolean)TRUE)
            {
               /*CAMHAL_vidAngClkGenManager();*/
            }
         }
         else
         {
            if ( ( CAMHAL_au8Position[udtChannelName]
                 != CAMHAL_au8ExpectedPosition[udtChannelName])
               && ( CAMHAL_au8ExpectedPosition[udtChannelName]
                  != CAMHAL_udtPOSITION_INIT))
            {
               /* !Comment: Call CAMHAL_vidPatternManagement in case of */
               /* default detected, to run pattern diagnosis            */
               CAMHAL_vidPatternManagement(udtChannelName);
            }
            else
            {
               CAMHAL_vidEXPECT_NEXT_POSITION(udtChannelName);
            }
         }
      }
      CAMHAL_abPreviousToothType[udtChannelName] =
         CAMHAL_abToothType[udtChannelName];
      CAMHAL_au32LastToothDuration[udtChannelName] = u32LocalToothDuration;
   }
   CAMHAL_au32PreviousEdgeTime[udtChannelName] = u32EdgeTime;
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidPSA_3CYL_PatternMng                               */
/* !Description : The function runs the pattern management for PSA CAMHAL     */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidPSA_3CYL_PatternMng
(
   CAMHAL_tudtChannel udtChannelName,
   boolean* pbFaultExist
)
{

   if (  (  CAMHAL_au8Position[udtChannelName]
         != CAMHAL_au8ExpectedPosition[udtChannelName])
      && (  CAMHAL_au8ExpectedPosition[udtChannelName]
         != CAMHAL_udtPOSITION_INIT))
   {
      *pbFaultExist = (boolean)TRUE;
   }
   else
   {
      /* !MComment: Determination of the next expected pattern form           */
      /* !MComment: Determination of the next expected cylinder               */
      CAMHAL_vidEXPECT_NEXT_POSITION(udtChannelName);
      CAMHAL_vidGET_NEXT_CYLINDER_3(udtChannelName);
      *pbFaultExist = (boolean)FALSE;
   }
}

#endif /* (CAMHAL_bPSA_3CYL_ALLOWED == 1) */

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
