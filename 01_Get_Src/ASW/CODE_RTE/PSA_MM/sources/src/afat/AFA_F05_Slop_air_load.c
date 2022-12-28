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
/* !File            : AFA_F05_Slop_air_load.c                                 */
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
/*   Model name       : AFA_F05_Slop_air_load.mdl                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F05_Slop_air_load.h"
#include "AFA_F05_Slop_air_load_private.h"
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
SInt16 AFA_facSlopGrdEfc_agCkIn;      /* '<Root>/Divide' */
UInt16 AFA_facSlopEfcGrd_pDsThr;     /* '<Root>/Product' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F05_Slop_air_load' */
void mr_AFA_F05_Slop_air_load(const UInt16 *rtu_AFA_facCorSlopEfc, const
  SInt16 *rtu_AFA_facCorSlopGrdEfc_agCkIn, const UInt16
  *rtu_AFA_rVolCylClsInVlv, const SInt32 *rtu_AFA_rVolCylGrdClsInVlv_agCk,
  const UInt8 *rtu_AFA_facTCo, const UInt32 *rtu_AFA_facSlopEfcCorFil, const
  UInt16 *rtu_AFA_pDsThrFil, const UInt16 *rtu_AFA_facTAirUsInVlv, SInt16
  *rty_AFA_facSlopGrdEfc_agCkIn, UInt16 *rty_AFA_facSlopEfcGrd_pDsThr)
{
  Float32d localtmp;
  UInt32 localtmp_0;
  UInt16 localtmp_1;

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/AirEfc_pRef_C'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  Product: '<Root>/Product1'
   *  Product: '<Root>/Product2'
   *  Product: '<Root>/Product3'
   *  Product: '<Root>/Product4'
   *  Sum: '<Root>/Add'
   */
  localtmp = ACTEMS_FloorF(((((Float32d)(((((((Float32)(*rtu_AFA_facCorSlopEfc)) *
    3.051757813E-005F) * (((Float32)(*rtu_AFA_rVolCylGrdClsInVlv_agCk)) *
    3.051800093E-007F)) + ((((Float32)(*rtu_AFA_rVolCylClsInVlv)) *
    3.051757813E-005F) * (((Float32)(*rtu_AFA_facCorSlopGrdEfc_agCkIn)) *
    3.051757858E-006F))) * (((Float32)(*rtu_AFA_facTAirUsInVlv)) *
    3.051757813E-005F)) * (((Float32)(*rtu_AFA_facTCo)) * 0.0078125F))) /
    ACTEMS_LdexpF((Float32d)AirEfc_pRef_C, 3)) / 3.0517578124999999E-011F) + 0.5F);
  if (localtmp < 32768.0F) {
    if (localtmp >= -32768.0F) {
      AFA_facSlopGrdEfc_agCkIn = (SInt16)localtmp;
    } else {
      AFA_facSlopGrdEfc_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_facSlopGrdEfc_agCkIn = MAX_int16_T;
  }

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_facSlopGrdEfc_agCkIn) = AFA_facSlopGrdEfc_agCkIn;

  /* Product: '<Root>/Product' */
  localtmp_0 = mul_u32_u32_u32_sr17_sat_near((*rtu_AFA_facSlopEfcCorFil),
    (UInt32)(*rtu_AFA_pDsThrFil));
  if (localtmp_0 > 65535U) {
    localtmp_1 = MAX_uint16_T;
  } else {
    localtmp_1 = (UInt16)localtmp_0;
  }

  localtmp_0 = ((UInt32)localtmp_1) * 52429U;
  localtmp_0 = (UInt32)(((localtmp_0 & 16384U) != 0U) + ((SInt32)(localtmp_0 >>
    15U)));
  if (localtmp_0 > 65535U) {
    AFA_facSlopEfcGrd_pDsThr = MAX_uint16_T;
  } else {
    AFA_facSlopEfcGrd_pDsThr = (UInt16)localtmp_0;
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_facSlopEfcGrd_pDsThr) = AFA_facSlopEfcGrd_pDsThr;
}

/* Model initialize function */
void mr_AFA_F05_Slop_air__initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
