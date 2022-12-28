/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pCylM                                                   */
/* !Description     : CYLINDER PRESSURE ESTIMATOR                             */
/*                                                                            */
/* !Module          : pCylM                                                   */
/*                                                                            */
/* !File            : pCylM.h                                                 */
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
/*   Code generated on: Tue Dec 06 14:44:34 2011                              */
/*   Model name       : pCylM_AUTOCODE.mdl                                    */
/*   Model version    : 1.181                                                 */
/*   Root subsystem   : /pCylM                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PCYLM/pCylM.h_v           $*/
/* $Revision::   1.6                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   08 Dec 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_pCylM_h_
#define RTW_HEADER_pCylM_h_
#ifndef pCylM_COMMON_INCLUDES_
# define pCylM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "pCylM_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MAXf.h"
#include "rt_MINf.h"
#endif                                 /* pCylM_COMMON_INCLUDES_ */

#include "pCylM_types.h"

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
  UInt16 VEMS_vidGET;                /* '<S18>/VEMS_vidGET' */
  UInt16 VEMS_vidGET_n;              /* '<S13>/VEMS_vidGET' */
  UInt16 VEMS_vidGET_f;              /* '<S14>/VEMS_vidGET' */
  UInt16 VEMS_vidGET_m;              /* '<S17>/VEMS_vidGET' */
  UInt16 VEMS_vidGET3[6];            /* '<S13>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET1;               /* '<S18>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET3_b[6];          /* '<S14>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET4[6];            /* '<S13>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5[6];            /* '<S13>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET6[6];            /* '<S13>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET9[6];            /* '<S13>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET9_p[6];          /* '<S14>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET6_p[6];          /* '<S14>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET4_m[6];          /* '<S14>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5_m[6];          /* '<S14>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET7[6];            /* '<S13>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET8[6];            /* '<S13>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET10[6];           /* '<S13>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET11[6];           /* '<S13>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET7_p[6];          /* '<S14>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET8_o[6];          /* '<S14>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET10_l[6];         /* '<S14>/VEMS_vidGET10' */
  UInt16 VEMS_vidGET11_a[6];         /* '<S14>/VEMS_vidGET11' */
  UInt16 VEMS_vidGET_c;              /* '<S46>/VEMS_vidGET' */
  UInt16 TmpSignalConversionAtVEMS_vidSE[6];
  UInt16 VEMS_vidGET1_d;             /* '<S46>/VEMS_vidGET1' */
  UInt16 TmpSignalConversionAtVEMS_vid_g[6];
  UInt16 VEMS_vidGET2;               /* '<S46>/VEMS_vidGET2' */
  UInt16 TmpSignalConversionAtVEMS_vid_a[6];
  UInt16 VEMS_vidGET3_bo;            /* '<S46>/VEMS_vidGET3' */
  UInt16 TmpSignalConversionAtVEMS_vid_n[6];
  UInt16 DataTypeConversion5;        /* '<S17>/Data Type Conversion5' */
  UInt16 VEMS_vidGET2_m;             /* '<S47>/VEMS_vidGET2' */
  UInt16 Assignment1[6];             /* '<S47>/Assignment1' */
  UInt16 VEMS_vidGET3_a;             /* '<S47>/VEMS_vidGET3' */
  UInt16 Assignment8[6];             /* '<S47>/Assignment8' */
  UInt16 VEMS_vidGET4_p;             /* '<S47>/VEMS_vidGET4' */
  UInt16 Assignment2[6];             /* '<S47>/Assignment2' */
  UInt16 VEMS_vidGET5_g;             /* '<S47>/VEMS_vidGET5' */
  UInt16 Assignment3[6];             /* '<S47>/Assignment3' */
  UInt16 VEMS_vidGET9_f[6];          /* '<S48>/VEMS_vidGET9' */
  UInt16 VEMS_vidGET3_bs;            /* '<S48>/VEMS_vidGET3' */
  UInt16 Assignment1_k[6];           /* '<S48>/Assignment1' */
  UInt16 VEMS_vidGET8_e[6];          /* '<S48>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET2_d;             /* '<S48>/VEMS_vidGET2' */
  UInt16 Assignment8_i[6];           /* '<S48>/Assignment8' */
  UInt16 VEMS_vidGET6_a[6];          /* '<S48>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET4_n;             /* '<S48>/VEMS_vidGET4' */
  UInt16 Assignment2_h[6];           /* '<S48>/Assignment2' */
  UInt16 VEMS_vidGET7_a[6];          /* '<S48>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET5_c;             /* '<S48>/VEMS_vidGET5' */
  UInt16 Assignment3_i[6];           /* '<S48>/Assignment3' */
  UInt16 Merge;                      /* '<S18>/Merge' */
  UInt16 Merge1;                     /* '<S18>/Merge1' */
  UInt16 Merge2;                     /* '<S18>/Merge2' */
  UInt16 Merge3;                     /* '<S18>/Merge3' */
  UInt8 VEMS_vidGET1_e;              /* '<S47>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_g;               /* '<S47>/VEMS_vidGET' */
  UInt8 VEMS_vidGET2_b;              /* '<S13>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET1_l;              /* '<S13>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET1_o;              /* '<S48>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_fq;              /* '<S48>/VEMS_vidGET' */
  UInt8 VEMS_vidGET2_bq;             /* '<S14>/VEMS_vidGET2' */
  UInt8 VEMS_vidGET1_o0;             /* '<S14>/VEMS_vidGET1' */
} BlockIO_pCylM;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define PCYLM_START_SEC_VAR_UNSPECIFIED
#include "pCylM_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_pCylM pCylM_B;

#define PCYLM_STOP_SEC_VAR_UNSPECIFIED
#include "pCylM_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define PCYLM_START_SEC_CODE
#include "pCylM_MemMap.h"

/* Model entry point functions */
extern void pCylM_initialize(void);
extern void CylM_SdlFast_pCylM(void);
extern void CylM_EveRst_pCylM(void);
extern void CylM_EveInj_pCylM(void);
extern void CylM_EveCkSnOn_pCylM(void);

#define PCYLM_STOP_SEC_CODE
#include "pCylM_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define PCYLM_START_SEC_CALIB_16BIT
#include "pCylM_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 720.0                                                             */
extern CONST(UInt16, PCYLM_CALIB) CylM_agInjPha_A[16];

/* Type:    SInt16                                                           */
/* Slope:   0.09375                                                           */
/* Bias:    0.0                                                               */
/* Units:   °Ck                                                               */
/* PhysMin: -720.0                                                            */
/* PhysMax: 720.0                                                             */
extern CONST(SInt16, PCYLM_CALIB) CylM_agOfsConvVlvRef_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, PCYLM_CALIB) CylM_facCorPresCylNEng_T[16];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, PCYLM_CALIB) CylM_nEng_A[16];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PCYLM_CALIB) CylM_pCylEstimInjH1ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PCYLM_CALIB) CylM_pCylEstimInjH2ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PCYLM_CALIB) CylM_pCylEstimInjS1ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern CONST(UInt16, PCYLM_CALIB) CylM_pCylEstimInjS2ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000001E-008                                           */
/* Bias:    0.0                                                               */
/* Units:   m^3                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218749E-003                                           */
extern CONST(UInt16, PCYLM_CALIB) CylM_vCylInjPha_T[16];

#define PCYLM_STOP_SEC_CALIB_16BIT
#include "pCylM_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define PCYLM_START_SEC_CALIB_8BIT
#include "pCylM_MemMap.h"

/* Type:    SInt8                                                            */
/* Units:   -                                                                 */
/* PhysMin: -1.0                                                              */
/* PhysMax: 1.0                                                               */
extern CONST(SInt8, PCYLM_CALIB) CylM_facConvVlvRef_C;

#define PCYLM_STOP_SEC_CALIB_8BIT
#include "pCylM_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define PCYLM_START_SEC_CALIB_BOOLEAN
#include "pCylM_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PCYLM_CALIB) CylM_bAcvETBCylPresEstim1_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, PCYLM_CALIB) CylM_bAcvETBCylPresEstim2_C;

#define PCYLM_STOP_SEC_CALIB_BOOLEAN
#include "pCylM_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define PCYLM_START_SEC_VAR_16BIT
#include "pCylM_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PCYLM_VAR) CylM_pCylEstimInjH1;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PCYLM_VAR) CylM_pCylEstimInjH2;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PCYLM_VAR) CylM_pCylEstimInjS1;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PCYLM_VAR) CylM_pCylEstimInjS2;

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimInjH1Cyl[6];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimInjH2Cyl[6];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimInjS1Cyl[6];

/* Type:    UInt16                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.119921875E+007                                                  */
extern VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimInjS2Cyl[6];

#define PCYLM_STOP_SEC_VAR_16BIT
#include "pCylM_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S16>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Relational Operator' : Unused code path elimination
 * Block '<S32>/Relational Operator1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S22>/BKPT1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S22>/TABLE' : Unused code path elimination
 * Block '<S23>/BKPT1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S23>/TABLE' : Unused code path elimination
 * Block '<S20>/CylM_agInjPha_A' : Unused code path elimination
 * Block '<S20>/CylM_nEng_A' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/Data Type Propagation1' : Unused code path elimination
 * Block '<S36>/Data Type Propagation' : Unused code path elimination
 * Block '<S36>/Data Type Conversion' : Unused code path elimination
 * Block '<S36>/Data Type Conversion1' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/Data Type Propagation1' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S38>/Data Type Conversion' : Unused code path elimination
 * Block '<S38>/Data Type Conversion1' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/Data Type Propagation1' : Unused code path elimination
 * Block '<S40>/Data Type Propagation' : Unused code path elimination
 * Block '<S40>/Data Type Conversion' : Unused code path elimination
 * Block '<S40>/Data Type Conversion1' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Data Type Propagation1' : Unused code path elimination
 * Block '<S42>/Data Type Propagation' : Unused code path elimination
 * Block '<S42>/Data Type Conversion' : Unused code path elimination
 * Block '<S42>/Data Type Conversion1' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Propagation1' : Unused code path elimination
 * Block '<S44>/Data Type Propagation' : Unused code path elimination
 * Block '<S44>/Data Type Conversion' : Unused code path elimination
 * Block '<S44>/Data Type Conversion1' : Unused code path elimination
 * Block '<S29>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S30>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S31>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S33>/Conversion' : Eliminate redundant data type conversion
 * Block '<S34>/Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('pCylM_AUTOCODE/pCylM')    - opens subsystem pCylM_AUTOCODE/pCylM
 * hilite_system('pCylM_AUTOCODE/pCylM/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : pCylM_AUTOCODE
 * '<S5>'   : pCylM_AUTOCODE/pCylM
 * '<S6>'   : pCylM_AUTOCODE/pCylM/CylM_fc_demux1
 * '<S7>'   : pCylM_AUTOCODE/pCylM/CylM_fc_demux2
 * '<S8>'   : pCylM_AUTOCODE/pCylM/CylM_fc_demux3
 * '<S9>'   : pCylM_AUTOCODE/pCylM/CylM_fc_demux4
 * '<S10>'  : pCylM_AUTOCODE/pCylM/F01_pCylMInSync
 * '<S11>'  : pCylM_AUTOCODE/pCylM/F02_pCylM
 * '<S12>'  : pCylM_AUTOCODE/pCylM/F03_pCylMOutSync
 * '<S13>'  : pCylM_AUTOCODE/pCylM/F01_pCylMInSync/F01_CylMInSyncEve
 * '<S14>'  : pCylM_AUTOCODE/pCylM/F01_pCylMInSync/F02_CylMInSyncSdlFast
 * '<S15>'  : pCylM_AUTOCODE/pCylM/F01_pCylMInSync/F01_CylMInSyncEve/multiplication1
 * '<S16>'  : pCylM_AUTOCODE/pCylM/F01_pCylMInSync/F02_CylMInSyncSdlFast/multiplication1
 * '<S17>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F01_CylPMdlIni
 * '<S18>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl
 * '<S19>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F01_pCylEstimTest
 * '<S20>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest
 * '<S21>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/BaryCentre_VEMS
 * '<S22>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Carto_1D_21
 * '<S23>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Carto_1D_22
 * '<S24>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem
 * '<S25>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem1
 * '<S26>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem2
 * '<S27>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem3
 * '<S28>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem5
 * '<S29>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/division_451
 * '<S30>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/multiplication
 * '<S31>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/multiplication1
 * '<S32>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/BaryCentre_VEMS/Clamp
 * '<S33>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited
 * '<S34>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/BaryCentre_VEMS/Clamp/Data Type Conversion Inherited1
 * '<S35>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/BaryCentre_VEMS/Clamp/Saturation Dynamic
 * '<S36>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem/Data Type Police Only single
 * '<S37>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem/If Action Subsystem3
 * '<S38>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem1/Data Type Police Only single
 * '<S39>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem1/If Action Subsystem3
 * '<S40>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem2/Data Type Police Only single
 * '<S41>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem2/If Action Subsystem3
 * '<S42>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem3/Data Type Police Only single
 * '<S43>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem3/If Action Subsystem3
 * '<S44>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem5/Data Type Police Only single
 * '<S45>'  : pCylM_AUTOCODE/pCylM/F02_pCylM/F02_CylPMdl/F02_pCylEstimnoTest/Subsystem5/If Action Subsystem3
 * '<S46>'  : pCylM_AUTOCODE/pCylM/F03_pCylMOutSync/F01_CylMSyncRst
 * '<S47>'  : pCylM_AUTOCODE/pCylM/F03_pCylMOutSync/F02_CylMSyncEveInj
 * '<S48>'  : pCylM_AUTOCODE/pCylM/F03_pCylMOutSync/F03_CylMSyncEve
 */

/*-
 * Requirements for '<Root>': pCylM
 */
#endif                                 /* RTW_HEADER_pCylM_h_ */

/*-------------------------------- end of file -------------------------------*/
