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
/* !File            : AFA_F04_Calc_Sensitivity_Pap.c                          */
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
/*   Model name       : AFA_F04_Calc_Sensitivity_Pap.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F04_Calc_Sensitivity_Pap.h"
#include "AFA_F04_Calc_Sensitivity_Pap_private.h"
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
UInt16 AFA_pGrdDsThr_facArEffThrOfs3;/* '<S6>/OutDTConv' */
UInt16 AFA_pGrdDsThr_facArEffThrOfs2;/* '<S5>/OutDTConv' */
UInt16 AFA_pGrdDsThr_facArEffThrOfs1;/* '<S4>/OutDTConv' */
UInt16 AFA_pGrdDsThr_arEffThr;       /* '<S11>/OutDTConv' */
UInt16 AFA_rlamGrd_facArEffThrOfs1;  /* '<S7>/OutDTConv' */
UInt16 AFA_rlamGrd_facArEffThrOfs3;  /* '<S9>/OutDTConv' */
UInt16 AFA_rlamGrd_facArEffThrOfs2;  /* '<S8>/OutDTConv' */
UInt16 AFA_rlamGrd_arEffThr;         /* '<S10>/OutDTConv' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F04_Calc_Sensitivity_Pap' */
void mr_AFA_F04_Calc_Sensitivity_Pap(const UInt16 *rtu_AFA_mfArThr_rAirPres,
  const UInt16 *rtu_AFA_pDsThrFi4, const UInt16 *rtu_AFA_arEffAdpThrFil,
  const UInt16 *rtu_AFA_rInMassFlowFil, const UInt16 *rtu_AFA_rOpSIFil,
  const UInt32 *rtu_AFA_rTotLdGrd_pDsThr, UInt16 *rty_AFA_pGrdDsThr_arEffThr,
  UInt16 *rty_AFA_pGrdDsThr_facArEffThrOf, UInt16
  *rty_AFA_pGrdDsThr_facArEffThr_c, UInt16 *rty_AFA_pGrdDsThr_facArEffThr_a,
  UInt16 *rty_AFA_rlamGrd_arEffThr, UInt16 *rty_AFA_rlamGrd_facArEffThrOfs1,
  UInt16 *rty_AFA_rlamGrd_facArEffThrOfs2, UInt16
  *rty_AFA_rlamGrd_facArEffThrOfs3)
{
  UInt16 localrtmin;
  Float32 localDataTypeConversion4;
  Float32 localMinMax1;
  Float32 localDivide3;
  Float32 localDivide;
  Float32 localSwitch1_o;
  Float32 localSwitch1;

  /* MinMax: '<Root>/MinMax' incorporates:
   *  Constant: '<Root>/AFA_rOpThrMax_C'
   */
  localrtmin = (*rtu_AFA_rOpSIFil);
  if (AFA_rOpThrMax_C < (*rtu_AFA_rOpSIFil)) {
    localrtmin = AFA_rOpThrMax_C;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  localDataTypeConversion4 = ((Float32)localrtmin) * 0.0009765625F;

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  localMinMax1 = ((Float32)(*rtu_AFA_rInMassFlowFil)) * 1.525878906E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  localDivide3 = ((Float32)(*rtu_AFA_arEffAdpThrFil)) * 5.960464478E-008F;

  /* Product: '<S2>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  localDivide = (((Float32)(*rtu_AFA_pDsThrFi4)) * 8.0F) / localDivide3;

  /* Outputs for atomic SubSystem: '<S2>/If Action Subsystem3' */

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant2'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  Saturate: '<S15>/Saturation'
   */
  if (localDivide != localDivide) {
    localDivide = 0.0F;
  } else {
    localDivide = rt_SATURATE(localDivide, -3.000000005E+038F, 3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S2>/If Action Subsystem3' */

  /* Product: '<S1>/Divide' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   *  Sum: '<Root>/Subtract1'
   */
  localDivide /= (((Float32)(*rtu_AFA_rTotLdGrd_pDsThr)) * 2.328306437E-004F) -
    ((((Float32)(*rtu_AFA_mfArThr_rAirPres)) * 0.0078125F) - 511.9921875F);

  /* Outputs for atomic SubSystem: '<S1>/If Action Subsystem3' */

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/Constant2'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  Saturate: '<S13>/Saturation'
   */
  if (localDivide != localDivide) {
    localSwitch1_o = 0.0F;
  } else {
    localSwitch1_o = rt_SATURATE(localDivide, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S1>/If Action Subsystem3' */

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Product: '<Root>/Divide1'
   *  Sum: '<Root>/Subtract2'
   */
  localDivide = (localMinMax1 / (localMinMax1 + 1.0F)) / localDivide3;

  /* Outputs for atomic SubSystem: '<S3>/If Action Subsystem3' */

  /* Switch: '<S17>/Switch1' incorporates:
   *  Constant: '<S17>/Constant2'
   *  RelationalOperator: '<S17>/Relational Operator'
   *  Saturate: '<S17>/Saturation'
   */
  if (localDivide != localDivide) {
    localSwitch1 = 0.0F;
  } else {
    localSwitch1 = rt_SATURATE(localDivide, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S3>/If Action Subsystem3' */

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Sum: '<Root>/Subtract3'
   */
  localDivide3 = localSwitch1_o / (localMinMax1 + 1.0F);

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/AFA_rOpThrRef2_C'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  localMinMax1 = localDataTypeConversion4 - (((Float32)AFA_rOpThrRef2_C) *
    0.0009765625F);

  /* MinMax: '<Root>/MinMax1' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  localSwitch1_o = rt_MAXf(0.0F, localMinMax1);

  /* Sum: '<Root>/Subtract4' incorporates:
   *  Constant: '<Root>/AFA_rOpThrRef3_C'
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   */
  localDivide = localDataTypeConversion4 - (((Float32)AFA_rOpThrRef3_C) *
    0.0009765625F);

  /* MinMax: '<Root>/MinMax2' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  localDivide = rt_MAXf(0.0F, localDivide);

  /* DataTypeConversion: '<S7>/OutDTConv' incorporates:
   *  Constant: '<S7>/offset'
   *  Constant: '<S7>/offset1'
   *  Constant: '<S7>/one_on_slope'
   *  Product: '<Root>/Product3'
   *  Product: '<S7>/Product4'
   *  Sum: '<S7>/Add1'
   *  Sum: '<S7>/Add2'
   */
  localMinMax1 = ((localDataTypeConversion4 * localSwitch1) * 6.553599834E-001F)
    + 0.5F;
  if (localMinMax1 < 65536.0F) {
    if (localMinMax1 >= 0.0F) {
      AFA_rlamGrd_facArEffThrOfs1 = (UInt16)localMinMax1;
    } else {
      AFA_rlamGrd_facArEffThrOfs1 = 0U;
    }
  } else {
    AFA_rlamGrd_facArEffThrOfs1 = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_rlamGrd_facArEffThrOfs1) = AFA_rlamGrd_facArEffThrOfs1;

  /* DataTypeConversion: '<S9>/OutDTConv' incorporates:
   *  Constant: '<S9>/offset'
   *  Constant: '<S9>/offset1'
   *  Constant: '<S9>/one_on_slope'
   *  Product: '<Root>/Product5'
   *  Product: '<S9>/Product4'
   *  Sum: '<S9>/Add1'
   *  Sum: '<S9>/Add2'
   */
  localMinMax1 = ((localDivide * localSwitch1) * 6.553599834E-001F) + 0.5F;
  if (localMinMax1 < 65536.0F) {
    if (localMinMax1 >= 0.0F) {
      AFA_rlamGrd_facArEffThrOfs3 = (UInt16)localMinMax1;
    } else {
      AFA_rlamGrd_facArEffThrOfs3 = 0U;
    }
  } else {
    AFA_rlamGrd_facArEffThrOfs3 = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_rlamGrd_facArEffThrOfs3) = AFA_rlamGrd_facArEffThrOfs3;

  /* DataTypeConversion: '<S8>/OutDTConv' incorporates:
   *  Constant: '<S8>/offset'
   *  Constant: '<S8>/offset1'
   *  Constant: '<S8>/one_on_slope'
   *  Product: '<Root>/Product4'
   *  Product: '<S8>/Product4'
   *  Sum: '<S8>/Add1'
   *  Sum: '<S8>/Add2'
   */
  localMinMax1 = ((localSwitch1_o * localSwitch1) * 6.553599834E-001F) + 0.5F;
  if (localMinMax1 < 65536.0F) {
    if (localMinMax1 >= 0.0F) {
      AFA_rlamGrd_facArEffThrOfs2 = (UInt16)localMinMax1;
    } else {
      AFA_rlamGrd_facArEffThrOfs2 = 0U;
    }
  } else {
    AFA_rlamGrd_facArEffThrOfs2 = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal3' */
  (*rty_AFA_rlamGrd_facArEffThrOfs2) = AFA_rlamGrd_facArEffThrOfs2;

  /* DataTypeConversion: '<S6>/OutDTConv' incorporates:
   *  Constant: '<S6>/offset'
   *  Constant: '<S6>/offset1'
   *  Constant: '<S6>/one_on_slope'
   *  Product: '<Root>/Product2'
   *  Product: '<S6>/Product4'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S6>/Add2'
   */
  localMinMax1 = ((localDivide3 * localDivide) * 6.553600087E-006F) + 0.5F;
  if (localMinMax1 < 65536.0F) {
    if (localMinMax1 >= 0.0F) {
      AFA_pGrdDsThr_facArEffThrOfs3 = (UInt16)localMinMax1;
    } else {
      AFA_pGrdDsThr_facArEffThrOfs3 = 0U;
    }
  } else {
    AFA_pGrdDsThr_facArEffThrOfs3 = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal4' */
  (*rty_AFA_pGrdDsThr_facArEffThr_a) = AFA_pGrdDsThr_facArEffThrOfs3;

  /* DataTypeConversion: '<S5>/OutDTConv' incorporates:
   *  Constant: '<S5>/offset'
   *  Constant: '<S5>/offset1'
   *  Constant: '<S5>/one_on_slope'
   *  Product: '<Root>/Product1'
   *  Product: '<S5>/Product4'
   *  Sum: '<S5>/Add1'
   *  Sum: '<S5>/Add2'
   */
  localMinMax1 = ((localDivide3 * localSwitch1_o) * 6.553600087E-006F) + 0.5F;
  if (localMinMax1 < 65536.0F) {
    if (localMinMax1 >= 0.0F) {
      AFA_pGrdDsThr_facArEffThrOfs2 = (UInt16)localMinMax1;
    } else {
      AFA_pGrdDsThr_facArEffThrOfs2 = 0U;
    }
  } else {
    AFA_pGrdDsThr_facArEffThrOfs2 = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal5' */
  (*rty_AFA_pGrdDsThr_facArEffThr_c) = AFA_pGrdDsThr_facArEffThrOfs2;

  /* DataTypeConversion: '<S4>/OutDTConv' incorporates:
   *  Constant: '<S4>/offset'
   *  Constant: '<S4>/offset1'
   *  Constant: '<S4>/one_on_slope'
   *  Product: '<Root>/Product'
   *  Product: '<S4>/Product4'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add2'
   */
  localMinMax1 = ((localDivide3 * localDataTypeConversion4) * 6.553600087E-006F)
    + 0.5F;
  if (localMinMax1 < 65536.0F) {
    if (localMinMax1 >= 0.0F) {
      AFA_pGrdDsThr_facArEffThrOfs1 = (UInt16)localMinMax1;
    } else {
      AFA_pGrdDsThr_facArEffThrOfs1 = 0U;
    }
  } else {
    AFA_pGrdDsThr_facArEffThrOfs1 = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal6' */
  (*rty_AFA_pGrdDsThr_facArEffThrOf) = AFA_pGrdDsThr_facArEffThrOfs1;

  /* DataTypeConversion: '<S10>/OutDTConv' incorporates:
   *  Constant: '<S10>/offset'
   *  Constant: '<S10>/offset1'
   *  Constant: '<S10>/one_on_slope'
   *  Product: '<S10>/Product4'
   *  Sum: '<S10>/Add1'
   *  Sum: '<S10>/Add2'
   */
  localMinMax1 = (6.553599834E-001F * localSwitch1) + 0.5F;
  if (localMinMax1 < 65536.0F) {
    if (localMinMax1 >= 0.0F) {
      AFA_rlamGrd_arEffThr = (UInt16)localMinMax1;
    } else {
      AFA_rlamGrd_arEffThr = 0U;
    }
  } else {
    AFA_rlamGrd_arEffThr = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal7' */
  (*rty_AFA_rlamGrd_arEffThr) = AFA_rlamGrd_arEffThr;

  /* DataTypeConversion: '<S11>/OutDTConv' incorporates:
   *  Constant: '<S11>/offset'
   *  Constant: '<S11>/offset1'
   *  Constant: '<S11>/one_on_slope'
   *  Product: '<S11>/Product4'
   *  Sum: '<S11>/Add1'
   *  Sum: '<S11>/Add2'
   */
  localMinMax1 = (6.553600087E-006F * localDivide3) + 0.5F;
  if (localMinMax1 < 65536.0F) {
    if (localMinMax1 >= 0.0F) {
      AFA_pGrdDsThr_arEffThr = (UInt16)localMinMax1;
    } else {
      AFA_pGrdDsThr_arEffThr = 0U;
    }
  } else {
    AFA_pGrdDsThr_arEffThr = MAX_uint16_T;
  }

  /* SignalConversion: '<Root>/Signal8' */
  (*rty_AFA_pGrdDsThr_arEffThr) = AFA_pGrdDsThr_arEffThr;
}

/* Model initialize function */
void mr_AFA_F04_Calc_Sens_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
