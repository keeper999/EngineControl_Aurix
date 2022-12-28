/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActrTstHPPmp                                            */
/* !Description     : ACTRTSTHPPmp- HP PUMP ACTUATOR TEST                     */
/*                                                                            */
/* !Module          : ActrTstHPPmp                                            */
/*                                                                            */
/* !File            : ActrTstHPPmp.h                                          */
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
/*   Code generated on: Tue Mar 05 11:01:47 2013                              */
/*   Model name       : ActrTstHPPmp_AUTOCODE.mdl                             */
/*   Model version    : 1.89                                                  */
/*   Root subsystem   : /ActrTstHPPmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/ACTRTSTHPPMP/ActrTstHPPmp$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   08 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ActrTstHPPmp_h_
#define RTW_HEADER_ActrTstHPPmp_h_
#ifndef ActrTstHPPmp_COMMON_INCLUDES_
# define ActrTstHPPmp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "ActrTstHPPmp_import.h"
#include "VEMS.H"
#include "rt_ABS.h"
#include "rt_MAX.h"
#endif                                 /* ActrTstHPPmp_COMMON_INCLUDES_ */

#include "ActrTstHPPmp_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define HPPMP_ACTRTEST_END             ((UInt8) 32U)
#define HPPMP_ACTRTEST_INIT            ((UInt8) 0U)
#define HPPMP_ACTRTEST_PHASE_0         ((UInt8) 1U)
#define HPPMP_ACTRTEST_PHASE_1         ((UInt8) 2U)
#define HPPMP_ACTRTEST_PHASE_1_BIS     ((UInt8) 4U)
#define HPPMP_ACTRTEST_PHASE_2         ((UInt8) 8U)
#define HPPMP_ACTRTEST_PHASE_3         ((UInt8) 16U)

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
  UInt16 VEMS_vidGET1;               /* '<S6>/VEMS_vidGET1' */
  UInt16 ActrTstHPPmp_agWdPmpCmdReq_n;/* '<S7>/HPPmpActrTstChart' */
  UInt8 VEMS_vidGET;                 /* '<S6>/VEMS_vidGET' */
  UInt8 ActrTstHPPmp_stActrTst_h;    /* '<S7>/HPPmpActrTstChart' */
  Boolean VEMS_vidGET2;              /* '<S6>/VEMS_vidGET2' */
  Boolean RelationalOperator3;       /* '<S8>/Relational Operator3' */
  Boolean RelationalOperator4;       /* '<S8>/Relational Operator4' */
  Boolean RelationalOperator1;       /* '<S8>/Relational Operator1' */
  Boolean ActrTstHPPmp_bActrTstInProgs_e;/* '<S7>/HPPmpActrTstChart' */
  Boolean ActrTstHPPmp_bActrTstCmpl_o;/* '<S7>/HPPmpActrTstChart' */
  Boolean ActrTstHPPmp_bInjAuthReq_d;/* '<S7>/HPPmpActrTstChart' */
} BlockIO_ActrTstHPPmp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 is_active_c2_ActrTstHPPmp;   /* '<S7>/HPPmpActrTstChart' */
  UInt8 is_c2_ActrTstHPPmp;          /* '<S7>/HPPmpActrTstChart' */
  UInt8 is_TestEnCours;              /* '<S7>/HPPmpActrTstChart' */
} D_Work_ActrTstHPPmp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTRTSTHPPMP_START_SEC_VAR_UNSPECIFIED
#include "ActrTstHPPmp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_ActrTstHPPmp ActrTstHPPmp_B;

/* Block states (auto storage) */
extern D_Work_ActrTstHPPmp ActrTstHPPmp_DWork;

#define ACTRTSTHPPMP_STOP_SEC_VAR_UNSPECIFIED
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define ACTRTSTHPPMP_START_SEC_CODE
#include "ActrTstHPPmp_MemMap.h"

/* Model entry point functions */
extern void ActrTstHPPmp_initialize(void);
extern void PFuCtl_EveSpl_ActrTstHPPmp(void);
extern void PFuCtl_EveRst_ActrTstHPPmp(void);

#define ACTRTSTHPPMP_STOP_SEC_CODE
#include "ActrTstHPPmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define ACTRTSTHPPMP_START_SEC_CALIB_16BIT
#include "ActrTstHPPmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 655.0                                                             */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_Tempo2_C;

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 655.0                                                             */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_TempoMax_C;

/* Type:    UInt16                                                          */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 655.0                                                             */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_Tempo_Phase1_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_agWdReq_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailPerPmp_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailPresDif2_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailSpThdHi_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailSpThdLo_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_pRailSpThd_C;

#define ACTRTSTHPPMP_STOP_SEC_CALIB_16BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define ACTRTSTHPPMP_START_SEC_CALIB_8BIT
#include "ActrTstHPPmp_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   su                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, ACTRTSTHPPMP_CALIB) ActrTstHPPmp_ctRstActTst_C;

#define ACTRTSTHPPMP_STOP_SEC_CALIB_8BIT
#include "ActrTstHPPmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define ACTRTSTHPPMP_START_SEC_VAR_16BIT
#include "ActrTstHPPmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °vil                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_agWdPmpCmdReq;

#define ACTRTSTHPPMP_STOP_SEC_VAR_16BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define ACTRTSTHPPMP_START_SEC_VAR_8BIT
#include "ActrTstHPPmp_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern VAR(UInt8, ACTRTSTHPPMP_VAR) ActrTstHPPmp_stActrTst;

#define ACTRTSTHPPMP_STOP_SEC_VAR_8BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define ACTRTSTHPPMP_START_SEC_VAR_BOOLEAN
#include "ActrTstHPPmp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bActrTstCmpl;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bActrTstInProgs;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bInjAuthReq;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bItActrTstReq;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bPrailLeak;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTHPPMP_VAR) ActrTstHPPmp_bPrailPresIncFail;

#define ACTRTSTHPPMP_STOP_SEC_VAR_BOOLEAN
#include "ActrTstHPPmp_MemMap.h"

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
 * hilite_system('ActrTstHPPmp_AUTOCODE/ActrTstHPPmp')    - opens subsystem ActrTstHPPmp_AUTOCODE/ActrTstHPPmp
 * hilite_system('ActrTstHPPmp_AUTOCODE/ActrTstHPPmp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ActrTstHPPmp_AUTOCODE
 * '<S1>'   : ActrTstHPPmp_AUTOCODE/ActrTstHPPmp
 * '<S4>'   : ActrTstHPPmp_AUTOCODE/ActrTstHPPmp/F00_HPPmpTst_Init
 * '<S5>'   : ActrTstHPPmp_AUTOCODE/ActrTstHPPmp/F01_HPPmpTst
 * '<S6>'   : ActrTstHPPmp_AUTOCODE/ActrTstHPPmp/F01_HPPmpTst/F01_HPPmpTst
 * '<S7>'   : ActrTstHPPmp_AUTOCODE/ActrTstHPPmp/F01_HPPmpTst/F01_HPPmpTst/F01_HPPmpActrTst
 * '<S8>'   : ActrTstHPPmp_AUTOCODE/ActrTstHPPmp/F01_HPPmpTst/F01_HPPmpTst/F02_Diagnosis
 * '<S9>'   : ActrTstHPPmp_AUTOCODE/ActrTstHPPmp/F01_HPPmpTst/F01_HPPmpTst/F01_HPPmpActrTst/HPPmpActrTstChart
 */

/*-
 * Requirements for '<Root>': ActrTstHPPmp
 */
#endif                                 /* RTW_HEADER_ActrTstHPPmp_h_ */

/*-------------------------------- end of file -------------------------------*/
