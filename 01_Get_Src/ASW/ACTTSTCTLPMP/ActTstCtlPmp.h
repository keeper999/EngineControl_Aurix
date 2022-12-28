/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstCtlPmp                                            */
/* !Description     : Test actionneur Electrovanne Pompe à Huile              */
/*                                                                            */
/* !Module          : ActTstCtlPmp                                            */
/*                                                                            */
/* !File            : ActTstCtlPmp.h                                          */
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
/*   Code generated on: Thu Oct 20 10:51:47 2011                              */
/*   Model name       : ActTstCtlPmp_AUTOCODE.mdl                             */
/*   Model version    : 1.27                                                  */
/*   Root subsystem   : /ActTstCtlPmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/ACTTSTCTLPMP/ActTstCtlPmp.h_$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Oct 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ActTstCtlPmp_h_
#define RTW_HEADER_ActTstCtlPmp_h_
#ifndef ActTstCtlPmp_COMMON_INCLUDES_
# define ActTstCtlPmp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "ActTstCtlPmp_import.h"
#include "VEMS.H"
#include "rt_MAX.h"
#endif                                 /* ActTstCtlPmp_COMMON_INCLUDES_ */

#include "ActTstCtlPmp_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define OIL_ACTRTEST_END               ((UInt8) 1U)
#define OIL_ACTRTEST_IDLE              ((UInt8) 2U)
#define OIL_ACTRTEST_MAX               ((UInt8) 4U)
#define OIL_ACTRTEST_MIN               ((UInt8) 8U)

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
  UInt8 VEMS_vidGET;                 /* '<S4>/VEMS_vidGET' */
  Boolean VEMS_vidGET1;              /* '<S4>/VEMS_vidGET1' */
  Boolean Oil_bActrTstInProgs_l;     /* '<S4>/F01_CtlPmpTstChart' */
  Boolean Oil_bCtlPmpTstCmpl_l;      /* '<S4>/F01_CtlPmpTstChart' */
  UInt8 Oil_rSpPosnActrTst_a;        /* '<S4>/F01_CtlPmpTstChart' */
} BlockIO_ActTstCtlPmp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 is_active_c2_ActTstCtlPmp;   /* '<S4>/F01_CtlPmpTstChart' */
  UInt8 is_c2_ActTstCtlPmp;          /* '<S4>/F01_CtlPmpTstChart' */
  UInt8 is_TestEnCours;              /* '<S4>/F01_CtlPmpTstChart' */
} D_Work_ActTstCtlPmp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTTSTCTLPMP_START_SEC_VAR_UNSPECIFIED
#include "ActTstCtlPmp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_ActTstCtlPmp ActTstCtlPmp_B;

/* Block states (auto storage) */
extern D_Work_ActTstCtlPmp ActTstCtlPmp_DWork;

#define ACTTSTCTLPMP_STOP_SEC_VAR_UNSPECIFIED
#include "ActTstCtlPmp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define ACTTSTCTLPMP_START_SEC_CODE
#include "ActTstCtlPmp_MemMap.h"

/* Model entry point functions */
extern void ActTstCtlPmp_initialize(void);
extern void Oil_SdlMid_ActrTstCtlPmp(void);
extern void Oil_EveRst_ActrTstCtlPmp(void);

#define ACTTSTCTLPMP_STOP_SEC_CODE
#include "ActTstCtlPmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define ACTTSTCTLPMP_START_SEC_CALIB_16BIT
#include "ActTstCtlPmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt16, ACTTSTCTLPMP_CALIB) ActrTstCtlPmp_OffTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt16, ACTTSTCTLPMP_CALIB) ActrTstCtlPmp_OnTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTTSTCTLPMP_CALIB) ActrTstCtlPmp_Tempo_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTTSTCTLPMP_CALIB) ActrTstCtlPmp_TotTime_C;

#define ACTTSTCTLPMP_STOP_SEC_CALIB_16BIT
#include "ActTstCtlPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define ACTTSTCTLPMP_START_SEC_CALIB_8BIT
#include "ActTstCtlPmp_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.390625                                                          */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 99.609375                                                         */
extern CONST(UInt8, ACTTSTCTLPMP_CALIB) Oil_rSpPosnActrTstPos1_C;

/* Type:    UInt8                                                           */
/* Slope:   0.390625                                                          */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 99.609375                                                         */
extern CONST(UInt8, ACTTSTCTLPMP_CALIB) Oil_rSpPosnActrTstPos2_C;

#define ACTTSTCTLPMP_STOP_SEC_CALIB_8BIT
#include "ActTstCtlPmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define ACTTSTCTLPMP_START_SEC_VAR_BOOLEAN
#include "ActTstCtlPmp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTTSTCTLPMP_VAR) Oil_bActrTstInProgs;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTTSTCTLPMP_VAR) Oil_bCtlPmpTstCmpl;

#define ACTTSTCTLPMP_STOP_SEC_VAR_BOOLEAN
#include "ActTstCtlPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define ACTTSTCTLPMP_START_SEC_VAR_8BIT
#include "ActTstCtlPmp_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.390625                                                          */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 99.609375                                                         */
extern VAR(UInt8, ACTTSTCTLPMP_VAR) Oil_rSpPosnActrTst;

#define ACTTSTCTLPMP_STOP_SEC_VAR_8BIT
#include "ActTstCtlPmp_MemMap.h"

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
 * hilite_system('ActTstCtlPmp_AUTOCODE/ActTstCtlPmp')    - opens subsystem ActTstCtlPmp_AUTOCODE/ActTstCtlPmp
 * hilite_system('ActTstCtlPmp_AUTOCODE/ActTstCtlPmp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ActTstCtlPmp_AUTOCODE
 * '<S1>'   : ActTstCtlPmp_AUTOCODE/ActTstCtlPmp
 * '<S4>'   : ActTstCtlPmp_AUTOCODE/ActTstCtlPmp/F01_CtlPmpTst
 * '<S5>'   : ActTstCtlPmp_AUTOCODE/ActTstCtlPmp/F01_CtlPmpTst/F01_CtlPmpTstChart
 */

/*-
 * Requirements for '<Root>': ActTstCtlPmp
 */
#endif                                 /* RTW_HEADER_ActTstCtlPmp_h_ */

/*-------------------------------- end of file -------------------------------*/
