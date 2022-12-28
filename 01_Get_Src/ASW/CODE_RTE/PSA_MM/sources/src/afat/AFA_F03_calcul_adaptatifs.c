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
/* !File            : AFA_F03_calcul_adaptatifs.c                             */
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
/*   Model name       : AFA_F03_calcul_adaptatifs.mdl                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F03_calcul_adaptatifs.h"
#include "AFA_F03_calcul_adaptatifs_private.h"
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
SInt32 AFA_facSlopInjGainPrev;        /* '<Root>/Signal Conversion3' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

SInt16 AFA_arEffThrOfsPrev;           /* '<Root>/Signal Conversion4' */
SInt16 AFA_facIvsInjGainPrev;         /* '<Root>/Signal Conversion' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"

SInt8 AFA_tiOffInjPrev;               /* '<Root>/Signal Conversion2' */
SInt8 AFA_facArEffThrOfs1Prev;        /* '<Root>/Signal Conversion5' */
SInt8 AFA_facArEffThrOfs2Prev;        /* '<Root>/Signal Conversion6' */
SInt8 AFA_facArEffThrOfs3Prev;        /* '<Root>/Signal Conversion7' */
SInt8 AFA_rCor_arEffEGRVlvPrev;       /* '<Root>/Signal Conversion8' */
SInt8 AFA_agCkOpInVlvOfsPrev;         /* '<Root>/Signal Conversion1' */
SInt8 AFA_agCkClsExVlvOfsPrev;        /* '<Root>/Signal Conversion9' */

#define AFAT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F03_calcul_adaptatifs' */
void mr_AFA_F03_calcul_adaptatifs(const SInt16 rtu_AFA_prm_rErr_PIM[8], const
  SInt8 *rtu_AFA_tiOffInjPrev3, const SInt32 *rtu_AFA_facSlopInjGainP3, const
  SInt16 *rtu_AFA_arEffThrOfsPrev3, const SInt8 *rtu_AFA_facArEffThrOfs1P3,
  const SInt8 *rtu_AFA_facArEffThrOfs2P3, const SInt8
  *rtu_AFA_facArEffThrOfs3P3, const SInt8 *rtu_AFA_rCor_arEffEGRVlvP3, const
  SInt16 *rtu_AFA_facIvsInjGainP3, const SInt8 *rtu_AFA_agCkOpInVlvOfsP3,
  const SInt8 *rtu_AFA_agCkClsExVlvOfsP3, SInt16 *rty_AFA_facIvsInjGai2,
  SInt8 *rty_AFA_tiOffInj3, SInt32 *rty_AFA_facSlopInjGain3, SInt16
  *rty_AFA_arEffThrOf3, SInt8 *rty_AFA_facArEffThrOf12, SInt8
  *rty_AFA_facArEffThrOf22, SInt8 *rty_AFA_facArEffThrOf32, SInt8
  *rty_AFA_rCor_arEffEGRV3, SInt8 *rty_AFA_agCkOpInVlvOf3, SInt8
  *rty_AFA_agCkClsExVlvOf3, SInt8 *rty_AFA_arEffEGRVlvOf3)
{
  SInt16 localDiff[8];
  Float32 localDataTypeConversion13;
  Float32 localSubtract2;
  SInt32 localSwitch2_cv;
  SInt32 localSwitch2_a;
  SInt32 localSwitch2_m;
  SInt16 localSwitch6;
  SInt32 locali;
  SInt32 localq;
  SInt32 localq_0;
  SInt32 localqY;

  /* SignalConversion: '<Root>/Signal Conversion' */
  AFA_facIvsInjGainPrev = (*rtu_AFA_facIvsInjGainP3);

  /* Product: '<S24>/Divide' incorporates:
   *  Constant: '<Root>/AFA_rErrDB_C'
   *  Constant: '<Root>/Constant41'
   */
  locali = AFA_rErrDB_C + -32768;
  if (locali <= -32768) {
    localSwitch6 = MIN_int16_T;
  } else {
    localSwitch6 = (SInt16)locali;
  }

  localSwitch2_cv = -localSwitch6;

  /* Sum: '<S11>/Diff' incorporates:
   *  Constant: '<Root>/AFA_rErrDB_C'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  RelationalOperator: '<S11>/u_GTE_up'
   *  RelationalOperator: '<S11>/u_GT_lo'
   *  Switch: '<S11>/Switch'
   *  Switch: '<S11>/Switch1'
   */
  for (locali = 0; locali < 8; locali++) {
    if (rtu_AFA_prm_rErr_PIM[(locali)] >= (AFA_rErrDB_C + -32768)) {
      localSwitch6 = 0;
    } else if (rtu_AFA_prm_rErr_PIM[(locali)] > localSwitch2_cv) {
      localSwitch6 = rtu_AFA_prm_rErr_PIM[(locali)];
    } else {
      localSwitch6 = 0;
    }

    localq = rtu_AFA_prm_rErr_PIM[(locali)] - localSwitch6;
    if (localq > 32767) {
      localSwitch6 = MAX_int16_T;
    } else if (localq <= -32768) {
      localSwitch6 = MIN_int16_T;
    } else {
      localSwitch6 = (SInt16)localq;
    }

    localDiff[locali] = localSwitch6;
  }

  /* SignalConversion: '<Root>/Signal Conversion1' */
  AFA_agCkOpInVlvOfsPrev = (*rtu_AFA_agCkOpInVlvOfsP3);

  /* SignalConversion: '<Root>/Signal Conversion2' */
  AFA_tiOffInjPrev = (*rtu_AFA_tiOffInjPrev3);

  /* Sum: '<Root>/Subtract2' incorporates:
   *  Constant: '<Root>/AFA_tiOffInjRef_C'
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   *  DataTypeConversion: '<Root>/Data Type Conversion11'
   *  DataTypeConversion: '<Root>/Data Type Conversion12'
   *  Product: '<Root>/Product3'
   */
  localSubtract2 = ((((Float32)AFA_tiOffInjRef_C) * 3.200000037E-006F) *
                    (((Float32)localDiff[1]) * 0.0001220703125F)) + (((Float32)
    AFA_tiOffInjPrev) * 3.200000037E-006F);

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Constant: '<Root>/AFA_tiOffInjSat_C'
   */
  localDataTypeConversion13 = ((Float32)AFA_tiOffInjSat_C) * 3.200000037E-006F;

  /* Switch: '<S41>/Switch2' incorporates:
   *  RelationalOperator: '<S41>/LowerRelop1'
   */
  if (localSubtract2 > localDataTypeConversion13) {
    localSubtract2 = localDataTypeConversion13;
  } else {
    /* Product: '<S25>/Divide' incorporates:
     *  Constant: '<Root>/Constant20'
     */
    localDataTypeConversion13 = -localDataTypeConversion13;

    /* Switch: '<S41>/Switch' incorporates:
     *  RelationalOperator: '<S41>/UpperRelop'
     */
    if (localSubtract2 < localDataTypeConversion13) {
      localSubtract2 = localDataTypeConversion13;
    }
  }

  /* SignalConversion: '<Root>/Signal Conversion3' */
  AFA_facSlopInjGainPrev = (*rtu_AFA_facSlopInjGainP3);

  /* DataTypeConversion: '<S45>/Conversion' incorporates:
   *  Constant: '<Root>/AFA_arEffThrOfsSat_C'
   */
  localSwitch2_cv = AFA_arEffThrOfsSat_C;

  /* SignalConversion: '<Root>/Signal Conversion4' */
  AFA_arEffThrOfsPrev = (*rtu_AFA_arEffThrOfsPrev3);

  /* Sum: '<Root>/Subtract4' incorporates:
   *  Constant: '<Root>/AFA_arEffThrOfsRef_C'
   *  Product: '<S17>/Divide'
   */
  localq = AFA_arEffThrOfsPrev;
  locali = AFA_arEffThrOfsRef_C * localDiff[3];
  locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 13U)) : (~((SInt32)
    (((UInt32)(~locali)) >> 13U)));
  localqY = localq + locali;
  if ((localq < 0) && ((locali < 0) && (localqY >= 0))) {
    localqY = MIN_int32_T;
  } else {
    if ((localq > 0) && ((locali > 0) && (localqY <= 0))) {
      localqY = MAX_int32_T;
    }
  }

  /* Switch: '<S47>/Switch2' incorporates:
   *  RelationalOperator: '<S47>/LowerRelop1'
   */
  if (!(localqY > localSwitch2_cv)) {
    /* Product: '<S27>/Divide' incorporates:
     *  Constant: '<Root>/AFA_arEffThrOfsSat_C'
     *  Constant: '<Root>/Constant24'
     */
    localq = -AFA_arEffThrOfsSat_C;

    /* Switch: '<S47>/Switch' incorporates:
     *  RelationalOperator: '<S47>/UpperRelop'
     */
    if (localqY < localq) {
      localqY = localq;
    }

    localSwitch2_cv = localqY;
  }

  /* DataTypeConversion: '<S48>/Conversion' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs1Sat_C'
   */
  localSwitch2_a = AFA_facArEffThrOfs1Sat_C;

  /* SignalConversion: '<Root>/Signal Conversion5' */
  AFA_facArEffThrOfs1Prev = (*rtu_AFA_facArEffThrOfs1P3);

  /* Sum: '<Root>/Subtract5' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs1Ref_C'
   *  Product: '<Root>/Product'
   */
  localq = AFA_facArEffThrOfs1Prev;
  locali = AFA_facArEffThrOfs1Ref_C * localDiff[4];
  locali = ((locali & 4096) != 0) + ((locali >= 0) ? ((SInt32)(((UInt32)
    locali) >> 13U)) : (~((SInt32)(((UInt32)(~locali)) >> 13U))));
  localqY = localq + locali;
  if ((localq < 0) && ((locali < 0) && (localqY >= 0))) {
    localqY = MIN_int32_T;
  } else {
    if ((localq > 0) && ((locali > 0) && (localqY <= 0))) {
      localqY = MAX_int32_T;
    }
  }

  /* Switch: '<S50>/Switch2' incorporates:
   *  RelationalOperator: '<S50>/LowerRelop1'
   */
  if (!(localqY > localSwitch2_a)) {
    /* Product: '<S28>/Divide' incorporates:
     *  Constant: '<Root>/AFA_facArEffThrOfs1Sat_C'
     *  Constant: '<Root>/Constant26'
     */
    localq = -AFA_facArEffThrOfs1Sat_C;

    /* Switch: '<S50>/Switch' incorporates:
     *  RelationalOperator: '<S50>/UpperRelop'
     */
    if (localqY < localq) {
      localqY = localq;
    }

    localSwitch2_a = localqY;
  }

  /* DataTypeConversion: '<S51>/Conversion' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs2Sat_C'
   */
  localSwitch2_m = AFA_facArEffThrOfs2Sat_C;

  /* SignalConversion: '<Root>/Signal Conversion6' */
  AFA_facArEffThrOfs2Prev = (*rtu_AFA_facArEffThrOfs2P3);

  /* Sum: '<Root>/Subtract6' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs2Ref_C'
   *  Product: '<Root>/Product4'
   */
  localq = AFA_facArEffThrOfs2Prev;
  locali = AFA_facArEffThrOfs2Ref_C * localDiff[5];
  locali = ((locali & 4096) != 0) + ((locali >= 0) ? ((SInt32)(((UInt32)
    locali) >> 13U)) : (~((SInt32)(((UInt32)(~locali)) >> 13U))));
  localqY = localq + locali;
  if ((localq < 0) && ((locali < 0) && (localqY >= 0))) {
    localqY = MIN_int32_T;
  } else {
    if ((localq > 0) && ((locali > 0) && (localqY <= 0))) {
      localqY = MAX_int32_T;
    }
  }

  /* Switch: '<S53>/Switch2' incorporates:
   *  RelationalOperator: '<S53>/LowerRelop1'
   */
  if (!(localqY > localSwitch2_m)) {
    /* Product: '<S29>/Divide' incorporates:
     *  Constant: '<Root>/AFA_facArEffThrOfs2Sat_C'
     *  Constant: '<Root>/Constant29'
     */
    localq = -AFA_facArEffThrOfs2Sat_C;

    /* Switch: '<S53>/Switch' incorporates:
     *  RelationalOperator: '<S53>/UpperRelop'
     */
    if (localqY < localq) {
      localqY = localq;
    }

    localSwitch2_m = localqY;
  }

  /* DataTypeConversion: '<S54>/Conversion' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs3Sat_C'
   */
  localq = AFA_facArEffThrOfs3Sat_C;

  /* SignalConversion: '<Root>/Signal Conversion7' */
  AFA_facArEffThrOfs3Prev = (*rtu_AFA_facArEffThrOfs3P3);

  /* Sum: '<Root>/Subtract7' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs3Ref_C'
   *  Product: '<Root>/Product8'
   */
  localq_0 = AFA_facArEffThrOfs3Prev;
  locali = AFA_facArEffThrOfs3Ref_C * localDiff[6];
  locali = ((locali & 4096) != 0) + ((locali >= 0) ? ((SInt32)(((UInt32)
    locali) >> 13U)) : (~((SInt32)(((UInt32)(~locali)) >> 13U))));
  localqY = localq_0 + locali;
  if ((localq_0 < 0) && ((locali < 0) && (localqY >= 0))) {
    localqY = MIN_int32_T;
  } else {
    if ((localq_0 > 0) && ((locali > 0) && (localqY <= 0))) {
      localqY = MAX_int32_T;
    }
  }

  /* Switch: '<S56>/Switch2' incorporates:
   *  RelationalOperator: '<S56>/LowerRelop1'
   */
  if (!(localqY > localq)) {
    /* Product: '<S30>/Divide' incorporates:
     *  Constant: '<Root>/AFA_facArEffThrOfs3Sat_C'
     *  Constant: '<Root>/Constant36'
     */
    localq = -AFA_facArEffThrOfs3Sat_C;

    /* Switch: '<S56>/Switch' incorporates:
     *  RelationalOperator: '<S56>/UpperRelop'
     */
    if (localqY < localq) {
      localqY = localq;
    }

    localq = localqY;
  }

  /* SignalConversion: '<Root>/Signal Conversion8' */
  AFA_rCor_arEffEGRVlvPrev = (*rtu_AFA_rCor_arEffEGRVlvP3);

  /* SignalConversion: '<Root>/Signal Conversion9' */
  AFA_agCkClsExVlvOfsPrev = (*rtu_AFA_agCkClsExVlvOfsP3);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  if (localSwitch2_a > 127) {
    (*rty_AFA_facArEffThrOf12) = MAX_int8_T;
  } else if (localSwitch2_a <= -128) {
    (*rty_AFA_facArEffThrOf12) = MIN_int8_T;
  } else {
    (*rty_AFA_facArEffThrOf12) = (SInt8)localSwitch2_a;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  if (localSwitch2_cv > 32767) {
    (*rty_AFA_arEffThrOf3) = MAX_int16_T;
  } else if (localSwitch2_cv <= -32768) {
    (*rty_AFA_arEffThrOf3) = MIN_int16_T;
  } else {
    (*rty_AFA_arEffThrOf3) = (SInt16)localSwitch2_cv;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  if (localq > 127) {
    (*rty_AFA_facArEffThrOf32) = MAX_int8_T;
  } else if (localq <= -128) {
    (*rty_AFA_facArEffThrOf32) = MIN_int8_T;
  } else {
    (*rty_AFA_facArEffThrOf32) = (SInt8)localq;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  if (localSwitch2_m > 127) {
    (*rty_AFA_facArEffThrOf22) = MAX_int8_T;
  } else if (localSwitch2_m <= -128) {
    (*rty_AFA_facArEffThrOf22) = MIN_int8_T;
  } else {
    (*rty_AFA_facArEffThrOf22) = (SInt8)localSwitch2_m;
  }

  /* Product: '<S19>/Product4' incorporates:
   *  Constant: '<S19>/offset'
   *  Constant: '<S19>/one_on_slope'
   *  Sum: '<S19>/Add1'
   */
  localDataTypeConversion13 = 312500.0F * localSubtract2;

  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S19>/offset2'
   *  Constant: '<S19>/offset3'
   *  Constant: '<S19>/offset4'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  Sum: '<S19>/Add3'
   *  Sum: '<S19>/Add4'
   */
  if (localDataTypeConversion13 >= 0.0F) {
    localSubtract2 = localDataTypeConversion13 + 0.5F;
  } else {
    localSubtract2 = localDataTypeConversion13 - 0.5F;
  }

  /* DataTypeConversion: '<S19>/OutDTConv' */
  if (localSubtract2 < 128.0F) {
    if (localSubtract2 >= -128.0F) {
      (*rty_AFA_tiOffInj3) = (SInt8)localSubtract2;
    } else {
      (*rty_AFA_tiOffInj3) = MIN_int8_T;
    }
  } else {
    (*rty_AFA_tiOffInj3) = MAX_int8_T;
  }

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/AFA_bAcvVVTAdp_C1'
   *  Constant: '<Root>/AFA_bAcvVVTAdp_C2'
   *  Constant: '<Root>/AFA_bSelAdpTyp_C'
   *  Constant: '<Root>/Constant9'
   *  Constant: '<Root>/Eng_bEGRVlvCf_SC1'
   *  Constant: '<Root>/Eng_bExVlvCf_SC1'
   *  DataTypeConversion: '<Root>/Data Type Conversion23'
   *  Logic: '<Root>/Logical Operator25'
   *  Logic: '<Root>/Logical Operator3'
   *  Logic: '<Root>/Logical Operator4'
   *  Logic: '<Root>/Logical Operator5'
   *  Logic: '<Root>/Logical Operator6'
   */
  if (((!(Eng_bExVlvCf_SC || Eng_bEGRVlvCf_SC)) || (!AFA_bAcvVVTAdp_C)) ||
      (AFA_bSelAdpTyp_C && AFA_bAcvVVTAdp_C)) {
    /* Switch: '<Root>/Switch5' incorporates:
     *  Constant: '<Root>/AFA_bAcvVVTAdp_C'
     */
    if (AFA_bAcvVVTAdp_C) {
      /* Switch: '<Root>/Switch6' incorporates:
       *  Constant: '<Root>/Eng_bEGRVlvCf_SC'
       *  Constant: '<Root>/Eng_bExVlvCf_SC'
       *  Logic: '<Root>/Logical Operator2'
       *  Logic: '<Root>/Logical Operator8'
       */
      if (!(Eng_bExVlvCf_SC || Eng_bEGRVlvCf_SC)) {
        localSwitch6 = localDiff[7];
      } else {
        localSwitch6 = localDiff[2];
      }
    } else {
      localSwitch6 = localDiff[0];
    }

    /* Sum: '<Root>/Subtract9' incorporates:
     *  Constant: '<Root>/AFA_facIvsInjGainRef_C'
     *  Product: '<S12>/Divide'
     */
    localq = AFA_facIvsInjGainPrev;
    locali = AFA_facIvsInjGainRef_C * localSwitch6;
    locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 13U)) :
      (~((SInt32)(((UInt32)(~locali)) >> 13U)));
    localqY = localq + locali;
    if ((localq < 0) && ((locali < 0) && (localqY >= 0))) {
      localqY = MIN_int32_T;
    } else {
      if ((localq > 0) && ((locali > 0) && (localqY <= 0))) {
        localqY = MAX_int32_T;
      }
    }

    /* DataTypeConversion: '<S33>/Conversion' incorporates:
     *  Constant: '<Root>/AFA_facIvsInjGainSat_C'
     */
    localq = AFA_facIvsInjGainSat_C;

    /* Switch: '<S35>/Switch2' incorporates:
     *  RelationalOperator: '<S35>/LowerRelop1'
     */
    if (!(localqY > localq)) {
      /* Product: '<S22>/Divide' incorporates:
       *  Constant: '<Root>/AFA_facIvsInjGainSat_C'
       *  Constant: '<Root>/Constant16'
       */
      localq = -AFA_facIvsInjGainSat_C;

      /* Switch: '<S35>/Switch' incorporates:
       *  RelationalOperator: '<S35>/UpperRelop'
       */
      if (localqY < localq) {
        localqY = localq;
      }

      localq = localqY;
    }

    if (localq > 32767) {
      (*rty_AFA_facIvsInjGai2) = MAX_int16_T;
    } else if (localq <= -32768) {
      (*rty_AFA_facIvsInjGai2) = MIN_int16_T;
    } else {
      (*rty_AFA_facIvsInjGai2) = (SInt16)localq;
    }
  } else {
    (*rty_AFA_facIvsInjGai2) = 0;
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant32'
   *  Constant: '<Root>/Eng_bInVlvCf_SC'
   *  DataTypeConversion: '<S18>/OutDTConv'
   */
  if (Eng_bInVlvCf_SC) {
    /* Sum: '<Root>/Subtract1' incorporates:
     *  Constant: '<Root>/AFA_agCkVlvInRef_C'
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     *  DataTypeConversion: '<Root>/Data Type Conversion6'
     *  Product: '<S14>/Divide'
     */
    localSubtract2 = ((((Float32)AFA_agCkVlvInRef_C) * 0.09375F) * (((Float32)
      localDiff[0]) * 0.0001220703125F)) + (((Float32)AFA_agCkOpInVlvOfsPrev) *
      0.09375F);

    /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
     *  Constant: '<Root>/AFA_agCkVlvInSat_C'
     */
    localDataTypeConversion13 = ((Float32)AFA_agCkVlvInSat_C) * 0.09375F;

    /* Switch: '<S38>/Switch2' incorporates:
     *  RelationalOperator: '<S38>/LowerRelop1'
     */
    if (localSubtract2 > localDataTypeConversion13) {
      localSubtract2 = localDataTypeConversion13;
    } else {
      /* Product: '<S23>/Divide' incorporates:
       *  Constant: '<Root>/Constant18'
       */
      localDataTypeConversion13 = -localDataTypeConversion13;

      /* Switch: '<S38>/Switch' incorporates:
       *  RelationalOperator: '<S38>/UpperRelop'
       */
      if (localSubtract2 < localDataTypeConversion13) {
        localSubtract2 = localDataTypeConversion13;
      }
    }

    /* Product: '<S18>/Product4' incorporates:
     *  Constant: '<S18>/offset'
     *  Constant: '<S18>/one_on_slope'
     *  Sum: '<S18>/Add1'
     */
    localDataTypeConversion13 = 1.066666698E+001F * localSubtract2;

    /* Switch: '<S18>/Switch1' incorporates:
     *  Constant: '<S18>/offset2'
     *  Constant: '<S18>/offset3'
     *  Constant: '<S18>/offset4'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  Sum: '<S18>/Add3'
     *  Sum: '<S18>/Add4'
     */
    if (localDataTypeConversion13 >= 0.0F) {
      localSubtract2 = localDataTypeConversion13 + 0.5F;
    } else {
      localSubtract2 = localDataTypeConversion13 - 0.5F;
    }

    if (localSubtract2 < 128.0F) {
      if (localSubtract2 >= -128.0F) {
        (*rty_AFA_agCkOpInVlvOf3) = (SInt8)localSubtract2;
      } else {
        (*rty_AFA_agCkOpInVlvOf3) = MIN_int8_T;
      }
    } else {
      (*rty_AFA_agCkOpInVlvOf3) = MAX_int8_T;
    }
  } else {
    (*rty_AFA_agCkOpInVlvOf3) = 0;
  }

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant34'
   *  Constant: '<Root>/Eng_bEGRVlvCf_SC2'
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   */
  if (Eng_bEGRVlvCf_SC) {
    /* Sum: '<Root>/Subtract10' incorporates:
     *  Constant: '<Root>/AFA_rCorArEffEGRVlvReqRef_C'
     *  Product: '<S15>/Divide'
     */
    localq = AFA_rCor_arEffEGRVlvPrev;
    locali = AFA_rCorArEffEGRVlvReqRef_C * localDiff[7];
    locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 14U)) :
      (~((SInt32)(((UInt32)(~locali)) >> 14U)));
    localqY = localq + locali;
    if ((localq < 0) && ((locali < 0) && (localqY >= 0))) {
      localqY = MIN_int32_T;
    } else {
      if ((localq > 0) && ((locali > 0) && (localqY <= 0))) {
        localqY = MAX_int32_T;
      }
    }

    /* DataTypeConversion: '<S57>/Conversion' incorporates:
     *  Constant: '<Root>/AFA_rCorArEffEGRVlvReqSat_C'
     */
    localq = AFA_rCorArEffEGRVlvReqSat_C;

    /* Switch: '<S59>/Switch2' incorporates:
     *  RelationalOperator: '<S59>/LowerRelop1'
     */
    if (!(localqY > localq)) {
      /* Product: '<S31>/Divide' incorporates:
       *  Constant: '<Root>/AFA_rCorArEffEGRVlvReqSat_C'
       *  Constant: '<Root>/Constant38'
       */
      localq = -AFA_rCorArEffEGRVlvReqSat_C;

      /* Switch: '<S59>/Switch' incorporates:
       *  RelationalOperator: '<S59>/UpperRelop'
       */
      if (localqY < localq) {
        localqY = localq;
      }

      localq = localqY;
    }

    if (localq > 127) {
      (*rty_AFA_rCor_arEffEGRV3) = MAX_int8_T;
    } else if (localq <= -128) {
      (*rty_AFA_rCor_arEffEGRV3) = MIN_int8_T;
    } else {
      (*rty_AFA_rCor_arEffEGRV3) = (SInt8)localq;
    }
  } else {
    (*rty_AFA_rCor_arEffEGRV3) = 0;
  }

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/Constant33'
   *  Constant: '<Root>/Eng_bExVlvCf_SC2'
   *  DataTypeConversion: '<S21>/OutDTConv'
   */
  if (Eng_bExVlvCf_SC) {
    /* Sum: '<Root>/Subtract8' incorporates:
     *  Constant: '<Root>/AFA_agCkVlvExRef_C'
     *  DataTypeConversion: '<Root>/Data Type Conversion18'
     *  DataTypeConversion: '<Root>/Data Type Conversion19'
     *  DataTypeConversion: '<Root>/Data Type Conversion20'
     *  Product: '<S13>/Divide'
     */
    localSubtract2 = ((((Float32)AFA_agCkVlvExRef_C) * 0.09375F) * (((Float32)
      localDiff[7]) * 0.0001220703125F)) + (((Float32)AFA_agCkClsExVlvOfsPrev) *
      0.09375F);

    /* DataTypeConversion: '<Root>/Data Type Conversion21' incorporates:
     *  Constant: '<Root>/AFA_agCkVlvExSat_C'
     */
    localDataTypeConversion13 = ((Float32)AFA_agCkVlvExSat_C) * 0.09375F;

    /* Switch: '<S62>/Switch2' incorporates:
     *  RelationalOperator: '<S62>/LowerRelop1'
     */
    if (localSubtract2 > localDataTypeConversion13) {
      localSubtract2 = localDataTypeConversion13;
    } else {
      /* Product: '<S32>/Divide' incorporates:
       *  Constant: '<Root>/Constant39'
       */
      localDataTypeConversion13 = -localDataTypeConversion13;

      /* Switch: '<S62>/Switch' incorporates:
       *  RelationalOperator: '<S62>/UpperRelop'
       */
      if (localSubtract2 < localDataTypeConversion13) {
        localSubtract2 = localDataTypeConversion13;
      }
    }

    /* Product: '<S21>/Product4' incorporates:
     *  Constant: '<S21>/offset'
     *  Constant: '<S21>/one_on_slope'
     *  Sum: '<S21>/Add1'
     */
    localDataTypeConversion13 = 1.066666698E+001F * localSubtract2;

    /* Switch: '<S21>/Switch1' incorporates:
     *  Constant: '<S21>/offset2'
     *  Constant: '<S21>/offset3'
     *  Constant: '<S21>/offset4'
     *  RelationalOperator: '<S21>/Relational Operator'
     *  Sum: '<S21>/Add3'
     *  Sum: '<S21>/Add4'
     */
    if (localDataTypeConversion13 >= 0.0F) {
      localSubtract2 = localDataTypeConversion13 + 0.5F;
    } else {
      localSubtract2 = localDataTypeConversion13 - 0.5F;
    }

    if (localSubtract2 < 128.0F) {
      if (localSubtract2 >= -128.0F) {
        (*rty_AFA_agCkClsExVlvOf3) = (SInt8)localSubtract2;
      } else {
        (*rty_AFA_agCkClsExVlvOf3) = MIN_int8_T;
      }
    } else {
      (*rty_AFA_agCkClsExVlvOf3) = MAX_int8_T;
    }
  } else {
    (*rty_AFA_agCkClsExVlvOf3) = 0;
  }

  /* Switch: '<Root>/Switch7' incorporates:
   *  Constant: '<Root>/AFA_bAcvVVTAdp_C3'
   *  Constant: '<Root>/AFA_bSelAdpTyp_C1'
   *  Constant: '<Root>/Constant37'
   *  DataTypeConversion: '<S20>/OutDTConv'
   *  Logic: '<Root>/Logical Operator7'
   */
  if (AFA_bSelAdpTyp_C && AFA_bAcvVVTAdp_C) {
    (*rty_AFA_facSlopInjGain3) = 0;
  } else {
    /* Sum: '<Root>/Subtract3' incorporates:
     *  Constant: '<Root>/AFA_facSlopInjGainRef_C'
     *  DataTypeConversion: '<Root>/Data Type Conversion14'
     *  DataTypeConversion: '<Root>/Data Type Conversion15'
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     *  Product: '<S16>/Divide'
     */
    localSubtract2 = ((((Float32)AFA_facSlopInjGainRef_C) * 3.255208325E-010F) *
                      (((Float32)localDiff[2]) * 0.0001220703125F)) +
      (((Float32)AFA_facSlopInjGainPrev) * 3.255208325E-010F);

    /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
     *  Constant: '<Root>/AFA_facSlopInjGainSat_C'
     */
    localDataTypeConversion13 = ((Float32)AFA_facSlopInjGainSat_C) *
      3.255208325E-010F;

    /* Switch: '<S44>/Switch2' incorporates:
     *  RelationalOperator: '<S44>/LowerRelop1'
     */
    if (localSubtract2 > localDataTypeConversion13) {
      localSubtract2 = localDataTypeConversion13;
    } else {
      /* Product: '<S26>/Divide' incorporates:
       *  Constant: '<Root>/Constant22'
       */
      localDataTypeConversion13 = -localDataTypeConversion13;

      /* Switch: '<S44>/Switch' incorporates:
       *  RelationalOperator: '<S44>/UpperRelop'
       */
      if (localSubtract2 < localDataTypeConversion13) {
        localSubtract2 = localDataTypeConversion13;
      }
    }

    /* Product: '<S20>/Product4' incorporates:
     *  Constant: '<S20>/offset'
     *  Constant: '<S20>/one_on_slope'
     *  Sum: '<S20>/Add1'
     */
    localDataTypeConversion13 = 4.294967296E+009F * localSubtract2;

    /* Switch: '<S20>/Switch1' incorporates:
     *  Constant: '<S20>/offset2'
     *  Constant: '<S20>/offset3'
     *  Constant: '<S20>/offset4'
     *  RelationalOperator: '<S20>/Relational Operator'
     *  Sum: '<S20>/Add3'
     *  Sum: '<S20>/Add4'
     */
    if (localDataTypeConversion13 >= 0.0F) {
      localSubtract2 = localDataTypeConversion13 + 0.5F;
    } else {
      localSubtract2 = localDataTypeConversion13 - 0.5F;
    }

    if (localSubtract2 < 2.147483648E+009F) {
      if (localSubtract2 >= -2.147483648E+009F) {
        (*rty_AFA_facSlopInjGain3) = (SInt32)localSubtract2;
      } else {
        (*rty_AFA_facSlopInjGain3) = MIN_int32_T;
      }
    } else {
      (*rty_AFA_facSlopInjGain3) = MAX_int32_T;
    }
  }

  /* Constant: '<Root>/Constant40' */
  (*rty_AFA_arEffEGRVlvOf3) = 0;
}

/* Model initialize function */
void mr_AFA_F03_calcul_ad_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
