/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjResuCmp                                              */
/* !Description     : InjResuCmp : INJECTION COMPENSATION AFTER CUT OFF       */
/*                                                                            */
/* !Module          : InjResuCmp                                              */
/*                                                                            */
/* !File            : InjResuCmp.h                                            */
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
/*   Code generated on: Mon Dec 02 18:06:23 2013                              */
/*   Model name       : InjResuCmp_AUTOCODE.mdl                               */
/*   Model version    : 1.293                                                 */
/*   Root subsystem   : /InjResuCmp                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJRESUCMP/InjResuCmp.h_v $*/
/* $Revision::   1.5                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Dec 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjResuCmp_h_
#define RTW_HEADER_InjResuCmp_h_
#ifndef InjResuCmp_COMMON_INCLUDES_
# define InjResuCmp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "InjResuCmp_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#endif                                 /* InjResuCmp_COMMON_INCLUDES_ */

#include "InjResuCmp_types.h"

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

/* Block signals for system '<S15>/rising_edge10' */
typedef struct {
  Boolean LogicalOperator;           /* '<S35>/Logical Operator' */
} rtB_rising_edge10_InjResuCmp;

/* Block states (auto storage) for system '<S15>/rising_edge10' */
typedef struct {
  Boolean UnitDelay_DSTATE;          /* '<S42>/Unit Delay' */
} rtDW_rising_edge10_InjResuCmp;

/* Block signals for system '<S50>/Counter' */
typedef struct {
  UInt16 Switch2;                    /* '<S102>/Switch2' */
  rtB_rising_edge10_InjResuCmp rising_edge6;/* '<S56>/rising_edge6' */
} rtB_Counter_InjResuCmp;

/* Block states (auto storage) for system '<S50>/Counter' */
typedef struct {
  UInt16 UnitDelay_DSTATE;           /* '<S95>/Unit Delay' */
  rtDW_rising_edge10_InjResuCmp rising_edge6;/* '<S56>/rising_edge6' */
} rtDW_Counter_InjResuCmp;

/* Block signals for system '<S52>/falling_edge1' */
typedef struct {
  Boolean LogicalOperator;           /* '<S193>/Logical Operator' */
} rtB_falling_edge1_InjResuCmp;

/* Block states (auto storage) for system '<S52>/falling_edge1' */
typedef struct {
  Boolean UnitDelay_DSTATE;          /* '<S205>/Unit Delay' */
} rtDW_falling_edge1_InjResuCmp;

/* Block signals (auto storage) */
typedef struct {
  SInt16 VEMS_vidGET4;                /* '<S49>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET2;               /* '<S49>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET1[6];            /* '<S49>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET5;               /* '<S49>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET8[6];            /* '<S49>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET7[6];            /* '<S49>/VEMS_vidGET7' */
  UInt16 OutDTConv[6];               /* '<S331>/OutDTConv' */
  UInt8 VEMS_vidGET3[6];             /* '<S49>/VEMS_vidGET3' */
  Boolean VEMS_vidGET6[6];           /* '<S49>/VEMS_vidGET6' */
  Boolean VEMS_vidGET;               /* '<S49>/VEMS_vidGET' */
  Boolean VEMS_vidGET9;              /* '<S49>/VEMS_vidGET9' */
  Boolean VEMS_vidGET_d[6];          /* '<S15>/VEMS_vidGET' */
  rtB_rising_edge10_InjResuCmp rising_edge7_j;/* '<S53>/rising_edge7' */
  rtB_rising_edge10_InjResuCmp rising_edge5_f;/* '<S53>/rising_edge5' */
  rtB_rising_edge10_InjResuCmp rising_edge4_k;/* '<S53>/rising_edge4' */
  rtB_rising_edge10_InjResuCmp rising_edge3_e;/* '<S53>/rising_edge3' */
  rtB_rising_edge10_InjResuCmp rising_edge2_p;/* '<S53>/rising_edge2' */
  rtB_rising_edge10_InjResuCmp rising_edge1_c;/* '<S53>/rising_edge1' */
  rtB_Counter_InjResuCmp Counter5_n;   /* '<S53>/Counter5' */
  rtB_Counter_InjResuCmp Counter4_b;   /* '<S53>/Counter4' */
  rtB_Counter_InjResuCmp Counter3_h;   /* '<S53>/Counter3' */
  rtB_Counter_InjResuCmp Counter2_o;   /* '<S53>/Counter2' */
  rtB_Counter_InjResuCmp Counter1_h;   /* '<S53>/Counter1' */
  rtB_Counter_InjResuCmp Counter_e;    /* '<S53>/Counter' */
  rtB_rising_edge10_InjResuCmp rising_edge6_e;/* '<S52>/rising_edge6' */
  rtB_rising_edge10_InjResuCmp rising_edge5_g;/* '<S52>/rising_edge5' */
  rtB_rising_edge10_InjResuCmp rising_edge4_c;/* '<S52>/rising_edge4' */
  rtB_rising_edge10_InjResuCmp rising_edge3_f;/* '<S52>/rising_edge3' */
  rtB_rising_edge10_InjResuCmp rising_edge2_g;/* '<S52>/rising_edge2' */
  rtB_rising_edge10_InjResuCmp rising_edge1_k;/* '<S52>/rising_edge1' */
  rtB_falling_edge1_InjResuCmp falling_edge6;/* '<S52>/falling_edge6' */
  rtB_falling_edge1_InjResuCmp falling_edge5;/* '<S52>/falling_edge5' */
  rtB_falling_edge1_InjResuCmp falling_edge4;/* '<S52>/falling_edge4' */
  rtB_falling_edge1_InjResuCmp falling_edge3;/* '<S52>/falling_edge3' */
  rtB_falling_edge1_InjResuCmp falling_edge2;/* '<S52>/falling_edge2' */
  rtB_falling_edge1_InjResuCmp falling_edge1;/* '<S52>/falling_edge1' */
  rtB_rising_edge10_InjResuCmp rising_edge9_n;/* '<S50>/rising_edge9' */
  rtB_rising_edge10_InjResuCmp rising_edge8_a;/* '<S50>/rising_edge8' */
  rtB_rising_edge10_InjResuCmp rising_edge7;/* '<S50>/rising_edge7' */
  rtB_rising_edge10_InjResuCmp rising_edge6_k;/* '<S50>/rising_edge6' */
  rtB_rising_edge10_InjResuCmp rising_edge5;/* '<S50>/rising_edge5' */
  rtB_rising_edge10_InjResuCmp rising_edge4;/* '<S50>/rising_edge4' */
  rtB_rising_edge10_InjResuCmp rising_edge3;/* '<S50>/rising_edge3' */
  rtB_rising_edge10_InjResuCmp rising_edge2;/* '<S50>/rising_edge2' */
  rtB_rising_edge10_InjResuCmp rising_edge12_h;/* '<S50>/rising_edge12' */
  rtB_rising_edge10_InjResuCmp rising_edge11_i;/* '<S50>/rising_edge11' */
  rtB_rising_edge10_InjResuCmp rising_edge10_k;/* '<S50>/rising_edge10' */
  rtB_rising_edge10_InjResuCmp rising_edge1;/* '<S50>/rising_edge1' */
  rtB_Counter_InjResuCmp Counter5;     /* '<S50>/Counter5' */
  rtB_Counter_InjResuCmp Counter4;     /* '<S50>/Counter4' */
  rtB_Counter_InjResuCmp Counter3;     /* '<S50>/Counter3' */
  rtB_Counter_InjResuCmp Counter2;     /* '<S50>/Counter2' */
  rtB_Counter_InjResuCmp Counter1;     /* '<S50>/Counter1' */
  rtB_Counter_InjResuCmp Counter;      /* '<S50>/Counter' */
  rtB_rising_edge10_InjResuCmp rising_edge9;/* '<S15>/rising_edge9' */
  rtB_rising_edge10_InjResuCmp rising_edge8;/* '<S15>/rising_edge8' */
  rtB_rising_edge10_InjResuCmp rising_edge6;/* '<S15>/rising_edge6' */
  rtB_rising_edge10_InjResuCmp rising_edge13;/* '<S15>/rising_edge13' */
  rtB_rising_edge10_InjResuCmp rising_edge12;/* '<S15>/rising_edge12' */
  rtB_rising_edge10_InjResuCmp rising_edge11;/* '<S15>/rising_edge11' */
  rtB_rising_edge10_InjResuCmp rising_edge10;/* '<S15>/rising_edge10' */
} BlockIO_InjResuCmp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt16 UnitDelay_DSTATE[6];        /* '<S235>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_e[6];      /* '<S80>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S174>/UnitDelay' */
  Boolean UnitDelay_n;               /* '<S174>/UnitDelay1' */
  Boolean UnitDelay_c;               /* '<S175>/UnitDelay' */
  Boolean UnitDelay_l;               /* '<S175>/UnitDelay1' */
  Boolean UnitDelay_j;               /* '<S176>/UnitDelay' */
  Boolean UnitDelay_nc;              /* '<S176>/UnitDelay1' */
  Boolean UnitDelay_g;               /* '<S177>/UnitDelay' */
  Boolean UnitDelay_gw;              /* '<S177>/UnitDelay1' */
  Boolean UnitDelay_i;               /* '<S178>/UnitDelay' */
  Boolean UnitDelay_p;               /* '<S178>/UnitDelay1' */
  Boolean UnitDelay_o;               /* '<S179>/UnitDelay' */
  Boolean UnitDelay_na;              /* '<S179>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_c[6];     /* '<S192>/Unit Delay' */
  Boolean UnitDelay_oz;              /* '<S16>/UnitDelay' */
  Boolean UnitDelay_ncb;             /* '<S16>/UnitDelay1' */
  Boolean UnitDelay_lq;              /* '<S17>/UnitDelay' */
  Boolean UnitDelay_k;               /* '<S17>/UnitDelay1' */
  Boolean UnitDelay_pr;              /* '<S18>/UnitDelay' */
  Boolean UnitDelay_ci;              /* '<S18>/UnitDelay1' */
  Boolean UnitDelay_gb;              /* '<S19>/UnitDelay' */
  Boolean UnitDelay_lk;              /* '<S19>/UnitDelay1' */
  Boolean UnitDelay_nb;              /* '<S20>/UnitDelay' */
  Boolean UnitDelay_f;               /* '<S20>/UnitDelay1' */
  Boolean UnitDelay_oj;              /* '<S21>/UnitDelay' */
  Boolean UnitDelay_a;               /* '<S21>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_p[6];     /* '<S34>/Unit Delay' */
  rtDW_rising_edge10_InjResuCmp rising_edge7_j;/* '<S53>/rising_edge7' */
  rtDW_rising_edge10_InjResuCmp rising_edge5_f;/* '<S53>/rising_edge5' */
  rtDW_rising_edge10_InjResuCmp rising_edge4_k;/* '<S53>/rising_edge4' */
  rtDW_rising_edge10_InjResuCmp rising_edge3_e;/* '<S53>/rising_edge3' */
  rtDW_rising_edge10_InjResuCmp rising_edge2_p;/* '<S53>/rising_edge2' */
  rtDW_rising_edge10_InjResuCmp rising_edge1_c;/* '<S53>/rising_edge1' */
  rtDW_Counter_InjResuCmp Counter5_n;  /* '<S53>/Counter5' */
  rtDW_Counter_InjResuCmp Counter4_b;  /* '<S53>/Counter4' */
  rtDW_Counter_InjResuCmp Counter3_h;  /* '<S53>/Counter3' */
  rtDW_Counter_InjResuCmp Counter2_o;  /* '<S53>/Counter2' */
  rtDW_Counter_InjResuCmp Counter1_h;  /* '<S53>/Counter1' */
  rtDW_Counter_InjResuCmp Counter_e;   /* '<S53>/Counter' */
  rtDW_rising_edge10_InjResuCmp rising_edge6_e;/* '<S52>/rising_edge6' */
  rtDW_rising_edge10_InjResuCmp rising_edge5_g;/* '<S52>/rising_edge5' */
  rtDW_rising_edge10_InjResuCmp rising_edge4_c;/* '<S52>/rising_edge4' */
  rtDW_rising_edge10_InjResuCmp rising_edge3_f;/* '<S52>/rising_edge3' */
  rtDW_rising_edge10_InjResuCmp rising_edge2_g;/* '<S52>/rising_edge2' */
  rtDW_rising_edge10_InjResuCmp rising_edge1_k;/* '<S52>/rising_edge1' */
  rtDW_falling_edge1_InjResuCmp falling_edge6;/* '<S52>/falling_edge6' */
  rtDW_falling_edge1_InjResuCmp falling_edge5;/* '<S52>/falling_edge5' */
  rtDW_falling_edge1_InjResuCmp falling_edge4;/* '<S52>/falling_edge4' */
  rtDW_falling_edge1_InjResuCmp falling_edge3;/* '<S52>/falling_edge3' */
  rtDW_falling_edge1_InjResuCmp falling_edge2;/* '<S52>/falling_edge2' */
  rtDW_falling_edge1_InjResuCmp falling_edge1;/* '<S52>/falling_edge1' */
  rtDW_rising_edge10_InjResuCmp rising_edge9_n;/* '<S50>/rising_edge9' */
  rtDW_rising_edge10_InjResuCmp rising_edge8_a;/* '<S50>/rising_edge8' */
  rtDW_rising_edge10_InjResuCmp rising_edge7;/* '<S50>/rising_edge7' */
  rtDW_rising_edge10_InjResuCmp rising_edge6_k;/* '<S50>/rising_edge6' */
  rtDW_rising_edge10_InjResuCmp rising_edge5;/* '<S50>/rising_edge5' */
  rtDW_rising_edge10_InjResuCmp rising_edge4;/* '<S50>/rising_edge4' */
  rtDW_rising_edge10_InjResuCmp rising_edge3;/* '<S50>/rising_edge3' */
  rtDW_rising_edge10_InjResuCmp rising_edge2;/* '<S50>/rising_edge2' */
  rtDW_rising_edge10_InjResuCmp rising_edge12_h;/* '<S50>/rising_edge12' */
  rtDW_rising_edge10_InjResuCmp rising_edge11_i;/* '<S50>/rising_edge11' */
  rtDW_rising_edge10_InjResuCmp rising_edge10_k;/* '<S50>/rising_edge10' */
  rtDW_rising_edge10_InjResuCmp rising_edge1;/* '<S50>/rising_edge1' */
  rtDW_Counter_InjResuCmp Counter5;    /* '<S50>/Counter5' */
  rtDW_Counter_InjResuCmp Counter4;    /* '<S50>/Counter4' */
  rtDW_Counter_InjResuCmp Counter3;    /* '<S50>/Counter3' */
  rtDW_Counter_InjResuCmp Counter2;    /* '<S50>/Counter2' */
  rtDW_Counter_InjResuCmp Counter1;    /* '<S50>/Counter1' */
  rtDW_Counter_InjResuCmp Counter;     /* '<S50>/Counter' */
  rtDW_rising_edge10_InjResuCmp rising_edge9;/* '<S15>/rising_edge9' */
  rtDW_rising_edge10_InjResuCmp rising_edge8;/* '<S15>/rising_edge8' */
  rtDW_rising_edge10_InjResuCmp rising_edge6;/* '<S15>/rising_edge6' */
  rtDW_rising_edge10_InjResuCmp rising_edge13;/* '<S15>/rising_edge13' */
  rtDW_rising_edge10_InjResuCmp rising_edge12;/* '<S15>/rising_edge12' */
  rtDW_rising_edge10_InjResuCmp rising_edge11;/* '<S15>/rising_edge11' */
  rtDW_rising_edge10_InjResuCmp rising_edge10;/* '<S15>/rising_edge10' */
} D_Work_InjResuCmp;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: ConstMat_Value
   * Referenced by: '<S54>/ConstMat'
   */
  Float32 ConstMat_Value[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S16>/Logic'
   *   '<S17>/Logic'
   *   '<S18>/Logic'
   *   '<S19>/Logic'
   *   '<S20>/Logic'
   *   '<S21>/Logic'
   *   '<S174>/Logic'
   *   '<S175>/Logic'
   *   '<S176>/Logic'
   *   '<S177>/Logic'
   *   '<S178>/Logic'
   *   '<S179>/Logic'
   */
  Boolean pooled17[16];

  /* Computed Parameter: UnitDelay_X0
   * Referenced by: '<S34>/Unit Delay'
   */
  Boolean UnitDelay_X0[6];
} ConstParam_InjResuCmp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJRESUCMP_START_SEC_VAR_UNSPECIFIED
#include "InjResuCmp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InjResuCmp InjResuCmp_B;

/* Block states (auto storage) */
extern D_Work_InjResuCmp InjResuCmp_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_InjResuCmp InjResuCmp_ConstP;

#define INJRESUCMP_STOP_SEC_VAR_UNSPECIFIED
#include "InjResuCmp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define INJRESUCMP_START_SEC_CODE
#include "InjResuCmp_MemMap.h"

/* Model entry point functions */
extern void InjResuCmp_initialize(void);
extern void InjSys_EveStTR_InjResuCmp(void);
extern void InjSys_EveRTSt_InjResuCmp(void);
extern void InjSys_EveInj_InjResuCmp(void);
extern void InjSys_EveRst_InjResuCmp(void);

#define INJRESUCMP_STOP_SEC_CODE
#include "InjResuCmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define INJRESUCMP_START_SEC_CALIB_16BIT
#include "InjResuCmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_ctAntCmpStop_A[8];

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_ctAntCmpStop_T[8];

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_ct_facInjResuIdlCmp_A[8];

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_ct_facInjResuIntrSTT_A[8];

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_ct_facInjResuTqCmp_A[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuCorIntrSTT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuCor_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuIdlCmp_T[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuIntrSTT_T[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuTCorIntrSTT_T[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuTCor_T[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_facInjResuTqCmp_T[8];

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_mAir_facInjResuCorY_A[8];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, INJRESUCMP_CALIB) InjSys_nEng_facInjResuCorX_A[8];

#define INJRESUCMP_STOP_SEC_CALIB_16BIT
#include "InjResuCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJRESUCMP_START_SEC_CALIB_8BIT
#include "InjResuCmp_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJRESUCMP_CALIB) InjSys_tCo_facInjResuTCor_A[8];

#define INJRESUCMP_STOP_SEC_CALIB_8BIT
#include "InjResuCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define INJRESUCMP_START_SEC_CALIB_BOOLEAN
#include "InjResuCmp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJRESUCMP_CALIB) InjSys_bAcvInjResuCmp_C;

#define INJRESUCMP_STOP_SEC_CALIB_BOOLEAN
#include "InjResuCmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJRESUCMP_START_SEC_VAR_16BIT
#include "InjResuCmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern VAR(UInt16, INJRESUCMP_VAR) InjSys_prm_facInjResuCyl[6];

#define INJRESUCMP_STOP_SEC_VAR_16BIT
#include "InjResuCmp_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/LO3' : Unused code path elimination
 * Block '<S17>/LO3' : Unused code path elimination
 * Block '<S18>/LO3' : Unused code path elimination
 * Block '<S19>/LO3' : Unused code path elimination
 * Block '<S20>/LO3' : Unused code path elimination
 * Block '<S21>/LO3' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S97>/Data Type Duplicate' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Relational Operator' : Unused code path elimination
 * Block '<S93>/Relational Operator1' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Propagation' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Relational Operator' : Unused code path elimination
 * Block '<S94>/Relational Operator1' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Propagation' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Relational Operator' : Unused code path elimination
 * Block '<S104>/Relational Operator1' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate' : Unused code path elimination
 * Block '<S110>/Data Type Propagation' : Unused code path elimination
 * Block '<S111>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Relational Operator' : Unused code path elimination
 * Block '<S105>/Relational Operator1' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Data Type Propagation' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Relational Operator' : Unused code path elimination
 * Block '<S115>/Relational Operator1' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Propagation' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Relational Operator' : Unused code path elimination
 * Block '<S116>/Relational Operator1' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Propagation' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Relational Operator' : Unused code path elimination
 * Block '<S126>/Relational Operator1' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Propagation' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Relational Operator' : Unused code path elimination
 * Block '<S127>/Relational Operator1' : Unused code path elimination
 * Block '<S135>/Data Type Duplicate' : Unused code path elimination
 * Block '<S135>/Data Type Propagation' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate' : Unused code path elimination
 * Block '<S137>/Relational Operator' : Unused code path elimination
 * Block '<S137>/Relational Operator1' : Unused code path elimination
 * Block '<S143>/Data Type Duplicate' : Unused code path elimination
 * Block '<S143>/Data Type Propagation' : Unused code path elimination
 * Block '<S144>/Data Type Duplicate' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate' : Unused code path elimination
 * Block '<S138>/Relational Operator' : Unused code path elimination
 * Block '<S138>/Relational Operator1' : Unused code path elimination
 * Block '<S146>/Data Type Duplicate' : Unused code path elimination
 * Block '<S146>/Data Type Propagation' : Unused code path elimination
 * Block '<S152>/Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/Relational Operator' : Unused code path elimination
 * Block '<S148>/Relational Operator1' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate' : Unused code path elimination
 * Block '<S154>/Data Type Propagation' : Unused code path elimination
 * Block '<S155>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate' : Unused code path elimination
 * Block '<S149>/Relational Operator' : Unused code path elimination
 * Block '<S149>/Relational Operator1' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Data Type Propagation' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate1' : Unused code path elimination
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
 * Block '<S171>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S171>/x1' : Unused code path elimination
 * Block '<S174>/LO3' : Unused code path elimination
 * Block '<S175>/LO3' : Unused code path elimination
 * Block '<S176>/LO3' : Unused code path elimination
 * Block '<S177>/LO3' : Unused code path elimination
 * Block '<S178>/LO3' : Unused code path elimination
 * Block '<S179>/LO3' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S247>/Data Type Duplicate' : Unused code path elimination
 * Block '<S248>/Data Type Duplicate' : Unused code path elimination
 * Block '<S243>/Relational Operator' : Unused code path elimination
 * Block '<S243>/Relational Operator1' : Unused code path elimination
 * Block '<S249>/Data Type Duplicate' : Unused code path elimination
 * Block '<S249>/Data Type Propagation' : Unused code path elimination
 * Block '<S250>/Data Type Duplicate' : Unused code path elimination
 * Block '<S251>/Data Type Duplicate' : Unused code path elimination
 * Block '<S244>/Relational Operator' : Unused code path elimination
 * Block '<S244>/Relational Operator1' : Unused code path elimination
 * Block '<S252>/Data Type Duplicate' : Unused code path elimination
 * Block '<S252>/Data Type Propagation' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S254>/Relational Operator' : Unused code path elimination
 * Block '<S254>/Relational Operator1' : Unused code path elimination
 * Block '<S260>/Data Type Duplicate' : Unused code path elimination
 * Block '<S260>/Data Type Propagation' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate' : Unused code path elimination
 * Block '<S255>/Relational Operator' : Unused code path elimination
 * Block '<S255>/Relational Operator1' : Unused code path elimination
 * Block '<S263>/Data Type Duplicate' : Unused code path elimination
 * Block '<S263>/Data Type Propagation' : Unused code path elimination
 * Block '<S269>/Data Type Duplicate' : Unused code path elimination
 * Block '<S270>/Data Type Duplicate' : Unused code path elimination
 * Block '<S265>/Relational Operator' : Unused code path elimination
 * Block '<S265>/Relational Operator1' : Unused code path elimination
 * Block '<S271>/Data Type Duplicate' : Unused code path elimination
 * Block '<S271>/Data Type Propagation' : Unused code path elimination
 * Block '<S272>/Data Type Duplicate' : Unused code path elimination
 * Block '<S273>/Data Type Duplicate' : Unused code path elimination
 * Block '<S266>/Relational Operator' : Unused code path elimination
 * Block '<S266>/Relational Operator1' : Unused code path elimination
 * Block '<S274>/Data Type Duplicate' : Unused code path elimination
 * Block '<S274>/Data Type Propagation' : Unused code path elimination
 * Block '<S280>/Data Type Duplicate' : Unused code path elimination
 * Block '<S281>/Data Type Duplicate' : Unused code path elimination
 * Block '<S276>/Relational Operator' : Unused code path elimination
 * Block '<S276>/Relational Operator1' : Unused code path elimination
 * Block '<S282>/Data Type Duplicate' : Unused code path elimination
 * Block '<S282>/Data Type Propagation' : Unused code path elimination
 * Block '<S283>/Data Type Duplicate' : Unused code path elimination
 * Block '<S284>/Data Type Duplicate' : Unused code path elimination
 * Block '<S277>/Relational Operator' : Unused code path elimination
 * Block '<S277>/Relational Operator1' : Unused code path elimination
 * Block '<S285>/Data Type Duplicate' : Unused code path elimination
 * Block '<S285>/Data Type Propagation' : Unused code path elimination
 * Block '<S291>/Data Type Duplicate' : Unused code path elimination
 * Block '<S292>/Data Type Duplicate' : Unused code path elimination
 * Block '<S287>/Relational Operator' : Unused code path elimination
 * Block '<S287>/Relational Operator1' : Unused code path elimination
 * Block '<S293>/Data Type Duplicate' : Unused code path elimination
 * Block '<S293>/Data Type Propagation' : Unused code path elimination
 * Block '<S294>/Data Type Duplicate' : Unused code path elimination
 * Block '<S295>/Data Type Duplicate' : Unused code path elimination
 * Block '<S288>/Relational Operator' : Unused code path elimination
 * Block '<S288>/Relational Operator1' : Unused code path elimination
 * Block '<S296>/Data Type Duplicate' : Unused code path elimination
 * Block '<S296>/Data Type Propagation' : Unused code path elimination
 * Block '<S302>/Data Type Duplicate' : Unused code path elimination
 * Block '<S303>/Data Type Duplicate' : Unused code path elimination
 * Block '<S298>/Relational Operator' : Unused code path elimination
 * Block '<S298>/Relational Operator1' : Unused code path elimination
 * Block '<S304>/Data Type Duplicate' : Unused code path elimination
 * Block '<S304>/Data Type Propagation' : Unused code path elimination
 * Block '<S305>/Data Type Duplicate' : Unused code path elimination
 * Block '<S306>/Data Type Duplicate' : Unused code path elimination
 * Block '<S299>/Relational Operator' : Unused code path elimination
 * Block '<S299>/Relational Operator1' : Unused code path elimination
 * Block '<S307>/Data Type Duplicate' : Unused code path elimination
 * Block '<S307>/Data Type Propagation' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S226>/Data Type Duplicate' : Unused code path elimination
 * Block '<S226>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S229>/Data Type Duplicate' : Unused code path elimination
 * Block '<S230>/Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate' : Unused code path elimination
 * Block '<S232>/Data Type Duplicate' : Unused code path elimination
 * Block '<S233>/Data Type Duplicate' : Unused code path elimination
 * Block '<S234>/Data Type Duplicate' : Unused code path elimination
 * Block '<S319>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S319>/x1' : Unused code path elimination
 * Block '<S320>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S320>/x1' : Unused code path elimination
 * Block '<S321>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S321>/x1' : Unused code path elimination
 * Block '<S322>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S322>/x' : Unused code path elimination
 * Block '<S323>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S323>/x' : Unused code path elimination
 * Block '<S324>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S324>/x' : Unused code path elimination
 * Block '<S333>/Data Type Duplicate' : Unused code path elimination
 * Block '<S334>/Data Type Duplicate' : Unused code path elimination
 * Block '<S332>/Relational Operator' : Unused code path elimination
 * Block '<S332>/Relational Operator1' : Unused code path elimination
 * Block '<S335>/Data Type Duplicate' : Unused code path elimination
 * Block '<S335>/Data Type Propagation' : Unused code path elimination
 * Block '<S100>/Conversion' : Eliminate redundant data type conversion
 * Block '<S101>/Conversion' : Eliminate redundant data type conversion
 * Block '<S111>/Conversion' : Eliminate redundant data type conversion
 * Block '<S112>/Conversion' : Eliminate redundant data type conversion
 * Block '<S122>/Conversion' : Eliminate redundant data type conversion
 * Block '<S123>/Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Conversion' : Eliminate redundant data type conversion
 * Block '<S134>/Conversion' : Eliminate redundant data type conversion
 * Block '<S144>/Conversion' : Eliminate redundant data type conversion
 * Block '<S145>/Conversion' : Eliminate redundant data type conversion
 * Block '<S155>/Conversion' : Eliminate redundant data type conversion
 * Block '<S156>/Conversion' : Eliminate redundant data type conversion
 * Block '<S172>/Switch' : Eliminated due to constant selection input
 * Block '<S250>/Conversion' : Eliminate redundant data type conversion
 * Block '<S251>/Conversion' : Eliminate redundant data type conversion
 * Block '<S261>/Conversion' : Eliminate redundant data type conversion
 * Block '<S262>/Conversion' : Eliminate redundant data type conversion
 * Block '<S272>/Conversion' : Eliminate redundant data type conversion
 * Block '<S273>/Conversion' : Eliminate redundant data type conversion
 * Block '<S283>/Conversion' : Eliminate redundant data type conversion
 * Block '<S284>/Conversion' : Eliminate redundant data type conversion
 * Block '<S294>/Conversion' : Eliminate redundant data type conversion
 * Block '<S295>/Conversion' : Eliminate redundant data type conversion
 * Block '<S305>/Conversion' : Eliminate redundant data type conversion
 * Block '<S306>/Conversion' : Eliminate redundant data type conversion
 * Block '<S333>/Conversion' : Eliminate redundant data type conversion
 * Block '<S334>/Conversion' : Eliminate redundant data type conversion
 * Block '<S331>/Switch' : Eliminated due to constant selection input
 * Block '<S172>/Add3' : Unused code path elimination
 * Block '<S172>/Add4' : Unused code path elimination
 * Block '<S172>/Constant' : Unused code path elimination
 * Block '<S172>/Relational Operator' : Unused code path elimination
 * Block '<S172>/Switch1' : Unused code path elimination
 * Block '<S172>/offset2' : Unused code path elimination
 * Block '<S172>/offset3' : Unused code path elimination
 * Block '<S172>/offset4' : Unused code path elimination
 * Block '<S331>/Add3' : Unused code path elimination
 * Block '<S331>/Add4' : Unused code path elimination
 * Block '<S331>/Constant' : Unused code path elimination
 * Block '<S331>/Relational Operator' : Unused code path elimination
 * Block '<S331>/Switch1' : Unused code path elimination
 * Block '<S331>/offset2' : Unused code path elimination
 * Block '<S331>/offset3' : Unused code path elimination
 * Block '<S331>/offset4' : Unused code path elimination
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
 * hilite_system('InjResuCmp_AUTOCODE/InjResuCmp')    - opens subsystem InjResuCmp_AUTOCODE/InjResuCmp
 * hilite_system('InjResuCmp_AUTOCODE/InjResuCmp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InjResuCmp_AUTOCODE
 * '<S1>'   : InjResuCmp_AUTOCODE/InjResuCmp
 * '<S6>'   : InjResuCmp_AUTOCODE/InjResuCmp/F00_RstDetStall
 * '<S7>'   : InjResuCmp_AUTOCODE/InjResuCmp/F01_Initialization
 * '<S8>'   : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator
 * '<S9>'   : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp
 * '<S10>'  : InjResuCmp_AUTOCODE/InjResuCmp/F03_Det_Stall
 * '<S11>'  : InjResuCmp_AUTOCODE/InjResuCmp/demux_fc1
 * '<S12>'  : InjResuCmp_AUTOCODE/InjResuCmp/demux_fc2
 * '<S13>'  : InjResuCmp_AUTOCODE/InjResuCmp/demux_fc3
 * '<S14>'  : InjResuCmp_AUTOCODE/InjResuCmp/F00_RstDetStall/F00_RstDetStall
 * '<S15>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator
 * '<S16>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/BasculeRS
 * '<S17>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/BasculeRS1
 * '<S18>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/BasculeRS2
 * '<S19>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/BasculeRS3
 * '<S20>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/BasculeRS4
 * '<S21>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/BasculeRS5
 * '<S22>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Assignment
 * '<S23>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Assignment1
 * '<S24>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Assignment2
 * '<S25>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Assignment3
 * '<S26>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Assignment4
 * '<S27>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Assignment5
 * '<S28>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Selector
 * '<S29>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Selector1
 * '<S30>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Selector2
 * '<S31>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Selector3
 * '<S32>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Selector4
 * '<S33>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/One_Based_Selector5
 * '<S34>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/UnitDelay1
 * '<S35>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge10
 * '<S36>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge11
 * '<S37>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge12
 * '<S38>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge13
 * '<S39>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge6
 * '<S40>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge8
 * '<S41>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge9
 * '<S42>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge10/SubSystem
 * '<S43>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge11/SubSystem
 * '<S44>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge12/SubSystem
 * '<S45>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge13/SubSystem
 * '<S46>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge6/SubSystem
 * '<S47>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge8/SubSystem
 * '<S48>'  : InjResuCmp_AUTOCODE/InjResuCmp/F01_Stall_indicator/F01_Stall_indicator/rising_edge9/SubSystem
 * '<S49>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp
 * '<S50>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters
 * '<S51>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F02_Compensation_Stop_Anticipation
 * '<S52>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation
 * '<S53>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters
 * '<S54>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations
 * '<S55>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F06_Fuel_Choice
 * '<S56>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter
 * '<S57>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1
 * '<S58>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2
 * '<S59>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3
 * '<S60>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4
 * '<S61>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5
 * '<S62>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Assignment
 * '<S63>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Assignment1
 * '<S64>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Assignment2
 * '<S65>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Assignment3
 * '<S66>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Assignment4
 * '<S67>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Assignment5
 * '<S68>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector
 * '<S69>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector1
 * '<S70>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector10
 * '<S71>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector11
 * '<S72>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector2
 * '<S73>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector3
 * '<S74>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector4
 * '<S75>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector5
 * '<S76>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector6
 * '<S77>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector7
 * '<S78>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector8
 * '<S79>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/One_Based_Selector9
 * '<S80>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/UnitDelay1
 * '<S81>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge1
 * '<S82>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge10
 * '<S83>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge11
 * '<S84>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge12
 * '<S85>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge2
 * '<S86>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge3
 * '<S87>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge4
 * '<S88>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge5
 * '<S89>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge6
 * '<S90>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge7
 * '<S91>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge8
 * '<S92>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge9
 * '<S93>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/Clamp
 * '<S94>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/Clamp1
 * '<S95>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/SubSystem
 * '<S96>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/rising_edge6
 * '<S97>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/Clamp/Data Type Conversion Inherited
 * '<S98>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/Clamp/Data Type Conversion Inherited1
 * '<S99>'  : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/Clamp/Saturation Dynamic
 * '<S100>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/Clamp1/Data Type Conversion Inherited
 * '<S101>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/Clamp1/Data Type Conversion Inherited1
 * '<S102>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/Clamp1/Saturation Dynamic
 * '<S103>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter/rising_edge6/SubSystem
 * '<S104>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/Clamp
 * '<S105>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/Clamp1
 * '<S106>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/SubSystem
 * '<S107>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/rising_edge6
 * '<S108>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/Clamp/Data Type Conversion Inherited
 * '<S109>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/Clamp/Data Type Conversion Inherited1
 * '<S110>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/Clamp/Saturation Dynamic
 * '<S111>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/Clamp1/Data Type Conversion Inherited
 * '<S112>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/Clamp1/Data Type Conversion Inherited1
 * '<S113>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/Clamp1/Saturation Dynamic
 * '<S114>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter1/rising_edge6/SubSystem
 * '<S115>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/Clamp
 * '<S116>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/Clamp1
 * '<S117>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/SubSystem
 * '<S118>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/rising_edge6
 * '<S119>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/Clamp/Data Type Conversion Inherited
 * '<S120>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/Clamp/Data Type Conversion Inherited1
 * '<S121>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/Clamp/Saturation Dynamic
 * '<S122>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/Clamp1/Data Type Conversion Inherited
 * '<S123>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/Clamp1/Data Type Conversion Inherited1
 * '<S124>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/Clamp1/Saturation Dynamic
 * '<S125>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter2/rising_edge6/SubSystem
 * '<S126>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/Clamp
 * '<S127>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/Clamp1
 * '<S128>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/SubSystem
 * '<S129>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/rising_edge6
 * '<S130>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/Clamp/Data Type Conversion Inherited
 * '<S131>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/Clamp/Data Type Conversion Inherited1
 * '<S132>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/Clamp/Saturation Dynamic
 * '<S133>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/Clamp1/Data Type Conversion Inherited
 * '<S134>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/Clamp1/Data Type Conversion Inherited1
 * '<S135>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/Clamp1/Saturation Dynamic
 * '<S136>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter3/rising_edge6/SubSystem
 * '<S137>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/Clamp
 * '<S138>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/Clamp1
 * '<S139>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/SubSystem
 * '<S140>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/rising_edge6
 * '<S141>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/Clamp/Data Type Conversion Inherited
 * '<S142>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/Clamp/Data Type Conversion Inherited1
 * '<S143>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/Clamp/Saturation Dynamic
 * '<S144>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/Clamp1/Data Type Conversion Inherited
 * '<S145>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/Clamp1/Data Type Conversion Inherited1
 * '<S146>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/Clamp1/Saturation Dynamic
 * '<S147>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter4/rising_edge6/SubSystem
 * '<S148>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/Clamp
 * '<S149>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/Clamp1
 * '<S150>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/SubSystem
 * '<S151>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/rising_edge6
 * '<S152>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/Clamp/Data Type Conversion Inherited
 * '<S153>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/Clamp/Data Type Conversion Inherited1
 * '<S154>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/Clamp/Saturation Dynamic
 * '<S155>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/Clamp1/Data Type Conversion Inherited
 * '<S156>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/Clamp1/Data Type Conversion Inherited1
 * '<S157>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/Clamp1/Saturation Dynamic
 * '<S158>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/Counter5/rising_edge6/SubSystem
 * '<S159>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge1/SubSystem
 * '<S160>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge10/SubSystem
 * '<S161>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge11/SubSystem
 * '<S162>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge12/SubSystem
 * '<S163>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge2/SubSystem
 * '<S164>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge3/SubSystem
 * '<S165>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge4/SubSystem
 * '<S166>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge5/SubSystem
 * '<S167>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge6/SubSystem
 * '<S168>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge7/SubSystem
 * '<S169>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge8/SubSystem
 * '<S170>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F01_CutOff_Counters/rising_edge9/SubSystem
 * '<S171>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F02_Compensation_Stop_Anticipation/LookUp_1D
 * '<S172>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F02_Compensation_Stop_Anticipation/SingleToFixdt
 * '<S173>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F02_Compensation_Stop_Anticipation/division_411
 * '<S174>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/BasculeRS1
 * '<S175>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/BasculeRS2
 * '<S176>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/BasculeRS3
 * '<S177>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/BasculeRS4
 * '<S178>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/BasculeRS5
 * '<S179>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/BasculeRS6
 * '<S180>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Assignment1
 * '<S181>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Assignment2
 * '<S182>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Assignment3
 * '<S183>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Assignment4
 * '<S184>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Assignment5
 * '<S185>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Assignment6
 * '<S186>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Selector1
 * '<S187>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Selector12
 * '<S188>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Selector2
 * '<S189>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Selector3
 * '<S190>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Selector4
 * '<S191>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/One_Based_Selector5
 * '<S192>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/UnitDelay2
 * '<S193>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge1
 * '<S194>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge2
 * '<S195>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge3
 * '<S196>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge4
 * '<S197>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge5
 * '<S198>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge6
 * '<S199>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge1
 * '<S200>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge2
 * '<S201>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge3
 * '<S202>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge4
 * '<S203>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge5
 * '<S204>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge6
 * '<S205>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge1/SubSystem
 * '<S206>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge2/SubSystem
 * '<S207>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge3/SubSystem
 * '<S208>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge4/SubSystem
 * '<S209>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge5/SubSystem
 * '<S210>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/falling_edge6/SubSystem
 * '<S211>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge1/SubSystem
 * '<S212>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge2/SubSystem
 * '<S213>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge3/SubSystem
 * '<S214>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge4/SubSystem
 * '<S215>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge5/SubSystem
 * '<S216>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F03_Resume_counter_activation/rising_edge6/SubSystem
 * '<S217>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter
 * '<S218>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1
 * '<S219>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2
 * '<S220>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3
 * '<S221>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4
 * '<S222>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5
 * '<S223>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Assignment1
 * '<S224>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Assignment2
 * '<S225>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Assignment3
 * '<S226>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Assignment4
 * '<S227>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Assignment5
 * '<S228>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Assignment6
 * '<S229>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Selector1
 * '<S230>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Selector12
 * '<S231>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Selector2
 * '<S232>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Selector3
 * '<S233>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Selector4
 * '<S234>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/One_Based_Selector5
 * '<S235>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/UnitDelay1
 * '<S236>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/division_421
 * '<S237>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge1
 * '<S238>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge2
 * '<S239>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge3
 * '<S240>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge4
 * '<S241>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge5
 * '<S242>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge7
 * '<S243>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/Clamp
 * '<S244>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/Clamp1
 * '<S245>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/SubSystem
 * '<S246>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/rising_edge6
 * '<S247>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/Clamp/Data Type Conversion Inherited
 * '<S248>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/Clamp/Data Type Conversion Inherited1
 * '<S249>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/Clamp/Saturation Dynamic
 * '<S250>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/Clamp1/Data Type Conversion Inherited
 * '<S251>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/Clamp1/Data Type Conversion Inherited1
 * '<S252>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/Clamp1/Saturation Dynamic
 * '<S253>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter/rising_edge6/SubSystem
 * '<S254>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/Clamp
 * '<S255>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/Clamp1
 * '<S256>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/SubSystem
 * '<S257>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/rising_edge6
 * '<S258>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/Clamp/Data Type Conversion Inherited
 * '<S259>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/Clamp/Data Type Conversion Inherited1
 * '<S260>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/Clamp/Saturation Dynamic
 * '<S261>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/Clamp1/Data Type Conversion Inherited
 * '<S262>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/Clamp1/Data Type Conversion Inherited1
 * '<S263>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/Clamp1/Saturation Dynamic
 * '<S264>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter1/rising_edge6/SubSystem
 * '<S265>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/Clamp
 * '<S266>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/Clamp1
 * '<S267>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/SubSystem
 * '<S268>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/rising_edge6
 * '<S269>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/Clamp/Data Type Conversion Inherited
 * '<S270>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/Clamp/Data Type Conversion Inherited1
 * '<S271>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/Clamp/Saturation Dynamic
 * '<S272>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/Clamp1/Data Type Conversion Inherited
 * '<S273>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/Clamp1/Data Type Conversion Inherited1
 * '<S274>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/Clamp1/Saturation Dynamic
 * '<S275>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter2/rising_edge6/SubSystem
 * '<S276>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/Clamp
 * '<S277>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/Clamp1
 * '<S278>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/SubSystem
 * '<S279>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/rising_edge6
 * '<S280>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/Clamp/Data Type Conversion Inherited
 * '<S281>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/Clamp/Data Type Conversion Inherited1
 * '<S282>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/Clamp/Saturation Dynamic
 * '<S283>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/Clamp1/Data Type Conversion Inherited
 * '<S284>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/Clamp1/Data Type Conversion Inherited1
 * '<S285>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/Clamp1/Saturation Dynamic
 * '<S286>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter3/rising_edge6/SubSystem
 * '<S287>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/Clamp
 * '<S288>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/Clamp1
 * '<S289>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/SubSystem
 * '<S290>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/rising_edge6
 * '<S291>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/Clamp/Data Type Conversion Inherited
 * '<S292>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/Clamp/Data Type Conversion Inherited1
 * '<S293>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/Clamp/Saturation Dynamic
 * '<S294>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/Clamp1/Data Type Conversion Inherited
 * '<S295>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/Clamp1/Data Type Conversion Inherited1
 * '<S296>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/Clamp1/Saturation Dynamic
 * '<S297>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter4/rising_edge6/SubSystem
 * '<S298>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/Clamp
 * '<S299>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/Clamp1
 * '<S300>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/SubSystem
 * '<S301>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/rising_edge6
 * '<S302>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/Clamp/Data Type Conversion Inherited
 * '<S303>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/Clamp/Data Type Conversion Inherited1
 * '<S304>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/Clamp/Saturation Dynamic
 * '<S305>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/Clamp1/Data Type Conversion Inherited
 * '<S306>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/Clamp1/Data Type Conversion Inherited1
 * '<S307>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/Clamp1/Saturation Dynamic
 * '<S308>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/Counter5/rising_edge6/SubSystem
 * '<S309>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge1/SubSystem
 * '<S310>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge2/SubSystem
 * '<S311>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge3/SubSystem
 * '<S312>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge4/SubSystem
 * '<S313>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge5/SubSystem
 * '<S314>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F04_Resume_counters/rising_edge7/SubSystem
 * '<S315>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/Interp_1D
 * '<S316>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/Interp_1D1
 * '<S317>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/Interp_2D
 * '<S318>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/Interp_2D1
 * '<S319>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/LookUp_1D
 * '<S320>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/LookUp_1D1
 * '<S321>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/LookUp_1D2
 * '<S322>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/PreLookUp_Binary
 * '<S323>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/PreLookUp_Binary1
 * '<S324>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/PreLookUp_Binary2
 * '<S325>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/multiplication_411
 * '<S326>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/multiplication_421
 * '<S327>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/multiplication_431
 * '<S328>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/multiplication_441
 * '<S329>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F05_Compensations/multiplication_451
 * '<S330>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F06_Fuel_Choice/BaryCentre_VEMS
 * '<S331>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F06_Fuel_Choice/SingleToFixdt
 * '<S332>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F06_Fuel_Choice/BaryCentre_VEMS/Clamp
 * '<S333>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F06_Fuel_Choice/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S334>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F06_Fuel_Choice/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S335>' : InjResuCmp_AUTOCODE/InjResuCmp/F02_InjResuCmp/F02_InjResuCmp/F06_Fuel_Choice/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S336>' : InjResuCmp_AUTOCODE/InjResuCmp/F03_Det_Stall/F03_Det_Stall
 */

/*-
 * Requirements for '<Root>': InjResuCmp
 */
#endif                                 /* RTW_HEADER_InjResuCmp_h_ */

/*-------------------------------- end of file -------------------------------*/
