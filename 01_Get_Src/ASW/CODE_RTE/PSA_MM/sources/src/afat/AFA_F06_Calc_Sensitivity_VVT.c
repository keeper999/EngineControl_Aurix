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
/* !File            : AFA_F06_Calc_Sensitivity_VVT.c                          */
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
/*   Model name       : AFA_F06_Calc_Sensitivity_VVT.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F06_Calc_Sensitivity_VVT.h"
#include "AFA_F06_Calc_Sensitivity_VVT_private.h"
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


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
SInt16 AFA_rlamGrd_agCkIn;            /* '<Root>/Merge1' */
SInt16 AFA_rlamGrd_agCkEx;            /* '<Root>/Merge2' */
SInt16 AFA_pGrdDsThr_agCkIn;          /* '<Root>/Merge' */
SInt16 AFA_pGrdDsThr_agCkEx;          /* '<Root>/Merge3' */

/* Exported block states */
SInt16 AFA_facMassFlowArGrd_pDsThr;   /* '<S1>/Data Store Memory' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F06_Calc_Sensitivity_VVT' */
void mr_AFA_F06_Calc_Sensitivity_VVT(const UInt32 *rtu_AFA_facSlopEfcCor6,
  const SInt16 *rtu_AFA_facSlopGrdEfc_agCkIn, const SInt16
  *rtu_AFA_facOfsGrdEfc_agCkIn, const SInt16 *rtu_AFA_facOfsGrdEfc_agCkEx,
  const UInt16 *rtu_AFA_pDsThrCorFil, const UInt16 *rtu_AFA_rAirPresFil,
  const UInt16 *rtu_AFA_rAirLdCorFil, const UInt16 *rtu_AFA_arEffAdpThr6,
  const UInt16 *rtu_AFA_arEffAdpEGRVlv6, const UInt16 *rtu_AFA_nEngFil,
  const UInt16 *rtu_AFA_pDsThrEstimFil, SInt16 *rty_AFA_rlamGrd_agCkEx,
  SInt16 *rty_AFA_pGrdDsThr_agCkEx, SInt16 *rty_AFA_pGrdDsThr_agCkIn, SInt16 *
  rty_AFA_rlamGrd_agCkIn)
{
  Float32 localDataTypeConversion;
  Float32 localDataTypeConversion1;
  Float32 localSwitch1_h;
  Float32 localDivide_l;
  Float32 localProduct_g;
  Float32 localDataTypeConversion1_j;
  Float32 localSwitch1_n;
  Float32 localSwitch1_a;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  localDataTypeConversion = ((Float32)(*rtu_AFA_facSlopEfcCor6)) *
    2.328306437E-010F;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  localDataTypeConversion1 = ((Float32)(*rtu_AFA_rAirLdCorFil)) *
    6.103515625E-005F;

  /* Outputs for atomic SubSystem: '<Root>/F01_Calc_Sensivity_facMassFlowAr' *
   * Block requirements for '<Root>/F01_Calc_Sensivity_facMassFlowAr':
   *  1. SubSystem "F01_Calc_Sensivity_facMassFlowAr" !Trace_To : VEMS_R_11_04467_104.01 ;
   */

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S1>/AirEfc_noCylEng_C'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Eng_mRef_C'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Product: '<S1>/Product2'
   *  Product: '<S1>/Product3'
   */
  localDivide_l = 120.0F / (((((Float32)Eng_mRef_C) * 1.192016583E-007F) *
    ((Float32)AirEfc_noCylEng_C)) * ((Float32)(*rtu_AFA_nEngFil)));

  /* Outputs for atomic SubSystem: '<S6>/If Action Subsystem3' */

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant2'
   *  RelationalOperator: '<S10>/Relational Operator'
   *  Saturate: '<S10>/Saturation'
   */
  if (localDivide_l != localDivide_l) {
    localDivide_l = 0.0F;
  } else {
    localDivide_l = rt_SATURATE(localDivide_l, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S6>/If Action Subsystem3' */

  /* Product: '<S1>/Product' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   *  Lookup_n-D: '<S7>/Lookup Table (n-D)'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Add5'
   */
  localProduct_g = (((((Float32)(*rtu_AFA_arEffAdpThr6)) * 5.960464478E-008F) +
                     (((Float32)(*rtu_AFA_arEffAdpEGRVlv6)) * 5.960464478E-008F))
                    * localDivide_l) * look1_iu16lfts32n16If_binlcns
    ((*rtu_AFA_rAirPresFil), (&(Air_rAirPres_A[0])),
     (&(AFA_facMassFlowArGrdThr_T[0])), 21U);

  /* Product: '<S8>/Product4' incorporates:
   *  Constant: '<S8>/offset'
   *  Constant: '<S8>/one_on_slope'
   *  Sum: '<S8>/Add1'
   */
  localDivide_l = 327680.0F * localProduct_g;

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/offset2'
   *  Constant: '<S8>/offset3'
   *  Constant: '<S8>/offset4'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  Sum: '<S8>/Add3'
   *  Sum: '<S8>/Add4'
   */
  if (localDivide_l >= 0.0F) {
    localSwitch1_h = localDivide_l + 0.5F;
  } else {
    localSwitch1_h = localDivide_l - 0.5F;
  }

  /* DataStoreWrite: '<S1>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S8>/OutDTConv'
   */
  if (localSwitch1_h < 32768.0F) {
    if (localSwitch1_h >= -32768.0F) {
      AFA_facMassFlowArGrd_pDsThr = (SInt16)localSwitch1_h;
    } else {
      AFA_facMassFlowArGrd_pDsThr = MIN_int16_T;
    }
  } else {
    AFA_facMassFlowArGrd_pDsThr = MAX_int16_T;
  }

  /* end of Outputs for SubSystem: '<Root>/F01_Calc_Sensivity_facMassFlowAr' */

  /* Outputs for enable SubSystem: '<Root>/F02_Without_exhaust_VVT' incorporates:
   *  Constant: '<Root>/Eng_bExVlvCf_SC'
   *  EnablePort: '<S2>/Enable'
   *  Logic: '<Root>/Logical Operator1'
   *
   * Block requirements for '<Root>/F02_Without_exhaust_VVT':
   *  1. SubSystem "F02_Without_exhaust_VVT" !Trace_To : VEMS_R_11_04467_105.01 ;
   */
  if (!Eng_bExVlvCf_SC) {
    /* Constant: '<S2>/Constant2' */
    AFA_pGrdDsThr_agCkEx = 0;

    /* Constant: '<S2>/Constant1' */
    AFA_rlamGrd_agCkEx = 0;
  }

  /* end of Outputs for SubSystem: '<Root>/F02_Without_exhaust_VVT' */

  /* Outputs for enable SubSystem: '<Root>/F03_Init_sensitivity_agCkIn' incorporates:
   *  Constant: '<Root>/Eng_bInVlvCf_SC'
   *  EnablePort: '<S3>/Enable'
   *
   * Block requirements for '<Root>/F03_Init_sensitivity_agCkIn':
   *  1. SubSystem "F03_Init_sensitivity_agCkIn" !Trace_To : VEMS_R_11_04467_106.01 ;
   */
  if (Eng_bInVlvCf_SC) {
    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    localDataTypeConversion1_j = ((Float32)(*rtu_AFA_facSlopGrdEfc_agCkIn)) *
      3.051757805E-011F;

    /* DataTypeConversion: '<S3>/Data Type Conversion2' */
    localSwitch1_n = ((Float32)(*rtu_AFA_facOfsGrdEfc_agCkIn)) *
      3.051757858E-006F;

    /* Product: '<S11>/Divide' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion3'
     *  Product: '<S3>/Product'
     *  Sum: '<S3>/Add'
     */
    localDivide_l = (((((Float32)(*rtu_AFA_pDsThrCorFil)) * 8.0F) *
                      localDataTypeConversion1_j) - localSwitch1_n) /
      localDataTypeConversion1;

    /* Outputs for atomic SubSystem: '<S11>/If Action Subsystem3' */

    /* Switch: '<S16>/Switch1' incorporates:
     *  Constant: '<S16>/Constant2'
     *  RelationalOperator: '<S16>/Relational Operator'
     *  Saturate: '<S16>/Saturation'
     */
    if (localDivide_l != localDivide_l) {
      localSwitch1_a = 0.0F;
    } else {
      localSwitch1_a = rt_SATURATE(localDivide_l, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S11>/If Action Subsystem3' */

    /* Product: '<S12>/Divide' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion4'
     *  Product: '<S3>/Product1'
     *  Sum: '<S3>/Add1'
     *  Sum: '<S3>/Add3'
     */
    localDivide_l = (localSwitch1_n - ((((Float32)(*rtu_AFA_pDsThrEstimFil)) *
      8.0F) * localDataTypeConversion1_j)) / (localDataTypeConversion -
      localProduct_g);

    /* Outputs for atomic SubSystem: '<S12>/If Action Subsystem3' */

    /* Switch: '<S18>/Switch1' incorporates:
     *  Constant: '<S18>/Constant2'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  Saturate: '<S18>/Saturation'
     */
    if (localDivide_l != localDivide_l) {
      localSwitch1_h = 0.0F;
    } else {
      localSwitch1_h = rt_SATURATE(localDivide_l, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S12>/If Action Subsystem3' */

    /* Product: '<S13>/Product4' incorporates:
     *  Constant: '<S13>/offset'
     *  Constant: '<S13>/one_on_slope'
     *  Constant: '<S3>/Constant1'
     *  Product: '<S3>/Product3'
     *  Sum: '<S13>/Add1'
     */
    localDivide_l = (-localSwitch1_a) * 327680.0F;

    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/offset2'
     *  Constant: '<S13>/offset3'
     *  Constant: '<S13>/offset4'
     *  RelationalOperator: '<S13>/Relational Operator'
     *  Sum: '<S13>/Add3'
     *  Sum: '<S13>/Add4'
     */
    if (localDivide_l >= 0.0F) {
      localSwitch1_n = localDivide_l + 0.5F;
    } else {
      localSwitch1_n = localDivide_l - 0.5F;
    }

    /* DataTypeConversion: '<S13>/OutDTConv' */
    if (localSwitch1_n < 32768.0F) {
      if (localSwitch1_n >= -32768.0F) {
        AFA_rlamGrd_agCkIn = (SInt16)localSwitch1_n;
      } else {
        AFA_rlamGrd_agCkIn = MIN_int16_T;
      }
    } else {
      AFA_rlamGrd_agCkIn = MAX_int16_T;
    }

    /* Product: '<S14>/Product4' incorporates:
     *  Constant: '<S14>/offset'
     *  Constant: '<S14>/one_on_slope'
     *  Constant: '<S3>/Constant16'
     *  Product: '<S3>/Product2'
     *  Sum: '<S14>/Add1'
     */
    localDivide_l = (-localSwitch1_h) * 16.0F;

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S14>/offset2'
     *  Constant: '<S14>/offset3'
     *  Constant: '<S14>/offset4'
     *  RelationalOperator: '<S14>/Relational Operator'
     *  Sum: '<S14>/Add3'
     *  Sum: '<S14>/Add4'
     */
    if (localDivide_l >= 0.0F) {
      localSwitch1_n = localDivide_l + 0.5F;
    } else {
      localSwitch1_n = localDivide_l - 0.5F;
    }

    /* DataTypeConversion: '<S14>/OutDTConv' */
    if (localSwitch1_n < 32768.0F) {
      if (localSwitch1_n >= -32768.0F) {
        AFA_pGrdDsThr_agCkIn = (SInt16)localSwitch1_n;
      } else {
        AFA_pGrdDsThr_agCkIn = MIN_int16_T;
      }
    } else {
      AFA_pGrdDsThr_agCkIn = MAX_int16_T;
    }
  }

  /* end of Outputs for SubSystem: '<Root>/F03_Init_sensitivity_agCkIn' */

  /* Outputs for enable SubSystem: '<Root>/F04_Without_Intake_VVT' incorporates:
   *  Constant: '<Root>/Eng_bInVlvCf_SC'
   *  EnablePort: '<S4>/Enable'
   *  Logic: '<Root>/Logical Operator'
   *
   * Block requirements for '<Root>/F04_Without_Intake_VVT':
   *  1. SubSystem "F04_Without_Intake_VVT" !Trace_To : VEMS_R_11_04467_107.01 ;
   */
  if (!Eng_bInVlvCf_SC) {
    /* Constant: '<S4>/Constant2' */
    AFA_rlamGrd_agCkIn = 0;

    /* Constant: '<S4>/Constant1' */
    AFA_pGrdDsThr_agCkIn = 0;
  }

  /* end of Outputs for SubSystem: '<Root>/F04_Without_Intake_VVT' */

  /* Outputs for enable SubSystem: '<Root>/F05_Init_sensitivity_agCkEx' incorporates:
   *  Constant: '<Root>/Eng_bExVlvCf_SC'
   *  EnablePort: '<S5>/Enable'
   *
   * Block requirements for '<Root>/F05_Init_sensitivity_agCkEx':
   *  1. SubSystem "F05_Init_sensitivity_agCkEx" !Trace_To : VEMS_R_11_04467_108.01 ;
   */
  if (Eng_bExVlvCf_SC) {
    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    localSwitch1_n = ((Float32)(*rtu_AFA_facOfsGrdEfc_agCkEx)) *
      3.051757858E-006F;

    /* Product: '<S19>/Divide' incorporates:
     *  Sum: '<S5>/Add2'
     */
    localDivide_l = localSwitch1_n / (localDataTypeConversion - localProduct_g);

    /* Outputs for atomic SubSystem: '<S19>/If Action Subsystem3' */

    /* Switch: '<S24>/Switch1' incorporates:
     *  Constant: '<S24>/Constant2'
     *  RelationalOperator: '<S24>/Relational Operator'
     *  Saturate: '<S24>/Saturation'
     */
    if (localDivide_l != localDivide_l) {
      localDataTypeConversion1_j = 0.0F;
    } else {
      localDataTypeConversion1_j = rt_SATURATE(localDivide_l, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S19>/If Action Subsystem3' */

    /* Product: '<S20>/Divide' incorporates:
     *  Constant: '<S5>/Constant2'
     *  Product: '<S5>/Product2'
     */
    localDivide_l = (-localSwitch1_n) / localDataTypeConversion1;

    /* Outputs for atomic SubSystem: '<S20>/If Action Subsystem3' */

    /* Switch: '<S26>/Switch1' incorporates:
     *  Constant: '<S26>/Constant2'
     *  RelationalOperator: '<S26>/Relational Operator'
     *  Saturate: '<S26>/Saturation'
     */
    if (localDivide_l != localDivide_l) {
      localSwitch1_h = 0.0F;
    } else {
      localSwitch1_h = rt_SATURATE(localDivide_l, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S20>/If Action Subsystem3' */

    /* Product: '<S21>/Product4' incorporates:
     *  Constant: '<S21>/offset'
     *  Constant: '<S21>/one_on_slope'
     *  Constant: '<S5>/Constant16'
     *  Product: '<S5>/Product'
     *  Sum: '<S21>/Add1'
     */
    localDivide_l = (-localDataTypeConversion1_j) * 16.0F;

    /* Switch: '<S21>/Switch1' incorporates:
     *  Constant: '<S21>/offset2'
     *  Constant: '<S21>/offset3'
     *  Constant: '<S21>/offset4'
     *  RelationalOperator: '<S21>/Relational Operator'
     *  Sum: '<S21>/Add3'
     *  Sum: '<S21>/Add4'
     */
    if (localDivide_l >= 0.0F) {
      localSwitch1_n = localDivide_l + 0.5F;
    } else {
      localSwitch1_n = localDivide_l - 0.5F;
    }

    /* DataTypeConversion: '<S21>/OutDTConv' */
    if (localSwitch1_n < 32768.0F) {
      if (localSwitch1_n >= -32768.0F) {
        AFA_pGrdDsThr_agCkEx = (SInt16)localSwitch1_n;
      } else {
        AFA_pGrdDsThr_agCkEx = MIN_int16_T;
      }
    } else {
      AFA_pGrdDsThr_agCkEx = MAX_int16_T;
    }

    /* Product: '<S22>/Product4' incorporates:
     *  Constant: '<S22>/offset'
     *  Constant: '<S22>/one_on_slope'
     *  Constant: '<S5>/Constant1'
     *  Product: '<S5>/Product1'
     *  Sum: '<S22>/Add1'
     */
    localDivide_l = (-localSwitch1_h) * 327680.0F;

    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/offset2'
     *  Constant: '<S22>/offset3'
     *  Constant: '<S22>/offset4'
     *  RelationalOperator: '<S22>/Relational Operator'
     *  Sum: '<S22>/Add3'
     *  Sum: '<S22>/Add4'
     */
    if (localDivide_l >= 0.0F) {
      localSwitch1_n = localDivide_l + 0.5F;
    } else {
      localSwitch1_n = localDivide_l - 0.5F;
    }

    /* DataTypeConversion: '<S22>/OutDTConv' */
    if (localSwitch1_n < 32768.0F) {
      if (localSwitch1_n >= -32768.0F) {
        AFA_rlamGrd_agCkEx = (SInt16)localSwitch1_n;
      } else {
        AFA_rlamGrd_agCkEx = MIN_int16_T;
      }
    } else {
      AFA_rlamGrd_agCkEx = MAX_int16_T;
    }
  }

  /* end of Outputs for SubSystem: '<Root>/F05_Init_sensitivity_agCkEx' */

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_pGrdDsThr_agCkIn) = AFA_pGrdDsThr_agCkIn;

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_rlamGrd_agCkIn) = AFA_rlamGrd_agCkIn;

  /* SignalConversion: '<Root>/Signal3' */
  (*rty_AFA_rlamGrd_agCkEx) = AFA_rlamGrd_agCkEx;

  /* SignalConversion: '<Root>/Signal4' */
  (*rty_AFA_pGrdDsThr_agCkEx) = AFA_pGrdDsThr_agCkEx;
}

/* Model initialize function */
void mr_AFA_F06_Calc_Sens_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
