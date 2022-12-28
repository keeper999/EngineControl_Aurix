/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA                                                     */
/* !Description     : AFA Software Component                                  */
/*                                                                            */
/* !File            : AFA_F02_Activation_EOM_Mode.c                           */
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
/*   Model name       : AFA_F02_Activation_EOM_Mode.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F02_Activation_EOM_Mode.h"
#include "AFA_F02_Activation_EOM_Mode_private.h"
#include "AFAT.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAT_MemMap.h"


/* Exported block signals */
Boolean AFA_bIdcObsSpcInjWiDly;      /* '<S5>/Relational Operator3' */

/* Exported block states */
Boolean AFA_bIdcObsSpcInjMod_MP;     /* '<S1>/Data Store Memory' */
Boolean AFA_bIdcObsSpcInjSel_MP;     /* '<S1>/Data Store Memory1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

rtMdlrefDWork_mr_AFA_F02_Activa mr_AFA_F02_Activati_MdlrefDWork;


#define AFAT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F02_Activation_EOM_Mode' */
void mr_AFA_F02_Activation_EOM_Mode(const UInt8 *rtu_AFA_noObsSpcInjModP2,
  const UInt16 *rtu_AFA_noAdpEfc2, const Boolean *rtu_AFAMgt_bIdcInjrMdlC2,
  const Boolean *rtu_AFAMgt_bIdcTmpObsC2, const UInt32
  *rtu_AFA_tiAcvSpcInjModP2, UInt8 *rty_AFA_noObsSpcInj2, Boolean
  *rty_AFA_bAcvSpcInj2, UInt32 *rty_AFA_tiAcvSpcInj2)
{
  rtB_mr_AFA_F02_Activation_EOM_M *localB =
    &(mr_AFA_F02_Activati_MdlrefDWork.rtb);
  rtDW_mr_AFA_F02_Activation_EOM_ *localDW =
    &(mr_AFA_F02_Activati_MdlrefDWork.rtdw);
  UInt8 localSwitch3_e;
  Boolean localLogicalOperator;
  Boolean localLogicalOperator2_e;
  SInt32 localSwitch;
  UInt32 localtmp;

  /* Outputs for atomic SubSystem: '<Root>/F01_Specific_Observation_Conditions' *
   * Block requirements for '<Root>/F01_Specific_Observation_Conditions':
   *  1. SubSystem "F01_Specific_Observation_Conditions" !Trace_To : VEMS_R_11_04467_034.01 ;
   */

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Logic: '<S1>/Logical Operator1'
   */
  localLogicalOperator = ((*rtu_AFAMgt_bIdcTmpObsC2) &&
    (!(*rtu_AFAMgt_bIdcInjrMdlC2)));

  /* DataStoreWrite: '<S1>/Data Store Write' */
  AFA_bIdcObsSpcInjMod_MP = localLogicalOperator;

  /* Logic: '<S1>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S1>/Relational Operator2'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  localLogicalOperator2_e = ((localLogicalOperator) && (((SInt32)
    localLogicalOperator) != ((SInt32)localDW->UnitDelay_DSTATE)));

  /* DataStoreWrite: '<S1>/Data Store Write1' */
  AFA_bIdcObsSpcInjSel_MP = localLogicalOperator2_e;

  /* S-Function (fcncallgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/Subsystem'
   */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S1>/AFA_tiDlySpcInjMod_C'
   *  Constant: '<S1>/AFA_tiSampleSlow_SC'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Inport: '<S5>/Timer_prev'
   *  Logic: '<S6>/Logical Operator2'
   *  Logic: '<S6>/Logical Operator4'
   *  Sum: '<S5>/Add1'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  if ((!localLogicalOperator) && localDW->UnitDelay1_DSTATE) {
    localtmp = mul_u32_u32_u32_sat(AFA_tiDlySpcInjMod_C, 10U);
    if (localtmp > 2147483647U) {
      localSwitch = MAX_int32_T;
    } else {
      localSwitch = (SInt32)localtmp;
    }
  } else {
    localSwitch = localB->MinMax - AFA_tiSampleSlow_SC;
    if ((localB->MinMax < 0) && (localSwitch >= 0)) {
      localSwitch = MIN_int32_T;
    }
  }

  /* MinMax: '<S5>/MinMax' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (0 > localSwitch) {
    localSwitch = 0;
  }

  localB->MinMax = localSwitch;

  /* RelationalOperator: '<S5>/Relational Operator3' incorporates:
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  AFA_bIdcObsSpcInjWiDly = ((localB->MinMax <= 0) == ((SInt32)
    localLogicalOperator));

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = localLogicalOperator;

  /* Switch: '<S1>/Switch3' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Sum'
   */
  if (localLogicalOperator2_e) {
    localSwitch = (*rtu_AFA_noObsSpcInjModP2) + 1;
    if (((UInt32)localSwitch) > 255U) {
      localSwitch3_e = MAX_uint8_T;
    } else {
      localSwitch3_e = (UInt8)localSwitch;
    }
  } else {
    localSwitch3_e = (*rtu_AFA_noObsSpcInjModP2);
  }

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localLogicalOperator;

  /* end of Outputs for SubSystem: '<Root>/F01_Specific_Observation_Conditions' */

  /* Outputs for atomic SubSystem: '<Root>/F02_Specific_Injection_Conditions' *
   * Block requirements for '<Root>/F02_Specific_Injection_Conditions':
   *  1. SubSystem "F02_Specific_Injection_Conditions" !Trace_To : VEMS_R_11_04467_035.01 ;
   */

  /* Logic: '<S2>/Logical Operator3' incorporates:
   *  Constant: '<S2>/AFA_noObsSpcInjModThd_C'
   *  RelationalOperator: '<S2>/Relational Operator1'
   */
  localLogicalOperator = ((localSwitch3_e > AFA_noObsSpcInjModThd_C) &&
    (AFA_bIdcObsSpcInjWiDly));

  /* Switch: '<S2>/Switch3' incorporates:
   *  Constant: '<S2>/AFA_tiDlySpcInjMod_C'
   *  Constant: '<S2>/AFA_tiSampleSlow_SC'
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  Sum: '<S2>/Sum1'
   */
  if (localLogicalOperator) {
    localtmp = mul_u32_u32_u32_sat((*rtu_AFA_tiAcvSpcInjModP2), 10U);
    if (localtmp > 2147483647U) {
      localSwitch = MAX_int32_T;
    } else {
      localSwitch = (SInt32)localtmp;
    }

    localSwitch -= AFA_tiSampleSlow_SC;
  } else {
    localtmp = mul_u32_u32_u32_sat(AFA_tiDlySpcInjMod_C, 10U);
    if (localtmp > 2147483647U) {
      localSwitch = MAX_int32_T;
    } else {
      localSwitch = (SInt32)localtmp;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  (*rty_AFA_tiAcvSpcInj2) = mul_u32_s32_s32_sr33_sat_near(localSwitch, 858993459);

  /* Logic: '<S2>/Logical Operator2' incorporates:
   *  Constant: '<S2>/AFA_noAdpEfcSpcInjModThd_C'
   *  Constant: '<S2>/Constant8'
   *  Logic: '<S2>/Logical Operator4'
   *  RelationalOperator: '<S2>/Relational Operator2'
   *  RelationalOperator: '<S2>/Relational Operator4'
   */
  (*rty_AFA_bAcvSpcInj2) = (((*rtu_AFA_noAdpEfc2) < AFA_noAdpEfcSpcInjModThd_C) ||
                            ((localLogicalOperator) && (localSwitch > 0)));

  /* end of Outputs for SubSystem: '<Root>/F02_Specific_Injection_Conditions' */

  /* SignalConversion: '<Root>/Signal Conversion' */
  (*rty_AFA_noObsSpcInj2) = localSwitch3_e;
}

/* Model initialize function */
void mr_AFA_F02_Activatio_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
