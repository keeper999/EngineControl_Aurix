/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F02_Afa_adapt_terms_reset                           */
/*                                                                            */
/* !File            : AFA_F02_Afa_adapt_terms_reset.h                         */
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
/*   Model name       : AFA_F02_Afa_adapt_terms_reset.mdl                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   01 Feb 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F02_Afa_adapt_terms_reset_h_
#define RTW_HEADER_AFA_F02_Afa_adapt_terms_reset_h_
#ifndef AFA_F02_Afa_adapt_terms_reset_COMMON_INCLUDES_
# define AFA_F02_Afa_adapt_terms_reset_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F02_Afa_adapt_terms_reset_import.h"
#include "rtw_shared_utils.h"
#endif                                 /* AFA_F02_Afa_adapt_terms_reset_COMMON_INCLUDES_ */

#include "AFA_F02_Afa_adapt_terms_reset_types.h"

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

extern void mr_AFA_F02_Afa_adapt_terms_rese(SInt16 *rty_AFA_facIvsInjGai1,
  SInt8 *rty_AFA_tiOffInj, SInt32 *rty_AFA_facSlopInjGai1, SInt16
  *rty_AFA_arEffThrOfs, SInt8 *rty_AFA_facArEffThrOf11, SInt8
  *rty_AFA_facArEffThrOf21, SInt8 *rty_AFA_facArEffThrOf31, SInt8
  *rty_AFA_rCor_arEffEGRVl1, SInt8 *rty_AFA_agCkOpInVlvOf1, SInt8
  *rty_AFA_agCkClsExVlvOf1, SInt8 *rty_AFA_arEffEGRVl1);

/* Model reference registration function */
extern void mr_AFA_F02_Afa_adapt_initialize(void);

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
 * '<Root>' : AFA_F02_Afa_adapt_terms_reset
 */

/*-
 * Requirements for '<Root>': AFA_F02_Afa_adapt_terms_reset
 */
#endif                                 /* RTW_HEADER_AFA_F02_Afa_adapt_terms_reset_h_ */

/*-------------------------------- end of file -------------------------------*/
