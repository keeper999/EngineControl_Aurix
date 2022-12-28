/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : agPmpRefPFuM                                            */
/* !Description     : CALCULATION OF THE ANGULAR REFERENCES FOR THE PUMP STRIKES (GDI)*/
/*                                                                            */
/* !Module          : agPmpRefPFuM                                            */
/*                                                                            */
/* !File            : agPmpRefPFuM.h                                          */
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
/*   Code generated on: Thu Sep 12 10:58:54 2013                              */
/*   Model name       : agPmpRefPFuM_AUTOCODE.mdl                             */
/*   Model version    : 1.77                                                  */
/*   Root subsystem   : /agPmpRefPFuM                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/agPmpRefPFuM/5-SOFT-LIV/agPm$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Sep 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_agPmpRefPFuM_h_
#define RTW_HEADER_agPmpRefPFuM_h_
#ifndef agPmpRefPFuM_COMMON_INCLUDES_
# define agPmpRefPFuM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "agPmpRefPFuM_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_mod_uint8.h"
#endif                                 /* agPmpRefPFuM_COMMON_INCLUDES_ */

#include "agPmpRefPFuM_types.h"

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
  UInt32 SFunction2;                 /* '<S10>/S-Function2' */
  UInt32 SFunction5;                 /* '<S7>/S-Function5' */
  SInt32 DTConv_UFix_To_Single_1;     /* '<S10>/DTConv_UFix_To_Single_1' */
  SInt32 Switch2;                     /* '<S7>/Switch2' */
  SInt32 Switch3;                     /* '<S7>/Switch3' */
  UInt16 SFunction3;                 /* '<S10>/S-Function3' */
  UInt16 SFunction4;                 /* '<S7>/S-Function4' */
  UInt16 SFunction1;                 /* '<S10>/S-Function1' */
  UInt16 SFunction6;                 /* '<S10>/S-Function6' */
  UInt16 SFunction1_a;               /* '<S7>/S-Function1' */
  UInt16 SFunction3_g;               /* '<S7>/S-Function3' */
  SInt16 Add4;                        /* '<S10>/Add4' */
  SInt16 Add12;                       /* '<S10>/Add12' */
  SInt16 DTConv_UFix_To_Single_1_o[2];/* '<S7>/DTConv_UFix_To_Single_1' */
  SInt16 Switch[2];                   /* '<S7>/Switch' */
  UInt8 SFunction2_b;                /* '<S7>/S-Function2' */
} BlockIO_agPmpRefPFuM;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define AGPMPREFPFUM_START_SEC_VAR_UNSPECIFIED
#include "agPmpRefPFuM_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_agPmpRefPFuM agPmpRefPFuM_B;

#define AGPMPREFPFUM_STOP_SEC_VAR_UNSPECIFIED
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define AGPMPREFPFUM_START_SEC_CODE
#include "agPmpRefPFuM_MemMap.h"

/* Model entry point functions */
extern void agPmpRefPFuM_initialize(void);
extern void FuSysM_EveSpl_agPmpRefPFuM(void);
extern void FuSysM_EveInj_agPmpRefPFuM(void);
extern void FuSysM_EveCkSnOn_agPmpRefPFuM(void);

#define AGPMPREFPFUM_STOP_SEC_CODE
#include "agPmpRefPFuM_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define AGPMPREFPFUM_START_SEC_CALIB_16BIT
#include "agPmpRefPFuM_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, AGPMPREFPFUM_CALIB) FuSysM_agBtwTDCRef_C;

/* Type:    SInt16                                                           */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: -720.0                                                            */
/* PhysMax: 720.0                                                             */
extern CONST(SInt16, AGPMPREFPFUM_CALIB) FuSysM_agConvSplRefEveInj_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, AGPMPREFPFUM_CALIB) FuSysM_agDlyPmpStk_T[16];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, AGPMPREFPFUM_CALIB) FuSysM_agPerPmpRef_C;

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, AGPMPREFPFUM_CALIB) FuSysM_nEng_A[16];

#define AGPMPREFPFUM_STOP_SEC_CALIB_16BIT
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define AGPMPREFPFUM_START_SEC_CALIB_8BIT
#include "agPmpRefPFuM_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 6.0                                                               */
extern CONST(UInt8, AGPMPREFPFUM_CALIB) FuSysM_ctTDCRefPmpCmd_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.0                                                               */
extern CONST(UInt8, AGPMPREFPFUM_CALIB) FuSysM_noTDCBtwPmpStk_C;

#define AGPMPREFPFUM_STOP_SEC_CALIB_8BIT
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define AGPMPREFPFUM_START_SEC_CALIB_BOOLEAN
#include "agPmpRefPFuM_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AGPMPREFPFUM_CALIB) FuSysM_bCfPmpOneTDCStk_C;

#define AGPMPREFPFUM_STOP_SEC_CALIB_BOOLEAN
#include "agPmpRefPFuM_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define AGPMPREFPFUM_START_SEC_VAR_32BIT
#include "agPmpRefPFuM_MemMap.h"

/* Type:    SInt32                                                           */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: -0.0078125                                                        */
/* PhysMax: 0.0078125                                                         */
extern VAR(SInt32, AGPMPREFPFUM_VAR) FuSysM_mFuPmpStk1Req;

/* Type:    SInt32                                                           */
/* Slope:   7.4505805969238281E-009                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: -0.0078125                                                        */
/* PhysMax: 0.0078125                                                         */
extern VAR(SInt32, AGPMPREFPFUM_VAR) FuSysM_mFuPmpStk2Req;

#define AGPMPREFPFUM_STOP_SEC_VAR_32BIT
#include "agPmpRefPFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define AGPMPREFPFUM_START_SEC_VAR_16BIT
#include "agPmpRefPFuM_MemMap.h"

/* Type:    SInt16                                                           */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: -720.0                                                            */
/* PhysMax: 720.0                                                             */
extern VAR(SInt16, AGPMPREFPFUM_VAR) FuSysM_agBegPmpStk1Ref;

/* Type:    SInt16                                                           */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: -720.0                                                            */
/* PhysMax: 720.0                                                             */
extern VAR(SInt16, AGPMPREFPFUM_VAR) FuSysM_agBegPmpStk2Ref;

/* Type:    SInt16                                                           */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: -720.0                                                            */
/* PhysMax: 720.0                                                             */
extern VAR(SInt16, AGPMPREFPFUM_VAR) FuSysM_agEndPmpStk1Ref;

/* Type:    SInt16                                                           */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: -720.0                                                            */
/* PhysMax: 720.0                                                             */
extern VAR(SInt16, AGPMPREFPFUM_VAR) FuSysM_agEndPmpStk2Ref;

#define AGPMPREFPFUM_STOP_SEC_VAR_16BIT
#include "agPmpRefPFuM_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/BKPT1' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S8>/TABLE' : Unused code path elimination
 * Block '<S7>/FuSysM_nEng_A' : Unused code path elimination
 * Block '<S11>/BKPT1' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S11>/TABLE' : Unused code path elimination
 * Block '<S10>/FuSysM_nEng_A' : Unused code path elimination
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * hilite_system('agPmpRefPFuM_AUTOCODE/agPmpRefPFuM')    - opens subsystem agPmpRefPFuM_AUTOCODE/agPmpRefPFuM
 * hilite_system('agPmpRefPFuM_AUTOCODE/agPmpRefPFuM/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : agPmpRefPFuM_AUTOCODE
 * '<S4>'   : agPmpRefPFuM_AUTOCODE/agPmpRefPFuM
 * '<S5>'   : agPmpRefPFuM_AUTOCODE/agPmpRefPFuM/F01_agPmpStkRef_EveInj
 * '<S6>'   : agPmpRefPFuM_AUTOCODE/agPmpRefPFuM/F02_agPmpStkRef_Spl
 * '<S7>'   : agPmpRefPFuM_AUTOCODE/agPmpRefPFuM/F01_agPmpStkRef_EveInj/F01_agPmpStkRef_EveInj
 * '<S8>'   : agPmpRefPFuM_AUTOCODE/agPmpRefPFuM/F01_agPmpStkRef_EveInj/F01_agPmpStkRef_EveInj/Carto_1D_21
 * '<S9>'   : agPmpRefPFuM_AUTOCODE/agPmpRefPFuM/F02_agPmpStkRef_Spl/F02_agPmpStkRef_Spl
 * '<S10>'  : agPmpRefPFuM_AUTOCODE/agPmpRefPFuM/F02_agPmpStkRef_Spl/F02_agPmpStkRef_Spl/F01_agPmpStkRefClcn
 * '<S11>'  : agPmpRefPFuM_AUTOCODE/agPmpRefPFuM/F02_agPmpStkRef_Spl/F02_agPmpStkRef_Spl/F01_agPmpStkRefClcn/Carto_1D_22
 */

/*-
 * Requirements for '<Root>': agPmpRefPFuM
 */
#endif                                 /* RTW_HEADER_agPmpRefPFuM_h_ */

/*-------------------------------- end of file -------------------------------*/
