/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMinT                                                 */
/* !Description     : AdvMinT Software Component                              */
/*                                                                            */
/* !Module          : AdvMinT                                                 */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : AdvMinT.h                                               */
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
/*   Model name       : AdvMinT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMinT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M02-AdvMinT/5-S$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   23 Oct 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvMinT_h_
#define RTW_HEADER_AdvMinT_h_
#ifndef AdvMinT_COMMON_INCLUDES_
# define AdvMinT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AdvMinT.h"
#include "AdvMinT_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_CeilF.h"
#include "ACTEMS_FabsF.h"
#include "ACTEMS_FloorF.h"
#include "rt_MAX.h"
#include "rt_MAXf.h"
#include "rt_MINf.h"
#include "rt_rem32.h"
#endif                                 /* AdvMinT_COMMON_INCLUDES_ */

#include "AdvMinT_types.h"

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
  SInt16 TmpSignalConversionAtExt_tCoStr;
  UInt16 TmpSignalConversionAtExt_nEngOu;
  UInt16 TmpSignalConversionAtEngM_rAirL;
  UInt8 Merge2;                      /* '<S7>/Merge2' */
} BlockIO_AdvMinT;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S85>/Unit Delay' */
  Float32 UnitDelay_DSTATE_e;         /* '<S82>/Unit Delay' */
  Float32 UnitDelay_DSTATE_i;         /* '<S79>/Unit Delay' */
  Float32 UnitDelay_DSTATE_n;         /* '<S76>/Unit Delay' */
  Float32 UnitDelay_DSTATE_h[5];      /* '<S39>/Unit Delay' */
  Float32 UnitDelay_DSTATE_eb[5];     /* '<S38>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_ih;         /* '<S46>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S19>/UnitDelay' */
  Boolean UnitDelay_l;               /* '<S19>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_m[5];     /* '<S66>/Unit Delay' */
  Boolean UnitDelay_DSTATE_ej;       /* '<S65>/Unit Delay' */
  Boolean UnitDelay1_DSTATE[5];      /* '<S39>/Unit Delay1' */
  Boolean UnitDelay_DSTATE_f;        /* '<S48>/Unit Delay' */
  Boolean UnitDelay1_DSTATE_n;       /* '<S38>/Unit Delay1' */
  UInt8 is_active_c2_AdvMinT;        /* '<S18>/F01_State_avmin' */
  UInt8 is_c2_AdvMinT;               /* '<S18>/F01_State_avmin' */
  UInt8 UnitDelay_DSTATE_a;          /* '<S41>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_o;          /* '<S42>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_k;          /* '<S40>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_k4;         /* '<S43>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_mx;         /* '<S44>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_b;          /* '<S45>/Unit Delay' */
} D_Work_AdvMinT;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S117>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxInde[2];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S19>/Logic'
   */
  Boolean Logic_table[16];
} ConstParam_AdvMinT;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define AdvMinT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMinT_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_AdvMinT AdvMinT_B;

/* Block states (auto storage) */
extern D_Work_AdvMinT AdvMinT_DWork;




#define AdvMinT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMinT_MemMap.h"
#define AdvMinT_START_SEC_CODE
#include "AdvMinT_MemMap.h"

extern void RE_AdvMinT_Init(void);
/* Model entry point functions */
extern void RE_AdvMinT_002_DRE(void);
extern void RE_AdvMinT_001_MSE(void);
extern void RE_AdvMinT_008_DRE(void);
extern void RE_AdvMinT_006_DRE(void);
extern void RE_AdvMinT_005_MSE(void);

#define AdvMinT_STOP_SEC_CODE
#include "AdvMinT_MemMap.h"

#define AdvMinT_START_SEC_CONST_UNSPECIFIED
#include "AdvMinT_MemMap.h"

/* Constant parameters (auto storage) */
extern const ConstParam_AdvMinT AdvMinT_ConstP;

#define AdvMinT_STOP_SEC_CONST_UNSPECIFIED
#include "AdvMinT_MemMap.h"

#define AdvMinT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMinT_MemMap.h"

/* Model init function */


#define AdvMinT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMinT_MemMap.h"

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
 * Block '<S19>/LO3' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S33>/x' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S34>/x' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S35>/x' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/x' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Relational Operator' : Unused code path elimination
 * Block '<S49>/Relational Operator1' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Propagation' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Relational Operator' : Unused code path elimination
 * Block '<S50>/Relational Operator1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Propagation' : Unused code path elimination
 * Block '<S38>/Constant4' : Unused code path elimination
 * Block '<S38>/Switch1' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Relational Operator' : Unused code path elimination
 * Block '<S57>/Relational Operator1' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Propagation' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Relational Operator' : Unused code path elimination
 * Block '<S58>/Relational Operator1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Propagation' : Unused code path elimination
 * Block '<S47>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S74>/x1' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S96>/x1' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S117>/x1' : Unused code path elimination
 * Block '<S117>/x2' : Unused code path elimination
 * Block '<S143>/Data Type Duplicate' : Unused code path elimination
 * Block '<S144>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Relational Operator' : Unused code path elimination
 * Block '<S131>/Relational Operator1' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate' : Unused code path elimination
 * Block '<S145>/Data Type Propagation' : Unused code path elimination
 * Block '<S146>/Data Type Duplicate' : Unused code path elimination
 * Block '<S147>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Relational Operator' : Unused code path elimination
 * Block '<S132>/Relational Operator1' : Unused code path elimination
 * Block '<S148>/Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/Data Type Propagation' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S134>/x1' : Unused code path elimination
 * Block '<S135>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S135>/x1' : Unused code path elimination
 * Block '<S165>/Data Type Duplicate' : Unused code path elimination
 * Block '<S166>/Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/Relational Operator' : Unused code path elimination
 * Block '<S153>/Relational Operator1' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Propagation' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S154>/Relational Operator' : Unused code path elimination
 * Block '<S154>/Relational Operator1' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Propagation' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S156>/x1' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S157>/x1' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Relational Operator' : Unused code path elimination
 * Block '<S182>/Relational Operator1' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Propagation' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S180>/x1' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Relational Operator' : Unused code path elimination
 * Block '<S191>/Relational Operator1' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Propagation' : Unused code path elimination
 * Block '<S196>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S195>/Relational Operator' : Unused code path elimination
 * Block '<S195>/Relational Operator1' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Propagation' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S211>/Relational Operator' : Unused code path elimination
 * Block '<S211>/Relational Operator1' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Data Type Propagation' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate' : Unused code path elimination
 * Block '<S215>/Relational Operator' : Unused code path elimination
 * Block '<S215>/Relational Operator1' : Unused code path elimination
 * Block '<S218>/Data Type Duplicate' : Unused code path elimination
 * Block '<S218>/Data Type Propagation' : Unused code path elimination
 * Block '<S207>/Data Type Duplicate' : Unused code path elimination
 * Block '<S208>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S104>/x' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S105>/x' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S106>/x' : Unused code path elimination
 * Block '<S37>/Switch' : Eliminated due to constant selection input
 * Block '<S51>/Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Switch2' : Eliminated due to constant selection input
 * Block '<S59>/Conversion' : Eliminate redundant data type conversion
 * Block '<S60>/Conversion' : Eliminate redundant data type conversion
 * Block '<S62>/Conversion' : Eliminate redundant data type conversion
 * Block '<S63>/Conversion' : Eliminate redundant data type conversion
 * Block '<S39>/Switch1' : Eliminated due to constant selection input
 * Block '<S39>/Switch2' : Eliminated due to constant selection input
 * Block '<S75>/Switch' : Eliminated due to constant selection input
 * Block '<S78>/Switch' : Eliminated due to constant selection input
 * Block '<S81>/Switch' : Eliminated due to constant selection input
 * Block '<S84>/Switch' : Eliminated due to constant selection input
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S88>/copy' : Eliminate redundant signal conversion block
 * Block '<S89>/copy' : Eliminate redundant signal conversion block
 * Block '<S90>/copy' : Eliminate redundant signal conversion block
 * Block '<S91>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S92>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S93>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S94>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S95>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S97>/Switch' : Eliminated due to constant selection input
 * Block '<S98>/copy' : Eliminate redundant signal conversion block
 * Block '<S118>/Switch' : Eliminated due to constant selection input
 * Block '<S124>/Switch' : Eliminated due to constant selection input
 * Block '<S125>/Switch' : Eliminated due to constant selection input
 * Block '<S143>/Conversion' : Eliminate redundant data type conversion
 * Block '<S144>/Conversion' : Eliminate redundant data type conversion
 * Block '<S146>/Conversion' : Eliminate redundant data type conversion
 * Block '<S147>/Conversion' : Eliminate redundant data type conversion
 * Block '<S136>/Switch' : Eliminated due to constant selection input
 * Block '<S137>/Switch' : Eliminated due to constant selection input
 * Block '<S138>/Switch' : Eliminated due to constant selection input
 * Block '<S139>/Switch' : Eliminated due to constant selection input
 * Block '<S165>/Conversion' : Eliminate redundant data type conversion
 * Block '<S166>/Conversion' : Eliminate redundant data type conversion
 * Block '<S168>/Conversion' : Eliminate redundant data type conversion
 * Block '<S169>/Conversion' : Eliminate redundant data type conversion
 * Block '<S158>/Switch' : Eliminated due to constant selection input
 * Block '<S159>/Switch' : Eliminated due to constant selection input
 * Block '<S160>/Switch' : Eliminated due to constant selection input
 * Block '<S161>/Switch' : Eliminated due to constant selection input
 * Block '<S176>/Switch' : Eliminated due to constant selection input
 * Block '<S183>/Conversion' : Eliminate redundant data type conversion
 * Block '<S184>/Conversion' : Eliminate redundant data type conversion
 * Block '<S181>/Switch' : Eliminated due to constant selection input
 * Block '<S192>/Conversion' : Eliminate redundant data type conversion
 * Block '<S193>/Conversion' : Eliminate redundant data type conversion
 * Block '<S196>/Conversion' : Eliminate redundant data type conversion
 * Block '<S197>/Conversion' : Eliminate redundant data type conversion
 * Block '<S190>/Switch' : Eliminated due to constant selection input
 * Block '<S201>/Switch' : Eliminated due to constant selection input
 * Block '<S202>/Switch' : Eliminated due to constant selection input
 * Block '<S203>/Switch' : Eliminated due to constant selection input
 * Block '<S212>/Conversion' : Eliminate redundant data type conversion
 * Block '<S213>/Conversion' : Eliminate redundant data type conversion
 * Block '<S216>/Conversion' : Eliminate redundant data type conversion
 * Block '<S217>/Conversion' : Eliminate redundant data type conversion
 * Block '<S209>/Switch' : Eliminated due to constant selection input
 * Block '<S210>/Switch' : Eliminated due to constant selection input
 * Block '<S107>/Switch' : Eliminated due to constant selection input
 * Block '<S113>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S114>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S37>/Add3' : Unused code path elimination
 * Block '<S37>/Add4' : Unused code path elimination
 * Block '<S37>/Constant' : Unused code path elimination
 * Block '<S37>/Relational Operator' : Unused code path elimination
 * Block '<S37>/Switch1' : Unused code path elimination
 * Block '<S37>/offset2' : Unused code path elimination
 * Block '<S37>/offset3' : Unused code path elimination
 * Block '<S37>/offset4' : Unused code path elimination
 * Block '<S38>/Constant3' : Unused code path elimination
 * Block '<S39>/Constant3' : Unused code path elimination
 * Block '<S39>/Constant4' : Unused code path elimination
 * Block '<S75>/Add3' : Unused code path elimination
 * Block '<S75>/Add4' : Unused code path elimination
 * Block '<S75>/Constant' : Unused code path elimination
 * Block '<S75>/Relational Operator' : Unused code path elimination
 * Block '<S75>/Switch1' : Unused code path elimination
 * Block '<S75>/offset2' : Unused code path elimination
 * Block '<S75>/offset3' : Unused code path elimination
 * Block '<S75>/offset4' : Unused code path elimination
 * Block '<S78>/Add3' : Unused code path elimination
 * Block '<S78>/Add4' : Unused code path elimination
 * Block '<S78>/Constant' : Unused code path elimination
 * Block '<S78>/Relational Operator' : Unused code path elimination
 * Block '<S78>/Switch1' : Unused code path elimination
 * Block '<S78>/offset2' : Unused code path elimination
 * Block '<S78>/offset3' : Unused code path elimination
 * Block '<S78>/offset4' : Unused code path elimination
 * Block '<S81>/Add3' : Unused code path elimination
 * Block '<S81>/Add4' : Unused code path elimination
 * Block '<S81>/Constant' : Unused code path elimination
 * Block '<S81>/Relational Operator' : Unused code path elimination
 * Block '<S81>/Switch1' : Unused code path elimination
 * Block '<S81>/offset2' : Unused code path elimination
 * Block '<S81>/offset3' : Unused code path elimination
 * Block '<S81>/offset4' : Unused code path elimination
 * Block '<S84>/Add3' : Unused code path elimination
 * Block '<S84>/Add4' : Unused code path elimination
 * Block '<S84>/Constant' : Unused code path elimination
 * Block '<S84>/Relational Operator' : Unused code path elimination
 * Block '<S84>/Switch1' : Unused code path elimination
 * Block '<S84>/offset2' : Unused code path elimination
 * Block '<S84>/offset3' : Unused code path elimination
 * Block '<S84>/offset4' : Unused code path elimination
 * Block '<S97>/Add3' : Unused code path elimination
 * Block '<S97>/Add4' : Unused code path elimination
 * Block '<S97>/Constant' : Unused code path elimination
 * Block '<S97>/Relational Operator' : Unused code path elimination
 * Block '<S97>/Switch1' : Unused code path elimination
 * Block '<S97>/offset2' : Unused code path elimination
 * Block '<S97>/offset3' : Unused code path elimination
 * Block '<S97>/offset4' : Unused code path elimination
 * Block '<S118>/Add3' : Unused code path elimination
 * Block '<S118>/Add4' : Unused code path elimination
 * Block '<S118>/Constant' : Unused code path elimination
 * Block '<S118>/Relational Operator' : Unused code path elimination
 * Block '<S118>/Switch1' : Unused code path elimination
 * Block '<S118>/offset2' : Unused code path elimination
 * Block '<S118>/offset3' : Unused code path elimination
 * Block '<S118>/offset4' : Unused code path elimination
 * Block '<S124>/Add2' : Unused code path elimination
 * Block '<S124>/Constant' : Unused code path elimination
 * Block '<S124>/offset1' : Unused code path elimination
 * Block '<S125>/Add2' : Unused code path elimination
 * Block '<S125>/Constant' : Unused code path elimination
 * Block '<S125>/offset1' : Unused code path elimination
 * Block '<S136>/Add3' : Unused code path elimination
 * Block '<S136>/Add4' : Unused code path elimination
 * Block '<S136>/Constant' : Unused code path elimination
 * Block '<S136>/Relational Operator' : Unused code path elimination
 * Block '<S136>/Switch1' : Unused code path elimination
 * Block '<S136>/offset2' : Unused code path elimination
 * Block '<S136>/offset3' : Unused code path elimination
 * Block '<S136>/offset4' : Unused code path elimination
 * Block '<S137>/Add2' : Unused code path elimination
 * Block '<S137>/Constant' : Unused code path elimination
 * Block '<S137>/offset1' : Unused code path elimination
 * Block '<S138>/Add3' : Unused code path elimination
 * Block '<S138>/Add4' : Unused code path elimination
 * Block '<S138>/Constant' : Unused code path elimination
 * Block '<S138>/Relational Operator' : Unused code path elimination
 * Block '<S138>/Switch1' : Unused code path elimination
 * Block '<S138>/offset2' : Unused code path elimination
 * Block '<S138>/offset3' : Unused code path elimination
 * Block '<S138>/offset4' : Unused code path elimination
 * Block '<S139>/Add2' : Unused code path elimination
 * Block '<S139>/Constant' : Unused code path elimination
 * Block '<S139>/offset1' : Unused code path elimination
 * Block '<S158>/Add2' : Unused code path elimination
 * Block '<S158>/Constant' : Unused code path elimination
 * Block '<S158>/offset1' : Unused code path elimination
 * Block '<S159>/Add2' : Unused code path elimination
 * Block '<S159>/Constant' : Unused code path elimination
 * Block '<S159>/offset1' : Unused code path elimination
 * Block '<S160>/Add3' : Unused code path elimination
 * Block '<S160>/Add4' : Unused code path elimination
 * Block '<S160>/Constant' : Unused code path elimination
 * Block '<S160>/Relational Operator' : Unused code path elimination
 * Block '<S160>/Switch1' : Unused code path elimination
 * Block '<S160>/offset2' : Unused code path elimination
 * Block '<S160>/offset3' : Unused code path elimination
 * Block '<S160>/offset4' : Unused code path elimination
 * Block '<S161>/Add3' : Unused code path elimination
 * Block '<S161>/Add4' : Unused code path elimination
 * Block '<S161>/Constant' : Unused code path elimination
 * Block '<S161>/Relational Operator' : Unused code path elimination
 * Block '<S161>/Switch1' : Unused code path elimination
 * Block '<S161>/offset2' : Unused code path elimination
 * Block '<S161>/offset3' : Unused code path elimination
 * Block '<S161>/offset4' : Unused code path elimination
 * Block '<S176>/Add2' : Unused code path elimination
 * Block '<S176>/Constant' : Unused code path elimination
 * Block '<S176>/offset1' : Unused code path elimination
 * Block '<S181>/Add3' : Unused code path elimination
 * Block '<S181>/Add4' : Unused code path elimination
 * Block '<S181>/Constant' : Unused code path elimination
 * Block '<S181>/Relational Operator' : Unused code path elimination
 * Block '<S181>/Switch1' : Unused code path elimination
 * Block '<S181>/offset2' : Unused code path elimination
 * Block '<S181>/offset3' : Unused code path elimination
 * Block '<S181>/offset4' : Unused code path elimination
 * Block '<S190>/Add2' : Unused code path elimination
 * Block '<S190>/Constant' : Unused code path elimination
 * Block '<S190>/offset1' : Unused code path elimination
 * Block '<S201>/Add3' : Unused code path elimination
 * Block '<S201>/Add4' : Unused code path elimination
 * Block '<S201>/Constant' : Unused code path elimination
 * Block '<S201>/Relational Operator' : Unused code path elimination
 * Block '<S201>/Switch1' : Unused code path elimination
 * Block '<S201>/offset2' : Unused code path elimination
 * Block '<S201>/offset3' : Unused code path elimination
 * Block '<S201>/offset4' : Unused code path elimination
 * Block '<S202>/Add2' : Unused code path elimination
 * Block '<S202>/Constant' : Unused code path elimination
 * Block '<S202>/offset1' : Unused code path elimination
 * Block '<S203>/Add3' : Unused code path elimination
 * Block '<S203>/Add4' : Unused code path elimination
 * Block '<S203>/Constant' : Unused code path elimination
 * Block '<S203>/Relational Operator' : Unused code path elimination
 * Block '<S203>/Switch1' : Unused code path elimination
 * Block '<S203>/offset2' : Unused code path elimination
 * Block '<S203>/offset3' : Unused code path elimination
 * Block '<S203>/offset4' : Unused code path elimination
 * Block '<S209>/Add2' : Unused code path elimination
 * Block '<S209>/Constant' : Unused code path elimination
 * Block '<S209>/offset1' : Unused code path elimination
 * Block '<S210>/Add3' : Unused code path elimination
 * Block '<S210>/Add4' : Unused code path elimination
 * Block '<S210>/Constant' : Unused code path elimination
 * Block '<S210>/Relational Operator' : Unused code path elimination
 * Block '<S210>/Switch1' : Unused code path elimination
 * Block '<S210>/offset2' : Unused code path elimination
 * Block '<S210>/offset3' : Unused code path elimination
 * Block '<S210>/offset4' : Unused code path elimination
 * Block '<S107>/Add3' : Unused code path elimination
 * Block '<S107>/Add4' : Unused code path elimination
 * Block '<S107>/Constant' : Unused code path elimination
 * Block '<S107>/Relational Operator' : Unused code path elimination
 * Block '<S107>/Switch1' : Unused code path elimination
 * Block '<S107>/offset2' : Unused code path elimination
 * Block '<S107>/offset3' : Unused code path elimination
 * Block '<S107>/offset4' : Unused code path elimination
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
 * hilite_system('AdvMinT_AUTOSAR/AdvMinT')    - opens subsystem AdvMinT_AUTOSAR/AdvMinT
 * hilite_system('AdvMinT_AUTOSAR/AdvMinT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AdvMinT_AUTOSAR
 * '<S1>'   : AdvMinT_AUTOSAR/AdvMinT
 * '<S7>'   : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr
 * '<S8>'   : AdvMinT_AUTOSAR/AdvMinT/F01_Init
 * '<S9>'   : AdvMinT_AUTOSAR/AdvMinT/F01_Init1
 * '<S10>'  : AdvMinT_AUTOSAR/AdvMinT/F02_Init_delay
 * '<S11>'  : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini
 * '<S12>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F01_Condition_d_activation
 * '<S13>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination
 * '<S14>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_NOT
 * '<S15>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/convertout
 * '<S16>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr
 * '<S17>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes
 * '<S18>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F03_Choix_avance
 * '<S19>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/BasculeRS
 * '<S20>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Falling_edge
 * '<S21>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D1
 * '<S22>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D10
 * '<S23>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D11
 * '<S24>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D12
 * '<S25>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D2
 * '<S26>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D3
 * '<S27>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D4
 * '<S28>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D5
 * '<S29>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D6
 * '<S30>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D7
 * '<S31>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D8
 * '<S32>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Interp_2D9
 * '<S33>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/PreLookUp_Binary
 * '<S34>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/PreLookUp_Binary1
 * '<S35>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/PreLookUp_Binary2
 * '<S36>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/PreLookUp_Binary3
 * '<S37>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/SingleToFixdt
 * '<S38>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1
 * '<S39>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2
 * '<S40>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDelay1
 * '<S41>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDelay2
 * '<S42>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDelay3
 * '<S43>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDelay4
 * '<S44>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDelay5
 * '<S45>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDelay6
 * '<S46>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDelay7
 * '<S47>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDly_ExtIni1
 * '<S48>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/Falling_edge/SubSystem
 * '<S49>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1/Clamp2
 * '<S50>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1/Clamp3
 * '<S51>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1/Clamp2/Data Type Conversion Inherited
 * '<S52>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1/Clamp2/Data Type Conversion Inherited1
 * '<S53>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1/Clamp2/Saturation Dynamic
 * '<S54>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1/Clamp3/Data Type Conversion Inherited
 * '<S55>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1/Clamp3/Data Type Conversion Inherited1
 * '<S56>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst1/Clamp3/Saturation Dynamic
 * '<S57>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2/Clamp2
 * '<S58>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2/Clamp3
 * '<S59>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2/Clamp2/Data Type Conversion Inherited
 * '<S60>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2/Clamp2/Data Type Conversion Inherited1
 * '<S61>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2/Clamp2/Saturation Dynamic
 * '<S62>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2/Clamp3/Data Type Conversion Inherited
 * '<S63>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2/Clamp3/Data Type Conversion Inherited1
 * '<S64>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/TmrRst2/Clamp3/Saturation Dynamic
 * '<S65>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDly_ExtIni1/SubSystem1
 * '<S66>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F01_Tempo_agr/UnitDly_ExtIni1/SubSystem2
 * '<S67>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F01_Conversion_pente1
 * '<S68>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F02_Conversion_pente2
 * '<S69>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F03_Conversion_pente3
 * '<S70>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F04_Conversion_pente4
 * '<S71>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/division1
 * '<S72>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/division2
 * '<S73>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/multiplication_new2
 * '<S74>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F01_Conversion_pente1/LookUp_1D
 * '<S75>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F01_Conversion_pente1/SingleToFixdt1
 * '<S76>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F01_Conversion_pente1/SubSystem
 * '<S77>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F01_Conversion_pente1/division
 * '<S78>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F02_Conversion_pente2/SingleToFixdt1
 * '<S79>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F02_Conversion_pente2/SubSystem
 * '<S80>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F02_Conversion_pente2/division1
 * '<S81>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F03_Conversion_pente3/SingleToFixdt1
 * '<S82>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F03_Conversion_pente3/SubSystem
 * '<S83>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F03_Conversion_pente3/division1
 * '<S84>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F04_Conversion_pente4/SingleToFixdt1
 * '<S85>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F04_Conversion_pente4/SubSystem
 * '<S86>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F02_Pentes/F04_Conversion_pente4/division1
 * '<S87>'  : AdvMinT_AUTOSAR/AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F03_Choix_avance/F01_State_avmin
 * '<S88>'  : AdvMinT_AUTOSAR/AdvMinT/F01_Init/autosar_testpoint
 * '<S89>'  : AdvMinT_AUTOSAR/AdvMinT/F01_Init/autosar_testpoint1
 * '<S90>'  : AdvMinT_AUTOSAR/AdvMinT/F01_Init/autosar_testpoint2
 * '<S91>'  : AdvMinT_AUTOSAR/AdvMinT/F01_Init/convertout
 * '<S92>'  : AdvMinT_AUTOSAR/AdvMinT/F01_Init/convertout1
 * '<S93>'  : AdvMinT_AUTOSAR/AdvMinT/F01_Init/convertout2
 * '<S94>'  : AdvMinT_AUTOSAR/AdvMinT/F01_Init/convertout3
 * '<S95>'  : AdvMinT_AUTOSAR/AdvMinT/F01_Init1/convertout
 * '<S96>'  : AdvMinT_AUTOSAR/AdvMinT/F02_Init_delay/LookUp_1D
 * '<S97>'  : AdvMinT_AUTOSAR/AdvMinT/F02_Init_delay/SingleToFixdt
 * '<S98>'  : AdvMinT_AUTOSAR/AdvMinT/F02_Init_delay/autosar_testpoint
 * '<S99>'  : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim
 * '<S100>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat
 * '<S101>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb
 * '<S102>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_calcul_avance_min_agrement
 * '<S103>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo
 * '<S104>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/PreLookUp_Binary
 * '<S105>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/PreLookUp_Binary1
 * '<S106>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/PreLookUp_Binary2
 * '<S107>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/SingleToFixdt1
 * '<S108>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/autosar_testpoint
 * '<S109>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/autosar_testpoint1
 * '<S110>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/autosar_testpoint2
 * '<S111>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/convertout
 * '<S112>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/convertout1
 * '<S113>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/convertout2
 * '<S114>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/convertout3
 * '<S115>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F01_calcul_avance_min_demarrage
 * '<S116>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min
 * '<S117>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F01_calcul_avance_min_demarrage/LookUp_2D
 * '<S118>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F01_calcul_avance_min_demarrage/SingleToFixdt
 * '<S119>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F01_calc_AAmin_comb_ref
 * '<S120>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr
 * '<S121>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F03_calc_cor_cold
 * '<S122>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F01_calc_AAmin_comb_ref/Interp_2D1
 * '<S123>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F01_calc_AAmin_comb_ref/Interp_2D2
 * '<S124>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F01_calc_AAmin_comb_ref/SingleToFixdt
 * '<S125>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F01_calc_AAmin_comb_ref/SingleToFixdt1
 * '<S126>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr
 * '<S127>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F02_Ign_min_opti_vvt_adm_ref
 * '<S128>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F03_Ign_min_opti_vvt_exh_ref
 * '<S129>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr
 * '<S130>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F05_Basic_advance_min_setpoint
 * '<S131>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Clamp
 * '<S132>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Clamp1
 * '<S133>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Interp_2D1
 * '<S134>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/LookUp_1D1
 * '<S135>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/LookUp_1D2
 * '<S136>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/SingleToFixdt1
 * '<S137>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/SingleToFixdt2
 * '<S138>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/SingleToFixdt3
 * '<S139>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/SingleToFixdt4
 * '<S140>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/division1
 * '<S141>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/division2
 * '<S142>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/multiplication_new2
 * '<S143>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Clamp/Data Type Conversion Inherited
 * '<S144>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Clamp/Data Type Conversion Inherited1
 * '<S145>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Clamp/Saturation Dynamic
 * '<S146>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Clamp1/Data Type Conversion Inherited
 * '<S147>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Clamp1/Data Type Conversion Inherited1
 * '<S148>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F01_Ign_min_angle_vvt_adm_corr/Clamp1/Saturation Dynamic
 * '<S149>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F02_Ign_min_opti_vvt_adm_ref/Interp_2D
 * '<S150>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F02_Ign_min_opti_vvt_adm_ref/Interp_2D1
 * '<S151>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F03_Ign_min_opti_vvt_exh_ref/Interp_2D1
 * '<S152>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F03_Ign_min_opti_vvt_exh_ref/Interp_2D2
 * '<S153>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Clamp
 * '<S154>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Clamp1
 * '<S155>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Interp_2D1
 * '<S156>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/LookUp_1D
 * '<S157>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/LookUp_1D1
 * '<S158>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/SingleToFixdt
 * '<S159>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/SingleToFixdt1
 * '<S160>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/SingleToFixdt2
 * '<S161>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/SingleToFixdt3
 * '<S162>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/division1
 * '<S163>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/division2
 * '<S164>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/multiplication_new2
 * '<S165>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Clamp/Data Type Conversion Inherited
 * '<S166>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Clamp/Data Type Conversion Inherited1
 * '<S167>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Clamp/Saturation Dynamic
 * '<S168>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Clamp1/Data Type Conversion Inherited
 * '<S169>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Clamp1/Data Type Conversion Inherited1
 * '<S170>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F04_Ign_min_angle_vvt_exh_corr/Clamp1/Saturation Dynamic
 * '<S171>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F05_Basic_advance_min_setpoint/multiplication_new
 * '<S172>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F05_Basic_advance_min_setpoint/multiplication_new1
 * '<S173>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F05_Basic_advance_min_setpoint/multiplication_new2
 * '<S174>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F02_calc_vvt_corr/F05_Basic_advance_min_setpoint/multiplication_new3
 * '<S175>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F03_calc_cor_cold/Interp_2D1
 * '<S176>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F01_Calcul_av_lim/F02_calcul_avance_min/F03_calc_cor_cold/SingleToFixdt
 * '<S177>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/BaryCentre_VEMS
 * '<S178>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/Interp_2D
 * '<S179>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/Interp_2D1
 * '<S180>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/LookUp_1D1
 * '<S181>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/SingleToFixdt
 * '<S182>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/BaryCentre_VEMS/Clamp
 * '<S183>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S184>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S185>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F02_Calcul_av_meca_stat/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S186>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS
 * '<S187>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS1
 * '<S188>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/One_Based_Selector
 * '<S189>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/One_Based_Selector1
 * '<S190>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/SingleToFixdt
 * '<S191>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS/Clamp
 * '<S192>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S193>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S194>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S195>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS1/Clamp
 * '<S196>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited
 * '<S197>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited1
 * '<S198>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_Correctifs_AAmini_comb/BaryCentre_VEMS1/Clamp/Saturation Dynamic
 * '<S199>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_calcul_avance_min_agrement/Interp_2D1
 * '<S200>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_calcul_avance_min_agrement/Interp_2D2
 * '<S201>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_calcul_avance_min_agrement/SingleToFixdt
 * '<S202>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_calcul_avance_min_agrement/SingleToFixdt1
 * '<S203>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_calcul_avance_min_agrement/SingleToFixdt2
 * '<S204>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F03_calcul_avance_min_agrement/multiplication_new2
 * '<S205>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS
 * '<S206>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS1
 * '<S207>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/One_Based_Selector
 * '<S208>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/One_Based_Selector1
 * '<S209>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/SingleToFixdt
 * '<S210>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/SingleToFixdt1
 * '<S211>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS/Clamp
 * '<S212>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S213>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S214>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S215>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS1/Clamp
 * '<S216>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited
 * '<S217>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited1
 * '<S218>' : AdvMinT_AUTOSAR/AdvMinT/F03_Calc_bornage_avance_mini/F04_Correctifs_AAmini_thermo/BaryCentre_VEMS1/Clamp/Saturation Dynamic
 */

/*-
 * Requirements for '<Root>': AdvMinT
 *
 * Inherited requirements for '<S1>/F01_IgAdvMinMgr':
 *  1. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_001.05 ;
 *  2. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_043.02 ;
 *  3. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_038.02 ;
 *  4. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_041.01 ;
 *  5. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_035.01 ;
 *  6. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_033.01 ;
 *  7. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_042.02 ;
 *  8. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_067.01 ;
 *  9. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_068.01 ;
 *  10. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_040.01 ;
 *  11. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_032.02 ;
 *  12. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_034.01 ;
 *  13. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_037.02 ;
 *  14. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_050.02 ;
 *  15. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_077.01 ;
 *  16. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_051.01 ;
 *  17. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_044.03 ;
 *  18. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_070.05 ;
 *  19. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_084.01 ;
 *  20. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_083.01 ;
 *  21. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_082.01 ;
 *  22. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_081.01 ;
 *  23. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_080.01 ;
 *  24. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_079.01 ;
 *  25. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_066.03 ;
 *  26. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_065.03 ;
 *  27. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_002.05 ;
 *  28. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_085.01 ;
 *  29. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_086.01 ;
 *  30. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_087.01 ;
 *
 * Inherited requirements for '<S1>/F01_Init':
 *  1. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_014.01 ;
 *  2. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_063.03 ;
 *  3. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_064.03 ;
 *  4. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_076.01 ;
 *  5. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_075.01 ;
 *  6. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_065.03 ;
 *  7. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_066.03 ;
 *  8. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_071.02 ;
 *  9. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_078.01 ;
 *  10. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_012.02 ;
 *  11. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_013.02 ;
 *
 * Inherited requirements for '<S1>/F01_Init1':
 *  1. SubSystem "F01_Init1" !Trace_To : VEMS_R_10_06440_044.03 ;
 *  2. SubSystem "F01_Init1" !Trace_To : VEMS_R_10_06440_069.02 ;
 *
 * Inherited requirements for '<S1>/F02_Init_delay':
 *  1. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_015.01 ;
 *  2. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_074.02 ;
 *  3. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_049.01 ;
 *  4. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_078.01 ;
 *  5. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_012.02 ;
 *  6. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_013.02 ;
 *
 * Inherited requirements for '<S1>/F03_Calc_bornage_avance_mini':
 *  1. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_016.03 ;
 *  2. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_047.01 ;
 *  3. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_048.01 ;
 *  4. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_035.01 ;
 *  5. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_052.01 ;
 *  6. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_053.01 ;
 *  7. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_036.01 ;
 *  8. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_054.01 ;
 *  9. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_055.01 ;
 *  10. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_056.01 ;
 *  11. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_057.01 ;
 *  12. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_058.01 ;
 *  13. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_059.01 ;
 *  14. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_060.01 ;
 *  15. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_061.01 ;
 *  16. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_062.01 ;
 *  17. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_063.03 ;
 *  18. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_064.03 ;
 *  19. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_076.01 ;
 *  20. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_075.01 ;
 *  21. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_066.03 ;
 *  22. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_065.03 ;
 *  23. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_072.03 ;
 *  24. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_078.01 ;
 *  25. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_012.02 ;
 *  26. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_013.02 ;

 */
#endif                                 /* RTW_HEADER_AdvMinT_h_ */

/*-------------------------------- end of file -------------------------------*/
