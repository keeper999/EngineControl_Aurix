/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F03_Slop_correction                                 */
/*                                                                            */
/* !File            : AFA_F03_Slop_correction.h                               */
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
/*   Model name       : AFA_F03_Slop_correction.mdl                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F03_Slop_correction_h_
#define RTW_HEADER_AFA_F03_Slop_correction_h_
#ifndef AFA_F03_Slop_correction_COMMON_INCLUDES_
# define AFA_F03_Slop_correction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F03_Slop_correction_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FloorF.h"
#include "ACTEMS_LdexpF.h"
#include "rt_MAXf.h"
#include "rt_MINf.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F03_Slop_correction_COMMON_INCLUDES_ */

#include "AFA_F03_Slop_correction_types.h"

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
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern UInt32 AFA_facChgCorSlopEfc_MP;/* '<S3>/Data Store Memory1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


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
extern UInt16 AFA_nEngCorSlopFil;    /* '<S5>/Switch' */
extern UInt16 AFA_facCorSlopEfc;     /* '<S4>/Sum' */
extern UInt16 AFA_facCorBoostSlopEfc;/* '<S8>/Look-Up Table (2-D)' */
extern UInt16 AFA_facCorAtmSlopEfc;  /* '<S6>/Look-Up Table (2-D)' */
extern SInt16 AFA_facCorSlopGrdEfc_agCkIn;/* '<S4>/Sum6' */
extern SInt16 AFA_facCorBoostGrdSlopEfc_agCkIn;/* '<S2>/Data Type Conversion2' */
extern SInt16 AFA_facCorAtmGrdSlopEfc_agCkIn;/* '<S1>/Data Type Conversion3' */
extern UInt16 AFA_facChgCorSlopEfc;  /* '<S11>/Look-Up Table' */
extern UInt16 AFA_facChgCorGrdSlopEfc_agCkIn;/* '<S12>/Look-Up Table' */
extern UInt16 AFA_facChgCorSlopEfcMax_MP;/* '<S3>/Data Store Memory' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F03_Slop_correction(const UInt16
  *rtu_AFA_agCkClsInVlvEstimRef1Fi, const UInt16 *rtu_AFA_nEngFil, const
  UInt16 *rtu_AFA_pDsThrFil, const UInt16 *rtu_AFA_pAirExtEstimFil, const
  UInt16 *rtu_AFA_nEngCorFil, UInt16 *rty_AFA_facCorSlopEfc, SInt16
  *rty_AFA_facCorSlopGrdEfc_agCkIn);

/* Model reference registration function */
extern void mr_AFA_F03_Slop_corr_initialize(void);

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
 * Block '<S1>/AFA_agCkGrdClsInVlvX_A' : Unused code path elimination
 * Block '<S1>/AirEfc_agCkClsInVlvX_A' : Unused code path elimination
 * Block '<S1>/AirEfc_nEngY_A' : Unused code path elimination
 * Block '<S1>/AirEfc_nEngY_A1' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S6>/TABLE' : Unused code path elimination
 * Block '<S6>/TABLE1' : Unused code path elimination
 * Block '<S6>/TABLE2' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S7>/TABLE' : Unused code path elimination
 * Block '<S7>/TABLE1' : Unused code path elimination
 * Block '<S7>/TABLE2' : Unused code path elimination
 * Block '<S2>/AFA_agCkGrdClsInVlvX_A' : Unused code path elimination
 * Block '<S2>/AirEfc_agCkClsInVlvX_A' : Unused code path elimination
 * Block '<S2>/AirEfc_nEngY_A' : Unused code path elimination
 * Block '<S2>/AirEfc_nEngY_A1' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S8>/TABLE' : Unused code path elimination
 * Block '<S8>/TABLE1' : Unused code path elimination
 * Block '<S8>/TABLE2' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S9>/TABLE' : Unused code path elimination
 * Block '<S9>/TABLE1' : Unused code path elimination
 * Block '<S9>/TABLE2' : Unused code path elimination
 * Block '<S3>/AFA_agCkGrdClsInVlvX_A' : Unused code path elimination
 * Block '<S3>/AirEfc_agCkClsInVlvX_A' : Unused code path elimination
 * Block '<S3>/AirEfc_facChgCorSlopEfc_A' : Unused code path elimination
 * Block '<S3>/AirEfc_facChgCorSlopEfc_A1' : Unused code path elimination
 * Block '<S3>/AirEfc_nEngY_A' : Unused code path elimination
 * Block '<S3>/AirEfc_nEngY_A1' : Unused code path elimination
 * Block '<S3>/AirEfc_pRef_C1' : Unused code path elimination
 * Block '<S10>/BKPT1' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S10>/TABLE' : Unused code path elimination
 * Block '<S11>/BKPT1' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S11>/TABLE' : Unused code path elimination
 * Block '<S12>/BKPT1' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S12>/TABLE' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S13>/TABLE' : Unused code path elimination
 * Block '<S13>/TABLE1' : Unused code path elimination
 * Block '<S13>/TABLE2' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S14>/TABLE' : Unused code path elimination
 * Block '<S14>/TABLE1' : Unused code path elimination
 * Block '<S14>/TABLE2' : Unused code path elimination
 * Block '<S17>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/Data Type Propagation1' : Unused code path elimination
 * Block '<S20>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Unused code path elimination
 * Block '<S20>/Data Type Conversion1' : Unused code path elimination
 * Block '<S18>/Data Type Propagation' : Unused code path elimination
 * Block '<S18>/Data Type Propagation1' : Unused code path elimination
 * Block '<S22>/Data Type Propagation' : Unused code path elimination
 * Block '<S22>/Data Type Conversion' : Unused code path elimination
 * Block '<S22>/Data Type Conversion1' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Data Type Propagation1' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/Data Type Conversion' : Unused code path elimination
 * Block '<S24>/Data Type Conversion1' : Unused code path elimination
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Signal Conversion1' : Eliminate redundant signal conversion block
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
 * '<Root>' : AFA_F03_Slop_correction
 * '<S1>'   : AFA_F03_Slop_correction/F01_Atmospheric_slop_correction
 * '<S2>'   : AFA_F03_Slop_correction/F02_Boost_slop_correction
 * '<S3>'   : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction
 * '<S4>'   : AFA_F03_Slop_correction/F04_Slop_correction_calculation
 * '<S5>'   : AFA_F03_Slop_correction/F05_Engine_speed_choice
 * '<S6>'   : AFA_F03_Slop_correction/F01_Atmospheric_slop_correction/Carto_2D
 * '<S7>'   : AFA_F03_Slop_correction/F01_Atmospheric_slop_correction/Carto_2D1
 * '<S8>'   : AFA_F03_Slop_correction/F02_Boost_slop_correction/Carto_2D
 * '<S9>'   : AFA_F03_Slop_correction/F02_Boost_slop_correction/Carto_2D1
 * '<S10>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Carto_1D
 * '<S11>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Carto_1D1
 * '<S12>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Carto_1D2
 * '<S13>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Carto_2D
 * '<S14>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Carto_2D1
 * '<S15>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/CompareToConstant
 * '<S16>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/CompareToZero
 * '<S17>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only
 * '<S18>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only1
 * '<S19>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only2
 * '<S20>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only/Data Type Police Only single
 * '<S21>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only/If Action Subsystem3
 * '<S22>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only1/Data Type Police Only single
 * '<S23>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only1/If Action Subsystem3
 * '<S24>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only2/Data Type Police Only single
 * '<S25>'  : AFA_F03_Slop_correction/F03_Coefficient_atmospheric_to_boost_slop_correction/Div_float_only2/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F03_Slop_correction
 */
#endif                                 /* RTW_HEADER_AFA_F03_Slop_correction_h_ */

/*-------------------------------- end of file -------------------------------*/
