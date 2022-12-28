/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjrMdl                                                 */
/* !Description     : InjSys - MODELE INJECTEUR (GDI)                         */
/*                                                                            */
/* !Module          : InjrMdl                                                 */
/*                                                                            */
/* !File            : InjrMdl.c                                               */
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
/* !Reference       : V01NT1007996 / 01                                       */
/* !OtherRefs       : VEMS V02 ECU#065269                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed Mar 13 19:55:28 2013                              */
/*   Model name       : InjrMdl_AUTOCODE.mdl                                  */
/*   Model version    : 1.280                                                 */
/*   Root subsystem   : /InjrMdl                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjrMdl/5-SOFT-LIV/InjrMdl.c$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   18 Mar 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjrMdl.h"
#include "InjrMdl_private.h"

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
#define INJRMDL_START_SEC_VAR_UNSPECIFIED
#include "InjrMdl_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InjrMdl InjrMdl_B;

#define INJRMDL_STOP_SEC_VAR_UNSPECIFIED
#include "InjrMdl_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define INJRMDL_START_SEC_CODE
#include "InjrMdl_MemMap.h"

void InjrMdl_ASYNC1(int controlPortIdx)
{
}

void InjrMdl_ASYNC2(int controlPortIdx)
{
  InjrMdl_F02_InjrMdlSyncEveClcn();
}

void InjrMdl_ASYNC3(int controlPortIdx)
{
  InjrMdl_F01_InjrMdl_g();
}

/*
 * Output and update for atomic system:
 *    '<S8>/F01_InjrMdl'
 *    '<S15>/F01_InjrMdl'
 */
void InjrMdl_F01_InjrMdl(UInt16 rtu_FuSysM_tFu, const UInt16
  rtu_InjrM_prm_facGainLnrlnjRaw[4], const UInt16 rtu_InjrM_prm_pDifInjr[4],
  SInt32 rtu_AFA_facSlopInjGain, SInt16 rtu_AFA_facIvsInjGain, const UInt16
  rtu_InjrM_prm_facCorGainLnr[4], UInt16 rtu_Ext_uBatt, const SInt16
  rtu_InjrM_prm_tiInjOfsRaw[4], SInt8 rtu_AFA_tiOffInj, rtB_F01_InjrMdl_InjrMdl
  *localB)
{
  /* local block i/o variables */
  UInt16 localLookUpTable;
  Float32 locallocalDivide;
  Float32d localtmp;
  SInt16 localtmp_0;
  UInt16 localtmp_1;

  /* If: '<S27>/If' incorporates:
   *  ActionPort: '<S28>/Action Port'
   *  ActionPort: '<S29>/Action Port'
   *  Constant: '<S27>/InjrM_bAcvInjMdlETB_C'
   *  SubSystem: '<S27>/F01_InjrMdlTest'
   *  SubSystem: '<S27>/F02_InjrMdlnoTest'
   */
  if (InjrM_bAcvInjMdlETB_C) {
    /* SignalConversion: '<S28>/Signal Conversion' incorporates:
     *  Constant: '<S28>/InjrM_tiInjOfsInjH1ETB_C'
     */
    localB->Merge[0] = InjrM_tiInjOfsInjH1ETB_C;

    /* SignalConversion: '<S28>/Signal Conversion2' incorporates:
     *  Constant: '<S28>/InjrM_tiInjOfsInjS1ETB_C'
     */
    localB->Merge[2] = InjrM_tiInjOfsInjS1ETB_C;

    /* SignalConversion: '<S28>/Signal Conversion4' incorporates:
     *  Constant: '<S28>/InjrM_tiInjOfsInjS2ETB_C'
     */
    localB->Merge[3] = InjrM_tiInjOfsInjS2ETB_C;

    /* SignalConversion: '<S28>/Signal Conversion6' incorporates:
     *  Constant: '<S28>/InjrM_tiInjOfsInjH2ETB_C'
     */
    localB->Merge[1] = InjrM_tiInjOfsInjH2ETB_C;

    /* SignalConversion: '<S28>/Signal Conversion1' incorporates:
     *  Constant: '<S28>/InjrM_facGainInjH1ETB_C'
     */
    localB->Merge1[0] = InjrM_facGainInjH1ETB_C;

    /* SignalConversion: '<S28>/Signal Conversion3' incorporates:
     *  Constant: '<S28>/InjrM_facGainInjS1ETB_C'
     */
    localB->Merge1[2] = InjrM_facGainInjS1ETB_C;

    /* SignalConversion: '<S28>/Signal Conversion5' incorporates:
     *  Constant: '<S28>/InjrM_facGainInjS2ETB_C'
     */
    localB->Merge1[3] = InjrM_facGainInjS2ETB_C;

    /* SignalConversion: '<S28>/Signal Conversion7' incorporates:
     *  Constant: '<S28>/InjrM_facGainInjH2ETB_C'
     */
    localB->Merge1[1] = InjrM_facGainInjH2ETB_C;
  } else {
    /* Lookup: '<S34>/Look-Up Table'
     * About '<S34>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  Bias 233.0
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(InjrM_facCorGainLnrInjTFu_T[0])),
                   rtu_FuSysM_tFu, (&(InjrM_tFu_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate1'
     *
     * Regarding '<S34>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S35>/Divide' */
    locallocalDivide = (((Float32)localLookUpTable) * 3.051757813E-005F) *
      (((Float32)rtu_InjrM_prm_facGainLnrlnjRaw[0]) * 0.015625F);

    /* DataStoreWrite: '<S31>/Data Store Write1' */
    InjrM_prm_mfFuStndAdp_MP[0] = locallocalDivide;

    /* Sum: '<S31>/Sum4' incorporates:
     *  Product: '<S36>/Divide'
     *  Sum: '<S31>/Sum3'
     */
    locallocalDivide = (locallocalDivide - ((Float32)((((Float32d)
      rtu_InjrM_prm_pDifInjr[0]) * 781.25) * ACTEMS_LdexpF((Float32d)
      rtu_AFA_facSlopInjGain, -32)))) - (((Float32)rtu_AFA_facIvsInjGain) *
      0.015625F);

    /* DataStoreWrite: '<S31>/Data Store Write3' */
    InjrM_prm_facGainLnrInj[0] = locallocalDivide;

    /* Product: '<S37>/Divide' */
    locallocalDivide = (Float32)ACTEMS_FloorF((((((Float32)
      rtu_InjrM_prm_facCorGainLnr[0]) * 3.051757813E-005F) * locallocalDivide) *
      64.0F) + 0.5F);
    if (locallocalDivide < 65536.0F) {
      if (locallocalDivide >= 0.0F) {
        localtmp_1 = (UInt16)locallocalDivide;
      } else {
        localtmp_1 = 0U;
      }
    } else {
      localtmp_1 = MAX_uint16_T;
    }

    localB->Merge1[0] = localtmp_1;

    /* Product: '<S35>/Divide' */
    locallocalDivide = (((Float32)localLookUpTable) * 3.051757813E-005F) *
      (((Float32)rtu_InjrM_prm_facGainLnrlnjRaw[1]) * 0.015625F);

    /* DataStoreWrite: '<S31>/Data Store Write1' */
    InjrM_prm_mfFuStndAdp_MP[1] = locallocalDivide;

    /* Sum: '<S31>/Sum4' incorporates:
     *  Product: '<S36>/Divide'
     *  Sum: '<S31>/Sum3'
     */
    locallocalDivide = (locallocalDivide - ((Float32)((((Float32d)
      rtu_InjrM_prm_pDifInjr[1]) * 781.25) * ACTEMS_LdexpF((Float32d)
      rtu_AFA_facSlopInjGain, -32)))) - (((Float32)rtu_AFA_facIvsInjGain) *
      0.015625F);

    /* DataStoreWrite: '<S31>/Data Store Write3' */
    InjrM_prm_facGainLnrInj[1] = locallocalDivide;

    /* Product: '<S37>/Divide' */
    locallocalDivide = (Float32)ACTEMS_FloorF((((((Float32)
      rtu_InjrM_prm_facCorGainLnr[1]) * 3.051757813E-005F) * locallocalDivide) *
      64.0F) + 0.5F);
    if (locallocalDivide < 65536.0F) {
      if (locallocalDivide >= 0.0F) {
        localtmp_1 = (UInt16)locallocalDivide;
      } else {
        localtmp_1 = 0U;
      }
    } else {
      localtmp_1 = MAX_uint16_T;
    }

    localB->Merge1[1] = localtmp_1;

    /* Product: '<S35>/Divide' */
    locallocalDivide = (((Float32)localLookUpTable) * 3.051757813E-005F) *
      (((Float32)rtu_InjrM_prm_facGainLnrlnjRaw[2]) * 0.015625F);

    /* DataStoreWrite: '<S31>/Data Store Write1' */
    InjrM_prm_mfFuStndAdp_MP[2] = locallocalDivide;

    /* Sum: '<S31>/Sum4' incorporates:
     *  Product: '<S36>/Divide'
     *  Sum: '<S31>/Sum3'
     */
    locallocalDivide = (locallocalDivide - ((Float32)((((Float32d)
      rtu_InjrM_prm_pDifInjr[2]) * 781.25) * ACTEMS_LdexpF((Float32d)
      rtu_AFA_facSlopInjGain, -32)))) - (((Float32)rtu_AFA_facIvsInjGain) *
      0.015625F);

    /* DataStoreWrite: '<S31>/Data Store Write3' */
    InjrM_prm_facGainLnrInj[2] = locallocalDivide;

    /* Product: '<S37>/Divide' */
    locallocalDivide = (Float32)ACTEMS_FloorF((((((Float32)
      rtu_InjrM_prm_facCorGainLnr[2]) * 3.051757813E-005F) * locallocalDivide) *
      64.0F) + 0.5F);
    if (locallocalDivide < 65536.0F) {
      if (locallocalDivide >= 0.0F) {
        localtmp_1 = (UInt16)locallocalDivide;
      } else {
        localtmp_1 = 0U;
      }
    } else {
      localtmp_1 = MAX_uint16_T;
    }

    localB->Merge1[2] = localtmp_1;

    /* Product: '<S35>/Divide' */
    locallocalDivide = (((Float32)localLookUpTable) * 3.051757813E-005F) *
      (((Float32)rtu_InjrM_prm_facGainLnrlnjRaw[3]) * 0.015625F);

    /* DataStoreWrite: '<S31>/Data Store Write1' */
    InjrM_prm_mfFuStndAdp_MP[3] = locallocalDivide;

    /* Sum: '<S31>/Sum4' incorporates:
     *  Product: '<S36>/Divide'
     *  Sum: '<S31>/Sum3'
     */
    locallocalDivide = (locallocalDivide - ((Float32)((((Float32d)
      rtu_InjrM_prm_pDifInjr[3]) * 781.25) * ACTEMS_LdexpF((Float32d)
      rtu_AFA_facSlopInjGain, -32)))) - (((Float32)rtu_AFA_facIvsInjGain) *
      0.015625F);

    /* DataStoreWrite: '<S31>/Data Store Write3' */
    InjrM_prm_facGainLnrInj[3] = locallocalDivide;

    /* Product: '<S37>/Divide' */
    locallocalDivide = (Float32)ACTEMS_FloorF((((((Float32)
      rtu_InjrM_prm_facCorGainLnr[3]) * 3.051757813E-005F) * locallocalDivide) *
      64.0F) + 0.5F);
    if (locallocalDivide < 65536.0F) {
      if (locallocalDivide >= 0.0F) {
        localtmp_1 = (UInt16)locallocalDivide;
      } else {
        localtmp_1 = 0U;
      }
    } else {
      localtmp_1 = MAX_uint16_T;
    }

    localB->Merge1[3] = localtmp_1;

    /* Lookup: '<S32>/Look-Up Table'
     * About '<S32>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-6  FSlope 1.5104
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(InjrM_facCorOfsuBatt_T[0])),
                   rtu_Ext_uBatt, (&(Ext_uBatt_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate1'
     *
     * Regarding '<S32>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S30>/Sum3' incorporates:
     *  Product: '<S33>/Divide'
     */
    localtmp = ACTEMS_FloorF(((Float32d)(((Float32)((((Float32d)
      rtu_InjrM_prm_tiInjOfsRaw[0]) * 3.2E-006) * ACTEMS_LdexpF((Float32d)
      localLookUpTable, -15))) - (((Float32)rtu_AFA_tiOffInj) *
      3.200000037E-006F))) / 3.2E-006);
    if (localtmp < 32768.0) {
      if (localtmp >= -32768.0) {
        localtmp_0 = (SInt16)localtmp;
      } else {
        localtmp_0 = MIN_int16_T;
      }
    } else {
      localtmp_0 = MAX_int16_T;
    }

    localB->Merge[0] = localtmp_0;
    localtmp = ACTEMS_FloorF(((Float32d)(((Float32)((((Float32d)
      rtu_InjrM_prm_tiInjOfsRaw[1]) * 3.2E-006) * ACTEMS_LdexpF((Float32d)
      localLookUpTable, -15))) - (((Float32)rtu_AFA_tiOffInj) *
      3.200000037E-006F))) / 3.2E-006);
    if (localtmp < 32768.0) {
      if (localtmp >= -32768.0) {
        localtmp_0 = (SInt16)localtmp;
      } else {
        localtmp_0 = MIN_int16_T;
      }
    } else {
      localtmp_0 = MAX_int16_T;
    }

    localB->Merge[1] = localtmp_0;
    localtmp = ACTEMS_FloorF(((Float32d)(((Float32)((((Float32d)
      rtu_InjrM_prm_tiInjOfsRaw[2]) * 3.2E-006) * ACTEMS_LdexpF((Float32d)
      localLookUpTable, -15))) - (((Float32)rtu_AFA_tiOffInj) *
      3.200000037E-006F))) / 3.2E-006);
    if (localtmp < 32768.0) {
      if (localtmp >= -32768.0) {
        localtmp_0 = (SInt16)localtmp;
      } else {
        localtmp_0 = MIN_int16_T;
      }
    } else {
      localtmp_0 = MAX_int16_T;
    }

    localB->Merge[2] = localtmp_0;
    localtmp = ACTEMS_FloorF(((Float32d)(((Float32)((((Float32d)
      rtu_InjrM_prm_tiInjOfsRaw[3]) * 3.2E-006) * ACTEMS_LdexpF((Float32d)
      localLookUpTable, -15))) - (((Float32)rtu_AFA_tiOffInj) *
      3.200000037E-006F))) / 3.2E-006);
    if (localtmp < 32768.0) {
      if (localtmp >= -32768.0) {
        localtmp_0 = (SInt16)localtmp;
      } else {
        localtmp_0 = MIN_int16_T;
      }
    } else {
      localtmp_0 = MAX_int16_T;
    }

    localB->Merge[3] = localtmp_0;
  }
}

/* Output and update for function-call system: '<S1>/F01_InjrMdl_EveRst' */
void InjrMdl_F01_InjrMdl_EveRst(void)
{
  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET3 */
  VEMS_vidGET(Ext_uBatt, InjrMdl_B.VEMS_vidGET3_c);

  /* DataTypeConversion Block: '<S32>/Data Type Conversion'
   *
   * Regarding '<S32>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET2 */
  VEMS_vidGET(AFA_tiOffInj, InjrMdl_B.VEMS_vidGET2_e);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET */
  VEMS_vidGET(AFA_facIvsInjGain, InjrMdl_B.VEMS_vidGET_p);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET1 */
  VEMS_vidGET(AFA_facSlopInjGain, InjrMdl_B.VEMS_vidGET1_o);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET4 */
  VEMS_vidGET(FuSysM_tFu, InjrMdl_B.VEMS_vidGET4_m);

  /* DataTypeConversion Block: '<S34>/Data Type Conversion'
   *
   * Regarding '<S34>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET8 */
  VEMS_vidGET1DArray(InjrM_prm_tiInjOfsRaw, 4, InjrMdl_B.VEMS_vidGET8_b);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET7 */
  VEMS_vidGET1DArray(InjrM_prm_pDifInjr, 4, InjrMdl_B.VEMS_vidGET7_g);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET6 */
  VEMS_vidGET1DArray(InjrM_prm_facGainLnrlnjRaw, 4, InjrMdl_B.VEMS_vidGET6_b);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET5 */
  VEMS_vidGET1DArray(InjrM_prm_facCorGainLnr, 4, InjrMdl_B.VEMS_vidGET5_i);

  /* Outputs for atomic SubSystem: '<S8>/F01_InjrMdl' */
  InjrMdl_F01_InjrMdl(InjrMdl_B.VEMS_vidGET4_m, InjrMdl_B.VEMS_vidGET6_b,
                      InjrMdl_B.VEMS_vidGET7_g, InjrMdl_B.VEMS_vidGET1_o,
                      InjrMdl_B.VEMS_vidGET_p, InjrMdl_B.VEMS_vidGET5_i,
                      InjrMdl_B.VEMS_vidGET3_c, InjrMdl_B.VEMS_vidGET8_b,
                      InjrMdl_B.VEMS_vidGET2_e, &InjrMdl_B.F01_InjrMdl_b);

  /* end of Outputs for SubSystem: '<S8>/F01_InjrMdl' */

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET */
  VEMS_vidSET1DArray(InjrM_prm_facGainInj, 4, InjrMdl_B.F01_InjrMdl_b.Merge1);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET1 */
  VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInj, 4, InjrMdl_B.F01_InjrMdl_b.Merge);
}

/* Output and update for function-call system: '<S9>/F01_InjrMdlSyncRst' */
void InjrMdl_F01_InjrMdlSyncRst(void)
{
  /* S-Function "vems_vidGET" Block: <S38>/VEMS_vidGET1 */
  VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInj, 4, InjrMdl_B.VEMS_vidGET1_l);

  /* SignalConversion: '<S38>/TmpSignal ConversionAtVEMS_vidSET4Inport1' */
  InjrMdl_B.TmpSignalConversionAtVEMS_vidSE[0] = InjrMdl_B.VEMS_vidGET1_l[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vidSE[1] = InjrMdl_B.VEMS_vidGET1_l[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vidSE[2] = InjrMdl_B.VEMS_vidGET1_l[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vidSE[3] = InjrMdl_B.VEMS_vidGET1_l[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vidSE[4] = InjrMdl_B.VEMS_vidGET1_l[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vidSE[5] = InjrMdl_B.VEMS_vidGET1_l[0];

  /* SignalConversion: '<S38>/TmpSignal ConversionAtVEMS_vidSET5Inport1' */
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_n[0] = InjrMdl_B.VEMS_vidGET1_l[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_n[1] = InjrMdl_B.VEMS_vidGET1_l[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_n[2] = InjrMdl_B.VEMS_vidGET1_l[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_n[3] = InjrMdl_B.VEMS_vidGET1_l[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_n[4] = InjrMdl_B.VEMS_vidGET1_l[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_n[5] = InjrMdl_B.VEMS_vidGET1_l[1];

  /* SignalConversion: '<S38>/TmpSignal ConversionAtVEMS_vidSET6Inport1' */
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_m[0] = InjrMdl_B.VEMS_vidGET1_l[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_m[1] = InjrMdl_B.VEMS_vidGET1_l[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_m[2] = InjrMdl_B.VEMS_vidGET1_l[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_m[3] = InjrMdl_B.VEMS_vidGET1_l[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_m[4] = InjrMdl_B.VEMS_vidGET1_l[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_m[5] = InjrMdl_B.VEMS_vidGET1_l[2];

  /* SignalConversion: '<S38>/TmpSignal ConversionAtVEMS_vidSET7Inport1' */
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_j[0] = InjrMdl_B.VEMS_vidGET1_l[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_j[1] = InjrMdl_B.VEMS_vidGET1_l[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_j[2] = InjrMdl_B.VEMS_vidGET1_l[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_j[3] = InjrMdl_B.VEMS_vidGET1_l[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_j[4] = InjrMdl_B.VEMS_vidGET1_l[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_j[5] = InjrMdl_B.VEMS_vidGET1_l[3];

  /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET4 */
  VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjH1Cyl, 6,
                     InjrMdl_B.TmpSignalConversionAtVEMS_vidSE);

  /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET5 */
  VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjH2Cyl, 6,
                     InjrMdl_B.TmpSignalConversionAtVEMS_vid_n);

  /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET6 */
  VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjS1Cyl, 6,
                     InjrMdl_B.TmpSignalConversionAtVEMS_vid_m);

  /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET7 */
  VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjS2Cyl, 6,
                     InjrMdl_B.TmpSignalConversionAtVEMS_vid_j);

  /* S-Function "vems_vidGET" Block: <S38>/VEMS_vidGET */
  VEMS_vidGET1DArray(InjrM_prm_facGainInj, 4, InjrMdl_B.VEMS_vidGET_e);

  /* SignalConversion: '<S38>/TmpSignal ConversionAtVEMS_vidSET1Inport1' */
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_d[0] = InjrMdl_B.VEMS_vidGET_e[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_d[1] = InjrMdl_B.VEMS_vidGET_e[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_d[2] = InjrMdl_B.VEMS_vidGET_e[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_d[3] = InjrMdl_B.VEMS_vidGET_e[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_d[4] = InjrMdl_B.VEMS_vidGET_e[1];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_d[5] = InjrMdl_B.VEMS_vidGET_e[1];

  /* SignalConversion: '<S38>/TmpSignal ConversionAtVEMS_vidSET2Inport1' */
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_p[0] = InjrMdl_B.VEMS_vidGET_e[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_p[1] = InjrMdl_B.VEMS_vidGET_e[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_p[2] = InjrMdl_B.VEMS_vidGET_e[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_p[3] = InjrMdl_B.VEMS_vidGET_e[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_p[4] = InjrMdl_B.VEMS_vidGET_e[2];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_p[5] = InjrMdl_B.VEMS_vidGET_e[2];

  /* SignalConversion: '<S38>/TmpSignal ConversionAtVEMS_vidSET3Inport1' */
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_c[0] = InjrMdl_B.VEMS_vidGET_e[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_c[1] = InjrMdl_B.VEMS_vidGET_e[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_c[2] = InjrMdl_B.VEMS_vidGET_e[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_c[3] = InjrMdl_B.VEMS_vidGET_e[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_c[4] = InjrMdl_B.VEMS_vidGET_e[3];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_c[5] = InjrMdl_B.VEMS_vidGET_e[3];

  /* SignalConversion: '<S38>/TmpSignal ConversionAtVEMS_vidSETInport1' */
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_o[0] = InjrMdl_B.VEMS_vidGET_e[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_o[1] = InjrMdl_B.VEMS_vidGET_e[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_o[2] = InjrMdl_B.VEMS_vidGET_e[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_o[3] = InjrMdl_B.VEMS_vidGET_e[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_o[4] = InjrMdl_B.VEMS_vidGET_e[0];
  InjrMdl_B.TmpSignalConversionAtVEMS_vid_o[5] = InjrMdl_B.VEMS_vidGET_e[0];

  /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET */
  VEMS_vidSET1DArray(InjrM_prm_facGainInjH1Cyl, 6,
                     InjrMdl_B.TmpSignalConversionAtVEMS_vid_o);

  /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET1 */
  VEMS_vidSET1DArray(InjrM_prm_facGainInjH2Cyl, 6,
                     InjrMdl_B.TmpSignalConversionAtVEMS_vid_d);

  /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET2 */
  VEMS_vidSET1DArray(InjrM_prm_facGainInjS1Cyl, 6,
                     InjrMdl_B.TmpSignalConversionAtVEMS_vid_p);

  /* S-Function "vems_vidSET" Block: <S38>/VEMS_vidSET3 */
  VEMS_vidSET1DArray(InjrM_prm_facGainInjS2Cyl, 6,
                     InjrMdl_B.TmpSignalConversionAtVEMS_vid_c);
}

/* Start for exported function: InjrM_EveRst_InjrMdl */
void InjrM_EveRst_InjrMdl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjrMdl_fc_demux1'
   */

  /* Start for S-Function (fcncallgen): '<S10>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S1>/F01_InjrMdl_EveRst'
   *  Start for SubSystem: '<S9>/F01_InjrMdlSyncRst'
   */
}

/* Output and update for exported function: InjrM_EveRst_InjrMdl */
void InjrM_EveRst_InjrMdl(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrMdl_fc_demux1'
   */

  /* S-Function (fcncallgen): '<S10>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/F01_InjrMdl_EveRst'
   *  SubSystem: '<S9>/F01_InjrMdlSyncRst'
   */
  InjrMdl_F01_InjrMdl_EveRst();
  InjrMdl_F01_InjrMdlSyncRst();
}

/* Output and update for function-call system: '<S1>/F01_InjrMdl' */
void InjrMdl_F01_InjrMdl_g(void)
{
  /* Outputs for enable SubSystem: '<S7>/F01_InjrMdl' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/INJRMDL_u8Inhib'
   *  EnablePort: '<S15>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (INJRMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_uBatt, InjrMdl_B.VEMS_vidGET3);

    /* DataTypeConversion Block: '<S21>/Data Type Conversion'
     *
     * Regarding '<S21>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET2 */
    VEMS_vidGET(AFA_tiOffInj, InjrMdl_B.VEMS_vidGET2_i);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET */
    VEMS_vidGET(AFA_facIvsInjGain, InjrMdl_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET1 */
    VEMS_vidGET(AFA_facSlopInjGain, InjrMdl_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET4 */
    VEMS_vidGET(FuSysM_tFu, InjrMdl_B.VEMS_vidGET4);

    /* DataTypeConversion Block: '<S23>/Data Type Conversion'
     *
     * Regarding '<S23>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsRaw, 4, InjrMdl_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjrM_prm_pDifInjr, 4, InjrMdl_B.VEMS_vidGET7_m);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjrM_prm_facGainLnrlnjRaw, 4, InjrMdl_B.VEMS_vidGET6_d);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjrM_prm_facCorGainLnr, 4, InjrMdl_B.VEMS_vidGET5_c);

    /* Outputs for atomic SubSystem: '<S15>/F01_InjrMdl' */
    InjrMdl_F01_InjrMdl(InjrMdl_B.VEMS_vidGET4, InjrMdl_B.VEMS_vidGET6_d,
                        InjrMdl_B.VEMS_vidGET7_m, InjrMdl_B.VEMS_vidGET1,
                        InjrMdl_B.VEMS_vidGET, InjrMdl_B.VEMS_vidGET5_c,
                        InjrMdl_B.VEMS_vidGET3, InjrMdl_B.VEMS_vidGET8,
                        InjrMdl_B.VEMS_vidGET2_i, &InjrMdl_B.F01_InjrMdl_j);

    /* end of Outputs for SubSystem: '<S15>/F01_InjrMdl' */

    /* S-Function "vems_vidSET" Block: <S15>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjrM_prm_facGainInj, 4, InjrMdl_B.F01_InjrMdl_j.Merge1);

    /* S-Function "vems_vidSET" Block: <S15>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInj, 4, InjrMdl_B.F01_InjrMdl_j.Merge);
  }

  /* end of Outputs for SubSystem: '<S7>/F01_InjrMdl' */
}

/* Output and update for function-call system: '<S9>/F02_InjrMdlSyncEveClcn' */
void InjrMdl_F02_InjrMdlSyncEveClcn(void)
{
  Boolean localRelationalOperator;
  SInt16 localAssignment1[6];
  SInt16 localAssignment2[6];
  SInt16 localAssignment3[6];
  SInt16 localAssignment4[6];
  UInt16 localAssignment5[6];
  UInt16 localAssignment6[6];
  UInt16 localAssignment7[6];
  UInt16 localAssignment8[6];
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S39>/F02_InjrMdlSyncEveClcn' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Constant: '<S39>/INJRMDL_u8Inhib'
   *  EnablePort: '<S41>/Enable'
   *  RelationalOperator: '<S39>/Relational Operator'
   */
  if (INJRMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjH2Cyl, 6,
                       InjrM_prm_tiInjOfsH2CylPrev);

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInj, 4, InjrMdl_B.VEMS_vidGET6_g);

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInCyl, InjrMdl_B.VEMS_vidGET1_gl);

    /* Assignment: '<S41>/Assignment1' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment1[locali] = InjrM_prm_tiInjOfsH2CylPrev[(locali)];
    }

    localAssignment1[InjrMdl_B.VEMS_vidGET1_gl - 1] = InjrMdl_B.VEMS_vidGET6_g[1];

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjH1Cyl, 6,
                       InjrM_prm_tiInjOfsH1CylPrev);

    /* Assignment: '<S41>/Assignment2' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment2[locali] = InjrM_prm_tiInjOfsH1CylPrev[(locali)];
    }

    localAssignment2[InjrMdl_B.VEMS_vidGET1_gl - 1] = InjrMdl_B.VEMS_vidGET6_g[0];

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjS1Cyl, 6,
                       InjrM_prm_tiInjOfsS1CylPrev);

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET */
    VEMS_vidGET(Eng_noCmprCyl, InjrMdl_B.VEMS_vidGET_o);

    /* Assignment: '<S41>/Assignment3' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment3[locali] = InjrM_prm_tiInjOfsS1CylPrev[(locali)];
    }

    localAssignment3[InjrMdl_B.VEMS_vidGET_o - 1] = InjrMdl_B.VEMS_vidGET6_g[2];

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjS2Cyl, 6,
                       InjrM_prm_tiInjOfsS2CylPrev);

    /* Assignment: '<S41>/Assignment4' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment4[locali] = InjrM_prm_tiInjOfsS2CylPrev[(locali)];
    }

    localAssignment4[InjrMdl_B.VEMS_vidGET_o - 1] = InjrMdl_B.VEMS_vidGET6_g[3];

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjH1Cyl, 6, InjrM_prm_facGainH1CylPrev);

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInj, 4, InjrMdl_B.VEMS_vidGET5_f);

    /* Assignment: '<S41>/Assignment5' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment5[locali] = InjrM_prm_facGainH1CylPrev[(locali)];
    }

    localAssignment5[InjrMdl_B.VEMS_vidGET1_gl - 1] = InjrMdl_B.VEMS_vidGET5_f[0];

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjH2Cyl, 6, InjrM_prm_facGainH2CylPrev);

    /* Assignment: '<S41>/Assignment6' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment6[locali] = InjrM_prm_facGainH2CylPrev[(locali)];
    }

    localAssignment6[InjrMdl_B.VEMS_vidGET1_gl - 1] = InjrMdl_B.VEMS_vidGET5_f[1];

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjS1Cyl, 6, InjrM_prm_facGainS1CylPrev);

    /* Assignment: '<S41>/Assignment7' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment7[locali] = InjrM_prm_facGainS1CylPrev[(locali)];
    }

    localAssignment7[InjrMdl_B.VEMS_vidGET_o - 1] = InjrMdl_B.VEMS_vidGET5_f[2];

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET14 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjS2Cyl, 6, InjrM_prm_facGainS2CylPrev);

    /* Assignment: '<S41>/Assignment8' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment8[locali] = InjrM_prm_facGainS2CylPrev[(locali)];
    }

    localAssignment8[InjrMdl_B.VEMS_vidGET_o - 1] = InjrMdl_B.VEMS_vidGET5_f[3];

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_stTypElCmdInjrReq, InjrMdl_B.VEMS_vidGET3_m);

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_stTypElCmdInjrReqPrev, InjrMdl_B.VEMS_vidGET4_mh);

    /* RelationalOperator: '<S41>/Relational Operator' */
    localRelationalOperator = (InjrMdl_B.VEMS_vidGET3_m !=
      InjrMdl_B.VEMS_vidGET4_mh);

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET2 */
    VEMS_vidGET(InjSys_noInCylElCmdUpd, InjrMdl_B.VEMS_vidGET2_d);

    /* Logic: '<S41>/Logical Operator' incorporates:
     *  RelationalOperator: '<S41>/Relational Operator1'
     */
    InjrMdl_B.LogicalOperator = ((localRelationalOperator) &&
      (InjrMdl_B.VEMS_vidGET2_d == InjrMdl_B.VEMS_vidGET1_gl));
    for (locali = 0; locali < 6; locali++) {
      /* Switch: '<S41>/Switch' */
      if (InjrMdl_B.LogicalOperator) {
        InjrMdl_B.Switch[(locali)] = InjrM_prm_tiInjOfsH1CylPrev[(locali)];
      } else {
        InjrMdl_B.Switch[(locali)] = localAssignment2[locali];
      }

      /* Switch: '<S41>/Switch1' */
      if (InjrMdl_B.LogicalOperator) {
        InjrMdl_B.Switch1[(locali)] = InjrM_prm_tiInjOfsH2CylPrev[(locali)];
      } else {
        InjrMdl_B.Switch1[(locali)] = localAssignment1[locali];
      }

      /* Switch: '<S41>/Switch2' */
      if (InjrMdl_B.LogicalOperator) {
        InjrMdl_B.Switch2[(locali)] = InjrM_prm_tiInjOfsS1CylPrev[(locali)];
      } else {
        InjrMdl_B.Switch2[(locali)] = localAssignment3[locali];
      }

      /* Switch: '<S41>/Switch3' */
      if (InjrMdl_B.LogicalOperator) {
        InjrMdl_B.Switch3[(locali)] = InjrM_prm_tiInjOfsS2CylPrev[(locali)];
      } else {
        InjrMdl_B.Switch3[(locali)] = localAssignment4[locali];
      }

      /* Switch: '<S41>/Switch4' */
      if (InjrMdl_B.LogicalOperator) {
        InjrMdl_B.Switch4[(locali)] = InjrM_prm_facGainH1CylPrev[(locali)];
      } else {
        InjrMdl_B.Switch4[(locali)] = localAssignment5[locali];
      }

      /* Switch: '<S41>/Switch5' */
      if (InjrMdl_B.LogicalOperator) {
        InjrMdl_B.Switch5[(locali)] = InjrM_prm_facGainH2CylPrev[(locali)];
      } else {
        InjrMdl_B.Switch5[(locali)] = localAssignment6[locali];
      }

      /* Switch: '<S41>/Switch6' */
      if (InjrMdl_B.LogicalOperator) {
        InjrMdl_B.Switch6[(locali)] = InjrM_prm_facGainS1CylPrev[(locali)];
      } else {
        InjrMdl_B.Switch6[(locali)] = localAssignment7[locali];
      }

      /* Switch: '<S41>/Switch7' */
      if (InjrMdl_B.LogicalOperator) {
        InjrMdl_B.Switch7[(locali)] = InjrM_prm_facGainS2CylPrev[(locali)];
      } else {
        InjrMdl_B.Switch7[(locali)] = localAssignment8[locali];
      }
    }

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET */
    VEMS_vidSET(InjrM_bInhInjrMUpd, InjrMdl_B.LogicalOperator);

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjrM_prm_facGainInjH1Cyl, 6, InjrMdl_B.Switch4);

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjrM_prm_facGainInjH2Cyl, 6, InjrMdl_B.Switch5);

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjrM_prm_facGainInjS1Cyl, 6, InjrMdl_B.Switch6);

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(InjrM_prm_facGainInjS2Cyl, 6, InjrMdl_B.Switch7);

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjH1Cyl, 6, InjrMdl_B.Switch);

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET6 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjH2Cyl, 6, InjrMdl_B.Switch1);

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET7 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjS1Cyl, 6, InjrMdl_B.Switch2);

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET8 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjS2Cyl, 6, InjrMdl_B.Switch3);
  }

  /* end of Outputs for SubSystem: '<S39>/F02_InjrMdlSyncEveClcn' */
}

/* Start for exported function: InjrM_EveCkSnOn_InjrMdl */
void InjrM_EveCkSnOn_InjrMdl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjrMdl_fc_demux2'
   */

  /* Start for S-Function (fcncallgen): '<S11>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S1>/F01_InjrMdl'
   *  Start for SubSystem: '<S9>/F02_InjrMdlSyncEveClcn'
   */
}

/* Output and update for exported function: InjrM_EveCkSnOn_InjrMdl */
void InjrM_EveCkSnOn_InjrMdl(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrMdl_fc_demux2'
   */

  /* S-Function (fcncallgen): '<S11>/Function-Call Generator' */
  InjrMdl_ASYNC3(0);
  InjrMdl_ASYNC2(0);
}

/* Output and update for exported function: InjrM_SdlFast_InjrMdl */
void InjrM_SdlFast_InjrMdl(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrMdl_fc_demux3'
   */

  /* S-Function (fcncallgen): '<S12>/Function-Call Generator' */
  InjrMdl_ASYNC3(1);
  InjrMdl_ASYNC2(1);
}

/* Output and update for function-call system: '<S9>/F03_InjrMdlSyncEveInj' */
void InjrMdl_F03_InjrMdlSyncEveInj(void)
{
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S40>/F03_InjrMdlSyncEveInj' incorporates:
   *  Constant: '<S40>/Constant1'
   *  Constant: '<S40>/INJRMDL_u8Inhib'
   *  EnablePort: '<S42>/Enable'
   *  RelationalOperator: '<S40>/Relational Operator'
   */
  if (INJRMDL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjH2Cyl, 6, InjrMdl_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInj, 4, InjrMdl_B.VEMS_vidGET3_p);

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, InjrMdl_B.VEMS_vidGET1_g);

    /* Assignment: '<S42>/Assignment1' */
    for (locali = 0; locali < 6; locali++) {
      InjrMdl_B.Assignment1[(locali)] = InjrMdl_B.VEMS_vidGET5[(locali)];
    }

    InjrMdl_B.Assignment1[InjrMdl_B.VEMS_vidGET1_g - 1] =
      InjrMdl_B.VEMS_vidGET3_p[1];

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjS1Cyl, 6, InjrMdl_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInCyl, InjrMdl_B.VEMS_vidGET_g);

    /* Assignment: '<S42>/Assignment2' */
    for (locali = 0; locali < 6; locali++) {
      InjrMdl_B.Assignment2[(locali)] = InjrMdl_B.VEMS_vidGET6[(locali)];
    }

    InjrMdl_B.Assignment2[InjrMdl_B.VEMS_vidGET_g - 1] =
      InjrMdl_B.VEMS_vidGET3_p[2];

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjS2Cyl, 6, InjrMdl_B.VEMS_vidGET7);

    /* Assignment: '<S42>/Assignment3' */
    for (locali = 0; locali < 6; locali++) {
      InjrMdl_B.Assignment3[(locali)] = InjrMdl_B.VEMS_vidGET7[(locali)];
    }

    InjrMdl_B.Assignment3[InjrMdl_B.VEMS_vidGET_g - 1] =
      InjrMdl_B.VEMS_vidGET3_p[3];

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjH1Cyl, 6, InjrMdl_B.VEMS_vidGET8_m);

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInj, 4, InjrMdl_B.VEMS_vidGET2);

    /* Assignment: '<S42>/Assignment4' */
    for (locali = 0; locali < 6; locali++) {
      InjrMdl_B.Assignment4[(locali)] = InjrMdl_B.VEMS_vidGET8_m[(locali)];
    }

    InjrMdl_B.Assignment4[InjrMdl_B.VEMS_vidGET1_g - 1] =
      InjrMdl_B.VEMS_vidGET2[0];

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjH2Cyl, 6, InjrMdl_B.VEMS_vidGET9);

    /* Assignment: '<S42>/Assignment5' */
    for (locali = 0; locali < 6; locali++) {
      InjrMdl_B.Assignment5[(locali)] = InjrMdl_B.VEMS_vidGET9[(locali)];
    }

    InjrMdl_B.Assignment5[InjrMdl_B.VEMS_vidGET1_g - 1] =
      InjrMdl_B.VEMS_vidGET2[1];

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjS1Cyl, 6, InjrMdl_B.VEMS_vidGET10);

    /* Assignment: '<S42>/Assignment6' */
    for (locali = 0; locali < 6; locali++) {
      InjrMdl_B.Assignment6[(locali)] = InjrMdl_B.VEMS_vidGET10[(locali)];
    }

    InjrMdl_B.Assignment6[InjrMdl_B.VEMS_vidGET_g - 1] = InjrMdl_B.VEMS_vidGET2
      [2];

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInjS2Cyl, 6, InjrMdl_B.VEMS_vidGET11);

    /* Assignment: '<S42>/Assignment7' */
    for (locali = 0; locali < 6; locali++) {
      InjrMdl_B.Assignment7[(locali)] = InjrMdl_B.VEMS_vidGET11[(locali)];
    }

    InjrMdl_B.Assignment7[InjrMdl_B.VEMS_vidGET_g - 1] = InjrMdl_B.VEMS_vidGET2
      [3];

    /* S-Function "vems_vidGET" Block: <S42>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInjH1Cyl, 6, InjrMdl_B.VEMS_vidGET4_a);

    /* Assignment: '<S42>/Assignment8' */
    for (locali = 0; locali < 6; locali++) {
      InjrMdl_B.Assignment8[(locali)] = InjrMdl_B.VEMS_vidGET4_a[(locali)];
    }

    InjrMdl_B.Assignment8[InjrMdl_B.VEMS_vidGET1_g - 1] =
      InjrMdl_B.VEMS_vidGET3_p[0];

    /* S-Function "vems_vidSET" Block: <S42>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjrM_prm_facGainInjH1Cyl, 6, InjrMdl_B.Assignment4);

    /* S-Function "vems_vidSET" Block: <S42>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjrM_prm_facGainInjH2Cyl, 6, InjrMdl_B.Assignment5);

    /* S-Function "vems_vidSET" Block: <S42>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjrM_prm_facGainInjS1Cyl, 6, InjrMdl_B.Assignment6);

    /* S-Function "vems_vidSET" Block: <S42>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjrM_prm_facGainInjS2Cyl, 6, InjrMdl_B.Assignment7);

    /* S-Function "vems_vidSET" Block: <S42>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjH1Cyl, 6, InjrMdl_B.Assignment8);

    /* S-Function "vems_vidSET" Block: <S42>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjH2Cyl, 6, InjrMdl_B.Assignment1);

    /* S-Function "vems_vidSET" Block: <S42>/VEMS_vidSET6 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjS1Cyl, 6, InjrMdl_B.Assignment2);

    /* S-Function "vems_vidSET" Block: <S42>/VEMS_vidSET7 */
    VEMS_vidSET1DArray(InjrM_prm_tiInjOfsInjS2Cyl, 6, InjrMdl_B.Assignment3);
  }

  /* end of Outputs for SubSystem: '<S40>/F03_InjrMdlSyncEveInj' */
}

/* Start for exported function: InjrM_EveInj_InjrMdl */
void InjrM_EveInj_InjrMdl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjrMdl_fc_demux4'
   */
}

/* Output and update for exported function: InjrM_EveInj_InjrMdl */
void InjrM_EveInj_InjrMdl(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrMdl_fc_demux4'
   */

  /* S-Function (fcncallgen): '<S13>/Function-Call Generator' incorporates:
   *  SubSystem: '<S9>/F03_InjrMdlSyncEveInj'
   */
  InjrMdl_ASYNC3(2);
  InjrMdl_F03_InjrMdlSyncEveInj();
}

/* Output and update for exported function: InjrM_EveSpl_InjrMdl */
void InjrM_EveSpl_InjrMdl(void)
{
  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjrMdl_fc_demux5'
   */

  /* S-Function (fcncallgen): '<S14>/Function-Call Generator' */
  InjrMdl_ASYNC3(3);
  InjrMdl_ASYNC2(2);
}

/* Model initialize function */
void InjrMdl_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  InjrM_EveRst_InjrMdl_Start();
  InjrM_EveCkSnOn_InjrMdl_Start();
  InjrM_EveInj_InjrMdl_Start();
}

#define INJRMDL_STOP_SEC_CODE
#include "InjrMdl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
