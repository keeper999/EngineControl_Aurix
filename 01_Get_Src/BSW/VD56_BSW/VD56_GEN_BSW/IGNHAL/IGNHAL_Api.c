/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_Api.c                                            */
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
 * %PID: P2017_BSW:A30397.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "IGNHAL_co_Cfg.h"
#include "IGNHAL.h"
#include "IGNHAL_E.h"
#include "IGNHAL_Def.h"
#include "IGNHAL_gtm_Cfg.h"
#include "IGNHAL_I.h"
#include "IGNHAL_L.h"
#include "MATHSRV.h"


#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALInit                                                  */
/*                                                                            */
/* !Description : API to initialise all internal variables of the             */
/*                IGNHAL component.                                           */
/******************************************************************************/
void IgnHALInit(void)
{
   uint8 u8LocalIndex;


   for (u8LocalIndex = (uint8)UINT8_MIN; u8LocalIndex
        < (uint8)IGNHAL_COILS_CHANNEL_NB; u8LocalIndex++)
   {
      /* Diagnotics Status Flag */
      IGNHAL_u8EventStateMachine[u8LocalIndex] = IGNHAL_u8EVENT_T0_T1;
      /* Dwell Time default value */
      IGNHAL_u32DwellTime[u8LocalIndex] = (uint16)(IGNHAL_u32DWELL_TIME_MIN
                                                   / IGNHAL_u16DWELL_TIME_RESOL);
      /* Desired Energy for conduction */
      IGNHAL_au8DesiredVoltage[u8LocalIndex] = (uint8)UINT8_MIN;
      /* Stores current Time  */
      IGNHAL_u32DateOnCoil[u8LocalIndex] = (uint32)UINT32_MIN;
      /* Angle for Time T1 */
      IGNHAL_u16AngleSlope1[u8LocalIndex] = (uint16)UINT16_MIN;
      /* Angle for Time T2 */
      IGNHAL_u16AngleSlope2[u8LocalIndex] = (uint16)UINT16_MIN;
      /* Angle for Time T1 */
      IGNHAL_u16AbsAngleSlope1[u8LocalIndex] = (uint16)UINT16_MIN;
      /* Angle for Time T2 */
      IGNHAL_u16AbsAngleSlope2[u8LocalIndex] = (uint16)UINT16_MIN;

      /* Time at T1 */
      IGNHAL_u32TimeSlope1[u8LocalIndex] = (uint32)UINT32_MIN;
      /* Time at T2 */
      IGNHAL_u32TimeSlope2[u8LocalIndex] = (uint32)UINT32_MIN;
      /* Voltage at T1 */
      IGNHAL_u16VoltageSlope1[u8LocalIndex] = (uint16)UINT16_MIN;
      /* Voltage at T2 */
      IGNHAL_u16VoltageSlope2[u8LocalIndex] = (uint16)UINT16_MIN;
      /* Flag indicating OC */
      IGNHAL_bOCDefaultFlag[u8LocalIndex] = (boolean)FALSE;

      /* Flag indicating SC */
      IGNHAL_bSCDefaultFlag[u8LocalIndex] = (boolean)FALSE;
      /* Flag indicating Diagnostics Request */
      IGNHAL_abDiagRequest[u8LocalIndex] = (boolean)FALSE;
      /* Flag indicating Diagnotics Done*/
      IGNHAL_abDiagDone[u8LocalIndex] = (boolean)FALSE;
      /* Diagnostics Data Valid Flag */
      IGNHAL_bSlopeAcqValid[u8LocalIndex] = (boolean)FALSE;

      IGNHAL_u32ScDateOnCoil[u8LocalIndex] = (uint32)UINT32_MIN;
      IGNHAL_au32WdgDelay[u8LocalIndex]    = (uint32)UINT32_MIN;
      IGNHAL_au16EndAngle[u8LocalIndex]    = (uint16)UINT16_MIN;
   }
   /* Advance Angle to Apply */
   IgnHALAdvanceToApplicate = IGNHAL_u16MIN_ADV_ANGLE;
   /* Next Advance Angle to Apply */
   IgnHALNextAdvanceToApplicate = IgnHALAdvanceToApplicate;
   /* advance angle applied */
   IGNHAL_u16AppliedAdvance = IgnHALAdvanceToApplicate;
   /* Advance Available */
   Avance_disponible = (boolean)FALSE;

   Trait_pmh_avance_glisse = (boolean)FALSE;
   /* Periodic measurement enabled */
   IGNHAL_bPeriodicIgnVbrfEna = (boolean)TRUE;

   IgnHALResetAdapValues();

   /* Coil to ignite */
   IgnHALCoilToCommand = (uint8)UINT8_MIN;

   /* Mode of IGNITION driver */
   IgnHALMode = IGN_HAL_MODE_FIXED;

   /* Dwell Time in 100ns resolution */
   IgnHALFixedDwellTime = (uint16)(IGNHAL_u32DWELL_TIME_MIN
                                   / IGNHAL_u16DWELL_TIME_RESOL);
   /* Flag indicating Write Energy API */
   IgnHALWriteEnergy_APICalled = (boolean)FALSE;
   /* No Ignition Enable yet */
   IGNHAL_bEnabled = (boolean)FALSE;

   IGNHAL_GtmInit();

}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALEnable                                                */
/*                                                                            */
/* !Description : API shall enable the IGNHAL component by activating         */
/*                microcontroller resources. The API shall initialise the     */
/*                first coil ignition.                                        */
/******************************************************************************/
void IgnHALEnable(void)
{
   uint8 u8LocalChannelIndex ;

   if (IgnHALMode != IGN_HAL_MODE_TEST)
   {
      /* disable ATOM channel used to manage conduction of
         coil X. This function will also cut the command
         (stop the conduction)immediately. Output pin state
         will be changed to inactive level - low.

         todo: removed as this is done in the Disable Function
	      Check during testing if this is not creating any glitch or any
	      other issues. especially on CRK-ON / CRK -OFF
	   */
      IGNHAL_vidDisableCmd(IGNHAL_u8COIL_A);
      IGNHAL_vidDisableCmd(IGNHAL_u8COIL_B);
      IGNHAL_vidDisableCmd(IGNHAL_u8COIL_C);
      /* IGNHAL_vidDisableCmd(COIL_D);*/

      /* No alarm needed while initializing */
      CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_COIL_A_CMD);
      CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_COIL_B_CMD);
      CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_COIL_C_CMD);
      /*CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_COIL_D_CMD);*/

      /* Ref Teeth alarm needed when the angle match happens no action */
      CRKHAL_vidActivateAlarmMode(CRKHAL_u8ALARM_IGN_REF_TEETH, MODE_NO_ACTION);

      /* Not Case 1 but normal case */
      Interdit_trig_it_dent_ref = (boolean)FALSE;

      /* Advance available : for first time programming */
      Avance_disponible = (boolean)TRUE;

      /* */
      Trait_pmh_avance_glisse = (boolean)FALSE;

      /* */
      IGNHAL_bPeriodicIgnVbrfEna = (boolean)FALSE;

      /* Initialize the diagnostics variables */
      for (u8LocalChannelIndex = (uint8)UINT8_MIN; u8LocalChannelIndex <
    	   	  (uint8)IGNHAL_COILS_CHANNEL_NB; u8LocalChannelIndex ++)
      {
         IGNHAL_u8EventStateMachine[u8LocalChannelIndex] = IGNHAL_u8EVENT_T0_T1 ;
         IGNHAL_abDiagRequest[u8LocalChannelIndex] = (boolean)FALSE;
         IGNHAL_abDiagDone[u8LocalChannelIndex] = (boolean)FALSE;
      }

      /* All cylinders are cut off initially */
      IGNHAL_bCutCylinderA = (boolean)FALSE;
      IGNHAL_bCutCylinderB = (boolean)FALSE;
      IGNHAL_bCutCylinderC = (boolean)FALSE;
      /* IGNHAL_bCutCylinderD = (boolean)FALSE; */

      /* Enable the ATOM channel mapped to REF TEETH */
      IGNHAL_GtmEnable();

      /* initialize the first coil conduction */
      it_dent_ref();

      /* Enable the alarm function for Ref Teeth */
      CRKHAL_vidEnableAlarmNotif(CRKHAL_u8ALARM_IGN_REF_TEETH);

      /* Ignition Enabled */
      IGNHAL_bEnabled = (boolean)TRUE;
   }
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALDisable                                               */
/*                                                                            */
/* !Description : API shall disable the IGNHAL component by activating        */
/*                microcontroller resources. The API shall initialize the     */
/*                first coil ignition.                                        */
/******************************************************************************/
void IgnHALDisable(void)
{
   if (IgnHALMode != IGN_HAL_MODE_TEST)
   {
      IGNHAL_vidCoilsDisable();
      IGNHAL_bEnabled = (boolean)FALSE;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALWriteAngle                                            */
/*                                                                            */
/* !Description : API IgnHALWriteAngle shall program an <<u16Advance>>        */
/*                ignition advance angle on the <<u8Channel>> cylinder        */
/******************************************************************************/
void IgnHALWriteAngle(uint8  u8Channel,
                      uint16 u16Advance)
{

   IGNHAL_vidRefreshCoilToCommand();
   switch (u8Channel)
   {
      case IGN_HAL_CYLINDER_A:
         if (IgnHALCoilToCommand == IGNHAL_u8COIL_A)
         {
            IgnHALAdvanceToApplicate = u16Advance;
         }
         else
         {
            if (IgnHALCoilToCommand == IGNHAL_u8COIL_C)
            {
               Interdit_trig_it_dent_ref    = (boolean)TRUE;
               IgnHALNextAdvanceToApplicate = u16Advance;
            }
         }
         break;

      case IGN_HAL_CYLINDER_B:
         if (IgnHALCoilToCommand == IGNHAL_u8COIL_B)
         {
            IgnHALAdvanceToApplicate = u16Advance;
         }
         else
         {
            if (IgnHALCoilToCommand == IGNHAL_u8COIL_A)
            {
               Interdit_trig_it_dent_ref    = (boolean)TRUE;
               IgnHALNextAdvanceToApplicate = u16Advance;
            }
         }
         break;

      case IGN_HAL_CYLINDER_C:
         if (IgnHALCoilToCommand == IGNHAL_u8COIL_C)
         {
            IgnHALAdvanceToApplicate = u16Advance;
         }
         else
         {
            if (IgnHALCoilToCommand == IGNHAL_u8COIL_B)
            {
               Interdit_trig_it_dent_ref    = (boolean)TRUE;
               IgnHALNextAdvanceToApplicate = u16Advance;
            }
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidWriteEnergy                                       */
/*                                                                            */
/* !Description : while the IGNHAL component is in fixed mode, the energy     */
/*                parameter given by IGNHAL_vidWriteEnergy shall have no      */
/*                effect IGNHAL_vidWriteEnergy shall apply a given electrical */
/*                current <<u16DesiredCurrent>>) for coils conduction.        */
/******************************************************************************/
void IGNHAL_vidWriteEnergy(uint16 u16DesiredCurrent)
{
   uint32 u32LocalTheorDesiredVoltage;
   uint16 u16LocalDesiredCurrent;
   uint32 M2C_uint32_1;


   u16LocalDesiredCurrent = (uint16)MATHSRV_udtMIN( (sint32)u16DesiredCurrent,
                                                    (sint32)IGNHAL_u16MAX_CURRENT);
   u32LocalTheorDesiredVoltage = (8u + ( ( (uint32)u16LocalDesiredCurrent) * ( (
                                                                                  uint32)IGNHAL_ku16ShuntResistor) ) )
                                 >> 4U;
   switch (IGNHAL_ku8CoilPhysicMode)
   {
      case IGNHAL_u8JUMOPHYS_MODE:
         /*
               M2C_uint32_1 = (2097152u + (u32LocalTheorDesiredVoltage * (((sint16)
            Icd_igbt_fdbk_gain_a_c) + 1024u))) >> 22U;
               if (M2C_uint32_1 > 255u)
               {
                  M2C_uint32_1 = 255u;
               }
               IGNHAL_au8DesiredVoltage[IGNHAL_u8COIL_A_C] = (uint8)M2C_uint32_1;
               M2C_uint32_1 = (2097152u + (u32LocalTheorDesiredVoltage * (((sint16)
            Icd_igbt_fdbk_gain_b_d) + 1024))) >> 22U;
               if (M2C_uint32_1 > 255u)
               {
                  M2C_uint32_1 = 255u;
               }
               IGNHAL_au8DesiredVoltage[IGNHAL_u8COIL_B_D] = (uint8)M2C_uint32_1;
               IgnHALWriteEnergy_APICalled = (boolean)TRUE;
          */
         break;

      case IGNHAL_u8MONOPHYS_MODE:
         M2C_uint32_1 = (2097152u + (u32LocalTheorDesiredVoltage * ( ( (sint16)
                                                                       Icd_igbt_fdbk_gain_a) + 1024u) ) ) >> 22U;
         if (M2C_uint32_1 > 255u)
         {
            M2C_uint32_1 = 255u;
         }
         IGNHAL_au8DesiredVoltage[IGNHAL_u8COIL_A] = (uint8)M2C_uint32_1;
         M2C_uint32_1                              = (2097152u + (u32LocalTheorDesiredVoltage * ( ( (sint16)
                                                                                                    Icd_igbt_fdbk_gain_b)
                                                                                                  + 1024u) ) ) >> 22U;
         if (M2C_uint32_1 > 255u)
         {
            M2C_uint32_1 = 255u;
         }
         IGNHAL_au8DesiredVoltage[IGNHAL_u8COIL_B] = (uint8)M2C_uint32_1;
         M2C_uint32_1                              = (2097152u + (uint32)(u32LocalTheorDesiredVoltage * ( ( (sint16)
                                                                                                            Icd_igbt_fdbk_gain_c)
                                                                                                          + 1024u) ) )
                                                     >> 22U;
         if (M2C_uint32_1 > 255u)
         {
            M2C_uint32_1 = 255u;
         }
         IGNHAL_au8DesiredVoltage[IGNHAL_u8COIL_C] = (uint8)M2C_uint32_1;
         IgnHALWriteEnergy_APICalled               = (boolean)TRUE;
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALWriteDwellTime                                        */
/*                                                                            */
/* !Description : The API shall apply a <<u16DwellTime>> coil conduction time */
/*                in FIXED mode. When the IGNHAL driver is in adaptation mode,*/
/*                the IgnHALWriteDwellTime calling shall have no effect on    */
/*                coil conduction times applied.                              */
/******************************************************************************/
void IgnHALWriteDwellTime(uint16 u16DwellTime)
{

   IgnHALFixedDwellTime = (uint32)( ( (uint32)u16DwellTime
                                      * IGNHAL_INTERP_RESOL_COEF) / IGNHAL_DESIRED_RESOL_COEF);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALReadDwellTime                                         */
/*                                                                            */
/* !Description : The API shall return the dwell time applied for the         */
/*                <<u8Channel>> coil                                          */
/******************************************************************************/
uint16 IgnHALReadDwellTime(uint8 u8Channel)
{
   uint16 Tmp_uw = 0U;


   switch (IGNHAL_ku8CoilPhysicMode)
   {
      case IGNHAL_u8JUMOPHYS_MODE:
         /*
            switch(u8Channel)
            {
            case IGN_HAL_CYLINDER_A:
            case IGN_HAL_CYLINDER_C:
            Tmp_uw = IGNHAL_u32DwellTime[IGNHAL_u8COIL_A_C];
            break;
            case IGN_HAL_CYLINDER_B:
            case IGN_HAL_CYLINDER_D:
            Tmp_uw = IGNHAL_u32DwellTime[IGNHAL_u8COIL_B_D];
            break;
            default:
            Tmp_uw = (uint16)UINT16_MIN;
            SWFAIL_vidSoftwareErrorHook();
            break;
            }*/
         break;

      case IGNHAL_u8MONOPHYS_MODE:
         switch (u8Channel)
         {
            case IGN_HAL_CYLINDER_A:
               Tmp_uw = IGNHAL_u32DwellTime[IGNHAL_u8COIL_A];
               break;

            case IGN_HAL_CYLINDER_B:
               Tmp_uw = IGNHAL_u32DwellTime[IGNHAL_u8COIL_B];
               break;

            case IGN_HAL_CYLINDER_C:
               Tmp_uw = IGNHAL_u32DwellTime[IGNHAL_u8COIL_C];
               break;

            default:
               Tmp_uw = (uint16)UINT16_MIN;
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         break;

      default:
         Tmp_uw = (uint16)UINT16_MIN;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   Tmp_uw = (Tmp_uw * IGNHAL_DESIRED_RESOL_COEF) / IGNHAL_INTERP_RESOL_COEF;
   return(Tmp_uw);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALWriteMode                                             */
/*                                                                            */
/* !Description : The API If the adaptation parameters have been calculated   */
/*                and the energy parameters have been given and <<enuMode>>   */
/*                is IGN_HAL_MODE_ADAP, then IgnHALWriteMode shall enter the  */
/*                ICD in adaptation mode.                                     */
/*                If the fixed dwell time has been given and <<enuMode>> is   */
/*                IGN_HAL_MODE_FIXED, then IgnHALWriteMode shall enter the    */
/*                ICD in fixed mode.                                          */
/*                When <<enuMode>> is IGN_HAL_MODE_TEST, IgnHALWriteMode shall*/
/*               enter immediately the ICD in test mode.                      */
/******************************************************************************/
uint8 IgnHALWriteMode(uint8 u8Mode)
{
   uint8 u8LocalMode;


   switch (u8Mode)
   {
      case IGN_HAL_MODE_ADAP:
         IgnHALWantedMode = IGNHAL_MODE_ADAP_WANTED;
         IGNHAL_vidChangeToWantedMode();
         break;

      case IGN_HAL_MODE_FIXED:
         IgnHALWantedMode = IGNHAL_MODE_FIXED_WANTED;
         IGNHAL_vidChangeToWantedMode();
         break;

      case IGN_HAL_MODE_TEST:
         IgnHALWantedMode = IGNHAL_MODE_TEST_WANTED;
         IGNHAL_vidChangeToWantedMode();
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   u8LocalMode = (uint8)IgnHALMode;
   return(u8LocalMode);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidCoilsDisable                                      */
/*                                                                            */
/* !Description : The API The shall disable the coils and reset all its       */
/*                ATOM channels and initialize its internal variables.        */
/******************************************************************************/
void IGNHAL_vidCoilsDisable(void)
{
   uint8 u8LocalIndex;


   CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_IGN_REF_TEETH);

   /* cut the coils and Disable the SC Diagnostics Notifications*/
   IGNHAL_vidCOIL_CUT_OFF(COIL_A);
   IGNHAL_vidCOIL_CUT_OFF(COIL_B);
   IGNHAL_vidCOIL_CUT_OFF(COIL_C);
   /* IGNHAL_vidCOIL_CUT_OFF(COIL_D);*/

   /* Disable the SC Diagnostics Notifications */
   /*
    * In IFX AURIX IGNHAL implementation new function will be
    * implemented to disable notification on ATOM[i]_CH[y] compare unit CCU0,
    * programmed with tuned delay normally set to 500 µs, and used to trigger
    * conduction coil X short circuit to
    * battery diagnostic, as described in 5.1.2
    */
   IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_A, (uint8)IfxGtm_Compare_Unit_0);
   IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_A, (uint8)IfxGtm_Compare_Unit_1);
   IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_B, (uint8)IfxGtm_Compare_Unit_0);
   IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_B, (uint8)IfxGtm_Compare_Unit_1);
   IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_C, (uint8)IfxGtm_Compare_Unit_0);
   IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_C, (uint8)IfxGtm_Compare_Unit_1);

   /*
    * In IFX AURIX IGNHAL implementation new function/macro will be implemented
    * to disable ATOM channel used to manage coil X diagnostics */
   IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_A);
   IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_B);
   IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_C);

   /* Reset flags for all coil channels to initial values */
   for (u8LocalIndex = (uint8)UINT8_MIN; u8LocalIndex
        < (uint8)IGNHAL_COILS_CHANNEL_NB; u8LocalIndex++)
   {
      IGNHAL_bOCDefaultFlag[u8LocalIndex]      = (boolean)FALSE;
      IGNHAL_bSCDefaultFlag[u8LocalIndex]      = (boolean)FALSE;
      IGNHAL_u8EventStateMachine[u8LocalIndex] = IGNHAL_u8EVENT_T0_T1;
      IGNHAL_abDiagRequest[u8LocalIndex]       = (boolean)FALSE;
      IGNHAL_abDiagDone[u8LocalIndex]          = (boolean)FALSE;
   }

   /* Enable periodic Battery Voltage monitoring */
   IGNHAL_bPeriodicIgnVbrfEna = (boolean)TRUE;

   /*todo: check dwell_tact :: what is needed */
   /*
    * In IFX AURIX IGNHAL implementation this functionality will be implemented
    * reusing resources of the normal mode.
    * Depending on a project dynamics implementation of this functionality
    * might be left for the final step release planned for 05. 2014.
    */
   /* CRKHAL_vidDisableAlarmNotif(CAPCOM_TEMPS_DWELL_TACT);
      TmrBSLDisableNotification(CAPCOM_TEMPS_DWELL_TACT);
      TmrBSLWrite(CAPCOM_TEMPS_DWELL_TACT, (uint32)UINT32_MIN);
    */

   /* Disable ATOM associated with REF TOOTH */
   IGNHAL_GtmDisable();
}
/**/
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALWriteTestTime                                         */
/*                                                                            */
/* !Description : The API shall start the coil conduction immediately in      */
/*                test mode.                                                  */
/******************************************************************************/
void IgnHALWriteTestTime(uint8  u8Channel,
                         uint32 u32TestTime)
{
   #if IGN_TEST_MODE_SUPPORTED
   uint32 u32LocalTestTime;
   uint32 u32LocalReadTimer;

   if (IgnHALMode == IGN_HAL_MODE_TEST)
   {
      IGNHAL_vidDwellTimeLimitCalc();
      u32LocalTestTime = MATHSRV_udtMIN(MATHSRV_udtMAX(u32TestTime,
                                                       (uint32)( (uint16)(IGNHAL_u32DWELL_TIME_MIN
                                                                          / IGNHAL_u16DWELL_TIME_RESOL) ) ),
                                        (uint32)IGNHAL_u32WdgDelayLimitation);
      switch (IGNHAL_ku8CoilPhysicMode)
      {
         case IGNHAL_u8JUMOPHYS_MODE:
            switch (u8Channel)
            {
               case IGN_HAL_CYLINDER_A:
               case IGN_HAL_CYLINDER_C:
                  u32LocalReadTimer = TmrBSLRead(COIL_A_C_CONDUCT_DELAY_WTDG);
                  if (u32LocalReadTimer == 0)
                  {
                     IGNHAL_vidComputeDiagPointTime(u32LocalTestTime);
                     IGNHAL_vidCOIL_TIMER_CONTROL(BOTH, DISABLE, COIL_A_C);
                     lance_it_diag_tact(IGNHAL_u32DiagPointOffset);
                     TmrBSLEnableNotification(COIL_A_C_CONDUCT_DELAY_WTDG);
                     TmrBSLWrite(COIL_A_C_CONDUCT_DELAY_WTDG, u32LocalTestTime);
                     TmrBSLStart(COIL_A_C_CONDUCT_DELAY_WTDG);
                     if ( (IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_A_C]) == (boolean)FALSE)
                     {
                        IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A_C] =
                           IGNHAL_u8PROG_1ER_POINT;
                     }
                     IGNHAL_vidLAUNCH_SC_DIAG_IT(COIL_A_C, (uint16)(
                                                    IGNHAL_ku32SCToSupplyDiagDelay / IGNHAL_u16SCDIAG_TIMER_RESOL) );
                  }
                  break;

               case IGN_HAL_CYLINDER_B:
               case IGN_HAL_CYLINDER_D:
                  u32LocalReadTimer = TmrBSLRead(COIL_B_D_CONDUCT_DELAY_WTDG);
                  if (u32LocalReadTimer == 0)
                  {
                     IGNHAL_vidComputeDiagPointTime(u32LocalTestTime);
                     IGNHAL_vidCOIL_TIMER_CONTROL(BOTH, DISABLE, COIL_B_D);
                     lance_it_diag_tact(IGNHAL_u32DiagPointOffset);
                     TmrBSLEnableNotification(COIL_B_D_CONDUCT_DELAY_WTDG);
                     TmrBSLWrite(COIL_B_D_CONDUCT_DELAY_WTDG, u32LocalTestTime);
                     TmrBSLStart(COIL_B_D_CONDUCT_DELAY_WTDG);
                     if ( (IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_B_D]) == (boolean)FALSE)
                     {
                        IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B_D] =
                           IGNHAL_u8PROG_1ER_POINT;
                     }
                     IGNHAL_vidLAUNCH_SC_DIAG_IT(COIL_B_D, (uint16)(
                                                    IGNHAL_ku32SCToSupplyDiagDelay / IGNHAL_u16SCDIAG_TIMER_RESOL) );
                  }
                  break;

               default:
                  SWFAIL_vidSoftwareErrorHook();
                  break;
            }
            break;

         case IGNHAL_u8MONOPHYS_MODE:
            switch (u8Channel)
            {
               case IGN_HAL_CYLINDER_A:
                  u32LocalReadTimer = TmrBSLRead(COIL_A_CONDUCT_DELAY_WTDG);
                  if (u32LocalReadTimer == 0)
                  {
                     IGNHAL_vidCOIL_TIMER_CONTROL(BOTH, DISABLE, COIL_A);
                     /* !Comment: check if specific external power coils code is present           */
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                     if (IGNHAL_kbEnableExtPowerCoils == (boolean)TRUE)
                     {
                        u32LocalReadTimer = IGNHAL_ku32DiagPointDelay1;
                     }
                     else
                     {
                     #endif /* if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED) */
                     IGNHAL_vidComputeDiagPointTime(u32LocalTestTime);
                     lance_it_diag_tact(IGNHAL_u32DiagPointOffset);
                     u32LocalReadTimer = IGNHAL_ku32SCToSupplyDiagDelay;
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                  }
                     #endif
                     TmrBSLEnableNotification(COIL_A_CONDUCT_DELAY_WTDG);
                     TmrBSLWrite(COIL_A_CONDUCT_DELAY_WTDG, u32LocalTestTime);
                     TmrBSLStart(COIL_A_CONDUCT_DELAY_WTDG);
                     IGNHAL_vidLAUNCH_SC_DIAG_IT(COIL_A, (uint16)(u32LocalReadTimer
                                                                  / IGNHAL_u16SCDIAG_TIMER_RESOL) );
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                     if (IGNHAL_kbEnableExtPowerCoils == (boolean)TRUE)
                     {
                        IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A] = IGNHAL_u8PROG_1ER_POINT
                        ;
                        IGNHAL_abDiagDone[IGNHAL_u8COIL_A]    = (boolean)FALSE;
                        IGNHAL_abDiagRequest[IGNHAL_u8COIL_A] = (boolean)FALSE;
                     }
                     else
                     {
                     #endif /* if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED) */
                     if ( (IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_A]) == (boolean)FALSE)
                     {
                        IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A] =
                           IGNHAL_u8PROG_1ER_POINT;
                     }
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                  }
                     #endif
                  }
                  break;

               case IGN_HAL_CYLINDER_B:
                  u32LocalReadTimer = TmrBSLRead(COIL_B_CONDUCT_DELAY_WTDG);
                  if (u32LocalReadTimer == 0)
                  {
                     IGNHAL_vidCOIL_TIMER_CONTROL(BOTH, DISABLE, COIL_B);
                     /* !Comment: check if specific external power coils code is present   */
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                     if (IGNHAL_kbEnableExtPowerCoils == (boolean)TRUE)
                     {
                        u32LocalReadTimer = IGNHAL_ku32DiagPointDelay1;
                     }
                     else
                     {
                     #endif /* if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED) */
                     IGNHAL_vidComputeDiagPointTime(u32LocalTestTime);
                     lance_it_diag_tact(IGNHAL_u32DiagPointOffset);
                     u32LocalReadTimer = IGNHAL_ku32SCToSupplyDiagDelay;
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                  }
                     #endif
                     TmrBSLEnableNotification(COIL_B_CONDUCT_DELAY_WTDG);
                     TmrBSLWrite(COIL_B_CONDUCT_DELAY_WTDG, u32LocalTestTime);
                     TmrBSLStart(COIL_B_CONDUCT_DELAY_WTDG);
                     IGNHAL_vidLAUNCH_SC_DIAG_IT(COIL_B, (uint16)(u32LocalReadTimer
                                                                  / IGNHAL_u16SCDIAG_TIMER_RESOL) );
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                     if (IGNHAL_kbEnableExtPowerCoils == (boolean)TRUE)
                     {
                        IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B] = IGNHAL_u8PROG_1ER_POINT
                        ;
                        IGNHAL_abDiagDone[IGNHAL_u8COIL_B]    = (boolean)FALSE;
                        IGNHAL_abDiagRequest[IGNHAL_u8COIL_B] = (boolean)FALSE;
                     }
                     else
                     {
                     #endif /* if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED) */
                     if ( (IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_B]) == (boolean)FALSE)
                     {
                        IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B] =
                           IGNHAL_u8PROG_1ER_POINT;
                     }
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                  }
                     #endif
                  }
                  break;

               case IGN_HAL_CYLINDER_C:
                  u32LocalReadTimer = TmrBSLRead(COIL_C_CONDUCT_DELAY_WTDG);
                  if (u32LocalReadTimer == 0)
                  {
                     IGNHAL_vidCOIL_TIMER_CONTROL(BOTH, DISABLE, COIL_C);
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                     if (IGNHAL_kbEnableExtPowerCoils == (boolean)TRUE)
                     {
                        u32LocalReadTimer = IGNHAL_ku32DiagPointDelay1;
                     }
                     else
                     {
                     #endif /* if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED) */
                     IGNHAL_vidComputeDiagPointTime(u32LocalTestTime);
                     lance_it_diag_tact(IGNHAL_u32DiagPointOffset);
                     u32LocalReadTimer = IGNHAL_ku32SCToSupplyDiagDelay;
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                  }
                     #endif
                     TmrBSLEnableNotification(COIL_C_CONDUCT_DELAY_WTDG);
                     TmrBSLWrite(COIL_C_CONDUCT_DELAY_WTDG, u32LocalTestTime);
                     TmrBSLStart(COIL_C_CONDUCT_DELAY_WTDG);
                     IGNHAL_vidLAUNCH_SC_DIAG_IT(COIL_C, (uint16)(u32LocalReadTimer
                                                                  / IGNHAL_u16SCDIAG_TIMER_RESOL) );
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                     if (IGNHAL_kbEnableExtPowerCoils == (boolean)TRUE)
                     {
                        IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C] = IGNHAL_u8PROG_1ER_POINT
                        ;
                        IGNHAL_abDiagDone[IGNHAL_u8COIL_C]    = (boolean)FALSE;
                        IGNHAL_abDiagRequest[IGNHAL_u8COIL_C] = (boolean)FALSE;
                     }
                     else
                     {
                     #endif /* if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED) */
                     if ( (IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_C]) == (boolean)FALSE)
                     {
                        IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C] =
                           IGNHAL_u8PROG_1ER_POINT;
                     }
                     #if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)
                  }
                     #endif
                  }
                  break;

               default:
                  SWFAIL_vidSoftwareErrorHook();
                  break;
            }
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
   #else /* if IGN_TEST_MODE_SUPPORTED */

    COMPILER_UNUSED_PARAMETER(u8Channel);
    COMPILER_UNUSED_PARAMETER(u32TestTime);

   #endif /* if IGN_TEST_MODE_SUPPORTED */
   /* #if IGN_TEST_MODE_SUPPORTED */
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALGetAdapValues                                         */
/*                                                                            */
/* !Description : The API shall return the adaptation values (<<pu16Factor>>  */
/*                factor and <<pu16Offset>> offset) used by the ICD in        */
/*                adaptation mode for the <<u8Channel>> coil                  */
/******************************************************************************/
void IgnHALGetAdapValues(uint8   u8Channel,
                         uint16 *pu16Factor,
                         uint16 *pu16Offset)
{
   switch (IGNHAL_ku8CoilPhysicMode)
   {
      case IGNHAL_u8JUMOPHYS_MODE:
         /*
            switch(u8Channel)
            {
            case IGN_HAL_CYLINDER_A:
            case IGN_HAL_CYLINDER_C:
            *pu16Factor = IGNHAL_u16AdaptFactor[IGNHAL_u8COIL_A_C];
            *pu16Offset = (uint16)((((uint16)
                IGNHAL_s16AdaptOffset[IGNHAL_u8COIL_A_C]) / 8U)
          + 32768u);
            break;
            case IGN_HAL_CYLINDER_B:
            case IGN_HAL_CYLINDER_D:
          ++*pu16Factor = IGNHAL_u16AdaptFactor[IGNHAL_u8COIL_B_D];
          ++*pu16Offset = (uint16)((((uint16)
                IGNHAL_s16AdaptOffset[IGNHAL_u8COIL_B_D]) / 8U)
          + 32768u);
            break;
            default:
            SWFAIL_vidSoftwareErrorHook();
            break;
            }
          */
         break;

      case IGNHAL_u8MONOPHYS_MODE:
         switch (u8Channel)
         {
            case IGN_HAL_CYLINDER_A:
               *pu16Factor = IGNHAL_u16AdaptFactor[IGNHAL_u8COIL_A];
               *pu16Offset = (uint16)( ( ( (uint16)
                                           IGNHAL_s16AdaptOffset[IGNHAL_u8COIL_A]) / 8U)
                                       + 32768u);
               break;

            case IGN_HAL_CYLINDER_B:
               *pu16Factor = IGNHAL_u16AdaptFactor[IGNHAL_u8COIL_B];
               *pu16Offset = (uint16)( ( ( (uint16)
                                           IGNHAL_s16AdaptOffset[IGNHAL_u8COIL_B]) / 8U)
                                       + 32768u);
               break;

            case IGN_HAL_CYLINDER_C:
               *pu16Factor = IGNHAL_u16AdaptFactor[IGNHAL_u8COIL_C];
               *pu16Offset = (uint16)( ( ( (uint16)
                                           IGNHAL_s16AdaptOffset[IGNHAL_u8COIL_C]) / 8U)
                                       + 32768u);
               break;

            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IgnHALResetAdapValues                                       */
/*                                                                            */
/* !Description : The API shall reset the adaptation values to default value. */
/******************************************************************************/
void IgnHALResetAdapValues(void)
{
   uint8 u8LocalIndex;


   for (u8LocalIndex = (uint8)UINT8_MIN; u8LocalIndex
        < (uint8)IGNHAL_COILS_CHANNEL_NB; u8LocalIndex++)
   {
      IGNHAL_bAdaptCalcValid[u8LocalIndex] = (boolean)FALSE;
      IGNHAL_u16AdaptFactor[u8LocalIndex]  = IGNHAL_ku16AdaptFactorDef;
      IGNHAL_s16AdaptOffset[u8LocalIndex]  = IGNHAL_ks16AdaptOffsetDef;
   }
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IGNHAL_vidInhibCoil                                         */
/*                                                                            */
/* !Description : The API shall request a cut of the coil.                    */
/******************************************************************************/
void IGNHAL_vidInhibCoil(uint8 u8Channel)
{

   switch (u8Channel)
   {
      case IGN_HAL_CYLINDER_A:
         IGNHAL_bCutCylinderA = (boolean)TRUE;
         break;

      case IGN_HAL_CYLINDER_B:
         IGNHAL_bCutCylinderB = (boolean)TRUE;
         break;

      case IGN_HAL_CYLINDER_C:
         IGNHAL_bCutCylinderC = (boolean)TRUE;
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"
/*------------------------------- end of file --------------------------------*/
