/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F08_burn_gas_temperature                            */
/*                                                                            */
/* !File            : AFA_F08_burn_gas_temperature.h                          */
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
/*   Model name       : AFA_F08_burn_gas_temperature.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F08_burn_gas_temperature_h_
#define RTW_HEADER_AFA_F08_burn_gas_temperature_h_
#ifndef AFA_F08_burn_gas_temperature_COMMON_INCLUDES_
# define AFA_F08_burn_gas_temperature_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F08_burn_gas_temperature_import.h"
#include "rtw_shared_utils.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F08_burn_gas_temperature_COMMON_INCLUDES_ */

#include "AFA_F08_burn_gas_temperature_types.h"

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
extern UInt16 AFA_facTBurnCyl;       /* '<S14>/OutDTConv' */
extern SInt16 AFA_facTBurnGrdCyl_agCkEx;/* '<S15>/OutDTConv' */
extern SInt16 AFA_facTBurnGrdCyl_agCkIn;/* '<S16>/OutDTConv' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern UInt16 AFA_rMassBurn1_MP;     /* '<Root>/Data Store Memory1' */
extern UInt16 AFA_rMassBurn2_MP;     /* '<Root>/Data Store Memory2' */
extern UInt16 AFA_rMassBurn3_MP;     /* '<Root>/Data Store Memory3' */
extern UInt16 AFA_rMassBurn4_MP;     /* '<Root>/Data Store Memory4' */
extern UInt16 AFA_tBurnCyl_MP;       /* '<Root>/Data Store Memory5' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F08_burn_gas_temperature(const UInt16
  *rtu_AFA_tExMnfEstimF8, const UInt16 *rtu_AFA_pDsThrPred_facVlvOvlpFi, const
  UInt16 *rtu_AFA_pExMnfEstimF8, const UInt16 *rtu_AFA_rMassBurnRspg, const
  SInt16 *rtu_AFA_rMassGrdBurnRspg_agCkEx, const SInt16
  *rtu_AFA_rMassGrdBurnRspg_agCkIn, const UInt16 *rtu_AFA_rMassBurnRg, const
  SInt16 *rtu_AFA_rMassGrdBurnRg_agCkEx, const SInt16
  *rtu_AFA_rMassGrdBurnRg_agCkIn, const UInt16 *rtu_AFA_rMassBurn, const
  SInt16 *rtu_AFA_rMassBurn_agCkEx, const SInt16 *rtu_AFA_rMassBurn_agCkIn,
  UInt16 *rty_AFA_facTBurnCyl, SInt16 *rty_AFA_facTBurnGrdCyl_agCkEx, SInt16
  *rty_AFA_facTBurnGrdCyl_agCkIn);

/* Model reference registration function */
extern void mr_AFA_F08_burn_gas__initialize(void);

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
 * Block '<S7>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/x1' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S8>/x1' : Unused code path elimination
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
 * Block '<Root>/Signal Conversion5' : Eliminate redundant signal conversion block
 * Block '<S9>/Switch' : Eliminated due to constant selection input
 * Block '<S10>/Switch' : Eliminated due to constant selection input
 * Block '<S11>/Switch' : Eliminated due to constant selection input
 * Block '<S12>/Switch' : Eliminated due to constant selection input
 * Block '<S13>/Switch' : Eliminated due to constant selection input
 * Block '<S14>/Switch' : Eliminated due to constant selection input
 * Block '<S15>/Switch' : Eliminated due to constant selection input
 * Block '<S16>/Switch' : Eliminated due to constant selection input
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
 * Block '<S12>/Add3' : Unused code path elimination
 * Block '<S12>/Add4' : Unused code path elimination
 * Block '<S12>/Constant' : Unused code path elimination
 * Block '<S12>/Relational Operator' : Unused code path elimination
 * Block '<S12>/Switch1' : Unused code path elimination
 * Block '<S12>/offset2' : Unused code path elimination
 * Block '<S12>/offset3' : Unused code path elimination
 * Block '<S12>/offset4' : Unused code path elimination
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
 * Block '<S15>/Add2' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S15>/offset1' : Unused code path elimination
 * Block '<S16>/Add2' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S16>/offset1' : Unused code path elimination
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
 * '<Root>' : AFA_F08_burn_gas_temperature
 * '<S1>'   : AFA_F08_burn_gas_temperature/Div_float_only
 * '<S2>'   : AFA_F08_burn_gas_temperature/Div_float_only2
 * '<S3>'   : AFA_F08_burn_gas_temperature/Div_float_only3
 * '<S4>'   : AFA_F08_burn_gas_temperature/Div_float_only4
 * '<S5>'   : AFA_F08_burn_gas_temperature/Div_float_only5
 * '<S6>'   : AFA_F08_burn_gas_temperature/Div_float_only6
 * '<S7>'   : AFA_F08_burn_gas_temperature/LookUp_1D
 * '<S8>'   : AFA_F08_burn_gas_temperature/LookUp_1D1
 * '<S9>'   : AFA_F08_burn_gas_temperature/SingleToFixdt
 * '<S10>'  : AFA_F08_burn_gas_temperature/SingleToFixdt1
 * '<S11>'  : AFA_F08_burn_gas_temperature/SingleToFixdt2
 * '<S12>'  : AFA_F08_burn_gas_temperature/SingleToFixdt3
 * '<S13>'  : AFA_F08_burn_gas_temperature/SingleToFixdt4
 * '<S14>'  : AFA_F08_burn_gas_temperature/SingleToFixdt5
 * '<S15>'  : AFA_F08_burn_gas_temperature/SingleToFixdt6
 * '<S16>'  : AFA_F08_burn_gas_temperature/SingleToFixdt7
 * '<S17>'  : AFA_F08_burn_gas_temperature/Div_float_only/Data Type Police Only single
 * '<S18>'  : AFA_F08_burn_gas_temperature/Div_float_only/If Action Subsystem3
 * '<S19>'  : AFA_F08_burn_gas_temperature/Div_float_only2/Data Type Police Only single
 * '<S20>'  : AFA_F08_burn_gas_temperature/Div_float_only2/If Action Subsystem3
 * '<S21>'  : AFA_F08_burn_gas_temperature/Div_float_only3/Data Type Police Only single
 * '<S22>'  : AFA_F08_burn_gas_temperature/Div_float_only3/If Action Subsystem3
 * '<S23>'  : AFA_F08_burn_gas_temperature/Div_float_only4/Data Type Police Only single
 * '<S24>'  : AFA_F08_burn_gas_temperature/Div_float_only4/If Action Subsystem3
 * '<S25>'  : AFA_F08_burn_gas_temperature/Div_float_only5/Data Type Police Only single
 * '<S26>'  : AFA_F08_burn_gas_temperature/Div_float_only5/If Action Subsystem3
 * '<S27>'  : AFA_F08_burn_gas_temperature/Div_float_only6/Data Type Police Only single
 * '<S28>'  : AFA_F08_burn_gas_temperature/Div_float_only6/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F08_burn_gas_temperature
 */
#endif                                 /* RTW_HEADER_AFA_F08_burn_gas_temperature_h_ */

/*-------------------------------- end of file -------------------------------*/
