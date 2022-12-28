/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : KnkMgrCorRbl                                            */
/* !Description     : CORRECTION RUMBLE                                       */
/*                                                                            */
/* !Module          : KnkMgrCorRbl                                            */
/*                                                                            */
/* !File            : KnkMgrCorRbl.h                                          */
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
/*   Code generated on: Mon Mar 03 16:32:53 2014                              */
/*   Model name       : KnkMgrCorRbl_AUTOCODE.mdl                             */
/*   Model version    : 1.302                                                 */
/*   Root subsystem   : /KnkMgrCorRbl                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKMGRCORRBL/KnkM$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   mbenfrad                               $$Date::   04 Mar 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_KnkMgrCorRbl_h_
#define RTW_HEADER_KnkMgrCorRbl_h_
#ifndef KnkMgrCorRbl_COMMON_INCLUDES_
# define KnkMgrCorRbl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "KnkMgrCorRbl_import.h"
#include "VEMS.H"
#include "GDGAR.H"
#include "rtw_shared_utils.h"
#include "rt_MAX.h"
#include "rt_MIN.h"
#endif                                 /* KnkMgrCorRbl_COMMON_INCLUDES_ */

#include "KnkMgrCorRbl_types.h"

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
  UInt16 VEMS_vidGET2;               /* '<S72>/VEMS_vidGET2' */
  UInt16 Assignment2[4];             /* '<S78>/Assignment2' */
  UInt16 SFunction9[4];              /* '<S72>/S-Function9' */
  UInt16 VEMS_vidGET1;               /* '<S41>/VEMS_vidGET1' */
  UInt16 Assignment2_d[4];           /* '<S45>/Assignment2' */
  UInt16 Assignment2_f[9];           /* '<S71>/Assignment2' */
  UInt16 Assignment1[9];             /* '<S71>/Assignment1' */
  UInt16 Assignment1_m[9];           /* '<S70>/Assignment1' */
  UInt16 Assignment2_e[9];           /* '<S70>/Assignment2' */
  UInt16 Assignment1_f[9];           /* '<S69>/Assignment1' */
  UInt16 Assignment2_l[9];           /* '<S69>/Assignment2' */
  UInt16 Assignment2_j[9];           /* '<S68>/Assignment2' */
  UInt16 Assignment1_b[9];           /* '<S68>/Assignment1' */
  UInt16 VEMS_vidGET1_n;             /* '<S72>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET;                /* '<S41>/VEMS_vidGET' */
  SInt16 VEMS_vidGET3;                /* '<S41>/VEMS_vidGET3' */
  UInt8 TmpSignalConversionAtVEMS_vidSE[4];
  UInt8 TmpSignalConversionAtVEMS_vid_n[4];
  UInt8 TmpSignalConversionAtVEMS_vid_e[4];
  UInt8 VEMS_vidGET4[4];             /* '<S72>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET5[4];             /* '<S72>/VEMS_vidGET5' */
  UInt8 Assignment2_n[4];            /* '<S75>/Assignment2' */
  UInt8 Assignment2_a[4];            /* '<S77>/Assignment2' */
  UInt8 Assignment1_j[4];            /* '<S44>/Assignment1' */
  Boolean VEMS_vidGET_f;             /* '<S99>/VEMS_vidGET' */
  Boolean VEMS_vidGET1_f;            /* '<S99>/VEMS_vidGET1' */
  Boolean VEMS_vidGET3_d;            /* '<S99>/VEMS_vidGET3' */
  Boolean VEMS_vidGET2_c;            /* '<S99>/VEMS_vidGET2' */
  Boolean Assignment1_p[4];          /* '<S77>/Assignment1' */
  Boolean VEMS_vidGET6;              /* '<S72>/VEMS_vidGET6' */
  Boolean VEMS_vidGET7;              /* '<S72>/VEMS_vidGET7' */
  Boolean Merge;                     /* '<S87>/Merge' */
  Boolean Merge_g;                   /* '<S88>/Merge' */
  Boolean Merge_i;                   /* '<S93>/Merge' */
  Boolean LogicalOperator2;          /* '<S86>/Logical Operator2' */
  Boolean Merge_gy;                  /* '<S51>/Merge' */
  Boolean LogicalOperator2_f[4];     /* '<S43>/Logical Operator2' */
  Boolean VEMS_vidGET2_d[4];         /* '<S16>/VEMS_vidGET2' */
  Boolean VEMS_vidGET1_n0[4];        /* '<S16>/VEMS_vidGET1' */
  Boolean VEMS_vidGET_h[4];          /* '<S16>/VEMS_vidGET' */
  Boolean VEMS_vidGET4_f[4];         /* '<S16>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET3_j;              /* '<S72>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET2_i;              /* '<S41>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET3_f;              /* '<S16>/VEMS_vidGET3' */
} BlockIO_KnkMgrCorRbl;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 UnitDelay_DSTATE[4];         /* '<S65>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_l;          /* '<S38>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_a;          /* '<S37>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_a1;         /* '<S34>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_n;          /* '<S33>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_k;          /* '<S30>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_e;          /* '<S29>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_ep;         /* '<S25>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_p;          /* '<S26>/Unit Delay' */
  Boolean UnitDelay_DSTATE_c[4];     /* '<S82>/Unit Delay' */
  Boolean UnitDelay_DSTATE_h;        /* '<S95>/Unit Delay' */
  Boolean UnitDelay_DSTATE_at;       /* '<S98>/Unit Delay' */
  Boolean UnitDelay_DSTATE_aa;       /* '<S61>/Unit Delay' */
  Boolean UnitDelay_DSTATE_aw[4];    /* '<S40>/Unit Delay' */
  Boolean UnitDelay_DSTATE_c5[4];    /* '<S39>/Unit Delay' */
} D_Work_KnkMgrCorRbl;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define KNKMGRCORRBL_START_SEC_VAR_UNSPECIFIED
#include "KnkMgrCorRbl_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_KnkMgrCorRbl KnkMgrCorRbl_B;

/* Block states (auto storage) */
extern D_Work_KnkMgrCorRbl KnkMgrCorRbl_DWork;

#define KNKMGRCORRBL_STOP_SEC_VAR_UNSPECIFIED
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define KNKMGRCORRBL_START_SEC_CODE
#include "KnkMgrCorRbl_MemMap.h"

/* Model entry point functions */
extern void KnkMgrCorRbl_initialize(void);
extern void KnkTreat_EveRst_KnkMgrCorRbl(void);
extern void KnkTreat_EveRbl_KnkMgrCorRbl(void);

#define KNKMGRCORRBL_STOP_SEC_CODE
#include "KnkMgrCorRbl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define KNKMGRCORRBL_START_SEC_CALIB_32BIT
#include "KnkMgrCorRbl_MemMap.h"

/* Type:    UInt32                                                          */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.294967295E+009                                                  */
extern CONST(UInt32, KNKMGRCORRBL_CALIB) KnkMgt_ctOccurRblIrvLdLimHiThd_C;

/* Type:    UInt32                                                          */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.294967295E+009                                                  */
extern CONST(UInt32, KNKMGRCORRBL_CALIB) KnkMgt_ctOccurRbllrvLdLimLoThd_C;

#define KNKMGRCORRBL_STOP_SEC_CALIB_32BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define KNKMGRCORRBL_START_SEC_CALIB_16BIT
#include "KnkMgrCorRbl_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_ctTotKnkRblInc_M[81];

/* Type:    UInt16                                                          */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_ctTotRblInc_M[81];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_nEngNbZoneRbl_A[3];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_nEngSuperKnkHiThd_C;

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_nEngSuperKnkLoThd_C;

/* Type:    UInt16                                                          */
/* Slope:   0.125                                                             */
/* Bias:    0.0                                                               */
/* Units:   tr/min                                                            */
/* PhysMin: 0                                                                 */
/* PhysMax: 8191.875                                                          */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_nEng_A[9];

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    0.0                                                               */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_rAirLdNbZoneRbl_A[3];

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    0.0                                                               */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_rAirLd_A[9];

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_rLdSuperKnkHiThd_C;

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_rLdSuperKnkLoThd_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0625                                                            */
/* Bias:    -2000.0                                                           */
/* Units:   N.m                                                               */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(UInt16, KNKMGRCORRBL_CALIB) KnkMgt_tqGlblTqRawSpThd_M[9];

#define KNKMGRCORRBL_STOP_SEC_CALIB_16BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define KNKMGRCORRBL_START_SEC_CALIB_8BIT
#include "KnkMgrCorRbl_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctIdxETBCyl1_T[16];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctIdxETBCyl2_T[16];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctIdxETBCyl3_T[16];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctIdxETBCyl4_T[16];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctInjCutOfTmpLimLdHiThd_C;

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctInjCutOfTmpLimLdLoThd_C;

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctInjCutOffVlvPosnHiThd_C;

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctInjCutOffVlvPosnLoThd_C;

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdKnkRblInc_M[81];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblDec_M[81];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblInc_M[81];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    1.0                                                               */
/* Units:   [-]                                                               */
/* PhysMin: 1.0                                                               */
/* PhysMax: 256.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblInjCutOffDec_C;

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblInjCutOffThd1_T[9];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctPerdRblInjCutOffThd2_T[9];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctTDCInjCutOffDec_M[81];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctTDCInjCutOffInc_M[81];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_ctTotNbCycDecRbl_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 15.0                                                              */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxBkptETB_A[16];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 16.0                                                              */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxCritRblThd_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    1.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 16.0                                                              */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxMaxETBCyl1_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    1.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 16.0                                                              */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxMaxETBCyl2_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    1.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 16.0                                                              */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxMaxETBCyl3_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    1.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 16.0                                                              */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_idxMaxETBCyl4_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0                                                               */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_stKnkETBCyl1_T[16];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0                                                               */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_stKnkETBCyl2_T[16];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0                                                               */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_stKnkETBCyl3_T[16];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0                                                               */
extern CONST(UInt8, KNKMGRCORRBL_CALIB) KnkMgt_stKnkETBCyl4_T[16];

#define KNKMGRCORRBL_STOP_SEC_CALIB_8BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define KNKMGRCORRBL_START_SEC_CALIB_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKMGRCORRBL_CALIB) KnkMgt_bIdxMinPosnRblAcv_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKMGRCORRBL_CALIB) KnkMgt_bInhIrvLdLimRbl_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKMGRCORRBL_CALIB) KnkMgt_bRblETB_C;

#define KNKMGRCORRBL_STOP_SEC_CALIB_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define KNKMGRCORRBL_START_SEC_VAR_8BIT
#include "KnkMgrCorRbl_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctPerdRbl[4];

/* Type:    UInt8                                                           */
/* Units:   PMH                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTDCInjCutOff[4];

/* Type:    UInt8                                                           */
/* Units:   [-]                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 16.0                                                              */
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxMinPosnRbl[4];

#define KNKMGRCORRBL_STOP_SEC_VAR_8BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define KNKMGRCORRBL_START_SEC_VAR_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bAcvIrvLdLimRblReq;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bAcvTmpLdLimRblReq;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bAcvVlvPosnRblReq;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bSuperKnkDet[4];

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_prm_bInjCutOffRblCyl[4];

#define KNKMGRCORRBL_STOP_SEC_VAR_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S23>/BKPT1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S23>/TABLE' : Unused code path elimination
 * Block '<S17>/KnkMgt_idxBkptETB_A' : Unused code path elimination
 * Block '<S17>/KnkMgt_idxBkptETB_A_1' : Unused code path elimination
 * Block '<S24>/BKPT1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S24>/TABLE' : Unused code path elimination
 * Block '<S27>/BKPT1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S27>/TABLE' : Unused code path elimination
 * Block '<S18>/KnkMgt_idxBkptETB_A' : Unused code path elimination
 * Block '<S18>/KnkMgt_idxBkptETB_A_1' : Unused code path elimination
 * Block '<S28>/BKPT1' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S28>/TABLE' : Unused code path elimination
 * Block '<S31>/BKPT1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S31>/TABLE' : Unused code path elimination
 * Block '<S19>/KnkMgt_idxBkptETB_A' : Unused code path elimination
 * Block '<S19>/KnkMgt_idxBkptETB_A_1' : Unused code path elimination
 * Block '<S32>/BKPT1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S32>/TABLE' : Unused code path elimination
 * Block '<S35>/BKPT1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S35>/TABLE' : Unused code path elimination
 * Block '<S20>/KnkMgt_idxBkptETB_A' : Unused code path elimination
 * Block '<S20>/KnkMgt_idxBkptETB_A_1' : Unused code path elimination
 * Block '<S36>/BKPT1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/TABLE' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S48>/x1' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S58>/TABLE' : Unused code path elimination
 * Block '<S58>/TABLE1' : Unused code path elimination
 * Block '<S58>/TABLE2' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S59>/TABLE' : Unused code path elimination
 * Block '<S59>/TABLE1' : Unused code path elimination
 * Block '<S59>/TABLE2' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S60>/TABLE' : Unused code path elimination
 * Block '<S60>/TABLE1' : Unused code path elimination
 * Block '<S60>/TABLE2' : Unused code path elimination
 * Block '<S44>/KnkMgt_nEng_A' : Unused code path elimination
 * Block '<S44>/KnkMgt_nEng_A_1' : Unused code path elimination
 * Block '<S44>/KnkMgt_nEng_A_2' : Unused code path elimination
 * Block '<S44>/KnkMgt_rAirLd_A' : Unused code path elimination
 * Block '<S44>/KnkMgt_rAirLd_A_1' : Unused code path elimination
 * Block '<S44>/KnkMgt_rAirLd_A_2' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S63>/TABLE' : Unused code path elimination
 * Block '<S63>/TABLE1' : Unused code path elimination
 * Block '<S63>/TABLE2' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S64>/TABLE' : Unused code path elimination
 * Block '<S64>/TABLE1' : Unused code path elimination
 * Block '<S64>/TABLE2' : Unused code path elimination
 * Block '<S45>/KnkMgt_nEng_A' : Unused code path elimination
 * Block '<S45>/KnkMgt_nEng_A_1' : Unused code path elimination
 * Block '<S45>/KnkMgt_rAirLd_A' : Unused code path elimination
 * Block '<S45>/KnkMgt_rAirLd_A_1' : Unused code path elimination
 * Block '<S46>/KnkMgt_nEngNbZoneRbl_A' : Unused code path elimination
 * Block '<S46>/KnkMgt_rAirLdNbZoneRbl_A' : Unused code path elimination
 * Block '<S79>/BKPT1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S79>/TABLE' : Unused code path elimination
 * Block '<S80>/BKPT1' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S80>/TABLE' : Unused code path elimination
 * Block '<S76>/KnkMgt_nEng_A' : Unused code path elimination
 * Block '<S76>/KnkMgt_nEng_A_1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S81>/TABLE' : Unused code path elimination
 * Block '<S81>/TABLE1' : Unused code path elimination
 * Block '<S81>/TABLE2' : Unused code path elimination
 * Block '<S77>/KnkMgt_nEng_A' : Unused code path elimination
 * Block '<S77>/KnkMgt_rAirLd_A' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S83>/TABLE' : Unused code path elimination
 * Block '<S83>/TABLE1' : Unused code path elimination
 * Block '<S83>/TABLE2' : Unused code path elimination
 * Block '<S78>/KnkMgt_nEng_A' : Unused code path elimination
 * Block '<S78>/KnkMgt_rAirLd_A' : Unused code path elimination
 * Block '<S94>/Logical Operator2' : Unused code path elimination
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S35>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S49>/Switch' : Eliminated due to constant selection input
 * Block '<S58>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S41>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S81>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S83>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S49>/Add2' : Unused code path elimination
 * Block '<S49>/Constant' : Unused code path elimination
 * Block '<S49>/offset1' : Unused code path elimination
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
 * hilite_system('KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl')    - opens subsystem KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl
 * hilite_system('KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : KnkMgrCorRbl_AUTOCODE
 * '<S1>'   : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl
 * '<S4>'   : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode
 * '<S5>'   : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_Init
 * '<S6>'   : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_InitBis
 * '<S7>'   : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount
 * '<S8>'   : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr
 * '<S9>'   : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F05_Interface
 * '<S10>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F06_Previous
 * '<S11>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/GDGAR_vidGdu
 * '<S12>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/GDGAR_vidGdu1
 * '<S13>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/GDGAR_vidGdu2
 * '<S14>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/demux_fc
 * '<S15>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/demux_fc1
 * '<S16>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode
 * '<S17>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F01_RblTestBenchCyl1
 * '<S18>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F02_RblTestBenchCyl2
 * '<S19>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F03_RblTestBenchCyl3
 * '<S20>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F04_RblTestBenchCyl4
 * '<S21>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F05_RblBenchCoord
 * '<S22>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F06_RblBenchAcv
 * '<S23>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F01_RblTestBenchCyl1/KnkMgt_ctIdxETBCyl1_T
 * '<S24>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F01_RblTestBenchCyl1/KnkMgt_stKnkETBCyl1_T
 * '<S25>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F01_RblTestBenchCyl1/UnitDelay1
 * '<S26>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F01_RblTestBenchCyl1/UnitDelay2
 * '<S27>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F02_RblTestBenchCyl2/KnkMgt_ctIdxETBCyl2_T
 * '<S28>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F02_RblTestBenchCyl2/KnkMgt_stKnkETBCyl2_T
 * '<S29>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F02_RblTestBenchCyl2/UnitDelay3
 * '<S30>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F02_RblTestBenchCyl2/UnitDelay4
 * '<S31>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F03_RblTestBenchCyl3/KnkMgt_ctIdxETBCyl3_T
 * '<S32>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F03_RblTestBenchCyl3/KnkMgt_stKnkETBCyl3_T
 * '<S33>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F03_RblTestBenchCyl3/UnitDelay5
 * '<S34>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F03_RblTestBenchCyl3/UnitDelay6
 * '<S35>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F04_RblTestBenchCyl4/KnkMgt_ctIdxETBCyl4_T
 * '<S36>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F04_RblTestBenchCyl4/KnkMgt_stKnkETBCyl4_T
 * '<S37>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F04_RblTestBenchCyl4/UnitDelay7
 * '<S38>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F04_RblTestBenchCyl4/UnitDelay8
 * '<S39>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F05_RblBenchCoord/UnitDelay10
 * '<S40>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F01_BenchMode/F01_BenchMode/F05_RblBenchCoord/UnitDelay9
 * '<S41>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount
 * '<S42>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F00_RblInhWin
 * '<S43>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl
 * '<S44>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F02_FastCount
 * '<S45>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F03_SlowCount
 * '<S46>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F04_ZoneFct
 * '<S47>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F05_OccurCount
 * '<S48>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F00_RblInhWin/LookUp_1D
 * '<S49>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F00_RblInhWin/SingleToFixdt
 * '<S50>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl/Hysteresis1
 * '<S51>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl/Hysteresis2
 * '<S52>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl/One_Based_Selector
 * '<S53>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl/One_Based_Selector1
 * '<S54>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl/Hysteresis1/If Action Subsystem
 * '<S55>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl/Hysteresis1/If Action Subsystem1
 * '<S56>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl/Hysteresis2/If Action Subsystem
 * '<S57>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F01_RblDetCurCyl/Hysteresis2/If Action Subsystem1
 * '<S58>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F02_FastCount/KnkMgt_ctPerdKnkRblInc_M
 * '<S59>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F02_FastCount/KnkMgt_ctPerdRblDec_M
 * '<S60>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F02_FastCount/KnkMgt_ctPerdRblInc_M
 * '<S61>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F02_FastCount/UnitDelay11
 * '<S62>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F02_FastCount/multiplication_411
 * '<S63>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F03_SlowCount/KnkMgt_ctTotKnkRblInc_M
 * '<S64>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F03_SlowCount/KnkMgt_ctTotRblInc_M
 * '<S65>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F03_SlowCount/UnitDelay12
 * '<S66>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F04_ZoneFct/Index_search1
 * '<S67>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F04_ZoneFct/Index_search2
 * '<S68>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F05_OccurCount/F01_OccurRblCyl1
 * '<S69>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F05_OccurCount/F02_OccurRblCyl2
 * '<S70>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F05_OccurCount/F03_OccurRblCyl3
 * '<S71>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F02_RblCount/F02_RblCount/F05_OccurCount/F04_OccurRblCyl4
 * '<S72>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr
 * '<S73>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection
 * '<S74>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades
 * '<S75>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F01_Min_index_Rbl
 * '<S76>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F02_Depassement_seuil
 * '<S77>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F03_Coupure_injection
 * '<S78>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F04_Nb_coupure_inj
 * '<S79>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F02_Depassement_seuil/KnkMgt_ctPerdRblInjCutOffThd1_T
 * '<S80>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F02_Depassement_seuil/KnkMgt_ctPerdRblInjCutOffThd2_T
 * '<S81>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F03_Coupure_injection/KnkMgt_ctTDCInjCutOffInc_M
 * '<S82>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F03_Coupure_injection/UnitDelay13
 * '<S83>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F04_Nb_coupure_inj/KnkMgt_ctTDCInjCutOffDec_M
 * '<S84>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F01_Coupure_injection/F04_Nb_coupure_inj/multiplication_421
 * '<S85>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F01_TmpRblCorReq
 * '<S86>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F02_IrvRblCorReq
 * '<S87>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F01_TmpRblCorReq/Hysteresis1
 * '<S88>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F01_TmpRblCorReq/Hysteresis2
 * '<S89>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F01_TmpRblCorReq/Hysteresis1/If Action Subsystem
 * '<S90>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F01_TmpRblCorReq/Hysteresis1/If Action Subsystem1
 * '<S91>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F01_TmpRblCorReq/Hysteresis2/If Action Subsystem
 * '<S92>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F01_TmpRblCorReq/Hysteresis2/If Action Subsystem1
 * '<S93>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F02_IrvRblCorReq/Hysteresis1
 * '<S94>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F02_IrvRblCorReq/SR_FlipFlop2
 * '<S95>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F02_IrvRblCorReq/UnitDelay14
 * '<S96>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F02_IrvRblCorReq/Hysteresis1/If Action Subsystem
 * '<S97>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F02_IrvRblCorReq/Hysteresis1/If Action Subsystem1
 * '<S98>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F03_RblCorr/F03_RblCorr/F02_Modes_degrades/F02_IrvRblCorReq/SR_FlipFlop2/UnitDelay13
 * '<S99>'  : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F05_Interface/F05_Interface
 * '<S100>' : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/F06_Previous/F06_Previous
 * '<S101>' : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/GDGAR_vidGdu/GDGAR_vidGdu
 * '<S102>' : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/GDGAR_vidGdu1/GDGAR_vidGdu
 * '<S103>' : KnkMgrCorRbl_AUTOCODE/KnkMgrCorRbl/GDGAR_vidGdu2/GDGAR_vidGdu
 */

/*-
 * Requirements for '<Root>': KnkMgrCorRbl
 *
 * Inherited requirements for '<Root>/KnkMgrCorRbl':
 *  1. SubSystem "KnkMgrCorRbl" !Trace_To : VEMS_E_10_02583_001.01 ;
 *  2. SubSystem "KnkMgrCorRbl" !Trace_To : VEMS_E_10_02583_003.01 ;
 *  3. SubSystem "KnkMgrCorRbl" !Trace_To : VEMS_E_10_02583_004.01 ;
 *
 * Inherited requirements for '<S1>/F01_BenchMode':
 *  1. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_009.01 ;
 *  2. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_003.01 ;
 *  3. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_004.01 ;
 *
 * Inherited requirements for '<S1>/F01_Init':
 *  1. SubSystem "F01_Init" !Trace_To : VEMS_E_10_02583_003.01 ;
 *  2. SubSystem "F01_Init" !Trace_To : VEMS_E_10_02583_004.01 ;
 *
 * Inherited requirements for '<S1>/F01_InitBis':
 *  1. SubSystem "F01_InitBis" !Trace_To : VEMS_E_10_02583_003.01 ;
 *  2. SubSystem "F01_InitBis" !Trace_To : VEMS_E_10_02583_004.01 ;
 *
 * Inherited requirements for '<S1>/F02_RblCount':
 *  1. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_005.01 ;
 *  2. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_003.01 ;
 *  3. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_004.01 ;
 *
 * Inherited requirements for '<S1>/F03_RblCorr':
 *  1. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_001.01 ;
 *  2. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_003.01 ;
 *  3. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_004.01 ;
 *
 * Inherited requirements for '<S1>/F05_Interface':
 *  1. SubSystem "F05_Interface" !Trace_To : VEMS_E_10_02583_003.01 ;
 *  2. SubSystem "F05_Interface" !Trace_To : VEMS_E_10_02583_004.01 ;
 *
 * Inherited requirements for '<S1>/F06_Previous':
 *  1. SubSystem "F06_Previous" !Trace_To : VEMS_E_10_02583_003.01 ;
 *  2. SubSystem "F06_Previous" !Trace_To : VEMS_E_10_02583_004.01 ;
 *
 * Inherited requirements for '<S1>/demux_fc':
 *  1. SubSystem "demux_fc" !Trace_To : VEMS_E_10_02583_002.01 ;
 *
 * Inherited requirements for '<S1>/demux_fc1':
 *  1. SubSystem "demux_fc1" !Trace_To : VEMS_E_10_02583_002.01 ;

 */
#endif                                 /* RTW_HEADER_KnkMgrCorRbl_h_ */

/*-------------------------------- end of file -------------------------------*/
