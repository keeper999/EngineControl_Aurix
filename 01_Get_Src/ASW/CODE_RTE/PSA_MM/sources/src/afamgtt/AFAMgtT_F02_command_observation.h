/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT_F02_command_observation                         */
/*                                                                            */
/* !File            : AFAMgtT_F02_command_observation.h                       */
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
/*   Model name       : AFAMgtT_F02_command_observation.mdl                   */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   22 Aug 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFAMgtT_F02_command_observation_h_
#define RTW_HEADER_AFAMgtT_F02_command_observation_h_
#ifndef AFAMgtT_F02_command_observation_COMMON_INCLUDES_
# define AFAMgtT_F02_command_observation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFAMgtT_F02_command_observation_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "ACTEMS_LdexpF.h"
#include "rt_MAX.h"
#include "rt_MIN.h"
#include "rt_SATURATE.h"
#endif                                 /* AFAMgtT_F02_command_observation_COMMON_INCLUDES_ */

#include "AFAMgtT_F02_command_observation_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Block signals for model 'AFAMgtT_F02_command_observation' */
#ifndef AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_

typedef struct {
  Boolean AFAMgt_bAuthAdpReq;        /* '<S2>/F01_command_observation_chart' */
  Boolean AFAMgt_bAdpObsReq;         /* '<S2>/F01_command_observation_chart' */
} rtB_mr_AFAMgtT_F02_command_obse;

#endif                                 /*AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_*/

/* Block states (auto storage) for model 'AFAMgtT_F02_command_observation' */
#ifndef AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_

typedef struct {
  SInt32 AFAMgt_tiCntCanPurgReqInh;   /* '<S2>/F01_command_observation_chart' */
  UInt8 is_active_c8_AFAMgtT_F02_comman;/* '<S2>/F01_command_observation_chart' */
  UInt8 is_c8_AFAMgtT_F02_command_obser;/* '<S2>/F01_command_observation_chart' */
  UInt8 is_Observation;              /* '<S2>/F01_command_observation_chart' */
  UInt8 AFAMgt_ctAdpObsDft;          /* '<S2>/F01_command_observation_chart' */
} rtDW_mr_AFAMgtT_F02_command_obs;

#endif                                 /*AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_*/

#ifndef AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_

typedef struct {
  rtB_mr_AFAMgtT_F02_command_obse rtb;
  rtDW_mr_AFAMgtT_F02_command_obs rtdw;
} rtMdlrefDWork_mr_AFAMgtT_F02_co;

#endif                                 /*AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_*/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */


#define AFAMgtT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAMgtT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern Boolean AFAMgt_bIdcTmpObsCndOk;/* '<S1>/Logical Operator2' */
extern Boolean AFAMgt_bIdcTiInjMinCnd;/* '<S20>/Logical Operator2' */
extern Boolean AFAMgt_bIdcFacCorGainLnrCnd;/* '<S19>/Logical Operator2' */
extern Boolean AFAMgt_bIdcDeltaLdInjPhaCnd;/* '<S10>/Relational Operator8' */
extern Boolean AFAMgt_bIdcMassAirScvCnd;/* '<S9>/Relational Operator1' */
extern Boolean AFAMgt_bIdcStabCnd;   /* '<S8>/Logical Operator1' */
extern Boolean AFAMgt_bIdcPresCnd;   /* '<S7>/Logical Operator1' */
extern Boolean AFAMgt_bIdcThermoCnd; /* '<S6>/Logical Operator1' */
extern Boolean AFAMgt_bIdcTiDlyObsCnd;/* '<S5>/Relational Operator' */
extern Boolean AFAMgt_bIdcFARSpCnd;  /* '<S4>/Logical Operator1' */
extern Boolean AFAMgt_bIdcEngCnd;    /* '<S3>/Logical Operator2' */

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_VAR_UNSPECIFIED
#include "AFAMgtT_MemMap.h"


#ifndef AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_

extern rtMdlrefDWork_mr_AFAMgtT_F02_co mr_AFAMgtT_F02_comm_MdlrefDWork;

#endif                                 /*AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_*/


#define AFAMgtT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAMgtT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

extern void mr_AFAMgtT_F02_command_obs_Init(Boolean *rty_AFAMgt_bDgoObsAdp,
  Boolean *rty_AFAMgt_bMonRunObsAdp);
extern void mr_AFAMgtT_F02_command_observat(const Boolean
  *rtu_AFAMgt_bStabAirLdCor, const Boolean *rtu_AFAMgt_bIdcStabRatOpEGR, const
  Boolean *rtu_AFAMgt_bIdcNotDynCorPres, const Boolean
  *rtu_AFAMgt_bStabEgdGear, const Boolean *rtu_AFAMgt_bIdcStabAirMod, const
  Boolean *rtu_AFAMgt_bIdcStabFuMod, const Boolean *rtu_GSM_bAcvAFAAdp,
  const UInt32 *rtu_AFAMgt_tiDlyLstObsThd, const UInt16 *rtu_Ext_nEng, const
  UInt32 *rtu_AFA_tiDlyLstObs, const UInt16 *rtu_EngM_rTotLdExCor, const
  UInt16 *rtu_Ext_pDsThrMesSI, const Boolean *rtu_FRM_bInhAFAObsAdp, const
  SInt16 *rtu_Ext_tDsThrMes, const SInt16 *rtu_Ext_tCoMes, const Boolean
  *rtu_AFA_bAuthClsCan1, const UInt16 *rtu_FARSp_rMixtCylSp, const UInt16
  *rtu_AFA_nEngLstObs, const UInt16 *rtu_AFA_rTotLdCorLstObs, const UInt16
  *rtu_UsThrM_pAirExt, const Boolean *rtu_AFAMgt_bStabEOM, const SInt16
  *rtu_EngM_rDeltaLdInjPha, const UInt16 rtu_InjrM_prm_facCorGainLnr[4], const
  UInt16 rtu_InjrM_prm_pDifInjr[4], const UInt32 rtu_InjrSys_prm_tiInj[4],
  const Boolean *rtu_AFAMgt_bStabFacStrtCor, const Boolean
  *rtu_Blby_bIdcWoutBlbyCnd, const UInt16 *rtu_EngM_rltMassAirScvCor,
  Boolean *rty_AFAMgt_bIdcTmpObs1, Boolean *rty_AFAMgt_bIdcInjrMdl1,
  Boolean *rty_AFAMgt_bDgoObsAdp, Boolean *rty_AFAMgt_bMonRunObsAdp,
  Boolean *rty_AFAMgt_bAuthAdp1, Boolean *rty_AFAMgt_bAdpObs1);

/* Model reference registration function */
extern void mr_AFAMgtT_F02_comma_initialize(void);

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

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
 * Block '<S12>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S13>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S16>/Force any float to Double everything else to uint8' : Unused code path elimination
 * Block '<S16>/Force any float to Single everything else to uint8' : Unused code path elimination
 * Block '<S19>/AFAMgt_pDifInjr2' : Unused code path elimination
 * Block '<S21>/BKPT1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S21>/TABLE' : Unused code path elimination
 * Block '<S22>/Data Type Propagation' : Unused code path elimination
 * Block '<S22>/Data Type Propagation1' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/Data Type Conversion' : Unused code path elimination
 * Block '<S26>/Data Type Conversion1' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/Data Type Propagation1' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Conversion' : Unused code path elimination
 * Block '<S28>/Data Type Conversion1' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/Data Type Propagation1' : Unused code path elimination
 * Block '<S30>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Data Type Conversion' : Unused code path elimination
 * Block '<S30>/Data Type Conversion1' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/Data Type Propagation1' : Unused code path elimination
 * Block '<S32>/Data Type Propagation' : Unused code path elimination
 * Block '<S32>/Data Type Conversion' : Unused code path elimination
 * Block '<S32>/Data Type Conversion1' : Unused code path elimination
 * Block '<S20>/AFAMgt_pDifInjr2' : Unused code path elimination
 * Block '<S34>/BKPT1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S34>/TABLE' : Unused code path elimination
 * Block '<S15>/FixPt Gateway Out' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : AFAMgtT_F02_command_observation
 * '<S1>'   : AFAMgtT_F02_command_observation/F01_calc_Tempo
 * '<S2>'   : AFAMgtT_F02_command_observation/F02_Manager
 * '<S3>'   : AFAMgtT_F02_command_observation/F01_calc_Tempo/F01_Engine_state_Conditions
 * '<S4>'   : AFAMgtT_F02_command_observation/F01_calc_Tempo/F02_Richness_Condition
 * '<S5>'   : AFAMgtT_F02_command_observation/F01_calc_Tempo/F03_Delay_Observation_Conditions
 * '<S6>'   : AFAMgtT_F02_command_observation/F01_calc_Tempo/F04_Temperature_Conditions
 * '<S7>'   : AFAMgtT_F02_command_observation/F01_calc_Tempo/F05_Pressure_Conditions
 * '<S8>'   : AFAMgtT_F02_command_observation/F01_calc_Tempo/F06_Stabilty_Conditions
 * '<S9>'   : AFAMgtT_F02_command_observation/F01_calc_Tempo/F07_Air_Scavaging_Condition
 * '<S10>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F08_Engine_Load_Model_Correction_Conditions
 * '<S11>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition
 * '<S12>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F05_Pressure_Conditions/division
 * '<S13>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F05_Pressure_Conditions/multiplication_new
 * '<S14>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F08_Engine_Load_Model_Correction_Conditions/Secured fixpoint division1
 * '<S15>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F08_Engine_Load_Model_Correction_Conditions/Secured fixpoint division1/Data Type Scaling Strip
 * '<S16>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F08_Engine_Load_Model_Correction_Conditions/Secured fixpoint division1/Data Type Police No Floating Point1
 * '<S17>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F08_Engine_Load_Model_Correction_Conditions/Secured fixpoint division1/If Action Subsystem2
 * '<S18>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F08_Engine_Load_Model_Correction_Conditions/Secured fixpoint division1/If Action Subsystem3
 * '<S19>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition
 * '<S20>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F02_Injection_Timing_Conditions
 * '<S21>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Carto_1D1
 * '<S22>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem
 * '<S23>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem1
 * '<S24>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem2
 * '<S25>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem3
 * '<S26>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem/Data Type Police Only single
 * '<S27>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem/If Action Subsystem3
 * '<S28>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem1/Data Type Police Only single
 * '<S29>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem1/If Action Subsystem3
 * '<S30>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem2/Data Type Police Only single
 * '<S31>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem2/If Action Subsystem3
 * '<S32>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem3/Data Type Police Only single
 * '<S33>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F01_Gain_Linear_Correction_Condition/Subsystem3/If Action Subsystem3
 * '<S34>'  : AFAMgtT_F02_command_observation/F01_calc_Tempo/F09_Injector_Model_Correction_Condition/F02_Injection_Timing_Conditions/Carto_1D1
 * '<S35>'  : AFAMgtT_F02_command_observation/F02_Manager/F01_command_observation_chart
 */

/*-
 * Requirements for '<Root>': AFAMgtT_F02_command_observation
 */
#endif                                 /* RTW_HEADER_AFAMgtT_F02_command_observation_h_ */

/*-------------------------------- end of file -------------------------------*/
