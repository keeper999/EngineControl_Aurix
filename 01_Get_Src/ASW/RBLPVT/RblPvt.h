/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : RblPvt                                                  */
/* !Description     : RUMBLE PREVENTION                                       */
/*                                                                            */
/* !Module          : RblPvt                                                  */
/*                                                                            */
/* !File            : RblPvt.h                                                */
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
/*   Code generated on: Thu Dec 13 15:30:24 2012                              */
/*   Model name       : RblPvt_AUTOCODE.mdl                                   */
/*   Model version    : 1.23                                                  */
/*   Root subsystem   : /RblPvt                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/RblPvt/5-SOFT-LIV/RblPvt.h_v$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   14 Dec 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_RblPvt_h_
#define RTW_HEADER_RblPvt_h_
#ifndef RblPvt_COMMON_INCLUDES_
# define RblPvt_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "RblPvt_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "ACTEMS_FloorF.h"
#include "rt_MAXf.h"
#include "rt_MINf.h"
#endif                                 /* RblPvt_COMMON_INCLUDES_ */

#include "RblPvt_types.h"

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
  UInt16 VEMS_vidGET1;               /* '<S6>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET;                /* '<S6>/VEMS_vidGET' */
  UInt16 VEMS_vidGET2;               /* '<S6>/VEMS_vidGET2' */
  SInt16 VEMS_vidGET3;                /* '<S6>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET4;               /* '<S6>/VEMS_vidGET4' */
  Boolean Merge;                     /* '<S8>/Merge' */
  Boolean Merge_a;                   /* '<S9>/Merge' */
} BlockIO_RblPvt;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S20>/Unit Delay' */
  Float32 UnitDelay_DSTATE_b;         /* '<S19>/Unit Delay' */
} D_Work_RblPvt;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define RBLPVT_START_SEC_VAR_UNSPECIFIED
#include "RblPvt_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_RblPvt RblPvt_B;

/* Block states (auto storage) */
extern D_Work_RblPvt RblPvt_DWork;

#define RBLPVT_STOP_SEC_VAR_UNSPECIFIED
#include "RblPvt_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define RBLPVT_START_SEC_CODE
#include "RblPvt_MemMap.h"

/* Model entry point functions */
extern void RblPvt_initialize(void);
extern void KnkTreat_SdlSlow_RblPvt(void);
extern void KnkTreat_EveRst_RblPvt(void);

#define RBLPVT_STOP_SEC_CODE
#include "RblPvt_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define RBLPVT_START_SEC_CALIB_16BIT
#include "RblPvt_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, RBLPVT_CALIB) KnkMgt_ctRblIrvLdLimPvtHiThd_C;

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, RBLPVT_CALIB) KnkMgt_ctRbllrvLdLimPvtLoThd_C;

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, RBLPVT_CALIB) KnkMgt_ctToilRblIrvLdLimHiThd_C;

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, RBLPVT_CALIB) KnkMgt_ctToilRbllrvLdLimLoThd_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, RBLPVT_CALIB) KnkMgt_pDsThrMes_A[9];

/* Type:    SInt16                                                           */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 200.0                                                             */
extern CONST(SInt16, RBLPVT_CALIB) KnkMgt_tOilMesHi_C;

/* Type:    SInt16                                                           */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 200.0                                                             */
extern CONST(SInt16, RBLPVT_CALIB) KnkMgt_tOilMesLo_C;

#define RBLPVT_STOP_SEC_CALIB_16BIT
#include "RblPvt_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define RBLPVT_START_SEC_CALIB_8BIT
#include "RblPvt_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -10.0                                                             */
/* Units:   su                                                                */
/* PhysMin: -10.0                                                             */
/* PhysMax: 10.0                                                              */
extern CONST(UInt8, RBLPVT_CALIB) KnkMgt_ctTotRblPvtInc_M[81];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -10.0                                                             */
/* Units:   su                                                                */
/* PhysMin: -10.0                                                             */
/* PhysMax: 10.0                                                              */
extern CONST(UInt8, RBLPVT_CALIB) KnkMgt_ctTotRblPvtToilH_M[81];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -10.0                                                             */
/* Units:   su                                                                */
/* PhysMin: -10.0                                                             */
/* PhysMax: 10.0                                                              */
extern CONST(UInt8, RBLPVT_CALIB) KnkMgt_ctTotRblPvtToilL_M[81];

#define RBLPVT_STOP_SEC_CALIB_8BIT
#include "RblPvt_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define RBLPVT_START_SEC_VAR_BOOLEAN
#include "RblPvt_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, RBLPVT_VAR) KnkMgt_bAcvIrvLdLimRblPvtReq;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, RBLPVT_VAR) KnkMgt_bAcvIrvLdLimToilReq;

#define RBLPVT_STOP_SEC_VAR_BOOLEAN
#include "RblPvt_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Relational Operator' : Unused code path elimination
 * Block '<S21>/Relational Operator1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S13>/x' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S14>/x' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S15>/x' : Unused code path elimination
 * Block '<S18>/Data Type Propagation' : Unused code path elimination
 * Block '<S18>/Data Type Propagation1' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S29>/Data Type Conversion' : Unused code path elimination
 * Block '<S29>/Data Type Conversion1' : Unused code path elimination
 * Block '<S22>/Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Switch' : Eliminated due to constant selection input
 * Block '<S17>/Switch' : Eliminated due to constant selection input
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S16>/Add3' : Unused code path elimination
 * Block '<S16>/Add4' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S16>/Relational Operator' : Unused code path elimination
 * Block '<S16>/Switch1' : Unused code path elimination
 * Block '<S16>/offset2' : Unused code path elimination
 * Block '<S16>/offset3' : Unused code path elimination
 * Block '<S16>/offset4' : Unused code path elimination
 * Block '<S17>/Add3' : Unused code path elimination
 * Block '<S17>/Add4' : Unused code path elimination
 * Block '<S17>/Constant' : Unused code path elimination
 * Block '<S17>/Relational Operator' : Unused code path elimination
 * Block '<S17>/Switch1' : Unused code path elimination
 * Block '<S17>/offset2' : Unused code path elimination
 * Block '<S17>/offset3' : Unused code path elimination
 * Block '<S17>/offset4' : Unused code path elimination
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
 * hilite_system('RblPvt_AUTOCODE/RblPvt')    - opens subsystem RblPvt_AUTOCODE/RblPvt
 * hilite_system('RblPvt_AUTOCODE/RblPvt/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : RblPvt_AUTOCODE
 * '<S1>'   : RblPvt_AUTOCODE/RblPvt
 * '<S4>'   : RblPvt_AUTOCODE/RblPvt/01_RblPvt_init
 * '<S5>'   : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc
 * '<S6>'   : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc
 * '<S7>'   : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/BaryCentre_VEMS
 * '<S8>'   : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Hysteresis
 * '<S9>'   : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Hysteresis1
 * '<S10>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Interp_2D
 * '<S11>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Interp_2D1
 * '<S12>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Interp_2D2
 * '<S13>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/PreLookUp_Binary
 * '<S14>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/PreLookUp_Binary1
 * '<S15>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/PreLookUp_Binary2
 * '<S16>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/SingleToFixdt
 * '<S17>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/SingleToFixdt1
 * '<S18>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Subsystem
 * '<S19>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/VEMS_UnitDelay
 * '<S20>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/VEMS_UnitDelay1
 * '<S21>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/BaryCentre_VEMS/Clamp
 * '<S22>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S23>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S24>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S25>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Hysteresis/If Action Subsystem
 * '<S26>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Hysteresis/If Action Subsystem1
 * '<S27>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Hysteresis1/If Action Subsystem
 * '<S28>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Hysteresis1/If Action Subsystem1
 * '<S29>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Subsystem/Data Type Police Only single
 * '<S30>'  : RblPvt_AUTOCODE/RblPvt/02_RblPvt_calc/02_RblPvt_calc/Subsystem/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': RblPvt
 */
#endif                                 /* RTW_HEADER_RblPvt_h_ */

/*-------------------------------- end of file -------------------------------*/
