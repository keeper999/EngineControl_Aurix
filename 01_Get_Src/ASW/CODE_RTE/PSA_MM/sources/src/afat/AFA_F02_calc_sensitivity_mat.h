/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F02_calc_sensitivity_mat                            */
/*                                                                            */
/* !File            : AFA_F02_calc_sensitivity_mat.h                          */
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
/*   Model name       : AFA_F02_calc_sensitivity_mat.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F02_calc_sensitivity_mat_h_
#define RTW_HEADER_AFA_F02_calc_sensitivity_mat_h_
#ifndef AFA_F02_calc_sensitivity_mat_COMMON_INCLUDES_
# define AFA_F02_calc_sensitivity_mat_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F02_calc_sensitivity_mat_import.h"
#endif                                 /* AFA_F02_calc_sensitivity_mat_COMMON_INCLUDES_ */

#include "AFA_F02_calc_sensitivity_mat_types.h"

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
extern SInt32 AFA_prm_facSenTransMat1_MP[2];/* '<Root>/Data Store Memory1' */
extern SInt32 AFA_prm_facSenTransMat2_MP[2];/* '<Root>/Data Store Memory2' */
extern SInt32 AFA_prm_facSenTransMat3_MP[2];/* '<Root>/Data Store Memory3' */
extern SInt32 AFA_prm_facSenTransMat4_MP[2];/* '<Root>/Data Store Memory4' */
extern SInt32 AFA_prm_facSenTransMat5_MP[2];/* '<Root>/Data Store Memory5' */
extern SInt32 AFA_prm_facSenTransMat6_MP[2];/* '<Root>/Data Store Memory6' */
extern SInt32 AFA_prm_facSenTransMat7_MP[2];/* '<Root>/Data Store Memory7' */
extern SInt32 AFA_prm_facSenTransMat8_MP[2];/* '<Root>/Data Store Memory8' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F02_calc_sensitivi_Start(void);
extern void mr_AFA_F02_calc_sensitivity_mat(const Boolean
  rtu_AFA_prm_bMaskSenMat_PIM[16], const UInt16 *rtu_AFA_pGrdDsThr_arEffThr,
  const UInt16 *rtu_AFA_pGrdDsThr_facArEffThrOf, const UInt16
  *rtu_AFA_pGrdDsThr_facArEffThr_p, const UInt16
  *rtu_AFA_pGrdDsThr_facArEffThr_d, const UInt16 *rtu_AFA_rlamGrd_arEffThr,
  const UInt16 *rtu_AFA_rlamGrd_facArEffThrOfs1, const UInt16
  *rtu_AFA_rlamGrd_facArEffThrOfs2, const UInt16
  *rtu_AFA_rlamGrd_facArEffThrOfs3, const UInt16 *rtu_AFA_rlamGrd_arEffEGRVlv,
  const UInt16 *rtu_AFA_pGrdDsThr_arEffEGRVlv, const UInt16
  *rtu_AFA_rlamGrd_tiOffInj, const UInt16 *rtu_AFA_rlamGrd_facIvsInjGain,
  const UInt32 *rtu_AFA_rlamGrd_facSlopInjGain, const SInt16
  *rtu_AFA_rlamGrd_agCkEx, const SInt16 *rtu_AFA_pGrdDsThr_agCkEx, const
  SInt16 *rtu_AFA_pGrdDsThr_agCkIn, const SInt16 *rtu_AFA_rlamGrd_agCkIn,
  SInt32 rty_AFA_prm_facSenTransMat_PIM[16]);

/* Model reference registration function */
extern void mr_AFA_F02_calc_sens_initialize(void);

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
 * Block '<Root>/Reshape1' : Reshape block reduction
 * Block '<Root>/Reshape2' : Reshape block reduction
 * Block '<S1>/Switch' : Eliminated due to constant selection input
 * Block '<S2>/Switch' : Eliminated due to constant selection input
 * Block '<S3>/Switch' : Eliminated due to constant selection input
 * Block '<S4>/Switch' : Eliminated due to constant selection input
 * Block '<S5>/Switch' : Eliminated due to constant selection input
 * Block '<S6>/Switch' : Eliminated due to constant selection input
 * Block '<S7>/Switch' : Eliminated due to constant selection input
 * Block '<S8>/Switch' : Eliminated due to constant selection input
 * Block '<S9>/Switch' : Eliminated due to constant selection input
 * Block '<S1>/Add2' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/offset1' : Unused code path elimination
 * Block '<S2>/Add2' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/offset1' : Unused code path elimination
 * Block '<S3>/Add2' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/offset1' : Unused code path elimination
 * Block '<S4>/Add2' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S4>/offset1' : Unused code path elimination
 * Block '<S5>/Add2' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S5>/offset1' : Unused code path elimination
 * Block '<S6>/Add2' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<S6>/offset1' : Unused code path elimination
 * Block '<S7>/Add2' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S7>/offset1' : Unused code path elimination
 * Block '<S8>/Add2' : Unused code path elimination
 * Block '<S8>/Constant' : Unused code path elimination
 * Block '<S8>/offset1' : Unused code path elimination
 * Block '<S9>/Add2' : Unused code path elimination
 * Block '<S9>/Constant' : Unused code path elimination
 * Block '<S9>/offset1' : Unused code path elimination
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
 * '<Root>' : AFA_F02_calc_sensitivity_mat
 * '<S1>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt
 * '<S2>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt1
 * '<S3>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt2
 * '<S4>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt3
 * '<S5>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt4
 * '<S6>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt5
 * '<S7>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt6
 * '<S8>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt7
 * '<S9>'   : AFA_F02_calc_sensitivity_mat/SingleToFixdt8
 */

/*-
 * Requirements for '<Root>': AFA_F02_calc_sensitivity_mat
 */
#endif                                 /* RTW_HEADER_AFA_F02_calc_sensitivity_mat_h_ */

/*-------------------------------- end of file -------------------------------*/
