/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : TqCkEngLimCord                                          */
/* !Description     : SAFETY TMS : GERER LE BOUCLAGE                          */
/*                                                                            */
/* !Module          : TqCkEngLimCord                                          */
/*                                                                            */
/* !File            : TqCkEngLimCord.h                                        */
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
/*   Code generated on: Tue Jun 19 17:16:01 2012                              */
/*   Model name       : TqCkEngLimCord_AUTOCODE.mdl                           */
/*   Model version    : 1.173                                                 */
/*   Root subsystem   : /TqCkEngLimCord                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKENGLIMCORD_CA/TqCk$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   27 Jun 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_TqCkEngLimCord_h_
#define RTW_HEADER_TqCkEngLimCord_h_
#ifndef TqCkEngLimCord_COMMON_INCLUDES_
# define TqCkEngLimCord_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "TqCkEngLimCord_import.h"
#include "VEMS.H"
#include "rtw_shared_utils.h"
#include "rt_MINf.h"
#endif                                 /* TqCkEngLimCord_COMMON_INCLUDES_ */

#include "TqCkEngLimCord_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define SftyMgt_tiSdlCllReq_SC         ((UInt8) 40U)

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
  UInt16 SFunction10;                /* '<S6>/S-Function10' */
  SInt16 SFunction6;                  /* '<S6>/S-Function6' */
  SInt16 SFunction4;                  /* '<S6>/S-Function4' */
  SInt16 SFunction3;                  /* '<S6>/S-Function3' */
  SInt16 SFunction14;                 /* '<S6>/S-Function14' */
  SInt16 SFunction13;                 /* '<S6>/S-Function13' */
  SInt16 SFunction12;                 /* '<S6>/S-Function12' */
  SInt16 Switch1;                     /* '<S24>/Switch1' */
  UInt8 SFunction8;                  /* '<S6>/S-Function8' */
  Boolean SFunction7;                /* '<S6>/S-Function7' */
  Boolean SFunction9;                /* '<S6>/S-Function9' */
  Boolean SFunction5;                /* '<S6>/S-Function5' */
  Boolean SFunction1;                /* '<S6>/S-Function1' */
  Boolean SFunction11;               /* '<S6>/S-Function11' */
  Boolean LogicalOperator2;          /* '<S26>/Logical Operator2' */
} BlockIO_TqCkEngLimCord;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float UnitDelay_DSTATE;           /* '<S32>/Unit Delay' */
  Float UnitDelay_DSTATE_e;         /* '<S33>/Unit Delay' */
  Float UnitDelay_DSTATE_o;         /* '<S34>/Unit Delay' */
  Float UnitDelay_DSTATE_g;         /* '<S35>/Unit Delay' */
  Float UnitDelay_DSTATE_i;         /* '<S19>/Unit Delay' */
  Float UnitDelay_DSTATE_c;         /* '<S17>/Unit Delay' */
  Float UnitDelay_DSTATE_gf;        /* '<S20>/Unit Delay' */
  Float UnitDelay_DSTATE_iw;        /* '<S18>/Unit Delay' */
  Boolean UnitDelay_DSTATE_k;        /* '<S15>/Unit Delay' */
  Boolean UnitDelay_DSTATE_m;        /* '<S16>/Unit Delay' */
} D_Work_TqCkEngLimCord;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S14>/Logic'
   */
  Boolean Logic_table[16];
} ConstParam_TqCkEngLimCord;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define TQCKENGLIMCORD_START_SEC_VAR_UNSPECIFIED
#include "TqCkEngLimCord_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_TqCkEngLimCord TqCkEngLimCord_B;

/* Block states (auto storage) */
extern D_Work_TqCkEngLimCord TqCkEngLimCord_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_TqCkEngLimCord TqCkEngLimCord_ConstP;

#define TQCKENGLIMCORD_STOP_SEC_VAR_UNSPECIFIED
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Define code in section "SEC_CODE" */
#define TQCKENGLIMCORD_START_SEC_CODE
#include "TqCkEngLimCord_MemMap.h"

/* Model entry point functions */
extern void TqCkEngLimCord_initialize(void);
extern void SftyMgt_Init_tqCkEngLimCord(void);
extern void SftyMgt_SdlMid_tqCkEngLimCord(void);

#define TQCKENGLIMCORD_STOP_SEC_CODE
#include "TqCkEngLimCord_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_16BIT" */
#define TQCKENGLIMCORD_START_SEC_CALIB_16BIT
#include "TqCkEngLimCord_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   0.25                                                              */
/* Bias:    0.0                                                               */
/* Units:   rpm                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 8000.0                                                            */
extern CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_nEngOplThdX_A[8];

/* Type:    UInt16                                                          */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 100.0                                                             */
extern CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tiDftTqIdcAgIgMin_C;

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   N.m                                                               */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(SInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqDifHighForc_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   N.m                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 2000.0                                                            */
extern CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqHiResThr_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   N.m                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 2000.0                                                            */
extern CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqLoResThr_C;

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   N.m                                                               */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(SInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqMaxAntiOsc_C;

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   N.m                                                               */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(SInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqOfsAgIgMin_C;

/* Type:    UInt16                                                          */
/* Slope:   0.0625                                                            */
/* Bias:    -2000.0                                                           */
/* Units:   Nm                                                                */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern CONST(UInt16, TQCKENGLIMCORD_CALIB) SftyMgt_tqOplThd_T[8];

#define TQCKENGLIMCORD_STOP_SEC_CALIB_16BIT
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define TQCKENGLIMCORD_START_SEC_CALIB_8BIT
#include "TqCkEngLimCord_MemMap.h"

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_noTqReqChaASR_C;

/* Type:    UInt8                                                           */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 7.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_noTqReqChaMSR_C;

/* Type:    UInt8                                                           */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiAcvForcCll_C;

/* Type:    UInt8                                                           */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiDeacForcCll_C;

/* Type:    UInt8                                                           */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiDftCll_C;

/* Type:    UInt8                                                           */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiDftIdcAir_C;

/* Type:    UInt8                                                           */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiDftTqAntiOscMon_C;

/* Type:    UInt8                                                           */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 4.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiTqDifCfm_C;

/* Type:    UInt8                                                           */
/* Slope:   0.04                                                              */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.0                                                               */
extern CONST(UInt8, TQCKENGLIMCORD_CALIB) SftyMgt_tiTranCll_C;

#define TQCKENGLIMCORD_STOP_SEC_CALIB_8BIT
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Declare data in section "SEC_CALIB_BOOLEAN" */
#define TQCKENGLIMCORD_START_SEC_CALIB_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, TQCKENGLIMCORD_CALIB) SftyMgt_bInhDftAOS_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, TQCKENGLIMCORD_CALIB) SftyMgt_bInhDftAgIgMin_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, TQCKENGLIMCORD_CALIB) SftyMgt_bInhDftCll_C;

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, TQCKENGLIMCORD_CALIB) SftyMgt_bInhDftIdcAir_C;

#define TQCKENGLIMCORD_STOP_SEC_CALIB_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define TQCKENGLIMCORD_START_SEC_VAR_16BIT
#include "TqCkEngLimCord_MemMap.h"

/* Type:    SInt16                                                           */
/* Slope:   0.0625                                                            */
/* Bias:    0.0                                                               */
/* Units:   N.m                                                               */
/* PhysMin: -2000.0                                                           */
/* PhysMax: 2000.0                                                            */
extern VAR(SInt16, TQCKENGLIMCORD_VAR) SftyMgt_tqCkEngLimCord;

#define TQCKENGLIMCORD_STOP_SEC_VAR_16BIT
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define TQCKENGLIMCORD_START_SEC_VAR_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   bool                                                              */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoTqCord;

#define TQCKENGLIMCORD_STOP_SEC_VAR_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S14>/LO3' : Unused code path elimination
 * Block '<S27>/BKPT1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S27>/TABLE' : Unused code path elimination
 * Block '<S25>/Constant_51' : Unused code path elimination
 * Block '<S13>/Switch1' : Eliminated due to constant selection input
 * Block '<S27>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S7>/Cste_0' : Unused code path elimination
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
 * hilite_system('TqCkEngLimCord_AUTOCODE/TqCkEngLimCord')    - opens subsystem TqCkEngLimCord_AUTOCODE/TqCkEngLimCord
 * hilite_system('TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : TqCkEngLimCord_AUTOCODE
 * '<S1>'   : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord
 * '<S4>'   : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage
 * '<S5>'   : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/Init
 * '<S6>'   : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage
 * '<S7>'   : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage
 * '<S8>'   : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle
 * '<S9>'   : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/PosHys
 * '<S10>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/Turn_On_Delay_Simple1
 * '<S11>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/Turn_On_Delay_Simple2
 * '<S12>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/Turn_On_Delay_Simple3
 * '<S13>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/Turn_off_Delay_Simple
 * '<S14>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/PosHys/BasculeRS
 * '<S15>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/PosHys/BasculeRS/VEMS_UnitDelay
 * '<S16>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/PosHys/BasculeRS/VEMS_UnitDelay1
 * '<S17>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/Turn_On_Delay_Simple1/VEMS_UnitDelay
 * '<S18>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/Turn_On_Delay_Simple2/VEMS_UnitDelay
 * '<S19>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/Turn_On_Delay_Simple3/VEMS_UnitDelay
 * '<S20>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F01_Generer_demande_bouclage/Turn_off_Delay_Simple/VEMS_UnitDelay
 * '<S21>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_01_bouclage_debouclage
 * '<S22>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_02_AOS
 * '<S23>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_03_CoordinationBoucleAAMin
 * '<S24>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_04_OTorque
 * '<S25>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_05_securisation_consigne_air
 * '<S26>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut
 * '<S27>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_05_securisation_consigne_air/Carto_1D1
 * '<S28>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut/Turn_On_Delay_Simple
 * '<S29>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut/Turn_On_Delay_Simple1
 * '<S30>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut/Turn_On_Delay_Simple2
 * '<S31>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut/Turn_On_Delay_Simple3
 * '<S32>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut/Turn_On_Delay_Simple/VEMS_UnitDelay
 * '<S33>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut/Turn_On_Delay_Simple1/VEMS_UnitDelay
 * '<S34>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut/Turn_On_Delay_Simple2/VEMS_UnitDelay
 * '<S35>'  : TqCkEngLimCord_AUTOCODE/TqCkEngLimCord/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage/F02_Generer_Couple_Boucle/F02_06_synthese_defaut/Turn_On_Delay_Simple3/VEMS_UnitDelay
 */

/*-
 * Requirements for '<Root>': TqCkEngLimCord
 */
#endif                                 /* RTW_HEADER_TqCkEngLimCord_h_ */

/*-------------------------------- end of file -------------------------------*/
