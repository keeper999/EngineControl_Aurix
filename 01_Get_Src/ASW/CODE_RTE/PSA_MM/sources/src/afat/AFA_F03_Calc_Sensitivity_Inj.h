/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F03_Calc_Sensitivity_Inj                            */
/*                                                                            */
/* !File            : AFA_F03_Calc_Sensitivity_Inj.h                          */
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
/*   Model name       : AFA_F03_Calc_Sensitivity_Inj.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F03_Calc_Sensitivity_Inj_h_
#define RTW_HEADER_AFA_F03_Calc_Sensitivity_Inj_h_
#ifndef AFA_F03_Calc_Sensitivity_Inj_COMMON_INCLUDES_
# define AFA_F03_Calc_Sensitivity_Inj_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F03_Calc_Sensitivity_Inj_import.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F03_Calc_Sensitivity_Inj_COMMON_INCLUDES_ */

#include "AFA_F03_Calc_Sensitivity_Inj_types.h"

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


#define AFAT_START_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern UInt32 AFA_rlamGrd_facSlopInjGain;/* '<S14>/OutDTConv' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

extern UInt16 AFA_rlamGrd_facIvsInjGain;/* '<S13>/OutDTConv' */
extern UInt16 AFA_rlamGrd_tiOffInj;  /* '<S15>/OutDTConv' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern UInt16 AFA_prm_rlamGrd_facIvsInj_MP[4];/* '<Root>/Data Store Memory1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F03_Calc_Sensitivity_Inj(const UInt32 *rtu_AFA_mFuReqFil,
  const UInt32 rtu_AFA_prm_facGainInjFil_PIM[4], const UInt32
  rtu_AFA_prm_pDifInjrFil_PIM[4], const UInt32 rtu_InjrSys_prm_tiInj[4], const
  UInt16 rtu_AFA_prm_facCorGainLnrFil_PI[4], const UInt16
  *rtu_AFA_rEthStoichFil, const UInt8 *rtu_AFA_facRhoFuFil, UInt16
  *rty_AFA_rlamGrd_tiOffInj, UInt16 *rty_AFA_rlamGrd_facIvsInjGain, UInt32
  *rty_AFA_rlamGrd_facSlopInjGain);

/* Model reference registration function */
extern void mr_AFA_F03_Calc_Sens_initialize(void);

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
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Data Type Propagation1' : Unused code path elimination
 * Block '<S17>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/Data Type Conversion' : Unused code path elimination
 * Block '<S17>/Data Type Conversion1' : Unused code path elimination
 * Block '<S2>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/Data Type Propagation1' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Data Type Conversion' : Unused code path elimination
 * Block '<S19>/Data Type Conversion1' : Unused code path elimination
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Propagation1' : Unused code path elimination
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S21>/Data Type Conversion' : Unused code path elimination
 * Block '<S21>/Data Type Conversion1' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/Data Type Propagation1' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/Data Type Conversion' : Unused code path elimination
 * Block '<S23>/Data Type Conversion1' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Data Type Propagation1' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/Data Type Conversion' : Unused code path elimination
 * Block '<S25>/Data Type Conversion1' : Unused code path elimination
 * Block '<S6>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/Data Type Propagation1' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Data Type Conversion' : Unused code path elimination
 * Block '<S27>/Data Type Conversion1' : Unused code path elimination
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/Data Type Propagation1' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S29>/Data Type Conversion' : Unused code path elimination
 * Block '<S29>/Data Type Conversion1' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/Data Type Propagation1' : Unused code path elimination
 * Block '<S31>/Data Type Propagation' : Unused code path elimination
 * Block '<S31>/Data Type Conversion' : Unused code path elimination
 * Block '<S31>/Data Type Conversion1' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/Data Type Propagation1' : Unused code path elimination
 * Block '<S33>/Data Type Propagation' : Unused code path elimination
 * Block '<S33>/Data Type Conversion' : Unused code path elimination
 * Block '<S33>/Data Type Conversion1' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S10>/Data Type Propagation1' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S35>/Data Type Conversion' : Unused code path elimination
 * Block '<S35>/Data Type Conversion1' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/Data Type Propagation1' : Unused code path elimination
 * Block '<S37>/Data Type Propagation' : Unused code path elimination
 * Block '<S37>/Data Type Conversion' : Unused code path elimination
 * Block '<S37>/Data Type Conversion1' : Unused code path elimination
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/Data Type Propagation1' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Data Type Conversion' : Unused code path elimination
 * Block '<S39>/Data Type Conversion1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S13>/Switch' : Eliminated due to constant selection input
 * Block '<S14>/Switch' : Eliminated due to constant selection input
 * Block '<S15>/Switch' : Eliminated due to constant selection input
 * Block '<S16>/Switch' : Eliminated due to constant selection input
 * Block '<S13>/Add3' : Unused code path elimination
 * Block '<S13>/Add4' : Unused code path elimination
 * Block '<S13>/Constant' : Unused code path elimination
 * Block '<S13>/Relational Operator' : Unused code path elimination
 * Block '<S13>/Switch1' : Unused code path elimination
 * Block '<S13>/offset2' : Unused code path elimination
 * Block '<S13>/offset3' : Unused code path elimination
 * Block '<S13>/offset4' : Unused code path elimination
 * Block '<S14>/Add3' : Unused code path elimination
 * Block '<S14>/Add4' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S14>/Relational Operator' : Unused code path elimination
 * Block '<S14>/Switch1' : Unused code path elimination
 * Block '<S14>/offset2' : Unused code path elimination
 * Block '<S14>/offset3' : Unused code path elimination
 * Block '<S14>/offset4' : Unused code path elimination
 * Block '<S15>/Add3' : Unused code path elimination
 * Block '<S15>/Add4' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S15>/Relational Operator' : Unused code path elimination
 * Block '<S15>/Switch1' : Unused code path elimination
 * Block '<S15>/offset2' : Unused code path elimination
 * Block '<S15>/offset3' : Unused code path elimination
 * Block '<S15>/offset4' : Unused code path elimination
 * Block '<S16>/Add3' : Unused code path elimination
 * Block '<S16>/Add4' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S16>/Relational Operator' : Unused code path elimination
 * Block '<S16>/Switch1' : Unused code path elimination
 * Block '<S16>/offset2' : Unused code path elimination
 * Block '<S16>/offset3' : Unused code path elimination
 * Block '<S16>/offset4' : Unused code path elimination
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
 * '<Root>' : AFA_F03_Calc_Sensitivity_Inj
 * '<S1>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only1
 * '<S2>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only10
 * '<S3>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only11
 * '<S4>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only12
 * '<S5>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only2
 * '<S6>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only3
 * '<S7>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only4
 * '<S8>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only5
 * '<S9>'   : AFA_F03_Calc_Sensitivity_Inj/Div_float_only6
 * '<S10>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only7
 * '<S11>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only8
 * '<S12>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only9
 * '<S13>'  : AFA_F03_Calc_Sensitivity_Inj/SingleToFixdt1
 * '<S14>'  : AFA_F03_Calc_Sensitivity_Inj/SingleToFixdt2
 * '<S15>'  : AFA_F03_Calc_Sensitivity_Inj/SingleToFixdt3
 * '<S16>'  : AFA_F03_Calc_Sensitivity_Inj/SingleToFixdt5
 * '<S17>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only1/Data Type Police Only single
 * '<S18>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only1/If Action Subsystem3
 * '<S19>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only10/Data Type Police Only single
 * '<S20>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only10/If Action Subsystem3
 * '<S21>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only11/Data Type Police Only single
 * '<S22>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only11/If Action Subsystem3
 * '<S23>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only12/Data Type Police Only single
 * '<S24>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only12/If Action Subsystem3
 * '<S25>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only2/Data Type Police Only single
 * '<S26>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only2/If Action Subsystem3
 * '<S27>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only3/Data Type Police Only single
 * '<S28>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only3/If Action Subsystem3
 * '<S29>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only4/Data Type Police Only single
 * '<S30>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only4/If Action Subsystem3
 * '<S31>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only5/Data Type Police Only single
 * '<S32>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only5/If Action Subsystem3
 * '<S33>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only6/Data Type Police Only single
 * '<S34>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only6/If Action Subsystem3
 * '<S35>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only7/Data Type Police Only single
 * '<S36>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only7/If Action Subsystem3
 * '<S37>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only8/Data Type Police Only single
 * '<S38>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only8/If Action Subsystem3
 * '<S39>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only9/Data Type Police Only single
 * '<S40>'  : AFA_F03_Calc_Sensitivity_Inj/Div_float_only9/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F03_Calc_Sensitivity_Inj
 */
#endif                                 /* RTW_HEADER_AFA_F03_Calc_Sensitivity_Inj_h_ */

/*-------------------------------- end of file -------------------------------*/
