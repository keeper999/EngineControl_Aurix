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
/* !File            : AFA_F04_calc_innovation_vect.c                          */
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
/*   Model name       : AFA_F04_calc_innovation_vect.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F04_calc_innovation_vect.h"
#include "AFA_F04_calc_innovation_vect_private.h"
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

/* Output and update for referenced model: 'AFA_F04_calc_innovation_vect' */
void mr_AFA_F04_calc_innovation_vect(const SInt16 rtu_AFA_prm_rErr_PIM[8],
  const SInt16 rtu_AFA_prm_facMes_PIM[2], const SInt32 rtu_AFA_prm_facSenT[16],
  SInt16 rty_AFA_prm_facOutInnov_PIM[2], SInt32 rty_AFA_prm_facSenMat_PIM[16])
{
  SInt32 localtmp;
  Float32 localtmp_0[2];
  SInt32 localtmp_1;
  Float32 locallocalSwitch;
  SInt16 localtmp_2;

  /* Math: '<Root>/Math Function' */
  for (localtmp = 0; localtmp < 8; localtmp++) {
    rty_AFA_prm_facSenMat_PIM[(localtmp << 1)] = rtu_AFA_prm_facSenT[(localtmp)];
    rty_AFA_prm_facSenMat_PIM[1 + (localtmp << 1)] =
      rtu_AFA_prm_facSenT[localtmp + 8];
  }

  /* Product: '<S1>/Product4' incorporates:
   *  Constant: '<S1>/offset'
   *  Constant: '<S1>/one_on_slope'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Subtract'
   *  Sum: '<S1>/Add1'
   */
  for (localtmp = 0; localtmp < 2; localtmp++) {
    locallocalSwitch = 0.0F;
    for (localtmp_1 = 0; localtmp_1 < 8; localtmp_1++) {
      locallocalSwitch += (((Float32)rty_AFA_prm_facSenMat_PIM[(localtmp_1 << 1)
                            + localtmp]) * 0.0009765625F) * (((Float32)
        rtu_AFA_prm_rErr_PIM[(localtmp_1)]) * 0.0001220703125F);
    }

    localtmp_0[localtmp] = (((Float32)rtu_AFA_prm_facMes_PIM[(localtmp)]) *
      0.00390625F) - locallocalSwitch;
  }

  locallocalSwitch = 256.0F * localtmp_0[0];

  /* DataTypeConversion: '<S1>/OutDTConv' incorporates:
   *  Constant: '<S1>/offset2'
   *  Constant: '<S1>/offset3'
   *  Constant: '<S1>/offset4'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  Sum: '<S1>/Add3'
   *  Sum: '<S1>/Add4'
   *  Switch: '<S1>/Switch1'
   */
  if (locallocalSwitch >= 0.0F) {
    locallocalSwitch += 0.5F;
    if (locallocalSwitch < 32768.0F) {
      localtmp_2 = (SInt16)locallocalSwitch;
    } else {
      localtmp_2 = MAX_int16_T;
    }

    rty_AFA_prm_facOutInnov_PIM[0] = localtmp_2;
  } else {
    locallocalSwitch -= 0.5F;
    if (locallocalSwitch >= -32768.0F) {
      localtmp_2 = (SInt16)locallocalSwitch;
    } else {
      localtmp_2 = MIN_int16_T;
    }

    rty_AFA_prm_facOutInnov_PIM[0] = localtmp_2;
  }

  locallocalSwitch = 256.0F * localtmp_0[1];

  /* DataTypeConversion: '<S1>/OutDTConv' incorporates:
   *  Constant: '<S1>/offset2'
   *  Constant: '<S1>/offset3'
   *  Constant: '<S1>/offset4'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  Sum: '<S1>/Add3'
   *  Sum: '<S1>/Add4'
   *  Switch: '<S1>/Switch1'
   */
  if (locallocalSwitch >= 0.0F) {
    locallocalSwitch += 0.5F;
    if (locallocalSwitch < 32768.0F) {
      localtmp_2 = (SInt16)locallocalSwitch;
    } else {
      localtmp_2 = MAX_int16_T;
    }

    rty_AFA_prm_facOutInnov_PIM[1] = localtmp_2;
  } else {
    locallocalSwitch -= 0.5F;
    if (locallocalSwitch >= -32768.0F) {
      localtmp_2 = (SInt16)locallocalSwitch;
    } else {
      localtmp_2 = MIN_int16_T;
    }

    rty_AFA_prm_facOutInnov_PIM[1] = localtmp_2;
  }
}

/* Model initialize function */
void mr_AFA_F04_calc_inno_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
