/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSysSpCrk                                             */
/* !Description     : InjSysSpCrk : INJECTION SETPOINTS FOR START             */
/*                                                                            */
/* !Module          : InjSysSpCrk                                             */
/*                                                                            */
/* !File            : InjSysSpCrk.h                                           */
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
/*   Code generated on: Thu Feb 14 12:28:19 2013                              */
/*   Model name       : InjSysSpCrk_AUTOCODE.mdl                              */
/*   Model version    : 1.113                                                 */
/*   Root subsystem   : /InjSysSpCrk                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJSYSSPCRK/InjSysSpCrk.h_$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   21 Feb 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjSysSpCrk_h_
#define RTW_HEADER_InjSysSpCrk_h_
#ifndef InjSysSpCrk_COMMON_INCLUDES_
# define InjSysSpCrk_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "InjSysSpCrk_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#endif                                 /* InjSysSpCrk_COMMON_INCLUDES_ */

#include "InjSysSpCrk_types.h"

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
  SInt16 VEMS_vidGET3;                /* '<S55>/VEMS_vidGET3' */
  SInt16 VEMS_vidGET4;                /* '<S15>/VEMS_vidGET4' */
  SInt16 VEMS_vidGET3_g;              /* '<S172>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET2;               /* '<S55>/VEMS_vidGET2' */
  UInt16 VEMS_vidGET3_n;             /* '<S15>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET2_g;             /* '<S172>/VEMS_vidGET2' */
  UInt16 Merge;                      /* '<S15>/Merge' */
  UInt16 Merge1;                     /* '<S15>/Merge1' */
  UInt16 Merge2;                     /* '<S15>/Merge2' */
  UInt16 Merge_m;                    /* '<S172>/Merge' */
  UInt16 Merge_n;                    /* '<S55>/Merge' */
  UInt16 Merge1_d;                   /* '<S55>/Merge1' */
  UInt16 Merge2_n;                   /* '<S55>/Merge2' */
  Boolean VEMS_vidGET5;              /* '<S55>/VEMS_vidGET5' */
  Boolean VEMS_vidGET8;              /* '<S55>/VEMS_vidGET8' */
  Boolean VEMS_vidGET1;              /* '<S55>/VEMS_vidGET1' */
  Boolean VEMS_vidGET;               /* '<S55>/VEMS_vidGET' */
  Boolean VEMS_vidGET4_d;            /* '<S55>/VEMS_vidGET4' */
  Boolean VEMS_vidGET6;              /* '<S55>/VEMS_vidGET6' */
  Boolean VEMS_vidGET7;              /* '<S55>/VEMS_vidGET7' */
  Boolean VEMS_vidGET2_a;            /* '<S15>/VEMS_vidGET2' */
  Boolean VEMS_vidGET1_e;            /* '<S15>/VEMS_vidGET1' */
  Boolean VEMS_vidGET5_i;            /* '<S15>/VEMS_vidGET5' */
  Boolean VEMS_vidGET_a;             /* '<S15>/VEMS_vidGET' */
  Boolean VEMS_vidGET6_e;            /* '<S15>/VEMS_vidGET6' */
  Boolean VEMS_vidGET9;              /* '<S15>/VEMS_vidGET9' */
  Boolean VEMS_vidGET7_b;            /* '<S15>/VEMS_vidGET7' */
  Boolean VEMS_vidGET8_d;            /* '<S15>/VEMS_vidGET8' */
  Boolean VEMS_vidGET_i;             /* '<S14>/VEMS_vidGET' */
  Boolean VEMS_vidGET1_b;            /* '<S14>/VEMS_vidGET1' */
  Boolean VEMS_vidGET2_b;            /* '<S14>/VEMS_vidGET2' */
  Boolean LogicalOperator7;          /* '<S14>/Logical Operator7' */
  Boolean VEMS_vidGET1_eo;           /* '<S172>/VEMS_vidGET1' */
  Boolean VEMS_vidGET_a4;            /* '<S172>/VEMS_vidGET' */
  Boolean VEMS_vidGET4_b;            /* '<S172>/VEMS_vidGET4' */
  Boolean VEMS_vidGET5_o;            /* '<S172>/VEMS_vidGET5' */
  Boolean VEMS_vidGET6_h;            /* '<S172>/VEMS_vidGET6' */
  Boolean VEMS_vidGET7_k;            /* '<S172>/VEMS_vidGET7' */
} BlockIO_InjSysSpCrk;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJSYSSPCRK_START_SEC_VAR_UNSPECIFIED
#include "InjSysSpCrk_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InjSysSpCrk InjSysSpCrk_B;

#define INJSYSSPCRK_STOP_SEC_VAR_UNSPECIFIED
#include "InjSysSpCrk_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define INJSYSSPCRK_START_SEC_CODE
#include "InjSysSpCrk_MemMap.h"

/* Model entry point functions */
extern void InjSysSpCrk_initialize(void);
extern void InjSys_SdlFast_InjSysSpCrk(void);
extern void InjSys_EveStTR_InjSysSpCrk(void);
extern void InjSys_EveSpl_InjSysSpCrk(void);
extern void InjSys_EveRst_InjSysSpCrk(void);

#define INJSYSSPCRK_STOP_SEC_CODE
#include "InjSysSpCrk_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define INJSYSSPCRK_START_SEC_CALIB_16BIT
#include "InjSysSpCrk_MemMap.h"

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, INJSYSSPCRK_CALIB) Ext_nEngRef3_A[9];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1FrstInj_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModHBasCrkSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModHBasCrk_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModHIntrSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModHLPCrkSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModHLPCrk_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModSplIntrSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModSplstBasSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModSplstBas_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModSplstLPSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj1ModSplstLP_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2FrstInj_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2ModSplIntrSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2ModSplstBasSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2ModSplstBas_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2ModSplstLPSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2ModSplstLP_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2ModSstBasSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2ModSstBas_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agBegInj2ModSstIntrSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3FrstInj_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3ModSplIntrSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3ModSplstBasSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3ModSplstBas_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3ModSplstLPSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3ModSplstLP_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3ModSstBasSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3ModSstBas_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agEndInj3ModSstIntrSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agInj1CrkSpDft_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agInj2CrkSpDft_C;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_agInj3CrkSpDft_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModHCrkSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModHCrk_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModHLPCrkSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModHLPCrk_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModSplstLPSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModSplstLP_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModSplstSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModSplst_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModSstSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_pFuCrkSpModSst_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj2CrkSpModSplBasSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj2CrkSpModSplBas_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj2CrkSpModSplLPSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj2CrkSpModSplLP_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj2FrstInj_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj3CrkSpModSplBasSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj3CrkSpModSplBas_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj3CrkSpModSplLPSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj3CrkSpModSplLP_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj3CrkSpModSstBasSTT_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj3CrkSpModSstBas_M[144];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(UInt16, INJSYSSPCRK_CALIB) InjSys_rInj3FrstInj_M[144];

#define INJSYSSPCRK_STOP_SEC_CALIB_16BIT
#include "InjSysSpCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define INJSYSSPCRK_START_SEC_CALIB_BOOLEAN
#include "InjSysSpCrk_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJSYSSPCRK_CALIB) InjSys_bInhFrstInjSp_C;

#define INJSYSSPCRK_STOP_SEC_CALIB_BOOLEAN
#include "InjSysSpCrk_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJSYSSPCRK_START_SEC_VAR_16BIT
#include "InjSysSpCrk_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSYSSPCRK_VAR) InjSys_agInj1CrkSp;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSYSSPCRK_VAR) InjSys_agInj2CrkSp;

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern VAR(UInt16, INJSYSSPCRK_VAR) InjSys_agInj3CrkSp;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, INJSYSSPCRK_VAR) InjSys_pFuCrkSp;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, INJSYSSPCRK_VAR) InjSys_rInj1CrkSp;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, INJSYSSPCRK_VAR) InjSys_rInj2CrkSp;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(UInt16, INJSYSSPCRK_VAR) InjSys_rInj3CrkSp;

#define INJSYSSPCRK_STOP_SEC_VAR_16BIT
#include "InjSysSpCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJSYSSPCRK_START_SEC_VAR_BOOLEAN
#include "InjSysSpCrk_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJSYSSPCRK_VAR) InjSys_bAcvFrstInjSp;

#define INJSYSSPCRK_STOP_SEC_VAR_BOOLEAN
#include "InjSysSpCrk_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S22>/TABLE' : Unused code path elimination
 * Block '<S22>/TABLE1' : Unused code path elimination
 * Block '<S22>/TABLE2' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S23>/TABLE' : Unused code path elimination
 * Block '<S23>/TABLE1' : Unused code path elimination
 * Block '<S23>/TABLE2' : Unused code path elimination
 * Block '<S20>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S20>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S20>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S20>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S24>/TABLE' : Unused code path elimination
 * Block '<S24>/TABLE1' : Unused code path elimination
 * Block '<S24>/TABLE2' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S25>/TABLE' : Unused code path elimination
 * Block '<S25>/TABLE1' : Unused code path elimination
 * Block '<S25>/TABLE2' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S26>/TABLE' : Unused code path elimination
 * Block '<S26>/TABLE1' : Unused code path elimination
 * Block '<S26>/TABLE2' : Unused code path elimination
 * Block '<S21>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S21>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S21>/Ext_nEngRef3_A_2' : Unused code path elimination
 * Block '<S21>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S21>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S21>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S29>/TABLE' : Unused code path elimination
 * Block '<S29>/TABLE1' : Unused code path elimination
 * Block '<S29>/TABLE2' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S30>/TABLE' : Unused code path elimination
 * Block '<S30>/TABLE1' : Unused code path elimination
 * Block '<S30>/TABLE2' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S31>/TABLE' : Unused code path elimination
 * Block '<S31>/TABLE1' : Unused code path elimination
 * Block '<S31>/TABLE2' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S32>/TABLE' : Unused code path elimination
 * Block '<S32>/TABLE1' : Unused code path elimination
 * Block '<S32>/TABLE2' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S33>/TABLE' : Unused code path elimination
 * Block '<S33>/TABLE1' : Unused code path elimination
 * Block '<S33>/TABLE2' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S34>/TABLE' : Unused code path elimination
 * Block '<S34>/TABLE1' : Unused code path elimination
 * Block '<S34>/TABLE2' : Unused code path elimination
 * Block '<S27>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S27>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S27>/Ext_nEngRef3_A_2' : Unused code path elimination
 * Block '<S27>/Ext_nEngRef3_A_3' : Unused code path elimination
 * Block '<S27>/Ext_nEngRef3_A_4' : Unused code path elimination
 * Block '<S27>/Ext_nEngRef3_A_5' : Unused code path elimination
 * Block '<S27>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S27>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S27>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S27>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S27>/Ext_tCoMes_A_4' : Unused code path elimination
 * Block '<S27>/Ext_tCoMes_A_5' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S35>/TABLE' : Unused code path elimination
 * Block '<S35>/TABLE1' : Unused code path elimination
 * Block '<S35>/TABLE2' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/TABLE' : Unused code path elimination
 * Block '<S36>/TABLE1' : Unused code path elimination
 * Block '<S36>/TABLE2' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S37>/TABLE' : Unused code path elimination
 * Block '<S37>/TABLE1' : Unused code path elimination
 * Block '<S37>/TABLE2' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S38>/TABLE' : Unused code path elimination
 * Block '<S38>/TABLE1' : Unused code path elimination
 * Block '<S38>/TABLE2' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S39>/TABLE' : Unused code path elimination
 * Block '<S39>/TABLE1' : Unused code path elimination
 * Block '<S39>/TABLE2' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S40>/TABLE' : Unused code path elimination
 * Block '<S40>/TABLE1' : Unused code path elimination
 * Block '<S40>/TABLE2' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S41>/TABLE' : Unused code path elimination
 * Block '<S41>/TABLE1' : Unused code path elimination
 * Block '<S41>/TABLE2' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S42>/TABLE' : Unused code path elimination
 * Block '<S42>/TABLE1' : Unused code path elimination
 * Block '<S42>/TABLE2' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S43>/TABLE' : Unused code path elimination
 * Block '<S43>/TABLE1' : Unused code path elimination
 * Block '<S43>/TABLE2' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A_2' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A_3' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A_4' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A_5' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A_6' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A_7' : Unused code path elimination
 * Block '<S28>/Ext_nEngRef3_A_8' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A_4' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A_5' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A_6' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A_7' : Unused code path elimination
 * Block '<S28>/Ext_tCoMes_A_8' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S46>/TABLE' : Unused code path elimination
 * Block '<S46>/TABLE1' : Unused code path elimination
 * Block '<S46>/TABLE2' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S47>/TABLE' : Unused code path elimination
 * Block '<S47>/TABLE1' : Unused code path elimination
 * Block '<S47>/TABLE2' : Unused code path elimination
 * Block '<S44>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S44>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S44>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S44>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S48>/TABLE' : Unused code path elimination
 * Block '<S48>/TABLE1' : Unused code path elimination
 * Block '<S48>/TABLE2' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S49>/TABLE' : Unused code path elimination
 * Block '<S49>/TABLE1' : Unused code path elimination
 * Block '<S49>/TABLE2' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S50>/TABLE' : Unused code path elimination
 * Block '<S50>/TABLE1' : Unused code path elimination
 * Block '<S50>/TABLE2' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S51>/TABLE' : Unused code path elimination
 * Block '<S51>/TABLE1' : Unused code path elimination
 * Block '<S51>/TABLE2' : Unused code path elimination
 * Block '<S45>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S45>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S45>/Ext_nEngRef3_A_2' : Unused code path elimination
 * Block '<S45>/Ext_nEngRef3_A_3' : Unused code path elimination
 * Block '<S45>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S45>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S45>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S45>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S52>/TABLE' : Unused code path elimination
 * Block '<S52>/TABLE1' : Unused code path elimination
 * Block '<S52>/TABLE2' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S53>/TABLE' : Unused code path elimination
 * Block '<S53>/TABLE1' : Unused code path elimination
 * Block '<S53>/TABLE2' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S54>/TABLE' : Unused code path elimination
 * Block '<S54>/TABLE1' : Unused code path elimination
 * Block '<S54>/TABLE2' : Unused code path elimination
 * Block '<S19>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S19>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S19>/Ext_nEngRef3_A_2' : Unused code path elimination
 * Block '<S19>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S19>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S19>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S62>/TABLE' : Unused code path elimination
 * Block '<S62>/TABLE1' : Unused code path elimination
 * Block '<S62>/TABLE2' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S63>/TABLE' : Unused code path elimination
 * Block '<S63>/TABLE1' : Unused code path elimination
 * Block '<S63>/TABLE2' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S64>/TABLE' : Unused code path elimination
 * Block '<S64>/TABLE1' : Unused code path elimination
 * Block '<S64>/TABLE2' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S65>/TABLE' : Unused code path elimination
 * Block '<S65>/TABLE1' : Unused code path elimination
 * Block '<S65>/TABLE2' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Relational Operator' : Unused code path elimination
 * Block '<S66>/Relational Operator1' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Propagation' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Relational Operator' : Unused code path elimination
 * Block '<S67>/Relational Operator1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Propagation' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Relational Operator' : Unused code path elimination
 * Block '<S68>/Relational Operator1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Propagation' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Relational Operator' : Unused code path elimination
 * Block '<S69>/Relational Operator1' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Data Type Propagation' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Relational Operator' : Unused code path elimination
 * Block '<S70>/Relational Operator1' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Propagation' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Relational Operator' : Unused code path elimination
 * Block '<S71>/Relational Operator1' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Propagation' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Relational Operator' : Unused code path elimination
 * Block '<S72>/Relational Operator1' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Data Type Propagation' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Relational Operator' : Unused code path elimination
 * Block '<S73>/Relational Operator1' : Unused code path elimination
 * Block '<S97>/Data Type Duplicate' : Unused code path elimination
 * Block '<S97>/Data Type Propagation' : Unused code path elimination
 * Block '<S60>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S60>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S60>/Ext_nEngRef3_A_2' : Unused code path elimination
 * Block '<S60>/Ext_nEngRef3_A_3' : Unused code path elimination
 * Block '<S60>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S60>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S60>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S60>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S98>/TABLE' : Unused code path elimination
 * Block '<S98>/TABLE1' : Unused code path elimination
 * Block '<S98>/TABLE2' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S99>/TABLE' : Unused code path elimination
 * Block '<S99>/TABLE1' : Unused code path elimination
 * Block '<S99>/TABLE2' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S100>/TABLE' : Unused code path elimination
 * Block '<S100>/TABLE1' : Unused code path elimination
 * Block '<S100>/TABLE2' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S101>/TABLE' : Unused code path elimination
 * Block '<S101>/TABLE1' : Unused code path elimination
 * Block '<S101>/TABLE2' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate' : Unused code path elimination
 * Block '<S111>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Relational Operator' : Unused code path elimination
 * Block '<S102>/Relational Operator1' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Data Type Propagation' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 * Block '<S114>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Relational Operator' : Unused code path elimination
 * Block '<S103>/Relational Operator1' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Data Type Propagation' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Relational Operator' : Unused code path elimination
 * Block '<S104>/Relational Operator1' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S118>/Data Type Propagation' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Relational Operator' : Unused code path elimination
 * Block '<S105>/Relational Operator1' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Propagation' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Relational Operator' : Unused code path elimination
 * Block '<S106>/Relational Operator1' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Propagation' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Relational Operator' : Unused code path elimination
 * Block '<S107>/Relational Operator1' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Propagation' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Relational Operator' : Unused code path elimination
 * Block '<S108>/Relational Operator1' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Propagation' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Relational Operator' : Unused code path elimination
 * Block '<S109>/Relational Operator1' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Propagation' : Unused code path elimination
 * Block '<S61>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S61>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S61>/Ext_nEngRef3_A_2' : Unused code path elimination
 * Block '<S61>/Ext_nEngRef3_A_3' : Unused code path elimination
 * Block '<S61>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S61>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S61>/Ext_tCoMes_A_2' : Unused code path elimination
 * Block '<S61>/Ext_tCoMes_A_3' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S136>/TABLE' : Unused code path elimination
 * Block '<S136>/TABLE1' : Unused code path elimination
 * Block '<S136>/TABLE2' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S140>/Data Type Duplicate' : Unused code path elimination
 * Block '<S137>/Relational Operator' : Unused code path elimination
 * Block '<S137>/Relational Operator1' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S141>/Data Type Propagation' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate' : Unused code path elimination
 * Block '<S143>/Data Type Duplicate' : Unused code path elimination
 * Block '<S138>/Relational Operator' : Unused code path elimination
 * Block '<S138>/Relational Operator1' : Unused code path elimination
 * Block '<S144>/Data Type Duplicate' : Unused code path elimination
 * Block '<S144>/Data Type Propagation' : Unused code path elimination
 * Block '<S134>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S134>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S145>/TABLE' : Unused code path elimination
 * Block '<S145>/TABLE1' : Unused code path elimination
 * Block '<S145>/TABLE2' : Unused code path elimination
 * Block '<S148>/Data Type Duplicate' : Unused code path elimination
 * Block '<S149>/Data Type Duplicate' : Unused code path elimination
 * Block '<S146>/Relational Operator' : Unused code path elimination
 * Block '<S146>/Relational Operator1' : Unused code path elimination
 * Block '<S150>/Data Type Duplicate' : Unused code path elimination
 * Block '<S150>/Data Type Propagation' : Unused code path elimination
 * Block '<S151>/Data Type Duplicate' : Unused code path elimination
 * Block '<S152>/Data Type Duplicate' : Unused code path elimination
 * Block '<S147>/Relational Operator' : Unused code path elimination
 * Block '<S147>/Relational Operator1' : Unused code path elimination
 * Block '<S153>/Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/Data Type Propagation' : Unused code path elimination
 * Block '<S135>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S135>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S154>/TABLE' : Unused code path elimination
 * Block '<S154>/TABLE1' : Unused code path elimination
 * Block '<S154>/TABLE2' : Unused code path elimination
 * Block '<S155>/Data Type Duplicate' : Unused code path elimination
 * Block '<S155>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S155>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S155>/TABLE' : Unused code path elimination
 * Block '<S155>/TABLE1' : Unused code path elimination
 * Block '<S155>/TABLE2' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Relational Operator' : Unused code path elimination
 * Block '<S156>/Relational Operator1' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Propagation' : Unused code path elimination
 * Block '<S163>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Relational Operator' : Unused code path elimination
 * Block '<S157>/Relational Operator1' : Unused code path elimination
 * Block '<S165>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Data Type Propagation' : Unused code path elimination
 * Block '<S166>/Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Relational Operator' : Unused code path elimination
 * Block '<S158>/Relational Operator1' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Propagation' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S159>/Relational Operator' : Unused code path elimination
 * Block '<S159>/Relational Operator1' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Propagation' : Unused code path elimination
 * Block '<S59>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S59>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S59>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S59>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S178>/TABLE' : Unused code path elimination
 * Block '<S178>/TABLE1' : Unused code path elimination
 * Block '<S178>/TABLE2' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S179>/TABLE' : Unused code path elimination
 * Block '<S179>/TABLE1' : Unused code path elimination
 * Block '<S179>/TABLE2' : Unused code path elimination
 * Block '<S176>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S176>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S176>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S176>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S180>/TABLE' : Unused code path elimination
 * Block '<S180>/TABLE1' : Unused code path elimination
 * Block '<S180>/TABLE2' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S181>/TABLE' : Unused code path elimination
 * Block '<S181>/TABLE1' : Unused code path elimination
 * Block '<S181>/TABLE2' : Unused code path elimination
 * Block '<S177>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S177>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S177>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S177>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S184>/TABLE' : Unused code path elimination
 * Block '<S184>/TABLE1' : Unused code path elimination
 * Block '<S184>/TABLE2' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S185>/TABLE' : Unused code path elimination
 * Block '<S185>/TABLE1' : Unused code path elimination
 * Block '<S185>/TABLE2' : Unused code path elimination
 * Block '<S182>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S182>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S182>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S182>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S186>/TABLE' : Unused code path elimination
 * Block '<S186>/TABLE1' : Unused code path elimination
 * Block '<S186>/TABLE2' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S187>/TABLE' : Unused code path elimination
 * Block '<S187>/TABLE1' : Unused code path elimination
 * Block '<S187>/TABLE2' : Unused code path elimination
 * Block '<S183>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S183>/Ext_nEngRef3_A_1' : Unused code path elimination
 * Block '<S183>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S183>/Ext_tCoMes_A_1' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S190>/TABLE' : Unused code path elimination
 * Block '<S190>/TABLE1' : Unused code path elimination
 * Block '<S190>/TABLE2' : Unused code path elimination
 * Block '<S188>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S188>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S191>/TABLE' : Unused code path elimination
 * Block '<S191>/TABLE1' : Unused code path elimination
 * Block '<S191>/TABLE2' : Unused code path elimination
 * Block '<S189>/Ext_nEngRef3_A' : Unused code path elimination
 * Block '<S189>/Ext_tCoMes_A' : Unused code path elimination
 * Block '<S60>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S60>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S60>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S60>/Signal Conversion5' : Eliminate redundant signal conversion block
 * Block '<S61>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S61>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S61>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S61>/Signal Conversion5' : Eliminate redundant signal conversion block
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
 * hilite_system('InjSysSpCrk_AUTOCODE/InjSysSpCrk')    - opens subsystem InjSysSpCrk_AUTOCODE/InjSysSpCrk
 * hilite_system('InjSysSpCrk_AUTOCODE/InjSysSpCrk/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InjSysSpCrk_AUTOCODE
 * '<S1>'   : InjSysSpCrk_AUTOCODE/InjSysSpCrk
 * '<S6>'   : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F00_FrstInjMgr
 * '<S7>'   : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn
 * '<S8>'   : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn
 * '<S9>'   : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn
 * '<S10>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/fc_demux1
 * '<S11>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/fc_demux2
 * '<S12>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F00_FrstInjMgr/F00_Init
 * '<S13>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F00_FrstInjMgr/F01_AuthFrstInjAdap
 * '<S14>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F00_FrstInjMgr/F01_AuthFrstInjAdap/F01_AuthFrstInjAdap_Inhib
 * '<S15>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib
 * '<S16>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F01_HomAg
 * '<S17>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg
 * '<S18>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg
 * '<S19>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F04_FrstInjAg
 * '<S20>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F01_HomAg/F01_HomCrkAgSTT
 * '<S21>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F01_HomAg/F02_HomCrkAgWoSTT
 * '<S22>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F01_HomAg/F01_HomCrkAgSTT/Carto_2D1
 * '<S23>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F01_HomAg/F01_HomCrkAgSTT/Carto_2D2
 * '<S24>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F01_HomAg/F02_HomCrkAgWoSTT/Carto_2D3
 * '<S25>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F01_HomAg/F02_HomCrkAgWoSTT/Carto_2D4
 * '<S26>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F01_HomAg/F02_HomCrkAgWoSTT/Carto_2D5
 * '<S27>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F01_SplitStrtAgSTT
 * '<S28>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT
 * '<S29>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F01_SplitStrtAgSTT/Carto_2D10
 * '<S30>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F01_SplitStrtAgSTT/Carto_2D11
 * '<S31>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F01_SplitStrtAgSTT/Carto_2D6
 * '<S32>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F01_SplitStrtAgSTT/Carto_2D7
 * '<S33>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F01_SplitStrtAgSTT/Carto_2D8
 * '<S34>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F01_SplitStrtAgSTT/Carto_2D9
 * '<S35>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D12
 * '<S36>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D13
 * '<S37>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D14
 * '<S38>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D15
 * '<S39>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D16
 * '<S40>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D17
 * '<S41>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D18
 * '<S42>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D19
 * '<S43>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F02_SplitStrtAg/F02_SplitAgStrtWoSTT/Carto_2D20
 * '<S44>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg/F01_SStrtAgSTT
 * '<S45>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg/F02_SStrtAgWoSTT
 * '<S46>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg/F01_SStrtAgSTT/Carto_2D21
 * '<S47>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg/F01_SStrtAgSTT/Carto_2D22
 * '<S48>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg/F02_SStrtAgWoSTT/Carto_2D23
 * '<S49>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg/F02_SStrtAgWoSTT/Carto_2D24
 * '<S50>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg/F02_SStrtAgWoSTT/Carto_2D25
 * '<S51>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F03_SStrtAg/F02_SStrtAgWoSTT/Carto_2D26
 * '<S52>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F04_FrstInjAg/Carto_2D27
 * '<S53>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F04_FrstInjAg/Carto_2D28
 * '<S54>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F01_InjPhaClcn/F01_InjPhaClcn_Inhib/F04_FrstInjAg/Carto_2D29
 * '<S55>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib
 * '<S56>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F01_HomFrac
 * '<S57>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac
 * '<S58>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac
 * '<S59>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac
 * '<S60>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT
 * '<S61>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT
 * '<S62>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Carto_2D30
 * '<S63>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Carto_2D31
 * '<S64>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Carto_2D32
 * '<S65>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Carto_2D33
 * '<S66>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp
 * '<S67>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp1
 * '<S68>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp2
 * '<S69>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp3
 * '<S70>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp4
 * '<S71>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp5
 * '<S72>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp6
 * '<S73>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp7
 * '<S74>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp/Data Type Conversion Inherited
 * '<S75>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp/Data Type Conversion Inherited1
 * '<S76>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp/Saturation Dynamic
 * '<S77>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp1/Data Type Conversion Inherited
 * '<S78>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp1/Data Type Conversion Inherited1
 * '<S79>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp1/Saturation Dynamic
 * '<S80>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp2/Data Type Conversion Inherited
 * '<S81>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp2/Data Type Conversion Inherited1
 * '<S82>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp2/Saturation Dynamic
 * '<S83>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp3/Data Type Conversion Inherited
 * '<S84>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp3/Data Type Conversion Inherited1
 * '<S85>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp3/Saturation Dynamic
 * '<S86>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp4/Data Type Conversion Inherited
 * '<S87>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp4/Data Type Conversion Inherited1
 * '<S88>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp4/Saturation Dynamic
 * '<S89>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp5/Data Type Conversion Inherited
 * '<S90>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp5/Data Type Conversion Inherited1
 * '<S91>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp5/Saturation Dynamic
 * '<S92>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp6/Data Type Conversion Inherited
 * '<S93>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp6/Data Type Conversion Inherited1
 * '<S94>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp6/Saturation Dynamic
 * '<S95>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp7/Data Type Conversion Inherited
 * '<S96>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp7/Data Type Conversion Inherited1
 * '<S97>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F01_SplStrtFracSTT/Clamp7/Saturation Dynamic
 * '<S98>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Carto_2D34
 * '<S99>'  : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Carto_2D35
 * '<S100>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Carto_2D36
 * '<S101>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Carto_2D37
 * '<S102>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp
 * '<S103>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp1
 * '<S104>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp2
 * '<S105>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp3
 * '<S106>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp4
 * '<S107>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp5
 * '<S108>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp6
 * '<S109>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp7
 * '<S110>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp/Data Type Conversion Inherited
 * '<S111>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp/Data Type Conversion Inherited1
 * '<S112>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp/Saturation Dynamic
 * '<S113>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp1/Data Type Conversion Inherited
 * '<S114>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp1/Data Type Conversion Inherited1
 * '<S115>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp1/Saturation Dynamic
 * '<S116>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp2/Data Type Conversion Inherited
 * '<S117>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp2/Data Type Conversion Inherited1
 * '<S118>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp2/Saturation Dynamic
 * '<S119>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp3/Data Type Conversion Inherited
 * '<S120>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp3/Data Type Conversion Inherited1
 * '<S121>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp3/Saturation Dynamic
 * '<S122>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp4/Data Type Conversion Inherited
 * '<S123>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp4/Data Type Conversion Inherited1
 * '<S124>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp4/Saturation Dynamic
 * '<S125>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp5/Data Type Conversion Inherited
 * '<S126>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp5/Data Type Conversion Inherited1
 * '<S127>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp5/Saturation Dynamic
 * '<S128>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp6/Data Type Conversion Inherited
 * '<S129>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp6/Data Type Conversion Inherited1
 * '<S130>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp6/Saturation Dynamic
 * '<S131>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp7/Data Type Conversion Inherited
 * '<S132>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp7/Data Type Conversion Inherited1
 * '<S133>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F02_SplStrtFrac/F02_SplStrtFracWoSTT/Clamp7/Saturation Dynamic
 * '<S134>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT
 * '<S135>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT
 * '<S136>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Carto_2D38
 * '<S137>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Clamp
 * '<S138>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Clamp1
 * '<S139>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Clamp/Data Type Conversion Inherited
 * '<S140>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Clamp/Data Type Conversion Inherited1
 * '<S141>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Clamp/Saturation Dynamic
 * '<S142>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Clamp1/Data Type Conversion Inherited
 * '<S143>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Clamp1/Data Type Conversion Inherited1
 * '<S144>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F01_SStrtFracSTT/Clamp1/Saturation Dynamic
 * '<S145>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Carto_2D39
 * '<S146>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Clamp
 * '<S147>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Clamp1
 * '<S148>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Clamp/Data Type Conversion Inherited
 * '<S149>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Clamp/Data Type Conversion Inherited1
 * '<S150>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Clamp/Saturation Dynamic
 * '<S151>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Clamp1/Data Type Conversion Inherited
 * '<S152>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Clamp1/Data Type Conversion Inherited1
 * '<S153>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F03_SStrtFrac/F02_SStrtFracWoSTT/Clamp1/Saturation Dynamic
 * '<S154>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Carto_2D40
 * '<S155>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Carto_2D41
 * '<S156>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp
 * '<S157>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp1
 * '<S158>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp2
 * '<S159>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp3
 * '<S160>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp/Data Type Conversion Inherited
 * '<S161>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp/Data Type Conversion Inherited1
 * '<S162>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp/Saturation Dynamic
 * '<S163>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp1/Data Type Conversion Inherited
 * '<S164>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp1/Data Type Conversion Inherited1
 * '<S165>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp1/Saturation Dynamic
 * '<S166>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp2/Data Type Conversion Inherited
 * '<S167>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp2/Data Type Conversion Inherited1
 * '<S168>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp2/Saturation Dynamic
 * '<S169>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp3/Data Type Conversion Inherited
 * '<S170>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp3/Data Type Conversion Inherited1
 * '<S171>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F02_rInjSpClcn/F02_rInjSpClcn_Inhib/F04_FrstInjFrac/Clamp3/Saturation Dynamic
 * '<S172>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib
 * '<S173>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F01_ModHPrail
 * '<S174>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F02_SplitStrtPrail
 * '<S175>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F03_SStrtPrail
 * '<S176>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F01_ModHPrail/F01_ModHSTT
 * '<S177>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F01_ModHPrail/F02_ModHWoSTT
 * '<S178>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F01_ModHPrail/F01_ModHSTT/Carto_2D42
 * '<S179>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F01_ModHPrail/F01_ModHSTT/Carto_2D43
 * '<S180>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F01_ModHPrail/F02_ModHWoSTT/Carto_2D44
 * '<S181>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F01_ModHPrail/F02_ModHWoSTT/Carto_2D45
 * '<S182>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F02_SplitStrtPrail/F01_SplitStrtPrailSTT
 * '<S183>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F02_SplitStrtPrail/F02_SplitStrtPrailWoSTT
 * '<S184>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F02_SplitStrtPrail/F01_SplitStrtPrailSTT/Carto_2D46
 * '<S185>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F02_SplitStrtPrail/F01_SplitStrtPrailSTT/Carto_2D47
 * '<S186>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F02_SplitStrtPrail/F02_SplitStrtPrailWoSTT/Carto_2D48
 * '<S187>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F02_SplitStrtPrail/F02_SplitStrtPrailWoSTT/Carto_2D49
 * '<S188>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F03_SStrtPrail/F01_SStrtPrailSTT
 * '<S189>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F03_SStrtPrail/F02_SStrtPrailWoSTT
 * '<S190>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F03_SStrtPrail/F01_SStrtPrailSTT/Carto_2D50
 * '<S191>' : InjSysSpCrk_AUTOCODE/InjSysSpCrk/F03_PfurailClcn/F03_PfurailClcn_Inhib/F03_SStrtPrail/F02_SStrtPrailWoSTT/Carto_2D51
 */

/*-
 * Requirements for '<Root>': InjSysSpCrk
 *
 * Inherited requirements for '<S1>/F01_InjPhaClcn':
 *  1. SubSystem "F01_InjPhaClcn" !Trace_To : VEMS_E_11_01572_003.01 ;
 *
 * Inherited requirements for '<S1>/F03_PfurailClcn':
 *  1. SubSystem "F03_PfurailClcn" !Trace_To : VEMS_E_11_01572_007.01 ;

 */
#endif                                 /* RTW_HEADER_InjSysSpCrk_h_ */

/*-------------------------------- end of file -------------------------------*/
