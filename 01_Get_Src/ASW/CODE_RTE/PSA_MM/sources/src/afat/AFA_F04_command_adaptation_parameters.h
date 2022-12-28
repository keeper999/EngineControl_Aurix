/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F04_command_adaptation_parameters                   */
/*                                                                            */
/* !File            : AFA_F04_command_adaptation_parameters.h                 */
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
/*   Model name       : AFA_F04_command_adaptation_parameters.mdl             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F04_command_adaptation_parameters_h_
#define RTW_HEADER_AFA_F04_command_adaptation_parameters_h_
#ifndef AFA_F04_command_adaptation_parameters_COMMON_INCLUDES_
# define AFA_F04_command_adaptation_parameters_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F04_command_adaptation_parameters_import.h"
#include "rtw_shared_utils.h"
#endif                                 /* AFA_F04_command_adaptation_parameters_COMMON_INCLUDES_ */

#include "AFA_F04_command_adaptation_parameters_types.h"

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
extern Boolean AFA_bAcvAdpVlvExOfs;  /* '<S3>/Logical Operator36' */
extern Boolean AFA_bAcvAdpVlvInOfs;  /* '<S2>/Logical Operator33' */
extern Boolean AFA_bAcvAdpDlyLsclCnd;/* '<S1>/Logical Operator25' */
extern Boolean AFA_bAcvAdpThrCnd;    /* '<S1>/Logical Operator26' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern Boolean AFA_prm_bMaskSenMat1_MP[2];/* '<S4>/Data Store Memory' */
extern Boolean AFA_prm_bMaskSenMat2_MP[2];/* '<S4>/Data Store Memory1' */
extern Boolean AFA_prm_bMaskSenMat3_MP[2];/* '<S4>/Data Store Memory2' */
extern Boolean AFA_prm_bMaskSenMat4_MP[2];/* '<S4>/Data Store Memory3' */
extern Boolean AFA_prm_bMaskSenMat5_MP[2];/* '<S4>/Data Store Memory4' */
extern Boolean AFA_prm_bMaskSenMat6_MP[2];/* '<S4>/Data Store Memory5' */
extern Boolean AFA_prm_bMaskSenMat7_MP[2];/* '<S4>/Data Store Memory6' */
extern Boolean AFA_prm_bMaskSenMat8_MP[2];/* '<S4>/Data Store Memory7' */

#define AFAT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F04_command_adaptation_p(const UInt16 *rtu_AFA_noAdpEfc,
  const UInt16 *rtu_ThrLrn_rOpSI, const UInt8 *rtu_InjSys_noTDCDlyLsclFilMod,
  const UInt16 *rtu_Ext_nEng, const UInt16 *rtu_EngM_rTotLdExCor, Boolean
  rty_AFA_prm_bMaskSenMat_PIM[16]);

/* Model reference registration function */
extern void mr_AFA_F04_command_a_initialize(void);

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
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S5>/TABLE' : Unused code path elimination
 * Block '<S5>/TABLE1' : Unused code path elimination
 * Block '<S5>/TABLE2' : Unused code path elimination
 * Block '<S2>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S2>/Ext_nEng_A' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S6>/TABLE' : Unused code path elimination
 * Block '<S6>/TABLE1' : Unused code path elimination
 * Block '<S6>/TABLE2' : Unused code path elimination
 * Block '<S3>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S3>/Ext_nEng_A' : Unused code path elimination
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : AFA_F04_command_adaptation_parameters
 * '<S1>'   : AFA_F04_command_adaptation_parameters/F01_Mask_Activation_Conditions
 * '<S2>'   : AFA_F04_command_adaptation_parameters/F02_Adpatation_Intake_Valve_Activation_Conditions
 * '<S3>'   : AFA_F04_command_adaptation_parameters/F03_Adpatation_Exhaust_Valve_Activation_Conditions
 * '<S4>'   : AFA_F04_command_adaptation_parameters/F04_Calc_Mask_Sensibility
 * '<S5>'   : AFA_F04_command_adaptation_parameters/F02_Adpatation_Intake_Valve_Activation_Conditions/Carto_2D
 * '<S6>'   : AFA_F04_command_adaptation_parameters/F03_Adpatation_Exhaust_Valve_Activation_Conditions/Carto_2D
 */

/*-
 * Requirements for '<Root>': AFA_F04_command_adaptation_parameters
 */
#endif                                 /* RTW_HEADER_AFA_F04_command_adaptation_parameters_h_ */

/*-------------------------------- end of file -------------------------------*/
