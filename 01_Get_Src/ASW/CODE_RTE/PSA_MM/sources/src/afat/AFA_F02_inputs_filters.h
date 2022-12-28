/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F02_inputs_filters                                  */
/*                                                                            */
/* !File            : AFA_F02_inputs_filters.h                                */
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
/*   Model name       : AFA_F02_inputs_filters.mdl                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F02_inputs_filters_h_
#define RTW_HEADER_AFA_F02_inputs_filters_h_
#ifndef AFA_F02_inputs_filters_COMMON_INCLUDES_
# define AFA_F02_inputs_filters_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F02_inputs_filters_import.h"
#include "rt_SATURATE.h"
#endif                                 /* AFA_F02_inputs_filters_COMMON_INCLUDES_ */

#include "AFA_F02_inputs_filters_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Block states (auto storage) for model 'AFA_F02_inputs_filters' */
#ifndef AFA_F02_inputs_filters_MDLREF_HIDE_CHILD_

typedef struct {
  Float32 UnitDelay;                  /* '<S66>/UnitDelay' */
  Float32 UnitDelay_h;                /* '<S70>/UnitDelay' */
  Float32 UnitDelay_o;                /* '<S74>/UnitDelay' */
  Float32 UnitDelay_n;                /* '<S78>/UnitDelay' */
  Float32 UnitDelay_h4;               /* '<S82>/UnitDelay' */
  Float32 UnitDelay_l;                /* '<S86>/UnitDelay' */
  Float32 UnitDelay_a;                /* '<S90>/UnitDelay' */
  Float32 UnitDelay_os;               /* '<S94>/UnitDelay' */
  Float32 UnitDelay_m[4];             /* '<S98>/UnitDelay' */
  Float32 UnitDelay_ol;               /* '<S102>/UnitDelay' */
  Float32 UnitDelay_nr;               /* '<S106>/UnitDelay' */
  Float32 UnitDelay_hv;               /* '<S110>/UnitDelay' */
  Float32 UnitDelay_k;                /* '<S114>/UnitDelay' */
  Float32 UnitDelay_ky;               /* '<S118>/UnitDelay' */
  Float32 UnitDelay_j;                /* '<S122>/UnitDelay' */
  Float32 UnitDelay_i;                /* '<S126>/UnitDelay' */
  Float32 UnitDelay_iu;               /* '<S130>/UnitDelay' */
  Float32 UnitDelay_g;                /* '<S134>/UnitDelay' */
  Float32 UnitDelay_e;                /* '<S138>/UnitDelay' */
  Float32 UnitDelay_oo;               /* '<S142>/UnitDelay' */
  Float32 UnitDelay_p;                /* '<S146>/UnitDelay' */
  Float32 UnitDelay_i2;               /* '<S150>/UnitDelay' */
  Float32 UnitDelay_eh;               /* '<S154>/UnitDelay' */
  Float32 UnitDelay_g0;               /* '<S158>/UnitDelay' */
  Float32 UnitDelay_ps;               /* '<S162>/UnitDelay' */
  Float32 UnitDelay_b;                /* '<S166>/UnitDelay' */
  Float32 UnitDelay_mx;               /* '<S170>/UnitDelay' */
  Float32 UnitDelay_n5;               /* '<S174>/UnitDelay' */
  Float32 UnitDelay_hp[4];            /* '<S178>/UnitDelay' */
  Float32 UnitDelay_f[4];             /* '<S182>/UnitDelay' */
  Float32 UnitDelay_lk;               /* '<S186>/UnitDelay' */
  Boolean UnitDelay_b2;              /* '<S66>/UnitDelay1' */
  Boolean UnitDelay_DSTATE;          /* '<S64>/UnitDelay' */
  Boolean UnitDelay_pt;              /* '<S70>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_g;        /* '<S68>/UnitDelay' */
  Boolean UnitDelay_hpy;             /* '<S74>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_c;        /* '<S72>/UnitDelay' */
  Boolean UnitDelay_k4;              /* '<S78>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_f;        /* '<S76>/UnitDelay' */
  Boolean UnitDelay_psn;             /* '<S82>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_p;        /* '<S80>/UnitDelay' */
  Boolean UnitDelay_hh;              /* '<S86>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_k;        /* '<S84>/UnitDelay' */
  Boolean UnitDelay_ib;              /* '<S90>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_c1;       /* '<S88>/UnitDelay' */
  Boolean UnitDelay_gi;              /* '<S94>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_b;        /* '<S92>/UnitDelay' */
  Boolean UnitDelay_hf;              /* '<S98>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_a;        /* '<S96>/UnitDelay' */
  Boolean UnitDelay_p0;              /* '<S102>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_j;        /* '<S100>/UnitDelay' */
  Boolean UnitDelay_f4;              /* '<S106>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_jg;       /* '<S104>/UnitDelay' */
  Boolean UnitDelay_ip;              /* '<S110>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_fm;       /* '<S108>/UnitDelay' */
  Boolean UnitDelay_gl;              /* '<S114>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_bd;       /* '<S112>/UnitDelay' */
  Boolean UnitDelay_jj;              /* '<S118>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_ku;       /* '<S116>/UnitDelay' */
  Boolean UnitDelay_psh;             /* '<S122>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_ai;       /* '<S120>/UnitDelay' */
  Boolean UnitDelay_ko;              /* '<S126>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_d;        /* '<S124>/UnitDelay' */
  Boolean UnitDelay_ll;              /* '<S130>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_px;       /* '<S128>/UnitDelay' */
  Boolean UnitDelay_fn;              /* '<S134>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_b3;       /* '<S132>/UnitDelay' */
  Boolean UnitDelay_d;               /* '<S138>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_l;        /* '<S136>/UnitDelay' */
  Boolean UnitDelay_iy;              /* '<S142>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_l1;       /* '<S140>/UnitDelay' */
  Boolean UnitDelay_lv;              /* '<S146>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_ap;       /* '<S144>/UnitDelay' */
  Boolean UnitDelay_h1;              /* '<S150>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_dx;       /* '<S148>/UnitDelay' */
  Boolean UnitDelay_h3;              /* '<S154>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_gx;       /* '<S152>/UnitDelay' */
  Boolean UnitDelay_ea;              /* '<S158>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_m;        /* '<S156>/UnitDelay' */
  Boolean UnitDelay_hs;              /* '<S162>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_e;        /* '<S160>/UnitDelay' */
  Boolean UnitDelay_he;              /* '<S166>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_n;        /* '<S164>/UnitDelay' */
  Boolean UnitDelay_g5;              /* '<S170>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_c0;       /* '<S168>/UnitDelay' */
  Boolean UnitDelay_hz;              /* '<S174>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_ef;       /* '<S172>/UnitDelay' */
  Boolean UnitDelay_i2k;             /* '<S178>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_i;        /* '<S176>/UnitDelay' */
  Boolean UnitDelay_eo;              /* '<S182>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_c0p;      /* '<S180>/UnitDelay' */
  Boolean UnitDelay_al;              /* '<S186>/UnitDelay1' */
  Boolean UnitDelay_DSTATE_me;       /* '<S184>/UnitDelay' */
} rtDW_mr_AFA_F02_inputs_filters;

#endif                                 /*AFA_F02_inputs_filters_MDLREF_HIDE_CHILD_*/

#ifndef AFA_F02_inputs_filters_MDLREF_HIDE_CHILD_

typedef struct {
  rtDW_mr_AFA_F02_inputs_filters rtdw;
} rtMdlrefDWork_mr_AFA_F02_inputs;

#endif                                 /*AFA_F02_inputs_filters_MDLREF_HIDE_CHILD_*/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F02_inputs_filters(const UInt16 *rtu_InM_pDsThrPred2, const
  UInt16 *rtu_InM_rAirPres7, const UInt16 *rtu_InM_arEffAdpThr7, const
  UInt16 *rtu_InM_arEffAdpEGRVlv8, const UInt16 *rtu_InM_arEffEGRV4, const
  UInt16 *rtu_InM_mfEGREstimE1, const UInt16 *rtu_InM_mfAirThrEstim7, const
  UInt16 rtu_InjrM_prm_facGain78[4], const UInt16 *rtu_EngM_rAirLd1, const
  UInt16 *rtu_ThrLrn_rOpSI1, const UInt16 *rtu_InM_pDsThrC5, const SInt16
  *rtu_InM_pDsThrEstim4, const UInt16 *rtu_ExM_pExMnfEstim_fac1, const
  UInt16 *rtu_EngM_facSlopEfc1, const UInt16 *rtu_ExM_tExMnfEsti2, const
  UInt16 *rtu_Ext_nEng10, const UInt16 *rtu_InThM_tAirUsInVlvE45, const
  SInt16 *rtu_EngM_agCkClsExVlv1, const SInt16 *rtu_EngM_agCkOpInVlvEs1, const
  UInt16 *rtu_EngM_rTotLdExCor5, const UInt16 *rtu_EngM_agCkClsInVlvEs1,
  const UInt16 *rtu_UsThrM_pAirExt22, const UInt32 *rtu_InjSys_mFuReq5,
  const UInt16 rtu_InjrM_prm_facCorGainLnr1[4], const SInt16 *rtu_Ext_tCoMe45,
  const UInt16 *rtu_InM_pDsThrPred_facVlv7, const UInt32
  *rtu_InM_pDsThrEstim7, const UInt16 *rtu_UsThrM_pUsThrCor7, const UInt16
  rtu_InjrM_prm_pDifInjr5[4], const UInt16 *rtu_InThM_nEngCor, const UInt16 *
  rtu_AfuA_rEthStoich, const UInt8 *rtu_Ext_facRhoFu, UInt16
  *rty_AFA_pDsThrPre9, UInt16 *rty_AFA_rAirPre9, UInt16 *rty_AFA_arEffAdpT9,
  UInt16 *rty_AFA_arEffAdpEGR9, UInt16 *rty_AFA_arEffEGRV9, UInt16
  *rty_AFA_rInMassFlo9, UInt32 rty_AFA_prm_facGainInjFil_PIM1[4], UInt16
  *rty_AFA_rAirLdC9, UInt16 *rty_AFA_rOpSIFil8, UInt16 *rty_AFA_pDsThrCo9,
  SInt16 *rty_ErrFil, UInt16 *rty_AFA_pExMnfEstimFil7, UInt32
  *rty_AFA_facSlopEfc8, UInt16 *rty_AFA_tExMnfEst89, UInt16
  *rty_AFA_nEngFil21, UInt32 *rty_AFA_tAirUsInVlvE45, SInt16
  *rty_AFA_agCkClsExVlvEstim1, SInt16 *rty_AFA_agCkOpInVlv8, UInt16
  *rty_AFA_rTotLdEx5, UInt16 *rty_AFA_agCkClsInVlvEstimRe8, UInt16
  *rty_AFA_pAirExtE10, UInt32 *rty_AFA_mFuReqFil23, UInt16
  rty_AFA_prm_facCorG[4], SInt16 *rty_AFA_tCoMes8, UInt16
  *rty_AFA_pDsThrPred_facVlv4, UInt16 *rty_AFA_pDsThrEsti9, UInt16
  *rty_AFA_pUsThrCorFil4, UInt32 rty_AFA_prm_pDifInjrFil_PIM1[4], UInt16
  *rty_AFA_nEngCorFil, UInt16 *rty_AFA_rEthStoichFil1, UInt8
  *rty_AFA_facRhoFuFil1);

/* Model reference registration function */
extern void mr_AFA_F02_inputs_fi_initialize(void);

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

#ifndef AFA_F02_inputs_filters_MDLREF_HIDE_CHILD_

extern rtMdlrefDWork_mr_AFA_F02_inputs mr_AFA_F02_inputs_f_MdlrefDWork;

#endif                                 /*AFA_F02_inputs_filters_MDLREF_HIDE_CHILD_*/


#define AFAT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

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
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S189>/Force any float to Double everything else to uint8' : Unused code path elimination
 * Block '<S189>/Force any float to Single everything else to uint8' : Unused code path elimination
 * Block '<S1>/Switch' : Eliminated due to constant selection input
 * Block '<S2>/Switch' : Eliminated due to constant selection input
 * Block '<S3>/Switch' : Eliminated due to constant selection input
 * Block '<S4>/Switch' : Eliminated due to constant selection input
 * Block '<S5>/Switch' : Eliminated due to constant selection input
 * Block '<S6>/Switch' : Eliminated due to constant selection input
 * Block '<S7>/Switch' : Eliminated due to constant selection input
 * Block '<S8>/Switch' : Eliminated due to constant selection input
 * Block '<S9>/Switch' : Eliminated due to constant selection input
 * Block '<S10>/Switch' : Eliminated due to constant selection input
 * Block '<S11>/Switch' : Eliminated due to constant selection input
 * Block '<S12>/Switch' : Eliminated due to constant selection input
 * Block '<S13>/Switch' : Eliminated due to constant selection input
 * Block '<S14>/Switch' : Eliminated due to constant selection input
 * Block '<S15>/Switch' : Eliminated due to constant selection input
 * Block '<S16>/Switch' : Eliminated due to constant selection input
 * Block '<S17>/Switch' : Eliminated due to constant selection input
 * Block '<S18>/Switch' : Eliminated due to constant selection input
 * Block '<S19>/Switch' : Eliminated due to constant selection input
 * Block '<S20>/Switch' : Eliminated due to constant selection input
 * Block '<S21>/Switch' : Eliminated due to constant selection input
 * Block '<S22>/Switch' : Eliminated due to constant selection input
 * Block '<S23>/Switch' : Eliminated due to constant selection input
 * Block '<S24>/Switch' : Eliminated due to constant selection input
 * Block '<S25>/Switch' : Eliminated due to constant selection input
 * Block '<S26>/Switch' : Eliminated due to constant selection input
 * Block '<S27>/Switch' : Eliminated due to constant selection input
 * Block '<S28>/Switch' : Eliminated due to constant selection input
 * Block '<S29>/Switch' : Eliminated due to constant selection input
 * Block '<S30>/Switch' : Eliminated due to constant selection input
 * Block '<S31>/Switch' : Eliminated due to constant selection input
 * Block '<S188>/FixPt Gateway Out' : Eliminate redundant data type conversion
 * Block '<S33>/Switch' : Eliminated due to constant selection input
 * Block '<S34>/Switch' : Eliminated due to constant selection input
 * Block '<S35>/Switch' : Eliminated due to constant selection input
 * Block '<S36>/Switch' : Eliminated due to constant selection input
 * Block '<S37>/Switch' : Eliminated due to constant selection input
 * Block '<S38>/Switch' : Eliminated due to constant selection input
 * Block '<S39>/Switch' : Eliminated due to constant selection input
 * Block '<S40>/Switch' : Eliminated due to constant selection input
 * Block '<S41>/Switch' : Eliminated due to constant selection input
 * Block '<S42>/Switch' : Eliminated due to constant selection input
 * Block '<S43>/Switch' : Eliminated due to constant selection input
 * Block '<S44>/Switch' : Eliminated due to constant selection input
 * Block '<S45>/Switch' : Eliminated due to constant selection input
 * Block '<S46>/Switch' : Eliminated due to constant selection input
 * Block '<S47>/Switch' : Eliminated due to constant selection input
 * Block '<S48>/Switch' : Eliminated due to constant selection input
 * Block '<S49>/Switch' : Eliminated due to constant selection input
 * Block '<S50>/Switch' : Eliminated due to constant selection input
 * Block '<S51>/Switch' : Eliminated due to constant selection input
 * Block '<S52>/Switch' : Eliminated due to constant selection input
 * Block '<S53>/Switch' : Eliminated due to constant selection input
 * Block '<S54>/Switch' : Eliminated due to constant selection input
 * Block '<S55>/Switch' : Eliminated due to constant selection input
 * Block '<S56>/Switch' : Eliminated due to constant selection input
 * Block '<S57>/Switch' : Eliminated due to constant selection input
 * Block '<S58>/Switch' : Eliminated due to constant selection input
 * Block '<S59>/Switch' : Eliminated due to constant selection input
 * Block '<S60>/Switch' : Eliminated due to constant selection input
 * Block '<S61>/Switch' : Eliminated due to constant selection input
 * Block '<S62>/Switch' : Eliminated due to constant selection input
 * Block '<S63>/Switch' : Eliminated due to constant selection input
 * Block '<S65>/Data Type Conversion' : Unused code path elimination
 * Block '<S69>/Data Type Conversion' : Unused code path elimination
 * Block '<S73>/Data Type Conversion' : Unused code path elimination
 * Block '<S77>/Data Type Conversion' : Unused code path elimination
 * Block '<S81>/Data Type Conversion' : Unused code path elimination
 * Block '<S85>/Data Type Conversion' : Unused code path elimination
 * Block '<S89>/Data Type Conversion' : Unused code path elimination
 * Block '<S93>/Data Type Conversion' : Unused code path elimination
 * Block '<S97>/Data Type Conversion' : Unused code path elimination
 * Block '<S101>/Data Type Conversion' : Unused code path elimination
 * Block '<S105>/Data Type Conversion' : Unused code path elimination
 * Block '<S109>/Data Type Conversion' : Unused code path elimination
 * Block '<S113>/Data Type Conversion' : Unused code path elimination
 * Block '<S117>/Data Type Conversion' : Unused code path elimination
 * Block '<S121>/Data Type Conversion' : Unused code path elimination
 * Block '<S125>/Data Type Conversion' : Unused code path elimination
 * Block '<S129>/Data Type Conversion' : Unused code path elimination
 * Block '<S133>/Data Type Conversion' : Unused code path elimination
 * Block '<S137>/Data Type Conversion' : Unused code path elimination
 * Block '<S141>/Data Type Conversion' : Unused code path elimination
 * Block '<S145>/Data Type Conversion' : Unused code path elimination
 * Block '<S149>/Data Type Conversion' : Unused code path elimination
 * Block '<S153>/Data Type Conversion' : Unused code path elimination
 * Block '<S157>/Data Type Conversion' : Unused code path elimination
 * Block '<S161>/Data Type Conversion' : Unused code path elimination
 * Block '<S165>/Data Type Conversion' : Unused code path elimination
 * Block '<S169>/Data Type Conversion' : Unused code path elimination
 * Block '<S173>/Data Type Conversion' : Unused code path elimination
 * Block '<S177>/Data Type Conversion' : Unused code path elimination
 * Block '<S181>/Data Type Conversion' : Unused code path elimination
 * Block '<S185>/Data Type Conversion' : Unused code path elimination
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
 * Block '<S37>/Add2' : Unused code path elimination
 * Block '<S37>/Constant' : Unused code path elimination
 * Block '<S37>/offset1' : Unused code path elimination
 * Block '<S38>/Add3' : Unused code path elimination
 * Block '<S38>/Add4' : Unused code path elimination
 * Block '<S38>/Constant' : Unused code path elimination
 * Block '<S38>/Relational Operator' : Unused code path elimination
 * Block '<S38>/Switch1' : Unused code path elimination
 * Block '<S38>/offset2' : Unused code path elimination
 * Block '<S38>/offset3' : Unused code path elimination
 * Block '<S38>/offset4' : Unused code path elimination
 * Block '<S39>/Add3' : Unused code path elimination
 * Block '<S39>/Add4' : Unused code path elimination
 * Block '<S39>/Constant' : Unused code path elimination
 * Block '<S39>/Relational Operator' : Unused code path elimination
 * Block '<S39>/Switch1' : Unused code path elimination
 * Block '<S39>/offset2' : Unused code path elimination
 * Block '<S39>/offset3' : Unused code path elimination
 * Block '<S39>/offset4' : Unused code path elimination
 * Block '<S40>/Add3' : Unused code path elimination
 * Block '<S40>/Add4' : Unused code path elimination
 * Block '<S40>/Constant' : Unused code path elimination
 * Block '<S40>/Relational Operator' : Unused code path elimination
 * Block '<S40>/Switch1' : Unused code path elimination
 * Block '<S40>/offset2' : Unused code path elimination
 * Block '<S40>/offset3' : Unused code path elimination
 * Block '<S40>/offset4' : Unused code path elimination
 * Block '<S41>/Add3' : Unused code path elimination
 * Block '<S41>/Add4' : Unused code path elimination
 * Block '<S41>/Constant' : Unused code path elimination
 * Block '<S41>/Relational Operator' : Unused code path elimination
 * Block '<S41>/Switch1' : Unused code path elimination
 * Block '<S41>/offset2' : Unused code path elimination
 * Block '<S41>/offset3' : Unused code path elimination
 * Block '<S41>/offset4' : Unused code path elimination
 * Block '<S42>/Add3' : Unused code path elimination
 * Block '<S42>/Add4' : Unused code path elimination
 * Block '<S42>/Constant' : Unused code path elimination
 * Block '<S42>/Relational Operator' : Unused code path elimination
 * Block '<S42>/Switch1' : Unused code path elimination
 * Block '<S42>/offset2' : Unused code path elimination
 * Block '<S42>/offset3' : Unused code path elimination
 * Block '<S42>/offset4' : Unused code path elimination
 * Block '<S43>/Add3' : Unused code path elimination
 * Block '<S43>/Add4' : Unused code path elimination
 * Block '<S43>/Constant' : Unused code path elimination
 * Block '<S43>/Relational Operator' : Unused code path elimination
 * Block '<S43>/Switch1' : Unused code path elimination
 * Block '<S43>/offset2' : Unused code path elimination
 * Block '<S43>/offset3' : Unused code path elimination
 * Block '<S43>/offset4' : Unused code path elimination
 * Block '<S44>/Add3' : Unused code path elimination
 * Block '<S44>/Add4' : Unused code path elimination
 * Block '<S44>/Constant' : Unused code path elimination
 * Block '<S44>/Relational Operator' : Unused code path elimination
 * Block '<S44>/Switch1' : Unused code path elimination
 * Block '<S44>/offset2' : Unused code path elimination
 * Block '<S44>/offset3' : Unused code path elimination
 * Block '<S44>/offset4' : Unused code path elimination
 * Block '<S45>/Add3' : Unused code path elimination
 * Block '<S45>/Add4' : Unused code path elimination
 * Block '<S45>/Constant' : Unused code path elimination
 * Block '<S45>/Relational Operator' : Unused code path elimination
 * Block '<S45>/Switch1' : Unused code path elimination
 * Block '<S45>/offset2' : Unused code path elimination
 * Block '<S45>/offset3' : Unused code path elimination
 * Block '<S45>/offset4' : Unused code path elimination
 * Block '<S46>/Add3' : Unused code path elimination
 * Block '<S46>/Add4' : Unused code path elimination
 * Block '<S46>/Constant' : Unused code path elimination
 * Block '<S46>/Relational Operator' : Unused code path elimination
 * Block '<S46>/Switch1' : Unused code path elimination
 * Block '<S46>/offset2' : Unused code path elimination
 * Block '<S46>/offset3' : Unused code path elimination
 * Block '<S46>/offset4' : Unused code path elimination
 * Block '<S47>/Add3' : Unused code path elimination
 * Block '<S47>/Add4' : Unused code path elimination
 * Block '<S47>/Constant' : Unused code path elimination
 * Block '<S47>/Relational Operator' : Unused code path elimination
 * Block '<S47>/Switch1' : Unused code path elimination
 * Block '<S47>/offset2' : Unused code path elimination
 * Block '<S47>/offset3' : Unused code path elimination
 * Block '<S47>/offset4' : Unused code path elimination
 * Block '<S48>/Add2' : Unused code path elimination
 * Block '<S48>/Constant' : Unused code path elimination
 * Block '<S48>/offset1' : Unused code path elimination
 * Block '<S49>/Add2' : Unused code path elimination
 * Block '<S49>/Constant' : Unused code path elimination
 * Block '<S49>/offset1' : Unused code path elimination
 * Block '<S50>/Add3' : Unused code path elimination
 * Block '<S50>/Add4' : Unused code path elimination
 * Block '<S50>/Constant' : Unused code path elimination
 * Block '<S50>/Relational Operator' : Unused code path elimination
 * Block '<S50>/Switch1' : Unused code path elimination
 * Block '<S50>/offset2' : Unused code path elimination
 * Block '<S50>/offset3' : Unused code path elimination
 * Block '<S50>/offset4' : Unused code path elimination
 * Block '<S51>/Add3' : Unused code path elimination
 * Block '<S51>/Add4' : Unused code path elimination
 * Block '<S51>/Constant' : Unused code path elimination
 * Block '<S51>/Relational Operator' : Unused code path elimination
 * Block '<S51>/Switch1' : Unused code path elimination
 * Block '<S51>/offset2' : Unused code path elimination
 * Block '<S51>/offset3' : Unused code path elimination
 * Block '<S51>/offset4' : Unused code path elimination
 * Block '<S52>/Add3' : Unused code path elimination
 * Block '<S52>/Add4' : Unused code path elimination
 * Block '<S52>/Constant' : Unused code path elimination
 * Block '<S52>/Relational Operator' : Unused code path elimination
 * Block '<S52>/Switch1' : Unused code path elimination
 * Block '<S52>/offset2' : Unused code path elimination
 * Block '<S52>/offset3' : Unused code path elimination
 * Block '<S52>/offset4' : Unused code path elimination
 * Block '<S53>/Add3' : Unused code path elimination
 * Block '<S53>/Add4' : Unused code path elimination
 * Block '<S53>/Constant' : Unused code path elimination
 * Block '<S53>/Relational Operator' : Unused code path elimination
 * Block '<S53>/Switch1' : Unused code path elimination
 * Block '<S53>/offset2' : Unused code path elimination
 * Block '<S53>/offset3' : Unused code path elimination
 * Block '<S53>/offset4' : Unused code path elimination
 * Block '<S54>/Add3' : Unused code path elimination
 * Block '<S54>/Add4' : Unused code path elimination
 * Block '<S54>/Constant' : Unused code path elimination
 * Block '<S54>/Relational Operator' : Unused code path elimination
 * Block '<S54>/Switch1' : Unused code path elimination
 * Block '<S54>/offset2' : Unused code path elimination
 * Block '<S54>/offset3' : Unused code path elimination
 * Block '<S54>/offset4' : Unused code path elimination
 * Block '<S55>/Add3' : Unused code path elimination
 * Block '<S55>/Add4' : Unused code path elimination
 * Block '<S55>/Constant' : Unused code path elimination
 * Block '<S55>/Relational Operator' : Unused code path elimination
 * Block '<S55>/Switch1' : Unused code path elimination
 * Block '<S55>/offset2' : Unused code path elimination
 * Block '<S55>/offset3' : Unused code path elimination
 * Block '<S55>/offset4' : Unused code path elimination
 * Block '<S56>/Add3' : Unused code path elimination
 * Block '<S56>/Add4' : Unused code path elimination
 * Block '<S56>/Constant' : Unused code path elimination
 * Block '<S56>/Relational Operator' : Unused code path elimination
 * Block '<S56>/Switch1' : Unused code path elimination
 * Block '<S56>/offset2' : Unused code path elimination
 * Block '<S56>/offset3' : Unused code path elimination
 * Block '<S56>/offset4' : Unused code path elimination
 * Block '<S57>/Add3' : Unused code path elimination
 * Block '<S57>/Add4' : Unused code path elimination
 * Block '<S57>/Constant' : Unused code path elimination
 * Block '<S57>/Relational Operator' : Unused code path elimination
 * Block '<S57>/Switch1' : Unused code path elimination
 * Block '<S57>/offset2' : Unused code path elimination
 * Block '<S57>/offset3' : Unused code path elimination
 * Block '<S57>/offset4' : Unused code path elimination
 * Block '<S58>/Add3' : Unused code path elimination
 * Block '<S58>/Add4' : Unused code path elimination
 * Block '<S58>/Constant' : Unused code path elimination
 * Block '<S58>/Relational Operator' : Unused code path elimination
 * Block '<S58>/Switch1' : Unused code path elimination
 * Block '<S58>/offset2' : Unused code path elimination
 * Block '<S58>/offset3' : Unused code path elimination
 * Block '<S58>/offset4' : Unused code path elimination
 * Block '<S59>/Add3' : Unused code path elimination
 * Block '<S59>/Add4' : Unused code path elimination
 * Block '<S59>/Constant' : Unused code path elimination
 * Block '<S59>/Relational Operator' : Unused code path elimination
 * Block '<S59>/Switch1' : Unused code path elimination
 * Block '<S59>/offset2' : Unused code path elimination
 * Block '<S59>/offset3' : Unused code path elimination
 * Block '<S59>/offset4' : Unused code path elimination
 * Block '<S60>/Add3' : Unused code path elimination
 * Block '<S60>/Add4' : Unused code path elimination
 * Block '<S60>/Constant' : Unused code path elimination
 * Block '<S60>/Relational Operator' : Unused code path elimination
 * Block '<S60>/Switch1' : Unused code path elimination
 * Block '<S60>/offset2' : Unused code path elimination
 * Block '<S60>/offset3' : Unused code path elimination
 * Block '<S60>/offset4' : Unused code path elimination
 * Block '<S61>/Add3' : Unused code path elimination
 * Block '<S61>/Add4' : Unused code path elimination
 * Block '<S61>/Constant' : Unused code path elimination
 * Block '<S61>/Relational Operator' : Unused code path elimination
 * Block '<S61>/Switch1' : Unused code path elimination
 * Block '<S61>/offset2' : Unused code path elimination
 * Block '<S61>/offset3' : Unused code path elimination
 * Block '<S61>/offset4' : Unused code path elimination
 * Block '<S62>/Add3' : Unused code path elimination
 * Block '<S62>/Add4' : Unused code path elimination
 * Block '<S62>/Constant' : Unused code path elimination
 * Block '<S62>/Relational Operator' : Unused code path elimination
 * Block '<S62>/Switch1' : Unused code path elimination
 * Block '<S62>/offset2' : Unused code path elimination
 * Block '<S62>/offset3' : Unused code path elimination
 * Block '<S62>/offset4' : Unused code path elimination
 * Block '<S63>/Add2' : Unused code path elimination
 * Block '<S63>/Constant' : Unused code path elimination
 * Block '<S63>/offset1' : Unused code path elimination
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
 * '<Root>' : AFA_F02_inputs_filters
 * '<S1>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA
 * '<S2>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA1
 * '<S3>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA10
 * '<S4>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA11
 * '<S5>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA12
 * '<S6>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA13
 * '<S7>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA14
 * '<S8>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA15
 * '<S9>'   : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA16
 * '<S10>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA17
 * '<S11>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA18
 * '<S12>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA19
 * '<S13>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA2
 * '<S14>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA20
 * '<S15>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA21
 * '<S16>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA22
 * '<S17>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA23
 * '<S18>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA24
 * '<S19>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA25
 * '<S20>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA26
 * '<S21>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA27
 * '<S22>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA28
 * '<S23>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA29
 * '<S24>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA3
 * '<S25>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA30
 * '<S26>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA4
 * '<S27>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA5
 * '<S28>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA6
 * '<S29>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA7
 * '<S30>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA8
 * '<S31>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA9
 * '<S32>'  : AFA_F02_inputs_filters/Secured fixpoint division
 * '<S33>'  : AFA_F02_inputs_filters/SingleToFixdt
 * '<S34>'  : AFA_F02_inputs_filters/SingleToFixdt1
 * '<S35>'  : AFA_F02_inputs_filters/SingleToFixdt10
 * '<S36>'  : AFA_F02_inputs_filters/SingleToFixdt11
 * '<S37>'  : AFA_F02_inputs_filters/SingleToFixdt12
 * '<S38>'  : AFA_F02_inputs_filters/SingleToFixdt13
 * '<S39>'  : AFA_F02_inputs_filters/SingleToFixdt14
 * '<S40>'  : AFA_F02_inputs_filters/SingleToFixdt15
 * '<S41>'  : AFA_F02_inputs_filters/SingleToFixdt16
 * '<S42>'  : AFA_F02_inputs_filters/SingleToFixdt17
 * '<S43>'  : AFA_F02_inputs_filters/SingleToFixdt18
 * '<S44>'  : AFA_F02_inputs_filters/SingleToFixdt19
 * '<S45>'  : AFA_F02_inputs_filters/SingleToFixdt2
 * '<S46>'  : AFA_F02_inputs_filters/SingleToFixdt20
 * '<S47>'  : AFA_F02_inputs_filters/SingleToFixdt21
 * '<S48>'  : AFA_F02_inputs_filters/SingleToFixdt22
 * '<S49>'  : AFA_F02_inputs_filters/SingleToFixdt23
 * '<S50>'  : AFA_F02_inputs_filters/SingleToFixdt24
 * '<S51>'  : AFA_F02_inputs_filters/SingleToFixdt25
 * '<S52>'  : AFA_F02_inputs_filters/SingleToFixdt26
 * '<S53>'  : AFA_F02_inputs_filters/SingleToFixdt27
 * '<S54>'  : AFA_F02_inputs_filters/SingleToFixdt28
 * '<S55>'  : AFA_F02_inputs_filters/SingleToFixdt29
 * '<S56>'  : AFA_F02_inputs_filters/SingleToFixdt3
 * '<S57>'  : AFA_F02_inputs_filters/SingleToFixdt30
 * '<S58>'  : AFA_F02_inputs_filters/SingleToFixdt4
 * '<S59>'  : AFA_F02_inputs_filters/SingleToFixdt5
 * '<S60>'  : AFA_F02_inputs_filters/SingleToFixdt6
 * '<S61>'  : AFA_F02_inputs_filters/SingleToFixdt7
 * '<S62>'  : AFA_F02_inputs_filters/SingleToFixdt8
 * '<S63>'  : AFA_F02_inputs_filters/SingleToFixdt9
 * '<S64>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA/IniCdn
 * '<S65>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA/Reset du filtre
 * '<S66>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA/UnitDly_ExtIni
 * '<S67>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA/filtrage
 * '<S68>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA1/IniCdn
 * '<S69>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA1/Reset du filtre
 * '<S70>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA1/UnitDly_ExtIni
 * '<S71>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA1/filtrage
 * '<S72>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA10/IniCdn
 * '<S73>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA10/Reset du filtre
 * '<S74>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA10/UnitDly_ExtIni
 * '<S75>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA10/filtrage
 * '<S76>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA11/IniCdn
 * '<S77>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA11/Reset du filtre
 * '<S78>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA11/UnitDly_ExtIni
 * '<S79>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA11/filtrage
 * '<S80>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA12/IniCdn
 * '<S81>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA12/Reset du filtre
 * '<S82>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA12/UnitDly_ExtIni
 * '<S83>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA12/filtrage
 * '<S84>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA13/IniCdn
 * '<S85>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA13/Reset du filtre
 * '<S86>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA13/UnitDly_ExtIni
 * '<S87>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA13/filtrage
 * '<S88>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA14/IniCdn
 * '<S89>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA14/Reset du filtre
 * '<S90>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA14/UnitDly_ExtIni
 * '<S91>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA14/filtrage
 * '<S92>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA15/IniCdn
 * '<S93>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA15/Reset du filtre
 * '<S94>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA15/UnitDly_ExtIni
 * '<S95>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA15/filtrage
 * '<S96>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA16/IniCdn
 * '<S97>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA16/Reset du filtre
 * '<S98>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA16/UnitDly_ExtIni
 * '<S99>'  : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA16/filtrage
 * '<S100>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA17/IniCdn
 * '<S101>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA17/Reset du filtre
 * '<S102>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA17/UnitDly_ExtIni
 * '<S103>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA17/filtrage
 * '<S104>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA18/IniCdn
 * '<S105>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA18/Reset du filtre
 * '<S106>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA18/UnitDly_ExtIni
 * '<S107>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA18/filtrage
 * '<S108>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA19/IniCdn
 * '<S109>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA19/Reset du filtre
 * '<S110>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA19/UnitDly_ExtIni
 * '<S111>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA19/filtrage
 * '<S112>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA2/IniCdn
 * '<S113>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA2/Reset du filtre
 * '<S114>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA2/UnitDly_ExtIni
 * '<S115>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA2/filtrage
 * '<S116>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA20/IniCdn
 * '<S117>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA20/Reset du filtre
 * '<S118>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA20/UnitDly_ExtIni
 * '<S119>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA20/filtrage
 * '<S120>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA21/IniCdn
 * '<S121>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA21/Reset du filtre
 * '<S122>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA21/UnitDly_ExtIni
 * '<S123>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA21/filtrage
 * '<S124>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA22/IniCdn
 * '<S125>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA22/Reset du filtre
 * '<S126>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA22/UnitDly_ExtIni
 * '<S127>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA22/filtrage
 * '<S128>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA23/IniCdn
 * '<S129>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA23/Reset du filtre
 * '<S130>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA23/UnitDly_ExtIni
 * '<S131>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA23/filtrage
 * '<S132>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA24/IniCdn
 * '<S133>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA24/Reset du filtre
 * '<S134>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA24/UnitDly_ExtIni
 * '<S135>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA24/filtrage
 * '<S136>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA25/IniCdn
 * '<S137>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA25/Reset du filtre
 * '<S138>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA25/UnitDly_ExtIni
 * '<S139>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA25/filtrage
 * '<S140>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA26/IniCdn
 * '<S141>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA26/Reset du filtre
 * '<S142>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA26/UnitDly_ExtIni
 * '<S143>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA26/filtrage
 * '<S144>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA27/IniCdn
 * '<S145>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA27/Reset du filtre
 * '<S146>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA27/UnitDly_ExtIni
 * '<S147>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA27/filtrage
 * '<S148>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA28/IniCdn
 * '<S149>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA28/Reset du filtre
 * '<S150>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA28/UnitDly_ExtIni
 * '<S151>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA28/filtrage
 * '<S152>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA29/IniCdn
 * '<S153>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA29/Reset du filtre
 * '<S154>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA29/UnitDly_ExtIni
 * '<S155>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA29/filtrage
 * '<S156>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA3/IniCdn
 * '<S157>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA3/Reset du filtre
 * '<S158>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA3/UnitDly_ExtIni
 * '<S159>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA3/filtrage
 * '<S160>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA30/IniCdn
 * '<S161>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA30/Reset du filtre
 * '<S162>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA30/UnitDly_ExtIni
 * '<S163>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA30/filtrage
 * '<S164>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA4/IniCdn
 * '<S165>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA4/Reset du filtre
 * '<S166>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA4/UnitDly_ExtIni
 * '<S167>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA4/filtrage
 * '<S168>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA5/IniCdn
 * '<S169>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA5/Reset du filtre
 * '<S170>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA5/UnitDly_ExtIni
 * '<S171>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA5/filtrage
 * '<S172>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA6/IniCdn
 * '<S173>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA6/Reset du filtre
 * '<S174>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA6/UnitDly_ExtIni
 * '<S175>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA6/filtrage
 * '<S176>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA7/IniCdn
 * '<S177>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA7/Reset du filtre
 * '<S178>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA7/UnitDly_ExtIni
 * '<S179>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA7/filtrage
 * '<S180>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA8/IniCdn
 * '<S181>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA8/Reset du filtre
 * '<S182>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA8/UnitDly_ExtIni
 * '<S183>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA8/filtrage
 * '<S184>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA9/IniCdn
 * '<S185>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA9/Reset du filtre
 * '<S186>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA9/UnitDly_ExtIni
 * '<S187>' : AFA_F02_inputs_filters/Filtre_1er_ordre_avec_reset_PSA9/filtrage
 * '<S188>' : AFA_F02_inputs_filters/Secured fixpoint division/Data Type Scaling Strip
 * '<S189>' : AFA_F02_inputs_filters/Secured fixpoint division/Data Type Police No Floating Point1
 * '<S190>' : AFA_F02_inputs_filters/Secured fixpoint division/If Action Subsystem2
 * '<S191>' : AFA_F02_inputs_filters/Secured fixpoint division/If Action Subsystem3
 */

/*-
 * Requirements for '<Root>': AFA_F02_inputs_filters
 */
#endif                                 /* RTW_HEADER_AFA_F02_inputs_filters_h_ */

/*-------------------------------- end of file -------------------------------*/
