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
/* !File            : AFA_F08_calc_est_error_covar_mat.c                      */
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
/*   Model name       : AFA_F08_calc_est_error_covar_mat.mdl                  */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F08_calc_est_error_covar_mat.h"
#include "AFA_F08_calc_est_error_covar_mat_private.h"
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
UInt16 AFA_prm_covErrEstim1_MP[64];  /* '<Root>/Data Store Memory1' */
UInt16 AFA_prm_covErrEstim2_MP[64];  /* '<Root>/Data Store Memory2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F08_calc_est_error_covar_mat' */
void mr_AFA_F08_calc_est_error_covar(const UInt8
  rtu_AFA_prm_covNoiseMesMat_PIM[4], const SInt16 rtu_AFA_prm_facKalm[16],
  const UInt16 rtu_AFA_prm_covPredErrMat_PIM[64], const SInt16
  rtu_AFA_prm_facInterMat_PIM[16], const SInt32 rtu_AFA_prm_facSen[16],
  UInt16 rty_AFA_prm_covErrEstimMat_PIM[64])
{
  Float32 localDataTypeConversion[16];
  Float32 localSwitch[64];
  Float32 localProduct5[64];
  Float32 localProduct4_e[64];
  SInt32 locali;
  Float32 localtmp[64];
  SInt32 localtmp_0;
  Float32 locallocalDataTypeConversion[16];
  SInt32 localtmp_1;
  Float32 locallocalSwitch;
  Float32 localtmp_2;
  UInt16 localtmp_3;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  for (locali = 0; locali < 16; locali++) {
    localDataTypeConversion[locali] = ((Float32)rtu_AFA_prm_facKalm[(locali)]) *
      3.051757813E-005F;
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Product: '<Root>/Product1'
   */
  for (locali = 0; locali < 8; locali++) {
    for (localtmp_1 = 0; localtmp_1 < 8; localtmp_1++) {
      localSwitch[locali + (localtmp_1 << 3)] = (((Float32)
        rtu_AFA_prm_covPredErrMat_PIM[(localtmp_1 << 3) + locali]) *
        3.051757813E-005F) - (((((Float32)rtu_AFA_prm_facInterMat_PIM
        [(localtmp_1 << 1) + 1]) * 0.001953125F) *
        localDataTypeConversion[locali + 8]) + ((((Float32)
        rtu_AFA_prm_facInterMat_PIM[(localtmp_1 << 1)]) * 0.001953125F) *
        localDataTypeConversion[locali]));
    }
  }

  /* Product: '<Root>/Product5' incorporates:
   *  Constant: '<Root>/Constant40'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  Math: '<Root>/Math Function'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Subtract1'
   */
  for (locali = 0; locali < 8; locali++) {
    for (localtmp_1 = 0; localtmp_1 < 8; localtmp_1++) {
      localtmp[locali + (localtmp_1 << 3)] =
        AFA_F08_calc_est_error_c_ConstP.Constant40_Value[(localtmp_1 << 3) +
        locali] - (((((Float32)rtu_AFA_prm_facSen[(localtmp_1 << 1) + 1]) *
                     0.0009765625F) * localDataTypeConversion[locali + 8]) +
                   ((((Float32)rtu_AFA_prm_facSen[(localtmp_1 << 1)]) *
                     0.0009765625F) * localDataTypeConversion[locali]));
    }
  }

  for (locali = 0; locali < 8; locali++) {
    for (localtmp_1 = 0; localtmp_1 < 8; localtmp_1++) {
      localProduct5[locali + (localtmp_1 << 3)] = 0.0F;
      for (localtmp_0 = 0; localtmp_0 < 8; localtmp_0++) {
        localProduct5[locali + (localtmp_1 << 3)] = (localSwitch[(localtmp_0 <<
          3) + locali] * localtmp[(localtmp_0 << 3) + localtmp_1]) +
          localProduct5[(localtmp_1 << 3) + locali];
      }
    }
  }

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  Constant: '<S2>/offset'
   *  Constant: '<S2>/offset1'
   *  Constant: '<S2>/one_on_slope'
   *  DataTypeConversion: '<S2>/OutDTConv'
   *  Product: '<S2>/Product4'
   *  Sum: '<S2>/Add1'
   *  Sum: '<S2>/Add2'
   */
  for (locali = 0; locali < 64; locali++) {
    locallocalSwitch = (32768.0F * localProduct5[locali]) + 0.5F;
    if (locallocalSwitch < 65536.0F) {
      if (locallocalSwitch >= 0.0F) {
        localtmp_3 = (UInt16)locallocalSwitch;
      } else {
        localtmp_3 = 0U;
      }
    } else {
      localtmp_3 = MAX_uint16_T;
    }

    AFA_prm_covErrEstim1_MP[locali] = localtmp_3;
  }

  /* Product: '<Root>/Product4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Math: '<Root>/Math Function1'
   *  Product: '<Root>/Product2'
   */
  for (locali = 0; locali < 8; locali++) {
    locallocalDataTypeConversion[locali] = 0.0F;
    locallocalDataTypeConversion[locali] += (((Float32)
      rtu_AFA_prm_covNoiseMesMat_PIM[0]) * 0.25F) *
      localDataTypeConversion[locali];
    locallocalDataTypeConversion[locali] += localDataTypeConversion[locali + 8] *
      (((Float32)rtu_AFA_prm_covNoiseMesMat_PIM[1]) * 0.25F);
    locallocalDataTypeConversion[locali + 8] = 0.0F;
    locallocalDataTypeConversion[locali + 8] += (((Float32)
      rtu_AFA_prm_covNoiseMesMat_PIM[2]) * 0.25F) *
      localDataTypeConversion[locali];
    locallocalDataTypeConversion[locali + 8] += localDataTypeConversion[locali +
      8] * (((Float32)rtu_AFA_prm_covNoiseMesMat_PIM[3]) * 0.25F);
  }

  for (locali = 0; locali < 8; locali++) {
    for (localtmp_1 = 0; localtmp_1 < 8; localtmp_1++) {
      localProduct4_e[locali + (localtmp_1 << 3)] = 0.0F;
      localProduct4_e[locali + (localtmp_1 << 3)] = localProduct4_e[(localtmp_1 <<
        3) + locali] + (locallocalDataTypeConversion[locali] *
                        localDataTypeConversion[localtmp_1]);
      localProduct4_e[locali + (localtmp_1 << 3)] = localProduct4_e[(localtmp_1 <<
        3) + locali] + (locallocalDataTypeConversion[locali + 8] *
                        localDataTypeConversion[localtmp_1 + 8]);
    }
  }

  for (locali = 0; locali < 64; locali++) {
    locallocalSwitch = localSwitch[locali];

    /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
     *  Constant: '<S1>/offset'
     *  Constant: '<S1>/offset1'
     *  Constant: '<S1>/one_on_slope'
     *  DataTypeConversion: '<S1>/OutDTConv'
     *  Product: '<S1>/Product4'
     *  Sum: '<S1>/Add1'
     *  Sum: '<S1>/Add2'
     */
    localtmp_2 = (32768.0F * localProduct4_e[locali]) + 0.5F;
    if (localtmp_2 < 65536.0F) {
      if (localtmp_2 >= 0.0F) {
        localtmp_3 = (UInt16)localtmp_2;
      } else {
        localtmp_3 = 0U;
      }
    } else {
      localtmp_3 = MAX_uint16_T;
    }

    AFA_prm_covErrEstim2_MP[locali] = localtmp_3;

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/AFA_bInhCalcMod_C'
     *  Sum: '<Root>/Subtract2'
     */
    if (!AFA_bInhCalcMod_C) {
      locallocalSwitch = localProduct5[locali] + localProduct4_e[locali];
    }

    /* DataTypeConversion: '<S3>/OutDTConv' incorporates:
     *  Constant: '<S3>/offset'
     *  Constant: '<S3>/offset1'
     *  Constant: '<S3>/one_on_slope'
     *  Product: '<S3>/Product4'
     *  Sum: '<S3>/Add1'
     *  Sum: '<S3>/Add2'
     */
    locallocalSwitch = (32768.0F * locallocalSwitch) + 0.5F;
    if (locallocalSwitch < 65536.0F) {
      if (locallocalSwitch >= 0.0F) {
        localtmp_3 = (UInt16)locallocalSwitch;
      } else {
        localtmp_3 = 0U;
      }
    } else {
      localtmp_3 = MAX_uint16_T;
    }

    rty_AFA_prm_covErrEstimMat_PIM[(locali)] = localtmp_3;
  }
}

/* Model initialize function */
void mr_AFA_F08_calc_est__initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
