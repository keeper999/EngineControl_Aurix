/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : FuSysExtLeakDiag                                        */
/* !Description     : Functional diagnosis of external leak on Fuel System    */
/*                                                                            */
/* !Module          : FuSysExtLeakDiag                                        */
/*                                                                            */
/* !File            : FuSysExtLeakDiag.h                                      */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
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
/*   Code generated on: Tue Dec 17 15:22:53 2013                              */
/*   Model name       : FuSysExtLeakDiag_AUTOCODE.mdl                         */
/*   Model version    : 1.349                                                 */
/*   Root subsystem   : /FuSysExtLeakDiag                                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FUSYSEXTLEAKDIAG/FuSysExtLeak$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   etsasson                               $$Date::   19 Dec 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_FuSysExtLeakDiag_h_
#define RTW_HEADER_FuSysExtLeakDiag_h_
#ifndef FuSysExtLeakDiag_COMMON_INCLUDES_
# define FuSysExtLeakDiag_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "FuSysExtLeakDiag_import.h"
#include "VEMS.H"
#include "GDGAR.H"
#include "rtw_shared_utils.h"
#endif                                 /* FuSysExtLeakDiag_COMMON_INCLUDES_ */

#include "FuSysExtLeakDiag_types.h"

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
  SInt32 VEMS_vidGET7;                /* '<S8>/VEMS_vidGET7' */
  UInt32 VEMS_vidGET3;               /* '<S8>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET2;               /* '<S8>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET5;               /* '<S8>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET4;               /* '<S8>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET;                 /* '<S8>/VEMS_vidGET' */
  Boolean RelationalOperator;        /* '<S5>/Relational Operator' */
  Boolean RelationalOperator1;       /* '<S8>/Relational Operator1' */
  Boolean VEMS_vidGET1;              /* '<S8>/VEMS_vidGET1' */
  Boolean VEMS_vidGET6;              /* '<S8>/VEMS_vidGET6' */
  Boolean VEMS_vidGET8;              /* '<S8>/VEMS_vidGET8' */
  Boolean Switch2[2];                /* '<S27>/Switch2' */
  Boolean Switch2_h[2];              /* '<S18>/Switch2' */
} BlockIO_FuSysExtLeakDiag;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt32 UnitDelay_DSTATE;           /* '<S35>/Unit Delay' */
  UInt32 UnitDelay_DSTATE_p;         /* '<S39>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_k;         /* '<S34>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_i;         /* '<S31>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_i4;        /* '<S22>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_h;         /* '<S30>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_kp;        /* '<S21>/Unit Delay' */
  Boolean UnitDelay_DSTATE_b;        /* '<S43>/Unit Delay' */
  Boolean UnitDelay_DSTATE_g;        /* '<S42>/Unit Delay' */
  Boolean UnitDelay_DSTATE_pt;       /* '<S40>/Unit Delay' */
  Boolean UnitDelay_DSTATE_gp;       /* '<S41>/Unit Delay' */
  Boolean UnitDelay_DSTATE_f;        /* '<S37>/Unit Delay' */
  Boolean UnitDelay_DSTATE_d;        /* '<S29>/Unit Delay' */
  Boolean UnitDelay_DSTATE_pm;       /* '<S20>/Unit Delay' */
} D_Work_FuSysExtLeakDiag;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define FUSYSEXTLEAKDIAG_START_SEC_VAR_UNSPECIFIED
#include "FuSysExtLeakDiag_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_FuSysExtLeakDiag FuSysExtLeakDiag_B;

/* Block states (auto storage) */
extern D_Work_FuSysExtLeakDiag FuSysExtLeakDiag_DWork;

#define FUSYSEXTLEAKDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define FUSYSEXTLEAKDIAG_START_SEC_CODE
#include "FuSysExtLeakDiag_MemMap.h"

/* Model entry point functions */
extern void FuSysExtLeakDiag_initialize(void);
extern void Fu_SdlMid_ExtLeakDiag(void);
extern void Fu_EveRst_ExtLeakDiag(void);

#define FUSYSEXTLEAKDIAG_STOP_SEC_CODE
#include "FuSysExtLeakDiag_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_32BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.00048828125                                                     */
extern CONST(UInt32, FUSYSEXTLEAKDIAG_CALIB) Fu_mFuReqDiff_C;

/* Type:    SInt32                                                           */
/* Slope:   1.1920928955078125E-002                                           */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.5599999988079071E+007                                           */
extern CONST(SInt32, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailDifExtLeakThd_C;

/* Type:    UInt32                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 500.0                                                             */
extern CONST(UInt32, FUSYSEXTLEAKDIAG_CALIB) Fu_tiTransPFuReq_C;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_32BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_16BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_nEngMinLeakEngRunDiag_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailExtLeakEngStallMem_A[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailExtLeakMinThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailGrdExtLkEngRunOfsThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailGrdExtLkEngStallThd_T[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuReqDiff_C;

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 500.0                                                             */
extern CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_tiPFuRailExtLeakEngRunDly_C;

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 500.0                                                             */
extern CONST(UInt16, FUSYSEXTLEAKDIAG_CALIB) Fu_tiPFuRailExtLeakEngStallDly_C;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_16BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_8BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   3.9215686274509803E-003                                           */
/* Bias:    0.0                                                               */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, FUSYSEXTLEAKDIAG_CALIB) Fu_pFuRailGrdExtLkEngRunGThd_C;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_8BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_BOOLEAN
#include "FuSysExtLeakDiag_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FUSYSEXTLEAKDIAG_CALIB) Fu_bAcvExtLeakEngRunDiag_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FUSYSEXTLEAKDIAG_CALIB) Fu_bAcvExtLeakEngStallDiag_C;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_BOOLEAN
#include "FuSysExtLeakDiag_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S19>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S28>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/x1' : Unused code path elimination
 * Block '<S36>/Logical Operator' : Unused code path elimination
 * Block '<S38>/Unit Delay' : Unused code path elimination
 * Block '<S36>/Switch1' : Unused code path elimination
 * Block '<S23>/Switch' : Eliminated due to constant selection input
 * Block '<S33>/Switch' : Eliminated due to constant selection input
 * Block '<S23>/Add3' : Unused code path elimination
 * Block '<S23>/Add4' : Unused code path elimination
 * Block '<S23>/Constant' : Unused code path elimination
 * Block '<S23>/Relational Operator' : Unused code path elimination
 * Block '<S23>/Switch1' : Unused code path elimination
 * Block '<S23>/offset2' : Unused code path elimination
 * Block '<S23>/offset3' : Unused code path elimination
 * Block '<S23>/offset4' : Unused code path elimination
 * Block '<S33>/Add3' : Unused code path elimination
 * Block '<S33>/Add4' : Unused code path elimination
 * Block '<S33>/Constant' : Unused code path elimination
 * Block '<S33>/Relational Operator' : Unused code path elimination
 * Block '<S33>/Switch1' : Unused code path elimination
 * Block '<S33>/offset2' : Unused code path elimination
 * Block '<S33>/offset3' : Unused code path elimination
 * Block '<S33>/offset4' : Unused code path elimination
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
 * hilite_system('FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag')    - opens subsystem FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag
 * hilite_system('FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : FuSysExtLeakDiag_AUTOCODE
 * '<S1>'   : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag
 * '<S4>'   : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/00_FuSysExtLeakDiagInit
 * '<S5>'   : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag
 * '<S6>'   : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/GDGAR_vidGdu
 * '<S7>'   : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/demux_fc1
 * '<S8>'   : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag
 * '<S9>'   : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag
 * '<S10>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag
 * '<S11>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/03_FuSysStabPrail
 * '<S12>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/Falling_edge1
 * '<S13>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/Falling_edge2
 * '<S14>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/Falling_edge3
 * '<S15>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/Rising_edge
 * '<S16>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/01_DlyAcvDiagRun
 * '<S17>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/02_SavePFuRailRun
 * '<S18>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/03_IfGARRun
 * '<S19>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/01_DlyAcvDiagRun/UnitDly_ExtIni
 * '<S20>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/01_DlyAcvDiagRun/UnitDly_ExtIni/SubSystem1
 * '<S21>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/01_DlyAcvDiagRun/UnitDly_ExtIni/SubSystem2
 * '<S22>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/02_SavePFuRailRun/UnitDelay1
 * '<S23>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/03_IfGARRun/SingleToFixdt
 * '<S24>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakEngRunDiag/03_IfGARRun/multiplication
 * '<S25>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/01_DlyAcvDiagStall
 * '<S26>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/02_SavePFuRailStall
 * '<S27>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/03_IfGARStall
 * '<S28>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/01_DlyAcvDiagStall/UnitDly_ExtIni
 * '<S29>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/01_DlyAcvDiagStall/UnitDly_ExtIni/SubSystem1
 * '<S30>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/01_DlyAcvDiagStall/UnitDly_ExtIni/SubSystem2
 * '<S31>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/02_SavePFuRailStall/UnitDelay2
 * '<S32>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/03_IfGARStall/LookUp_1D1
 * '<S33>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/02_FuSysExtLeakEngStallDiag/03_IfGARStall/SingleToFixdt
 * '<S34>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/03_FuSysStabPrail/SubSystem
 * '<S35>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/03_FuSysStabPrail/SubSystem1
 * '<S36>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/03_FuSysStabPrail/TIMER
 * '<S37>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/03_FuSysStabPrail/TIMER/SubSystem
 * '<S38>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/03_FuSysStabPrail/TIMER/SubSystem1
 * '<S39>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/03_FuSysStabPrail/TIMER/SubSystem2
 * '<S40>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/Falling_edge1/SubSystem
 * '<S41>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/Falling_edge2/SubSystem
 * '<S42>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/Falling_edge3/SubSystem
 * '<S43>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/01_FuSysExtLeakDiag/01_FuSysExtLeakDiag/Rising_edge/SubSystem
 * '<S44>'  : FuSysExtLeakDiag_AUTOCODE/FuSysExtLeakDiag/GDGAR_vidGdu/GDGAR_vidGdu
 */

/*-
 * Requirements for '<Root>': FuSysExtLeakDiag
 *
 * Inherited requirements for '<S1>/01_FuSysExtLeakDiag':
 *  1. SubSystem "01_FuSysExtLeakDiag" !Trace_To : VEMS_E_11_02026_001.01 ;
 *
 * Inherited requirements for '<S1>/GDGAR_vidGdu':
 *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_11_02026_001.01 ;

 */
#endif                                 /* RTW_HEADER_FuSysExtLeakDiag_h_ */

/*-------------------------------- end of file -------------------------------*/
