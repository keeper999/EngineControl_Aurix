/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT_F01_AFAAdpCndChk                                */
/*                                                                            */
/* !File            : AFAMgtT_F01_AFAAdpCndChk.h                              */
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
/*   Model name       : AFAMgtT_F01_AFAAdpCndChk.mdl                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Jul 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFAMgtT_F01_AFAAdpCndChk_h_
#define RTW_HEADER_AFAMgtT_F01_AFAAdpCndChk_h_
#ifndef AFAMgtT_F01_AFAAdpCndChk_COMMON_INCLUDES_
# define AFAMgtT_F01_AFAAdpCndChk_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFAMgtT_F01_AFAAdpCndChk_import.h"
#endif                                 /* AFAMgtT_F01_AFAAdpCndChk_COMMON_INCLUDES_ */

#include "AFAMgtT_F01_AFAAdpCndChk_types.h"

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
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

extern void mr_AFAMgtT_F01_AFAAdpCndChk(const UInt16 *rtu_AFA_noAdpEfc, const
  UInt8 *rtu_AFA_noObsDone, const Boolean *rtu_AFA_bIdcCohLstObs, Boolean *
  rty_AFAMgt_bAdpEfc1);

/* Model reference registration function */
extern void mr_AFAMgtT_F01_AFAAd_initialize(void);

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

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
 * '<Root>' : AFAMgtT_F01_AFAAdpCndChk
 * '<S1>'   : AFAMgtT_F01_AFAAdpCndChk/AFAMgtT_F01_AFAAdpCndChk
 */

/*-
 * Requirements for '<Root>': AFAMgtT_F01_AFAAdpCndChk
 */
#endif                                 /* RTW_HEADER_AFAMgtT_F01_AFAAdpCndChk_h_ */

/*-------------------------------- end of file -------------------------------*/
