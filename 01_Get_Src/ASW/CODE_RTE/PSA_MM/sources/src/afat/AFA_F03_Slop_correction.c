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
/* !File            : AFA_F03_Slop_correction.c                               */
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
/*   Model name       : AFA_F03_Slop_correction.mdl                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F03_Slop_correction.h"
#include "AFA_F03_Slop_correction_private.h"
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
UInt32 AFA_facChgCorSlopEfc_MP;      /* '<S3>/Data Store Memory1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt16 AFA_nEngCorSlopFil;           /* '<S5>/Switch' */
UInt16 AFA_facCorSlopEfc;            /* '<S4>/Sum' */
UInt16 AFA_facCorBoostSlopEfc;       /* '<S8>/Look-Up Table (2-D)' */
UInt16 AFA_facCorAtmSlopEfc;         /* '<S6>/Look-Up Table (2-D)' */
SInt16 AFA_facCorSlopGrdEfc_agCkIn;   /* '<S4>/Sum6' */
SInt16 AFA_facCorBoostGrdSlopEfc_agCkIn;/* '<S2>/Data Type Conversion2' */
SInt16 AFA_facCorAtmGrdSlopEfc_agCkIn;/* '<S1>/Data Type Conversion3' */
UInt16 AFA_facChgCorSlopEfc;         /* '<S11>/Look-Up Table' */
UInt16 AFA_facChgCorGrdSlopEfc_agCkIn;/* '<S12>/Look-Up Table' */
UInt16 AFA_facChgCorSlopEfcMax_MP;   /* '<S3>/Data Store Memory' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F03_Slop_correction' */
void mr_AFA_F03_Slop_correction(const UInt16 *rtu_AFA_agCkClsInVlvEstimRef1Fi,
  const UInt16 *rtu_AFA_nEngFil, const UInt16 *rtu_AFA_pDsThrFil, const
  UInt16 *rtu_AFA_pAirExtEstimFil, const UInt16 *rtu_AFA_nEngCorFil,
  UInt16 *rty_AFA_facCorSlopEfc, SInt16 *rty_AFA_facCorSlopGrdEfc_agCkIn)
{
  /* local block i/o variables */
  UInt16 localLookUpTable;
  UInt16 localDataTypeConversion_h;
  UInt16 localDataTypeConversion1_h;
  UInt16 localDataTypeConversion1_d;
  UInt16 localDataTypeConversion1_n;
  UInt16 localDataTypeConversion1_o;
  SInt16 localLookUpTable2D;
  SInt16 localLookUpTable2D_m;
  SInt16 localLookUpTable2D_b;
  Float32 localDivide;
  Float32 localDataTypeConversion2;
  Float32 localMinMax1;
  Float32 localDataTypeConversion3_p;
  Float32 localProduct;
  Float32 localProduct6;
  UInt32 localSwitch1_o;
  Float32d localtmp;
  SInt32 localqY;
  SInt16 localtmp_0;

  /* Outputs for atomic SubSystem: '<Root>/F05_Engine_speed_choice' *
   * Block requirements for '<Root>/F05_Engine_speed_choice':
   *  1. SubSystem "F05_Engine_speed_choice" !Trace_To : VEMS_R_11_04467_238.01 ;
   */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/AFA_bAcvEngSpdCorSlop_C'
   */
  if (AFA_bAcvEngSpdCorSlop_C) {
    AFA_nEngCorSlopFil = (*rtu_AFA_nEngCorFil);
  } else {
    AFA_nEngCorSlopFil = (*rtu_AFA_nEngFil);
  }

  /* end of Outputs for SubSystem: '<Root>/F05_Engine_speed_choice' */

  /* Outputs for atomic SubSystem: '<Root>/F01_Atmospheric_slop_correction' *
   * Block requirements for '<Root>/F01_Atmospheric_slop_correction':
   *  1. SubSystem "F01_Atmospheric_slop_correction" !Trace_To : VEMS_R_11_04467_068.02 ;
   */

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  localDataTypeConversion1_o = (UInt16)((((UInt32)
    (*rtu_AFA_agCkClsInVlvEstimRef1Fi)) * 43691U) >> 16U);

  /* Lookup2D: '<S6>/Look-Up Table (2-D)'
   * About '<S6>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
   * Output0 Data Type:  Fixed Point    U16  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(AFA_facCorAtmSlopEfc), (&(AirEfc_facCorAtmSlopEfc_M[0])),
                     AFA_nEngCorSlopFil, (&(AirEfc_nEngY_A[0])), 17U,
                     localDataTypeConversion1_o, (&(AirEfc_agCkClsInVlvX_A[0])),
                     12U);

  /* DataTypeDuplicate Block: '<S6>/Data Type Duplicate2'
   *
   * Regarding '<S6>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  localqY = ((SInt32)((((UInt32)(*rtu_AFA_agCkClsInVlvEstimRef1Fi)) * 43691U)
                       >> 16U)) + -896;
  if (localqY <= 0) {
    localDataTypeConversion1_o = 0U;
  } else if (localqY > 65535) {
    localDataTypeConversion1_o = MAX_uint16_T;
  } else {
    localDataTypeConversion1_o = (UInt16)localqY;
  }

  /* Lookup2D: '<S7>/Look-Up Table (2-D)'
   * About '<S7>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5  Bias 84.0
   * Output0 Data Type:  Fixed Point    S16  2^-20  FSlope 1.6
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_S16_U16_U16( &(localLookUpTable2D_m), (&(AFA_facCorAtmGrdSlopEfc_M[0])),
                     AFA_nEngCorSlopFil, (&(AirEfc_nEngY_A[0])), 17U,
                     localDataTypeConversion1_o, (&(AFA_agCkGrdClsInVlvX_A[0])),
                     11U);

  /* DataTypeDuplicate Block: '<S7>/Data Type Duplicate2'
   *
   * Regarding '<S7>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S1>/Data Type Conversion3' */
  localtmp_0 = (SInt16)((localLookUpTable2D_m < 0) + localLookUpTable2D_m);
  AFA_facCorAtmGrdSlopEfc_agCkIn = (SInt16)((localtmp_0 >= 0) ? ((SInt32)
    (((UInt32)localtmp_0) >> 1U)) : (~((SInt32)(((UInt32)(~localtmp_0)) >>
    1U))));

  /* end of Outputs for SubSystem: '<Root>/F01_Atmospheric_slop_correction' */

  /* Outputs for atomic SubSystem: '<Root>/F02_Boost_slop_correction' *
   * Block requirements for '<Root>/F02_Boost_slop_correction':
   *  1. SubSystem "F02_Boost_slop_correction" !Trace_To : VEMS_R_11_04467_069.02 ;
   */

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  localDataTypeConversion1_n = (UInt16)((((UInt32)
    (*rtu_AFA_agCkClsInVlvEstimRef1Fi)) * 43691U) >> 16U);

  /* Lookup2D: '<S8>/Look-Up Table (2-D)'
   * About '<S8>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
   * Output0 Data Type:  Fixed Point    U16  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(AFA_facCorBoostSlopEfc), (&(AirEfc_facCorBoostSlopEfc_M
    [0])), AFA_nEngCorSlopFil, (&(AirEfc_nEngY_A[0])), 17U,
                     localDataTypeConversion1_n, (&(AirEfc_agCkClsInVlvX_A[0])),
                     12U);

  /* DataTypeDuplicate Block: '<S8>/Data Type Duplicate2'
   *
   * Regarding '<S8>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  localqY = ((SInt32)((((UInt32)(*rtu_AFA_agCkClsInVlvEstimRef1Fi)) * 43691U)
                       >> 16U)) + -896;
  if (localqY <= 0) {
    localDataTypeConversion1_n = 0U;
  } else if (localqY > 65535) {
    localDataTypeConversion1_n = MAX_uint16_T;
  } else {
    localDataTypeConversion1_n = (UInt16)localqY;
  }

  /* Lookup2D: '<S9>/Look-Up Table (2-D)'
   * About '<S9>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5  Bias 84.0
   * Output0 Data Type:  Fixed Point    S16  2^-20  FSlope 1.6
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_S16_U16_U16( &(localLookUpTable2D), (&(AFA_facCorBoostGrdSlopEfc_M[0])),
                     AFA_nEngCorSlopFil, (&(AirEfc_nEngY_A[0])), 17U,
                     localDataTypeConversion1_n, (&(AFA_agCkGrdClsInVlvX_A[0])),
                     11U);

  /* DataTypeDuplicate Block: '<S9>/Data Type Duplicate2'
   *
   * Regarding '<S9>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  localtmp_0 = (SInt16)((localLookUpTable2D < 0) + localLookUpTable2D);
  AFA_facCorBoostGrdSlopEfc_agCkIn = (SInt16)((localtmp_0 >= 0) ? ((SInt32)
    (((UInt32)localtmp_0) >> 1U)) : (~((SInt32)(((UInt32)(~localtmp_0)) >>
    1U))));

  /* end of Outputs for SubSystem: '<Root>/F02_Boost_slop_correction' */

  /* Outputs for atomic SubSystem: '<Root>/F03_Coefficient_atmospheric_to_boost_slop_correction' *
   * Block requirements for '<Root>/F03_Coefficient_atmospheric_to_boost_slop_correction':
   *  1. SubSystem "F03_Coefficient_atmospheric_to_boost_slop_correction" !Trace_To : VEMS_R_11_04467_070.02 ;
   */

  /* DataTypeConversion: '<S14>/Data Type Conversion1' */
  localDataTypeConversion1_d = (UInt16)((((UInt32)
    (*rtu_AFA_agCkClsInVlvEstimRef1Fi)) * 43691U) >> 16U);

  /* Lookup2D: '<S14>/Look-Up Table (2-D)'
   * About '<S14>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
   * Output0 Data Type:  Fixed Point    U16  2^3
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localDataTypeConversion_h),
                     (&(AirEfc_pBegCorBoostSlopEfc_M[0])), AFA_nEngCorSlopFil, (
    &(AirEfc_nEngY_A[0])), 17U, localDataTypeConversion1_d,
                     (&(AirEfc_agCkClsInVlvX_A[0])), 12U);

  /* DataTypeDuplicate Block: '<S14>/Data Type Duplicate2'
   *
   * Regarding '<S14>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* Product: '<S17>/Divide' incorporates:
   *  Constant: '<S3>/AirEfc_pRef_C'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  localDivide = (((Float32)(*rtu_AFA_pAirExtEstimFil)) * 8.0F) / (((Float32)
    AirEfc_pRef_C) * 8.0F);

  /* Outputs for atomic SubSystem: '<S17>/If Action Subsystem3' */

  /* Switch: '<S21>/Switch1' incorporates:
   *  Constant: '<S21>/Constant2'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  Saturate: '<S21>/Saturation'
   */
  if (localDivide != localDivide) {
    localDivide = 0.0F;
  } else {
    localDivide = rt_SATURATE(localDivide, -3.000000005E+038F, 3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S17>/If Action Subsystem3' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Product: '<S3>/Product2'
   */
  localMinMax1 = (((Float32)(*rtu_AFA_pDsThrFil)) * 8.0F) - ((((Float32)
    localDataTypeConversion_h) * 8.0F) * localDivide);

  /* Lookup: '<S10>/Look-Up Table'
   * About '<S10>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^3
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable), (&(AirEfc_pDeltaCorSlopEfc_T[0])),
                 AFA_nEngCorSlopFil, (&(AirEfc_nDeltaCorSlopEfc_A[0])), 17U);

  /* DataTypeDuplicate Block: '<S10>/Data Type Duplicate1'
   *
   * Regarding '<S10>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Lookup: '<S10>/Look-Up Table'
   */
  localDataTypeConversion2 = ((Float32)localLookUpTable) * 8.0F;

  /* Product: '<S19>/Divide' incorporates:
   *  Product: '<S3>/Product1'
   */
  localDivide = localMinMax1 / (localDivide * localDataTypeConversion2);

  /* Outputs for atomic SubSystem: '<S19>/If Action Subsystem3' */

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/Constant2'
   *  RelationalOperator: '<S25>/Relational Operator'
   *  Saturate: '<S25>/Saturation'
   */
  if (localDivide != localDivide) {
    localDivide = 0.0F;
  } else {
    localDivide = rt_SATURATE(localDivide, -3.000000005E+038F, 3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S19>/If Action Subsystem3' */

  /* DataTypeConversion: '<S3>/Data Type Conversion4' */
  localtmp = ACTEMS_LdexpF((Float32d)localDivide, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion_h = (UInt16)localtmp;
    } else {
      localDataTypeConversion_h = 0U;
    }
  } else {
    localDataTypeConversion_h = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S3>/Data Store Write' */
  AFA_facChgCorSlopEfcMax_MP = localDataTypeConversion_h;

  /* MinMax: '<S3>/MinMax1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  localMinMax1 = rt_MAXf(localDivide, 0.0F);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S3>/Constant3'
   *  RelationalOperator: '<S15>/Compare'
   */
  if (localMinMax1 >= 1.0F) {
    localSwitch1_o = 0U;
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S3>/Constant2'
     *  RelationalOperator: '<S16>/Compare'
     */
    if (localDivide <= 0.0F) {
      localDivide = 0.0F;
    } else {
      /* DataTypeConversion: '<S13>/Data Type Conversion1' */
      localqY = ((SInt32)((((UInt32)(*rtu_AFA_agCkClsInVlvEstimRef1Fi)) *
                            43691U) >> 16U)) + -896;
      if (localqY <= 0) {
        localDataTypeConversion1_h = 0U;
      } else if (localqY > 65535) {
        localDataTypeConversion1_h = MAX_uint16_T;
      } else {
        localDataTypeConversion1_h = (UInt16)localqY;
      }

      /* Lookup2D: '<S13>/Look-Up Table (2-D)'
       * About '<S13>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-4  FSlope 1.5  Bias 84.0
       * Output0 Data Type:  Fixed Point    S16  2^-5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_S16_U16_U16( &(localLookUpTable2D_b),
                         (&(AFA_pGrdBegCorBoostSlopEfc_M[0])),
                         AFA_nEngCorSlopFil, (&(AirEfc_nEngY_A[0])), 17U,
                         localDataTypeConversion1_h, (&(AFA_agCkGrdClsInVlvX_A[0])),
                         11U);

      /* DataTypeDuplicate Block: '<S13>/Data Type Duplicate2'
       *
       * Regarding '<S13>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Product: '<S18>/Divide' incorporates:
       *  Constant: '<S3>/Constant6'
       *  DataTypeConversion: '<S3>/Data Type Conversion3'
       *  Lookup2D: '<S13>/Look-Up Table (2-D)'
       *  Product: '<S3>/Product3'
       */
      localDivide = ((((Float32)localLookUpTable2D_b) * 0.03125F) * -1.0F) /
        localDataTypeConversion2;

      /* Outputs for atomic SubSystem: '<S18>/If Action Subsystem3' */

      /* Switch: '<S23>/Switch1' incorporates:
       *  Constant: '<S23>/Constant2'
       *  RelationalOperator: '<S23>/Relational Operator'
       *  Saturate: '<S23>/Saturation'
       */
      if (localDivide != localDivide) {
        localDivide = 0.0F;
      } else {
        localDivide = rt_SATURATE(localDivide, -3.000000005E+038F,
          3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S18>/If Action Subsystem3' */
    }

    localtmp = ACTEMS_LdexpF((Float32d)localDivide, 16);
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        localSwitch1_o = (UInt32)localtmp;
      } else {
        localSwitch1_o = 0U;
      }
    } else {
      localSwitch1_o = MAX_uint32_T;
    }
  }

  /* DataStoreWrite: '<S3>/Data Store Write1' */
  AFA_facChgCorSlopEfc_MP = localSwitch1_o;

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S3>/Constant1'
   *  MinMax: '<S3>/MinMax'
   */
  localtmp = ACTEMS_LdexpF((Float32d)rt_MINf(localMinMax1, 1.0F), 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion_h = (UInt16)localtmp;
    } else {
      localDataTypeConversion_h = 0U;
    }
  } else {
    localDataTypeConversion_h = MAX_uint16_T;
  }

  /* Lookup: '<S11>/Look-Up Table'
   * About '<S11>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(AFA_facChgCorSlopEfc), (&(AirEfc_facChgCorSlopEfc_T[0])),
                 localDataTypeConversion_h, (&(AirEfc_facChgCorSlopEfc_A[0])),
                 10U);

  /* DataTypeDuplicate Block: '<S11>/Data Type Duplicate1'
   *
   * Regarding '<S11>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (localSwitch1_o > 65535U) {
    localDataTypeConversion_h = MAX_uint16_T;
  } else {
    localDataTypeConversion_h = (UInt16)localSwitch1_o;
  }

  /* Lookup: '<S12>/Look-Up Table'
   * About '<S12>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(AFA_facChgCorGrdSlopEfc_agCkIn),
                 (&(AirEfc_facChgCorSlopEfc_T[0])), localDataTypeConversion_h, (
    &(AirEfc_facChgCorSlopEfc_A[0])), 10U);

  /* DataTypeDuplicate Block: '<S12>/Data Type Duplicate1'
   *
   * Regarding '<S12>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* end of Outputs for SubSystem: '<Root>/F03_Coefficient_atmospheric_to_boost_slop_correction' */

  /* Outputs for atomic SubSystem: '<Root>/F04_Slop_correction_calculation' *
   * Block requirements for '<Root>/F04_Slop_correction_calculation':
   *  1. SubSystem "F04_Slop_correction_calculation" !Trace_To : VEMS_R_11_04467_071.01 ;
   */

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  localDivide = ((Float32)AFA_facCorAtmSlopEfc) * 3.051757813E-005F;

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  localMinMax1 = ((Float32)AFA_facCorBoostSlopEfc) * 3.051757813E-005F;

  /* DataTypeConversion: '<S4>/Data Type Conversion2' */
  localDataTypeConversion2 = ((Float32)AFA_facChgCorSlopEfc) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S4>/Data Type Conversion3' */
  localDataTypeConversion3_p = ((Float32)AFA_facChgCorGrdSlopEfc_agCkIn) *
    1.525878906E-005F;

  /* Product: '<S4>/Product' incorporates:
   *  Product: '<S4>/Product5'
   *  Sum: '<S4>/Sum1'
   */
  localProduct = ((localDivide * localMinMax1) - localDivide) *
    localDataTypeConversion2;

  /* Product: '<S4>/Product2' */
  localProduct6 = (Float32)((((Float32d)AFA_facCorBoostGrdSlopEfc_agCkIn) *
    3.0517578125000002E-006F) * ((Float32d)localDataTypeConversion2));

  /* Sum: '<S4>/Sum3' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S4>/Product4'
   *  Sum: '<S4>/Sum2'
   */
  localDataTypeConversion2 = ((localMinMax1 * localDataTypeConversion2) -
    localDataTypeConversion2) + 1.0F;

  /* Sum: '<S4>/Sum' */
  localtmp = ACTEMS_LdexpF((Float32d)(localDivide + localProduct), 15);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      AFA_facCorSlopEfc = (UInt16)localtmp;
    } else {
      AFA_facCorSlopEfc = 0U;
    }
  } else {
    AFA_facCorSlopEfc = MAX_uint16_T;
  }

  /* Sum: '<S4>/Sum6' incorporates:
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product3'
   *  Product: '<S4>/Product6'
   *  Sum: '<S4>/Sum4'
   *  Sum: '<S4>/Sum5'
   */
  localqY = (SInt32)ACTEMS_FloorF((((Float32d)(((((localMinMax1 *
    localDataTypeConversion3_p) + localProduct6) - localDataTypeConversion3_p) *
    localDivide) + ((Float32)((((Float32d)AFA_facCorAtmGrdSlopEfc_agCkIn) *
    3.0517578125000002E-006F) * ((Float32d)localDataTypeConversion2))))) /
    3.0517578125000002E-006F) + 0.5F);
  if (localqY < 32768) {
    if (localqY >= -32768) {
      AFA_facCorSlopGrdEfc_agCkIn = (SInt16)localqY;
    } else {
      AFA_facCorSlopGrdEfc_agCkIn = MIN_int16_T;
    }
  } else {
    AFA_facCorSlopGrdEfc_agCkIn = MAX_int16_T;
  }

  /* end of Outputs for SubSystem: '<Root>/F04_Slop_correction_calculation' */

  /* SignalConversion: '<Root>/Signal Conversion' */
  (*rty_AFA_facCorSlopEfc) = AFA_facCorSlopEfc;

  /* SignalConversion: '<Root>/Signal Conversion1' */
  (*rty_AFA_facCorSlopGrdEfc_agCkIn) = AFA_facCorSlopGrdEfc_agCkIn;
}

/* Model initialize function */
void mr_AFA_F03_Slop_corr_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
