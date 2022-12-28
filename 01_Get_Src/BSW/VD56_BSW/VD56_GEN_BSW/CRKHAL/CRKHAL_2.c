/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CRKHAL                                                  */
/* !Description     : CRKHAL Component                                        */
/*                                                                            */
/* !File            : CRKHAL_2.c                                              */
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
 * %PID: P2017_BSW:0A143300.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "std_types.h"
#include "std_limits.h"
#include "TSKSRV.h"
#include "CRKHAL.h"
#include "CRKHAL_I.h"
#include "CRKHAL_co_Cfg.h"
#include "IfxGtm_Ccu.h"
#include "KRN.h"
#include "MATHSRV.h"

/*lint -esym(818,16.7)*/
/* !MComment: Check of defines declaration                                    */
#ifndef CRKHAL_coBIDIR_PULSE_DIAG
   #error The macro-constant CRKHAL_coBIDIR_PULSE_DIAG shall be defined
#endif
#ifndef CRKHAL_coENABLED
   #error The macro-constant CRKHAL_coENABLED shall be defined
#endif

#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

/*********************** Bi-dir Sensor Support ********************************/

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDirectionChangeIsr                                */
/* !Description : Direction Change Interrupt (on DCGI Interrupt)              */
/*                This interrupt is generated when direction is detected by   */
/*                DPLL for example (FWD - BWD) or (BWD - FWD)                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
/*IFX_INTERRUPT(CRKHAL_vidDirectionChangeIsr, 0, DCGI_INT_PRIO)*/
void CRKHAL_vidDirectionChangeIsr(void)
{
   boolean         ubLocalRotaionDir;
   uint32          u32LocalAptVal          = (uint32)CRKHAL_snGET_GTM_DPLL_APT2c;
   uint32          u32LocalPrevToothDur    = *CRKHAL_pu32McsPrevToothDur;
   uint32          u32LocalTwoPrevToothDur = *CRKHAL_pu32McsT_2;
   uint32          u32LocalTeethDurationMin;
   volatile uint32 u32LocalBiDirDelay = (uint32)UINT32_MIN;


   CRKHAL_vidCLEAR_INTERRUPT(DIR);

   /* A small delay is given here for the BWD1 status to be reliably set , as
    * according to the GTM user manual, the BWD1 status is only updated after
    * interrupt is raised.
    */
   for (u32LocalBiDirDelay = 0U; u32LocalBiDirDelay < 2000u; u32LocalBiDirDelay++)
   {
      ;
   }
   /* Gets Direction status for DPLL */
   ubLocalRotaionDir          = (boolean)CRKHAL_snGET_DIRECTION();
   CRKHAL_bDirectionChangeDet = (boolean)TRUE;

   if (CRKHAL_bEnaBwdRotationDetection != (boolean)FALSE)
   {
      /* if detected tooth is in Forward direction */
      if (ubLocalRotaionDir == (boolean)CRKHAL_bFWD_ROTATION)
      {
         /* update APT accordingly */
         /*u32LocalAptVal = (u32LocalAptVal + 1U);*/
         if (u32LocalAptVal > CRKHAL_u16PhyTeethFullScale1Ms)
         {
            u32LocalAptVal -= CRKHAL_u16PhyTeethFullScale;
         }

         CRKHAL_vidSET_GTM_DPLL_APT_APT2b(u32LocalAptVal);

         CRKHAL_bRotationDirection  = CRKHAL_bFWD_ROTATION;
         *CRKHAL_pu32McsBiDirBwdCnt = (uint32)UINT32_MIN;
         /* update TOV for Gap Check */
         CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_CHECK_GAP);

         if (CRKHAL_bBwdRotationPhase != (boolean)FALSE)
         {
            if (CRKHAL_bRunning != (boolean)FALSE)
            {
               CRKHAL_vidENABLE_INTERRUPT(MTI);
               CRKHAL_vidENABLE_INTERRUPT(TE0);
               CRKHAL_vidENABLE_INTERRUPT(TE1);
            }
            CRKHAL_bBwdRotationPhase = (boolean)FALSE;
         }
         CRKHAL_bDirectionChangeDet = (boolean)FALSE;
         /* Activate N_INV_OFF event */
         TSKSRV_vidActivateTask(CRKHAL_N_INV_OFF_EVENT);

         u32LocalTeethDurationMin = MATHSRV_udtMIN(u32LocalTwoPrevToothDur, u32LocalPrevToothDur);

         if (  (u32LocalTeethDurationMin >= *CRKHAL_pu32McsEngineSpeedThd)
            && (*CRKHAL_pu32McsEngineSpeedThd != UINT32_MIN) )
         {
            CRKHAL_bChangeOfDirTaskEvent = (boolean)TRUE;
         }
      }
      else
      {
         /* if detected tooth is back word direction */
         *CRKHAL_pu32McsBiDirFwTotCfg = (uint32)CRKHAL_u8MAX_CNT_TO_FWDDir;
         CRKHAL_bRotationDirection    = CRKHAL_bBWD_ROTATION;
         *CRKHAL_pu32McsBiDirFwdCnt   = (uint32)UINT32_MIN;
         u32LocalTeethDurationMin     = MATHSRV_udtMIN(u32LocalTwoPrevToothDur, u32LocalPrevToothDur);
         if (  (u32LocalTeethDurationMin >= *CRKHAL_pu32McsEngineSpeedThd)
            && (*CRKHAL_pu32McsEngineSpeedThd != UINT32_MIN) )
         {
            CRKHAL_bChangeOfDirTaskEvent = (boolean)TRUE;
         }

         if (CRKHAL_bRestartPhase != (boolean)FALSE)
         {
            CRKHAL_bEnaStopPosAfterCalc = (boolean)FALSE;
         }

         if (CRKHAL_bBwdRotationPhase == (boolean)FALSE)
         {
            CRKHAL_bBwdRotationPhase = (boolean)TRUE;
            /*u32LocalAptVal = (u32LocalAptVal - 1U);*/
            CRKHAL_vidSET_GTM_DPLL_APT_APT2b(u32LocalAptVal);
            /* Activate N_INV event */
            TSKSRV_vidActivateTask(CRKHAL_N_INV_EVENT);
            /* update TOV for No Gap Check */
            CRKHAL_vidSET_TOV_Active_TRIGGER(CRKHAL_TS_T_NO_GAP);
            CRKHAL_vidDISABLE_INTERRUPT(MTI);
            CRKHAL_vidDISABLE_INTERRUPT(TE0);
            CRKHAL_vidDISABLE_INTERRUPT(TE1);

            if (CRKHAL_bSynchronized != (boolean)FALSE)
            {
               if (CRKHAL_bQuickSynchroEnabled == (boolean)FALSE)
               {
                  CRKHAL_bEngPositionKnown        = (boolean)FALSE;
                  CRKHAL_bEnaLtooSearchAftRestart = (boolean)FALSE;
               }
               CRKHAL_u16NumOfSyncLoss++;

               CRKHAL_vidSynchroLost();
               CRKHAL_vidSyncLossEntry();
               /* Activate TOLO event */
               TSKSRV_vidActivateTask(CRKHAL_TOLO_EVENT);
               CRKHAL_bDesynchroForcee = (boolean)FALSE;
               /**CRKHAL_pu32McsTeeAfrLastSyLos  = 1U;*/
               *CRKHAL_pu32McsEngineStatus = MCS_RUN;
               CRKHAL_ubGliLockStatus      = (boolean)FALSE;
               /*CRKHAL_vidDISABLE_INTERRUPT(LLI);*/
            }
            /* configuration for Quick Synchronisation */
            if (  (CRKHAL_bQuickSynchroEnabled != (boolean)FALSE)
               && (CRKHAL_bEngPositionKnown != (boolean)FALSE) )
            {
               CRKHAL_bChangeOfMindEnabled     = (boolean)TRUE;
               *CRKHAL_pu32McsBiDirChgMndEn    = (boolean)TRUE;
               CRKHAL_bEnaLtooSearchAftRestart = (boolean)TRUE;
               /*CRKHAL_bFwdCntCfg = (boolean)FALSE;*/
            }
            CRKHAL_bDirectionChangeDet = (boolean)FALSE;
         }
      }
   }
}

/******************************************************************************/
/* !FuncName    : CRKHAL_vidStopPosCalculation                                */
/* !Description : Calculates Stop Position                                    */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void CRKHAL_vidStopPosCalculation(uint8  *pu8ToothPosition,
                                  uint16 *pu16CountPosition)
{
   uint16 u16LocalEngAnglePosition;
   uint8  u8LocalAptPosition;


   u8LocalAptPosition = *pu8ToothPosition;
   /* update the stop angle
    * check the last tooth is Long tooth ? */

   if (u8LocalAptPosition == 0U)
   {
      u8LocalAptPosition = CRKHAL_u16PhyTeethFullScale;
   }

   u16LocalEngAnglePosition = u8LocalAptPosition * CRKHAL_u16NORMAL_TOOTH_ANGLE;

   if ( (u8LocalAptPosition > CRKHAL_u16PhyTeeth1Minus) ) /* 57 */
   {
      u16LocalEngAnglePosition += (2U * CRKHAL_u16NORMAL_TOOTH_ANGLE);
   }

   if (u8LocalAptPosition == CRKHAL_u16PhyTeethFullScale) /* 116 */
   {
      u16LocalEngAnglePosition += (2U * CRKHAL_u16NORMAL_TOOTH_ANGLE);
   }

   if (  (u8LocalAptPosition == CRKHAL_u16PhyTeeth1Minus)
      || (u8LocalAptPosition == CRKHAL_u16PhyTeethFullScale1Ms) )
   {
      u16LocalEngAnglePosition = (u16LocalEngAnglePosition + 576U); /* 576 = 1.5 times of Long tooth*/
   }
   else
   {
      u16LocalEngAnglePosition = u16LocalEngAnglePosition + (CRKHAL_u16NORMAL_TOOTH_ANGLE / 2U);
   }

   if (u16LocalEngAnglePosition < CRKHAL_u32NumberOfMlt_Tdc)
   {
      u16LocalEngAnglePosition = u16LocalEngAnglePosition + CRKHAL_u32NumberOfMlt_Full;
   }

   u16LocalEngAnglePosition = u16LocalEngAnglePosition - CRKHAL_ku16TDC_1_Angle;

   if (u16LocalEngAnglePosition >= CRKHAL_u32NumberOfMlt_Full)
   {
      u16LocalEngAnglePosition = u16LocalEngAnglePosition - CRKHAL_u32NumberOfMlt_Full;
   }

   *pu16CountPosition = u16LocalEngAnglePosition;
}

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
