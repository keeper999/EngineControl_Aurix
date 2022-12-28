/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F00_init_scruter_environ_adaptation                 */
/*                                                                            */
/* !File            : AFA_F00_init_scruter_environ_adaptation.h               */
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
/*   Model name       : AFA_F00_init_scruter_environ_adaptation.mdl           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   ADELVARE                               $$Date::   29 Jul 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F00_init_scruter_environ_adaptation_h_
#define RTW_HEADER_AFA_F00_init_scruter_environ_adaptation_h_
#ifndef AFA_F00_init_scruter_environ_adaptation_COMMON_INCLUDES_
# define AFA_F00_init_scruter_environ_adaptation_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AFA_F00_init_scruter_environ_adaptation_COMMON_INCLUDES_ */

#include "AFA_F00_init_scruter_environ_adaptation_types.h"

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

/* Model reference registration function */
extern void mr_AFA_F00_init_scru_initialize(void);




extern void mr_AFA_F00_init_scruter_environ(const UInt16
  *rtu_ThrLrn_rOpClsThrBol, const UInt16 *rtu_UsThrM_pAirExtEstim, const
  UInt32 *rtu_EGRVlv_rOpClsEGR1, const UInt16 rtu_VlvAct_prm_agCkOpIn1[4],
  const UInt16 rtu_VlvAct_prm_agCkClsEx1[4], Boolean *rty_AFA_bClsEGRRef,
  Boolean *rty_AFA_bFitPresAirExt, Boolean *rty_AFA_bFitZeroPosnThr,
  Boolean *rty_AFA_bFitOpInVlvBol, Boolean *rty_AFA_bFitClsExVlvBol,
  UInt16 *rty_AFA_rOpClsThrBolHld, UInt16 *rty_AFA_pAirExtEstimHld, UInt16
  *rty_AFA_rOpClsEGRVlvBol1, UInt16 *rty_AFA_agCkOpInVlvBol1, UInt16
  *rty_AFA_agCkClsExVlvBo1);

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
 * '<Root>' : AFA_F00_init_scruter_environ_adaptation
 */

/*-
 * Requirements for '<Root>': AFA_F00_init_scruter_environ_adaptation
 */
#endif                                 /* RTW_HEADER_AFA_F00_init_scruter_environ_adaptation_h_ */

/*-------------------------------- end of file -------------------------------*/
