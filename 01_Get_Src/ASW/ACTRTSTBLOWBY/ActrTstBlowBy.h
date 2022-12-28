/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActrTstBlowBy                                           */
/* !Description     : Test actionneur Blow By                                 */
/*                                                                            */
/* !Module          : ActrTstBlowBy                                           */
/*                                                                            */
/* !File            : ActrTstBlowBy.h                                         */
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
/*   Code generated on: Thu Jan 17 11:16:37 2013                              */
/*   Model name       : ActrTstBlowBy_AUTOCODE.mdl                            */
/*   Model version    : 1.78                                                  */
/*   Root subsystem   : /ActrTstBlowBy                                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/ACTRTSTBLOWBY/ActrTstBlowBy.$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   18 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ActrTstBlowBy_h_
#define RTW_HEADER_ActrTstBlowBy_h_
#ifndef ActrTstBlowBy_COMMON_INCLUDES_
# define ActrTstBlowBy_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "ActrTstBlowBy_import.h"
#include "VEMS.H"
#include "rt_MAX.h"
#endif                                 /* ActrTstBlowBy_COMMON_INCLUDES_ */

#include "ActrTstBlowBy_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define OIL_ACTRTEST_BB1_END           ((UInt8) 1U)
#define OIL_ACTRTEST_BB1_IDLE          ((UInt8) 2U)
#define OIL_ACTRTEST_BB1_MAX           ((UInt8) 4U)
#define OIL_ACTRTEST_BB1_MIN           ((UInt8) 8U)
#define OIL_ACTRTEST_BB2_END           ((UInt8) 1U)
#define OIL_ACTRTEST_BB2_IDLE          ((UInt8) 2U)
#define OIL_ACTRTEST_BB2_MAX           ((UInt8) 4U)
#define OIL_ACTRTEST_BB2_MIN           ((UInt8) 8U)

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
  UInt8 VEMS_vidGET;                 /* '<S5>/VEMS_vidGET' */
  UInt8 VEMS_vidGET_e;               /* '<S4>/VEMS_vidGET' */
  Boolean VEMS_vidGET1;              /* '<S5>/VEMS_vidGET1' */
  Boolean Oil_bBlowBy2ReqActrTst_l;  /* '<S5>/F01_BlowBy2TstChart' */
  Boolean Oil_bActrTstInProgsBB2_m;  /* '<S5>/F01_BlowBy2TstChart' */
  Boolean Oil_bBlowByTstCmpl_l;      /* '<S5>/F01_BlowBy2TstChart' */
  Boolean VEMS_vidGET1_n;            /* '<S4>/VEMS_vidGET1' */
  Boolean Oil_bBlowBy1ReqActrTst_o;  /* '<S4>/F01_BlowBy1TstChart' */
  Boolean Oil_bActrTstInProgsBB1_n;  /* '<S4>/F01_BlowBy1TstChart' */
  Boolean Oil_bBlowByTstCmpl_n;      /* '<S4>/F01_BlowBy1TstChart' */
} BlockIO_ActrTstBlowBy;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 is_active_c1_ActrTstBlowBy;  /* '<S5>/F01_BlowBy2TstChart' */
  UInt8 is_c1_ActrTstBlowBy;         /* '<S5>/F01_BlowBy2TstChart' */
  UInt8 is_TestEnCoursBB2;           /* '<S5>/F01_BlowBy2TstChart' */
  UInt8 is_active_c2_ActrTstBlowBy;  /* '<S4>/F01_BlowBy1TstChart' */
  UInt8 is_c2_ActrTstBlowBy;         /* '<S4>/F01_BlowBy1TstChart' */
  UInt8 is_TestEnCoursBB1;           /* '<S4>/F01_BlowBy1TstChart' */
} D_Work_ActrTstBlowBy;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTRTSTBLOWBY_START_SEC_VAR_UNSPECIFIED
#include "ActrTstBlowBy_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_ActrTstBlowBy ActrTstBlowBy_B;

/* Block states (auto storage) */
extern D_Work_ActrTstBlowBy ActrTstBlowBy_DWork;

#define ACTRTSTBLOWBY_STOP_SEC_VAR_UNSPECIFIED
#include "ActrTstBlowBy_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define ACTRTSTBLOWBY_START_SEC_CODE
#include "ActrTstBlowBy_MemMap.h"

/* Model entry point functions */
extern void ActrTstBlowBy_initialize(void);
extern void Oil_SdlMid_ActrTstBlowBy(void);
extern void Oil_EveRst_ActrTstBlowBy(void);

#define ACTRTSTBLOWBY_STOP_SEC_CODE
#include "ActrTstBlowBy_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define ACTRTSTBLOWBY_START_SEC_CALIB_16BIT
#include "ActrTstBlowBy_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy1_OffTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy1_OnTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy1_Tempo_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy1_TotTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy2_OffTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy2_OnTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy2_Tempo_C;

/* Type:    UInt16                                                          */
/* Slope:   0.01                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTRTSTBLOWBY_CALIB) ActrTstBlowBy2_TotTime_C;

#define ACTRTSTBLOWBY_STOP_SEC_CALIB_16BIT
#include "ActrTstBlowBy_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define ACTRTSTBLOWBY_START_SEC_VAR_BOOLEAN
#include "ActrTstBlowBy_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bActrTstInProgsBB1;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bActrTstInProgsBB2;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bBlowBy1ReqActrTst;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bBlowBy2ReqActrTst;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTRTSTBLOWBY_VAR) Oil_bBlowByTstCmpl;

#define ACTRTSTBLOWBY_STOP_SEC_VAR_BOOLEAN
#include "ActrTstBlowBy_MemMap.h"

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
 * hilite_system('ActrTstBlowBy_AUTOCODE/ActrTstBlowBy')    - opens subsystem ActrTstBlowBy_AUTOCODE/ActrTstBlowBy
 * hilite_system('ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ActrTstBlowBy_AUTOCODE
 * '<S1>'   : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy
 * '<S4>'   : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/F01_BlowBy1Tst
 * '<S5>'   : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/F02_BlowBy2Tst
 * '<S6>'   : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/demux_fc
 * '<S7>'   : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/demux_fc1
 * '<S8>'   : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/F01_BlowBy1Tst/F01_BlowBy1TstChart
 * '<S9>'   : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/F01_BlowBy1Tst/TEST_BLOW_BY_1
 * '<S10>'  : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/F02_BlowBy2Tst/F01_BlowBy2TstChart
 * '<S11>'  : ActrTstBlowBy_AUTOCODE/ActrTstBlowBy/F02_BlowBy2Tst/TEST_BLOW_BY_2
 */

/*-
 * Requirements for '<Root>': ActrTstBlowBy
 */
#endif                                 /* RTW_HEADER_ActrTstBlowBy_h_ */

/*-------------------------------- end of file -------------------------------*/
