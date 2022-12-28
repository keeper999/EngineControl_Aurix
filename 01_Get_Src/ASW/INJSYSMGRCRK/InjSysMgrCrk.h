/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSysMgrCrk                                            */
/* !Description     : InjSysMgrCrk : Start manager                            */
/*                                                                            */
/* !Module          : InjSysMgrCrk                                            */
/*                                                                            */
/* !File            : InjSysMgrCrk.h                                          */
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
/*   Code generated on: Wed May 01 18:07:07 2013                              */
/*   Model name       : InjSysMgrCrk_AUTOCODE.mdl                             */
/*   Model version    : 1.204                                                 */
/*   Root subsystem   : /InjSysMgrCrk                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJSYSMGRCRK/InjSysMgrCrk.$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   14 May 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjSysMgrCrk_h_
#define RTW_HEADER_InjSysMgrCrk_h_
#ifndef InjSysMgrCrk_COMMON_INCLUDES_
# define InjSysMgrCrk_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "InjSysMgrCrk_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MAX.h"
#include "rt_MIN.h"
#endif                                 /* InjSysMgrCrk_COMMON_INCLUDES_ */

#include "InjSysMgrCrk_types.h"

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

/* Block signals for system '<S12>/F01_StallToRot_StrtHP' */
typedef struct {
  UInt16 Merge1;                     /* '<S16>/Merge1' */
  UInt8 Merge2;                      /* '<S16>/Merge2' */
  Boolean ConstMat[6];               /* '<S17>/ConstMat' */
  Boolean ConstVal;                  /* '<S17>/ConstVal' */
  Boolean RelationalOperator6;       /* '<S17>/Relational Operator6' */
  Boolean Merge3;                    /* '<S15>/Merge3' */
  Boolean Merge4;                    /* '<S15>/Merge4' */
  Boolean Merge5;                    /* '<S15>/Merge5' */
  Boolean Merge2_p;                  /* '<S14>/Merge2' */
} rtB_F01_StallToRot_StrtHP_InjSy;

/* Block signals (auto storage) */
typedef struct {
  SInt16 VEMS_vidGET6;                /* '<S8>/VEMS_vidGET6' */
  SInt16 VEMS_vidGET6_b;              /* '<S12>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET5;               /* '<S8>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET5_h;             /* '<S12>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET5_j;             /* '<S57>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET4;               /* '<S57>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET7;               /* '<S8>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET7_n;             /* '<S12>/VEMS_vidGET7' */
  UInt8 VEMS_vidGET2;                /* '<S8>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET2_c;              /* '<S12>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET;                 /* '<S82>/VEMS_vidGET' */
  UInt8 VEMS_vidGET6_g;              /* '<S82>/VEMS_vidGET6' */
  UInt8 VEMS_vidGET1;                /* '<S82>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET2_n;              /* '<S57>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET1_k;              /* '<S57>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_d;               /* '<S57>/VEMS_vidGET' */
  UInt8 Merge1;                      /* '<S57>/Merge1' */
  Boolean VEMS_vidGET4_p;            /* '<S8>/VEMS_vidGET4' */
  Boolean VEMS_vidGET3;              /* '<S8>/VEMS_vidGET3' */
  Boolean VEMS_vidGET1_h;            /* '<S8>/VEMS_vidGET1' */
  Boolean VEMS_vidGET_f;             /* '<S8>/VEMS_vidGET' */
  Boolean VEMS_vidGET4_px;           /* '<S12>/VEMS_vidGET4' */
  Boolean VEMS_vidGET3_o;            /* '<S12>/VEMS_vidGET3' */
  Boolean VEMS_vidGET1_o;            /* '<S12>/VEMS_vidGET1' */
  Boolean VEMS_vidGET_k;             /* '<S12>/VEMS_vidGET' */
  Boolean VEMS_vidGET3_b;            /* '<S82>/VEMS_vidGET3' */
  Boolean VEMS_vidGET4_j[6];         /* '<S82>/VEMS_vidGET4' */
  Boolean VEMS_vidGET2_m;            /* '<S82>/VEMS_vidGET2' */
  Boolean Assignment[6];             /* '<S83>/Assignment' */
  Boolean VEMS_vidGET3_l;            /* '<S57>/VEMS_vidGET3' */
  Boolean Merge2;                    /* '<S57>/Merge2' */
  Boolean Merge3;                    /* '<S57>/Merge3' */
  Boolean Merge4[6];                 /* '<S57>/Merge4' */
  Boolean Merge5;                    /* '<S57>/Merge5' */
  Boolean SignalConversion3;         /* '<S58>/Signal Conversion3' */
  Boolean SignalConversion4;         /* '<S58>/Signal Conversion4' */
  Boolean SignalConversion5;         /* '<S58>/Signal Conversion5' */
  UInt8 VEMS_vidGET5_d;              /* '<S82>/VEMS_vidGET5' */
  rtB_F01_StallToRot_StrtHP_InjSy F01_StallToRot_StrtHP_d;/* '<S8>/F01_StallToRot_StrtHP' */
  rtB_F01_StallToRot_StrtHP_InjSy F01_StallToRot_StrtHP_n;/* '<S12>/F01_StallToRot_StrtHP' */
} BlockIO_InjSysMgrCrk;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Boolean UnitDelay_DSTATE;          /* '<S81>/Unit Delay' */
  Boolean UnitDelay_DSTATE_h;        /* '<S76>/Unit Delay' */
  Boolean UnitDelay_DSTATE_b;        /* '<S74>/Unit Delay' */
  Boolean UnitDelay_DSTATE_l;        /* '<S75>/Unit Delay' */
  Boolean UnitDelay_DSTATE_d;        /* '<S77>/Unit Delay' */
  Boolean UnitDelay_DSTATE_o;        /* '<S73>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S66>/UnitDelay' */
  Boolean UnitDelay_p;               /* '<S66>/UnitDelay1' */
} D_Work_InjSysMgrCrk;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/Logic'
   *   '<S70>/Logic'
   */
  Boolean pooled6[16];

  /* Computed Parameter: ConstMat_Value_b
   * Referenced by: '<S59>/ConstMat'
   */
  Boolean ConstMat_Value_b[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S39>/ConstMat'
   *   '<S17>/ConstMat'
   */
  Boolean pooled7[6];
} ConstParam_InjSysMgrCrk;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJSYSMGRCRK_START_SEC_VAR_UNSPECIFIED
#include "InjSysMgrCrk_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InjSysMgrCrk InjSysMgrCrk_B;

/* Block states (auto storage) */
extern D_Work_InjSysMgrCrk InjSysMgrCrk_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_InjSysMgrCrk InjSysMgrCrk_ConstP;

#define INJSYSMGRCRK_STOP_SEC_VAR_UNSPECIFIED
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define INJSYSMGRCRK_START_SEC_CODE
#include "InjSysMgrCrk_MemMap.h"

/* Model entry point functions */
extern void InjSysMgrCrk_initialize(void);
extern void InjSys_EveStTR_InjSysMgrCrk(void);
extern void InjSys_EveRst_InjSysMgrCrk(void);
extern void InjSys_EveRTSt_InjSysMgrCrk(void);
extern void InjSys_EveInj_InjSysMgrCrk(void);
extern void InjSys_EveCkSnNtAc_InjSysMgrCrk(void);

#define INJSYSMGRCRK_STOP_SEC_CODE
#include "InjSysMgrCrk_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define INJSYSMGRCRK_START_SEC_CALIB_16BIT
#include "InjSysMgrCrk_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuRailLoThdInhHPst_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThAcvInjLPSt_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModHSTT_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModH_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModSSTT_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModS_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModSplSTT_T[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_pFuThdAcvInjModSpl_T[16];

/* Type:    UInt16                                                          */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern CONST(UInt16, INJSYSMGRCRK_CALIB) InjSys_tFuHPSt_A[9];

#define INJSYSMGRCRK_STOP_SEC_CALIB_16BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJSYSMGRCRK_START_SEC_CALIB_8BIT
#include "InjSysMgrCrk_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_bAuthHPStSTT_T[9];

/* Type:    UInt8                                                           */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_bAuthHPSt_T[9];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_ctTDCThdAcvInjHPRstrt_T[16];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_ctTDCThdAcvInjHPstSTT_T[16];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_ctTDCThdAcvInjHPst_T[16];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvHPstSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvHPst_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSplLPSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSplstLP_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSplstSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSplst_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSstSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoHiThdAcvModSst_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvHPstSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvHPst_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSplLPSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSplstLP_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSplstSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSplst_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSstSTT_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJSYSMGRCRK_CALIB) InjSys_tCoLoThdAcvModSst_C;

#define INJSYSMGRCRK_STOP_SEC_CALIB_8BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define INJSYSMGRCRK_START_SEC_CALIB_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJSYSMGRCRK_CALIB) InjSys_bInhETBHPst_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJSYSMGRCRK_CALIB) InjSys_bInhTFuelCondForHPStrt_C;

#define INJSYSMGRCRK_STOP_SEC_CALIB_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJSYSMGRCRK_START_SEC_VAR_16BIT
#include "InjSysMgrCrk_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, INJSYSMGRCRK_VAR) InjSys_pFuThdAcvInjHPst;

#define INJSYSMGRCRK_STOP_SEC_VAR_16BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define INJSYSMGRCRK_START_SEC_VAR_8BIT
#include "InjSysMgrCrk_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern VAR(UInt8, INJSYSMGRCRK_VAR) InjSys_ctTDCThdAcvInjHPst;

#define INJSYSMGRCRK_STOP_SEC_VAR_8BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJSYSMGRCRK_START_SEC_VAR_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvHPst;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModH;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModSplst;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModSst;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bDetPFuThdInjHPst;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bInhInjHPst;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_prm_bInhInjHPstCyl[6];

#define INJSYSMGRCRK_STOP_SEC_VAR_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S20>/BKPT1' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S20>/TABLE' : Unused code path elimination
 * Block '<S18>/InjSys_tFuHPSt_A' : Unused code path elimination
 * Block '<S21>/BKPT1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S21>/TABLE' : Unused code path elimination
 * Block '<S19>/InjSys_tFuHPSt_A' : Unused code path elimination
 * Block '<S24>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S24>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S24>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S24>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S26>/BKPT1' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S26>/TABLE' : Unused code path elimination
 * Block '<S27>/BKPT1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S27>/TABLE' : Unused code path elimination
 * Block '<S28>/BKPT1' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S28>/TABLE' : Unused code path elimination
 * Block '<S29>/BKPT1' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S29>/TABLE' : Unused code path elimination
 * Block '<S25>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S25>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S25>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S25>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S25>/Ext_tCoMes_A_4' : Unused code path elimination
 * Block '<S30>/BKPT1' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S30>/TABLE' : Unused code path elimination
 * Block '<S31>/BKPT1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S31>/TABLE' : Unused code path elimination
 * Block '<S32>/BKPT1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S32>/TABLE' : Unused code path elimination
 * Block '<S33>/BKPT1' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S33>/TABLE' : Unused code path elimination
 * Block '<S34>/BKPT1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S34>/TABLE' : Unused code path elimination
 * Block '<S42>/BKPT1' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S42>/TABLE' : Unused code path elimination
 * Block '<S40>/InjSys_tFuHPSt_A' : Unused code path elimination
 * Block '<S43>/BKPT1' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S43>/TABLE' : Unused code path elimination
 * Block '<S41>/InjSys_tFuHPSt_A' : Unused code path elimination
 * Block '<S46>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S46>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S46>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S46>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S48>/BKPT1' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S48>/TABLE' : Unused code path elimination
 * Block '<S49>/BKPT1' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S49>/TABLE' : Unused code path elimination
 * Block '<S50>/BKPT1' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S50>/TABLE' : Unused code path elimination
 * Block '<S51>/BKPT1' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S51>/TABLE' : Unused code path elimination
 * Block '<S47>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S47>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S47>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S47>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S47>/Ext_tCoMes_A_4' : Unused code path elimination
 * Block '<S52>/BKPT1' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S52>/TABLE' : Unused code path elimination
 * Block '<S53>/BKPT1' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S53>/TABLE' : Unused code path elimination
 * Block '<S54>/BKPT1' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S54>/TABLE' : Unused code path elimination
 * Block '<S55>/BKPT1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S55>/TABLE' : Unused code path elimination
 * Block '<S56>/BKPT1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S56>/TABLE' : Unused code path elimination
 * Block '<S70>/LO3' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S33>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S34>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S42>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S48>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S49>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S50>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S53>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Signal Conversion2' : Eliminate redundant signal conversion block
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
 * hilite_system('InjSysMgrCrk_AUTOCODE/InjSysMgrCrk')    - opens subsystem InjSysMgrCrk_AUTOCODE/InjSysMgrCrk
 * hilite_system('InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InjSysMgrCrk_AUTOCODE
 * '<S1>'   : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk
 * '<S7>'   : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP
 * '<S8>'   : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init
 * '<S9>'   : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP
 * '<S10>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F03_InhInjSyncNtAc
 * '<S11>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/demux_fc1
 * '<S12>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP
 * '<S13>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP
 * '<S14>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StrtHPCond
 * '<S15>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F02_StrtInjMod
 * '<S16>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd
 * '<S17>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F04_StrtHPInjIf
 * '<S18>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StrtHPCond/F01_StrtHPCondSTT
 * '<S19>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StrtHPCond/F02_StrtHPCond
 * '<S20>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StrtHPCond/F01_StrtHPCondSTT/InjSys_bAuthHPStSTT_T
 * '<S21>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StrtHPCond/F02_StrtHPCond/InjSys_bAuthHPSt_T
 * '<S22>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F02_StrtInjMod/F01_StrtInjModSTT
 * '<S23>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F02_StrtInjMod/F02_StrtInjModWoSTT
 * '<S24>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT
 * '<S25>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT
 * '<S26>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT/InjSys_ctTDCThdAcvInjHPstSTT_T
 * '<S27>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT/InjSys_pFuThdAcvInjModHSTT_T
 * '<S28>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT/InjSys_pFuThdAcvInjModSSTT_T
 * '<S29>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT/InjSys_pFuThdAcvInjModSplSTT_T
 * '<S30>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_ctTDCThdAcvInjHPRstrt_T
 * '<S31>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_ctTDCThdAcvInjHPst_T
 * '<S32>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_pFuThdAcvInjModH_T
 * '<S33>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_pFuThdAcvInjModS_T
 * '<S34>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_pFuThdAcvInjModSpl_T
 * '<S35>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP
 * '<S36>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F01_StrtHPCond
 * '<S37>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F02_StrtInjMod
 * '<S38>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd
 * '<S39>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F04_StrtHPInjIf
 * '<S40>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F01_StrtHPCond/F01_StrtHPCondSTT
 * '<S41>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F01_StrtHPCond/F02_StrtHPCond
 * '<S42>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F01_StrtHPCond/F01_StrtHPCondSTT/InjSys_bAuthHPStSTT_T
 * '<S43>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F01_StrtHPCond/F02_StrtHPCond/InjSys_bAuthHPSt_T
 * '<S44>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F02_StrtInjMod/F01_StrtInjModSTT
 * '<S45>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F02_StrtInjMod/F02_StrtInjModWoSTT
 * '<S46>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT
 * '<S47>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT
 * '<S48>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT/InjSys_ctTDCThdAcvInjHPstSTT_T
 * '<S49>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT/InjSys_pFuThdAcvInjModHSTT_T
 * '<S50>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT/InjSys_pFuThdAcvInjModSSTT_T
 * '<S51>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F01_pRailThdSTT/InjSys_pFuThdAcvInjModSplSTT_T
 * '<S52>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_ctTDCThdAcvInjHPRstrt_T
 * '<S53>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_ctTDCThdAcvInjHPst_T
 * '<S54>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_pFuThdAcvInjModH_T
 * '<S55>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_pFuThdAcvInjModS_T
 * '<S56>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F01_StallToRot_StrtHP_init/F01_StallToRot_StrtHP/F03_pRailThd/F02_pRailThdWoSTT/InjSys_pFuThdAcvInjModSpl_T
 * '<S57>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP
 * '<S58>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk
 * '<S59>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F02_Inj_StrtnotHPCrk
 * '<S60>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F01_StrtHPDisa
 * '<S61>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq
 * '<S62>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F03_InjModReq
 * '<S63>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F04_InhInjSync
 * '<S64>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F01_StrtHPDisa/F01_DecCnt
 * '<S65>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F01_StrtHPDisa/F02_NoDecCnt
 * '<S66>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/BasculeRS1
 * '<S67>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/PosHys2
 * '<S68>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/Rising_edge
 * '<S69>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/Rising_edge1
 * '<S70>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/PosHys2/BasculeRS
 * '<S71>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/PosHys2/BasculeRS/IniCdn
 * '<S72>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/PosHys2/BasculeRS/UnitDly_ExtIni
 * '<S73>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/PosHys2/BasculeRS/IniCdn/SubSystem
 * '<S74>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/PosHys2/BasculeRS/UnitDly_ExtIni/SubSystem
 * '<S75>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/PosHys2/BasculeRS/UnitDly_ExtIni/SubSystem1
 * '<S76>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/Rising_edge/SubSystem
 * '<S77>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F02_StrtHPReq/Rising_edge1/SubSystem
 * '<S78>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F04_InhInjSync/Falling_edge
 * '<S79>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F04_InhInjSync/One_Based_Assignment
 * '<S80>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F04_InhInjSync/One_Based_Assignment1
 * '<S81>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F02_Inj_StrtHP/F02_Inj_StrtHP/F01_Inj_StrtHPCrk/F04_InhInjSync/Falling_edge/SubSystem
 * '<S82>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F03_InhInjSyncNtAc/F03_InhInjSyncNtAc
 * '<S83>'  : InjSysMgrCrk_AUTOCODE/InjSysMgrCrk/F03_InhInjSyncNtAc/F03_InhInjSyncNtAc/One_Based_Assignment
 */

/*-
 * Requirements for '<Root>': InjSysMgrCrk
 */
#endif                                 /* RTW_HEADER_InjSysMgrCrk_h_ */

/*-------------------------------- end of file -------------------------------*/
