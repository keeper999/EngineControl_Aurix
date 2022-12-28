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
/* !File            : AFA_F04_command_adaptation_parameters.c                 */
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
/*   Model name       : AFA_F04_command_adaptation_parameters.mdl             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F04_command_adaptation_parameters.h"
#include "AFA_F04_command_adaptation_parameters_private.h"
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
Boolean AFA_bAcvAdpVlvExOfs;         /* '<S3>/Logical Operator36' */
Boolean AFA_bAcvAdpVlvInOfs;         /* '<S2>/Logical Operator33' */
Boolean AFA_bAcvAdpDlyLsclCnd;       /* '<S1>/Logical Operator25' */
Boolean AFA_bAcvAdpThrCnd;           /* '<S1>/Logical Operator26' */

/* Exported block states */
Boolean AFA_prm_bMaskSenMat1_MP[2];  /* '<S4>/Data Store Memory' */
Boolean AFA_prm_bMaskSenMat2_MP[2];  /* '<S4>/Data Store Memory1' */
Boolean AFA_prm_bMaskSenMat3_MP[2];  /* '<S4>/Data Store Memory2' */
Boolean AFA_prm_bMaskSenMat4_MP[2];  /* '<S4>/Data Store Memory3' */
Boolean AFA_prm_bMaskSenMat5_MP[2];  /* '<S4>/Data Store Memory4' */
Boolean AFA_prm_bMaskSenMat6_MP[2];  /* '<S4>/Data Store Memory5' */
Boolean AFA_prm_bMaskSenMat7_MP[2];  /* '<S4>/Data Store Memory6' */
Boolean AFA_prm_bMaskSenMat8_MP[2];  /* '<S4>/Data Store Memory7' */

#define AFAT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F04_command_adaptation_parameters' */
void mr_AFA_F04_command_adaptation_p(const UInt16 *rtu_AFA_noAdpEfc, const
  UInt16 *rtu_ThrLrn_rOpSI, const UInt8 *rtu_InjSys_noTDCDlyLsclFilMod,
  const UInt16 *rtu_Ext_nEng, const UInt16 *rtu_EngM_rTotLdExCor, Boolean
  rty_AFA_prm_bMaskSenMat_PIM[16])
{
  /* local block i/o variables */
  UInt8 localLookUpTable2D;
  UInt8 localLookUpTable2D_a;
  Boolean localLogicalOperator34;
  Boolean localSwitch19;
  Boolean locallocalMatrixConcatenation1_;
  Boolean locallocalMatrixConcatenation_0;
  Boolean locallocalMatrixConcatenation3_;
  Boolean locallocalMatrixConcatenation_1;
  Boolean locallocalMatrixConcatenation4_;
  Boolean locallocalMatrixConcatenation_2;
  Boolean locallocalMatrixConcatenation2_;
  Boolean locallocalMatrixConcatenation_3;
  Boolean locallocalMatrixConcatenation5_;
  Boolean locallocalMatrixConcatenation_4;
  Boolean locallocalMatrixConcatenation7_;
  Boolean locallocalMatrixConcatenation_5;
  Boolean locallocalMatrixConcatenation6_;
  Boolean locallocalMatrixConcatenation_6;
  Boolean locallocalMatrixConcatenation8_;

  /* Outputs for atomic SubSystem: '<Root>/F01_Mask_Activation_Conditions' *
   * Block requirements for '<Root>/F01_Mask_Activation_Conditions':
   *  1. SubSystem "F01_Mask_Activation_Conditions" !Trace_To : VEMS_R_11_04467_027.01 ;
   */

  /* Logic: '<S1>/Logical Operator34' incorporates:
   *  Constant: '<S1>/AFA_bInhMaskSen_C'
   */
  localLogicalOperator34 = !AFA_bInhMaskSen_C;

  /* Logic: '<S1>/Logical Operator25' incorporates:
   *  Constant: '<S1>/Constant13'
   *  RelationalOperator: '<S1>/Relational Operator1'
   */
  AFA_bAcvAdpDlyLsclCnd = (((*rtu_InjSys_noTDCDlyLsclFilMod) != 0) ||
    (localLogicalOperator34));

  /* Logic: '<S1>/Logical Operator26' incorporates:
   *  Constant: '<S1>/AFA_rOpThrMax_C'
   *  RelationalOperator: '<S1>/Relational Operator'
   */
  AFA_bAcvAdpThrCnd = ((localLogicalOperator34) || ((*rtu_ThrLrn_rOpSI) <
    AFA_rOpThrMax_C));

  /* end of Outputs for SubSystem: '<Root>/F01_Mask_Activation_Conditions' */

  /* Outputs for atomic SubSystem: '<Root>/F02_Adpatation_Intake_Valve_Activation_Conditions' *
   * Block requirements for '<Root>/F02_Adpatation_Intake_Valve_Activation_Conditions':
   *  1. SubSystem "F02_Adpatation_Intake_Valve_Activation_Conditions" !Trace_To : VEMS_R_11_04467_028.01 ;
   */

  /* Lookup2D: '<S5>/Look-Up Table (2-D)'
   * About '<S5>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-14
   * Output0 Data Type:  Integer        U8
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U8_U16_U16( &(localLookUpTable2D_a), (&(AFA_bInVlvAdp_M[0])),
                    (*rtu_Ext_nEng), (&(Ext_nEng_A[0])), 15U,
                    (*rtu_EngM_rTotLdExCor), (&(Eng_rAirLd_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S5>/Data Type Duplicate2'
   *
   * Regarding '<S5>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* Logic: '<S2>/Logical Operator33' incorporates:
   *  Constant: '<S2>/AFA_bInhAdpVlvInOfs_C'
   *  Constant: '<S2>/AFA_noAdpEfcThd_C'
   *  Constant: '<S2>/Eng_bInVlvCf_SC'
   *  DataTypeConversion: '<S2>/Data Type Conversion32'
   *  Inport: '<Root>/EngM_rTotLdExCor'
   *  Inport: '<Root>/Ext_nEng'
   *  Logic: '<S2>/Logical Operator30'
   *  Logic: '<S2>/Logical Operator31'
   *  Logic: '<S2>/Logical Operator32'
   *  Lookup2D: '<S5>/Look-Up Table (2-D)'
   *  RelationalOperator: '<S2>/Relational Operator2'
   */
  AFA_bAcvAdpVlvInOfs = ((((*rtu_AFA_noAdpEfc) <= AFA_noAdpEfcThd_C) &&
    (localLookUpTable2D_a != 0)) && ((!AFA_bInhAdpVlvInOfs_C) && Eng_bInVlvCf_SC));

  /* end of Outputs for SubSystem: '<Root>/F02_Adpatation_Intake_Valve_Activation_Conditions' */

  /* Outputs for atomic SubSystem: '<Root>/F03_Adpatation_Exhaust_Valve_Activation_Conditions' *
   * Block requirements for '<Root>/F03_Adpatation_Exhaust_Valve_Activation_Conditions':
   *  1. SubSystem "F03_Adpatation_Exhaust_Valve_Activation_Conditions" !Trace_To : VEMS_R_11_04467_029.01 ;
   */

  /* Lookup2D: '<S6>/Look-Up Table (2-D)'
   * About '<S6>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-14
   * Output0 Data Type:  Integer        U8
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U8_U16_U16( &(localLookUpTable2D), (&(AFA_bExVlvAdp_M[0])),
                    (*rtu_Ext_nEng), (&(Ext_nEng_A[0])), 15U,
                    (*rtu_EngM_rTotLdExCor), (&(Eng_rAirLd_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S6>/Data Type Duplicate2'
   *
   * Regarding '<S6>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* Logic: '<S3>/Logical Operator36' incorporates:
   *  Constant: '<S3>/AFA_bInhAdpVlvExOfs_C'
   *  Constant: '<S3>/AFA_noAdpEfcThd_C'
   *  Constant: '<S3>/Eng_bExVlvCf_SC'
   *  DataTypeConversion: '<S3>/Data Type Conversion32'
   *  Inport: '<Root>/EngM_rTotLdExCor'
   *  Inport: '<Root>/Ext_nEng'
   *  Logic: '<S3>/Logical Operator27'
   *  Logic: '<S3>/Logical Operator28'
   *  Logic: '<S3>/Logical Operator35'
   *  Lookup2D: '<S6>/Look-Up Table (2-D)'
   *  RelationalOperator: '<S3>/Relational Operator4'
   */
  AFA_bAcvAdpVlvExOfs = ((((*rtu_AFA_noAdpEfc) <= AFA_noAdpEfcThd_C) &&
    (localLookUpTable2D != 0)) && ((!AFA_bInhAdpVlvExOfs_C) && Eng_bExVlvCf_SC));

  /* end of Outputs for SubSystem: '<Root>/F03_Adpatation_Exhaust_Valve_Activation_Conditions' */

  /* Outputs for atomic SubSystem: '<Root>/F04_Calc_Mask_Sensibility' *
   * Block requirements for '<Root>/F04_Calc_Mask_Sensibility':
   *  1. SubSystem "F04_Calc_Mask_Sensibility" !Trace_To : VEMS_R_11_04467_030.01 ;
   */

  /* Logic: '<S4>/Logical Operator24' incorporates:
   *  Constant: '<S4>/AFA_bInhAdpIvsInjGain_C1'
   */
  localLogicalOperator34 = !AFA_bInhAdpIvsInjGain_C;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/AFA_bAcvVVTAdp_C2'
   */
  if (AFA_bAcvVVTAdp_C) {
    localSwitch19 = AFA_bAcvAdpVlvInOfs;
  } else {
    localSwitch19 = localLogicalOperator34;
  }

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant19'
   *  Logic: '<S4>/Logical Operator3'
   */
  if ((AFA_bAcvAdpThrCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation1_ = TRUE;
  } else {
    locallocalMatrixConcatenation1_ = FALSE;
  }

  /* Switch: '<S4>/Switch3' incorporates:
   *  Constant: '<S4>/Constant21'
   *  Constant: '<S4>/Constant23'
   *  Logic: '<S4>/Logical Operator9'
   */
  if ((AFA_bAcvAdpDlyLsclCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation_0 = TRUE;
  } else {
    locallocalMatrixConcatenation_0 = FALSE;
  }

  /* DataStoreWrite: '<S4>/Data Store Write' */
  AFA_prm_bMaskSenMat1_MP[0] = locallocalMatrixConcatenation1_;
  AFA_prm_bMaskSenMat1_MP[1] = locallocalMatrixConcatenation_0;

  /* Logic: '<S4>/Logical Operator23' incorporates:
   *  Constant: '<S4>/AFA_bInhAdpInjOfs_C'
   */
  localSwitch19 = !AFA_bInhAdpInjOfs_C;

  /* Switch: '<S4>/Switch4' incorporates:
   *  Constant: '<S4>/Constant24'
   *  Constant: '<S4>/Constant25'
   *  Logic: '<S4>/Logical Operator2'
   */
  if ((AFA_bAcvAdpThrCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation3_ = TRUE;
  } else {
    locallocalMatrixConcatenation3_ = FALSE;
  }

  /* Switch: '<S4>/Switch5' incorporates:
   *  Constant: '<S4>/Constant26'
   *  Constant: '<S4>/Constant27'
   *  Logic: '<S4>/Logical Operator10'
   */
  if ((AFA_bAcvAdpDlyLsclCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation_1 = TRUE;
  } else {
    locallocalMatrixConcatenation_1 = FALSE;
  }

  /* DataStoreWrite: '<S4>/Data Store Write1' */
  AFA_prm_bMaskSenMat2_MP[0] = locallocalMatrixConcatenation3_;
  AFA_prm_bMaskSenMat2_MP[1] = locallocalMatrixConcatenation_1;

  /* Switch: '<S4>/Switch18' incorporates:
   *  Constant: '<S4>/AFA_bAcvVVTAdp_C'
   *  Constant: '<S4>/AFA_bInhAdp_pDsThr_C'
   *  Constant: '<S4>/AFA_bSelAdpTyp_C'
   *  Logic: '<S4>/Logical Operator18'
   *  Logic: '<S4>/Logical Operator25'
   */
  if (!(AFA_bSelAdpTyp_C && AFA_bAcvVVTAdp_C)) {
    localLogicalOperator34 = !AFA_bInhAdp_pDsThr_C;
  }

  /* Switch: '<S4>/Switch6' incorporates:
   *  Constant: '<S4>/Constant28'
   *  Constant: '<S4>/Constant29'
   *  Logic: '<S4>/Logical Operator1'
   */
  if ((AFA_bAcvAdpThrCnd) && (localLogicalOperator34)) {
    locallocalMatrixConcatenation4_ = TRUE;
  } else {
    locallocalMatrixConcatenation4_ = FALSE;
  }

  /* Switch: '<S4>/Switch7' incorporates:
   *  Constant: '<S4>/Constant30'
   *  Constant: '<S4>/Constant31'
   *  Logic: '<S4>/Logical Operator11'
   */
  if ((AFA_bAcvAdpDlyLsclCnd) && (localLogicalOperator34)) {
    locallocalMatrixConcatenation_2 = TRUE;
  } else {
    locallocalMatrixConcatenation_2 = FALSE;
  }

  /* DataStoreWrite: '<S4>/Data Store Write2' */
  AFA_prm_bMaskSenMat3_MP[0] = locallocalMatrixConcatenation4_;
  AFA_prm_bMaskSenMat3_MP[1] = locallocalMatrixConcatenation_2;

  /* Logic: '<S4>/Logical Operator19' incorporates:
   *  Constant: '<S4>/AFA_bInhAdpArEffTot_C'
   */
  localSwitch19 = !AFA_bInhAdpArEffTot_C;

  /* Switch: '<S4>/Switch8' incorporates:
   *  Constant: '<S4>/Constant32'
   *  Constant: '<S4>/Constant33'
   *  Logic: '<S4>/Logical Operator4'
   */
  if ((AFA_bAcvAdpThrCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation2_ = TRUE;
  } else {
    locallocalMatrixConcatenation2_ = FALSE;
  }

  /* Switch: '<S4>/Switch9' incorporates:
   *  Constant: '<S4>/Constant34'
   *  Constant: '<S4>/Constant35'
   *  Logic: '<S4>/Logical Operator12'
   */
  if ((AFA_bAcvAdpDlyLsclCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation_3 = TRUE;
  } else {
    locallocalMatrixConcatenation_3 = FALSE;
  }

  /* DataStoreWrite: '<S4>/Data Store Write3' */
  AFA_prm_bMaskSenMat4_MP[0] = locallocalMatrixConcatenation2_;
  AFA_prm_bMaskSenMat4_MP[1] = locallocalMatrixConcatenation_3;

  /* Logic: '<S4>/Logical Operator20' incorporates:
   *  Constant: '<S4>/AFA_bInhAdpFacArEffThrOfs1_C'
   */
  localSwitch19 = !AFA_bInhAdpFacArEffThrOfs1_C;

  /* Switch: '<S4>/Switch10' incorporates:
   *  Constant: '<S4>/Constant36'
   *  Constant: '<S4>/Constant37'
   *  Logic: '<S4>/Logical Operator5'
   */
  if ((AFA_bAcvAdpThrCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation5_ = TRUE;
  } else {
    locallocalMatrixConcatenation5_ = FALSE;
  }

  /* Switch: '<S4>/Switch11' incorporates:
   *  Constant: '<S4>/Constant38'
   *  Constant: '<S4>/Constant39'
   *  Logic: '<S4>/Logical Operator13'
   */
  if ((AFA_bAcvAdpDlyLsclCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation_4 = TRUE;
  } else {
    locallocalMatrixConcatenation_4 = FALSE;
  }

  /* DataStoreWrite: '<S4>/Data Store Write4' */
  AFA_prm_bMaskSenMat5_MP[0] = locallocalMatrixConcatenation5_;
  AFA_prm_bMaskSenMat5_MP[1] = locallocalMatrixConcatenation_4;

  /* Logic: '<S4>/Logical Operator21' incorporates:
   *  Constant: '<S4>/AFA_bInhAdpFacArEffThrOfs2_C'
   */
  localSwitch19 = !AFA_bInhAdpFacArEffThrOfs2_C;

  /* Switch: '<S4>/Switch12' incorporates:
   *  Constant: '<S4>/Constant40'
   *  Constant: '<S4>/Constant41'
   *  Logic: '<S4>/Logical Operator6'
   */
  if ((AFA_bAcvAdpThrCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation7_ = TRUE;
  } else {
    locallocalMatrixConcatenation7_ = FALSE;
  }

  /* Switch: '<S4>/Switch13' incorporates:
   *  Constant: '<S4>/Constant42'
   *  Constant: '<S4>/Constant43'
   *  Logic: '<S4>/Logical Operator14'
   */
  if ((AFA_bAcvAdpDlyLsclCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation_5 = TRUE;
  } else {
    locallocalMatrixConcatenation_5 = FALSE;
  }

  /* DataStoreWrite: '<S4>/Data Store Write5' */
  AFA_prm_bMaskSenMat6_MP[0] = locallocalMatrixConcatenation7_;
  AFA_prm_bMaskSenMat6_MP[1] = locallocalMatrixConcatenation_5;

  /* Logic: '<S4>/Logical Operator22' incorporates:
   *  Constant: '<S4>/AFA_bInhAdpFacArEffThrOfs3_C'
   */
  localSwitch19 = !AFA_bInhAdpFacArEffThrOfs3_C;

  /* Switch: '<S4>/Switch14' incorporates:
   *  Constant: '<S4>/Constant44'
   *  Constant: '<S4>/Constant45'
   *  Logic: '<S4>/Logical Operator7'
   */
  if ((AFA_bAcvAdpThrCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation6_ = TRUE;
  } else {
    locallocalMatrixConcatenation6_ = FALSE;
  }

  /* Switch: '<S4>/Switch15' incorporates:
   *  Constant: '<S4>/Constant46'
   *  Constant: '<S4>/Constant47'
   *  Logic: '<S4>/Logical Operator15'
   */
  if ((AFA_bAcvAdpDlyLsclCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation_6 = TRUE;
  } else {
    locallocalMatrixConcatenation_6 = FALSE;
  }

  /* DataStoreWrite: '<S4>/Data Store Write6' */
  AFA_prm_bMaskSenMat7_MP[0] = locallocalMatrixConcatenation6_;
  AFA_prm_bMaskSenMat7_MP[1] = locallocalMatrixConcatenation_6;

  /* Switch: '<S4>/Switch20' incorporates:
   *  Constant: '<S4>/AFA_bInhAdpIvsInjGain_C'
   *  Constant: '<S4>/Eng_bEGRVlvCf_SC'
   *  Constant: '<S4>/Eng_bExVlvCf_SC'
   *  Logic: '<S4>/Logical Operator26'
   *  Logic: '<S4>/Logical Operator27'
   */
  if (Eng_bExVlvCf_SC || Eng_bEGRVlvCf_SC) {
    /* Switch: '<S4>/Switch19' incorporates:
     *  Constant: '<S4>/AFA_bAcvVVTAdp_C1'
     *  Constant: '<S4>/AFA_bInhAdpArEffEGROfs_C'
     *  Constant: '<S4>/Eng_bEGRVlvCf_SC1'
     *  Logic: '<S4>/Logical Operator17'
     *  Logic: '<S4>/Logical Operator29'
     */
    if (AFA_bAcvVVTAdp_C) {
      localSwitch19 = AFA_bAcvAdpVlvExOfs;
    } else {
      localSwitch19 = ((!AFA_bInhAdpArEffEGROfs_C) && Eng_bEGRVlvCf_SC);
    }
  } else {
    localSwitch19 = !AFA_bInhAdpIvsInjGain_C;
  }

  /* Switch: '<S4>/Switch16' incorporates:
   *  Constant: '<S4>/Constant48'
   *  Constant: '<S4>/Constant49'
   *  Logic: '<S4>/Logical Operator8'
   */
  if ((AFA_bAcvAdpThrCnd) && (localSwitch19)) {
    locallocalMatrixConcatenation8_ = TRUE;
  } else {
    locallocalMatrixConcatenation8_ = FALSE;
  }

  /* Switch: '<S4>/Switch17' incorporates:
   *  Constant: '<S4>/Constant50'
   *  Constant: '<S4>/Constant51'
   *  Logic: '<S4>/Logical Operator16'
   */
  if ((AFA_bAcvAdpDlyLsclCnd) && (localSwitch19)) {
    localLogicalOperator34 = TRUE;
  } else {
    localLogicalOperator34 = FALSE;
  }

  /* DataStoreWrite: '<S4>/Data Store Write7' */
  AFA_prm_bMaskSenMat8_MP[0] = locallocalMatrixConcatenation8_;
  AFA_prm_bMaskSenMat8_MP[1] = localLogicalOperator34;

  /* Concatenate: '<S4>/Matrix Concatenation9' */
  rty_AFA_prm_bMaskSenMat_PIM[0] = locallocalMatrixConcatenation1_;
  rty_AFA_prm_bMaskSenMat_PIM[8] = locallocalMatrixConcatenation_0;
  rty_AFA_prm_bMaskSenMat_PIM[1] = locallocalMatrixConcatenation3_;
  rty_AFA_prm_bMaskSenMat_PIM[9] = locallocalMatrixConcatenation_1;
  rty_AFA_prm_bMaskSenMat_PIM[2] = locallocalMatrixConcatenation4_;
  rty_AFA_prm_bMaskSenMat_PIM[10] = locallocalMatrixConcatenation_2;
  rty_AFA_prm_bMaskSenMat_PIM[3] = locallocalMatrixConcatenation2_;
  rty_AFA_prm_bMaskSenMat_PIM[11] = locallocalMatrixConcatenation_3;
  rty_AFA_prm_bMaskSenMat_PIM[4] = locallocalMatrixConcatenation5_;
  rty_AFA_prm_bMaskSenMat_PIM[12] = locallocalMatrixConcatenation_4;
  rty_AFA_prm_bMaskSenMat_PIM[5] = locallocalMatrixConcatenation7_;
  rty_AFA_prm_bMaskSenMat_PIM[13] = locallocalMatrixConcatenation_5;
  rty_AFA_prm_bMaskSenMat_PIM[6] = locallocalMatrixConcatenation6_;
  rty_AFA_prm_bMaskSenMat_PIM[14] = locallocalMatrixConcatenation_6;
  rty_AFA_prm_bMaskSenMat_PIM[7] = locallocalMatrixConcatenation8_;
  rty_AFA_prm_bMaskSenMat_PIM[15] = localLogicalOperator34;

  /* end of Outputs for SubSystem: '<Root>/F04_Calc_Mask_Sensibility' */
}

/* Model initialize function */
void mr_AFA_F04_command_a_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
