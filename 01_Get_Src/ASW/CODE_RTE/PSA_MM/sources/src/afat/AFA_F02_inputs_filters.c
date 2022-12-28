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
/* !File            : AFA_F02_inputs_filters.c                                */
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
/*   Model name       : AFA_F02_inputs_filters.mdl                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F02_inputs_filters.h"
#include "AFA_F02_inputs_filters_private.h"
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


#define AFAT_START_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"


rtMdlrefDWork_mr_AFA_F02_inputs mr_AFA_F02_inputs_f_MdlrefDWork;


#define AFAT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F02_inputs_filters' */
void mr_AFA_F02_inputs_filters(const UInt16 *rtu_InM_pDsThrPred2, const
  UInt16 *rtu_InM_rAirPres7, const UInt16 *rtu_InM_arEffAdpThr7, const
  UInt16 *rtu_InM_arEffAdpEGRVlv8, const UInt16 *rtu_InM_arEffEGRV4, const
  UInt16 *rtu_InM_mfEGREstimE1, const UInt16 *rtu_InM_mfAirThrEstim7, const
  UInt16 rtu_InjrM_prm_facGain78[4], const UInt16 *rtu_EngM_rAirLd1, const
  UInt16 *rtu_ThrLrn_rOpSI1, const UInt16 *rtu_InM_pDsThrC5, const SInt16
  *rtu_InM_pDsThrEstim4, const UInt16 *rtu_ExM_pExMnfEstim_fac1, const
  UInt16 *rtu_EngM_facSlopEfc1, const UInt16 *rtu_ExM_tExMnfEsti2, const
  UInt16 *rtu_Ext_nEng10, const UInt16 *rtu_InThM_tAirUsInVlvE45, const
  SInt16 *rtu_EngM_agCkClsExVlv1, const SInt16 *rtu_EngM_agCkOpInVlvEs1, const
  UInt16 *rtu_EngM_rTotLdExCor5, const UInt16 *rtu_EngM_agCkClsInVlvEs1,
  const UInt16 *rtu_UsThrM_pAirExt22, const UInt32 *rtu_InjSys_mFuReq5,
  const UInt16 rtu_InjrM_prm_facCorGainLnr1[4], const SInt16 *rtu_Ext_tCoMe45,
  const UInt16 *rtu_InM_pDsThrPred_facVlv7, const UInt32
  *rtu_InM_pDsThrEstim7, const UInt16 *rtu_UsThrM_pUsThrCor7, const UInt16
  rtu_InjrM_prm_pDifInjr5[4], const UInt16 *rtu_InThM_nEngCor, const UInt16 *
  rtu_AfuA_rEthStoich, const UInt8 *rtu_Ext_facRhoFu, UInt16
  *rty_AFA_pDsThrPre9, UInt16 *rty_AFA_rAirPre9, UInt16 *rty_AFA_arEffAdpT9,
  UInt16 *rty_AFA_arEffAdpEGR9, UInt16 *rty_AFA_arEffEGRV9, UInt16
  *rty_AFA_rInMassFlo9, UInt32 rty_AFA_prm_facGainInjFil_PIM1[4], UInt16
  *rty_AFA_rAirLdC9, UInt16 *rty_AFA_rOpSIFil8, UInt16 *rty_AFA_pDsThrCo9,
  SInt16 *rty_ErrFil, UInt16 *rty_AFA_pExMnfEstimFil7, UInt32
  *rty_AFA_facSlopEfc8, UInt16 *rty_AFA_tExMnfEst89, UInt16
  *rty_AFA_nEngFil21, UInt32 *rty_AFA_tAirUsInVlvE45, SInt16
  *rty_AFA_agCkClsExVlvEstim1, SInt16 *rty_AFA_agCkOpInVlv8, UInt16
  *rty_AFA_rTotLdEx5, UInt16 *rty_AFA_agCkClsInVlvEstimRe8, UInt16
  *rty_AFA_pAirExtE10, UInt32 *rty_AFA_mFuReqFil23, UInt16
  rty_AFA_prm_facCorG[4], SInt16 *rty_AFA_tCoMes8, UInt16
  *rty_AFA_pDsThrPred_facVlv4, UInt16 *rty_AFA_pDsThrEsti9, UInt16
  *rty_AFA_pUsThrCorFil4, UInt32 rty_AFA_prm_pDifInjrFil_PIM1[4], UInt16
  *rty_AFA_nEngCorFil, UInt16 *rty_AFA_rEthStoichFil1, UInt8
  *rty_AFA_facRhoFuFil1)
{
  rtDW_mr_AFA_F02_inputs_filters *localDW =
    &(mr_AFA_F02_inputs_f_MdlrefDWork.rtdw);
  Float32 localSwitch;
  Float32 localSwitch_f;
  Float32 localSwitch_b;
  Float32 localDataTypeConversion109;
  Float32 localSwitch_d;
  Float32 localSwitch_i;
  Float32 localSwitch_h;
  Float32 localSwitch_o;
  Float32 localSwitch_p;
  Float32 localSwitch_k;
  Float32 localSwitch_bb;
  Float32 localSwitch_dv;
  Float32 localSwitch_l;
  Float32 localSwitch_j;
  Float32 localSwitch_op;
  Float32 localSwitch_ou;
  Float32 localSwitch_m;
  Float32 localSwitch_e;
  Float32 localSwitch_pr;
  Float32 localSwitch_os;
  Float32 localSwitch_bq;
  Float32 localSwitch_ju;
  Float32 localSwitch_g;
  Float32 localSwitch_n;
  Float32 localSwitch_gs;
  Float32 localSwitch_an;
  Float32 localSwitch_lu;
  Float32 localSwitch_fd;
  Float32 localSwitch_fd2;
  Float32 localSaturation01_ku;
  Float32 localSum1;
  Float32 localSum1_o;
  Float32 localSum1_k;
  Float32 localSum1_p;
  Float32 localSum1_l;
  Float32 localSum1_c;
  Float32 localSum1_ln;
  Float32 localSum1_kx;
  Float32 localSum1_d3;
  Float32 localSum1_f;
  Float32 localSum1_g;
  Float32 localSum1_oy;
  Float32 localSum1_j;
  Float32 localSum1_a;
  Float32 localSum1_h;
  Float32 localSum1_m;
  Float32 localSum1_b;
  Float32 localSum1_p3;
  Float32 localSum1_af;
  Float32 localSum1_n;
  Float32 localSum1_cs;
  Float32 localSum1_o3;
  Float32 localSum1_ds;
  Float32 localSum1_by;
  Float32 localSum1_ky;
  Float32 localSum1_p5;
  Float32 localSum1_pg;
  Float32 locallocalAdd;
  Float32 locallocalSwitch_a_idx;
  Float32 locallocalSwitch_ij_idx;
  Float32 locallocalSwitch_f1_idx;
  Float32 locallocalSwitch_a_idx_0;
  Float32 locallocalSwitch_ij_idx_0;
  Float32 locallocalSwitch_f1_idx_0;
  Float32 locallocalSwitch_a_idx_1;
  Float32 locallocalSwitch_ij_idx_1;
  Float32 locallocalSwitch_f1_idx_1;
  Float32 locallocalSwitch_a_idx_2;
  Float32 locallocalSwitch_ij_idx_2;
  Float32 locallocalSwitch_f1_idx_2;
  Float32 locallocalAdd2_idx;
  Float32 locallocalAdd2_idx_0;
  Float32 locallocalAdd2_idx_1;
  Float32 locallocalAdd2_idx_2;
  Float32 locallocalSum1_d_idx;
  Float32 locallocalSum1_d_idx_0;
  Float32 locallocalSum1_d_idx_1;
  Float32 locallocalSum1_d_idx_2;
  Float32 locallocalSum1_e_idx;
  Float32 locallocalSum1_e_idx_0;
  Float32 locallocalSum1_e_idx_1;
  Float32 locallocalSum1_e_idx_2;
  UInt32 localtmp;
  UInt16 localtmp_0;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  localSwitch = (Float32)(*rtu_InThM_nEngCor);

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  localSwitch_f = ((Float32)(*rtu_InM_pDsThrEstim4)) * 8.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion101' */
  localSwitch_b = ((Float32)(*rtu_EngM_rAirLd1)) * 6.103515625E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion109' incorporates:
   *  Constant: '<Root>/AFA_facFilPresInjDelta_C'
   */
  localDataTypeConversion109 = ((Float32)AFA_facFilPresInjDelta_C) *
    0.00390625F;

  /* DataTypeConversion: '<Root>/Data Type Conversion11' */
  localSwitch_d = ((Float32)(*rtu_ExM_pExMnfEstim_fac1)) * 8.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion12' */
  localSwitch_i = ((Float32)(*rtu_EngM_facSlopEfc1)) * 3.356933620E-010F;

  /* DataTypeConversion: '<Root>/Data Type Conversion13' */
  localSwitch_h = (((Float32)(*rtu_ExM_tExMnfEsti2)) * 0.03125F) + 223.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion14' */
  localSwitch_o = (Float32)(*rtu_Ext_nEng10);

  /* DataTypeConversion: '<Root>/Data Type Conversion16' */
  localSwitch_p = (((Float32)(*rtu_InThM_tAirUsInVlvE45)) * 0.0078125F) +
    223.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion17' */
  localSwitch_k = ((Float32)(*rtu_EngM_agCkClsExVlv1)) * 0.09375F;

  /* DataTypeConversion: '<Root>/Data Type Conversion19' */
  localSwitch_bb = ((Float32)(*rtu_EngM_rTotLdExCor5)) * 6.103515625E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  localSwitch_dv = ((Float32)(*rtu_AfuA_rEthStoich)) * 3.051757813E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion20' */
  localSwitch_l = (((Float32)(*rtu_EngM_agCkClsInVlvEs1)) * 0.09375F) + 84.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion21' */
  localSwitch_j = ((Float32)(*rtu_UsThrM_pAirExt22)) * 8.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion22' */
  localSwitch_op = ((Float32)(*rtu_InjSys_mFuReq5)) * 7.450580597E-009F;

  /* DataTypeConversion: '<Root>/Data Type Conversion24' */
  localSwitch_ou = (Float32)(*rtu_Ext_tCoMe45);

  /* DataTypeConversion: '<Root>/Data Type Conversion26' */
  localSwitch_m = ((Float32)(*rtu_InM_pDsThrEstim7)) * 0.0078125F;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  localSwitch_e = ((Float32)(*rtu_Ext_facRhoFu)) * 0.0078125F;

  /* DataTypeConversion: '<Root>/Data Type Conversion49' */
  localSwitch_pr = ((Float32)(*rtu_InM_pDsThrPred_facVlv7)) * 8.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion52' */
  localSwitch_os = ((Float32)(*rtu_UsThrM_pUsThrCor7)) * 8.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion55' */
  localSwitch_bq = ((Float32)(*rtu_InM_pDsThrC5)) * 8.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion104' */
  locallocalSwitch_a_idx = ((Float32)rtu_InjrM_prm_facGain78[0]) * 0.015625F;

  /* DataTypeConversion: '<Root>/Data Type Conversion30' */
  locallocalSwitch_ij_idx = ((Float32)rtu_InjrM_prm_pDifInjr5[0]) * 781.25F;

  /* DataTypeConversion: '<Root>/Data Type Conversion60' */
  locallocalSwitch_f1_idx = ((Float32)rtu_InjrM_prm_facCorGainLnr1[0]) *
    3.051757813E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion104' */
  locallocalSwitch_a_idx_0 = ((Float32)rtu_InjrM_prm_facGain78[1]) * 0.015625F;

  /* DataTypeConversion: '<Root>/Data Type Conversion30' */
  locallocalSwitch_ij_idx_0 = ((Float32)rtu_InjrM_prm_pDifInjr5[1]) * 781.25F;

  /* DataTypeConversion: '<Root>/Data Type Conversion60' */
  locallocalSwitch_f1_idx_0 = ((Float32)rtu_InjrM_prm_facCorGainLnr1[1]) *
    3.051757813E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion104' */
  locallocalSwitch_a_idx_1 = ((Float32)rtu_InjrM_prm_facGain78[2]) * 0.015625F;

  /* DataTypeConversion: '<Root>/Data Type Conversion30' */
  locallocalSwitch_ij_idx_1 = ((Float32)rtu_InjrM_prm_pDifInjr5[2]) * 781.25F;

  /* DataTypeConversion: '<Root>/Data Type Conversion60' */
  locallocalSwitch_f1_idx_1 = ((Float32)rtu_InjrM_prm_facCorGainLnr1[2]) *
    3.051757813E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion104' */
  locallocalSwitch_a_idx_2 = ((Float32)rtu_InjrM_prm_facGain78[3]) * 0.015625F;

  /* DataTypeConversion: '<Root>/Data Type Conversion30' */
  locallocalSwitch_ij_idx_2 = ((Float32)rtu_InjrM_prm_pDifInjr5[3]) * 781.25F;

  /* DataTypeConversion: '<Root>/Data Type Conversion60' */
  locallocalSwitch_f1_idx_2 = ((Float32)rtu_InjrM_prm_facCorGainLnr1[3]) *
    3.051757813E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion62' */
  localSwitch_ju = ((Float32)(*rtu_InM_rAirPres7)) * 1.525878906E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion64' */
  localSwitch_g = ((Float32)(*rtu_InM_arEffAdpThr7)) * 5.960464478E-008F;

  /* DataTypeConversion: '<Root>/Data Type Conversion67' */
  localSwitch_n = ((Float32)(*rtu_InM_arEffAdpEGRVlv8)) * 5.960464478E-008F;

  /* DataTypeConversion: '<Root>/Data Type Conversion71' */
  localSwitch_gs = ((Float32)(*rtu_InM_arEffEGRV4)) * 5.960464478E-008F;

  /* DataTypeConversion: '<Root>/Data Type Conversion79' */
  localSwitch_an = ((Float32)(*rtu_EngM_agCkOpInVlvEs1)) * 0.09375F;

  /* DataTypeConversion: '<Root>/Data Type Conversion8' */
  localSwitch_lu = ((Float32)(*rtu_ThrLrn_rOpSI1)) * 0.0009765625F;

  /* DataTypeConversion: '<Root>/Data Type Convesion108' */
  localSwitch_fd = ((Float32)(*rtu_InM_pDsThrPred2)) * 8.0F;

  /* UnitDelay: '<S66>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay;

  /* Switch: '<S66>/Switch' incorporates:
   *  UnitDelay: '<S66>/UnitDelay1'
   */
  if (!localDW->UnitDelay_b2) {
    localSwitch_fd2 = localSwitch_fd;
  }

  /* Sum: '<S67>/Sum1' incorporates:
   *  Product: '<S67>/Product'
   *  Saturate: '<S67>/Saturation [0-1]'
   *  Sum: '<S67>/Sum'
   */
  localSum1 = ((localSwitch_fd - localSwitch_fd2) * rt_SATURATE
               (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S64>/Switch' incorporates:
   *  UnitDelay: '<S64>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE) {
    localSwitch_fd = localSum1;
  }

  /* UnitDelay: '<S70>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_h;

  /* Switch: '<S70>/Switch' incorporates:
   *  UnitDelay: '<S70>/UnitDelay1'
   */
  if (!localDW->UnitDelay_pt) {
    localSwitch_fd2 = localSwitch_m;
  }

  /* Sum: '<S71>/Sum1' incorporates:
   *  Product: '<S71>/Product'
   *  Saturate: '<S71>/Saturation [0-1]'
   *  Sum: '<S71>/Sum'
   */
  localSum1_o = ((localSwitch_m - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S68>/Switch' incorporates:
   *  UnitDelay: '<S68>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_g) {
    localSwitch_m = localSum1_o;
  }

  /* UnitDelay: '<S74>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_o;

  /* Switch: '<S74>/Switch' incorporates:
   *  UnitDelay: '<S74>/UnitDelay1'
   */
  if (!localDW->UnitDelay_hpy) {
    localSwitch_fd2 = localSwitch_j;
  }

  /* Sum: '<S75>/Sum1' incorporates:
   *  Product: '<S75>/Product'
   *  Saturate: '<S75>/Saturation [0-1]'
   *  Sum: '<S75>/Sum'
   */
  localSum1_k = ((localSwitch_j - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S72>/Switch' incorporates:
   *  UnitDelay: '<S72>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_c) {
    localSwitch_j = localSum1_k;
  }

  /* UnitDelay: '<S78>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_n;

  /* Switch: '<S78>/Switch' incorporates:
   *  UnitDelay: '<S78>/UnitDelay1'
   */
  if (!localDW->UnitDelay_k4) {
    localSwitch_fd2 = localSwitch_d;
  }

  /* Sum: '<S79>/Sum1' incorporates:
   *  Product: '<S79>/Product'
   *  Saturate: '<S79>/Saturation [0-1]'
   *  Sum: '<S79>/Sum'
   */
  localSum1_p = ((localSwitch_d - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S76>/Switch' incorporates:
   *  UnitDelay: '<S76>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_f) {
    localSwitch_d = localSum1_p;
  }

  /* UnitDelay: '<S82>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_h4;

  /* Switch: '<S82>/Switch' incorporates:
   *  UnitDelay: '<S82>/UnitDelay1'
   */
  if (!localDW->UnitDelay_psn) {
    localSwitch_fd2 = localSwitch_f;
  }

  /* Sum: '<S83>/Sum1' incorporates:
   *  Product: '<S83>/Product'
   *  Saturate: '<S83>/Saturation [0-1]'
   *  Sum: '<S83>/Sum'
   */
  localSum1_l = ((localSwitch_f - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S80>/Switch' incorporates:
   *  UnitDelay: '<S80>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_p) {
    localSwitch_f = localSum1_l;
  }

  /* UnitDelay: '<S86>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_l;

  /* Switch: '<S86>/Switch' incorporates:
   *  UnitDelay: '<S86>/UnitDelay1'
   */
  if (!localDW->UnitDelay_hh) {
    localSwitch_fd2 = localSwitch_bq;
  }

  /* Sum: '<S87>/Sum1' incorporates:
   *  Product: '<S87>/Product'
   *  Saturate: '<S87>/Saturation [0-1]'
   *  Sum: '<S87>/Sum'
   */
  localSum1_c = ((localSwitch_bq - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S84>/Switch' incorporates:
   *  UnitDelay: '<S84>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_k) {
    localSwitch_bq = localSum1_c;
  }

  /* UnitDelay: '<S90>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_a;

  /* Switch: '<S90>/Switch' incorporates:
   *  UnitDelay: '<S90>/UnitDelay1'
   */
  if (!localDW->UnitDelay_ib) {
    localSwitch_fd2 = localSwitch_lu;
  }

  /* Sum: '<S91>/Sum1' incorporates:
   *  Product: '<S91>/Product'
   *  Saturate: '<S91>/Saturation [0-1]'
   *  Sum: '<S91>/Sum'
   */
  localSum1_ln = ((localSwitch_lu - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S88>/Switch' incorporates:
   *  UnitDelay: '<S88>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_c1) {
    localSwitch_lu = localSum1_ln;
  }

  /* UnitDelay: '<S94>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_os;

  /* Switch: '<S94>/Switch' incorporates:
   *  UnitDelay: '<S94>/UnitDelay1'
   */
  if (!localDW->UnitDelay_gi) {
    localSwitch_fd2 = localSwitch_b;
  }

  /* Sum: '<S95>/Sum1' incorporates:
   *  Product: '<S95>/Product'
   *  Saturate: '<S95>/Saturation [0-1]'
   *  Sum: '<S95>/Sum'
   */
  localSum1_kx = ((localSwitch_b - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S92>/Switch' incorporates:
   *  UnitDelay: '<S92>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_b) {
    localSwitch_b = localSum1_kx;
  }

  /* Saturate: '<S99>/Saturation [0-1]' */
  localSaturation01_ku = rt_SATURATE(localDataTypeConversion109, 0.0F, 1.0F);

  /* UnitDelay: '<S98>/UnitDelay' */
  locallocalAdd2_idx = localDW->UnitDelay_m[0];
  locallocalAdd2_idx_0 = localDW->UnitDelay_m[1];
  locallocalAdd2_idx_1 = localDW->UnitDelay_m[2];
  locallocalAdd2_idx_2 = localDW->UnitDelay_m[3];

  /* Switch: '<S98>/Switch' incorporates:
   *  UnitDelay: '<S98>/UnitDelay1'
   */
  if (!localDW->UnitDelay_hf) {
    locallocalAdd2_idx = locallocalSwitch_a_idx;
    locallocalAdd2_idx_0 = locallocalSwitch_a_idx_0;
    locallocalAdd2_idx_1 = locallocalSwitch_a_idx_1;
    locallocalAdd2_idx_2 = locallocalSwitch_a_idx_2;
  }

  /* Sum: '<S99>/Sum1' incorporates:
   *  Product: '<S99>/Product'
   *  Sum: '<S99>/Sum'
   */
  locallocalSum1_d_idx = ((locallocalSwitch_a_idx - locallocalAdd2_idx) *
    localSaturation01_ku) + locallocalAdd2_idx;
  locallocalSum1_d_idx_0 = ((locallocalSwitch_a_idx_0 - locallocalAdd2_idx_0) *
    localSaturation01_ku) + locallocalAdd2_idx_0;
  locallocalSum1_d_idx_1 = ((locallocalSwitch_a_idx_1 - locallocalAdd2_idx_1) *
    localSaturation01_ku) + locallocalAdd2_idx_1;
  locallocalSum1_d_idx_2 = ((locallocalSwitch_a_idx_2 - locallocalAdd2_idx_2) *
    localSaturation01_ku) + locallocalAdd2_idx_2;

  /* Switch: '<S96>/Switch' incorporates:
   *  UnitDelay: '<S96>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_a) {
    locallocalSwitch_a_idx = locallocalSum1_d_idx;
    locallocalSwitch_a_idx_0 = locallocalSum1_d_idx_0;
    locallocalSwitch_a_idx_1 = locallocalSum1_d_idx_1;
    locallocalSwitch_a_idx_2 = locallocalSum1_d_idx_2;
  }

  /* UnitDelay: '<S102>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_ol;

  /* Switch: '<S102>/Switch' incorporates:
   *  UnitDelay: '<S102>/UnitDelay1'
   */
  if (!localDW->UnitDelay_p0) {
    localSwitch_fd2 = localSwitch_gs;
  }

  /* Sum: '<S103>/Sum1' incorporates:
   *  Product: '<S103>/Product'
   *  Saturate: '<S103>/Saturation [0-1]'
   *  Sum: '<S103>/Sum'
   */
  localSum1_d3 = ((localSwitch_gs - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S100>/Switch' incorporates:
   *  UnitDelay: '<S100>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_j) {
    localSwitch_gs = localSum1_d3;
  }

  /* UnitDelay: '<S106>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_nr;

  /* Switch: '<S106>/Switch' incorporates:
   *  UnitDelay: '<S106>/UnitDelay1'
   */
  if (!localDW->UnitDelay_f4) {
    localSwitch_fd2 = localSwitch_i;
  }

  /* Sum: '<S107>/Sum1' incorporates:
   *  Product: '<S107>/Product'
   *  Saturate: '<S107>/Saturation [0-1]'
   *  Sum: '<S107>/Sum'
   */
  localSum1_f = ((localSwitch_i - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S104>/Switch' incorporates:
   *  UnitDelay: '<S104>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_jg) {
    localSwitch_i = localSum1_f;
  }

  /* UnitDelay: '<S110>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_hv;

  /* Switch: '<S110>/Switch' incorporates:
   *  UnitDelay: '<S110>/UnitDelay1'
   */
  if (!localDW->UnitDelay_ip) {
    localSwitch_fd2 = localSwitch_h;
  }

  /* Sum: '<S111>/Sum1' incorporates:
   *  Product: '<S111>/Product'
   *  Saturate: '<S111>/Saturation [0-1]'
   *  Sum: '<S111>/Sum'
   */
  localSum1_g = ((localSwitch_h - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S108>/Switch' incorporates:
   *  UnitDelay: '<S108>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_fm) {
    localSwitch_h = localSum1_g;
  }

  /* UnitDelay: '<S114>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_k;

  /* Switch: '<S114>/Switch' incorporates:
   *  UnitDelay: '<S114>/UnitDelay1'
   */
  if (!localDW->UnitDelay_gl) {
    localSwitch_fd2 = localSwitch_ju;
  }

  /* Sum: '<S115>/Sum1' incorporates:
   *  Product: '<S115>/Product'
   *  Saturate: '<S115>/Saturation [0-1]'
   *  Sum: '<S115>/Sum'
   */
  localSum1_oy = ((localSwitch_ju - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S112>/Switch' incorporates:
   *  UnitDelay: '<S112>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_bd) {
    localSwitch_ju = localSum1_oy;
  }

  /* UnitDelay: '<S118>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_ky;

  /* Switch: '<S118>/Switch' incorporates:
   *  UnitDelay: '<S118>/UnitDelay1'
   */
  if (!localDW->UnitDelay_jj) {
    localSwitch_fd2 = localSwitch_o;
  }

  /* Sum: '<S119>/Sum1' incorporates:
   *  Product: '<S119>/Product'
   *  Saturate: '<S119>/Saturation [0-1]'
   *  Sum: '<S119>/Sum'
   */
  localSum1_j = ((localSwitch_o - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S116>/Switch' incorporates:
   *  UnitDelay: '<S116>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_ku) {
    localSwitch_o = localSum1_j;
  }

  /* UnitDelay: '<S122>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_j;

  /* Switch: '<S122>/Switch' incorporates:
   *  UnitDelay: '<S122>/UnitDelay1'
   */
  if (!localDW->UnitDelay_psh) {
    localSwitch_fd2 = localSwitch_p;
  }

  /* Sum: '<S123>/Sum1' incorporates:
   *  Product: '<S123>/Product'
   *  Saturate: '<S123>/Saturation [0-1]'
   *  Sum: '<S123>/Sum'
   */
  localSum1_a = ((localSwitch_p - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S120>/Switch' incorporates:
   *  UnitDelay: '<S120>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_ai) {
    localSwitch_p = localSum1_a;
  }

  /* UnitDelay: '<S126>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_i;

  /* Switch: '<S126>/Switch' incorporates:
   *  UnitDelay: '<S126>/UnitDelay1'
   */
  if (!localDW->UnitDelay_ko) {
    localSwitch_fd2 = localSwitch_k;
  }

  /* Sum: '<S127>/Sum1' incorporates:
   *  Product: '<S127>/Product'
   *  Saturate: '<S127>/Saturation [0-1]'
   *  Sum: '<S127>/Sum'
   */
  localSum1_h = ((localSwitch_k - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S124>/Switch' incorporates:
   *  UnitDelay: '<S124>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_d) {
    localSwitch_k = localSum1_h;
  }

  /* UnitDelay: '<S130>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_iu;

  /* Switch: '<S130>/Switch' incorporates:
   *  UnitDelay: '<S130>/UnitDelay1'
   */
  if (!localDW->UnitDelay_ll) {
    localSwitch_fd2 = localSwitch_an;
  }

  /* Sum: '<S131>/Sum1' incorporates:
   *  Product: '<S131>/Product'
   *  Saturate: '<S131>/Saturation [0-1]'
   *  Sum: '<S131>/Sum'
   */
  localSum1_m = ((localSwitch_an - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S128>/Switch' incorporates:
   *  UnitDelay: '<S128>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_px) {
    localSwitch_an = localSum1_m;
  }

  /* UnitDelay: '<S134>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_g;

  /* Switch: '<S134>/Switch' incorporates:
   *  UnitDelay: '<S134>/UnitDelay1'
   */
  if (!localDW->UnitDelay_fn) {
    localSwitch_fd2 = localSwitch_bb;
  }

  /* Sum: '<S135>/Sum1' incorporates:
   *  Product: '<S135>/Product'
   *  Saturate: '<S135>/Saturation [0-1]'
   *  Sum: '<S135>/Sum'
   */
  localSum1_b = ((localSwitch_bb - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S132>/Switch' incorporates:
   *  UnitDelay: '<S132>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_b3) {
    localSwitch_bb = localSum1_b;
  }

  /* UnitDelay: '<S138>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_e;

  /* Switch: '<S138>/Switch' incorporates:
   *  UnitDelay: '<S138>/UnitDelay1'
   */
  if (!localDW->UnitDelay_d) {
    localSwitch_fd2 = localSwitch_op;
  }

  /* Sum: '<S139>/Sum1' incorporates:
   *  Product: '<S139>/Product'
   *  Saturate: '<S139>/Saturation [0-1]'
   *  Sum: '<S139>/Sum'
   */
  localSum1_p3 = ((localSwitch_op - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S136>/Switch' incorporates:
   *  UnitDelay: '<S136>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_l) {
    localSwitch_op = localSum1_p3;
  }

  /* UnitDelay: '<S142>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_oo;

  /* Switch: '<S142>/Switch' incorporates:
   *  UnitDelay: '<S142>/UnitDelay1'
   */
  if (!localDW->UnitDelay_iy) {
    localSwitch_fd2 = localSwitch_pr;
  }

  /* Sum: '<S143>/Sum1' incorporates:
   *  Product: '<S143>/Product'
   *  Saturate: '<S143>/Saturation [0-1]'
   *  Sum: '<S143>/Sum'
   */
  localSum1_af = ((localSwitch_pr - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S140>/Switch' incorporates:
   *  UnitDelay: '<S140>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_l1) {
    localSwitch_pr = localSum1_af;
  }

  /* UnitDelay: '<S146>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_p;

  /* Switch: '<S146>/Switch' incorporates:
   *  UnitDelay: '<S146>/UnitDelay1'
   */
  if (!localDW->UnitDelay_lv) {
    localSwitch_fd2 = localSwitch_os;
  }

  /* Sum: '<S147>/Sum1' incorporates:
   *  Product: '<S147>/Product'
   *  Saturate: '<S147>/Saturation [0-1]'
   *  Sum: '<S147>/Sum'
   */
  localSum1_n = ((localSwitch_os - localSwitch_fd2) * rt_SATURATE
                 (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S144>/Switch' incorporates:
   *  UnitDelay: '<S144>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_ap) {
    localSwitch_os = localSum1_n;
  }

  /* UnitDelay: '<S150>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_i2;

  /* Switch: '<S150>/Switch' incorporates:
   *  UnitDelay: '<S150>/UnitDelay1'
   */
  if (!localDW->UnitDelay_h1) {
    localSwitch_fd2 = localSwitch;
  }

  /* Sum: '<S151>/Sum1' incorporates:
   *  Product: '<S151>/Product'
   *  Saturate: '<S151>/Saturation [0-1]'
   *  Sum: '<S151>/Sum'
   */
  localSum1_cs = ((localSwitch - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S148>/Switch' incorporates:
   *  UnitDelay: '<S148>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_dx) {
    localSwitch = localSum1_cs;
  }

  /* UnitDelay: '<S154>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_eh;

  /* Switch: '<S154>/Switch' incorporates:
   *  UnitDelay: '<S154>/UnitDelay1'
   */
  if (!localDW->UnitDelay_h3) {
    localSwitch_fd2 = localSwitch_dv;
  }

  /* Sum: '<S155>/Sum1' incorporates:
   *  Product: '<S155>/Product'
   *  Saturate: '<S155>/Saturation [0-1]'
   *  Sum: '<S155>/Sum'
   */
  localSum1_o3 = ((localSwitch_dv - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S152>/Switch' incorporates:
   *  UnitDelay: '<S152>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_gx) {
    localSwitch_dv = localSum1_o3;
  }

  /* UnitDelay: '<S158>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_g0;

  /* Switch: '<S158>/Switch' incorporates:
   *  UnitDelay: '<S158>/UnitDelay1'
   */
  if (!localDW->UnitDelay_ea) {
    localSwitch_fd2 = localSwitch_g;
  }

  /* Sum: '<S159>/Sum1' incorporates:
   *  Product: '<S159>/Product'
   *  Saturate: '<S159>/Saturation [0-1]'
   *  Sum: '<S159>/Sum'
   */
  localSum1_ds = ((localSwitch_g - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S156>/Switch' incorporates:
   *  UnitDelay: '<S156>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_m) {
    localSwitch_g = localSum1_ds;
  }

  /* UnitDelay: '<S162>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_ps;

  /* Switch: '<S162>/Switch' incorporates:
   *  UnitDelay: '<S162>/UnitDelay1'
   */
  if (!localDW->UnitDelay_hs) {
    localSwitch_fd2 = localSwitch_e;
  }

  /* Sum: '<S163>/Sum1' incorporates:
   *  Product: '<S163>/Product'
   *  Saturate: '<S163>/Saturation [0-1]'
   *  Sum: '<S163>/Sum'
   */
  localSum1_by = ((localSwitch_e - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S160>/Switch' incorporates:
   *  UnitDelay: '<S160>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_e) {
    localSwitch_e = localSum1_by;
  }

  /* UnitDelay: '<S166>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_b;

  /* Switch: '<S166>/Switch' incorporates:
   *  UnitDelay: '<S166>/UnitDelay1'
   */
  if (!localDW->UnitDelay_he) {
    localSwitch_fd2 = localSwitch_n;
  }

  /* Sum: '<S167>/Sum1' incorporates:
   *  Product: '<S167>/Product'
   *  Saturate: '<S167>/Saturation [0-1]'
   *  Sum: '<S167>/Sum'
   */
  localSum1_ky = ((localSwitch_n - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S164>/Switch' incorporates:
   *  UnitDelay: '<S164>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_n) {
    localSwitch_n = localSum1_ky;
  }

  /* If: '<S32>/If2' incorporates:
   *  ActionPort: '<S190>/Action Port'
   *  ActionPort: '<S191>/Action Port'
   *  Constant: '<S32>/Constant7'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  SubSystem: '<S32>/If Action Subsystem2'
   *  SubSystem: '<S32>/If Action Subsystem3'
   */
  if ((*rtu_InM_mfAirThrEstim7) == 0) {
    /* Constant: '<S190>/Byp_Fonction_SC' */
    localSaturation01_ku = 0.0F;
  } else {
    /* Product: '<S191>/Divide1' */
    localSaturation01_ku = (((Float32)(*rtu_InM_mfEGREstimE1)) *
      1.525878906E-005F) / (((Float32)(*rtu_InM_mfAirThrEstim7)) *
      1.525878906E-005F);
  }

  /* UnitDelay: '<S170>/UnitDelay' */
  localSwitch_fd2 = localDW->UnitDelay_mx;

  /* Switch: '<S170>/Switch' incorporates:
   *  Constant: '<Root>/Constant5'
   *  UnitDelay: '<S170>/UnitDelay1'
   */
  if (!localDW->UnitDelay_g5) {
    localSwitch_fd2 = 0.0F;
  }

  /* Sum: '<S171>/Sum1' incorporates:
   *  Product: '<S171>/Product'
   *  Saturate: '<S171>/Saturation [0-1]'
   *  Sum: '<S171>/Sum'
   */
  localSum1_p5 = ((localSaturation01_ku - localSwitch_fd2) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) + localSwitch_fd2;

  /* Switch: '<S168>/Switch' incorporates:
   *  Constant: '<Root>/Constant5'
   *  UnitDelay: '<S168>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_c0) {
    localSwitch_fd2 = localSum1_p5;
  } else {
    localSwitch_fd2 = 0.0F;
  }

  /* UnitDelay: '<S174>/UnitDelay' */
  localSaturation01_ku = localDW->UnitDelay_n5;

  /* Switch: '<S174>/Switch' incorporates:
   *  UnitDelay: '<S174>/UnitDelay1'
   */
  if (!localDW->UnitDelay_hz) {
    localSaturation01_ku = localSwitch_l;
  }

  /* Sum: '<S175>/Sum1' incorporates:
   *  Product: '<S175>/Product'
   *  Saturate: '<S175>/Saturation [0-1]'
   *  Sum: '<S175>/Sum'
   */
  localSum1_pg = ((localSwitch_l - localSaturation01_ku) * rt_SATURATE
                  (localDataTypeConversion109, 0.0F, 1.0F)) +
    localSaturation01_ku;

  /* Switch: '<S172>/Switch' incorporates:
   *  UnitDelay: '<S172>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_ef) {
    localSwitch_l = localSum1_pg;
  }

  /* Saturate: '<S179>/Saturation [0-1]' */
  localSaturation01_ku = rt_SATURATE(localDataTypeConversion109, 0.0F, 1.0F);

  /* UnitDelay: '<S178>/UnitDelay' */
  locallocalAdd2_idx = localDW->UnitDelay_hp[0];
  locallocalAdd2_idx_0 = localDW->UnitDelay_hp[1];
  locallocalAdd2_idx_1 = localDW->UnitDelay_hp[2];
  locallocalAdd2_idx_2 = localDW->UnitDelay_hp[3];

  /* Switch: '<S178>/Switch' incorporates:
   *  UnitDelay: '<S178>/UnitDelay1'
   */
  if (!localDW->UnitDelay_i2k) {
    locallocalAdd2_idx = locallocalSwitch_f1_idx;
    locallocalAdd2_idx_0 = locallocalSwitch_f1_idx_0;
    locallocalAdd2_idx_1 = locallocalSwitch_f1_idx_1;
    locallocalAdd2_idx_2 = locallocalSwitch_f1_idx_2;
  }

  /* Sum: '<S179>/Sum1' incorporates:
   *  Product: '<S179>/Product'
   *  Sum: '<S179>/Sum'
   */
  locallocalSum1_e_idx = ((locallocalSwitch_f1_idx - locallocalAdd2_idx) *
    localSaturation01_ku) + locallocalAdd2_idx;
  locallocalSum1_e_idx_0 = ((locallocalSwitch_f1_idx_0 - locallocalAdd2_idx_0) *
    localSaturation01_ku) + locallocalAdd2_idx_0;
  locallocalSum1_e_idx_1 = ((locallocalSwitch_f1_idx_1 - locallocalAdd2_idx_1) *
    localSaturation01_ku) + locallocalAdd2_idx_1;
  locallocalSum1_e_idx_2 = ((locallocalSwitch_f1_idx_2 - locallocalAdd2_idx_2) *
    localSaturation01_ku) + locallocalAdd2_idx_2;

  /* Switch: '<S176>/Switch' incorporates:
   *  UnitDelay: '<S176>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_i) {
    locallocalSwitch_f1_idx = locallocalSum1_e_idx;
    locallocalSwitch_f1_idx_0 = locallocalSum1_e_idx_0;
    locallocalSwitch_f1_idx_1 = locallocalSum1_e_idx_1;
    locallocalSwitch_f1_idx_2 = locallocalSum1_e_idx_2;
  }

  /* Saturate: '<S183>/Saturation [0-1]' */
  localSaturation01_ku = rt_SATURATE(localDataTypeConversion109, 0.0F, 1.0F);

  /* UnitDelay: '<S182>/UnitDelay' */
  locallocalAdd2_idx = localDW->UnitDelay_f[0];
  locallocalAdd2_idx_0 = localDW->UnitDelay_f[1];
  locallocalAdd2_idx_1 = localDW->UnitDelay_f[2];
  locallocalAdd2_idx_2 = localDW->UnitDelay_f[3];

  /* Switch: '<S182>/Switch' incorporates:
   *  UnitDelay: '<S182>/UnitDelay1'
   */
  if (!localDW->UnitDelay_eo) {
    locallocalAdd2_idx = locallocalSwitch_ij_idx;
    locallocalAdd2_idx_0 = locallocalSwitch_ij_idx_0;
    locallocalAdd2_idx_1 = locallocalSwitch_ij_idx_1;
    locallocalAdd2_idx_2 = locallocalSwitch_ij_idx_2;
  }

  /* Sum: '<S183>/Sum1' incorporates:
   *  Product: '<S183>/Product'
   *  Sum: '<S183>/Sum'
   */
  locallocalAdd2_idx += (locallocalSwitch_ij_idx - locallocalAdd2_idx) *
    localSaturation01_ku;
  locallocalAdd2_idx_0 += (locallocalSwitch_ij_idx_0 - locallocalAdd2_idx_0) *
    localSaturation01_ku;
  locallocalAdd2_idx_1 += (locallocalSwitch_ij_idx_1 - locallocalAdd2_idx_1) *
    localSaturation01_ku;
  locallocalAdd = ((locallocalSwitch_ij_idx_2 - locallocalAdd2_idx_2) *
                   localSaturation01_ku) + locallocalAdd2_idx_2;

  /* Switch: '<S180>/Switch' incorporates:
   *  UnitDelay: '<S180>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_c0p) {
    locallocalSwitch_ij_idx = locallocalAdd2_idx;
    locallocalSwitch_ij_idx_0 = locallocalAdd2_idx_0;
    locallocalSwitch_ij_idx_1 = locallocalAdd2_idx_1;
    locallocalSwitch_ij_idx_2 = locallocalAdd;
  }

  /* UnitDelay: '<S186>/UnitDelay' */
  localSaturation01_ku = localDW->UnitDelay_lk;

  /* Switch: '<S186>/Switch' incorporates:
   *  UnitDelay: '<S186>/UnitDelay1'
   */
  if (!localDW->UnitDelay_al) {
    localSaturation01_ku = localSwitch_ou;
  }

  /* Sum: '<S187>/Sum1' incorporates:
   *  Product: '<S187>/Product'
   *  Saturate: '<S187>/Saturation [0-1]'
   *  Sum: '<S187>/Sum'
   */
  localDataTypeConversion109 = ((localSwitch_ou - localSaturation01_ku) *
    rt_SATURATE(localDataTypeConversion109, 0.0F, 1.0F)) + localSaturation01_ku;

  /* Switch: '<S184>/Switch' incorporates:
   *  UnitDelay: '<S184>/UnitDelay'
   */
  if (localDW->UnitDelay_DSTATE_me) {
    localSwitch_ou = localDataTypeConversion109;
  }

  /* DataTypeConversion: '<S33>/OutDTConv' incorporates:
   *  Constant: '<S33>/offset'
   *  Constant: '<S33>/offset1'
   *  Constant: '<S33>/one_on_slope'
   *  Product: '<S33>/Product4'
   *  Sum: '<S33>/Add1'
   *  Sum: '<S33>/Add2'
   */
  locallocalAdd2_idx_2 = (0.125F * localSwitch_fd) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_pDsThrPre9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_pDsThrPre9) = 0U;
    }
  } else {
    (*rty_AFA_pDsThrPre9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S34>/OutDTConv' incorporates:
   *  Constant: '<S34>/offset'
   *  Constant: '<S34>/offset1'
   *  Constant: '<S34>/one_on_slope'
   *  Product: '<S34>/Product4'
   *  Sum: '<S34>/Add1'
   *  Sum: '<S34>/Add2'
   */
  locallocalAdd2_idx_2 = (0.125F * localSwitch_m) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_pDsThrEsti9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_pDsThrEsti9) = 0U;
    }
  } else {
    (*rty_AFA_pDsThrEsti9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S35>/OutDTConv' incorporates:
   *  Constant: '<S35>/offset'
   *  Constant: '<S35>/offset1'
   *  Constant: '<S35>/one_on_slope'
   *  Product: '<S35>/Product4'
   *  Sum: '<S35>/Add1'
   *  Sum: '<S35>/Add2'
   */
  locallocalAdd2_idx_2 = (0.125F * localSwitch_j) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_pAirExtE10) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_pAirExtE10) = 0U;
    }
  } else {
    (*rty_AFA_pAirExtE10) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S36>/OutDTConv' incorporates:
   *  Constant: '<S36>/offset'
   *  Constant: '<S36>/offset1'
   *  Constant: '<S36>/one_on_slope'
   *  Product: '<S36>/Product4'
   *  Sum: '<S36>/Add1'
   *  Sum: '<S36>/Add2'
   */
  locallocalAdd2_idx_2 = (0.125F * localSwitch_d) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_pExMnfEstimFil7) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_pExMnfEstimFil7) = 0U;
    }
  } else {
    (*rty_AFA_pExMnfEstimFil7) = MAX_uint16_T;
  }

  /* Product: '<S37>/Product4' incorporates:
   *  Constant: '<S37>/offset'
   *  Constant: '<S37>/one_on_slope'
   *  Sum: '<S37>/Add1'
   */
  localSaturation01_ku = 0.125F * localSwitch_f;

  /* Switch: '<S37>/Switch1' incorporates:
   *  Constant: '<S37>/offset2'
   *  Constant: '<S37>/offset3'
   *  Constant: '<S37>/offset4'
   *  RelationalOperator: '<S37>/Relational Operator'
   *  Sum: '<S37>/Add3'
   *  Sum: '<S37>/Add4'
   */
  if (localSaturation01_ku >= 0.0F) {
    localSaturation01_ku += 0.5F;
  } else {
    localSaturation01_ku -= 0.5F;
  }

  /* DataTypeConversion: '<S37>/OutDTConv' */
  if (localSaturation01_ku < 32768.0F) {
    if (localSaturation01_ku >= -32768.0F) {
      (*rty_ErrFil) = (SInt16)localSaturation01_ku;
    } else {
      (*rty_ErrFil) = MIN_int16_T;
    }
  } else {
    (*rty_ErrFil) = MAX_int16_T;
  }

  /* DataTypeConversion: '<S38>/OutDTConv' incorporates:
   *  Constant: '<S38>/offset'
   *  Constant: '<S38>/offset1'
   *  Constant: '<S38>/one_on_slope'
   *  Product: '<S38>/Product4'
   *  Sum: '<S38>/Add1'
   *  Sum: '<S38>/Add2'
   */
  locallocalAdd2_idx_2 = (0.125F * localSwitch_bq) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_pDsThrCo9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_pDsThrCo9) = 0U;
    }
  } else {
    (*rty_AFA_pDsThrCo9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S39>/OutDTConv' incorporates:
   *  Constant: '<S39>/offset'
   *  Constant: '<S39>/offset1'
   *  Constant: '<S39>/one_on_slope'
   *  Product: '<S39>/Product4'
   *  Sum: '<S39>/Add1'
   *  Sum: '<S39>/Add2'
   */
  locallocalAdd2_idx_2 = (1024.0F * localSwitch_lu) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_rOpSIFil8) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_rOpSIFil8) = 0U;
    }
  } else {
    (*rty_AFA_rOpSIFil8) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S40>/OutDTConv' incorporates:
   *  Constant: '<S40>/offset'
   *  Constant: '<S40>/offset1'
   *  Constant: '<S40>/one_on_slope'
   *  Product: '<S40>/Product4'
   *  Sum: '<S40>/Add1'
   *  Sum: '<S40>/Add2'
   */
  locallocalAdd2_idx_2 = (16384.0F * localSwitch_b) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_rAirLdC9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_rAirLdC9) = 0U;
    }
  } else {
    (*rty_AFA_rAirLdC9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S41>/OutDTConv' incorporates:
   *  Constant: '<S41>/offset'
   *  Constant: '<S41>/offset1'
   *  Constant: '<S41>/one_on_slope'
   *  Product: '<S41>/Product4'
   *  Sum: '<S41>/Add1'
   *  Sum: '<S41>/Add2'
   */
  locallocalAdd2_idx_2 = (64.0F * locallocalSwitch_a_idx) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp = (UInt32)locallocalAdd2_idx_2;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint32_T;
  }

  rty_AFA_prm_facGainInjFil_PIM1[0] = localtmp;
  locallocalAdd2_idx_2 = (64.0F * locallocalSwitch_a_idx_0) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp = (UInt32)locallocalAdd2_idx_2;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint32_T;
  }

  rty_AFA_prm_facGainInjFil_PIM1[1] = localtmp;
  locallocalAdd2_idx_2 = (64.0F * locallocalSwitch_a_idx_1) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp = (UInt32)locallocalAdd2_idx_2;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint32_T;
  }

  rty_AFA_prm_facGainInjFil_PIM1[2] = localtmp;
  locallocalAdd2_idx_2 = (64.0F * locallocalSwitch_a_idx_2) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp = (UInt32)locallocalAdd2_idx_2;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint32_T;
  }

  rty_AFA_prm_facGainInjFil_PIM1[3] = localtmp;

  /* DataTypeConversion: '<S42>/OutDTConv' incorporates:
   *  Constant: '<S42>/offset'
   *  Constant: '<S42>/offset1'
   *  Constant: '<S42>/one_on_slope'
   *  Product: '<S42>/Product4'
   *  Sum: '<S42>/Add1'
   *  Sum: '<S42>/Add2'
   */
  locallocalAdd2_idx_2 = (1.6777216E+007F * localSwitch_gs) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_arEffEGRV9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_arEffEGRV9) = 0U;
    }
  } else {
    (*rty_AFA_arEffEGRV9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S43>/OutDTConv' incorporates:
   *  Constant: '<S43>/offset'
   *  Constant: '<S43>/offset1'
   *  Constant: '<S43>/one_on_slope'
   *  Product: '<S43>/Product4'
   *  Sum: '<S43>/Add1'
   *  Sum: '<S43>/Add2'
   */
  locallocalAdd2_idx_2 = (4.294967296E+009F * localSwitch_i) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_facSlopEfc8) = (UInt32)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_facSlopEfc8) = 0U;
    }
  } else {
    (*rty_AFA_facSlopEfc8) = MAX_uint32_T;
  }

  /* DataTypeConversion: '<S44>/OutDTConv' incorporates:
   *  Constant: '<S44>/offset'
   *  Constant: '<S44>/offset1'
   *  Constant: '<S44>/one_on_slope'
   *  Product: '<S44>/Product4'
   *  Sum: '<S44>/Add1'
   *  Sum: '<S44>/Add2'
   */
  locallocalAdd2_idx_2 = localSwitch_o + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_nEngFil21) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_nEngFil21) = 0U;
    }
  } else {
    (*rty_AFA_nEngFil21) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S45>/OutDTConv' incorporates:
   *  Constant: '<S45>/offset'
   *  Constant: '<S45>/offset1'
   *  Constant: '<S45>/one_on_slope'
   *  Product: '<S45>/Product4'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Add2'
   */
  locallocalAdd2_idx_2 = (65536.0F * localSwitch_ju) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_rAirPre9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_rAirPre9) = 0U;
    }
  } else {
    (*rty_AFA_rAirPre9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S46>/OutDTConv' incorporates:
   *  Constant: '<S46>/offset'
   *  Constant: '<S46>/offset1'
   *  Constant: '<S46>/one_on_slope'
   *  Product: '<S46>/Product4'
   *  Sum: '<S46>/Add1'
   *  Sum: '<S46>/Add2'
   */
  locallocalAdd2_idx_2 = (32.0F * localSwitch_h) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_tExMnfEst89) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_tExMnfEst89) = 0U;
    }
  } else {
    (*rty_AFA_tExMnfEst89) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S47>/OutDTConv' incorporates:
   *  Constant: '<S47>/offset'
   *  Constant: '<S47>/offset1'
   *  Constant: '<S47>/one_on_slope'
   *  Product: '<S47>/Product4'
   *  Sum: '<S47>/Add1'
   *  Sum: '<S47>/Add2'
   */
  locallocalAdd2_idx_2 = (128.0F * localSwitch_p) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_tAirUsInVlvE45) = (UInt32)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_tAirUsInVlvE45) = 0U;
    }
  } else {
    (*rty_AFA_tAirUsInVlvE45) = MAX_uint32_T;
  }

  /* Product: '<S48>/Product4' incorporates:
   *  Constant: '<S48>/offset'
   *  Constant: '<S48>/one_on_slope'
   *  Sum: '<S48>/Add1'
   */
  localSaturation01_ku = 16.0F * localSwitch_k;

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/offset2'
   *  Constant: '<S48>/offset3'
   *  Constant: '<S48>/offset4'
   *  RelationalOperator: '<S48>/Relational Operator'
   *  Sum: '<S48>/Add3'
   *  Sum: '<S48>/Add4'
   */
  if (localSaturation01_ku >= 0.0F) {
    localSaturation01_ku += 0.5F;
  } else {
    localSaturation01_ku -= 0.5F;
  }

  /* DataTypeConversion: '<S48>/OutDTConv' */
  if (localSaturation01_ku < 32768.0F) {
    if (localSaturation01_ku >= -32768.0F) {
      (*rty_AFA_agCkClsExVlvEstim1) = (SInt16)localSaturation01_ku;
    } else {
      (*rty_AFA_agCkClsExVlvEstim1) = MIN_int16_T;
    }
  } else {
    (*rty_AFA_agCkClsExVlvEstim1) = MAX_int16_T;
  }

  /* Product: '<S49>/Product4' incorporates:
   *  Constant: '<S49>/offset'
   *  Constant: '<S49>/one_on_slope'
   *  Sum: '<S49>/Add1'
   */
  localSaturation01_ku = 16.0F * localSwitch_an;

  /* Switch: '<S49>/Switch1' incorporates:
   *  Constant: '<S49>/offset2'
   *  Constant: '<S49>/offset3'
   *  Constant: '<S49>/offset4'
   *  RelationalOperator: '<S49>/Relational Operator'
   *  Sum: '<S49>/Add3'
   *  Sum: '<S49>/Add4'
   */
  if (localSaturation01_ku >= 0.0F) {
    localSaturation01_ku += 0.5F;
  } else {
    localSaturation01_ku -= 0.5F;
  }

  /* DataTypeConversion: '<S49>/OutDTConv' */
  if (localSaturation01_ku < 32768.0F) {
    if (localSaturation01_ku >= -32768.0F) {
      (*rty_AFA_agCkOpInVlv8) = (SInt16)localSaturation01_ku;
    } else {
      (*rty_AFA_agCkOpInVlv8) = MIN_int16_T;
    }
  } else {
    (*rty_AFA_agCkOpInVlv8) = MAX_int16_T;
  }

  /* DataTypeConversion: '<S50>/OutDTConv' incorporates:
   *  Constant: '<S50>/offset'
   *  Constant: '<S50>/offset1'
   *  Constant: '<S50>/one_on_slope'
   *  Product: '<S50>/Product4'
   *  Sum: '<S50>/Add1'
   *  Sum: '<S50>/Add2'
   */
  locallocalAdd2_idx_2 = (16384.0F * localSwitch_bb) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_rTotLdEx5) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_rTotLdEx5) = 0U;
    }
  } else {
    (*rty_AFA_rTotLdEx5) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S51>/OutDTConv' incorporates:
   *  Constant: '<S51>/offset'
   *  Constant: '<S51>/offset1'
   *  Constant: '<S51>/one_on_slope'
   *  Product: '<S51>/Product4'
   *  Sum: '<S51>/Add1'
   *  Sum: '<S51>/Add2'
   */
  locallocalAdd2_idx_2 = (1.34217728E+008F * localSwitch_op) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_mFuReqFil23) = (UInt32)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_mFuReqFil23) = 0U;
    }
  } else {
    (*rty_AFA_mFuReqFil23) = MAX_uint32_T;
  }

  /* DataTypeConversion: '<S52>/OutDTConv' incorporates:
   *  Constant: '<S52>/offset'
   *  Constant: '<S52>/offset1'
   *  Constant: '<S52>/one_on_slope'
   *  Product: '<S52>/Product4'
   *  Sum: '<S52>/Add1'
   *  Sum: '<S52>/Add2'
   */
  locallocalAdd2_idx_2 = (0.125F * localSwitch_pr) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_pDsThrPred_facVlv4) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_pDsThrPred_facVlv4) = 0U;
    }
  } else {
    (*rty_AFA_pDsThrPred_facVlv4) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S53>/OutDTConv' incorporates:
   *  Constant: '<S53>/offset'
   *  Constant: '<S53>/offset1'
   *  Constant: '<S53>/one_on_slope'
   *  Product: '<S53>/Product4'
   *  Sum: '<S53>/Add1'
   *  Sum: '<S53>/Add2'
   */
  locallocalAdd2_idx_2 = (0.125F * localSwitch_os) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_pUsThrCorFil4) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_pUsThrCorFil4) = 0U;
    }
  } else {
    (*rty_AFA_pUsThrCorFil4) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S54>/OutDTConv' incorporates:
   *  Constant: '<S54>/offset'
   *  Constant: '<S54>/offset1'
   *  Constant: '<S54>/one_on_slope'
   *  Product: '<S54>/Product4'
   *  Sum: '<S54>/Add1'
   *  Sum: '<S54>/Add2'
   */
  locallocalAdd2_idx_2 = localSwitch + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_nEngCorFil) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_nEngCorFil) = 0U;
    }
  } else {
    (*rty_AFA_nEngCorFil) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S55>/OutDTConv' incorporates:
   *  Constant: '<S55>/offset'
   *  Constant: '<S55>/offset1'
   *  Constant: '<S55>/one_on_slope'
   *  Product: '<S55>/Product4'
   *  Sum: '<S55>/Add1'
   *  Sum: '<S55>/Add2'
   */
  locallocalAdd2_idx_2 = (16.0F * localSwitch_l) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_agCkClsInVlvEstimRe8) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_agCkClsInVlvEstimRe8) = 0U;
    }
  } else {
    (*rty_AFA_agCkClsInVlvEstimRe8) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S56>/OutDTConv' incorporates:
   *  Constant: '<S56>/offset'
   *  Constant: '<S56>/offset1'
   *  Constant: '<S56>/one_on_slope'
   *  Product: '<S56>/Product4'
   *  Sum: '<S56>/Add1'
   *  Sum: '<S56>/Add2'
   */
  locallocalAdd2_idx_2 = (1.6777216E+007F * localSwitch_g) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_arEffAdpT9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_arEffAdpT9) = 0U;
    }
  } else {
    (*rty_AFA_arEffAdpT9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S57>/OutDTConv' incorporates:
   *  Constant: '<S57>/offset'
   *  Constant: '<S57>/offset1'
   *  Constant: '<S57>/one_on_slope'
   *  Product: '<S57>/Product4'
   *  Sum: '<S57>/Add1'
   *  Sum: '<S57>/Add2'
   */
  locallocalAdd2_idx_2 = (128.0F * localSwitch_e) + 0.5F;
  if (locallocalAdd2_idx_2 < 256.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_facRhoFuFil1) = (UInt8)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_facRhoFuFil1) = 0U;
    }
  } else {
    (*rty_AFA_facRhoFuFil1) = MAX_uint8_T;
  }

  /* DataTypeConversion: '<S58>/OutDTConv' incorporates:
   *  Constant: '<S58>/offset'
   *  Constant: '<S58>/offset1'
   *  Constant: '<S58>/one_on_slope'
   *  Product: '<S58>/Product4'
   *  Sum: '<S58>/Add1'
   *  Sum: '<S58>/Add2'
   */
  locallocalAdd2_idx_2 = (1.6777216E+007F * localSwitch_n) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_arEffAdpEGR9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_arEffAdpEGR9) = 0U;
    }
  } else {
    (*rty_AFA_arEffAdpEGR9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S59>/OutDTConv' incorporates:
   *  Constant: '<S59>/offset'
   *  Constant: '<S59>/offset1'
   *  Constant: '<S59>/one_on_slope'
   *  Product: '<S59>/Product4'
   *  Sum: '<S59>/Add1'
   *  Sum: '<S59>/Add2'
   */
  locallocalAdd2_idx_2 = (65536.0F * localSwitch_fd2) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_rInMassFlo9) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_rInMassFlo9) = 0U;
    }
  } else {
    (*rty_AFA_rInMassFlo9) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S60>/OutDTConv' incorporates:
   *  Constant: '<S60>/offset'
   *  Constant: '<S60>/offset1'
   *  Constant: '<S60>/one_on_slope'
   *  Product: '<S60>/Product4'
   *  Sum: '<S60>/Add1'
   *  Sum: '<S60>/Add2'
   */
  locallocalAdd2_idx_2 = (32768.0F * localSwitch_dv) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      (*rty_AFA_rEthStoichFil1) = (UInt16)locallocalAdd2_idx_2;
    } else {
      (*rty_AFA_rEthStoichFil1) = 0U;
    }
  } else {
    (*rty_AFA_rEthStoichFil1) = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S61>/OutDTConv' incorporates:
   *  Constant: '<S61>/offset'
   *  Constant: '<S61>/offset1'
   *  Constant: '<S61>/one_on_slope'
   *  Product: '<S61>/Product4'
   *  Sum: '<S61>/Add1'
   *  Sum: '<S61>/Add2'
   */
  locallocalAdd2_idx_2 = (32768.0F * locallocalSwitch_f1_idx) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp_0 = (UInt16)locallocalAdd2_idx_2;
    } else {
      localtmp_0 = 0U;
    }
  } else {
    localtmp_0 = MAX_uint16_T;
  }

  rty_AFA_prm_facCorG[0] = localtmp_0;

  /* DataTypeConversion: '<S62>/OutDTConv' incorporates:
   *  Constant: '<S62>/offset'
   *  Constant: '<S62>/offset1'
   *  Constant: '<S62>/one_on_slope'
   *  Product: '<S62>/Product4'
   *  Sum: '<S62>/Add1'
   *  Sum: '<S62>/Add2'
   */
  locallocalAdd2_idx_2 = (0.001953125F * locallocalSwitch_ij_idx) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp = (UInt32)locallocalAdd2_idx_2;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint32_T;
  }

  rty_AFA_prm_pDifInjrFil_PIM1[0] = localtmp;

  /* DataTypeConversion: '<S61>/OutDTConv' incorporates:
   *  Constant: '<S61>/offset'
   *  Constant: '<S61>/offset1'
   *  Constant: '<S61>/one_on_slope'
   *  Product: '<S61>/Product4'
   *  Sum: '<S61>/Add1'
   *  Sum: '<S61>/Add2'
   */
  locallocalAdd2_idx_2 = (32768.0F * locallocalSwitch_f1_idx_0) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp_0 = (UInt16)locallocalAdd2_idx_2;
    } else {
      localtmp_0 = 0U;
    }
  } else {
    localtmp_0 = MAX_uint16_T;
  }

  rty_AFA_prm_facCorG[1] = localtmp_0;

  /* DataTypeConversion: '<S62>/OutDTConv' incorporates:
   *  Constant: '<S62>/offset'
   *  Constant: '<S62>/offset1'
   *  Constant: '<S62>/one_on_slope'
   *  Product: '<S62>/Product4'
   *  Sum: '<S62>/Add1'
   *  Sum: '<S62>/Add2'
   */
  locallocalAdd2_idx_2 = (0.001953125F * locallocalSwitch_ij_idx_0) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp = (UInt32)locallocalAdd2_idx_2;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint32_T;
  }

  rty_AFA_prm_pDifInjrFil_PIM1[1] = localtmp;

  /* DataTypeConversion: '<S61>/OutDTConv' incorporates:
   *  Constant: '<S61>/offset'
   *  Constant: '<S61>/offset1'
   *  Constant: '<S61>/one_on_slope'
   *  Product: '<S61>/Product4'
   *  Sum: '<S61>/Add1'
   *  Sum: '<S61>/Add2'
   */
  locallocalAdd2_idx_2 = (32768.0F * locallocalSwitch_f1_idx_1) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp_0 = (UInt16)locallocalAdd2_idx_2;
    } else {
      localtmp_0 = 0U;
    }
  } else {
    localtmp_0 = MAX_uint16_T;
  }

  rty_AFA_prm_facCorG[2] = localtmp_0;

  /* DataTypeConversion: '<S62>/OutDTConv' incorporates:
   *  Constant: '<S62>/offset'
   *  Constant: '<S62>/offset1'
   *  Constant: '<S62>/one_on_slope'
   *  Product: '<S62>/Product4'
   *  Sum: '<S62>/Add1'
   *  Sum: '<S62>/Add2'
   */
  locallocalAdd2_idx_2 = (0.001953125F * locallocalSwitch_ij_idx_1) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp = (UInt32)locallocalAdd2_idx_2;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint32_T;
  }

  rty_AFA_prm_pDifInjrFil_PIM1[2] = localtmp;

  /* DataTypeConversion: '<S61>/OutDTConv' incorporates:
   *  Constant: '<S61>/offset'
   *  Constant: '<S61>/offset1'
   *  Constant: '<S61>/one_on_slope'
   *  Product: '<S61>/Product4'
   *  Sum: '<S61>/Add1'
   *  Sum: '<S61>/Add2'
   */
  locallocalAdd2_idx_2 = (32768.0F * locallocalSwitch_f1_idx_2) + 0.5F;
  if (locallocalAdd2_idx_2 < 65536.0F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp_0 = (UInt16)locallocalAdd2_idx_2;
    } else {
      localtmp_0 = 0U;
    }
  } else {
    localtmp_0 = MAX_uint16_T;
  }

  rty_AFA_prm_facCorG[3] = localtmp_0;

  /* DataTypeConversion: '<S62>/OutDTConv' incorporates:
   *  Constant: '<S62>/offset'
   *  Constant: '<S62>/offset1'
   *  Constant: '<S62>/one_on_slope'
   *  Product: '<S62>/Product4'
   *  Sum: '<S62>/Add1'
   *  Sum: '<S62>/Add2'
   */
  locallocalAdd2_idx_2 = (0.001953125F * locallocalSwitch_ij_idx_2) + 0.5F;
  if (locallocalAdd2_idx_2 < 4.294967296E+009F) {
    if (locallocalAdd2_idx_2 >= 0.0F) {
      localtmp = (UInt32)locallocalAdd2_idx_2;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint32_T;
  }

  rty_AFA_prm_pDifInjrFil_PIM1[3] = localtmp;

  /* Switch: '<S63>/Switch1' incorporates:
   *  Constant: '<S63>/offset'
   *  Constant: '<S63>/offset2'
   *  Constant: '<S63>/offset3'
   *  Constant: '<S63>/offset4'
   *  Constant: '<S63>/one_on_slope'
   *  Product: '<S63>/Product4'
   *  RelationalOperator: '<S63>/Relational Operator'
   *  Sum: '<S63>/Add1'
   *  Sum: '<S63>/Add3'
   *  Sum: '<S63>/Add4'
   */
  if (localSwitch_ou >= 0.0F) {
    localSaturation01_ku = localSwitch_ou + 0.5F;
  } else {
    localSaturation01_ku = localSwitch_ou - 0.5F;
  }

  /* DataTypeConversion: '<S63>/OutDTConv' */
  if (localSaturation01_ku < 32768.0F) {
    if (localSaturation01_ku >= -32768.0F) {
      (*rty_AFA_tCoMes8) = (SInt16)localSaturation01_ku;
    } else {
      (*rty_AFA_tCoMes8) = MIN_int16_T;
    }
  } else {
    (*rty_AFA_tCoMes8) = MAX_int16_T;
  }

  /* Update for UnitDelay: '<S66>/UnitDelay' */
  localDW->UnitDelay = localSum1;

  /* Update for UnitDelay: '<S66>/UnitDelay1' incorporates:
   *  Constant: '<S66>/Constant3'
   */
  localDW->UnitDelay_b2 = TRUE;

  /* Update for UnitDelay: '<S64>/UnitDelay' incorporates:
   *  Constant: '<S64>/Constant3'
   */
  localDW->UnitDelay_DSTATE = TRUE;

  /* Update for UnitDelay: '<S70>/UnitDelay' */
  localDW->UnitDelay_h = localSum1_o;

  /* Update for UnitDelay: '<S70>/UnitDelay1' incorporates:
   *  Constant: '<S70>/Constant3'
   */
  localDW->UnitDelay_pt = TRUE;

  /* Update for UnitDelay: '<S68>/UnitDelay' incorporates:
   *  Constant: '<S68>/Constant3'
   */
  localDW->UnitDelay_DSTATE_g = TRUE;

  /* Update for UnitDelay: '<S74>/UnitDelay' */
  localDW->UnitDelay_o = localSum1_k;

  /* Update for UnitDelay: '<S74>/UnitDelay1' incorporates:
   *  Constant: '<S74>/Constant3'
   */
  localDW->UnitDelay_hpy = TRUE;

  /* Update for UnitDelay: '<S72>/UnitDelay' incorporates:
   *  Constant: '<S72>/Constant3'
   */
  localDW->UnitDelay_DSTATE_c = TRUE;

  /* Update for UnitDelay: '<S78>/UnitDelay' */
  localDW->UnitDelay_n = localSum1_p;

  /* Update for UnitDelay: '<S78>/UnitDelay1' incorporates:
   *  Constant: '<S78>/Constant3'
   */
  localDW->UnitDelay_k4 = TRUE;

  /* Update for UnitDelay: '<S76>/UnitDelay' incorporates:
   *  Constant: '<S76>/Constant3'
   */
  localDW->UnitDelay_DSTATE_f = TRUE;

  /* Update for UnitDelay: '<S82>/UnitDelay' */
  localDW->UnitDelay_h4 = localSum1_l;

  /* Update for UnitDelay: '<S82>/UnitDelay1' incorporates:
   *  Constant: '<S82>/Constant3'
   */
  localDW->UnitDelay_psn = TRUE;

  /* Update for UnitDelay: '<S80>/UnitDelay' incorporates:
   *  Constant: '<S80>/Constant3'
   */
  localDW->UnitDelay_DSTATE_p = TRUE;

  /* Update for UnitDelay: '<S86>/UnitDelay' */
  localDW->UnitDelay_l = localSum1_c;

  /* Update for UnitDelay: '<S86>/UnitDelay1' incorporates:
   *  Constant: '<S86>/Constant3'
   */
  localDW->UnitDelay_hh = TRUE;

  /* Update for UnitDelay: '<S84>/UnitDelay' incorporates:
   *  Constant: '<S84>/Constant3'
   */
  localDW->UnitDelay_DSTATE_k = TRUE;

  /* Update for UnitDelay: '<S90>/UnitDelay' */
  localDW->UnitDelay_a = localSum1_ln;

  /* Update for UnitDelay: '<S90>/UnitDelay1' incorporates:
   *  Constant: '<S90>/Constant3'
   */
  localDW->UnitDelay_ib = TRUE;

  /* Update for UnitDelay: '<S88>/UnitDelay' incorporates:
   *  Constant: '<S88>/Constant3'
   */
  localDW->UnitDelay_DSTATE_c1 = TRUE;

  /* Update for UnitDelay: '<S94>/UnitDelay' */
  localDW->UnitDelay_os = localSum1_kx;

  /* Update for UnitDelay: '<S94>/UnitDelay1' incorporates:
   *  Constant: '<S94>/Constant3'
   */
  localDW->UnitDelay_gi = TRUE;

  /* Update for UnitDelay: '<S92>/UnitDelay' incorporates:
   *  Constant: '<S92>/Constant3'
   */
  localDW->UnitDelay_DSTATE_b = TRUE;

  /* Update for UnitDelay: '<S98>/UnitDelay1' incorporates:
   *  Constant: '<S98>/Constant3'
   */
  localDW->UnitDelay_hf = TRUE;

  /* Update for UnitDelay: '<S96>/UnitDelay' incorporates:
   *  Constant: '<S96>/Constant3'
   */
  localDW->UnitDelay_DSTATE_a = TRUE;

  /* Update for UnitDelay: '<S102>/UnitDelay' */
  localDW->UnitDelay_ol = localSum1_d3;

  /* Update for UnitDelay: '<S102>/UnitDelay1' incorporates:
   *  Constant: '<S102>/Constant3'
   */
  localDW->UnitDelay_p0 = TRUE;

  /* Update for UnitDelay: '<S100>/UnitDelay' incorporates:
   *  Constant: '<S100>/Constant3'
   */
  localDW->UnitDelay_DSTATE_j = TRUE;

  /* Update for UnitDelay: '<S106>/UnitDelay' */
  localDW->UnitDelay_nr = localSum1_f;

  /* Update for UnitDelay: '<S106>/UnitDelay1' incorporates:
   *  Constant: '<S106>/Constant3'
   */
  localDW->UnitDelay_f4 = TRUE;

  /* Update for UnitDelay: '<S104>/UnitDelay' incorporates:
   *  Constant: '<S104>/Constant3'
   */
  localDW->UnitDelay_DSTATE_jg = TRUE;

  /* Update for UnitDelay: '<S110>/UnitDelay' */
  localDW->UnitDelay_hv = localSum1_g;

  /* Update for UnitDelay: '<S110>/UnitDelay1' incorporates:
   *  Constant: '<S110>/Constant3'
   */
  localDW->UnitDelay_ip = TRUE;

  /* Update for UnitDelay: '<S108>/UnitDelay' incorporates:
   *  Constant: '<S108>/Constant3'
   */
  localDW->UnitDelay_DSTATE_fm = TRUE;

  /* Update for UnitDelay: '<S114>/UnitDelay' */
  localDW->UnitDelay_k = localSum1_oy;

  /* Update for UnitDelay: '<S114>/UnitDelay1' incorporates:
   *  Constant: '<S114>/Constant3'
   */
  localDW->UnitDelay_gl = TRUE;

  /* Update for UnitDelay: '<S112>/UnitDelay' incorporates:
   *  Constant: '<S112>/Constant3'
   */
  localDW->UnitDelay_DSTATE_bd = TRUE;

  /* Update for UnitDelay: '<S118>/UnitDelay' */
  localDW->UnitDelay_ky = localSum1_j;

  /* Update for UnitDelay: '<S118>/UnitDelay1' incorporates:
   *  Constant: '<S118>/Constant3'
   */
  localDW->UnitDelay_jj = TRUE;

  /* Update for UnitDelay: '<S116>/UnitDelay' incorporates:
   *  Constant: '<S116>/Constant3'
   */
  localDW->UnitDelay_DSTATE_ku = TRUE;

  /* Update for UnitDelay: '<S122>/UnitDelay' */
  localDW->UnitDelay_j = localSum1_a;

  /* Update for UnitDelay: '<S122>/UnitDelay1' incorporates:
   *  Constant: '<S122>/Constant3'
   */
  localDW->UnitDelay_psh = TRUE;

  /* Update for UnitDelay: '<S120>/UnitDelay' incorporates:
   *  Constant: '<S120>/Constant3'
   */
  localDW->UnitDelay_DSTATE_ai = TRUE;

  /* Update for UnitDelay: '<S126>/UnitDelay' */
  localDW->UnitDelay_i = localSum1_h;

  /* Update for UnitDelay: '<S126>/UnitDelay1' incorporates:
   *  Constant: '<S126>/Constant3'
   */
  localDW->UnitDelay_ko = TRUE;

  /* Update for UnitDelay: '<S124>/UnitDelay' incorporates:
   *  Constant: '<S124>/Constant3'
   */
  localDW->UnitDelay_DSTATE_d = TRUE;

  /* Update for UnitDelay: '<S130>/UnitDelay' */
  localDW->UnitDelay_iu = localSum1_m;

  /* Update for UnitDelay: '<S130>/UnitDelay1' incorporates:
   *  Constant: '<S130>/Constant3'
   */
  localDW->UnitDelay_ll = TRUE;

  /* Update for UnitDelay: '<S128>/UnitDelay' incorporates:
   *  Constant: '<S128>/Constant3'
   */
  localDW->UnitDelay_DSTATE_px = TRUE;

  /* Update for UnitDelay: '<S134>/UnitDelay' */
  localDW->UnitDelay_g = localSum1_b;

  /* Update for UnitDelay: '<S134>/UnitDelay1' incorporates:
   *  Constant: '<S134>/Constant3'
   */
  localDW->UnitDelay_fn = TRUE;

  /* Update for UnitDelay: '<S132>/UnitDelay' incorporates:
   *  Constant: '<S132>/Constant3'
   */
  localDW->UnitDelay_DSTATE_b3 = TRUE;

  /* Update for UnitDelay: '<S138>/UnitDelay' */
  localDW->UnitDelay_e = localSum1_p3;

  /* Update for UnitDelay: '<S138>/UnitDelay1' incorporates:
   *  Constant: '<S138>/Constant3'
   */
  localDW->UnitDelay_d = TRUE;

  /* Update for UnitDelay: '<S136>/UnitDelay' incorporates:
   *  Constant: '<S136>/Constant3'
   */
  localDW->UnitDelay_DSTATE_l = TRUE;

  /* Update for UnitDelay: '<S142>/UnitDelay' */
  localDW->UnitDelay_oo = localSum1_af;

  /* Update for UnitDelay: '<S142>/UnitDelay1' incorporates:
   *  Constant: '<S142>/Constant3'
   */
  localDW->UnitDelay_iy = TRUE;

  /* Update for UnitDelay: '<S140>/UnitDelay' incorporates:
   *  Constant: '<S140>/Constant3'
   */
  localDW->UnitDelay_DSTATE_l1 = TRUE;

  /* Update for UnitDelay: '<S146>/UnitDelay' */
  localDW->UnitDelay_p = localSum1_n;

  /* Update for UnitDelay: '<S146>/UnitDelay1' incorporates:
   *  Constant: '<S146>/Constant3'
   */
  localDW->UnitDelay_lv = TRUE;

  /* Update for UnitDelay: '<S144>/UnitDelay' incorporates:
   *  Constant: '<S144>/Constant3'
   */
  localDW->UnitDelay_DSTATE_ap = TRUE;

  /* Update for UnitDelay: '<S150>/UnitDelay' */
  localDW->UnitDelay_i2 = localSum1_cs;

  /* Update for UnitDelay: '<S150>/UnitDelay1' incorporates:
   *  Constant: '<S150>/Constant3'
   */
  localDW->UnitDelay_h1 = TRUE;

  /* Update for UnitDelay: '<S148>/UnitDelay' incorporates:
   *  Constant: '<S148>/Constant3'
   */
  localDW->UnitDelay_DSTATE_dx = TRUE;

  /* Update for UnitDelay: '<S154>/UnitDelay' */
  localDW->UnitDelay_eh = localSum1_o3;

  /* Update for UnitDelay: '<S154>/UnitDelay1' incorporates:
   *  Constant: '<S154>/Constant3'
   */
  localDW->UnitDelay_h3 = TRUE;

  /* Update for UnitDelay: '<S152>/UnitDelay' incorporates:
   *  Constant: '<S152>/Constant3'
   */
  localDW->UnitDelay_DSTATE_gx = TRUE;

  /* Update for UnitDelay: '<S158>/UnitDelay' */
  localDW->UnitDelay_g0 = localSum1_ds;

  /* Update for UnitDelay: '<S158>/UnitDelay1' incorporates:
   *  Constant: '<S158>/Constant3'
   */
  localDW->UnitDelay_ea = TRUE;

  /* Update for UnitDelay: '<S156>/UnitDelay' incorporates:
   *  Constant: '<S156>/Constant3'
   */
  localDW->UnitDelay_DSTATE_m = TRUE;

  /* Update for UnitDelay: '<S162>/UnitDelay' */
  localDW->UnitDelay_ps = localSum1_by;

  /* Update for UnitDelay: '<S162>/UnitDelay1' incorporates:
   *  Constant: '<S162>/Constant3'
   */
  localDW->UnitDelay_hs = TRUE;

  /* Update for UnitDelay: '<S160>/UnitDelay' incorporates:
   *  Constant: '<S160>/Constant3'
   */
  localDW->UnitDelay_DSTATE_e = TRUE;

  /* Update for UnitDelay: '<S166>/UnitDelay' */
  localDW->UnitDelay_b = localSum1_ky;

  /* Update for UnitDelay: '<S166>/UnitDelay1' incorporates:
   *  Constant: '<S166>/Constant3'
   */
  localDW->UnitDelay_he = TRUE;

  /* Update for UnitDelay: '<S164>/UnitDelay' incorporates:
   *  Constant: '<S164>/Constant3'
   */
  localDW->UnitDelay_DSTATE_n = TRUE;

  /* Update for UnitDelay: '<S170>/UnitDelay' */
  localDW->UnitDelay_mx = localSum1_p5;

  /* Update for UnitDelay: '<S170>/UnitDelay1' incorporates:
   *  Constant: '<S170>/Constant3'
   */
  localDW->UnitDelay_g5 = TRUE;

  /* Update for UnitDelay: '<S168>/UnitDelay' incorporates:
   *  Constant: '<S168>/Constant3'
   */
  localDW->UnitDelay_DSTATE_c0 = TRUE;

  /* Update for UnitDelay: '<S174>/UnitDelay' */
  localDW->UnitDelay_n5 = localSum1_pg;

  /* Update for UnitDelay: '<S174>/UnitDelay1' incorporates:
   *  Constant: '<S174>/Constant3'
   */
  localDW->UnitDelay_hz = TRUE;

  /* Update for UnitDelay: '<S172>/UnitDelay' incorporates:
   *  Constant: '<S172>/Constant3'
   */
  localDW->UnitDelay_DSTATE_ef = TRUE;

  /* Update for UnitDelay: '<S178>/UnitDelay1' incorporates:
   *  Constant: '<S178>/Constant3'
   */
  localDW->UnitDelay_i2k = TRUE;

  /* Update for UnitDelay: '<S176>/UnitDelay' incorporates:
   *  Constant: '<S176>/Constant3'
   */
  localDW->UnitDelay_DSTATE_i = TRUE;

  /* Update for UnitDelay: '<S98>/UnitDelay' */
  localDW->UnitDelay_m[0] = locallocalSum1_d_idx;

  /* Update for UnitDelay: '<S178>/UnitDelay' */
  localDW->UnitDelay_hp[0] = locallocalSum1_e_idx;

  /* Update for UnitDelay: '<S182>/UnitDelay' */
  localDW->UnitDelay_f[0] = locallocalAdd2_idx;

  /* Update for UnitDelay: '<S98>/UnitDelay' */
  localDW->UnitDelay_m[1] = locallocalSum1_d_idx_0;

  /* Update for UnitDelay: '<S178>/UnitDelay' */
  localDW->UnitDelay_hp[1] = locallocalSum1_e_idx_0;

  /* Update for UnitDelay: '<S182>/UnitDelay' */
  localDW->UnitDelay_f[1] = locallocalAdd2_idx_0;

  /* Update for UnitDelay: '<S98>/UnitDelay' */
  localDW->UnitDelay_m[2] = locallocalSum1_d_idx_1;

  /* Update for UnitDelay: '<S178>/UnitDelay' */
  localDW->UnitDelay_hp[2] = locallocalSum1_e_idx_1;

  /* Update for UnitDelay: '<S182>/UnitDelay' */
  localDW->UnitDelay_f[2] = locallocalAdd2_idx_1;

  /* Update for UnitDelay: '<S98>/UnitDelay' */
  localDW->UnitDelay_m[3] = locallocalSum1_d_idx_2;

  /* Update for UnitDelay: '<S178>/UnitDelay' */
  localDW->UnitDelay_hp[3] = locallocalSum1_e_idx_2;

  /* Update for UnitDelay: '<S182>/UnitDelay' */
  localDW->UnitDelay_f[3] = locallocalAdd;

  /* Update for UnitDelay: '<S182>/UnitDelay1' incorporates:
   *  Constant: '<S182>/Constant3'
   */
  localDW->UnitDelay_eo = TRUE;

  /* Update for UnitDelay: '<S180>/UnitDelay' incorporates:
   *  Constant: '<S180>/Constant3'
   */
  localDW->UnitDelay_DSTATE_c0p = TRUE;

  /* Update for UnitDelay: '<S186>/UnitDelay' */
  localDW->UnitDelay_lk = localDataTypeConversion109;

  /* Update for UnitDelay: '<S186>/UnitDelay1' incorporates:
   *  Constant: '<S186>/Constant3'
   */
  localDW->UnitDelay_al = TRUE;

  /* Update for UnitDelay: '<S184>/UnitDelay' incorporates:
   *  Constant: '<S184>/Constant3'
   */
  localDW->UnitDelay_DSTATE_me = TRUE;
}

/* Model initialize function */
void mr_AFA_F02_inputs_fi_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
