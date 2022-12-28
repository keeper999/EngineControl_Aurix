/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvPrevKnkT                                             */
/* !Description     : AdvPrevKnkT Software Component                          */
/*                                                                            */
/* !Module          : AdvPrevKnkT                                             */
/* !Description     : Public Declarations                                     */
/*                                                                            */
/* !File            : AdvPrevKnkT.h                                           */
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
/*   Model name       : AdvPrevKnkT_AUTOSAR.mdl                               */
/*   Root subsystem   : /AdvPrevKnkT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M05-AdvPrevKnkT$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   11 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvPrevKnkT_h_
#define RTW_HEADER_AdvPrevKnkT_h_
#ifndef AdvPrevKnkT_COMMON_INCLUDES_
# define AdvPrevKnkT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AdvPrevKnkT.h"
#include "AdvPrevKnkT_import.h"
#include "rtw_shared_utils.h"
#include "ACTEMS_FloorF.h"
#include "ACTEMS_LdexpF.h"
#include "rt_MAX.h"
#include "rt_MINf.h"
#include "rt_SATURATE.h"
#endif                                 /* AdvPrevKnkT_COMMON_INCLUDES_ */

#include "AdvPrevKnkT_types.h"

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
  Float32 IgSys_agIgPrevDynOfs_i;     /* '<S71>/F01_02_04_03_01_Automate' */
} BlockIO_AdvPrevKnkT;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Float32 UnitDelay;                  /* '<S67>/UnitDelay' */
  Float32 UnitDelay_m;                /* '<S41>/UnitDelay' */
  Float32 UnitDelay_l;                /* '<S38>/UnitDelay' */
  Float32 UnitDelay_DSTATE;           /* '<S35>/Unit Delay' */
  Float32 UnitDelay_DSTATE_b;         /* '<S34>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_l;         /* '<S58>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_c;         /* '<S57>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_f;         /* '<S59>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_f2;        /* '<S64>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_n;         /* '<S63>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_o;         /* '<S62>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_k;         /* '<S61>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_kj;        /* '<S60>/Unit Delay' */
  UInt16 UnitDelay_DSTATE_i;         /* '<S47>/Unit Delay' */
  Boolean UnitDelay_lg;              /* '<S67>/UnitDelay1' */
  Boolean UnitDelay1_DSTATE;         /* '<S47>/Unit Delay1' */
  Boolean UnitDelay_k;               /* '<S41>/UnitDelay1' */
  Boolean UnitDelay_f;               /* '<S38>/UnitDelay1' */
  UInt8 is_active_c1_AdvPrevKnkT;    /* '<S71>/F01_02_04_03_01_Automate' */
  UInt8 is_c1_AdvPrevKnkT;           /* '<S71>/F01_02_04_03_01_Automate' */
} D_Work_AdvPrevKnkT;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvPrevKnkT_MemMap.h"

/* Block signals (auto storage) */
extern BlockIO_AdvPrevKnkT AdvPrevKnkT_B;

/* Block states (auto storage) */
extern D_Work_AdvPrevKnkT AdvPrevKnkT_DWork;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvPrevKnkT_MemMap.h"
#define AdvPrevKnkT_START_SEC_CODE
#include "AdvPrevKnkT_MemMap.h"

extern void Runnable_AdvPrevKnkT_Init(void);
/* Model entry point functions */
extern void RE_AdvPrevKnkT_002(void);
extern void RE_AdvPrevKnkT_001_MSE(void);

#define AdvPrevKnkT_STOP_SEC_CODE
#include "AdvPrevKnkT_MemMap.h"
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvPrevKnkT_MemMap.h"

/* Model init function */


#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvPrevKnkT_MemMap.h"

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
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Relational Operator' : Unused code path elimination
 * Block '<S17>/Relational Operator1' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/BKPT1' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S30>/TABLE' : Unused code path elimination
 * Block '<S31>/BKPT1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S31>/TABLE' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/IgSys_nEng_facFilDeltaAir_A' : Unused code path elimination
 * Block '<S36>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S45>/BKPT1' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S45>/TABLE' : Unused code path elimination
 * Block '<S43>/IgSys_nEng_AirLdDet_A' : Unused code path elimination
 * Block '<S46>/BKPT1' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S46>/TABLE' : Unused code path elimination
 * Block '<S44>/IgSys_nEng_AirLdDet_A' : Unused code path elimination
 * Block '<S48>/Relational Operator' : Unused code path elimination
 * Block '<S48>/Relational Operator1' : Unused code path elimination
 * Block '<S49>/Relational Operator' : Unused code path elimination
 * Block '<S49>/Relational Operator1' : Unused code path elimination
 * Block '<S47>/Constant4' : Unused code path elimination
 * Block '<S47>/Switch1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S55>/TABLE' : Unused code path elimination
 * Block '<S55>/TABLE1' : Unused code path elimination
 * Block '<S55>/TABLE2' : Unused code path elimination
 * Block '<S50>/IgSys_nEng_facFilAirldDynX_A' : Unused code path elimination
 * Block '<S50>/IgSys_pDsThr_facFilAirLdDynY_A' : Unused code path elimination
 * Block '<S56>/BKPT1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S56>/TABLE' : Unused code path elimination
 * Block '<S51>/IgSys_nEng_noDlyCalcAirLd_A' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S72>/TABLE' : Unused code path elimination
 * Block '<S72>/TABLE1' : Unused code path elimination
 * Block '<S72>/TABLE2' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S73>/TABLE' : Unused code path elimination
 * Block '<S73>/TABLE1' : Unused code path elimination
 * Block '<S73>/TABLE2' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S74>/TABLE' : Unused code path elimination
 * Block '<S74>/TABLE1' : Unused code path elimination
 * Block '<S74>/TABLE2' : Unused code path elimination
 * Block '<S69>/IgSys_knkAdp_PrevDynX_A' : Unused code path elimination
 * Block '<S69>/IgSys_nEng_PrevDynX_A' : Unused code path elimination
 * Block '<S69>/IgSys_noEgdGearCord_PrevDynX_A' : Unused code path elimination
 * Block '<S69>/IgSys_rAirLdCor_PrevDynY_A' : Unused code path elimination
 * Block '<S69>/IgSys_spdVeh_PrevDynY_A' : Unused code path elimination
 * Block '<S69>/IgSys_tAirUsInVlv_PrevDynY_A' : Unused code path elimination
 * Block '<S75>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S76>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S77>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S78>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S84>/TABLE' : Unused code path elimination
 * Block '<S84>/TABLE1' : Unused code path elimination
 * Block '<S84>/TABLE2' : Unused code path elimination
 * Block '<S80>/IgSys_nEng_PrevStatX_A' : Unused code path elimination
 * Block '<S80>/IgSys_rLamEngCorReq_PrevStaY_A' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S85>/TABLE' : Unused code path elimination
 * Block '<S85>/TABLE1' : Unused code path elimination
 * Block '<S85>/TABLE2' : Unused code path elimination
 * Block '<S81>/IgSys_nEng_PrevStatX_A' : Unused code path elimination
 * Block '<S81>/IgSys_rAirLdCor_PrevStatY_A' : Unused code path elimination
 * Block '<S86>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S87>/BKPT1' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S87>/TABLE' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S88>/TABLE' : Unused code path elimination
 * Block '<S88>/TABLE1' : Unused code path elimination
 * Block '<S88>/TABLE2' : Unused code path elimination
 * Block '<S82>/IgSys_nEng_PrevStatX_A' : Unused code path elimination
 * Block '<S82>/IgSys_pAirExtMes_PrevStat_A' : Unused code path elimination
 * Block '<S82>/IgSys_rAirLdCor_PrevStatY_A' : Unused code path elimination
 * Block '<S90>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S91>/TABLE' : Unused code path elimination
 * Block '<S91>/TABLE1' : Unused code path elimination
 * Block '<S91>/TABLE2' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S92>/TABLE' : Unused code path elimination
 * Block '<S92>/TABLE1' : Unused code path elimination
 * Block '<S92>/TABLE2' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S93>/TABLE' : Unused code path elimination
 * Block '<S93>/TABLE1' : Unused code path elimination
 * Block '<S93>/TABLE2' : Unused code path elimination
 * Block '<S83>/IgSys_nEng_PrevStatX_A' : Unused code path elimination
 * Block '<S83>/IgSys_rAirLdCor_PrevStatY_A' : Unused code path elimination
 * Block '<S83>/IgSys_tAirUsInVlv_PrevStatY_A' : Unused code path elimination
 * Block '<S83>/IgSys_tCoMes_PrevStatX_A' : Unused code path elimination
 * Block '<S95>/Byp_Fonction_SC' : Unused code path elimination
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Switch' : Eliminated due to constant selection input
 * Block '<S33>/Switch' : Eliminated due to constant selection input
 * Block '<S45>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S44>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S44>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S44>/SignalConversion' : Eliminate redundant data type conversion
 * Block '<S47>/Switch2' : Eliminated due to constant selection input
 * Block '<S55>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S56>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Switch' : Eliminated due to constant selection input
 * Block '<S72>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S84>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S85>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S85>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S87>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S88>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S88>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S82>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S91>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S92>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S92>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S93>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S93>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S83>/SignalConversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S37>/Data Type Conversion' : Unused code path elimination
 * Block '<S40>/Data Type Conversion' : Unused code path elimination
 * Block '<S47>/Constant3' : Unused code path elimination
 * Block '<S66>/Data Type Conversion' : Unused code path elimination
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
 * hilite_system('AdvPrevKnkT_AUTOSAR/AdvPrevKnkT')    - opens subsystem AdvPrevKnkT_AUTOSAR/AdvPrevKnkT
 * hilite_system('AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AdvPrevKnkT_AUTOSAR
 * '<S1>'   : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT
 * '<S4>'   : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F00_AdvPrevKnkT_init
 * '<S5>'   : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT
 * '<S6>'   : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F00_AdvPrevKnkT_init/convertout1
 * '<S7>'   : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F00_AdvPrevKnkT_init/convertout2
 * '<S8>'   : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F00_AdvPrevKnkT_init/convertout3
 * '<S9>'   : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F00_AdvPrevKnkT_init/convertout4
 * '<S10>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/Enabled Subsystem
 * '<S11>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_01_Condition_d_activation
 * '<S12>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis
 * '<S13>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/Enabled Subsystem/convertout1
 * '<S14>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/Enabled Subsystem/convertout2
 * '<S15>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/Enabled Subsystem/convertout3
 * '<S16>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/Enabled Subsystem/convertout4
 * '<S17>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/Clamp1
 * '<S18>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage
 * '<S19>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_02_Dynamique_de_charge
 * '<S20>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique
 * '<S21>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique
 * '<S22>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique
 * '<S23>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/convertout1
 * '<S24>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/convertout2
 * '<S25>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/convertout3
 * '<S26>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/convertout4
 * '<S27>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/Clamp1/Data Type Conversion Inherited
 * '<S28>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/Clamp1/Data Type Conversion Inherited1
 * '<S29>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/Clamp1/Saturation Dynamic
 * '<S30>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Carto_1D1
 * '<S31>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Carto_1D2
 * '<S32>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Filtre_1er_ordre  avec reset1
 * '<S33>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Filtre_1er_ordre  avec reset2
 * '<S34>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/UnitDelay1
 * '<S35>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/UnitDelay2
 * '<S36>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/multiplication_411
 * '<S37>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Filtre_1er_ordre  avec reset1/Reset du filtre
 * '<S38>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Filtre_1er_ordre  avec reset1/UnitDly_ExtIni
 * '<S39>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Filtre_1er_ordre  avec reset1/filtrage
 * '<S40>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Filtre_1er_ordre  avec reset2/Reset du filtre
 * '<S41>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Filtre_1er_ordre  avec reset2/UnitDly_ExtIni
 * '<S42>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_01_Calcul_delta_remplissage/Filtre_1er_ordre  avec reset2/filtrage
 * '<S43>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_02_Dynamique_de_charge/F01_02_02_01_Maintien_dynamique_charge
 * '<S44>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_02_Dynamique_de_charge/F01_02_02_02_Calcul_dynamique_de_charge
 * '<S45>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_02_Dynamique_de_charge/F01_02_02_01_Maintien_dynamique_charge/Carto_1D1
 * '<S46>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_02_Dynamique_de_charge/F01_02_02_02_Calcul_dynamique_de_charge/Carto_1D1
 * '<S47>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_02_Dynamique_de_charge/F01_02_02_02_Calcul_dynamique_de_charge/TmrRst
 * '<S48>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_02_Dynamique_de_charge/F01_02_02_02_Calcul_dynamique_de_charge/TmrRst/Clamp
 * '<S49>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_02_Dynamique_de_charge/F01_02_02_02_Calcul_dynamique_de_charge/TmrRst/Clamp1
 * '<S50>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_01_Calcul_du_facteur_de_filtrage
 * '<S51>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_02_Calcul_du_retard
 * '<S52>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_03_Calcul_et_choix_de_remplissage
 * '<S53>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard
 * '<S54>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_05_Filtarge_du_remplissage
 * '<S55>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_01_Calcul_du_facteur_de_filtrage/Carto_2D1
 * '<S56>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_02_Calcul_du_retard/Carto_1D1
 * '<S57>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard/UnitDelay1
 * '<S58>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard/UnitDelay10
 * '<S59>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard/UnitDelay2
 * '<S60>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard/UnitDelay3
 * '<S61>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard/UnitDelay4
 * '<S62>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard/UnitDelay5
 * '<S63>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard/UnitDelay6
 * '<S64>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_04_Application_du_retard/UnitDelay7
 * '<S65>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_05_Filtarge_du_remplissage/Filtre_1er_ordre  avec reset1
 * '<S66>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_05_Filtarge_du_remplissage/Filtre_1er_ordre  avec reset1/Reset du filtre
 * '<S67>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_05_Filtarge_du_remplissage/Filtre_1er_ordre  avec reset1/UnitDly_ExtIni
 * '<S68>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_03_Calcul_du_remplissage_dynamique/F01_02_03_05_Filtarge_du_remplissage/Filtre_1er_ordre  avec reset1/filtrage
 * '<S69>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_01_Calcul_du_retrait_d_avance
 * '<S70>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_02_Pente_de_retour
 * '<S71>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_03_Gestion_du_correctif_cliquetis_dynamique
 * '<S72>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_01_Calcul_du_retrait_d_avance/Carto_2D2
 * '<S73>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_01_Calcul_du_retrait_d_avance/Carto_2D3
 * '<S74>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_01_Calcul_du_retrait_d_avance/Carto_2D4
 * '<S75>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_01_Calcul_du_retrait_d_avance/multiplication_421
 * '<S76>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_01_Calcul_du_retrait_d_avance/multiplication_431
 * '<S77>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_02_Pente_de_retour/division_441
 * '<S78>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_02_Pente_de_retour/division_451
 * '<S79>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_03_Gestion_du_correctif_cliquetis_dynamique/F01_02_04_03_01_Automate
 * '<S80>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_01_Aspect_richesse_correctif_statique
 * '<S81>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_02_Aspect_EGR_correctif_statique
 * '<S82>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_03_Aspect_Patmo_correctif_statique
 * '<S83>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_04_Aspect_temperatures_correctif_statique
 * '<S84>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_01_Aspect_richesse_correctif_statique/Carto_2D
 * '<S85>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_02_Aspect_EGR_correctif_statique/Carto_2D
 * '<S86>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_02_Aspect_EGR_correctif_statique/multiplication_461
 * '<S87>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_03_Aspect_Patmo_correctif_statique/Carto_1D
 * '<S88>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_03_Aspect_Patmo_correctif_statique/Carto_2D
 * '<S89>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_03_Aspect_Patmo_correctif_statique/Rte_Call_R_FRM_bAcvPAirExtMesDft_GetFunctionPermission
 * '<S90>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_03_Aspect_Patmo_correctif_statique/multiplication_471
 * '<S91>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_04_Aspect_temperatures_correctif_statique/Carto_2D
 * '<S92>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_04_Aspect_temperatures_correctif_statique/Carto_2D1
 * '<S93>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_04_Aspect_temperatures_correctif_statique/Carto_2D2
 * '<S94>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_04_Aspect_temperatures_correctif_statique/Rte_Call_R_FRM_bAcvTCoMesDft_GetFunctionPermission
 * '<S95>'  : AdvPrevKnkT_AUTOSAR/AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_05_Avance_preventive_statique/F01_02_05_04_Aspect_temperatures_correctif_statique/multiplication_481
 */

/*-
 * Requirements for '<Root>': AdvPrevKnkT
 *
 * Inherited requirements for '<S1>/F00_AdvPrevKnkT_init':
 *  1. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_024.01 ;
 *  2. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_042.01 ;
 *  3. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_047.01 ;
 *  4. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_048.01 ;
 *
 * Inherited requirements for '<S1>/F01_AdvPrevKnkT':
 *  1. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_001.01 ;
 *  2. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_002.01 ;
 *  3. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_024.01 ;
 *  4. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_025.01 ;
 *  5. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_026.01 ;
 *  6. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_027.01 ;
 *  7. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_028.01 ;
 *  8. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_029.02 ;
 *  9. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_030.01 ;
 *  10. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_031.01 ;
 *  11. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_032.01 ;
 *  12. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_033.01 ;
 *  13. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_034.01 ;
 *  14. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_035.01 ;
 *  15. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_036.01 ;
 *  16. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_037.01 ;
 *  17. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_038.01 ;
 *  18. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_039.02 ;
 *  19. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_040.01 ;
 *  20. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_041.01 ;
 *  21. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_042.01 ;
 *  22. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_043.01 ;
 *  23. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_044.01 ;
 *  24. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_045.01 ;
 *  25. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_046.01 ;
 *  26. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_047.01 ;
 *  27. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_048.01 ;
 *  28. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_049.01 ;
 *  29. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_050.01 ;
 *  30. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_051.01 ;
 *  31. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_052.01 ;
 *  32. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_053.01 ;
 *  33. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_054.01 ;

 */
#endif                                 /* RTW_HEADER_AdvPrevKnkT_h_ */

/*-------------------------------- end of file -------------------------------*/
