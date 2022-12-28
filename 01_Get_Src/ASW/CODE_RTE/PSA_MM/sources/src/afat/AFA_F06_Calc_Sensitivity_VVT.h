/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F06_Calc_Sensitivity_VVT                            */
/*                                                                            */
/* !File            : AFA_F06_Calc_Sensitivity_VVT.h                          */
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
/*   Model name       : AFA_F06_Calc_Sensitivity_VVT.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F06_Calc_Sensitivity_VVT_h_
#define RTW_HEADER_AFA_F06_Calc_Sensitivity_VVT_h_
#ifndef AFA_F06_Calc_Sensitivity_VVT_COMMON_INCLUDES_
# define AFA_F06_Calc_Sensitivity_VVT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F06_Calc_Sensitivity_VVT_import.h"
#include "rtw_shared_utils.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F06_Calc_Sensitivity_VVT_COMMON_INCLUDES_ */

#include "AFA_F06_Calc_Sensitivity_VVT_types.h"

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
extern SInt16 AFA_rlamGrd_agCkIn;     /* '<Root>/Merge1' */
extern SInt16 AFA_rlamGrd_agCkEx;     /* '<Root>/Merge2' */
extern SInt16 AFA_pGrdDsThr_agCkIn;   /* '<Root>/Merge' */
extern SInt16 AFA_pGrdDsThr_agCkEx;   /* '<Root>/Merge3' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern SInt16 AFA_facMassFlowArGrd_pDsThr;/* '<S1>/Data Store Memory' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F06_Calc_Sensitivity_VVT(const UInt32
  *rtu_AFA_facSlopEfcCor6, const SInt16 *rtu_AFA_facSlopGrdEfc_agCkIn, const
  SInt16 *rtu_AFA_facOfsGrdEfc_agCkIn, const SInt16
  *rtu_AFA_facOfsGrdEfc_agCkEx, const UInt16 *rtu_AFA_pDsThrCorFil, const
  UInt16 *rtu_AFA_rAirPresFil, const UInt16 *rtu_AFA_rAirLdCorFil, const
  UInt16 *rtu_AFA_arEffAdpThr6, const UInt16 *rtu_AFA_arEffAdpEGRVlv6, const
  UInt16 *rtu_AFA_nEngFil, const UInt16 *rtu_AFA_pDsThrEstimFil, SInt16
  *rty_AFA_rlamGrd_agCkEx, SInt16 *rty_AFA_pGrdDsThr_agCkEx, SInt16
  *rty_AFA_pGrdDsThr_agCkIn, SInt16 *rty_AFA_rlamGrd_agCkIn);

/* Model reference registration function */
extern void mr_AFA_F06_Calc_Sens_initialize(void);

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
 * Block '<S6>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/Data Type Propagation1' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Unused code path elimination
 * Block '<S9>/Data Type Conversion1' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/x1' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/Data Type Propagation1' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Data Type Conversion' : Unused code path elimination
 * Block '<S15>/Data Type Conversion1' : Unused code path elimination
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/Data Type Propagation1' : Unused code path elimination
 * Block '<S17>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/Data Type Conversion' : Unused code path elimination
 * Block '<S17>/Data Type Conversion1' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Data Type Propagation1' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/Data Type Conversion' : Unused code path elimination
 * Block '<S23>/Data Type Conversion1' : Unused code path elimination
 * Block '<S20>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/Data Type Propagation1' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/Data Type Conversion' : Unused code path elimination
 * Block '<S25>/Data Type Conversion1' : Unused code path elimination
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S8>/Switch' : Eliminated due to constant selection input
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S13>/Switch' : Eliminated due to constant selection input
 * Block '<S14>/Switch' : Eliminated due to constant selection input
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S21>/Switch' : Eliminated due to constant selection input
 * Block '<S22>/Switch' : Eliminated due to constant selection input
 * Block '<S8>/Add2' : Unused code path elimination
 * Block '<S8>/Constant' : Unused code path elimination
 * Block '<S8>/offset1' : Unused code path elimination
 * Block '<S13>/Add2' : Unused code path elimination
 * Block '<S13>/Constant' : Unused code path elimination
 * Block '<S13>/offset1' : Unused code path elimination
 * Block '<S14>/Add2' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S14>/offset1' : Unused code path elimination
 * Block '<S21>/Add2' : Unused code path elimination
 * Block '<S21>/Constant' : Unused code path elimination
 * Block '<S21>/offset1' : Unused code path elimination
 * Block '<S22>/Add2' : Unused code path elimination
 * Block '<S22>/Constant' : Unused code path elimination
 * Block '<S22>/offset1' : Unused code path elimination
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
 * '<Root>' : AFA_F06_Calc_Sensitivity_VVT
 * '<S1>'   : AFA_F06_Calc_Sensitivity_VVT/F01_Calc_Sensivity_facMassFlowAr
 * '<S2>'   : AFA_F06_Calc_Sensitivity_VVT/F02_Without_exhaust_VVT
 * '<S3>'   : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn
 * '<S4>'   : AFA_F06_Calc_Sensitivity_VVT/F04_Without_Intake_VVT
 * '<S5>'   : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx
 * '<S6>'   : AFA_F06_Calc_Sensitivity_VVT/F01_Calc_Sensivity_facMassFlowAr/Div_float_only
 * '<S7>'   : AFA_F06_Calc_Sensitivity_VVT/F01_Calc_Sensivity_facMassFlowAr/LookUp_1D
 * '<S8>'   : AFA_F06_Calc_Sensitivity_VVT/F01_Calc_Sensivity_facMassFlowAr/SingleToFixdt
 * '<S9>'   : AFA_F06_Calc_Sensitivity_VVT/F01_Calc_Sensivity_facMassFlowAr/Div_float_only/Data Type Police Only single
 * '<S10>'  : AFA_F06_Calc_Sensitivity_VVT/F01_Calc_Sensivity_facMassFlowAr/Div_float_only/If Action Subsystem3
 * '<S11>'  : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn/Div_float_only
 * '<S12>'  : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn/Div_float_only1
 * '<S13>'  : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn/SingleToFixdt
 * '<S14>'  : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn/SingleToFixdt1
 * '<S15>'  : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn/Div_float_only/Data Type Police Only single
 * '<S16>'  : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn/Div_float_only/If Action Subsystem3
 * '<S17>'  : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn/Div_float_only1/Data Type Police Only single
 * '<S18>'  : AFA_F06_Calc_Sensitivity_VVT/F03_Init_sensitivity_agCkIn/Div_float_only1/If Action Subsystem3
 * '<S19>'  : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx/Div_float_only
 * '<S20>'  : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx/Div_float_only1
 * '<S21>'  : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx/SingleToFixdt
 * '<S22>'  : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx/SingleToFixdt1
 * '<S23>'  : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx/Div_float_only/Data Type Police Only single
 * '<S24>'  : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx/Div_float_only/If Action Subsystem3
 * '<S25>'  : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx/Div_float_only1/Data Type Police Only single
 * '<S26>'  : AFA_F06_Calc_Sensitivity_VVT/F05_Init_sensitivity_agCkEx/Div_float_only1/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F06_Calc_Sensitivity_VVT
 */
#endif                                 /* RTW_HEADER_AFA_F06_Calc_Sensitivity_VVT_h_ */

/*-------------------------------- end of file -------------------------------*/
