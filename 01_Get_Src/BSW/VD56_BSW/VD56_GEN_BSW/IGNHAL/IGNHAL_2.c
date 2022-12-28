/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_2.c                                              */
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
 * %PID: P2017_BSW:A30396.A-SRC;6 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "ADCHAL.h"
#include "DGOHAL.h"
#include "IGNHAL.h"
#include "IGNHAL_Def.h"
#include "IGNHAL_gtm_Cfg.h"
#include "IGNHAL_I.h"
#include "IGNHAL_L.h"

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : it_diag_ccbat_bobine_a                                      */
/* !Description : Call back function of Diagnostic Events for Coil A.         */
/*                                                                            */
/******************************************************************************/
void it_diag_ccbat_bobine_a(uint16 IrqNotifVal)
{
   switch (IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A])
   {
      case IGNHAL_u8EVENT_T0_T1:
      case IGNHAL_u8EVENT_T0_T2:
      case IGNHAL_u8EVENT_T0:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vidEVENT_PROCESSING(COIL_A, IrqNotifVal);
               break;

            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         break;

      case IGNHAL_u8EVENT_T1:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vid_EVENT_PROCESSING_T1(COIL_A);
               IGNHAL_vidConfigureT2_a();
               break;

            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         break;

      case IGNHAL_u8EVENT_T2:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vid_EVENT_PROCESSING_T2(COIL_A);
               IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A] = \
                  IGNHAL_u8EVENT_FINISHED;
               IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_A, \
                                         (uint8)IfxGtm_Compare_Unit_1);
               IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_A);
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
/* !FuncName    : it_diag_ccbat_bobine_b                                      */
/* !Description : Call back function of Diagnostic Events for Coil B.         */
/*                                                                            */
/******************************************************************************/
void it_diag_ccbat_bobine_b(uint16 IrqNotifVal)
{
   switch (IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B])
   {
      case IGNHAL_u8EVENT_T0_T1:
      case IGNHAL_u8EVENT_T0_T2:
      case IGNHAL_u8EVENT_T0:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vidEVENT_PROCESSING(COIL_B, IrqNotifVal);
               break;

            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         break;

      case IGNHAL_u8EVENT_T1:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vid_EVENT_PROCESSING_T1(COIL_B);
               IGNHAL_vidConfigureT2_b();
               break;

            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         break;

      case IGNHAL_u8EVENT_T2:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vid_EVENT_PROCESSING_T2(COIL_B);
               IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B] = \
                  IGNHAL_u8EVENT_FINISHED;
               IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_B, \
                                         (uint8)IfxGtm_Compare_Unit_1);
               IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_B);
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
/* !FuncName    : it_diag_ccbat_bobine_c                                      */
/* !Description : Call back function of Diagnostic Events for Coil C.         */
/*                                                                            */
/******************************************************************************/
void it_diag_ccbat_bobine_c(uint16 IrqNotifVal)
{
   switch (IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C])
   {
      case IGNHAL_u8EVENT_T0_T1:
      case IGNHAL_u8EVENT_T0_T2:
      case IGNHAL_u8EVENT_T0:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               SWFAIL_vidSoftwareErrorHook();
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vidEVENT_PROCESSING(COIL_C, IrqNotifVal);
               break;

            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         break;

      case IGNHAL_u8EVENT_T1:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               SWFAIL_vidSoftwareErrorHook();
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vid_EVENT_PROCESSING_T1(COIL_C);
               IGNHAL_vidConfigureT2_c();
               break;

            default:
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         break;

      case IGNHAL_u8EVENT_T2:
         switch (IGNHAL_ku8CoilPhysicMode)
         {
            case IGNHAL_u8JUMOPHYS_MODE:
               SWFAIL_vidSoftwareErrorHook();
               break;

            case IGNHAL_u8MONOPHYS_MODE:
               IGNHAL_vid_EVENT_PROCESSING_T2(COIL_C);
               IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C] = \
                  IGNHAL_u8EVENT_FINISHED;
               IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_C, \
                                         (uint8)IfxGtm_Compare_Unit_1);
               IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_C);
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
/* !FuncName    : diag_ccbat_a                                                */
/* !Description : API runs the SC diagnostics for Coil A.                     */
/*                                                                            */
/******************************************************************************/
void diag_ccbat_a
(
   uint16 Tension_bob_a
)
{
   /* Compare the built up voltage on the coil after a tuned delay time with
    * the calibrated value Seuil_bobine_cc_bat
    */
   if ( ( (sint32)Tension_bob_a) > ( (sint32)Seuil_bobine_cc_bat) )
   {
      /* Short circuit to supply detected
       * Cut off the coil conduction to protect the coil
       * Indicate that slope acquisitions are in-valid
       */
      IGNHAL_vidCOIL_CUT_OFF(COIL_A);

      /* Set diagnostic status to initial value */
      IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A] = IGNHAL_u8EVENT_T0_T1;

      DGOHAL_vidWrite(IGNHAL_udtICD_A_DGO_CH,
                      DGOHAL_bfVALID_SUPPLY,
                      DGOHAL_bfFAULT_SUPPLY);

      IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_A] = 1U;
      IGNHAL_bSlopeAcqValid[IGNHAL_u8COIL_A] = 0U;
      ADCHAL_vidEntry_IGN_EVENT();
      /* Activate the task IGNHAL_DIAG_COIL_X_EVENT on which the coil diagnosis
       * is continued on 1st and 2nd points of diagnosis
       * This task will in turn call function diagnostic_bobine_X as implemented
       * in ignhal_3.c file with macro IGNHAL_vidDIAGNOSIS(COIL_X) defined in
       * IGNHAL_I.H file */
      TSKSRV_vidActivateTask(IGNHAL_DIAG_COIL_A_EVENT);
   }
   else
   {
      /* Measured voltage on a coil is below the threshold
       * Short circuit to supply NOT detected, diagnostic OK
       */
      DGOHAL_vidWrite(IGNHAL_udtICD_A_DGO_CH,
                      DGOHAL_bfVALID_SUPPLY,
                      DGOHAL_bfNO_FAULT_SUPPLY
                     );
      IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_A] = 0U;

      if (IGNHAL_u8EVENT_T0 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A])
      {
         IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_A, (uint8)IfxGtm_Compare_Unit_1);
         IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_A, (uint8)IfxGtm_Compare_Unit_0);
         IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_A);
         IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A] = IGNHAL_u8EVENT_FINISHED;
      }
      /* Configure ATOM channel for current measurement at time T1*/
      else if (IGNHAL_u8EVENT_T0_T1 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A])
      {
         IGNHAL_vidConfigureT1_a();
      }
      else
      {
         if (IGNHAL_u8EVENT_T0_T2 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A])
         {
            IGNHAL_vidConfigureT2_a();
         }
      }
   }
}
/******************************************************************************/
/* !FuncName    : diag_ccbat_b                                                */
/* !Description : API runs the SC diagnostics for Coil B.                     */
/*                                                                            */
/******************************************************************************/
void diag_ccbat_b
(
   uint16 Tension_bob_b
)
{
   if ( ( (sint32)Tension_bob_b) > ( (sint32)Seuil_bobine_cc_bat) )
   {
      IGNHAL_vidCOIL_CUT_OFF(COIL_B);

      IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B] = IGNHAL_u8EVENT_T0_T1;
      DGOHAL_vidWrite(IGNHAL_udtICD_B_DGO_CH,
                      DGOHAL_bfVALID_SUPPLY,
                      DGOHAL_bfFAULT_SUPPLY);

      IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_B] = 1U;
      IGNHAL_bSlopeAcqValid[IGNHAL_u8COIL_B] = 0U;
      ADCHAL_vidEntry_IGN_EVENT();
      TSKSRV_vidActivateTask(IGNHAL_DIAG_COIL_B_EVENT);
   }
   else
   {
      DGOHAL_vidWrite(IGNHAL_udtICD_B_DGO_CH,
                      DGOHAL_bfVALID_SUPPLY,
                      DGOHAL_bfNO_FAULT_SUPPLY
                     );
      IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_B] = 0U;

      if (IGNHAL_u8EVENT_T0 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B])
      {
         IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_B, \
                                   (uint8)IfxGtm_Compare_Unit_1);
         IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_B, \
                                   (uint8)IfxGtm_Compare_Unit_0);
         IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_B);

         IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B] = IGNHAL_u8EVENT_FINISHED;
      }
      /* Configure ATOM channel for current measurement at time T1*/
      else if (IGNHAL_u8EVENT_T0_T1 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B])
      {
         IGNHAL_vidConfigureT1_b();
      }
      else
      {
         if (IGNHAL_u8EVENT_T0_T2 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B])
         {
            IGNHAL_vidConfigureT2_b();
         }
      }
   }
}

/******************************************************************************/
/* !FuncName    : diag_ccbat_c                                                */
/* !Description : API runs the SC diagnostics for Coil C.                     */
/*                                                                            */
/******************************************************************************/
void diag_ccbat_c
(
   uint16 Tension_bob_c
)
{
   if ( ( (sint32)Tension_bob_c) > ( (sint32)Seuil_bobine_cc_bat) )
   {
      IGNHAL_vidCOIL_CUT_OFF(COIL_C);

      IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C] = IGNHAL_u8EVENT_T0_T1;

      DGOHAL_vidWrite(IGNHAL_udtICD_C_DGO_CH,
                      DGOHAL_bfVALID_SUPPLY,
                      DGOHAL_bfFAULT_SUPPLY);

      IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_C] = 1U;
      IGNHAL_bSlopeAcqValid[IGNHAL_u8COIL_C] = 0U;
      ADCHAL_vidEntry_IGN_EVENT();
      TSKSRV_vidActivateTask(IGNHAL_DIAG_COIL_C_EVENT);
   }
   else
   {
      DGOHAL_vidWrite(IGNHAL_udtICD_C_DGO_CH,
                      DGOHAL_bfVALID_SUPPLY,
                      DGOHAL_bfNO_FAULT_SUPPLY
                     );
      IGNHAL_bSCDefaultFlag[IGNHAL_u8COIL_C] = 0U;

      if (IGNHAL_u8EVENT_T0 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C])
      {
         IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_C, (uint8)IfxGtm_Compare_Unit_1);
         IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_C, (uint8)IfxGtm_Compare_Unit_0);
         IGNHAL_vidDisableDiagnostic(IGNHAL_u8COIL_C);

         IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C] = IGNHAL_u8EVENT_FINISHED;
      }
      /* Configure ATOM channel for current measurement at time T1*/
      else if (IGNHAL_u8EVENT_T0_T1 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C])
      {
         IGNHAL_vidConfigureT1_c();
      }
      else
      {
         if (IGNHAL_u8EVENT_T0_T2 == IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C])
         {
            IGNHAL_vidConfigureT2_c();
         }
      }
   }
}

/******************************************************************************/
/* !FuncName    : IGNHAL_vidEventT1_a                                        */
/* !Description : API handles the Event at T1 for Coil A.                    */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidEventT1_a(void)
{
   IGNHAL_u32TimeSlope1[IGNHAL_u8COIL_A] =
      (uint32)( (IfxGtm_u32ReadCapTime(IGNHAL_pstrCOIL_A_DIAG) - IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_A]) & (0x00FFFFFFU) );
   IGNHAL_u16VoltageSlope1[IGNHAL_u8COIL_A] = ADCBSL_u16Read(ANI_COIL_A);
   ADCHAL_vidEntry_IGN_EVENT();
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidEventT1_b                                        */
/* !Description : API handles the Event at T1 for Coil B.                    */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidEventT1_b(void)
{
   IGNHAL_u32TimeSlope1[IGNHAL_u8COIL_B] =
      (uint32)( (IfxGtm_u32ReadCapTime(IGNHAL_pstrCOIL_B_DIAG) - IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_B]) & (0x00FFFFFFU) );
   IGNHAL_u16VoltageSlope1[IGNHAL_u8COIL_B] = ADCBSL_u16Read(ANI_COIL_B);
   ADCHAL_vidEntry_IGN_EVENT();
}

/******************************************************************************/
/* !FuncName    : IGNHAL_vidEventT1_c                                        */
/* !Description : API handles the Event at T1 for Coil B.                    */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidEventT1_c(void)
{
   IGNHAL_u32TimeSlope1[IGNHAL_u8COIL_C] =
      (uint32)( (IfxGtm_u32ReadCapTime(IGNHAL_pstrCOIL_C_DIAG) - IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_C]) & (0x00FFFFFFU) );
   IGNHAL_u16VoltageSlope1[IGNHAL_u8COIL_C] = ADCBSL_u16Read(ANI_COIL_C);
   ADCHAL_vidEntry_IGN_EVENT();
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidEventT2_a                                        */
/* !Description : API handles the Event at T2 for Coil A.                    */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidEventT2_a(void)
{
   IGNHAL_u32TimeSlope2[IGNHAL_u8COIL_A] =
      (uint32)( (IfxGtm_u32ReadCapTime(IGNHAL_pstrCOIL_A_DIAG) - IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_A]) & (0x00FFFFFFU) );
   IGNHAL_u16VoltageSlope2[IGNHAL_u8COIL_A] = ADCBSL_u16Read(ANI_COIL_A);
   IGNHAL_bSlopeAcqValid[IGNHAL_u8COIL_A]   = 1U;
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidEventT2_b                                        */
/* !Description : API handles the Event at T2 for Coil B.                    */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidEventT2_b(void)
{
   IGNHAL_u32TimeSlope2[IGNHAL_u8COIL_B] =
      (uint32)( (IfxGtm_u32ReadCapTime(IGNHAL_pstrCOIL_B_DIAG) - IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_B]) & (0x00FFFFFFU) );
   IGNHAL_u16VoltageSlope2[IGNHAL_u8COIL_B] = ADCBSL_u16Read(ANI_COIL_B);
   IGNHAL_bSlopeAcqValid[IGNHAL_u8COIL_B]   = 1U;
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidEventT2_c                                        */
/* !Description : API handles the Event at T2 for Coil C.                    */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidEventT2_c(void)
{
   IGNHAL_u32TimeSlope2[IGNHAL_u8COIL_C] =
      (uint32)( (IfxGtm_u32ReadCapTime(IGNHAL_pstrCOIL_C_DIAG) - IGNHAL_u32DateOnCoil[IGNHAL_u8COIL_C]) & (0x00FFFFFFU) );
   IGNHAL_u16VoltageSlope2[IGNHAL_u8COIL_C] = ADCBSL_u16Read(ANI_COIL_C);
   IGNHAL_bSlopeAcqValid[IGNHAL_u8COIL_C]   = 1U;
}

/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_a                                    */
/* !Description : API configures the Event at T0 for Coil A.                 */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_a(void)
{
   IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_A_DIAG, \
                                     (uint8)IfxGtm_Compare_Unit_1);

   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_A_DIAG,
                         INACTIVE_CCU1,
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_A],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU0_ONLY_OUT_NO_CHANGE
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_b                                    */
/* !Description : API configures the Event at T0 for Coil B.                 */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_b(void)
{
   IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_B_DIAG, \
                                     (uint8)IfxGtm_Compare_Unit_1);

   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_B_DIAG,
                         INACTIVE_CCU1,
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_B],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU0_ONLY_OUT_NO_CHANGE
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_c                                    */
/* !Description : API configures the Event at T0 for Coil C.                 */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_c(void)
{
   IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_C_DIAG, \
                                     (uint8)IfxGtm_Compare_Unit_1);
   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_C_DIAG,
                         INACTIVE_CCU1,
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_C],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU0_ONLY_OUT_NO_CHANGE
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_T1_a                                 */
/* !Description : API configures the Event at T0 and T1 for Coil A.          */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_T1_a(void)
{
   /* Set the ATOM channel to low and enable the channel */
   IfxGtm_vidAtomEnableChannel(IGNHAL_pstrCOIL_A_DIAG,
                               IGNHAL_pstrAgcCOIL_A_DIAG,
                               IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A_DIAG),
                               IfxGtm_Atom_Level_Low
                              );
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_A_DIAG, \
                             (uint8)IfxGtm_Compare_Unit_0);
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_A_DIAG, \
                             (uint8)IfxGtm_Compare_Unit_1);

   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_A_DIAG,
                         IGNHAL_u16AbsAngleSlope1[IGNHAL_u8COIL_A],
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_A],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_NO_CHANGE
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_T1_b                                 */
/* !Description : API configures the Event at T0 and T1 for Coil B.          */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_T1_b(void)
{

   /* Set the ATOM channel to low and enable the channel */
   IfxGtm_vidAtomEnableChannel(IGNHAL_pstrCOIL_B_DIAG,
                               IGNHAL_pstrAgcCOIL_B_DIAG,
                               IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B_DIAG),
                               IfxGtm_Atom_Level_Low
                              );
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_B_DIAG, \
                             (uint8)IfxGtm_Compare_Unit_0);
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_B_DIAG, \
                             (uint8)IfxGtm_Compare_Unit_1);
   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_B_DIAG,
                         IGNHAL_u16AbsAngleSlope1[IGNHAL_u8COIL_B],
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_B],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_NO_CHANGE
                        );
}

/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_T1_c                                 */
/* !Description : API configures the Event at T0 and T1 for Coil C.          */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_T1_c(void)
{
   /* Set the ATOM channel to low and enable the channel */
   IfxGtm_vidAtomEnableChannel(IGNHAL_pstrCOIL_C_DIAG,
                               IGNHAL_pstrAgcCOIL_C_DIAG,
                               IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C_DIAG),
                               IfxGtm_Atom_Level_Low
                              );
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_C_DIAG, \
                             (uint8)IfxGtm_Compare_Unit_0);
   IfxGtm_vidAtomEnableNotif(IGNHAL_pstrCOIL_C_DIAG, \
                             (uint8)IfxGtm_Compare_Unit_1);

   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_C_DIAG,
                         IGNHAL_u16AbsAngleSlope1[IGNHAL_u8COIL_C],
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_C],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_NO_CHANGE
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_T2_a                                 */
/* !Description : API configures the Event at T0 and T2 for Coil A.          */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_T2_a(void)
{
   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_A_DIAG,
                         IGNHAL_u16AbsAngleSlope2[IGNHAL_u8COIL_A],
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_A],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_NO_CHANGE
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_T2_b                                 */
/* !Description : API configures the Event at T0 and T2 for Coil B.          */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_T2_b(void)
{
   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_B_DIAG,
                         IGNHAL_u16AbsAngleSlope2[IGNHAL_u8COIL_B],
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_B],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_NO_CHANGE
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT0_T2_c                                 */
/* !Description : API configures the Event at T0 and T2 for Coil C.          */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT0_T2_c(void)
{
   /* Serve First and the Output no change compare match */
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_C_DIAG,
                         IGNHAL_u16AbsAngleSlope2[IGNHAL_u8COIL_C],
                         IGNHAL_u32ScDateOnCoil[IGNHAL_u8COIL_C],
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         SERVE_FIRST_OUT_NO_CHANGE
                        );
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT1_a                                    */
/* !Description : API configures the Event at T1  for Coil A.                */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT1_a(void)
{
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_A_DIAG,
                         IGNHAL_u16AbsAngleSlope1[IGNHAL_u8COIL_A],
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_NO_CHANGE
                        );
   IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A] = IGNHAL_u8EVENT_T1;
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT1_b                                    */
/* !Description : API configures the Event at T1  for Coil B.                */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT1_b(void)
{
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_B_DIAG,
                         IGNHAL_u16AbsAngleSlope1[IGNHAL_u8COIL_B],
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_NO_CHANGE
                        );
   IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B] = IGNHAL_u8EVENT_T1;
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT1_c                                    */
/* !Description : API configures the Event at T1  for Coil C.                */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT1_c(void)
{
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_C_DIAG,
                         IGNHAL_u16AbsAngleSlope1[IGNHAL_u8COIL_C],
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_NO_CHANGE
                        );
   IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C] = IGNHAL_u8EVENT_T1;
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT2_a                                    */
/* !Description : API configures the Event at T2  for Coil A.                */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT2_a(void)
{
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_A_DIAG,
                         IGNHAL_u16AbsAngleSlope2[IGNHAL_u8COIL_A],
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_NO_CHANGE
                        );
   IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_A] = IGNHAL_u8EVENT_T2;
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT2_b                                    */
/* !Description : API configures the Event at T2  for Coil B.                */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT2_b(void)
{
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_B_DIAG,
                         IGNHAL_u16AbsAngleSlope2[IGNHAL_u8COIL_B],
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_NO_CHANGE
                        );
   IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_B] = IGNHAL_u8EVENT_T2;
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidConfigureT2_c                                    */
/* !Description : API configures the Event at T2  for Coil C.                */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidConfigureT2_c(void)
{
   IfxGtm_vidAtomSetCond(IGNHAL_pstrCOIL_C_DIAG,
                         IGNHAL_u16AbsAngleSlope2[IGNHAL_u8COIL_C],
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_NO_CHANGE
                        );
   IGNHAL_u8EventStateMachine[IGNHAL_u8COIL_C] = IGNHAL_u8EVENT_T2;
}

/******************************************************************************/
/* !FuncName    : IGNHAL_vidDisableSCWNotif                           */
/* !Description : API disables the notification for diagnostics ATOM.        */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidDisableSCWNotif(uint8 u8Coil,
                               uint8 Ccu_toDisable)
{
   switch (u8Coil)
   {
      case IGNHAL_u8COIL_A:
         IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_A_DIAG, Ccu_toDisable);
         break;

      case IGNHAL_u8COIL_B:
         IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_B_DIAG, Ccu_toDisable);
         break;

      case IGNHAL_u8COIL_C:
         IfxGtm_vidAtomDisableNotification(IGNHAL_pstrCOIL_C_DIAG, Ccu_toDisable);
         break;

      case IGNHAL_u8COIL_D:
         /*IfxGtm_vidAtomDisableNotification( IGNHAL_pstrCOIL_D_DIAG, Ccu_toDisable);*/
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/******************************************************************************/
/* !FuncName    : IGNHAL_vidDisableDiagnostic                                */
/* !Description : API disables the diagnostics ATOM channel.                 */
/*                                                                           */
/******************************************************************************/
void IGNHAL_vidDisableDiagnostic(uint8 u8Coil)
{
   /* Disable the associated ATOM */
   switch (u8Coil)
   {
      case IGNHAL_u8COIL_A:
         IfxGtm_vidAtomDisableChannel
         (
            IGNHAL_pstrCOIL_A_DIAG,
            IGNHAL_pstrAgcCOIL_A_DIAG,
            IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_A_DIAG),
            IfxGtm_Atom_Level_High
         );
         break;

      case IGNHAL_u8COIL_B:
         IfxGtm_vidAtomDisableChannel
         (
            IGNHAL_pstrCOIL_B_DIAG,
            IGNHAL_pstrAgcCOIL_B_DIAG,
            IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_B_DIAG),
            IfxGtm_Atom_Level_High
         );
         break;

      case IGNHAL_u8COIL_C:
         IfxGtm_vidAtomDisableChannel
         (
            IGNHAL_pstrCOIL_C_DIAG,
            IGNHAL_pstrAgcCOIL_C_DIAG,
            IGNHAL_snGET_ATOM_Channel_FROM_CFG(COIL_C_DIAG),
            IfxGtm_Atom_Level_High
         );
         break;

      case IGNHAL_u8COIL_D:
         /*   IfxGtm_vidAtomDisableChannel( IGNHAL_pstrCOIL_D_DIAG ,IGNHAL_pstrAgcCOIL_D_DIAG);*/
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/* !FuncName    : IGNHAL_vidCheckDiagnosticsIntr                             */
/* !Description : API checks whether the interrupt is time /angle based.     */
/*                                                                           */
/******************************************************************************/
uint32 IGNHAL_vidCheckDiagnosticsIntr(uint8 u8Coil)
{
   uint32 Time_Angle;


   Time_Angle = 0u;

   switch (u8Coil)
   {
      case IGNHAL_u8COIL_A:
         Time_Angle = IfxGtm_u32AtomIrqAngTime(IGNHAL_pstrCOIL_A_DIAG);
         break;

      case IGNHAL_u8COIL_B:
         Time_Angle = IfxGtm_u32AtomIrqAngTime(IGNHAL_pstrCOIL_B_DIAG);
         break;

      case IGNHAL_u8COIL_C:
         Time_Angle = IfxGtm_u32AtomIrqAngTime(IGNHAL_pstrCOIL_C_DIAG);
         break;

      /*
         case IGNHAL_u8COIL_D:
         Time_Angle = IfxGtm_u32AtomIrqAngTime(IGNHAL_pstrCOIL_D_DIAG);
         break;
       */

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   if (Time_Angle == IFXGTM_IRQ_UNKNOWN)
   {
      SWFAIL_vidSoftwareErrorHook();
   }
   return(Time_Angle);
}
#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
