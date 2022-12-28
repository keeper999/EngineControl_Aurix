/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F04_detect_adaptation_stop                          */
/*                                                                            */
/* !File            : AFA_F04_detect_adaptation_stop.h                        */
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
/*   Model name       : AFA_F04_detect_adaptation_stop.mdl                    */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   01 Feb 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F04_detect_adaptation_stop_h_
#define RTW_HEADER_AFA_F04_detect_adaptation_stop_h_
#ifndef AFA_F04_detect_adaptation_stop_COMMON_INCLUDES_
# define AFA_F04_detect_adaptation_stop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F04_detect_adaptation_stop_import.h"
#include "rtw_shared_utils.h"
#endif                                 /* AFA_F04_detect_adaptation_stop_COMMON_INCLUDES_ */

#include "AFA_F04_detect_adaptation_stop_types.h"

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

extern void mr_AFA_F04_detect_adaptation_st(const SInt16 *rtu_AFA_facIvsInjGain,
  const SInt8 *rtu_AFA_tiOffInj, const SInt32 *rtu_AFA_facSlopInjGain, const
  SInt16 *rtu_AFA_arEffThrOfs, const SInt8 *rtu_AFA_facArEffThrOfs1, const
  SInt8 *rtu_AFA_facArEffThrOfs2, const SInt8 *rtu_AFA_facArEffThrOfs3, const
  SInt8 *rtu_AFA_rCor_arEffEGRVlv, const SInt8 *rtu_AFA_agCkOpInVlvOfs, const
  SInt8 *rtu_AFA_agCkClsExVlvOfs, Boolean *rty_AFA_bMonRunAdpIvsInjConLim,
  Boolean *rty_AFA_bDgoAdpIvsInjConLim, Boolean *rty_AFA_bMonRunAdpInjOfsLim,
  Boolean *rty_AFA_bDgoAdpInjOfsLim, Boolean
  *rty_AFA_bMonRunAdpSlopInjConLim, Boolean *rty_AFA_bDgoAdpSlopInjConLim,
  Boolean *rty_AFA_bMonRunAdpArEffThrOfsLi, Boolean
  *rty_AFA_bDgoAdpArEffThrOfsLim, Boolean *rty_AFA_bMonRunAdpArEffThrOfs1L,
  Boolean *rty_AFA_bDgoAdpArEffThrOfs1Lim, Boolean
  *rty_AFA_bMonRunAdpArEffThrOfs2L, Boolean *rty_AFA_bDgoAdpArEffThrOfs2Lim,
  Boolean *rty_AFA_bMonRunAdpArEffThrOfs3L, Boolean
  *rty_AFA_bDgoAdpArEffThrOfs3Lim, Boolean *rty_AFA_bMonRunAdpArEffEGRVlvLi,
  Boolean *rty_AFA_bDgoAdpArEffEGRVlvLim, Boolean
  *rty_AFA_bMonRunAdpOpInOfsLim, Boolean *rty_AFA_bDgoAdpOpInOfsLim, Boolean
  *rty_AFA_bMonRunAdpClsExOfsLim, Boolean *rty_AFA_bDgoAdpClsExOfsLim);

/* Model reference registration function */
extern void mr_AFA_F04_detect_ad_initialize(void);

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
 * '<Root>' : AFA_F04_detect_adaptation_stop
 * '<S1>'   : AFA_F04_detect_adaptation_stop/multiplication
 * '<S2>'   : AFA_F04_detect_adaptation_stop/multiplication1
 */

/*-
 * Requirements for '<Root>': AFA_F04_detect_adaptation_stop
 */
#endif                                 /* RTW_HEADER_AFA_F04_detect_adaptation_stop_h_ */

/*-------------------------------- end of file -------------------------------*/
