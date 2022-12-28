/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CRKHAL                                                  */
/* !Description     : CRKHAL Component                                        */
/*                                                                            */
/* !File            : CRKHAL_1.c                                              */
/* !Description     : Internal Function and Interrupts of CRKHAL Component    */
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
 * %PID: P2017_BSW:A18541.A-SRC;12 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "TSKSRV.h"
#include "CAMHAL.h"
#include "DGOHAL.h"
#include "SWFAIL.h"
#include "CRKHAL.h"
#include "CRKHAL_L.h"
#include "CRKHAL_I.h"
#include "IfxGtm_Ccu.h"
#include "CRKHAL_co_Cfg.h"
#include "KRN.h"
#include "MATHSRV.h"

/*lint -esym(960,17.4) */
/*lint -esym(960,19.5) */
/*lint -esym(506,13.7) */
/*lint -esym(506,14.1) */
/* !MComment: Check of defines declaration                                    */
#ifndef CRKHAL_coTOOTH_TASK_ACTIVATION
   #error The macro-constant CRKHAL_coTOOTH_TASK_ACTIVATION shall be defined
#endif
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
/* !FuncName    : CRKHAL_vidDesyncManagement                                  */
/* !Description : This function will be called to reset the Variables         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidDesyncManagement(void)
{
   /* increment sync loss count */
   CRKHAL_u16NumOfSyncLoss++;

   CRKHAL_vidSynchroLost();
   CRKHAL_vidSyncLossEntry();
   TSKSRV_vidActivateTask(CRKHAL_TOLO_EVENT);
   CRKHAL_bDesynchroForcee = (boolean)FALSE;
   /**CRKHAL_pu32McsTeeAfrLastSyLos  = 1U;*/
   *CRKHAL_pu32McsEngineStatus     = MCS_RUN;
   CRKHAL_bEngPositionKnown        = (boolean)FALSE;
   CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
   CRKHAL_ubGliLockStatus          = (boolean)FALSE;

   CRKHAL_bDirectionChangeDet = (boolean)FALSE;
   /*   CRKHAL_bRotationDirection   = CRKHAL_bFWD_ROTATION;
      CRKHAL_bQuickSynchroEnabled = (boolean)FALSE;
      CRKHAL_bBwdRotationPhase    = (boolean)FALSE;*/

   CRKHAL_vidDISABLE_INTERRUPT(TE0);
   CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_CHECK_GAP);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDpllLongToothIsr                                  */
/* !Description : CRKHAL_vidDpllLongToothIsr [Missing TRIGGER interrupt]      */
/*                This interrupt is generated when the current Tooth duration */
/*                is greater than the previous multiplied by TOV              */
/*                 (i.e. current > TOV * last TOV=2.0)                        */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(CRKHAL_DPLL_longToothIsr, 0, MTI_INT_PRIO) */
void CRKHAL_vidDpllLongToothIsr(void)
{
   CRKHAL_vidCLEAR_INTERRUPT(MTI);

   /* First time - before Synchronisation */
   if (CRKHAL_bSynchronized == (boolean)FALSE)
   {
      /* first synchronisation check for conditions */
      if (  (CRKHAL_bSynchroEnable != (boolean)FALSE)
         && (  (CRKHAL_bRotationDirection == (boolean)CRKHAL_bFWD_ROTATION)
            && (CRKHAL_bDirectionChangeDet == (boolean)FALSE) ) )
      {
         /* set Singularity detected - long tooth detected */
         CRKHAL_bSingularityDetected = (boolean)TRUE;

         /* Reset APTs & Enable Interrupts for Change of Mind enabled is FALSE */
         if (  (CRKHAL_bChangeOfMindEnabled == (boolean)FALSE)
            && (CRKHAL_bBwdRotationPhase == (boolean)FALSE) )
         {
            /* Reset APT pointers to 0 */
            CRKHAL_vidSYNC_CYLINDER_NUMBER();

            switch (CRKHAL_enuCylinderNumber)
            {
               case CRKHAL_udtFIRST_CYLINDER:
                  CRKHAL_vidSET_GTM_DPLL_APT_APT(CRKHAL_u16PhyTeethFullScale1Ms);
                  CRKHAL_vidSET_GTM_DPLL_APT_APT2b(0U);
                  CRKHAL_vidSET_GTM_DPLL_APT2c(0U);
                  break;

               case CRKHAL_udtSECOND_CYLINDER:
                  CRKHAL_vidSET_GTM_DPLL_APT_APT(CRKHAL_u16PhyTeeth1Minus);
                  CRKHAL_vidSET_GTM_DPLL_APT_APT2b( (CRKHAL_ku16NbPhysTeeth + 2U) );
                  CRKHAL_vidSET_GTM_DPLL_APT2c(CRKHAL_ku16NbPhysTeeth);
                  break;

               case CRKHAL_udtUNKNOWN_CYLINDER:
               default:
                  CRKHAL_vidSET_GTM_DPLL_APT_APT(CRKHAL_u16PhyTeethFullScale1Ms);
                  CRKHAL_vidSET_GTM_DPLL_APT_APT2b(0U);
                  CRKHAL_vidSET_GTM_DPLL_APT2c(0U);
                  SWFAIL_vidSoftwareErrorHook();
                  break;
            }
            /* Current TIM Tooth Duration is copied to Duration of last TRIGGER */
            CRKHAL_u32LastToothDurInLtoo1 = (uint32)(CRKHAL_snGET_TOOTH_PERIOD() );
            /* Set NUTC for DPLL */
            CRKHAL_ubNutcCheck = (boolean)TRUE;
            /* Enable GLI & LLI interrupts */
            CRKHAL_vidENABLE_INTERRUPT(GLI);
            CRKHAL_vidENABLE_INTERRUPT(LLI);
         }
         else
         {
            /* Enable interrupts for change of Mind enabled */
            CRKHAL_vidSYNC_CYLINDER_NUMBER();

            switch (CRKHAL_enuCylinderNumber)
            {
               case CRKHAL_udtFIRST_CYLINDER:
                  CRKHAL_vidSET_GTM_DPLL_APT_APT(CRKHAL_u16PhyTeethFullScale1Ms);
                  CRKHAL_vidSET_GTM_DPLL_APT_APT2b(0U);
                  CRKHAL_vidSET_GTM_DPLL_APT2c(0U);
                  break;

               case CRKHAL_udtSECOND_CYLINDER:
                  CRKHAL_vidSET_GTM_DPLL_APT_APT(CRKHAL_u16PhyTeeth1Minus);
                  CRKHAL_vidSET_GTM_DPLL_APT_APT2b( (CRKHAL_ku16NbPhysTeeth + 2U) );
                  CRKHAL_vidSET_GTM_DPLL_APT2c(CRKHAL_ku16NbPhysTeeth);
                  break;

               case CRKHAL_udtUNKNOWN_CYLINDER:
               default:
                  CRKHAL_vidSET_GTM_DPLL_APT_APT(CRKHAL_u16PhyTeethFullScale1Ms);
                  CRKHAL_vidSET_GTM_DPLL_APT_APT2b(0U);
                  CRKHAL_vidSET_GTM_DPLL_APT2c(0U);
                  SWFAIL_vidSoftwareErrorHook();
                  break;
            }
            /* Current TIM Tooth Duration is copied to Duration of last TRIGGER */
            CRKHAL_u32LastToothDurInLtoo1 = (uint32)(CRKHAL_snGET_TOOTH_PERIOD() );
            /* Set NUTC for DPLL */
            CRKHAL_ubNutcCheck = (boolean)TRUE;
            /* Enable GLI & LLI interrupts */
            CRKHAL_vidENABLE_INTERRUPT(GLI);
            CRKHAL_vidENABLE_INTERRUPT(LLI);
            CRKHAL_vidENABLE_INTERRUPT(TE0);
            CRKHAL_vidENABLE_INTERRUPT(TE1);
         }
      }
   }
   else
   {
      /* set CRKHAL_bSingularityDetected Normal synchronisation */
      CRKHAL_bSingularityDetected = (boolean)TRUE;
      /* update the TOV for more than long tooth value */
      CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_NO_GAP);
   }

   /* To improve the DPLL prediction capabilities */
   if (CRKHAL_ubNutcCheck != (boolean)FALSE)
   {
      CRKHAL_ubNutcCheck = (boolean)FALSE;
      CRKHAL_vidSET_DPLL_NUTC_NUTE(CRKHAL_u16PhyTeethFullScale + 4U);
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidStallDetection                                    */
/* !Description : Stall detection Management                                  */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidStallDetection(void)
{
   if (CRKHAL_bRunning != (boolean)FALSE)
   {
      *CRKHAL_pu32McsEngineStatus = MCS_NO_RUN;
      /* clear Interrupt notification & Disable Interrupt TE1 */
      CRKHAL_vidCLEAR_INTERRUPT(TE1);
      CRKHAL_vidDISABLE_INTERRUPT(TE1);

      /* clear Interrupt notification & Disable Interrupt MTI */
      CRKHAL_vidCLEAR_INTERRUPT(MTI);
      CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_CHECK_GAP);
      CRKHAL_vidDISABLE_INTERRUPT(MTI);
      /* Configure bRunning to FALSE */
      CRKHAL_vidRUN_TO_STALL();
      TSKSRV_vidActivateTask(CRKHAL_ENG_STAL_EVENT);
      /* update the variable if synchronised */
      if (CRKHAL_bSynchronized != (boolean)FALSE)
      {
         /* configure Quick synchronisation variables accordingly */
         if (CRKHAL_bQuickSynchroEnabled != (boolean)FALSE)
         {
            CRKHAL_bChangeOfMindEnabled  = (boolean)TRUE;
            *CRKHAL_pu32McsBiDirChgMndEn = (boolean)TRUE;
            if (CRKHAL_bEnaLtooSearchAftRestart == (boolean)FALSE)
            {
               CRKHAL_bEnaLtooSearchAftRestart = (boolean)TRUE;
            }
         }
         else
         {
            CRKHAL_bEngPositionKnown        = (boolean)FALSE;
            CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
         }

         CRKHAL_u16NumOfSyncLoss++;  /* Added for debug purpose */
         CRKHAL_bSynchronized    = (boolean)FALSE;
         CRKHAL_bEngSynchronized = (boolean)FALSE;
         CRKHAL_vidSynchroLost();
         CRKHAL_vidSyncLossEntry();
         CRKHAL_vidDISABLE_INTERRUPT(TE0);
         /**CRKHAL_pu32McsTeeAfrLastSyLos = 1U;*/
         TSKSRV_vidActivateTask(CRKHAL_TOLO_EVENT);
      }
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDpllLostLockIsr                                   */
/* !Description : This interrupt is raised when the Dpll losses the           */
/*                synchronization                                             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(Ifx_lliIsr, 0, LLI_INT_PRIO) */
void CRKHAL_vidDpllLostLockIsr(void)
{
   CRKHAL_vidCLEAR_INTERRUPT(LLI);
   /* Reset Lock status - Hardware is not locked */
   CRKHAL_ubGliLockStatus = (boolean)FALSE;
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSynchSearchAndCtlIsr                              */
/* !Description : Synchronisation Check & Control (on TE1 Interrupt)          */
/*                This interrupt is generated at the end of the               */
/*                synchronisation window. The interrupt is programmed on a    */
/*                specific tooth the crank profile stored in the ADT_T memory */
/*                location.                                                   */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/*IFX_INTERRUPT(CRKHAL_vidSynchSearchAndCtlIsr, 0, TE1_INT_PRIO)*/

void CRKHAL_vidSynchSearchAndCtlIsr(void)
{
   uint32 u32Local_T5               = (uint32)UINT32_MIN;
   uint32 u32Local_T4               = (uint32)UINT32_MIN;
   uint32 u32Local_T3               = (uint32)UINT32_MIN;
   uint32 u32Local_T2               = (uint32)UINT32_MIN;
   uint32 u32Local_T1               = (uint32)UINT32_MIN;
   uint32 u32Local_T0               = (uint32)UINT32_MIN;
   uint32 u32LocalLastToothDuration = (uint32)UINT32_MIN;

   uint32 u32LocalCurrAbsAng_1 = (uint32)UINT32_MIN;
   uint8  u8LocalAptVal        = (uint8)UINT8_MIN;
   /*uint8 u8LocalAptCal            = (uint8)UINT8_MIN;*/
   uint32  u32LocalAptVal_1       = (uint32)UINT32_MIN;
   boolean ubLocalDesynchroForcee = (boolean)FALSE;


   CRKHAL_vidCLEAR_INTERRUPT(TE1);

#if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED)
   if (CRKHAL_bDesynchroThdEnabled != FALSE)
   {
      CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32ToothMaxDuration);
   }
   else
#endif /* CRKHAL_coLOW_RPM_DESYNCHRO */
   {
      CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32StalDetThd);
   }

   if (CRKHAL_bRotationDirection == CRKHAL_bFWD_ROTATION)
   {
      if (CRKHAL_bSynchronized != (boolean)FALSE)
      {
         /* De-synchronisation in case of CRKHAL_udtForceDesynchronisation */
         if (CRKHAL_bDesynchroForcee != (boolean)FALSE)
         {
            ubLocalDesynchroForcee = (boolean)TRUE;
            CRKHAL_vidDesyncManagement();
         }
         /* Disable CDTI in case NTI value is 0 */
         if (  (CRKHAL_snGET_NTI() != 0U)
            && (CRKHAL_bSingularityDetected != (boolean)FALSE) )
         {
            CRKHAL_vidCLEAR_INTERRUPT(CDTI);
            CRKHAL_vidDISABLE_INTERRUPT(CDTI);
            CRKHAL_vidSET_NTI(0U);
         }
      }

      if (ubLocalDesynchroForcee == (boolean)FALSE)
      {
         if (  (CRKHAL_bSynchronized == (boolean)FALSE)
            && (CRKHAL_bRotationDirection == CRKHAL_bFWD_ROTATION) )
         {
            /*u32LocalAptVal = CRKHAL_snGET_GTM_DPLL_APT2c;*/
            u32LocalLastToothDuration = (uint32)(CRKHAL_snGET_TOOTH_PERIOD() );
            u32Local_T1               = *CRKHAL_pu32McsT_2;
            u32Local_T2               = CRKHAL_u32LastToothDurInLtoo1;

            /* Synchronisation Search (1st time only) */
            /*if (((((((Vtd_t_toth[2]) << 1) < (Vtd_t_toth[1])) && ((
               u32LocalLastToothDuration << 1) < (Vtd_t_toth[1]))) && (((Vtd_t_toth[2]) << 3) >
               (Vtd_t_toth[1]))) && ((u32LocalLastToothDuration << 3) > (Vtd_t_toth[1]))) && (
               CRKHAL_u8ToothDirection == UINT8_MIN))*/
            if (  (  (  (  ( ( (u32Local_T2) << 1U) < (u32Local_T1) )
                        && ( (u32LocalLastToothDuration << 1U) < (u32Local_T1) ) )
                     && ( ( (u32Local_T2) << 3U) > (u32Local_T1) ) )
                  && ( (u32LocalLastToothDuration << 3U) > (u32Local_T1) ) )
               && (CRKHAL_bSingularityDetected != (boolean)FALSE) )
            {

               CRKHAL_vidDISABLE_INTERRUPT(CDTI);
               CRKHAL_vidSET_NTI(0U);
               /* set sync found management */
               CRKHAL_vidSyncFoundMngt();
               /* Gets the Engine Angle */

               /* Note - On the engine start or restart, when the 1st long tooth occurs, the DPLL
                * generates only 384 microticks and not 1152 microticks as expected, as the DPLL
                * is not locked. As a result the DeltaAngleOnSync value has an error of 12 degrees.
                * In order to correct this, when the angular counter is stopped and stored
                * in u32LocalCurrAbsAng_1, 12 degrees(768 microticks) is added to this local variable
                * So from the testing point of view, when CRKHAL_u16DeltaAngleOnSynchro is validated,
                * using engine position from CRKHAL_udtGetToothInfo API, there is going to be a difference
                * of 12 degrees(768 microticks) for the engine start and restart.
                */
               if (CRKHAL_bFirstLtoo1Event != (boolean)FALSE)
               {
                  u32LocalCurrAbsAng_1    = CRKHAL_u16GetEngineAngle() + (2U * CRKHAL_u16NORMAL_TOOTH_ANGLE);
                  CRKHAL_bFirstLtoo1Event = (boolean)FALSE;
               }
               else
               {
                  u32LocalCurrAbsAng_1 = CRKHAL_u16GetEngineAngle();
               }
               /* Stop the Angular Counter */
               CRKHAL_vidSTOP_ANG_POS_COUNTER();
               /* resets the Global teeth offsets */
               CRKHAL_u32GlobalTeethOffset = (uint32)UINT32_MIN;

               DGOHAL_vidWrite( (DGOHAL_tudtChannel)DGOHAL_udtCRKHAL,
                                (DGOHAL_tbfStatus)( (uint32)DGOHAL_bfVALID_CRK_LTOO
                                                    | (uint32)DGOHAL_bfVALID_CRK_LTOO1),
                                (DGOHAL_tbfStatus)( (uint32)DGOHAL_bfNO_FAULT_CRK_LTOO
                                                    | (uint32)DGOHAL_bfNO_FAULT_CRK_LTOO1) );
               /* update APTs according to Cylinder Number */
               CRKHAL_vidSYNC_CYLINDER_NUMBER();
               if (CRKHAL_enuCylinderNumber != CRKHAL_udtUNKNOWN_CYLINDER)
               {
                  CRKHAL_vidSynchroCrkTimerConf();
               }
               /* updated Delta on Angle Sync values */
               CRKHAL_vidDeltaOnAngleUpdate(u32LocalCurrAbsAng_1);

               /* configure parameters for Sync found */
               CRKHAL_vidSynchroFound();

               /* update the TOV for more than long tooth */
               CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_NO_GAP);

               CRKHAL_vidENABLE_INTERRUPT(TE0);

            }
         }
         else
         {
            if (  (CRKHAL_bSynchronized != (boolean)FALSE)
               && (CRKHAL_bDirectionChangeDet == (boolean)FALSE) )
            {

               u8LocalAptVal = (uint32)CRKHAL_snGET_GTM_DPLL_APT2c;

               /*
                  if ((CRKHAL_bRestartPhase != (boolean)FALSE) && (CRKHAL_bEnaStopPosAfterCalc
                  != (boolean)FALSE))
                  {
                  update the APT calculation for Stop Angle After
                  if(CRKHAL_u8Apt2c < u8LocalAptVal)
                  {
                   u8LocalAptCal = (u8LocalAptVal - CRKHAL_u8Apt2c);
                  }
                  else
                  {
                   u8LocalAptCal = ((CRKHAL_u16PhyTeethFullScale - CRKHAL_u8Apt2c) + u8LocalAptVal);
                  }
                  CRKHAL_vidStopPosCalculation(&u8LocalAptCal, &CRKHAL_u16StopAngPositionAfter);
                  CRKHAL_bStopPosAfterCalculation = (boolean)TRUE;
                  CRKHAL_bRestartPhase         = (boolean)FALSE;
                  }
                */
               /* Reset the ChangeOfMindEnable */
               if (CRKHAL_bChangeOfMindEnabled != (boolean)FALSE)
               {
                  CRKHAL_bChangeOfMindEnabled  = (boolean)FALSE;
                  *CRKHAL_pu32McsBiDirChgMndEn = (boolean)FALSE;
               }
               if (CRKHAL_bEnaLtooSearchAftRestart != (boolean)FALSE)
               {
                  CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
               }

               u32Local_T2 = (CRKHAL_TOOTH_DUR_ARRAY[u8LocalAptVal - 3U] * 3U);
               u32Local_T1 = CRKHAL_TOOTH_DUR_ARRAY[u8LocalAptVal - 2U];
               u32Local_T0 = (uint32)(CRKHAL_snGET_TOOTH_PERIOD() );
               if (u8LocalAptVal <= 3U)
               {
                  u32Local_T5 = CRKHAL_TOOTH_DUR_ARRAY[(u8LocalAptVal - 6U)
                                                       + CRKHAL_u16PhyTeethFullScale];
                  u32Local_T4 = CRKHAL_TOOTH_DUR_ARRAY[(u8LocalAptVal - 5U)
                                                       + CRKHAL_u16PhyTeethFullScale];
                  u32Local_T3 = CRKHAL_TOOTH_DUR_ARRAY[(u8LocalAptVal - 4U)
                                                       + CRKHAL_u16PhyTeethFullScale];
               }
               else
               {
                  u32Local_T5 = CRKHAL_TOOTH_DUR_ARRAY[(u8LocalAptVal - 6U)];
                  u32Local_T4 = CRKHAL_TOOTH_DUR_ARRAY[(u8LocalAptVal - 5U)];
                  u32Local_T3 = CRKHAL_TOOTH_DUR_ARRAY[(u8LocalAptVal - 4U)];
               }
               /* if long tooth Detected & Rotation direction is Forward */
               if (  (CRKHAL_bSingularityDetected != (boolean)FALSE)
                  && (CRKHAL_bRotationDirection == (boolean)CRKHAL_bFWD_ROTATION) )
               {
                  /** FALSE == CRKHAL_bSingularityDetected -- OR
                   * NOT [Normal case: 2*(Tooth_duration_2) - (Tooth_duration_1) -
                   * (Tooth_duration_3) - (Tooth_duration_4) > 0]  **/
                  /* Normal Tooth */
                  /* if (((sint32)(((Vtd_t_toth[3]) + ((Vtd_t_toth[4]) + (Vtd_t_toth[1
                     ]))) - ((Vtd_t_toth[2]) * 2))) < UINT32_MIN)  **/
                  if ( (2U * u32Local_T2) >= (u32Local_T1 + u32Local_T3 + u32Local_T4) )
                  {

                     if (  (CRKHAL_bRestartPhase != (boolean)FALSE)
                        && (CRKHAL_bEnaStopPosAfterCalc != (boolean)FALSE) )
                     {
                        /*update the APT calculation for Stop Angle After*/
                        CRKHAL_u16StopAngPositionAfter  = CRKHAL_u16StopAngPosition;
                        CRKHAL_bStopPosAfterCalculation = (boolean)TRUE;
                        CRKHAL_bRestartPhase            = (boolean)FALSE;
                        CRKHAL_u8FwdTeeth               = 0U;
                     }

                     /* Normal Tooth */
                     DGOHAL_vidWrite( (DGOHAL_tudtChannel)DGOHAL_udtCRKHAL,
                                      (DGOHAL_tbfStatus)( ( (uint32)DGOHAL_bfVALID_CRK_LTOO
                                                            | (uint32)DGOHAL_bfVALID_CRK_TOO_EXCESS)
                                                          | (uint32)DGOHAL_bfVALID_CRK_TOO_MISS),
                                      (DGOHAL_tbfStatus)( ( (uint32)DGOHAL_bfNO_FAULT_CRK_LTOO
                                                            | (uint32)DGOHAL_bfNO_FAULT_CRK_TOO_EXCESS)
                                                          | (uint32)DGOHAL_bfNO_FAULT_CRK_TOO_MISS) );

                     /* Activate LTOO Event */
                     TSKSRV_vidActivateTask(CRKHAL_LTOO_EVENT);
                  }
                  /* if (((sint32)(((Vtd_t_toth[4]) + ((Vtd_t_toth[5]) + (
                     Vtd_t_toth[2]))) - ((Vtd_t_toth[3]) * 2))) < UINT32_MIN)*/
                  else if ( (2U * u32Local_T3) >= (u32Local_T2 + u32Local_T4 + u32Local_T5) )
                  {
                     /* Missing Tooth */
                     /* 1 Tooth Missing - long one detected, while normal one is expected */

                     u8LocalAptVal = (u8LocalAptVal + 1U);
                     if (u8LocalAptVal > CRKHAL_u16PhyTeethFullScale1Ms)
                     {
                        u8LocalAptVal -= CRKHAL_u16PhyTeethFullScale;
                     }

                     /* update the APTs & Global offset count */

                     /* Adjust APT pointer */
                     u32LocalAptVal_1 = CRKHAL_snGET_GTM_DPLL_APT_APT;
                     u32LocalAptVal_1 = (u32LocalAptVal_1 + 1U);
                     CRKHAL_vidSET_GTM_DPLL_APT_APT(u32LocalAptVal_1);

                     /* Adjust APT2B pointer */
                     if (u8LocalAptVal > CRKHAL_ku16NbPhysTeeth)
                     {
                        CRKHAL_vidSET_GTM_DPLL_APT_APT2b( (u8LocalAptVal + 2U) );
                     }
                     else
                     {
                        CRKHAL_vidSET_GTM_DPLL_APT_APT2b(u8LocalAptVal);
                     }
                     /* Adjust APT2C pointer */
                     CRKHAL_vidSET_GTM_DPLL_APT2c(u8LocalAptVal);

                     /* Adjust the angular clock (add missing ticks) */
                     CRKHAL_vidINCREMENT_ANG_CLOCK();

                     CRKHAL_u16NumOfMissingTooth++;

                     if (  (CRKHAL_bRestartPhase != (boolean)FALSE)
                        && (CRKHAL_bEnaStopPosAfterCalc != (boolean)FALSE) )
                     {
                        /*update the APT calculation for Stop Angle After*/
                        CRKHAL_u16StopAngPositionAfter = CRKHAL_u16StopAngPosition + CRKHAL_u16NORMAL_TOOTH_ANGLE;
                        if (CRKHAL_u16StopAngPositionAfter >= CRKHAL_u32NumberOfMlt_Full)
                        {
                           CRKHAL_u16StopAngPositionAfter = CRKHAL_u16StopAngPositionAfter - CRKHAL_u32NumberOfMlt_Full;
                        }
                        CRKHAL_bStopPosAfterCalculation = (boolean)TRUE;
                        CRKHAL_bRestartPhase            = (boolean)FALSE;
                        CRKHAL_u8FwdTeeth               = 0U;
                     }

                     DGOHAL_vidWrite( (DGOHAL_tudtChannel)DGOHAL_udtCRKHAL,
                                      (DGOHAL_tbfStatus)( ( (uint32)DGOHAL_bfVALID_CRK_LTOO
                                                            | (uint32)DGOHAL_bfVALID_CRK_TOO_EXCESS)
                                                          | (uint32)DGOHAL_bfVALID_CRK_TOO_MISS),
                                      (DGOHAL_tbfStatus)( ( (uint32)DGOHAL_bfNO_FAULT_CRK_LTOO
                                                            | (uint32)DGOHAL_bfNO_FAULT_CRK_TOO_EXCESS)
                                                          | (uint32)DGOHAL_bfFAULT_CRK_TOO_MISS) );

                     /* Activate LTOO Event */
                     TSKSRV_vidActivateTask(CRKHAL_LTOO_EVENT);
                  }
                  /* if (((sint32)(((Vtd_t_toth[2]) + ((Vtd_t_toth[3]) + (Vtd_t_toth[0]))) - ((Vtd_t_toth[1]) * 2))) <
                     UINT32_MIN)**/
                  else if ( (2U * u32Local_T1) >= (u32Local_T2 + u32Local_T3 + u32Local_T0) )
                  {
                     /* Tooth Excess */
                     /* A normal tooth has been detected while a long one was expected
                        TOOTH IN EXCESS */
                     u8LocalAptVal = (u8LocalAptVal - 1U);
                     /* update the APTs & Global offset count */

                     /* Adjust APT pointer */
                     u32LocalAptVal_1 = CRKHAL_snGET_GTM_DPLL_APT_APT;
                     u32LocalAptVal_1 = (u32LocalAptVal_1 - 1U);
                     CRKHAL_vidSET_GTM_DPLL_APT_APT(u32LocalAptVal_1);

                     /* Adjust APT2B pointer */
                     if (u8LocalAptVal > CRKHAL_ku16NbPhysTeeth)
                     {
                        CRKHAL_vidSET_GTM_DPLL_APT_APT2b( (u8LocalAptVal + 2U) );
                     }
                     else
                     {
                        CRKHAL_vidSET_GTM_DPLL_APT_APT2b(u8LocalAptVal);
                     }
                     /* Adjust APT2C pointer */
                     CRKHAL_vidSET_GTM_DPLL_APT2c(u8LocalAptVal);

                     /* Adjust the angular clock (remove ticks in excess) */
                     CRKHAL_vidDECREMENT_ANG_CLOCK();

                     /* ToothInExcess++ - for debugging purpose */
                     CRKHAL_u16NumOfToothInExcess++;

                     if (  (CRKHAL_bRestartPhase != (boolean)FALSE)
                        && (CRKHAL_bEnaStopPosAfterCalc
                            != (boolean)FALSE) )
                     {
                        /*update the APT calculation for Stop Angle After*/
                        if (CRKHAL_u16StopAngPosition < CRKHAL_u16NORMAL_TOOTH_ANGLE)
                        {
                           CRKHAL_u16StopAngPositionAfter = CRKHAL_u16StopAngPositionAfter + CRKHAL_u32NumberOfMlt_Full;
                        }
                        CRKHAL_u16StopAngPositionAfter = CRKHAL_u16StopAngPosition - CRKHAL_u16NORMAL_TOOTH_ANGLE;

                        CRKHAL_bStopPosAfterCalculation = (boolean)TRUE;
                        CRKHAL_bRestartPhase            = (boolean)FALSE;
                        CRKHAL_u8FwdTeeth               = 0U;
                     }

                     DGOHAL_vidWrite( (DGOHAL_tudtChannel)DGOHAL_udtCRKHAL,
                                      (DGOHAL_tbfStatus)( ( (uint32)DGOHAL_bfVALID_CRK_LTOO
                                                            | (uint32)DGOHAL_bfVALID_CRK_TOO_EXCESS)
                                                          | (uint32)DGOHAL_bfVALID_CRK_TOO_MISS),
                                      (DGOHAL_tbfStatus)( ( (uint32)DGOHAL_bfNO_FAULT_CRK_LTOO
                                                            | (uint32)DGOHAL_bfFAULT_CRK_TOO_EXCESS)
                                                          | (uint32)DGOHAL_bfNO_FAULT_CRK_TOO_MISS) );

                     /* Activate LTOO Event */
                     TSKSRV_vidActivateTask(CRKHAL_LTOO_EVENT);

                  }
                  else
                  {
                     /* No Normal tooth, No Missing Tooth or No Tooth in Excess */
                     CRKHAL_bLtooFaultOccur = (boolean)TRUE;
                  }
               }
               else
               {
                  /* No long tooth (CRKHAL_bSingularityDetected) Detected */
                  CRKHAL_bLtooFaultOccur = (boolean)TRUE;
               }
               /* if LTOO Fault Occur - Desync */
               if (CRKHAL_bLtooFaultOccur != (boolean)FALSE)
               {

                  DGOHAL_vidWrite( (DGOHAL_tudtChannel)DGOHAL_udtCRKHAL,
                                   (DGOHAL_tbfStatus)DGOHAL_bfVALID_CRK_LTOO,
                                   (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CRK_LTOO);

                  CRKHAL_vidDesyncManagement();
               }
               else
               {
                  CRKHAL_vidDISABLE_INTERRUPT(TE1);

                  /* update the TOV for more than long tooth */
                  CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_NO_GAP);
               }
            }
         }
      }
      CRKHAL_bSingularityDetected = (boolean)FALSE;
   }
   else
   {
      /* update the TOV for more than long tooth */
      CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_CHECK_GAP);
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidEngStopManagement                                 */
/* !Description : Engine Stop Management                                      */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidEngStopManagement(void)
{

   /* Reset the variables */
   CRKHAL_bDesynchroForcee = (boolean)FALSE;
   CRKHAL_vidSIGNAL_LOSS();

   CRKHAL_ubNutcCheck           = (boolean)FALSE;
   CRKHAL_ubGliLockStatus       = (boolean)FALSE;
   CRKHAL_bChangeOfDirTaskEvent = (boolean)FALSE;
   *CRKHAL_pu32McsEngineStatus  = MCS_NO_RUN;
   CRKHAL_vidDPLL_DISABLE();
   CRKHAL_vidDISABLE_INTERRUPT(CDTI);
   *CRKHAL_pu32McsToothCnt = (uint32)(*CRKHAL_pu32McsToothCnt - 1U);
   CRKHAL_bFirstLtoo1Event = (boolean)TRUE;
   /* Reset the Quick synchronisation related variable accordingly */
   if (CRKHAL_bEngPositionKnown != (boolean)FALSE)
   {
      if (CRKHAL_snGET_GTM_DPLL_APT2c == 0U)
      {
         CRKHAL_u8Apt2c = CRKHAL_u16PhyTeethFullScale1Ms;
      }
      else
      {
         CRKHAL_u8Apt2c = (uint8)(CRKHAL_snGET_GTM_DPLL_APT2c - 1U);
      }

      if (CRKHAL_bBwdRotationPhase != (boolean)FALSE)
      {
         CRKHAL_u8Apt2c = (CRKHAL_u8Apt2c + 2U);
      }

      /* update the Stop Position According to Long tooth or Normal Tooth */
      CRKHAL_vidStopPosCalculation(&CRKHAL_u8Apt2c, &CRKHAL_u16StopAngPosition);

      CRKHAL_bStopPosCalculation  = (boolean)TRUE;
      CRKHAL_bRestartPhase        = (boolean)TRUE;
      CRKHAL_bEnaStopPosAfterCalc = (boolean)TRUE;
      if (CRKHAL_bQuickSynchroEnabled != (boolean)FALSE)
      {
         CRKHAL_bEnaLtooSearchAftRestart = (boolean)TRUE;
      }
   }
   else
   {
      CRKHAL_bStopPosCalculation  = (boolean)FALSE;
      CRKHAL_bRestartPhase        = (boolean)FALSE;
      CRKHAL_bEnaStopPosAfterCalc = (boolean)FALSE;
   }
   /* Activate N_INV event */
   if (CRKHAL_bBwdRotationPhase != (boolean)FALSE)
   {
      TSKSRV_vidActivateTask(CRKHAL_N_INV_OFF_EVENT);

      if (*CRKHAL_pu32McsPulseDiagCounter > 0U)
      {
         *CRKHAL_pu32McsPulseDiagCounter = (*CRKHAL_pu32McsPulseDiagCounter - 1U);
      }

   }
   CRKHAL_bBwdRotationPhase     = (boolean)FALSE;
   CRKHAL_bChangeOfMindEnabled  = (boolean)FALSE;
   *CRKHAL_pu32McsBiDirChgMndEn = (boolean)FALSE;
   CRKHAL_bRotationDirection    = CRKHAL_bFWD_ROTATION;

   /* CRKHAL_bStopPosAfterCalculation = (boolean)FALSE; */
#if (CRKHAL_coBIDIR_PULSE_DIAG == CRKHAL_coENABLED)
   /* CRKHAL_vidWRITE_BIDIR_PULSE_DUR((uint32) CRKHAL_ku16BiDirFwdPulseDurMax); */
   *CRKHAL_pu32McsBiDirDiaEn = (boolean)FALSE;
#endif /* CRKHAL_coBIDIR_PULSE_DIAG */

   if (CRKHAL_bDetection != (boolean)FALSE)
   {
      /*Re-enable All the interrupts....*/
      CRKHAL_vidENABLE_INTERRUPT(NEWVAL);
   }
   /* Reset the McsFirstEdge */
   CRKHAL_bMcsFirstEdge = FALSE;
   /* Resets MCS variables */
   IfxGtm_vidMcsResetVars();
   if (*CRKHAL_pu32McsTeeAfrLastSyLos > 0U)
   {
      *CRKHAL_pu32McsTeeAfrLastSyLos = (*CRKHAL_pu32McsTeeAfrLastSyLos - 1U);
   }
   /* Disable GLI & LLI interrupts */
   CRKHAL_vidDISABLE_INTERRUPT(GLI);
   CRKHAL_vidDISABLE_INTERRUPT(LLI);
   /**CRKHAL_pu32McsTeeAfrLastSyLos = (uint32)UINT32_MIN;*/

   /* Disable Direction Management Flags for Bidirection */
   if (CRKHAL_bEnaBwdRotationDetection != (boolean)FALSE)
   {
      CRKHAL_vidDISABLE_INTERRUPT(DIR);
      CRKHAL_vidSET_TRIGGER_HOLD_TIME(0U);
      /*CRKHAL_u32BiDirFwdToothCnt = *CRKHAL_pu32McsBiDirFwdCnt;
         CRKHAL_u32BiDirBwdToothCnt = *CRKHAL_pu32McsBiDirBwdCnt;*/
      *CRKHAL_pu32McsDirCfgEn = (boolean)FALSE;
   }
   CRKHAL_vidCLEAR_INTERRUPT(MCS);
   /* Disable MCS */
   CRKHAL_vidDISABLE_INTERRUPT(MCS);
   /* Activate CRK OFF Event */
   TSKSRV_vidActivateTask(CRKHAL_CRK_OFF_EVENT);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidCrkOnMngtIsr                                      */
/* !Description : This will be raised when First time after 'N' Teeth         */
/*                Detection                                                   */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(IfxCRK_CDTI, 0, CDTI_INT_PRIO) */
void CRKHAL_vidCrkOnMngtIsr(void)
{

   CRKHAL_vidCLEAR_INTERRUPT(CDTI);
   CRKHAL_vidDISABLE_INTERRUPT(CDTI);

   /* First time */
   if (CRKHAL_bRunning == (boolean)FALSE)
   {
      CRKHAL_bDetected = (boolean)TRUE;
      /* 320ms for CRK_OFF */
      CRANKHAL_vidSET_CRANKOFF_DELAY(CRKHAL_u32OffCrkDly);
      CRKHAL_vidENABLE_TIMEOUT(CRK_OFF);
      CRKHAL_vidENABLE_INTERRUPT(CRK_OFF);


      /* Activate CRANK ON Event */
      TSKSRV_vidActivateTask(CRKHAL_CRK_ON_EVENT);
   }
   else
   {
      /*No Sync Found within <CRKHAL_ku8MaxNbTeethWithoutLtoo> teeth*/
      if (CRKHAL_bEnaLtooSearchAftRestart != (boolean)FALSE)
      {

         DGOHAL_vidWrite( (DGOHAL_tudtChannel)DGOHAL_udtCRKHAL,
                          (DGOHAL_tbfStatus)DGOHAL_bfVALID_CRK_LTOO,
                          (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CRK_LTOO);
         CRKHAL_u16NumOfSyncLoss++;
         CRKHAL_bEngPositionKnown        = (boolean)FALSE;
         CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
         CRKHAL_vidSynchroLost();
         CRKHAL_vidSyncLossEntry();
         TSKSRV_vidActivateTask(CRKHAL_TOLO_EVENT);
      }
      else
      {
         DGOHAL_vidWrite( (DGOHAL_tudtChannel)DGOHAL_udtCRKHAL,
                          (DGOHAL_tbfStatus)DGOHAL_bfVALID_CRK_LTOO1,
                          (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CRK_LTOO1);
      }
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidTimCrkInputToDpllIsr                              */
/* !Description : Tim0 Ch 0 Interrupt                                         */
/*                To manage the NewVal and Timeout detection unit Interrupts  */
/*                of the TIM0_CH0 module.                                     */
/*                The TIM0_CH0 provides the CRK Timestamps to the DPLL.       */
/*                                                                            */
/*                This will be raised when First time when New Val is detected*/
/*                Time Out Detection for STALL                                */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(IfxCrk_tim00Isr, 0, TIM00_INT_PRIO) */
void CRKHAL_vidTimCrkInputToDpllIsr(void)
{
   if (CRKHAL_GetIRQ_NOTIFY(TIM_ENG_STALL) != (boolean)FALSE)
   {
      /* Clear Engine Stall Management */
      CRKHAL_vidCLEAR_INTERRUPT(ENG_STALL);

#if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED)
      if (CRKHAL_bDesynchroThdEnabled != (boolean)FALSE)
      {
         if (CRKHAL_bSynchronized != (boolean)FALSE)
         {
            CRKHAL_u16NumOfSyncLoss++;
            CRKHAL_vidSynchroLost();
            CRKHAL_vidSyncLossEntry();
            TSKSRV_vidActivateTask(CRKHAL_LOW_RPM_TOLO_EVENT);
            TSKSRV_vidActivateTask(CRKHAL_TOLO_EVENT);
            CRKHAL_bEngPositionKnown        = (boolean)FALSE;
            CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
            CRKHAL_ubGliLockStatus          = (boolean)FALSE;
            /**CRKHAL_pu32McsTeeAfrLastSyLos  = 1U;*/
            *CRKHAL_pu32McsEngineStatus = MCS_RUN;
            CRKHAL_vidDISABLE_INTERRUPT(TE0);
            CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_NO_GAP);
         }
      }
      else
#endif /* if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED) */
      {
         CRKHAL_vidDISABLE_INTERRUPT(ENG_STALL);
         CRKHAL_vidDISABLE_TIMEOUT(ENG_STALL);
         /* Stall detected */
         CRKHAL_vidStallDetection();
      }
   }
   else
   {
      /* NEWVAL detected - An edge is detected on CRANK */
      if (CRKHAL_GetIRQ_NOTIFY(TIM_NEWVAL) != (boolean)FALSE)
      {
         CRKHAL_vidCLEAR_INTERRUPT(NEWVAL);
         CRKHAL_vidREENABLE_ANG_TMR_CNT(); /* ReEnables during CRK OFF */
         CRKHAL_vidDPLL_ENABLE();          /* Enable DPLL */
         /* update the Minimum value for CRANK_ON to NTI */
         if (CRKHAL_bREAD_EDGE_LEVEL() != (boolean)STD_HIGH)
         {
            CRKHAL_vidSET_NTI(CRKHAL_ku8CrkOnToothNr - 1U);
         }
         else
         {
            CRKHAL_vidSET_NTI(CRKHAL_ku8CrkOnToothNr);
         }
         /* Enable CDTI interrupt for CRANK ON */
         CRKHAL_vidENABLE_INTERRUPT(CDTI);

         /* Disable NEWVAL */
         CRKHAL_vidDISABLE_INTERRUPT(NEWVAL);
         /* Enable MCS */
         CRKHAL_vidENABLE_MCS();
         CRKHAL_vidENABLE_INTERRUPT(MCS);

         if (CRKHAL_bEnaBwdRotationDetection != (boolean)FALSE)
         {
            *CRKHAL_pu32McsBiDirEn = (boolean)TRUE;
            if (  (CRKHAL_bQuickSynchroEnabled != (boolean)FALSE)
               && (CRKHAL_bEngPositionKnown != (boolean)FALSE) )
            {
               /*MCS enabled in order to provide tooth event after 3 FWD teeth*/
               *CRKHAL_pu32McsBiDirChgMndEn = (boolean)TRUE;
               /*CRKHAL_bFwdCntCfg = (boolean)FALSE;*/
            }
         }

#if (CRKHAL_coBIDIR_PULSE_DIAG == CRKHAL_coENABLED)
         /* CRKHAL_vidWRITE_BIDIR_PULSE_DUR((uint32) CRKHAL_ku16BiDirFwdPulseDurMax); */
         *CRKHAL_pu32McsBiDirDiaEn = (boolean)TRUE;
#endif /* CRKHAL_coBIDIR_PULSE_DIAG */
      }
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidTimCrkInputToMcsIsr                               */
/* !Description : To manage the Timeout detection unit Interrupt of the       */
/*                TIM0_CH1 module                                             */
/*                The TIM0_CH1 measures the CRK period and duty and the       */
/*                results (period/duty) are sent automatically to the MCS     */
/*                module for further processing.                              */
/*                                                                            */
/*                This will be raised when Time Out Detection has occured     */
/*                after CRK_OFF Delay                                         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(IfxCrk_tim01Isr, 0, TIM01_INT_PRIO) */
void CRKHAL_vidTimCrkInputToMcsIsr(void)
{
   CRKHAL_vidDISABLE_INTERRUPT(MCS);
   if (CRKHAL_GetIRQ_NOTIFY(TIM_CRK_OFF) != (boolean)FALSE)
   {
      CRKHAL_vidCLEAR_INTERRUPT(CRK_OFF);
      /* CRK-OFF Management */
      if (CRKHAL_bDetected != (boolean)FALSE)
      {
         /* Stall detected if CRKHAL_ku32OffCrkDly < CRKHAL_ku32StalDetThd */
         if (CRKHAL_ku32OffCrkDly < CRKHAL_ku32StalDetThd)
         {
            CRKHAL_vidCLEAR_INTERRUPT(ENG_STALL);
            CRKHAL_vidDISABLE_INTERRUPT(ENG_STALL);
            CRKHAL_vidDISABLE_TIMEOUT(ENG_STALL);

            CRKHAL_vidStallDetection();
         }
         /* Engine Stop Management due to Crank off Delay */
         CRKHAL_vidEngStopManagement();
      }
      CRKHAL_vidDISABLE_INTERRUPT(CRK_OFF);
      CRKHAL_vidDISABLE_TIMEOUT(CRK_OFF);
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidMcsTaskMgmtIsr                                    */
/* !Description : Tooth Task Management Interrupt                             */
/*                This will be called from MCS during                         */
/*                Initially during First time Synchronisation for Engine       */
/*                Management to handle STALL threshold management             */
/*                Interrupt on every tooth below certain RPM threshold value  */
/*                (CRKHAL_TOOTH_EVENT).                                       */
/*                Configuration of Direction Detection (THMI) for below threshold */
/*                THMI value after reaching greater threshold configure THMI to*/
/*                0.                                                          */
/*                3 Forward Tooth Interrupt for Quick sync & Change of Mind   */
/*                Quick Synchronisation & Change of Mind enable feature       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(CRKHAL_vidMcsTaskMgmtIsr, 0, MCS0_INT_PRIO) */
void CRKHAL_vidMcsTaskMgmtIsr(void)
{
   uint32 u32LocalAptVal_1;
   uint32 u32LocalAptVal_2c;
   uint32 u32LocalAptVal_2b;
   uint32 u32LocalCurrDutation = (uint32)(CRKHAL_snGET_TOOTH_PERIOD() );
   uint32 u32LocalCurrAbsAng   = (uint32)UINT32_MIN;
   uint32 u32LocalPrevToothDur = *CRKHAL_pu32McsPrevToothDur;
   uint32 u32LocalTeethDurationMin;
   uint32 u32LocalUpdatedAngAct;
   uint32 u32LocalUpdatedAngCal;


   CRKHAL_vidCLEAR_INTERRUPT(MCS);

   /* Reset MCS variable */
   if (CRKHAL_bMcsFirstEdge == (boolean)FALSE)
   {
      *CRKHAL_pu32McsBiDirFwdCnt = (uint32)UINT32_MIN;
      *CRKHAL_pu32McsBiDirBwdCnt = (uint32)UINT32_MIN;
      CRKHAL_bMcsFirstEdge       = TRUE;
   }

   if (CRKHAL_bDetected != (boolean)FALSE)
   {
      /* to verify the engine run condition */
      if (  (CRKHAL_bRunning == (boolean)FALSE)
         && (u32LocalCurrDutation < CRKHAL_u32EngRunThDuration) )
      {
         /* copy number of fwd tooth count */
         CRKHAL_u8FwdTeeth = (uint8) * CRKHAL_pu32McsBiDirFwdCnt;
         if (CRKHAL_bEngPositionKnown != (boolean)FALSE)
         {
            /* MCS enabled in order to provide tooth event after 3 FWD teeth */
            *CRKHAL_pu32McsBiDirChgMndEn = (boolean)TRUE;
            *CRKHAL_pu32McsBiDirFwTotCfg = (*CRKHAL_pu32McsBiDirFwdCnt + 1U);
         }
         /* Running threshold detected */
         CRKHAL_vidEngRun();
      }
      /* For Bidirectional Sensor support */
      if (CRKHAL_bEnaBwdRotationDetection != (boolean)FALSE)
      {
         /* For Bidirectional Sensor support configure the THMI register accordingly */
         CRKHAL_vidCfgDirDetThreshold();
      }

      /* Set to Synchronisation in case for change of Mind Enabled or Quick synchronisation enabled */
      if (  (CRKHAL_bChangeOfMindEnabled != (boolean)FALSE)
         || (CRKHAL_bQuickSynchroEnabled != (boolean)FALSE) )
      {
         /* check for the conditions for Synchronisation */
         if (  (CRKHAL_bSynchroEnable != (boolean)FALSE)
            && (CRKHAL_bRunning != (boolean)FALSE)
            && (CRKHAL_bRotationDirection == CRKHAL_bFWD_ROTATION) )
         {
            /* Check for Synchronised status and Minimum Forward Tooth count to set
             * sync  */
            if (  (CRKHAL_bSynchronized == (boolean)FALSE)
               && (CRKHAL_bEnaLtooSearchAftRestart != (boolean)FALSE) )
            {
               if ( (*CRKHAL_pu32McsBiDirFwdCnt - CRKHAL_u8FwdTeeth) >= CRKHAL_u8MAX_CNT_TO_FWDDir)
               {
                  /** Synchronisation found management */
                  *CRKHAL_pu32McsEngineStatus = MCS_SYNC;
                  /**CRKHAL_pu32McsTeeAfrLastSyLos = (*CRKHAL_pu32McsTeeAfrLastSyLos - 1U);*/
                  CRKHAL_u32ToothCntLtoo1event = (uint8)(*CRKHAL_pu32McsToothCnt);
                  if (CRKHAL_bChangeOfMindEnabled == (boolean)FALSE)
                  {
                     u32LocalCurrAbsAng = CRKHAL_u16GetEngineAngle();
                     /* The Angular Counter needs to be updated */
                     CRKHAL_vidSTOP_ANG_POS_COUNTER();
                     u32LocalAptVal_2c = CRKHAL_u8Apt2c + 2U + (*CRKHAL_pu32McsBiDirFwdCnt - *CRKHAL_pu32McsBiDirBwdCnt);
                     /* update APT2c accordingly */
                     if (u32LocalAptVal_2c > CRKHAL_u16PhyTeethFullScale1Ms)
                     {
                        u32LocalAptVal_2c -= CRKHAL_u16PhyTeethFullScale;
                     }
                     /* update APT2b accordingly */
                     u32LocalAptVal_2b = u32LocalAptVal_2c;
                     /* APT pointer correction*/
                     if (u32LocalAptVal_2c == 0U)
                     {
                        CRKHAL_vidSET_GTM_DPLL_APT_APT(CRKHAL_u16PhyTeethFullScale1Ms);
                     }
                     else
                     {
                        CRKHAL_vidSET_GTM_DPLL_APT_APT( (u32LocalAptVal_2c - 1U) );
                     }
                     /* update APT2B pointer*/
                     if (u32LocalAptVal_2b > CRKHAL_ku16NbPhysTeeth)
                     {
                        u32LocalAptVal_2b = (u32LocalAptVal_2b + 2U);
                     }
                     if (u32LocalAptVal_2c == 0U)
                     {
                        CRKHAL_vidSET_GTM_DPLL_APT_APT2b(CRKHAL_u16BegSecondLongTooth);
                     }
                     else
                     {
                        CRKHAL_vidSET_GTM_DPLL_APT_APT2b(u32LocalAptVal_2b);
                     }
                     CRKHAL_vidSET_GTM_DPLL_APT2c(u32LocalAptVal_2c);
                     /* update Delta on Angle management */
                     *CRKHAL_pu32McsLtoo1event = 1U;
                     u32LocalAptVal_1          = CRKHAL_snGET_GTM_DPLL_APT_APT2b;
                     /* Angle calculation depends on APT (tooth) pointer */
                     if (u32LocalAptVal_1 == 0u)
                     {
                        u32LocalUpdatedAngCal = CRKHAL_u16BegSecondLongTooth * CRKHAL_u16NORMAL_TOOTH_ANGLE;
                     }
                     else
                     {
                        u32LocalUpdatedAngCal = ( (u32LocalAptVal_1 - 1U) * CRKHAL_u16NORMAL_TOOTH_ANGLE);
                     }
                     /* update TBU angle as per calculated */
                     CRKHAL_TBU_ANGLE            = u32LocalUpdatedAngCal;
                     CRKHAL_u32GlobalTeethOffset = (uint32)UINT32_MIN;
                     u32LocalUpdatedAngAct       = CRKHAL_u16TbuConvRelToAbsAng(u32LocalUpdatedAngCal);
                     /* Calculate Delta on Angle accordingly */
                     if (u32LocalUpdatedAngAct > u32LocalCurrAbsAng)
                     {
                        CRKHAL_u16DeltaAngleOnSynchro = (uint16)(u32LocalUpdatedAngAct - u32LocalCurrAbsAng);
                     }
                     else
                     {
                        CRKHAL_u16DeltaAngleOnSynchro =
                           (uint16)( (u32LocalUpdatedAngAct + CRKHAL_u16EngineCycleAngle) - u32LocalCurrAbsAng);
                     }
                     /* update Angular alarm accordingly */
                     if ( ( (uint16)CRKHAL_u16DeltaAngleOnSynchro) != (uint16)UINT16_MIN)
                     {
                        CRKHAL_vidUpdateAngAlarms( (uint16)CRKHAL_u16DeltaAngleOnSynchro);
                     }
                     CRKHAL_u32Ltoo1TbuValue = CRKHAL_u16GetEngineAngle();
                     CRKHAL_vidSTART_ANG_POS_COUNTER();
                  }
                  else
                  {
                     u32LocalAptVal_2b = GTM_DPLL_APT2C_READ;
                     if (u32LocalAptVal_2b > CRKHAL_ku16NbPhysTeeth)
                     {
                        u32LocalAptVal_2b = (u32LocalAptVal_2b + 2U);
                     }
                     else
                     {
                        if (u32LocalAptVal_2b == 0U)
                        {
                           u32LocalAptVal_2b = CRKHAL_u16BegSecondLongTooth;
                        }
                     }
                     CRKHAL_vidSET_GTM_DPLL_APT_APT2b(u32LocalAptVal_2b);
                     CRKHAL_u16DeltaAngleOnSynchro = 0U;
                  }
                  /* Sync found entry */
                  CRKHAL_vidSyncFoundEntry();
                  /* Set synchronisation conditions */
                  CRKHAL_bSynchronized    = (boolean)TRUE;
                  CRKHAL_bEngSynchronized = (boolean)TRUE;

                  CRKHAL_bEngPositionKnown = (boolean)TRUE;
                  /* Activate LT001 Event */
                  TSKSRV_vidActivateTask(CRKHAL_LTOO1_EVENT);
                  /* Enable TE0 interrupt */
                  CRKHAL_vidENABLE_INTERRUPT(TE0);
                  CRKHAL_vidENABLE_INTERRUPT(GLI);
                  CRKHAL_vidENABLE_INTERRUPT(LLI);
               }
            }
         }
      }

      u32LocalTeethDurationMin = MATHSRV_udtMIN(u32LocalCurrDutation, u32LocalPrevToothDur);

      /*Generate an Interrupt only in case of speed < IfxCRK_pGtmMcs0EngineSpeedThd*/
      if (  (u32LocalTeethDurationMin >= *CRKHAL_pu32McsEngineSpeedThd)
         || (  (CRKHAL_bChangeOfDirTaskEvent != (boolean)FALSE)
            && (CRKHAL_bEnaBwdRotationDetection != (boolean)FALSE) ) )
      {
         TSKSRV_vidActivateTask(CRKHAL_TOOTH_EVENT);
      }

      if (CRKHAL_bChangeOfDirTaskEvent != (boolean)FALSE)
      {
         CRKHAL_bChangeOfDirTaskEvent = (boolean)FALSE;
      }
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidStartOfSyncWinIsr                                 */
/* !Description : TRIGGER event interrupt 0                                   */
/*                This will be raised as per configuration (see TE0 in ADT_T) */
/*                at beginning of every synchronization window                */
/*                                                                            */
/*                Setup the Stall Threshold to 3x100ms                        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(IfxCRK_te0Isr, 0, TE0_INT_PRIO) */
void CRKHAL_vidStartOfSyncWinIsr(void)
{
   CRKHAL_vidCLEAR_INTERRUPT(TE0);

   if (CRKHAL_bRotationDirection == CRKHAL_bFWD_ROTATION) /* need to check status..for contus MTI in bwd */
   {
      /* update TOV value to Normal value to detect Gap */
      CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_CHECK_GAP);
      /* Re enable TE1  */
      CRKHAL_vidENABLE_INTERRUPT(TE1);
   }
   else
   {
      /* update TOV value to Normal value to detect Gap */
      CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_NO_GAP);
   }


#if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED)
   if (CRKHAL_bDesynchroThdEnabled != FALSE)
   {
      CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32LongToothMaxDuration);
   }
   else
#endif /* CRKHAL_coLOW_RPM_DESYNCHRO */
   {
      CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32LongToothStalDetThd);
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidUpdateIntAngOffIsr                                */
/* !Description : TRIGGER event interrupt 2                                   */
/*                This will be raised as per configuration every 0th Teeth    */
/*                [720deg] (see TE2 in ADT_T profile)                         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(IfxCRK_te2Isr, 0, TE2_INT_PRIO) */
void CRKHAL_vidUpdateIntAngOffIsr(void)
{
   CRKHAL_vidCLEAR_INTERRUPT(TE2);
   if (  (CRKHAL_bSynchronized != (boolean)FALSE)
      && (CRKHAL_bRotationDirection != (boolean)CRKHAL_bBWD_ROTATION) )
   {
      /* It means Tooth 0, need to update the offset */
      CRKHAL_u32GlobalTeethOffset = ( (uint32)CRKHAL_vidREAD_ANGULAR_COUNTER() + 1U);
   }
   else
   {
      if (CRKHAL_bRotationDirection == (boolean)CRKHAL_bBWD_ROTATION)
      {
         CRKHAL_u32GlobalTeethOffset = ( (uint32)CRKHAL_vidREAD_ANGULAR_COUNTER() + 1U);
         CRKHAL_u32GlobalTeethOffset = (CRKHAL_u32GlobalTeethOffset - CRKHAL_u16NORMAL_TOOTH_ANGLE);
      }
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDpllGetLockIsr                                    */
/* !Description : DPLL Get of lock interrupt                                  */
/*                If DPLL locks this Interrupt will be raised                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/* IFX_INTERRUPT(Ifx_gliIsr, 0, GLI_INT_PRIO) */
void CRKHAL_vidDpllGetLockIsr(void)
{
   CRKHAL_ubGliLockStatus = (boolean)TRUE;
   CRKHAL_vidCLEAR_INTERRUPT(GLI);
}


/******************************************************************************/
/* !FuncName    : CRKHAL_vidSynchroFound                                      */
/* !Description : Synchronisation finding management                          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidSynchroFound(void)
{
   CRKHAL_vidSyncFoundEntry();

   CRKHAL_bSynchronized            = (boolean)TRUE;
   CRKHAL_bEngSynchronized         = (boolean)TRUE;
   CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
   CRKHAL_bEngPositionKnown        = (boolean)TRUE;

   TSKSRV_vidActivateTask(CRKHAL_LTOO1_EVENT);
   TSKSRV_vidActivateTask(CRKHAL_LTOO_EVENT);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSynchroLost                                       */
/* !Description : Synchronization losing management                           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidSynchroLost(void)
{
   CRKHAL_vidSYNC_LOSS();
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSynchroCrkTimerConf                               */
/* !Description : Counter Position initialisation when synchronisation is     */
/*                found                                                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidSynchroCrkTimerConf(void)
{
   uint8 u8LocalAPT2cTooth;
   uint8 u8LocalAPT2bToothCal;
   uint8 u8LocalAPTOffsetSync = 3U;


   switch (CRKHAL_enuCylinderNumber)
   {
      case CRKHAL_udtFIRST_CYLINDER:
         CRKHAL_u16SynchroApt2cPosition = CRKHAL_ku16SyncApt2cAtFirstCyl;  /*3*/
         CRKHAL_u16SynchroApt2bPosition = CRKHAL_ku16SyncApt2bAtFirstCyl;  /*3*/
         break;

      case CRKHAL_udtSECOND_CYLINDER:
         CRKHAL_u16SynchroApt2cPosition = CRKHAL_ku16SyncApt2cAtSecondCyl;  /*61*/
         CRKHAL_u16SynchroApt2bPosition = CRKHAL_ku16SyncApt2bAtSecondCyl;  /*63*/
         break;

      case CRKHAL_udtTHIRD_CYLINDER:
         CRKHAL_u16SynchroApt2cPosition = CRKHAL_ku16SyncApt2cAtThirdCyl;
         CRKHAL_u16SynchroApt2bPosition = CRKHAL_ku16SyncApt2bAtThirdCyl;
         break;

      case CRKHAL_udtFOURTH_CYLINDER:
         CRKHAL_u16SynchroApt2cPosition = CRKHAL_ku16SyncApt2cAtFourthCyl;
         CRKHAL_u16SynchroApt2bPosition = CRKHAL_ku16SyncApt2bAtFourthCyl;
         break;

      case CRKHAL_udtUNKNOWN_CYLINDER:
      default:
         CRKHAL_u16SynchroApt2cPosition = CRKHAL_ku16SyncApt2cAtFirstCyl;
         CRKHAL_u16SynchroApt2bPosition = CRKHAL_ku16SyncApt2bAtFirstCyl;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   if (CRKHAL_bAptPtrReset != (boolean)FALSE)
   {
      u8LocalAPT2cTooth = (uint8)(CRKHAL_u16SynchroApt2cPosition)
                          - u8LocalAPTOffsetSync;
      u8LocalAPT2bToothCal = (uint8)(CRKHAL_u16SynchroApt2bPosition)
                             - u8LocalAPTOffsetSync;
      CRKHAL_bAptPtrReset = (boolean)FALSE;
   }
   else
   {
      u8LocalAPT2cTooth    = (uint8)(CRKHAL_u16SynchroApt2cPosition);
      u8LocalAPT2bToothCal = (uint8)(CRKHAL_u16SynchroApt2bPosition);
   }
   CRKHAL_vidSET_GTM_DPLL_APT_APT2b(u8LocalAPT2bToothCal);
   CRKHAL_vidSET_GTM_DPLL_APT2c(u8LocalAPT2cTooth);
   /**CRKHAL_pu32McsGlobalOffsetCnt = u8LocalAPT2cTooth;*/
}


/******************************************************************************/
/* !FuncName    : CRKHAL_vidForceSignalLoss                                   */
/* !Description : This function updates the configurations Signal Loss is     */
/*                forced found                                                */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidForceSignalLoss(void)
{

   CRKHAL_vidSTOP_ANG_POS_COUNTER();
   CRKHAL_vidDisableTim();

   /**CRKHAL_pu32McsTeeAfrLastSyLos = (uint32)UINT32_MIN;*/
   *CRKHAL_pu32McsEngineStatus = MCS_NO_RUN;
   /* Resets MCS variables */
   IfxGtm_vidMcsResetVars();
   /* Disable MCS */
   CRKHAL_vidDISABLE_MCS();

   CRKHAL_vidDPLL_DIS_INTR();

   CRKHAL_vidDisableTimeOut();

   CRKHAL_vidDPLL_DISABLE();
   if (CRKHAL_bSynchronized != (boolean)FALSE)
   {
      CRKHAL_bEngPositionKnown        = (boolean)FALSE;
      CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
      CRKHAL_bChangeOfMindEnabled     = (boolean)FALSE;
      *CRKHAL_pu32McsBiDirChgMndEn    = (boolean)FALSE;
      CRKHAL_vidSyncLossEntry();
      TSKSRV_vidActivateTask(CRKHAL_TOLO_EVENT);
   }
   CRKHAL_vidSYNC_LOSS();
   if (CRKHAL_bRunning != (boolean)FALSE)
   {
      TSKSRV_vidActivateTask(CRKHAL_ENG_STAL_EVENT);
   }
   CRKHAL_vidRUN_TO_STALL();
   if (CRKHAL_bDetected != (boolean)FALSE)
   {
      TSKSRV_vidActivateTask(CRKHAL_CRK_OFF_EVENT);
   }
   CRKHAL_vidSIGNAL_LOSS();
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSyncFoundMngt                                     */
/* !Description : This function updates the necessary variable responsible for*/
/*                Sync Found management                                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/

void CRKHAL_vidSyncFoundMngt(void)
{
   *CRKHAL_pu32McsEngineStatus = MCS_SYNC;

   /**CRKHAL_pu32McsTeeAfrLastSyLos = (*CRKHAL_pu32McsTeeAfrLastSyLos - 1U);*/

   CRKHAL_u32ToothCntLtoo1event = (uint8)(*CRKHAL_pu32McsToothCnt);

   CRKHAL_bChangeOfMindEnabled  = (boolean)FALSE;
   *CRKHAL_pu32McsBiDirChgMndEn = (boolean)FALSE;
   CRKHAL_bRestartPhase         = (boolean)FALSE;
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDeltaOnAngleUpdate                                */
/* !Description : Delta on angle sync management                              */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidDeltaOnAngleUpdate(uint32 u32LocalCurrAbsAng_1)
{
   uint32 u32LocalAptVal_1;
   uint32 u32LocalUpdatedAngAct;
   uint32 u32LocalUpdatedAngCal;


   u32LocalAptVal_1 = CRKHAL_snGET_GTM_DPLL_APT2c;
   /* Angle calculation depends on APT (tooth) pointer */
   u32LocalUpdatedAngCal = ( (u32LocalAptVal_1 - 1U) * CRKHAL_u16NORMAL_TOOTH_ANGLE); /* 64*2 */

   /* update Angle counter */
   if (u32LocalAptVal_1 > CRKHAL_u16PhyTeeth1Minus)
   {
      u32LocalUpdatedAngCal += (2U * CRKHAL_u16NORMAL_TOOTH_ANGLE);
   }
   /* update TBU angle as per calculated */
   CRKHAL_TBU_ANGLE = u32LocalUpdatedAngCal;

   u32LocalUpdatedAngAct =
      CRKHAL_u16TbuConvRelToAbsAng(u32LocalUpdatedAngCal);

   /* Calculate Delta on Angle accordingly */
   if (u32LocalUpdatedAngAct > u32LocalCurrAbsAng_1)
   {
      CRKHAL_u16DeltaAngleOnSynchro = (uint16)(u32LocalUpdatedAngAct - u32LocalCurrAbsAng_1);
   }
   else
   {
      CRKHAL_u16DeltaAngleOnSynchro =
         (uint16)( (u32LocalUpdatedAngAct + CRKHAL_u16EngineCycleAngle) - u32LocalCurrAbsAng_1);
   }
   /* update Angular alarm accordingly */
   if ( ( (uint16)CRKHAL_u16DeltaAngleOnSynchro) != (uint16)UINT16_MIN)
   {
      CRKHAL_vidUpdateAngAlarms( (uint16)CRKHAL_u16DeltaAngleOnSynchro);
   }

   *CRKHAL_pu32McsLtoo1event = 1U;

   CRKHAL_u32Ltoo1TbuValue = CRKHAL_u16GetEngineAngle();
   CRKHAL_vidSTART_ANG_POS_COUNTER(); /* Re-enable Angular Counter */
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidEngRun                                            */
/* !Description : This function configures necessary action for Engine Run    */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidEngRun(void)
{
   *CRKHAL_pu32McsEngineStatus = MCS_RUN;

   /* Enable MTI & TE1 for 1st Sync */
   CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_CHECK_GAP);
   CRKHAL_vidENABLE_INTERRUPT(MTI);
   CRKHAL_vidENABLE_INTERRUPT(TE1);

   CRKHAL_bRunning = (boolean)TRUE;

   /* Enable the Stall Detection Management using the TIM0_CH0_TDU */
   /* (3x33.3ms)/CMU_CLK2 res (500us) */
#if (CRKHAL_coLOW_RPM_DESYNCHRO == CRKHAL_coENABLED)
   if (CRKHAL_bDesynchroThdEnabled != FALSE)
   {
      CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32LongToothMaxDuration);
   }
   else
#endif /* CRKHAL_coLOW_RPM_DESYNCHRO */
   {
      CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32LongToothStalDetThd);
   }
   /* Enable TIMEOUT for ENG_STALL interrupts */
   CRKHAL_vidENABLE_TIMEOUT(ENG_STALL);
   CRKHAL_vidENABLE_INTERRUPT(ENG_STALL);

   /* The synchronisation has to be found before than CDTI Interrupt occurs*/
   CRKHAL_vidSET_NTI(CRKHAL_ku8MaxNbTeethWithoutLtoo);
   CRKHAL_vidENABLE_INTERRUPT(CDTI);

   /* Activate ENG RUN task */
   TSKSRV_vidActivateTask(CRKHAL_ENG_RUN_EVENT);
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidCfgDirDetThreshold                                */
/* !Description : This Function configures the Direction detection threshold  */
/*                 if the Engine speed below configurable
 *                (CRKHAL_ku32BidirSensorValidThd) threshold.
 *                if greater than threshold it will disables the Direction
 *                detection                                                   */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/

void CRKHAL_vidCfgDirDetThreshold(void)
{
   /* Configures the THMI only if MCS set the McsBwdReliable to TRUE under
    * lesser than configurable parameter CRKHAL_ku32BidirSensorValidThd */
   if (  (*CRKHAL_pu32McsDirCfgEn == (boolean)FALSE)
      && (*CRKHAL_pu32McsBwdReliable != (boolean)FALSE)
      && (*CRKHAL_pu32McsPrevToothDur > (uint32)(*CRKHAL_pu32McsRotDirMngMaxDur
                                                 + ( (uint32)CRKHAL_u8BiDir_THMI_THRESHOLD_CORRECTION) ) )
      && (*CRKHAL_pu32McsT_2 > (uint32)(*CRKHAL_pu32McsRotDirMngMaxDur
                                        + ( (uint32)CRKHAL_u8BiDir_THMI_THRESHOLD_CORRECTION) ) ) )
   {
      CRKHAL_vidSET_TRIGGER_HOLD_TIME(CRKHAL_ku16BiDirTrgHoldTimMin);
      CRKHAL_vidENABLE_INTERRUPT(DIR);
      *CRKHAL_pu32McsDirCfgEn = (boolean)TRUE;
      /* CRKHAL_bFastEngSpeedConfirmed = (boolean)FALSE;*/
   }

   /* Configures the THMI to 0 (means no Direction detection required) only if
    * MCS reset the McsBwdReliable to FALSE above the configurable parameter
    * CRKHAL_ku32BidirSensorValidThd */
   if (  (*CRKHAL_pu32McsDirCfgEn != (boolean)FALSE)
      && (*CRKHAL_pu32McsBwdReliable == (boolean)FALSE)
      && (*CRKHAL_pu32McsPrevToothDur < (uint32)(*CRKHAL_pu32McsRotDirMngMaxDur
                                                 - ( (uint32)CRKHAL_u8BiDir_THMI_THRESHOLD_CORRECTION) ) )
      && (*CRKHAL_pu32McsT_2 < (uint32)(*CRKHAL_pu32McsRotDirMngMaxDur
                                        - ( (uint32)CRKHAL_u8BiDir_THMI_THRESHOLD_CORRECTION) ) ) )
   {
      CRKHAL_vidDISABLE_INTERRUPT(DIR);
      CRKHAL_vidSET_TRIGGER_HOLD_TIME(0U);
      *CRKHAL_pu32McsDirCfgEn = (boolean)FALSE;
      /*CRKHAL_bFastEngSpeedConfirmed = (boolean)TRUE;*/
   }
}

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
