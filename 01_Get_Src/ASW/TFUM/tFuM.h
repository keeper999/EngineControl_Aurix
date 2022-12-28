/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tFuM                                                    */
/* !Description     : tFuM – Fuel temperature estimation                      */
/*                                                                            */
/* !Module          : tFuM                                                    */
/*                                                                            */
/* !File            : tFuM.h                                                  */
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
/*   Code generated on: Thu Jul 12 15:18:26 2012                              */
/*   Model name       : tFuM_AUTOCODE.mdl                                     */
/*   Model version    : 1.500                                                 */
/*   Root subsystem   : /tFuM                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/tFuM/5-SOFT-LIV/tFuM.h_v    $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_tFuM_h_
#define RTW_HEADER_tFuM_h_
#ifndef tFuM_COMMON_INCLUDES_
# define tFuM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "tFuM_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_SATURATE.h"
#endif                                 /* tFuM_COMMON_INCLUDES_ */

#include "tFuM_types.h"

/* Includes for objects with custom storage classes. */
#include "GDGAR.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define Ext_bTSen_tFuRail_SC           0
#define Ext_bTSen_tFuUsPmp_SC          0

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
  UInt32 EepromReadAccess1;          /* '<S27>/EepromReadAccess1' */
  UInt32 VEMS_vidGET;                /* '<S27>/VEMS_vidGET' */
  UInt32 VEMS_vidGET_d;              /* '<S124>/VEMS_vidGET' */
  SInt16 EepromReadAccess;            /* '<S27>/EepromReadAccess' */
  SInt16 VEMS_vidGET1;                /* '<S27>/VEMS_vidGET1' */
  SInt16 VEMS_vidGET2;                /* '<S27>/VEMS_vidGET2' */
  SInt16 VEMS_vidGET3;                /* '<S27>/VEMS_vidGET3' */
  SInt16 VEMS_vidGET6;                /* '<S35>/VEMS_vidGET6' */
  SInt16 VEMS_vidGET5;                /* '<S35>/VEMS_vidGET5' */
  SInt16 VEMS_vidGET7;                /* '<S35>/VEMS_vidGET7' */
  SInt16 VEMS_vidGET8;                /* '<S35>/VEMS_vidGET8' */
  SInt16 VEMS_vidGET3_h;              /* '<S12>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET2_l;             /* '<S35>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET9;               /* '<S35>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET_i;              /* '<S10>/VEMS_vidGET' */
  SInt16 VEMS_vidGET1_g;              /* '<S12>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET3_j;             /* '<S35>/VEMS_vidGET3' */
  UInt16 EepromReadAccess2;          /* '<S27>/EepromReadAccess2' */
  UInt16 OutDTConv;                  /* '<S33>/OutDTConv' */
  UInt16 VEMS_vidGET1_a;             /* '<S124>/VEMS_vidGET1' */
  UInt16 OutDTConv_b;                /* '<S38>/OutDTConv' */
  UInt8 VEMS_vidGET4;                /* '<S35>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET1_j;              /* '<S35>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET2_k;              /* '<S12>/VEMS_vidGET2' */
  Boolean VEMS_vidGET10;             /* '<S35>/VEMS_vidGET10' */
  UInt8 VEMS_vidGET_l;               /* '<S35>/VEMS_vidGET' */
  UInt8 VEMS_vidGET_la;              /* '<S12>/VEMS_vidGET' */
  UInt8 EepromReadAccess3;           /* '<S27>/EepromReadAccess3' */
  UInt8 OutDTConv_d;                 /* '<S32>/OutDTConv' */
  UInt8 VEMS_vidGET2_e;              /* '<S124>/VEMS_vidGET2' */
  UInt8 OutDTConv_c;                 /* '<S39>/OutDTConv' */
} BlockIO_tFuM;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S85>/Unit Delay' */
  Float32 UnitDelay_DSTATE_d;         /* '<S94>/Unit Delay' */
  Float32 UnitDelay_DSTATE_h;         /* '<S103>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S54>/UnitDelay' */
  Boolean UnitDelay_m;               /* '<S55>/UnitDelay' */
  Boolean UnitDelay_DSTATE_e;        /* '<S81>/Unit Delay' */
  Boolean UnitDelay_DSTATE_n;        /* '<S84>/Unit Delay' */
  Boolean UnitDelay_DSTATE_dp;       /* '<S90>/Unit Delay' */
  Boolean UnitDelay_DSTATE_d5;       /* '<S93>/Unit Delay' */
  Boolean UnitDelay_DSTATE_f;        /* '<S99>/Unit Delay' */
  Boolean UnitDelay_DSTATE_p;        /* '<S102>/Unit Delay' */
} D_Work_tFuM;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define TFUM_START_SEC_VAR_UNSPECIFIED
#include "tFuM_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_tFuM tFuM_B;

/* Block states (auto storage) */
extern D_Work_tFuM tFuM_DWork;

#define TFUM_STOP_SEC_VAR_UNSPECIFIED
#include "tFuM_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define TFUM_START_SEC_CODE
#include "tFuM_MemMap.h"

/* Model entry point functions */
extern void tFuM_initialize(void);
extern void FuSysM_EveRxn552_tFuM(void);
extern void FuSysM_EvePwrl_tFuM(void);
extern void FuSysM_SdlSlow_tFuM(void);
extern void FuSysM_EveRst_tFuM(void);

#define TFUM_STOP_SEC_CODE
#include "tFuM_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define TFUM_START_SEC_CALIB_32BIT
#include "tFuM_MemMap.h"

/* Type:    UInt32                                                          */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 864000.0                                                          */
extern CONST(UInt32, TFUM_CALIB) FuSysM_tiEngStop_A[9];

#define TFUM_STOP_SEC_CALIB_32BIT
#include "tFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define TFUM_START_SEC_CALIB_16BIT
#include "tFuM_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgAirStalltFuUsPmp_T[9];

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgAirStalltFu_T[9];

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgUndHo_M[81];

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgWatFuUsPmp_C;

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgWatFu_C;

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgmfFu_M[81];

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgtEngtFuUsPmp_M[81];

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgtEngtFu_M[81];

/* Type:    UInt16                                                          */
/* Slope:   1.5258789062500000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.9998474121093750E-001                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_facExgtExttFuUsPmp_M[81];

/* Type:    UInt16                                                          */
/* Slope:   3.90625E-007                                                      */
/* Bias:    0.0                                                               */
/* Units:   kg/s                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.5599609374999999E-002                                           */
extern CONST(UInt16, TFUM_CALIB) FuSysM_mfFuEstim_A[9];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, TFUM_CALIB) FuSysM_pFuRail_A[9];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, TFUM_CALIB) FuSysM_rGainFilUndHo_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, TFUM_CALIB) FuSysM_tiFilBastFuUsPmp_M[81];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, TFUM_CALIB) FuSysM_tiFilExgtFuUsPmp_M[81];

#define TFUM_STOP_SEC_CALIB_16BIT
#include "tFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define TFUM_START_SEC_CALIB_8BIT
#include "tFuM_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFuExgWa_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFuUsPmpEng_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFuUsPmpExt_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFuUsPmp_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, TFUM_CALIB) FuSysM_facCormfFutFu_T[9];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    -0.9921875                                                        */
/* Units:   -                                                                 */
/* PhysMin: -0.9921875                                                        */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, TFUM_CALIB) FuSysM_rCorTFuIni_M[81];

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    -0.9921875                                                        */
/* Units:   -                                                                 */
/* PhysMin: -0.9921875                                                        */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, TFUM_CALIB) FuSysM_rCorTFuUsPmpIni_M[81];

/* Type:    UInt8                                                           */
/* Slope:   2.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 126.0                                                             */
extern CONST(UInt8, TFUM_CALIB) FuSysM_rSpdFanReq_A[9];

/* Type:    UInt8                                                           */
/* Units:   km/h                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, TFUM_CALIB) FuSysM_spdVeh_A[9];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -50.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 200.0                                                             */
extern CONST(UInt8, TFUM_CALIB) FuSysM_tAirExtMes_A[9];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, TFUM_CALIB) FuSysM_tCoMes_A[9];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern CONST(UInt8, TFUM_CALIB) FuSysM_tFuETB_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern CONST(UInt8, TFUM_CALIB) FuSysM_tFuUsPmpETB_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern CONST(UInt8, TFUM_CALIB) FuSysM_tFuUsPmpWaPmpOff_M[81];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern CONST(UInt8, TFUM_CALIB) FuSysM_tFuUsPmpWaPmpOn_M[81];

#define TFUM_STOP_SEC_CALIB_8BIT
#include "tFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define TFUM_START_SEC_CALIB_BOOLEAN
#include "tFuM_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, TFUM_CALIB) FuSysM_bAcvTFuETB_C;

#define TFUM_STOP_SEC_CALIB_BOOLEAN
#include "tFuM_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define TFUM_START_SEC_VAR_16BIT
#include "tFuM_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern VAR(UInt16, TFUM_VAR) FuSysM_tFu;

#define TFUM_STOP_SEC_VAR_16BIT
#include "tFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define TFUM_START_SEC_VAR_8BIT
#include "tFuM_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern VAR(UInt8, TFUM_VAR) FuSysM_tFuUsPmp;

#define TFUM_STOP_SEC_VAR_8BIT
#include "tFuM_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S16>/x' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S17>/x' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S30>/x' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S31>/x' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S45>/x' : Unused code path elimination
 * Block '<S78>/Data Type Propagation' : Unused code path elimination
 * Block '<S78>/Data Type Propagation1' : Unused code path elimination
 * Block '<S82>/Data Type Propagation' : Unused code path elimination
 * Block '<S82>/Data Type Conversion' : Unused code path elimination
 * Block '<S82>/Data Type Conversion1' : Unused code path elimination
 * Block '<S79>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S87>/Data Type Propagation' : Unused code path elimination
 * Block '<S87>/Data Type Propagation1' : Unused code path elimination
 * Block '<S91>/Data Type Propagation' : Unused code path elimination
 * Block '<S91>/Data Type Conversion' : Unused code path elimination
 * Block '<S91>/Data Type Conversion1' : Unused code path elimination
 * Block '<S88>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S96>/Data Type Propagation' : Unused code path elimination
 * Block '<S96>/Data Type Propagation1' : Unused code path elimination
 * Block '<S100>/Data Type Propagation' : Unused code path elimination
 * Block '<S100>/Data Type Conversion' : Unused code path elimination
 * Block '<S100>/Data Type Conversion1' : Unused code path elimination
 * Block '<S97>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S64>/x' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S65>/x' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S115>/x' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S43>/x' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S44>/x' : Unused code path elimination
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Switch' : Eliminated due to constant selection input
 * Block '<S32>/Switch' : Eliminated due to constant selection input
 * Block '<S33>/Switch' : Eliminated due to constant selection input
 * Block '<S46>/Switch' : Eliminated due to constant selection input
 * Block '<S78>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S78>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S78>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S87>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S87>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S87>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S70>/Switch' : Eliminated due to constant selection input
 * Block '<S71>/Switch' : Eliminated due to constant selection input
 * Block '<S38>/Switch' : Eliminated due to constant selection input
 * Block '<S39>/Switch' : Eliminated due to constant selection input
 * Block '<S13>/Constant' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Unused code path elimination
 * Block '<S32>/Add3' : Unused code path elimination
 * Block '<S32>/Add4' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S32>/Relational Operator' : Unused code path elimination
 * Block '<S32>/Switch1' : Unused code path elimination
 * Block '<S32>/offset2' : Unused code path elimination
 * Block '<S32>/offset3' : Unused code path elimination
 * Block '<S32>/offset4' : Unused code path elimination
 * Block '<S33>/Add3' : Unused code path elimination
 * Block '<S33>/Add4' : Unused code path elimination
 * Block '<S33>/Constant' : Unused code path elimination
 * Block '<S33>/Relational Operator' : Unused code path elimination
 * Block '<S33>/Switch1' : Unused code path elimination
 * Block '<S33>/offset2' : Unused code path elimination
 * Block '<S33>/offset3' : Unused code path elimination
 * Block '<S33>/offset4' : Unused code path elimination
 * Block '<S46>/Add3' : Unused code path elimination
 * Block '<S46>/Add4' : Unused code path elimination
 * Block '<S46>/Constant' : Unused code path elimination
 * Block '<S46>/Relational Operator' : Unused code path elimination
 * Block '<S46>/Switch1' : Unused code path elimination
 * Block '<S46>/offset2' : Unused code path elimination
 * Block '<S46>/offset3' : Unused code path elimination
 * Block '<S46>/offset4' : Unused code path elimination
 * Block '<S70>/Add3' : Unused code path elimination
 * Block '<S70>/Add4' : Unused code path elimination
 * Block '<S70>/Constant' : Unused code path elimination
 * Block '<S70>/Relational Operator' : Unused code path elimination
 * Block '<S70>/Switch1' : Unused code path elimination
 * Block '<S70>/offset2' : Unused code path elimination
 * Block '<S70>/offset3' : Unused code path elimination
 * Block '<S70>/offset4' : Unused code path elimination
 * Block '<S71>/Add3' : Unused code path elimination
 * Block '<S71>/Add4' : Unused code path elimination
 * Block '<S71>/Constant' : Unused code path elimination
 * Block '<S71>/Relational Operator' : Unused code path elimination
 * Block '<S71>/Switch1' : Unused code path elimination
 * Block '<S71>/offset2' : Unused code path elimination
 * Block '<S71>/offset3' : Unused code path elimination
 * Block '<S71>/offset4' : Unused code path elimination
 * Block '<S38>/Add3' : Unused code path elimination
 * Block '<S38>/Add4' : Unused code path elimination
 * Block '<S38>/Constant' : Unused code path elimination
 * Block '<S38>/Relational Operator' : Unused code path elimination
 * Block '<S38>/Switch1' : Unused code path elimination
 * Block '<S38>/offset2' : Unused code path elimination
 * Block '<S38>/offset3' : Unused code path elimination
 * Block '<S38>/offset4' : Unused code path elimination
 * Block '<S39>/Add3' : Unused code path elimination
 * Block '<S39>/Add4' : Unused code path elimination
 * Block '<S39>/Constant' : Unused code path elimination
 * Block '<S39>/Relational Operator' : Unused code path elimination
 * Block '<S39>/Switch1' : Unused code path elimination
 * Block '<S39>/offset2' : Unused code path elimination
 * Block '<S39>/offset3' : Unused code path elimination
 * Block '<S39>/offset4' : Unused code path elimination
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
 * hilite_system('tFuM_AUTOCODE/tFuM')    - opens subsystem tFuM_AUTOCODE/tFuM
 * hilite_system('tFuM_AUTOCODE/tFuM/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : tFuM_AUTOCODE
 * '<S5>'   : tFuM_AUTOCODE/tFuM
 * '<S6>'   : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp
 * '<S7>'   : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp
 * '<S8>'   : tFuM_AUTOCODE/tFuM/tFuM_fc_demux_1
 * '<S9>'   : tFuM_AUTOCODE/tFuM/tFuM_fc_demux_2
 * '<S10>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F01_Ini_tEng
 * '<S11>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng
 * '<S12>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng
 * '<S13>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/Filtre_1er_ordre1
 * '<S14>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/FuSysM_facExgUndHo_M
 * '<S15>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/FuSysM_rGainFilUndHo_M
 * '<S16>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/FuSysM_rSpdFanReq_A_PreLookUp
 * '<S17>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/FuSysM_spdVeh_A_PreLookUp
 * '<S18>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/multiplication_411
 * '<S19>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/Filtre_1er_ordre1/Filtre_1er_ordre  avec reset
 * '<S20>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/Filtre_1er_ordre1/Filtre_1er_ordre  avec reset/Reset du filtre
 * '<S21>'  : tFuM_AUTOCODE/tFuM/F01_Calc_eng_temp/F02_Calc_tEng/F02_Calc_tEng/Filtre_1er_ordre1/Filtre_1er_ordre  avec reset/filtrage
 * '<S22>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F00_Ini_acvTFu
 * '<S23>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp
 * '<S24>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp
 * '<S25>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F03_save_fuel_temp_EEPROM
 * '<S26>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/Function_Call_Generator_with_condition1
 * '<S27>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp/F01_Init_fuel_temp
 * '<S28>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp/F01_Init_fuel_temp/FuSysM_rCorTFuIni_M
 * '<S29>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp/F01_Init_fuel_temp/FuSysM_rCorTFuUsPmpIni_M
 * '<S30>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp/F01_Init_fuel_temp/FuSysM_tCoMes_A_PreLookUp
 * '<S31>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp/F01_Init_fuel_temp/FuSysM_tiEngStop_A_PreLookUp
 * '<S32>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp/F01_Init_fuel_temp/SingleToFixdt
 * '<S33>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp/F01_Init_fuel_temp/SingleToFixdt1
 * '<S34>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F01_Init_fuel_temp/F01_Init_fuel_temp/multiplication_421
 * '<S35>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp
 * '<S36>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F01_ClcntFuTest
 * '<S37>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest
 * '<S38>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/SingleToFixdt
 * '<S39>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/SingleToFixdt1
 * '<S40>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F01_Fuel_flow_Calc
 * '<S41>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp
 * '<S42>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu
 * '<S43>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/FuSysM_rSpdFanReq_A_PreLookUp
 * '<S44>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/FuSysM_spdVeh_A_PreLookUp
 * '<S45>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F01_Fuel_flow_Calc/FuSysM_mfFuEstim_A_PreLookUp
 * '<S46>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F01_Fuel_flow_Calc/SingleToFixdt
 * '<S47>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F01_Fuel_flow_Calc/division_431
 * '<S48>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F01_Fuel_flow_Calc/multiplication_441
 * '<S49>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F01_Fuel_flow_Calc/multiplication_451
 * '<S50>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F01_tFuUsPmp_Mes
 * '<S51>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc
 * '<S52>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running
 * '<S53>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F02_tFuUsPmp_not_Running
 * '<S54>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/rising_edge
 * '<S55>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/rising_edge1
 * '<S56>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T
 * '<S57>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1
 * '<S58>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2
 * '<S59>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_facCormfFutFuUsPmpEng_T
 * '<S60>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_facCormfFutFuUsPmpExt_T
 * '<S61>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_facCormfFutFuUsPmp_T
 * '<S62>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_facExgtEngtFuUsPmp_M
 * '<S63>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_facExgtExttFuUsPmp_M
 * '<S64>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_tAirExtMes_A_PreLookUp
 * '<S65>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_tCoMes_A_PreLookUp
 * '<S66>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_tFuUsPmpWaPmpOff_M
 * '<S67>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_tFuUsPmpWaPmpOn_M
 * '<S68>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_tiFilBastFuUsPmp_M
 * '<S69>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/FuSysM_tiFilExgtFuUsPmp_M
 * '<S70>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/SingleToFixdt
 * '<S71>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/SingleToFixdt1
 * '<S72>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/multiplication_1
 * '<S73>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/multiplication_461
 * '<S74>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/multiplication_471
 * '<S75>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/multiplication_481
 * '<S76>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/multiplication_491
 * '<S77>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/IniCdn
 * '<S78>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/Subsystem1
 * '<S79>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/UnitDly_ExtIni
 * '<S80>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/multiplication_451
 * '<S81>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/IniCdn/SubSystem
 * '<S82>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/Subsystem1/Data Type Police Only single
 * '<S83>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/Subsystem1/If Action Subsystem3
 * '<S84>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/UnitDly_ExtIni/SubSystem1
 * '<S85>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T/UnitDly_ExtIni/SubSystem2
 * '<S86>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/IniCdn
 * '<S87>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/Subsystem1
 * '<S88>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/UnitDly_ExtIni
 * '<S89>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/multiplication_451
 * '<S90>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/IniCdn/SubSystem
 * '<S91>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/Subsystem1/Data Type Police Only single
 * '<S92>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/Subsystem1/If Action Subsystem3
 * '<S93>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/UnitDly_ExtIni/SubSystem1
 * '<S94>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T1/UnitDly_ExtIni/SubSystem2
 * '<S95>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/IniCdn
 * '<S96>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/Subsystem1
 * '<S97>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/UnitDly_ExtIni
 * '<S98>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/multiplication_451
 * '<S99>'  : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/IniCdn/SubSystem
 * '<S100>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/Subsystem1/Data Type Police Only single
 * '<S101>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/Subsystem1/If Action Subsystem3
 * '<S102>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/UnitDly_ExtIni/SubSystem1
 * '<S103>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F01_tFuUsPmp_Running/1er_ordre Filtre avec reset_Type T2/UnitDly_ExtIni/SubSystem2
 * '<S104>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F02_tFuUsPmp_not_Running/FuSysM_facExgAirStalltFuUsPmp_T
 * '<S105>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F02_tFuUsPmp_not_Running/multiplication_4101
 * '<S106>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F02_tFuUsPmp/F02_tFuUsPmp_Calc/F02_tFuUsPmp_not_Running/multiplication_4111
 * '<S107>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F01_tFu_Mes
 * '<S108>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc
 * '<S109>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running
 * '<S110>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F02_tFu_not_Running
 * '<S111>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/FuSysM_facCormfFutFuExgWa_T
 * '<S112>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/FuSysM_facCormfFutFu_T
 * '<S113>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/FuSysM_facExgmfFu_M
 * '<S114>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/FuSysM_facExgtEngtFu_M
 * '<S115>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/FuSysM_pFuRail_A_PreLookUp
 * '<S116>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/multiplication_1
 * '<S117>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/multiplication_4121
 * '<S118>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/multiplication_4131
 * '<S119>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/multiplication_4141
 * '<S120>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F01_tFu_Running/multiplication_4151
 * '<S121>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F02_tFu_not_Running/FuSysM_facExgAirStalltFu_T
 * '<S122>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F02_tFu_not_Running/multiplication_4161
 * '<S123>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_Sdl_Calc_fuel_temp/F02_ClcntFuNoTest/F03_tFu/F02_tFu_Calc/F02_tFu_not_Running/multiplication_4171
 * '<S124>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/F03_save_fuel_temp_EEPROM/F03_save_fuel_temp_EEPROM
 * '<S125>' : tFuM_AUTOCODE/tFuM/F02_Calc_fuel_temp/Function_Call_Generator_with_condition1/Chart
 */

/*-
 * Requirements for '<Root>': tFuM
 */
#endif                                 /* RTW_HEADER_tFuM_h_ */

/*-------------------------------- end of file -------------------------------*/
