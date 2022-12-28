/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_6.c                                              */
/* !Description     :                                                         */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:A30391.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "ADCHAL.h"
#include "CAMHAL.h"
#include "IGNHAL.h"
#include "IGNHAL_Cfg.h"
#include "IGNHAL_Def.h"
#include "IGNHAL_I.h"
#include "MATHSRV.h"
#include "SWFAIL.h"
#include "TDCHAL.h"

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : IGNHAL_vidCoilDwellTimeCalc                                */
/* !Description : Dwell Time Calculations.                                   */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidCoilDwellTimeCalc(uint8 u8Coil)
{
   uint32 u32LocalDwellTime;
   uint32 u32LocalTmp;
   sint32 M2C_sint32_1;


   switch (IgnHALMode)
   {
      case IGN_HAL_MODE_FIXED:
         if ( (IGNHAL_bSCDefaultFlag[u8Coil]) == (boolean)FALSE)
         {
            /* in 100ns */
            u32LocalDwellTime = (uint32)MATHSRV_udtMAX( (sint32)IgnHALFixedDwellTime,
                                                        (sint32)( (IGNHAL_u32DWELL_TIME_MIN
                                                                   / IGNHAL_u16DWELL_TIME_RESOL) ) );
         }
         else
         {
            /* in 100ns */
            u32LocalDwellTime = (uint16)(IGNHAL_u32DWELL_TIME_MIN
                                         / IGNHAL_u16DWELL_TIME_RESOL);
         }
         break;

      case IGN_HAL_MODE_ADAP:
         if ( (IGNHAL_bSCDefaultFlag[u8Coil]) == (boolean)FALSE)
         {
            /* IGNHAL_au8DesiredVoltage is calculated in IGNHAL_vidWriteEnergy Api
             * based on u16DesiredCurrent passed from ASW, shunt resistor value
             * and ignition coil X gain factor Icd_igbt_fdbk_gain_X */
            M2C_sint32_1 = ( (sint32)(IGNHAL_au8DesiredVoltage[u8Coil]) * 8) - (
               IGNHAL_s16AdaptOffset[u8Coil]);
            if (M2C_sint32_1 < 0)
            {
               M2C_sint32_1 = 0;
            }
            u32LocalTmp = (uint16)M2C_sint32_1;
            u32LocalTmp = (32u + (u32LocalTmp
                                    * (IGNHAL_u16AdaptFactor[u8Coil]) ) ) / 64u;

            u32LocalDwellTime = (uint32)MATHSRV_udtMIN(MATHSRV_udtMAX(
                                                          (sint32)u32LocalTmp, (sint32)( (IGNHAL_u32DWELL_TIME_MIN
                                                                                          / IGNHAL_u16DWELL_TIME_RESOL) ) ),
                                                       (sint32)IGNHAL_u32AdaptDwellLimitation);
            /* IGNHAL_u32AdaptDwellLimitation is calculated in IGNHAL_vidDwellTimeLimitCalc
             * function given further below */
         }
         else
         {
            u32LocalDwellTime = (uint32)(IGNHAL_u32DWELL_TIME_MIN
                                         / IGNHAL_u16DWELL_TIME_RESOL);
         }
         break;

      case IGN_HAL_MODE_TEST:
         u32LocalDwellTime = IGNHAL_u32DwellTime[u8Coil];
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         u32LocalDwellTime = (uint32)(IGNHAL_u32DWELL_TIME_MIN
                                      / IGNHAL_u16DWELL_TIME_RESOL);
         break;
   }
   /* IGNHAL_u32WdgDelayLimitation is actually Maximum Time allowed for coil
    * conduction. That time is used to program watchdog timer while
    * programming conduction of given coil with conduction start and stop angles.
    * IGNHAL_vidCoilCommand function calling IGNHAL_akpfCoilConductProg function
    * IGNHAL_u32WdgDelayLimitation is calculated in IGNHAL_vidDwellTimeLimitCalc
    * function given further below
    */
   if ( ( (sint32)u32LocalDwellTime) > ( (sint32)IGNHAL_u32WdgDelayLimitation) )
   {
      IGNHAL_u32DwellTime[u8Coil] = IGNHAL_u32WdgDelayLimitation;
   }
   else
   {
      IGNHAL_u32DwellTime[u8Coil] = u32LocalDwellTime;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidChangeToWantedMode / E                            */
/*                                                                            */
/* !Description : API changes the Mode of IGNHAL                              */
/******************************************************************************/
void IGNHAL_vidChangeToWantedMode(void)
{
   switch (IgnHALWantedMode)
   {
      case IGNHAL_MODE_ADAP_WANTED:
         if (IgnHALMode == IGN_HAL_MODE_TEST)
         {
            IGNHAL_vidCoilsDisable();
         }
         if ( /*((IGNHAL_ku8CoilPhysicMode == IGNHAL_u8JUMOPHYS_MODE) &&
                 (((IGNHAL_bAdaptCalcValid[IGNHAL_u8COIL_A_C]) != (boolean)FALSE) &&
                 ((IGNHAL_bAdaptCalcValid[IGNHAL_u8COIL_B_D]) != (boolean)FALSE)))|| */
            (  (IGNHAL_ku8CoilPhysicMode == IGNHAL_u8MONOPHYS_MODE)
            && (  (  ( (IGNHAL_bAdaptCalcValid[IGNHAL_u8COIL_A]) != (boolean)FALSE)
                  && ( (IGNHAL_bAdaptCalcValid[IGNHAL_u8COIL_B]) != (boolean)FALSE) )
               && ( (IGNHAL_bAdaptCalcValid[IGNHAL_u8COIL_C]) != (boolean)FALSE) ) ) )
         {
            if (IgnHALWriteEnergy_APICalled != (boolean)FALSE)
            {
               IgnHALMode = IGN_HAL_MODE_ADAP;
            }
         }
         break;

      case IGNHAL_MODE_FIXED_WANTED:
         if (IgnHALMode == IGN_HAL_MODE_TEST)
         {
            IGNHAL_vidCoilsDisable();
         }
         IgnHALMode = IGN_HAL_MODE_FIXED;
         break;

      case IGNHAL_MODE_TEST_WANTED:
         if (IgnHALMode != IGN_HAL_MODE_TEST)
         {
            IGNHAL_vidCoilsDisable();
         }
         IgnHALMode = IGN_HAL_MODE_TEST;
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidDwellTimeLimitCalc / C                            */
/*                                                                            */
/* !Description : Dwell Time Limit Calculations.                              */
/******************************************************************************/
void IGNHAL_vidDwellTimeLimitCalc(void)
{
   Std_ReturnType udtLocalRetValue;
   uint32         u32LocalTdcPeriod;
   uint16         u16LocalTmp;
   uint16         u16LocalCalcParaY;
   uint32         M2C_uint32_1;
   uint32         M2C_uint32_2;
   uint16         Value;


   if (IgnHALMode == IGN_HAL_MODE_TEST)
   {
      IGNHAL_u16EngineSpeed = (uint16)UINT16_MIN;
   }
   else
   {
      udtLocalRetValue = TDCHAL_udtReadPeriod(&u32LocalTdcPeriod);
      if (udtLocalRetValue != E_OK)
      {
         udtLocalRetValue = CAMHAL_udtReadToothPeriod(IGNHAL_udtCAMHAL_CH,
                                                      &u32LocalTdcPeriod);
      }
      if (udtLocalRetValue == E_OK)
      {
         M2C_uint32_1 = IGNHAL_u32ENG_SPD_ADAPT_RESOL;
         M2C_uint32_2 = u32LocalTdcPeriod;
         if (M2C_uint32_2 == 0u)
         {
            M2C_uint32_1 = UINT32_MAX;
         }
         else
         {
            M2C_uint32_1 = M2C_uint32_1 / M2C_uint32_2;
         }

         M2C_uint32_2 = M2C_uint32_1;
         if (M2C_uint32_2 > 65535u)
         {
            M2C_uint32_2 = 65535u;
         }

         IGNHAL_u16EngineSpeed = (uint16)M2C_uint32_2;
      }
      else
      {
         IGNHAL_u16EngineSpeed = (uint16)UINT16_MIN;
      }
   }

   (void)ADCHAL_udtPrivateRead(IGNHAL_u8ADCHAL_CH, &IGNHAL_u16IgnVbrf);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(IGNHAL_kau16VbrfBrkptTab,
                                                    IGNHAL_u16IgnVbrf, IGNHAL_u8VBRF_BRKPT_NB);
   u16LocalTmp = MATHSRV_u16CalcParaIncAryU16(IGNHAL_kau16EngSpdBrkptTab,
                                              IGNHAL_u16EngineSpeed, IGNHAL_u8ENG_SPD_BRKPT_NB);

   Value = MATHSRV_u16Interp2d(&(IGNHAL_kau16WdgDelayLimitMap[0][0]), u16LocalTmp, u16LocalCalcParaY,
                               IGNHAL_u8VBRF_BRKPT_NB);

   /* convert from 3.2us to 100 ns */
   IGNHAL_u32WdgDelayLimitation = (uint32)( (uint32)(Value * IGNHAL_INTERP_RESOL_COEF)
                                            / IGNHAL_DESIRED_RESOL_COEF);

   Value = MATHSRV_u16Interp1d(&(IGNHAL_kau16AdaptDwellLimitMap[0]), u16LocalCalcParaY);

   IGNHAL_u32AdaptDwellLimitation = (uint32)( (uint32)(Value * IGNHAL_INTERP_RESOL_COEF)
                                              / IGNHAL_DESIRED_RESOL_COEF);
}

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
