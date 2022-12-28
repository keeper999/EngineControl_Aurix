/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpMdl                                                */
/* !Description     : HPPmpMdl - Modèle de la pompe haute pression            */
/*                                                                            */
/* !Module          : HPPmpMdl                                                */
/*                                                                            */
/* !File            : HPPmpMdl.h                                              */
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
/*   Code generated on: Thu Apr 04 17:41:39 2013                              */
/*   Model name       : HPPmpMdl_AUTOCODE.mdl                                 */
/*   Model version    : 1.167                                                 */
/*   Root subsystem   : /HPPmpMdl                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPMDL/HPPmpMdl.h_v    $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   09 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPPmpMdl_h_
#define RTW_HEADER_HPPmpMdl_h_
#ifndef HPPmpMdl_COMMON_INCLUDES_
# define HPPmpMdl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "HPPmpMdl_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MAXf.h"
#endif                                 /* HPPmpMdl_COMMON_INCLUDES_ */

#include "HPPmpMdl_types.h"

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

/* Block signals for system '<S6>/F01_HPPmpMdl_RTSt_inhib' */
typedef struct {
  UInt32 Const1;                     /* '<S12>/Const1' */
  Boolean SignalConversion1;         /* '<S12>/Signal Conversion1' */
} rtB_F01_HPPmpMdl_RTSt_inhib_HPP;

/* Block signals (auto storage) */
typedef struct {
  UInt32 VEMS_vidGET12;              /* '<S16>/VEMS_vidGET12' */
  UInt32 OutDTConv;                  /* '<S61>/OutDTConv' */
  UInt32 Switch5;                    /* '<S19>/Switch5' */
  UInt16 VEMS_vidGET1;               /* '<S69>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET3;               /* '<S16>/VEMS_vidGET3' */
  SInt16 VEMS_vidGET;                 /* '<S69>/VEMS_vidGET' */
  SInt16 VEMS_vidGET2;                /* '<S16>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET4;               /* '<S16>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5;               /* '<S16>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET7;               /* '<S16>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET2_j;             /* '<S69>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET5_l;             /* '<S69>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET_c;              /* '<S16>/VEMS_vidGET' */
  UInt16 OutDTConv_m;                /* '<S50>/OutDTConv' */
  UInt16 OutDTConv_b;                /* '<S51>/OutDTConv' */
  UInt16 Switch2;                    /* '<S34>/Switch2' */
  UInt16 Merge;                      /* '<S83>/Merge' */
  UInt16 Switch2_k;                  /* '<S71>/Switch2' */
  UInt16 LookUpTable2D;              /* '<S90>/Look-Up Table (2-D)' */
  UInt16 OutDTConv_c;                /* '<S91>/OutDTConv' */
  UInt16 Switch1;                    /* '<S72>/Switch1' */
  UInt16 SignalConversion1;          /* '<S16>/Signal Conversion1' */
  UInt8 VEMS_vidGET4_g;              /* '<S69>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET8;                /* '<S16>/VEMS_vidGET8' */
  Boolean VEMS_vidGET13;             /* '<S16>/VEMS_vidGET13' */
  Boolean VEMS_vidGET9;              /* '<S16>/VEMS_vidGET9' */
  Boolean VEMS_vidGET11;             /* '<S16>/VEMS_vidGET11' */
  Boolean VEMS_vidGET10;             /* '<S16>/VEMS_vidGET10' */
  Boolean VEMS_vidGET1_o;            /* '<S16>/VEMS_vidGET1' */
  Boolean OR3;                       /* '<S34>/OR3' */
  UInt8 VEMS_vidGET3_b;              /* '<S69>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET6;                /* '<S16>/VEMS_vidGET6' */
  rtB_F01_HPPmpMdl_RTSt_inhib_HPP F01_HPPmpMdl_RTSt_inhib_j;/* '<S13>/F01_HPPmpMdl_RTSt_inhib' */
  rtB_F01_HPPmpMdl_RTSt_inhib_HPP F01_HPPmpMdl_RTSt_inhib;/* '<S6>/F01_HPPmpMdl_RTSt_inhib' */
} BlockIO_HPPmpMdl;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S67>/Unit Delay' */
  Float32 UnitDelay_DSTATE_d;         /* '<S68>/Unit Delay' */
  SInt16 UnitDelay_DSTATE_c;          /* '<S56>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_l;         /* '<S66>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S77>/UnitDelay' */
  Boolean UnitDelay_p;               /* '<S77>/UnitDelay1' */
  Boolean UnitDelay_e;               /* '<S80>/UnitDelay' */
  Boolean UnitDelay_n;               /* '<S80>/UnitDelay1' */
  Boolean UnitDelay_et;              /* '<S78>/UnitDelay' */
  Boolean UnitDelay_d;               /* '<S78>/UnitDelay1' */
  Boolean UnitDelay_a;               /* '<S79>/UnitDelay' */
  Boolean UnitDelay_f;               /* '<S79>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_i;        /* '<S57>/Unit Delay' */
  Boolean UnitDelay_DSTATE_f;        /* '<S58>/Unit Delay' */
  Boolean UnitDelay_g;               /* '<S45>/UnitDelay' */
  Boolean UnitDelay_dh;              /* '<S45>/UnitDelay1' */
} D_Work_HPPmpMdl;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S77>/Logic'
   *   '<S78>/Logic'
   *   '<S79>/Logic'
   *   '<S80>/Logic'
   *   '<S45>/Logic'
   */
  Boolean pooled12[16];
} ConstParam_HPPmpMdl;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define HPPMPMDL_START_SEC_VAR_UNSPECIFIED
#include "HPPmpMdl_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_HPPmpMdl HPPmpMdl_B;

/* Block states (auto storage) */
extern D_Work_HPPmpMdl HPPmpMdl_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_HPPmpMdl HPPmpMdl_ConstP;

#define HPPMPMDL_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpMdl_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define HPPMPMDL_START_SEC_CODE
#include "HPPmpMdl_MemMap.h"

/* Model entry point functions */
extern void HPPmpMdl_initialize(void);
extern void PFuCtl_EveSpl_HPPmpMdl(void);
extern void PFuCtl_EveStTR_HPPmpMdl(void);
extern void PFuCtl_EveRTSt_HPPmpMdl(void);
extern void PFuCtl_EveRst_HPPmpMdl(void);

#define HPPMPMDL_STOP_SEC_CODE
#include "HPPmpMdl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define HPPMPMDL_START_SEC_CALIB_32BIT
#include "HPPmpMdl_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    -0.015625                                                         */
/* Units:   l                                                                 */
/* PhysMin: -0.015625                                                         */
/* PhysMax: 0.015625                                                          */
extern CONST(UInt32, HPPMPMDL_CALIB) PFuCtl_OfsVolPmpCor_T[16];

/* Type:    UInt32                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    -0.015625                                                         */
/* Units:   l                                                                 */
/* PhysMin: -0.015625                                                         */
/* PhysMax: 0.015625                                                          */
extern CONST(UInt32, HPPMPMDL_CALIB) PFuCtl_volFuReqEfc_A[16];

/* Type:    UInt32                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    -0.015625                                                         */
/* Units:   l                                                                 */
/* PhysMin: -0.015625                                                         */
/* PhysMax: 0.015625                                                          */
extern CONST(UInt32, HPPMPMDL_CALIB) PFuCtl_volFuReqEfc_T[16];

#define HPPMPMDL_STOP_SEC_CALIB_32BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define HPPMPMDL_START_SEC_CALIB_16BIT
#include "HPPmpMdl_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.0236                                                            */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1546.626                                                          */
extern CONST(UInt16, HPPMPMDL_CALIB) Ext_uBatt_A[9];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agPmpCmdDecelReq_T[16];

/* Type:    SInt16                                                           */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: -720.0                                                            */
/* PhysMax: 720.0                                                             */
extern CONST(SInt16, HPPMPMDL_CALIB) PFuCtl_agPmpCmdMin_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agPmpCmdReqIni_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agPmpCmdReqRawBum_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdMax_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdMin_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdReqOpl_T[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdReqRawBum_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdReq_A[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdReq_T[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdSpil_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   Kg/l                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_dens_T[16];

/* Type:    UInt16                                                          */
/* Slope:   1.4901161193847656E-008                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 9.7654759883880615E-004                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_mFuPmpCtlMin_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEngHiDecelThdHi_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEngHiDecelThdLo_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEngLoDecelThdHi_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEngLoDecelThdLo_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEng_A[16];

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524272.0                                                          */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pDsThrMesHiDecelThdHi_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524272.0                                                          */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pDsThrMesHiDecelThdLo_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524272.0                                                          */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pDsThrMesLoDecelThdHi_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524272.0                                                          */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pDsThrMesLoDecelThdLo_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pFuRailSplMes_A[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pHiThdPresTiPmpCmd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pLoThdPresTiPmpCmd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pPrailThdMFuPmpEstim_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_rVolEfcPmpCor_T[16];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_rVolEfcPmp_M[256];

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiCmdEndTDCPmp_C;

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiOfsPmpCmdHyd_M[256];

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiOfsPmpCmdN_M[225];

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPeakDurnCmd_T[25];

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPeakDurnOfs_C;

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdDecelGap_M[256];

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdDecel_T[16];

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdLo_M[144];

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdReqIni_C;

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdReqRawBum_T[16];

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmd_M[144];

#define HPPMPMDL_STOP_SEC_CALIB_16BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPPMPMDL_START_SEC_CALIB_8BIT
#include "HPPmpMdl_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_NrProfCmd_A[25];

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_NumProfilCmd_A[25];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_noSplInLrnCond_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_tFuEstim_A[16];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    233.0                                                             */
/* Units:   K                                                                 */
/* PhysMin: 233.0                                                             */
/* PhysMax: 488.0                                                             */
extern CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_tFuUsPmp_A[16];

#define HPPMPMDL_STOP_SEC_CALIB_8BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define HPPMPMDL_START_SEC_CALIB_BOOLEAN
#include "HPPmpMdl_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bAcvLrnCondPmpCmdLim_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bAcvPmpCmdEndTDC_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bAcvPmpMinFrzI_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bChoCmdAg_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bForcAcvDecelZone_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bmFuPmpEstim_C;

#define HPPMPMDL_STOP_SEC_CALIB_BOOLEAN
#include "HPPmpMdl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define HPPMPMDL_START_SEC_VAR_32BIT
#include "HPPmpMdl_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   Kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.0078125                                                         */
extern VAR(UInt32, HPPMPMDL_VAR) PFuCtl_mFuPmpEstim;

/* Type:    UInt32                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   Kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.0078125                                                         */
extern VAR(UInt32, HPPMPMDL_VAR) PFuCtl_mFuPmpEstimRaw;

#define HPPMPMDL_STOP_SEC_VAR_32BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define HPPMPMDL_START_SEC_VAR_16BIT
#include "HPPmpMdl_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agPmpCmdEfcReq;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agPmpCmdReq;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agWdPmpCmdReq;

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiBeg2PulseDif;

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPeakDurnCmd;

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdDecelGap;

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdDecelReq;

/* Type:    UInt16                                                          */
/* Slope:   6.4E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.1942399999999991E-001                                           */
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdReq;

#define HPPMPMDL_STOP_SEC_VAR_16BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define HPPMPMDL_START_SEC_VAR_BOOLEAN
#include "HPPmpMdl_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bDetAgWdPmpCmdLim;

#define HPPMPMDL_STOP_SEC_VAR_BOOLEAN
#include "HPPmpMdl_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S20>/BKPT1' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S20>/TABLE' : Unused code path elimination
 * Block '<S21>/BKPT1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S21>/TABLE' : Unused code path elimination
 * Block '<S22>/BKPT1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S22>/TABLE' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S23>/TABLE' : Unused code path elimination
 * Block '<S23>/TABLE1' : Unused code path elimination
 * Block '<S23>/TABLE2' : Unused code path elimination
 * Block '<S17>/PFuCtl_nEng_A' : Unused code path elimination
 * Block '<S17>/PFuCtl_pFuRailSplMes_A' : Unused code path elimination
 * Block '<S17>/PFuCtl_pFuRailSplMes_A1' : Unused code path elimination
 * Block '<S17>/PFuCtl_tFuEstim_A' : Unused code path elimination
 * Block '<S17>/PFuCtl_tFuEstim_A1' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/Data Type Propagation1' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Conversion' : Unused code path elimination
 * Block '<S28>/Data Type Conversion1' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/Data Type Propagation1' : Unused code path elimination
 * Block '<S30>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Data Type Conversion' : Unused code path elimination
 * Block '<S30>/Data Type Conversion1' : Unused code path elimination
 * Block '<S35>/BKPT1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S35>/TABLE' : Unused code path elimination
 * Block '<S36>/BKPT1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/TABLE' : Unused code path elimination
 * Block '<S37>/BKPT1' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S37>/TABLE' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S38>/TABLE' : Unused code path elimination
 * Block '<S38>/TABLE1' : Unused code path elimination
 * Block '<S38>/TABLE2' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S39>/TABLE' : Unused code path elimination
 * Block '<S39>/TABLE1' : Unused code path elimination
 * Block '<S39>/TABLE2' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S40>/TABLE' : Unused code path elimination
 * Block '<S40>/TABLE1' : Unused code path elimination
 * Block '<S40>/TABLE2' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S41>/TABLE' : Unused code path elimination
 * Block '<S41>/TABLE1' : Unused code path elimination
 * Block '<S41>/TABLE2' : Unused code path elimination
 * Block '<S32>/Ext_uBatt_A' : Unused code path elimination
 * Block '<S32>/Ext_uBatt_A1' : Unused code path elimination
 * Block '<S32>/Ext_uBatt_A2' : Unused code path elimination
 * Block '<S32>/PFuCtl_NrProfCmd_A' : Unused code path elimination
 * Block '<S32>/PFuCtl_nEng_A' : Unused code path elimination
 * Block '<S32>/PFuCtl_nEng_A1' : Unused code path elimination
 * Block '<S32>/PFuCtl_nEng_A2' : Unused code path elimination
 * Block '<S32>/PFuCtl_nEng_A3' : Unused code path elimination
 * Block '<S32>/PFuCtl_tFuEstim_A' : Unused code path elimination
 * Block '<S32>/PFuCtl_volFuReqEfc_A' : Unused code path elimination
 * Block '<S32>/PFuCtl_volFuReqEfc_A1' : Unused code path elimination
 * Block '<S45>/LO3' : Unused code path elimination
 * Block '<S44>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S47>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Relational Operator' : Unused code path elimination
 * Block '<S48>/Relational Operator1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Propagation' : Unused code path elimination
 * Block '<S52>/Constant1' : Unused code path elimination
 * Block '<S52>/Switch3' : Unused code path elimination
 * Block '<S59>/BKPT1' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S59>/TABLE' : Unused code path elimination
 * Block '<S19>/PFuCtl_agWdPmpCmdReq_A' : Unused code path elimination
 * Block '<S77>/LO3' : Unused code path elimination
 * Block '<S78>/LO3' : Unused code path elimination
 * Block '<S79>/LO3' : Unused code path elimination
 * Block '<S80>/LO3' : Unused code path elimination
 * Block '<S81>/BKPT1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S81>/TABLE' : Unused code path elimination
 * Block '<S82>/BKPT1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S82>/TABLE' : Unused code path elimination
 * Block '<S71>/PFuCtl_nEng_A' : Unused code path elimination
 * Block '<S85>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S86>/Force any float to Double everything else to uint8' : Unused code path elimination
 * Block '<S86>/Force any float to Single everything else to uint8' : Unused code path elimination
 * Block '<S84>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S89>/BKPT1' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S89>/TABLE' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S90>/TABLE' : Unused code path elimination
 * Block '<S90>/TABLE1' : Unused code path elimination
 * Block '<S90>/TABLE2' : Unused code path elimination
 * Block '<S72>/PFuCtl_NumProfilCmd_A' : Unused code path elimination
 * Block '<S72>/PFuCtl_nEng_A' : Unused code path elimination
 * Block '<S72>/PFuCtl_nEng_A1' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S24>/Switch' : Eliminated due to constant selection input
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S35>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S37>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S40>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S40>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S49>/Switch' : Eliminated due to constant selection input
 * Block '<S50>/Switch' : Eliminated due to constant selection input
 * Block '<S51>/Switch' : Eliminated due to constant selection input
 * Block '<S59>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Switch' : Eliminated due to constant selection input
 * Block '<S61>/Switch' : Eliminated due to constant selection input
 * Block '<S16>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S81>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S82>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S85>/FixPt Gateway Out' : Eliminate redundant data type conversion
 * Block '<S89>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S91>/Switch' : Eliminated due to constant selection input
 * Block '<S24>/Add3' : Unused code path elimination
 * Block '<S24>/Add4' : Unused code path elimination
 * Block '<S24>/Constant' : Unused code path elimination
 * Block '<S24>/Relational Operator' : Unused code path elimination
 * Block '<S24>/Switch1' : Unused code path elimination
 * Block '<S24>/offset2' : Unused code path elimination
 * Block '<S24>/offset3' : Unused code path elimination
 * Block '<S24>/offset4' : Unused code path elimination
 * Block '<S49>/Add3' : Unused code path elimination
 * Block '<S49>/Add4' : Unused code path elimination
 * Block '<S49>/Constant' : Unused code path elimination
 * Block '<S49>/Relational Operator' : Unused code path elimination
 * Block '<S49>/Switch1' : Unused code path elimination
 * Block '<S49>/offset2' : Unused code path elimination
 * Block '<S49>/offset3' : Unused code path elimination
 * Block '<S49>/offset4' : Unused code path elimination
 * Block '<S50>/Add3' : Unused code path elimination
 * Block '<S50>/Add4' : Unused code path elimination
 * Block '<S50>/Constant' : Unused code path elimination
 * Block '<S50>/Relational Operator' : Unused code path elimination
 * Block '<S50>/Switch1' : Unused code path elimination
 * Block '<S50>/offset2' : Unused code path elimination
 * Block '<S50>/offset3' : Unused code path elimination
 * Block '<S50>/offset4' : Unused code path elimination
 * Block '<S51>/Add3' : Unused code path elimination
 * Block '<S51>/Add4' : Unused code path elimination
 * Block '<S51>/Constant' : Unused code path elimination
 * Block '<S51>/Relational Operator' : Unused code path elimination
 * Block '<S51>/Switch1' : Unused code path elimination
 * Block '<S51>/offset2' : Unused code path elimination
 * Block '<S51>/offset3' : Unused code path elimination
 * Block '<S51>/offset4' : Unused code path elimination
 * Block '<S65>/Add3' : Unused code path elimination
 * Block '<S65>/Add4' : Unused code path elimination
 * Block '<S65>/Constant' : Unused code path elimination
 * Block '<S65>/Relational Operator' : Unused code path elimination
 * Block '<S65>/Switch1' : Unused code path elimination
 * Block '<S65>/offset2' : Unused code path elimination
 * Block '<S65>/offset3' : Unused code path elimination
 * Block '<S65>/offset4' : Unused code path elimination
 * Block '<S61>/Add3' : Unused code path elimination
 * Block '<S61>/Add4' : Unused code path elimination
 * Block '<S61>/Constant' : Unused code path elimination
 * Block '<S61>/Relational Operator' : Unused code path elimination
 * Block '<S61>/Switch1' : Unused code path elimination
 * Block '<S61>/offset2' : Unused code path elimination
 * Block '<S61>/offset3' : Unused code path elimination
 * Block '<S61>/offset4' : Unused code path elimination
 * Block '<S91>/Add3' : Unused code path elimination
 * Block '<S91>/Add4' : Unused code path elimination
 * Block '<S91>/Constant' : Unused code path elimination
 * Block '<S91>/Relational Operator' : Unused code path elimination
 * Block '<S91>/Switch1' : Unused code path elimination
 * Block '<S91>/offset2' : Unused code path elimination
 * Block '<S91>/offset3' : Unused code path elimination
 * Block '<S91>/offset4' : Unused code path elimination
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
 * hilite_system('HPPmpMdl_AUTOCODE/HPPmpMdl')    - opens subsystem HPPmpMdl_AUTOCODE/HPPmpMdl
 * hilite_system('HPPmpMdl_AUTOCODE/HPPmpMdl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : HPPmpMdl_AUTOCODE
 * '<S1>'   : HPPmpMdl_AUTOCODE/HPPmpMdl
 * '<S6>'   : HPPmpMdl_AUTOCODE/HPPmpMdl/F01_HPPmpMdl_Ini
 * '<S7>'   : HPPmpMdl_AUTOCODE/HPPmpMdl/F01_HPPmpMdl_RTSt
 * '<S8>'   : HPPmpMdl_AUTOCODE/HPPmpMdl/F02_HPPmpMdl_StTR
 * '<S9>'   : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl
 * '<S10>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel
 * '<S11>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/demux_fc
 * '<S12>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F01_HPPmpMdl_Ini/F01_HPPmpMdl_RTSt_inhib
 * '<S13>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F01_HPPmpMdl_RTSt/F01_HPPmpMdl_RTSt
 * '<S14>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F01_HPPmpMdl_RTSt/F01_HPPmpMdl_RTSt/F01_HPPmpMdl_RTSt_inhib
 * '<S15>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F02_HPPmpMdl_StTR/F02_HPPmpMdl_StTR
 * '<S16>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl
 * '<S17>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn
 * '<S18>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct
 * '<S19>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim
 * '<S20>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Carto_1D_31
 * '<S21>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Carto_1D_32
 * '<S22>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Carto_1D_33
 * '<S23>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Carto_2D1
 * '<S24>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/SingleToFixdt
 * '<S25>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Subsystem1
 * '<S26>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Subsystem2
 * '<S27>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/multiplication_411
 * '<S28>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Subsystem1/Data Type Police Only single
 * '<S29>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Subsystem1/If Action Subsystem3
 * '<S30>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Subsystem2/Data Type Police Only single
 * '<S31>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F01_VolFuPmpClcn/Subsystem2/If Action Subsystem3
 * '<S32>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw
 * '<S33>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F02_agWdPmpMinClcn
 * '<S34>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor
 * '<S35>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/Carto_1D_34
 * '<S36>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/Carto_1D_35
 * '<S37>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/Carto_1D_36
 * '<S38>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/Carto_2D_22
 * '<S39>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/Carto_2D_23
 * '<S40>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/Carto_2D_24
 * '<S41>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/Carto_2D_25
 * '<S42>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/PosHys1
 * '<S43>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/multiplication_421
 * '<S44>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/multiplication_431
 * '<S45>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F01_agPmpCmdRaw/PosHys1/BasculeRS
 * '<S46>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F02_agWdPmpMinClcn/multiplication_1
 * '<S47>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F02_agWdPmpMinClcn/multiplication_431
 * '<S48>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/Clamp
 * '<S49>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/SingleToFixdt
 * '<S50>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/SingleToFixdt1
 * '<S51>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/SingleToFixdt2
 * '<S52>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/TIMER2
 * '<S53>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/Clamp/Data Type Conversion Inherited
 * '<S54>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/Clamp/Data Type Conversion Inherited1
 * '<S55>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/Clamp/Saturation Dynamic
 * '<S56>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/TIMER2/SubSystem
 * '<S57>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/TIMER2/SubSystem1
 * '<S58>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F02_AgBegPmpAct/F03_agPmpCmdCor/TIMER2/SubSystem2
 * '<S59>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/Carto_1D_37
 * '<S60>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/F01_MFuPmpEstim
 * '<S61>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/SingleToFixdt
 * '<S62>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/multiplication_461
 * '<S63>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/multiplication_471
 * '<S64>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/F01_MFuPmpEstim/Mem
 * '<S65>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/F01_MFuPmpEstim/SingleToFixdt
 * '<S66>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/F01_MFuPmpEstim/VEMS_UnitDelay
 * '<S67>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/F01_MFuPmpEstim/VEMS_UnitDelay1
 * '<S68>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F03_HPPmpMdl/F03_HPPmpMdl/F03_MFuPmpEstim/F01_MFuPmpEstim/Mem/VEMS_UnitDelay1
 * '<S69>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel
 * '<S70>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone
 * '<S71>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command
 * '<S72>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F03_TipumCommand_Calculation
 * '<S73>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone/NegHys1
 * '<S74>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone/NegHys2
 * '<S75>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone/PosHys1
 * '<S76>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone/PosHys2
 * '<S77>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone/NegHys1/BasculeRS
 * '<S78>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone/NegHys2/BasculeRS
 * '<S79>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone/PosHys1/BasculeRS
 * '<S80>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F01_DecelZone/PosHys2/BasculeRS
 * '<S81>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command/Carto_1D_31
 * '<S82>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command/Carto_1D_38
 * '<S83>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command/Secured fixpoint division
 * '<S84>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command/multiplication_471
 * '<S85>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command/Secured fixpoint division/Data Type Scaling Strip
 * '<S86>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command/Secured fixpoint division/Data Type Police No Floating Point1
 * '<S87>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command/Secured fixpoint division/If Action Subsystem2
 * '<S88>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F02_Nominal_command/Secured fixpoint division/If Action Subsystem3
 * '<S89>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F03_TipumCommand_Calculation/Carto_1D_310
 * '<S90>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F03_TipumCommand_Calculation/Carto_2D_26
 * '<S91>'  : HPPmpMdl_AUTOCODE/HPPmpMdl/F04_HPPmpDecel/F04_HPPmpDecel/F03_TipumCommand_Calculation/SingleToFixdt
 */

/*-
 * Requirements for '<Root>': HPPmpMdl
 *
 * Inherited requirements for '<S1>/F01_HPPmpMdl_Ini':
 *  1. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_002.01 ;
 *  2. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_011.01 ;
 *  3. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_010.01 ;
 *  4. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_009.01 ;
 *  5. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_001.02 ;
 *
 * Inherited requirements for '<S1>/F01_HPPmpMdl_RTSt':
 *  1. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_002.01 ;
 *  2. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_011.01 ;
 *  3. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_010.01 ;
 *  4. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_009.01 ;
 *  5. SubSystem "F01_HPPmpMdl_Ini" !Trace_To : VEMS_E_10_08013_001.02 ;
 *
 * Inherited requirements for '<S1>/F02_HPPmpMdl_StTR':
 *  1. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_002.01 ;
 *  2. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_011.01 ;
 *  3. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_010.01 ;
 *  4. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_009.01 ;
 *  5. SubSystem "F02_HPPmpMdl_StTR" !Trace_To : VEMS_E_10_08013_001.02 ;
 *
 * Inherited requirements for '<S1>/F03_HPPmpMdl':
 *  1. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_002.01 ;
 *  2. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_011.01 ;
 *  3. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_010.01 ;
 *  4. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_009.01 ;
 *  5. SubSystem "F03_HPPmpMdl" !Trace_To : VEMS_E_10_08013_001.02 ;
 *
 * Inherited requirements for '<S1>/F04_HPPmpDecel':
 *  1. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_008.01 ;
 *  2. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_002.01 ;
 *  3. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_011.01 ;
 *  4. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_010.01 ;
 *  5. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_009.01 ;
 *  6. SubSystem "F04_HPPmpDecel" !Trace_To : VEMS_E_10_08013_001.02 ;

 */
#endif                                 /* RTW_HEADER_HPPmpMdl_h_ */

/*-------------------------------- end of file -------------------------------*/
