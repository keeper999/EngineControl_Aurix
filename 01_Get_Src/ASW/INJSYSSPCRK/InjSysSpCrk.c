/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSysSpCrk                                             */
/* !Description     : InjSysSpCrk : INJECTION SETPOINTS FOR START             */
/*                                                                            */
/* !Module          : InjSysSpCrk                                             */
/*                                                                            */
/* !File            : InjSysSpCrk.c                                           */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : PTS_DOC_5051193 / 01                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Feb 14 12:28:19 2013                              */
/*   Model name       : InjSysSpCrk_AUTOCODE.mdl                              */
/*   Model version    : 1.113                                                 */
/*   Root subsystem   : /InjSysSpCrk                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJSYSSPCRK/InjSysSpCrk.c_$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjSysSpCrk.h"
#include "InjSysSpCrk_private.h"

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
#define INJSYSSPCRK_START_SEC_VAR_UNSPECIFIED
#include "InjSysSpCrk_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InjSysSpCrk InjSysSpCrk_B;

#define INJSYSSPCRK_STOP_SEC_VAR_UNSPECIFIED
#include "InjSysSpCrk_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define INJSYSSPCRK_START_SEC_CODE
#include "InjSysSpCrk_MemMap.h"

void InjSysSpCrk_ASYNC1(int controlPortIdx)
{
}

void InjSysSpCrk_ASYNC2(int controlPortIdx)
{
  InjSysSpCrk_F01_AuthFrstInjAdap();
  InjSysSpCrk_F01_InjPhaClcn();
  InjSysSpCrk_F02_rInjSpClcn();
}

void InjSysSpCrk_ASYNC4(int controlPortIdx)
{
  InjSysSpCrk_F03_PfurailClcn();
}

/* Output and update for function-call system: '<S6>/F00_Init' */
void InjSysSpCrk_F00_Init(void)
{
  /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET */
  VEMS_vidSET(InjSys_bAcvFrstInjSp, TRUE);
}

/* Output and update for exported function: InjSys_EveRst_InjSysSpCrk */
void InjSys_EveRst_InjSysSpCrk(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S6>/F00_Init'
   */
  InjSysSpCrk_F00_Init();
}

/* Output and update for function-call system: '<S1>/F03_PfurailClcn' */
void InjSysSpCrk_F03_PfurailClcn(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion1;
  UInt16 localDataTypeConversion1_l;
  UInt16 localDataTypeConversion1_lo;
  UInt16 localDataTypeConversion1_e;
  UInt16 localDataTypeConversion1_d;
  UInt16 localDataTypeConversion1_b;
  UInt16 localDataTypeConversion1_m;
  UInt16 localDataTypeConversion1_bs;
  UInt16 localDataTypeConversion1_ej;
  UInt16 localDataTypeConversion1_f;
  UInt16 localLookUpTable2D;
  UInt16 localLookUpTable2D_m;
  UInt16 localLookUpTable2D_l;
  UInt16 localLookUpTable2D_j;
  UInt16 localLookUpTable2D_c;
  UInt16 localLookUpTable2D_p;
  UInt16 localLookUpTable2D_pp;
  UInt16 localLookUpTable2D_a;
  UInt16 localLookUpTable2D_b;
  UInt16 localLookUpTable2D_h;
  UInt8 localDataTypeConversion;
  UInt8 localDataTypeConversion_a;
  UInt8 localDataTypeConversion_o;
  UInt8 localDataTypeConversion_d;
  UInt8 localDataTypeConversion_o5;
  UInt8 localDataTypeConversion_dv;
  UInt8 localDataTypeConversion_p;
  UInt8 localDataTypeConversion_i;
  UInt8 localDataTypeConversion_g;
  UInt8 localDataTypeConversion_d4;
  SInt32 localtmp;

  /* Outputs for enable SubSystem: '<S9>/F03_PfurailClcn_Inhib' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/INJSYSSPCRK_u8Inhib'
   *  EnablePort: '<S172>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (INJSYSSPCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S172>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_tCoMes, InjSysSpCrk_B.VEMS_vidGET3_g);

    /* S-Function "vems_vidGET" Block: <S172>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_nEngLoResl, InjSysSpCrk_B.VEMS_vidGET2_g);

    /* S-Function "vems_vidGET" Block: <S172>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjSysSpCrk_B.VEMS_vidGET1_eo);

    /* S-Function "vems_vidGET" Block: <S172>/VEMS_vidGET */
    VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, InjSysSpCrk_B.VEMS_vidGET_a4);

    /* S-Function "vems_vidGET" Block: <S172>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_bAcvHPst, InjSysSpCrk_B.VEMS_vidGET4_b);

    /* S-Function "vems_vidGET" Block: <S172>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_bAcvInjModH, InjSysSpCrk_B.VEMS_vidGET5_o);

    /* Outputs for enable SubSystem: '<S172>/F01_ModHPrail' incorporates:
     *  EnablePort: '<S173>/InjSys_bAcvInjModH'
     */
    if (InjSysSpCrk_B.VEMS_vidGET5_o) {
      /* If: '<S173>/If3' incorporates:
       *  ActionPort: '<S176>/Action Port'
       *  ActionPort: '<S177>/Action Port'
       *  Logic: '<S173>/Logical Operator3'
       *  SubSystem: '<S173>/F01_ModHSTT'
       *  SubSystem: '<S173>/F02_ModHWoSTT'
       */
      if (InjSysSpCrk_B.VEMS_vidGET1_eo || InjSysSpCrk_B.VEMS_vidGET_a4) {
        /* DataTypeConversion: '<S178>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_p = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_p = MAX_uint8_T;
        } else {
          localDataTypeConversion_p = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S178>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_m = MAX_uint16_T;
        } else {
          localDataTypeConversion1_m = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S178>/Look-Up Table (2-D)'
         * About '<S178>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_pp),
                          (&(InjSys_pFuCrkSpModHCrkSTT_M[0])),
                          localDataTypeConversion_p, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_m, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S178>/Data Type Duplicate2'
         *
         * Regarding '<S178>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S179>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_i = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_i = MAX_uint8_T;
        } else {
          localDataTypeConversion_i = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S179>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_bs = MAX_uint16_T;
        } else {
          localDataTypeConversion1_bs = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S179>/Look-Up Table (2-D)'
         * About '<S179>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_a),
                          (&(InjSys_pFuCrkSpModHLPCrkSTT_M[0])),
                          localDataTypeConversion_i, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_bs, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S179>/Data Type Duplicate2'
         *
         * Regarding '<S179>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S176>/Switch2' incorporates:
         *  Lookup2D: '<S178>/Look-Up Table (2-D)'
         *  Lookup2D: '<S179>/Look-Up Table (2-D)'
         *  SignalConversion: '<S176>/Signal Conversion1'
         */
        if (InjSysSpCrk_B.VEMS_vidGET4_b) {
          InjSysSpCrk_B.Merge_m = localLookUpTable2D_pp;
        } else {
          InjSysSpCrk_B.Merge_m = localLookUpTable2D_a;
        }
      } else {
        /* DataTypeConversion: '<S180>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_o5 = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_o5 = MAX_uint8_T;
        } else {
          localDataTypeConversion_o5 = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S180>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_d = MAX_uint16_T;
        } else {
          localDataTypeConversion1_d = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S180>/Look-Up Table (2-D)'
         * About '<S180>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_c), (&(InjSys_pFuCrkSpModHCrk_M
          [0])), localDataTypeConversion_o5, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_d, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S180>/Data Type Duplicate2'
         *
         * Regarding '<S180>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S181>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_dv = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_dv = MAX_uint8_T;
        } else {
          localDataTypeConversion_dv = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S181>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_b = MAX_uint16_T;
        } else {
          localDataTypeConversion1_b = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S181>/Look-Up Table (2-D)'
         * About '<S181>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_p),
                          (&(InjSys_pFuCrkSpModHLPCrk_M[0])),
                          localDataTypeConversion_dv, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_b, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S181>/Data Type Duplicate2'
         *
         * Regarding '<S181>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S177>/Switch2' incorporates:
         *  Lookup2D: '<S180>/Look-Up Table (2-D)'
         *  Lookup2D: '<S181>/Look-Up Table (2-D)'
         *  SignalConversion: '<S177>/Signal Conversion1'
         */
        if (InjSysSpCrk_B.VEMS_vidGET4_b) {
          InjSysSpCrk_B.Merge_m = localLookUpTable2D_c;
        } else {
          InjSysSpCrk_B.Merge_m = localLookUpTable2D_p;
        }
      }
    }

    /* end of Outputs for SubSystem: '<S172>/F01_ModHPrail' */
    /* S-Function "vems_vidGET" Block: <S172>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bAcvInjModSplst, InjSysSpCrk_B.VEMS_vidGET6_h);

    /* Outputs for enable SubSystem: '<S172>/F02_SplitStrtPrail' incorporates:
     *  EnablePort: '<S174>/InjSys_bAcvInjModSplst'
     */
    if (InjSysSpCrk_B.VEMS_vidGET6_h) {
      /* If: '<S174>/If3' incorporates:
       *  ActionPort: '<S182>/Action Port'
       *  ActionPort: '<S183>/Action Port'
       *  Logic: '<S174>/Logical Operator3'
       *  SubSystem: '<S174>/F01_SplitStrtPrailSTT'
       *  SubSystem: '<S174>/F02_SplitStrtPrailWoSTT'
       */
      if (InjSysSpCrk_B.VEMS_vidGET1_eo || InjSysSpCrk_B.VEMS_vidGET_a4) {
        /* DataTypeConversion: '<S184>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_o = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_o = MAX_uint8_T;
        } else {
          localDataTypeConversion_o = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S184>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_lo = MAX_uint16_T;
        } else {
          localDataTypeConversion1_lo = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S184>/Look-Up Table (2-D)'
         * About '<S184>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_l),
                          (&(InjSys_pFuCrkSpModSplstLPSTT_M[0])),
                          localDataTypeConversion_o, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_lo, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S184>/Data Type Duplicate2'
         *
         * Regarding '<S184>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S185>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_d = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_d = MAX_uint8_T;
        } else {
          localDataTypeConversion_d = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S185>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_e = MAX_uint16_T;
        } else {
          localDataTypeConversion1_e = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S185>/Look-Up Table (2-D)'
         * About '<S185>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_j),
                          (&(InjSys_pFuCrkSpModSplstSTT_M[0])),
                          localDataTypeConversion_d, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_e, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S185>/Data Type Duplicate2'
         *
         * Regarding '<S185>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S182>/Switch2' incorporates:
         *  Lookup2D: '<S184>/Look-Up Table (2-D)'
         *  Lookup2D: '<S185>/Look-Up Table (2-D)'
         *  SignalConversion: '<S182>/Signal Conversion1'
         */
        if (InjSysSpCrk_B.VEMS_vidGET4_b) {
          InjSysSpCrk_B.Merge_m = localLookUpTable2D_j;
        } else {
          InjSysSpCrk_B.Merge_m = localLookUpTable2D_l;
        }
      } else {
        /* DataTypeConversion: '<S186>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion = MAX_uint8_T;
        } else {
          localDataTypeConversion = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S186>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1 = MAX_uint16_T;
        } else {
          localDataTypeConversion1 = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S186>/Look-Up Table (2-D)'
         * About '<S186>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D),
                          (&(InjSys_pFuCrkSpModSplstLP_M[0])),
                          localDataTypeConversion, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S186>/Data Type Duplicate2'
         *
         * Regarding '<S186>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S187>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_a = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_a = MAX_uint8_T;
        } else {
          localDataTypeConversion_a = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S187>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_l = MAX_uint16_T;
        } else {
          localDataTypeConversion1_l = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S187>/Look-Up Table (2-D)'
         * About '<S187>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_m),
                          (&(InjSys_pFuCrkSpModSplst_M[0])),
                          localDataTypeConversion_a, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_l, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S187>/Data Type Duplicate2'
         *
         * Regarding '<S187>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S183>/Switch2' incorporates:
         *  Lookup2D: '<S186>/Look-Up Table (2-D)'
         *  Lookup2D: '<S187>/Look-Up Table (2-D)'
         *  SignalConversion: '<S183>/Signal Conversion1'
         */
        if (InjSysSpCrk_B.VEMS_vidGET4_b) {
          InjSysSpCrk_B.Merge_m = localLookUpTable2D_m;
        } else {
          InjSysSpCrk_B.Merge_m = localLookUpTable2D;
        }
      }
    }

    /* end of Outputs for SubSystem: '<S172>/F02_SplitStrtPrail' */
    /* S-Function "vems_vidGET" Block: <S172>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_bAcvInjModSst, InjSysSpCrk_B.VEMS_vidGET7_k);

    /* Outputs for enable SubSystem: '<S172>/F03_SStrtPrail' incorporates:
     *  EnablePort: '<S175>/InjSys_bAcvInjModSst'
     */
    if (InjSysSpCrk_B.VEMS_vidGET7_k) {
      /* If: '<S175>/If3' incorporates:
       *  ActionPort: '<S188>/Action Port'
       *  ActionPort: '<S189>/Action Port'
       *  Logic: '<S175>/Logical Operator3'
       *  SubSystem: '<S175>/F01_SStrtPrailSTT'
       *  SubSystem: '<S175>/F02_SStrtPrailWoSTT'
       */
      if (InjSysSpCrk_B.VEMS_vidGET1_eo || InjSysSpCrk_B.VEMS_vidGET_a4) {
        /* DataTypeConversion: '<S190>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_d4 = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_d4 = MAX_uint8_T;
        } else {
          localDataTypeConversion_d4 = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S190>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_f = MAX_uint16_T;
        } else {
          localDataTypeConversion1_f = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S190>/Look-Up Table (2-D)'
         * About '<S190>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_h),
                          (&(InjSys_pFuCrkSpModSstSTT_M[0])),
                          localDataTypeConversion_d4, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_f, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S190>/Data Type Duplicate2'
         *
         * Regarding '<S190>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* SignalConversion: '<S188>/Signal Conversion1' */
        InjSysSpCrk_B.Merge_m = localLookUpTable2D_h;
      } else {
        /* DataTypeConversion: '<S191>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET3_g + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_g = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_g = MAX_uint8_T;
        } else {
          localDataTypeConversion_g = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S191>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2_g > 2047) {
          localDataTypeConversion1_ej = MAX_uint16_T;
        } else {
          localDataTypeConversion1_ej = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2_g <<
            5);
        }

        /* Lookup2D: '<S191>/Look-Up Table (2-D)'
         * About '<S191>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_b), (&(InjSys_pFuCrkSpModSst_M[0])),
                          localDataTypeConversion_g, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_ej, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S191>/Data Type Duplicate2'
         *
         * Regarding '<S191>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* SignalConversion: '<S189>/Signal Conversion1' */
        InjSysSpCrk_B.Merge_m = localLookUpTable2D_b;
      }
    }

    /* end of Outputs for SubSystem: '<S172>/F03_SStrtPrail' */
    /* S-Function "vems_vidSET" Block: <S172>/VEMS_vidSET */
    VEMS_vidSET(InjSys_pFuCrkSp, InjSysSpCrk_B.Merge_m);
  }

  /* end of Outputs for SubSystem: '<S9>/F03_PfurailClcn_Inhib' */
}

/* Output and update for exported function: InjSys_EveSpl_InjSysSpCrk */
void InjSys_EveSpl_InjSysSpCrk(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' */
  InjSysSpCrk_ASYNC4(1);
}

/* Output and update for function-call system: '<S6>/F01_AuthFrstInjAdap' */
void InjSysSpCrk_F01_AuthFrstInjAdap(void)
{
  Boolean localLogicalOperator1;
  Boolean localLogicalOperator2;

  /* Outputs for enable SubSystem: '<S13>/F01_AuthFrstInjAdap_Inhib' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/INJSYSSPCRK_u8Inhib'
   *  EnablePort: '<S14>/Enable'
   *  RelationalOperator: '<S13>/Relational Operator'
   */
  if (INJSYSSPCRK_u8Inhib != 90) {
    /* Logic: '<S14>/Logical Operator1' incorporates:
     *  Constant: '<S14>/InjSys_bInhFrstInjSp_C'
     */
    localLogicalOperator1 = !InjSys_bInhFrstInjSp_C;

    /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjSysSpCrk_B.VEMS_vidGET_i);

    /* Logic: '<S14>/Logical Operator2' */
    localLogicalOperator2 = !InjSysSpCrk_B.VEMS_vidGET_i;

    /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET1 */
    VEMS_vidGET(InjSys_bAcvHPst, InjSysSpCrk_B.VEMS_vidGET1_b);

    /* S-Function "vems_vidGET" Block: <S14>/VEMS_vidGET2 */
    VEMS_vidGET(InjSys_bInhInjHPst, InjSysSpCrk_B.VEMS_vidGET2_b);

    /* Logic: '<S14>/Logical Operator7' */
    InjSysSpCrk_B.LogicalOperator7 = (((InjSysSpCrk_B.VEMS_vidGET1_b &&
      InjSysSpCrk_B.VEMS_vidGET2_b) && (localLogicalOperator1)) &&
      (localLogicalOperator2));

    /* S-Function "vems_vidSET" Block: <S14>/VEMS_vidSET */
    VEMS_vidSET(InjSys_bAcvFrstInjSp, InjSysSpCrk_B.LogicalOperator7);
  }

  /* end of Outputs for SubSystem: '<S13>/F01_AuthFrstInjAdap_Inhib' */
}

/* Output and update for function-call system: '<S1>/F01_InjPhaClcn' */
void InjSysSpCrk_F01_InjPhaClcn(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion1_i;
  UInt16 localDataTypeConversion1_lg;
  UInt16 localDataTypeConversion1_g;
  UInt16 localDataTypeConversion1_fb;
  UInt16 localDataTypeConversion1_o;
  UInt16 localDataTypeConversion1_my;
  UInt16 localDataTypeConversion1_ea;
  UInt16 localDataTypeConversion1_j;
  UInt16 localDataTypeConversion1_ix;
  UInt16 localDataTypeConversion1_c;
  UInt16 localLookUpTable2D_ba;
  UInt16 localLookUpTable2D_h1;
  UInt16 localLookUpTable2D_hi;
  UInt16 localLookUpTable2D_mu;
  UInt16 localLookUpTable2D_f;
  UInt16 localLookUpTable2D_o;
  UInt16 localLookUpTable2D_k;
  UInt16 localLookUpTable2D_i;
  UInt16 localLookUpTable2D_lm;
  UInt16 localLookUpTable2D_n;
  UInt16 localLookUpTable2D_in;
  UInt16 localLookUpTable2D_cb;
  UInt16 localLookUpTable2D_pq;
  UInt16 localLookUpTable2D_pr;
  UInt16 localLookUpTable2D_pi;
  UInt16 localLookUpTable2D_ik;
  UInt16 localLookUpTable2D_bm;
  UInt16 localLookUpTable2D_k2;
  UInt16 localLookUpTable2D_hs;
  UInt16 localLookUpTable2D_mq;
  UInt16 localLookUpTable2D_jf;
  UInt16 localLookUpTable2D_lx;
  UInt16 localLookUpTable2D_g;
  UInt16 localLookUpTable2D_oz;
  UInt16 localLookUpTable2D_n2;
  UInt16 localLookUpTable2D_e;
  UInt16 localLookUpTable2D_e4;
  UInt16 localLookUpTable2D_af;
  UInt16 localLookUpTable2D_cy;
  UInt8 localDataTypeConversion_k;
  UInt8 localDataTypeConversion_j;
  UInt8 localDataTypeConversion_kt;
  UInt8 localDataTypeConversion_l;
  UInt8 localDataTypeConversion_go;
  UInt8 localDataTypeConversion_iz;
  UInt8 localDataTypeConversion_js;
  UInt8 localDataTypeConversion_h;
  UInt8 localDataTypeConversion_hn;
  UInt8 localDataTypeConversion_hu;
  UInt16 localSwitch2_h;
  UInt16 locallocalSwitch1_b_idx;
  UInt16 locallocalSwitch1_b_idx_0;
  SInt32 localtmp;

  /* Outputs for enable SubSystem: '<S7>/F01_InjPhaClcn_Inhib' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/INJSYSSPCRK_u8Inhib'
   *  EnablePort: '<S15>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (INJSYSSPCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_tCoMes, InjSysSpCrk_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_nEngLoResl, InjSysSpCrk_B.VEMS_vidGET3_n);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET2 */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjSysSpCrk_B.VEMS_vidGET2_a);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET1 */
    VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, InjSysSpCrk_B.VEMS_vidGET1_e);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_bAcvHPst, InjSysSpCrk_B.VEMS_vidGET5_i);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET */
    VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd, InjSysSpCrk_B.VEMS_vidGET_a);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bAcvInjModH, InjSysSpCrk_B.VEMS_vidGET6_e);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET9 */
    VEMS_vidGET(InjSys_bAcvFrstInjSp, InjSysSpCrk_B.VEMS_vidGET9);

    /* Outputs for enable SubSystem: '<S15>/F01_HomAg' incorporates:
     *  EnablePort: '<S16>/InjSys_bAcvInjModH'
     *  Logic: '<S15>/Logical Operator2'
     *  Logic: '<S15>/Logical Operator3'
     *
     * Block requirements for '<S15>/F01_HomAg':
     *  1. SubSystem "F01_HomAg" !Trace_To : VEMS_E_11_01572_004.01 ;
     */
    if (InjSysSpCrk_B.VEMS_vidGET6_e && (!InjSysSpCrk_B.VEMS_vidGET9)) {
      /* If: '<S16>/If5' incorporates:
       *  ActionPort: '<S20>/Action Port'
       *  ActionPort: '<S21>/Action Port'
       *  Logic: '<S16>/Logical Operator3'
       *  SubSystem: '<S16>/F01_HomCrkAgSTT'
       *  SubSystem: '<S16>/F02_HomCrkAgWoSTT'
       */
      if (InjSysSpCrk_B.VEMS_vidGET2_a || InjSysSpCrk_B.VEMS_vidGET1_e) {
        /* DataTypeConversion: '<S22>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_l = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_l = MAX_uint8_T;
        } else {
          localDataTypeConversion_l = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S22>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_fb = MAX_uint16_T;
        } else {
          localDataTypeConversion1_fb = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S22>/Look-Up Table (2-D)'
         * About '<S22>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_mu),
                          (&(InjSys_agBegInj1ModHBasCrkSTT_M[0])),
                          localDataTypeConversion_l, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_fb, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate2'
         *
         * Regarding '<S22>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S23>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_go = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_go = MAX_uint8_T;
        } else {
          localDataTypeConversion_go = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S23>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_o = MAX_uint16_T;
        } else {
          localDataTypeConversion1_o = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S23>/Look-Up Table (2-D)'
         * About '<S23>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_f),
                          (&(InjSys_agBegInj1ModHLPCrkSTT_M[0])),
                          localDataTypeConversion_go, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_o, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate2'
         *
         * Regarding '<S23>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S20>/Switch2' incorporates:
         *  Lookup2D: '<S22>/Look-Up Table (2-D)'
         *  Lookup2D: '<S23>/Look-Up Table (2-D)'
         */
        if (InjSysSpCrk_B.VEMS_vidGET5_i) {
          InjSysSpCrk_B.Merge = localLookUpTable2D_mu;
        } else {
          InjSysSpCrk_B.Merge = localLookUpTable2D_f;
        }
      } else {
        /* DataTypeConversion: '<S24>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_k = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_k = MAX_uint8_T;
        } else {
          localDataTypeConversion_k = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S24>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_i = MAX_uint16_T;
        } else {
          localDataTypeConversion1_i = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S24>/Look-Up Table (2-D)'
         * About '<S24>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_ba),
                          (&(InjSys_agBegInj1ModHBasCrk_M[0])),
                          localDataTypeConversion_k, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_i, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S24>/Data Type Duplicate2'
         *
         * Regarding '<S24>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S25>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_j = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_j = MAX_uint8_T;
        } else {
          localDataTypeConversion_j = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S25>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_lg = MAX_uint16_T;
        } else {
          localDataTypeConversion1_lg = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S25>/Look-Up Table (2-D)'
         * About '<S25>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_h1),
                          (&(InjSys_agBegInj1ModHIntrSTT_M[0])),
                          localDataTypeConversion_j, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_lg, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S25>/Data Type Duplicate2'
         *
         * Regarding '<S25>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S26>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_kt = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_kt = MAX_uint8_T;
        } else {
          localDataTypeConversion_kt = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S26>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_g = MAX_uint16_T;
        } else {
          localDataTypeConversion1_g = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S26>/Look-Up Table (2-D)'
         * About '<S26>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_hi),
                          (&(InjSys_agBegInj1ModHLPCrk_M[0])),
                          localDataTypeConversion_kt, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_g, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S26>/Data Type Duplicate2'
         *
         * Regarding '<S26>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S21>/Switch2' incorporates:
         *  Lookup2D: '<S24>/Look-Up Table (2-D)'
         *  Lookup2D: '<S26>/Look-Up Table (2-D)'
         */
        if (InjSysSpCrk_B.VEMS_vidGET5_i) {
          localSwitch2_h = localLookUpTable2D_ba;
        } else {
          localSwitch2_h = localLookUpTable2D_hi;
        }

        /* Switch: '<S21>/Switch1' incorporates:
         *  Logic: '<S21>/Logical Operator3'
         *  Lookup2D: '<S25>/Look-Up Table (2-D)'
         */
        if (!InjSysSpCrk_B.VEMS_vidGET_a) {
          InjSysSpCrk_B.Merge = localSwitch2_h;
        } else {
          InjSysSpCrk_B.Merge = localLookUpTable2D_h1;
        }
      }

      /* SignalConversion: '<S16>/Signal Conversion5' incorporates:
       *  Constant: '<S16>/InjSys_agInj2CrkSpDft_C'
       */
      InjSysSpCrk_B.Merge1 = InjSys_agInj2CrkSpDft_C;

      /* SignalConversion: '<S16>/Signal Conversion1' incorporates:
       *  Constant: '<S16>/InjSys_agInj3CrkSpDft_C'
       */
      InjSysSpCrk_B.Merge2 = InjSys_agInj3CrkSpDft_C;
    }

    /* end of Outputs for SubSystem: '<S15>/F01_HomAg' */
    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_bAcvInjModSplst, InjSysSpCrk_B.VEMS_vidGET7_b);

    /* Outputs for enable SubSystem: '<S15>/F02_SplitStrtAg' incorporates:
     *  EnablePort: '<S17>/InjSys_bAcvInjModSplst'
     *  Logic: '<S15>/Logical Operator4'
     *  Logic: '<S15>/Logical Operator5'
     */
    if (InjSysSpCrk_B.VEMS_vidGET7_b && (!InjSysSpCrk_B.VEMS_vidGET9)) {
      /* If: '<S17>/If3' incorporates:
       *  ActionPort: '<S27>/Action Port'
       *  ActionPort: '<S28>/Action Port'
       *  Logic: '<S17>/Logical Operator3'
       *  SubSystem: '<S17>/F01_SplitStrtAgSTT'
       *  SubSystem: '<S17>/F02_SplitAgStrtWoSTT'
       */
      if (InjSysSpCrk_B.VEMS_vidGET2_a || InjSysSpCrk_B.VEMS_vidGET1_e) {
        /* DataTypeConversion: '<S29>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hn = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hn = MAX_uint8_T;
        } else {
          localDataTypeConversion_hn = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S29>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_ix = MAX_uint16_T;
        } else {
          localDataTypeConversion1_ix = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S29>/Look-Up Table (2-D)'
         * About '<S29>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_oz),
                          (&(InjSys_agEndInj3ModSplstBasSTT_M[0])),
                          localDataTypeConversion_hn, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_ix, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate2'
         *
         * Regarding '<S29>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S30>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hn = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hn = MAX_uint8_T;
        } else {
          localDataTypeConversion_hn = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S30>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_ix = MAX_uint16_T;
        } else {
          localDataTypeConversion1_ix = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S30>/Look-Up Table (2-D)'
         * About '<S30>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_n2),
                          (&(InjSys_agEndInj3ModSplstLPSTT_M[0])),
                          localDataTypeConversion_hn, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_ix, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S30>/Data Type Duplicate2'
         *
         * Regarding '<S30>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S31>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hn = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hn = MAX_uint8_T;
        } else {
          localDataTypeConversion_hn = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S31>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_ix = MAX_uint16_T;
        } else {
          localDataTypeConversion1_ix = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S31>/Look-Up Table (2-D)'
         * About '<S31>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_e),
                          (&(InjSys_agBegInj1ModSplstBasSTT_M[0])),
                          localDataTypeConversion_hn, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_ix, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate2'
         *
         * Regarding '<S31>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S32>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hn = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hn = MAX_uint8_T;
        } else {
          localDataTypeConversion_hn = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S32>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_ix = MAX_uint16_T;
        } else {
          localDataTypeConversion1_ix = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S32>/Look-Up Table (2-D)'
         * About '<S32>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_e4),
                          (&(InjSys_agBegInj1ModSplstLPSTT_M[0])),
                          localDataTypeConversion_hn, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_ix, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate2'
         *
         * Regarding '<S32>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S33>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hn = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hn = MAX_uint8_T;
        } else {
          localDataTypeConversion_hn = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S33>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_ix = MAX_uint16_T;
        } else {
          localDataTypeConversion1_ix = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S33>/Look-Up Table (2-D)'
         * About '<S33>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_af),
                          (&(InjSys_agBegInj2ModSplstBasSTT_M[0])),
                          localDataTypeConversion_hn, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_ix, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S33>/Data Type Duplicate2'
         *
         * Regarding '<S33>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S34>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hn = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hn = MAX_uint8_T;
        } else {
          localDataTypeConversion_hn = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S34>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_ix = MAX_uint16_T;
        } else {
          localDataTypeConversion1_ix = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S34>/Look-Up Table (2-D)'
         * About '<S34>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_cy),
                          (&(InjSys_agBegInj2ModSplstLPSTT_M[0])),
                          localDataTypeConversion_hn, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_ix, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate2'
         *
         * Regarding '<S34>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S27>/Switch2' incorporates:
         *  SignalConversion: '<S27>/Signal Conversion1'
         *  SignalConversion: '<S27>/Signal Conversion2'
         *  SignalConversion: '<S27>/Signal Conversion5'
         */
        if (InjSysSpCrk_B.VEMS_vidGET5_i) {
          InjSysSpCrk_B.Merge = localLookUpTable2D_e;
          InjSysSpCrk_B.Merge1 = localLookUpTable2D_af;
          InjSysSpCrk_B.Merge2 = localLookUpTable2D_oz;
        } else {
          InjSysSpCrk_B.Merge = localLookUpTable2D_e4;
          InjSysSpCrk_B.Merge1 = localLookUpTable2D_cy;
          InjSysSpCrk_B.Merge2 = localLookUpTable2D_n2;
        }
      } else {
        /* DataTypeConversion: '<S35>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S35>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S35>/Look-Up Table (2-D)'
         * About '<S35>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_pi),
                          (&(InjSys_agBegInj1ModSplIntrSTT_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate2'
         *
         * Regarding '<S35>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S36>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S36>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S36>/Look-Up Table (2-D)'
         * About '<S36>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_ik),
                          (&(InjSys_agBegInj1ModSplstBas_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate2'
         *
         * Regarding '<S36>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S37>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S37>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S37>/Look-Up Table (2-D)'
         * About '<S37>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_bm),
                          (&(InjSys_agBegInj1ModSplstLP_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate2'
         *
         * Regarding '<S37>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S38>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S38>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S38>/Look-Up Table (2-D)'
         * About '<S38>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_k2),
                          (&(InjSys_agBegInj2ModSplIntrSTT_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S38>/Data Type Duplicate2'
         *
         * Regarding '<S38>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S39>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S39>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S39>/Look-Up Table (2-D)'
         * About '<S39>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_hs),
                          (&(InjSys_agBegInj2ModSplstBas_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S39>/Data Type Duplicate2'
         *
         * Regarding '<S39>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S40>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S40>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S40>/Look-Up Table (2-D)'
         * About '<S40>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_mq),
                          (&(InjSys_agBegInj2ModSplstLP_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S40>/Data Type Duplicate2'
         *
         * Regarding '<S40>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S41>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S41>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S41>/Look-Up Table (2-D)'
         * About '<S41>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_jf),
                          (&(InjSys_agEndInj3ModSplIntrSTT_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S41>/Data Type Duplicate2'
         *
         * Regarding '<S41>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S42>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S42>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S42>/Look-Up Table (2-D)'
         * About '<S42>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_lx),
                          (&(InjSys_agEndInj3ModSplstBas_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S42>/Data Type Duplicate2'
         *
         * Regarding '<S42>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S43>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_hu = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_hu = MAX_uint8_T;
        } else {
          localDataTypeConversion_hu = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S43>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_c = MAX_uint16_T;
        } else {
          localDataTypeConversion1_c = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S43>/Look-Up Table (2-D)'
         * About '<S43>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_g),
                          (&(InjSys_agEndInj3ModSplstLP_M[0])),
                          localDataTypeConversion_hu, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_c, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S43>/Data Type Duplicate2'
         *
         * Regarding '<S43>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S28>/Switch2' */
        if (InjSysSpCrk_B.VEMS_vidGET5_i) {
          localSwitch2_h = localLookUpTable2D_ik;
          locallocalSwitch1_b_idx = localLookUpTable2D_hs;
          locallocalSwitch1_b_idx_0 = localLookUpTable2D_lx;
        } else {
          localSwitch2_h = localLookUpTable2D_bm;
          locallocalSwitch1_b_idx = localLookUpTable2D_mq;
          locallocalSwitch1_b_idx_0 = localLookUpTable2D_g;
        }

        /* Switch: '<S28>/Switch1' incorporates:
         *  Logic: '<S28>/Logical Operator3'
         */
        if (InjSysSpCrk_B.VEMS_vidGET_a) {
          localSwitch2_h = localLookUpTable2D_pi;
          locallocalSwitch1_b_idx = localLookUpTable2D_k2;
          locallocalSwitch1_b_idx_0 = localLookUpTable2D_jf;
        }

        /* SignalConversion: '<S28>/Signal Conversion1' */
        InjSysSpCrk_B.Merge = localSwitch2_h;

        /* SignalConversion: '<S28>/Signal Conversion3' */
        InjSysSpCrk_B.Merge1 = locallocalSwitch1_b_idx;

        /* SignalConversion: '<S28>/Signal Conversion4' */
        InjSysSpCrk_B.Merge2 = locallocalSwitch1_b_idx_0;
      }
    }

    /* end of Outputs for SubSystem: '<S15>/F02_SplitStrtAg' */
    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_bAcvInjModSst, InjSysSpCrk_B.VEMS_vidGET8_d);

    /* Outputs for enable SubSystem: '<S15>/F03_SStrtAg' incorporates:
     *  EnablePort: '<S18>/InjSys_bAcvInjModSst'
     *  Logic: '<S15>/Logical Operator6'
     *  Logic: '<S15>/Logical Operator7'
     */
    if (InjSysSpCrk_B.VEMS_vidGET8_d && (!InjSysSpCrk_B.VEMS_vidGET9)) {
      /* SignalConversion: '<S18>/Signal Conversion1' incorporates:
       *  Constant: '<S18>/InjSys_agInj1CrkSpDft_C'
       */
      InjSysSpCrk_B.Merge = InjSys_agInj1CrkSpDft_C;

      /* If: '<S18>/If3' incorporates:
       *  ActionPort: '<S44>/Action Port'
       *  ActionPort: '<S45>/Action Port'
       *  Logic: '<S18>/Logical Operator3'
       *  SubSystem: '<S18>/F01_SStrtAgSTT'
       *  SubSystem: '<S18>/F02_SStrtAgWoSTT'
       */
      if (InjSysSpCrk_B.VEMS_vidGET2_a || InjSysSpCrk_B.VEMS_vidGET1_e) {
        /* DataTypeConversion: '<S46>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_iz = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_iz = MAX_uint8_T;
        } else {
          localDataTypeConversion_iz = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S46>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_my = MAX_uint16_T;
        } else {
          localDataTypeConversion1_my = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S46>/Look-Up Table (2-D)'
         * About '<S46>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_pq),
                          (&(InjSys_agBegInj2ModSstBasSTT_M[0])),
                          localDataTypeConversion_iz, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_my, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S46>/Data Type Duplicate2'
         *
         * Regarding '<S46>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S47>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_iz = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_iz = MAX_uint8_T;
        } else {
          localDataTypeConversion_iz = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S47>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_my = MAX_uint16_T;
        } else {
          localDataTypeConversion1_my = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S47>/Look-Up Table (2-D)'
         * About '<S47>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_pr),
                          (&(InjSys_agEndInj3ModSstBasSTT_M[0])),
                          localDataTypeConversion_iz, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_my, (&(Ext_nEngRef3_A[0])),
                          8U);

        /* DataTypeDuplicate Block: '<S47>/Data Type Duplicate2'
         *
         * Regarding '<S47>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* SignalConversion: '<S44>/Signal Conversion1' */
        InjSysSpCrk_B.Merge1 = localLookUpTable2D_pq;

        /* SignalConversion: '<S44>/Signal Conversion2' */
        InjSysSpCrk_B.Merge2 = localLookUpTable2D_pr;
      } else {
        /* DataTypeConversion: '<S48>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_h = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_h = MAX_uint8_T;
        } else {
          localDataTypeConversion_h = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S48>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_j = MAX_uint16_T;
        } else {
          localDataTypeConversion1_j = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S48>/Look-Up Table (2-D)'
         * About '<S48>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_lm),
                          (&(InjSys_agBegInj2ModSstBas_M[0])),
                          localDataTypeConversion_h, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_j, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S48>/Data Type Duplicate2'
         *
         * Regarding '<S48>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S49>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_h = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_h = MAX_uint8_T;
        } else {
          localDataTypeConversion_h = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S49>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_j = MAX_uint16_T;
        } else {
          localDataTypeConversion1_j = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S49>/Look-Up Table (2-D)'
         * About '<S49>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_n),
                          (&(InjSys_agBegInj2ModSstIntrSTT_M[0])),
                          localDataTypeConversion_h, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_j, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S49>/Data Type Duplicate2'
         *
         * Regarding '<S49>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S50>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_h = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_h = MAX_uint8_T;
        } else {
          localDataTypeConversion_h = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S50>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_j = MAX_uint16_T;
        } else {
          localDataTypeConversion1_j = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S50>/Look-Up Table (2-D)'
         * About '<S50>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_in),
                          (&(InjSys_agEndInj3ModSstBas_M[0])),
                          localDataTypeConversion_h, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_j, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S50>/Data Type Duplicate2'
         *
         * Regarding '<S50>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S51>/Data Type Conversion' */
        localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
        if (localtmp <= 0) {
          localDataTypeConversion_h = 0U;
        } else if (localtmp > 255) {
          localDataTypeConversion_h = MAX_uint8_T;
        } else {
          localDataTypeConversion_h = (UInt8)localtmp;
        }

        /* DataTypeConversion: '<S51>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
          localDataTypeConversion1_j = MAX_uint16_T;
        } else {
          localDataTypeConversion1_j = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
            5);
        }

        /* Lookup2D: '<S51>/Look-Up Table (2-D)'
         * About '<S51>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localLookUpTable2D_cb),
                          (&(InjSys_agEndInj3ModSstIntrSTT_M[0])),
                          localDataTypeConversion_h, (&(Ext_tCoMes_A[0])), 15U,
                          localDataTypeConversion1_j, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate2'
         *
         * Regarding '<S51>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* Switch: '<S45>/Switch1' incorporates:
         *  Logic: '<S45>/Logical Operator3'
         *  SignalConversion: '<S45>/Signal Conversion1'
         *  SignalConversion: '<S45>/Signal Conversion2'
         */
        if (!InjSysSpCrk_B.VEMS_vidGET_a) {
          InjSysSpCrk_B.Merge1 = localLookUpTable2D_lm;
          InjSysSpCrk_B.Merge2 = localLookUpTable2D_in;
        } else {
          InjSysSpCrk_B.Merge1 = localLookUpTable2D_n;
          InjSysSpCrk_B.Merge2 = localLookUpTable2D_cb;
        }
      }
    }

    /* end of Outputs for SubSystem: '<S15>/F03_SStrtAg' */

    /* Outputs for enable SubSystem: '<S15>/F04_FrstInjAg' incorporates:
     *  EnablePort: '<S19>/InjSys_bAcvFrstInjSp'
     *
     * Block requirements for '<S15>/F04_FrstInjAg':
     *  1. SubSystem "F04_FrstInjAg" !Trace_To : VEMS_E_11_01572_006.01 ;
     */
    if (InjSysSpCrk_B.VEMS_vidGET9) {
      /* DataTypeConversion: '<S52>/Data Type Conversion' */
      localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
      if (localtmp <= 0) {
        localDataTypeConversion_js = 0U;
      } else if (localtmp > 255) {
        localDataTypeConversion_js = MAX_uint8_T;
      } else {
        localDataTypeConversion_js = (UInt8)localtmp;
      }

      /* DataTypeConversion: '<S52>/Data Type Conversion1' */
      if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
        localDataTypeConversion1_ea = MAX_uint16_T;
      } else {
        localDataTypeConversion1_ea = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
          5);
      }

      /* Lookup2D: '<S52>/Look-Up Table (2-D)'
       * About '<S52>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U8  Bias -40.0
       * Input1  Data Type:  Integer        U16
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U8_U16( &(localLookUpTable2D_o), (&(InjSys_agBegInj1FrstInj_M[0])),
                        localDataTypeConversion_js, (&(Ext_tCoMes_A[0])), 15U,
                        localDataTypeConversion1_ea, (&(Ext_nEngRef3_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S52>/Data Type Duplicate2'
       *
       * Regarding '<S52>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S53>/Data Type Conversion' */
      localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
      if (localtmp <= 0) {
        localDataTypeConversion_js = 0U;
      } else if (localtmp > 255) {
        localDataTypeConversion_js = MAX_uint8_T;
      } else {
        localDataTypeConversion_js = (UInt8)localtmp;
      }

      /* DataTypeConversion: '<S53>/Data Type Conversion1' */
      if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
        localDataTypeConversion1_ea = MAX_uint16_T;
      } else {
        localDataTypeConversion1_ea = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
          5);
      }

      /* Lookup2D: '<S53>/Look-Up Table (2-D)'
       * About '<S53>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U8  Bias -40.0
       * Input1  Data Type:  Integer        U16
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U8_U16( &(localLookUpTable2D_k), (&(InjSys_agBegInj2FrstInj_M[0])),
                        localDataTypeConversion_js, (&(Ext_tCoMes_A[0])), 15U,
                        localDataTypeConversion1_ea, (&(Ext_nEngRef3_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate2'
       *
       * Regarding '<S53>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S54>/Data Type Conversion' */
      localtmp = InjSysSpCrk_B.VEMS_vidGET4 + 40;
      if (localtmp <= 0) {
        localDataTypeConversion_js = 0U;
      } else if (localtmp > 255) {
        localDataTypeConversion_js = MAX_uint8_T;
      } else {
        localDataTypeConversion_js = (UInt8)localtmp;
      }

      /* DataTypeConversion: '<S54>/Data Type Conversion1' */
      if (InjSysSpCrk_B.VEMS_vidGET3_n > 2047) {
        localDataTypeConversion1_ea = MAX_uint16_T;
      } else {
        localDataTypeConversion1_ea = (UInt16)(InjSysSpCrk_B.VEMS_vidGET3_n <<
          5);
      }

      /* Lookup2D: '<S54>/Look-Up Table (2-D)'
       * About '<S54>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U8  Bias -40.0
       * Input1  Data Type:  Integer        U16
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U8_U16( &(localLookUpTable2D_i), (&(InjSys_agEndInj3FrstInj_M[0])),
                        localDataTypeConversion_js, (&(Ext_tCoMes_A[0])), 15U,
                        localDataTypeConversion1_ea, (&(Ext_nEngRef3_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate2'
       *
       * Regarding '<S54>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* SignalConversion: '<S19>/Signal Conversion1' */
      InjSysSpCrk_B.Merge = localLookUpTable2D_o;

      /* SignalConversion: '<S19>/Signal Conversion2' */
      InjSysSpCrk_B.Merge1 = localLookUpTable2D_k;

      /* SignalConversion: '<S19>/Signal Conversion3' */
      InjSysSpCrk_B.Merge2 = localLookUpTable2D_i;
    }

    /* end of Outputs for SubSystem: '<S15>/F04_FrstInjAg' */
    /* S-Function "vems_vidSET" Block: <S15>/VEMS_vidSET */
    VEMS_vidSET(InjSys_agInj1CrkSp, InjSysSpCrk_B.Merge);

    /* S-Function "vems_vidSET" Block: <S15>/VEMS_vidSET1 */
    VEMS_vidSET(InjSys_agInj2CrkSp, InjSysSpCrk_B.Merge1);

    /* S-Function "vems_vidSET" Block: <S15>/VEMS_vidSET2 */
    VEMS_vidSET(InjSys_agInj3CrkSp, InjSysSpCrk_B.Merge2);
  }

  /* end of Outputs for SubSystem: '<S7>/F01_InjPhaClcn_Inhib' */
}

/* Output and update for function-call system: '<S1>/F02_rInjSpClcn' */
void InjSysSpCrk_F02_rInjSpClcn(void)
{
  /* local block i/o variables */
  UInt16 localSwitch2_g;
  UInt16 localSwitch2_b;
  UInt16 localSwitch2_ai;
  UInt16 localSwitch2_m;
  UInt16 localSwitch2_h0;
  UInt16 localSwitch2_o;
  UInt16 localSwitch2_an;
  UInt16 localAdd2;
  UInt16 localAdd2_m;
  UInt16 localAdd2_g;
  UInt16 localAdd5;
  UInt16 localAdd2_l;
  UInt16 localSwitch2_hh;
  UInt16 localSwitch2_og;
  UInt16 localSwitch2_l;
  UInt16 localSwitch2_gq;
  UInt16 localSwitch2_gy;
  UInt16 localSwitch_dok;
  UInt16 localSwitch_m;
  UInt8 localDataTypeConversion_ap;
  UInt8 localDataTypeConversion_c;
  UInt8 localDataTypeConversion_jg;
  UInt8 localDataTypeConversion_m;
  UInt8 localDataTypeConversion_b;
  UInt16 localSwitch2_mw;
  UInt32 localAdd6;
  UInt32 localSwitch_d;
  UInt16 localSwitch2_by;
  SInt32 localqY;

  /* Outputs for enable SubSystem: '<S8>/F02_rInjSpClcn_Inhib' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/INJSYSSPCRK_u8Inhib'
   *  EnablePort: '<S55>/Enable'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if (INJSYSSPCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_bAcvInjModH, InjSysSpCrk_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_bAcvFrstInjSp, InjSysSpCrk_B.VEMS_vidGET8);

    /* Outputs for enable SubSystem: '<S55>/F01_HomFrac' incorporates:
     *  EnablePort: '<S56>/InjSys_bAcvInjModH'
     *  Logic: '<S55>/Logical Operator5'
     *  Logic: '<S55>/Logical Operator6'
     */
    if (InjSysSpCrk_B.VEMS_vidGET5 && (!InjSysSpCrk_B.VEMS_vidGET8)) {
      /* Constant: '<S56>/Constant' */
      InjSysSpCrk_B.Merge_n = 32768U;

      /* Constant: '<S56>/Constant1' */
      InjSysSpCrk_B.Merge1_d = 0U;

      /* Constant: '<S56>/Constant2' */
      InjSysSpCrk_B.Merge2_n = 0U;
    }

    /* end of Outputs for SubSystem: '<S55>/F01_HomFrac' */
    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_nEngLoResl, InjSysSpCrk_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_tCoMes, InjSysSpCrk_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjSysSpCrk_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET */
    VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, InjSysSpCrk_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_bAcvHPst, InjSysSpCrk_B.VEMS_vidGET4_d);

    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bAcvInjModSplst, InjSysSpCrk_B.VEMS_vidGET6);

    /* Outputs for enable SubSystem: '<S55>/F02_SplStrtFrac' incorporates:
     *  EnablePort: '<S57>/InjSys_bAcvInjModSplst'
     *  Logic: '<S55>/Logical Operator2'
     *  Logic: '<S55>/Logical Operator3'
     */
    if (InjSysSpCrk_B.VEMS_vidGET6 && (!InjSysSpCrk_B.VEMS_vidGET8)) {
      /* If: '<S57>/If3' incorporates:
       *  ActionPort: '<S60>/Action Port'
       *  ActionPort: '<S61>/Action Port'
       *  Logic: '<S57>/Logical Operator3'
       *  SubSystem: '<S57>/F01_SplStrtFracSTT'
       *  SubSystem: '<S57>/F02_SplStrtFracWoSTT'
       */
      if (InjSysSpCrk_B.VEMS_vidGET1 || InjSysSpCrk_B.VEMS_vidGET) {
        /* DataTypeConversion: '<S86>/Conversion' incorporates:
         *  Constant: '<S60>/Constant9'
         */
        localSwitch_d = 32768U;

        /* DataTypeConversion: '<S74>/Conversion' incorporates:
         *  Constant: '<S60>/Constant2'
         */
        localSwitch2_mw = 32768U;

        /* DataTypeConversion: '<S62>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_b = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_b = MAX_uint8_T;
        } else {
          localDataTypeConversion_b = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S62>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_o = MAX_uint16_T;
        } else {
          localSwitch2_o = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S62>/Look-Up Table (2-D)'
         * About '<S62>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localSwitch2_gq),
                          (&(InjSys_rInj2CrkSpModSplBasSTT_M[0])),
                          localDataTypeConversion_b, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_o, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S62>/Data Type Duplicate2'
         *
         * Regarding '<S62>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S74>/Data Type Duplicate'
         *
         * Regarding '<S74>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S75>/Data Type Duplicate'
         *
         * Regarding '<S75>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S76>/Data Type Propagation'
         *
         * Regarding '<S76>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S75>/Conversion' incorporates:
         *  Constant: '<S60>/Constant3'
         */
        localSwitch2_o = 0U;

        /* Switch: '<S76>/Switch' incorporates:
         *  RelationalOperator: '<S76>/UpperRelop'
         */
        if (!(localSwitch2_gq < localSwitch2_o)) {
          localSwitch2_o = localSwitch2_gq;
        }

        /* Switch: '<S76>/Switch2' incorporates:
         *  RelationalOperator: '<S76>/LowerRelop1'
         */
        if (!(localSwitch2_gq > 32768)) {
          localSwitch2_mw = localSwitch2_o;
        }

        /* DataTypeConversion: '<S77>/Conversion' incorporates:
         *  Constant: '<S60>/Constant4'
         */
        localSwitch2_gq = 32768U;

        /* DataTypeConversion: '<S64>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_b = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_b = MAX_uint8_T;
        } else {
          localDataTypeConversion_b = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S64>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_o = MAX_uint16_T;
        } else {
          localSwitch2_o = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S64>/Look-Up Table (2-D)'
         * About '<S64>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localSwitch_m), (&(InjSys_rInj3CrkSpModSplBasSTT_M
          [0])), localDataTypeConversion_b, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_o, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate2'
         *
         * Regarding '<S64>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S77>/Data Type Duplicate'
         *
         * Regarding '<S77>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S78>/Data Type Duplicate'
         *
         * Regarding '<S78>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S79>/Data Type Propagation'
         *
         * Regarding '<S79>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S78>/Conversion' incorporates:
         *  Constant: '<S60>/Constant18'
         */
        localSwitch2_o = 0U;

        /* Switch: '<S79>/Switch' incorporates:
         *  RelationalOperator: '<S79>/UpperRelop'
         */
        if (!(localSwitch_m < localSwitch2_o)) {
          localSwitch2_o = localSwitch_m;
        }

        /* Switch: '<S79>/Switch2' incorporates:
         *  RelationalOperator: '<S79>/LowerRelop1'
         */
        if (!(localSwitch_m > localSwitch2_gq)) {
          localSwitch2_gq = localSwitch2_o;
        }

        /* Sum: '<S60>/Add3' */
        localAdd6 = (UInt32)(localSwitch2_mw + localSwitch2_gq);

        /* Switch: '<S88>/Switch2' incorporates:
         *  RelationalOperator: '<S88>/LowerRelop1'
         *  RelationalOperator: '<S88>/UpperRelop'
         *  Switch: '<S88>/Switch'
         */
        if (!(localAdd6 > 32768U)) {
          localSwitch_d = localAdd6;
        }

        /* Sum: '<S60>/Add1' incorporates:
         *  Constant: '<S60>/Constant'
         */
        localqY = 32768 - ((SInt32)localSwitch_d);
        if (localqY <= 0) {
          localSwitch_m = 0U;
        } else if (localqY > 65535) {
          localSwitch_m = MAX_uint16_T;
        } else {
          localSwitch_m = (UInt16)localqY;
        }

        /* DataTypeConversion: '<S89>/Conversion' incorporates:
         *  Constant: '<S60>/Constant21'
         */
        localSwitch_d = 32768U;

        /* DataTypeConversion: '<S80>/Conversion' incorporates:
         *  Constant: '<S60>/Constant5'
         */
        localSwitch2_o = 32768U;

        /* DataTypeConversion: '<S63>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_b = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_b = MAX_uint8_T;
        } else {
          localDataTypeConversion_b = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S63>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_an = MAX_uint16_T;
        } else {
          localSwitch2_an = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S63>/Look-Up Table (2-D)'
         * About '<S63>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localSwitch2_gy),
                          (&(InjSys_rInj2CrkSpModSplLPSTT_M[0])),
                          localDataTypeConversion_b, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_an, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S63>/Data Type Duplicate2'
         *
         * Regarding '<S63>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S80>/Data Type Duplicate'
         *
         * Regarding '<S80>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S81>/Data Type Duplicate'
         *
         * Regarding '<S81>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S82>/Data Type Propagation'
         *
         * Regarding '<S82>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S81>/Conversion' incorporates:
         *  Constant: '<S60>/Constant6'
         */
        localSwitch2_an = 0U;

        /* Switch: '<S82>/Switch' incorporates:
         *  RelationalOperator: '<S82>/UpperRelop'
         */
        if (!(localSwitch2_gy < localSwitch2_an)) {
          localSwitch2_an = localSwitch2_gy;
        }

        /* Switch: '<S82>/Switch2' incorporates:
         *  RelationalOperator: '<S82>/LowerRelop1'
         */
        if (!(localSwitch2_gy > localSwitch2_o)) {
          localSwitch2_o = localSwitch2_an;
        }

        /* DataTypeConversion: '<S83>/Conversion' incorporates:
         *  Constant: '<S60>/Constant7'
         */
        localSwitch2_gy = 32768U;

        /* DataTypeConversion: '<S65>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_b = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_b = MAX_uint8_T;
        } else {
          localDataTypeConversion_b = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S65>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_an = MAX_uint16_T;
        } else {
          localSwitch2_an = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S65>/Look-Up Table (2-D)'
         * About '<S65>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localAdd2_l), (&(InjSys_rInj3CrkSpModSplLPSTT_M[0])),
                          localDataTypeConversion_b, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_an, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S65>/Data Type Duplicate2'
         *
         * Regarding '<S65>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S83>/Data Type Duplicate'
         *
         * Regarding '<S83>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S84>/Data Type Duplicate'
         *
         * Regarding '<S84>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S85>/Data Type Propagation'
         *
         * Regarding '<S85>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S84>/Conversion' incorporates:
         *  Constant: '<S60>/Constant8'
         */
        localSwitch2_an = 0U;

        /* Switch: '<S85>/Switch' incorporates:
         *  RelationalOperator: '<S85>/UpperRelop'
         */
        if (!(localAdd2_l < localSwitch2_an)) {
          localSwitch2_an = localAdd2_l;
        }

        /* Switch: '<S85>/Switch2' incorporates:
         *  RelationalOperator: '<S85>/LowerRelop1'
         */
        if (!(localAdd2_l > localSwitch2_gy)) {
          localSwitch2_gy = localSwitch2_an;
        }

        /* Sum: '<S60>/Add4' */
        localAdd6 = (UInt32)(localSwitch2_o + localSwitch2_gy);

        /* Switch: '<S91>/Switch2' incorporates:
         *  RelationalOperator: '<S91>/LowerRelop1'
         *  RelationalOperator: '<S91>/UpperRelop'
         *  Switch: '<S91>/Switch'
         */
        if (!(localAdd6 > 32768U)) {
          localSwitch_d = localAdd6;
        }

        /* Sum: '<S60>/Add2' incorporates:
         *  Constant: '<S60>/Constant1'
         */
        localqY = 32768 - ((SInt32)localSwitch_d);
        if (localqY <= 0) {
          localAdd2_l = 0U;
        } else if (localqY > 65535) {
          localAdd2_l = MAX_uint16_T;
        } else {
          localAdd2_l = (UInt16)localqY;
        }

        /* DataTypeConversion: '<S92>/Conversion' incorporates:
         *  Constant: '<S60>/Constant10'
         */
        localSwitch2_an = 32768U;

        /* Switch: '<S94>/Switch' incorporates:
         *  RelationalOperator: '<S94>/UpperRelop'
         */
        localSwitch2_by = localSwitch_m;

        /* Switch: '<S94>/Switch2' incorporates:
         *  RelationalOperator: '<S94>/LowerRelop1'
         */
        if (!(localSwitch_m > localSwitch2_an)) {
          localSwitch2_an = localSwitch2_by;
        }

        /* DataTypeConversion: '<S95>/Conversion' incorporates:
         *  Constant: '<S60>/Constant12'
         */
        localSwitch2_by = 32768U;

        /* DataTypeConversion: '<S96>/Conversion' incorporates:
         *  Constant: '<S60>/Constant13'
         */
        localSwitch_m = 0U;

        /* Switch: '<S97>/Switch' incorporates:
         *  RelationalOperator: '<S97>/UpperRelop'
         */
        if (!(localAdd2_l < localSwitch_m)) {
          localSwitch_m = localAdd2_l;
        }

        /* Switch: '<S97>/Switch2' incorporates:
         *  RelationalOperator: '<S97>/LowerRelop1'
         */
        if (!(localAdd2_l > 32768)) {
          localSwitch2_by = localSwitch_m;
        }

        /* Switch: '<S60>/Switch2' incorporates:
         *  SignalConversion: '<S60>/Signal Conversion4'
         *  SignalConversion: '<S60>/Signal Conversion6'
         *  SignalConversion: '<S60>/Signal Conversion7'
         */
        if (InjSysSpCrk_B.VEMS_vidGET4_d) {
          InjSysSpCrk_B.Merge1_d = localSwitch2_mw;
          InjSysSpCrk_B.Merge_n = localSwitch2_an;
          InjSysSpCrk_B.Merge2_n = localSwitch2_gq;
        } else {
          InjSysSpCrk_B.Merge1_d = localSwitch2_o;
          InjSysSpCrk_B.Merge_n = localSwitch2_by;
          InjSysSpCrk_B.Merge2_n = localSwitch2_gy;
        }
      } else {
        /* DataTypeConversion: '<S116>/Conversion' incorporates:
         *  Constant: '<S61>/Constant6'
         */
        localSwitch2_mw = 32768U;

        /* DataTypeConversion: '<S99>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_m = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_m = MAX_uint8_T;
        } else {
          localDataTypeConversion_m = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S99>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_m = MAX_uint16_T;
        } else {
          localSwitch2_m = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S99>/Look-Up Table (2-D)'
         * About '<S99>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localSwitch2_og), (&(InjSys_rInj2CrkSpModSplLP_M[0])),
                          localDataTypeConversion_m, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_m, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S99>/Data Type Duplicate2'
         *
         * Regarding '<S99>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S116>/Data Type Duplicate'
         *
         * Regarding '<S116>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S117>/Data Type Duplicate'
         *
         * Regarding '<S117>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S118>/Data Type Propagation'
         *
         * Regarding '<S118>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S117>/Conversion' incorporates:
         *  Constant: '<S61>/Constant7'
         */
        localSwitch2_m = 0U;

        /* Switch: '<S118>/Switch' incorporates:
         *  RelationalOperator: '<S118>/UpperRelop'
         */
        if (!(localSwitch2_og < localSwitch2_m)) {
          localSwitch2_m = localSwitch2_og;
        }

        /* Switch: '<S118>/Switch2' incorporates:
         *  RelationalOperator: '<S118>/LowerRelop1'
         */
        if (!(localSwitch2_og > 32768)) {
          localSwitch2_mw = localSwitch2_m;
        }

        /* DataTypeConversion: '<S119>/Conversion' incorporates:
         *  Constant: '<S61>/Constant8'
         */
        localSwitch2_og = 32768U;

        /* DataTypeConversion: '<S101>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_m = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_m = MAX_uint8_T;
        } else {
          localDataTypeConversion_m = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S101>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_m = MAX_uint16_T;
        } else {
          localSwitch2_m = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S101>/Look-Up Table (2-D)'
         * About '<S101>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localSwitch_dok), (&(InjSys_rInj3CrkSpModSplLP_M[0])),
                          localDataTypeConversion_m, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_m, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S101>/Data Type Duplicate2'
         *
         * Regarding '<S101>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S119>/Data Type Duplicate'
         *
         * Regarding '<S119>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S120>/Data Type Duplicate'
         *
         * Regarding '<S120>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S121>/Data Type Propagation'
         *
         * Regarding '<S121>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S120>/Conversion' incorporates:
         *  Constant: '<S61>/Constant9'
         */
        localSwitch2_m = 0U;

        /* Switch: '<S121>/Switch' incorporates:
         *  RelationalOperator: '<S121>/UpperRelop'
         */
        if (!(localSwitch_dok < localSwitch2_m)) {
          localSwitch2_m = localSwitch_dok;
        }

        /* Switch: '<S121>/Switch2' incorporates:
         *  RelationalOperator: '<S121>/LowerRelop1'
         */
        if (!(localSwitch_dok > localSwitch2_og)) {
          localSwitch2_og = localSwitch2_m;
        }

        /* Sum: '<S61>/Add1' */
        localSwitch_d = (UInt32)(localSwitch2_mw + localSwitch2_og);

        /* DataTypeConversion: '<S131>/Conversion' incorporates:
         *  Constant: '<S61>/Constant12'
         */
        localAdd6 = 32768U;

        /* Switch: '<S133>/Switch2' incorporates:
         *  RelationalOperator: '<S133>/LowerRelop1'
         *  RelationalOperator: '<S133>/UpperRelop'
         *  Switch: '<S133>/Switch'
         */
        if (!(localSwitch_d > 32768U)) {
          localAdd6 = localSwitch_d;
        }

        /* Sum: '<S61>/Add2' incorporates:
         *  Constant: '<S61>/Constant1'
         */
        localqY = 32768 - ((SInt32)localAdd6);
        if (localqY <= 0) {
          localSwitch_dok = 0U;
        } else if (localqY > 65535) {
          localSwitch_dok = MAX_uint16_T;
        } else {
          localSwitch_dok = (UInt16)localqY;
        }

        /* DataTypeConversion: '<S125>/Conversion' incorporates:
         *  Constant: '<S61>/Constant16'
         */
        localSwitch_d = 32768U;

        /* DataTypeConversion: '<S110>/Conversion' incorporates:
         *  Constant: '<S61>/Constant2'
         */
        localSwitch2_m = 32768U;

        /* DataTypeConversion: '<S98>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_m = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_m = MAX_uint8_T;
        } else {
          localDataTypeConversion_m = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S98>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_h0 = MAX_uint16_T;
        } else {
          localSwitch2_h0 = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S98>/Look-Up Table (2-D)'
         * About '<S98>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localSwitch2_l), (&(InjSys_rInj2CrkSpModSplBas_M[0])),
                          localDataTypeConversion_m, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_h0, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S98>/Data Type Duplicate2'
         *
         * Regarding '<S98>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S110>/Data Type Duplicate'
         *
         * Regarding '<S110>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S111>/Data Type Duplicate'
         *
         * Regarding '<S111>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S112>/Data Type Propagation'
         *
         * Regarding '<S112>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S111>/Conversion' incorporates:
         *  Constant: '<S61>/Constant3'
         */
        localSwitch2_h0 = 0U;

        /* Switch: '<S112>/Switch' incorporates:
         *  RelationalOperator: '<S112>/UpperRelop'
         */
        if (!(localSwitch2_l < localSwitch2_h0)) {
          localSwitch2_h0 = localSwitch2_l;
        }

        /* Switch: '<S112>/Switch2' incorporates:
         *  RelationalOperator: '<S112>/LowerRelop1'
         */
        if (!(localSwitch2_l > localSwitch2_m)) {
          localSwitch2_m = localSwitch2_h0;
        }

        /* DataTypeConversion: '<S113>/Conversion' incorporates:
         *  Constant: '<S61>/Constant4'
         */
        localSwitch2_l = 32768U;

        /* DataTypeConversion: '<S100>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_m = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_m = MAX_uint8_T;
        } else {
          localDataTypeConversion_m = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S100>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_h0 = MAX_uint16_T;
        } else {
          localSwitch2_h0 = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S100>/Look-Up Table (2-D)'
         * About '<S100>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localAdd5), (&(InjSys_rInj3CrkSpModSplBas_M[0])),
                          localDataTypeConversion_m, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_h0, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S100>/Data Type Duplicate2'
         *
         * Regarding '<S100>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S113>/Data Type Duplicate'
         *
         * Regarding '<S113>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S114>/Data Type Duplicate'
         *
         * Regarding '<S114>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S115>/Data Type Propagation'
         *
         * Regarding '<S115>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S114>/Conversion' incorporates:
         *  Constant: '<S61>/Constant5'
         */
        localSwitch2_h0 = 0U;

        /* Switch: '<S115>/Switch' incorporates:
         *  RelationalOperator: '<S115>/UpperRelop'
         */
        if (!(localAdd5 < localSwitch2_h0)) {
          localSwitch2_h0 = localAdd5;
        }

        /* Switch: '<S115>/Switch2' incorporates:
         *  RelationalOperator: '<S115>/LowerRelop1'
         */
        if (!(localAdd5 > localSwitch2_l)) {
          localSwitch2_l = localSwitch2_h0;
        }

        /* Sum: '<S61>/Add6' */
        localAdd6 = (UInt32)(localSwitch2_m + localSwitch2_l);

        /* Switch: '<S127>/Switch2' incorporates:
         *  RelationalOperator: '<S127>/LowerRelop1'
         *  RelationalOperator: '<S127>/UpperRelop'
         *  Switch: '<S127>/Switch'
         */
        if (!(localAdd6 > 32768U)) {
          localSwitch_d = localAdd6;
        }

        /* Sum: '<S61>/Add5' incorporates:
         *  Constant: '<S61>/Constant'
         */
        localqY = 32768 - ((SInt32)localSwitch_d);
        if (localqY <= 0) {
          localAdd5 = 0U;
        } else if (localqY > 65535) {
          localAdd5 = MAX_uint16_T;
        } else {
          localAdd5 = (UInt16)localqY;
        }

        /* DataTypeConversion: '<S122>/Conversion' incorporates:
         *  Constant: '<S61>/Constant10'
         */
        localSwitch2_h0 = 32768U;

        /* Switch: '<S124>/Switch' incorporates:
         *  RelationalOperator: '<S124>/UpperRelop'
         */
        localSwitch2_by = localSwitch_dok;

        /* Switch: '<S124>/Switch2' incorporates:
         *  RelationalOperator: '<S124>/LowerRelop1'
         */
        if (!(localSwitch_dok > localSwitch2_h0)) {
          localSwitch2_h0 = localSwitch2_by;
        }

        /* DataTypeConversion: '<S128>/Conversion' incorporates:
         *  Constant: '<S61>/Constant14'
         */
        localSwitch2_by = 32768U;

        /* DataTypeConversion: '<S129>/Conversion' incorporates:
         *  Constant: '<S61>/Constant15'
         */
        localSwitch_dok = 0U;

        /* Switch: '<S130>/Switch' incorporates:
         *  RelationalOperator: '<S130>/UpperRelop'
         */
        if (!(localAdd5 < localSwitch_dok)) {
          localSwitch_dok = localAdd5;
        }

        /* Switch: '<S130>/Switch2' incorporates:
         *  RelationalOperator: '<S130>/LowerRelop1'
         */
        if (!(localAdd5 > 32768)) {
          localSwitch2_by = localSwitch_dok;
        }

        /* Switch: '<S61>/Switch2' incorporates:
         *  SignalConversion: '<S61>/Signal Conversion4'
         *  SignalConversion: '<S61>/Signal Conversion6'
         *  SignalConversion: '<S61>/Signal Conversion7'
         */
        if (InjSysSpCrk_B.VEMS_vidGET4_d) {
          InjSysSpCrk_B.Merge1_d = localSwitch2_m;
          InjSysSpCrk_B.Merge_n = localSwitch2_by;
          InjSysSpCrk_B.Merge2_n = localSwitch2_l;
        } else {
          InjSysSpCrk_B.Merge1_d = localSwitch2_mw;
          InjSysSpCrk_B.Merge_n = localSwitch2_h0;
          InjSysSpCrk_B.Merge2_n = localSwitch2_og;
        }
      }
    }

    /* end of Outputs for SubSystem: '<S55>/F02_SplStrtFrac' */
    /* S-Function "vems_vidGET" Block: <S55>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_bAcvInjModSst, InjSysSpCrk_B.VEMS_vidGET7);

    /* Outputs for enable SubSystem: '<S55>/F03_SStrtFrac' incorporates:
     *  EnablePort: '<S58>/InjSys_bAcvInjModSst'
     *  Logic: '<S55>/Logical Operator1'
     *  Logic: '<S55>/Logical Operator4'
     */
    if (InjSysSpCrk_B.VEMS_vidGET7 && (!InjSysSpCrk_B.VEMS_vidGET8)) {
      /* If: '<S58>/If3' incorporates:
       *  ActionPort: '<S134>/Action Port'
       *  ActionPort: '<S135>/Action Port'
       *  Logic: '<S58>/Logical Operator3'
       *  SubSystem: '<S58>/F01_SStrtFracSTT'
       *  SubSystem: '<S58>/F02_SStrtFracWoSTT'
       */
      if (InjSysSpCrk_B.VEMS_vidGET1 || InjSysSpCrk_B.VEMS_vidGET) {
        /* Constant: '<S134>/Constant1' */
        InjSysSpCrk_B.Merge_n = 0U;

        /* DataTypeConversion: '<S142>/Conversion' incorporates:
         *  Constant: '<S134>/Constant4'
         */
        localSwitch2_mw = 32768U;

        /* DataTypeConversion: '<S136>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_c = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_c = MAX_uint8_T;
        } else {
          localDataTypeConversion_c = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S136>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_b = MAX_uint16_T;
        } else {
          localSwitch2_b = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S136>/Look-Up Table (2-D)'
         * About '<S136>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localAdd2_g), (&(InjSys_rInj3CrkSpModSstBasSTT_M[0])),
                          localDataTypeConversion_c, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_b, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S136>/Data Type Duplicate2'
         *
         * Regarding '<S136>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S142>/Data Type Duplicate'
         *
         * Regarding '<S142>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S143>/Data Type Duplicate'
         *
         * Regarding '<S143>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S144>/Data Type Propagation'
         *
         * Regarding '<S144>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S143>/Conversion' incorporates:
         *  Constant: '<S134>/Constant5'
         */
        localSwitch2_b = 0U;

        /* Switch: '<S144>/Switch' incorporates:
         *  RelationalOperator: '<S144>/UpperRelop'
         */
        if (!(localAdd2_g < localSwitch2_b)) {
          localSwitch2_b = localAdd2_g;
        }

        /* Switch: '<S144>/Switch2' incorporates:
         *  RelationalOperator: '<S144>/LowerRelop1'
         */
        if (!(localAdd2_g > 32768)) {
          localSwitch2_mw = localSwitch2_b;
        }

        /* Sum: '<S134>/Add2' incorporates:
         *  Constant: '<S134>/Constant'
         */
        localqY = 32768 - localSwitch2_mw;
        if (localqY <= 0) {
          localAdd2_g = 0U;
        } else {
          localAdd2_g = (UInt16)localqY;
        }

        /* DataTypeConversion: '<S139>/Conversion' incorporates:
         *  Constant: '<S134>/Constant2'
         */
        localSwitch2_b = 32768U;

        /* Switch: '<S141>/Switch' incorporates:
         *  RelationalOperator: '<S141>/UpperRelop'
         */
        localSwitch2_by = localAdd2_g;

        /* Switch: '<S141>/Switch2' incorporates:
         *  RelationalOperator: '<S141>/LowerRelop1'
         */
        if (!(localAdd2_g > localSwitch2_b)) {
          localSwitch2_b = localSwitch2_by;
        }

        /* SignalConversion: '<S134>/Signal Conversion1' */
        InjSysSpCrk_B.Merge2_n = localSwitch2_mw;

        /* SignalConversion: '<S134>/Signal Conversion2' */
        InjSysSpCrk_B.Merge1_d = localSwitch2_b;
      } else {
        /* Constant: '<S135>/Constant1' */
        InjSysSpCrk_B.Merge_n = 0U;

        /* DataTypeConversion: '<S151>/Conversion' incorporates:
         *  Constant: '<S135>/Constant4'
         */
        localSwitch2_mw = 32768U;

        /* DataTypeConversion: '<S145>/Data Type Conversion' */
        localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
        if (localqY <= 0) {
          localDataTypeConversion_ap = 0U;
        } else if (localqY > 255) {
          localDataTypeConversion_ap = MAX_uint8_T;
        } else {
          localDataTypeConversion_ap = (UInt8)localqY;
        }

        /* DataTypeConversion: '<S145>/Data Type Conversion1' */
        if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
          localSwitch2_g = MAX_uint16_T;
        } else {
          localSwitch2_g = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
        }

        /* Lookup2D: '<S145>/Look-Up Table (2-D)'
         * About '<S145>/Look-Up Table (2-D)':
         * Input0  Data Type:  Fixed Point    U8  Bias -40.0
         * Input1  Data Type:  Integer        U16
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U8_U16( &(localAdd2_m), (&(InjSys_rInj3CrkSpModSstBas_M[0])),
                          localDataTypeConversion_ap, (&(Ext_tCoMes_A[0])), 15U,
                          localSwitch2_g, (&(Ext_nEngRef3_A[0])), 8U);

        /* DataTypeDuplicate Block: '<S145>/Data Type Duplicate2'
         *
         * Regarding '<S145>/Data Type Duplicate2':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S151>/Data Type Duplicate'
         *
         * Regarding '<S151>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* DataTypeDuplicate Block: '<S152>/Data Type Duplicate'
         *
         * Regarding '<S152>/Data Type Duplicate':
         *   Unused code path elimination
         */

        /* S-Function Block: '<S153>/Data Type Propagation'
         *
         * Regarding '<S153>/Data Type Propagation':
         *   Unused code path elimination
         */

        /* DataTypeConversion: '<S152>/Conversion' incorporates:
         *  Constant: '<S135>/Constant5'
         */
        localSwitch2_g = 0U;

        /* Switch: '<S153>/Switch' incorporates:
         *  RelationalOperator: '<S153>/UpperRelop'
         */
        if (!(localAdd2_m < localSwitch2_g)) {
          localSwitch2_g = localAdd2_m;
        }

        /* Switch: '<S153>/Switch2' incorporates:
         *  RelationalOperator: '<S153>/LowerRelop1'
         */
        if (!(localAdd2_m > 32768)) {
          localSwitch2_mw = localSwitch2_g;
        }

        /* Sum: '<S135>/Add2' incorporates:
         *  Constant: '<S135>/Constant'
         */
        localqY = 32768 - localSwitch2_mw;
        if (localqY <= 0) {
          localAdd2_m = 0U;
        } else {
          localAdd2_m = (UInt16)localqY;
        }

        /* DataTypeConversion: '<S148>/Conversion' incorporates:
         *  Constant: '<S135>/Constant2'
         */
        localSwitch2_g = 32768U;

        /* Switch: '<S150>/Switch' incorporates:
         *  RelationalOperator: '<S150>/UpperRelop'
         */
        localSwitch2_by = localAdd2_m;

        /* Switch: '<S150>/Switch2' incorporates:
         *  RelationalOperator: '<S150>/LowerRelop1'
         */
        if (!(localAdd2_m > localSwitch2_g)) {
          localSwitch2_g = localSwitch2_by;
        }

        /* SignalConversion: '<S135>/Signal Conversion1' */
        InjSysSpCrk_B.Merge2_n = localSwitch2_mw;

        /* SignalConversion: '<S135>/Signal Conversion2' */
        InjSysSpCrk_B.Merge1_d = localSwitch2_g;
      }
    }

    /* end of Outputs for SubSystem: '<S55>/F03_SStrtFrac' */

    /* Outputs for enable SubSystem: '<S55>/F04_FrstInjFrac' incorporates:
     *  EnablePort: '<S59>/InjSys_bAcvFrstInjSp'
     */
    if (InjSysSpCrk_B.VEMS_vidGET8) {
      /* DataTypeConversion: '<S166>/Conversion' incorporates:
       *  Constant: '<S59>/Constant5'
       */
      localSwitch_d = 32768U;

      /* DataTypeConversion: '<S160>/Conversion' incorporates:
       *  Constant: '<S59>/Constant2'
       */
      localSwitch2_mw = 32768U;

      /* DataTypeConversion: '<S154>/Data Type Conversion' */
      localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
      if (localqY <= 0) {
        localDataTypeConversion_jg = 0U;
      } else if (localqY > 255) {
        localDataTypeConversion_jg = MAX_uint8_T;
      } else {
        localDataTypeConversion_jg = (UInt8)localqY;
      }

      /* DataTypeConversion: '<S154>/Data Type Conversion1' */
      if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
        localSwitch2_ai = MAX_uint16_T;
      } else {
        localSwitch2_ai = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
      }

      /* Lookup2D: '<S154>/Look-Up Table (2-D)'
       * About '<S154>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U8  Bias -40.0
       * Input1  Data Type:  Integer        U16
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U8_U16( &(localSwitch2_hh), (&(InjSys_rInj2FrstInj_M[0])),
                        localDataTypeConversion_jg, (&(Ext_tCoMes_A[0])), 15U,
                        localSwitch2_ai, (&(Ext_nEngRef3_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S154>/Data Type Duplicate2'
       *
       * Regarding '<S154>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeDuplicate Block: '<S160>/Data Type Duplicate'
       *
       * Regarding '<S160>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* DataTypeDuplicate Block: '<S161>/Data Type Duplicate'
       *
       * Regarding '<S161>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* S-Function Block: '<S162>/Data Type Propagation'
       *
       * Regarding '<S162>/Data Type Propagation':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S161>/Conversion' incorporates:
       *  Constant: '<S59>/Constant3'
       */
      localSwitch2_ai = 0U;

      /* Switch: '<S162>/Switch' incorporates:
       *  RelationalOperator: '<S162>/UpperRelop'
       */
      if (!(localSwitch2_hh < localSwitch2_ai)) {
        localSwitch2_ai = localSwitch2_hh;
      }

      /* Switch: '<S162>/Switch2' incorporates:
       *  RelationalOperator: '<S162>/LowerRelop1'
       */
      if (!(localSwitch2_hh > 32768)) {
        localSwitch2_mw = localSwitch2_ai;
      }

      /* DataTypeConversion: '<S163>/Conversion' incorporates:
       *  Constant: '<S59>/Constant1'
       */
      localSwitch2_hh = 32768U;

      /* DataTypeConversion: '<S155>/Data Type Conversion' */
      localqY = InjSysSpCrk_B.VEMS_vidGET3 + 40;
      if (localqY <= 0) {
        localDataTypeConversion_jg = 0U;
      } else if (localqY > 255) {
        localDataTypeConversion_jg = MAX_uint8_T;
      } else {
        localDataTypeConversion_jg = (UInt8)localqY;
      }

      /* DataTypeConversion: '<S155>/Data Type Conversion1' */
      if (InjSysSpCrk_B.VEMS_vidGET2 > 2047) {
        localSwitch2_ai = MAX_uint16_T;
      } else {
        localSwitch2_ai = (UInt16)(InjSysSpCrk_B.VEMS_vidGET2 << 5);
      }

      /* Lookup2D: '<S155>/Look-Up Table (2-D)'
       * About '<S155>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U8  Bias -40.0
       * Input1  Data Type:  Integer        U16
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U8_U16( &(localAdd2), (&(InjSys_rInj3FrstInj_M[0])),
                        localDataTypeConversion_jg, (&(Ext_tCoMes_A[0])), 15U,
                        localSwitch2_ai, (&(Ext_nEngRef3_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S155>/Data Type Duplicate2'
       *
       * Regarding '<S155>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeDuplicate Block: '<S163>/Data Type Duplicate'
       *
       * Regarding '<S163>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* DataTypeDuplicate Block: '<S164>/Data Type Duplicate'
       *
       * Regarding '<S164>/Data Type Duplicate':
       *   Unused code path elimination
       */

      /* S-Function Block: '<S165>/Data Type Propagation'
       *
       * Regarding '<S165>/Data Type Propagation':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S164>/Conversion' incorporates:
       *  Constant: '<S59>/Constant4'
       */
      localSwitch2_ai = 0U;

      /* Switch: '<S165>/Switch' incorporates:
       *  RelationalOperator: '<S165>/UpperRelop'
       */
      if (!(localAdd2 < localSwitch2_ai)) {
        localSwitch2_ai = localAdd2;
      }

      /* Switch: '<S165>/Switch2' incorporates:
       *  RelationalOperator: '<S165>/LowerRelop1'
       */
      if (!(localAdd2 > localSwitch2_hh)) {
        localSwitch2_hh = localSwitch2_ai;
      }

      /* Sum: '<S59>/Add4' */
      localAdd6 = (UInt32)(localSwitch2_mw + localSwitch2_hh);

      /* Switch: '<S168>/Switch2' incorporates:
       *  RelationalOperator: '<S168>/LowerRelop1'
       *  RelationalOperator: '<S168>/UpperRelop'
       *  Switch: '<S168>/Switch'
       */
      if (!(localAdd6 > 32768U)) {
        localSwitch_d = localAdd6;
      }

      /* Sum: '<S59>/Add2' incorporates:
       *  Constant: '<S59>/Constant'
       */
      localqY = 32768 - ((SInt32)localSwitch_d);
      if (localqY <= 0) {
        localAdd2 = 0U;
      } else if (localqY > 65535) {
        localAdd2 = MAX_uint16_T;
      } else {
        localAdd2 = (UInt16)localqY;
      }

      /* DataTypeConversion: '<S169>/Conversion' incorporates:
       *  Constant: '<S59>/Constant7'
       */
      localSwitch2_ai = 32768U;

      /* Switch: '<S171>/Switch' incorporates:
       *  RelationalOperator: '<S171>/UpperRelop'
       */
      localSwitch2_by = localAdd2;

      /* Switch: '<S171>/Switch2' incorporates:
       *  RelationalOperator: '<S171>/LowerRelop1'
       */
      if (!(localAdd2 > localSwitch2_ai)) {
        localSwitch2_ai = localSwitch2_by;
      }

      /* SignalConversion: '<S59>/Signal Conversion1' */
      InjSysSpCrk_B.Merge2_n = localSwitch2_hh;

      /* SignalConversion: '<S59>/Signal Conversion2' */
      InjSysSpCrk_B.Merge_n = localSwitch2_ai;

      /* SignalConversion: '<S59>/Signal Conversion5' */
      InjSysSpCrk_B.Merge1_d = localSwitch2_mw;
    }

    /* end of Outputs for SubSystem: '<S55>/F04_FrstInjFrac' */
    /* S-Function "vems_vidSET" Block: <S55>/VEMS_vidSET */
    VEMS_vidSET(InjSys_rInj1CrkSp, InjSysSpCrk_B.Merge_n);

    /* S-Function "vems_vidSET" Block: <S55>/VEMS_vidSET1 */
    VEMS_vidSET(InjSys_rInj2CrkSp, InjSysSpCrk_B.Merge1_d);

    /* S-Function "vems_vidSET" Block: <S55>/VEMS_vidSET2 */
    VEMS_vidSET(InjSys_rInj3CrkSp, InjSysSpCrk_B.Merge2_n);
  }

  /* end of Outputs for SubSystem: '<S8>/F02_rInjSpClcn_Inhib' */
}

/* Start for exported function: InjSys_EveStTR_InjSysSpCrk */
void InjSys_EveStTR_InjSysSpCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/fc_demux2'
   */

  /* Start for S-Function (fcncallgen): '<S11>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S1>/F01_InjPhaClcn'
   *  Start for SubSystem: '<S1>/F02_rInjSpClcn'
   *  Start for SubSystem: '<S1>/F03_PfurailClcn'
   *  Start for SubSystem: '<S6>/F01_AuthFrstInjAdap'
   *
   * Block requirements for '<S1>/F01_InjPhaClcn':
   *  1. SubSystem "F01_InjPhaClcn" !Trace_To : VEMS_E_11_01572_003.01 ;
   *
   * Block requirements for '<S1>/F03_PfurailClcn':
   *  1. SubSystem "F03_PfurailClcn" !Trace_To : VEMS_E_11_01572_007.01 ;
   */
}

/* Output and update for exported function: InjSys_EveStTR_InjSysSpCrk */
void InjSys_EveStTR_InjSysSpCrk(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/fc_demux2'
   */

  /* S-Function (fcncallgen): '<S11>/Function-Call Generator' */
  InjSysSpCrk_ASYNC2(0);
  InjSysSpCrk_ASYNC4(0);
}

/* Output and update for exported function: InjSys_SdlFast_InjSysSpCrk */
void InjSys_SdlFast_InjSysSpCrk(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/fc_demux1'
   */

  /* S-Function (fcncallgen): '<S10>/Function-Call Generator' */
  InjSysSpCrk_ASYNC2(1);
}

/* Model initialize function */
void InjSysSpCrk_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  InjSys_EveStTR_InjSysSpCrk_Start();
}

#define INJSYSSPCRK_STOP_SEC_CODE
#include "InjSysSpCrk_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
