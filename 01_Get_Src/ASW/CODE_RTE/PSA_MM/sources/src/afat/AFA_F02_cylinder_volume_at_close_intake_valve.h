/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F02_cylinder_volume_at_close_intake_valve           */
/*                                                                            */
/* !File            : AFA_F02_cylinder_volume_at_close_intake_valve.h         */
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
/*   Model name       : AFA_F02_cylinder_volume_at_close_intake_valve.mdl     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F02_cylinder_volume_at_close_intake_valve_h_
#define RTW_HEADER_AFA_F02_cylinder_volume_at_close_intake_valve_h_
#ifndef AFA_F02_cylinder_volume_at_close_intake_valve_COMMON_INCLUDES_
# define AFA_F02_cylinder_volume_at_close_intake_valve_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F02_cylinder_volume_at_close_intake_valve_import.h"
#include "rtw_shared_utils.h"
#endif                                 /* AFA_F02_cylinder_volume_at_close_intake_valve_COMMON_INCLUDES_ */

#include "AFA_F02_cylinder_volume_at_close_intake_valve_types.h"

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
extern SInt32 AFA_rVolCylGrdClsInVlv_agCkIn;/* '<Root>/Switch1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

extern UInt16 AFA_rVolCylClsInVlv;   /* '<S1>/Look-Up Table' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F02_cylinder_volume_at_c(const UInt16
  *rtu_AFA_agCkClsInVlvEstimRef1_, UInt16 *rty_AFA_rVolCylClsInVlv, SInt32
  *rty_AFA_rVolCylGrdClsInVlv_agCk);

/* Model reference registration function */
extern void mr_AFA_F02_cylinder__initialize(void);

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
 * Block '<Root>/AFA_agCk_facTDCGrd_A' : Unused code path elimination
 * Block '<Root>/AirEfc_agCk_facTDC_A' : Unused code path elimination
 * Block '<S1>/BKPT1' : Unused code path elimination
 * Block '<S1>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S1>/TABLE' : Unused code path elimination
 * Block '<S2>/BKPT1' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S2>/TABLE' : Unused code path elimination
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
 * '<Root>' : AFA_F02_cylinder_volume_at_close_intake_valve
 * '<S1>'   : AFA_F02_cylinder_volume_at_close_intake_valve/Carto_1D1
 * '<S2>'   : AFA_F02_cylinder_volume_at_close_intake_valve/Carto_1D2
 */

/*-
 * Requirements for '<Root>': AFA_F02_cylinder_volume_at_close_intake_valve
 */
#endif                                 /* RTW_HEADER_AFA_F02_cylinder_volume_at_close_intake_valve_h_ */

/*-------------------------------- end of file -------------------------------*/
