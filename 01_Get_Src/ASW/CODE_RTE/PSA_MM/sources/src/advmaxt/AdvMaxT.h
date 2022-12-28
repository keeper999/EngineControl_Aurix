/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMaxT                                                 */
/* !Description     : AdvMaxT Software Component                              */
/*                                                                            */
/* !Module          : AdvMaxT                                                 */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : AdvMaxT.h                                               */
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
/*   Model name       : AdvMaxT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMaxT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M04-AdvMaxT/5-S$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   11 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvMaxT_h_
#define RTW_HEADER_AdvMaxT_h_
#ifndef AdvMaxT_COMMON_INCLUDES_
# define AdvMaxT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AdvMaxT.h"
#include "AdvMaxT_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "ACTEMS_LdexpF.h"
#include "rt_MINf.h"
#include "rt_SATURATE.h"
#endif                                 /* AdvMaxT_COMMON_INCLUDES_ */

#include "AdvMaxT_types.h"

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
  Float32 Merge[6];                   /* '<S5>/Merge' */
  Float32 Merge1;                     /* '<S5>/Merge1' */
  Float32 Merge2;                     /* '<S5>/Merge2' */
  Float32 Merge3;                     /* '<S5>/Merge3' */
} BlockIO_AdvMaxT;

/* Invariant block signals (auto storage) */
typedef struct {
  const UInt8 DataTypeConversion_o[6];/* '<S9>/Data Type Conversion' */
} ConstBlockIO_AdvMaxT;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Ext_noCylEng_SC1_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC1'
   */
  UInt8 Ext_noCylEng_SC1_Valu[6];

  /* Computed Parameter: Ext_noCylEng_SC2_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC2'
   */
  UInt8 Ext_noCylEng_SC2_Valu[6];

  /* Computed Parameter: Ext_noCylEng_SC3_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC3'
   */
  UInt8 Ext_noCylEng_SC3_Valu[6];

  /* Computed Parameter: Ext_noCylEng_SC4_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC4'
   */
  UInt8 Ext_noCylEng_SC4_Valu[6];

  /* Computed Parameter: Ext_noCylEng_SC5_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC5'
   */
  UInt8 Ext_noCylEng_SC5_Valu[6];

  /* Computed Parameter: Ext_noCylEng_SC6_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC6'
   */
  UInt8 Ext_noCylEng_SC6_Valu[6];
} ConstParam_AdvMaxT;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define AdvMaxT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMaxT_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_AdvMaxT AdvMaxT_B;





#define AdvMaxT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMaxT_MemMap.h"
#define AdvMaxT_START_SEC_CODE
#include "AdvMaxT_MemMap.h"

extern void Runnable_AdvMax_Init(void);
/* Model entry point functions */
extern void RE_AdvMaxT_002_DRE(void);
extern void RE_AdvMaxT_001_MSE(void);

#define AdvMaxT_STOP_SEC_CODE
#include "AdvMaxT_MemMap.h"

#define AdvMaxT_START_SEC_CONST_UNSPECIFIED
#include "AdvMaxT_MemMap.h"

extern ConstBlockIO_AdvMaxT AdvMaxT_ConstB;/* constant block i/o */
/* Constant parameters (auto storage) */
extern const ConstParam_AdvMaxT AdvMaxT_ConstP;

#define AdvMaxT_STOP_SEC_CONST_UNSPECIFIED
#include "AdvMaxT_MemMap.h"

#define AdvMaxT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMaxT_MemMap.h"

/* Model init function */


#define AdvMaxT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMaxT_MemMap.h"

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
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S22>/TABLE' : Unused code path elimination
 * Block '<S22>/TABLE1' : Unused code path elimination
 * Block '<S22>/TABLE2' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S23>/TABLE' : Unused code path elimination
 * Block '<S23>/TABLE1' : Unused code path elimination
 * Block '<S23>/TABLE2' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S24>/TABLE' : Unused code path elimination
 * Block '<S24>/TABLE1' : Unused code path elimination
 * Block '<S24>/TABLE2' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S25>/TABLE' : Unused code path elimination
 * Block '<S25>/TABLE1' : Unused code path elimination
 * Block '<S25>/TABLE2' : Unused code path elimination
 * Block '<S19>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S19>/Eng_rAirLd_A1' : Unused code path elimination
 * Block '<S19>/Ext_nEng_A' : Unused code path elimination
 * Block '<S19>/Ext_nEng_A1' : Unused code path elimination
 * Block '<S19>/Vlv_agCkExVlvNorm_A' : Unused code path elimination
 * Block '<S19>/Vlv_agCkExVlvNorm_A1' : Unused code path elimination
 * Block '<S19>/Vlv_agCkInVlvNorm_A' : Unused code path elimination
 * Block '<S19>/Vlv_agCkInVlvNorm_A1' : Unused code path elimination
 * Block '<S26>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S27>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S28>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S29>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S34>/TABLE' : Unused code path elimination
 * Block '<S34>/TABLE1' : Unused code path elimination
 * Block '<S34>/TABLE2' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S35>/TABLE' : Unused code path elimination
 * Block '<S35>/TABLE1' : Unused code path elimination
 * Block '<S35>/TABLE2' : Unused code path elimination
 * Block '<S30>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S30>/Eng_rAirLd_A1' : Unused code path elimination
 * Block '<S30>/Ext_nEng_A' : Unused code path elimination
 * Block '<S30>/Ext_nEng_A1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/TABLE' : Unused code path elimination
 * Block '<S36>/TABLE1' : Unused code path elimination
 * Block '<S36>/TABLE2' : Unused code path elimination
 * Block '<S31>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S31>/Ext_nEng_A' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S37>/TABLE' : Unused code path elimination
 * Block '<S37>/TABLE1' : Unused code path elimination
 * Block '<S37>/TABLE2' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S38>/TABLE' : Unused code path elimination
 * Block '<S38>/TABLE1' : Unused code path elimination
 * Block '<S38>/TABLE2' : Unused code path elimination
 * Block '<S32>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S32>/Eng_rAirLd_A1' : Unused code path elimination
 * Block '<S32>/Ext_nEng_A' : Unused code path elimination
 * Block '<S32>/Ext_nEng_A1' : Unused code path elimination
 * Block '<S39>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S40>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S41>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S42>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S47>/TABLE' : Unused code path elimination
 * Block '<S47>/TABLE1' : Unused code path elimination
 * Block '<S47>/TABLE2' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S48>/TABLE' : Unused code path elimination
 * Block '<S48>/TABLE1' : Unused code path elimination
 * Block '<S48>/TABLE2' : Unused code path elimination
 * Block '<S43>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S43>/Eng_rAirLd_A1' : Unused code path elimination
 * Block '<S43>/Ext_nEng_A' : Unused code path elimination
 * Block '<S43>/Ext_nEng_A1' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S49>/TABLE' : Unused code path elimination
 * Block '<S49>/TABLE1' : Unused code path elimination
 * Block '<S49>/TABLE2' : Unused code path elimination
 * Block '<S44>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S44>/Ext_nEng_A' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S50>/TABLE' : Unused code path elimination
 * Block '<S50>/TABLE1' : Unused code path elimination
 * Block '<S50>/TABLE2' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S51>/TABLE' : Unused code path elimination
 * Block '<S51>/TABLE1' : Unused code path elimination
 * Block '<S51>/TABLE2' : Unused code path elimination
 * Block '<S45>/Eng_rAirLd_A' : Unused code path elimination
 * Block '<S45>/Eng_rAirLd_A1' : Unused code path elimination
 * Block '<S45>/Ext_nEng_A' : Unused code path elimination
 * Block '<S45>/Ext_nEng_A1' : Unused code path elimination
 * Block '<S52>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S53>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S54>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S55>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Relational Operator' : Unused code path elimination
 * Block '<S61>/Relational Operator1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Propagation' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Relational Operator' : Unused code path elimination
 * Block '<S65>/Relational Operator1' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Propagation' : Unused code path elimination
 * Block '<S69>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S70>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S71>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * hilite_system('AdvMaxT_AUTOSAR/AdvMaxT')    - opens subsystem AdvMaxT_AUTOSAR/AdvMaxT
 * hilite_system('AdvMaxT_AUTOSAR/AdvMaxT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AdvMaxT_AUTOSAR
 * '<S1>'   : AdvMaxT_AUTOSAR/AdvMaxT
 * '<S4>'   : AdvMaxT_AUTOSAR/AdvMaxT/F00_AdvMax_Init
 * '<S5>'   : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax
 * '<S6>'   : AdvMaxT_AUTOSAR/AdvMaxT/F00_AdvMax_Init/convertout1
 * '<S7>'   : AdvMaxT_AUTOSAR/AdvMaxT/F00_AdvMax_Init/convertout2
 * '<S8>'   : AdvMaxT_AUTOSAR/AdvMaxT/F00_AdvMax_Init/convertout3
 * '<S9>'   : AdvMaxT_AUTOSAR/AdvMaxT/F00_AdvMax_Init/convertout4
 * '<S10>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F01_Activation
 * '<S11>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax
 * '<S12>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/NOT
 * '<S13>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/convertout1
 * '<S14>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/convertout2
 * '<S15>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/convertout3
 * '<S16>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/convertout4
 * '<S17>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn
 * '<S18>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax
 * '<S19>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation
 * '<S20>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat
 * '<S21>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn
 * '<S22>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation/Carto_2D1
 * '<S23>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation/Carto_2D2
 * '<S24>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation/Carto_2D3
 * '<S25>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation/Carto_2D4
 * '<S26>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation/division
 * '<S27>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation/division1
 * '<S28>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation/division2
 * '<S29>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F01_Calc_facteurs_ponderation/division3
 * '<S30>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F01_AdvMaxInVlvStat
 * '<S31>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F02_AdvMaxVlvStat
 * '<S32>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F03_AdvMaxExVlvStat
 * '<S33>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F04_AdvKnkBasStat
 * '<S34>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F01_AdvMaxInVlvStat/Carto_2D4
 * '<S35>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F01_AdvMaxInVlvStat/Carto_2D5
 * '<S36>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F02_AdvMaxVlvStat/Carto_2D6
 * '<S37>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F03_AdvMaxExVlvStat/Carto_2D7
 * '<S38>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F03_AdvMaxExVlvStat/Carto_2D8
 * '<S39>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F04_AdvKnkBasStat/multiplication_451
 * '<S40>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F04_AdvKnkBasStat/multiplication_461
 * '<S41>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F04_AdvKnkBasStat/multiplication_471
 * '<S42>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F02_Degradation_knk_stat/F04_AdvKnkBasStat/multiplication_481
 * '<S43>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F01_AdvMaxInVlvDyn
 * '<S44>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F02_AdvMaxVlvDyn
 * '<S45>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F03_AdvMaxExVlvDyn
 * '<S46>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F04_AdvKnkBasDyn
 * '<S47>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F01_AdvMaxInVlvDyn/Carto_2D10
 * '<S48>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F01_AdvMaxInVlvDyn/Carto_2D9
 * '<S49>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F02_AdvMaxVlvDyn/Carto_2D11
 * '<S50>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F03_AdvMaxExVlvDyn/Carto_2D12
 * '<S51>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F03_AdvMaxExVlvDyn/Carto_2D13
 * '<S52>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F04_AdvKnkBasDyn/multiplication_4101
 * '<S53>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F04_AdvKnkBasDyn/multiplication_4111
 * '<S54>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F04_AdvKnkBasDyn/multiplication_4121
 * '<S55>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F01_AdvKnkBasStatDyn/F03_Degradation_knk_dyn/F04_AdvKnkBasDyn/multiplication_491
 * '<S56>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F01_AdvMaxWoutPrevAdpMv
 * '<S57>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs
 * '<S58>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F03_Coordination_preventif_adaptatif
 * '<S59>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS
 * '<S60>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS1
 * '<S61>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS/Clamp
 * '<S62>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S63>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S64>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S65>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS1/Clamp
 * '<S66>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited
 * '<S67>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited1
 * '<S68>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F02_Correctifs/BaryCentre_VEMS1/Clamp/Saturation Dynamic
 * '<S69>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F03_Coordination_preventif_adaptatif/division_4141
 * '<S70>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F03_Coordination_preventif_adaptatif/multiplication_1
 * '<S71>'  : AdvMaxT_AUTOSAR/AdvMaxT/F01_AdvMax/F02_CalcAdvMax/F02_CoordAdvMax/F03_Coordination_preventif_adaptatif/multiplication_4131
 */

/*-
 * Requirements for '<Root>': AdvMaxT
 *
 * Inherited requirements for '<S1>/F01_AdvMax':
 *  1. SubSystem "F01_AdvMax" !Trace_To : VEMS_R_10_06439_001.01 ;

 */
#endif                                 /* RTW_HEADER_AdvMaxT_h_ */

/*-------------------------------- end of file -------------------------------*/
