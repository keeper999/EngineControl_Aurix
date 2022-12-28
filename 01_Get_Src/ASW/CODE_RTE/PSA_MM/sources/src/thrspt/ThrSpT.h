/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : ThrSpT                                                  */
/* !Description     : ThrSpT Software Component                               */
/*                                                                            */
/* !Module          : ThrSpT                                                  */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : ThrSpT.h                                                */
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
/*   Model name       : ThrSpT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /ThrSpT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M09-ThrSpT/5-SOF$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   plchinaz                               $$Date::   03 May 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ThrSpT_h_
#define RTW_HEADER_ThrSpT_h_
#ifndef ThrSpT_COMMON_INCLUDES_
# define ThrSpT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_ThrSpT.h"
#include "ThrSpT_import.h"
#include "ThrSpT_nvm.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_LdexpF.h"
#include "rt_MAXf.h"
#endif                                 /* ThrSpT_COMMON_INCLUDES_ */

#include "ThrSpT_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Block signals (auto storage) */
typedef struct {
  SInt32 EepromReadAccess;            /* '<S5>/EepromReadAccess' */
  SInt32 TmpSignalConversionAtThrSys_arS;
  SInt32 Merge2;                      /* '<S7>/Merge2' */
} BlockIO_ThrSpT;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  SInt32 UnitDelay_DSTATE;            /* '<S32>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_a;         /* '<S26>/Unit Delay' */
  Boolean UnitDelay_DSTATE_o;        /* '<S27>/Unit Delay' */
} D_Work_ThrSpT;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define ThrSpT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ThrSpT_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_ThrSpT ThrSpT_B;

/* Block states (auto storage) */
extern D_Work_ThrSpT ThrSpT_DWork;

#define ThrSpT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ThrSpT_MemMap.h"
#define ThrSpT_START_SEC_CODE
#include "ThrSpT_MemMap.h"

extern void RE_ThrSp_Init(void);
/* Model entry point functions */
extern void RE_ThrSpT_001_MSE(void);
extern void RE_ThrSpT_002_TEV(void);
extern void RE_ThrSpT_003_TEV(void);

#define ThrSpT_STOP_SEC_CODE
#include "ThrSpT_MemMap.h"
#define ThrSpT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ThrSpT_MemMap.h"

/* Model init function */


#define ThrSpT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ThrSpT_MemMap.h"

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
 * Block '<S10>/Air_arEffThr_A' : Unused code path elimination
 * Block '<S14>/BKPT1' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S14>/TABLE' : Unused code path elimination
 * Block '<S15>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S16>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S17>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S12>/Air_arEffThr_A' : Unused code path elimination
 * Block '<S18>/BKPT1' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S18>/TABLE' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Relational Operator' : Unused code path elimination
 * Block '<S31>/Relational Operator1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/DTConv_UFix_To_Single_1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/copy' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S23>/Switch' : Eliminated due to constant selection input
 * Block '<S23>/Constant' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ThrSpT_AUTOSAR/ThrSpT')    - opens subsystem ThrSpT_AUTOSAR/ThrSpT
 * hilite_system('ThrSpT_AUTOSAR/ThrSpT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ThrSpT_AUTOSAR
 * '<S1>'   : ThrSpT_AUTOSAR/ThrSpT
 * '<S5>'   : ThrSpT_AUTOSAR/ThrSpT/F00_ThrAdpr_initialization
 * '<S6>'   : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap
 * '<S7>'   : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt
 * '<S8>'   : ThrSpT_AUTOSAR/ThrSpT/F00_ThrAdpr_initialization/AutosarTestPoint
 * '<S9>'   : ThrSpT_AUTOSAR/ThrSpT/F00_ThrAdpr_initialization/convertout1
 * '<S10>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/F01_01_Calc_Consigne_position_nominale
 * '<S11>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/F01_02_Calc_eff_area_offset
 * '<S12>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/F01_03_Calc_Consigne_position_papillon_corrigee
 * '<S13>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/convertout
 * '<S14>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/F01_01_Calc_Consigne_position_nominale/Carto_1D
 * '<S15>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/F01_02_Calc_eff_area_offset/multiplication1
 * '<S16>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/F01_02_Calc_eff_area_offset/multiplication2
 * '<S17>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/F01_02_Calc_eff_area_offset/multiplication3
 * '<S18>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Calcul_de_la_consig_pos_pap/F01_03_Calc_Consigne_position_papillon_corrigee/Carto_1D
 * '<S19>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/AutosarTestPoint
 * '<S20>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_01_Cond_adapt
 * '<S21>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon
 * '<S22>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon_else
 * '<S23>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/Rte_Call_R_FRM_bInhSpdAdpThr_GetFunctionPermission
 * '<S24>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_01_Init_adapt
 * '<S25>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt
 * '<S26>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/SubSystem
 * '<S27>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/SubSystem1
 * '<S28>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt/F01_02_02_01_Calcul_du_signe
 * '<S29>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt/F01_02_02_02_Adapt_papillon
 * '<S30>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt/F01_02_02_02_Adapt_papillon_else
 * '<S31>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt/F01_02_02_02_Adapt_papillon/Clamp
 * '<S32>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt/F01_02_02_02_Adapt_papillon/SubSystem
 * '<S33>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt/F01_02_02_02_Adapt_papillon/Clamp/Data Type Conversion Inherited
 * '<S34>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt/F01_02_02_02_Adapt_papillon/Clamp/Data Type Conversion Inherited1
 * '<S35>'  : ThrSpT_AUTOSAR/ThrSpT/F01_Thr_adpt/F01_02_Adaptation_papillon/F01_02_02_Run_adapt/F01_02_02_02_Adapt_papillon/Clamp/Saturation Dynamic
 */

/*-
 * Requirements for '<Root>': ThrSpT
 *
 * Inherited requirements for '<S1>/F00_ThrAdpr_initialization':
 *  1. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_026.01 ;
 *  2. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_014.01 ;
 *  3. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_024.01 ;
 *  4. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_029.01 ;
 *
 * Inherited requirements for '<S1>/F01_Calcul_de_la_consig_pos_pap':
 *  1. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_002.01 ;
 *  2. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_001.01 ;
 *  3. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_027.01 ;
 *  4. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_015.01 ;
 *  5. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_016.01 ;
 *  6. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_017.01 ;
 *  7. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_018.01 ;
 *  8. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_019.01 ;
 *  9. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_014.01 ;
 *  10. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_024.01 ;
 *
 * Inherited requirements for '<S1>/F01_Thr_adpt':
 *  1. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_007.01 ;
 *  2. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_006.01 ;
 *  3. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_028.01 ;
 *  4. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_020.01 ;
 *  5. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_021.01 ;
 *  6. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_022.01 ;
 *  7. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_023.01 ;
 *  8. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_024.01 ;
 *  9. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_025.01 ;

 */
#endif                                 /* RTW_HEADER_ThrSpT_h_ */

/*-------------------------------- end of file -------------------------------*/
