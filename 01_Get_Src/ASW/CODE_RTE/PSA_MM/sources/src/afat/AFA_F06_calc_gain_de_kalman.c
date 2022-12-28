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
/* !File            : AFA_F06_calc_gain_de_kalman.c                           */
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
/*   Model name       : AFA_F06_calc_gain_de_kalman.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F06_calc_gain_de_kalman.h"
#include "AFA_F06_calc_gain_de_kalman_private.h"
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

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F06_calc_gain_de_kalman' */
void mr_AFA_F06_calc_gain_de_kalman(const UInt16
  rtu_AFA_prm_covIvsPredInnovMat_[4], const Boolean *rtu_AFA_bIdcInv_covPred4,
  const SInt32 rtu_AFA_prm_facSenTransMat_PIM[16], const UInt16
  rtu_AFA_prm_covPredE[64], SInt16 rty_AFA_prm_facKalmMat_PIM[16])
{
  Float32 localSwitch1_e[16];
  SInt32 locali;
  Float32 localtmp[16];
  SInt32 localtmp_0;
  Float32 localtmp_1[16];
  SInt32 localtmp_2;
  Float32 locallocalSwitch1_e;
  SInt16 localtmp_3;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<S1>/OutDTConv'
   */
  if ((*rtu_AFA_bIdcInv_covPred4)) {
    for (locali = 0; locali < 16; locali++) {
      rty_AFA_prm_facKalmMat_PIM[(locali)] =
        AFA_F06_calc_gain_de_kal_ConstP.Constant2_Value[(locali)];
    }
  } else {
    /* Product: '<S1>/Product4' incorporates:
     *  Constant: '<S1>/offset'
     *  Constant: '<S1>/one_on_slope'
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     *  Product: '<Root>/Product'
     *  Product: '<Root>/Product2'
     *  Sum: '<S1>/Add1'
     */
    for (locali = 0; locali < 8; locali++) {
      for (localtmp_2 = 0; localtmp_2 < 2; localtmp_2++) {
        localtmp[locali + (localtmp_2 << 3)] = 0.0F;
        for (localtmp_0 = 0; localtmp_0 < 8; localtmp_0++) {
          localtmp[locali + (localtmp_2 << 3)] = ((((Float32)
            rtu_AFA_prm_covPredE[(localtmp_0 << 3) + locali]) *
            3.051757813E-005F) * (((Float32)rtu_AFA_prm_facSenTransMat_PIM
            [(localtmp_2 << 3) + localtmp_0]) * 0.0009765625F)) + localtmp
            [(localtmp_2 << 3) + locali];
        }
      }
    }

    for (locali = 0; locali < 8; locali++) {
      localtmp_1[locali] = ((((Float32)rtu_AFA_prm_covIvsPredInnovMat_[0]) *
        3.051757813E-005F) * localtmp[locali]) + (localtmp[locali + 8] *
        (((Float32)rtu_AFA_prm_covIvsPredInnovMat_[1]) * 3.051757813E-005F));
      localtmp_1[locali + 8] = ((((Float32)rtu_AFA_prm_covIvsPredInnovMat_[2]) *
        3.051757813E-005F) * localtmp[locali]) + (localtmp[locali + 8] *
        (((Float32)rtu_AFA_prm_covIvsPredInnovMat_[3]) * 3.051757813E-005F));
    }

    for (locali = 0; locali < 2; locali++) {
      for (localtmp_2 = 0; localtmp_2 < 8; localtmp_2++) {
        localSwitch1_e[localtmp_2 + (locali << 3)] = localtmp_1[(locali << 3) +
          localtmp_2] * 32768.0F;
      }
    }

    for (locali = 0; locali < 16; locali++) {
      /* Switch: '<S1>/Switch1' incorporates:
       *  Constant: '<S1>/offset2'
       *  Constant: '<S1>/offset3'
       *  Constant: '<S1>/offset4'
       *  RelationalOperator: '<S1>/Relational Operator'
       *  Sum: '<S1>/Add3'
       *  Sum: '<S1>/Add4'
       */
      if (localSwitch1_e[locali] >= 0.0F) {
        locallocalSwitch1_e = localSwitch1_e[locali] + 0.5F;
      } else {
        locallocalSwitch1_e = localSwitch1_e[locali] - 0.5F;
      }

      if (locallocalSwitch1_e < 32768.0F) {
        if (locallocalSwitch1_e >= -32768.0F) {
          localtmp_3 = (SInt16)locallocalSwitch1_e;
        } else {
          localtmp_3 = MIN_int16_T;
        }
      } else {
        localtmp_3 = MAX_int16_T;
      }

      rty_AFA_prm_facKalmMat_PIM[(locali)] = localtmp_3;
    }
  }
}

/* Model initialize function */
void mr_AFA_F06_calc_gain_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
