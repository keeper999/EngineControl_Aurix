/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : KnkLdLim                                                */
/* !Description     : LOAD LIMITATION IN KNOCK SITUATION                      */
/*                                                                            */
/* !Module          : KnkLdLim                                                */
/*                                                                            */
/* !File            : KnkLdLim.h                                              */
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
/*   Code generated on: Thu Mar 28 15:46:24 2013                              */
/*   Model name       : KnkLdLim_AUTOCODE.mdl                                 */
/*   Model version    : 1.206                                                 */
/*   Root subsystem   : /KnkLdLim                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKLDLIM/KnkLdLim$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   etsasson                               $$Date::   29 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_KnkLdLim_h_
#define RTW_HEADER_KnkLdLim_h_
#ifndef KnkLdLim_COMMON_INCLUDES_
# define KnkLdLim_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "Std_Types.h"
#include "KnkLdLim_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_SATURATE.h"
#endif                                 /* KnkLdLim_COMMON_INCLUDES_ */

#include "KnkLdLim_types.h"

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
  Float32 DataTypeConversion;         /* '<S19>/Data Type Conversion' */
  UInt16 VEMS_vidGET1;               /* '<S6>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET2;               /* '<S6>/VEMS_vidGET2' */
  Boolean VEMS_vidGET4[4];           /* '<S6>/VEMS_vidGET4' */
  Boolean VEMS_vidGET[4];            /* '<S6>/VEMS_vidGET' */
  Boolean OU4;                       /* '<S10>/OU4' */
  Boolean Switch;                    /* '<S10>/Switch' */
  UInt8 VEMS_vidGET6[6];             /* '<S6>/VEMS_vidGET6' */
  UInt8 VEMS_vidGET3;                /* '<S6>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET5[6];             /* '<S6>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET7;                /* '<S6>/VEMS_vidGET7' */
} BlockIO_KnkLdLim;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay;                  /* '<S20>/UnitDelay' */
  UInt16 UnitDelay_DSTATE;           /* '<S31>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_d;         /* '<S26>/Unit Delay' */
  Boolean UnitDelay_DSTATE_d3;       /* '<S24>/Unit Delay' */
  Boolean UnitDelay_i;               /* '<S20>/UnitDelay1' */
} D_Work_KnkLdLim;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define KNKLDLIM_START_SEC_VAR_UNSPECIFIED
#include "KnkLdLim_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_KnkLdLim KnkLdLim_B;

/* Block states (auto storage) */
extern D_Work_KnkLdLim KnkLdLim_DWork;

#define KNKLDLIM_STOP_SEC_VAR_UNSPECIFIED
#include "KnkLdLim_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define KNKLDLIM_START_SEC_CODE
#include "KnkLdLim_MemMap.h"

/* Model entry point functions */
extern void KnkLdLim_initialize(void);
extern void KnkTreat_EveRst_LdLim(void);
extern void KnkTreat_EveBDC_LdLim(void);

#define KNKLDLIM_STOP_SEC_CODE
#include "KnkLdLim_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define KNKLDLIM_START_SEC_CALIB_16BIT
#include "KnkLdLim_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctKnkDetHiThd_C;

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctKnkDetLoThd_C;

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctSuperKnkDetDec_C;

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctSuperKnkDetHiThd_C;

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 65535.0                                                           */
extern CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_ctSuperKnkDetLoThd_C;

/* Type:    UInt16                                                          */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_nEng_ldLim_A[8];

/* Type:    UInt16                                                          */
/* Slope:   4.5776367187500000E-003                                           */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.9999542236328119E+002                                           */
extern CONST(UInt16, KNKLDLIM_CALIB) KnkMgt_rAirLd_ldLim_A[8];

#define KNKLDLIM_STOP_SEC_CALIB_16BIT
#include "KnkLdLim_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define KNKLDLIM_START_SEC_CALIB_8BIT
#include "KnkLdLim_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.375                                                             */
/* Bias:    -36.0                                                             */
/* Units:   °Vil                                                              */
/* PhysMin: -36.0                                                             */
/* PhysMax: 59.625                                                            */
extern CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_agIgHiThd_KnkLdLim_M[64];

/* Type:    UInt8                                                           */
/* Slope:   0.375                                                             */
/* Bias:    -36.0                                                             */
/* Units:   °Vil                                                              */
/* PhysMin: -36.0                                                             */
/* PhysMax: 59.625                                                            */
extern CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_agIgLoThd_KnkLdLim_M[64];

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_ctKnkDetDec_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_ctKnkDetInc_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_ctSuperKnkDetInc_C;

/* Type:    UInt8                                                           */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, KNKLDLIM_CALIB) KnkMgt_tiFilAgIgKnkCor_C;

#define KNKLDLIM_STOP_SEC_CALIB_8BIT
#include "KnkLdLim_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define KNKLDLIM_START_SEC_CALIB_BOOLEAN
#include "KnkLdLim_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bAcvLdLimAdvCor_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bAcvLdLimKnkDet_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bAcvLdLimSuperKnkDet_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bLdLimAdvCor_knk_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bLdLimAdvCor_superKnk_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bLdLimStra_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, KNKLDLIM_CALIB) KnkMgt_bStraLdLimKnkDet_C;

#define KNKLDLIM_STOP_SEC_CALIB_BOOLEAN
#include "KnkLdLim_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define KNKLDLIM_START_SEC_VAR_BOOLEAN
#include "KnkLdLim_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bAcvTmpLdLimKnkReq;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bAcvTmpLdLimSuperKnkReq;

#define KNKLDLIM_STOP_SEC_VAR_BOOLEAN
#include "KnkLdLim_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S15>/x' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S16>/x' : Unused code path elimination
 * Block '<S27>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S32>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S10>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * hilite_system('KnkLdLim_AUTOCODE/KnkLdLim')    - opens subsystem KnkLdLim_AUTOCODE/KnkLdLim
 * hilite_system('KnkLdLim_AUTOCODE/KnkLdLim/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : KnkLdLim_AUTOCODE
 * '<S1>'   : KnkLdLim_AUTOCODE/KnkLdLim
 * '<S4>'   : KnkLdLim_AUTOCODE/KnkLdLim/F01_Init
 * '<S5>'   : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc
 * '<S6>'   : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc
 * '<S7>'   : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor
 * '<S8>'   : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F02_LoadLimKnk
 * '<S9>'   : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F03_LoadLimSuperKnk
 * '<S10>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F04_LoadLimCoord
 * '<S11>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/Filtre_1er_ordre  avec reset1
 * '<S12>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/Hysteresis
 * '<S13>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/KnkMgt_agIgHiThd_KnkLdLim_M
 * '<S14>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/KnkMgt_agIgLoThd_KnkLdLim_M
 * '<S15>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/KnkMgt_nEng_ldLim_A
 * '<S16>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/KnkMgt_rAirLd_ldLim_A
 * '<S17>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/division_411
 * '<S18>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/rising_edge1
 * '<S19>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/Filtre_1er_ordre  avec reset1/Reset du filtre
 * '<S20>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/Filtre_1er_ordre  avec reset1/UnitDly_ExtIni
 * '<S21>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/Filtre_1er_ordre  avec reset1/filtrage
 * '<S22>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/Hysteresis/If Action Subsystem
 * '<S23>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/Hysteresis/If Action Subsystem1
 * '<S24>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F01_LdLimAdvCor/rising_edge1/SubSystem
 * '<S25>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F02_LoadLimKnk/Hysteresis
 * '<S26>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F02_LoadLimKnk/UnitDelay1
 * '<S27>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F02_LoadLimKnk/multiplication1
 * '<S28>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F02_LoadLimKnk/Hysteresis/If Action Subsystem
 * '<S29>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F02_LoadLimKnk/Hysteresis/If Action Subsystem1
 * '<S30>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F03_LoadLimSuperKnk/Hysteresis
 * '<S31>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F03_LoadLimSuperKnk/UnitDelay2
 * '<S32>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F03_LoadLimSuperKnk/multiplication2
 * '<S33>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F03_LoadLimSuperKnk/Hysteresis/If Action Subsystem
 * '<S34>'  : KnkLdLim_AUTOCODE/KnkLdLim/F02_LoadLimCalc/F02_LoadLimCalc/F03_LoadLimSuperKnk/Hysteresis/If Action Subsystem1
 */

/*-
 * Requirements for '<Root>': KnkLdLim
 *
 * Inherited requirements for '<S1>/F01_Init':
 *  1. SubSystem "F01_Init" !Trace_To : VEMS_E_11_01859_001.01 ;
 *  2. SubSystem "F01_Init" !Trace_To : VEMS_E_11_01859_002.01 ;
 *  3. SubSystem "F01_Init" !Trace_To : VEMS_E_11_01859_003.01 ;
 *  4. SubSystem "F01_Init" !Trace_To : VEMS_E_11_01859_004.01 ;
 *
 * Inherited requirements for '<S1>/F02_LoadLimCalc':
 *  1. SubSystem "F02_LoadLimCalc" !Trace_To : VEMS_E_11_01859_001.01 ;
 *  2. SubSystem "F02_LoadLimCalc" !Trace_To : VEMS_E_11_01859_002.01 ;
 *  3. SubSystem "F02_LoadLimCalc" !Trace_To : VEMS_E_11_01859_003.01 ;
 *  4. SubSystem "F02_LoadLimCalc" !Trace_To : VEMS_E_11_01859_004.01 ;

 */
#endif                                 /* RTW_HEADER_KnkLdLim_h_ */

/*-------------------------------- end of file -------------------------------*/
