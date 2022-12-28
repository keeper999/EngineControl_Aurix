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
/* !File            : AFA_F08_burn_gas_temperature.c                          */
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
/*   Model name       : AFA_F08_burn_gas_temperature.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F08_burn_gas_temperature.h"
#include "AFA_F08_burn_gas_temperature_private.h"
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
UInt16 AFA_facTBurnCyl;              /* '<S14>/OutDTConv' */
SInt16 AFA_facTBurnGrdCyl_agCkEx;     /* '<S15>/OutDTConv' */
SInt16 AFA_facTBurnGrdCyl_agCkIn;     /* '<S16>/OutDTConv' */

/* Exported block states */
UInt16 AFA_rMassBurn1_MP;            /* '<Root>/Data Store Memory1' */
UInt16 AFA_rMassBurn2_MP;            /* '<Root>/Data Store Memory2' */
UInt16 AFA_rMassBurn3_MP;            /* '<Root>/Data Store Memory3' */
UInt16 AFA_rMassBurn4_MP;            /* '<Root>/Data Store Memory4' */
UInt16 AFA_tBurnCyl_MP;              /* '<Root>/Data Store Memory5' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F08_burn_gas_temperature' */
void mr_AFA_F08_burn_gas_temperature(const UInt16 *rtu_AFA_tExMnfEstimF8,
  const UInt16 *rtu_AFA_pDsThrPred_facVlvOvlpFi, const UInt16
  *rtu_AFA_pExMnfEstimF8, const UInt16 *rtu_AFA_rMassBurnRspg, const SInt16
  *rtu_AFA_rMassGrdBurnRspg_agCkEx, const SInt16
  *rtu_AFA_rMassGrdBurnRspg_agCkIn, const UInt16 *rtu_AFA_rMassBurnRg, const
  SInt16 *rtu_AFA_rMassGrdBurnRg_agCkEx, const SInt16
  *rtu_AFA_rMassGrdBurnRg_agCkIn, const UInt16 *rtu_AFA_rMassBurn, const
  SInt16 *rtu_AFA_rMassBurn_agCkEx, const SInt16 *rtu_AFA_rMassBurn_agCkIn,
  UInt16 *rty_AFA_facTBurnCyl, SInt16 *rty_AFA_facTBurnGrdCyl_agCkEx, SInt16
  *rty_AFA_facTBurnGrdCyl_agCkIn)
{
  Float32 localDataTypeConversion7;
  Float32 localDataTypeConversion13;
  Float32 localDataTypeConversion6;
  Float32 localLookupTablenD;
  Float32 localDivide;
  Float32 localSwitch1_hd;
  Float32 localLookupTablenD_n;
  Float32 localSwitch1_ff;
  Float32 localSwitch1_h;
  Float32 localSwitch1_a;
  Float32 localDataTypeConversion5;
  UInt16 locallocalOutDTConv;
  UInt32 localtmp;
  UInt16 locallocalDataTypeConversion;

  /* DataTypeConversion: '<Root>/Data Type Conversion7' */
  localDataTypeConversion7 = ((Float32)(*rtu_AFA_rMassBurnRspg)) *
    6.103515625E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion11' */
  localDataTypeConversion13 = ((Float32)(*rtu_AFA_rMassBurn_agCkEx)) *
    3.051757858E-006F;

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  localDataTypeConversion6 = ((Float32)(*rtu_AFA_rMassBurn)) *
    6.103515625E-005F;

  /* Product: '<Root>/Product6' */
  localLookupTablenD = localDataTypeConversion6 * localDataTypeConversion6;

  /* Product: '<S2>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion15'
   *  Product: '<Root>/Product'
   *  Product: '<Root>/Product1'
   *  Sum: '<Root>/Sum3'
   */
  localDivide = (((((Float32)(*rtu_AFA_rMassGrdBurnRspg_agCkEx)) *
                   3.051757858E-006F) * localDataTypeConversion6) -
                 (localDataTypeConversion7 * localDataTypeConversion13)) /
    localLookupTablenD;

  /* Outputs for atomic SubSystem: '<S2>/If Action Subsystem3' */

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S20>/Constant2'
   *  RelationalOperator: '<S20>/Relational Operator'
   *  Saturate: '<S20>/Saturation'
   */
  if (localDivide != localDivide) {
    localSwitch1_hd = 0.0F;
  } else {
    localSwitch1_hd = rt_SATURATE(localDivide, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S2>/If Action Subsystem3' */

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  Constant: '<S10>/offset'
   *  Constant: '<S10>/offset1'
   *  Constant: '<S10>/one_on_slope'
   *  DataTypeConversion: '<S10>/OutDTConv'
   *  Product: '<S10>/Product4'
   *  Sum: '<S10>/Add1'
   *  Sum: '<S10>/Add2'
   */
  localDivide = (16384.0F * localSwitch1_hd) + 0.5F;
  if (localDivide < 65536.0F) {
    if (localDivide >= 0.0F) {
      AFA_rMassBurn1_MP = (UInt16)localDivide;
    } else {
      AFA_rMassBurn1_MP = 0U;
    }
  } else {
    AFA_rMassBurn1_MP = MAX_uint16_T;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  localLookupTablenD_n = ((Float32)(*rtu_AFA_rMassBurnRg)) * 6.103515625E-005F;

  /* Product: '<S3>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion12'
   *  Product: '<Root>/Product7'
   *  Product: '<Root>/Product9'
   *  Sum: '<Root>/Sum4'
   */
  localDivide = (((((Float32)(*rtu_AFA_rMassGrdBurnRg_agCkEx)) *
                   3.051757858E-006F) * localDataTypeConversion6) -
                 (localLookupTablenD_n * localDataTypeConversion13)) /
    localLookupTablenD;

  /* Outputs for atomic SubSystem: '<S3>/If Action Subsystem3' */

  /* Switch: '<S22>/Switch1' incorporates:
   *  Constant: '<S22>/Constant2'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  Saturate: '<S22>/Saturation'
   */
  if (localDivide != localDivide) {
    localSwitch1_ff = 0.0F;
  } else {
    localSwitch1_ff = rt_SATURATE(localDivide, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S3>/If Action Subsystem3' */

  /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
   *  Constant: '<S11>/offset'
   *  Constant: '<S11>/offset1'
   *  Constant: '<S11>/one_on_slope'
   *  DataTypeConversion: '<S11>/OutDTConv'
   *  Product: '<S11>/Product4'
   *  Sum: '<S11>/Add1'
   *  Sum: '<S11>/Add2'
   */
  localDivide = (16384.0F * localSwitch1_ff) + 0.5F;
  if (localDivide < 65536.0F) {
    if (localDivide >= 0.0F) {
      AFA_rMassBurn2_MP = (UInt16)localDivide;
    } else {
      AFA_rMassBurn2_MP = 0U;
    }
  } else {
    AFA_rMassBurn2_MP = MAX_uint16_T;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion13' */
  localDataTypeConversion13 = ((Float32)(*rtu_AFA_rMassBurn_agCkIn)) *
    3.051757858E-006F;

  /* Product: '<S4>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion16'
   *  Product: '<Root>/Product11'
   *  Product: '<Root>/Product12'
   *  Sum: '<Root>/Sum6'
   */
  localDivide = (((((Float32)(*rtu_AFA_rMassGrdBurnRspg_agCkIn)) *
                   3.051757858E-006F) * localDataTypeConversion6) -
                 (localDataTypeConversion7 * localDataTypeConversion13)) /
    localLookupTablenD;

  /* Outputs for atomic SubSystem: '<S4>/If Action Subsystem3' */

  /* Switch: '<S24>/Switch1' incorporates:
   *  Constant: '<S24>/Constant2'
   *  RelationalOperator: '<S24>/Relational Operator'
   *  Saturate: '<S24>/Saturation'
   */
  if (localDivide != localDivide) {
    localSwitch1_h = 0.0F;
  } else {
    localSwitch1_h = rt_SATURATE(localDivide, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S4>/If Action Subsystem3' */

  /* DataStoreWrite: '<Root>/Data Store Write3' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/offset1'
   *  Constant: '<S12>/one_on_slope'
   *  DataTypeConversion: '<S12>/OutDTConv'
   *  Product: '<S12>/Product4'
   *  Sum: '<S12>/Add1'
   *  Sum: '<S12>/Add2'
   */
  localDivide = (16384.0F * localSwitch1_h) + 0.5F;
  if (localDivide < 65536.0F) {
    if (localDivide >= 0.0F) {
      AFA_rMassBurn3_MP = (UInt16)localDivide;
    } else {
      AFA_rMassBurn3_MP = 0U;
    }
  } else {
    AFA_rMassBurn3_MP = MAX_uint16_T;
  }

  /* Product: '<S5>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion14'
   *  Product: '<Root>/Product13'
   *  Product: '<Root>/Product17'
   *  Sum: '<Root>/Sum7'
   */
  localDivide = (((((Float32)(*rtu_AFA_rMassGrdBurnRg_agCkIn)) *
                   3.051757858E-006F) * localDataTypeConversion6) -
                 (localLookupTablenD_n * localDataTypeConversion13)) /
    localLookupTablenD;

  /* Outputs for atomic SubSystem: '<S5>/If Action Subsystem3' */

  /* Switch: '<S26>/Switch1' incorporates:
   *  Constant: '<S26>/Constant2'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  Saturate: '<S26>/Saturation'
   */
  if (localDivide != localDivide) {
    localDataTypeConversion13 = 0.0F;
  } else {
    localDataTypeConversion13 = rt_SATURATE(localDivide, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S5>/If Action Subsystem3' */

  /* DataStoreWrite: '<Root>/Data Store Write4' incorporates:
   *  Constant: '<S13>/offset'
   *  Constant: '<S13>/offset1'
   *  Constant: '<S13>/one_on_slope'
   *  DataTypeConversion: '<S13>/OutDTConv'
   *  Product: '<S13>/Product4'
   *  Sum: '<S13>/Add1'
   *  Sum: '<S13>/Add2'
   */
  localDivide = (16384.0F * localDataTypeConversion13) + 0.5F;
  if (localDivide < 65536.0F) {
    if (localDivide >= 0.0F) {
      AFA_rMassBurn4_MP = (UInt16)localDivide;
    } else {
      AFA_rMassBurn4_MP = 0U;
    }
  } else {
    AFA_rMassBurn4_MP = MAX_uint16_T;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  localDataTypeConversion5 = ((Float32)(*rtu_AFA_tExMnfEstimF8)) * 0.03125F;

  /* Product: '<S1>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  localDivide = (((Float32)(*rtu_AFA_pDsThrPred_facVlvOvlpFi)) * 8.0F) /
    (((Float32)(*rtu_AFA_pExMnfEstimF8)) * 8.0F);

  /* Outputs for atomic SubSystem: '<S1>/If Action Subsystem3' */

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<S18>/Constant2'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  Saturate: '<S18>/Saturation'
   */
  if (localDivide != localDivide) {
    localDivide = 0.0F;
  } else {
    localDivide = rt_SATURATE(localDivide, -3.000000005E+038F, 3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S1>/If Action Subsystem3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion9' incorporates:
   *  Constant: '<Root>/AirEfc_gmaIvsAir_C'
   */
  localSwitch1_a = (((Float32)AirEfc_gmaIvsAir_C) * 7.629394531E-006F) + 0.5F;

  /* Product: '<Root>/Product5' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Product: '<Root>/Product4'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum2'
   */
  localSwitch1_a = (((1.0F - localSwitch1_a) * localDivide) + localSwitch1_a) *
    localDataTypeConversion5;

  /* Product: '<S6>/Divide' incorporates:
   *  Product: '<Root>/Product2'
   *  Product: '<Root>/Product8'
   *  Sum: '<Root>/Sum'
   */
  localDivide = ((localDataTypeConversion7 * localDataTypeConversion5) +
                 (localLookupTablenD_n * localSwitch1_a)) /
    localDataTypeConversion6;

  /* Outputs for atomic SubSystem: '<S6>/If Action Subsystem3' */

  /* Switch: '<S28>/Switch1' incorporates:
   *  RelationalOperator: '<S28>/Relational Operator'
   *  Saturate: '<S28>/Saturation'
   */
  if (localDivide != localDivide) {
    localDivide = localDataTypeConversion5;
  } else {
    localDivide = rt_SATURATE(localDivide, -3.000000005E+038F, 3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S6>/If Action Subsystem3' */

  /* Sum: '<S9>/Add2' incorporates:
   *  Constant: '<S9>/offset'
   *  Constant: '<S9>/offset1'
   *  Constant: '<S9>/one_on_slope'
   *  Product: '<S9>/Product4'
   *  Sum: '<S9>/Add1'
   */
  localLookupTablenD_n = ((localDivide - 223.0F) * 32.0F) + 0.5F;

  /* DataTypeConversion: '<S9>/OutDTConv' */
  if (localLookupTablenD_n < 65536.0F) {
    if (localLookupTablenD_n >= 0.0F) {
      locallocalOutDTConv = (UInt16)localLookupTablenD_n;
    } else {
      locallocalOutDTConv = 0U;
    }
  } else {
    locallocalOutDTConv = MAX_uint16_T;
  }

  /* DataStoreWrite: '<Root>/Data Store Write5' */
  AFA_tBurnCyl_MP = locallocalOutDTConv;

  /* DataTypeConversion: '<Root>/Data Type Conversion17' */
  localtmp = (UInt32)(locallocalOutDTConv + 7136);
  if (localtmp > 65535U) {
    locallocalDataTypeConversion = MAX_uint16_T;
  } else {
    locallocalDataTypeConversion = (UInt16)localtmp;
  }

  /* Lookup_n-D: '<S8>/Lookup Table (n-D)' */
  localLookupTablenD = look1_iu16lfts16n19If_binlcns(locallocalOutDTConv,
    (&(AFA_tGrdBurnCyl_A[0])), (&(AFA_facTGrdBurnCyl_T[0])), 14U);

  /* Product: '<Root>/Product18' */
  localDataTypeConversion13 *= localSwitch1_a;

  /* DataTypeConversion: '<S14>/OutDTConv' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/offset1'
   *  Constant: '<S14>/one_on_slope'
   *  Lookup_n-D: '<S7>/Lookup Table (n-D)'
   *  Product: '<S14>/Product4'
   *  Sum: '<S14>/Add1'
   *  Sum: '<S14>/Add2'
   */
  localDivide = (6.553600098E+003F * look1_iu16lftu16n13If_binlcns__1
                 (locallocalDataTypeConversion, (&(AirEfc_tBurnCyl_A[0])),
                  (&(AirEfc_facTBurnCyl_T[0])), 15U)) + 0.5F;
  if (localDivide < 65536.0F) {
    if (localDivide >= 0.0F) {
      AFA_facTBurnCyl = (UInt16)localDivide;
    } else {
      AFA_facTBurnCyl = 0U;
    }
  } else {
    AFA_facTBurnCyl = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_facTBurnCyl) = AFA_facTBurnCyl;

  /* Product: '<S15>/Product4' incorporates:
   *  Constant: '<S15>/offset'
   *  Constant: '<S15>/one_on_slope'
   *  Product: '<Root>/Product10'
   *  Product: '<Root>/Product14'
   *  Product: '<Root>/Product15'
   *  Sum: '<Root>/Sum5'
   *  Sum: '<S15>/Add1'
   */
  localDivide = (((localDataTypeConversion5 * localSwitch1_hd) + (localSwitch1_a
    * localSwitch1_ff)) * localLookupTablenD) * 65536.0F;

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/offset2'
   *  Constant: '<S15>/offset3'
   *  Constant: '<S15>/offset4'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  Sum: '<S15>/Add3'
   *  Sum: '<S15>/Add4'
   */
  if (localDivide >= 0.0F) {
    localSwitch1_a = localDivide + 0.5F;
  } else {
    localSwitch1_a = localDivide - 0.5F;
  }

  /* DataTypeConversion: '<S15>/OutDTConv' */
  if (localSwitch1_a < 32768.0F) {
    if (localSwitch1_a >= -32768.0F) {
      AFA_facTBurnGrdCyl_agCkEx = (SInt16)localSwitch1_a;
    } else {
      AFA_facTBurnGrdCyl_agCkEx = MIN_int16_T;
    }
  } else {
    AFA_facTBurnGrdCyl_agCkEx = MAX_int16_T;
  }

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_facTBurnGrdCyl_agCkEx) = AFA_facTBurnGrdCyl_agCkEx;

  /* Product: '<S16>/Product4' incorporates:
   *  Constant: '<S16>/offset'
   *  Constant: '<S16>/one_on_slope'
   *  Product: '<Root>/Product16'
   *  Product: '<Root>/Product19'
   *  Sum: '<Root>/Sum8'
   *  Sum: '<S16>/Add1'
   */
  localDivide = (((localDataTypeConversion5 * localSwitch1_h) +
                  localDataTypeConversion13) * localLookupTablenD) * 65536.0F;

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/offset2'
   *  Constant: '<S16>/offset3'
   *  Constant: '<S16>/offset4'
   *  RelationalOperator: '<S16>/Relational Operator'
   *  Sum: '<S16>/Add3'
   *  Sum: '<S16>/Add4'
   */
  if (localDivide >= 0.0F) {
    localSwitch1_a = localDivide + 0.5F;
  } else {
    localSwitch1_a = localDivide - 0.5F;
  }

  /* DataTypeConversion: '<S16>/OutDTConv' */
  if (localSwitch1_a < 32768.0F) {
    if (localSwitch1_a >= -32768.0F) {
      AFA_facTBurnGrdCyl_agCkIn = (SInt16)localSwitch1_a;
    } else {
      AFA_facTBurnGrdCyl_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_facTBurnGrdCyl_agCkIn = MAX_int16_T;
  }

  /* SignalConversion: '<Root>/Signal3' */
  (*rty_AFA_facTBurnGrdCyl_agCkIn) = AFA_facTBurnGrdCyl_agCkIn;
}

/* Model initialize function */
void mr_AFA_F08_burn_gas__initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
