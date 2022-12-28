/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstTrbWaPmp                                          */
/* !Description     : Test actionneur Pompe à Eau Turbo                       */
/*                                                                            */
/* !Module          : ActTstTrbWaPmp                                          */
/*                                                                            */
/* !File            : ActTstTrbWaPmp.h                                        */
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
/*   Code generated on: Sun Oct 02 10:12:20 2011                              */
/*   Model name       : ActTstTrbWaPmp_AUTOCODE.mdl                           */
/*   Model version    : 1.32                                                  */
/*   Root subsystem   : /ActTstTrbWaPmp                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ACTTSTTRBWAPMP/ActTstTrbWaPmp.h_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   14 Oct 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ActTstTrbWaPmp_h_
#define RTW_HEADER_ActTstTrbWaPmp_h_
#ifndef ActTstTrbWaPmp_COMMON_INCLUDES_
# define ActTstTrbWaPmp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "ActTstTrbWaPmp_import.h"
#include "VEMS.H"
#include "rt_MAX.h"
#endif                                 /* ActTstTrbWaPmp_COMMON_INCLUDES_ */

#include "ActTstTrbWaPmp_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define THMGT_ACTRTEST_END             ((UInt8) 2U)
#define THMGT_ACTRTEST_IDLE            ((UInt8) 4U)
#define THMGT_ACTRTEST_MAX             ((UInt8) 6U)
#define THMGT_ACTRTEST_MIN             ((UInt8) 8U)

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
  UInt8 VEMS_vidGET5;                /* '<S4>/VEMS_vidGET5' */
  Boolean VEMS_vidGET4;              /* '<S4>/VEMS_vidGET4' */
  Boolean ThMgt_bTrbWaPmpReqActrTst_p;/* '<S4>/F01_TrbWaPmpTstChart' */
  Boolean ThMgt_bActrTstInProgs_m;   /* '<S4>/F01_TrbWaPmpTstChart' */
  Boolean ThMgt_bTrbWaPmpTstCmpl_k;  /* '<S4>/F01_TrbWaPmpTstChart' */
} BlockIO_ActTstTrbWaPmp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UInt8 is_active_c3_ActTstTrbWaPmp; /* '<S4>/F01_TrbWaPmpTstChart' */
  UInt8 is_c3_ActTstTrbWaPmp;        /* '<S4>/F01_TrbWaPmpTstChart' */
  UInt8 is_TestEnCours;              /* '<S4>/F01_TrbWaPmpTstChart' */
} D_Work_ActTstTrbWaPmp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTTSTTRBWAPMP_START_SEC_VAR_UNSPECIFIED
#include "ActTstTrbWaPmp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_ActTstTrbWaPmp ActTstTrbWaPmp_B;

/* Block states (auto storage) */
extern D_Work_ActTstTrbWaPmp ActTstTrbWaPmp_DWork;

#define ACTTSTTRBWAPMP_STOP_SEC_VAR_UNSPECIFIED
#include "ActTstTrbWaPmp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define ACTTSTTRBWAPMP_START_SEC_CODE
#include "ActTstTrbWaPmp_MemMap.h"

/* Model entry point functions */
extern void ActTstTrbWaPmp_initialize(void);
extern void ThMgt_SdlMid_ActrTstTrbWaPmp(void);
extern void ThMgt_EveRst_ActrTstTrbWaPmp(void);

#define ACTTSTTRBWAPMP_STOP_SEC_CODE
#include "ActTstTrbWaPmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define ACTTSTTRBWAPMP_START_SEC_CALIB_16BIT
#include "ActTstTrbWaPmp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTTSTTRBWAPMP_CALIB) ActrTstTrbWaPmp_Tempo_C;

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 50.0                                                              */
extern CONST(UInt16, ACTTSTTRBWAPMP_CALIB) ActrTstTrbWaPmp_TotTime_C;

#define ACTTSTTRBWAPMP_STOP_SEC_CALIB_16BIT
#include "ActTstTrbWaPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define ACTTSTTRBWAPMP_START_SEC_CALIB_8BIT
#include "ActTstTrbWaPmp_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt8, ACTTSTTRBWAPMP_CALIB) ActrTstTrbWaPmp_OffTime_C;

/* Type:    UInt8                                                           */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 25.0                                                              */
extern CONST(UInt8, ACTTSTTRBWAPMP_CALIB) ActrTstTrbWaPmp_OnTime_C;

#define ACTTSTTRBWAPMP_STOP_SEC_CALIB_8BIT
#include "ActTstTrbWaPmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define ACTTSTTRBWAPMP_START_SEC_VAR_BOOLEAN
#include "ActTstTrbWaPmp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTTSTTRBWAPMP_VAR) ThMgt_bActrTstInProgs;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTTSTTRBWAPMP_VAR) ThMgt_bTrbWaPmpReqActrTst;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, ACTTSTTRBWAPMP_VAR) ThMgt_bTrbWaPmpTstCmpl;

#define ACTTSTTRBWAPMP_STOP_SEC_VAR_BOOLEAN
#include "ActTstTrbWaPmp_MemMap.h"

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
 * hilite_system('ActTstTrbWaPmp_AUTOCODE/ActTstTrbWaPmp')    - opens subsystem ActTstTrbWaPmp_AUTOCODE/ActTstTrbWaPmp
 * hilite_system('ActTstTrbWaPmp_AUTOCODE/ActTstTrbWaPmp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ActTstTrbWaPmp_AUTOCODE
 * '<S1>'   : ActTstTrbWaPmp_AUTOCODE/ActTstTrbWaPmp
 * '<S4>'   : ActTstTrbWaPmp_AUTOCODE/ActTstTrbWaPmp/F01_TrbWaPmpTst
 * '<S5>'   : ActTstTrbWaPmp_AUTOCODE/ActTstTrbWaPmp/F01_TrbWaPmpTst/F01_TrbWaPmpTstChart
 */

/*-
 * Requirements for '<Root>': ActTstTrbWaPmp
 */
#endif                                 /* RTW_HEADER_ActTstTrbWaPmp_h_ */

/*-------------------------------- end of file -------------------------------*/
