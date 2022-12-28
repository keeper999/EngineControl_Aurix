/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F10_Total_load_gradient                             */
/*                                                                            */
/* !File            : AFA_F10_Total_load_gradient.h                           */
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
/*   Model name       : AFA_F10_Total_load_gradient.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F10_Total_load_gradient_h_
#define RTW_HEADER_AFA_F10_Total_load_gradient_h_
#ifndef AFA_F10_Total_load_gradient_COMMON_INCLUDES_
# define AFA_F10_Total_load_gradient_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F10_Total_load_gradient_COMMON_INCLUDES_ */

#include "AFA_F10_Total_load_gradient_types.h"

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
extern UInt32 AFA_rTotLdGrd_pDsThr;  /* '<S1>/Data Type Conversion2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F10_Total_load_gradient(const UInt16
  *rtu_AFA_facSlopEfcGrd_pDsThr, const UInt16 *rtu_AFA_rTotLdExCorFil, const
  UInt32 *rtu_AFA_facOfsEfcGrd_pDsThr, const UInt16 *rtu_AFA_rMassAirScv,
  UInt32 *rty_AFA_rTotLdGrd_pDsThr);

/* Model reference registration function */
extern void mr_AFA_F10_Total_loa_initialize(void);

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
 * Block '<S2>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/Data Type Conversion' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : AFA_F10_Total_load_gradient
 * '<S1>'   : AFA_F10_Total_load_gradient/Div_float_only
 * '<S2>'   : AFA_F10_Total_load_gradient/Div_float_only/Data Type Police Only single
 * '<S3>'   : AFA_F10_Total_load_gradient/Div_float_only/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F10_Total_load_gradient
 */
#endif                                 /* RTW_HEADER_AFA_F10_Total_load_gradient_h_ */

/*-------------------------------- end of file -------------------------------*/
