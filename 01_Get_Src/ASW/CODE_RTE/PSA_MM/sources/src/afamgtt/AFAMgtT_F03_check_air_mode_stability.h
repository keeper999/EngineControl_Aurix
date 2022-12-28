/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT_F03_check_air_mode_stability                    */
/*                                                                            */
/* !File            : AFAMgtT_F03_check_air_mode_stability.h                  */
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
/*   Model name       : AFAMgtT_F03_check_air_mode_stability.mdl              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Jul 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFAMgtT_F03_check_air_mode_stability_h_
#define RTW_HEADER_AFAMgtT_F03_check_air_mode_stability_h_
#ifndef AFAMgtT_F03_check_air_mode_stability_COMMON_INCLUDES_
# define AFAMgtT_F03_check_air_mode_stability_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFAMgtT_F03_check_air_mode_stability_import.h"
#endif                                 /* AFAMgtT_F03_check_air_mode_stability_COMMON_INCLUDES_ */

#include "AFAMgtT_F03_check_air_mode_stability_types.h"

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

/* Model reference registration function */
extern void mr_AFAMgtT_F03_check_initialize(void);




extern void mr_AFAMgtT_F03_check_air_mode_s(const Boolean
  *rtu_FRM_bInhInMNomMod, const Boolean *rtu_AFAMgt_bEveRstStab1, const
  Boolean *rtu_AFAMgt_bInhAF1, const UInt32 *rtu_AFAMgt_tiCntStabAirModPrev,
  const Boolean *rtu_AFAMgt_bInhAirModPrev, Boolean
  *rty_AFAMgt_bIdcStabAirMod, UInt32 *rty_AFAMgt_tiCntStabAirMod, Boolean
  *rty_AFAMgt_bInhAirModTmp);

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
 * '<Root>' : AFAMgtT_F03_check_air_mode_stability
 * '<S1>'   : AFAMgtT_F03_check_air_mode_stability/F01_Afa_air_mode_stable_no_check
 * '<S2>'   : AFAMgtT_F03_check_air_mode_stability/F02_Afa_air_mode_stable_check
 * '<S3>'   : AFAMgtT_F03_check_air_mode_stability/F02_Afa_air_mode_stable_check/F01_Afa_air_mode_stable
 * '<S4>'   : AFAMgtT_F03_check_air_mode_stability/F02_Afa_air_mode_stable_check/F02_Afa_air_mode_stable_Wait
 */

/*-
 * Requirements for '<Root>': AFAMgtT_F03_check_air_mode_stability
 */
#endif                                 /* RTW_HEADER_AFAMgtT_F03_check_air_mode_stability_h_ */

/*-------------------------------- end of file -------------------------------*/
