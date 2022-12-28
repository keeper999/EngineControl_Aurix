/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuInj                                                  */
/* !Description     : INJECTION MASS PER INJECTION                            */
/*                                                                            */
/* !Module          : mFuInj                                                  */
/*                                                                            */
/* !File            : mFuInj.h                                                */
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
/*   Code generated on: Thu Jul 18 15:02:19 2013                              */
/*   Model name       : mFuInj_AUTOCODE.mdl                                   */
/*   Model version    : 1.302                                                 */
/*   Root subsystem   : /mFuInj                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUINJ/mFuInj.h_v         $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   29 Jul 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_mFuInj_h_
#define RTW_HEADER_mFuInj_h_
#ifndef mFuInj_COMMON_INCLUDES_
# define mFuInj_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "mFuInj_import.h"
#include "VEMS.H"
#include "rt_MIN.h"
#endif                                 /* mFuInj_COMMON_INCLUDES_ */

#include "mFuInj_types.h"

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
  UInt32 OutDTConv;                  /* '<S44>/OutDTConv' */
  UInt16 VEMS_vidGET2[6];            /* '<S11>/VEMS_vidGET2' */
  UInt16 Switch1[6];                 /* '<S34>/Switch1' */
  UInt16 Switch11[6];                /* '<S34>/Switch11' */
  UInt16 Switch14[6];                /* '<S34>/Switch14' */
  UInt16 Switch2[6];                 /* '<S34>/Switch2' */
  UInt16 VEMS_vidGET8[6];            /* '<S52>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET9[6];            /* '<S52>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET11[6];           /* '<S52>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET12[6];           /* '<S52>/VEMS_vidGET12' */
  UInt16 Switch1_m[6];               /* '<S52>/Switch1' */
  UInt16 Switch11_a[6];              /* '<S52>/Switch11' */
  UInt16 Switch14_c[6];              /* '<S52>/Switch14' */
  UInt16 Switch2_j[6];               /* '<S52>/Switch2' */
  UInt16 VEMS_vidGET6;               /* '<S18>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET4[6];            /* '<S11>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5[6];            /* '<S11>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET6_b[6];          /* '<S11>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET7[6];            /* '<S11>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET3[6];            /* '<S11>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET10[6];           /* '<S18>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET8_h[6];          /* '<S18>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET3_o[6];          /* '<S18>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET5_i[6];          /* '<S18>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET7_n[6];          /* '<S18>/VEMS_vidGET7' */
  UInt8 VEMS_vidGET;                 /* '<S11>/VEMS_vidGET' */
  UInt8 VEMS_vidGET1;                /* '<S11>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET2_l;              /* '<S34>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET1_o;              /* '<S34>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET3_k;              /* '<S34>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET1_j;              /* '<S52>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET2_k;              /* '<S52>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET_h;               /* '<S52>/VEMS_vidGET' */
  UInt8 VEMS_vidGET4_l;              /* '<S52>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET3_e;              /* '<S52>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET3_a;              /* '<S17>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET2_b;              /* '<S18>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET1_m;              /* '<S18>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET4_f;              /* '<S18>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET9_e;              /* '<S18>/VEMS_vidGET9' */
  Boolean VEMS_vidGET4_g[6];         /* '<S34>/VEMS_vidGET4' */
  Boolean VEMS_vidGET5_ip[6];        /* '<S34>/VEMS_vidGET5' */
  Boolean VEMS_vidGET6_p[2];         /* '<S52>/VEMS_vidGET6' */
  Boolean VEMS_vidGET10_j;           /* '<S52>/VEMS_vidGET10' */
  Boolean VEMS_vidGET5_e[6];         /* '<S52>/VEMS_vidGET5' */
  Boolean VEMS_vidGET7_p[6];         /* '<S52>/VEMS_vidGET7' */
} BlockIO_mFuInj;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 UnitDelay_DSTATE;            /* '<S81>/Unit Delay' */
  Boolean UnitDelay_DSTATE_n;        /* '<S30>/Unit Delay' */
} D_Work_mFuInj;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/Constant10'
   *   '<S31>/Constant6'
   *   '<S31>/Constant7'
   *   '<S31>/Constant9'
   *   '<S34>/Constant11'
   *   '<S34>/Constant12'
   *   '<S34>/Constant15'
   *   '<S34>/Constant3'
   *   '<S52>/Constant11'
   *   '<S52>/Constant12'
   *   '<S52>/Constant15'
   *   '<S52>/Constant3'
   */
  UInt16 pooled7[6];
} ConstParam_mFuInj;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define MFUINJ_START_SEC_VAR_UNSPECIFIED
#include "mFuInj_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_mFuInj mFuInj_B;

/* Block states (auto storage) */
extern D_Work_mFuInj mFuInj_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_mFuInj mFuInj_ConstP;

#define MFUINJ_STOP_SEC_VAR_UNSPECIFIED
#include "mFuInj_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define MFUINJ_START_SEC_CODE
#include "mFuInj_MemMap.h"

/* Model entry point functions */
extern void mFuInj_initialize(void);
extern void InjSys_SdlFast_mFuInj(void);
extern void InjSys_EveRst_mFuInj(void);
extern void InjSys_EveInj_mFuInj(void);
extern void InjSys_EveCkSnNtAc_mFuInj(void);

#define MFUINJ_STOP_SEC_CODE
#include "mFuInj_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define MFUINJ_START_SEC_CALIB_BOOLEAN
#include "mFuInj_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, MFUINJ_CALIB) InjSys_bAcvInjPatcond_C;

#define MFUINJ_STOP_SEC_CALIB_BOOLEAN
#include "mFuInj_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define MFUINJ_START_SEC_VAR_32BIT
#include "mFuInj_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.00048828125                                                     */
extern VAR(UInt32, MFUINJ_VAR) InjSys_mFuReq;

#define MFUINJ_STOP_SEC_VAR_32BIT
#include "mFuInj_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define MFUINJ_START_SEC_VAR_16BIT
#include "mFuInj_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjH1ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjH2ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjS1ReqCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjS2ReqCyl[6];

#define MFUINJ_STOP_SEC_VAR_16BIT
#include "mFuInj_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Logical Operator2' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate1' : Unused code path elimination
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
 * Block '<S68>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Switch' : Eliminated due to constant selection input
 * Block '<S44>/Switch' : Eliminated due to constant selection input
 * Block '<S45>/Switch' : Eliminated due to constant selection input
 * Block '<S46>/Switch' : Eliminated due to constant selection input
 * Block '<S47>/Switch' : Eliminated due to constant selection input
 * Block '<S48>/Switch' : Eliminated due to constant selection input
 * Block '<S49>/Switch' : Eliminated due to constant selection input
 * Block '<S50>/Switch' : Eliminated due to constant selection input
 * Block '<S51>/Switch' : Eliminated due to constant selection input
 * Block '<S73>/Switch' : Eliminated due to constant selection input
 * Block '<S74>/Switch' : Eliminated due to constant selection input
 * Block '<S75>/Switch' : Eliminated due to constant selection input
 * Block '<S76>/Switch' : Eliminated due to constant selection input
 * Block '<S77>/Switch' : Eliminated due to constant selection input
 * Block '<S78>/Switch' : Eliminated due to constant selection input
 * Block '<S79>/Switch' : Eliminated due to constant selection input
 * Block '<S80>/Switch' : Eliminated due to constant selection input
 * Block '<S43>/Add3' : Unused code path elimination
 * Block '<S43>/Add4' : Unused code path elimination
 * Block '<S43>/Constant' : Unused code path elimination
 * Block '<S43>/Relational Operator' : Unused code path elimination
 * Block '<S43>/Switch1' : Unused code path elimination
 * Block '<S43>/offset2' : Unused code path elimination
 * Block '<S43>/offset3' : Unused code path elimination
 * Block '<S43>/offset4' : Unused code path elimination
 * Block '<S44>/Add3' : Unused code path elimination
 * Block '<S44>/Add4' : Unused code path elimination
 * Block '<S44>/Constant' : Unused code path elimination
 * Block '<S44>/Relational Operator' : Unused code path elimination
 * Block '<S44>/Switch1' : Unused code path elimination
 * Block '<S44>/offset2' : Unused code path elimination
 * Block '<S44>/offset3' : Unused code path elimination
 * Block '<S44>/offset4' : Unused code path elimination
 * Block '<S45>/Add3' : Unused code path elimination
 * Block '<S45>/Add4' : Unused code path elimination
 * Block '<S45>/Constant' : Unused code path elimination
 * Block '<S45>/Relational Operator' : Unused code path elimination
 * Block '<S45>/Switch1' : Unused code path elimination
 * Block '<S45>/offset2' : Unused code path elimination
 * Block '<S45>/offset3' : Unused code path elimination
 * Block '<S45>/offset4' : Unused code path elimination
 * Block '<S46>/Add3' : Unused code path elimination
 * Block '<S46>/Add4' : Unused code path elimination
 * Block '<S46>/Constant' : Unused code path elimination
 * Block '<S46>/Relational Operator' : Unused code path elimination
 * Block '<S46>/Switch1' : Unused code path elimination
 * Block '<S46>/offset2' : Unused code path elimination
 * Block '<S46>/offset3' : Unused code path elimination
 * Block '<S46>/offset4' : Unused code path elimination
 * Block '<S47>/Add3' : Unused code path elimination
 * Block '<S47>/Add4' : Unused code path elimination
 * Block '<S47>/Constant' : Unused code path elimination
 * Block '<S47>/Relational Operator' : Unused code path elimination
 * Block '<S47>/Switch1' : Unused code path elimination
 * Block '<S47>/offset2' : Unused code path elimination
 * Block '<S47>/offset3' : Unused code path elimination
 * Block '<S47>/offset4' : Unused code path elimination
 * Block '<S48>/Add3' : Unused code path elimination
 * Block '<S48>/Add4' : Unused code path elimination
 * Block '<S48>/Constant' : Unused code path elimination
 * Block '<S48>/Relational Operator' : Unused code path elimination
 * Block '<S48>/Switch1' : Unused code path elimination
 * Block '<S48>/offset2' : Unused code path elimination
 * Block '<S48>/offset3' : Unused code path elimination
 * Block '<S48>/offset4' : Unused code path elimination
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
 * Block '<S73>/Add3' : Unused code path elimination
 * Block '<S73>/Add4' : Unused code path elimination
 * Block '<S73>/Constant' : Unused code path elimination
 * Block '<S73>/Relational Operator' : Unused code path elimination
 * Block '<S73>/Switch1' : Unused code path elimination
 * Block '<S73>/offset2' : Unused code path elimination
 * Block '<S73>/offset3' : Unused code path elimination
 * Block '<S73>/offset4' : Unused code path elimination
 * Block '<S74>/Add3' : Unused code path elimination
 * Block '<S74>/Add4' : Unused code path elimination
 * Block '<S74>/Constant' : Unused code path elimination
 * Block '<S74>/Relational Operator' : Unused code path elimination
 * Block '<S74>/Switch1' : Unused code path elimination
 * Block '<S74>/offset2' : Unused code path elimination
 * Block '<S74>/offset3' : Unused code path elimination
 * Block '<S74>/offset4' : Unused code path elimination
 * Block '<S75>/Add3' : Unused code path elimination
 * Block '<S75>/Add4' : Unused code path elimination
 * Block '<S75>/Constant' : Unused code path elimination
 * Block '<S75>/Relational Operator' : Unused code path elimination
 * Block '<S75>/Switch1' : Unused code path elimination
 * Block '<S75>/offset2' : Unused code path elimination
 * Block '<S75>/offset3' : Unused code path elimination
 * Block '<S75>/offset4' : Unused code path elimination
 * Block '<S76>/Add3' : Unused code path elimination
 * Block '<S76>/Add4' : Unused code path elimination
 * Block '<S76>/Constant' : Unused code path elimination
 * Block '<S76>/Relational Operator' : Unused code path elimination
 * Block '<S76>/Switch1' : Unused code path elimination
 * Block '<S76>/offset2' : Unused code path elimination
 * Block '<S76>/offset3' : Unused code path elimination
 * Block '<S76>/offset4' : Unused code path elimination
 * Block '<S77>/Add3' : Unused code path elimination
 * Block '<S77>/Add4' : Unused code path elimination
 * Block '<S77>/Constant' : Unused code path elimination
 * Block '<S77>/Relational Operator' : Unused code path elimination
 * Block '<S77>/Switch1' : Unused code path elimination
 * Block '<S77>/offset2' : Unused code path elimination
 * Block '<S77>/offset3' : Unused code path elimination
 * Block '<S77>/offset4' : Unused code path elimination
 * Block '<S78>/Add3' : Unused code path elimination
 * Block '<S78>/Add4' : Unused code path elimination
 * Block '<S78>/Constant' : Unused code path elimination
 * Block '<S78>/Relational Operator' : Unused code path elimination
 * Block '<S78>/Switch1' : Unused code path elimination
 * Block '<S78>/offset2' : Unused code path elimination
 * Block '<S78>/offset3' : Unused code path elimination
 * Block '<S78>/offset4' : Unused code path elimination
 * Block '<S79>/Add3' : Unused code path elimination
 * Block '<S79>/Add4' : Unused code path elimination
 * Block '<S79>/Constant' : Unused code path elimination
 * Block '<S79>/Relational Operator' : Unused code path elimination
 * Block '<S79>/Switch1' : Unused code path elimination
 * Block '<S79>/offset2' : Unused code path elimination
 * Block '<S79>/offset3' : Unused code path elimination
 * Block '<S79>/offset4' : Unused code path elimination
 * Block '<S80>/Add3' : Unused code path elimination
 * Block '<S80>/Add4' : Unused code path elimination
 * Block '<S80>/Constant' : Unused code path elimination
 * Block '<S80>/Relational Operator' : Unused code path elimination
 * Block '<S80>/Switch1' : Unused code path elimination
 * Block '<S80>/offset2' : Unused code path elimination
 * Block '<S80>/offset3' : Unused code path elimination
 * Block '<S80>/offset4' : Unused code path elimination
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
 * hilite_system('mFuInj_AUTOCODE/mFuInj')    - opens subsystem mFuInj_AUTOCODE/mFuInj
 * hilite_system('mFuInj_AUTOCODE/mFuInj/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : mFuInj_AUTOCODE
 * '<S5>'   : mFuInj_AUTOCODE/mFuInj
 * '<S6>'   : mFuInj_AUTOCODE/mFuInj/F01_mFuInjRunClcn
 * '<S7>'   : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn
 * '<S8>'   : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync
 * '<S9>'   : mFuInj_AUTOCODE/mFuInj/mFuInj_fc_demux
 * '<S10>'  : mFuInj_AUTOCODE/mFuInj/mFuInj_fc_demux_1
 * '<S11>'  : mFuInj_AUTOCODE/mFuInj/F01_mFuInjRunClcn/F01_mFuInjRunClcn
 * '<S12>'  : mFuInj_AUTOCODE/mFuInj/F01_mFuInjRunClcn/F01_mFuInjRunClcn/multiplication_1
 * '<S13>'  : mFuInj_AUTOCODE/mFuInj/F01_mFuInjRunClcn/F01_mFuInjRunClcn/multiplication_411
 * '<S14>'  : mFuInj_AUTOCODE/mFuInj/F01_mFuInjRunClcn/F01_mFuInjRunClcn/multiplication_421
 * '<S15>'  : mFuInj_AUTOCODE/mFuInj/F01_mFuInjRunClcn/F01_mFuInjRunClcn/multiplication_431
 * '<S16>'  : mFuInj_AUTOCODE/mFuInj/F01_mFuInjRunClcn/F01_mFuInjRunClcn/multiplication_441
 * '<S17>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn
 * '<S18>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct
 * '<S19>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/One_Based_Selector
 * '<S20>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/One_Based_Selector1
 * '<S21>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/One_Based_Selector2
 * '<S22>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/One_Based_Selector3
 * '<S23>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/One_Based_Selector4
 * '<S24>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/SR_FlipFlop
 * '<S25>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/multiplication_1
 * '<S26>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/multiplication_451
 * '<S27>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/multiplication_461
 * '<S28>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/multiplication_471
 * '<S29>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/multiplication_481
 * '<S30>'  : mFuInj_AUTOCODE/mFuInj/F02_mFuInjCrkClcn/F02_mFuInjCrkClcn/F01_mFuInjCrkFct/SR_FlipFlop/SubSystem
 * '<S31>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F01_Initialization
 * '<S32>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync
 * '<S33>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync
 * '<S34>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync
 * '<S35>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/Assignment1
 * '<S36>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/Assignment2
 * '<S37>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/Assignment3
 * '<S38>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/Assignment4
 * '<S39>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/Selector1
 * '<S40>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/Selector2
 * '<S41>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/Selector3
 * '<S42>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/Selector5
 * '<S43>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt
 * '<S44>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt1
 * '<S45>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt2
 * '<S46>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt3
 * '<S47>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt4
 * '<S48>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt5
 * '<S49>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt6
 * '<S50>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt7
 * '<S51>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F02_mFuInj_EveSync/F02_mFuInj_EveSync/SingleToFixdt8
 * '<S52>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync
 * '<S53>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment1
 * '<S54>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment10
 * '<S55>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment11
 * '<S56>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment12
 * '<S57>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment13
 * '<S58>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment14
 * '<S59>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment15
 * '<S60>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment16
 * '<S61>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment2
 * '<S62>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment3
 * '<S63>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment4
 * '<S64>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment5
 * '<S65>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment6
 * '<S66>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment7
 * '<S67>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment8
 * '<S68>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Assignment9
 * '<S69>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Selector1
 * '<S70>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Selector2
 * '<S71>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Selector3
 * '<S72>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/Selector4
 * '<S73>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SingleToFixdt1
 * '<S74>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SingleToFixdt2
 * '<S75>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SingleToFixdt3
 * '<S76>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SingleToFixdt4
 * '<S77>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SingleToFixdt5
 * '<S78>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SingleToFixdt6
 * '<S79>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SingleToFixdt7
 * '<S80>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SingleToFixdt8
 * '<S81>'  : mFuInj_AUTOCODE/mFuInj/F03_mFuInjSync/F03_mFuInj_SdlSync/F03_mFuInj_SdlSync/SubSystem
 */

/*-
 * Requirements for '<Root>': mFuInj
 */
#endif                                 /* RTW_HEADER_mFuInj_h_ */

/*-------------------------------- end of file -------------------------------*/
