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
/* !File            : AFA_F01_Calc_Sensitivity_SaintVenant.c                  */
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
/*   Model name       : AFA_F01_Calc_Sensitivity_SaintVenant.mdl              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_Calc_Sensitivity_SaintVenant.h"
#include "AFA_F01_Calc_Sensitivity_SaintVenant_private.h"
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
UInt16 AFA_mfArGrdVlv_rPresInEx;     /* '<Root>/Data Store Memory' */
UInt16 AFA_mfArGrdVlv_rPres_MP[2];   /* '<Root>/Data Store Memory3' */
UInt16 AFA_mfArGrdVlv_rPresExIn;     /* '<Root>/Data Store Memory1' */
UInt16 AFA_mfArThr_rAirPres;         /* '<Root>/Data Store Memory2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Start for referenced model: 'AFA_F01_Calc_Sensitivity_SaintVenant' */
void mr_AFA_F01_Calc_Sensitivi_Start(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  AFA_mfArGrdVlv_rPresExIn = 512U;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  AFA_mfArThr_rAirPres = MAX_uint16_T;

  /* S-Function Block: '<S5>/Data Type Propagation'
   *
   * Regarding '<S5>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S5>/Data Type Conversion'
   *
   * Regarding '<S5>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S1>/Data Type Duplicate1'
   *
   * Regarding '<S1>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* SignalConversion Block: '<Root>/Signal Conversion'
   *
   * Regarding '<Root>/Signal Conversion':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<Root>/Signal Conversion1'
   *
   * Regarding '<Root>/Signal Conversion1':
   *   Eliminate redundant signal conversion block
   */
}

/* Output and update for referenced model: 'AFA_F01_Calc_Sensitivity_SaintVenant' */
void mr_AFA_F01_Calc_Sensitivity_Sai(const UInt16 *rtu_AFA_pDsThrFil, const
  UInt16 *rtu_AFA_pExMnfEstimFil, const UInt16 *rtu_AFA_rAirPresFil,
  UInt16 *rty_AFA_mfArGrdVlv_rPresInEx, UInt16 *rty_AFA_mfArGrdVlv_rPresExIn,
  UInt16 *rty_AFA_mfArThr_rAirPres)
{
  /* local block i/o variables */
  UInt16 localLookUpTable[2];
  UInt16 localSignal4[2];
  UInt16 localLookUpTable_c;
  UInt16 localLookUpTable_i;
  Float32 localDivide;
  Float32 localSwitch1_g;
  UInt16 localSwitch;
  UInt16 locallocalDataTypeConversion;
  UInt16 locallocalDataTypeConversion_0;
  Float32d localtmp;

  /* Product: '<S4>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversin'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  localDivide = (((Float32)(*rtu_AFA_pDsThrFil)) * 8.0F) / (((Float32)
    (*rtu_AFA_pExMnfEstimFil)) * 8.0F);

  /* Outputs for atomic SubSystem: '<S4>/If Action Subsystem3' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant2'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  Saturate: '<S8>/Saturation'
   */
  if (localDivide != localDivide) {
    localSwitch1_g = 0.0F;
  } else {
    localSwitch1_g = rt_SATURATE(localDivide, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S4>/If Action Subsystem3' */

  /* Product: '<S5>/Divide' incorporates:
   *  Constant: '<Root>/Ratio_Critique3'
   */
  localDivide = 1.0F / localSwitch1_g;

  /* Outputs for atomic SubSystem: '<S5>/If Action Subsystem3' */

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant2'
   *  RelationalOperator: '<S10>/Relational Operator'
   *  Saturate: '<S10>/Saturation'
   */
  if (localDivide != localDivide) {
    localDivide = 0.0F;
  } else {
    localDivide = rt_SATURATE(localDivide, -3.000000005E+038F, 3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S5>/If Action Subsystem3' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  localtmp = ACTEMS_LdexpF((Float32d)localSwitch1_g, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localSwitch = (UInt16)localtmp;
    } else {
      localSwitch = 0U;
    }
  } else {
    localSwitch = MAX_uint16_T;
  }

  localSignal4[0] = localSwitch;
  localtmp = ACTEMS_LdexpF((Float32d)localDivide, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localSwitch = (UInt16)localtmp;
    } else {
      localSwitch = 0U;
    }
  } else {
    localSwitch = MAX_uint16_T;
  }

  localSignal4[1] = localSwitch;

  /* Lookup: '<S1>/Look-Up Table'
   * About '<S1>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-9  Bias -1.2799804687500000E+002
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable[0]), (&(AFA_mfArGrdVlv_rPres_T[0])),
                 localSignal4[0], (&(Air_rAirPres_A[0])), 21U);
  LookUp_U16_U16( &(localLookUpTable[1]), (&(AFA_mfArGrdVlv_rPres_T[0])),
                 localSignal4[1], (&(Air_rAirPres_A[0])), 21U);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Ratio_Critique1'
   *  Constant: '<Root>/Ratio_Critique6'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  if (localSwitch1_g > 1.0F) {
    localSwitch = MAX_uint16_T;
  } else {
    localSwitch = localLookUpTable[0];
  }

  /* DataStoreWrite: '<Root>/Data Store Write' */
  AFA_mfArGrdVlv_rPresInEx = localSwitch;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Ratio_Critique2'
   *  Constant: '<Root>/Ratio_Critique4'
   *  Constant: '<Root>/Ratio_Critique5'
   *  RelationalOperator: '<Root>/Relational Operator3'
   *  Sum: '<Root>/Sum'
   */
  if (localDivide >= 1.0F) {
    localDivide = 0.0F;
  } else {
    localDivide = 1.289980469E+002F - (((Float32)localLookUpTable[1]) *
      0.001953125F);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion7' */
  localtmp = ACTEMS_LdexpF((Float32d)localDivide, 9);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalDataTypeConversion = (UInt16)localtmp;
    } else {
      locallocalDataTypeConversion = 0U;
    }
  } else {
    locallocalDataTypeConversion = MAX_uint16_T;
  }

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  AFA_mfArGrdVlv_rPresExIn = locallocalDataTypeConversion;

  /* SignalConversion: '<Root>/Signal4' */
  localSignal4[0] = localLookUpTable[0];

  /* DataStoreWrite: '<Root>/Data Store Write3' */
  AFA_mfArGrdVlv_rPres_MP[0] = localSignal4[0];

  /* SignalConversion: '<Root>/Signal4' */
  localSignal4[1] = localLookUpTable[1];

  /* DataStoreWrite: '<Root>/Data Store Write3' */
  AFA_mfArGrdVlv_rPres_MP[1] = localSignal4[1];

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Ratio_Critique7'
   *  Constant: '<Root>/Ratio_Critique8'
   *  RelationalOperator: '<Root>/Relational Operator5'
   */

  /* Lookup: '<S3>/Look-Up Table'
   * About '<S3>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-20
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_i), (&(InM_facCfeThr_T[0])),
                 (*rtu_AFA_rAirPresFil), (&(Air_rAirPres_A[0])), 21U);

  /* DataTypeDuplicate Block: '<S3>/Data Type Duplicate1'
   *
   * Regarding '<S3>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/AFA_rAirPresFil'
   *  Lookup: '<S3>/Look-Up Table'
   */
  localDivide = ((Float32)localLookUpTable_i) * 9.536743164E-007F;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  localSwitch1_g = ((Float32)(*rtu_AFA_rAirPresFil)) * 1.525878906E-005F;

  /* Lookup: '<S2>/Look-Up Table'
   * About '<S2>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-11  Bias -3.1999511718750000E+001
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_c), (&(InM_facCfeGradThr_T[0])),
                 (*rtu_AFA_rAirPresFil), (&(Air_rAirPres_A[0])), 21U);

  /* DataTypeDuplicate Block: '<S2>/Data Type Duplicate1'
   *
   * Regarding '<S2>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Product: '<S6>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  Inport: '<Root>/AFA_rAirPresFil'
   *  Lookup: '<S2>/Look-Up Table'
   *  Product: '<Root>/Product'
   */
  localDivide = (((((Float32)localLookUpTable_c) * 0.00048828125F) -
                  3.199951172E+001F) * localSwitch1_g) / localDivide;

  /* Outputs for atomic SubSystem: '<S6>/If Action Subsystem3' */

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant2'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  Saturate: '<S12>/Saturation'
   */
  if (localDivide != localDivide) {
    localDivide = 0.0F;
  } else {
    localDivide = rt_SATURATE(localDivide, -3.000000005E+038F, 3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S6>/If Action Subsystem3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  localtmp = ACTEMS_LdexpF(((Float32d)localDivide) + 511.9921875F, 7);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalDataTypeConversion_0 = (UInt16)localtmp;
    } else {
      locallocalDataTypeConversion_0 = 0U;
    }
  } else {
    locallocalDataTypeConversion_0 = MAX_uint16_T;
  }

  /* DataStoreWrite: '<Root>/Data Store Write2' */
  AFA_mfArThr_rAirPres = locallocalDataTypeConversion_0;

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_mfArGrdVlv_rPresInEx) = localSwitch;

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_mfArGrdVlv_rPresExIn) = locallocalDataTypeConversion;

  /* SignalConversion: '<Root>/Signal3' */
  (*rty_AFA_mfArThr_rAirPres) = locallocalDataTypeConversion_0;
}

/* Model initialize function */
void mr_AFA_F01_Calc_Sens_initialize(void)
{
  /* Registration code */

  /* states (dwork) */

  /* exported global states */
  AFA_mfArGrdVlv_rPresInEx = 65535U;
  AFA_mfArGrdVlv_rPres_MP[0] = 65535U;
  AFA_mfArGrdVlv_rPres_MP[1] = 65535U;
  AFA_mfArThr_rAirPres = 65535U;
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
