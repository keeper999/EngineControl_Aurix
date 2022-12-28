/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software Component                              */
/*                                                                            */
/* !File            : AFAMgtT_F04_check_petrol_mode_stability.c               */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AFAMgtT_F04_check_petrol_mode_stability.mdl           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Jul 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT_F04_check_petrol_mode_stability.h"
#include "AFAMgtT_F04_check_petrol_mode_stability_private.h"
#include "AFAMgtT.h"
/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

/* Output and update for referenced model: 'AFAMgtT_F04_check_petrol_mode_stability' */
void mr_AFAMgtT_F04_check_petrol_mod(const Boolean *rtu_InjSys_bAcvFuCll,
  const Boolean *rtu_AFAMgt_bEveRstStab2, const Boolean *rtu_AFAMgt_bInhAF2,
  const UInt32 *rtu_AFAMgt_tiCntStabFuModPrev, Boolean
  *rty_AFAMgt_bIdcStabFuMod, Boolean *rty_AFAMgt_bEveRstStabChkAck, UInt32
  *rty_AFAMgt_tiCntStabFuMod)
{
  UInt32 localtmp;

  /* If: '<Root>/If1' incorporates:
   *  ActionPort: '<S1>/Action Port'
   *  ActionPort: '<S2>/Action Port'
   *  Logic: '<Root>/Logical Operator'
   *  SubSystem: '<Root>/F01_Afa_fuel_mode_stable_no_check'
   *  SubSystem: '<Root>/F02_Afa_fuel_mode_stable_check'
   *
   * Block requirements for '<Root>/F01_Afa_fuel_mode_stable_no_check':
   *  1. SubSystem "F01_Afa_fuel_mode_stable_no_check" !Trace_To : VEMS_R_11 _04434_042.01 ;
   *
   * Block requirements for '<Root>/F02_Afa_fuel_mode_stable_check':
   *  1. SubSystem "F02_Afa_fuel_mode_stable_check" !Trace_To : VEMS_R_11 _04434_043.01 ;
   */
  if (((!(*rtu_InjSys_bAcvFuCll)) || (*rtu_AFAMgt_bEveRstStab2)) ||
      (*rtu_AFAMgt_bInhAF2)) {
    /* Constant: '<S1>/Constant1' */
    (*rty_AFAMgt_bEveRstStabChkAck) = FALSE;

    /* Constant: '<S1>/Constant2' */
    (*rty_AFAMgt_bIdcStabFuMod) = FALSE;

    /* SignalConversion: '<S1>/Signal Conversion' incorporates:
     *  Constant: '<S1>/AFAMgt_tiDlyStabFuMod_C'
     */
    (*rty_AFAMgt_tiCntStabFuMod) = AFAMgt_tiDlyStabFuMod_C;
  } else {
    /* If: '<S2>/If' incorporates:
     *  ActionPort: '<S3>/Action Port'
     *  ActionPort: '<S4>/Action Port'
     *  Constant: '<S2>/Constant'
     *  RelationalOperator: '<S2>/Relational Operator'
     *  SubSystem: '<S2>/F01_Afa_fuel_mode_stable'
     *  SubSystem: '<S2>/F02_Afa_fuel_mode_stable_Wait'
     *
     * Block requirements for '<S2>/F01_Afa_fuel_mode_stable':
     *  1. SubSystem "F01_Afa_fuel_mode_stable" !Trace_To : VEMS_R_11 _04434_044.01 ;
     *
     * Block requirements for '<S2>/F02_Afa_fuel_mode_stable_Wait':
     *  1. SubSystem "F02_Afa_fuel_mode_stable_Wait" !Trace_To : VEMS_R_11 _04434_045.01 ;
     */
    if ((*rtu_AFAMgt_tiCntStabFuModPrev) <= 0U) {
      /* Constant: '<S3>/Constant4' */
      (*rty_AFAMgt_bIdcStabFuMod) = TRUE;

      /* SignalConversion: '<S3>/Signal Conversion' */
      (*rty_AFAMgt_tiCntStabFuMod) = (*rtu_AFAMgt_tiCntStabFuModPrev);
    } else {
      /* Constant: '<S4>/Constant4' */
      (*rty_AFAMgt_bIdcStabFuMod) = FALSE;

      /* Sum: '<S4>/Add1' incorporates:
       *  Constant: '<S4>/AFAMgt_tiSampleSlow_SC'
       */
      localtmp = (*rtu_AFAMgt_tiCntStabFuModPrev) - ((((UInt32)
        AFAMgt_tiSampleSlow_SC) * 52429U) >> 19);
      if (localtmp > (*rtu_AFAMgt_tiCntStabFuModPrev)) {
        localtmp = 0U;
      }

      (*rty_AFAMgt_tiCntStabFuMod) = localtmp;
    }

    /* SignalConversion: '<S2>/Signal Conversion' */
    (*rty_AFAMgt_bEveRstStabChkAck) = (*rtu_AFAMgt_bEveRstStab2);
  }
}

/* Model initialize function */
void mr_AFAMgtT_F04_check_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
