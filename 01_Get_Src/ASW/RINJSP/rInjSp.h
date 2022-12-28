/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : rInjSp                                                  */
/* !Description     : V01NT1006234.001                                        */
/*                                                                            */
/* !Module          : rInjSp                                                  */
/*                                                                            */
/* !File            : rInjSp.h                                                */
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
/*   Code generated on: Sun Jan 13 20:30:13 2013                              */
/*   Model name       : rInjSp_AUTOCODE.mdl                                   */
/*   Model version    : 1.181                                                 */
/*   Root subsystem   : /rInjSp                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/RINJSP/rInjSp.h_v         $*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Feb 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_rInjSp_h_
#define RTW_HEADER_rInjSp_h_
#ifndef rInjSp_COMMON_INCLUDES_
# define rInjSp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "rInjSp_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "ACTEMS_LdexpF.h"
#endif                                 /* rInjSp_COMMON_INCLUDES_ */

#include "rInjSp_types.h"

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
  UInt16 VEMS_vidGET;                /* '<S6>/VEMS_vidGET' */
  UInt16 VEMS_vidGET10;              /* '<S6>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET1;               /* '<S6>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET9;               /* '<S6>/VEMS_vidGET9' */
  UInt16 Merge;                      /* '<S6>/Merge' */
  UInt16 Merge1;                     /* '<S6>/Merge1' */
  UInt16 Merge2;                     /* '<S6>/Merge2' */
  UInt8 VEMS_vidGET5;                /* '<S6>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET7;                /* '<S6>/VEMS_vidGET7' */
  UInt8 VEMS_vidGET6;                /* '<S6>/VEMS_vidGET6' */
  UInt8 VEMS_vidGET8;                /* '<S6>/VEMS_vidGET8' */
  UInt8 Merge3;                      /* '<S6>/Merge3' */
  Boolean Merge4;                    /* '<S6>/Merge4' */
  Boolean Merge5;                    /* '<S6>/Merge5' */
  Boolean Merge6;                    /* '<S6>/Merge6' */
  Boolean Merge7;                    /* '<S6>/Merge7' */
  UInt8 VEMS_vidGET2;                /* '<S6>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET3;                /* '<S6>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET4;                /* '<S6>/VEMS_vidGET4' */
} BlockIO_rInjSp;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define RINJSP_START_SEC_VAR_UNSPECIFIED
#include "rInjSp_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_rInjSp rInjSp_B;

#define RINJSP_STOP_SEC_VAR_UNSPECIFIED
#include "rInjSp_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define RINJSP_START_SEC_CODE
#include "rInjSp_MemMap.h"

/* Model entry point functions */
extern void rInjSp_initialize(void);
extern void InjSys_SdlFast_rInjSp(void);
extern void InjSys_EveRst_rInjSp(void);

#define RINJSP_STOP_SEC_CODE
#include "rInjSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define RINJSP_START_SEC_CALIB_16BIT
#include "rInjSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal10_M[64];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal11_M[64];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal12_M[64];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal1_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal2_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal3_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal4_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal5_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal6_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal7_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal8_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2Cal9_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2SpCal13_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2SpETB_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj2SpETB_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal10_M[64];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal11_M[64];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal12_M[64];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal1_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal2_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal3_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal4_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal5_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal6_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal7_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal8_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3Cal9_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3SpCal13_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3SpETB_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInj3SpETB_M[256];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, RINJSP_CALIB) InjSys_rInjM1Min_C;

#define RINJSP_STOP_SEC_CALIB_16BIT
#include "rInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define RINJSP_START_SEC_CALIB_8BIT
#include "rInjSp_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern CONST(UInt8, RINJSP_CALIB) InjSys_idxModRatInjSatMax_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 1.0                                                               */
/* PhysMax: 32.0                                                              */
extern CONST(UInt8, RINJSP_CALIB) InjSys_idxModRatInjSatMin_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, RINJSP_CALIB) InjSys_noETBSelnoInjPat_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, RINJSP_CALIB) InjSys_noETBSelrInj2Sp_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt8, RINJSP_CALIB) InjSys_noETBSelrInj3Sp_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.0                                                               */
extern CONST(UInt8, RINJSP_CALIB) InjSys_noInjPatETB_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.0                                                               */
extern CONST(UInt8, RINJSP_CALIB) InjSys_noInjPatETB_M[256];

#define RINJSP_STOP_SEC_CALIB_8BIT
#include "rInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define RINJSP_START_SEC_CALIB_BOOLEAN
#include "rInjSp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, RINJSP_CALIB) InjSys_bAcvETBrInjSp_C;

#define RINJSP_STOP_SEC_CALIB_BOOLEAN
#include "rInjSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define RINJSP_START_SEC_VAR_16BIT
#include "rInjSp_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj1Sp;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2Sp;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3Sp;

#define RINJSP_STOP_SEC_VAR_16BIT
#include "rInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define RINJSP_START_SEC_VAR_8BIT
#include "rInjSp_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.0                                                               */
extern VAR(UInt8, RINJSP_VAR) InjSys_noInjPat;

#define RINJSP_STOP_SEC_VAR_8BIT
#include "rInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define RINJSP_START_SEC_VAR_BOOLEAN
#include "rInjSp_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvInjPat0;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvInjPat1;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvInjPat2;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvInjPat3;

#define RINJSP_STOP_SEC_VAR_BOOLEAN
#include "rInjSp_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S9>/TABLE' : Unused code path elimination
 * Block '<S9>/TABLE1' : Unused code path elimination
 * Block '<S9>/TABLE2' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S10>/TABLE' : Unused code path elimination
 * Block '<S10>/TABLE1' : Unused code path elimination
 * Block '<S10>/TABLE2' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S11>/TABLE' : Unused code path elimination
 * Block '<S11>/TABLE1' : Unused code path elimination
 * Block '<S11>/TABLE2' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Relational Operator' : Unused code path elimination
 * Block '<S12>/Relational Operator1' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Relational Operator' : Unused code path elimination
 * Block '<S13>/Relational Operator1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/Constant_22' : Unused code path elimination
 * Block '<S7>/Constant_23' : Unused code path elimination
 * Block '<S7>/Constant_32' : Unused code path elimination
 * Block '<S7>/Constant_33' : Unused code path elimination
 * Block '<S7>/Ext_nEngX_A' : Unused code path elimination
 * Block '<S7>/Ext_pDsThrMesSIY_A' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Relational Operator' : Unused code path elimination
 * Block '<S32>/Relational Operator1' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Relational Operator' : Unused code path elimination
 * Block '<S33>/Relational Operator1' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Propagation' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Relational Operator' : Unused code path elimination
 * Block '<S34>/Relational Operator1' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Propagation' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Relational Operator' : Unused code path elimination
 * Block '<S35>/Relational Operator1' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Propagation' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S63>/TABLE' : Unused code path elimination
 * Block '<S63>/TABLE1' : Unused code path elimination
 * Block '<S63>/TABLE2' : Unused code path elimination
 * Block '<S49>/InjSys_mAirInjSpCal1Y_A' : Unused code path elimination
 * Block '<S49>/InjSys_nEngInjSpCal1X_A' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S64>/TABLE' : Unused code path elimination
 * Block '<S64>/TABLE1' : Unused code path elimination
 * Block '<S64>/TABLE2' : Unused code path elimination
 * Block '<S50>/InjSys_mAirInjSpCal2Y_A' : Unused code path elimination
 * Block '<S50>/InjSys_nEngInjSpCal2X_A' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S65>/TABLE' : Unused code path elimination
 * Block '<S65>/TABLE1' : Unused code path elimination
 * Block '<S65>/TABLE2' : Unused code path elimination
 * Block '<S51>/InjSys_mAirInjSpCal3Y_A' : Unused code path elimination
 * Block '<S51>/InjSys_nEngInjSpCal3X_A' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S66>/TABLE' : Unused code path elimination
 * Block '<S66>/TABLE1' : Unused code path elimination
 * Block '<S66>/TABLE2' : Unused code path elimination
 * Block '<S52>/InjSys_mAirInjSpCal4Y_A' : Unused code path elimination
 * Block '<S52>/InjSys_nEngInjSpCal4X_A' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S67>/TABLE' : Unused code path elimination
 * Block '<S67>/TABLE1' : Unused code path elimination
 * Block '<S67>/TABLE2' : Unused code path elimination
 * Block '<S53>/InjSys_mAirInjSpCal5Y_A' : Unused code path elimination
 * Block '<S53>/InjSys_nEngInjSpCal5X_A' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S68>/TABLE' : Unused code path elimination
 * Block '<S68>/TABLE1' : Unused code path elimination
 * Block '<S68>/TABLE2' : Unused code path elimination
 * Block '<S54>/InjSys_mAirInjSpCal6Y_A' : Unused code path elimination
 * Block '<S54>/InjSys_nEngInjSpCal6X_A' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S69>/TABLE' : Unused code path elimination
 * Block '<S69>/TABLE1' : Unused code path elimination
 * Block '<S69>/TABLE2' : Unused code path elimination
 * Block '<S55>/InjSys_mAirInjSpCal7Y_A' : Unused code path elimination
 * Block '<S55>/InjSys_nEngInjSpCal7X_A' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S70>/TABLE' : Unused code path elimination
 * Block '<S70>/TABLE1' : Unused code path elimination
 * Block '<S70>/TABLE2' : Unused code path elimination
 * Block '<S56>/InjSys_mAirInjSpCal8Y_A' : Unused code path elimination
 * Block '<S56>/InjSys_nEngInjSpCal8X_A' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S71>/TABLE' : Unused code path elimination
 * Block '<S71>/TABLE1' : Unused code path elimination
 * Block '<S71>/TABLE2' : Unused code path elimination
 * Block '<S57>/InjSys_mAirInjSpCal9Y_A' : Unused code path elimination
 * Block '<S57>/InjSys_nEngInjSpCal9X_A' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S72>/TABLE' : Unused code path elimination
 * Block '<S72>/TABLE1' : Unused code path elimination
 * Block '<S72>/TABLE2' : Unused code path elimination
 * Block '<S58>/InjSys_mAirInjSpCal10Y_A' : Unused code path elimination
 * Block '<S58>/InjSys_nEngInjSpCal10X_A' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S73>/TABLE' : Unused code path elimination
 * Block '<S73>/TABLE1' : Unused code path elimination
 * Block '<S73>/TABLE2' : Unused code path elimination
 * Block '<S59>/InjSys_mAirInjSpCal11Y_A' : Unused code path elimination
 * Block '<S59>/InjSys_nEngInjSpCal11X_A' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S74>/TABLE' : Unused code path elimination
 * Block '<S74>/TABLE1' : Unused code path elimination
 * Block '<S74>/TABLE2' : Unused code path elimination
 * Block '<S60>/InjSys_mAirInjSpCal12Y_A' : Unused code path elimination
 * Block '<S60>/InjSys_nEngInjSpCal12X_A' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Relational Operator' : Unused code path elimination
 * Block '<S78>/Relational Operator1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Propagation' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Relational Operator' : Unused code path elimination
 * Block '<S82>/Relational Operator1' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Data Type Propagation' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Relational Operator' : Unused code path elimination
 * Block '<S86>/Relational Operator1' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Propagation' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Relational Operator' : Unused code path elimination
 * Block '<S94>/Relational Operator1' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Propagation' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate' : Unused code path elimination
 * Block '<S95>/Relational Operator' : Unused code path elimination
 * Block '<S95>/Relational Operator1' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Data Type Propagation' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S96>/Relational Operator' : Unused code path elimination
 * Block '<S96>/Relational Operator1' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Propagation' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S97>/Relational Operator' : Unused code path elimination
 * Block '<S97>/Relational Operator1' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Propagation' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S125>/TABLE' : Unused code path elimination
 * Block '<S125>/TABLE1' : Unused code path elimination
 * Block '<S125>/TABLE2' : Unused code path elimination
 * Block '<S111>/InjSys_mAirInjSpCal1Y_A' : Unused code path elimination
 * Block '<S111>/InjSys_nEngInjSpCal1X_A' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S126>/TABLE' : Unused code path elimination
 * Block '<S126>/TABLE1' : Unused code path elimination
 * Block '<S126>/TABLE2' : Unused code path elimination
 * Block '<S112>/InjSys_mAirInjSpCal2Y_A' : Unused code path elimination
 * Block '<S112>/InjSys_nEngInjSpCal2X_A' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S127>/TABLE' : Unused code path elimination
 * Block '<S127>/TABLE1' : Unused code path elimination
 * Block '<S127>/TABLE2' : Unused code path elimination
 * Block '<S113>/InjSys_mAirInjSpCal3Y_A' : Unused code path elimination
 * Block '<S113>/InjSys_nEngInjSpCal3X_A' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S128>/TABLE' : Unused code path elimination
 * Block '<S128>/TABLE1' : Unused code path elimination
 * Block '<S128>/TABLE2' : Unused code path elimination
 * Block '<S114>/InjSys_mAirInjSpCal4Y_A' : Unused code path elimination
 * Block '<S114>/InjSys_nEngInjSpCal4X_A' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S129>/TABLE' : Unused code path elimination
 * Block '<S129>/TABLE1' : Unused code path elimination
 * Block '<S129>/TABLE2' : Unused code path elimination
 * Block '<S115>/InjSys_mAirInjSpCal5Y_A' : Unused code path elimination
 * Block '<S115>/InjSys_nEngInjSpCal5X_A' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S130>/TABLE' : Unused code path elimination
 * Block '<S130>/TABLE1' : Unused code path elimination
 * Block '<S130>/TABLE2' : Unused code path elimination
 * Block '<S116>/InjSys_mAirInjSpCal6Y_A' : Unused code path elimination
 * Block '<S116>/InjSys_nEngInjSpCal6X_A' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S131>/TABLE' : Unused code path elimination
 * Block '<S131>/TABLE1' : Unused code path elimination
 * Block '<S131>/TABLE2' : Unused code path elimination
 * Block '<S117>/InjSys_mAirInjSpCal7Y_A' : Unused code path elimination
 * Block '<S117>/InjSys_nEngInjSpCal7X_A' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S132>/TABLE' : Unused code path elimination
 * Block '<S132>/TABLE1' : Unused code path elimination
 * Block '<S132>/TABLE2' : Unused code path elimination
 * Block '<S118>/InjSys_mAirInjSpCal8Y_A' : Unused code path elimination
 * Block '<S118>/InjSys_nEngInjSpCal8X_A' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S133>/TABLE' : Unused code path elimination
 * Block '<S133>/TABLE1' : Unused code path elimination
 * Block '<S133>/TABLE2' : Unused code path elimination
 * Block '<S119>/InjSys_mAirInjSpCal9Y_A' : Unused code path elimination
 * Block '<S119>/InjSys_nEngInjSpCal9X_A' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S134>/TABLE' : Unused code path elimination
 * Block '<S134>/TABLE1' : Unused code path elimination
 * Block '<S134>/TABLE2' : Unused code path elimination
 * Block '<S120>/InjSys_mAirInjSpCal10Y_A' : Unused code path elimination
 * Block '<S120>/InjSys_nEngInjSpCal10X_A' : Unused code path elimination
 * Block '<S135>/Data Type Duplicate' : Unused code path elimination
 * Block '<S135>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S135>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S135>/TABLE' : Unused code path elimination
 * Block '<S135>/TABLE1' : Unused code path elimination
 * Block '<S135>/TABLE2' : Unused code path elimination
 * Block '<S121>/InjSys_mAirInjSpCal11Y_A' : Unused code path elimination
 * Block '<S121>/InjSys_nEngInjSpCal11X_A' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S136>/TABLE' : Unused code path elimination
 * Block '<S136>/TABLE1' : Unused code path elimination
 * Block '<S136>/TABLE2' : Unused code path elimination
 * Block '<S122>/InjSys_mAirInjSpCal12Y_A' : Unused code path elimination
 * Block '<S122>/InjSys_nEngInjSpCal12X_A' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate' : Unused code path elimination
 * Block '<S140>/Relational Operator' : Unused code path elimination
 * Block '<S140>/Relational Operator1' : Unused code path elimination
 * Block '<S143>/Data Type Duplicate' : Unused code path elimination
 * Block '<S143>/Data Type Propagation' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate' : Unused code path elimination
 * Block '<S146>/Data Type Duplicate' : Unused code path elimination
 * Block '<S144>/Relational Operator' : Unused code path elimination
 * Block '<S144>/Relational Operator1' : Unused code path elimination
 * Block '<S147>/Data Type Duplicate' : Unused code path elimination
 * Block '<S147>/Data Type Propagation' : Unused code path elimination
 * Block '<S149>/Data Type Duplicate' : Unused code path elimination
 * Block '<S150>/Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/Relational Operator' : Unused code path elimination
 * Block '<S148>/Relational Operator1' : Unused code path elimination
 * Block '<S151>/Data Type Duplicate' : Unused code path elimination
 * Block '<S151>/Data Type Propagation' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S152>/Relational Operator' : Unused code path elimination
 * Block '<S152>/Relational Operator1' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate' : Unused code path elimination
 * Block '<S159>/Data Type Propagation' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/Relational Operator' : Unused code path elimination
 * Block '<S153>/Relational Operator1' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Propagation' : Unused code path elimination
 * Block '<S165>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S166>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S17>/Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Switch' : Eliminated due to constant selection input
 * Block '<S15>/Switch' : Eliminated due to constant selection input
 * Block '<S16>/Switch' : Eliminated due to constant selection input
 * Block '<S36>/Conversion' : Eliminate redundant data type conversion
 * Block '<S37>/Conversion' : Eliminate redundant data type conversion
 * Block '<S39>/Conversion' : Eliminate redundant data type conversion
 * Block '<S40>/Conversion' : Eliminate redundant data type conversion
 * Block '<S42>/Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Conversion' : Eliminate redundant data type conversion
 * Block '<S45>/Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Conversion' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S66>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S66>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S67>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S67>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S68>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S68>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S69>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S69>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S71>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S71>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S79>/Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Conversion' : Eliminate redundant data type conversion
 * Block '<S83>/Conversion' : Eliminate redundant data type conversion
 * Block '<S84>/Conversion' : Eliminate redundant data type conversion
 * Block '<S87>/Conversion' : Eliminate redundant data type conversion
 * Block '<S88>/Conversion' : Eliminate redundant data type conversion
 * Block '<S98>/Conversion' : Eliminate redundant data type conversion
 * Block '<S99>/Conversion' : Eliminate redundant data type conversion
 * Block '<S101>/Conversion' : Eliminate redundant data type conversion
 * Block '<S102>/Conversion' : Eliminate redundant data type conversion
 * Block '<S104>/Conversion' : Eliminate redundant data type conversion
 * Block '<S105>/Conversion' : Eliminate redundant data type conversion
 * Block '<S107>/Conversion' : Eliminate redundant data type conversion
 * Block '<S108>/Conversion' : Eliminate redundant data type conversion
 * Block '<S125>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S125>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S126>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S126>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S127>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S127>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S128>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S128>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S129>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S129>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S130>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S130>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S131>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S131>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S132>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S132>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S133>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S134>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S134>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S135>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S135>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S136>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S136>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S141>/Conversion' : Eliminate redundant data type conversion
 * Block '<S142>/Conversion' : Eliminate redundant data type conversion
 * Block '<S145>/Conversion' : Eliminate redundant data type conversion
 * Block '<S146>/Conversion' : Eliminate redundant data type conversion
 * Block '<S149>/Conversion' : Eliminate redundant data type conversion
 * Block '<S150>/Conversion' : Eliminate redundant data type conversion
 * Block '<S157>/Conversion' : Eliminate redundant data type conversion
 * Block '<S158>/Conversion' : Eliminate redundant data type conversion
 * Block '<S160>/Conversion' : Eliminate redundant data type conversion
 * Block '<S161>/Conversion' : Eliminate redundant data type conversion
 * Block '<S154>/Switch' : Eliminated due to constant selection input
 * Block '<S155>/Switch' : Eliminated due to constant selection input
 * Block '<S156>/Switch' : Eliminated due to constant selection input
 * Block '<S163>/Switch' : Eliminated due to constant selection input
 * Block '<S164>/Switch' : Eliminated due to constant selection input
 * Block '<S14>/Add3' : Unused code path elimination
 * Block '<S14>/Add4' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S14>/Relational Operator' : Unused code path elimination
 * Block '<S14>/Switch1' : Unused code path elimination
 * Block '<S14>/offset2' : Unused code path elimination
 * Block '<S14>/offset3' : Unused code path elimination
 * Block '<S14>/offset4' : Unused code path elimination
 * Block '<S15>/Add3' : Unused code path elimination
 * Block '<S15>/Add4' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S15>/Relational Operator' : Unused code path elimination
 * Block '<S15>/Switch1' : Unused code path elimination
 * Block '<S15>/offset2' : Unused code path elimination
 * Block '<S15>/offset3' : Unused code path elimination
 * Block '<S15>/offset4' : Unused code path elimination
 * Block '<S16>/Add3' : Unused code path elimination
 * Block '<S16>/Add4' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S16>/Relational Operator' : Unused code path elimination
 * Block '<S16>/Switch1' : Unused code path elimination
 * Block '<S16>/offset2' : Unused code path elimination
 * Block '<S16>/offset3' : Unused code path elimination
 * Block '<S16>/offset4' : Unused code path elimination
 * Block '<S154>/Add3' : Unused code path elimination
 * Block '<S154>/Add4' : Unused code path elimination
 * Block '<S154>/Constant' : Unused code path elimination
 * Block '<S154>/Relational Operator' : Unused code path elimination
 * Block '<S154>/Switch1' : Unused code path elimination
 * Block '<S154>/offset2' : Unused code path elimination
 * Block '<S154>/offset3' : Unused code path elimination
 * Block '<S154>/offset4' : Unused code path elimination
 * Block '<S155>/Add3' : Unused code path elimination
 * Block '<S155>/Add4' : Unused code path elimination
 * Block '<S155>/Constant' : Unused code path elimination
 * Block '<S155>/Relational Operator' : Unused code path elimination
 * Block '<S155>/Switch1' : Unused code path elimination
 * Block '<S155>/offset2' : Unused code path elimination
 * Block '<S155>/offset3' : Unused code path elimination
 * Block '<S155>/offset4' : Unused code path elimination
 * Block '<S156>/Add3' : Unused code path elimination
 * Block '<S156>/Add4' : Unused code path elimination
 * Block '<S156>/Constant' : Unused code path elimination
 * Block '<S156>/Relational Operator' : Unused code path elimination
 * Block '<S156>/Switch1' : Unused code path elimination
 * Block '<S156>/offset2' : Unused code path elimination
 * Block '<S156>/offset3' : Unused code path elimination
 * Block '<S156>/offset4' : Unused code path elimination
 * Block '<S163>/Add3' : Unused code path elimination
 * Block '<S163>/Add4' : Unused code path elimination
 * Block '<S163>/Constant' : Unused code path elimination
 * Block '<S163>/Relational Operator' : Unused code path elimination
 * Block '<S163>/Switch1' : Unused code path elimination
 * Block '<S163>/offset2' : Unused code path elimination
 * Block '<S163>/offset3' : Unused code path elimination
 * Block '<S163>/offset4' : Unused code path elimination
 * Block '<S164>/Add3' : Unused code path elimination
 * Block '<S164>/Add4' : Unused code path elimination
 * Block '<S164>/Constant' : Unused code path elimination
 * Block '<S164>/Relational Operator' : Unused code path elimination
 * Block '<S164>/Switch1' : Unused code path elimination
 * Block '<S164>/offset2' : Unused code path elimination
 * Block '<S164>/offset3' : Unused code path elimination
 * Block '<S164>/offset4' : Unused code path elimination
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
 * hilite_system('rInjSp_AUTOCODE/rInjSp')    - opens subsystem rInjSp_AUTOCODE/rInjSp
 * hilite_system('rInjSp_AUTOCODE/rInjSp/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : rInjSp_AUTOCODE
 * '<S3>'   : rInjSp_AUTOCODE/rInjSp
 * '<S4>'   : rInjSp_AUTOCODE/rInjSp/F01_Initialisation
 * '<S5>'   : rInjSp_AUTOCODE/rInjSp/F02_rInjSp
 * '<S6>'   : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp
 * '<S7>'   : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB
 * '<S8>'   : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn
 * '<S9>'   : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Carto_2D1
 * '<S10>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Carto_2D2
 * '<S11>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Carto_2D3
 * '<S12>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Clamp
 * '<S13>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Clamp1
 * '<S14>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/SingleToFixdt
 * '<S15>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/SingleToFixdt1
 * '<S16>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/SingleToFixdt2
 * '<S17>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Clamp/Data Type Conversion Inherited
 * '<S18>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Clamp/Data Type Conversion Inherited1
 * '<S19>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Clamp/Saturation Dynamic
 * '<S20>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Clamp1/Data Type Conversion Inherited
 * '<S21>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Clamp1/Data Type Conversion Inherited1
 * '<S22>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F00_rInjSpETB/Clamp1/Saturation Dynamic
 * '<S23>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp
 * '<S24>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp
 * '<S25>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj
 * '<S26>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F04_InjPat
 * '<S27>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F05_FuMass
 * '<S28>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp
 * '<S29>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp
 * '<S30>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F04_Select_Modes_FuMass3Tmp
 * '<S31>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp
 * '<S32>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp
 * '<S33>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp1
 * '<S34>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp2
 * '<S35>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp3
 * '<S36>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp/Data Type Conversion Inherited
 * '<S37>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp/Data Type Conversion Inherited1
 * '<S38>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp/Saturation Dynamic
 * '<S39>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp1/Data Type Conversion Inherited
 * '<S40>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp1/Data Type Conversion Inherited1
 * '<S41>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp1/Saturation Dynamic
 * '<S42>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp2/Data Type Conversion Inherited
 * '<S43>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp2/Data Type Conversion Inherited1
 * '<S44>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp2/Saturation Dynamic
 * '<S45>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp3/Data Type Conversion Inherited
 * '<S46>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp3/Data Type Conversion Inherited1
 * '<S47>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F02_Mode_Mask_FuMass3Tmp/Clamp3/Saturation Dynamic
 * '<S48>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F01_Unvectorize_Activation_Boolean_FuMass3Tmp
 * '<S49>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F02_Calibration_1_FuMass3Tmp
 * '<S50>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F03_Calibration_2_FuMass3Tmp
 * '<S51>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F04_Calibration_3_FuMass3Tmp
 * '<S52>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F05_Calibration_4_FuMass3Tmp
 * '<S53>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F06_Calibration_5_FuMass3Tmp
 * '<S54>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F07_Calibration_6_FuMass3Tmp
 * '<S55>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F08_Calibration_7_FuMass3Tmp
 * '<S56>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F09_Calibration_8_FuMass3Tmp
 * '<S57>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F10_Calibration_9_FuMass3Tmp
 * '<S58>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F11_Calibration_10_FuMass3Tmp
 * '<S59>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F12_Calibration_11_FuMass3Tmp
 * '<S60>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F13_Calibration_12_FuMass3Tmp
 * '<S61>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F14_Calibration_13_FuMass3Tmp
 * '<S62>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F20_Vectorize_Calibrations_FuMass3Tmp
 * '<S63>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F02_Calibration_1_FuMass3Tmp/Carto_2D4
 * '<S64>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F03_Calibration_2_FuMass3Tmp/Carto_2D5
 * '<S65>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F04_Calibration_3_FuMass3Tmp/Carto_2D6
 * '<S66>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F05_Calibration_4_FuMass3Tmp/Carto_2D7
 * '<S67>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F06_Calibration_5_FuMass3Tmp/Carto_2D8
 * '<S68>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F07_Calibration_6_FuMass3Tmp/Carto_2D9
 * '<S69>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F08_Calibration_7_FuMass3Tmp/Carto_2D10
 * '<S70>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F09_Calibration_8_FuMass3Tmp/Carto_2D11
 * '<S71>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F10_Calibration_9_FuMass3Tmp/Carto_2D12
 * '<S72>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F11_Calibration_10_FuMass3Tmp/Carto_2D13
 * '<S73>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F12_Calibration_11_FuMass3Tmp/Carto_2D14
 * '<S74>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F03_Calibrations_FuMass3Tmp/F13_Calibration_12_FuMass3Tmp/Carto_2D15
 * '<S75>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS1
 * '<S76>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS2
 * '<S77>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS3
 * '<S78>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS1/Clamp
 * '<S79>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited
 * '<S80>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS1/Clamp/Data Type Conversion Inherited1
 * '<S81>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS1/Clamp/Saturation Dynamic
 * '<S82>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS2/Clamp
 * '<S83>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS2/Clamp/Data Type Conversion Inherited
 * '<S84>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS2/Clamp/Data Type Conversion Inherited1
 * '<S85>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS2/Clamp/Saturation Dynamic
 * '<S86>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS3/Clamp
 * '<S87>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS3/Clamp/Data Type Conversion Inherited
 * '<S88>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS3/Clamp/Data Type Conversion Inherited1
 * '<S89>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F01_FuMass3Tmp/F05_Interpolation_FuMass3Tmp/BaryCentre_VEMS3/Clamp/Saturation Dynamic
 * '<S90>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp
 * '<S91>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp
 * '<S92>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F04_Select_Modes_FuMass2Tmp
 * '<S93>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp
 * '<S94>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp
 * '<S95>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp1
 * '<S96>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp2
 * '<S97>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp3
 * '<S98>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp/Data Type Conversion Inherited
 * '<S99>'  : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp/Data Type Conversion Inherited1
 * '<S100>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp/Saturation Dynamic
 * '<S101>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp1/Data Type Conversion Inherited
 * '<S102>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp1/Data Type Conversion Inherited1
 * '<S103>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp1/Saturation Dynamic
 * '<S104>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp2/Data Type Conversion Inherited
 * '<S105>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp2/Data Type Conversion Inherited1
 * '<S106>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp2/Saturation Dynamic
 * '<S107>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp3/Data Type Conversion Inherited
 * '<S108>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp3/Data Type Conversion Inherited1
 * '<S109>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F02_Mode_Mask_FuMass2Tmp/Clamp3/Saturation Dynamic
 * '<S110>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F01_Unvectorize_Activation_Boolean_FuMass2Tmp
 * '<S111>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F02_Calibration_1_FuMass2Tmp
 * '<S112>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F03_Calibration_2_FuMass2Tmp
 * '<S113>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F04_Calibration_3_FuMass2Tmp
 * '<S114>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F05_Calibration_4_FuMass2Tmp
 * '<S115>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F06_Calibration_5_FuMass2Tmp
 * '<S116>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F07_Calibration_6_FuMass2Tmp
 * '<S117>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F08_Calibration_7_FuMass2Tmp
 * '<S118>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F09_Calibration_8_FuMass2Tmp
 * '<S119>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F10_Calibration_9_FuMass2Tmp
 * '<S120>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F11_Calibration_10_FuMass2Tmp
 * '<S121>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F12_Calibration_11_FuMass2Tmp
 * '<S122>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F13_Calibration_12_FuMass2Tmp
 * '<S123>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F14_Calibration_13_FuMass2Tmp
 * '<S124>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F20_Vectorize_Calibrations_FuMass2Tmp
 * '<S125>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F02_Calibration_1_FuMass2Tmp/Carto_2D16
 * '<S126>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F03_Calibration_2_FuMass2Tmp/Carto_2D17
 * '<S127>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F04_Calibration_3_FuMass2Tmp/Carto_2D18
 * '<S128>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F05_Calibration_4_FuMass2Tmp/Carto_2D19
 * '<S129>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F06_Calibration_5_FuMass2Tmp/Carto_2D20
 * '<S130>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F07_Calibration_6_FuMass2Tmp/Carto_2D21
 * '<S131>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F08_Calibration_7_FuMass2Tmp/Carto_2D22
 * '<S132>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F09_Calibration_8_FuMass2Tmp/Carto_2D23
 * '<S133>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F10_Calibration_9_FuMass2Tmp/Carto_2D24
 * '<S134>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F11_Calibration_10_FuMass2Tmp/Carto_2D25
 * '<S135>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F12_Calibration_11_FuMass2Tmp/Carto_2D26
 * '<S136>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F03_Calibrations_FuMass2Tmp/F13_Calibration_12_FuMass2Tmp/Carto_2D27
 * '<S137>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS2
 * '<S138>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS3
 * '<S139>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS4
 * '<S140>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS2/Clamp
 * '<S141>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS2/Clamp/Data Type Conversion Inherited
 * '<S142>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS2/Clamp/Data Type Conversion Inherited1
 * '<S143>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS2/Clamp/Saturation Dynamic
 * '<S144>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS3/Clamp
 * '<S145>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS3/Clamp/Data Type Conversion Inherited
 * '<S146>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS3/Clamp/Data Type Conversion Inherited1
 * '<S147>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS3/Clamp/Saturation Dynamic
 * '<S148>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS4/Clamp
 * '<S149>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS4/Clamp/Data Type Conversion Inherited
 * '<S150>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS4/Clamp/Data Type Conversion Inherited1
 * '<S151>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F02_FuMass2Tmp/F05_Interpolation_FuMass2Tmp/BaryCentre_VEMS4/Clamp/Saturation Dynamic
 * '<S152>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/Clamp
 * '<S153>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/Clamp1
 * '<S154>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/SingleToFixdt
 * '<S155>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/SingleToFixdt1
 * '<S156>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/SingleToFixdt2
 * '<S157>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/Clamp/Data Type Conversion Inherited
 * '<S158>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/Clamp/Data Type Conversion Inherited1
 * '<S159>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/Clamp/Saturation Dynamic
 * '<S160>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/Clamp1/Data Type Conversion Inherited
 * '<S161>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/Clamp1/Data Type Conversion Inherited1
 * '<S162>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F03_SatInj/Clamp1/Saturation Dynamic
 * '<S163>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F05_FuMass/SingleToFixdt
 * '<S164>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F05_FuMass/SingleToFixdt1
 * '<S165>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F05_FuMass/division_411
 * '<S166>' : rInjSp_AUTOCODE/rInjSp/F02_rInjSp/F02_rInjSp/F01_FuMassClcn/F05_FuMass/division_421
 */

/*-
 * Requirements for '<Root>': rInjSp
 */
#endif                                 /* RTW_HEADER_rInjSp_h_ */

/*-------------------------------- end of file -------------------------------*/
