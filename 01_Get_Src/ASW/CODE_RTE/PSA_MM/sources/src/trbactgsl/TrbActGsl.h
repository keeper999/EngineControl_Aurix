/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActGsl                                               */
/* !Description     : TrbActGsl Software Component                            */
/*                                                                            */
/* !Module          : TrbActGsl                                               */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : TrbActGsl.h                                             */
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
/*   Model name       : TrbActGsl_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActGsl                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M15-TrbActGsl/5-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   15 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_TrbActGsl_h_
#define RTW_HEADER_TrbActGsl_h_
#ifndef TrbActGsl_COMMON_INCLUDES_
# define TrbActGsl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_TrbActGsl.h"
#include "TrbActGsl_import.h"
#include "TrbActGsl_nvm.h"
#include "rtw_shared_utils.h"
#include "rt_SATURATE.h"
#endif                                 /* TrbActGsl_COMMON_INCLUDES_ */

#include "TrbActGsl_types.h"

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
  UInt16 TmpSignalConversionAtExt_nEngOu;
  UInt16 TmpSignalConversionAtTrbAct_rOp;
  SInt16 EepromReadAccess;            /* '<S6>/EepromReadAccess' */
  SInt16 EepromReadAccess_p;          /* '<S8>/EepromReadAccess' */
  SInt16 OutDTConv;                   /* '<S68>/OutDTConv' */
  UInt16 EepromReadAccess1;          /* '<S6>/EepromReadAccess1' */
  UInt16 EepromReadAccess1_e;        /* '<S8>/EepromReadAccess1' */
  UInt16 OutDTConv_l;                /* '<S75>/OutDTConv' */
} BlockIO_TrbActGsl;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay;                  /* '<S106>/UnitDelay' */
  Float32 UnitDelay_c;                /* '<S110>/UnitDelay' */
  Float32 UnitDelay_DSTATE;           /* '<S83>/Unit Delay' */
  Float32 UnitDelay_p;                /* '<S40>/UnitDelay' */
  Boolean UnitDelay_f;               /* '<S106>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_f;        /* '<S104>/UnitDelay' */
  Boolean UnitDelay_n;               /* '<S110>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_k;        /* '<S108>/UnitDelay' */
  Boolean UnitDelay_a;               /* '<S50>/UnitDelay' */
  Boolean UnitDelay_k;               /* '<S50>/UnitDelay1' */
  Boolean UnitDelay_g;               /* '<S40>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_j;        /* '<S38>/UnitDelay' */
} D_Work_TrbActGsl;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S33>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxInde[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S116>/Lookup Table (n-D)'
   *   '<S32>/Lookup Table (n-D)'
   */
  UInt32 pooled12[2];

  /* Computed Parameter: LookupTablenD_maxIn_f
   * Referenced by: '<S47>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxIn_f[2];

  /* Computed Parameter: LookupTablenD_maxIn_l
   * Referenced by: '<S115>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxIn_l[2];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S50>/Logic'
   */
  Boolean Logic_table[16];
} ConstParam_TrbActGsl;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define TrbActGsl_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActGsl_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_TrbActGsl TrbActGsl_B;

/* Block states (auto storage) */
extern D_Work_TrbActGsl TrbActGsl_DWork;




#define TrbActGsl_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActGsl_MemMap.h"
#define TrbActGsl_START_SEC_CODE
#include "TrbActGsl_MemMap.h"

extern void Runnable_TrbActGsl_Init(void);
/* Model entry point functions */
extern void RE_TrbActGsl_001_MSE(void);
extern void RE_TrbActGsl_004_TEV(void);
extern void RE_TrbActGsl_003_TEV(void);
extern void RE_TrbActGsl_002_TEV(void);

#define TrbActGsl_STOP_SEC_CODE
#include "TrbActGsl_MemMap.h"

#define TrbActGsl_START_SEC_CONST_UNSPECIFIED
#include "TrbActGsl_MemMap.h"

/* Constant parameters (auto storage) */
extern const ConstParam_TrbActGsl TrbActGsl_ConstP;

#define TrbActGsl_STOP_SEC_CONST_UNSPECIFIED
#include "TrbActGsl_MemMap.h"

#define TrbActGsl_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActGsl_MemMap.h"

/* Model init function */


#define TrbActGsl_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActGsl_MemMap.h"

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
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S32>/x1' : Unused code path elimination
 * Block '<S32>/x2' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S33>/x1' : Unused code path elimination
 * Block '<S33>/x2' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Relational Operator' : Unused code path elimination
 * Block '<S42>/Relational Operator1' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Propagation' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S47>/x1' : Unused code path elimination
 * Block '<S47>/x2' : Unused code path elimination
 * Block '<S50>/LO3' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Relational Operator' : Unused code path elimination
 * Block '<S51>/Relational Operator1' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Propagation' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Relational Operator' : Unused code path elimination
 * Block '<S52>/Relational Operator1' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Data Type Propagation' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Relational Operator' : Unused code path elimination
 * Block '<S53>/Relational Operator1' : Unused code path elimination
 * Block '<S97>/Data Type Duplicate' : Unused code path elimination
 * Block '<S97>/Data Type Propagation' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Relational Operator' : Unused code path elimination
 * Block '<S54>/Relational Operator1' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Propagation' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Relational Operator' : Unused code path elimination
 * Block '<S55>/Relational Operator1' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Data Type Propagation' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S64>/x1' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S65>/x1' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S66>/x' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S67>/x' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S115>/x1' : Unused code path elimination
 * Block '<S115>/x2' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S116>/x1' : Unused code path elimination
 * Block '<S116>/x2' : Unused code path elimination
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/copy' : Eliminate redundant signal conversion block
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Switch' : Eliminated due to constant selection input
 * Block '<S34>/Switch' : Eliminated due to constant selection input
 * Block '<S35>/Switch' : Eliminated due to constant selection input
 * Block '<S36>/Switch' : Eliminated due to constant selection input
 * Block '<S44>/Conversion' : Eliminate redundant data type conversion
 * Block '<S45>/Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Switch' : Eliminated due to constant selection input
 * Block '<S48>/Switch' : Eliminated due to constant selection input
 * Block '<S30>/Switch' : Eliminated due to constant selection input
 * Block '<S89>/Conversion' : Eliminate redundant data type conversion
 * Block '<S90>/Conversion' : Eliminate redundant data type conversion
 * Block '<S92>/Conversion' : Eliminate redundant data type conversion
 * Block '<S93>/Conversion' : Eliminate redundant data type conversion
 * Block '<S95>/Conversion' : Eliminate redundant data type conversion
 * Block '<S96>/Conversion' : Eliminate redundant data type conversion
 * Block '<S98>/Conversion' : Eliminate redundant data type conversion
 * Block '<S99>/Conversion' : Eliminate redundant data type conversion
 * Block '<S101>/Conversion' : Eliminate redundant data type conversion
 * Block '<S102>/Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S57>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S59>/Switch' : Eliminated due to constant selection input
 * Block '<S60>/Switch' : Eliminated due to constant selection input
 * Block '<S68>/Switch' : Eliminated due to constant selection input
 * Block '<S69>/Switch' : Eliminated due to constant selection input
 * Block '<S70>/Switch' : Eliminated due to constant selection input
 * Block '<S71>/Switch' : Eliminated due to constant selection input
 * Block '<S72>/Switch' : Eliminated due to constant selection input
 * Block '<S73>/Switch' : Eliminated due to constant selection input
 * Block '<S74>/Switch' : Eliminated due to constant selection input
 * Block '<S75>/Switch' : Eliminated due to constant selection input
 * Block '<S76>/Switch' : Eliminated due to constant selection input
 * Block '<S77>/Switch' : Eliminated due to constant selection input
 * Block '<S78>/Switch' : Eliminated due to constant selection input
 * Block '<S79>/Switch' : Eliminated due to constant selection input
 * Block '<S80>/Switch' : Eliminated due to constant selection input
 * Block '<S81>/Switch' : Eliminated due to constant selection input
 * Block '<S82>/Switch' : Eliminated due to constant selection input
 * Block '<S112>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S121>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S121>/Switch' : Eliminated due to constant selection input
 * Block '<S117>/Switch' : Eliminated due to constant selection input
 * Block '<S118>/Switch' : Eliminated due to constant selection input
 * Block '<S39>/Data Type Conversion' : Unused code path elimination
 * Block '<S34>/Add3' : Unused code path elimination
 * Block '<S34>/Add4' : Unused code path elimination
 * Block '<S34>/Constant' : Unused code path elimination
 * Block '<S34>/Relational Operator' : Unused code path elimination
 * Block '<S34>/Switch1' : Unused code path elimination
 * Block '<S34>/offset2' : Unused code path elimination
 * Block '<S34>/offset3' : Unused code path elimination
 * Block '<S34>/offset4' : Unused code path elimination
 * Block '<S35>/Add2' : Unused code path elimination
 * Block '<S35>/Constant' : Unused code path elimination
 * Block '<S35>/offset1' : Unused code path elimination
 * Block '<S36>/Add2' : Unused code path elimination
 * Block '<S36>/Constant' : Unused code path elimination
 * Block '<S36>/offset1' : Unused code path elimination
 * Block '<S43>/Add2' : Unused code path elimination
 * Block '<S43>/Constant' : Unused code path elimination
 * Block '<S43>/offset1' : Unused code path elimination
 * Block '<S48>/Add3' : Unused code path elimination
 * Block '<S48>/Add4' : Unused code path elimination
 * Block '<S48>/Constant' : Unused code path elimination
 * Block '<S48>/Relational Operator' : Unused code path elimination
 * Block '<S48>/Switch1' : Unused code path elimination
 * Block '<S48>/offset2' : Unused code path elimination
 * Block '<S48>/offset3' : Unused code path elimination
 * Block '<S48>/offset4' : Unused code path elimination
 * Block '<S30>/Add2' : Unused code path elimination
 * Block '<S30>/Constant' : Unused code path elimination
 * Block '<S30>/offset1' : Unused code path elimination
 * Block '<S105>/Data Type Conversion' : Unused code path elimination
 * Block '<S109>/Data Type Conversion' : Unused code path elimination
 * Block '<S68>/Add2' : Unused code path elimination
 * Block '<S68>/Constant' : Unused code path elimination
 * Block '<S68>/offset1' : Unused code path elimination
 * Block '<S69>/Add3' : Unused code path elimination
 * Block '<S69>/Add4' : Unused code path elimination
 * Block '<S69>/Constant' : Unused code path elimination
 * Block '<S69>/Relational Operator' : Unused code path elimination
 * Block '<S69>/Switch1' : Unused code path elimination
 * Block '<S69>/offset2' : Unused code path elimination
 * Block '<S69>/offset3' : Unused code path elimination
 * Block '<S69>/offset4' : Unused code path elimination
 * Block '<S70>/Add2' : Unused code path elimination
 * Block '<S70>/Constant' : Unused code path elimination
 * Block '<S70>/offset1' : Unused code path elimination
 * Block '<S71>/Add2' : Unused code path elimination
 * Block '<S71>/Constant' : Unused code path elimination
 * Block '<S71>/offset1' : Unused code path elimination
 * Block '<S72>/Add3' : Unused code path elimination
 * Block '<S72>/Add4' : Unused code path elimination
 * Block '<S72>/Constant' : Unused code path elimination
 * Block '<S72>/Relational Operator' : Unused code path elimination
 * Block '<S72>/Switch1' : Unused code path elimination
 * Block '<S72>/offset2' : Unused code path elimination
 * Block '<S72>/offset3' : Unused code path elimination
 * Block '<S72>/offset4' : Unused code path elimination
 * Block '<S73>/Add2' : Unused code path elimination
 * Block '<S73>/Constant' : Unused code path elimination
 * Block '<S73>/offset1' : Unused code path elimination
 * Block '<S74>/Add3' : Unused code path elimination
 * Block '<S74>/Add4' : Unused code path elimination
 * Block '<S74>/Constant' : Unused code path elimination
 * Block '<S74>/Relational Operator' : Unused code path elimination
 * Block '<S74>/Switch1' : Unused code path elimination
 * Block '<S74>/offset2' : Unused code path elimination
 * Block '<S74>/offset3' : Unused code path elimination
 * Block '<S74>/offset4' : Unused code path elimination
 * Block '<S75>/Add3' : Unused code path elimination
 * Block '<S75>/Add4' : Unused code path elimination
 * Block '<S75>/Constant' : Unused code path elimination
 * Block '<S75>/Relational Operator' : Unused code path elimination
 * Block '<S75>/Switch1' : Unused code path elimination
 * Block '<S75>/offset2' : Unused code path elimination
 * Block '<S75>/offset3' : Unused code path elimination
 * Block '<S75>/offset4' : Unused code path elimination
 * Block '<S76>/Add2' : Unused code path elimination
 * Block '<S76>/Constant' : Unused code path elimination
 * Block '<S76>/offset1' : Unused code path elimination
 * Block '<S77>/Add2' : Unused code path elimination
 * Block '<S77>/Constant' : Unused code path elimination
 * Block '<S77>/offset1' : Unused code path elimination
 * Block '<S78>/Add2' : Unused code path elimination
 * Block '<S78>/Constant' : Unused code path elimination
 * Block '<S78>/offset1' : Unused code path elimination
 * Block '<S79>/Add2' : Unused code path elimination
 * Block '<S79>/Constant' : Unused code path elimination
 * Block '<S79>/offset1' : Unused code path elimination
 * Block '<S80>/Add3' : Unused code path elimination
 * Block '<S80>/Add4' : Unused code path elimination
 * Block '<S80>/Constant' : Unused code path elimination
 * Block '<S80>/Relational Operator' : Unused code path elimination
 * Block '<S80>/Switch1' : Unused code path elimination
 * Block '<S80>/offset2' : Unused code path elimination
 * Block '<S80>/offset3' : Unused code path elimination
 * Block '<S80>/offset4' : Unused code path elimination
 * Block '<S81>/Add2' : Unused code path elimination
 * Block '<S81>/Constant' : Unused code path elimination
 * Block '<S81>/offset1' : Unused code path elimination
 * Block '<S82>/Add3' : Unused code path elimination
 * Block '<S82>/Add4' : Unused code path elimination
 * Block '<S82>/Constant' : Unused code path elimination
 * Block '<S82>/Relational Operator' : Unused code path elimination
 * Block '<S82>/Switch1' : Unused code path elimination
 * Block '<S82>/offset2' : Unused code path elimination
 * Block '<S82>/offset3' : Unused code path elimination
 * Block '<S82>/offset4' : Unused code path elimination
 * Block '<S114>/Constant' : Unused code path elimination
 * Block '<S122>/Data Type Conversion' : Unused code path elimination
 * Block '<S117>/Add2' : Unused code path elimination
 * Block '<S117>/Constant' : Unused code path elimination
 * Block '<S117>/offset1' : Unused code path elimination
 * Block '<S118>/Add3' : Unused code path elimination
 * Block '<S118>/Add4' : Unused code path elimination
 * Block '<S118>/Constant' : Unused code path elimination
 * Block '<S118>/Relational Operator' : Unused code path elimination
 * Block '<S118>/Switch1' : Unused code path elimination
 * Block '<S118>/offset2' : Unused code path elimination
 * Block '<S118>/offset3' : Unused code path elimination
 * Block '<S118>/offset4' : Unused code path elimination
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
 * hilite_system('TrbActGsl_AUTOSAR/TrbActGsl')    - opens subsystem TrbActGsl_AUTOSAR/TrbActGsl
 * hilite_system('TrbActGsl_AUTOSAR/TrbActGsl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : TrbActGsl_AUTOSAR
 * '<S1>'   : TrbActGsl_AUTOSAR/TrbActGsl
 * '<S6>'   : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst
 * '<S7>'   : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn
 * '<S8>'   : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO
 * '<S9>'   : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim
 * '<S10>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout1
 * '<S11>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout10
 * '<S12>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout2
 * '<S13>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout3
 * '<S14>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout4
 * '<S15>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout5
 * '<S16>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout6
 * '<S17>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout7
 * '<S18>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout8
 * '<S19>'  : TrbActGsl_AUTOSAR/TrbActGsl/F00_TrbActGl_Rst/Convertout9
 * '<S20>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/Convertout10
 * '<S21>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/Convertout2
 * '<S22>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/Convertout3
 * '<S23>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/Convertout4
 * '<S24>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/Convertout6
 * '<S25>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif
 * '<S26>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F02_PnmActMaxPresDif
 * '<S27>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F03_PnmActPresDif
 * '<S28>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F04_RCOReqClcn
 * '<S29>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F05_TrbActCtl
 * '<S30>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/SingleToFixdt1
 * '<S31>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/Filtre_1er_ordre_avec_reset_PSA
 * '<S32>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/LookUp_2D
 * '<S33>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/LookUp_2D1
 * '<S34>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/SingleToFixdt
 * '<S35>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/SingleToFixdt1
 * '<S36>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/SingleToFixdt2
 * '<S37>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/multiplication1
 * '<S38>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/Filtre_1er_ordre_avec_reset_PSA/IniCdn
 * '<S39>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/Filtre_1er_ordre_avec_reset_PSA/Reset du filtre
 * '<S40>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/Filtre_1er_ordre_avec_reset_PSA/UnitDly_ExtIni
 * '<S41>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F01_TrbActPresDif/Filtre_1er_ordre_avec_reset_PSA/filtrage
 * '<S42>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F03_PnmActPresDif/Clamp
 * '<S43>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F03_PnmActPresDif/SingleToFixdt1
 * '<S44>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F03_PnmActPresDif/Clamp/Data Type Conversion Inherited
 * '<S45>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F03_PnmActPresDif/Clamp/Data Type Conversion Inherited1
 * '<S46>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F03_PnmActPresDif/Clamp/Saturation Dynamic
 * '<S47>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F04_RCOReqClcn/LookUp_2D
 * '<S48>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F04_RCOReqClcn/SingleToFixdt1
 * '<S49>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F05_TrbActCtl/PosHys
 * '<S50>'  : TrbActGsl_AUTOSAR/TrbActGsl/F01_RCOReqClcn/F05_TrbActCtl/PosHys/BasculeRS
 * '<S51>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp
 * '<S52>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp1
 * '<S53>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp2
 * '<S54>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp3
 * '<S55>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp4
 * '<S56>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Convertout3
 * '<S57>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Convertout7
 * '<S58>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Convertout9
 * '<S59>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA
 * '<S60>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA1
 * '<S61>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Interp_1D
 * '<S62>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Interp_1D1
 * '<S63>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Interp_2D
 * '<S64>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/LookUp_1D
 * '<S65>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/LookUp_1D1
 * '<S66>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/PreLookUp_Binary
 * '<S67>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/PreLookUp_Binary1
 * '<S68>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt1
 * '<S69>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt10
 * '<S70>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt11
 * '<S71>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt12
 * '<S72>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt13
 * '<S73>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt14
 * '<S74>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt15
 * '<S75>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt2
 * '<S76>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt3
 * '<S77>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt4
 * '<S78>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt5
 * '<S79>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt6
 * '<S80>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt7
 * '<S81>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt8
 * '<S82>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SingleToFixdt9
 * '<S83>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/SubSystem
 * '<S84>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/multiplication1
 * '<S85>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/multiplication2
 * '<S86>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/multiplication3
 * '<S87>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/multiplication4
 * '<S88>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/multiplication5
 * '<S89>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp/Data Type Conversion Inherited
 * '<S90>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp/Data Type Conversion Inherited1
 * '<S91>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp/Saturation Dynamic
 * '<S92>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp1/Data Type Conversion Inherited
 * '<S93>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp1/Data Type Conversion Inherited1
 * '<S94>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp1/Saturation Dynamic
 * '<S95>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp2/Data Type Conversion Inherited
 * '<S96>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp2/Data Type Conversion Inherited1
 * '<S97>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp2/Saturation Dynamic
 * '<S98>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp3/Data Type Conversion Inherited
 * '<S99>'  : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp3/Data Type Conversion Inherited1
 * '<S100>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp3/Saturation Dynamic
 * '<S101>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp4/Data Type Conversion Inherited
 * '<S102>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp4/Data Type Conversion Inherited1
 * '<S103>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Clamp4/Saturation Dynamic
 * '<S104>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA/IniCdn
 * '<S105>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA/Reset du filtre
 * '<S106>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA/UnitDly_ExtIni
 * '<S107>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA/filtrage
 * '<S108>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA1/IniCdn
 * '<S109>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA1/Reset du filtre
 * '<S110>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA1/UnitDly_ExtIni
 * '<S111>' : TrbActGsl_AUTOSAR/TrbActGsl/F02_rRCO/Filtre_1er_ordre_avec_reset_PSA1/filtrage
 * '<S112>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/Convertout1
 * '<S113>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/Convertout2
 * '<S114>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/Filtre_1er_ordre1
 * '<S115>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/LookUp_2D
 * '<S116>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/LookUp_2D1
 * '<S117>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/SingleToFixdt1
 * '<S118>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/SingleToFixdt5
 * '<S119>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/multiplication2
 * '<S120>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/multiplication3
 * '<S121>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/Filtre_1er_ordre1/Filtre_1er_ordre  avec reset
 * '<S122>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/Filtre_1er_ordre1/Filtre_1er_ordre  avec reset/Reset du filtre
 * '<S123>' : TrbActGsl_AUTOSAR/TrbActGsl/F03_rOpTrbActEstim/Filtre_1er_ordre1/Filtre_1er_ordre  avec reset/filtrage
 */

/*-
 * Requirements for '<Root>': TrbActGsl
 *
 * Inherited requirements for '<S1>/F00_TrbActGl_Rst':
 *  1. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_034.02 ;
 *  2. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_001.01 ;
 *  3. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_002.01 ;
 *  4. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_003.01 ;
 *  5. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_010.01 ;
 *  6. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_011.01 ;
 *  7. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_012.01 ;
 *  8. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_014.01 ;
 *  9. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_015.01 ;
 *  10. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_016.01 ;
 *  11. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_018.01 ;
 *  12. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_028.01 ;
 *  13. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_027.01 ;
 *  14. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_032.01 ;
 *  15. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_030.02 ;
 *  16. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_031.02 ;
 *  17. SubSystem "F00_TrbActGl_Rst" !Trace_To : VEMS_R_10_07022_039.01 ;
 *
 * Inherited requirements for '<S1>/F01_RCOReqClcn':
 *  1. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_035.01 ;
 *  2. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_001.01 ;
 *  3. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_002.01 ;
 *  4. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_004.01 ;
 *  5. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_019.01 ;
 *  6. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_020.01 ;
 *  7. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_021.01 ;
 *  8. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_022.01 ;
 *  9. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_023.02 ;
 *  10. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_018.01 ;
 *  11. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_030.02 ;
 *  12. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_031.02 ;
 *  13. SubSystem "F01_RCOReqClcn" !Trace_To : VEMS_R_10_07022_032.01 ;
 *
 * Inherited requirements for '<S1>/F02_rRCO':
 *  1. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_036.02 ;
 *  2. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_010.01 ;
 *  3. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_011.01 ;
 *  4. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_013.01 ;
 *  5. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_024.01 ;
 *  6. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_025.01 ;
 *  7. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_026.01 ;
 *  8. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_032.01 ;
 *  9. SubSystem "F02_rRCO" !Trace_To : VEMS_R_10_07022_039.01 ;
 *
 * Inherited requirements for '<S1>/F03_rOpTrbActEstim':
 *  1. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_037.02 ;
 *  2. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_014.01 ;
 *  3. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_015.01 ;
 *  4. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_017.01 ;
 *  5. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_029.01 ;
 *  6. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_030.02 ;
 *  7. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_031.02 ;
 *  8. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_028.01 ;
 *  9. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_038.01 ;
 *  10. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_027.01 ;
 *  11. SubSystem "F03_rOpTrbActEstim" !Trace_To : VEMS_R_10_07022_040.01 ;

 */
#endif                                 /* RTW_HEADER_TrbActGsl_h_ */

/*-------------------------------- end of file -------------------------------*/
