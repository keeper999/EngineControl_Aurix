/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvCordT                                                */
/* !Description     : AdvCordT Software Component                             */
/*                                                                            */
/* !Module          : AdvCordT                                                */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : AdvCordT.h                                              */
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
/*   Model name       : AdvCordT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /AdvCordT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M07-AdvCordT/5-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvCordT_h_
#define RTW_HEADER_AdvCordT_h_
#ifndef AdvCordT_COMMON_INCLUDES_
# define AdvCordT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AdvCordT.h"
#include "AdvCordT_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "rt_MAX.h"
#include "rt_MAXf.h"
#include "rt_MIN.h"
#include "rt_MINf.h"
#endif                                 /* AdvCordT_COMMON_INCLUDES_ */

#include "AdvCordT_types.h"

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
  UInt8 TmpSignalConversionAtEng_noCmpr;
  UInt8 TmpSignalConversionAtIgSys_agIg;
} BlockIO_AdvCordT;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S115>/Unit Delay' */
  Float32 UnitDelay_DSTATE_i[3];      /* '<S102>/Unit Delay' */
  Float32 UnitDelay_DSTATE_j;         /* '<S83>/Unit Delay' */
  Boolean UnitDelay_DSTATE_iv;       /* '<S77>/Unit Delay' */
} D_Work_AdvCordT;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState F01_Init_decalage_avance_Trig_Z;/* '<S11>/F01_Init_decalage_avance' */
} PrevZCSigStates_AdvCordT;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_0_0_0_0_0'
   *   '<S52>/Cste_1_0_0_0_0_0_1'
   */
  Float32 pooled5[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_0_0_0_0'
   *   '<S52>/Cste_1_1_0_0_0_0_1'
   */
  Float32 pooled6[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_1_0_0_0'
   *   '<S52>/Cste_1_1_1_0_0_0_1'
   */
  Float32 pooled7[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_1_1_0_0'
   *   '<S52>/Cste_1_1_1_1_0_0_1'
   */
  Float32 pooled8[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_1_1_1_0'
   *   '<S52>/Cste_1_1_1_1_1_0_1'
   */
  Float32 pooled9[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_1_1_1_1'
   *   '<S52>/Cste_1_1_1_1_1_1_1'
   */
  Float32 pooled10[6];

  /* Computed Parameter: Cste_0_60_60_60_60_60
   * Referenced by: '<S52>/Cste_0_60_60_60_60_60'
   */
  Float32 Cste_0_60_60_60_60_60[6];

  /* Computed Parameter: Cste_0_0_60_60_60_60_
   * Referenced by: '<S52>/Cste_0_0_60_60_60_60'
   */
  Float32 Cste_0_0_60_60_60_60_[6];

  /* Computed Parameter: Cste_0_0_0_60_60_60_V
   * Referenced by: '<S52>/Cste_0_0_0_60_60_60'
   */
  Float32 Cste_0_0_0_60_60_60_V[6];

  /* Computed Parameter: Cste_0_0_0_0_60_60_Va
   * Referenced by: '<S52>/Cste_0_0_0_0_60_60'
   */
  Float32 Cste_0_0_0_0_60_60_Va[6];

  /* Computed Parameter: Cste_0_0_0_0_0_60_Val
   * Referenced by: '<S52>/Cste_0_0_0_0_0_60'
   */
  Float32 Cste_0_0_0_0_0_60_Val[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_0_0_0_0_0_0'
   *   '<S52>/Cste_0_0_0_0_0_0_1'
   */
  Float32 pooled11[6];

  /* Computed Parameter: Cste_0_36_36_36_36_36
   * Referenced by: '<S52>/Cste_0_36_36_36_36_36'
   */
  Float32 Cste_0_36_36_36_36_36[6];

  /* Computed Parameter: Cste_0_0_36_36_36_36_
   * Referenced by: '<S52>/Cste_0_0_36_36_36_36'
   */
  Float32 Cste_0_0_36_36_36_36_[6];

  /* Computed Parameter: Cste_0_0_0_36_36_36_V
   * Referenced by: '<S52>/Cste_0_0_0_36_36_36'
   */
  Float32 Cste_0_0_0_36_36_36_V[6];

  /* Computed Parameter: Cste_0_0_0_0_36_36_Va
   * Referenced by: '<S52>/Cste_0_0_0_0_36_36'
   */
  Float32 Cste_0_0_0_0_36_36_Va[6];

  /* Computed Parameter: Cste_0_0_0_0_0_36_Val
   * Referenced by: '<S52>/Cste_0_0_0_0_0_36'
   */
  Float32 Cste_0_0_0_0_0_36_Val[6];

  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S42>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxInde[2];
} ConstParam_AdvCordT;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define AdvCordT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvCordT_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_AdvCordT AdvCordT_B;

/* Block states (auto storage) */
extern D_Work_AdvCordT AdvCordT_DWork;




#define AdvCordT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvCordT_MemMap.h"
#define AdvCordT_START_SEC_CODE
#include "AdvCordT_MemMap.h"

extern void Runnable_AdvCordT_Init(void);
/* Model entry point functions */
extern void RE_AdvCordT_005_DRE(void);
extern void RE_AdvCordT_007_DRE(void);
extern void RE_AdvCordT_002_DRE(void);
extern void RE_AdvCordT_003_MSE(void);
extern void RE_AdvCordT_001_MSE(void);

#define AdvCordT_STOP_SEC_CODE
#include "AdvCordT_MemMap.h"

#define AdvCordT_START_SEC_CONST_UNSPECIFIED
#include "AdvCordT_MemMap.h"

/* Constant parameters (auto storage) */
extern const ConstParam_AdvCordT AdvCordT_ConstP;

#define AdvCordT_STOP_SEC_CONST_UNSPECIFIED
#include "AdvCordT_MemMap.h"

#define AdvCordT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvCordT_MemMap.h"

/* Model init function */


#define AdvCordT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvCordT_MemMap.h"

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
 * Block '<S42>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S42>/x1' : Unused code path elimination
 * Block '<S42>/x2' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/SignalConversion11' : Eliminate redundant signal conversion block
 * Block '<S8>/SignalConversion12' : Eliminate redundant signal conversion block
 * Block '<S8>/SignalConversion13' : Eliminate redundant signal conversion block
 * Block '<S8>/SignalConversion3' : Eliminate redundant signal conversion block
 * Block '<S8>/SignalConversion4' : Eliminate redundant signal conversion block
 * Block '<S8>/SignalConversion5' : Eliminate redundant signal conversion block
 * Block '<S32>/copy' : Eliminate redundant signal conversion block
 * Block '<S33>/copy' : Eliminate redundant signal conversion block
 * Block '<S34>/copy' : Eliminate redundant signal conversion block
 * Block '<S35>/copy' : Eliminate redundant signal conversion block
 * Block '<S36>/copy' : Eliminate redundant signal conversion block
 * Block '<S37>/copy' : Eliminate redundant signal conversion block
 * Block '<S38>/copy' : Eliminate redundant signal conversion block
 * Block '<S39>/copy' : Eliminate redundant signal conversion block
 * Block '<S43>/Switch' : Eliminated due to constant selection input
 * Block '<S44>/Switch' : Eliminated due to constant selection input
 * Block '<S46>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S47>/copy' : Eliminate redundant signal conversion block
 * Block '<S48>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S49>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S50>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Switch' : Eliminated due to constant selection input
 * Block '<S59>/Switch' : Eliminated due to constant selection input
 * Block '<S60>/Switch' : Eliminated due to constant selection input
 * Block '<S61>/Switch' : Eliminated due to constant selection input
 * Block '<S62>/Switch' : Eliminated due to constant selection input
 * Block '<S54>/Switch' : Eliminated due to constant selection input
 * Block '<S55>/Switch' : Eliminated due to constant selection input
 * Block '<S56>/Switch' : Eliminated due to constant selection input
 * Block '<S66>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S67>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S68>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S69>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/copy' : Eliminate redundant signal conversion block
 * Block '<S71>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S78>/Switch' : Eliminated due to constant selection input
 * Block '<S82>/Switch' : Eliminated due to constant selection input
 * Block '<S84>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S89>/Switch' : Eliminated due to constant selection input
 * Block '<S90>/Switch' : Eliminated due to constant selection input
 * Block '<S91>/Switch' : Eliminated due to constant selection input
 * Block '<S92>/Switch' : Eliminated due to constant selection input
 * Block '<S93>/Switch' : Eliminated due to constant selection input
 * Block '<S94>/Switch' : Eliminated due to constant selection input
 * Block '<S95>/Switch' : Eliminated due to constant selection input
 * Block '<S96>/Switch' : Eliminated due to constant selection input
 * Block '<S97>/Switch' : Eliminated due to constant selection input
 * Block '<S98>/Switch' : Eliminated due to constant selection input
 * Block '<S99>/Switch' : Eliminated due to constant selection input
 * Block '<S100>/Switch' : Eliminated due to constant selection input
 * Block '<S101>/Switch' : Eliminated due to constant selection input
 * Block '<S106>/Switch' : Eliminated due to constant selection input
 * Block '<S107>/Switch' : Eliminated due to constant selection input
 * Block '<S108>/Switch' : Eliminated due to constant selection input
 * Block '<S109>/Switch' : Eliminated due to constant selection input
 * Block '<S110>/Switch' : Eliminated due to constant selection input
 * Block '<S111>/Switch' : Eliminated due to constant selection input
 * Block '<S112>/Switch' : Eliminated due to constant selection input
 * Block '<S113>/Switch' : Eliminated due to constant selection input
 * Block '<S114>/Switch' : Eliminated due to constant selection input
 * Block '<S11>/SignalConversion1' : Eliminate redundant signal conversion block
 * Block '<S43>/Add3' : Unused code path elimination
 * Block '<S43>/Add4' : Unused code path elimination
 * Block '<S43>/Constant' : Unused code path elimination
 * Block '<S43>/Relational Operator' : Unused code path elimination
 * Block '<S43>/Switch1' : Unused code path elimination
 * Block '<S43>/offset2' : Unused code path elimination
 * Block '<S43>/offset3' : Unused code path elimination
 * Block '<S43>/offset4' : Unused code path elimination
 * Block '<S44>/Add3' : Unused code path elimination
 * Block '<S44>/Add4' : Unused code path elimination
 * Block '<S44>/Constant' : Unused code path elimination
 * Block '<S44>/Relational Operator' : Unused code path elimination
 * Block '<S44>/Switch1' : Unused code path elimination
 * Block '<S44>/offset2' : Unused code path elimination
 * Block '<S44>/offset3' : Unused code path elimination
 * Block '<S44>/offset4' : Unused code path elimination
 * Block '<S58>/Add3' : Unused code path elimination
 * Block '<S58>/Add4' : Unused code path elimination
 * Block '<S58>/Constant' : Unused code path elimination
 * Block '<S58>/Relational Operator' : Unused code path elimination
 * Block '<S58>/Switch1' : Unused code path elimination
 * Block '<S58>/offset2' : Unused code path elimination
 * Block '<S58>/offset3' : Unused code path elimination
 * Block '<S58>/offset4' : Unused code path elimination
 * Block '<S59>/Add3' : Unused code path elimination
 * Block '<S59>/Add4' : Unused code path elimination
 * Block '<S59>/Constant' : Unused code path elimination
 * Block '<S59>/Relational Operator' : Unused code path elimination
 * Block '<S59>/Switch1' : Unused code path elimination
 * Block '<S59>/offset2' : Unused code path elimination
 * Block '<S59>/offset3' : Unused code path elimination
 * Block '<S59>/offset4' : Unused code path elimination
 * Block '<S60>/Add3' : Unused code path elimination
 * Block '<S60>/Add4' : Unused code path elimination
 * Block '<S60>/Constant' : Unused code path elimination
 * Block '<S60>/Relational Operator' : Unused code path elimination
 * Block '<S60>/Switch1' : Unused code path elimination
 * Block '<S60>/offset2' : Unused code path elimination
 * Block '<S60>/offset3' : Unused code path elimination
 * Block '<S60>/offset4' : Unused code path elimination
 * Block '<S61>/Add3' : Unused code path elimination
 * Block '<S61>/Add4' : Unused code path elimination
 * Block '<S61>/Constant' : Unused code path elimination
 * Block '<S61>/Relational Operator' : Unused code path elimination
 * Block '<S61>/Switch1' : Unused code path elimination
 * Block '<S61>/offset2' : Unused code path elimination
 * Block '<S61>/offset3' : Unused code path elimination
 * Block '<S61>/offset4' : Unused code path elimination
 * Block '<S62>/Add3' : Unused code path elimination
 * Block '<S62>/Add4' : Unused code path elimination
 * Block '<S62>/Constant' : Unused code path elimination
 * Block '<S62>/Relational Operator' : Unused code path elimination
 * Block '<S62>/Switch1' : Unused code path elimination
 * Block '<S62>/offset2' : Unused code path elimination
 * Block '<S62>/offset3' : Unused code path elimination
 * Block '<S62>/offset4' : Unused code path elimination
 * Block '<S54>/Add3' : Unused code path elimination
 * Block '<S54>/Add4' : Unused code path elimination
 * Block '<S54>/Constant' : Unused code path elimination
 * Block '<S54>/Relational Operator' : Unused code path elimination
 * Block '<S54>/Switch1' : Unused code path elimination
 * Block '<S54>/offset2' : Unused code path elimination
 * Block '<S54>/offset3' : Unused code path elimination
 * Block '<S54>/offset4' : Unused code path elimination
 * Block '<S55>/Add3' : Unused code path elimination
 * Block '<S55>/Add4' : Unused code path elimination
 * Block '<S55>/Constant' : Unused code path elimination
 * Block '<S55>/Relational Operator' : Unused code path elimination
 * Block '<S55>/Switch1' : Unused code path elimination
 * Block '<S55>/offset2' : Unused code path elimination
 * Block '<S55>/offset3' : Unused code path elimination
 * Block '<S55>/offset4' : Unused code path elimination
 * Block '<S56>/Add3' : Unused code path elimination
 * Block '<S56>/Add4' : Unused code path elimination
 * Block '<S56>/Constant' : Unused code path elimination
 * Block '<S56>/Relational Operator' : Unused code path elimination
 * Block '<S56>/Switch1' : Unused code path elimination
 * Block '<S56>/offset2' : Unused code path elimination
 * Block '<S56>/offset3' : Unused code path elimination
 * Block '<S56>/offset4' : Unused code path elimination
 * Block '<S78>/Add3' : Unused code path elimination
 * Block '<S78>/Add4' : Unused code path elimination
 * Block '<S78>/Constant' : Unused code path elimination
 * Block '<S78>/Relational Operator' : Unused code path elimination
 * Block '<S78>/Switch1' : Unused code path elimination
 * Block '<S78>/offset2' : Unused code path elimination
 * Block '<S78>/offset3' : Unused code path elimination
 * Block '<S78>/offset4' : Unused code path elimination
 * Block '<S82>/Add3' : Unused code path elimination
 * Block '<S82>/Add4' : Unused code path elimination
 * Block '<S82>/Constant' : Unused code path elimination
 * Block '<S82>/Relational Operator' : Unused code path elimination
 * Block '<S82>/Switch1' : Unused code path elimination
 * Block '<S82>/offset2' : Unused code path elimination
 * Block '<S82>/offset3' : Unused code path elimination
 * Block '<S82>/offset4' : Unused code path elimination
 * Block '<S89>/Add3' : Unused code path elimination
 * Block '<S89>/Add4' : Unused code path elimination
 * Block '<S89>/Constant' : Unused code path elimination
 * Block '<S89>/Relational Operator' : Unused code path elimination
 * Block '<S89>/Switch1' : Unused code path elimination
 * Block '<S89>/offset2' : Unused code path elimination
 * Block '<S89>/offset3' : Unused code path elimination
 * Block '<S89>/offset4' : Unused code path elimination
 * Block '<S90>/Add3' : Unused code path elimination
 * Block '<S90>/Add4' : Unused code path elimination
 * Block '<S90>/Constant' : Unused code path elimination
 * Block '<S90>/Relational Operator' : Unused code path elimination
 * Block '<S90>/Switch1' : Unused code path elimination
 * Block '<S90>/offset2' : Unused code path elimination
 * Block '<S90>/offset3' : Unused code path elimination
 * Block '<S90>/offset4' : Unused code path elimination
 * Block '<S91>/Add3' : Unused code path elimination
 * Block '<S91>/Add4' : Unused code path elimination
 * Block '<S91>/Constant' : Unused code path elimination
 * Block '<S91>/Relational Operator' : Unused code path elimination
 * Block '<S91>/Switch1' : Unused code path elimination
 * Block '<S91>/offset2' : Unused code path elimination
 * Block '<S91>/offset3' : Unused code path elimination
 * Block '<S91>/offset4' : Unused code path elimination
 * Block '<S92>/Add3' : Unused code path elimination
 * Block '<S92>/Add4' : Unused code path elimination
 * Block '<S92>/Constant' : Unused code path elimination
 * Block '<S92>/Relational Operator' : Unused code path elimination
 * Block '<S92>/Switch1' : Unused code path elimination
 * Block '<S92>/offset2' : Unused code path elimination
 * Block '<S92>/offset3' : Unused code path elimination
 * Block '<S92>/offset4' : Unused code path elimination
 * Block '<S93>/Add3' : Unused code path elimination
 * Block '<S93>/Add4' : Unused code path elimination
 * Block '<S93>/Constant' : Unused code path elimination
 * Block '<S93>/Relational Operator' : Unused code path elimination
 * Block '<S93>/Switch1' : Unused code path elimination
 * Block '<S93>/offset2' : Unused code path elimination
 * Block '<S93>/offset3' : Unused code path elimination
 * Block '<S93>/offset4' : Unused code path elimination
 * Block '<S94>/Add3' : Unused code path elimination
 * Block '<S94>/Add4' : Unused code path elimination
 * Block '<S94>/Constant' : Unused code path elimination
 * Block '<S94>/Relational Operator' : Unused code path elimination
 * Block '<S94>/Switch1' : Unused code path elimination
 * Block '<S94>/offset2' : Unused code path elimination
 * Block '<S94>/offset3' : Unused code path elimination
 * Block '<S94>/offset4' : Unused code path elimination
 * Block '<S95>/Add3' : Unused code path elimination
 * Block '<S95>/Add4' : Unused code path elimination
 * Block '<S95>/Constant' : Unused code path elimination
 * Block '<S95>/Relational Operator' : Unused code path elimination
 * Block '<S95>/Switch1' : Unused code path elimination
 * Block '<S95>/offset2' : Unused code path elimination
 * Block '<S95>/offset3' : Unused code path elimination
 * Block '<S95>/offset4' : Unused code path elimination
 * Block '<S96>/Add3' : Unused code path elimination
 * Block '<S96>/Add4' : Unused code path elimination
 * Block '<S96>/Constant' : Unused code path elimination
 * Block '<S96>/Relational Operator' : Unused code path elimination
 * Block '<S96>/Switch1' : Unused code path elimination
 * Block '<S96>/offset2' : Unused code path elimination
 * Block '<S96>/offset3' : Unused code path elimination
 * Block '<S96>/offset4' : Unused code path elimination
 * Block '<S97>/Add3' : Unused code path elimination
 * Block '<S97>/Add4' : Unused code path elimination
 * Block '<S97>/Constant' : Unused code path elimination
 * Block '<S97>/Relational Operator' : Unused code path elimination
 * Block '<S97>/Switch1' : Unused code path elimination
 * Block '<S97>/offset2' : Unused code path elimination
 * Block '<S97>/offset3' : Unused code path elimination
 * Block '<S97>/offset4' : Unused code path elimination
 * Block '<S98>/Add3' : Unused code path elimination
 * Block '<S98>/Add4' : Unused code path elimination
 * Block '<S98>/Constant' : Unused code path elimination
 * Block '<S98>/Relational Operator' : Unused code path elimination
 * Block '<S98>/Switch1' : Unused code path elimination
 * Block '<S98>/offset2' : Unused code path elimination
 * Block '<S98>/offset3' : Unused code path elimination
 * Block '<S98>/offset4' : Unused code path elimination
 * Block '<S99>/Add3' : Unused code path elimination
 * Block '<S99>/Add4' : Unused code path elimination
 * Block '<S99>/Constant' : Unused code path elimination
 * Block '<S99>/Relational Operator' : Unused code path elimination
 * Block '<S99>/Switch1' : Unused code path elimination
 * Block '<S99>/offset2' : Unused code path elimination
 * Block '<S99>/offset3' : Unused code path elimination
 * Block '<S99>/offset4' : Unused code path elimination
 * Block '<S100>/Add3' : Unused code path elimination
 * Block '<S100>/Add4' : Unused code path elimination
 * Block '<S100>/Constant' : Unused code path elimination
 * Block '<S100>/Relational Operator' : Unused code path elimination
 * Block '<S100>/Switch1' : Unused code path elimination
 * Block '<S100>/offset2' : Unused code path elimination
 * Block '<S100>/offset3' : Unused code path elimination
 * Block '<S100>/offset4' : Unused code path elimination
 * Block '<S101>/Add3' : Unused code path elimination
 * Block '<S101>/Add4' : Unused code path elimination
 * Block '<S101>/Constant' : Unused code path elimination
 * Block '<S101>/Relational Operator' : Unused code path elimination
 * Block '<S101>/Switch1' : Unused code path elimination
 * Block '<S101>/offset2' : Unused code path elimination
 * Block '<S101>/offset3' : Unused code path elimination
 * Block '<S101>/offset4' : Unused code path elimination
 * Block '<S106>/Add3' : Unused code path elimination
 * Block '<S106>/Add4' : Unused code path elimination
 * Block '<S106>/Constant' : Unused code path elimination
 * Block '<S106>/Relational Operator' : Unused code path elimination
 * Block '<S106>/Switch1' : Unused code path elimination
 * Block '<S106>/offset2' : Unused code path elimination
 * Block '<S106>/offset3' : Unused code path elimination
 * Block '<S106>/offset4' : Unused code path elimination
 * Block '<S107>/Add3' : Unused code path elimination
 * Block '<S107>/Add4' : Unused code path elimination
 * Block '<S107>/Constant' : Unused code path elimination
 * Block '<S107>/Relational Operator' : Unused code path elimination
 * Block '<S107>/Switch1' : Unused code path elimination
 * Block '<S107>/offset2' : Unused code path elimination
 * Block '<S107>/offset3' : Unused code path elimination
 * Block '<S107>/offset4' : Unused code path elimination
 * Block '<S108>/Add3' : Unused code path elimination
 * Block '<S108>/Add4' : Unused code path elimination
 * Block '<S108>/Constant' : Unused code path elimination
 * Block '<S108>/Relational Operator' : Unused code path elimination
 * Block '<S108>/Switch1' : Unused code path elimination
 * Block '<S108>/offset2' : Unused code path elimination
 * Block '<S108>/offset3' : Unused code path elimination
 * Block '<S108>/offset4' : Unused code path elimination
 * Block '<S109>/Add3' : Unused code path elimination
 * Block '<S109>/Add4' : Unused code path elimination
 * Block '<S109>/Constant' : Unused code path elimination
 * Block '<S109>/Relational Operator' : Unused code path elimination
 * Block '<S109>/Switch1' : Unused code path elimination
 * Block '<S109>/offset2' : Unused code path elimination
 * Block '<S109>/offset3' : Unused code path elimination
 * Block '<S109>/offset4' : Unused code path elimination
 * Block '<S110>/Add3' : Unused code path elimination
 * Block '<S110>/Add4' : Unused code path elimination
 * Block '<S110>/Constant' : Unused code path elimination
 * Block '<S110>/Relational Operator' : Unused code path elimination
 * Block '<S110>/Switch1' : Unused code path elimination
 * Block '<S110>/offset2' : Unused code path elimination
 * Block '<S110>/offset3' : Unused code path elimination
 * Block '<S110>/offset4' : Unused code path elimination
 * Block '<S111>/Add3' : Unused code path elimination
 * Block '<S111>/Add4' : Unused code path elimination
 * Block '<S111>/Constant' : Unused code path elimination
 * Block '<S111>/Relational Operator' : Unused code path elimination
 * Block '<S111>/Switch1' : Unused code path elimination
 * Block '<S111>/offset2' : Unused code path elimination
 * Block '<S111>/offset3' : Unused code path elimination
 * Block '<S111>/offset4' : Unused code path elimination
 * Block '<S112>/Add3' : Unused code path elimination
 * Block '<S112>/Add4' : Unused code path elimination
 * Block '<S112>/Constant' : Unused code path elimination
 * Block '<S112>/Relational Operator' : Unused code path elimination
 * Block '<S112>/Switch1' : Unused code path elimination
 * Block '<S112>/offset2' : Unused code path elimination
 * Block '<S112>/offset3' : Unused code path elimination
 * Block '<S112>/offset4' : Unused code path elimination
 * Block '<S113>/Add3' : Unused code path elimination
 * Block '<S113>/Add4' : Unused code path elimination
 * Block '<S113>/Constant' : Unused code path elimination
 * Block '<S113>/Relational Operator' : Unused code path elimination
 * Block '<S113>/Switch1' : Unused code path elimination
 * Block '<S113>/offset2' : Unused code path elimination
 * Block '<S113>/offset3' : Unused code path elimination
 * Block '<S113>/offset4' : Unused code path elimination
 * Block '<S114>/Add3' : Unused code path elimination
 * Block '<S114>/Add4' : Unused code path elimination
 * Block '<S114>/Constant' : Unused code path elimination
 * Block '<S114>/Relational Operator' : Unused code path elimination
 * Block '<S114>/Switch1' : Unused code path elimination
 * Block '<S114>/offset2' : Unused code path elimination
 * Block '<S114>/offset3' : Unused code path elimination
 * Block '<S114>/offset4' : Unused code path elimination
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
 * hilite_system('AdvCordT_AUTOSAR/AdvCordT')    - opens subsystem AdvCordT_AUTOSAR/AdvCordT
 * hilite_system('AdvCordT_AUTOSAR/AdvCordT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AdvCordT_AUTOSAR
 * '<S1>'   : AdvCordT_AUTOSAR/AdvCordT
 * '<S7>'   : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init
 * '<S8>'   : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap
 * '<S9>'   : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap
 * '<S10>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig
 * '<S11>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running
 * '<S12>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout1
 * '<S13>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout10
 * '<S14>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout11
 * '<S15>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout14
 * '<S16>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout15
 * '<S17>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout3
 * '<S18>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout4
 * '<S19>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout5
 * '<S20>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout6
 * '<S21>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout7
 * '<S22>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout8
 * '<S23>'  : AdvCordT_AUTOSAR/AdvCordT/F01_AdvCordT_Init/Convertout9
 * '<S24>'  : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap/Convertout1
 * '<S25>'  : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap/Convertout2
 * '<S26>'  : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap/Convertout20
 * '<S27>'  : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap/Convertout21
 * '<S28>'  : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap/Convertout22
 * '<S29>'  : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap/Convertout23
 * '<S30>'  : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap/Convertout24
 * '<S31>'  : AdvCordT_AUTOSAR/AdvCordT/F01_IgAdvMap/Convertout3
 * '<S32>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/Convertout1
 * '<S33>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/Convertout2
 * '<S34>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/Convertout20
 * '<S35>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/Convertout21
 * '<S36>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/Convertout22
 * '<S37>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/Convertout23
 * '<S38>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/Convertout24
 * '<S39>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/Convertout3
 * '<S40>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/F01_Calcul_avance_MAP
 * '<S41>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/F02_Calcul_avance_MAP_Default
 * '<S42>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/F01_Calcul_avance_MAP/LookUp_2D
 * '<S43>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/F01_Calcul_avance_MAP/SingleToFixdt
 * '<S44>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/F01_Calcul_avance_MAP/SingleToFixdt1
 * '<S45>'  : AdvCordT_AUTOSAR/AdvCordT/F02_IgAdvMap/F01_Calcul_avance_MAP/division_411
 * '<S46>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/Convertout1
 * '<S47>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/Convertout11
 * '<S48>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/Convertout2
 * '<S49>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/Convertout3
 * '<S50>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/Convertout4
 * '<S51>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/Convertout5
 * '<S52>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis
 * '<S53>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F02_Avance_maxi
 * '<S54>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/SingleToFixdt1
 * '<S55>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/SingleToFixdt3
 * '<S56>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/SingleToFixdt4
 * '<S57>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/One_Based_Selector
 * '<S58>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/SingleToFixdt
 * '<S59>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/SingleToFixdt1
 * '<S60>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/SingleToFixdt2
 * '<S61>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/SingleToFixdt3
 * '<S62>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/SingleToFixdt4
 * '<S63>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/division_421
 * '<S64>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/multiplication_1
 * '<S65>'  : AdvCordT_AUTOSAR/AdvCordT/F03_coordination_Avance_maxi_trig/F01_Limite_cliquetis/multiplication_431
 * '<S66>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/Convertout1
 * '<S67>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/Convertout2
 * '<S68>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/Convertout3
 * '<S69>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/Convertout4
 * '<S70>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/Convertout5
 * '<S71>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/Convertout6
 * '<S72>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F01_Init_decalage_avance
 * '<S73>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F02_Decalage_avance
 * '<S74>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable
 * '<S75>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Decalage_avance_default
 * '<S76>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F04_Vecteur_avance
 * '<S77>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/UnitDelay1
 * '<S78>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F01_Init_decalage_avance/SingleToFixdt
 * '<S79>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F02_Decalage_avance/F01_Compute_decalage
 * '<S80>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F02_Decalage_avance/F02_Compute_decalage
 * '<S81>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F02_Decalage_avance/F03_Compute_decalage_default
 * '<S82>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F02_Decalage_avance/F02_Compute_decalage/SingleToFixdt
 * '<S83>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F02_Decalage_avance/F02_Compute_decalage/UnitDelay1
 * '<S84>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale
 * '<S85>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next
 * '<S86>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/One_Based_Selector
 * '<S87>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/One_Based_Selector1
 * '<S88>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/One_Based_Selector2
 * '<S89>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt
 * '<S90>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt1
 * '<S91>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt10
 * '<S92>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt11
 * '<S93>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt12
 * '<S94>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt13
 * '<S95>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt2
 * '<S96>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt3
 * '<S97>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt4
 * '<S98>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt5
 * '<S99>'  : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt6
 * '<S100>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt8
 * '<S101>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/SingleToFixdt9
 * '<S102>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F01_Calc_avance_finale/UnitDelay2
 * '<S103>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/One_Based_Selector
 * '<S104>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/One_Based_Selector1
 * '<S105>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/One_Based_Selector2
 * '<S106>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt
 * '<S107>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt1
 * '<S108>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt10
 * '<S109>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt2
 * '<S110>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt3
 * '<S111>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt4
 * '<S112>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt5
 * '<S113>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt7
 * '<S114>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/SingleToFixdt9
 * '<S115>' : AdvCordT_AUTOSAR/AdvCordT/F04_Calcul_avance_running/F03_Calcul_avance_running_enable/F02_Calc_avance_finale_next/UnitDelay3
 */

/*-
 * Requirements for '<Root>': AdvCordT
 *
 * Inherited requirements for '<S1>/F01_AdvCordT_Init':
 *  1. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_004.02 ;
 *  2. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_005.02 ;
 *  3. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_009.02 ;
 *  4. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_023.02 ;
 *  5. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_024.02 ;
 *  6. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_025.02 ;
 *  7. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_027.02 ;
 *  8. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_028.02 ;
 *  9. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_046.02 ;
 *  10. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_047.02 ;
 *  11. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_048.02 ;
 *  12. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_049.01 ;
 *  13. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_051.02 ;
 *  14. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_060.02 ;
 *  15. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_067.02 ;
 *  16. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_071.01 ;
 *  17. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_050.03 ;
 *
 * Inherited requirements for '<S1>/F01_IgAdvMap':
 *  1. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_069.01 ;
 *  2. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_052.03 ;
 *  3. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_053.02 ;
 *  4. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_054.02 ;
 *  5. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_055.02 ;
 *  6. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_056.02 ;
 *  7. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_057.02 ;
 *  8. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_058.02 ;
 *  9. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_059.02 ;
 *
 * Inherited requirements for '<S1>/F02_IgAdvMap':
 *  1. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_001.01 ;
 *  2. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_070.02 ;
 *  3. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_018.02 ;
 *  4. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_019.01 ;
 *  5. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_020.01 ;
 *  6. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_022.01 ;
 *  7. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_052.03 ;
 *  8. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_053.02 ;
 *  9. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_054.02 ;
 *  10. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_055.02 ;
 *  11. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_056.02 ;
 *  12. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_057.02 ;
 *  13. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_058.02 ;
 *  14. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_059.02 ;
 *  15. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_002.01 ;
 *
 * Inherited requirements for '<S1>/F03_coordination_Avance_maxi_trig':
 *  1. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_073.02 ;
 *  2. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_004.02 ;
 *  3. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_005.02 ;
 *  4. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_006.02 ;
 *  5. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_032.01 ;
 *  6. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_037.01 ;
 *  7. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_039.01 ;
 *  8. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_043.01 ;
 *  9. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_044.01 ;
 *  10. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_045.02 ;
 *  11. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_067.02 ;
 *  12. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_024.02 ;
 *  13. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_025.02 ;
 *  14. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_027.02 ;
 *  15. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_028.02 ;
 *  16. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_050.03 ;
 *  17. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_075.01 ;
 *
 * Inherited requirements for '<S1>/F04_Calcul_avance_running':
 *  1. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_004.02 ;
 *  2. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_005.02 ;
 *  3. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_010.02 ;
 *  4. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_072.02 ;
 *  5. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_029.01 ;
 *  6. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_030.01 ;
 *  7. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_031.01 ;
 *  8. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_032.01 ;
 *  9. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_033.01 ;
 *  10. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_034.01 ;
 *  11. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_038.01 ;
 *  12. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_040.01 ;
 *  13. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_041.01 ;
 *  14. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_042.01 ;
 *  15. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_022.01 ;
 *  16. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_044.01 ;
 *  17. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_045.02 ;
 *  18. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_067.01 ;
 *  19. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_060.01 ;
 *  20. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_053.02 ;
 *  21. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_054.02 ;
 *  22. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_055.02 ;
 *  23. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_056.02 ;
 *  24. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_057.02 ;
 *  25. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_058.02 ;
 *  26. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_059.02 ;
 *  27. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_023.02 ;
 *  28. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_046.02 ;
 *  29. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_047.02 ;
 *  30. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_048.02 ;
 *  31. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_051.02 ;
 *  32. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_060.01 ;
 *  33. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_026.02 ;
 *  34. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_074.01 ;
 *  35. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_075.01 ;

 */
#endif                                 /* RTW_HEADER_AdvCordT_h_ */

/*-------------------------------- end of file -------------------------------*/
