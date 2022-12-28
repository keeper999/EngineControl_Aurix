/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F02_calc_model_noise_mat                            */
/*                                                                            */
/* !File            : AFA_F02_calc_model_noise_mat.h                          */
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
/*   Model name       : AFA_F02_calc_model_noise_mat.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F02_calc_model_noise_mat_h_
#define RTW_HEADER_AFA_F02_calc_model_noise_mat_h_
#ifndef AFA_F02_calc_model_noise_mat_COMMON_INCLUDES_
# define AFA_F02_calc_model_noise_mat_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AFA_F02_calc_model_noise_mat_COMMON_INCLUDES_ */

#include "AFA_F02_calc_model_noise_mat_types.h"

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

extern void mr_AFA_F02_calc_model_noise_mat(const UInt16
  rtu_AFA_prm_covNoiseVal_PIM[8], const UInt16 rtu_AFA_prm_covErr[64],
  UInt16 rty_AFA_prm_covPredErrMat_PIM[64]);

/* Model reference registration function */
extern void mr_AFA_F02_calc_mode_initialize(void);

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
 * '<Root>' : AFA_F02_calc_model_noise_mat
 * '<S1>'   : AFA_F02_calc_model_noise_mat/Diag_Vect2Mat
 */

/*-
 * Requirements for '<Root>': AFA_F02_calc_model_noise_mat
 */
#endif                                 /* RTW_HEADER_AFA_F02_calc_model_noise_mat_h_ */

/*-------------------------------- end of file -------------------------------*/
