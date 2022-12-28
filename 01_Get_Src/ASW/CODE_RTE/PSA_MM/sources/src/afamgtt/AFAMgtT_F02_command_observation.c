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
/* !File            : AFAMgtT_F02_command_observation.c                       */
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
/*   Model name       : AFAMgtT_F02_command_observation.mdl                   */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   22 Aug 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT_F02_command_observation.h"
#include "AFAMgtT_F02_command_observation_private.h"
#include "AFAMgtT.h"
/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S2>/F01_command_observation_chart' */
#define AFAMgtT_F02__IN_NO_ACTIVE_CHILD (0U)
#define AFAMgtT_F02_c_IN_PasObservation (2U)
#define AFAMgtT_F02_comm_IN_Observation (2U)
#define AFAMgtT_F_IN_AttenteObservation (1U)
#define AFAMgtT_F_IN_DemandeObservation (1U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */


#define AFAMgtT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAMgtT_MemMap.h"


/* Exported block signals */
Boolean AFAMgt_bIdcTmpObsCndOk;      /* '<S1>/Logical Operator2' */
Boolean AFAMgt_bIdcTiInjMinCnd;      /* '<S20>/Logical Operator2' */
Boolean AFAMgt_bIdcFacCorGainLnrCnd; /* '<S19>/Logical Operator2' */
Boolean AFAMgt_bIdcDeltaLdInjPhaCnd; /* '<S10>/Relational Operator8' */
Boolean AFAMgt_bIdcMassAirScvCnd;    /* '<S9>/Relational Operator1' */
Boolean AFAMgt_bIdcStabCnd;          /* '<S8>/Logical Operator1' */
Boolean AFAMgt_bIdcPresCnd;          /* '<S7>/Logical Operator1' */
Boolean AFAMgt_bIdcThermoCnd;        /* '<S6>/Logical Operator1' */
Boolean AFAMgt_bIdcTiDlyObsCnd;      /* '<S5>/Relational Operator' */
Boolean AFAMgt_bIdcFARSpCnd;         /* '<S4>/Logical Operator1' */
Boolean AFAMgt_bIdcEngCnd;           /* '<S3>/Logical Operator2' */

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_VAR_UNSPECIFIED
#include "AFAMgtT_MemMap.h"

rtMdlrefDWork_mr_AFAMgtT_F02_co mr_AFAMgtT_F02_comm_MdlrefDWork;


#define AFAMgtT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAMgtT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

/* Initial conditions for referenced model: 'AFAMgtT_F02_command_observation' */
void mr_AFAMgtT_F02_command_obs_Init(Boolean *rty_AFAMgt_bDgoObsAdp, Boolean
  *rty_AFAMgt_bMonRunObsAdp)
{
  /* InitializeConditions for atomic SubSystem: '<Root>/F02_Manager' *
   * Block requirements for '<Root>/F02_Manager':
   *  1. SubSystem "F02_Manager" !Trace_To : VEMS_R_11 _04434_070.01 ;
   */

  /* InitializeConditions for Stateflow: '<S2>/F01_command_observation_chart' */
  (*rty_AFAMgt_bDgoObsAdp) = FALSE;
  (*rty_AFAMgt_bMonRunObsAdp) = FALSE;

  /* end of InitializeConditions for SubSystem: '<Root>/F02_Manager' */
}

/* Output and update for referenced model: 'AFAMgtT_F02_command_observation' */
void mr_AFAMgtT_F02_command_observat(const Boolean *rtu_AFAMgt_bStabAirLdCor,
  const Boolean *rtu_AFAMgt_bIdcStabRatOpEGR, const Boolean
  *rtu_AFAMgt_bIdcNotDynCorPres, const Boolean *rtu_AFAMgt_bStabEgdGear, const
  Boolean *rtu_AFAMgt_bIdcStabAirMod, const Boolean
  *rtu_AFAMgt_bIdcStabFuMod, const Boolean *rtu_GSM_bAcvAFAAdp, const UInt32
  *rtu_AFAMgt_tiDlyLstObsThd, const UInt16 *rtu_Ext_nEng, const UInt32
  *rtu_AFA_tiDlyLstObs, const UInt16 *rtu_EngM_rTotLdExCor, const UInt16
  *rtu_Ext_pDsThrMesSI, const Boolean *rtu_FRM_bInhAFAObsAdp, const SInt16
  *rtu_Ext_tDsThrMes, const SInt16 *rtu_Ext_tCoMes, const Boolean
  *rtu_AFA_bAuthClsCan1, const UInt16 *rtu_FARSp_rMixtCylSp, const UInt16
  *rtu_AFA_nEngLstObs, const UInt16 *rtu_AFA_rTotLdCorLstObs, const UInt16
  *rtu_UsThrM_pAirExt, const Boolean *rtu_AFAMgt_bStabEOM, const SInt16
  *rtu_EngM_rDeltaLdInjPha, const UInt16 rtu_InjrM_prm_facCorGainLnr[4], const
  UInt16 rtu_InjrM_prm_pDifInjr[4], const UInt32 rtu_InjrSys_prm_tiInj[4],
  const Boolean *rtu_AFAMgt_bStabFacStrtCor, const Boolean
  *rtu_Blby_bIdcWoutBlbyCnd, const UInt16 *rtu_EngM_rltMassAirScvCor,
  Boolean *rty_AFAMgt_bIdcTmpObs1, Boolean *rty_AFAMgt_bIdcInjrMdl1,
  Boolean *rty_AFAMgt_bDgoObsAdp, Boolean *rty_AFAMgt_bMonRunObsAdp,
  Boolean *rty_AFAMgt_bAuthAdp1, Boolean *rty_AFAMgt_bAdpObs1)
{
  rtB_mr_AFAMgtT_F02_command_obse *localB =
    &(mr_AFAMgtT_F02_comm_MdlrefDWork.rtb);
  rtDW_mr_AFAMgtT_F02_command_obs *localDW =
    &(mr_AFAMgtT_F02_comm_MdlrefDWork.rtdw);

  /* local block i/o variables */
  UInt32 localLookUpTable[4];
  UInt32 localDataTypeConversion_f[4];
  UInt32 localDataTypeConversion_e[4];
  UInt16 localLookUpTable_k[4];
  Boolean localLogicalOperator1_ix;
  Boolean localLogicalOperator;
  Float32 localMerge;
  Float32 localAdd1;
  Float32 localSwitch1;
  Float32 localSwitch1_c;
  Float32 localSwitch1_e;
  UInt16 localAbs1_l;
  Float32 locallocalAbs2_idx;
  Float32 locallocalAbs2_idx_0;
  Float32 locallocalAbs2_idx_1;
  Float32 locallocalAbs2_idx_2;

  /* Outputs for atomic SubSystem: '<Root>/F01_calc_Tempo' *
   * Block requirements for '<Root>/F01_calc_Tempo':
   *  1. SubSystem "F01_calc_Tempo" !Trace_To : VEMS_R_11 _04434_058.01 ;
   */

  /* Outputs for atomic SubSystem: '<S1>/F01_Engine_state_Conditions' *
   * Block requirements for '<S1>/F01_Engine_state_Conditions':
   *  1. SubSystem "F01_Engine_state_Conditions" !Trace_To : VEMS_R_11 _04434_059.01 ;
   */

  /* Logic: '<S3>/Logical Operator2' incorporates:
   *  Abs: '<S3>/Abs'
   *  Abs: '<S3>/Abs1'
   *  Constant: '<S3>/AFAMgt_nEngLstObsThd_C'
   *  Constant: '<S3>/AFAMgt_rTotLdCorLstObsThd_C'
   *  RelationalOperator: '<S3>/Relational Operator8'
   *  RelationalOperator: '<S3>/Relational Operator9'
   *  Sum: '<S3>/Add'
   *  Sum: '<S3>/Add1'
   */
  AFAMgt_bIdcEngCnd = ((ACTEMS_FabsF((((Float32)(*rtu_EngM_rTotLdExCor)) *
    6.103515625E-005F) - (((Float32)(*rtu_AFA_rTotLdCorLstObs)) *
    6.103515625E-005F)) > (((Float32)AFAMgt_rTotLdCorLstObsThd_C) *
    6.103515625E-005F)) || (((SInt32)ACTEMS_FabsF((Float32)((*rtu_Ext_nEng) -
                           (*rtu_AFA_nEngLstObs)))) > AFAMgt_nEngLstObsThd_C));

  /* end of Outputs for SubSystem: '<S1>/F01_Engine_state_Conditions' */

  /* Outputs for atomic SubSystem: '<S1>/F02_Richness_Condition' *
   * Block requirements for '<S1>/F02_Richness_Condition':
   *  1. SubSystem "F02_Richness_Condition" !Trace_To : VEMS_R_11 _04434_060.01 ;
   */

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Constant: '<S4>/AFAMgt_rlamReqMaxThd_C'
   *  Constant: '<S4>/AFAMgt_rlamReqMinThd_C'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  RelationalOperator: '<S4>/Relational Operator7'
   */
  AFAMgt_bIdcFARSpCnd = ((((UInt32)(AFAMgt_rlamReqMaxThd_C * 15)) > ((UInt32)
                           ((*rtu_FARSp_rMixtCylSp) << 4))) && (((UInt32)
    ((*rtu_FARSp_rMixtCylSp) << 4)) > ((UInt32)(AFAMgt_rlamReqMinThd_C * 15))));

  /* end of Outputs for SubSystem: '<S1>/F02_Richness_Condition' */

  /* Outputs for atomic SubSystem: '<S1>/F03_Delay_Observation_Conditions' *
   * Block requirements for '<S1>/F03_Delay_Observation_Conditions':
   *  1. SubSystem "F03_Delay_Observation_Conditions" !Trace_To : VEMS_R_11 _04434_061.01 ;
   */

  /* RelationalOperator: '<S5>/Relational Operator' */
  AFAMgt_bIdcTiDlyObsCnd = ((*rtu_AFA_tiDlyLstObs) > (*rtu_AFAMgt_tiDlyLstObsThd));

  /* end of Outputs for SubSystem: '<S1>/F03_Delay_Observation_Conditions' */

  /* Outputs for atomic SubSystem: '<S1>/F04_Temperature_Conditions' *
   * Block requirements for '<S1>/F04_Temperature_Conditions':
   *  1. SubSystem "F04_Temperature_Conditions" !Trace_To : VEMS_R_11 _04434_062.01 ;
   */

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S6>/AFAMgt_tAirMaxThd_C'
   *  Constant: '<S6>/AFAMgt_tAirMinThd_C'
   *  Constant: '<S6>/AFAMgt_tCoMaxThd_C'
   *  Constant: '<S6>/AFAMgt_tCoMinThd_C'
   *  RelationalOperator: '<S6>/Relational Operator2'
   *  RelationalOperator: '<S6>/Relational Operator3'
   *  RelationalOperator: '<S6>/Relational Operator4'
   *  RelationalOperator: '<S6>/Relational Operator5'
   */
  AFAMgt_bIdcThermoCnd = (((((AFAMgt_tAirMaxThd_C + -50) > (*rtu_Ext_tDsThrMes))
    && ((*rtu_Ext_tDsThrMes) >= (AFAMgt_tAirMinThd_C + -50))) &&
    ((AFAMgt_tCoMaxThd_C + -40) > (*rtu_Ext_tCoMes))) && ((*rtu_Ext_tCoMes) >=
    (AFAMgt_tCoMinThd_C + -40)));

  /* end of Outputs for SubSystem: '<S1>/F04_Temperature_Conditions' */

  /* Outputs for atomic SubSystem: '<S1>/F05_Pressure_Conditions' *
   * Block requirements for '<S1>/F05_Pressure_Conditions':
   *  1. SubSystem "F05_Pressure_Conditions" !Trace_To : VEMS_R_11 _04434_063.01 ;
   */

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S7>/AFAMgt_pDsThrMaxThd_C'
   *  Constant: '<S7>/AFAMgt_pDsThrMinThd_C'
   *  Constant: '<S7>/Air_pRef_C'
   *  Product: '<S12>/Divide'
   *  Product: '<S13>/Divide'
   *  RelationalOperator: '<S7>/Relational Operator10'
   *  RelationalOperator: '<S7>/Relational Operator6'
   */
  AFAMgt_bIdcPresCnd = (((((Float32)(ACTEMS_LdexpF((Float32d)(*rtu_UsThrM_pAirExt),
    3) / (ACTEMS_LdexpF((Float32d)Air_pRef_C, 3) + 1.0E+005F))) * (((Float32)
    AFAMgt_pDsThrMaxThd_C) * 8.0F)) > (((Float32)(*rtu_Ext_pDsThrMesSI)) * 8.0F))
                        && ((*rtu_Ext_pDsThrMesSI) > AFAMgt_pDsThrMinThd_C));

  /* end of Outputs for SubSystem: '<S1>/F05_Pressure_Conditions' */

  /* Outputs for atomic SubSystem: '<S1>/F06_Stabilty_Conditions' *
   * Block requirements for '<S1>/F06_Stabilty_Conditions':
   *  1. SubSystem "F06_Stabilty_Conditions" !Trace_To : VEMS_R_11 _04434_064.01 ;
   */

  /* Logic: '<S8>/Logical Operator1' */
  AFAMgt_bIdcStabCnd = (((((((*rtu_AFAMgt_bStabAirLdCor) &&
    (*rtu_AFAMgt_bIdcStabRatOpEGR)) && (*rtu_AFAMgt_bIdcNotDynCorPres)) &&
    (*rtu_AFAMgt_bStabEgdGear)) && (*rtu_AFAMgt_bIdcStabFuMod)) &&
    (*rtu_AFAMgt_bStabEOM)) && (*rtu_AFAMgt_bStabFacStrtCor));

  /* end of Outputs for SubSystem: '<S1>/F06_Stabilty_Conditions' */

  /* Outputs for atomic SubSystem: '<S1>/F07_Air_Scavaging_Condition' *
   * Block requirements for '<S1>/F07_Air_Scavaging_Condition':
   *  1. SubSystem "F07_Air_Scavaging_Condition" !Trace_To : VEMS_R_11 _04434_065.01 ;
   */

  /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
   *  Constant: '<S9>/AFAMgt_rltMassAirScvMaxThd_C'
   */
  AFAMgt_bIdcMassAirScvCnd = (((UInt32)(AFAMgt_rltMassAirScvMaxThd_C << 2)) >
                              ((UInt32)(*rtu_EngM_rltMassAirScvCor)));

  /* end of Outputs for SubSystem: '<S1>/F07_Air_Scavaging_Condition' */

  /* Outputs for atomic SubSystem: '<S1>/F08_Engine_Load_Model_Correction_Conditions' *
   * Block requirements for '<S1>/F08_Engine_Load_Model_Correction_Conditions':
   *  1. SubSystem "F08_Engine_Load_Model_Correction_Conditions" !Trace_To : VEMS_R_11 _04434_066.01 ;
   */

  /* Abs: '<S10>/Abs1' */
  if ((*rtu_EngM_rDeltaLdInjPha) < 0) {
    localAbs1_l = (UInt16)((UInt32)(-(*rtu_EngM_rDeltaLdInjPha)));
  } else {
    localAbs1_l = (UInt16)(*rtu_EngM_rDeltaLdInjPha);
  }

  /* If: '<S14>/If2' incorporates:
   *  ActionPort: '<S17>/Action Port'
   *  ActionPort: '<S18>/Action Port'
   *  Constant: '<S14>/Constant7'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  SubSystem: '<S14>/If Action Subsystem2'
   *  SubSystem: '<S14>/If Action Subsystem3'
   */
  if ((*rtu_EngM_rTotLdExCor) == 0) {
    /* Constant: '<S17>/Byp_Fonction_SC' */
    localMerge = 0.0F;
  } else {
    /* Product: '<S18>/Divide1' */
    localMerge = (Float32)((((Float32d)localAbs1_l) * 9.1552734375000000E-005F) /
      ACTEMS_LdexpF((Float32d)(*rtu_EngM_rTotLdExCor), -14));
  }

  /* RelationalOperator: '<S10>/Relational Operator8' incorporates:
   *  Constant: '<S10>/AFAMgt_rDeltaLdInjPhaObsThd_C'
   */
  AFAMgt_bIdcDeltaLdInjPhaCnd = (localMerge < (((Float32)
    AFAMgt_rDeltaLdInjPhaObsThd_C) * 0.00390625F));

  /* end of Outputs for SubSystem: '<S1>/F08_Engine_Load_Model_Correction_Conditions' */

  /* Outputs for atomic SubSystem: '<S1>/F09_Injector_Model_Correction_Condition' *
   * Block requirements for '<S1>/F09_Injector_Model_Correction_Condition':
   *  1. SubSystem "F09_Injector_Model_Correction_Condition" !Trace_To : VEMS_R_11 _04434_067.01 ;
   */

  /* Outputs for atomic SubSystem: '<S11>/F01_Gain_Linear_Correction_Condition' *
   * Block requirements for '<S11>/F01_Gain_Linear_Correction_Condition':
   *  1. SubSystem "F01_Gain_Linear_Correction_Condition" !Trace_To : VEMS_R_11 _04434_068.01 ;
   */

  /* Sum: '<S19>/Add1' */
  localAdd1 = (((((Float32)rtu_InjrSys_prm_tiInj[0]) * 3.200000037E-006F) +
                (((Float32)rtu_InjrSys_prm_tiInj[1]) * 3.200000037E-006F)) +
               (((Float32)rtu_InjrSys_prm_tiInj[2]) * 3.200000037E-006F)) +
    (((Float32)rtu_InjrSys_prm_tiInj[3]) * 3.200000037E-006F);

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<S19>/Cste_1'
   */
  locallocalAbs2_idx = (((Float32)rtu_InjrM_prm_facCorGainLnr[0]) *
                        3.051757813E-005F) - 1.0F;

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  localDataTypeConversion_e[0] = rtu_InjrM_prm_pDifInjr[0];

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<S19>/Cste_1'
   */
  locallocalAbs2_idx_0 = (((Float32)rtu_InjrM_prm_facCorGainLnr[1]) *
    3.051757813E-005F) - 1.0F;

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  localDataTypeConversion_e[1] = rtu_InjrM_prm_pDifInjr[1];

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<S19>/Cste_1'
   */
  locallocalAbs2_idx_1 = (((Float32)rtu_InjrM_prm_facCorGainLnr[2]) *
    3.051757813E-005F) - 1.0F;

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  localDataTypeConversion_e[2] = rtu_InjrM_prm_pDifInjr[2];

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<S19>/Cste_1'
   */
  locallocalAbs2_idx_2 = (((Float32)rtu_InjrM_prm_facCorGainLnr[3]) *
    3.051757813E-005F) - 1.0F;

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  localDataTypeConversion_e[3] = rtu_InjrM_prm_pDifInjr[3];

  /* Lookup: '<S21>/Look-Up Table'
   * About '<S21>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U32  2^9  FSlope 1.5258789062500000E+000
   * Output0 Data Type:  Fixed Point    U16  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U32( &(localLookUpTable_k[0]), (&(AFAMgt_facCorGainLnrThd_T[0])),
                 localDataTypeConversion_e[0], (&(AFAMgt_pDifInjr_A[0])), 8U);
  LookUp_U16_U32( &(localLookUpTable_k[1]), (&(AFAMgt_facCorGainLnrThd_T[0])),
                 localDataTypeConversion_e[1], (&(AFAMgt_pDifInjr_A[0])), 8U);
  LookUp_U16_U32( &(localLookUpTable_k[2]), (&(AFAMgt_facCorGainLnrThd_T[0])),
                 localDataTypeConversion_e[2], (&(AFAMgt_pDifInjr_A[0])), 8U);
  LookUp_U16_U32( &(localLookUpTable_k[3]), (&(AFAMgt_facCorGainLnrThd_T[0])),
                 localDataTypeConversion_e[3], (&(AFAMgt_pDifInjr_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S21>/Data Type Duplicate1'
   *
   * Regarding '<S21>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Product: '<S25>/Divide' incorporates:
   *  DataTypeConversion: '<S19>/Data Type Conversion'
   */
  localMerge = (((Float32)rtu_InjrSys_prm_tiInj[0]) * 3.200000037E-006F) /
    localAdd1;

  /* Outputs for atomic SubSystem: '<S25>/If Action Subsystem3' */

  /* Switch: '<S33>/Switch1' incorporates:
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S33>/Constant2'
   *  Constant: '<S33>/Constant3'
   *  Logic: '<S33>/Logical Operator1'
   *  RelationalOperator: '<S33>/Relational Operator'
   *  RelationalOperator: '<S33>/Relational Operator1'
   *  RelationalOperator: '<S33>/Relational Operator3'
   *  Saturate: '<S33>/Saturation'
   */
  if (((localMerge != localMerge) || (localMerge > 1.0E+007F)) || (-1.0E+007F >
       localMerge)) {
    localSwitch1 = 1.0F;
  } else {
    localSwitch1 = rt_SATURATE(localMerge, -1.0E+007F, 1.0E+007F);
  }

  /* end of Outputs for SubSystem: '<S25>/If Action Subsystem3' */

  /* Product: '<S24>/Divide' incorporates:
   *  DataTypeConversion: '<S19>/Data Type Conversion1'
   */
  localMerge = (((Float32)rtu_InjrSys_prm_tiInj[1]) * 3.200000037E-006F) /
    localAdd1;

  /* Outputs for atomic SubSystem: '<S24>/If Action Subsystem3' */

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S31>/Constant2'
   *  Constant: '<S31>/Constant3'
   *  Logic: '<S31>/Logical Operator1'
   *  RelationalOperator: '<S31>/Relational Operator'
   *  RelationalOperator: '<S31>/Relational Operator1'
   *  RelationalOperator: '<S31>/Relational Operator3'
   *  Saturate: '<S31>/Saturation'
   */
  if (((localMerge != localMerge) || (localMerge > 1.0E+007F)) || (-1.0E+007F >
       localMerge)) {
    localSwitch1_c = 1.0F;
  } else {
    localSwitch1_c = rt_SATURATE(localMerge, -1.0E+007F, 1.0E+007F);
  }

  /* end of Outputs for SubSystem: '<S24>/If Action Subsystem3' */

  /* Product: '<S23>/Divide' incorporates:
   *  DataTypeConversion: '<S19>/Data Type Conversion2'
   */
  localMerge = (((Float32)rtu_InjrSys_prm_tiInj[2]) * 3.200000037E-006F) /
    localAdd1;

  /* Outputs for atomic SubSystem: '<S23>/If Action Subsystem3' */

  /* Switch: '<S29>/Switch1' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S29>/Constant3'
   *  Logic: '<S29>/Logical Operator1'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  RelationalOperator: '<S29>/Relational Operator1'
   *  RelationalOperator: '<S29>/Relational Operator3'
   *  Saturate: '<S29>/Saturation'
   */
  if (((localMerge != localMerge) || (localMerge > 1.0E+007F)) || (-1.0E+007F >
       localMerge)) {
    localSwitch1_e = 1.0F;
  } else {
    localSwitch1_e = rt_SATURATE(localMerge, -1.0E+007F, 1.0E+007F);
  }

  /* end of Outputs for SubSystem: '<S23>/If Action Subsystem3' */

  /* Product: '<S22>/Divide' incorporates:
   *  DataTypeConversion: '<S19>/Data Type Conversion3'
   */
  localMerge = (((Float32)rtu_InjrSys_prm_tiInj[3]) * 3.200000037E-006F) /
    localAdd1;

  /* Outputs for atomic SubSystem: '<S22>/If Action Subsystem3' */

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/Constant1'
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S27>/Constant3'
   *  Logic: '<S27>/Logical Operator1'
   *  RelationalOperator: '<S27>/Relational Operator'
   *  RelationalOperator: '<S27>/Relational Operator1'
   *  RelationalOperator: '<S27>/Relational Operator3'
   *  Saturate: '<S27>/Saturation'
   */
  if (((localMerge != localMerge) || (localMerge > 1.0E+007F)) || (-1.0E+007F >
       localMerge)) {
    localMerge = 1.0F;
  } else {
    localMerge = rt_SATURATE(localMerge, -1.0E+007F, 1.0E+007F);
  }

  /* end of Outputs for SubSystem: '<S22>/If Action Subsystem3' */

  /* Logic: '<S19>/Logical Operator2' incorporates:
   *  Abs: '<S19>/Abs2'
   *  Constant: '<S19>/AFAMgt_tiObsThd1_C'
   *  Constant: '<S19>/AFAMgt_tiObsThd2_C'
   *  Constant: '<S19>/AFAMgt_tiObsThd3_C'
   *  Constant: '<S19>/AFAMgt_tiObsThd4_C'
   *  Logic: '<S19>/Logical Operator1'
   *  RelationalOperator: '<S19>/Relational Operator1'
   *  RelationalOperator: '<S19>/Relational Operator2'
   *  RelationalOperator: '<S19>/Relational Operator3'
   *  RelationalOperator: '<S19>/Relational Operator4'
   *  RelationalOperator: '<S19>/Relational Operator5'
   */
  AFAMgt_bIdcFacCorGainLnrCnd = (((((ACTEMS_FabsF(locallocalAbs2_idx) <
    (((Float32)localLookUpTable_k[0]) * 3.051757813E-005F)) || (localSwitch1 <
                                     (((Float32)AFAMgt_tiObsThd1_C) *
    3.200000037E-006F))) && ((ACTEMS_FabsF(locallocalAbs2_idx_0) < (((Float32)
    localLookUpTable_k[1]) * 3.051757813E-005F)) || (localSwitch1_c <
    (((Float32)AFAMgt_tiObsThd2_C) * 3.200000037E-006F)))) && ((ACTEMS_FabsF
    (locallocalAbs2_idx_1) < (((Float32)localLookUpTable_k[2]) *
    3.051757813E-005F)) || (localSwitch1_e < (((Float32)AFAMgt_tiObsThd3_C) *
    3.200000037E-006F)))) && ((ACTEMS_FabsF(locallocalAbs2_idx_2) < (((Float32)
    localLookUpTable_k[3]) * 3.051757813E-005F)) || (localMerge < (((Float32)
    AFAMgt_tiObsThd4_C) * 3.200000037E-006F))));

  /* end of Outputs for SubSystem: '<S11>/F01_Gain_Linear_Correction_Condition' */

  /* Outputs for atomic SubSystem: '<S11>/F02_Injection_Timing_Conditions' *
   * Block requirements for '<S11>/F02_Injection_Timing_Conditions':
   *  1. SubSystem "F02_Injection_Timing_Conditions" !Trace_To : VEMS_R_11 _04434_069.01 ;
   */

  /* DataTypeConversion: '<S34>/Data Type Conversion' */
  localDataTypeConversion_f[0] = rtu_InjrM_prm_pDifInjr[0];
  localDataTypeConversion_f[1] = rtu_InjrM_prm_pDifInjr[1];
  localDataTypeConversion_f[2] = rtu_InjrM_prm_pDifInjr[2];
  localDataTypeConversion_f[3] = rtu_InjrM_prm_pDifInjr[3];

  /* Lookup: '<S34>/Look-Up Table'
   * About '<S34>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U32  2^9  FSlope 1.5258789062500000E+000
   * Output0 Data Type:  Fixed Point    U32  2^-19  FSlope 1.6777216
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U32_U32( &(localLookUpTable[0]), (&(AFAMgt_tiInjLoThd_T[0])),
                 localDataTypeConversion_f[0], (&(AFAMgt_pDifInjr_A[0])), 8U);
  LookUp_U32_U32( &(localLookUpTable[1]), (&(AFAMgt_tiInjLoThd_T[0])),
                 localDataTypeConversion_f[1], (&(AFAMgt_pDifInjr_A[0])), 8U);
  LookUp_U32_U32( &(localLookUpTable[2]), (&(AFAMgt_tiInjLoThd_T[0])),
                 localDataTypeConversion_f[2], (&(AFAMgt_pDifInjr_A[0])), 8U);
  LookUp_U32_U32( &(localLookUpTable[3]), (&(AFAMgt_tiInjLoThd_T[0])),
                 localDataTypeConversion_f[3], (&(AFAMgt_pDifInjr_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate1'
   *
   * Regarding '<S34>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Logic: '<S20>/Logical Operator2' incorporates:
   *  Constant: '<S20>/Cste_0'
   *  DataTypeConversion: '<S34>/Data Type Conversion'
   *  Inport: '<Root>/InjrM_prm_pDifInjr'
   *  Logic: '<S20>/Logical Operator'
   *  Logic: '<S20>/Logical Operator1'
   *  Lookup: '<S34>/Look-Up Table'
   *  RelationalOperator: '<S20>/Relational Operator1'
   *  RelationalOperator: '<S20>/Relational Operator8'
   */
  AFAMgt_bIdcTiInjMinCnd = (((((!(rtu_InjrSys_prm_tiInj[0] > 0U)) ||
    (rtu_InjrSys_prm_tiInj[0] >= localLookUpTable[0])) &&
    ((!(rtu_InjrSys_prm_tiInj[1] > 0U)) || (rtu_InjrSys_prm_tiInj[1] >=
    localLookUpTable[1]))) && ((!(rtu_InjrSys_prm_tiInj[2] > 0U)) ||
    (rtu_InjrSys_prm_tiInj[2] >= localLookUpTable[2]))) &&
    ((!(rtu_InjrSys_prm_tiInj[3] > 0U)) || (rtu_InjrSys_prm_tiInj[3] >=
    localLookUpTable[3])));

  /* end of Outputs for SubSystem: '<S11>/F02_Injection_Timing_Conditions' */

  /* Logic: '<S11>/Logical Operator' */
  localLogicalOperator = ((AFAMgt_bIdcFacCorGainLnrCnd) &&
    (AFAMgt_bIdcTiInjMinCnd));

  /* end of Outputs for SubSystem: '<S1>/F09_Injector_Model_Correction_Condition' */

  /* Logic: '<S1>/Logical Operator1' */
  localLogicalOperator1_ix = (((((((((AFAMgt_bIdcEngCnd) && (AFAMgt_bIdcFARSpCnd))
    && (AFAMgt_bIdcTiDlyObsCnd)) && (AFAMgt_bIdcThermoCnd)) &&
    (AFAMgt_bIdcPresCnd)) && (AFAMgt_bIdcStabCnd)) && (AFAMgt_bIdcMassAirScvCnd))
    && (AFAMgt_bIdcDeltaLdInjPhaCnd)) && (*rtu_Blby_bIdcWoutBlbyCnd));

  /* Logic: '<S1>/Logical Operator2' */
  AFAMgt_bIdcTmpObsCndOk = ((localLogicalOperator1_ix) && (localLogicalOperator));

  /* SignalConversion: '<S1>/Signal Conversion' */
  (*rty_AFAMgt_bIdcTmpObs1) = localLogicalOperator1_ix;

  /* SignalConversion: '<S1>/Signal Conversion1' */
  (*rty_AFAMgt_bIdcInjrMdl1) = localLogicalOperator;

  /* end of Outputs for SubSystem: '<Root>/F01_calc_Tempo' */

  /* Outputs for atomic SubSystem: '<Root>/F02_Manager' *
   * Block requirements for '<Root>/F02_Manager':
   *  1. SubSystem "F02_Manager" !Trace_To : VEMS_R_11 _04434_070.01 ;
   */

  /* Stateflow: '<S2>/F01_command_observation_chart' incorporates:
   *  Constant: '<S2>/AFAMgt_tiDecAdpObsDft_C'
   *  Constant: '<S2>/AFAMgt_tiDlyCanPurgClsFast_C'
   *  Constant: '<S2>/AFAMgt_tiDlyCanPurgClsSlow_C'
   *  Constant: '<S2>/AFAMgt_tiIncAdpObsDft_C'
   *  Constant: '<S2>/AFAMgt_tiSampleSlow_SC'
   */
  /* Gateway: F02_Manager/F01_command_observation_chart */
  /* During: F02_Manager/F01_command_observation_chart */
  if (localDW->is_active_c8_AFAMgtT_F02_comman == 0) {
    /* Entry: F02_Manager/F01_command_observation_chart */
    localDW->is_active_c8_AFAMgtT_F02_comman = 1U;

    /* Transition: '<S35>:13' */
    /* Entry 'AttenteObservation': '<S35>:2' */
    localDW->is_c8_AFAMgtT_F02_command_obser = AFAMgtT_F_IN_AttenteObservation;
    localB->AFAMgt_bAuthAdpReq = FALSE;
    localB->AFAMgt_bAdpObsReq = FALSE;
    localDW->AFAMgt_tiCntCanPurgReqInh = (SInt32)(*rtu_AFAMgt_tiDlyLstObsThd);
  } else {
    switch (localDW->is_c8_AFAMgtT_F02_command_obser) {
     case AFAMgtT_F_IN_AttenteObservation:
      /* During 'AttenteObservation': '<S35>:2' */
      if (((((SInt32)AFAMgt_bIdcTmpObsCndOk) != 0) && (((SInt32)
             (*rtu_FRM_bInhAFAObsAdp)) == 0)) &&
          (localDW->AFAMgt_tiCntCanPurgReqInh <= 0)) {
        /* Transition: '<S35>:9' */
        if (((SInt32)(*rtu_AFA_bAuthClsCan1)) != 0) {
          /* Transition: '<S35>:7' */
          /* Exit 'AttenteObservation': '<S35>:2' */
          localDW->AFAMgt_tiCntCanPurgReqInh = (SInt32)
            AFAMgt_tiDlyCanPurgClsSlow_C;

          /* Entry 'Observation': '<S35>:4' */
          localDW->is_c8_AFAMgtT_F02_command_obser =
            AFAMgtT_F02_comm_IN_Observation;
          localB->AFAMgt_bAuthAdpReq = TRUE;

          /* Transition: '<S35>:19' */
          /* Entry 'PasObservation': '<S35>:1' */
          localDW->is_Observation = AFAMgtT_F02_c_IN_PasObservation;
          localB->AFAMgt_bAdpObsReq = FALSE;
        } else {
          /* Transition: '<S35>:21' */
          /* Transition: '<S35>:20' */
          /* Exit 'AttenteObservation': '<S35>:2' */
          localDW->AFAMgt_tiCntCanPurgReqInh = (SInt32)
            AFAMgt_tiDlyCanPurgClsFast_C;

          /* Entry 'Observation': '<S35>:4' */
          localDW->is_c8_AFAMgtT_F02_command_obser =
            AFAMgtT_F02_comm_IN_Observation;
          localB->AFAMgt_bAuthAdpReq = TRUE;

          /* Transition: '<S35>:19' */
          /* Entry 'PasObservation': '<S35>:1' */
          localDW->is_Observation = AFAMgtT_F02_c_IN_PasObservation;
          localB->AFAMgt_bAdpObsReq = FALSE;
        }
      } else {
        localDW->AFAMgt_tiCntCanPurgReqInh = localDW->AFAMgt_tiCntCanPurgReqInh
          - ((SInt32)((((UInt32)AFAMgt_tiSampleSlow_SC) * 52429U) >> 19U));
      }
      break;

     case AFAMgtT_F02_comm_IN_Observation:
      /* During 'Observation': '<S35>:4' */
      /* Transition: '<S35>:6' */
      if (localDW->AFAMgt_tiCntCanPurgReqInh <= 0) {
        /* Transition: '<S35>:12' */
        localDW->AFAMgt_ctAdpObsDft = (UInt8)rt_MIN
          (localDW->AFAMgt_ctAdpObsDft + AFAMgt_tiIncAdpObsDft_C, 255);
        if (localDW->AFAMgt_ctAdpObsDft == 255) {
          /* Transition: '<S35>:17' */
          (*rty_AFAMgt_bDgoObsAdp) = TRUE;
          (*rty_AFAMgt_bMonRunObsAdp) = TRUE;

          /* Exit 'DemandeObservation': '<S35>:3' */
          localDW->is_Observation = (UInt8)AFAMgtT_F02__IN_NO_ACTIVE_CHILD;

          /* Exit 'PasObservation': '<S35>:1' */
          /* Exit 'Observation': '<S35>:4' */
          /* Entry 'AttenteObservation': '<S35>:2' */
          localDW->is_c8_AFAMgtT_F02_command_obser =
            AFAMgtT_F_IN_AttenteObservation;
          localB->AFAMgt_bAuthAdpReq = FALSE;
          localB->AFAMgt_bAdpObsReq = FALSE;
          localDW->AFAMgt_tiCntCanPurgReqInh = (SInt32)
            (*rtu_AFAMgt_tiDlyLstObsThd);
        } else {
          /* Transition: '<S35>:10' */
          /* Transition: '<S35>:11' */
          /* Exit 'DemandeObservation': '<S35>:3' */
          localDW->is_Observation = (UInt8)AFAMgtT_F02__IN_NO_ACTIVE_CHILD;

          /* Exit 'PasObservation': '<S35>:1' */
          /* Exit 'Observation': '<S35>:4' */
          /* Entry 'AttenteObservation': '<S35>:2' */
          localDW->is_c8_AFAMgtT_F02_command_obser =
            AFAMgtT_F_IN_AttenteObservation;
          localB->AFAMgt_bAuthAdpReq = FALSE;
          localB->AFAMgt_bAdpObsReq = FALSE;
          localDW->AFAMgt_tiCntCanPurgReqInh = (SInt32)
            (*rtu_AFAMgt_tiDlyLstObsThd);
        }
      } else {
        /* Transition: '<S35>:8' */
        if ((*rtu_AFA_tiDlyLstObs) <= (*rtu_AFAMgt_tiDlyLstObsThd)) {
          /* Transition: '<S35>:5' */
          localDW->AFAMgt_ctAdpObsDft = (UInt8)rt_MAX
            (localDW->AFAMgt_ctAdpObsDft - AFAMgt_tiDecAdpObsDft_C, 0);
          if (localDW->AFAMgt_ctAdpObsDft == 0) {
            /* Transition: '<S35>:16' */
            (*rty_AFAMgt_bDgoObsAdp) = FALSE;
            (*rty_AFAMgt_bMonRunObsAdp) = TRUE;

            /* Exit 'DemandeObservation': '<S35>:3' */
            localDW->is_Observation = (UInt8)AFAMgtT_F02__IN_NO_ACTIVE_CHILD;

            /* Exit 'PasObservation': '<S35>:1' */
            /* Exit 'Observation': '<S35>:4' */
            /* Entry 'AttenteObservation': '<S35>:2' */
            localDW->is_c8_AFAMgtT_F02_command_obser =
              AFAMgtT_F_IN_AttenteObservation;
            localB->AFAMgt_bAuthAdpReq = FALSE;
            localB->AFAMgt_bAdpObsReq = FALSE;
            localDW->AFAMgt_tiCntCanPurgReqInh = (SInt32)
              (*rtu_AFAMgt_tiDlyLstObsThd);
          } else {
            /* Transition: '<S35>:15' */
            /* Transition: '<S35>:14' */
            /* Exit 'DemandeObservation': '<S35>:3' */
            localDW->is_Observation = (UInt8)AFAMgtT_F02__IN_NO_ACTIVE_CHILD;

            /* Exit 'PasObservation': '<S35>:1' */
            /* Exit 'Observation': '<S35>:4' */
            /* Entry 'AttenteObservation': '<S35>:2' */
            localDW->is_c8_AFAMgtT_F02_command_obser =
              AFAMgtT_F_IN_AttenteObservation;
            localB->AFAMgt_bAuthAdpReq = FALSE;
            localB->AFAMgt_bAdpObsReq = FALSE;
            localDW->AFAMgt_tiCntCanPurgReqInh = (SInt32)
              (*rtu_AFAMgt_tiDlyLstObsThd);
          }
        } else {
          localDW->AFAMgt_tiCntCanPurgReqInh =
            localDW->AFAMgt_tiCntCanPurgReqInh - ((SInt32)((((UInt32)
            AFAMgt_tiSampleSlow_SC) * 52429U) >> 19U));
          switch (localDW->is_Observation) {
           case AFAMgtT_F_IN_DemandeObservation:
            /* During 'DemandeObservation': '<S35>:3' */
            if (((((SInt32)AFAMgt_bIdcTmpObsCndOk) == 0) || (((SInt32)
                   (*rtu_AFAMgt_bIdcStabAirMod)) == 0)) || (((SInt32)
                  (*rtu_GSM_bAcvAFAAdp)) == 0)) {
              /* Transition: '<S35>:18' */
              /* Exit 'DemandeObservation': '<S35>:3' */
              /* Entry 'PasObservation': '<S35>:1' */
              localDW->is_Observation = AFAMgtT_F02_c_IN_PasObservation;
              localB->AFAMgt_bAdpObsReq = FALSE;
            }
            break;

           case AFAMgtT_F02_c_IN_PasObservation:
            /* During 'PasObservation': '<S35>:1' */
            if (((((SInt32)AFAMgt_bIdcTmpObsCndOk) != 0) && (((SInt32)
                   (*rtu_AFAMgt_bIdcStabAirMod)) != 0)) && (((SInt32)
                  (*rtu_GSM_bAcvAFAAdp)) != 0)) {
              /* Transition: '<S35>:22' */
              /* Exit 'PasObservation': '<S35>:1' */
              /* Entry 'DemandeObservation': '<S35>:3' */
              localDW->is_Observation = AFAMgtT_F_IN_DemandeObservation;
              localB->AFAMgt_bAdpObsReq = TRUE;
            }
            break;

           default:
            /* Transition: '<S35>:19' */
            /* Entry 'PasObservation': '<S35>:1' */
            localDW->is_Observation = AFAMgtT_F02_c_IN_PasObservation;
            localB->AFAMgt_bAdpObsReq = FALSE;
            break;
          }
        }
      }
      break;

     default:
      /* Transition: '<S35>:13' */
      /* Entry 'AttenteObservation': '<S35>:2' */
      localDW->is_c8_AFAMgtT_F02_command_obser = AFAMgtT_F_IN_AttenteObservation;
      localB->AFAMgt_bAuthAdpReq = FALSE;
      localB->AFAMgt_bAdpObsReq = FALSE;
      localDW->AFAMgt_tiCntCanPurgReqInh = (SInt32)(*rtu_AFAMgt_tiDlyLstObsThd);
      break;
    }
  }

  /* SignalConversion: '<S2>/Signal Conversion' */
  (*rty_AFAMgt_bAuthAdp1) = localB->AFAMgt_bAuthAdpReq;

  /* SignalConversion: '<S2>/Signal Conversion1' */
  (*rty_AFAMgt_bAdpObs1) = localB->AFAMgt_bAdpObsReq;

  /* end of Outputs for SubSystem: '<Root>/F02_Manager' */
}

/* Model initialize function */
void mr_AFAMgtT_F02_comma_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
