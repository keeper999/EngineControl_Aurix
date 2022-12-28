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
/* !File            : AFA_F05_calc_pred_innov_covar_mat.c                     */
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
/*   Model name       : AFA_F05_calc_pred_innov_covar_mat.mdl                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F05_calc_pred_innov_covar_mat.h"
#include "AFA_F05_calc_pred_innov_covar_mat_private.h"
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


/* Exported block states */
SInt16 AFA_prm_covPredInnovMat[4];    /* '<S2>/Data Store Memory' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Start for referenced model: 'AFA_F05_calc_pred_innov_covar_mat' */
void mr_AFA_F05_calc_pred_inno_Start(void)
{
  /* Start for atomic SubSystem: '<Root>/F01_pred_innov_covariance' *
   * Block requirements for '<Root>/F01_pred_innov_covariance':
   *  1. SubSystem "F01_pred_innov_covariance" !Trace_To : VEMS_R_11_04467_123.01 ;
   */

  /* Start for DataStoreMemory: '<S2>/Data Store Memory' */
  AFA_prm_covPredInnovMat[0] = MIN_int16_T;
  AFA_prm_covPredInnovMat[1] = MIN_int16_T;
  AFA_prm_covPredInnovMat[2] = MIN_int16_T;
  AFA_prm_covPredInnovMat[3] = MIN_int16_T;

  /* end of Start for SubSystem: '<Root>/F01_pred_innov_covariance' */
}

/* Output and update for referenced model: 'AFA_F05_calc_pred_innov_covar_mat' */
void mr_AFA_F05_calc_pred_innov_cova(const SInt32 rtu_AFA_prm_facSen[16], const
  SInt32 rtu_AFA_prm_facSenT[16], const UInt16 rtu_AFA_prm_covPredE[64],
  UInt16 rty_AFA_prm_covIvsPredInnovMat_[4], Boolean
  *rty_AFA_bIdcInv_covPredIn9, SInt16 rty_AFA_prm_facInterMat_PIM[16], UInt8
  rty_AFA_prm_covNoiseMesMat_PIM[4])
{
  Float32 localSelector;
  Float32 localSelector1;
  Float32 localSelector2;
  Float32 localSelector3;
  Float32 localSum;
  Boolean localCompare;
  Float32 localSubtract5[4];
  Float32 localSwitch1_b[16];
  UInt16 localMatrixConcatenation2[4];
  SInt32 localtmp;
  SInt32 localtmp_0;
  SInt32 localtmp_1;
  Float32 locallocalSwitch1_h;
  SInt16 localtmp_2;
  UInt16 localtmp_3;
  UInt8 localtmp_4;

  /* Outputs for atomic SubSystem: '<Root>/F01_pred_innov_covariance' *
   * Block requirements for '<Root>/F01_pred_innov_covariance':
   *  1. SubSystem "F01_pred_innov_covariance" !Trace_To : VEMS_R_11_04467_123.01 ;
   */

  /* Product: '<S2>/Product2' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   *  DataTypeConversion: '<S2>/Data Type Conversion4'
   */
  for (localtmp = 0; localtmp < 2; localtmp++) {
    for (localtmp_0 = 0; localtmp_0 < 8; localtmp_0++) {
      localSwitch1_b[localtmp + (localtmp_0 << 1)] = 0.0F;
      for (localtmp_1 = 0; localtmp_1 < 8; localtmp_1++) {
        localSwitch1_b[localtmp + (localtmp_0 << 1)] = ((((Float32)
          rtu_AFA_prm_facSen[(localtmp_1 << 1) + localtmp]) * 0.0009765625F) *
          (((Float32)rtu_AFA_prm_covPredE[(localtmp_0 << 3) + localtmp_1]) *
           3.051757813E-005F)) + localSwitch1_b[(localtmp_0 << 1) + localtmp];
      }
    }
  }

  /* Concatenate: '<S2>/Matrix Concatenation2' incorporates:
   *  Constant: '<S2>/AFA_covNoiseValLamFb_C'
   *  Constant: '<S2>/AFA_covNoiseValPresDsThr_C'
   *  Constant: '<S2>/Constant5'
   *  Constant: '<S2>/Constant6'
   *  Sum: '<S2>/Subtract3'
   *  Sum: '<S2>/Subtract4'
   */
  localMatrixConcatenation2[0] = (UInt16)(4 + AFA_covNoiseValPresDsThr_C);
  localMatrixConcatenation2[2] = 0U;
  localMatrixConcatenation2[1] = 0U;
  localMatrixConcatenation2[3] = (UInt16)(AFA_covNoiseValLamFb_C + 4);

  /* Sum: '<S2>/Subtract5' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   *  Product: '<S2>/Product'
   */
  for (localtmp = 0; localtmp < 2; localtmp++) {
    for (localtmp_0 = 0; localtmp_0 < 2; localtmp_0++) {
      locallocalSwitch1_h = 0.0F;
      for (localtmp_1 = 0; localtmp_1 < 8; localtmp_1++) {
        locallocalSwitch1_h += (((Float32)rtu_AFA_prm_facSenT[(localtmp_0 << 3)
          + localtmp_1]) * 0.0009765625F) * localSwitch1_b[(localtmp_1 << 1) +
          localtmp];
      }

      localSubtract5[localtmp + (localtmp_0 << 1)] = (((Float32)
        localMatrixConcatenation2[(localtmp_0 << 1) + localtmp]) * 0.25F) +
        locallocalSwitch1_h;
    }
  }

  /* Product: '<S6>/Product4' incorporates:
   *  Constant: '<S6>/offset'
   *  Constant: '<S6>/one_on_slope'
   *  Sum: '<S6>/Add1'
   */
  locallocalSwitch1_h = 32.0F * localSubtract5[0];

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/offset2'
   *  Constant: '<S6>/offset3'
   *  Constant: '<S6>/offset4'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  Sum: '<S6>/Add3'
   *  Sum: '<S6>/Add4'
   */
  if (locallocalSwitch1_h >= 0.0F) {
    locallocalSwitch1_h += 0.5F;
  } else {
    locallocalSwitch1_h -= 0.5F;
  }

  /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S6>/OutDTConv'
   */
  if (locallocalSwitch1_h < 32768.0F) {
    if (locallocalSwitch1_h >= -32768.0F) {
      localtmp_2 = (SInt16)locallocalSwitch1_h;
    } else {
      localtmp_2 = MIN_int16_T;
    }
  } else {
    localtmp_2 = MAX_int16_T;
  }

  AFA_prm_covPredInnovMat[0] = localtmp_2;

  /* Product: '<S6>/Product4' incorporates:
   *  Constant: '<S6>/offset'
   *  Constant: '<S6>/one_on_slope'
   *  Sum: '<S6>/Add1'
   */
  locallocalSwitch1_h = 32.0F * localSubtract5[1];

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/offset2'
   *  Constant: '<S6>/offset3'
   *  Constant: '<S6>/offset4'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  Sum: '<S6>/Add3'
   *  Sum: '<S6>/Add4'
   */
  if (locallocalSwitch1_h >= 0.0F) {
    locallocalSwitch1_h += 0.5F;
  } else {
    locallocalSwitch1_h -= 0.5F;
  }

  /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S6>/OutDTConv'
   */
  if (locallocalSwitch1_h < 32768.0F) {
    if (locallocalSwitch1_h >= -32768.0F) {
      localtmp_2 = (SInt16)locallocalSwitch1_h;
    } else {
      localtmp_2 = MIN_int16_T;
    }
  } else {
    localtmp_2 = MAX_int16_T;
  }

  AFA_prm_covPredInnovMat[1] = localtmp_2;

  /* Product: '<S6>/Product4' incorporates:
   *  Constant: '<S6>/offset'
   *  Constant: '<S6>/one_on_slope'
   *  Sum: '<S6>/Add1'
   */
  locallocalSwitch1_h = 32.0F * localSubtract5[2];

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/offset2'
   *  Constant: '<S6>/offset3'
   *  Constant: '<S6>/offset4'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  Sum: '<S6>/Add3'
   *  Sum: '<S6>/Add4'
   */
  if (locallocalSwitch1_h >= 0.0F) {
    locallocalSwitch1_h += 0.5F;
  } else {
    locallocalSwitch1_h -= 0.5F;
  }

  /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S6>/OutDTConv'
   */
  if (locallocalSwitch1_h < 32768.0F) {
    if (locallocalSwitch1_h >= -32768.0F) {
      localtmp_2 = (SInt16)locallocalSwitch1_h;
    } else {
      localtmp_2 = MIN_int16_T;
    }
  } else {
    localtmp_2 = MAX_int16_T;
  }

  AFA_prm_covPredInnovMat[2] = localtmp_2;

  /* Product: '<S6>/Product4' incorporates:
   *  Constant: '<S6>/offset'
   *  Constant: '<S6>/one_on_slope'
   *  Sum: '<S6>/Add1'
   */
  locallocalSwitch1_h = 32.0F * localSubtract5[3];

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/offset2'
   *  Constant: '<S6>/offset3'
   *  Constant: '<S6>/offset4'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  Sum: '<S6>/Add3'
   *  Sum: '<S6>/Add4'
   */
  if (locallocalSwitch1_h >= 0.0F) {
    locallocalSwitch1_h += 0.5F;
  } else {
    locallocalSwitch1_h -= 0.5F;
  }

  /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S6>/OutDTConv'
   */
  if (locallocalSwitch1_h < 32768.0F) {
    if (locallocalSwitch1_h >= -32768.0F) {
      localtmp_2 = (SInt16)locallocalSwitch1_h;
    } else {
      localtmp_2 = MIN_int16_T;
    }
  } else {
    localtmp_2 = MAX_int16_T;
  }

  AFA_prm_covPredInnovMat[3] = localtmp_2;

  /* end of Outputs for SubSystem: '<Root>/F01_pred_innov_covariance' */

  /* Selector: '<S3>/Selector' */
  localSelector = localSubtract5[0];

  /* Selector: '<S3>/Selector1' */
  localSelector1 = localSubtract5[3];

  /* Selector: '<S3>/Selector2' */
  localSelector2 = localSubtract5[1];

  /* Selector: '<S3>/Selector3' */
  localSelector3 = localSubtract5[2];

  /* Sum: '<S3>/Sum' incorporates:
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   */
  localSum = (localSubtract5[0] * localSubtract5[3]) - (localSubtract5[1] *
    localSubtract5[2]);

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  localCompare = (localSum <= 0.0F);

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_bIdcInv_covPredIn9) = localCompare;
  for (localtmp = 0; localtmp < 16; localtmp++) {
    /* Product: '<S5>/Product4' incorporates:
     *  Constant: '<S5>/offset'
     *  Constant: '<S5>/one_on_slope'
     *  Sum: '<S5>/Add1'
     */
    locallocalSwitch1_h = 512.0F * localSwitch1_b[localtmp];

    /* Switch: '<S5>/Switch1' incorporates:
     *  Constant: '<S5>/offset2'
     *  Constant: '<S5>/offset3'
     *  Constant: '<S5>/offset4'
     *  RelationalOperator: '<S5>/Relational Operator'
     *  Sum: '<S5>/Add3'
     *  Sum: '<S5>/Add4'
     */
    if (locallocalSwitch1_h >= 0.0F) {
      locallocalSwitch1_h += 0.5F;
    } else {
      locallocalSwitch1_h -= 0.5F;
    }

    /* SignalConversion: '<Root>/Signal3' incorporates:
     *  DataTypeConversion: '<S5>/OutDTConv'
     */
    if (locallocalSwitch1_h < 32768.0F) {
      if (locallocalSwitch1_h >= -32768.0F) {
        localtmp_2 = (SInt16)locallocalSwitch1_h;
      } else {
        localtmp_2 = MIN_int16_T;
      }
    } else {
      localtmp_2 = MAX_int16_T;
    }

    rty_AFA_prm_facInterMat_PIM[(localtmp)] = localtmp_2;
  }

  /* SignalConversion: '<Root>/Signal4' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  if (localMatrixConcatenation2[0] > 255) {
    localtmp_4 = MAX_uint8_T;
  } else {
    localtmp_4 = (UInt8)localMatrixConcatenation2[0];
  }

  rty_AFA_prm_covNoiseMesMat_PIM[0] = localtmp_4;
  rty_AFA_prm_covNoiseMesMat_PIM[1] = 0U;
  rty_AFA_prm_covNoiseMesMat_PIM[2] = 0U;
  if (localMatrixConcatenation2[3] > 255) {
    localtmp_4 = MAX_uint8_T;
  } else {
    localtmp_4 = (UInt8)localMatrixConcatenation2[3];
  }

  rty_AFA_prm_covNoiseMesMat_PIM[3] = localtmp_4;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S4>/offset'
   *  Constant: '<S4>/offset1'
   *  Constant: '<S4>/one_on_slope'
   *  DataTypeConversion: '<S4>/OutDTConv'
   *  Product: '<S4>/Product4'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add2'
   */
  if (localCompare) {
    rty_AFA_prm_covIvsPredInnovMat_[0] = 0U;
    rty_AFA_prm_covIvsPredInnovMat_[1] = 0U;
    rty_AFA_prm_covIvsPredInnovMat_[2] = 0U;
    rty_AFA_prm_covIvsPredInnovMat_[3] = 0U;
  } else {
    /* Product: '<S3>/Product2' incorporates:
     *  Constant: '<S3>/Constant'
     */
    locallocalSwitch1_h = -localSum;

    /* SignalConversion: '<S3>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
     *  Product: '<S3>/Product5'
     *  Product: '<S3>/Product7'
     */
    localSubtract5[2] = localSelector3 / locallocalSwitch1_h;
    localSubtract5[3] = localSelector / localSum;

    /* Product: '<S3>/Product6' */
    locallocalSwitch1_h = localSelector2 / locallocalSwitch1_h;

    /* SignalConversion: '<S3>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
     *  Product: '<S3>/Product4'
     */
    localSubtract5[0] = localSelector1 / localSum;
    localSubtract5[1] = locallocalSwitch1_h;
    locallocalSwitch1_h = (32768.0F * localSubtract5[0]) + 0.5F;
    if (locallocalSwitch1_h < 65536.0F) {
      if (locallocalSwitch1_h >= 0.0F) {
        localtmp_3 = (UInt16)locallocalSwitch1_h;
      } else {
        localtmp_3 = 0U;
      }
    } else {
      localtmp_3 = MAX_uint16_T;
    }

    rty_AFA_prm_covIvsPredInnovMat_[0] = localtmp_3;
    locallocalSwitch1_h = (32768.0F * localSubtract5[1]) + 0.5F;
    if (locallocalSwitch1_h < 65536.0F) {
      if (locallocalSwitch1_h >= 0.0F) {
        localtmp_3 = (UInt16)locallocalSwitch1_h;
      } else {
        localtmp_3 = 0U;
      }
    } else {
      localtmp_3 = MAX_uint16_T;
    }

    rty_AFA_prm_covIvsPredInnovMat_[1] = localtmp_3;
    locallocalSwitch1_h = (32768.0F * localSubtract5[2]) + 0.5F;
    if (locallocalSwitch1_h < 65536.0F) {
      if (locallocalSwitch1_h >= 0.0F) {
        localtmp_3 = (UInt16)locallocalSwitch1_h;
      } else {
        localtmp_3 = 0U;
      }
    } else {
      localtmp_3 = MAX_uint16_T;
    }

    rty_AFA_prm_covIvsPredInnovMat_[2] = localtmp_3;
    locallocalSwitch1_h = (32768.0F * localSubtract5[3]) + 0.5F;
    if (locallocalSwitch1_h < 65536.0F) {
      if (locallocalSwitch1_h >= 0.0F) {
        localtmp_3 = (UInt16)locallocalSwitch1_h;
      } else {
        localtmp_3 = 0U;
      }
    } else {
      localtmp_3 = MAX_uint16_T;
    }

    rty_AFA_prm_covIvsPredInnovMat_[3] = localtmp_3;
  }
}

/* Model initialize function */
void mr_AFA_F05_calc_pred_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
