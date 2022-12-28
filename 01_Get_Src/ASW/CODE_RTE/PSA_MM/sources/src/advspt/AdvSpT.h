/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvSpT                                                  */
/* !Description     : AdvSpT Software Component                               */
/*                                                                            */
/* !Module          : AdvSpT                                                  */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : AdvSpT.h                                                */
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
/*   Model name       : AdvSpT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /AdvSpT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M06-AdvSpT/5-SO$*/
/* $Revision::   1.16                                                        $*/
/* $Author::   adelvare                               $$Date::   02 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvSpT_h_
#define RTW_HEADER_AdvSpT_h_
#ifndef AdvSpT_COMMON_INCLUDES_
# define AdvSpT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AdvSpT.h"
#include "AdvSpT_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "rt_MAXf.h"
#include "rt_MIN.h"
#include "rt_MINf.h"
#endif                                 /* AdvSpT_COMMON_INCLUDES_ */

#include "AdvSpT_types.h"

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
  SInt16 TmpSignalConversionAtTqSys_tqId;
  UInt16 TmpSignalConversionAtIgSys_rTar;
  UInt16 TmpSignalConversionAtIgSys_rT_g;
  UInt16 Merge2;                     /* '<S11>/Merge2' */
  UInt16 Merge1;                     /* '<S11>/Merge1' */
  UInt8 Merge1_c;                    /* '<S13>/Merge1' */
  UInt8 Merge1_g;                    /* '<S12>/Merge1' */
  UInt8 Merge2_f;                    /* '<S12>/Merge2' */
  UInt8 Merge3;                      /* '<S12>/Merge3' */
  UInt8 Merge4;                      /* '<S12>/Merge4' */
} BlockIO_AdvSpT;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 UnitDelay_DSTATE;            /* '<S63>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_e;          /* '<S60>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_g;          /* '<S61>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_c;          /* '<S62>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_k;          /* '<S64>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_m;          /* '<S59>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_n;          /* '<S58>/Unit Delay' */
} D_Work_AdvSpT;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState F1_01_01_02_Detecter_coupure_Tr;/* '<S53>/F1_01_01_02_Detecter_coupure' */
} PrevZCSigStates_AdvSpT;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define AdvSpT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvSpT_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_AdvSpT AdvSpT_B;

/* Block states (auto storage) */
extern D_Work_AdvSpT AdvSpT_DWork;

#define AdvSpT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvSpT_MemMap.h"
#define AdvSpT_START_SEC_CODE
#include "AdvSpT_MemMap.h"

extern void Runnable_AdvSp_Init(void);
/* Model entry point functions */
extern void RE_AdvSpT_004_DRE(void);
extern void RE_AdvSpT_006_DRE(void);
extern void RE_AdvSpT_002_DRE(void);
extern void RE_AdvSpT_005_MSE(void);
extern void RE_AdvSpT_001_MSE(void);
extern void RE_AdvSpT_003_MSE(void);

#define AdvSpT_STOP_SEC_CODE
#include "AdvSpT_MemMap.h"
#define AdvSpT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvSpT_MemMap.h"

/* Model init function */


#define AdvSpT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvSpT_MemMap.h"

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
 * Block '<S26>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S36>/BKPT1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/TABLE' : Unused code path elimination
 * Block '<S34>/IgSys_rTar_OfsAgIg_A' : Unused code path elimination
 * Block '<S41>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S42>/Force any float to Double everything else to uint8' : Unused code path elimination
 * Block '<S42>/Force any float to Single everything else to uint8' : Unused code path elimination
 * Block '<S45>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S46>/Force any float to Double everything else to uint8' : Unused code path elimination
 * Block '<S46>/Force any float to Single everything else to uint8' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Relational Operator' : Unused code path elimination
 * Block '<S65>/Relational Operator1' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Propagation' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Relational Operator' : Unused code path elimination
 * Block '<S66>/Relational Operator1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Propagation' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Relational Operator' : Unused code path elimination
 * Block '<S67>/Relational Operator1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Propagation' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Relational Operator' : Unused code path elimination
 * Block '<S68>/Relational Operator1' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/copy' : Eliminate redundant signal conversion block
 * Block '<S19>/copy' : Eliminate redundant signal conversion block
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Switch' : Eliminated due to constant selection input
 * Block '<S36>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S41>/FixPt Gateway Out' : Eliminate redundant data type conversion
 * Block '<S45>/FixPt Gateway Out' : Eliminate redundant data type conversion
 * Block '<S39>/Switch' : Eliminated due to constant selection input
 * Block '<S40>/Switch' : Eliminated due to constant selection input
 * Block '<S29>/Switch' : Eliminated due to constant selection input
 * Block '<S30>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S33>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S74>/Conversion' : Eliminate redundant data type conversion
 * Block '<S75>/Conversion' : Eliminate redundant data type conversion
 * Block '<S77>/Conversion' : Eliminate redundant data type conversion
 * Block '<S78>/Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Conversion' : Eliminate redundant data type conversion
 * Block '<S81>/Conversion' : Eliminate redundant data type conversion
 * Block '<S83>/Conversion' : Eliminate redundant data type conversion
 * Block '<S84>/Conversion' : Eliminate redundant data type conversion
 * Block '<S51>/Switch' : Eliminated due to constant selection input
 * Block '<S52>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Add3' : Unused code path elimination
 * Block '<S25>/Add4' : Unused code path elimination
 * Block '<S25>/Constant' : Unused code path elimination
 * Block '<S25>/Relational Operator' : Unused code path elimination
 * Block '<S25>/Switch1' : Unused code path elimination
 * Block '<S25>/offset2' : Unused code path elimination
 * Block '<S25>/offset3' : Unused code path elimination
 * Block '<S25>/offset4' : Unused code path elimination
 * Block '<S39>/Add2' : Unused code path elimination
 * Block '<S39>/Constant' : Unused code path elimination
 * Block '<S39>/offset1' : Unused code path elimination
 * Block '<S40>/Add3' : Unused code path elimination
 * Block '<S40>/Add4' : Unused code path elimination
 * Block '<S40>/Constant' : Unused code path elimination
 * Block '<S40>/Relational Operator' : Unused code path elimination
 * Block '<S40>/Switch1' : Unused code path elimination
 * Block '<S40>/offset2' : Unused code path elimination
 * Block '<S40>/offset3' : Unused code path elimination
 * Block '<S40>/offset4' : Unused code path elimination
 * Block '<S29>/Constant' : Unused code path elimination
 * Block '<S51>/Constant' : Unused code path elimination
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
 * hilite_system('AdvSpT_AUTOSAR/AdvSpT')    - opens subsystem AdvSpT_AUTOSAR/AdvSpT
 * hilite_system('AdvSpT_AUTOSAR/AdvSpT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AdvSpT_AUTOSAR
 * '<S1>'   : AdvSpT_AUTOSAR/AdvSpT
 * '<S8>'   : AdvSpT_AUTOSAR/AdvSpT/F00_AdvSp_Init
 * '<S9>'   : AdvSpT_AUTOSAR/AdvSpT/F00_IgAdvEffSp_Init
 * '<S10>'  : AdvSpT_AUTOSAR/AdvSpT/F00_IgAdvSelCutOff_Init
 * '<S11>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2013_v1_1
 * '<S12>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0
 * '<S13>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1
 * '<S14>'  : AdvSpT_AUTOSAR/AdvSpT/F00_AdvSp_Init/convertout1
 * '<S15>'  : AdvSpT_AUTOSAR/AdvSpT/F00_AdvSp_Init/convertout2
 * '<S16>'  : AdvSpT_AUTOSAR/AdvSpT/F00_AdvSp_Init/convertout3
 * '<S17>'  : AdvSpT_AUTOSAR/AdvSpT/F00_AdvSp_Init/convertout4
 * '<S18>'  : AdvSpT_AUTOSAR/AdvSpT/F00_IgAdvEffSp_Init/autosar_testpoint
 * '<S19>'  : AdvSpT_AUTOSAR/AdvSpT/F00_IgAdvEffSp_Init/autosar_testpoint1
 * '<S20>'  : AdvSpT_AUTOSAR/AdvSpT/F00_IgAdvSelCutOff_Init/convertout
 * '<S21>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2013_v1_1/F01_Cal_rendement_consigne_d_avance
 * '<S22>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2013_v1_1/F01_Cal_rendement_consigne_d_avance_Default
 * '<S23>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2013_v1_1/autosar_testpoint
 * '<S24>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2013_v1_1/autosar_testpoint1
 * '<S25>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2013_v1_1/F01_Cal_rendement_consigne_d_avance/SingleToFixdt
 * '<S26>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2013_v1_1/F01_Cal_rendement_consigne_d_avance/division_1
 * '<S27>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance
 * '<S28>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance_Default
 * '<S29>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/Rte_Call_R_FRM_bAcvCll_GetFunctionPermission
 * '<S30>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/convertout1
 * '<S31>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/convertout2
 * '<S32>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/convertout3
 * '<S33>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/convertout4
 * '<S34>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse
 * '<S35>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F0_03_BouclageSC
 * '<S36>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/IgSys_agIgTarOfs_OfsAgIg_T
 * '<S37>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division
 * '<S38>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division1
 * '<S39>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/SingleToFixdt
 * '<S40>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/SingleToFixdt1
 * '<S41>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division/Data Type Scaling Strip
 * '<S42>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division/Data Type Police No Floating Point1
 * '<S43>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division/If Action Subsystem2
 * '<S44>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division/If Action Subsystem3
 * '<S45>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division1/Data Type Scaling Strip
 * '<S46>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division1/Data Type Police No Floating Point1
 * '<S47>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division1/If Action Subsystem2
 * '<S48>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2144_2_v1_0/F0_01_Calcul_consigne_avance/F01_Rendement_avance_inverse/Secured fixpoint division1/If Action Subsystem3
 * '<S49>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure
 * '<S50>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure_Default
 * '<S51>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/Rte_Call_R_FRM_bLimSelCutOff_GetFunctionPermission
 * '<S52>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/convertout
 * '<S53>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj
 * '<S54>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective
 * '<S55>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_01_Preparer_detection_coupure
 * '<S56>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_02_Detecter_coupure
 * '<S57>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_03_Appliquer_retard
 * '<S58>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_01_Preparer_detection_coupure/UnitDelay1
 * '<S59>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_03_Appliquer_retard/UnitDelay1
 * '<S60>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_03_Appliquer_retard/UnitDelay2
 * '<S61>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_03_Appliquer_retard/UnitDelay3
 * '<S62>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_03_Appliquer_retard/UnitDelay4
 * '<S63>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_03_Appliquer_retard/UnitDelay5
 * '<S64>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_01_retarder_coupure_reinj/F1_01_01_03_Appliquer_retard/UnitDelay6
 * '<S65>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp
 * '<S66>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp1
 * '<S67>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp2
 * '<S68>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp3
 * '<S69>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/F01_If
 * '<S70>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/F02_Else
 * '<S71>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/division1
 * '<S72>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/division2
 * '<S73>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/division3
 * '<S74>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp/Data Type Conversion Inherited
 * '<S75>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp/Data Type Conversion Inherited1
 * '<S76>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp/Saturation Dynamic
 * '<S77>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp1/Data Type Conversion Inherited
 * '<S78>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp1/Data Type Conversion Inherited1
 * '<S79>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp1/Saturation Dynamic
 * '<S80>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp2/Data Type Conversion Inherited
 * '<S81>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp2/Data Type Conversion Inherited1
 * '<S82>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp2/Saturation Dynamic
 * '<S83>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp3/Data Type Conversion Inherited
 * '<S84>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp3/Data Type Conversion Inherited1
 * '<S85>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/Clamp3/Saturation Dynamic
 * '<S86>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/F02_Else/F01_Condition1
 * '<S87>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/F02_Else/F01_Condition1_else
 * '<S88>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/F02_Else/F02_Condition2
 * '<S89>'  : AdvSpT_AUTOSAR/AdvSpT/F0_CSMT_CGMT08_2145_v1_1/F01_01_activation_calcul_consigne_coupure/F01_01_02_Consigne_coupure_selective/F02_Else/F02_Condition2_else
 */

/*-
 * Requirements for '<Root>': AdvSpT
 *
 * Inherited requirements for '<S1>/F00_AdvSp_Init':
 *  1. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_053.01 ;
 *  2. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_038.01 ;
 *  3. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_037.01 ;
 *  4. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_036.01 ;
 *  5. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_034.01 ;
 *
 * Inherited requirements for '<S1>/F00_IgAdvEffSp_Init':
 *  1. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_049.01 ;
 *  2. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_044.01 ;
 *  3. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_043.01 ;
 *
 * Inherited requirements for '<S1>/F00_IgAdvSelCutOff_Init':
 *  1. SubSystem "F00_IgAdvSelCutOff_Init" !Trace_To : VEMS_R_10_06437_010.01 ;
 *  2. SubSystem "F00_IgAdvSelCutOff_Init" !Trace_To : VEMS_R_10_06437_009.01 ;
 *  3. SubSystem "F00_IgAdvSelCutOff_Init" !Trace_To : VEMS_R_10_06437_008.01 ;
 *  4. SubSystem "F00_IgAdvSelCutOff_Init" !Trace_To : VEMS_R_10_06437_051.01 ;
 *
 * Inherited requirements for '<S1>/F0_CSMT_CGMT08_2013_v1_1':
 *  1. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_001.01 ;
 *  2. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_050.01 ;
 *  3. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_044.01 ;
 *  4. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_043.01 ;
 *  5. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_041.01 ;
 *  6. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_040.01 ;
 *  7. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_039.02 ;
 *  8. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_023.01 ;
 *
 * Inherited requirements for '<S1>/F0_CSMT_CGMT08_2144_2_v1_0':
 *  1. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_004.01 ;
 *  2. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_055.01 ;
 *  3. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_048.01 ;
 *  4. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_044.01 ;
 *  5. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_043.01 ;
 *  6. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_042.01 ;
 *  7. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_035.01 ;
 *  8. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_038.01 ;
 *  9. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_037.01 ;
 *  10. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_036.01 ;
 *  11. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_034.01 ;
 *  12. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_033.01 ;
 *  13. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_032.01 ;
 *  14. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_031.01 ;
 *  15. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_030.01 ;
 *  16. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_023.01 ;
 *
 * Inherited requirements for '<S1>/F0_CSMT_CGMT08_2145_v1_1':
 *  1. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_009.01 ;
 *  2. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_008.01 ;
 *  3. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_052.01 ;
 *  4. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_047.01 ;
 *  5. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_028.01 ;
 *  6. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_029.01 ;
 *  7. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_027.01 ;
 *  8. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_026.01 ;
 *  9. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_025.01 ;
 *  10. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_024.01 ;
 *  11. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_023.01 ;
 *  12. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_022.01 ;
 *  13. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_021.01 ;
 *  14. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_020.01 ;
 *  15. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_019.01 ;
 *  16. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_018.01 ;

 */
#endif                                 /* RTW_HEADER_AdvSpT_h_ */

/*-------------------------------- end of file -------------------------------*/
