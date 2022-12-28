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
/* !File            : AFA_F05_Calc_Sensitivity_EGR.c                          */
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
/*   Model name       : AFA_F05_Calc_Sensitivity_EGR.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F05_Calc_Sensitivity_EGR.h"
#include "AFA_F05_Calc_Sensitivity_EGR_private.h"
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
UInt16 AFA_rlamGrd_arEffEGRVlv;      /* '<Root>/Merge' */
UInt16 AFA_pGrdDsThr_arEffEGRVlv;    /* '<Root>/Merge1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F05_Calc_Sensitivity_EGR' */
void mr_AFA_F05_Calc_Sensitivity_EGR(const UInt32 *rtu_AFA_rTotLdGrd_pDs_,
  const UInt16 *rtu_AFA_arEffAdpThrFi5, const UInt16 *rtu_AFA_rInMassFlowFi5,
  const UInt16 *rtu_AFA_arEffAdpEGRVlvFil, const UInt16
  *rtu_AFA_mfArThr_rAirPre5, const UInt16 *rtu_AFA_pDsThrFi5, const UInt16
  *rtu_AFA_arEffEGRVlvFil, UInt16 *rty_AFA_rlamGrd_arEffEGRVlv, UInt16
  *rty_AFA_pGrdDsThr_arEffEGRVlv)
{
  Float32 localDataTypeConversion1;
  Float32 localDataTypeConversion2;
  Float32 localDataTypeConversion4;
  Float32 localDataTypeConversion5;
  Float32 localDataTypeConversion7;
  Boolean localRelationalOperator_b;
  Float32 localProduct;
  Float32 localSubtract4;
  Float32 localDivide_n;
  Float32 localDivide_f;

  /* Outputs for enable SubSystem: '<Root>/F01_Without_EGR' incorporates:
   *  Constant: '<Root>/Eng_bEGRVlvCf_SC'
   *  EnablePort: '<S1>/Enable'
   *  EnablePort: '<S2>/Enable'
   *  Logic: '<Root>/Logical Operator1'
   *  SubSystem: '<Root>/F02_Calc_sensitivity_EGR'
   *
   * Block requirements for '<Root>/F01_Without_EGR':
   *  1. SubSystem "F01_Without_EGR" !Trace_To : VEMS_R_11_04467_101.01 ;
   *
   * Block requirements for '<Root>/F02_Calc_sensitivity_EGR':
   *  1. SubSystem "F02_Calc_sensitivity_EGR" !Trace_To : VEMS_R_11_04467_102.01 ;
   */
  if (!Eng_bEGRVlvCf_SC) {
    /* Constant: '<S1>/Constant2' */
    AFA_pGrdDsThr_arEffEGRVlv = 0U;

    /* Constant: '<S1>/Constant1' */
    AFA_rlamGrd_arEffEGRVlv = 0U;
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    localDataTypeConversion1 = ((Float32)(*rtu_AFA_pDsThrFi5)) * 8.0F;

    /* DataTypeConversion: '<S2>/Data Type Conversion2' */
    localDataTypeConversion2 = ((Float32)(*rtu_AFA_rInMassFlowFi5)) *
      1.525878906E-005F;

    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    localDataTypeConversion4 = ((Float32)(*rtu_AFA_arEffAdpEGRVlvFil)) *
      5.960464478E-008F;

    /* DataTypeConversion: '<S2>/Data Type Conversion5' */
    localDataTypeConversion5 = ((Float32)(*rtu_AFA_arEffAdpThrFi5)) *
      5.960464478E-008F;

    /* DataTypeConversion: '<S2>/Data Type Conversion7' */
    localDataTypeConversion7 = ((Float32)(*rtu_AFA_arEffEGRVlvFil)) *
      5.960464478E-008F;

    /* Sum: '<S2>/Subtract4' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion3'
     *  DataTypeConversion: '<S2>/Data Type Conversion6'
     */
    localSubtract4 = (((Float32)(*rtu_AFA_rTotLdGrd_pDs_)) * 2.328306437E-004F)
      - ((((Float32)(*rtu_AFA_mfArThr_rAirPre5)) * 0.0078125F) - 511.9921875F);

    /* RelationalOperator: '<S2>/Relational Operator' incorporates:
     *  Constant: '<S2>/Constant3'
     */
    localRelationalOperator_b = ((*rtu_AFA_arEffAdpEGRVlvFil) != 0);

    /* Switch: '<S2>/Switch1' */
    if (localRelationalOperator_b) {
      /* Product: '<S6>/Divide' incorporates:
       *  Constant: '<S2>/Constant1'
       *  Constant: '<S2>/Constant16'
       *  Product: '<S2>/Divide'
       *  Product: '<S2>/Product2'
       *  Sum: '<S2>/Subtract10'
       */
      localDivide_n = ((-localDataTypeConversion2) / (localDataTypeConversion2 +
        1.0F)) / localDataTypeConversion4;

      /* Outputs for atomic SubSystem: '<S6>/If Action Subsystem3' */

      /* Switch: '<S18>/Switch1' incorporates:
       *  Constant: '<S18>/Constant2'
       *  RelationalOperator: '<S18>/Relational Operator'
       *  Saturate: '<S18>/Saturation'
       */
      if (localDivide_n != localDivide_n) {
        localDivide_f = 0.0F;
      } else {
        localDivide_f = rt_SATURATE(localDivide_n, -3.000000005E+038F,
          3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S6>/If Action Subsystem3' */
    } else {
      /* Product: '<S7>/Divide' incorporates:
       *  Constant: '<S2>/Constant2'
       */
      localDivide_f = -1.0F / localDataTypeConversion5;

      /* Outputs for atomic SubSystem: '<S7>/If Action Subsystem3' */

      /* Switch: '<S20>/Switch1' incorporates:
       *  Constant: '<S20>/Constant2'
       *  RelationalOperator: '<S20>/Relational Operator'
       *  Saturate: '<S20>/Saturation'
       */
      if (localDivide_f != localDivide_f) {
        localDivide_f = 0.0F;
      } else {
        localDivide_f = rt_SATURATE(localDivide_f, -3.000000005E+038F,
          3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S7>/If Action Subsystem3' */
    }

    /* Product: '<S2>/Product' */
    localProduct = localDivide_f * localDataTypeConversion7;

    /* Switch: '<S2>/Switch2' incorporates:
     *  Product: '<S2>/Product3'
     */
    if (localRelationalOperator_b) {
      /* Product: '<S4>/Divide' */
      localDataTypeConversion1 /= localDataTypeConversion4;

      /* Product: '<S8>/Divide' incorporates:
       *  Constant: '<S2>/Constant4'
       *  Product: '<S2>/Divide1'
       *  Sum: '<S2>/Subtract5'
       */
      localDivide_f = (localDataTypeConversion2 / (localDataTypeConversion2 +
        1.0F)) / localSubtract4;

      /* Outputs for atomic SubSystem: '<S8>/If Action Subsystem3' */

      /* Switch: '<S22>/Switch1' incorporates:
       *  Constant: '<S22>/Constant2'
       *  RelationalOperator: '<S22>/Relational Operator'
       *  Saturate: '<S22>/Saturation'
       */
      if (localDivide_f != localDivide_f) {
        localDivide_n = 0.0F;
      } else {
        localDivide_n = rt_SATURATE(localDivide_f, -3.000000005E+038F,
          3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S8>/If Action Subsystem3' */

      /* Outputs for atomic SubSystem: '<S4>/If Action Subsystem3' */

      /* Switch: '<S14>/Switch1' incorporates:
       *  Constant: '<S14>/Constant2'
       *  RelationalOperator: '<S14>/Relational Operator'
       *  Saturate: '<S14>/Saturation'
       */
      if (localDataTypeConversion1 != localDataTypeConversion1) {
        localDivide_f = 0.0F;
      } else {
        localDivide_f = rt_SATURATE(localDataTypeConversion1, -3.000000005E+038F,
          3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S4>/If Action Subsystem3' */
      localDivide_f *= localDivide_n;
    } else {
      /* Product: '<S3>/Divide' */
      localDivide_f = localDataTypeConversion1 / localDataTypeConversion5;

      /* Outputs for atomic SubSystem: '<S3>/If Action Subsystem3' */

      /* Switch: '<S12>/Switch1' incorporates:
       *  Constant: '<S12>/Constant2'
       *  RelationalOperator: '<S12>/Relational Operator'
       *  Saturate: '<S12>/Saturation'
       */
      if (localDivide_f != localDivide_f) {
        localDivide_f = 0.0F;
      } else {
        localDivide_f = rt_SATURATE(localDivide_f, -3.000000005E+038F,
          3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S3>/If Action Subsystem3' */

      /* Product: '<S5>/Divide' */
      localDivide_f /= localSubtract4;

      /* Outputs for atomic SubSystem: '<S5>/If Action Subsystem3' */

      /* Switch: '<S16>/Switch1' incorporates:
       *  Constant: '<S16>/Constant2'
       *  RelationalOperator: '<S16>/Relational Operator'
       *  Saturate: '<S16>/Saturation'
       */
      if (localDivide_f != localDivide_f) {
        localDivide_f = 0.0F;
      } else {
        localDivide_f = rt_SATURATE(localDivide_f, -3.000000005E+038F,
          3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
    }

    /* DataTypeConversion: '<S9>/OutDTConv' incorporates:
     *  Constant: '<S9>/offset'
     *  Constant: '<S9>/offset1'
     *  Constant: '<S9>/one_on_slope'
     *  Product: '<S9>/Product4'
     *  Sum: '<S9>/Add1'
     *  Sum: '<S9>/Add2'
     */
    localDataTypeConversion1 = (6.553599834E-001F * localProduct) + 0.5F;
    if (localDataTypeConversion1 < 65536.0F) {
      if (localDataTypeConversion1 >= 0.0F) {
        AFA_rlamGrd_arEffEGRVlv = (UInt16)localDataTypeConversion1;
      } else {
        AFA_rlamGrd_arEffEGRVlv = 0U;
      }
    } else {
      AFA_rlamGrd_arEffEGRVlv = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S10>/OutDTConv' incorporates:
     *  Constant: '<S10>/offset'
     *  Constant: '<S10>/offset1'
     *  Constant: '<S10>/one_on_slope'
     *  Product: '<S10>/Product4'
     *  Product: '<S2>/Product1'
     *  Sum: '<S10>/Add1'
     *  Sum: '<S10>/Add2'
     */
    localDataTypeConversion1 = ((localDataTypeConversion7 * localDivide_f) *
      6.553600087E-006F) + 0.5F;
    if (localDataTypeConversion1 < 65536.0F) {
      if (localDataTypeConversion1 >= 0.0F) {
        AFA_pGrdDsThr_arEffEGRVlv = (UInt16)localDataTypeConversion1;
      } else {
        AFA_pGrdDsThr_arEffEGRVlv = 0U;
      }
    } else {
      AFA_pGrdDsThr_arEffEGRVlv = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<Root>/F01_Without_EGR' */

  /* SignalConversion: '<Root>/Signal Conversion' */
  (*rty_AFA_rlamGrd_arEffEGRVlv) = AFA_rlamGrd_arEffEGRVlv;

  /* SignalConversion: '<Root>/Signal Conversion1' */
  (*rty_AFA_pGrdDsThr_arEffEGRVlv) = AFA_pGrdDsThr_arEffEGRVlv;
}

/* Model initialize function */
void mr_AFA_F05_Calc_Sens_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
