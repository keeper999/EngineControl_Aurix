/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : InThMdlT                                                */
/* !Description     : InThMdlT Software Component                             */
/*                                                                            */
/* !Module          : InThMdlT                                                */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : InThMdlT.h                                              */
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
/*   Model name       : InThMdlT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /InThMdlT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M03-InThMdlT/5-S$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   17 Nov 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InThMdlT_h_
#define RTW_HEADER_InThMdlT_h_
#ifndef InThMdlT_COMMON_INCLUDES_
# define InThMdlT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_InThMdlT.h"
#include "InThMdlT_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FloorF.h"
#include "ACTEMS_LdexpF.h"
#include "rt_MAXf.h"
#include "rt_SATURATE.h"
#endif                                 /* InThMdlT_COMMON_INCLUDES_ */

#include "InThMdlT_types.h"

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

#define UNUSED_IO(x)                   (void) (x)

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Block signals (auto storage) */
typedef struct {
  UInt16 TmpSignalConversionAtExt_nEngOu;/* '<S12>/Ext_nEng' */
  UInt16 TmpSignalConversionAtUsThrM_tTh;/* '<S12>/UsThrM_tThrMes' */
  UInt16 TmpSignalConversionAtInThM_tWal;/* '<S12>/InThM_tWallInMnf' */
  UInt16 TmpSignalConversionAtInThM_tW_b;/* '<S12>/InThM_tWallInCylHead_irv' */
  UInt16 TmpSignalConversionAtUsThrM_tDs;/* '<S9>/UsThrM_tDsThrCorMes' */
  UInt16 TmpSignalConversionAtInM_mfEGRE;/* '<S12>/InM_mfEGREstimEGRVlv' */
  UInt16 TmpSignalConversionAtEngM_mfTot;/* '<S12>/EngM_mfTotExCor' */
  UInt16 TmpSignalConversionAtInThM_tEGR;/* '<S12>/InThM_tEGRInMnf' */
  UInt8 TmpSignalConversionAtEng_stEruO;/* '<S12>/Eng_stEru' */
} BlockIO_InThMdlT;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define InThMdlT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "InThMdlT_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InThMdlT InThMdlT_B;

#define InThMdlT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "InThMdlT_MemMap.h"
#define InThMdlT_START_SEC_CODE
#include "InThMdlT_MemMap.h"

extern void RE_InThMdl_Init(void);
/* Model entry point functions */
extern void RE_InThMdlT_006_TEV(void);
extern void RE_InThMdlT_004_TEV(void);
extern void RE_InThMdlT_005_TEV(void);
extern void RE_InThMdlT_008_TEV(void);
extern void RE_InThMdlT_007_TEV(void);
extern void RE_InThMdlT_002_TEV(void);
extern void RE_InThMdlT_001_MSE(void);

#define InThMdlT_STOP_SEC_CODE
#include "InThMdlT_MemMap.h"
#define InThMdlT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "InThMdlT_MemMap.h"




#define InThMdlT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "InThMdlT_MemMap.h"

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
 * Block '<S27>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S30>/Air_mfAir_A' : Unused code path elimination
 * Block '<S32>/BKPT1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S32>/TABLE' : Unused code path elimination
 * Block '<S33>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S34>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S51>/Data Type Propagation' : Unused code path elimination
 * Block '<S51>/Data Type Propagation1' : Unused code path elimination
 * Block '<S54>/Data Type Propagation' : Unused code path elimination
 * Block '<S54>/Data Type Conversion' : Unused code path elimination
 * Block '<S54>/Data Type Conversion1' : Unused code path elimination
 * Block '<S52>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S53>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S56>/Air_mfAir_A' : Unused code path elimination
 * Block '<S58>/BKPT1' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S58>/TABLE' : Unused code path elimination
 * Block '<S61>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S63>/Air_mfAir_A' : Unused code path elimination
 * Block '<S63>/Air_pAir_A' : Unused code path elimination
 * Block '<S64>/BKPT1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S64>/TABLE' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S65>/TABLE' : Unused code path elimination
 * Block '<S65>/TABLE1' : Unused code path elimination
 * Block '<S65>/TABLE2' : Unused code path elimination
 * Block '<S63>/Ext_nEngRef1_A' : Unused code path elimination
 * Block '<S66>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S70>/Air_pAir_A' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S71>/TABLE' : Unused code path elimination
 * Block '<S71>/TABLE1' : Unused code path elimination
 * Block '<S71>/TABLE2' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S72>/TABLE' : Unused code path elimination
 * Block '<S72>/TABLE1' : Unused code path elimination
 * Block '<S72>/TABLE2' : Unused code path elimination
 * Block '<S70>/Ext_nEngRef1_A' : Unused code path elimination
 * Block '<S70>/Ext_nEngRef1_A1' : Unused code path elimination
 * Block '<S73>/BKPT1' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S73>/TABLE' : Unused code path elimination
 * Block '<S70>/InThM_rEngSpdCor_A' : Unused code path elimination
 * Block '<S70>/InThM_rtInMnf_A' : Unused code path elimination
 * Block '<S74>/Data Type Propagation' : Unused code path elimination
 * Block '<S74>/Data Type Propagation1' : Unused code path elimination
 * Block '<S76>/Data Type Propagation' : Unused code path elimination
 * Block '<S76>/Data Type Conversion' : Unused code path elimination
 * Block '<S76>/Data Type Conversion1' : Unused code path elimination
 * Block '<S75>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S13>/Air_mfEGR_A' : Unused code path elimination
 * Block '<S13>/Eng_rAirLdRef2_A' : Unused code path elimination
 * Block '<S13>/Ext_nEngRef2_A' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S81>/TABLE' : Unused code path elimination
 * Block '<S81>/TABLE1' : Unused code path elimination
 * Block '<S81>/TABLE2' : Unused code path elimination
 * Block '<S82>/BKPT1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S82>/TABLE' : Unused code path elimination
 * Block '<S85>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S89>/Air_mfEGR_A' : Unused code path elimination
 * Block '<S92>/BKPT1' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S92>/TABLE' : Unused code path elimination
 * Block '<S93>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/copy' : Eliminate redundant signal conversion block
 * Block '<S32>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S71>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S79>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S44>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S45>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S47>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S48>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S86>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S86>/Switch' : Eliminated due to constant selection input
 * Block '<S81>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S81>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S82>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S83>/copy' : Eliminate redundant signal conversion block
 * Block '<S92>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S91>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Constant' : Unused code path elimination
 * Block '<S87>/Data Type Conversion' : Unused code path elimination
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
 * hilite_system('InThMdlT_AUTOSAR/InThMdlT')    - opens subsystem InThMdlT_AUTOSAR/InThMdlT
 * hilite_system('InThMdlT_AUTOSAR/InThMdlT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InThMdlT_AUTOSAR
 * '<S1>'   : InThMdlT_AUTOSAR/InThMdlT
 * '<S9>'   : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters
 * '<S10>'  : InThMdlT_AUTOSAR/InThMdlT/F02_Calcul_cylinder_head_wall_temp
 * '<S11>'  : InThMdlT_AUTOSAR/InThMdlT/F03_Manifold_wall_temp
 * '<S12>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold
 * '<S13>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp
 * '<S14>'  : InThMdlT_AUTOSAR/InThMdlT/F06_Egr_manifold_temp
 * '<S15>'  : InThMdlT_AUTOSAR/InThMdlT/F07_Reset_egr_manifold_temp
 * '<S16>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/F01_01_Reset_egr_manifold_temperature
 * '<S17>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/If Action Subsystem1
 * '<S18>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/autosar_testpoint
 * '<S19>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/autosar_testpoint1
 * '<S20>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/convertout
 * '<S21>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/convertout1
 * '<S22>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/convertout3
 * '<S23>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/convertout4
 * '<S24>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/convertout5
 * '<S25>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/convertout6
 * '<S26>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/convertout7
 * '<S27>'  : InThMdlT_AUTOSAR/InThMdlT/F01_Reset_manifold_parameters/multiplication1
 * '<S28>'  : InThMdlT_AUTOSAR/InThMdlT/F02_Calcul_cylinder_head_wall_temp/autosar_testpoint1
 * '<S29>'  : InThMdlT_AUTOSAR/InThMdlT/F03_Manifold_wall_temp/F03_1_Reset_manifold_wall_temperature
 * '<S30>'  : InThMdlT_AUTOSAR/InThMdlT/F03_Manifold_wall_temp/F03_2_Manifold_wall_temperature
 * '<S31>'  : InThMdlT_AUTOSAR/InThMdlT/F03_Manifold_wall_temp/convertout5
 * '<S32>'  : InThMdlT_AUTOSAR/InThMdlT/F03_Manifold_wall_temp/F03_2_Manifold_wall_temperature/InThM_facHeatFil_tWallInMnf_M
 * '<S33>'  : InThMdlT_AUTOSAR/InThMdlT/F03_Manifold_wall_temp/F03_2_Manifold_wall_temperature/multiplication
 * '<S34>'  : InThMdlT_AUTOSAR/InThMdlT/F03_Manifold_wall_temp/F03_2_Manifold_wall_temperature/multiplication1
 * '<S35>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_1_Calc_manifold_raw_temperature
 * '<S36>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_2_Manifold_heat_transfert_factor
 * '<S37>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_3_Calc_manifold_temperature
 * '<S38>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_4_Calc_cylinder_intake_temperature
 * '<S39>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_5_Calc_downgraded_mode
 * '<S40>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed
 * '<S41>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_7_Calc_downgraded_mode_engine_speed
 * '<S42>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/Rte_Call_R_FRM_bInhInThMEngSpdCor_GetFunctionPermission
 * '<S43>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/Rte_Call_R_FRM_bInhInThM_GetFunctionPermission
 * '<S44>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/convertout
 * '<S45>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/convertout1
 * '<S46>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/convertout2
 * '<S47>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/convertout3
 * '<S48>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/convertout5
 * '<S49>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_1_Calc_manifold_raw_temperature/F04_1_1_Reset_manifold_raw_temperature
 * '<S50>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_1_Calc_manifold_raw_temperature/F04_1_2_Manifold_raw_temperature
 * '<S51>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_1_Calc_manifold_raw_temperature/F04_1_2_Manifold_raw_temperature/Subsystem
 * '<S52>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_1_Calc_manifold_raw_temperature/F04_1_2_Manifold_raw_temperature/multiplication1
 * '<S53>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_1_Calc_manifold_raw_temperature/F04_1_2_Manifold_raw_temperature/multiplication2
 * '<S54>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_1_Calc_manifold_raw_temperature/F04_1_2_Manifold_raw_temperature/Subsystem/Data Type Police Only single
 * '<S55>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_1_Calc_manifold_raw_temperature/F04_1_2_Manifold_raw_temperature/Subsystem/If Action Subsystem3
 * '<S56>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_2_Manifold_heat_transfert_factor/F04_2_1_Calc_manifold_heat_transfert_factor
 * '<S57>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_2_Manifold_heat_transfert_factor/F04_2_2_Calc_manifold_heat_transfer_factor_Default
 * '<S58>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_2_Manifold_heat_transfert_factor/F04_2_1_Calc_manifold_heat_transfert_factor/InThM_facHeatExcWallInMnf_T
 * '<S59>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_3_Calc_manifold_temperature/F04_3_1_Reset_manifold_temperature
 * '<S60>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_3_Calc_manifold_temperature/F04_3_2_Manifold_temperature
 * '<S61>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_3_Calc_manifold_temperature/F04_3_2_Manifold_temperature/multiplication
 * '<S62>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_4_Calc_cylinder_intake_temperature/F04_4_1_Reset_cylinder_intake_temperature
 * '<S63>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_4_Calc_cylinder_intake_temperature/F04_4_2_Cylinder_intake_temperature
 * '<S64>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_4_Calc_cylinder_intake_temperature/F04_4_2_Cylinder_intake_temperature/Carto_1D
 * '<S65>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_4_Calc_cylinder_intake_temperature/F04_4_2_Cylinder_intake_temperature/Carto_2D
 * '<S66>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_4_Calc_cylinder_intake_temperature/F04_4_2_Cylinder_intake_temperature/multiplication
 * '<S67>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_5_Calc_downgraded_mode/F04_5_1_Reset_corrected_cyl_intake_temperature
 * '<S68>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_5_Calc_downgraded_mode/F04_5_2_Corrected_cyl_intake_temperature
 * '<S69>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_1_Reset_corrected_engine_speed
 * '<S70>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_2_Corrected_Engine_Speed
 * '<S71>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_2_Corrected_Engine_Speed/Carto_2D
 * '<S72>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_2_Corrected_Engine_Speed/Carto_2D1
 * '<S73>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_2_Corrected_Engine_Speed/InThM_rEngSpdCorDB_T
 * '<S74>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_2_Corrected_Engine_Speed/Subsystem
 * '<S75>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_2_Corrected_Engine_Speed/multiplication2
 * '<S76>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_2_Corrected_Engine_Speed/Subsystem/Data Type Police Only single
 * '<S77>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_6_Calc_Corrected_Engine_Speed/F04_6_2_Corrected_Engine_Speed/Subsystem/If Action Subsystem3
 * '<S78>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_7_Calc_downgraded_mode_engine_speed/F04_7_1_Reset_corrected_engine_speed
 * '<S79>'  : InThMdlT_AUTOSAR/InThMdlT/F04_Calc_manifold/F04_7_Calc_downgraded_mode_engine_speed/F04_7_2_Corrected_engine_speed
 * '<S80>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/Filtre_1er_ordre2
 * '<S81>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/InThM_tOfsCorUsEGRVlv_M
 * '<S82>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/InThM_tUsEGRVlv_T
 * '<S83>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/autosar_testpoint
 * '<S84>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/convertout1
 * '<S85>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/multiplication2
 * '<S86>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/Filtre_1er_ordre2/Filtre_1er_ordre  avec reset
 * '<S87>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/Filtre_1er_ordre2/Filtre_1er_ordre  avec reset/Reset du filtre
 * '<S88>'  : InThMdlT_AUTOSAR/InThMdlT/F05_Egr_temp/Filtre_1er_ordre2/Filtre_1er_ordre  avec reset/filtrage
 * '<S89>'  : InThMdlT_AUTOSAR/InThMdlT/F06_Egr_manifold_temp/F06_01_Egr_mnfld_temp
 * '<S90>'  : InThMdlT_AUTOSAR/InThMdlT/F06_Egr_manifold_temp/If Action Subsystem1
 * '<S91>'  : InThMdlT_AUTOSAR/InThMdlT/F06_Egr_manifold_temp/convertout
 * '<S92>'  : InThMdlT_AUTOSAR/InThMdlT/F06_Egr_manifold_temp/F06_01_Egr_mnfld_temp/InThM_FacHeatExcWallEGRPipe_T
 * '<S93>'  : InThMdlT_AUTOSAR/InThMdlT/F06_Egr_manifold_temp/F06_01_Egr_mnfld_temp/multiplication
 * '<S94>'  : InThMdlT_AUTOSAR/InThMdlT/F07_Reset_egr_manifold_temp/F07_01_Reset_egr_manifold_temperature
 * '<S95>'  : InThMdlT_AUTOSAR/InThMdlT/F07_Reset_egr_manifold_temp/If Action Subsystem1
 * '<S96>'  : InThMdlT_AUTOSAR/InThMdlT/F07_Reset_egr_manifold_temp/convertout
 */

/*-
 * Requirements for '<Root>': InThMdlT
 *
 * Inherited requirements for '<S1>/F01_Reset_manifold_parameters':
 *  1. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_037.01 ;
 *  2. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_039.01 ;
 *  3. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_050.01 ;
 *  4. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_040.01 ;
 *  5. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_051.02 ;
 *  6. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_036.01 ;
 *  7. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_049.01 ;
 *  8. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_048.01 ;
 *  9. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_047.01 ;
 *  10. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_045.02 ;
 *  11. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_041.01 ;
 *  12. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_060.02 ;
 *  13. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_059.02 ;
 *  14. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_061.02 ;
 *  15. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_062.02 ;
 *  16. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_076.01 ;
 *  17. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_075.01 ;
 *  18. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_074.01 ;
 *  19. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_014.01 ;
 *  20. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_011.01 ;
 *  21. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_012.01 ;
 *  22. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_013.01 ;
 *  23. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_007.01 ;
 *  24. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_008.01 ;
 *  25. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_009.01 ;
 *  26. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_003.01 ;
 *  27. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_002.01 ;
 *  28. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_001.01 ;
 *  29. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_101.01 ;
 *
 * Inherited requirements for '<S1>/F02_Calcul_cylinder_head_wall_temp':
 *  1. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_040.01 ;
 *  2. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_060.02 ;
 *  3. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_065.01 ;
 *  4. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_010.01 ;
 *  5. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_009.01 ;
 *  6. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_008.01 ;
 *  7. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_007.01 ;
 *
 * Inherited requirements for '<S1>/F03_Manifold_wall_temp':
 *  1. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_050.01 ;
 *  2. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_037.01 ;
 *  3. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_044.02 ;
 *  4. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_043.01 ;
 *  5. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_042.01 ;
 *  6. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_041.01 ;
 *  7. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_066.01 ;
 *  8. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_015.01 ;
 *  9. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_011.01 ;
 *  10. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_012.01 ;
 *  11. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_013.01 ;
 *
 * Inherited requirements for '<S1>/F04_Calc_manifold':
 *  1. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_078.01 ;
 *  2. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_044.02 ;
 *  3. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_056.01 ;
 *  4. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_037.01 ;
 *  5. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_038.01 ;
 *  6. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_055.01 ;
 *  7. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_060.02 ;
 *  8. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_051.02 ;
 *  9. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_045.02 ;
 *  10. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_047.01 ;
 *  11. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_048.01 ;
 *  12. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_049.01 ;
 *  13. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_067.02 ;
 *  14. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_080.01 ;
 *  15. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_079.01 ;
 *  16. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_103.01 ;
 *  17. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_104.01 ;
 *  18. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_039.01 ;
 *  19. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_052.01 ;
 *  20. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_101.01 ;
 *  21. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_102.01 ;
 *
 * Inherited requirements for '<S1>/F05_Egr_temp':
 *  1. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_055.01 ;
 *  2. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_038.01 ;
 *  3. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_058.01 ;
 *  4. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_061.02 ;
 *  5. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_059.02 ;
 *  6. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_068.02 ;
 *  7. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_077.01 ;
 *  8. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_075.01 ;
 *  9. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_074.01 ;
 *
 * Inherited requirements for '<S1>/F06_Egr_manifold_temp':
 *  1. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_005.01 ;
 *  2. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_051.02 ;
 *  3. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_038.01 ;
 *  4. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_039.01 ;
 *  5. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_037.01 ;
 *  6. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_060.02 ;
 *  7. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_061.02 ;
 *  8. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_036.01 ;
 *  9. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_063.01 ;
 *
 * Inherited requirements for '<S1>/F07_Reset_egr_manifold_temp':
 *  1. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_003.01 ;
 *  2. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_039.01 ;
 *  3. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_037.01 ;
 *  4. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_036.01 ;
 *  5. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_064.01 ;
 *  6. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_002.01 ;
 *  7. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_001.01 ;

 */
#endif                                 /* RTW_HEADER_InThMdlT_h_ */

/*-------------------------------- end of file -------------------------------*/
