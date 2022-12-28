/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F01_scruter_environ_adaptation                      */
/*                                                                            */
/* !File            : AFA_F01_scruter_environ_adaptation.h                    */
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
/*   Model name       : AFA_F01_scruter_environ_adaptation.mdl                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   20 Feb 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F01_scruter_environ_adaptation_h_
#define RTW_HEADER_AFA_F01_scruter_environ_adaptation_h_
#ifndef AFA_F01_scruter_environ_adaptation_COMMON_INCLUDES_
# define AFA_F01_scruter_environ_adaptation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F01_scruter_environ_adaptation_import.h"
#include "ACTEMS_FabsF.h"
#endif                                 /* AFA_F01_scruter_environ_adaptation_COMMON_INCLUDES_ */

#include "AFA_F01_scruter_environ_adaptation_types.h"

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

extern void mr_AFA_F01_scruter_environ_adap(const UInt16
  *rtu_ThrLrn_1_rOpClsThrBol, const UInt16 *rtu_UsThrM_1_pAirExtEstim, const
  UInt32 *rtu_EGRVlv_1_rOpClsEGRVlvBol, const UInt16
  rtu_VlvAct_1_prm_agCkOpInVlvBol[4], const UInt16
  rtu_VlvAct_1_prm_agCkClsExVlvBo[4], const UInt16 *rtu_AFA_1_rOpClsThrBolPrev,
  const UInt16 *rtu_AFA_1_pAirExtEstimPrev, const UInt16
  *rtu_AFA_1_rOpClsEGRVlvBolPrev, const UInt16 *rtu_AFA_1_agCkOpInVlvBolPrev,
  const UInt16 *rtu_AFA_1_agCkClsExVlvBolPrev, const Boolean
  *rtu_AFA_bFitPresAirExtPrev, const Boolean *rtu_AFA_bFitZeroPosnThrPrev,
  const Boolean *rtu_AFA_bClsEGRRefPrev, const Boolean
  *rtu_AFA_bFitOpInVlvBolPrev, const Boolean *rtu_AFA_bFitClsExVlvBolPrev,
  Boolean *rty_AFA_bClsEGRR1, Boolean *rty_AFA_bFitPresAirE1, Boolean
  *rty_AFA_bFitZeroPosnT1, Boolean *rty_AFA_bFitOpInVlvB1, Boolean
  *rty_AFA_bFitClsExVlvB1, UInt16 *rty_AFA_rOpClsThrB1, UInt16
  *rty_AFA_pAirExtEstimH1, UInt16 *rty_AFA_rOpClsEGRVlvBolH1, UInt16
  *rty_AFA_agCkOpInVlvBolH1, UInt16 *rty_AFA_agCkClsExVlvBolH1);

/* Model reference registration function */
extern void mr_AFA_F01_scruter_e_initialize(void);

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
 * '<Root>' : AFA_F01_scruter_environ_adaptation
 * '<S1>'   : AFA_F01_scruter_environ_adaptation/F01_pAirExtDelta
 * '<S2>'   : AFA_F01_scruter_environ_adaptation/F01_pAirExtDelta1
 * '<S3>'   : AFA_F01_scruter_environ_adaptation/F02_rOpClsThrRawDelta
 * '<S4>'   : AFA_F01_scruter_environ_adaptation/F02_rOpClsThrRawDelta1
 * '<S5>'   : AFA_F01_scruter_environ_adaptation/F03_rOpClsEGRVlvDelta
 * '<S6>'   : AFA_F01_scruter_environ_adaptation/F03_rOpClsEGRVlvDelta1
 * '<S7>'   : AFA_F01_scruter_environ_adaptation/F04_agCkOpInVlvBolDelta
 * '<S8>'   : AFA_F01_scruter_environ_adaptation/F04_agCkOpInVlvBolDelta1
 * '<S9>'   : AFA_F01_scruter_environ_adaptation/F05_agCkClsExVlvBolDelta
 * '<S10>'  : AFA_F01_scruter_environ_adaptation/F05_agCkClsExVlvBolDelta1
 */

/*-
 * Requirements for '<Root>': AFA_F01_scruter_environ_adaptation
 */
#endif                                 /* RTW_HEADER_AFA_F01_scruter_environ_adaptation_h_ */

/*-------------------------------- end of file -------------------------------*/
