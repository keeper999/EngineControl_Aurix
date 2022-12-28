/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMinT                                                 */
/* !Description     : AdvMinT Software Component                              */
/*                                                                            */
/* !Module          : AdvMinT                                                 */
/* !Description     : AdvMinT Software Component                              */
/*                                                                            */
/* !File            : AdvMinT.c                                               */
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
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Mon Oct 22 14:52:26 2012                              */
/*   Model name       : AdvMinT_AUTOSAR.mdl                                   */
/*   Model version    : 1.821                                                 */
/*   Root subsystem   : /AdvMinT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M02-AdvMinT/5-S$*/
/* $Revision::   1.13                                                        $*/
/* $Author::   adelvare                               $$Date::   01 Feb 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvMinT.h"
#include "AdvMinT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S18>/F01_State_avmin' */
#define IN_AGREMENT                    (1U)
#define IN_DEPART                      (2U)
#define IN_MINI_COMB                   (3U)
#define IN_PROT_COMP                   (4U)
#define IN_SORTIE_DEPART               (5U)
#define IN_TRANSITION_AGR_mini_comb    (6U)
#define IN_TRANSITION_Prot_Comp_mini_co (7U)
#define IN_TRANSITION_mini_comb_prot_Co (8U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AdvMinT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMinT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AdvMinT AdvMinT_B;

/* Block states (auto storage) */
D_Work_AdvMinT AdvMinT_DWork;

#define AdvMinT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMinT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AdvMinT_START_SEC_CODE
#include "AdvMinT_MemMap.h"

void AdvMinT_ASYNC1(int controlPortIdx)
{
}

void AdvMinT_ASYNC2(int controlPortIdx)
{
}

void AdvMinT_ASYNC3(int controlPortIdx)
{
}

void AdvMinT_ASYNC4(int controlPortIdx)
{
}

/* Start for exported function: RE_AdvMinT_005_MSE */
void RE_AdvMinT_005_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Init'
   *
   * Block requirements for '<S1>/F01_Init':
   *  1. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_014.01 ;
   *  2. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_063.03 ;
   *  3. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_064.03 ;
   *  4. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_076.01 ;
   *  5. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_075.01 ;
   *  6. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_065.03 ;
   *  7. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_066.03 ;
   *  8. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_071.02 ;
   *  9. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_078.01 ;
   *  10. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_012.02 ;
   *  11. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_013.02 ;
   */
}

/* Output and update for exported function: RE_AdvMinT_005_MSE */
void RE_AdvMinT_005_MSE(void)
{
  UInt8 localSwitch;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Init'
   *
   * Block requirements for '<S1>/F01_Init':
   *  1. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_014.01 ;
   *  2. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_063.03 ;
   *  3. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_064.03 ;
   *  4. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_076.01 ;
   *  5. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_075.01 ;
   *  6. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_065.03 ;
   *  7. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_066.03 ;
   *  8. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_071.02 ;
   *  9. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_078.01 ;
   *  10. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_012.02 ;
   *  11. SubSystem "F01_Init" !Trace_To : VEMS_R_10_06440_013.02 ;
   */

  /* user code (Output function Body for TID9) */
  RE_AdvMinT_Init();

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S88>/autosar_testpoint1' incorporates:
   *  Constant: '<S8>/Cste_3'
   */

  /* S-Function Block: <S88>/autosar_testpoint1 */
  IgSys_ctLimAdvReact_IRV_MP = ((UInt8)0U);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_ctLimAdvReact_irvInport2' incorporates:
   *  Constant: '<S8>/Cste_3'
   *  SignalConversion: '<S8>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_AdvMinT_005_MSE_IgSys_ctLimAdvReact_irv(0U);

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S8>/Cste_1'
   *  Constant: '<S91>/Byp_Fonction_SC'
   *  Constant: '<S91>/Int_BypC'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch = IgSys_agIgLimMinRef_B;
  } else {
    localSwitch = 96U;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgLimMinRefInport2' */
  Rte_Write_P_IgSys_agIgLimMinRef_IgSys_agIgLimMinRef(localSwitch);

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S8>/Cste_2'
   *  Constant: '<S92>/Byp_Fonction_SC'
   *  Constant: '<S92>/Int_BypC'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch = IgSys_agIgLimMinKnk_B;
  } else {
    localSwitch = 96U;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgLimMinKnkInport2' */
  Rte_Write_P_IgSys_agIgLimMinKnk_IgSys_agIgLimMinKnk(localSwitch);

  /* Switch: '<S94>/Switch' incorporates:
   *  Constant: '<S8>/Cste_5'
   *  Constant: '<S94>/Byp_Fonction_SC'
   *  Constant: '<S94>/Int_BypC'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch = IgSys_agIgMinThermo_B;
  } else {
    localSwitch = 96U;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgMinThermoInport2' */
  Rte_Write_P_IgSys_agIgMinThermo_IgSys_agIgMinThermo(localSwitch);

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S8>/Cste_4'
   *  Constant: '<S93>/Byp_Fonction_SC'
   *  Constant: '<S93>/Int_BypC'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch = IgSys_agIgMinCmb_B;
  } else {
    localSwitch = 96U;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgMinCmbInport2' */
  Rte_Write_P_IgSys_agIgMinCmb_IgSys_agIgMinCmb(localSwitch);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S89>/autosar_testpoint1' incorporates:
   *  Constant: '<S8>/Cste_6'
   */

  /* S-Function Block: <S89>/autosar_testpoint1 */
  IgSys_agIgMinDriv_IRV_MP = 96U;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgMinDriv_irvInport2' incorporates:
   *  Constant: '<S8>/Cste_6'
   *  SignalConversion: '<S8>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_AdvMinT_005_MSE_IgSys_agIgMinDriv_irv(96U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S90>/autosar_testpoint1' incorporates:
   *  Constant: '<S8>/Cste_7'
   */

  /* S-Function Block: <S90>/autosar_testpoint1 */
  IgSys_agIgMinStrt_IRV_MP = 96U;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgMinStrt_irvInport2' incorporates:
   *  Constant: '<S8>/Cste_7'
   *  SignalConversion: '<S8>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_AdvMinT_005_MSE_IgSys_agIgMinStrt_irv(96U);
}

/* Start for exported function: RE_AdvMinT_006_DRE */
void RE_AdvMinT_006_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F03_Calc_bornage_avance_mini'
   *
   * Block requirements for '<S1>/F03_Calc_bornage_avance_mini':
   *  1. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_016.03 ;
   *  2. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_047.01 ;
   *  3. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_048.01 ;
   *  4. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_035.01 ;
   *  5. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_052.01 ;
   *  6. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_053.01 ;
   *  7. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_036.01 ;
   *  8. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_054.01 ;
   *  9. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_055.01 ;
   *  10. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_056.01 ;
   *  11. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_057.01 ;
   *  12. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_058.01 ;
   *  13. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_059.01 ;
   *  14. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_060.01 ;
   *  15. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_061.01 ;
   *  16. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_062.01 ;
   *  17. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_063.03 ;
   *  18. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_064.03 ;
   *  19. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_076.01 ;
   *  20. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_075.01 ;
   *  21. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_066.03 ;
   *  22. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_065.03 ;
   *  23. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_072.03 ;
   *  24. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_078.01 ;
   *  25. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_012.02 ;
   *  26. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_013.02 ;
   */
}

/* Output and update for exported function: RE_AdvMinT_006_DRE */
void RE_AdvMinT_006_DRE(void)
{
  Float32 localSum2_n;
  Float32 localInterpolationUsingPrelooku;
  Float32 localEngM_rAirLdCor_Eng_rAirLd_;
  Float32 localfrac[2];
  Float32 localExt_nEng_Ext_nEng_A_16_f;
  UInt32 localEngM_rAirLdCor_Eng_rAirL_l;
  UInt32 localbpIndex[2];
  UInt32 localExt_nEng_Ext_nEng_A_16_k;
  Float32 localfrac_0[2];
  Float32 localExt_tCoMes_IgSys_tCoMes_A_;
  UInt32 localbpIndex_0[2];
  UInt32 localExt_tCoMes_IgSys_tCoMes__i;
  SInt32 localrtmax;
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Float32 localAdd2_o;
  Float32 localfrac_3[2];
  UInt32 localbpIndex_3[2];
  Float32 localInterpolationUsingPreloo_b;
  Float32 localfrac_4[2];
  UInt32 localbpIndex_4[2];
  Float32 localSwitch1_oi;
  Float32 localfrac_5[2];
  UInt32 localbpIndex_5[2];
  Float32 localfrac_6[2];
  UInt32 localbpIndex_6[2];
  Float32 localSwitch1_i;
  Float32 localAdd2_g;
  Boolean localLowerRelop1_g;
  Float32 localfrac_7[2];
  UInt32 localbpIndex_7[2];
  Float32 localfrac_8[2];
  UInt32 localbpIndex_8[2];
  Float32 localfrac_9[2];
  UInt32 localbpIndex_9[2];
  Float32 localfrac_a[2];
  UInt32 localbpIndex_a[2];
  Float32 localfrac_b[2];
  UInt32 localbpIndex_b[2];
  SInt16 localTmpSignalConversionAtExt_t;
  UInt8 localSwitch_l;
  SInt16 localTmpSignalConversionAtIgSys;
  SInt16 localTmpSignalConversionAtIgS_o;
  UInt8 localTmpSignalConversionAtIgS_k[10];
  UInt8 localTmpSignalConversionAtIg_ka[10];
  SInt16 localTmpSignalConversionAtIgS_n;
  UInt16 localTmpSignalConversionAtFARSp;
  SInt16 localTmpSignalConversionAtIgS_j;
  SInt16 localTmpSignalConversionAtIg_jb;
  SInt16 localTmpSignalConversionAtIgS_g;
  SInt16 localTmpSignalConversionAtExt_a;
  SInt16 localTmpSignalConversionAtExt_b;
  UInt8 locallocalOutDTConv_p;
  UInt8 locallocalOutDTConv_k;
  Float32d localtmp;
  UInt8 locallocalDataTypeConversion;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_Calc_bornage_avance_mini'
   *
   * Block requirements for '<S1>/F03_Calc_bornage_avance_mini':
   *  1. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_016.03 ;
   *  2. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_047.01 ;
   *  3. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_048.01 ;
   *  4. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_035.01 ;
   *  5. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_052.01 ;
   *  6. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_053.01 ;
   *  7. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_036.01 ;
   *  8. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_054.01 ;
   *  9. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_055.01 ;
   *  10. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_056.01 ;
   *  11. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_057.01 ;
   *  12. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_058.01 ;
   *  13. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_059.01 ;
   *  14. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_060.01 ;
   *  15. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_061.01 ;
   *  16. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_062.01 ;
   *  17. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_063.03 ;
   *  18. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_064.03 ;
   *  19. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_076.01 ;
   *  20. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_075.01 ;
   *  21. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_066.03 ;
   *  22. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_065.03 ;
   *  23. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_072.03 ;
   *  24. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_078.01 ;
   *  25. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_012.02 ;
   *  26. SubSystem "F03_Calc_bornage_avance_mini" !Trace_To : VEMS_R_10_06440_013.02 ;
   */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&AdvMinT_B.TmpSignalConversionAtExt_nEngOu);

  /* PreLookup: '<S106>/Prelookup' */
  localExt_nEng_Ext_nEng_A_16_k = plook_u32u16f_binc
    (AdvMinT_B.TmpSignalConversionAtExt_nEngOu, (&(Ext_nEng_A[0])), 15U,
     &localExt_nEng_Ext_nEng_A_16_f);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_agCkOpInVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkOpInVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0
    (&localTmpSignalConversionAtExt_a);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_agCkClsExVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkClsExVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0
    (&localTmpSignalConversionAtExt_b);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor
    (&AdvMinT_B.TmpSignalConversionAtEngM_rAirL);

  /* PreLookup: '<S104>/Prelookup' */
  localEngM_rAirLdCor_Eng_rAirL_l = plook_u32u16f_binc
    (AdvMinT_B.TmpSignalConversionAtEngM_rAirL, (&(Eng_rAirLd_A[0])), 15U,
     &localEngM_rAirLdCor_Eng_rAirLd_);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_tCoStrtMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoStrtMes'
   */
  Rte_Read_R_Ext_tCoStrtMes_Ext_tCoStrtMes
    (&AdvMinT_B.TmpSignalConversionAtExt_tCoStr);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* PreLookup: '<S105>/Prelookup' */
  localExt_tCoMes_IgSys_tCoMes__i = plook_u32s16f_binc
    (localTmpSignalConversionAtExt_t, (&(IgSys_tCoMes_A[0])), 15U,
     &localExt_tCoMes_IgSys_tCoMes_A_);

  /* Outputs for atomic SubSystem: '<S11>/F01_Calcul_av_lim' *
   * Block requirements for '<S11>/F01_Calcul_av_lim':
   *  1. SubSystem "F01_Calcul_av_lim" !Trace_To : VEMS_R_10_06440_017.03 ;
   */

  /* Outputs for atomic SubSystem: '<S99>/F01_calcul_avance_min_demarrage' *
   * Block requirements for '<S99>/F01_calcul_avance_min_demarrage':
   *  1. SubSystem "F01_calcul_avance_min_demarrage" !Trace_To : VEMS_R_10_06440_018.01 ;
   */

  /* Lookup_n-D: '<S117>/Lookup Table (n-D)' */
  localAdd2_o = look2_is16u16lftu8n2If_binlcns
    (AdvMinT_B.TmpSignalConversionAtExt_tCoStr,
     AdvMinT_B.TmpSignalConversionAtExt_nEngOu, (&(IgSys_tCoMes_A[0])),
     (&(IgSys_nEngMinStrt_A[0])), (&(IgSys_agIgMinStrt_M[0])),
     &AdvMinT_ConstP.LookupTablenD_maxInde[0], 16U);

  /* DataTypeConversion: '<S118>/OutDTConv' incorporates:
   *  Constant: '<S118>/offset'
   *  Constant: '<S118>/offset1'
   *  Constant: '<S118>/one_on_slope'
   *  Product: '<S118>/Product4'
   *  Sum: '<S118>/Add1'
   *  Sum: '<S118>/Add2'
   */
  localInterpolationUsingPreloo_b = ((localAdd2_o - -36.0F) * 2.666666746E+000F)
    + 0.5F;
  if (localInterpolationUsingPreloo_b < 256.0F) {
    if (localInterpolationUsingPreloo_b >= 0.0F) {
      locallocalOutDTConv_k = (UInt8)localInterpolationUsingPreloo_b;
    } else {
      locallocalOutDTConv_k = 0U;
    }
  } else {
    locallocalOutDTConv_k = MAX_uint8_T;
  }

  /* end of Outputs for SubSystem: '<S99>/F01_calcul_avance_min_demarrage' */

  /* Outputs for atomic SubSystem: '<S99>/F02_calcul_avance_min' *
   * Block requirements for '<S99>/F02_calcul_avance_min':
   *  1. SubSystem "F02_calcul_avance_min" !Trace_To : VEMS_R_10_06440_019.02 ;
   */

  /* Outputs for atomic SubSystem: '<S116>/F01_calc_AAmin_comb_ref' *
   * Block requirements for '<S116>/F01_calc_AAmin_comb_ref':
   *  1. SubSystem "F01_calc_AAmin_comb_ref" !Trace_To : VEMS_R_10_06440_020.01 ;
   */

  /* Interpolation_n-D: '<S123>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_3[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_3[1] = localAdd2_o;
  localbpIndex_3[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_3[1] = localExt_nEng_Ext_nEng_A_16_k;
  localInterpolationUsingPreloo_b = intrp2d_is16n2ff_u32f_l_ns(localbpIndex_3,
    localfrac_3, (&(IgSys_agIgNotCorMinThdReac_M[0])), 16U);

  /* Product: '<S124>/Product4' incorporates:
   *  Constant: '<S124>/offset'
   *  Constant: '<S124>/one_on_slope'
   *  Sum: '<S124>/Add1'
   */
  localAdd2_o = 2.666666746E+000F * localInterpolationUsingPreloo_b;

  /* Switch: '<S124>/Switch1' incorporates:
   *  Constant: '<S124>/offset2'
   *  Constant: '<S124>/offset3'
   *  Constant: '<S124>/offset4'
   *  RelationalOperator: '<S124>/Relational Operator'
   *  Sum: '<S124>/Add3'
   *  Sum: '<S124>/Add4'
   */
  if (localAdd2_o >= 0.0F) {
    localAdd2_o += 0.5F;
  } else {
    localAdd2_o -= 0.5F;
  }

  /* DataStoreWrite: '<S119>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S124>/OutDTConv'
   */
  if (localAdd2_o < 32768.0F) {
    if (localAdd2_o >= -32768.0F) {
      IgSys_agIgNotCorMinThdReac_MP = (SInt16)localAdd2_o;
    } else {
      IgSys_agIgNotCorMinThdReac_MP = MIN_int16_T;
    }
  } else {
    IgSys_agIgNotCorMinThdReac_MP = MAX_int16_T;
  }

  /* Interpolation_n-D: '<S122>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_4[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_4[1] = localAdd2_o;
  localbpIndex_4[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_4[1] = localExt_nEng_Ext_nEng_A_16_k;
  localAdd2_o = intrp2d_is16n2ff_u32f_l_ns(localbpIndex_4, localfrac_4,
    (&(IgSys_agIgNotCorMinThd_M[0])), 16U);

  /* Product: '<S125>/Product4' incorporates:
   *  Constant: '<S125>/offset'
   *  Constant: '<S125>/one_on_slope'
   *  Sum: '<S125>/Add1'
   */
  localSwitch1_oi = 2.666666746E+000F * localAdd2_o;

  /* Switch: '<S125>/Switch1' incorporates:
   *  Constant: '<S125>/offset2'
   *  Constant: '<S125>/offset3'
   *  Constant: '<S125>/offset4'
   *  RelationalOperator: '<S125>/Relational Operator'
   *  Sum: '<S125>/Add3'
   *  Sum: '<S125>/Add4'
   */
  if (localSwitch1_oi >= 0.0F) {
    localSwitch1_oi += 0.5F;
  } else {
    localSwitch1_oi -= 0.5F;
  }

  /* DataStoreWrite: '<S119>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<S125>/OutDTConv'
   */
  if (localSwitch1_oi < 32768.0F) {
    if (localSwitch1_oi >= -32768.0F) {
      IgSys_agIgNotCorMinThd_MP = (SInt16)localSwitch1_oi;
    } else {
      IgSys_agIgNotCorMinThd_MP = MIN_int16_T;
    }
  } else {
    IgSys_agIgNotCorMinThd_MP = MAX_int16_T;
  }

  /* Sum: '<S119>/Sum1' incorporates:
   *  Constant: '<S119>/Cste_1_1'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_ctLimAdvReactOutport2'
   */
  localTmpSignalConversionAtExt_t = (SInt16)
    (Rte_IrvRead_RE_AdvMinT_006_DRE_IgSys_ctLimAdvReact_irv() - 1);

  /* MinMax: '<S119>/MinMax' incorporates:
   *  Constant: '<S119>/Cste_0'
   */
  localTmpSignalConversionAtExt_t = (SInt16)rt_MAX
    (localTmpSignalConversionAtExt_t, 0);

  /* DataTypeConversion: '<S119>/Data Type Conversion1' */
  if (localTmpSignalConversionAtExt_t <= 0) {
    locallocalDataTypeConversion = 0U;
  } else if (localTmpSignalConversionAtExt_t > 255) {
    locallocalDataTypeConversion = MAX_uint8_T;
  } else {
    locallocalDataTypeConversion = (UInt8)localTmpSignalConversionAtExt_t;
  }

  /* Switch: '<S119>/Switch2' incorporates:
   *  Constant: '<S119>/Cste_1'
   *  RelationalOperator: '<S119>/Relational Operator'
   */
  if (localTmpSignalConversionAtExt_t != 0) {
    IgSys_agIgWrmMin = localInterpolationUsingPreloo_b;
  } else {
    IgSys_agIgWrmMin = localAdd2_o;
  }

  /* end of Outputs for SubSystem: '<S116>/F01_calc_AAmin_comb_ref' */

  /* Outputs for atomic SubSystem: '<S116>/F02_calc_vvt_corr' *
   * Block requirements for '<S116>/F02_calc_vvt_corr':
   *  1. SubSystem "F02_calc_vvt_corr" !Trace_To : VEMS_R_10_06440_021.01 ;
   */

  /* Outputs for atomic SubSystem: '<S120>/F01_Ign_min_angle_vvt_adm_corr' *
   * Block requirements for '<S120>/F01_Ign_min_angle_vvt_adm_corr':
   *  1. SubSystem "F01_Ign_min_angle_vvt_adm_corr" !Trace_To : VEMS_R_10_06440_022.01 ;
   */

  /* Interpolation_n-D: '<S133>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_6[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_6[1] = localAdd2_o;
  localbpIndex_6[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_6[1] = localExt_nEng_Ext_nEng_A_16_k;
  localAdd2_o = intrp2d_is16n1ff_u32f_l_ns(localbpIndex_6, localfrac_6,
    (&(IgSys_agCkOpInVlvWrmDft_M[0])), 16U);

  /* Sum: '<S126>/Sum2' incorporates:
   *  DataTypeConversion: '<S126>/Data Type Conversion3'
   */
  localSwitch1_oi = (((Float32)localTmpSignalConversionAtExt_a) * 0.09375F) -
    localAdd2_o;

  /* DataTypeConversion: '<S126>/Data Type Conversion9' incorporates:
   *  Constant: '<S126>/IgSys_agCkDeltaInVlvThd_C'
   */
  localInterpolationUsingPreloo_b = ((Float32)IgSys_agCkDeltaInVlvThd_C) *
    0.75F;

  /* Switch: '<S126>/Switch1' incorporates:
   *  Constant: '<S126>/Constant_61'
   *  Constant: '<S126>/Cste_0'
   *  Product: '<S142>/Divide'
   *  RelationalOperator: '<S126>/Relational Operator1'
   */
  if (localSwitch1_oi < (-localInterpolationUsingPreloo_b)) {
    localSwitch1_i = localSwitch1_oi;
  } else {
    localSwitch1_i = 0.0F;
  }

  /* Product: '<S137>/Product4' incorporates:
   *  Constant: '<S137>/offset'
   *  Constant: '<S137>/one_on_slope'
   *  Sum: '<S137>/Add1'
   */
  localAdd2_g = 1.333333373E+000F * localSwitch1_i;

  /* Switch: '<S137>/Switch1' incorporates:
   *  Constant: '<S137>/offset2'
   *  Constant: '<S137>/offset3'
   *  Constant: '<S137>/offset4'
   *  RelationalOperator: '<S137>/Relational Operator'
   *  Sum: '<S137>/Add3'
   *  Sum: '<S137>/Add4'
   */
  if (localAdd2_g >= 0.0F) {
    localAdd2_g = 0.5F;
  } else {
    localAdd2_g -= 0.5F;
  }

  /* DataStoreWrite: '<S126>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S137>/OutDTConv'
   */
  if (localAdd2_g >= -32768.0F) {
    IgSys_agCkDeltaInVlv3_MP = (SInt16)localAdd2_g;
  } else {
    IgSys_agCkDeltaInVlv3_MP = MIN_int16_T;
  }

  /* Switch: '<S126>/Switch2' incorporates:
   *  Constant: '<S126>/Cste_1'
   *  RelationalOperator: '<S126>/Relational Operator'
   */
  if (!(localSwitch1_oi > localInterpolationUsingPreloo_b)) {
    localSwitch1_oi = 0.0F;
  }

  /* Switch: '<S139>/Switch1' incorporates:
   *  Constant: '<S139>/offset'
   *  Constant: '<S139>/offset2'
   *  Constant: '<S139>/offset3'
   *  Constant: '<S139>/offset4'
   *  Constant: '<S139>/one_on_slope'
   *  Product: '<S139>/Product4'
   *  RelationalOperator: '<S139>/Relational Operator'
   *  Sum: '<S139>/Add1'
   *  Sum: '<S139>/Add3'
   *  Sum: '<S139>/Add4'
   */
  localAdd2_g = (1.333333373E+000F * localSwitch1_oi) + 0.5F;

  /* DataStoreWrite: '<S126>/Data Store Write3' incorporates:
   *  DataTypeConversion: '<S139>/OutDTConv'
   */
  if (localAdd2_g < 32768.0F) {
    IgSys_agCkDeltaInVlv4_MP = (SInt16)localAdd2_g;
  } else {
    IgSys_agCkDeltaInVlv4_MP = MAX_int16_T;
  }

  /* Sum: '<S126>/Sum3' incorporates:
   *  Constant: '<S126>/Vlv_agCkInVlvRefMax_C'
   *  DataTypeConversion: '<S126>/Data Type Conversion5'
   */
  localAdd2_g = (((Float32)Vlv_agCkInVlvRefMax_C) * 0.09375F) - localAdd2_o;

  /* RelationalOperator: '<S145>/LowerRelop1' incorporates:
   *  Constant: '<S126>/Cste_2'
   */
  localLowerRelop1_g = (localAdd2_g > 100.0F);

  /* Switch: '<S145>/Switch' incorporates:
   *  Constant: '<S126>/Cste_3'
   *  RelationalOperator: '<S145>/UpperRelop'
   */
  if (localAdd2_g < 1.0F) {
    localAdd2_g = 1.0F;
  }

  /* Switch: '<S145>/Switch2' incorporates:
   *  Constant: '<S126>/Cste_2'
   */
  if (localLowerRelop1_g) {
    localAdd2_g = 100.0F;
  }

  /* Sum: '<S126>/Sum1' incorporates:
   *  Constant: '<S126>/Vlv_agCkInVlvRefMin_C'
   *  DataTypeConversion: '<S126>/Data Type Conversion4'
   */
  localAdd2_o = (((Float32)Vlv_agCkInVlvRefMin_C) * 0.09375F) - localAdd2_o;

  /* RelationalOperator: '<S148>/LowerRelop1' incorporates:
   *  Constant: '<S126>/Cste_4'
   */
  localLowerRelop1_g = (localAdd2_o > -1.0F);

  /* Switch: '<S148>/Switch' incorporates:
   *  Constant: '<S126>/Cste_5'
   *  RelationalOperator: '<S148>/UpperRelop'
   */
  if (localAdd2_o < -100.0F) {
    localAdd2_o = -100.0F;
  }

  /* Switch: '<S148>/Switch2' incorporates:
   *  Constant: '<S126>/Cste_4'
   */
  if (localLowerRelop1_g) {
    localAdd2_o = -1.0F;
  }

  /* DataTypeConversion: '<S136>/OutDTConv' incorporates:
   *  Constant: '<S136>/offset'
   *  Constant: '<S136>/offset1'
   *  Constant: '<S136>/one_on_slope'
   *  Product: '<S136>/Product4'
   *  Product: '<S141>/Divide'
   *  Sum: '<S136>/Add1'
   *  Sum: '<S136>/Add2'
   */
  localInterpolationUsingPreloo_b = ((localSwitch1_oi / localAdd2_g) * 256.0F) +
    0.5F;
  if (localInterpolationUsingPreloo_b < 256.0F) {
    IgSys_rDeltaInVlv4_MP = (UInt8)localInterpolationUsingPreloo_b;
  } else {
    IgSys_rDeltaInVlv4_MP = MAX_uint8_T;
  }

  /* DataTypeConversion: '<S138>/OutDTConv' incorporates:
   *  Constant: '<S138>/offset'
   *  Constant: '<S138>/offset1'
   *  Constant: '<S138>/one_on_slope'
   *  Product: '<S138>/Product4'
   *  Product: '<S140>/Divide'
   *  Sum: '<S138>/Add1'
   *  Sum: '<S138>/Add2'
   */
  localInterpolationUsingPreloo_b = ((localSwitch1_i / localAdd2_o) * 256.0F) +
    0.5F;
  if (localInterpolationUsingPreloo_b < 256.0F) {
    if (localInterpolationUsingPreloo_b >= 0.0F) {
      IgSys_rDeltaInVlv3_MP = (UInt8)localInterpolationUsingPreloo_b;
    } else {
      IgSys_rDeltaInVlv3_MP = 0U;
    }
  } else {
    IgSys_rDeltaInVlv3_MP = MAX_uint8_T;
  }

  /* Lookup_n-D: '<S134>/Lookup Table (n-D)' */
  IgSys_rAdvMinInVlvMax = look1_iu8lfIf_binlcns(IgSys_rDeltaInVlv4_MP,
    (&(IgSys_agCkVlvEstim_A[0])), (&(IgSys_rAdvMinInVlvMax_T[0])), 8U);

  /* Lookup_n-D: '<S135>/Lookup Table (n-D)' */
  IgSys_rAdvMinInVlvMin = look1_iu8lfIf_binlcns(IgSys_rDeltaInVlv3_MP,
    (&(IgSys_agCkVlvEstim_A[0])), (&(IgSys_rAdvMinInVlvMin_T[0])), 8U);

  /* end of Outputs for SubSystem: '<S120>/F01_Ign_min_angle_vvt_adm_corr' */

  /* Outputs for atomic SubSystem: '<S120>/F02_Ign_min_opti_vvt_adm_ref' *
   * Block requirements for '<S120>/F02_Ign_min_opti_vvt_adm_ref':
   *  1. SubSystem "F02_Ign_min_opti_vvt_adm_ref" !Trace_To : VEMS_R_10_06440_023.01 ;
   */

  /* Interpolation_n-D: '<S149>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_7[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_7[1] = localAdd2_o;
  localbpIndex_7[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_7[1] = localExt_nEng_Ext_nEng_A_16_k;
  IgSys_agIgMinInVlvMax = intrp2d_is16n2ff_u32f_l_ns(localbpIndex_7, localfrac_7,
    (&(IgSys_agIgMinInVlvMax_M[0])), 16U);

  /* Interpolation_n-D: '<S150>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_8[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_8[1] = localAdd2_o;
  localbpIndex_8[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_8[1] = localExt_nEng_Ext_nEng_A_16_k;
  IgSys_agIgMinInVlvMin = intrp2d_is16n2ff_u32f_l_ns(localbpIndex_8, localfrac_8,
    (&(IgSys_agIgMinInVlvMin_M[0])), 16U);

  /* end of Outputs for SubSystem: '<S120>/F02_Ign_min_opti_vvt_adm_ref' */

  /* Outputs for atomic SubSystem: '<S120>/F03_Ign_min_opti_vvt_exh_ref' *
   * Block requirements for '<S120>/F03_Ign_min_opti_vvt_exh_ref':
   *  1. SubSystem "F03_Ign_min_opti_vvt_exh_ref" !Trace_To : VEMS_R_10_06440_024.01 ;
   */

  /* Interpolation_n-D: '<S151>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_9[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_9[1] = localAdd2_o;
  localbpIndex_9[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_9[1] = localExt_nEng_Ext_nEng_A_16_k;
  IgSys_agIgMinExVlvMax = intrp2d_is16n2ff_u32f_l_ns(localbpIndex_9, localfrac_9,
    (&(IgSys_agIgMinExVlvMax_M[0])), 16U);

  /* Interpolation_n-D: '<S152>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_a[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_a[1] = localAdd2_o;
  localbpIndex_a[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_a[1] = localExt_nEng_Ext_nEng_A_16_k;
  IgSys_agIgMinExVlvMin = intrp2d_is16n2ff_u32f_l_ns(localbpIndex_a, localfrac_a,
    (&(IgSys_agIgMinExVlvMin_M[0])), 16U);

  /* end of Outputs for SubSystem: '<S120>/F03_Ign_min_opti_vvt_exh_ref' */

  /* Outputs for atomic SubSystem: '<S120>/F04_Ign_min_angle_vvt_exh_corr' *
   * Block requirements for '<S120>/F04_Ign_min_angle_vvt_exh_corr':
   *  1. SubSystem "F04_Ign_min_angle_vvt_exh_corr" !Trace_To : VEMS_R_10_06440_025.01 ;
   */

  /* Interpolation_n-D: '<S155>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_b[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_b[1] = localAdd2_o;
  localbpIndex_b[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_b[1] = localExt_nEng_Ext_nEng_A_16_k;
  localAdd2_o = intrp2d_is16n1ff_u32f_l_ns(localbpIndex_b, localfrac_b,
    (&(IgSys_agCkClsExVlvWrmDft_M[0])), 16U);

  /* Sum: '<S129>/Sum2' incorporates:
   *  DataTypeConversion: '<S129>/Data Type Conversion3'
   */
  localSwitch1_oi = (((Float32)localTmpSignalConversionAtExt_b) * 0.09375F) -
    localAdd2_o;

  /* DataTypeConversion: '<S129>/Data Type Conversion4' incorporates:
   *  Constant: '<S129>/IgSys_agCkDeltaExVlvThd_C'
   */
  localInterpolationUsingPreloo_b = ((Float32)IgSys_agCkDeltaExVlvThd_C) *
    0.75F;

  /* Switch: '<S129>/Switch1' incorporates:
   *  Constant: '<S129>/Constant_62'
   *  Constant: '<S129>/Cste_0'
   *  Product: '<S164>/Divide'
   *  RelationalOperator: '<S129>/Relational Operator1'
   */
  if (localSwitch1_oi < (-localInterpolationUsingPreloo_b)) {
    localSwitch1_i = localSwitch1_oi;
  } else {
    localSwitch1_i = 0.0F;
  }

  /* Product: '<S158>/Product4' incorporates:
   *  Constant: '<S158>/offset'
   *  Constant: '<S158>/one_on_slope'
   *  Sum: '<S158>/Add1'
   */
  localAdd2_g = 1.333333373E+000F * localSwitch1_i;

  /* Switch: '<S158>/Switch1' incorporates:
   *  Constant: '<S158>/offset2'
   *  Constant: '<S158>/offset3'
   *  Constant: '<S158>/offset4'
   *  RelationalOperator: '<S158>/Relational Operator'
   *  Sum: '<S158>/Add3'
   *  Sum: '<S158>/Add4'
   */
  if (localAdd2_g >= 0.0F) {
    localAdd2_g = 0.5F;
  } else {
    localAdd2_g -= 0.5F;
  }

  /* DataStoreWrite: '<S129>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S158>/OutDTConv'
   */
  if (localAdd2_g >= -32768.0F) {
    IgSys_agCkDeltaExVlv3_MP = (SInt16)localAdd2_g;
  } else {
    IgSys_agCkDeltaExVlv3_MP = MIN_int16_T;
  }

  /* Switch: '<S129>/Switch2' incorporates:
   *  Constant: '<S129>/Cste_1'
   *  RelationalOperator: '<S129>/Relational Operator'
   */
  if (!(localSwitch1_oi > localInterpolationUsingPreloo_b)) {
    localSwitch1_oi = 0.0F;
  }

  /* Switch: '<S159>/Switch1' incorporates:
   *  Constant: '<S159>/offset'
   *  Constant: '<S159>/offset2'
   *  Constant: '<S159>/offset3'
   *  Constant: '<S159>/offset4'
   *  Constant: '<S159>/one_on_slope'
   *  Product: '<S159>/Product4'
   *  RelationalOperator: '<S159>/Relational Operator'
   *  Sum: '<S159>/Add1'
   *  Sum: '<S159>/Add3'
   *  Sum: '<S159>/Add4'
   */
  localAdd2_g = (1.333333373E+000F * localSwitch1_oi) + 0.5F;

  /* DataStoreWrite: '<S129>/Data Store Write3' incorporates:
   *  DataTypeConversion: '<S159>/OutDTConv'
   */
  if (localAdd2_g < 32768.0F) {
    IgSys_agCkDeltaExVlv4_MP = (SInt16)localAdd2_g;
  } else {
    IgSys_agCkDeltaExVlv4_MP = MAX_int16_T;
  }

  /* Sum: '<S129>/Sum3' incorporates:
   *  Constant: '<S129>/Vlv_agCkExVlvRefMax_C'
   *  DataTypeConversion: '<S129>/Data Type Conversion6'
   */
  localAdd2_g = (((Float32)Vlv_agCkExVlvRefMax_C) * 0.09375F) - localAdd2_o;

  /* RelationalOperator: '<S167>/LowerRelop1' incorporates:
   *  Constant: '<S129>/Cste_2'
   */
  localLowerRelop1_g = (localAdd2_g > 100.0F);

  /* Switch: '<S167>/Switch' incorporates:
   *  Constant: '<S129>/Cste_3'
   *  RelationalOperator: '<S167>/UpperRelop'
   */
  if (localAdd2_g < 1.0F) {
    localAdd2_g = 1.0F;
  }

  /* Switch: '<S167>/Switch2' incorporates:
   *  Constant: '<S129>/Cste_2'
   */
  if (localLowerRelop1_g) {
    localAdd2_g = 100.0F;
  }

  /* Sum: '<S129>/Sum1' incorporates:
   *  Constant: '<S129>/Vlv_agCkExVlvRefMin_C'
   *  DataTypeConversion: '<S129>/Data Type Conversion5'
   */
  localAdd2_o = (((Float32)Vlv_agCkExVlvRefMin_C) * 0.09375F) - localAdd2_o;

  /* RelationalOperator: '<S170>/LowerRelop1' incorporates:
   *  Constant: '<S129>/Cste_4'
   */
  localLowerRelop1_g = (localAdd2_o > -1.0F);

  /* Switch: '<S170>/Switch' incorporates:
   *  Constant: '<S129>/Cste_5'
   *  RelationalOperator: '<S170>/UpperRelop'
   */
  if (localAdd2_o < -100.0F) {
    localAdd2_o = -100.0F;
  }

  /* Switch: '<S170>/Switch2' incorporates:
   *  Constant: '<S129>/Cste_4'
   */
  if (localLowerRelop1_g) {
    localAdd2_o = -1.0F;
  }

  /* DataTypeConversion: '<S161>/OutDTConv' incorporates:
   *  Constant: '<S161>/offset'
   *  Constant: '<S161>/offset1'
   *  Constant: '<S161>/one_on_slope'
   *  Product: '<S161>/Product4'
   *  Product: '<S163>/Divide'
   *  Sum: '<S161>/Add1'
   *  Sum: '<S161>/Add2'
   */
  localInterpolationUsingPreloo_b = ((localSwitch1_oi / localAdd2_g) * 256.0F) +
    0.5F;
  if (localInterpolationUsingPreloo_b < 256.0F) {
    IgSys_rDeltaExVlv4_MP = (UInt8)localInterpolationUsingPreloo_b;
  } else {
    IgSys_rDeltaExVlv4_MP = MAX_uint8_T;
  }

  /* DataTypeConversion: '<S160>/OutDTConv' incorporates:
   *  Constant: '<S160>/offset'
   *  Constant: '<S160>/offset1'
   *  Constant: '<S160>/one_on_slope'
   *  Product: '<S160>/Product4'
   *  Product: '<S162>/Divide'
   *  Sum: '<S160>/Add1'
   *  Sum: '<S160>/Add2'
   */
  localInterpolationUsingPreloo_b = ((localSwitch1_i / localAdd2_o) * 256.0F) +
    0.5F;
  if (localInterpolationUsingPreloo_b < 256.0F) {
    if (localInterpolationUsingPreloo_b >= 0.0F) {
      IgSys_rDeltaExVlv3_MP = (UInt8)localInterpolationUsingPreloo_b;
    } else {
      IgSys_rDeltaExVlv3_MP = 0U;
    }
  } else {
    IgSys_rDeltaExVlv3_MP = MAX_uint8_T;
  }

  /* Lookup_n-D: '<S156>/Lookup Table (n-D)' */
  IgSys_rAdvMinExVlvMax = look1_iu8lfIf_binlcns(IgSys_rDeltaExVlv4_MP,
    (&(IgSys_agCkVlvEstim_A[0])), (&(IgSys_rAdvMinExVlvMax_T[0])), 8U);

  /* Lookup_n-D: '<S157>/Lookup Table (n-D)' */
  IgSys_rAdvMinExVlvMin = look1_iu8lfIf_binlcns(IgSys_rDeltaExVlv3_MP,
    (&(IgSys_agCkVlvEstim_A[0])), (&(IgSys_rAdvMinExVlvMin_T[0])), 8U);

  /* end of Outputs for SubSystem: '<S120>/F04_Ign_min_angle_vvt_exh_corr' */

  /* Outputs for atomic SubSystem: '<S120>/F05_Basic_advance_min_setpoint' *
   * Block requirements for '<S120>/F05_Basic_advance_min_setpoint':
   *  1. SubSystem "F05_Basic_advance_min_setpoint" !Trace_To : VEMS_R_10_06440_026.01 ;
   */

  /* Sum: '<S130>/Sum2' incorporates:
   *  Product: '<S171>/Divide'
   *  Product: '<S172>/Divide'
   *  Product: '<S173>/Divide'
   *  Product: '<S174>/Divide'
   *  Sum: '<S130>/Sum'
   *  Sum: '<S130>/Sum1'
   *  Sum: '<S130>/Sum3'
   *  Sum: '<S130>/Sum4'
   */
  IgSys_agIgWrmUpCor = (((((IgSys_agIgMinInVlvMax - IgSys_agIgWrmMin) *
    IgSys_rAdvMinInVlvMax) + IgSys_agIgWrmMin) + ((IgSys_agIgMinInVlvMin -
    IgSys_agIgWrmMin) * IgSys_rAdvMinInVlvMin)) + ((IgSys_agIgMinExVlvMax -
    IgSys_agIgWrmMin) * IgSys_rAdvMinExVlvMax)) + ((IgSys_agIgMinExVlvMin -
    IgSys_agIgWrmMin) * IgSys_rAdvMinExVlvMin);

  /* end of Outputs for SubSystem: '<S120>/F05_Basic_advance_min_setpoint' */

  /* end of Outputs for SubSystem: '<S116>/F02_calc_vvt_corr' */

  /* Outputs for atomic SubSystem: '<S116>/F03_calc_cor_cold' *
   * Block requirements for '<S116>/F03_calc_cor_cold':
   *  1. SubSystem "F03_calc_cor_cold" !Trace_To : VEMS_R_10_06440_027.01 ;
   */

  /* Interpolation_n-D: '<S175>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_5[0] = localAdd2_o;
  localAdd2_o = localExt_tCoMes_IgSys_tCoMes_A_;
  localfrac_5[1] = localAdd2_o;
  localbpIndex_5[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_5[1] = localExt_tCoMes_IgSys_tCoMes__i;
  localAdd2_o = intrp2d_is16n2ff_u32f_l_ns(localbpIndex_5, localfrac_5,
    (&(IgSys_agIgColdCor_M[0])), 16U);

  /* Product: '<S176>/Product4' incorporates:
   *  Constant: '<S176>/offset'
   *  Constant: '<S176>/one_on_slope'
   *  Sum: '<S176>/Add1'
   */
  localSwitch1_oi = 2.666666746E+000F * localAdd2_o;

  /* Switch: '<S176>/Switch1' incorporates:
   *  Constant: '<S176>/offset2'
   *  Constant: '<S176>/offset3'
   *  Constant: '<S176>/offset4'
   *  RelationalOperator: '<S176>/Relational Operator'
   *  Sum: '<S176>/Add3'
   *  Sum: '<S176>/Add4'
   */
  if (localSwitch1_oi >= 0.0F) {
    localSwitch1_oi += 0.5F;
  } else {
    localSwitch1_oi -= 0.5F;
  }

  /* DataStoreWrite: '<S121>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<S176>/OutDTConv'
   */
  if (localSwitch1_oi < 32768.0F) {
    if (localSwitch1_oi >= -32768.0F) {
      IgSys_agIgColdCor_MP = (SInt16)localSwitch1_oi;
    } else {
      IgSys_agIgColdCor_MP = MIN_int16_T;
    }
  } else {
    IgSys_agIgColdCor_MP = MAX_int16_T;
  }

  /* Sum: '<S121>/Sum' */
  IgSys_agIgMinCmbWoutOfs = IgSys_agIgWrmUpCor + localAdd2_o;

  /* end of Outputs for SubSystem: '<S116>/F03_calc_cor_cold' */

  /* end of Outputs for SubSystem: '<S99>/F02_calcul_avance_min' */

  /* end of Outputs for SubSystem: '<S11>/F01_Calcul_av_lim' */

  /* SignalConversion: '<S108>/copy' */
  IgSys_ctLimAdvReact_IRV_MP = locallocalDataTypeConversion;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S108>/autosar_testpoint1' */

  /* S-Function Block: <S108>/autosar_testpoint1 */

  /* SignalConversion: '<S109>/copy' */
  IgSys_agIgMinStrt_IRV_MP = locallocalOutDTConv_k;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S109>/autosar_testpoint1' */

  /* S-Function Block: <S109>/autosar_testpoint1 */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgCmbModOfsMinCmbOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgCmbModOfsMinCmb'
   */
  Rte_Read_R_IgSys_agIgCmbModOfsMinCmb_IgSys_agIgCmbModOfsMinCmb
    (&localTmpSignalConversionAtIgSys);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinCmbFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMinCmbFlex'
   */
  Rte_Read_R_IgSys_agIgMinCmbFlex_IgSys_agIgMinCmbFlex
    (&localTmpSignalConversionAtIgS_o);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinCmbGasOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMinCmbGas'
   */
  Rte_Read_R_IgSys_agIgMinCmbGas_IgSys_agIgMinCmbGas
    (&localTmpSignalConversionAtIgS_n);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_facFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_facFlex'
   */
  Rte_Read_R_IgSys_prm_facFlex_IgSys_prm_facFlex
    (&localTmpSignalConversionAtIgS_k);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_facGasOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_facGas'
   */
  Rte_Read_R_IgSys_prm_facGas_IgSys_prm_facGas(&localTmpSignalConversionAtIg_ka);

  /* Outputs for atomic SubSystem: '<S11>/F03_Correctifs_AAmini_comb' *
   * Block requirements for '<S11>/F03_Correctifs_AAmini_comb':
   *  1. SubSystem "F03_Correctifs_AAmini_comb" !Trace_To : VEMS_R_10_06440_030.01 ;
   */

  /* Sum: '<S101>/Sum3' incorporates:
   *  DataTypeConversion: '<S101>/Data Type Conversion6'
   */
  localSwitch1_oi = (((Float32)localTmpSignalConversionAtIgSys) * 0.25F) +
    IgSys_agIgMinCmbWoutOfs;

  /* DataTypeConversion: '<S101>/Data Type Conversion3' */
  localInterpolationUsingPreloo_b = ((Float32)localTmpSignalConversionAtIgS_o) *
    0.25F;

  /* Switch: '<S101>/Switch1' incorporates:
   *  Constant: '<S101>/IgSys_bFlexMinCmbOfs_C'
   *  Sum: '<S101>/Sum'
   */
  if (!IgSys_bFlexMinCmbOfs_C) {
    localInterpolationUsingPreloo_b += IgSys_agIgMinCmbWoutOfs;
  }

  /* Sum: '<S186>/Sum3' */
  localAdd2_o = localInterpolationUsingPreloo_b - localSwitch1_oi;

  /* DataTypeConversion: '<S101>/Data Type Conversion4' incorporates:
   *  Constant: '<S188>/Constant'
   *  MinMax: '<S188>/MinMax'
   *  Selector: '<S188>/Selector'
   */
  localInterpolationUsingPreloo_b = ((Float32)localTmpSignalConversionAtIgS_k[2])
    * 0.0078125F;

  /* Switch: '<S194>/Switch2' incorporates:
   *  Constant: '<S186>/Constant'
   *  RelationalOperator: '<S194>/LowerRelop1'
   */
  if (localInterpolationUsingPreloo_b > 1.0F) {
    localInterpolationUsingPreloo_b = 1.0F;
  }

  /* Sum: '<S186>/Sum2' incorporates:
   *  Product: '<S186>/Divide'
   */
  localSwitch1_oi += localAdd2_o * localInterpolationUsingPreloo_b;

  /* Product: '<S190>/Product4' incorporates:
   *  Constant: '<S190>/offset'
   *  Constant: '<S190>/one_on_slope'
   *  Sum: '<S190>/Add1'
   */
  localInterpolationUsingPreloo_b = 2.666666746E+000F * localSwitch1_oi;

  /* Switch: '<S190>/Switch1' incorporates:
   *  Constant: '<S190>/offset2'
   *  Constant: '<S190>/offset3'
   *  Constant: '<S190>/offset4'
   *  RelationalOperator: '<S190>/Relational Operator'
   *  Sum: '<S190>/Add3'
   *  Sum: '<S190>/Add4'
   */
  if (localInterpolationUsingPreloo_b >= 0.0F) {
    localInterpolationUsingPreloo_b += 0.5F;
  } else {
    localInterpolationUsingPreloo_b -= 0.5F;
  }

  /* DataStoreWrite: '<S101>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S190>/OutDTConv'
   */
  if (localInterpolationUsingPreloo_b < 32768.0F) {
    if (localInterpolationUsingPreloo_b >= -32768.0F) {
      IgSys_agIgMinCmbWiFlexCor_MP = (SInt16)localInterpolationUsingPreloo_b;
    } else {
      IgSys_agIgMinCmbWiFlexCor_MP = MIN_int16_T;
    }
  } else {
    IgSys_agIgMinCmbWiFlexCor_MP = MAX_int16_T;
  }

  /* DataTypeConversion: '<S101>/Data Type Conversion5' incorporates:
   *  Constant: '<S189>/Constant'
   *  MinMax: '<S189>/MinMax'
   *  Selector: '<S189>/Selector'
   */
  localInterpolationUsingPreloo_b = ((Float32)localTmpSignalConversionAtIg_ka[2])
    * 0.0078125F;

  /* Switch: '<S198>/Switch2' incorporates:
   *  Constant: '<S187>/Constant'
   *  RelationalOperator: '<S198>/LowerRelop1'
   */
  if (localInterpolationUsingPreloo_b > 1.0F) {
    localInterpolationUsingPreloo_b = 1.0F;
  }

  /* DataTypeConversion: '<S101>/Data Type Conversion2' */
  localAdd2_o = ((Float32)localTmpSignalConversionAtIgS_n) * 0.25F;

  /* Switch: '<S101>/Switch3' incorporates:
   *  Constant: '<S101>/IgSys_bGasMinCmbOfs_C'
   *  Sum: '<S101>/Sum1'
   */
  if (!IgSys_bGasMinCmbOfs_C) {
    localAdd2_o += localSwitch1_oi;
  }

  /* Sum: '<S187>/Sum2' incorporates:
   *  Product: '<S187>/Divide'
   *  Sum: '<S187>/Sum3'
   */
  localSum2_n = ((localAdd2_o - localSwitch1_oi) *
                 localInterpolationUsingPreloo_b) + localSwitch1_oi;

  /* end of Outputs for SubSystem: '<S11>/F03_Correctifs_AAmini_comb' */

  /* Outputs for atomic SubSystem: '<S11>/F03_calcul_avance_min_agrement' *
   * Block requirements for '<S11>/F03_calcul_avance_min_agrement':
   *  1. SubSystem "F03_calcul_avance_min_agrement" !Trace_To : VEMS_R_10_06440_028.02 ;
   */

  /* Interpolation_n-D: '<S200>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac[1] = localAdd2_o;
  localbpIndex[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex[1] = localExt_nEng_Ext_nEng_A_16_k;
  localSwitch1_oi = intrp2d_is16n1ff_u32f_l_ns(localbpIndex, localfrac,
    (&(IgSys_agIgMinDriv_M[0])), 16U);

  /* Product: '<S202>/Product4' incorporates:
   *  Constant: '<S202>/offset'
   *  Constant: '<S202>/one_on_slope'
   *  Sum: '<S202>/Add1'
   */
  localAdd2_o = 1.333333373E+000F * localSwitch1_oi;

  /* Switch: '<S202>/Switch1' incorporates:
   *  Constant: '<S202>/offset2'
   *  Constant: '<S202>/offset3'
   *  Constant: '<S202>/offset4'
   *  RelationalOperator: '<S202>/Relational Operator'
   *  Sum: '<S202>/Add3'
   *  Sum: '<S202>/Add4'
   */
  if (localAdd2_o >= 0.0F) {
    localAdd2_o += 0.5F;
  } else {
    localAdd2_o -= 0.5F;
  }

  /* DataStoreWrite: '<S102>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S202>/OutDTConv'
   */
  if (localAdd2_o < 32768.0F) {
    if (localAdd2_o >= -32768.0F) {
      IgSys_agIgMinDriv_MP = (SInt16)localAdd2_o;
    } else {
      IgSys_agIgMinDriv_MP = MIN_int16_T;
    }
  } else {
    IgSys_agIgMinDriv_MP = MAX_int16_T;
  }

  /* Interpolation_n-D: '<S199>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_0[0] = localAdd2_o;
  localAdd2_o = localExt_tCoMes_IgSys_tCoMes_A_;
  localfrac_0[1] = localAdd2_o;
  localbpIndex_0[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_0[1] = localExt_tCoMes_IgSys_tCoMes__i;
  localAdd2_o = intrp2d_iu8n8ff_u32f_l_ns(localbpIndex_0, localfrac_0,
    (&(IgSys_facMinDriv_M[0])), 16U);

  /* DataStoreWrite: '<S102>/Data Store Write2' incorporates:
   *  Constant: '<S203>/offset'
   *  Constant: '<S203>/offset1'
   *  Constant: '<S203>/one_on_slope'
   *  DataTypeConversion: '<S203>/OutDTConv'
   *  Product: '<S203>/Product4'
   *  Sum: '<S203>/Add1'
   *  Sum: '<S203>/Add2'
   */
  localInterpolationUsingPreloo_b = (256.0F * localAdd2_o) + 0.5F;
  if (localInterpolationUsingPreloo_b < 256.0F) {
    if (localInterpolationUsingPreloo_b >= 0.0F) {
      IgSys_facMinDriv_MP = (UInt8)localInterpolationUsingPreloo_b;
    } else {
      IgSys_facMinDriv_MP = 0U;
    }
  } else {
    IgSys_facMinDriv_MP = MAX_uint8_T;
  }

  /* Product: '<S204>/Divide' */
  localSwitch1_oi *= localAdd2_o;

  /* Switch: '<S102>/Switch2' incorporates:
   *  Constant: '<S102>/IgSys_bAcvAgIgMinDrivOfs_C'
   *  Sum: '<S102>/Add1'
   */
  if (IgSys_bAcvAgIgMinDrivOfs_C) {
    localSwitch1_oi = localSum2_n - localSwitch1_oi;
  }

  /* DataTypeConversion: '<S201>/OutDTConv' incorporates:
   *  Constant: '<S201>/offset'
   *  Constant: '<S201>/offset1'
   *  Constant: '<S201>/one_on_slope'
   *  Product: '<S201>/Product4'
   *  Sum: '<S201>/Add1'
   *  Sum: '<S201>/Add2'
   */
  localInterpolationUsingPreloo_b = ((localSwitch1_oi - -36.0F) *
    2.666666746E+000F) + 0.5F;
  if (localInterpolationUsingPreloo_b < 256.0F) {
    if (localInterpolationUsingPreloo_b >= 0.0F) {
      locallocalOutDTConv_p = (UInt8)localInterpolationUsingPreloo_b;
    } else {
      locallocalOutDTConv_p = 0U;
    }
  } else {
    locallocalOutDTConv_p = MAX_uint8_T;
  }

  /* end of Outputs for SubSystem: '<S11>/F03_calcul_avance_min_agrement' */

  /* SignalConversion: '<S110>/copy' */
  IgSys_agIgMinDriv_IRV_MP = locallocalOutDTConv_p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S110>/autosar_testpoint1' */

  /* S-Function Block: <S110>/autosar_testpoint1 */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&localTmpSignalConversionAtFARSp);

  /* Outputs for atomic SubSystem: '<S11>/F02_Calcul_av_meca_stat' *
   * Block requirements for '<S11>/F02_Calcul_av_meca_stat':
   *  1. SubSystem "F02_Calcul_av_meca_stat" !Trace_To : VEMS_R_10_06440_029.02 ;
   */

  /* MinMax: '<S100>/MinMax' incorporates:
   *  Constant: '<S100>/Cste_0'
   *  Constant: '<S100>/FARSp_rMixtAgIgMinProtRef_C'
   *  Sum: '<S100>/Sum5'
   */
  localrtmax = (localTmpSignalConversionAtFARSp << 14) -
    (FARSp_rMixtAgIgMinProtRef_C * 16777);
  localrtmax = mul_s32_s32_s32_sr7_sat((localrtmax >= 0) ? ((SInt32)(((UInt32)
    localrtmax) >> 14U)) : (~((SInt32)(((UInt32)(~localrtmax)) >> 14U))), 125);
  if (0 > localrtmax) {
    localrtmax = 0;
  }

  if (localrtmax <= 0) {
    IgSys_rMixtAgIgMinLim_MP = 0U;
  } else if (localrtmax > 65535) {
    IgSys_rMixtAgIgMinLim_MP = MAX_uint16_T;
  } else {
    IgSys_rMixtAgIgMinLim_MP = (UInt16)localrtmax;
  }

  /* Lookup_n-D: '<S180>/Lookup Table (n-D)' */
  localSwitch1_oi = look1_iu16lftu8n7If_binlcns(IgSys_rMixtAgIgMinLim_MP,
    (&(IgSys_rMixt_facAgIgMinProt_A[0])), (&(IgSys_facAgIgMinProt_T[0])), 10U);

  /* DataStoreWrite: '<S100>/Data Store Write2' incorporates:
   *  Constant: '<S181>/offset'
   *  Constant: '<S181>/offset1'
   *  Constant: '<S181>/one_on_slope'
   *  DataTypeConversion: '<S181>/OutDTConv'
   *  Product: '<S181>/Product4'
   *  Sum: '<S181>/Add1'
   *  Sum: '<S181>/Add2'
   */
  localInterpolationUsingPreloo_b = (100.0F * localSwitch1_oi) + 0.5F;
  if (localInterpolationUsingPreloo_b < 256.0F) {
    if (localInterpolationUsingPreloo_b >= 0.0F) {
      IgSys_facAgIgMinProt_MP = (UInt8)localInterpolationUsingPreloo_b;
    } else {
      IgSys_facAgIgMinProt_MP = 0U;
    }
  } else {
    IgSys_facAgIgMinProt_MP = MAX_uint8_T;
  }

  /* RelationalOperator: '<S185>/LowerRelop1' incorporates:
   *  Constant: '<S177>/Constant'
   */
  localLowerRelop1_g = (localSwitch1_oi > 1.0F);

  /* Switch: '<S185>/Switch' incorporates:
   *  Constant: '<S177>/Constant1'
   *  RelationalOperator: '<S185>/UpperRelop'
   */
  if (localSwitch1_oi < 0.0F) {
    localSwitch1_oi = 0.0F;
  }

  /* Switch: '<S185>/Switch2' incorporates:
   *  Constant: '<S177>/Constant'
   */
  if (localLowerRelop1_g) {
    localSwitch1_oi = 1.0F;
  }

  /* Interpolation_n-D: '<S178>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_1[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_1[1] = localAdd2_o;
  localbpIndex_1[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_1[1] = localExt_nEng_Ext_nEng_A_16_k;
  localInterpolationUsingPrelooku = intrp2d_iu8n2ff_u32f_l_ns(localbpIndex_1,
    localfrac_1, (&(IgSys_agIgMinGsl_M[0])), 16U);

  /* Interpolation_n-D: '<S179>/Interpolation Using Prelookup3' */
  localAdd2_o = localEngM_rAirLdCor_Eng_rAirLd_;
  localfrac_2[0] = localAdd2_o;
  localAdd2_o = localExt_nEng_Ext_nEng_A_16_f;
  localfrac_2[1] = localAdd2_o;
  localbpIndex_2[0] = localEngM_rAirLdCor_Eng_rAirL_l;
  localbpIndex_2[1] = localExt_nEng_Ext_nEng_A_16_k;
  localAdd2_g = intrp2d_iu8n2ff_u32f_l_ns(localbpIndex_2, localfrac_2,
    (&(IgSys_agIgMinKnk_M[0])), 16U);

  /* Sum: '<S177>/Sum2' incorporates:
   *  Product: '<S177>/Divide'
   *  Sum: '<S177>/Sum3'
   */
  IgSys_agIgMinThermoWoutOfs = ((localAdd2_g - localInterpolationUsingPrelooku) *
    localSwitch1_oi) + localInterpolationUsingPrelooku;

  /* end of Outputs for SubSystem: '<S11>/F02_Calcul_av_meca_stat' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgCmbModOfsMinThermoOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgCmbModOfsMinThermo'
   */
  Rte_Read_R_IgSys_agIgCmbModOfsMinThermo_IgSys_agIgCmbModOfsMinThermo
    (&localTmpSignalConversionAtIgS_j);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinThermoFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMinThermoFlex'
   */
  Rte_Read_R_IgSys_agIgMinThermoFlex_IgSys_agIgMinThermoFlex
    (&localTmpSignalConversionAtIg_jb);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinThermoGasOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMinThermoGas'
   */
  Rte_Read_R_IgSys_agIgMinThermoGas_IgSys_agIgMinThermoGas
    (&localTmpSignalConversionAtIgS_g);

  /* Outputs for atomic SubSystem: '<S11>/F04_Correctifs_AAmini_thermo' *
   * Block requirements for '<S11>/F04_Correctifs_AAmini_thermo':
   *  1. SubSystem "F04_Correctifs_AAmini_thermo" !Trace_To : VEMS_R_10_06440_031.01 ;
   */

  /* Sum: '<S103>/Sum3' incorporates:
   *  DataTypeConversion: '<S103>/Data Type Conversion6'
   */
  localSwitch1_oi = (((Float32)localTmpSignalConversionAtIgS_j) * 0.25F) +
    IgSys_agIgMinThermoWoutOfs;

  /* DataTypeConversion: '<S103>/Data Type Conversion3' */
  localInterpolationUsingPreloo_b = ((Float32)localTmpSignalConversionAtIg_jb) *
    0.25F;

  /* Switch: '<S103>/Switch1' incorporates:
   *  Constant: '<S103>/IgSys_bFlexMinThermoOfs_C'
   *  Sum: '<S103>/Sum'
   */
  if (!IgSys_bFlexMinThermoOfs_C) {
    localInterpolationUsingPreloo_b += IgSys_agIgMinThermoWoutOfs;
  }

  /* Sum: '<S205>/Sum3' */
  localAdd2_o = localInterpolationUsingPreloo_b - localSwitch1_oi;

  /* DataTypeConversion: '<S103>/Data Type Conversion2' incorporates:
   *  Constant: '<S207>/Constant'
   *  MinMax: '<S207>/MinMax'
   *  Selector: '<S207>/Selector'
   */
  localInterpolationUsingPreloo_b = ((Float32)localTmpSignalConversionAtIgS_k[3])
    * 0.0078125F;

  /* Switch: '<S214>/Switch2' incorporates:
   *  Constant: '<S205>/Constant'
   *  RelationalOperator: '<S214>/LowerRelop1'
   */
  if (localInterpolationUsingPreloo_b > 1.0F) {
    localInterpolationUsingPreloo_b = 1.0F;
  }

  /* Sum: '<S205>/Sum2' incorporates:
   *  Product: '<S205>/Divide'
   */
  localSwitch1_oi += localAdd2_o * localInterpolationUsingPreloo_b;

  /* Product: '<S209>/Product4' incorporates:
   *  Constant: '<S209>/offset'
   *  Constant: '<S209>/one_on_slope'
   *  Sum: '<S209>/Add1'
   */
  localInterpolationUsingPreloo_b = 2.666666746E+000F * localSwitch1_oi;

  /* Switch: '<S209>/Switch1' incorporates:
   *  Constant: '<S209>/offset2'
   *  Constant: '<S209>/offset3'
   *  Constant: '<S209>/offset4'
   *  RelationalOperator: '<S209>/Relational Operator'
   *  Sum: '<S209>/Add3'
   *  Sum: '<S209>/Add4'
   */
  if (localInterpolationUsingPreloo_b >= 0.0F) {
    localInterpolationUsingPreloo_b += 0.5F;
  } else {
    localInterpolationUsingPreloo_b -= 0.5F;
  }

  /* DataStoreWrite: '<S103>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S209>/OutDTConv'
   */
  if (localInterpolationUsingPreloo_b < 32768.0F) {
    if (localInterpolationUsingPreloo_b >= -32768.0F) {
      IgSys_agIgMinThermoWiFlex_MP = (SInt16)localInterpolationUsingPreloo_b;
    } else {
      IgSys_agIgMinThermoWiFlex_MP = MIN_int16_T;
    }
  } else {
    IgSys_agIgMinThermoWiFlex_MP = MAX_int16_T;
  }

  /* DataTypeConversion: '<S103>/Data Type Conversion5' incorporates:
   *  Constant: '<S208>/Constant'
   *  MinMax: '<S208>/MinMax'
   *  Selector: '<S208>/Selector'
   */
  localInterpolationUsingPreloo_b = ((Float32)localTmpSignalConversionAtIg_ka[3])
    * 0.0078125F;

  /* Switch: '<S218>/Switch2' incorporates:
   *  Constant: '<S206>/Constant'
   *  RelationalOperator: '<S218>/LowerRelop1'
   */
  if (localInterpolationUsingPreloo_b > 1.0F) {
    localInterpolationUsingPreloo_b = 1.0F;
  }

  /* DataTypeConversion: '<S103>/Data Type Conversion4' */
  localSwitch1_i = ((Float32)localTmpSignalConversionAtIgS_g) * 0.25F;

  /* Switch: '<S103>/Switch3' incorporates:
   *  Constant: '<S103>/IgSys_bGasMinThermoOfs_C'
   *  Sum: '<S103>/Sum1'
   */
  if (!IgSys_bGasMinThermoOfs_C) {
    localSwitch1_i += localSwitch1_oi;
  }

  /* Sum: '<S210>/Add2' incorporates:
   *  Constant: '<S210>/offset'
   *  Constant: '<S210>/offset1'
   *  Constant: '<S210>/one_on_slope'
   *  Product: '<S206>/Divide'
   *  Product: '<S210>/Product4'
   *  Sum: '<S206>/Sum2'
   *  Sum: '<S206>/Sum3'
   *  Sum: '<S210>/Add1'
   */
  localSwitch1_i = (((((localSwitch1_i - localSwitch1_oi) *
                       localInterpolationUsingPreloo_b) + localSwitch1_oi) -
                     -36.0F) * 2.666666746E+000F) + 0.5F;

  /* end of Outputs for SubSystem: '<S11>/F04_Correctifs_AAmini_thermo' */

  /* Sum: '<S107>/Add2' incorporates:
   *  Constant: '<S107>/offset'
   *  Constant: '<S107>/offset1'
   *  Constant: '<S107>/one_on_slope'
   *  Product: '<S107>/Product4'
   *  Sum: '<S107>/Add1'
   */
  localAdd2_o = ((localSum2_n - -36.0F) * 2.666666746E+000F) + 0.5F;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S112>/Byp_Fonction_SC'
   *  Constant: '<S112>/Int_BypC'
   *  DataTypeConversion: '<S112>/Data Type Conversion'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch_l = IgSys_agIgLimMinKnk_B;
  } else {
    localtmp = (((Float32d)localAdd2_g) + 36.0F) / 0.375F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        localSwitch_l = (UInt8)localtmp;
      } else {
        localSwitch_l = 0U;
      }
    } else {
      localSwitch_l = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgLimMinKnkInport2' */
  Rte_Write_P_IgSys_agIgLimMinKnk_IgSys_agIgLimMinKnk(localSwitch_l);

  /* Switch: '<S111>/Switch' incorporates:
   *  Constant: '<S111>/Byp_Fonction_SC'
   *  Constant: '<S111>/Int_BypC'
   *  DataTypeConversion: '<S111>/Data Type Conversion'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch_l = IgSys_agIgLimMinRef_B;
  } else {
    localtmp = (((Float32d)localInterpolationUsingPrelooku) + 36.0F) / 0.375F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        localSwitch_l = (UInt8)localtmp;
      } else {
        localSwitch_l = 0U;
      }
    } else {
      localSwitch_l = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgLimMinRefInport2' */
  Rte_Write_P_IgSys_agIgLimMinRef_IgSys_agIgLimMinRef(localSwitch_l);

  /* Switch: '<S113>/Switch' incorporates:
   *  Constant: '<S113>/Byp_Fonction_SC'
   *  Constant: '<S113>/Int_BypC'
   *  DataTypeConversion: '<S107>/OutDTConv'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch_l = IgSys_agIgMinCmb_B;
  } else if (localAdd2_o < 256.0F) {
    if (localAdd2_o >= 0.0F) {
      localSwitch_l = (UInt8)localAdd2_o;
    } else {
      localSwitch_l = 0U;
    }
  } else {
    localSwitch_l = MAX_uint8_T;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinCmbInport2' */
  Rte_Write_P_IgSys_agIgMinCmb_IgSys_agIgMinCmb(localSwitch_l);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinDriv_irvInport2' incorporates:
   *  SignalConversion: '<S11>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_AdvMinT_006_DRE_IgSys_agIgMinDriv_irv(locallocalOutDTConv_p);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinStrt_irvInport2' incorporates:
   *  SignalConversion: '<S11>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_AdvMinT_006_DRE_IgSys_agIgMinStrt_irv(locallocalOutDTConv_k);

  /* Switch: '<S114>/Switch' incorporates:
   *  Constant: '<S114>/Byp_Fonction_SC'
   *  Constant: '<S114>/Int_BypC'
   *  DataTypeConversion: '<S210>/OutDTConv'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch_l = IgSys_agIgMinThermo_B;
  } else if (localSwitch1_i < 256.0F) {
    if (localSwitch1_i >= 0.0F) {
      localSwitch_l = (UInt8)localSwitch1_i;
    } else {
      localSwitch_l = 0U;
    }
  } else {
    localSwitch_l = MAX_uint8_T;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinThermoInport2' */
  Rte_Write_P_IgSys_agIgMinThermo_IgSys_agIgMinThermo(localSwitch_l);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_ctLimAdvReact_irvInport2' incorporates:
   *  SignalConversion: '<S11>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_AdvMinT_006_DRE_IgSys_ctLimAdvReact_irv
    (locallocalDataTypeConversion);
}

/* Start for exported function: RE_AdvMinT_008_DRE */
void RE_AdvMinT_008_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Init_delay'
   *
   * Block requirements for '<S1>/F02_Init_delay':
   *  1. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_015.01 ;
   *  2. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_074.02 ;
   *  3. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_049.01 ;
   *  4. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_078.01 ;
   *  5. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_012.02 ;
   *  6. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_013.02 ;
   */
}

/* Output and update for exported function: RE_AdvMinT_008_DRE */
void RE_AdvMinT_008_DRE(void)
{
  /* local block i/o variables */
  UInt8 localOutDTConv_ki;
  UInt8 localTmpSignalConversionAtCoPt_;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Init_delay'
   *
   * Block requirements for '<S1>/F02_Init_delay':
   *  1. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_015.01 ;
   *  2. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_074.02 ;
   *  3. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_049.01 ;
   *  4. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_078.01 ;
   *  5. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_012.02 ;
   *  6. SubSystem "F02_Init_delay" !Trace_To : VEMS_R_10_06440_013.02 ;
   */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtCoPt_noEgdGearCordOutport2' incorporates:
   *  Inport: '<Root>/CoPt_noEgdGearCord'
   */
  Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord
    (&localTmpSignalConversionAtCoPt_);

  /* DataTypeConversion: '<S97>/OutDTConv' incorporates:
   *  Constant: '<S97>/offset'
   *  Constant: '<S97>/offset1'
   *  Constant: '<S97>/one_on_slope'
   *  Lookup_n-D: '<S96>/Lookup Table (n-D)'
   *  Product: '<S97>/Product4'
   *  Sum: '<S97>/Add1'
   *  Sum: '<S97>/Add2'
   */
  localtmp = look1_iu8lftu16If_binlcs(localTmpSignalConversionAtCoPt_,
    (&(IgSys_noGear6_A[0])), (&(IgSys_tiDlyIgLim_T[0])), 6U) + 0.5F;
  if (localtmp < 256.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_ki = (UInt8)localtmp;
    } else {
      localOutDTConv_ki = 0U;
    }
  } else {
    localOutDTConv_ki = MAX_uint8_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S98>/autosar_testpoint1' */

  /* S-Function Block: <S98>/autosar_testpoint1 */
  IgSys_ctLimAdvReact_IRV_MP = localOutDTConv_ki;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_ctLimAdvReact_irvInport2' incorporates:
   *  SignalConversion: '<S10>/Signal Conversion'
   */
  Rte_IrvWrite_RE_AdvMinT_008_DRE_IgSys_ctLimAdvReact_irv(localOutDTConv_ki);
}

/* Output and update for exported function: RE_AdvMinT_001_MSE */
void RE_AdvMinT_001_MSE(void)
{
  UInt8 localSwitch_n2;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Init1'
   *
   * Block requirements for '<S1>/F01_Init1':
   *  1. SubSystem "F01_Init1" !Trace_To : VEMS_R_10_06440_044.03 ;
   *  2. SubSystem "F01_Init1" !Trace_To : VEMS_R_10_06440_069.02 ;
   */

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S95>/Byp_Fonction_SC'
   *  Constant: '<S95>/Int_BypC'
   *  Constant: '<S9>/Cste_1'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localSwitch_n2 = IgSys_agIgMin_B;
  } else {
    localSwitch_n2 = 96U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_agIgMinInport2' */
  Rte_Write_P_IgSys_agIgMin_IgSys_agIgMin(localSwitch_n2);
}

/* Start for exported function: RE_AdvMinT_002_DRE */
void RE_AdvMinT_002_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_IgAdvMinMgr'
   *
   * Block requirements for '<S1>/F01_IgAdvMinMgr':
   *  1. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_001.05 ;
   *  2. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_043.02 ;
   *  3. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_038.02 ;
   *  4. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_041.01 ;
   *  5. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_035.01 ;
   *  6. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_033.01 ;
   *  7. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_042.02 ;
   *  8. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_067.01 ;
   *  9. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_068.01 ;
   *  10. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_040.01 ;
   *  11. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_032.02 ;
   *  12. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_034.01 ;
   *  13. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_037.02 ;
   *  14. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_050.02 ;
   *  15. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_077.01 ;
   *  16. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_051.01 ;
   *  17. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_044.03 ;
   *  18. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_070.05 ;
   *  19. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_084.01 ;
   *  20. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_083.01 ;
   *  21. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_082.01 ;
   *  22. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_081.01 ;
   *  23. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_080.01 ;
   *  24. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_079.01 ;
   *  25. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_066.03 ;
   *  26. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_065.03 ;
   *  27. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_002.05 ;
   *  28. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_085.01 ;
   *  29. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_086.01 ;
   *  30. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_087.01 ;
   */

  /* Start for enable SubSystem: '<S7>/F02_Coordination' *
   * Block requirements for '<S7>/F02_Coordination':
   *  1. SubSystem "F02_Coordination" !Trace_To : VEMS_R_10_06440_004.05 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S13>/F01_Tempo_agr' *
   * Block requirements for '<S13>/F01_Tempo_agr':
   *  1. SubSystem "F01_Tempo_agr" !Trace_To : VEMS_R_10_06440_005.05 ;
   */

  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay' */
  AdvMinT_DWork.UnitDelay_DSTATE_a = MAX_uint8_T;

  /* InitializeConditions for UnitDelay: '<S42>/Unit Delay' */
  AdvMinT_DWork.UnitDelay_DSTATE_o = MAX_uint8_T;

  /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
  AdvMinT_DWork.UnitDelay_DSTATE_k = MAX_uint8_T;

  /* InitializeConditions for UnitDelay: '<S43>/Unit Delay' */
  AdvMinT_DWork.UnitDelay_DSTATE_k4 = MAX_uint8_T;

  /* InitializeConditions for UnitDelay: '<S44>/Unit Delay' */
  AdvMinT_DWork.UnitDelay_DSTATE_mx = MAX_uint8_T;

  /* InitializeConditions for UnitDelay: '<S45>/Unit Delay' */
  AdvMinT_DWork.UnitDelay_DSTATE_b = MAX_uint8_T;

  /* end of InitializeConditions for SubSystem: '<S13>/F01_Tempo_agr' */

  /* end of Start for SubSystem: '<S7>/F02_Coordination' */

  /* Start for enable SubSystem: '<S7>/F02_NOT' *
   * Block requirements for '<S7>/F02_NOT':
   *  1. SubSystem "F02_NOT" !Trace_To : VEMS_R_10_06440_003.01 ;
   */

  /* VirtualOutportStart for Outport: '<S14>/IgSys_agIgMin' */
  AdvMinT_B.Merge2 = 96U;

  /* end of Start for SubSystem: '<S7>/F02_NOT' */
}

/* Output and update for exported function: RE_AdvMinT_002_DRE */
void RE_AdvMinT_002_DRE(void)
{
  /* local block i/o variables */
  Boolean localLogic[2];
  Boolean localLogicalOperator25;
  Boolean localLogicalOperator1_o;
  UInt8 localTmpSignalConversionAtEng_s;
  UInt8 localTmpSignalConversionAtEng_n;
  Float32 localDataTypeConversion2;
  Float32 localInterpolationUsingPrelo_c5;
  Float32 localfractionTmp_0d;
  Float32 localfrac[2];
  Float32 localEngM_rAirLdCor_IgSys_rAirL;
  UInt32 localExt_nEng_IgSys_nEng_Cor_A_;
  UInt32 localbpIndex[2];
  UInt32 localEngM_rAirLdCor_IgSys_rAi_i;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Float32 localfrac_3[2];
  UInt32 localbpIndex_3[2];
  Boolean localLogicalOperator21[5];
  Boolean localLogicalOperator9[5];
  Float32 localSwitch2_hd[5];
  Boolean localSwitch_f[5];
  Boolean localLogicalOperator2;
  Float32 localSwitch_p[5];
  Boolean localLogicalOperator23;
  Boolean localLogicalOperator_j;
  Float32 localfrac_4[2];
  UInt32 localbpIndex_4[2];
  Float32 localSwitch8;
  Float32 localfrac_5[2];
  Float32 localInterpolationUsingPrelo_aq;
  UInt32 localExt_nEng_Ext_nEng_A_16_k_n;
  UInt32 localbpIndex_5[2];
  UInt32 localEngM_rAirLdCor_EngM_rAirLd;
  Float32 localfrac_6[2];
  UInt32 localbpIndex_6[2];
  Float32 localfrac_7[2];
  UInt32 localbpIndex_7[2];
  Float32 localfrac_8[2];
  UInt32 localbpIndex_8[2];
  Float32 localfrac_9[2];
  UInt32 localbpIndex_9[2];
  Float32 localfrac_a[2];
  UInt32 localbpIndex_a[2];
  Boolean localTmpSignalConversionAtFAR_m;
  Boolean localTmpSignalConversionAtCoP_n;
  Boolean localTmpSignalConversionAtCoCha;
  Boolean localTmpSignalConversionAtTqSys;
  Boolean localTmpSignalConversionAtTqS_g;
  Boolean localTmpSignalConversionAtIdlSy;
  Boolean localSwitch2_m2;
  Boolean localTmpSignalConversionAtIgS_f;
  Boolean localTmpSignalConversionAtAirSy;
  Boolean localTmpSignalConversionAtTPM_b;
  Boolean localLogicalOperator22[5];
  Float32 localSwitch2_f[5];
  Float32 localSwitch_j[5];
  UInt8 localTmpSignalConversionAtInjSy;
  Boolean localTmpSignalConversionAtCoEs_;
  Float32 localAdd2_a;
  UInt16 localTmpSignalConversionAtEx_ng;
  Boolean localTmpSignalConversionAtCoC_p;
  Float32 localSwitch13;
  Float32 localInterpolationUsingPreloo_h;
  Float32 localInterpolationUsingPreloo_p;
  SInt16 localTmpSignalConversionAtExt_n;
  UInt8 localTmpSignalConversionAtIgS_l;
  UInt8 localTmpSignalConversionAtIg_oz;
  UInt8 localTmpSignalConversionAtIgS_d;
  UInt8 localSwitch_d;
  UInt8 localSwitch3_k;
  UInt8 localSwitch1_e;
  UInt8 localSwitch4;
  UInt8 localSwitch5;
  UInt8 localTmpSignalConversionAtIgS_c;
  UInt8 localTmpSignalConversionAtExt_l;
  UInt8 localTmpSignalConversionAtIg_lp;
  UInt8 localTmpSignalConversionAtIg_p3;
  UInt16 localTmpSignalConversionAtExM_t;
  UInt8 localTmpSignalConversionAtIg_jw;
  UInt8 localTmpSignalConversionAtIgS_b;
  UInt16 localTmpSignalConversionAtEngM_;
  SInt32 locali;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_IgAdvMinMgr'
   *
   * Block requirements for '<S1>/F01_IgAdvMinMgr':
   *  1. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_001.05 ;
   *  2. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_043.02 ;
   *  3. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_038.02 ;
   *  4. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_041.01 ;
   *  5. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_035.01 ;
   *  6. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_033.01 ;
   *  7. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_042.02 ;
   *  8. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_067.01 ;
   *  9. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_068.01 ;
   *  10. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_040.01 ;
   *  11. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_032.02 ;
   *  12. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_034.01 ;
   *  13. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_037.02 ;
   *  14. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_050.02 ;
   *  15. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_077.01 ;
   *  16. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_051.01 ;
   *  17. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_044.03 ;
   *  18. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_070.05 ;
   *  19. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_084.01 ;
   *  20. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_083.01 ;
   *  21. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_082.01 ;
   *  22. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_081.01 ;
   *  23. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_080.01 ;
   *  24. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_079.01 ;
   *  25. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_066.03 ;
   *  26. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_065.03 ;
   *  27. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_002.05 ;
   *  28. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_085.01 ;
   *  29. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_086.01 ;
   *  30. SubSystem "F01_IgAdvMinMgr" !Trace_To : VEMS_R_10_06440_087.01 ;
   */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* Outputs for atomic SubSystem: '<S7>/F01_Condition_d_activation' *
   * Block requirements for '<S7>/F01_Condition_d_activation':
   *  1. SubSystem "F01_Condition_d_activation" !Trace_To : VEMS_R_10_06440_003.01 ;
   */

  /* RelationalOperator: '<S12>/Relational Operator' incorporates:
   *  Constant: '<S12>/Ext_stRun_SC'
   */
  IgSys_bAcvMinMgr = (localTmpSignalConversionAtEng_s == Ext_stRun_SC);

  /* end of Outputs for SubSystem: '<S7>/F01_Condition_d_activation' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_tCoStrtMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoStrtMes'
   */
  Rte_Read_R_Ext_tCoStrtMes_Ext_tCoStrtMes(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtEx_ng);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgMinStrtOutport2' */
  localTmpSignalConversionAtIgS_l =
    Rte_IrvRead_RE_AdvMinT_002_DRE_IgSys_agIgMinStrt_irv();

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgMinThermoOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMinThermo_INPUT'
   */
  Rte_Read_R_IgSys_agIgMinThermo_IgSys_agIgMinThermo
    (&localTmpSignalConversionAtIgS_b);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgMinDrivOutport2' */
  localTmpSignalConversionAtIg_oz =
    Rte_IrvRead_RE_AdvMinT_002_DRE_IgSys_agIgMinDriv_irv();

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIgS_f);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEng_noCmprCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprCyl'
   */
  Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl(&localTmpSignalConversionAtEng_n);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTqSys_bAcvCllOutport2' incorporates:
   *  Inport: '<Root>/TqSys_bAcvCll'
   */
  Rte_Read_R_TqSys_bAcvCll_TqSys_bAcvCll(&localTmpSignalConversionAtTqSys);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgSpOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgSp'
   */
  Rte_Read_R_IgSys_agIgSp_IgSys_agIgSp(&localTmpSignalConversionAtIg_jw);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIdlSys_bAcvIgMinSpcOutport2' incorporates:
   *  Inport: '<Root>/IdlSys_bAcvIgMinSpc'
   */
  Rte_Read_R_IdlSys_bAcvIgMinSpc_IdlSys_bAcvIgMinSpc
    (&localTmpSignalConversionAtIdlSy);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtCoEs_bAcvIgSysSTTEsOutport2' incorporates:
   *  Inport: '<Root>/CoEs_bAcvIgSysSTTEs'
   */
  Rte_Read_R_CoEs_bAcvIgSysSTTEs_CoEs_bAcvIgSysSTTEs
    (&localTmpSignalConversionAtCoEs_);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTPM_bExThermoProtOutport2' incorporates:
   *  Inport: '<Root>/TPM_bExThermoProt'
   */
  Rte_Read_R_TPM_bExThermoProt_TPM_bExThermoProt
    (&localTmpSignalConversionAtTPM_b);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgMinCmb_inputOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMinCmb_INPUT'
   */
  Rte_Read_R_IgSys_agIgMinCmb_IgSys_agIgMinCmb(&localTmpSignalConversionAtIgS_c);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtFARSp_bRichLoTqReqNotAuthOutport2' incorporates:
   *  Inport: '<Root>/FARSp_bRichLoTqReqNotAuth'
   */
  Rte_Read_R_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth
    (&localTmpSignalConversionAtFAR_m);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtCoPt_bSIPOutport2' incorporates:
   *  Inport: '<Root>/CoPt_bSIP'
   */
  Rte_Read_R_CoPt_bSIP_CoPt_bSIP(&localTmpSignalConversionAtCoP_n);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtCoCha_bTqReqASROutport2' incorporates:
   *  Inport: '<Root>/CoCha_bTqReqASR'
   */
  Rte_Read_R_CoCha_bTqReqASR_CoCha_bTqReqASR(&localTmpSignalConversionAtCoCha);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTqSys_bAOSAcvOutport2' incorporates:
   *  Inport: '<Root>/TqSys_bAOSAcv'
   */
  Rte_Read_R_TqSys_bAOSAcv_TqSys_bAOSAcv(&localTmpSignalConversionAtTqS_g);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgTarWiCllTarOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgTarWiCllTar'
   */
  Rte_Read_R_IgSys_agIgTarWiCllTar_IgSys_agIgTarWiCllTar
    (&localTmpSignalConversionAtIg_p3);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgLimMinKnkOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgLimMinKnk_INPUT'
   */
  Rte_Read_R_IgSys_agIgLimMinKnk_IgSys_agIgLimMinKnk
    (&localTmpSignalConversionAtIg_lp);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_tiTDCOutport2' incorporates:
   *  Inport: '<Root>/Ext_tiTDC'
   */
  Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&localTmpSignalConversionAtExt_l);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtCoCha_bASRSecuReqOutport2' incorporates:
   *  Inport: '<Root>/CoCha_bASRSecuReq'
   */
  Rte_Read_R_CoCha_bASRSecuReq_CoCha_bASRSecuReq
    (&localTmpSignalConversionAtCoC_p);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExDynOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExDyn'
   */
  Rte_Read_R_ExM_tExDyn_ExM_tExDyn(&localTmpSignalConversionAtExM_t);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_bActStraLimSurgeOutport2' incorporates:
   *  Inport: '<Root>/AirSys_bActStraLimSurge'
   */
  Rte_Read_R_AirSys_bActStraLimSurge_AirSys_bActStraLimSurge
    (&localTmpSignalConversionAtAirSy);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInjSys_noCylCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_noCylCutOff'
   */
  Rte_Read_R_InjSys_noCylCutOff_InjSys_noCylCutOff
    (&localTmpSignalConversionAtInjSy);

  /* Outputs for enable SubSystem: '<S7>/F02_Coordination' incorporates:
   *  EnablePort: '<S13>/IgSys_bAcvMinMgr'
   *
   * Block requirements for '<S7>/F02_Coordination':
   *  1. SubSystem "F02_Coordination" !Trace_To : VEMS_R_10_06440_004.05 ;
   */
  if (IgSys_bAcvMinMgr) {
    /* Outputs for atomic SubSystem: '<S13>/F01_Tempo_agr' *
     * Block requirements for '<S13>/F01_Tempo_agr':
     *  1. SubSystem "F01_Tempo_agr" !Trace_To : VEMS_R_10_06440_005.05 ;
     */

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     *  RelationalOperator: '<S16>/Relational Operator'
     *  UnitDelay: '<S41>/Unit Delay'
     */
    if (localTmpSignalConversionAtEng_n == 1) {
      localSwitch_d = localTmpSignalConversionAtIg_jw;
    } else {
      localSwitch_d = AdvMinT_DWork.UnitDelay_DSTATE_a;
    }

    /* Switch: '<S16>/Switch3' incorporates:
     *  Constant: '<S16>/Constant2'
     *  RelationalOperator: '<S16>/Relational Operator5'
     *  UnitDelay: '<S42>/Unit Delay'
     */
    if (localTmpSignalConversionAtEng_n == 2) {
      localSwitch3_k = localTmpSignalConversionAtIg_jw;
    } else {
      localSwitch3_k = AdvMinT_DWork.UnitDelay_DSTATE_o;
    }

    /* Switch: '<S16>/Switch1' incorporates:
     *  Constant: '<S16>/Constant3'
     *  RelationalOperator: '<S16>/Relational Operator4'
     *  UnitDelay: '<S40>/Unit Delay'
     */
    if (localTmpSignalConversionAtEng_n == 3) {
      localSwitch1_e = localTmpSignalConversionAtIg_jw;
    } else {
      localSwitch1_e = AdvMinT_DWork.UnitDelay_DSTATE_k;
    }

    /* Switch: '<S16>/Switch4' incorporates:
     *  Constant: '<S16>/Constant4'
     *  RelationalOperator: '<S16>/Relational Operator6'
     *  UnitDelay: '<S43>/Unit Delay'
     */
    if (localTmpSignalConversionAtEng_n == 4) {
      localSwitch4 = localTmpSignalConversionAtIg_jw;
    } else {
      localSwitch4 = AdvMinT_DWork.UnitDelay_DSTATE_k4;
    }

    /* Switch: '<S16>/Switch5' incorporates:
     *  Constant: '<S16>/Constant5'
     *  RelationalOperator: '<S16>/Relational Operator7'
     *  UnitDelay: '<S44>/Unit Delay'
     */
    if (localTmpSignalConversionAtEng_n == 5) {
      localSwitch5 = localTmpSignalConversionAtIg_jw;
    } else {
      localSwitch5 = AdvMinT_DWork.UnitDelay_DSTATE_mx;
    }

    /* Switch: '<S16>/Switch6' incorporates:
     *  Constant: '<S16>/Constant6'
     *  RelationalOperator: '<S16>/Relational Operator8'
     *  UnitDelay: '<S45>/Unit Delay'
     */
    if (localTmpSignalConversionAtEng_n != 6) {
      localTmpSignalConversionAtIg_jw = AdvMinT_DWork.UnitDelay_DSTATE_b;
    }

    /* MinMax: '<S16>/MinMax2' */
    localTmpSignalConversionAtEng_s = localSwitch_d;
    if (localSwitch3_k < localSwitch_d) {
      localTmpSignalConversionAtEng_s = localSwitch3_k;
    }

    if (localSwitch1_e < localTmpSignalConversionAtEng_s) {
      localTmpSignalConversionAtEng_s = localSwitch1_e;
    }

    if (localSwitch4 < localTmpSignalConversionAtEng_s) {
      localTmpSignalConversionAtEng_s = localSwitch4;
    }

    if (localSwitch5 < localTmpSignalConversionAtEng_s) {
      localTmpSignalConversionAtEng_s = localSwitch5;
    }

    if (localTmpSignalConversionAtIg_jw < localTmpSignalConversionAtEng_s) {
      localTmpSignalConversionAtEng_s = localTmpSignalConversionAtIg_jw;
    }

    IgSys_agIgSpDriv_MP = localTmpSignalConversionAtEng_s;

    /* RelationalOperator: '<S16>/Relational Operator3' */
    localLogicalOperator25 = (localTmpSignalConversionAtIgS_c <
      IgSys_agIgSpDriv_MP);

    /* Switch: '<S16>/Switch2' incorporates:
     *  Constant: '<S16>/Compteur'
     *  Constant: '<S16>/RAZ'
     *  RelationalOperator: '<S16>/Relational Operator2'
     *  Sum: '<S16>/Add1'
     *  UnitDelay: '<S46>/Unit Delay'
     */
    if (IgSys_agIgSpDriv_MP < localTmpSignalConversionAtIgS_c) {
      locali = AdvMinT_DWork.UnitDelay_DSTATE_ih + 1;
      if (((UInt32)locali) > 255U) {
        localTmpSignalConversionAtEng_s = MAX_uint8_T;
      } else {
        localTmpSignalConversionAtEng_s = (UInt8)locali;
      }
    } else {
      localTmpSignalConversionAtEng_s = 0U;
    }

    /* RelationalOperator: '<S16>/Relational Operator1' incorporates:
     *  Constant: '<S16>/IgSys_tAgIgMinDriv_C'
     */
    IgSys_bDriv_MP = (localTmpSignalConversionAtEng_s >= IgSys_tAgIgMinDriv_C);

    /* UnitDelay: '<S19>/UnitDelay' */
    localLogicalOperator1_o = AdvMinT_DWork.UnitDelay;

    /* CombinatorialLogic: '<S19>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator25 != 0);
      rowidx = (rowidx << 1) + (UInt32)(IgSys_bDriv_MP != 0);
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator1_o != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = AdvMinT_ConstP.Logic_table[rowidx];
      localLogic[1] = AdvMinT_ConstP.Logic_table[rowidx + 8];
    }

    /* UnitDelay: '<S19>/UnitDelay1' */
    localLogicalOperator1_o = AdvMinT_DWork.UnitDelay_l;

    /* Switch: '<S19>/Switch2' incorporates:
     *  Constant: '<S19>/NotCLR3'
     */
    if (localLogicalOperator1_o) {
      localSwitch2_m2 = localLogic[0];
    } else {
      localSwitch2_m2 = FALSE;
    }

    /* DataTypeConversion: '<S16>/Data Type Conversion2' */
    localDataTypeConversion2 = ((Float32)localTmpSignalConversionAtExt_l) *
      1.000000047E-003F;

    /* PreLookup: '<S34>/Prelookup' */
    localExt_nEng_IgSys_nEng_Cor_A_ = plook_u32u16f_binc
      (localTmpSignalConversionAtEx_ng, (&(IgSys_nEng_Cor_A[0])), 5U,
       &localInterpolationUsingPrelo_c5);

    /* PreLookup: '<S33>/Prelookup' */
    localEngM_rAirLdCor_IgSys_rAi_i = plook_u32u16f_binc
      (localTmpSignalConversionAtEngM_, (&(IgSys_rAirLdCor_Cor_A[0])), 6U,
       &localEngM_rAirLdCor_IgSys_rAirL);

    /* Interpolation_n-D: '<S21>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac[1] = localfractionTmp_0d;
    localbpIndex[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localInterpolationUsingPreloo_h = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex,
      localfrac, (&(IgSys_tiDlyAdvMinPrevAcv_M[0])), 6U);

    /* Interpolation_n-D: '<S25>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_0[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_0[1] = localfractionTmp_0d;
    localbpIndex_0[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_0[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localSwitch13 = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_0, localfrac_0,
      (&(IgSys_tiDlyAdvMinAOSAcv_M[0])), 6U);

    /* Interpolation_n-D: '<S26>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_1[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_1[1] = localfractionTmp_0d;
    localbpIndex_1[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_1[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localInterpolationUsingPrelo_aq = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_1,
      localfrac_1, (&(IgSys_tiDlyAdvMinGcAcv_M[0])), 6U);

    /* Interpolation_n-D: '<S27>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_2[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_2[1] = localfractionTmp_0d;
    localbpIndex_2[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_2[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localSwitch8 = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_2, localfrac_2,
      (&(IgSys_tiDlyAdvMinESPAcv_M[0])), 6U);

    /* Interpolation_n-D: '<S28>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_3[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_3[1] = localfractionTmp_0d;
    localbpIndex_3[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_3[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localInterpolationUsingPreloo_p = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_3,
      localfrac_3, (&(IgSys_tiDlyAdvMinLimSurgeAcv_M[0])), 6U);

    /* RelationalOperator: '<S61>/LowerRelop1' incorporates:
     *  Constant: '<S39>/Constant5'
     */
    localLogicalOperator21[0] = (localInterpolationUsingPreloo_h > 10000.0F);
    localLogicalOperator21[1] = (localSwitch13 > 10000.0F);
    localLogicalOperator21[2] = (localInterpolationUsingPrelo_aq > 10000.0F);
    localLogicalOperator21[3] = (localSwitch8 > 10000.0F);
    localLogicalOperator21[4] = (localInterpolationUsingPreloo_p > 10000.0F);

    /* RelationalOperator: '<S61>/UpperRelop' incorporates:
     *  Constant: '<S39>/Constant7'
     */
    localLogicalOperator9[0] = (localInterpolationUsingPreloo_h < 0.0F);
    localLogicalOperator9[1] = (localSwitch13 < 0.0F);
    localLogicalOperator9[2] = (localInterpolationUsingPrelo_aq < 0.0F);
    localLogicalOperator9[3] = (localSwitch8 < 0.0F);
    localLogicalOperator9[4] = (localInterpolationUsingPreloo_p < 0.0F);

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S39>/Constant7'
     */
    if (localLogicalOperator9[0]) {
      localSwitch2_hd[0] = 0.0F;
    } else {
      localSwitch2_hd[0] = localInterpolationUsingPreloo_h;
    }

    if (localLogicalOperator9[1]) {
      localSwitch2_hd[1] = 0.0F;
    } else {
      localSwitch2_hd[1] = localSwitch13;
    }

    if (localLogicalOperator9[2]) {
      localSwitch2_hd[2] = 0.0F;
    } else {
      localSwitch2_hd[2] = localInterpolationUsingPrelo_aq;
    }

    if (localLogicalOperator9[3]) {
      localSwitch2_hd[3] = 0.0F;
    } else {
      localSwitch2_hd[3] = localSwitch8;
    }

    if (localLogicalOperator9[4]) {
      localSwitch2_hd[4] = 0.0F;
    } else {
      localSwitch2_hd[4] = localInterpolationUsingPreloo_p;
    }

    /* UnitDelay: '<S65>/Unit Delay' */
    localLogicalOperator1_o = AdvMinT_DWork.UnitDelay_DSTATE_ej;
    for (locali = 0; locali < 5; locali++) {
      localAdd2_a = localSwitch2_hd[locali];

      /* Switch: '<S61>/Switch2' incorporates:
       *  Constant: '<S39>/Constant5'
       */
      if (localLogicalOperator21[locali]) {
        localAdd2_a = 10000.0F;
      }

      /* Switch: '<S47>/Switch' incorporates:
       *  Constant: '<S16>/Constant12'
       *  UnitDelay: '<S66>/Unit Delay'
       */
      if (localLogicalOperator1_o) {
        localLogicalOperator2 = AdvMinT_DWork.UnitDelay_DSTATE_m[(locali)];
      } else {
        localLogicalOperator2 = FALSE;
      }

      /* Sum: '<S39>/Sum3' incorporates:
       *  Logic: '<S39>/Logical Operator'
       *  Logic: '<S39>/Logical Operator1'
       *  Logic: '<S39>/Logical Operator3'
       *  Sum: '<S39>/Sum1'
       *  Switch: '<S39>/Switch3'
       *  UnitDelay: '<S39>/Unit Delay'
       *  UnitDelay: '<S39>/Unit Delay1'
       */
      if ((localLogicalOperator2) && (!AdvMinT_DWork.UnitDelay1_DSTATE[(locali)]))
      {
        localInterpolationUsingPreloo_p = localDataTypeConversion2 + localAdd2_a;
      } else {
        localInterpolationUsingPreloo_p = AdvMinT_DWork.UnitDelay_DSTATE_h
          [(locali)];
      }

      localInterpolationUsingPreloo_p -= localDataTypeConversion2;

      /* RelationalOperator: '<S39>/Relational Operator' incorporates:
       *  Constant: '<S39>/Constant1'
       */
      IgSys_prmTimerOut1_MP[(locali)] = (localInterpolationUsingPreloo_p > 0.0F);
      localSwitch_p[locali] = localInterpolationUsingPreloo_p;
      localSwitch_f[locali] = localLogicalOperator2;
      localSwitch2_hd[locali] = localAdd2_a;
    }

    /* Logic: '<S16>/Logical Operator23' */
    localLogicalOperator23 = ((((IgSys_prmTimerOut1_MP[0] ||
      IgSys_prmTimerOut1_MP[1]) || IgSys_prmTimerOut1_MP[2]) ||
      IgSys_prmTimerOut1_MP[3]) || IgSys_prmTimerOut1_MP[4]);

    /* UnitDelay: '<S48>/Unit Delay' */
    localLogicalOperator1_o = AdvMinT_DWork.UnitDelay_DSTATE_f;

    /* Logic: '<S20>/Logical Operator' incorporates:
     *  Logic: '<S20>/Logical Operator1'
     */
    localLogicalOperator_j = ((!localLogicalOperator23) &&
      (localLogicalOperator1_o));

    /* Interpolation_n-D: '<S22>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_4[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_4[1] = localfractionTmp_0d;
    localbpIndex_4[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_4[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localInterpolationUsingPreloo_p = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_4,
      localfrac_4, (&(IgSys_tiDlyAdvMinLimSurgeInh_M[0])), 6U);

    /* PreLookup: '<S36>/Prelookup' */
    localExt_nEng_Ext_nEng_A_16_k_n = plook_u32u16f_binc
      (localTmpSignalConversionAtEx_ng, (&(Ext_nEng_A[0])), 15U, &localSwitch8);

    /* PreLookup: '<S35>/Prelookup' */
    localEngM_rAirLdCor_EngM_rAirLd = plook_u32u16f_binc
      (localTmpSignalConversionAtEngM_, (&(EngM_rAirLdCor_A[0])), 11U,
       &localInterpolationUsingPrelo_aq);

    /* Interpolation_n-D: '<S23>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localSwitch8;
    localfrac_5[0] = localfractionTmp_0d;
    localfractionTmp_0d = localInterpolationUsingPrelo_aq;
    localfrac_5[1] = localfractionTmp_0d;
    localbpIndex_5[0] = localExt_nEng_Ext_nEng_A_16_k_n;
    localbpIndex_5[1] = localEngM_rAirLdCor_EngM_rAirLd;
    localSwitch13 = intrp2d_iu8n2ff_u32f_l_ns(localbpIndex_5, localfrac_5,
      (&(IgSys_agIgMinCANSIP_M[0])), 16U);

    /* Interpolation_n-D: '<S24>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localSwitch8;
    localfrac_6[0] = localfractionTmp_0d;
    localfractionTmp_0d = localInterpolationUsingPrelo_aq;
    localfrac_6[1] = localfractionTmp_0d;
    localbpIndex_6[0] = localExt_nEng_Ext_nEng_A_16_k_n;
    localbpIndex_6[1] = localEngM_rAirLdCor_EngM_rAirLd;
    localSwitch8 = intrp2d_iu8n2ff_u32f_l_ns(localbpIndex_6, localfrac_6,
      (&(IgSys_agIgMinCANESP_M[0])), 16U);

    /* Interpolation_n-D: '<S29>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_7[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_7[1] = localfractionTmp_0d;
    localbpIndex_7[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_7[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localInterpolationUsingPrelo_aq = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_7,
      localfrac_7, (&(IgSys_tiDlyAdvMinPrevInh_M[0])), 6U);

    /* Interpolation_n-D: '<S30>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_8[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_8[1] = localfractionTmp_0d;
    localbpIndex_8[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_8[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localInterpolationUsingPreloo_h = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_8,
      localfrac_8, (&(IgSys_tiDlyAdvMinAOSInh_M[0])), 6U);

    /* Interpolation_n-D: '<S31>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_9[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_9[1] = localfractionTmp_0d;
    localbpIndex_9[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_9[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localAdd2_a = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_9, localfrac_9,
      (&(IgSys_tiDlyAdvMinGcInh_M[0])), 6U);

    /* Interpolation_n-D: '<S32>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_c5;
    localfrac_a[0] = localfractionTmp_0d;
    localfractionTmp_0d = localEngM_rAirLdCor_IgSys_rAirL;
    localfrac_a[1] = localfractionTmp_0d;
    localbpIndex_a[0] = localExt_nEng_IgSys_nEng_Cor_A_;
    localbpIndex_a[1] = localEngM_rAirLdCor_IgSys_rAi_i;
    localInterpolationUsingPrelo_c5 = intrp2d_iu16n13ff_u32f_l_ns__1(localbpIndex_a,
      localfrac_a, (&(IgSys_tiDlyAdvMinESPInh_M[0])), 6U);

    /* Logic: '<S16>/Logical Operator1' incorporates:
     *  Constant: '<S16>/IgSys_bAcvAdvMinLimSurge_C'
     */
    localLogicalOperator1_o = ((localTmpSignalConversionAtAirSy) &&
      IgSys_bAcvAdvMinLimSurge_C);

    /* Logic: '<S16>/Logical Operator25' incorporates:
     *  Constant: '<S16>/IgSys_bAcvAdvMinPrevAAMin_C'
     */
    localLogicalOperator25 = ((localTmpSignalConversionAtTqSys) &&
      IgSys_bAcvAdvMinPrevAAMin_C);

    /* SignalConversion: '<S16>/Signal Conversion' incorporates:
     *  Constant: '<S16>/IgSys_bAcvAdvMinCurAAMin_C'
     *  Constant: '<S16>/IgSys_bAcvAdvMinESPASR_C1'
     *  Constant: '<S16>/IgSys_bAcvAdvMinSIP_C1'
     *  Logic: '<S16>/Logical Operator14'
     *  Logic: '<S16>/Logical Operator26'
     *  Logic: '<S16>/Logical Operator27'
     */
    IgSys_prmInhThermoProt_MP[0] = localLogicalOperator25;
    IgSys_prmInhThermoProt_MP[1] = ((localTmpSignalConversionAtTqS_g) &&
      IgSys_bAcvAdvMinCurAAMin_C);
    IgSys_prmInhThermoProt_MP[2] = ((localTmpSignalConversionAtCoP_n) &&
      IgSys_bAcvAdvMinSIP_C);
    IgSys_prmInhThermoProt_MP[3] = ((localTmpSignalConversionAtCoCha) &&
      IgSys_bAcvAdvMinESPASR_C);
    IgSys_prmInhThermoProt_MP[4] = localLogicalOperator1_o;

    /* RelationalOperator: '<S53>/LowerRelop1' incorporates:
     *  Constant: '<S38>/Constant5'
     */
    localLogicalOperator21[0] = (localInterpolationUsingPrelo_aq > 10000.0F);
    localLogicalOperator21[1] = (localInterpolationUsingPreloo_h > 10000.0F);
    localLogicalOperator21[2] = (localAdd2_a > 10000.0F);
    localLogicalOperator21[3] = (localInterpolationUsingPrelo_c5 > 10000.0F);
    localLogicalOperator21[4] = (localInterpolationUsingPreloo_p > 10000.0F);

    /* RelationalOperator: '<S53>/UpperRelop' incorporates:
     *  Constant: '<S38>/Constant7'
     */
    localLogicalOperator22[0] = (localInterpolationUsingPrelo_aq < 0.0F);
    localLogicalOperator22[1] = (localInterpolationUsingPreloo_h < 0.0F);
    localLogicalOperator22[2] = (localAdd2_a < 0.0F);
    localLogicalOperator22[3] = (localInterpolationUsingPrelo_c5 < 0.0F);
    localLogicalOperator22[4] = (localInterpolationUsingPreloo_p < 0.0F);

    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S38>/Constant7'
     */
    if (localLogicalOperator22[0]) {
      localSwitch2_f[0] = 0.0F;
    } else {
      localSwitch2_f[0] = localInterpolationUsingPrelo_aq;
    }

    if (localLogicalOperator22[1]) {
      localSwitch2_f[1] = 0.0F;
    } else {
      localSwitch2_f[1] = localInterpolationUsingPreloo_h;
    }

    if (localLogicalOperator22[2]) {
      localSwitch2_f[2] = 0.0F;
    } else {
      localSwitch2_f[2] = localAdd2_a;
    }

    if (localLogicalOperator22[3]) {
      localSwitch2_f[3] = 0.0F;
    } else {
      localSwitch2_f[3] = localInterpolationUsingPrelo_c5;
    }

    if (localLogicalOperator22[4]) {
      localSwitch2_f[4] = 0.0F;
    } else {
      localSwitch2_f[4] = localInterpolationUsingPreloo_p;
    }

    for (locali = 0; locali < 5; locali++) {
      localInterpolationUsingPreloo_p = localSwitch2_f[locali];

      /* Logic: '<S16>/Logical Operator9' */
      localLogicalOperator9[locali] = ((localTmpSignalConversionAtTPM_b) &&
        IgSys_prmInhThermoProt_MP[(locali)]);

      /* Switch: '<S53>/Switch2' incorporates:
       *  Constant: '<S38>/Constant5'
       */
      if (localLogicalOperator21[locali]) {
        localInterpolationUsingPreloo_p = 10000.0F;
      }

      /* UnitDelay: '<S38>/Unit Delay' */
      localSwitch_j[locali] = AdvMinT_DWork.UnitDelay_DSTATE_eb[(locali)];
      localSwitch2_f[locali] = localInterpolationUsingPreloo_p;
    }

    /* Switch: '<S38>/Switch3' incorporates:
     *  Constant: '<S16>/Constant7'
     *  Logic: '<S38>/Logical Operator'
     *  Logic: '<S38>/Logical Operator1'
     *  Logic: '<S38>/Logical Operator2'
     *  Logic: '<S38>/Logical Operator3'
     *  Sum: '<S38>/Sum1'
     *  UnitDelay: '<S38>/Unit Delay1'
     */
    if ((localLogicalOperator_j) && (!AdvMinT_DWork.UnitDelay1_DSTATE_n)) {
      for (locali = 0; locali < 5; locali++) {
        localSwitch_j[locali] = localDataTypeConversion2 + localSwitch2_f[locali];
      }
    }

    for (locali = 0; locali < 5; locali++) {
      localInterpolationUsingPreloo_p = localSwitch_p[locali];
      localAdd2_a = localSwitch2_hd[locali];

      /* Sum: '<S38>/Sum3' */
      localfractionTmp_0d = localSwitch_j[locali] - localDataTypeConversion2;

      /* RelationalOperator: '<S38>/Relational Operator' incorporates:
       *  Constant: '<S38>/Constant1'
       */
      IgSys_prmTimerOut2_MP[(locali)] = (localfractionTmp_0d > 0.0F);

      /* Logic: '<S16>/Logical Operator22' */
      localLogicalOperator2 = !IgSys_prmTimerOut2_MP[(locali)];

      /* Logic: '<S16>/Logical Operator21' */
      localLogicalOperator21[locali] = ((localLogicalOperator9[locali]) &&
        (localLogicalOperator2));

      /* Switch: '<S64>/Switch' incorporates:
       *  Constant: '<S39>/Constant1'
       *  RelationalOperator: '<S64>/UpperRelop'
       */
      if (localSwitch_p[locali] < 0.0F) {
        localInterpolationUsingPreloo_p = 0.0F;
      }

      /* Switch: '<S64>/Switch2' incorporates:
       *  RelationalOperator: '<S64>/LowerRelop1'
       */
      if (!(localSwitch_p[locali] > localSwitch2_hd[locali])) {
        localAdd2_a = localInterpolationUsingPreloo_p;
      }

      /* Logic: '<S16>/Logical Operator18' incorporates:
       *  Constant: '<S16>/Constant15'
       *  RelationalOperator: '<S16>/Relational Operator10'
       */
      IgSys_prmTimerIn1_MP[(locali)] = ((localAdd2_a > 0.0F) &&
        (localSwitch_f[locali]));
      localLogicalOperator22[locali] = localLogicalOperator2;
      localSwitch_j[locali] = localfractionTmp_0d;
      localSwitch2_hd[locali] = localAdd2_a;
    }

    /* RelationalOperator: '<S16>/Relational Operator9' */
    localLogicalOperator2 = (localTmpSignalConversionAtIg_p3 <
      localTmpSignalConversionAtIg_lp);

    /* Logic: '<S16>/Logical Operator4' incorporates:
     *  Constant: '<S16>/IgSys_bAcvAdvMinESPASR_C'
     *  Constant: '<S16>/IgSys_bAcvAdvMinSIP_C'
     *  Constant: '<S16>/IgSys_bRichLoTqAuth_C'
     *  Constant: '<S16>/IgSys_idxAdvMinESPASR_C'
     *  Constant: '<S16>/IgSys_idxAdvMinSIP_C'
     *  Logic: '<S16>/Logical Operator'
     *  Logic: '<S16>/Logical Operator10'
     *  Logic: '<S16>/Logical Operator12'
     *  Logic: '<S16>/Logical Operator15'
     *  Logic: '<S16>/Logical Operator17'
     *  Logic: '<S16>/Logical Operator3'
     *  Logic: '<S16>/Logical Operator5'
     *  Logic: '<S16>/Logical Operator7'
     */
    IgSys_bDriv = (((((localSwitch2_m2) && (!((localTmpSignalConversionAtFAR_m) &&
      IgSys_bRichLoTqAuth_C))) && (localTmpSignalConversionAtIgS_f)) &&
                    (((((localTmpSignalConversionAtTqSys) ||
                        (localTmpSignalConversionAtTqS_g)) ||
                       (localTmpSignalConversionAtIdlSy)) ||
                      (((localTmpSignalConversionAtCoP_n) &&
                        IgSys_bAcvAdvMinSIP_C) && (!IgSys_idxAdvMinSIP_C))) ||
                     (((localTmpSignalConversionAtCoCha) &&
                       IgSys_bAcvAdvMinESPASR_C) && (!IgSys_idxAdvMinESPASR_C))))
                   || (localTmpSignalConversionAtCoEs_));

    /* Switch: '<S16>/Switch12' incorporates:
     *  Constant: '<S16>/IgSys_tExMax_C'
     *  Constant: '<S16>/IgSys_tExMax_C1'
     */
    if (localTmpSignalConversionAtCoC_p) {
      localTmpSignalConversionAtEngM_ = IgSys_tExMaxASR_C;
    } else {
      localTmpSignalConversionAtEngM_ = IgSys_tExMax_C;
    }

    /* Switch: '<S16>/Switch10' incorporates:
     *  Constant: '<S16>/Constant'
     *  Logic: '<S16>/Logical Operator13'
     *  Logic: '<S16>/Logical Operator20'
     */
    if (((((localLogicalOperator21[0]) || (localLogicalOperator21[1])) ||
          (localLogicalOperator21[2])) || (localLogicalOperator21[3])) ||
        (localLogicalOperator21[4])) {
      localTmpSignalConversionAtTPM_b = FALSE;
    }

    /* Switch: '<S16>/Switch7' incorporates:
     *  Constant: '<S16>/Constant8'
     */
    if (localTmpSignalConversionAtCoC_p) {
      localTmpSignalConversionAtTPM_b = FALSE;
    }

    /* Switch: '<S16>/Switch9' incorporates:
     *  Constant: '<S16>/Constant9'
     *  RelationalOperator: '<S16>/Relational Operator11'
     */
    if (localTmpSignalConversionAtExM_t >= localTmpSignalConversionAtEngM_) {
      localTmpSignalConversionAtTPM_b = TRUE;
    }

    /* Logic: '<S16>/Logical Operator6' incorporates:
     *  Constant: '<S16>/Constant10'
     *  Constant: '<S16>/Constant11'
     *  Constant: '<S16>/IgSys_tExMax_C2'
     *  Logic: '<S16>/Logical Operator2'
     *  Logic: '<S16>/Logical Operator28'
     *  RelationalOperator: '<S16>/Relational Operator12'
     *  RelationalOperator: '<S16>/Relational Operator13'
     */
    IgSys_bExThermoProt = ((!((InjSys_noCylCutOffInh_C != 0) &&
      (localTmpSignalConversionAtInjSy > 0))) &&
      (localTmpSignalConversionAtTPM_b));

    /* Switch: '<S16>/Switch13' incorporates:
     *  Constant: '<S16>/IgSys_bAcvAdvMinSIP_C'
     *  Constant: '<S16>/IgSys_idxAdvMinSIP_C'
     *  Logic: '<S16>/Logical Operator16'
     */
    if (!((IgSys_idxAdvMinSIP_C && IgSys_bAcvAdvMinSIP_C) &&
          (localTmpSignalConversionAtCoP_n))) {
      localSwitch13 = (((Float32)localTmpSignalConversionAtIgS_c) * 0.375F) -
        36.0F;
    }

    /* Switch: '<S16>/Switch8' incorporates:
     *  Constant: '<S16>/IgSys_bAcvAdvMinESPASR_C'
     *  Constant: '<S16>/IgSys_idxAdvMinESPASR_C'
     *  Logic: '<S16>/Logical Operator11'
     */
    if (!((IgSys_idxAdvMinESPASR_C && IgSys_bAcvAdvMinESPASR_C) &&
          (localTmpSignalConversionAtCoCha))) {
      localSwitch8 = localSwitch13;
    }

    /* Sum: '<S37>/Add1' incorporates:
     *  Constant: '<S37>/offset'
     */
    localfractionTmp_0d = localSwitch8 - -36.0F;

    /* DataTypeConversion: '<S37>/OutDTConv' incorporates:
     *  Constant: '<S37>/offset1'
     *  Constant: '<S37>/one_on_slope'
     *  Product: '<S37>/Product4'
     *  Sum: '<S37>/Add2'
     */
    localInterpolationUsingPreloo_p = (2.666666746E+000F * localfractionTmp_0d)
      + 0.5F;
    if (localInterpolationUsingPreloo_p < 256.0F) {
      if (localInterpolationUsingPreloo_p >= 0.0F) {
        IgSys_agIgMinCmbWiCANSpcReq = (UInt8)localInterpolationUsingPreloo_p;
      } else {
        IgSys_agIgMinCmbWiCANSpcReq = 0U;
      }
    } else {
      IgSys_agIgMinCmbWiCANSpcReq = MAX_uint8_T;
    }

    /* Update for UnitDelay: '<S46>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_ih = localTmpSignalConversionAtEng_s;

    /* Update for UnitDelay: '<S41>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_a = localSwitch_d;

    /* Update for UnitDelay: '<S42>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_o = localSwitch3_k;

    /* Update for UnitDelay: '<S40>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_k = localSwitch1_e;

    /* Update for UnitDelay: '<S43>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_k4 = localSwitch4;

    /* Update for UnitDelay: '<S44>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_mx = localSwitch5;

    /* Update for UnitDelay: '<S45>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_b = localTmpSignalConversionAtIg_jw;

    /* Update for UnitDelay: '<S19>/UnitDelay' */
    AdvMinT_DWork.UnitDelay = localSwitch2_m2;

    /* Update for UnitDelay: '<S19>/UnitDelay1' incorporates:
     *  Constant: '<S19>/NotCLR2'
     */
    AdvMinT_DWork.UnitDelay_l = TRUE;

    /* Update for UnitDelay: '<S65>/Unit Delay' incorporates:
     *  Constant: '<S47>/Constant3'
     */
    AdvMinT_DWork.UnitDelay_DSTATE_ej = TRUE;

    /* Update for UnitDelay: '<S48>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_f = localLogicalOperator23;

    /* Update for UnitDelay: '<S38>/Unit Delay1' */
    AdvMinT_DWork.UnitDelay1_DSTATE_n = localLogicalOperator_j;
    for (locali = 0; locali < 5; locali++) {
      localInterpolationUsingPreloo_p = localSwitch_j[locali];

      /* Switch: '<S56>/Switch' incorporates:
       *  Constant: '<S38>/Constant1'
       *  RelationalOperator: '<S56>/UpperRelop'
       */
      if (localSwitch_j[locali] < 0.0F) {
        localInterpolationUsingPreloo_p = 0.0F;
      }

      /* Update for UnitDelay: '<S66>/Unit Delay' incorporates:
       *  Constant: '<S16>/Constant16'
       *  Constant: '<S16>/Constant17'
       *  Logic: '<S16>/Logical Operator19'
       *  Logic: '<S16>/Logical Operator8'
       *  Switch: '<S16>/Switch11'
       */
      if ((((localLogicalOperator9[locali]) && (localLogicalOperator22[locali]))
           && (localLogicalOperator2)) || IgSys_prmTimerIn1_MP[(locali)]) {
        AdvMinT_DWork.UnitDelay_DSTATE_m[(locali)] = TRUE;
      } else {
        AdvMinT_DWork.UnitDelay_DSTATE_m[(locali)] = FALSE;
      }

      /* Update for UnitDelay: '<S39>/Unit Delay1' */
      AdvMinT_DWork.UnitDelay1_DSTATE[(locali)] = localSwitch_f[locali];

      /* Update for UnitDelay: '<S39>/Unit Delay' */
      AdvMinT_DWork.UnitDelay_DSTATE_h[(locali)] = localSwitch2_hd[locali];

      /* Update for UnitDelay: '<S38>/Unit Delay' incorporates:
       *  RelationalOperator: '<S56>/LowerRelop1'
       *  Switch: '<S56>/Switch2'
       */
      if (localSwitch_j[locali] > localSwitch2_f[locali]) {
        AdvMinT_DWork.UnitDelay_DSTATE_eb[(locali)] = localSwitch2_f[locali];
      } else {
        AdvMinT_DWork.UnitDelay_DSTATE_eb[(locali)] =
          localInterpolationUsingPreloo_p;
      }
    }

    /* end of Outputs for SubSystem: '<S13>/F01_Tempo_agr' */

    /* Outputs for atomic SubSystem: '<S13>/F02_Pentes' *
     * Block requirements for '<S13>/F02_Pentes':
     *  1. SubSystem "F02_Pentes" !Trace_To : VEMS_R_10_06440_006.01 ;
     */

    /* Product: '<S73>/Divide' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/IgSys_bAcvAgIgMinDrivOfs_C'
     *  Constant: '<S17>/passage_en_min'
     *  DataTypeConversion: '<S17>/Data Type Conversion1'
     *  DataTypeConversion: '<S17>/Data Type Conversion2'
     *  Product: '<S71>/Divide'
     *  Product: '<S72>/Divide'
     */
    localfractionTmp_0d = (((Float32)localTmpSignalConversionAtEx_ng) / 60.0F) *
      (((Float32)Ext_noCylEng_SC) / 2.0F);

    /* MinMax: '<S17>/MinMax' incorporates:
     *  Constant: '<S17>/Constant2'
     */
    localInterpolationUsingPreloo_h = rt_MAXf(localfractionTmp_0d, 1.0F);

    /* Outputs for atomic SubSystem: '<S17>/F01_Conversion_pente1' *
     * Block requirements for '<S17>/F01_Conversion_pente1':
     *  1. SubSystem "F01_Conversion_pente1" !Trace_To : VEMS_R_10_06440_007.02 ;
     */

    /* Sum: '<S67>/Sum1' incorporates:
     *  Lookup_n-D: '<S74>/Lookup Table (n-D)'
     *  Product: '<S77>/Divide'
     *  UnitDelay: '<S76>/Unit Delay'
     */
    localInterpolationUsingPreloo_p = (look1_is16lftu16p1If_binlcs
      (localTmpSignalConversionAtExt_n, (&(IgSys_tCoAgIgMinX_A[0])),
       (&(IgSys_agIgMinStrtDecOfs_T[0])), 7U) / localInterpolationUsingPreloo_h)
      + AdvMinT_DWork.UnitDelay_DSTATE_n;

    /* Math: '<S67>/Math Function' incorporates:
     *  Constant: '<S67>/passage_en_min1'
     */
    localfractionTmp_0d = rt_rem32(localInterpolationUsingPreloo_p, 0.375F);

    /* DataTypeConversion: '<S75>/OutDTConv' incorporates:
     *  Constant: '<S75>/offset'
     *  Constant: '<S75>/offset1'
     *  Constant: '<S75>/one_on_slope'
     *  Product: '<S75>/Product4'
     *  Sum: '<S67>/Sum2'
     *  Sum: '<S75>/Add1'
     *  Sum: '<S75>/Add2'
     */
    localInterpolationUsingPreloo_p = (((localInterpolationUsingPreloo_p -
      localfractionTmp_0d) - -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localInterpolationUsingPreloo_p < 256.0F) {
      if (localInterpolationUsingPreloo_p >= 0.0F) {
        IgSys_agIgSlopStrtDec = (UInt8)localInterpolationUsingPreloo_p;
      } else {
        IgSys_agIgSlopStrtDec = 0U;
      }
    } else {
      IgSys_agIgSlopStrtDec = MAX_uint8_T;
    }

    /* Update for UnitDelay: '<S76>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_n = localfractionTmp_0d;

    /* end of Outputs for SubSystem: '<S17>/F01_Conversion_pente1' */

    /* Outputs for atomic SubSystem: '<S17>/F02_Conversion_pente2' *
     * Block requirements for '<S17>/F02_Conversion_pente2':
     *  1. SubSystem "F02_Conversion_pente2" !Trace_To : VEMS_R_10_06440_008.02 ;
     */

    /* Sum: '<S68>/Sum1' incorporates:
     *  Constant: '<S68>/IgSys_agIgMinDrivIncOfs_C'
     *  DataTypeConversion: '<S68>/Data Type Conversion9'
     *  Product: '<S80>/Divide'
     *  UnitDelay: '<S79>/Unit Delay'
     */
    localfractionTmp_0d = ((((Float32)IgSys_agIgMinDrivIncOfs_C) * 2.0F) /
      localInterpolationUsingPreloo_h) + AdvMinT_DWork.UnitDelay_DSTATE_i;

    /* Math: '<S68>/Math Function' incorporates:
     *  Constant: '<S68>/passage_en_min1'
     */
    localAdd2_a = rt_rem32(localfractionTmp_0d, 0.375F);

    /* DataTypeConversion: '<S78>/OutDTConv' incorporates:
     *  Constant: '<S78>/offset'
     *  Constant: '<S78>/offset1'
     *  Constant: '<S78>/one_on_slope'
     *  Product: '<S78>/Product4'
     *  Sum: '<S68>/Sum2'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Add2'
     */
    localInterpolationUsingPreloo_p = (((localfractionTmp_0d - localAdd2_a) -
      -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localInterpolationUsingPreloo_p < 256.0F) {
      if (localInterpolationUsingPreloo_p >= 0.0F) {
        IgSys_agIgSlopDrivInc = (UInt8)localInterpolationUsingPreloo_p;
      } else {
        IgSys_agIgSlopDrivInc = 0U;
      }
    } else {
      IgSys_agIgSlopDrivInc = MAX_uint8_T;
    }

    /* Update for UnitDelay: '<S79>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_i = localAdd2_a;

    /* end of Outputs for SubSystem: '<S17>/F02_Conversion_pente2' */

    /* Outputs for atomic SubSystem: '<S17>/F03_Conversion_pente3' *
     * Block requirements for '<S17>/F03_Conversion_pente3':
     *  1. SubSystem "F03_Conversion_pente3" !Trace_To : VEMS_R_10_06440_009.03 ;
     */

    /* DataTypeConversion: '<S69>/Data Type Conversion9' incorporates:
     *  Constant: '<S69>/IgSys_agIgMinThermoIncOfs_C'
     */
    localfractionTmp_0d = ((Float32)IgSys_agIgMinThermoIncOfs_C) * 2.0F;

    /* Switch: '<S69>/Switch3' incorporates:
     *  Product: '<S83>/Divide'
     */
    if (!localTmpSignalConversionAtCoP_n) {
      localfractionTmp_0d /= localInterpolationUsingPreloo_h;
    }

    /* Sum: '<S69>/Sum1' incorporates:
     *  UnitDelay: '<S82>/Unit Delay'
     */
    localfractionTmp_0d += AdvMinT_DWork.UnitDelay_DSTATE_e;

    /* Math: '<S69>/Math Function' incorporates:
     *  Constant: '<S69>/passage_en_min1'
     */
    localAdd2_a = rt_rem32(localfractionTmp_0d, 0.375F);

    /* DataTypeConversion: '<S81>/OutDTConv' incorporates:
     *  Constant: '<S81>/offset'
     *  Constant: '<S81>/offset1'
     *  Constant: '<S81>/one_on_slope'
     *  Product: '<S81>/Product4'
     *  Sum: '<S69>/Sum2'
     *  Sum: '<S81>/Add1'
     *  Sum: '<S81>/Add2'
     */
    localInterpolationUsingPreloo_p = (((localfractionTmp_0d - localAdd2_a) -
      -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localInterpolationUsingPreloo_p < 256.0F) {
      if (localInterpolationUsingPreloo_p >= 0.0F) {
        IgSys_agIgSlopThermoInc = (UInt8)localInterpolationUsingPreloo_p;
      } else {
        IgSys_agIgSlopThermoInc = 0U;
      }
    } else {
      IgSys_agIgSlopThermoInc = MAX_uint8_T;
    }

    /* Update for UnitDelay: '<S82>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE_e = localAdd2_a;

    /* end of Outputs for SubSystem: '<S17>/F03_Conversion_pente3' */

    /* Outputs for atomic SubSystem: '<S17>/F04_Conversion_pente4' *
     * Block requirements for '<S17>/F04_Conversion_pente4':
     *  1. SubSystem "F04_Conversion_pente4" !Trace_To : VEMS_R_10_06440_010.03 ;
     */

    /* DataTypeConversion: '<S70>/Data Type Conversion9' incorporates:
     *  Constant: '<S70>/IgSys_agIgMinThermoDecOfs_C'
     */
    localAdd2_a = ((Float32)IgSys_agIgMinThermoDecOfs_C) * 2.0F;

    /* Switch: '<S70>/Switch3' incorporates:
     *  Product: '<S86>/Divide'
     */
    if (!localTmpSignalConversionAtCoP_n) {
      localAdd2_a /= localInterpolationUsingPreloo_h;
    }

    /* Sum: '<S70>/Sum1' incorporates:
     *  UnitDelay: '<S85>/Unit Delay'
     */
    localAdd2_a += AdvMinT_DWork.UnitDelay_DSTATE;

    /* Math: '<S70>/Math Function' incorporates:
     *  Constant: '<S70>/passage_en_min1'
     */
    localfractionTmp_0d = rt_rem32(localAdd2_a, 0.375F);

    /* DataTypeConversion: '<S84>/OutDTConv' incorporates:
     *  Constant: '<S84>/offset'
     *  Constant: '<S84>/offset1'
     *  Constant: '<S84>/one_on_slope'
     *  Product: '<S84>/Product4'
     *  Sum: '<S70>/Sum2'
     *  Sum: '<S84>/Add1'
     *  Sum: '<S84>/Add2'
     */
    localInterpolationUsingPreloo_p = (((localAdd2_a - localfractionTmp_0d) -
      -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localInterpolationUsingPreloo_p < 256.0F) {
      if (localInterpolationUsingPreloo_p >= 0.0F) {
        IgSys_agIgSlopThermoDec = (UInt8)localInterpolationUsingPreloo_p;
      } else {
        IgSys_agIgSlopThermoDec = 0U;
      }
    } else {
      IgSys_agIgSlopThermoDec = MAX_uint8_T;
    }

    /* Update for UnitDelay: '<S85>/Unit Delay' */
    AdvMinT_DWork.UnitDelay_DSTATE = localfractionTmp_0d;

    /* end of Outputs for SubSystem: '<S17>/F04_Conversion_pente4' */

    /* end of Outputs for SubSystem: '<S13>/F02_Pentes' */

    /* Outputs for atomic SubSystem: '<S13>/F03_Choix_avance' *
     * Block requirements for '<S13>/F03_Choix_avance':
     *  1. SubSystem "F03_Choix_avance" !Trace_To : VEMS_R_10_06440_011.03 ;
     */

    /* *
     * Block requirements for '<S18>/F01_State_avmin':
     *  1. SubSystem "F01_State_avmin" !Trace_To : VEMS_R_10_06440_011.03 ;
     */

    /* Stateflow: '<S18>/F01_State_avmin' */
    /* Gateway: AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F03_Choix_avance/F01_State_avmin */
    /* During: AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F03_Choix_avance/F01_State_avmin */
    if (AdvMinT_DWork.is_active_c2_AdvMinT == 0) {
      /* Entry: AdvMinT/F01_IgAdvMinMgr/F02_Coordination/F03_Choix_avance/F01_State_avmin */
      AdvMinT_DWork.is_active_c2_AdvMinT = 1U;

      /* Transition: '<S87>:9' */
      /* Entry 'DEPART': '<S87>:1' */
      AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
      AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
    } else {
      switch (AdvMinT_DWork.is_c2_AdvMinT) {
       case IN_AGREMENT:
        /* During 'AGREMENT': '<S87>:4' */
        if (((SInt32)localTmpSignalConversionAtIgS_f) == 0) {
          /* Transition: '<S87>:14' */
          /* Exit 'AGREMENT': '<S87>:4' */
          /* Entry 'DEPART': '<S87>:1' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        } else if ((((SInt32)IgSys_bDriv) == 0) && (((SInt32)
                     IgSys_bExThermoProt) == 0)) {
          /* Transition: '<S87>:16' */
          /* Exit 'AGREMENT': '<S87>:4' */
          /* Entry 'TRANSITION_AGR_mini_comb': '<S87>:6' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_TRANSITION_AGR_mini_comb;
          localfractionTmp_0d = (((Float32)(AdvMinT_B.Merge2 +
            IgSys_agIgSlopDrivInc)) * 0.375F) - 72.0F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MINf(localfractionTmp_0d,
            (((Float32)IgSys_agIgMinCmbWiCANSpcReq) * 0.375F) - 36.0F)) + 36.0F)
            / 0.375F);
        } else if ((((SInt32)IgSys_bExThermoProt) == 1) &&
                   (localTmpSignalConversionAtIg_oz <=
                    localTmpSignalConversionAtIgS_b)) {
          /* Transition: '<S87>:24' */
          /* Exit 'AGREMENT': '<S87>:4' */
          /* Entry 'TRANSITION_mini_comb_prot_Comp': '<S87>:7' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_TRANSITION_mini_comb_prot_Co;
          localfractionTmp_0d = (((Float32)(AdvMinT_B.Merge2 +
            IgSys_agIgSlopThermoInc)) * 0.375F) - 72.0F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MINf(localfractionTmp_0d,
            (((Float32)localTmpSignalConversionAtIgS_b) * 0.375F) - 36.0F)) +
            36.0F) / 0.375F);
        } else {
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIg_oz;
        }
        break;

       case IN_DEPART:
        /* During 'DEPART': '<S87>:1' */
        if (((SInt32)localTmpSignalConversionAtIgS_f) == 1) {
          /* Transition: '<S87>:10' */
          /* Exit 'DEPART': '<S87>:1' */
          /* Entry 'SORTIE_DEPART': '<S87>:2' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_SORTIE_DEPART;
          localfractionTmp_0d = ((Float32)(AdvMinT_B.Merge2 -
            IgSys_agIgSlopStrtDec)) * 0.375F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MAXf(localfractionTmp_0d,
            (((Float32)IgSys_agIgMinCmbWiCANSpcReq) * 0.375F) - 36.0F)) + 36.0F)
            / 0.375F);
        } else {
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        }
        break;

       case IN_MINI_COMB:
        /* During 'MINI_COMB': '<S87>:3' */
        if (((SInt32)localTmpSignalConversionAtIgS_f) == 0) {
          /* Transition: '<S87>:13' */
          /* Exit 'MINI_COMB': '<S87>:3' */
          /* Entry 'DEPART': '<S87>:1' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        } else if ((((SInt32)IgSys_bExThermoProt) == 1) &&
                   (IgSys_agIgMinCmbWiCANSpcReq <=
                    localTmpSignalConversionAtIgS_b)) {
          /* Transition: '<S87>:19' */
          /* Exit 'MINI_COMB': '<S87>:3' */
          /* Entry 'TRANSITION_mini_comb_prot_Comp': '<S87>:7' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_TRANSITION_mini_comb_prot_Co;
          localfractionTmp_0d = (((Float32)(AdvMinT_B.Merge2 +
            IgSys_agIgSlopThermoInc)) * 0.375F) - 72.0F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MINf(localfractionTmp_0d,
            (((Float32)localTmpSignalConversionAtIgS_b) * 0.375F) - 36.0F)) +
            36.0F) / 0.375F);
        } else if ((((SInt32)IgSys_bDriv) == 1) && (((SInt32)
                     IgSys_bExThermoProt) == 0)) {
          /* Transition: '<S87>:18' */
          /* Exit 'MINI_COMB': '<S87>:3' */
          /* Entry 'AGREMENT': '<S87>:4' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_AGREMENT;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIg_oz;
        } else {
          AdvMinT_B.Merge2 = IgSys_agIgMinCmbWiCANSpcReq;
        }
        break;

       case IN_PROT_COMP:
        /* During 'PROT_COMP': '<S87>:5' */
        if ((((SInt32)IgSys_bExThermoProt) == 0) && (((SInt32)
              localTmpSignalConversionAtIgS_f) == 1)) {
          /* Transition: '<S87>:21' */
          /* Exit 'PROT_COMP': '<S87>:5' */
          /* Entry 'TRANSITION_Prot_Comp_mini_comb': '<S87>:8' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_TRANSITION_Prot_Comp_mini_co;
          localfractionTmp_0d = ((Float32)(AdvMinT_B.Merge2 -
            IgSys_agIgSlopThermoDec)) * 0.375F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MAXf(localfractionTmp_0d,
            (((Float32)IgSys_agIgMinCmbWiCANSpcReq) * 0.375F) - 36.0F)) + 36.0F)
            / 0.375F);
        } else if (((SInt32)localTmpSignalConversionAtIgS_f) == 0) {
          /* Transition: '<S87>:15' */
          /* Exit 'PROT_COMP': '<S87>:5' */
          /* Entry 'DEPART': '<S87>:1' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        } else {
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_b;
        }
        break;

       case IN_SORTIE_DEPART:
        /* During 'SORTIE_DEPART': '<S87>:2' */
        if (((SInt32)localTmpSignalConversionAtIgS_f) == 0) {
          /* Transition: '<S87>:11' */
          /* Exit 'SORTIE_DEPART': '<S87>:2' */
          /* Entry 'DEPART': '<S87>:1' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        } else if ((((SInt32)IgSys_bExThermoProt) == 1) && (AdvMinT_B.Merge2 <=
                    localTmpSignalConversionAtIgS_b)) {
          /* Transition: '<S87>:27' */
          /* Exit 'SORTIE_DEPART': '<S87>:2' */
          /* Entry 'PROT_COMP': '<S87>:5' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_PROT_COMP;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_b;
        } else if ((AdvMinT_B.Merge2 <= IgSys_agIgMinCmbWiCANSpcReq) &&
                   (((SInt32)IgSys_bExThermoProt) == 0)) {
          /* Transition: '<S87>:12' */
          /* Exit 'SORTIE_DEPART': '<S87>:2' */
          /* Entry 'MINI_COMB': '<S87>:3' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_MINI_COMB;
          AdvMinT_B.Merge2 = IgSys_agIgMinCmbWiCANSpcReq;
        } else {
          localfractionTmp_0d = ((Float32)(AdvMinT_B.Merge2 -
            IgSys_agIgSlopStrtDec)) * 0.375F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MAXf(localfractionTmp_0d,
            (((Float32)IgSys_agIgMinCmbWiCANSpcReq) * 0.375F) - 36.0F)) + 36.0F)
            / 0.375F);
        }
        break;

       case IN_TRANSITION_AGR_mini_comb:
        /* During 'TRANSITION_AGR_mini_comb': '<S87>:6' */
        if (((SInt32)localTmpSignalConversionAtIgS_f) == 0) {
          /* Transition: '<S87>:26' */
          /* Exit 'TRANSITION_AGR_mini_comb': '<S87>:6' */
          /* Entry 'DEPART': '<S87>:1' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        } else if (AdvMinT_B.Merge2 >= IgSys_agIgMinCmbWiCANSpcReq) {
          /* Transition: '<S87>:17' */
          /* Exit 'TRANSITION_AGR_mini_comb': '<S87>:6' */
          /* Entry 'MINI_COMB': '<S87>:3' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_MINI_COMB;
          AdvMinT_B.Merge2 = IgSys_agIgMinCmbWiCANSpcReq;
        } else {
          localfractionTmp_0d = (((Float32)(AdvMinT_B.Merge2 +
            IgSys_agIgSlopDrivInc)) * 0.375F) - 72.0F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MINf(localfractionTmp_0d,
            (((Float32)IgSys_agIgMinCmbWiCANSpcReq) * 0.375F) - 36.0F)) + 36.0F)
            / 0.375F);
        }
        break;

       case IN_TRANSITION_Prot_Comp_mini_co:
        /* During 'TRANSITION_Prot_Comp_mini_comb': '<S87>:8' */
        if (((SInt32)localTmpSignalConversionAtIgS_f) == 0) {
          /* Transition: '<S87>:25' */
          /* Exit 'TRANSITION_Prot_Comp_mini_comb': '<S87>:8' */
          /* Entry 'DEPART': '<S87>:1' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        } else if (AdvMinT_B.Merge2 <= IgSys_agIgMinCmbWiCANSpcReq) {
          /* Transition: '<S87>:22' */
          /* Exit 'TRANSITION_Prot_Comp_mini_comb': '<S87>:8' */
          /* Entry 'MINI_COMB': '<S87>:3' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_MINI_COMB;
          AdvMinT_B.Merge2 = IgSys_agIgMinCmbWiCANSpcReq;
        } else {
          localfractionTmp_0d = ((Float32)(AdvMinT_B.Merge2 -
            IgSys_agIgSlopThermoDec)) * 0.375F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MAXf(localfractionTmp_0d,
            (((Float32)IgSys_agIgMinCmbWiCANSpcReq) * 0.375F) - 36.0F)) + 36.0F)
            / 0.375F);
        }
        break;

       case IN_TRANSITION_mini_comb_prot_Co:
        /* During 'TRANSITION_mini_comb_prot_Comp': '<S87>:7' */
        if ((AdvMinT_B.Merge2 >= localTmpSignalConversionAtIgS_b) && (((SInt32)
              localTmpSignalConversionAtIgS_f) == 1)) {
          /* Transition: '<S87>:20' */
          /* Exit 'TRANSITION_mini_comb_prot_Comp': '<S87>:7' */
          /* Entry 'PROT_COMP': '<S87>:5' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_PROT_COMP;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_b;
        } else if (((SInt32)localTmpSignalConversionAtIgS_f) == 0) {
          /* Transition: '<S87>:23' */
          /* Exit 'TRANSITION_mini_comb_prot_Comp': '<S87>:7' */
          /* Entry 'DEPART': '<S87>:1' */
          AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
          AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        } else {
          localfractionTmp_0d = (((Float32)(AdvMinT_B.Merge2 +
            IgSys_agIgSlopThermoInc)) * 0.375F) - 72.0F;
          AdvMinT_B.Merge2 = (UInt8)((((Float32d)rt_MINf(localfractionTmp_0d,
            (((Float32)localTmpSignalConversionAtIgS_b) * 0.375F) - 36.0F)) +
            36.0F) / 0.375F);
        }
        break;

       default:
        /* Transition: '<S87>:9' */
        /* Entry 'DEPART': '<S87>:1' */
        AdvMinT_DWork.is_c2_AdvMinT = IN_DEPART;
        AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_l;
        break;
      }
    }

    /* end of Outputs for SubSystem: '<S13>/F03_Choix_avance' */
  }

  /* end of Outputs for SubSystem: '<S7>/F02_Coordination' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgMin_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMin_INPUT'
   */
  Rte_Read_R_IgSys_agIgMin_IgSys_agIgMin(&localTmpSignalConversionAtIgS_d);

  /* Outputs for enable SubSystem: '<S7>/F02_NOT' incorporates:
   *  EnablePort: '<S14>/IgSys_bAcvMinMgr'
   *  Logic: '<S7>/NAN'
   *
   * Block requirements for '<S7>/F02_NOT':
   *  1. SubSystem "F02_NOT" !Trace_To : VEMS_R_10_06440_003.01 ;
   */
  if (!IgSys_bAcvMinMgr) {
    /* SignalConversion: '<S14>/Signal Conversion1' */
    AdvMinT_B.Merge2 = localTmpSignalConversionAtIgS_d;
  }

  /* end of Outputs for SubSystem: '<S7>/F02_NOT' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Byp_Fonction_SC'
   *  Constant: '<S15>/Int_BypC'
   */
  if (ADVMINT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEng_s = IgSys_agIgMin_B;
  } else {
    localTmpSignalConversionAtEng_s = AdvMinT_B.Merge2;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgMinInport2' */
  Rte_Write_P_IgSys_agIgMin_IgSys_agIgMin(localTmpSignalConversionAtEng_s);
}

/* Model initialize function */
void RE_AdvMinT_Init(void)
{
  /* Registration code */

  /* block I/O */
  {
    AdvMinT_B.Merge2 = 96U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  RE_AdvMinT_005_MSE_Start();
  RE_AdvMinT_006_DRE_Start();
  RE_AdvMinT_008_DRE_Start();
  RE_AdvMinT_002_DRE_Start();
}

#define AdvMinT_STOP_SEC_CODE
#include "AdvMinT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
