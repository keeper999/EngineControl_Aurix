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
/* !File            : AFA_F03_Calc_Sensitivity_Inj.c                          */
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
/*   Model name       : AFA_F03_Calc_Sensitivity_Inj.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F03_Calc_Sensitivity_Inj.h"
#include "AFA_F03_Calc_Sensitivity_Inj_private.h"
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
UInt32 AFA_rlamGrd_facSlopInjGain;   /* '<S14>/OutDTConv' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

UInt16 AFA_rlamGrd_facIvsInjGain;    /* '<S13>/OutDTConv' */
UInt16 AFA_rlamGrd_tiOffInj;         /* '<S15>/OutDTConv' */

/* Exported block states */
UInt16 AFA_prm_rlamGrd_facIvsInj_MP[4];/* '<Root>/Data Store Memory1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F03_Calc_Sensitivity_Inj' */
void mr_AFA_F03_Calc_Sensitivity_Inj(const UInt32 *rtu_AFA_mFuReqFil, const
  UInt32 rtu_AFA_prm_facGainInjFil_PIM[4], const UInt32
  rtu_AFA_prm_pDifInjrFil_PIM[4], const UInt32 rtu_InjrSys_prm_tiInj[4], const
  UInt16 rtu_AFA_prm_facCorGainLnrFil_PI[4], const UInt16
  *rtu_AFA_rEthStoichFil, const UInt8 *rtu_AFA_facRhoFuFil, UInt16
  *rty_AFA_rlamGrd_tiOffInj, UInt16 *rty_AFA_rlamGrd_facIvsInjGain, UInt32
  *rty_AFA_rlamGrd_facSlopInjGain)
{
  Float32 localDivide_h;
  Float32 localSwitch1_e;
  Float32 localSwitch1_k0;
  Float32 localSwitch1_p;
  Float32 locallocalDataTypeConversion;
  Float32 locallocalDataTypeConversion4_i;
  Float32 locallocalDataTypeConversion4_0;
  Float32 locallocalDataTypeConversion4_1;
  Float32 locallocalDataTypeConversion4_2;
  Float32 locallocalDataTypeConversion5_i;
  Float32 locallocalDataTypeConversion5_0;
  Float32 locallocalDataTypeConversion5_1;
  Float32 locallocalDataTypeConversion5_2;
  Float32 locallocalProduct1_idx;
  Float32 locallocalProduct1_idx_0;
  Float32 locallocalProduct1_idx_1;
  Float32 locallocalProduct1_idx_2;
  UInt16 localtmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  locallocalDataTypeConversion4_i = ((Float32)rtu_AFA_prm_facGainInjFil_PIM[0])
    * 0.015625F;
  locallocalDataTypeConversion4_0 = ((Float32)rtu_AFA_prm_facGainInjFil_PIM[1])
    * 0.015625F;
  locallocalDataTypeConversion4_1 = ((Float32)rtu_AFA_prm_facGainInjFil_PIM[2])
    * 0.015625F;
  locallocalDataTypeConversion4_2 = ((Float32)rtu_AFA_prm_facGainInjFil_PIM[3])
    * 0.015625F;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/AFA_bSelInjGain_C'
   */
  if (!AFA_bSelInjGain_C) {
    /* Product: '<S4>/Divide' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     */
    localDivide_h = locallocalDataTypeConversion4_i / (((Float32)
      rtu_AFA_prm_facCorGainLnrFil_PI[0]) * 3.051757813E-005F);

    /* Outputs for atomic SubSystem: '<S4>/If Action Subsystem3' */

    /* Switch: '<S24>/Switch1' incorporates:
     *  Constant: '<S24>/Constant2'
     *  RelationalOperator: '<S24>/Relational Operator'
     *  Saturate: '<S24>/Saturation'
     */
    if (localDivide_h != localDivide_h) {
      localSwitch1_e = 0.0F;
    } else {
      localSwitch1_e = rt_SATURATE(localDivide_h, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S4>/If Action Subsystem3' */

    /* Product: '<S3>/Divide' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     */
    localDivide_h = locallocalDataTypeConversion4_0 / (((Float32)
      rtu_AFA_prm_facCorGainLnrFil_PI[1]) * 3.051757813E-005F);

    /* Outputs for atomic SubSystem: '<S3>/If Action Subsystem3' */

    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/Constant2'
     *  RelationalOperator: '<S22>/Relational Operator'
     *  Saturate: '<S22>/Saturation'
     */
    if (localDivide_h != localDivide_h) {
      localSwitch1_k0 = 0.0F;
    } else {
      localSwitch1_k0 = rt_SATURATE(localDivide_h, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S3>/If Action Subsystem3' */

    /* Product: '<S2>/Divide' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     */
    localDivide_h = locallocalDataTypeConversion4_1 / (((Float32)
      rtu_AFA_prm_facCorGainLnrFil_PI[2]) * 3.051757813E-005F);

    /* Outputs for atomic SubSystem: '<S2>/If Action Subsystem3' */

    /* Switch: '<S20>/Switch1' incorporates:
     *  Constant: '<S20>/Constant2'
     *  RelationalOperator: '<S20>/Relational Operator'
     *  Saturate: '<S20>/Saturation'
     */
    if (localDivide_h != localDivide_h) {
      localSwitch1_p = 0.0F;
    } else {
      localSwitch1_p = rt_SATURATE(localDivide_h, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S2>/If Action Subsystem3' */

    /* Product: '<S1>/Divide' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     */
    localDivide_h = locallocalDataTypeConversion4_2 / (((Float32)
      rtu_AFA_prm_facCorGainLnrFil_PI[3]) * 3.051757813E-005F);

    /* Outputs for atomic SubSystem: '<S1>/If Action Subsystem3' */

    /* Switch: '<S18>/Switch1' incorporates:
     *  Constant: '<S18>/Constant2'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  Saturate: '<S18>/Saturation'
     */
    if (localDivide_h != localDivide_h) {
      localDivide_h = 0.0F;
    } else {
      localDivide_h = rt_SATURATE(localDivide_h, -3.000000005E+038F,
        3.000000005E+038F);
    }

    /* end of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
    locallocalDataTypeConversion4_i = localSwitch1_e;
    locallocalDataTypeConversion4_0 = localSwitch1_k0;
    locallocalDataTypeConversion4_1 = localSwitch1_p;
    locallocalDataTypeConversion4_2 = localDivide_h;
  }

  /* Product: '<S9>/Divide' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  localDivide_h = 1.0F / locallocalDataTypeConversion4_i;

  /* Outputs for atomic SubSystem: '<S9>/If Action Subsystem3' */

  /* Switch: '<S34>/Switch1' incorporates:
   *  Constant: '<S34>/Constant2'
   *  RelationalOperator: '<S34>/Relational Operator'
   *  Saturate: '<S34>/Saturation'
   */
  if (localDivide_h != localDivide_h) {
    localSwitch1_e = 0.0F;
  } else {
    localSwitch1_e = rt_SATURATE(localDivide_h, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S9>/If Action Subsystem3' */

  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  localDivide_h = 1.0F / locallocalDataTypeConversion4_0;

  /* Outputs for atomic SubSystem: '<S10>/If Action Subsystem3' */

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S36>/Constant2'
   *  RelationalOperator: '<S36>/Relational Operator'
   *  Saturate: '<S36>/Saturation'
   */
  if (localDivide_h != localDivide_h) {
    localSwitch1_k0 = 0.0F;
  } else {
    localSwitch1_k0 = rt_SATURATE(localDivide_h, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S10>/If Action Subsystem3' */

  /* Product: '<S11>/Divide' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  localDivide_h = 1.0F / locallocalDataTypeConversion4_1;

  /* Outputs for atomic SubSystem: '<S11>/If Action Subsystem3' */

  /* Switch: '<S38>/Switch1' incorporates:
   *  Constant: '<S38>/Constant2'
   *  RelationalOperator: '<S38>/Relational Operator'
   *  Saturate: '<S38>/Saturation'
   */
  if (localDivide_h != localDivide_h) {
    localSwitch1_p = 0.0F;
  } else {
    localSwitch1_p = rt_SATURATE(localDivide_h, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S11>/If Action Subsystem3' */

  /* Product: '<S12>/Divide' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  localDivide_h = 1.0F / locallocalDataTypeConversion4_2;

  /* Outputs for atomic SubSystem: '<S12>/If Action Subsystem3' */

  /* Switch: '<S40>/Switch1' incorporates:
   *  Constant: '<S40>/Constant2'
   *  RelationalOperator: '<S40>/Relational Operator'
   *  Saturate: '<S40>/Saturation'
   */
  if (localDivide_h != localDivide_h) {
    localDivide_h = 0.0F;
  } else {
    localDivide_h = rt_SATURATE(localDivide_h, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S12>/If Action Subsystem3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   *  RelationalOperator: '<Root>/Relational Operator2'
   */
  locallocalDataTypeConversion5_i = (Float32)(rtu_InjrSys_prm_tiInj[0] > 0U);
  locallocalDataTypeConversion5_0 = (Float32)(rtu_InjrSys_prm_tiInj[1] > 0U);
  locallocalDataTypeConversion5_1 = (Float32)(rtu_InjrSys_prm_tiInj[2] > 0U);
  locallocalDataTypeConversion5_2 = (Float32)(rtu_InjrSys_prm_tiInj[3] > 0U);

  /* Product: '<Root>/Product1' */
  locallocalProduct1_idx = localSwitch1_e * locallocalDataTypeConversion5_i;
  locallocalProduct1_idx_0 = localSwitch1_k0 * locallocalDataTypeConversion5_0;
  locallocalProduct1_idx_1 = localSwitch1_p * locallocalDataTypeConversion5_1;
  locallocalProduct1_idx_2 = localDivide_h * locallocalDataTypeConversion5_2;

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  Constant: '<S16>/offset'
   *  Constant: '<S16>/offset1'
   *  Constant: '<S16>/one_on_slope'
   *  DataTypeConversion: '<S16>/OutDTConv'
   *  Product: '<S16>/Product4'
   *  Sum: '<S16>/Add1'
   *  Sum: '<S16>/Add2'
   */
  locallocalDataTypeConversion = (655360.0F * locallocalProduct1_idx) + 0.5F;
  if (locallocalDataTypeConversion < 65536.0F) {
    if (locallocalDataTypeConversion >= 0.0F) {
      localtmp = (UInt16)locallocalDataTypeConversion;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint16_T;
  }

  AFA_prm_rlamGrd_facIvsInj_MP[0] = localtmp;

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  Constant: '<S16>/offset'
   *  Constant: '<S16>/offset1'
   *  Constant: '<S16>/one_on_slope'
   *  DataTypeConversion: '<S16>/OutDTConv'
   *  Product: '<S16>/Product4'
   *  Sum: '<S16>/Add1'
   *  Sum: '<S16>/Add2'
   */
  locallocalDataTypeConversion = (655360.0F * locallocalProduct1_idx_0) + 0.5F;
  if (locallocalDataTypeConversion < 65536.0F) {
    if (locallocalDataTypeConversion >= 0.0F) {
      localtmp = (UInt16)locallocalDataTypeConversion;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint16_T;
  }

  AFA_prm_rlamGrd_facIvsInj_MP[1] = localtmp;

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  Constant: '<S16>/offset'
   *  Constant: '<S16>/offset1'
   *  Constant: '<S16>/one_on_slope'
   *  DataTypeConversion: '<S16>/OutDTConv'
   *  Product: '<S16>/Product4'
   *  Sum: '<S16>/Add1'
   *  Sum: '<S16>/Add2'
   */
  locallocalDataTypeConversion = (655360.0F * locallocalProduct1_idx_1) + 0.5F;
  if (locallocalDataTypeConversion < 65536.0F) {
    if (locallocalDataTypeConversion >= 0.0F) {
      localtmp = (UInt16)locallocalDataTypeConversion;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint16_T;
  }

  AFA_prm_rlamGrd_facIvsInj_MP[2] = localtmp;

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  Constant: '<S16>/offset'
   *  Constant: '<S16>/offset1'
   *  Constant: '<S16>/one_on_slope'
   *  DataTypeConversion: '<S16>/OutDTConv'
   *  Product: '<S16>/Product4'
   *  Sum: '<S16>/Add1'
   *  Sum: '<S16>/Add2'
   */
  locallocalDataTypeConversion = (655360.0F * locallocalProduct1_idx_2) + 0.5F;
  if (locallocalDataTypeConversion < 65536.0F) {
    if (locallocalDataTypeConversion >= 0.0F) {
      localtmp = (UInt16)locallocalDataTypeConversion;
    } else {
      localtmp = 0U;
    }
  } else {
    localtmp = MAX_uint16_T;
  }

  AFA_prm_rlamGrd_facIvsInj_MP[3] = localtmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  localDivide_h = ((Float32)(*rtu_AFA_mFuReqFil)) * 7.450580597E-009F;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/AFA_bInhFacEthStoich_C'
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   */
  if (AFA_bInhFacEthStoich_C) {
    localSwitch1_p = 1.0F;
  } else {
    localSwitch1_p = ((Float32)(*rtu_AFA_rEthStoichFil)) * 3.051757813E-005F;
  }

  /* Product: '<Root>/Product4' incorporates:
   *  Product: '<Root>/Product'
   */
  locallocalDataTypeConversion4_i = (locallocalDataTypeConversion4_i *
    localDivide_h) * localSwitch1_p;
  locallocalDataTypeConversion4_0 = (locallocalDataTypeConversion4_0 *
    localDivide_h) * localSwitch1_p;
  locallocalDataTypeConversion4_1 = (locallocalDataTypeConversion4_1 *
    localDivide_h) * localSwitch1_p;
  locallocalDataTypeConversion = (locallocalDataTypeConversion4_2 *
    localDivide_h) * localSwitch1_p;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/AFA_bInhFacRhoFu_C'
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  if (AFA_bInhFacRhoFu_C) {
    localSwitch1_p = 1.0F;
  } else {
    localSwitch1_p = ((Float32)(*rtu_AFA_facRhoFuFil)) * 0.0078125F;
  }

  /* Product: '<Root>/Product5' */
  locallocalDataTypeConversion *= localSwitch1_p;

  /* Product: '<S5>/Divide' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  localDivide_h = 1.0F / (locallocalDataTypeConversion4_i * localSwitch1_p);

  /* Outputs for atomic SubSystem: '<S5>/If Action Subsystem3' */

  /* Switch: '<S26>/Switch1' incorporates:
   *  Constant: '<S26>/Constant2'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  Saturate: '<S26>/Saturation'
   */
  if (localDivide_h != localDivide_h) {
    localSwitch1_e = 0.0F;
  } else {
    localSwitch1_e = rt_SATURATE(localDivide_h, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S5>/If Action Subsystem3' */

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  localDivide_h = 1.0F / (locallocalDataTypeConversion4_0 * localSwitch1_p);

  /* Outputs for atomic SubSystem: '<S6>/If Action Subsystem3' */

  /* Switch: '<S28>/Switch1' incorporates:
   *  Constant: '<S28>/Constant2'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  Saturate: '<S28>/Saturation'
   */
  if (localDivide_h != localDivide_h) {
    localSwitch1_k0 = 0.0F;
  } else {
    localSwitch1_k0 = rt_SATURATE(localDivide_h, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S6>/If Action Subsystem3' */

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  localDivide_h = 1.0F / (locallocalDataTypeConversion4_1 * localSwitch1_p);

  /* Outputs for atomic SubSystem: '<S7>/If Action Subsystem3' */

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S30>/Constant2'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  Saturate: '<S30>/Saturation'
   */
  if (localDivide_h != localDivide_h) {
    localSwitch1_p = 0.0F;
  } else {
    localSwitch1_p = rt_SATURATE(localDivide_h, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S7>/If Action Subsystem3' */

  /* Product: '<S8>/Divide' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  localDivide_h = 1.0F / locallocalDataTypeConversion;

  /* Outputs for atomic SubSystem: '<S8>/If Action Subsystem3' */

  /* Switch: '<S32>/Switch1' incorporates:
   *  Constant: '<S32>/Constant2'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  Saturate: '<S32>/Saturation'
   */
  if (localDivide_h != localDivide_h) {
    localDivide_h = 0.0F;
  } else {
    localDivide_h = rt_SATURATE(localDivide_h, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S8>/If Action Subsystem3' */

  /* Product: '<Root>/Product2' */
  locallocalDataTypeConversion5_i *= localSwitch1_e;
  locallocalDataTypeConversion5_0 *= localSwitch1_k0;
  locallocalDataTypeConversion5_1 *= localSwitch1_p;

  /* DataTypeConversion: '<S14>/OutDTConv' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/offset1'
   *  Constant: '<S14>/one_on_slope'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Product: '<Root>/Product3'
   *  Product: '<S14>/Product4'
   *  Sum: '<Root>/Add1'
   *  Sum: '<S14>/Add1'
   *  Sum: '<S14>/Add2'
   */
  locallocalDataTypeConversion = ((((((((Float32)rtu_AFA_prm_pDifInjrFil_PIM[0])
    * 512.0F) * locallocalProduct1_idx) + ((((Float32)
    rtu_AFA_prm_pDifInjrFil_PIM[1]) * 512.0F) * locallocalProduct1_idx_0)) +
                                    ((((Float32)rtu_AFA_prm_pDifInjrFil_PIM[2])
    * 512.0F) * locallocalProduct1_idx_1)) + ((((Float32)
    rtu_AFA_prm_pDifInjrFil_PIM[3]) * 512.0F) * locallocalProduct1_idx_2)) *
    64.0F) + 0.5F;
  if (locallocalDataTypeConversion < 4.294967296E+009F) {
    if (locallocalDataTypeConversion >= 0.0F) {
      AFA_rlamGrd_facSlopInjGain = (UInt32)locallocalDataTypeConversion;
    } else {
      AFA_rlamGrd_facSlopInjGain = 0U;
    }
  } else {
    AFA_rlamGrd_facSlopInjGain = MAX_uint32_T;
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_rlamGrd_facSlopInjGain) = AFA_rlamGrd_facSlopInjGain;

  /* DataTypeConversion: '<S15>/OutDTConv' incorporates:
   *  Constant: '<S15>/offset'
   *  Constant: '<S15>/offset1'
   *  Constant: '<S15>/one_on_slope'
   *  Product: '<S15>/Product4'
   *  Sum: '<Root>/Add2'
   *  Sum: '<S15>/Add1'
   *  Sum: '<S15>/Add2'
   */
  locallocalDataTypeConversion = ((((locallocalDataTypeConversion5_i +
    locallocalDataTypeConversion5_0) + locallocalDataTypeConversion5_1) +
    (locallocalDataTypeConversion5_2 * localDivide_h)) * 32.0F) + 0.5F;
  if (locallocalDataTypeConversion < 65536.0F) {
    if (locallocalDataTypeConversion >= 0.0F) {
      AFA_rlamGrd_tiOffInj = (UInt16)locallocalDataTypeConversion;
    } else {
      AFA_rlamGrd_tiOffInj = 0U;
    }
  } else {
    AFA_rlamGrd_tiOffInj = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_rlamGrd_tiOffInj) = AFA_rlamGrd_tiOffInj;

  /* DataTypeConversion: '<S13>/OutDTConv' incorporates:
   *  Constant: '<S13>/offset'
   *  Constant: '<S13>/offset1'
   *  Constant: '<S13>/one_on_slope'
   *  Product: '<S13>/Product4'
   *  Sum: '<Root>/Add4'
   *  Sum: '<S13>/Add1'
   *  Sum: '<S13>/Add2'
   */
  locallocalDataTypeConversion = ((((locallocalProduct1_idx +
    locallocalProduct1_idx_0) + locallocalProduct1_idx_1) +
    locallocalProduct1_idx_2) * 655360.0F) + 0.5F;
  if (locallocalDataTypeConversion < 65536.0F) {
    if (locallocalDataTypeConversion >= 0.0F) {
      AFA_rlamGrd_facIvsInjGain = (UInt16)locallocalDataTypeConversion;
    } else {
      AFA_rlamGrd_facIvsInjGain = 0U;
    }
  } else {
    AFA_rlamGrd_facIvsInjGain = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal3' */
  (*rty_AFA_rlamGrd_facIvsInjGain) = AFA_rlamGrd_facIvsInjGain;
}

/* Model initialize function */
void mr_AFA_F03_Calc_Sens_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
