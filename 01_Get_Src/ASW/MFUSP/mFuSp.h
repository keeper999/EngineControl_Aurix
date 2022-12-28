/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuSp                                                   */
/* !Description     : INJECTION MASS PER CYLINDER                             */
/*                                                                            */
/* !Module          : mFuSp                                                   */
/*                                                                            */
/* !File            : mFuSp.h                                                 */
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
/*   Code generated on: Wed Jul 17 12:40:01 2013                              */
/*   Model name       : mFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.274                                                 */
/*   Root subsystem   : /mFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUSP/mFuSp.h_v           $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   22 Jul 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_mFuSp_h_
#define RTW_HEADER_mFuSp_h_
#ifndef mFuSp_COMMON_INCLUDES_
# define mFuSp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "mFuSp_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MIN.h"
#endif                                 /* mFuSp_COMMON_INCLUDES_ */

#include "mFuSp_types.h"

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
  Float32 INIT_OUTPUT;                /* '<S17>/INIT_OUTPUT' */
  Float32 Sum1;                       /* '<S16>/Sum1' */
  UInt16 VEMS_vidGET8;               /* '<S9>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET;                /* '<S9>/VEMS_vidGET' */
  UInt16 VEMS_vidGET15;              /* '<S9>/VEMS_vidGET15' */
  UInt16 VEMS_vidGET3[6];            /* '<S9>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET4[6];            /* '<S9>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET1;               /* '<S9>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET2;               /* '<S9>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET9;               /* '<S9>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET12[6];           /* '<S9>/VEMS_vidGET12' */
  UInt16 VEMS_vidGET17[6];           /* '<S9>/VEMS_vidGET17' */
  UInt16 VEMS_vidGET18[6];           /* '<S9>/VEMS_vidGET18' */
  UInt16 VEMS_vidGET13[6];           /* '<S9>/VEMS_vidGET13' */
  UInt16 VEMS_vidGET16[6];           /* '<S9>/VEMS_vidGET16' */
  SInt16 VEMS_vidGET19;               /* '<S9>/VEMS_vidGET19' */
  UInt16 Assignment1[6];             /* '<S56>/Assignment1' */
  UInt16 Selector1;                  /* '<S56>/Selector1' */
  UInt16 Merge3[2];                  /* '<S9>/Merge3' */
  UInt16 VEMS_vidGET2_n[6];          /* '<S59>/VEMS_vidGET2' */
  UInt16 Switch[6];                  /* '<S59>/Switch' */
  UInt16 Selector3;                  /* '<S59>/Selector3' */
  UInt16 Assignment3[6];             /* '<S56>/Assignment3' */
  UInt16 VEMS_vidGET3_h[6];          /* '<S59>/VEMS_vidGET3' */
  UInt16 Assignment[6];              /* '<S59>/Assignment' */
  UInt8 VEMS_vidGET1_f;              /* '<S56>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_e;               /* '<S56>/VEMS_vidGET' */
  UInt8 VEMS_vidGET11;               /* '<S9>/VEMS_vidGET11' */
  UInt8 VEMS_vidGET10[6];            /* '<S9>/VEMS_vidGET10' */
  UInt8 VEMS_vidGET6;                /* '<S9>/VEMS_vidGET6' */
  UInt8 VEMS_vidGET5;                /* '<S9>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET_o;               /* '<S59>/VEMS_vidGET' */
  UInt8 VEMS_vidGET1_p;              /* '<S59>/VEMS_vidGET1' */
  Boolean VEMS_vidGET7;              /* '<S9>/VEMS_vidGET7' */
  Boolean VEMS_vidGET20;             /* '<S9>/VEMS_vidGET20' */
  SInt8 VEMS_vidGET14;                /* '<S9>/VEMS_vidGET14' */
} BlockIO_mFuSp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 Y;                          /* '<S13>/Data Store Memory' */
  UInt8 UnitDelay_DSTATE;            /* '<S13>/Unit Delay' */
} D_Work_mFuSp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define MFUSP_START_SEC_VAR_UNSPECIFIED
#include "mFuSp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_mFuSp mFuSp_B;

/* Block states (auto storage) */
extern D_Work_mFuSp mFuSp_DWork;

#define MFUSP_STOP_SEC_VAR_UNSPECIFIED
#include "mFuSp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define MFUSP_START_SEC_CODE
#include "mFuSp_MemMap.h"

/* Model entry point functions */
extern void mFuSp_initialize(void);
extern void InjSys_SdlFast_mFuSp(void);
extern void InjSys_EveRst_mFuSp(void);
extern void InjSys_EveInj_mFuSp(void);

#define MFUSP_STOP_SEC_CODE
#include "mFuSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define MFUSP_START_SEC_CALIB_16BIT
#include "mFuSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, MFUSP_CALIB) Ext_nEngX_A[16];

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, MFUSP_CALIB) Ext_pDsThrMesSIY_A[16];

/* Type:    UInt16                                                          */
/* Slope:   0.00025                                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 15.0                                                              */
extern CONST(UInt16, MFUSP_CALIB) InjSys_facInjCmpETB_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+001                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_facStoichBasGas_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+001                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_facStoichFlex1_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+001                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_facStoichFlex2_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+001                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_facStoichGsl_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+001                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_facStoichRichGas_C;

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_mETBFuMassSlewRate_C;

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_mETBFuMass_C;

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_mFuMax_C;

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_mFuMin_C;

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern CONST(UInt16, MFUSP_CALIB) InjSys_mFuSpETB_M[256];

#define MFUSP_STOP_SEC_CALIB_16BIT
#include "mFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define MFUSP_START_SEC_CALIB_8BIT
#include "mFuSp_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, MFUSP_CALIB) InjSys_noETBSelMassFuSp_C;

#define MFUSP_STOP_SEC_CALIB_8BIT
#include "mFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define MFUSP_START_SEC_CALIB_BOOLEAN
#include "mFuSp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, MFUSP_CALIB) InjSys_bAcvETBFuMass_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, MFUSP_CALIB) InjSys_bInhCorRichETBFuMass_C;

#define MFUSP_STOP_SEC_CALIB_BOOLEAN
#include "mFuSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define MFUSP_START_SEC_VAR_16BIT
#include "mFuSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, MFUSP_VAR) InjSys_mFuSp;

/* Type:    UInt16                                                          */
/* Slope:   0.00025                                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 15.0                                                              */
extern VAR(UInt16, MFUSP_VAR) InjSys_prm_facInjCmpCyl[6];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, MFUSP_VAR) InjSys_prm_mCanPurg[2];

/* Type:    UInt16                                                          */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.8827379941940308E-004                                           */
extern VAR(UInt16, MFUSP_VAR) InjSys_prm_mFuSpCyl[6];

#define MFUSP_STOP_SEC_VAR_16BIT
#include "mFuSp_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S12>/TABLE' : Unused code path elimination
 * Block '<S12>/TABLE1' : Unused code path elimination
 * Block '<S12>/TABLE2' : Unused code path elimination
 * Block '<S10>/Ext_nEngX_A' : Unused code path elimination
 * Block '<S10>/Ext_pDsThrMesSIY_A' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Relational Operator' : Unused code path elimination
 * Block '<S25>/Relational Operator1' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Relational Operator' : Unused code path elimination
 * Block '<S29>/Relational Operator1' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S38>/Data Type Propagation1' : Unused code path elimination
 * Block '<S49>/Data Type Propagation' : Unused code path elimination
 * Block '<S49>/Data Type Conversion' : Unused code path elimination
 * Block '<S49>/Data Type Conversion1' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Data Type Propagation1' : Unused code path elimination
 * Block '<S51>/Data Type Propagation' : Unused code path elimination
 * Block '<S51>/Data Type Conversion' : Unused code path elimination
 * Block '<S51>/Data Type Conversion1' : Unused code path elimination
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S26>/Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Conversion' : Eliminate redundant data type conversion
 * Block '<S47>/Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S22>/Switch' : Eliminated due to constant selection input
 * Block '<S57>/Switch' : Eliminated due to constant selection input
 * Block '<S58>/Switch' : Eliminated due to constant selection input
 * Block '<S22>/Add3' : Unused code path elimination
 * Block '<S22>/Add4' : Unused code path elimination
 * Block '<S22>/Constant' : Unused code path elimination
 * Block '<S22>/Relational Operator' : Unused code path elimination
 * Block '<S22>/Switch1' : Unused code path elimination
 * Block '<S22>/offset2' : Unused code path elimination
 * Block '<S22>/offset3' : Unused code path elimination
 * Block '<S22>/offset4' : Unused code path elimination
 * Block '<S57>/Add3' : Unused code path elimination
 * Block '<S57>/Add4' : Unused code path elimination
 * Block '<S57>/Constant' : Unused code path elimination
 * Block '<S57>/Relational Operator' : Unused code path elimination
 * Block '<S57>/Switch1' : Unused code path elimination
 * Block '<S57>/offset2' : Unused code path elimination
 * Block '<S57>/offset3' : Unused code path elimination
 * Block '<S57>/offset4' : Unused code path elimination
 * Block '<S58>/Add3' : Unused code path elimination
 * Block '<S58>/Add4' : Unused code path elimination
 * Block '<S58>/Constant' : Unused code path elimination
 * Block '<S58>/Relational Operator' : Unused code path elimination
 * Block '<S58>/Switch1' : Unused code path elimination
 * Block '<S58>/offset2' : Unused code path elimination
 * Block '<S58>/offset3' : Unused code path elimination
 * Block '<S58>/offset4' : Unused code path elimination
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
 * hilite_system('mFuSp_AUTOCODE/mFuSp')    - opens subsystem mFuSp_AUTOCODE/mFuSp
 * hilite_system('mFuSp_AUTOCODE/mFuSp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : mFuSp_AUTOCODE
 * '<S4>'   : mFuSp_AUTOCODE/mFuSp
 * '<S5>'   : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp
 * '<S6>'   : mFuSp_AUTOCODE/mFuSp/F01_InjSys_mFuSpSync
 * '<S7>'   : mFuSp_AUTOCODE/mFuSp/mFuSp_fc_demux2
 * '<S8>'   : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass
 * '<S9>'   : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass
 * '<S10>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F01_mFuSpETB
 * '<S11>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn
 * '<S12>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F01_mFuSpETB/Carto_2D1
 * '<S13>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F01_mFuSpETB/Slew_rate
 * '<S14>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F01_mFuSpETB/multiplication_1
 * '<S15>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F01_mFuSpETB/multiplication_431
 * '<S16>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F01_mFuSpETB/Slew_rate/Slewing
 * '<S17>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F01_mFuSpETB/Slew_rate/initialisation_slewing
 * '<S18>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F01_Air_Filling
 * '<S19>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F02_Canister_Purge
 * '<S20>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F03_Stoichiometric_Coefficient
 * '<S21>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point
 * '<S22>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/SingleToFixdt
 * '<S23>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F02_Canister_Purge/multiplication_411
 * '<S24>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F03_Stoichiometric_Coefficient/BaryCentre_VEMS
 * '<S25>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F03_Stoichiometric_Coefficient/BaryCentre_VEMS/Clamp
 * '<S26>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F03_Stoichiometric_Coefficient/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S27>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F03_Stoichiometric_Coefficient/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S28>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F03_Stoichiometric_Coefficient/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S29>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Clamp
 * '<S30>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/One_Based_Selector
 * '<S31>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/One_Based_Selector1
 * '<S32>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/One_Based_Selector2
 * '<S33>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/One_Based_Selector3
 * '<S34>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/One_Based_Selector4
 * '<S35>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/One_Based_Selector5
 * '<S36>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/One_Based_Selector6
 * '<S37>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/One_Based_Selector7
 * '<S38>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Subsystem
 * '<S39>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Subsystem1
 * '<S40>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/multiplication_1
 * '<S41>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/multiplication_2
 * '<S42>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/multiplication_3
 * '<S43>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/multiplication_4
 * '<S44>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/multiplication_431
 * '<S45>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/multiplication_461
 * '<S46>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Clamp/Data Type Conversion Inherited
 * '<S47>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Clamp/Data Type Conversion Inherited1
 * '<S48>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Clamp/Saturation Dynamic
 * '<S49>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Subsystem/Data Type Police Only single
 * '<S50>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Subsystem/If Action Subsystem3
 * '<S51>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Subsystem1/Data Type Police Only single
 * '<S52>'  : mFuSp_AUTOCODE/mFuSp/F00_InjSys_mFuSp/F01_Calculate_Injection_Mass/F00_Calculate_Injection_Mass/F02_mFuSpClcn/F04_Fuel_Mass_Set_Point/Subsystem1/If Action Subsystem3
 * '<S53>'  : mFuSp_AUTOCODE/mFuSp/F01_InjSys_mFuSpSync/F01_Initialize
 * '<S54>'  : mFuSp_AUTOCODE/mFuSp/F01_InjSys_mFuSpSync/F02_mFuSpSyncEve1
 * '<S55>'  : mFuSp_AUTOCODE/mFuSp/F01_InjSys_mFuSpSync/F02_mFuSpSyncEve2
 * '<S56>'  : mFuSp_AUTOCODE/mFuSp/F01_InjSys_mFuSpSync/F02_mFuSpSyncEve1/F00_mFuSpSyncEve1
 * '<S57>'  : mFuSp_AUTOCODE/mFuSp/F01_InjSys_mFuSpSync/F02_mFuSpSyncEve1/F00_mFuSpSyncEve1/SingleToFixdt
 * '<S58>'  : mFuSp_AUTOCODE/mFuSp/F01_InjSys_mFuSpSync/F02_mFuSpSyncEve1/F00_mFuSpSyncEve1/SingleToFixdt1
 * '<S59>'  : mFuSp_AUTOCODE/mFuSp/F01_InjSys_mFuSpSync/F02_mFuSpSyncEve2/F00_mFuSpSyncEve
 */

/*-
 * Requirements for '<Root>': mFuSp
 */
#endif                                 /* RTW_HEADER_mFuSp_h_ */

/*-------------------------------- end of file -------------------------------*/
