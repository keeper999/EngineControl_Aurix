/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F07_Residual_scavenged_reaspired_mass               */
/*                                                                            */
/* !File            : AFA_F07_Residual_scavenged_reaspired_mass.h             */
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
/*   Model name       : AFA_F07_Residual_scavenged_reaspired_mass.mdl         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F07_Residual_scavenged_reaspired_mass_h_
#define RTW_HEADER_AFA_F07_Residual_scavenged_reaspired_mass_h_
#ifndef AFA_F07_Residual_scavenged_reaspired_mass_COMMON_INCLUDES_
# define AFA_F07_Residual_scavenged_reaspired_mass_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F07_Residual_scavenged_reaspired_mass_import.h"
#include "rtw_shared_utils.h"
#include "rt_MAXf.h"
#include "rt_MINf.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F07_Residual_scavenged_reaspired_mass_COMMON_INCLUDES_ */

#include "AFA_F07_Residual_scavenged_reaspired_mass_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Block signals for model 'AFA_F07_Residual_scavenged_reaspired_mass' */
#ifndef AFA_F07_Residual_scavenged_reaspired_mass_MDLREF_HIDE_CHILD_

typedef struct {
  Float32 Merge1;                     /* '<S7>/Merge1' */
  Float32 Merge;                      /* '<S6>/Merge' */
} rtB_mr_AFA_F07_Residual_scaveng;

#endif                                 /*AFA_F07_Residual_scavenged_reaspired_mass_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F07_Residual_scavenged_reaspired_mass_MDLREF_HIDE_CHILD_

typedef struct {
  rtB_mr_AFA_F07_Residual_scaveng rtb;
} rtMdlrefDWork_mr_AFA_F07_Residu;

#endif                                 /*AFA_F07_Residual_scavenged_reaspired_mass_MDLREF_HIDE_CHILD_*/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern UInt32 AFA_facTExSqrt_MP;     /* '<S25>/Look-Up Table' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

extern UInt16 AFA_nEngCorScvFil;     /* '<S10>/Switch' */
extern SInt16 AFA_rMassBurn_agCkEx;   /* '<S110>/OutDTConv' */
extern SInt16 AFA_rMassBurn_agCkIn;   /* '<S111>/OutDTConv' */
extern UInt16 AFA_facMassFlowCor;    /* '<S17>/Look-Up Table (2-D)' */
extern UInt16 AFA_rMassBurn;         /* '<S109>/OutDTConv' */
extern UInt16 AFA_rMassAirScv;       /* '<S7>/Merge' */
extern UInt16 AFA_facAirScv;         /* '<S94>/OutDTConv' */
extern SInt16 AFA_mGrdBurnRspg_pDsThr;/* '<S49>/OutDTConv' */
extern UInt16 AFA_mGrdAirScvTot_pDsThr;/* '<S89>/OutDTConv' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern SInt16 AFA_rMassGrdBnRgBstSat_agCkEx;/* '<S7>/Data Store Memory2' */
extern SInt16 AFA_rMassGrdBnRgBstSat_agCkIn;/* '<S7>/Data Store Memory3' */
extern SInt16 AFA_rMassGrdBurnRgSat_agCkIn;/* '<S5>/Data Store Memory1' */
extern SInt16 AFA_rMassGrdBurnRgCor_agCkIn;/* '<S5>/Data Store Memory2' */
extern SInt16 AFA_rMassGrdBurnRgCor_agCkEx;/* '<S5>/Data Store Memory4' */
extern SInt16 AFA_rMassGrdBurnRgSat_agCkEx;/* '<S5>/Data Store Memory5' */
extern SInt16 AFA_rVolCylGrd_agCkOpIn_MP;/* '<S4>/Data Store Memory1' */
extern SInt16 AFA_facCorMassGrdBurnRg_MP;/* '<S4>/Data Store Memory2' */
extern SInt16 AFA_rMassGrdBurnRgTot_agCkIn;/* '<S4>/Data Store Memory5' */
extern SInt16 AFA_rMassGrdBurnRgTot_agCkEx;/* '<S4>/Data Store Memory6' */
extern SInt16 AFA_rMassGrdBurnRspg_agCkEx;/* '<S22>/Data Store Memory2' */
extern SInt16 AFA_rMassGrdBurnRspgTot_agCkEx;/* '<S22>/Data Store Memory3' */
extern SInt16 AFA_rMassGrdBurnRspg_agCkIn;/* '<S22>/Data Store Memory4' */
extern SInt16 AFA_rMassGrdBurnRspgTot_agCkIn;/* '<S22>/Data Store Memory5' */
extern SInt16 AFA_facMassFlowGrd_agCkEx;/* '<S1>/Data Store Memory' */
extern SInt16 AFA_facMassFlowGrd_agCkIn;/* '<S1>/Data Store Memory1' */
extern UInt16 AFA_facMassFlowLd;     /* '<S2>/Data Store Memory' */
extern UInt16 AFA_rFacMassGrdBurnRspgTot;/* '<S21>/Data Store Memory' */
extern SInt16 AFA_rMassBurnRgCor;     /* '<S5>/Data Store Memory' */
extern SInt16 AFA_rMassBurnRspgTot;   /* '<S21>/Data Store Memory1' */
extern UInt16 AFA_rMassBurnRgBoostCorSat;/* '<S7>/Data Store Memory1' */
extern UInt16 AFA_rMassAirScvTot;    /* '<S6>/Data Store Memory3' */
extern UInt16 AFA_rMassBurnRgCorSat; /* '<S5>/Data Store Memory3' */
extern UInt16 AFA_rMassBurnRgTot;    /* '<S4>/Data Store Memory4' */
extern UInt16 AFA_rMassBurnRspg;     /* '<S21>/Data Store Memory2' */
extern UInt16 AFA_mfAirScvRedCor_MP; /* '<S70>/Data Store Memory2' */
extern UInt16 AFA_mfBurnRspgRedBas;  /* '<S21>/Data Store Memory3' */
extern UInt16 AFA_facChrExpFil;      /* '<S21>/Data Store Memory4' */
extern UInt16 AFA_mfBurnRspgRedCor;  /* '<S21>/Data Store Memory5' */
extern UInt16 AFA_mfGrdBurnRspgRed_MP;/* '<S22>/Data Store Memory1' */
extern SInt16 AFA_rVolGrdCyl_MP;      /* '<S4>/Data Store Memory' */
extern UInt16 AFA_facTInSqrt_MP;     /* '<S70>/Data Store Memory1' */
extern UInt16 AFA_rVolCyl_MP;        /* '<S4>/Data Store Memory3' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"


#ifndef AFA_F07_Residual_scavenged_reaspired_mass_MDLREF_HIDE_CHILD_

extern rtMdlrefDWork_mr_AFA_F07_Residu mr_AFA_F07_Residual_MdlrefDWork;

#endif                                 /*AFA_F07_Residual_scavenged_reaspired_mass_MDLREF_HIDE_CHILD_*/


#define AFAT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F07_Residual_scave_Start(void);
extern void mr_AFA_F07_Residual_scavenged_r(const UInt16 *rtu_AFA_nEngFil,
  const UInt16 *rtu_AFA_pDsThrPred_facVlvOvlp_, const UInt16
  *rtu_AFA_pExMnfEstimFi7, const UInt16 *rtu_AFA_tExMnfEstimFi7, const SInt16
  *rtu_AFA_agCkVlvOvlp, const UInt16 *rtu_AFA_agCkPosnVlvOvlp, const SInt16
  *rtu_AFA_agCkOpInVlvEstimRef1Fil, const SInt16
  *rtu_AFA_agCkClsExVlvEstimRef1Fi, const UInt32 *rtu_AFA_tAirUsInVlvEstimFil,
  const UInt16 *rtu_AFA_mfArGrdVlv_rPresInEx, const UInt16
  *rtu_AFA_mfArGrdVlv_rPresExIn, const UInt16 *rtu_AFA_nEngCorFil, UInt16
  *rty_AFA_rMassBurnRspg, SInt16 *rty_AFA_rMassGrdBurnRspg_agCkEx, SInt16
  *rty_AFA_rMassGrdBurnRspg_agCkIn, UInt16 *rty_AFA_rMassBurnRg, SInt16
  *rty_AFA_rMassGrdBurnRg_agCkEx, SInt16 *rty_AFA_rMassGrdBurnRg_agCkIn,
  UInt16 *rty_AFA_rMassBurn, SInt16 *rty_AFA_rMassBurn_agCkEx, SInt16
  *rty_AFA_rMassBurn_agCkIn, SInt16 *rty_AFA_mGrdBurnRspg_pDsThr, UInt16
  *rty_AFA_facAirScv, UInt16 *rty_AFA_mGrdAirScvTot_pDsThr, UInt16
  *rty_AFA_rMassAirScv);

/* Model reference registration function */
extern void mr_AFA_F07_Residual__initialize(void);

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */

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
 * Block '<S1>/AirEfc_agCkPosnVlvOvlpX_A' : Unused code path elimination
 * Block '<S1>/AirEfc_nEngY_A1' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S17>/TABLE' : Unused code path elimination
 * Block '<S17>/TABLE1' : Unused code path elimination
 * Block '<S17>/TABLE2' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S18>/x1' : Unused code path elimination
 * Block '<S18>/x2' : Unused code path elimination
 * Block '<S21>/AirEfc_tExMnf_A' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/x1' : Unused code path elimination
 * Block '<S25>/BKPT1' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S25>/TABLE' : Unused code path elimination
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
 * Block '<S28>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S28>/x1' : Unused code path elimination
 * Block '<S28>/x2' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S29>/x1' : Unused code path elimination
 * Block '<S29>/x2' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S42>/x1' : Unused code path elimination
 * Block '<S42>/x2' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S43>/x1' : Unused code path elimination
 * Block '<S43>/x2' : Unused code path elimination
 * Block '<S4>/AirEfc_bVolBurnRgTot_C7' : Unused code path elimination
 * Block '<S4>/AirEfc_bVolBurnRgTot_C8' : Unused code path elimination
 * Block '<S4>/AirEfc_pRef_C1' : Unused code path elimination
 * Block '<S4>/AirEfc_pRef_C10' : Unused code path elimination
 * Block '<S4>/AirEfc_pRef_C2' : Unused code path elimination
 * Block '<S4>/AirEfc_pRef_C5' : Unused code path elimination
 * Block '<S4>/AirEfc_pRef_C6' : Unused code path elimination
 * Block '<S4>/AirEfc_pRef_C7' : Unused code path elimination
 * Block '<S4>/AirEfc_pRef_C8' : Unused code path elimination
 * Block '<S4>/AirEfc_pRef_C9' : Unused code path elimination
 * Block '<S50>/BKPT1' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S50>/TABLE' : Unused code path elimination
 * Block '<S51>/BKPT1' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S51>/TABLE' : Unused code path elimination
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
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S55>/TABLE' : Unused code path elimination
 * Block '<S55>/TABLE1' : Unused code path elimination
 * Block '<S55>/TABLE2' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S56>/x1' : Unused code path elimination
 * Block '<S56>/x2' : Unused code path elimination
 * Block '<S61>/Force any float to Double everything else to uint8' : Unused code path elimination
 * Block '<S61>/Force any float to Single everything else to uint8' : Unused code path elimination
 * Block '<S70>/AirEfc_tAirUsInVlv_A' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S74>/x1' : Unused code path elimination
 * Block '<S75>/BKPT1' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S75>/TABLE' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Relational Operator' : Unused code path elimination
 * Block '<S76>/Relational Operator1' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Propagation' : Unused code path elimination
 * Block '<S77>/Data Type Propagation' : Unused code path elimination
 * Block '<S77>/Data Type Propagation1' : Unused code path elimination
 * Block '<S85>/Data Type Propagation' : Unused code path elimination
 * Block '<S85>/Data Type Conversion' : Unused code path elimination
 * Block '<S85>/Data Type Conversion1' : Unused code path elimination
 * Block '<S78>/Data Type Propagation' : Unused code path elimination
 * Block '<S78>/Data Type Propagation1' : Unused code path elimination
 * Block '<S87>/Data Type Propagation' : Unused code path elimination
 * Block '<S87>/Data Type Conversion' : Unused code path elimination
 * Block '<S87>/Data Type Conversion1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S79>/x1' : Unused code path elimination
 * Block '<S79>/x2' : Unused code path elimination
 * Block '<S98>/Data Type Propagation' : Unused code path elimination
 * Block '<S98>/Data Type Propagation1' : Unused code path elimination
 * Block '<S99>/Data Type Propagation' : Unused code path elimination
 * Block '<S99>/Data Type Conversion' : Unused code path elimination
 * Block '<S99>/Data Type Conversion1' : Unused code path elimination
 * Block '<S101>/Data Type Propagation' : Unused code path elimination
 * Block '<S101>/Data Type Propagation1' : Unused code path elimination
 * Block '<S105>/Data Type Propagation' : Unused code path elimination
 * Block '<S105>/Data Type Conversion' : Unused code path elimination
 * Block '<S105>/Data Type Conversion1' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S102>/x1' : Unused code path elimination
 * Block '<S102>/x2' : Unused code path elimination
 * Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S19>/Switch' : Eliminated due to constant selection input
 * Block '<S20>/Switch' : Eliminated due to constant selection input
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S30>/Switch' : Eliminated due to constant selection input
 * Block '<S31>/Switch' : Eliminated due to constant selection input
 * Block '<S32>/Switch' : Eliminated due to constant selection input
 * Block '<S33>/Switch' : Eliminated due to constant selection input
 * Block '<S34>/Switch' : Eliminated due to constant selection input
 * Block '<S35>/Switch' : Eliminated due to constant selection input
 * Block '<S36>/Switch' : Eliminated due to constant selection input
 * Block '<S44>/Switch' : Eliminated due to constant selection input
 * Block '<S45>/Switch' : Eliminated due to constant selection input
 * Block '<S46>/Switch' : Eliminated due to constant selection input
 * Block '<S47>/Switch' : Eliminated due to constant selection input
 * Block '<S48>/Switch' : Eliminated due to constant selection input
 * Block '<S49>/Switch' : Eliminated due to constant selection input
 * Block '<S50>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S53>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S53>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S4>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S58>/Switch' : Eliminated due to constant selection input
 * Block '<S59>/Switch' : Eliminated due to constant selection input
 * Block '<S60>/Switch' : Eliminated due to constant selection input
 * Block '<S64>/Switch' : Eliminated due to constant selection input
 * Block '<S65>/Switch' : Eliminated due to constant selection input
 * Block '<S66>/Switch' : Eliminated due to constant selection input
 * Block '<S67>/Switch' : Eliminated due to constant selection input
 * Block '<S68>/Switch' : Eliminated due to constant selection input
 * Block '<S69>/Switch' : Eliminated due to constant selection input
 * Block '<S82>/Conversion' : Eliminate redundant data type conversion
 * Block '<S83>/Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S77>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S77>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S78>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S78>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S78>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S70>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S80>/Switch' : Eliminated due to constant selection input
 * Block '<S81>/Switch' : Eliminated due to constant selection input
 * Block '<S89>/Switch' : Eliminated due to constant selection input
 * Block '<S73>/Switch' : Eliminated due to constant selection input
 * Block '<S98>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S98>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S98>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S103>/Switch' : Eliminated due to constant selection input
 * Block '<S104>/Switch' : Eliminated due to constant selection input
 * Block '<S94>/Switch' : Eliminated due to constant selection input
 * Block '<S95>/Switch' : Eliminated due to constant selection input
 * Block '<S96>/Switch' : Eliminated due to constant selection input
 * Block '<S97>/Switch' : Eliminated due to constant selection input
 * Block '<S109>/Switch' : Eliminated due to constant selection input
 * Block '<S110>/Switch' : Eliminated due to constant selection input
 * Block '<S111>/Switch' : Eliminated due to constant selection input
 * Block '<S11>/Switch' : Eliminated due to constant selection input
 * Block '<S12>/Switch' : Eliminated due to constant selection input
 * Block '<S13>/Switch' : Eliminated due to constant selection input
 * Block '<S14>/Switch' : Eliminated due to constant selection input
 * Block '<S15>/Switch' : Eliminated due to constant selection input
 * Block '<S16>/Switch' : Eliminated due to constant selection input
 * Block '<S19>/Add2' : Unused code path elimination
 * Block '<S19>/Constant' : Unused code path elimination
 * Block '<S19>/offset1' : Unused code path elimination
 * Block '<S20>/Add3' : Unused code path elimination
 * Block '<S20>/Add4' : Unused code path elimination
 * Block '<S20>/Constant' : Unused code path elimination
 * Block '<S20>/Relational Operator' : Unused code path elimination
 * Block '<S20>/Switch1' : Unused code path elimination
 * Block '<S20>/offset2' : Unused code path elimination
 * Block '<S20>/offset3' : Unused code path elimination
 * Block '<S20>/offset4' : Unused code path elimination
 * Block '<S30>/Add3' : Unused code path elimination
 * Block '<S30>/Add4' : Unused code path elimination
 * Block '<S30>/Constant' : Unused code path elimination
 * Block '<S30>/Relational Operator' : Unused code path elimination
 * Block '<S30>/Switch1' : Unused code path elimination
 * Block '<S30>/offset2' : Unused code path elimination
 * Block '<S30>/offset3' : Unused code path elimination
 * Block '<S30>/offset4' : Unused code path elimination
 * Block '<S31>/Add2' : Unused code path elimination
 * Block '<S31>/Constant' : Unused code path elimination
 * Block '<S31>/offset1' : Unused code path elimination
 * Block '<S32>/Add3' : Unused code path elimination
 * Block '<S32>/Add4' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S32>/Relational Operator' : Unused code path elimination
 * Block '<S32>/Switch1' : Unused code path elimination
 * Block '<S32>/offset2' : Unused code path elimination
 * Block '<S32>/offset3' : Unused code path elimination
 * Block '<S32>/offset4' : Unused code path elimination
 * Block '<S33>/Add3' : Unused code path elimination
 * Block '<S33>/Add4' : Unused code path elimination
 * Block '<S33>/Constant' : Unused code path elimination
 * Block '<S33>/Relational Operator' : Unused code path elimination
 * Block '<S33>/Switch1' : Unused code path elimination
 * Block '<S33>/offset2' : Unused code path elimination
 * Block '<S33>/offset3' : Unused code path elimination
 * Block '<S33>/offset4' : Unused code path elimination
 * Block '<S34>/Add3' : Unused code path elimination
 * Block '<S34>/Add4' : Unused code path elimination
 * Block '<S34>/Constant' : Unused code path elimination
 * Block '<S34>/Relational Operator' : Unused code path elimination
 * Block '<S34>/Switch1' : Unused code path elimination
 * Block '<S34>/offset2' : Unused code path elimination
 * Block '<S34>/offset3' : Unused code path elimination
 * Block '<S34>/offset4' : Unused code path elimination
 * Block '<S35>/Add3' : Unused code path elimination
 * Block '<S35>/Add4' : Unused code path elimination
 * Block '<S35>/Constant' : Unused code path elimination
 * Block '<S35>/Relational Operator' : Unused code path elimination
 * Block '<S35>/Switch1' : Unused code path elimination
 * Block '<S35>/offset2' : Unused code path elimination
 * Block '<S35>/offset3' : Unused code path elimination
 * Block '<S35>/offset4' : Unused code path elimination
 * Block '<S36>/Add3' : Unused code path elimination
 * Block '<S36>/Add4' : Unused code path elimination
 * Block '<S36>/Constant' : Unused code path elimination
 * Block '<S36>/Relational Operator' : Unused code path elimination
 * Block '<S36>/Switch1' : Unused code path elimination
 * Block '<S36>/offset2' : Unused code path elimination
 * Block '<S36>/offset3' : Unused code path elimination
 * Block '<S36>/offset4' : Unused code path elimination
 * Block '<S44>/Add3' : Unused code path elimination
 * Block '<S44>/Add4' : Unused code path elimination
 * Block '<S44>/Constant' : Unused code path elimination
 * Block '<S44>/Relational Operator' : Unused code path elimination
 * Block '<S44>/Switch1' : Unused code path elimination
 * Block '<S44>/offset2' : Unused code path elimination
 * Block '<S44>/offset3' : Unused code path elimination
 * Block '<S44>/offset4' : Unused code path elimination
 * Block '<S45>/Add2' : Unused code path elimination
 * Block '<S45>/Constant' : Unused code path elimination
 * Block '<S45>/offset1' : Unused code path elimination
 * Block '<S46>/Add2' : Unused code path elimination
 * Block '<S46>/Constant' : Unused code path elimination
 * Block '<S46>/offset1' : Unused code path elimination
 * Block '<S47>/Add2' : Unused code path elimination
 * Block '<S47>/Constant' : Unused code path elimination
 * Block '<S47>/offset1' : Unused code path elimination
 * Block '<S48>/Add2' : Unused code path elimination
 * Block '<S48>/Constant' : Unused code path elimination
 * Block '<S48>/offset1' : Unused code path elimination
 * Block '<S49>/Add2' : Unused code path elimination
 * Block '<S49>/Constant' : Unused code path elimination
 * Block '<S49>/offset1' : Unused code path elimination
 * Block '<S58>/Add3' : Unused code path elimination
 * Block '<S58>/Add4' : Unused code path elimination
 * Block '<S58>/Constant' : Unused code path elimination
 * Block '<S58>/Relational Operator' : Unused code path elimination
 * Block '<S58>/Switch1' : Unused code path elimination
 * Block '<S58>/offset2' : Unused code path elimination
 * Block '<S58>/offset3' : Unused code path elimination
 * Block '<S58>/offset4' : Unused code path elimination
 * Block '<S59>/Add2' : Unused code path elimination
 * Block '<S59>/Constant' : Unused code path elimination
 * Block '<S59>/offset1' : Unused code path elimination
 * Block '<S60>/Add2' : Unused code path elimination
 * Block '<S60>/Constant' : Unused code path elimination
 * Block '<S60>/offset1' : Unused code path elimination
 * Block '<S64>/Add2' : Unused code path elimination
 * Block '<S64>/Constant' : Unused code path elimination
 * Block '<S64>/offset1' : Unused code path elimination
 * Block '<S65>/Add3' : Unused code path elimination
 * Block '<S65>/Add4' : Unused code path elimination
 * Block '<S65>/Constant' : Unused code path elimination
 * Block '<S65>/Relational Operator' : Unused code path elimination
 * Block '<S65>/Switch1' : Unused code path elimination
 * Block '<S65>/offset2' : Unused code path elimination
 * Block '<S65>/offset3' : Unused code path elimination
 * Block '<S65>/offset4' : Unused code path elimination
 * Block '<S66>/Add2' : Unused code path elimination
 * Block '<S66>/Constant' : Unused code path elimination
 * Block '<S66>/offset1' : Unused code path elimination
 * Block '<S67>/Add2' : Unused code path elimination
 * Block '<S67>/Constant' : Unused code path elimination
 * Block '<S67>/offset1' : Unused code path elimination
 * Block '<S68>/Add2' : Unused code path elimination
 * Block '<S68>/Constant' : Unused code path elimination
 * Block '<S68>/offset1' : Unused code path elimination
 * Block '<S69>/Add2' : Unused code path elimination
 * Block '<S69>/Constant' : Unused code path elimination
 * Block '<S69>/offset1' : Unused code path elimination
 * Block '<S80>/Add3' : Unused code path elimination
 * Block '<S80>/Add4' : Unused code path elimination
 * Block '<S80>/Constant' : Unused code path elimination
 * Block '<S80>/Relational Operator' : Unused code path elimination
 * Block '<S80>/Switch1' : Unused code path elimination
 * Block '<S80>/offset2' : Unused code path elimination
 * Block '<S80>/offset3' : Unused code path elimination
 * Block '<S80>/offset4' : Unused code path elimination
 * Block '<S81>/Add3' : Unused code path elimination
 * Block '<S81>/Add4' : Unused code path elimination
 * Block '<S81>/Constant' : Unused code path elimination
 * Block '<S81>/Relational Operator' : Unused code path elimination
 * Block '<S81>/Switch1' : Unused code path elimination
 * Block '<S81>/offset2' : Unused code path elimination
 * Block '<S81>/offset3' : Unused code path elimination
 * Block '<S81>/offset4' : Unused code path elimination
 * Block '<S89>/Add3' : Unused code path elimination
 * Block '<S89>/Add4' : Unused code path elimination
 * Block '<S89>/Constant' : Unused code path elimination
 * Block '<S89>/Relational Operator' : Unused code path elimination
 * Block '<S89>/Switch1' : Unused code path elimination
 * Block '<S89>/offset2' : Unused code path elimination
 * Block '<S89>/offset3' : Unused code path elimination
 * Block '<S89>/offset4' : Unused code path elimination
 * Block '<S73>/Add3' : Unused code path elimination
 * Block '<S73>/Add4' : Unused code path elimination
 * Block '<S73>/Constant' : Unused code path elimination
 * Block '<S73>/Relational Operator' : Unused code path elimination
 * Block '<S73>/Switch1' : Unused code path elimination
 * Block '<S73>/offset2' : Unused code path elimination
 * Block '<S73>/offset3' : Unused code path elimination
 * Block '<S73>/offset4' : Unused code path elimination
 * Block '<S103>/Add3' : Unused code path elimination
 * Block '<S103>/Add4' : Unused code path elimination
 * Block '<S103>/Constant' : Unused code path elimination
 * Block '<S103>/Relational Operator' : Unused code path elimination
 * Block '<S103>/Switch1' : Unused code path elimination
 * Block '<S103>/offset2' : Unused code path elimination
 * Block '<S103>/offset3' : Unused code path elimination
 * Block '<S103>/offset4' : Unused code path elimination
 * Block '<S104>/Add3' : Unused code path elimination
 * Block '<S104>/Add4' : Unused code path elimination
 * Block '<S104>/Constant' : Unused code path elimination
 * Block '<S104>/Relational Operator' : Unused code path elimination
 * Block '<S104>/Switch1' : Unused code path elimination
 * Block '<S104>/offset2' : Unused code path elimination
 * Block '<S104>/offset3' : Unused code path elimination
 * Block '<S104>/offset4' : Unused code path elimination
 * Block '<S94>/Add3' : Unused code path elimination
 * Block '<S94>/Add4' : Unused code path elimination
 * Block '<S94>/Constant' : Unused code path elimination
 * Block '<S94>/Relational Operator' : Unused code path elimination
 * Block '<S94>/Switch1' : Unused code path elimination
 * Block '<S94>/offset2' : Unused code path elimination
 * Block '<S94>/offset3' : Unused code path elimination
 * Block '<S94>/offset4' : Unused code path elimination
 * Block '<S95>/Add3' : Unused code path elimination
 * Block '<S95>/Add4' : Unused code path elimination
 * Block '<S95>/Constant' : Unused code path elimination
 * Block '<S95>/Relational Operator' : Unused code path elimination
 * Block '<S95>/Switch1' : Unused code path elimination
 * Block '<S95>/offset2' : Unused code path elimination
 * Block '<S95>/offset3' : Unused code path elimination
 * Block '<S95>/offset4' : Unused code path elimination
 * Block '<S96>/Add2' : Unused code path elimination
 * Block '<S96>/Constant' : Unused code path elimination
 * Block '<S96>/offset1' : Unused code path elimination
 * Block '<S97>/Add2' : Unused code path elimination
 * Block '<S97>/Constant' : Unused code path elimination
 * Block '<S97>/offset1' : Unused code path elimination
 * Block '<S109>/Add3' : Unused code path elimination
 * Block '<S109>/Add4' : Unused code path elimination
 * Block '<S109>/Constant' : Unused code path elimination
 * Block '<S109>/Relational Operator' : Unused code path elimination
 * Block '<S109>/Switch1' : Unused code path elimination
 * Block '<S109>/offset2' : Unused code path elimination
 * Block '<S109>/offset3' : Unused code path elimination
 * Block '<S109>/offset4' : Unused code path elimination
 * Block '<S110>/Add2' : Unused code path elimination
 * Block '<S110>/Constant' : Unused code path elimination
 * Block '<S110>/offset1' : Unused code path elimination
 * Block '<S111>/Add2' : Unused code path elimination
 * Block '<S111>/Constant' : Unused code path elimination
 * Block '<S111>/offset1' : Unused code path elimination
 * Block '<S11>/Add3' : Unused code path elimination
 * Block '<S11>/Add4' : Unused code path elimination
 * Block '<S11>/Constant' : Unused code path elimination
 * Block '<S11>/Relational Operator' : Unused code path elimination
 * Block '<S11>/Switch1' : Unused code path elimination
 * Block '<S11>/offset2' : Unused code path elimination
 * Block '<S11>/offset3' : Unused code path elimination
 * Block '<S11>/offset4' : Unused code path elimination
 * Block '<S12>/Add2' : Unused code path elimination
 * Block '<S12>/Constant' : Unused code path elimination
 * Block '<S12>/offset1' : Unused code path elimination
 * Block '<S13>/Add2' : Unused code path elimination
 * Block '<S13>/Constant' : Unused code path elimination
 * Block '<S13>/offset1' : Unused code path elimination
 * Block '<S14>/Add3' : Unused code path elimination
 * Block '<S14>/Add4' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S14>/Relational Operator' : Unused code path elimination
 * Block '<S14>/Switch1' : Unused code path elimination
 * Block '<S14>/offset2' : Unused code path elimination
 * Block '<S14>/offset3' : Unused code path elimination
 * Block '<S14>/offset4' : Unused code path elimination
 * Block '<S15>/Add2' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S15>/offset1' : Unused code path elimination
 * Block '<S16>/Add2' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S16>/offset1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AFA_F07_Residual_scavenged_reaspired_mass
 * '<S1>'   : AFA_F07_Residual_scavenged_reaspired_mass/F01_Correction_reaspired_scavenged_massflow
 * '<S2>'   : AFA_F07_Residual_scavenged_reaspired_mass/F02_Coefficient_massflow_to_load
 * '<S3>'   : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass
 * '<S4>'   : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass
 * '<S5>'   : AFA_F07_Residual_scavenged_reaspired_mass/F05_Atmospheric_residual_burn_mass
 * '<S6>'   : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass
 * '<S7>'   : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass
 * '<S8>'   : AFA_F07_Residual_scavenged_reaspired_mass/F08_residual_burn_mass
 * '<S9>'   : AFA_F07_Residual_scavenged_reaspired_mass/F09_burn_mass
 * '<S10>'  : AFA_F07_Residual_scavenged_reaspired_mass/F10_Engine_speed_choice
 * '<S11>'  : AFA_F07_Residual_scavenged_reaspired_mass/SingleToFixdt
 * '<S12>'  : AFA_F07_Residual_scavenged_reaspired_mass/SingleToFixdt1
 * '<S13>'  : AFA_F07_Residual_scavenged_reaspired_mass/SingleToFixdt2
 * '<S14>'  : AFA_F07_Residual_scavenged_reaspired_mass/SingleToFixdt3
 * '<S15>'  : AFA_F07_Residual_scavenged_reaspired_mass/SingleToFixdt4
 * '<S16>'  : AFA_F07_Residual_scavenged_reaspired_mass/SingleToFixdt5
 * '<S17>'  : AFA_F07_Residual_scavenged_reaspired_mass/F01_Correction_reaspired_scavenged_massflow/Carto_2D
 * '<S18>'  : AFA_F07_Residual_scavenged_reaspired_mass/F01_Correction_reaspired_scavenged_massflow/LookUp_2D
 * '<S19>'  : AFA_F07_Residual_scavenged_reaspired_mass/F01_Correction_reaspired_scavenged_massflow/SingleToFixdt
 * '<S20>'  : AFA_F07_Residual_scavenged_reaspired_mass/F02_Coefficient_massflow_to_load/SingleToFixdt
 * '<S21>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal
 * '<S22>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT
 * '<S23>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F03_Calcul_derive_Pcol
 * '<S24>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/Carto_1D1
 * '<S25>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/Carto_1D2
 * '<S26>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/Div_float_only
 * '<S27>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/Div_float_only1
 * '<S28>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/LookUp_2D
 * '<S29>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/LookUp_2D1
 * '<S30>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/SingleToFixdt
 * '<S31>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/SingleToFixdt1
 * '<S32>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/SingleToFixdt2
 * '<S33>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/SingleToFixdt3
 * '<S34>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/SingleToFixdt4
 * '<S35>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/SingleToFixdt5
 * '<S36>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/SingleToFixdt6
 * '<S37>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/Div_float_only/Data Type Police Only single
 * '<S38>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/Div_float_only/If Action Subsystem3
 * '<S39>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/Div_float_only1/Data Type Police Only single
 * '<S40>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F01_calcul_nominal/Div_float_only1/If Action Subsystem3
 * '<S41>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT/CompareToZero
 * '<S42>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT/LookUp_2D
 * '<S43>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT/LookUp_2D1
 * '<S44>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT/SingleToFixdt
 * '<S45>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT/SingleToFixdt1
 * '<S46>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT/SingleToFixdt2
 * '<S47>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT/SingleToFixdt3
 * '<S48>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F02_calcul_derive_VVT/SingleToFixdt4
 * '<S49>'  : AFA_F07_Residual_scavenged_reaspired_mass/F03_Reaspired_burn_mass/F03_Calcul_derive_Pcol/SingleToFixdt
 * '<S50>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Carto_1D
 * '<S51>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Carto_1D1
 * '<S52>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Carto_2D
 * '<S53>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Carto_2D2
 * '<S54>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Carto_2D3
 * '<S55>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Carto_2D4
 * '<S56>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/LookUp_2D
 * '<S57>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Secured fixpoint division2
 * '<S58>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/SingleToFixdt
 * '<S59>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/SingleToFixdt1
 * '<S60>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/SingleToFixdt2
 * '<S61>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Secured fixpoint division2/Data Type Police No Floating Point1
 * '<S62>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Secured fixpoint division2/If Action Subsystem2
 * '<S63>'  : AFA_F07_Residual_scavenged_reaspired_mass/F04_Atmospheric_residual_total_burn_mass/Secured fixpoint division2/If Action Subsystem3
 * '<S64>'  : AFA_F07_Residual_scavenged_reaspired_mass/F05_Atmospheric_residual_burn_mass/SingleToFixdt
 * '<S65>'  : AFA_F07_Residual_scavenged_reaspired_mass/F05_Atmospheric_residual_burn_mass/SingleToFixdt1
 * '<S66>'  : AFA_F07_Residual_scavenged_reaspired_mass/F05_Atmospheric_residual_burn_mass/SingleToFixdt2
 * '<S67>'  : AFA_F07_Residual_scavenged_reaspired_mass/F05_Atmospheric_residual_burn_mass/SingleToFixdt3
 * '<S68>'  : AFA_F07_Residual_scavenged_reaspired_mass/F05_Atmospheric_residual_burn_mass/SingleToFixdt4
 * '<S69>'  : AFA_F07_Residual_scavenged_reaspired_mass/F05_Atmospheric_residual_burn_mass/SingleToFixdt5
 * '<S70>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal
 * '<S71>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F02_Scavenged_total_mass_init
 * '<S72>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F03_Calc_Sensitivity_Mbaltot
 * '<S73>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/SingleToFixdt
 * '<S74>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Carto_1D1
 * '<S75>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Carto_1D2
 * '<S76>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Clamp
 * '<S77>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Div_float_only
 * '<S78>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Div_float_only1
 * '<S79>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/LookUp_2D
 * '<S80>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/SingleToFixdt
 * '<S81>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/SingleToFixdt1
 * '<S82>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Clamp/Data Type Conversion Inherited
 * '<S83>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Clamp/Data Type Conversion Inherited1
 * '<S84>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Clamp/Saturation Dynamic
 * '<S85>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Div_float_only/Data Type Police Only single
 * '<S86>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Div_float_only/If Action Subsystem3
 * '<S87>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Div_float_only1/Data Type Police Only single
 * '<S88>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F01_Scavenged_total_mass_cal/Div_float_only1/If Action Subsystem3
 * '<S89>'  : AFA_F07_Residual_scavenged_reaspired_mass/F06_Scavenged_total_mass/F03_Calc_Sensitivity_Mbaltot/SingleToFixdt
 * '<S90>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F01_scavenged_and_residual_mass
 * '<S91>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F02_balancing_mass_cal
 * '<S92>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F03_balancing_mass_Def
 * '<S93>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F04_calcul_derive_VVT
 * '<S94>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/SingleToFixdt
 * '<S95>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/SingleToFixdt1
 * '<S96>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/SingleToFixdt2
 * '<S97>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/SingleToFixdt3
 * '<S98>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F01_scavenged_and_residual_mass/Div_float_only
 * '<S99>'  : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F01_scavenged_and_residual_mass/Div_float_only/Data Type Police Only single
 * '<S100>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F01_scavenged_and_residual_mass/Div_float_only/If Action Subsystem3
 * '<S101>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F02_balancing_mass_cal/Div_float_only1
 * '<S102>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F02_balancing_mass_cal/LookUp_2D
 * '<S103>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F02_balancing_mass_cal/SingleToFixdt
 * '<S104>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F02_balancing_mass_cal/SingleToFixdt1
 * '<S105>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F02_balancing_mass_cal/Div_float_only1/Data Type Police Only single
 * '<S106>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F02_balancing_mass_cal/Div_float_only1/If Action Subsystem3
 * '<S107>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F04_calcul_derive_VVT/CompareToZero1
 * '<S108>' : AFA_F07_Residual_scavenged_reaspired_mass/F07_Balancing_scavenged_and_residual_mass/F04_calcul_derive_VVT/CompareToZero2
 * '<S109>' : AFA_F07_Residual_scavenged_reaspired_mass/F09_burn_mass/SingleToFixdt
 * '<S110>' : AFA_F07_Residual_scavenged_reaspired_mass/F09_burn_mass/SingleToFixdt1
 * '<S111>' : AFA_F07_Residual_scavenged_reaspired_mass/F09_burn_mass/SingleToFixdt2
 */

/*-
 * Requirements for '<Root>': AFA_F07_Residual_scavenged_reaspired_mass
 */
#endif                                 /* RTW_HEADER_AFA_F07_Residual_scavenged_reaspired_mass_h_ */

/*-------------------------------- end of file -------------------------------*/
