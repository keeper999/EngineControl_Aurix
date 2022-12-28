/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpCtl                                                */
/* !Description     : HPPmpCtl - RÉGULATION DE LA PRESSION RAIL               */
/*                                                                            */
/* !Module          : HPPmpCtl                                                */
/*                                                                            */
/* !File            : HPPmpCtl.h                                              */
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
/*   Code generated on: Tue Jul 10 10:40:13 2012                              */
/*   Model name       : HPPmpCtl_AUTOCODE.mdl                                 */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /HPPmpCtl                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPCTL/HPPmpCtl.h_v    $*/
/* $Revision::   1.4                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPPmpCtl_h_
#define RTW_HEADER_HPPmpCtl_h_
#ifndef HPPmpCtl_COMMON_INCLUDES_
# define HPPmpCtl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "HPPmpCtl_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "ACTEMS_FloorF.h"
#endif                                 /* HPPmpCtl_COMMON_INCLUDES_ */

#include "HPPmpCtl_types.h"

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

/* Block signals for system '<S10>/F01_HPPmpCtl' */
typedef struct {
  SInt32 ConstVal;                    /* '<S11>/ConstVal' */
} rtB_F01_HPPmpCtl_HPPmpCtl;

/* Block signals (auto storage) */
typedef struct {
  UInt32 OutDTConv;                  /* '<S51>/OutDTConv' */
  SInt32 VEMS_vidGET9;                /* '<S18>/VEMS_vidGET9' */
  SInt32 OutDTConv_m;                 /* '<S29>/OutDTConv' */
  UInt16 VEMS_vidGET;                /* '<S18>/VEMS_vidGET' */
  UInt16 VEMS_vidGET4;               /* '<S18>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET1;               /* '<S18>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET2;               /* '<S18>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET5;               /* '<S18>/VEMS_vidGET5' */
  SInt16 Sub;                         /* '<S22>/Sub' */
  Boolean Merge2;                    /* '<S13>/Merge2' */
  Boolean VEMS_vidGET8;              /* '<S18>/VEMS_vidGET8' */
  Boolean VEMS_vidGET6;              /* '<S18>/VEMS_vidGET6' */
  Boolean VEMS_vidGET7;              /* '<S18>/VEMS_vidGET7' */
  Boolean VEMS_vidGET3;              /* '<S18>/VEMS_vidGET3' */
  Boolean GreaterOrEqual;            /* '<S41>/Greater Or Equal' */
  rtB_F01_HPPmpCtl_HPPmpCtl F01_HPPmpCtl_d;/* '<S7>/F01_HPPmpCtl' */
  rtB_F01_HPPmpCtl_HPPmpCtl F01_HPPmpCtl_p;/* '<S10>/F01_HPPmpCtl' */
} BlockIO_HPPmpCtl;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S34>/Unit Delay' */
  Boolean UnitDelay_DSTATE_a;        /* '<S32>/Unit Delay' */
  Boolean UnitDelay_DSTATE_o;        /* '<S33>/Unit Delay' */
} D_Work_HPPmpCtl;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define HPPMPCTL_START_SEC_VAR_UNSPECIFIED
#include "HPPmpCtl_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_HPPmpCtl HPPmpCtl_B;

/* Block states (auto storage) */
extern D_Work_HPPmpCtl HPPmpCtl_DWork;

#define HPPMPCTL_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpCtl_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define HPPMPCTL_START_SEC_CODE
#include "HPPmpCtl_MemMap.h"

/* Model entry point functions */
extern void HPPmpCtl_initialize(void);
extern void PFuCtl_SdlMid_HPPmpCtl(void);
extern void PFuCtl_EveSpl_HPPmpCtl(void);
extern void PFuCtl_EveRst_HPPmpCtl(void);
extern void PFuCtl_EveRTSt_HPPmpCtl(void);

#define HPPMPCTL_STOP_SEC_CODE
#include "HPPmpCtl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define HPPMPCTL_START_SEC_CALIB_16BIT
#include "HPPmpCtl_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, HPPMPCTL_CALIB) InjrSys_mFuInjEstim_A[7];

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    -2.0                                                              */
/* Units:   su                                                                */
/* PhysMin: -2.0                                                              */
/* PhysMax: 1.9999389648437500E+000                                           */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_facGainD1PFuCtl_T[16];

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    -2.0                                                              */
/* Units:   su                                                                */
/* PhysMin: -2.0                                                              */
/* PhysMax: 1.9999389648437500E+000                                           */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_facGainD2PFuCtl_T[16];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_facGainIPFuCtl_M[112];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_facGainPPFuCtl_M[112];

/* Type:    UInt16                                                          */
/* Units:   tr/min                                                            */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_nEng1_A[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifAcvClCtlDft_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifAcvClCtl_C;

/* Type:    SInt16                                                           */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern CONST(SInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifReqETB_C;

/* Type:    SInt16                                                           */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern CONST(SInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifStep1ETB_C;

/* Type:    SInt16                                                           */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern CONST(SInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDifStep2ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    -2.56E+007                                                        */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_pFuRailDif_A[5];

/* Type:    UInt16                                                          */
/* Slope:   390.625                                                           */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.5599609375000000E+007                                           */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_pRailRampMaxETB_C;

/* Type:    UInt16                                                          */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 32.76                                                             */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_tiPFuDifStep1ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 32.76                                                             */
extern CONST(UInt16, HPPMPCTL_CALIB) PFuCtl_tiPFuDifStep2ETB_C;

#define HPPMPCTL_STOP_SEC_CALIB_16BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPPMPCTL_START_SEC_CALIB_8BIT
#include "HPPmpCtl_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.00390625                                                        */
/* Units:   su                                                                */
/* PhysMin: 0.00390625                                                        */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, HPPMPCTL_CALIB) PFuCtl_facWErrGainPPFuCtl_T[5];

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 6.0                                                               */
extern CONST(UInt8, HPPMPCTL_CALIB) PFuCtl_noTDCPmpStk_C;

#define HPPMPCTL_STOP_SEC_CALIB_8BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define HPPMPCTL_START_SEC_CALIB_BOOLEAN
#include "HPPmpCtl_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPCTL_CALIB) PFuCtl_bAcvETBPFuClCtl_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPCTL_CALIB) PFuCtl_bAcvRstIFuRailCtl_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPCTL_CALIB) PFuCtl_bSelETBpFuRailDifReq_C;

#define HPPMPCTL_STOP_SEC_CALIB_BOOLEAN
#include "HPPmpCtl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define HPPMPCTL_START_SEC_VAR_32BIT
#include "HPPmpCtl_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    -0.0078125                                                        */
/* Units:   kg                                                                */
/* PhysMin: -0.0078125                                                        */
/* PhysMax: 0.0078125                                                         */
extern VAR(UInt32, HPPMPCTL_VAR) PFuCtl_mFuPmpReq;

/* Type:    SInt32                                                           */
/* Slope:   1.1920928955078125E-002                                           */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.5599999988079071E+007                                           */
extern VAR(SInt32, HPPMPCTL_VAR) PFuCtl_pFuRailDifIClCtl;

#define HPPMPCTL_STOP_SEC_VAR_32BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define HPPMPCTL_START_SEC_VAR_16BIT
#include "HPPmpCtl_MemMap.h"

/* Type:    SInt16                                                           */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern VAR(SInt16, HPPMPCTL_VAR) PFuCtl_pFuRailDif;

#define HPPMPCTL_STOP_SEC_VAR_16BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define HPPMPCTL_START_SEC_VAR_BOOLEAN
#include "HPPmpCtl_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, HPPMPCTL_VAR) PFuCtl_bAcvETBPFuOplCtl;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, HPPMPCTL_VAR) PFuCtl_bAcvIFrzPrailDif;

#define HPPMPCTL_STOP_SEC_VAR_BOOLEAN
#include "HPPmpCtl_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/x1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S27>/x' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S28>/x' : Unused code path elimination
 * Block '<S52>/Data Type Propagation' : Unused code path elimination
 * Block '<S52>/Data Type Propagation1' : Unused code path elimination
 * Block '<S54>/Data Type Propagation' : Unused code path elimination
 * Block '<S54>/Data Type Conversion' : Unused code path elimination
 * Block '<S54>/Data Type Conversion1' : Unused code path elimination
 * Block '<S13>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S13>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S52>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S52>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('HPPmpCtl_AUTOCODE/HPPmpCtl')    - opens subsystem HPPmpCtl_AUTOCODE/HPPmpCtl
 * hilite_system('HPPmpCtl_AUTOCODE/HPPmpCtl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : HPPmpCtl_AUTOCODE
 * '<S1>'   : HPPmpCtl_AUTOCODE/HPPmpCtl
 * '<S6>'   : HPPmpCtl_AUTOCODE/HPPmpCtl/F01_HPPmpCtl
 * '<S7>'   : HPPmpCtl_AUTOCODE/HPPmpCtl/F01_HPPmpCtl_Ini
 * '<S8>'   : HPPmpCtl_AUTOCODE/HPPmpCtl/F02_HPPmpCtl_ETB
 * '<S9>'   : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl
 * '<S10>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F01_HPPmpCtl/F01_HPPmpCtl
 * '<S11>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F01_HPPmpCtl/F01_HPPmpCtl/F01_HPPmpCtl
 * '<S12>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F01_HPPmpCtl_Ini/F01_HPPmpCtl
 * '<S13>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F02_HPPmpCtl_ETB/F02_HPPmpCtl_ETB
 * '<S14>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F02_HPPmpCtl_ETB/F02_HPPmpCtl_ETB/F01_PFuOplCtl_Clcn
 * '<S15>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F02_HPPmpCtl_ETB/F02_HPPmpCtl_ETB/F02_PFuOplCtl_Ini
 * '<S16>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F02_HPPmpCtl_ETB/F02_HPPmpCtl_ETB/F01_PFuOplCtl_Clcn/Slew_rate_clamper
 * '<S17>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F02_HPPmpCtl_ETB/F02_HPPmpCtl_ETB/F01_PFuOplCtl_Clcn/multiplication_411
 * '<S18>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl
 * '<S19>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl
 * '<S20>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F02_MFuPmpClcn
 * '<S21>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F01_PFuRailClCtlIni
 * '<S22>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F02_pFuRailDifClcn
 * '<S23>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F03_P
 * '<S24>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F04_I
 * '<S25>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F05_D
 * '<S26>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F06_pFuRailDifClCtlClcn
 * '<S27>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/PreLookUp_Binary
 * '<S28>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/PreLookUp_Binary1
 * '<S29>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/SingleToFixdt
 * '<S30>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F01_PFuRailClCtlIni/falling_edge
 * '<S31>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F01_PFuRailClCtlIni/rising_edge
 * '<S32>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F01_PFuRailClCtlIni/falling_edge/SubSystem
 * '<S33>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F01_PFuRailClCtlIni/rising_edge/SubSystem
 * '<S34>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F02_pFuRailDifClcn/UnitDelay1
 * '<S35>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F03_P/Interp_2D
 * '<S36>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F03_P/LookUp_1D
 * '<S37>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F03_P/SingleToFixdt1
 * '<S38>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F03_P/multiplication_411
 * '<S39>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F03_P/multiplication_421
 * '<S40>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F04_I/F01_IIni
 * '<S41>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F04_I/F02_IClcn
 * '<S42>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F04_I/F02_IClcn/Interp_2D
 * '<S43>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F04_I/F02_IClcn/SingleToFixdt
 * '<S44>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F04_I/F02_IClcn/multiplication_431
 * '<S45>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F05_D/F01_DIni
 * '<S46>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F05_D/F02_DClcn
 * '<S47>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F05_D/F02_DClcn/Interp_1D
 * '<S48>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F05_D/F02_DClcn/Interp_1D1
 * '<S49>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F05_D/F02_DClcn/multiplication_441
 * '<S50>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F01_PFuRailClCtl/F05_D/F02_DClcn/multiplication_451
 * '<S51>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F02_MFuPmpClcn/SingleToFixdt
 * '<S52>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F02_MFuPmpClcn/Subsystem
 * '<S53>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F02_MFuPmpClcn/multiplication_461
 * '<S54>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F02_MFuPmpClcn/Subsystem/Data Type Police Only single
 * '<S55>'  : HPPmpCtl_AUTOCODE/HPPmpCtl/F03_HPPmpCtl/F03_HPPmpCtl/F02_MFuPmpClcn/Subsystem/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': HPPmpCtl
 *
 * Inherited requirements for '<S1>/F01_HPPmpCtl':
 *  1. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_04161_001.01 ;
 *  2. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_04161_002.01 ;
 *  3. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_04161_003.01 ;
 *  4. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_001.01 ;
 *  5. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_002.01 ;
 *  6. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_003.01 ;
 *  7. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_004.01 ;
 *  8. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_005.01 ;
 *  9. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_006.01 ;
 *  10. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_007.01 ;
 *  11. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_009.01 ;
 *  12. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_008.01 ;
 *  13. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_2880_012.01 ;
 *  14. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_2880_013.01 ;
 *  15. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_2880_041.01 ;
 *
 * Inherited requirements for '<S1>/F01_HPPmpCtl_Ini':
 *  1. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_04161_001.01 ;
 *  2. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_04161_002.01 ;
 *  3. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_04161_003.01 ;
 *  4. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_001.01 ;
 *  5. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_002.01 ;
 *  6. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_003.01 ;
 *  7. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_004.01 ;
 *  8. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_005.01 ;
 *  9. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_006.01 ;
 *  10. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_007.01 ;
 *  11. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_009.01 ;
 *  12. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_008.01 ;
 *  13. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_2880_012.01 ;
 *  14. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_2880_013.01 ;
 *  15. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_2880_041.01 ;
 *
 * Inherited requirements for '<S1>/F02_HPPmpCtl_ETB':
 *  1. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_04161_001.01 ;
 *  2. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_04161_002.01 ;
 *  3. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_04161_003.01 ;
 *  4. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_001.01 ;
 *  5. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_002.01 ;
 *  6. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_003.01 ;
 *  7. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_004.01 ;
 *  8. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_005.01 ;
 *  9. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_006.01 ;
 *  10. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_007.01 ;
 *  11. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_008.01 ;
 *  12. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_009.01 ;
 *  13. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_2880_012.01 ;
 *  14. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_2880_013.01 ;
 *  15. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_2880_041.01 ;
 *
 * Inherited requirements for '<S1>/F03_HPPmpCtl':
 *  1. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_04161_001.01 ;
 *  2. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_04161_002.01 ;
 *  3. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_04161_003.01 ;
 *  4. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_001.01 ;
 *  5. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_002.01 ;
 *  6. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_003.01 ;
 *  7. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_004.01 ;
 *  8. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_005.01 ;
 *  9. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_006.01 ;
 *  10. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_007.01 ;
 *  11. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_008.01 ;
 *  12. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_009.01 ;
 *  13. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_2880_012.01 ;
 *  14. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_2880_013.01 ;
 *  15. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_2880_041.01 ;

 */
#endif                                 /* RTW_HEADER_HPPmpCtl_h_ */

/*-------------------------------- end of file -------------------------------*/
