/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F05_Calc_Sensitivity_EGR                            */
/*                                                                            */
/* !File            : AFA_F05_Calc_Sensitivity_EGR.h                          */
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
/*   Model name       : AFA_F05_Calc_Sensitivity_EGR.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F05_Calc_Sensitivity_EGR_h_
#define RTW_HEADER_AFA_F05_Calc_Sensitivity_EGR_h_
#ifndef AFA_F05_Calc_Sensitivity_EGR_COMMON_INCLUDES_
# define AFA_F05_Calc_Sensitivity_EGR_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F05_Calc_Sensitivity_EGR_import.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F05_Calc_Sensitivity_EGR_COMMON_INCLUDES_ */

#include "AFA_F05_Calc_Sensitivity_EGR_types.h"

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
extern UInt16 AFA_rlamGrd_arEffEGRVlv;/* '<Root>/Merge' */
extern UInt16 AFA_pGrdDsThr_arEffEGRVlv;/* '<Root>/Merge1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F05_Calc_Sensitivity_EGR(const UInt32
  *rtu_AFA_rTotLdGrd_pDs_, const UInt16 *rtu_AFA_arEffAdpThrFi5, const
  UInt16 *rtu_AFA_rInMassFlowFi5, const UInt16 *rtu_AFA_arEffAdpEGRVlvFil,
  const UInt16 *rtu_AFA_mfArThr_rAirPre5, const UInt16 *rtu_AFA_pDsThrFi5,
  const UInt16 *rtu_AFA_arEffEGRVlvFil, UInt16 *rty_AFA_rlamGrd_arEffEGRVlv,
  UInt16 *rty_AFA_pGrdDsThr_arEffEGRVlv);

/* Model reference registration function */
extern void mr_AFA_F05_Calc_Sens_initialize(void);

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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Propagation1' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/Data Type Conversion' : Unused code path elimination
 * Block '<S11>/Data Type Conversion1' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/Data Type Propagation1' : Unused code path elimination
 * Block '<S13>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/Data Type Conversion' : Unused code path elimination
 * Block '<S13>/Data Type Conversion1' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Data Type Propagation1' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Data Type Conversion' : Unused code path elimination
 * Block '<S15>/Data Type Conversion1' : Unused code path elimination
 * Block '<S6>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/Data Type Propagation1' : Unused code path elimination
 * Block '<S17>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/Data Type Conversion' : Unused code path elimination
 * Block '<S17>/Data Type Conversion1' : Unused code path elimination
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/Data Type Propagation1' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Data Type Conversion' : Unused code path elimination
 * Block '<S19>/Data Type Conversion1' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/Data Type Propagation1' : Unused code path elimination
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S21>/Data Type Conversion' : Unused code path elimination
 * Block '<S21>/Data Type Conversion1' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S9>/Switch' : Eliminated due to constant selection input
 * Block '<S10>/Switch' : Eliminated due to constant selection input
 * Block '<S9>/Add3' : Unused code path elimination
 * Block '<S9>/Add4' : Unused code path elimination
 * Block '<S9>/Constant' : Unused code path elimination
 * Block '<S9>/Relational Operator' : Unused code path elimination
 * Block '<S9>/Switch1' : Unused code path elimination
 * Block '<S9>/offset2' : Unused code path elimination
 * Block '<S9>/offset3' : Unused code path elimination
 * Block '<S9>/offset4' : Unused code path elimination
 * Block '<S10>/Add3' : Unused code path elimination
 * Block '<S10>/Add4' : Unused code path elimination
 * Block '<S10>/Constant' : Unused code path elimination
 * Block '<S10>/Relational Operator' : Unused code path elimination
 * Block '<S10>/Switch1' : Unused code path elimination
 * Block '<S10>/offset2' : Unused code path elimination
 * Block '<S10>/offset3' : Unused code path elimination
 * Block '<S10>/offset4' : Unused code path elimination
 */

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
 * '<Root>' : AFA_F05_Calc_Sensitivity_EGR
 * '<S1>'   : AFA_F05_Calc_Sensitivity_EGR/F01_Without_EGR
 * '<S2>'   : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR
 * '<S3>'   : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only
 * '<S4>'   : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only1
 * '<S5>'   : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only2
 * '<S6>'   : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only3
 * '<S7>'   : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only5
 * '<S8>'   : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only6
 * '<S9>'   : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/SingleToFixdt
 * '<S10>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/SingleToFixdt1
 * '<S11>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only/Data Type Police Only single
 * '<S12>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only/If Action Subsystem3
 * '<S13>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only1/Data Type Police Only single
 * '<S14>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only1/If Action Subsystem3
 * '<S15>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only2/Data Type Police Only single
 * '<S16>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only2/If Action Subsystem3
 * '<S17>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only3/Data Type Police Only single
 * '<S18>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only3/If Action Subsystem3
 * '<S19>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only5/Data Type Police Only single
 * '<S20>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only5/If Action Subsystem3
 * '<S21>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only6/Data Type Police Only single
 * '<S22>'  : AFA_F05_Calc_Sensitivity_EGR/F02_Calc_sensitivity_EGR/Div_float_only6/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F05_Calc_Sensitivity_EGR
 */
#endif                                 /* RTW_HEADER_AFA_F05_Calc_Sensitivity_EGR_h_ */

/*-------------------------------- end of file -------------------------------*/
