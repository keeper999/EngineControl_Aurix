/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSpMgt                                                */
/* !Description     : INJECTION PARAMETERS MANAGER                            */
/*                                                                            */
/* !Module          : InjSpMgt                                                */
/*                                                                            */
/* !File            : InjSpMgt.h                                              */
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
/*   Code generated on: Thu Mar 07 15:35:56 2013                              */
/*   Model name       : InjSpMgt_AUTOCODE.mdl                                 */
/*   Model version    : 1.1004                                                */
/*   Root subsystem   : /InjSpMgt                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjSpMgt/5-SOFT-LIV/InjSpMgt$*/
/* $Revision::   1.13                                                        $*/
/* $Author::   adelvare                               $$Date::   11 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjSpMgt_h_
#define RTW_HEADER_InjSpMgt_h_
#ifndef InjSpMgt_COMMON_INCLUDES_
# define InjSpMgt_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "InjSpMgt_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "ACTEMS_FloorF.h"
#include "rt_MAXf.h"
#include "rt_MIN.h"
#include "rt_SATURATE.h"
#include "rt_mod32.h"
#include "rt_mod_uint16.h"
#endif                                 /* InjSpMgt_COMMON_INCLUDES_ */

#include "InjSpMgt_types.h"

/* Includes for objects with custom storage classes. */
#include "GDGAR.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define InjSys_agCkPosEveInj_SC        ((UInt16) 220U)
#define Ext_agWdTooth_SC               ((UInt8) 6U)

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
  UInt32 VEMS_vidGET30[4];           /* '<S18>/VEMS_vidGET30' */
  SInt16 VEMS_vidGET;                 /* '<S12>/VEMS_vidGET' */
  UInt16 VEMS_vidGET1;               /* '<S265>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET10;              /* '<S18>/VEMS_vidGET10' */
  SInt16 VEMS_vidGET29[4];            /* '<S18>/VEMS_vidGET29' */
  UInt16 VEMS_vidGET28[4];           /* '<S18>/VEMS_vidGET28' */
  UInt16 VEMS_vidGET20;              /* '<S18>/VEMS_vidGET20' */
  UInt16 VEMS_vidGET21[6];           /* '<S18>/VEMS_vidGET21' */
  UInt16 Assignment[6];              /* '<S171>/Assignment' */
  UInt16 Assignment_m[6];            /* '<S188>/Assignment' */
  UInt16 Assignment_my[6];           /* '<S190>/Assignment' */
  UInt16 Assignment_h[6];            /* '<S193>/Assignment' */
  UInt16 TmpSignalConversionAtVEMS_vidSE[6];
  UInt16 VEMS_vidGET9[6];            /* '<S237>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET3[6];            /* '<S237>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET4[6];            /* '<S237>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5[6];            /* '<S237>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET6[6];            /* '<S237>/VEMS_vidGET6' */
  UInt16 Switch1[6];                 /* '<S237>/Switch1' */
  UInt16 Switch2[6];                 /* '<S237>/Switch2' */
  UInt16 Switch3[6];                 /* '<S237>/Switch3' */
  UInt16 Switch6[6];                 /* '<S237>/Switch6' */
  UInt16 Switch8[6];                 /* '<S237>/Switch8' */
  UInt16 Assignment_p[6];            /* '<S208>/Assignment' */
  UInt16 Assignment_j[6];            /* '<S209>/Assignment' */
  UInt16 Assignment_a[6];            /* '<S226>/Assignment' */
  UInt16 Assignment_jh[6];           /* '<S227>/Assignment' */
  UInt16 Assignment_f[6];            /* '<S228>/Assignment' */
  UInt16 VEMS_vidGET23;              /* '<S18>/VEMS_vidGET23' */
  UInt16 VEMS_vidGET25;              /* '<S18>/VEMS_vidGET25' */
  UInt16 VEMS_vidGET27;              /* '<S18>/VEMS_vidGET27' */
  UInt16 VEMS_vidGET22;              /* '<S18>/VEMS_vidGET22' */
  UInt16 VEMS_vidGET24;              /* '<S18>/VEMS_vidGET24' */
  UInt16 VEMS_vidGET26;              /* '<S18>/VEMS_vidGET26' */
  UInt16 Assignment_b[6];            /* '<S176>/Assignment' */
  UInt16 Assignment_b2[6];           /* '<S178>/Assignment' */
  UInt16 Assignment_e[6];            /* '<S180>/Assignment' */
  UInt16 Assignment_k[6];            /* '<S183>/Assignment' */
  UInt16 VEMS_vidGET13[6];           /* '<S237>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET14[6];           /* '<S237>/VEMS_vidGET14' */
  UInt16 VEMS_vidGET15[6];           /* '<S237>/VEMS_vidGET15' */
  UInt16 VEMS_vidGET12[6];           /* '<S237>/VEMS_vidGET12' */
  UInt16 Switch10[6];                /* '<S237>/Switch10' */
  UInt16 Switch11[6];                /* '<S237>/Switch11' */
  UInt16 Switch12[6];                /* '<S237>/Switch12' */
  UInt16 Switch13[6];                /* '<S237>/Switch13' */
  UInt16 Switch12_f[6];              /* '<S207>/Switch12' */
  UInt16 Switch13_o[6];              /* '<S207>/Switch13' */
  UInt16 Switch15[6];                /* '<S207>/Switch15' */
  UInt16 Switch18[6];                /* '<S207>/Switch18' */
  UInt16 VEMS_vidGET15_a;            /* '<S18>/VEMS_vidGET15' */
  UInt16 VEMS_vidGET17;              /* '<S18>/VEMS_vidGET17' */
  UInt16 VEMS_vidGET19;              /* '<S18>/VEMS_vidGET19' */
  UInt16 VEMS_vidGET14_e;            /* '<S18>/VEMS_vidGET14' */
  UInt16 VEMS_vidGET16;              /* '<S18>/VEMS_vidGET16' */
  UInt16 VEMS_vidGET18;              /* '<S18>/VEMS_vidGET18' */
  UInt16 VEMS_vidGET9_k;             /* '<S18>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET12_l;            /* '<S18>/VEMS_vidGET12' */
  UInt16 VEMS_vidGET3_l[6];          /* '<S18>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET4_e;             /* '<S265>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET3_c;             /* '<S265>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET2;               /* '<S265>/VEMS_vidGET2' */
  UInt16 OutDTConv;                  /* '<S282>/OutDTConv' */
  UInt16 VEMS_vidGET11;              /* '<S18>/VEMS_vidGET11' */
  UInt16 OutDTConv_c;                /* '<S288>/OutDTConv' */
  UInt16 VEMS_vidGET2_e;             /* '<S18>/VEMS_vidGET2' */
  UInt16 Assignment_jw[6];           /* '<S172>/Assignment' */
  UInt16 Assignment_o[6];            /* '<S174>/Assignment' */
  UInt16 Assignment_l[6];            /* '<S185>/Assignment' */
  UInt16 Assignment_ma[6];           /* '<S187>/Assignment' */
  UInt16 VEMS_vidGET8[6];            /* '<S237>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET7[6];            /* '<S237>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET10_h[6];         /* '<S237>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET11_g[6];         /* '<S237>/VEMS_vidGET11' */
  UInt16 Switch4[6];                 /* '<S237>/Switch4' */
  UInt16 Switch5[6];                 /* '<S237>/Switch5' */
  UInt16 Switch7[6];                 /* '<S237>/Switch7' */
  UInt16 Switch9[6];                 /* '<S237>/Switch9' */
  UInt16 Switch3_f[6];               /* '<S207>/Switch3' */
  UInt16 Switch4_b[6];               /* '<S207>/Switch4' */
  UInt16 Switch8_e[6];               /* '<S207>/Switch8' */
  UInt16 Switch9_p[6];               /* '<S207>/Switch9' */
  UInt8 VEMS_vidGET1_p;              /* '<S170>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET1_p5;             /* '<S237>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_f;               /* '<S237>/VEMS_vidGET' */
  UInt8 VEMS_vidGET_l;               /* '<S292>/VEMS_vidGET' */
  UInt8 VEMS_vidGET1_j;              /* '<S292>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET3_j;              /* '<S292>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET3_n;              /* '<S291>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET1_a;              /* '<S207>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET2_d;              /* '<S207>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET_b;               /* '<S207>/VEMS_vidGET' */
  UInt8 VEMS_vidGET3_lr;             /* '<S207>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET_d;               /* '<S265>/VEMS_vidGET' */
  UInt8 VEMS_vidGET8_p;              /* '<S18>/VEMS_vidGET8' */
  UInt8 VEMS_vidGET6_h;              /* '<S18>/VEMS_vidGET6' */
  UInt8 VEMS_vidGET7_d;              /* '<S18>/VEMS_vidGET7' */
  UInt8 VEMS_vidGET5_h;              /* '<S18>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET1_h;              /* '<S18>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET4_i;              /* '<S18>/VEMS_vidGET4' */
  UInt8 SignalConversion1;           /* '<S132>/Signal Conversion1' */
  UInt8 VEMS_vidGET1_i;              /* '<S8>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_g;               /* '<S8>/VEMS_vidGET' */
  Boolean VEMS_vidGET_o;             /* '<S170>/VEMS_vidGET' */
  Boolean VEMS_vidGET2_f;            /* '<S237>/VEMS_vidGET2' */
  Boolean VEMS_vidGET2_m;            /* '<S292>/VEMS_vidGET2' */
  Boolean Switch3_o[2];              /* '<S292>/Switch3' */
  Boolean VEMS_vidGET2_n;            /* '<S291>/VEMS_vidGET2' */
  Boolean VEMS_vidGET_fh;            /* '<S291>/VEMS_vidGET' */
  Boolean Switch3_j[2];              /* '<S291>/Switch3' */
  Boolean VEMS_vidGET32;             /* '<S18>/VEMS_vidGET32' */
  Boolean VEMS_vidGET_gw;            /* '<S18>/VEMS_vidGET' */
  Boolean LogicalOperator;           /* '<S68>/Logical Operator' */
  Boolean TmpSignalConversionAtSignalConv;
  Boolean LogicalOperator1;          /* '<S68>/Logical Operator1' */
  UInt8 VEMS_vidGET13_m;             /* '<S18>/VEMS_vidGET13' */
  UInt8 VEMS_vidGET1_jg;             /* '<S291>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET31;               /* '<S18>/VEMS_vidGET31' */
} BlockIO_InjSpMgt;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S277>/Unit Delay' */
  UInt32 Prelookup_DWORK1;           /* '<S118>/Prelookup' */
  UInt32 Prelookup_DWORK1_o;         /* '<S46>/Prelookup' */
  UInt32 Prelookup_DWORK1_e;         /* '<S36>/Prelookup' */
  UInt16 UnitDelay_DSTATE_d;         /* '<S203>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_c;         /* '<S204>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_p;         /* '<S205>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_h;         /* '<S206>/Unit Delay' */
  Boolean UnitDelay_DSTATE_dk;       /* '<S264>/Unit Delay' */
  Boolean UnitDelay_DSTATE_e;        /* '<S278>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S126>/UnitDelay' */
  Boolean UnitDelay_d;               /* '<S126>/UnitDelay1' */
  Boolean UnitDelay_e;               /* '<S55>/UnitDelay' */
  Boolean UnitDelay_g;               /* '<S55>/UnitDelay1' */
  Boolean UnitDelay_j;               /* '<S56>/UnitDelay' */
  Boolean UnitDelay_p;               /* '<S56>/UnitDelay1' */
  Boolean UnitDelay_k;               /* '<S57>/UnitDelay' */
  Boolean UnitDelay_m;               /* '<S57>/UnitDelay1' */
  Boolean UnitDelay_df;              /* '<S58>/UnitDelay' */
  Boolean UnitDelay_f;               /* '<S58>/UnitDelay1' */
  Boolean UnitDelay_e3;              /* '<S37>/UnitDelay' */
  Boolean UnitDelay_h;               /* '<S37>/UnitDelay1' */
  Boolean UnitDelay_er;              /* '<S32>/UnitDelay' */
  Boolean UnitDelay_n;               /* '<S32>/UnitDelay1' */
} D_Work_InjSpMgt;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S124>/Lookup Table (n-D)'
   *   '<S134>/Lookup Table (n-D)'
   */
  UInt32 pooled16[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S137>/Lookup Table (n-D)'
   *   '<S138>/Lookup Table (n-D)'
   */
  UInt32 pooled17[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S32>/Logic'
   *   '<S37>/Logic'
   *   '<S55>/Logic'
   *   '<S56>/Logic'
   *   '<S57>/Logic'
   *   '<S58>/Logic'
   *   '<S126>/Logic'
   */
  Boolean pooled26[16];
} ConstParam_InjSpMgt;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJSPMGT_START_SEC_VAR_UNSPECIFIED
#include "InjSpMgt_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InjSpMgt InjSpMgt_B;

/* Block states (auto storage) */
extern D_Work_InjSpMgt InjSpMgt_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_InjSpMgt InjSpMgt_ConstP;

#define INJSPMGT_STOP_SEC_VAR_UNSPECIFIED
#include "InjSpMgt_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define INJSPMGT_START_SEC_CODE
#include "InjSpMgt_MemMap.h"

/* Model entry point functions */
extern void InjSpMgt_initialize(void);
extern void InjSys_EveStTCr_InjSpMgt(void);
extern void InjSys_EveInj_InjSpMgt(void);
extern void InjSys_EveSpl_InjSpMgt(void);
extern void InjSys_SdlFast_InjSpMgt(void);
extern void InjSys_EveCkSnNtAc_InjSpMgt(void);
extern void InjSys_EveRst_InjSpMgt(void);

#define INJSPMGT_STOP_SEC_CODE
#include "InjSpMgt_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define INJSPMGT_START_SEC_CALIB_16BIT
#include "InjSpMgt_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) Eng_AgCkOffFuInjStrt_T[9];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) Eng_tiAgCkInjPhd_M[81];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_DifInjr_A[9];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agBegInjH1SpcInjMod_M[256];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agBegInjH2HiThd_T[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agBegInjH2LoThd_T[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agBegInjSpcModLP_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agCkClsInVlvEstimRef1_A[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agEndInjSpcModMaxLP_M[256];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH1SpHiThd_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH1SpLoThd_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH2SpMax_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH2SpMin_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjH2SpcInjMod_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS1SpMax_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS1SpcInjMod_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS2SpMax_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS2SpMinLP_T[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS2SpMin_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agInjS2SpcInjMod_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agOfsPhaIg_T[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_agOfsPhaInj_T[16];

/* Type:    UInt16                                                          */
/* Units:   °Ck/s                                                             */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_facConvTiToagWdStall_C;

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_mAirCrkSpRef_C;

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_mAirInjSpMgt_A[16];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_nEng_A[16];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_nEng_AgCkInjPhd_A[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuGrdNeg_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuGrdPos_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuRailIni_T[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuRailMes_A[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuRailMin_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuReqMaxDft_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuReqMax_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_pFuReqMin_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_rMFuReqLPFu_C;

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0971199999999990E-001                                           */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_tiInjMinHys_T[16];

/* Type:    UInt16                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0971199999999990E-001                                           */
extern CONST(UInt16, INJSPMGT_CALIB) InjSys_tiInjMinLoThd_T[16];

#define INJSPMGT_STOP_SEC_CALIB_16BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJSPMGT_START_SEC_CALIB_8BIT
#include "InjSpMgt_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.99609375                                                        */
extern CONST(UInt8, INJSPMGT_CALIB) InjSys_rFilGainPFuReq_T[16];

/* Type:    UInt8                                                           */
/* Slope:   3.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt8, INJSPMGT_CALIB) Sync_agEs_A[9];

#define INJSPMGT_STOP_SEC_CALIB_8BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define INJSPMGT_START_SEC_CALIB_BOOLEAN
#include "InjSpMgt_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJSPMGT_CALIB) InjSys_bAcvTiInjETB_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJSPMGT_CALIB) InjSys_bEnaPresFuGrdLim_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJSPMGT_CALIB) InjSys_bInhCorInjPhaSIgSp_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJSPMGT_CALIB) InjSys_bInhrMFuReqLPFu_C;

#define INJSPMGT_STOP_SEC_CALIB_BOOLEAN
#include "InjSpMgt_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJSPMGT_START_SEC_VAR_16BIT
#include "InjSpMgt_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_pFuReq;

/* Type:    UInt16                                                          */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjH1ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjH2ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjS1ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjS2ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjH1ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjH2ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjS1ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjS2ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjH1ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjH2ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjS1ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjS2ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rMFuReqLPFu[6];

#define INJSPMGT_STOP_SEC_VAR_16BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define INJSPMGT_START_SEC_VAR_8BIT
#include "InjSpMgt_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:                                                                     */
/* PhysMin: 1.0                                                               */
/* PhysMax: 6.0                                                               */
extern VAR(UInt8, INJSPMGT_VAR) InjSys_noInCylStopSTT;

#define INJSPMGT_STOP_SEC_VAR_8BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJSPMGT_START_SEC_VAR_BOOLEAN
#include "InjSpMgt_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bAcvSpcInjModOvlp;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetBegInjMaxThd;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetInjOvlp;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSPMGT_VAR) InjSys_prm_bInhFrstInjSTT[2];

#define INJSPMGT_STOP_SEC_VAR_BOOLEAN
#include "InjSpMgt_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/LO3' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S31>/x' : Unused code path elimination
 * Block '<S37>/LO3' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/x' : Unused code path elimination
 * Block '<S55>/LO3' : Unused code path elimination
 * Block '<S56>/LO3' : Unused code path elimination
 * Block '<S57>/LO3' : Unused code path elimination
 * Block '<S58>/LO3' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S46>/x' : Unused code path elimination
 * Block '<S62>/Data Type Propagation' : Unused code path elimination
 * Block '<S62>/Data Type Propagation1' : Unused code path elimination
 * Block '<S63>/Data Type Propagation' : Unused code path elimination
 * Block '<S63>/Data Type Conversion' : Unused code path elimination
 * Block '<S63>/Data Type Conversion1' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S90>/Data Type Propagation' : Unused code path elimination
 * Block '<S90>/Data Type Propagation1' : Unused code path elimination
 * Block '<S93>/Data Type Propagation' : Unused code path elimination
 * Block '<S93>/Data Type Conversion' : Unused code path elimination
 * Block '<S93>/Data Type Conversion1' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate' : Unused code path elimination
 * Block '<S96>/Data Type Propagation' : Unused code path elimination
 * Block '<S96>/Data Type Propagation1' : Unused code path elimination
 * Block '<S99>/Data Type Propagation' : Unused code path elimination
 * Block '<S99>/Data Type Conversion' : Unused code path elimination
 * Block '<S99>/Data Type Conversion1' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Propagation' : Unused code path elimination
 * Block '<S102>/Data Type Propagation1' : Unused code path elimination
 * Block '<S105>/Data Type Propagation' : Unused code path elimination
 * Block '<S105>/Data Type Conversion' : Unused code path elimination
 * Block '<S105>/Data Type Conversion1' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Propagation' : Unused code path elimination
 * Block '<S108>/Data Type Propagation1' : Unused code path elimination
 * Block '<S111>/Data Type Propagation' : Unused code path elimination
 * Block '<S111>/Data Type Conversion' : Unused code path elimination
 * Block '<S111>/Data Type Conversion1' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S118>/x' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S123>/x1' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S124>/x1' : Unused code path elimination
 * Block '<S124>/x2' : Unused code path elimination
 * Block '<S126>/LO3' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S133>/x1' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S134>/x1' : Unused code path elimination
 * Block '<S134>/x2' : Unused code path elimination
 * Block '<S137>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S137>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S137>/x1' : Unused code path elimination
 * Block '<S137>/x2' : Unused code path elimination
 * Block '<S138>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S138>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S138>/x1' : Unused code path elimination
 * Block '<S138>/x2' : Unused code path elimination
 * Block '<S142>/Data Type Propagation' : Unused code path elimination
 * Block '<S142>/Data Type Propagation1' : Unused code path elimination
 * Block '<S146>/Data Type Propagation' : Unused code path elimination
 * Block '<S146>/Data Type Conversion' : Unused code path elimination
 * Block '<S146>/Data Type Conversion1' : Unused code path elimination
 * Block '<S143>/Data Type Propagation' : Unused code path elimination
 * Block '<S143>/Data Type Propagation1' : Unused code path elimination
 * Block '<S148>/Data Type Propagation' : Unused code path elimination
 * Block '<S148>/Data Type Conversion' : Unused code path elimination
 * Block '<S148>/Data Type Conversion1' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S164>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S165>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S166>/Force any float to Double everything else to uint8' : Unused code path elimination
 * Block '<S166>/Force any float to Single everything else to uint8' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate1' : Unused code path elimination
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
 * Block '<S186>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S208>/Data Type Duplicate' : Unused code path elimination
 * Block '<S208>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S210>/Data Type Duplicate' : Unused code path elimination
 * Block '<S210>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S215>/Data Type Duplicate' : Unused code path elimination
 * Block '<S215>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S218>/Data Type Duplicate' : Unused code path elimination
 * Block '<S218>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate1' : Unused code path elimination
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
 * Block '<S238>/Data Type Duplicate' : Unused code path elimination
 * Block '<S238>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S241>/Data Type Duplicate' : Unused code path elimination
 * Block '<S241>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S244>/Data Type Duplicate' : Unused code path elimination
 * Block '<S244>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S245>/Data Type Duplicate' : Unused code path elimination
 * Block '<S245>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S247>/Data Type Duplicate' : Unused code path elimination
 * Block '<S247>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S248>/Data Type Duplicate' : Unused code path elimination
 * Block '<S248>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S249>/Data Type Duplicate' : Unused code path elimination
 * Block '<S249>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S250>/Data Type Duplicate' : Unused code path elimination
 * Block '<S250>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S251>/Data Type Duplicate' : Unused code path elimination
 * Block '<S251>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S252>/Data Type Duplicate' : Unused code path elimination
 * Block '<S252>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S253>/Data Type Duplicate' : Unused code path elimination
 * Block '<S253>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S254>/Data Type Duplicate' : Unused code path elimination
 * Block '<S254>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S255>/Data Type Duplicate' : Unused code path elimination
 * Block '<S255>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S256>/Data Type Duplicate' : Unused code path elimination
 * Block '<S256>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S260>/Data Type Duplicate' : Unused code path elimination
 * Block '<S260>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S263>/Data Type Duplicate' : Unused code path elimination
 * Block '<S263>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S274>/Data Type Duplicate' : Unused code path elimination
 * Block '<S275>/Data Type Duplicate' : Unused code path elimination
 * Block '<S270>/Relational Operator' : Unused code path elimination
 * Block '<S270>/Relational Operator1' : Unused code path elimination
 * Block '<S276>/Data Type Duplicate' : Unused code path elimination
 * Block '<S276>/Data Type Propagation' : Unused code path elimination
 * Block '<S283>/Data Type Duplicate' : Unused code path elimination
 * Block '<S284>/Data Type Duplicate' : Unused code path elimination
 * Block '<S279>/Relational Operator' : Unused code path elimination
 * Block '<S279>/Relational Operator1' : Unused code path elimination
 * Block '<S285>/Data Type Duplicate' : Unused code path elimination
 * Block '<S285>/Data Type Propagation' : Unused code path elimination
 * Block '<S281>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S281>/x1' : Unused code path elimination
 * Block '<S287>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S287>/x1' : Unused code path elimination
 * Block '<S62>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S62>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S62>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S102>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S102>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S102>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S85>/Switch' : Eliminated due to constant selection input
 * Block '<S86>/Switch' : Eliminated due to constant selection input
 * Block '<S87>/Switch' : Eliminated due to constant selection input
 * Block '<S88>/Switch' : Eliminated due to constant selection input
 * Block '<S68>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S139>/Switch' : Eliminated due to constant selection input
 * Block '<S140>/Switch' : Eliminated due to constant selection input
 * Block '<S141>/Switch' : Eliminated due to constant selection input
 * Block '<S142>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S142>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S142>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S150>/Switch' : Eliminated due to constant selection input
 * Block '<S151>/Switch' : Eliminated due to constant selection input
 * Block '<S152>/Switch' : Eliminated due to constant selection input
 * Block '<S153>/Switch' : Eliminated due to constant selection input
 * Block '<S154>/Switch' : Eliminated due to constant selection input
 * Block '<S155>/Switch' : Eliminated due to constant selection input
 * Block '<S156>/Switch' : Eliminated due to constant selection input
 * Block '<S157>/Switch' : Eliminated due to constant selection input
 * Block '<S158>/Switch' : Eliminated due to constant selection input
 * Block '<S159>/Switch' : Eliminated due to constant selection input
 * Block '<S160>/Switch' : Eliminated due to constant selection input
 * Block '<S161>/Switch' : Eliminated due to constant selection input
 * Block '<S164>/FixPt Gateway Out' : Eliminate redundant data type conversion
 * Block '<S165>/FixPt Gateway Out' : Eliminate redundant data type conversion
 * Block '<S162>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S195>/Switch' : Eliminated due to constant selection input
 * Block '<S196>/Switch' : Eliminated due to constant selection input
 * Block '<S197>/Switch' : Eliminated due to constant selection input
 * Block '<S198>/Switch' : Eliminated due to constant selection input
 * Block '<S199>/Switch' : Eliminated due to constant selection input
 * Block '<S200>/Switch' : Eliminated due to constant selection input
 * Block '<S201>/Switch' : Eliminated due to constant selection input
 * Block '<S202>/Switch' : Eliminated due to constant selection input
 * Block '<S229>/Switch' : Eliminated due to constant selection input
 * Block '<S230>/Switch' : Eliminated due to constant selection input
 * Block '<S231>/Switch' : Eliminated due to constant selection input
 * Block '<S232>/Switch' : Eliminated due to constant selection input
 * Block '<S233>/Switch' : Eliminated due to constant selection input
 * Block '<S234>/Switch' : Eliminated due to constant selection input
 * Block '<S235>/Switch' : Eliminated due to constant selection input
 * Block '<S236>/Switch' : Eliminated due to constant selection input
 * Block '<S274>/Conversion' : Eliminate redundant data type conversion
 * Block '<S275>/Conversion' : Eliminate redundant data type conversion
 * Block '<S280>/Switch1' : Eliminated due to constant selection input
 * Block '<S282>/Switch' : Eliminated due to constant selection input
 * Block '<S288>/Switch' : Eliminated due to constant selection input
 * Block '<S85>/Add3' : Unused code path elimination
 * Block '<S85>/Add4' : Unused code path elimination
 * Block '<S85>/Constant' : Unused code path elimination
 * Block '<S85>/Relational Operator' : Unused code path elimination
 * Block '<S85>/Switch1' : Unused code path elimination
 * Block '<S85>/offset2' : Unused code path elimination
 * Block '<S85>/offset3' : Unused code path elimination
 * Block '<S85>/offset4' : Unused code path elimination
 * Block '<S86>/Add3' : Unused code path elimination
 * Block '<S86>/Add4' : Unused code path elimination
 * Block '<S86>/Constant' : Unused code path elimination
 * Block '<S86>/Relational Operator' : Unused code path elimination
 * Block '<S86>/Switch1' : Unused code path elimination
 * Block '<S86>/offset2' : Unused code path elimination
 * Block '<S86>/offset3' : Unused code path elimination
 * Block '<S86>/offset4' : Unused code path elimination
 * Block '<S87>/Add3' : Unused code path elimination
 * Block '<S87>/Add4' : Unused code path elimination
 * Block '<S87>/Constant' : Unused code path elimination
 * Block '<S87>/Relational Operator' : Unused code path elimination
 * Block '<S87>/Switch1' : Unused code path elimination
 * Block '<S87>/offset2' : Unused code path elimination
 * Block '<S87>/offset3' : Unused code path elimination
 * Block '<S87>/offset4' : Unused code path elimination
 * Block '<S88>/Add3' : Unused code path elimination
 * Block '<S88>/Add4' : Unused code path elimination
 * Block '<S88>/Constant' : Unused code path elimination
 * Block '<S88>/Relational Operator' : Unused code path elimination
 * Block '<S88>/Switch1' : Unused code path elimination
 * Block '<S88>/offset2' : Unused code path elimination
 * Block '<S88>/offset3' : Unused code path elimination
 * Block '<S88>/offset4' : Unused code path elimination
 * Block '<S139>/Add3' : Unused code path elimination
 * Block '<S139>/Add4' : Unused code path elimination
 * Block '<S139>/Constant' : Unused code path elimination
 * Block '<S139>/Relational Operator' : Unused code path elimination
 * Block '<S139>/Switch1' : Unused code path elimination
 * Block '<S139>/offset2' : Unused code path elimination
 * Block '<S139>/offset3' : Unused code path elimination
 * Block '<S139>/offset4' : Unused code path elimination
 * Block '<S140>/Add3' : Unused code path elimination
 * Block '<S140>/Add4' : Unused code path elimination
 * Block '<S140>/Constant' : Unused code path elimination
 * Block '<S140>/Relational Operator' : Unused code path elimination
 * Block '<S140>/Switch1' : Unused code path elimination
 * Block '<S140>/offset2' : Unused code path elimination
 * Block '<S140>/offset3' : Unused code path elimination
 * Block '<S140>/offset4' : Unused code path elimination
 * Block '<S141>/Add3' : Unused code path elimination
 * Block '<S141>/Add4' : Unused code path elimination
 * Block '<S141>/Constant' : Unused code path elimination
 * Block '<S141>/Relational Operator' : Unused code path elimination
 * Block '<S141>/Switch1' : Unused code path elimination
 * Block '<S141>/offset2' : Unused code path elimination
 * Block '<S141>/offset3' : Unused code path elimination
 * Block '<S141>/offset4' : Unused code path elimination
 * Block '<S150>/Add3' : Unused code path elimination
 * Block '<S150>/Add4' : Unused code path elimination
 * Block '<S150>/Constant' : Unused code path elimination
 * Block '<S150>/Relational Operator' : Unused code path elimination
 * Block '<S150>/Switch1' : Unused code path elimination
 * Block '<S150>/offset2' : Unused code path elimination
 * Block '<S150>/offset3' : Unused code path elimination
 * Block '<S150>/offset4' : Unused code path elimination
 * Block '<S151>/Add3' : Unused code path elimination
 * Block '<S151>/Add4' : Unused code path elimination
 * Block '<S151>/Constant' : Unused code path elimination
 * Block '<S151>/Relational Operator' : Unused code path elimination
 * Block '<S151>/Switch1' : Unused code path elimination
 * Block '<S151>/offset2' : Unused code path elimination
 * Block '<S151>/offset3' : Unused code path elimination
 * Block '<S151>/offset4' : Unused code path elimination
 * Block '<S152>/Add3' : Unused code path elimination
 * Block '<S152>/Add4' : Unused code path elimination
 * Block '<S152>/Constant' : Unused code path elimination
 * Block '<S152>/Relational Operator' : Unused code path elimination
 * Block '<S152>/Switch1' : Unused code path elimination
 * Block '<S152>/offset2' : Unused code path elimination
 * Block '<S152>/offset3' : Unused code path elimination
 * Block '<S152>/offset4' : Unused code path elimination
 * Block '<S153>/Add3' : Unused code path elimination
 * Block '<S153>/Add4' : Unused code path elimination
 * Block '<S153>/Constant' : Unused code path elimination
 * Block '<S153>/Relational Operator' : Unused code path elimination
 * Block '<S153>/Switch1' : Unused code path elimination
 * Block '<S153>/offset2' : Unused code path elimination
 * Block '<S153>/offset3' : Unused code path elimination
 * Block '<S153>/offset4' : Unused code path elimination
 * Block '<S154>/Add3' : Unused code path elimination
 * Block '<S154>/Add4' : Unused code path elimination
 * Block '<S154>/Constant' : Unused code path elimination
 * Block '<S154>/Relational Operator' : Unused code path elimination
 * Block '<S154>/Switch1' : Unused code path elimination
 * Block '<S154>/offset2' : Unused code path elimination
 * Block '<S154>/offset3' : Unused code path elimination
 * Block '<S154>/offset4' : Unused code path elimination
 * Block '<S155>/Add3' : Unused code path elimination
 * Block '<S155>/Add4' : Unused code path elimination
 * Block '<S155>/Constant' : Unused code path elimination
 * Block '<S155>/Relational Operator' : Unused code path elimination
 * Block '<S155>/Switch1' : Unused code path elimination
 * Block '<S155>/offset2' : Unused code path elimination
 * Block '<S155>/offset3' : Unused code path elimination
 * Block '<S155>/offset4' : Unused code path elimination
 * Block '<S156>/Add3' : Unused code path elimination
 * Block '<S156>/Add4' : Unused code path elimination
 * Block '<S156>/Constant' : Unused code path elimination
 * Block '<S156>/Relational Operator' : Unused code path elimination
 * Block '<S156>/Switch1' : Unused code path elimination
 * Block '<S156>/offset2' : Unused code path elimination
 * Block '<S156>/offset3' : Unused code path elimination
 * Block '<S156>/offset4' : Unused code path elimination
 * Block '<S157>/Add3' : Unused code path elimination
 * Block '<S157>/Add4' : Unused code path elimination
 * Block '<S157>/Constant' : Unused code path elimination
 * Block '<S157>/Relational Operator' : Unused code path elimination
 * Block '<S157>/Switch1' : Unused code path elimination
 * Block '<S157>/offset2' : Unused code path elimination
 * Block '<S157>/offset3' : Unused code path elimination
 * Block '<S157>/offset4' : Unused code path elimination
 * Block '<S158>/Add3' : Unused code path elimination
 * Block '<S158>/Add4' : Unused code path elimination
 * Block '<S158>/Constant' : Unused code path elimination
 * Block '<S158>/Relational Operator' : Unused code path elimination
 * Block '<S158>/Switch1' : Unused code path elimination
 * Block '<S158>/offset2' : Unused code path elimination
 * Block '<S158>/offset3' : Unused code path elimination
 * Block '<S158>/offset4' : Unused code path elimination
 * Block '<S159>/Add3' : Unused code path elimination
 * Block '<S159>/Add4' : Unused code path elimination
 * Block '<S159>/Constant' : Unused code path elimination
 * Block '<S159>/Relational Operator' : Unused code path elimination
 * Block '<S159>/Switch1' : Unused code path elimination
 * Block '<S159>/offset2' : Unused code path elimination
 * Block '<S159>/offset3' : Unused code path elimination
 * Block '<S159>/offset4' : Unused code path elimination
 * Block '<S160>/Add3' : Unused code path elimination
 * Block '<S160>/Add4' : Unused code path elimination
 * Block '<S160>/Constant' : Unused code path elimination
 * Block '<S160>/Relational Operator' : Unused code path elimination
 * Block '<S160>/Switch1' : Unused code path elimination
 * Block '<S160>/offset2' : Unused code path elimination
 * Block '<S160>/offset3' : Unused code path elimination
 * Block '<S160>/offset4' : Unused code path elimination
 * Block '<S161>/Add3' : Unused code path elimination
 * Block '<S161>/Add4' : Unused code path elimination
 * Block '<S161>/Constant' : Unused code path elimination
 * Block '<S161>/Relational Operator' : Unused code path elimination
 * Block '<S161>/Switch1' : Unused code path elimination
 * Block '<S161>/offset2' : Unused code path elimination
 * Block '<S161>/offset3' : Unused code path elimination
 * Block '<S161>/offset4' : Unused code path elimination
 * Block '<S195>/Add3' : Unused code path elimination
 * Block '<S195>/Add4' : Unused code path elimination
 * Block '<S195>/Constant' : Unused code path elimination
 * Block '<S195>/Relational Operator' : Unused code path elimination
 * Block '<S195>/Switch1' : Unused code path elimination
 * Block '<S195>/offset2' : Unused code path elimination
 * Block '<S195>/offset3' : Unused code path elimination
 * Block '<S195>/offset4' : Unused code path elimination
 * Block '<S196>/Add3' : Unused code path elimination
 * Block '<S196>/Add4' : Unused code path elimination
 * Block '<S196>/Constant' : Unused code path elimination
 * Block '<S196>/Relational Operator' : Unused code path elimination
 * Block '<S196>/Switch1' : Unused code path elimination
 * Block '<S196>/offset2' : Unused code path elimination
 * Block '<S196>/offset3' : Unused code path elimination
 * Block '<S196>/offset4' : Unused code path elimination
 * Block '<S197>/Add3' : Unused code path elimination
 * Block '<S197>/Add4' : Unused code path elimination
 * Block '<S197>/Constant' : Unused code path elimination
 * Block '<S197>/Relational Operator' : Unused code path elimination
 * Block '<S197>/Switch1' : Unused code path elimination
 * Block '<S197>/offset2' : Unused code path elimination
 * Block '<S197>/offset3' : Unused code path elimination
 * Block '<S197>/offset4' : Unused code path elimination
 * Block '<S198>/Add3' : Unused code path elimination
 * Block '<S198>/Add4' : Unused code path elimination
 * Block '<S198>/Constant' : Unused code path elimination
 * Block '<S198>/Relational Operator' : Unused code path elimination
 * Block '<S198>/Switch1' : Unused code path elimination
 * Block '<S198>/offset2' : Unused code path elimination
 * Block '<S198>/offset3' : Unused code path elimination
 * Block '<S198>/offset4' : Unused code path elimination
 * Block '<S199>/Add3' : Unused code path elimination
 * Block '<S199>/Add4' : Unused code path elimination
 * Block '<S199>/Constant' : Unused code path elimination
 * Block '<S199>/Relational Operator' : Unused code path elimination
 * Block '<S199>/Switch1' : Unused code path elimination
 * Block '<S199>/offset2' : Unused code path elimination
 * Block '<S199>/offset3' : Unused code path elimination
 * Block '<S199>/offset4' : Unused code path elimination
 * Block '<S200>/Add3' : Unused code path elimination
 * Block '<S200>/Add4' : Unused code path elimination
 * Block '<S200>/Constant' : Unused code path elimination
 * Block '<S200>/Relational Operator' : Unused code path elimination
 * Block '<S200>/Switch1' : Unused code path elimination
 * Block '<S200>/offset2' : Unused code path elimination
 * Block '<S200>/offset3' : Unused code path elimination
 * Block '<S200>/offset4' : Unused code path elimination
 * Block '<S201>/Add3' : Unused code path elimination
 * Block '<S201>/Add4' : Unused code path elimination
 * Block '<S201>/Constant' : Unused code path elimination
 * Block '<S201>/Relational Operator' : Unused code path elimination
 * Block '<S201>/Switch1' : Unused code path elimination
 * Block '<S201>/offset2' : Unused code path elimination
 * Block '<S201>/offset3' : Unused code path elimination
 * Block '<S201>/offset4' : Unused code path elimination
 * Block '<S202>/Add3' : Unused code path elimination
 * Block '<S202>/Add4' : Unused code path elimination
 * Block '<S202>/Constant' : Unused code path elimination
 * Block '<S202>/Relational Operator' : Unused code path elimination
 * Block '<S202>/Switch1' : Unused code path elimination
 * Block '<S202>/offset2' : Unused code path elimination
 * Block '<S202>/offset3' : Unused code path elimination
 * Block '<S202>/offset4' : Unused code path elimination
 * Block '<S229>/Add3' : Unused code path elimination
 * Block '<S229>/Add4' : Unused code path elimination
 * Block '<S229>/Constant' : Unused code path elimination
 * Block '<S229>/Relational Operator' : Unused code path elimination
 * Block '<S229>/Switch1' : Unused code path elimination
 * Block '<S229>/offset2' : Unused code path elimination
 * Block '<S229>/offset3' : Unused code path elimination
 * Block '<S229>/offset4' : Unused code path elimination
 * Block '<S230>/Add3' : Unused code path elimination
 * Block '<S230>/Add4' : Unused code path elimination
 * Block '<S230>/Constant' : Unused code path elimination
 * Block '<S230>/Relational Operator' : Unused code path elimination
 * Block '<S230>/Switch1' : Unused code path elimination
 * Block '<S230>/offset2' : Unused code path elimination
 * Block '<S230>/offset3' : Unused code path elimination
 * Block '<S230>/offset4' : Unused code path elimination
 * Block '<S231>/Add3' : Unused code path elimination
 * Block '<S231>/Add4' : Unused code path elimination
 * Block '<S231>/Constant' : Unused code path elimination
 * Block '<S231>/Relational Operator' : Unused code path elimination
 * Block '<S231>/Switch1' : Unused code path elimination
 * Block '<S231>/offset2' : Unused code path elimination
 * Block '<S231>/offset3' : Unused code path elimination
 * Block '<S231>/offset4' : Unused code path elimination
 * Block '<S232>/Add3' : Unused code path elimination
 * Block '<S232>/Add4' : Unused code path elimination
 * Block '<S232>/Constant' : Unused code path elimination
 * Block '<S232>/Relational Operator' : Unused code path elimination
 * Block '<S232>/Switch1' : Unused code path elimination
 * Block '<S232>/offset2' : Unused code path elimination
 * Block '<S232>/offset3' : Unused code path elimination
 * Block '<S232>/offset4' : Unused code path elimination
 * Block '<S233>/Add3' : Unused code path elimination
 * Block '<S233>/Add4' : Unused code path elimination
 * Block '<S233>/Constant' : Unused code path elimination
 * Block '<S233>/Relational Operator' : Unused code path elimination
 * Block '<S233>/Switch1' : Unused code path elimination
 * Block '<S233>/offset2' : Unused code path elimination
 * Block '<S233>/offset3' : Unused code path elimination
 * Block '<S233>/offset4' : Unused code path elimination
 * Block '<S234>/Add3' : Unused code path elimination
 * Block '<S234>/Add4' : Unused code path elimination
 * Block '<S234>/Constant' : Unused code path elimination
 * Block '<S234>/Relational Operator' : Unused code path elimination
 * Block '<S234>/Switch1' : Unused code path elimination
 * Block '<S234>/offset2' : Unused code path elimination
 * Block '<S234>/offset3' : Unused code path elimination
 * Block '<S234>/offset4' : Unused code path elimination
 * Block '<S235>/Add3' : Unused code path elimination
 * Block '<S235>/Add4' : Unused code path elimination
 * Block '<S235>/Constant' : Unused code path elimination
 * Block '<S235>/Relational Operator' : Unused code path elimination
 * Block '<S235>/Switch1' : Unused code path elimination
 * Block '<S235>/offset2' : Unused code path elimination
 * Block '<S235>/offset3' : Unused code path elimination
 * Block '<S235>/offset4' : Unused code path elimination
 * Block '<S236>/Add3' : Unused code path elimination
 * Block '<S236>/Add4' : Unused code path elimination
 * Block '<S236>/Constant' : Unused code path elimination
 * Block '<S236>/Relational Operator' : Unused code path elimination
 * Block '<S236>/Switch1' : Unused code path elimination
 * Block '<S236>/offset2' : Unused code path elimination
 * Block '<S236>/offset3' : Unused code path elimination
 * Block '<S236>/offset4' : Unused code path elimination
 * Block '<S267>/Constant1' : Unused code path elimination
 * Block '<S267>/Data Type Conversion3' : Unused code path elimination
 * Block '<S282>/Add3' : Unused code path elimination
 * Block '<S282>/Add4' : Unused code path elimination
 * Block '<S282>/Constant' : Unused code path elimination
 * Block '<S282>/Relational Operator' : Unused code path elimination
 * Block '<S282>/Switch1' : Unused code path elimination
 * Block '<S282>/offset2' : Unused code path elimination
 * Block '<S282>/offset3' : Unused code path elimination
 * Block '<S282>/offset4' : Unused code path elimination
 * Block '<S288>/Add3' : Unused code path elimination
 * Block '<S288>/Add4' : Unused code path elimination
 * Block '<S288>/Constant' : Unused code path elimination
 * Block '<S288>/Relational Operator' : Unused code path elimination
 * Block '<S288>/Switch1' : Unused code path elimination
 * Block '<S288>/offset2' : Unused code path elimination
 * Block '<S288>/offset3' : Unused code path elimination
 * Block '<S288>/offset4' : Unused code path elimination
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
 * hilite_system('InjSpMgt_AUTOCODE/InjSpMgt')    - opens subsystem InjSpMgt_AUTOCODE/InjSpMgt
 * hilite_system('InjSpMgt_AUTOCODE/InjSpMgt/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InjSpMgt_AUTOCODE
 * '<S1>'   : InjSpMgt_AUTOCODE/InjSpMgt
 * '<S8>'   : InjSpMgt_AUTOCODE/InjSpMgt/F00_Init
 * '<S9>'   : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct
 * '<S10>'  : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync
 * '<S11>'  : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2
 * '<S12>'  : InjSpMgt_AUTOCODE/InjSpMgt/F03a_PfurailInit
 * '<S13>'  : InjSpMgt_AUTOCODE/InjSpMgt/F04_InhFrstInjSTT
 * '<S14>'  : InjSpMgt_AUTOCODE/InjSpMgt/InjSpMgt_fc_demux
 * '<S15>'  : InjSpMgt_AUTOCODE/InjSpMgt/InjSpMgt_fc_demux1
 * '<S16>'  : InjSpMgt_AUTOCODE/InjSpMgt/InjSpMgt_fc_demux3
 * '<S17>'  : InjSpMgt_AUTOCODE/InjSpMgt/InjSpMgt_fc_demux4
 * '<S18>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct
 * '<S19>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf
 * '<S20>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac
 * '<S21>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha
 * '<S22>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm
 * '<S23>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F04_AcvFctClcn
 * '<S24>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F01_RunCase
 * '<S25>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F02_NoRunCase
 * '<S26>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F01_RunCase/Interp
 * '<S27>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F01_RunCase/Interp1
 * '<S28>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F01_RunCase/One_Based_Selector
 * '<S29>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F01_RunCase/One_Based_Selector1
 * '<S30>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F01_RunCase/PosHys
 * '<S31>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F01_RunCase/PreLookUp
 * '<S32>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F01_RunCase/PosHys/BasculeRS
 * '<S33>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F02_NoRunCase/Interp
 * '<S34>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F02_NoRunCase/Interp1
 * '<S35>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F02_NoRunCase/PosHys
 * '<S36>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F02_NoRunCase/PreLookUp
 * '<S37>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F00_InjSpIf/F02_NoRunCase/PosHys/BasculeRS
 * '<S38>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet
 * '<S39>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F02_rMassFuInjclcn
 * '<S40>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/Interp
 * '<S41>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/Interp1
 * '<S42>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/NegHys
 * '<S43>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/NegHys1
 * '<S44>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/NegHys2
 * '<S45>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/NegHys3
 * '<S46>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/PreLookUp
 * '<S47>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/multiplication_1
 * '<S48>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/multiplication_2
 * '<S49>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/multiplication_3
 * '<S50>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/multiplication_4
 * '<S51>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/multiplication_421
 * '<S52>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/multiplication_5
 * '<S53>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/multiplication_6
 * '<S54>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/multiplication_7
 * '<S55>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/NegHys/BasculeRS
 * '<S56>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/NegHys1/BasculeRS
 * '<S57>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/NegHys2/BasculeRS
 * '<S58>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F01_tiInjMinDet/NegHys3/BasculeRS
 * '<S59>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F02_rMassFuInjclcn/F01_InjVldChk
 * '<S60>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F02_rMassFuInjclcn/F02_noVldInjCase
 * '<S61>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F02_rMassFuInjclcn/F03_VldInjCase
 * '<S62>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F02_rMassFuInjclcn/F03_VldInjCase/Subsystem
 * '<S63>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F02_rMassFuInjclcn/F03_VldInjCase/Subsystem/Data Type Police Only single
 * '<S64>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F01_TestFrac/F02_rMassFuInjclcn/F03_VldInjCase/Subsystem/If Action Subsystem3
 * '<S65>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp
 * '<S66>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp
 * '<S67>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp
 * '<S68>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F04_DetSatPhaInj
 * '<S69>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp/multiplication_1
 * '<S70>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp/multiplication_2
 * '<S71>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp/multiplication_3
 * '<S72>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp/multiplication_4
 * '<S73>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp/multiplication_481
 * '<S74>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp/multiplication_5
 * '<S75>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp/multiplication_6
 * '<S76>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F01_tiInjSp/multiplication_7
 * '<S77>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F01_InjHom1Width
 * '<S78>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F02_InjHom1WidthNul
 * '<S79>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F03_InjHom2Width
 * '<S80>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F04_InjHom2WidthNul
 * '<S81>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F05_InjS1Width
 * '<S82>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F06_InjS1WidthNul
 * '<S83>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F07_InjS2Width
 * '<S84>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F08_InjS2WidthNul
 * '<S85>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/SingleToFixdt
 * '<S86>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/SingleToFixdt1
 * '<S87>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/SingleToFixdt2
 * '<S88>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/SingleToFixdt3
 * '<S89>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F01_InjHom1Width/One_Based_Selector
 * '<S90>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F01_InjHom1Width/Subsystem
 * '<S91>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F01_InjHom1Width/multiplication_1
 * '<S92>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F01_InjHom1Width/multiplication_491
 * '<S93>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F01_InjHom1Width/Subsystem/Data Type Police Only single
 * '<S94>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F01_InjHom1Width/Subsystem/If Action Subsystem3
 * '<S95>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F03_InjHom2Width/One_Based_Selector
 * '<S96>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F03_InjHom2Width/Subsystem
 * '<S97>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F03_InjHom2Width/multiplication_1
 * '<S98>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F03_InjHom2Width/multiplication_491
 * '<S99>'  : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F03_InjHom2Width/Subsystem/Data Type Police Only single
 * '<S100>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F03_InjHom2Width/Subsystem/If Action Subsystem3
 * '<S101>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F05_InjS1Width/One_Based_Selector
 * '<S102>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F05_InjS1Width/Subsystem
 * '<S103>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F05_InjS1Width/multiplication_1
 * '<S104>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F05_InjS1Width/multiplication_491
 * '<S105>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F05_InjS1Width/Subsystem/Data Type Police Only single
 * '<S106>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F05_InjS1Width/Subsystem/If Action Subsystem3
 * '<S107>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F07_InjS2Width/One_Based_Selector
 * '<S108>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F07_InjS2Width/Subsystem
 * '<S109>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F07_InjS2Width/multiplication_1
 * '<S110>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F07_InjS2Width/multiplication_491
 * '<S111>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F07_InjS2Width/Subsystem/Data Type Police Only single
 * '<S112>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F02_agWdInjSp/F07_InjS2Width/Subsystem/If Action Subsystem3
 * '<S113>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F01_agOfsPhaInjClcn
 * '<S114>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop
 * '<S115>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop
 * '<S116>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F01_agOfsPhaInjClcn/Interp
 * '<S117>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F01_agOfsPhaInjClcn/Interp1
 * '<S118>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F01_agOfsPhaInjClcn/PreLookUp
 * '<S119>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop/F01_PhaInjS2
 * '<S120>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop/F02_PhaInjS1
 * '<S121>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop/F03_PhaInjH2
 * '<S122>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop/F04_PhaInjH1
 * '<S123>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop/F01_PhaInjS2/LookUp_1D
 * '<S124>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop/F01_PhaInjS2/LookUp_2D
 * '<S125>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop/F04_PhaInjH1/PosHys
 * '<S126>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F02_agInjSpnoSTTStop/F04_PhaInjH1/PosHys/BasculeRS
 * '<S127>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop/F01_FrstInjSTTOfsClcn
 * '<S128>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop/F02_PhaInjS2STT
 * '<S129>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop/F03_PhaInjS1STT
 * '<S130>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop/F04_PhaInjH2STT
 * '<S131>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop/F05_PhaInjH1STT
 * '<S132>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop/F06_noInCylSTOP
 * '<S133>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop/F01_FrstInjSTTOfsClcn/LookUp_1D
 * '<S134>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F02_TestPha/F03_agInjSp/F03_agInjSpSTTStop/F02_PhaInjS2STT/LookUp_2D
 * '<S135>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod
 * '<S136>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod
 * '<S137>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/LookUp_2D
 * '<S138>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/LookUp_2D1
 * '<S139>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/SingleToFixdt
 * '<S140>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/SingleToFixdt1
 * '<S141>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/SingleToFixdt2
 * '<S142>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/Subsystem
 * '<S143>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/Subsystem1
 * '<S144>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/multiplication_4261
 * '<S145>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/multiplication_4281
 * '<S146>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/Subsystem/Data Type Police Only single
 * '<S147>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/Subsystem/If Action Subsystem3
 * '<S148>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/Subsystem1/Data Type Police Only single
 * '<S149>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F01_SpcInjMod/Subsystem1/If Action Subsystem3
 * '<S150>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt
 * '<S151>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt1
 * '<S152>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt10
 * '<S153>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt11
 * '<S154>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt2
 * '<S155>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt3
 * '<S156>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt4
 * '<S157>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt5
 * '<S158>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt6
 * '<S159>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt7
 * '<S160>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt8
 * '<S161>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F03_InjPrm/F02_NoSpcInjMod/SingleToFixdt9
 * '<S162>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F04_AcvFctClcn/Modulo
 * '<S163>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F04_AcvFctClcn/division_4291
 * '<S164>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F04_AcvFctClcn/Modulo/Data Type Scaling Strip
 * '<S165>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F04_AcvFctClcn/Modulo/Data Type Scaling Strip1
 * '<S166>' : InjSpMgt_AUTOCODE/InjSpMgt/F01_InjSpMgtFct/F01_InjSpMgtFct/F04_AcvFctClcn/Modulo/Data Type Police No Floating Point
 * '<S167>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank
 * '<S168>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt
 * '<S169>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt
 * '<S170>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank
 * '<S171>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment1
 * '<S172>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment10
 * '<S173>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment11
 * '<S174>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment12
 * '<S175>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment13
 * '<S176>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment14
 * '<S177>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment15
 * '<S178>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment16
 * '<S179>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment17
 * '<S180>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment18
 * '<S181>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment19
 * '<S182>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment2
 * '<S183>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment20
 * '<S184>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment21
 * '<S185>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment22
 * '<S186>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment23
 * '<S187>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment24
 * '<S188>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment3
 * '<S189>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment4
 * '<S190>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment5
 * '<S191>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment6
 * '<S192>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment7
 * '<S193>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment8
 * '<S194>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/One_Based_Assignment9
 * '<S195>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/SingleToFixdt1
 * '<S196>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/SingleToFixdt2
 * '<S197>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/SingleToFixdt3
 * '<S198>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/SingleToFixdt4
 * '<S199>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/SingleToFixdt5
 * '<S200>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/SingleToFixdt6
 * '<S201>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/SingleToFixdt7
 * '<S202>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/SingleToFixdt8
 * '<S203>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/UnitDelay1
 * '<S204>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/UnitDelay6
 * '<S205>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/UnitDelay7
 * '<S206>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F01_SyncRotToCrank/F01_SyncRotToCrank/UnitDelay8
 * '<S207>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt
 * '<S208>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment1
 * '<S209>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment10
 * '<S210>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment11
 * '<S211>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment12
 * '<S212>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment13
 * '<S213>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment14
 * '<S214>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment15
 * '<S215>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment16
 * '<S216>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment17
 * '<S217>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment18
 * '<S218>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment19
 * '<S219>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment2
 * '<S220>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment20
 * '<S221>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment21
 * '<S222>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment3
 * '<S223>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment4
 * '<S224>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment5
 * '<S225>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment6
 * '<S226>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment7
 * '<S227>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment8
 * '<S228>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/One_Based_Assignment9
 * '<S229>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/SingleToFixdt
 * '<S230>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/SingleToFixdt1
 * '<S231>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/SingleToFixdt2
 * '<S232>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/SingleToFixdt3
 * '<S233>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/SingleToFixdt4
 * '<S234>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/SingleToFixdt5
 * '<S235>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/SingleToFixdt6
 * '<S236>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F02_SdlEveClcn_InjSpMgt/F02_SdlEveClcn_InjSpMgt/SingleToFixdt7
 * '<S237>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt
 * '<S238>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment
 * '<S239>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment1
 * '<S240>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment10
 * '<S241>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment11
 * '<S242>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment12
 * '<S243>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment13
 * '<S244>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment14
 * '<S245>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment15
 * '<S246>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment16
 * '<S247>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment17
 * '<S248>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment18
 * '<S249>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment19
 * '<S250>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment2
 * '<S251>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment20
 * '<S252>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment21
 * '<S253>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment22
 * '<S254>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment23
 * '<S255>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment24
 * '<S256>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment25
 * '<S257>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment3
 * '<S258>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment4
 * '<S259>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment5
 * '<S260>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment6
 * '<S261>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment7
 * '<S262>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment8
 * '<S263>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/One_Based_Assignment9
 * '<S264>' : InjSpMgt_AUTOCODE/InjSpMgt/F02_InjSpMgtOutSync/F03_SyncEveClcn_InjSpMgt/F03_SyncEveClcn_InjSpMgt/SubSystem13
 * '<S265>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2
 * '<S266>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw
 * '<S267>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt
 * '<S268>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter
 * '<S269>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/multiplication_4261
 * '<S270>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/Clamp
 * '<S271>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/UnitDly_ExtIni
 * '<S272>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/multiplication_1
 * '<S273>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/multiplication_4281
 * '<S274>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/Clamp/Data Type Conversion Inherited
 * '<S275>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/Clamp/Data Type Conversion Inherited1
 * '<S276>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/Clamp/Saturation Dynamic
 * '<S277>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/UnitDly_ExtIni/SubSystem
 * '<S278>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F01_PFuReqRaw/RateLimiter/UnitDly_ExtIni/SubSystem1
 * '<S279>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt/Clamp
 * '<S280>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt/Filtre_1er_ordre_Init
 * '<S281>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt/LookUp_1D
 * '<S282>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt/SingleToFixdt
 * '<S283>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt/Clamp/Data Type Conversion Inherited
 * '<S284>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt/Clamp/Data Type Conversion Inherited1
 * '<S285>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt/Clamp/Saturation Dynamic
 * '<S286>' : InjSpMgt_AUTOCODE/InjSpMgt/F03_InjSpMgtFct2/F03_InjSpMgtFct2/F02_PfuFilt/Filtre_1er_ordre_Init/multiplication_4281
 * '<S287>' : InjSpMgt_AUTOCODE/InjSpMgt/F03a_PfurailInit/LookUp_1D
 * '<S288>' : InjSpMgt_AUTOCODE/InjSpMgt/F03a_PfurailInit/SingleToFixdt
 * '<S289>' : InjSpMgt_AUTOCODE/InjSpMgt/F04_InhFrstInjSTT/F01_InhFrstInjCkOn
 * '<S290>' : InjSpMgt_AUTOCODE/InjSpMgt/F04_InhFrstInjSTT/F02_InhFrstInjSdlFast
 * '<S291>' : InjSpMgt_AUTOCODE/InjSpMgt/F04_InhFrstInjSTT/F01_InhFrstInjCkOn/F01_InhFrstInjCkOn
 * '<S292>' : InjSpMgt_AUTOCODE/InjSpMgt/F04_InhFrstInjSTT/F02_InhFrstInjSdlFast/F02_InhFrstInjSdlFast
 */

/*-
 * Requirements for '<Root>': InjSpMgt
 */
#endif                                 /* RTW_HEADER_InjSpMgt_h_ */

/*-------------------------------- end of file -------------------------------*/
