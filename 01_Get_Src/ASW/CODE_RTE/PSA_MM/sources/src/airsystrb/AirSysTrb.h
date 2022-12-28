/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysTrb                                               */
/* !Description     : AirSysTrb Software Component                            */
/*                                                                            */
/* !Module          : AirSysTrb                                               */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : AirSysTrb.h                                             */
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
/*   Model name       : AirSysTrb_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysTrb                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M18-AirSysTrb/5-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   PLCHINAZ                               $$Date::   30 Jun 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AirSysTrb_h_
#define RTW_HEADER_AirSysTrb_h_
#ifndef AirSysTrb_COMMON_INCLUDES_
# define AirSysTrb_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AirSysTrb.h"
#include "AirSysTrb_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FloorF.h"
#include "ACTEMS_LdexpF.h"
#include "rt_MAXf.h"
#include "rt_SATURATE.h"
#endif                                 /* AirSysTrb_COMMON_INCLUDES_ */

#include "AirSysTrb_types.h"

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
  Float32 DTConv_Single_To_UFix_5[2]; /* '<S8>/DTConv_Single_To_UFix_5' */
  Float32 DTConv_Single_To_UFix_1[2]; /* '<S8>/DTConv_Single_To_UFix_1' */
  Float32 DTConv_Single_To_UFix_2[2]; /* '<S11>/DTConv_Single_To_UFix_2' */
  UInt16 TmpSignalConversionAtAirSys_prm[2];
  UInt16 TmpSignalConversionAtAirSys_p_m[2];
  UInt16 TmpSignalConversionAtAirSys_p_p[2];
  UInt16 TmpSignalConversionAtUsThrM_pAi;
  UInt16 TmpSignalConversionAtAirSys_pUs;
} BlockIO_AirSysTrb;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay_DSTATE;           /* '<S105>/Unit Delay' */
  Float32 UnitDelay_DSTATE_l;         /* '<S103>/Unit Delay' */
  Float32 UnitDelay_DSTATE_b;         /* '<S102>/Unit Delay' */
  Float32 UnitDelay_DSTATE_m;         /* '<S104>/Unit Delay' */
  Float32 UnitDelay_DSTATE_m5;        /* '<S63>/Unit Delay' */
  SInt32 UnitDelay_DSTATE_e;          /* '<S69>/Unit Delay' */
  SInt32 UnitDelay_DSTATE_mu;         /* '<S79>/Unit Delay' */
  SInt32 UnitDelay_DSTATE_o;          /* '<S89>/Unit Delay' */
  Boolean UnitDelay_DSTATE_le;       /* '<S62>/Unit Delay' */
  Boolean UnitDelay_DSTATE_j;        /* '<S73>/Unit Delay' */
  Boolean UnitDelay_DSTATE_d;        /* '<S74>/Unit Delay' */
  Boolean UnitDelay;                 /* '<S65>/UnitDelay' */
  Boolean UnitDelay_l;               /* '<S65>/UnitDelay1' */
  Boolean UnitDelay_d;               /* '<S64>/UnitDelay' */
  Boolean UnitDelay_f;               /* '<S64>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_o3;       /* '<S83>/Unit Delay' */
  Boolean UnitDelay_DSTATE_f;        /* '<S84>/Unit Delay' */
  Boolean UnitDelay_d3;              /* '<S75>/UnitDelay' */
  Boolean UnitDelay_j;               /* '<S75>/UnitDelay1' */
  Boolean UnitDelay_c;               /* '<S61>/UnitDelay' */
  Boolean UnitDelay_je;              /* '<S61>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_c;        /* '<S93>/Unit Delay' */
  Boolean UnitDelay_DSTATE_em;       /* '<S94>/Unit Delay' */
  Boolean UnitDelay_b;               /* '<S85>/UnitDelay' */
  Boolean UnitDelay_n;               /* '<S85>/UnitDelay1' */
} D_Work_AirSysTrb;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/Logic'
   *   '<S64>/Logic'
   *   '<S65>/Logic'
   *   '<S75>/Logic'
   *   '<S85>/Logic'
   */
  Boolean pooled8[16];
} ConstParam_AirSysTrb;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define AirSysTrb_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirSysTrb_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_AirSysTrb AirSysTrb_B;

/* Block states (auto storage) */
extern D_Work_AirSysTrb AirSysTrb_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_AirSysTrb AirSysTrb_ConstP;

#define AirSysTrb_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirSysTrb_MemMap.h"
#define AirSysTrb_START_SEC_CODE
#include "AirSysTrb_MemMap.h"

/* Model entry point functions */
extern void RE_AirSysTrb_001_MSE(void);
extern void RE_AirSysTrb_002_TEV(void);
extern void RE_AirSysTrb_003_TEV(void);
extern void RE_AirSysTrb_004_TEV(void);
extern void RE_AirSysTrb_005_TEV(void);

/* Model init function */
extern void Runnable_AirSysTrb_Init(void);
#define AirSysTrb_STOP_SEC_CODE
#include "AirSysTrb_MemMap.h"
#define AirSysTrb_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirSysTrb_MemMap.h"


#define AirSysTrb_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirSysTrb_MemMap.h"

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
 * Block '<S8>/AirSys_facRatPresThrClcn_A' : Unused code path elimination
 * Block '<S22>/BKPT1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S22>/TABLE' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Relational Operator' : Unused code path elimination
 * Block '<S23>/Relational Operator1' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/Data Type Propagation1' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S35>/Data Type Conversion' : Unused code path elimination
 * Block '<S35>/Data Type Conversion1' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/Data Type Propagation1' : Unused code path elimination
 * Block '<S37>/Data Type Propagation' : Unused code path elimination
 * Block '<S37>/Data Type Conversion' : Unused code path elimination
 * Block '<S37>/Data Type Conversion1' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Data Type Propagation1' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Data Type Conversion' : Unused code path elimination
 * Block '<S39>/Data Type Conversion1' : Unused code path elimination
 * Block '<S30>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S31>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S9>/Air_mfAirRef1_A' : Unused code path elimination
 * Block '<S41>/BKPT1' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S41>/TABLE' : Unused code path elimination
 * Block '<S10>/Air_mfAirRef1_A' : Unused code path elimination
 * Block '<S44>/BKPT1' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S44>/TABLE' : Unused code path elimination
 * Block '<S64>/LO3' : Unused code path elimination
 * Block '<S65>/LO3' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Relational Operator' : Unused code path elimination
 * Block '<S66>/Relational Operator1' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Propagation' : Unused code path elimination
 * Block '<S75>/LO3' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Relational Operator' : Unused code path elimination
 * Block '<S76>/Relational Operator1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Propagation' : Unused code path elimination
 * Block '<S85>/LO3' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Relational Operator' : Unused code path elimination
 * Block '<S86>/Relational Operator1' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Propagation' : Unused code path elimination
 * Block '<S95>/BKPT1' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S95>/TABLE' : Unused code path elimination
 * Block '<S96>/BKPT1' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S96>/TABLE' : Unused code path elimination
 * Block '<S54>/Ext_nEngRef2_A' : Unused code path elimination
 * Block '<S54>/Ext_nEngRef2_A1' : Unused code path elimination
 * Block '<S106>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S107>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S108>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S109>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S110>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S111>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S112>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S113>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Conversion' : Eliminate redundant data type conversion
 * Block '<S33>/Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/SignalConversion1' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S9>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S44>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S52>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/SignalConversion' : Eliminate redundant data type conversion
 * Block '<S97>/Saturation' : Eliminated Saturate block
 * Block '<S98>/Saturation' : Eliminated Saturate block
 * Block '<S99>/Saturation' : Eliminated Saturate block
 * Block '<S100>/Saturation' : Eliminated Saturate block
 * Block '<S54>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S54>/Signal Conversion1' : Eliminate redundant signal conversion block
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
 * hilite_system('AirSysTrb_AUTOSAR/AirSysTrb')    - opens subsystem AirSysTrb_AUTOSAR/AirSysTrb
 * hilite_system('AirSysTrb_AUTOSAR/AirSysTrb/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AirSysTrb_AUTOSAR
 * '<S1>'   : AirSysTrb_AUTOSAR/AirSysTrb
 * '<S7>'   : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init
 * '<S8>'   : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq
 * '<S9>'   : AirSysTrb_AUTOSAR/AirSysTrb/F03_UsCmprPresReqClcn
 * '<S10>'  : AirSysTrb_AUTOSAR/AirSysTrb/F04_DsCmprPresReqClcn
 * '<S11>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil
 * '<S12>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/Convertout1
 * '<S13>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/Convertout2
 * '<S14>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/Convertout3
 * '<S15>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/Convertout4
 * '<S16>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/Convertout5
 * '<S17>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/Convertout6
 * '<S18>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/Convertout7
 * '<S19>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/Terminator4
 * '<S20>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/autosar_testpoint
 * '<S21>'  : AirSysTrb_AUTOSAR/AirSysTrb/F00_AirSysTrb_init/autosar_testpoint1
 * '<S22>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/AirSys_rAirPresThr_T
 * '<S23>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Clamp
 * '<S24>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Convertout7
 * '<S25>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem
 * '<S26>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem1
 * '<S27>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem2
 * '<S28>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Terminator1
 * '<S29>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Terminator4
 * '<S30>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/multiplication
 * '<S31>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/multiplication2
 * '<S32>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Clamp/Data Type Conversion Inherited
 * '<S33>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Clamp/Data Type Conversion Inherited1
 * '<S34>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Clamp/Saturation Dynamic
 * '<S35>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem/Data Type Police Only single
 * '<S36>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem/If Action Subsystem3
 * '<S37>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem1/Data Type Police Only single
 * '<S38>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem1/If Action Subsystem3
 * '<S39>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem2/Data Type Police Only single
 * '<S40>'  : AirSysTrb_AUTOSAR/AirSysTrb/F02_UsThrPresReq/Subsystem2/If Action Subsystem3
 * '<S41>'  : AirSysTrb_AUTOSAR/AirSysTrb/F03_UsCmprPresReqClcn/Air_pLossAirFil_T
 * '<S42>'  : AirSysTrb_AUTOSAR/AirSysTrb/F03_UsCmprPresReqClcn/Terminator1
 * '<S43>'  : AirSysTrb_AUTOSAR/AirSysTrb/F03_UsCmprPresReqClcn/autosar_testpoint1
 * '<S44>'  : AirSysTrb_AUTOSAR/AirSysTrb/F04_DsCmprPresReqClcn/Air_pLossCAC_T
 * '<S45>'  : AirSysTrb_AUTOSAR/AirSysTrb/F04_DsCmprPresReqClcn/Terminator1
 * '<S46>'  : AirSysTrb_AUTOSAR/AirSysTrb/F04_DsCmprPresReqClcn/autosar_testpoint1
 * '<S47>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/Convertout1
 * '<S48>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/Convertout2
 * '<S49>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/Convertout3
 * '<S50>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/Convertout4
 * '<S51>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/Convertout5
 * '<S52>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/Convertout6
 * '<S53>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr
 * '<S54>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt
 * '<S55>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F01_FrzInh
 * '<S56>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv
 * '<S57>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/NegHys1
 * '<S58>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1
 * '<S59>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2
 * '<S60>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3
 * '<S61>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/VEMS_BasculeRS
 * '<S62>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/VEMS_UnitDelay
 * '<S63>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/VEMS_UnitDelay1
 * '<S64>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/NegHys1/BasculeRS1
 * '<S65>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/BasculeRS
 * '<S66>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/Clamp
 * '<S67>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/Falling_edge
 * '<S68>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/Rising_edge
 * '<S69>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/VEMS_UnitDelay
 * '<S70>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/Clamp/Data Type Conversion Inherited
 * '<S71>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/Clamp/Data Type Conversion Inherited1
 * '<S72>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/Clamp/Saturation Dynamic
 * '<S73>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/Falling_edge/SubSystem
 * '<S74>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay1/Rising_edge/SubSystem
 * '<S75>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/BasculeRS
 * '<S76>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/Clamp
 * '<S77>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/Falling_edge
 * '<S78>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/Rising_edge
 * '<S79>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/VEMS_UnitDelay
 * '<S80>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/Clamp/Data Type Conversion Inherited
 * '<S81>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/Clamp/Data Type Conversion Inherited1
 * '<S82>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/Clamp/Saturation Dynamic
 * '<S83>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/Falling_edge/SubSystem
 * '<S84>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay2/Rising_edge/SubSystem
 * '<S85>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/BasculeRS
 * '<S86>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/Clamp
 * '<S87>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/Falling_edge
 * '<S88>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/Rising_edge
 * '<S89>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/VEMS_UnitDelay
 * '<S90>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/Clamp/Data Type Conversion Inherited
 * '<S91>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/Clamp/Data Type Conversion Inherited1
 * '<S92>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/Clamp/Saturation Dynamic
 * '<S93>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/Falling_edge/SubSystem
 * '<S94>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F01_TipOutMgr/F02_FrzAcv/Turn_Off_Delay3/Rising_edge/SubSystem
 * '<S95>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/Carto_1D1
 * '<S96>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/Carto_1D2
 * '<S97>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK
 * '<S98>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK1
 * '<S99>'  : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK2
 * '<S100>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK3
 * '<S101>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/Terminator4
 * '<S102>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/VEMS_UnitDelay
 * '<S103>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/VEMS_UnitDelay1
 * '<S104>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/VEMS_UnitDelay2
 * '<S105>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/VEMS_UnitDelay3
 * '<S106>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK/multiplication
 * '<S107>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK/multiplication1
 * '<S108>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK1/multiplication
 * '<S109>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK1/multiplication1
 * '<S110>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK2/multiplication
 * '<S111>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK2/multiplication1
 * '<S112>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK3/multiplication
 * '<S113>' : AirSysTrb_AUTOSAR/AirSysTrb/F05_AirReqFil/F02_FrzFilt/LowPassFilter_typeK3/multiplication1
 */

/*-
 * Requirements for '<Root>': AirSysTrb
 *
 * Inherited requirements for '<S1>/F00_AirSysTrb_init':
 *  1. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_003.01 ;
 *  2. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_005.01 ;
 *  3. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_006.01 ;
 *  4. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_007.01 ;
 *  5. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_009.01 ;
 *  6. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_010.01 ;
 *  7. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_011.01 ;
 *  8. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_013.03 ;
 *  9. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_014.03 ;
 *  10. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_015.01 ;
 *  11. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_021.01 ;
 *  12. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_023.01 ;
 *  13. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_025.01 ;
 *  14. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_027.01 ;
 *  15. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_028.01 ;
 *  16. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_029.01 ;
 *  17. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_030.01 ;
 *  18. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_031.01 ;
 *  19. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_032.01 ;
 *  20. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_033.01 ;
 *  21. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_034.01 ;
 *  22. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_035.01 ;
 *  23. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_036.01 ;
 *  24. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_038.01 ;
 *
 * Inherited requirements for '<S1>/F02_UsThrPresReq':
 *  1. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_001.01 ;
 *  2. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_002.01 ;
 *  3. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_004.01 ;
 *  4. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_021.01 ;
 *  5. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_022.01 ;
 *  6. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_023.01 ;
 *  7. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_024.01 ;
 *  8. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_025.01 ;
 *  9. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_026.01 ;
 *  10. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_039.01 ;
 *
 * Inherited requirements for '<S1>/F03_UsCmprPresReqClcn':
 *  1. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_005.01 ;
 *  2. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_006.01 ;
 *  3. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_008.01 ;
 *  4. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_023.01 ;
 *  5. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_025.01 ;
 *  6. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_027.01 ;
 *  7. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_040.01 ;
 *
 * Inherited requirements for '<S1>/F04_DsCmprPresReqClcn':
 *  1. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_009.01 ;
 *  2. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_010.01 ;
 *  3. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_012.01 ;
 *  4. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_023.01 ;
 *  5. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_028.01 ;
 *  6. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_029.01 ;
 *  7. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_041.01 ;
 *
 * Inherited requirements for '<S1>/F05_AirReqFil':
 *  1. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_013.03 ;
 *  2. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_014.03 ;
 *  3. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_016.03 ;
 *  4. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_021.01 ;
 *  5. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_023.01 ;
 *  6. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_027.01 ;
 *  7. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_028.01 ;
 *  8. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_029.01 ;
 *  9. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_031.01 ;
 *  10. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_032.01 ;
 *  11. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_033.01 ;
 *  12. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_034.01 ;
 *  13. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_035.01 ;
 *  14. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_036.01 ;
 *  15. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_037.01 ;
 *  16. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_042.02 ;
 *  17. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_043.01 ;
 *  18. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_044.01 ;
 *  19. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_045.01 ;
 *  20. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_046.01 ;
 *  21. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_048.01 ;
 *  22. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_049.01 ;
 *  23. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_050.01 ;

 */
#endif                                 /* RTW_HEADER_AirSysTrb_h_ */

/*-------------------------------- end of file -------------------------------*/
