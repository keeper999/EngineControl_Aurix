/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F01_init_inputs_filters                             */
/*                                                                            */
/* !File            : AFA_F01_init_inputs_filters.h                           */
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
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F01_init_inputs_filters_h_
#define RTW_HEADER_AFA_F01_init_inputs_filters_h_
#ifndef AFA_F01_init_inputs_filters_COMMON_INCLUDES_
# define AFA_F01_init_inputs_filters_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AFA_F01_init_inputs_filters_COMMON_INCLUDES_ */

#include "AFA_F01_init_inputs_filters_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Model reference registration function */
extern void mr_AFA_F01_init_inpu_initialize(void);

extern void mr_AFA_F01_init_inputs_filters(const UInt16 *rtu_InM_pDsThrPred_43,
  const UInt16 *rtu_InM_rAirPres_42, const UInt16 *rtu_InM_arEffAdpThr_41,
  const UInt16 *rtu_InM_arEffAdpEGRVlv_40, const UInt16
  *rtu_InM_arEffEGRVlv_39, const UInt16 rtu_InjrM_prm_facGainInj33[4], const
  UInt16 *rtu_EngM_rAirLdCor_37, const UInt16 *rtu_ThrLrn_rOpSI_36, const
  UInt16 *rtu_InM_pDsThrCor_35, const SInt16 *rtu_InM_pDsThrEstimErr_34,
  const UInt16 *rtu_ExM_pExMnfEstim_33, const UInt16
  *rtu_EngM_facSlopEfcCor_32, const UInt16 *rtu_ExM_tExMnfEstim_31, const
  UInt16 *rtu_Ext_nEng66, const UInt16 *rtu_InThM_tAirUsIn_20, const SInt16
  *rtu_EngM_agCkCls_22, const SInt16 *rtu_EngM_agCkOp_23, const UInt16
  *rtu_EngM_rTotLd_24, const UInt16 *rtu_EngM_agCkClsI_25, const UInt16
  *rtu_UsThrM_pAirExt_25, const UInt32 *rtu_InjSys_mFuReq_22, const UInt16
  rtu_InjrM_prm_facCor85[4], const SInt16 *rtu_Ext_tCoMes_29, const UInt16
  *rtu_InM_pDsThrPred_001, const UInt32 *rtu_InM_pDsThrEs_21, const UInt16
  *rtu_UsThrM_pUsThrCor_30, const UInt16 rtu_InjrM_prm_pDifInjr55[4], const
  UInt16 *rtu_InThM_nEngCor, const UInt16 *rtu_AfuA_rEthStoich, const
  UInt8 *rtu_Ext_facRhoFu, UInt16 *rty_AFA_pDsThrPredFil_44, UInt16
  *rty_AFA_rAirPresFil_45, UInt16 *rty_AFA_arEffAdpThrFil_46, UInt16
  *rty_AFA_arEffAdpEGR_01, UInt16 *rty_AFA_arEffEGR_09, UInt16
  *rty_AFA_rInMassF_001, UInt32 rty_AFA_prm_facGainInjFil_PIM[4], UInt16
  *rty_AFA_rAirLdCorFil_42, UInt16 *rty_AFA_rOpSIFil_43, UInt16
  *rty_AFA_pDsThrCorFil_44, SInt16 *rty_AFA_pDsThrEstim_002, UInt16
  *rty_AFA_pExMnfEstim_11, UInt32 *rty_AFA_facSlopEfcCor_10, UInt16
  *rty_AFA_tExMnfEstim_12, UInt16 *rty_AFA_nEngFil11, UInt32
  *rty_AFA_tAirUsInVlv_02, SInt16 *rty_AFA_agCkClsExVlv_04, SInt16
  *rty_AFA_agCkOpInVlv_05, UInt16 *rty_AFA_rTotLdExCor_06, UInt16
  *rty_AFA_agCkClsInVlv_07, UInt16 *rty_AFA_pAirExtEstim_08, UInt32
  *rty_AFA_mFuReqFil12, UInt16 rty_AFA_prm_facCorG[4], SInt16
  *rty_AFA_tCoMesFil_46, UInt16 *rty_AFA_pDsThrPred_001, UInt16
  *rty_AFA_pDsThrEstim_03, UInt16 *rty_AFA_pUsThrCorFil_47, UInt32
  rty_AFA_prm_pDifInjrFil_PIM[4], UInt16 *rty_AFA_nEngCorFil, UInt16
  *rty_AFA_rEthStoichFil, UInt8 *rty_AFA_facRhoFuFil);

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AFA_F01_init_inputs_filters
 */

/*-
 * Requirements for '<Root>': AFA_F01_init_inputs_filters
 */
#endif                                 /* RTW_HEADER_AFA_F01_init_inputs_filters_h_ */

/*-------------------------------- end of file -------------------------------*/
