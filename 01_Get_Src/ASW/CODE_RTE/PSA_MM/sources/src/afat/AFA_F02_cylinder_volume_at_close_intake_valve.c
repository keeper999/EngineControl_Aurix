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
/* !File            : AFA_F02_cylinder_volume_at_close_intake_valve.c         */
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
/*   Model name       : AFA_F02_cylinder_volume_at_close_intake_valve.mdl     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F02_cylinder_volume_at_close_intake_valve.h"
#include "AFA_F02_cylinder_volume_at_close_intake_valve_private.h"
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
SInt32 AFA_rVolCylGrdClsInVlv_agCkIn; /* '<Root>/Switch1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

UInt16 AFA_rVolCylClsInVlv;          /* '<S1>/Look-Up Table' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F02_cylinder_volume_at_close_intake_valve' */
void mr_AFA_F02_cylinder_volume_at_c(const UInt16
  *rtu_AFA_agCkClsInVlvEstimRef1_, UInt16 *rty_AFA_rVolCylClsInVlv, SInt32
  *rty_AFA_rVolCylGrdClsInVlv_agCk)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion;
  SInt16 localLookUpTable;
  Boolean localRelationalOperator;
  Float32 localSwitch;
  SInt32 localtmp;

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant'
   */
  localRelationalOperator = ((*rtu_AFA_agCkClsInVlvEstimRef1_) > 2880);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Sum'
   */
  if (localRelationalOperator) {
    localSwitch = (((Float32)(*rtu_AFA_agCkClsInVlvEstimRef1_)) * 0.0625F) -
      360.0F;
  } else {
    localSwitch = ((Float32)(*rtu_AFA_agCkClsInVlvEstimRef1_)) * 0.0625F;
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/AirEfc_bVolBurnRgTot_C3'
   *  Constant: '<Root>/AirEfc_bVolBurnRgTot_C4'
   *  Product: '<Root>/Product8'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  if (!(localSwitch >= 0.0F)) {
    localSwitch = -localSwitch;
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  localDataTypeConversion = (UInt16)(((Float32d)localSwitch) / 0.09375F);

  /* Lookup: '<S1>/Look-Up Table'
   * About '<S1>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
   * Output0 Data Type:  Fixed Point    U16  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(AFA_rVolCylClsInVlv), (&(AirEfc_rVolCyl_T[0])),
                 localDataTypeConversion, (&(AirEfc_agCk_facTDC_A[0])), 19U);

  /* DataTypeDuplicate Block: '<S1>/Data Type Duplicate1'
   *
   * Regarding '<S1>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  localDataTypeConversion = (UInt16)(((Float32d)localSwitch) / 0.09375F);

  /* Lookup: '<S2>/Look-Up Table'
   * About '<S2>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
   * Output0 Data Type:  Fixed Point    S16  2^-22  FSlope 1.28
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_S16_U16( &(localLookUpTable), (&(AFA_rVolGrdCyl_T[0])),
                 localDataTypeConversion, (&(AFA_agCk_facTDCGrd_A[0])), 18U);

  /* DataTypeDuplicate Block: '<S2>/Data Type Duplicate1'
   *
   * Regarding '<S2>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_rVolCylClsInVlv) = AFA_rVolCylClsInVlv;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant16'
   *  Product: '<Root>/Product'
   */
  if (localRelationalOperator) {
    localtmp = -localLookUpTable;
    AFA_rVolCylGrdClsInVlv_agCkIn = mul_s32_s32_s32_sr29_sat((localtmp >= 0) ?
      ((SInt32)(((UInt32)localtmp) >> 1U)) : (~((SInt32)(((UInt32)
      (~localtmp)) >> 1U))), 1073726981);
  } else {
    AFA_rVolCylGrdClsInVlv_agCkIn = localLookUpTable;
  }

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_rVolCylGrdClsInVlv_agCk) = AFA_rVolCylGrdClsInVlv_agCkIn;
}

/* Model initialize function */
void mr_AFA_F02_cylinder__initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
