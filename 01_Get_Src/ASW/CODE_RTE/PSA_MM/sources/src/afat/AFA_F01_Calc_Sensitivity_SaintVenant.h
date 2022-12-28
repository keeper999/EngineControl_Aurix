/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F01_Calc_Sensitivity_SaintVenant                    */
/*                                                                            */
/* !File            : AFA_F01_Calc_Sensitivity_SaintVenant.h                  */
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
/*   Model name       : AFA_F01_Calc_Sensitivity_SaintVenant.mdl              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F01_Calc_Sensitivity_SaintVenant_h_
#define RTW_HEADER_AFA_F01_Calc_Sensitivity_SaintVenant_h_
#ifndef AFA_F01_Calc_Sensitivity_SaintVenant_COMMON_INCLUDES_
# define AFA_F01_Calc_Sensitivity_SaintVenant_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F01_Calc_Sensitivity_SaintVenant_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_LdexpF.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F01_Calc_Sensitivity_SaintVenant_COMMON_INCLUDES_ */

#include "AFA_F01_Calc_Sensitivity_SaintVenant_types.h"

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
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern UInt16 AFA_mfArGrdVlv_rPresInEx;/* '<Root>/Data Store Memory' */
extern UInt16 AFA_mfArGrdVlv_rPres_MP[2];/* '<Root>/Data Store Memory3' */
extern UInt16 AFA_mfArGrdVlv_rPresExIn;/* '<Root>/Data Store Memory1' */
extern UInt16 AFA_mfArThr_rAirPres;  /* '<Root>/Data Store Memory2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F01_Calc_Sensitivi_Start(void);
extern void mr_AFA_F01_Calc_Sensitivity_Sai(const UInt16 *rtu_AFA_pDsThrFil,
  const UInt16 *rtu_AFA_pExMnfEstimFil, const UInt16 *rtu_AFA_rAirPresFil,
  UInt16 *rty_AFA_mfArGrdVlv_rPresInEx, UInt16 *rty_AFA_mfArGrdVlv_rPresExIn,
  UInt16 *rty_AFA_mfArThr_rAirPres);

/* Model reference registration function */
extern void mr_AFA_F01_Calc_Sens_initialize(void);

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
 * Block '<S1>/BKPT1' : Unused code path elimination
 * Block '<S1>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S1>/TABLE' : Unused code path elimination
 * Block '<S2>/BKPT1' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S2>/TABLE' : Unused code path elimination
 * Block '<S3>/BKPT1' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S3>/TABLE' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/Data Type Propagation1' : Unused code path elimination
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/Data Type Conversion' : Unused code path elimination
 * Block '<S7>/Data Type Conversion1' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Data Type Propagation1' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Unused code path elimination
 * Block '<S9>/Data Type Conversion1' : Unused code path elimination
 * Block '<S6>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/Data Type Propagation1' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/Data Type Conversion' : Unused code path elimination
 * Block '<S11>/Data Type Conversion1' : Unused code path elimination
 * Block '<Root>/Ratio_Critique10' : Unused code path elimination
 * Block '<Root>/Ratio_Critique11' : Unused code path elimination
 * Block '<Root>/Ratio_Critique9' : Unused code path elimination
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<Root>/Signal Conversion1' : Eliminate redundant signal conversion block
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
 * '<Root>' : AFA_F01_Calc_Sensitivity_SaintVenant
 * '<S1>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Carto_1D
 * '<S2>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Carto_1D1
 * '<S3>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Carto_1D2
 * '<S4>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only
 * '<S5>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only1
 * '<S6>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only2
 * '<S7>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only/Data Type Police Only single
 * '<S8>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only/If Action Subsystem3
 * '<S9>'   : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only1/Data Type Police Only single
 * '<S10>'  : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only1/If Action Subsystem3
 * '<S11>'  : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only2/Data Type Police Only single
 * '<S12>'  : AFA_F01_Calc_Sensitivity_SaintVenant/Div_float_only2/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F01_Calc_Sensitivity_SaintVenant
 */
#endif                                 /* RTW_HEADER_AFA_F01_Calc_Sensitivity_SaintVenant_h_ */

/*-------------------------------- end of file -------------------------------*/
