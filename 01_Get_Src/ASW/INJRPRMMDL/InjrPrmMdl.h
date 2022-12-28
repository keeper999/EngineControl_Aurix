/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjrPrmMdl                                              */
/* !Description     : INJECTOR MODEL PARAMETERS SPECIFICATION                 */
/*                                                                            */
/* !Module          : InjrPrmMdl                                              */
/*                                                                            */
/* !File            : InjrPrmMdl.h                                            */
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
/*   Code generated on: Wed Sep 12 10:33:08 2012                              */
/*   Model name       : InjrPrmMdl_AUTOCODE.mdl                               */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /InjrPrmMdl                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjrPrmMdl/5-SOFT-LIV/InjrPr$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   25 Sep 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjrPrmMdl_h_
#define RTW_HEADER_InjrPrmMdl_h_
#ifndef InjrPrmMdl_COMMON_INCLUDES_
# define InjrPrmMdl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "InjrPrmMdl_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MIN.h"
#endif                                 /* InjrPrmMdl_COMMON_INCLUDES_ */

#include "InjrPrmMdl_types.h"

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

/* Block signals for system '<S10>/F03_InjrPrmMdlFct' */
typedef struct {
  UInt16 SignalConversion[4];        /* '<S115>/Signal Conversion' */
  SInt16 OutDTConv[4];                /* '<S133>/OutDTConv' */
  UInt16 OutDTConv_d[4];             /* '<S146>/OutDTConv' */
  UInt16 Switch[4];                  /* '<S125>/Switch' */
  UInt8 SignalConversion1;           /* '<S115>/Signal Conversion1' */
} rtB_F03_InjrPrmMdlFct_InjrPrmMd;

/* Block signals (auto storage) */
typedef struct {
  UInt16 VEMS_vidGET;                /* '<S72>/VEMS_vidGET' */
  UInt16 VEMS_vidGET_k;              /* '<S10>/VEMS_vidGET' */
  UInt16 VEMS_vidGET6[6];            /* '<S32>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET_d[6];           /* '<S32>/VEMS_vidGET' */
  UInt16 VEMS_vidGET1[6];            /* '<S32>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET7[6];            /* '<S32>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET8[6];            /* '<S32>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET2[6];            /* '<S32>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET9[6];            /* '<S32>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET3[6];            /* '<S32>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET9_n[6];          /* '<S19>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET8_n[6];          /* '<S19>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET7_l[6];          /* '<S19>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET6_h[6];          /* '<S19>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET_f[6];           /* '<S19>/VEMS_vidGET' */
  UInt16 VEMS_vidGET1_m[6];          /* '<S19>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET2_l[6];          /* '<S19>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET3_b[6];          /* '<S19>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET6_m[6];          /* '<S18>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET_n[6];           /* '<S18>/VEMS_vidGET' */
  UInt16 VEMS_vidGET1_h[6];          /* '<S18>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET7_h[6];          /* '<S18>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET8_k[6];          /* '<S18>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET2_a[6];          /* '<S18>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET9_ne[6];         /* '<S18>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET3_n[6];          /* '<S18>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET10[6];           /* '<S32>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET11[6];           /* '<S32>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET12[6];           /* '<S32>/VEMS_vidGET12' */
  UInt16 VEMS_vidGET13[6];           /* '<S32>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET12_j[6];         /* '<S19>/VEMS_vidGET12' */
  UInt16 VEMS_vidGET13_c[6];         /* '<S19>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET10_g[6];         /* '<S19>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET11_g[6];         /* '<S19>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET10_f[6];         /* '<S18>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET11_k[6];         /* '<S18>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET12_i[6];         /* '<S18>/VEMS_vidGET12' */
  UInt16 VEMS_vidGET13_g[6];         /* '<S18>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET1_d;             /* '<S72>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET1_e;             /* '<S10>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET1_ei;             /* '<S62>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_b;               /* '<S62>/VEMS_vidGET' */
  UInt8 VEMS_vidGET4;                /* '<S32>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET5;                /* '<S32>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET2_c;              /* '<S72>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET1_f;              /* '<S67>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_g;               /* '<S67>/VEMS_vidGET' */
  UInt8 VEMS_vidGET4_i;              /* '<S19>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET5_j;              /* '<S19>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET2_d;              /* '<S10>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET4_h;              /* '<S18>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET5_d;              /* '<S18>/VEMS_vidGET5' */
  rtB_F03_InjrPrmMdlFct_InjrPrmMd F03_InjrPrmMdlFct_fy;/* '<S72>/F03_InjrPrmMdlFct' */
  rtB_F03_InjrPrmMdlFct_InjrPrmMd F03_InjrPrmMdlFct_f;/* '<S10>/F03_InjrPrmMdlFct' */
} BlockIO_InjrPrmMdl;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S121>/Lookup Table (n-D)'
   *   '<S79>/Lookup Table (n-D)'
   */
  UInt32 pooled12[2];
} ConstParam_InjrPrmMdl;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJRPRMMDL_START_SEC_VAR_UNSPECIFIED
#include "InjrPrmMdl_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InjrPrmMdl InjrPrmMdl_B;

/* Constant parameters (auto storage) */
extern const ConstParam_InjrPrmMdl InjrPrmMdl_ConstP;

#define INJRPRMMDL_STOP_SEC_VAR_UNSPECIFIED
#include "InjrPrmMdl_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define INJRPRMMDL_START_SEC_CODE
#include "InjrPrmMdl_MemMap.h"

/* Model entry point functions */
extern void InjrPrmMdl_initialize(void);
extern void InjrM_EveSpl_InjrPrmMdl(void);
extern void InjrM_EveInj_InjrPrmMdl(void);
extern void InjrM_SdlFast_InjrPrmMdl(void);
extern void InjrM_EveCkSnOn_InjrPrmMdl(void);
extern void InjrM_EveRst_InjrPrmMdl(void);

#define INJRPRMMDL_STOP_SEC_CODE
#include "InjrPrmMdl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define INJRPRMMDL_START_SEC_CALIB_16BIT
#include "InjrPrmMdl_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_facCorCylGainLnr_T[6];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_facCorCylOfsInj_T[6];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_facCorCylPFuInj_T[6];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.99996                                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_facCorGainLnrProf1_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.99996                                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_facCorGainLnrProf2_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.99996                                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_facCorGainLnrProf3_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.99996                                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_facCorGainLnrProf4_M[256];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_facGainLnrRawProf_M[256];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_mFuReq1_A[16];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_mFuReq2_A[16];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_mFuReq3_A[16];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_mFuReq4_A[16];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_nEng_A[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_pCylEstim_A[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_pDifInjr_A[16];

/* Type:    SInt16                                                           */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: -2.56E+007                                                        */
/* PhysMax: 2.559921875E+007                                                  */
extern CONST(SInt16, INJRPRMMDL_CALIB) InjrM_pDsInjrCor_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_pFuEstim_A[16];

/* Type:    UInt16                                                          */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern CONST(UInt16, INJRPRMMDL_CALIB) InjrM_tFu_A[16];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, INJRPRMMDL_CALIB) InjrM_tiInjOfsRawProf1_M[256];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, INJRPRMMDL_CALIB) InjrM_tiInjOfsRawProf2_M[256];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, INJRPRMMDL_CALIB) InjrM_tiInjOfsRawProf3_M[256];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, INJRPRMMDL_CALIB) InjrM_tiInjOfsRawProf4_M[256];

#define INJRPRMMDL_STOP_SEC_CALIB_16BIT
#include "InjrPrmMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJRPRMMDL_START_SEC_CALIB_8BIT
#include "InjrPrmMdl_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 4.0                                                               */
extern CONST(UInt8, INJRPRMMDL_CALIB) InjrM_IdxInjrMdlInj_T[4];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 6.0                                                               */
extern CONST(UInt8, INJRPRMMDL_CALIB) InjrM_noCyl_A[6];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, INJRPRMMDL_CALIB) InjrM_stTypElCmdInjrReq_A[4];

#define INJRPRMMDL_STOP_SEC_CALIB_8BIT
#include "InjrPrmMdl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJRPRMMDL_START_SEC_VAR_16BIT
#include "InjrPrmMdl_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern VAR(UInt16, INJRPRMMDL_VAR) InjrM_prm_facCorGainLnr[4];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern VAR(UInt16, INJRPRMMDL_VAR) InjrM_prm_facGainLnrlnjRaw[4];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, INJRPRMMDL_VAR) InjrM_prm_pDifInjr[4];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern VAR(SInt16, INJRPRMMDL_VAR) InjrM_prm_tiInjOfsRaw[4];

#define INJRPRMMDL_STOP_SEC_VAR_16BIT
#include "InjrPrmMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define INJRPRMMDL_START_SEC_VAR_8BIT
#include "InjrPrmMdl_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 4.0                                                               */
extern VAR(UInt8, INJRPRMMDL_VAR) InjrM_IdxInjrMdlInj;

#define INJRPRMMDL_STOP_SEC_VAR_8BIT
#include "InjrPrmMdl_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S66>/x' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S71>/x' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S77>/x1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S79>/x1' : Unused code path elimination
 * Block '<S79>/x2' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S90>/x' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S108>/x' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S110>/x' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S112>/x' : Unused code path elimination
 * Block '<S114>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S114>/x' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S103>/x' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S84>/x' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S119>/x1' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S121>/x1' : Unused code path elimination
 * Block '<S121>/x2' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S132>/x' : Unused code path elimination
 * Block '<S150>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S150>/x' : Unused code path elimination
 * Block '<S152>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S152>/x' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S154>/x' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S156>/x' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S145>/x' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S126>/x' : Unused code path elimination
 * Block '<S78>/Switch' : Eliminated due to constant selection input
 * Block '<S80>/Switch' : Eliminated due to constant selection input
 * Block '<S91>/Switch' : Eliminated due to constant selection input
 * Block '<S104>/Switch' : Eliminated due to constant selection input
 * Block '<S105>/Switch' : Eliminated due to constant selection input
 * Block '<S120>/Switch' : Eliminated due to constant selection input
 * Block '<S122>/Switch' : Eliminated due to constant selection input
 * Block '<S133>/Switch' : Eliminated due to constant selection input
 * Block '<S146>/Switch' : Eliminated due to constant selection input
 * Block '<S147>/Switch' : Eliminated due to constant selection input
 * Block '<S78>/Add3' : Unused code path elimination
 * Block '<S78>/Add4' : Unused code path elimination
 * Block '<S78>/Constant' : Unused code path elimination
 * Block '<S78>/Relational Operator' : Unused code path elimination
 * Block '<S78>/Switch1' : Unused code path elimination
 * Block '<S78>/offset2' : Unused code path elimination
 * Block '<S78>/offset3' : Unused code path elimination
 * Block '<S78>/offset4' : Unused code path elimination
 * Block '<S80>/Add3' : Unused code path elimination
 * Block '<S80>/Add4' : Unused code path elimination
 * Block '<S80>/Constant' : Unused code path elimination
 * Block '<S80>/Relational Operator' : Unused code path elimination
 * Block '<S80>/Switch1' : Unused code path elimination
 * Block '<S80>/offset2' : Unused code path elimination
 * Block '<S80>/offset3' : Unused code path elimination
 * Block '<S80>/offset4' : Unused code path elimination
 * Block '<S91>/Add2' : Unused code path elimination
 * Block '<S91>/Constant' : Unused code path elimination
 * Block '<S91>/offset1' : Unused code path elimination
 * Block '<S104>/Add3' : Unused code path elimination
 * Block '<S104>/Add4' : Unused code path elimination
 * Block '<S104>/Constant' : Unused code path elimination
 * Block '<S104>/Relational Operator' : Unused code path elimination
 * Block '<S104>/Switch1' : Unused code path elimination
 * Block '<S104>/offset2' : Unused code path elimination
 * Block '<S104>/offset3' : Unused code path elimination
 * Block '<S104>/offset4' : Unused code path elimination
 * Block '<S105>/Add3' : Unused code path elimination
 * Block '<S105>/Add4' : Unused code path elimination
 * Block '<S105>/Constant' : Unused code path elimination
 * Block '<S105>/Relational Operator' : Unused code path elimination
 * Block '<S105>/Switch1' : Unused code path elimination
 * Block '<S105>/offset2' : Unused code path elimination
 * Block '<S105>/offset3' : Unused code path elimination
 * Block '<S105>/offset4' : Unused code path elimination
 * Block '<S120>/Add3' : Unused code path elimination
 * Block '<S120>/Add4' : Unused code path elimination
 * Block '<S120>/Constant' : Unused code path elimination
 * Block '<S120>/Relational Operator' : Unused code path elimination
 * Block '<S120>/Switch1' : Unused code path elimination
 * Block '<S120>/offset2' : Unused code path elimination
 * Block '<S120>/offset3' : Unused code path elimination
 * Block '<S120>/offset4' : Unused code path elimination
 * Block '<S122>/Add3' : Unused code path elimination
 * Block '<S122>/Add4' : Unused code path elimination
 * Block '<S122>/Constant' : Unused code path elimination
 * Block '<S122>/Relational Operator' : Unused code path elimination
 * Block '<S122>/Switch1' : Unused code path elimination
 * Block '<S122>/offset2' : Unused code path elimination
 * Block '<S122>/offset3' : Unused code path elimination
 * Block '<S122>/offset4' : Unused code path elimination
 * Block '<S133>/Add2' : Unused code path elimination
 * Block '<S133>/Constant' : Unused code path elimination
 * Block '<S133>/offset1' : Unused code path elimination
 * Block '<S146>/Add3' : Unused code path elimination
 * Block '<S146>/Add4' : Unused code path elimination
 * Block '<S146>/Constant' : Unused code path elimination
 * Block '<S146>/Relational Operator' : Unused code path elimination
 * Block '<S146>/Switch1' : Unused code path elimination
 * Block '<S146>/offset2' : Unused code path elimination
 * Block '<S146>/offset3' : Unused code path elimination
 * Block '<S146>/offset4' : Unused code path elimination
 * Block '<S147>/Add3' : Unused code path elimination
 * Block '<S147>/Add4' : Unused code path elimination
 * Block '<S147>/Constant' : Unused code path elimination
 * Block '<S147>/Relational Operator' : Unused code path elimination
 * Block '<S147>/Switch1' : Unused code path elimination
 * Block '<S147>/offset2' : Unused code path elimination
 * Block '<S147>/offset3' : Unused code path elimination
 * Block '<S147>/offset4' : Unused code path elimination
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
 * hilite_system('InjrPrmMdl_AUTOCODE/InjrPrmMdl')    - opens subsystem InjrPrmMdl_AUTOCODE/InjrPrmMdl
 * hilite_system('InjrPrmMdl_AUTOCODE/InjrPrmMdl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InjrPrmMdl_AUTOCODE
 * '<S1>'   : InjrPrmMdl_AUTOCODE/InjrPrmMdl
 * '<S7>'   : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn
 * '<S8>'   : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj
 * '<S9>'   : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct
 * '<S10>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1
 * '<S11>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/InjrPrmMdl_fc_demux1
 * '<S12>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/InjrPrmMdl_fc_demux2
 * '<S13>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/InjrPrmMdl_fc_demux3
 * '<S14>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/InjrPrmMdl_fc_demux4
 * '<S15>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/InjrPrmMdl_fc_demux5
 * '<S16>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn
 * '<S17>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1
 * '<S18>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2
 * '<S19>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn
 * '<S20>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector
 * '<S21>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector1
 * '<S22>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector10
 * '<S23>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector11
 * '<S24>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector2
 * '<S25>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector3
 * '<S26>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector4
 * '<S27>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector5
 * '<S28>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector6
 * '<S29>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector7
 * '<S30>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector8
 * '<S31>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F01_SyncIn/F01_SyncIn/One_Based_Selector9
 * '<S32>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1
 * '<S33>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1
 * '<S34>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector1
 * '<S35>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector10
 * '<S36>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector11
 * '<S37>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector12
 * '<S38>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector2
 * '<S39>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector3
 * '<S40>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector4
 * '<S41>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector5
 * '<S42>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector6
 * '<S43>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector7
 * '<S44>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector8
 * '<S45>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn1/F02_SyncIn1/F02_SyncIn1/One_Based_Selector9
 * '<S46>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1
 * '<S47>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector1
 * '<S48>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector10
 * '<S49>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector11
 * '<S50>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector12
 * '<S51>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector2
 * '<S52>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector3
 * '<S53>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector4
 * '<S54>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector5
 * '<S55>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector6
 * '<S56>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector7
 * '<S57>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector8
 * '<S58>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F01_InjrPrmMdlSyncIn/F02_SyncIn2/F02_SyncIn1/One_Based_Selector9
 * '<S59>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F01_InjrMdlCylCorSyncRst
 * '<S60>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F02_InjrMdlCylCorSyncEveInj
 * '<S61>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F03_InjrMdlCylCorSyncEve
 * '<S62>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F02_InjrMdlCylCorSyncEveInj/F02_InjrMdlCylCorSyncEveInj
 * '<S63>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F02_InjrMdlCylCorSyncEveInj/F02_InjrMdlCylCorSyncEveInj/Interp_1D
 * '<S64>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F02_InjrMdlCylCorSyncEveInj/F02_InjrMdlCylCorSyncEveInj/Interp_1D1
 * '<S65>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F02_InjrMdlCylCorSyncEveInj/F02_InjrMdlCylCorSyncEveInj/Interp_1D2
 * '<S66>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F02_InjrMdlCylCorSyncEveInj/F02_InjrMdlCylCorSyncEveInj/PreLookUp_Binary
 * '<S67>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F03_InjrMdlCylCorSyncEve/F03_InjrMdlCylCorSyncEve
 * '<S68>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F03_InjrMdlCylCorSyncEve/F03_InjrMdlCylCorSyncEve/Interp_1D
 * '<S69>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F03_InjrMdlCylCorSyncEve/F03_InjrMdlCylCorSyncEve/Interp_1D1
 * '<S70>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F03_InjrMdlCylCorSyncEve/F03_InjrMdlCylCorSyncEve/Interp_1D2
 * '<S71>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F02_InjrPrmMdlCorInj/F03_InjrMdlCylCorSyncEve/F03_InjrMdlCylCorSyncEve/PreLookUp_Binary
 * '<S72>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct
 * '<S73>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct
 * '<S74>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F01_IdxCartoSelector
 * '<S75>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F02_pDifInjClcn
 * '<S76>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm
 * '<S77>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F01_IdxCartoSelector/LookUp_1D
 * '<S78>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F01_IdxCartoSelector/SingleToFixdt
 * '<S79>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F02_pDifInjClcn/LookUp_2D
 * '<S80>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F02_pDifInjClcn/SingleToFixdt
 * '<S81>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F02_pDifInjClcn/multiplication_411
 * '<S82>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw
 * '<S83>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain
 * '<S84>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/PreLookUp_Binary1
 * '<S85>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F01_tiInjOfs1
 * '<S86>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F02_tiInjOfs2
 * '<S87>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F03_tiInjOfs3
 * '<S88>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F04_tiInjOfs4
 * '<S89>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F09_tiInjOfs9
 * '<S90>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/PreLookUp_Binary
 * '<S91>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/SingleToFixdt
 * '<S92>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/multiplication_421
 * '<S93>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F01_tiInjOfs1/Interp_2D
 * '<S94>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F02_tiInjOfs2/Interp_2D
 * '<S95>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F03_tiInjOfs3/Interp_2D
 * '<S96>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F04_tiInjOfs4/Interp_2D
 * '<S97>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F10_facCorGainLnr1
 * '<S98>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F11_facCorGainLnr2
 * '<S99>'  : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F12_facCorGainLnr3
 * '<S100>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F13_facCorGainLnr4
 * '<S101>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F18_facCorGainLnr9
 * '<S102>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/Interp_2D
 * '<S103>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/PreLookUp_Binary1
 * '<S104>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/SingleToFixdt
 * '<S105>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/SingleToFixdt1
 * '<S106>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/multiplication_431
 * '<S107>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F10_facCorGainLnr1/Interp_2D
 * '<S108>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F10_facCorGainLnr1/PreLookUp_Binary
 * '<S109>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F11_facCorGainLnr2/Interp_2D
 * '<S110>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F11_facCorGainLnr2/PreLookUp_Binary
 * '<S111>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F12_facCorGainLnr3/Interp_2D
 * '<S112>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F12_facCorGainLnr3/PreLookUp_Binary
 * '<S113>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F13_facCorGainLnr4/Interp_2D
 * '<S114>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F13_facCorGainLnr4/PreLookUp_Binary
 * '<S115>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct
 * '<S116>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F01_IdxCartoSelector
 * '<S117>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F02_pDifInjClcn
 * '<S118>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm
 * '<S119>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F01_IdxCartoSelector/LookUp_1D
 * '<S120>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F01_IdxCartoSelector/SingleToFixdt
 * '<S121>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F02_pDifInjClcn/LookUp_2D
 * '<S122>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F02_pDifInjClcn/SingleToFixdt
 * '<S123>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F02_pDifInjClcn/multiplication_411
 * '<S124>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw
 * '<S125>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain
 * '<S126>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/PreLookUp_Binary1
 * '<S127>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F01_tiInjOfs1
 * '<S128>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F02_tiInjOfs2
 * '<S129>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F03_tiInjOfs3
 * '<S130>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F04_tiInjOfs4
 * '<S131>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F09_tiInjOfs9
 * '<S132>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/PreLookUp_Binary
 * '<S133>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/SingleToFixdt
 * '<S134>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/multiplication_421
 * '<S135>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F01_tiInjOfs1/Interp_2D
 * '<S136>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F02_tiInjOfs2/Interp_2D
 * '<S137>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F03_tiInjOfs3/Interp_2D
 * '<S138>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F01_tiInjOfsRaw/F04_tiInjOfs4/Interp_2D
 * '<S139>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F10_facCorGainLnr1
 * '<S140>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F11_facCorGainLnr2
 * '<S141>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F12_facCorGainLnr3
 * '<S142>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F13_facCorGainLnr4
 * '<S143>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F18_facCorGainLnr9
 * '<S144>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/Interp_2D
 * '<S145>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/PreLookUp_Binary1
 * '<S146>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/SingleToFixdt
 * '<S147>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/SingleToFixdt1
 * '<S148>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/multiplication_431
 * '<S149>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F10_facCorGainLnr1/Interp_2D
 * '<S150>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F10_facCorGainLnr1/PreLookUp_Binary
 * '<S151>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F11_facCorGainLnr2/Interp_2D
 * '<S152>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F11_facCorGainLnr2/PreLookUp_Binary
 * '<S153>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F12_facCorGainLnr3/Interp_2D
 * '<S154>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F12_facCorGainLnr3/PreLookUp_Binary
 * '<S155>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F13_facCorGainLnr4/Interp_2D
 * '<S156>' : InjrPrmMdl_AUTOCODE/InjrPrmMdl/F03_InjrPrmMdlFct1/F03_InjrPrmMdlFct/F03_InjrPrm/F02_Gain/F13_facCorGainLnr4/PreLookUp_Binary
 */

/*-
 * Requirements for '<Root>': InjrPrmMdl
 */
#endif                                 /* RTW_HEADER_InjrPrmMdl_h_ */

/*-------------------------------- end of file -------------------------------*/
