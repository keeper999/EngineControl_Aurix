/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_1.c                                              */
/* !Description     : General sub-functions of the CAMHAL Component           */
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
 * %PID: P2017_BSW:A81083.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CAMHAL_CFG.h"
#include "CAMHAL_I.h"
#include "CRKHAL.h"
#include "TSKSRV.h"
#include "CAMHAL.h"
#include "CAMHAL_L.h"
#include "SchM_CAMHAL.h"
#include "CAMHAL_gtm_cfg.h"

#define CAMHAL_START_SEC_CODE
#include "CAMHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : CAMHAL_vidCaptureManagement                                 */
/* !Description : Call back function when the edge is detected                */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidCaptureManagement
(
   CAMHAL_tudtChannel udtChannelName
)
{
   uint32  u32LocalEdgeTime;
   boolean bLocalEdgeType;

   if (  (  (CAMHAL_abDetectionEnabled[udtChannelName] != (boolean)FALSE)
         || (CAMHAL_abDetected[udtChannelName] != (boolean)FALSE))
      && (CAMHAL_bBackwardRotationDetected == (boolean)FALSE))
   {
/*
      u32LocalEdgeTime = ( ((CAMHAL_u32EdgeTimeRead(udtChannelName)) * CAMHAL_u16COEF_TIMER_RESOL)
                           / CAMHAL_u16COEF_DESIRED_RESOL );
*/
     /* in 100ns, to take care of the 24 bit limit */
     u32LocalEdgeTime = CAMHAL_u32EdgeTimeRead(udtChannelName) + CAMHAL_TBU_OFFSET;
      CAMHAL_au8DetectedTimeoutCnt[udtChannelName] =
         CAMHAL_kau8DetectedThreshold[udtChannelName];

      /* !Comment: Edges counter management */
      bLocalEdgeType = CAMHAL_bDioRead(udtChannelName);

      if (bLocalEdgeType == STD_LOW)
      {
         CAMHAL_au16FallingEdgeCounter[udtChannelName]++;
      }
      else
      {
         CAMHAL_au16RisingEdgeCounter[udtChannelName]++;
      }
/*
For Beta Rel Start
      if (...RMO!=1) {
      uint8 u8EdgeCtn = (uint8) (CAMHAL_au16AllEdgesCounter[udtChannelName]);
      CAMHAL_u16CamEdgeAngles[udtChannelName][u8EdgeCtn] = angleValueOnEdge;
      CAMHAL_au16AllEdgesCounter[udtChannelName] = (u8EdgeCtn + 1) % 6;
For Beta Rel Stop
*/
      CAMHAL_vidActivateCamEdgeEvent(udtChannelName);

      switch (CAMHAL_kau16CamSynchroMode[udtChannelName])
      {
#if ( CAMHAL_bNSN_4CYL_ALLOWED == 1)
         case CAMHAL_u16NSN_4CYL_CAMSHAFT:
            CAMHAL_vidNSN_4CYL_CaptureMng(udtChannelName, u32LocalEdgeTime);
            break;
#endif /* ( CAMHAL_bNSN_4CYL_ALLOWED == 1) */

#if ( CAMHAL_bRSA_STD_ALLOWED == 1)
         case CAMHAL_u16RSA_STD_CAMSHAFT:
            CAMHAL_vidRSA_STD_CaptureMng(udtChannelName, u32LocalEdgeTime);
            break;
#endif /* ( CAMHAL_bRSA_STD_ALLOWED == 1) */

#if ( CAMHAL_bSTANDARD_ALLOWED == 1)
         case CAMHAL_u16STANDARD_CAMSHAFT:
            CAMHAL_vidSTANDARD_CaptureMng(udtChannelName, u32LocalEdgeTime);
            break;
#endif /* ( CAMHAL_bSTANDARD_ALLOWED == 1) */

#if ( CAMHAL_bPSA_3CYL_ALLOWED == 1)
         case CAMHAL_u16PSA_3CYL_CAMSHAFT:
            CAMHAL_vidPSA_3CYL_CaptureMng(udtChannelName, u32LocalEdgeTime);
            break;
#endif /* ( CAMHAL_bPSA_3CYL_ALLOWED == 1) */

#if ( CAMHAL_bPSA_4CYL_ALLOWED == 1)
         case CAMHAL_u16PSA_4CYL_CAMSHAFT:
            CAMHAL_vidPSA_4CYL_CaptureMng(udtChannelName, u32LocalEdgeTime);
            break;
#endif /* ( CAMHAL_bPSA_4CYL_ALLOWED == 1) */

         case CAMHAL_u16NO_CAMSHAFT:
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
   else
   {
      CAMHAL_abEnableCaptMng[udtChannelName]        = (boolean)FALSE;
      CAMHAL_au8EventCounter[udtChannelName]        = (uint8)UINT8_MIN;
      CAMHAL_abFirstCamPeriod[udtChannelName]       = (boolean)TRUE;
      CAMHAL_abEvtPositionAvailable[udtChannelName] = (boolean)FALSE;
      CAMHAL_abPreviousGap[udtChannelName]          = (boolean)FALSE;
   }
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidTimeoutDetection                                  */
/* !Description : The function which runs the Time out detection              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidTimeoutDetection(void)
{
   uint8 u8LocalTmp;

   for (u8LocalTmp = (uint8)UINT8_MIN;
        (sint32)u8LocalTmp < (sint32)CAMHAL_udtCHANNELS_NUMBER;
        u8LocalTmp++)
   {
      if (CAMHAL_aenuMode[u8LocalTmp] == CAMHAL_udtNORMAL_MODE)
      {
         if (CAMHAL_au8RunningTimeoutCnt[u8LocalTmp] != (uint8)UINT8_MIN)
         {
            SchM_Enter_CAMHAL_ACCESS_001();
            CAMHAL_au8RunningTimeoutCnt[u8LocalTmp]--;
            SchM_Exit_CAMHAL_ACCESS_001();

         }
         else
         {
            if (CAMHAL_abEvtActivationEnabled[u8LocalTmp] == (boolean)TRUE)
            {
               if (CAMHAL_abRunning[u8LocalTmp] != (boolean)FALSE)
               {
                  TSKSRV_vidActivateTask(CAMHAL_RUN_TO_STALL_EVENT);
               }
               if (CAMHAL_abSynchronised[u8LocalTmp] != (boolean)FALSE)
               {
                  CAMHAL_vidSyncLossEntry(u8LocalTmp);
                  TSKSRV_vidActivateTask(CAMHAL_SYNC_LOSS_EVENT);
               }
            }
            CAMHAL_vidRUN_TO_STALL(u8LocalTmp);
            CAMHAL_vidSYNC_LOSS(u8LocalTmp);
         }
         if (CAMHAL_au8DetectedTimeoutCnt[u8LocalTmp] != (uint8)UINT8_MIN)
         {
            SchM_Enter_CAMHAL_ACCESS_002();
            CAMHAL_au8DetectedTimeoutCnt[u8LocalTmp]--;
            SchM_Exit_CAMHAL_ACCESS_002();
         }
         else
         {
            if (CAMHAL_abRunning[u8LocalTmp] == FALSE)
            {
               if (CAMHAL_abEvtActivationEnabled[u8LocalTmp] == TRUE)
               {
                  if (CAMHAL_abDetected[u8LocalTmp] != FALSE)
                  {
                     /* !Comment: CAMHAL_vidDisableAngClkGen shall be called */
                     /*           on E_CAMHAL_SIGNAL_LOSS                    */
                     /*CAMHAL_vidDisableAngClkGen();*/
                     TSKSRV_vidActivateTask(CAMHAL_SIGNAL_LOSS_EVENT);
                  }
               }
               CAMHAL_vidSIGNAL_LOSS(u8LocalTmp);
            }
         }
      }
   }
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidPatternManagement                                 */
/* !Description : The function which runs the pattern management              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidPatternManagement
(
   CAMHAL_tudtChannel udtChannelName
)
{
   boolean bLocalFaultExist;

   /* Test and Update expected values for next cycle test. */
   switch (CAMHAL_kau16CamSynchroMode[udtChannelName])
   {
#if ( CAMHAL_bNSN_4CYL_ALLOWED == 1)
      case CAMHAL_u16NSN_4CYL_CAMSHAFT:
         CAMHAL_vidNSN_4CYL_PatternMng(udtChannelName, &bLocalFaultExist);
         break;
#endif /* ( CAMHAL_bNSN_4CYL_ALLOWED == 1) */

#if ( CAMHAL_bRSA_STD_ALLOWED == 1)
      case CAMHAL_u16RSA_STD_CAMSHAFT:
         CAMHAL_vidRSA_STD_PatternMng(udtChannelName, &bLocalFaultExist);
         break;
#endif /* ( CAMHAL_bRSA_STD_ALLOWED == 1) */

#if ( CAMHAL_bPSA_3CYL_ALLOWED == 1)
      case CAMHAL_u16PSA_3CYL_CAMSHAFT:
         CAMHAL_vidPSA_3CYL_PatternMng(udtChannelName, &bLocalFaultExist);
         break;
#endif /* ( CAMHAL_bPSA_3CYL_ALLOWED == 1) */

#if ( CAMHAL_bPSA_4CYL_ALLOWED == 1)
      case CAMHAL_u16PSA_4CYL_CAMSHAFT:
         CAMHAL_vidPSA_4CYL_PatternMng(udtChannelName, &bLocalFaultExist);
         break;
#endif /* ( CAMHAL_bPSA_4CYL_ALLOWED == 1) */

      default:
         bLocalFaultExist = (boolean)TRUE;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   /* !MComment: Pattern Diagnosis */
   if (CAMHAL_abRunning[udtChannelName] != (boolean)FALSE)
   {
      if (  CAMHAL_aenuPatternDiagStatus[udtChannelName]
         != CAMHAL_udtPATTERN_DIAG_DISABLED)
      {
         if (bLocalFaultExist == (boolean)TRUE)
         {
            CAMHAL_vidDgoWriteFault(udtChannelName);

            /* !Comment: Diagnosis is disabled on the next package */
            CAMHAL_aenuPatternDiagStatus[udtChannelName] =
               CAMHAL_udtPATTERN_DIAG_DISABLED;
         }
         else
         {
            CAMHAL_vidDgoWriteNoFault(udtChannelName);
            CAMHAL_aenuPatternDiagStatus[udtChannelName] = CAMHAL_udtPATTERN_DIAG_OK;
         }
      }
      else
      {
         /* !Comment: Diagnosis is enabled because the expected cylinder has */
         /*           been determined                                        */
         CAMHAL_aenuPatternDiagStatus[udtChannelName] =
            CAMHAL_udtPATTERN_DIAG_NOT_READY;
      }

      /* !MComment: Synchronisation management and event tasks activation */
      if (  CAMHAL_aenuPatternDiagStatus[udtChannelName]
         == CAMHAL_udtPATTERN_DIAG_OK)
      {
         if(CAMHAL_abSynchronised[udtChannelName] == (boolean)FALSE)
         {
            if (  (CAMHAL_abSynchroEnabled[udtChannelName] != (boolean)FALSE)
               && (  (CAMHAL_bENG_SYNC_ON_ANY_CYL == TRUE)
                  || (CAMHAL_aenuCylinderNumber[udtChannelName] ==
                         CAMHAL_kau8SynchroCylinders[udtChannelName][0])
                  || (CAMHAL_aenuCylinderNumber[udtChannelName] ==
                         CAMHAL_kau8SynchroCylinders[udtChannelName][1])))
            {
               CAMHAL_abSynchronised[udtChannelName] = (boolean)TRUE;
               if ((CAMHAL_abEvtActivationEnabled[udtChannelName]) == (boolean)TRUE)
               {
                  /*CAMHAL_vidSynchroniseAngClkGen();*/
                  TSKSRV_vidActivateTask(CAMHAL_FIRST_SYNC_EVENT);
                  TSKSRV_vidActivateTask(CAMHAL_SYNC_CONTROL_EVENT);
                  /*todo: what is the purpose of this? Are we supposed to
                   * enable the ANGSCHED alarm?
                   */
                  /*ANGSCHED_vidEnable(CAMHAL_u8ANGSCHED_ALARM);*/
               }
            }
         }
         else
         {
            if (CAMHAL_abDesynchroRequested[udtChannelName] != (boolean)FALSE)
            {
               CAMHAL_vidSYNC_LOSS(udtChannelName);
               if (CAMHAL_abEvtActivationEnabled[udtChannelName] == (boolean)TRUE)
               {
                  CAMHAL_vidSyncLossEntry(udtChannelName);
                  TSKSRV_vidActivateTask(CAMHAL_SYNC_LOSS_EVENT);
               }
            }
         }
      }
      else
      {
         if (  CAMHAL_aenuPatternDiagStatus[udtChannelName]
            == CAMHAL_udtPATTERN_DIAG_DISABLED)
         {
            if (  (CAMHAL_abEvtActivationEnabled[udtChannelName] == (boolean)TRUE)
               && (CAMHAL_abSynchronised[udtChannelName] != (boolean)FALSE))
            {
               CAMHAL_vidSyncLossEntry(udtChannelName);
               TSKSRV_vidActivateTask(CAMHAL_SYNC_LOSS_EVENT);
            }
            CAMHAL_vidSYNC_LOSS(udtChannelName);
         }
      }
   }
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidForceSignalLoss                                   */
/* !Description : The function which forces the Synch loss                    */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidForceSignalLoss
(
   CAMHAL_tudtChannel udtChannelName
)
{
   if (CAMHAL_abEvtActivationEnabled[udtChannelName] == (boolean)TRUE)
   {
      if (CAMHAL_abRunning[udtChannelName] != (boolean)FALSE)
      {
         TSKSRV_vidActivateTask(CAMHAL_RUN_TO_STALL_EVENT);
      }
      if (CAMHAL_abSynchronised[udtChannelName] != (boolean)FALSE)
      {
         CAMHAL_vidSyncLossEntry(udtChannelName);
         TSKSRV_vidActivateTask(CAMHAL_SYNC_LOSS_EVENT);
      }
   }

   CAMHAL_vidRUN_TO_STALL(udtChannelName);
   CAMHAL_vidSYNC_LOSS(udtChannelName);

   if (CAMHAL_abEvtActivationEnabled[udtChannelName] == (boolean)TRUE)
   {
      if (CAMHAL_abDetected[udtChannelName] != (boolean)FALSE)
      {
         /* !Comment: CAMHAL_vidDisableAngClkGen shall be called */
         /*           on E_CAMHAL_SIGNAL_LOSS                    */
         /*CAMHAL_vidDisableAngClkGen();*/
         TSKSRV_vidActivateTask(CAMHAL_SIGNAL_LOSS_EVENT);
      }
   }
   CAMHAL_vidSIGNAL_LOSS(udtChannelName);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_enuGetCylinder                                       */
/* !Description : The function gets the next cylinder and the current one     */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
CAMHAL_tenuCylinderNumber CAMHAL_enuGetCylinder
(
   CAMHAL_tudtChannel udtChannelName
)
{
   CAMHAL_tenuCylinderNumber enuLocalCylinder;
   boolean                   bLocalCamPosition;

   bLocalCamPosition = CAMHAL_bDioRead(udtChannelName);
   if (bLocalCamPosition == STD_HIGH)
   {
      enuLocalCylinder = CAMHAL_kau8SynchroCylinders[udtChannelName][0];
   }
   else
   {
      enuLocalCylinder = CAMHAL_kau8SynchroCylinders[udtChannelName][1];
   }
   return(enuLocalCylinder);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidDisableInputAcq                                   */
/* !Description : The function Disables the TIM channel aqusitions            */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidDisableInputAcq
(
   CAMHAL_tudtChannel udtChannelName
)
{
   /* !Comment: Disable acquisition input */
   CRKHAL_vidDisableAlarmNotif(CAMHAL_kau8CrkAlarm[udtChannelName]);
   CRKHAL_vidDeactivateAlarmMode(CAMHAL_kau8CrkAlarm[udtChannelName]);
}

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
