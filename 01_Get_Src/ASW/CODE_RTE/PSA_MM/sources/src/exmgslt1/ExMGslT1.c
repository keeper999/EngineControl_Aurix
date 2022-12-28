/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : ExMGslT1                                                */
/* !Description     : ExMGslT1 Software Component                             */
/*                                                                            */
/* !Module          : ExMGslT1                                                */
/* !Description     : ExMGslT1 Software Component                             */
/*                                                                            */
/* !File            : ExMGslT1.c                                              */
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
/*   Model name       : ExMGslT1_AUTOSAR.mdl                                  */
/*   Root subsystem   : /ExMGslT1                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M06-ExMGslT1/5-S$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   29 Jun 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ExMGslT1.h"
#include "ExMGslT1_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define ExMGslT1_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ExMGslT1_MemMap.h"

/* Block signals (auto storage) */
BlockIO_ExMGslT1 ExMGslT1_B;

/* Block states (auto storage) */
D_Work_ExMGslT1 ExMGslT1_DWork;

#define ExMGslT1_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ExMGslT1_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define EXMGSLT1_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define EXMGSLT1_VEMSRTLIBT_MINOR_VERSION_REQ 21
#define EXMGSLT1_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define EXMGSLT1_VEMSRTLIBT_VERSION_REQ (EXMGSLT1_VEMSRTLIBT_PATCH_VERSION_REQ + EXMGSLT1_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + EXMGSLT1_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if EXMGSLT1_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define ExMGslT1_START_SEC_CODE
#include "ExMGslT1_MemMap.h"

void ExMGslT1_ASYNC1(int controlPortIdx)
{
}

void ExMGslT1_ASYNC2(int controlPortIdx)
{
}

/* Output and update for exported function: RE_ExMGslT1_005_MSE */
void RE_ExMGslT1_005_MSE(void)
{
  UInt16 localSwitch;
  UInt16 localSwitch_c[6];
  SInt32 locali;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_Initialiser_sorties'
   */

  /* Switch: '<S329>/Switch' incorporates:
   *  Constant: '<S329>/Byp_Fonction_SC'
   *  Constant: '<S329>/Int_BypC'
   *  Constant: '<S8>/OvlpExP_pExMnfOvlpIni_C'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch = ExM_pExMnfEstim_facVlvOvlp_B;
  } else {
    localSwitch = OvlpExP_pExMnfOvlpIni_C;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_pExMnfEstim_facVlvOvlpInport2' */
  Rte_Write_P_ExM_pExMnfEstim_facVlvOvlp_ExM_pExMnfEstim_facVlvOvlp(localSwitch);

  /* Switch: '<S330>/Switch' incorporates:
   *  Constant: '<S330>/Byp_Fonction_SC'
   *  Constant: '<S330>/Int_BypC'
   *  Constant: '<S8>/OvlpExP_pExMnfOvlpIni_C'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localSwitch_c[locali] = ExM_prm_pExMnfEstimOvlpCyl_B[(locali)];
    }
  } else {
    localSwitch_c[0] = OvlpExP_pExMnfOvlpIni_C;
    localSwitch_c[1] = OvlpExP_pExMnfOvlpIni_C;
    localSwitch_c[2] = OvlpExP_pExMnfOvlpIni_C;
    localSwitch_c[3] = OvlpExP_pExMnfOvlpIni_C;
    localSwitch_c[4] = OvlpExP_pExMnfOvlpIni_C;
    localSwitch_c[5] = OvlpExP_pExMnfOvlpIni_C;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_prm_pExMnfEstimOvlpCylInport2' */
  Rte_Write_P_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl
    (&localSwitch_c);
}

/* Start for exported function: RE_ExMGslT1_004_MSE */
void RE_ExMGslT1_004_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Initialisation_du_calcul'
   */
}

/* Output and update for exported function: RE_ExMGslT1_004_MSE */
void RE_ExMGslT1_004_MSE(void)
{
  SInt16 localTmpSignalConversionAtExt_t;
  UInt16 localSwitch_h;
  UInt32 localSwitch_i;
  SInt32 localtmp;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Initialisation_du_calcul'
   */

  /* user code (Output function Body for TID5) */
  RE_ExMGslT_Init();

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Byp_Fonction_SC'
   *  Constant: '<S15>/Int_BypC'
   *  Constant: '<S6>/Cste_273'
   *  Sum: '<S6>/Subtract4'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_h = ExM_tExDyn_B;
  } else {
    localtmp = localTmpSignalConversionAtExt_t + 50;
    if (localtmp <= 0) {
      localSwitch_h = 0U;
    } else if (localtmp > 2047) {
      localSwitch_h = MAX_uint16_T;
    } else {
      localSwitch_h = (UInt16)(localtmp << 5);
    }
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_tExDynInport2' */
  Rte_Write_P_ExM_tExDyn_ExM_tExDyn(localSwitch_h);

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Byp_Fonction_SC'
   *  Constant: '<S18>/Int_BypC'
   *  Constant: '<S6>/Cste_8'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_h = ExM_tExPostOxOfs_B;
  } else {
    localSwitch_h = 0U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_tExPostOxOfsInport2' */
  Rte_Write_P_ExM_tExPostOxOfs_ExM_tExPostOxOfs(localSwitch_h);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Byp_Fonction_SC'
   *  Constant: '<S16>/Int_BypC'
   *  Constant: '<S6>/Cste_1'
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_h = ExM_tExStatAfs_B;
  } else {
    localSwitch_h = 4800U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_tExStatAfsInport2' */
  Rte_Write_P_ExM_tExStatAfs_ExM_tExStatAfs(localSwitch_h);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Byp_Fonction_SC'
   *  Constant: '<S12>/Int_BypC'
   *  Constant: '<S6>/Cste_3'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_h = ExM_facCorProtComp_B;
  } else {
    localSwitch_h = 8192U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_facCorProtCompInport2' */
  Rte_Write_P_ExM_facCorProtComp_ExM_facCorProtComp(localSwitch_h);

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Byp_Fonction_SC'
   *  Constant: '<S17>/Int_BypC'
   *  Constant: '<S6>/Cste_2'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_h = ExM_facCorIgProtComp_B;
  } else {
    localSwitch_h = 16384U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_facCorIgProtCompInport2' */
  Rte_Write_P_ExM_facCorIgProtComp_ExM_facCorIgProtComp(localSwitch_h);

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Byp_Fonction_SC'
   *  Constant: '<S11>/Int_BypC'
   *  Constant: '<S6>/Cste_5'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_h = ExM_gmaInMixt_B;
  } else {
    localSwitch_h = 1434U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_gmaInMixtInport2' */
  Rte_Write_P_ExM_gmaInMixt_ExM_gmaInMixt(localSwitch_h);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Byp_Fonction_SC'
   *  Constant: '<S10>/Int_BypC'
   *  Constant: '<S6>/Cste_4'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_h = ExM_mfEgTot_B;
  } else {
    localSwitch_h = 66U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_mfEgTotInport2' */
  Rte_Write_P_ExM_mfEgTot_ExM_mfEgTot(localSwitch_h);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Byp_Fonction_SC'
   *  Constant: '<S13>/Int_BypC'
   *  Constant: '<S6>/Cste_6'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_h = ExM_molMassInMixt_B;
  } else {
    localSwitch_h = 3712U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_molMassInMixtInport2' */
  Rte_Write_P_ExM_molMassInMixt_ExM_molMassInMixt(localSwitch_h);

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Byp_Fonction_SC'
   *  Constant: '<S14>/Int_BypC'
   *  Constant: '<S6>/Cste_7'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localSwitch_i = ExM_lamTot_B;
  } else {
    localSwitch_i = 8192U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_lamTotInport2' */
  Rte_Write_P_ExM_lamTot_ExM_lamTot(localSwitch_i);
}

/* Start for exported function: RE_ExMGslT1_003_TEV */
void RE_ExMGslT1_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F04_Calculer_sorties'
   */
}

/* Output and update for exported function: RE_ExMGslT1_003_TEV */
void RE_ExMGslT1_003_TEV(void)
{
  /* local block i/o variables */
  UInt32 localLookUpTable;
  UInt16 localDataTypeConversion1_a;
  UInt16 localDataTypeConversion1_k;
  UInt16 localDataTypeConversion1_g;
  UInt16 localDataTypeConversion1_m;
  UInt16 localDataTypeConversion1_ml;
  UInt16 localDataTypeConversion1_o;
  UInt16 localDataTypeConversion1_ju;
  UInt16 localDataTypeConversion1_kh;
  UInt16 localDataTypeConversion1_b;
  UInt16 localDataTypeConversion_f;
  UInt16 localLookUpTable_b;
  UInt16 localLookUpTable_l;
  UInt16 localLookUpTable_g;
  UInt16 localDataTypeConversion_h;
  UInt16 localDataTypeConversion_p;
  UInt16 localLookUpTable2D;
  UInt16 localLookUpTable2D_a;
  UInt16 localLookUpTable2D_a5;
  UInt16 localLookUpTable2D_d;
  UInt16 localLookUpTable2D_m;
  UInt16 localLookUpTable2D_c;
  UInt16 localLookUpTable2D_j;
  UInt16 localLookUpTable2D_b;
  UInt16 localLookUpTable2D_e;
  UInt8 localTmpSignalConversionAtEng_n;
  Float32 localDataTypeConversion_ai;
  Float32 localDivide_hq;
  UInt16 localAssignment[6];
  UInt16 localTmpSignalConversionAtExM_o;
  UInt16 localTmpSignalConversionAtExM_f;
  UInt16 localTmpSignalConversionAtExM_p;
  SInt16 localTmpSignalConversionAtEngM_;
  SInt16 localTmpSignalConversionAtEng_b;
  UInt16 localTmpSignalConversionAtExM_t;
  UInt16 localTmpSignalConversionAtUsThr;
  SInt32 locali;
  Float32d localtmp;
  UInt16 locallocalTmpSignalConversionAt;
  UInt32 localtmp_0;
  SInt16 locallocalSum_m;
  SInt16 locallocalSum1_g;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F04_Calculer_sorties'
   */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkOpInVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsExVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (&localTmpSignalConversionAtEng_b);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&ExMGslT1_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_mfEgWoutEGROutport2' incorporates:
   *  Inport: '<Root>/ExM_mfEgWoutEGR'
   */
  Rte_Read_R_ExM_mfEgWoutEGR_ExM_mfEgWoutEGR(&locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_mfTrbEstimSatOutport2' incorporates:
   *  Inport: '<Root>/ExM_mfTrbEstimSat'
   */
  Rte_Read_R_ExM_mfTrbEstimSat_ExM_mfTrbEstimSat
    (&localTmpSignalConversionAtExM_o);

  /* Outputs for atomic SubSystem: '<S9>/F04_Selectionner_debit_echappement' */

  /* Switch: '<S334>/Switch' incorporates:
   *  Constant: '<S334>/OvlpExP_bSelMfEg_C'
   */
  if (OvlpExP_bSelMfEg_C) {
    OvlpExP_mfEg = ((Float32)locallocalTmpSignalConversionAt) *
      1.525878906E-005F;
  } else {
    OvlpExP_mfEg = ((Float32)localTmpSignalConversionAtExM_o) *
      1.525878906E-005F;
  }

  /* end of Outputs for SubSystem: '<S9>/F04_Selectionner_debit_echappement' */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_tExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExMnfEstim'
   */
  Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim(&localTmpSignalConversionAtExM_t);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsThr);

  /* Outputs for atomic SubSystem: '<S9>/F01_01_Calculer_rPres' */

  /* Outputs for atomic SubSystem: '<S331>/F01_01_01_Cartographier_rPres_specifiques' */

  /* Outputs for atomic SubSystem: '<S339>/F01_01_01_01_Determiner_charge_corrigee' */

  /* Outputs for atomic SubSystem: '<S342>/F01_01_01_01_01_Calculer_facteur_debit_charge' */

  /* Product: '<S352>/Divide' incorporates:
   *  Constant: '<S344>/AirEfc_densAir_C'
   *  Constant: '<S344>/AirEfc_noCylEng_C'
   *  Constant: '<S344>/AirEfc_volRef_C'
   *  Constant: '<S344>/Constant2'
   *  Constant: '<S344>/Constant3'
   *  DataTypeConversion: '<S344>/Data Type Conversion'
   *  DataTypeConversion: '<S344>/Data Type Conversion1'
   *  DataTypeConversion: '<S344>/Data Type Conversion2'
   *  DataTypeConversion: '<S344>/Data Type Conversion3'
   *  Product: '<S348>/Divide'
   *  Product: '<S349>/Divide'
   *  Product: '<S350>/Divide'
   *  Product: '<S351>/Divide'
   */
  OvlpExP_facMassFlowLd = (((((Float32)AirEfc_volRef_C) * 7.629394894E-009F) *
                            (((Float32)AirEfc_noCylEng_C) / 2.0F)) *
    (((Float32)AirEfc_densAir_C) * 1.525878906E-005F)) * (((Float32)
    ExMGslT1_B.TmpSignalConversionAtExt_nEngOu) / 60.0F);

  /* end of Outputs for SubSystem: '<S342>/F01_01_01_01_01_Calculer_facteur_debit_charge' */

  /* Outputs for atomic SubSystem: '<S342>/F01_01_01_01_02_Calculer_facteurs_thermodynamiques' */

  /* DataTypeConversion: '<S353>/Data Type Conversion' */
  localtmp_0 = (UInt32)(localTmpSignalConversionAtExM_t + 7136);
  if (localtmp_0 > 65535U) {
    localDataTypeConversion_p = MAX_uint16_T;
  } else {
    localDataTypeConversion_p = (UInt16)localtmp_0;
  }

  /* Lookup: '<S353>/Look-Up Table'
   * About '<S353>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-5
   * Output0 Data Type:  Fixed Point    U32  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U32_U16( &(localLookUpTable), (&(AirEfc_facTExSqrt_T[0])),
                 localDataTypeConversion_p, (&(AirEfc_tExMnf_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S353>/Data Type Duplicate1'
   *
   * Regarding '<S353>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S345>/Data Type Conversion1' incorporates:
   *  Lookup: '<S353>/Look-Up Table'
   */
  OvlpExP_facTEgSqrtIvs = ((Float32)localLookUpTable) * 3.051757813E-005F;

  /* Product: '<S354>/Divide' incorporates:
   *  Constant: '<S345>/AirEfc_pRef_C'
   *  DataTypeConversion: '<S345>/Data Type Conversion2'
   *  DataTypeConversion: '<S345>/Data Type Conversion3'
   */
  localDivide_hq = (((Float32)AirEfc_pRef_C) * 8.0F) / (((Float32)
    localTmpSignalConversionAtUsThr) * 8.0F);

  /* Outputs for atomic SubSystem: '<S354>/If Action Subsystem3' */

  /* Switch: '<S356>/Switch1' incorporates:
   *  Constant: '<S356>/Constant1'
   *  Constant: '<S356>/Constant2'
   *  Constant: '<S356>/Constant3'
   *  Logic: '<S356>/Logical Operator1'
   *  RelationalOperator: '<S356>/Relational Operator'
   *  RelationalOperator: '<S356>/Relational Operator1'
   *  RelationalOperator: '<S356>/Relational Operator3'
   */
  if (((localDivide_hq != localDivide_hq) || (localDivide_hq > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_hq)) {
    OvlpExP_facPresAirExt = 0.0F;
  } else {
    OvlpExP_facPresAirExt = localDivide_hq;
  }

  /* end of Outputs for SubSystem: '<S354>/If Action Subsystem3' */

  /* end of Outputs for SubSystem: '<S342>/F01_01_01_01_02_Calculer_facteurs_thermodynamiques' */

  /* Outputs for enable SubSystem: '<S342>/F01_01_01_01_03_Calculer_charge_corrigee_mode_faible_regime' incorporates:
   *  Constant: '<S342>/OvlpExP_nEngThdLdCorClc_C'
   *  EnablePort: '<S346>/Enable'
   *  EnablePort: '<S347>/Enable'
   *  Logic: '<S342>/Logical Operator'
   *  RelationalOperator: '<S342>/Relational Operator'
   *  SubSystem: '<S342>/F01_01_01_01_04_Calculer_charge_corrigee_mode_normal'
   */
  if (ExMGslT1_B.TmpSignalConversionAtExt_nEngOu < OvlpExP_nEngThdLdCorClc_C) {
    /* SignalConversion: '<S346>/Signal Conversion3' incorporates:
     *  Constant: '<S346>/OvlpExP_rEgTotLdCor_nEngThd_C'
     */
    OvlpExP_rEgTotLdCor_nEng = OvlpExP_rEgTotLdCor_nEngThd_C;
  } else {
    /* Product: '<S357>/Divide' */
    localDivide_hq = OvlpExP_mfEg / OvlpExP_facMassFlowLd;

    /* Outputs for atomic SubSystem: '<S357>/If Action Subsystem3' */

    /* Switch: '<S361>/Switch1' incorporates:
     *  Constant: '<S361>/Constant1'
     *  Constant: '<S361>/Constant2'
     *  Constant: '<S361>/Constant3'
     *  Logic: '<S361>/Logical Operator1'
     *  RelationalOperator: '<S361>/Relational Operator'
     *  RelationalOperator: '<S361>/Relational Operator1'
     *  RelationalOperator: '<S361>/Relational Operator3'
     */
    if (((localDivide_hq != localDivide_hq) || (localDivide_hq >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hq)) {
      localDivide_hq = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S357>/If Action Subsystem3' */

    /* DataStoreWrite: '<S347>/Data Store Write3' incorporates:
     *  DataTypeConversion: '<S347>/Data Type Conversion5'
     */
    localtmp = ((Float32d)localDivide_hq) / 1.5258789062500000E-004F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        OvlpExP_rEgTotLd_nEng_MP = (UInt16)localtmp;
      } else {
        OvlpExP_rEgTotLd_nEng_MP = 0U;
      }
    } else {
      OvlpExP_rEgTotLd_nEng_MP = MAX_uint16_T;
    }

    /* Product: '<S358>/Divide' incorporates:
     *  Product: '<S359>/Divide'
     */
    localDivide_hq = (OvlpExP_facPresAirExt * localDivide_hq) /
      OvlpExP_facTEgSqrtIvs;

    /* Outputs for atomic SubSystem: '<S358>/If Action Subsystem3' */

    /* Switch: '<S363>/Switch1' incorporates:
     *  Constant: '<S363>/Constant1'
     *  Constant: '<S363>/Constant2'
     *  Constant: '<S363>/Constant3'
     *  Logic: '<S363>/Logical Operator1'
     *  RelationalOperator: '<S363>/Relational Operator'
     *  RelationalOperator: '<S363>/Relational Operator1'
     *  RelationalOperator: '<S363>/Relational Operator3'
     */
    if (((localDivide_hq != localDivide_hq) || (localDivide_hq >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hq)) {
      localDivide_hq = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S358>/If Action Subsystem3' */

    /* DataTypeConversion: '<S358>/Data Type Conversion2' */
    localtmp = ((Float32d)localDivide_hq) / 1.5258789062500000E-004F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        OvlpExP_rEgTotLdCor_nEng = (UInt16)localtmp;
      } else {
        OvlpExP_rEgTotLdCor_nEng = 0U;
      }
    } else {
      OvlpExP_rEgTotLdCor_nEng = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S342>/F01_01_01_01_03_Calculer_charge_corrigee_mode_faible_regime' */

  /* end of Outputs for SubSystem: '<S339>/F01_01_01_01_Determiner_charge_corrigee' */

  /* Outputs for atomic SubSystem: '<S339>/F01_01_01_02_Calculer_rPres_specifiques' */

  /* DataTypeConversion: '<S364>/Data Type Conversion1' */
  localDataTypeConversion1_a = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S364>/Look-Up Table (2-D)'
   * About '<S364>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D), (&(OvlpExP_rPresInMaxExMax_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_a, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S364>/Data Type Duplicate2'
   *
   * Regarding '<S364>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S365>/Data Type Conversion1' */
  localDataTypeConversion1_k = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S365>/Look-Up Table (2-D)'
   * About '<S365>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_a), (&(OvlpExP_rPresInMidExMax_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_k, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S365>/Data Type Duplicate2'
   *
   * Regarding '<S365>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S366>/Data Type Conversion1' */
  localDataTypeConversion1_g = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S366>/Look-Up Table (2-D)'
   * About '<S366>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_a5), (&(OvlpExP_rPresInMinExMax_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_g, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S366>/Data Type Duplicate2'
   *
   * Regarding '<S366>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S367>/Data Type Conversion1' */
  localDataTypeConversion1_m = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S367>/Look-Up Table (2-D)'
   * About '<S367>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_d), (&(OvlpExP_rPresInMaxExMid_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_m, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S367>/Data Type Duplicate2'
   *
   * Regarding '<S367>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S368>/Data Type Conversion1' */
  localDataTypeConversion1_ml = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S368>/Look-Up Table (2-D)'
   * About '<S368>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_m), (&(OvlpExP_rPresInMidExMid_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_ml, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S368>/Data Type Duplicate2'
   *
   * Regarding '<S368>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S369>/Data Type Conversion1' */
  localDataTypeConversion1_o = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S369>/Look-Up Table (2-D)'
   * About '<S369>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_c), (&(OvlpExP_rPresInMidExMin_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_o, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S369>/Data Type Duplicate2'
   *
   * Regarding '<S369>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S370>/Data Type Conversion1' */
  localDataTypeConversion1_ju = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S370>/Look-Up Table (2-D)'
   * About '<S370>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_j), (&(OvlpExP_rPresInMinExMin_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_ju, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S370>/Data Type Duplicate2'
   *
   * Regarding '<S370>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S371>/Data Type Conversion1' */
  localDataTypeConversion1_kh = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S371>/Look-Up Table (2-D)'
   * About '<S371>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_b), (&(OvlpExP_rPresInMaxExMin_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_kh, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S371>/Data Type Duplicate2'
   *
   * Regarding '<S371>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S372>/Data Type Conversion1' */
  localDataTypeConversion1_b = ExMGslT1_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup2D: '<S372>/Look-Up Table (2-D)'
   * About '<S372>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_e), (&(OvlpExP_rPresInMinExMid_M[0])),
                     OvlpExP_rEgTotLdCor_nEng, (&(OvlpExP_rEgTotLdCorX_A[0])),
                     15U, localDataTypeConversion1_b, (&(OvlpExP_nEngY_A[0])),
                     17U);

  /* DataTypeDuplicate Block: '<S372>/Data Type Duplicate2'
   *
   * Regarding '<S372>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S343>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S369>/Data Type Conversion1'
   *  Lookup2D: '<S369>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMidExMin = ((Float32)localLookUpTable2D_c) * 7.629394531E-005F;

  /* DataTypeConversion: '<S343>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S372>/Data Type Conversion1'
   *  Lookup2D: '<S372>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMinExMid = ((Float32)localLookUpTable2D_e) * 7.629394531E-005F;

  /* DataTypeConversion: '<S343>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S368>/Data Type Conversion1'
   *  Lookup2D: '<S368>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMidExMid = ((Float32)localLookUpTable2D_m) * 7.629394531E-005F;

  /* DataTypeConversion: '<S343>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S367>/Data Type Conversion1'
   *  Lookup2D: '<S367>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMaxExMid = ((Float32)localLookUpTable2D_d) * 7.629394531E-005F;

  /* DataTypeConversion: '<S343>/Data Type Conversion4' incorporates:
   *  DataTypeConversion: '<S366>/Data Type Conversion1'
   *  Lookup2D: '<S366>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMinExMax = ((Float32)localLookUpTable2D_a5) *
    7.629394531E-005F;

  /* DataTypeConversion: '<S343>/Data Type Conversion5' incorporates:
   *  DataTypeConversion: '<S365>/Data Type Conversion1'
   *  Lookup2D: '<S365>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMidExMax = ((Float32)localLookUpTable2D_a) * 7.629394531E-005F;

  /* DataTypeConversion: '<S343>/Data Type Conversion6' incorporates:
   *  DataTypeConversion: '<S364>/Data Type Conversion1'
   *  Lookup2D: '<S364>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMaxExMax = ((Float32)localLookUpTable2D) * 7.629394531E-005F;

  /* DataTypeConversion: '<S343>/Data Type Conversion7' incorporates:
   *  DataTypeConversion: '<S371>/Data Type Conversion1'
   *  Lookup2D: '<S371>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMaxExMin = ((Float32)localLookUpTable2D_b) * 7.629394531E-005F;

  /* DataTypeConversion: '<S343>/Data Type Conversion8' incorporates:
   *  DataTypeConversion: '<S370>/Data Type Conversion1'
   *  Lookup2D: '<S370>/Look-Up Table (2-D)'
   */
  OvlpExP_rPresInMinExMin = ((Float32)localLookUpTable2D_j) * 7.629394531E-005F;

  /* end of Outputs for SubSystem: '<S339>/F01_01_01_02_Calculer_rPres_specifiques' */

  /* end of Outputs for SubSystem: '<S331>/F01_01_01_Cartographier_rPres_specifiques' */

  /* Outputs for atomic SubSystem: '<S331>/F01_01_02_Interpoler_rPres_OA' */

  /* Outputs for atomic SubSystem: '<S340>/F01_01_02_01_Determiner_pentes_d_interpolations' */

  /* Sum: '<S373>/Sum' incorporates:
   *  Constant: '<S373>/OvlpExP_agCkOpInVlvMid_C'
   *  Constant: '<S373>/OvlpExP_agCkOpInVlvMin_C'
   */
  locali = OvlpExP_agCkOpInVlvMid_C - OvlpExP_agCkOpInVlvMin_C;
  if (locali > 32767) {
    locallocalSum_m = MAX_int16_T;
  } else if (locali <= -32768) {
    locallocalSum_m = MIN_int16_T;
  } else {
    locallocalSum_m = (SInt16)locali;
  }

  /* DataStoreWrite: '<S373>/Data Store Write1' */
  OvlpExP_agCkInDeltaMidMin_MP = locallocalSum_m;

  /* Sum: '<S373>/Sum1' incorporates:
   *  Constant: '<S373>/OvlpExP_agCkOpInVlvMax_C'
   *  Constant: '<S373>/OvlpExP_agCkOpInVlvMid_C1'
   */
  locali = OvlpExP_agCkOpInVlvMax_C - OvlpExP_agCkOpInVlvMid_C;
  if (locali > 32767) {
    locallocalSum1_g = MAX_int16_T;
  } else if (locali <= -32768) {
    locallocalSum1_g = MIN_int16_T;
  } else {
    locallocalSum1_g = (SInt16)locali;
  }

  /* DataStoreWrite: '<S373>/Data Store Write3' */
  OvlpExP_agCkInDeltaMaxMid_MP = locallocalSum1_g;

  /* DataTypeConversion: '<S373>/Data Type Conversion' */
  localDataTypeConversion_ai = ((Float32)localTmpSignalConversionAtEngM_) *
    0.09375F;

  /* Outputs for enable SubSystem: '<S373>/F01_01_02_01_01_Calculer_pente_OA_MinMid_isobornes' incorporates:
   *  Constant: '<S373>/OvlpExP_agCkOpInVlvLimThd_C'
   *  EnablePort: '<S377>/Enable'
   *  EnablePort: '<S378>/Enable'
   *  Logic: '<S373>/Logical Operator'
   *  RelationalOperator: '<S373>/Relational Operator'
   *  SubSystem: '<S373>/F01_01_02_01_02_Calculer_pente_OA_MinMid_mode_normal'
   */
  if (!(locallocalSum_m >= OvlpExP_agCkOpInVlvLimThd_C)) {
    /* DataTypeConversion: '<S377>/Data Type Conversion2' incorporates:
     *  Constant: '<S377>/OvlpExP_facOpInVlvMinMidEqu_C'
     */
    OvlpExP_facSatOpInVlvMinMid = ((Float32)OvlpExP_facOpInVlvMinMidEqu_C) *
      1.525878906E-005F;
  } else {
    /* DataTypeConversion: '<S378>/Data Type Conversion2' incorporates:
     *  Constant: '<S378>/OvlpExP_agCkOpInVlvMid_C'
     */
    localDivide_hq = ((Float32)OvlpExP_agCkOpInVlvMid_C) * 0.09375F;

    /* Product: '<S381>/Divide' incorporates:
     *  Constant: '<S378>/OvlpExP_agCkOpInVlvMin_C'
     *  DataTypeConversion: '<S378>/Data Type Conversion1'
     *  Sum: '<S378>/Add1'
     *  Sum: '<S378>/Add4'
     */
    localDivide_hq = (localDivide_hq - localDataTypeConversion_ai) /
      (localDivide_hq - (((Float32)OvlpExP_agCkOpInVlvMin_C) * 0.09375F));

    /* Outputs for atomic SubSystem: '<S381>/If Action Subsystem3' */

    /* Switch: '<S383>/Switch1' incorporates:
     *  Constant: '<S383>/Constant1'
     *  Constant: '<S383>/Constant2'
     *  Constant: '<S383>/Constant3'
     *  Logic: '<S383>/Logical Operator1'
     *  RelationalOperator: '<S383>/Relational Operator'
     *  RelationalOperator: '<S383>/Relational Operator1'
     *  RelationalOperator: '<S383>/Relational Operator3'
     */
    if (((localDivide_hq != localDivide_hq) || (localDivide_hq >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hq)) {
      localDivide_hq = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S381>/If Action Subsystem3' */

    /* DataStoreWrite: '<S378>/Data Store Write3' incorporates:
     *  DataTypeConversion: '<S378>/Data Type Conversion5'
     */
    localtmp = ACTEMS_LdexpF((Float32d)localDivide_hq, 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        OvlpExP_facOpInVlvMinMid_MP = (UInt16)localtmp;
      } else {
        OvlpExP_facOpInVlvMinMid_MP = 0U;
      }
    } else {
      OvlpExP_facOpInVlvMinMid_MP = MAX_uint16_T;
    }

    /* MinMax: '<S378>/MinMax2' incorporates:
     *  Constant: '<S378>/Constant'
     */
    localDivide_hq = rt_MAXf(0.0F, localDivide_hq);

    /* MinMax: '<S378>/MinMax3' incorporates:
     *  Constant: '<S378>/Constant1'
     */
    OvlpExP_facSatOpInVlvMinMid = rt_MINf(1.0F, localDivide_hq);
  }

  /* end of Outputs for SubSystem: '<S373>/F01_01_02_01_01_Calculer_pente_OA_MinMid_isobornes' */

  /* Outputs for enable SubSystem: '<S373>/F01_01_02_01_03_Calculer_pente_OA_MidMax_isobornes' incorporates:
   *  Constant: '<S373>/OvlpExP_agCkOpInVlvLimThd_C1'
   *  EnablePort: '<S379>/Enable'
   *  EnablePort: '<S380>/Enable'
   *  Logic: '<S373>/Logical Operator1'
   *  RelationalOperator: '<S373>/Relational Operator1'
   *  SubSystem: '<S373>/F01_01_02_01_04_Calculer_pente_OA_MidMax'
   */
  if (!(locallocalSum1_g >= OvlpExP_agCkOpInVlvLimThd_C)) {
    /* DataTypeConversion: '<S379>/Data Type Conversion2' incorporates:
     *  Constant: '<S379>/OvlpExP_facOpInVlvMidMaxEqu_C'
     */
    OvlpExP_facSatOpInVlvMidMax = ((Float32)OvlpExP_facOpInVlvMidMaxEqu_C) *
      1.525878906E-005F;
  } else {
    /* DataTypeConversion: '<S380>/Data Type Conversion1' incorporates:
     *  Constant: '<S380>/OvlpExP_agCkOpInVlvMax_C'
     */
    localDivide_hq = ((Float32)OvlpExP_agCkOpInVlvMax_C) * 0.09375F;

    /* Product: '<S384>/Divide' incorporates:
     *  Constant: '<S380>/OvlpExP_agCkOpInVlvMid_C'
     *  DataTypeConversion: '<S380>/Data Type Conversion2'
     *  Sum: '<S380>/Add2'
     *  Sum: '<S380>/Add3'
     */
    localDivide_hq = (localDivide_hq - localDataTypeConversion_ai) /
      (localDivide_hq - (((Float32)OvlpExP_agCkOpInVlvMid_C) * 0.09375F));

    /* Outputs for atomic SubSystem: '<S384>/If Action Subsystem3' */

    /* Switch: '<S386>/Switch1' incorporates:
     *  Constant: '<S386>/Constant1'
     *  Constant: '<S386>/Constant2'
     *  Constant: '<S386>/Constant3'
     *  Logic: '<S386>/Logical Operator1'
     *  RelationalOperator: '<S386>/Relational Operator'
     *  RelationalOperator: '<S386>/Relational Operator1'
     *  RelationalOperator: '<S386>/Relational Operator3'
     */
    if (((localDivide_hq != localDivide_hq) || (localDivide_hq >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hq)) {
      localDivide_hq = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S384>/If Action Subsystem3' */

    /* DataStoreWrite: '<S380>/Data Store Write3' incorporates:
     *  DataTypeConversion: '<S380>/Data Type Conversion5'
     */
    localtmp = ACTEMS_LdexpF((Float32d)localDivide_hq, 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        OvlpExP_facOpInVlvMidMax_MP = (UInt16)localtmp;
      } else {
        OvlpExP_facOpInVlvMidMax_MP = 0U;
      }
    } else {
      OvlpExP_facOpInVlvMidMax_MP = MAX_uint16_T;
    }

    /* MinMax: '<S380>/MinMax' incorporates:
     *  Constant: '<S380>/Constant'
     */
    localDivide_hq = rt_MAXf(localDivide_hq, 0.0F);

    /* MinMax: '<S380>/MinMax1' incorporates:
     *  Constant: '<S380>/Constant1'
     */
    OvlpExP_facSatOpInVlvMidMax = rt_MINf(localDivide_hq, 1.0F);
  }

  /* end of Outputs for SubSystem: '<S373>/F01_01_02_01_03_Calculer_pente_OA_MidMax_isobornes' */

  /* end of Outputs for SubSystem: '<S340>/F01_01_02_01_Determiner_pentes_d_interpolations' */

  /* Outputs for atomic SubSystem: '<S340>/F01_01_02_02_Interpoler_rPres_a_FE_max' */

  /* DataTypeConversion: '<S388>/Data Type Conversion' */
  localtmp = ACTEMS_LdexpF((Float32d)OvlpExP_facSatOpInVlvMinMid, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion_h = (UInt16)localtmp;
    } else {
      localDataTypeConversion_h = 0U;
    }
  } else {
    localDataTypeConversion_h = MAX_uint16_T;
  }

  /* Lookup: '<S388>/Look-Up Table'
   * About '<S388>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_l), (&(OvlpExP_facInMinMidAdjExMax_T[0])),
                 localDataTypeConversion_h, (&(OvlpExP_facInMinMid_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S388>/Data Type Duplicate1'
   *
   * Regarding '<S388>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataStoreWrite: '<S374>/Data Store Write1' */
  OvlpExP_facInMinMidAdjExMax_MP = localLookUpTable_l;

  /* DataTypeConversion: '<S387>/Data Type Conversion' */
  localtmp = ACTEMS_LdexpF((Float32d)OvlpExP_facSatOpInVlvMidMax, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion_h = (UInt16)localtmp;
    } else {
      localDataTypeConversion_h = 0U;
    }
  } else {
    localDataTypeConversion_h = MAX_uint16_T;
  }

  /* Lookup: '<S387>/Look-Up Table'
   * About '<S387>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_g), (&(OvlpExP_facInMidMaxAdjExMax_T[0])),
                 localDataTypeConversion_h, (&(OvlpExP_facInMidMax_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S387>/Data Type Duplicate1'
   *
   * Regarding '<S387>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataStoreWrite: '<S374>/Data Store Write3' */
  OvlpExP_facInMidMaxAdjExMax_MP = localLookUpTable_g;

  /* RelationalOperator: '<S374>/Relational Operator' incorporates:
   *  Constant: '<S374>/OvlpExP_agCkOpInVlvMid_C'
   */
  OvlpExP_bInOverMidAdjExMax_MP = (localTmpSignalConversionAtEngM_ >=
    OvlpExP_agCkOpInVlvMid_C);

  /* Switch: '<S374>/Switch' incorporates:
   *  DataTypeConversion: '<S374>/Data Type Conversion1'
   *  DataTypeConversion: '<S374>/Data Type Conversion2'
   *  Product: '<S389>/Divide'
   *  Product: '<S390>/Divide'
   *  Sum: '<S374>/Add1'
   *  Sum: '<S374>/Add2'
   *  Sum: '<S374>/Add3'
   *  Sum: '<S374>/Add4'
   */
  if (OvlpExP_bInOverMidAdjExMax_MP) {
    OvlpExP_rPresClsExVlvMax = ((OvlpExP_rPresInMidExMax -
      OvlpExP_rPresInMaxExMax) * (((Float32)localLookUpTable_g) *
      1.525878906E-005F)) + OvlpExP_rPresInMaxExMax;
  } else {
    OvlpExP_rPresClsExVlvMax = ((OvlpExP_rPresInMinExMax -
      OvlpExP_rPresInMidExMax) * (((Float32)localLookUpTable_l) *
      1.525878906E-005F)) + OvlpExP_rPresInMidExMax;
  }

  /* end of Outputs for SubSystem: '<S340>/F01_01_02_02_Interpoler_rPres_a_FE_max' */

  /* Outputs for atomic SubSystem: '<S340>/F01_01_02_03_Interpoler_rPres_a_FE_mid' */

  /* DataTypeConversion: '<S391>/Data Type Conversion' */
  localtmp = ACTEMS_LdexpF((Float32d)OvlpExP_facSatOpInVlvMidMax, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion_f = (UInt16)localtmp;
    } else {
      localDataTypeConversion_f = 0U;
    }
  } else {
    localDataTypeConversion_f = MAX_uint16_T;
  }

  /* Lookup: '<S391>/Look-Up Table'
   * About '<S391>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_b), (&(OvlpExP_facInMidMaxAdjExMid_T[0])),
                 localDataTypeConversion_f, (&(OvlpExP_facInMidMax_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S391>/Data Type Duplicate1'
   *
   * Regarding '<S391>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataStoreWrite: '<S375>/Data Store Write3' */
  OvlpExP_facInMidMaxAdjExMid_MP = localLookUpTable_b;

  /* RelationalOperator: '<S375>/Relational Operator2' incorporates:
   *  Constant: '<S375>/OvlpExP_agCkOpInVlvMid_C'
   */
  OvlpExP_bInOverMidAdjExMid_MP = (localTmpSignalConversionAtEngM_ >=
    OvlpExP_agCkOpInVlvMid_C);

  /* Switch: '<S375>/Switch2' incorporates:
   *  DataTypeConversion: '<S375>/Data Type Conversion3'
   *  Product: '<S392>/Divide'
   *  Product: '<S393>/Divide'
   *  Sum: '<S375>/Add10'
   *  Sum: '<S375>/Add11'
   *  Sum: '<S375>/Add12'
   *  Sum: '<S375>/Add9'
   */
  if (OvlpExP_bInOverMidAdjExMid_MP) {
    OvlpExP_rPresClsExVlvMid = ((OvlpExP_rPresInMidExMid -
      OvlpExP_rPresInMaxExMid) * (((Float32)localLookUpTable_b) *
      1.525878906E-005F)) + OvlpExP_rPresInMaxExMid;
  } else {
    OvlpExP_rPresClsExVlvMid = ((OvlpExP_rPresInMinExMid -
      OvlpExP_rPresInMidExMid) * OvlpExP_facSatOpInVlvMinMid) +
      OvlpExP_rPresInMidExMid;
  }

  /* end of Outputs for SubSystem: '<S340>/F01_01_02_03_Interpoler_rPres_a_FE_mid' */

  /* Outputs for atomic SubSystem: '<S340>/F01_01_02_04_Interpoler_rPres_a_FE_min' */

  /* RelationalOperator: '<S376>/Relational Operator1' incorporates:
   *  Constant: '<S376>/OvlpExP_agCkOpInVlvMid_C'
   */
  OvlpExP_bInOverMidAdjExMin_MP = (localTmpSignalConversionAtEngM_ >=
    OvlpExP_agCkOpInVlvMid_C);

  /* Switch: '<S376>/Switch1' incorporates:
   *  Product: '<S394>/Divide'
   *  Product: '<S395>/Divide'
   *  Sum: '<S376>/Add5'
   *  Sum: '<S376>/Add6'
   *  Sum: '<S376>/Add7'
   *  Sum: '<S376>/Add8'
   */
  if (OvlpExP_bInOverMidAdjExMin_MP) {
    OvlpExP_rPresClsExVlvMin = ((OvlpExP_rPresInMidExMin -
      OvlpExP_rPresInMaxExMin) * OvlpExP_facSatOpInVlvMidMax) +
      OvlpExP_rPresInMaxExMin;
  } else {
    OvlpExP_rPresClsExVlvMin = ((OvlpExP_rPresInMinExMin -
      OvlpExP_rPresInMidExMin) * OvlpExP_facSatOpInVlvMinMid) +
      OvlpExP_rPresInMidExMin;
  }

  /* end of Outputs for SubSystem: '<S340>/F01_01_02_04_Interpoler_rPres_a_FE_min' */

  /* end of Outputs for SubSystem: '<S331>/F01_01_02_Interpoler_rPres_OA' */

  /* Outputs for atomic SubSystem: '<S331>/F01_01_03_Interpoler_rPres_FE' */

  /* Outputs for atomic SubSystem: '<S341>/F01_01_03_01_Calculer_les_coefficients_d_interpolation_en_FE' */

  /* Sum: '<S396>/Sum' incorporates:
   *  Constant: '<S396>/OvlpExP_agCkClsExVlvMid_C'
   *  Constant: '<S396>/OvlpExP_agCkClsExVlvMin_C'
   */
  locali = OvlpExP_agCkClsExVlvMid_C - OvlpExP_agCkClsExVlvMin_C;
  if (locali > 32767) {
    localTmpSignalConversionAtEngM_ = MAX_int16_T;
  } else if (locali <= -32768) {
    localTmpSignalConversionAtEngM_ = MIN_int16_T;
  } else {
    localTmpSignalConversionAtEngM_ = (SInt16)locali;
  }

  /* DataStoreWrite: '<S396>/Data Store Write1' */
  OvlpExP_agCkExDeltaMidMin_MP = localTmpSignalConversionAtEngM_;

  /* Sum: '<S396>/Sum1' incorporates:
   *  Constant: '<S396>/OvlpExP_agCkClsExVlvMax_C'
   *  Constant: '<S396>/OvlpExP_agCkClsExVlvMid_C1'
   */
  locali = OvlpExP_agCkClsExVlvMax_C - OvlpExP_agCkClsExVlvMid_C;
  if (locali > 32767) {
    locallocalSum_m = MAX_int16_T;
  } else if (locali <= -32768) {
    locallocalSum_m = MIN_int16_T;
  } else {
    locallocalSum_m = (SInt16)locali;
  }

  /* DataStoreWrite: '<S396>/Data Store Write3' */
  OvlpExP_agCkExDeltaMaxMid_MP = locallocalSum_m;

  /* DataTypeConversion: '<S396>/Data Type Conversion' */
  localDataTypeConversion_ai = ((Float32)localTmpSignalConversionAtEng_b) *
    0.09375F;

  /* Outputs for enable SubSystem: '<S396>/F01_01_03_01_01_Calculer_pente_FE_MinMid_isobornes' incorporates:
   *  Constant: '<S396>/OvlpExP_agCkClsExVlvLimThd_C'
   *  EnablePort: '<S398>/Enable'
   *  EnablePort: '<S399>/Enable'
   *  Logic: '<S396>/Logical Operator'
   *  RelationalOperator: '<S396>/Relational Operator'
   *  SubSystem: '<S396>/F01_01_03_01_02_Calculer_pente_FE_MinMid_mode_normal'
   */
  if (!(localTmpSignalConversionAtEngM_ >= OvlpExP_agCkClsExVlvLimThd_C)) {
    /* DataTypeConversion: '<S398>/Data Type Conversion' incorporates:
     *  Constant: '<S398>/OvlpExP_facClsExVlvMinMidEqu_C'
     */
    OvlpExP_facSatClsExVlvMinMid = ((Float32)OvlpExP_facClsExVlvMinMidEqu_C) *
      1.525878906E-005F;
  } else {
    /* DataTypeConversion: '<S399>/Data Type Conversion1' incorporates:
     *  Constant: '<S399>/OvlpExP_agCkClsExVlvMid_C'
     */
    localDivide_hq = ((Float32)OvlpExP_agCkClsExVlvMid_C) * 0.09375F;

    /* Product: '<S402>/Divide' incorporates:
     *  Constant: '<S399>/OvlpExP_agCkClsExVlvMin_C'
     *  DataTypeConversion: '<S399>/Data Type Conversion'
     *  Sum: '<S399>/Add2'
     *  Sum: '<S399>/Add5'
     */
    localDivide_hq = (localDivide_hq - localDataTypeConversion_ai) /
      (localDivide_hq - (((Float32)OvlpExP_agCkClsExVlvMin_C) * 0.09375F));

    /* Outputs for atomic SubSystem: '<S402>/If Action Subsystem3' */

    /* Switch: '<S404>/Switch1' incorporates:
     *  Constant: '<S404>/Constant1'
     *  Constant: '<S404>/Constant2'
     *  Constant: '<S404>/Constant3'
     *  Logic: '<S404>/Logical Operator1'
     *  RelationalOperator: '<S404>/Relational Operator'
     *  RelationalOperator: '<S404>/Relational Operator1'
     *  RelationalOperator: '<S404>/Relational Operator3'
     */
    if (((localDivide_hq != localDivide_hq) || (localDivide_hq >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hq)) {
      localDivide_hq = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S402>/If Action Subsystem3' */

    /* DataStoreWrite: '<S399>/Data Store Write3' incorporates:
     *  DataTypeConversion: '<S399>/Data Type Conversion5'
     */
    localtmp = ACTEMS_LdexpF((Float32d)localDivide_hq, 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        OvlpExP_facClsExVlvMinMid_MP = (UInt16)localtmp;
      } else {
        OvlpExP_facClsExVlvMinMid_MP = 0U;
      }
    } else {
      OvlpExP_facClsExVlvMinMid_MP = MAX_uint16_T;
    }

    /* MinMax: '<S399>/MinMax' incorporates:
     *  Constant: '<S399>/Constant1'
     */
    localDivide_hq = rt_MAXf(0.0F, localDivide_hq);

    /* MinMax: '<S399>/MinMax1' incorporates:
     *  Constant: '<S399>/Constant4'
     */
    OvlpExP_facSatClsExVlvMinMid = rt_MINf(1.0F, localDivide_hq);
  }

  /* end of Outputs for SubSystem: '<S396>/F01_01_03_01_01_Calculer_pente_FE_MinMid_isobornes' */

  /* Outputs for enable SubSystem: '<S396>/F01_01_03_01_03_Calculer_pente_FE_MidMax_isobornes' incorporates:
   *  Constant: '<S396>/OvlpExP_agCkClsExVlvLimThd_C1'
   *  EnablePort: '<S400>/Enable'
   *  EnablePort: '<S401>/Enable'
   *  Logic: '<S396>/Logical Operator1'
   *  RelationalOperator: '<S396>/Relational Operator1'
   *  SubSystem: '<S396>/F01_01_03_01_04_Calculer_pente_FE_MidMax_mode_normal'
   */
  if (!(locallocalSum_m >= OvlpExP_agCkClsExVlvLimThd_C)) {
    /* DataTypeConversion: '<S400>/Data Type Conversion' incorporates:
     *  Constant: '<S400>/OvlpExP_facClsExVlvMidMaxEqu_C'
     */
    OvlpExP_facSatClsExVlvMidMax = ((Float32)OvlpExP_facClsExVlvMidMaxEqu_C) *
      1.525878906E-005F;
  } else {
    /* DataTypeConversion: '<S401>/Data Type Conversion1' incorporates:
     *  Constant: '<S401>/OvlpExP_agCkClsExVlvMax_C'
     */
    localDivide_hq = ((Float32)OvlpExP_agCkClsExVlvMax_C) * 0.09375F;

    /* Product: '<S405>/Divide' incorporates:
     *  Constant: '<S401>/OvlpExP_agCkClsExVlvMid_C'
     *  DataTypeConversion: '<S401>/Data Type Conversion'
     *  Sum: '<S401>/Add1'
     *  Sum: '<S401>/Add4'
     */
    localDivide_hq = (localDivide_hq - localDataTypeConversion_ai) /
      (localDivide_hq - (((Float32)OvlpExP_agCkClsExVlvMid_C) * 0.09375F));

    /* Outputs for atomic SubSystem: '<S405>/If Action Subsystem3' */

    /* Switch: '<S407>/Switch1' incorporates:
     *  Constant: '<S407>/Constant1'
     *  Constant: '<S407>/Constant2'
     *  Constant: '<S407>/Constant3'
     *  Logic: '<S407>/Logical Operator1'
     *  RelationalOperator: '<S407>/Relational Operator'
     *  RelationalOperator: '<S407>/Relational Operator1'
     *  RelationalOperator: '<S407>/Relational Operator3'
     */
    if (((localDivide_hq != localDivide_hq) || (localDivide_hq >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hq)) {
      localDivide_hq = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S405>/If Action Subsystem3' */

    /* DataStoreWrite: '<S401>/Data Store Write3' incorporates:
     *  DataTypeConversion: '<S401>/Data Type Conversion5'
     */
    localtmp = ACTEMS_LdexpF((Float32d)localDivide_hq, 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        OvlpExP_facClsExVlvMidMax_MP = (UInt16)localtmp;
      } else {
        OvlpExP_facClsExVlvMidMax_MP = 0U;
      }
    } else {
      OvlpExP_facClsExVlvMidMax_MP = MAX_uint16_T;
    }

    /* MinMax: '<S401>/MinMax2' incorporates:
     *  Constant: '<S401>/Constant2'
     */
    localDivide_hq = rt_MAXf(localDivide_hq, 0.0F);

    /* MinMax: '<S401>/MinMax3' incorporates:
     *  Constant: '<S401>/Constant3'
     */
    OvlpExP_facSatClsExVlvMidMax = rt_MINf(localDivide_hq, 1.0F);
  }

  /* end of Outputs for SubSystem: '<S396>/F01_01_03_01_03_Calculer_pente_FE_MidMax_isobornes' */

  /* end of Outputs for SubSystem: '<S341>/F01_01_03_01_Calculer_les_coefficients_d_interpolation_en_FE' */

  /* Outputs for atomic SubSystem: '<S341>/F01_01_03_02_Interpoler_les_ratios_de_pressions_pour_FE_et_OA_quelconque' */

  /* RelationalOperator: '<S397>/Relational Operator2' incorporates:
   *  Constant: '<S397>/OvlpExP_agCkClsExVlvMid_C'
   */
  OvlpExP_bExOverMid_MP = (localTmpSignalConversionAtEng_b >=
    OvlpExP_agCkClsExVlvMid_C);

  /* Switch: '<S397>/Switch2' incorporates:
   *  Product: '<S408>/Divide'
   *  Product: '<S409>/Divide'
   *  Sum: '<S397>/Add10'
   *  Sum: '<S397>/Add11'
   *  Sum: '<S397>/Add12'
   *  Sum: '<S397>/Add9'
   */
  if (OvlpExP_bExOverMid_MP) {
    OvlpExP_rPresExMnf_facVlvOvlp = ((OvlpExP_rPresClsExVlvMid -
      OvlpExP_rPresClsExVlvMax) * OvlpExP_facSatClsExVlvMidMax) +
      OvlpExP_rPresClsExVlvMax;
  } else {
    OvlpExP_rPresExMnf_facVlvOvlp = ((OvlpExP_rPresClsExVlvMin -
      OvlpExP_rPresClsExVlvMid) * OvlpExP_facSatClsExVlvMinMid) +
      OvlpExP_rPresClsExVlvMid;
  }

  /* end of Outputs for SubSystem: '<S341>/F01_01_03_02_Interpoler_les_ratios_de_pressions_pour_FE_et_OA_quelconque' */

  /* end of Outputs for SubSystem: '<S331>/F01_01_03_Interpoler_rPres_FE' */

  /* end of Outputs for SubSystem: '<S9>/F01_01_Calculer_rPres' */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_pExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_pExMnfEstim'
   */
  Rte_Read_R_ExM_pExMnfEstim_ExM_pExMnfEstim(&localTmpSignalConversionAtExM_p);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_pDsTrbEstimSIOutport2' incorporates:
   *  Inport: '<Root>/ExM_pDsTrbEstimSI'
   */
  Rte_Read_R_ExM_pDsTrbEstimSI_ExM_pDsTrbEstimSI
    (&localTmpSignalConversionAtExM_f);

  /* Outputs for atomic SubSystem: '<S9>/F01_02_Calculer_P3_croisement' */

  /* Switch: '<S332>/Switch' incorporates:
   *  Constant: '<S332>/OvlpExP_bTrb_C'
   */
  if (OvlpExP_bTrb_C) {
    localTmpSignalConversionAtExM_p = localTmpSignalConversionAtExM_f;
  }

  /* Product: '<S410>/Divide' */
  localDivide_hq = (Float32)ACTEMS_FloorF((((((Float32)
    localTmpSignalConversionAtExM_p) * 8.0F) * OvlpExP_rPresExMnf_facVlvOvlp) *
    0.125F) + 0.5F);
  if (localDivide_hq < 65536.0F) {
    if (localDivide_hq >= 0.0F) {
      locallocalTmpSignalConversionAt = (UInt16)localDivide_hq;
    } else {
      locallocalTmpSignalConversionAt = 0U;
    }
  } else {
    locallocalTmpSignalConversionAt = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S9>/F01_02_Calculer_P3_croisement' */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&ExMGslT1_B.TmpSignalConversionAtEng_noExCy);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEng_noExNxtCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExNxtCyl'
   */
  Rte_Read_R_Eng_noExNxtCyl_Eng_noExNxtCyl(&localTmpSignalConversionAtEng_n);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_prm_pExMnfEstimOvlpCyl_INPUTOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_pExMnfEstimOvlpCyl_INPUT'
   */
  Rte_Read_R_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl
    ((&(ExM_prm_pExMnfEstimOvlpPrev[0])));

  /* Outputs for atomic SubSystem: '<S9>/F01_03_Vectoriser_P3_croisement' */

  /* Assignment: '<S333>/Assignment' */
  for (locali = 0; locali < 6; locali++) {
    localAssignment[locali] = ExM_prm_pExMnfEstimOvlpPrev[(locali)];
  }

  localAssignment[ExMGslT1_B.TmpSignalConversionAtEng_noExCy - 1] =
    locallocalTmpSignalConversionAt;

  /* Assignment: '<S333>/Assignment1' */
  localAssignment[localTmpSignalConversionAtEng_n - 1] =
    locallocalTmpSignalConversionAt;

  /* end of Outputs for SubSystem: '<S9>/F01_03_Vectoriser_P3_croisement' */

  /* Switch: '<S337>/Switch' incorporates:
   *  Constant: '<S337>/Byp_Fonction_SC'
   *  Constant: '<S337>/Int_BypC'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    locallocalTmpSignalConversionAt = ExM_pExMnfEstim_facVlvOvlp_B;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_pExMnfEstim_facVlvOvlpInport2' */
  Rte_Write_P_ExM_pExMnfEstim_facVlvOvlp_ExM_pExMnfEstim_facVlvOvlp
    (locallocalTmpSignalConversionAt);

  /* Switch: '<S338>/Switch' incorporates:
   *  Constant: '<S338>/Byp_Fonction_SC'
   *  Constant: '<S338>/Int_BypC'
   */
  for (locali = 0; locali < 6; locali++) {
    if (EXMGSLT1_ACTIVE_BYP_C) {
      localAssignment[locali] = ExM_prm_pExMnfEstimOvlpCyl_B[(locali)];
    }
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_prm_pExMnfEstimOvlpCylInport2' */
  Rte_Write_P_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl
    (&localAssignment);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_rGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_rGas'
   */
  Rte_Read_R_ExM_rGas_ExM_rGas(&ExMGslT1_B.TmpSignalConversionAtExM_rGasOu);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAfuA_rFlexOutport2' incorporates:
   *  Inport: '<Root>/AfuA_rFlex'
   */
  Rte_Read_R_AfuA_rFlex_AfuA_rFlex(&ExMGslT1_B.TmpSignalConversionAtAfuA_rFlex);
}

/* Start for exported function: RE_ExMGslT1_002_TEV */
void RE_ExMGslT1_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Calcul_Principal'
   */
}

/* Output and update for exported function: RE_ExMGslT1_002_TEV */
void RE_ExMGslT1_002_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localTmpSignalConversionAtEng_j;
  UInt16 localTmpSignalConversionAtEng_o;
  UInt16 localLookUpTable2D_o;
  UInt16 localLookUpTable2D_e5;
  UInt16 localLookUpTable2D_h;
  UInt16 localDataTypeConversion_mr;
  UInt16 localLookUpTable2D_n;
  UInt16 localLookUpTable2D_e4;
  UInt16 localLookUpTable2D_p;
  UInt16 localLookUpTable2D_eg;
  UInt16 localLookUpTable2D_ca;
  UInt16 localTmpSignalConversionAtIgS_e;
  UInt16 localDataTypeConversion_fj;
  UInt16 localLookUpTable2D_j1;
  UInt16 localLookUpTable2D_bf;
  UInt16 localLookUpTable2D_er;
  UInt16 localLookUpTable2D_js;
  UInt16 localLookUpTable2D_j2;
  UInt16 localLookUpTable2D_c2;
  UInt16 localLookUpTable2D_jg;
  UInt16 localLookUpTable2D_f;
  UInt16 localLookUpTable2D_c0;
  UInt16 localLookUpTable2D_i;
  UInt16 localLookUpTable_gd;
  UInt16 localLookUpTable_o;
  UInt16 localDataTypeConversion4_p;
  UInt16 localSwitch2_he;
  UInt16 localDataTypeConversion_n;
  UInt16 localSelector2;
  UInt16 localSelector2_m;
  UInt16 localSelector2_p;
  UInt16 localDataTypeConversion_id;
  UInt16 localLookUpTable_e;
  UInt16 localLookUpTable_oa;
  UInt16 localLookUpTable_j;
  UInt16 localLookUpTable_lf;
  UInt16 localLookUpTable_bh;
  UInt16 localLookUpTable_jq;
  Boolean localRte_Call_R_FRM_bLimTExIni_;
  UInt8 localLookUpTable2D_i0;
  UInt8 localLookUpTable2D_d1;
  UInt8 localLookUpTable2D_ow;
  UInt8 localDataTypeConversion1_p;
  UInt8 localDataTypeConversion1_c;
  Float32 localDataTypeConversion_l[5];
  Float32 localDataTypeConversion1_f[5];
  Boolean localTmpSignalConversionAtIgS_i;
  Float32 localDataTypeConversion2_n;
  Float32 localDataTypeConversion3_n;
  SInt16 localTmpSignalConversionAtExt_e;
  Boolean localTmpSignalConversionAtInjSy;
  Boolean localRelationalOperator1_no;
  Boolean localRelationalOperator2_k;
  Float32 localSubtract1;
  Float32 localDivide_bfr;
  Float32 localSubtract3_p;
  UInt8 localTmpSignalConversionAtEn_np;
  UInt16 localTmpSignalConversionAtEng_h[6];
  UInt16 localrtmax[6];
  UInt8 localTmpSignalConversionAtEn_hp;
  Boolean localRelationalOperator3_jv;
  UInt16 localTmpSignalConversionAtEx_pw[5];
  UInt16 localTmpSignalConversionAtExM_b[5];
  SInt16 localTmpSignalConversionAtExt_d;
  SInt16 localTmpSignalConversionAtExt_a;
  SInt16 localTmpSignalConversionAtEx_iw;
  SInt16 localTmpSignalConversionAtEx_ia;
  UInt16 localTmpSignalConversionAtExM_g;
  SInt32 localTmpSignalConversionAtEx_pn;
  UInt32 localTmpSignalConversionAtIgSys;
  UInt16 localTmpSignalConversionAtFARSp;
  UInt16 localTmpSignalConversionAtEx_fu;
  UInt16 localTmpSignalConversionAtEx_df;
  UInt16 localTmpSignalConversionAtExM_k;
  UInt16 localTmpSignalConversionAtEx_b3;
  UInt16 localMerge1;
  UInt16 localMerge10;
  UInt16 localMerge2;
  UInt16 localTmpSignalConversionAtExM_n;
  UInt16 localTmpSignalConversionAtE_b3t;
  UInt16 localTmpSignalConversionAtEx_it;
  UInt16 localTmpSignalConversionAtInThM;
  UInt16 localTmpSignalConversionAtEng_l[6];
  UInt16 localTmpSignalConversionAtExM_i;
  SInt16 localTmpSignalConversionAtEx_nq;
  UInt16 localTmpSignalConversionAtEx_fa;
  SInt16 localTmpSignalConversionAtExM_d;
  UInt16 localTmpSignalConversionAtEx_ox;
  SInt32 localTmpSignalConversionAtExM_c;
  UInt16 localTmpSignalConversionAtEx_b5;
  SInt32 localTmpSignalConversionAtEx_mt;
  UInt16 localTmpSignalConversionAtEng_g;
  SInt32 locali;
  Float32d localtmp;
  Float32 localtmp_0;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Calcul_Principal'
   */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_prm_facFlexOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_facFlex'
   */
  Rte_Read_R_ExM_prm_facFlex_ExM_prm_facFlex(&localTmpSignalConversionAtEx_pw);

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  for (locali = 0; locali < 5; locali++) {
    localDataTypeConversion_l[locali] = ((Float32)
      localTmpSignalConversionAtEx_pw[locali]) * 6.103515625E-005F;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_prm_facGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_facGas'
   */
  Rte_Read_R_ExM_prm_facGas_ExM_prm_facGas(&localTmpSignalConversionAtExM_b);

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  for (locali = 0; locali < 5; locali++) {
    localDataTypeConversion1_f[locali] = ((Float32)
      localTmpSignalConversionAtExM_b[locali]) * 6.103515625E-005F;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEng_o);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_agCkOpInVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkOpInVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0
    (&localTmpSignalConversionAtExt_a);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_agCkClsExVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkClsExVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0
    (&localTmpSignalConversionAtExt_d);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_bAcvStructAirOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAir'
   */
  Rte_Read_R_IgSys_bAcvStructAir_IgSys_bAcvStructAir
    (&localTmpSignalConversionAtIgS_i);

  /* Outputs for enable SubSystem: '<S7>/F01_Temperature_de_base' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (localTmpSignalConversionAtIgS_i) {
    /* DataTypeConversion: '<S19>/Data Type Conversion2' */
    localDataTypeConversion2_n = ((Float32)localTmpSignalConversionAtExt_d) *
      0.09375F;

    /* DataTypeConversion: '<S19>/Data Type Conversion3' */
    localDataTypeConversion3_n = ((Float32)localTmpSignalConversionAtExt_a) *
      0.09375F;

    /* Outputs for atomic SubSystem: '<S19>/F0_01_01_01_Cartos_et_calibrations' */

    /* Lookup2D: '<S45>/Look-Up Table (2-D)'
     * About '<S45>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-5  Bias 223.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_n), (&(ExM_tExMinOvlp_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S45>/Data Type Duplicate2'
     *
     * Regarding '<S45>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S46>/Look-Up Table (2-D)'
     * About '<S46>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-5  Bias 223.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_e4), (&(ExM_tExMid_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S46>/Data Type Duplicate2'
     *
     * Regarding '<S46>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S47>/Look-Up Table (2-D)'
     * About '<S47>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_j1), (&(ExM_agCkMidEx_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S47>/Data Type Duplicate2'
     *
     * Regarding '<S47>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S48>/Look-Up Table (2-D)'
     * About '<S48>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_bf), (&(ExM_agCkExCmMaxShiftIn_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S48>/Data Type Duplicate2'
     *
     * Regarding '<S48>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S49>/Look-Up Table (2-D)'
     * About '<S49>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_er), (&(ExM_agCkExCmMaxShiftEx_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S49>/Data Type Duplicate2'
     *
     * Regarding '<S49>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S50>/Look-Up Table (2-D)'
     * About '<S50>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_js), (&(ExM_agCkMaxOvlpIn_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S50>/Data Type Duplicate2'
     *
     * Regarding '<S50>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S51>/Look-Up Table (2-D)'
     * About '<S51>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_j2), (&(ExM_agCkMaxOvlpEx_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate2'
     *
     * Regarding '<S51>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S52>/Look-Up Table (2-D)'
     * About '<S52>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-5  Bias 223.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_p), (&(ExM_tExExCmMaxShift_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S52>/Data Type Duplicate2'
     *
     * Regarding '<S52>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S53>/Look-Up Table (2-D)'
     * About '<S53>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-5  Bias 223.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_eg), (&(ExM_tExMaxOvlp_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate2'
     *
     * Regarding '<S53>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S54>/Look-Up Table (2-D)'
     * About '<S54>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-5  Bias 223.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_ca), (&(ExM_tExInCmMaxShift_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate2'
     *
     * Regarding '<S54>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S55>/Look-Up Table (2-D)'
     * About '<S55>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_c2), (&(ExM_agCkInCmMaxShiftIn_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate2'
     *
     * Regarding '<S55>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S56>/Look-Up Table (2-D)'
     * About '<S56>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_jg), (&(ExM_agCkInCmMaxShiftEx_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate2'
     *
     * Regarding '<S56>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S57>/Look-Up Table (2-D)'
     * About '<S57>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_f), (&(ExM_agCkMinOvlpIn_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S57>/Data Type Duplicate2'
     *
     * Regarding '<S57>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S58>/Look-Up Table (2-D)'
     * About '<S58>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_c0), (&(ExM_agCkMinOvlpEx_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate2'
     *
     * Regarding '<S58>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S59>/Look-Up Table (2-D)'
     * About '<S59>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-1  FSlope 1.5  Bias -96.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_i), (&(ExM_agCkMidIn_M[0])),
                       localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                       localTmpSignalConversionAtEng_o, (&(ExM_rAirY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate2'
     *
     * Regarding '<S59>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S41>/Data Type Conversion' incorporates:
     *  Lookup2D: '<S49>/Look-Up Table (2-D)'
     */
    ExM_agCkExCmMaxShiftEx = (((Float32)localLookUpTable2D_er) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion1' incorporates:
     *  Lookup2D: '<S48>/Look-Up Table (2-D)'
     */
    ExM_agCkExCmMaxShiftIn = (((Float32)localLookUpTable2D_bf) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion10' incorporates:
     *  Lookup2D: '<S45>/Look-Up Table (2-D)'
     */
    ExM_tExMinOvlp = (((Float32)localLookUpTable2D_n) * 0.03125F) + 223.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion11' incorporates:
     *  Lookup2D: '<S46>/Look-Up Table (2-D)'
     */
    ExM_tExMid = (((Float32)localLookUpTable2D_e4) * 0.03125F) + 223.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion12' incorporates:
     *  Lookup2D: '<S52>/Look-Up Table (2-D)'
     */
    ExM_tExExCmMaxShift = (((Float32)localLookUpTable2D_p) * 0.03125F) + 223.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion13' incorporates:
     *  Lookup2D: '<S53>/Look-Up Table (2-D)'
     */
    ExM_tExMaxOvlp = (((Float32)localLookUpTable2D_eg) * 0.03125F) + 223.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion14' incorporates:
     *  Lookup2D: '<S47>/Look-Up Table (2-D)'
     */
    ExM_agCkMidEx = (((Float32)localLookUpTable2D_j1) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion2' incorporates:
     *  Lookup2D: '<S50>/Look-Up Table (2-D)'
     */
    ExM_agCkMaxOvlpIn = (((Float32)localLookUpTable2D_js) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion3' incorporates:
     *  Lookup2D: '<S51>/Look-Up Table (2-D)'
     */
    ExM_agCkMaxOvlpEx = (((Float32)localLookUpTable2D_j2) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion4' incorporates:
     *  Lookup2D: '<S59>/Look-Up Table (2-D)'
     */
    ExM_agCkMidIn = (((Float32)localLookUpTable2D_i) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion5' incorporates:
     *  Lookup2D: '<S58>/Look-Up Table (2-D)'
     */
    ExM_agCkMinOvlpEx = (((Float32)localLookUpTable2D_c0) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion6' incorporates:
     *  Lookup2D: '<S57>/Look-Up Table (2-D)'
     */
    ExM_agCkMinOvlpIn = (((Float32)localLookUpTable2D_f) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion7' incorporates:
     *  Lookup2D: '<S56>/Look-Up Table (2-D)'
     */
    ExM_agCkInCmMaxShiftEx = (((Float32)localLookUpTable2D_jg) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion8' incorporates:
     *  Lookup2D: '<S55>/Look-Up Table (2-D)'
     */
    ExM_agCkInCmMaxShiftIn = (((Float32)localLookUpTable2D_c2) * 0.75F) - 96.0F;

    /* DataTypeConversion: '<S41>/Data Type Conversion9' incorporates:
     *  Lookup2D: '<S54>/Look-Up Table (2-D)'
     */
    ExM_tExInCmMaxShift = (((Float32)localLookUpTable2D_ca) * 0.03125F) +
      223.0F;

    /* end of Outputs for SubSystem: '<S19>/F0_01_01_01_Cartos_et_calibrations' */

    /* Outputs for atomic SubSystem: '<S19>/F0_01_01_02_Choix_des_points_du_plan' */

    /* RelationalOperator: '<S42>/Relational Operator1' */
    localRelationalOperator1_no = (localDataTypeConversion3_n > ExM_agCkMidIn);

    /* RelationalOperator: '<S42>/Relational Operator2' */
    localRelationalOperator2_k = (localDataTypeConversion2_n > ExM_agCkMidEx);

    /* Switch: '<S42>/Switch4' */
    if (localRelationalOperator1_no) {
      ExM_agCkOvlpEx_MP = ExM_agCkMinOvlpEx;
    } else {
      ExM_agCkOvlpEx_MP = ExM_agCkMaxOvlpEx;
    }

    /* Sum: '<S42>/Subtract1' */
    localSubtract1 = ExM_agCkOvlpEx_MP - ExM_agCkMidEx;

    /* Switch: '<S42>/Switch1' */
    if (localRelationalOperator1_no) {
      ExM_agCkOvlpIn_MP = ExM_agCkMinOvlpIn;
    } else {
      ExM_agCkOvlpIn_MP = ExM_agCkMaxOvlpIn;
    }

    /* Product: '<S62>/Divide' incorporates:
     *  Sum: '<S42>/Subtract2'
     */
    localDivide_bfr = localSubtract1 / (ExM_agCkOvlpIn_MP - ExM_agCkMidIn);

    /* Outputs for atomic SubSystem: '<S62>/If Action Subsystem3' */

    /* Switch: '<S71>/Switch1' incorporates:
     *  Constant: '<S71>/Constant1'
     *  Constant: '<S71>/Constant3'
     *  Logic: '<S71>/Logical Operator1'
     *  RelationalOperator: '<S71>/Relational Operator'
     *  RelationalOperator: '<S71>/Relational Operator1'
     *  RelationalOperator: '<S71>/Relational Operator3'
     */
    if (((localDivide_bfr != localDivide_bfr) || (localDivide_bfr >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_bfr)) {
      ExM_agCkGrdMaxShift_MP = localSubtract1;
    } else {
      ExM_agCkGrdMaxShift_MP = localDivide_bfr;
    }

    /* end of Outputs for SubSystem: '<S62>/If Action Subsystem3' */

    /* Sum: '<S42>/Subtract4' incorporates:
     *  Product: '<S64>/Divide'
     *  Product: '<S65>/Divide'
     *  Sum: '<S42>/Subtract5'
     */
    ExM_agCkClsExVlvVirt_MP = (ExM_agCkMidEx - (ExM_agCkGrdMaxShift_MP *
      ExM_agCkMidIn)) + (localDataTypeConversion3_n * ExM_agCkGrdMaxShift_MP);

    /* RelationalOperator: '<S42>/Relational Operator3' */
    ExM_bAcvPts3_MP = (localDataTypeConversion2_n <= ExM_agCkClsExVlvVirt_MP);

    /* Switch: '<S42>/Switch5' */
    if (localRelationalOperator2_k) {
      ExM_agCkMaxShiftEx_MP = ExM_agCkExCmMaxShiftEx;
    } else {
      ExM_agCkMaxShiftEx_MP = ExM_agCkInCmMaxShiftEx;
    }

    /* Sum: '<S42>/Subtract3' */
    localSubtract3_p = ExM_agCkMaxShiftEx_MP - ExM_agCkMidEx;

    /* Switch: '<S42>/Switch2' */
    if (localRelationalOperator2_k) {
      ExM_agCkMaxShiftIn_MP = ExM_agCkExCmMaxShiftIn;
    } else {
      ExM_agCkMaxShiftIn_MP = ExM_agCkInCmMaxShiftIn;
    }

    /* Product: '<S63>/Divide' incorporates:
     *  Sum: '<S42>/Subtract6'
     */
    localSubtract1 = localSubtract3_p / (ExM_agCkMaxShiftIn_MP - ExM_agCkMidIn);

    /* Outputs for atomic SubSystem: '<S63>/If Action Subsystem3' */

    /* Switch: '<S73>/Switch1' incorporates:
     *  Constant: '<S73>/Constant1'
     *  Constant: '<S73>/Constant3'
     *  Logic: '<S73>/Logical Operator1'
     *  RelationalOperator: '<S73>/Relational Operator'
     *  RelationalOperator: '<S73>/Relational Operator1'
     *  RelationalOperator: '<S73>/Relational Operator3'
     */
    if (((localSubtract1 != localSubtract1) || (localSubtract1 >
          3.000000005E+038F)) || (-3.000000005E+038F > localSubtract1)) {
      ExM_agCkGrdOvlp_MP = localSubtract3_p;
    } else {
      ExM_agCkGrdOvlp_MP = localSubtract1;
    }

    /* end of Outputs for SubSystem: '<S63>/If Action Subsystem3' */

    /* Product: '<S60>/Divide' */
    localSubtract1 = localDataTypeConversion2_n / ExM_agCkGrdOvlp_MP;

    /* Outputs for atomic SubSystem: '<S60>/If Action Subsystem3' */

    /* Switch: '<S67>/Switch1' incorporates:
     *  Constant: '<S67>/Constant1'
     *  Constant: '<S67>/Constant3'
     *  Logic: '<S67>/Logical Operator1'
     *  RelationalOperator: '<S67>/Relational Operator'
     *  RelationalOperator: '<S67>/Relational Operator1'
     *  RelationalOperator: '<S67>/Relational Operator3'
     */
    if (((localSubtract1 != localSubtract1) || (localSubtract1 >
          3.000000005E+038F)) || (-3.000000005E+038F > localSubtract1)) {
      localSubtract1 = localDataTypeConversion2_n;
    }

    /* end of Outputs for SubSystem: '<S60>/If Action Subsystem3' */

    /* Product: '<S61>/Divide' */
    localDivide_bfr = ExM_agCkMidEx / ExM_agCkGrdOvlp_MP;

    /* Outputs for atomic SubSystem: '<S61>/If Action Subsystem3' */

    /* Switch: '<S69>/Switch1' incorporates:
     *  Constant: '<S69>/Constant1'
     *  Constant: '<S69>/Constant3'
     *  Logic: '<S69>/Logical Operator1'
     *  RelationalOperator: '<S69>/Relational Operator'
     *  RelationalOperator: '<S69>/Relational Operator1'
     *  RelationalOperator: '<S69>/Relational Operator3'
     */
    if (((localDivide_bfr != localDivide_bfr) || (localDivide_bfr >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_bfr)) {
      localDivide_bfr = ExM_agCkMidEx;
    }

    /* end of Outputs for SubSystem: '<S61>/If Action Subsystem3' */

    /* Sum: '<S42>/Subtract9' incorporates:
     *  Sum: '<S42>/Subtract7'
     */
    ExM_agCkOpInVlvVirt_MP = (localSubtract1 + ExM_agCkMidIn) - localDivide_bfr;

    /* RelationalOperator: '<S42>/Relational Operator5' */
    ExM_bAcvPts2_MP = (localDataTypeConversion3_n > ExM_agCkOpInVlvVirt_MP);

    /* Switch: '<S42>/Switch10' */
    if (ExM_bAcvPts2_MP) {
      ExM_agCkInCmPts2 = ExM_agCkMinOvlpIn;
    } else {
      ExM_agCkInCmPts2 = ExM_agCkMaxOvlpIn;
    }

    /* Switch: '<S42>/Switch11' */
    if (ExM_bAcvPts3_MP) {
      ExM_agCkExCmPts3 = ExM_agCkInCmMaxShiftEx;
    } else {
      ExM_agCkExCmPts3 = ExM_agCkExCmMaxShiftEx;
    }

    /* Switch: '<S42>/Switch12' */
    if (ExM_bAcvPts3_MP) {
      ExM_agCkInCmPts3 = ExM_agCkInCmMaxShiftIn;
    } else {
      ExM_agCkInCmPts3 = ExM_agCkExCmMaxShiftIn;
    }

    /* Switch: '<S42>/Switch3' */
    if (ExM_bAcvPts2_MP) {
      ExM_tExPts2 = ExM_tExMinOvlp;
    } else {
      ExM_tExPts2 = ExM_tExMaxOvlp;
    }

    /* Switch: '<S42>/Switch6' */
    if (ExM_bAcvPts3_MP) {
      ExM_tExPts3 = ExM_tExInCmMaxShift;
    } else {
      ExM_tExPts3 = ExM_tExExCmMaxShift;
    }

    /* Switch: '<S42>/Switch9' */
    if (ExM_bAcvPts2_MP) {
      ExM_agCkExCmPts2 = ExM_agCkMinOvlpEx;
    } else {
      ExM_agCkExCmPts2 = ExM_agCkMaxOvlpEx;
    }

    /* end of Outputs for SubSystem: '<S19>/F0_01_01_02_Choix_des_points_du_plan' */

    /* Outputs for atomic SubSystem: '<S19>/F0_01_01_03_Equation_du_plan' */

    /* Sum: '<S43>/Subtract1' */
    ExM_agCkInCmDelta_MP = ExM_agCkInCmPts3 - ExM_agCkMidIn;

    /* Sum: '<S43>/Subtract6' */
    ExM_agCkExCmDelta2_MP = ExM_agCkExCmPts2 - ExM_agCkMidEx;

    /* Sum: '<S43>/Subtract5' */
    ExM_agCkInCmDelta2_MP = ExM_agCkInCmPts2 - ExM_agCkMidIn;

    /* Sum: '<S43>/Subtract4' */
    ExM_agCkExCmDelta_MP = ExM_agCkExCmPts3 - ExM_agCkMidEx;

    /* Sum: '<S43>/Subtract10' incorporates:
     *  Product: '<S76>/Divide'
     *  Product: '<S77>/Divide'
     */
    ExM_fac3 = (ExM_agCkInCmDelta_MP * ExM_agCkExCmDelta2_MP) -
      (ExM_agCkInCmDelta2_MP * ExM_agCkExCmDelta_MP);

    /* Sum: '<S43>/Subtract2' */
    ExM_tExDelta_MP = ExM_tExPts3 - ExM_tExMid;

    /* Sum: '<S43>/Subtract7' */
    ExM_tExDelta2_MP = ExM_tExPts2 - ExM_tExMid;

    /* Sum: '<S43>/Subtract9' incorporates:
     *  Product: '<S74>/Divide'
     *  Product: '<S75>/Divide'
     */
    ExM_fac2 = (ExM_agCkInCmDelta2_MP * ExM_tExDelta_MP) - (ExM_agCkInCmDelta_MP
      * ExM_tExDelta2_MP);

    /* Sum: '<S43>/Subtract8' incorporates:
     *  Product: '<S78>/Divide'
     *  Product: '<S79>/Divide'
     */
    ExM_fac1 = (ExM_agCkExCmDelta_MP * ExM_tExDelta2_MP) -
      (ExM_agCkExCmDelta2_MP * ExM_tExDelta_MP);

    /* Sum: '<S43>/Subtract3' incorporates:
     *  Product: '<S80>/Divide'
     *  Product: '<S81>/Divide'
     *  Product: '<S82>/Divide'
     */
    ExM_fac4 = ((ExM_agCkMidEx * ExM_fac2) + (ExM_fac3 * ExM_tExMid)) +
      (ExM_fac1 * ExM_agCkMidIn);

    /* end of Outputs for SubSystem: '<S19>/F0_01_01_03_Equation_du_plan' */

    /* Outputs for atomic SubSystem: '<S19>/F0_01_01_04_Temperature_d_echappement_par_l_equation_du_plan' */

    /* RelationalOperator: '<S44>/Relational Operator2' incorporates:
     *  Constant: '<S44>/Cste_0'
     */
    ExM_bDivZeroTExBas_MP = (ExM_fac3 == 0.0F);

    /* Switch: '<S44>/Switch2' incorporates:
     *  Constant: '<S44>/Cste_1__2'
     */
    if (ExM_bDivZeroTExBas_MP) {
      localSubtract1 = 1.0F;
    } else {
      localSubtract1 = ExM_fac3;
    }

    /* Product: '<S83>/Divide' */
    localSubtract1 = ExM_fac4 / localSubtract1;

    /* Outputs for atomic SubSystem: '<S83>/If Action Subsystem3' */

    /* Switch: '<S89>/Switch1' incorporates:
     *  Constant: '<S89>/Constant1'
     *  Constant: '<S89>/Constant2'
     *  Constant: '<S89>/Constant3'
     *  Logic: '<S89>/Logical Operator1'
     *  RelationalOperator: '<S89>/Relational Operator'
     *  RelationalOperator: '<S89>/Relational Operator1'
     *  RelationalOperator: '<S89>/Relational Operator3'
     */
    if (((localSubtract1 != localSubtract1) || (localSubtract1 >
          3.000000005E+038F)) || (-3.000000005E+038F > localSubtract1)) {
      ExM_tStepClc1_MP = 0.0F;
    } else {
      ExM_tStepClc1_MP = localSubtract1;
    }

    /* end of Outputs for SubSystem: '<S83>/If Action Subsystem3' */

    /* Switch: '<S44>/Switch1' incorporates:
     *  Constant: '<S44>/Cste_1__1'
     */
    if (ExM_bDivZeroTExBas_MP) {
      localSubtract1 = 1.0F;
    } else {
      localSubtract1 = ExM_fac3;
    }

    /* Product: '<S84>/Divide' incorporates:
     *  Product: '<S86>/Divide'
     */
    localDivide_bfr = (ExM_fac1 * localDataTypeConversion3_n) / localSubtract1;

    /* Outputs for atomic SubSystem: '<S84>/If Action Subsystem3' */

    /* Switch: '<S91>/Switch1' incorporates:
     *  Constant: '<S91>/Constant1'
     *  Constant: '<S91>/Constant2'
     *  Constant: '<S91>/Constant3'
     *  Logic: '<S91>/Logical Operator1'
     *  RelationalOperator: '<S91>/Relational Operator'
     *  RelationalOperator: '<S91>/Relational Operator1'
     *  RelationalOperator: '<S91>/Relational Operator3'
     */
    if (((localDivide_bfr != localDivide_bfr) || (localDivide_bfr >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_bfr)) {
      localDivide_bfr = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S84>/If Action Subsystem3' */

    /* Switch: '<S44>/Switch4' incorporates:
     *  Constant: '<S44>/Cste_1'
     */
    if (ExM_bDivZeroTExBas_MP) {
      localSubtract1 = 1.0F;
    } else {
      localSubtract1 = ExM_fac3;
    }

    /* Product: '<S85>/Divide' incorporates:
     *  Product: '<S87>/Divide'
     */
    localSubtract1 = (ExM_fac2 * localDataTypeConversion2_n) / localSubtract1;

    /* Outputs for atomic SubSystem: '<S85>/If Action Subsystem3' */

    /* Switch: '<S93>/Switch1' incorporates:
     *  Constant: '<S93>/Constant1'
     *  Constant: '<S93>/Constant2'
     *  Constant: '<S93>/Constant3'
     *  Logic: '<S93>/Logical Operator1'
     *  RelationalOperator: '<S93>/Relational Operator'
     *  RelationalOperator: '<S93>/Relational Operator1'
     *  RelationalOperator: '<S93>/Relational Operator3'
     */
    if (((localSubtract1 != localSubtract1) || (localSubtract1 >
          3.000000005E+038F)) || (-3.000000005E+038F > localSubtract1)) {
      localSubtract1 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S85>/If Action Subsystem3' */

    /* Sum: '<S44>/Subtract2' */
    ExM_tStepClc2_MP = ExM_tStepClc1_MP - localDivide_bfr;

    /* Switch: '<S44>/Switch3' incorporates:
     *  Constant: '<S44>/Cste_373'
     *  Sum: '<S44>/Subtract3'
     */
    if (ExM_bDivZeroTExBas_MP) {
      ExM_tExBas = 373.0F;
    } else {
      ExM_tExBas = ExM_tStepClc2_MP - localSubtract1;
    }

    /* end of Outputs for SubSystem: '<S19>/F0_01_01_04_Temperature_d_echappement_par_l_equation_du_plan' */
  }

  /* end of Outputs for SubSystem: '<S7>/F01_Temperature_de_base' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExFlexOfsOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExFlexOfs'
   */
  Rte_Read_R_ExM_tExFlexOfs_ExM_tExFlexOfs(&localTmpSignalConversionAtEx_ia);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExFlexOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExFlex'
   */
  Rte_Read_R_ExM_tExFlex_ExM_tExFlex(&localTmpSignalConversionAtExM_g);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExOfsOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExOfs'
   */
  Rte_Read_R_ExM_tExOfs_ExM_tExOfs(&localTmpSignalConversionAtEx_iw);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExGas'
   */
  Rte_Read_R_ExM_tExGas_ExM_tExGas(&localTmpSignalConversionAtEx_pn);

  /* Outputs for atomic SubSystem: '<S7>/F02_Plug_In_Temperature_de_base' */

  /* Selector: '<S20>/Selector1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  localDivide_bfr = localDataTypeConversion_l[0];

  /* Switch: '<S99>/Switch2' incorporates:
   *  Constant: '<S94>/Constant'
   *  RelationalOperator: '<S99>/LowerRelop1'
   */
  if (localDataTypeConversion_l[0] > 1.0F) {
    localDivide_bfr = 1.0F;
  }

  /* Sum: '<S20>/Sum1' incorporates:
   *  DataTypeConversion: '<S20>/Data Type Conversion2'
   */
  localSubtract1 = ((((Float32)localTmpSignalConversionAtEx_iw) * 0.03125F) +
                    0.03125F) + ExM_tExBas;

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/ExM_bAcvFlex_C'
   *  DataTypeConversion: '<S20>/Data Type Conversion1'
   */
  if (ExM_bAcvFlex_C) {
    localSubtract3_p = (((Float32)localTmpSignalConversionAtExM_g) * 0.03125F)
      + 223.0F;
  } else {
    localSubtract3_p = ExM_tExBas;
  }

  /* Sum: '<S94>/Sum2' incorporates:
   *  DataTypeConversion: '<S20>/Data Type Conversion11'
   *  Product: '<S94>/Divide'
   *  Sum: '<S20>/Sum'
   *  Sum: '<S94>/Sum3'
   */
  ExM_tExBasGslFlex_MP = (((((((Float32)localTmpSignalConversionAtEx_ia) *
    0.03125F) + 0.03125F) + localSubtract3_p) - localSubtract1) *
    localDivide_bfr) + localSubtract1;

  /* Selector: '<S20>/Selector2' incorporates:
   *  Constant: '<S20>/Constant1'
   */
  localSubtract3_p = localDataTypeConversion1_f[0];

  /* Switch: '<S103>/Switch2' incorporates:
   *  Constant: '<S95>/Constant'
   *  RelationalOperator: '<S103>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[0] > 1.0F) {
    localSubtract3_p = 1.0F;
  }

  /* DataTypeConversion: '<S20>/Data Type Conversion3' */
  localSubtract1 = ((Float32)localTmpSignalConversionAtEx_pn) * 0.03125F;

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S20>/ExM_bAcvGas_C'
   *  Sum: '<S20>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localSubtract1 += ExM_tExBasGslFlex_MP;
  }

  /* Sum: '<S95>/Sum2' incorporates:
   *  Product: '<S95>/Divide'
   *  Sum: '<S95>/Sum3'
   */
  ExM_tExBasCor = ((localSubtract1 - ExM_tExBasGslFlex_MP) * localSubtract3_p) +
    ExM_tExBasGslFlex_MP;

  /* end of Outputs for SubSystem: '<S7>/F02_Plug_In_Temperature_de_base' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_lamClcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_lamClc'
   */
  Rte_Read_R_IgSys_lamClc_IgSys_lamClc(&localTmpSignalConversionAtIgSys);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&localTmpSignalConversionAtFARSp);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_mfTotExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfTotExCor'
   */
  Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor(&localTmpSignalConversionAtEng_j);

  /* Outputs for atomic SubSystem: '<S7>/F03_Correction_lamda' */

  /* DataTypeConversion: '<S21>/Data Type Conversion1' */
  localSubtract1 = ((Float32)localTmpSignalConversionAtFARSp) * 0.000244140625F;

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S21>/Cste'
   *  Constant: '<S21>/Cste_1'
   *  Constant: '<S21>/ExM_bLamClc_C'
   *  DataTypeConversion: '<S21>/Data Type Conversion11'
   *  MinMax: '<S21>/MinMax'
   *  Product: '<S105>/Divide'
   */
  if (ExM_bLamClc_C) {
    ExM_lam = ((Float32)localTmpSignalConversionAtIgSys) * 0.0001220703125F;
  } else {
    ExM_lam = 1.0F / rt_MAXf(localSubtract1, 1.000000015E-001F);
  }

  /* DataTypeConversion: '<S104>/Data Type Conversion' */
  localtmp = ((Float32d)ExM_lam) / 0.001F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion_n = (UInt16)localtmp;
    } else {
      localDataTypeConversion_n = 0U;
    }
  } else {
    localDataTypeConversion_n = MAX_uint16_T;
  }

  /* Lookup2D: '<S104>/Look-Up Table (2-D)'
   * About '<S104>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
   * Input1  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U8  2^-7  Bias 0.0078125
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U8_U16_U16( &(localLookUpTable2D_ow), (&(ExM_facLamCorGsl_M[0])),
                    localDataTypeConversion_n, (&(ExM_lamClcX_A[0])), 10U,
                    localTmpSignalConversionAtEng_j, (&(ExM_mfTotExCorY_A[0])),
                    8U);

  /* DataTypeDuplicate Block: '<S104>/Data Type Duplicate2'
   *
   * Regarding '<S104>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S21>/Data Type Conversion3' incorporates:
   *  Lookup2D: '<S104>/Look-Up Table (2-D)'
   */
  ExM_facLamCorGsl = (((Float32)localLookUpTable2D_ow) * 0.0078125F) +
    0.0078125F;

  /* end of Outputs for SubSystem: '<S7>/F03_Correction_lamda' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_facLamCorFlexOutport2' incorporates:
   *  Inport: '<Root>/ExM_facLamCorFlex'
   */
  Rte_Read_R_ExM_facLamCorFlex_ExM_facLamCorFlex
    (&localTmpSignalConversionAtEx_fu);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_facLamCorGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_facLamCorGas'
   */
  Rte_Read_R_ExM_facLamCorGas_ExM_facLamCorGas(&localTmpSignalConversionAtEx_df);

  /* Outputs for atomic SubSystem: '<S7>/F04_Plug_In_Correction_lamda' */

  /* Selector: '<S22>/Selector1' incorporates:
   *  Constant: '<S22>/Constant1'
   */
  localSubtract1 = localDataTypeConversion_l[1];

  /* Switch: '<S111>/Switch2' incorporates:
   *  Constant: '<S106>/Constant'
   *  RelationalOperator: '<S111>/LowerRelop1'
   */
  if (localDataTypeConversion_l[1] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Sum: '<S106>/Sum2' incorporates:
   *  DataTypeConversion: '<S22>/Data Type Conversion2'
   *  Product: '<S106>/Divide'
   *  Sum: '<S106>/Sum3'
   */
  ExM_facLamGslFlex_MP = (((((Float32)localTmpSignalConversionAtEx_fu) *
    6.103515625E-005F) - ExM_facLamCorGsl) * localSubtract1) + ExM_facLamCorGsl;

  /* Selector: '<S22>/Selector2' incorporates:
   *  Constant: '<S22>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[1];

  /* Switch: '<S115>/Switch2' incorporates:
   *  Constant: '<S107>/Constant'
   *  RelationalOperator: '<S115>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[1] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion3' */
  localDivide_bfr = (((Float32)localTmpSignalConversionAtEx_df) *
                     6.103515625E-005F) - 1.999938965E+000F;

  /* Switch: '<S22>/Switch1' incorporates:
   *  Constant: '<S22>/ExM_bAcvGas_C'
   *  Sum: '<S22>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_facLamGslFlex_MP;
  }

  /* Sum: '<S107>/Sum2' incorporates:
   *  Product: '<S107>/Divide'
   *  Sum: '<S107>/Sum3'
   */
  ExM_facLamCor = ((localDivide_bfr - ExM_facLamGslFlex_MP) * localSubtract1) +
    ExM_facLamGslFlex_MP;

  /* end of Outputs for SubSystem: '<S7>/F04_Plug_In_Correction_lamda' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_rDynIgSpEfcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rDynIgSpEfc'
   */
  Rte_Read_R_IgSys_rDynIgSpEfc_IgSys_rDynIgSpEfc
    (&localTmpSignalConversionAtIgS_e);

  /* Outputs for enable SubSystem: '<S7>/F05_Correction_avance' incorporates:
   *  EnablePort: '<S23>/Enable'
   */
  if (localTmpSignalConversionAtIgS_i) {
    /* Lookup2D: '<S116>/Look-Up Table (2-D)'
     * About '<S116>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-10
     * Input1  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U8  2^-7  Bias 0.0078125
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localLookUpTable2D_d1), (&(ExM_facIgCorGsl_M[0])),
                      localTmpSignalConversionAtIgS_e, (&(ExM_rDynIgSpEfcX_A[0])),
                      5U, localTmpSignalConversionAtEng_j, (&(ExM_mfTotExCorY_A
      [0])), 8U);

    /* DataTypeDuplicate Block: '<S116>/Data Type Duplicate2'
     *
     * Regarding '<S116>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S23>/Data Type Conversion' incorporates:
     *  Lookup2D: '<S116>/Look-Up Table (2-D)'
     */
    ExM_facIgCorGsl = (((Float32)localLookUpTable2D_d1) * 0.0078125F) +
      0.0078125F;
  }

  /* end of Outputs for SubSystem: '<S7>/F05_Correction_avance' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_facIgCorFlexOutport2' incorporates:
   *  Inport: '<Root>/ExM_facIgCorFlex'
   */
  Rte_Read_R_ExM_facIgCorFlex_ExM_facIgCorFlex(&localTmpSignalConversionAtExM_k);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_facIgCorGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_facIgCorGas'
   */
  Rte_Read_R_ExM_facIgCorGas_ExM_facIgCorGas(&localTmpSignalConversionAtEx_b3);

  /* Outputs for atomic SubSystem: '<S7>/F06_Plug_In_Correction_avance' */

  /* Selector: '<S24>/Selector1' incorporates:
   *  Constant: '<S24>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[2];

  /* Switch: '<S122>/Switch2' incorporates:
   *  Constant: '<S117>/Constant'
   *  RelationalOperator: '<S122>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[2] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Selector: '<S24>/Selector2' incorporates:
   *  Constant: '<S24>/Constant1'
   */
  localDivide_bfr = localDataTypeConversion_l[2];

  /* Switch: '<S126>/Switch2' incorporates:
   *  Constant: '<S118>/Constant'
   *  RelationalOperator: '<S126>/LowerRelop1'
   */
  if (localDataTypeConversion_l[2] > 1.0F) {
    localDivide_bfr = 1.0F;
  }

  /* Sum: '<S118>/Sum2' incorporates:
   *  DataTypeConversion: '<S24>/Data Type Conversion2'
   *  Product: '<S118>/Divide'
   *  Sum: '<S118>/Sum3'
   */
  ExM_facIgGslFlex_MP = (((((Float32)localTmpSignalConversionAtExM_k) *
    6.103515625E-005F) - ExM_facIgCorGsl) * localDivide_bfr) + ExM_facIgCorGsl;

  /* DataTypeConversion: '<S24>/Data Type Conversion1' */
  localDivide_bfr = (((Float32)localTmpSignalConversionAtEx_b3) *
                     6.103515625E-005F) - 1.999938965E+000F;

  /* Switch: '<S24>/Switch1' incorporates:
   *  Constant: '<S24>/ExM_bAcvGas_C'
   *  Sum: '<S24>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_facIgGslFlex_MP;
  }

  /* Sum: '<S117>/Sum2' incorporates:
   *  Product: '<S117>/Divide'
   *  Sum: '<S117>/Sum3'
   */
  ExM_facIgCor = ((localDivide_bfr - ExM_facIgGslFlex_MP) * localSubtract1) +
    ExM_facIgGslFlex_MP;

  /* end of Outputs for SubSystem: '<S7>/F06_Plug_In_Correction_avance' */

  /* S-Function (sfun_autosar_clientop): '<S31>/Rte_Call_R_FRM_bLimTExIni_tCo_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bLimTExIni_tCo_GetFunctionPermission
    (&localRte_Call_R_FRM_bLimTExIni_);

  /* Logic: '<S31>/Not' */
  localRelationalOperator1_no = !localRte_Call_R_FRM_bLimTExIni_;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_e);

  /* Outputs for atomic SubSystem: '<S7>/F07_Correction_temperature_moteur' */

  /* Switch: '<S25>/Switch11' incorporates:
   *  Constant: '<S25>/ExM_tLimTExIni_C'
   *  DataTypeConversion: '<S25>/Data Type Conversion1'
   *  DataTypeConversion: '<S25>/Data Type Conversion2'
   */
  if (localRelationalOperator1_no) {
    ExM_tCoMesSwt = (Float32)ExM_tLimTExIni_C;
  } else {
    ExM_tCoMesSwt = (Float32)localTmpSignalConversionAtExt_e;
  }

  /* Sum: '<S25>/Subtract4' incorporates:
   *  Constant: '<S25>/ExM_tCoHot_C'
   *  DataTypeConversion: '<S25>/Data Type Conversion3'
   */
  ExM_tCoDelta_MP = (((Float32)ExM_tCoHot_C) - 40.0F) - ExM_tCoMesSwt;

  /* DataTypeConversion: '<S127>/Data Type Conversion1' */
  localtmp = ((Float32d)ExM_tCoDelta_MP) + 80.0F;
  if (localtmp < 256.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion1_p = (UInt8)localtmp;
    } else {
      localDataTypeConversion1_p = 0U;
    }
  } else {
    localDataTypeConversion1_p = MAX_uint8_T;
  }

  /* Lookup2D: '<S127>/Look-Up Table (2-D)'
   * About '<S127>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U8  Bias -80.0
   * Output0 Data Type:  Fixed Point    U8  2^-7  Bias 0.0078125
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U8_U16_U8( &(localLookUpTable2D_i0), (&(ExM_facTCoCor_M[0])),
                   localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                   localDataTypeConversion1_p, (&(ExM_tCoDeltaY_A[0])), 9U);

  /* DataTypeDuplicate Block: '<S127>/Data Type Duplicate2'
   *
   * Regarding '<S127>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S25>/Data Type Conversion' incorporates:
   *  Lookup2D: '<S127>/Look-Up Table (2-D)'
   */
  ExM_facTCoCor = (((Float32)localLookUpTable2D_i0) * 0.0078125F) + 0.0078125F;

  /* end of Outputs for SubSystem: '<S7>/F07_Correction_temperature_moteur' */

  /* Outputs for enable SubSystem: '<S7>/F08_Calcul' incorporates:
   *  EnablePort: '<S26>/Enable'
   */
  if (localTmpSignalConversionAtIgS_i) {
    /* Lookup: '<S128>/Look-Up Table'
     * About '<S128>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-14  FSlope 1.6384
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_e), (&(ExM_facNEngTExStatAfs_T[0])),
                   localTmpSignalConversionAtExt_n, (&(ExM_nEngTExStatAfs_A[0])),
                   15U);

    /* DataTypeDuplicate Block: '<S128>/Data Type Duplicate1'
     *
     * Regarding '<S128>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S144>/Data Type Duplicate'
     *
     * Regarding '<S144>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S145>/Data Type Duplicate'
     *
     * Regarding '<S145>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S146>/Data Type Propagation'
     *
     * Regarding '<S146>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S144>/Conversion' incorporates:
     *  Constant: '<S129>/Constant1'
     */
    localTmpSignalConversionAtEx_fu = 9984U;

    /* Switch: '<S146>/Switch2' incorporates:
     *  RelationalOperator: '<S146>/LowerRelop1'
     *  RelationalOperator: '<S146>/UpperRelop'
     *  Switch: '<S146>/Switch'
     */
    if (!(localLookUpTable_e > 9984)) {
      localTmpSignalConversionAtEx_fu = localLookUpTable_e;
    }

    /* Product: '<S134>/Divide' incorporates:
     *  Product: '<S136>/Divide'
     */
    localSubtract1 = (ExM_tExBasCor * ExM_facTCoCor) * ExM_facIgCor;

    /* Switch: '<S141>/Switch' incorporates:
     *  UnitDelay: '<S141>/UnitDelay'
     *  UnitDelay: '<S141>/UnitDelay1'
     */
    if (ExMGslT1_DWork.UnitDelay_o) {
      localDivide_bfr = ExMGslT1_DWork.UnitDelay_l;
    } else {
      localDivide_bfr = localSubtract1;
    }

    /* Sum: '<S129>/Sum2' incorporates:
     *  Constant: '<S129>/Constant3'
     *  Product: '<S142>/Divide'
     *  Product: '<S143>/Divide'
     *  Sum: '<S129>/Sum1'
     */
    localSubtract3_p = ((1.0F - (((Float32)localTmpSignalConversionAtEx_fu) *
      9.999999747E-005F)) * localDivide_bfr) + ((Float32)((((Float32d)
      localTmpSignalConversionAtEx_fu) * 0.0001F) * ((Float32d)localSubtract1)));

    /* Switch: '<S140>/Switch' incorporates:
     *  UnitDelay: '<S140>/UnitDelay'
     */
    if (ExMGslT1_DWork.UnitDelay_DSTATE_o) {
      localDivide_bfr = localSubtract3_p;
    } else {
      localDivide_bfr = localSubtract1;
    }

    /* DataTypeConversion: '<S130>/OutDTConv' incorporates:
     *  Constant: '<S130>/offset'
     *  Constant: '<S130>/one_on_slope'
     *  Product: '<S130>/Product4'
     *  Sum: '<S130>/Add1'
     */
    localtmp_0 = (localDivide_bfr - 223.0F) * 32.0F;
    if (localtmp_0 < 65536.0F) {
      if (localtmp_0 >= 0.0F) {
        localMerge1 = (UInt16)localtmp_0;
      } else {
        localMerge1 = 0U;
      }
    } else {
      localMerge1 = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S131>/OutDTConv' incorporates:
     *  Constant: '<S131>/offset'
     *  Constant: '<S131>/one_on_slope'
     *  Product: '<S131>/Product4'
     *  Product: '<S135>/Divide'
     *  Sum: '<S131>/Add1'
     */
    localtmp_0 = (ExM_facLamCor * ExM_facTCoCor) * 16384.0F;
    if (localtmp_0 < 65536.0F) {
      if (localtmp_0 >= 0.0F) {
        localMerge10 = (UInt16)localtmp_0;
      } else {
        localMerge10 = 0U;
      }
    } else {
      localMerge10 = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S132>/OutDTConv' incorporates:
     *  Constant: '<S132>/offset'
     *  Constant: '<S132>/one_on_slope'
     *  Product: '<S132>/Product4'
     *  Product: '<S137>/Divide'
     *  Product: '<S138>/Divide'
     *  Sum: '<S132>/Add1'
     */
    localtmp_0 = ((ExM_facTCoCor * ExM_facIgCor) * ExM_facLamCor) * 8192.0F;
    if (localtmp_0 < 65536.0F) {
      if (localtmp_0 >= 0.0F) {
        localMerge2 = (UInt16)localtmp_0;
      } else {
        localMerge2 = 0U;
      }
    } else {
      localMerge2 = MAX_uint16_T;
    }

    /* Product: '<S133>/Divide' */
    ExM_tExStat = localSubtract1 * ExM_facLamCor;

    /* Update for UnitDelay: '<S141>/UnitDelay' */
    ExMGslT1_DWork.UnitDelay_l = localSubtract3_p;

    /* Update for UnitDelay: '<S141>/UnitDelay1' incorporates:
     *  Constant: '<S141>/Constant3'
     */
    ExMGslT1_DWork.UnitDelay_o = TRUE;

    /* Update for UnitDelay: '<S140>/UnitDelay' incorporates:
     *  Constant: '<S140>/Constant3'
     */
    ExMGslT1_DWork.UnitDelay_DSTATE_o = TRUE;
  }

  /* end of Outputs for SubSystem: '<S7>/F08_Calcul' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_facCorIgProtComp_INPUTOutport2' incorporates:
   *  Inport: '<Root>/ExM_facCorIgProtComp_INPUT'
   */
  Rte_Read_R_ExM_facCorIgProtComp_ExM_facCorIgProtComp
    (&localTmpSignalConversionAtExM_n);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExStatAfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExStatAfs_INPUT'
   */
  Rte_Read_R_ExM_tExStatAfs_ExM_tExStatAfs(&localTmpSignalConversionAtE_b3t);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_facCorProtComp_INPUTOutport2' incorporates:
   *  Inport: '<Root>/ExM_facCorProtComp_INPUT'
   */
  Rte_Read_R_ExM_facCorProtComp_ExM_facCorProtComp
    (&localTmpSignalConversionAtEx_it);

  /* Outputs for enable SubSystem: '<S7>/F08_Calcul_default' incorporates:
   *  EnablePort: '<S27>/Enable'
   *  Logic: '<S7>/Logical Operator'
   */
  if (!localTmpSignalConversionAtIgS_i) {
    /* SignalConversion: '<S27>/Signal Conversion' */
    localMerge10 = localTmpSignalConversionAtExM_n;

    /* SignalConversion: '<S27>/Signal Conversion1' */
    localMerge1 = localTmpSignalConversionAtE_b3t;

    /* SignalConversion: '<S27>/Signal Conversion2' */
    localMerge2 = localTmpSignalConversionAtEx_it;
  }

  /* end of Outputs for SubSystem: '<S7>/F08_Calcul_default' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&localTmpSignalConversionAtInThM);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_prm_mfAirCorCylOutport2' incorporates:
   *  Inport: '<Root>/EngM_prm_mfAirCorCyl'
   */
  Rte_Read_R_EngM_prm_mfAirCorCyl_EngM_prm_mfAirCorCyl
    (&localTmpSignalConversionAtEng_l);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_prm_mfAirScvCorCylOutport2' incorporates:
   *  Inport: '<Root>/EngM_prm_mfAirScvCorCyl'
   */
  Rte_Read_R_EngM_prm_mfAirScvCorCyl_EngM_prm_mfAirScvCorCyl
    (&localTmpSignalConversionAtEng_h);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEng_noInCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInCyl'
   */
  Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&localTmpSignalConversionAtEn_np);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&localTmpSignalConversionAtEn_hp);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_rItBurnRateCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rItBurnRateCor'
   */
  Rte_Read_R_EngM_rItBurnRateCor_EngM_rItBurnRateCor
    (&localTmpSignalConversionAtEng_g);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_cppExFlexOutport2' incorporates:
   *  Inport: '<Root>/ExM_cppExFlex'
   */
  Rte_Read_R_ExM_cppExFlex_ExM_cppExFlex(&localTmpSignalConversionAtExM_i);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_cppIngFlexOutport2' incorporates:
   *  Inport: '<Root>/ExM_cppIngFlex'
   */
  Rte_Read_R_ExM_cppIngFlex_ExM_cppIngFlex(&localTmpSignalConversionAtEx_fa);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_molMassExFlexOutport2' incorporates:
   *  Inport: '<Root>/ExM_molMassExFlex'
   */
  Rte_Read_R_ExM_molMassExFlex_ExM_molMassExFlex
    (&localTmpSignalConversionAtEx_ox);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_molMassInWoutRgFlexOutport2' incorporates:
   *  Inport: '<Root>/ExM_molMassInWoutRgFlex'
   */
  Rte_Read_R_ExM_molMassInWoutRgFlex_ExM_molMassInWoutRgFlex
    (&localTmpSignalConversionAtEx_b5);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_cppIngGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_cppIngGas'
   */
  Rte_Read_R_ExM_cppIngGas_ExM_cppIngGas(&localTmpSignalConversionAtExM_d);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_cppExGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_cppExGas'
   */
  Rte_Read_R_ExM_cppExGas_ExM_cppExGas(&localTmpSignalConversionAtEx_nq);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInjSys_bTotCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bTotCutOff'
   */
  Rte_Read_R_InjSys_bTotCutOff_InjSys_bTotCutOff
    (&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_molMassExGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_molMassExGas'
   */
  Rte_Read_R_ExM_molMassExGas_ExM_molMassExGas(&localTmpSignalConversionAtExM_c);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_molMassInWoutRgGasOutport2' incorporates:
   *  Inport: '<Root>/ExM_molMassInWoutRgGas'
   */
  Rte_Read_R_ExM_molMassInWoutRgGas_ExM_molMassInWoutRgGas
    (&localTmpSignalConversionAtEx_mt);

  /* Outputs for atomic SubSystem: '<S7>/F09_Scavenging' */

  /* Outputs for atomic SubSystem: '<S28>/F01_Zero_protection' */

  /* Outputs for atomic SubSystem: '<S147>/F01_Renommage_de_la_temperature_d_air' */

  /* DataTypeConversion: '<S151>/Data Type Conversion' */
  ExM_tAirRef = (((Float32)localTmpSignalConversionAtInThM) * 0.0078125F) +
    223.0F;

  /* end of Outputs for SubSystem: '<S147>/F01_Renommage_de_la_temperature_d_air' */

  /* Outputs for atomic SubSystem: '<S147>/F03_Choix_de_temperature_Statique' */

  /* Switch: '<S153>/Switch4' incorporates:
   *  Constant: '<S153>/Cste_273'
   *  Sum: '<S153>/Subtract4'
   */
  if (localTmpSignalConversionAtIgS_i) {
    ExM_tExStatCor = ExM_tExStat;
  } else {
    ExM_tExStatCor = ExM_tCoMesSwt + 273.0F;
  }

  /* end of Outputs for SubSystem: '<S147>/F03_Choix_de_temperature_Statique' */

  /* Outputs for atomic SubSystem: '<S147>/F02_Phaser_Debits' */

  /* MultiPortSwitch: '<S152>/Multiport Switch5' */
  switch (localTmpSignalConversionAtEn_np) {
   case 1:
    localTmpSignalConversionAtFARSp = localTmpSignalConversionAtEng_h[0];
    break;

   case 2:
    localTmpSignalConversionAtFARSp = localTmpSignalConversionAtEng_h[1];
    break;

   case 3:
    localTmpSignalConversionAtFARSp = localTmpSignalConversionAtEng_h[2];
    break;

   case 4:
    localTmpSignalConversionAtFARSp = localTmpSignalConversionAtEng_h[3];
    break;

   case 5:
    localTmpSignalConversionAtFARSp = localTmpSignalConversionAtEng_h[4];
    break;

   default:
    localTmpSignalConversionAtFARSp = localTmpSignalConversionAtEng_h[5];
    break;
  }

  /* DataTypeConversion: '<S152>/Data Type Conversion' */
  ExM_mfAirScvCorPh = ((Float32)localTmpSignalConversionAtFARSp) *
    1.525878906E-005F;

  /* MinMax: '<S152>/MinMax' incorporates:
   *  Constant: '<S152>/ExM_mfAirIni_C'
   */
  for (locali = 0; locali < 6; locali++) {
    localrtmax[locali] = localTmpSignalConversionAtEng_l[locali];
    if (ExM_mfAirIni_C > localTmpSignalConversionAtEng_l[locali]) {
      localrtmax[locali] = ExM_mfAirIni_C;
    }
  }

  /* MultiPortSwitch: '<S152>/Multiport Switch1' */
  switch (localTmpSignalConversionAtEn_hp) {
   case 1:
    localTmpSignalConversionAtFARSp = localrtmax[0];
    break;

   case 2:
    localTmpSignalConversionAtFARSp = localrtmax[1];
    break;

   case 3:
    localTmpSignalConversionAtFARSp = localrtmax[2];
    break;

   case 4:
    localTmpSignalConversionAtFARSp = localrtmax[3];
    break;

   case 5:
    localTmpSignalConversionAtFARSp = localrtmax[4];
    break;

   default:
    localTmpSignalConversionAtFARSp = localrtmax[5];
    break;
  }

  /* DataTypeConversion: '<S152>/Data Type Conversion1' */
  ExM_mfAirCorPh = ((Float32)localTmpSignalConversionAtFARSp) *
    1.525878906E-005F;

  /* end of Outputs for SubSystem: '<S147>/F02_Phaser_Debits' */

  /* Outputs for atomic SubSystem: '<S147>/F04_Coefficient_Stoechiometrique' */

  /* Selector: '<S154>/Selector1' incorporates:
   *  Constant: '<S154>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[3];

  /* Switch: '<S160>/Switch2' incorporates:
   *  RelationalOperator: '<S160>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[3] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* DataTypeConversion: '<S156>/Data Type Conversion' incorporates:
   *  Constant: '<S154>/Constant1'
   *  Selector: '<S154>/Selector2'
   */
  localDataTypeConversion_id = (UInt16)(((Float32d)localDataTypeConversion_l[3])
    / 0.0001F);

  /* Lookup: '<S156>/Look-Up Table'
   * About '<S156>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-14  FSlope 1.6384
   * Output0 Data Type:  Fixed Point    U16  2^-12  FSlope 1.8125  Bias 1.0004425048828125E+000
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_oa), (&(ExM_rAfsCor_T[0])),
                 localDataTypeConversion_id, (&(ExM_facFlex_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S156>/Data Type Duplicate1'
   *
   * Regarding '<S156>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S154>/Data Type Conversion' incorporates:
   *  Lookup: '<S156>/Look-Up Table'
   */
  ExM_rAfsGslFlex_MP = (((Float32)localLookUpTable_oa) * 4.425048828E-004F) +
    1.000442505E+000F;

  /* DataTypeConversion: '<S154>/Data Type Conversion1' incorporates:
   *  Constant: '<S154>/ExM_rAfsGas_C'
   */
  localDivide_bfr = (((Float32)ExM_rAfsGas_C) * 4.425048828E-004F) +
    1.000442505E+000F;

  /* Switch: '<S154>/Switch1' incorporates:
   *  Constant: '<S154>/ExM_bAcvGas_C'
   *  Sum: '<S154>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_rAfsGslFlex_MP;
  }

  /* Sum: '<S155>/Sum2' incorporates:
   *  Product: '<S155>/Divide'
   *  Sum: '<S155>/Sum3'
   */
  ExM_rAfs = ((localDivide_bfr - ExM_rAfsGslFlex_MP) * localSubtract1) +
    ExM_rAfsGslFlex_MP;

  /* end of Outputs for SubSystem: '<S147>/F04_Coefficient_Stoechiometrique' */

  /* end of Outputs for SubSystem: '<S28>/F01_Zero_protection' */

  /* Outputs for atomic SubSystem: '<S28>/F02_Elements_Cp' */

  /* Outputs for atomic SubSystem: '<S148>/F01_Lamda' */

  /* RelationalOperator: '<S161>/Relational Operator' incorporates:
   *  Constant: '<S161>/Cste_1'
   */
  localRelationalOperator1_no = (ExM_lam < 1.0F);

  /* Product: '<S174>/Divide' incorporates:
   *  Product: '<S178>/Divide'
   */
  localSubtract1 = ExM_mfAirCorPh / (ExM_lam * ExM_rAfs);

  /* Outputs for atomic SubSystem: '<S174>/If Action Subsystem3' */

  /* Switch: '<S190>/Switch1' incorporates:
   *  Constant: '<S190>/Constant1'
   *  Constant: '<S190>/Constant2'
   *  Constant: '<S190>/Constant3'
   *  Logic: '<S190>/Logical Operator1'
   *  RelationalOperator: '<S190>/Relational Operator'
   *  RelationalOperator: '<S190>/Relational Operator1'
   *  RelationalOperator: '<S190>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    ExM_mfFuCyl_MP = 0.0F;
  } else {
    ExM_mfFuCyl_MP = localSubtract1;
  }

  /* end of Outputs for SubSystem: '<S174>/If Action Subsystem3' */

  /* Switch: '<S161>/Switch9' incorporates:
   *  Constant: '<S161>/Cste_0'
   */
  if (localTmpSignalConversionAtInjSy) {
    ExM_mfFuCyl = 0.0F;
  } else {
    ExM_mfFuCyl = ExM_mfFuCyl_MP;
  }

  /* Product: '<S173>/Divide' */
  localSubtract1 = ExM_mfAirCorPh / ExM_rAfs;

  /* Outputs for atomic SubSystem: '<S173>/If Action Subsystem3' */

  /* Switch: '<S188>/Switch1' incorporates:
   *  Constant: '<S188>/Constant1'
   *  Constant: '<S188>/Constant2'
   *  Constant: '<S188>/Constant3'
   *  Logic: '<S188>/Logical Operator1'
   *  RelationalOperator: '<S188>/Relational Operator'
   *  RelationalOperator: '<S188>/Relational Operator1'
   *  RelationalOperator: '<S188>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    ExM_mfFuStoich_MP = 0.0F;
  } else {
    ExM_mfFuStoich_MP = localSubtract1;
  }

  /* end of Outputs for SubSystem: '<S173>/If Action Subsystem3' */

  /* Sum: '<S161>/Subtract6' */
  localDivide_bfr = ExM_mfFuCyl - ExM_mfFuStoich_MP;

  /* Switch: '<S161>/Switch6' incorporates:
   *  Constant: '<S161>/Cste_0__2'
   *  Constant: '<S161>/Cste_0__3'
   *  RelationalOperator: '<S161>/Relational Operator2'
   */
  if (localDivide_bfr < 0.0F) {
    ExM_mfFuCylLe_MP = 0.0F;
  } else {
    ExM_mfFuCylLe_MP = localDivide_bfr;
  }

  /* Product: '<S172>/Divide' incorporates:
   *  Product: '<S176>/Divide'
   */
  localSubtract1 = ExM_mfAirScvCorPh / (ExM_lam * ExM_rAfs);

  /* Outputs for atomic SubSystem: '<S172>/If Action Subsystem3' */

  /* Switch: '<S186>/Switch1' incorporates:
   *  Constant: '<S186>/Constant1'
   *  Constant: '<S186>/Constant2'
   *  Constant: '<S186>/Constant3'
   *  Logic: '<S186>/Logical Operator1'
   *  RelationalOperator: '<S186>/Relational Operator'
   *  RelationalOperator: '<S186>/Relational Operator1'
   *  RelationalOperator: '<S186>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    ExM_mfFuScv_MP = 0.0F;
  } else {
    ExM_mfFuScv_MP = localSubtract1;
  }

  /* end of Outputs for SubSystem: '<S172>/If Action Subsystem3' */

  /* Switch: '<S161>/Switch2' incorporates:
   *  Constant: '<S161>/Cste_0__4'
   *  Constant: '<S161>/Eng_bSelDI_SC'
   */
  if (Eng_bSelDI_SC) {
    localDivide_bfr = 0.0F;
  } else {
    localDivide_bfr = ExM_mfFuScv_MP;
  }

  /* Switch: '<S161>/Switch10' incorporates:
   *  Constant: '<S161>/Cste_0__1'
   */
  if (localTmpSignalConversionAtInjSy) {
    ExM_mfFuScv = 0.0F;
  } else {
    ExM_mfFuScv = localDivide_bfr;
  }

  /* Switch: '<S161>/Switch1' incorporates:
   *  Sum: '<S161>/Subtract5'
   */
  if (localRelationalOperator1_no) {
    localDivide_bfr = ExM_mfFuCylLe_MP + ExM_mfFuScv;
  } else {
    localDivide_bfr = ExM_mfFuScv;
  }

  /* RelationalOperator: '<S161>/Relational Operator1' incorporates:
   *  Constant: '<S161>/Cste_0__5'
   */
  localRelationalOperator2_k = (localDivide_bfr == 0.0F);

  /* Sum: '<S161>/Subtract2' */
  ExM_mfFuTot_MP = ExM_mfFuScv + ExM_mfFuCyl;

  /* RelationalOperator: '<S161>/Relational Operator3' incorporates:
   *  Constant: '<S161>/Cste_0__6'
   */
  localRelationalOperator3_jv = (ExM_mfFuTot_MP == 0.0F);

  /* Sum: '<S161>/Subtract1' */
  ExM_mfAirTot_MP = ExM_mfAirCorPh + ExM_mfAirScvCorPh;

  /* Switch: '<S161>/Switch8' incorporates:
   *  Constant: '<S161>/Cste_1__2'
   */
  if (localRelationalOperator3_jv) {
    localDataTypeConversion2_n = 1.0F;
  } else {
    localDataTypeConversion2_n = ExM_mfFuTot_MP;
  }

  /* Product: '<S170>/Divide' */
  localSubtract1 = ExM_mfAirTot_MP / localDataTypeConversion2_n;

  /* Outputs for atomic SubSystem: '<S170>/If Action Subsystem3' */

  /* Switch: '<S182>/Switch1' incorporates:
   *  Constant: '<S182>/Constant1'
   *  Constant: '<S182>/Constant2'
   *  Constant: '<S182>/Constant3'
   *  Logic: '<S182>/Logical Operator1'
   *  RelationalOperator: '<S182>/Relational Operator'
   *  RelationalOperator: '<S182>/Relational Operator1'
   *  RelationalOperator: '<S182>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    localSubtract1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S170>/If Action Subsystem3' */

  /* Product: '<S169>/Divide' */
  localDataTypeConversion2_n = localSubtract1 / ExM_rAfs;

  /* Outputs for atomic SubSystem: '<S169>/If Action Subsystem3' */

  /* Switch: '<S180>/Switch1' incorporates:
   *  Constant: '<S180>/Constant1'
   *  Constant: '<S180>/Constant2'
   *  Constant: '<S180>/Constant3'
   *  Logic: '<S180>/Logical Operator1'
   *  RelationalOperator: '<S180>/Relational Operator'
   *  RelationalOperator: '<S180>/Relational Operator1'
   *  RelationalOperator: '<S180>/Relational Operator3'
   */
  if (((localDataTypeConversion2_n != localDataTypeConversion2_n) ||
       (localDataTypeConversion2_n > 3.000000005E+038F)) || (-3.000000005E+038F >
       localDataTypeConversion2_n)) {
    localDataTypeConversion2_n = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S169>/If Action Subsystem3' */

  /* Switch: '<S161>/Switch7' incorporates:
   *  Constant: '<S161>/Cste_2__1'
   */
  if (localRelationalOperator3_jv) {
    localDataTypeConversion2_n = 10.0F;
  }

  /* Product: '<S168>/Product4' incorporates:
   *  Constant: '<S168>/offset'
   *  Constant: '<S168>/one_on_slope'
   *  Sum: '<S168>/Add1'
   */
  localDataTypeConversion2_n *= 8192.0F;

  /* Sum: '<S161>/Subtract7' incorporates:
   *  Product: '<S177>/Divide'
   */
  ExM_mfAirCylLe_MP = ExM_mfAirCorPh - (ExM_mfFuCyl * ExM_rAfs);

  /* Switch: '<S161>/Switch3' incorporates:
   *  Sum: '<S161>/Subtract8'
   */
  if (localRelationalOperator1_no) {
    ExM_mfAirEx_MP = ExM_mfAirScvCorPh;
  } else {
    ExM_mfAirEx_MP = ExM_mfAirScvCorPh + ExM_mfAirCylLe_MP;
  }

  /* Switch: '<S161>/Switch4' incorporates:
   *  Constant: '<S161>/Cste_1__1'
   */
  if (localRelationalOperator2_k) {
    ExM_mfFuEx_MP = 1.0F;
  } else {
    ExM_mfFuEx_MP = localDivide_bfr;
  }

  /* Product: '<S171>/Divide' */
  localSubtract1 = ExM_mfAirEx_MP / ExM_mfFuEx_MP;

  /* Outputs for atomic SubSystem: '<S171>/If Action Subsystem3' */

  /* Switch: '<S184>/Switch1' incorporates:
   *  Constant: '<S184>/Constant1'
   *  Constant: '<S184>/Constant2'
   *  Constant: '<S184>/Constant3'
   *  Logic: '<S184>/Logical Operator1'
   *  RelationalOperator: '<S184>/Relational Operator'
   *  RelationalOperator: '<S184>/Relational Operator1'
   *  RelationalOperator: '<S184>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    localSubtract1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S171>/If Action Subsystem3' */

  /* Product: '<S175>/Divide' */
  localSubtract1 /= ExM_rAfs;

  /* Outputs for atomic SubSystem: '<S175>/If Action Subsystem3' */

  /* Switch: '<S192>/Switch1' incorporates:
   *  Constant: '<S192>/Constant1'
   *  Constant: '<S192>/Constant2'
   *  Constant: '<S192>/Constant3'
   *  Logic: '<S192>/Logical Operator1'
   *  RelationalOperator: '<S192>/Relational Operator'
   *  RelationalOperator: '<S192>/Relational Operator1'
   *  RelationalOperator: '<S192>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    ExM_lamEx_MP = 0.0F;
  } else {
    ExM_lamEx_MP = localSubtract1;
  }

  /* end of Outputs for SubSystem: '<S175>/If Action Subsystem3' */

  /* Sum: '<S161>/Subtract3' */
  ExM_mfScvMixt = ExM_mfFuEx_MP + ExM_mfAirEx_MP;

  /* Switch: '<S161>/Switch5' incorporates:
   *  Constant: '<S161>/Cste_2'
   */
  if (localRelationalOperator2_k) {
    ExM_lamEx = 50.0F;
  } else {
    ExM_lamEx = ExM_lamEx_MP;
  }

  /* end of Outputs for SubSystem: '<S148>/F01_Lamda' */

  /* Outputs for atomic SubSystem: '<S148>/F02_Tables' */

  /* DataTypeConversion: '<S162>/Data Type Conversion4' */
  localtmp = ((Float32d)ExM_lam) / 0.001F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion4_p = (UInt16)localtmp;
    } else {
      localDataTypeConversion4_p = 0U;
    }
  } else {
    localDataTypeConversion4_p = MAX_uint16_T;
  }

  /* Lookup: '<S193>/Look-Up Table'
   * About '<S193>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
   * Output0 Data Type:  Fixed Point    U16  2^-7  FSlope 1.28
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_j), (&(ExM_molMassEx_T[0])),
                 localDataTypeConversion4_p, (&(ExM_lamClc_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S193>/Data Type Duplicate1'
   *
   * Regarding '<S193>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Lookup: '<S194>/Look-Up Table'
   * About '<S194>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
   * Output0 Data Type:  Fixed Point    U16  2^-7  FSlope 1.28
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_lf), (&(ExM_molMassInMixt_T[0])),
                 localDataTypeConversion4_p, (&(ExM_lamClc_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S194>/Data Type Duplicate1'
   *
   * Regarding '<S194>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S195>/Data Type Conversion' */
  localtmp = ACTEMS_LdexpF(((Float32d)ExM_tAirRef) - 223.0F, 7);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion_fj = (UInt16)localtmp;
    } else {
      localDataTypeConversion_fj = 0U;
    }
  } else {
    localDataTypeConversion_fj = MAX_uint16_T;
  }

  /* Switch: '<S162>/Switch2' incorporates:
   *  Constant: '<S162>/Cste_2'
   *  Constant: '<S162>/Eng_bSelDI_SC'
   */
  if (Eng_bSelDI_SC) {
    localSwitch2_he = 10000U;
  } else {
    localSwitch2_he = localDataTypeConversion4_p;
  }

  /* Lookup2D: '<S195>/Look-Up Table (2-D)'
   * About '<S195>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
   * Input1  Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
   * Output0 Data Type:  Fixed Point    U16  2^-1
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_o), (&(ExM_cppIng_M[0])),
                     localDataTypeConversion_fj, (&(ExM_tAirRefX_A[0])), 14U,
                     localSwitch2_he, (&(ExM_lamClcY_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S195>/Data Type Duplicate2'
   *
   * Regarding '<S195>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S196>/Data Type Conversion' */
  localtmp = ACTEMS_LdexpF(((Float32d)ExM_tExStatCor) - 223.0F, 5);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion_mr = (UInt16)localtmp;
    } else {
      localDataTypeConversion_mr = 0U;
    }
  } else {
    localDataTypeConversion_mr = MAX_uint16_T;
  }

  /* Lookup2D: '<S196>/Look-Up Table (2-D)'
   * About '<S196>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-5  Bias 223.0
   * Input1  Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
   * Output0 Data Type:  Fixed Point    U16  2^-1
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_e5), (&(ExM_cppEx_M[0])),
                     localDataTypeConversion_mr, (&(ExM_tExStatX_A[0])), 14U,
                     localDataTypeConversion4_p, (&(ExM_lamClcY_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S196>/Data Type Duplicate2'
   *
   * Regarding '<S196>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S162>/Data Type Conversion' incorporates:
   *  Lookup2D: '<S195>/Look-Up Table (2-D)'
   */
  ExM_cppIng = ((Float32)localLookUpTable2D_o) * 0.5F;

  /* DataTypeConversion: '<S162>/Data Type Conversion1' incorporates:
   *  Lookup: '<S194>/Look-Up Table'
   */
  ExM_molMassInWoutRg = ((Float32)localLookUpTable_lf) * 9.999999776E-003F;

  /* DataTypeConversion: '<S162>/Data Type Conversion2' incorporates:
   *  Lookup: '<S193>/Look-Up Table'
   */
  ExM_molMassEx = ((Float32)localLookUpTable_j) * 9.999999776E-003F;

  /* DataTypeConversion: '<S162>/Data Type Conversion3' incorporates:
   *  Lookup2D: '<S196>/Look-Up Table (2-D)'
   */
  ExM_cppEx = ((Float32)localLookUpTable2D_e5) * 0.5F;

  /* end of Outputs for SubSystem: '<S148>/F02_Tables' */

  /* Outputs for atomic SubSystem: '<S148>/F03_Plug_In_CpEx' */

  /* Selector: '<S163>/Selector2' incorporates:
   *  Constant: '<S163>/Constant1'
   */
  localSubtract1 = localDataTypeConversion_l[4];

  /* Switch: '<S202>/Switch2' incorporates:
   *  Constant: '<S197>/Constant'
   *  RelationalOperator: '<S202>/LowerRelop1'
   */
  if (localDataTypeConversion_l[4] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Sum: '<S197>/Sum2' incorporates:
   *  DataTypeConversion: '<S163>/Data Type Conversion2'
   *  Product: '<S197>/Divide'
   *  Sum: '<S197>/Sum3'
   */
  ExM_cppExGslFlex_MP = (((((Float32)localTmpSignalConversionAtExM_i) * 0.5F) -
    ExM_cppEx) * localSubtract1) + ExM_cppEx;

  /* Selector: '<S163>/Selector1' incorporates:
   *  Constant: '<S163>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[4];

  /* Switch: '<S206>/Switch2' incorporates:
   *  Constant: '<S198>/Constant'
   *  RelationalOperator: '<S206>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[4] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* DataTypeConversion: '<S163>/Data Type Conversion1' */
  localDivide_bfr = ((Float32)localTmpSignalConversionAtEx_nq) * 0.5F;

  /* Switch: '<S163>/Switch1' incorporates:
   *  Constant: '<S163>/ExM_bAcvGas_C'
   *  Sum: '<S163>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_cppExGslFlex_MP;
  }

  /* Sum: '<S198>/Sum2' incorporates:
   *  Product: '<S198>/Divide'
   *  Sum: '<S198>/Sum3'
   */
  ExM_cppExCor = ((localDivide_bfr - ExM_cppExGslFlex_MP) * localSubtract1) +
    ExM_cppExGslFlex_MP;

  /* end of Outputs for SubSystem: '<S148>/F03_Plug_In_CpEx' */

  /* Outputs for atomic SubSystem: '<S148>/F04_Plug_In_CpIn' */

  /* Selector: '<S164>/Selector2' incorporates:
   *  Constant: '<S164>/Constant1'
   */
  localSubtract1 = localDataTypeConversion_l[4];

  /* Switch: '<S212>/Switch2' incorporates:
   *  Constant: '<S207>/Constant'
   *  RelationalOperator: '<S212>/LowerRelop1'
   */
  if (localDataTypeConversion_l[4] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Sum: '<S207>/Sum2' incorporates:
   *  DataTypeConversion: '<S164>/Data Type Conversion2'
   *  Product: '<S207>/Divide'
   *  Sum: '<S207>/Sum3'
   */
  ExM_cppIngGslFlex_MP = (((((Float32)localTmpSignalConversionAtEx_fa) * 0.5F)
    - ExM_cppIng) * localSubtract1) + ExM_cppIng;

  /* Selector: '<S164>/Selector1' incorporates:
   *  Constant: '<S164>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[4];

  /* Switch: '<S216>/Switch2' incorporates:
   *  Constant: '<S208>/Constant'
   *  RelationalOperator: '<S216>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[4] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* DataTypeConversion: '<S164>/Data Type Conversion1' */
  localDivide_bfr = ((Float32)localTmpSignalConversionAtExM_d) * 0.5F;

  /* Switch: '<S164>/Switch1' incorporates:
   *  Constant: '<S164>/ExM_bAcvGas_C'
   *  Sum: '<S164>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_cppIngGslFlex_MP;
  }

  /* Sum: '<S208>/Sum2' incorporates:
   *  Product: '<S208>/Divide'
   *  Sum: '<S208>/Sum3'
   */
  ExM_cppIngCor = ((localDivide_bfr - ExM_cppIngGslFlex_MP) * localSubtract1) +
    ExM_cppIngGslFlex_MP;

  /* end of Outputs for SubSystem: '<S148>/F04_Plug_In_CpIn' */

  /* Outputs for atomic SubSystem: '<S148>/F05_Plug_In_MolMassEx' */

  /* Selector: '<S165>/Selector1' incorporates:
   *  Constant: '<S165>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[4];

  /* Switch: '<S222>/Switch2' incorporates:
   *  Constant: '<S217>/Constant'
   *  RelationalOperator: '<S222>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[4] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Selector: '<S165>/Selector2' incorporates:
   *  Constant: '<S165>/Constant1'
   */
  localDivide_bfr = localDataTypeConversion_l[4];

  /* Switch: '<S226>/Switch2' incorporates:
   *  Constant: '<S218>/Constant'
   *  RelationalOperator: '<S226>/LowerRelop1'
   */
  if (localDataTypeConversion_l[4] > 1.0F) {
    localDivide_bfr = 1.0F;
  }

  /* Sum: '<S218>/Sum2' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion4'
   *  Product: '<S218>/Divide'
   *  Sum: '<S218>/Sum3'
   */
  ExM_molMassExGslFlex_MP = (((((Float32)localTmpSignalConversionAtEx_ox) *
    0.0078125F) - ExM_molMassEx) * localDivide_bfr) + ExM_molMassEx;

  /* DataTypeConversion: '<S165>/Data Type Conversion1' */
  localDivide_bfr = ((Float32)localTmpSignalConversionAtExM_c) * 0.0078125F;

  /* Switch: '<S165>/Switch1' incorporates:
   *  Constant: '<S165>/ExM_bAcvGas_C'
   *  Sum: '<S165>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_molMassExGslFlex_MP;
  }

  /* Sum: '<S217>/Sum2' incorporates:
   *  Product: '<S217>/Divide'
   *  Sum: '<S217>/Sum3'
   */
  ExM_molMassExCor = ((localDivide_bfr - ExM_molMassExGslFlex_MP) *
                      localSubtract1) + ExM_molMassExGslFlex_MP;

  /* end of Outputs for SubSystem: '<S148>/F05_Plug_In_MolMassEx' */

  /* Outputs for atomic SubSystem: '<S148>/F06_Plug_In_molMassInWoutRg' */

  /* Selector: '<S166>/Selector1' incorporates:
   *  Constant: '<S166>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[4];

  /* Switch: '<S232>/Switch2' incorporates:
   *  Constant: '<S227>/Constant'
   *  RelationalOperator: '<S232>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[4] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Selector: '<S166>/Selector2' incorporates:
   *  Constant: '<S166>/Constant1'
   */
  localDivide_bfr = localDataTypeConversion_l[4];

  /* Switch: '<S236>/Switch2' incorporates:
   *  Constant: '<S228>/Constant'
   *  RelationalOperator: '<S236>/LowerRelop1'
   */
  if (localDataTypeConversion_l[4] > 1.0F) {
    localDivide_bfr = 1.0F;
  }

  /* Sum: '<S228>/Sum2' incorporates:
   *  DataTypeConversion: '<S166>/Data Type Conversion2'
   *  Product: '<S228>/Divide'
   *  Sum: '<S228>/Sum3'
   */
  ExM_molMassWoutRgGslFlex_MP = (((((Float32)localTmpSignalConversionAtEx_b5) *
    0.0078125F) - ExM_molMassInWoutRg) * localDivide_bfr) + ExM_molMassInWoutRg;

  /* DataTypeConversion: '<S166>/Data Type Conversion1' */
  localDivide_bfr = ((Float32)localTmpSignalConversionAtEx_mt) * 0.0078125F;

  /* Switch: '<S166>/Switch1' incorporates:
   *  Constant: '<S166>/ExM_bAcvGas_C'
   *  Sum: '<S166>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_molMassWoutRgGslFlex_MP;
  }

  /* Sum: '<S227>/Sum2' incorporates:
   *  Product: '<S227>/Divide'
   *  Sum: '<S227>/Sum3'
   */
  ExM_molMassInWoutRgCor = ((localDivide_bfr - ExM_molMassWoutRgGslFlex_MP) *
    localSubtract1) + ExM_molMassWoutRgGslFlex_MP;

  /* end of Outputs for SubSystem: '<S148>/F06_Plug_In_molMassInWoutRg' */

  /* Outputs for atomic SubSystem: '<S148>/F07_Tables_Calcul' */

  /* MinMax: '<S167>/MinMax' incorporates:
   *  Constant: '<S167>/Cste_0_7'
   */
  localSubtract1 = ((Float32)localTmpSignalConversionAtEng_g) *
    6.103515625E-005F;
  localSubtract1 = rt_MINf(localSubtract1, 6.999999881E-001F);

  /* Product: '<S247>/Divide' incorporates:
   *  Constant: '<S167>/Cste_1'
   *  Product: '<S245>/Divide'
   *  Sum: '<S167>/Subtract1'
   */
  ExM_mfAirRg_MP = (localSubtract1 / (1.0F - localSubtract1)) * ExM_mfAirCorPh;

  /* Product: '<S241>/Divide' incorporates:
   *  Product: '<S246>/Divide'
   *  Product: '<S248>/Divide'
   *  Sum: '<S167>/Subtract5'
   *  Sum: '<S167>/Subtract6'
   */
  localSubtract1 = ((ExM_cppExCor * ExM_mfAirRg_MP) + (ExM_cppIngCor *
    ExM_mfAirCorPh)) / (ExM_mfAirCorPh + ExM_mfAirRg_MP);

  /* Outputs for atomic SubSystem: '<S241>/If Action Subsystem3' */

  /* Switch: '<S255>/Switch1' incorporates:
   *  Constant: '<S255>/Constant1'
   *  Constant: '<S255>/Constant2'
   *  Constant: '<S255>/Constant3'
   *  Logic: '<S255>/Logical Operator1'
   *  RelationalOperator: '<S255>/Relational Operator'
   *  RelationalOperator: '<S255>/Relational Operator1'
   *  RelationalOperator: '<S255>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    ExM_cppIngWithRg_MP = 0.0F;
  } else {
    ExM_cppIngWithRg_MP = localSubtract1;
  }

  /* end of Outputs for SubSystem: '<S241>/If Action Subsystem3' */

  /* Sum: '<S167>/Subtract3' */
  ExM_mfTot_MP = ExM_mfAirRg_MP + ExM_mfAirCorPh;

  /* Product: '<S242>/Divide' */
  localSubtract1 = ExM_mfAirCorPh / ExM_molMassInWoutRgCor;

  /* Outputs for atomic SubSystem: '<S242>/If Action Subsystem3' */

  /* Switch: '<S257>/Switch1' incorporates:
   *  Constant: '<S257>/Constant1'
   *  Constant: '<S257>/Constant2'
   *  Constant: '<S257>/Constant3'
   *  Logic: '<S257>/Logical Operator1'
   *  RelationalOperator: '<S257>/Relational Operator'
   *  RelationalOperator: '<S257>/Relational Operator1'
   *  RelationalOperator: '<S257>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    localSubtract1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S242>/If Action Subsystem3' */

  /* Product: '<S239>/Divide' */
  localDivide_bfr = ExM_mfAirRg_MP / ExM_molMassExCor;

  /* Outputs for atomic SubSystem: '<S239>/If Action Subsystem3' */

  /* Switch: '<S251>/Switch1' incorporates:
   *  Constant: '<S251>/Constant1'
   *  Constant: '<S251>/Constant2'
   *  Constant: '<S251>/Constant3'
   *  Logic: '<S251>/Logical Operator1'
   *  RelationalOperator: '<S251>/Relational Operator'
   *  RelationalOperator: '<S251>/Relational Operator1'
   *  RelationalOperator: '<S251>/Relational Operator3'
   */
  if (((localDivide_bfr != localDivide_bfr) || (localDivide_bfr >
        3.000000005E+038F)) || (-3.000000005E+038F > localDivide_bfr)) {
    localDivide_bfr = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S239>/If Action Subsystem3' */

  /* Sum: '<S167>/Subtract2' */
  ExM_molTot_MP = localSubtract1 + localDivide_bfr;

  /* Product: '<S240>/Divide' */
  localSubtract1 = ExM_mfTot_MP / ExM_molTot_MP;

  /* Outputs for atomic SubSystem: '<S240>/If Action Subsystem3' */

  /* Switch: '<S253>/Switch1' incorporates:
   *  Constant: '<S253>/Constant1'
   *  Constant: '<S253>/Constant2'
   *  Constant: '<S253>/Constant3'
   *  Logic: '<S253>/Logical Operator1'
   *  RelationalOperator: '<S253>/Relational Operator'
   *  RelationalOperator: '<S253>/Relational Operator1'
   *  RelationalOperator: '<S253>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    localSubtract1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S240>/If Action Subsystem3' */

  /* Product: '<S244>/Divide' incorporates:
   *  Constant: '<S167>/Cste_1000_1'
   *  Product: '<S249>/Divide'
   */
  ExM_cppIngMol_MP = (ExM_cppIngWithRg_MP * localSubtract1) / 1000.0F;

  /* Sum: '<S167>/Subtract7' incorporates:
   *  Constant: '<S167>/Cste_8_314'
   */
  ExM_cpvIngMol_MP = ExM_cppIngMol_MP - 8.314000130E+000F;

  /* Product: '<S243>/Divide' */
  localDataTypeConversion3_n = ExM_cppIngMol_MP / ExM_cpvIngMol_MP;

  /* Outputs for atomic SubSystem: '<S243>/If Action Subsystem3' */

  /* Switch: '<S259>/Switch1' incorporates:
   *  Constant: '<S259>/Constant1'
   *  Constant: '<S259>/Constant2'
   *  Constant: '<S259>/Constant3'
   *  Logic: '<S259>/Logical Operator1'
   *  RelationalOperator: '<S259>/Relational Operator'
   *  RelationalOperator: '<S259>/Relational Operator1'
   *  RelationalOperator: '<S259>/Relational Operator3'
   */
  if (((localDataTypeConversion3_n != localDataTypeConversion3_n) ||
       (localDataTypeConversion3_n > 3.000000005E+038F)) || (-3.000000005E+038F >
       localDataTypeConversion3_n)) {
    localDataTypeConversion3_n = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S243>/If Action Subsystem3' */

  /* Switch: '<S167>/Switch1' incorporates:
   *  Constant: '<S167>/ExM_bSelGmaInMixt_C'
   *  Constant: '<S167>/ExM_gmaSelGmaInMixt_C'
   *  DataTypeConversion: '<S167>/Data Type Conversion4'
   */
  if (ExM_bSelGmaInMixt_C) {
    localDataTypeConversion3_n = ((Float32)ExM_gmaSelGmaInMixt_C) *
      5.507812370E-003F;
  }

  /* DataTypeConversion: '<S237>/OutDTConv' incorporates:
   *  Constant: '<S237>/offset'
   *  Constant: '<S237>/one_on_slope'
   *  Product: '<S237>/Product4'
   *  Sum: '<S237>/Add1'
   */
  localtmp_0 = 1024.0F * localDataTypeConversion3_n;
  if (localtmp_0 < 65536.0F) {
    if (localtmp_0 >= 0.0F) {
      localTmpSignalConversionAtFARSp = (UInt16)localtmp_0;
    } else {
      localTmpSignalConversionAtFARSp = 0U;
    }
  } else {
    localTmpSignalConversionAtFARSp = MAX_uint16_T;
  }

  /* Switch: '<S167>/Switch3' incorporates:
   *  Constant: '<S167>/ExM_bSelMolMassInMixt_C'
   *  Constant: '<S167>/ExM_molSelMolMassInMixt_C'
   *  DataTypeConversion: '<S167>/Data Type Conversion2'
   */
  if (ExM_bSelMolMassInMixt_C) {
    localDataTypeConversion3_n = ((Float32)ExM_molSelMolMassInMixt_C) *
      9.999999776E-003F;
  } else {
    localDataTypeConversion3_n = localSubtract1;
  }

  /* Product: '<S238>/Product4' incorporates:
   *  Constant: '<S238>/offset'
   *  Constant: '<S238>/one_on_slope'
   *  Sum: '<S238>/Add1'
   */
  localDataTypeConversion3_n *= 128.0F;

  /* end of Outputs for SubSystem: '<S148>/F07_Tables_Calcul' */

  /* end of Outputs for SubSystem: '<S28>/F02_Elements_Cp' */

  /* Outputs for atomic SubSystem: '<S28>/F03_Mix' */

  /* Sum: '<S149>/Subtract10' */
  localSubtract1 = ExM_mfFuCyl + ExM_mfAirCorPh;

  /* Sum: '<S149>/Subtract3' */
  localDivide_bfr = ExM_mfAirScvCorPh + ExM_mfFuScv;

  /* Sum: '<S149>/Subtract1' */
  ExM_mfEgTotWithScv = localSubtract1 + localDivide_bfr;

  /* DataTypeConversion: '<S260>/OutDTConv' incorporates:
   *  Constant: '<S260>/offset'
   *  Constant: '<S260>/one_on_slope'
   *  Product: '<S260>/Product4'
   *  Sum: '<S260>/Add1'
   */
  localtmp_0 = 65536.0F * ExM_mfEgTotWithScv;
  if (localtmp_0 < 65536.0F) {
    if (localtmp_0 >= 0.0F) {
      localTmpSignalConversionAtEx_fu = (UInt16)localtmp_0;
    } else {
      localTmpSignalConversionAtEx_fu = 0U;
    }
  } else {
    localTmpSignalConversionAtEx_fu = MAX_uint16_T;
  }

  /* Product: '<S264>/Divide' */
  ExM_wEx_MP = localSubtract1 * ExM_cppExCor;

  /* Product: '<S263>/Divide' */
  ExM_wIng_MP = ExM_cppIngCor * localDivide_bfr;

  /* Sum: '<S149>/Subtract6' */
  localSubtract1 = ExM_wEx_MP + ExM_wIng_MP;

  /* Product: '<S261>/Divide' */
  localDivide_bfr = localSubtract1 / ExM_mfEgTotWithScv;

  /* Outputs for atomic SubSystem: '<S261>/If Action Subsystem3' */

  /* Switch: '<S268>/Switch1' incorporates:
   *  Constant: '<S268>/Constant1'
   *  Constant: '<S268>/Constant2'
   *  Constant: '<S268>/Constant3'
   *  Logic: '<S268>/Logical Operator1'
   *  RelationalOperator: '<S268>/Relational Operator'
   *  RelationalOperator: '<S268>/Relational Operator1'
   *  RelationalOperator: '<S268>/Relational Operator3'
   */
  if (((localDivide_bfr != localDivide_bfr) || (localDivide_bfr >
        3.000000005E+038F)) || (-3.000000005E+038F > localDivide_bfr)) {
    ExM_cppExMixt = 0.0F;
  } else {
    ExM_cppExMixt = localDivide_bfr;
  }

  /* end of Outputs for SubSystem: '<S261>/If Action Subsystem3' */

  /* Product: '<S265>/Divide' */
  ExM_wHeatEx_MP = ExM_tExStatCor * ExM_wEx_MP;

  /* Product: '<S266>/Divide' */
  ExM_wHeatIng_MP = ExM_wIng_MP * ExM_tAirRef;

  /* Product: '<S262>/Divide' incorporates:
   *  Sum: '<S149>/Subtract8'
   */
  localSubtract1 = (ExM_wHeatEx_MP + ExM_wHeatIng_MP) / localSubtract1;

  /* Outputs for atomic SubSystem: '<S262>/If Action Subsystem3' */

  /* Switch: '<S270>/Switch1' incorporates:
   *  Constant: '<S270>/Constant1'
   *  Constant: '<S270>/Constant2'
   *  Constant: '<S270>/Constant3'
   *  Logic: '<S270>/Logical Operator1'
   *  RelationalOperator: '<S270>/Relational Operator'
   *  RelationalOperator: '<S270>/Relational Operator1'
   *  RelationalOperator: '<S270>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    ExM_tExScv = 0.0F;
  } else {
    ExM_tExScv = localSubtract1;
  }

  /* end of Outputs for SubSystem: '<S262>/If Action Subsystem3' */

  /* Switch: '<S149>/Switch1' incorporates:
   *  Constant: '<S149>/Cste_2'
   */
  if (!localTmpSignalConversionAtIgS_i) {
    localTmpSignalConversionAtEx_fu = 0U;
  }

  /* Switch: '<S149>/Switch3' incorporates:
   *  Constant: '<S149>/ExM_bSelMassFlowEgTot_C'
   *  Constant: '<S149>/ExM_mfSelMassFlowEgTot_C'
   */
  if (ExM_bSelMassFlowEgTot_C) {
    localTmpSignalConversionAtEx_fu = ExM_mfSelMassFlowEgTot_C;
  }

  /* end of Outputs for SubSystem: '<S28>/F03_Mix' */

  /* Outputs for atomic SubSystem: '<S28>/F04_Post_Oxydation' */

  /* DataTypeConversion: '<S150>/Data Type Conversion' */
  for (locali = 0; locali < 5; locali++) {
    localTmpSignalConversionAtEx_pw[locali] = (UInt16)(((Float32d)
      localDataTypeConversion_l[locali]) / 0.0001F);
  }

  /* Outputs for atomic SubSystem: '<S150>/F01_PCI' */

  /* Selector: '<S271>/Selector1' incorporates:
   *  Constant: '<S271>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[3];

  /* Switch: '<S280>/Switch2' incorporates:
   *  Constant: '<S275>/Constant'
   *  RelationalOperator: '<S280>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[3] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Selector: '<S271>/Selector2' incorporates:
   *  Constant: '<S271>/Constant1'
   */
  localSelector2_p = localTmpSignalConversionAtEx_pw[3];

  /* Lookup: '<S276>/Look-Up Table'
   * About '<S276>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-14  FSlope 1.6384
   * Output0 Data Type:  Fixed Point    U16  2^11  FSlope 1.4901161193847656E+000  Bias 3.0517578125000000E+003
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_bh), (&(ExM_PCICor_T[0])), localSelector2_p,
                 (&(ExM_facFlex_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S276>/Data Type Duplicate1'
   *
   * Regarding '<S276>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S271>/Data Type Conversion' incorporates:
   *  Constant: '<S271>/Constant1'
   *  Lookup: '<S276>/Look-Up Table'
   *  Selector: '<S271>/Selector2'
   */
  ExM_PCICor_MP = (((Float32)localLookUpTable_bh) * 3.051757813E+003F) +
    3.051757813E+003F;

  /* DataTypeConversion: '<S271>/Data Type Conversion2' incorporates:
   *  Constant: '<S271>/ExM_PCIGas_C'
   */
  localDivide_bfr = (((Float32)ExM_PCIGas_C) * 3.051757813E+003F) -
    9.9996952E+007F;

  /* Switch: '<S271>/Switch1' incorporates:
   *  Constant: '<S271>/ExM_bAcvGas_C'
   *  Sum: '<S271>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_PCICor_MP;
  }

  /* Sum: '<S275>/Sum2' incorporates:
   *  Product: '<S275>/Divide'
   *  Sum: '<S275>/Sum3'
   */
  ExM_PCI = ((localDivide_bfr - ExM_PCICor_MP) * localSubtract1) + ExM_PCICor_MP;

  /* end of Outputs for SubSystem: '<S150>/F01_PCI' */

  /* Outputs for atomic SubSystem: '<S150>/F02_Lean_limit_Post_oxydation' */

  /* Selector: '<S272>/Selector1' incorporates:
   *  Constant: '<S272>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[3];

  /* Switch: '<S286>/Switch2' incorporates:
   *  Constant: '<S281>/Constant'
   *  RelationalOperator: '<S286>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[3] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Selector: '<S272>/Selector2' incorporates:
   *  Constant: '<S272>/Constant1'
   */
  localSelector2_m = localTmpSignalConversionAtEx_pw[3];

  /* Lookup: '<S282>/Look-Up Table'
   * About '<S282>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-14  FSlope 1.6384
   * Output0 Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_o), (&(ExM_lamLeanLimPostOxCor_T[0])),
                 localSelector2_m, (&(ExM_facFlex_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S282>/Data Type Duplicate1'
   *
   * Regarding '<S282>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S272>/Data Type Conversion' incorporates:
   *  Constant: '<S272>/Constant1'
   *  Lookup: '<S282>/Look-Up Table'
   *  Selector: '<S272>/Selector2'
   */
  ExM_lamLeanLimPostOxCor_MP = ((Float32)localLookUpTable_o) *
    1.000000047E-003F;

  /* DataTypeConversion: '<S272>/Data Type Conversion2' incorporates:
   *  Constant: '<S272>/ExM_lamLeanLimPostOxGas_C'
   */
  localDivide_bfr = ((Float32)ExM_lamLeanLimPostOxGas_C) * 1.000000047E-003F;

  /* Switch: '<S272>/Switch1' incorporates:
   *  Constant: '<S272>/ExM_bAcvGas_C'
   *  Sum: '<S272>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_lamLeanLimPostOxCor_MP;
  }

  /* Sum: '<S281>/Sum2' incorporates:
   *  Product: '<S281>/Divide'
   *  Sum: '<S281>/Sum3'
   */
  ExM_lamLeanLimPostOx = ((localDivide_bfr - ExM_lamLeanLimPostOxCor_MP) *
    localSubtract1) + ExM_lamLeanLimPostOxCor_MP;

  /* end of Outputs for SubSystem: '<S150>/F02_Lean_limit_Post_oxydation' */

  /* Outputs for atomic SubSystem: '<S150>/F03_Rich_limit_Post_oxydation' */

  /* Selector: '<S273>/Selector1' incorporates:
   *  Constant: '<S273>/Constant2'
   */
  localSubtract1 = localDataTypeConversion1_f[3];

  /* Switch: '<S292>/Switch2' incorporates:
   *  Constant: '<S287>/Constant'
   *  RelationalOperator: '<S292>/LowerRelop1'
   */
  if (localDataTypeConversion1_f[3] > 1.0F) {
    localSubtract1 = 1.0F;
  }

  /* Selector: '<S273>/Selector2' incorporates:
   *  Constant: '<S273>/Constant1'
   */
  localSelector2 = localTmpSignalConversionAtEx_pw[3];

  /* Lookup: '<S288>/Look-Up Table'
   * About '<S288>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-14  FSlope 1.6384
   * Output0 Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_gd), (&(ExM_lamRichLimPostOxCor_T[0])),
                 localSelector2, (&(ExM_facFlex_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S288>/Data Type Duplicate1'
   *
   * Regarding '<S288>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S273>/Data Type Conversion' incorporates:
   *  Constant: '<S273>/Constant1'
   *  Lookup: '<S288>/Look-Up Table'
   *  Selector: '<S273>/Selector2'
   */
  ExM_lamRichLimPostOxCor_MP = ((Float32)localLookUpTable_gd) *
    1.000000047E-003F;

  /* DataTypeConversion: '<S273>/Data Type Conversion2' incorporates:
   *  Constant: '<S273>/ExM_lamRichLimPostOxGas_C'
   */
  localDivide_bfr = ((Float32)ExM_lamRichLimPostOxGas_C) * 1.000000047E-003F;

  /* Switch: '<S273>/Switch1' incorporates:
   *  Constant: '<S273>/ExM_bAcvGas_C'
   *  Sum: '<S273>/Sum2'
   */
  if (!ExM_bAcvGas_C) {
    localDivide_bfr += ExM_lamRichLimPostOxCor_MP;
  }

  /* Sum: '<S287>/Sum2' incorporates:
   *  Product: '<S287>/Divide'
   *  Sum: '<S287>/Sum3'
   */
  ExM_lamRichLimPostOx = ((localDivide_bfr - ExM_lamRichLimPostOxCor_MP) *
    localSubtract1) + ExM_lamRichLimPostOxCor_MP;

  /* end of Outputs for SubSystem: '<S150>/F03_Rich_limit_Post_oxydation' */

  /* Outputs for atomic SubSystem: '<S150>/F04_Calcul_Post_oxydation' */

  /* Product: '<S295>/Divide' incorporates:
   *  Constant: '<S274>/TMOTATMHSP1'
   *  Product: '<S300>/Divide'
   *  Sum: '<S274>/Subtract2'
   */
  localSubtract1 = ExM_PCI / ((ExM_rAfs * ExM_lamEx) + 1.0F);

  /* Outputs for atomic SubSystem: '<S295>/If Action Subsystem3' */

  /* Switch: '<S305>/Switch1' incorporates:
   *  Constant: '<S305>/Constant1'
   *  Constant: '<S305>/Constant2'
   *  Constant: '<S305>/Constant3'
   *  Logic: '<S305>/Logical Operator1'
   *  RelationalOperator: '<S305>/Relational Operator'
   *  RelationalOperator: '<S305>/Relational Operator1'
   *  RelationalOperator: '<S305>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    localSubtract1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S295>/If Action Subsystem3' */

  /* Product: '<S294>/Divide' incorporates:
   *  Product: '<S301>/Divide'
   */
  localDivide_bfr = (ExM_PCI * ExM_lamEx) / ExM_rAfs;

  /* Outputs for atomic SubSystem: '<S294>/If Action Subsystem3' */

  /* Switch: '<S303>/Switch1' incorporates:
   *  Constant: '<S303>/Constant1'
   *  Constant: '<S303>/Constant2'
   *  Constant: '<S303>/Constant3'
   *  Logic: '<S303>/Logical Operator1'
   *  RelationalOperator: '<S303>/Relational Operator'
   *  RelationalOperator: '<S303>/Relational Operator1'
   *  RelationalOperator: '<S303>/Relational Operator3'
   */
  if (((localDivide_bfr != localDivide_bfr) || (localDivide_bfr >
        3.000000005E+038F)) || (-3.000000005E+038F > localDivide_bfr)) {
    localDivide_bfr = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S294>/If Action Subsystem3' */

  /* Switch: '<S274>/Switch1' incorporates:
   *  Constant: '<S274>/TMOTATMHSP11'
   *  RelationalOperator: '<S274>/Relational Operator3'
   */
  if (ExM_lamEx < 1.0F) {
    ExM_EPostOx_MP = localSubtract1;
  } else {
    ExM_EPostOx_MP = localDivide_bfr;
  }

  /* Product: '<S296>/Divide' incorporates:
   *  Product: '<S298>/Divide'
   *  Product: '<S299>/Divide'
   */
  localSubtract1 = (ExM_mfScvMixt * ExM_EPostOx_MP) / (ExM_cppExMixt *
    ExM_mfEgTotWithScv);

  /* Outputs for atomic SubSystem: '<S296>/If Action Subsystem3' */

  /* Switch: '<S307>/Switch1' incorporates:
   *  Constant: '<S307>/Constant1'
   *  Constant: '<S307>/Constant2'
   *  Constant: '<S307>/Constant3'
   *  Logic: '<S307>/Logical Operator1'
   *  RelationalOperator: '<S307>/Relational Operator'
   *  RelationalOperator: '<S307>/Relational Operator1'
   *  RelationalOperator: '<S307>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    localSubtract1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S296>/If Action Subsystem3' */

  /* DataTypeConversion: '<S293>/OutDTConv' incorporates:
   *  Constant: '<S293>/offset'
   *  Constant: '<S293>/one_on_slope'
   *  Product: '<S293>/Product4'
   *  Sum: '<S293>/Add1'
   */
  localtmp_0 = 32.0F * localSubtract1;
  if (localtmp_0 < 65536.0F) {
    if (localtmp_0 >= 0.0F) {
      localTmpSignalConversionAtEx_df = (UInt16)localtmp_0;
    } else {
      localTmpSignalConversionAtEx_df = 0U;
    }
  } else {
    localTmpSignalConversionAtEx_df = MAX_uint16_T;
  }

  /* Switch: '<S274>/Switch3' incorporates:
   *  Constant: '<S274>/ExM_facPostOx_C'
   *  DataTypeConversion: '<S274>/Data Type Conversion'
   *  Product: '<S297>/Divide'
   *  RelationalOperator: '<S274>/Relational Operator2'
   *  Sum: '<S274>/Subtract5'
   */
  if (ExM_lamEx < ExM_lamLeanLimPostOx) {
    localSubtract1 = (((((Float32)ExM_facPostOx_C) * 0.0078125F) + 0.0078125F) *
                      localSubtract1) + ExM_tExScv;
  } else {
    localSubtract1 = ExM_tExScv;
  }

  /* Switch: '<S274>/Switch4' incorporates:
   *  RelationalOperator: '<S274>/Relational Operator1'
   */
  if (!(ExM_lamEx > ExM_lamRichLimPostOx)) {
    localSubtract1 = ExM_tExScv;
  }

  /* Switch: '<S274>/Switch2' incorporates:
   *  Constant: '<S274>/ExM_bAcvPostOx_C'
   */
  if (ExM_bAcvPostOx_C) {
    ExM_tExScvPostOx = localSubtract1;
  } else {
    ExM_tExScvPostOx = ExM_tExScv;
  }

  /* end of Outputs for SubSystem: '<S150>/F04_Calcul_Post_oxydation' */

  /* end of Outputs for SubSystem: '<S28>/F04_Post_Oxydation' */

  /* end of Outputs for SubSystem: '<S7>/F09_Scavenging' */

  /* Outputs for enable SubSystem: '<S7>/F10_Correction_coupure_injection' incorporates:
   *  EnablePort: '<S29>/Enable'
   */
  if (localTmpSignalConversionAtIgS_i) {
    /* Lookup: '<S308>/Look-Up Table'
     * About '<S308>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U16  2^-8  FSlope 1.00390625
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_jq), (&(ExM_facMassFlowTotExCutOff_T[0])),
                   localTmpSignalConversionAtEng_j, (&(ExM_mfTotExCor_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S308>/Data Type Duplicate1'
     *
     * Regarding '<S308>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S309>/Data Type Conversion1' */
    localtmp = ((Float32d)ExM_tCoMesSwt) + 40.0F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion1_c = (UInt8)localtmp;
      } else {
        localDataTypeConversion1_c = 0U;
      }
    } else {
      localDataTypeConversion1_c = MAX_uint8_T;
    }

    /* Lookup2D: '<S309>/Look-Up Table (2-D)'
     * About '<S309>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U16  2^-5  Bias 223.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U8( &(localLookUpTable2D_h), (&(ExM_tExCutOffStat_M[0])),
                      localTmpSignalConversionAtExt_n, (&(ExM_nEngX_A[0])), 15U,
                      localDataTypeConversion1_c, (&(ExM_tCoMesSwtY_A[0])), 5U);

    /* DataTypeDuplicate Block: '<S309>/Data Type Duplicate2'
     *
     * Regarding '<S309>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S316>/Conversion' incorporates:
     *  Constant: '<S310>/Constant1'
     */
    localSubtract1 = 1.0F;

    /* DataTypeConversion: '<S317>/Conversion' incorporates:
     *  Constant: '<S310>/Constant2'
     */
    localDivide_bfr = 0.0F;

    /* DataTypeConversion: '<S29>/Data Type Conversion' incorporates:
     *  Lookup: '<S308>/Look-Up Table'
     */
    ExM_facTotCutOffFil_MP = ((Float32)localLookUpTable_jq) * 3.921508789E-003F;

    /* Switch: '<S318>/Switch' incorporates:
     *  RelationalOperator: '<S318>/UpperRelop'
     */
    if (!(ExM_facTotCutOffFil_MP < 0.0F)) {
      localDivide_bfr = ExM_facTotCutOffFil_MP;
    }

    /* Switch: '<S318>/Switch2' incorporates:
     *  RelationalOperator: '<S318>/LowerRelop1'
     */
    if (!(ExM_facTotCutOffFil_MP > 1.0F)) {
      localSubtract1 = localDivide_bfr;
    }

    /* DataTypeConversion: '<S29>/Data Type Conversion1' incorporates:
     *  Lookup2D: '<S309>/Look-Up Table (2-D)'
     */
    ExM_tExCutOffStat_MP = (((Float32)localLookUpTable2D_h) * 0.03125F) +
      223.0F;

    /* Product: '<S314>/Divide' */
    localSubtract3_p = ExM_tExCutOffStat_MP * localSubtract1;

    /* Sum: '<S310>/Sum1' incorporates:
     *  Constant: '<S310>/Constant3'
     */
    localDivide_bfr = 1.0F - localSubtract1;

    /* Switch: '<S313>/Switch' incorporates:
     *  UnitDelay: '<S313>/UnitDelay'
     *  UnitDelay: '<S313>/UnitDelay1'
     */
    if (ExMGslT1_DWork.UnitDelay_m) {
      localSubtract1 = ExMGslT1_DWork.UnitDelay;
    } else {
      localSubtract1 = ExM_tExStat;
    }

    /* Switch: '<S310>/Switch' incorporates:
     *  Logic: '<S29>/Logical Operator'
     *  Product: '<S315>/Divide'
     *  Sum: '<S310>/Sum2'
     */
    if (!localTmpSignalConversionAtInjSy) {
      localSubtract1 = ExM_tExStat;
    } else {
      localSubtract1 = (localDivide_bfr * localSubtract1) + localSubtract3_p;
    }

    /* Switch: '<S312>/Switch' incorporates:
     *  UnitDelay: '<S312>/UnitDelay'
     */
    if (ExMGslT1_DWork.UnitDelay_DSTATE_d) {
      ExM_tCutOffCor = localSubtract1;
    } else {
      ExM_tCutOffCor = ExM_tExStat;
    }

    /* Update for UnitDelay: '<S313>/UnitDelay' */
    ExMGslT1_DWork.UnitDelay = localSubtract1;

    /* Update for UnitDelay: '<S313>/UnitDelay1' incorporates:
     *  Constant: '<S313>/Constant3'
     */
    ExMGslT1_DWork.UnitDelay_m = TRUE;

    /* Update for UnitDelay: '<S312>/UnitDelay' incorporates:
     *  Constant: '<S312>/Constant3'
     */
    ExMGslT1_DWork.UnitDelay_DSTATE_d = TRUE;
  }

  /* end of Outputs for SubSystem: '<S7>/F10_Correction_coupure_injection' */

  /* Outputs for atomic SubSystem: '<S7>/F11_Transitoire' */

  /* Product: '<S324>/Divide' */
  localSubtract1 = ExM_mfEgTotWithScv * ExM_cppExMixt;

  /* Switch: '<S30>/Switch4' */
  if (localTmpSignalConversionAtInjSy) {
    localDivide_bfr = ExM_tCutOffCor;
  } else {
    localDivide_bfr = ExM_tExScvPostOx;
  }

  /* Sum: '<S30>/Subtract4' incorporates:
   *  Constant: '<S30>/Cste_273'
   */
  localSubtract3_p = ExM_tCoMesSwt + 273.0F;

  /* Switch: '<S30>/Switch2' */
  if (localTmpSignalConversionAtIgS_i) {
    ExM_tExAfterTran_MP = localDivide_bfr;
  } else {
    ExM_tExAfterTran_MP = localSubtract3_p;
  }

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S30>/ExM_wMassVlvHeatECoDown_C'
   *  Constant: '<S30>/ExM_wMassVlvHeatE_C'
   *  DataTypeConversion: '<S30>/Data Type Conversion3'
   *  DataTypeConversion: '<S30>/Data Type Conversion4'
   */
  if (localTmpSignalConversionAtIgS_i) {
    ExM_wMassVlvHeatEShift_MP = ((Float32)ExM_wMassVlvHeatE_C) + 1.0F;
  } else {
    ExM_wMassVlvHeatEShift_MP = ((Float32)ExM_wMassVlvHeatECoDown_C) + 1.0F;
  }

  /* Switch: '<S321>/Switch' incorporates:
   *  UnitDelay: '<S327>/Unit Delay'
   *  UnitDelay: '<S328>/Unit Delay'
   */
  if (ExMGslT1_DWork.UnitDelay_DSTATE_e) {
    ExM_tDynPrev_MP = ExMGslT1_DWork.UnitDelay_DSTATE;
  } else {
    ExM_tDynPrev_MP = localSubtract3_p;
  }

  /* Sum: '<S30>/Subtract1' */
  ExM_wAbsTotHeat_MP = ExM_wMassVlvHeatEShift_MP + localSubtract1;

  /* Product: '<S320>/Divide' incorporates:
   *  Product: '<S322>/Divide'
   *  Product: '<S323>/Divide'
   *  Sum: '<S30>/Subtract2'
   */
  localSubtract1 = ((localSubtract1 * ExM_tExAfterTran_MP) +
                    (ExM_wMassVlvHeatEShift_MP * ExM_tDynPrev_MP)) /
    ExM_wAbsTotHeat_MP;

  /* Outputs for atomic SubSystem: '<S320>/If Action Subsystem3' */

  /* Switch: '<S326>/Switch1' incorporates:
   *  Constant: '<S326>/Constant1'
   *  Constant: '<S326>/Constant2'
   *  Constant: '<S326>/Constant3'
   *  Logic: '<S326>/Logical Operator1'
   *  RelationalOperator: '<S326>/Relational Operator'
   *  RelationalOperator: '<S326>/Relational Operator1'
   *  RelationalOperator: '<S326>/Relational Operator3'
   */
  if (((localSubtract1 != localSubtract1) || (localSubtract1 > 3.000000005E+038F))
      || (-3.000000005E+038F > localSubtract1)) {
    localSubtract1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S320>/If Action Subsystem3' */

  /* Switch: '<S30>/Switch3' incorporates:
   *  Constant: '<S30>/ExM_bSelTExDyn_C'
   *  Constant: '<S30>/ExM_tSelTExDyn_C'
   *  Constant: '<S319>/offset'
   *  Constant: '<S319>/one_on_slope'
   *  DataTypeConversion: '<S319>/OutDTConv'
   *  Product: '<S319>/Product4'
   *  Sum: '<S319>/Add1'
   */
  if (ExM_bSelTExDyn_C) {
    localTmpSignalConversionAtExM_g = ExM_tSelTExDyn_C;
  } else {
    localtmp_0 = (localSubtract1 - 223.0F) * 32.0F;
    if (localtmp_0 < 65536.0F) {
      if (localtmp_0 >= 0.0F) {
        localTmpSignalConversionAtExM_g = (UInt16)localtmp_0;
      } else {
        localTmpSignalConversionAtExM_g = 0U;
      }
    } else {
      localTmpSignalConversionAtExM_g = MAX_uint16_T;
    }
  }

  /* Update for UnitDelay: '<S328>/Unit Delay' */
  ExMGslT1_DWork.UnitDelay_DSTATE = localSubtract1;

  /* Update for UnitDelay: '<S327>/Unit Delay' incorporates:
   *  Constant: '<S321>/Constant3'
   */
  ExMGslT1_DWork.UnitDelay_DSTATE_e = TRUE;

  /* end of Outputs for SubSystem: '<S7>/F11_Transitoire' */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Byp_Fonction_SC'
   *  Constant: '<S37>/Int_BypC'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localMerge10 = ExM_facCorIgProtComp_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_facCorIgProtCompInport2' */
  Rte_Write_P_ExM_facCorIgProtComp_ExM_facCorIgProtComp(localMerge10);

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Byp_Fonction_SC'
   *  Constant: '<S39>/Int_BypC'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localMerge2 = ExM_facCorProtComp_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_facCorProtCompInport2' */
  Rte_Write_P_ExM_facCorProtComp_ExM_facCorProtComp(localMerge2);

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Byp_Fonction_SC'
   *  Constant: '<S33>/Int_BypC'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localTmpSignalConversionAtFARSp = ExM_gmaInMixt_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_gmaInMixtInport2' */
  Rte_Write_P_ExM_gmaInMixt_ExM_gmaInMixt(localTmpSignalConversionAtFARSp);

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Byp_Fonction_SC'
   *  Constant: '<S34>/Int_BypC'
   *  DataTypeConversion: '<S168>/OutDTConv'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgSys = ExM_lamTot_B;
  } else if (localDataTypeConversion2_n < 4.294967296E+009F) {
    if (localDataTypeConversion2_n >= 0.0F) {
      localTmpSignalConversionAtIgSys = (UInt32)localDataTypeConversion2_n;
    } else {
      localTmpSignalConversionAtIgSys = 0U;
    }
  } else {
    localTmpSignalConversionAtIgSys = MAX_uint32_T;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_lamTotInport2' */
  Rte_Write_P_ExM_lamTot_ExM_lamTot(localTmpSignalConversionAtIgSys);

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Byp_Fonction_SC'
   *  Constant: '<S35>/Int_BypC'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEx_fu = ExM_mfEgTot_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_mfEgTotInport2' */
  Rte_Write_P_ExM_mfEgTot_ExM_mfEgTot(localTmpSignalConversionAtEx_fu);

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Byp_Fonction_SC'
   *  Constant: '<S32>/Int_BypC'
   *  DataTypeConversion: '<S238>/OutDTConv'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localTmpSignalConversionAtFARSp = ExM_molMassInMixt_B;
  } else if (localDataTypeConversion3_n < 65536.0F) {
    if (localDataTypeConversion3_n >= 0.0F) {
      localTmpSignalConversionAtFARSp = (UInt16)localDataTypeConversion3_n;
    } else {
      localTmpSignalConversionAtFARSp = 0U;
    }
  } else {
    localTmpSignalConversionAtFARSp = MAX_uint16_T;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_molMassInMixtInport2' */
  Rte_Write_P_ExM_molMassInMixt_ExM_molMassInMixt
    (localTmpSignalConversionAtFARSp);

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/Byp_Fonction_SC'
   *  Constant: '<S36>/Int_BypC'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExM_g = ExM_tExDyn_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExDynInport2' */
  Rte_Write_P_ExM_tExDyn_ExM_tExDyn(localTmpSignalConversionAtExM_g);

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Byp_Fonction_SC'
   *  Constant: '<S40>/Int_BypC'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEx_df = ExM_tExPostOxOfs_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExPostOxOfsInport2' */
  Rte_Write_P_ExM_tExPostOxOfs_ExM_tExPostOxOfs(localTmpSignalConversionAtEx_df);

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Byp_Fonction_SC'
   *  Constant: '<S38>/Int_BypC'
   */
  if (EXMGSLT1_ACTIVE_BYP_C) {
    localMerge1 = ExM_tExStatAfs_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExStatAfsInport2' */
  Rte_Write_P_ExM_tExStatAfs_ExM_tExStatAfs(localMerge1);
}

/* Model initialize function */
void RE_ExMGslT_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  RE_ExMGslT1_004_MSE_Start();
  RE_ExMGslT1_003_TEV_Start();
  RE_ExMGslT1_002_TEV_Start();
}

#define ExMGslT1_STOP_SEC_CODE
#include "ExMGslT1_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
