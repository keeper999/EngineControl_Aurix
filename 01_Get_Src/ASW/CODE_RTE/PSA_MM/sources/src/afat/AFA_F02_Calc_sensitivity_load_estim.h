/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F02_Calc_sensitivity_load_estim                     */
/*                                                                            */
/* !File            : AFA_F02_Calc_sensitivity_load_estim.h                   */
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
/*   Model name       : AFA_F02_Calc_sensitivity_load_estim.mdl               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F02_Calc_sensitivity_load_estim_h_
#define RTW_HEADER_AFA_F02_Calc_sensitivity_load_estim_h_
#ifndef AFA_F02_Calc_sensitivity_load_estim_COMMON_INCLUDES_
# define AFA_F02_Calc_sensitivity_load_estim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F02_Calc_sensitivity_load_estim_import.h"
#endif                                 /* AFA_F02_Calc_sensitivity_load_estim_COMMON_INCLUDES_ */

#include "AFA_F02_Calc_sensitivity_load_estim_types.h"

/* Child system includes */
#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F10_Total_load_gradient_MDLREF_HIDE_CHILD_
#include "AFA_F10_Total_load_gradient.h"
#undef AFA_F10_Total_load_gradient_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F09_offset_air_load_MDLREF_HIDE_CHILD_
#include "AFA_F09_offset_air_load.h"
#undef AFA_F09_offset_air_load_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F08_burn_gas_temperature_MDLREF_HIDE_CHILD_
#include "AFA_F08_burn_gas_temperature.h"
#undef AFA_F08_burn_gas_temperature_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F07_Residual_scavenged_reaspired_mass_MDLREF_HIDE_CHILD_
#include "AFA_F07_Residual_scavenged_reaspired_mass.h"
#undef AFA_F07_Residual_scavenged_reaspired_mass_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F06_Specific_VVT_angle_MDLREF_HIDE_CHILD_
#include "AFA_F06_Specific_VVT_angle.h"
#undef AFA_F06_Specific_VVT_angle_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F05_Slop_air_load_MDLREF_HIDE_CHILD_
#include "AFA_F05_Slop_air_load.h"
#undef AFA_F05_Slop_air_load_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F04_Water_correction_temperature_MDLREF_HIDE_CHILD_
#include "AFA_F04_Water_correction_temperature.h"
#undef AFA_F04_Water_correction_temperature_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F03_Slop_correction_MDLREF_HIDE_CHILD_
#include "AFA_F03_Slop_correction.h"
#undef AFA_F03_Slop_correction_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F02_cylinder_volume_at_close_intake_valve_MDLREF_HIDE_CHILD_
#include "AFA_F02_cylinder_volume_at_close_intake_valve.h"
#undef AFA_F02_cylinder_volume_at_close_intake_valve_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_
#define AFA_F01_fresh_gas_temperature_MDLREF_HIDE_CHILD_
#include "AFA_F01_fresh_gas_temperature.h"
#undef AFA_F01_fresh_gas_temperature_MDLREF_HIDE_CHILD_
#endif                                 /*AFA_F02_Calc_sensitivity_load_estim_MDLREF_HIDE_CHILD_*/

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
extern UInt16 AFA_rMassBurnRg;       /* '<Root>/AFA_F07_Residual_scavenged_reaspired_mass' */
extern SInt16 AFA_rMassGrdBurnRg_agCkEx;/* '<Root>/AFA_F07_Residual_scavenged_reaspired_mass' */
extern SInt16 AFA_rMassGrdBurnRg_agCkIn;/* '<Root>/AFA_F07_Residual_scavenged_reaspired_mass' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F02_Calc_sensitivi_Start(void);
extern void mr_AFA_F02_Calc_sensitivity_loa(const UInt16 *rtu_AFA_nEngFil,
  const SInt16 *rtu_AFA_agCkClsExVlvEstimRef1_p, const UInt16
  *rtu_AFA_agCkClsInVlvEstimRef1_k, const SInt16
  *rtu_AFA_agCkOpInVlvEstimRef1F_o, const UInt32 *rtu_AFA_tAirUsInVlvEstimFil,
  const UInt16 *rtu_AFA_tExMnfEstimFi2, const UInt16 *rtu_AFA_pDsThrFi2,
  const UInt16 *rtu_AFA_pExMnfEstimFi2, const UInt16
  *rtu_AFA_pAirExtEstimFil, const UInt16 *rtu_AFA_pDsThrPred_facVlvOvlp_b,
  const SInt16 *rtu_AFA_tCoMesFil, const UInt32 *rtu_AFA_facSlopEfcCorFil,
  const UInt16 *rtu_AFA_rTotLdExCorFil, const UInt16
  *rtu_AFA_mfArGrdVlv_rPresInEx, const UInt16 *rtu_AFA_mfArGrdVlv_rPresExIn,
  const UInt16 *rtu_AFA_nEngCorFil, UInt32 *rty_AFA_rTotLdGrd_pDsThr,
  SInt16 *rty_AFA_facSlopGrdEfc_agCkIn, SInt16 *rty_AFA_facOfsGrdEfc_agCkIn,
  SInt16 *rty_AFA_facOfsGrdEfc_agCkEx);

/* Model reference registration function */
extern void mr_AFA_F02_Calc_sens_initialize(void);

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
 * '<Root>' : AFA_F02_Calc_sensitivity_load_estim
 */

/*-
 * Requirements for '<Root>': AFA_F02_Calc_sensitivity_load_estim
 */
#endif                                 /* RTW_HEADER_AFA_F02_Calc_sensitivity_load_estim_h_ */

/*-------------------------------- end of file -------------------------------*/
