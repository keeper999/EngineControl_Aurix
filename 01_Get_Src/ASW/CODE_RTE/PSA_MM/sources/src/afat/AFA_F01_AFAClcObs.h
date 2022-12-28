/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F01_AFAClcObs                                       */
/*                                                                            */
/* !File            : AFA_F01_AFAClcObs.h                                     */
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
#ifndef RTW_HEADER_AFA_F01_AFAClcObs_h_
#define RTW_HEADER_AFA_F01_AFAClcObs_h_
#ifndef AFA_F01_AFAClcObs_COMMON_INCLUDES_
# define AFA_F01_AFAClcObs_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F01_AFAClcObs_import.h"
#endif                                 /* AFA_F01_AFAClcObs_COMMON_INCLUDES_ */

#include "AFA_F01_AFAClcObs_types.h"

/* Child system includes */
#ifndef AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_
#define AFA_F06_Calc_Sensitivity_VVT_MDLREF_HIDE_CHILD_
#include "AFA_F06_Calc_Sensitivity_VVT.h"
#undef AFA_F06_Calc_Sensitivity_VVT_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_
#define AFA_F05_Calc_Sensitivity_EGR_MDLREF_HIDE_CHILD_
#include "AFA_F05_Calc_Sensitivity_EGR.h"
#undef AFA_F05_Calc_Sensitivity_EGR_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_
#define AFA_F04_Calc_Sensitivity_Pap_MDLREF_HIDE_CHILD_
#include "AFA_F04_Calc_Sensitivity_Pap.h"
#undef AFA_F04_Calc_Sensitivity_Pap_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_
#define AFA_F03_Calc_Sensitivity_Inj_MDLREF_HIDE_CHILD_
#include "AFA_F03_Calc_Sensitivity_Inj.h"
#undef AFA_F03_Calc_Sensitivity_Inj_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_
#define AFA_F02_calc_sensitivity_mat_MDLREF_HIDE_CHILD_
#include "AFA_F02_calc_sensitivity_mat.h"
#undef AFA_F02_calc_sensitivity_mat_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_
#define AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#include "AFA_F02_Calc_sensitivity_load_estim.h"
#undef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_
#define AFA_F01_Calc_Sensitivity_SaintVenant_MDLREF_HIDE_CHILD_
#include "AFA_F01_Calc_Sensitivity_SaintVenant.h"
#undef AFA_F01_Calc_Sensitivity_SaintVenant_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F01_AFAClcObs_MDLREF_HIDE_CHILD_*/

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

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern UInt16 AFA_pDsThrFil;         /* '<S1>/Switch' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F01_AFAClcObs_Start(void);
extern void mr_AFA_F01_AFAClcObs(const UInt16 *rtu_AFA_pDsThrCorFil, const
  UInt16 *rtu_AFA_pExMnfEstimFil, const UInt16 *rtu_AFA_nEngFil_irv, const
  UInt16 *rtu_AFA_tExMnfEstimFil, const UInt32 *rtu_AFA_tAirUsInVlv2, const
  SInt16 *rtu_AFA_agCkClsExVlv1, const SInt16 *rtu_AFA_agCkOpInVlv1, const
  UInt16 *rtu_AFA_rTotLdExCorFil, const UInt32 *rtu_AFA_facSlopEfcCorFil,
  const UInt16 *rtu_AFA_rAirPresFil, const UInt16 *rtu_AFA_arEffAdpThrFil,
  const UInt16 *rtu_AFA_arEffAdpEGR1, const UInt16 *rtu_AFA_rInMassFlowFil,
  const UInt16 *rtu_AFA_rOpSIFil, const UInt16 *rtu_AFA_arEffEGRVlvFil,
  const UInt16 *rtu_AFA_rAirLdCorFil, const UInt16 *rtu_AFA_agCkClsInVlv1,
  const UInt16 *rtu_AFA_pAirExtEstimFil, const UInt32 *rtu_AFA_mFuReqFil,
  const SInt16 *rtu_AFA_tCoMesFil, const UInt16 *rtu_AFA_pDsThrPred_03, const
  UInt16 *rtu_AFA_pDsThrEstimFil, const UInt32 rtu_InjrSys_prm_tiInj[4],
  const Boolean rtu_AFA_prm_bMaskSenMat_PIM[16], const UInt16
  rtu_AFA_prm_facCorGainLnrFil__m[4], const UInt32
  rtu_AFA_prm_facGainInjFil_PIM[4], const UInt32 rtu_AFA_prm_pDifInjrFil_PIM[4],
  const UInt16 *rtu_AFA_nEngCorFil, const UInt16 *rtu_AFA_rEthStoichFil,
  const UInt8 *rtu_AFA_facRhoFuFil, SInt32 rty_AFA_prm_facSenTransMat_PIM[16]);

/* Model reference registration function */
extern void mr_AFA_F01_AFAClcObs_initialize(void);

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
 * '<Root>' : AFA_F01_AFAClcObs
 * '<S1>'   : AFA_F01_AFAClcObs/F01_calc_sensitivity_fct
 */

/*-
 * Requirements for '<Root>': AFA_F01_AFAClcObs
 */
#endif                                 /* RTW_HEADER_AFA_F01_AFAClcObs_h_ */

/*-------------------------------- end of file -------------------------------*/
