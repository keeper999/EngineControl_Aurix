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
/* !File            : AFA_F01_AFAClcObs.c                                     */
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
/*   Model name       : AFA_F01_AFAClcObs.mdl                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_AFAClcObs.h"
#include "AFA_F01_AFAClcObs_private.h"
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


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt16 AFA_pDsThrFil;                /* '<S1>/Switch' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Start for referenced model: 'AFA_F01_AFAClcObs' */
void mr_AFA_F01_AFAClcObs_Start(void)
{
  /* Start for atomic SubSystem: '<Root>/F01_calc_sensitivity_fct' *
   * Block requirements for '<Root>/F01_calc_sensitivity_fct':
   *  1. SubSystem "F01_calc_sensitivity_fct" !Trace_To : VEMS_R_11_04467_062.02 ;
   */
  /* Start for ModelReference: '<S1>/AFA_F01_Calc_Sensitivity_SaintVenant' */
  mr_AFA_F01_Calc_Sensitivi_Start();

  /* Start for ModelReference: '<S1>/AFA_F02_Calc_sensitivity_load_estim' */
  mr_AFA_F02_Calc_sensitivi_Start();

  /* end of Start for SubSystem: '<Root>/F01_calc_sensitivity_fct' */

  /* Start for ModelReference: '<Root>/AFA_F02_calc_sensitivity_mat' */
  mr_AFA_F02_calc_sensitivi_Start();
}

/* Output and update for referenced model: 'AFA_F01_AFAClcObs' */
void mr_AFA_F01_AFAClcObs(const UInt16 *rtu_AFA_pDsThrCorFil, const UInt16
  *rtu_AFA_pExMnfEstimFil, const UInt16 *rtu_AFA_nEngFil_irv, const UInt16
  *rtu_AFA_tExMnfEstimFil, const UInt32 *rtu_AFA_tAirUsInVlv2, const SInt16
  *rtu_AFA_agCkClsExVlv1, const SInt16 *rtu_AFA_agCkOpInVlv1, const UInt16
  *rtu_AFA_rTotLdExCorFil, const UInt32 *rtu_AFA_facSlopEfcCorFil, const
  UInt16 *rtu_AFA_rAirPresFil, const UInt16 *rtu_AFA_arEffAdpThrFil, const
  UInt16 *rtu_AFA_arEffAdpEGR1, const UInt16 *rtu_AFA_rInMassFlowFil, const
  UInt16 *rtu_AFA_rOpSIFil, const UInt16 *rtu_AFA_arEffEGRVlvFil, const
  UInt16 *rtu_AFA_rAirLdCorFil, const UInt16 *rtu_AFA_agCkClsInVlv1, const
  UInt16 *rtu_AFA_pAirExtEstimFil, const UInt32 *rtu_AFA_mFuReqFil, const
  SInt16 *rtu_AFA_tCoMesFil, const UInt16 *rtu_AFA_pDsThrPred_03, const
  UInt16 *rtu_AFA_pDsThrEstimFil, const UInt32 rtu_InjrSys_prm_tiInj[4],
  const Boolean rtu_AFA_prm_bMaskSenMat_PIM[16], const UInt16
  rtu_AFA_prm_facCorGainLnrFil__m[4], const UInt32
  rtu_AFA_prm_facGainInjFil_PIM[4], const UInt32 rtu_AFA_prm_pDifInjrFil_PIM[4],
  const UInt16 *rtu_AFA_nEngCorFil, const UInt16 *rtu_AFA_rEthStoichFil,
  const UInt8 *rtu_AFA_facRhoFuFil, SInt32 rty_AFA_prm_facSenTransMat_PIM[16])
{
  /* local block i/o variables */
  UInt32 localAFA_F03_Calc_Sensitivity_I;
  UInt32 localAFA_F02_Calc_sensitivity_l;
  UInt16 localAFA_F03_Calc_Sensitivity_g;
  SInt16 localAFA_F06_Calc_Sensitivity_V;
  SInt16 localAFA_F06_Calc_Sensitivity_h;
  UInt16 localAFA_F04_Calc_Sensitivity_P;
  UInt16 localAFA_F04_Calc_Sensitivity_o;
  UInt16 localAFA_F04_Calc_Sensitivit_oz;
  UInt16 localAFA_F04_Calc_Sensitivity_m;
  UInt16 localAFA_F05_Calc_Sensitivity_E;
  SInt16 localAFA_F02_Calc_sensitivity_o;
  SInt16 localAFA_F02_Calc_sensitivity_e;
  SInt16 localAFA_F06_Calc_Sensitivity_m;
  SInt16 localAFA_F06_Calc_Sensitivity_k;
  UInt16 localAFA_F04_Calc_Sensitivity_j;
  UInt16 localAFA_F04_Calc_Sensitivity_k;
  UInt16 localAFA_F04_Calc_Sensitivit_kr;
  UInt16 localAFA_F04_Calc_Sensitivity_d;
  UInt16 localAFA_F05_Calc_Sensitivity_n;
  UInt16 localAFA_F03_Calc_Sensitivity_c;
  UInt16 localAFA_F01_Calc_Sensitivity_S;
  UInt16 localAFA_F01_Calc_Sensitivity_l;
  UInt16 localAFA_F01_Calc_Sensitivity_a;
  SInt16 localAFA_F02_Calc_sensitivity_m;

  /* Outputs for atomic SubSystem: '<Root>/F01_calc_sensitivity_fct' *
   * Block requirements for '<Root>/F01_calc_sensitivity_fct':
   *  1. SubSystem "F01_calc_sensitivity_fct" !Trace_To : VEMS_R_11_04467_062.02 ;
   */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Ratio_Critique3'
   */
  if (AFA_bSelPresObs_C) {
    AFA_pDsThrFil = (*rtu_AFA_pDsThrCorFil);
  } else {
    AFA_pDsThrFil = (*rtu_AFA_pDsThrEstimFil);
  }

  /* ModelReference: '<S1>/AFA_F01_Calc_Sensitivity_SaintVenant'
   *
   * Block requirements for '<S1>/AFA_F01_Calc_Sensitivity_SaintVenant':
   *  1. ModelReference "AFA_F01_Calc_Sensitivity_SaintVenant" !Trace_To : VEMS_R_11_04467_063.01 ;
   */
  mr_AFA_F01_Calc_Sensitivity_Sai(&AFA_pDsThrFil, &(*rtu_AFA_pExMnfEstimFil), &(*
    rtu_AFA_rAirPresFil), &localAFA_F01_Calc_Sensitivity_S,
    &localAFA_F01_Calc_Sensitivity_l, &localAFA_F01_Calc_Sensitivity_a);

  /* ModelReference: '<S1>/AFA_F02_Calc_sensitivity_load_estim'
   *
   * Block requirements for '<S1>/AFA_F02_Calc_sensitivity_load_estim':
   *  1. ModelReference "AFA_F02_Calc_sensitivity_load_estim" !Trace_To : VEMS_R_11_04467_064.02 ;
   */
  mr_AFA_F02_Calc_sensitivity_loa(&(*rtu_AFA_nEngFil_irv),
    &(*rtu_AFA_agCkClsExVlv1), &(*rtu_AFA_agCkClsInVlv1),
    &(*rtu_AFA_agCkOpInVlv1), &(*rtu_AFA_tAirUsInVlv2),
    &(*rtu_AFA_tExMnfEstimFil), &AFA_pDsThrFil, &(*rtu_AFA_pExMnfEstimFil),
    &(*rtu_AFA_pAirExtEstimFil), &(*rtu_AFA_pDsThrPred_03), &(*rtu_AFA_tCoMesFil),
    &(*rtu_AFA_facSlopEfcCorFil), &(*rtu_AFA_rTotLdExCorFil),
    &localAFA_F01_Calc_Sensitivity_S, &localAFA_F01_Calc_Sensitivity_l,
    &(*rtu_AFA_nEngCorFil), &localAFA_F02_Calc_sensitivity_l,
    &localAFA_F02_Calc_sensitivity_m, &localAFA_F02_Calc_sensitivity_o,
    &localAFA_F02_Calc_sensitivity_e);

  /* ModelReference: '<S1>/AFA_F04_Calc_Sensitivity_Pap'
   *
   * Block requirements for '<S1>/AFA_F04_Calc_Sensitivity_Pap':
   *  1. ModelReference "AFA_F04_Calc_Sensitivity_Pap" !Trace_To : VEMS_R_11_04467_099.01 ;
   */
  mr_AFA_F04_Calc_Sensitivity_Pap(&localAFA_F01_Calc_Sensitivity_a,
    &AFA_pDsThrFil, &(*rtu_AFA_arEffAdpThrFil), &(*rtu_AFA_rInMassFlowFil),
    &(*rtu_AFA_rOpSIFil), &localAFA_F02_Calc_sensitivity_l,
    &localAFA_F04_Calc_Sensitivity_P, &localAFA_F04_Calc_Sensitivity_o,
    &localAFA_F04_Calc_Sensitivit_oz, &localAFA_F04_Calc_Sensitivity_m,
    &localAFA_F04_Calc_Sensitivity_j, &localAFA_F04_Calc_Sensitivity_k,
    &localAFA_F04_Calc_Sensitivit_kr, &localAFA_F04_Calc_Sensitivity_d);

  /* ModelReference: '<S1>/AFA_F05_Calc_Sensitivity_EGR'
   *
   * Block requirements for '<S1>/AFA_F05_Calc_Sensitivity_EGR':
   *  1. ModelReference "AFA_F05_Calc_Sensitivity_EGR" !Trace_To : VEMS_R_11_04467_100.01 ;
   */
  mr_AFA_F05_Calc_Sensitivity_EGR(&localAFA_F02_Calc_sensitivity_l,
    &(*rtu_AFA_arEffAdpThrFil), &(*rtu_AFA_rInMassFlowFil),
    &(*rtu_AFA_arEffAdpEGR1), &localAFA_F01_Calc_Sensitivity_a, &AFA_pDsThrFil,
    &(*rtu_AFA_arEffEGRVlvFil), &localAFA_F05_Calc_Sensitivity_n,
    &localAFA_F05_Calc_Sensitivity_E);

  /* ModelReference: '<S1>/AFA_F06_Calc_Sensitivity_VVT'
   *
   * Block requirements for '<S1>/AFA_F06_Calc_Sensitivity_VVT':
   *  1. ModelReference "AFA_F06_Calc_Sensitivity_VVT" !Trace_To : VEMS_R_11_04467_103.01 ;
   */
  mr_AFA_F06_Calc_Sensitivity_VVT(&(*rtu_AFA_facSlopEfcCorFil),
    &localAFA_F02_Calc_sensitivity_m, &localAFA_F02_Calc_sensitivity_o,
    &localAFA_F02_Calc_sensitivity_e, &(*rtu_AFA_pDsThrCorFil),
    &(*rtu_AFA_rAirPresFil), &(*rtu_AFA_rAirLdCorFil), &(*rtu_AFA_arEffAdpThrFil),
    &(*rtu_AFA_arEffAdpEGR1), &(*rtu_AFA_nEngFil_irv), &(*rtu_AFA_pDsThrEstimFil),
    &localAFA_F06_Calc_Sensitivity_m, &localAFA_F06_Calc_Sensitivity_V,
    &localAFA_F06_Calc_Sensitivity_h, &localAFA_F06_Calc_Sensitivity_k);

  /* ModelReference: '<S1>/AFA_F03_Calc_Sensitivity_Inj'
   *
   * Block requirements for '<S1>/AFA_F03_Calc_Sensitivity_Inj':
   *  1. ModelReference "AFA_F03_Calc_Sensitivity_Inj" !Trace_To : VEMS_R_11_04467_098.01 ;
   */
  mr_AFA_F03_Calc_Sensitivity_Inj(&(*rtu_AFA_mFuReqFil),
    rtu_AFA_prm_facGainInjFil_PIM, rtu_AFA_prm_pDifInjrFil_PIM,
    rtu_InjrSys_prm_tiInj, rtu_AFA_prm_facCorGainLnrFil__m,
    &(*rtu_AFA_rEthStoichFil), &(*rtu_AFA_facRhoFuFil),
    &localAFA_F03_Calc_Sensitivity_g, &localAFA_F03_Calc_Sensitivity_c,
    &localAFA_F03_Calc_Sensitivity_I);

  /* end of Outputs for SubSystem: '<Root>/F01_calc_sensitivity_fct' */

  /* ModelReference: '<Root>/AFA_F02_calc_sensitivity_mat'
   *
   * Block requirements for '<Root>/AFA_F02_calc_sensitivity_mat':
   *  1. ModelReference "AFA_F02_calc_sensitivity_mat" !Trace_To : VEMS_R_11_04467_109.01 ;
   */
  mr_AFA_F02_calc_sensitivity_mat(rtu_AFA_prm_bMaskSenMat_PIM,
    &localAFA_F04_Calc_Sensitivity_P, &localAFA_F04_Calc_Sensitivity_o,
    &localAFA_F04_Calc_Sensitivit_oz, &localAFA_F04_Calc_Sensitivity_m,
    &localAFA_F04_Calc_Sensitivity_j, &localAFA_F04_Calc_Sensitivity_k,
    &localAFA_F04_Calc_Sensitivit_kr, &localAFA_F04_Calc_Sensitivity_d,
    &localAFA_F05_Calc_Sensitivity_n, &localAFA_F05_Calc_Sensitivity_E,
    &localAFA_F03_Calc_Sensitivity_g, &localAFA_F03_Calc_Sensitivity_c,
    &localAFA_F03_Calc_Sensitivity_I, &localAFA_F06_Calc_Sensitivity_m,
    &localAFA_F06_Calc_Sensitivity_V, &localAFA_F06_Calc_Sensitivity_h,
    &localAFA_F06_Calc_Sensitivity_k, rty_AFA_prm_facSenTransMat_PIM);
}

/* Model initialize function */
void mr_AFA_F01_AFAClcObs_initialize(void)
{
  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F02_calc_sensitivity_mat' */
  mr_AFA_F02_calc_sens_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S1>/AFA_F01_Calc_Sensitivity_SaintVenant' */
  mr_AFA_F01_Calc_Sens_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S1>/AFA_F02_Calc_sensitivity_load_estim' */
  mr_AFA_F02_Calc_sens_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S1>/AFA_F03_Calc_Sensitivity_Inj' */
  mr_AFA_F03_Calc_Sens_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S1>/AFA_F04_Calc_Sensitivity_Pap' */
  mr_AFA_F04_Calc_Sens_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S1>/AFA_F05_Calc_Sensitivity_EGR' */
  mr_AFA_F05_Calc_Sens_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S1>/AFA_F06_Calc_Sensitivity_VVT' */
  mr_AFA_F06_Calc_Sens_initialize();
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
