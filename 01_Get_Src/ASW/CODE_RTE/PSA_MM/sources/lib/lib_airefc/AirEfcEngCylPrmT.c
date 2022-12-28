/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirEfcEngCylPrmT                                        */
/* !Description     : AirEfcEngCylPrmT Software Component                     */
/*                                                                            */
/* !Module          : AirEfcEngCylPrmT                                        */
/* !Description     : AirEfcEngCylPrmT Software Component                     */
/*                                                                            */
/* !File            : AirEfcEngCylPrmT.c                                      */
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
/*   Model name       : AirEfcEngCylPrmT_AUTOSAR.mdl                          */
/*   Root subsystem   : /AirEfcEngCylPrmT                                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M04-AirEfcEngCyl$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   19 Jun 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirEfcEngCylPrmT.h"
#include "AirEfcEngCylPrmT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AirEfcEngCylPrmT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirEfcEngCylPrmT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AirEfcEngCylPrmT AirEfcEngCylPrmT_B;

/* Block states (auto storage) */
D_Work_AirEfcEngCylPrmT AirEfcEngCylPrmT_DWork;

#define AirEfcEngCylPrmT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirEfcEngCylPrmT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define AIREFCENGCYLPRMT_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define AIREFCENGCYLPRMT_VEMSRTLIBT_MINOR_VERSION_REQ 21
#define AIREFCENGCYLPRMT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define AIREFCENGCYLPRMT_VEMSRTLIBT_VERSION_REQ (AIREFCENGCYLPRMT_VEMSRTLIBT_PATCH_VERSION_REQ + AIREFCENGCYLPRMT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + AIREFCENGCYLPRMT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if AIREFCENGCYLPRMT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AirEfcEngCylPrmT_START_SEC_CODE
#include "AirEfcEngCylPrmT_MemMap.h"

/* Output and update for atomic system: '<S5>/Subsystem' */
void Subsystem(UInt16 rtu_In_Ext_nEngRef, Float32
               rtu_In_EngM_agCkClsInVlvRef1, UInt16
               rtu_In_InM_tAirUsInVlvEstimRef, UInt16 rtu_In_InM_pDsThr,
               UInt8 rtu_In_EngM_noAcvMPVal, UInt16 rtu_In_InjSys_tFuRef,
               Float32 rtu_In_UsThrM_pAirExtEstimRef, UInt16
               rtu_In_InThM_nEngCorRef, Float32 rtu_In_EngM_agCkOpInVlvRef1,
               Float32 rtu_In_EngM_agCkClsExVlvRef1, Float32
               rtu_In_InM_pDsThrPred_facVlvOvl, Float32
               rtu_In_ExM_pExMnfEstimRef, Float32 rtu_In_ExM_tExMnfEstimRef,
               Float32 rtu_In_AirEfc_facChrExpFilPrev, Float32
               rtu_In_AirEfc_facChrExpScvFilPr, UInt16
               rtu_In_InjSys_rlamEngCorReqRef, SInt16 rtu_In_Ext_tCoMes,
               Float32 rtu_In_InjSys_agInj1BegRef, Float32
               rtu_In_InjSys_agInj1EndRef, Float32 rtu_In_InjSys_mFu1Inj,
               Float32 rtu_In_EngM_facCorOfsEfcRef, Float32
               rtu_In_EngM_facCorSlopEfcRef, Float32 *rty_Out_AirEfc_rMassBurn,
               Float32 *rty_Out_AirEfc_rMassAirResi, Float32
               *rty_Out_AirEfc_facChrExpScvFil, Float32
               *rty_Out_AirEfc_facMassAirScv, Float32 *rty_Out_AirEfc_agInj1End,
               Float32 *rty_Out_AirEfc_rFuMassInj1InPha, Float32
               *rty_Out_AirEfc_rDeltaLdInjPhaRe, Float32
               *rty_Out_AirEfc_facTAirUsInVlv, Float32 *rty_Out_AirEfc_facTCo,
               Float32 *rty_Out_AirEfc_facCorAtmSlopEfc, Float32
               *rty_Out_AirEfc_facCorBoostSlopE, Float32
               *rty_Out_AirEfc_pBegCorBoostSlop, Float32
               *rty_Out_AirEfc_facSlopEfc, Float32
               *rty_Out_AirEfc_pDeltaCorSlopEfc, Float32
               *rty_Out_AirEfc_facOfsEfc, Float32 *rty_Out_AirEfc_rMassAirScv,
               Float32 *rty_Out_AirEfc_pDsThrCorClsInVl, Float32
               *rty_Out_AirEfc_tBurnCyl, Float32
               *rty_Out_AirEfc_rVolCylClsInVlv, Float32
               *rty_Out_AirEfc_facMassFlowLd, Float32
               *rty_Out_AirEfc_facChrExpFil, rtB_Subsystem_AirEfcEngCylPrmT
               *localB, rtDW_Subsystem_AirEfcEngCylPrmT *localDW)
{
  /* local block i/o variables */
  UInt32 localLookUpTable;
  UInt16 locala21;
  UInt16 localSwitch_j;
  UInt16 localSwitch_h;
  UInt16 localDTConv_UFix_To_Single_1_pd;
  UInt16 localLookUpTable_j;
  UInt16 localLookUpTable_h;
  UInt16 localLookUpTable_b;
  UInt16 localAbs_k;
  UInt16 localOutDTConv_k;
  UInt16 localLookUpTable2D;
  UInt16 localLookUpTable2D_o;
  UInt16 localLookUpTable2D_b;
  UInt16 localOutDTConv_kw;
  UInt16 localLookUpTable_jf;
  SInt16 localOutDTConv_c;
  UInt16 localOutDTConv_e;
  UInt16 localOutDTConv_oi;
  UInt16 localLookUpTable_f;
  UInt16 localLookUpTable2D_m;
  UInt16 localLookUpTable_i;
  SInt16 localOutDTConv_dz;
  Float32 locala23;
  UInt16 locala25;
  UInt16 locala27;
  UInt16 locala39;
  Float32 localInterpolationUsingPreloo_b;
  Float32 localInterpolationUsingPrelooku;
  Float32 localInterpolationUsingPreloo_k;
  Float32 localInterpolationUsingPrelo_cw;
  Float32 localInterpolationUsingPreloo_c;
  Float32 localDTConv_UFix_To_Single_1_b;
  Float32 localDTConv_Single_To_UFix_16;
  Float32 localDivide_pl;
  Float32 localDTConv_UFix_To_Single_2;
  Float32 localDTConv_UFix_To_Single_5;
  Float32 localPrelookup_o2;
  Float32 localfractionTmp_0d;
  Float32 localfrac[2];
  Float32 localPrelookup_o2_a;
  SInt32 localPrelookup_o1;
  SInt32 localbpIndex[2];
  SInt32 localPrelookup_o1_o;
  Float32 localSum_o;
  Float32 localfrac_0[2];
  Float32 localPrelookup_o2_hl;
  SInt32 localbpIndex_0[2];
  Float32 localDivide_nd;
  Float32 localSum_ht;
  Float32 localSwitch;
  Float32 localPrelookup_o2_h;
  Float32 localfrac_1[2];
  Float32 localPrelookup_o2_j;
  SInt32 localPrelookup_o1_h;
  SInt32 localbpIndex_1[2];
  SInt32 localPrelookup_o1_c;
  Float32 localfrac_2[2];
  SInt32 localbpIndex_2[2];
  Float32 localfrac_3[2];
  SInt32 localbpIndex_3[2];
  Float32 localfrac_4[2];
  Float32 localPrelookup_o2_b;
  SInt32 localbpIndex_4[2];
  Boolean localRelationalOperator_l;
  Float32 localMerge1;
  Float32 localfrac_5[2];
  Float32 localPrelookup_o2_g;
  SInt32 localbpIndex_5[2];
  Float32 localSum_h;
  Float32 localmax;
  Float32 localInterpolationUsingPreloo_j;
  Float32 localSwitch2_o;
  Float32 localInterpolationUsingPreloo_l;
  Float32 localfrac_6[2];
  SInt32 localbpIndex_6[2];
  Float32 localDTConv_UFix_To_Single_12;
  Float32 localDTConv_UFix_To_Single_2_n;
  Float32 localDTConv_UFix_To_Single_1_pv;
  Float32 localMinMax_jq;
  Float32 localInterpolationUsingPreloo_h;
  Float32 localfrac_7[2];
  SInt32 localbpIndex_7[2];
  Float32 localInterpolationUsingPrelo_bu;
  Float32 localPrelookup_o2_k;
  Float32 localfrac_8[2];
  SInt32 localbpIndex_8[2];
  Float32 localPrelookup_o2_c;
  Float32 localfrac_9[2];
  SInt32 localbpIndex_9[2];
  SInt16 locallocalOutDTConv_o;
  UInt32 locallocalOutDTConv_l;
  UInt8 locallocalDTConv_UFix_To_Single;

  /* SignalConversion: '<S8>/a21' */
  locala21 = rtu_In_Ext_nEngRef;

  /* SignalConversion: '<S8>/a23' */
  locala23 = rtu_In_EngM_agCkClsInVlvRef1;

  /* SignalConversion: '<S8>/a25' */
  locala25 = rtu_In_InM_tAirUsInVlvEstimRef;

  /* SignalConversion: '<S8>/a27' */
  locala27 = rtu_In_InM_pDsThr;

  /* SignalConversion: '<S8>/a39' */
  locala39 = rtu_In_InjSys_tFuRef;

  /* Outputs for atomic SubSystem: '<S8>/LibAirEfc' *
   * Block requirements for '<S8>/LibAirEfc':
   *  1. SubSystem "LibAirEfc" !Trace_To : VEMS_R_11_00996_022.03 ;
   */

  /* DataStoreWrite: '<S9>/GT' incorporates:
   *  Constant: '<S9>/AcvMP_noEngMdl_C'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  SignalConversion: '<S8>/a35'
   */
  localDW->AcvMP_bEngMdl = (AcvMP_noEngMdl_C == rtu_In_EngM_noAcvMPVal);

  /* PreLookup: '<S11>/Prelookup' */
  localPrelookup_o1 = plook_s32u16f_bincpa(locala21, (&(AirEfc_nEngY_A[0])), 17U,
    &localPrelookup_o2, &localDW->Prelookup_DWORK1);

  /* PreLookup: '<S12>/Prelookup' */
  localPrelookup_o1_o = plook_s32u16f_bincpa(locala25, (&(AirEfc_tAirUsInVlv_A[0])),
    15U, &localPrelookup_o2_a, &localDW->Prelookup_DWORK1_m);

  /* DataTypeConversion: '<S9>/DTConv_UFix_To_Single_2' incorporates:
   *  Constant: '<S9>/AirEfc_pRef_C'
   */
  localDTConv_UFix_To_Single_2 = ((Float32)AirEfc_pRef_C) * 8.0F;

  /* DataTypeConversion: '<S9>/DTConv_UFix_To_Single_5' */
  localDTConv_UFix_To_Single_5 = ((Float32)locala27) * 8.0F;

  /* Outputs for atomic SubSystem: '<S9>/F01_fresh_gas_temperature' *
   * Block requirements for '<S9>/F01_fresh_gas_temperature':
   *  1. SubSystem "F01_fresh_gas_temperature" !Trace_To : VEMS_R_11_00996_023.02 ;
   */

  /* Interpolation_n-D: '<S26>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2;
  localfrac[0] = localfractionTmp_0d;
  localfractionTmp_0d = localPrelookup_o2_a;
  localfrac[1] = localfractionTmp_0d;
  localbpIndex[0] = localPrelookup_o1;
  localbpIndex[1] = localPrelookup_o1_o;
  localInterpolationUsingPreloo_b = intrp2d_iu16n15ff_s32f_la_ns(localbpIndex,
    localfrac, (&(AirEfc_facTAirUsInVlv_M[0])), 18U,
    &AirEfcEngCylPrmT_ConstP.pooled11[0]);

  /* If: '<S27>/If' incorporates:
   *  ActionPort: '<S28>/Action Port'
   *  DataStoreRead: '<S27>/GT'
   *  SubSystem: '<S27>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S28>/MP' */
    AirEfc_facTAirUsInVlv_MP = localInterpolationUsingPreloo_b;
  }

  /* end of Outputs for SubSystem: '<S9>/F01_fresh_gas_temperature' */

  /* Outputs for atomic SubSystem: '<S9>/F02_cylinder_volume_at_close_intake_valve' *
   * Block requirements for '<S9>/F02_cylinder_volume_at_close_intake_valve':
   *  1. SubSystem "F02_cylinder_volume_at_close_intake_valve" !Trace_To : VEMS_R_11_00996_024.01 ;
   */

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/ConstVal'
   *  Constant: '<S14>/ConstVal_2'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  Sum: '<S14>/Sum'
   */
  if (locala23 > 180.0F) {
    localfractionTmp_0d = locala23 - 360.0F;
  } else {
    localfractionTmp_0d = locala23;
  }

  /* Abs: '<S14>/Abs' */
  localfractionTmp_0d = ACTEMS_FabsF(localfractionTmp_0d);

  /* If: '<S29>/If' incorporates:
   *  ActionPort: '<S32>/Action Port'
   *  DataStoreRead: '<S29>/GT'
   *  SubSystem: '<S29>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S32>/MP' */
    AirEfc_agCk_facTDC_MP = localfractionTmp_0d;
  }

  /* DataTypeConversion: '<S31>/OutDTConv' incorporates:
   *  Constant: '<S31>/offset'
   *  Constant: '<S31>/one_on_slope'
   *  Product: '<S31>/Product4'
   *  Sum: '<S31>/Add1'
   */
  localfractionTmp_0d *= 1.066666698E+001F;
  if (localfractionTmp_0d < 65536.0F) {
    localOutDTConv_k = (UInt16)localfractionTmp_0d;
  } else {
    localOutDTConv_k = MAX_uint16_T;
  }

  /* Lookup: '<S30>/Look-Up Table'
   * About '<S30>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
   * Output0 Data Type:  Fixed Point    U16  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_b), (&(AirEfc_rVolCyl_T[0])),
                 localOutDTConv_k, (&(AirEfc_agCk_facTDC_A[0])), 19U);

  /* DataTypeDuplicate Block: '<S30>/Data Type Duplicate1'
   *
   * Regarding '<S30>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S14>/DTConv_Single_To_UFix_16' incorporates:
   *  Lookup: '<S30>/Look-Up Table'
   */
  localDTConv_Single_To_UFix_16 = ((Float32)localLookUpTable_b) *
    3.051757813E-005F;

  /* end of Outputs for SubSystem: '<S9>/F02_cylinder_volume_at_close_intake_valve' */

  /* Outputs for atomic SubSystem: '<S9>/F03_Slop_correction' *
   * Block requirements for '<S9>/F03_Slop_correction':
   *  1. SubSystem "F03_Slop_correction" !Trace_To : VEMS_R_11_00996_025.03 ;
   */

  /* DataTypeConversion: '<S40>/OutDTConv' incorporates:
   *  Constant: '<S40>/offset'
   *  Constant: '<S40>/one_on_slope'
   *  Product: '<S40>/Product4'
   *  Sum: '<S40>/Add1'
   */
  localfractionTmp_0d = 1.066666698E+001F * locala23;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      locala27 = (UInt16)localfractionTmp_0d;
    } else {
      locala27 = 0U;
    }
  } else {
    locala27 = MAX_uint16_T;
  }

  /* PreLookup: '<S33>/Prelookup' */
  localPrelookup_o1_c = plook_s32u16f_bincpa(locala27,
    (&(AirEfc_agCkClsInVlvX_A[0])), 12U, &localPrelookup_o2_j,
    &localDW->Prelookup_DWORK1_gu);

  /* Outputs for atomic SubSystem: '<S15>/F05_Engine_speed_choice' *
   * Block requirements for '<S15>/F05_Engine_speed_choice':
   *  1. SubSystem "F05_Engine_speed_choice" !Trace_To : VEMS_R_11_00996_166.01 ;
   */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/AirEfc_bAcvEngSpdCorSlop_C'
   */
  if (AirEfc_bAcvEngSpdCorSlop_C) {
    localSwitch_h = rtu_In_InThM_nEngCorRef;
  } else {
    localSwitch_h = locala21;
  }

  /* If: '<S68>/If' incorporates:
   *  ActionPort: '<S70>/Action Port'
   *  DataStoreRead: '<S68>/GT'
   *  SubSystem: '<S68>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S70>/MP' */
    AirEfc_nEngSlop_MP = localSwitch_h;
  }

  /* PreLookup: '<S69>/Prelookup' */
  localPrelookup_o1_h = plook_s32u16f_bincpa(localSwitch_h, (&(AirEfc_nEngY_A[0])),
    17U, &localPrelookup_o2_h, &localDW->Prelookup_DWORK1_a);

  /* end of Outputs for SubSystem: '<S15>/F05_Engine_speed_choice' */

  /* Outputs for atomic SubSystem: '<S15>/F01_Atmospheric_slop_correction' *
   * Block requirements for '<S15>/F01_Atmospheric_slop_correction':
   *  1. SubSystem "F01_Atmospheric_slop_correction" !Trace_To : VEMS_R_11_00996_026.02 ;
   */

  /* Interpolation_n-D: '<S42>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2_h;
  localfrac_1[0] = localfractionTmp_0d;
  localfractionTmp_0d = localPrelookup_o2_j;
  localfrac_1[1] = localfractionTmp_0d;
  localbpIndex_1[0] = localPrelookup_o1_h;
  localbpIndex_1[1] = localPrelookup_o1_c;
  localInterpolationUsingPreloo_k = intrp2d_iu16n15ff_s32f_la_ns(localbpIndex_1,
    localfrac_1, (&(AirEfc_facCorAtmSlopEfc_M[0])), 18U,
    &AirEfcEngCylPrmT_ConstP.pooled12[0]);

  /* If: '<S43>/If' incorporates:
   *  ActionPort: '<S44>/Action Port'
   *  DataStoreRead: '<S43>/GT'
   *  SubSystem: '<S43>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S44>/MP' */
    AirEfc_facCorAtmSlopEfc_MP = localInterpolationUsingPreloo_k;
  }

  /* end of Outputs for SubSystem: '<S15>/F01_Atmospheric_slop_correction' */

  /* Outputs for atomic SubSystem: '<S15>/F02_Boost_slop_correction' *
   * Block requirements for '<S15>/F02_Boost_slop_correction':
   *  1. SubSystem "F02_Boost_slop_correction" !Trace_To : VEMS_R_11_00996_027.02 ;
   */

  /* Interpolation_n-D: '<S45>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2_h;
  localfrac_2[0] = localfractionTmp_0d;
  localfractionTmp_0d = localPrelookup_o2_j;
  localfrac_2[1] = localfractionTmp_0d;
  localbpIndex_2[0] = localPrelookup_o1_h;
  localbpIndex_2[1] = localPrelookup_o1_c;
  localInterpolationUsingPrelo_cw = intrp2d_iu16n15ff_s32f_la_ns(localbpIndex_2,
    localfrac_2, (&(AirEfc_facCorBoostSlopEfc_M[0])), 18U,
    &AirEfcEngCylPrmT_ConstP.pooled12[0]);

  /* If: '<S46>/If' incorporates:
   *  ActionPort: '<S47>/Action Port'
   *  DataStoreRead: '<S46>/GT'
   *  SubSystem: '<S46>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S47>/MP' */
    AirEfc_facCorBoostSlopEfc_MP = localInterpolationUsingPrelo_cw;
  }

  /* end of Outputs for SubSystem: '<S15>/F02_Boost_slop_correction' */

  /* Outputs for atomic SubSystem: '<S15>/F03_Coefficient_atmospheric_to_boost_slop_correction' *
   * Block requirements for '<S15>/F03_Coefficient_atmospheric_to_boost_slop_correction':
   *  1. SubSystem "F03_Coefficient_atmospheric_to_boost_slop_correction" !Trace_To : VEMS_R_11_00996_028.03 ;
   */

  /* Interpolation_n-D: '<S52>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2_h;
  localfrac_3[0] = localfractionTmp_0d;
  localfractionTmp_0d = localPrelookup_o2_j;
  localfrac_3[1] = localfractionTmp_0d;
  localbpIndex_3[0] = localPrelookup_o1_h;
  localbpIndex_3[1] = localPrelookup_o1_c;
  localInterpolationUsingPreloo_c = intrp2d_iu16p3ff_s32f_la_s(localbpIndex_3,
    localfrac_3, (&(AirEfc_pBegCorBoostSlopEfc_M[0])), 18U,
    &AirEfcEngCylPrmT_ConstP.pooled12[0]);

  /* Product: '<S56>/Divide' */
  localfractionTmp_0d = rtu_In_UsThrM_pAirExtEstimRef /
    localDTConv_UFix_To_Single_2;

  /* Outputs for atomic SubSystem: '<S56>/If Action Subsystem3' */

  /* Switch: '<S65>/Switch1' incorporates:
   *  Constant: '<S65>/Constant1'
   *  Constant: '<S65>/Constant2'
   *  Constant: '<S65>/Constant3'
   *  Logic: '<S65>/Logical Operator1'
   *  RelationalOperator: '<S65>/Relational Operator'
   *  RelationalOperator: '<S65>/Relational Operator1'
   *  RelationalOperator: '<S65>/Relational Operator3'
   */
  if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
        3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
    localfractionTmp_0d = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S56>/If Action Subsystem3' */

  /* Lookup: '<S53>/Look-Up Table'
   * About '<S53>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^3
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_j), (&(AirEfc_pDeltaCorSlopEfc_T[0])),
                 localSwitch_h, (&(AirEfc_nDeltaCorSlopEfc_A[0])), 17U);

  /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate1'
   *
   * Regarding '<S53>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S37>/DTConv_UFix_To_Single_1' incorporates:
   *  Lookup: '<S53>/Look-Up Table'
   */
  localDTConv_UFix_To_Single_1_b = ((Float32)localLookUpTable_j) * 8.0F;

  /* Product: '<S55>/Divide' incorporates:
   *  Product: '<S57>/Divide'
   *  Product: '<S58>/Divide'
   *  Sum: '<S37>/Sum'
   */
  localfractionTmp_0d = (localDTConv_UFix_To_Single_5 -
    (localInterpolationUsingPreloo_c * localfractionTmp_0d)) /
    (localfractionTmp_0d * localDTConv_UFix_To_Single_1_b);

  /* Outputs for atomic SubSystem: '<S55>/If Action Subsystem3' */

  /* Switch: '<S63>/Switch1' incorporates:
   *  Constant: '<S63>/Constant1'
   *  Constant: '<S63>/Constant2'
   *  Constant: '<S63>/Constant3'
   *  Logic: '<S63>/Logical Operator1'
   *  RelationalOperator: '<S63>/Relational Operator'
   *  RelationalOperator: '<S63>/Relational Operator1'
   *  RelationalOperator: '<S63>/Relational Operator3'
   */
  if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
        3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
    localfractionTmp_0d = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S55>/If Action Subsystem3' */

  /* If: '<S48>/If' incorporates:
   *  ActionPort: '<S59>/Action Port'
   *  DataStoreRead: '<S48>/GT'
   *  SubSystem: '<S48>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S59>/MP' */
    AirEfc_facChgCorSlopEfcMax_MP = localfractionTmp_0d;
  }

  /* MinMax: '<S37>/MinMax1' incorporates:
   *  Constant: '<S37>/ConstVal'
   */
  localfractionTmp_0d = rt_MAXf(localfractionTmp_0d, 0.0F);

  /* MinMax: '<S37>/MinMax' incorporates:
   *  Constant: '<S37>/ConstVal_2'
   */
  localfractionTmp_0d = rt_MINf(localfractionTmp_0d, 1.0F);

  /* If: '<S49>/If' incorporates:
   *  ActionPort: '<S60>/Action Port'
   *  DataStoreRead: '<S49>/GT'
   *  SubSystem: '<S49>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S60>/MP' */
    AirEfc_facChgCorSlopEfcMin_MP = localfractionTmp_0d;
  }

  /* DataTypeConversion: '<S54>/OutDTConv' incorporates:
   *  Constant: '<S54>/offset'
   *  Constant: '<S54>/one_on_slope'
   *  Product: '<S54>/Product4'
   *  Sum: '<S54>/Add1'
   */
  localfractionTmp_0d *= 65536.0F;
  if (localfractionTmp_0d < 65536.0F) {
    localOutDTConv_kw = (UInt16)localfractionTmp_0d;
  } else {
    localOutDTConv_kw = MAX_uint16_T;
  }

  /* Lookup: '<S51>/Look-Up Table'
   * About '<S51>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_jf), (&(AirEfc_facChgCorSlopEfc_T[0])),
                 localOutDTConv_kw, (&(AirEfc_facChgCorSlopEfc_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate1'
   *
   * Regarding '<S51>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S37>/DTConv_UFix_To_Single_12' incorporates:
   *  Lookup: '<S51>/Look-Up Table'
   */
  localfractionTmp_0d = ((Float32)localLookUpTable_jf) * 1.525878906E-005F;

  /* If: '<S50>/If' incorporates:
   *  ActionPort: '<S61>/Action Port'
   *  DataStoreRead: '<S50>/GT'
   *  SubSystem: '<S50>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S61>/MP' */
    AirEfc_facChgCorSlopEfc_MP = localfractionTmp_0d;
  }

  /* end of Outputs for SubSystem: '<S15>/F03_Coefficient_atmospheric_to_boost_slop_correction' */

  /* Outputs for atomic SubSystem: '<S15>/F04_Slop_correction_calculation' *
   * Block requirements for '<S15>/F04_Slop_correction_calculation':
   *  1. SubSystem "F04_Slop_correction_calculation" !Trace_To : VEMS_R_11_00996_029.01 ;
   */

  /* Sum: '<S38>/Sum' incorporates:
   *  Product: '<S66>/Divide'
   *  Product: '<S67>/Divide'
   *  Sum: '<S38>/Sum1'
   */
  localSum_o = (((localInterpolationUsingPreloo_k *
                  localInterpolationUsingPrelo_cw) -
                 localInterpolationUsingPreloo_k) * localfractionTmp_0d) +
    localInterpolationUsingPreloo_k;

  /* end of Outputs for SubSystem: '<S15>/F04_Slop_correction_calculation' */

  /* If: '<S34>/If' incorporates:
   *  ActionPort: '<S41>/Action Port'
   *  DataStoreRead: '<S34>/GT'
   *  SubSystem: '<S34>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S41>/MP' */
    AirEfc_facCorSlopEfc_MP = localSum_o;
  }

  /* end of Outputs for SubSystem: '<S9>/F03_Slop_correction' */

  /* Outputs for atomic SubSystem: '<S9>/F11_Water_correction_temperature' *
   * Block requirements for '<S9>/F11_Water_correction_temperature':
   *  1. SubSystem "F11_Water_correction_temperature" !Trace_To : VEMS_R_11_00996_057.01 ;
   */

  /* DataTypeConversion: '<S23>/DTConv_UFix_To_Single_1' */
  localPrelookup_o1_c = rtu_In_Ext_tCoMes + 40;
  if (localPrelookup_o1_c <= 0) {
    locallocalDTConv_UFix_To_Single = 0U;
  } else if (localPrelookup_o1_c > 255) {
    locallocalDTConv_UFix_To_Single = MAX_uint8_T;
  } else {
    locallocalDTConv_UFix_To_Single = (UInt8)localPrelookup_o1_c;
  }

  /* PreLookup: '<S273>/Prelookup' */
  localPrelookup_o1_c = plook_s32u8f_bincpa(locallocalDTConv_UFix_To_Single,
    (&(AirEfc_tCoX_A[0])), 9U, &localPrelookup_o2_hl,
    &localDW->Prelookup_DWORK1_i);

  /* Interpolation_n-D: '<S271>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2;
  localfrac_0[0] = localfractionTmp_0d;
  localfractionTmp_0d = localPrelookup_o2_hl;
  localfrac_0[1] = localfractionTmp_0d;
  localbpIndex_0[0] = localPrelookup_o1;
  localbpIndex_0[1] = localPrelookup_o1_c;
  localInterpolationUsingPrelooku = intrp2d_iu16n7ff_s32f_la_ns(localbpIndex_0,
    localfrac_0, (&(AirEfc_facTCo_M[0])), 18U,
    &AirEfcEngCylPrmT_ConstP.InterpolationUsingP_p[0]);

  /* If: '<S272>/If' incorporates:
   *  ActionPort: '<S274>/Action Port'
   *  DataStoreRead: '<S272>/GT'
   *  SubSystem: '<S272>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S274>/MP' */
    AirEfc_facTCo_MP = localInterpolationUsingPrelooku;
  }

  /* end of Outputs for SubSystem: '<S9>/F11_Water_correction_temperature' */

  /* Outputs for atomic SubSystem: '<S9>/F13_Alternative_Fuel_Correction_Activation' *
   * Block requirements for '<S9>/F13_Alternative_Fuel_Correction_Activation':
   *  1. SubSystem "F13_Alternative_Fuel_Correction_Activation" !Trace_To : VEMS_R_11_00996_067.01 ;
   */

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/AirEfc_bAcvAirLdCor_C'
   *  Constant: '<S25>/ConstVal_2'
   */
  if (AirEfc_bAcvAirLdCor_C) {
    localSwitch = rtu_In_EngM_facCorOfsEfcRef;
  } else {
    localSwitch = 0.0F;
  }

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/AirEfc_bAcvAirLdCor_C'
   *  Constant: '<S25>/ConstVal'
   */
  if (AirEfc_bAcvAirLdCor_C) {
    localfractionTmp_0d = rtu_In_EngM_facCorSlopEfcRef;
  } else {
    localfractionTmp_0d = 1.0F;
  }

  /* end of Outputs for SubSystem: '<S9>/F13_Alternative_Fuel_Correction_Activation' */

  /* Outputs for atomic SubSystem: '<S9>/F05_Slop_air_load' *
   * Block requirements for '<S9>/F05_Slop_air_load':
   *  1. SubSystem "F05_Slop_air_load" !Trace_To : VEMS_R_11_00996_031.01 ;
   */

  /* Product: '<S72>/Divide' incorporates:
   *  Product: '<S73>/Divide'
   *  Product: '<S74>/Divide'
   *  Product: '<S75>/Divide'
   *  Product: '<S76>/Divide'
   */
  localDivide_nd = ((((localDTConv_Single_To_UFix_16 * localSum_o) *
                      localInterpolationUsingPreloo_b) *
                     localInterpolationUsingPrelooku) * localfractionTmp_0d) /
    localDTConv_UFix_To_Single_2;

  /* Outputs for atomic SubSystem: '<S72>/If Action Subsystem3' */

  /* Switch: '<S78>/Switch1' incorporates:
   *  Constant: '<S78>/Constant1'
   *  Constant: '<S78>/Constant2'
   *  Constant: '<S78>/Constant3'
   *  Logic: '<S78>/Logical Operator1'
   *  RelationalOperator: '<S78>/Relational Operator'
   *  RelationalOperator: '<S78>/Relational Operator1'
   *  RelationalOperator: '<S78>/Relational Operator3'
   */
  if (((localDivide_nd != localDivide_nd) || (localDivide_nd > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_nd)) {
    localDivide_nd = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S72>/If Action Subsystem3' */

  /* end of Outputs for SubSystem: '<S9>/F05_Slop_air_load' */

  /* Outputs for atomic SubSystem: '<S9>/F06_Specific_VVT_angle' *
   * Block requirements for '<S9>/F06_Specific_VVT_angle':
   *  1. SubSystem "F06_Specific_VVT_angle" !Trace_To : VEMS_R_11_00996_032.01 ;
   */

  /* DataTypeConversion: '<S81>/OutDTConv' incorporates:
   *  Constant: '<S18>/ConstVal'
   *  Constant: '<S81>/offset'
   *  Constant: '<S81>/one_on_slope'
   *  Product: '<S81>/Product4'
   *  Product: '<S82>/Divide'
   *  Sum: '<S18>/Sum1'
   *  Sum: '<S81>/Add1'
   */
  localfractionTmp_0d = ((rtu_In_EngM_agCkOpInVlvRef1 +
    rtu_In_EngM_agCkClsExVlvRef1) / 2.0F) * 1.066666698E+001F;
  if (localfractionTmp_0d < 32768.0F) {
    if (localfractionTmp_0d >= -32768.0F) {
      locallocalOutDTConv_o = (SInt16)localfractionTmp_0d;
    } else {
      locallocalOutDTConv_o = MIN_int16_T;
    }
  } else {
    locallocalOutDTConv_o = MAX_int16_T;
  }

  /* If: '<S79>/If' incorporates:
   *  ActionPort: '<S83>/Action Port'
   *  DataStoreRead: '<S79>/GT'
   *  SubSystem: '<S79>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S83>/MP' */
    AirEfc_agCkPosnVlvOvlp_MP = locallocalOutDTConv_o;
  }

  /* Sum: '<S18>/Sum' */
  localSum_ht = rtu_In_EngM_agCkClsExVlvRef1 - rtu_In_EngM_agCkOpInVlvRef1;

  /* If: '<S80>/If' incorporates:
   *  ActionPort: '<S84>/Action Port'
   *  DataStoreRead: '<S80>/GT'
   *  SubSystem: '<S80>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S84>/MP' */
    AirEfc_agCkVlvOvlp_MP = localSum_ht;
  }

  /* end of Outputs for SubSystem: '<S9>/F06_Specific_VVT_angle' */

  /* Outputs for atomic SubSystem: '<S9>/F07_Residual_scavenged_reaspired_mass' *
   * Block requirements for '<S9>/F07_Residual_scavenged_reaspired_mass':
   *  1. SubSystem "F07_Residual_scavenged_reaspired_mass" !Trace_To : VEMS_R_11_00996_033.02 ;
   */

  /* Outputs for atomic SubSystem: '<S19>/F01_Correction_reaspired_scavenged_massflow' *
   * Block requirements for '<S19>/F01_Correction_reaspired_scavenged_massflow':
   *  1. SubSystem "F01_Correction_reaspired_scavenged_massflow" !Trace_To : VEMS_R_11_00996_034.01 ;
   */

  /* PreLookup: '<S101>/Prelookup' */
  localPrelookup_o1_c = plook_s32s16f_bincpa(locallocalOutDTConv_o,
    (&(AirEfc_agCkPosnVlvOvlpX_A[0])), 12U, &localPrelookup_o2_b,
    &localDW->Prelookup_DWORK1_e);

  /* Interpolation_n-D: '<S102>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2;
  localfrac_4[0] = localfractionTmp_0d;
  localfractionTmp_0d = localPrelookup_o2_b;
  localfrac_4[1] = localfractionTmp_0d;
  localbpIndex_4[0] = localPrelookup_o1;
  localbpIndex_4[1] = localPrelookup_o1_c;
  localInterpolationUsingPreloo_j = intrp2d_iu16n17ff_s32f_la_ns(localbpIndex_4,
    localfrac_4, (&(AirEfc_facMassFlowCor_M[0])), 18U,
    &AirEfcEngCylPrmT_ConstP.pooled12[0]);

  /* If: '<S103>/If' incorporates:
   *  ActionPort: '<S104>/Action Port'
   *  DataStoreRead: '<S103>/GT'
   *  SubSystem: '<S103>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S104>/MP' */
    AirEfc_facMassFlowCor_MP = localInterpolationUsingPreloo_j;
  }

  /* end of Outputs for SubSystem: '<S19>/F01_Correction_reaspired_scavenged_massflow' */

  /* Outputs for atomic SubSystem: '<S19>/F02_Coefficient_massflow_to_load' *
   * Block requirements for '<S19>/F02_Coefficient_massflow_to_load':
   *  1. SubSystem "F02_Coefficient_massflow_to_load" !Trace_To : VEMS_R_11_00996_035.01 ;
   */

  /* Product: '<S107>/Divide' incorporates:
   *  Constant: '<S88>/AirEfc_densAir_C'
   *  Constant: '<S88>/AirEfc_noCylEng_C'
   *  Constant: '<S88>/AirEfc_volRef_C'
   *  Constant: '<S88>/ConstVal'
   *  Constant: '<S88>/ConstVal_2'
   *  DataTypeConversion: '<S88>/DTConv_UFix_To_Single_1'
   *  DataTypeConversion: '<S88>/DTConv_UFix_To_Single_2'
   *  DataTypeConversion: '<S88>/DTConv_UFix_To_Single_3'
   *  DataTypeConversion: '<S88>/DTConv_UFix_To_Single_4'
   *  Product: '<S105>/Divide'
   *  Product: '<S106>/Divide'
   *  Product: '<S108>/Divide'
   *  Product: '<S109>/Divide'
   */
  localDivide_pl = (((((Float32)AirEfc_volRef_C) * 7.629394894E-009F) *
                     (((Float32)AirEfc_noCylEng_C) / 2.0F)) * (((Float32)
    AirEfc_densAir_C) * 1.525878906E-005F)) * (((Float32)locala21) / 60.0F);

  /* end of Outputs for SubSystem: '<S19>/F02_Coefficient_massflow_to_load' */

  /* DataTypeConversion: '<S98>/OutDTConv' incorporates:
   *  Constant: '<S98>/offset'
   *  Constant: '<S98>/one_on_slope'
   *  Product: '<S98>/Product4'
   *  Sum: '<S98>/Add1'
   */
  localfractionTmp_0d = 1.066666698E+001F * localSum_ht;
  if (localfractionTmp_0d < 32768.0F) {
    if (localfractionTmp_0d >= -32768.0F) {
      localOutDTConv_c = (SInt16)localfractionTmp_0d;
    } else {
      localOutDTConv_c = MIN_int16_T;
    }
  } else {
    localOutDTConv_c = MAX_int16_T;
  }

  /* Outputs for atomic SubSystem: '<S19>/F03_Reaspired_burn_mass' *
   * Block requirements for '<S19>/F03_Reaspired_burn_mass':
   *  1. SubSystem "F03_Reaspired_burn_mass" !Trace_To : VEMS_R_11_00996_036.01 ;
   */

  /* Outputs for enable SubSystem: '<S89>/F01_Reaspired_burn_mass' incorporates:
   *  Constant: '<S89>/AirEfc_nEngThdVal_C'
   *  EnablePort: '<S111>/Enable'
   *  EnablePort: '<S112>/Enable'
   *  Logic: '<S89>/Logical Operator'
   *  RelationalOperator: '<S89>/Relational Operator'
   *  SubSystem: '<S89>/F02_Reaspired_burn_mass_init'
   *
   * Block requirements for '<S89>/F01_Reaspired_burn_mass':
   *  1. SubSystem "F01_Reaspired_burn_mass" !Trace_To : VEMS_R_11_00996_037.01 ;
   *
   * Block requirements for '<S89>/F02_Reaspired_burn_mass_init':
   *  1. SubSystem "F02_Reaspired_burn_mass_init" !Trace_To : VEMS_R_11_00996_038.01 ;
   */
  if (locala21 >= AirEfc_nEngThdVal_C) {
    /* Product: '<S129>/Divide' */
    localfractionTmp_0d = rtu_In_InM_pDsThrPred_facVlvOvl /
      rtu_In_ExM_pExMnfEstimRef;

    /* Outputs for atomic SubSystem: '<S129>/If Action Subsystem3' */

    /* Switch: '<S148>/Switch1' incorporates:
     *  Constant: '<S148>/Constant1'
     *  Constant: '<S148>/Constant2'
     *  Constant: '<S148>/Constant3'
     *  Logic: '<S148>/Logical Operator1'
     *  RelationalOperator: '<S148>/Relational Operator'
     *  RelationalOperator: '<S148>/Relational Operator1'
     *  RelationalOperator: '<S148>/Relational Operator3'
     */
    if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
          3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
      localfractionTmp_0d = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S129>/If Action Subsystem3' */

    /* Switch: '<S143>/Switch' incorporates:
     *  Constant: '<S111>/ConstVal'
     *  RelationalOperator: '<S143>/UpperRelop'
     */
    if (localfractionTmp_0d < 0.0F) {
      localInterpolationUsingPreloo_l = 0.0F;
    } else {
      localInterpolationUsingPreloo_l = localfractionTmp_0d;
    }

    /* Switch: '<S143>/Switch2' incorporates:
     *  Constant: '<S111>/ConstVal_1'
     *  RelationalOperator: '<S143>/LowerRelop1'
     */
    if (localfractionTmp_0d > 1.0F) {
      localSwitch2_o = 1.0F;
    } else {
      localSwitch2_o = localInterpolationUsingPreloo_l;
    }

    /* Product: '<S127>/Product4' incorporates:
     *  Constant: '<S127>/offset'
     *  Constant: '<S127>/one_on_slope'
     *  Sum: '<S127>/Add1'
     */
    localInterpolationUsingPreloo_l = 65536.0F * localSwitch2_o;

    /* DataTypeConversion: '<S127>/OutDTConv' */
    localfractionTmp_0d = localInterpolationUsingPreloo_l;
    if (localfractionTmp_0d < 4.294967296E+009F) {
      if (localfractionTmp_0d >= 0.0F) {
        locallocalOutDTConv_l = (UInt32)localfractionTmp_0d;
      } else {
        locallocalOutDTConv_l = 0U;
      }
    } else {
      locallocalOutDTConv_l = MAX_uint32_T;
    }

    /* PreLookup: '<S122>/Prelookup' */
    localPrelookup_o1_c = plook_s32u32f_bincpa(locallocalOutDTConv_l,
      (&(AirEfc_rPresEngX_A[0])), 10U, &localInterpolationUsingPreloo_l,
      &localDW->Prelookup_DWORK1_c);

    /* Interpolation_n-D: '<S114>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_l;
    localMinMax_jq = intrp1d_iu16n16ff_s32f_la_ns(localPrelookup_o1_c,
      localfractionTmp_0d, (&(AirEfc_facChrExp_T[0])), 10U);

    /* Interpolation_n-D: '<S115>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2;
    localfrac_6[0] = localfractionTmp_0d;
    localfractionTmp_0d = localInterpolationUsingPreloo_l;
    localfrac_6[1] = localfractionTmp_0d;
    localbpIndex_6[0] = localPrelookup_o1;
    localbpIndex_6[1] = localPrelookup_o1_c;
    localInterpolationUsingPreloo_l = intrp2d_iu16n16ff_s32f_la_ns
      (localbpIndex_6, localfrac_6, (&(AirEfc_facLfpChrExpAtm_M[0])), 18U,
       &AirEfcEngCylPrmT_ConstP.InterpolationUsingPre[0]);

    /* DataTypeConversion: '<S128>/OutDTConv' incorporates:
     *  Constant: '<S128>/offset'
     *  Constant: '<S128>/one_on_slope'
     *  Product: '<S128>/Product4'
     *  Sum: '<S128>/Add1'
     */
    localfractionTmp_0d = 32.0F * rtu_In_ExM_tExMnfEstimRef;
    if (localfractionTmp_0d < 65536.0F) {
      if (localfractionTmp_0d >= 0.0F) {
        localOutDTConv_oi = (UInt16)localfractionTmp_0d;
      } else {
        localOutDTConv_oi = 0U;
      }
    } else {
      localOutDTConv_oi = MAX_uint16_T;
    }

    /* Lookup: '<S117>/Look-Up Table'
     * About '<S117>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-5
     * Output0 Data Type:  Fixed Point    U32  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U32_U16( &(localLookUpTable), (&(AirEfc_facTExSqrt_T[0])),
                   localOutDTConv_oi, (&(AirEfc_tExMnf_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S117>/Data Type Duplicate1'
     *
     * Regarding '<S117>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S111>/DTConv_UFix_To_Single_12' incorporates:
     *  Lookup: '<S117>/Look-Up Table'
     */
    localDTConv_UFix_To_Single_12 = ((Float32)localLookUpTable) *
      3.051757813E-005F;

    /* If: '<S116>/If' incorporates:
     *  ActionPort: '<S136>/Action Port'
     *  DataStoreRead: '<S116>/GT'
     *  SubSystem: '<S116>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S136>/MP' */
      AirEfc_facTExSqrt_MP = localDTConv_UFix_To_Single_12;
    }

    /* Lookup2D: '<S118>/Look-Up Table (2-D)'
     * About '<S118>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    U16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_S16( &(localLookUpTable2D_o), (&(AirEfc_mfBurnRspgRedBas_M[0])),
                       locala21, (&(AirEfc_nEngY_A[0])), 17U, localOutDTConv_c,
                       (&(AirEfc_agCkVlvOvlpX_A[0])), 24U);

    /* DataTypeDuplicate Block: '<S118>/Data Type Duplicate2'
     *
     * Regarding '<S118>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S119>/Look-Up Table (2-D)'
     * About '<S119>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    U16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_S16( &(localLookUpTable2D_b), (&(AirEfc_mfBurnRspgRedCor_M[0])),
                       locala21, (&(AirEfc_nEngY_A[0])), 17U, localOutDTConv_c,
                       (&(AirEfc_agCkVlvOvlpX_A[0])), 24U);

    /* DataTypeDuplicate Block: '<S119>/Data Type Duplicate2'
     *
     * Regarding '<S119>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S111>/DTConv_UFix_To_Single_2' incorporates:
     *  Lookup2D: '<S118>/Look-Up Table (2-D)'
     */
    localDTConv_UFix_To_Single_2_n = ((Float32)localLookUpTable2D_o) *
      1.525878906E-005F;

    /* If: '<S120>/If' incorporates:
     *  ActionPort: '<S137>/Action Port'
     *  DataStoreRead: '<S120>/GT'
     *  SubSystem: '<S120>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S137>/MP' */
      AirEfc_mfBurnRspgRedBas_MP = localDTConv_UFix_To_Single_2_n;
    }

    /* DataTypeConversion: '<S111>/DTConv_UFix_To_Single_1' incorporates:
     *  Lookup2D: '<S119>/Look-Up Table (2-D)'
     */
    localDTConv_UFix_To_Single_1_pv = ((Float32)localLookUpTable2D_b) *
      1.525878906E-005F;

    /* If: '<S121>/If' incorporates:
     *  ActionPort: '<S138>/Action Port'
     *  DataStoreRead: '<S121>/GT'
     *  SubSystem: '<S121>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S138>/MP' */
      AirEfc_mfBurnRspgRedCor_MP = localDTConv_UFix_To_Single_1_pv;
    }

    /* If: '<S123>/If' incorporates:
     *  ActionPort: '<S139>/Action Port'
     *  DataStoreRead: '<S123>/GT'
     *  SubSystem: '<S123>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S139>/MP' */
      AirEfc_rPresEng_MP = localSwitch2_o;
    }

    /* Product: '<S131>/Divide' */
    localSwitch2_o = rtu_In_ExM_pExMnfEstimRef / localDTConv_UFix_To_Single_2;

    /* Outputs for atomic SubSystem: '<S131>/If Action Subsystem3' */

    /* Switch: '<S152>/Switch1' incorporates:
     *  Constant: '<S152>/Constant1'
     *  Constant: '<S152>/Constant2'
     *  Constant: '<S152>/Constant3'
     *  Logic: '<S152>/Logical Operator1'
     *  RelationalOperator: '<S152>/Relational Operator'
     *  RelationalOperator: '<S152>/Relational Operator1'
     *  RelationalOperator: '<S152>/Relational Operator3'
     */
    if (((localSwitch2_o != localSwitch2_o) || (localSwitch2_o >
          3.000000005E+038F)) || (-3.000000005E+038F > localSwitch2_o)) {
      localSwitch2_o = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S131>/If Action Subsystem3' */

    /* If: '<S124>/If' incorporates:
     *  ActionPort: '<S140>/Action Port'
     *  DataStoreRead: '<S124>/GT'
     *  SubSystem: '<S124>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S140>/MP' */
      AirEfc_rPresExMnf_MP = localSwitch2_o;
    }

    /* Saturate: '<S146>/Saturation [0-1]' */
    localfractionTmp_0d = localInterpolationUsingPreloo_l;

    /* Sum: '<S146>/Sum1' incorporates:
     *  Product: '<S146>/Product'
     *  Sum: '<S146>/Sum'
     */
    localfractionTmp_0d = ((localMinMax_jq - rtu_In_AirEfc_facChrExpFilPrev) *
      rt_SATURATE(localfractionTmp_0d, 0.0F, 1.0F)) +
      rtu_In_AirEfc_facChrExpFilPrev;

    /* Product: '<S130>/Divide' incorporates:
     *  Constant: '<S111>/ConstVal_2'
     *  Product: '<S132>/Divide'
     *  Product: '<S133>/Divide'
     *  Product: '<S134>/Divide'
     *  Product: '<S135>/Divide'
     *  Sum: '<S111>/Sum'
     *  Sum: '<S111>/Sum1'
     */
    localDTConv_UFix_To_Single_1_pv = ((((((localfractionTmp_0d - 1.0F) *
      localDTConv_UFix_To_Single_1_pv) + localDTConv_UFix_To_Single_2_n) *
      localSwitch2_o) * localDTConv_UFix_To_Single_12) *
      localInterpolationUsingPreloo_j) / localDivide_pl;

    /* Outputs for atomic SubSystem: '<S130>/If Action Subsystem3' */

    /* Switch: '<S150>/Switch1' incorporates:
     *  Constant: '<S150>/Constant1'
     *  Constant: '<S150>/Constant2'
     *  Constant: '<S150>/Constant3'
     *  Logic: '<S150>/Logical Operator1'
     *  RelationalOperator: '<S150>/Relational Operator'
     *  RelationalOperator: '<S150>/Relational Operator1'
     *  RelationalOperator: '<S150>/Relational Operator3'
     */
    if (((localDTConv_UFix_To_Single_1_pv != localDTConv_UFix_To_Single_1_pv) ||
         (localDTConv_UFix_To_Single_1_pv > 3.000000005E+038F)) ||
        (-3.000000005E+038F > localDTConv_UFix_To_Single_1_pv)) {
      localDTConv_UFix_To_Single_1_pv = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S130>/If Action Subsystem3' */

    /* SignalConversion: '<S111>/Signal Conversion2' incorporates:
     *  Constant: '<S111>/ConstVal_4'
     *  MinMax: '<S111>/MinMax'
     */
    localMerge1 = rt_MAXf(localDTConv_UFix_To_Single_1_pv, 0.0F);

    /* SignalConversion: '<S111>/Signal Conversion3' */
    localB->SignalConversion3_n = localfractionTmp_0d;
  } else {
    /* Constant: '<S112>/ConstVal' */
    localDTConv_UFix_To_Single_1_pv = 0.0F;

    /* Constant: '<S112>/ConstVal_2' */
    localMerge1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S89>/F01_Reaspired_burn_mass' */

  /* If: '<S110>/If' incorporates:
   *  ActionPort: '<S113>/Action Port'
   *  DataStoreRead: '<S110>/GT'
   *  SubSystem: '<S110>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S113>/MP' */
    AirEfc_rMassBurnRspgTot_MP = localDTConv_UFix_To_Single_1_pv;
  }

  /* end of Outputs for SubSystem: '<S19>/F03_Reaspired_burn_mass' */

  /* If: '<S85>/If' incorporates:
   *  ActionPort: '<S99>/Action Port'
   *  DataStoreRead: '<S85>/GT'
   *  SubSystem: '<S85>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S99>/MP' */
    AirEfc_rMassBurnRspg_MP = localMerge1;
  }

  /* Outputs for atomic SubSystem: '<S19>/F04_Atmospheric_residual_total_burn_mass' *
   * Block requirements for '<S19>/F04_Atmospheric_residual_total_burn_mass':
   *  1. SubSystem "F04_Atmospheric_residual_total_burn_mass" !Trace_To : VEMS_R_11_00996_039.01 ;
   */

  /* DataTypeConversion: '<S160>/OutDTConv' incorporates:
   *  Constant: '<S160>/offset'
   *  Constant: '<S160>/one_on_slope'
   *  Product: '<S160>/Product4'
   *  Sum: '<S160>/Add1'
   */
  localfractionTmp_0d = 1.066666698E+001F * rtu_In_EngM_agCkClsExVlvRef1;
  if (localfractionTmp_0d < 32768.0F) {
    if (localfractionTmp_0d >= -32768.0F) {
      locallocalOutDTConv_o = (SInt16)localfractionTmp_0d;
    } else {
      locallocalOutDTConv_o = MIN_int16_T;
    }
  } else {
    locallocalOutDTConv_o = MAX_int16_T;
  }

  /* PreLookup: '<S153>/Prelookup' */
  localPrelookup_o1_h = plook_s32s16f_bincpa(locallocalOutDTConv_o,
    (&(AirEfc_agCkClsExVlvX_A[0])), 12U, &localPrelookup_o2_g,
    &localDW->Prelookup_DWORK1_b);

  /* Interpolation_n-D: '<S154>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2;
  localfrac_5[0] = localfractionTmp_0d;
  localfractionTmp_0d = localPrelookup_o2_g;
  localfrac_5[1] = localfractionTmp_0d;
  localbpIndex_5[0] = localPrelookup_o1;
  localbpIndex_5[1] = localPrelookup_o1_h;
  localDTConv_UFix_To_Single_2_n = intrp2d_iu16n15ff_s32f_la_ns(localbpIndex_5,
    localfrac_5, (&(AirEfc_facCorMassBurnRg_M[0])), 18U,
    &AirEfcEngCylPrmT_ConstP.pooled12[0]);

  /* If: '<S155>/If' incorporates:
   *  ActionPort: '<S166>/Action Port'
   *  DataStoreRead: '<S155>/GT'
   *  SubSystem: '<S155>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S166>/MP' */
    AirEfc_facCorMassBurnRg_MP = localDTConv_UFix_To_Single_2_n;
  }

  /* If: '<S90>/If' incorporates:
   *  ActionPort: '<S158>/Action Port'
   *  ActionPort: '<S159>/Action Port'
   *  Constant: '<S90>/AirEfc_bVolBurnRgTot_C'
   *  SubSystem: '<S90>/F04_1_AirEfc_rVolCyl_MP_IF'
   *  SubSystem: '<S90>/F04_2_AirEfc_rVolCyl_MP_ELSE'
   */
  if (AirEfc_bVolBurnRgTot_C) {
    /* Abs: '<S158>/Abs' */
    if (locallocalOutDTConv_o < 0) {
      localAbs_k = (UInt16)(-locallocalOutDTConv_o);
    } else {
      localAbs_k = (UInt16)locallocalOutDTConv_o;
    }

    /* Lookup: '<S169>/Look-Up Table'
     * About '<S169>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_h), (&(AirEfc_rVolCyl_T[0])), localAbs_k,
                   (&(AirEfc_agCk_facTDC_A[0])), 19U);

    /* DataTypeDuplicate Block: '<S169>/Data Type Duplicate1'
     *
     * Regarding '<S169>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S158>/DTConv_UFix_To_Single_1' incorporates:
     *  Lookup: '<S169>/Look-Up Table'
     */
    localDTConv_UFix_To_Single_12 = ((Float32)localLookUpTable_h) *
      3.051757813E-005F;
  } else {
    /* Product: '<S172>/Product4' incorporates:
     *  Constant: '<S172>/offset'
     *  Constant: '<S172>/one_on_slope'
     *  Sum: '<S172>/Add1'
     */
    localInterpolationUsingPreloo_h = 1.066666698E+001F *
      rtu_In_EngM_agCkOpInVlvRef1;

    /* DataTypeConversion: '<S172>/OutDTConv' */
    localfractionTmp_0d = localInterpolationUsingPreloo_h;
    if (localfractionTmp_0d < 32768.0F) {
      if (localfractionTmp_0d >= -32768.0F) {
        locallocalOutDTConv_o = (SInt16)localfractionTmp_0d;
      } else {
        locallocalOutDTConv_o = MIN_int16_T;
      }
    } else {
      locallocalOutDTConv_o = MAX_int16_T;
    }

    /* PreLookup: '<S170>/Prelookup' */
    localPrelookup_o1_c = plook_s32s16f_bincpa(locallocalOutDTConv_o,
      (&(AirEfc_agCkOpInVlvY_A[0])), 12U, &localInterpolationUsingPreloo_h,
      &localDW->Prelookup_DWORK1_n);

    /* Interpolation_n-D: '<S171>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_h;
    localfrac_7[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_g;
    localfrac_7[1] = localfractionTmp_0d;
    localbpIndex_7[0] = localPrelookup_o1_c;
    localbpIndex_7[1] = localPrelookup_o1_h;
    localInterpolationUsingPreloo_h = intrp2d_iu16n15ff_s32f_la_ns
      (localbpIndex_7, localfrac_7, (&(AirEfc_rVolCyl_M[0])), 13U,
       &AirEfcEngCylPrmT_ConstP.InterpolationUsingP_d[0]);

    /* SignalConversion: '<S159>/Signal Conversion2' */
    localDTConv_UFix_To_Single_12 = localInterpolationUsingPreloo_h;
  }

  /* Product: '<S162>/Divide' incorporates:
   *  Constant: '<S90>/AirEfc_pRef_C'
   *  DataTypeConversion: '<S90>/DTConv_UFix_To_Single_3'
   */
  localfractionTmp_0d = rtu_In_ExM_pExMnfEstimRef / (((Float32)AirEfc_pRef_C) *
    8.0F);

  /* Outputs for atomic SubSystem: '<S162>/If Action Subsystem3' */

  /* Switch: '<S176>/Switch1' incorporates:
   *  Constant: '<S176>/Constant1'
   *  Constant: '<S176>/Constant2'
   *  Constant: '<S176>/Constant3'
   *  Logic: '<S176>/Logical Operator1'
   *  RelationalOperator: '<S176>/Relational Operator'
   *  RelationalOperator: '<S176>/Relational Operator1'
   *  RelationalOperator: '<S176>/Relational Operator3'
   */
  if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
        3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
    localfractionTmp_0d = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S162>/If Action Subsystem3' */

  /* Product: '<S161>/Divide' incorporates:
   *  Constant: '<S90>/AirEfc_tRef_C'
   *  DataTypeConversion: '<S90>/DTConv_UFix_To_Single_4'
   */
  localSwitch2_o = (((Float32)AirEfc_tRef_C) * 0.0078125F) /
    rtu_In_ExM_tExMnfEstimRef;

  /* Outputs for atomic SubSystem: '<S161>/If Action Subsystem3' */

  /* Switch: '<S174>/Switch1' incorporates:
   *  Constant: '<S174>/Constant1'
   *  Constant: '<S174>/Constant2'
   *  Constant: '<S174>/Constant3'
   *  Logic: '<S174>/Logical Operator1'
   *  RelationalOperator: '<S174>/Relational Operator'
   *  RelationalOperator: '<S174>/Relational Operator1'
   *  RelationalOperator: '<S174>/Relational Operator3'
   */
  if (((localSwitch2_o != localSwitch2_o) || (localSwitch2_o > 3.000000005E+038F))
      || (-3.000000005E+038F > localSwitch2_o)) {
    localSwitch2_o = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S161>/If Action Subsystem3' */

  /* Product: '<S165>/Divide' incorporates:
   *  Product: '<S163>/Divide'
   *  Product: '<S164>/Divide'
   */
  localSwitch2_o *= (localfractionTmp_0d * localDTConv_UFix_To_Single_2_n) *
    localDTConv_UFix_To_Single_12;

  /* If: '<S156>/If' incorporates:
   *  ActionPort: '<S167>/Action Port'
   *  DataStoreRead: '<S156>/GT'
   *  SubSystem: '<S156>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S167>/MP' */
    AirEfc_rMassBurnRgTot_MP = localSwitch2_o;
  }

  /* If: '<S157>/If' incorporates:
   *  ActionPort: '<S168>/Action Port'
   *  DataStoreRead: '<S157>/GT'
   *  SubSystem: '<S157>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S168>/MP' */
    AirEfc_rVolCyl_MP = localDTConv_UFix_To_Single_12;
  }

  /* end of Outputs for SubSystem: '<S19>/F04_Atmospheric_residual_total_burn_mass' */

  /* Outputs for atomic SubSystem: '<S19>/F05_Atmospheric_residual_burn_mass' *
   * Block requirements for '<S19>/F05_Atmospheric_residual_burn_mass':
   *  1. SubSystem "F05_Atmospheric_residual_burn_mass" !Trace_To : VEMS_R_11_00996_040.01 ;
   */

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/AirEfc_agCkVlvOvlpLim_C'
   *  Constant: '<S91>/ConstVal_4'
   *  Constant: '<S92>/AirEfc_bBoostCf_C'
   *  DataTypeConversion: '<S91>/DTConv_UFix_To_Single_1'
   *  RelationalOperator: '<S91>/Relational Operator'
   */
  if (AirEfc_bBoostCf_C) {
    localRelationalOperator_l = (localSum_ht > ((((Float32)
      AirEfc_agCkVlvOvlpLim_C) * 1.5F) - 192.0F));
  } else {
    localRelationalOperator_l = FALSE;
  }

  /* If: '<S177>/If' incorporates:
   *  ActionPort: '<S180>/Action Port'
   *  DataStoreRead: '<S177>/GT'
   *  SubSystem: '<S177>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S180>/MP' */
    AirEfc_bMassBurnRgCor_MP = localRelationalOperator_l;
  }

  /* Switch: '<S91>/Switch1' incorporates:
   *  Constant: '<S91>/ConstVal_1'
   *  Constant: '<S91>/ConstVal_2'
   *  MinMax: '<S91>/MinMax'
   */
  if (localRelationalOperator_l) {
    localfractionTmp_0d = 0.0F;
  } else {
    localfractionTmp_0d = rt_MINf(localDTConv_UFix_To_Single_1_pv, 0.0F);
  }

  /* Sum: '<S91>/Sum' */
  localSum_h = localSwitch2_o + localfractionTmp_0d;

  /* MinMax: '<S91>/MinMax1' incorporates:
   *  Constant: '<S91>/ConstVal'
   */
  localmax = rt_MAXf(localSum_h, 0.0F);

  /* If: '<S178>/If' incorporates:
   *  ActionPort: '<S181>/Action Port'
   *  DataStoreRead: '<S178>/GT'
   *  SubSystem: '<S178>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S181>/MP' */
    AirEfc_rMassBurnRgCorSat_MP = localmax;
  }

  /* If: '<S179>/If' incorporates:
   *  ActionPort: '<S182>/Action Port'
   *  DataStoreRead: '<S179>/GT'
   *  SubSystem: '<S179>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S182>/MP' */
    AirEfc_rMassBurnRgCor_MP = localSum_h;
  }

  /* end of Outputs for SubSystem: '<S19>/F05_Atmospheric_residual_burn_mass' */

  /* Outputs for atomic SubSystem: '<S19>/F11_Engine_Speed_choice' *
   * Block requirements for '<S19>/F11_Engine_Speed_choice':
   *  1. SubSystem "F11_Engine_Speed_choice" !Trace_To : VEMS_R_11_00996_167.01 ;
   */

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S97>/AirEfc_bAcvEngSpdCorScv_C'
   */
  if (AirEfc_bAcvEngSpdCorScv_C) {
    localSwitch_j = rtu_In_InThM_nEngCorRef;
  } else {
    localSwitch_j = locala21;
  }

  /* PreLookup: '<S247>/Prelookup' */
  localPrelookup_o1_h = plook_s32u16f_bincpa(localSwitch_j, (&(AirEfc_nEng2Y_A[0])),
    7U, &localPrelookup_o2_k, &localDW->Prelookup_DWORK1_f);

  /* If: '<S248>/If' incorporates:
   *  ActionPort: '<S249>/Action Port'
   *  DataStoreRead: '<S248>/GT'
   *  SubSystem: '<S248>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S249>/MP' */
    AirEfc_nEngScv_MP = localSwitch_j;
  }

  /* end of Outputs for SubSystem: '<S19>/F11_Engine_Speed_choice' */

  /* Outputs for atomic SubSystem: '<S19>/F07_Scavenged_total_mass' *
   * Block requirements for '<S19>/F07_Scavenged_total_mass':
   *  1. SubSystem "F07_Scavenged_total_mass" !Trace_To : VEMS_R_11_00996_042.02 ;
   */

  /* RelationalOperator: '<S93>/Relational Operator' incorporates:
   *  Constant: '<S93>/AirEfc_nEngThdVal_C'
   */
  localRelationalOperator_l = (localSwitch_j >= AirEfc_nEngThdVal_C);

  /* Outputs for enable SubSystem: '<S93>/F01_Scavenged_total_mass_cal' incorporates:
   *  Constant: '<S92>/AirEfc_bBoost_C'
   *  EnablePort: '<S184>/Enable'
   *  Logic: '<S93>/Logical Operator'
   *
   * Block requirements for '<S93>/F01_Scavenged_total_mass_cal':
   *  1. SubSystem "F01_Scavenged_total_mass_cal" !Trace_To : VEMS_R_11_00996_043.02 ;
   */
  if (AirEfc_bBoost_C && (localRelationalOperator_l)) {
    /* Product: '<S201>/Divide' */
    localfractionTmp_0d = rtu_In_ExM_pExMnfEstimRef /
      rtu_In_InM_pDsThrPred_facVlvOvl;

    /* Outputs for atomic SubSystem: '<S201>/If Action Subsystem3' */

    /* Switch: '<S221>/Switch1' incorporates:
     *  Constant: '<S221>/Constant1'
     *  Constant: '<S221>/Constant2'
     *  Constant: '<S221>/Constant3'
     *  Logic: '<S221>/Logical Operator1'
     *  RelationalOperator: '<S221>/Relational Operator'
     *  RelationalOperator: '<S221>/Relational Operator1'
     *  RelationalOperator: '<S221>/Relational Operator3'
     */
    if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
          3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
      localfractionTmp_0d = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S201>/If Action Subsystem3' */

    /* Switch: '<S212>/Switch' incorporates:
     *  Constant: '<S184>/ConstVal_2'
     *  RelationalOperator: '<S212>/UpperRelop'
     */
    if (localfractionTmp_0d < 0.0F) {
      localInterpolationUsingPrelo_bu = 0.0F;
    } else {
      localInterpolationUsingPrelo_bu = localfractionTmp_0d;
    }

    /* Switch: '<S212>/Switch2' incorporates:
     *  Constant: '<S184>/ConstVal'
     *  RelationalOperator: '<S212>/LowerRelop1'
     */
    if (localfractionTmp_0d > 1.0F) {
      localDTConv_UFix_To_Single_1_pv = 1.0F;
    } else {
      localDTConv_UFix_To_Single_1_pv = localInterpolationUsingPrelo_bu;
    }

    /* Product: '<S198>/Product4' incorporates:
     *  Constant: '<S198>/offset'
     *  Constant: '<S198>/one_on_slope'
     *  Sum: '<S198>/Add1'
     */
    localInterpolationUsingPrelo_bu = 65536.0F * localDTConv_UFix_To_Single_1_pv;

    /* DataTypeConversion: '<S198>/OutDTConv' */
    localfractionTmp_0d = localInterpolationUsingPrelo_bu;
    if (localfractionTmp_0d < 4.294967296E+009F) {
      if (localfractionTmp_0d >= 0.0F) {
        locallocalOutDTConv_l = (UInt32)localfractionTmp_0d;
      } else {
        locallocalOutDTConv_l = 0U;
      }
    } else {
      locallocalOutDTConv_l = MAX_uint32_T;
    }

    /* PreLookup: '<S195>/Prelookup' */
    localPrelookup_o1_c = plook_s32u32f_bincpa(locallocalOutDTConv_l,
      (&(AirEfc_rPresEngX_A[0])), 10U, &localInterpolationUsingPrelo_bu,
      &localDW->Prelookup_DWORK1_mq);

    /* Interpolation_n-D: '<S187>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPrelo_bu;
    localMinMax_jq = intrp1d_iu16n16ff_s32f_la_ns(localPrelookup_o1_c,
      localfractionTmp_0d, (&(AirEfc_facChrExp_T[0])), 10U);

    /* Interpolation_n-D: '<S188>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_k;
    localfrac_8[0] = localfractionTmp_0d;
    localfractionTmp_0d = localInterpolationUsingPrelo_bu;
    localfrac_8[1] = localfractionTmp_0d;
    localbpIndex_8[0] = localPrelookup_o1_h;
    localbpIndex_8[1] = localPrelookup_o1_c;
    localInterpolationUsingPrelo_bu = intrp2d_iu16n16ff_s32f_la_ns
      (localbpIndex_8, localfrac_8, (&(AirEfc_facLfpChrExpBoost_M[0])), 8U,
       &AirEfcEngCylPrmT_ConstP.pooled14[0]);

    /* Interpolation_n-D: '<S190>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_a;
    localDTConv_UFix_To_Single_12 = intrp1d_iu16n15ff_s32f_la_ns
      (localPrelookup_o1_o, localfractionTmp_0d, (&(AirEfc_facTInSqrt_T[0])),
       15U);

    /* If: '<S189>/If' incorporates:
     *  ActionPort: '<S206>/Action Port'
     *  DataStoreRead: '<S189>/GT'
     *  SubSystem: '<S189>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S206>/MP' */
      AirEfc_facTInSqrt_MP = localDTConv_UFix_To_Single_12;
    }

    /* Lookup2D: '<S191>/Look-Up Table (2-D)'
     * About '<S191>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    U16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_S16( &(localLookUpTable2D), (&(AirEfc_mfAirScvRed_M[0])),
                       localSwitch_j, (&(AirEfc_nEng2Y_A[0])), 7U,
                       localOutDTConv_c, (&(AirEfc_agCkVlvOvlpX_A[0])), 24U);

    /* DataTypeDuplicate Block: '<S191>/Data Type Duplicate2'
     *
     * Regarding '<S191>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S184>/DTConv_UFix_To_Single_1' incorporates:
     *  Lookup2D: '<S191>/Look-Up Table (2-D)'
     */
    localDTConv_UFix_To_Single_2_n = ((Float32)localLookUpTable2D) *
      1.525878906E-005F;

    /* If: '<S192>/If' incorporates:
     *  ActionPort: '<S207>/Action Port'
     *  DataStoreRead: '<S192>/GT'
     *  SubSystem: '<S192>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S207>/MP' */
      AirEfc_mfAirScvRed_MP = localDTConv_UFix_To_Single_2_n;
    }

    /* Product: '<S199>/Divide' */
    localSwitch2_o = rtu_In_InM_pDsThrPred_facVlvOvl /
      localDTConv_UFix_To_Single_2;

    /* Outputs for atomic SubSystem: '<S199>/If Action Subsystem3' */

    /* Switch: '<S217>/Switch1' incorporates:
     *  Constant: '<S217>/Constant1'
     *  Constant: '<S217>/Constant2'
     *  Constant: '<S217>/Constant3'
     *  Logic: '<S217>/Logical Operator1'
     *  RelationalOperator: '<S217>/Relational Operator'
     *  RelationalOperator: '<S217>/Relational Operator1'
     *  RelationalOperator: '<S217>/Relational Operator3'
     */
    if (((localSwitch2_o != localSwitch2_o) || (localSwitch2_o >
          3.000000005E+038F)) || (-3.000000005E+038F > localSwitch2_o)) {
      localSwitch2_o = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S199>/If Action Subsystem3' */

    /* If: '<S193>/If' incorporates:
     *  ActionPort: '<S208>/Action Port'
     *  DataStoreRead: '<S193>/GT'
     *  SubSystem: '<S193>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S208>/MP' */
      AirEfc_rPresDsThr_MP = localSwitch2_o;
    }

    /* If: '<S194>/If' incorporates:
     *  ActionPort: '<S209>/Action Port'
     *  DataStoreRead: '<S194>/GT'
     *  SubSystem: '<S194>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S209>/MP' */
      AirEfc_rPresEngScv_MP = localDTConv_UFix_To_Single_1_pv;
    }

    /* Saturate: '<S215>/Saturation [0-1]' */
    localfractionTmp_0d = localInterpolationUsingPrelo_bu;

    /* Sum: '<S215>/Sum1' incorporates:
     *  Product: '<S215>/Product'
     *  Sum: '<S215>/Sum'
     */
    localMinMax_jq = ((localMinMax_jq - rtu_In_AirEfc_facChrExpScvFilPr) *
                      rt_SATURATE(localfractionTmp_0d, 0.0F, 1.0F)) +
      rtu_In_AirEfc_facChrExpScvFilPr;

    /* SignalConversion: '<S184>/Signal Conversion3' */
    localB->SignalConversion3 = localMinMax_jq;

    /* Product: '<S200>/Divide' incorporates:
     *  Product: '<S202>/Divide'
     *  Product: '<S203>/Divide'
     *  Product: '<S204>/Divide'
     *  Product: '<S205>/Divide'
     */
    localfractionTmp_0d = ((((localDTConv_UFix_To_Single_2_n * localMinMax_jq) *
      localSwitch2_o) * localDTConv_UFix_To_Single_12) *
      localInterpolationUsingPreloo_j) / localDivide_pl;

    /* Outputs for atomic SubSystem: '<S200>/If Action Subsystem3' */

    /* Switch: '<S219>/Switch1' incorporates:
     *  Constant: '<S219>/Constant1'
     *  Constant: '<S219>/Constant2'
     *  Constant: '<S219>/Constant3'
     *  DataTypeConversion: '<S200>/Data Type Conversion2'
     *  Logic: '<S219>/Logical Operator1'
     *  RelationalOperator: '<S219>/Relational Operator'
     *  RelationalOperator: '<S219>/Relational Operator1'
     *  RelationalOperator: '<S219>/Relational Operator3'
     */
    if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
          3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
      localB->Merge = 0.0F;
    } else {
      localB->Merge = localfractionTmp_0d;
    }

    /* end of Outputs for SubSystem: '<S200>/If Action Subsystem3' */
  }

  /* end of Outputs for SubSystem: '<S93>/F01_Scavenged_total_mass_cal' */

  /* Outputs for enable SubSystem: '<S93>/F02_Scavenged_total_mass_init' incorporates:
   *  Constant: '<S92>/AirEfc_bBoost_C'
   *  EnablePort: '<S185>/Enable'
   *  Logic: '<S93>/Logical Operator1'
   *  Logic: '<S93>/Logical Operator2'
   *
   * Block requirements for '<S93>/F02_Scavenged_total_mass_init':
   *  1. SubSystem "F02_Scavenged_total_mass_init" !Trace_To : VEMS_R_11_00996_044.01 ;
   */
  if (AirEfc_bBoost_C && (!localRelationalOperator_l)) {
    /* Constant: '<S185>/ConstVal' */
    localB->Merge = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S93>/F02_Scavenged_total_mass_init' */

  /* If: '<S183>/If' incorporates:
   *  ActionPort: '<S186>/Action Port'
   *  DataStoreRead: '<S183>/GT'
   *  SubSystem: '<S183>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S186>/MP' */
    AirEfc_rMassAirScvTot_MP = localB->Merge;
  }

  /* end of Outputs for SubSystem: '<S19>/F07_Scavenged_total_mass' */

  /* Outputs for atomic SubSystem: '<S19>/F08_Balancing_scavenged_and_residual_mass' *
   * Block requirements for '<S19>/F08_Balancing_scavenged_and_residual_mass':
   *  1. SubSystem "F08_Balancing_scavenged_and_residual_mass" !Trace_To : VEMS_R_11_00996_045.02 ;
   */

  /* Outputs for atomic SubSystem: '<S94>/F01_scavenged_and_residual_mass' *
   * Block requirements for '<S94>/F01_scavenged_and_residual_mass':
   *  1. SubSystem "F01_scavenged_and_residual_mass" !Trace_To : VEMS_R_11_00996_046.01 ;
   */

  /* Product: '<S228>/Divide' incorporates:
   *  DataTypeConversion: '<S223>/DTConv_Single_To_UFix_5'
   */
  localfractionTmp_0d = rtu_In_ExM_tExMnfEstimRef / ((((Float32)locala25) *
    0.0078125F) + 223.0F);

  /* Outputs for atomic SubSystem: '<S228>/If Action Subsystem3' */

  /* Switch: '<S232>/Switch1' incorporates:
   *  Constant: '<S232>/Constant1'
   *  Constant: '<S232>/Constant2'
   *  Constant: '<S232>/Constant3'
   *  Logic: '<S232>/Logical Operator1'
   *  RelationalOperator: '<S232>/Relational Operator'
   *  RelationalOperator: '<S232>/Relational Operator1'
   *  RelationalOperator: '<S232>/Relational Operator3'
   */
  if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
        3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
    localfractionTmp_0d = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S228>/If Action Subsystem3' */

  /* Switch: '<S223>/Switch' incorporates:
   *  Constant: '<S223>/AirEfc_bRhoAir_C'
   *  Product: '<S229>/Divide'
   */
  if (AirEfc_bRhoAir_C) {
    localfractionTmp_0d *= localSum_h;
  } else {
    localfractionTmp_0d = localSum_h;
  }

  /* Sum: '<S223>/Sum1' */
  localfractionTmp_0d += localB->Merge;

  /* If: '<S227>/If' incorporates:
   *  ActionPort: '<S230>/Action Port'
   *  DataStoreRead: '<S227>/GT'
   *  SubSystem: '<S227>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S230>/MP' */
    AirEfc_facAirScv_MP = localfractionTmp_0d;
  }

  /* end of Outputs for SubSystem: '<S94>/F01_scavenged_and_residual_mass' */

  /* RelationalOperator: '<S94>/Relational Operator' incorporates:
   *  Constant: '<S94>/ConstVal'
   */
  localRelationalOperator_l = (localfractionTmp_0d > 0.0F);

  /* Outputs for enable SubSystem: '<S94>/F02_balancing_mass_cal' incorporates:
   *  Constant: '<S92>/AirEfc_bBoost_C'
   *  EnablePort: '<S224>/Enable'
   *  Logic: '<S94>/Logical Operator'
   *
   * Block requirements for '<S94>/F02_balancing_mass_cal':
   *  1. SubSystem "F02_balancing_mass_cal" !Trace_To : VEMS_R_11_00996_047.02 ;
   */
  if (AirEfc_bBoost_C && (localRelationalOperator_l)) {
    /* Product: '<S239>/Divide' */
    localfractionTmp_0d = localB->Merge / localfractionTmp_0d;

    /* Outputs for atomic SubSystem: '<S239>/If Action Subsystem3' */

    /* Switch: '<S246>/Switch1' incorporates:
     *  Constant: '<S246>/Constant1'
     *  Constant: '<S246>/Constant2'
     *  Constant: '<S246>/Constant3'
     *  Logic: '<S246>/Logical Operator1'
     *  RelationalOperator: '<S246>/Relational Operator'
     *  RelationalOperator: '<S246>/Relational Operator1'
     *  RelationalOperator: '<S246>/Relational Operator3'
     */
    if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
          3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
      localfractionTmp_0d = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S239>/If Action Subsystem3' */

    /* If: '<S233>/If' incorporates:
     *  ActionPort: '<S242>/Action Port'
     *  DataStoreRead: '<S233>/GT'
     *  SubSystem: '<S233>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S242>/MP' */
      AirEfc_facAirScv1_MP = localfractionTmp_0d;
    }

    /* Product: '<S238>/Product4' incorporates:
     *  Constant: '<S238>/offset'
     *  Constant: '<S238>/one_on_slope'
     *  Sum: '<S238>/Add1'
     */
    localPrelookup_o2_c = 65536.0F * localfractionTmp_0d;

    /* DataTypeConversion: '<S238>/OutDTConv' */
    localfractionTmp_0d = localPrelookup_o2_c;
    if (localfractionTmp_0d < 65536.0F) {
      if (localfractionTmp_0d >= 0.0F) {
        locala27 = (UInt16)localfractionTmp_0d;
      } else {
        locala27 = 0U;
      }
    } else {
      locala27 = MAX_uint16_T;
    }

    /* PreLookup: '<S235>/Prelookup' */
    localPrelookup_o1_c = plook_s32u16f_bincpa(locala27, (&(AirEfc_facAirScvX_A
      [0])), 10U, &localPrelookup_o2_c, &localDW->Prelookup_DWORK1_g);

    /* Interpolation_n-D: '<S236>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_k;
    localfrac_9[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_c;
    localfrac_9[1] = localfractionTmp_0d;
    localbpIndex_9[0] = localPrelookup_o1_h;
    localbpIndex_9[1] = localPrelookup_o1_c;
    localSwitch2_o = intrp2d_iu16n16ff_s32f_la_ns(localbpIndex_9, localfrac_9, (
      &(AirEfc_facAirScv_M[0])), 8U, &AirEfcEngCylPrmT_ConstP.pooled14[0]);

    /* If: '<S234>/If' incorporates:
     *  ActionPort: '<S243>/Action Port'
     *  DataStoreRead: '<S234>/GT'
     *  SubSystem: '<S234>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S243>/MP' */
      AirEfc_facAirScv2_MP = localSwitch2_o;
    }

    /* Sum: '<S224>/Sum' incorporates:
     *  Constant: '<S224>/ConstVal'
     *  Product: '<S240>/Divide'
     *  Sum: '<S224>/Sum2'
     */
    localfractionTmp_0d = localSum_h - ((1.0F - localSwitch2_o) * localB->Merge);

    /* If: '<S237>/If' incorporates:
     *  ActionPort: '<S244>/Action Port'
     *  DataStoreRead: '<S237>/GT'
     *  SubSystem: '<S237>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S244>/MP' */
      AirEfc_rMassBurnRgBoostCor_MP = localfractionTmp_0d;
    }

    /* MinMax: '<S224>/MinMax1' incorporates:
     *  Constant: '<S224>/ConstVal_2'
     */
    localB->Merge1_k = rt_MAXf(localfractionTmp_0d, 0.0F);

    /* SignalConversion: '<S224>/Signal Conversion1' */
    localB->Merge2 = localSwitch2_o;

    /* Product: '<S241>/Divide' */
    localB->Merge3 = localB->Merge * localSwitch2_o;
  }

  /* end of Outputs for SubSystem: '<S94>/F02_balancing_mass_cal' */

  /* Outputs for enable SubSystem: '<S94>/F03_balancing_mass_Def' incorporates:
   *  Constant: '<S92>/AirEfc_bBoost_C'
   *  EnablePort: '<S225>/Enable'
   *  Logic: '<S94>/Logical Operator1'
   *  Logic: '<S94>/Logical Operator2'
   *
   * Block requirements for '<S94>/F03_balancing_mass_Def':
   *  1. SubSystem "F03_balancing_mass_Def" !Trace_To : VEMS_R_11_00996_048.01 ;
   */
  if ((!localRelationalOperator_l) && AirEfc_bBoost_C) {
    /* DataTypeConversion: '<S225>/DTConv_UFix_To_Single_2' incorporates:
     *  Constant: '<S225>/AirEfc_facMassAirScv_C'
     */
    localB->Merge2 = ((Float32)AirEfc_facMassAirScv_C) * 9.999999747E-005F;

    /* Constant: '<S225>/ConstVal_2' */
    localB->Merge3 = 0.0F;

    /* Constant: '<S225>/ConstVal' */
    localB->Merge1_k = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S94>/F03_balancing_mass_Def' */

  /* If: '<S222>/If' incorporates:
   *  ActionPort: '<S226>/Action Port'
   *  DataStoreRead: '<S222>/GT'
   *  SubSystem: '<S222>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S226>/MP' */
    AirEfc_rMassBurnRgBoostCorSat_MP = localB->Merge1_k;
  }

  /* end of Outputs for SubSystem: '<S19>/F08_Balancing_scavenged_and_residual_mass' */

  /* Outputs for atomic SubSystem: '<S19>/F09_residual_burn_mass' *
   * Block requirements for '<S19>/F09_residual_burn_mass':
   *  1. SubSystem "F09_residual_burn_mass" !Trace_To : VEMS_R_11_00996_049.01 ;
   */

  /* Switch: '<S95>/Switch1' incorporates:
   *  Constant: '<S92>/AirEfc_bBoost_C'
   */
  if (AirEfc_bBoost_C) {
    localmax = localB->Merge1_k;
  }

  /* end of Outputs for SubSystem: '<S19>/F09_residual_burn_mass' */

  /* Outputs for atomic SubSystem: '<S19>/F10_burn_mass' *
   * Block requirements for '<S19>/F10_burn_mass':
   *  1. SubSystem "F10_burn_mass" !Trace_To : VEMS_R_11_00996_050.01 ;
   */

  /* Sum: '<S96>/Sum' */
  localSum_ht = localmax + localMerge1;

  /* end of Outputs for SubSystem: '<S19>/F10_burn_mass' */

  /* If: '<S86>/If' incorporates:
   *  ActionPort: '<S100>/Action Port'
   *  DataStoreRead: '<S86>/GT'
   *  SubSystem: '<S86>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S100>/MP' */
    AirEfc_rMassBurn_MP = localSum_ht;
  }

  /* end of Outputs for SubSystem: '<S9>/F07_Residual_scavenged_reaspired_mass' */

  /* Outputs for atomic SubSystem: '<S9>/F08_burn_gas_temperature' *
   * Block requirements for '<S9>/F08_burn_gas_temperature':
   *  1. SubSystem "F08_burn_gas_temperature" !Trace_To : VEMS_R_11_00996_051.01 ;
   */

  /* Outputs for enable SubSystem: '<S20>/F01_burn_gas_temperature' incorporates:
   *  Constant: '<S20>/ConstVal'
   *  EnablePort: '<S251>/Enable'
   *  EnablePort: '<S252>/Enable'
   *  Logic: '<S20>/Logical Operator'
   *  RelationalOperator: '<S20>/Relational Operator'
   *  SubSystem: '<S20>/F02_Ex_gas_temperature'
   *
   * Block requirements for '<S20>/F01_burn_gas_temperature':
   *  1. SubSystem "F01_burn_gas_temperature" !Trace_To : VEMS_R_11_00996_052.01 ;
   *
   * Block requirements for '<S20>/F02_Ex_gas_temperature':
   *  1. SubSystem "F02_Ex_gas_temperature" !Trace_To : VEMS_R_11_00996_053.01 ;
   */
  if (localSum_ht > 0.0F) {
    /* Product: '<S256>/Divide' */
    localfractionTmp_0d = rtu_In_InM_pDsThrPred_facVlvOvl /
      rtu_In_ExM_pExMnfEstimRef;

    /* Outputs for atomic SubSystem: '<S256>/If Action Subsystem3' */

    /* Switch: '<S264>/Switch1' incorporates:
     *  Constant: '<S264>/Constant1'
     *  Constant: '<S264>/Constant2'
     *  Constant: '<S264>/Constant3'
     *  Logic: '<S264>/Logical Operator1'
     *  RelationalOperator: '<S264>/Relational Operator'
     *  RelationalOperator: '<S264>/Relational Operator1'
     *  RelationalOperator: '<S264>/Relational Operator3'
     */
    if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
          3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
      localfractionTmp_0d = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S256>/If Action Subsystem3' */

    /* Product: '<S255>/Divide' incorporates:
     *  Constant: '<S251>/AirEfc_gmaIvsAir_C'
     *  Constant: '<S251>/AirEfc_gmaIvsAir_C_2'
     *  Constant: '<S251>/ConstVal'
     *  DataTypeConversion: '<S251>/DTConv_UFix_To_Single_1'
     *  DataTypeConversion: '<S251>/DTConv_UFix_To_Single_2'
     *  Product: '<S257>/Divide'
     *  Product: '<S258>/Divide'
     *  Product: '<S259>/Divide'
     *  Product: '<S260>/Divide'
     *  Sum: '<S251>/Sum'
     *  Sum: '<S251>/Sum1'
     *  Sum: '<S251>/Sum2'
     */
    localDTConv_UFix_To_Single_1_pv = ((((((1.0F - ((((Float32)
      AirEfc_gmaIvsAir_C) * 7.629394531E-006F) + 0.5F)) * localfractionTmp_0d) +
      ((((Float32)AirEfc_gmaIvsAir_C) * 7.629394531E-006F) + 0.5F)) *
      rtu_In_ExM_tExMnfEstimRef) * localmax) + (localMerge1 *
      rtu_In_ExM_tExMnfEstimRef)) / localSum_ht;

    /* Outputs for atomic SubSystem: '<S255>/If Action Subsystem3' */

    /* Switch: '<S262>/Switch1' incorporates:
     *  Constant: '<S262>/Constant1'
     *  Constant: '<S262>/Constant2'
     *  Constant: '<S262>/Constant3'
     *  Logic: '<S262>/Logical Operator1'
     *  RelationalOperator: '<S262>/Relational Operator'
     *  RelationalOperator: '<S262>/Relational Operator1'
     *  RelationalOperator: '<S262>/Relational Operator3'
     */
    if (((localDTConv_UFix_To_Single_1_pv != localDTConv_UFix_To_Single_1_pv) ||
         (localDTConv_UFix_To_Single_1_pv > 3.000000005E+038F)) ||
        (-3.000000005E+038F > localDTConv_UFix_To_Single_1_pv)) {
      localDTConv_UFix_To_Single_1_pv = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S255>/If Action Subsystem3' */
  } else {
    /* SignalConversion: '<S252>/Signal Conversion1' */
    localDTConv_UFix_To_Single_1_pv = rtu_In_ExM_tExMnfEstimRef;
  }

  /* end of Outputs for SubSystem: '<S20>/F01_burn_gas_temperature' */

  /* Outputs for atomic SubSystem: '<S20>/F03_fac_burn_gas_temperature' *
   * Block requirements for '<S20>/F03_fac_burn_gas_temperature':
   *  1. SubSystem "F03_fac_burn_gas_temperature" !Trace_To : VEMS_R_11_00996_054.01 ;
   */

  /* DataTypeConversion: '<S266>/OutDTConv' incorporates:
   *  Constant: '<S266>/offset'
   *  Constant: '<S266>/one_on_slope'
   *  Product: '<S266>/Product4'
   *  Sum: '<S266>/Add1'
   */
  localfractionTmp_0d = 32.0F * localDTConv_UFix_To_Single_1_pv;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      localOutDTConv_e = (UInt16)localfractionTmp_0d;
    } else {
      localOutDTConv_e = 0U;
    }
  } else {
    localOutDTConv_e = MAX_uint16_T;
  }

  /* Lookup: '<S265>/Look-Up Table'
   * About '<S265>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-5
   * Output0 Data Type:  Fixed Point    U16  2^-13  FSlope 1.25
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_f), (&(AirEfc_facTBurnCyl_T[0])),
                 localOutDTConv_e, (&(AirEfc_tBurnCyl_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S265>/Data Type Duplicate1'
   *
   * Regarding '<S265>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S253>/DTConv_UFix_To_Single_2' incorporates:
   *  Lookup: '<S265>/Look-Up Table'
   */
  localMinMax_jq = ((Float32)localLookUpTable_f) * 1.525878906E-004F;

  /* end of Outputs for SubSystem: '<S20>/F03_fac_burn_gas_temperature' */

  /* If: '<S250>/If' incorporates:
   *  ActionPort: '<S254>/Action Port'
   *  DataStoreRead: '<S250>/GT'
   *  SubSystem: '<S250>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S254>/MP' */
    AirEfc_facTBurnCyl_MP = localMinMax_jq;
  }

  /* end of Outputs for SubSystem: '<S9>/F08_burn_gas_temperature' */

  /* Outputs for atomic SubSystem: '<S9>/F12_Gasoline_direct_injection_offset' *
   * Block requirements for '<S9>/F12_Gasoline_direct_injection_offset':
   *  1. SubSystem "F12_Gasoline_direct_injection_offset" !Trace_To : VEMS_R_11_00996_058.02 ;
   */

  /* If: '<S24>/If' incorporates:
   *  ActionPort: '<S275>/Action Port'
   *  ActionPort: '<S276>/Action Port'
   *  Constant: '<S24>/AirEfc_bAcvGDIOfs_C'
   *  SubSystem: '<S24>/F01_Gasoline_Direct_Injection_Offset_Calculation'
   *  SubSystem: '<S24>/F02_GDI_Offset_Correction'
   *
   * Block requirements for '<S24>/F01_Gasoline_Direct_Injection_Offset_Calculation':
   *  1. SubSystem "F01_Gasoline_Direct_Injection_Offset_Calculation" !Trace_To : VEMS_R_11_00996_059.02 ;
   *
   * Block requirements for '<S24>/F02_GDI_Offset_Correction':
   *  1. SubSystem "F02_GDI_Offset_Correction" !Trace_To : VEMS_R_11_00996_066.01 ;
   */
  if (AirEfc_bAcvGDIOfs_C) {
    /* Outputs for atomic SubSystem: '<S275>/F01_Sqrt_Fuel_Temperature' *
     * Block requirements for '<S275>/F01_Sqrt_Fuel_Temperature':
     *  1. SubSystem "F01_Sqrt_Fuel_Temperature" !Trace_To : VEMS_R_11_00996_060.01 ;
     */

    /* DataTypeConversion: '<S277>/DTConv_UFix_To_Single_1' */
    if (locala39 > 511) {
      localDTConv_UFix_To_Single_1_pd = MAX_uint16_T;
    } else {
      localDTConv_UFix_To_Single_1_pd = (UInt16)(locala39 << 7);
    }

    /* Lookup: '<S283>/Look-Up Table'
     * About '<S283>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
     * Output0 Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_i), (&(AirEfc_facTFu_T[0])),
                   localDTConv_UFix_To_Single_1_pd, (&(AirEfc_tFu_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S283>/Data Type Duplicate1'
     *
     * Regarding '<S283>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S277>/DTConv_UFix_To_Single_2' incorporates:
     *  Lookup: '<S283>/Look-Up Table'
     */
    localDTConv_UFix_To_Single_2_n = ((Float32)localLookUpTable_i) *
      1.000000047E-003F;

    /* end of Outputs for SubSystem: '<S275>/F01_Sqrt_Fuel_Temperature' */

    /* Outputs for atomic SubSystem: '<S275>/F05_Angle_Offset_End_of_first_Injection' *
     * Block requirements for '<S275>/F05_Angle_Offset_End_of_first_Injection':
     *  1. SubSystem "F05_Angle_Offset_End_of_first_Injection" !Trace_To : VEMS_R_11_00996_064.01 ;
     */

    /* Sum: '<S281>/Add' incorporates:
     *  Constant: '<S281>/AirEfc_agInj1EndOfs_C'
     *  DataTypeConversion: '<S281>/DTConv_UFix_To_Single_1'
     */
    localSum_h = (((Float32)AirEfc_agInj1EndOfs_C) * 1.000000015E-001F) +
      rtu_In_InjSys_agInj1EndRef;

    /* end of Outputs for SubSystem: '<S275>/F05_Angle_Offset_End_of_first_Injection' */

    /* Outputs for atomic SubSystem: '<S275>/F04_Angle_Offset_Start_of_first_Injection' *
     * Block requirements for '<S275>/F04_Angle_Offset_Start_of_first_Injection':
     *  1. SubSystem "F04_Angle_Offset_Start_of_first_Injection" !Trace_To : VEMS_R_11_00996_063.01 ;
     */

    /* Sum: '<S280>/Add' incorporates:
     *  Constant: '<S280>/AirEfc_agInj1BegOfs_C'
     *  DataTypeConversion: '<S280>/DTConv_UFix_To_Single_1'
     */
    localSwitch2_o = (((Float32)AirEfc_agInj1BegOfs_C) * 1.000000015E-001F) +
      rtu_In_InjSys_agInj1BegRef;

    /* end of Outputs for SubSystem: '<S275>/F04_Angle_Offset_Start_of_first_Injection' */

    /* Outputs for atomic SubSystem: '<S275>/F06_Mass_to_ratio' *
     * Block requirements for '<S275>/F06_Mass_to_ratio':
     *  1. SubSystem "F06_Mass_to_ratio" !Trace_To : VEMS_R_11_00996_065.01 ;
     */

    /* Product: '<S298>/Divide' incorporates:
     *  Constant: '<S282>/EngM_mRef_C'
     *  DataTypeConversion: '<S282>/DTConv_UFix_To_Single_1'
     */
    localDTConv_UFix_To_Single_12 = rtu_In_InjSys_mFu1Inj / (((Float32)
      EngM_mRef_C) * 1.192016583E-007F);

    /* Outputs for atomic SubSystem: '<S298>/If Action Subsystem3' */

    /* Switch: '<S300>/Switch1' incorporates:
     *  Constant: '<S300>/Constant1'
     *  Constant: '<S300>/Constant2'
     *  Constant: '<S300>/Constant3'
     *  Logic: '<S300>/Logical Operator1'
     *  RelationalOperator: '<S300>/Relational Operator'
     *  RelationalOperator: '<S300>/Relational Operator1'
     *  RelationalOperator: '<S300>/Relational Operator3'
     */
    if (((localDTConv_UFix_To_Single_12 != localDTConv_UFix_To_Single_12) ||
         (localDTConv_UFix_To_Single_12 > 3.000000005E+038F)) ||
        (-3.000000005E+038F > localDTConv_UFix_To_Single_12)) {
      localDTConv_UFix_To_Single_12 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S298>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S275>/F06_Mass_to_ratio' */

    /* Outputs for atomic SubSystem: '<S275>/F02_Ratio_Fuel_Mass_Injected_Before_Intake_closing' *
     * Block requirements for '<S275>/F02_Ratio_Fuel_Mass_Injected_Before_Intake_closing':
     *  1. SubSystem "F02_Ratio_Fuel_Mass_Injected_Before_Intake_closing" !Trace_To : VEMS_R_11_00996_061.01 ;
     */

    /* Sum: '<S278>/Add3' */
    localfractionTmp_0d = localSwitch2_o - localSum_h;

    /* MinMax: '<S278>/MinMax2' incorporates:
     *  Constant: '<S278>/ConstVal_3'
     */
    localfractionTmp_0d = rt_MAXf(1.0F, localfractionTmp_0d);

    /* If: '<S284>/If' incorporates:
     *  ActionPort: '<S288>/Action Port'
     *  DataStoreRead: '<S284>/GT'
     *  SubSystem: '<S284>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S288>/MP' */
      AirEfc_agCkInj_MP = localfractionTmp_0d;
    }

    /* Product: '<S286>/Divide' incorporates:
     *  Sum: '<S278>/Add2'
     */
    localfractionTmp_0d = (localSwitch2_o - locala23) / localfractionTmp_0d;

    /* RelationalOperator: '<S291>/LowerRelop1' incorporates:
     *  Constant: '<S278>/ConstVal_1'
     */
    localRelationalOperator_l = (localfractionTmp_0d > 1.0F);

    /* Switch: '<S291>/Switch' incorporates:
     *  Constant: '<S278>/ConstVal'
     *  RelationalOperator: '<S291>/UpperRelop'
     */
    if (localfractionTmp_0d < 0.0F) {
      localfractionTmp_0d = 0.0F;
    }

    /* Switch: '<S291>/Switch2' incorporates:
     *  Constant: '<S278>/ConstVal_1'
     */
    if (localRelationalOperator_l) {
      localfractionTmp_0d = 1.0F;
    }

    /* Product: '<S287>/Divide' */
    localDTConv_UFix_To_Single_12 *= localfractionTmp_0d;

    /* end of Outputs for SubSystem: '<S275>/F02_Ratio_Fuel_Mass_Injected_Before_Intake_closing' */

    /* Outputs for atomic SubSystem: '<S275>/F03_Offset_of_Fuel_Mass_and_timing_effect' *
     * Block requirements for '<S275>/F03_Offset_of_Fuel_Mass_and_timing_effect':
     *  1. SubSystem "F03_Offset_of_Fuel_Mass_and_timing_effect" !Trace_To : VEMS_R_11_00996_062.01 ;
     */

    /* DataTypeConversion: '<S294>/OutDTConv' incorporates:
     *  Constant: '<S294>/offset'
     *  Constant: '<S294>/one_on_slope'
     *  Product: '<S294>/Product4'
     *  Sum: '<S279>/Add'
     *  Sum: '<S294>/Add1'
     */
    localfractionTmp_0d = (localSum_h - locala23) * 10.0F;
    if (localfractionTmp_0d < 32768.0F) {
      if (localfractionTmp_0d >= -32768.0F) {
        localOutDTConv_dz = (SInt16)localfractionTmp_0d;
      } else {
        localOutDTConv_dz = MIN_int16_T;
      }
    } else {
      localOutDTConv_dz = MAX_int16_T;
    }

    /* Lookup2D: '<S292>/Look-Up Table (2-D)'
     * About '<S292>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.6
     * Output0 Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_S16( &(localLookUpTable2D_m), (&(AirEfc_rFuStmMass_M[0])),
                       locala21, (&(AirEfc_nEngY_A[0])), 17U, localOutDTConv_dz,
                       (&(AirEfc_agInjPha_A[0])), 19U);

    /* DataTypeDuplicate Block: '<S292>/Data Type Duplicate2'
     *
     * Regarding '<S292>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S279>/DTConv_UFix_To_Single_2' incorporates:
     *  Lookup2D: '<S292>/Look-Up Table (2-D)'
     */
    localSwitch2_o = ((Float32)localLookUpTable2D_m) * 1.000000047E-003F;

    /* Sum: '<S279>/Add1' incorporates:
     *  Product: '<S295>/Divide'
     *  Product: '<S296>/Divide'
     */
    localfractionTmp_0d = (localDTConv_UFix_To_Single_12 *
      localDTConv_UFix_To_Single_2_n) - (localSwitch2_o *
      localDTConv_UFix_To_Single_12);

    /* If: '<S293>/If' incorporates:
     *  ActionPort: '<S297>/Action Port'
     *  DataStoreRead: '<S293>/GT'
     *  SubSystem: '<S293>/F01_MP'
     */
    if (localDW->AcvMP_bEngMdl) {
      /* DataStoreWrite: '<S297>/MP' */
      AirEfc_rFuStmMass_MP = localSwitch2_o;
    }

    /* end of Outputs for SubSystem: '<S275>/F03_Offset_of_Fuel_Mass_and_timing_effect' */
  } else {
    /* Constant: '<S276>/ConstVal' */
    localDTConv_UFix_To_Single_12 = 0.0F;

    /* Constant: '<S276>/ConstVal_2' */
    localfractionTmp_0d = 0.0F;

    /* SignalConversion: '<S276>/Signal Conversion1' */
    localSum_h = rtu_In_InjSys_agInj1EndRef;
  }

  /* end of Outputs for SubSystem: '<S9>/F12_Gasoline_direct_injection_offset' */

  /* Outputs for atomic SubSystem: '<S9>/F09_offset_air_load' *
   * Block requirements for '<S9>/F09_offset_air_load':
   *  1. SubSystem "F09_offset_air_load" !Trace_To : VEMS_R_11_00996_055.02 ;
   */

  /* Product: '<S267>/Divide' */
  localfractionTmp_0d *= localInterpolationUsingPreloo_b;

  /* end of Outputs for SubSystem: '<S9>/F09_offset_air_load' */

  /* end of Outputs for SubSystem: '<S8>/LibAirEfc' */

  /* SignalConversion: '<S8>/a' */
  (*rty_Out_AirEfc_rMassBurn) = localSum_ht;

  /* SignalConversion: '<S8>/a1' incorporates:
   *  Constant: '<S22>/ConstVal'
   */
  (*rty_Out_AirEfc_rMassAirResi) = 0.0F;

  /* SignalConversion: '<S8>/a10' */
  (*rty_Out_AirEfc_facChrExpScvFil) = localB->SignalConversion3;

  /* SignalConversion: '<S8>/a11' */
  (*rty_Out_AirEfc_facMassAirScv) = localB->Merge2;

  /* SignalConversion: '<S8>/a12' */
  (*rty_Out_AirEfc_agInj1End) = localSum_h;

  /* SignalConversion: '<S8>/a13' */
  (*rty_Out_AirEfc_rFuMassInj1InPha) = localDTConv_UFix_To_Single_12;

  /* SignalConversion: '<S8>/a14' */
  (*rty_Out_AirEfc_rDeltaLdInjPhaRe) = localfractionTmp_0d;

  /* SignalConversion: '<S8>/a15' */
  (*rty_Out_AirEfc_facTAirUsInVlv) = localInterpolationUsingPreloo_b;

  /* SignalConversion: '<S8>/a16' */
  (*rty_Out_AirEfc_facTCo) = localInterpolationUsingPrelooku;

  /* SignalConversion: '<S8>/a17' */
  (*rty_Out_AirEfc_facCorAtmSlopEfc) = localInterpolationUsingPreloo_k;

  /* SignalConversion: '<S8>/a18' */
  (*rty_Out_AirEfc_facCorBoostSlopE) = localInterpolationUsingPrelo_cw;

  /* SignalConversion: '<S8>/a19' */
  (*rty_Out_AirEfc_pBegCorBoostSlop) = localInterpolationUsingPreloo_c;

  /* SignalConversion: '<S8>/a2' */
  (*rty_Out_AirEfc_facSlopEfc) = localDivide_nd;

  /* SignalConversion: '<S8>/a20' */
  (*rty_Out_AirEfc_pDeltaCorSlopEfc) = localDTConv_UFix_To_Single_1_b;

  /* SignalConversion: '<S8>/a3' incorporates:
   *  Product: '<S268>/Divide'
   *  Product: '<S269>/Divide'
   *  Sum: '<S21>/Add2'
   *  Sum: '<S21>/Add3'
   */
  (*rty_Out_AirEfc_facOfsEfc) = (((localInterpolationUsingPreloo_b *
    localMinMax_jq) * localSum_ht) + localfractionTmp_0d) + localSwitch;

  /* SignalConversion: '<S8>/a4' */
  (*rty_Out_AirEfc_rMassAirScv) = localB->Merge3;

  /* SignalConversion: '<S8>/a5' incorporates:
   *  Product: '<S71>/Divide'
   */
  (*rty_Out_AirEfc_pDsThrCorClsInVl) = localDTConv_UFix_To_Single_5 * localSum_o;

  /* SignalConversion: '<S8>/a6' */
  (*rty_Out_AirEfc_tBurnCyl) = localDTConv_UFix_To_Single_1_pv;

  /* SignalConversion: '<S8>/a7' */
  (*rty_Out_AirEfc_rVolCylClsInVlv) = localDTConv_Single_To_UFix_16;

  /* SignalConversion: '<S8>/a8' */
  (*rty_Out_AirEfc_facMassFlowLd) = localDivide_pl;

  /* SignalConversion: '<S8>/a9' */
  (*rty_Out_AirEfc_facChrExpFil) = localB->SignalConversion3_n;
}

/* Start for exported function: OP_LibAirEfc */
void OP_LibAirEfc_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/OP_LibAirEfc'
   *
   * Block requirements for '<S1>/OP_LibAirEfc':
   *  1. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_099.01 ;
   *  2. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_100.01 ;
   *  3. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_101.01 ;
   *  4. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_102.02 ;
   *  5. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_103.01 ;
   *  6. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_104.01 ;
   *  7. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_105.01 ;
   *  8. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_106.01 ;
   *  9. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_107.01 ;
   *  10. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_108.01 ;
   *  11. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_109.01 ;
   *  12. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_110.01 ;
   *  13. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_111.01 ;
   *  14. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_112.01 ;
   *  15. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_113.01 ;
   *  16. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_114.01 ;
   *  17. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_115.01 ;
   *  18. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_116.01 ;
   *  19. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_117.01 ;
   *  20. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_118.01 ;
   *  21. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_119.01 ;
   *  22. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_120.01 ;
   *  23. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_121.01 ;
   *  24. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_122.01 ;
   *  25. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_123.01 ;
   *  26. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_124.01 ;
   *  27. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_125.01 ;
   *  28. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_126.01 ;
   *  29. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_127.01 ;
   *  30. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_128.01 ;
   *  31. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_129.01 ;
   *  32. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_130.01 ;
   *  33. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_131.01 ;
   *  34. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_132.01 ;
   *  35. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_133.01 ;
   *  36. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_134.01 ;
   *  37. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_021.03 ;
   *  38. SubSystem "OP_LibAirEfc" !Trace_To : VEMS_R_11_00996_168.01 ;
   */
}



/* Output and update for atomic system: '<S6>/Subsystem' */
void Subsystem_o(UInt8 rtu_In_EngM_noAcvMPVal, Float32
                 rtu_In_AirEfc_rMassBurn, Float32 rtu_In_AirEfc_rMassAirResi,
                 Float32 rtu_In_InM_concAir, UInt16 rtu_In_Ext_nEngRef,
                 UInt16 rtu_In_InM_pDsThr, Float32 rtu_In_AirEfc_facSlopEfc,
                 Float32 rtu_In_AirEfc_facOfsEfc, UInt16
                 rtu_In_InM_tAirUsInVlvEstimRef, Float32
                 rtu_In_AirEfc_agInj1End, Float32 rtu_In_EngM_agCkClsInVlvRef1,
                 UInt16 rtu_In_InjSys_tFuRef, Float32
                 rtu_In_AirEfc_rFuMassInj1InPha, Float32 rtu_In_AirEfc_tBurnCyl,
                 Float32 rtu_In_AirEfc_pDsThrCorClsInVlv, Float32
                 rtu_In_AirEfc_rVolCylClsInVlv, Float32
                 rtu_In_AirEfc_rMassAirScv, Float32 rtu_In_AirEfc_facMassFlowLd,
                 Float32 *rty_Out_EngM_rItBurnRate, Float32
                 *rty_Out_EngM_tMixtCyl, Float32 *rty_Out_EngM_mAirScv,
                 Float32 *rty_Out_EngM_tMixtCylGDI, Float32
                 *rty_Out_EngM_rltMassAirScv, Float32 *rty_Out_EngM_rAirLd,
                 Float32 *rty_Out_EngM_rTotLdEx, Float32
                 *rty_Out_EngM_mfAirScv, Float32 *rty_Out_EngM_mAir, Float32
                 *rty_Out_EngM_mfAir, Float32 *rty_Out_EngM_mTotEx, Float32
                 *rty_Out_EngM_mfTotEx, Float32 *rty_Out_EngM_mBurn,
                 rtB_Subsystem_AirEfcEngCylPrm_l *localB,
                 rtDW_Subsystem_AirEfcEngCylPr_p *localDW)
{
  /* local block i/o variables */
  UInt16 localDTConv_UFix_To_Single_7;
  UInt16 localLookUpTable_d;
  Float32 localSum2_l;
  Float32 localDTConv_UFix_To_Single_1_p2;
  Float32 localMerge2_n;
  Float32 localmax;
  Float32 localDTConv_UFix_To_Single_4_n;
  Float32 localInterpolationUsingPreloo_d;
  Float32 localfrac[2];
  Float32 localPrelookup_o2_j3;
  SInt32 localPrelookup_o1_ie;
  SInt32 localbpIndex[2];
  SInt32 localPrelookup_o1_ij;
  Float32 localSum3_a;
  Float32 localDTConv_UFix_To_Single_2_o;
  Float32 localInterpolationUsingPrelo_it;
  Float32 localfrac_0[2];
  SInt32 localbpIndex_0[2];
  Float32 localDivide_if;
  Float32 localDivide_fq;
  Float32 localDivide_bb;
  Float32 localDivide_bt;
  Float32 localSum1_k;
  SInt16 locallocalOutDTConv_p;

  /* Outputs for atomic SubSystem: '<S301>/LibEngCylPrm' *
   * Block requirements for '<S301>/LibEngCylPrm':
   *  1. SubSystem "LibEngCylPrm" !Trace_To : VEMS_R_11_00996_002.01 ;
   */

  /* DataStoreWrite: '<S302>/GT' incorporates:
   *  Constant: '<S302>/AcvMP_noEngMdl_C'
   *  RelationalOperator: '<S302>/Relational Operator'
   */
  localDW->AcvMP_bEngMdl = (AcvMP_noEngMdl_C == rtu_In_EngM_noAcvMPVal);

  /* DataTypeConversion: '<S302>/DTConv_UFix_To_Single_1' incorporates:
   *  Constant: '<S302>/EngM_mRef_C'
   */
  localDTConv_UFix_To_Single_1_p2 = ((Float32)EngM_mRef_C) * 1.192016583E-007F;

  /* Outputs for atomic SubSystem: '<S302>/F01_cylinder_mass_estimation' *
   * Block requirements for '<S302>/F01_cylinder_mass_estimation':
   *  1. SubSystem "F01_cylinder_mass_estimation" !Trace_To : VEMS_R_11_00996_003.01 ;
   */

  /* If: '<S304>/If' incorporates:
   *  ActionPort: '<S317>/Action Port'
   *  ActionPort: '<S318>/Action Port'
   *  Constant: '<S304>/EngM_bTotLdEx_C'
   *  SubSystem: '<S304>/F01_1_EngM_rTotLdExMax_MP_IF'
   *  SubSystem: '<S304>/F01_2_EngM_rTotLdExMax_MP_ELSE'
   */
  if (EngM_bTotLdEx_C) {
    /* PreLookup: '<S322>/Prelookup' */
    localPrelookup_o1_ie = plook_s32u16f_bincpa(rtu_In_Ext_nEngRef,
      (&(EngM_nEngY_A[0])), 17U, &localInterpolationUsingPreloo_d,
      &localDW->Prelookup_DWORK1_d);

    /* PreLookup: '<S323>/Prelookup' */
    localPrelookup_o1_ij = plook_s32u16f_bincpa(rtu_In_InM_pDsThr,
      (&(EngM_pDsThr_A[0])), 15U, &localPrelookup_o2_j3,
      &localDW->Prelookup_DWORK1_k);

    /* Interpolation_n-D: '<S324>/Interpolation Using Prelookup3' */
    localMerge2_n = localInterpolationUsingPreloo_d;
    localfrac[0] = localMerge2_n;
    localMerge2_n = localPrelookup_o2_j3;
    localfrac[1] = localMerge2_n;
    localbpIndex[0] = localPrelookup_o1_ie;
    localbpIndex[1] = localPrelookup_o1_ij;
    localInterpolationUsingPreloo_d = intrp2d_iu16n14ff_s32f_la_ns(localbpIndex,
      localfrac, (&(EngM_rTotLdEx_M[0])), 18U,
      &AirEfcEngCylPrmT_ConstP.pooled11[0]);

    /* SignalConversion: '<S317>/Signal Conversion1' */
    localMerge2_n = localInterpolationUsingPreloo_d;
  } else {
    /* Sum: '<S318>/Sum1' incorporates:
     *  DataTypeConversion: '<S318>/DTConv_UFix_To_Single_1'
     *  Product: '<S325>/Divide'
     */
    localMerge2_n = ((((Float32)rtu_In_InM_pDsThr) * 8.0F) *
                     rtu_In_AirEfc_facSlopEfc) - rtu_In_AirEfc_facOfsEfc;
  }

  /* If: '<S315>/If' incorporates:
   *  ActionPort: '<S320>/Action Port'
   *  DataStoreRead: '<S315>/GT'
   *  SubSystem: '<S315>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S320>/MP' */
    EngM_rTotLdExMax_MP = localMerge2_n;
  }

  /* MinMax: '<S304>/MinMax' incorporates:
   *  Constant: '<S304>/EngM_rTotLdExMin_C'
   */
  localmax = rt_MAXf(localMerge2_n, ((Float32)EngM_rTotLdExMin_C) *
                     6.103515625E-005F);

  /* Sum: '<S304>/Sum3' */
  localSum3_a = (localmax + rtu_In_AirEfc_rMassBurn) +
    rtu_In_AirEfc_rMassAirResi;

  /* If: '<S316>/If' incorporates:
   *  ActionPort: '<S321>/Action Port'
   *  DataStoreRead: '<S316>/GT'
   *  SubSystem: '<S316>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S321>/MP' */
    EngM_rTotLd_MP = localSum3_a;
  }

  /* Sum: '<S304>/Sum2' incorporates:
   *  Product: '<S319>/Divide'
   */
  localSum2_l = (localmax * rtu_In_InM_concAir) + rtu_In_AirEfc_rMassAirResi;

  /* end of Outputs for SubSystem: '<S302>/F01_cylinder_mass_estimation' */

  /* Outputs for atomic SubSystem: '<S302>/F02_internal_burn_rate' *
   * Block requirements for '<S302>/F02_internal_burn_rate':
   *  1. SubSystem "F02_internal_burn_rate" !Trace_To : VEMS_R_11_00996_004.01 ;
   */

  /* Outputs for enable SubSystem: '<S305>/F01_internal_burn_rate_With_Out_Fuel' incorporates:
   *  Constant: '<S305>/EngM_bItBurnRate_C'
   *  EnablePort: '<S326>/Enable'
   *
   * Block requirements for '<S305>/F01_internal_burn_rate_With_Out_Fuel':
   *  1. SubSystem "F01_internal_burn_rate_With_Out_Fuel" !Trace_To : VEMS_R_11_00996_005.01 ;
   */
  if (EngM_bItBurnRate_C) {
    /* Product: '<S328>/Divide' */
    localMerge2_n = rtu_In_AirEfc_rMassBurn / localSum3_a;

    /* Outputs for atomic SubSystem: '<S328>/If Action Subsystem3' */

    /* Switch: '<S330>/Switch1' incorporates:
     *  Constant: '<S330>/Constant1'
     *  Constant: '<S330>/Constant2'
     *  Constant: '<S330>/Constant3'
     *  DataTypeConversion: '<S328>/Data Type Conversion2'
     *  Logic: '<S330>/Logical Operator1'
     *  RelationalOperator: '<S330>/Relational Operator'
     *  RelationalOperator: '<S330>/Relational Operator1'
     *  RelationalOperator: '<S330>/Relational Operator3'
     */
    if (((localMerge2_n != localMerge2_n) || (localMerge2_n > 3.000000005E+038F))
        || (-3.000000005E+038F > localMerge2_n)) {
      localB->Merge = 0.0F;
    } else {
      localB->Merge = localMerge2_n;
    }

    /* end of Outputs for SubSystem: '<S328>/If Action Subsystem3' */
  }

  /* end of Outputs for SubSystem: '<S305>/F01_internal_burn_rate_With_Out_Fuel' */

  /* Outputs for enable SubSystem: '<S305>/F02_internal_burn_rate_With_Fuel' incorporates:
   *  Constant: '<S305>/EngM_bItBurnRate_C_2'
   *  EnablePort: '<S327>/Enable'
   *  Logic: '<S305>/Logical Operator1'
   *
   * Block requirements for '<S305>/F02_internal_burn_rate_With_Fuel':
   *  1. SubSystem "F02_internal_burn_rate_With_Fuel" !Trace_To : VEMS_R_11_00996_006.01 ;
   */
  if (!EngM_bItBurnRate_C) {
    /* Product: '<S331>/Divide' incorporates:
     *  Constant: '<S327>/EngM_facStoich_C'
     *  DataTypeConversion: '<S327>/DTConv_UFix_To_Single_1'
     */
    localMerge2_n = localSum2_l / ((((Float32)EngM_facStoich_C) *
      1.000000047E-003F) + 4.0F);

    /* Outputs for atomic SubSystem: '<S331>/If Action Subsystem3' */

    /* Switch: '<S334>/Switch1' incorporates:
     *  Constant: '<S334>/Constant1'
     *  Constant: '<S334>/Constant2'
     *  Constant: '<S334>/Constant3'
     *  Logic: '<S334>/Logical Operator1'
     *  RelationalOperator: '<S334>/Relational Operator'
     *  RelationalOperator: '<S334>/Relational Operator1'
     *  RelationalOperator: '<S334>/Relational Operator3'
     */
    if (((localMerge2_n != localMerge2_n) || (localMerge2_n > 3.000000005E+038F))
        || (-3.000000005E+038F > localMerge2_n)) {
      localMerge2_n = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S331>/If Action Subsystem3' */

    /* Product: '<S332>/Divide' incorporates:
     *  Sum: '<S327>/Sum2'
     */
    localMerge2_n = rtu_In_AirEfc_rMassBurn / (localMerge2_n + localSum3_a);

    /* Outputs for atomic SubSystem: '<S332>/If Action Subsystem3' */

    /* Switch: '<S336>/Switch1' incorporates:
     *  Constant: '<S336>/Constant1'
     *  Constant: '<S336>/Constant2'
     *  Constant: '<S336>/Constant3'
     *  DataTypeConversion: '<S332>/Data Type Conversion2'
     *  Logic: '<S336>/Logical Operator1'
     *  RelationalOperator: '<S336>/Relational Operator'
     *  RelationalOperator: '<S336>/Relational Operator1'
     *  RelationalOperator: '<S336>/Relational Operator3'
     */
    if (((localMerge2_n != localMerge2_n) || (localMerge2_n > 3.000000005E+038F))
        || (-3.000000005E+038F > localMerge2_n)) {
      localB->Merge = 0.0F;
    } else {
      localB->Merge = localMerge2_n;
    }

    /* end of Outputs for SubSystem: '<S332>/If Action Subsystem3' */
  }

  /* end of Outputs for SubSystem: '<S305>/F02_internal_burn_rate_With_Fuel' */

  /* end of Outputs for SubSystem: '<S302>/F02_internal_burn_rate' */

  /* Outputs for atomic SubSystem: '<S302>/F03_cylinder_mixture_temperature' *
   * Block requirements for '<S302>/F03_cylinder_mixture_temperature':
   *  1. SubSystem "F03_cylinder_mixture_temperature" !Trace_To : VEMS_R_11_00996_007.01 ;
   */

  /* DataTypeConversion: '<S306>/DTConv_UFix_To_Single_4' */
  localDTConv_UFix_To_Single_4_n = (((Float32)rtu_In_InM_tAirUsInVlvEstimRef) *
    0.0078125F) + 223.0F;

  /* Outputs for atomic SubSystem: '<S306>/F03_enthalpy_mixture_temperature_with_GDI' *
   * Block requirements for '<S306>/F03_enthalpy_mixture_temperature_with_GDI':
   *  1. SubSystem "F03_enthalpy_mixture_temperature_with_GDI" !Trace_To : VEMS_R_11_00996_010.01 ;
   */

  /* Sum: '<S339>/Add' */
  localMerge2_n = rtu_In_AirEfc_agInj1End - rtu_In_EngM_agCkClsInVlvRef1;

  /* PreLookup: '<S357>/Prelookup' */
  localPrelookup_o1_ie = plook_s32u16f_bincpa(rtu_In_Ext_nEngRef,
    (&(AirEfc_nEngY_A[0])), 17U, &localInterpolationUsingPrelo_it,
    &localDW->Prelookup_DWORK1);

  /* Product: '<S366>/Product4' incorporates:
   *  Constant: '<S366>/offset'
   *  Constant: '<S366>/one_on_slope'
   *  Sum: '<S366>/Add1'
   */
  localDTConv_UFix_To_Single_2_o = 10.0F * localMerge2_n;

  /* DataTypeConversion: '<S366>/OutDTConv' */
  localMerge2_n = localDTConv_UFix_To_Single_2_o;
  if (localMerge2_n < 32768.0F) {
    if (localMerge2_n >= -32768.0F) {
      locallocalOutDTConv_p = (SInt16)localMerge2_n;
    } else {
      locallocalOutDTConv_p = MIN_int16_T;
    }
  } else {
    locallocalOutDTConv_p = MAX_int16_T;
  }

  /* PreLookup: '<S358>/Prelookup' */
  localPrelookup_o1_ij = plook_s32s16f_bincpa(locallocalOutDTConv_p,
    (&(AirEfc_agInjPha_A[0])), 19U, &localDTConv_UFix_To_Single_2_o,
    &localDW->Prelookup_DWORK1_c);

  /* Interpolation_n-D: '<S359>/Interpolation Using Prelookup3' */
  localMerge2_n = localInterpolationUsingPrelo_it;
  localfrac_0[0] = localMerge2_n;
  localMerge2_n = localDTConv_UFix_To_Single_2_o;
  localfrac_0[1] = localMerge2_n;
  localbpIndex_0[0] = localPrelookup_o1_ie;
  localbpIndex_0[1] = localPrelookup_o1_ij;
  localInterpolationUsingPrelo_it = intrp2d_iu16n10ff_s32f_la_ns(localbpIndex_0,
    localfrac_0, (&(AirEfc_rFuStmMass_M[0])), 18U,
    &AirEfcEngCylPrmT_ConstP.InterpolationUsingP_a[0]);

  /* DataTypeConversion: '<S339>/DTConv_UFix_To_Single_7' */
  if (rtu_In_InjSys_tFuRef > 511) {
    localDTConv_UFix_To_Single_7 = MAX_uint16_T;
  } else {
    localDTConv_UFix_To_Single_7 = (UInt16)(rtu_In_InjSys_tFuRef << 7);
  }

  /* Lookup: '<S362>/Look-Up Table'
   * About '<S362>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
   * Output0 Data Type:  Fixed Point    U16  Bias 1000.0
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_d), (&(EngM_cppFu_T[0])),
                 localDTConv_UFix_To_Single_7, (&(AirEfc_tFu_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S362>/Data Type Duplicate1'
   *
   * Regarding '<S362>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S339>/DTConv_UFix_To_Single_2' incorporates:
   *  Lookup: '<S362>/Look-Up Table'
   */
  localDTConv_UFix_To_Single_2_o = ((Float32)localLookUpTable_d) + 1000.0F;

  /* Product: '<S370>/Divide' incorporates:
   *  Constant: '<S339>/EngM_cppAirBurn_C'
   *  DataTypeConversion: '<S339>/DTConv_UFix_To_Single_5'
   *  Sum: '<S339>/Sum2'
   */
  localDivide_if = ((((Float32)EngM_cppAirBurn_C) * 1.171875F) + 1050.0F) *
    (rtu_In_AirEfc_rMassAirResi + rtu_In_AirEfc_rMassBurn);

  /* If: '<S360>/If' incorporates:
   *  ActionPort: '<S377>/Action Port'
   *  DataStoreRead: '<S360>/GT'
   *  SubSystem: '<S360>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S377>/MP' */
    EngM_SumcppBurnMass_MP = localDivide_if;
  }

  /* Product: '<S374>/Divide' */
  localDivide_fq = rtu_In_AirEfc_rFuMassInj1InPha *
    localDTConv_UFix_To_Single_2_o;

  /* Product: '<S369>/Divide' incorporates:
   *  Constant: '<S339>/EngM_cppAir_C'
   *  DataTypeConversion: '<S339>/DTConv_UFix_To_Single_3'
   */
  localMerge2_n = ((((Float32)EngM_cppAir_C) * 0.1953125F) + 1000.0F) *
    localmax;

  /* Sum: '<S339>/Sum1' */
  localSum1_k = (localDivide_if + localDivide_fq) + localMerge2_n;

  /* If: '<S361>/If' incorporates:
   *  ActionPort: '<S378>/Action Port'
   *  DataStoreRead: '<S361>/GT'
   *  SubSystem: '<S361>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S378>/MP' */
    EngM_SumcppMass_MP = localSum1_k;
  }

  /* Product: '<S372>/Divide' */
  localDivide_bb = localMerge2_n * localDTConv_UFix_To_Single_4_n;

  /* If: '<S363>/If' incorporates:
   *  ActionPort: '<S379>/Action Port'
   *  DataStoreRead: '<S363>/GT'
   *  SubSystem: '<S363>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S379>/MP' */
    EngM_facAirtMixt_MP = localDivide_bb;
  }

  /* Product: '<S375>/Divide' */
  localMerge2_n = localDTConv_UFix_To_Single_2_o *
    localInterpolationUsingPrelo_it;

  /* Product: '<S368>/Divide' incorporates:
   *  Constant: '<S339>/AirEfc_tRef_C'
   *  DataTypeConversion: '<S339>/DTConv_UFix_To_Single_6'
   *  Product: '<S376>/Divide'
   */
  localDivide_bt = ((((Float32)AirEfc_tRef_C) * 0.0078125F) * localMerge2_n) *
    rtu_In_AirEfc_rFuMassInj1InPha;

  /* If: '<S364>/If' incorporates:
   *  ActionPort: '<S380>/Action Port'
   *  DataStoreRead: '<S364>/GT'
   *  SubSystem: '<S364>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S380>/MP' */
    EngM_facFuSteam_MP = localDivide_bt;
  }

  /* Product: '<S373>/Divide' */
  localMerge2_n = (Float32)((((Float32d)rtu_In_InjSys_tFuRef) + 223.0F) * ((Float32d)
    localDivide_fq));

  /* If: '<S365>/If' incorporates:
   *  ActionPort: '<S381>/Action Port'
   *  DataStoreRead: '<S365>/GT'
   *  SubSystem: '<S365>/F01_MP'
   */
  if (localDW->AcvMP_bEngMdl) {
    /* DataStoreWrite: '<S381>/MP' */
    EngM_facFutMixt_MP = localMerge2_n;
  }

  /* Product: '<S367>/Divide' incorporates:
   *  Product: '<S371>/Divide'
   *  Sum: '<S339>/Sum3'
   */
  localDivide_bb = (((localDivide_bb + localMerge2_n) - localDivide_bt) +
                    (rtu_In_AirEfc_tBurnCyl * localDivide_if)) / localSum1_k;

  /* Outputs for atomic SubSystem: '<S367>/If Action Subsystem3' */

  /* Switch: '<S383>/Switch1' incorporates:
   *  Constant: '<S383>/Constant1'
   *  Constant: '<S383>/Constant2'
   *  Constant: '<S383>/Constant3'
   *  Logic: '<S383>/Logical Operator1'
   *  RelationalOperator: '<S383>/Relational Operator'
   *  RelationalOperator: '<S383>/Relational Operator1'
   *  RelationalOperator: '<S383>/Relational Operator3'
   */
  if (((localDivide_bb != localDivide_bb) || (localDivide_bb > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_bb)) {
    localDivide_bb = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S367>/If Action Subsystem3' */

  /* end of Outputs for SubSystem: '<S306>/F03_enthalpy_mixture_temperature_with_GDI' */

  /* If: '<S306>/If' incorporates:
   *  ActionPort: '<S337>/Action Port'
   *  ActionPort: '<S338>/Action Port'
   *  Constant: '<S306>/AirEfc_bTMixtCylGDI_C'
   *  SubSystem: '<S306>/F01_EngM_tMixtCyl_IF'
   *  SubSystem: '<S306>/F02_EngM_tMixtCyl_ELSE'
   */
  if (AirEfc_bTMixtCylGDI_C) {
    /* SignalConversion: '<S337>/Signal Conversion2' */
    localB->Merge2 = localDivide_bb;
  } else {
    /* Outputs for enable SubSystem: '<S338>/F01_enthalpy_mixture_temperature' incorporates:
     *  Constant: '<S338>/EngM_bTMixtCyl_C'
     *  EnablePort: '<S340>/Enable'
     *
     * Block requirements for '<S338>/F01_enthalpy_mixture_temperature':
     *  1. SubSystem "F01_enthalpy_mixture_temperature" !Trace_To : VEMS_R_11_00996_008.01 ;
     */
    if (EngM_bTMixtCyl_C) {
      /* Product: '<S344>/Divide' incorporates:
       *  Constant: '<S340>/EngM_cppAir_C'
       *  DataTypeConversion: '<S340>/DTConv_UFix_To_Single_2'
       */
      localMerge2_n = ((((Float32)EngM_cppAir_C) * 0.1953125F) + 1000.0F) *
        localmax;

      /* Product: '<S345>/Divide' incorporates:
       *  Constant: '<S340>/EngM_cppAirBurn_C'
       *  DataTypeConversion: '<S340>/DTConv_UFix_To_Single_1'
       *  Sum: '<S340>/Sum2'
       */
      localDivide_fq = ((((Float32)EngM_cppAirBurn_C) * 1.171875F) + 1050.0F) *
        (rtu_In_AirEfc_rMassAirResi + rtu_In_AirEfc_rMassBurn);

      /* Product: '<S342>/Divide' incorporates:
       *  Product: '<S343>/Divide'
       *  Product: '<S346>/Divide'
       *  Sum: '<S340>/Sum1'
       *  Sum: '<S340>/Sum3'
       */
      localMerge2_n = ((localMerge2_n * localDTConv_UFix_To_Single_4_n) +
                       (rtu_In_AirEfc_tBurnCyl * localDivide_fq)) /
        (localDivide_fq + localMerge2_n);

      /* Outputs for atomic SubSystem: '<S342>/If Action Subsystem3' */

      /* Switch: '<S348>/Switch1' incorporates:
       *  Constant: '<S348>/Constant1'
       *  Constant: '<S348>/Constant2'
       *  Constant: '<S348>/Constant3'
       *  DataTypeConversion: '<S342>/Data Type Conversion2'
       *  Logic: '<S348>/Logical Operator1'
       *  RelationalOperator: '<S348>/Relational Operator'
       *  RelationalOperator: '<S348>/Relational Operator1'
       *  RelationalOperator: '<S348>/Relational Operator3'
       */
      if (((localMerge2_n != localMerge2_n) || (localMerge2_n >
            3.000000005E+038F)) || (-3.000000005E+038F > localMerge2_n)) {
        localB->Merge2 = 0.0F;
      } else {
        localB->Merge2 = localMerge2_n;
      }

      /* end of Outputs for SubSystem: '<S342>/If Action Subsystem3' */
    }

    /* end of Outputs for SubSystem: '<S338>/F01_enthalpy_mixture_temperature' */

    /* Outputs for enable SubSystem: '<S338>/F02_gp_mixture_temperature' incorporates:
     *  Constant: '<S338>/EngM_bTMixtCyl_C_2'
     *  EnablePort: '<S341>/Enable'
     *  Logic: '<S338>/Logical Operator'
     *
     * Block requirements for '<S338>/F02_gp_mixture_temperature':
     *  1. SubSystem "F02_gp_mixture_temperature" !Trace_To : VEMS_R_11_00996_009.01 ;
     */
    if (!EngM_bTMixtCyl_C) {
      /* Product: '<S349>/Divide' incorporates:
       *  Constant: '<S341>/AirEfc_pRef_C'
       *  DataTypeConversion: '<S341>/DTConv_UFix_To_Single_1'
       */
      localMerge2_n = rtu_In_AirEfc_pDsThrCorClsInVlv / (((Float32)
        AirEfc_pRef_C) * 8.0F);

      /* Outputs for atomic SubSystem: '<S349>/If Action Subsystem3' */

      /* Switch: '<S354>/Switch1' incorporates:
       *  Constant: '<S354>/Constant1'
       *  Constant: '<S354>/Constant2'
       *  Constant: '<S354>/Constant3'
       *  Logic: '<S354>/Logical Operator1'
       *  RelationalOperator: '<S354>/Relational Operator'
       *  RelationalOperator: '<S354>/Relational Operator1'
       *  RelationalOperator: '<S354>/Relational Operator3'
       */
      if (((localMerge2_n != localMerge2_n) || (localMerge2_n >
            3.000000005E+038F)) || (-3.000000005E+038F > localMerge2_n)) {
        localMerge2_n = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S349>/If Action Subsystem3' */

      /* Product: '<S350>/Divide' incorporates:
       *  Product: '<S351>/Divide'
       */
      localMerge2_n = (localMerge2_n * rtu_In_AirEfc_rVolCylClsInVlv) /
        localSum3_a;

      /* Outputs for atomic SubSystem: '<S350>/If Action Subsystem3' */

      /* Switch: '<S356>/Switch1' incorporates:
       *  Constant: '<S356>/Constant1'
       *  Constant: '<S356>/Constant2'
       *  Constant: '<S356>/Constant3'
       *  Logic: '<S356>/Logical Operator1'
       *  RelationalOperator: '<S356>/Relational Operator'
       *  RelationalOperator: '<S356>/Relational Operator1'
       *  RelationalOperator: '<S356>/Relational Operator3'
       */
      if (((localMerge2_n != localMerge2_n) || (localMerge2_n >
            3.000000005E+038F)) || (-3.000000005E+038F > localMerge2_n)) {
        localMerge2_n = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S350>/If Action Subsystem3' */

      /* Product: '<S352>/Divide' incorporates:
       *  Constant: '<S341>/AirEfc_tRef_C'
       *  DataTypeConversion: '<S341>/DTConv_UFix_To_Single_2'
       */
      localB->Merge2 = (((Float32)AirEfc_tRef_C) * 0.0078125F) * localMerge2_n;
    }

    /* end of Outputs for SubSystem: '<S338>/F02_gp_mixture_temperature' */
  }

  /* end of Outputs for SubSystem: '<S302>/F03_cylinder_mixture_temperature' */

  /* Outputs for atomic SubSystem: '<S302>/F05_scavenged_air_massflow' *
   * Block requirements for '<S302>/F05_scavenged_air_massflow':
   *  1. SubSystem "F05_scavenged_air_massflow" !Trace_To : VEMS_R_11_00996_012.01 ;
   */

  /* Product: '<S385>/Divide' */
  localMerge2_n = rtu_In_AirEfc_rMassAirScv * rtu_In_AirEfc_facMassFlowLd;

  /* end of Outputs for SubSystem: '<S302>/F05_scavenged_air_massflow' */

  /* Outputs for atomic SubSystem: '<S302>/F07_fresh_air_massflow' *
   * Block requirements for '<S302>/F07_fresh_air_massflow':
   *  1. SubSystem "F07_fresh_air_massflow" !Trace_To : VEMS_R_11_00996_014.01 ;
   */

  /* Product: '<S387>/Divide' */
  localDivide_fq = localSum2_l * rtu_In_AirEfc_facMassFlowLd;

  /* end of Outputs for SubSystem: '<S302>/F07_fresh_air_massflow' */

  /* Outputs for atomic SubSystem: '<S302>/F11_Scavenged_air_ratio' *
   * Block requirements for '<S302>/F11_Scavenged_air_ratio':
   *  1. SubSystem "F11_Scavenged_air_ratio" !Trace_To : VEMS_R_11_00996_018.01 ;
   */

  /* Outputs for enable SubSystem: '<S314>/F01_Scavenged_air_ratio_Cal' incorporates:
   *  Constant: '<S314>/AirEfc_nEngThdVal_C'
   *  EnablePort: '<S391>/Enable'
   *  EnablePort: '<S392>/Enable'
   *  Logic: '<S314>/Logical Operator'
   *  RelationalOperator: '<S314>/Relational Operator'
   *  SubSystem: '<S314>/F02_Scavenged_air_ratio_Ini'
   *
   * Block requirements for '<S314>/F01_Scavenged_air_ratio_Cal':
   *  1. SubSystem "F01_Scavenged_air_ratio_Cal" !Trace_To : VEMS_R_11_00996_019.01 ;
   *
   * Block requirements for '<S314>/F02_Scavenged_air_ratio_Ini':
   *  1. SubSystem "F02_Scavenged_air_ratio_Ini" !Trace_To : VEMS_R_11_00996_020.01 ;
   */
  if (rtu_In_Ext_nEngRef >= AirEfc_nEngThdVal_C) {
    /* Product: '<S393>/Divide' incorporates:
     *  Sum: '<S391>/Sum'
     */
    localDivide_bt = localMerge2_n / (localMerge2_n + localDivide_fq);

    /* Outputs for atomic SubSystem: '<S393>/If Action Subsystem3' */

    /* Switch: '<S395>/Switch1' incorporates:
     *  Constant: '<S395>/Constant1'
     *  Constant: '<S395>/Constant2'
     *  Constant: '<S395>/Constant3'
     *  Logic: '<S395>/Logical Operator1'
     *  RelationalOperator: '<S395>/Relational Operator'
     *  RelationalOperator: '<S395>/Relational Operator1'
     *  RelationalOperator: '<S395>/Relational Operator3'
     */
    if (((localDivide_bt != localDivide_bt) || (localDivide_bt >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_bt)) {
      localDivide_bt = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S393>/If Action Subsystem3' */
  } else {
    /* Constant: '<S392>/ConstVal' */
    localDivide_bt = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S314>/F01_Scavenged_air_ratio_Cal' */

  /* end of Outputs for SubSystem: '<S302>/F11_Scavenged_air_ratio' */

  /* end of Outputs for SubSystem: '<S301>/LibEngCylPrm' */

  /* SignalConversion: '<S301>/a' */
  (*rty_Out_EngM_rItBurnRate) = localB->Merge;

  /* SignalConversion: '<S301>/a1' */
  (*rty_Out_EngM_tMixtCyl) = localB->Merge2;

  /* SignalConversion: '<S301>/a10' incorporates:
   *  Product: '<S390>/Divide'
   */
  (*rty_Out_EngM_mAirScv) = rtu_In_AirEfc_rMassAirScv *
    localDTConv_UFix_To_Single_1_p2;

  /* SignalConversion: '<S301>/a11' */
  (*rty_Out_EngM_tMixtCylGDI) = localDivide_bb;

  /* SignalConversion: '<S301>/a12' */
  (*rty_Out_EngM_rltMassAirScv) = localDivide_bt;

  /* SignalConversion: '<S301>/a2' */
  (*rty_Out_EngM_rAirLd) = localSum2_l;

  /* SignalConversion: '<S301>/a3' */
  (*rty_Out_EngM_rTotLdEx) = localmax;

  /* SignalConversion: '<S301>/a4' */
  (*rty_Out_EngM_mfAirScv) = localMerge2_n;

  /* SignalConversion: '<S301>/a5' incorporates:
   *  Product: '<S386>/Divide'
   */
  (*rty_Out_EngM_mAir) = localSum2_l * localDTConv_UFix_To_Single_1_p2;

  /* SignalConversion: '<S301>/a6' */
  (*rty_Out_EngM_mfAir) = localDivide_fq;

  /* SignalConversion: '<S301>/a7' incorporates:
   *  Product: '<S388>/Divide'
   */
  (*rty_Out_EngM_mTotEx) = localmax * localDTConv_UFix_To_Single_1_p2;

  /* SignalConversion: '<S301>/a8' incorporates:
   *  Product: '<S384>/Divide'
   *  Sum: '<S307>/Sum3'
   */
  (*rty_Out_EngM_mfTotEx) = (localmax + rtu_In_AirEfc_rMassAirScv) *
    rtu_In_AirEfc_facMassFlowLd;

  /* SignalConversion: '<S301>/a9' incorporates:
   *  Product: '<S389>/Divide'
   */
  (*rty_Out_EngM_mBurn) = rtu_In_AirEfc_rMassBurn *
    localDTConv_UFix_To_Single_1_p2;
}

/* Start for exported function: OP_LibEngCylPrm */
void OP_LibEngCylPrm_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/OP_LibEngCylPrm'
   *
   * Block requirements for '<S1>/OP_LibEngCylPrm':
   *  1. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_135.01 ;
   *  2. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_136.01 ;
   *  3. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_137.01 ;
   *  4. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_138.01 ;
   *  5. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_139.01 ;
   *  6. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_140.01 ;
   *  7. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_141.01 ;
   *  8. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_142.01 ;
   *  9. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_143.01 ;
   *  10. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_144.01 ;
   *  11. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_145.01 ;
   *  12. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_146.01 ;
   *  13. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_147.01 ;
   *  14. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_148.01 ;
   *  15. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_149.01 ;
   *  16. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_150.01 ;
   *  17. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_151.01 ;
   *  18. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_152.01 ;
   *  19. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_153.01 ;
   *  20. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_154.01 ;
   *  21. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_155.01 ;
   *  22. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_156.01 ;
   *  23. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_157.01 ;
   *  24. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_158.01 ;
   *  25. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_159.01 ;
   *  26. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_160.01 ;
   *  27. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_161.01 ;
   *  28. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_162.01 ;
   *  29. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_163.01 ;
   *  30. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_164.01 ;
   *  31. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_165.01 ;
   *  32. SubSystem "OP_LibEngCylPrm" !Trace_To : VEMS_R_11_00996_001.01 ;
   */
}



/* Output and update for atomic system: '<S7>/Subsystem' */
void Subsystem_a(UInt8 rtu_In_EngM_noAcvVlvMPVal, UInt32 rtu_In_EOM_tiEngRun,
                 SInt16 rtu_In_Ext_tCoStrtMes, Float32
                 rtu_In_EngM_dstInVlvClrCor, Float32 rtu_In_AFA_agCkOpInVlvOfs,
                 Float32 rtu_In_EngM_agCkOpInVlvRef0, Float32
                 rtu_In_EngM_dstExVlvClrCor, Float32 rtu_In_AFA_agCkClsExVlvOfs,
                 Float32 rtu_In_EngM_agCkClsExVlvRef0, Float32
                 *rty_Out_EngM_agCkOpInVlvRef1, Float32
                 *rty_Out_EngM_agCkClsInVlvRef1, Float32
                 *rty_Out_EngM_agCkClsInVlvRef0, Float32
                 *rty_Out_EngM_agCkClsExVlvRef1, Float32
                 *rty_Out_EngM_agCkOpExVlvRef1, Float32
                 *rty_Out_EngM_agCkOpExVlvRef0, Float32
                 *rty_Out_EngM_agCkClsExVlvOfsRef, Float32
                 *rty_Out_EngM_agCkOpInVlvOfsRef0,
                 rtDW_Subsystem_AirEfcEngCylPr_h *localDW)
{
  Float32 localSubtract5_f;
  Float32 localSwitch_d;
  Float32 localSwitch_hf;
  Float32 localDTConv_UFix_To_Single_12_k;
  Float32 localDTConv_UFix_To_Single_1_d;
  Float32 localDTConv_UFix_To_Single_2_h;
  Float32 localPrelookup_o2_p;
  SInt32 localPrelookup_o1_fw;
  Float32 localDTConv_UFix_To_Single_12_p;
  Float32 localDTConv_UFix_To_Single_1_a;
  Float32 localDTConv_UFix_To_Single_2_j3;
  Float32 localPrelookup_o2_m;
  Float32 localPrelookup_o2_cs;
  Float32 localfractionTmp_0d;
  Float32 localfrac[2];
  Float32 localPrelookup_o2_o;
  SInt32 localPrelookup_o1_a;
  SInt32 localbpIndex[2];
  SInt32 localPrelookup_o1_gy;
  Float32 localInterpolationUsingPreloo_g;
  Float32 localInterpolationUsingPrelo_hp;
  Float32 localfrac_0[2];
  SInt32 localbpIndex_0[2];
  Float32 localInterpolationUsingPreloo_a;
  UInt16 locallocalDTConv_UFix_To_Single;

  /* Outputs for atomic SubSystem: '<S396>/LibVlvBasChg' *
   * Block requirements for '<S396>/LibVlvBasChg':
   *  1. SubSystem "LibVlvBasChg" !Trace_To : VEMS_R_11_00996_069.01 ;
   */

  /* DataStoreWrite: '<S397>/GT' incorporates:
   *  Constant: '<S397>/AcvMP_noVlvMdl_C'
   *  RelationalOperator: '<S397>/Relational Operator'
   */
  localDW->AcvMP_bVlvMdl = (((UInt32)AcvMP_noVlvMdl_C) == ((UInt32)
    rtu_In_EngM_noAcvVlvMPVal));

  /* DataTypeConversion: '<S397>/DTConv_UFix_To_Single_3' */
  if (rtu_In_EOM_tiEngRun > 65535U) {
    locallocalDTConv_UFix_To_Single = MAX_uint16_T;
  } else {
    locallocalDTConv_UFix_To_Single = (UInt16)rtu_In_EOM_tiEngRun;
  }

  /* PreLookup: '<S399>/Prelookup' */
  localPrelookup_o1_a = plook_s32s16f_bincpa(rtu_In_Ext_tCoStrtMes,
    (&(EngM_tCoStrtY_A[0])), 12U, &localPrelookup_o2_cs,
    &localDW->Prelookup_DWORK1);

  /* PreLookup: '<S400>/Prelookup' */
  localPrelookup_o1_gy = plook_s32u16f_bincpa(locallocalDTConv_UFix_To_Single, (
    &(EngM_tiEngRunX_A[0])), 13U, &localPrelookup_o2_o,
    &localDW->Prelookup_DWORK1_d);

  /* Outputs for atomic SubSystem: '<S397>/F01_Calculation_angle_vvt_intake' *
   * Block requirements for '<S397>/F01_Calculation_angle_vvt_intake':
   *  1. SubSystem "F01_Calculation_angle_vvt_intake" !Trace_To : VEMS_R_11_00996_070.01 ;
   */

  /* Outputs for atomic SubSystem: '<S401>/F01_Intake_Valve_Clearance_Calculation' *
   * Block requirements for '<S401>/F01_Intake_Valve_Clearance_Calculation':
   *  1. SubSystem "F01_Intake_Valve_Clearance_Calculation" !Trace_To : VEMS_R_11_00996_071.01 ;
   */

  /* If: '<S403>/If' incorporates:
   *  ActionPort: '<S409>/Action Port'
   *  ActionPort: '<S410>/Action Port'
   *  Constant: '<S403>/EngM_bdstVlvClr_C'
   *  SubSystem: '<S403>/F01_1_EngM_dstInVlvClr_MP_IF'
   *  SubSystem: '<S403>/F01_2_EngM_dstInVlvClr_MP_ELSE'
   */
  if (EngM_bdstVlvClr_C) {
    /* Interpolation_n-D: '<S413>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_cs;
    localfrac[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_o;
    localfrac[1] = localfractionTmp_0d;
    localbpIndex[0] = localPrelookup_o1_a;
    localbpIndex[1] = localPrelookup_o1_gy;
    localfractionTmp_0d = intrp2d_iu16n23ff_s32f_la_ns(localbpIndex, localfrac,
      (&(EngM_dstInVlvClr_M[0])), 13U, &AirEfcEngCylPrmT_ConstP.pooled15[0]);
  } else {
    /* SignalConversion: '<S410>/Signal Conversion1' */
    localfractionTmp_0d = rtu_In_EngM_dstInVlvClrCor;
  }

  /* DataTypeConversion: '<S411>/OutDTConv' incorporates:
   *  Constant: '<S411>/offset'
   *  Constant: '<S411>/one_on_slope'
   *  Product: '<S411>/Product4'
   *  Sum: '<S411>/Add1'
   */
  localfractionTmp_0d *= 6.5536E+006F;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      locallocalDTConv_UFix_To_Single = (UInt16)localfractionTmp_0d;
    } else {
      locallocalDTConv_UFix_To_Single = 0U;
    }
  } else {
    locallocalDTConv_UFix_To_Single = MAX_uint16_T;
  }

  /* If: '<S408>/If' incorporates:
   *  ActionPort: '<S412>/Action Port'
   *  DataStoreRead: '<S408>/GT'
   *  SubSystem: '<S408>/F01_MP'
   */
  if (localDW->AcvMP_bVlvMdl) {
    /* DataStoreWrite: '<S412>/MP' */
    EngM_dstInVlvClr_MP = locallocalDTConv_UFix_To_Single;
  }

  /* end of Outputs for SubSystem: '<S401>/F01_Intake_Valve_Clearance_Calculation' */

  /* Outputs for atomic SubSystem: '<S401>/F02_Calculation_angle_vvt_intake_AFA' *
   * Block requirements for '<S401>/F02_Calculation_angle_vvt_intake_AFA':
   *  1. SubSystem "F02_Calculation_angle_vvt_intake_AFA" !Trace_To : VEMS_R_11_00996_072.01 ;
   */

  /* Switch: '<S404>/Switch' incorporates:
   *  Constant: '<S404>/EngM_bOpInVlvOfs_C'
   *  Sum: '<S404>/Add'
   */
  if (EngM_bOpInVlvOfs_C) {
    localSwitch_hf = rtu_In_AFA_agCkOpInVlvOfs + rtu_In_EngM_agCkOpInVlvRef0;
  } else {
    localSwitch_hf = rtu_In_EngM_agCkOpInVlvRef0;
  }

  /* end of Outputs for SubSystem: '<S401>/F02_Calculation_angle_vvt_intake_AFA' */

  /* Outputs for atomic SubSystem: '<S401>/F03_Reference_intake_law' *
   * Block requirements for '<S401>/F03_Reference_intake_law':
   *  1. SubSystem "F03_Reference_intake_law" !Trace_To : VEMS_R_11_00996_073.01 ;
   */

  /* DataTypeConversion: '<S405>/DTConv_UFix_To_Single_12' incorporates:
   *  Constant: '<S405>/EngM_agCkOpInVlvRef0Ref1_C'
   */
  localDTConv_UFix_To_Single_12_k = (((Float32)EngM_agCkOpInVlvRef0Ref1_C) *
    2.593994141E-003F) - 120.0F;

  /* DataTypeConversion: '<S405>/DTConv_UFix_To_Single_1' incorporates:
   *  Constant: '<S405>/EngM_agCkInWdLawRef0_C'
   */
  localDTConv_UFix_To_Single_1_d = (((Float32)EngM_agCkInWdLawRef0_C) *
    2.593994141E-003F) + 170.0F;

  /* DataTypeConversion: '<S405>/DTConv_UFix_To_Single_2' incorporates:
   *  Constant: '<S405>/EngM_agCkClsInVlvRef0Ref1_C'
   */
  localDTConv_UFix_To_Single_2_h = (((Float32)EngM_agCkClsInVlvRef0Ref1_C) *
    2.593994141E-003F) - 120.0F;

  /* end of Outputs for SubSystem: '<S401>/F03_Reference_intake_law' */

  /* Outputs for atomic SubSystem: '<S401>/F04_Intake_Valve_Clearance_Angle_Offset' *
   * Block requirements for '<S401>/F04_Intake_Valve_Clearance_Angle_Offset':
   *  1. SubSystem "F04_Intake_Valve_Clearance_Angle_Offset" !Trace_To : VEMS_R_11_00996_074.01 ;
   */

  /* PreLookup: '<S418>/Prelookup' */
  localPrelookup_o1_fw = plook_s32u16f_bincpa(locallocalDTConv_UFix_To_Single, (
    &(EngM_dstInVlvClrX_A[0])), 17U, &localPrelookup_o2_p,
    &localDW->Prelookup_DWORK1_e);

  /* Interpolation_n-D: '<S415>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2_p;
  localInterpolationUsingPreloo_g = intrp1d_iu16n11ff_s32f_la_ns
    (localPrelookup_o1_fw, localfractionTmp_0d, (&(EngM_agCkClsInVlvClrOfs_T[0])),
     17U);

  /* If: '<S414>/If' incorporates:
   *  ActionPort: '<S419>/Action Port'
   *  DataStoreRead: '<S414>/GT'
   *  SubSystem: '<S414>/F01_MP'
   */
  if (localDW->AcvMP_bVlvMdl) {
    /* DataStoreWrite: '<S419>/MP' */
    EngM_agCkClsInVlvClrOfs_MP = localInterpolationUsingPreloo_g;
  }

  /* Interpolation_n-D: '<S417>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2_p;
  localInterpolationUsingPrelo_hp = intrp1d_iu16n11ff_s32f_la_ns
    (localPrelookup_o1_fw, localfractionTmp_0d, (&(EngM_agCkOpInVlvClrOfs_T[0])),
     17U);

  /* If: '<S416>/If' incorporates:
   *  ActionPort: '<S420>/Action Port'
   *  DataStoreRead: '<S416>/GT'
   *  SubSystem: '<S416>/F01_MP'
   */
  if (localDW->AcvMP_bVlvMdl) {
    /* DataStoreWrite: '<S420>/MP' */
    EngM_agCkOpInVlvClrOfs_MP = localInterpolationUsingPrelo_hp;
  }

  /* end of Outputs for SubSystem: '<S401>/F04_Intake_Valve_Clearance_Angle_Offset' */

  /* Outputs for atomic SubSystem: '<S401>/F05_Calculation_angle_vvt_intake_ref1' *
   * Block requirements for '<S401>/F05_Calculation_angle_vvt_intake_ref1':
   *  1. SubSystem "F05_Calculation_angle_vvt_intake_ref1" !Trace_To : VEMS_R_11_00996_075.01 ;
   */

  /* Sum: '<S407>/Subtract5' */
  localSubtract5_f = localSwitch_hf + localDTConv_UFix_To_Single_1_d;

  /* end of Outputs for SubSystem: '<S401>/F05_Calculation_angle_vvt_intake_ref1' */

  /* end of Outputs for SubSystem: '<S397>/F01_Calculation_angle_vvt_intake' */

  /* Outputs for atomic SubSystem: '<S397>/F02_Calculation_angle_vvt_exhaust' *
   * Block requirements for '<S397>/F02_Calculation_angle_vvt_exhaust':
   *  1. SubSystem "F02_Calculation_angle_vvt_exhaust" !Trace_To : VEMS_R_11_00996_076.01 ;
   */

  /* Outputs for atomic SubSystem: '<S402>/F01_Exhaust_Valve_Clearance_Calculation' *
   * Block requirements for '<S402>/F01_Exhaust_Valve_Clearance_Calculation':
   *  1. SubSystem "F01_Exhaust_Valve_Clearance_Calculation" !Trace_To : VEMS_R_11_00996_077.01 ;
   */

  /* If: '<S421>/If' incorporates:
   *  ActionPort: '<S427>/Action Port'
   *  ActionPort: '<S428>/Action Port'
   *  Constant: '<S421>/EngM_bdstVlvClr_C'
   *  SubSystem: '<S421>/F01_1_EngM_dstExVlvClr_MP_IF'
   *  SubSystem: '<S421>/F01_2_EngM_dstExVlvClr_MP_ELSE'
   */
  if (EngM_bdstVlvClr_C) {
    /* Interpolation_n-D: '<S431>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_cs;
    localfrac_0[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_o;
    localfrac_0[1] = localfractionTmp_0d;
    localbpIndex_0[0] = localPrelookup_o1_a;
    localbpIndex_0[1] = localPrelookup_o1_gy;
    localfractionTmp_0d = intrp2d_iu16n23ff_s32f_la_ns(localbpIndex_0,
      localfrac_0, (&(EngM_dstExVlvClr_M[0])), 13U,
      &AirEfcEngCylPrmT_ConstP.pooled15[0]);
  } else {
    /* SignalConversion: '<S428>/Signal Conversion1' */
    localfractionTmp_0d = rtu_In_EngM_dstExVlvClrCor;
  }

  /* DataTypeConversion: '<S429>/OutDTConv' incorporates:
   *  Constant: '<S429>/offset'
   *  Constant: '<S429>/one_on_slope'
   *  Product: '<S429>/Product4'
   *  Sum: '<S429>/Add1'
   */
  localfractionTmp_0d *= 6.5536E+006F;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      locallocalDTConv_UFix_To_Single = (UInt16)localfractionTmp_0d;
    } else {
      locallocalDTConv_UFix_To_Single = 0U;
    }
  } else {
    locallocalDTConv_UFix_To_Single = MAX_uint16_T;
  }

  /* If: '<S426>/If' incorporates:
   *  ActionPort: '<S430>/Action Port'
   *  DataStoreRead: '<S426>/GT'
   *  SubSystem: '<S426>/F01_MP'
   */
  if (localDW->AcvMP_bVlvMdl) {
    /* DataStoreWrite: '<S430>/MP' */
    EngM_dstExVlvClr_MP = locallocalDTConv_UFix_To_Single;
  }

  /* end of Outputs for SubSystem: '<S402>/F01_Exhaust_Valve_Clearance_Calculation' */

  /* Outputs for atomic SubSystem: '<S402>/F02_Calculation_angle_vvt_exhaust_AFA' *
   * Block requirements for '<S402>/F02_Calculation_angle_vvt_exhaust_AFA':
   *  1. SubSystem "F02_Calculation_angle_vvt_exhaust_AFA" !Trace_To : VEMS_R_11_00996_078.01 ;
   */

  /* Switch: '<S422>/Switch' incorporates:
   *  Constant: '<S422>/EngM_bClsExVlvOfs_C'
   *  Sum: '<S422>/Add'
   */
  if (EngM_bClsExVlvOfs_C) {
    localSwitch_d = rtu_In_AFA_agCkClsExVlvOfs + rtu_In_EngM_agCkClsExVlvRef0;
  } else {
    localSwitch_d = rtu_In_EngM_agCkClsExVlvRef0;
  }

  /* end of Outputs for SubSystem: '<S402>/F02_Calculation_angle_vvt_exhaust_AFA' */

  /* Outputs for atomic SubSystem: '<S402>/F03_Reference_exhaust_law' *
   * Block requirements for '<S402>/F03_Reference_exhaust_law':
   *  1. SubSystem "F03_Reference_exhaust_law" !Trace_To : VEMS_R_11_00996_079.01 ;
   */

  /* DataTypeConversion: '<S423>/DTConv_UFix_To_Single_12' incorporates:
   *  Constant: '<S423>/EngM_agCkClsExVlvRef0Ref1_C'
   */
  localDTConv_UFix_To_Single_12_p = (((Float32)EngM_agCkClsExVlvRef0Ref1_C) *
    2.593994141E-003F) - 120.0F;

  /* DataTypeConversion: '<S423>/DTConv_UFix_To_Single_1' incorporates:
   *  Constant: '<S423>/EngM_agCkExWdLawRef0_C'
   */
  localDTConv_UFix_To_Single_1_a = (((Float32)EngM_agCkExWdLawRef0_C) *
    2.593994141E-003F) + 170.0F;

  /* DataTypeConversion: '<S423>/DTConv_UFix_To_Single_2' incorporates:
   *  Constant: '<S423>/EngM_agCkOpExVlvRef0Ref1_C'
   */
  localDTConv_UFix_To_Single_2_j3 = (((Float32)EngM_agCkOpExVlvRef0Ref1_C) *
    2.593994141E-003F) - 120.0F;

  /* end of Outputs for SubSystem: '<S402>/F03_Reference_exhaust_law' */

  /* Outputs for atomic SubSystem: '<S402>/F04_Exhaust_Valve_Clearance_Angle_Offset' *
   * Block requirements for '<S402>/F04_Exhaust_Valve_Clearance_Angle_Offset':
   *  1. SubSystem "F04_Exhaust_Valve_Clearance_Angle_Offset" !Trace_To : VEMS_R_11_00996_080.01 ;
   */

  /* PreLookup: '<S436>/Prelookup' */
  localPrelookup_o1_a = plook_s32u16f_bincpa(locallocalDTConv_UFix_To_Single,
    (&(EngM_dstExVlvClrX_A[0])), 17U, &localPrelookup_o2_m,
    &localDW->Prelookup_DWORK1_b);

  /* Interpolation_n-D: '<S433>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2_m;
  localInterpolationUsingPreloo_a = intrp1d_iu16n11ff_s32f_la_ns
    (localPrelookup_o1_a, localfractionTmp_0d, (&(EngM_agCkClsExVlvClrOfs_T[0])),
     17U);

  /* If: '<S432>/If' incorporates:
   *  ActionPort: '<S437>/Action Port'
   *  DataStoreRead: '<S432>/GT'
   *  SubSystem: '<S432>/F01_MP'
   */
  if (localDW->AcvMP_bVlvMdl) {
    /* DataStoreWrite: '<S437>/MP' */
    EngM_agCkClsExVlvClrOfs_MP = localInterpolationUsingPreloo_a;
  }

  /* Interpolation_n-D: '<S435>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2_m;
  localDTConv_UFix_To_Single_1_d = intrp1d_iu16n11ff_s32f_la_ns
    (localPrelookup_o1_a, localfractionTmp_0d, (&(EngM_agCkOpExVlvClrOfs_T[0])),
     17U);

  /* If: '<S434>/If' incorporates:
   *  ActionPort: '<S438>/Action Port'
   *  DataStoreRead: '<S434>/GT'
   *  SubSystem: '<S434>/F01_MP'
   */
  if (localDW->AcvMP_bVlvMdl) {
    /* DataStoreWrite: '<S438>/MP' */
    EngM_agCkOpExVlvClrOfs_MP = localDTConv_UFix_To_Single_1_d;
  }

  /* end of Outputs for SubSystem: '<S402>/F04_Exhaust_Valve_Clearance_Angle_Offset' */

  /* Outputs for atomic SubSystem: '<S402>/F05_Calculation_angle_vvt_exhaust_ref1' *
   * Block requirements for '<S402>/F05_Calculation_angle_vvt_exhaust_ref1':
   *  1. SubSystem "F05_Calculation_angle_vvt_exhaust_ref1" !Trace_To : VEMS_R_11_00996_081.01 ;
   */

  /* Sum: '<S425>/Subtract5' */
  localfractionTmp_0d = localSwitch_d - localDTConv_UFix_To_Single_1_a;

  /* end of Outputs for SubSystem: '<S402>/F05_Calculation_angle_vvt_exhaust_ref1' */

  /* end of Outputs for SubSystem: '<S397>/F02_Calculation_angle_vvt_exhaust' */

  /* end of Outputs for SubSystem: '<S396>/LibVlvBasChg' */

  /* SignalConversion: '<S396>/a' incorporates:
   *  Sum: '<S407>/Subtract3'
   */
  (*rty_Out_EngM_agCkOpInVlvRef1) = (localSwitch_hf -
    localDTConv_UFix_To_Single_12_k) + localInterpolationUsingPrelo_hp;

  /* SignalConversion: '<S396>/a1' incorporates:
   *  Sum: '<S407>/Subtract4'
   */
  (*rty_Out_EngM_agCkClsInVlvRef1) = (localDTConv_UFix_To_Single_2_h -
    localInterpolationUsingPreloo_g) + localSubtract5_f;

  /* SignalConversion: '<S396>/a2' */
  (*rty_Out_EngM_agCkClsInVlvRef0) = localSubtract5_f;

  /* SignalConversion: '<S396>/a3' incorporates:
   *  Sum: '<S425>/Subtract3'
   */
  (*rty_Out_EngM_agCkClsExVlvRef1) = (localSwitch_d -
    localInterpolationUsingPreloo_a) + localDTConv_UFix_To_Single_12_p;

  /* SignalConversion: '<S396>/a4' incorporates:
   *  Sum: '<S425>/Subtract4'
   */
  (*rty_Out_EngM_agCkOpExVlvRef1) = (localDTConv_UFix_To_Single_1_d -
    localDTConv_UFix_To_Single_2_j3) + localfractionTmp_0d;

  /* SignalConversion: '<S396>/a5' */
  (*rty_Out_EngM_agCkOpExVlvRef0) = localfractionTmp_0d;

  /* SignalConversion: '<S396>/a6' */
  (*rty_Out_EngM_agCkClsExVlvOfsRef) = localSwitch_d;

  /* SignalConversion: '<S396>/a7' */
  (*rty_Out_EngM_agCkOpInVlvOfsRef0) = localSwitch_hf;
}



/* Model initialize function */
void RE_AirEfcEngCylPrmT_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  OP_LibAirEfc_Start();
  OP_LibEngCylPrm_Start();
}

/* =========================================================
   Server Call Interface for Subsystem: '<S5>/Subsystem'
   '<S5>/Subsystem' <==> AirEfcEngCylPrmT/AirEfcEngCylPrmT/OP_LibAirEfc/Subsystem
   =========================================================
 */
void OP_LibAirEfc( UInt16 In_Ext_nEngRef,
  Float32 In_EngM_agCkClsExVlvRef1, Float32 In_EngM_agCkClsInVlvRef1, Float32
  In_EngM_agCkOpInVlvRef1, UInt16 In_InM_tAirUsInVlvEstimRef, Float32
  In_ExM_tExMnfEstimRef, UInt16 In_InM_pDsThr, Float32 In_ExM_pExMnfEstimRef,
  Float32 In_UsThrM_pAirExtEstimRef, UInt16 In_InjSys_rlamEngCorReqRef,
  Float32 In_InM_pDsThrPred_facVlvOvlpRef, SInt16 In_Ext_tCoMes, Float32
  In_AirEfc_facChrExpFilPrev, Float32 In_AirEfc_facChrExpScvFilPrev, UInt8
  In_EngM_noAcvMPVal, Float32 In_InjSys_agInj1BegRef, Float32
  In_InjSys_agInj1EndRef, Float32 In_InjSys_mFu1Inj, UInt16 In_InjSys_tFuRef,
  Float32 In_EngM_facCorOfsEfcRef, Float32 In_EngM_facCorSlopEfcRef, UInt16
  In_InThM_nEngCorRef, Float32 *Out_AirEfc_rMassBurn, Float32
  *Out_AirEfc_rMassAirResi, Float32 *Out_AirEfc_facSlopEfc, Float32
  *Out_AirEfc_facOfsEfc, Float32 *Out_AirEfc_rMassAirScv, Float32
  *Out_AirEfc_pDsThrCorClsInVlv, Float32 *Out_AirEfc_tBurnCyl, Float32
  *Out_AirEfc_rVolCylClsInVlv, Float32 *Out_AirEfc_facMassFlowLd, Float32
  *Out_AirEfc_facChrExpFil, Float32 *Out_AirEfc_facChrExpScvFil, Float32
  *Out_AirEfc_facMassAirScv, Float32 *Out_AirEfc_agInj1End, Float32
  *Out_AirEfc_rFuMassInj1InPha, Float32 *Out_AirEfc_rDeltaLdInjPhaRef, Float32
  *Out_AirEfc_facTAirUsInVlv, Float32 *Out_AirEfc_facTCo, Float32
  *Out_AirEfc_facCorAtmSlopEfc, Float32 *Out_AirEfc_facCorBoostSlopEfc,
  Float32 *Out_AirEfc_pBegCorBoostSlopEfc, Float32
  *Out_AirEfc_pDeltaCorSlopEfc)
{
  /* Call subsystem's output code */
  Subsystem(In_Ext_nEngRef, In_EngM_agCkClsInVlvRef1, In_InM_tAirUsInVlvEstimRef,
            In_InM_pDsThr, In_EngM_noAcvMPVal, In_InjSys_tFuRef,
            In_UsThrM_pAirExtEstimRef, In_InThM_nEngCorRef,
            In_EngM_agCkOpInVlvRef1, In_EngM_agCkClsExVlvRef1,
            In_InM_pDsThrPred_facVlvOvlpRef, In_ExM_pExMnfEstimRef,
            In_ExM_tExMnfEstimRef, In_AirEfc_facChrExpFilPrev,
            In_AirEfc_facChrExpScvFilPrev, In_InjSys_rlamEngCorReqRef,
            In_Ext_tCoMes, In_InjSys_agInj1BegRef, In_InjSys_agInj1EndRef,
            In_InjSys_mFu1Inj, In_EngM_facCorOfsEfcRef, In_EngM_facCorSlopEfcRef,
            Out_AirEfc_rMassBurn, Out_AirEfc_rMassAirResi,
            Out_AirEfc_facChrExpScvFil, Out_AirEfc_facMassAirScv,
            Out_AirEfc_agInj1End, Out_AirEfc_rFuMassInj1InPha,
            Out_AirEfc_rDeltaLdInjPhaRef, Out_AirEfc_facTAirUsInVlv,
            Out_AirEfc_facTCo, Out_AirEfc_facCorAtmSlopEfc,
            Out_AirEfc_facCorBoostSlopEfc, Out_AirEfc_pBegCorBoostSlopEfc,
            Out_AirEfc_facSlopEfc, Out_AirEfc_pDeltaCorSlopEfc,
            Out_AirEfc_facOfsEfc, Out_AirEfc_rMassAirScv,
            Out_AirEfc_pDsThrCorClsInVlv, Out_AirEfc_tBurnCyl,
            Out_AirEfc_rVolCylClsInVlv, Out_AirEfc_facMassFlowLd,
            Out_AirEfc_facChrExpFil, &AirEfcEngCylPrmT_B.Subsystem_i,
            &AirEfcEngCylPrmT_DWork.Subsystem_i);
}

/* =========================================================
   Server Call Interface for Subsystem: '<S6>/Subsystem'
   '<S6>/Subsystem' <==> AirEfcEngCylPrmT/AirEfcEngCylPrmT/OP_LibEngCylPrm/Subsystem
   =========================================================
 */
void OP_LibEngCylPrm( UInt16
  In_InM_tAirUsInVlvEstimRef, Float32 In_AirEfc_tBurnCyl, UInt16
  In_InM_pDsThr, Float32 In_AirEfc_facOfsEfc, Float32 In_AirEfc_facSlopEfc,
  Float32 In_AirEfc_rMassAirResi, Float32 In_AirEfc_rMassBurn, Float32
  In_AirEfc_rMassAirScv, Float32 In_AirEfc_facMassFlowLd, Float32
  In_InM_concAir, Float32 In_AirEfc_pDsThrCorClsInVlv, Float32
  In_AirEfc_rVolCylClsInVlv, UInt16 In_Ext_nEngRef, UInt8 In_EngM_noAcvMPVal,
  UInt16 In_InjSys_tFuRef, Float32 In_EngM_agCkClsInVlvRef1, Float32
  In_AirEfc_agInj1End, Float32 In_AirEfc_rFuMassInj1InPha, Float32
  *Out_EngM_rItBurnRate, Float32 *Out_EngM_tMixtCyl, Float32 *Out_EngM_rAirLd,
  Float32 *Out_EngM_rTotLdEx, Float32 *Out_EngM_mfAirScv, Float32
  *Out_EngM_mAir, Float32 *Out_EngM_mfAir, Float32 *Out_EngM_mTotEx, Float32 *
  Out_EngM_mfTotEx, Float32 *Out_EngM_mBurn, Float32 *Out_EngM_mAirScv,
  Float32 *Out_EngM_tMixtCylGDI, Float32 *Out_EngM_rltMassAirScv)
{
  /* Call subsystem's output code */
  Subsystem_o(In_EngM_noAcvMPVal, In_AirEfc_rMassBurn, In_AirEfc_rMassAirResi,
              In_InM_concAir, In_Ext_nEngRef, In_InM_pDsThr,
              In_AirEfc_facSlopEfc, In_AirEfc_facOfsEfc,
              In_InM_tAirUsInVlvEstimRef, In_AirEfc_agInj1End,
              In_EngM_agCkClsInVlvRef1, In_InjSys_tFuRef,
              In_AirEfc_rFuMassInj1InPha, In_AirEfc_tBurnCyl,
              In_AirEfc_pDsThrCorClsInVlv, In_AirEfc_rVolCylClsInVlv,
              In_AirEfc_rMassAirScv, In_AirEfc_facMassFlowLd,
              Out_EngM_rItBurnRate, Out_EngM_tMixtCyl, Out_EngM_mAirScv,
              Out_EngM_tMixtCylGDI, Out_EngM_rltMassAirScv, Out_EngM_rAirLd,
              Out_EngM_rTotLdEx, Out_EngM_mfAirScv, Out_EngM_mAir,
              Out_EngM_mfAir, Out_EngM_mTotEx, Out_EngM_mfTotEx, Out_EngM_mBurn,
              &AirEfcEngCylPrmT_B.Subsystem_on,
              &AirEfcEngCylPrmT_DWork.Subsystem_on);
}

/* =========================================================
   Server Call Interface for Subsystem: '<S7>/Subsystem'
   '<S7>/Subsystem' <==> AirEfcEngCylPrmT/AirEfcEngCylPrmT/OP_LibVlvBasChg/Subsystem
   =========================================================
 */
void OP_LibVlvBasChg( Float32
  In_EngM_agCkOpInVlvRef0, Float32 In_EngM_agCkClsExVlvRef0, SInt16
  In_Ext_tCoStrtMes, Float32 In_AFA_agCkOpInVlvOfs, Float32
  In_AFA_agCkClsExVlvOfs, UInt32 In_EOM_tiEngRun, Float32
  In_EngM_dstInVlvClrCor, Float32 In_EngM_dstExVlvClrCor, UInt8
  In_EngM_noAcvVlvMPVal, Float32 *Out_EngM_agCkOpInVlvRef1, Float32
  *Out_EngM_agCkClsInVlvRef1, Float32 *Out_EngM_agCkClsInVlvRef0, Float32
  *Out_EngM_agCkClsExVlvRef1, Float32 *Out_EngM_agCkOpExVlvRef1, Float32
  *Out_EngM_agCkOpExVlvRef0, Float32 *Out_EngM_agCkClsExVlvOfsRef0, Float32
  *Out_EngM_agCkOpInVlvOfsRef0)
{
  /* Call subsystem's output code */
  Subsystem_a(In_EngM_noAcvVlvMPVal, In_EOM_tiEngRun, In_Ext_tCoStrtMes,
              In_EngM_dstInVlvClrCor, In_AFA_agCkOpInVlvOfs,
              In_EngM_agCkOpInVlvRef0, In_EngM_dstExVlvClrCor,
              In_AFA_agCkClsExVlvOfs, In_EngM_agCkClsExVlvRef0,
              Out_EngM_agCkOpInVlvRef1, Out_EngM_agCkClsInVlvRef1,
              Out_EngM_agCkClsInVlvRef0, Out_EngM_agCkClsExVlvRef1,
              Out_EngM_agCkOpExVlvRef1, Out_EngM_agCkOpExVlvRef0,
              Out_EngM_agCkClsExVlvOfsRef0, Out_EngM_agCkOpInVlvOfsRef0,
              &AirEfcEngCylPrmT_DWork.Subsystem_ay);
}

#define AirEfcEngCylPrmT_STOP_SEC_CODE
#include "AirEfcEngCylPrmT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
