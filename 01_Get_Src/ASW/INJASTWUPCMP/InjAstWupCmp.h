/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjAstWupCmp                                            */
/* !Description     : INJECTION CORRECTION IN AFTER START AND WARM UP         */
/*                                                                            */
/* !Module          : InjAstWupCmp                                            */
/*                                                                            */
/* !File            : InjAstWupCmp.h                                          */
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
/*   Code generated on: Mon Feb 18 18:51:55 2013                              */
/*   Model name       : InjAstWupCmp_AUTOCODE.mdl                             */
/*   Model version    : 1.510                                                 */
/*   Root subsystem   : /InjAstWupCmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJASTWUPCMP/InjAstWupCmp.$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   22 Feb 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjAstWupCmp_h_
#define RTW_HEADER_InjAstWupCmp_h_
#ifndef InjAstWupCmp_COMMON_INCLUDES_
# define InjAstWupCmp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "InjAstWupCmp_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MAXf.h"
#include "rt_MIN.h"
#endif                                 /* InjAstWupCmp_COMMON_INCLUDES_ */

#include "InjAstWupCmp_types.h"

/* Includes for objects with custom storage classes. */
#include "GDGAR.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define InjSys_stAstAutn_SC            ((UInt8) 3U)
#define InjSys_stAstSTT_SC             ((UInt8) 2U)
#define InjSys_stAstStrt_SC            ((UInt8) 1U)
#define InjSys_stIni_SC                ((UInt8) 0U)

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
  UInt32 VEMS_vidGET28;              /* '<S8>/VEMS_vidGET28' */
  SInt16 VEMS_vidGET38;               /* '<S8>/VEMS_vidGET38' */
  SInt16 VEMS_vidGET39;               /* '<S8>/VEMS_vidGET39' */
  SInt16 VEMS_vidGET40;               /* '<S8>/VEMS_vidGET40' */
  UInt16 Switch2;                    /* '<S30>/Switch2' */
  UInt16 VEMS_vidGET36;              /* '<S8>/VEMS_vidGET36' */
  SInt16 VEMS_vidGET29;               /* '<S8>/VEMS_vidGET29' */
  SInt16 VEMS_vidGET30;               /* '<S8>/VEMS_vidGET30' */
  UInt16 VEMS_vidGET31[6];           /* '<S8>/VEMS_vidGET31' */
  UInt16 VEMS_vidGET42;              /* '<S8>/VEMS_vidGET42' */
  UInt16 VEMS_vidGET43;              /* '<S8>/VEMS_vidGET43' */
  UInt16 VEMS_vidGET45;              /* '<S8>/VEMS_vidGET45' */
  UInt16 VEMS_vidGET46;              /* '<S8>/VEMS_vidGET46' */
  UInt16 VEMS_vidGET47;              /* '<S8>/VEMS_vidGET47' */
  UInt16 VEMS_vidGET32;              /* '<S8>/VEMS_vidGET32' */
  SInt16 VEMS_vidGET44;               /* '<S8>/VEMS_vidGET44' */
  UInt16 OutDTConv[6];               /* '<S152>/OutDTConv' */
  UInt8 VEMS_vidGET34;               /* '<S8>/VEMS_vidGET34' */
  UInt8 VEMS_vidGET48;               /* '<S8>/VEMS_vidGET48' */
  UInt8 VEMS_vidGET26;               /* '<S8>/VEMS_vidGET26' */
  UInt8 VEMS_vidGET49;               /* '<S8>/VEMS_vidGET49' */
  UInt8 VEMS_vidGET37[6];            /* '<S8>/VEMS_vidGET37' */
  Boolean VEMS_vidGET35;             /* '<S154>/VEMS_vidGET35' */
  Boolean VEMS_vidGET35_b;           /* '<S8>/VEMS_vidGET35' */
  Boolean VEMS_vidGET25;             /* '<S8>/VEMS_vidGET25' */
  Boolean LogicalOperator2;          /* '<S10>/Logical Operator2' */
  Boolean VEMS_vidGET33;             /* '<S8>/VEMS_vidGET33' */
  Boolean VEMS_vidGET27;             /* '<S8>/VEMS_vidGET27' */
  UInt8 VEMS_vidGET41;               /* '<S8>/VEMS_vidGET41' */
} BlockIO_InjAstWupCmp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S138>/Unit Delay' */
  Float32 UnitDelay_DSTATE_k[6];      /* '<S153>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_i;         /* '<S23>/Unit Delay' */
  Boolean UnitDelay_DSTATE_m;        /* '<S31>/Unit Delay' */
  Boolean UnitDelay_DSTATE_ij;       /* '<S19>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S24>/UnitDelay' */
  Boolean UnitDelay_DSTATE_a;        /* '<S137>/Unit Delay' */
  Boolean UnitDelay_DSTATE_b;        /* '<S139>/Unit Delay' */
  Boolean UnitDelay_DSTATE_o;        /* '<S140>/Unit Delay' */
  UInt8 is_active_c2_InjAstWupCmp;   /* '<S35>/F01_Etat_Activations1' */
  UInt8 is_c2_InjAstWupCmp;          /* '<S35>/F01_Etat_Activations1' */
} D_Work_InjAstWupCmp;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState u_Detection_Trig_ZCE;     /* '<S154>/00_Detection' */
} PrevZCSigStates_InjAstWupCmp;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: UnitDelay_X0
   * Referenced by: '<S153>/Unit Delay'
   */
  Float32 UnitDelay_X0[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S54>/Lookup Table (n-D)'
   *   '<S76>/Lookup Table (n-D)'
   *   '<S96>/Lookup Table (n-D)'
   */
  UInt32 pooled4[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S120>/Lookup Table (n-D)'
   *   '<S55>/Lookup Table (n-D)'
   *   '<S77>/Lookup Table (n-D)'
   *   '<S97>/Lookup Table (n-D)'
   */
  UInt32 pooled5[2];

  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S143>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxInde[2];

  /* Computed Parameter: LookupTablenD_maxIn_k
   * Referenced by: '<S144>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxIn_k[2];
} ConstParam_InjAstWupCmp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJASTWUPCMP_START_SEC_VAR_UNSPECIFIED
#include "InjAstWupCmp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InjAstWupCmp InjAstWupCmp_B;

/* Block states (auto storage) */
extern D_Work_InjAstWupCmp InjAstWupCmp_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_InjAstWupCmp InjAstWupCmp_ConstP;

#define INJASTWUPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "InjAstWupCmp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define INJASTWUPCMP_START_SEC_CODE
#include "InjAstWupCmp_MemMap.h"

/* Model entry point functions */
extern void InjAstWupCmp_initialize(void);
extern void InjSys_SdlFast_InjAstWupCmp(void);
extern void InjSys_EveInj_InjAstWupCmp(void);
extern void InjSys_EveRst_InjAstWupCmp(void);

#define INJASTWUPCMP_STOP_SEC_CODE
#include "InjAstWupCmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_32BIT" */
#define INJASTWUPCMP_START_SEC_CALIB_32BIT
#include "InjAstWupCmp_MemMap.h"

/* Type:    UInt32                                                          */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 864000.0                                                          */
extern CONST(UInt32, INJASTWUPCMP_CALIB) InjSys_ti_facAstTiEngStopX_A[8];

#define INJASTWUPCMP_STOP_SEC_CALIB_32BIT
#include "InjAstWupCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define INJASTWUPCMP_START_SEC_CALIB_16BIT
#include "InjAstWupCmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4095.0                                                            */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_ct_facAstInjY_A[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstAutnCorVVT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj0Autn_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj0STT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj0_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj1Autn_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj1STT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj1_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj2Autn_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj2STT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj2_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj3Autn_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj3STT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorInj3_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorTWCHeatHi_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstCorTWCHeatLo_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj0Autn_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj0STT_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj0_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj1Autn_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj1STT_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj1_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj2Autn_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj2STT_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj2_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj3Autn_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj3STT_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstInj3_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstSTTCorVVT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstStrtCorVVT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstTWCHeatHi_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstTWCHeatLo_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstTiEngStopAutn_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstTiEngStopSTT_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facAstTiEngStop_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facCorRichNAirLd_M[216];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facCorRichNTAir_M[162];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facCorRichTAir_T[9];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facHotStrtCorAutn_T[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facHotStrtCorSTT_T[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facHotStrtCor_T[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupCorAirT_T[8];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupCorInj0_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupCorInj1_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupCorInj2_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupCorInj3_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupCorTWCHeatHi_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupCorTWCHeatLo_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupCorVVT_M[64];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupInj0_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupInj1_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupInj2_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupInj3_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupTWCHeatHi_M[96];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_facWupTWCHeatLo_M[96];

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_mAir_facAstCorInjY_A[8];

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_mAir_facWupCorInjY_A[8];

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_nCorRichX_A[18];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_nEng_facAstCorInjX_A[8];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_nEng_facWupCorInjX_A[8];

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt16, INJASTWUPCMP_CALIB) InjSys_rCorRichNAirLdY_A[12];

/* Type:    SInt16                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   K                                                                 */
/* PhysMin: -256.0                                                            */
/* PhysMax: 255.9921875                                                       */
extern CONST(SInt16, INJASTWUPCMP_CALIB) InjSys_tDifCorNTAirY_A[9];

#define INJASTWUPCMP_STOP_SEC_CALIB_16BIT
#include "InjAstWupCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJASTWUPCMP_START_SEC_CALIB_8BIT
#include "InjAstWupCmp_MemMap.h"

/* Type:    SInt8                                                            */
/* Slope:   1.5                                                               */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: -192.0                                                            */
/* PhysMax: 190.5                                                             */
extern CONST(SInt8, INJASTWUPCMP_CALIB) InjSys_agCk_facCorVVTX_A[8];

/* Type:    SInt8                                                            */
/* Slope:   0.75                                                              */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: -96.0                                                             */
/* PhysMax: 95.25                                                             */
extern CONST(SInt8, INJASTWUPCMP_CALIB) InjSys_agCk_facCorVVTY_A[8];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJASTWUPCMP_CALIB) InjSys_tAcvStrtCor_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -50.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 200.0                                                             */
extern CONST(UInt8, INJASTWUPCMP_CALIB) InjSys_tAir_facHotStrtCor_A[8];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -50.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 200.0                                                             */
extern CONST(UInt8, INJASTWUPCMP_CALIB) InjSys_tAir_facWupCorAirT_A[8];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJASTWUPCMP_CALIB) InjSys_tCo_facAstInjX_A[12];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJASTWUPCMP_CALIB) InjSys_tCo_facAstTiEngStopY_A[12];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJASTWUPCMP_CALIB) InjSys_tCo_facWupInjX_A[12];

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 214.0                                                             */
extern CONST(UInt8, INJASTWUPCMP_CALIB) InjSys_tCo_facWupInjY_A[8];

/* Type:    UInt8                                                           */
/* Slope:   0.01171875                                                        */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.0                                                               */
extern CONST(UInt8, INJASTWUPCMP_CALIB) InjSys_tiTauDeacStrtCor_C;

#define INJASTWUPCMP_STOP_SEC_CALIB_8BIT
#include "InjAstWupCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define INJASTWUPCMP_START_SEC_CALIB_BOOLEAN
#include "InjAstWupCmp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJASTWUPCMP_CALIB) InjSys_bAcvInjAstWupCmp_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJASTWUPCMP_CALIB) InjSys_bAcvStrtCor_C;

#define INJASTWUPCMP_STOP_SEC_CALIB_BOOLEAN
#include "InjAstWupCmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJASTWUPCMP_START_SEC_VAR_16BIT
#include "InjAstWupCmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4095.0                                                            */
extern VAR(UInt16, INJASTWUPCMP_VAR) InjSys_ctNbCmbAst;

/* Type:    UInt16                                                          */
/* Slope:   0.000244140625                                                    */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 15.0                                                              */
extern VAR(UInt16, INJASTWUPCMP_VAR) InjSys_prm_facStrtCorCyl[6];

#define INJASTWUPCMP_STOP_SEC_VAR_16BIT
#include "InjAstWupCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJASTWUPCMP_START_SEC_VAR_BOOLEAN
#include "InjAstWupCmp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJASTWUPCMP_VAR) InjSys_bAcvStrtCor;

#define INJASTWUPCMP_STOP_SEC_VAR_BOOLEAN
#include "InjAstWupCmp_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Relational Operator' : Unused code path elimination
 * Block '<S21>/Relational Operator1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Relational Operator' : Unused code path elimination
 * Block '<S22>/Relational Operator1' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Propagation' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S53>/x1' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S54>/x1' : Unused code path elimination
 * Block '<S54>/x2' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S55>/x1' : Unused code path elimination
 * Block '<S55>/x2' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S56>/x' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S57>/x' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S58>/x' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S59>/x' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S75>/x1' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S76>/x1' : Unused code path elimination
 * Block '<S76>/x2' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S77>/x1' : Unused code path elimination
 * Block '<S77>/x2' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S78>/x' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S79>/x' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S80>/x' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S81>/x' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S95>/x1' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S96>/x1' : Unused code path elimination
 * Block '<S96>/x2' : Unused code path elimination
 * Block '<S97>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S97>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S97>/x1' : Unused code path elimination
 * Block '<S97>/x2' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S98>/x' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S99>/x' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S100>/x' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S101>/x' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S119>/x1' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S120>/x1' : Unused code path elimination
 * Block '<S120>/x2' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S121>/x' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S122>/x' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S123>/x' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S124>/x' : Unused code path elimination
 * Block '<S149>/Data Type Duplicate' : Unused code path elimination
 * Block '<S150>/Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/Relational Operator' : Unused code path elimination
 * Block '<S148>/Relational Operator1' : Unused code path elimination
 * Block '<S151>/Data Type Duplicate' : Unused code path elimination
 * Block '<S151>/Data Type Propagation' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S142>/x1' : Unused code path elimination
 * Block '<S143>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S143>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S143>/x1' : Unused code path elimination
 * Block '<S143>/x2' : Unused code path elimination
 * Block '<S144>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S144>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S144>/x1' : Unused code path elimination
 * Block '<S144>/x2' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Switch' : Eliminated due to constant selection input
 * Block '<S33>/Switch' : Eliminated due to constant selection input
 * Block '<S149>/Conversion' : Eliminate redundant data type conversion
 * Block '<S150>/Conversion' : Eliminate redundant data type conversion
 * Block '<S152>/Switch' : Eliminated due to constant selection input
 * Block '<S32>/Add2' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S32>/offset1' : Unused code path elimination
 * Block '<S33>/Add2' : Unused code path elimination
 * Block '<S33>/Constant' : Unused code path elimination
 * Block '<S33>/offset1' : Unused code path elimination
 * Block '<S152>/Add3' : Unused code path elimination
 * Block '<S152>/Add4' : Unused code path elimination
 * Block '<S152>/Constant' : Unused code path elimination
 * Block '<S152>/Relational Operator' : Unused code path elimination
 * Block '<S152>/Switch1' : Unused code path elimination
 * Block '<S152>/offset2' : Unused code path elimination
 * Block '<S152>/offset3' : Unused code path elimination
 * Block '<S152>/offset4' : Unused code path elimination
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
 * hilite_system('InjAstWupCmp_AUTOCODE/InjAstWupCmp')    - opens subsystem InjAstWupCmp_AUTOCODE/InjAstWupCmp
 * hilite_system('InjAstWupCmp_AUTOCODE/InjAstWupCmp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InjAstWupCmp_AUTOCODE
 * '<S1>'   : InjAstWupCmp_AUTOCODE/InjAstWupCmp
 * '<S5>'   : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F01_Initialization
 * '<S6>'   : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp
 * '<S7>'   : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F03_EventDetection
 * '<S8>'   : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp
 * '<S9>'   : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F00_Sync
 * '<S10>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation
 * '<S11>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F02_Specific_VVT_angle
 * '<S12>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start
 * '<S13>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up
 * '<S14>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation
 * '<S15>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice
 * '<S16>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F07_Vectorization
 * '<S17>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F00_Sync/One_Based_Selector
 * '<S18>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter
 * '<S19>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/SubSystem
 * '<S20>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/rising_edge
 * '<S21>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/Clamp
 * '<S22>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/Clamp1
 * '<S23>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/SubSystem
 * '<S24>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/rising_edge
 * '<S25>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/Clamp/Data Type Conversion Inherited
 * '<S26>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/Clamp/Data Type Conversion Inherited1
 * '<S27>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/Clamp/Saturation Dynamic
 * '<S28>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/Clamp1/Data Type Conversion Inherited
 * '<S29>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/Clamp1/Data Type Conversion Inherited1
 * '<S30>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/Counter/Clamp1/Saturation Dynamic
 * '<S31>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F01_Activation/rising_edge/SubSystem
 * '<S32>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F02_Specific_VVT_angle/SingleToFixdt
 * '<S33>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F02_Specific_VVT_angle/SingleToFixdt1
 * '<S34>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F02_Specific_VVT_angle/division_4131
 * '<S35>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F01_Detection_Life_Case
 * '<S36>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start
 * '<S37>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT
 * '<S38>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart
 * '<S39>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F05_Choice_Ast
 * '<S40>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F01_Detection_Life_Case/F01_Etat_Activations1
 * '<S41>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D
 * '<S42>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D1
 * '<S43>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D10
 * '<S44>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D11
 * '<S45>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D2
 * '<S46>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D3
 * '<S47>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D4
 * '<S48>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D5
 * '<S49>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D6
 * '<S50>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D7
 * '<S51>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D8
 * '<S52>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/Interp_2D9
 * '<S53>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/LookUp_1D
 * '<S54>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/LookUp_2D1
 * '<S55>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/LookUp_2D2
 * '<S56>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/PreLookUp_Binary
 * '<S57>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/PreLookUp_Binary1
 * '<S58>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/PreLookUp_Binary2
 * '<S59>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/PreLookUp_Binary3
 * '<S60>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/multiplication_1
 * '<S61>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/multiplication_2
 * '<S62>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/multiplication_3
 * '<S63>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/multiplication_411
 * '<S64>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/multiplication_421
 * '<S65>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/multiplication_431
 * '<S66>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F02_Ast_Nominal_Start/multiplication_441
 * '<S67>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/Interp_2D
 * '<S68>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/Interp_2D1
 * '<S69>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/Interp_2D2
 * '<S70>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/Interp_2D3
 * '<S71>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/Interp_2D4
 * '<S72>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/Interp_2D5
 * '<S73>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/Interp_2D6
 * '<S74>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/Interp_2D7
 * '<S75>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/LookUp_1D
 * '<S76>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/LookUp_2D1
 * '<S77>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/LookUp_2D2
 * '<S78>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/PreLookUp_Binary
 * '<S79>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/PreLookUp_Binary1
 * '<S80>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/PreLookUp_Binary2
 * '<S81>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/PreLookUp_Binary3
 * '<S82>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/multiplication_1
 * '<S83>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/multiplication_2
 * '<S84>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/multiplication_451
 * '<S85>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/multiplication_461
 * '<S86>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F03_Ast_STT/multiplication_471
 * '<S87>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/Interp_2D
 * '<S88>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/Interp_2D1
 * '<S89>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/Interp_2D10
 * '<S90>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/Interp_2D2
 * '<S91>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/Interp_2D3
 * '<S92>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/Interp_2D4
 * '<S93>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/Interp_2D5
 * '<S94>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/Interp_2D9
 * '<S95>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/LookUp_1D
 * '<S96>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/LookUp_2D
 * '<S97>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/LookUp_2D1
 * '<S98>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/PreLookUp_Binary
 * '<S99>'  : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/PreLookUp_Binary1
 * '<S100>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/PreLookUp_Binary2
 * '<S101>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/PreLookUp_Binary3
 * '<S102>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/multiplication_1
 * '<S103>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/multiplication_2
 * '<S104>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/multiplication_4111
 * '<S105>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/multiplication_461
 * '<S106>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F04_Ast_Autonomous_Restart/multiplication_491
 * '<S107>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D1
 * '<S108>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D12
 * '<S109>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D13
 * '<S110>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D14
 * '<S111>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D15
 * '<S112>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D16
 * '<S113>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D2
 * '<S114>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D3
 * '<S115>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D4
 * '<S116>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D5
 * '<S117>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D6
 * '<S118>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/Interp_2D7
 * '<S119>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/LookUp_1D
 * '<S120>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/LookUp_2D1
 * '<S121>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/PreLookUp_Binary
 * '<S122>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/PreLookUp_Binary1
 * '<S123>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/PreLookUp_Binary2
 * '<S124>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/PreLookUp_Binary3
 * '<S125>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/multiplication_1
 * '<S126>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/multiplication_2
 * '<S127>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/multiplication_4141
 * '<S128>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/multiplication_4151
 * '<S129>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/multiplication_4161
 * '<S130>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F04_Warm_Up/multiplication_441
 * '<S131>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/Filter_VEMS
 * '<S132>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/falling_edge
 * '<S133>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/Filter_VEMS/IniCdn
 * '<S134>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/Filter_VEMS/UnitDly_ExtIni1
 * '<S135>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/Filter_VEMS/division_421
 * '<S136>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/Filter_VEMS/multiplication_451
 * '<S137>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/Filter_VEMS/IniCdn/SubSystem
 * '<S138>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/Filter_VEMS/UnitDly_ExtIni1/SubSystem
 * '<S139>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/Filter_VEMS/UnitDly_ExtIni1/SubSystem1
 * '<S140>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F05_Deactivation/falling_edge/SubSystem
 * '<S141>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/BaryCentre_VEMS
 * '<S142>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/LookUp_1D
 * '<S143>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/LookUp_2D1
 * '<S144>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/LookUp_2D2
 * '<S145>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/One_Based_Selector
 * '<S146>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/multiplication_1
 * '<S147>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/multiplication_4141
 * '<S148>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/BaryCentre_VEMS/Clamp
 * '<S149>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S150>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S151>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F06_Fuel_Choice/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S152>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F07_Vectorization/SingleToFixdt
 * '<S153>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F07_Vectorization/UnitDelay1
 * '<S154>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F03_EventDetection/F03_EventDetection
 * '<S155>' : InjAstWupCmp_AUTOCODE/InjAstWupCmp/F03_EventDetection/F03_EventDetection/00_Detection
 */

/*-
 * Requirements for '<Root>': InjAstWupCmp
 */
#endif                                 /* RTW_HEADER_InjAstWupCmp_h_ */

/*-------------------------------- end of file -------------------------------*/
