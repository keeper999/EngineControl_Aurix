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
/* !File            : AFA_F01_fresh_gas_temperature.c                         */
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
/*   Model name       : AFA_F01_fresh_gas_temperature.mdl                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_fresh_gas_temperature.h"
#include "AFA_F01_fresh_gas_temperature_private.h"
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
UInt16 AFA_facTAirUsInVlv;           /* '<S1>/Look-Up Table (2-D)' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F01_fresh_gas_temperature' */
void mr_AFA_F01_fresh_gas_temperatur(const UInt32 *rtu_AFA_tAirUsInVlvEstimFi1,
  const UInt16 *rtu_AFA_nEngFil, UInt16 *rty_AFA_facTAirUsInVlv)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion1;
  SInt32 localq;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  if ((*rtu_AFA_tAirUsInVlvEstimFi1) > 2147483647U) {
    localq = MAX_int32_T;
  } else {
    localq = (SInt32)(*rtu_AFA_tAirUsInVlvEstimFi1);
  }

  localq += -28544;
  if (localq <= 0) {
    localDataTypeConversion1 = 0U;
  } else if (localq > 65535) {
    localDataTypeConversion1 = MAX_uint16_T;
  } else {
    localDataTypeConversion1 = (UInt16)localq;
  }

  /* Lookup2D: '<S1>/Look-Up Table (2-D)'
   * About '<S1>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
   * Output0 Data Type:  Fixed Point    U16  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(AFA_facTAirUsInVlv), (&(AirEfc_facTAirUsInVlv_M[0])),
                     (*rtu_AFA_nEngFil), (&(AirEfc_nEngY_A[0])), 17U,
                     localDataTypeConversion1, (&(AirEfc_tAirUsInVlv_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S1>/Data Type Duplicate2'
   *
   * Regarding '<S1>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_facTAirUsInVlv) = AFA_facTAirUsInVlv;
}

/* Model initialize function */
void mr_AFA_F01_fresh_gas_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
