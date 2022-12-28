/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_7.c                                              */
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
 * %PID: P2017_BSW:A30390.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CRKHAL.h"
#include "IGNHAL.h"
#include "IGNHAL_Def.h"
#include "IGNHAL_I.h"
#include "IGNHAL_L.h"
#include "MATHSRV.h"

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidCoilCommand / F                                   */
/*                                                                            */
/* !Description : Starts the coil Conduction.                                 */
/******************************************************************************/
void IGNHAL_vidCoilCommand
(
   uint8  u8Coil,
   uint16 Event_bob_offset /* IGNHAL_u16COIL_x_MIN_ADV_ANGLE */
)
{
   uint16  A_dwell;
   uint16  Local_debut; /* Angle_ON_coil_x */
   uint16  Local_fin;   /* Angle_OFF_coil_x */
   uint16  Local_counter;
   uint32  u32Time;
   sint32  Tmp_sint32_1;
   boolean Trig_immediat;


   /* IGNHAL_vidCoilCommand is called from it_dent_ref notification
    * IGNHAL_u16AppliedAdvance = IgnHALAdvanceToApplicate;
    * IGNHAL_vidCurrentMonoCoilManager();
    * IGNHAL_u16AppliedAdvance = IgnHALNextAdvanceToApplicate;
    * IGNHAL_vidNextMonoCoilManager();
    */
   /* Angle_OFF_coil_x = IGNHAL_u16COIL_x_MIN_ADV_ANGLE - IgnHALAdvanceToApplicate */
   Tmp_sint32_1 = ( (sint32)Event_bob_offset) - ( (sint32)IGNHAL_u16AppliedAdvance);
   if (Tmp_sint32_1 < 0)
   {
      Tmp_sint32_1 = (sint32)CRKHAL_u16ENGINE_CYCLE + Tmp_sint32_1;
   }
   Local_fin = (uint16)Tmp_sint32_1;

   Local_counter = IGNHAL_akpfReadStartCounter[u8Coil]();

   Tmp_sint32_1 = ( (sint32)Local_fin) - ( (sint32)Local_counter);
   if (Tmp_sint32_1 < 0)
   {
      Tmp_sint32_1 = (sint32)CRKHAL_u16ENGINE_CYCLE + Tmp_sint32_1;
   }

   if ( ( (uint16)Tmp_sint32_1) <= (2U * IGNHAL_u16TDC_OFFSET) )
   {
      /* Converting DwellTime to Angle_dwell, IGNHAL_u32DwellTime is calculated in IGNHAL_vidCoilDwellTimeCalc function
        given in ignhal_6.c file      */
      /* Dwell time shall be scaled (devided by two) in order to fit the CRKHAL_udtTimeToAngle input parameter
        resolution (200 ns) */
      u32Time = IGNHAL_u32DwellTime[u8Coil] / 2;
      (void)CRKHAL_udtTimeToAngle(u32Time, &A_dwell);

      A_dwell = (uint16)MATHSRV_udtMIN(A_dwell, IGNHAL_u16DWELL_ANGLE_MAX);

      /* Angle_ON_coil_x = Angle_OFF_coil_x - Angle_dwell */
      Tmp_sint32_1 = ( (sint32)Local_fin) - ( (sint32)A_dwell);
      if (Tmp_sint32_1 < 0)
      {
         Tmp_sint32_1 = (sint32)CRKHAL_u16ENGINE_CYCLE + Tmp_sint32_1;
      }
      Local_debut                        = (uint16)Tmp_sint32_1;
      IGNHAL_u8EventStateMachine[u8Coil] = IGNHAL_u8EVENT_T0_T1;

      IGNHAL_au32WdgDelay[u8Coil] = IGNHAL_u32WdgDelayLimitation;
      IGNHAL_au16EndAngle[u8Coil] = Local_fin;

      Trig_immediat = (boolean)FALSE;
      Local_counter = IGNHAL_akpfReadStartCounter[u8Coil]();
      if ( ( (sint32)Local_debut) < ( (sint32)Event_bob_offset) )
      {
         if (  (Local_counter >= Local_debut)
            && (Local_counter < Event_bob_offset) )
         {
            Trig_immediat = (boolean)TRUE;
         }
      }
      else
      {
         if ( ( (sint32)Local_counter) < ( (sint32)Event_bob_offset) )
         {
            Trig_immediat = (boolean)TRUE;
         }
         else
         {
            if ( ( (sint32)Local_counter) >= ( (sint32)Local_debut) )
            {
               Trig_immediat = (boolean)TRUE;
            }
         }
      }
      if (Trig_immediat != (boolean)FALSE)
      {
         Local_debut  = IGNHAL_akpfReadStartCounter[u8Coil]();
         Tmp_sint32_1 = ( (sint32)Local_fin) - ( (sint32)Local_debut);
         if (Tmp_sint32_1 < 0)
         {
            Tmp_sint32_1 = (sint32)CRKHAL_u16ENGINE_CYCLE + Tmp_sint32_1;
         }
         A_dwell = (uint16)Tmp_sint32_1;
      }
      IGNHAL_u16AngleSlope1[u8Coil] =
         (uint16)( (A_dwell * Icd_pos_slope_1) / 256U);
      IGNHAL_u16AngleSlope2[u8Coil] =
         (uint16)( ( (A_dwell * Icd_pos_slope_2) / 256U)
                   - (IGNHAL_u16AngleSlope1[u8Coil]) );

      /* Local_debut added to IGNHAL_u16AngleSlope1 and IGNHAL_u16AngleSlope2
       * to take care of the 40% and 90% of the dwell time.
       */
      IGNHAL_u16AbsAngleSlope1[u8Coil] =
         (IGNHAL_u16AngleSlope1[u8Coil] + Local_debut);

      if (IGNHAL_u16AbsAngleSlope1[u8Coil] >= CRKHAL_u16ENGINE_CYCLE /*CRKHAL_u16EngineCycleAngle*/)
      {
         IGNHAL_u16AbsAngleSlope1[u8Coil] -= CRKHAL_u16ENGINE_CYCLE;  /*CRKHAL_u16EngineCycleAngle;*/
      }
      IGNHAL_u16AbsAngleSlope2[u8Coil] =
         (IGNHAL_u16AngleSlope2[u8Coil] + Local_debut + IGNHAL_u16AngleSlope1[u8Coil]);

      if (IGNHAL_u16AbsAngleSlope2[u8Coil] >= CRKHAL_u16ENGINE_CYCLE /*CRKHAL_u16EngineCycleAngle*/)
      {
         IGNHAL_u16AbsAngleSlope2[u8Coil] -= CRKHAL_u16ENGINE_CYCLE;  /*CRKHAL_u16EngineCycleAngle;*/
      }
      /* Programming conduction of coil x */
      /* IGNHAL_u32WdgDelayLimitation is actually Maximum Time allowed for coil
       * conduction as shown on my temporal graph of Internal Coil Management.
       * That time is used to program watchdog timer while programming conduction
       * of given coil with conduction start and stop angles
       * IGNHAL_u32WdgDelayLimitation is calculated in
       * IGNHAL_vidDwellTimeLimitCalc function given in ignhal_6.c file
       */
      if (Trig_immediat != (boolean)FALSE)
      {
         IGNHAL_akpfCoilImmediateTrig[u8Coil]();
      }
      else
      {
         IGNHAL_akpfCoilConductProg[u8Coil](Local_debut);
      }
   }
}

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
