/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActMgt                                               */
/* !Description     : TrbActMgt Software Component                            */
/*                                                                            */
/* !Module          : TrbActMgt                                               */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : TrbActMgt.h                                             */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
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
/*   Model name       : TrbActMgt_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActMgt                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M13-TrbActMgt/5-$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_TrbActMgt_h_
#define RTW_HEADER_TrbActMgt_h_
#ifndef TrbActMgt_COMMON_INCLUDES_
# define TrbActMgt_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_TrbActMgt.h"
#include "TrbActMgt_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FabsF.h"
#include "rt_SATURATE.h"
#endif                                 /* TrbActMgt_COMMON_INCLUDES_ */

#include "TrbActMgt_types.h"

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
  Float32 TrbAct_pErrUsThr_TrbAct_pErrUsT;/* '<S81>/Prelookup' */
  Float32 NS_TrbAct_pErrUsThr2_A_9_f; /* '<S83>/Prelookup' */
  Float32 TrbAct_pErrFltGrd_MP_TrbAct_pEr;/* '<S84>/Prelookup' */
  Float32 Ext_nEng_TrbAct_nEngCtl_A_9_f;/* '<S82>/Prelookup' */
  Float32 Ext_nEngGrd_TrbAct_nEngGrd_A_9_;/* '<S80>/Prelookup' */
  Float32 DataTypeConversion5[2];     /* '<S5>/Data Type Conversion5' */
  Float32 Ext_nEng_TrbAct_nEng_A_9_f; /* '<S33>/Prelookup' */
  UInt32 TrbAct_pErrUsThr_TrbAct_pErrU_l;/* '<S81>/Prelookup' */
  UInt32 NS_TrbAct_pErrUsThr2_A_9_k; /* '<S83>/Prelookup' */
  UInt32 TrbAct_pErrFltGrd_MP_TrbAct_p_l;/* '<S84>/Prelookup' */
  UInt32 Ext_nEng_TrbAct_nEngCtl_A_9_k;/* '<S82>/Prelookup' */
  UInt32 Ext_nEngGrd_TrbAct_nEngGrd_A__h;/* '<S80>/Prelookup' */
  UInt32 Ext_nEng_TrbAct_nEng_A_9_k; /* '<S33>/Prelookup' */
  SInt32 MinMax;                      /* '<S39>/MinMax' */
  UInt16 TmpSignalConversionAtExt_nEngOu;
  UInt16 TmpSignalConversionAtExt_nEng_g;
  UInt16 TmpSignalConversionAtAirSys_pUs;
  UInt16 TmpSignalConversionAtUsThrM_pAi;
  Boolean TmpSignalConversionAtAirSys_bAc;
  Boolean TmpSignalConversionAtTrbAct_bIn;
  UInt8 TmpSignalConversionAtAfuA_rEthW;
  UInt8 TmpSignalConversionAtAfuA_rEt_d;
  SInt8 TmpSignalConversionAtExt_nEngGr;
} BlockIO_TrbActMgt;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S134>/Unit Delay' */
  Float32 UnitDelay_DSTATE_p;         /* '<S135>/Unit Delay' */
  Float32 UnitDelay_DSTATE_l;         /* '<S129>/Unit Delay' */
  Float32 UnitDelay_DSTATE_j;         /* '<S88>/Unit Delay' */
  Float32 UnitDelay;                  /* '<S91>/UnitDelay' */
  Float32 UnitDelay_DSTATE_f;         /* '<S50>/Unit Delay' */
  Float32 UnitDelay_DSTATE_a;         /* '<S37>/Unit Delay' */
  Float32 UnitDelay_o;                /* '<S25>/UnitDelay' */
  SInt16 TrbAct_pErrGrd_MP;           /* '<S75>/Data Store Memory' */
  Boolean UnitDelay_l;               /* '<S127>/UnitDelay' */
  Boolean UnitDelay_e;               /* '<S127>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_b;        /* '<S123>/Unit Delay' */
  Boolean UnitDelay_lj;              /* '<S91>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_d;        /* '<S89>/UnitDelay' */
  Boolean UnitDelay_d;               /* '<S48>/UnitDelay' */
  Boolean UnitDelay_i;               /* '<S48>/UnitDelay1' */
  Boolean UnitDelay_h;               /* '<S41>/UnitDelay' */
  Boolean UnitDelay_f;               /* '<S41>/UnitDelay1' */
  Boolean UnitDelay1_DSTATE;         /* '<S40>/Unit Delay1' */
  Boolean UnitDelay_i0;              /* '<S25>/UnitDelay1' */
  Boolean UnitDelay_a;               /* '<S27>/UnitDelay' */
  Boolean UnitDelay_fc;              /* '<S27>/UnitDelay1' */
} D_Work_TrbActMgt;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState F02_IParInit_Trig_ZCE;    /* '<S67>/F02_IParInit' */
} PrevZCSigStates_TrbActMgt;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S27>/Logic'
   *   '<S41>/Logic'
   *   '<S48>/Logic'
   *   '<S127>/Logic'
   */
  Boolean pooled9[16];
} ConstParam_TrbActMgt;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define TrbActMgt_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActMgt_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_TrbActMgt TrbActMgt_B;

/* Block states (auto storage) */
extern D_Work_TrbActMgt TrbActMgt_DWork;




#define TrbActMgt_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActMgt_MemMap.h"
#define TrbActMgt_START_SEC_CODE
#include "TrbActMgt_MemMap.h"

extern void RE_TrbActMgt_Init(void);
/* Model entry point functions */
extern void RE_TrbActMgt_003_TEV(void);
extern void RE_TrbActMgt_002_TEV(void);
extern void RE_TrbActMgt_001_MSE(void);

#define TrbActMgt_STOP_SEC_CODE
#include "TrbActMgt_MemMap.h"

#define TrbActMgt_START_SEC_CONST_UNSPECIFIED
#include "TrbActMgt_MemMap.h"

/* Constant parameters (auto storage) */
extern const ConstParam_TrbActMgt TrbActMgt_ConstP;

#define TrbActMgt_STOP_SEC_CONST_UNSPECIFIED
#include "TrbActMgt_MemMap.h"

#define TrbActMgt_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActMgt_MemMap.h"

/* Model init function */


#define TrbActMgt_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActMgt_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/x1' : Unused code path elimination
 * Block '<S27>/LO3' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S28>/x1' : Unused code path elimination
 * Block '<S41>/LO3' : Unused code path elimination
 * Block '<S48>/LO3' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S45>/x' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S46>/x' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S57>/x1' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S33>/x' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S80>/x' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S81>/x' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S82>/x' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S83>/x' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S84>/x' : Unused code path elimination
 * Block '<S114>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S114>/x' : Unused code path elimination
 * Block '<S127>/LO3' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Relational Operator' : Unused code path elimination
 * Block '<S128>/Relational Operator1' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Switch' : Eliminated due to constant selection input
 * Block '<S47>/Switch' : Eliminated due to constant selection input
 * Block '<S16>/Switch' : Eliminated due to constant selection input
 * Block '<S17>/Switch' : Eliminated due to constant selection input
 * Block '<S18>/Switch' : Eliminated due to constant selection input
 * Block '<S19>/Switch' : Eliminated due to constant selection input
 * Block '<S20>/Switch' : Eliminated due to constant selection input
 * Block '<S59>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S62>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S79>/Switch' : Eliminated due to constant selection input
 * Block '<S85>/Switch' : Eliminated due to constant selection input
 * Block '<S86>/Switch' : Eliminated due to constant selection input
 * Block '<S87>/Switch' : Eliminated due to constant selection input
 * Block '<S131>/Conversion' : Eliminate redundant data type conversion
 * Block '<S132>/Conversion' : Eliminate redundant data type conversion
 * Block '<S71>/Switch' : Eliminated due to constant selection input
 * Block '<S72>/Switch' : Eliminated due to constant selection input
 * Block '<S73>/Switch' : Eliminated due to constant selection input
 * Block '<S74>/Switch' : Eliminated due to constant selection input
 * Block '<S141>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S142>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S144>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S145>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S146>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S147>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S148>/copy' : Eliminate redundant signal conversion block
 * Block '<S149>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Unused code path elimination
 * Block '<S47>/Add3' : Unused code path elimination
 * Block '<S47>/Add4' : Unused code path elimination
 * Block '<S47>/Constant' : Unused code path elimination
 * Block '<S47>/Relational Operator' : Unused code path elimination
 * Block '<S47>/Switch1' : Unused code path elimination
 * Block '<S47>/offset2' : Unused code path elimination
 * Block '<S47>/offset3' : Unused code path elimination
 * Block '<S47>/offset4' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S17>/Constant' : Unused code path elimination
 * Block '<S18>/Constant' : Unused code path elimination
 * Block '<S19>/Add3' : Unused code path elimination
 * Block '<S19>/Add4' : Unused code path elimination
 * Block '<S19>/Constant' : Unused code path elimination
 * Block '<S19>/Relational Operator' : Unused code path elimination
 * Block '<S19>/Switch1' : Unused code path elimination
 * Block '<S19>/offset2' : Unused code path elimination
 * Block '<S19>/offset3' : Unused code path elimination
 * Block '<S19>/offset4' : Unused code path elimination
 * Block '<S20>/Add3' : Unused code path elimination
 * Block '<S20>/Add4' : Unused code path elimination
 * Block '<S20>/Constant' : Unused code path elimination
 * Block '<S20>/Relational Operator' : Unused code path elimination
 * Block '<S20>/Switch1' : Unused code path elimination
 * Block '<S20>/offset2' : Unused code path elimination
 * Block '<S20>/offset3' : Unused code path elimination
 * Block '<S20>/offset4' : Unused code path elimination
 * Block '<S90>/Data Type Conversion' : Unused code path elimination
 * Block '<S85>/Add2' : Unused code path elimination
 * Block '<S85>/Constant' : Unused code path elimination
 * Block '<S85>/offset1' : Unused code path elimination
 * Block '<S86>/Add2' : Unused code path elimination
 * Block '<S86>/Constant' : Unused code path elimination
 * Block '<S86>/offset1' : Unused code path elimination
 * Block '<S87>/Add2' : Unused code path elimination
 * Block '<S87>/Constant' : Unused code path elimination
 * Block '<S87>/offset1' : Unused code path elimination
 * Block '<S71>/Add3' : Unused code path elimination
 * Block '<S71>/Add4' : Unused code path elimination
 * Block '<S71>/Constant' : Unused code path elimination
 * Block '<S71>/Relational Operator' : Unused code path elimination
 * Block '<S71>/Switch1' : Unused code path elimination
 * Block '<S71>/offset2' : Unused code path elimination
 * Block '<S71>/offset3' : Unused code path elimination
 * Block '<S71>/offset4' : Unused code path elimination
 * Block '<S72>/Add2' : Unused code path elimination
 * Block '<S72>/Constant' : Unused code path elimination
 * Block '<S72>/offset1' : Unused code path elimination
 * Block '<S73>/Add2' : Unused code path elimination
 * Block '<S73>/Constant' : Unused code path elimination
 * Block '<S73>/offset1' : Unused code path elimination
 * Block '<S74>/Add2' : Unused code path elimination
 * Block '<S74>/Constant' : Unused code path elimination
 * Block '<S74>/offset1' : Unused code path elimination
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
 * hilite_system('TrbActMgt_AUTOSAR/TrbActMgt')    - opens subsystem TrbActMgt_AUTOSAR/TrbActMgt
 * hilite_system('TrbActMgt_AUTOSAR/TrbActMgt/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : TrbActMgt_AUTOSAR
 * '<S1>'   : TrbActMgt_AUTOSAR/TrbActMgt
 * '<S5>'   : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr
 * '<S6>'   : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl
 * '<S7>'   : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init
 * '<S8>'   : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/Convertout1
 * '<S9>'   : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/Convertout2
 * '<S10>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/Convertout3
 * '<S11>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/Convertout5
 * '<S12>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/Convertout6
 * '<S13>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F01_TransDet
 * '<S14>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F02_AltiCorSp
 * '<S15>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn
 * '<S16>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/Rte_Call_R_FRM_bInhPosnTrbActMod_GetFunctionPermission
 * '<S17>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/Rte_Call_R_FRM_bInhSenCtl_GetFunctionPermission
 * '<S18>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/Rte_Call_R_FRM_bInhTrbActCmd_GetFunctionPermission
 * '<S19>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/SingleToFixdt
 * '<S20>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/SingleToFixdt1
 * '<S21>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F01_TransDet/Filtre_1er_ordre  avec reset
 * '<S22>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F01_TransDet/LookUp_1D
 * '<S23>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F01_TransDet/PosHys
 * '<S24>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F01_TransDet/Filtre_1er_ordre  avec reset/Reset du filtre
 * '<S25>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F01_TransDet/Filtre_1er_ordre  avec reset/UnitDly_ExtIni
 * '<S26>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F01_TransDet/Filtre_1er_ordre  avec reset/filtrage
 * '<S27>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F01_TransDet/PosHys/BasculeRS
 * '<S28>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F02_AltiCorSp/LookUp_1D
 * '<S29>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn
 * '<S30>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F02_TrbActCmdCdn
 * '<S31>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F03_BoostClCtlCdn
 * '<S32>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F04_NatBoostPres
 * '<S33>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/PreLookUp_Binary
 * '<S34>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn/DelayEdge_falling_VEMS
 * '<S35>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn/PosHys
 * '<S36>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn/Terminator
 * '<S37>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn/UnitDelay2
 * '<S38>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn/multiplication_411
 * '<S39>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn/DelayEdge_falling_VEMS/Subsystem
 * '<S40>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn/DelayEdge_falling_VEMS/Subsystem/FallingEdge
 * '<S41>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F01_PosnTrbActModCdn/PosHys/BasculeRS
 * '<S42>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F02_TrbActCmdCdn/Interp_1D
 * '<S43>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F02_TrbActCmdCdn/Interp_2D
 * '<S44>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F02_TrbActCmdCdn/PosHys
 * '<S45>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F02_TrbActCmdCdn/PreLookUp_Binary
 * '<S46>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F02_TrbActCmdCdn/PreLookUp_Binary1
 * '<S47>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F02_TrbActCmdCdn/SingleToFixdt
 * '<S48>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F02_TrbActCmdCdn/PosHys/BasculeRS
 * '<S49>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F03_BoostClCtlCdn/Interp_1D
 * '<S50>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F03_BoostClCtlCdn/UnitDelay3
 * '<S51>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F03_BoostClCtlCdn/multiplication_421
 * '<S52>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F04_NatBoostPres/F01_NatBoostPresRef
 * '<S53>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F04_NatBoostPres/F02_NatBoostPres
 * '<S54>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F04_NatBoostPres/F03_NatEthBoostPres
 * '<S55>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F04_NatBoostPres/F01_NatBoostPresRef/Interp_1D
 * '<S56>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F04_NatBoostPres/F03_NatEthBoostPres/Interp_1D
 * '<S57>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F04_NatBoostPres/F03_NatEthBoostPres/LookUp_1D
 * '<S58>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02800_TrbActMgt_SdlFast_TrbActMgr/F03_TrbActCtlCdn/F04_NatBoostPres/F03_NatEthBoostPres/multiplication_421
 * '<S59>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/Convertout1
 * '<S60>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/Convertout2
 * '<S61>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/Convertout3
 * '<S62>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/Convertout4
 * '<S63>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/Convertout7
 * '<S64>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F01_ErrClcn
 * '<S65>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn
 * '<S66>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F03_P
 * '<S67>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I
 * '<S68>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F05_D
 * '<S69>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F06_Ant
 * '<S70>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F07_pUsThrCorSpClcn
 * '<S71>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/SingleToFixdt
 * '<S72>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/SingleToFixdt1
 * '<S73>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/SingleToFixdt2
 * '<S74>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/SingleToFixdt3
 * '<S75>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain
 * '<S76>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef
 * '<S77>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F03_CtlGain
 * '<S78>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain
 * '<S79>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/Filtre_1er_ordre_avec_reset_PSA1
 * '<S80>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/PreLookUp_Binary
 * '<S81>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/PreLookUp_Binary1
 * '<S82>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/PreLookUp_Binary2
 * '<S83>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/PreLookUp_Binary3
 * '<S84>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/PreLookUp_Binary4
 * '<S85>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/SingleToFixdt1
 * '<S86>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/SingleToFixdt2
 * '<S87>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/SingleToFixdt3
 * '<S88>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/UnitDelay10
 * '<S89>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/Filtre_1er_ordre_avec_reset_PSA1/IniCdn
 * '<S90>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/Filtre_1er_ordre_avec_reset_PSA1/Reset du filtre
 * '<S91>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/Filtre_1er_ordre_avec_reset_PSA1/UnitDly_ExtIni
 * '<S92>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F01_IndCtlGain/Filtre_1er_ordre_avec_reset_PSA1/filtrage
 * '<S93>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D
 * '<S94>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D1
 * '<S95>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D2
 * '<S96>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D3
 * '<S97>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D4
 * '<S98>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D5
 * '<S99>'  : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D6
 * '<S100>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D7
 * '<S101>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/Interp_2D8
 * '<S102>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/multiplication_411
 * '<S103>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/multiplication_421
 * '<S104>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/multiplication_431
 * '<S105>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F02_CtlGainRef/multiplication_441
 * '<S106>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/Interp_1D
 * '<S107>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/Interp_1D1
 * '<S108>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/Interp_1D2
 * '<S109>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/Interp_1D3
 * '<S110>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/Interp_2D
 * '<S111>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/Interp_2D1
 * '<S112>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/Interp_2D2
 * '<S113>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/Interp_2D3
 * '<S114>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/PreLookUp_Binary
 * '<S115>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/multiplication_1
 * '<S116>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/multiplication_2
 * '<S117>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/multiplication_3
 * '<S118>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F02_GainPIDAntiClcn/F04_EthCtlGain/multiplication_461
 * '<S119>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F03_P/multiplication_431
 * '<S120>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F01_RstCond_FrzCond
 * '<S121>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F02_IParInit
 * '<S122>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F03_ICor
 * '<S123>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F01_RstCond_FrzCond/UnitDelay5
 * '<S124>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F02_IParInit/PosHys
 * '<S125>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F02_IParInit/multiplication_441
 * '<S126>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F02_IParInit/multiplication_451
 * '<S127>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F02_IParInit/PosHys/BasculeRS
 * '<S128>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F03_ICor/Clamp
 * '<S129>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F03_ICor/UnitDelay10
 * '<S130>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F03_ICor/multiplication_461
 * '<S131>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F03_ICor/Clamp/Data Type Conversion Inherited
 * '<S132>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F03_ICor/Clamp/Data Type Conversion Inherited1
 * '<S133>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F04_I/F03_ICor/Clamp/Saturation Dynamic
 * '<S134>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F05_D/UnitDelay1
 * '<S135>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F05_D/UnitDelay2
 * '<S136>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F05_D/multiplication_471
 * '<S137>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F05_D/multiplication_481
 * '<S138>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F06_Ant/multiplication_491
 * '<S139>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F07_pUsThrCorSpClcn/multiplication
 * '<S140>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_02801_TrbActMgt_SdlFast_TrbActCtl/F07_pUsThrCorSpClcn/multiplication1
 * '<S141>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout1
 * '<S142>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout10
 * '<S143>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout2
 * '<S144>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout3
 * '<S145>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout4
 * '<S146>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout5
 * '<S147>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout6
 * '<S148>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout7
 * '<S149>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout8
 * '<S150>' : TrbActMgt_AUTOSAR/TrbActMgt/RE_TrbActMgt_init/Convertout9
 */

/*-
 * Requirements for '<Root>': TrbActMgt
 *
 * Inherited requirements for '<S1>/RE_02800_TrbActMgt_SdlFast_TrbActMgr':
 *  1. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_015.03 ;
 *  2. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_016.03 ;
 *  3. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_028.01 ;
 *  4. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_030.01 ;
 *  5. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_029.02 ;
 *  6. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_031.01 ;
 *  7. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_053.02 ;
 *  8. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_032.01 ;
 *  9. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_052.01 ;
 *  10. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_054.01 ;
 *  11. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_033.01 ;
 *  12. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_034.02 ;
 *  13. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_035.01 ;
 *  14. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_024.01 ;
 *  15. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_025.01 ;
 *  16. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_026.01 ;
 *  17. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_027.02 ;
 *  18. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_058.02 ;
 *  19. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_049.04 ;
 *  20. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_046.01 ;
 *  21. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_047.01 ;
 *  22. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_055.01 ;
 *  23. SubSystem "RE_02800_TrbActMgt_SdlFast_TrbActMgr" !Trace_To : VEMS_R_10_07014_059.01 ;
 *
 * Inherited requirements for '<S1>/RE_02801_TrbActMgt_SdlFast_TrbActCtl':
 *  1. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_001.03 ;
 *  2. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_002.03 ;
 *  3. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_004.03 ;
 *  4. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_028.01 ;
 *  5. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_040.01 ;
 *  6. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_031.01 ;
 *  7. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_039.01 ;
 *  8. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_041.01 ;
 *  9. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_033.01 ;
 *  10. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_051.02 ;
 *  11. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_042.01 ;
 *  12. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_043.01 ;
 *  13. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_044.01 ;
 *  14. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_057.02 ;
 *  15. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_037.01 ;
 *  16. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_038.01 ;
 *  17. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_056.02 ;
 *  18. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_059.01 ;
 *  19. SubSystem "RE_02801_TrbActMgt_SdlFast_TrbActCtl" !Trace_To : VEMS_R_10_07014_050.04 ;
 *
 * Inherited requirements for '<S1>/RE_TrbActMgt_init':
 *  1. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_001.03 ;
 *  2. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_002.03 ;
 *  3. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_003.01 ;
 *  4. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_043.01 ;
 *  5. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_024.01 ;
 *  6. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_025.01 ;
 *  7. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_037.01 ;
 *  8. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_026.01 ;
 *  9. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_027.02 ;
 *  10. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_038.01 ;
 *  11. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_058.02 ;
 *  12. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_056.02 ;
 *  13. SubSystem "RE_TrbActMgt_init" !Trace_To : VEMS_R_10_07014_048.03 ;

 */
#endif                                 /* RTW_HEADER_TrbActMgt_h_ */

/*-------------------------------- end of file -------------------------------*/
