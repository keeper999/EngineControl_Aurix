/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpFctDiag                                            */
/* !Description     : HPPmpFctDiag– DIAGNOSTIC FONCTIONNEL DE LA REGULATION PRESSION RAIL*/
/*                                                                            */
/* !Module          : HPPmpFctDiag                                            */
/*                                                                            */
/* !File            : HPPmpFctDiag.h                                          */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
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
/*   Code generated on: Wed Jul 23 18:15:05 2014                              */
/*   Model name       : HPPmpFctDiag_AUTOCODE.mdl                             */
/*   Model version    : 1.358                                                 */
/*   Root subsystem   : /HPPmpFctDiag                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPFCTDIAG/HPPmpFctDiag$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   mbenfrad                               $$Date::   24 Jul 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPPmpFctDiag_h_
#define RTW_HEADER_HPPmpFctDiag_h_
#ifndef HPPmpFctDiag_COMMON_INCLUDES_
# define HPPmpFctDiag_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "HPPmpFctDiag_import.h"
#include "VEMS.H"
#include "GDGAR.H"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#endif                                 /* HPPmpFctDiag_COMMON_INCLUDES_ */

#include "HPPmpFctDiag_types.h"

/* Includes for objects with custom storage classes. */
#include "GDGAR.h"

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
  UInt32 VEMS_vidGET1;               /* '<S17>/VEMS_vidGET1' */
  SInt32 VEMS_vidGET14;               /* '<S17>/VEMS_vidGET14' */
  UInt32 Switch;                     /* '<S23>/Switch' */
  SInt16 VEMS_vidGET5;                /* '<S17>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET3;               /* '<S17>/VEMS_vidGET3' */
  SInt16 VEMS_vidGET13;               /* '<S17>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET4;               /* '<S17>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET8;               /* '<S17>/VEMS_vidGET8' */
  UInt8 VEMS_vidGET;                 /* '<S17>/VEMS_vidGET' */
  Boolean VEMS_vidGET11;             /* '<S17>/VEMS_vidGET11' */
  Boolean VEMS_vidGET9;              /* '<S17>/VEMS_vidGET9' */
  Boolean VEMS_vidGET7;              /* '<S17>/VEMS_vidGET7' */
  Boolean VEMS_vidGET2;              /* '<S17>/VEMS_vidGET2' */
  Boolean VEMS_vidGET15;             /* '<S17>/VEMS_vidGET15' */
  Boolean VEMS_vidGET10;             /* '<S17>/VEMS_vidGET10' */
  Boolean VEMS_vidGET12;             /* '<S17>/VEMS_vidGET12' */
  UInt8 VEMS_vidGET6;                /* '<S17>/VEMS_vidGET6' */
} BlockIO_HPPmpFctDiag;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S53>/Unit Delay' */
  UInt32 UnitDelay_DSTATE_a;         /* '<S56>/Unit Delay' */
  UInt32 UnitDelay_DSTATE_h;         /* '<S59>/Unit Delay' */
  UInt32 UnitDelay_DSTATE_o;         /* '<S48>/Unit Delay' */
  UInt32 UnitDelay_DSTATE_d;         /* '<S35>/Unit Delay' */
  UInt32 UnitDelay_DSTATE_ol;        /* '<S32>/Unit Delay' */
  Boolean UnitDelay_DSTATE_i;        /* '<S54>/Unit Delay' */
  Boolean UnitDelay_DSTATE_k;        /* '<S55>/Unit Delay' */
  Boolean UnitDelay_DSTATE_al;       /* '<S57>/Unit Delay' */
  Boolean UnitDelay_DSTATE_m;        /* '<S58>/Unit Delay' */
  Boolean UnitDelay_DSTATE_ar;       /* '<S46>/Unit Delay' */
  Boolean UnitDelay_DSTATE_l;        /* '<S47>/Unit Delay' */
  Boolean UnitDelay_DSTATE_kf;       /* '<S33>/Unit Delay' */
  Boolean UnitDelay_DSTATE_g;        /* '<S34>/Unit Delay' */
  Boolean UnitDelay_DSTATE_e;        /* '<S30>/Unit Delay' */
  Boolean UnitDelay_DSTATE_n;        /* '<S31>/Unit Delay' */
} D_Work_HPPmpFctDiag;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define HPPMPFCTDIAG_START_SEC_VAR_UNSPECIFIED
#include "HPPmpFctDiag_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_HPPmpFctDiag HPPmpFctDiag_B;

/* Block states (auto storage) */
extern D_Work_HPPmpFctDiag HPPmpFctDiag_DWork;

#define HPPMPFCTDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpFctDiag_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define HPPMPFCTDIAG_START_SEC_CODE
#include "HPPmpFctDiag_MemMap.h"

/* Model entry point functions */
extern void HPPmpFctDiag_initialize(void);
extern void PFuCtl_EveSpl_HPPmpFctDiag(void);

#define HPPMPFCTDIAG_STOP_SEC_CODE
#include "HPPmpFctDiag_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define HPPMPFCTDIAG_START_SEC_CALIB_32BIT
#include "HPPmpFctDiag_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.99999E+002                                                      */
extern CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiAftrCutOff_C;

/* Type:    UInt32                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.99999E+002                                                      */
extern CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiORngDly_C;

/* Type:    UInt32                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.99999E+002                                                      */
extern CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiPFuRailMes_C;

/* Type:    UInt32                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.99999E+002                                                      */
extern CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiThdDetDeICtl_C;

/* Type:    UInt32                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.99999E+002                                                      */
extern CONST(UInt32, HPPMPFCTDIAG_CALIB) PFuCtl_tiTransPFuReq_C;

#define HPPMPFCTDIAG_STOP_SEC_CALIB_32BIT
#include "HPPmpFctDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define HPPMPFCTDIAG_START_SEC_CALIB_16BIT
#include "HPPmpFctDiag_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    -100.0                                                            */
/* Units:   %                                                                 */
/* PhysMin: -100.0                                                            */
/* PhysMax: 0                                                                 */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_FuRailNegDifColdTcoThd_T[9];

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    -100.0                                                            */
/* Units:   %                                                                 */
/* PhysMin: -100.0                                                            */
/* PhysMax: 0                                                                 */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_FuRailNegDifHotTcoThd_T[9];

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 100.0                                                             */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_FuRailPosDifColdTcoThd_T[9];

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 100.0                                                             */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_FuRailPosDifHotTcoThd_T[9];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_nEngMin_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    -5.119921875E+007                                                 */
/* Units:   Pa                                                                */
/* PhysMin: -5.119921875E+007                                                 */
/* PhysMax: 0                                                                 */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuRailINegThdDetDe_T[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuRailIPosThdDetDe_T[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuRailMesThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuReqMax_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuReqMin_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pFuReq_A[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPFCTDIAG_CALIB) PFuCtl_pPrailSpDiff_C;

#define HPPMPFCTDIAG_STOP_SEC_CALIB_16BIT
#include "HPPmpFctDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPPMPFCTDIAG_START_SEC_CALIB_8BIT
#include "HPPmpFctDiag_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, HPPMPFCTDIAG_CALIB) PFuCtl_tCoMesThd_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, HPPMPFCTDIAG_CALIB) PFuCtl_tCoMes_A[9];

#define HPPMPFCTDIAG_STOP_SEC_CALIB_8BIT
#include "HPPmpFctDiag_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S25>/BKPT1' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S25>/TABLE' : Unused code path elimination
 * Block '<S18>/PFuCtl_tCoMes_A' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S27>/x' : Unused code path elimination
 * Block '<S36>/BKPT1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/TABLE' : Unused code path elimination
 * Block '<S37>/BKPT1' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S37>/TABLE' : Unused code path elimination
 * Block '<S19>/PFuCtl_pFuReq_A' : Unused code path elimination
 * Block '<S19>/PFuCtl_pFuReq_A_1' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S38>/Data Type Propagation1' : Unused code path elimination
 * Block '<S40>/Data Type Propagation' : Unused code path elimination
 * Block '<S40>/Data Type Conversion' : Unused code path elimination
 * Block '<S40>/Data Type Conversion1' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S44>/x' : Unused code path elimination
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S37>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('HPPmpFctDiag_AUTOCODE/HPPmpFctDiag')    - opens subsystem HPPmpFctDiag_AUTOCODE/HPPmpFctDiag
 * hilite_system('HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : HPPmpFctDiag_AUTOCODE
 * '<S1>'   : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag
 * '<S3>'   : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu
 * '<S4>'   : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu1
 * '<S5>'   : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu2
 * '<S6>'   : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu3
 * '<S7>'   : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu4
 * '<S8>'   : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu5
 * '<S9>'   : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag
 * '<S10>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/demux_fc1
 * '<S11>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu/GDGAR_vidGdu
 * '<S12>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu1/GDGAR_vidGdu
 * '<S13>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu2/GDGAR_vidGdu
 * '<S14>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu3/GDGAR_vidGdu
 * '<S15>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu4/GDGAR_vidGdu
 * '<S16>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/GDGAR_vidGdu5/GDGAR_vidGdu
 * '<S17>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag
 * '<S18>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag
 * '<S19>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F02_NegativeDiff
 * '<S20>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F03_PositiveDiff
 * '<S21>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F04_ORngPFuRailMes
 * '<S22>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl
 * '<S23>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F06_tiHighPressure
 * '<S24>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F07_IFrz
 * '<S25>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/PFuCtl_pFuRailINegThdDetDe_T
 * '<S26>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/PFuCtl_pFuRailIPosThdDetDe_T
 * '<S27>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/PFuCtl_tCoMes_A_PreLookUp
 * '<S28>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/TIMER1
 * '<S29>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/TIMER2
 * '<S30>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/TIMER1/UnitDelay1
 * '<S31>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/TIMER1/UnitDelay2
 * '<S32>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/TIMER1/UnitDelay3
 * '<S33>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/TIMER2/UnitDelay1
 * '<S34>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/TIMER2/UnitDelay2
 * '<S35>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F01_HPPmpCtlFctDiag/TIMER2/UnitDelay3
 * '<S36>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F02_NegativeDiff/PFuCtl_FuRailNegDifColdTcoThd_T
 * '<S37>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F02_NegativeDiff/PFuCtl_FuRailNegDifHotTcoThd_T
 * '<S38>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F02_NegativeDiff/Subsystem1
 * '<S39>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F02_NegativeDiff/multiplication_411
 * '<S40>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F02_NegativeDiff/Subsystem1/Data Type Police Only single
 * '<S41>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F02_NegativeDiff/Subsystem1/If Action Subsystem3
 * '<S42>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F03_PositiveDiff/PFuCtl_FuRailPosDifColdTcoThd_T
 * '<S43>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F03_PositiveDiff/PFuCtl_FuRailPosDifHotTcoThd_T
 * '<S44>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F03_PositiveDiff/PFuCtl_pFuReq_A_PreLookUp
 * '<S45>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F04_ORngPFuRailMes/TIMER1
 * '<S46>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F04_ORngPFuRailMes/TIMER1/UnitDelay1
 * '<S47>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F04_ORngPFuRailMes/TIMER1/UnitDelay2
 * '<S48>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F04_ORngPFuRailMes/TIMER1/UnitDelay3
 * '<S49>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition
 * '<S50>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F02_Activation_Diag
 * '<S51>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/TIMER1
 * '<S52>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/TIMER2
 * '<S53>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/UnitDelay1
 * '<S54>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/TIMER1/UnitDelay1
 * '<S55>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/TIMER1/UnitDelay2
 * '<S56>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/TIMER1/UnitDelay3
 * '<S57>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/TIMER2/UnitDelay1
 * '<S58>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/TIMER2/UnitDelay2
 * '<S59>'  : HPPmpFctDiag_AUTOCODE/HPPmpFctDiag/HPPmpCtlFctDiag/HPPmpCtlFctDiag/F05_bMonRun_PFuCtl/F01_Transient_Condition/TIMER2/UnitDelay3
 */
#endif                                 /* RTW_HEADER_HPPmpFctDiag_h_ */

/*-------------------------------- end of file -------------------------------*/
