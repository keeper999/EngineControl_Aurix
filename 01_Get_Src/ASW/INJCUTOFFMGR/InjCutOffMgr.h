/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjCutOffMgr                                            */
/* !Description     : GESTION DE LA COUPURE DES INJECTEURS                    */
/*                                                                            */
/* !Module          : InjCutOffMgr                                            */
/*                                                                            */
/* !File            : InjCutOffMgr.h                                          */
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
/*   Code generated on: Mon Mar 25 22:22:41 2013                              */
/*   Model name       : InjCutOffMgr_AUTOCODE.mdl                             */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /InjCutOffMgr                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJCUTOFFMGR/InjCutOffMgr.$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   27 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjCutOffMgr_h_
#define RTW_HEADER_InjCutOffMgr_h_
#ifndef InjCutOffMgr_COMMON_INCLUDES_
# define InjCutOffMgr_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "InjCutOffMgr_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#endif                                 /* InjCutOffMgr_COMMON_INCLUDES_ */

#include "InjCutOffMgr_types.h"

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
  UInt32 VEMS_vidGET8;               /* '<S9>/VEMS_vidGET8' */
  SInt16 VEMS_vidGET25;               /* '<S9>/VEMS_vidGET25' */
  UInt16 VEMS_vidGET;                /* '<S9>/VEMS_vidGET' */
  UInt16 VEMS_vidGET24;              /* '<S9>/VEMS_vidGET24' */
  UInt8 VEMS_vidGET11;               /* '<S9>/VEMS_vidGET11' */
  UInt8 VEMS_vidGET3;                /* '<S9>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET13;               /* '<S9>/VEMS_vidGET13' */
  UInt8 VEMS_vidGET14;               /* '<S9>/VEMS_vidGET14' */
  UInt8 VEMS_vidGET9;                /* '<S9>/VEMS_vidGET9' */
  UInt8 VEMS_vidGET12;               /* '<S9>/VEMS_vidGET12' */
  UInt8 VEMS_vidGET10;               /* '<S9>/VEMS_vidGET10' */
  UInt8 VEMS_vidGET23;               /* '<S9>/VEMS_vidGET23' */
  UInt8 Sum;                         /* '<S20>/Sum' */
  UInt8 Sum1;                        /* '<S20>/Sum1' */
  Boolean VEMS_vidGET_k;             /* '<S6>/VEMS_vidGET' */
  Boolean OU1;                       /* '<S6>/OU1' */
  Boolean TmpSignalConversionAtVEMS_vidSE[6];
  Boolean VEMS_vidGET21;             /* '<S9>/VEMS_vidGET21' */
  Boolean VEMS_vidGET1;              /* '<S9>/VEMS_vidGET1' */
  Boolean VEMS_vidGET5;              /* '<S9>/VEMS_vidGET5' */
  Boolean VEMS_vidGET6;              /* '<S9>/VEMS_vidGET6' */
  Boolean VEMS_vidGET17;             /* '<S9>/VEMS_vidGET17' */
  Boolean VEMS_vidGET2;              /* '<S9>/VEMS_vidGET2' */
  Boolean VEMS_vidGET15;             /* '<S9>/VEMS_vidGET15' */
  Boolean VEMS_vidGET22;             /* '<S9>/VEMS_vidGET22' */
  Boolean VEMS_vidGET4;              /* '<S9>/VEMS_vidGET4' */
  Boolean VEMS_vidGET19;             /* '<S9>/VEMS_vidGET19' */
  Boolean VEMS_vidGET7;              /* '<S9>/VEMS_vidGET7' */
  Boolean VEMS_vidGET27;             /* '<S9>/VEMS_vidGET27' */
  Boolean VEMS_vidGET28;             /* '<S9>/VEMS_vidGET28' */
  Boolean VEMS_vidGET29;             /* '<S9>/VEMS_vidGET29' */
  Boolean VEMS_vidGET30;             /* '<S9>/VEMS_vidGET30' */
  Boolean VEMS_vidGET20;             /* '<S9>/VEMS_vidGET20' */
  Boolean VEMS_vidGET16[4];          /* '<S9>/VEMS_vidGET16' */
  Boolean LogicalOperator3;          /* '<S20>/Logical Operator3' */
  Boolean LogicalOperator5;          /* '<S20>/Logical Operator5' */
  Boolean LogicalOperator7;          /* '<S20>/Logical Operator7' */
  Boolean LogicalOperator8;          /* '<S20>/Logical Operator8' */
  Boolean Switch[6];                 /* '<S20>/Switch' */
  Boolean SignalConversion5;         /* '<S19>/Signal Conversion5' */
  Boolean OU5;                       /* '<S25>/OU5' */
  Boolean OU12;                      /* '<S10>/OU12' */
  Boolean OU6;                       /* '<S10>/OU6' */
  Boolean OU3;                       /* '<S13>/OU3' */
  UInt8 VEMS_vidGET18;               /* '<S9>/VEMS_vidGET18' */
  UInt8 VEMS_vidGET26;               /* '<S9>/VEMS_vidGET26' */
} BlockIO_InjCutOffMgr;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt32 Prelookup_DWORK1;           /* '<S12>/Prelookup' */
  UInt8 UnitDelay_DSTATE;            /* '<S18>/Unit Delay' */
  Boolean UnitDelay_DSTATE_p[6];     /* '<S32>/Unit Delay' */
  Boolean UnitDelay_DSTATE_n[4];     /* '<S28>/Unit Delay' */
} D_Work_InjCutOffMgr;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJCUTOFFMGR_START_SEC_VAR_UNSPECIFIED
#include "InjCutOffMgr_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InjCutOffMgr InjCutOffMgr_B;

/* Block states (auto storage) */
extern D_Work_InjCutOffMgr InjCutOffMgr_DWork;

#define INJCUTOFFMGR_STOP_SEC_VAR_UNSPECIFIED
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define INJCUTOFFMGR_START_SEC_CODE
#include "InjCutOffMgr_MemMap.h"

/* Model entry point functions */
extern void InjCutOffMgr_initialize(void);
extern void InjCutOff_EveStTCr_CutOff(void);
extern void InjCutOff_SdlFast_CutOff(void);
extern void InjCutOff_EveRst_CutOff(void);
extern void InjCutOff_EveInj_CutOff(void);

#define INJCUTOFFMGR_STOP_SEC_CODE
#include "InjCutOffMgr_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define INJCUTOFFMGR_START_SEC_CALIB_16BIT
#include "InjCutOffMgr_MemMap.h"

/* Type:    SInt16                                                           */
/* Slope:   2.3840332031250001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   Kg                                                                */
/* PhysMin: -0.007812                                                         */
/* PhysMax: 7.8117615966796878E-003                                           */
extern CONST(SInt16, INJCUTOFFMGR_CALIB) InjSys_mAirMinInhCutOff_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 655.0                                                             */
extern CONST(UInt16, INJCUTOFFMGR_CALIB) InjSys_tiDlyInjCutOff_T[9];

#define INJCUTOFFMGR_STOP_SEC_CALIB_16BIT
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJCUTOFFMGR_START_SEC_CALIB_8BIT
#include "InjCutOffMgr_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   32.0                                                              */
/* Bias:    0.0                                                               */
/* Units:   tr/min                                                            */
/* PhysMin: 0                                                                 */
/* PhysMax: 8160.0                                                            */
extern CONST(UInt8, INJCUTOFFMGR_CALIB) Fco_regul_rich_regime_thresh;

/* Type:    UInt8                                                           */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.0                                                               */
extern CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_GearEgd_A[6];

/* Type:    UInt8                                                           */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_bInhCylCutOff_T[6];

/* Type:    UInt8                                                           */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_bInhTWCTotCutOff_T[6];

/* Type:    UInt8                                                           */
/* Units:                                                                     */
/* PhysMin: 1.0                                                               */
/* PhysMax: 6.0                                                               */
extern CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_noInNxtCyl_A[6];

/* Type:    UInt8                                                           */
/* Units:                                                                     */
/* PhysMin: 1.0                                                               */
/* PhysMax: 6.0                                                               */
extern CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_noInNxtNxtNxtCyl_T[6];

#define INJCUTOFFMGR_STOP_SEC_CALIB_8BIT
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define INJCUTOFFMGR_START_SEC_CALIB_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjCutOff_bAcvInjCutOffSTTEs_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bAcvPrioProtAC_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bETBAcvTotCutOff_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaSelCutASRSecu_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaSelCutASR_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaSelCutSIP_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaTotCutASRSecu_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaTotCutASR_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaTotCutSIP_C;

#define INJCUTOFFMGR_STOP_SEC_CALIB_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define INJCUTOFFMGR_START_SEC_VAR_8BIT
#include "InjCutOffMgr_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj;

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 6.0                                                               */
extern VAR(UInt8, INJCUTOFFMGR_VAR) InjSys_noCylCutOff;

#define INJCUTOFFMGR_STOP_SEC_VAR_8BIT
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJCUTOFFMGR_START_SEC_VAR_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) Auto_injection;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_inj_ess_1;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_inj_ess_2;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_inj_ess_3;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_inj_ess_4;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) Fco_for_mf_cat_dam_actif;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bFuCutOff;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bInhCutOffAirMin;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bTotCutOff;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_prm_bCylCutOff[6];

#define INJCUTOFFMGR_STOP_SEC_VAR_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S16>/x1' : Unused code path elimination
 * Block '<S31>/BKPT1' : Unused code path elimination
 * Block '<S31>/BKPT2' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/InjSys_noInNxtCyl_A' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S12>/x' : Unused code path elimination
 * Block '<S17>/Switch' : Eliminated due to constant selection input
 * Block '<S10>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S10>/Signal Conversion10' : Eliminate redundant signal conversion block
 * Block '<S31>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Signal Conversion5' : Eliminate redundant signal conversion block
 * Block '<S27>/Switch' : Eliminated due to constant selection input
 * Block '<S20>/Signal Conversion10' : Eliminate redundant signal conversion block
 * Block '<S17>/Add3' : Unused code path elimination
 * Block '<S17>/Add4' : Unused code path elimination
 * Block '<S17>/Constant' : Unused code path elimination
 * Block '<S17>/Relational Operator' : Unused code path elimination
 * Block '<S17>/Switch1' : Unused code path elimination
 * Block '<S17>/offset2' : Unused code path elimination
 * Block '<S17>/offset3' : Unused code path elimination
 * Block '<S17>/offset4' : Unused code path elimination
 * Block '<S27>/Add3' : Unused code path elimination
 * Block '<S27>/Add4' : Unused code path elimination
 * Block '<S27>/Constant' : Unused code path elimination
 * Block '<S27>/Relational Operator' : Unused code path elimination
 * Block '<S27>/Switch1' : Unused code path elimination
 * Block '<S27>/offset2' : Unused code path elimination
 * Block '<S27>/offset3' : Unused code path elimination
 * Block '<S27>/offset4' : Unused code path elimination
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
 * hilite_system('InjCutOffMgr_AUTOCODE/InjCutOffMgr')    - opens subsystem InjCutOffMgr_AUTOCODE/InjCutOffMgr
 * hilite_system('InjCutOffMgr_AUTOCODE/InjCutOffMgr/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InjCutOffMgr_AUTOCODE
 * '<S1>'   : InjCutOffMgr_AUTOCODE/InjCutOffMgr
 * '<S6>'   : InjCutOffMgr_AUTOCODE/InjCutOffMgr/0_Initialisation
 * '<S7>'   : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection
 * '<S8>'   : InjCutOffMgr_AUTOCODE/InjCutOffMgr/2_InjCutOffMgrDftMod
 * '<S9>'   : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection
 * '<S10>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F01_TotCutOff
 * '<S11>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff
 * '<S12>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/PreLookUp_Linear
 * '<S13>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F01_TotCutOff/F01_ReqInhFuCutOff
 * '<S14>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F01_TotCutOff/F02_ForcFuCutOff
 * '<S15>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F01_TotCutOff/F01_ReqInhFuCutOff/InjSys_bInhTWCTotCutOff_T
 * '<S16>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F01_TotCutOff/F01_ReqInhFuCutOff/InjSys_tiDlyInjCutOff_T
 * '<S17>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F01_TotCutOff/F01_ReqInhFuCutOff/SingleToFixdt
 * '<S18>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F01_TotCutOff/F02_ForcFuCutOff/UnitDelay1
 * '<S19>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre
 * '<S20>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F02_FuelCutOffMgr
 * '<S21>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/00_CylCutOffTar
 * '<S22>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/0_Cylindre_1
 * '<S23>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/1_Cylindre_2
 * '<S24>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/2_Cylindre_3
 * '<S25>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/3_Cylindre_4
 * '<S26>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/InjSys_bInhCylCutOff_T
 * '<S27>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/SingleToFixdt1
 * '<S28>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/UnitDelay2
 * '<S29>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/00_CylCutOffTar/1_SubPos
 * '<S30>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/00_CylCutOffTar/2_SubNeg
 * '<S31>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F01_Coupure_par_cylindre/00_CylCutOffTar/Index_1D
 * '<S32>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/1_Gestion_coupure_injection/Gestion_coupure_injection/F02_CylCutOff/F02_FuelCutOffMgr/UnitDelay2
 * '<S33>'  : InjCutOffMgr_AUTOCODE/InjCutOffMgr/2_InjCutOffMgrDftMod/2_InjCutOffMgrDftMod
 */

/*-
 * Requirements for '<Root>': InjCutOffMgr
 */
#endif                                 /* RTW_HEADER_InjCutOffMgr_h_ */

/*-------------------------------- end of file -------------------------------*/
