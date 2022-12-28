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
/* !File            : AFA_F09_offset_air_load.c                               */
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
/*   Model name       : AFA_F09_offset_air_load.mdl                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F09_offset_air_load.h"
#include "AFA_F09_offset_air_load_private.h"
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
UInt32 AFA_facOfsEfcGrd_pDsThr;      /* '<Root>/Sum2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

SInt16 AFA_facOfsGrdEfc_agCkEx;       /* '<Root>/Product12' */
SInt16 AFA_facOfsGrdEfc_agCkIn;       /* '<Root>/Product15' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F09_offset_air_load' */
void mr_AFA_F09_offset_air_load(const UInt16 *rtu_AFA_facTAirUsInVl9, const
  UInt16 *rtu_AFA_facTBurnCyl, const SInt16 *rtu_AFA_facTBurnGrdCyl_agCkEx,
  const SInt16 *rtu_AFA_facTBurnGrdCyl_agCkIn, const UInt16
  *rtu_AFA_rMassBurnRg, const UInt16 *rtu_AFA_rMassBurn, const SInt16
  *rtu_AFA_rMassBurn_agCkE9, const SInt16 *rtu_AFA_rMassBurn_agCkI9, const
  SInt16 *rtu_AFA_mGrdBurnRspg_p9, const UInt16 *rtu_AFA_facAirScv, const
  UInt16 *rtu_AFA_mGrdAirScvTot_p9, UInt32 *rty_AFA_facOfsEfcGrd_pDsThr,
  SInt16 *rty_AFA_facOfsGrdEfc_agCkEx, SInt16 *rty_AFA_facOfsGrdEfc_agCkIn)
{
  Float32 localSum1;
  SInt32 localtmp;
  Float32d localtmp_0;

  /* DataTypeConversion: '<Root>/Data Type Conversion11' */
  localSum1 = ((Float32)(*rtu_AFA_rMassBurn)) * 6.103515625E-005F;

  /* Product: '<Root>/Product12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  Product: '<Root>/Product'
   *  Product: '<Root>/Product11'
   *  Sum: '<Root>/Add'
   */
  localtmp = (SInt32)ACTEMS_FloorF((((Float32d)(((((Float32)
    (*rtu_AFA_facTBurnGrdCyl_agCkEx)) * 1.525878906E-005F) * localSum1) +
    ((((Float32)(*rtu_AFA_facTBurnCyl)) * 1.525878906E-004F) * (((Float32)
    (*rtu_AFA_rMassBurn_agCkE9)) * 3.051757858E-006F)))) * ((Float32d)(((Float32)
                                        (*rtu_AFA_facTAirUsInVl9)) *
    3.051757813E-005F))) / 3.0517578125000002E-006F);
  if (localtmp < 32768) {
    if (localtmp >= -32768) {
      AFA_facOfsGrdEfc_agCkEx = (SInt16)localtmp;
    } else {
      AFA_facOfsGrdEfc_agCkEx = MIN_int16_T;
    }
  } else {
    AFA_facOfsGrdEfc_agCkEx = MAX_int16_T;
  }

  /* Product: '<Root>/Product15' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   *  Product: '<Root>/Product13'
   *  Product: '<Root>/Product14'
   *  Sum: '<Root>/Add1'
   */
  localtmp_0 = ACTEMS_FloorF((((Float32d)(((((Float32)
    (*rtu_AFA_facTBurnGrdCyl_agCkIn)) * 1.525878906E-005F) * localSum1) +
    ((Float32)((((Float32d)(*rtu_AFA_facTBurnCyl)) * 1.5258789062500000E-004F) *
                ((Float32d)(((Float32)(*rtu_AFA_rMassBurn_agCkI9)) *
    3.051757858E-006F)))))) * ACTEMS_LdexpF((Float32d)(*rtu_AFA_facTAirUsInVl9),
    -15)) / 3.0517578125000002E-006F);
  if (localtmp_0 < 32768.0F) {
    if (localtmp_0 >= -32768.0F) {
      AFA_facOfsGrdEfc_agCkIn = (SInt16)localtmp_0;
    } else {
      AFA_facOfsGrdEfc_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_facOfsGrdEfc_agCkIn = MAX_int16_T;
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant5'
   *  Product: '<Root>/Product18'
   *  Sum: '<Root>/Sum9'
   */
  if ((*rtu_AFA_rMassBurnRg) != 0) {
    localSum1 = (Float32)(((Float32d)(1.0F - (((Float32)(*rtu_AFA_facAirScv)) *
      1.525878906E-005F))) * (((Float32d)(*rtu_AFA_mGrdAirScvTot_p9)) *
      7.6293945312500000E+000F));
  } else {
    localSum1 = 0.0F;
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_facOfsGrdEfc_agCkEx) = AFA_facOfsGrdEfc_agCkEx;

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_facOfsGrdEfc_agCkIn) = AFA_facOfsGrdEfc_agCkIn;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Product: '<Root>/Product16'
   *  Product: '<Root>/Product17'
   *  Product: '<Root>/Product19'
   *  Sum: '<Root>/Sum1'
   */
  localtmp_0 = ((Float32d)(((Float32)((((Float32d)(*rtu_AFA_mGrdAirScvTot_p9)) *
    7.6293945312500000E+000F) * ACTEMS_LdexpF((Float32d)(*rtu_AFA_facAirScv), -16)))
    - (((Float32)((((Float32d)(*rtu_AFA_facTBurnCyl)) * 1.5258789062500000E-004F) *
                   ACTEMS_LdexpF((Float32d)(*rtu_AFA_facTAirUsInVl9), -15))) *
       ((((Float32)(*rtu_AFA_mGrdBurnRspg_p9)) * 3.051757813E-004F) - localSum1))))
    / 2.3283064365386963E-004F;
  if (localtmp_0 < 4.294967296E+009F) {
    if (localtmp_0 >= 0.0F) {
      AFA_facOfsEfcGrd_pDsThr = (UInt32)localtmp_0;
    } else {
      AFA_facOfsEfcGrd_pDsThr = 0U;
    }
  } else {
    AFA_facOfsEfcGrd_pDsThr = MAX_uint32_T;
  }

  /* SignalConversion: '<Root>/Signal3' */
  (*rty_AFA_facOfsEfcGrd_pDsThr) = AFA_facOfsEfcGrd_pDsThr;
}

/* Model initialize function */
void mr_AFA_F09_offset_ai_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
