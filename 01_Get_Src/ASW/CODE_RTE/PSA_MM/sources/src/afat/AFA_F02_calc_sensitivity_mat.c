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
/* !File            : AFA_F02_calc_sensitivity_mat.c                          */
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
/*   Model name       : AFA_F02_calc_sensitivity_mat.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F02_calc_sensitivity_mat.h"
#include "AFA_F02_calc_sensitivity_mat_private.h"
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


/* Exported block states */
SInt32 AFA_prm_facSenTransMat1_MP[2]; /* '<Root>/Data Store Memory1' */
SInt32 AFA_prm_facSenTransMat2_MP[2]; /* '<Root>/Data Store Memory2' */
SInt32 AFA_prm_facSenTransMat3_MP[2]; /* '<Root>/Data Store Memory3' */
SInt32 AFA_prm_facSenTransMat4_MP[2]; /* '<Root>/Data Store Memory4' */
SInt32 AFA_prm_facSenTransMat5_MP[2]; /* '<Root>/Data Store Memory5' */
SInt32 AFA_prm_facSenTransMat6_MP[2]; /* '<Root>/Data Store Memory6' */
SInt32 AFA_prm_facSenTransMat7_MP[2]; /* '<Root>/Data Store Memory7' */
SInt32 AFA_prm_facSenTransMat8_MP[2]; /* '<Root>/Data Store Memory8' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Start for referenced model: 'AFA_F02_calc_sensitivity_mat' */
void mr_AFA_F02_calc_sensitivi_Start(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  AFA_prm_facSenTransMat1_MP[0] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  AFA_prm_facSenTransMat2_MP[0] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  AFA_prm_facSenTransMat3_MP[0] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  AFA_prm_facSenTransMat4_MP[0] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  AFA_prm_facSenTransMat5_MP[0] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  AFA_prm_facSenTransMat6_MP[0] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  AFA_prm_facSenTransMat7_MP[0] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  AFA_prm_facSenTransMat8_MP[0] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  AFA_prm_facSenTransMat1_MP[1] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  AFA_prm_facSenTransMat2_MP[1] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  AFA_prm_facSenTransMat3_MP[1] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  AFA_prm_facSenTransMat4_MP[1] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  AFA_prm_facSenTransMat5_MP[1] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  AFA_prm_facSenTransMat6_MP[1] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  AFA_prm_facSenTransMat7_MP[1] = -32768;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  AFA_prm_facSenTransMat8_MP[1] = -32768;
}

/* Output and update for referenced model: 'AFA_F02_calc_sensitivity_mat' */
void mr_AFA_F02_calc_sensitivity_mat(const Boolean
  rtu_AFA_prm_bMaskSenMat_PIM[16], const UInt16 *rtu_AFA_pGrdDsThr_arEffThr,
  const UInt16 *rtu_AFA_pGrdDsThr_facArEffThrOf, const UInt16
  *rtu_AFA_pGrdDsThr_facArEffThr_p, const UInt16
  *rtu_AFA_pGrdDsThr_facArEffThr_d, const UInt16 *rtu_AFA_rlamGrd_arEffThr,
  const UInt16 *rtu_AFA_rlamGrd_facArEffThrOfs1, const UInt16
  *rtu_AFA_rlamGrd_facArEffThrOfs2, const UInt16
  *rtu_AFA_rlamGrd_facArEffThrOfs3, const UInt16 *rtu_AFA_rlamGrd_arEffEGRVlv,
  const UInt16 *rtu_AFA_pGrdDsThr_arEffEGRVlv, const UInt16
  *rtu_AFA_rlamGrd_tiOffInj, const UInt16 *rtu_AFA_rlamGrd_facIvsInjGain,
  const UInt32 *rtu_AFA_rlamGrd_facSlopInjGain, const SInt16
  *rtu_AFA_rlamGrd_agCkEx, const SInt16 *rtu_AFA_pGrdDsThr_agCkEx, const
  SInt16 *rtu_AFA_pGrdDsThr_agCkIn, const SInt16 *rtu_AFA_rlamGrd_agCkIn,
  SInt32 rty_AFA_prm_facSenTransMat_PIM[16])
{
  Float32 localDataTypeConversion;
  Float32 localDataTypeConversion1;
  Float32 localDataTypeConversion12;
  Float32 localDataTypeConversion6;
  Float32 localDataTypeConversion13;
  Float32 localProduct28;
  Float32 locallocalMatrixConcatenation[16];
  Float32 locallocalSwitch1_m;
  Float32 locallocalMatrixConcatenation1_;
  Float32 locallocalMatrixConcatenation3_;
  Float32 locallocalMatrixConcatenation_0;
  Float32 locallocalMatrixConcatenation4_;
  Float32 locallocalMatrixConcatenation_1;
  Float32 locallocalMatrixConcatenation5_;
  Float32 locallocalMatrixConcatenation_2;
  Float32 locallocalMatrixConcatenation6_;
  Float32 locallocalMatrixConcatenation_3;
  Float32 locallocalMatrixConcatenation_i;
  Float32 locallocalMatrixConcatenation_4;
  Float32 locallocalMatrixConcatenation2_;
  SInt32 localtmp;
  SInt32 localtmp_0;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/AFA_facPresDsThrErrRef_C'
   */
  localDataTypeConversion = ((Float32)AFA_facPresDsThrErrRef_C) *
    6.103515625E-005F;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/AFA_agCkVlvInRef_C'
   */
  localDataTypeConversion1 = ((Float32)AFA_agCkVlvInRef_C) * 0.09375F;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/AFA_bAcvVVTAdp_C1'
   *  Constant: '<Root>/Constant15'
   *  DataTypeConversion: '<Root>/Data Type Conversion21'
   *  Product: '<Root>/Product10'
   *  Product: '<Root>/Product11'
   */
  if (AFA_bAcvVVTAdp_C) {
    locallocalMatrixConcatenation_i = (localDataTypeConversion *
      localDataTypeConversion1) * (((Float32)(*rtu_AFA_pGrdDsThr_agCkIn)) *
      0.0625F);
  } else {
    locallocalMatrixConcatenation_i = 0.0F;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Constant: '<Root>/AFA_facLamErrRef_C'
   */
  localDataTypeConversion12 = ((Float32)AFA_facLamErrRef_C) * 0.015625F;

  /* DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
   *  Constant: '<Root>/AFA_facIvsInjGainRef_C'
   */
  localDataTypeConversion6 = ((Float32)AFA_facIvsInjGainRef_C) * 0.015625F;

  /* DataTypeConversion: '<Root>/Data Type Conversion13' */
  localDataTypeConversion13 = ((Float32)(*rtu_AFA_rlamGrd_facIvsInjGain)) *
    1.525878929E-006F;

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/AFA_bAcvVVTAdp_C3'
   *  DataTypeConversion: '<Root>/Data Type Conversion22'
   *  Product: '<Root>/Product12'
   *  Product: '<Root>/Product13'
   *  Product: '<Root>/Product30'
   *  Product: '<Root>/Product31'
   */
  if (AFA_bAcvVVTAdp_C) {
    locallocalMatrixConcatenation_4 = (localDataTypeConversion12 *
      localDataTypeConversion1) * (((Float32)(*rtu_AFA_rlamGrd_agCkIn)) *
      3.051757858E-006F);
  } else {
    locallocalMatrixConcatenation_4 = (localDataTypeConversion12 *
      localDataTypeConversion6) * localDataTypeConversion13;
  }

  /* Product: '<Root>/Product29' incorporates:
   *  Constant: '<Root>/AFA_tiOffInjRef_C'
   *  DataTypeConversion: '<Root>/Data Type Conversion14'
   *  DataTypeConversion: '<Root>/Data Type Conversion23'
   *  Product: '<Root>/Product14'
   */
  locallocalMatrixConcatenation1_ = ((((Float32)AFA_tiOffInjRef_C) *
    3.200000037E-006F) * localDataTypeConversion12) * (((Float32)
    (*rtu_AFA_rlamGrd_tiOffInj)) * 0.03125F);

  /* Product: '<S8>/Product4' incorporates:
   *  Constant: '<S8>/offset'
   *  Constant: '<S8>/one_on_slope'
   *  Sum: '<S8>/Add1'
   */
  locallocalSwitch1_m = 1024.0F * locallocalMatrixConcatenation_i;

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/offset2'
   *  Constant: '<S8>/offset3'
   *  Constant: '<S8>/offset4'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  Sum: '<S8>/Add3'
   *  Sum: '<S8>/Add4'
   */
  if (locallocalSwitch1_m >= 0.0F) {
    locallocalSwitch1_m += 0.5F;
  } else {
    locallocalSwitch1_m -= 0.5F;
  }

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S8>/OutDTConv'
   */
  AFA_prm_facSenTransMat1_MP[0] = (SInt32)locallocalSwitch1_m;

  /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<S7>/OutDTConv'
   */
  AFA_prm_facSenTransMat2_MP[0] = 0;

  /* Product: '<S8>/Product4' incorporates:
   *  Constant: '<S8>/offset'
   *  Constant: '<S8>/one_on_slope'
   *  Sum: '<S8>/Add1'
   */
  locallocalSwitch1_m = 1024.0F * locallocalMatrixConcatenation_4;

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/offset2'
   *  Constant: '<S8>/offset3'
   *  Constant: '<S8>/offset4'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  Sum: '<S8>/Add3'
   *  Sum: '<S8>/Add4'
   */
  if (locallocalSwitch1_m >= 0.0F) {
    locallocalSwitch1_m += 0.5F;
  } else {
    locallocalSwitch1_m -= 0.5F;
  }

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S8>/OutDTConv'
   */
  AFA_prm_facSenTransMat1_MP[1] = (SInt32)locallocalSwitch1_m;

  /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
   *  Constant: '<S7>/offset'
   *  Constant: '<S7>/offset2'
   *  Constant: '<S7>/offset3'
   *  Constant: '<S7>/offset4'
   *  Constant: '<S7>/one_on_slope'
   *  DataTypeConversion: '<S7>/OutDTConv'
   *  Product: '<S7>/Product4'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  Sum: '<S7>/Add1'
   *  Sum: '<S7>/Add3'
   *  Sum: '<S7>/Add4'
   *  Switch: '<S7>/Switch1'
   */
  AFA_prm_facSenTransMat2_MP[1] = (SInt32)((1024.0F *
    locallocalMatrixConcatenation1_) + 0.5F);

  /* Product: '<Root>/Product28' incorporates:
   *  Product: '<Root>/Product15'
   */
  localProduct28 = (localDataTypeConversion13 * localDataTypeConversion6) *
    localDataTypeConversion12;

  /* Switch: '<Root>/Switch18' incorporates:
   *  Constant: '<Root>/AFA_bAcvVVTAdp_C2'
   *  Constant: '<Root>/AFA_bSelAdpTyp_C'
   *  Constant: '<Root>/AFA_facSlopInjGainRef_C'
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   *  Logic: '<Root>/Logical Operator25'
   *  Product: '<Root>/Product35'
   *  Product: '<Root>/Product36'
   */
  if (AFA_bSelAdpTyp_C && AFA_bAcvVVTAdp_C) {
    locallocalMatrixConcatenation2_ = localProduct28;
  } else {
    locallocalMatrixConcatenation2_ = ((((Float32)AFA_facSlopInjGainRef_C) *
      3.255208325E-010F) * localDataTypeConversion12) * (((Float32)
      (*rtu_AFA_rlamGrd_facSlopInjGain)) * 0.015625F);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Constant: '<Root>/AFA_arEffThrOfsRef_C'
   */
  localDataTypeConversion1 = ((Float32)AFA_arEffThrOfsRef_C) *
    5.960464478E-008F;

  /* Product: '<Root>/Product8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion20'
   *  Product: '<Root>/Product9'
   */
  locallocalMatrixConcatenation3_ = (localDataTypeConversion *
    localDataTypeConversion1) * (((Float32)(*rtu_AFA_pGrdDsThr_arEffThr)) *
    1.525878906E+005F);

  /* Product: '<Root>/Product27' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion24'
   *  Product: '<Root>/Product16'
   */
  locallocalMatrixConcatenation_0 = (localDataTypeConversion12 *
    localDataTypeConversion1) * (((Float32)(*rtu_AFA_rlamGrd_arEffThr)) *
    1.525878906E+000F);

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs1Ref_C'
   */
  localDataTypeConversion1 = ((Float32)AFA_facArEffThrOfs1Ref_C) *
    3.814697266E-006F;

  /* Product: '<Root>/Product33' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion19'
   *  Product: '<Root>/Product32'
   */
  locallocalMatrixConcatenation4_ = (localDataTypeConversion *
    localDataTypeConversion1) * (((Float32)(*rtu_AFA_pGrdDsThr_facArEffThrOf)) *
    1.525878906E+005F);

  /* Product: '<Root>/Product26' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion25'
   *  Product: '<Root>/Product17'
   */
  locallocalMatrixConcatenation_1 = (localDataTypeConversion12 *
    localDataTypeConversion1) * (((Float32)(*rtu_AFA_rlamGrd_facArEffThrOfs1)) *
    1.525878906E+000F);

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs2Ref_C'
   */
  localDataTypeConversion1 = ((Float32)AFA_facArEffThrOfs2Ref_C) *
    3.814697266E-006F;

  /* Product: '<Root>/Product6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion18'
   *  Product: '<Root>/Product7'
   */
  locallocalMatrixConcatenation5_ = (localDataTypeConversion *
    localDataTypeConversion1) * (((Float32)(*rtu_AFA_pGrdDsThr_facArEffThr_p)) *
    1.525878906E+005F);

  /* Product: '<Root>/Product25' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion26'
   *  Product: '<Root>/Product18'
   */
  locallocalMatrixConcatenation_2 = (localDataTypeConversion12 *
    localDataTypeConversion1) * (((Float32)(*rtu_AFA_rlamGrd_facArEffThrOfs2)) *
    1.525878906E+000F);

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs3Ref_C'
   */
  localDataTypeConversion1 = ((Float32)AFA_facArEffThrOfs3Ref_C) *
    3.814697266E-006F;

  /* Product: '<Root>/Product5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion17'
   *  Product: '<Root>/Product4'
   */
  locallocalMatrixConcatenation6_ = (localDataTypeConversion *
    localDataTypeConversion1) * (((Float32)(*rtu_AFA_pGrdDsThr_facArEffThr_d)) *
    1.525878906E+005F);

  /* Product: '<Root>/Product24' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion27'
   *  Product: '<Root>/Product19'
   */
  locallocalMatrixConcatenation_3 = (localDataTypeConversion12 *
    localDataTypeConversion1) * (((Float32)(*rtu_AFA_rlamGrd_facArEffThrOfs3)) *
    1.525878906E+000F);

  /* DataStoreWrite: '<Root>/Data Store Write3' incorporates:
   *  DataTypeConversion: '<S6>/OutDTConv'
   */
  AFA_prm_facSenTransMat3_MP[0] = 0;

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/offset'
   *  Constant: '<S5>/offset2'
   *  Constant: '<S5>/offset3'
   *  Constant: '<S5>/offset4'
   *  Constant: '<S5>/one_on_slope'
   *  Product: '<S5>/Product4'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  Sum: '<S5>/Add1'
   *  Sum: '<S5>/Add3'
   *  Sum: '<S5>/Add4'
   */
  locallocalSwitch1_m = (1024.0F * locallocalMatrixConcatenation3_) + 0.5F;

  /* DataStoreWrite: '<Root>/Data Store Write4' incorporates:
   *  DataTypeConversion: '<S5>/OutDTConv'
   */
  if (locallocalSwitch1_m < 2.147483648E+009F) {
    localtmp_0 = (SInt32)locallocalSwitch1_m;
  } else {
    localtmp_0 = MAX_int32_T;
  }

  AFA_prm_facSenTransMat4_MP[0] = localtmp_0;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/offset'
   *  Constant: '<S4>/offset2'
   *  Constant: '<S4>/offset3'
   *  Constant: '<S4>/offset4'
   *  Constant: '<S4>/one_on_slope'
   *  Product: '<S4>/Product4'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add3'
   *  Sum: '<S4>/Add4'
   */
  locallocalSwitch1_m = (1024.0F * locallocalMatrixConcatenation4_) + 0.5F;

  /* DataStoreWrite: '<Root>/Data Store Write5' incorporates:
   *  DataTypeConversion: '<S4>/OutDTConv'
   */
  if (locallocalSwitch1_m < 2.147483648E+009F) {
    localtmp_0 = (SInt32)locallocalSwitch1_m;
  } else {
    localtmp_0 = MAX_int32_T;
  }

  AFA_prm_facSenTransMat5_MP[0] = localtmp_0;

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/offset'
   *  Constant: '<S3>/offset2'
   *  Constant: '<S3>/offset3'
   *  Constant: '<S3>/offset4'
   *  Constant: '<S3>/one_on_slope'
   *  Product: '<S3>/Product4'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  Sum: '<S3>/Add1'
   *  Sum: '<S3>/Add3'
   *  Sum: '<S3>/Add4'
   */
  locallocalSwitch1_m = (1024.0F * locallocalMatrixConcatenation5_) + 0.5F;

  /* DataStoreWrite: '<Root>/Data Store Write6' incorporates:
   *  DataTypeConversion: '<S3>/OutDTConv'
   */
  if (locallocalSwitch1_m < 2.147483648E+009F) {
    localtmp_0 = (SInt32)locallocalSwitch1_m;
  } else {
    localtmp_0 = MAX_int32_T;
  }

  AFA_prm_facSenTransMat6_MP[0] = localtmp_0;

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/offset'
   *  Constant: '<S2>/offset2'
   *  Constant: '<S2>/offset3'
   *  Constant: '<S2>/offset4'
   *  Constant: '<S2>/one_on_slope'
   *  Product: '<S2>/Product4'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  Sum: '<S2>/Add1'
   *  Sum: '<S2>/Add3'
   *  Sum: '<S2>/Add4'
   */
  locallocalSwitch1_m = (1024.0F * locallocalMatrixConcatenation6_) + 0.5F;

  /* DataStoreWrite: '<Root>/Data Store Write7' incorporates:
   *  DataTypeConversion: '<S2>/OutDTConv'
   */
  if (locallocalSwitch1_m < 2.147483648E+009F) {
    localtmp_0 = (SInt32)locallocalSwitch1_m;
  } else {
    localtmp_0 = MAX_int32_T;
  }

  AFA_prm_facSenTransMat7_MP[0] = localtmp_0;

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/offset'
   *  Constant: '<S6>/offset2'
   *  Constant: '<S6>/offset3'
   *  Constant: '<S6>/offset4'
   *  Constant: '<S6>/one_on_slope'
   *  Product: '<S6>/Product4'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S6>/Add3'
   *  Sum: '<S6>/Add4'
   */
  locallocalSwitch1_m = (1024.0F * locallocalMatrixConcatenation2_) + 0.5F;

  /* DataStoreWrite: '<Root>/Data Store Write3' incorporates:
   *  DataTypeConversion: '<S6>/OutDTConv'
   */
  if (locallocalSwitch1_m < 2.147483648E+009F) {
    localtmp_0 = (SInt32)locallocalSwitch1_m;
  } else {
    localtmp_0 = MAX_int32_T;
  }

  AFA_prm_facSenTransMat3_MP[1] = localtmp_0;

  /* DataStoreWrite: '<Root>/Data Store Write4' incorporates:
   *  Constant: '<S5>/offset'
   *  Constant: '<S5>/offset2'
   *  Constant: '<S5>/offset3'
   *  Constant: '<S5>/offset4'
   *  Constant: '<S5>/one_on_slope'
   *  DataTypeConversion: '<S5>/OutDTConv'
   *  Product: '<S5>/Product4'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  Sum: '<S5>/Add1'
   *  Sum: '<S5>/Add3'
   *  Sum: '<S5>/Add4'
   *  Switch: '<S5>/Switch1'
   */
  AFA_prm_facSenTransMat4_MP[1] = (SInt32)((1024.0F *
    locallocalMatrixConcatenation_0) + 0.5F);

  /* DataStoreWrite: '<Root>/Data Store Write5' incorporates:
   *  Constant: '<S4>/offset'
   *  Constant: '<S4>/offset2'
   *  Constant: '<S4>/offset3'
   *  Constant: '<S4>/offset4'
   *  Constant: '<S4>/one_on_slope'
   *  DataTypeConversion: '<S4>/OutDTConv'
   *  Product: '<S4>/Product4'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add3'
   *  Sum: '<S4>/Add4'
   *  Switch: '<S4>/Switch1'
   */
  AFA_prm_facSenTransMat5_MP[1] = (SInt32)((1024.0F *
    locallocalMatrixConcatenation_1) + 0.5F);

  /* DataStoreWrite: '<Root>/Data Store Write6' incorporates:
   *  Constant: '<S3>/offset'
   *  Constant: '<S3>/offset2'
   *  Constant: '<S3>/offset3'
   *  Constant: '<S3>/offset4'
   *  Constant: '<S3>/one_on_slope'
   *  DataTypeConversion: '<S3>/OutDTConv'
   *  Product: '<S3>/Product4'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  Sum: '<S3>/Add1'
   *  Sum: '<S3>/Add3'
   *  Sum: '<S3>/Add4'
   *  Switch: '<S3>/Switch1'
   */
  AFA_prm_facSenTransMat6_MP[1] = (SInt32)((1024.0F *
    locallocalMatrixConcatenation_2) + 0.5F);

  /* DataStoreWrite: '<Root>/Data Store Write7' incorporates:
   *  Constant: '<S2>/offset'
   *  Constant: '<S2>/offset2'
   *  Constant: '<S2>/offset3'
   *  Constant: '<S2>/offset4'
   *  Constant: '<S2>/one_on_slope'
   *  DataTypeConversion: '<S2>/OutDTConv'
   *  Product: '<S2>/Product4'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  Sum: '<S2>/Add1'
   *  Sum: '<S2>/Add3'
   *  Sum: '<S2>/Add4'
   *  Switch: '<S2>/Switch1'
   */
  AFA_prm_facSenTransMat7_MP[1] = (SInt32)((1024.0F *
    locallocalMatrixConcatenation_3) + 0.5F);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/AFA_agCkVlvExRef_C'
   */
  localDataTypeConversion6 = ((Float32)AFA_agCkVlvExRef_C) * 0.09375F;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/AFA_rCorArEffEGRVlvReqRef_C'
   */
  localDataTypeConversion13 = ((Float32)AFA_rCorArEffEGRVlvReqRef_C) *
    0.001953125F;

  /* Switch: '<Root>/Switch6' incorporates:
   *  Constant: '<Root>/Cste_2'
   *  Constant: '<Root>/Eng_bEGRVlvCf_SC1'
   *  Constant: '<Root>/Eng_bExVlvCf_SC'
   *  Logic: '<Root>/Logical Operator4'
   *  Logic: '<Root>/Logical Operator5'
   *  Logic: '<Root>/Logical Operator6'
   */
  if ((!Eng_bExVlvCf_SC) && (!Eng_bEGRVlvCf_SC)) {
    localDataTypeConversion = 0.0F;
  } else {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/AFA_bAcvVVTAdp_C'
     *  DataTypeConversion: '<Root>/Data Type Conversion15'
     *  DataTypeConversion: '<Root>/Data Type Conversion16'
     *  Product: '<Root>/Product'
     *  Product: '<Root>/Product1'
     *  Product: '<Root>/Product2'
     *  Product: '<Root>/Product3'
     */
    if (AFA_bAcvVVTAdp_C) {
      localDataTypeConversion1 = (localDataTypeConversion *
        localDataTypeConversion6) * (((Float32)(*rtu_AFA_pGrdDsThr_agCkEx)) *
        0.0625F);
    } else {
      localDataTypeConversion1 = (localDataTypeConversion *
        localDataTypeConversion13) * (((Float32)(*rtu_AFA_pGrdDsThr_arEffEGRVlv))
        * 1.525878906E+005F);
    }

    localDataTypeConversion = localDataTypeConversion1;
  }

  /* Switch: '<Root>/Switch5' incorporates:
   *  Constant: '<Root>/Eng_bEGRVlvCf_SC'
   *  Constant: '<Root>/Eng_bExVlvCf_SC1'
   *  Logic: '<Root>/Logical Operator1'
   *  Logic: '<Root>/Logical Operator2'
   *  Logic: '<Root>/Logical Operator3'
   */
  if ((!Eng_bExVlvCf_SC) && (!Eng_bEGRVlvCf_SC)) {
    localDataTypeConversion1 = localProduct28;
  } else {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<Root>/AFA_bAcvVVTAdp_C4'
     *  DataTypeConversion: '<Root>/Data Type Conversion28'
     *  DataTypeConversion: '<Root>/Data Type Conversion29'
     *  Product: '<Root>/Product20'
     *  Product: '<Root>/Product21'
     *  Product: '<Root>/Product22'
     *  Product: '<Root>/Product23'
     */
    if (AFA_bAcvVVTAdp_C) {
      localDataTypeConversion1 = (localDataTypeConversion12 *
        localDataTypeConversion6) * (((Float32)(*rtu_AFA_rlamGrd_agCkEx)) *
        3.051757858E-006F);
    } else {
      localDataTypeConversion1 = (localDataTypeConversion12 *
        localDataTypeConversion13) * (((Float32)(*rtu_AFA_rlamGrd_arEffEGRVlv))
        * 1.525878906E+000F);
    }
  }

  /* Product: '<S1>/Product4' incorporates:
   *  Constant: '<S1>/offset'
   *  Constant: '<S1>/one_on_slope'
   *  Sum: '<S1>/Add1'
   */
  locallocalSwitch1_m = 1024.0F * localDataTypeConversion;

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/offset2'
   *  Constant: '<S1>/offset3'
   *  Constant: '<S1>/offset4'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  Sum: '<S1>/Add3'
   *  Sum: '<S1>/Add4'
   */
  if (locallocalSwitch1_m >= 0.0F) {
    locallocalSwitch1_m += 0.5F;
  } else {
    locallocalSwitch1_m -= 0.5F;
  }

  /* DataStoreWrite: '<Root>/Data Store Write8' incorporates:
   *  DataTypeConversion: '<S1>/OutDTConv'
   */
  if (locallocalSwitch1_m < 2.147483648E+009F) {
    localtmp_0 = (SInt32)locallocalSwitch1_m;
  } else {
    localtmp_0 = MAX_int32_T;
  }

  AFA_prm_facSenTransMat8_MP[0] = localtmp_0;

  /* Product: '<S1>/Product4' incorporates:
   *  Constant: '<S1>/offset'
   *  Constant: '<S1>/one_on_slope'
   *  Sum: '<S1>/Add1'
   */
  locallocalSwitch1_m = 1024.0F * localDataTypeConversion1;

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/offset2'
   *  Constant: '<S1>/offset3'
   *  Constant: '<S1>/offset4'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  Sum: '<S1>/Add3'
   *  Sum: '<S1>/Add4'
   */
  if (locallocalSwitch1_m >= 0.0F) {
    locallocalSwitch1_m += 0.5F;
  } else {
    locallocalSwitch1_m -= 0.5F;
  }

  /* DataStoreWrite: '<Root>/Data Store Write8' incorporates:
   *  DataTypeConversion: '<S1>/OutDTConv'
   */
  if (locallocalSwitch1_m < 2.147483648E+009F) {
    localtmp_0 = (SInt32)locallocalSwitch1_m;
  } else {
    localtmp_0 = MAX_int32_T;
  }

  AFA_prm_facSenTransMat8_MP[1] = localtmp_0;

  /* Product: '<S9>/Product4' incorporates:
   *  Concatenate: '<Root>/Matrix Concatenation8'
   *  Constant: '<S9>/offset'
   *  Constant: '<S9>/one_on_slope'
   *  DataTypeConversion: '<Root>/Data Type Conversion11'
   *  Product: '<Root>/Product34'
   *  Sum: '<S9>/Add1'
   */
  locallocalMatrixConcatenation[0] = locallocalMatrixConcatenation_i;
  locallocalMatrixConcatenation[8] = locallocalMatrixConcatenation_4;
  locallocalMatrixConcatenation[1] = 0.0F;
  locallocalMatrixConcatenation[9] = locallocalMatrixConcatenation1_;
  locallocalMatrixConcatenation[2] = 0.0F;
  locallocalMatrixConcatenation[10] = locallocalMatrixConcatenation2_;
  locallocalMatrixConcatenation[3] = locallocalMatrixConcatenation3_;
  locallocalMatrixConcatenation[11] = locallocalMatrixConcatenation_0;
  locallocalMatrixConcatenation[4] = locallocalMatrixConcatenation4_;
  locallocalMatrixConcatenation[12] = locallocalMatrixConcatenation_1;
  locallocalMatrixConcatenation[5] = locallocalMatrixConcatenation5_;
  locallocalMatrixConcatenation[13] = locallocalMatrixConcatenation_2;
  locallocalMatrixConcatenation[6] = locallocalMatrixConcatenation6_;
  locallocalMatrixConcatenation[14] = locallocalMatrixConcatenation_3;
  locallocalMatrixConcatenation[7] = localDataTypeConversion;
  locallocalMatrixConcatenation[15] = localDataTypeConversion1;
  for (localtmp_0 = 0; localtmp_0 < 16; localtmp_0++) {
    locallocalSwitch1_m = (locallocalMatrixConcatenation[localtmp_0] *
      ((Float32)rtu_AFA_prm_bMaskSenMat_PIM[(localtmp_0)])) * 1024.0F;

    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S9>/offset2'
     *  Constant: '<S9>/offset3'
     *  Constant: '<S9>/offset4'
     *  RelationalOperator: '<S9>/Relational Operator'
     *  Sum: '<S9>/Add3'
     *  Sum: '<S9>/Add4'
     */
    if (locallocalSwitch1_m >= 0.0F) {
      locallocalSwitch1_m += 0.5F;
    } else {
      locallocalSwitch1_m -= 0.5F;
    }

    /* Reshape: '<Root>/Reshape3' incorporates:
     *  DataTypeConversion: '<S9>/OutDTConv'
     */
    if (locallocalSwitch1_m < 2.147483648E+009F) {
      localtmp = (SInt32)locallocalSwitch1_m;
    } else {
      localtmp = MAX_int32_T;
    }

    rty_AFA_prm_facSenTransMat_PIM[(localtmp_0)] = localtmp;
  }
}

/* Model initialize function */
void mr_AFA_F02_calc_sens_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
