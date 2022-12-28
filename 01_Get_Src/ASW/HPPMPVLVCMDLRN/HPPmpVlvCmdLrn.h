/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpVlvCmdLrn                                          */
/* !Description     : HPPMPVLVCMDLRN - LEARNING STRATEGY OF THE HP PUMP SPILL VALVE COMMAND PROFILE*/
/*                                                                            */
/* !Module          : HPPmpVlvCmdLrn                                          */
/*                                                                            */
/* !File            : HPPmpVlvCmdLrn.h                                        */
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
/*   Code generated on: Sun Mar 31 19:11:05 2013                              */
/*   Model name       : HPPmpVlvCmdLrn_AUTOCODE.mdl                           */
/*   Model version    : 1.471                                                 */
/*   Root subsystem   : /HPPmpVlvCmdLrn                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPVLVCMDLRN/HPPmpVlvCm$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   etsasson                               $$Date::   03 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPPmpVlvCmdLrn_h_
#define RTW_HEADER_HPPmpVlvCmdLrn_h_
#ifndef HPPmpVlvCmdLrn_COMMON_INCLUDES_
# define HPPmpVlvCmdLrn_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "HPPmpVlvCmdLrn_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#endif                                 /* HPPmpVlvCmdLrn_COMMON_INCLUDES_ */

#include "HPPmpVlvCmdLrn_types.h"

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

#define HPPmpVlvCmdLrn_M               (HPPmpVlvCmdLrn_M)

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Block signals (auto storage) */
typedef struct {
  UInt32 VEMS_vidGET12;              /* '<S6>/VEMS_vidGET12' */
  SInt16 VEMS_vidGET4;                /* '<S6>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET;                /* '<S6>/VEMS_vidGET' */
  UInt16 SignalConversion;           /* '<S12>/Signal Conversion' */
  UInt16 SignalConversion1;          /* '<S12>/Signal Conversion1' */
  UInt16 VEMS_vidGET1;               /* '<S6>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET2;               /* '<S6>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET7;               /* '<S6>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET5;               /* '<S6>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET8;               /* '<S6>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET9;               /* '<S6>/VEMS_vidGET9' */
  SInt8 VEMS_vidGET3;                 /* '<S6>/VEMS_vidGET3' */
  UInt8 Merge;                       /* '<S6>/Merge' */
  Boolean VEMS_vidGET10;             /* '<S6>/VEMS_vidGET10' */
  Boolean VEMS_vidGET11;             /* '<S6>/VEMS_vidGET11' */
  Boolean VEMS_vidGET6;              /* '<S6>/VEMS_vidGET6' */
  Boolean SignalConversion_j;        /* '<S8>/Signal Conversion' */
  Boolean SignalConversion1_m;       /* '<S8>/Signal Conversion1' */
  Boolean Switch2;                   /* '<S91>/Switch2' */
  Boolean LogicalOperator4;          /* '<S16>/Logical Operator4' */
  Boolean LogicalOperator11;         /* '<S16>/Logical Operator11' */
} BlockIO_HPPmpVlvCmdLrn;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S60>/Unit Delay' */
  Float32 UnitDelay_DSTATE_e;         /* '<S63>/Unit Delay' */
  Float32 UnitDelay_DSTATE_l;         /* '<S66>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_p;         /* '<S108>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_j;         /* '<S107>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_n;         /* '<S90>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_o;         /* '<S88>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_c;         /* '<S89>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_c4;        /* '<S72>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_ez;        /* '<S53>/Unit Delay' */
  UInt8 UnitDelay_DSTATE_ek;         /* '<S84>/Unit Delay' */
  Boolean UnitDelay_DSTATE_ow;       /* '<S15>/Unit Delay' */
  Boolean UnitDelay_DSTATE_os;       /* '<S14>/Unit Delay' */
  Boolean UnitDelay_DSTATE_a;        /* '<S13>/Unit Delay' */
  Boolean UnitDelay_DSTATE_k;        /* '<S112>/Unit Delay' */
  Boolean UnitDelay_DSTATE_m;        /* '<S111>/Unit Delay' */
  Boolean UnitDelay_DSTATE_g;        /* '<S82>/Unit Delay' */
  Boolean UnitDelay_DSTATE_b;        /* '<S83>/Unit Delay' */
  Boolean UnitDelay_DSTATE_lg;       /* '<S99>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S91>/UnitDelay' */
  Boolean UnitDelay_i;               /* '<S91>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_i;        /* '<S97>/Unit Delay' */
  Boolean UnitDelay_DSTATE_d;        /* '<S96>/Unit Delay' */
  Boolean UnitDelay_DSTATE_eu;       /* '<S98>/Unit Delay' */
  Boolean UnitDelay_DSTATE_kb;       /* '<S19>/Unit Delay' */
  Boolean UnitDelay_b;               /* '<S69>/UnitDelay' */
  Boolean UnitDelay_h;               /* '<S69>/UnitDelay1' */
  Boolean UnitDelay_n;               /* '<S58>/UnitDelay' */
  Boolean UnitDelay_k;               /* '<S58>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_dt;       /* '<S61>/Unit Delay' */
  Boolean UnitDelay_DSTATE_k3;       /* '<S62>/Unit Delay' */
  Boolean UnitDelay_DSTATE_od;       /* '<S64>/Unit Delay' */
  Boolean UnitDelay_DSTATE_o0;       /* '<S65>/Unit Delay' */
  Boolean UnitDelay_DSTATE_il;       /* '<S67>/Unit Delay' */
  Boolean UnitDelay_DSTATE_i1;       /* '<S68>/Unit Delay' */
  Boolean UnitDelay_DSTATE_c5;       /* '<S59>/Unit Delay' */
  Boolean UnitDelay_c;               /* '<S31>/UnitDelay' */
  Boolean UnitDelay_cm;              /* '<S31>/UnitDelay1' */
  Boolean UnitDelay_f;               /* '<S36>/UnitDelay' */
  Boolean UnitDelay_fi;              /* '<S36>/UnitDelay1' */
  Boolean UnitDelay_e;               /* '<S30>/UnitDelay' */
  Boolean UnitDelay_d;               /* '<S30>/UnitDelay1' */
  Boolean UnitDelay_db;              /* '<S35>/UnitDelay' */
  Boolean UnitDelay_a;               /* '<S35>/UnitDelay1' */
  Boolean UnitDelay_m;               /* '<S32>/UnitDelay' */
  Boolean UnitDelay_hd;              /* '<S32>/UnitDelay1' */
  Boolean UnitDelay_p;               /* '<S39>/UnitDelay' */
  Boolean UnitDelay_bx;              /* '<S39>/UnitDelay1' */
  Boolean UnitDelay_l;               /* '<S33>/UnitDelay' */
  Boolean UnitDelay_c5;              /* '<S33>/UnitDelay1' */
  Boolean UnitDelay_g;               /* '<S38>/UnitDelay' */
  Boolean UnitDelay_p1;              /* '<S38>/UnitDelay1' */
  Boolean UnitDelay_ig;              /* '<S34>/UnitDelay' */
  Boolean UnitDelay_au;              /* '<S34>/UnitDelay1' */
  Boolean UnitDelay_o;               /* '<S37>/UnitDelay' */
  Boolean UnitDelay_hv;              /* '<S37>/UnitDelay1' */
  SInt8 If_ActiveSubsystem;           /* '<S6>/If' */
  Boolean F00_HPPmpVlvCmdLrn_MODE;   /* '<S5>/F00_HPPmpVlvCmdLrn' */
  Boolean F01_Buffer_MODE;           /* '<S10>/F01_Buffer' */
  Boolean F02_Interruption_Condition_MODE;/* '<S17>/F02_Interruption_Condition' */
} D_Work_HPPmpVlvCmdLrn;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState F03c_learning_Interrupt_Trig_ZC;/* '<S10>/F03c_learning_Interrupt' */
  ZCSigState F03b_Failed_pump_strokes_Trig_Z;/* '<S10>/F03b_Failed_pump_strokes' */
  ZCSigState F03_Failed_Pump_Stroke_Trig_ZCE;/* '<S10>/F03_Failed_Pump_Stroke' */
  ZCSigState F04_Deactivation_inc_press_test;/* '<S18>/F04_Deactivation_inc_press_test' */
  ZCSigState F03_Activation_inc_press_test_T;/* '<S18>/F03_Activation_inc_press_test' */
  ZCSigState F02_Reinit_ct_Trig_ZCE;   /* '<S43>/F02_Reinit_ct' */
  ZCSigState F01_ct_nbr_Lrn_Trig_ZCE;  /* '<S43>/F01_ct_nbr_Lrn' */
  ZCSigState F01_Learning_EnvCond_Trig_ZCE;/* '<S17>/F01_Learning_EnvCond' */
} PrevZCSigStates_HPPmpVlvCmdLrn;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S47>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxInde[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S91>/Logic'
   *   '<S30>/Logic'
   *   '<S31>/Logic'
   *   '<S32>/Logic'
   *   '<S33>/Logic'
   *   '<S34>/Logic'
   *   '<S35>/Logic'
   *   '<S36>/Logic'
   *   '<S37>/Logic'
   *   '<S38>/Logic'
   *   '<S39>/Logic'
   *   '<S69>/Logic'
   *   '<S58>/Logic'
   */
  Boolean pooled9[16];
} ConstParam_HPPmpVlvCmdLrn;

/* Real-time Model Data Structure */
struct RT_MODEL_HPPmpVlvCmdLrn {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    Boolean firstInitCondFlag;
  } Timing;
};

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_UNSPECIFIED
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_HPPmpVlvCmdLrn HPPmpVlvCmdLrn_B;

/* Block states (auto storage) */
extern D_Work_HPPmpVlvCmdLrn HPPmpVlvCmdLrn_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_HPPmpVlvCmdLrn HPPmpVlvCmdLrn_ConstP;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define HPPMPVLVCMDLRN_START_SEC_CODE
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Model entry point functions */
extern void HPPmpVlvCmdLrn_initialize(void);
extern void PFuCtl_EveSpl_HPPmpVlvCmdLrn(void);
extern void PFuCtl_EveSpl_HPPmpVlvCmdLrn_Disable(void);
extern void PFuCtl_EveRst_HPPmpVlvCmdLrn(void);

#define HPPMPVLVCMDLRN_STOP_SEC_CODE
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_UNSPECIFIED
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Real-time Model object */
extern struct RT_MODEL_HPPmpVlvCmdLrn *HPPmpVlvCmdLrn_M;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpVlvCmdLrn_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define HPPMPVLVCMDLRN_START_SEC_CALIB_32BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 10000.0                                                           */
extern CONST(UInt32, HPPMPVLVCMDLRN_CALIB) PFuCtl_tiTransLrn_C;

/* Type:    UInt32                                                          */
/* Slope:   0.001                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 10000.0                                                           */
extern CONST(UInt32, HPPMPVLVCMDLRN_CALIB) PFuCtl_tiTransPrail_M[81];

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_32BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define HPPMPVLVCMDLRN_START_SEC_CALIB_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Type:    SInt16                                                           */
/* Units:   su                                                                */
/* PhysMin: -250.0                                                            */
/* PhysMax: 250.0                                                             */
extern CONST(SInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_FaildPmpStk_C;

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_NrAppl_T[16];

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_NrLrnCond_C;

/* Type:    UInt16                                                          */
/* Slope:   1.0                                                               */
/* Bias:    -250.0                                                            */
/* Units:   su                                                                */
/* PhysMin: -250.0                                                            */
/* PhysMax: 250.0                                                             */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_OfsNrProfCmd_M[256];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_mFuInjEstim_A[16];

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngDiff_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngHiLrnThdHi_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngHiLrnThdLo_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngLoLrnThdHi_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEngLoLrnThdLo_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_nEng_tiTrans_A[9];

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesDiff_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesHiLrnThdHi_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesHiLrnThdLo_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesLoLrnThdHi_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pDsThrMesLoLrnThdLo_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pFuRailMesDiff_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pFuReqDiff_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pPrailDiffThd_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pPrailHiDiffThdPmpStk_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pPrailLoDiffThdPmpStk_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pPrailSpDiffThdHi_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_pRailSpDifAbs_A[9];

/* Type:    UInt16                                                          */
/* Slope:   0.0236                                                            */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1546.626                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattDiff_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0236                                                            */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1546.626                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattHiLrnThdHi_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0236                                                            */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1546.626                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattHiLrnThdLo_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0236                                                            */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1546.626                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattLoLrnThdHi_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0236                                                            */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1546.626                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattLoLrnThdLo_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0236                                                            */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1546.626                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBattLrn_A[16];

/* Type:    UInt16                                                          */
/* Slope:   0.0236                                                            */
/* Bias:    0.0                                                               */
/* Units:   V                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1546.626                                                          */
extern CONST(UInt16, HPPMPVLVCMDLRN_CALIB) PFuCtl_uBatt_A[16];

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPPMPVLVCMDLRN_START_SEC_CALIB_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfCor_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfETB_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfiNoIdle_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfilInit_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_CmdProfilTst_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_FaildCndProfilInc_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_LrnPmpCmdProfMax_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_LrnPmpCmdProfMin_C;

/* Type:    UInt8                                                           */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_NoSplRazFailPmpStk_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_NrSpilEvePerCycle_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_PmpCmdDftProfil_T[16];

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_PmpCmdProfDft_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_PmpCmdProfMax_C;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_PmpCmdProfMin_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 100.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tAirHiLrnThdHi_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 100.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tAirHiLrnThdLo_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 100.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tAirLoLrnThdHi_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 100.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tAirLoLrnThdLo_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tCoMesHiLrnThdHi_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tCoMesHiLrnThdLo_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tCoMesLoLrnThdHi_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) PFuCtl_tCoMesLoLrnThdLo_C;

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define HPPMPVLVCMDLRN_START_SEC_CALIB_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPVLVCMDLRN_CALIB) PFuCtl_bAcvETBHPPmpVlvCmdLrn_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPVLVCMDLRN_CALIB) PFuCtl_bForcAcvLrn_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, HPPMPVLVCMDLRN_CALIB) PFuCtl_bForcIntLrn_C;

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_ctNrLrnInProgs;

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_ctNrLrnVld;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 250.0                                                             */
extern VAR(UInt8, HPPMPVLVCMDLRN_VAR) PFuCtl_NrProfCmd;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvHPPmpVlvLrnCond;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvLowNoiseZone;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvLrnInProgs;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bFaildPmpStk;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnVld;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S30>/LO3' : Unused code path elimination
 * Block '<S31>/LO3' : Unused code path elimination
 * Block '<S32>/LO3' : Unused code path elimination
 * Block '<S33>/LO3' : Unused code path elimination
 * Block '<S34>/LO3' : Unused code path elimination
 * Block '<S35>/LO3' : Unused code path elimination
 * Block '<S36>/LO3' : Unused code path elimination
 * Block '<S37>/LO3' : Unused code path elimination
 * Block '<S38>/LO3' : Unused code path elimination
 * Block '<S39>/LO3' : Unused code path elimination
 * Block '<S54>/Data Type Propagation' : Unused code path elimination
 * Block '<S54>/Data Type Propagation1' : Unused code path elimination
 * Block '<S56>/Data Type Propagation' : Unused code path elimination
 * Block '<S56>/Data Type Conversion' : Unused code path elimination
 * Block '<S56>/Data Type Conversion1' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S47>/x1' : Unused code path elimination
 * Block '<S47>/x2' : Unused code path elimination
 * Block '<S58>/LO3' : Unused code path elimination
 * Block '<S50>/Constant1' : Unused code path elimination
 * Block '<S50>/Switch3' : Unused code path elimination
 * Block '<S51>/Constant1' : Unused code path elimination
 * Block '<S51>/Switch3' : Unused code path elimination
 * Block '<S52>/Constant1' : Unused code path elimination
 * Block '<S52>/Switch3' : Unused code path elimination
 * Block '<S69>/LO3' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Relational Operator' : Unused code path elimination
 * Block '<S73>/Relational Operator1' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Propagation' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S80>/x1' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S100>/TABLE' : Unused code path elimination
 * Block '<S100>/TABLE1' : Unused code path elimination
 * Block '<S100>/TABLE2' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Relational Operator' : Unused code path elimination
 * Block '<S101>/Relational Operator1' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Propagation' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S102>/x1' : Unused code path elimination
 * Block '<S11>/PFuCtl_uBattLrn_A' : Unused code path elimination
 * Block '<S11>/PFuCtl_uBatt_A' : Unused code path elimination
 * Block '<S54>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S43>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S85>/Conversion' : Eliminate redundant data type conversion
 * Block '<S86>/Conversion' : Eliminate redundant data type conversion
 * Block '<S81>/Switch' : Eliminated due to constant selection input
 * Block '<S100>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S100>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S104>/Conversion' : Eliminate redundant data type conversion
 * Block '<S105>/Conversion' : Eliminate redundant data type conversion
 * Block '<S103>/Switch' : Eliminated due to constant selection input
 * Block '<S81>/Add3' : Unused code path elimination
 * Block '<S81>/Add4' : Unused code path elimination
 * Block '<S81>/Constant' : Unused code path elimination
 * Block '<S81>/Relational Operator' : Unused code path elimination
 * Block '<S81>/Switch1' : Unused code path elimination
 * Block '<S81>/offset2' : Unused code path elimination
 * Block '<S81>/offset3' : Unused code path elimination
 * Block '<S81>/offset4' : Unused code path elimination
 * Block '<S103>/Add3' : Unused code path elimination
 * Block '<S103>/Add4' : Unused code path elimination
 * Block '<S103>/Constant' : Unused code path elimination
 * Block '<S103>/Relational Operator' : Unused code path elimination
 * Block '<S103>/Switch1' : Unused code path elimination
 * Block '<S103>/offset2' : Unused code path elimination
 * Block '<S103>/offset3' : Unused code path elimination
 * Block '<S103>/offset4' : Unused code path elimination
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
 * hilite_system('HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn')    - opens subsystem HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn
 * hilite_system('HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : HPPmpVlvCmdLrn_AUTOCODE
 * '<S1>'   : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn
 * '<S4>'   : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F01_Init
 * '<S5>'   : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn
 * '<S6>'   : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn
 * '<S7>'   : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F01_HPPmpCmdLrnETB
 * '<S8>'   : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn
 * '<S9>'   : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition
 * '<S10>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning
 * '<S11>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F03_appl_Lrn
 * '<S12>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F04_Counter
 * '<S13>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/UnitDelay1
 * '<S14>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/UnitDelay8
 * '<S15>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/UnitDelay9
 * '<S16>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition
 * '<S17>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F02_Interruption_condition
 * '<S18>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition
 * '<S19>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/UnitDelay3
 * '<S20>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys1
 * '<S21>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys2
 * '<S22>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys3
 * '<S23>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys4
 * '<S24>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys5
 * '<S25>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys
 * '<S26>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys1
 * '<S27>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys2
 * '<S28>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys3
 * '<S29>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys4
 * '<S30>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys1/BasculeRS
 * '<S31>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys2/BasculeRS
 * '<S32>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys3/BasculeRS
 * '<S33>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys4/BasculeRS
 * '<S34>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/NegHys5/BasculeRS
 * '<S35>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys/BasculeRS
 * '<S36>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys1/BasculeRS
 * '<S37>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys2/BasculeRS
 * '<S38>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys3/BasculeRS
 * '<S39>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F01_Environmental_Activation_condition/PosHys4/BasculeRS
 * '<S40>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F02_Interruption_condition/F01_Learning_EnvCond
 * '<S41>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F02_Interruption_condition/F02_Interruption_Condition
 * '<S42>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition
 * '<S43>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F02_Learning_in_progress
 * '<S44>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F03_Activation_inc_press_test
 * '<S45>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F04_Deactivation_inc_press_test
 * '<S46>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/F01_Sample_time
 * '<S47>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/LookUp_2D
 * '<S48>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/PosHys
 * '<S49>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/Rising_edge
 * '<S50>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER
 * '<S51>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER1
 * '<S52>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER2
 * '<S53>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/UnitDelay1
 * '<S54>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/F01_Sample_time/Subsystem
 * '<S55>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/F01_Sample_time/multiplication_411
 * '<S56>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/F01_Sample_time/Subsystem/Data Type Police Only single
 * '<S57>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/F01_Sample_time/Subsystem/If Action Subsystem3
 * '<S58>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/PosHys/BasculeRS
 * '<S59>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/Rising_edge/SubSystem
 * '<S60>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER/SubSystem
 * '<S61>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER/SubSystem1
 * '<S62>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER/SubSystem2
 * '<S63>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER1/SubSystem
 * '<S64>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER1/SubSystem1
 * '<S65>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER1/SubSystem2
 * '<S66>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER2/SubSystem
 * '<S67>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER2/SubSystem1
 * '<S68>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F01_Activation_Deactivation_Condition/TIMER2/SubSystem2
 * '<S69>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F02_Learning_in_progress/BasculeRS1
 * '<S70>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F02_Learning_in_progress/F01_ct_nbr_Lrn
 * '<S71>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F02_Learning_in_progress/F02_Reinit_ct
 * '<S72>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F01_Learning_Activation_Condition/F03_Consolidation_Activation_condition/F02_Learning_in_progress/UnitDelay2
 * '<S73>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/Clamp
 * '<S74>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F01_Buffer
 * '<S75>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F02_Iteration_profil
 * '<S76>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F03_Failed_Pump_Stroke
 * '<S77>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F03b_Failed_pump_strokes
 * '<S78>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F03c_learning_Interrupt
 * '<S79>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess
 * '<S80>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/LookUp_1D
 * '<S81>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/SingleToFixdt
 * '<S82>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/UnitDelay1
 * '<S83>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/UnitDelay2
 * '<S84>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/UnitDelay3
 * '<S85>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/Clamp/Data Type Conversion Inherited
 * '<S86>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/Clamp/Data Type Conversion Inherited1
 * '<S87>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/Clamp/Saturation Dynamic
 * '<S88>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F01_Buffer/UnitDelay1
 * '<S89>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F01_Buffer/UnitDelay2
 * '<S90>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F01_Buffer/UnitDelay4
 * '<S91>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/BasculeRS1
 * '<S92>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/falling_edge
 * '<S93>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/falling_edge1
 * '<S94>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/rising_edge1
 * '<S95>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/rising_edge2
 * '<S96>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/falling_edge/SubSystem
 * '<S97>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/falling_edge1/SubSystem
 * '<S98>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/rising_edge1/SubSystem
 * '<S99>'  : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F02_Learning/F04_LearningSuccess/rising_edge2/SubSystem
 * '<S100>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F03_appl_Lrn/Carto_2D
 * '<S101>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F03_appl_Lrn/Clamp
 * '<S102>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F03_appl_Lrn/PFuCtl_PmpCmdDftProfil_T
 * '<S103>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F03_appl_Lrn/SingleToFixdt
 * '<S104>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F03_appl_Lrn/Clamp/Data Type Conversion Inherited
 * '<S105>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F03_appl_Lrn/Clamp/Data Type Conversion Inherited1
 * '<S106>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F03_appl_Lrn/Clamp/Saturation Dynamic
 * '<S107>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F04_Counter/UnitDelay1
 * '<S108>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F04_Counter/UnitDelay6
 * '<S109>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F04_Counter/rising_edge1
 * '<S110>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F04_Counter/rising_edge2
 * '<S111>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F04_Counter/rising_edge1/SubSystem
 * '<S112>' : HPPmpVlvCmdLrn_AUTOCODE/HPPmpVlvCmdLrn/F02_HPPmpVlvCmdLrn/F00_HPPmpVlvCmdLrn/F02_HPPmpCmdLrn/F04_Counter/rising_edge2/SubSystem
 */

/*-
 * Requirements for '<Root>': HPPmpVlvCmdLrn
 */
#endif                                 /* RTW_HEADER_HPPmpVlvCmdLrn_h_ */

/*-------------------------------- end of file -------------------------------*/
