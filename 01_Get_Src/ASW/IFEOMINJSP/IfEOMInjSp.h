/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : IfEOMInjSp                                              */
/* !Description     : CALCUL DES MASSES D ESSENCE À INJECTER                  */
/*                                                                            */
/* !Module          : IfEOMInjSp                                              */
/*                                                                            */
/* !File            : IfEOMInjSp.h                                            */
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
/*   Code generated on: Fri Jun 01 12:04:59 2012                              */
/*   Model name       : IfEOMInjSp_AUTOCODE.mdl                               */
/*   Model version    : 1.102                                                 */
/*   Root subsystem   : /IfEOMInjSp                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/IFEOMINJSP/IfEOMInjSp.h_v $*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   06 Jun 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_IfEOMInjSp_h_
#define RTW_HEADER_IfEOMInjSp_h_
#ifndef IfEOMInjSp_COMMON_INCLUDES_
# define IfEOMInjSp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "IfEOMInjSp_import.h"
#include "VEMS.H"
#endif                                 /* IfEOMInjSp_COMMON_INCLUDES_ */

#include "IfEOMInjSp_types.h"

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
  UInt16 VEMS_vidGET9;               /* '<S6>/VEMS_vidGET9' */
  UInt16 OutDTConv;                  /* '<S9>/OutDTConv' */
  UInt16 VEMS_vidGET7[6];            /* '<S6>/VEMS_vidGET7' */
  UInt16 OutDTConv_a;                /* '<S10>/OutDTConv' */
  UInt8 VEMS_vidGET3[16];            /* '<S6>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET5[16];            /* '<S6>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET4[16];            /* '<S6>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET6[16];            /* '<S6>/VEMS_vidGET6' */
  UInt8 VEMS_vidGET8;                /* '<S6>/VEMS_vidGET8' */
  UInt8 VEMS_vidGET[16];             /* '<S6>/VEMS_vidGET' */
  UInt8 VEMS_vidGET1[16];            /* '<S6>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET2[16];            /* '<S6>/VEMS_vidGET2' */
  UInt8 DataTypeConversion10;        /* '<S6>/Data Type Conversion10' */
  UInt8 DataTypeConversion11;        /* '<S6>/Data Type Conversion11' */
  UInt8 DataTypeConversion9;         /* '<S6>/Data Type Conversion9' */
  UInt8 DataTypeConversion12;        /* '<S6>/Data Type Conversion12' */
  UInt8 DataTypeConversion13;        /* '<S6>/Data Type Conversion13' */
  UInt8 DataTypeConversion4;         /* '<S6>/Data Type Conversion4' */
  UInt8 DataTypeConversion1;         /* '<S6>/Data Type Conversion1' */
  UInt8 DataTypeConversion14;        /* '<S6>/Data Type Conversion14' */
  UInt8 DataTypeConversion15;        /* '<S6>/Data Type Conversion15' */
} BlockIO_IfEOMInjSp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float FixPtUnitDelay1_DSTATE;     /* '<S11>/FixPt Unit Delay1' */
  Float FixPtUnitDelay1_DSTATE_h;   /* '<S13>/FixPt Unit Delay1' */
  UInt8 FixPtUnitDelay2_DSTATE;      /* '<S11>/FixPt Unit Delay2' */
  UInt8 FixPtUnitDelay2_DSTATE_a;    /* '<S13>/FixPt Unit Delay2' */
} D_Work_IfEOMInjSp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define IFEOMINJSP_START_SEC_VAR_UNSPECIFIED
#include "IfEOMInjSp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_IfEOMInjSp IfEOMInjSp_B;

/* Block states (auto storage) */
extern D_Work_IfEOMInjSp IfEOMInjSp_DWork;

#define IFEOMINJSP_STOP_SEC_VAR_UNSPECIFIED
#include "IfEOMInjSp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define IFEOMINJSP_START_SEC_CODE
#include "IfEOMInjSp_MemMap.h"

/* Model entry point functions */
extern void IfEOMInjSp_initialize(void);
extern void InjSys_EveRst_IfEOMInjSp(void);
extern void InjSys_SdlFast_IfEOMInjSp(void);

#define IFEOMINJSP_STOP_SEC_CODE
#include "IfEOMInjSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define IFEOMINJSP_START_SEC_CALIB_16BIT
#include "IfEOMInjSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern CONST(UInt16, IFEOMINJSP_CALIB) InjSys_mAirDBInjSp_C;

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, IFEOMINJSP_CALIB) InjSys_nEngDBInjSp_C;

#define IFEOMINJSP_STOP_SEC_CALIB_16BIT
#include "IfEOMInjSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define IFEOMINJSP_START_SEC_VAR_16BIT
#include "IfEOMInjSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   1.1920166015625001E-007                                           */
/* Bias:    0.0                                                               */
/* Units:   kg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.8118807983398441E-003                                           */
extern VAR(UInt16, IFEOMINJSP_VAR) InjSys_mAirPredInjSp;

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern VAR(UInt16, IFEOMINJSP_VAR) InjSys_nEngInjSp;

#define IFEOMINJSP_STOP_SEC_VAR_16BIT
#include "IfEOMInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define IFEOMINJSP_START_SEC_VAR_8BIT
#include "IfEOMInjSp_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModCurAgInj;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModCurPfuSp;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModCurRatInj;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModTarAgInj;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModTarPfuSp;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModTarRatInj;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facTranModAgInj;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facTranModPfuSp;

/* Type:    UInt8                                                           */
/* Slope:   0.0078125                                                         */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_facTranModRatInj;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModCurAgInj;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModCurPfuSp;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModCurRatInj;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModTarAgInj;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModTarPfuSp;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModTarRatInj;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModCurAgInj;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModCurPfuSp;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModCurRatInj;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModTarAgInj;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModTarPfuSp;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModTarRatInj;

#define IFEOMINJSP_STOP_SEC_VAR_8BIT
#include "IfEOMInjSp_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S14>/Byp_Fonction_SC' : Unused code path elimination
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
 * hilite_system('IfEOMInjSp_AUTOCODE/IfEOMInjSp')    - opens subsystem IfEOMInjSp_AUTOCODE/IfEOMInjSp
 * hilite_system('IfEOMInjSp_AUTOCODE/IfEOMInjSp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : IfEOMInjSp_AUTOCODE
 * '<S1>'   : IfEOMInjSp_AUTOCODE/IfEOMInjSp
 * '<S4>'   : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F00_Init
 * '<S5>'   : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp
 * '<S6>'   : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp
 * '<S7>'   : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp/F03_01_02_01_Backlash_module_ambt
 * '<S8>'   : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp/F03_01_02_01_Backlash_module_ambt1
 * '<S9>'   : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp/SingleToFixdt
 * '<S10>'  : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp/SingleToFixdt1
 * '<S11>'  : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp/F03_01_02_01_Backlash_module_ambt/Unit Delay External IC
 * '<S12>'  : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp/F03_01_02_01_Backlash_module_ambt/multiplication
 * '<S13>'  : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp/F03_01_02_01_Backlash_module_ambt1/Unit Delay External IC
 * '<S14>'  : IfEOMInjSp_AUTOCODE/IfEOMInjSp/F01_IfEOMInjSp/F01_IfEOMInjSp/F03_01_02_01_Backlash_module_ambt1/multiplication
 */

/*-
 * Requirements for '<Root>': IfEOMInjSp
 */
#endif                                 /* RTW_HEADER_IfEOMInjSp_h_ */

/*-------------------------------- end of file -------------------------------*/
