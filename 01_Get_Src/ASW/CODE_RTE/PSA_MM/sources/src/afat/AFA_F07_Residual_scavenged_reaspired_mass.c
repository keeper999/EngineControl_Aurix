/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA                                                     */
/* !Description     : AFA Software Component                                  */
/*                                                                            */
/* !File            : AFA_F07_Residual_scavenged_reaspired_mass.c             */
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
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F07_Residual_scavenged_reaspired_mass.h"
#include "AFA_F07_Residual_scavenged_reaspired_mass_private.h"
#include "AFAT.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt32 AFA_facTExSqrt_MP;            /* '<S25>/Look-Up Table' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

UInt16 AFA_nEngCorScvFil;            /* '<S10>/Switch' */
SInt16 AFA_rMassBurn_agCkEx;          /* '<S110>/OutDTConv' */
SInt16 AFA_rMassBurn_agCkIn;          /* '<S111>/OutDTConv' */
UInt16 AFA_facMassFlowCor;           /* '<S17>/Look-Up Table (2-D)' */
UInt16 AFA_rMassBurn;                /* '<S109>/OutDTConv' */
UInt16 AFA_rMassAirScv;              /* '<S7>/Merge' */
UInt16 AFA_facAirScv;                /* '<S94>/OutDTConv' */
SInt16 AFA_mGrdBurnRspg_pDsThr;       /* '<S49>/OutDTConv' */
UInt16 AFA_mGrdAirScvTot_pDsThr;     /* '<S89>/OutDTConv' */

/* Exported block states */
SInt16 AFA_rMassGrdBnRgBstSat_agCkEx; /* '<S7>/Data Store Memory2' */
SInt16 AFA_rMassGrdBnRgBstSat_agCkIn; /* '<S7>/Data Store Memory3' */
SInt16 AFA_rMassGrdBurnRgSat_agCkIn;  /* '<S5>/Data Store Memory1' */
SInt16 AFA_rMassGrdBurnRgCor_agCkIn;  /* '<S5>/Data Store Memory2' */
SInt16 AFA_rMassGrdBurnRgCor_agCkEx;  /* '<S5>/Data Store Memory4' */
SInt16 AFA_rMassGrdBurnRgSat_agCkEx;  /* '<S5>/Data Store Memory5' */
SInt16 AFA_rVolCylGrd_agCkOpIn_MP;    /* '<S4>/Data Store Memory1' */
SInt16 AFA_facCorMassGrdBurnRg_MP;    /* '<S4>/Data Store Memory2' */
SInt16 AFA_rMassGrdBurnRgTot_agCkIn;  /* '<S4>/Data Store Memory5' */
SInt16 AFA_rMassGrdBurnRgTot_agCkEx;  /* '<S4>/Data Store Memory6' */
SInt16 AFA_rMassGrdBurnRspg_agCkEx;   /* '<S22>/Data Store Memory2' */
SInt16 AFA_rMassGrdBurnRspgTot_agCkEx;/* '<S22>/Data Store Memory3' */
SInt16 AFA_rMassGrdBurnRspg_agCkIn;   /* '<S22>/Data Store Memory4' */
SInt16 AFA_rMassGrdBurnRspgTot_agCkIn;/* '<S22>/Data Store Memory5' */
SInt16 AFA_facMassFlowGrd_agCkEx;     /* '<S1>/Data Store Memory' */
SInt16 AFA_facMassFlowGrd_agCkIn;     /* '<S1>/Data Store Memory1' */
UInt16 AFA_facMassFlowLd;            /* '<S2>/Data Store Memory' */
UInt16 AFA_rFacMassGrdBurnRspgTot;   /* '<S21>/Data Store Memory' */
SInt16 AFA_rMassBurnRgCor;            /* '<S5>/Data Store Memory' */
SInt16 AFA_rMassBurnRspgTot;          /* '<S21>/Data Store Memory1' */
UInt16 AFA_rMassBurnRgBoostCorSat;   /* '<S7>/Data Store Memory1' */
UInt16 AFA_rMassAirScvTot;           /* '<S6>/Data Store Memory3' */
UInt16 AFA_rMassBurnRgCorSat;        /* '<S5>/Data Store Memory3' */
UInt16 AFA_rMassBurnRgTot;           /* '<S4>/Data Store Memory4' */
UInt16 AFA_rMassBurnRspg;            /* '<S21>/Data Store Memory2' */
UInt16 AFA_mfAirScvRedCor_MP;        /* '<S70>/Data Store Memory2' */
UInt16 AFA_mfBurnRspgRedBas;         /* '<S21>/Data Store Memory3' */
UInt16 AFA_facChrExpFil;             /* '<S21>/Data Store Memory4' */
UInt16 AFA_mfBurnRspgRedCor;         /* '<S21>/Data Store Memory5' */
UInt16 AFA_mfGrdBurnRspgRed_MP;      /* '<S22>/Data Store Memory1' */
SInt16 AFA_rVolGrdCyl_MP;             /* '<S4>/Data Store Memory' */
UInt16 AFA_facTInSqrt_MP;            /* '<S70>/Data Store Memory1' */
UInt16 AFA_rVolCyl_MP;               /* '<S4>/Data Store Memory3' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

rtMdlrefDWork_mr_AFA_F07_Residu mr_AFA_F07_Residual_MdlrefDWork;


#define AFAT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Start for referenced model: 'AFA_F07_Residual_scavenged_reaspired_mass' */
void mr_AFA_F07_Residual_scave_Start(void)
{
  /* Start for atomic SubSystem: '<Root>/F03_Reaspired_burn_mass' *
   * Block requirements for '<Root>/F03_Reaspired_burn_mass':
   *  1. SubSystem "F03_Reaspired_burn_mass" !Trace_To : VEMS_R_11_04467_078.01 ;
   */

  /* Start for atomic SubSystem: '<S3>/F02_calcul_derive_VVT' *
   * Block requirements for '<S3>/F02_calcul_derive_VVT':
   *  1. SubSystem "F02_calcul_derive_VVT" !Trace_To : VEMS_R_11_04467_080.01 ;
   */

  /* Start for DataStoreMemory: '<S22>/Data Store Memory1' */
  AFA_mfGrdBurnRspgRed_MP = 32768U;

  /* end of Start for SubSystem: '<S3>/F02_calcul_derive_VVT' */

  /* end of Start for SubSystem: '<Root>/F03_Reaspired_burn_mass' */
}

/* Output and update for referenced model: 'AFA_F07_Residual_scavenged_reaspired_mass' */
void mr_AFA_F07_Residual_scavenged_r(const UInt16 *rtu_AFA_nEngFil, const
  UInt16 *rtu_AFA_pDsThrPred_facVlvOvlp_, const UInt16
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
  *rty_AFA_rMassAirScv)
{
  rtB_mr_AFA_F07_Residual_scaveng *localB =
    &(mr_AFA_F07_Residual_MdlrefDWork.rtb);

  /* local block i/o variables */
  SInt16 localDataTypeConversion6;
  SInt16 localDataTypeConversion4_p;
  SInt16 localDataTypeConversion2_m;
  SInt16 localLookUpTable2D;
  SInt16 localLookUpTable2D_p;
  SInt16 localOutDTConv_g;
  SInt16 localLookUpTable;
  UInt16 localLookUpTable_l;
  UInt16 localLookUpTable2D_m;
  UInt16 localLookUpTable_h;
  UInt16 localDataTypeConversion5_k;
  UInt16 localOutDTConv_aa;
  Float32 localDataTypeConversion;
  Float32 localDataTypeConversion1;
  Float32 localSwitch_h;
  Float32 localSwitch1_b;
  Float32 localSwitch1_g;
  Float32 localDivide1_b;
  Float32 localDataTypeConversion1_n;
  Float32 localProduct2_o;
  Float32 localLookupTablenD_d;
  Boolean localRelationalOperator1;
  Float32 localProduct5_l;
  Boolean localRelationalOperator_k;
  Float32 localSwitch1_d4;
  Float32 localLookupTablenD;
  Float32 localLookupTablenD_mx;
  Float32 localLookupTablenD_m;
  Float32 localmax;
  Float32 localSwitch1_es;
  Float32 localProduct2_g;
  Boolean localCompare_c;
  Float32 localProduct5_h;
  Float32 localProduct7_a;
  SInt32 localDataTypeConversion3_m;
  SInt32 localAbs;
  SInt16 localOutDTConv_oa;
  UInt16 localOutDTConv_k4;
  SInt16 locallocalOutDTConv_k;
  UInt32 locallupIdx;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  localDataTypeConversion = ((Float32)(*rtu_AFA_pExMnfEstimFi7)) * 8.0F;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  localDataTypeConversion1 = ((Float32)(*rtu_AFA_pDsThrPred_facVlvOvlp_)) *
    8.0F;

  /* Outputs for atomic SubSystem: '<Root>/F01_Correction_reaspired_scavenged_massflow' *
   * Block requirements for '<Root>/F01_Correction_reaspired_scavenged_massflow':
   *  1. SubSystem "F01_Correction_reaspired_scavenged_massflow" !Trace_To : VEMS_R_11_04467_076.01 ;
   */

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  localAbs = (*rtu_AFA_agCkPosnVlvOvlp) + -1024;
  if (localAbs > 32767) {
    localDataTypeConversion2_m = MAX_int16_T;
  } else {
    localDataTypeConversion2_m = (SInt16)localAbs;
  }

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Lookup_n-D: '<S18>/Lookup Table (n-D)'
   */
  localDivide1_b = look2_1fc22bc2bcvbfbbt5dfbbnx((*rtu_AFA_nEngFil),
    localDataTypeConversion2_m, (&(AirEfc_nEngY_A[0])),
    (&(AFA_agCkGrdPosnVlvOvlpX_A[0])), (&(AFA_facMassFlowGrdCor_M[0])),
    &AFA_F07_Residual_scaveng_ConstP.LookupTablenD_maxInde[0], 18U) / 2.0F;

  /* Product: '<S19>/Product4' incorporates:
   *  Constant: '<S19>/offset'
   *  Constant: '<S19>/one_on_slope'
   *  Sum: '<S19>/Add1'
   */
  localSwitch1_g = 327680.0F * localDivide1_b;

  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S19>/offset2'
   *  Constant: '<S19>/offset3'
   *  Constant: '<S19>/offset4'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  Sum: '<S19>/Add3'
   *  Sum: '<S19>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S19>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      locallocalOutDTConv_k = (SInt16)localSwitch1_g;
    } else {
      locallocalOutDTConv_k = MIN_int16_T;
    }
  } else {
    locallocalOutDTConv_k = MAX_int16_T;
  }

  /* DataStoreWrite: '<S1>/Data Store Write' */
  AFA_facMassFlowGrd_agCkEx = locallocalOutDTConv_k;

  /* DataStoreWrite: '<S1>/Data Store Write1' */
  AFA_facMassFlowGrd_agCkIn = locallocalOutDTConv_k;

  /* Lookup2D: '<S17>/Look-Up Table (2-D)'
   * About '<S17>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
   * Output0 Data Type:  Fixed Point    U16  2^-17  FSlope 1.2  Bias 0.7
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_S16( &(AFA_facMassFlowCor), (&(AirEfc_facMassFlowCor_M[0])),
                     (*rtu_AFA_nEngFil), (&(AirEfc_nEngY_A[0])), 17U,
                     localDataTypeConversion2_m, (&(AirEfc_agCkPosnVlvOvlpX_A[0])),
                     12U);

  /* DataTypeDuplicate Block: '<S17>/Data Type Duplicate2'
   *
   * Regarding '<S17>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  localDataTypeConversion1_n = (((Float32)AFA_facMassFlowCor) *
    9.155273801E-006F) + 6.999999881E-001F;

  /* end of Outputs for SubSystem: '<Root>/F01_Correction_reaspired_scavenged_massflow' */

  /* Outputs for atomic SubSystem: '<Root>/F02_Coefficient_massflow_to_load' *
   * Block requirements for '<Root>/F02_Coefficient_massflow_to_load':
   *  1. SubSystem "F02_Coefficient_massflow_to_load" !Trace_To : VEMS_R_11_04467_077.01 ;
   */

  /* Product: '<S2>/Product2' incorporates:
   *  Constant: '<S2>/AirEfc_densAir_C'
   *  Constant: '<S2>/AirEfc_noCylEng_C'
   *  Constant: '<S2>/AirEfc_volRef_C'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant3'
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  DataTypeConversion: '<S2>/Data Type Conversion4'
   *  Product: '<S2>/Divide'
   *  Product: '<S2>/Divide1'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  localProduct2_o = (((((Float32)AirEfc_volRef_C) * 7.629394894E-009F) *
                      (((Float32)AirEfc_noCylEng_C) / 2.0F)) * (((Float32)
    AirEfc_densAir_C) * 1.525878906E-005F)) * (((Float32)(*rtu_AFA_nEngFil)) /
    60.0F);

  /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
   *  Constant: '<S20>/offset'
   *  Constant: '<S20>/offset1'
   *  Constant: '<S20>/one_on_slope'
   *  DataTypeConversion: '<S20>/OutDTConv'
   *  Product: '<S20>/Product4'
   *  Sum: '<S20>/Add1'
   *  Sum: '<S20>/Add2'
   */
  localSwitch1_g = (163840.0F * localProduct2_o) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    AFA_facMassFlowLd = (UInt16)localSwitch1_g;
  } else {
    AFA_facMassFlowLd = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<Root>/F02_Coefficient_massflow_to_load' */

  /* Outputs for atomic SubSystem: '<Root>/F03_Reaspired_burn_mass' *
   * Block requirements for '<Root>/F03_Reaspired_burn_mass':
   *  1. SubSystem "F03_Reaspired_burn_mass" !Trace_To : VEMS_R_11_04467_078.01 ;
   */

  /* Outputs for atomic SubSystem: '<S3>/F01_calcul_nominal' *
   * Block requirements for '<S3>/F01_calcul_nominal':
   *  1. SubSystem "F01_calcul_nominal" !Trace_To : VEMS_R_11_04467_079.01 ;
   */

  /* Product: '<S21>/Divide1' incorporates:
   *  Constant: '<S21>/AirEfc_pRef_C'
   */
  localSwitch1_g = localDataTypeConversion / (((Float32)AirEfc_pRef_C) * 8.0F);

  /* Lookup: '<S25>/Look-Up Table'
   * About '<S25>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-5
   * Output0 Data Type:  Fixed Point    U32  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U32_U16( &(AFA_facTExSqrt_MP), (&(AirEfc_facTExSqrt_T[0])),
                 (*rtu_AFA_tExMnfEstimFi7), (&(AirEfc_tExMnf_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S25>/Data Type Duplicate1'
   *
   * Regarding '<S25>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Product: '<S26>/Divide' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion3'
   *  Product: '<S21>/Product'
   */
  localSwitch1_g = ((((Float32)AFA_facTExSqrt_MP) * 3.051757813E-005F) *
                    localSwitch1_g) / localProduct2_o;

  /* Outputs for atomic SubSystem: '<S26>/If Action Subsystem3' */

  /* Switch: '<S38>/Switch1' incorporates:
   *  Constant: '<S38>/Constant2'
   *  RelationalOperator: '<S38>/Relational Operator'
   *  Saturate: '<S38>/Saturation'
   */
  if (localSwitch1_g != localSwitch1_g) {
    localSwitch1_d4 = 0.0F;
  } else {
    localSwitch1_d4 = rt_SATURATE(localSwitch1_g, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S26>/If Action Subsystem3' */

  /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
   *  Constant: '<S30>/offset'
   *  Constant: '<S30>/offset1'
   *  Constant: '<S30>/one_on_slope'
   *  DataTypeConversion: '<S30>/OutDTConv'
   *  Product: '<S30>/Product4'
   *  Sum: '<S30>/Add1'
   *  Sum: '<S30>/Add2'
   */
  localSwitch1_g = (6.553600311E+001F * localSwitch1_d4) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_rFacMassGrdBurnRspgTot = (UInt16)localSwitch1_g;
    } else {
      AFA_rFacMassGrdBurnRspgTot = 0U;
    }
  } else {
    AFA_rFacMassGrdBurnRspgTot = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S28>/Lookup Table (n-D)' */
  localLookupTablenD = look2_1fc22bc2bcvbfbbr6dfbbnx((*rtu_AFA_nEngFil),
    (*rtu_AFA_agCkVlvOvlp), (&(AirEfc_nEngY_A[0])), (&(AirEfc_agCkVlvOvlpX_A[0])),
    (&(AirEfc_mfBurnRspgRedBas_M[0])),
    &AFA_F07_Residual_scaveng_ConstP.pooled11[0], 18U);

  /* Lookup_n-D: '<S29>/Lookup Table (n-D)' */
  localLookupTablenD_m = look2_1fc22bc2bcvbfbbr6dfbbnx((*rtu_AFA_nEngFil),
    (*rtu_AFA_agCkVlvOvlp), (&(AirEfc_nEngY_A[0])), (&(AirEfc_agCkVlvOvlpX_A[0])),
    (&(AirEfc_mfBurnRspgRedCor_M[0])),
    &AFA_F07_Residual_scaveng_ConstP.pooled11[0], 18U);

  /* Product: '<S27>/Divide' */
  localSwitch1_g = localDataTypeConversion1 / localDataTypeConversion;

  /* Outputs for atomic SubSystem: '<S27>/If Action Subsystem3' */

  /* Switch: '<S40>/Switch1' incorporates:
   *  Constant: '<S40>/Constant2'
   *  RelationalOperator: '<S40>/Relational Operator'
   *  Saturate: '<S40>/Saturation'
   */
  if (localSwitch1_g != localSwitch1_g) {
    localSwitch1_g = 0.0F;
  } else {
    localSwitch1_g = rt_SATURATE(localSwitch1_g, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S27>/If Action Subsystem3' */

  /* DataTypeConversion: '<S32>/OutDTConv' incorporates:
   *  Constant: '<S32>/offset'
   *  Constant: '<S32>/offset1'
   *  Constant: '<S32>/one_on_slope'
   *  Product: '<S32>/Product4'
   *  Sum: '<S32>/Add1'
   *  Sum: '<S32>/Add2'
   */
  localSwitch1_g = (65536.0F * localSwitch1_g) + 0.5F;
  if (localSwitch1_g < 4.294967296E+009F) {
    if (localSwitch1_g >= 0.0F) {
      locallupIdx = (UInt32)localSwitch1_g;
    } else {
      locallupIdx = 0U;
    }
  } else {
    locallupIdx = MAX_uint32_T;
  }

  /* Lookup_n-D: '<S24>/Lookup Table (n-D)' */
  localLookupTablenD_mx = look1_iu32lftu16n16If_binlcns(locallupIdx,
    (&(AirEfc_rPresEngX_A[0])), (&(AirEfc_facChrExp_T[0])), 10U);

  /* Product: '<S21>/Product5' incorporates:
   *  Constant: '<S21>/Constant5'
   *  Product: '<S21>/Product1'
   *  Product: '<S21>/Product3'
   *  Product: '<S21>/Product4'
   *  Sum: '<S21>/Sum1'
   *  Sum: '<S21>/Sum2'
   */
  localProduct5_l = ((((localLookupTablenD_mx - 1.0F) * localLookupTablenD_m) *
                      localDataTypeConversion1_n) + (localLookupTablenD *
    localDataTypeConversion1_n)) * localSwitch1_d4;

  /* Product: '<S31>/Product4' incorporates:
   *  Constant: '<S31>/offset'
   *  Constant: '<S31>/one_on_slope'
   *  Sum: '<S31>/Add1'
   */
  localSwitch1_g = 8192.0F * localProduct5_l;

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/offset2'
   *  Constant: '<S31>/offset3'
   *  Constant: '<S31>/offset4'
   *  RelationalOperator: '<S31>/Relational Operator'
   *  Sum: '<S31>/Add3'
   *  Sum: '<S31>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S21>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S31>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassBurnRspgTot = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassBurnRspgTot = MIN_int16_T;
    }
  } else {
    AFA_rMassBurnRspgTot = MAX_int16_T;
  }

  /* MinMax: '<S21>/MinMax' incorporates:
   *  Constant: '<S21>/Constant1'
   */
  localmax = rt_MAXf(localProduct5_l, 0.0F);

  /* DataStoreWrite: '<S21>/Data Store Write2' incorporates:
   *  Constant: '<S33>/offset'
   *  Constant: '<S33>/offset1'
   *  Constant: '<S33>/one_on_slope'
   *  DataTypeConversion: '<S33>/OutDTConv'
   *  Product: '<S33>/Product4'
   *  Sum: '<S33>/Add1'
   *  Sum: '<S33>/Add2'
   */
  localSwitch1_g = (16384.0F * localmax) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    AFA_rMassBurnRspg = (UInt16)localSwitch1_g;
  } else {
    AFA_rMassBurnRspg = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S21>/Data Store Write3' incorporates:
   *  Constant: '<S34>/offset'
   *  Constant: '<S34>/offset1'
   *  Constant: '<S34>/one_on_slope'
   *  DataTypeConversion: '<S34>/OutDTConv'
   *  Product: '<S34>/Product4'
   *  Sum: '<S34>/Add1'
   *  Sum: '<S34>/Add2'
   */
  localSwitch1_g = (65536.0F * localLookupTablenD) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_mfBurnRspgRedBas = (UInt16)localSwitch1_g;
    } else {
      AFA_mfBurnRspgRedBas = 0U;
    }
  } else {
    AFA_mfBurnRspgRedBas = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S21>/Data Store Write4' incorporates:
   *  Constant: '<S35>/offset'
   *  Constant: '<S35>/offset1'
   *  Constant: '<S35>/one_on_slope'
   *  DataTypeConversion: '<S35>/OutDTConv'
   *  Product: '<S35>/Product4'
   *  Sum: '<S35>/Add1'
   *  Sum: '<S35>/Add2'
   */
  localSwitch1_g = (65536.0F * localLookupTablenD_m) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_mfBurnRspgRedCor = (UInt16)localSwitch1_g;
    } else {
      AFA_mfBurnRspgRedCor = 0U;
    }
  } else {
    AFA_mfBurnRspgRedCor = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S21>/Data Store Write5' incorporates:
   *  Constant: '<S36>/offset'
   *  Constant: '<S36>/offset1'
   *  Constant: '<S36>/one_on_slope'
   *  DataTypeConversion: '<S36>/OutDTConv'
   *  Product: '<S36>/Product4'
   *  Sum: '<S36>/Add1'
   *  Sum: '<S36>/Add2'
   */
  localSwitch1_g = (65536.0F * localLookupTablenD_mx) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_facChrExpFil = (UInt16)localSwitch1_g;
    } else {
      AFA_facChrExpFil = 0U;
    }
  } else {
    AFA_facChrExpFil = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S3>/F01_calcul_nominal' */

  /* Outputs for atomic SubSystem: '<S3>/F02_calcul_derive_VVT' *
   * Block requirements for '<S3>/F02_calcul_derive_VVT':
   *  1. SubSystem "F02_calcul_derive_VVT" !Trace_To : VEMS_R_11_04467_080.01 ;
   */

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S22>/Constant5'
   */
  localSwitch1_es = localLookupTablenD_mx - 1.0F;

  /* Sum: '<S22>/Sum3' incorporates:
   *  Lookup_n-D: '<S42>/Lookup Table (n-D)'
   *  Lookup_n-D: '<S43>/Lookup Table (n-D)'
   *  Product: '<S22>/Product'
   */
  localProduct2_g = (localSwitch1_es * look2_1fc22bc2bcvbfbbt4xfbbnx
                     ((*rtu_AFA_nEngFil), (*rtu_AFA_agCkVlvOvlp),
                      (&(AirEfc_nEngY_A[0])), (&(AFA_agCkGrdVlvOvlpX_A[0])),
                      (&(AFA_mfGrdBurnRspgRedCor_M[0])),
                      &AFA_F07_Residual_scaveng_ConstP.pooled12[0], 18U)) +
    look2_1fc22bc2bcvbfbbt4xfbbnx((*rtu_AFA_nEngFil), (*rtu_AFA_agCkVlvOvlp),
                                  (&(AirEfc_nEngY_A[0])),
    (&(AFA_agCkGrdVlvOvlpX_A[0])), (&(AFA_mfGrdBurnRspgRedBas_M[0])),
    &AFA_F07_Residual_scaveng_ConstP.pooled12[0], 18U);

  /* DataStoreWrite: '<S22>/Data Store Write1' incorporates:
   *  Constant: '<S44>/offset'
   *  Constant: '<S44>/offset1'
   *  Constant: '<S44>/one_on_slope'
   *  DataTypeConversion: '<S44>/OutDTConv'
   *  Product: '<S44>/Product4'
   *  Sum: '<S44>/Add1'
   *  Sum: '<S44>/Add2'
   */
  localSwitch1_g = ((localProduct2_g - -9.999999776E-003F) * 3.2768E+006F) +
    0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_mfGrdBurnRspgRed_MP = (UInt16)localSwitch1_g;
    } else {
      AFA_mfGrdBurnRspgRed_MP = 0U;
    }
  } else {
    AFA_mfGrdBurnRspgRed_MP = MAX_uint16_T;
  }

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   */
  localCompare_c = (localProduct5_l < 0.0F);

  /* Sum: '<S22>/Sum5' incorporates:
   *  Product: '<S22>/Product1'
   */
  localLookupTablenD += localLookupTablenD_m * localSwitch1_es;

  /* Product: '<S22>/Product2' */
  localProduct2_g *= localDataTypeConversion1_n;

  /* Product: '<S22>/Product5' incorporates:
   *  Product: '<S22>/Product3'
   *  Sum: '<S22>/Sum2'
   */
  localProduct5_h = ((localLookupTablenD * localDivide1_b) + localProduct2_g) *
    localSwitch1_d4;

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Constant3'
   */
  if (localCompare_c) {
    localSwitch_h = 0.0F;
  } else {
    localSwitch_h = localProduct5_h;
  }

  /* Product: '<S48>/Product4' incorporates:
   *  Constant: '<S48>/offset'
   *  Constant: '<S48>/one_on_slope'
   *  Sum: '<S48>/Add1'
   */
  localSwitch1_g = 327680.0F * localSwitch_h;

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/offset2'
   *  Constant: '<S48>/offset3'
   *  Constant: '<S48>/offset4'
   *  RelationalOperator: '<S48>/Relational Operator'
   *  Sum: '<S48>/Add3'
   *  Sum: '<S48>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_es = localSwitch1_g + 0.5F;
  } else {
    localSwitch1_es = localSwitch1_g - 0.5F;
  }

  /* DataStoreWrite: '<S22>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<S48>/OutDTConv'
   */
  if (localSwitch1_es < 32768.0F) {
    if (localSwitch1_es >= -32768.0F) {
      AFA_rMassGrdBurnRspg_agCkEx = (SInt16)localSwitch1_es;
    } else {
      AFA_rMassGrdBurnRspg_agCkEx = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRspg_agCkEx = MAX_int16_T;
  }

  /* Product: '<S47>/Product4' incorporates:
   *  Constant: '<S47>/offset'
   *  Constant: '<S47>/one_on_slope'
   *  Sum: '<S47>/Add1'
   */
  localSwitch1_g = 327680.0F * localProduct5_h;

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<S47>/offset2'
   *  Constant: '<S47>/offset3'
   *  Constant: '<S47>/offset4'
   *  RelationalOperator: '<S47>/Relational Operator'
   *  Sum: '<S47>/Add3'
   *  Sum: '<S47>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_es = localSwitch1_g + 0.5F;
  } else {
    localSwitch1_es = localSwitch1_g - 0.5F;
  }

  /* DataStoreWrite: '<S22>/Data Store Write3' incorporates:
   *  DataTypeConversion: '<S47>/OutDTConv'
   */
  if (localSwitch1_es < 32768.0F) {
    if (localSwitch1_es >= -32768.0F) {
      AFA_rMassGrdBurnRspgTot_agCkEx = (SInt16)localSwitch1_es;
    } else {
      AFA_rMassGrdBurnRspgTot_agCkEx = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRspgTot_agCkEx = MAX_int16_T;
  }

  /* Product: '<S22>/Product7' incorporates:
   *  Constant: '<S22>/Constant16'
   *  Product: '<S22>/Product4'
   *  Product: '<S22>/Product6'
   *  Sum: '<S22>/Sum4'
   */
  localProduct7_a = ((-localProduct2_g) + (localLookupTablenD * localDivide1_b))
    * localSwitch1_d4;

  /* Switch: '<S22>/Switch1' incorporates:
   *  Constant: '<S22>/Constant4'
   */
  if (localCompare_c) {
    localSwitch1_b = 0.0F;
  } else {
    localSwitch1_b = localProduct7_a;
  }

  /* Product: '<S46>/Product4' incorporates:
   *  Constant: '<S46>/offset'
   *  Constant: '<S46>/one_on_slope'
   *  Sum: '<S46>/Add1'
   */
  localSwitch1_g = 327680.0F * localSwitch1_b;

  /* Switch: '<S46>/Switch1' incorporates:
   *  Constant: '<S46>/offset2'
   *  Constant: '<S46>/offset3'
   *  Constant: '<S46>/offset4'
   *  RelationalOperator: '<S46>/Relational Operator'
   *  Sum: '<S46>/Add3'
   *  Sum: '<S46>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localLookupTablenD = localSwitch1_g + 0.5F;
  } else {
    localLookupTablenD = localSwitch1_g - 0.5F;
  }

  /* DataStoreWrite: '<S22>/Data Store Write4' incorporates:
   *  DataTypeConversion: '<S46>/OutDTConv'
   */
  if (localLookupTablenD < 32768.0F) {
    if (localLookupTablenD >= -32768.0F) {
      AFA_rMassGrdBurnRspg_agCkIn = (SInt16)localLookupTablenD;
    } else {
      AFA_rMassGrdBurnRspg_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRspg_agCkIn = MAX_int16_T;
  }

  /* Product: '<S45>/Product4' incorporates:
   *  Constant: '<S45>/offset'
   *  Constant: '<S45>/one_on_slope'
   *  Sum: '<S45>/Add1'
   */
  localSwitch1_g = 327680.0F * localProduct7_a;

  /* Switch: '<S45>/Switch1' incorporates:
   *  Constant: '<S45>/offset2'
   *  Constant: '<S45>/offset3'
   *  Constant: '<S45>/offset4'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  Sum: '<S45>/Add3'
   *  Sum: '<S45>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localLookupTablenD = localSwitch1_g + 0.5F;
  } else {
    localLookupTablenD = localSwitch1_g - 0.5F;
  }

  /* DataStoreWrite: '<S22>/Data Store Write5' incorporates:
   *  DataTypeConversion: '<S45>/OutDTConv'
   */
  if (localLookupTablenD < 32768.0F) {
    if (localLookupTablenD >= -32768.0F) {
      AFA_rMassGrdBurnRspgTot_agCkIn = (SInt16)localLookupTablenD;
    } else {
      AFA_rMassGrdBurnRspgTot_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRspgTot_agCkIn = MAX_int16_T;
  }

  /* end of Outputs for SubSystem: '<S3>/F02_calcul_derive_VVT' */

  /* Outputs for atomic SubSystem: '<S3>/F03_Calcul_derive_Pcol' *
   * Block requirements for '<S3>/F03_Calcul_derive_Pcol':
   *  1. SubSystem "F03_Calcul_derive_Pcol" !Trace_To : VEMS_R_11_04467_081.01 ;
   */

  /* Product: '<S49>/Product4' incorporates:
   *  Constant: '<S49>/offset'
   *  Constant: '<S49>/one_on_slope'
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   *  Product: '<S23>/Product2'
   *  Product: '<S23>/Product3'
   *  Product: '<S23>/Product4'
   *  Product: '<S23>/Product5'
   *  Sum: '<S49>/Add1'
   */
  localSwitch1_g = ((((localLookupTablenD_m * localSwitch1_d4) *
                      localDataTypeConversion1_n) * localLookupTablenD_mx) *
                    ((((Float32)(*rtu_AFA_mfArGrdVlv_rPresInEx)) * 0.001953125F)
                     - 1.279980469E+002F)) * 3.276800049E+003F;

  /* Switch: '<S49>/Switch1' incorporates:
   *  Constant: '<S49>/offset2'
   *  Constant: '<S49>/offset3'
   *  Constant: '<S49>/offset4'
   *  RelationalOperator: '<S49>/Relational Operator'
   *  Sum: '<S49>/Add3'
   *  Sum: '<S49>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S49>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_mGrdBurnRspg_pDsThr = (SInt16)localSwitch1_g;
    } else {
      AFA_mGrdBurnRspg_pDsThr = MIN_int16_T;
    }
  } else {
    AFA_mGrdBurnRspg_pDsThr = MAX_int16_T;
  }

  /* end of Outputs for SubSystem: '<S3>/F03_Calcul_derive_Pcol' */

  /* end of Outputs for SubSystem: '<Root>/F03_Reaspired_burn_mass' */

  /* Outputs for atomic SubSystem: '<Root>/F04_Atmospheric_residual_total_burn_mass' *
   * Block requirements for '<Root>/F04_Atmospheric_residual_total_burn_mass':
   *  1. SubSystem "F04_Atmospheric_residual_total_burn_mass" !Trace_To : VEMS_R_11_04467_082.01 ;
   */

  /* DataTypeConversion: '<S4>/Data Type Conversion3' */
  localAbs = (*rtu_AFA_agCkClsExVlvEstimRef1Fi) * 21845;
  localDataTypeConversion3_m = ((localAbs & 16384) != 0) + ((localAbs >= 0) ?
    ((SInt32)(((UInt32)localAbs) >> 15U)) : (~((SInt32)(((UInt32)
    (~localAbs)) >> 15U))));

  /* Abs: '<S4>/Abs' */
  if (localDataTypeConversion3_m < 0) {
    locallupIdx = (UInt32)(-localDataTypeConversion3_m);
    if (locallupIdx > 2147483647U) {
      localAbs = MAX_int32_T;
    } else {
      localAbs = (SInt32)locallupIdx;
    }
  } else {
    localAbs = localDataTypeConversion3_m;
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion5' */
  if (localAbs <= 0) {
    localDataTypeConversion5_k = 0U;
  } else if (localAbs > 65535) {
    localDataTypeConversion5_k = MAX_uint16_T;
  } else {
    localDataTypeConversion5_k = (UInt16)localAbs;
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion6' */
  localAbs = (*rtu_AFA_agCkOpInVlvEstimRef1Fil) * 21845;
  localAbs = ((localAbs & 16384) != 0) + ((localAbs >= 0) ? ((SInt32)
    (((UInt32)localAbs) >> 15U)) : (~((SInt32)(((UInt32)(~localAbs)) >> 15U))));
  if (localAbs > 32767) {
    localDataTypeConversion6 = MAX_int16_T;
  } else if (localAbs <= -32768) {
    localDataTypeConversion6 = MIN_int16_T;
  } else {
    localDataTypeConversion6 = (SInt16)localAbs;
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion4' */
  if (localDataTypeConversion3_m > 32767) {
    localDataTypeConversion4_p = MAX_int16_T;
  } else if (localDataTypeConversion3_m <= -32768) {
    localDataTypeConversion4_p = MIN_int16_T;
  } else {
    localDataTypeConversion4_p = (SInt16)localDataTypeConversion3_m;
  }

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/AirEfc_bVolBurnRgTot_C1'
   *  Lookup: '<S50>/Look-Up Table'
   */
  if (AirEfc_bVolBurnRgTot_C) {
    /* Lookup: '<S50>/Look-Up Table'
     * About '<S50>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    S16  2^-22  FSlope 1.28
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S16_U16( &(localLookUpTable), (&(AFA_rVolGrdCyl_T[0])),
                   localDataTypeConversion5_k, (&(AFA_agCk_facTDCGrd_A[0])), 18U);

    /* DataTypeDuplicate Block: '<S50>/Data Type Duplicate1'
     *
     * Regarding '<S50>/Data Type Duplicate1':
     *   Unused code path elimination
     */
    locallocalOutDTConv_k = localLookUpTable;
  } else {
    /* Lookup2D: '<S53>/Look-Up Table (2-D)'
     * About '<S53>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    S16  2^-19  FSlope 1.6
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_S16_S16_S16( &(localLookUpTable2D), (&(AFA_rVolCylGrd_agCkClsEx_M[0])),
                       localDataTypeConversion6, (&(AirEfc_agCkOpInVlvY_A[0])),
                       12U, localDataTypeConversion4_p,
                       (&(AFA_agCkGrdClsExVlvX_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate2'
     *
     * Regarding '<S53>/Data Type Duplicate2':
     *   Unused code path elimination
     */
    localAbs = localLookUpTable2D * 10;
    if (localAbs > 32767) {
      locallocalOutDTConv_k = MAX_int16_T;
    } else if (localAbs <= -32768) {
      locallocalOutDTConv_k = MIN_int16_T;
    } else {
      locallocalOutDTConv_k = (SInt16)localAbs;
    }
  }

  /* DataStoreWrite: '<S4>/Data Store Write' */
  AFA_rVolGrdCyl_MP = locallocalOutDTConv_k;

  /* Switch: '<S4>/Switch3' incorporates:
   *  Constant: '<S4>/AirEfc_bVolBurnRgTot_C2'
   *  Constant: '<S4>/diff_IVO_AirEfc_rVolCyl_T'
   *  Lookup2D: '<S54>/Look-Up Table (2-D)'
   */
  if (AirEfc_bVolBurnRgTot_C) {
    localOutDTConv_oa = 0;
  } else {
    /* Lookup2D: '<S54>/Look-Up Table (2-D)'
     * About '<S54>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    S16  2^-19  FSlope 1.6
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_S16_S16_S16( &(localLookUpTable2D_p), (&(AFA_rVolCylGrd_agCkOpIn_M[0])),
                       localDataTypeConversion6, (&(AFA_agCkGrdOpInVlvY_A[0])),
                       11U, localDataTypeConversion4_p,
                       (&(AirEfc_agCkClsExVlvX_A[0])), 12U);

    /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate2'
     *
     * Regarding '<S54>/Data Type Duplicate2':
     *   Unused code path elimination
     */
    localOutDTConv_oa = localLookUpTable2D_p;
  }

  /* DataStoreWrite: '<S4>/Data Store Write1' */
  AFA_rVolCylGrd_agCkOpIn_MP = localOutDTConv_oa;

  /* Lookup2D: '<S55>/Look-Up Table (2-D)'
   * About '<S55>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
   * Output0 Data Type:  Fixed Point    S16  2^-19  FSlope 1.6
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_S16_U16_S16( &(localOutDTConv_g), (&(AFA_facCorMassGrdBurnRg_M[0])),
                     (*rtu_AFA_nEngFil), (&(AirEfc_nEngY_A[0])), 17U,
                     localDataTypeConversion4_p, (&(AFA_agCkGrdClsExVlvX_A[0])),
                     11U);

  /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate2'
   *
   * Regarding '<S55>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* SignalConversion Block: '<S4>/Signal Conversion2'
   *
   * Regarding '<S4>/Signal Conversion2':
   *   Eliminate redundant signal conversion block
   */

  /* DataStoreWrite: '<S4>/Data Store Write2' */
  AFA_facCorMassGrdBurnRg_MP = localOutDTConv_g;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/AirEfc_bVolBurnRgTot_C'
   *  Lookup2D: '<S52>/Look-Up Table (2-D)'
   *  Lookup: '<S51>/Look-Up Table'
   */
  if (AirEfc_bVolBurnRgTot_C) {
    /* Lookup: '<S51>/Look-Up Table'
     * About '<S51>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_l), (&(AirEfc_rVolCyl_T[0])),
                   localDataTypeConversion5_k, (&(AirEfc_agCk_facTDC_A[0])), 19U);

    /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate1'
     *
     * Regarding '<S51>/Data Type Duplicate1':
     *   Unused code path elimination
     */
    localOutDTConv_k4 = localLookUpTable_l;
  } else {
    /* Lookup2D: '<S52>/Look-Up Table (2-D)'
     * About '<S52>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Input1  Data Type:  Fixed Point    S16  2^-4  FSlope 1.5
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_S16_S16( &(localLookUpTable2D_m), (&(AirEfc_rVolCyl_M[0])),
                       localDataTypeConversion6, (&(AirEfc_agCkOpInVlvY_A[0])),
                       12U, localDataTypeConversion4_p,
                       (&(AirEfc_agCkClsExVlvX_A[0])), 12U);

    /* DataTypeDuplicate Block: '<S52>/Data Type Duplicate2'
     *
     * Regarding '<S52>/Data Type Duplicate2':
     *   Unused code path elimination
     */
    localOutDTConv_k4 = localLookUpTable2D_m;
  }

  /* DataStoreWrite: '<S4>/Data Store Write3' */
  AFA_rVolCyl_MP = localOutDTConv_k4;

  /* DataTypeConversion: '<S4>/Data Type Conversion7' */
  localSwitch1_es = ((Float32)localOutDTConv_k4) * 3.051757813E-005F;

  /* Lookup_n-D: '<S56>/Lookup Table (n-D)' */
  localLookupTablenD_d = look2_1fc22bc2bcvbfbbr6nfbbnx((*rtu_AFA_nEngFil),
    localDataTypeConversion4_p, (&(AirEfc_nEngY_A[0])),
    (&(AirEfc_agCkClsExVlvX_A[0])), (&(AirEfc_facCorMassBurnRg_M[0])),
    &AFA_F07_Residual_scaveng_ConstP.LookupTablenD_maxIn_a[0], 18U);

  /* If: '<S57>/If2' incorporates:
   *  ActionPort: '<S62>/Action Port'
   *  ActionPort: '<S63>/Action Port'
   *  Constant: '<S57>/Constant7'
   *  RelationalOperator: '<S57>/Relational Operator'
   *  SubSystem: '<S57>/If Action Subsystem2'
   *  SubSystem: '<S57>/If Action Subsystem3'
   */
  if ((*rtu_AFA_tExMnfEstimFi7) == 0) {
    /* Constant: '<S62>/Byp_Fonction_SC' */
    localSwitch1_g = 0.0F;
  } else {
    /* Product: '<S63>/Divide1' incorporates:
     *  Constant: '<S4>/AirEfc_tRef_C'
     */
    localSwitch1_g = (((Float32)AirEfc_tRef_C) * 0.0078125F) / (((Float32)
      (*rtu_AFA_tExMnfEstimFi7)) * 0.03125F);
  }

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/AirEfc_pRef_C'
   *  Product: '<S4>/Divide'
   */
  localLookupTablenD = (localDataTypeConversion / (((Float32)AirEfc_pRef_C) *
    8.0F)) * localSwitch1_g;

  /* Product: '<S4>/Product5' incorporates:
   *  Product: '<S4>/Product1'
   */
  localDivide1_b = (localLookupTablenD_d * localLookupTablenD) * localSwitch1_es;

  /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
   *  Constant: '<S58>/offset'
   *  Constant: '<S58>/offset1'
   *  Constant: '<S58>/one_on_slope'
   *  DataTypeConversion: '<S58>/OutDTConv'
   *  Product: '<S58>/Product4'
   *  Sum: '<S58>/Add1'
   *  Sum: '<S58>/Add2'
   */
  localSwitch1_g = (16384.0F * localDivide1_b) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_rMassBurnRgTot = (UInt16)localSwitch1_g;
    } else {
      AFA_rMassBurnRgTot = 0U;
    }
  } else {
    AFA_rMassBurnRgTot = MAX_uint16_T;
  }

  /* Product: '<S4>/Product9' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   *  Product: '<S4>/Product7'
   */
  localProduct2_g = ((((Float32)localOutDTConv_oa) * 3.051757858E-006F) *
                     localLookupTablenD_d) * localLookupTablenD;

  /* Product: '<S59>/Product4' incorporates:
   *  Constant: '<S59>/offset'
   *  Constant: '<S59>/one_on_slope'
   *  Sum: '<S59>/Add1'
   */
  localSwitch1_g = 327680.0F * localProduct2_g;

  /* Switch: '<S59>/Switch1' incorporates:
   *  Constant: '<S59>/offset2'
   *  Constant: '<S59>/offset3'
   *  Constant: '<S59>/offset4'
   *  RelationalOperator: '<S59>/Relational Operator'
   *  Sum: '<S59>/Add3'
   *  Sum: '<S59>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S4>/Data Store Write5' incorporates:
   *  DataTypeConversion: '<S59>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassGrdBurnRgTot_agCkIn = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassGrdBurnRgTot_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRgTot_agCkIn = MAX_int16_T;
  }

  /* Product: '<S4>/Product11' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion1'
   *  Product: '<S4>/Product3'
   *  Product: '<S4>/Product6'
   *  Sum: '<S4>/Add'
   */
  localSwitch1_es = (((Float32)((((Float32d)localOutDTConv_g) *
    3.0517578125000002E-006F) * ((Float32d)localSwitch1_es))) + ((((Float32)
    locallocalOutDTConv_k) * 3.051757744E-007F) * localLookupTablenD_d)) *
    localLookupTablenD;

  /* Product: '<S60>/Product4' incorporates:
   *  Constant: '<S60>/offset'
   *  Constant: '<S60>/one_on_slope'
   *  Sum: '<S60>/Add1'
   */
  localSwitch1_g = 327680.0F * localSwitch1_es;

  /* Switch: '<S60>/Switch1' incorporates:
   *  Constant: '<S60>/offset2'
   *  Constant: '<S60>/offset3'
   *  Constant: '<S60>/offset4'
   *  RelationalOperator: '<S60>/Relational Operator'
   *  Sum: '<S60>/Add3'
   *  Sum: '<S60>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S60>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      localOutDTConv_g = (SInt16)localSwitch1_g;
    } else {
      localOutDTConv_g = MIN_int16_T;
    }
  } else {
    localOutDTConv_g = MAX_int16_T;
  }

  /* DataStoreWrite: '<S4>/Data Store Write6' */
  AFA_rMassGrdBurnRgTot_agCkEx = localOutDTConv_g;

  /* end of Outputs for SubSystem: '<Root>/F04_Atmospheric_residual_total_burn_mass' */

  /* Outputs for atomic SubSystem: '<Root>/F05_Atmospheric_residual_burn_mass' *
   * Block requirements for '<Root>/F05_Atmospheric_residual_burn_mass':
   *  1. SubSystem "F05_Atmospheric_residual_burn_mass" !Trace_To : VEMS_R_11_04467_083.01 ;
   */

  /* Switch: '<S5>/Switch7' incorporates:
   *  Constant: '<S5>/AirEfc_agCkVlvOvlpLim_C'
   *  Constant: '<S5>/AirEfc_bBoostCf_C'
   *  Constant: '<S5>/Constant7'
   *  RelationalOperator: '<S5>/Relational Operator2'
   */
  if (AirEfc_bBoostCf_C) {
    localCompare_c = ((*rtu_AFA_agCkVlvOvlp) > ((AirEfc_agCkVlvOvlpLim_C + -128)
      << 4));
  } else {
    localCompare_c = FALSE;
  }

  /* Switch: '<S5>/Switch8' incorporates:
   *  Constant: '<S5>/Constant8'
   *  Constant: '<S5>/Constant9'
   *  MinMax: '<S5>/MinMax'
   */
  if (localCompare_c) {
    localSwitch1_g = 0.0F;
  } else {
    localSwitch1_g = rt_MINf(localProduct5_l, 0.0F);
  }

  /* Sum: '<S5>/Sum' */
  localLookupTablenD_m = localDivide1_b + localSwitch1_g;

  /* Product: '<S64>/Product4' incorporates:
   *  Constant: '<S64>/offset'
   *  Constant: '<S64>/one_on_slope'
   *  Sum: '<S64>/Add1'
   */
  localSwitch1_g = 8192.0F * localLookupTablenD_m;

  /* Switch: '<S64>/Switch1' incorporates:
   *  Constant: '<S64>/offset2'
   *  Constant: '<S64>/offset3'
   *  Constant: '<S64>/offset4'
   *  RelationalOperator: '<S64>/Relational Operator'
   *  Sum: '<S64>/Add3'
   *  Sum: '<S64>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S5>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S64>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassBurnRgCor = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassBurnRgCor = MIN_int16_T;
    }
  } else {
    AFA_rMassBurnRgCor = MAX_int16_T;
  }

  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  localRelationalOperator1 = (localLookupTablenD_m < 0.0F);

  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  localRelationalOperator_k = (localProduct5_l < 0.0F);

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  if (localCompare_c) {
    localSwitch1_g = 0.0F;
  } else {
    /* Switch: '<S5>/Switch6' incorporates:
     *  Constant: '<S5>/Constant5'
     */
    if (!localRelationalOperator_k) {
      localProduct7_a = 0.0F;
    }

    localSwitch1_g = localProduct7_a;
  }

  /* Sum: '<S5>/Sum2' */
  localSwitch1_d4 = localSwitch1_g + localProduct2_g;

  /* Switch: '<S5>/Switch5' incorporates:
   *  Constant: '<S5>/Constant6'
   */
  if (localRelationalOperator1) {
    localProduct7_a = 0.0F;
  } else {
    localProduct7_a = localSwitch1_d4;
  }

  /* Product: '<S66>/Product4' incorporates:
   *  Constant: '<S66>/offset'
   *  Constant: '<S66>/one_on_slope'
   *  Sum: '<S66>/Add1'
   */
  localSwitch1_g = 327680.0F * localProduct7_a;

  /* Switch: '<S66>/Switch1' incorporates:
   *  Constant: '<S66>/offset2'
   *  Constant: '<S66>/offset3'
   *  Constant: '<S66>/offset4'
   *  RelationalOperator: '<S66>/Relational Operator'
   *  Sum: '<S66>/Add3'
   *  Sum: '<S66>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S5>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S66>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassGrdBurnRgSat_agCkIn = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassGrdBurnRgSat_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRgSat_agCkIn = MAX_int16_T;
  }

  /* Product: '<S67>/Product4' incorporates:
   *  Constant: '<S67>/offset'
   *  Constant: '<S67>/one_on_slope'
   *  Sum: '<S67>/Add1'
   */
  localSwitch1_g = 327680.0F * localSwitch1_d4;

  /* Switch: '<S67>/Switch1' incorporates:
   *  Constant: '<S67>/offset2'
   *  Constant: '<S67>/offset3'
   *  Constant: '<S67>/offset4'
   *  RelationalOperator: '<S67>/Relational Operator'
   *  Sum: '<S67>/Add3'
   *  Sum: '<S67>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S5>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<S67>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassGrdBurnRgCor_agCkIn = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassGrdBurnRgCor_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRgCor_agCkIn = MAX_int16_T;
  }

  /* MinMax: '<S5>/MinMax1' incorporates:
   *  Constant: '<S5>/Constant10'
   */
  localLookupTablenD_mx = rt_MAXf(localLookupTablenD_m, 0.0F);

  /* DataStoreWrite: '<S5>/Data Store Write3' incorporates:
   *  Constant: '<S65>/offset'
   *  Constant: '<S65>/offset1'
   *  Constant: '<S65>/one_on_slope'
   *  DataTypeConversion: '<S65>/OutDTConv'
   *  Product: '<S65>/Product4'
   *  Sum: '<S65>/Add1'
   *  Sum: '<S65>/Add2'
   */
  localSwitch1_g = (16384.0F * localLookupTablenD_mx) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    AFA_rMassBurnRgCorSat = (UInt16)localSwitch1_g;
  } else {
    AFA_rMassBurnRgCorSat = MAX_uint16_T;
  }

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  if (localCompare_c) {
    localSwitch1_g = 0.0F;
  } else {
    /* Switch: '<S5>/Switch4' incorporates:
     *  Constant: '<S5>/Constant4'
     */
    if (!localRelationalOperator_k) {
      localProduct5_h = 0.0F;
    }

    localSwitch1_g = localProduct5_h;
  }

  /* Sum: '<S5>/Sum1' */
  localDivide1_b = localSwitch1_g + localSwitch1_es;

  /* Product: '<S68>/Product4' incorporates:
   *  Constant: '<S68>/offset'
   *  Constant: '<S68>/one_on_slope'
   *  Sum: '<S68>/Add1'
   */
  localSwitch1_g = 327680.0F * localDivide1_b;

  /* Switch: '<S68>/Switch1' incorporates:
   *  Constant: '<S68>/offset2'
   *  Constant: '<S68>/offset3'
   *  Constant: '<S68>/offset4'
   *  RelationalOperator: '<S68>/Relational Operator'
   *  Sum: '<S68>/Add3'
   *  Sum: '<S68>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S5>/Data Store Write4' incorporates:
   *  DataTypeConversion: '<S68>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassGrdBurnRgCor_agCkEx = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassGrdBurnRgCor_agCkEx = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRgCor_agCkEx = MAX_int16_T;
  }

  /* Switch: '<S5>/Switch3' incorporates:
   *  Constant: '<S5>/Constant11'
   */
  if (localRelationalOperator1) {
    localProduct2_g = 0.0F;
  } else {
    localProduct2_g = localDivide1_b;
  }

  /* Product: '<S69>/Product4' incorporates:
   *  Constant: '<S69>/offset'
   *  Constant: '<S69>/one_on_slope'
   *  Sum: '<S69>/Add1'
   */
  localSwitch1_g = 327680.0F * localProduct2_g;

  /* Switch: '<S69>/Switch1' incorporates:
   *  Constant: '<S69>/offset2'
   *  Constant: '<S69>/offset3'
   *  Constant: '<S69>/offset4'
   *  RelationalOperator: '<S69>/Relational Operator'
   *  Sum: '<S69>/Add3'
   *  Sum: '<S69>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S5>/Data Store Write5' incorporates:
   *  DataTypeConversion: '<S69>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassGrdBurnRgSat_agCkEx = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassGrdBurnRgSat_agCkEx = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBurnRgSat_agCkEx = MAX_int16_T;
  }

  /* end of Outputs for SubSystem: '<Root>/F05_Atmospheric_residual_burn_mass' */

  /* Outputs for atomic SubSystem: '<Root>/F10_Engine_speed_choice' */

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/AFA_bAcvEngSpdCorScv_C'
   */
  if (AFA_bAcvEngSpdCorScv_C) {
    AFA_nEngCorScvFil = (*rtu_AFA_nEngCorFil);
  } else {
    AFA_nEngCorScvFil = (*rtu_AFA_nEngFil);
  }

  /* end of Outputs for SubSystem: '<Root>/F10_Engine_speed_choice' */

  /* Outputs for atomic SubSystem: '<Root>/F06_Scavenged_total_mass' *
   * Block requirements for '<Root>/F06_Scavenged_total_mass':
   *  1. SubSystem "F06_Scavenged_total_mass" !Trace_To : VEMS_R_11_04467_084.02 ;
   */

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/AirEfc_nEngThdVal_C'
   */
  localCompare_c = (AFA_nEngCorScvFil >= AirEfc_nEngThdVal_C);

  /* Outputs for enable SubSystem: '<S6>/F01_Scavenged_total_mass_cal' incorporates:
   *  Constant: '<S6>/AirEfc_bBoost_C'
   *  EnablePort: '<S70>/Enable'
   *  Logic: '<S6>/Logical Operator'
   *
   * Block requirements for '<S6>/F01_Scavenged_total_mass_cal':
   *  1. SubSystem "F01_Scavenged_total_mass_cal" !Trace_To : VEMS_R_11_04467_085.02 ;
   */
  if (AirEfc_bBoost_C && (localCompare_c)) {
    /* DataTypeConversion: '<S75>/Data Type Conversion' */
    if ((*rtu_AFA_tAirUsInVlvEstimFil) > 2147483647U) {
      localAbs = MAX_int32_T;
    } else {
      localAbs = (SInt32)(*rtu_AFA_tAirUsInVlvEstimFil);
    }

    localAbs += -28544;
    if (localAbs <= 0) {
      localOutDTConv_aa = 0U;
    } else if (localAbs > 65535) {
      localOutDTConv_aa = MAX_uint16_T;
    } else {
      localOutDTConv_aa = (UInt16)localAbs;
    }

    /* Lookup: '<S75>/Look-Up Table'
     * About '<S75>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_h), (&(AirEfc_facTInSqrt_T[0])),
                   localOutDTConv_aa, (&(AirEfc_tAirUsInVlv_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S75>/Data Type Duplicate1'
     *
     * Regarding '<S75>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* SignalConversion Block: '<S70>/Signal Conversion1'
     *
     * Regarding '<S70>/Signal Conversion1':
     *   Eliminate redundant signal conversion block
     */

    /* DataStoreWrite: '<S70>/Data Store Write1' */
    AFA_facTInSqrt_MP = localLookUpTable_h;

    /* Product: '<S78>/Divide' */
    localSwitch1_g = localDataTypeConversion / localDataTypeConversion1;

    /* Outputs for atomic SubSystem: '<S78>/If Action Subsystem3' */

    /* Switch: '<S88>/Switch1' incorporates:
     *  Constant: '<S88>/Constant2'
     *  RelationalOperator: '<S88>/Relational Operator'
     *  Saturate: '<S88>/Saturation'
     */
    if (localSwitch1_g != localSwitch1_g) {
      localSwitch1_g = 0.0F;
    } else {
      localSwitch1_g = rt_SATURATE(localSwitch1_g, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S78>/If Action Subsystem3' */

    /* Switch: '<S84>/Switch2' incorporates:
     *  Constant: '<S70>/Constant3'
     *  RelationalOperator: '<S84>/LowerRelop1'
     */
    if (localSwitch1_g > 1.0F) {
      localSwitch1_g = 1.0F;
    } else {
      /* Switch: '<S84>/Switch' incorporates:
       *  Constant: '<S70>/Constant6'
       *  RelationalOperator: '<S84>/UpperRelop'
       */
      if (localSwitch1_g < 0.0F) {
        localSwitch1_g = 0.0F;
      }
    }

    /* Sum: '<S80>/Add2' incorporates:
     *  Constant: '<S80>/offset'
     *  Constant: '<S80>/offset1'
     *  Constant: '<S80>/one_on_slope'
     *  Product: '<S80>/Product4'
     *  Sum: '<S80>/Add1'
     */
    localSwitch1_g = (65536.0F * localSwitch1_g) + 0.5F;

    /* DataTypeConversion: '<S80>/OutDTConv' */
    if (localSwitch1_g < 4.294967296E+009F) {
      locallupIdx = (UInt32)localSwitch1_g;
    } else {
      locallupIdx = MAX_uint32_T;
    }

    /* Product: '<S70>/Product2' incorporates:
     *  Lookup_n-D: '<S74>/Lookup Table (n-D)'
     *  Lookup_n-D: '<S79>/Lookup Table (n-D)'
     */
    localSwitch1_g = look2_1fc22bc2bcvbfbbr6dfbbnx(AFA_nEngCorScvFil,
      (*rtu_AFA_agCkVlvOvlp), (&(AirEfc_nEng2Y_A[0])), (&(AirEfc_agCkVlvOvlpX_A
      [0])), (&(AirEfc_mfAirScvRed_M[0])),
      &AFA_F07_Residual_scaveng_ConstP.LookupTablenD_maxIn_l[0], 8U) *
      look1_iu32lftu16n16If_binlcns(locallupIdx, (&(AirEfc_rPresEngX_A[0])),
      (&(AirEfc_facChrExp_T[0])), 10U);

    /* DataTypeConversion: '<S81>/OutDTConv' incorporates:
     *  Constant: '<S81>/offset'
     *  Constant: '<S81>/offset1'
     *  Constant: '<S81>/one_on_slope'
     *  Product: '<S81>/Product4'
     *  Sum: '<S81>/Add1'
     *  Sum: '<S81>/Add2'
     */
    localLookupTablenD_d = (65536.0F * localSwitch1_g) + 0.5F;
    if (localLookupTablenD_d < 65536.0F) {
      if (localLookupTablenD_d >= 0.0F) {
        localOutDTConv_aa = (UInt16)localLookupTablenD_d;
      } else {
        localOutDTConv_aa = 0U;
      }
    } else {
      localOutDTConv_aa = MAX_uint16_T;
    }

    /* DataStoreWrite: '<S70>/Data Store Write2' */
    AFA_mfAirScvRedCor_MP = localOutDTConv_aa;

    /* Product: '<S77>/Divide' incorporates:
     *  Constant: '<S70>/AirEfc_pRef_C'
     *  DataTypeConversion: '<S70>/Data Type Conversion5'
     *  Product: '<S70>/Divide1'
     *  Product: '<S70>/Product'
     *  Product: '<S70>/Product1'
     *  Product: '<S70>/Product7'
     */
    localSwitch1_g = ((((localDataTypeConversion1 / (((Float32)AirEfc_pRef_C) *
      8.0F)) * localSwitch1_g) * (((Float32)localLookUpTable_h) *
      3.051757813E-005F)) * localDataTypeConversion1_n) / localProduct2_o;

    /* Outputs for atomic SubSystem: '<S77>/If Action Subsystem3' */

    /* Switch: '<S86>/Switch1' incorporates:
     *  Constant: '<S86>/Constant2'
     *  DataTypeConversion: '<S77>/Data Type Conversion2'
     *  RelationalOperator: '<S86>/Relational Operator'
     *  Saturate: '<S86>/Saturation'
     */
    if (localSwitch1_g != localSwitch1_g) {
      localB->Merge = 0.0F;
    } else {
      localB->Merge = rt_SATURATE(localSwitch1_g, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S77>/If Action Subsystem3' */
  }

  /* end of Outputs for SubSystem: '<S6>/F01_Scavenged_total_mass_cal' */

  /* Outputs for enable SubSystem: '<S6>/F02_Scavenged_total_mass_init' incorporates:
   *  Constant: '<S6>/AirEfc_bBoost_C1'
   *  EnablePort: '<S71>/Enable'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator2'
   *
   * Block requirements for '<S6>/F02_Scavenged_total_mass_init':
   *  1. SubSystem "F02_Scavenged_total_mass_init" !Trace_To : VEMS_R_11_04467_086.01 ;
   */
  if (AirEfc_bBoost_C && (!localCompare_c)) {
    /* Constant: '<S71>/Constant1' */
    localB->Merge = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S6>/F02_Scavenged_total_mass_init' */

  /* DataStoreWrite: '<S6>/Data Store Write3' incorporates:
   *  Constant: '<S73>/offset'
   *  Constant: '<S73>/offset1'
   *  Constant: '<S73>/one_on_slope'
   *  DataTypeConversion: '<S73>/OutDTConv'
   *  Product: '<S73>/Product4'
   *  Sum: '<S73>/Add1'
   *  Sum: '<S73>/Add2'
   */
  localSwitch1_g = (16384.0F * localB->Merge) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_rMassAirScvTot = (UInt16)localSwitch1_g;
    } else {
      AFA_rMassAirScvTot = 0U;
    }
  } else {
    AFA_rMassAirScvTot = MAX_uint16_T;
  }

  /* Outputs for enable SubSystem: '<S6>/F03_Calc_Sensitivity_Mbaltot' incorporates:
   *  Constant: '<S6>/AirEfc_bBoost_C2'
   *  EnablePort: '<S72>/Enable'
   *
   * Block requirements for '<S6>/F03_Calc_Sensitivity_Mbaltot':
   *  1. SubSystem "F03_Calc_Sensitivity_Mbaltot" !Trace_To : VEMS_R_11_04467_087.01 ;
   */
  if (AirEfc_bBoost_C) {
    /* DataTypeConversion: '<S89>/OutDTConv' incorporates:
     *  Constant: '<S89>/offset'
     *  Constant: '<S89>/offset1'
     *  Constant: '<S89>/one_on_slope'
     *  DataTypeConversion: '<S72>/Data Type Conversion'
     *  Product: '<S72>/Product'
     *  Product: '<S89>/Product4'
     *  Sum: '<S89>/Add1'
     *  Sum: '<S89>/Add2'
     */
    localSwitch1_g = (((((Float32)(*rtu_AFA_mfArGrdVlv_rPresExIn)) *
                        0.001953125F) * localB->Merge) * 1.310719997E-001F) +
      0.5F;
    if (localSwitch1_g < 65536.0F) {
      if (localSwitch1_g >= 0.0F) {
        AFA_mGrdAirScvTot_pDsThr = (UInt16)localSwitch1_g;
      } else {
        AFA_mGrdAirScvTot_pDsThr = 0U;
      }
    } else {
      AFA_mGrdAirScvTot_pDsThr = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S6>/F03_Calc_Sensitivity_Mbaltot' */

  /* end of Outputs for SubSystem: '<Root>/F06_Scavenged_total_mass' */

  /* Outputs for atomic SubSystem: '<Root>/F07_Balancing_scavenged_and_residual_mass' *
   * Block requirements for '<Root>/F07_Balancing_scavenged_and_residual_mass':
   *  1. SubSystem "F07_Balancing_scavenged_and_residual_mass" !Trace_To : VEMS_R_11_04467_088.02 ;
   */

  /* Outputs for atomic SubSystem: '<S7>/F01_scavenged_and_residual_mass' *
   * Block requirements for '<S7>/F01_scavenged_and_residual_mass':
   *  1. SubSystem "F01_scavenged_and_residual_mass" !Trace_To : VEMS_R_11_04467_089.02 ;
   */

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S90>/AirEfc_bRhoAir_C'
   *  Product: '<S90>/Product'
   */
  if (AirEfc_bRhoAir_C) {
    /* Product: '<S98>/Divide' incorporates:
     *  DataTypeConversion: '<S90>/Data Type Conversion'
     *  DataTypeConversion: '<S90>/Data Type Conversion1'
     */
    localSwitch1_g = (((Float32)(*rtu_AFA_tExMnfEstimFi7)) * 0.03125F) /
      (((Float32)(*rtu_AFA_tAirUsInVlvEstimFil)) * 0.0078125F);

    /* Outputs for atomic SubSystem: '<S98>/If Action Subsystem3' */

    /* Switch: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant2'
     *  RelationalOperator: '<S100>/Relational Operator'
     *  Saturate: '<S100>/Saturation'
     */
    if (localSwitch1_g != localSwitch1_g) {
      localSwitch1_g = 0.0F;
    } else {
      localSwitch1_g = rt_SATURATE(localSwitch1_g, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S98>/If Action Subsystem3' */
    localSwitch1_g *= localLookupTablenD_m;
  } else {
    localSwitch1_g = localLookupTablenD_m;
  }

  /* Sum: '<S90>/Sum1' */
  localSwitch1_es = localB->Merge + localSwitch1_g;

  /* end of Outputs for SubSystem: '<S7>/F01_scavenged_and_residual_mass' */

  /* RelationalOperator: '<S7>/Relational Operator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  localCompare_c = (localSwitch1_es > 0.0F);

  /* Outputs for enable SubSystem: '<S7>/F02_balancing_mass_cal' incorporates:
   *  Constant: '<S7>/AirEfc_bBoost_C'
   *  EnablePort: '<S91>/Enable'
   *  Logic: '<S7>/Logical Operator'
   *
   * Block requirements for '<S7>/F02_balancing_mass_cal':
   *  1. SubSystem "F02_balancing_mass_cal" !Trace_To : VEMS_R_11_04467_090.02 ;
   */
  if (AirEfc_bBoost_C && (localCompare_c)) {
    /* Product: '<S101>/Divide' */
    localSwitch1_g = localB->Merge / localSwitch1_es;

    /* Outputs for atomic SubSystem: '<S101>/If Action Subsystem3' */

    /* Switch: '<S106>/Switch1' incorporates:
     *  Constant: '<S106>/Constant2'
     *  RelationalOperator: '<S106>/Relational Operator'
     *  Saturate: '<S106>/Saturation'
     */
    if (localSwitch1_g != localSwitch1_g) {
      localSwitch1_g = 0.0F;
    } else {
      localSwitch1_g = rt_SATURATE(localSwitch1_g, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S101>/If Action Subsystem3' */

    /* Sum: '<S103>/Add2' incorporates:
     *  Constant: '<S103>/offset'
     *  Constant: '<S103>/offset1'
     *  Constant: '<S103>/one_on_slope'
     *  Product: '<S103>/Product4'
     *  Sum: '<S103>/Add1'
     */
    localSwitch1_g = (65536.0F * localSwitch1_g) + 0.5F;

    /* DataTypeConversion: '<S103>/OutDTConv' */
    if (localSwitch1_g < 65536.0F) {
      if (localSwitch1_g >= 0.0F) {
        localOutDTConv_k4 = (UInt16)localSwitch1_g;
      } else {
        localOutDTConv_k4 = 0U;
      }
    } else {
      localOutDTConv_k4 = MAX_uint16_T;
    }

    /* Lookup_n-D: '<S102>/Lookup Table (n-D)' */
    localSwitch1_g = look2_1fcv2bcvbcvbfbbr6dfbbnx(AFA_nEngCorScvFil,
      localOutDTConv_k4, (&(AirEfc_nEng2Y_A[0])), (&(AirEfc_facAirScvX_A[0])), (
      &(AirEfc_facAirScv_M[0])),
      &AFA_F07_Residual_scaveng_ConstP.LookupTablenD_maxIn_f[0], 8U);

    /* Sum: '<S91>/Sum' incorporates:
     *  Constant: '<S91>/Constant2'
     *  Product: '<S91>/Product'
     *  Sum: '<S91>/Sum2'
     */
    localLookupTablenD = localLookupTablenD_m - ((1.0F - localSwitch1_g) *
      localB->Merge);

    /* MinMax: '<S91>/MinMax1' incorporates:
     *  Constant: '<S91>/Constant1'
     */
    localB->Merge1 = rt_MAXf(localLookupTablenD, 0.0F);

    /* DataTypeConversion: '<S104>/OutDTConv' incorporates:
     *  Constant: '<S104>/offset'
     *  Constant: '<S104>/offset1'
     *  Constant: '<S104>/one_on_slope'
     *  Product: '<S104>/Product4'
     *  Product: '<S91>/Product1'
     *  Sum: '<S104>/Add1'
     *  Sum: '<S104>/Add2'
     */
    localSwitch1_g = ((localB->Merge * localSwitch1_g) * 16384.0F) + 0.5F;
    if (localSwitch1_g < 65536.0F) {
      if (localSwitch1_g >= 0.0F) {
        AFA_rMassAirScv = (UInt16)localSwitch1_g;
      } else {
        AFA_rMassAirScv = 0U;
      }
    } else {
      AFA_rMassAirScv = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S7>/F02_balancing_mass_cal' */

  /* Outputs for enable SubSystem: '<S7>/F03_balancing_mass_Def' incorporates:
   *  Constant: '<S7>/AirEfc_bBoost_C1'
   *  EnablePort: '<S92>/Enable'
   *  Logic: '<S7>/Logical Operator1'
   *  Logic: '<S7>/Logical Operator2'
   *
   * Block requirements for '<S7>/F03_balancing_mass_Def':
   *  1. SubSystem "F03_balancing_mass_Def" !Trace_To : VEMS_R_11_04467_091.01 ;
   */
  if ((!localCompare_c) && AirEfc_bBoost_C) {
    /* Constant: '<S92>/Constant1' */
    AFA_rMassAirScv = 0U;

    /* Constant: '<S92>/Constant2' */
    localB->Merge1 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S7>/F03_balancing_mass_Def' */

  /* DataStoreWrite: '<S7>/Data Store Write1' incorporates:
   *  Constant: '<S95>/offset'
   *  Constant: '<S95>/offset1'
   *  Constant: '<S95>/one_on_slope'
   *  DataTypeConversion: '<S95>/OutDTConv'
   *  Product: '<S95>/Product4'
   *  Sum: '<S95>/Add1'
   *  Sum: '<S95>/Add2'
   */
  localSwitch1_g = (16384.0F * localB->Merge1) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_rMassBurnRgBoostCorSat = (UInt16)localSwitch1_g;
    } else {
      AFA_rMassBurnRgBoostCorSat = 0U;
    }
  } else {
    AFA_rMassBurnRgBoostCorSat = MAX_uint16_T;
  }

  /* Outputs for atomic SubSystem: '<S7>/F04_calcul_derive_VVT' *
   * Block requirements for '<S7>/F04_calcul_derive_VVT':
   *  1. SubSystem "F04_calcul_derive_VVT" !Trace_To : VEMS_R_11_04467_092.01 ;
   */

  /* Switch: '<S93>/Switch1' incorporates:
   *  Constant: '<S107>/Constant'
   *  Constant: '<S93>/Constant6'
   *  RelationalOperator: '<S107>/Compare'
   */
  if (localLookupTablenD_m < 0.0F) {
    localDivide1_b = 0.0F;
  }

  /* Switch: '<S93>/Switch2' incorporates:
   *  Constant: '<S108>/Constant'
   *  Constant: '<S93>/Constant3'
   *  RelationalOperator: '<S108>/Compare'
   */
  if (localLookupTablenD_m < 0.0F) {
    localSwitch1_d4 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S7>/F04_calcul_derive_VVT' */

  /* Product: '<S96>/Product4' incorporates:
   *  Constant: '<S96>/offset'
   *  Constant: '<S96>/one_on_slope'
   *  Sum: '<S96>/Add1'
   */
  localSwitch1_g = 327680.0F * localDivide1_b;

  /* Switch: '<S96>/Switch1' incorporates:
   *  Constant: '<S96>/offset2'
   *  Constant: '<S96>/offset3'
   *  Constant: '<S96>/offset4'
   *  RelationalOperator: '<S96>/Relational Operator'
   *  Sum: '<S96>/Add3'
   *  Sum: '<S96>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S7>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<S96>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassGrdBnRgBstSat_agCkEx = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassGrdBnRgBstSat_agCkEx = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBnRgBstSat_agCkEx = MAX_int16_T;
  }

  /* Product: '<S97>/Product4' incorporates:
   *  Constant: '<S97>/offset'
   *  Constant: '<S97>/one_on_slope'
   *  Sum: '<S97>/Add1'
   */
  localSwitch1_g = 327680.0F * localSwitch1_d4;

  /* Switch: '<S97>/Switch1' incorporates:
   *  Constant: '<S97>/offset2'
   *  Constant: '<S97>/offset3'
   *  Constant: '<S97>/offset4'
   *  RelationalOperator: '<S97>/Relational Operator'
   *  Sum: '<S97>/Add3'
   *  Sum: '<S97>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataStoreWrite: '<S7>/Data Store Write3' incorporates:
   *  DataTypeConversion: '<S97>/OutDTConv'
   */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassGrdBnRgBstSat_agCkIn = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassGrdBnRgBstSat_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_rMassGrdBnRgBstSat_agCkIn = MAX_int16_T;
  }

  /* DataTypeConversion: '<S94>/OutDTConv' incorporates:
   *  Constant: '<S94>/offset'
   *  Constant: '<S94>/offset1'
   *  Constant: '<S94>/one_on_slope'
   *  Product: '<S94>/Product4'
   *  Sum: '<S94>/Add1'
   *  Sum: '<S94>/Add2'
   */
  localSwitch1_g = (65536.0F * localSwitch1_es) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_facAirScv = (UInt16)localSwitch1_g;
    } else {
      AFA_facAirScv = 0U;
    }
  } else {
    AFA_facAirScv = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<Root>/F07_Balancing_scavenged_and_residual_mass' */

  /* Outputs for atomic SubSystem: '<Root>/F08_residual_burn_mass' *
   * Block requirements for '<Root>/F08_residual_burn_mass':
   *  1. SubSystem "F08_residual_burn_mass" !Trace_To : VEMS_R_11_04467_093.01 ;
   */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/AirEfc_bBoost_C'
   */
  if (AirEfc_bBoost_C) {
    localLookupTablenD_mx = localB->Merge1;
  }

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S8>/AirEfc_bBoost_C1'
   */
  if (AirEfc_bBoost_C) {
    localProduct2_g = localDivide1_b;
  }

  /* Switch: '<S8>/Switch3' incorporates:
   *  Constant: '<S8>/AirEfc_bBoost_C2'
   */
  if (AirEfc_bBoost_C) {
    localProduct7_a = localSwitch1_d4;
  }

  /* end of Outputs for SubSystem: '<Root>/F08_residual_burn_mass' */

  /* Outputs for atomic SubSystem: '<Root>/F09_burn_mass' *
   * Block requirements for '<Root>/F09_burn_mass':
   *  1. SubSystem "F09_burn_mass" !Trace_To : VEMS_R_11_04467_094.01 ;
   */

  /* DataTypeConversion: '<S109>/OutDTConv' incorporates:
   *  Constant: '<S109>/offset'
   *  Constant: '<S109>/offset1'
   *  Constant: '<S109>/one_on_slope'
   *  Product: '<S109>/Product4'
   *  Sum: '<S109>/Add1'
   *  Sum: '<S109>/Add2'
   *  Sum: '<S9>/Sum'
   */
  localSwitch1_g = ((localLookupTablenD_mx + localmax) * 16384.0F) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      AFA_rMassBurn = (UInt16)localSwitch1_g;
    } else {
      AFA_rMassBurn = 0U;
    }
  } else {
    AFA_rMassBurn = MAX_uint16_T;
  }

  /* Product: '<S110>/Product4' incorporates:
   *  Constant: '<S110>/offset'
   *  Constant: '<S110>/one_on_slope'
   *  Sum: '<S110>/Add1'
   *  Sum: '<S9>/Sum1'
   */
  localSwitch1_g = (localProduct2_g + localSwitch_h) * 327680.0F;

  /* Switch: '<S110>/Switch1' incorporates:
   *  Constant: '<S110>/offset2'
   *  Constant: '<S110>/offset3'
   *  Constant: '<S110>/offset4'
   *  RelationalOperator: '<S110>/Relational Operator'
   *  Sum: '<S110>/Add3'
   *  Sum: '<S110>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S110>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassBurn_agCkEx = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassBurn_agCkEx = MIN_int16_T;
    }
  } else {
    AFA_rMassBurn_agCkEx = MAX_int16_T;
  }

  /* Product: '<S111>/Product4' incorporates:
   *  Constant: '<S111>/offset'
   *  Constant: '<S111>/one_on_slope'
   *  Sum: '<S111>/Add1'
   *  Sum: '<S9>/Sum2'
   */
  localSwitch1_g = (localProduct7_a + localSwitch1_b) * 327680.0F;

  /* Switch: '<S111>/Switch1' incorporates:
   *  Constant: '<S111>/offset2'
   *  Constant: '<S111>/offset3'
   *  Constant: '<S111>/offset4'
   *  RelationalOperator: '<S111>/Relational Operator'
   *  Sum: '<S111>/Add3'
   *  Sum: '<S111>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S111>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      AFA_rMassBurn_agCkIn = (SInt16)localSwitch1_g;
    } else {
      AFA_rMassBurn_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_rMassBurn_agCkIn = MAX_int16_T;
  }

  /* end of Outputs for SubSystem: '<Root>/F09_burn_mass' */

  /* SignalConversion: '<Root>/Signal Conversion' */
  (*rty_AFA_mGrdAirScvTot_pDsThr) = AFA_mGrdAirScvTot_pDsThr;

  /* SignalConversion: '<Root>/Signal Conversion1' */
  (*rty_AFA_mGrdBurnRspg_pDsThr) = AFA_mGrdBurnRspg_pDsThr;

  /* SignalConversion: '<Root>/Signal Conversion10' */
  (*rty_AFA_rMassBurn_agCkIn) = AFA_rMassBurn_agCkIn;

  /* SignalConversion: '<Root>/Signal Conversion11' */
  (*rty_AFA_rMassBurn_agCkEx) = AFA_rMassBurn_agCkEx;

  /* SignalConversion: '<Root>/Signal Conversion12' */
  (*rty_AFA_rMassBurn) = AFA_rMassBurn;

  /* SignalConversion: '<Root>/Signal Conversion2' */
  (*rty_AFA_rMassAirScv) = AFA_rMassAirScv;

  /* SignalConversion: '<Root>/Signal Conversion3' */
  (*rty_AFA_facAirScv) = AFA_facAirScv;

  /* DataTypeConversion: '<S11>/OutDTConv' incorporates:
   *  Constant: '<S11>/offset'
   *  Constant: '<S11>/offset1'
   *  Constant: '<S11>/one_on_slope'
   *  Product: '<S11>/Product4'
   *  Sum: '<S11>/Add1'
   *  Sum: '<S11>/Add2'
   */
  localSwitch1_g = (16384.0F * localLookupTablenD_mx) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    if (localSwitch1_g >= 0.0F) {
      (*rty_AFA_rMassBurnRg) = (UInt16)localSwitch1_g;
    } else {
      (*rty_AFA_rMassBurnRg) = 0U;
    }
  } else {
    (*rty_AFA_rMassBurnRg) = MAX_uint16_T;
  }

  /* Product: '<S12>/Product4' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/one_on_slope'
   *  Sum: '<S12>/Add1'
   */
  localSwitch1_g = 327680.0F * localProduct2_g;

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/offset2'
   *  Constant: '<S12>/offset3'
   *  Constant: '<S12>/offset4'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  Sum: '<S12>/Add3'
   *  Sum: '<S12>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S12>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      (*rty_AFA_rMassGrdBurnRg_agCkEx) = (SInt16)localSwitch1_g;
    } else {
      (*rty_AFA_rMassGrdBurnRg_agCkEx) = MIN_int16_T;
    }
  } else {
    (*rty_AFA_rMassGrdBurnRg_agCkEx) = MAX_int16_T;
  }

  /* Product: '<S13>/Product4' incorporates:
   *  Constant: '<S13>/offset'
   *  Constant: '<S13>/one_on_slope'
   *  Sum: '<S13>/Add1'
   */
  localSwitch1_g = 327680.0F * localProduct7_a;

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/offset2'
   *  Constant: '<S13>/offset3'
   *  Constant: '<S13>/offset4'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  Sum: '<S13>/Add3'
   *  Sum: '<S13>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S13>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      (*rty_AFA_rMassGrdBurnRg_agCkIn) = (SInt16)localSwitch1_g;
    } else {
      (*rty_AFA_rMassGrdBurnRg_agCkIn) = MIN_int16_T;
    }
  } else {
    (*rty_AFA_rMassGrdBurnRg_agCkIn) = MAX_int16_T;
  }

  /* DataTypeConversion: '<S14>/OutDTConv' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/offset1'
   *  Constant: '<S14>/one_on_slope'
   *  Product: '<S14>/Product4'
   *  Sum: '<S14>/Add1'
   *  Sum: '<S14>/Add2'
   */
  localSwitch1_g = (16384.0F * localmax) + 0.5F;
  if (localSwitch1_g < 65536.0F) {
    (*rty_AFA_rMassBurnRspg) = (UInt16)localSwitch1_g;
  } else {
    (*rty_AFA_rMassBurnRspg) = MAX_uint16_T;
  }

  /* Product: '<S15>/Product4' incorporates:
   *  Constant: '<S15>/offset'
   *  Constant: '<S15>/one_on_slope'
   *  Sum: '<S15>/Add1'
   */
  localSwitch1_g = 327680.0F * localSwitch_h;

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/offset2'
   *  Constant: '<S15>/offset3'
   *  Constant: '<S15>/offset4'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  Sum: '<S15>/Add3'
   *  Sum: '<S15>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S15>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      (*rty_AFA_rMassGrdBurnRspg_agCkEx) = (SInt16)localSwitch1_g;
    } else {
      (*rty_AFA_rMassGrdBurnRspg_agCkEx) = MIN_int16_T;
    }
  } else {
    (*rty_AFA_rMassGrdBurnRspg_agCkEx) = MAX_int16_T;
  }

  /* Product: '<S16>/Product4' incorporates:
   *  Constant: '<S16>/offset'
   *  Constant: '<S16>/one_on_slope'
   *  Sum: '<S16>/Add1'
   */
  localSwitch1_g = 327680.0F * localSwitch1_b;

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/offset2'
   *  Constant: '<S16>/offset3'
   *  Constant: '<S16>/offset4'
   *  RelationalOperator: '<S16>/Relational Operator'
   *  Sum: '<S16>/Add3'
   *  Sum: '<S16>/Add4'
   */
  if (localSwitch1_g >= 0.0F) {
    localSwitch1_g += 0.5F;
  } else {
    localSwitch1_g -= 0.5F;
  }

  /* DataTypeConversion: '<S16>/OutDTConv' */
  if (localSwitch1_g < 32768.0F) {
    if (localSwitch1_g >= -32768.0F) {
      (*rty_AFA_rMassGrdBurnRspg_agCkIn) = (SInt16)localSwitch1_g;
    } else {
      (*rty_AFA_rMassGrdBurnRspg_agCkIn) = MIN_int16_T;
    }
  } else {
    (*rty_AFA_rMassGrdBurnRspg_agCkIn) = MAX_int16_T;
  }
}

/* Model initialize function */
void mr_AFA_F07_Residual__initialize(void)
{
  /* Registration code */

  /* states (dwork) */

  /* exported global states */
  AFA_mfGrdBurnRspgRed_MP = 32768U;
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
