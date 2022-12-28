/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : FuRailCtlMgr                                            */
/* !Description     : FuRailCtlMgr- RAIL PRESSURE CONTROL MANAGER             */
/*                                                                            */
/* !Module          : FuRailCtlMgr                                            */
/*                                                                            */
/* !File            : FuRailCtlMgr.h                                          */
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
/*   Code generated on: Wed Dec 19 10:34:55 2012                              */
/*   Model name       : FuRailCtlMgr_AUTOCODE.mdl                             */
/*   Model version    : 1.333                                                 */
/*   Root subsystem   : /FuRailCtlMgr                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/FuRailCtlMgr/5-SOFT-LIV/FuRa$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   19 Dec 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_FuRailCtlMgr_h_
#define RTW_HEADER_FuRailCtlMgr_h_
#ifndef FuRailCtlMgr_COMMON_INCLUDES_
# define FuRailCtlMgr_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "FuRailCtlMgr_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#endif                                 /* FuRailCtlMgr_COMMON_INCLUDES_ */

#include "FuRailCtlMgr_types.h"

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

/* Block signals for system '<S17>/F01_F00_FuRailCtlMgr_init' */
typedef struct {
  Boolean SignalConversion;          /* '<S18>/Signal Conversion' */
  Boolean SignalConversion1;         /* '<S18>/Signal Conversion1' */
} rtB_F01_F00_FuRailCtlMgr_init_F;

/* Block signals for system '<S38>/F04_FirstSplEveRst' */
typedef struct {
  Boolean ConstVal;                  /* '<S39>/ConstVal' */
  Boolean ConstVal_1;                /* '<S39>/ConstVal_1' */
} rtB_F04_FirstSplEveRst_FuRailCt;

/* Block signals (auto storage) */
typedef struct {
  SInt16 VEMS_vidGET5;                /* '<S20>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET2;               /* '<S40>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET4;               /* '<S40>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5_l;             /* '<S40>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET4_i;             /* '<S20>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET1;                /* '<S20>/VEMS_vidGET1' */
  Boolean VEMS_vidGET3;              /* '<S40>/VEMS_vidGET3' */
  Boolean VEMS_vidGET1_g;            /* '<S40>/VEMS_vidGET1' */
  Boolean VEMS_vidGET;               /* '<S40>/VEMS_vidGET' */
  Boolean VEMS_vidGET6;              /* '<S40>/VEMS_vidGET6' */
  Boolean Merge;                     /* '<S40>/Merge' */
  Boolean VEMS_vidGET8;              /* '<S20>/VEMS_vidGET8' */
  Boolean VEMS_vidGET7;              /* '<S20>/VEMS_vidGET7' */
  Boolean VEMS_vidGET_j;             /* '<S20>/VEMS_vidGET' */
  Boolean VEMS_vidGET6_n;            /* '<S20>/VEMS_vidGET6' */
  Boolean VEMS_vidGET2_f;            /* '<S20>/VEMS_vidGET2' */
  Boolean VEMS_vidGET3_p;            /* '<S20>/VEMS_vidGET3' */
  Boolean VEMS_vidGET10;             /* '<S20>/VEMS_vidGET10' */
  Boolean VEMS_vidGET9;              /* '<S20>/VEMS_vidGET9' */
  Boolean Merge_m;                   /* '<S33>/Merge' */
  Boolean LogicalOperator8;          /* '<S22>/Logical Operator8' */
  Boolean LogicalOperator9;          /* '<S22>/Logical Operator9' */
  rtB_F04_FirstSplEveRst_FuRailCt F04_FirstSplEveRst_l;/* '<S11>/F04_FirstSplEveRst' */
  rtB_F01_F00_FuRailCtlMgr_init_F F01_F00_FuRailCtlMgr_init_a;/* '<S8>/F01_F00_FuRailCtlMgr_init' */
  rtB_F04_FirstSplEveRst_FuRailCt F04_FirstSplEveRst_p;/* '<S38>/F04_FirstSplEveRst' */
  rtB_F01_F00_FuRailCtlMgr_init_F F01_F00_FuRailCtlMgr_init_k;/* '<S17>/F01_F00_FuRailCtlMgr_init' */
} BlockIO_FuRailCtlMgr;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Boolean UnitDelay;                 /* '<S44>/UnitDelay' */
  Boolean UnitDelay_m;               /* '<S44>/UnitDelay1' */
  SInt8 If_ActiveSubsystem;           /* '<S40>/If' */
  Boolean F05_FuRailCtlMgr_conti_MODE[2];/* '<S1>/F05_FuRailCtlMgr_conti' */
  Boolean F05_F00_FuRailCtlMgr_conti_MODE;/* '<S13>/F05_F00_FuRailCtlMgr_conti' */
} D_Work_FuRailCtlMgr;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S44>/Logic'
   */
  Boolean Logic_table[16];
} ConstParam_FuRailCtlMgr;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define FURAILCTLMGR_START_SEC_VAR_UNSPECIFIED
#include "FuRailCtlMgr_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_FuRailCtlMgr FuRailCtlMgr_B;

/* Block states (auto storage) */
extern D_Work_FuRailCtlMgr FuRailCtlMgr_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_FuRailCtlMgr FuRailCtlMgr_ConstP;

#define FURAILCTLMGR_STOP_SEC_VAR_UNSPECIFIED
#include "FuRailCtlMgr_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define FURAILCTLMGR_START_SEC_CODE
#include "FuRailCtlMgr_MemMap.h"

/* Model entry point functions */
extern void FuRailCtlMgr_initialize(void);
extern void PFuCtl_SdlFast_FuRailCtlMgr(void);
extern void PFuCtl_SdlFast_FuRailCtlMgr_Enable(void);
extern void PFuCtl_SdlFast_FuRailCtlMgr_Disable(void);
extern void PFuCtl_EveStTR_FuRailCtlMgr(void);
extern void PFuCtl_EveSpl_FuRailCtlMgr(void);
extern void PFuCtl_EveSpl_FuRailCtlMgr_Enable(void);
extern void PFuCtl_EveSpl_FuRailCtlMgr_Disable(void);
extern void PFuCtl_EveRst_FuRailCtlMgr(void);
extern void PFuCtl_EveRTSt_FuRailCtlMgr(void);

#define FURAILCTLMGR_STOP_SEC_CODE
#include "FuRailCtlMgr_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define FURAILCTLMGR_START_SEC_CALIB_16BIT
#include "FuRailCtlMgr_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailLoThdInhClCtl_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModHSTT_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModH_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModSSTT_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModS_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlModSpl_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, FURAILCTLMGR_CALIB) PFuCtl_pFuRailThdAcvCtlSplSTT_T[16];

#define FURAILCTLMGR_STOP_SEC_CALIB_16BIT
#include "FuRailCtlMgr_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define FURAILCTLMGR_START_SEC_CALIB_8BIT
#include "FuRailCtlMgr_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, FURAILCTLMGR_CALIB) Ext_tCoMes_A[16];

#define FURAILCTLMGR_STOP_SEC_CALIB_8BIT
#include "FuRailCtlMgr_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define FURAILCTLMGR_START_SEC_CALIB_BOOLEAN
#include "FuRailCtlMgr_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FURAILCTLMGR_CALIB) PFuCtl_bAcvHPPmpCutOff_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FURAILCTLMGR_CALIB) PFuCtl_bAcvLPCmdContns_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FURAILCTLMGR_CALIB) PFuCtl_bAcvPFuCtlCrk_C;

#define FURAILCTLMGR_STOP_SEC_CALIB_BOOLEAN
#include "FuRailCtlMgr_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define FURAILCTLMGR_START_SEC_VAR_BOOLEAN
#include "FuRailCtlMgr_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, FURAILCTLMGR_VAR) PFuCtl_bAcvCmdContnsReq;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, FURAILCTLMGR_VAR) PFuCtl_bAcvPFuCtl;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, FURAILCTLMGR_VAR) PFuCtl_bEveFirstSpl;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, FURAILCTLMGR_VAR) PFuCtl_bInhPFuCtl;

#define FURAILCTLMGR_STOP_SEC_VAR_BOOLEAN
#include "FuRailCtlMgr_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S23>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S23>/x' : Unused code path elimination
 * Block '<S44>/LO3' : Unused code path elimination
 * Block '<S26>/Switch' : Eliminated due to constant selection input
 * Block '<S22>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S26>/Add3' : Unused code path elimination
 * Block '<S26>/Add4' : Unused code path elimination
 * Block '<S26>/Constant' : Unused code path elimination
 * Block '<S26>/Relational Operator' : Unused code path elimination
 * Block '<S26>/Switch1' : Unused code path elimination
 * Block '<S26>/offset2' : Unused code path elimination
 * Block '<S26>/offset3' : Unused code path elimination
 * Block '<S26>/offset4' : Unused code path elimination
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
 * hilite_system('FuRailCtlMgr_AUTOCODE/FuRailCtlMgr')    - opens subsystem FuRailCtlMgr_AUTOCODE/FuRailCtlMgr
 * hilite_system('FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : FuRailCtlMgr_AUTOCODE
 * '<S1>'   : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr
 * '<S7>'   : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F01_FuRailCtlMgr_init
 * '<S8>'   : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F01_FuRailCtlMgr_init_inhibition
 * '<S9>'   : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn
 * '<S10>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F03_FirstSplEveAcv
 * '<S11>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F04_FirstSplEveRst
 * '<S12>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F04_FirstSplEveRst_inhibition
 * '<S13>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F05_FuRailCtlMgr_conti
 * '<S14>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/demux_fc
 * '<S15>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/demux_fc1
 * '<S16>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/demux_fc3
 * '<S17>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F01_FuRailCtlMgr_init/F01_F00_FuRailCtlMgr_init
 * '<S18>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F01_FuRailCtlMgr_init/F01_F00_FuRailCtlMgr_init/F01_F00_FuRailCtlMgr_init
 * '<S19>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F01_FuRailCtlMgr_init_inhibition/F01_F00_FuRailCtlMgr_init
 * '<S20>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn
 * '<S21>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd
 * '<S22>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F02_pFuRailClCtl
 * '<S23>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/Ext_tCoMes_A_PreLookUp
 * '<S24>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/F01_pFuRailThdSTT
 * '<S25>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/F02_pFuRailThd
 * '<S26>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/SingleToFixdt
 * '<S27>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/F01_pFuRailThdSTT/PFuCtl_pFuRailThdAcvCtlModHSTT_T
 * '<S28>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/F01_pFuRailThdSTT/PFuCtl_pFuRailThdAcvCtlModSSTT_T
 * '<S29>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/F01_pFuRailThdSTT/PFuCtl_pFuRailThdAcvCtlSplSTT_T
 * '<S30>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/F02_pFuRailThd/PFuCtl_pFuRailThdAcvCtlModH_T
 * '<S31>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/F02_pFuRailThd/PFuCtl_pFuRailThdAcvCtlModS_T
 * '<S32>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F01_pFuRailThd/F02_pFuRailThd/PFuCtl_pFuRailThdAcvCtlModSpl_T
 * '<S33>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F02_pFuRailClCtl/Hysteresis1
 * '<S34>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F02_pFuRailClCtl/Hysteresis1/If Action Subsystem
 * '<S35>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F02_FuRailCtlMgr_clcn/F02_F00_FuRailCtlMgr_clcn/F02_pFuRailClCtl/Hysteresis1/If Action Subsystem1
 * '<S36>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F03_FirstSplEveAcv/F03_F00_FirstSplEveAcv
 * '<S37>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F04_FirstSplEveRst/F04_FirstSplEveRst
 * '<S38>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F04_FirstSplEveRst_inhibition/F04_F00_FirstSplEveRst
 * '<S39>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F04_FirstSplEveRst_inhibition/F04_F00_FirstSplEveRst/F04_FirstSplEveRst
 * '<S40>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F05_FuRailCtlMgr_conti/F05_F00_FuRailCtlMgr_conti
 * '<S41>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F05_FuRailCtlMgr_conti/F05_F00_FuRailCtlMgr_conti/F01_Activation
 * '<S42>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F05_FuRailCtlMgr_conti/F05_F00_FuRailCtlMgr_conti/F02_Deactivation
 * '<S43>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F05_FuRailCtlMgr_conti/F05_F00_FuRailCtlMgr_conti/F01_Activation/NegHys
 * '<S44>'  : FuRailCtlMgr_AUTOCODE/FuRailCtlMgr/F05_FuRailCtlMgr_conti/F05_F00_FuRailCtlMgr_conti/F01_Activation/NegHys/BasculeRS
 */

/*-
 * Requirements for '<Root>': FuRailCtlMgr
 *
 * Inherited requirements for '<S1>/F01_FuRailCtlMgr_init':
 *  1. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_002.01 ;
 *  2. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_001.01 ;
 *  3. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_003.01 ;
 *  4. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_004.01 ;
 *  5. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_005.01 ;
 *  6. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_006.01 ;
 *
 * Inherited requirements for '<S1>/F01_FuRailCtlMgr_init_inhibition':
 *  1. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_002.01 ;
 *  2. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_001.01 ;
 *  3. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_003.01 ;
 *  4. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_004.01 ;
 *  5. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_005.01 ;
 *  6. SubSystem "F01_FuRailCtlMgr_init" !Trace_To : VEMS_E_10_04153_006.01 ;
 *
 * Inherited requirements for '<S1>/F02_FuRailCtlMgr_clcn':
 *  1. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_002.01 ;
 *  2. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_001.01 ;
 *  3. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_003.01 ;
 *  4. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_004.01 ;
 *  5. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_005.01 ;
 *  6. SubSystem "F02_FuRailCtlMgr_clcn" !Trace_To : VEMS_E_10_04153_006.01 ;
 *
 * Inherited requirements for '<S1>/F03_FirstSplEveAcv':
 *  1. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_002.01 ;
 *  2. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_001.01 ;
 *  3. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_003.01 ;
 *  4. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_004.01 ;
 *  5. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_005.01 ;
 *  6. SubSystem "F03_FirstSplEveAcv" !Trace_To : VEMS_E_10_04153_006.01 ;
 *
 * Inherited requirements for '<S1>/F04_FirstSplEveRst':
 *  1. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_002.01 ;
 *  2. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_001.01 ;
 *  3. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_003.01 ;
 *  4. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_004.01 ;
 *  5. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_005.01 ;
 *  6. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_006.01 ;
 *
 * Inherited requirements for '<S1>/F04_FirstSplEveRst_inhibition':
 *  1. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_002.01 ;
 *  2. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_001.01 ;
 *  3. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_003.01 ;
 *  4. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_004.01 ;
 *  5. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_005.01 ;
 *  6. SubSystem "F04_FirstSplEveRst" !Trace_To : VEMS_E_10_04153_006.01 ;
 *
 * Inherited requirements for '<S1>/F05_FuRailCtlMgr_conti':
 *  1. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_002.01 ;
 *  2. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_001.01 ;
 *  3. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_003.01 ;
 *  4. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_004.01 ;
 *  5. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_005.01 ;
 *  6. SubSystem "F05_FuRailCtlMgr_conti" !Trace_To : VEMS_E_10_04153_006.01 ;

 */
#endif                                 /* RTW_HEADER_FuRailCtlMgr_h_ */

/*-------------------------------- end of file -------------------------------*/
