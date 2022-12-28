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
/* !File            : AFA_F01_init_inputs_filters.c                           */
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
/*   Model name       : AFA_F01_init_inputs_filters.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_init_inputs_filters.h"
#include "AFA_F01_init_inputs_filters_private.h"
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

/* Output and update for referenced model: 'AFA_F01_init_inputs_filters' */
void mr_AFA_F01_init_inputs_filters(const UInt16 *rtu_InM_pDsThrPred_43, const
  UInt16 *rtu_InM_rAirPres_42, const UInt16 *rtu_InM_arEffAdpThr_41, const
  UInt16 *rtu_InM_arEffAdpEGRVlv_40, const UInt16 *rtu_InM_arEffEGRVlv_39,
  const UInt16 rtu_InjrM_prm_facGainInj33[4], const UInt16
  *rtu_EngM_rAirLdCor_37, const UInt16 *rtu_ThrLrn_rOpSI_36, const UInt16
  *rtu_InM_pDsThrCor_35, const SInt16 *rtu_InM_pDsThrEstimErr_34, const
  UInt16 *rtu_ExM_pExMnfEstim_33, const UInt16 *rtu_EngM_facSlopEfcCor_32,
  const UInt16 *rtu_ExM_tExMnfEstim_31, const UInt16 *rtu_Ext_nEng66, const
  UInt16 *rtu_InThM_tAirUsIn_20, const SInt16 *rtu_EngM_agCkCls_22, const
  SInt16 *rtu_EngM_agCkOp_23, const UInt16 *rtu_EngM_rTotLd_24, const
  UInt16 *rtu_EngM_agCkClsI_25, const UInt16 *rtu_UsThrM_pAirExt_25, const
  UInt32 *rtu_InjSys_mFuReq_22, const UInt16 rtu_InjrM_prm_facCor85[4],
  const SInt16 *rtu_Ext_tCoMes_29, const UInt16 *rtu_InM_pDsThrPred_001,
  const UInt32 *rtu_InM_pDsThrEs_21, const UInt16 *rtu_UsThrM_pUsThrCor_30,
  const UInt16 rtu_InjrM_prm_pDifInjr55[4], const UInt16 *rtu_InThM_nEngCor,
  const UInt16 *rtu_AfuA_rEthStoich, const UInt8 *rtu_Ext_facRhoFu, UInt16
  *rty_AFA_pDsThrPredFil_44, UInt16 *rty_AFA_rAirPresFil_45, UInt16
  *rty_AFA_arEffAdpThrFil_46, UInt16 *rty_AFA_arEffAdpEGR_01, UInt16
  *rty_AFA_arEffEGR_09, UInt16 *rty_AFA_rInMassF_001, UInt32
  rty_AFA_prm_facGainInjFil_PIM[4], UInt16 *rty_AFA_rAirLdCorFil_42, UInt16 *
  rty_AFA_rOpSIFil_43, UInt16 *rty_AFA_pDsThrCorFil_44, SInt16
  *rty_AFA_pDsThrEstim_002, UInt16 *rty_AFA_pExMnfEstim_11, UInt32
  *rty_AFA_facSlopEfcCor_10, UInt16 *rty_AFA_tExMnfEstim_12, UInt16
  *rty_AFA_nEngFil11, UInt32 *rty_AFA_tAirUsInVlv_02, SInt16
  *rty_AFA_agCkClsExVlv_04, SInt16 *rty_AFA_agCkOpInVlv_05, UInt16
  *rty_AFA_rTotLdExCor_06, UInt16 *rty_AFA_agCkClsInVlv_07, UInt16
  *rty_AFA_pAirExtEstim_08, UInt32 *rty_AFA_mFuReqFil12, UInt16
  rty_AFA_prm_facCorG[4], SInt16 *rty_AFA_tCoMesFil_46, UInt16
  *rty_AFA_pDsThrPred_001, UInt16 *rty_AFA_pDsThrEstim_03, UInt16
  *rty_AFA_pUsThrCorFil_47, UInt32 rty_AFA_prm_pDifInjrFil_PIM[4], UInt16
  *rty_AFA_nEngCorFil, UInt16 *rty_AFA_rEthStoichFil, UInt8
  *rty_AFA_facRhoFuFil)
{
  SInt32 localq;
  UInt32 localqY;

  /* SignalConversion: '<Root>/Signal Conversion26' */
  (*rty_AFA_pDsThrPredFil_44) = (*rtu_InM_pDsThrPred_43);

  /* SignalConversion: '<Root>/Signal Conversion1' */
  (*rty_AFA_rAirPresFil_45) = (*rtu_InM_rAirPres_42);

  /* SignalConversion: '<Root>/Signal Conversion2' */
  (*rty_AFA_arEffAdpThrFil_46) = (*rtu_InM_arEffAdpThr_41);

  /* SignalConversion: '<Root>/Signal Conversion3' */
  (*rty_AFA_arEffAdpEGR_01) = (*rtu_InM_arEffAdpEGRVlv_40);

  /* SignalConversion: '<Root>/Signal Conversion4' */
  (*rty_AFA_arEffEGR_09) = (*rtu_InM_arEffEGRVlv_39);

  /* Constant: '<Root>/Constant' */
  (*rty_AFA_rInMassF_001) = 0U;

  /* SignalConversion: '<Root>/Signal Conversion7' */
  (*rty_AFA_rAirLdCorFil_42) = (*rtu_EngM_rAirLdCor_37);

  /* SignalConversion: '<Root>/Signal Conversion8' */
  (*rty_AFA_rOpSIFil_43) = (*rtu_ThrLrn_rOpSI_36);

  /* SignalConversion: '<Root>/Signal Conversion9' */
  (*rty_AFA_pDsThrCorFil_44) = (*rtu_InM_pDsThrCor_35);

  /* SignalConversion: '<Root>/Signal Conversion10' */
  (*rty_AFA_pDsThrEstim_002) = (*rtu_InM_pDsThrEstimErr_34);

  /* SignalConversion: '<Root>/Signal Conversion11' */
  (*rty_AFA_pExMnfEstim_11) = (*rtu_ExM_pExMnfEstim_33);

  /* DataTypeConversion: '<Root>/Data Type Cnversion1' */
  (*rty_AFA_facSlopEfcCor_10) = ((((UInt32)(*rtu_EngM_facSlopEfcCor_32)) *
    47245U) >> 15);

  /* DataTypeConversion: '<Root>/Data Type Cnversion2' */
  localqY = (UInt32)((*rtu_ExM_tExMnfEstim_31) + 7136);
  if (localqY > 65535U) {
    (*rty_AFA_tExMnfEstim_12) = MAX_uint16_T;
  } else {
    (*rty_AFA_tExMnfEstim_12) = (UInt16)localqY;
  }

  /* SignalConversion: '<Root>/Signal Conversion16' */
  (*rty_AFA_nEngFil11) = (*rtu_Ext_nEng66);

  /* DataTypeConversion: '<Root>/Data Type Cnversion4' */
  localq = (*rtu_InThM_tAirUsIn_20);
  localqY = (UInt32)(localq + 28544);
  if (localqY < ((UInt32)localq)) {
    localqY = MAX_uint32_T;
  }

  (*rty_AFA_tAirUsInVlv_02) = localqY;

  /* DataTypeConversion: '<Root>/Data Type Cnversion5' */
  localq = (*rtu_EngM_agCkCls_22) * 3;
  localq += (localq < 0);
  localq = (localq >= 0) ? ((SInt32)(((UInt32)localq) >> 1U)) : (~((SInt32)
    (((UInt32)(~localq)) >> 1U)));
  if (localq > 32767) {
    (*rty_AFA_agCkClsExVlv_04) = MAX_int16_T;
  } else if (localq <= -32768) {
    (*rty_AFA_agCkClsExVlv_04) = MIN_int16_T;
  } else {
    (*rty_AFA_agCkClsExVlv_04) = (SInt16)localq;
  }

  /* DataTypeConversion: '<Root>/Data Type Cnversion6' */
  localq = (*rtu_EngM_agCkOp_23) * 3;
  localq += (localq < 0);
  localq = (localq >= 0) ? ((SInt32)(((UInt32)localq) >> 1U)) : (~((SInt32)
    (((UInt32)(~localq)) >> 1U)));
  if (localq > 32767) {
    (*rty_AFA_agCkOpInVlv_05) = MAX_int16_T;
  } else if (localq <= -32768) {
    (*rty_AFA_agCkOpInVlv_05) = MIN_int16_T;
  } else {
    (*rty_AFA_agCkOpInVlv_05) = (SInt16)localq;
  }

  /* SignalConversion: '<Root>/Signal Conversion21' */
  (*rty_AFA_rTotLdExCor_06) = (*rtu_EngM_rTotLd_24);

  /* DataTypeConversion: '<Root>/Data Type Cnversion7' */
  localqY = (UInt32)((SInt32)(((UInt32)(((*rtu_EngM_agCkClsI_25) * 3) +
    2688)) >> 1));
  if (localqY > 65535U) {
    (*rty_AFA_agCkClsInVlv_07) = MAX_uint16_T;
  } else {
    (*rty_AFA_agCkClsInVlv_07) = (UInt16)localqY;
  }

  /* SignalConversion: '<Root>/Signal Conversion14' */
  (*rty_AFA_pAirExtEstim_08) = (*rtu_UsThrM_pAirExt_25);

  /* SignalConversion: '<Root>/Signal Conversion15' */
  (*rty_AFA_mFuReqFil12) = (*rtu_InjSys_mFuReq_22);

  /* SignalConversion: '<Root>/Signal Conversion23' */
  (*rty_AFA_tCoMesFil_46) = (*rtu_Ext_tCoMes_29);

  /* SignalConversion: '<Root>/Signal Conversion24' */
  (*rty_AFA_pDsThrPred_001) = (*rtu_InM_pDsThrPred_001);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  localqY = ((*rtu_InM_pDsThrEs_21) >> 10);
  if (localqY > 65535U) {
    (*rty_AFA_pDsThrEstim_03) = MAX_uint16_T;
  } else {
    (*rty_AFA_pDsThrEstim_03) = (UInt16)localqY;
  }

  /* SignalConversion: '<Root>/Signal Conversion25' */
  (*rty_AFA_pUsThrCorFil_47) = (*rtu_UsThrM_pUsThrCor_30);

  /* DataTypeConversion: '<Root>/Data Type Cnversion3' */
  rty_AFA_prm_facGainInjFil_PIM[0] = rtu_InjrM_prm_facGainInj33[0];

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rty_AFA_prm_facCorG[0] = rtu_InjrM_prm_facCor85[0];

  /* DataTypeConversion: '<Root>/Data Type Cnversion8' */
  rty_AFA_prm_pDifInjrFil_PIM[0] = (UInt32)((SInt32)(((UInt32)
    (rtu_InjrM_prm_pDifInjr55[0] * 3125)) >> 11));

  /* DataTypeConversion: '<Root>/Data Type Cnversion3' */
  rty_AFA_prm_facGainInjFil_PIM[1] = rtu_InjrM_prm_facGainInj33[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rty_AFA_prm_facCorG[1] = rtu_InjrM_prm_facCor85[1];

  /* DataTypeConversion: '<Root>/Data Type Cnversion8' */
  rty_AFA_prm_pDifInjrFil_PIM[1] = (UInt32)((SInt32)(((UInt32)
    (rtu_InjrM_prm_pDifInjr55[1] * 3125)) >> 11));

  /* DataTypeConversion: '<Root>/Data Type Cnversion3' */
  rty_AFA_prm_facGainInjFil_PIM[2] = rtu_InjrM_prm_facGainInj33[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rty_AFA_prm_facCorG[2] = rtu_InjrM_prm_facCor85[2];

  /* DataTypeConversion: '<Root>/Data Type Cnversion8' */
  rty_AFA_prm_pDifInjrFil_PIM[2] = (UInt32)((SInt32)(((UInt32)
    (rtu_InjrM_prm_pDifInjr55[2] * 3125)) >> 11));

  /* DataTypeConversion: '<Root>/Data Type Cnversion3' */
  rty_AFA_prm_facGainInjFil_PIM[3] = rtu_InjrM_prm_facGainInj33[3];

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rty_AFA_prm_facCorG[3] = rtu_InjrM_prm_facCor85[3];

  /* DataTypeConversion: '<Root>/Data Type Cnversion8' */
  rty_AFA_prm_pDifInjrFil_PIM[3] = (UInt32)((SInt32)(((UInt32)
    (rtu_InjrM_prm_pDifInjr55[3] * 3125)) >> 11));

  /* SignalConversion: '<Root>/Signal Conversion28' */
  (*rty_AFA_nEngCorFil) = (*rtu_InThM_nEngCor);

  /* SignalConversion: '<Root>/Signal Conversion5' */
  (*rty_AFA_rEthStoichFil) = (*rtu_AfuA_rEthStoich);

  /* SignalConversion: '<Root>/Signal Conversion6' */
  (*rty_AFA_facRhoFuFil) = (*rtu_Ext_facRhoFu);
}

/* Model initialize function */
void mr_AFA_F01_init_inpu_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
