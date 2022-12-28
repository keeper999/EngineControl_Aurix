/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjrMdl                                                 */
/* !Description     : InjSys - MODELE INJECTEUR (GDI)                         */
/*                                                                            */
/* !Module          : InjrMdl                                                 */
/*                                                                            */
/* !File            : InjrMdl.h                                               */
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
/*   Code generated on: Wed Mar 13 19:55:28 2013                              */
/*   Model name       : InjrMdl_AUTOCODE.mdl                                  */
/*   Model version    : 1.280                                                 */
/*   Root subsystem   : /InjrMdl                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjrMdl/5-SOFT-LIV/InjrMdl.h$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   18 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjrMdl_h_
#define RTW_HEADER_InjrMdl_h_
#ifndef InjrMdl_COMMON_INCLUDES_
# define InjrMdl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "InjrMdl_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "ACTEMS_FloorF.h"
#include "ACTEMS_LdexpF.h"
#endif                                 /* InjrMdl_COMMON_INCLUDES_ */

#include "InjrMdl_types.h"

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

/* Block signals for system '<S8>/F01_InjrMdl' */
typedef struct {
  SInt16 Merge[4];                    /* '<S27>/Merge' */
  UInt16 Merge1[4];                  /* '<S27>/Merge1' */
} rtB_F01_InjrMdl_InjrMdl;

/* Block signals (auto storage) */
typedef struct {
  SInt32 VEMS_vidGET1;                /* '<S15>/VEMS_vidGET1' */
  SInt32 VEMS_vidGET1_o;              /* '<S8>/VEMS_vidGET1' */
  UInt16 VEMS_vidGET3;               /* '<S15>/VEMS_vidGET3' */
  UInt16 VEMS_vidGET3_c;             /* '<S8>/VEMS_vidGET3' */
  SInt16 VEMS_vidGET;                 /* '<S15>/VEMS_vidGET' */
  SInt16 VEMS_vidGET_p;               /* '<S8>/VEMS_vidGET' */
  UInt16 VEMS_vidGET4;               /* '<S15>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET4_m;             /* '<S8>/VEMS_vidGET4' */
  SInt16 VEMS_vidGET5[6];             /* '<S42>/VEMS_vidGET5' */
  SInt16 VEMS_vidGET3_p[4];           /* '<S42>/VEMS_vidGET3' */
  SInt16 Assignment1[6];              /* '<S42>/Assignment1' */
  SInt16 VEMS_vidGET6[6];             /* '<S42>/VEMS_vidGET6' */
  SInt16 Assignment2[6];              /* '<S42>/Assignment2' */
  SInt16 VEMS_vidGET7[6];             /* '<S42>/VEMS_vidGET7' */
  SInt16 Assignment3[6];              /* '<S42>/Assignment3' */
  SInt16 VEMS_vidGET4_a[6];           /* '<S42>/VEMS_vidGET4' */
  SInt16 Assignment8[6];              /* '<S42>/Assignment8' */
  SInt16 VEMS_vidGET6_g[4];           /* '<S41>/VEMS_vidGET6' */
  SInt16 Switch[6];                   /* '<S41>/Switch' */
  SInt16 Switch1[6];                  /* '<S41>/Switch1' */
  SInt16 Switch2[6];                  /* '<S41>/Switch2' */
  SInt16 Switch3[6];                  /* '<S41>/Switch3' */
  SInt16 VEMS_vidGET8[4];             /* '<S15>/VEMS_vidGET8' */
  SInt16 VEMS_vidGET1_l[4];           /* '<S38>/VEMS_vidGET1' */
  SInt16 TmpSignalConversionAtVEMS_vidSE[6];
  SInt16 TmpSignalConversionAtVEMS_vid_n[6];
  SInt16 TmpSignalConversionAtVEMS_vid_m[6];
  SInt16 TmpSignalConversionAtVEMS_vid_j[6];
  SInt16 VEMS_vidGET8_b[4];           /* '<S8>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET7_m[4];          /* '<S15>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET7_g[4];          /* '<S8>/VEMS_vidGET7' */
  UInt16 VEMS_vidGET8_m[6];          /* '<S42>/VEMS_vidGET8' */
  UInt16 VEMS_vidGET2[4];            /* '<S42>/VEMS_vidGET2' */
  UInt16 Assignment4[6];             /* '<S42>/Assignment4' */
  UInt16 VEMS_vidGET9[6];            /* '<S42>/VEMS_vidGET9' */
  UInt16 Assignment5[6];             /* '<S42>/Assignment5' */
  UInt16 VEMS_vidGET10[6];           /* '<S42>/VEMS_vidGET10' */
  UInt16 Assignment6[6];             /* '<S42>/Assignment6' */
  UInt16 VEMS_vidGET11[6];           /* '<S42>/VEMS_vidGET11' */
  UInt16 Assignment7[6];             /* '<S42>/Assignment7' */
  UInt16 VEMS_vidGET5_f[4];          /* '<S41>/VEMS_vidGET5' */
  UInt16 Switch4[6];                 /* '<S41>/Switch4' */
  UInt16 Switch5[6];                 /* '<S41>/Switch5' */
  UInt16 Switch6[6];                 /* '<S41>/Switch6' */
  UInt16 Switch7[6];                 /* '<S41>/Switch7' */
  UInt16 VEMS_vidGET6_d[4];          /* '<S15>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET_e[4];           /* '<S38>/VEMS_vidGET' */
  UInt16 TmpSignalConversionAtVEMS_vid_d[6];
  UInt16 TmpSignalConversionAtVEMS_vid_p[6];
  UInt16 TmpSignalConversionAtVEMS_vid_c[6];
  UInt16 TmpSignalConversionAtVEMS_vid_o[6];
  UInt16 VEMS_vidGET6_b[4];          /* '<S8>/VEMS_vidGET6' */
  UInt16 VEMS_vidGET5_c[4];          /* '<S15>/VEMS_vidGET5' */
  UInt16 VEMS_vidGET5_i[4];          /* '<S8>/VEMS_vidGET5' */
  UInt8 VEMS_vidGET1_g;              /* '<S42>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_g;               /* '<S42>/VEMS_vidGET' */
  UInt8 VEMS_vidGET1_gl;             /* '<S41>/VEMS_vidGET1' */
  UInt8 VEMS_vidGET_o;               /* '<S41>/VEMS_vidGET' */
  UInt8 VEMS_vidGET3_m;              /* '<S41>/VEMS_vidGET3' */
  UInt8 VEMS_vidGET4_mh;             /* '<S41>/VEMS_vidGET4' */
  UInt8 VEMS_vidGET2_d;              /* '<S41>/VEMS_vidGET2' */
  Boolean LogicalOperator;           /* '<S41>/Logical Operator' */
  SInt8 VEMS_vidGET2_i;               /* '<S15>/VEMS_vidGET2' */
  SInt8 VEMS_vidGET2_e;               /* '<S8>/VEMS_vidGET2' */
  rtB_F01_InjrMdl_InjrMdl F01_InjrMdl_j;/* '<S15>/F01_InjrMdl' */
  rtB_F01_InjrMdl_InjrMdl F01_InjrMdl_b;/* '<S8>/F01_InjrMdl' */
} BlockIO_InjrMdl;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJRMDL_START_SEC_VAR_UNSPECIFIED
#include "InjrMdl_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_InjrMdl InjrMdl_B;

#define INJRMDL_STOP_SEC_VAR_UNSPECIFIED
#include "InjrMdl_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define INJRMDL_START_SEC_CODE
#include "InjrMdl_MemMap.h"

/* Model entry point functions */
extern void InjrMdl_initialize(void);
extern void InjrM_EveSpl_InjrMdl(void);
extern void InjrM_EveInj_InjrMdl(void);
extern void InjrM_SdlFast_InjrMdl(void);
extern void InjrM_EveCkSnOn_InjrMdl(void);
extern void InjrM_EveRst_InjrMdl(void);

#define INJRMDL_STOP_SEC_CODE
#include "InjrMdl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define INJRMDL_START_SEC_CALIB_16BIT
#include "InjrMdl_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, INJRMDL_CALIB) InjrM_facCorGainLnrInjTFu_T[16];

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, INJRMDL_CALIB) InjrM_facCorOfsuBatt_T[9];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, INJRMDL_CALIB) InjrM_facGainInjH1ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, INJRMDL_CALIB) InjrM_facGainInjH2ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, INJRMDL_CALIB) InjrM_facGainInjS1ETB_C;

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, INJRMDL_CALIB) InjrM_facGainInjS2ETB_C;

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, INJRMDL_CALIB) InjrM_tiInjOfsInjH1ETB_C;

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, INJRMDL_CALIB) InjrM_tiInjOfsInjH2ETB_C;

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, INJRMDL_CALIB) InjrM_tiInjOfsInjS1ETB_C;

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern CONST(SInt16, INJRMDL_CALIB) InjrM_tiInjOfsInjS2ETB_C;

#define INJRMDL_STOP_SEC_CALIB_16BIT
#include "InjrMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define INJRMDL_START_SEC_CALIB_BOOLEAN
#include "InjrMdl_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, INJRMDL_CALIB) InjrM_bAcvInjMdlETB_C;

#define INJRMDL_STOP_SEC_CALIB_BOOLEAN
#include "InjrMdl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJRMDL_START_SEC_VAR_16BIT
#include "InjrMdl_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInj[4];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInjH1Cyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInjH2Cyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInjS1Cyl[6];

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   s/kg                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInjS2Cyl[6];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInj[4];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInjH1Cyl[6];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInjH2Cyl[6];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInjS1Cyl[6];

/* Type:    SInt16                                                           */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: -0.1048576                                                        */
/* PhysMax: 0.1048544                                                         */
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInjS2Cyl[6];

#define INJRMDL_STOP_SEC_VAR_16BIT
#include "InjrMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJRMDL_START_SEC_VAR_BOOLEAN
#include "InjrMdl_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, INJRMDL_VAR) InjrM_bInhInjrMUpd;

#define INJRMDL_STOP_SEC_VAR_BOOLEAN
#include "InjrMdl_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S21>/BKPT1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S21>/TABLE' : Unused code path elimination
 * Block '<S19>/Ext_uBatt_A' : Unused code path elimination
 * Block '<S22>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S23>/BKPT1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S23>/TABLE' : Unused code path elimination
 * Block '<S20>/InjrM_tFu_A' : Unused code path elimination
 * Block '<S25>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S32>/BKPT1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S32>/TABLE' : Unused code path elimination
 * Block '<S30>/Ext_uBatt_A' : Unused code path elimination
 * Block '<S33>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S34>/BKPT1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S34>/TABLE' : Unused code path elimination
 * Block '<S31>/InjrM_tFu_A' : Unused code path elimination
 * Block '<S36>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S34>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * hilite_system('InjrMdl_AUTOCODE/InjrMdl')    - opens subsystem InjrMdl_AUTOCODE/InjrMdl
 * hilite_system('InjrMdl_AUTOCODE/InjrMdl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : InjrMdl_AUTOCODE
 * '<S1>'   : InjrMdl_AUTOCODE/InjrMdl
 * '<S7>'   : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl
 * '<S8>'   : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst
 * '<S9>'   : InjrMdl_AUTOCODE/InjrMdl/F02_InjrMdlSync
 * '<S10>'  : InjrMdl_AUTOCODE/InjrMdl/InjrMdl_fc_demux1
 * '<S11>'  : InjrMdl_AUTOCODE/InjrMdl/InjrMdl_fc_demux2
 * '<S12>'  : InjrMdl_AUTOCODE/InjrMdl/InjrMdl_fc_demux3
 * '<S13>'  : InjrMdl_AUTOCODE/InjrMdl/InjrMdl_fc_demux4
 * '<S14>'  : InjrMdl_AUTOCODE/InjrMdl/InjrMdl_fc_demux5
 * '<S15>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl
 * '<S16>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl
 * '<S17>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdlTest
 * '<S18>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest
 * '<S19>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest/F01_Ofs
 * '<S20>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain
 * '<S21>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest/F01_Ofs/Carto_1D
 * '<S22>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest/F01_Ofs/multiplication_411
 * '<S23>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain/Carto_1D_21
 * '<S24>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain/multiplication_1
 * '<S25>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain/multiplication_2
 * '<S26>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl/F01_InjrMdl/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain/multiplication_411
 * '<S27>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl
 * '<S28>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F01_InjrMdlTest
 * '<S29>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest
 * '<S30>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest/F01_Ofs
 * '<S31>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain
 * '<S32>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest/F01_Ofs/Carto_1D
 * '<S33>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest/F01_Ofs/multiplication_411
 * '<S34>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain/Carto_1D_21
 * '<S35>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain/multiplication_1
 * '<S36>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain/multiplication_2
 * '<S37>'  : InjrMdl_AUTOCODE/InjrMdl/F01_InjrMdl_EveRst/F01_InjrMdl/F02_InjrMdlnoTest/F02_Gain/multiplication_411
 * '<S38>'  : InjrMdl_AUTOCODE/InjrMdl/F02_InjrMdlSync/F01_InjrMdlSyncRst
 * '<S39>'  : InjrMdl_AUTOCODE/InjrMdl/F02_InjrMdlSync/F02_InjrMdlSyncEveClcn
 * '<S40>'  : InjrMdl_AUTOCODE/InjrMdl/F02_InjrMdlSync/F03_InjrMdlSyncEveInj
 * '<S41>'  : InjrMdl_AUTOCODE/InjrMdl/F02_InjrMdlSync/F02_InjrMdlSyncEveClcn/F02_InjrMdlSyncEveClcn
 * '<S42>'  : InjrMdl_AUTOCODE/InjrMdl/F02_InjrMdlSync/F03_InjrMdlSyncEveInj/F03_InjrMdlSyncEveInj
 */

/*-
 * Requirements for '<Root>': InjrMdl
 */
#endif                                 /* RTW_HEADER_InjrMdl_h_ */

/*-------------------------------- end of file -------------------------------*/
