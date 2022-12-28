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
/* !File            : AFA_F04_Water_correction_temperature.c                  */
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
/*   Model name       : AFA_F04_Water_correction_temperature.mdl              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F04_Water_correction_temperature.h"
#include "AFA_F04_Water_correction_temperature_private.h"
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
UInt8 AFA_facTCo;                    /* '<Root>/Data Type Conversion2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F04_Water_correction_temperature' */
void mr_AFA_F04_Water_correction_tem(const UInt16 *rtu_AFA_nEngFil, const
  SInt16 *rtu_AFA_tCoMesFil, UInt8 *rty_AFA_facTCo)
{
  /* local block i/o variables */
  UInt16 localLookUpTable2D;
  UInt8 localDataTypeConversion1;
  SInt32 localtmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  localtmp = (*rtu_AFA_tCoMesFil) + 40;
  if (localtmp <= 0) {
    localDataTypeConversion1 = 0U;
  } else if (localtmp > 255) {
    localDataTypeConversion1 = MAX_uint8_T;
  } else {
    localDataTypeConversion1 = (UInt8)localtmp;
  }

  /* Lookup2D: '<S1>/Look-Up Table (2-D)'
   * About '<S1>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U8  Bias -40.0
   * Output0 Data Type:  Fixed Point    U16  2^-7
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U8( &(localLookUpTable2D), (&(AirEfc_facTCo_M[0])),
                    (*rtu_AFA_nEngFil), (&(AirEfc_nEngY_A[0])), 17U,
                    localDataTypeConversion1, (&(AirEfc_tCoX_A[0])), 9U);

  /* DataTypeDuplicate Block: '<S1>/Data Type Duplicate2'
   *
   * Regarding '<S1>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  if (localLookUpTable2D > 255) {
    AFA_facTCo = MAX_uint8_T;
  } else {
    AFA_facTCo = (UInt8)localLookUpTable2D;
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_facTCo) = AFA_facTCo;
}

/* Model initialize function */
void mr_AFA_F04_Water_cor_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
