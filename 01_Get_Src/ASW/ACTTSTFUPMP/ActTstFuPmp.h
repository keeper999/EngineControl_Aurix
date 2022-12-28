/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstFuPmp                                             */
/* !Description     : Test actionneur Pompe de Gavage                         */
/*                                                                            */
/* !Module          : ActTstFuPmp                                             */
/*                                                                            */
/* !File            : ActTstFuPmp.h                                           */
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
/*   Code generated on: Tue Sep 27 15:48:17 2011                              */
/*   Model name       : ActTstFuPmp_AUTOCODE.mdl                              */
/*   Model version    : 1.65                                                  */
/*   Root subsystem   : /ActTstFuPmp                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUPMP/ACTTSTFUPMP/ActTstFuPmp.h_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Oct 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ActTstFuPmp_h_
#define RTW_HEADER_ActTstFuPmp_h_
#ifndef ActTstFuPmp_COMMON_INCLUDES_
# define ActTstFuPmp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "ActTstFuPmp_import.h"
#include "VEMS.H"
#include "rt_MAX.h"
#endif                                 /* ActTstFuPmp_COMMON_INCLUDES_ */

#include "ActTstFuPmp_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define FUPMP_ACTRTEST_END             ((UInt8) 1U)
#define FUPMP_ACTRTEST_IDLE            ((UInt8) 2U)
#define FUPMP_ACTRTEST_MAX             ((UInt8) 4U)
#define FUPMP_ACTRTEST_MIN             ((UInt8) 8U)

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
  UInt16 FuPmp_rSpPosnActrTst_m;     /* '<S4>/F01_FuTnkPmpChart' */
  UInt8 VEMS_vidGET;                 /* '<S4>/VEMS_vidGET' */
  Boolean VEMS_vidGET1;              /* '<S4>/VEMS_vidGET1' */
  Boolean FuPmp_bFuTnkPmpTstCmpl_g;  /* '<S4>/F01_FuTnkPmpChart' */
  Boolean FuPmp_bActrTstInProgs_a;   /* '<S4>/F01_FuTnkPmpChart' */
} BlockIO_ActTstFuPmp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 is_active_c2_ActTstFuPmp;    /* '<S4>/F01_FuTnkPmpChart' */
  UInt8 is_c2_ActTstFuPmp;           /* '<S4>/F01_FuTnkPmpChart' */
  UInt8 is_TestEnCours;              /* '<S4>/F01_FuTnkPmpChart' */
} D_Work_ActTstFuPmp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTTSTFUPMP_START_SEC_VAR_UNSPECIFIED
#include "ActTstFuPmp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_ActTstFuPmp ActTstFuPmp_B;

/* Block states (auto storage) */
extern D_Work_ActTstFuPmp ActTstFuPmp_DWork;

#define ACTTSTFUPMP_STOP_SEC_VAR_UNSPECIFIED
#include "ActTstFuPmp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define ACTTSTFUPMP_START_SEC_CODE
#include "ActTstFuPmp_MemMap.h"

/* Model entry point functions */
extern void ActTstFuPmp_initialize(void);
extern void FuPmp_SdlMid_ActrTstFuTnkPmp(void);
extern void FuPmp_EveRst_ActrTstFuTnkPmp(void);

#define ACTTSTFUPMP_STOP_SEC_CODE
#include "ActTstFuPmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define ACTTSTFUPMP_START_SEC_CALIB_16BIT
#include "ActTstFuPmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt16, ACTTSTFUPMP_CALIB) ActrTstFuTnkPmp_OffTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt16, ACTTSTFUPMP_CALIB) ActrTstFuTnkPmp_OnTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTTSTFUPMP_CALIB) ActrTstFuTnkPmp_Tempo_C;

/* Type:    UInt16                                                          */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTTSTFUPMP_CALIB) ActrTstFuTnkPmp_TotTime_C;

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 100.0                                                             */
extern CONST(UInt16, ACTTSTFUPMP_CALIB) FuPmp_rSpPosnActrTstPos1_C;

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 100.0                                                             */
extern CONST(UInt16, ACTTSTFUPMP_CALIB) FuPmp_rSpPosnActrTstPos2_C;

#define ACTTSTFUPMP_STOP_SEC_CALIB_16BIT
#include "ActTstFuPmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define ACTTSTFUPMP_START_SEC_VAR_16BIT
#include "ActTstFuPmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 100.0                                                             */
extern VAR(UInt16, ACTTSTFUPMP_VAR) FuPmp_rSpPosnActrTst;

#define ACTTSTFUPMP_STOP_SEC_VAR_16BIT
#include "ActTstFuPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define ACTTSTFUPMP_START_SEC_VAR_BOOLEAN
#include "ActTstFuPmp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTTSTFUPMP_VAR) FuPmp_bActrTstInProgs;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTTSTFUPMP_VAR) FuPmp_bFuTnkPmpTstCmpl;

#define ACTTSTFUPMP_STOP_SEC_VAR_BOOLEAN
#include "ActTstFuPmp_MemMap.h"

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
 * hilite_system('ActTstFuPmp_AUTOCODE/ActTstFuPmp')    - opens subsystem ActTstFuPmp_AUTOCODE/ActTstFuPmp
 * hilite_system('ActTstFuPmp_AUTOCODE/ActTstFuPmp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ActTstFuPmp_AUTOCODE
 * '<S1>'   : ActTstFuPmp_AUTOCODE/ActTstFuPmp
 * '<S4>'   : ActTstFuPmp_AUTOCODE/ActTstFuPmp/F01_FuTnkPmpTst
 * '<S5>'   : ActTstFuPmp_AUTOCODE/ActTstFuPmp/F01_FuTnkPmpTst/F01_FuTnkPmpChart
 */

/*-
 * Requirements for '<Root>': ActTstFuPmp
 */
#endif                                 /* RTW_HEADER_ActTstFuPmp_h_ */

/*-------------------------------- end of file -------------------------------*/
