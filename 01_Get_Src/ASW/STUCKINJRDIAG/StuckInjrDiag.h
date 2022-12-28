/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : StuckInjrDiag                                           */
/* !Description     : Diagnosis of stuck injectors                            */
/*                                                                            */
/* !Module          : StuckInjrDiag                                           */
/*                                                                            */
/* !File            : StuckInjrDiag.h                                         */
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
/*   Code generated on: Sun Oct 20 10:36:43 2013                              */
/*   Model name       : StuckInjrDiag_AUTOCODE.mdl                            */
/*   Model version    : 1.223                                                 */
/*   Root subsystem   : /StuckInjrDiag                                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/STUCKINJRDIAG/StuckInjrDiag.h$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   28 Oct 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_StuckInjrDiag_h_
#define RTW_HEADER_StuckInjrDiag_h_
#ifndef StuckInjrDiag_COMMON_INCLUDES_
# define StuckInjrDiag_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "StuckInjrDiag_import.h"
#include "VEMS.H"
#include "GDGAR.H"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#endif                                 /* StuckInjrDiag_COMMON_INCLUDES_ */

#include "StuckInjrDiag_types.h"

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
  SInt32 VEMS_vidGET5;                /* '<S9>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET;                /* '<S9>/VEMS_vidGET' */
  UInt16 VEMS_vidGET4;               /* '<S9>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET3;               /* '<S9>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET2;               /* '<S9>/VEMS_vidGET2' */
  UInt8 SFunction4;                  /* '<S7>/S-Function4' */
  UInt8 VEMS_vidGET1;                /* '<S9>/VEMS_vidGET1' */
} BlockIO_StuckInjrDiag;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt32 UnitDelay_DSTATE;           /* '<S22>/Unit Delay' */
  Boolean UnitDelay_DSTATE_o;        /* '<S20>/Unit Delay' */
  Boolean UnitDelay_DSTATE_d;        /* '<S21>/Unit Delay' */
} D_Work_StuckInjrDiag;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S14>/Lookup Table (n-D)'
   *   '<S18>/Lookup Table (n-D)'
   */
  UInt32 pooled3[2];
} ConstParam_StuckInjrDiag;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define STUCKINJRDIAG_START_SEC_VAR_UNSPECIFIED
#include "StuckInjrDiag_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_StuckInjrDiag StuckInjrDiag_B;

/* Block states (auto storage) */
extern D_Work_StuckInjrDiag StuckInjrDiag_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_StuckInjrDiag StuckInjrDiag_ConstP;

#define STUCKINJRDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define STUCKINJRDIAG_START_SEC_CODE
#include "StuckInjrDiag_MemMap.h"

/* Model entry point functions */
extern void StuckInjrDiag_initialize(void);
extern void Fu_SdlFast_StuckInjrDiag(void);

#define STUCKINJRDIAG_STOP_SEC_CODE
#include "StuckInjrDiag_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define STUCKINJRDIAG_START_SEC_CALIB_16BIT
#include "StuckInjrDiag_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_MinEngAuthDiagStuckInjr_C;

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_mFuSpStckOpInjrFallp_A[9];

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_nEngStckOpInjrThd_A[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    -2.56E+007                                                        */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_pFuRailDifStckOpInjrThd_M[81];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    -2.56E+007                                                        */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_pFuRailStckOpInjrFallp_M[81];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_pFuRailStckOpInjrThd_A[9];

/* Type:    SInt16                                                           */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   su                                                                */
/* PhysMin: -1.0                                                              */
/* PhysMax: 1.0                                                               */
extern CONST(SInt16, STUCKINJRDIAG_CALIB) Fu_pFuReqGainMaxThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    -2.56E+007                                                        */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_pFuReqOfsMaxThd_C;

/* Type:    UInt16                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_rFuReqGainThd_C;

/* Type:    UInt16                                                          */
/* Slope:   0.02                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 500.0                                                             */
extern CONST(UInt16, STUCKINJRDIAG_CALIB) Fu_tiPFuRailStabDly_C;

#define STUCKINJRDIAG_STOP_SEC_CALIB_16BIT
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define STUCKINJRDIAG_START_SEC_CALIB_BOOLEAN
#include "StuckInjrDiag_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, STUCKINJRDIAG_CALIB) Fu_bInhPFuRailStabStckInjr_C;

#define STUCKINJRDIAG_STOP_SEC_CALIB_BOOLEAN
#include "StuckInjrDiag_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S18>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S18>/x1' : Unused code path elimination
 * Block '<S18>/x2' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S14>/x1' : Unused code path elimination
 * Block '<S14>/x2' : Unused code path elimination
 * Block '<S15>/Switch' : Eliminated due to constant selection input
 * Block '<S15>/Add2' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S15>/offset1' : Unused code path elimination
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
 * hilite_system('StuckInjrDiag_AUTOCODE/StuckInjrDiag')    - opens subsystem StuckInjrDiag_AUTOCODE/StuckInjrDiag
 * hilite_system('StuckInjrDiag_AUTOCODE/StuckInjrDiag/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : StuckInjrDiag_AUTOCODE
 * '<S1>'   : StuckInjrDiag_AUTOCODE/StuckInjrDiag
 * '<S3>'   : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag
 * '<S4>'   : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem
 * '<S5>'   : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem1
 * '<S6>'   : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem2
 * '<S7>'   : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem3
 * '<S8>'   : StuckInjrDiag_AUTOCODE/StuckInjrDiag/demux_fc1
 * '<S9>'   : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag
 * '<S10>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv
 * '<S11>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/02_bMonRunStuckOpInjr
 * '<S12>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/03_bDgoStuckOpInjr
 * '<S13>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/01_StckOpInjrDetect
 * '<S14>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/LookUp_2D
 * '<S15>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/SingleToFixdt
 * '<S16>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/TIMER
 * '<S17>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/multiplication1
 * '<S18>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/01_StckOpInjrDetect/LookUp_2D
 * '<S19>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/01_StckOpInjrDetect/multiplication1
 * '<S20>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/TIMER/SubSystem
 * '<S21>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/TIMER/SubSystem1
 * '<S22>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/01_StuckOpenInjrDiag/01_StuckOpenInjrDiag/01_StuckOpInjrDiagAcv/TIMER/SubSystem2
 * '<S23>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem/GDGAR_vidGdu
 * '<S24>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem1/GDGAR_vidGdu
 * '<S25>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem2/GDGAR_vidGdu
 * '<S26>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem3/Fun_Call_Gen_with_condition_Modified
 * '<S27>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem3/GDGAR_vidGdu_Subsystem
 * '<S28>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem3/Fun_Call_Gen_with_condition_Modified/Chart
 * '<S29>'  : StuckInjrDiag_AUTOCODE/StuckInjrDiag/Function-Call Subsystem3/GDGAR_vidGdu_Subsystem/GDGAR_vidGdu
 */

/*-
 * Requirements for '<Root>': StuckInjrDiag
 *
 * Inherited requirements for '<S1>/01_StuckOpenInjrDiag':
 *  1. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_001.01 ;
 *  2. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_002.01 ;
 *  3. SubSystem "01_StuckOpenInjrDiag" !Trace_To : VEMS_E_11_01999_003.01 ;

 */
#endif                                 /* RTW_HEADER_StuckInjrDiag_h_ */

/*-------------------------------- end of file -------------------------------*/
