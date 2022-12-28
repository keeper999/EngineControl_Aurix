/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F04_Calc_Sensitivity_Pap                            */
/*                                                                            */
/* !File            : AFA_F04_Calc_Sensitivity_Pap.h                          */
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
/*   Model name       : AFA_F04_Calc_Sensitivity_Pap.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F04_Calc_Sensitivity_Pap_h_
#define RTW_HEADER_AFA_F04_Calc_Sensitivity_Pap_h_
#ifndef AFA_F04_Calc_Sensitivity_Pap_COMMON_INCLUDES_
# define AFA_F04_Calc_Sensitivity_Pap_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F04_Calc_Sensitivity_Pap_import.h"
#include "rt_MAXf.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F04_Calc_Sensitivity_Pap_COMMON_INCLUDES_ */

#include "AFA_F04_Calc_Sensitivity_Pap_types.h"

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
extern UInt16 AFA_pGrdDsThr_facArEffThrOfs3;/* '<S6>/OutDTConv' */
extern UInt16 AFA_pGrdDsThr_facArEffThrOfs2;/* '<S5>/OutDTConv' */
extern UInt16 AFA_pGrdDsThr_facArEffThrOfs1;/* '<S4>/OutDTConv' */
extern UInt16 AFA_pGrdDsThr_arEffThr;/* '<S11>/OutDTConv' */
extern UInt16 AFA_rlamGrd_facArEffThrOfs1;/* '<S7>/OutDTConv' */
extern UInt16 AFA_rlamGrd_facArEffThrOfs3;/* '<S9>/OutDTConv' */
extern UInt16 AFA_rlamGrd_facArEffThrOfs2;/* '<S8>/OutDTConv' */
extern UInt16 AFA_rlamGrd_arEffThr;  /* '<S10>/OutDTConv' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F04_Calc_Sensitivity_Pap(const UInt16
  *rtu_AFA_mfArThr_rAirPres, const UInt16 *rtu_AFA_pDsThrFi4, const UInt16
  *rtu_AFA_arEffAdpThrFil, const UInt16 *rtu_AFA_rInMassFlowFil, const
  UInt16 *rtu_AFA_rOpSIFil, const UInt32 *rtu_AFA_rTotLdGrd_pDsThr, UInt16
  *rty_AFA_pGrdDsThr_arEffThr, UInt16 *rty_AFA_pGrdDsThr_facArEffThrOf,
  UInt16 *rty_AFA_pGrdDsThr_facArEffThr_c, UInt16
  *rty_AFA_pGrdDsThr_facArEffThr_a, UInt16 *rty_AFA_rlamGrd_arEffThr, UInt16
  *rty_AFA_rlamGrd_facArEffThrOfs1, UInt16 *rty_AFA_rlamGrd_facArEffThrOfs2,
  UInt16 *rty_AFA_rlamGrd_facArEffThrOfs3);

/* Model reference registration function */
extern void mr_AFA_F04_Calc_Sens_initialize(void);

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
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/Data Type Conversion' : Unused code path elimination
 * Block '<S12>/Data Type Conversion1' : Unused code path elimination
 * Block '<S2>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/Data Type Propagation1' : Unused code path elimination
 * Block '<S14>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/Data Type Conversion' : Unused code path elimination
 * Block '<S14>/Data Type Conversion1' : Unused code path elimination
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Propagation1' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/Data Type Conversion' : Unused code path elimination
 * Block '<S16>/Data Type Conversion1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S4>/Switch' : Eliminated due to constant selection input
 * Block '<S5>/Switch' : Eliminated due to constant selection input
 * Block '<S6>/Switch' : Eliminated due to constant selection input
 * Block '<S7>/Switch' : Eliminated due to constant selection input
 * Block '<S8>/Switch' : Eliminated due to constant selection input
 * Block '<S9>/Switch' : Eliminated due to constant selection input
 * Block '<S10>/Switch' : Eliminated due to constant selection input
 * Block '<S11>/Switch' : Eliminated due to constant selection input
 * Block '<S4>/Add3' : Unused code path elimination
 * Block '<S4>/Add4' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S4>/Relational Operator' : Unused code path elimination
 * Block '<S4>/Switch1' : Unused code path elimination
 * Block '<S4>/offset2' : Unused code path elimination
 * Block '<S4>/offset3' : Unused code path elimination
 * Block '<S4>/offset4' : Unused code path elimination
 * Block '<S5>/Add3' : Unused code path elimination
 * Block '<S5>/Add4' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S5>/Relational Operator' : Unused code path elimination
 * Block '<S5>/Switch1' : Unused code path elimination
 * Block '<S5>/offset2' : Unused code path elimination
 * Block '<S5>/offset3' : Unused code path elimination
 * Block '<S5>/offset4' : Unused code path elimination
 * Block '<S6>/Add3' : Unused code path elimination
 * Block '<S6>/Add4' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<S6>/Relational Operator' : Unused code path elimination
 * Block '<S6>/Switch1' : Unused code path elimination
 * Block '<S6>/offset2' : Unused code path elimination
 * Block '<S6>/offset3' : Unused code path elimination
 * Block '<S6>/offset4' : Unused code path elimination
 * Block '<S7>/Add3' : Unused code path elimination
 * Block '<S7>/Add4' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S7>/Relational Operator' : Unused code path elimination
 * Block '<S7>/Switch1' : Unused code path elimination
 * Block '<S7>/offset2' : Unused code path elimination
 * Block '<S7>/offset3' : Unused code path elimination
 * Block '<S7>/offset4' : Unused code path elimination
 * Block '<S8>/Add3' : Unused code path elimination
 * Block '<S8>/Add4' : Unused code path elimination
 * Block '<S8>/Constant' : Unused code path elimination
 * Block '<S8>/Relational Operator' : Unused code path elimination
 * Block '<S8>/Switch1' : Unused code path elimination
 * Block '<S8>/offset2' : Unused code path elimination
 * Block '<S8>/offset3' : Unused code path elimination
 * Block '<S8>/offset4' : Unused code path elimination
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
 * Block '<S11>/Add3' : Unused code path elimination
 * Block '<S11>/Add4' : Unused code path elimination
 * Block '<S11>/Constant' : Unused code path elimination
 * Block '<S11>/Relational Operator' : Unused code path elimination
 * Block '<S11>/Switch1' : Unused code path elimination
 * Block '<S11>/offset2' : Unused code path elimination
 * Block '<S11>/offset3' : Unused code path elimination
 * Block '<S11>/offset4' : Unused code path elimination
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
 * '<Root>' : AFA_F04_Calc_Sensitivity_Pap
 * '<S1>'   : AFA_F04_Calc_Sensitivity_Pap/Div_float_only
 * '<S2>'   : AFA_F04_Calc_Sensitivity_Pap/Div_float_only1
 * '<S3>'   : AFA_F04_Calc_Sensitivity_Pap/Div_float_only2
 * '<S4>'   : AFA_F04_Calc_Sensitivity_Pap/SingleToFixdt
 * '<S5>'   : AFA_F04_Calc_Sensitivity_Pap/SingleToFixdt1
 * '<S6>'   : AFA_F04_Calc_Sensitivity_Pap/SingleToFixdt2
 * '<S7>'   : AFA_F04_Calc_Sensitivity_Pap/SingleToFixdt3
 * '<S8>'   : AFA_F04_Calc_Sensitivity_Pap/SingleToFixdt4
 * '<S9>'   : AFA_F04_Calc_Sensitivity_Pap/SingleToFixdt5
 * '<S10>'  : AFA_F04_Calc_Sensitivity_Pap/SingleToFixdt6
 * '<S11>'  : AFA_F04_Calc_Sensitivity_Pap/SingleToFixdt7
 * '<S12>'  : AFA_F04_Calc_Sensitivity_Pap/Div_float_only/Data Type Police Only single
 * '<S13>'  : AFA_F04_Calc_Sensitivity_Pap/Div_float_only/If Action Subsystem3
 * '<S14>'  : AFA_F04_Calc_Sensitivity_Pap/Div_float_only1/Data Type Police Only single
 * '<S15>'  : AFA_F04_Calc_Sensitivity_Pap/Div_float_only1/If Action Subsystem3
 * '<S16>'  : AFA_F04_Calc_Sensitivity_Pap/Div_float_only2/Data Type Police Only single
 * '<S17>'  : AFA_F04_Calc_Sensitivity_Pap/Div_float_only2/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F04_Calc_Sensitivity_Pap
 */
#endif                                 /* RTW_HEADER_AFA_F04_Calc_Sensitivity_Pap_h_ */

/*-------------------------------- end of file -------------------------------*/
