/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : OilTqCf                                                 */
/* !Description     : OIL TORQUE CONFIGURATION                                */
/*                                                                            */
/* !Module          : OilTqCf                                                 */
/*                                                                            */
/* !File            : OilTqCf.h                                               */
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
/*   Code generated on: Sun Oct 21 15:29:22 2012                              */
/*   Model name       : OilTqCf_AUTOCODE.mdl                                  */
/*   Model version    : 1.64                                                  */
/*   Root subsystem   : /OilTqCf                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/OILTQCF_CA/OilTqC$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   25 Oct 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_OilTqCf_h_
#define RTW_HEADER_OilTqCf_h_
#ifndef OilTqCf_COMMON_INCLUDES_
# define OilTqCf_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "OilTqCf_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "rt_MAXf.h"
#include "rt_MINf.h"
#endif                                 /* OilTqCf_COMMON_INCLUDES_ */

#include "OilTqCf_types.h"

/* Includes for objects with custom storage classes. */
#include "GDGAR.h"

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

/* Block signals for system '<S6>/Mem' */
typedef struct {
  SInt16 Switch1;                     /* '<S10>/Switch1' */
} rtB_Mem_OilTqCf;

/* Block states (auto storage) for system '<S6>/Mem' */
typedef struct {
  SInt16 UnitDelay_DSTATE;            /* '<S16>/Unit Delay' */
} rtDW_Mem_OilTqCf;

/* Block signals (auto storage) */
typedef struct {
  UInt16 VEMS_vidGET4;               /* '<S6>/VEMS_vidGET4' */
  UInt16 VEMS_vidGET5;               /* '<S6>/VEMS_vidGET5' */
  SInt16 VEMS_vidGET6;                /* '<S6>/VEMS_vidGET6' */
  SInt16 VEMS_vidGET7;                /* '<S6>/VEMS_vidGET7' */
  SInt16 VEMS_vidGET3;                /* '<S6>/VEMS_vidGET3' */
  SInt16 VEMS_vidGET1;                /* '<S6>/VEMS_vidGET1' */
  SInt16 VEMS_vidGET2;                /* '<S6>/VEMS_vidGET2' */
  SInt16 Switch1;                     /* '<S6>/Switch1' */
  SInt16 VEMS_vidGET9;                /* '<S6>/VEMS_vidGET9' */
  SInt16 VEMS_vidGET8;                /* '<S6>/VEMS_vidGET8' */
  SInt16 Switch;                      /* '<S6>/Switch' */
  Boolean VEMS_vidGET;               /* '<S6>/VEMS_vidGET' */
  Boolean Switch2;                   /* '<S6>/Switch2' */
  rtB_Mem_OilTqCf Mem1;                /* '<S6>/Mem1' */
  rtB_Mem_OilTqCf Mem;                 /* '<S6>/Mem' */
} BlockIO_OilTqCf;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S24>/Unit Delay' */
  Boolean UnitDelay_DSTATE_a;        /* '<S25>/Unit Delay' */
  Boolean UnitDelay_DSTATE_g;        /* '<S32>/Unit Delay' */
  Boolean UnitDelay_DSTATE_h;        /* '<S33>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S15>/UnitDelay' */
  Boolean UnitDelay_g;               /* '<S15>/UnitDelay1' */
  Boolean Memory_PreviousInput;      /* '<S23>/Memory' */
  rtDW_Mem_OilTqCf Mem1;               /* '<S6>/Mem1' */
  rtDW_Mem_OilTqCf Mem;                /* '<S6>/Mem' */
} D_Work_OilTqCf;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S8>/Lookup Table (n-D)'
   *   '<S9>/Lookup Table (n-D)'
   */
  UInt32 pooled3[2];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S15>/Logic'
   */
  Boolean Logic_table[16];

  /* Computed Parameter: Logic_table_f
   * Referenced by: '<S23>/Logic'
   */
  Boolean Logic_table_f[16];
} ConstParam_OilTqCf;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define OILTQCF_START_SEC_VAR_UNSPECIFIED
#include "OilTqCf_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_OilTqCf OilTqCf_B;

/* Block states (auto storage) */
extern D_Work_OilTqCf OilTqCf_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_OilTqCf OilTqCf_ConstP;

#define OILTQCF_STOP_SEC_VAR_UNSPECIFIED
#include "OilTqCf_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define OILTQCF_START_SEC_CODE
#include "OilTqCf_MemMap.h"

/* Model entry point functions */
extern void OilTqCf_initialize(void);
extern void OilTqCf_Sdl20ms_OilTqCf(void);
extern void OilTqCf_EveRst_OilTqCf(void);

#define OILTQCF_STOP_SEC_CODE
#include "OilTqCf_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define OILTQCF_START_SEC_CALIB_16BIT
#include "OilTqCf_MemMap.h"

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(SInt16, OILTQCF_CALIB) OilTqCf_facDen_C;

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(SInt16, OILTQCF_CALIB) OilTqCf_facNum_C;

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, OILTQCF_CALIB) OilTqCf_nEng_rLdHiX_A[9];

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, OILTQCF_CALIB) OilTqCf_nEng_rLdLoX_A[9];

/* Type:    UInt16                                                          */
/* Units:   mbar                                                              */
/* PhysMin: 500.0                                                             */
/* PhysMax: 1500.0                                                            */
extern CONST(UInt16, OILTQCF_CALIB) OilTqCf_pAirExtMes_rLdHiY_A[4];

/* Type:    UInt16                                                          */
/* Units:   mbar                                                              */
/* PhysMin: 500.0                                                             */
/* PhysMax: 1500.0                                                            */
extern CONST(UInt16, OILTQCF_CALIB) OilTqCf_pAirExtMes_rLdLoY_A[4];

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 100.0                                                             */
extern CONST(UInt16, OILTQCF_CALIB) OilTqCf_rLdHi_M[36];

/* Type:    UInt16                                                          */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   %                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 100.0                                                             */
extern CONST(UInt16, OILTQCF_CALIB) OilTqCf_rLdLo_M[36];

#define OILTQCF_STOP_SEC_CALIB_16BIT
#include "OilTqCf_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define OILTQCF_START_SEC_CALIB_8BIT
#include "OilTqCf_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 3.0                                                               */
extern CONST(UInt8, OILTQCF_CALIB) OilTqCf_stPrmDen_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.0                                                               */
extern CONST(UInt8, OILTQCF_CALIB) OilTqCf_stPrmNum_C;

/* Type:    UInt8                                                           */
/* Slope:   0.1                                                               */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 10.0                                                              */
extern CONST(UInt8, OILTQCF_CALIB) OilTqCf_tiDlyHysCfm_C;

#define OILTQCF_STOP_SEC_CALIB_8BIT
#include "OilTqCf_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define OILTQCF_START_SEC_CALIB_BOOLEAN
#include "OilTqCf_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, OILTQCF_CALIB) OilTqCf_bAcvSIPCordCdnDen_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, OILTQCF_CALIB) OilTqCf_bAcvSIPCordCdnNum_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, OILTQCF_CALIB) OilTqCf_bAcvrLdNormCdn_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, OILTQCF_CALIB) OilTqCf_bPresOilReqCf_C;

#define OILTQCF_STOP_SEC_CALIB_BOOLEAN
#include "OilTqCf_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define OILTQCF_START_SEC_VAR_16BIT
#include "OilTqCf_MemMap.h"

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern VAR(SInt16, OILTQCF_VAR) OilTqCf_facDen;

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern VAR(SInt16, OILTQCF_VAR) OilTqCf_facNum;

#define OILTQCF_STOP_SEC_VAR_16BIT
#include "OilTqCf_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define OILTQCF_START_SEC_VAR_BOOLEAN
#include "OilTqCf_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, OILTQCF_VAR) OilTqCf_bPresOilReqCf;

#define OILTQCF_STOP_SEC_VAR_BOOLEAN
#include "OilTqCf_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/LO3' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S8>/x1' : Unused code path elimination
 * Block '<S8>/x2' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S9>/x1' : Unused code path elimination
 * Block '<S9>/x2' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Relational Operator' : Unused code path elimination
 * Block '<S18>/Relational Operator1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/Logical Operator' : Unused code path elimination
 * Block '<S12>/Min4' : Unused code path elimination
 * Block '<S12>/Min5' : Unused code path elimination
 * Block '<S12>/Switch3' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Relational Operator' : Unused code path elimination
 * Block '<S22>/Relational Operator1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Conversion' : Eliminate redundant data type conversion
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
 * hilite_system('OilTqCf_AUTOCODE/OilTqCf')    - opens subsystem OilTqCf_AUTOCODE/OilTqCf
 * hilite_system('OilTqCf_AUTOCODE/OilTqCf/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : OilTqCf_AUTOCODE
 * '<S1>'   : OilTqCf_AUTOCODE/OilTqCf
 * '<S4>'   : OilTqCf_AUTOCODE/OilTqCf/F00_OilTqCf_Init
 * '<S5>'   : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf
 * '<S6>'   : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf
 * '<S7>'   : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/HysPos1
 * '<S8>'   : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/LookUp_2D
 * '<S9>'   : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/LookUp_2D1
 * '<S10>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/Mem
 * '<S11>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/Mem1
 * '<S12>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/SecureDiviFloat
 * '<S13>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay
 * '<S14>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_multiplication
 * '<S15>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/HysPos1/BasculeRS1
 * '<S16>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/Mem/SubSystem
 * '<S17>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/Mem1/SubSystem
 * '<S18>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/SecureDiviFloat/Clamp
 * '<S19>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/SecureDiviFloat/Clamp/Data Type Conversion Inherited
 * '<S20>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/SecureDiviFloat/Clamp/Data Type Conversion Inherited1
 * '<S21>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/SecureDiviFloat/Clamp/Saturation Dynamic
 * '<S22>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/Clamp
 * '<S23>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/S-R Flip-Flop
 * '<S24>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/SubSystem
 * '<S25>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/SubSystem1
 * '<S26>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/multiplication_1
 * '<S27>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/rising_edge
 * '<S28>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/rising_edge2
 * '<S29>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/Clamp/Data Type Conversion Inherited
 * '<S30>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/Clamp/Data Type Conversion Inherited1
 * '<S31>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/Clamp/Saturation Dynamic
 * '<S32>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/rising_edge/SubSystem
 * '<S33>'  : OilTqCf_AUTOCODE/OilTqCf/F0_OilTqCf/F01_OilTqCf/VEMS_TurnONDelay/rising_edge2/SubSystem
 */

/*-
 * Requirements for '<Root>': OilTqCf
 *
 * Inherited requirements for '<S1>/F0_OilTqCf':
 *  1. SubSystem "F0_OilTqCf" !Trace_To : VEMS_R_11_07584_001.02 ;
 *  2. SubSystem "F0_OilTqCf" !Trace_To : VEMS_R_11_07584_002.02 ;

 */
#endif                                 /* RTW_HEADER_OilTqCf_h_ */

/*-------------------------------- end of file -------------------------------*/
