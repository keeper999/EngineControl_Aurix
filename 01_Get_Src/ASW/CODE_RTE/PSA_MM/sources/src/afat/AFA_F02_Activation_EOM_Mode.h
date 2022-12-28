/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F02_Activation_EOM_Mode                             */
/*                                                                            */
/* !File            : AFA_F02_Activation_EOM_Mode.h                           */
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
/*   Model name       : AFA_F02_Activation_EOM_Mode.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F02_Activation_EOM_Mode_h_
#define RTW_HEADER_AFA_F02_Activation_EOM_Mode_h_
#ifndef AFA_F02_Activation_EOM_Mode_COMMON_INCLUDES_
# define AFA_F02_Activation_EOM_Mode_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F02_Activation_EOM_Mode_import.h"
#include "rtw_shared_utils.h"
#endif                                 /* AFA_F02_Activation_EOM_Mode_COMMON_INCLUDES_ */

#include "AFA_F02_Activation_EOM_Mode_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Block signals for model 'AFA_F02_Activation_EOM_Mode' */
#ifndef AFA_F02_Activation_EOM_Mode_MDLREF_HIDE_CHILD_

typedef struct {
  SInt32 MinMax;                      /* '<S5>/MinMax' */
} rtB_mr_AFA_F02_Activation_EOM_M;

#endif                                 /*AFA_F02_Activation_EOM_Mode_MDLREF_HIDE_CHILD_*/

/* Block states (auto storage) for model 'AFA_F02_Activation_EOM_Mode' */
#ifndef AFA_F02_Activation_EOM_Mode_MDLREF_HIDE_CHILD_

typedef struct {
  Boolean UnitDelay_DSTATE;          /* '<S4>/Unit Delay' */
  Boolean UnitDelay1_DSTATE;         /* '<S6>/Unit Delay1' */
} rtDW_mr_AFA_F02_Activation_EOM_;

#endif                                 /*AFA_F02_Activation_EOM_Mode_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_Activation_EOM_Mode_MDLREF_HIDE_CHILD_

typedef struct {
  rtB_mr_AFA_F02_Activation_EOM_M rtb;
  rtDW_mr_AFA_F02_Activation_EOM_ rtdw;
} rtMdlrefDWork_mr_AFA_F02_Activa;

#endif                                 /*AFA_F02_Activation_EOM_Mode_MDLREF_HIDE_CHILD_*/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern Boolean AFA_bIdcObsSpcInjWiDly;/* '<S5>/Relational Operator3' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern Boolean AFA_bIdcObsSpcInjMod_MP;/* '<S1>/Data Store Memory' */
extern Boolean AFA_bIdcObsSpcInjSel_MP;/* '<S1>/Data Store Memory1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"


#ifndef AFA_F02_Activation_EOM_Mode_MDLREF_HIDE_CHILD_

extern rtMdlrefDWork_mr_AFA_F02_Activa mr_AFA_F02_Activati_MdlrefDWork;

#endif                                 /*AFA_F02_Activation_EOM_Mode_MDLREF_HIDE_CHILD_*/


#define AFAT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F02_Activation_EOM_Mode(const UInt8
  *rtu_AFA_noObsSpcInjModP2, const UInt16 *rtu_AFA_noAdpEfc2, const Boolean *
  rtu_AFAMgt_bIdcInjrMdlC2, const Boolean *rtu_AFAMgt_bIdcTmpObsC2, const
  UInt32 *rtu_AFA_tiAcvSpcInjModP2, UInt8 *rty_AFA_noObsSpcInj2, Boolean
  *rty_AFA_bAcvSpcInj2, UInt32 *rty_AFA_tiAcvSpcInj2);

/* Model reference registration function */
extern void mr_AFA_F02_Activatio_initialize(void);

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */

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
 * Block '<S1>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S1>/Signal Conversion1' : Eliminate redundant signal conversion block
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
 * '<Root>' : AFA_F02_Activation_EOM_Mode
 * '<S1>'   : AFA_F02_Activation_EOM_Mode/F01_Specific_Observation_Conditions
 * '<S2>'   : AFA_F02_Activation_EOM_Mode/F02_Specific_Injection_Conditions
 * '<S3>'   : AFA_F02_Activation_EOM_Mode/F01_Specific_Observation_Conditions/DelayEdge_falling_VEMS
 * '<S4>'   : AFA_F02_Activation_EOM_Mode/F01_Specific_Observation_Conditions/SubSystem
 * '<S5>'   : AFA_F02_Activation_EOM_Mode/F01_Specific_Observation_Conditions/DelayEdge_falling_VEMS/Subsystem
 * '<S6>'   : AFA_F02_Activation_EOM_Mode/F01_Specific_Observation_Conditions/DelayEdge_falling_VEMS/Subsystem/FallingEdge
 */

/*-
 * Requirements for '<Root>': AFA_F02_Activation_EOM_Mode
 */
#endif                                 /* RTW_HEADER_AFA_F02_Activation_EOM_Mode_h_ */

/*-------------------------------- end of file -------------------------------*/
