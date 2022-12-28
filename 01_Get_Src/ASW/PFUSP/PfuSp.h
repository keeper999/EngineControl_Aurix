/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pFuSp                                                   */
/* !Description     : pFuSp : Fuel Pressure Set Point                         */
/*                                                                            */
/* !Module          : pFuSp                                                   */
/*                                                                            */
/* !File            : pFuSp.h                                                 */
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
/*   Code generated on: Thu Dec 20 19:22:07 2012                              */
/*   Model name       : pFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.341                                                 */
/*   Root subsystem   : /pFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PFUSP/pFuSp.h_v           $*/
/* $Revision::   1.11                                                        $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_pFuSp_h_
#define RTW_HEADER_pFuSp_h_
#ifndef pFuSp_COMMON_INCLUDES_
# define pFuSp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "pFuSp_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MAXf.h"
#endif                                 /* pFuSp_COMMON_INCLUDES_ */

#include "pFuSp_types.h"

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

/* Block signals (auto storage) */
typedef struct {
  Float32 INIT_OUTPUT;                /* '<S15>/INIT_OUTPUT' */
  Float32 Sum1;                       /* '<S14>/Sum1' */
  SInt16 VEMS_vidGET4;                /* '<S6>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET;                /* '<S6>/VEMS_vidGET' */
  UInt16 VEMS_vidGET15;              /* '<S6>/VEMS_vidGET15' */
  UInt16 VEMS_vidGET1;               /* '<S6>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET16;              /* '<S6>/VEMS_vidGET16' */
  UInt16 VEMS_vidGET3;               /* '<S6>/VEMS_vidGET3' */
  UInt16 Merge;                      /* '<S6>/Merge' */
  UInt16 VEMS_vidGET14;              /* '<S6>/VEMS_vidGET14' */
  SInt16 VEMS_vidGET18;               /* '<S6>/VEMS_vidGET18' */
  UInt16 VEMS_vidGET2;               /* '<S6>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET10;               /* '<S6>/VEMS_vidGET10' */
  UInt8 VEMS_vidGET12;               /* '<S6>/VEMS_vidGET12' */
  UInt8 VEMS_vidGET11;               /* '<S6>/VEMS_vidGET11' */
  UInt8 VEMS_vidGET13;               /* '<S6>/VEMS_vidGET13' */
  Boolean VEMS_vidGET17;             /* '<S6>/VEMS_vidGET17' */
  Boolean VEMS_vidGET6;              /* '<S6>/VEMS_vidGET6' */
  Boolean LogicalOperator3;          /* '<S89>/Logical Operator3' */
  Boolean LogicalOperator6;          /* '<S89>/Logical Operator6' */
  Boolean LogicalOperator1;          /* '<S88>/Logical Operator1' */
  Boolean Switch5;                   /* '<S87>/Switch5' */
  Boolean LogicalOperator1_f;        /* '<S87>/Logical Operator1' */
  Boolean Switch;                    /* '<S87>/Switch' */
  Boolean Merge_p;                   /* '<S91>/Merge' */
  UInt8 VEMS_vidGET5;                /* '<S6>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET7;                /* '<S6>/VEMS_vidGET7' */
  UInt8 VEMS_vidGET8;                /* '<S6>/VEMS_vidGET8' */
  UInt8 VEMS_vidGET9;                /* '<S6>/VEMS_vidGET9' */
} BlockIO_pFuSp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S101>/Unit Delay' */
  Float32 UnitDelay_DSTATE_e;         /* '<S115>/Unit Delay' */
  Float32 UnitDelay_DSTATE_h;         /* '<S122>/Unit Delay' */
  Float32 Y;                          /* '<S12>/Data Store Memory' */
  UInt16 UnitDelay_DSTATE_a;         /* '<S111>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_m;          /* '<S12>/Unit Delay' */
  Boolean UnitDelay_DSTATE_g;        /* '<S102>/Unit Delay' */
  Boolean UnitDelay_DSTATE_j;        /* '<S109>/Unit Delay' */
  Boolean UnitDelay_DSTATE_ae;       /* '<S110>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S97>/UnitDelay' */
  Boolean UnitDelay_h;               /* '<S97>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_b;        /* '<S114>/Unit Delay' */
  Boolean UnitDelay_j;               /* '<S123>/UnitDelay' */
  Boolean UnitDelay_k;               /* '<S124>/UnitDelay' */
  Boolean Memory_PreviousInput;      /* '<S100>/Memory' */
  Boolean Memory_PreviousInput_e;    /* '<S121>/Memory' */
} D_Work_pFuSp;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S100>/Logic'
   *   '<S121>/Logic'
   */
  Boolean pooled11[16];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S97>/Logic'
   */
  Boolean Logic_table[16];
} ConstParam_pFuSp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define PFUSP_START_SEC_VAR_UNSPECIFIED
#include "pFuSp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_pFuSp pFuSp_B;

/* Block states (auto storage) */
extern D_Work_pFuSp pFuSp_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_pFuSp pFuSp_ConstP;

#define PFUSP_STOP_SEC_VAR_UNSPECIFIED
#include "pFuSp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define PFUSP_START_SEC_CODE
#include "pFuSp_MemMap.h"

/* Model entry point functions */
extern void pFuSp_initialize(void);
extern void InjSys_EveSpl_pFuSp(void);
extern void InjSys_EveRst_pFuSp(void);

#define PFUSP_STOP_SEC_CODE
#include "pFuSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define PFUSP_START_SEC_CALIB_16BIT
#include "pFuSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   1.9454956054687500E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.2749805450439450E+001                                           */
extern CONST(UInt16, PFUSP_CALIB) InjSys_facPresDifMaxInj_T[8];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, PFUSP_CALIB) InjSys_nMaxGrdLdSat_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuDifMaxRailDcha_C;

/* Type:    UInt16                                                          */
/* Slope:   10000.0                                                           */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0E+007                                                          */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuMinRailDcha_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal10_M[64];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal11_M[64];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal12_M[64];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal13_M[64];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal14_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal15_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal1_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal2_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal3_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal4_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal5_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal6_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal7_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal8_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal9_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpETBSlewRate_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpETB_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpETB_M[256];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pPresDifLowHys_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pPresDifMaxInj_A[10];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PFUSP_CALIB) InjSys_pPresDifMaxInj_T[10];

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   N.m                                                               */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(SInt16, PFUSP_CALIB) InjSys_tqMaxNegGrdDcha_C;

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   N.m                                                               */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(SInt16, PFUSP_CALIB) InjSys_tqMaxPosGrdDcha_C;

#define PFUSP_STOP_SEC_CALIB_16BIT
#include "pFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define PFUSP_START_SEC_CALIB_8BIT
#include "pFuSp_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern CONST(UInt8, PFUSP_CALIB) InjSys_idxModPfuSatMax_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern CONST(UInt8, PFUSP_CALIB) InjSys_idxModPfuSatMin_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, PFUSP_CALIB) InjSys_idxTiPerSplEve_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, PFUSP_CALIB) InjSys_noETBSelpFuSp_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, PFUSP_CALIB) InjSys_stManAirLdMinSat_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, PFUSP_CALIB) InjSys_stManInhInjCutOff_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, PFUSP_CALIB) InjSys_stManSpcInjMod_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, PFUSP_CALIB) InjSys_tCo_facPresDifMaxInj_A[8];

/* Type:    UInt8                                                           */
/* Slope:   0.5                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 125.0                                                             */
extern CONST(UInt8, PFUSP_CALIB) InjSys_tiDlyAcvSpcInjMod_C;

/* Type:    UInt8                                                           */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 12.0                                                              */
extern CONST(UInt8, PFUSP_CALIB) InjSys_tiPmpCutOffTqLimEM_C;

#define PFUSP_STOP_SEC_CALIB_8BIT
#include "pFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define PFUSP_START_SEC_CALIB_BOOLEAN
#include "pFuSp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bAcvAirLdMinSatDcha_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bAcvAirLdMinSat_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bAcvETBpFuSp_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bAcvMonMisfSpcInjMod_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bAcvPmpCutTqLimEM_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bAcvSpcInjMod_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bAuthAirLdMinSat_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bInhDifFuRailDCha_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PFUSP_CALIB) InjSys_bInhInjCutOff_C;

#define PFUSP_STOP_SEC_CALIB_BOOLEAN
#include "pFuSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define PFUSP_START_SEC_VAR_16BIT
#include "pFuSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSp;

#define PFUSP_STOP_SEC_VAR_16BIT
#include "pFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define PFUSP_START_SEC_VAR_BOOLEAN
#include "pFuSp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvAirLdMinSat;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvCllRailDcha;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvSpcInjMod;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, PFUSP_VAR) InjSys_bCanPurgCutOff;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, PFUSP_VAR) InjSys_bHPPmpCutOff;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, PFUSP_VAR) InjSys_bInhInjCutOffPFuDcha;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, PFUSP_VAR) InjSys_bInjSpNotAccu;

#define PFUSP_STOP_SEC_VAR_BOOLEAN
#include "pFuSp_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Ext_nEngX_A' : Unused code path elimination
 * Block '<S7>/Ext_pDsThrMesSIY_A' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S10>/TABLE' : Unused code path elimination
 * Block '<S10>/TABLE1' : Unused code path elimination
 * Block '<S10>/TABLE2' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Relational Operator' : Unused code path elimination
 * Block '<S20>/Relational Operator1' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Relational Operator' : Unused code path elimination
 * Block '<S21>/Relational Operator1' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Relational Operator' : Unused code path elimination
 * Block '<S22>/Relational Operator1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Propagation' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Relational Operator' : Unused code path elimination
 * Block '<S23>/Relational Operator1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S37>/InjSys_mAirInjSpCal1Y_A' : Unused code path elimination
 * Block '<S37>/InjSys_nEngInjSpCal1X_A' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S53>/TABLE' : Unused code path elimination
 * Block '<S53>/TABLE1' : Unused code path elimination
 * Block '<S53>/TABLE2' : Unused code path elimination
 * Block '<S38>/InjSys_mAirInjSpCal2Y_A' : Unused code path elimination
 * Block '<S38>/InjSys_nEngInjSpCal2X_A' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S54>/TABLE' : Unused code path elimination
 * Block '<S54>/TABLE1' : Unused code path elimination
 * Block '<S54>/TABLE2' : Unused code path elimination
 * Block '<S39>/InjSys_mAirInjSpCal3Y_A' : Unused code path elimination
 * Block '<S39>/InjSys_nEngInjSpCal3X_A' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S55>/TABLE' : Unused code path elimination
 * Block '<S55>/TABLE1' : Unused code path elimination
 * Block '<S55>/TABLE2' : Unused code path elimination
 * Block '<S40>/InjSys_mAirInjSpCal4Y_A' : Unused code path elimination
 * Block '<S40>/InjSys_nEngInjSpCal4X_A' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S56>/TABLE' : Unused code path elimination
 * Block '<S56>/TABLE1' : Unused code path elimination
 * Block '<S56>/TABLE2' : Unused code path elimination
 * Block '<S41>/InjSys_mAirInjSpCal5Y_A' : Unused code path elimination
 * Block '<S41>/InjSys_nEngInjSpCal5X_A' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S57>/TABLE' : Unused code path elimination
 * Block '<S57>/TABLE1' : Unused code path elimination
 * Block '<S57>/TABLE2' : Unused code path elimination
 * Block '<S42>/InjSys_mAirInjSpCal6Y_A' : Unused code path elimination
 * Block '<S42>/InjSys_nEngInjSpCal6X_A' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S58>/TABLE' : Unused code path elimination
 * Block '<S58>/TABLE1' : Unused code path elimination
 * Block '<S58>/TABLE2' : Unused code path elimination
 * Block '<S43>/InjSys_mAirInjSpCal7Y_A' : Unused code path elimination
 * Block '<S43>/InjSys_nEngInjSpCal7X_A' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S59>/TABLE' : Unused code path elimination
 * Block '<S59>/TABLE1' : Unused code path elimination
 * Block '<S59>/TABLE2' : Unused code path elimination
 * Block '<S44>/InjSys_mAirInjSpCal8Y_A' : Unused code path elimination
 * Block '<S44>/InjSys_nEngInjSpCal8X_A' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S60>/TABLE' : Unused code path elimination
 * Block '<S60>/TABLE1' : Unused code path elimination
 * Block '<S60>/TABLE2' : Unused code path elimination
 * Block '<S45>/InjSys_mAirInjSpCal9Y_A' : Unused code path elimination
 * Block '<S45>/InjSys_nEngInjSpCal9X_A' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S61>/TABLE' : Unused code path elimination
 * Block '<S61>/TABLE1' : Unused code path elimination
 * Block '<S61>/TABLE2' : Unused code path elimination
 * Block '<S46>/InjSys_mAirInjSpCal10Y_A' : Unused code path elimination
 * Block '<S46>/InjSys_nEngInjSpCal10X_A' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S62>/TABLE' : Unused code path elimination
 * Block '<S62>/TABLE1' : Unused code path elimination
 * Block '<S62>/TABLE2' : Unused code path elimination
 * Block '<S47>/InjSys_mAirInjSpCal11Y_A' : Unused code path elimination
 * Block '<S47>/InjSys_nEngInjSpCal11X_A' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S63>/TABLE' : Unused code path elimination
 * Block '<S63>/TABLE1' : Unused code path elimination
 * Block '<S63>/TABLE2' : Unused code path elimination
 * Block '<S48>/InjSys_mAirInjSpCal12Y_A' : Unused code path elimination
 * Block '<S48>/InjSys_nEngInjSpCal12X_A' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S64>/TABLE' : Unused code path elimination
 * Block '<S64>/TABLE1' : Unused code path elimination
 * Block '<S64>/TABLE2' : Unused code path elimination
 * Block '<S49>/InjSys_mAirInjSpCal13Y_A' : Unused code path elimination
 * Block '<S49>/InjSys_nEngInjSpCal13X_A' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S65>/TABLE' : Unused code path elimination
 * Block '<S65>/TABLE1' : Unused code path elimination
 * Block '<S65>/TABLE2' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Relational Operator' : Unused code path elimination
 * Block '<S70>/Relational Operator1' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Propagation' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Relational Operator' : Unused code path elimination
 * Block '<S74>/Relational Operator1' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Propagation' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Relational Operator' : Unused code path elimination
 * Block '<S78>/Relational Operator1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Propagation' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S92>/x1' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S93>/x1' : Unused code path elimination
 * Block '<S97>/LO3' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Relational Operator' : Unused code path elimination
 * Block '<S99>/Relational Operator1' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Propagation' : Unused code path elimination
 * Block '<S112>/Data Type Propagation' : Unused code path elimination
 * Block '<S112>/Data Type Propagation1' : Unused code path elimination
 * Block '<S116>/Data Type Propagation' : Unused code path elimination
 * Block '<S116>/Data Type Conversion' : Unused code path elimination
 * Block '<S116>/Data Type Conversion1' : Unused code path elimination
 * Block '<S113>/Data Type Propagation' : Unused code path elimination
 * Block '<S113>/Data Type Propagation1' : Unused code path elimination
 * Block '<S118>/Data Type Propagation' : Unused code path elimination
 * Block '<S118>/Data Type Conversion' : Unused code path elimination
 * Block '<S118>/Data Type Conversion1' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Relational Operator' : Unused code path elimination
 * Block '<S120>/Relational Operator1' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Propagation' : Unused code path elimination
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S11>/Switch' : Eliminated due to constant selection input
 * Block '<S24>/Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Conversion' : Eliminate redundant data type conversion
 * Block '<S33>/Conversion' : Eliminate redundant data type conversion
 * Block '<S34>/Conversion' : Eliminate redundant data type conversion
 * Block '<S53>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S53>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S56>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S57>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S57>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S58>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S61>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S62>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S62>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S71>/Conversion' : Eliminate redundant data type conversion
 * Block '<S72>/Conversion' : Eliminate redundant data type conversion
 * Block '<S75>/Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Conversion' : Eliminate redundant data type conversion
 * Block '<S79>/Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Conversion' : Eliminate redundant data type conversion
 * Block '<S69>/Switch' : Eliminated due to constant selection input
 * Block '<S106>/Conversion' : Eliminate redundant data type conversion
 * Block '<S107>/Conversion' : Eliminate redundant data type conversion
 * Block '<S86>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S112>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S112>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S112>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S125>/Conversion' : Eliminate redundant data type conversion
 * Block '<S126>/Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S11>/Add3' : Unused code path elimination
 * Block '<S11>/Add4' : Unused code path elimination
 * Block '<S11>/Constant' : Unused code path elimination
 * Block '<S11>/Relational Operator' : Unused code path elimination
 * Block '<S11>/Switch1' : Unused code path elimination
 * Block '<S11>/offset2' : Unused code path elimination
 * Block '<S11>/offset3' : Unused code path elimination
 * Block '<S11>/offset4' : Unused code path elimination
 * Block '<S69>/Add3' : Unused code path elimination
 * Block '<S69>/Add4' : Unused code path elimination
 * Block '<S69>/Constant' : Unused code path elimination
 * Block '<S69>/Relational Operator' : Unused code path elimination
 * Block '<S69>/Switch1' : Unused code path elimination
 * Block '<S69>/offset2' : Unused code path elimination
 * Block '<S69>/offset3' : Unused code path elimination
 * Block '<S69>/offset4' : Unused code path elimination
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
 * hilite_system('pFuSp_AUTOCODE/pFuSp')    - opens subsystem pFuSp_AUTOCODE/pFuSp
 * hilite_system('pFuSp_AUTOCODE/pFuSp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : pFuSp_AUTOCODE
 * '<S3>'   : pFuSp_AUTOCODE/pFuSp
 * '<S4>'   : pFuSp_AUTOCODE/pFuSp/F01_Initialization
 * '<S5>'   : pFuSp_AUTOCODE/pFuSp/F02_pFuSp
 * '<S6>'   : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp
 * '<S7>'   : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F00_pFuSpETB
 * '<S8>'   : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn
 * '<S9>'   : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode
 * '<S10>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F00_pFuSpETB/InjSys_pFuSpETB_M
 * '<S11>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F00_pFuSpETB/SingleToFixdt
 * '<S12>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F00_pFuSpETB/Slew_rate
 * '<S13>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F00_pFuSpETB/multiplication
 * '<S14>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F00_pFuSpETB/Slew_rate/Slewing
 * '<S15>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F00_pFuSpETB/Slew_rate/initialisation_slewing
 * '<S16>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp
 * '<S17>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp
 * '<S18>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F04_Select_Modes_pFuSp
 * '<S19>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp
 * '<S20>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp
 * '<S21>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp1
 * '<S22>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp2
 * '<S23>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp3
 * '<S24>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp/Data Type Conversion Inherited
 * '<S25>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp/Data Type Conversion Inherited1
 * '<S26>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp/Saturation Dynamic
 * '<S27>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp1/Data Type Conversion Inherited
 * '<S28>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp1/Data Type Conversion Inherited1
 * '<S29>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp1/Saturation Dynamic
 * '<S30>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp2/Data Type Conversion Inherited
 * '<S31>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp2/Data Type Conversion Inherited1
 * '<S32>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp2/Saturation Dynamic
 * '<S33>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp3/Data Type Conversion Inherited
 * '<S34>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp3/Data Type Conversion Inherited1
 * '<S35>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F02_Mode_Mask_pFuSp/Clamp3/Saturation Dynamic
 * '<S36>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F01_Unvectorize_Activation_Boolean_pFuSp
 * '<S37>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F02_Calibration_1_pFuSp
 * '<S38>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F03_Calibration_2_pFuSp
 * '<S39>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F04_Calibration_3_pFuSp
 * '<S40>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F05_Calibration_4_pFuSp
 * '<S41>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F06_Calibration_5_pFuSp
 * '<S42>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F07_Calibration_6_pFuSp
 * '<S43>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F08_Calibration_7_pFuSp
 * '<S44>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F09_Calibration_8_pFuSp
 * '<S45>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F10_Calibration_9_pFuSp
 * '<S46>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F11_Calibration_10_pFuSp
 * '<S47>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F12_Calibration_11_pFuSp
 * '<S48>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F13_Calibration_12_pFuSp
 * '<S49>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F14_Calibration_13_pFuSp
 * '<S50>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F15_Calibration_14_pFuSp
 * '<S51>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F16_Calibration_15_pFuSp
 * '<S52>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F20_Vectorize_Calibrations_pFuSp
 * '<S53>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F02_Calibration_1_pFuSp/InjSys_pFuSpCal1_M
 * '<S54>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F03_Calibration_2_pFuSp/InjSys_pFuSpCal2_M
 * '<S55>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F04_Calibration_3_pFuSp/InjSys_pFuSpCal3_M
 * '<S56>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F05_Calibration_4_pFuSp/InjSys_pFuSpCal4_M
 * '<S57>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F06_Calibration_5_pFuSp/InjSys_pFuSpCal5_M
 * '<S58>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F07_Calibration_6_pFuSp/InjSys_pFuSpCal6_M
 * '<S59>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F08_Calibration_7_pFuSp/InjSys_pFuSpCal7_M
 * '<S60>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F09_Calibration_8_pFuSp/InjSys_pFuSpCal8_M
 * '<S61>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F10_Calibration_9_pFuSp/InjSys_pFuSpCal9_M
 * '<S62>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F11_Calibration_10_pFuSp/InjSys_pFuSpCal10_M
 * '<S63>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F12_Calibration_11_pFuSp/InjSys_pFuSpCal11_M
 * '<S64>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F13_Calibration_12_pFuSp/InjSys_pFuSpCal12_M
 * '<S65>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F03_Calibrations_pFuSp/F14_Calibration_13_pFuSp/InjSys_pFuSpCal13_M
 * '<S66>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS
 * '<S67>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS1
 * '<S68>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS2
 * '<S69>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/SingleToFixdt
 * '<S70>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS/Clamp
 * '<S71>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S72>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S73>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S74>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS1/Clamp
 * '<S75>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited
 * '<S76>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited1
 * '<S77>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS1/Clamp/Saturation Dynamic
 * '<S78>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS2/Clamp
 * '<S79>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS2/Clamp/Data Type Conversion Inherited
 * '<S80>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS2/Clamp/Data Type Conversion Inherited1
 * '<S81>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F01_pFuSpClcn/F05_Interpolation_pFuSp/BaryCentre_VEMS2/Clamp/Saturation Dynamic
 * '<S82>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F01_Synchronize_HP_Pump
 * '<S83>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F02_Monitor_pressure
 * '<S84>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring
 * '<S85>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F04_Monitor_Engine_Speed
 * '<S86>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F05_Choose_Strategy
 * '<S87>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F06_Activate_functionality
 * '<S88>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F07_Tq_Cll_Request
 * '<S89>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump
 * '<S90>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F01_Synchronize_HP_Pump/multiplication_411
 * '<S91>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F02_Monitor_pressure/Hysteresis
 * '<S92>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F02_Monitor_pressure/LookUp_1D
 * '<S93>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F02_Monitor_pressure/LookUp_1D1
 * '<S94>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F02_Monitor_pressure/multiplication_411
 * '<S95>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F02_Monitor_pressure/Hysteresis/If Action Subsystem
 * '<S96>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F02_Monitor_pressure/Hysteresis/If Action Subsystem1
 * '<S97>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_BasculeRS
 * '<S98>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay
 * '<S99>'  : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/Clamp
 * '<S100>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/S-R Flip-Flop
 * '<S101>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/SubSystem
 * '<S102>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/SubSystem1
 * '<S103>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/multiplication_1
 * '<S104>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/rising_edge
 * '<S105>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/rising_edge2
 * '<S106>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/Clamp/Data Type Conversion Inherited
 * '<S107>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/Clamp/Data Type Conversion Inherited1
 * '<S108>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/Clamp/Saturation Dynamic
 * '<S109>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/rising_edge/SubSystem
 * '<S110>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F03_Monitor_Misfiring/VEMS_TurnONDelay/rising_edge2/SubSystem
 * '<S111>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F04_Monitor_Engine_Speed/UnitDelay1
 * '<S112>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/Subsystem
 * '<S113>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/Subsystem1
 * '<S114>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay
 * '<S115>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_UnitDelay1
 * '<S116>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/Subsystem/Data Type Police Only single
 * '<S117>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/Subsystem/If Action Subsystem3
 * '<S118>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/Subsystem1/Data Type Police Only single
 * '<S119>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/Subsystem1/If Action Subsystem3
 * '<S120>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay/Clamp
 * '<S121>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay/S-R Flip-Flop
 * '<S122>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay/SubSystem
 * '<S123>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay/falling_edge
 * '<S124>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay/rising_edge2
 * '<S125>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay/Clamp/Data Type Conversion Inherited
 * '<S126>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay/Clamp/Data Type Conversion Inherited1
 * '<S127>' : pFuSp_AUTOCODE/pFuSp/F02_pFuSp/F02_pFuSp/F02_Activate_Specific_Mode/F08_Cut_off_HP_Pump/VEMS_TurnOFF_Delay/Clamp/Saturation Dynamic
 */

/*-
 * Requirements for '<Root>': pFuSp
 */
#endif                                 /* RTW_HEADER_pFuSp_h_ */

/*-------------------------------- end of file -------------------------------*/
