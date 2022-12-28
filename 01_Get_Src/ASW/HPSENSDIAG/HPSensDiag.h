/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPSensDiag                                              */
/* !Description     : Functional diagnosis of HP Sensor                       */
/*                                                                            */
/* !Module          : HPSensDiag                                              */
/*                                                                            */
/* !File            : HPSensDiag.h                                            */
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
/*   Code generated on: Thu Oct 17 18:16:02 2013                              */
/*   Model name       : HPSensDiag_Autocode.mdl                               */
/*   Model version    : 1.418                                                 */
/*   Root subsystem   : /HPSensDiag                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/HPSENSDIAG/HPSensDiag.h_v    $*/
/* $Revision::   1.7                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   21 Oct 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPSensDiag_h_
#define RTW_HEADER_HPSensDiag_h_
#ifndef HPSensDiag_COMMON_INCLUDES_
# define HPSensDiag_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "HPSensDiag_import.h"
#include "VEMS.H"
#include "GDGAR.H"
#include "rtw_shared_utils.h"
#endif                                 /* HPSensDiag_COMMON_INCLUDES_ */

#include "HPSensDiag_types.h"

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
  UInt32 VEMS_vidGET1;               /* '<S42>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET3;               /* '<S14>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET;                /* '<S42>/VEMS_vidGET' */
  UInt16 VEMS_vidGET_g;              /* '<S14>/VEMS_vidGET' */
  UInt16 VEMS_vidGET2;               /* '<S14>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET1_k;             /* '<S14>/VEMS_vidGET1' */
} BlockIO_HPSensDiag;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt32 UnitDelay_DSTATE;           /* '<S45>/Unit Delay' */
  SInt32 UnitDelay_DSTATE_l;          /* '<S39>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_ly;        /* '<S49>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_j;         /* '<S40>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_h;         /* '<S32>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_b;         /* '<S33>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_k;         /* '<S44>/Unit Delay' */
  Boolean UnitDelay_DSTATE_lp;       /* '<S41>/Unit Delay' */
  Boolean UnitDelay_DSTATE_m;        /* '<S17>/Unit Delay' */
  Boolean UnitDelay_DSTATE_bx;       /* '<S18>/Unit Delay' */
  Boolean UnitDelay_DSTATE_hs;       /* '<S35>/Unit Delay' */
  Boolean UnitDelay_DSTATE_h3;       /* '<S37>/Unit Delay' */
  Boolean UnitDelay_DSTATE_f;        /* '<S38>/Unit Delay' */
  Boolean UnitDelay_DSTATE_jk;       /* '<S36>/Unit Delay' */
  Boolean UnitDelay_DSTATE_fv;       /* '<S25>/Unit Delay' */
  Boolean UnitDelay_DSTATE_fi;       /* '<S27>/Unit Delay' */
  Boolean UnitDelay_DSTATE_d;        /* '<S26>/Unit Delay' */
} D_Work_HPSensDiag;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define HPSENSDIAG_START_SEC_VAR_UNSPECIFIED
#include "HPSensDiag_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_HPSensDiag HPSensDiag_B;

/* Block states (auto storage) */
extern D_Work_HPSensDiag HPSensDiag_DWork;

#define HPSENSDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "HPSensDiag_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define HPSENSDIAG_START_SEC_CODE
#include "HPSensDiag_MemMap.h"

/* Model entry point functions */
extern void HPSensDiag_initialize(void);
extern void Fu_EveSpl_HPSensDiag(void);
extern void Fu_SdlFast_HPSensDiag(void);
extern void Fu_EveRst_HPSensDiag(void);

#define HPSENSDIAG_STOP_SEC_CODE
#include "HPSensDiag_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define HPSENSDIAG_START_SEC_CALIB_32BIT
#include "HPSensDiag_MemMap.h"

/* Type:    SInt32                                                           */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: -0.00048828125                                                    */
/* PhysMax: 0.0078125                                                         */
extern CONST(SInt32, HPSENSDIAG_CALIB) Fu_mFuDifBtwSpl_A[9];

#define HPSENSDIAG_STOP_SEC_CALIB_32BIT
#include "HPSensDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define HPSENSDIAG_START_SEC_CALIB_16BIT
#include "HPSensDiag_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_mFuDifThdMin_C;

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_mFuInjMinHPSensThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuDifHPSensDiagThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    -5.119921875E+007                                                 */
/* Units:   Pa                                                                */
/* PhysMin: -5.119921875E+007                                                 */
/* PhysMax: 0                                                                 */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailDifNegThd_T[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailDifPosThd_T[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailGrdHPSensDiag_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailMaxHPSensThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailMinHPSensThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailThdMax_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuRailThdMin_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuReqGrdHPSensDiagThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_pFuReqThdBdVal_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_rFuEngMinHPSensThd_C;

/* Type:    UInt16                                                          */
/* Slope:   0.02                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 500.0                                                             */
extern CONST(UInt16, HPSENSDIAG_CALIB) Fu_tiPFuRailStabHPSensDiagDly_C;

#define HPSENSDIAG_STOP_SEC_CALIB_16BIT
#include "HPSensDiag_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S22>/Logical Operator2' : Unused code path elimination
 * Block '<S19>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S43>/Fu_mFuDifBtwSpl_A' : Unused code path elimination
 * Block '<S46>/BKPT1' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S46>/TABLE' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S47>/x1' : Unused code path elimination
 * Block '<S23>/Switch' : Eliminated due to constant selection input
 * Block '<S46>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S48>/Switch' : Eliminated due to constant selection input
 * Block '<S23>/Add2' : Unused code path elimination
 * Block '<S23>/Constant' : Unused code path elimination
 * Block '<S23>/offset1' : Unused code path elimination
 * Block '<S48>/Add2' : Unused code path elimination
 * Block '<S48>/Constant' : Unused code path elimination
 * Block '<S48>/offset1' : Unused code path elimination
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
 * hilite_system('HPSensDiag_Autocode/HPSensDiag')    - opens subsystem HPSensDiag_Autocode/HPSensDiag
 * hilite_system('HPSensDiag_Autocode/HPSensDiag/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : HPSensDiag_Autocode
 * '<S1>'   : HPSensDiag_Autocode/HPSensDiag
 * '<S5>'   : HPSensDiag_Autocode/HPSensDiag/F00_mFuBtwEveInj
 * '<S6>'   : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag
 * '<S7>'   : HPSensDiag_Autocode/HPSensDiag/F02_CohTest
 * '<S8>'   : HPSensDiag_Autocode/HPSensDiag/F03_HPSensDiagInit
 * '<S9>'   : HPSensDiag_Autocode/HPSensDiag/GDGAR_vidGdu
 * '<S10>'  : HPSensDiag_Autocode/HPSensDiag/GDGAR_vidGdu1
 * '<S11>'  : HPSensDiag_Autocode/HPSensDiag/demux_fc
 * '<S12>'  : HPSensDiag_Autocode/HPSensDiag/demux_fc1
 * '<S13>'  : HPSensDiag_Autocode/HPSensDiag/F00_mFuBtwEveInj/F00_mFuBtwEveInj
 * '<S14>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag
 * '<S15>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn
 * '<S16>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd
 * '<S17>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/SubSystem
 * '<S18>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/SubSystem1
 * '<S19>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/Unit_Delay_External_IC
 * '<S20>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn/Falling_edge
 * '<S21>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn/Rising_edge1
 * '<S22>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn/SR_FlipFlop
 * '<S23>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn/SingleToFixdt
 * '<S24>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn/multiplication
 * '<S25>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn/Falling_edge/SubSystem
 * '<S26>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn/Rising_edge1/SubSystem
 * '<S27>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F01_pFuRailReqCdn/SR_FlipFlop/SubSystem
 * '<S28>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/F01_bDgoStuckClcn
 * '<S29>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/F02_bAcvStuckDiag
 * '<S30>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/Rising_edge
 * '<S31>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/Rising_edge1
 * '<S32>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/SubSystem
 * '<S33>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/SubSystem1
 * '<S34>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/TIMER
 * '<S35>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/Rising_edge/SubSystem
 * '<S36>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/Rising_edge1/SubSystem
 * '<S37>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/TIMER/SubSystem
 * '<S38>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/TIMER/SubSystem1
 * '<S39>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/F02_pFuRailGrd/TIMER/SubSystem2
 * '<S40>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/Unit_Delay_External_IC/SubSystem
 * '<S41>'  : HPSensDiag_Autocode/HPSensDiag/F01_HPSensDiag/F01_HPSensDiag/Unit_Delay_External_IC/SubSystem1
 * '<S42>'  : HPSensDiag_Autocode/HPSensDiag/F02_CohTest/F02_CohTest
 * '<S43>'  : HPSensDiag_Autocode/HPSensDiag/F02_CohTest/F02_CohTest/F01_DiagAcv
 * '<S44>'  : HPSensDiag_Autocode/HPSensDiag/F02_CohTest/F02_CohTest/VEMS_UnitDelay
 * '<S45>'  : HPSensDiag_Autocode/HPSensDiag/F02_CohTest/F02_CohTest/VEMS_UnitDelay1
 * '<S46>'  : HPSensDiag_Autocode/HPSensDiag/F02_CohTest/F02_CohTest/F01_DiagAcv/Fu_pFuRailDifNegThd_T
 * '<S47>'  : HPSensDiag_Autocode/HPSensDiag/F02_CohTest/F02_CohTest/F01_DiagAcv/Fu_pFuRailDifPosThd_T
 * '<S48>'  : HPSensDiag_Autocode/HPSensDiag/F02_CohTest/F02_CohTest/F01_DiagAcv/SingleToFixdt
 * '<S49>'  : HPSensDiag_Autocode/HPSensDiag/F02_CohTest/F02_CohTest/F01_DiagAcv/VEMS_UnitDelay
 * '<S50>'  : HPSensDiag_Autocode/HPSensDiag/GDGAR_vidGdu/GDGAR_vidGdu
 * '<S51>'  : HPSensDiag_Autocode/HPSensDiag/GDGAR_vidGdu1/GDGAR_vidGdu
 */

/*-
 * Requirements for '<Root>': HPSensDiag
 *
 * Inherited requirements for '<S1>/GDGAR_vidGdu':
 *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_10_08248_029.01 ;
 *
 * Inherited requirements for '<S1>/GDGAR_vidGdu1':
 *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_10_08248_029.01 ;

 */
#endif                                 /* RTW_HEADER_HPSensDiag_h_ */

/*-------------------------------- end of file -------------------------------*/
