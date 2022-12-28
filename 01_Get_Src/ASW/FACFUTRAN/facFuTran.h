/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : facFuTran                                               */
/* !Description     : FACFUTRAN : INJECTED FUEL MASS CORRECTION FACTOR DURING LOAD TRANSIENT*/
/*                                                                            */
/* !Module          : facFuTran                                               */
/*                                                                            */
/* !File            : facFuTran.h                                             */
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
/*   Code generated on: Mon May 19 23:02:25 2014                              */
/*   Model name       : facFuTran_AUTOCODE.mdl                                */
/*   Model version    : 1.640                                                 */
/*   Root subsystem   : /facFuTran                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/FACFUTRAN/facFuTran.h_v   $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   etsasson                               $$Date::   02 Jun 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_facFuTran_h_
#define RTW_HEADER_facFuTran_h_
#ifndef facFuTran_COMMON_INCLUDES_
# define facFuTran_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "facFuTran_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MAX.h"
#include "rt_MIN.h"
#endif                                 /* facFuTran_COMMON_INCLUDES_ */

#include "facFuTran_types.h"

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

/* Block signals for system '<S42>/rising_edge' */
typedef struct {
  Boolean LogicalOperator;           /* '<S49>/Logical Operator' */
} rtB_rising_edge_facFuTran_i;

/* Block states (auto storage) for system '<S42>/rising_edge' */
typedef struct {
  Boolean UnitDelay_DSTATE;          /* '<S54>/Unit Delay' */
} rtDW_rising_edge_facFuTran_j;

/* Block signals for system '<S35>/facFuTranFctInit_Inhib' */
typedef struct {
  Float32 Switch1;                    /* '<S36>/Switch1' */
  Boolean LogicalOperator1;          /* '<S37>/Logical Operator1' */
  rtB_rising_edge_facFuTran_i rising_edge1;/* '<S37>/rising_edge1' */
  rtB_rising_edge_facFuTran_i rising_edge2;/* '<S42>/rising_edge2' */
  rtB_rising_edge_facFuTran_i rising_edge;/* '<S42>/rising_edge' */
} rtB_facFuTranFctInit_Inhib_facF;

/* Block states (auto storage) for system '<S35>/facFuTranFctInit_Inhib' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S46>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_a;          /* '<S41>/Unit Delay' */
  Boolean UnitDelay_DSTATE_b;        /* '<S38>/Unit Delay' */
  Boolean UnitDelay_DSTATE_e;        /* '<S47>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S44>/UnitDelay' */
  Boolean UnitDelay_c;               /* '<S44>/UnitDelay1' */
  Boolean UnitDelay_b;               /* '<S39>/UnitDelay' */
  Boolean UnitDelay_o;               /* '<S39>/UnitDelay1' */
  rtDW_rising_edge_facFuTran_j rising_edge1;/* '<S37>/rising_edge1' */
  rtDW_rising_edge_facFuTran_j rising_edge2;/* '<S42>/rising_edge2' */
  rtDW_rising_edge_facFuTran_j rising_edge;/* '<S42>/rising_edge' */
} rtDW_facFuTranFctInit_Inhib_fac;

/* Block signals for system '<S178>/rising_edge' */
typedef struct {
  Boolean LogicalOperator;           /* '<S185>/Logical Operator' */
} rtB_rising_edge_facFuTran;

/* Block states (auto storage) for system '<S178>/rising_edge' */
typedef struct {
  Boolean UnitDelay_DSTATE;          /* '<S187>/Unit Delay' */
} rtDW_rising_edge_facFuTran;

/* Block signals (auto storage) */
typedef struct {
  UInt32 VEMS_vidGET7;               /* '<S5>/VEMS_vidGET7' */
  UInt32 VEMS_vidGET7_h;             /* '<S35>/VEMS_vidGET7' */
  SInt16 VEMS_vidGET2;                /* '<S57>/VEMS_vidGET2' */
  SInt16 VEMS_vidGET8;                /* '<S90>/VEMS_vidGET8' */
  SInt16 VEMS_vidGET7_o;              /* '<S90>/VEMS_vidGET7' */
  SInt16 VEMS_vidGET9;                /* '<S90>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET4;               /* '<S57>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET8_a;             /* '<S5>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET13;              /* '<S90>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET11;              /* '<S90>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET8_n;             /* '<S35>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET3;               /* '<S57>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET;                /* '<S57>/VEMS_vidGET' */
  UInt16 VEMS_vidGET1;               /* '<S57>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET12;              /* '<S90>/VEMS_vidGET12' */
  UInt16 VEMS_vidGET10;              /* '<S90>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET9_j[6];          /* '<S5>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET9_c[6];          /* '<S35>/VEMS_vidGET9' */
  UInt16 Assignment[6];              /* '<S239>/Assignment' */
  UInt8 VEMS_vidGET1_k;              /* '<S5>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET4_p;              /* '<S5>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET_n;               /* '<S238>/VEMS_vidGET' */
  UInt8 VEMS_vidGET3_g[16];          /* '<S90>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET5[16];            /* '<S90>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET4_i[16];          /* '<S90>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET6[16];            /* '<S90>/VEMS_vidGET6' */
  UInt8 VEMS_vidGET1_d;              /* '<S35>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET4_m;              /* '<S35>/VEMS_vidGET4' */
  Boolean VEMS_vidGET5_a;            /* '<S57>/VEMS_vidGET5' */
  Boolean ConstVal;                  /* '<S59>/ConstVal' */
  Boolean ConstVal_2;                /* '<S59>/ConstVal_2' */
  Boolean Switch2;                   /* '<S60>/Switch2' */
  Boolean Switch2_p;                 /* '<S61>/Switch2' */
  Boolean VEMS_vidGET6_c;            /* '<S5>/VEMS_vidGET6' */
  Boolean VEMS_vidGET10_f;           /* '<S5>/VEMS_vidGET10' */
  Boolean VEMS_vidGET3_c;            /* '<S5>/VEMS_vidGET3' */
  Boolean VEMS_vidGET_j;             /* '<S5>/VEMS_vidGET' */
  Boolean VEMS_vidGET2_p;            /* '<S5>/VEMS_vidGET2' */
  Boolean VEMS_vidGET14;             /* '<S90>/VEMS_vidGET14' */
  Boolean VEMS_vidGET6_b;            /* '<S35>/VEMS_vidGET6' */
  Boolean VEMS_vidGET10_j;           /* '<S35>/VEMS_vidGET10' */
  Boolean VEMS_vidGET3_d;            /* '<S35>/VEMS_vidGET3' */
  Boolean VEMS_vidGET_k;             /* '<S35>/VEMS_vidGET' */
  Boolean VEMS_vidGET2_m;            /* '<S35>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET_p[16];           /* '<S90>/VEMS_vidGET' */
  UInt8 VEMS_vidGET1_m[16];          /* '<S90>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET2_d[16];          /* '<S90>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET5_b;              /* '<S5>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET5_e;              /* '<S35>/VEMS_vidGET5' */
  rtB_rising_edge_facFuTran_i rising_edge3;/* '<S58>/rising_edge3' */
  rtB_rising_edge_facFuTran_i rising_edge2_f;/* '<S58>/rising_edge2' */
  rtB_rising_edge_facFuTran_i rising_edge1_n;/* '<S58>/rising_edge1' */
  rtB_rising_edge_facFuTran_i rising_edge_h0;/* '<S58>/rising_edge' */
  rtB_facFuTranFctInit_Inhib_facF facFuTranFctInit_Inhib_c;/* '<S5>/facFuTranFctInit_Inhib' */
  rtB_rising_edge_facFuTran rising_edge1_i;/* '<S181>/rising_edge1' */
  rtB_rising_edge_facFuTran rising_edge_h;/* '<S181>/rising_edge' */
  rtB_rising_edge_facFuTran rising_edge2_e;/* '<S180>/rising_edge2' */
  rtB_rising_edge_facFuTran rising_edge1_b;/* '<S180>/rising_edge1' */
  rtB_rising_edge_facFuTran rising_edge2;/* '<S179>/rising_edge2' */
  rtB_rising_edge_facFuTran rising_edge1_d;/* '<S179>/rising_edge1' */
  rtB_rising_edge_facFuTran_i Rising_edge;/* '<S189>/Rising_edge' */
  rtB_rising_edge_facFuTran rising_edge1;/* '<S178>/rising_edge1' */
  rtB_rising_edge_facFuTran rising_edge_m;/* '<S178>/rising_edge' */
  rtB_facFuTranFctInit_Inhib_facF facFuTranFctInit_Inhib;/* '<S35>/facFuTranFctInit_Inhib' */
} BlockIO_facFuTran;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S233>/Unit Delay' */
  UInt16 UnitDelay;                  /* '<S190>/UnitDelay' */
  UInt16 UnitDelay_DSTATE_f;         /* '<S196>/Unit Delay' */
  Boolean UnitDelay_e;               /* '<S60>/UnitDelay' */
  Boolean UnitDelay_j;               /* '<S60>/UnitDelay1' */
  Boolean UnitDelay_a;               /* '<S61>/UnitDelay' */
  Boolean UnitDelay_k;               /* '<S61>/UnitDelay1' */
  Boolean UnitDelay_kb;              /* '<S214>/UnitDelay' */
  Boolean UnitDelay_ep;              /* '<S214>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_k;        /* '<S232>/Unit Delay' */
  Boolean UnitDelay_DSTATE_km;       /* '<S231>/Unit Delay' */
  Boolean UnitDelay_b;               /* '<S182>/UnitDelay' */
  Boolean UnitDelay_l;               /* '<S182>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_k1;       /* '<S95>/Unit Delay' */
  SInt8 If_ActiveSubsystem;           /* '<S90>/If' */
  rtDW_rising_edge_facFuTran_j rising_edge3;/* '<S58>/rising_edge3' */
  rtDW_rising_edge_facFuTran_j rising_edge2_f;/* '<S58>/rising_edge2' */
  rtDW_rising_edge_facFuTran_j rising_edge1_n;/* '<S58>/rising_edge1' */
  rtDW_rising_edge_facFuTran_j rising_edge_h0;/* '<S58>/rising_edge' */
  rtDW_facFuTranFctInit_Inhib_fac facFuTranFctInit_Inhib_c;/* '<S5>/facFuTranFctInit_Inhib' */
  rtDW_rising_edge_facFuTran rising_edge1_i;/* '<S181>/rising_edge1' */
  rtDW_rising_edge_facFuTran rising_edge_h;/* '<S181>/rising_edge' */
  rtDW_rising_edge_facFuTran rising_edge2_e;/* '<S180>/rising_edge2' */
  rtDW_rising_edge_facFuTran rising_edge1_b;/* '<S180>/rising_edge1' */
  rtDW_rising_edge_facFuTran rising_edge2;/* '<S179>/rising_edge2' */
  rtDW_rising_edge_facFuTran rising_edge1_d;/* '<S179>/rising_edge1' */
  rtDW_rising_edge_facFuTran_j Rising_edge;/* '<S189>/Rising_edge' */
  rtDW_rising_edge_facFuTran rising_edge1;/* '<S178>/rising_edge1' */
  rtDW_rising_edge_facFuTran rising_edge_m;/* '<S178>/rising_edge' */
  rtDW_facFuTranFctInit_Inhib_fac facFuTranFctInit_Inhib;/* '<S35>/facFuTranFctInit_Inhib' */
} D_Work_facFuTran;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S173>/Lookup Table (n-D)'
   *   '<S174>/Lookup Table (n-D)'
   */
  UInt32 pooled9[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S17>/Logic'
   *   '<S60>/Logic'
   *   '<S61>/Logic'
   *   '<S22>/Logic'
   *   '<S39>/Logic'
   *   '<S44>/Logic'
   *   '<S182>/Logic'
   *   '<S214>/Logic'
   */
  Boolean pooled19[16];
} ConstParam_facFuTran;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define FACFUTRAN_START_SEC_VAR_UNSPECIFIED
#include "facFuTran_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_facFuTran facFuTran_B;

/* Block states (auto storage) */
extern D_Work_facFuTran facFuTran_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_facFuTran facFuTran_ConstP;

#define FACFUTRAN_STOP_SEC_VAR_UNSPECIFIED
#include "facFuTran_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define FACFUTRAN_START_SEC_CODE
#include "facFuTran_MemMap.h"

/* Model entry point functions */
extern void facFuTran_initialize(void);
extern void InjSys_SdlFast_facFuTran(void);
extern void InjSys_EveRst_facFuTran(void);
extern void InjSys_EveInj_facFuTran(void);

#define FACFUTRAN_STOP_SEC_CODE
#include "facFuTran_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define FACFUTRAN_START_SEC_CALIB_16BIT
#include "facFuTran_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4095.0                                                            */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_ctNbCmbAst_A[9];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facCorAst_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facCorExtCd_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal1_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal2_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal3_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal4_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal5_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranAccCal6_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal1_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal2_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal3_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal4_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal5_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_facTranDecCal6_M[81];

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_mAirInjSpTranY_A[9];

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_mAirPredInjSp_A[9];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_nEngInjSpTranX_A[9];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_nEngInjSp_A[9];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, FACFUTRAN_CALIB) InjSys_nMaxAcvWf_C;

#define FACFUTRAN_STOP_SEC_CALIB_16BIT
#include "facFuTran_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define FACFUTRAN_START_SEC_CALIB_8BIT
#include "facFuTran_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 15.9375                                                           */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_facDetAccTranHiThr_M[81];

/* Type:    UInt8                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 15.9375                                                           */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_facDetDecTranLoThr_M[81];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_idxModInjTranSatMax_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_idxModInjTranSatMin_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_noClcnAftrReInjThr_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    1.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 256.0                                                             */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_noCmbRmpTranAcc_M[81];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    1.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 256.0                                                             */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_noCmbRmpTranDec_M[81];

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.99609375                                                        */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_rDetAccTranHiThr_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.99609375                                                        */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_rDetAccTranLoThr_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    -1.0                                                              */
/* Units:   -                                                                 */
/* PhysMin: -1.0                                                              */
/* PhysMax: -0.00390625                                                       */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_rDetDecTranHiThr_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    -1.0                                                              */
/* Units:   -                                                                 */
/* PhysMin: -1.0                                                              */
/* PhysMax: -0.00390625                                                       */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_rDetDecTranLoThr_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_rGainFilAccCmp_M[81];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_rGainFilDecCmp_M[81];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -50.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 200.0                                                             */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_tAirExtMes_A[9];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_tCoMes_A[9];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_tCoStrtMes_A[9];

/* Type:    UInt8                                                           */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_tiDlyAcvWfSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt8, FACFUTRAN_CALIB) InjSys_tiDlyAcvWf_C;

#define FACFUTRAN_STOP_SEC_CALIB_8BIT
#include "facFuTran_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define FACFUTRAN_START_SEC_CALIB_BOOLEAN
#include "facFuTran_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FACFUTRAN_CALIB) InjSys_bAcvFISAWupAdp_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FACFUTRAN_CALIB) InjSys_bAcvWfModTran_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FACFUTRAN_CALIB) InjSys_bAcvWfResuTran_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FACFUTRAN_CALIB) InjSys_bAcvfacFuTranClcn_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FACFUTRAN_CALIB) InjSys_bInhReInjCond_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, FACFUTRAN_CALIB) InjSys_bSelVarInjSys_C;

#define FACFUTRAN_STOP_SEC_CALIB_BOOLEAN
#include "facFuTran_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define FACFUTRAN_START_SEC_VAR_16BIT
#include "facFuTran_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.5999755859375000E+001                                           */
extern VAR(UInt16, FACFUTRAN_VAR) InjSys_prm_facTranCmpCylRaw[6];

#define FACFUTRAN_STOP_SEC_VAR_16BIT
#include "facFuTran_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define FACFUTRAN_START_SEC_VAR_BOOLEAN
#include "facFuTran_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvWfCmp;

#define FACFUTRAN_STOP_SEC_VAR_BOOLEAN
#include "facFuTran_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S17>/LO3' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Relational Operator' : Unused code path elimination
 * Block '<S23>/Relational Operator1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/LO3' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Relational Operator' : Unused code path elimination
 * Block '<S45>/Relational Operator1' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Propagation' : Unused code path elimination
 * Block '<S60>/LO3' : Unused code path elimination
 * Block '<S61>/LO3' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S64>/x' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S65>/x' : Unused code path elimination
 * Block '<S68>/BKPT1' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S68>/TABLE' : Unused code path elimination
 * Block '<S69>/BKPT1' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S69>/TABLE' : Unused code path elimination
 * Block '<S58>/InjSys_tCoMes_A' : Unused code path elimination
 * Block '<S58>/InjSys_tCoMes_A_2' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S70>/x' : Unused code path elimination
 * Block '<S73>/Data Type Propagation' : Unused code path elimination
 * Block '<S73>/Data Type Propagation1' : Unused code path elimination
 * Block '<S84>/Data Type Propagation' : Unused code path elimination
 * Block '<S84>/Data Type Conversion' : Unused code path elimination
 * Block '<S84>/Data Type Conversion1' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S111>/Relational Operator' : Unused code path elimination
 * Block '<S111>/Relational Operator1' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Propagation' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Relational Operator' : Unused code path elimination
 * Block '<S112>/Relational Operator1' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Propagation' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Relational Operator' : Unused code path elimination
 * Block '<S113>/Relational Operator1' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Propagation' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S114>/Relational Operator' : Unused code path elimination
 * Block '<S114>/Relational Operator1' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Propagation' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S140>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S140>/x' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S141>/x' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate' : Unused code path elimination
 * Block '<S155>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S163>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Relational Operator' : Unused code path elimination
 * Block '<S161>/Relational Operator1' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Data Type Propagation' : Unused code path elimination
 * Block '<S166>/Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Relational Operator' : Unused code path elimination
 * Block '<S165>/Relational Operator1' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Propagation' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Relational Operator' : Unused code path elimination
 * Block '<S169>/Relational Operator1' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Propagation' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S173>/x1' : Unused code path elimination
 * Block '<S173>/x2' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S174>/x1' : Unused code path elimination
 * Block '<S174>/x2' : Unused code path elimination
 * Block '<S182>/LO3' : Unused code path elimination
 * Block '<S178>/InjSys_nEngInjSpTranX_A' : Unused code path elimination
 * Block '<S178>/InjSys_nEngInjSpTranX_A_2' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S183>/TABLE' : Unused code path elimination
 * Block '<S183>/TABLE1' : Unused code path elimination
 * Block '<S183>/TABLE2' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S184>/TABLE' : Unused code path elimination
 * Block '<S184>/TABLE1' : Unused code path elimination
 * Block '<S184>/TABLE2' : Unused code path elimination
 * Block '<S178>/InjSys_tCoMes_A' : Unused code path elimination
 * Block '<S178>/InjSys_tCoMes_A_2' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Relational Operator' : Unused code path elimination
 * Block '<S193>/Relational Operator1' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S199>/Data Type Propagation' : Unused code path elimination
 * Block '<S200>/Data Type Duplicate' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Relational Operator' : Unused code path elimination
 * Block '<S194>/Relational Operator1' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate' : Unused code path elimination
 * Block '<S202>/Data Type Propagation' : Unused code path elimination
 * Block '<S206>/Data Type Propagation' : Unused code path elimination
 * Block '<S206>/Data Type Propagation1' : Unused code path elimination
 * Block '<S210>/Data Type Propagation' : Unused code path elimination
 * Block '<S210>/Data Type Conversion' : Unused code path elimination
 * Block '<S210>/Data Type Conversion1' : Unused code path elimination
 * Block '<S214>/LO3' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S229>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Relational Operator' : Unused code path elimination
 * Block '<S223>/Relational Operator1' : Unused code path elimination
 * Block '<S230>/Data Type Duplicate' : Unused code path elimination
 * Block '<S230>/Data Type Propagation' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S216>/x' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S219>/x' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S29>/Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Conversion' : Eliminate redundant data type conversion
 * Block '<S51>/Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S68>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S69>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S96>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S96>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S96>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S96>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S119>/Conversion' : Eliminate redundant data type conversion
 * Block '<S120>/Conversion' : Eliminate redundant data type conversion
 * Block '<S122>/Conversion' : Eliminate redundant data type conversion
 * Block '<S123>/Conversion' : Eliminate redundant data type conversion
 * Block '<S125>/Conversion' : Eliminate redundant data type conversion
 * Block '<S126>/Conversion' : Eliminate redundant data type conversion
 * Block '<S128>/Conversion' : Eliminate redundant data type conversion
 * Block '<S129>/Conversion' : Eliminate redundant data type conversion
 * Block '<S162>/Conversion' : Eliminate redundant data type conversion
 * Block '<S163>/Conversion' : Eliminate redundant data type conversion
 * Block '<S166>/Conversion' : Eliminate redundant data type conversion
 * Block '<S167>/Conversion' : Eliminate redundant data type conversion
 * Block '<S170>/Conversion' : Eliminate redundant data type conversion
 * Block '<S171>/Conversion' : Eliminate redundant data type conversion
 * Block '<S183>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S183>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S184>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S184>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S198>/Conversion' : Eliminate redundant data type conversion
 * Block '<S200>/Conversion' : Eliminate redundant data type conversion
 * Block '<S201>/Conversion' : Eliminate redundant data type conversion
 * Block '<S189>/Switch1' : Eliminated due to constant selection input
 * Block '<S206>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S206>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S206>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S228>/Conversion' : Eliminate redundant data type conversion
 * Block '<S229>/Conversion' : Eliminate redundant data type conversion
 * Block '<S220>/Switch' : Eliminated due to constant selection input
 * Block '<S179>/ConstVal_3' : Unused code path elimination
 * Block '<S220>/Add3' : Unused code path elimination
 * Block '<S220>/Add4' : Unused code path elimination
 * Block '<S220>/Constant' : Unused code path elimination
 * Block '<S220>/Relational Operator' : Unused code path elimination
 * Block '<S220>/Switch1' : Unused code path elimination
 * Block '<S220>/offset2' : Unused code path elimination
 * Block '<S220>/offset3' : Unused code path elimination
 * Block '<S220>/offset4' : Unused code path elimination
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
 * hilite_system('facFuTran_AUTOCODE/facFuTran')    - opens subsystem facFuTran_AUTOCODE/facFuTran
 * hilite_system('facFuTran_AUTOCODE/facFuTran/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : facFuTran_AUTOCODE
 * '<S4>'   : facFuTran_AUTOCODE/facFuTran
 * '<S5>'   : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit
 * '<S6>'   : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib
 * '<S7>'   : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct
 * '<S8>'   : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct
 * '<S9>'   : facFuTran_AUTOCODE/facFuTran/F02_InjSys_facFuTranSync
 * '<S10>'  : facFuTran_AUTOCODE/facFuTran/F03_RstDetTran
 * '<S11>'  : facFuTran_AUTOCODE/facFuTran/fc_demux1
 * '<S12>'  : facFuTran_AUTOCODE/facFuTran/fc_demux2
 * '<S13>'  : facFuTran_AUTOCODE/facFuTran/fc_demux3
 * '<S14>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib
 * '<S15>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp
 * '<S16>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/SubSystem
 * '<S17>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/BasculeRS1
 * '<S18>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/One_Based_Selector
 * '<S19>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/SubSystem
 * '<S20>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS
 * '<S21>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/rising_edge1
 * '<S22>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/BasculeRS
 * '<S23>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/Clamp
 * '<S24>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/SubSystem
 * '<S25>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/SubSystem1
 * '<S26>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/multiplication_1
 * '<S27>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/rising_edge
 * '<S28>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/rising_edge2
 * '<S29>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/Clamp/Data Type Conversion Inherited
 * '<S30>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S31>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/Clamp/Saturation Dynamic
 * '<S32>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/rising_edge/SubSystem
 * '<S33>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/rising_edge2/SubSystem
 * '<S34>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/rising_edge1/SubSystem
 * '<S35>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit
 * '<S36>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib
 * '<S37>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp
 * '<S38>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/SubSystem
 * '<S39>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/BasculeRS1
 * '<S40>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/One_Based_Selector
 * '<S41>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/SubSystem
 * '<S42>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS
 * '<S43>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/rising_edge1
 * '<S44>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/BasculeRS
 * '<S45>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/Clamp
 * '<S46>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/SubSystem
 * '<S47>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/SubSystem1
 * '<S48>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/multiplication_1
 * '<S49>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/rising_edge
 * '<S50>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/rising_edge2
 * '<S51>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/Clamp/Data Type Conversion Inherited
 * '<S52>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S53>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/Clamp/Saturation Dynamic
 * '<S54>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/rising_edge/SubSystem
 * '<S55>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/TurnONDelay_VEMS/rising_edge2/SubSystem
 * '<S56>'  : facFuTran_AUTOCODE/facFuTran/F00_facFuTranFctInit_Inhib/F00_facFuTranFctInit/facFuTranFctInit_Inhib/F01_bACvWfCmp/rising_edge1/SubSystem
 * '<S57>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib
 * '<S58>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn
 * '<S59>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F02_DetTrannoClcn
 * '<S60>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/BasculeRS
 * '<S61>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/BasculeRS1
 * '<S62>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Hysteresis1
 * '<S63>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Hysteresis2
 * '<S64>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/InjSys_nEngInjSp_A_PreLookUp
 * '<S65>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/InjSys_nEngInjSp_A_PreLookUp1
 * '<S66>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/InjSys_rDetAccTranHiThr_T
 * '<S67>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/InjSys_rDetAccTranLoThr_T
 * '<S68>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/InjSys_rDetDecTranHiThr_T
 * '<S69>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/InjSys_rDetDecTranLoThr_T
 * '<S70>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/InjSys_tCoMes_A_PreLookUp
 * '<S71>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Interp_2D
 * '<S72>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Interp_2D1
 * '<S73>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Subsystem
 * '<S74>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/multiplication_1
 * '<S75>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/multiplication_412
 * '<S76>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/rising_edge
 * '<S77>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/rising_edge1
 * '<S78>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/rising_edge2
 * '<S79>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/rising_edge3
 * '<S80>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Hysteresis1/If Action Subsystem
 * '<S81>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Hysteresis1/If Action Subsystem1
 * '<S82>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Hysteresis2/If Action Subsystem
 * '<S83>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Hysteresis2/If Action Subsystem1
 * '<S84>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Subsystem/Data Type Police Only single
 * '<S85>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/Subsystem/If Action Subsystem3
 * '<S86>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/rising_edge/SubSystem
 * '<S87>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/rising_edge1/SubSystem
 * '<S88>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/rising_edge2/SubSystem
 * '<S89>'  : facFuTran_AUTOCODE/facFuTran/F00b_DetTranFct/DetTranFct_Inhib/F01_DetTranClcn/rising_edge3/SubSystem
 * '<S90>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct
 * '<S91>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F00_DetAcvfacFuTran
 * '<S92>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn
 * '<S93>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F02_facFuTrannoClcn
 * '<S94>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F00_DetAcvfacFuTran/rising_edge
 * '<S95>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F00_DetAcvfacFuTran/rising_edge/SubSystem
 * '<S96>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F01_IfEOMfacTranSp
 * '<S97>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn
 * '<S98>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F04_facTranCmpIniClcn
 * '<S99>'  : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn
 * '<S100>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F01_IfEOMfacTranSp/One_Based_Selector
 * '<S101>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F01_IfEOMfacTranSp/One_Based_Selector1
 * '<S102>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F01_IfEOMfacTranSp/One_Based_Selector2
 * '<S103>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F01_IfEOMfacTranSp/One_Based_Selector3
 * '<S104>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F01_IfEOMfacTranSp/One_Based_Selector4
 * '<S105>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F01_IfEOMfacTranSp/One_Based_Selector5
 * '<S106>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F01_IfEOMfacTranSp/One_Based_Selector6
 * '<S107>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran
 * '<S108>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran
 * '<S109>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F03_Select_Modes_InjTran
 * '<S110>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran
 * '<S111>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp
 * '<S112>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp1
 * '<S113>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp2
 * '<S114>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp3
 * '<S115>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/One_Based_Assignment
 * '<S116>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/One_Based_Assignment1
 * '<S117>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/One_Based_Assignment2
 * '<S118>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/One_Based_Assignment3
 * '<S119>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp/Data Type Conversion Inherited
 * '<S120>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp/Data Type Conversion Inherited1
 * '<S121>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp/Saturation Dynamic
 * '<S122>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp1/Data Type Conversion Inherited
 * '<S123>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp1/Data Type Conversion Inherited1
 * '<S124>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp1/Saturation Dynamic
 * '<S125>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp2/Data Type Conversion Inherited
 * '<S126>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp2/Data Type Conversion Inherited1
 * '<S127>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp2/Saturation Dynamic
 * '<S128>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp3/Data Type Conversion Inherited
 * '<S129>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp3/Data Type Conversion Inherited1
 * '<S130>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F01_Mode_Mask_InjTran/Clamp3/Saturation Dynamic
 * '<S131>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F01_Unvectorize_Activation_Boolean_InjTran
 * '<S132>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F02_Calibration_1_InjTran
 * '<S133>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F03_Calibration_2_InjTran
 * '<S134>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F04_Calibration_3_InjTran
 * '<S135>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F05_Calibration_4_InjTran
 * '<S136>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F06_Calibration_5_InjTran
 * '<S137>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F07_Calibration_6_InjTran
 * '<S138>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F08_Vectorize_Calibrations_InjTranDec
 * '<S139>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F09_Vectorize_Calibrations_InjTranAcc
 * '<S140>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/InjSys_mAirInjSpTranY_A_PreLookUp
 * '<S141>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/InjSys_nEngInjSpTranX_A_PreLookUp
 * '<S142>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F02_Calibration_1_InjTran/InjSys_facTranAccCal1_M
 * '<S143>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F02_Calibration_1_InjTran/InjSys_facTranDecCal1_M
 * '<S144>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F03_Calibration_2_InjTran/InjSys_facTranAccCal2_M
 * '<S145>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F03_Calibration_2_InjTran/InjSys_facTranDecCal2_M
 * '<S146>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F04_Calibration_3_InjTran/InjSys_facTranAccCal3_M
 * '<S147>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F04_Calibration_3_InjTran/InjSys_facTranDecCal3_M
 * '<S148>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F05_Calibration_4_InjTran/InjSys_facTranAccCal4_M
 * '<S149>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F05_Calibration_4_InjTran/InjSys_facTranDecCal4_M
 * '<S150>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F06_Calibration_5_InjTran/InjSys_facTranAccCal5_M
 * '<S151>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F06_Calibration_5_InjTran/InjSys_facTranDecCal5_M
 * '<S152>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F07_Calibration_6_InjTran/InjSys_facTranAccCal6_M
 * '<S153>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F02_Calibrations_InjTran/F07_Calibration_6_InjTran/InjSys_facTranDecCal6_M
 * '<S154>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F03_Select_Modes_InjTran/One_Based_Selector
 * '<S155>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F03_Select_Modes_InjTran/One_Based_Selector1
 * '<S156>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F03_Select_Modes_InjTran/One_Based_Selector2
 * '<S157>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F03_Select_Modes_InjTran/One_Based_Selector3
 * '<S158>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS1
 * '<S159>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS2
 * '<S160>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS3
 * '<S161>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS1/Clamp
 * '<S162>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited
 * '<S163>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited1
 * '<S164>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS1/Clamp/Saturation Dynamic
 * '<S165>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS2/Clamp
 * '<S166>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS2/Clamp/Data Type Conversion Inherited
 * '<S167>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS2/Clamp/Data Type Conversion Inherited1
 * '<S168>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS2/Clamp/Saturation Dynamic
 * '<S169>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS3/Clamp
 * '<S170>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS3/Clamp/Data Type Conversion Inherited
 * '<S171>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS3/Clamp/Data Type Conversion Inherited1
 * '<S172>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F03_facTranSpClcn/F04_Interpolation_InjTran/BaryCentre_VEMS3/Clamp/Saturation Dynamic
 * '<S173>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F04_facTranCmpIniClcn/InjSys_facCorAst_M
 * '<S174>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F04_facTranCmpIniClcn/InjSys_facCorExtCd_M
 * '<S175>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F04_facTranCmpIniClcn/multiplication_1
 * '<S176>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F04_facTranCmpIniClcn/multiplication_412
 * '<S177>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F04_facTranCmpIniClcn/multiplication_421
 * '<S178>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F01_TranRmpClcn
 * '<S179>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn
 * '<S180>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp
 * '<S181>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil
 * '<S182>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F01_TranRmpClcn/BasculeRS1
 * '<S183>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F01_TranRmpClcn/InjSys_noCmbRmpTranAcc_M
 * '<S184>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F01_TranRmpClcn/InjSys_noCmbRmpTranDec_M
 * '<S185>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F01_TranRmpClcn/rising_edge
 * '<S186>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F01_TranRmpClcn/rising_edge1
 * '<S187>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F01_TranRmpClcn/rising_edge/SubSystem
 * '<S188>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F01_TranRmpClcn/rising_edge1/SubSystem
 * '<S189>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1
 * '<S190>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Mem
 * '<S191>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/rising_edge1
 * '<S192>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/rising_edge2
 * '<S193>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Clamp
 * '<S194>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Clamp1
 * '<S195>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Rising_edge
 * '<S196>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/SubSystem
 * '<S197>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Clamp/Data Type Conversion Inherited
 * '<S198>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Clamp/Data Type Conversion Inherited1
 * '<S199>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Clamp/Saturation Dynamic
 * '<S200>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Clamp1/Data Type Conversion Inherited
 * '<S201>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Clamp1/Data Type Conversion Inherited1
 * '<S202>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Clamp1/Saturation Dynamic
 * '<S203>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/Counter1/Rising_edge/SubSystem
 * '<S204>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/rising_edge1/SubSystem
 * '<S205>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F02_NbCmbTranClcn/rising_edge2/SubSystem
 * '<S206>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp/Subsystem
 * '<S207>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp/multiplication_431
 * '<S208>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp/rising_edge1
 * '<S209>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp/rising_edge2
 * '<S210>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp/Subsystem/Data Type Police Only single
 * '<S211>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp/Subsystem/If Action Subsystem3
 * '<S212>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp/rising_edge1/SubSystem
 * '<S213>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F03_TranCmpRmp/rising_edge2/SubSystem
 * '<S214>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/BasculeRS1
 * '<S215>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK
 * '<S216>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/InjSys_nEngInjSpTranX_A_PreLookUp
 * '<S217>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/InjSys_rGainFilAccCmp_M
 * '<S218>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/InjSys_rGainFilDecCmp_M
 * '<S219>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/InjSys_tCoMes_A_PreLookUp
 * '<S220>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/SingleToFixdt
 * '<S221>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/rising_edge
 * '<S222>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/rising_edge1
 * '<S223>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/Clamp1
 * '<S224>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/IniCdn
 * '<S225>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/UnitDly_ExtIni1
 * '<S226>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/multiplication1
 * '<S227>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/multiplication2
 * '<S228>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/Clamp1/Data Type Conversion Inherited
 * '<S229>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/Clamp1/Data Type Conversion Inherited1
 * '<S230>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/Clamp1/Saturation Dynamic
 * '<S231>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/IniCdn/SubSystem
 * '<S232>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/UnitDly_ExtIni1/SubSystem
 * '<S233>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/DLowPassFilter_TypeK/UnitDly_ExtIni1/SubSystem1
 * '<S234>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/rising_edge/SubSystem
 * '<S235>' : facFuTran_AUTOCODE/facFuTran/F01_facFuTranFct/F01_facFuTranFct/F01_facFuTranClcn/F05_facTranCmpFilClcn/F04_TranCmpFil/rising_edge1/SubSystem
 * '<S236>' : facFuTran_AUTOCODE/facFuTran/F02_InjSys_facFuTranSync/F01_facFuTranRst
 * '<S237>' : facFuTran_AUTOCODE/facFuTran/F02_InjSys_facFuTranSync/F02_facFuTranSync
 * '<S238>' : facFuTran_AUTOCODE/facFuTran/F02_InjSys_facFuTranSync/F02_facFuTranSync/F02_facFuTranSync
 * '<S239>' : facFuTran_AUTOCODE/facFuTran/F02_InjSys_facFuTranSync/F02_facFuTranSync/F02_facFuTranSync/One_Based_Assignment
 * '<S240>' : facFuTran_AUTOCODE/facFuTran/F03_RstDetTran/F03_RstDetTran
 */

/*-
 * Requirements for '<Root>': facFuTran
 */
#endif                                 /* RTW_HEADER_facFuTran_h_ */

/*-------------------------------- end of file -------------------------------*/
