/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CRKHAL                                                  */
/* !Description     : CRKHAL Component                                        */
/*                                                                            */
/* !File            : CRKHAL_API.c                                            */
/* !Description     : APIs of CRKHAL Component                                */
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
 * %PID: P2017_BSW:A18542.A-SRC;11 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CAMHAL.h"
#include "CRKHAL_CFG_I.h"
#include "CRKHAL_CO_CFG.h"
#include "SchM_CRKHAL.h"
#include "IfxGtm_Tbu_dpll.h"
#include "IfxGtm_Ccu.h"
#include "CRKHAL_L.h"
#include "mcs0.h"
#include "SWFAIL.h"
#include "TDCHAL.h"
#include "KRN.h"

/*lint -save -e927 */
/*lint -save -e928 */
/*lint -esym(960,5.1) */
/*lint -esym(960,17.4) */
/*lint -esym(960,11.5) */
/*lint -esym(960,19.5) */
/*lint -esym(960,8.7) */


#ifndef CRKHAL_coBIDIR_PULSE_DIAG
   #error The macro-constant CRKHAL_coBIDIR_PULSE_DIAG shall be defined
#endif
#ifndef CRKHAL_coLOW_RPM_DESYNCHRO
   #error The macro-constant CRKHAL_coLOW_RPM_DESYNCHRO shall be defined
#endif
#ifndef CRKHAL_coENABLED
   #error The macro-constant CRKHAL_coENABLED shall be defined
#endif

#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : CRKHAL_vidInit                                              */
/* !Description : Initialization of CRKHAL component                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void CRKHAL_vidInit(void)
{
   CRKHAL_vidRUN_TO_STALL();
   CRKHAL_bBwdRotationPhase        = (boolean)FALSE;
   CRKHAL_bChangeOfMindEnabled     = (boolean)FALSE;
   CRKHAL_bDesynchroForcee         = (boolean)FALSE;
   CRKHAL_bDesynchroThdEnabled     = (boolean)FALSE;
   CRKHAL_bDetected                = (boolean)FALSE;
   CRKHAL_bDetection               = (boolean)FALSE;
   CRKHAL_bEnaBwdRotationDetection = (boolean)FALSE;
   CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
   CRKHAL_bEnaStopPosAfterCalc     = (boolean)FALSE;
   CRKHAL_bEngPositionKnown        = (boolean)FALSE;
   CRKHAL_bEngSynchronized         = (boolean)FALSE;
   CRKHAL_bMcsFirstEdge            = (boolean)TRUE;
   CRKHAL_bQuickSynchroEnabled     = (boolean)FALSE;
   CRKHAL_bRestartPhase            = (boolean)FALSE;
   CRKHAL_bRunning                 = (boolean)FALSE;
   CRKHAL_bSingularityDetected     = (boolean)FALSE;
   CRKHAL_bChangeOfDirTaskEvent    = (boolean)FALSE;
   CRKHAL_bSynchroEnable           = (boolean)FALSE;
   CRKHAL_bSynchronized            = (boolean)FALSE;

   CRKHAL_u16OffsetInjDriver = (uint16)UINT16_MIN;
   CRKHAL_vidINIT_INJ_OFFSETS();

   CRKHAL_u32LongToothMaxDuration = (uint32)UINT32_MAX;
   CRKHAL_enuCylinderNumber       = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER;

   CRKHAL_u16NumOfMissingTooth  = (uint16)UINT16_MIN;
   CRKHAL_u16NumOfToothInExcess = (uint16)UINT16_MIN;
   CRKHAL_u16NumOfSyncLoss      = (uint16)UINT16_MIN;

   /* Initialise Tooth Duration Array Address */
   CRKHAL_TOOTH_DUR_ARRAY = (uint32 *)(IFX_GTM_BASE
                                       + DPLL_RAM2_OFFSET
                                       + DT_T_OFFSET);

   /* Initialise Tooth Duration Array Address */
   CRKHAL_TOOTH_TIME_STAMP_ARRAY = (uint32 *)(IFX_GTM_BASE
                                              + DPLL_RAM2_OFFSET
                                              + TSF_T_OFFSET);

   /*! Adapt Value x for All Increments */
   CRKHAL_ADT_Tx = (uint32 *)(IFX_GTM_BASE + RAM_2b_OFFSET + ADT_T_OFFSET);

   CRKHAL_u16BegFirstLongToothPos = (uint16)(CRKHAL_u16NORMAL_TOOTH_ANGLE * ( (uint32)CRKHAL_u16NbPhysTeeth) );

   CRKHAL_u16BegSecondLongToothPos = (uint16)(CRKHAL_u16NORMAL_TOOTH_ANGLE
                                              * (CRKHAL_u8LONG_TOOTH_SIZE
                                                 + (uint32)(2U * ( (uint32)CRKHAL_u16NbPhysTeeth) ) ) );

   CRKHAL_u32NumberOfMlt_Half = (uint32)CRKHAL_u16NORMAL_TOOTH_ANGLE
                                * (CRKHAL_ku16NbPhysTeeth
                                   + (uint16)CRKHAL_udtNUM_GAP_TEETH);

   CRKHAL_u32NumberOfMlt_Full = (uint32)CRKHAL_u32NumberOfMlt_Half
                                * (uint32)CRKHAL_udtNUM_CYCLE;

   CRKHAL_u32NumberOfMlt_Tdc = (uint32)CRKHAL_ku16TDC_1_Angle;
   /* 57 for 58 - 2 Profile*/
   CRKHAL_u16PhyTeeth1Minus = (uint16)(CRKHAL_ku16NbPhysTeeth - 1U);
   /* 59 for 58 - 2 Profile*/
   CRKHAL_u16PhyTeeth1Plus = (uint16)(CRKHAL_ku16NbPhysTeeth + 1U);
   /* 60 for 58 - 2 Profile*/
   CRKHAL_u16EndFirstLongTooth = (uint16)(CRKHAL_ku16NbPhysTeeth
                                          + CRKHAL_u8LONG_TOOTH_SIZE);
   /* 116 for 58 - 2 Profile*/
   CRKHAL_u16PhyTeethFullScale = (uint16)(CRKHAL_ku16NbPhysTeeth
                                          * (uint16)CRKHAL_udtNUM_CYCLE);
   /* 115 for 58 - 2 Profile*/
   CRKHAL_u16PhyTeethFullScale1Ms = (uint16)( (CRKHAL_ku16NbPhysTeeth
                                               * (uint16)CRKHAL_udtNUM_CYCLE) - 1U);
   /* 117 for 58 - 2 Profile*/
   CRKHAL_u16PhyTeethFullScale1Ps = (uint16)( (CRKHAL_ku16NbPhysTeeth
                                               * (uint16)CRKHAL_udtNUM_CYCLE) + 1U);
   /* 118 for 58 - 2 Profile*/
   CRKHAL_u16BegSecondLongTooth = CRKHAL_u16PhyTeethFullScale + CRKHAL_u8LONG_TOOTH_SIZE;

   CRKHAL_bStopPosCalculation = (boolean)FALSE;
   CRKHAL_bFirstLtoo1Event    = (boolean)TRUE;

   CRKHAL_bLtooFaultOccur = (boolean)FALSE;
   CRKHAL_bAptPtrReset    = (boolean)FALSE;

   CRKHAL_ubNutcCheck            = (boolean)FALSE;
   CRKHAL_ubGliLockStatus        = (boolean)FALSE;
   CRKHAL_u8Apt2c                = (uint8)UINT8_MIN;
   CRKHAL_u8FwdTeeth             = (uint8)UINT8_MIN;
   CRKHAL_u16DeltaAngleOnSynchro = (uint16)UINT16_MIN;

   CRKHAL_u16EngineCycleAngle = (uint16)CRKHAL_ku16EngineCycleAngle;

   CRKHAL_u32OffCrkDly = ( ( (2U * CRKHAL_ku32OffCrkDly)
                             + (uint32)CRKHAL_u16CRK_OFF_TIMER_RESOL)
                           / (2U * (uint32)CRKHAL_u16CRK_OFF_TIMER_RESOL) )
                         - 1U;

   CRKHAL_u16NbPhysTeeth          = (uint16)CRKHAL_ku16NbPhysTeeth;
   CRKHAL_u16StopAngPosition      = (uint16)UINT16_MAX;
   CRKHAL_u16StopAngPositionAfter = (uint16)UINT16_MAX;

   CRKHAL_u32LongToothStalDetThd = (uint32)( ( ( (2U * (CRKHAL_ku32StalDetThd * 3U) )
                                                 + (uint32)CRKHAL_u16STALL_TIMER_RESOL)
                                               / (2U * (uint32)CRKHAL_u16STALL_TIMER_RESOL) )
                                             - 1U);

   CRKHAL_u32StalDetThd = ( ( ( (2U * CRKHAL_ku32StalDetThd)
                                + (uint32)CRKHAL_u16STALL_TIMER_RESOL)
                              / (2U * (uint32)CRKHAL_u16STALL_TIMER_RESOL) )
                            - 1U);

   /* Engine Run Threshold tooth duration at 100ns resolution */
   CRKHAL_u32EngRunThDuration = (uint32)( ( (uint32)CRKHAL_u32StalDetThd + 1U)
                                          * (uint32)CRKHAL_u16STALL_TIMER_RESOL);

   CRKHAL_u32ToothMaxDuration = (uint32)CRKHAL_u32StalDetThd;

   if ( ( (sint32)CRKHAL_ku8CrkInputSignal) < ( (sint32)CRKHAL_u8NB_INPUT_SGN) )
   {
      CRKHAL_u8CrkInputSignal = (uint8)CRKHAL_ku8CrkInputSignal;
   }
   else
   {
      CRKHAL_u8CrkInputSignal = (uint8)CRKHAL_u8DEFAULT_CRK_INPUT_SGN;
      SWFAIL_vidSoftwareErrorHook();
   }

   /* Initialisation of Capture Channels */
   CRKHAL_vidInitTimCh();
   /* Initialise Alarm channels*/
   CRKHAL_vidInitAlarmChannels();
   /* Disable Angle counter */
   CRKHAL_vidSetCfgAngCounter(TBU_DISABLE_CLR);
   /* Configuration of Angle Counter */
   CRKHAL_vidCFG_ANG_CNTR();
   /* Configuration of Capture Channels */
   /* Not for Noise configuration (Filter )*/
   CRKHAL_vidCfgSignalInTimer();
   /* MCS initialisation */
   CRKHAL_vidMcsInit();
   /* DPLL configuration */
   CRKHAL_vidDpllConfig();
   /* Crank profile configurations */
   CRKHAL_vidCrankProfileInit();

   CRKHAL_bDirectionChangeDet = FALSE;
   CRKHAL_bRotationDirection  = CRKHAL_bFWD_ROTATION;

#if (CRKHAL_coBIDIR_PULSE_DIAG == CRKHAL_coENABLED)
   *CRKHAL_pu32McsBiDirDiaEn = (boolean)TRUE;
#else
   *CRKHAL_pu32McsBiDirDiaEn = (boolean)FALSE;
#endif /* CRKHAL_coBIDIR_PULSE_DIAG */
   CRKHAL_enuMode = (CRKHAL_tenuMode)CRKHAL_udtNOT_SET;
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSetMode                                           */
/* !Description : Sets the Mode of CRKHAL                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void CRKHAL_vidSetMode(CRKHAL_tenuMode enuMode)
{

   switch (enuMode)
   {
      case CRKHAL_udtNORMAL_MODE:
         if (CRKHAL_enuMode != (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
         {
            CRKHAL_enuMode              = (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE;
            CRKHAL_bQuickSynchroEnabled = (boolean)FALSE;
            CRKHAL_vidNormalModeEntry();
            CRKHAL_vidLINK_PORT_TO_TIM(CRKHAL_u8CrkInputSignal);
            CRKHAL_vidDPLL_EN_INTR();
            CRKHAL_vidENABLE_ANG_TMR_CNT();
            CRKHAL_vidWriteNoiseCanceler(CRKHAL_ku32NoiseCancelerTime);

            if (CRKHAL_bDetection != (boolean)FALSE)
            {
               CRKHAL_vidENABLE_INTERRUPT(NEWVAL);
            }
            CRKHAL_vidSynchroLost();

         }
         break;

      case CRKHAL_udtDOWNGRADED_MODE:
         if (CRKHAL_enuMode != (CRKHAL_tenuMode)CRKHAL_udtDOWNGRADED_MODE)
         {
            CRKHAL_bDesynchroThdEnabled    = (boolean)FALSE;
            CRKHAL_u32ToothMaxDuration     = CRKHAL_u32StalDetThd;
            CRKHAL_u32LongToothMaxDuration = (uint32)UINT32_MAX;
            if (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
            {
               CRKHAL_vidForceSignalLoss();
            }
            CRKHAL_vidSetCfgAngCounter(TBU_DISABLE_CLR);
            CRKHAL_enuMode = (CRKHAL_tenuMode)CRKHAL_udtDOWNGRADED_MODE;
            CRKHAL_vidDwnModeEntry();
         }
         break;

      case CRKHAL_udtNOT_SET:
         if (CRKHAL_enuMode != (CRKHAL_tenuMode)CRKHAL_udtNOT_SET)
         {
            if (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
            {
               CRKHAL_bDesynchroThdEnabled    = (boolean)FALSE;
               CRKHAL_u32ToothMaxDuration     = CRKHAL_u32StalDetThd;
               CRKHAL_u32LongToothMaxDuration = (uint32)UINT32_MAX;
               CRKHAL_vidForceSignalLoss();
            }
            CRKHAL_vidSetCfgAngCounter(TBU_DISABLE_CLR);
            CRKHAL_enuMode = (CRKHAL_tenuMode)CRKHAL_udtNOT_SET;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtReadMode                                          */
/* !Description : Reads the Mode of CRKHAL                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtReadMode(CRKHAL_tenuMode *penuMode)
{

   *penuMode = CRKHAL_enuMode;
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtReadStatus                                        */
/* !Description : Reads the Status of CRKHAL                                  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtReadStatus(uint8    u8Channel,
                                    boolean *pbStatus)
{
   Std_ReturnType Local_udtRetValue;


   if (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
   {
      Local_udtRetValue = E_OK;
      switch (u8Channel)
      {
         case CRKHAL_u8DETECTED:
            *pbStatus = CRKHAL_bDetected;
            break;

         case CRKHAL_u8RUNNING:
            *pbStatus = CRKHAL_bRunning;
            break;

         case CRKHAL_u8SYNCHRONISED:
            *pbStatus = CRKHAL_bSynchronized;
            break;

         case CRKHAL_u8ENG_SYNCHRONISED:
            *pbStatus = CRKHAL_bEngSynchronized;
            break;

         case CRKHAL_u8ENG_POSITION_KNOWN:
            *pbStatus = CRKHAL_bEngPositionKnown;
            break;

         default:
            *pbStatus = (boolean)FALSE;
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
   else
   {
      *pbStatus         = (boolean)FALSE;
      Local_udtRetValue = E_NOT_OK;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtEnableDetection                                   */
/* !Description : Enables tooth detection                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtEnableDetection(void)
{

   if (  (CRKHAL_bDetection == (boolean)FALSE)
      && (CRKHAL_bDetected == (boolean)FALSE) )
   {
      CRKHAL_vidEnableDetection();
      if (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
      {
         CRKHAL_vidENABLE_INTERRUPT(NEWVAL);
      }
   }
   CRKHAL_bDetection = (boolean)TRUE;
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtDisableDetection                                  */
/* !Description : Disables tooth detection                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtDisableDetection(void)
{

   CRKHAL_bDetection = (boolean)FALSE;
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtEnableSynchronisation                             */
/* !Description : Enables synchronization                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtEnableSynchronisation(void)
{

   CRKHAL_bSynchroEnable = (boolean)TRUE;
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtDisableSynchronisation                            */
/* !Description : Disables synchronization                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtDisableSynchronisation(void)
{

   CRKHAL_bSynchroEnable = (boolean)FALSE;
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtForceDesynchronisation                            */
/* !Description : Forces Desynchronization                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtForceDesynchronisation(void)
{
   Std_ReturnType Local_udtRetValue;


   if (  (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
      && (CRKHAL_bSynchronized != (boolean)FALSE) )
   {
      Local_udtRetValue       = E_OK;
      CRKHAL_bDesynchroForcee = (boolean)TRUE;
   }
   else
   {
      Local_udtRetValue       = E_NOT_OK;
      CRKHAL_bDesynchroForcee = (boolean)FALSE;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtReadToothEdgeDate                                 */
/* !Description : Reads Tooth Edge Date                                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtReadToothEdgeDate(uint32 *pu32Date)
{
   Std_ReturnType udtLocalRetValue;
   boolean        bLocalEdgeLevel;
   uint8          u8LocalSwonT;


   if (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
   {
      udtLocalRetValue = E_OK;
      bLocalEdgeLevel  = (CRKHAL_bREAD_EDGE_LEVEL() );
      /* Falling edge is detected */
      if (bLocalEdgeLevel == 0U)
      {
         *pu32Date = (uint32)CRKHAL_snGET_EDGE_TIMESTAMP();
      }
      /* Rising edge is detected */
      else
      {
         u8LocalSwonT = (uint8)CRKHAL_snGET_newTRIGGER();
         if (u8LocalSwonT == 0U)
         {
            *pu32Date = CRKHAL_u32READ_TOOTH_EDGE_DATE_OLD();
         }
         else
         {
            *pu32Date = CRKHAL_u32READ_TOOTH_EDGE_DATE();
         }
      }
   }
   else
   {
      udtLocalRetValue = E_NOT_OK;
      *pu32Date        = (uint32)UINT32_MIN;
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtGetDeltaAngleOnSync                               */
/* !Description : Gets the Delta Angle at Dynchonization Finding              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtGetDeltaAngleOnSync(uint16 *pu16DeltaAngle)
{
   Std_ReturnType Local_udtRetValue;
   uint16         Local_u16Angle;


   if (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
   {
      Local_udtRetValue = E_OK;
      Local_u16Angle    = CRKHAL_u16DeltaAngleOnSynchro;
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
      Local_u16Angle    = (uint16)UINT16_MIN;
   }
   *pu16DeltaAngle = Local_u16Angle;
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtGetRoundedAngle                                   */
/* !Description : Rounds the angle                                            */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtGetRoundedAngle(uint16  u16Angle,
                                         uint16 *pu16RoundedAngle)
{
   *pu16RoundedAngle = u16Angle;
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtGetTargetToothAngle                               */
/* !Description : Gets Target Tooth Angle                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtGetTargetToothAngle(uint16 *pu16ToothAngle)
{

   *pu16ToothAngle = ( (uint16)CRKHAL_u16NORMAL_TOOTH_ANGLE);
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtTimeToAngle                                       */
/* !Description : Converts Time in Angle                                      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtTimeToAngle(uint32  u32Time,
                                     uint16 *pu16Angle)
{
   Std_ReturnType Local_udtRetValue;
   uint16         Local_u16Angle;
   uint32         Local_u32Tmp;
   uint32         Local_u32TdcPeriod;
   uint32         Local_u32Arrondi;
   uint32         M2C_uint32_2;
   uint32         M2C_uint32_3;


   Local_u16Angle    = (uint16)UINT16_MIN;
   Local_udtRetValue = TDCHAL_udtReadPeriod(&Local_u32TdcPeriod);
   if (Local_udtRetValue != E_OK)
   {
      Local_udtRetValue = CAMHAL_udtReadToothPeriod(CRKHAL_udtCAMHAL_CH,
                                                    &Local_u32TdcPeriod);
   }
   if (Local_udtRetValue == E_OK)
   {
      if (Local_u32TdcPeriod != (uint32)UINT32_MIN)
      {
         if (u32Time <= (uint32)CRKHAL_u32MAX_TIME_TO_CONVERT)
         {
            /*lint -esym(960,10.3)*/ Local_u32Tmp = u32Time * (uint32)TDCHAL_u16TDC_OFFSET;
            Local_u32Arrondi                      = Local_u32TdcPeriod / 2U;
            M2C_uint32_2                          = Local_u32Arrondi;
            M2C_uint32_3                          = Local_u32Tmp;
            if (  ( ( (sint32)M2C_uint32_2) < (sint32)UINT32_MIN)
               && ( ( (sint32)M2C_uint32_3) < (sint32)UINT32_MIN) )
            {
               Local_u32Arrondi = (uint32)UINT32_MAX;
            }
            else
            {
               Local_u32Arrondi = M2C_uint32_2 + M2C_uint32_3;
               if (  (  ( ( (sint32)M2C_uint32_2) < (sint32)UINT32_MIN)
                     || ( ( (sint32)M2C_uint32_3) < (sint32)UINT32_MIN) )
                  && ( ( (sint32)Local_u32Arrondi) >= (sint32)UINT32_MIN) )
               {
                  Local_u32Arrondi = (uint32)UINT32_MAX;
               }
            }
            Local_u32Tmp = Local_u32Arrondi;
            if (Local_u32Tmp == (uint32)UINT32_MAX)
            {
               Local_u32TdcPeriod = Local_u32TdcPeriod
                                    / (uint32)CRKHAL_u8TIME_TO_ANGLE_SCALE;
               if (Local_u32TdcPeriod != (uint32)UINT32_MIN)
               {
                  Local_u32Tmp = u32Time * ( (uint32)( (uint32)(TDCHAL_u16TDC_OFFSET
                                                                / (uint16)CRKHAL_u8TIME_TO_ANGLE_SCALE) ) );
                  Local_u32Arrondi = Local_u32TdcPeriod / 2U;
                  M2C_uint32_2     = Local_u32Arrondi;
                  M2C_uint32_3     = Local_u32Tmp;
                  if (  ( ( (sint32)M2C_uint32_2) < (sint32)UINT32_MIN)
                     && ( ( (sint32)M2C_uint32_3) < (sint32)UINT32_MIN) )
                  {
                     Local_u32Arrondi = (uint32)UINT32_MAX;
                  }
                  else
                  {
                     Local_u32Arrondi = M2C_uint32_2 + M2C_uint32_3;
                     if (  (  ( ( (sint32)M2C_uint32_2) < (sint32)UINT32_MIN)
                           || ( ( (sint32)M2C_uint32_3) < (sint32)UINT32_MIN) )
                        && ( ( (sint32)Local_u32Arrondi) >= (sint32)UINT32_MIN) )
                     {
                        Local_u32Arrondi = (uint32)UINT32_MAX;
                     }
                  }
                  Local_u32Tmp = Local_u32Arrondi;
                  if (Local_u32Tmp == (uint32)UINT32_MAX)
                  {
                     Local_u16Angle = (uint16)UINT16_MAX;
                  }
                  else
                  {
                     Local_u32Arrondi = Local_u32Tmp;
                     Local_u32Tmp     = Local_u32TdcPeriod;
                     if ( (Local_u32Arrondi >> 16) >= Local_u32Tmp)
                     {
                        Local_u32Arrondi = (uint32)UINT16_MAX;
                     }
                     else
                     {
                        Local_u32Arrondi = Local_u32Arrondi / Local_u32Tmp;
                     }
                     Local_u16Angle = (uint16)Local_u32Arrondi;
                  }
               }
               else
               {
                  Local_u16Angle = (uint16)UINT16_MAX;
               }
            }
            else
            {
               Local_u32Arrondi = Local_u32Tmp;
               Local_u32Tmp     = Local_u32TdcPeriod;
               if ( (Local_u32Arrondi >> 16) >= Local_u32Tmp)
               {
                  Local_u32Arrondi = (uint32)UINT16_MAX;
               }
               else
               {
                  Local_u32Arrondi = Local_u32Arrondi / Local_u32Tmp;
               }
               Local_u16Angle = (uint16)Local_u32Arrondi;
            }
         }
         else
         {
            if (u32Time <= ( (uint32)(CRKHAL_u32MAX_TIME_TO_CONVERT
                                      * CRKHAL_u8TIME_TO_ANGLE_SCALE) ) )
            {
               Local_u32TdcPeriod = Local_u32TdcPeriod
                                    / (uint8)CRKHAL_u8TIME_TO_ANGLE_SCALE;
               if (Local_u32TdcPeriod != (uint32)UINT32_MIN)
               {
                  Local_u32Tmp = u32Time * ( (uint32)( (uint32)TDCHAL_u16TDC_OFFSET
                                                       / (uint16)CRKHAL_u8TIME_TO_ANGLE_SCALE) );
                  Local_u32Arrondi = Local_u32TdcPeriod / 2U;
                  M2C_uint32_2     = Local_u32Arrondi;
                  M2C_uint32_3     = Local_u32Tmp;
                  if (  ( ( (sint32)M2C_uint32_2) < (sint32)UINT32_MIN)
                     && ( ( (sint32)M2C_uint32_3) < (sint32)UINT32_MIN) )
                  {
                     Local_u32Arrondi = (uint32)UINT32_MAX;
                  }
                  else
                  {
                     Local_u32Arrondi = M2C_uint32_2 + M2C_uint32_3;
                     if (  (  ( ( (sint32)M2C_uint32_2) < (sint32)UINT32_MIN)
                           || ( ( (sint32)M2C_uint32_3) < (sint32)UINT32_MIN) )
                        && ( ( (sint32)Local_u32Arrondi) >= (sint32)UINT32_MIN) )
                     {
                        Local_u32Arrondi = (uint32)UINT32_MAX;
                     }
                  }
                  Local_u32Tmp = Local_u32Arrondi;
                  if (Local_u32Tmp == (uint32)UINT32_MAX)
                  {
                     Local_u16Angle = (uint16)UINT16_MAX;
                  }
                  else
                  {
                     Local_u32Arrondi = Local_u32Tmp;
                     Local_u32Tmp     = Local_u32TdcPeriod;
                     if ( (Local_u32Arrondi >> 16) >= Local_u32Tmp)
                     {
                        Local_u32Arrondi = (uint32)UINT16_MAX;
                     }
                     else
                     {
                        Local_u32Arrondi = Local_u32Arrondi / Local_u32Tmp;
                     }
                     Local_u16Angle = (uint16)Local_u32Arrondi;
                  }
               }
               else
               {
                  Local_u16Angle = (uint16)UINT16_MAX;
               }
            }
            else
            {
               Local_u16Angle = (uint16)UINT16_MAX;
            }
         }
      }
      else
      {
         Local_u16Angle = (uint16)UINT16_MAX;
      }
   }
   *pu16Angle = Local_u16Angle;
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidInjDriverRephase                                  */
/* !Description : Sets Injection Rephase                                      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void CRKHAL_vidInjDriverRephase(uint16 u16AngleOffset)
{
   uint16 u16Local_Tmp;


   if ( ( (sint32)u16AngleOffset) < CRKHAL_u16REVOL_OFFSET)
   {
      u16Local_Tmp = u16AngleOffset;
   }
   else
   {
      u16Local_Tmp = (uint16)CRKHAL_u16REVOL_OFFSET;
   }
   CRKHAL_u16OffsetInjDriver = (uint16)(u16Local_Tmp);

}
/******************************************************************************/
/* !FuncName    : CRKHAL_u16GetEngineAngle                                    */
/* !Description : Gets Engine Angle                                           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
uint16 CRKHAL_u16GetEngineAngle(void)
{
   uint16 Local_u16EngineAngle;


   Local_u16EngineAngle = CRKHAL_u16TbuConvRelToAbsAng( (uint32)CRKHAL_TBU_ANGLE);
   return(Local_u16EngineAngle);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtReadTeethAftrSyncLoss                             */
/* !Description : Reads Teeth Number Detected After Synchronization Loss      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtReadTeethAftrSyncLoss(uint16 *pu16TeethNumber)
{
   Std_ReturnType Local_udtRetValue;


   if (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
   {
      Local_udtRetValue               = E_OK;
      CRKHAL_u16TeethAftrLastSyncLoss = (uint16)(*CRKHAL_pu32McsTeeAfrLastSyLos);
      *pu16TeethNumber                = CRKHAL_u16TeethAftrLastSyncLoss;
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
      *pu16TeethNumber  = (uint16)UINT16_MIN;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtGetToothInfo                                      */
/* !Description : Gets Tooth informations                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtGetToothInfo(uint8   u8MaxTableSize,
                                      uint32 *pau32ToothInfoTable
                                     )
{
   Std_ReturnType Local_udtRetValue;
   boolean        bLocalRotationDirection;
   uint8          u8LocalIndex;
   uint8          u8LocalSwonT;
   uint32         u32LocalEngPosition;
   uint32         u32LocalToothDuration;
   uint32         u32LocalPrevToothDuration;
   uint32         au32LocalInfoTable[CRKHAL_u8TOOTH_TABLE_SIZE_MAX];
   uint32         u32LocalCurrApt2cValue = CRKHAL_snGET_GTM_DPLL_APT2c;
   uint32         u32TempLocalEngPosition;


   if (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
   {
      if ( ( (sint32)u8MaxTableSize) <= CRKHAL_u8TOOTH_TABLE_SIZE_MAX)
      {
         Local_udtRetValue = E_OK;
         SchM_Enter_CRKHAL_ACCESS_001();
         u8LocalIndex              = (uint8)(*CRKHAL_pu32McsToothCnt);
         u32LocalToothDuration     = (uint32)(CRKHAL_snGET_TOOTH_PERIOD() );
         u32LocalPrevToothDuration = *CRKHAL_pu32McsPrevToothDur;
         bLocalRotationDirection   = (boolean)(CRKHAL_snGET_DIRECTION() );

         if (CRKHAL_bEngSynchronized == FALSE)
         {
            boolean edgeCnt = (CRKHAL_bREAD_EDGE_LEVEL() );
            /* Falling edge is detected */

            if (*CRKHAL_pu32McsLtoo1event == TRUE)
            {
               u32LocalEngPosition = CRKHAL_u32Ltoo1TbuValue;
            }
            else
            {
               /**CRKHAL_pu32McsLtoo1event = FALSE;*/
               if (edgeCnt == 0U)
               {
                  u32LocalEngPosition = (uint32)(CRKHAL_u16TbuConvRelToAbsAng( (uint32)(CRKHAL_snGET_EDGE_ANGLE() ) ) );
               }
               /* Rising edge is detected */
               else
               {
                  u8LocalSwonT = (uint8)(CRKHAL_snGET_newTRIGGER() );
                  if (u8LocalSwonT == 0U)
                  {
                     u32LocalEngPosition =
                        (uint32)(CRKHAL_u16TbuConvRelToAbsAng( (uint32)(CRKHAL_snGET_FALLING_EDGE_ANGLE_OLD() ) ) );
                  }
                  else
                  {
                     u32LocalEngPosition =
                        (uint32)(CRKHAL_u16TbuConvRelToAbsAng( (uint32)(CRKHAL_snGET_FALLING_EDGE_ANGLE() ) ) );
                  }
               }
            }
         }
         else
         {
            if (u32LocalCurrApt2cValue <= 1U)
            {
               u32LocalCurrApt2cValue += CRKHAL_u16PhyTeethFullScale; /* 116 */
            }

            u32LocalCurrApt2cValue--;

            u32TempLocalEngPosition = (u32LocalCurrApt2cValue * CRKHAL_u16NORMAL_TOOTH_ANGLE);

            if ( (u32LocalCurrApt2cValue > CRKHAL_u16PhyTeeth1Minus) ) /* 57 */
            {
               u32TempLocalEngPosition += (2U * CRKHAL_u16NORMAL_TOOTH_ANGLE);
            }

            if (u32LocalCurrApt2cValue == CRKHAL_u16PhyTeethFullScale) /* 116 */
            {
               u32TempLocalEngPosition += (2U * CRKHAL_u16NORMAL_TOOTH_ANGLE);
            }

            if (u32TempLocalEngPosition < CRKHAL_u32NumberOfMlt_Tdc)
            {
               u32TempLocalEngPosition = (u32TempLocalEngPosition \
                                          + CRKHAL_u32NumberOfMlt_Full) - CRKHAL_u32NumberOfMlt_Tdc;
            }
            else
            {
               u32TempLocalEngPosition = u32TempLocalEngPosition - CRKHAL_u32NumberOfMlt_Tdc;
            }

            if (u32TempLocalEngPosition >= CRKHAL_u32NumberOfMlt_Full)
            {
               u32TempLocalEngPosition = u32TempLocalEngPosition - CRKHAL_u32NumberOfMlt_Full;
            }

            u32LocalEngPosition = u32TempLocalEngPosition;
         }

         SchM_Exit_CRKHAL_ACCESS_001();
         au32LocalInfoTable[0] = (uint32)u8LocalIndex;
         au32LocalInfoTable[1] = (uint32)u32LocalToothDuration;
         au32LocalInfoTable[2] = (uint32)u32LocalPrevToothDuration;
         au32LocalInfoTable[3] = (uint32)u32LocalEngPosition;
         au32LocalInfoTable[4] = (uint32)bLocalRotationDirection;
         for (u8LocalIndex = (uint8)UINT8_MIN;
              ( (sint32)u8LocalIndex) < ( (sint32)u8MaxTableSize);
              u8LocalIndex++)
         {
            pau32ToothInfoTable[u8LocalIndex] = au32LocalInfoTable[u8LocalIndex];
         }
      }
      else
      {
         Local_udtRetValue = E_NOT_OK;
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtEnableBwdRotation                                 */
/* !Description : Enables Backward Rotation Detection                         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtEnableBwdRotation(void)
{
   Std_ReturnType Local_udtRetValue;


   if (  (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
      && (CRKHAL_kbBidirSensorUsed
          != (boolean)FALSE) )
   {
      CRKHAL_bEnaBwdRotationDetection = TRUE;
      *CRKHAL_pu32McsDirCfgEn         = (boolean)FALSE;
      *CRKHAL_pu32McsBiDirEn          = (boolean)TRUE;
      Local_udtRetValue               = E_OK;
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtDisableBwdRotation                                */
/* !Description : Disables Backward Rotation Detection                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtDisableBwdRotation(void)
{
   Std_ReturnType Local_udtRetValue;


   if (  (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
      && (CRKHAL_kbBidirSensorUsed
          != (boolean)FALSE) )
   {
      SchM_Enter_CRKHAL_ACCESS_002();
      CRKHAL_bEnaBwdRotationDetection = FALSE;
      *CRKHAL_pu32McsBiDirEn          = (boolean)FALSE;
      CRKHAL_vidDISABLE_INTERRUPT(DIR);
      CRKHAL_vidSET_TRIGGER_HOLD_TIME(0U);
      *CRKHAL_pu32McsDirCfgEn = (boolean)TRUE;

      *CRKHAL_pu32McsBiDirFwdCnt = (uint32)UINT32_MIN;
      *CRKHAL_pu32McsBiDirBwdCnt = (uint32)UINT32_MIN;

      /* Eng run to Sync in case disabled */
      if (CRKHAL_bRotationDirection != CRKHAL_bFWD_ROTATION)
      {
         CRKHAL_vidDPLL_DISABLE();
         /* update TOV for Gap Check */
         CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_CHECK_GAP);
         CRKHAL_vidENABLE_INTERRUPT(MTI);
         CRKHAL_vidENABLE_INTERRUPT(TE1);
         CRKHAL_vidDPLL_ENABLE();
      }
      CRKHAL_bBwdRotationPhase  = (boolean)FALSE;
      CRKHAL_bRotationDirection = CRKHAL_bFWD_ROTATION;
      SchM_Exit_CRKHAL_ACCESS_002();
      Local_udtRetValue = E_OK;
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtEnableQuickSynchro                                */
/* !Description : Enables Quick synchronization                               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtEnableQuickSynchro(void)
{
   Std_ReturnType Local_udtRetValue;


   if (  (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
      && (CRKHAL_kbEnaQuickSynchro
          == CRKHAL_bQUICK_SYNCHRO_ENABLED) )
   {
      CRKHAL_bQuickSynchroEnabled = TRUE;
      Local_udtRetValue           = E_OK;
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtDisableQuickSynchro                               */
/* !Description : Disables Quick synchronization                              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtDisableQuickSynchro(void)
{
   Std_ReturnType Local_udtRetValue;


   if (  (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
      && (CRKHAL_kbEnaQuickSynchro
          == CRKHAL_bQUICK_SYNCHRO_ENABLED) )
   {
      CRKHAL_bQuickSynchroEnabled = FALSE;
      Local_udtRetValue           = E_OK;
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtWriteEnaToothTskRpmThd                            */
/* !Description : Specifies Engine Speed to Activate Tooth Tasks              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtWriteEnaToothTskRpmThd(uint16 u16EngineSpeedThd)
{
   Std_ReturnType Local_udtRetValue;
   uint32         u32LocalEnaToothTskThd;


   if (CRKHAL_enuMode == (CRKHAL_tenuMode)CRKHAL_udtNORMAL_MODE)
   {
      if (u16EngineSpeedThd != (uint16)UINT16_MIN)
      {
         u32LocalEnaToothTskThd = (uint32)CRKHAL_u32_1MIN_IN_RES_100NS
                                  / ( ( (uint32)u16EngineSpeedThd)
                                      * ( (uint32)CRKHAL_u8LONG_TOOTH_SIZE
                                          + ( (uint32)CRKHAL_u16NbPhysTeeth) ) );
         /* u32LocalEnaToothTskThd = CRKHAL_u32_1MIN_IN_RES_100NS
                                   / ((uint32) u16EngineSpeedThd); */
         CRKHAL_u32EnaToothTskDurThd = u32LocalEnaToothTskThd;
      }
      else
      {
         CRKHAL_u32EnaToothTskDurThd = (uint32)UINT32_MAX;
      }
      CRKHAL_vidUpdateToothTskDurationThd(CRKHAL_u32EnaToothTskDurThd);
      Local_udtRetValue = E_OK;
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtGetEngStopPosition                                */
/* !Description : Gets Engine Stop Position                                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtGetEngStopPosition(uint8   u8StopPositionType,
                                            uint16 *pu16StopPosition
                                           )
{
   Std_ReturnType Local_udtRetValue;


   if (  (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
      && (CRKHAL_bStopPosCalculation != FALSE) )
   {
      Local_udtRetValue = E_OK;
      switch (u8StopPositionType)
      {
         case CRKHAL_u8STOP_POSITION:
            *pu16StopPosition = CRKHAL_u16StopAngPosition;
            break;

         case CRKHAL_u8STOP_POSITION_AFTER:
            if (CRKHAL_bStopPosAfterCalculation != FALSE)
            {
               *pu16StopPosition = CRKHAL_u16StopAngPositionAfter;
            }
            else
            {
               Local_udtRetValue = E_NOT_OK;
            }
            break;

         default:
            Local_udtRetValue = E_NOT_OK;
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
   else
   {
      Local_udtRetValue = E_NOT_OK;
   }
   return(Local_udtRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtGetOorPulseInfo                                   */
/* !Description : Gets Out of Range Pulse Counter                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtGetOorPulseInfo(uint8 *pu8OorPulseCounter,
                                         uint8 *pu8TeethCounter
                                        )
{
   Std_ReturnType udtLocalRetValue = E_NOT_OK;
   uint8          u8LocalTeethCounter;
   uint8          u8LocalOorPulseCounter;


   if (  (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
      && (CRKHAL_kbBidirSensorUsed
          != (boolean)FALSE) )
   {
      udtLocalRetValue = E_OK;
      SchM_Enter_CRKHAL_ACCESS_003();
      u8LocalTeethCounter             = (uint8)(*CRKHAL_pu32McsPulseDiagCounter);
      u8LocalOorPulseCounter          = (uint8)(*CRKHAL_pu32McsOorPulseCounter);
      *CRKHAL_pu32McsOorPulseCounter  = (uint8)UINT8_MIN;
      *CRKHAL_pu32McsPulseDiagCounter = (uint8)UINT8_MIN;
      SchM_Exit_CRKHAL_ACCESS_003();
      *pu8OorPulseCounter = u8LocalOorPulseCounter;
      *pu8TeethCounter    = u8LocalTeethCounter;
   }
   else
   {
      udtLocalRetValue              = E_NOT_OK;
      CRKHAL_pu32McsOorPulseCounter = UINT8_MIN;
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtWriteDesynchroRpmThd                              */
/* !Description : Specifies Engine Speed Threshold to Loose Synchronization   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType CRKHAL_udtWriteDesynchroRpmThd(uint16 u16EngineSpeedThd)
{
#if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED)
   uint32  u32LocalToothMaxDuration;
   uint32  u32LocalLongToothMaxDuration;
   boolean bLocalDesynchroThdEnabled;
#endif /* if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED) */
   Std_ReturnType udtLocalReturnValue;
   udtLocalReturnValue = E_OK;
#if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED)
   bLocalDesynchroThdEnabled    = (boolean)FALSE;
   u32LocalToothMaxDuration     = (uint32)UINT32_MAX;
   u32LocalLongToothMaxDuration = (uint32)UINT32_MAX;
   if (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
   {
      if (u16EngineSpeedThd != (uint16)UINT16_MIN)
      {
         if (CRKHAL_bSynchronized != (boolean)FALSE)
         {
            u32LocalToothMaxDuration = CRKHAL_u32_1MIN_IN_RES_100NS
                                       / ( ( (uint32)u16EngineSpeedThd)
                                           * (CRKHAL_u8LONG_TOOTH_SIZE
                                              + ( (uint32)CRKHAL_u16NbPhysTeeth) ) );

            if ( (CRKHAL_u32_500_MICRO_SEC + u32LocalToothMaxDuration)
                 < CRKHAL_ku32StalDetThd)
            {
               bLocalDesynchroThdEnabled = TRUE;
               u32LocalLongToothMaxDuration = (u32LocalToothMaxDuration * 2u)
                                              + u32LocalToothMaxDuration;
               if (u32LocalToothMaxDuration != CRKHAL_u32ToothMaxDuration)
               {
                  if (CRKHAL_bSingularityDetected == FALSE)
                  {
                     u32LocalToothMaxDuration = ( ( ( (2U * u32LocalToothMaxDuration)
                                                      + (uint32)CRKHAL_u16STALL_TIMER_RESOL)
                                                    / (2U * (uint32)CRKHAL_u16STALL_TIMER_RESOL) )
                                                  - 1U);

                     CRANKHAL_vidSET_CRK_TIMEOUT(u32LocalToothMaxDuration);
                  }
                  else
                  {
                     u32LocalLongToothMaxDuration = ( ( ( (2U * u32LocalLongToothMaxDuration)
                                                          + (uint32)CRKHAL_u16STALL_TIMER_RESOL)
                                                        / (2U * (uint32)CRKHAL_u16STALL_TIMER_RESOL) )
                                                      - 1U);

                     CRANKHAL_vidSET_CRK_TIMEOUT(u32LocalLongToothMaxDuration);
                  }
               }
            }
         }
      }
      if (  (bLocalDesynchroThdEnabled == (boolean)FALSE)
         && (CRKHAL_bDesynchroThdEnabled != (boolean)FALSE) )
      {
         /*SuspendAllInterrupts();*/
         if (CRKHAL_bSingularityDetected == (boolean)FALSE)
         {
            CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32StalDetThd);
         }
         else
         {
            CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32LongToothStalDetThd);
         }
         /*ResumeAllInterrupts();*/
      }
   }
   else
   {
      udtLocalReturnValue = E_NOT_OK;
   }
   CRKHAL_bDesynchroThdEnabled    = bLocalDesynchroThdEnabled;
   CRKHAL_u32ToothMaxDuration     = u32LocalToothMaxDuration;
   CRKHAL_u32LongToothMaxDuration = u32LocalLongToothMaxDuration;

#else /* if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED) */

   COMPILER_UNUSED_PARAMETER(u16EngineSpeedThd);
   /*   COMPILER_UNUSED_PARAMETER(u32LocalToothMaxDuration);
      COMPILER_UNUSED_PARAMETER(u32LocalLongToothMaxDuration);
      COMPILER_UNUSED_PARAMETER(bLocalDesynchroThdEnabled);
      COMPILER_UNUSED_PARAMETER(u32LocalToothMaxDuration);*/

#endif /* if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED) */
   return(udtLocalReturnValue);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_udtGetSpecificToothInfo                              */
/* !Description : This function fills the table pointed by the parameter      */
/*				   pau32ToothInfoTable with <u8MaxTableSize> data. The data       */
/* 				   written in the table are 								            */
/*			       - Tooth start time stamp (i.e. pau32ToothInfoTable[0])	      */
/*				   It gives the time stamp value of the start of the tooth        */
/*				   identified by <ToothNb>.								               */
/*				   - Tooth duration (i.e. pau32ToothInfoTable[1])                 */
/*				   It gives the tooth duration of the tooth identified by         */
/* 				   <ToothNb>.											                  */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType CRKHAL_udtGetSpecificToothInfo(uint8   u8ToothNb,
                                              uint8   u8MaxTableSize,
                                              uint32 *pau32ToothInfoTable)
{
   Std_ReturnType udtLocalReturnValue;
   uint8          u8LocalIndex;
   /*boolean ubLocalEdge;*/
   uint32 au32LocalInfoTable[CRKHAL_u8SPECIFIC_TOOTH_TABLE_SIZE_MAX];


   udtLocalReturnValue = E_NOT_OK;

   if (  (CRKHAL_enuMode == CRKHAL_udtNORMAL_MODE)
      && (CRKHAL_bSynchronized != (boolean)FALSE) )
   {
      /* check valid tooth numbers */
      if (  (u8ToothNb < (uint8)CRKHAL_u16PhyTeethFullScale)
         && (u8MaxTableSize < 3U) )
      {
         SchM_Enter_CRKHAL_ACCESS_004();
         /* Time Stamp */
         /* Time Stamp is located on RAM CRKHAL_TOOTH_TIME_STAMP_ARRAY location
          * is based on APT2b pointer */
         if (u8ToothNb == 0U)
         {
            /* For tooth 0 time stamp located as 118 */
            au32LocalInfoTable[0] = (uint32)CRKHAL_TOOTH_TIME_STAMP_ARRAY[CRKHAL_u16PhyTeethFullScale + 2U];
         }
         else if (u8ToothNb <= CRKHAL_ku16NbPhysTeeth)
         {
            /* For tooth [below 58] refer location directly */
            au32LocalInfoTable[0] = (uint32)CRKHAL_TOOTH_TIME_STAMP_ARRAY[u8ToothNb];
         }
         else
         {
            /* For tooth [greater than 58 ] refer located on tooth Number + 2 */
            au32LocalInfoTable[0] = (uint32)CRKHAL_TOOTH_TIME_STAMP_ARRAY[u8ToothNb + 2U];
         }

         /* Tooth Duration */
         /* Tooth Duration is located on RAM CRKHAL_TOOTH_DUR_ARRAY location
          * is based on APT2b pointer */
         if (  (u8ToothNb == 0U)
            || (u8ToothNb == CRKHAL_ku16NbPhysTeeth) )
         {
            /* Long tooth - since DPLL divides by 3 in DT_T, multiply by 3 */
            au32LocalInfoTable[1] = (uint32)(CRKHAL_TOOTH_DUR_ARRAY[u8ToothNb] * 3U);
         }
         else
         {
            /* Normal tooth - refer same DT_T location */
            au32LocalInfoTable[1] = (uint32)CRKHAL_TOOTH_DUR_ARRAY[u8ToothNb];
         }

         SchM_Exit_CRKHAL_ACCESS_004();

         /* copy all local variables */
         for (u8LocalIndex = UINT8_MIN;
              ( (sint32)u8LocalIndex) < ( (sint32)u8MaxTableSize);
              u8LocalIndex++)
         {
            pau32ToothInfoTable[u8LocalIndex] = au32LocalInfoTable[u8LocalIndex];
         }
         udtLocalReturnValue = E_OK;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   return(udtLocalReturnValue);
}
/*lint -restore */
#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
