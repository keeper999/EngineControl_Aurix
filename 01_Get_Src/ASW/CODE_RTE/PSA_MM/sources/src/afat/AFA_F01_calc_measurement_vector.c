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
/* !File            : AFA_F01_calc_measurement_vector.c                       */
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
/*   Model name       : AFA_F01_calc_measurement_vector.mdl                   */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_calc_measurement_vector.h"
#include "AFA_F01_calc_measurement_vector_private.h"
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
UInt16 AFA_facMes1_MP;               /* '<Root>/Data Store Memory1' */
UInt16 AFA_facMes2_MP;               /* '<Root>/Data Store Memory2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F01_calc_measurement_vector' */
void mr_AFA_F01_calc_measurement_vec(const SInt16 *rtu_AFA_pDsThrEstimErrFil,
  const SInt32 *rtu_InjSys_lamFbFil, const UInt16 *rtu_AFA_noAdpEfc, SInt16
  rty_AFA_prm_facMes_PIM[2])
{
  Boolean localRelationalOperator2;
  Float32 localSwitch5;
  UInt16 localDataTypeConversion2;
  SInt16 localSwitch;
  SInt16 localSwitch1;
  Float32d localtmp;
  SInt32 localtmp_0;

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant10'
   *  Product: '<Root>/Product5'
   *  RelationalOperator: '<Root>/Relational Operator3'
   */
  if ((*rtu_AFA_pDsThrEstimErrFil) >= 0) {
    localSwitch = (*rtu_AFA_pDsThrEstimErrFil);
  } else {
    localtmp_0 = -(*rtu_AFA_pDsThrEstimErrFil);
    if (localtmp_0 > 32767) {
      localSwitch = MAX_int16_T;
    } else {
      localSwitch = (SInt16)localtmp_0;
    }
  }

  /* RelationalOperator: '<Root>/Relational Operator2' incorporates:
   *  Constant: '<Root>/AFA_noAdpEfcDoneDBThd_C'
   */
  localRelationalOperator2 = (((UInt32)(*rtu_AFA_noAdpEfc)) <= ((UInt32)
    AFA_noAdpEfcDoneDBThd_C));

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/AFA_pDsThrEstimErrDB_C'
   *  Constant: '<Root>/AFA_pDsThrEstimErrFirstObsDB_C'
   */
  if (localRelationalOperator2) {
    localDataTypeConversion2 = AFA_pDsThrEstimErrFirstObsDB_C;
  } else {
    localDataTypeConversion2 = AFA_pDsThrEstimErrDB_C;
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/AFA_facPresDsThrErrRef_C'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Product: '<Root>/Product'
   *  Product: '<Root>/Product1'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  if (localSwitch < localDataTypeConversion2) {
    localSwitch = 0;
  } else {
    localSwitch5 = (Float32)ACTEMS_FloorF(((((((Float32)
      (*rtu_AFA_pDsThrEstimErrFil)) * 8.0F) * (((Float32)
      AFA_facPresDsThrErrRef_C) * 6.103515625E-005F)) * -1.0F) * 256.0F) + 0.5F);
    if (((Float32d)localSwitch5) < 32768.0F) {
      if (((Float32d)localSwitch5) >= -32768.0F) {
        localSwitch = (SInt16)localSwitch5;
      } else {
        localSwitch = MIN_int16_T;
      }
    } else {
      localSwitch = MAX_int16_T;
    }
  }

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  localtmp_0 = localSwitch + 32768;
  if (localtmp_0 <= 0) {
    AFA_facMes1_MP = 0U;
  } else {
    AFA_facMes1_MP = (UInt16)localtmp_0;
  }

  /* Switch: '<Root>/Switch5' incorporates:
   *  Constant: '<Root>/Constant12'
   *  Constant: '<Root>/Constant13'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Product: '<Root>/Product4'
   *  RelationalOperator: '<Root>/Relational Operator4'
   */
  if ((*rtu_InjSys_lamFbFil) >= 0) {
    localSwitch5 = ((Float32)(*rtu_InjSys_lamFbFil)) * 7.629394531E-006F;
  } else {
    localSwitch5 = (Float32)(ACTEMS_LdexpF((Float32d)(*rtu_InjSys_lamFbFil), -17)
      * -1.0F);
  }

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/AFA_lamErrFirstObsDB_C'
   *  Constant: '<Root>/AFA_lamFbDB_C'
   */
  if (localRelationalOperator2) {
    localDataTypeConversion2 = AFA_lamErrFirstObsDB_C;
  } else {
    localDataTypeConversion2 = AFA_lamFbDB_C;
  }

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/AFA_facLamErrRef_C'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant6'
   *  Product: '<Root>/Product2'
   *  Product: '<Root>/Product3'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  if (localSwitch5 < (((Float32)localDataTypeConversion2) * 7.629394531E-006F))
  {
    localSwitch1 = 0;
  } else {
    localtmp = ACTEMS_FloorF(ACTEMS_LdexpF((Float32d)(((Float32)(ACTEMS_LdexpF
      ((Float32d)(*rtu_InjSys_lamFbFil), -17) * ACTEMS_LdexpF((Float32d)
      AFA_facLamErrRef_C, -6))) * -1.0F), 8));
    if (localtmp < 32768.0F) {
      if (localtmp >= -32768.0F) {
        localSwitch1 = (SInt16)localtmp;
      } else {
        localSwitch1 = MIN_int16_T;
      }
    } else {
      localSwitch1 = MAX_int16_T;
    }
  }

  /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  localtmp_0 = localSwitch1 + 32768;
  if (localtmp_0 <= 0) {
    AFA_facMes2_MP = 0U;
  } else {
    AFA_facMes2_MP = (UInt16)localtmp_0;
  }

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn1' */
  rty_AFA_prm_facMes_PIM[0] = localSwitch;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn2' */
  rty_AFA_prm_facMes_PIM[1] = localSwitch1;
}

/* Model initialize function */
void mr_AFA_F01_calc_meas_initialize(void)
{
  /* Registration code */

  /* states (dwork) */

  /* exported global states */
  AFA_facMes1_MP = 32768U;
  AFA_facMes2_MP = 32768U;
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
