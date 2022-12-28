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
/* !File            : AFA_F01_scruter_environ_adaptation.c                    */
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
/*   Model name       : AFA_F01_scruter_environ_adaptation.mdl                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   20 Feb 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_scruter_environ_adaptation.h"
#include "AFA_F01_scruter_environ_adaptation_private.h"
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

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F01_scruter_environ_adaptation' */
void mr_AFA_F01_scruter_environ_adap(const UInt16 *rtu_ThrLrn_1_rOpClsThrBol,
  const UInt16 *rtu_UsThrM_1_pAirExtEstim, const UInt32
  *rtu_EGRVlv_1_rOpClsEGRVlvBol, const UInt16 rtu_VlvAct_1_prm_agCkOpInVlvBol
  [4], const UInt16 rtu_VlvAct_1_prm_agCkClsExVlvBo[4], const UInt16
  *rtu_AFA_1_rOpClsThrBolPrev, const UInt16 *rtu_AFA_1_pAirExtEstimPrev, const
  UInt16 *rtu_AFA_1_rOpClsEGRVlvBolPrev, const UInt16
  *rtu_AFA_1_agCkOpInVlvBolPrev, const UInt16 *rtu_AFA_1_agCkClsExVlvBolPrev,
  const Boolean *rtu_AFA_bFitPresAirExtPrev, const Boolean
  *rtu_AFA_bFitZeroPosnThrPrev, const Boolean *rtu_AFA_bClsEGRRefPrev, const
  Boolean *rtu_AFA_bFitOpInVlvBolPrev, const Boolean
  *rtu_AFA_bFitClsExVlvBolPrev, Boolean *rty_AFA_bClsEGRR1, Boolean
  *rty_AFA_bFitPresAirE1, Boolean *rty_AFA_bFitZeroPosnT1, Boolean
  *rty_AFA_bFitOpInVlvB1, Boolean *rty_AFA_bFitClsExVlvB1, UInt16
  *rty_AFA_rOpClsThrB1, UInt16 *rty_AFA_pAirExtEstimH1, UInt16
  *rty_AFA_rOpClsEGRVlvBolH1, UInt16 *rty_AFA_agCkOpInVlvBolH1, UInt16
  *rty_AFA_agCkClsExVlvBolH1)
{
  SInt32 localAbs4;
  UInt32 localtmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  localtmp = ((*rtu_EGRVlv_1_rOpClsEGRVlvBol) >> 6);
  if (localtmp > 65535U) {
    (*rty_AFA_rOpClsEGRVlvBolH1) = MAX_uint16_T;
  } else {
    (*rty_AFA_rOpClsEGRVlvBolH1) = (UInt16)localtmp;
  }

  /* If: '<Root>/If2' incorporates:
   *  Abs: '<Root>/Abs2'
   *  ActionPort: '<S5>/Action Port'
   *  ActionPort: '<S6>/Action Port'
   *  Constant: '<Root>/AFA_rOpClsEGRVlvDeltaMinThd_C'
   *  RelationalOperator: '<Root>/Relational Operator2'
   *  SignalConversion: '<Root>/Signal Conversion7'
   *  SubSystem: '<Root>/F03_rOpClsEGRVlvDelta'
   *  SubSystem: '<Root>/F03_rOpClsEGRVlvDelta1'
   *  Sum: '<Root>/Subtract2'
   *
   * Block requirements for '<Root>/F03_rOpClsEGRVlvDelta':
   *  1. SubSystem "F03_rOpClsEGRVlvDelta" !Trace_To : VEMS_R_11_04467_043.01 ;
   */
  if (ACTEMS_FabsF((((Float32)(*rtu_EGRVlv_1_rOpClsEGRVlvBol)) *
                    1.525878906E-005F) - (((Float32)
         (*rtu_AFA_1_rOpClsEGRVlvBolPrev)) * 0.0009765625F)) > (((Float32)
        AFA_rOpClsEGRVlvDeltaMinThd_C) * 1.525878906E-005F)) {
    /* Constant: '<S5>/Bool' */
    (*rty_AFA_bClsEGRR1) = TRUE;
  } else {
    /* SignalConversion: '<S6>/Signal Conversion' */
    (*rty_AFA_bClsEGRR1) = (*rtu_AFA_bClsEGRRefPrev);
  }

  /* Sum: '<Root>/Subtract1' incorporates:
   *  SignalConversion: '<Root>/Signal Conversion5'
   */
  localAbs4 = (*rtu_UsThrM_1_pAirExtEstim) - (*rtu_AFA_1_pAirExtEstimPrev);

  /* Abs: '<Root>/Abs1' */
  if (localAbs4 < 0) {
    localAbs4 = -localAbs4;
  }

  /* If: '<Root>/If5' incorporates:
   *  ActionPort: '<S1>/Action Port'
   *  ActionPort: '<S2>/Action Port'
   *  Constant: '<Root>/AFA_pAirExtDeltaMinThd_C'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  SubSystem: '<Root>/F01_pAirExtDelta'
   *  SubSystem: '<Root>/F01_pAirExtDelta1'
   *
   * Block requirements for '<Root>/F01_pAirExtDelta':
   *  1. SubSystem "F01_pAirExtDelta" !Trace_To : VEMS_R_11_04467_041.01 ;
   */
  if (localAbs4 > AFA_pAirExtDeltaMinThd_C) {
    /* Constant: '<S1>/Bool' */
    (*rty_AFA_bFitPresAirE1) = TRUE;
  } else {
    /* SignalConversion: '<S2>/Signal Conversion' */
    (*rty_AFA_bFitPresAirE1) = (*rtu_AFA_bFitPresAirExtPrev);
  }

  /* SignalConversion: '<Root>/Signal5' incorporates:
   *  SignalConversion: '<Root>/Signal Conversion1'
   */
  (*rty_AFA_pAirExtEstimH1) = (*rtu_UsThrM_1_pAirExtEstim);

  /* Sum: '<Root>/Subtract' incorporates:
   *  SignalConversion: '<Root>/Signal Conversion6'
   */
  localAbs4 = (*rtu_ThrLrn_1_rOpClsThrBol) - (*rtu_AFA_1_rOpClsThrBolPrev);

  /* Abs: '<Root>/Abs' */
  if (localAbs4 < 0) {
    localAbs4 = -localAbs4;
  }

  /* If: '<Root>/If1' incorporates:
   *  ActionPort: '<S3>/Action Port'
   *  ActionPort: '<S4>/Action Port'
   *  Constant: '<Root>/AFA_rOpClsThrRawDeltaThd_C'
   *  RelationalOperator: '<Root>/Relational Operator1'
   *  SubSystem: '<Root>/F02_rOpClsThrRawDelta'
   *  SubSystem: '<Root>/F02_rOpClsThrRawDelta1'
   *
   * Block requirements for '<Root>/F02_rOpClsThrRawDelta':
   *  1. SubSystem "F02_rOpClsThrRawDelta" !Trace_To : VEMS_R_11_04467_042.01 ;
   */
  if (localAbs4 > AFA_rOpClsThrRawDeltaThd_C) {
    /* Constant: '<S3>/Bool' */
    (*rty_AFA_bFitZeroPosnT1) = TRUE;
  } else {
    /* SignalConversion: '<S4>/Signal Conversion' */
    (*rty_AFA_bFitZeroPosnT1) = (*rtu_AFA_bFitZeroPosnThrPrev);
  }

  /* SignalConversion: '<Root>/Signal4' incorporates:
   *  SignalConversion: '<Root>/Signal Conversion2'
   */
  (*rty_AFA_rOpClsThrB1) = (*rtu_ThrLrn_1_rOpClsThrBol);

  /* Sum: '<Root>/Subtract3' incorporates:
   *  SignalConversion: '<Root>/Signal Conversion8'
   */
  localAbs4 = rtu_VlvAct_1_prm_agCkOpInVlvBol[0] -
    (*rtu_AFA_1_agCkOpInVlvBolPrev);

  /* Abs: '<Root>/Abs3' */
  if (localAbs4 < 0) {
    localAbs4 = -localAbs4;
  }

  /* If: '<Root>/If6' incorporates:
   *  ActionPort: '<S7>/Action Port'
   *  ActionPort: '<S8>/Action Port'
   *  Constant: '<Root>/AFA_agCkOpInVlvBolDelta_C'
   *  RelationalOperator: '<Root>/Relational Operator3'
   *  SubSystem: '<Root>/F04_agCkOpInVlvBolDelta'
   *  SubSystem: '<Root>/F04_agCkOpInVlvBolDelta1'
   *
   * Block requirements for '<Root>/F04_agCkOpInVlvBolDelta':
   *  1. SubSystem "F04_agCkOpInVlvBolDelta" !Trace_To : VEMS_R_11_04467_044.01 ;
   */
  localtmp = (UInt32)(AFA_agCkOpInVlvBolDelta_C * 3);
  if (localAbs4 > ((SInt32)((UInt32)((((UInt32)(((SInt32)localtmp) & 1))
          != 0U) + ((SInt32)(((UInt32)((SInt32)localtmp)) >> 1)))))) {
    /* Constant: '<S7>/Bool' */
    (*rty_AFA_bFitOpInVlvB1) = TRUE;
  } else {
    /* SignalConversion: '<S8>/Signal Conversion' */
    (*rty_AFA_bFitOpInVlvB1) = (*rtu_AFA_bFitOpInVlvBolPrev);
  }

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_agCkOpInVlvBolH1) = rtu_VlvAct_1_prm_agCkOpInVlvBol[0];

  /* Sum: '<Root>/Subtract4' incorporates:
   *  SignalConversion: '<Root>/Signal Conversion9'
   */
  localAbs4 = rtu_VlvAct_1_prm_agCkClsExVlvBo[0] -
    (*rtu_AFA_1_agCkClsExVlvBolPrev);

  /* Abs: '<Root>/Abs4' */
  if (localAbs4 < 0) {
    localAbs4 = -localAbs4;
  }

  /* If: '<Root>/If3' incorporates:
   *  ActionPort: '<S10>/Action Port'
   *  ActionPort: '<S9>/Action Port'
   *  Constant: '<Root>/AFA_agCkClsExVlvBolDelta_C'
   *  RelationalOperator: '<Root>/Relational Operator4'
   *  SubSystem: '<Root>/F05_agCkClsExVlvBolDelta'
   *  SubSystem: '<Root>/F05_agCkClsExVlvBolDelta1'
   *
   * Block requirements for '<Root>/F05_agCkClsExVlvBolDelta':
   *  1. SubSystem "F05_agCkClsExVlvBolDelta" !Trace_To : VEMS_R_11_04467_045.01 ;
   */
  localtmp = (UInt32)(AFA_agCkClsExVlvBolDelta_C * 3);
  if (localAbs4 > ((SInt32)((UInt32)((((UInt32)(((SInt32)localtmp) & 1))
          != 0U) + ((SInt32)(((UInt32)((SInt32)localtmp)) >> 1)))))) {
    /* Constant: '<S9>/Bool' */
    (*rty_AFA_bFitClsExVlvB1) = TRUE;
  } else {
    /* SignalConversion: '<S10>/Signal Conversion' */
    (*rty_AFA_bFitClsExVlvB1) = (*rtu_AFA_bFitClsExVlvBolPrev);
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_agCkClsExVlvBolH1) = rtu_VlvAct_1_prm_agCkClsExVlvBo[0];
}

/* Model initialize function */
void mr_AFA_F01_scruter_e_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
