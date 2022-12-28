/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuSpCrk                                                */
/* !Description     : INJECTED FUEL MASS SET POINT DURING CRANKING            */
/*                                                                            */
/* !Module          : mFuSpCrk                                                */
/*                                                                            */
/* !File            : mFuSpCrk.h                                              */
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
/*   Code generated on: Sun Jun 02 16:30:57 2013                              */
/*   Model name       : mFuSpCrk_AUTOCODE.mdl                                 */
/*   Model version    : 1.387                                                 */
/*   Root subsystem   : /mFuSpCrk                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUSPCRK/mFuSpCrk.h_v     $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   HHAMLAOU                               $$Date::   03 Jul 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_mFuSpCrk_h_
#define RTW_HEADER_mFuSpCrk_h_
#ifndef mFuSpCrk_COMMON_INCLUDES_
# define mFuSpCrk_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "mFuSpCrk_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MAXf.h"
#endif                                 /* mFuSpCrk_COMMON_INCLUDES_ */

#include "mFuSpCrk_types.h"

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

/* Block signals for system '<S9>/F01_mFuFacCorRstrtSTT_Reusable' */
typedef struct {
  Float32 Switch;                     /* '<S28>/Switch' */
} rtB_F01_mFuFacCorRstrtSTT_Reusa;

/* Block signals (auto storage) */
typedef struct {
  Float32 Merge3;                     /* '<S7>/Merge3' */
  UInt32 VEMS_vidGET2;               /* '<S43>/VEMS_vidGET2' */
  UInt32 VEMS_vidGET1;               /* '<S43>/VEMS_vidGET1' */
  SInt16 VEMS_vidGET6;                /* '<S98>/VEMS_vidGET6' */
  SInt16 VEMS_vidGET6_d;              /* '<S69>/VEMS_vidGET6' */
  SInt16 VEMS_vidGET4;                /* '<S16>/VEMS_vidGET4' */
  SInt16 VEMS_vidGET4_l;              /* '<S46>/VEMS_vidGET4' */
  SInt16 VEMS_vidGET4_h;              /* '<S43>/VEMS_vidGET4' */
  SInt16 VEMS_vidGET4_b;              /* '<S9>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET3;               /* '<S16>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET3_f;             /* '<S9>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET4_bo;            /* '<S98>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET4_e;             /* '<S69>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET2_n;             /* '<S46>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET5;               /* '<S98>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET5_m;             /* '<S69>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET3_a;             /* '<S46>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET10;              /* '<S98>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET10_g;            /* '<S69>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET5_l;             /* '<S16>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET6_i;             /* '<S46>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET5_i;             /* '<S9>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET7;               /* '<S98>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET7_i;             /* '<S69>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET5_mw;            /* '<S46>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET2_i;             /* '<S16>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET2_o;             /* '<S9>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET12;              /* '<S98>/VEMS_vidGET12' */
  UInt16 Merge;                      /* '<S99>/Merge' */
  UInt16 Merge_n;                    /* '<S70>/Merge' */
  UInt16 Switch1;                    /* '<S46>/Switch1' */
  UInt8 VEMS_vidGET3_d;              /* '<S98>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET2_p;              /* '<S98>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET3_e;              /* '<S69>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET2_j;              /* '<S69>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET1_b;              /* '<S16>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET1_p;              /* '<S9>/VEMS_vidGET1' */
  Boolean VEMS_vidGET8;              /* '<S98>/VEMS_vidGET8' */
  Boolean VEMS_vidGET9;              /* '<S98>/VEMS_vidGET9' */
  Boolean VEMS_vidGET1_e;            /* '<S98>/VEMS_vidGET1' */
  Boolean VEMS_vidGET;               /* '<S98>/VEMS_vidGET' */
  Boolean VEMS_vidGET8_i;            /* '<S69>/VEMS_vidGET8' */
  Boolean VEMS_vidGET9_o;            /* '<S69>/VEMS_vidGET9' */
  Boolean VEMS_vidGET1_k;            /* '<S69>/VEMS_vidGET1' */
  Boolean VEMS_vidGET_p;             /* '<S69>/VEMS_vidGET' */
  Boolean VEMS_vidGET_f;             /* '<S16>/VEMS_vidGET' */
  Boolean VEMS_vidGET1_g;            /* '<S46>/VEMS_vidGET1' */
  Boolean VEMS_vidGET_g;             /* '<S46>/VEMS_vidGET' */
  Boolean VEMS_vidGET_l;             /* '<S43>/VEMS_vidGET' */
  Boolean VEMS_vidGET3_b;            /* '<S43>/VEMS_vidGET3' */
  Boolean VEMS_vidGET_h;             /* '<S9>/VEMS_vidGET' */
  rtB_F01_mFuFacCorRstrtSTT_Reusa F01_mFuFacCorRstrtSTT_Reusabl_g;/* '<S16>/F01_mFuFacCorRstrtSTT_Reusable' */
  rtB_F01_mFuFacCorRstrtSTT_Reusa F01_mFuFacCorRstrtSTT_Reusabl_d;/* '<S9>/F01_mFuFacCorRstrtSTT_Reusable' */
} BlockIO_mFuSpCrk;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 UnitDelay_DSTATE;            /* '<S129>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_d;          /* '<S97>/Unit Delay' */
  SInt8 If_ActiveSubsystem;           /* '<S98>/If' */
  SInt8 If_ActiveSubsystem_e;         /* '<S99>/If' */
  SInt8 If_ActiveSubsystem_h;         /* '<S69>/If' */
  SInt8 If_ActiveSubsystem_ev;        /* '<S70>/If' */
} D_Work_mFuSpCrk;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S33>/Lookup Table (n-D)'
   *   '<S22>/Lookup Table (n-D)'
   */
  UInt32 pooled5[2];
} ConstParam_mFuSpCrk;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define MFUSPCRK_START_SEC_VAR_UNSPECIFIED
#include "mFuSpCrk_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_mFuSpCrk mFuSpCrk_B;

/* Block states (auto storage) */
extern D_Work_mFuSpCrk mFuSpCrk_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_mFuSpCrk mFuSpCrk_ConstP;

#define MFUSPCRK_STOP_SEC_VAR_UNSPECIFIED
#include "mFuSpCrk_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define MFUSPCRK_START_SEC_CODE
#include "mFuSpCrk_MemMap.h"

/* Model entry point functions */
extern void mFuSpCrk_initialize(void);
extern void InjSys_EveInj_mFuSpCrk(void);
extern void InjSys_SdlFast_mFuSpCrk(void);
extern void InjSys_EveRTCr_mFuSpCrk(void);
extern void InjSys_EveStTR_mFuSpCrk(void);
extern void InjSys_EveKOn_mFuSpCrk(void);
extern void InjSys_EveRst_mFuSpCrk(void);

#define MFUSPCRK_STOP_SEC_CODE
#include "mFuSpCrk_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define MFUSPCRK_START_SEC_CALIB_32BIT
#include "mFuSpCrk_MemMap.h"

/* Type:    UInt32                                                          */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 864000.0                                                          */
extern CONST(UInt32, MFUSPCRK_CALIB) EOM_tiEngStopRst_A[9];

/* Type:    UInt32                                                          */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 864000.0                                                          */
extern CONST(UInt32, MFUSPCRK_CALIB) InjSys_tiEngStop_A[9];

#define MFUSPCRK_STOP_SEC_CALIB_32BIT
#include "mFuSpCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define MFUSPCRK_START_SEC_CALIB_16BIT
#include "mFuSpCrk_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, MFUSPCRK_CALIB) Ext_pFuRailMesRef2_A[9];

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_ctTDCThdAcvDecSTTst_T[16];

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_ctTDCThdAcvDecst_T[16];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuCrkActrTstHPPmp_C;

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0971199999999990E-001                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuDecStepSTTst_C;

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0971199999999990E-001                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuDecStepst_C;

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuReqCrkMinSTTst_M[144];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuReqCrkMinst_M[144];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuReqCrkSTTst_M[144];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuReqCrkst_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   mg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 6553.5                                                            */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_mO2Cat_A[16];

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, MFUSPCRK_CALIB) InjSys_pAirExt_A[9];

#define MFUSPCRK_STOP_SEC_CALIB_16BIT
#include "mFuSpCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define MFUSPCRK_START_SEC_CALIB_8BIT
#include "mFuSpCrk_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   s.u.                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacCorRstrtSTT_cntTDC_T[16];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   s.u.                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacCorRstrtSTT_mO2Cat_T[16];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   s.u.                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacCorRstrtSTT_nEng_tCo_M[256];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0078125                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0.0078125                                                         */
/* PhysMax: 2.0                                                               */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacMaxCorRstrtSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0078125                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0.0078125                                                         */
/* PhysMax: 2.0                                                               */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacMinCorRstrtSTT_C;

/* Type:    UInt8                                                           */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_bCorRstrtSTT_pAirExt_T[9];

/* Type:    UInt8                                                           */
/* Units:   PMH                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_ctTDCStrt_A[16];

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.00390625                                                        */
/* Units:   -                                                                 */
/* PhysMin: 0.00390625                                                        */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_facCorMassFuRstrtSTT_M[144];

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.00390625                                                        */
/* Units:   -                                                                 */
/* PhysMin: 0.00390625                                                        */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_facCorMassFuRstrt_M[144];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_facCorpAirMassFu_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_facCorpFuMassFu_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.99609375                                                        */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_rFilGainMassFuSTTst_T[16];

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.99609375                                                        */
extern CONST(UInt8, MFUSPCRK_CALIB) InjSys_rFilGainMassFust_T[16];

#define MFUSPCRK_STOP_SEC_CALIB_8BIT
#include "mFuSpCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define MFUSPCRK_START_SEC_CALIB_BOOLEAN
#include "mFuSpCrk_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, MFUSPCRK_CALIB) InjSys_bInhFISAAntiFlood_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, MFUSPCRK_CALIB) InjSys_bInhFISACalcMFu_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, MFUSPCRK_CALIB) InjSys_bSelSdlClcnMassFuCrk_C;

#define MFUSPCRK_STOP_SEC_CALIB_BOOLEAN
#include "mFuSpCrk_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define MFUSPCRK_START_SEC_VAR_16BIT
#include "mFuSpCrk_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, MFUSPCRK_VAR) InjSys_mFuCrkSp;

#define MFUSPCRK_STOP_SEC_VAR_16BIT
#include "mFuSpCrk_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Relational Operator' : Unused code path elimination
 * Block '<S18>/Relational Operator1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S19>/x1' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S20>/x1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/x1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S22>/x1' : Unused code path elimination
 * Block '<S22>/x2' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Relational Operator' : Unused code path elimination
 * Block '<S29>/Relational Operator1' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S30>/x1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S31>/x1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/x1' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S33>/x1' : Unused code path elimination
 * Block '<S33>/x2' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S44>/TABLE' : Unused code path elimination
 * Block '<S44>/TABLE1' : Unused code path elimination
 * Block '<S44>/TABLE2' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S45>/TABLE' : Unused code path elimination
 * Block '<S45>/TABLE1' : Unused code path elimination
 * Block '<S45>/TABLE2' : Unused code path elimination
 * Block '<S43>/ConstVal1' : Unused code path elimination
 * Block '<S43>/ConstVal2' : Unused code path elimination
 * Block '<S43>/ConstVal3' : Unused code path elimination
 * Block '<S43>/ConstVal4' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S53>/x1' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S54>/x1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S55>/x' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S56>/x' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S80>/x1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S81>/x1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S82>/x' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S83>/x' : Unused code path elimination
 * Block '<S111>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S111>/x1' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S112>/x1' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S105>/x' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S106>/x' : Unused code path elimination
 * Block '<S44>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S44>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S45>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S45>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S57>/Switch' : Eliminated due to constant selection input
 * Block '<S58>/Switch' : Eliminated due to constant selection input
 * Block '<S84>/Switch' : Eliminated due to constant selection input
 * Block '<S95>/Switch' : Eliminated due to constant selection input
 * Block '<S113>/Switch' : Eliminated due to constant selection input
 * Block '<S126>/Switch' : Eliminated due to constant selection input
 * Block '<S57>/Add3' : Unused code path elimination
 * Block '<S57>/Add4' : Unused code path elimination
 * Block '<S57>/Constant' : Unused code path elimination
 * Block '<S57>/Relational Operator' : Unused code path elimination
 * Block '<S57>/Switch1' : Unused code path elimination
 * Block '<S57>/offset2' : Unused code path elimination
 * Block '<S57>/offset3' : Unused code path elimination
 * Block '<S57>/offset4' : Unused code path elimination
 * Block '<S58>/Add3' : Unused code path elimination
 * Block '<S58>/Add4' : Unused code path elimination
 * Block '<S58>/Constant' : Unused code path elimination
 * Block '<S58>/Relational Operator' : Unused code path elimination
 * Block '<S58>/Switch1' : Unused code path elimination
 * Block '<S58>/offset2' : Unused code path elimination
 * Block '<S58>/offset3' : Unused code path elimination
 * Block '<S58>/offset4' : Unused code path elimination
 * Block '<S84>/Add3' : Unused code path elimination
 * Block '<S84>/Add4' : Unused code path elimination
 * Block '<S84>/Constant' : Unused code path elimination
 * Block '<S84>/Relational Operator' : Unused code path elimination
 * Block '<S84>/Switch1' : Unused code path elimination
 * Block '<S84>/offset2' : Unused code path elimination
 * Block '<S84>/offset3' : Unused code path elimination
 * Block '<S84>/offset4' : Unused code path elimination
 * Block '<S95>/Add3' : Unused code path elimination
 * Block '<S95>/Add4' : Unused code path elimination
 * Block '<S95>/Constant' : Unused code path elimination
 * Block '<S95>/Relational Operator' : Unused code path elimination
 * Block '<S95>/Switch1' : Unused code path elimination
 * Block '<S95>/offset2' : Unused code path elimination
 * Block '<S95>/offset3' : Unused code path elimination
 * Block '<S95>/offset4' : Unused code path elimination
 * Block '<S113>/Add3' : Unused code path elimination
 * Block '<S113>/Add4' : Unused code path elimination
 * Block '<S113>/Constant' : Unused code path elimination
 * Block '<S113>/Relational Operator' : Unused code path elimination
 * Block '<S113>/Switch1' : Unused code path elimination
 * Block '<S113>/offset2' : Unused code path elimination
 * Block '<S113>/offset3' : Unused code path elimination
 * Block '<S113>/offset4' : Unused code path elimination
 * Block '<S126>/Add3' : Unused code path elimination
 * Block '<S126>/Add4' : Unused code path elimination
 * Block '<S126>/Constant' : Unused code path elimination
 * Block '<S126>/Relational Operator' : Unused code path elimination
 * Block '<S126>/Switch1' : Unused code path elimination
 * Block '<S126>/offset2' : Unused code path elimination
 * Block '<S126>/offset3' : Unused code path elimination
 * Block '<S126>/offset4' : Unused code path elimination
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
 * hilite_system('mFuSpCrk_AUTOCODE/mFuSpCrk')    - opens subsystem mFuSpCrk_AUTOCODE/mFuSpCrk
 * hilite_system('mFuSpCrk_AUTOCODE/mFuSpCrk/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : mFuSpCrk_AUTOCODE
 * '<S7>'   : mFuSpCrk_AUTOCODE/mFuSpCrk
 * '<S8>'   : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT
 * '<S9>'   : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst
 * '<S10>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk
 * '<S11>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast
 * '<S12>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC
 * '<S13>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/demux_fc1
 * '<S14>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/demux_fc2
 * '<S15>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/demux_fc3
 * '<S16>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT
 * '<S17>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable
 * '<S18>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/Clamp
 * '<S19>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/LookUp_1D
 * '<S20>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/LookUp_1D1
 * '<S21>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/LookUp_1D2_Index
 * '<S22>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/LookUp_2D
 * '<S23>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/multiplication_new1
 * '<S24>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/multiplication_new2
 * '<S25>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/Clamp/Data Type Conversion Inherited
 * '<S26>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/Clamp/Data Type Conversion Inherited1
 * '<S27>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT/F01_mFuFacCorRstrtSTT_Reusable/Clamp/Saturation Dynamic
 * '<S28>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable
 * '<S29>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/Clamp
 * '<S30>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/LookUp_1D
 * '<S31>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/LookUp_1D1
 * '<S32>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/LookUp_1D2_Index
 * '<S33>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/LookUp_2D
 * '<S34>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/multiplication_new1
 * '<S35>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/multiplication_new2
 * '<S36>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/Clamp/Data Type Conversion Inherited
 * '<S37>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/Clamp/Data Type Conversion Inherited1
 * '<S38>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F01_mFuFacCorRstrtSTT_Rst/F01_mFuFacCorRstrtSTT_Reusable/Clamp/Saturation Dynamic
 * '<S39>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F01_IniCrkfacCor
 * '<S40>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass
 * '<S41>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/mFuSpCrk_fc_demux1
 * '<S42>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/mFuSpCrk_fc_demux2
 * '<S43>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F01_IniCrkfacCor/F01_IniCrkfacCor
 * '<S44>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F01_IniCrkfacCor/F01_IniCrkfacCor/Carto_2D
 * '<S45>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F01_IniCrkfacCor/F01_IniCrkfacCor/Carto_2D1
 * '<S46>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass
 * '<S47>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/Interp_1D
 * '<S48>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/Interp_1D1
 * '<S49>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/Interp_2D
 * '<S50>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/Interp_2D1
 * '<S51>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/Interp_2D2
 * '<S52>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/Interp_2D3
 * '<S53>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/LookUp_1D1
 * '<S54>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/LookUp_1D2
 * '<S55>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/PreLookUp_Binary
 * '<S56>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/PreLookUp_Binary1
 * '<S57>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/SingleToFixdt
 * '<S58>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/SingleToFixdt1
 * '<S59>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication
 * '<S60>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication1
 * '<S61>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication2
 * '<S62>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication3
 * '<S63>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication4
 * '<S64>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication5
 * '<S65>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication6
 * '<S66>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication7
 * '<S67>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication8
 * '<S68>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F02_IniCrk/F02_IniCrkMass/F02_IniCrkMass/multiplication9
 * '<S69>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast
 * '<S70>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast
 * '<S71>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F01_mFuInjCutOff
 * '<S72>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff
 * '<S73>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec
 * '<S74>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F02_mFuSpDec
 * '<S75>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/Mem
 * '<S76>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/Interp_2D
 * '<S77>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/Interp_2D1
 * '<S78>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/Interp_2D2
 * '<S79>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/Interp_2D3
 * '<S80>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/LookUp_1D
 * '<S81>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/LookUp_1D1
 * '<S82>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/PreLookUp_Binary
 * '<S83>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/PreLookUp_Binary1
 * '<S84>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/SingleToFixdt
 * '<S85>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication
 * '<S86>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication1
 * '<S87>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication2
 * '<S88>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication3
 * '<S89>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication4
 * '<S90>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication5
 * '<S91>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication6
 * '<S92>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication7
 * '<S93>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication8
 * '<S94>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F01_mFuSpPrevDec/multiplication9
 * '<S95>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F02_mFuSpDec/SingleToFixdt
 * '<S96>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/F02_mFuSpDec/multiplication
 * '<S97>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F03_mFuSpClcnSdlFast/F03_mFuSpClcnSdlFast/F01_mFuSpCrkSdlFast/F02_mFuNoInjCutOff/Mem/SubSystem
 * '<S98>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC
 * '<S99>'  : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC
 * '<S100>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F01_mFuTDCInjCutOff
 * '<S101>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC
 * '<S102>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec
 * '<S103>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F02_mFuSpFiltTDC
 * '<S104>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/Mem
 * '<S105>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/PreLookUp_Binary
 * '<S106>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/PreLookUp_Binary1
 * '<S107>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/Interp_2D
 * '<S108>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/Interp_2D1
 * '<S109>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/Interp_2D2
 * '<S110>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/Interp_2D3
 * '<S111>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/LookUp_1D1
 * '<S112>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/LookUp_1D2
 * '<S113>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/SingleToFixdt
 * '<S114>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication
 * '<S115>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication1
 * '<S116>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication2
 * '<S117>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication3
 * '<S118>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication4
 * '<S119>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication5
 * '<S120>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication6
 * '<S121>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication7
 * '<S122>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication8
 * '<S123>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F01_mFuSpTDCPrevDec/multiplication9
 * '<S124>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F02_mFuSpFiltTDC/Interp_1D
 * '<S125>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F02_mFuSpFiltTDC/Interp_1D1
 * '<S126>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F02_mFuSpFiltTDC/SingleToFixdt
 * '<S127>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F02_mFuSpFiltTDC/multiplication
 * '<S128>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/F02_mFuSpFiltTDC/multiplication1
 * '<S129>' : mFuSpCrk_AUTOCODE/mFuSpCrk/F04_mFuSpClcnTDC/F04_mFuSpClcnTDC/F01_mFuSpCrkTDC/F02_mFuTDC/Mem/SubSystem
 */

/*-
 * Requirements for '<Root>': mFuSpCrk
 *
 * Inherited requirements for '<S7>/F01_mFuFacCorRstrtSTT':
 *  1. SubSystem "F01_mFuFacCorRstrtSTT" !Trace_To : VEMS_E_11_01977_001.01 ;
 *
 * Inherited requirements for '<S7>/F01_mFuFacCorRstrtSTT_Rst':
 *  1. SubSystem "F01_mFuFacCorRstrtSTT" !Trace_To : VEMS_E_11_01977_001.01 ;

 */
#endif                                 /* RTW_HEADER_mFuSpCrk_h_ */

/*-------------------------------- end of file -------------------------------*/
