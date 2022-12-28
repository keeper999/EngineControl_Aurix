/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : MonEngStrt                                              */
/* !Description     : Surveillance du démarrage                               */
/*                                                                            */
/* !Module          : MonEngStrt                                              */
/*                                                                            */
/* !File            : MonEngStrt.h                                            */
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
/*   Code generated on: Wed Sep 11 09:00:08 2013                              */
/*   Model name       : MonEngStrt_AUTOCODE.mdl                               */
/*   Model version    : 1.201                                                 */
/*   Root subsystem   : /MonEngStrt                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/MONENGSTRT/MonEngStrt.h_v $*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   16 Sep 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_MonEngStrt_h_
#define RTW_HEADER_MonEngStrt_h_
#ifndef MonEngStrt_COMMON_INCLUDES_
# define MonEngStrt_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "MonEngStrt_import.h"
#include "VEMS.H"
#include "GDGAR.H"
#include "rtw_shared_utils.h"
#endif                                 /* MonEngStrt_COMMON_INCLUDES_ */

#include "MonEngStrt_types.h"

/* Includes for objects with custom storage classes. */
#include "GDGAR.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define ENGST_MONSTRT_ENDED            ((UInt8) 5U)
#define ENGST_MONSTRT_IDLE             ((UInt8) 0U)
#define ENGST_MONSTRT_PFUEL            ((UInt8) 6U)
#define ENGST_MONSTRT_PRES             ((UInt8) 1U)
#define ENGST_MONSTRT_STARTED          ((UInt8) 4U)
#define ENGST_MONSTRT_SYNCHRONYZED     ((UInt8) 3U)
#define ENGST_MONSTRT_UNLOCKED         ((UInt8) 2U)

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

/* Block signals for system '<S7>/F00_autorisationDiag' */
typedef struct {
  UInt16 EngSt_tiDlyStrt_j;          /* '<S19>/F02_Etat_Diag' */
  UInt16 EngSt_tiDlyUnlockADC_p;     /* '<S19>/F02_Etat_Diag' */
  UInt16 EngSt_tiDlySync_j;          /* '<S19>/F02_Etat_Diag' */
  UInt16 EngSt_tiDlyPFuMin_a;        /* '<S19>/F02_Etat_Diag' */
  UInt8 EngSt_stMonEngStrt_e;        /* '<S19>/F02_Etat_Diag' */
  Boolean EngSt_bMonWaitORngEngSt_m; /* '<S19>/F02_Etat_Diag' */
  Boolean EngSt_bAcvStrtDiag_k;      /* '<S19>/F02_Etat_Diag' */
  UInt8 DTConv_UFix_To_Single_1;     /* '<S19>/DTConv_UFix_To_Single_1' */
} rtB_F00_autorisationDiag_MonEng;

/* Block states (auto storage) for system '<S7>/F00_autorisationDiag' */
typedef struct {
  UInt8 is_active_c1_MonEngStrt;     /* '<S19>/F02_Etat_Diag' */
  UInt8 is_c1_MonEngStrt;            /* '<S19>/F02_Etat_Diag' */
  UInt8 is_ENGST_MONSTRT_RUNNING;    /* '<S19>/F02_Etat_Diag' */
} rtDW_F00_autorisationDiag_MonEn;

/* Block signals (auto storage) */
typedef struct {
  SInt16 VEMS_vidGET2;                /* '<S21>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET1;               /* '<S21>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET3;               /* '<S16>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET3_p;             /* '<S7>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET1_l;             /* '<S15>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET;                /* '<S4>/VEMS_vidGET' */
  UInt16 VEMS_vidGET3_h;             /* '<S21>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET9;                /* '<S21>/VEMS_vidGET9' */
  UInt8 VEMS_vidGET5;                /* '<S16>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET5_c;              /* '<S7>/VEMS_vidGET5' */
  Boolean VEMS_vidGET7;              /* '<S21>/VEMS_vidGET7' */
  Boolean VEMS_vidGET4;              /* '<S21>/VEMS_vidGET4' */
  Boolean VEMS_vidGET8;              /* '<S21>/VEMS_vidGET8' */
  Boolean VEMS_vidGET_d;             /* '<S21>/VEMS_vidGET' */
  Boolean VEMS_vidGET2_b;            /* '<S16>/VEMS_vidGET2' */
  Boolean SignalConversion7;         /* '<S16>/Signal Conversion7' */
  Boolean VEMS_vidGET4_e;            /* '<S16>/VEMS_vidGET4' */
  Boolean SignalConversion8;         /* '<S16>/Signal Conversion8' */
  Boolean VEMS_vidGET7_m;            /* '<S16>/VEMS_vidGET7' */
  Boolean VEMS_vidGET8_b;            /* '<S16>/VEMS_vidGET8' */
  Boolean SignalConversion9;         /* '<S16>/Signal Conversion9' */
  Boolean VEMS_vidGET_k;             /* '<S15>/VEMS_vidGET' */
  Boolean VEMS_vidGET2_k;            /* '<S7>/VEMS_vidGET2' */
  Boolean SignalConversion7_c;       /* '<S7>/Signal Conversion7' */
  Boolean VEMS_vidGET4_b;            /* '<S7>/VEMS_vidGET4' */
  Boolean SignalConversion8_m;       /* '<S7>/Signal Conversion8' */
  Boolean VEMS_vidGET7_i;            /* '<S7>/VEMS_vidGET7' */
  Boolean VEMS_vidGET8_f;            /* '<S7>/VEMS_vidGET8' */
  Boolean SignalConversion9_b;       /* '<S7>/Signal Conversion9' */
  UInt8 EepromReadAccess;            /* '<S4>/EepromReadAccess' */
  rtB_F00_autorisationDiag_MonEng F00_autorisationDiag_a;/* '<S16>/F00_autorisationDiag' */
  rtB_F00_autorisationDiag_MonEng F00_autorisationDiag;/* '<S7>/F00_autorisationDiag' */
} BlockIO_MonEngStrt;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  rtDW_F00_autorisationDiag_MonEn F00_autorisationDiag_a;/* '<S16>/F00_autorisationDiag' */
  rtDW_F00_autorisationDiag_MonEn F00_autorisationDiag;/* '<S7>/F00_autorisationDiag' */
} D_Work_MonEngStrt;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define MONENGSTRT_START_SEC_VAR_UNSPECIFIED
#include "MonEngStrt_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_MonEngStrt MonEngStrt_B;

/* Block states (auto storage) */
extern D_Work_MonEngStrt MonEngStrt_DWork;

#define MONENGSTRT_STOP_SEC_VAR_UNSPECIFIED
#include "MonEngStrt_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define MONENGSTRT_START_SEC_CODE
#include "MonEngStrt_MemMap.h"

/* Model entry point functions */
extern void MonEngStrt_initialize(void);
extern void EngSt_SdlFast_MonEngStrt(void);
extern void EngSt_EveRst_MonEngStrt(void);

#define MONENGSTRT_STOP_SEC_CODE
#include "MonEngStrt_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define MONENGSTRT_START_SEC_CALIB_16BIT
#include "MonEngStrt_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_nEngPFuLim_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_nEngSyncLim_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_nEngUnlockADCLim_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_tiPFuMinLim_T[6];

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 30.0                                                              */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_tiStrtLim_T[6];

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_tiSyncLim_T[6];

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_tiUnlockADCLim_C;

/* Type:    UInt16                                                          */
/* Slope:   2.3583984374999999E-002                                           */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 24.15                                                             */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_uBattPFuLim_C;

/* Type:    UInt16                                                          */
/* Slope:   2.3583984374999999E-002                                           */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 24.15                                                             */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_uBattSyncLim_C;

/* Type:    UInt16                                                          */
/* Slope:   2.3583984374999999E-002                                           */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 24.15                                                             */
extern CONST(UInt16, MONENGSTRT_CALIB) EngSt_uBattThdCmdCrk_C;

#define MONENGSTRT_STOP_SEC_CALIB_16BIT
#include "MonEngStrt_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define MONENGSTRT_START_SEC_CALIB_8BIT
#include "MonEngStrt_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -50.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 150.0                                                             */
extern CONST(UInt8, MONENGSTRT_CALIB) EngSt_bkptTcoStrt_A[6];

/* Type:    UInt8                                                           */
/* Slope:   0.5                                                               */
/* Bias:    0.0                                                               */
/* Units:   L                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 127.5                                                             */
extern CONST(UInt8, MONENGSTRT_CALIB) EngSt_volFuInitMin_C;

#define MONENGSTRT_STOP_SEC_CALIB_8BIT
#include "MonEngStrt_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define MONENGSTRT_START_SEC_CALIB_BOOLEAN
#include "MonEngStrt_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, MONENGSTRT_CALIB) EngSt_bStrtDiagCf_C;

#define MONENGSTRT_STOP_SEC_CALIB_BOOLEAN
#include "MonEngStrt_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define MONENGSTRT_START_SEC_VAR_16BIT
#include "MonEngStrt_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlySync;

#define MONENGSTRT_STOP_SEC_VAR_16BIT
#include "MonEngStrt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define MONENGSTRT_START_SEC_VAR_BOOLEAN
#include "MonEngStrt_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bStrtDiagCf;

#define MONENGSTRT_STOP_SEC_VAR_BOOLEAN
#include "MonEngStrt_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S24>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S24>/x' : Unused code path elimination
 * Block '<S26>/Switch' : Eliminated due to constant selection input
 * Block '<S34>/Switch' : Eliminated due to constant selection input
 * Block '<S35>/Switch' : Eliminated due to constant selection input
 * Block '<S26>/Add3' : Unused code path elimination
 * Block '<S26>/Add4' : Unused code path elimination
 * Block '<S26>/Constant' : Unused code path elimination
 * Block '<S26>/Relational Operator' : Unused code path elimination
 * Block '<S26>/Switch1' : Unused code path elimination
 * Block '<S26>/offset2' : Unused code path elimination
 * Block '<S26>/offset3' : Unused code path elimination
 * Block '<S26>/offset4' : Unused code path elimination
 * Block '<S34>/Add3' : Unused code path elimination
 * Block '<S34>/Add4' : Unused code path elimination
 * Block '<S34>/Constant' : Unused code path elimination
 * Block '<S34>/Relational Operator' : Unused code path elimination
 * Block '<S34>/Switch1' : Unused code path elimination
 * Block '<S34>/offset2' : Unused code path elimination
 * Block '<S34>/offset3' : Unused code path elimination
 * Block '<S34>/offset4' : Unused code path elimination
 * Block '<S35>/Add3' : Unused code path elimination
 * Block '<S35>/Add4' : Unused code path elimination
 * Block '<S35>/Constant' : Unused code path elimination
 * Block '<S35>/Relational Operator' : Unused code path elimination
 * Block '<S35>/Switch1' : Unused code path elimination
 * Block '<S35>/offset2' : Unused code path elimination
 * Block '<S35>/offset3' : Unused code path elimination
 * Block '<S35>/offset4' : Unused code path elimination
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
 * hilite_system('MonEngStrt_AUTOCODE/MonEngStrt')    - opens subsystem MonEngStrt_AUTOCODE/MonEngStrt
 * hilite_system('MonEngStrt_AUTOCODE/MonEngStrt/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : MonEngStrt_AUTOCODE
 * '<S1>'   : MonEngStrt_AUTOCODE/MonEngStrt
 * '<S4>'   : MonEngStrt_AUTOCODE/MonEngStrt/F00_Init
 * '<S5>'   : MonEngStrt_AUTOCODE/MonEngStrt/F01_CmdCranking
 * '<S6>'   : MonEngStrt_AUTOCODE/MonEngStrt/F02_autorisationDiag_Fast
 * '<S7>'   : MonEngStrt_AUTOCODE/MonEngStrt/F02_autorisationDiag_Rst
 * '<S8>'   : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic
 * '<S9>'   : MonEngStrt_AUTOCODE/MonEngStrt/GDGAR_vidGdu
 * '<S10>'  : MonEngStrt_AUTOCODE/MonEngStrt/GDGAR_vidGdu1
 * '<S11>'  : MonEngStrt_AUTOCODE/MonEngStrt/GDGAR_vidGdu2
 * '<S12>'  : MonEngStrt_AUTOCODE/MonEngStrt/GDGAR_vidGdu3
 * '<S13>'  : MonEngStrt_AUTOCODE/MonEngStrt/demux_fc1
 * '<S14>'  : MonEngStrt_AUTOCODE/MonEngStrt/demux_fc2
 * '<S15>'  : MonEngStrt_AUTOCODE/MonEngStrt/F01_CmdCranking/F00_CmdCranking
 * '<S16>'  : MonEngStrt_AUTOCODE/MonEngStrt/F02_autorisationDiag_Fast/F00_autorisationDiag_Fast
 * '<S17>'  : MonEngStrt_AUTOCODE/MonEngStrt/F02_autorisationDiag_Fast/F00_autorisationDiag_Fast/F00_autorisationDiag
 * '<S18>'  : MonEngStrt_AUTOCODE/MonEngStrt/F02_autorisationDiag_Fast/F00_autorisationDiag_Fast/F00_autorisationDiag/F02_Etat_Diag
 * '<S19>'  : MonEngStrt_AUTOCODE/MonEngStrt/F02_autorisationDiag_Rst/F00_autorisationDiag
 * '<S20>'  : MonEngStrt_AUTOCODE/MonEngStrt/F02_autorisationDiag_Rst/F00_autorisationDiag/F02_Etat_Diag
 * '<S21>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic
 * '<S22>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F00_Cdn
 * '<S23>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic
 * '<S24>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/PreLookUp_Binary
 * '<S25>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F00_Cdn/Interp_1D
 * '<S26>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F00_Cdn/SingleToFixdt
 * '<S27>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F01_MonRunADC
 * '<S28>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F01_MonRunStrt
 * '<S29>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F02_MonRunSync
 * '<S30>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F03_MonRunPFu
 * '<S31>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F04_DgoStrtDiag
 * '<S32>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F04_DgoStrtDiag/Interp_1D
 * '<S33>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F04_DgoStrtDiag/Interp_1D1
 * '<S34>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F04_DgoStrtDiag/SingleToFixdt
 * '<S35>'  : MonEngStrt_AUTOCODE/MonEngStrt/F03_Diagnostic/F00_Diagnostic/F01_Diagnostic/F04_DgoStrtDiag/SingleToFixdt1
 * '<S36>'  : MonEngStrt_AUTOCODE/MonEngStrt/GDGAR_vidGdu/GDGAR_vidGdu
 * '<S37>'  : MonEngStrt_AUTOCODE/MonEngStrt/GDGAR_vidGdu1/GDGAR_vidGdu
 * '<S38>'  : MonEngStrt_AUTOCODE/MonEngStrt/GDGAR_vidGdu2/GDGAR_vidGdu
 * '<S39>'  : MonEngStrt_AUTOCODE/MonEngStrt/GDGAR_vidGdu3/GDGAR_vidGdu
 */

/*-
 * Requirements for '<Root>': MonEngStrt
 *
 * Inherited requirements for '<S1>/F00_Init':
 *  1. SubSystem "F00_Init" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  2. SubSystem "F00_Init" !Trace_To : VEMS_R_09_06162_002.02 ;
 *  3. SubSystem "F00_Init" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  4. SubSystem "F00_Init" !Trace_To : VEMS_E_09_06162_014.01 ;
 *
 * Inherited requirements for '<S1>/F01_CmdCranking':
 *  1. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_003.01 ;
 *  2. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  3. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_002.02 ;
 *  4. SubSystem "F01_CmdCranking" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  5. SubSystem "F01_CmdCranking" !Trace_To : VEMS_E_09_06162_014.01 ;
 *
 * Inherited requirements for '<S1>/F02_autorisationDiag_Fast':
 *  1. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_004.01 ;
 *  2. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_005.01 ;
 *  3. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_006.01 ;
 *  4. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_007.02 ;
 *  5. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_008.02 ;
 *  6. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_015.01 ;
 *  7. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_016.01 ;
 *  8. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_019.01 ;
 *  9. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  10. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_002.02 ;
 *  11. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  12. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_014.01 ;
 *
 * Inherited requirements for '<S1>/F02_autorisationDiag_Rst':
 *  1. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_004.01 ;
 *  2. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_005.01 ;
 *  3. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_006.01 ;
 *  4. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_007.02 ;
 *  5. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_008.02 ;
 *  6. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_015.01 ;
 *  7. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_016.01 ;
 *  8. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_019.01 ;
 *  9. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  10. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_002.02 ;
 *  11. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  12. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_014.01 ;
 *
 * Inherited requirements for '<S1>/F03_Diagnostic':
 *  1. SubSystem "F03_Diagnostic" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  2. SubSystem "F03_Diagnostic" !Trace_To : VEMS_R_09_06162_002.02 ;
 *  3. SubSystem "F03_Diagnostic" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  4. SubSystem "F03_Diagnostic" !Trace_To : VEMS_E_09_06162_014.01 ;
 *
 * Inherited requirements for '<S1>/GDGAR_vidGdu':
 *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  2. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_09_06162_002.02 ;
 *  3. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  4. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_09_06162_014.01 ;
 *
 * Inherited requirements for '<S1>/GDGAR_vidGdu1':
 *  1. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  2. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_E_09_06162_014.01 ;
 *  3. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  4. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_R_09_06162_002.02 ;
 *
 * Inherited requirements for '<S1>/GDGAR_vidGdu2':
 *  1. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  2. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_R_09_06162_002.02 ;
 *  3. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  4. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_E_09_06162_014.01 ;
 *
 * Inherited requirements for '<S1>/GDGAR_vidGdu3':
 *  1. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_E_09_06162_013.01 ;
 *  2. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_E_09_06162_014.01 ;
 *  3. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_R_09_06162_001.02 ;
 *  4. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_R_09_06162_002.02 ;

 */
#endif                                 /* RTW_HEADER_MonEngStrt_h_ */

/*-------------------------------- end of file -------------------------------*/
