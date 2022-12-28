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
/* !File            : AFA_F01_Osbservation_Number.c                           */
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
/*   Model name       : AFA_F01_Osbservation_Number.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_Osbservation_Number.h"
#include "AFA_F01_Osbservation_Number_private.h"
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


#define AFAT_START_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt8 AFA_noObsDoneIdl;              /* '<Root>/Switch' */
UInt8 AFA_noObsDoneIdlTmp;           /* '<Root>/Signal Conversion2' */

/* Exported block states */
UInt8 AFA_prm_noObsDonePrev_MP;      /* '<Root>/Data Store Memory' */
UInt8 AFA_prm_noObsDoneRaw_MP[9];    /* '<Root>/Data Store Memory1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F01_Osbservation_Number' */
void mr_AFA_F01_Osbservation_Number(const Boolean *rtu_IdlSys_bAcvIdlCtl,
  const UInt16 *rtu_Ext_nEng, const UInt16 *rtu_EngM_rTotLdExCor, const
  UInt8 rtu_AFA_prm_noObsDoneMat_PIM[9], const UInt8
  *rtu_AFA_noObsDoneIdlPrev, const Boolean *rtu_EOM_bSpcInjMod, const UInt8 *
  rtu_AFA_noObsSpcInjModPrev, const UInt16 *rtu_AFA_noAdpEfc, UInt8
  rty_AFA_prm_noObsDoneMat_PIM1[9], Boolean *rty_AFA_bEngStopAuth, UInt8
  *rty_AFA_noObsDoneIdlTmp, UInt8 *rty_AFA_noObsSpcInjMod)
{
  /* local block i/o variables */
  UInt8 localSelector;
  UInt32 localAdd;
  UInt32 localAdd1_c;
  UInt32 localAdd1;
  UInt8 localSwitch2;
  UInt8 localSignalConversion3[9];
  UInt8 localAssignment[9];
  SInt32 locali;

  /* SignalConversion: '<Root>/Signal Conversion3' */
  for (locali = 0; locali < 9; locali++) {
    localSignalConversion3[locali] = rtu_AFA_prm_noObsDoneMat_PIM[(locali)];
  }

  /* Lookup: '<S1>/Look-Up Table'
   * About '<S1>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Integer        U8
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U8_U16( &(localSelector), (&(AFA_noDivEngSpd_T[0])), (*rtu_Ext_nEng), (
    &(AFA_nEngRef1_A[0])), 2U);

  /* DataTypeDuplicate Block: '<S1>/Data Type Duplicate1'
   *
   * Regarding '<S1>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  localAdd = localSelector;

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  localAdd1_c = localAdd - 1U;

  /* MinMax: '<S4>/MinMax' incorporates:
   *  Constant: '<S4>/Constant'
   */
  locali = (SInt32)rt_MIN(localAdd1_c, 2U);

  /* Lookup: '<S2>/Look-Up Table'
   * About '<S2>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-14
   * Output0 Data Type:  Integer        U8
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U8_U16( &(localSelector), (&(AFA_noDivEngLd_T[0])),
                (*rtu_EngM_rTotLdExCor), (&(AFA_rLdRef1_A[0])), 2U);

  /* DataTypeDuplicate Block: '<S2>/Data Type Duplicate1'
   *
   * Regarding '<S2>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  localAdd1_c = localSelector;

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<S4>/Constant3'
   */
  localAdd1 = localAdd1_c - 1U;

  /* Selector: '<S4>/Selector' incorporates:
   *  Constant: '<S4>/Constant2'
   *  MinMax: '<S4>/MinMax1'
   */
  localSelector = localSignalConversion3[(3 * ((SInt32)rt_MIN(localAdd1, 2U)))
    + locali];

  /* DataStoreWrite: '<Root>/Data Store Write' */
  AFA_prm_noObsDonePrev_MP = localSelector;

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  localAdd--;

  /* Sum: '<S3>/Add1' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  localAdd1_c--;

  /* Assignment: '<S3>/Assignment' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant2'
   *  MinMax: '<S3>/MinMax'
   *  MinMax: '<S3>/MinMax1'
   *  Sum: '<Root>/Add2'
   */
  for (locali = 0; locali < 9; locali++) {
    localAssignment[locali] = localSignalConversion3[locali];
  }

  locali = localSelector + 1;
  if (((UInt32)locali) > 255U) {
    localSwitch2 = MAX_uint8_T;
  } else {
    localSwitch2 = (UInt8)locali;
  }

  localAssignment[((SInt32)rt_MIN(localAdd, 2U)) + (3 * ((SInt32)rt_MIN
    (localAdd1_c, 2U)))] = localSwitch2;

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  for (locali = 0; locali < 9; locali++) {
    AFA_prm_noObsDoneRaw_MP[locali] = localAssignment[locali];
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   *  SignalConversion: '<Root>/Signal Conversion4'
   *  Sum: '<Root>/Add1'
   */
  if ((*rtu_IdlSys_bAcvIdlCtl)) {
    locali = (*rtu_AFA_noObsDoneIdlPrev) + 1;
    if (((UInt32)locali) > 255U) {
      AFA_noObsDoneIdl = MAX_uint8_T;
    } else {
      AFA_noObsDoneIdl = (UInt8)locali;
    }
  } else {
    AFA_noObsDoneIdl = (*rtu_AFA_noObsDoneIdlPrev);
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/AFA_noAdpEfcEngStopThd_C'
   *  Constant: '<Root>/AFA_noObsDoneIdlThd_C'
   *  Constant: '<Root>/AFA_noObsIdlFirstObsThd_C'
   *  RelationalOperator: '<Root>/Relational Operator2'
   */
  if (((UInt32)(*rtu_AFA_noAdpEfc)) < ((UInt32)AFA_noAdpEfcEngStopThd_C)) {
    localSwitch2 = AFA_noObsIdlFirstObsThd_C;
  } else {
    localSwitch2 = AFA_noObsDoneIdlThd_C;
  }

  /* SignalConversion: '<Root>/Signal Conversion2' */
  AFA_noObsDoneIdlTmp = AFA_noObsDoneIdl;

  /* SignalConversion: '<Root>/Signal Conversion6' */
  (*rty_AFA_noObsDoneIdlTmp) = AFA_noObsDoneIdlTmp;

  /* SignalConversion: '<Root>/Signal1' incorporates:
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  (*rty_AFA_bEngStopAuth) = (AFA_noObsDoneIdl >= localSwitch2);

  /* Switch: '<Root>/Switch1' */
  for (locali = 0; locali < 9; locali++) {
    if ((*rtu_IdlSys_bAcvIdlCtl)) {
      rty_AFA_prm_noObsDoneMat_PIM1[(locali)] = localSignalConversion3[locali];
    } else {
      rty_AFA_prm_noObsDoneMat_PIM1[(locali)] = localAssignment[locali];
    }
  }

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/AFA_noObsSpcInjModThd_C'
   *  Constant: '<Root>/Constant5'
   *  Logic: '<Root>/Logical Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  if ((*rtu_EOM_bSpcInjMod) && ((*rtu_AFA_noObsSpcInjModPrev) >
       AFA_noObsSpcInjModThd_C)) {
    (*rty_AFA_noObsSpcInjMod) = 0U;
  } else {
    (*rty_AFA_noObsSpcInjMod) = (*rtu_AFA_noObsSpcInjModPrev);
  }
}

/* Model initialize function */
void mr_AFA_F01_Osbservat_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
