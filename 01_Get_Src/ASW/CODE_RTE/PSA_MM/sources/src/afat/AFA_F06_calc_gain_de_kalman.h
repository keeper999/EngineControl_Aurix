/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F06_calc_gain_de_kalman                             */
/*                                                                            */
/* !File            : AFA_F06_calc_gain_de_kalman.h                           */
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
/*   Model name       : AFA_F06_calc_gain_de_kalman.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F06_calc_gain_de_kalman_h_
#define RTW_HEADER_AFA_F06_calc_gain_de_kalman_h_
#ifndef AFA_F06_calc_gain_de_kalman_COMMON_INCLUDES_
# define AFA_F06_calc_gain_de_kalman_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AFA_F06_calc_gain_de_kalman_COMMON_INCLUDES_ */

#include "AFA_F06_calc_gain_de_kalman_types.h"

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

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F06_calc_gain_de_kalman(const UInt16
  rtu_AFA_prm_covIvsPredInnovMat_[4], const Boolean *rtu_AFA_bIdcInv_covPred4,
  const SInt32 rtu_AFA_prm_facSenTransMat_PIM[16], const UInt16
  rtu_AFA_prm_covPredE[64], SInt16 rty_AFA_prm_facKalmMat_PIM[16]);

/* Model reference registration function */
extern void mr_AFA_F06_calc_gain_initialize(void);

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
 * Block '<S1>/Switch' : Eliminated due to constant selection input
 * Block '<S1>/Add2' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/offset1' : Unused code path elimination
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
 * '<Root>' : AFA_F06_calc_gain_de_kalman
 * '<S1>'   : AFA_F06_calc_gain_de_kalman/SingleToFixdt1
 */

/*-
 * Requirements for '<Root>': AFA_F06_calc_gain_de_kalman
 */
#endif                                 /* RTW_HEADER_AFA_F06_calc_gain_de_kalman_h_ */

/*-------------------------------- end of file -------------------------------*/
