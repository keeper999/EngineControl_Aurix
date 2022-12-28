/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMaxT                                                 */
/* !Description     : AdvMaxT Software Component                              */
/*                                                                            */
/* !Module          : AdvMaxT                                                 */
/* !Description     : AdvMaxT Software Component                              */
/*                                                                            */
/* !File            : AdvMaxT.c                                               */
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
/*   Model name       : AdvMaxT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMaxT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M04-AdvMaxT/5-S$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   ADELVARE                               $$Date::   03 Aug 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvMaxT.h"
#include "AdvMaxT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AdvMaxT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMaxT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AdvMaxT AdvMaxT_B;

#define AdvMaxT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvMaxT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define ADVMAXT_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define ADVMAXT_VEMSRTLIBT_MINOR_VERSION_REQ 2
#define ADVMAXT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define ADVMAXT_VEMSRTLIBT_VERSION_REQ (ADVMAXT_VEMSRTLIBT_PATCH_VERSION_REQ + ADVMAXT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + ADVMAXT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if ADVMAXT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AdvMaxT_START_SEC_CODE
#include "AdvMaxT_MemMap.h"

void AdvMaxT_ASYNC1(int controlPortIdx)
{
}

/* Start for exported function: RE_AdvMaxT_001_MSE */
void RE_AdvMaxT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_AdvMax_Init'
   */
}

/* Output and update for exported function: RE_AdvMaxT_001_MSE */
void RE_AdvMaxT_001_MSE(void)
{
  UInt8 localSwitch;
  UInt8 localSwitch_o[6];
  SInt32 locali;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_AdvMax_Init'
   */

  /* user code (Output function Body for TID3) */
  Runnable_AdvMax_Init();

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Byp_Fonction_SC'
   *  Constant: '<S7>/Int_BypC'
   */
  if (ADVMAXT_ACTIVE_BYP_C) {
    localSwitch = IgSys_agIgMaxWiPrevMv_B;
  } else {
    localSwitch = 96U;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevMvInport2' */
  Rte_Write_P_IgSys_agIgMaxWiPrevMv_IgSys_agIgMaxWiPrevMv(localSwitch);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Byp_Fonction_SC'
   *  Constant: '<S6>/Int_BypC'
   */
  if (ADVMAXT_ACTIVE_BYP_C) {
    localSwitch = IgSys_agIgMaxWiPrevAdpMv_B;
  } else {
    localSwitch = 96U;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevAdpMvInport2' */
  Rte_Write_P_IgSys_agIgMaxWiPrevAdpMv_IgSys_agIgMaxWiPrevAdpMv(localSwitch);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Byp_Fonction_SC'
   *  Constant: '<S8>/Int_BypC'
   */
  if (ADVMAXT_ACTIVE_BYP_C) {
    localSwitch = IgSys_agIgKnkAdpOfsMv_B;
  } else {
    localSwitch = 96U;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtIgSys_agIgKnkAdpOfsMvInport2' */
  Rte_Write_P_IgSys_agIgKnkAdpOfsMv_IgSys_agIgKnkAdpOfsMv(localSwitch);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Byp_Fonction_SC'
   *  Constant: '<S9>/Int_BypC'
   */
  for (locali = 0; locali < 6; locali++) {
    if (ADVMAXT_ACTIVE_BYP_C) {
      localSwitch_o[locali] = IgSys_prm_agIgMaxWiPrevAdpCyl_B[(locali)];
    } else {
      localSwitch_o[locali] = AdvMaxT_ConstB.DataTypeConversion_o[(locali)];
    }
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtIgSys_prm_agIgMaxWiPrevAdpCylInport2' */
  Rte_Write_P_IgSys_prm_agIgMaxWiPrevAdpCyl_IgSys_prm_agIgMaxWiPrevAdpCyl
    (&localSwitch_o);
}

/* Output and update for exported function: RE_AdvMaxT_002_DRE */
void RE_AdvMaxT_002_DRE(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion1;
  UInt16 localDataTypeConversion1_d;
  UInt16 localDataTypeConversion1_k;
  UInt16 localDataTypeConversion1_e;
  UInt16 localDataTypeConversion;
  UInt16 localDataTypeConversion_j;
  UInt16 localDataTypeConversion_b;
  UInt16 localDataTypeConversion_p;
  UInt16 localDataTypeConversion_e;
  UInt16 localDataTypeConversion_o;
  UInt16 localDataTypeConversion_ol;
  UInt16 localDataTypeConversion_i;
  UInt16 localDataTypeConversion1_p;
  UInt16 localDataTypeConversion1_j;
  UInt16 localDataTypeConversion1_k5;
  UInt16 localDataTypeConversion1_jk;
  SInt16 localLookUpTable2D;
  SInt16 localLookUpTable2D_o;
  UInt16 localTmpSignalConversionAtExt_n;
  SInt32 localDTConv_Single_To_UFix_1;
  Float32 localDTConv_Single_To_UFix_12;
  Float32 localDTConv_Single_To_UFix_2;
  Float32 localDTConv_Single_To_UFix_7;
  Float32 localDTConv_Single_To_UFix_9;
  UInt8 localTmpSignalConversionAtEng_s;
  Float32 localSum7;
  Float32 localAbs4;
  Float32 localAbs;
  Float32 localAbs3;
  UInt8 localMultiportSwitch[6];
  Float32 localDivide_f[6];
  Boolean localTmpSignalConversionAtIgS_l;
  UInt8 localTmpSignalConversionAtIgS_n[10];
  UInt8 localTmpSignalConversionAtIg_ah[10];
  UInt8 localTmpSignalConversionAtIgS_c;
  UInt8 localTmpSignalConversionAtKnkMg[6];
  UInt16 localTmpSignalConversionAtEngM_;
  UInt8 localTmpSignalConversionAtIgS_p;
  SInt16 localTmpSignalConversionAtExt_a;
  SInt16 localTmpSignalConversionAtExt_e;
  UInt16 localTmpSignalConversionAtIgSys;
  UInt8 localTmpSignalConversionAtIgS_g;
  UInt8 localTmpSignalConversionAtIgS_o;
  UInt8 localTmpSignalConversionAtIgS_a[6];
  UInt8 localTmpSignalConversionAtIgS_d;
  UInt8 localTmpSignalConversionAtIg_o5;
  UInt8 localTmpSignalConversionAtIgS_f;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_AdvMax'
   *
   * Block requirements for '<S1>/F01_AdvMax':
   *  1. SubSystem "F01_AdvMax" !Trace_To : VEMS_R_10_06439_001.01 ;
   */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* DataTypeConversion: '<S5>/DTConv_Single_To_UFix_1' */
  localDTConv_Single_To_UFix_1 = localTmpSignalConversionAtExt_n;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_prm_facFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_facFlex'
   */
  Rte_Read_R_IgSys_prm_facFlex_IgSys_prm_facFlex
    (&localTmpSignalConversionAtIgS_n);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_prm_facGasOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_facGas'
   */
  Rte_Read_R_IgSys_prm_facGas_IgSys_prm_facGas(&localTmpSignalConversionAtIg_ah);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgMaxGasOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMaxGas'
   */
  Rte_Read_R_IgSys_agIgMaxGas_IgSys_agIgMaxGas(&localTmpSignalConversionAtIgS_c);

  /* DataTypeConversion: '<S5>/DTConv_Single_To_UFix_12' */
  localDTConv_Single_To_UFix_12 = (((Float32)localTmpSignalConversionAtIgS_c) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtKnkMgt_prm_agIgKnkAdpOfsCylOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_prm_agIgKnkAdpOfsCyl'
   */
  Rte_Read_R_KnkMgt_prm_agIgKnkAdpOfsCyl_KnkMgt_prm_agIgKnkAdpOfsCyl
    (&localTmpSignalConversionAtKnkMg);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEngM_);

  /* DataTypeConversion: '<S5>/DTConv_Single_To_UFix_2' */
  localDTConv_Single_To_UFix_2 = ((Float32)localTmpSignalConversionAtEngM_) *
    6.103515625E-005F;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgKnkPrevOfsOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgKnkPrevOfs'
   */
  Rte_Read_R_IgSys_agIgKnkPrevOfs_IgSys_agIgKnkPrevOfs
    (&localTmpSignalConversionAtIgS_p);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_agCkOpInVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkOpInVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0
    (&localTmpSignalConversionAtExt_a);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_agCkClsExVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkClsExVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0
    (&localTmpSignalConversionAtExt_e);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_rAirLdClcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rAirLdClc'
   */
  Rte_Read_R_IgSys_rAirLdClc_IgSys_rAirLdClc(&localTmpSignalConversionAtIgSys);

  /* DataTypeConversion: '<S5>/DTConv_Single_To_UFix_7' */
  localDTConv_Single_To_UFix_7 = ((Float32)localTmpSignalConversionAtIgSys) *
    6.103515625E-005F;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgCmbModOfsMaxOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgCmbModOfsMax'
   */
  Rte_Read_R_IgSys_agIgCmbModOfsMax_IgSys_agIgCmbModOfsMax
    (&localTmpSignalConversionAtIgS_g);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgMaxFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMaxFlex'
   */
  Rte_Read_R_IgSys_agIgMaxFlex_IgSys_agIgMaxFlex
    (&localTmpSignalConversionAtIgS_o);

  /* DataTypeConversion: '<S5>/DTConv_Single_To_UFix_9' */
  localDTConv_Single_To_UFix_9 = (((Float32)localTmpSignalConversionAtIgS_o) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* Outputs for atomic SubSystem: '<S5>/F01_Activation' *
   * Block requirements for '<S5>/F01_Activation':
   *  1. SubSystem "F01_Activation" !Trace_To : VEMS_R_10_06439_003.01 ;
   */

  /* Logic: '<S10>/Logical Operator' incorporates:
   *  Constant: '<S10>/Ext_stRun_SC'
   *  Constant: '<S10>/IgSys_bAcvETBMod_C'
   *  Logic: '<S10>/Logical Operator1'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  IgSys_bAcvAdvMax = ((!IgSys_bAcvETBMod_C) && (localTmpSignalConversionAtEng_s ==
    Ext_stRun_SC));

  /* end of Outputs for SubSystem: '<S5>/F01_Activation' */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_bAirLdDynDetOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAirLdDynDet'
   */
  Rte_Read_R_IgSys_bAirLdDynDet_IgSys_bAirLdDynDet
    (&localTmpSignalConversionAtIgS_l);

  /* Outputs for enable SubSystem: '<S5>/F02_CalcAdvMax' incorporates:
   *  EnablePort: '<S11>/IgSys_bAcvAdvMax'
   *
   * Block requirements for '<S5>/F02_CalcAdvMax':
   *  1. SubSystem "F02_CalcAdvMax" !Trace_To : VEMS_R_10_06439_004.01 ;
   */
  if (IgSys_bAcvAdvMax) {
    /* Outputs for atomic SubSystem: '<S11>/F01_AdvKnkBasStatDyn' *
     * Block requirements for '<S11>/F01_AdvKnkBasStatDyn':
     *  1. SubSystem "F01_AdvKnkBasStatDyn" !Trace_To : VEMS_R_10_06439_005.01 ;
     */

    /* Outputs for atomic SubSystem: '<S17>/F01_Calc_facteurs_ponderation' *
     * Block requirements for '<S17>/F01_Calc_facteurs_ponderation':
     *  1. SubSystem "F01_Calc_facteurs_ponderation" !Trace_To : VEMS_R_10_06439_006.01 ;
     */

    /* DataTypeConversion: '<S22>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_2, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion_e = (UInt16)localtmp;
      } else {
        localDataTypeConversion_e = 0U;
      }
    } else {
      localDataTypeConversion_e = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S22>/Data Type Conversion1' */
    localDataTypeConversion1 = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S22>/Look-Up Table (2-D)'
     * About '<S22>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    S16  2^-1  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_S16_U16_U16( &(localLookUpTable2D), (&(IgSys_agCkOpInVlvWrmDft_M[0])),
                       localDataTypeConversion_e, (&(Eng_rAirLd_A[0])), 15U,
                       localDataTypeConversion1, (&(Ext_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate2'
     *
     * Regarding '<S22>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S19>/DTConv_UFix_To_Single_1' incorporates:
     *  Lookup2D: '<S22>/Look-Up Table (2-D)'
     */
    IgSys_agCkOpInVlvWrmAdvMax_MP = ((Float32)localLookUpTable2D) * 0.75F;

    /* Sum: '<S19>/Sum2' incorporates:
     *  DataTypeConversion: '<S5>/DTConv_Single_To_UFix_4'
     */
    IgSys_agCkDeltaInVlv_MP = (((Float32)localTmpSignalConversionAtExt_a) *
      0.09375F) - IgSys_agCkOpInVlvWrmAdvMax_MP;

    /* Abs: '<S19>/Abs' */
    localAbs = ACTEMS_FabsF(IgSys_agCkDeltaInVlv_MP);

    /* DataTypeConversion: '<S25>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_2, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion_o = (UInt16)localtmp;
      } else {
        localDataTypeConversion_o = 0U;
      }
    } else {
      localDataTypeConversion_o = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S25>/Data Type Conversion1' */
    localDataTypeConversion1_d = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S25>/Look-Up Table (2-D)'
     * About '<S25>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    S16  2^-1  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_S16_U16_U16( &(localLookUpTable2D_o), (&(IgSys_agCkClsExVlvWrmDft_M[0])),
                       localDataTypeConversion_o, (&(Eng_rAirLd_A[0])), 15U,
                       localDataTypeConversion1_d, (&(Ext_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S25>/Data Type Duplicate2'
     *
     * Regarding '<S25>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S19>/DTConv_UFix_To_Single_2' incorporates:
     *  Lookup2D: '<S25>/Look-Up Table (2-D)'
     */
    IgSys_agCkClsExVlvWrmAdvMax_MP = ((Float32)localLookUpTable2D_o) * 0.75F;

    /* Sum: '<S19>/Sum3' incorporates:
     *  DataTypeConversion: '<S5>/DTConv_Single_To_UFix_5'
     */
    IgSys_agCkDeltaExVlv_MP = (((Float32)localTmpSignalConversionAtExt_e) *
      0.09375F) - IgSys_agCkClsExVlvWrmAdvMax_MP;

    /* Sum: '<S19>/Sum8' incorporates:
     *  Constant: '<S19>/Vlv_agCkExVlvRefMin_C'
     */
    localSum7 = (((Float32)Vlv_agCkExVlvRefMin_C) * 0.09375F) -
      IgSys_agCkClsExVlvWrmAdvMax_MP;

    /* Saturate: '<S19>/Saturation5' */
    localSum7 = rt_SATURATE(localSum7, -100.0F, -1.0F);

    /* Abs: '<S19>/Abs3' */
    localAbs3 = ACTEMS_FabsF(localSum7);

    /* Sum: '<S19>/Sum1' incorporates:
     *  Constant: '<S19>/Vlv_agCkInVlvRefMin_C'
     */
    localSum7 = (((Float32)Vlv_agCkInVlvRefMin_C) * 0.09375F) -
      IgSys_agCkOpInVlvWrmAdvMax_MP;

    /* Saturate: '<S19>/Saturation4' */
    localSum7 = rt_SATURATE(localSum7, -100.0F, -1.0F);

    /* Abs: '<S19>/Abs4' */
    localAbs4 = ACTEMS_FabsF(localSum7);

    /* Sum: '<S19>/Sum4' incorporates:
     *  Constant: '<S19>/Vlv_agCkInVlvRefMax_C'
     */
    localSum7 = (((Float32)Vlv_agCkInVlvRefMax_C) * 0.09375F) -
      IgSys_agCkOpInVlvWrmAdvMax_MP;

    /* Switch: '<S19>/Switch1' incorporates:
     *  Constant: '<S19>/Constant6'
     *  Product: '<S26>/Divide'
     *  Product: '<S27>/Divide'
     *  RelationalOperator: '<S19>/Relational Operator3'
     *  Saturate: '<S19>/Saturation3'
     */
    if (IgSys_agCkDeltaInVlv_MP < 0.0F) {
      IgSys_rDeltaInVlv_MP = IgSys_agCkDeltaInVlv_MP / localAbs4;
    } else {
      IgSys_rDeltaInVlv_MP = IgSys_agCkDeltaInVlv_MP / rt_SATURATE(localSum7,
        1.0F, 100.0F);
    }

    /* Switch: '<S19>/Switch4' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S19>/IgSys_agCkDeltaInVlvThd_C'
     *  RelationalOperator: '<S19>/Relational Operator2'
     */
    if (localAbs > (((Float32)IgSys_agCkDeltaInVlvThd_C) * 0.75F)) {
      IgSys_facAdvMaxInVlv = IgSys_rDeltaInVlv_MP;
    } else {
      IgSys_facAdvMaxInVlv = 0.0F;
    }

    /* Sum: '<S19>/Sum7' incorporates:
     *  Constant: '<S19>/Vlv_agCkExVlvRefMax_C'
     */
    localSum7 = (((Float32)Vlv_agCkExVlvRefMax_C) * 0.09375F) -
      IgSys_agCkClsExVlvWrmAdvMax_MP;

    /* Switch: '<S19>/Switch3' incorporates:
     *  Constant: '<S19>/Constant3'
     *  Product: '<S28>/Divide'
     *  Product: '<S29>/Divide'
     *  RelationalOperator: '<S19>/Relational Operator4'
     *  Saturate: '<S19>/Saturation1'
     */
    if (IgSys_agCkDeltaExVlv_MP < 0.0F) {
      IgSys_rDeltaExVlv_MP = IgSys_agCkDeltaExVlv_MP / localAbs3;
    } else {
      IgSys_rDeltaExVlv_MP = IgSys_agCkDeltaExVlv_MP / rt_SATURATE(localSum7,
        1.0F, 100.0F);
    }

    /* Switch: '<S19>/Switch2' incorporates:
     *  Abs: '<S19>/Abs1'
     *  Constant: '<S19>/Constant2'
     *  Constant: '<S19>/IgSys_agCkDeltaExVlvThd_C'
     *  RelationalOperator: '<S19>/Relational Operator1'
     */
    if (ACTEMS_FabsF(IgSys_agCkDeltaExVlv_MP) > (((Float32)
          IgSys_agCkDeltaExVlvThd_C) * 0.75F)) {
      IgSys_facAdvMaxExVlv = IgSys_rDeltaExVlv_MP;
    } else {
      IgSys_facAdvMaxExVlv = 0.0F;
    }

    /* Lookup2D: '<S23>/Look-Up Table (2-D)'
     * About '<S23>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(IgSys_rAdvMaxExVlv),
      (&(IgSys_rAdvMaxExVlv_M[0])), IgSys_facAdvMaxInVlv,
      (&(Vlv_agCkInVlvNorm_A[0])), 16U, IgSys_facAdvMaxExVlv,
      (&(Vlv_agCkExVlvNorm_A[0])), 16U);

    /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate2'
     *
     * Regarding '<S23>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S24>/Look-Up Table (2-D)'
     * About '<S24>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(IgSys_rAdvMaxInVlv),
      (&(IgSys_rAdvMaxInVlv_M[0])), IgSys_facAdvMaxInVlv,
      (&(Vlv_agCkInVlvNorm_A[0])), 16U, IgSys_facAdvMaxExVlv,
      (&(Vlv_agCkExVlvNorm_A[0])), 16U);

    /* DataTypeDuplicate Block: '<S24>/Data Type Duplicate2'
     *
     * Regarding '<S24>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S17>/F01_Calc_facteurs_ponderation' */

    /* Outputs for atomic SubSystem: '<S17>/F02_Degradation_knk_stat' *
     * Block requirements for '<S17>/F02_Degradation_knk_stat':
     *  1. SubSystem "F02_Degradation_knk_stat" !Trace_To : VEMS_R_10_06439_007.01 ;
     */

    /* Outputs for atomic SubSystem: '<S20>/F01_AdvMaxInVlvStat' *
     * Block requirements for '<S20>/F01_AdvMaxInVlvStat':
     *  1. SubSystem "F01_AdvMaxInVlvStat" !Trace_To : VEMS_R_10_06439_008.01 ;
     */

    /* DataTypeConversion: '<S34>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_2, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion1_jk = (UInt16)localtmp;
      } else {
        localDataTypeConversion1_jk = 0U;
      }
    } else {
      localDataTypeConversion1_jk = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S34>/Data Type Conversion1' */
    localDataTypeConversion_p = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S34>/Look-Up Table (2-D)'
     * About '<S34>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxStatInVlvMax),
      (&(IgSys_agIgMaxInVlvMax_M[0])), localDataTypeConversion1_jk,
      (&(Eng_rAirLd_A[0])), 15U, localDataTypeConversion_p, (&(Ext_nEng_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate2'
     *
     * Regarding '<S34>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S35>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_2, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion_p = (UInt16)localtmp;
      } else {
        localDataTypeConversion_p = 0U;
      }
    } else {
      localDataTypeConversion_p = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S35>/Data Type Conversion1' */
    localDataTypeConversion1_jk = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S35>/Look-Up Table (2-D)'
     * About '<S35>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxStatInVlvMin),
      (&(IgSys_agIgMaxInVlvMin_M[0])), localDataTypeConversion_p,
      (&(Eng_rAirLd_A[0])), 15U, localDataTypeConversion1_jk, (&(Ext_nEng_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate2'
     *
     * Regarding '<S35>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S20>/F01_AdvMaxInVlvStat' */

    /* Outputs for atomic SubSystem: '<S20>/F02_AdvMaxVlvStat' *
     * Block requirements for '<S20>/F02_AdvMaxVlvStat':
     *  1. SubSystem "F02_AdvMaxVlvStat" !Trace_To : VEMS_R_10_06439_009.01 ;
     */

    /* DataTypeConversion: '<S36>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_2, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion_i = (UInt16)localtmp;
      } else {
        localDataTypeConversion_i = 0U;
      }
    } else {
      localDataTypeConversion_i = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S36>/Data Type Conversion1' */
    localDataTypeConversion1_e = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S36>/Look-Up Table (2-D)'
     * About '<S36>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxVlvStatRef),
      (&(IgSys_agIgMaxVlvRef_M[0])), localDataTypeConversion_i, (&(Eng_rAirLd_A
      [0])), 15U, localDataTypeConversion1_e, (&(Ext_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate2'
     *
     * Regarding '<S36>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S20>/F02_AdvMaxVlvStat' */

    /* Outputs for atomic SubSystem: '<S20>/F03_AdvMaxExVlvStat' *
     * Block requirements for '<S20>/F03_AdvMaxExVlvStat':
     *  1. SubSystem "F03_AdvMaxExVlvStat" !Trace_To : VEMS_R_10_06439_010.01 ;
     */

    /* DataTypeConversion: '<S37>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_2, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion1_k5 = (UInt16)localtmp;
      } else {
        localDataTypeConversion1_k5 = 0U;
      }
    } else {
      localDataTypeConversion1_k5 = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S37>/Data Type Conversion1' */
    localDataTypeConversion_b = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S37>/Look-Up Table (2-D)'
     * About '<S37>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxStatExVlvMax),
      (&(IgSys_agIgMaxExVlvMax_M[0])), localDataTypeConversion1_k5,
      (&(Eng_rAirLd_A[0])), 15U, localDataTypeConversion_b, (&(Ext_nEng_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate2'
     *
     * Regarding '<S37>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S38>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_2, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion_b = (UInt16)localtmp;
      } else {
        localDataTypeConversion_b = 0U;
      }
    } else {
      localDataTypeConversion_b = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S38>/Data Type Conversion1' */
    localDataTypeConversion1_k5 = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S38>/Look-Up Table (2-D)'
     * About '<S38>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxStatExVlvMin),
      (&(IgSys_agIgMaxExVlvMin_M[0])), localDataTypeConversion_b,
      (&(Eng_rAirLd_A[0])), 15U, localDataTypeConversion1_k5, (&(Ext_nEng_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S38>/Data Type Duplicate2'
     *
     * Regarding '<S38>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S20>/F03_AdvMaxExVlvStat' */

    /* Outputs for atomic SubSystem: '<S20>/F04_AdvKnkBasStat' *
     * Block requirements for '<S20>/F04_AdvKnkBasStat':
     *  1. SubSystem "F04_AdvKnkBasStat" !Trace_To : VEMS_R_10_06439_011.01 ;
     */

    /* Product: '<S40>/Divide' incorporates:
     *  Sum: '<S33>/Sum'
     */
    IgSys_agIgStatInVlvMax_MP = (IgSys_agIgMaxStatInVlvMax -
      IgSys_agIgMaxVlvStatRef) * IgSys_rAdvMaxInVlv;

    /* Product: '<S39>/Divide' incorporates:
     *  Sum: '<S33>/Sum1'
     */
    IgSys_agIgStatInVlvMin_MP = (IgSys_agIgMaxStatInVlvMin -
      IgSys_agIgMaxVlvStatRef) * IgSys_rAdvMaxInVlv;

    /* Switch: '<S33>/Switch5' incorporates:
     *  Constant: '<S33>/Constant6'
     *  RelationalOperator: '<S33>/Relational Operator3'
     */
    if (IgSys_facAdvMaxInVlv >= 0.0F) {
      localDTConv_Single_To_UFix_2 = IgSys_agIgStatInVlvMax_MP;
    } else {
      localDTConv_Single_To_UFix_2 = IgSys_agIgStatInVlvMin_MP;
    }

    /* Product: '<S41>/Divide' incorporates:
     *  Sum: '<S33>/Sum3'
     */
    IgSys_agIgStatExVlvMax_MP = (IgSys_agIgMaxStatExVlvMax -
      IgSys_agIgMaxVlvStatRef) * IgSys_rAdvMaxExVlv;

    /* Product: '<S42>/Divide' incorporates:
     *  Sum: '<S33>/Sum4'
     */
    IgSys_agIgStatExVlvMin_MP = (IgSys_agIgMaxStatExVlvMin -
      IgSys_agIgMaxVlvStatRef) * IgSys_rAdvMaxExVlv;

    /* Switch: '<S33>/Switch1' incorporates:
     *  Constant: '<S33>/Constant1'
     *  RelationalOperator: '<S33>/Relational Operator1'
     */
    if (IgSys_facAdvMaxExVlv >= 0.0F) {
      localAbs = IgSys_agIgStatExVlvMax_MP;
    } else {
      localAbs = IgSys_agIgStatExVlvMin_MP;
    }

    /* Sum: '<S33>/Sum2' */
    IgSys_agIgKnkBasStat = (IgSys_agIgMaxVlvStatRef +
      localDTConv_Single_To_UFix_2) + localAbs;

    /* end of Outputs for SubSystem: '<S20>/F04_AdvKnkBasStat' */

    /* end of Outputs for SubSystem: '<S17>/F02_Degradation_knk_stat' */

    /* Outputs for atomic SubSystem: '<S17>/F03_Degradation_knk_dyn' *
     * Block requirements for '<S17>/F03_Degradation_knk_dyn':
     *  1. SubSystem "F03_Degradation_knk_dyn" !Trace_To : VEMS_R_10_06439_012.01 ;
     */

    /* Outputs for atomic SubSystem: '<S21>/F01_AdvMaxInVlvDyn' *
     * Block requirements for '<S21>/F01_AdvMaxInVlvDyn':
     *  1. SubSystem "F01_AdvMaxInVlvDyn" !Trace_To : VEMS_R_10_06439_013.01 ;
     */

    /* DataTypeConversion: '<S47>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_7, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion1_j = (UInt16)localtmp;
      } else {
        localDataTypeConversion1_j = 0U;
      }
    } else {
      localDataTypeConversion1_j = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S47>/Data Type Conversion1' */
    localDataTypeConversion_j = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S47>/Look-Up Table (2-D)'
     * About '<S47>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxDynInVlvMin),
      (&(IgSys_agIgMaxInVlvMin_M[0])), localDataTypeConversion1_j,
      (&(Eng_rAirLd_A[0])), 15U, localDataTypeConversion_j, (&(Ext_nEng_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S47>/Data Type Duplicate2'
     *
     * Regarding '<S47>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S48>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_7, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion_j = (UInt16)localtmp;
      } else {
        localDataTypeConversion_j = 0U;
      }
    } else {
      localDataTypeConversion_j = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S48>/Data Type Conversion1' */
    localDataTypeConversion1_j = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S48>/Look-Up Table (2-D)'
     * About '<S48>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxDynInVlvMax),
      (&(IgSys_agIgMaxInVlvMax_M[0])), localDataTypeConversion_j,
      (&(Eng_rAirLd_A[0])), 15U, localDataTypeConversion1_j, (&(Ext_nEng_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S48>/Data Type Duplicate2'
     *
     * Regarding '<S48>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S21>/F01_AdvMaxInVlvDyn' */

    /* Outputs for atomic SubSystem: '<S21>/F02_AdvMaxVlvDyn' *
     * Block requirements for '<S21>/F02_AdvMaxVlvDyn':
     *  1. SubSystem "F02_AdvMaxVlvDyn" !Trace_To : VEMS_R_10_06439_014.01 ;
     */

    /* DataTypeConversion: '<S49>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_7, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion_ol = (UInt16)localtmp;
      } else {
        localDataTypeConversion_ol = 0U;
      }
    } else {
      localDataTypeConversion_ol = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S49>/Data Type Conversion1' */
    localDataTypeConversion1_k = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S49>/Look-Up Table (2-D)'
     * About '<S49>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxVlvDynRef),
      (&(IgSys_agIgMaxVlvRef_M[0])), localDataTypeConversion_ol,
      (&(Eng_rAirLd_A[0])), 15U, localDataTypeConversion1_k, (&(Ext_nEng_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S49>/Data Type Duplicate2'
     *
     * Regarding '<S49>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S21>/F02_AdvMaxVlvDyn' */

    /* Outputs for atomic SubSystem: '<S21>/F03_AdvMaxExVlvDyn' *
     * Block requirements for '<S21>/F03_AdvMaxExVlvDyn':
     *  1. SubSystem "F03_AdvMaxExVlvDyn" !Trace_To : VEMS_R_10_06439_015.01 ;
     */

    /* DataTypeConversion: '<S50>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_7, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion1_p = (UInt16)localtmp;
      } else {
        localDataTypeConversion1_p = 0U;
      }
    } else {
      localDataTypeConversion1_p = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S50>/Data Type Conversion1' */
    localDataTypeConversion = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S50>/Look-Up Table (2-D)'
     * About '<S50>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxDynExVlvMax),
      (&(IgSys_agIgMaxExVlvMax_M[0])), localDataTypeConversion1_p,
      (&(Eng_rAirLd_A[0])), 15U, localDataTypeConversion, (&(Ext_nEng_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S50>/Data Type Duplicate2'
     *
     * Regarding '<S50>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S51>/Data Type Conversion' */
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_7, 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion = (UInt16)localtmp;
      } else {
        localDataTypeConversion = 0U;
      }
    } else {
      localDataTypeConversion = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S51>/Data Type Conversion1' */
    localDataTypeConversion1_p = (UInt16)localDTConv_Single_To_UFix_1;

    /* Lookup2D: '<S51>/Look-Up Table (2-D)'
     * About '<S51>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-14
     * Input1  Data Type:  Integer        U16
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_U16_U16( &(IgSys_agIgMaxDynExVlvMin),
      (&(IgSys_agIgMaxExVlvMin_M[0])), localDataTypeConversion, (&(Eng_rAirLd_A
      [0])), 15U, localDataTypeConversion1_p, (&(Ext_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate2'
     *
     * Regarding '<S51>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S21>/F03_AdvMaxExVlvDyn' */

    /* Outputs for atomic SubSystem: '<S21>/F04_AdvKnkBasDyn' *
     * Block requirements for '<S21>/F04_AdvKnkBasDyn':
     *  1. SubSystem "F04_AdvKnkBasDyn" !Trace_To : VEMS_R_10_06439_016.01 ;
     */

    /* Product: '<S52>/Divide' incorporates:
     *  Sum: '<S46>/Sum'
     */
    IgSys_agIgDynInVlvMax_MP = (IgSys_agIgMaxDynInVlvMax -
      IgSys_agIgMaxVlvDynRef) * IgSys_rAdvMaxInVlv;

    /* Product: '<S55>/Divide' incorporates:
     *  Sum: '<S46>/Sum1'
     */
    IgSys_agIgDynInVlvMin_MP = (IgSys_agIgMaxDynInVlvMin -
      IgSys_agIgMaxVlvDynRef) * IgSys_rAdvMaxInVlv;

    /* Switch: '<S46>/Switch5' incorporates:
     *  Constant: '<S46>/Constant6'
     *  RelationalOperator: '<S46>/Relational Operator3'
     */
    if (IgSys_facAdvMaxInVlv >= 0.0F) {
      localDTConv_Single_To_UFix_2 = IgSys_agIgDynInVlvMax_MP;
    } else {
      localDTConv_Single_To_UFix_2 = IgSys_agIgDynInVlvMin_MP;
    }

    /* Product: '<S53>/Divide' incorporates:
     *  Sum: '<S46>/Sum3'
     */
    IgSys_agIgDynExVlvMax_MP = (IgSys_agIgMaxDynExVlvMax -
      IgSys_agIgMaxVlvDynRef) * IgSys_rAdvMaxExVlv;

    /* Product: '<S54>/Divide' incorporates:
     *  Sum: '<S46>/Sum4'
     */
    IgSys_agIgDynExVlvMin_MP = (IgSys_agIgMaxDynExVlvMin -
      IgSys_agIgMaxVlvDynRef) * IgSys_rAdvMaxExVlv;

    /* Switch: '<S46>/Switch1' incorporates:
     *  Constant: '<S46>/Constant1'
     *  RelationalOperator: '<S46>/Relational Operator1'
     */
    if (IgSys_facAdvMaxExVlv >= 0.0F) {
      localAbs = IgSys_agIgDynExVlvMax_MP;
    } else {
      localAbs = IgSys_agIgDynExVlvMin_MP;
    }

    /* Sum: '<S46>/Sum2' */
    IgSys_agIgKnkBasDyn = (IgSys_agIgMaxVlvDynRef + localDTConv_Single_To_UFix_2)
      + localAbs;

    /* end of Outputs for SubSystem: '<S21>/F04_AdvKnkBasDyn' */

    /* end of Outputs for SubSystem: '<S17>/F03_Degradation_knk_dyn' */

    /* end of Outputs for SubSystem: '<S11>/F01_AdvKnkBasStatDyn' */

    /* Outputs for atomic SubSystem: '<S11>/F02_CoordAdvMax' *
     * Block requirements for '<S11>/F02_CoordAdvMax':
     *  1. SubSystem "F02_CoordAdvMax" !Trace_To : VEMS_R_10_06439_017.01 ;
     */

    /* Outputs for atomic SubSystem: '<S18>/F01_AdvMaxWoutPrevAdpMv' *
     * Block requirements for '<S18>/F01_AdvMaxWoutPrevAdpMv':
     *  1. SubSystem "F01_AdvMaxWoutPrevAdpMv" !Trace_To : VEMS_R_10_06439_018.01 ;
     */

    /* Switch: '<S56>/Switch' incorporates:
     *  MinMax: '<S56>/MinMax'
     */
    if (localTmpSignalConversionAtIgS_l) {
      IgSys_agIgMaxWoutPrevAdpMv = rt_MINf(IgSys_agIgKnkBasDyn,
        IgSys_agIgKnkBasStat);
    } else {
      IgSys_agIgMaxWoutPrevAdpMv = IgSys_agIgKnkBasStat;
    }

    /* end of Outputs for SubSystem: '<S18>/F01_AdvMaxWoutPrevAdpMv' */

    /* Outputs for atomic SubSystem: '<S18>/F02_Correctifs' *
     * Block requirements for '<S18>/F02_Correctifs':
     *  1. SubSystem "F02_Correctifs" !Trace_To : VEMS_R_10_06439_019.01 ;
     */

    /* Selector: '<S57>/Selector1' incorporates:
     *  Constant: '<S57>/Constant'
     *  DataTypeConversion: '<S5>/DTConv_Single_To_UFix_10'
     */
    localDTConv_Single_To_UFix_2 = ((Float32)localTmpSignalConversionAtIgS_n[1])
      * 0.0078125F;

    /* Switch: '<S64>/Switch2' incorporates:
     *  RelationalOperator: '<S64>/LowerRelop1'
     */
    if (localDTConv_Single_To_UFix_2 > 1.0F) {
      localDTConv_Single_To_UFix_2 = 1.0F;
    }

    /* Sum: '<S57>/Sum3' incorporates:
     *  DataTypeConversion: '<S5>/DTConv_Single_To_UFix_8'
     */
    localAbs = ((((Float32)localTmpSignalConversionAtIgS_g) * 0.375F) - 36.0F)
      + IgSys_agIgMaxWoutPrevAdpMv;

    /* Switch: '<S57>/Switch1' incorporates:
     *  Constant: '<S57>/IgSys_bFlexMaxOfs_C'
     *  Sum: '<S57>/Sum'
     */
    if (!IgSys_bFlexMaxOfs_C) {
      localDTConv_Single_To_UFix_9 += IgSys_agIgMaxWoutPrevAdpMv;
    }

    /* Sum: '<S59>/Sum2' incorporates:
     *  Product: '<S59>/Divide'
     *  Sum: '<S59>/Sum3'
     */
    IgSys_agIgMaxWiFlexCor_MP = ((localDTConv_Single_To_UFix_9 - localAbs) *
      localDTConv_Single_To_UFix_2) + localAbs;

    /* Selector: '<S57>/Selector3' incorporates:
     *  Constant: '<S57>/Constant1'
     *  DataTypeConversion: '<S5>/DTConv_Single_To_UFix_11'
     */
    localDTConv_Single_To_UFix_9 = ((Float32)localTmpSignalConversionAtIg_ah[1])
      * 0.0078125F;

    /* Switch: '<S68>/Switch2' incorporates:
     *  RelationalOperator: '<S68>/LowerRelop1'
     */
    if (localDTConv_Single_To_UFix_9 > 1.0F) {
      localDTConv_Single_To_UFix_9 = 1.0F;
    }

    /* Switch: '<S57>/Switch3' incorporates:
     *  Constant: '<S57>/IgSys_bGasMaxOfs_C'
     *  Sum: '<S57>/Sum1'
     */
    if (IgSys_bGasMaxOfs_C) {
      localAbs = localDTConv_Single_To_UFix_12;
    } else {
      localAbs = localDTConv_Single_To_UFix_12 + IgSys_agIgMaxWiFlexCor_MP;
    }

    /* Sum: '<S60>/Sum2' incorporates:
     *  Product: '<S60>/Divide'
     *  Sum: '<S60>/Sum3'
     */
    IgSys_agIgMaxWiOfs = ((localAbs - IgSys_agIgMaxWiFlexCor_MP) *
                          localDTConv_Single_To_UFix_9) +
      IgSys_agIgMaxWiFlexCor_MP;

    /* end of Outputs for SubSystem: '<S18>/F02_Correctifs' */

    /* Outputs for atomic SubSystem: '<S18>/F03_Coordination_preventif_adaptatif' *
     * Block requirements for '<S18>/F03_Coordination_preventif_adaptatif':
     *  1. SubSystem "F03_Coordination_preventif_adaptatif" !Trace_To : VEMS_R_10_06439_020.01 ;
     */

    /* MultiPortSwitch: '<S58>/Multiport Switch' incorporates:
     *  Constant: '<S58>/Ext_noCylEng_SC'
     *  Constant: '<S58>/Ext_noCylEng_SC1'
     *  Constant: '<S58>/Ext_noCylEng_SC2'
     *  Constant: '<S58>/Ext_noCylEng_SC3'
     *  Constant: '<S58>/Ext_noCylEng_SC4'
     *  Constant: '<S58>/Ext_noCylEng_SC5'
     *  Constant: '<S58>/Ext_noCylEng_SC6'
     */
    switch (Ext_noCylEng_SC) {
     case 1:
      for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
           localDTConv_Single_To_UFix_1++) {
        localMultiportSwitch[localDTConv_Single_To_UFix_1] =
          AdvMaxT_ConstP.Ext_noCylEng_SC1_Valu[(localDTConv_Single_To_UFix_1)];
      }
      break;

     case 2:
      for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
           localDTConv_Single_To_UFix_1++) {
        localMultiportSwitch[localDTConv_Single_To_UFix_1] =
          AdvMaxT_ConstP.Ext_noCylEng_SC2_Valu[(localDTConv_Single_To_UFix_1)];
      }
      break;

     case 3:
      for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
           localDTConv_Single_To_UFix_1++) {
        localMultiportSwitch[localDTConv_Single_To_UFix_1] =
          AdvMaxT_ConstP.Ext_noCylEng_SC3_Valu[(localDTConv_Single_To_UFix_1)];
      }
      break;

     case 4:
      for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
           localDTConv_Single_To_UFix_1++) {
        localMultiportSwitch[localDTConv_Single_To_UFix_1] =
          AdvMaxT_ConstP.Ext_noCylEng_SC4_Valu[(localDTConv_Single_To_UFix_1)];
      }
      break;

     case 5:
      for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
           localDTConv_Single_To_UFix_1++) {
        localMultiportSwitch[localDTConv_Single_To_UFix_1] =
          AdvMaxT_ConstP.Ext_noCylEng_SC5_Valu[(localDTConv_Single_To_UFix_1)];
      }
      break;

     default:
      for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
           localDTConv_Single_To_UFix_1++) {
        localMultiportSwitch[localDTConv_Single_To_UFix_1] =
          AdvMaxT_ConstP.Ext_noCylEng_SC6_Valu[(localDTConv_Single_To_UFix_1)];
      }
      break;
    }

    /* Product: '<S70>/Divide' incorporates:
     *  DataTypeConversion: '<S5>/DTConv_Single_To_UFix_13'
     */
    for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
         localDTConv_Single_To_UFix_1++) {
      localDivide_f[localDTConv_Single_To_UFix_1] = ((((Float32)
        localTmpSignalConversionAtKnkMg[localDTConv_Single_To_UFix_1]) * 0.375F)
        - 36.0F) * ((Float32)localMultiportSwitch[localDTConv_Single_To_UFix_1]);
    }

    /* Product: '<S69>/Divide' incorporates:
     *  Constant: '<S58>/Ext_noCylEng_SC7'
     *  Sum: '<S58>/Sum1'
     */
    localDTConv_Single_To_UFix_2 = (((((localDivide_f[0] + localDivide_f[1]) +
      localDivide_f[2]) + localDivide_f[3]) + localDivide_f[4]) + localDivide_f
      [5]) / ((Float32)Ext_noCylEng_SC);

    /* SignalConversion: '<S58>/Signal Conversion' */
    AdvMaxT_B.Merge1 = localDTConv_Single_To_UFix_2;

    /* Sum: '<S58>/Sum2' incorporates:
     *  DataTypeConversion: '<S5>/DTConv_Single_To_UFix_3'
     */
    localAbs = ((((Float32)localTmpSignalConversionAtIgS_p) * 0.375F) - 36.0F)
      + IgSys_agIgMaxWiOfs;

    /* SignalConversion: '<S58>/Signal Conversion1' */
    AdvMaxT_B.Merge3 = localAbs;

    /* Sum: '<S58>/Sum3' incorporates:
     *  Product: '<S71>/Divide'
     */
    for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
         localDTConv_Single_To_UFix_1++) {
      AdvMaxT_B.Merge[(localDTConv_Single_To_UFix_1)] = (localAbs * ((Float32)
        localMultiportSwitch[localDTConv_Single_To_UFix_1])) -
        localDivide_f[localDTConv_Single_To_UFix_1];
    }

    /* Sum: '<S58>/Sum4' */
    AdvMaxT_B.Merge2 = localAbs - localDTConv_Single_To_UFix_2;

    /* end of Outputs for SubSystem: '<S18>/F03_Coordination_preventif_adaptatif' */

    /* end of Outputs for SubSystem: '<S11>/F02_CoordAdvMax' */
  }

  /* end of Outputs for SubSystem: '<S5>/F02_CalcAdvMax' */

  /* Logic: '<S5>/Logical Operator' */
  localTmpSignalConversionAtIgS_l = !IgSys_bAcvAdvMax;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevMv_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMaxWiPrevMv_INPUT'
   */
  Rte_Read_R_IgSys_agIgMaxWiPrevMv_IgSys_agIgMaxWiPrevMv
    (&localTmpSignalConversionAtIgS_f);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevAdpMv_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMaxWiPrevAdpMv_INPUT'
   */
  Rte_Read_R_IgSys_agIgMaxWiPrevAdpMv_IgSys_agIgMaxWiPrevAdpMv
    (&localTmpSignalConversionAtIg_o5);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgKnkAdpOfsMv_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgKnkAdpOfsMv_INPUT'
   */
  Rte_Read_R_IgSys_agIgKnkAdpOfsMv_IgSys_agIgKnkAdpOfsMv
    (&localTmpSignalConversionAtIgS_d);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_prm_agIgMaxWiPrevAdpCyl_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_agIgMaxWiPrevAdpCyl_INPUT'
   */
  Rte_Read_R_IgSys_prm_agIgMaxWiPrevAdpCyl_IgSys_prm_agIgMaxWiPrevAdpCyl
    (&localTmpSignalConversionAtIgS_a);

  /* Outputs for enable SubSystem: '<S5>/NOT' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (localTmpSignalConversionAtIgS_l) {
    /* DataTypeConversion: '<S12>/Data Type Conversion3' */
    for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
         localDTConv_Single_To_UFix_1++) {
      AdvMaxT_B.Merge[(localDTConv_Single_To_UFix_1)] = (((Float32)
        localTmpSignalConversionAtIgS_a[localDTConv_Single_To_UFix_1]) * 0.375F)
        - 36.0F;
    }

    /* DataTypeConversion: '<S12>/Data Type Conversion2' */
    AdvMaxT_B.Merge1 = (((Float32)localTmpSignalConversionAtIgS_d) * 0.375F) -
      36.0F;

    /* DataTypeConversion: '<S12>/Data Type Conversion1' */
    AdvMaxT_B.Merge2 = (((Float32)localTmpSignalConversionAtIg_o5) * 0.375F) -
      36.0F;

    /* DataTypeConversion: '<S12>/Data Type Conversion' */
    AdvMaxT_B.Merge3 = (((Float32)localTmpSignalConversionAtIgS_f) * 0.375F) -
      36.0F;
  }

  /* end of Outputs for SubSystem: '<S5>/NOT' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Byp_Fonction_SC'
   *  Constant: '<S15>/Int_BypC'
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   */
  if (ADVMAXT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_c = IgSys_agIgKnkAdpOfsMv_B;
  } else {
    localtmp = (((Float32d)AdvMaxT_B.Merge1) + 36.0F) / 0.375F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgS_c = (UInt8)localtmp;
      } else {
        localTmpSignalConversionAtIgS_c = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_c = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgKnkAdpOfsMvInport2' */
  Rte_Write_P_IgSys_agIgKnkAdpOfsMv_IgSys_agIgKnkAdpOfsMv
    (localTmpSignalConversionAtIgS_c);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Byp_Fonction_SC'
   *  Constant: '<S13>/Int_BypC'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  if (ADVMAXT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_c = IgSys_agIgMaxWiPrevAdpMv_B;
  } else {
    localtmp = (((Float32d)AdvMaxT_B.Merge2) + 36.0F) / 0.375F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgS_c = (UInt8)localtmp;
      } else {
        localTmpSignalConversionAtIgS_c = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_c = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevAdpMvInport2' */
  Rte_Write_P_IgSys_agIgMaxWiPrevAdpMv_IgSys_agIgMaxWiPrevAdpMv
    (localTmpSignalConversionAtIgS_c);

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Byp_Fonction_SC'
   *  Constant: '<S14>/Int_BypC'
   *  DataTypeConversion: '<S14>/Data Type Conversion'
   */
  if (ADVMAXT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_c = IgSys_agIgMaxWiPrevMv_B;
  } else {
    localtmp = (((Float32d)AdvMaxT_B.Merge3) + 36.0F) / 0.375F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgS_c = (UInt8)localtmp;
      } else {
        localTmpSignalConversionAtIgS_c = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_c = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevMvInport2' */
  Rte_Write_P_IgSys_agIgMaxWiPrevMv_IgSys_agIgMaxWiPrevMv
    (localTmpSignalConversionAtIgS_c);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Byp_Fonction_SC'
   *  Constant: '<S16>/Int_BypC'
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   */
  for (localDTConv_Single_To_UFix_1 = 0; localDTConv_Single_To_UFix_1 < 6;
       localDTConv_Single_To_UFix_1++) {
    if (ADVMAXT_ACTIVE_BYP_C) {
      localTmpSignalConversionAtKnkMg[localDTConv_Single_To_UFix_1] =
        IgSys_prm_agIgMaxWiPrevAdpCyl_B[(localDTConv_Single_To_UFix_1)];
    } else {
      localtmp = (((Float32d)AdvMaxT_B.Merge[(localDTConv_Single_To_UFix_1)]) +
                  36.0F) / 0.375F;
      if (localtmp < 256.0F) {
        if (localtmp >= 0.0F) {
          localTmpSignalConversionAtIgS_c = (UInt8)localtmp;
        } else {
          localTmpSignalConversionAtIgS_c = 0U;
        }
      } else {
        localTmpSignalConversionAtIgS_c = MAX_uint8_T;
      }

      localTmpSignalConversionAtKnkMg[localDTConv_Single_To_UFix_1] =
        localTmpSignalConversionAtIgS_c;
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_prm_agIgMaxWiPrevAdpCylInport2' */
  Rte_Write_P_IgSys_prm_agIgMaxWiPrevAdpCyl_IgSys_prm_agIgMaxWiPrevAdpCyl
    (&localTmpSignalConversionAtKnkMg);
}

/* Model initialize function */
void Runnable_AdvMax_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  RE_AdvMaxT_001_MSE_Start();
}

#define AdvMaxT_STOP_SEC_CODE
#include "AdvMaxT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
