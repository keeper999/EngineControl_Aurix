/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_Api.c                                            */
/* !Description     : APIs definition of CAMHAL Component                     */
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
 * %PID: P2017_BSW:A81086.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CAMHAL_Cfg.h"
#include "CAMHAL_I.h"
#include "CAMHAL_gtm_cfg.h"
#include "CRKHAL.h"
#include "SWFAIL.h"
#include "CAMHAL.h"
#include "CAMHAL_I.h"
#include "CAMHAL_L.h"

#define CAMHAL_START_SEC_CODE
#include "CAMHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : CAMHAL_vidInit                                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidInit(void)
{
   uint8 u8LocalTmp;

   CAMHAL_bBackwardRotationDetected = (boolean)FALSE;

   for (u8LocalTmp = UINT8_MIN;
        (sint32)u8LocalTmp < (sint32)CAMHAL_udtCHANNELS_NUMBER;
        u8LocalTmp++)
   {
      /* !Comment: Disable acquisition input */
      CAMHAL_vidDisableInputAcq(u8LocalTmp);

      /* !Comment: Init for camshaft input level */
      CAMHAL_abNSNCamPosition[u8LocalTmp]       = STD_LOW;

      /* !Comment: Init for signal detection */
      CAMHAL_au32PreviousEdgeTime[u8LocalTmp]   = (uint32)UINT32_MIN;
      CAMHAL_au32LastEdgeDate[u8LocalTmp]       = (uint32)UINT32_MIN;
      CAMHAL_au32FirstToothDuration[u8LocalTmp] = (uint32)UINT32_MIN;
      CAMHAL_au32LastToothDuration[u8LocalTmp]  = (uint32)UINT32_MIN;
      CAMHAL_au32LastEventTime[u8LocalTmp]      = (uint32)UINT32_MIN;
      CAMHAL_abDetectionEnabled[u8LocalTmp]     = (boolean)FALSE;
      CAMHAL_vidSIGNAL_LOSS(u8LocalTmp);

      /* !Comment: Init for running/pattern detection */
      CAMHAL_vidRUN_TO_STALL(u8LocalTmp);

      /* !Comment: Init for synchronisation detection */
      CAMHAL_abSynchroEnabled[u8LocalTmp]       = (boolean)FALSE;
      CAMHAL_vidSYNC_LOSS(u8LocalTmp);

      CAMHAL_abEvtActivationEnabled[u8LocalTmp] = (boolean)FALSE;
      CAMHAL_au16EngineAngle[u8LocalTmp]        = (uint16)UINT16_MIN;
      CAMHAL_au16CylinderNbDate[u8LocalTmp]     = (uint16)UINT16_MAX;

      /* !Comment: Init for CAMHAL mode, by default the driver is NOT SET */
      CAMHAL_aenuMode[u8LocalTmp]               = CAMHAL_udtNOT_SET;

      CAMHAL_au16FallingEdgeCounter[u8LocalTmp] = (uint16)UINT16_MIN;
      CAMHAL_au16RisingEdgeCounter[u8LocalTmp] = (uint16)UINT16_MIN;
   }
   /* This is a stub for Alpha */
   /*CAMHAL_vidInitAngClkGen();*/
   CAMHAL_vidGtmInit();
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidSetMode                                           */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidSetMode
(
   CAMHAL_tudtChannel udtChannelName,
   CAMHAL_tenuMode enuMode
)
{
   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      switch (enuMode)
      {
         case CAMHAL_udtNORMAL_MODE:
            if (CAMHAL_aenuMode[udtChannelName] != CAMHAL_udtNORMAL_MODE)
            {
               switch (CAMHAL_kau16CamSynchroMode[udtChannelName])
               {
#if ( CAMHAL_bNSN_4CYL_ALLOWED ==1)
                  case CAMHAL_u16NSN_4CYL_CAMSHAFT:
                     CAMHAL_vidNSN_4CYL_SetMode(udtChannelName);
                     break;
#endif /* ( CAMHAL_bNSN_4CYL_ALLOWED ==1) */

#if ( CAMHAL_bRSA_STD_ALLOWED ==1)
                  case CAMHAL_u16RSA_STD_CAMSHAFT:
                     CAMHAL_vidRSA_STD_SetMode(udtChannelName);
                     break;
#endif /* ( CAMHAL_bRSA_STD_ALLOWED ==1) */

#if ( CAMHAL_bSTANDARD_ALLOWED ==1)
                  case CAMHAL_u16STANDARD_CAMSHAFT:
                     CAMHAL_vidSTANDARD_SetMode(udtChannelName);
                     break;
#endif /* ( CAMHAL_bSTANDARD_ALLOWED ==1) */

#if ( CAMHAL_bPSA_3CYL_ALLOWED ==1)
                  case CAMHAL_u16PSA_3CYL_CAMSHAFT:
                     CAMHAL_vidPSA_3CYL_SetMode(udtChannelName);
                     break;
#endif /*( CAMHAL_bPSA_3CYL_ALLOWED ==1) */

#if (CAMHAL_bPSA_4CYL_ALLOWED ==1)
                  case CAMHAL_u16PSA_4CYL_CAMSHAFT:
                     CAMHAL_vidPSA_4CYL_SetMode(udtChannelName);
                     break;
#endif /* (CAMHAL_bPSA_4CYL_ALLOWED ==1) */

                  default:
                     SWFAIL_vidSoftwareErrorHook();
                     break;
               }
            }
            break;

         case CAMHAL_udtDOWNGRADED_MODE:
            if (CAMHAL_aenuMode[udtChannelName] != CAMHAL_udtDOWNGRADED_MODE)
            {
               /* !Comment: Forcing Signal Loss when CAMHAL was in Normal Mode*/
               if(CAMHAL_aenuMode[udtChannelName] == CAMHAL_udtNORMAL_MODE)
               {
                  CAMHAL_vidDisableInputAcq(udtChannelName);
                  CAMHAL_vidForceSignalLoss(udtChannelName);
               }
               CAMHAL_aenuMode[udtChannelName] = CAMHAL_udtDOWNGRADED_MODE;

               /* !Comment: Callback for Downgraded Mode Entry */
               CAMHAL_vidDwnModeEntry(udtChannelName);
            }
            break;

         case CAMHAL_udtNOT_SET:
            if (CAMHAL_aenuMode[udtChannelName] != CAMHAL_udtNOT_SET)
            {
               /* !Comment: Forcing Signal Loss when CAMHAL was in Normal Mode*/
               if (CAMHAL_aenuMode[udtChannelName] == CAMHAL_udtNORMAL_MODE)
               {
                  CAMHAL_vidDisableInputAcq(udtChannelName);
                  CAMHAL_vidForceSignalLoss(udtChannelName);
               }
               CAMHAL_aenuMode[udtChannelName] = CAMHAL_udtNOT_SET;
            }
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtReadMode                                          */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtReadMode
(
   CAMHAL_tudtChannel udtChannelName,
   CAMHAL_tenuMode* penuMode
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      *penuMode = CAMHAL_aenuMode[udtChannelName];
      udtLocalRetValue = E_OK;
   }
   else
   {
      *penuMode = CAMHAL_udtNOT_SET;
      udtLocalRetValue = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtReadStatus                                        */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtReadStatus
(
   CAMHAL_tudtChannel udtChannelName,
   uint8 u8ChannelStatus,
   boolean* pbStatus
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      if (CAMHAL_aenuMode[udtChannelName] == CAMHAL_udtNORMAL_MODE)
      {
         switch (u8ChannelStatus)
         {
            case CAMHAL_u8DETECTED:
               *pbStatus = CAMHAL_abDetected[udtChannelName];
               break;

            case CAMHAL_u8RUNNING:
               *pbStatus = CAMHAL_abRunning[udtChannelName];
               break;

            case CAMHAL_u8SYNCHRONISED:
            case CAMHAL_u8ENG_SYNCHRONISED:
               *pbStatus = CAMHAL_abSynchronised[udtChannelName];
               break;

            default:
               *pbStatus = (boolean)FALSE;
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         udtLocalRetValue = E_OK;
      }
      else
      {
         *pbStatus = (boolean)FALSE;
         udtLocalRetValue = E_NOT_OK;
      }
   }
   else
   {
      *pbStatus = FALSE;
      udtLocalRetValue = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtEnableDetection                                   */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtEnableDetection
(
   CAMHAL_tudtChannel udtChannelName
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      CAMHAL_abDetectionEnabled[udtChannelName] = (boolean)TRUE;
      udtLocalRetValue = E_OK;
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}


/******************************************************************************/
/* !FuncName    : CAMHAL_udtDisableDetection                                  */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtDisableDetection
(
   CAMHAL_tudtChannel udtChannelName
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      CAMHAL_abDetectionEnabled[udtChannelName] = (boolean)FALSE;
      udtLocalRetValue = E_OK;
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtEnableSynchronisation                             */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtEnableSynchronisation
(
   CAMHAL_tudtChannel udtChannelName
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      CAMHAL_abSynchroEnabled[udtChannelName] = (boolean)TRUE;
      udtLocalRetValue = E_OK;
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtDisableSynchronisation                            */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtDisableSynchronisation
(
   CAMHAL_tudtChannel udtChannelName
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      CAMHAL_abSynchroEnabled[udtChannelName] = (boolean)FALSE;
      udtLocalRetValue = E_OK;
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtForceDesynchronisation                            */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtForceDesynchronisation
(
   CAMHAL_tudtChannel udtChannelName
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      if (  (CAMHAL_aenuMode[udtChannelName] == CAMHAL_udtNORMAL_MODE)
         && (CAMHAL_abSynchronised[udtChannelName] == (boolean)TRUE))
      {
         CAMHAL_abDesynchroRequested[udtChannelName] = (boolean)TRUE;
         udtLocalRetValue = E_OK;
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
         CAMHAL_abDesynchroRequested[udtChannelName] = (boolean)FALSE;
      }
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtReadCylinderNumber                                */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtReadCylinderNumber
(
   CAMHAL_tudtChannel udtChannelName,
   CAMHAL_tenuCylinderNumber* penuCylinderNumber
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      if (CAMHAL_aenuMode[udtChannelName] == CAMHAL_udtNORMAL_MODE)
      {
         switch (CAMHAL_kau16CamSynchroMode[udtChannelName])
         {
#if ( CAMHAL_bNSN_4CYL_ALLOWED ==1)
            case CAMHAL_u16NSN_4CYL_CAMSHAFT:
               udtLocalRetValue =
                  CAMHAL_udtNSN_4CYL_ReadCylNum( udtChannelName,
                                                 penuCylinderNumber);
               break;
#endif /* ( CAMHAL_bNSN_4CYL_ALLOWED ==1) */

#if ( CAMHAL_bRSA_STD_ALLOWED ==1)
            case CAMHAL_u16RSA_STD_CAMSHAFT:
               udtLocalRetValue =
                  CAMHAL_udtRSA_STD_ReadCylNum( udtChannelName,
                                                 penuCylinderNumber);
               break;
#endif /* ( CAMHAL_bRSA_STD_ALLOWED ==1) */

#if ( CAMHAL_bSTANDARD_ALLOWED ==1)
            case CAMHAL_u16STANDARD_CAMSHAFT:
               udtLocalRetValue =
                  CAMHAL_udtSTANDARD_ReadCylNum( udtChannelName,
                                                 penuCylinderNumber);
               break;
#endif /* ( CAMHAL_bSTANDARD_ALLOWED ==1) */

#if ( CAMHAL_bPSA_3CYL_ALLOWED ==1)
            case CAMHAL_u16PSA_3CYL_CAMSHAFT:
               udtLocalRetValue =
                  CAMHAL_udtPSA_3CYL_ReadCylNum( udtChannelName,
                                                 penuCylinderNumber);
               break;
#endif /* ( CAMHAL_bPSA_3CYL_ALLOWED ==1) */

#if (CAMHAL_bPSA_4CYL_ALLOWED ==1)
            case CAMHAL_u16PSA_4CYL_CAMSHAFT:
               udtLocalRetValue =
                  CAMHAL_udtPSA_4CYL_ReadCylNum( udtChannelName,
                                                 penuCylinderNumber);
               break;
#endif /* (CAMHAL_bPSA_4CYL_ALLOWED ==1) */

            case CAMHAL_u16NO_CAMSHAFT:
               udtLocalRetValue = E_NOT_OK;
               *penuCylinderNumber = CAMHAL_udtUNKNOWN_CYLINDER;
               break;

            default:
               udtLocalRetValue = E_NOT_OK;
               *penuCylinderNumber = CAMHAL_udtUNKNOWN_CYLINDER;
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
         *penuCylinderNumber = CAMHAL_udtUNKNOWN_CYLINDER;
      }
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      *penuCylinderNumber = CAMHAL_udtUNKNOWN_CYLINDER;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtReadToothPeriod                                   */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtReadToothPeriod
(
   CAMHAL_tudtChannel udtChannelName,
   uint32* pu32Period
)
{
   uint32         u32LocalCamToothPeriod;
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      u32LocalCamToothPeriod = (CAMHAL_au32CamToothPeriod[udtChannelName]);
      if (  (CAMHAL_aenuMode[udtChannelName] == CAMHAL_udtNORMAL_MODE)
         && (u32LocalCamToothPeriod != (uint32)UINT32_MAX))
      {
         *pu32Period = u32LocalCamToothPeriod;
         udtLocalRetValue = E_OK;
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
         *pu32Period = (uint32)UINT32_MAX;
      }
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      *pu32Period = (uint32)UINT32_MAX;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtReadSignalLevel                                   */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtReadSignalLevel
(
   CAMHAL_tudtChannel udtChannelName,
   boolean* pbLevel
)
{
   Std_ReturnType udtLocalRetValue;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      if (CAMHAL_aenuMode[udtChannelName] == CAMHAL_udtNORMAL_MODE)
      {
         switch (CAMHAL_kau16CamSynchroMode[udtChannelName])
         {
#if ( CAMHAL_bNSN_4CYL_ALLOWED ==1)
            case CAMHAL_u16NSN_4CYL_CAMSHAFT:
               udtLocalRetValue = CAMHAL_udtNSN_4CYL_ReadSigLvl( udtChannelName,
                                                                 pbLevel);
               break;
#endif /* ( CAMHAL_bNSN_4CYL_ALLOWED ==1) */

#if ( CAMHAL_bRSA_STD_ALLOWED ==1)
            case CAMHAL_u16RSA_STD_CAMSHAFT:
               udtLocalRetValue = CAMHAL_udtRSA_STD_ReadSigLvl( udtChannelName,
                                                                 pbLevel);
               break;
#endif /* ( CAMHAL_bRSA_STD_ALLOWED ==1) */

#if ( CAMHAL_bSTANDARD_ALLOWED ==1)
            case CAMHAL_u16STANDARD_CAMSHAFT:
               udtLocalRetValue = CAMHAL_udtSTANDARD_ReadSigLvl( udtChannelName,
                                                                 pbLevel);
               break;
#endif /* ( CAMHAL_bSTANDARD_ALLOWED ==1) */

#if ( CAMHAL_bPSA_3CYL_ALLOWED ==1)
            case CAMHAL_u16PSA_3CYL_CAMSHAFT:
               udtLocalRetValue = CAMHAL_udtPSA_3CYL_ReadSigLvl( udtChannelName,
                                                                 pbLevel);
               break;
#endif /* ( CAMHAL_bPSA_3CYL_ALLOWED ==1) */

#if ( CAMHAL_bPSA_4CYL_ALLOWED ==1)
            case CAMHAL_u16PSA_4CYL_CAMSHAFT:
               udtLocalRetValue = CAMHAL_udtPSA_4CYL_ReadSigLvl( udtChannelName,
                                                                 pbLevel);
               break;
#endif /* ( CAMHAL_bPSA_4CYL_ALLOWED ==1) */

            case CAMHAL_u16NO_CAMSHAFT:
               udtLocalRetValue = E_NOT_OK;
               *pbLevel = STD_LOW;
               break;

            default:
               udtLocalRetValue = E_NOT_OK;
               *pbLevel = STD_LOW;
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
         *pbLevel = STD_LOW;
      }
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      *pbLevel = STD_LOW;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtReadEventPosition                                 */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtReadEventPosition
(
   CAMHAL_tudtChannel udtChannelName,
   uint16* pu16Position
)
{
   CRKHAL_tenuMode enuLocalCrkMode;
   Std_ReturnType  udtLocalStatus;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      udtLocalStatus = CRKHAL_udtReadMode(&enuLocalCrkMode);

      if (  (udtLocalStatus == E_OK)
         && (CAMHAL_aenuMode[udtChannelName] == CAMHAL_udtNORMAL_MODE)
         && (enuLocalCrkMode == CRKHAL_udtNORMAL_MODE)
         && (CAMHAL_abEvtPositionAvailable[udtChannelName] == (boolean)TRUE))
      {
         udtLocalStatus = E_OK;
         *pu16Position = CAMHAL_au16EngineAngle[udtChannelName];
      }
      else
      {
         udtLocalStatus = E_NOT_OK;
         *pu16Position = (uint16)UINT16_MIN;
      }
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
      *pu16Position = (uint16)UINT16_MIN;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalStatus);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtEnableEvtActivation                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtEnableEvtActivation
(
   CAMHAL_tudtChannel udtChannelName
)
{
   Std_ReturnType  udtLocalStatus;
   boolean         bLocalTmp;
   uint8           u8LocalTmp;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      bLocalTmp = (boolean)FALSE;
      for (u8LocalTmp = (uint8)UINT8_MIN;
           (sint32)u8LocalTmp < (sint32)CAMHAL_udtCHANNELS_NUMBER;
           u8LocalTmp++)
      {
         if (CAMHAL_abEvtActivationEnabled[u8LocalTmp] == (boolean)TRUE)
         {
            bLocalTmp = (boolean)TRUE;
         }
      }
      if (bLocalTmp == (boolean)FALSE)
      {
         CAMHAL_abEvtActivationEnabled[udtChannelName] = (boolean)TRUE;
         CAMHAL_udtEvtActivationChannel = udtChannelName;

         /* todo: store the expected Cam Profile into the DPLL RAM1c for post alpha*/
         /*vidStoreCamProfileIntoDpll(CAMHAL_kau16CamSynchroMode[udtChannelName]);*/
         udtLocalStatus = E_OK;
      }
      else
      {
         udtLocalStatus = E_NOT_OK;
      }
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(udtLocalStatus);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtDisableEvtActivation                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtDisableEvtActivation(void)
{
   uint8 u8LocalTmp;

   for (u8LocalTmp = (uint8)UINT8_MIN;
        (sint32)u8LocalTmp < (sint32)CAMHAL_udtCHANNELS_NUMBER;
        u8LocalTmp++)
   {
      CAMHAL_abEvtActivationEnabled[u8LocalTmp] = (boolean)FALSE;
   }
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CAMHAL_vidSetTrueEdgePos                                    */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CAMHAL_vidSetTrueEdgePos
(
   CAMHAL_tudtChannel udtChannelName,
   uint16* pau16CamEdgePositionTable
)
{

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      CAMHAL_au16EdgeAnglePosition_1[udtChannelName] =
         pau16CamEdgePositionTable[0];
      CAMHAL_au16EdgeAnglePosition_2[udtChannelName] =
         pau16CamEdgePositionTable[1];
      CAMHAL_au16EdgeAnglePosition_3[udtChannelName] =
         pau16CamEdgePositionTable[2];

      if(CAMHAL_u8NUMBER_OF_CYLINDERS == CAMHAL_u8FOUR_CYLINDERS)
      {
         CAMHAL_au16EdgeAnglePosition_4[udtChannelName] =
            pau16CamEdgePositionTable[3];
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !FuncName    : CAMHAL_udtGetEdgeCounter                                    */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CAMHAL_udtGetEdgeCounter
(
   CAMHAL_tudtChannel udtChannelName,
   boolean bEdgeType,
   uint16* pu16EdgeCount
)
{
   Std_ReturnType  udtLocalStatus;

   if (udtChannelName < (sint32)CAMHAL_udtCHANNELS_NUMBER)
   {
      if (bEdgeType == CAMHAL_bRISING_EDGE)
      {
         *pu16EdgeCount = CAMHAL_au16RisingEdgeCounter[udtChannelName];
      }
      else
      {
         *pu16EdgeCount = CAMHAL_au16FallingEdgeCounter[udtChannelName];
      }
      udtLocalStatus = E_OK;
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
      *pu16EdgeCount = (uint16)UINT16_MIN;
      SWFAIL_vidSoftwareErrorHook();
   }

   return(udtLocalStatus);
}

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
