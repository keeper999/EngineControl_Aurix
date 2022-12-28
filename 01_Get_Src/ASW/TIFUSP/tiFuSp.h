/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tiFuSp                                                  */
/* !Description     : CALCUL DU TEMPS D INJECTION                             */
/*                                                                            */
/* !Module          : tiFuSp                                                  */
/*                                                                            */
/* !File            : tiFuSp.h                                                */
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
/*   Code generated on: Sun Nov 17 20:13:35 2013                              */
/*   Model name       : tiFuSp_AUTOCODE.mdl                                   */
/*   Model version    : 1.766                                                 */
/*   Root subsystem   : /tiFuSp                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/TIFUSP/tiFuSp.h_v         $*/
/* $Revision::   1.24                                                        $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Nov 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_tiFuSp_h_
#define RTW_HEADER_tiFuSp_h_
#ifndef tiFuSp_COMMON_INCLUDES_
# define tiFuSp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "tiFuSp_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MAXf.h"
#include "rt_MIN.h"
#include "rt_MINf.h"
#endif                                 /* tiFuSp_COMMON_INCLUDES_ */

#include "tiFuSp_types.h"

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
  UInt32 VEMS_vidGET1;               /* '<S213>/VEMS_vidGET1' */
  UInt32 Switch7[6];                 /* '<S167>/Switch7' */
  UInt32 Switch8[6];                 /* '<S167>/Switch8' */
  UInt32 Switch5[6];                 /* '<S167>/Switch5' */
  UInt32 Switch9[6];                 /* '<S167>/Switch9' */
  UInt32 TmpSignalConversionAtVEMS_vidSE[4];
  UInt32 VEMS_vidGET10[6];           /* '<S189>/VEMS_vidGET10' */
  UInt32 VEMS_vidGET11[6];           /* '<S189>/VEMS_vidGET11' */
  UInt32 VEMS_vidGET12[6];           /* '<S189>/VEMS_vidGET12' */
  UInt32 Switch7_b[6];               /* '<S189>/Switch7' */
  UInt32 Switch8_g[6];               /* '<S189>/Switch8' */
  UInt32 Switch5_g[6];               /* '<S189>/Switch5' */
  UInt32 Switch9_h[6];               /* '<S189>/Switch9' */
  UInt16 VEMS_vidGET1_h;             /* '<S90>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET2;               /* '<S90>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET;                /* '<S213>/VEMS_vidGET' */
  UInt16 VEMS_vidGET3;               /* '<S90>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET4;               /* '<S90>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET3_l[6];          /* '<S53>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET6[6];            /* '<S53>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET7[6];            /* '<S53>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET2_h[6];          /* '<S53>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET3_k[6];          /* '<S18>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET6_g[6];          /* '<S18>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET7_i[6];          /* '<S18>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET2_l[6];          /* '<S18>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET8[6];            /* '<S53>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET4_c[6];          /* '<S53>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5[6];            /* '<S53>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET8_k[6];          /* '<S18>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET4_f[6];          /* '<S18>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5_e[6];          /* '<S18>/VEMS_vidGET5' */
  UInt16 MultiportSwitch;            /* '<S213>/Multiport Switch' */
  UInt16 VEMS_vidGET9[6];            /* '<S53>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET10_n[6];         /* '<S53>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET11_j[6];         /* '<S53>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET12_k[6];         /* '<S53>/VEMS_vidGET12' */
  UInt16 VEMS_vidGET9_l[6];          /* '<S18>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET10_c[6];         /* '<S18>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET11_b[6];         /* '<S18>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET12_j[6];         /* '<S18>/VEMS_vidGET12' */
  UInt16 VEMS_vidGET13[6];           /* '<S53>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET14[6];           /* '<S53>/VEMS_vidGET14' */
  UInt16 VEMS_vidGET15[6];           /* '<S53>/VEMS_vidGET15' */
  UInt16 VEMS_vidGET16[6];           /* '<S53>/VEMS_vidGET16' */
  UInt16 VEMS_vidGET13_p[6];         /* '<S18>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET14_e[6];         /* '<S18>/VEMS_vidGET14' */
  UInt16 VEMS_vidGET15_o[6];         /* '<S18>/VEMS_vidGET15' */
  UInt16 VEMS_vidGET16_k[6];         /* '<S18>/VEMS_vidGET16' */
  SInt16 VEMS_vidGET5_m[6];           /* '<S167>/VEMS_vidGET5' */
  SInt16 VEMS_vidGET17[6];            /* '<S53>/VEMS_vidGET17' */
  SInt16 VEMS_vidGET18[6];            /* '<S53>/VEMS_vidGET18' */
  SInt16 VEMS_vidGET19[6];            /* '<S53>/VEMS_vidGET19' */
  SInt16 VEMS_vidGET20[6];            /* '<S53>/VEMS_vidGET20' */
  SInt16 VEMS_vidGET6_k[6];           /* '<S189>/VEMS_vidGET6' */
  SInt16 VEMS_vidGET17_n[6];          /* '<S18>/VEMS_vidGET17' */
  SInt16 VEMS_vidGET18_b[6];          /* '<S18>/VEMS_vidGET18' */
  SInt16 VEMS_vidGET19_c[6];          /* '<S18>/VEMS_vidGET19' */
  SInt16 VEMS_vidGET20_m[6];          /* '<S18>/VEMS_vidGET20' */
  UInt16 VEMS_vidGET_f;              /* '<S90>/VEMS_vidGET' */
  UInt8 VEMS_vidGET4_fk;             /* '<S167>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET1_hr;             /* '<S167>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET3_e;              /* '<S167>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET2_a;              /* '<S167>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET1_n;              /* '<S53>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_fn;              /* '<S53>/VEMS_vidGET' */
  UInt8 VEMS_vidGET5_d;              /* '<S189>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET2_p;              /* '<S189>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET4_fz;             /* '<S189>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET1_o;              /* '<S189>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET3_g;              /* '<S189>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET7_g;              /* '<S90>/VEMS_vidGET7' */
  UInt8 VEMS_vidGET1_oj;             /* '<S18>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_m;               /* '<S18>/VEMS_vidGET' */
  Boolean VEMS_vidGET_c;             /* '<S167>/VEMS_vidGET' */
  Boolean VEMS_vidGET7_c;            /* '<S167>/VEMS_vidGET7' */
  Boolean VEMS_vidGET6_o[6];         /* '<S167>/VEMS_vidGET6' */
  Boolean VEMS_vidGET_k;             /* '<S189>/VEMS_vidGET' */
  Boolean VEMS_vidGET9_d;            /* '<S189>/VEMS_vidGET9' */
  Boolean VEMS_vidGET7_n[6];         /* '<S189>/VEMS_vidGET7' */
  Boolean VEMS_vidGET8_h[2];         /* '<S189>/VEMS_vidGET8' */
  Boolean VEMS_vidGET6_j;            /* '<S90>/VEMS_vidGET6' */
  UInt8 VEMS_vidGET5_l;              /* '<S90>/VEMS_vidGET5' */
} BlockIO_tiFuSp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Boolean UnitDelay_DSTATE;          /* '<S210>/Unit Delay' */
} D_Work_tiFuSp;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S214>/Lookup Table (n-D)'
   *   '<S96>/Lookup Table (n-D)'
   *   '<S122>/Lookup Table (n-D)'
   *   '<S132>/Lookup Table (n-D)'
   *   '<S142>/Lookup Table (n-D)'
   *   '<S160>/Lookup Table (n-D)'
   */
  UInt32 pooled10[2];

  /* Computed Parameter: LookupTablenD_maxIn_b
   * Referenced by: '<S154>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxIn_b[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S164>/ConstMat'
   *   '<S164>/ConstMat_1'
   *   '<S164>/ConstMat_2'
   *   '<S164>/ConstMat_5'
   *   '<S167>/ConstMat'
   *   '<S167>/ConstMat_1'
   *   '<S167>/ConstMat_2'
   *   '<S167>/ConstMat_4'
   *   '<S189>/ConstMat'
   *   '<S189>/ConstMat_1'
   *   '<S189>/ConstMat_2'
   *   '<S189>/ConstMat_4'
   */
  UInt32 pooled16[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S8>/InjrSys_prm_bDettiInjMin'
   *   '<S88>/ConstMat'
   */
  Boolean pooled20[6];
} ConstParam_tiFuSp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define TIFUSP_START_SEC_VAR_UNSPECIFIED
#include "tiFuSp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_tiFuSp tiFuSp_B;

/* Block states (auto storage) */
extern D_Work_tiFuSp tiFuSp_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_tiFuSp tiFuSp_ConstP;

#define TIFUSP_STOP_SEC_VAR_UNSPECIFIED
#include "tiFuSp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define TIFUSP_START_SEC_CODE
#include "tiFuSp_MemMap.h"

/* Model entry point functions */
extern void tiFuSp_initialize(void);
extern void InjrSys_SdlFast_tiFuSp(void);
extern void InjrSys_EveSpl_tiFuSp(void);
extern void InjrSys_EveRst_tiFuSp(void);
extern void InjrSys_EveInj_tiFuSp(void);
extern void InjrSys_EveCkSnOn_tiFuSp(void);

#define TIFUSP_STOP_SEC_CODE
#include "tiFuSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define TIFUSP_START_SEC_CALIB_32BIT
#include "tiFuSp_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern CONST(UInt32, TIFUSP_CALIB) InjrSys_tiInjTotETB_A[16];

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern CONST(UInt32, TIFUSP_CALIB) InjrSys_tiInjTotETB_C;

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern CONST(UInt32, TIFUSP_CALIB) InjrSys_tiInjTotETB_M[256];

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern CONST(UInt32, TIFUSP_CALIB) InjrSys_tiInj_A[16];

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern CONST(UInt32, TIFUSP_CALIB) InjrSys_ti_facCorInjGain_A[9];

#define TIFUSP_STOP_SEC_CALIB_32BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define TIFUSP_START_SEC_CALIB_16BIT
#include "tiFuSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_agEndInjSpcModMax_M[256];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_mFuInjEstimETB_M[256];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_nEng_facCorInjGain_A[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_pFuRailMes_A[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_pFuRailSplMes_A[16];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_rTiInjH2ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_rTiInjS1ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_rTiInjS2ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0971199999999990E-001                                           */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_tiBtwnInj_A[16];

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0971199999999990E-001                                           */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_tiInjMin_C;

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0971199999999990E-001                                           */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_tiInjMin_M[128];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, TIFUSP_CALIB) InjrSys_tiOfsCor_A[16];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, TIFUSP_CALIB) InjrSys_tiOfsH2Cor_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    -0.1048576                                                        */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 1.0485439999999990E-001                                           */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_tiOfsS1CorH2_M[256];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, TIFUSP_CALIB) InjrSys_tiOfsS1Cor_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    -0.1048576                                                        */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 1.0485439999999990E-001                                           */
extern CONST(UInt16, TIFUSP_CALIB) InjrSys_tiOfsS2CorS1_M[256];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, TIFUSP_CALIB) InjrSys_tiOfsS2Cor_M[256];

#define TIFUSP_STOP_SEC_CALIB_16BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define TIFUSP_START_SEC_CALIB_8BIT
#include "tiFuSp_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 8.0                                                               */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_IdxInjrMdlInj_A[8];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl1_C;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl2_C;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl3_C;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl4_C;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl5_C;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl6_C;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_facFuSysCor_M[81];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0                                                               */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_noETBSelMassFuEstim_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_noETBSelMassFuReq_C;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_tiOfsH2CorPFu_T[16];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_tiOfsS1CorPFu_T[16];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9921875                                                         */
extern CONST(UInt8, TIFUSP_CALIB) InjrSys_tiOfsS2CorPFu_T[16];

#define TIFUSP_STOP_SEC_CALIB_8BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define TIFUSP_START_SEC_CALIB_BOOLEAN
#include "tiFuSp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, TIFUSP_CALIB) InjrSys_bAcvMFuInjCmprCyl_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, TIFUSP_CALIB) InjrSys_bAcvTiInjETB_C;

#define TIFUSP_STOP_SEC_CALIB_BOOLEAN
#include "tiFuSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define TIFUSP_START_SEC_VAR_32BIT
#include "tiFuSp_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInj[4];

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH1ReqCyl[6];

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH2ReqCyl[6];

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjS1ReqCyl[6];

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895344000000E+004                                           */
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjS2ReqCyl[6];

#define TIFUSP_STOP_SEC_VAR_32BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define TIFUSP_START_SEC_VAR_16BIT
#include "tiFuSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, TIFUSP_VAR) InjrSys_mFuInjEstim;

#define TIFUSP_STOP_SEC_VAR_16BIT
#include "tiFuSp_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
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
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
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
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Relational Operator' : Unused code path elimination
 * Block '<S93>/Relational Operator1' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Data Type Propagation' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Relational Operator' : Unused code path elimination
 * Block '<S94>/Relational Operator1' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate' : Unused code path elimination
 * Block '<S110>/Data Type Propagation' : Unused code path elimination
 * Block '<S111>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S95>/Relational Operator' : Unused code path elimination
 * Block '<S95>/Relational Operator1' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Data Type Propagation' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S96>/x1' : Unused code path elimination
 * Block '<S96>/x2' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S122>/x1' : Unused code path elimination
 * Block '<S122>/x2' : Unused code path elimination
 * Block '<S117>/InjrSys_tiBtwnInj_A' : Unused code path elimination
 * Block '<S117>/InjrSys_tiOfsCor_A' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S130>/TABLE' : Unused code path elimination
 * Block '<S130>/TABLE1' : Unused code path elimination
 * Block '<S130>/TABLE2' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S132>/x1' : Unused code path elimination
 * Block '<S132>/x2' : Unused code path elimination
 * Block '<S118>/InjrSys_tiBtwnInj_A' : Unused code path elimination
 * Block '<S118>/InjrSys_tiOfsCor_A' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S141>/TABLE' : Unused code path elimination
 * Block '<S141>/TABLE1' : Unused code path elimination
 * Block '<S141>/TABLE2' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S142>/x1' : Unused code path elimination
 * Block '<S142>/x2' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S120>/x' : Unused code path elimination
 * Block '<S153>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S153>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S153>/x1' : Unused code path elimination
 * Block '<S153>/x2' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S154>/x1' : Unused code path elimination
 * Block '<S154>/x2' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S159>/x1' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S160>/x1' : Unused code path elimination
 * Block '<S160>/x2' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S195>/Data Type Duplicate' : Unused code path elimination
 * Block '<S195>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S196>/Data Type Duplicate' : Unused code path elimination
 * Block '<S196>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S200>/Data Type Duplicate' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Data Type Duplicate' : Unused code path elimination
 * Block '<S204>/Data Type Duplicate' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate' : Unused code path elimination
 * Block '<S206>/Data Type Duplicate' : Unused code path elimination
 * Block '<S207>/Data Type Duplicate' : Unused code path elimination
 * Block '<S208>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S214>/x1' : Unused code path elimination
 * Block '<S214>/x2' : Unused code path elimination
 * Block '<S215>/Data Type Duplicate' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate' : Unused code path elimination
 * Block '<S218>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S226>/Data Type Duplicate' : Unused code path elimination
 * Block '<S229>/Data Type Propagation' : Unused code path elimination
 * Block '<S229>/Data Type Propagation1' : Unused code path elimination
 * Block '<S233>/Data Type Propagation' : Unused code path elimination
 * Block '<S233>/Data Type Conversion' : Unused code path elimination
 * Block '<S233>/Data Type Conversion1' : Unused code path elimination
 * Block '<S230>/Data Type Propagation' : Unused code path elimination
 * Block '<S230>/Data Type Propagation1' : Unused code path elimination
 * Block '<S235>/Data Type Propagation' : Unused code path elimination
 * Block '<S235>/Data Type Conversion' : Unused code path elimination
 * Block '<S235>/Data Type Conversion1' : Unused code path elimination
 * Block '<S231>/Data Type Propagation' : Unused code path elimination
 * Block '<S231>/Data Type Propagation1' : Unused code path elimination
 * Block '<S237>/Data Type Propagation' : Unused code path elimination
 * Block '<S237>/Data Type Conversion' : Unused code path elimination
 * Block '<S237>/Data Type Conversion1' : Unused code path elimination
 * Block '<S232>/Data Type Propagation' : Unused code path elimination
 * Block '<S232>/Data Type Propagation1' : Unused code path elimination
 * Block '<S239>/Data Type Propagation' : Unused code path elimination
 * Block '<S239>/Data Type Conversion' : Unused code path elimination
 * Block '<S239>/Data Type Conversion1' : Unused code path elimination
 * Block '<S105>/Conversion' : Eliminate redundant data type conversion
 * Block '<S106>/Conversion' : Eliminate redundant data type conversion
 * Block '<S108>/Conversion' : Eliminate redundant data type conversion
 * Block '<S109>/Conversion' : Eliminate redundant data type conversion
 * Block '<S111>/Conversion' : Eliminate redundant data type conversion
 * Block '<S112>/Conversion' : Eliminate redundant data type conversion
 * Block '<S97>/Switch' : Eliminated due to constant selection input
 * Block '<S98>/Switch' : Eliminated due to constant selection input
 * Block '<S123>/Switch' : Eliminated due to constant selection input
 * Block '<S124>/Switch' : Eliminated due to constant selection input
 * Block '<S125>/Switch' : Eliminated due to constant selection input
 * Block '<S130>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S130>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S133>/Switch' : Eliminated due to constant selection input
 * Block '<S134>/Switch' : Eliminated due to constant selection input
 * Block '<S135>/Switch' : Eliminated due to constant selection input
 * Block '<S141>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S141>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S143>/Switch' : Eliminated due to constant selection input
 * Block '<S144>/Switch' : Eliminated due to constant selection input
 * Block '<S145>/Switch' : Eliminated due to constant selection input
 * Block '<S155>/Switch' : Eliminated due to constant selection input
 * Block '<S163>/Switch' : Eliminated due to constant selection input
 * Block '<S188>/Switch' : Eliminated due to constant selection input
 * Block '<S209>/Switch' : Eliminated due to constant selection input
 * Block '<S227>/Switch' : Eliminated due to constant selection input
 * Block '<S228>/Switch' : Eliminated due to constant selection input
 * Block '<S229>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S229>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S229>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S230>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S230>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S230>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S231>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S231>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S231>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S232>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S232>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S232>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S97>/Add3' : Unused code path elimination
 * Block '<S97>/Add4' : Unused code path elimination
 * Block '<S97>/Constant' : Unused code path elimination
 * Block '<S97>/Relational Operator' : Unused code path elimination
 * Block '<S97>/Switch1' : Unused code path elimination
 * Block '<S97>/offset2' : Unused code path elimination
 * Block '<S97>/offset3' : Unused code path elimination
 * Block '<S97>/offset4' : Unused code path elimination
 * Block '<S98>/Add3' : Unused code path elimination
 * Block '<S98>/Add4' : Unused code path elimination
 * Block '<S98>/Constant' : Unused code path elimination
 * Block '<S98>/Relational Operator' : Unused code path elimination
 * Block '<S98>/Switch1' : Unused code path elimination
 * Block '<S98>/offset2' : Unused code path elimination
 * Block '<S98>/offset3' : Unused code path elimination
 * Block '<S98>/offset4' : Unused code path elimination
 * Block '<S123>/Add3' : Unused code path elimination
 * Block '<S123>/Add4' : Unused code path elimination
 * Block '<S123>/Constant' : Unused code path elimination
 * Block '<S123>/Relational Operator' : Unused code path elimination
 * Block '<S123>/Switch1' : Unused code path elimination
 * Block '<S123>/offset2' : Unused code path elimination
 * Block '<S123>/offset3' : Unused code path elimination
 * Block '<S123>/offset4' : Unused code path elimination
 * Block '<S124>/Add2' : Unused code path elimination
 * Block '<S124>/Constant' : Unused code path elimination
 * Block '<S124>/offset1' : Unused code path elimination
 * Block '<S125>/Add3' : Unused code path elimination
 * Block '<S125>/Add4' : Unused code path elimination
 * Block '<S125>/Constant' : Unused code path elimination
 * Block '<S125>/Relational Operator' : Unused code path elimination
 * Block '<S125>/Switch1' : Unused code path elimination
 * Block '<S125>/offset2' : Unused code path elimination
 * Block '<S125>/offset3' : Unused code path elimination
 * Block '<S125>/offset4' : Unused code path elimination
 * Block '<S133>/Add3' : Unused code path elimination
 * Block '<S133>/Add4' : Unused code path elimination
 * Block '<S133>/Constant' : Unused code path elimination
 * Block '<S133>/Relational Operator' : Unused code path elimination
 * Block '<S133>/Switch1' : Unused code path elimination
 * Block '<S133>/offset2' : Unused code path elimination
 * Block '<S133>/offset3' : Unused code path elimination
 * Block '<S133>/offset4' : Unused code path elimination
 * Block '<S134>/Add2' : Unused code path elimination
 * Block '<S134>/Constant' : Unused code path elimination
 * Block '<S134>/offset1' : Unused code path elimination
 * Block '<S135>/Add3' : Unused code path elimination
 * Block '<S135>/Add4' : Unused code path elimination
 * Block '<S135>/Constant' : Unused code path elimination
 * Block '<S135>/Relational Operator' : Unused code path elimination
 * Block '<S135>/Switch1' : Unused code path elimination
 * Block '<S135>/offset2' : Unused code path elimination
 * Block '<S135>/offset3' : Unused code path elimination
 * Block '<S135>/offset4' : Unused code path elimination
 * Block '<S143>/Add3' : Unused code path elimination
 * Block '<S143>/Add4' : Unused code path elimination
 * Block '<S143>/Constant' : Unused code path elimination
 * Block '<S143>/Relational Operator' : Unused code path elimination
 * Block '<S143>/Switch1' : Unused code path elimination
 * Block '<S143>/offset2' : Unused code path elimination
 * Block '<S143>/offset3' : Unused code path elimination
 * Block '<S143>/offset4' : Unused code path elimination
 * Block '<S144>/Add2' : Unused code path elimination
 * Block '<S144>/Constant' : Unused code path elimination
 * Block '<S144>/offset1' : Unused code path elimination
 * Block '<S145>/Add3' : Unused code path elimination
 * Block '<S145>/Add4' : Unused code path elimination
 * Block '<S145>/Constant' : Unused code path elimination
 * Block '<S145>/Relational Operator' : Unused code path elimination
 * Block '<S145>/Switch1' : Unused code path elimination
 * Block '<S145>/offset2' : Unused code path elimination
 * Block '<S145>/offset3' : Unused code path elimination
 * Block '<S145>/offset4' : Unused code path elimination
 * Block '<S155>/Add3' : Unused code path elimination
 * Block '<S155>/Add4' : Unused code path elimination
 * Block '<S155>/Constant' : Unused code path elimination
 * Block '<S155>/Relational Operator' : Unused code path elimination
 * Block '<S155>/Switch1' : Unused code path elimination
 * Block '<S155>/offset2' : Unused code path elimination
 * Block '<S155>/offset3' : Unused code path elimination
 * Block '<S155>/offset4' : Unused code path elimination
 * Block '<S163>/Add3' : Unused code path elimination
 * Block '<S163>/Add4' : Unused code path elimination
 * Block '<S163>/Constant' : Unused code path elimination
 * Block '<S163>/Relational Operator' : Unused code path elimination
 * Block '<S163>/Switch1' : Unused code path elimination
 * Block '<S163>/offset2' : Unused code path elimination
 * Block '<S163>/offset3' : Unused code path elimination
 * Block '<S163>/offset4' : Unused code path elimination
 * Block '<S188>/Add3' : Unused code path elimination
 * Block '<S188>/Add4' : Unused code path elimination
 * Block '<S188>/Constant' : Unused code path elimination
 * Block '<S188>/Relational Operator' : Unused code path elimination
 * Block '<S188>/Switch1' : Unused code path elimination
 * Block '<S188>/offset2' : Unused code path elimination
 * Block '<S188>/offset3' : Unused code path elimination
 * Block '<S188>/offset4' : Unused code path elimination
 * Block '<S209>/Add3' : Unused code path elimination
 * Block '<S209>/Add4' : Unused code path elimination
 * Block '<S209>/Constant' : Unused code path elimination
 * Block '<S209>/Relational Operator' : Unused code path elimination
 * Block '<S209>/Switch1' : Unused code path elimination
 * Block '<S209>/offset2' : Unused code path elimination
 * Block '<S209>/offset3' : Unused code path elimination
 * Block '<S209>/offset4' : Unused code path elimination
 * Block '<S227>/Add3' : Unused code path elimination
 * Block '<S227>/Add4' : Unused code path elimination
 * Block '<S227>/Constant' : Unused code path elimination
 * Block '<S227>/Relational Operator' : Unused code path elimination
 * Block '<S227>/Switch1' : Unused code path elimination
 * Block '<S227>/offset2' : Unused code path elimination
 * Block '<S227>/offset3' : Unused code path elimination
 * Block '<S227>/offset4' : Unused code path elimination
 * Block '<S228>/Add3' : Unused code path elimination
 * Block '<S228>/Add4' : Unused code path elimination
 * Block '<S228>/Constant' : Unused code path elimination
 * Block '<S228>/Relational Operator' : Unused code path elimination
 * Block '<S228>/Switch1' : Unused code path elimination
 * Block '<S228>/offset2' : Unused code path elimination
 * Block '<S228>/offset3' : Unused code path elimination
 * Block '<S228>/offset4' : Unused code path elimination
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
 * hilite_system('tiFuSp_AUTOCODE/tiFuSp')    - opens subsystem tiFuSp_AUTOCODE/tiFuSp
 * hilite_system('tiFuSp_AUTOCODE/tiFuSp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : tiFuSp_AUTOCODE
 * '<S6>'   : tiFuSp_AUTOCODE/tiFuSp
 * '<S7>'   : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn
 * '<S8>'   : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi
 * '<S9>'   : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync
 * '<S10>'  : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu
 * '<S11>'  : tiFuSp_AUTOCODE/tiFuSp/tiFuSp_fc_demux1
 * '<S12>'  : tiFuSp_AUTOCODE/tiFuSp/tiFuSp_fc_demux2
 * '<S13>'  : tiFuSp_AUTOCODE/tiFuSp/tiFuSp_fc_demux3
 * '<S14>'  : tiFuSp_AUTOCODE/tiFuSp/tiFuSp_fc_demux4
 * '<S15>'  : tiFuSp_AUTOCODE/tiFuSp/tiFuSp_fc_demux5
 * '<S16>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn
 * '<S17>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj
 * '<S18>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn
 * '<S19>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector1
 * '<S20>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector10
 * '<S21>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector11
 * '<S22>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector12
 * '<S23>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector13
 * '<S24>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector14
 * '<S25>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector15
 * '<S26>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector16
 * '<S27>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector17
 * '<S28>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector18
 * '<S29>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector19
 * '<S30>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector2
 * '<S31>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector20
 * '<S32>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector21
 * '<S33>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector22
 * '<S34>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector23
 * '<S35>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector24
 * '<S36>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector25
 * '<S37>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector26
 * '<S38>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector27
 * '<S39>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector28
 * '<S40>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector29
 * '<S41>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector3
 * '<S42>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector30
 * '<S43>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector31
 * '<S44>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector32
 * '<S45>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector33
 * '<S46>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector34
 * '<S47>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector4
 * '<S48>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector5
 * '<S49>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector6
 * '<S50>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector7
 * '<S51>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector8
 * '<S52>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F01_tiFuSpSyncInEveClcn/F00_tiFuSpSyncInEveClcn/One_Based_Selector9
 * '<S53>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj
 * '<S54>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector1
 * '<S55>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector10
 * '<S56>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector11
 * '<S57>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector12
 * '<S58>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector13
 * '<S59>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector14
 * '<S60>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector15
 * '<S61>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector16
 * '<S62>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector17
 * '<S63>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector18
 * '<S64>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector19
 * '<S65>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector2
 * '<S66>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector20
 * '<S67>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector21
 * '<S68>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector22
 * '<S69>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector23
 * '<S70>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector24
 * '<S71>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector25
 * '<S72>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector26
 * '<S73>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector27
 * '<S74>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector28
 * '<S75>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector29
 * '<S76>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector3
 * '<S77>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector30
 * '<S78>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector31
 * '<S79>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector32
 * '<S80>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector33
 * '<S81>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector34
 * '<S82>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector4
 * '<S83>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector5
 * '<S84>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector6
 * '<S85>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector7
 * '<S86>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector8
 * '<S87>'  : tiFuSp_AUTOCODE/tiFuSp/F00_tiFuSpSyncIn/F02_tiFuSpSyncInEveInj/F00_tiFuSpSyncInEveInj/One_Based_Selector9
 * '<S88>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F01_tiFuSpRst
 * '<S89>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn
 * '<S90>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi
 * '<S91>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest
 * '<S92>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest
 * '<S93>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp
 * '<S94>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp1
 * '<S95>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp2
 * '<S96>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/InjrSys_tiInjTotETB_M
 * '<S97>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/SingleToFixdt
 * '<S98>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/SingleToFixdt1
 * '<S99>'  : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/multiplication_1
 * '<S100>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/multiplication_2
 * '<S101>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/multiplication_3
 * '<S102>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/multiplication_411
 * '<S103>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/multiplication_451
 * '<S104>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/multiplication_461
 * '<S105>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp/Data Type Conversion Inherited
 * '<S106>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp/Data Type Conversion Inherited1
 * '<S107>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp/Saturation Dynamic
 * '<S108>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp1/Data Type Conversion Inherited
 * '<S109>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp1/Data Type Conversion Inherited1
 * '<S110>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp1/Saturation Dynamic
 * '<S111>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp2/Data Type Conversion Inherited
 * '<S112>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp2/Data Type Conversion Inherited1
 * '<S113>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F01_InjTiTest/Clamp2/Saturation Dynamic
 * '<S114>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn
 * '<S115>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn
 * '<S116>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn
 * '<S117>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn
 * '<S118>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn
 * '<S119>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F04_InjS2CorClcn1
 * '<S120>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/InjrSys_pFuRailMes_A_PreLookUp
 * '<S121>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/InjrSys_tiOfsH2CorPFu_T
 * '<S122>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/InjrSys_tiOfsH2Cor_M
 * '<S123>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/SingleToFixdt
 * '<S124>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/SingleToFixdt1
 * '<S125>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/SingleToFixdt2
 * '<S126>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/division_1
 * '<S127>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/multiplication_1
 * '<S128>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/multiplication_2
 * '<S129>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F01_InjH2CorClcn/multiplication_3
 * '<S130>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/InjrSys_tiOfsS1CorH2_M
 * '<S131>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/InjrSys_tiOfsS1CorPFu_T
 * '<S132>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/InjrSys_tiOfsS1Cor_M
 * '<S133>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/SingleToFixdt
 * '<S134>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/SingleToFixdt1
 * '<S135>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/SingleToFixdt2
 * '<S136>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/division_1
 * '<S137>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/multiplication_1
 * '<S138>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/multiplication_2
 * '<S139>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F02_InjS1CorClcn/multiplication_471
 * '<S140>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/InjrSys_tiOfsS2CorPFu_T
 * '<S141>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/InjrSys_tiOfsS2CorS1_M
 * '<S142>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/InjrSys_tiOfsS2Cor_M
 * '<S143>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/SingleToFixdt
 * '<S144>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/SingleToFixdt1
 * '<S145>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/SingleToFixdt2
 * '<S146>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/division_1
 * '<S147>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/multiplication_1
 * '<S148>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/multiplication_2
 * '<S149>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F01_tiOfsCorClcn/F03_InjS2CorClcn/multiplication_3
 * '<S150>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F01_tiInjMinSat
 * '<S151>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F02_tiInjMaxSat
 * '<S152>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F03_InjCutOfftiInjReq
 * '<S153>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F01_tiInjMinSat/InjrSys_facFuSysCor_M
 * '<S154>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F01_tiInjMinSat/InjrSys_tiInjMin_M
 * '<S155>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F01_tiInjMinSat/SingleToFixdt
 * '<S156>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F01_tiInjMinSat/multiplication
 * '<S157>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F01_tiInjMinSat/multiplication1
 * '<S158>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F01_tiInjMinSat/multiplication2
 * '<S159>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F02_tiInjMaxSat/InjSys_agOfsPhaIg_T
 * '<S160>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F02_tiInjMaxSat/InjrSys_agEndInjSpcModMax_M
 * '<S161>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F02_tiInjMaxSat/division
 * '<S162>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F02_tiInjMaxSat/multiplication
 * '<S163>' : tiFuSp_AUTOCODE/tiFuSp/F01_InjTi/F02_tiFuSpClcn/F00_InjTi/F02_InjTinoTest/F02_tiClcn/F03_InjCutOfftiInjReq/SingleToFixdt
 * '<S164>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F01_InjtiSyncIni
 * '<S165>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj
 * '<S166>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn
 * '<S167>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj
 * '<S168>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Assignment
 * '<S169>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Assignment1
 * '<S170>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Assignment2
 * '<S171>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Assignment3
 * '<S172>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Assignment4
 * '<S173>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Assignment5
 * '<S174>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector
 * '<S175>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector1
 * '<S176>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector10
 * '<S177>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector11
 * '<S178>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector12
 * '<S179>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector13
 * '<S180>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector2
 * '<S181>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector3
 * '<S182>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector4
 * '<S183>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector5
 * '<S184>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector6
 * '<S185>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector7
 * '<S186>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector8
 * '<S187>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/One_Based_Selector9
 * '<S188>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F02_InjtiSyncEveInj/F00_InjtiSyncEveInj/SingleToFixdt
 * '<S189>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn
 * '<S190>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/Falling_edge
 * '<S191>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Assignment
 * '<S192>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Assignment1
 * '<S193>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Assignment2
 * '<S194>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Assignment3
 * '<S195>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Assignment4
 * '<S196>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Assignment5
 * '<S197>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Assignment6
 * '<S198>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Assignment7
 * '<S199>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector
 * '<S200>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector1
 * '<S201>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector2
 * '<S202>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector3
 * '<S203>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector4
 * '<S204>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector5
 * '<S205>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector6
 * '<S206>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector7
 * '<S207>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector8
 * '<S208>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/One_Based_Selector9
 * '<S209>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/SingleToFixdt
 * '<S210>' : tiFuSp_AUTOCODE/tiFuSp/F02_InjTiSync/F03_InjtiSyncEveClcn/F00_InjtiSyncEveClcn/Falling_edge/SubSystem
 * '<S211>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F01_InjmFuIni
 * '<S212>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu
 * '<S213>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu
 * '<S214>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/InjrSys_mFuInjEstimETB_M
 * '<S215>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector1
 * '<S216>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector10
 * '<S217>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector11
 * '<S218>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector12
 * '<S219>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector2
 * '<S220>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector3
 * '<S221>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector4
 * '<S222>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector5
 * '<S223>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector6
 * '<S224>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector7
 * '<S225>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector8
 * '<S226>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/One_Based_Selector9
 * '<S227>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/SingleToFixdt1
 * '<S228>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/SingleToFixdt2
 * '<S229>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem
 * '<S230>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem1
 * '<S231>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem2
 * '<S232>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem3
 * '<S233>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem/Data Type Police Only single
 * '<S234>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem/If Action Subsystem3
 * '<S235>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem1/Data Type Police Only single
 * '<S236>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem1/If Action Subsystem3
 * '<S237>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem2/Data Type Police Only single
 * '<S238>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem2/If Action Subsystem3
 * '<S239>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem3/Data Type Police Only single
 * '<S240>' : tiFuSp_AUTOCODE/tiFuSp/F03_InjTiMFu/F02_InjmFu/F00_InjmFu/Subsystem3/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': tiFuSp
 */
#endif                                 /* RTW_HEADER_tiFuSp_h_ */

/*-------------------------------- end of file -------------------------------*/
