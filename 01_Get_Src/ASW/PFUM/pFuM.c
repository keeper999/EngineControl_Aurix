/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pFuM                                                    */
/* !Description     : FUEL PRESSURE MODEL                                     */
/*                                                                            */
/* !Module          : pFuM                                                    */
/*                                                                            */
/* !File            : pFuM.c                                                  */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : V02NT1202018 / 01                                       */
/* !OtherRefs       : VEMS V02 ECU#062213                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Sun Jul 15 20:51:22 2012                              */
/*   Model name       : pFuM_AUTOCODE.mdl                                     */
/*   Model version    : 1.1269                                                */
/*   Root subsystem   : /pFuM                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/pFuM/5-SOFT-LIV/pFuM.c_v    $*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   16 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "pFuM.h"
#include "pFuM_private.h"

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
#define PFUM_START_SEC_VAR_UNSPECIFIED
#include "pFuM_MemMap.h"

/* Block signals (auto storage) */
BlockIO_pFuM pFuM_B;

#define PFUM_STOP_SEC_VAR_UNSPECIFIED
#include "pFuM_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define PFUM_START_SEC_CODE
#include "pFuM_MemMap.h"

void pFuM_ASYNC1(int controlPortIdx)
{
}

void pFuM_ASYNC2(int controlPortIdx)
{
  pFuM_F01_pFuMSyncEveClcn();
}

void pFuM_ASYNC3(int controlPortIdx)
{
  pFuM_F02_PFuMdl();
}

void pFuM_ASYNC6(int controlPortIdx)
{
  pFuM_F01_init1();
}

/*
 * Output and update for atomic system:
 *    '<S22>/F01_init'
 *    '<S30>/F01_init'
 */
void pFuM_F01_init(UInt16 rtu_Ext_pFuRailSplMes, UInt16 rtu_FuSysM_tFu,
                   rtB_F01_init_pFuM *localB)
{
  /* Lookup2D: '<S29>/Look-Up Table (2-D)'
   * About '<S29>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
   * Input1  Data Type:  Fixed Point    U16  Bias 233.0
   * Output0 Data Type:  Fixed Point    U16  2^20  FSlope 1.1641532182693481E+000
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localB->LookUpTable2D), (&(FuSysM_facCnvMassFuPFu_M[0])),
                     rtu_Ext_pFuRailSplMes, (&(FuSysM_pFuRailMes_A[0])), 15U,
                     rtu_FuSysM_tFu, (&(FuSysM_tFu_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate2'
   *
   * Regarding '<S29>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* SignalConversion: '<S28>/Signal Conversion' */
  localB->SignalConversion = rtu_Ext_pFuRailSplMes;

  /* SignalConversion: '<S28>/Signal Conversion1' */
  localB->SignalConversion1 = rtu_Ext_pFuRailSplMes;

  /* SignalConversion: '<S28>/Signal Conversion2' */
  localB->SignalConversion2 = rtu_Ext_pFuRailSplMes;

  /* SignalConversion: '<S28>/Signal Conversion3' */
  localB->SignalConversion3 = rtu_Ext_pFuRailSplMes;
}

/* Output and update for function-call system: '<S8>/F01_init' */
void pFuM_F01_init_o(void)
{
  /* S-Function "vems_vidGET" Block: <S22>/VEMS_vidGET */
  VEMS_vidGET(Ext_pFuRailSplMes, pFuM_B.VEMS_vidGET_a);

  /* DataTypeConversion Block: '<S29>/Data Type Conversion'
   *
   * Regarding '<S29>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* S-Function "vems_vidGET" Block: <S22>/VEMS_vidGET1 */
  VEMS_vidGET(FuSysM_tFu, pFuM_B.VEMS_vidGET1_m);

  /* DataTypeConversion Block: '<S29>/Data Type Conversion1'
   *
   * Regarding '<S29>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate1'
   *
   * Regarding '<S29>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Outputs for atomic SubSystem: '<S22>/F01_init' */
  pFuM_F01_init(pFuM_B.VEMS_vidGET_a, pFuM_B.VEMS_vidGET1_m, &pFuM_B.F01_init_c);

  /* end of Outputs for SubSystem: '<S22>/F01_init' */

  /* S-Function "vems_vidSET" Block: <S22>/VEMS_vidSET */
  VEMS_vidSET(FuSysM_facCnvMassFuPFu, pFuM_B.F01_init_c.LookUpTable2D);

  /* S-Function "vems_vidSET" Block: <S22>/VEMS_vidSET6 */
  VEMS_vidSET(FuSysM_pFuEstimInjH1, pFuM_B.F01_init_c.SignalConversion);

  /* S-Function "vems_vidSET" Block: <S22>/VEMS_vidSET7 */
  VEMS_vidSET(FuSysM_pFuEstimInjH2, pFuM_B.F01_init_c.SignalConversion1);

  /* S-Function "vems_vidSET" Block: <S22>/VEMS_vidSET8 */
  VEMS_vidSET(FuSysM_pFuEstimInjS1, pFuM_B.F01_init_c.SignalConversion2);

  /* S-Function "vems_vidSET" Block: <S22>/VEMS_vidSET9 */
  VEMS_vidSET(FuSysM_pFuEstimInjS2, pFuM_B.F01_init_c.SignalConversion3);
}

/*
 * Output and update for atomic system:
 *    '<S415>/F00_pFuMSyncEveRst'
 *    '<S422>/F00_pFuMSyncEveRst'
 */
void pFuM_F00_pFuMSyncEveRst(UInt16 rtu_0, UInt16 rtu_1, UInt16 rtu_2,
  UInt16 rtu_3, rtB_F00_pFuMSyncEveRst_pFuM *localB)
{
  /* Inport: '<S421>/FuSysM_pFuEstimInjH1' */
  localB->FuSysM_pFuEstimInjH1_d = rtu_0;

  /* Inport: '<S421>/FuSysM_pFuEstimInjH2' */
  localB->FuSysM_pFuEstimInjH2_a = rtu_1;

  /* Inport: '<S421>/FuSysM_pFuEstimInjS1' */
  localB->FuSysM_pFuEstimInjS1_e = rtu_2;

  /* Inport: '<S421>/FuSysM_pFuEstimInjS2' */
  localB->FuSysM_pFuEstimInjS2_n = rtu_3;
}

/* Output and update for function-call system: '<S9>/F00_pFuMSyncEveRst' */
void pFuM_F00_pFuMSyncEveRst_a(void)
{
  /* S-Function "vems_vidGET" Block: <S415>/VEMS_vidGET */
  VEMS_vidGET(FuSysM_pFuEstimInjH1, pFuM_B.VEMS_vidGET_l);

  /* S-Function "vems_vidGET" Block: <S415>/VEMS_vidGET1 */
  VEMS_vidGET(FuSysM_pFuEstimInjH2, pFuM_B.VEMS_vidGET1_a);

  /* S-Function "vems_vidGET" Block: <S415>/VEMS_vidGET2 */
  VEMS_vidGET(FuSysM_pFuEstimInjS1, pFuM_B.VEMS_vidGET2_f);

  /* S-Function "vems_vidGET" Block: <S415>/VEMS_vidGET3 */
  VEMS_vidGET(FuSysM_pFuEstimInjS2, pFuM_B.VEMS_vidGET3_h);

  /* Outputs for atomic SubSystem: '<S415>/F00_pFuMSyncEveRst' */
  pFuM_F00_pFuMSyncEveRst(pFuM_B.VEMS_vidGET_l, pFuM_B.VEMS_vidGET1_a,
    pFuM_B.VEMS_vidGET2_f, pFuM_B.VEMS_vidGET3_h, &pFuM_B.F00_pFuMSyncEveRst_i);

  /* end of Outputs for SubSystem: '<S415>/F00_pFuMSyncEveRst' */

  /* SignalConversion: '<S415>/TmpSignal ConversionAtVEMS_vidSET10Inport1' */
  pFuM_B.TmpSignalConversionAtVEMS_vid_c[0] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS1_e;
  pFuM_B.TmpSignalConversionAtVEMS_vid_c[1] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS1_e;
  pFuM_B.TmpSignalConversionAtVEMS_vid_c[2] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS1_e;
  pFuM_B.TmpSignalConversionAtVEMS_vid_c[3] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS1_e;
  pFuM_B.TmpSignalConversionAtVEMS_vid_c[4] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS1_e;
  pFuM_B.TmpSignalConversionAtVEMS_vid_c[5] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS1_e;

  /* SignalConversion: '<S415>/TmpSignal ConversionAtVEMS_vidSET11Inport1' */
  pFuM_B.TmpSignalConversionAtVEMS_vid_h[0] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS2_n;
  pFuM_B.TmpSignalConversionAtVEMS_vid_h[1] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS2_n;
  pFuM_B.TmpSignalConversionAtVEMS_vid_h[2] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS2_n;
  pFuM_B.TmpSignalConversionAtVEMS_vid_h[3] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS2_n;
  pFuM_B.TmpSignalConversionAtVEMS_vid_h[4] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS2_n;
  pFuM_B.TmpSignalConversionAtVEMS_vid_h[5] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjS2_n;

  /* SignalConversion: '<S415>/TmpSignal ConversionAtVEMS_vidSET8Inport1' */
  pFuM_B.TmpSignalConversionAtVEMS_vi_ox[0] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH1_d;
  pFuM_B.TmpSignalConversionAtVEMS_vi_ox[1] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH1_d;
  pFuM_B.TmpSignalConversionAtVEMS_vi_ox[2] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH1_d;
  pFuM_B.TmpSignalConversionAtVEMS_vi_ox[3] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH1_d;
  pFuM_B.TmpSignalConversionAtVEMS_vi_ox[4] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH1_d;
  pFuM_B.TmpSignalConversionAtVEMS_vi_ox[5] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH1_d;

  /* SignalConversion: '<S415>/TmpSignal ConversionAtVEMS_vidSET9Inport1' */
  pFuM_B.TmpSignalConversionAtVEMS_vid_a[0] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH2_a;
  pFuM_B.TmpSignalConversionAtVEMS_vid_a[1] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH2_a;
  pFuM_B.TmpSignalConversionAtVEMS_vid_a[2] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH2_a;
  pFuM_B.TmpSignalConversionAtVEMS_vid_a[3] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH2_a;
  pFuM_B.TmpSignalConversionAtVEMS_vid_a[4] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH2_a;
  pFuM_B.TmpSignalConversionAtVEMS_vid_a[5] =
    pFuM_B.F00_pFuMSyncEveRst_i.FuSysM_pFuEstimInjH2_a;

  /* S-Function "vems_vidSET" Block: <S415>/VEMS_vidSET10 */
  VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6,
                     pFuM_B.TmpSignalConversionAtVEMS_vid_c);

  /* S-Function "vems_vidSET" Block: <S415>/VEMS_vidSET11 */
  VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6,
                     pFuM_B.TmpSignalConversionAtVEMS_vid_h);

  /* S-Function "vems_vidSET" Block: <S415>/VEMS_vidSET8 */
  VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6,
                     pFuM_B.TmpSignalConversionAtVEMS_vi_ox);

  /* S-Function "vems_vidSET" Block: <S415>/VEMS_vidSET9 */
  VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6,
                     pFuM_B.TmpSignalConversionAtVEMS_vid_a);
}

/* Start for exported function: FuSysM_EveRst_pFuM */
void FuSysM_EveRst_pFuM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  Start for SubSystem: '<S6>/fc_demux5'
   */

  /* Start for S-Function (fcncallgen): '<S14>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S8>/F01_init'
   *  Start for SubSystem: '<S9>/F00_pFuMSyncEveRst'
   */
}

/* Output and update for exported function: FuSysM_EveRst_pFuM */
void FuSysM_EveRst_pFuM(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S6>/fc_demux5'
   */

  /* S-Function (fcncallgen): '<S14>/Function-Call Generator' incorporates:
   *  SubSystem: '<S8>/F01_init'
   *  SubSystem: '<S9>/F00_pFuMSyncEveRst'
   */
  pFuM_F01_init_o();
  pFuM_F00_pFuMSyncEveRst_a();
}

/* Output and update for function-call system: '<S8>/F01_init1' */
void pFuM_F01_init1(void)
{
  /* Outputs for enable SubSystem: '<S23>/F01_init' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S23>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S30>/Enable'
   *  RelationalOperator: '<S23>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S30>/VEMS_vidGET */
    VEMS_vidGET(Ext_pFuRailSplMes, pFuM_B.VEMS_vidGET_i);

    /* DataTypeConversion Block: '<S32>/Data Type Conversion'
     *
     * Regarding '<S32>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S30>/VEMS_vidGET1 */
    VEMS_vidGET(FuSysM_tFu, pFuM_B.VEMS_vidGET1_o);

    /* DataTypeConversion Block: '<S32>/Data Type Conversion1'
     *
     * Regarding '<S32>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate1'
     *
     * Regarding '<S32>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Outputs for atomic SubSystem: '<S30>/F01_init' */
    pFuM_F01_init(pFuM_B.VEMS_vidGET_i, pFuM_B.VEMS_vidGET1_o,
                  &pFuM_B.F01_init_kp);

    /* end of Outputs for SubSystem: '<S30>/F01_init' */

    /* S-Function "vems_vidSET" Block: <S30>/VEMS_vidSET5 */
    VEMS_vidSET(FuSysM_facCnvMassFuPFu, pFuM_B.F01_init_kp.LookUpTable2D);

    /* S-Function "vems_vidSET" Block: <S30>/VEMS_vidSET6 */
    VEMS_vidSET(FuSysM_pFuEstimInjH1, pFuM_B.F01_init_kp.SignalConversion);

    /* S-Function "vems_vidSET" Block: <S30>/VEMS_vidSET7 */
    VEMS_vidSET(FuSysM_pFuEstimInjH2, pFuM_B.F01_init_kp.SignalConversion1);

    /* S-Function "vems_vidSET" Block: <S30>/VEMS_vidSET8 */
    VEMS_vidSET(FuSysM_pFuEstimInjS1, pFuM_B.F01_init_kp.SignalConversion2);

    /* S-Function "vems_vidSET" Block: <S30>/VEMS_vidSET9 */
    VEMS_vidSET(FuSysM_pFuEstimInjS2, pFuM_B.F01_init_kp.SignalConversion3);
  }

  /* end of Outputs for SubSystem: '<S23>/F01_init' */
}

/* Output and update for function-call system: '<S9>/F01_pFuMSyncEveClcn' */
void pFuM_F01_pFuMSyncEveClcn(void)
{
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S417>/F01_pFuMSyncEveClcn' incorporates:
   *  Constant: '<S417>/Constant1'
   *  Constant: '<S417>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S424>/Enable'
   *  RelationalOperator: '<S417>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6,
                       FuSysM_prm_pFuEstimH1CylPrev);

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET2 */
    VEMS_vidGET(FuSysM_pFuEstimInjH1, pFuM_B.VEMS_vidGET2_a);

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInCyl, pFuM_B.VEMS_vidGET1_n);

    /* Assignment: '<S424>/Assignment4' */
    for (locali = 0; locali < 6; locali++) {
      pFuM_B.Assignment4_l[(locali)] = FuSysM_prm_pFuEstimH1CylPrev[(locali)];
    }

    pFuM_B.Assignment4_l[pFuM_B.VEMS_vidGET1_n - 1] = pFuM_B.VEMS_vidGET2_a;

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6,
                       FuSysM_prm_pFuEstimH2CylPrev);

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET3 */
    VEMS_vidGET(FuSysM_pFuEstimInjH2, pFuM_B.VEMS_vidGET3_i);

    /* Assignment: '<S424>/Assignment5' */
    for (locali = 0; locali < 6; locali++) {
      pFuM_B.Assignment5_e[(locali)] = FuSysM_prm_pFuEstimH2CylPrev[(locali)];
    }

    pFuM_B.Assignment5_e[pFuM_B.VEMS_vidGET1_n - 1] = pFuM_B.VEMS_vidGET3_i;

    /* S-Function "vems_vidSET" Block: <S424>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6, pFuM_B.Assignment4_l);

    /* S-Function "vems_vidSET" Block: <S424>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6, pFuM_B.Assignment5_e);

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6,
                       FuSysM_prm_pFuEstimS1CylPrev);

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET4 */
    VEMS_vidGET(FuSysM_pFuEstimInjS1, pFuM_B.VEMS_vidGET4_l);

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET */
    VEMS_vidGET(Eng_noCmprCyl, pFuM_B.VEMS_vidGET_pt);

    /* Assignment: '<S424>/Assignment1' */
    for (locali = 0; locali < 6; locali++) {
      pFuM_B.Assignment1_a[(locali)] = FuSysM_prm_pFuEstimS1CylPrev[(locali)];
    }

    pFuM_B.Assignment1_a[pFuM_B.VEMS_vidGET_pt - 1] = pFuM_B.VEMS_vidGET4_l;

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6,
                       FuSysM_prm_pFuEstimS2CylPrev);

    /* S-Function "vems_vidGET" Block: <S424>/VEMS_vidGET5 */
    VEMS_vidGET(FuSysM_pFuEstimInjS2, pFuM_B.VEMS_vidGET5_c);

    /* Assignment: '<S424>/Assignment2' */
    for (locali = 0; locali < 6; locali++) {
      pFuM_B.Assignment2_h[(locali)] = FuSysM_prm_pFuEstimS2CylPrev[(locali)];
    }

    pFuM_B.Assignment2_h[pFuM_B.VEMS_vidGET_pt - 1] = pFuM_B.VEMS_vidGET5_c;

    /* S-Function "vems_vidSET" Block: <S424>/VEMS_vidSET6 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6, pFuM_B.Assignment1_a);

    /* S-Function "vems_vidSET" Block: <S424>/VEMS_vidSET7 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6, pFuM_B.Assignment2_h);
  }

  /* end of Outputs for SubSystem: '<S417>/F01_pFuMSyncEveClcn' */
}

/* Start for exported function: FuSysM_EveCkSnOn_pFuM */
void FuSysM_EveCkSnOn_pFuM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S6>/fc_demux3'
   */

  /* Start for S-Function (fcncallgen): '<S12>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S8>/F01_init1'
   *  Start for SubSystem: '<S9>/F01_pFuMSyncEveClcn'
   */
}

/* Output and update for exported function: FuSysM_EveCkSnOn_pFuM */
void FuSysM_EveCkSnOn_pFuM(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S6>/fc_demux3'
   */

  /* S-Function (fcncallgen): '<S12>/Function-Call Generator' */
  pFuM_ASYNC6(0);
  pFuM_ASYNC2(0);
}

/* Output and update for function-call system: '<S9>/F00_pFuMSyncEveRst1' */
void pFuM_F00_pFuMSyncEveRst1(void)
{
  /* Outputs for enable SubSystem: '<S416>/F00_pFuMSyncEveRst' incorporates:
   *  Constant: '<S416>/Constant1'
   *  Constant: '<S416>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S422>/Enable'
   *  RelationalOperator: '<S416>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S422>/VEMS_vidGET */
    VEMS_vidGET(FuSysM_pFuEstimInjH1, pFuM_B.VEMS_vidGET_c);

    /* S-Function "vems_vidGET" Block: <S422>/VEMS_vidGET1 */
    VEMS_vidGET(FuSysM_pFuEstimInjH2, pFuM_B.VEMS_vidGET1_e);

    /* S-Function "vems_vidGET" Block: <S422>/VEMS_vidGET2 */
    VEMS_vidGET(FuSysM_pFuEstimInjS1, pFuM_B.VEMS_vidGET2_k);

    /* S-Function "vems_vidGET" Block: <S422>/VEMS_vidGET3 */
    VEMS_vidGET(FuSysM_pFuEstimInjS2, pFuM_B.VEMS_vidGET3_n);

    /* Outputs for atomic SubSystem: '<S422>/F00_pFuMSyncEveRst' */
    pFuM_F00_pFuMSyncEveRst(pFuM_B.VEMS_vidGET_c, pFuM_B.VEMS_vidGET1_e,
      pFuM_B.VEMS_vidGET2_k, pFuM_B.VEMS_vidGET3_n, &pFuM_B.F00_pFuMSyncEveRst_a);

    /* end of Outputs for SubSystem: '<S422>/F00_pFuMSyncEveRst' */

    /* SignalConversion: '<S422>/TmpSignal ConversionAtVEMS_vidSET10Inport1' */
    pFuM_B.TmpSignalConversionAtVEMS_vidSE[0] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS1_e;
    pFuM_B.TmpSignalConversionAtVEMS_vidSE[1] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS1_e;
    pFuM_B.TmpSignalConversionAtVEMS_vidSE[2] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS1_e;
    pFuM_B.TmpSignalConversionAtVEMS_vidSE[3] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS1_e;
    pFuM_B.TmpSignalConversionAtVEMS_vidSE[4] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS1_e;
    pFuM_B.TmpSignalConversionAtVEMS_vidSE[5] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS1_e;

    /* SignalConversion: '<S422>/TmpSignal ConversionAtVEMS_vidSET11Inport1' */
    pFuM_B.TmpSignalConversionAtVEMS_vid_l[0] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS2_n;
    pFuM_B.TmpSignalConversionAtVEMS_vid_l[1] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS2_n;
    pFuM_B.TmpSignalConversionAtVEMS_vid_l[2] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS2_n;
    pFuM_B.TmpSignalConversionAtVEMS_vid_l[3] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS2_n;
    pFuM_B.TmpSignalConversionAtVEMS_vid_l[4] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS2_n;
    pFuM_B.TmpSignalConversionAtVEMS_vid_l[5] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjS2_n;

    /* SignalConversion: '<S422>/TmpSignal ConversionAtVEMS_vidSET8Inport1' */
    pFuM_B.TmpSignalConversionAtVEMS_vid_o[0] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH1_d;
    pFuM_B.TmpSignalConversionAtVEMS_vid_o[1] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH1_d;
    pFuM_B.TmpSignalConversionAtVEMS_vid_o[2] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH1_d;
    pFuM_B.TmpSignalConversionAtVEMS_vid_o[3] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH1_d;
    pFuM_B.TmpSignalConversionAtVEMS_vid_o[4] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH1_d;
    pFuM_B.TmpSignalConversionAtVEMS_vid_o[5] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH1_d;

    /* SignalConversion: '<S422>/TmpSignal ConversionAtVEMS_vidSET9Inport1' */
    pFuM_B.TmpSignalConversionAtVEMS_vid_i[0] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH2_a;
    pFuM_B.TmpSignalConversionAtVEMS_vid_i[1] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH2_a;
    pFuM_B.TmpSignalConversionAtVEMS_vid_i[2] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH2_a;
    pFuM_B.TmpSignalConversionAtVEMS_vid_i[3] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH2_a;
    pFuM_B.TmpSignalConversionAtVEMS_vid_i[4] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH2_a;
    pFuM_B.TmpSignalConversionAtVEMS_vid_i[5] =
      pFuM_B.F00_pFuMSyncEveRst_a.FuSysM_pFuEstimInjH2_a;

    /* S-Function "vems_vidSET" Block: <S422>/VEMS_vidSET10 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6,
                       pFuM_B.TmpSignalConversionAtVEMS_vidSE);

    /* S-Function "vems_vidSET" Block: <S422>/VEMS_vidSET11 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6,
                       pFuM_B.TmpSignalConversionAtVEMS_vid_l);

    /* S-Function "vems_vidSET" Block: <S422>/VEMS_vidSET8 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6,
                       pFuM_B.TmpSignalConversionAtVEMS_vid_o);

    /* S-Function "vems_vidSET" Block: <S422>/VEMS_vidSET9 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6,
                       pFuM_B.TmpSignalConversionAtVEMS_vid_i);
  }

  /* end of Outputs for SubSystem: '<S416>/F00_pFuMSyncEveRst' */
}

/* Start for exported function: FuSysM_SdlFast_pFuM */
void FuSysM_SdlFast_pFuM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S6>/fc_demux4'
   */

  /* Start for S-Function (fcncallgen): '<S13>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S8>/F00_FctSdlFastStall'
   *  Start for SubSystem: '<S9>/F00_SyncOutSdlFastStall'
   */
}

/* Output and update for exported function: FuSysM_SdlFast_pFuM */
void FuSysM_SdlFast_pFuM(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S6>/fc_demux4'
   */

  /* S-Function (fcncallgen): '<S13>/Function-Call Generator' incorporates:
   *  SubSystem: '<S8>/F00_FctSdlFastStall'
   *  SubSystem: '<S9>/F00_SyncOutSdlFastStall'
   */

  /* Outputs for enable SubSystem: '<S21>/F00_FctSdlFastStall' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S21>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S26>/Enable'
   *  RelationalOperator: '<S21>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S26>/VEMS_vidGET */
    VEMS_vidGET(Ext_bRun, pFuM_B.VEMS_vidGET_il);

    /* Outputs for enable SubSystem: '<S26>/F01_FastSdl' incorporates:
     *  EnablePort: '<S27>/Enable'
     *  Logic: '<S26>/Logical Operator'
     */
    if (!pFuM_B.VEMS_vidGET_il) {
      /* S-Function (fcncallgen): '<S27>/Function-Call Generator' */
      pFuM_ASYNC6(1);
    }

    /* end of Outputs for SubSystem: '<S26>/F01_FastSdl' */
  }

  /* end of Outputs for SubSystem: '<S21>/F00_FctSdlFastStall' */

  /* Outputs for enable SubSystem: '<S414>/F00_SyncOutSdlFastStall' incorporates:
   *  Constant: '<S414>/Constant1'
   *  Constant: '<S414>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S419>/Enable'
   *  RelationalOperator: '<S414>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S419>/VEMS_vidGET */
    VEMS_vidGET(Ext_bRun, pFuM_B.VEMS_vidGET_lg);

    /* Outputs for enable SubSystem: '<S419>/F01_FastSdlSyncOut' incorporates:
     *  EnablePort: '<S420>/Enable'
     *  Logic: '<S419>/Logical Operator'
     */
    if (!pFuM_B.VEMS_vidGET_lg) {
      /* S-Function (fcncallgen): '<S420>/Function-Call Generator' incorporates:
       *  SubSystem: '<S9>/F00_pFuMSyncEveRst1'
       */
      pFuM_F00_pFuMSyncEveRst1();
    }

    /* end of Outputs for SubSystem: '<S419>/F01_FastSdlSyncOut' */
  }

  /* end of Outputs for SubSystem: '<S414>/F00_SyncOutSdlFastStall' */
}

/* Output and update for function-call system: '<S7>/F02_pFuSyncIn_EveInj' */
void pFuM_F02_pFuSyncIn_EveInj(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable;
  Float32 localDataTypeConversion9;
  Float32 localDataTypeConversion13;
  Float32 localDataTypeConversion10;
  Float32 localDataTypeConversion16;
  UInt16 localSelector15;
  UInt16 localSelector17;
  UInt16 localSelector18;
  Float32 locallocalAdd1_idx;
  Float32 locallocalAdd1_idx_0;
  Float32 locallocalAdd1_idx_1;
  Float32 locallocalAdd1_idx_2;
  Float32 locallocalAdd26_idx;
  Float32 locallocalAdd26_idx_0;
  Float32 locallocalAdd26_idx_1;
  Float32 locallocalAdd26_idx_2;
  Float32 locallocalAdd32_idx;
  Float32 locallocalAdd7_idx;
  Float32 locallocalAdd7_idx_0;
  Float32 locallocalAdd7_idx_1;

  /* Outputs for enable SubSystem: '<S16>/F02_pFuSyncIn_EveInj' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S19>/Enable'
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* DataTypeConversion: '<S19>/Data Type Conversion9' incorporates:
     *  Constant: '<S19>/FuSysM_agConvInjHRef_C'
     */
    localDataTypeConversion9 = ((Float32)FuSysM_agConvInjHRef_C) * 0.09375F;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, pFuM_B.VEMS_vidGET4_p);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_noInNxtNxtCyl, pFuM_B.VEMS_vidGET2_h);

    /* Selector: '<S19>/Selector16' */
    localSelector15 = pFuM_B.VEMS_vidGET4_p[pFuM_B.VEMS_vidGET2_h - 1];

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, pFuM_B.VEMS_vidGET8_f);

    /* Selector: '<S19>/Selector14' */
    localSelector17 = pFuM_B.VEMS_vidGET8_f[pFuM_B.VEMS_vidGET2_h - 1];

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, pFuM_B.VEMS_vidGET5_m);

    /* Selector: '<S19>/Selector13' */
    localSelector18 = pFuM_B.VEMS_vidGET5_m[pFuM_B.VEMS_vidGET2_h - 1];

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, pFuM_B.VEMS_vidGET9_o);

    /* Sum: '<S19>/Add1' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion14'
     *  Selector: '<S19>/Selector12'
     */
    locallocalAdd1_idx_2 = localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET9_o[pFuM_B.VEMS_vidGET2_h - 1]) * 0.0625F);

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_nEng, pFuM_B.VEMS_vidGET3_m);

    /* DataTypeConversion Block: '<S20>/Data Type Conversion'
     *
     * Regarding '<S20>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Lookup: '<S20>/Look-Up Table'
     * About '<S20>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(FuSysM_agDlyInj_T[0])),
                   pFuM_B.VEMS_vidGET3_m, (&(FuSysM_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S20>/Data Type Duplicate1'
     *
     * Regarding '<S20>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S19>/Data Type Conversion13' incorporates:
     *  Lookup: '<S20>/Look-Up Table'
     */
    localDataTypeConversion13 = ((Float32)localLookUpTable) * 0.09375F;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInCyl, pFuM_B.VEMS_vidGET_p);

    /* Sum: '<S19>/Add26' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion11'
     *  Selector: '<S19>/Selector20'
     *  Selector: '<S19>/Selector21'
     *  Selector: '<S19>/Selector22'
     *  Selector: '<S19>/Selector23'
     */
    locallocalAdd26_idx = localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET4_p[pFuM_B.VEMS_vidGET_p - 1]) * 0.0625F);
    locallocalAdd26_idx_0 = localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET8_f[pFuM_B.VEMS_vidGET_p - 1]) * 0.0625F);
    locallocalAdd26_idx_1 = localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET5_m[pFuM_B.VEMS_vidGET_p - 1]) * 0.0625F);
    locallocalAdd26_idx_2 = localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET9_o[pFuM_B.VEMS_vidGET_p - 1]) * 0.0625F);

    /* DataTypeConversion: '<S19>/Data Type Conversion10' incorporates:
     *  Constant: '<S19>/FuSysM_agPerInjRef_C'
     */
    localDataTypeConversion10 = ((Float32)FuSysM_agPerInjRef_C) * 0.09375F;

    /* Sum: '<S19>/Add3' incorporates:
     *  Sum: '<S19>/Add2'
     */
    locallocalAdd1_idx = ((localDataTypeConversion9 - (((Float32)
      localSelector15) * 0.0625F)) + localDataTypeConversion13) +
      localDataTypeConversion10;
    locallocalAdd1_idx_0 = ((localDataTypeConversion9 - (((Float32)
      localSelector17) * 0.0625F)) + localDataTypeConversion13) +
      localDataTypeConversion10;
    locallocalAdd1_idx_1 = ((localDataTypeConversion9 - (((Float32)
      localSelector18) * 0.0625F)) + localDataTypeConversion13) +
      localDataTypeConversion10;

    /* DataTypeConversion: '<S19>/Data Type Conversion16' incorporates:
     *  Constant: '<S19>/FuSysM_agConvInjSRef_C'
     */
    localDataTypeConversion16 = ((Float32)FuSysM_agConvInjSRef_C) * 0.09375F;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, pFuM_B.VEMS_vidGET6_ga);

    /* Selector: '<S19>/Selector11' */
    localSelector15 = pFuM_B.VEMS_vidGET6_ga[pFuM_B.VEMS_vidGET_p - 1];

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, pFuM_B.VEMS_vidGET10_h);

    /* Selector: '<S19>/Selector10' */
    localSelector18 = pFuM_B.VEMS_vidGET10_h[pFuM_B.VEMS_vidGET_p - 1];

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, pFuM_B.VEMS_vidGET7_ab);

    /* Selector: '<S19>/Selector9' */
    localSelector17 = pFuM_B.VEMS_vidGET7_ab[pFuM_B.VEMS_vidGET_p - 1];

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6, pFuM_B.VEMS_vidGET11_g);

    /* Sum: '<S19>/Add32' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion15'
     *  Selector: '<S19>/Selector8'
     *  Sum: '<S19>/Add30'
     */
    locallocalAdd32_idx = (localDataTypeConversion16 - (((Float32)
      pFuM_B.VEMS_vidGET11_g[pFuM_B.VEMS_vidGET_p - 1]) * 0.09375F)) +
      localDataTypeConversion13;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, pFuM_B.VEMS_vidGET1_op);

    /* Sum: '<S19>/Add7' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion12'
     *  Selector: '<S19>/Selector15'
     *  Selector: '<S19>/Selector17'
     *  Selector: '<S19>/Selector18'
     *  Selector: '<S19>/Selector19'
     *  Sum: '<S19>/Add4'
     */
    locallocalAdd7_idx = (localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET4_p[pFuM_B.VEMS_vidGET1_op - 1]) * 0.0625F)) +
      localDataTypeConversion13;
    locallocalAdd7_idx_0 = (localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET8_f[pFuM_B.VEMS_vidGET1_op - 1]) * 0.0625F)) +
      localDataTypeConversion13;
    locallocalAdd7_idx_1 = (localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET5_m[pFuM_B.VEMS_vidGET1_op - 1]) * 0.0625F)) +
      localDataTypeConversion13;
    localDataTypeConversion9 = (localDataTypeConversion9 - (((Float32)
      pFuM_B.VEMS_vidGET9_o[pFuM_B.VEMS_vidGET1_op - 1]) * 0.0625F)) +
      localDataTypeConversion13;

    /* Sum: '<S19>/Add8' incorporates:
     *  Sum: '<S19>/Add31'
     */
    locallocalAdd26_idx = (localDataTypeConversion13 + locallocalAdd26_idx) -
      localDataTypeConversion10;
    locallocalAdd26_idx_0 = (localDataTypeConversion13 + locallocalAdd26_idx_0)
      - localDataTypeConversion10;
    locallocalAdd26_idx_1 = (localDataTypeConversion13 + locallocalAdd26_idx_1)
      - localDataTypeConversion10;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, pFuM_B.VEMS_vidGET13_b);

    /* DataTypeConversion: '<S19>/Data Type Conversion1' incorporates:
     *  Selector: '<S19>/Selector2'
     */
    FuSysM_mFuReqInjH2 = ((Float32)
                          pFuM_B.VEMS_vidGET13_b[pFuM_B.VEMS_vidGET1_op - 1]) *
      7.450580597E-009F;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET14 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, pFuM_B.VEMS_vidGET14_g);

    /* DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
     *  Selector: '<S19>/Selector1'
     */
    FuSysM_mFuReqInjS1 = ((Float32)pFuM_B.VEMS_vidGET14_g[pFuM_B.VEMS_vidGET_p
                          - 1]) * 7.450580597E-009F;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET15 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, pFuM_B.VEMS_vidGET15_d);

    /* DataTypeConversion: '<S19>/Data Type Conversion3' incorporates:
     *  Selector: '<S19>/Selector'
     */
    FuSysM_mFuReqInjS2 = ((Float32)pFuM_B.VEMS_vidGET15_d[pFuM_B.VEMS_vidGET_p
                          - 1]) * 7.450580597E-009F;

    /* DataTypeConversion: '<S19>/Data Type Conversion4' incorporates:
     *  Selector: '<S19>/Selector3'
     */
    FuSysM_mFuReqInjH2Prev = ((Float32)
      pFuM_B.VEMS_vidGET13_b[pFuM_B.VEMS_vidGET_p - 1]) * 7.450580597E-009F;

    /* DataTypeConversion: '<S19>/Data Type Conversion5' incorporates:
     *  Selector: '<S19>/Selector4'
     */
    FuSysM_mFuReqInjH2Nxt = ((Float32)
      pFuM_B.VEMS_vidGET13_b[pFuM_B.VEMS_vidGET2_h - 1]) * 7.450580597E-009F;

    /* S-Function "vems_vidGET" Block: <S19>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, pFuM_B.VEMS_vidGET12_e);

    /* DataTypeConversion: '<S19>/Data Type Conversion6' incorporates:
     *  Selector: '<S19>/Selector5'
     */
    FuSysM_mFuReqInjH1 = ((Float32)
                          pFuM_B.VEMS_vidGET12_e[pFuM_B.VEMS_vidGET1_op - 1]) *
      7.450580597E-009F;

    /* DataTypeConversion: '<S19>/Data Type Conversion7' incorporates:
     *  Selector: '<S19>/Selector6'
     */
    FuSysM_mFuReqInjH1Prev = ((Float32)
      pFuM_B.VEMS_vidGET12_e[pFuM_B.VEMS_vidGET_p - 1]) * 7.450580597E-009F;

    /* DataTypeConversion: '<S19>/Data Type Conversion8' incorporates:
     *  Selector: '<S19>/Selector7'
     */
    FuSysM_mFuReqInjH1Nxt = ((Float32)
      pFuM_B.VEMS_vidGET12_e[pFuM_B.VEMS_vidGET2_h - 1]) * 7.450580597E-009F;

    /* SignalConversion: '<S19>/Signal Conversion' */
    FuSysM_agBegInjH1RefPrev = locallocalAdd26_idx;

    /* SignalConversion: '<S19>/Signal Conversion1' */
    FuSysM_agEndInjH1RefPrev = locallocalAdd26_idx_0;

    /* SignalConversion: '<S19>/Signal Conversion10' */
    FuSysM_agBegInjH2RefNxt = locallocalAdd1_idx_1;

    /* SignalConversion: '<S19>/Signal Conversion11' */
    FuSysM_agEndInjH2RefNxt = (localDataTypeConversion13 + locallocalAdd1_idx_2)
      + localDataTypeConversion10;

    /* SignalConversion: '<S19>/Signal Conversion12' */
    FuSysM_agBegInjS1Ref = (localDataTypeConversion16 - (((Float32)
      localSelector15) * 0.09375F)) + localDataTypeConversion13;

    /* SignalConversion: '<S19>/Signal Conversion13' */
    FuSysM_agEndInjS1Ref = (localDataTypeConversion16 - (((Float32)
      localSelector18) * 0.09375F)) + localDataTypeConversion13;

    /* SignalConversion: '<S19>/Signal Conversion14' */
    FuSysM_agBegInjS2Ref = (localDataTypeConversion16 - (((Float32)
      localSelector17) * 0.09375F)) + localDataTypeConversion13;

    /* SignalConversion: '<S19>/Signal Conversion15' */
    FuSysM_agEndInjS2Ref = locallocalAdd32_idx;

    /* SignalConversion: '<S19>/Signal Conversion2' */
    FuSysM_agBegInjH2RefPrev = locallocalAdd26_idx_1;

    /* SignalConversion: '<S19>/Signal Conversion3' */
    FuSysM_agEndInjH2RefPrev = (localDataTypeConversion13 +
      locallocalAdd26_idx_2) - localDataTypeConversion10;

    /* SignalConversion: '<S19>/Signal Conversion4' */
    FuSysM_agBegInjH1Ref = locallocalAdd7_idx;

    /* SignalConversion: '<S19>/Signal Conversion5' */
    FuSysM_agEndInjH1Ref = locallocalAdd7_idx_0;

    /* SignalConversion: '<S19>/Signal Conversion6' */
    FuSysM_agBegInjH2Ref = locallocalAdd7_idx_1;

    /* SignalConversion: '<S19>/Signal Conversion7' */
    FuSysM_agEndInjH2Ref = localDataTypeConversion9;

    /* SignalConversion: '<S19>/Signal Conversion8' */
    FuSysM_agBegInjH1RefNxt = locallocalAdd1_idx;

    /* SignalConversion: '<S19>/Signal Conversion9' */
    FuSysM_agEndInjH1RefNxt = locallocalAdd1_idx_0;
  }

  /* end of Outputs for SubSystem: '<S16>/F02_pFuSyncIn_EveInj' */
}

/* Output and update for action system: '<S33>/F02_PFuMdlClcn' */
void pFuM_F02_PFuMdlClcn(void)
{
  /* local block i/o variables */
  UInt16 localOutDTConv_f[2];
  UInt16 localLookUpTable_f[2];
  UInt16 localOutDTConv_n[2];
  UInt16 localLookUpTable_o[2];
  UInt16 localOutDTConv_l[6];
  UInt16 localLookUpTable_k[6];
  UInt16 localOutDTConv_fz[4];
  UInt16 localLookUpTable_kr[4];
  UInt16 localOutDTConv_g[2];
  UInt16 localLookUpTable_l[2];
  UInt16 localOutDTConv_i[2];
  UInt16 localLookUpTable_g[2];
  UInt16 localOutDTConv_p[4];
  UInt16 localLookUpTable_m[4];
  UInt16 localOutDTConv_is[4];
  UInt16 localLookUpTable_a[4];
  UInt16 localOutDTConv_it[2];
  UInt16 localLookUpTable_b[2];
  UInt16 localOutDTConv_b[2];
  UInt16 localLookUpTable_n[2];
  UInt16 localOutDTConv_fu[4];
  UInt16 localLookUpTable_j[4];
  UInt16 localOutDTConv_j[2];
  UInt16 localLookUpTable_e[2];
  UInt16 localOutDTConv_fp[2];
  UInt16 localLookUpTable_eo[2];
  UInt16 localOutDTConv_a[6];
  UInt16 localLookUpTable_oy[6];
  UInt16 localOutDTConv_h[6];
  UInt16 localLookUpTable_eoo[6];
  UInt16 localOutDTConv_lx[6];
  UInt16 localLookUpTable_as[6];
  UInt16 localLookUpTable2D[4];
  UInt16 localOutDTConv_e[4];
  UInt16 localLookUpTable2D_n[4];
  UInt16 localOutDTConv_d[4];
  UInt16 localLookUpTable2D_a[4];
  UInt16 localOutDTConv_lv[4];
  UInt16 localLookUpTable2D_j[4];
  UInt16 localOutDTConv_fn[4];
  Float32 localDataTypeConversion1;
  Float32 localDataTypeConversion2;
  Float32 localDataTypeConversion3;
  Float32 localDataTypeConversion4;
  Float32 localDataTypeConversion5;
  Float32 localDataTypeConversion7;
  Float32 localDataTypeConversion8;
  Float32 localDataTypeConversion9_g;
  Float32 localDataTypeConversion1_i;
  Float32 localAdd1_nw;
  Float32 localDivide_hb;
  Float32 localDivide_o3;
  Float32 localmin;
  Float32 localmin_0;
  Float32 localAdd19_e;
  Float32 localAdd1_o1;
  Float32 localAdd14_i;
  Float32 localAdd12_e;
  Float32 localAdd12;
  Float32 localAdd30_mn;
  Float32 locallocalDataTypeConversion4_l;
  Float32 locallocalDataTypeConversion4_0;
  Float32 locallocalDataTypeConversion4_1;
  Float32 locallocalDataTypeConversion4_2;
  Float32 locallocalDataTypeConversion5_i;
  Float32 locallocalDataTypeConversion5_0;
  Float32 locallocalDataTypeConversion5_1;
  Float32 locallocalDataTypeConversion5_2;
  Float32 localtmp;
  UInt16 locallocalOutDTConv_idx;

  /* DataTypeConversion: '<S36>/Data Type Conversion1' */
  FuSysM_pFuEstimInjH1Prev = ((Float32)pFuM_B.VEMS_vidGET9_g) * 781.25F;

  /* DataTypeConversion: '<S36>/Data Type Conversion2' */
  FuSysM_pFuEstimInjS1Prev = ((Float32)pFuM_B.VEMS_vidGET10) * 781.25F;

  /* DataTypeConversion: '<S36>/Data Type Conversion3' */
  FuSysM_pFuEstimInjH2Prev = ((Float32)pFuM_B.VEMS_vidGET11) * 781.25F;

  /* DataTypeConversion: '<S36>/Data Type Conversion4' */
  FuSysM_pFuEstimInjS2Prev = ((Float32)pFuM_B.VEMS_vidGET12) * 781.25F;

  /* If: '<S36>/If' incorporates:
   *  ActionPort: '<S46>/Action Port'
   *  ActionPort: '<S47>/Action Port'
   *  Constant: '<S36>/FuSysM_bAcvPFuMdl_C'
   *  SubSystem: '<S36>/F01_PfuMdl'
   *  SubSystem: '<S36>/F02_PfuMes'
   */
  if (FuSysM_bAcvPFuMdl_C) {
    /* DataTypeConversion: '<S46>/Data Type Conversion1' */
    localDataTypeConversion1 = ((Float32)pFuM_B.VEMS_vidGET4_o) * 0.09375F;

    /* DataTypeConversion: '<S46>/Data Type Conversion2' */
    localDataTypeConversion2 = ((Float32)pFuM_B.VEMS_vidGET3_o) * 0.09375F;

    /* DataTypeConversion: '<S46>/Data Type Conversion3' */
    localDataTypeConversion3 = ((Float32)pFuM_B.VEMS_vidGET5_d) * 0.09375F;

    /* DataTypeConversion: '<S46>/Data Type Conversion4' */
    localDataTypeConversion4 = ((Float32)pFuM_B.VEMS_vidGET6) *
      7.450580597E-009F;

    /* DataTypeConversion: '<S46>/Data Type Conversion5' */
    localDataTypeConversion5 = ((Float32)pFuM_B.VEMS_vidGET7) *
      7.450580597E-009F;

    /* DataTypeConversion: '<S46>/Data Type Conversion7' */
    localDataTypeConversion7 = ((Float32)pFuM_B.LookUpTable2D) *
      1.220703125E+006F;

    /* DataTypeConversion: '<S46>/Data Type Conversion8' */
    localDataTypeConversion8 = ((Float32)pFuM_B.VEMS_vidGET1) * 781.25F;

    /* DataTypeConversion: '<S46>/Data Type Conversion9' */
    localDataTypeConversion9_g = ((Float32)pFuM_B.VEMS_vidGET2_ak) * 0.09375F;

    /* If: '<S46>/If' incorporates:
     *  ActionPort: '<S48>/Action Port'
     *  ActionPort: '<S49>/Action Port'
     *  Constant: '<S46>/Constant16'
     *  RelationalOperator: '<S46>/Relational Operator1'
     *  SubSystem: '<S46>/F01_PfuInjH1Clcn'
     *  SubSystem: '<S46>/F02_PfuInjH1NotClcn'
     */
    if (FuSysM_mFuReqInjH1 > 0.0F) {
      /* MinMax: '<S48>/MinMax3' */
      localAdd1_nw = rt_MINf(FuSysM_agEndInjH1Ref, localDataTypeConversion2);

      /* Sum: '<S48>/Add1' incorporates:
       *  MinMax: '<S48>/MinMax2'
       */
      localAdd1_o1 = rt_MAXf(localAdd1_nw, FuSysM_agBegInjH1Ref) -
        FuSysM_agBegInjH1Ref;

      /* Product: '<S85>/Divide' incorporates:
       *  Constant: '<S48>/Constant22'
       *  Constant: '<S48>/Constant34'
       *  MinMax: '<S48>/MinMax38'
       *  MinMax: '<S48>/MinMax40'
       *  Sum: '<S48>/Add55'
       *  Sum: '<S48>/Add8'
       */
      localDivide_hb = (rt_MINf(0.0F, localDataTypeConversion1) - rt_MINf
                        (localDataTypeConversion9_g, 0.0F)) /
        (localDataTypeConversion1 - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S85>/If Action Subsystem3' */

      /* Switch: '<S134>/Switch1' incorporates:
       *  Constant: '<S134>/Constant1'
       *  Constant: '<S134>/Constant2'
       *  Constant: '<S134>/Constant3'
       *  Logic: '<S134>/Logical Operator1'
       *  RelationalOperator: '<S134>/Relational Operator'
       *  RelationalOperator: '<S134>/Relational Operator1'
       *  RelationalOperator: '<S134>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S85>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax23' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion9_g, FuSysM_agBegInjH1Ref);

      /* Product: '<S84>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax46'
       *  Sum: '<S48>/Add10'
       *  Sum: '<S48>/Add24'
       */
      localDataTypeConversion1_i = (rt_MINf(localAdd1_nw,
        localDataTypeConversion1) - localDataTypeConversion9_g) /
        (localDataTypeConversion1 - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S84>/If Action Subsystem3' */

      /* Switch: '<S132>/Switch1' incorporates:
       *  Constant: '<S132>/Constant1'
       *  Constant: '<S132>/Constant2'
       *  Constant: '<S132>/Constant3'
       *  Logic: '<S132>/Logical Operator1'
       *  RelationalOperator: '<S132>/Relational Operator'
       *  RelationalOperator: '<S132>/Relational Operator1'
       *  RelationalOperator: '<S132>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S84>/If Action Subsystem3' */

      /* Product: '<S83>/Divide' incorporates:
       *  Constant: '<S48>/Constant15'
       *  Constant: '<S48>/Constant38'
       *  MinMax: '<S48>/MinMax29'
       *  MinMax: '<S48>/MinMax37'
       *  Sum: '<S48>/Add21'
       *  Sum: '<S48>/Add56'
       */
      localDivide_o3 = (rt_MINf(0.0F, localDataTypeConversion3) - rt_MINf
                        (localDataTypeConversion2, 0.0F)) /
        (localDataTypeConversion3 - localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S83>/If Action Subsystem3' */

      /* Switch: '<S130>/Switch1' incorporates:
       *  Constant: '<S130>/Constant1'
       *  Constant: '<S130>/Constant2'
       *  Constant: '<S130>/Constant3'
       *  Logic: '<S130>/Logical Operator1'
       *  RelationalOperator: '<S130>/Relational Operator'
       *  RelationalOperator: '<S130>/Relational Operator1'
       *  RelationalOperator: '<S130>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S83>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax24' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion2, FuSysM_agBegInjH1Ref);

      /* Product: '<S82>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax39'
       *  Sum: '<S48>/Add25'
       *  Sum: '<S48>/Add54'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, localDataTypeConversion3) -
                      localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S82>/If Action Subsystem3' */

      /* Switch: '<S128>/Switch1' incorporates:
       *  Constant: '<S128>/Constant1'
       *  Constant: '<S128>/Constant2'
       *  Constant: '<S128>/Constant3'
       *  Logic: '<S128>/Logical Operator1'
       *  RelationalOperator: '<S128>/Relational Operator'
       *  RelationalOperator: '<S128>/Relational Operator1'
       *  RelationalOperator: '<S128>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S82>/If Action Subsystem3' */

      /* DataTypeConversion: '<S63>/OutDTConv' incorporates:
       *  Constant: '<S63>/offset'
       *  Constant: '<S63>/offset1'
       *  Constant: '<S63>/one_on_slope'
       *  Product: '<S63>/Product4'
       *  Sum: '<S63>/Add1'
       *  Sum: '<S63>/Add2'
       */
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_j[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_j[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_j[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_j[3] = locallocalOutDTConv_idx;

      /* Lookup2D: '<S60>/Look-Up Table (2-D)'
       * About '<S60>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localOutDTConv_fn[0]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_j[0], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_fn[1]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_j[1], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_fn[2]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_j[2], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_fn[3]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_j[3], (&(FuSysM_rAgPmp_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S60>/Data Type Duplicate2'
       *
       * Regarding '<S60>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S48>/Data Type Conversion5' */
      locallocalDataTypeConversion5_0 = ((Float32)localOutDTConv_fn[0]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_i = ((Float32)localOutDTConv_fn[1]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_2 = ((Float32)localOutDTConv_fn[2]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_1 = ((Float32)localOutDTConv_fn[3]) *
        3.051757813E-005F;

      /* MinMax: '<S48>/MinMax17' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1Ref, FuSysM_agEndInjS1Ref);

      /* MinMax: '<S48>/MinMax31' */
      localmin = rt_MINf(localAdd1_nw, FuSysM_agEndInjH1Ref);

      /* MinMax: '<S48>/MinMax18' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS1Ref, FuSysM_agBegInjH1Ref);

      /* MinMax: '<S48>/MinMax5' */
      localmin_0 = rt_MINf(FuSysM_agEndInjH1Ref, localAdd1_nw);

      /* Sum: '<S48>/Add14' */
      localAdd14_i = FuSysM_agEndInjS1Ref - FuSysM_agBegInjS1Ref;

      /* Sum: '<S48>/Add19' */
      localAdd19_e = FuSysM_agEndInjH1Ref - FuSysM_agBegInjH1Ref;

      /* MinMax: '<S48>/MinMax78' */
      localAdd1_nw = rt_MINf(localDataTypeConversion1, FuSysM_agEndInjH1Ref);

      /* Product: '<S69>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax82'
       *  Sum: '<S48>/Add6'
       *  Sum: '<S48>/Add65'
       */
      localDivide_hb = (rt_MAXf(localDataTypeConversion9_g, localAdd1_nw) -
                        localDataTypeConversion9_g) / (localDataTypeConversion1
        - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S69>/If Action Subsystem3' */

      /* Switch: '<S102>/Switch1' incorporates:
       *  Constant: '<S102>/Constant1'
       *  Constant: '<S102>/Constant2'
       *  Constant: '<S102>/Constant3'
       *  Logic: '<S102>/Logical Operator1'
       *  RelationalOperator: '<S102>/Relational Operator'
       *  RelationalOperator: '<S102>/Relational Operator1'
       *  RelationalOperator: '<S102>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S69>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax73' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion9_g, FuSysM_agBegInjH1Ref);

      /* Product: '<S70>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax80'
       *  Sum: '<S48>/Add12'
       *  Sum: '<S48>/Add60'
       */
      localDivide_o3 = (rt_MINf(localDataTypeConversion1, localAdd1_nw) -
                        localDataTypeConversion9_g) / (localDataTypeConversion1
        - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S70>/If Action Subsystem3' */

      /* Switch: '<S104>/Switch1' incorporates:
       *  Constant: '<S104>/Constant1'
       *  Constant: '<S104>/Constant2'
       *  Constant: '<S104>/Constant3'
       *  Logic: '<S104>/Logical Operator1'
       *  RelationalOperator: '<S104>/Relational Operator'
       *  RelationalOperator: '<S104>/Relational Operator1'
       *  RelationalOperator: '<S104>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S70>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax75' */
      localAdd1_nw = rt_MINf(localDataTypeConversion3, FuSysM_agEndInjH1Ref);

      /* Product: '<S81>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax76'
       *  Sum: '<S48>/Add59'
       *  Sum: '<S48>/Add63'
       */
      localDataTypeConversion1_i = (rt_MAXf(localDataTypeConversion2,
        localAdd1_nw) - localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S81>/If Action Subsystem3' */

      /* Switch: '<S126>/Switch1' incorporates:
       *  Constant: '<S126>/Constant1'
       *  Constant: '<S126>/Constant2'
       *  Constant: '<S126>/Constant3'
       *  Logic: '<S126>/Logical Operator1'
       *  RelationalOperator: '<S126>/Relational Operator'
       *  RelationalOperator: '<S126>/Relational Operator1'
       *  RelationalOperator: '<S126>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S81>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax77' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion2, FuSysM_agBegInjH1Ref);

      /* Product: '<S86>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax79'
       *  Sum: '<S48>/Add61'
       *  Sum: '<S48>/Add62'
       */
      localAdd1_nw = (rt_MINf(localDataTypeConversion3, localAdd1_nw) -
                      localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S86>/If Action Subsystem3' */

      /* Switch: '<S136>/Switch1' incorporates:
       *  Constant: '<S136>/Constant1'
       *  Constant: '<S136>/Constant2'
       *  Constant: '<S136>/Constant3'
       *  Logic: '<S136>/Logical Operator1'
       *  RelationalOperator: '<S136>/Relational Operator'
       *  RelationalOperator: '<S136>/Relational Operator1'
       *  RelationalOperator: '<S136>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S86>/If Action Subsystem3' */

      /* DataTypeConversion: '<S65>/OutDTConv' incorporates:
       *  Constant: '<S65>/offset'
       *  Constant: '<S65>/offset1'
       *  Constant: '<S65>/one_on_slope'
       *  Product: '<S65>/Product4'
       *  Sum: '<S65>/Add1'
       *  Sum: '<S65>/Add2'
       */
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fn[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fn[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fn[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fn[3] = locallocalOutDTConv_idx;

      /* Lookup2D: '<S61>/Look-Up Table (2-D)'
       * About '<S61>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_j[0]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_fn[0], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_j[1]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_fn[1], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_j[2]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_fn[2], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_j[3]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_fn[3], (&(FuSysM_rAgPmp_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S61>/Data Type Duplicate2'
       *
       * Regarding '<S61>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S48>/Data Type Conversion4' */
      locallocalDataTypeConversion4_l = ((Float32)localLookUpTable2D_j[0]) *
        3.051757813E-005F;
      locallocalDataTypeConversion4_0 = ((Float32)localLookUpTable2D_j[1]) *
        3.051757813E-005F;
      locallocalDataTypeConversion4_1 = ((Float32)localLookUpTable2D_j[2]) *
        3.051757813E-005F;
      locallocalDataTypeConversion4_2 = ((Float32)localLookUpTable2D_j[3]) *
        3.051757813E-005F;

      /* MinMax: '<S48>/MinMax26' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion1, FuSysM_agBegInjH1Ref);

      /* Product: '<S87>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax16'
       *  Sum: '<S48>/Add26'
       *  Sum: '<S48>/Add27'
       */
      localDataTypeConversion1_i = (FuSysM_agEndInjH1Ref - rt_MINf
        (FuSysM_agEndInjH1Ref, localAdd1_nw)) / (FuSysM_agEndInjH1Ref -
        FuSysM_agBegInjH1Ref);

      /* Outputs for atomic SubSystem: '<S87>/If Action Subsystem3' */

      /* Switch: '<S138>/Switch1' incorporates:
       *  Constant: '<S138>/Constant1'
       *  Constant: '<S138>/Constant2'
       *  Constant: '<S138>/Constant3'
       *  Logic: '<S138>/Logical Operator1'
       *  RelationalOperator: '<S138>/Relational Operator'
       *  RelationalOperator: '<S138>/Relational Operator1'
       *  RelationalOperator: '<S138>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S87>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax13' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion3, FuSysM_agBegInjH1Ref);

      /* Product: '<S88>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax11'
       *  Sum: '<S48>/Add20'
       */
      localAdd1_nw = (FuSysM_agEndInjH1Ref - rt_MINf(FuSysM_agEndInjH1Ref,
        localAdd1_nw)) / localAdd19_e;

      /* Outputs for atomic SubSystem: '<S88>/If Action Subsystem3' */

      /* Switch: '<S140>/Switch1' incorporates:
       *  Constant: '<S140>/Constant1'
       *  Constant: '<S140>/Constant2'
       *  Constant: '<S140>/Constant3'
       *  Logic: '<S140>/Logical Operator1'
       *  RelationalOperator: '<S140>/Relational Operator'
       *  RelationalOperator: '<S140>/Relational Operator1'
       *  RelationalOperator: '<S140>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S88>/If Action Subsystem3' */

      /* DataTypeConversion: '<S66>/OutDTConv' incorporates:
       *  Constant: '<S66>/offset'
       *  Constant: '<S66>/offset1'
       *  Constant: '<S66>/one_on_slope'
       *  Product: '<S66>/Product4'
       *  Sum: '<S66>/Add1'
       *  Sum: '<S66>/Add2'
       */
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_j[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_j[1] = locallocalOutDTConv_idx;

      /* Lookup: '<S59>/Look-Up Table'
       * About '<S59>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_e[0]), (&(FuSysM_facCorMassEndPmpStk_T
        [0])), localOutDTConv_j[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_e[1]), (&(FuSysM_facCorMassEndPmpStk_T
        [0])), localOutDTConv_j[1], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate1'
       *
       * Regarding '<S59>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S48>/Data Type Conversion1' incorporates:
       *  Lookup: '<S59>/Look-Up Table'
       */
      FuSysM_prm_fac1CorMassPmpInjH1[0] = ((Float32)localLookUpTable_e[0]) *
        3.051757813E-005F;
      FuSysM_prm_fac1CorMassPmpInjH1[1] = ((Float32)localLookUpTable_e[1]) *
        3.051757813E-005F;

      /* MinMax: '<S48>/MinMax7' */
      localAdd1_nw = rt_MINf(FuSysM_agEndInjH1Ref, localDataTypeConversion9_g);

      /* Product: '<S89>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax28'
       *  Sum: '<S48>/Add31'
       *  Sum: '<S48>/Add32'
       */
      localDataTypeConversion1_i = (rt_MAXf(localAdd1_nw, FuSysM_agBegInjH1Ref)
        - FuSysM_agBegInjH1Ref) / (FuSysM_agEndInjH1Ref - FuSysM_agBegInjH1Ref);

      /* Outputs for atomic SubSystem: '<S89>/If Action Subsystem3' */

      /* Switch: '<S142>/Switch1' incorporates:
       *  Constant: '<S142>/Constant1'
       *  Constant: '<S142>/Constant2'
       *  Constant: '<S142>/Constant3'
       *  Logic: '<S142>/Logical Operator1'
       *  RelationalOperator: '<S142>/Relational Operator'
       *  RelationalOperator: '<S142>/Relational Operator1'
       *  RelationalOperator: '<S142>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S89>/If Action Subsystem3' */

      /* Product: '<S90>/Divide' incorporates:
       *  Sum: '<S48>/Add23'
       */
      localAdd1_nw = localAdd1_o1 / (FuSysM_agEndInjH1Ref - FuSysM_agBegInjH1Ref);

      /* Outputs for atomic SubSystem: '<S90>/If Action Subsystem3' */

      /* Switch: '<S144>/Switch1' incorporates:
       *  Constant: '<S144>/Constant1'
       *  Constant: '<S144>/Constant2'
       *  Constant: '<S144>/Constant3'
       *  Logic: '<S144>/Logical Operator1'
       *  RelationalOperator: '<S144>/Relational Operator'
       *  RelationalOperator: '<S144>/Relational Operator1'
       *  RelationalOperator: '<S144>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S90>/If Action Subsystem3' */

      /* DataTypeConversion: '<S67>/OutDTConv' incorporates:
       *  Constant: '<S67>/offset'
       *  Constant: '<S67>/offset1'
       *  Constant: '<S67>/one_on_slope'
       *  Product: '<S67>/Product4'
       *  Sum: '<S67>/Add1'
       *  Sum: '<S67>/Add2'
       */
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fp[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fp[1] = locallocalOutDTConv_idx;

      /* Lookup: '<S58>/Look-Up Table'
       * About '<S58>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_eo[0]),
                     (&(FuSysM_facCorMassBegPmpStk_T[0])), localOutDTConv_fp[0],
                     (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_eo[1]),
                     (&(FuSysM_facCorMassBegPmpStk_T[0])), localOutDTConv_fp[1],
                     (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate1'
       *
       * Regarding '<S58>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S48>/Data Type Conversion2' incorporates:
       *  Lookup: '<S58>/Look-Up Table'
       */
      FuSysM_prm_fac2CorMassPmpInjH1[0] = ((Float32)localLookUpTable_eo[0]) *
        3.051757813E-005F;
      FuSysM_prm_fac2CorMassPmpInjH1[1] = ((Float32)localLookUpTable_eo[1]) *
        3.051757813E-005F;

      /* Product: '<S97>/Divide' incorporates:
       *  Constant: '<S48>/Constant7'
       *  Product: '<S96>/Divide'
       *  Sum: '<S48>/Add22'
       *  Sum: '<S48>/Add58'
       *  Sum: '<S48>/Add64'
       */
      FuSysM_prm_mFuPmpOvlpH1[0] = ((locallocalDataTypeConversion4_l -
        locallocalDataTypeConversion4_0) * localDataTypeConversion4) * ((1.0F +
        FuSysM_prm_fac1CorMassPmpInjH1[0]) - FuSysM_prm_fac2CorMassPmpInjH1[0]);
      FuSysM_prm_mFuPmpOvlpH1[1] = ((locallocalDataTypeConversion4_1 -
        locallocalDataTypeConversion4_2) * localDataTypeConversion5) * ((1.0F +
        FuSysM_prm_fac1CorMassPmpInjH1[1]) - FuSysM_prm_fac2CorMassPmpInjH1[1]);

      /* Sum: '<S48>/Add30' */
      localAdd30_mn = FuSysM_prm_mFuPmpOvlpH1[0] + FuSysM_prm_mFuPmpOvlpH1[1];

      /* MinMax: '<S48>/MinMax50' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1Ref, FuSysM_agEndInjH1RefPrev);

      /* MinMax: '<S48>/MinMax51' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefPrev,
        FuSysM_agBegInjH1Ref);

      /* Product: '<S91>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax52'
       *  MinMax: '<S48>/MinMax54'
       *  Sum: '<S48>/Add39'
       *  Sum: '<S48>/Add40'
       */
      locallocalDataTypeConversion4_0 = (rt_MINf(localAdd1_nw,
        FuSysM_agEndInjH1Ref) - rt_MINf(FuSysM_agEndInjH1Ref,
        localDataTypeConversion1_i)) / (FuSysM_agEndInjH1RefPrev -
        FuSysM_agBegInjH1RefPrev);

      /* Outputs for atomic SubSystem: '<S91>/If Action Subsystem3' */

      /* Switch: '<S146>/Switch1' incorporates:
       *  Constant: '<S146>/Constant1'
       *  Constant: '<S146>/Constant2'
       *  Constant: '<S146>/Constant3'
       *  Logic: '<S146>/Logical Operator1'
       *  RelationalOperator: '<S146>/Relational Operator'
       *  RelationalOperator: '<S146>/Relational Operator1'
       *  RelationalOperator: '<S146>/Relational Operator3'
       */
      if (((locallocalDataTypeConversion4_0 != locallocalDataTypeConversion4_0) ||
           (locallocalDataTypeConversion4_0 > 3.000000005E+038F)) ||
          (-3.000000005E+038F > locallocalDataTypeConversion4_0)) {
        locallocalDataTypeConversion4_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S91>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax53' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1Ref, FuSysM_agEndInjH2RefPrev);

      /* MinMax: '<S48>/MinMax55' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefPrev,
        FuSysM_agBegInjH1Ref);

      /* Product: '<S92>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax49'
       *  MinMax: '<S48>/MinMax56'
       *  Sum: '<S48>/Add41'
       *  Sum: '<S48>/Add42'
       */
      localAdd1_o1 = (rt_MINf(localAdd1_nw, FuSysM_agEndInjH1Ref) - rt_MINf
                      (FuSysM_agEndInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefPrev - FuSysM_agBegInjH2RefPrev);

      /* Outputs for atomic SubSystem: '<S92>/If Action Subsystem3' */

      /* Switch: '<S148>/Switch1' incorporates:
       *  Constant: '<S148>/Constant1'
       *  Constant: '<S148>/Constant2'
       *  Constant: '<S148>/Constant3'
       *  Logic: '<S148>/Logical Operator1'
       *  RelationalOperator: '<S148>/Relational Operator'
       *  RelationalOperator: '<S148>/Relational Operator1'
       *  RelationalOperator: '<S148>/Relational Operator3'
       */
      if (((localAdd1_o1 != localAdd1_o1) || (localAdd1_o1 > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_o1)) {
        localAdd1_o1 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S92>/If Action Subsystem3' */

      /* Product: '<S71>/Divide' incorporates:
       *  Sum: '<S48>/Add13'
       */
      localAdd19_e = (localmin - localmin_0) / localAdd14_i;

      /* Outputs for atomic SubSystem: '<S71>/If Action Subsystem3' */

      /* Switch: '<S106>/Switch1' incorporates:
       *  Constant: '<S106>/Constant1'
       *  Constant: '<S106>/Constant2'
       *  Constant: '<S106>/Constant3'
       *  Logic: '<S106>/Logical Operator1'
       *  RelationalOperator: '<S106>/Relational Operator'
       *  RelationalOperator: '<S106>/Relational Operator1'
       *  RelationalOperator: '<S106>/Relational Operator3'
       */
      if (((localAdd19_e != localAdd19_e) || (localAdd19_e > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd19_e)) {
        localAdd19_e = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S71>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax4' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1Ref, FuSysM_agEndInjS2Ref);

      /* MinMax: '<S48>/MinMax6' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjS2Ref,
        FuSysM_agBegInjH1Ref);

      /* Product: '<S72>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax15'
       *  MinMax: '<S48>/MinMax8'
       *  Sum: '<S48>/Add3'
       *  Sum: '<S48>/Add5'
       */
      localDivide_hb = (rt_MINf(localAdd1_nw, FuSysM_agEndInjH1Ref) - rt_MINf
                        (FuSysM_agEndInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjS2Ref - FuSysM_agBegInjS2Ref);

      /* Outputs for atomic SubSystem: '<S72>/If Action Subsystem3' */

      /* Switch: '<S108>/Switch1' incorporates:
       *  Constant: '<S108>/Constant1'
       *  Constant: '<S108>/Constant2'
       *  Constant: '<S108>/Constant3'
       *  Logic: '<S108>/Logical Operator1'
       *  RelationalOperator: '<S108>/Relational Operator'
       *  RelationalOperator: '<S108>/Relational Operator1'
       *  RelationalOperator: '<S108>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S72>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax66' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1Ref, FuSysM_agEndInjH1RefNxt);

      /* MinMax: '<S48>/MinMax67' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefNxt,
        FuSysM_agBegInjH1Ref);

      /* Product: '<S73>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax68'
       *  MinMax: '<S48>/MinMax70'
       *  Sum: '<S48>/Add50'
       *  Sum: '<S48>/Add51'
       */
      localDivide_o3 = (rt_MINf(localAdd1_nw, FuSysM_agEndInjH1Ref) - rt_MINf
                        (FuSysM_agEndInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH1RefNxt - FuSysM_agBegInjH1RefNxt);

      /* Outputs for atomic SubSystem: '<S73>/If Action Subsystem3' */

      /* Switch: '<S110>/Switch1' incorporates:
       *  Constant: '<S110>/Constant1'
       *  Constant: '<S110>/Constant2'
       *  Constant: '<S110>/Constant3'
       *  Logic: '<S110>/Logical Operator1'
       *  RelationalOperator: '<S110>/Relational Operator'
       *  RelationalOperator: '<S110>/Relational Operator1'
       *  RelationalOperator: '<S110>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S73>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax69' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1Ref, FuSysM_agEndInjH2RefNxt);

      /* MinMax: '<S48>/MinMax71' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefNxt,
        FuSysM_agBegInjH1Ref);

      /* Product: '<S74>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax65'
       *  MinMax: '<S48>/MinMax72'
       *  Sum: '<S48>/Add52'
       *  Sum: '<S48>/Add53'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, FuSysM_agEndInjH1Ref) - rt_MINf
                      (FuSysM_agEndInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefNxt - FuSysM_agBegInjH2RefNxt);

      /* Outputs for atomic SubSystem: '<S74>/If Action Subsystem3' */

      /* Switch: '<S112>/Switch1' incorporates:
       *  Constant: '<S112>/Constant1'
       *  Constant: '<S112>/Constant2'
       *  Constant: '<S112>/Constant3'
       *  Logic: '<S112>/Logical Operator1'
       *  RelationalOperator: '<S112>/Relational Operator'
       *  RelationalOperator: '<S112>/Relational Operator1'
       *  RelationalOperator: '<S112>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S74>/If Action Subsystem3' */

      /* DataTypeConversion: '<S68>/OutDTConv' incorporates:
       *  Constant: '<S68>/offset'
       *  Constant: '<S68>/offset1'
       *  Constant: '<S68>/one_on_slope'
       *  Product: '<S68>/Product4'
       *  Sum: '<S68>/Add1'
       *  Sum: '<S68>/Add2'
       */
      localtmp = (32768.0F * locallocalDataTypeConversion4_0) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_a[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_o1) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_a[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd19_e) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_a[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_a[3] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_a[4] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_a[5] = locallocalOutDTConv_idx;

      /* Lookup: '<S57>/Look-Up Table'
       * About '<S57>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      {
        SInt32 i1;
        const UInt16 *u0 = localOutDTConv_a;
        UInt16 *y0 = localLookUpTable_oy;
        for (i1=0; i1 < 6; i1++) {
          LookUp_U16_U16( &(y0[i1]), (&(FuSysM_rMassInj_T[0])), u0[i1],
                         (&(FuSysM_rAgInj_A[0])), 8U);
        }
      }

      /* DataTypeDuplicate Block: '<S57>/Data Type Duplicate1'
       *
       * Regarding '<S57>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S93>/Divide' incorporates:
       *  DataTypeConversion: '<S48>/Data Type Conversion13'
       *  Lookup: '<S57>/Look-Up Table'
       */
      FuSysM_prm_mFuInjOvlpH1[0] = (((Float32)localLookUpTable_oy[0]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Prev;
      FuSysM_prm_mFuInjOvlpH1[1] = (((Float32)localLookUpTable_oy[1]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Prev;
      FuSysM_prm_mFuInjOvlpH1[2] = (((Float32)localLookUpTable_oy[2]) *
        3.051757813E-005F) * FuSysM_mFuReqInjS1;
      FuSysM_prm_mFuInjOvlpH1[3] = (((Float32)localLookUpTable_oy[3]) *
        3.051757813E-005F) * FuSysM_mFuReqInjS2;
      FuSysM_prm_mFuInjOvlpH1[4] = (((Float32)localLookUpTable_oy[4]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Nxt;
      FuSysM_prm_mFuInjOvlpH1[5] = (((Float32)localLookUpTable_oy[5]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Nxt;

      /* Product: '<S94>/Divide' incorporates:
       *  Constant: '<S48>/FuSysM_rMassPFuMeanEstim_C'
       *  DataTypeConversion: '<S48>/Data Type Conversion11'
       *  Sum: '<S48>/Add4'
       *  Sum: '<S48>/Add44'
       */
      localmin_0 = ((localAdd30_mn - FuSysM_mFuReqInjH1) -
                    (((((FuSysM_prm_mFuInjOvlpH1[0] + FuSysM_prm_mFuInjOvlpH1[1])
                        + FuSysM_prm_mFuInjOvlpH1[2]) + FuSysM_prm_mFuInjOvlpH1
                       [3]) + FuSysM_prm_mFuInjOvlpH1[4]) +
                     FuSysM_prm_mFuInjOvlpH1[5])) * (((Float32)
        FuSysM_rMassPFuMeanEstim_C) * 3.051757813E-005F);

      /* Product: '<S99>/Divide' incorporates:
       *  Sum: '<S48>/Add11'
       *  Sum: '<S48>/Add57'
       */
      FuSysM_prm_mFuPmpBegH1[0] = (locallocalDataTypeConversion5_i -
        locallocalDataTypeConversion5_0) * localDataTypeConversion4;
      FuSysM_prm_mFuPmpBegH1[1] = (locallocalDataTypeConversion5_1 -
        locallocalDataTypeConversion5_2) * localDataTypeConversion5;

      /* Sum: '<S48>/Add45' */
      localAdd30_mn = FuSysM_prm_mFuPmpBegH1[0] + FuSysM_prm_mFuPmpBegH1[1];

      /* MinMax: '<S48>/MinMax19' incorporates:
       *  Constant: '<S48>/Constant17'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH1RefPrev);

      /* MinMax: '<S48>/MinMax21' incorporates:
       *  Constant: '<S48>/Constant16'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefPrev, 0.0F);

      /* Product: '<S80>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax22'
       *  MinMax: '<S48>/MinMax47'
       *  Sum: '<S48>/Add37'
       *  Sum: '<S48>/Add38'
       */
      locallocalDataTypeConversion4_0 = (rt_MINf(localAdd1_nw,
        FuSysM_agBegInjH1Ref) - rt_MINf(FuSysM_agBegInjH1Ref,
        localDataTypeConversion1_i)) / (FuSysM_agEndInjH1RefPrev -
        FuSysM_agBegInjH1RefPrev);

      /* Outputs for atomic SubSystem: '<S80>/If Action Subsystem3' */

      /* Switch: '<S124>/Switch1' incorporates:
       *  Constant: '<S124>/Constant1'
       *  Constant: '<S124>/Constant2'
       *  Constant: '<S124>/Constant3'
       *  Logic: '<S124>/Logical Operator1'
       *  RelationalOperator: '<S124>/Relational Operator'
       *  RelationalOperator: '<S124>/Relational Operator1'
       *  RelationalOperator: '<S124>/Relational Operator3'
       */
      if (((locallocalDataTypeConversion4_0 != locallocalDataTypeConversion4_0) ||
           (locallocalDataTypeConversion4_0 > 3.000000005E+038F)) ||
          (-3.000000005E+038F > locallocalDataTypeConversion4_0)) {
        locallocalDataTypeConversion4_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S80>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax36' incorporates:
       *  Constant: '<S48>/Constant12'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH2RefPrev);

      /* MinMax: '<S48>/MinMax44' incorporates:
       *  Constant: '<S48>/Constant3'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefPrev, 0.0F);

      /* Product: '<S79>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax20'
       *  MinMax: '<S48>/MinMax48'
       *  Sum: '<S48>/Add28'
       *  Sum: '<S48>/Add29'
       */
      localAdd1_o1 = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH1Ref) - rt_MINf
                      (FuSysM_agBegInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefPrev - FuSysM_agBegInjH2RefPrev);

      /* Outputs for atomic SubSystem: '<S79>/If Action Subsystem3' */

      /* Switch: '<S122>/Switch1' incorporates:
       *  Constant: '<S122>/Constant1'
       *  Constant: '<S122>/Constant2'
       *  Constant: '<S122>/Constant3'
       *  Logic: '<S122>/Logical Operator1'
       *  RelationalOperator: '<S122>/Relational Operator'
       *  RelationalOperator: '<S122>/Relational Operator1'
       *  RelationalOperator: '<S122>/Relational Operator3'
       */
      if (((localAdd1_o1 != localAdd1_o1) || (localAdd1_o1 > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_o1)) {
        localAdd1_o1 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S79>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax32' incorporates:
       *  Constant: '<S48>/Constant6'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjS1Ref);

      /* MinMax: '<S48>/MinMax33' incorporates:
       *  Constant: '<S48>/Constant1'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjS1Ref, 0.0F);

      /* Product: '<S78>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax34'
       *  MinMax: '<S48>/MinMax35'
       *  Sum: '<S48>/Add36'
       *  Sum: '<S48>/Add9'
       */
      localAdd19_e = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH1Ref) - rt_MINf
                      (FuSysM_agBegInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjS1Ref - FuSysM_agBegInjS1Ref);

      /* Outputs for atomic SubSystem: '<S78>/If Action Subsystem3' */

      /* Switch: '<S120>/Switch1' incorporates:
       *  Constant: '<S120>/Constant1'
       *  Constant: '<S120>/Constant2'
       *  Constant: '<S120>/Constant3'
       *  Logic: '<S120>/Logical Operator1'
       *  RelationalOperator: '<S120>/Relational Operator'
       *  RelationalOperator: '<S120>/Relational Operator1'
       *  RelationalOperator: '<S120>/Relational Operator3'
       */
      if (((localAdd19_e != localAdd19_e) || (localAdd19_e > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd19_e)) {
        localAdd19_e = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S78>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax41' incorporates:
       *  Constant: '<S48>/Constant2'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjS2Ref);

      /* MinMax: '<S48>/MinMax42' incorporates:
       *  Constant: '<S48>/Constant4'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjS2Ref, 0.0F);

      /* Product: '<S77>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax43'
       *  MinMax: '<S48>/MinMax45'
       *  Sum: '<S48>/Add33'
       *  Sum: '<S48>/Add34'
       */
      localDivide_hb = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH1Ref) - rt_MINf
                        (FuSysM_agBegInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjS2Ref - FuSysM_agBegInjS2Ref);

      /* Outputs for atomic SubSystem: '<S77>/If Action Subsystem3' */

      /* Switch: '<S118>/Switch1' incorporates:
       *  Constant: '<S118>/Constant1'
       *  Constant: '<S118>/Constant2'
       *  Constant: '<S118>/Constant3'
       *  Logic: '<S118>/Logical Operator1'
       *  RelationalOperator: '<S118>/Relational Operator'
       *  RelationalOperator: '<S118>/Relational Operator1'
       *  RelationalOperator: '<S118>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S77>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax57' incorporates:
       *  Constant: '<S48>/Constant5'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH1RefNxt);

      /* MinMax: '<S48>/MinMax59' incorporates:
       *  Constant: '<S48>/Constant8'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefNxt, 0.0F);

      /* Product: '<S76>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax60'
       *  MinMax: '<S48>/MinMax63'
       *  Sum: '<S48>/Add48'
       *  Sum: '<S48>/Add49'
       */
      localDivide_o3 = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH1Ref) - rt_MINf
                        (FuSysM_agBegInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH1RefNxt - FuSysM_agBegInjH1RefNxt);

      /* Outputs for atomic SubSystem: '<S76>/If Action Subsystem3' */

      /* Switch: '<S116>/Switch1' incorporates:
       *  Constant: '<S116>/Constant1'
       *  Constant: '<S116>/Constant2'
       *  Constant: '<S116>/Constant3'
       *  Logic: '<S116>/Logical Operator1'
       *  RelationalOperator: '<S116>/Relational Operator'
       *  RelationalOperator: '<S116>/Relational Operator1'
       *  RelationalOperator: '<S116>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S76>/If Action Subsystem3' */

      /* MinMax: '<S48>/MinMax61' incorporates:
       *  Constant: '<S48>/Constant9'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH2RefNxt);

      /* MinMax: '<S48>/MinMax62' incorporates:
       *  Constant: '<S48>/Constant10'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefNxt, 0.0F);

      /* Product: '<S75>/Divide' incorporates:
       *  MinMax: '<S48>/MinMax58'
       *  MinMax: '<S48>/MinMax64'
       *  Sum: '<S48>/Add46'
       *  Sum: '<S48>/Add47'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH1Ref) - rt_MINf
                      (FuSysM_agBegInjH1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefNxt - FuSysM_agBegInjH2RefNxt);

      /* Outputs for atomic SubSystem: '<S75>/If Action Subsystem3' */

      /* Switch: '<S114>/Switch1' incorporates:
       *  Constant: '<S114>/Constant1'
       *  Constant: '<S114>/Constant2'
       *  Constant: '<S114>/Constant3'
       *  Logic: '<S114>/Logical Operator1'
       *  RelationalOperator: '<S114>/Relational Operator'
       *  RelationalOperator: '<S114>/Relational Operator1'
       *  RelationalOperator: '<S114>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S75>/If Action Subsystem3' */

      /* DataTypeConversion: '<S64>/OutDTConv' incorporates:
       *  Constant: '<S64>/offset'
       *  Constant: '<S64>/offset1'
       *  Constant: '<S64>/one_on_slope'
       *  Product: '<S64>/Product4'
       *  Sum: '<S64>/Add1'
       *  Sum: '<S64>/Add2'
       */
      localtmp = (32768.0F * locallocalDataTypeConversion4_0) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_h[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_o1) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_h[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd19_e) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_h[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_h[3] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_h[4] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_h[5] = locallocalOutDTConv_idx;

      /* Lookup: '<S56>/Look-Up Table'
       * About '<S56>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      {
        SInt32 i1;
        const UInt16 *u0 = localOutDTConv_h;
        UInt16 *y0 = localLookUpTable_eoo;
        for (i1=0; i1 < 6; i1++) {
          LookUp_U16_U16( &(y0[i1]), (&(FuSysM_rMassInj_T[0])), u0[i1],
                         (&(FuSysM_rAgInj_A[0])), 8U);
        }
      }

      /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate1'
       *
       * Regarding '<S56>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S98>/Divide' incorporates:
       *  DataTypeConversion: '<S48>/Data Type Conversion12'
       *  Lookup: '<S56>/Look-Up Table'
       */
      FuSysM_prm_mFuInjBegH1[0] = (((Float32)localLookUpTable_eoo[0]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Prev;
      FuSysM_prm_mFuInjBegH1[1] = (((Float32)localLookUpTable_eoo[1]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Prev;
      FuSysM_prm_mFuInjBegH1[2] = (((Float32)localLookUpTable_eoo[2]) *
        3.051757813E-005F) * FuSysM_mFuReqInjS1;
      FuSysM_prm_mFuInjBegH1[3] = (((Float32)localLookUpTable_eoo[3]) *
        3.051757813E-005F) * FuSysM_mFuReqInjS2;
      FuSysM_prm_mFuInjBegH1[4] = (((Float32)localLookUpTable_eoo[4]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Nxt;
      FuSysM_prm_mFuInjBegH1[5] = (((Float32)localLookUpTable_eoo[5]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Nxt;

      /* Sum: '<S48>/Add35' incorporates:
       *  Product: '<S100>/Divide'
       *  Sum: '<S48>/Add43'
       *  Sum: '<S48>/Add7'
       */
      localAdd1_nw = ((localAdd30_mn - (((((FuSysM_prm_mFuInjBegH1[0] +
        FuSysM_prm_mFuInjBegH1[1]) + FuSysM_prm_mFuInjBegH1[2]) +
        FuSysM_prm_mFuInjBegH1[3]) + FuSysM_prm_mFuInjBegH1[4]) +
        FuSysM_prm_mFuInjBegH1[5])) * localDataTypeConversion7) +
        localDataTypeConversion8;

      /* DataTypeConversion: '<S48>/Data Type Conversion3' incorporates:
       *  Constant: '<S48>/FuSysM_pFuMin_C'
       */
      localDataTypeConversion1_i = ((Float32)FuSysM_pFuMin_C) * 781.25F;

      /* MinMax: '<S48>/MinMax' */
      FuSysM_pFuEstimBegH1 = rt_MAXf(localAdd1_nw, localDataTypeConversion1_i);

      /* Sum: '<S48>/Add2' incorporates:
       *  Product: '<S95>/Divide'
       */
      localAdd1_nw = (localDataTypeConversion7 * localmin_0) +
        FuSysM_pFuEstimBegH1;

      /* DataTypeConversion: '<S62>/OutDTConv' incorporates:
       *  Constant: '<S62>/offset'
       *  Constant: '<S62>/offset1'
       *  Constant: '<S62>/one_on_slope'
       *  MinMax: '<S48>/MinMax74'
       *  Product: '<S62>/Product4'
       *  Sum: '<S62>/Add1'
       *  Sum: '<S62>/Add2'
       */
      localtmp = (1.279999968E-003F * rt_MAXf(localAdd1_nw,
        localDataTypeConversion1_i)) + 0.5F;
      if (localtmp < 65536.0F) {
        pFuM_B.Merge = (UInt16)localtmp;
      } else {
        pFuM_B.Merge = MAX_uint16_T;
      }
    } else {
      /* DataTypeConversion: '<S149>/OutDTConv' incorporates:
       *  Constant: '<S149>/offset'
       *  Constant: '<S149>/offset1'
       *  Constant: '<S149>/one_on_slope'
       *  Product: '<S149>/Product4'
       *  Sum: '<S149>/Add1'
       *  Sum: '<S149>/Add2'
       */
      pFuM_B.Merge = (UInt16)((1.279999968E-003F * localDataTypeConversion8) +
        0.5F);
    }

    /* If: '<S46>/If1' incorporates:
     *  ActionPort: '<S50>/Action Port'
     *  ActionPort: '<S51>/Action Port'
     *  Constant: '<S46>/Constant13'
     *  RelationalOperator: '<S46>/Relational Operator3'
     *  SubSystem: '<S46>/F03_PfuInjS1Clcn'
     *  SubSystem: '<S46>/F04_PfuInjS1NotClcn'
     */
    if (FuSysM_mFuReqInjS1 > 0.0F) {
      /* MinMax: '<S50>/MinMax3' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS1Ref, FuSysM_agEndInjH1Ref);

      /* MinMax: '<S50>/MinMax6' */
      localmin = rt_MINf(localAdd1_nw, FuSysM_agEndInjS1Ref);

      /* MinMax: '<S50>/MinMax4' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1Ref, FuSysM_agBegInjS1Ref);

      /* MinMax: '<S50>/MinMax8' */
      localAdd14_i = rt_MINf(FuSysM_agEndInjS1Ref, localAdd1_nw);

      /* Sum: '<S50>/Add10' */
      localmin_0 = FuSysM_agEndInjS1Ref - FuSysM_agBegInjS1Ref;

      /* MinMax: '<S50>/MinMax24' */
      localAdd1_nw = rt_MINf(FuSysM_agEndInjS1Ref, localDataTypeConversion9_g);

      /* Sum: '<S50>/Add11' incorporates:
       *  MinMax: '<S50>/MinMax23'
       */
      localAdd30_mn = rt_MAXf(localAdd1_nw, FuSysM_agBegInjS1Ref) -
        FuSysM_agBegInjS1Ref;

      /* Sum: '<S50>/Add12' */
      localAdd12_e = FuSysM_agEndInjH2Ref - FuSysM_agBegInjH2Ref;

      /* Product: '<S180>/Divide' incorporates:
       *  Constant: '<S50>/Constant22'
       *  Constant: '<S50>/Constant34'
       *  MinMax: '<S50>/MinMax28'
       *  MinMax: '<S50>/MinMax38'
       *  Sum: '<S50>/Add17'
       *  Sum: '<S50>/Add47'
       */
      localDivide_hb = (rt_MINf(0.0F, localDataTypeConversion1) - rt_MINf
                        (localDataTypeConversion9_g, 0.0F)) /
        (localDataTypeConversion1 - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S180>/If Action Subsystem3' */

      /* Switch: '<S226>/Switch1' incorporates:
       *  Constant: '<S226>/Constant1'
       *  Constant: '<S226>/Constant2'
       *  Constant: '<S226>/Constant3'
       *  Logic: '<S226>/Logical Operator1'
       *  RelationalOperator: '<S226>/Relational Operator'
       *  RelationalOperator: '<S226>/Relational Operator1'
       *  RelationalOperator: '<S226>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S180>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax14' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion9_g, FuSysM_agBegInjS1Ref);

      /* Product: '<S179>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax30'
       *  Sum: '<S50>/Add18'
       *  Sum: '<S50>/Add24'
       */
      localDataTypeConversion1_i = (rt_MINf(localAdd1_nw,
        localDataTypeConversion1) - localDataTypeConversion9_g) /
        (localDataTypeConversion1 - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S179>/If Action Subsystem3' */

      /* Switch: '<S224>/Switch1' incorporates:
       *  Constant: '<S224>/Constant1'
       *  Constant: '<S224>/Constant2'
       *  Constant: '<S224>/Constant3'
       *  Logic: '<S224>/Logical Operator1'
       *  RelationalOperator: '<S224>/Relational Operator'
       *  RelationalOperator: '<S224>/Relational Operator1'
       *  RelationalOperator: '<S224>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S179>/If Action Subsystem3' */

      /* Product: '<S178>/Divide' incorporates:
       *  Constant: '<S50>/Constant38'
       *  Constant: '<S50>/Constant8'
       *  MinMax: '<S50>/MinMax16'
       *  MinMax: '<S50>/MinMax29'
       *  Sum: '<S50>/Add23'
       *  Sum: '<S50>/Add54'
       */
      localDivide_o3 = (rt_MINf(0.0F, localDataTypeConversion3) - rt_MINf
                        (localDataTypeConversion2, 0.0F)) /
        (localDataTypeConversion3 - localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S178>/If Action Subsystem3' */

      /* Switch: '<S222>/Switch1' incorporates:
       *  Constant: '<S222>/Constant1'
       *  Constant: '<S222>/Constant2'
       *  Constant: '<S222>/Constant3'
       *  Logic: '<S222>/Logical Operator1'
       *  RelationalOperator: '<S222>/Relational Operator'
       *  RelationalOperator: '<S222>/Relational Operator1'
       *  RelationalOperator: '<S222>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S178>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax15' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion2, FuSysM_agBegInjS1Ref);

      /* Product: '<S177>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax27'
       *  Sum: '<S50>/Add26'
       *  Sum: '<S50>/Add46'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, localDataTypeConversion3) -
                      localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S177>/If Action Subsystem3' */

      /* Switch: '<S220>/Switch1' incorporates:
       *  Constant: '<S220>/Constant1'
       *  Constant: '<S220>/Constant2'
       *  Constant: '<S220>/Constant3'
       *  Logic: '<S220>/Logical Operator1'
       *  RelationalOperator: '<S220>/Relational Operator'
       *  RelationalOperator: '<S220>/Relational Operator1'
       *  RelationalOperator: '<S220>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S177>/If Action Subsystem3' */

      /* DataTypeConversion: '<S156>/OutDTConv' incorporates:
       *  Constant: '<S156>/offset'
       *  Constant: '<S156>/offset1'
       *  Constant: '<S156>/one_on_slope'
       *  Product: '<S156>/Product4'
       *  Sum: '<S156>/Add1'
       *  Sum: '<S156>/Add2'
       */
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_a[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_a[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_a[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_a[3] = locallocalOutDTConv_idx;

      /* Lookup2D: '<S154>/Look-Up Table (2-D)'
       * About '<S154>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localOutDTConv_lv[0]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_a[0], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_lv[1]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_a[1], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_lv[2]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_a[2], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_lv[3]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_a[3], (&(FuSysM_rAgPmp_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S154>/Data Type Duplicate2'
       *
       * Regarding '<S154>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Product: '<S184>/Divide' incorporates:
       *  DataTypeConversion: '<S50>/Data Type Conversion13'
       *  Sum: '<S50>/Add22'
       *  Sum: '<S50>/Add55'
       */
      FuSysM_prm_mFuPmpBegS1[0] = ((((Float32)localOutDTConv_lv[1]) *
        3.051757813E-005F) - (((Float32)localOutDTConv_lv[0]) *
        3.051757813E-005F)) * localDataTypeConversion4;
      FuSysM_prm_mFuPmpBegS1[1] = ((((Float32)localOutDTConv_lv[3]) *
        3.051757813E-005F) - (((Float32)localOutDTConv_lv[2]) *
        3.051757813E-005F)) * localDataTypeConversion5;

      /* Sum: '<S50>/Add45' */
      localAdd1_o1 = FuSysM_prm_mFuPmpBegS1[0] + FuSysM_prm_mFuPmpBegS1[1];

      /* MinMax: '<S50>/MinMax12' incorporates:
       *  Constant: '<S50>/Constant12'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH1RefPrev);

      /* MinMax: '<S50>/MinMax39' incorporates:
       *  Constant: '<S50>/Constant1'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefPrev, 0.0F);

      /* Product: '<S176>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax13'
       *  MinMax: '<S50>/MinMax31'
       *  Sum: '<S50>/Add15'
       *  Sum: '<S50>/Add16'
       */
      localAdd19_e = (rt_MINf(localAdd1_nw, FuSysM_agBegInjS1Ref) - rt_MINf
                      (FuSysM_agBegInjS1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH1RefPrev - FuSysM_agBegInjH1RefPrev);

      /* Outputs for atomic SubSystem: '<S176>/If Action Subsystem3' */

      /* Switch: '<S218>/Switch1' incorporates:
       *  Constant: '<S218>/Constant1'
       *  Constant: '<S218>/Constant2'
       *  Constant: '<S218>/Constant3'
       *  Logic: '<S218>/Logical Operator1'
       *  RelationalOperator: '<S218>/Relational Operator'
       *  RelationalOperator: '<S218>/Relational Operator1'
       *  RelationalOperator: '<S218>/Relational Operator3'
       */
      if (((localAdd19_e != localAdd19_e) || (localAdd19_e > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd19_e)) {
        localAdd19_e = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S176>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax41' incorporates:
       *  Constant: '<S50>/Constant3'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH2RefPrev);

      /* MinMax: '<S50>/MinMax44' incorporates:
       *  Constant: '<S50>/Constant4'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefPrev, 0.0F);

      /* Product: '<S174>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax42'
       *  MinMax: '<S50>/MinMax43'
       *  Sum: '<S50>/Add29'
       *  Sum: '<S50>/Add30'
       */
      localDivide_hb = (rt_MINf(localAdd1_nw, FuSysM_agBegInjS1Ref) - rt_MINf
                        (FuSysM_agBegInjS1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefPrev - FuSysM_agBegInjH2RefPrev);

      /* Outputs for atomic SubSystem: '<S174>/If Action Subsystem3' */

      /* Switch: '<S214>/Switch1' incorporates:
       *  Constant: '<S214>/Constant1'
       *  Constant: '<S214>/Constant2'
       *  Constant: '<S214>/Constant3'
       *  Logic: '<S214>/Logical Operator1'
       *  RelationalOperator: '<S214>/Relational Operator'
       *  RelationalOperator: '<S214>/Relational Operator1'
       *  RelationalOperator: '<S214>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S174>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax17' incorporates:
       *  Constant: '<S50>/Constant5'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH1Ref);

      /* MinMax: '<S50>/MinMax18' incorporates:
       *  Constant: '<S50>/Constant6'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1Ref, 0.0F);

      /* Product: '<S163>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax25'
       *  MinMax: '<S50>/MinMax26'
       *  Sum: '<S50>/Add14'
       *  Sum: '<S50>/Add20'
       */
      localDivide_o3 = (rt_MINf(localAdd1_nw, FuSysM_agBegInjS1Ref) - rt_MINf
                        (FuSysM_agBegInjS1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH1Ref - FuSysM_agBegInjH1Ref);

      /* Outputs for atomic SubSystem: '<S163>/If Action Subsystem3' */

      /* Switch: '<S192>/Switch1' incorporates:
       *  Constant: '<S192>/Constant1'
       *  Constant: '<S192>/Constant2'
       *  Constant: '<S192>/Constant3'
       *  Logic: '<S192>/Logical Operator1'
       *  RelationalOperator: '<S192>/Relational Operator'
       *  RelationalOperator: '<S192>/Relational Operator1'
       *  RelationalOperator: '<S192>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S163>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax45' incorporates:
       *  Constant: '<S50>/Constant7'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH2Ref);

      /* MinMax: '<S50>/MinMax46' incorporates:
       *  Constant: '<S50>/Constant9'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2Ref, 0.0F);

      /* Product: '<S175>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax47'
       *  MinMax: '<S50>/MinMax48'
       *  Sum: '<S50>/Add31'
       *  Sum: '<S50>/Add32'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, FuSysM_agBegInjS1Ref) - rt_MINf
                      (FuSysM_agBegInjS1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2Ref - FuSysM_agBegInjH2Ref);

      /* Outputs for atomic SubSystem: '<S175>/If Action Subsystem3' */

      /* Switch: '<S216>/Switch1' incorporates:
       *  Constant: '<S216>/Constant1'
       *  Constant: '<S216>/Constant2'
       *  Constant: '<S216>/Constant3'
       *  Logic: '<S216>/Logical Operator1'
       *  RelationalOperator: '<S216>/Relational Operator'
       *  RelationalOperator: '<S216>/Relational Operator1'
       *  RelationalOperator: '<S216>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S175>/If Action Subsystem3' */

      /* DataTypeConversion: '<S157>/OutDTConv' incorporates:
       *  Constant: '<S157>/offset'
       *  Constant: '<S157>/offset1'
       *  Constant: '<S157>/one_on_slope'
       *  Product: '<S157>/Product4'
       *  Sum: '<S157>/Add1'
       *  Sum: '<S157>/Add2'
       */
      localtmp = (32768.0F * localAdd19_e) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_is[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_is[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_is[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_is[3] = locallocalOutDTConv_idx;

      /* Lookup: '<S150>/Look-Up Table'
       * About '<S150>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_a[0]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_is[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_a[1]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_is[1], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_a[2]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_is[2], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_a[3]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_is[3], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S150>/Data Type Duplicate1'
       *
       * Regarding '<S150>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S183>/Divide' incorporates:
       *  DataTypeConversion: '<S50>/Data Type Conversion12'
       *  Lookup: '<S150>/Look-Up Table'
       */
      FuSysM_prm_mFuInjBegS1[0] = (((Float32)localLookUpTable_a[0]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Prev;
      FuSysM_prm_mFuInjBegS1[1] = (((Float32)localLookUpTable_a[1]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Prev;
      FuSysM_prm_mFuInjBegS1[2] = (((Float32)localLookUpTable_a[2]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1;
      FuSysM_prm_mFuInjBegS1[3] = (((Float32)localLookUpTable_a[3]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2;

      /* Sum: '<S50>/Add13' incorporates:
       *  Product: '<S185>/Divide'
       *  Sum: '<S50>/Add19'
       *  Sum: '<S50>/Add43'
       */
      locallocalDataTypeConversion4_0 = ((localAdd1_o1 -
        (((FuSysM_prm_mFuInjBegS1[0] + FuSysM_prm_mFuInjBegS1[1]) +
          FuSysM_prm_mFuInjBegS1[2]) + FuSysM_prm_mFuInjBegS1[3])) *
        localDataTypeConversion7) + localDataTypeConversion8;

      /* MinMax: '<S50>/MinMax5' */
      localAdd1_nw = rt_MINf(FuSysM_agEndInjS1Ref, localDataTypeConversion2);

      /* Sum: '<S50>/Add2' incorporates:
       *  MinMax: '<S50>/MinMax1'
       */
      localAdd19_e = rt_MAXf(localAdd1_nw, FuSysM_agBegInjS1Ref) -
        FuSysM_agBegInjS1Ref;

      /* MinMax: '<S50>/MinMax78' */
      localAdd1_nw = rt_MINf(localDataTypeConversion1, FuSysM_agEndInjS1Ref);

      /* Product: '<S181>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax32'
       *  Sum: '<S50>/Add49'
       *  Sum: '<S50>/Add56'
       */
      localDivide_hb = (rt_MAXf(localDataTypeConversion9_g, localAdd1_nw) -
                        localDataTypeConversion9_g) / (localDataTypeConversion1
        - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S181>/If Action Subsystem3' */

      /* Switch: '<S228>/Switch1' incorporates:
       *  Constant: '<S228>/Constant1'
       *  Constant: '<S228>/Constant2'
       *  Constant: '<S228>/Constant3'
       *  Logic: '<S228>/Logical Operator1'
       *  RelationalOperator: '<S228>/Relational Operator'
       *  RelationalOperator: '<S228>/Relational Operator1'
       *  RelationalOperator: '<S228>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S181>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax2' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion9_g, FuSysM_agBegInjS1Ref);

      /* Product: '<S182>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax22'
       *  Sum: '<S50>/Add28'
       *  Sum: '<S50>/Add50'
       */
      localDivide_o3 = (rt_MINf(localDataTypeConversion1, localAdd1_nw) -
                        localDataTypeConversion9_g) / (localDataTypeConversion1
        - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S182>/If Action Subsystem3' */

      /* Switch: '<S230>/Switch1' incorporates:
       *  Constant: '<S230>/Constant1'
       *  Constant: '<S230>/Constant2'
       *  Constant: '<S230>/Constant3'
       *  Logic: '<S230>/Logical Operator1'
       *  RelationalOperator: '<S230>/Relational Operator'
       *  RelationalOperator: '<S230>/Relational Operator1'
       *  RelationalOperator: '<S230>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S182>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax34' */
      localAdd1_nw = rt_MINf(localDataTypeConversion3, FuSysM_agEndInjS1Ref);

      /* Product: '<S164>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax20'
       *  Sum: '<S50>/Add25'
       *  Sum: '<S50>/Add37'
       */
      localDataTypeConversion1_i = (rt_MAXf(localDataTypeConversion2,
        localAdd1_nw) - localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S164>/If Action Subsystem3' */

      /* Switch: '<S194>/Switch1' incorporates:
       *  Constant: '<S194>/Constant1'
       *  Constant: '<S194>/Constant2'
       *  Constant: '<S194>/Constant3'
       *  Logic: '<S194>/Logical Operator1'
       *  RelationalOperator: '<S194>/Relational Operator'
       *  RelationalOperator: '<S194>/Relational Operator1'
       *  RelationalOperator: '<S194>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S164>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax77' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion2, FuSysM_agBegInjS1Ref);

      /* Product: '<S165>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax79'
       *  Sum: '<S50>/Add35'
       *  Sum: '<S50>/Add36'
       */
      localAdd1_nw = (rt_MINf(localDataTypeConversion3, localAdd1_nw) -
                      localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S165>/If Action Subsystem3' */

      /* Switch: '<S196>/Switch1' incorporates:
       *  Constant: '<S196>/Constant1'
       *  Constant: '<S196>/Constant2'
       *  Constant: '<S196>/Constant3'
       *  Logic: '<S196>/Logical Operator1'
       *  RelationalOperator: '<S196>/Relational Operator'
       *  RelationalOperator: '<S196>/Relational Operator1'
       *  RelationalOperator: '<S196>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S165>/If Action Subsystem3' */

      /* DataTypeConversion: '<S158>/OutDTConv' incorporates:
       *  Constant: '<S158>/offset'
       *  Constant: '<S158>/offset1'
       *  Constant: '<S158>/one_on_slope'
       *  Product: '<S158>/Product4'
       *  Sum: '<S158>/Add1'
       *  Sum: '<S158>/Add2'
       */
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lv[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lv[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lv[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lv[3] = locallocalOutDTConv_idx;

      /* Lookup2D: '<S155>/Look-Up Table (2-D)'
       * About '<S155>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_a[0]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_lv[0], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_a[1]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_lv[1], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_a[2]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_lv[2], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_a[3]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_lv[3], (&(FuSysM_rAgPmp_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S155>/Data Type Duplicate2'
       *
       * Regarding '<S155>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S50>/Data Type Conversion15' */
      locallocalDataTypeConversion5_0 = ((Float32)localLookUpTable2D_a[0]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_i = ((Float32)localLookUpTable2D_a[1]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_2 = ((Float32)localLookUpTable2D_a[2]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_1 = ((Float32)localLookUpTable2D_a[3]) *
        3.051757813E-005F;

      /* MinMax: '<S50>/MinMax51' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS1Ref, FuSysM_agEndInjH1RefPrev);

      /* MinMax: '<S50>/MinMax53' */
      localDivide_hb = rt_MINf(localAdd1_nw, FuSysM_agEndInjS1Ref);

      /* MinMax: '<S50>/MinMax52' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1RefPrev, FuSysM_agBegInjS1Ref);

      /* MinMax: '<S50>/MinMax55' */
      localDivide_o3 = rt_MINf(FuSysM_agEndInjS1Ref, localAdd1_nw);

      /* MinMax: '<S50>/MinMax21' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion1, FuSysM_agBegInjS1Ref);

      /* Product: '<S166>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax19'
       *  Sum: '<S50>/Add5'
       *  Sum: '<S50>/Add8'
       */
      localDataTypeConversion1_i = (FuSysM_agEndInjS1Ref - rt_MINf
        (FuSysM_agEndInjS1Ref, localAdd1_nw)) / (FuSysM_agEndInjS1Ref -
        FuSysM_agBegInjS1Ref);

      /* Outputs for atomic SubSystem: '<S166>/If Action Subsystem3' */

      /* Switch: '<S198>/Switch1' incorporates:
       *  Constant: '<S198>/Constant1'
       *  Constant: '<S198>/Constant2'
       *  Constant: '<S198>/Constant3'
       *  Logic: '<S198>/Logical Operator1'
       *  RelationalOperator: '<S198>/Relational Operator'
       *  RelationalOperator: '<S198>/Relational Operator1'
       *  RelationalOperator: '<S198>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S166>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax36' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion3, FuSysM_agBegInjS1Ref);

      /* Product: '<S167>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax33'
       *  Sum: '<S50>/Add38'
       *  Sum: '<S50>/Add39'
       */
      localAdd1_nw = (FuSysM_agEndInjS1Ref - rt_MINf(FuSysM_agEndInjS1Ref,
        localAdd1_nw)) / (FuSysM_agEndInjS1Ref - FuSysM_agBegInjS1Ref);

      /* Outputs for atomic SubSystem: '<S167>/If Action Subsystem3' */

      /* Switch: '<S200>/Switch1' incorporates:
       *  Constant: '<S200>/Constant1'
       *  Constant: '<S200>/Constant2'
       *  Constant: '<S200>/Constant3'
       *  Logic: '<S200>/Logical Operator1'
       *  RelationalOperator: '<S200>/Relational Operator'
       *  RelationalOperator: '<S200>/Relational Operator1'
       *  RelationalOperator: '<S200>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S167>/If Action Subsystem3' */

      /* DataTypeConversion: '<S159>/OutDTConv' incorporates:
       *  Constant: '<S159>/offset'
       *  Constant: '<S159>/offset1'
       *  Constant: '<S159>/one_on_slope'
       *  Product: '<S159>/Product4'
       *  Sum: '<S159>/Add1'
       *  Sum: '<S159>/Add2'
       */
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_it[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_it[1] = locallocalOutDTConv_idx;

      /* Lookup: '<S151>/Look-Up Table'
       * About '<S151>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_b[0]), (&(FuSysM_facCorMassEndPmpStk_T
        [0])), localOutDTConv_it[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_b[1]), (&(FuSysM_facCorMassEndPmpStk_T
        [0])), localOutDTConv_it[1], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S151>/Data Type Duplicate1'
       *
       * Regarding '<S151>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S50>/Data Type Conversion1' incorporates:
       *  Lookup: '<S151>/Look-Up Table'
       */
      FuSysM_prm_fac1CorMassPmpInjS1[0] = ((Float32)localLookUpTable_b[0]) *
        3.051757813E-005F;
      FuSysM_prm_fac1CorMassPmpInjS1[1] = ((Float32)localLookUpTable_b[1]) *
        3.051757813E-005F;

      /* Product: '<S168>/Divide' */
      localDataTypeConversion1_i = localAdd30_mn / localmin_0;

      /* Outputs for atomic SubSystem: '<S168>/If Action Subsystem3' */

      /* Switch: '<S202>/Switch1' incorporates:
       *  Constant: '<S202>/Constant1'
       *  Constant: '<S202>/Constant2'
       *  Constant: '<S202>/Constant3'
       *  Logic: '<S202>/Logical Operator1'
       *  RelationalOperator: '<S202>/Relational Operator'
       *  RelationalOperator: '<S202>/Relational Operator1'
       *  RelationalOperator: '<S202>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S168>/If Action Subsystem3' */

      /* Product: '<S169>/Divide' incorporates:
       *  Sum: '<S50>/Add33'
       */
      localAdd1_nw = localAdd19_e / (FuSysM_agEndInjS1Ref - FuSysM_agBegInjS1Ref);

      /* Outputs for atomic SubSystem: '<S169>/If Action Subsystem3' */

      /* Switch: '<S204>/Switch1' incorporates:
       *  Constant: '<S204>/Constant1'
       *  Constant: '<S204>/Constant2'
       *  Constant: '<S204>/Constant3'
       *  Logic: '<S204>/Logical Operator1'
       *  RelationalOperator: '<S204>/Relational Operator'
       *  RelationalOperator: '<S204>/Relational Operator1'
       *  RelationalOperator: '<S204>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S169>/If Action Subsystem3' */

      /* DataTypeConversion: '<S160>/OutDTConv' incorporates:
       *  Constant: '<S160>/offset'
       *  Constant: '<S160>/offset1'
       *  Constant: '<S160>/one_on_slope'
       *  Product: '<S160>/Product4'
       *  Sum: '<S160>/Add1'
       *  Sum: '<S160>/Add2'
       */
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_b[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_b[1] = locallocalOutDTConv_idx;

      /* Lookup: '<S152>/Look-Up Table'
       * About '<S152>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_n[0]), (&(FuSysM_facCorMassBegPmpStk_T
        [0])), localOutDTConv_b[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_n[1]), (&(FuSysM_facCorMassBegPmpStk_T
        [0])), localOutDTConv_b[1], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S152>/Data Type Duplicate1'
       *
       * Regarding '<S152>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S50>/Data Type Conversion2' incorporates:
       *  Lookup: '<S152>/Look-Up Table'
       */
      FuSysM_prm_fac2CorMassPmpInjS1[0] = ((Float32)localLookUpTable_n[0]) *
        3.051757813E-005F;
      FuSysM_prm_fac2CorMassPmpInjS1[1] = ((Float32)localLookUpTable_n[1]) *
        3.051757813E-005F;

      /* Product: '<S187>/Divide' incorporates:
       *  Constant: '<S50>/Constant2'
       *  Product: '<S186>/Divide'
       *  Sum: '<S50>/Add21'
       *  Sum: '<S50>/Add48'
       *  Sum: '<S50>/Add9'
       */
      FuSysM_prm_mFuPmpOvlpS1[0] = ((locallocalDataTypeConversion5_0 -
        locallocalDataTypeConversion5_i) * localDataTypeConversion4) * ((1.0F +
        FuSysM_prm_fac1CorMassPmpInjS1[0]) - FuSysM_prm_fac2CorMassPmpInjS1[0]);
      FuSysM_prm_mFuPmpOvlpS1[1] = ((locallocalDataTypeConversion5_2 -
        locallocalDataTypeConversion5_1) * localDataTypeConversion5) * ((1.0F +
        FuSysM_prm_fac1CorMassPmpInjS1[1]) - FuSysM_prm_fac2CorMassPmpInjS1[1]);

      /* Sum: '<S50>/Add40' */
      localAdd19_e = FuSysM_prm_mFuPmpOvlpS1[0] + FuSysM_prm_mFuPmpOvlpS1[1];

      /* Product: '<S170>/Divide' incorporates:
       *  Sum: '<S50>/Add27'
       *  Sum: '<S50>/Add41'
       */
      localAdd1_o1 = (localDivide_hb - localDivide_o3) /
        (FuSysM_agEndInjH1RefPrev - FuSysM_agBegInjH1RefPrev);

      /* Outputs for atomic SubSystem: '<S170>/If Action Subsystem3' */

      /* Switch: '<S206>/Switch1' incorporates:
       *  Constant: '<S206>/Constant1'
       *  Constant: '<S206>/Constant2'
       *  Constant: '<S206>/Constant3'
       *  Logic: '<S206>/Logical Operator1'
       *  RelationalOperator: '<S206>/Relational Operator'
       *  RelationalOperator: '<S206>/Relational Operator1'
       *  RelationalOperator: '<S206>/Relational Operator3'
       */
      if (((localAdd1_o1 != localAdd1_o1) || (localAdd1_o1 > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_o1)) {
        localAdd1_o1 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S170>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax54' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS1Ref, FuSysM_agEndInjH2RefPrev);

      /* MinMax: '<S50>/MinMax56' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefPrev,
        FuSysM_agBegInjS1Ref);

      /* Product: '<S171>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax49'
       *  MinMax: '<S50>/MinMax50'
       *  Sum: '<S50>/Add34'
       *  Sum: '<S50>/Add42'
       */
      localDivide_hb = (rt_MINf(localAdd1_nw, FuSysM_agEndInjS1Ref) - rt_MINf
                        (FuSysM_agEndInjS1Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefPrev - FuSysM_agBegInjH2RefPrev);

      /* Outputs for atomic SubSystem: '<S171>/If Action Subsystem3' */

      /* Switch: '<S208>/Switch1' incorporates:
       *  Constant: '<S208>/Constant1'
       *  Constant: '<S208>/Constant2'
       *  Constant: '<S208>/Constant3'
       *  Logic: '<S208>/Logical Operator1'
       *  RelationalOperator: '<S208>/Relational Operator'
       *  RelationalOperator: '<S208>/Relational Operator1'
       *  RelationalOperator: '<S208>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S171>/If Action Subsystem3' */

      /* Product: '<S172>/Divide' incorporates:
       *  Sum: '<S50>/Add1'
       *  Sum: '<S50>/Add4'
       */
      localDivide_o3 = (localmin - localAdd14_i) / (FuSysM_agEndInjH1Ref -
        FuSysM_agBegInjH1Ref);

      /* Outputs for atomic SubSystem: '<S172>/If Action Subsystem3' */

      /* Switch: '<S210>/Switch1' incorporates:
       *  Constant: '<S210>/Constant1'
       *  Constant: '<S210>/Constant2'
       *  Constant: '<S210>/Constant3'
       *  Logic: '<S210>/Logical Operator1'
       *  RelationalOperator: '<S210>/Relational Operator'
       *  RelationalOperator: '<S210>/Relational Operator1'
       *  RelationalOperator: '<S210>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S172>/If Action Subsystem3' */

      /* MinMax: '<S50>/MinMax7' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS1Ref, FuSysM_agEndInjH2Ref);

      /* MinMax: '<S50>/MinMax9' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2Ref,
        FuSysM_agBegInjS1Ref);

      /* Product: '<S173>/Divide' incorporates:
       *  MinMax: '<S50>/MinMax10'
       *  MinMax: '<S50>/MinMax11'
       *  Sum: '<S50>/Add6'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, FuSysM_agEndInjS1Ref) - rt_MINf
                      (FuSysM_agEndInjS1Ref, localDataTypeConversion1_i)) /
        localAdd12_e;

      /* Outputs for atomic SubSystem: '<S173>/If Action Subsystem3' */

      /* Switch: '<S212>/Switch1' incorporates:
       *  Constant: '<S212>/Constant1'
       *  Constant: '<S212>/Constant2'
       *  Constant: '<S212>/Constant3'
       *  Logic: '<S212>/Logical Operator1'
       *  RelationalOperator: '<S212>/Relational Operator'
       *  RelationalOperator: '<S212>/Relational Operator1'
       *  RelationalOperator: '<S212>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S173>/If Action Subsystem3' */

      /* DataTypeConversion: '<S161>/OutDTConv' incorporates:
       *  Constant: '<S161>/offset'
       *  Constant: '<S161>/offset1'
       *  Constant: '<S161>/one_on_slope'
       *  Product: '<S161>/Product4'
       *  Sum: '<S161>/Add1'
       *  Sum: '<S161>/Add2'
       */
      localtmp = (32768.0F * localAdd1_o1) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fu[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fu[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fu[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fu[3] = locallocalOutDTConv_idx;

      /* Lookup: '<S153>/Look-Up Table'
       * About '<S153>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_j[0]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_fu[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_j[1]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_fu[1], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_j[2]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_fu[2], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_j[3]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_fu[3], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S153>/Data Type Duplicate1'
       *
       * Regarding '<S153>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S190>/Divide' incorporates:
       *  DataTypeConversion: '<S50>/Data Type Conversion14'
       *  Lookup: '<S153>/Look-Up Table'
       */
      FuSysM_prm_mFuInjOvlpS1[0] = (((Float32)localLookUpTable_j[0]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Prev;
      FuSysM_prm_mFuInjOvlpS1[1] = (((Float32)localLookUpTable_j[1]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Prev;
      FuSysM_prm_mFuInjOvlpS1[2] = (((Float32)localLookUpTable_j[2]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1;
      FuSysM_prm_mFuInjOvlpS1[3] = (((Float32)localLookUpTable_j[3]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2;

      /* DataTypeConversion: '<S50>/Data Type Conversion10' incorporates:
       *  Constant: '<S50>/FuSysM_pFuMin_C'
       */
      localAdd1_nw = ((Float32)FuSysM_pFuMin_C) * 781.25F;

      /* MinMax: '<S50>/MinMax' */
      FuSysM_pFuEstimBegS1 = rt_MAXf(locallocalDataTypeConversion4_0,
        localAdd1_nw);

      /* Sum: '<S50>/Add7' incorporates:
       *  Constant: '<S50>/FuSysM_rMassPFuMeanEstim_C'
       *  DataTypeConversion: '<S50>/Data Type Conversion11'
       *  Product: '<S188>/Divide'
       *  Product: '<S189>/Divide'
       *  Sum: '<S50>/Add3'
       *  Sum: '<S50>/Add44'
       */
      locallocalDataTypeConversion4_0 = ((((localAdd19_e - FuSysM_mFuReqInjS1) -
        (((FuSysM_prm_mFuInjOvlpS1[0] + FuSysM_prm_mFuInjOvlpS1[1]) +
          FuSysM_prm_mFuInjOvlpS1[2]) + FuSysM_prm_mFuInjOvlpS1[3])) *
        (((Float32)FuSysM_rMassPFuMeanEstim_C) * 3.051757813E-005F)) *
        localDataTypeConversion7) + FuSysM_pFuEstimBegS1;

      /* DataTypeConversion: '<S162>/OutDTConv' incorporates:
       *  Constant: '<S162>/offset'
       *  Constant: '<S162>/offset1'
       *  Constant: '<S162>/one_on_slope'
       *  MinMax: '<S50>/MinMax57'
       *  Product: '<S162>/Product4'
       *  Sum: '<S162>/Add1'
       *  Sum: '<S162>/Add2'
       */
      localtmp = (1.279999968E-003F * rt_MAXf(locallocalDataTypeConversion4_0,
        localAdd1_nw)) + 0.5F;
      if (localtmp < 65536.0F) {
        pFuM_B.Merge1 = (UInt16)localtmp;
      } else {
        pFuM_B.Merge1 = MAX_uint16_T;
      }
    } else {
      /* DataTypeConversion: '<S231>/OutDTConv' incorporates:
       *  Constant: '<S231>/offset'
       *  Constant: '<S231>/offset1'
       *  Constant: '<S231>/one_on_slope'
       *  Product: '<S231>/Product4'
       *  Sum: '<S231>/Add1'
       *  Sum: '<S231>/Add2'
       */
      pFuM_B.Merge1 = (UInt16)((1.279999968E-003F * localDataTypeConversion8)
        + 0.5F);
    }

    /* If: '<S46>/If3' incorporates:
     *  ActionPort: '<S52>/Action Port'
     *  ActionPort: '<S53>/Action Port'
     *  Constant: '<S46>/Constant2'
     *  RelationalOperator: '<S46>/Relational Operator4'
     *  SubSystem: '<S46>/F05_PfuInjH2Clcn'
     *  SubSystem: '<S46>/F06_PfuInjH2NotClcn'
     */
    if (FuSysM_mFuReqInjH2 > 0.0F) {
      /* MinMax: '<S52>/MinMax3' */
      localAdd1_nw = rt_MINf(FuSysM_agEndInjH2Ref, localDataTypeConversion2);

      /* Sum: '<S52>/Add1' incorporates:
       *  MinMax: '<S52>/MinMax2'
       */
      localAdd19_e = rt_MAXf(localAdd1_nw, FuSysM_agBegInjH2Ref) -
        FuSysM_agBegInjH2Ref;

      /* Sum: '<S52>/Add10' */
      localAdd1_o1 = FuSysM_agEndInjH2RefPrev - FuSysM_agBegInjH2RefPrev;

      /* MinMax: '<S52>/MinMax78' */
      localAdd1_nw = rt_MINf(localDataTypeConversion1, FuSysM_agEndInjH2Ref);

      /* Product: '<S261>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax14'
       *  Sum: '<S52>/Add41'
       *  Sum: '<S52>/Add56'
       */
      localDivide_hb = (rt_MAXf(localDataTypeConversion9_g, localAdd1_nw) -
                        localDataTypeConversion9_g) / (localDataTypeConversion1
        - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S261>/If Action Subsystem3' */

      /* Switch: '<S310>/Switch1' incorporates:
       *  Constant: '<S310>/Constant1'
       *  Constant: '<S310>/Constant2'
       *  Constant: '<S310>/Constant3'
       *  Logic: '<S310>/Logical Operator1'
       *  RelationalOperator: '<S310>/Relational Operator'
       *  RelationalOperator: '<S310>/Relational Operator1'
       *  RelationalOperator: '<S310>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S261>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax1' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion9_g, FuSysM_agBegInjH2Ref);

      /* Product: '<S259>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax12'
       *  Sum: '<S52>/Add16'
       *  Sum: '<S52>/Add18'
       */
      localDivide_o3 = (rt_MINf(localDataTypeConversion1, localAdd1_nw) -
                        localDataTypeConversion9_g) / (localDataTypeConversion1
        - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S259>/If Action Subsystem3' */

      /* Switch: '<S306>/Switch1' incorporates:
       *  Constant: '<S306>/Constant1'
       *  Constant: '<S306>/Constant2'
       *  Constant: '<S306>/Constant3'
       *  Logic: '<S306>/Logical Operator1'
       *  RelationalOperator: '<S306>/Relational Operator'
       *  RelationalOperator: '<S306>/Relational Operator1'
       *  RelationalOperator: '<S306>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S259>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax9' */
      localAdd1_nw = rt_MINf(localDataTypeConversion3, FuSysM_agEndInjH2Ref);

      /* Product: '<S258>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax10'
       *  Sum: '<S52>/Add15'
       *  Sum: '<S52>/Add39'
       */
      localDataTypeConversion1_i = (rt_MAXf(localDataTypeConversion2,
        localAdd1_nw) - localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S258>/If Action Subsystem3' */

      /* Switch: '<S304>/Switch1' incorporates:
       *  Constant: '<S304>/Constant1'
       *  Constant: '<S304>/Constant2'
       *  Constant: '<S304>/Constant3'
       *  Logic: '<S304>/Logical Operator1'
       *  RelationalOperator: '<S304>/Relational Operator'
       *  RelationalOperator: '<S304>/Relational Operator1'
       *  RelationalOperator: '<S304>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S258>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax77' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion2, FuSysM_agBegInjH2Ref);

      /* Product: '<S257>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax79'
       *  Sum: '<S52>/Add17'
       *  Sum: '<S52>/Add6'
       */
      localAdd1_nw = (rt_MINf(localDataTypeConversion3, localAdd1_nw) -
                      localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S257>/If Action Subsystem3' */

      /* Switch: '<S302>/Switch1' incorporates:
       *  Constant: '<S302>/Constant1'
       *  Constant: '<S302>/Constant2'
       *  Constant: '<S302>/Constant3'
       *  Logic: '<S302>/Logical Operator1'
       *  RelationalOperator: '<S302>/Relational Operator'
       *  RelationalOperator: '<S302>/Relational Operator1'
       *  RelationalOperator: '<S302>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S257>/If Action Subsystem3' */

      /* DataTypeConversion: '<S239>/OutDTConv' incorporates:
       *  Constant: '<S239>/offset'
       *  Constant: '<S239>/offset1'
       *  Constant: '<S239>/one_on_slope'
       *  Product: '<S239>/Product4'
       *  Sum: '<S239>/Add1'
       *  Sum: '<S239>/Add2'
       */
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D[3] = locallocalOutDTConv_idx;

      /* Lookup2D: '<S237>/Look-Up Table (2-D)'
       * About '<S237>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localOutDTConv_e[0]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D[0], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_e[1]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D[1], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_e[2]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D[2], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_e[3]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D[3], (&(FuSysM_rAgPmp_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S237>/Data Type Duplicate2'
       *
       * Regarding '<S237>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S52>/DTConv_Single_To_UFix_3' */
      locallocalDataTypeConversion5_0 = ((Float32)localOutDTConv_e[0]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_i = ((Float32)localOutDTConv_e[1]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_2 = ((Float32)localOutDTConv_e[2]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_1 = ((Float32)localOutDTConv_e[3]) *
        3.051757813E-005F;

      /* MinMax: '<S52>/MinMax26' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion1, FuSysM_agBegInjH2Ref);

      /* Product: '<S255>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax16'
       *  Sum: '<S52>/Add26'
       *  Sum: '<S52>/Add27'
       */
      localDataTypeConversion1_i = (FuSysM_agEndInjH2Ref - rt_MINf
        (FuSysM_agEndInjH2Ref, localAdd1_nw)) / (FuSysM_agEndInjH2Ref -
        FuSysM_agBegInjH2Ref);

      /* Outputs for atomic SubSystem: '<S255>/If Action Subsystem3' */

      /* Switch: '<S298>/Switch1' incorporates:
       *  Constant: '<S298>/Constant1'
       *  Constant: '<S298>/Constant2'
       *  Constant: '<S298>/Constant3'
       *  Logic: '<S298>/Logical Operator1'
       *  RelationalOperator: '<S298>/Relational Operator'
       *  RelationalOperator: '<S298>/Relational Operator1'
       *  RelationalOperator: '<S298>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S255>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax13' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion3, FuSysM_agBegInjH2Ref);

      /* Product: '<S254>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax11'
       *  Sum: '<S52>/Add19'
       *  Sum: '<S52>/Add20'
       */
      localAdd1_nw = (FuSysM_agEndInjH2Ref - rt_MINf(FuSysM_agEndInjH2Ref,
        localAdd1_nw)) / (FuSysM_agEndInjH2Ref - FuSysM_agBegInjH2Ref);

      /* Outputs for atomic SubSystem: '<S254>/If Action Subsystem3' */

      /* Switch: '<S296>/Switch1' incorporates:
       *  Constant: '<S296>/Constant1'
       *  Constant: '<S296>/Constant2'
       *  Constant: '<S296>/Constant3'
       *  Logic: '<S296>/Logical Operator1'
       *  RelationalOperator: '<S296>/Relational Operator'
       *  RelationalOperator: '<S296>/Relational Operator1'
       *  RelationalOperator: '<S296>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S254>/If Action Subsystem3' */

      /* DataTypeConversion: '<S240>/OutDTConv' incorporates:
       *  Constant: '<S240>/offset'
       *  Constant: '<S240>/offset1'
       *  Constant: '<S240>/one_on_slope'
       *  Product: '<S240>/Product4'
       *  Sum: '<S240>/Add1'
       *  Sum: '<S240>/Add2'
       */
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_f[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_f[1] = locallocalOutDTConv_idx;

      /* Lookup: '<S235>/Look-Up Table'
       * About '<S235>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_f[0]), (&(FuSysM_facCorMassEndPmpStk_T
        [0])), localOutDTConv_f[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_f[1]), (&(FuSysM_facCorMassEndPmpStk_T
        [0])), localOutDTConv_f[1], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S235>/Data Type Duplicate1'
       *
       * Regarding '<S235>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S52>/Data Type Conversion1' incorporates:
       *  Lookup: '<S235>/Look-Up Table'
       */
      FuSysM_prm_fac1CorMassPmpInjH2[0] = ((Float32)localLookUpTable_f[0]) *
        3.051757813E-005F;
      FuSysM_prm_fac1CorMassPmpInjH2[1] = ((Float32)localLookUpTable_f[1]) *
        3.051757813E-005F;

      /* MinMax: '<S52>/MinMax7' */
      localAdd1_nw = rt_MINf(FuSysM_agEndInjH2Ref, localDataTypeConversion9_g);

      /* Product: '<S253>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax28'
       *  Sum: '<S52>/Add31'
       *  Sum: '<S52>/Add32'
       */
      localDataTypeConversion1_i = (rt_MAXf(localAdd1_nw, FuSysM_agBegInjH2Ref)
        - FuSysM_agBegInjH2Ref) / (FuSysM_agEndInjH2Ref - FuSysM_agBegInjH2Ref);

      /* Outputs for atomic SubSystem: '<S253>/If Action Subsystem3' */

      /* Switch: '<S294>/Switch1' incorporates:
       *  Constant: '<S294>/Constant1'
       *  Constant: '<S294>/Constant2'
       *  Constant: '<S294>/Constant3'
       *  Logic: '<S294>/Logical Operator1'
       *  RelationalOperator: '<S294>/Relational Operator'
       *  RelationalOperator: '<S294>/Relational Operator1'
       *  RelationalOperator: '<S294>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S253>/If Action Subsystem3' */

      /* Product: '<S252>/Divide' incorporates:
       *  Sum: '<S52>/Add23'
       */
      localAdd1_nw = localAdd19_e / (FuSysM_agEndInjH2Ref - FuSysM_agBegInjH2Ref);

      /* Outputs for atomic SubSystem: '<S252>/If Action Subsystem3' */

      /* Switch: '<S292>/Switch1' incorporates:
       *  Constant: '<S292>/Constant1'
       *  Constant: '<S292>/Constant2'
       *  Constant: '<S292>/Constant3'
       *  Logic: '<S292>/Logical Operator1'
       *  RelationalOperator: '<S292>/Relational Operator'
       *  RelationalOperator: '<S292>/Relational Operator1'
       *  RelationalOperator: '<S292>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S252>/If Action Subsystem3' */

      /* DataTypeConversion: '<S241>/OutDTConv' incorporates:
       *  Constant: '<S241>/offset'
       *  Constant: '<S241>/offset1'
       *  Constant: '<S241>/one_on_slope'
       *  Product: '<S241>/Product4'
       *  Sum: '<S241>/Add1'
       *  Sum: '<S241>/Add2'
       */
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_n[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_n[1] = locallocalOutDTConv_idx;

      /* Lookup: '<S234>/Look-Up Table'
       * About '<S234>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_o[0]), (&(FuSysM_facCorMassBegPmpStk_T
        [0])), localOutDTConv_n[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_o[1]), (&(FuSysM_facCorMassBegPmpStk_T
        [0])), localOutDTConv_n[1], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S234>/Data Type Duplicate1'
       *
       * Regarding '<S234>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S52>/Data Type Conversion2' incorporates:
       *  Lookup: '<S234>/Look-Up Table'
       */
      FuSysM_prm_fac2CorMassPmpInjH2[0] = ((Float32)localLookUpTable_o[0]) *
        3.051757813E-005F;
      FuSysM_prm_fac2CorMassPmpInjH2[1] = ((Float32)localLookUpTable_o[1]) *
        3.051757813E-005F;

      /* Product: '<S274>/Divide' incorporates:
       *  Constant: '<S52>/Constant'
       *  Product: '<S273>/Divide'
       *  Sum: '<S52>/Add12'
       *  Sum: '<S52>/Add30'
       *  Sum: '<S52>/Add40'
       */
      FuSysM_prm_mFuPmpOvlpH2[0] = ((locallocalDataTypeConversion5_0 -
        locallocalDataTypeConversion5_i) * localDataTypeConversion4) * ((1.0F +
        FuSysM_prm_fac1CorMassPmpInjH2[0]) - FuSysM_prm_fac2CorMassPmpInjH2[0]);
      FuSysM_prm_mFuPmpOvlpH2[1] = ((locallocalDataTypeConversion5_2 -
        locallocalDataTypeConversion5_1) * localDataTypeConversion5) * ((1.0F +
        FuSysM_prm_fac1CorMassPmpInjH2[1]) - FuSysM_prm_fac2CorMassPmpInjH2[1]);

      /* Sum: '<S52>/Add11' */
      localAdd30_mn = FuSysM_prm_mFuPmpOvlpH2[0] + FuSysM_prm_mFuPmpOvlpH2[1];

      /* MinMax: '<S52>/MinMax17' */
      localDivide_o3 = rt_MAXf(FuSysM_agBegInjH2Ref, FuSysM_agEndInjS1Ref);

      /* MinMax: '<S52>/MinMax18' */
      localDivide_hb = rt_MAXf(FuSysM_agBegInjS1Ref, FuSysM_agBegInjH2Ref);

      /* MinMax: '<S52>/MinMax20' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH2Ref, FuSysM_agEndInjH1RefPrev);

      /* MinMax: '<S52>/MinMax21' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefPrev,
        FuSysM_agBegInjH2Ref);

      /* Product: '<S251>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax22'
       *  MinMax: '<S52>/MinMax24'
       *  Sum: '<S52>/Add7'
       *  Sum: '<S52>/Add8'
       */
      locallocalDataTypeConversion4_0 = (rt_MINf(localAdd1_nw,
        FuSysM_agEndInjH2Ref) - rt_MINf(FuSysM_agEndInjH2Ref,
        localDataTypeConversion1_i)) / (FuSysM_agEndInjH1RefPrev -
        FuSysM_agBegInjH1RefPrev);

      /* Outputs for atomic SubSystem: '<S251>/If Action Subsystem3' */

      /* Switch: '<S290>/Switch1' incorporates:
       *  Constant: '<S290>/Constant1'
       *  Constant: '<S290>/Constant2'
       *  Constant: '<S290>/Constant3'
       *  Logic: '<S290>/Logical Operator1'
       *  RelationalOperator: '<S290>/Relational Operator'
       *  RelationalOperator: '<S290>/Relational Operator1'
       *  RelationalOperator: '<S290>/Relational Operator3'
       */
      if (((locallocalDataTypeConversion4_0 != locallocalDataTypeConversion4_0) ||
           (locallocalDataTypeConversion4_0 > 3.000000005E+038F)) ||
          (-3.000000005E+038F > locallocalDataTypeConversion4_0)) {
        locallocalDataTypeConversion4_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S251>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax23' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH2Ref, FuSysM_agEndInjH2RefPrev);

      /* MinMax: '<S52>/MinMax29' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefPrev,
        FuSysM_agBegInjH2Ref);

      /* Product: '<S250>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax19'
       *  MinMax: '<S52>/MinMax32'
       *  Sum: '<S52>/Add9'
       */
      localAdd1_o1 = (rt_MINf(localAdd1_nw, FuSysM_agEndInjH2Ref) - rt_MINf
                      (FuSysM_agEndInjH2Ref, localDataTypeConversion1_i)) /
        localAdd1_o1;

      /* Outputs for atomic SubSystem: '<S250>/If Action Subsystem3' */

      /* Switch: '<S288>/Switch1' incorporates:
       *  Constant: '<S288>/Constant1'
       *  Constant: '<S288>/Constant2'
       *  Constant: '<S288>/Constant3'
       *  Logic: '<S288>/Logical Operator1'
       *  RelationalOperator: '<S288>/Relational Operator'
       *  RelationalOperator: '<S288>/Relational Operator1'
       *  RelationalOperator: '<S288>/Relational Operator3'
       */
      if (((localAdd1_o1 != localAdd1_o1) || (localAdd1_o1 > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_o1)) {
        localAdd1_o1 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S250>/If Action Subsystem3' */

      /* Product: '<S249>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax31'
       *  MinMax: '<S52>/MinMax5'
       *  Sum: '<S52>/Add13'
       *  Sum: '<S52>/Add14'
       */
      localAdd19_e = (rt_MINf(localDivide_o3, FuSysM_agEndInjH2Ref) - rt_MINf
                      (FuSysM_agEndInjH2Ref, localDivide_hb)) /
        (FuSysM_agEndInjS1Ref - FuSysM_agBegInjS1Ref);

      /* Outputs for atomic SubSystem: '<S249>/If Action Subsystem3' */

      /* Switch: '<S286>/Switch1' incorporates:
       *  Constant: '<S286>/Constant1'
       *  Constant: '<S286>/Constant2'
       *  Constant: '<S286>/Constant3'
       *  Logic: '<S286>/Logical Operator1'
       *  RelationalOperator: '<S286>/Relational Operator'
       *  RelationalOperator: '<S286>/Relational Operator1'
       *  RelationalOperator: '<S286>/Relational Operator3'
       */
      if (((localAdd19_e != localAdd19_e) || (localAdd19_e > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd19_e)) {
        localAdd19_e = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S249>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax4' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH2Ref, FuSysM_agEndInjS2Ref);

      /* MinMax: '<S52>/MinMax6' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjS2Ref,
        FuSysM_agBegInjH2Ref);

      /* Product: '<S248>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax15'
       *  MinMax: '<S52>/MinMax8'
       *  Sum: '<S52>/Add3'
       *  Sum: '<S52>/Add5'
       */
      localDivide_hb = (rt_MINf(localAdd1_nw, FuSysM_agEndInjH2Ref) - rt_MINf
                        (FuSysM_agEndInjH2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjS2Ref - FuSysM_agBegInjS2Ref);

      /* Outputs for atomic SubSystem: '<S248>/If Action Subsystem3' */

      /* Switch: '<S284>/Switch1' incorporates:
       *  Constant: '<S284>/Constant1'
       *  Constant: '<S284>/Constant2'
       *  Constant: '<S284>/Constant3'
       *  Logic: '<S284>/Logical Operator1'
       *  RelationalOperator: '<S284>/Relational Operator'
       *  RelationalOperator: '<S284>/Relational Operator1'
       *  RelationalOperator: '<S284>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S248>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax66' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH2Ref, FuSysM_agEndInjH1RefNxt);

      /* MinMax: '<S52>/MinMax67' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefNxt,
        FuSysM_agBegInjH2Ref);

      /* Product: '<S246>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax68'
       *  MinMax: '<S52>/MinMax70'
       *  Sum: '<S52>/Add21'
       *  Sum: '<S52>/Add22'
       */
      localDivide_o3 = (rt_MINf(localAdd1_nw, FuSysM_agEndInjH2Ref) - rt_MINf
                        (FuSysM_agEndInjH2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH1RefNxt - FuSysM_agBegInjH1RefNxt);

      /* Outputs for atomic SubSystem: '<S246>/If Action Subsystem3' */

      /* Switch: '<S280>/Switch1' incorporates:
       *  Constant: '<S280>/Constant1'
       *  Constant: '<S280>/Constant2'
       *  Constant: '<S280>/Constant3'
       *  Logic: '<S280>/Logical Operator1'
       *  RelationalOperator: '<S280>/Relational Operator'
       *  RelationalOperator: '<S280>/Relational Operator1'
       *  RelationalOperator: '<S280>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S246>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax69' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH2Ref, FuSysM_agEndInjH2RefNxt);

      /* MinMax: '<S52>/MinMax71' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefNxt,
        FuSysM_agBegInjH2Ref);

      /* Product: '<S247>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax65'
       *  MinMax: '<S52>/MinMax72'
       *  Sum: '<S52>/Add24'
       *  Sum: '<S52>/Add25'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, FuSysM_agEndInjH2Ref) - rt_MINf
                      (FuSysM_agEndInjH2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefNxt - FuSysM_agBegInjH2RefNxt);

      /* Outputs for atomic SubSystem: '<S247>/If Action Subsystem3' */

      /* Switch: '<S282>/Switch1' incorporates:
       *  Constant: '<S282>/Constant1'
       *  Constant: '<S282>/Constant2'
       *  Constant: '<S282>/Constant3'
       *  Logic: '<S282>/Logical Operator1'
       *  RelationalOperator: '<S282>/Relational Operator'
       *  RelationalOperator: '<S282>/Relational Operator1'
       *  RelationalOperator: '<S282>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S247>/If Action Subsystem3' */

      /* DataTypeConversion: '<S242>/OutDTConv' incorporates:
       *  Constant: '<S242>/offset'
       *  Constant: '<S242>/offset1'
       *  Constant: '<S242>/one_on_slope'
       *  Product: '<S242>/Product4'
       *  Sum: '<S242>/Add1'
       *  Sum: '<S242>/Add2'
       */
      localtmp = (32768.0F * locallocalDataTypeConversion4_0) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lx[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_o1) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lx[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd19_e) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lx[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lx[3] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lx[4] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_lx[5] = locallocalOutDTConv_idx;

      /* Lookup: '<S233>/Look-Up Table'
       * About '<S233>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      {
        SInt32 i1;
        const UInt16 *u0 = localOutDTConv_lx;
        UInt16 *y0 = localLookUpTable_as;
        for (i1=0; i1 < 6; i1++) {
          LookUp_U16_U16( &(y0[i1]), (&(FuSysM_rMassInj_T[0])), u0[i1],
                         (&(FuSysM_rAgInj_A[0])), 8U);
        }
      }

      /* DataTypeDuplicate Block: '<S233>/Data Type Duplicate1'
       *
       * Regarding '<S233>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S272>/Divide' */
      FuSysM_prm_mFuInjOvlpH2[0] = (((Float32)localLookUpTable_as[0]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Prev;
      FuSysM_prm_mFuInjOvlpH2[1] = (((Float32)localLookUpTable_as[1]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Prev;
      FuSysM_prm_mFuInjOvlpH2[2] = (((Float32)localLookUpTable_as[2]) *
        3.051757813E-005F) * FuSysM_mFuReqInjS1;
      FuSysM_prm_mFuInjOvlpH2[3] = (((Float32)localLookUpTable_as[3]) *
        3.051757813E-005F) * FuSysM_mFuReqInjS2;
      FuSysM_prm_mFuInjOvlpH2[4] = (((Float32)localLookUpTable_as[4]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Nxt;
      FuSysM_prm_mFuInjOvlpH2[5] = (((Float32)localLookUpTable_as[5]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Nxt;

      /* Product: '<S275>/Divide' incorporates:
       *  Constant: '<S52>/FuSysM_rMassPFuMeanEstim_C'
       *  DataTypeConversion: '<S52>/Data Type Conversion12'
       *  Sum: '<S52>/Add4'
       *  Sum: '<S52>/Add44'
       */
      localmin_0 = ((localAdd30_mn - FuSysM_mFuReqInjH2) -
                    (((((FuSysM_prm_mFuInjOvlpH2[0] + FuSysM_prm_mFuInjOvlpH2[1])
                        + FuSysM_prm_mFuInjOvlpH2[2]) + FuSysM_prm_mFuInjOvlpH2
                       [3]) + FuSysM_prm_mFuInjOvlpH2[4]) +
                     FuSysM_prm_mFuInjOvlpH2[5])) * (((Float32)
        FuSysM_rMassPFuMeanEstim_C) * 3.051757813E-005F);

      /* Product: '<S260>/Divide' incorporates:
       *  Constant: '<S52>/Constant22'
       *  Constant: '<S52>/Constant34'
       *  MinMax: '<S52>/MinMax38'
       *  MinMax: '<S52>/MinMax40'
       *  Sum: '<S52>/Add28'
       *  Sum: '<S52>/Add38'
       */
      localDivide_o3 = (rt_MINf(0.0F, localDataTypeConversion1) - rt_MINf
                        (localDataTypeConversion9_g, 0.0F)) /
        (localDataTypeConversion1 - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S260>/If Action Subsystem3' */

      /* Switch: '<S308>/Switch1' incorporates:
       *  Constant: '<S308>/Constant1'
       *  Constant: '<S308>/Constant2'
       *  Constant: '<S308>/Constant3'
       *  Logic: '<S308>/Logical Operator1'
       *  RelationalOperator: '<S308>/Relational Operator'
       *  RelationalOperator: '<S308>/Relational Operator1'
       *  RelationalOperator: '<S308>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S260>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax34' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion9_g, FuSysM_agBegInjH2Ref);

      /* Product: '<S245>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax46'
       *  Sum: '<S52>/Add29'
       *  Sum: '<S52>/Add35'
       */
      localDataTypeConversion1_i = (rt_MINf(localAdd1_nw,
        localDataTypeConversion1) - localDataTypeConversion9_g) /
        (localDataTypeConversion1 - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S245>/If Action Subsystem3' */

      /* Switch: '<S278>/Switch1' incorporates:
       *  Constant: '<S278>/Constant1'
       *  Constant: '<S278>/Constant2'
       *  Constant: '<S278>/Constant3'
       *  Logic: '<S278>/Logical Operator1'
       *  RelationalOperator: '<S278>/Relational Operator'
       *  RelationalOperator: '<S278>/Relational Operator1'
       *  RelationalOperator: '<S278>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S245>/If Action Subsystem3' */

      /* Product: '<S256>/Divide' incorporates:
       *  Constant: '<S52>/Constant15'
       *  Constant: '<S52>/Constant38'
       *  MinMax: '<S52>/MinMax36'
       *  MinMax: '<S52>/MinMax37'
       *  Sum: '<S52>/Add34'
       *  Sum: '<S52>/Add54'
       */
      localDivide_hb = (rt_MINf(0.0F, localDataTypeConversion3) - rt_MINf
                        (localDataTypeConversion2, 0.0F)) /
        (localDataTypeConversion3 - localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S256>/If Action Subsystem3' */

      /* Switch: '<S300>/Switch1' incorporates:
       *  Constant: '<S300>/Constant1'
       *  Constant: '<S300>/Constant2'
       *  Constant: '<S300>/Constant3'
       *  Logic: '<S300>/Logical Operator1'
       *  RelationalOperator: '<S300>/Relational Operator'
       *  RelationalOperator: '<S300>/Relational Operator1'
       *  RelationalOperator: '<S300>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S256>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax35' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion2, FuSysM_agBegInjH2Ref);

      /* Product: '<S262>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax39'
       *  Sum: '<S52>/Add36'
       *  Sum: '<S52>/Add37'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, localDataTypeConversion3) -
                      localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S262>/If Action Subsystem3' */

      /* Switch: '<S312>/Switch1' incorporates:
       *  Constant: '<S312>/Constant1'
       *  Constant: '<S312>/Constant2'
       *  Constant: '<S312>/Constant3'
       *  Logic: '<S312>/Logical Operator1'
       *  RelationalOperator: '<S312>/Relational Operator'
       *  RelationalOperator: '<S312>/Relational Operator1'
       *  RelationalOperator: '<S312>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S262>/If Action Subsystem3' */

      /* DataTypeConversion: '<S243>/OutDTConv' incorporates:
       *  Constant: '<S243>/offset'
       *  Constant: '<S243>/offset1'
       *  Constant: '<S243>/one_on_slope'
       *  Product: '<S243>/Product4'
       *  Sum: '<S243>/Add1'
       *  Sum: '<S243>/Add2'
       */
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_e[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_e[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_e[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_e[3] = locallocalOutDTConv_idx;

      /* Lookup2D: '<S236>/Look-Up Table (2-D)'
       * About '<S236>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D[0]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_e[0], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D[1]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_e[1], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D[2]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_e[2], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D[3]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_e[3], (&(FuSysM_rAgPmp_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S236>/Data Type Duplicate2'
       *
       * Regarding '<S236>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Product: '<S269>/Divide' incorporates:
       *  DataTypeConversion: '<S52>/Data Type Conversion6'
       *  Sum: '<S52>/Add33'
       *  Sum: '<S52>/Add55'
       */
      FuSysM_prm_mFuPmpBegH2[0] = ((((Float32)localLookUpTable2D[1]) *
        3.051757813E-005F) - (((Float32)localLookUpTable2D[0]) *
        3.051757813E-005F)) * localDataTypeConversion4;
      FuSysM_prm_mFuPmpBegH2[1] = ((((Float32)localLookUpTable2D[3]) *
        3.051757813E-005F) - (((Float32)localLookUpTable2D[2]) *
        3.051757813E-005F)) * localDataTypeConversion5;

      /* Sum: '<S52>/Add45' */
      localAdd30_mn = FuSysM_prm_mFuPmpBegH2[0] + FuSysM_prm_mFuPmpBegH2[1];

      /* MinMax: '<S52>/MinMax73' incorporates:
       *  Constant: '<S52>/Constant53'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH1RefPrev);

      /* MinMax: '<S52>/MinMax75' incorporates:
       *  Constant: '<S52>/Constant1'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefPrev, 0.0F);

      /* Product: '<S263>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax76'
       *  MinMax: '<S52>/MinMax95'
       *  Sum: '<S52>/Add63'
       *  Sum: '<S52>/Add64'
       */
      locallocalDataTypeConversion4_0 = (rt_MINf(localAdd1_nw,
        FuSysM_agBegInjH2Ref) - rt_MINf(FuSysM_agBegInjH2Ref,
        localDataTypeConversion1_i)) / (FuSysM_agEndInjH1RefPrev -
        FuSysM_agBegInjH1RefPrev);

      /* Outputs for atomic SubSystem: '<S263>/If Action Subsystem3' */

      /* Switch: '<S314>/Switch1' incorporates:
       *  Constant: '<S314>/Constant1'
       *  Constant: '<S314>/Constant2'
       *  Constant: '<S314>/Constant3'
       *  Logic: '<S314>/Logical Operator1'
       *  RelationalOperator: '<S314>/Relational Operator'
       *  RelationalOperator: '<S314>/Relational Operator1'
       *  RelationalOperator: '<S314>/Relational Operator3'
       */
      if (((locallocalDataTypeConversion4_0 != locallocalDataTypeConversion4_0) ||
           (locallocalDataTypeConversion4_0 > 3.000000005E+038F)) ||
          (-3.000000005E+038F > locallocalDataTypeConversion4_0)) {
        locallocalDataTypeConversion4_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S263>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax84' incorporates:
       *  Constant: '<S52>/Constant2'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH2RefPrev);

      /* MinMax: '<S52>/MinMax92' incorporates:
       *  Constant: '<S52>/Constant3'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefPrev, 0.0F);

      /* Product: '<S264>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax74'
       *  MinMax: '<S52>/MinMax96'
       *  Sum: '<S52>/Add57'
       *  Sum: '<S52>/Add58'
       */
      localAdd1_o1 = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH2Ref) - rt_MINf
                      (FuSysM_agBegInjH2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefPrev - FuSysM_agBegInjH2RefPrev);

      /* Outputs for atomic SubSystem: '<S264>/If Action Subsystem3' */

      /* Switch: '<S316>/Switch1' incorporates:
       *  Constant: '<S316>/Constant1'
       *  Constant: '<S316>/Constant2'
       *  Constant: '<S316>/Constant3'
       *  Logic: '<S316>/Logical Operator1'
       *  RelationalOperator: '<S316>/Relational Operator'
       *  RelationalOperator: '<S316>/Relational Operator1'
       *  RelationalOperator: '<S316>/Relational Operator3'
       */
      if (((localAdd1_o1 != localAdd1_o1) || (localAdd1_o1 > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_o1)) {
        localAdd1_o1 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S264>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax80' incorporates:
       *  Constant: '<S52>/Constant4'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjS1Ref);

      /* MinMax: '<S52>/MinMax81' incorporates:
       *  Constant: '<S52>/Constant5'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjS1Ref, 0.0F);

      /* Product: '<S265>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax82'
       *  MinMax: '<S52>/MinMax83'
       *  Sum: '<S52>/Add51'
       *  Sum: '<S52>/Add62'
       */
      localAdd19_e = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH2Ref) - rt_MINf
                      (FuSysM_agBegInjH2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjS1Ref - FuSysM_agBegInjS1Ref);

      /* Outputs for atomic SubSystem: '<S265>/If Action Subsystem3' */

      /* Switch: '<S318>/Switch1' incorporates:
       *  Constant: '<S318>/Constant1'
       *  Constant: '<S318>/Constant2'
       *  Constant: '<S318>/Constant3'
       *  Logic: '<S318>/Logical Operator1'
       *  RelationalOperator: '<S318>/Relational Operator'
       *  RelationalOperator: '<S318>/Relational Operator1'
       *  RelationalOperator: '<S318>/Relational Operator3'
       */
      if (((localAdd19_e != localAdd19_e) || (localAdd19_e > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd19_e)) {
        localAdd19_e = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S265>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax89' incorporates:
       *  Constant: '<S52>/Constant6'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjS2Ref);

      /* MinMax: '<S52>/MinMax90' incorporates:
       *  Constant: '<S52>/Constant7'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjS2Ref, 0.0F);

      /* Product: '<S266>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax91'
       *  MinMax: '<S52>/MinMax93'
       *  Sum: '<S52>/Add59'
       *  Sum: '<S52>/Add60'
       */
      localDivide_hb = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH2Ref) - rt_MINf
                        (FuSysM_agBegInjH2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjS2Ref - FuSysM_agBegInjS2Ref);

      /* Outputs for atomic SubSystem: '<S266>/If Action Subsystem3' */

      /* Switch: '<S320>/Switch1' incorporates:
       *  Constant: '<S320>/Constant1'
       *  Constant: '<S320>/Constant2'
       *  Constant: '<S320>/Constant3'
       *  Logic: '<S320>/Logical Operator1'
       *  RelationalOperator: '<S320>/Relational Operator'
       *  RelationalOperator: '<S320>/Relational Operator1'
       *  RelationalOperator: '<S320>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S266>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax57' incorporates:
       *  Constant: '<S52>/Constant8'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH1RefNxt);

      /* MinMax: '<S52>/MinMax59' incorporates:
       *  Constant: '<S52>/Constant9'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefNxt, 0.0F);

      /* Product: '<S267>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax60'
       *  MinMax: '<S52>/MinMax63'
       *  Sum: '<S52>/Add48'
       *  Sum: '<S52>/Add49'
       */
      localDivide_o3 = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH2Ref) - rt_MINf
                        (FuSysM_agBegInjH2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH1RefNxt - FuSysM_agBegInjH1RefNxt);

      /* Outputs for atomic SubSystem: '<S267>/If Action Subsystem3' */

      /* Switch: '<S322>/Switch1' incorporates:
       *  Constant: '<S322>/Constant1'
       *  Constant: '<S322>/Constant2'
       *  Constant: '<S322>/Constant3'
       *  Logic: '<S322>/Logical Operator1'
       *  RelationalOperator: '<S322>/Relational Operator'
       *  RelationalOperator: '<S322>/Relational Operator1'
       *  RelationalOperator: '<S322>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S267>/If Action Subsystem3' */

      /* MinMax: '<S52>/MinMax61' incorporates:
       *  Constant: '<S52>/Constant10'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH2RefNxt);

      /* MinMax: '<S52>/MinMax62' incorporates:
       *  Constant: '<S52>/Constant11'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefNxt, 0.0F);

      /* Product: '<S268>/Divide' incorporates:
       *  MinMax: '<S52>/MinMax58'
       *  MinMax: '<S52>/MinMax64'
       *  Sum: '<S52>/Add46'
       *  Sum: '<S52>/Add47'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, FuSysM_agBegInjH2Ref) - rt_MINf
                      (FuSysM_agBegInjH2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefNxt - FuSysM_agBegInjH2RefNxt);

      /* Outputs for atomic SubSystem: '<S268>/If Action Subsystem3' */

      /* Switch: '<S324>/Switch1' incorporates:
       *  Constant: '<S324>/Constant1'
       *  Constant: '<S324>/Constant2'
       *  Constant: '<S324>/Constant3'
       *  Logic: '<S324>/Logical Operator1'
       *  RelationalOperator: '<S324>/Relational Operator'
       *  RelationalOperator: '<S324>/Relational Operator1'
       *  RelationalOperator: '<S324>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S268>/If Action Subsystem3' */

      /* DataTypeConversion: '<S238>/OutDTConv' incorporates:
       *  Constant: '<S238>/offset'
       *  Constant: '<S238>/offset1'
       *  Constant: '<S238>/one_on_slope'
       *  Product: '<S238>/Product4'
       *  Sum: '<S238>/Add1'
       *  Sum: '<S238>/Add2'
       */
      localtmp = (32768.0F * locallocalDataTypeConversion4_0) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_l[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_o1) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_l[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd19_e) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_l[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_l[3] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_l[4] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_l[5] = locallocalOutDTConv_idx;

      /* Lookup: '<S232>/Look-Up Table'
       * About '<S232>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      {
        SInt32 i1;
        const UInt16 *u0 = localOutDTConv_l;
        UInt16 *y0 = localLookUpTable_k;
        for (i1=0; i1 < 6; i1++) {
          LookUp_U16_U16( &(y0[i1]), (&(FuSysM_rMassInj_T[0])), u0[i1],
                         (&(FuSysM_rAgInj_A[0])), 8U);
        }
      }

      /* DataTypeDuplicate Block: '<S232>/Data Type Duplicate1'
       *
       * Regarding '<S232>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S271>/Divide' incorporates:
       *  DataTypeConversion: '<S52>/Data Type Conversion4'
       *  Lookup: '<S232>/Look-Up Table'
       */
      FuSysM_prm_mFuInjBegH2[0] = (((Float32)localLookUpTable_k[0]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Prev;
      FuSysM_prm_mFuInjBegH2[1] = (((Float32)localLookUpTable_k[1]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Prev;
      FuSysM_prm_mFuInjBegH2[2] = (((Float32)localLookUpTable_k[2]) *
        3.051757813E-005F) * FuSysM_mFuReqInjS1;
      FuSysM_prm_mFuInjBegH2[3] = (((Float32)localLookUpTable_k[3]) *
        3.051757813E-005F) * FuSysM_mFuReqInjS2;
      FuSysM_prm_mFuInjBegH2[4] = (((Float32)localLookUpTable_k[4]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Nxt;
      FuSysM_prm_mFuInjBegH2[5] = (((Float32)localLookUpTable_k[5]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Nxt;

      /* Sum: '<S52>/Add61' incorporates:
       *  Product: '<S270>/Divide'
       *  Sum: '<S52>/Add43'
       *  Sum: '<S52>/Add65'
       */
      localAdd1_nw = (((localAdd30_mn - FuSysM_mFuReqInjH1) -
                       (((((FuSysM_prm_mFuInjBegH2[0] + FuSysM_prm_mFuInjBegH2[1])
                           + FuSysM_prm_mFuInjBegH2[2]) +
                          FuSysM_prm_mFuInjBegH2[3]) + FuSysM_prm_mFuInjBegH2[4])
                        + FuSysM_prm_mFuInjBegH2[5])) * localDataTypeConversion7)
        + localDataTypeConversion8;

      /* DataTypeConversion: '<S52>/Data Type Conversion7' incorporates:
       *  Constant: '<S52>/FuSysM_pFuMin_C'
       */
      localDataTypeConversion1_i = ((Float32)FuSysM_pFuMin_C) * 781.25F;

      /* MinMax: '<S52>/MinMax' */
      FuSysM_pFuEstimBegH2 = rt_MAXf(localAdd1_nw, localDataTypeConversion1_i);

      /* Sum: '<S52>/Add2' incorporates:
       *  Product: '<S276>/Divide'
       */
      localAdd1_nw = (localDataTypeConversion7 * localmin_0) +
        FuSysM_pFuEstimBegH2;

      /* DataTypeConversion: '<S244>/OutDTConv' incorporates:
       *  Constant: '<S244>/offset'
       *  Constant: '<S244>/offset1'
       *  Constant: '<S244>/one_on_slope'
       *  MinMax: '<S52>/MinMax33'
       *  Product: '<S244>/Product4'
       *  Sum: '<S244>/Add1'
       *  Sum: '<S244>/Add2'
       */
      localtmp = (1.279999968E-003F * rt_MAXf(localAdd1_nw,
        localDataTypeConversion1_i)) + 0.5F;
      if (localtmp < 65536.0F) {
        pFuM_B.Merge2 = (UInt16)localtmp;
      } else {
        pFuM_B.Merge2 = MAX_uint16_T;
      }
    } else {
      /* DataTypeConversion: '<S325>/OutDTConv' incorporates:
       *  Constant: '<S325>/offset'
       *  Constant: '<S325>/offset1'
       *  Constant: '<S325>/one_on_slope'
       *  Product: '<S325>/Product4'
       *  Sum: '<S325>/Add1'
       *  Sum: '<S325>/Add2'
       */
      pFuM_B.Merge2 = (UInt16)((1.279999968E-003F * localDataTypeConversion8)
        + 0.5F);
    }

    /* If: '<S46>/If2' incorporates:
     *  ActionPort: '<S54>/Action Port'
     *  ActionPort: '<S55>/Action Port'
     *  Constant: '<S46>/Constant1'
     *  RelationalOperator: '<S46>/Relational Operator2'
     *  SubSystem: '<S46>/F07_PfuInjS2Clcn'
     *  SubSystem: '<S46>/F08_PfuInjS2NotClcn'
     */
    if (FuSysM_mFuReqInjS2 > 0.0F) {
      /* MinMax: '<S54>/MinMax3' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS2Ref, FuSysM_agEndInjH1Ref);

      /* MinMax: '<S54>/MinMax6' */
      locallocalDataTypeConversion4_1 = rt_MINf(localAdd1_nw,
        FuSysM_agEndInjS2Ref);

      /* MinMax: '<S54>/MinMax4' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1Ref, FuSysM_agBegInjS2Ref);

      /* MinMax: '<S54>/MinMax8' */
      locallocalDataTypeConversion4_2 = rt_MINf(FuSysM_agEndInjS2Ref,
        localAdd1_nw);

      /* Sum: '<S54>/Add10' */
      locallocalDataTypeConversion4_l = FuSysM_agEndInjS2Ref -
        FuSysM_agBegInjS2Ref;

      /* MinMax: '<S54>/MinMax24' */
      localAdd1_nw = rt_MINf(FuSysM_agEndInjS2Ref, localDataTypeConversion9_g);

      /* Sum: '<S54>/Add11' incorporates:
       *  MinMax: '<S54>/MinMax23'
       */
      localAdd12_e = rt_MAXf(localAdd1_nw, FuSysM_agBegInjS2Ref) -
        FuSysM_agBegInjS2Ref;

      /* Sum: '<S54>/Add12' */
      localAdd12 = FuSysM_agEndInjH2Ref - FuSysM_agBegInjH2Ref;

      /* Product: '<S351>/Divide' incorporates:
       *  Constant: '<S54>/Constant22'
       *  Constant: '<S54>/Constant8'
       *  MinMax: '<S54>/MinMax38'
       *  MinMax: '<S54>/MinMax42'
       *  Sum: '<S54>/Add17'
       *  Sum: '<S54>/Add41'
       */
      localDivide_hb = (rt_MINf(0.0F, localDataTypeConversion1) - rt_MINf
                        (localDataTypeConversion9_g, 0.0F)) /
        (localDataTypeConversion1 - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S351>/If Action Subsystem3' */

      /* Switch: '<S392>/Switch1' incorporates:
       *  Constant: '<S392>/Constant1'
       *  Constant: '<S392>/Constant2'
       *  Constant: '<S392>/Constant3'
       *  Logic: '<S392>/Logical Operator1'
       *  RelationalOperator: '<S392>/Relational Operator'
       *  RelationalOperator: '<S392>/Relational Operator1'
       *  RelationalOperator: '<S392>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S351>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax28' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion9_g, FuSysM_agBegInjS2Ref);

      /* Product: '<S339>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax41'
       *  Sum: '<S54>/Add18'
       *  Sum: '<S54>/Add32'
       */
      localDataTypeConversion1_i = (rt_MINf(localAdd1_nw,
        localDataTypeConversion1) - localDataTypeConversion9_g) /
        (localDataTypeConversion1 - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S339>/If Action Subsystem3' */

      /* Switch: '<S368>/Switch1' incorporates:
       *  Constant: '<S368>/Constant1'
       *  Constant: '<S368>/Constant2'
       *  Constant: '<S368>/Constant3'
       *  Logic: '<S368>/Logical Operator1'
       *  RelationalOperator: '<S368>/Relational Operator'
       *  RelationalOperator: '<S368>/Relational Operator1'
       *  RelationalOperator: '<S368>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S339>/If Action Subsystem3' */

      /* Product: '<S350>/Divide' incorporates:
       *  Constant: '<S54>/Constant38'
       *  Constant: '<S54>/Constant9'
       *  MinMax: '<S54>/MinMax30'
       *  MinMax: '<S54>/MinMax39'
       *  Sum: '<S54>/Add19'
       *  Sum: '<S54>/Add54'
       */
      localDivide_o3 = (rt_MINf(0.0F, localDataTypeConversion3) - rt_MINf
                        (localDataTypeConversion2, 0.0F)) /
        (localDataTypeConversion3 - localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S350>/If Action Subsystem3' */

      /* Switch: '<S390>/Switch1' incorporates:
       *  Constant: '<S390>/Constant1'
       *  Constant: '<S390>/Constant2'
       *  Constant: '<S390>/Constant3'
       *  Logic: '<S390>/Logical Operator1'
       *  RelationalOperator: '<S390>/Relational Operator'
       *  RelationalOperator: '<S390>/Relational Operator1'
       *  RelationalOperator: '<S390>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S350>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax29' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion2, FuSysM_agBegInjS2Ref);

      /* Product: '<S352>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax31'
       *  Sum: '<S54>/Add31'
       *  Sum: '<S54>/Add40'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, localDataTypeConversion3) -
                      localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S352>/If Action Subsystem3' */

      /* Switch: '<S394>/Switch1' incorporates:
       *  Constant: '<S394>/Constant1'
       *  Constant: '<S394>/Constant2'
       *  Constant: '<S394>/Constant3'
       *  Logic: '<S394>/Logical Operator1'
       *  RelationalOperator: '<S394>/Relational Operator'
       *  RelationalOperator: '<S394>/Relational Operator1'
       *  RelationalOperator: '<S394>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S352>/If Action Subsystem3' */

      /* DataTypeConversion: '<S333>/OutDTConv' incorporates:
       *  Constant: '<S333>/offset'
       *  Constant: '<S333>/offset1'
       *  Constant: '<S333>/one_on_slope'
       *  Product: '<S333>/Product4'
       *  Sum: '<S333>/Add1'
       *  Sum: '<S333>/Add2'
       */
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_n[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_n[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_n[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localLookUpTable2D_n[3] = locallocalOutDTConv_idx;

      /* Lookup2D: '<S330>/Look-Up Table (2-D)'
       * About '<S330>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localOutDTConv_d[0]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_n[0], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_d[1]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_n[1], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_d[2]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_n[2], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localOutDTConv_d[3]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localLookUpTable2D_n[3], (&(FuSysM_rAgPmp_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S330>/Data Type Duplicate2'
       *
       * Regarding '<S330>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Product: '<S359>/Divide' incorporates:
       *  DataTypeConversion: '<S54>/Data Type Conversion4'
       *  Sum: '<S54>/Add16'
       *  Sum: '<S54>/Add55'
       */
      FuSysM_prm_mFuPmpBegS2[0] = ((((Float32)localOutDTConv_d[1]) *
        3.051757813E-005F) - (((Float32)localOutDTConv_d[0]) *
        3.051757813E-005F)) * localDataTypeConversion4;
      FuSysM_prm_mFuPmpBegS2[1] = ((((Float32)localOutDTConv_d[3]) *
        3.051757813E-005F) - (((Float32)localOutDTConv_d[2]) *
        3.051757813E-005F)) * localDataTypeConversion5;

      /* Sum: '<S54>/Add30' */
      localAdd1_o1 = FuSysM_prm_mFuPmpBegS2[0] + FuSysM_prm_mFuPmpBegS2[1];

      /* MinMax: '<S54>/MinMax49' incorporates:
       *  Constant: '<S54>/Constant34'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH1RefPrev);

      /* MinMax: '<S54>/MinMax72' incorporates:
       *  Constant: '<S54>/Constant10'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1RefPrev, 0.0F);

      /* Product: '<S353>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax50'
       *  MinMax: '<S54>/MinMax61'
       *  Sum: '<S54>/Add14'
       *  Sum: '<S54>/Add15'
       */
      localAdd19_e = (rt_MINf(localAdd1_nw, FuSysM_agBegInjS2Ref) - rt_MINf
                      (FuSysM_agBegInjS2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH1RefPrev - FuSysM_agBegInjH1RefPrev);

      /* Outputs for atomic SubSystem: '<S353>/If Action Subsystem3' */

      /* Switch: '<S396>/Switch1' incorporates:
       *  Constant: '<S396>/Constant1'
       *  Constant: '<S396>/Constant2'
       *  Constant: '<S396>/Constant3'
       *  Logic: '<S396>/Logical Operator1'
       *  RelationalOperator: '<S396>/Relational Operator'
       *  RelationalOperator: '<S396>/Relational Operator1'
       *  RelationalOperator: '<S396>/Relational Operator3'
       */
      if (((localAdd19_e != localAdd19_e) || (localAdd19_e > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd19_e)) {
        localAdd19_e = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S353>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax63' incorporates:
       *  Constant: '<S54>/Constant1'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH2RefPrev);

      /* MinMax: '<S54>/MinMax66' incorporates:
       *  Constant: '<S54>/Constant3'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2RefPrev, 0.0F);

      /* Product: '<S354>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax64'
       *  MinMax: '<S54>/MinMax65'
       *  Sum: '<S54>/Add42'
       *  Sum: '<S54>/Add43'
       */
      localDivide_hb = (rt_MINf(localAdd1_nw, FuSysM_agBegInjS2Ref) - rt_MINf
                        (FuSysM_agBegInjS2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2RefPrev - FuSysM_agBegInjH2RefPrev);

      /* Outputs for atomic SubSystem: '<S354>/If Action Subsystem3' */

      /* Switch: '<S398>/Switch1' incorporates:
       *  Constant: '<S398>/Constant1'
       *  Constant: '<S398>/Constant2'
       *  Constant: '<S398>/Constant3'
       *  Logic: '<S398>/Logical Operator1'
       *  RelationalOperator: '<S398>/Relational Operator'
       *  RelationalOperator: '<S398>/Relational Operator1'
       *  RelationalOperator: '<S398>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S354>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax54' incorporates:
       *  Constant: '<S54>/Constant4'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH1Ref);

      /* MinMax: '<S54>/MinMax55' incorporates:
       *  Constant: '<S54>/Constant5'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH1Ref, 0.0F);

      /* Product: '<S355>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax56'
       *  MinMax: '<S54>/MinMax57'
       *  Sum: '<S54>/Add34'
       *  Sum: '<S54>/Add47'
       */
      localDivide_o3 = (rt_MINf(localAdd1_nw, FuSysM_agBegInjS2Ref) - rt_MINf
                        (FuSysM_agBegInjS2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH1Ref - FuSysM_agBegInjH1Ref);

      /* Outputs for atomic SubSystem: '<S355>/If Action Subsystem3' */

      /* Switch: '<S400>/Switch1' incorporates:
       *  Constant: '<S400>/Constant1'
       *  Constant: '<S400>/Constant2'
       *  Constant: '<S400>/Constant3'
       *  Logic: '<S400>/Logical Operator1'
       *  RelationalOperator: '<S400>/Relational Operator'
       *  RelationalOperator: '<S400>/Relational Operator1'
       *  RelationalOperator: '<S400>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S355>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax67' incorporates:
       *  Constant: '<S54>/Constant6'
       */
      localAdd1_nw = rt_MAXf(0.0F, FuSysM_agEndInjH2Ref);

      /* MinMax: '<S54>/MinMax68' incorporates:
       *  Constant: '<S54>/Constant7'
       */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2Ref, 0.0F);

      /* Product: '<S356>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax69'
       *  MinMax: '<S54>/MinMax70'
       *  Sum: '<S54>/Add44'
       *  Sum: '<S54>/Add45'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, FuSysM_agBegInjS2Ref) - rt_MINf
                      (FuSysM_agBegInjS2Ref, localDataTypeConversion1_i)) /
        (FuSysM_agEndInjH2Ref - FuSysM_agBegInjH2Ref);

      /* Outputs for atomic SubSystem: '<S356>/If Action Subsystem3' */

      /* Switch: '<S402>/Switch1' incorporates:
       *  Constant: '<S402>/Constant1'
       *  Constant: '<S402>/Constant2'
       *  Constant: '<S402>/Constant3'
       *  Logic: '<S402>/Logical Operator1'
       *  RelationalOperator: '<S402>/Relational Operator'
       *  RelationalOperator: '<S402>/Relational Operator1'
       *  RelationalOperator: '<S402>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S356>/If Action Subsystem3' */

      /* DataTypeConversion: '<S332>/OutDTConv' incorporates:
       *  Constant: '<S332>/offset'
       *  Constant: '<S332>/offset1'
       *  Constant: '<S332>/one_on_slope'
       *  Product: '<S332>/Product4'
       *  Sum: '<S332>/Add1'
       *  Sum: '<S332>/Add2'
       */
      localtmp = (32768.0F * localAdd19_e) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fz[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fz[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fz[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_fz[3] = locallocalOutDTConv_idx;

      /* Lookup: '<S326>/Look-Up Table'
       * About '<S326>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_kr[0]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_fz[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_kr[1]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_fz[1], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_kr[2]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_fz[2], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_kr[3]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_fz[3], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S326>/Data Type Duplicate1'
       *
       * Regarding '<S326>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S361>/Divide' incorporates:
       *  DataTypeConversion: '<S54>/Data Type Conversion6'
       *  Lookup: '<S326>/Look-Up Table'
       */
      FuSysM_prm_mFuInjBegS2[0] = (((Float32)localLookUpTable_kr[0]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Prev;
      FuSysM_prm_mFuInjBegS2[1] = (((Float32)localLookUpTable_kr[1]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Prev;
      FuSysM_prm_mFuInjBegS2[2] = (((Float32)localLookUpTable_kr[2]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1;
      FuSysM_prm_mFuInjBegS2[3] = (((Float32)localLookUpTable_kr[3]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2;

      /* Sum: '<S54>/Add13' incorporates:
       *  Product: '<S360>/Divide'
       *  Sum: '<S54>/Add26'
       *  Sum: '<S54>/Add49'
       */
      localmin = (((localAdd1_o1 - FuSysM_mFuReqInjS1) -
                   (((FuSysM_prm_mFuInjBegS2[0] + FuSysM_prm_mFuInjBegS2[1]) +
                     FuSysM_prm_mFuInjBegS2[2]) + FuSysM_prm_mFuInjBegS2[3])) *
                  localDataTypeConversion7) + localDataTypeConversion8;

      /* MinMax: '<S54>/MinMax5' */
      localAdd1_nw = rt_MINf(FuSysM_agEndInjS2Ref, localDataTypeConversion2);

      /* Sum: '<S54>/Add2' incorporates:
       *  MinMax: '<S54>/MinMax1'
       */
      localAdd19_e = rt_MAXf(localAdd1_nw, FuSysM_agBegInjS2Ref) -
        FuSysM_agBegInjS2Ref;

      /* MinMax: '<S54>/MinMax14' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS2Ref, FuSysM_agEndInjH1RefPrev);

      /* MinMax: '<S54>/MinMax16' */
      localAdd14_i = rt_MINf(localAdd1_nw, FuSysM_agEndInjS2Ref);

      /* MinMax: '<S54>/MinMax15' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH1RefPrev, FuSysM_agBegInjS2Ref);

      /* MinMax: '<S54>/MinMax18' */
      localmin_0 = rt_MINf(FuSysM_agEndInjS2Ref, localAdd1_nw);

      /* MinMax: '<S54>/MinMax78' */
      localAdd1_nw = rt_MINf(localDataTypeConversion1, FuSysM_agEndInjS2Ref);

      /* Product: '<S349>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax32'
       *  Sum: '<S54>/Add37'
       *  Sum: '<S54>/Add56'
       */
      localDivide_hb = (rt_MAXf(localDataTypeConversion9_g, localAdd1_nw) -
                        localDataTypeConversion9_g) / (localDataTypeConversion1
        - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S349>/If Action Subsystem3' */

      /* Switch: '<S388>/Switch1' incorporates:
       *  Constant: '<S388>/Constant1'
       *  Constant: '<S388>/Constant2'
       *  Constant: '<S388>/Constant3'
       *  Logic: '<S388>/Logical Operator1'
       *  RelationalOperator: '<S388>/Relational Operator'
       *  RelationalOperator: '<S388>/Relational Operator1'
       *  RelationalOperator: '<S388>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S349>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax2' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion9_g, FuSysM_agBegInjS2Ref);

      /* Product: '<S348>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax22'
       *  Sum: '<S54>/Add28'
       *  Sum: '<S54>/Add50'
       */
      localDivide_o3 = (rt_MINf(localDataTypeConversion1, localAdd1_nw) -
                        localDataTypeConversion9_g) / (localDataTypeConversion1
        - localDataTypeConversion9_g);

      /* Outputs for atomic SubSystem: '<S348>/If Action Subsystem3' */

      /* Switch: '<S386>/Switch1' incorporates:
       *  Constant: '<S386>/Constant1'
       *  Constant: '<S386>/Constant2'
       *  Constant: '<S386>/Constant3'
       *  Logic: '<S386>/Logical Operator1'
       *  RelationalOperator: '<S386>/Relational Operator'
       *  RelationalOperator: '<S386>/Relational Operator1'
       *  RelationalOperator: '<S386>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S348>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax34' */
      localAdd1_nw = rt_MINf(localDataTypeConversion3, FuSysM_agEndInjS2Ref);

      /* Product: '<S347>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax20'
       *  Sum: '<S54>/Add25'
       *  Sum: '<S54>/Add36'
       */
      localDataTypeConversion1_i = (rt_MAXf(localDataTypeConversion2,
        localAdd1_nw) - localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S347>/If Action Subsystem3' */

      /* Switch: '<S384>/Switch1' incorporates:
       *  Constant: '<S384>/Constant1'
       *  Constant: '<S384>/Constant2'
       *  Constant: '<S384>/Constant3'
       *  Logic: '<S384>/Logical Operator1'
       *  RelationalOperator: '<S384>/Relational Operator'
       *  RelationalOperator: '<S384>/Relational Operator1'
       *  RelationalOperator: '<S384>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S347>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax77' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion2, FuSysM_agBegInjS2Ref);

      /* Product: '<S346>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax79'
       *  Sum: '<S54>/Add35'
       *  Sum: '<S54>/Add46'
       */
      localAdd1_nw = (rt_MINf(localDataTypeConversion3, localAdd1_nw) -
                      localDataTypeConversion2) / (localDataTypeConversion3 -
        localDataTypeConversion2);

      /* Outputs for atomic SubSystem: '<S346>/If Action Subsystem3' */

      /* Switch: '<S382>/Switch1' incorporates:
       *  Constant: '<S382>/Constant1'
       *  Constant: '<S382>/Constant2'
       *  Constant: '<S382>/Constant3'
       *  Logic: '<S382>/Logical Operator1'
       *  RelationalOperator: '<S382>/Relational Operator'
       *  RelationalOperator: '<S382>/Relational Operator1'
       *  RelationalOperator: '<S382>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S346>/If Action Subsystem3' */

      /* DataTypeConversion: '<S334>/OutDTConv' incorporates:
       *  Constant: '<S334>/offset'
       *  Constant: '<S334>/offset1'
       *  Constant: '<S334>/one_on_slope'
       *  Product: '<S334>/Product4'
       *  Sum: '<S334>/Add1'
       *  Sum: '<S334>/Add2'
       */
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_d[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_d[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_d[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_d[3] = locallocalOutDTConv_idx;

      /* Lookup2D: '<S331>/Look-Up Table (2-D)'
       * About '<S331>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_n[0]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_d[0], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_n[1]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_d[1], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_n[2]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_d[2], (&(FuSysM_rAgPmp_A[0])), 8U);
      Look2D_U16_U16_U16( &(localLookUpTable2D_n[3]), (&(FuSysM_rMassPmp_M[0])),
                         pFuM_B.VEMS_vidGET, (&(FuSysM_nEng_mOvlpPmp_A[0])), 8U,
                         localOutDTConv_d[3], (&(FuSysM_rAgPmp_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S331>/Data Type Duplicate2'
       *
       * Regarding '<S331>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S54>/DTConv_Single_To_UFix_3' */
      locallocalDataTypeConversion5_0 = ((Float32)localLookUpTable2D_n[0]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_i = ((Float32)localLookUpTable2D_n[1]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_2 = ((Float32)localLookUpTable2D_n[2]) *
        3.051757813E-005F;
      locallocalDataTypeConversion5_1 = ((Float32)localLookUpTable2D_n[3]) *
        3.051757813E-005F;

      /* Sum: '<S54>/Add22' */
      localAdd30_mn = FuSysM_agEndInjH2RefPrev - FuSysM_agBegInjH2RefPrev;

      /* Sum: '<S54>/Add23' */
      localDivide_hb = FuSysM_agEndInjH1RefPrev - FuSysM_agBegInjH1RefPrev;

      /* MinMax: '<S54>/MinMax17' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS2Ref, FuSysM_agEndInjH2RefPrev);

      /* MinMax: '<S54>/MinMax12' */
      locallocalDataTypeConversion4_0 = rt_MINf(localAdd1_nw,
        FuSysM_agEndInjS2Ref);

      /* MinMax: '<S54>/MinMax25' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjH2RefPrev, FuSysM_agBegInjS2Ref);

      /* MinMax: '<S54>/MinMax13' */
      localDivide_o3 = rt_MINf(FuSysM_agEndInjS2Ref, localAdd1_nw);

      /* MinMax: '<S54>/MinMax21' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion1, FuSysM_agBegInjS2Ref);

      /* Product: '<S345>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax19'
       *  Sum: '<S54>/Add5'
       *  Sum: '<S54>/Add8'
       */
      localDataTypeConversion1_i = (FuSysM_agEndInjS2Ref - rt_MINf
        (FuSysM_agEndInjS2Ref, localAdd1_nw)) / (FuSysM_agEndInjS2Ref -
        FuSysM_agBegInjS2Ref);

      /* Outputs for atomic SubSystem: '<S345>/If Action Subsystem3' */

      /* Switch: '<S380>/Switch1' incorporates:
       *  Constant: '<S380>/Constant1'
       *  Constant: '<S380>/Constant2'
       *  Constant: '<S380>/Constant3'
       *  Logic: '<S380>/Logical Operator1'
       *  RelationalOperator: '<S380>/Relational Operator'
       *  RelationalOperator: '<S380>/Relational Operator1'
       *  RelationalOperator: '<S380>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S345>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax36' */
      localAdd1_nw = rt_MAXf(localDataTypeConversion3, FuSysM_agBegInjS2Ref);

      /* Product: '<S344>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax33'
       *  Sum: '<S54>/Add38'
       *  Sum: '<S54>/Add39'
       */
      localAdd1_nw = (FuSysM_agEndInjS2Ref - rt_MINf(FuSysM_agEndInjS2Ref,
        localAdd1_nw)) / (FuSysM_agEndInjS2Ref - FuSysM_agBegInjS2Ref);

      /* Outputs for atomic SubSystem: '<S344>/If Action Subsystem3' */

      /* Switch: '<S378>/Switch1' incorporates:
       *  Constant: '<S378>/Constant1'
       *  Constant: '<S378>/Constant2'
       *  Constant: '<S378>/Constant3'
       *  Logic: '<S378>/Logical Operator1'
       *  RelationalOperator: '<S378>/Relational Operator'
       *  RelationalOperator: '<S378>/Relational Operator1'
       *  RelationalOperator: '<S378>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S344>/If Action Subsystem3' */

      /* DataTypeConversion: '<S335>/OutDTConv' incorporates:
       *  Constant: '<S335>/offset'
       *  Constant: '<S335>/offset1'
       *  Constant: '<S335>/one_on_slope'
       *  Product: '<S335>/Product4'
       *  Sum: '<S335>/Add1'
       *  Sum: '<S335>/Add2'
       */
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_g[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_g[1] = locallocalOutDTConv_idx;

      /* Lookup: '<S329>/Look-Up Table'
       * About '<S329>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_l[0]), (&(FuSysM_facCorMassEndPmpStk_T
        [0])), localOutDTConv_g[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_l[1]), (&(FuSysM_facCorMassEndPmpStk_T
        [0])), localOutDTConv_g[1], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S329>/Data Type Duplicate1'
       *
       * Regarding '<S329>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S54>/Data Type Conversion1' incorporates:
       *  Lookup: '<S329>/Look-Up Table'
       */
      FuSysM_prm_fac1CorMassPmpInjS2[0] = ((Float32)localLookUpTable_l[0]) *
        3.051757813E-005F;
      FuSysM_prm_fac1CorMassPmpInjS2[1] = ((Float32)localLookUpTable_l[1]) *
        3.051757813E-005F;

      /* Product: '<S343>/Divide' */
      localDataTypeConversion1_i = localAdd12_e /
        locallocalDataTypeConversion4_l;

      /* Outputs for atomic SubSystem: '<S343>/If Action Subsystem3' */

      /* Switch: '<S376>/Switch1' incorporates:
       *  Constant: '<S376>/Constant1'
       *  Constant: '<S376>/Constant2'
       *  Constant: '<S376>/Constant3'
       *  Logic: '<S376>/Logical Operator1'
       *  RelationalOperator: '<S376>/Relational Operator'
       *  RelationalOperator: '<S376>/Relational Operator1'
       *  RelationalOperator: '<S376>/Relational Operator3'
       */
      if (((localDataTypeConversion1_i != localDataTypeConversion1_i) ||
           (localDataTypeConversion1_i > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDataTypeConversion1_i)) {
        localDataTypeConversion1_i = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S343>/If Action Subsystem3' */

      /* Product: '<S342>/Divide' incorporates:
       *  Sum: '<S54>/Add33'
       */
      localAdd1_nw = localAdd19_e / (FuSysM_agEndInjS2Ref - FuSysM_agBegInjS2Ref);

      /* Outputs for atomic SubSystem: '<S342>/If Action Subsystem3' */

      /* Switch: '<S374>/Switch1' incorporates:
       *  Constant: '<S374>/Constant1'
       *  Constant: '<S374>/Constant2'
       *  Constant: '<S374>/Constant3'
       *  Logic: '<S374>/Logical Operator1'
       *  RelationalOperator: '<S374>/Relational Operator'
       *  RelationalOperator: '<S374>/Relational Operator1'
       *  RelationalOperator: '<S374>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S342>/If Action Subsystem3' */

      /* DataTypeConversion: '<S336>/OutDTConv' incorporates:
       *  Constant: '<S336>/offset'
       *  Constant: '<S336>/offset1'
       *  Constant: '<S336>/one_on_slope'
       *  Product: '<S336>/Product4'
       *  Sum: '<S336>/Add1'
       *  Sum: '<S336>/Add2'
       */
      localtmp = (32768.0F * localDataTypeConversion1_i) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_i[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_i[1] = locallocalOutDTConv_idx;

      /* Lookup: '<S328>/Look-Up Table'
       * About '<S328>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_g[0]), (&(FuSysM_facCorMassBegPmpStk_T
        [0])), localOutDTConv_i[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_g[1]), (&(FuSysM_facCorMassBegPmpStk_T
        [0])), localOutDTConv_i[1], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S328>/Data Type Duplicate1'
       *
       * Regarding '<S328>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S54>/Data Type Conversion2' incorporates:
       *  Lookup: '<S328>/Look-Up Table'
       */
      FuSysM_prm_fac2CorMassPmpInjS2[0] = ((Float32)localLookUpTable_g[0]) *
        3.051757813E-005F;
      FuSysM_prm_fac2CorMassPmpInjS2[1] = ((Float32)localLookUpTable_g[1]) *
        3.051757813E-005F;

      /* Product: '<S363>/Divide' incorporates:
       *  Constant: '<S54>/Constant2'
       *  Product: '<S362>/Divide'
       *  Sum: '<S54>/Add21'
       *  Sum: '<S54>/Add48'
       *  Sum: '<S54>/Add9'
       */
      FuSysM_prm_mFuPmpOvlpS2[0] = ((locallocalDataTypeConversion5_0 -
        locallocalDataTypeConversion5_i) * localDataTypeConversion4) * ((1.0F +
        FuSysM_prm_fac1CorMassPmpInjS2[0]) - FuSysM_prm_fac2CorMassPmpInjS2[0]);
      FuSysM_prm_mFuPmpOvlpS2[1] = ((locallocalDataTypeConversion5_2 -
        locallocalDataTypeConversion5_1) * localDataTypeConversion5) * ((1.0F +
        FuSysM_prm_fac1CorMassPmpInjS2[1]) - FuSysM_prm_fac2CorMassPmpInjS2[1]);

      /* Sum: '<S54>/Add27' */
      localAdd1_o1 = FuSysM_prm_mFuPmpOvlpS2[0] + FuSysM_prm_mFuPmpOvlpS2[1];

      /* Product: '<S341>/Divide' incorporates:
       *  Sum: '<S54>/Add20'
       */
      localAdd19_e = (localAdd14_i - localmin_0) / localDivide_hb;

      /* Outputs for atomic SubSystem: '<S341>/If Action Subsystem3' */

      /* Switch: '<S372>/Switch1' incorporates:
       *  Constant: '<S372>/Constant1'
       *  Constant: '<S372>/Constant2'
       *  Constant: '<S372>/Constant3'
       *  Logic: '<S372>/Logical Operator1'
       *  RelationalOperator: '<S372>/Relational Operator'
       *  RelationalOperator: '<S372>/Relational Operator1'
       *  RelationalOperator: '<S372>/Relational Operator3'
       */
      if (((localAdd19_e != localAdd19_e) || (localAdd19_e > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd19_e)) {
        localAdd19_e = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S341>/If Action Subsystem3' */

      /* Product: '<S340>/Divide' incorporates:
       *  Sum: '<S54>/Add24'
       */
      localDivide_hb = (locallocalDataTypeConversion4_0 - localDivide_o3) /
        localAdd30_mn;

      /* Outputs for atomic SubSystem: '<S340>/If Action Subsystem3' */

      /* Switch: '<S370>/Switch1' incorporates:
       *  Constant: '<S370>/Constant1'
       *  Constant: '<S370>/Constant2'
       *  Constant: '<S370>/Constant3'
       *  Logic: '<S370>/Logical Operator1'
       *  RelationalOperator: '<S370>/Relational Operator'
       *  RelationalOperator: '<S370>/Relational Operator1'
       *  RelationalOperator: '<S370>/Relational Operator3'
       */
      if (((localDivide_hb != localDivide_hb) || (localDivide_hb >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_hb)) {
        localDivide_hb = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S340>/If Action Subsystem3' */

      /* Product: '<S358>/Divide' incorporates:
       *  Sum: '<S54>/Add1'
       *  Sum: '<S54>/Add4'
       */
      localDivide_o3 = (locallocalDataTypeConversion4_1 -
                        locallocalDataTypeConversion4_2) / (FuSysM_agEndInjH1Ref
        - FuSysM_agBegInjH1Ref);

      /* Outputs for atomic SubSystem: '<S358>/If Action Subsystem3' */

      /* Switch: '<S406>/Switch1' incorporates:
       *  Constant: '<S406>/Constant1'
       *  Constant: '<S406>/Constant2'
       *  Constant: '<S406>/Constant3'
       *  Logic: '<S406>/Logical Operator1'
       *  RelationalOperator: '<S406>/Relational Operator'
       *  RelationalOperator: '<S406>/Relational Operator1'
       *  RelationalOperator: '<S406>/Relational Operator3'
       */
      if (((localDivide_o3 != localDivide_o3) || (localDivide_o3 >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_o3)) {
        localDivide_o3 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S358>/If Action Subsystem3' */

      /* MinMax: '<S54>/MinMax7' */
      localAdd1_nw = rt_MAXf(FuSysM_agBegInjS2Ref, FuSysM_agEndInjH2Ref);

      /* MinMax: '<S54>/MinMax9' */
      localDataTypeConversion1_i = rt_MAXf(FuSysM_agBegInjH2Ref,
        FuSysM_agBegInjS2Ref);

      /* Product: '<S357>/Divide' incorporates:
       *  MinMax: '<S54>/MinMax10'
       *  MinMax: '<S54>/MinMax11'
       *  Sum: '<S54>/Add6'
       */
      localAdd1_nw = (rt_MINf(localAdd1_nw, FuSysM_agEndInjS2Ref) - rt_MINf
                      (FuSysM_agEndInjS2Ref, localDataTypeConversion1_i)) /
        localAdd12;

      /* Outputs for atomic SubSystem: '<S357>/If Action Subsystem3' */

      /* Switch: '<S404>/Switch1' incorporates:
       *  Constant: '<S404>/Constant1'
       *  Constant: '<S404>/Constant2'
       *  Constant: '<S404>/Constant3'
       *  Logic: '<S404>/Logical Operator1'
       *  RelationalOperator: '<S404>/Relational Operator'
       *  RelationalOperator: '<S404>/Relational Operator1'
       *  RelationalOperator: '<S404>/Relational Operator3'
       */
      if (((localAdd1_nw != localAdd1_nw) || (localAdd1_nw > 3.000000005E+038F))
          || (-3.000000005E+038F > localAdd1_nw)) {
        localAdd1_nw = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S357>/If Action Subsystem3' */

      /* DataTypeConversion: '<S337>/OutDTConv' incorporates:
       *  Constant: '<S337>/offset'
       *  Constant: '<S337>/offset1'
       *  Constant: '<S337>/one_on_slope'
       *  Product: '<S337>/Product4'
       *  Sum: '<S337>/Add1'
       *  Sum: '<S337>/Add2'
       */
      localtmp = (32768.0F * localAdd19_e) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_p[0] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_hb) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_p[1] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localDivide_o3) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_p[2] = locallocalOutDTConv_idx;
      localtmp = (32768.0F * localAdd1_nw) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          locallocalOutDTConv_idx = (UInt16)localtmp;
        } else {
          locallocalOutDTConv_idx = 0U;
        }
      } else {
        locallocalOutDTConv_idx = MAX_uint16_T;
      }

      localOutDTConv_p[3] = locallocalOutDTConv_idx;

      /* Lookup: '<S327>/Look-Up Table'
       * About '<S327>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^-15
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_m[0]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_p[0], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_m[1]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_p[1], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_m[2]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_p[2], (&(FuSysM_rAgInj_A[0])), 8U);
      LookUp_U16_U16( &(localLookUpTable_m[3]), (&(FuSysM_rMassInj_T[0])),
                     localOutDTConv_p[3], (&(FuSysM_rAgInj_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S327>/Data Type Duplicate1'
       *
       * Regarding '<S327>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S366>/Divide' incorporates:
       *  DataTypeConversion: '<S54>/Data Type Conversion8'
       *  Lookup: '<S327>/Look-Up Table'
       */
      FuSysM_prm_mFuInjOvlpS2[0] = (((Float32)localLookUpTable_m[0]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1Prev;
      FuSysM_prm_mFuInjOvlpS2[1] = (((Float32)localLookUpTable_m[1]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2Prev;
      FuSysM_prm_mFuInjOvlpS2[2] = (((Float32)localLookUpTable_m[2]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH1;
      FuSysM_prm_mFuInjOvlpS2[3] = (((Float32)localLookUpTable_m[3]) *
        3.051757813E-005F) * FuSysM_mFuReqInjH2;

      /* DataTypeConversion: '<S54>/Data Type Conversion12' incorporates:
       *  Constant: '<S54>/FuSysM_pFuMin_C'
       */
      localAdd1_nw = ((Float32)FuSysM_pFuMin_C) * 781.25F;

      /* MinMax: '<S54>/MinMax26' */
      FuSysM_pFuEstimBegS2 = rt_MAXf(localmin, localAdd1_nw);

      /* Sum: '<S54>/Add7' incorporates:
       *  Constant: '<S54>/FuSysM_rMassPFuMeanEstim_C'
       *  DataTypeConversion: '<S54>/Data Type Conversion13'
       *  Product: '<S364>/Divide'
       *  Product: '<S365>/Divide'
       *  Sum: '<S54>/Add29'
       *  Sum: '<S54>/Add3'
       */
      localmin = ((((localAdd1_o1 - FuSysM_mFuReqInjS2) -
                    (((FuSysM_prm_mFuInjOvlpS2[0] + FuSysM_prm_mFuInjOvlpS2[1])
                      + FuSysM_prm_mFuInjOvlpS2[2]) + FuSysM_prm_mFuInjOvlpS2[3]))
                   * (((Float32)FuSysM_rMassPFuMeanEstim_C) * 3.051757813E-005F))
                  * localDataTypeConversion7) + FuSysM_pFuEstimBegS2;

      /* DataTypeConversion: '<S338>/OutDTConv' incorporates:
       *  Constant: '<S338>/offset'
       *  Constant: '<S338>/offset1'
       *  Constant: '<S338>/one_on_slope'
       *  MinMax: '<S54>/MinMax27'
       *  Product: '<S338>/Product4'
       *  Sum: '<S338>/Add1'
       *  Sum: '<S338>/Add2'
       */
      localtmp = (1.279999968E-003F * rt_MAXf(localmin, localAdd1_nw)) + 0.5F;
      if (localtmp < 65536.0F) {
        pFuM_B.Merge3 = (UInt16)localtmp;
      } else {
        pFuM_B.Merge3 = MAX_uint16_T;
      }
    } else {
      /* DataTypeConversion: '<S407>/OutDTConv' incorporates:
       *  Constant: '<S407>/offset'
       *  Constant: '<S407>/offset1'
       *  Constant: '<S407>/one_on_slope'
       *  Product: '<S407>/Product4'
       *  Sum: '<S407>/Add1'
       *  Sum: '<S407>/Add2'
       */
      pFuM_B.Merge3 = (UInt16)((1.279999968E-003F * localDataTypeConversion8)
        + 0.5F);
    }
  } else {
    /* Sum: '<S408>/Add1' incorporates:
     *  Constant: '<S408>/Constant1'
     *  Constant: '<S47>/FuSysM_rFilGainPFuMdl_C'
     */
    localAdd1_nw = 1.0F - (((Float32)FuSysM_rFilGainPFuMdl_C) * 0.00390625F);

    /* DataTypeConversion: '<S47>/Data Type Conversion1' */
    localDataTypeConversion1_i = ((Float32)pFuM_B.VEMS_vidGET1) * 781.25F;

    /* DataTypeConversion: '<S409>/OutDTConv' incorporates:
     *  Constant: '<S409>/offset'
     *  Constant: '<S409>/offset1'
     *  Constant: '<S409>/one_on_slope'
     *  Constant: '<S47>/FuSysM_rFilGainPFuMdl_C'
     *  Product: '<S409>/Product4'
     *  Product: '<S410>/Divide'
     *  Product: '<S411>/Divide'
     *  SignalConversion: '<S47>/Signal Conversion1'
     *  SignalConversion: '<S47>/Signal Conversion2'
     *  SignalConversion: '<S47>/Signal Conversion3'
     *  SignalConversion: '<S47>/Signal Conversion4'
     *  Sum: '<S408>/Sum2'
     *  Sum: '<S409>/Add1'
     *  Sum: '<S409>/Add2'
     */
    localtmp = ((((((Float32)FuSysM_rFilGainPFuMdl_C) * 0.00390625F) *
                  localDataTypeConversion1_i) + (localAdd1_nw *
      FuSysM_pFuEstimInjH1Prev)) * 1.279999968E-003F) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        pFuM_B.Merge = (UInt16)localtmp;
      } else {
        pFuM_B.Merge = 0U;
      }
    } else {
      pFuM_B.Merge = MAX_uint16_T;
    }

    localtmp = ((((((Float32)FuSysM_rFilGainPFuMdl_C) * 0.00390625F) *
                  localDataTypeConversion1_i) + (localAdd1_nw *
      FuSysM_pFuEstimInjS1Prev)) * 1.279999968E-003F) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        pFuM_B.Merge1 = (UInt16)localtmp;
      } else {
        pFuM_B.Merge1 = 0U;
      }
    } else {
      pFuM_B.Merge1 = MAX_uint16_T;
    }

    localtmp = ((((((Float32)FuSysM_rFilGainPFuMdl_C) * 0.00390625F) *
                  localDataTypeConversion1_i) + (localAdd1_nw *
      FuSysM_pFuEstimInjH2Prev)) * 1.279999968E-003F) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        pFuM_B.Merge2 = (UInt16)localtmp;
      } else {
        pFuM_B.Merge2 = 0U;
      }
    } else {
      pFuM_B.Merge2 = MAX_uint16_T;
    }

    localtmp = ((((((Float32)FuSysM_rFilGainPFuMdl_C) * 0.00390625F) *
                  localDataTypeConversion1_i) + (localAdd1_nw *
      FuSysM_pFuEstimInjS2Prev)) * 1.279999968E-003F) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        pFuM_B.Merge3 = (UInt16)localtmp;
      } else {
        pFuM_B.Merge3 = 0U;
      }
    } else {
      pFuM_B.Merge3 = MAX_uint16_T;
    }
  }
}

/* Output and update for function-call system: '<S8>/F02_PFuMdl' */
void pFuM_F02_PFuMdl(void)
{
  Float32 localSubtract4;
  UInt16 localrtmax;
  Float32 localtmp;
  UInt16 localrtmax_0;

  /* Outputs for enable SubSystem: '<S24>/F02_PFuMdl' incorporates:
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S24>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S33>/Enable'
   *  RelationalOperator: '<S24>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_pFuRailMes, pFuM_B.VEMS_vidGET1);

    /* DataTypeConversion Block: '<S37>/Data Type Conversion'
     *
     * Regarding '<S37>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET8 */
    VEMS_vidGET(FuSysM_tFu, pFuM_B.VEMS_vidGET8_a);

    /* DataTypeConversion Block: '<S37>/Data Type Conversion1'
     *
     * Regarding '<S37>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate1'
     *
     * Regarding '<S37>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S37>/Look-Up Table (2-D)'
     * About '<S37>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Input1  Data Type:  Fixed Point    U16  Bias 233.0
     * Output0 Data Type:  Fixed Point    U16  2^20  FSlope 1.1641532182693481E+000
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(pFuM_B.LookUpTable2D), (&(FuSysM_facCnvMassFuPFu_M[0])),
                       pFuM_B.VEMS_vidGET1, (&(FuSysM_pFuRailMes_A[0])), 15U,
                       pFuM_B.VEMS_vidGET8_a, (&(FuSysM_tFu_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate2'
     *
     * Regarding '<S37>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET9 */
    VEMS_vidGET(FuSysM_pFuEstimInjH1, pFuM_B.VEMS_vidGET9_g);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET10 */
    VEMS_vidGET(FuSysM_pFuEstimInjS1, pFuM_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET11 */
    VEMS_vidGET(FuSysM_pFuEstimInjH2, pFuM_B.VEMS_vidGET11);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET12 */
    VEMS_vidGET(FuSysM_pFuEstimInjS2, pFuM_B.VEMS_vidGET12);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET */
    VEMS_vidGET(Ext_nEng, pFuM_B.VEMS_vidGET);

    /* DataTypeConversion Block: '<S60>/Data Type Conversion'
     *
     * Regarding '<S60>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S61>/Data Type Conversion'
     *
     * Regarding '<S61>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S154>/Data Type Conversion'
     *
     * Regarding '<S154>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S155>/Data Type Conversion'
     *
     * Regarding '<S155>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S236>/Data Type Conversion'
     *
     * Regarding '<S236>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S237>/Data Type Conversion'
     *
     * Regarding '<S237>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S330>/Data Type Conversion'
     *
     * Regarding '<S330>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S331>/Data Type Conversion'
     *
     * Regarding '<S331>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET2 */
    VEMS_vidGET(FuSysM_agBegPmpStk1Ref, pFuM_B.VEMS_vidGET2_ak);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET4 */
    VEMS_vidGET(FuSysM_agEndPmpStk1Ref, pFuM_B.VEMS_vidGET4_o);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET3 */
    VEMS_vidGET(FuSysM_agBegPmpStk2Ref, pFuM_B.VEMS_vidGET3_o);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET5 */
    VEMS_vidGET(FuSysM_agEndPmpStk2Ref, pFuM_B.VEMS_vidGET5_d);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET6 */
    VEMS_vidGET(FuSysM_mFuPmpStk1Req, pFuM_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S33>/VEMS_vidGET7 */
    VEMS_vidGET(FuSysM_mFuPmpStk2Req, pFuM_B.VEMS_vidGET7);

    /* If: '<S33>/If' incorporates:
     *  ActionPort: '<S35>/Action Port'
     *  ActionPort: '<S36>/Action Port'
     *  Inport: '<Root>/FRM_bAcvPFuMDftMod'
     *  SubSystem: '<S33>/F01_bAcvPFuMDftMod'
     *  SubSystem: '<S33>/F02_PFuMdlClcn'
     */
    if (GDGAR_bGetFRM(FRM_FRM_ACVPFUMDFTMOD)) {
      /* DataTypeConversion: '<S35>/Data Type Conversion8' */
      localSubtract4 = ((Float32)pFuM_B.LookUpTable2D) * 1.220703125E+006F;

      /* Sum: '<S35>/Subtract4' incorporates:
       *  Product: '<S42>/Divide'
       *  Product: '<S43>/Divide'
       *  Product: '<S44>/Divide'
       *  Product: '<S45>/Divide'
       */
      localSubtract4 = (((FuSysM_mFuReqInjH1 * localSubtract4) +
                         (FuSysM_mFuReqInjS1 * localSubtract4)) +
                        (FuSysM_mFuReqInjH2 * localSubtract4)) +
        (FuSysM_mFuReqInjS2 * localSubtract4);

      /* MinMax: '<S35>/MinMax' incorporates:
       *  Constant: '<S35>/FuSysM_pFuMin_C'
       *  Constant: '<S38>/offset'
       *  Constant: '<S38>/offset1'
       *  Constant: '<S38>/one_on_slope'
       *  DataTypeConversion: '<S35>/Data Type Conversion9'
       *  DataTypeConversion: '<S38>/OutDTConv'
       *  Product: '<S38>/Product4'
       *  Sum: '<S35>/Subtract'
       *  Sum: '<S38>/Add1'
       *  Sum: '<S38>/Add2'
       */
      localrtmax = FuSysM_pFuMin_C;
      localtmp = (((((Float32)pFuM_B.VEMS_vidGET9_g) * 781.25F) -
                   localSubtract4) * 1.279999968E-003F) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          localrtmax_0 = (UInt16)localtmp;
        } else {
          localrtmax_0 = 0U;
        }
      } else {
        localrtmax_0 = MAX_uint16_T;
      }

      if (localrtmax_0 > FuSysM_pFuMin_C) {
        localrtmax = localrtmax_0;
      }

      pFuM_B.Merge = localrtmax;

      /* MinMax: '<S35>/MinMax1' incorporates:
       *  Constant: '<S35>/FuSysM_pFuMin_C'
       *  Constant: '<S39>/offset'
       *  Constant: '<S39>/offset1'
       *  Constant: '<S39>/one_on_slope'
       *  DataTypeConversion: '<S35>/Data Type Conversion1'
       *  DataTypeConversion: '<S39>/OutDTConv'
       *  Product: '<S39>/Product4'
       *  Sum: '<S35>/Subtract1'
       *  Sum: '<S39>/Add1'
       *  Sum: '<S39>/Add2'
       */
      localrtmax = FuSysM_pFuMin_C;
      localtmp = (((((Float32)pFuM_B.VEMS_vidGET10) * 781.25F) - localSubtract4)
                  * 1.279999968E-003F) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          localrtmax_0 = (UInt16)localtmp;
        } else {
          localrtmax_0 = 0U;
        }
      } else {
        localrtmax_0 = MAX_uint16_T;
      }

      if (localrtmax_0 > FuSysM_pFuMin_C) {
        localrtmax = localrtmax_0;
      }

      pFuM_B.Merge1 = localrtmax;

      /* MinMax: '<S35>/MinMax2' incorporates:
       *  Constant: '<S35>/FuSysM_pFuMin_C'
       *  Constant: '<S40>/offset'
       *  Constant: '<S40>/offset1'
       *  Constant: '<S40>/one_on_slope'
       *  DataTypeConversion: '<S35>/Data Type Conversion2'
       *  DataTypeConversion: '<S40>/OutDTConv'
       *  Product: '<S40>/Product4'
       *  Sum: '<S35>/Subtract2'
       *  Sum: '<S40>/Add1'
       *  Sum: '<S40>/Add2'
       */
      localrtmax = FuSysM_pFuMin_C;
      localtmp = (((((Float32)pFuM_B.VEMS_vidGET11) * 781.25F) - localSubtract4)
                  * 1.279999968E-003F) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          localrtmax_0 = (UInt16)localtmp;
        } else {
          localrtmax_0 = 0U;
        }
      } else {
        localrtmax_0 = MAX_uint16_T;
      }

      if (localrtmax_0 > FuSysM_pFuMin_C) {
        localrtmax = localrtmax_0;
      }

      pFuM_B.Merge2 = localrtmax;

      /* MinMax: '<S35>/MinMax3' incorporates:
       *  Constant: '<S35>/FuSysM_pFuMin_C'
       *  Constant: '<S41>/offset'
       *  Constant: '<S41>/offset1'
       *  Constant: '<S41>/one_on_slope'
       *  DataTypeConversion: '<S35>/Data Type Conversion3'
       *  DataTypeConversion: '<S41>/OutDTConv'
       *  Product: '<S41>/Product4'
       *  Sum: '<S35>/Subtract3'
       *  Sum: '<S41>/Add1'
       *  Sum: '<S41>/Add2'
       */
      localrtmax = FuSysM_pFuMin_C;
      localtmp = (((((Float32)pFuM_B.VEMS_vidGET12) * 781.25F) - localSubtract4)
                  * 1.279999968E-003F) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          localrtmax_0 = (UInt16)localtmp;
        } else {
          localrtmax_0 = 0U;
        }
      } else {
        localrtmax_0 = MAX_uint16_T;
      }

      if (localrtmax_0 > FuSysM_pFuMin_C) {
        localrtmax = localrtmax_0;
      }

      pFuM_B.Merge3 = localrtmax;
    } else {
      pFuM_F02_PFuMdlClcn();
    }

    /* S-Function "vems_vidSET" Block: <S33>/VEMS_vidSET */
    VEMS_vidSET(FuSysM_facCnvMassFuPFu, pFuM_B.LookUpTable2D);

    /* S-Function "vems_vidSET" Block: <S33>/VEMS_vidSET6 */
    VEMS_vidSET(FuSysM_pFuEstimInjH1, pFuM_B.Merge);

    /* S-Function "vems_vidSET" Block: <S33>/VEMS_vidSET7 */
    VEMS_vidSET(FuSysM_pFuEstimInjH2, pFuM_B.Merge2);

    /* S-Function "vems_vidSET" Block: <S33>/VEMS_vidSET8 */
    VEMS_vidSET(FuSysM_pFuEstimInjS1, pFuM_B.Merge1);

    /* S-Function "vems_vidSET" Block: <S33>/VEMS_vidSET9 */
    VEMS_vidSET(FuSysM_pFuEstimInjS2, pFuM_B.Merge3);
  }

  /* end of Outputs for SubSystem: '<S24>/F02_PFuMdl' */
}

/* Output and update for function-call system: '<S9>/F02_pFuMSyncEveInj' */
void pFuM_F02_pFuMSyncEveInj(void)
{
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S418>/F02_pFuMSyncEveInj' incorporates:
   *  Constant: '<S418>/Constant1'
   *  Constant: '<S418>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S425>/Enable'
   *  RelationalOperator: '<S418>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6, pFuM_B.VEMS_vidGET7_a);

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET3 */
    VEMS_vidGET(FuSysM_pFuEstimInjH2, pFuM_B.VEMS_vidGET3_a);

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, pFuM_B.VEMS_vidGET1_ew);

    /* Assignment: '<S425>/Assignment2' */
    for (locali = 0; locali < 6; locali++) {
      pFuM_B.Assignment2[(locali)] = pFuM_B.VEMS_vidGET7_a[(locali)];
    }

    pFuM_B.Assignment2[pFuM_B.VEMS_vidGET1_ew - 1] = pFuM_B.VEMS_vidGET3_a;

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6, pFuM_B.VEMS_vidGET6_g);

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET2 */
    VEMS_vidGET(FuSysM_pFuEstimInjH1, pFuM_B.VEMS_vidGET2);

    /* Assignment: '<S425>/Assignment5' */
    for (locali = 0; locali < 6; locali++) {
      pFuM_B.Assignment5[(locali)] = pFuM_B.VEMS_vidGET6_g[(locali)];
    }

    pFuM_B.Assignment5[pFuM_B.VEMS_vidGET1_ew - 1] = pFuM_B.VEMS_vidGET2;

    /* S-Function "vems_vidSET" Block: <S425>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjH1Cyl, 6, pFuM_B.Assignment5);

    /* S-Function "vems_vidSET" Block: <S425>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjH2Cyl, 6, pFuM_B.Assignment2);

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6, pFuM_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET4 */
    VEMS_vidGET(FuSysM_pFuEstimInjS1, pFuM_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInCyl, pFuM_B.VEMS_vidGET_b);

    /* Assignment: '<S425>/Assignment1' */
    for (locali = 0; locali < 6; locali++) {
      pFuM_B.Assignment1[(locali)] = pFuM_B.VEMS_vidGET8[(locali)];
    }

    pFuM_B.Assignment1[pFuM_B.VEMS_vidGET_b - 1] = pFuM_B.VEMS_vidGET4;

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6, pFuM_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S425>/VEMS_vidGET5 */
    VEMS_vidGET(FuSysM_pFuEstimInjS2, pFuM_B.VEMS_vidGET5);

    /* Assignment: '<S425>/Assignment4' */
    for (locali = 0; locali < 6; locali++) {
      pFuM_B.Assignment4[(locali)] = pFuM_B.VEMS_vidGET9[(locali)];
    }

    pFuM_B.Assignment4[pFuM_B.VEMS_vidGET_b - 1] = pFuM_B.VEMS_vidGET5;

    /* S-Function "vems_vidSET" Block: <S425>/VEMS_vidSET6 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjS1Cyl, 6, pFuM_B.Assignment1);

    /* S-Function "vems_vidSET" Block: <S425>/VEMS_vidSET7 */
    VEMS_vidSET1DArray(FuSysM_prm_pFuEstimInjS2Cyl, 6, pFuM_B.Assignment4);
  }

  /* end of Outputs for SubSystem: '<S418>/F02_pFuMSyncEveInj' */
}

/* Start for exported function: FuSysM_EveInj_pFuM */
void FuSysM_EveInj_pFuM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S6>/fc_demux2'
   */

  /* Start for S-Function (fcncallgen): '<S11>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S7>/F02_pFuSyncIn_EveInj'
   *  Start for SubSystem: '<S8>/F02_PFuMdl'
   *  Start for SubSystem: '<S9>/F02_pFuMSyncEveInj'
   */
}

/* Output and update for exported function: FuSysM_EveInj_pFuM */
void FuSysM_EveInj_pFuM(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S6>/fc_demux2'
   */

  /* S-Function (fcncallgen): '<S11>/Function-Call Generator' incorporates:
   *  SubSystem: '<S7>/F02_pFuSyncIn_EveInj'
   *  SubSystem: '<S9>/F02_pFuMSyncEveInj'
   */
  pFuM_F02_pFuSyncIn_EveInj();
  pFuM_ASYNC3(0);
  pFuM_F02_pFuMSyncEveInj();
}

/* Output and update for function-call system: '<S7>/F01_pFuSyncIn_EveClcn' */
void pFuM_F01_pFuSyncIn_EveClcn(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable_nq;
  Float32 localDataTypeConversion;
  Float32 localDataTypeConversion15;
  Float32 localDataTypeConversion9_k;
  Float32 localDataTypeConversion14_c;
  UInt16 localSelector8;
  UInt16 localSelector7_k;
  UInt16 localSelector6_g;
  Float32 locallocalAdd1_ja_idx;
  Float32 locallocalAdd1_ja_idx_0;
  Float32 locallocalAdd1_ja_idx_1;
  Float32 locallocalAdd1_ja_idx_2;
  Float32 locallocalAdd26_d_idx;
  Float32 locallocalAdd26_d_idx_0;
  Float32 locallocalAdd26_d_idx_1;
  Float32 locallocalAdd26_d_idx_2;
  Float32 locallocalAdd32_m_idx;
  Float32 locallocalAdd7_b_idx;
  Float32 locallocalAdd7_b_idx_0;
  Float32 locallocalAdd7_b_idx_1;

  /* Outputs for enable SubSystem: '<S15>/F01_pFuSyncIn_EveClcn' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S17>/Enable'
   *  RelationalOperator: '<S15>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
     *  Constant: '<S17>/FuSysM_agConvInjHRef_C'
     */
    localDataTypeConversion = ((Float32)FuSysM_agConvInjHRef_C) * 0.09375F;

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, pFuM_B.VEMS_vidGET4_d);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_noInNxtCyl, pFuM_B.VEMS_vidGET2_j);

    /* Selector: '<S17>/Selector24' */
    localSelector8 = pFuM_B.VEMS_vidGET4_d[pFuM_B.VEMS_vidGET2_j - 1];

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, pFuM_B.VEMS_vidGET8_g);

    /* Selector: '<S17>/Selector11' */
    localSelector7_k = pFuM_B.VEMS_vidGET8_g[pFuM_B.VEMS_vidGET2_j - 1];

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, pFuM_B.VEMS_vidGET5_n);

    /* Selector: '<S17>/Selector12' */
    localSelector6_g = pFuM_B.VEMS_vidGET5_n[pFuM_B.VEMS_vidGET2_j - 1];

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, pFuM_B.VEMS_vidGET9_gc);

    /* Sum: '<S17>/Add1' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion12'
     *  Selector: '<S17>/Selector13'
     */
    locallocalAdd1_ja_idx_2 = localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET9_gc[pFuM_B.VEMS_vidGET2_j - 1]) * 0.0625F);

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_nEng, pFuM_B.VEMS_vidGET3);

    /* DataTypeConversion Block: '<S18>/Data Type Conversion'
     *
     * Regarding '<S18>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Lookup: '<S18>/Look-Up Table'
     * About '<S18>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_nq), (&(FuSysM_agDlyInj_T[0])),
                   pFuM_B.VEMS_vidGET3, (&(FuSysM_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S18>/Data Type Duplicate1'
     *
     * Regarding '<S18>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S17>/Data Type Conversion15' incorporates:
     *  Lookup: '<S18>/Look-Up Table'
     */
    localDataTypeConversion15 = ((Float32)localLookUpTable_nq) * 0.09375F;

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET */
    VEMS_vidGET(Eng_noCmprCyl, pFuM_B.VEMS_vidGET_n);

    /* Sum: '<S17>/Add26' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion10'
     *  Selector: '<S17>/Selector1'
     *  Selector: '<S17>/Selector2'
     *  Selector: '<S17>/Selector3'
     *  Selector: '<S17>/Selector4'
     */
    locallocalAdd26_d_idx = localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET4_d[pFuM_B.VEMS_vidGET_n - 1]) * 0.0625F);
    locallocalAdd26_d_idx_0 = localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET8_g[pFuM_B.VEMS_vidGET_n - 1]) * 0.0625F);
    locallocalAdd26_d_idx_1 = localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET5_n[pFuM_B.VEMS_vidGET_n - 1]) * 0.0625F);
    locallocalAdd26_d_idx_2 = localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET9_gc[pFuM_B.VEMS_vidGET_n - 1]) * 0.0625F);

    /* DataTypeConversion: '<S17>/Data Type Conversion9' incorporates:
     *  Constant: '<S17>/FuSysM_agPerInjRef_C'
     */
    localDataTypeConversion9_k = ((Float32)FuSysM_agPerInjRef_C) * 0.09375F;

    /* Sum: '<S17>/Add3' incorporates:
     *  Sum: '<S17>/Add2'
     */
    locallocalAdd1_ja_idx = ((localDataTypeConversion - (((Float32)
      localSelector8) * 0.0625F)) + localDataTypeConversion15) +
      localDataTypeConversion9_k;
    locallocalAdd1_ja_idx_0 = ((localDataTypeConversion - (((Float32)
      localSelector7_k) * 0.0625F)) + localDataTypeConversion15) +
      localDataTypeConversion9_k;
    locallocalAdd1_ja_idx_1 = ((localDataTypeConversion - (((Float32)
      localSelector6_g) * 0.0625F)) + localDataTypeConversion15) +
      localDataTypeConversion9_k;

    /* DataTypeConversion: '<S17>/Data Type Conversion14' incorporates:
     *  Constant: '<S17>/FuSysM_agConvInjSRef_C'
     */
    localDataTypeConversion14_c = ((Float32)FuSysM_agConvInjSRef_C) * 0.09375F;

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, pFuM_B.VEMS_vidGET6_i);

    /* Selector: '<S17>/Selector9' */
    localSelector8 = pFuM_B.VEMS_vidGET6_i[pFuM_B.VEMS_vidGET_n - 1];

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, pFuM_B.VEMS_vidGET10_j);

    /* Selector: '<S17>/Selector10' */
    localSelector6_g = pFuM_B.VEMS_vidGET10_j[pFuM_B.VEMS_vidGET_n - 1];

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, pFuM_B.VEMS_vidGET7_d);

    /* Selector: '<S17>/Selector14' */
    localSelector7_k = pFuM_B.VEMS_vidGET7_d[pFuM_B.VEMS_vidGET_n - 1];

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6, pFuM_B.VEMS_vidGET11_o);

    /* Sum: '<S17>/Add32' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion13'
     *  Selector: '<S17>/Selector15'
     *  Sum: '<S17>/Add30'
     */
    locallocalAdd32_m_idx = (localDataTypeConversion14_c - (((Float32)
      pFuM_B.VEMS_vidGET11_o[pFuM_B.VEMS_vidGET_n - 1]) * 0.09375F)) +
      localDataTypeConversion15;

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInCyl, pFuM_B.VEMS_vidGET1_h);

    /* Sum: '<S17>/Add7' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion11'
     *  Selector: '<S17>/Selector5'
     *  Selector: '<S17>/Selector6'
     *  Selector: '<S17>/Selector7'
     *  Selector: '<S17>/Selector8'
     *  Sum: '<S17>/Add4'
     */
    locallocalAdd7_b_idx = (localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET4_d[pFuM_B.VEMS_vidGET1_h - 1]) * 0.0625F)) +
      localDataTypeConversion15;
    locallocalAdd7_b_idx_0 = (localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET8_g[pFuM_B.VEMS_vidGET1_h - 1]) * 0.0625F)) +
      localDataTypeConversion15;
    locallocalAdd7_b_idx_1 = (localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET5_n[pFuM_B.VEMS_vidGET1_h - 1]) * 0.0625F)) +
      localDataTypeConversion15;
    localDataTypeConversion = (localDataTypeConversion - (((Float32)
      pFuM_B.VEMS_vidGET9_gc[pFuM_B.VEMS_vidGET1_h - 1]) * 0.0625F)) +
      localDataTypeConversion15;

    /* Sum: '<S17>/Add8' incorporates:
     *  Sum: '<S17>/Add31'
     */
    locallocalAdd26_d_idx = (localDataTypeConversion15 + locallocalAdd26_d_idx)
      - localDataTypeConversion9_k;
    locallocalAdd26_d_idx_0 = (localDataTypeConversion15 +
      locallocalAdd26_d_idx_0) - localDataTypeConversion9_k;
    locallocalAdd26_d_idx_1 = (localDataTypeConversion15 +
      locallocalAdd26_d_idx_1) - localDataTypeConversion9_k;

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH2ReqCyl, 6, pFuM_B.VEMS_vidGET13);

    /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
     *  Selector: '<S17>/Selector19'
     */
    FuSysM_mFuReqInjH2 = ((Float32)pFuM_B.VEMS_vidGET13[pFuM_B.VEMS_vidGET1_h -
                          1]) * 7.450580597E-009F;

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET14 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS1ReqCyl, 6, pFuM_B.VEMS_vidGET14);

    /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
     *  Selector: '<S17>/Selector22'
     */
    FuSysM_mFuReqInjS1 = ((Float32)pFuM_B.VEMS_vidGET14[pFuM_B.VEMS_vidGET_n -
                          1]) * 7.450580597E-009F;

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET15 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjS2ReqCyl, 6, pFuM_B.VEMS_vidGET15);

    /* DataTypeConversion: '<S17>/Data Type Conversion3' incorporates:
     *  Selector: '<S17>/Selector23'
     */
    FuSysM_mFuReqInjS2 = ((Float32)pFuM_B.VEMS_vidGET15[pFuM_B.VEMS_vidGET_n -
                          1]) * 7.450580597E-009F;

    /* DataTypeConversion: '<S17>/Data Type Conversion4' incorporates:
     *  Selector: '<S17>/Selector20'
     */
    FuSysM_mFuReqInjH2Prev = ((Float32)
      pFuM_B.VEMS_vidGET13[pFuM_B.VEMS_vidGET_n - 1]) * 7.450580597E-009F;

    /* S-Function "vems_vidGET" Block: <S17>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_mFuInjH1ReqCyl, 6, pFuM_B.VEMS_vidGET12_j);

    /* DataTypeConversion: '<S17>/Data Type Conversion5' incorporates:
     *  Selector: '<S17>/Selector16'
     */
    FuSysM_mFuReqInjH1 = ((Float32)pFuM_B.VEMS_vidGET12_j[pFuM_B.VEMS_vidGET1_h
                          - 1]) * 7.450580597E-009F;

    /* DataTypeConversion: '<S17>/Data Type Conversion6' incorporates:
     *  Selector: '<S17>/Selector21'
     */
    FuSysM_mFuReqInjH2Nxt = ((Float32)
      pFuM_B.VEMS_vidGET13[pFuM_B.VEMS_vidGET2_j - 1]) * 7.450580597E-009F;

    /* DataTypeConversion: '<S17>/Data Type Conversion7' incorporates:
     *  Selector: '<S17>/Selector17'
     */
    FuSysM_mFuReqInjH1Prev = ((Float32)
      pFuM_B.VEMS_vidGET12_j[pFuM_B.VEMS_vidGET_n - 1]) * 7.450580597E-009F;

    /* DataTypeConversion: '<S17>/Data Type Conversion8' incorporates:
     *  Selector: '<S17>/Selector18'
     */
    FuSysM_mFuReqInjH1Nxt = ((Float32)
      pFuM_B.VEMS_vidGET12_j[pFuM_B.VEMS_vidGET2_j - 1]) * 7.450580597E-009F;

    /* SignalConversion: '<S17>/Signal Conversion' */
    FuSysM_agBegInjH1RefPrev = locallocalAdd26_d_idx;

    /* SignalConversion: '<S17>/Signal Conversion1' */
    FuSysM_agEndInjH1RefPrev = locallocalAdd26_d_idx_0;

    /* SignalConversion: '<S17>/Signal Conversion10' */
    FuSysM_agBegInjH2RefNxt = locallocalAdd1_ja_idx_1;

    /* SignalConversion: '<S17>/Signal Conversion11' */
    FuSysM_agEndInjH2RefNxt = (localDataTypeConversion15 +
      locallocalAdd1_ja_idx_2) + localDataTypeConversion9_k;

    /* SignalConversion: '<S17>/Signal Conversion12' */
    FuSysM_agBegInjS1Ref = (localDataTypeConversion14_c - (((Float32)
      localSelector8) * 0.09375F)) + localDataTypeConversion15;

    /* SignalConversion: '<S17>/Signal Conversion13' */
    FuSysM_agEndInjS1Ref = (localDataTypeConversion14_c - (((Float32)
      localSelector6_g) * 0.09375F)) + localDataTypeConversion15;

    /* SignalConversion: '<S17>/Signal Conversion14' */
    FuSysM_agBegInjS2Ref = (localDataTypeConversion14_c - (((Float32)
      localSelector7_k) * 0.09375F)) + localDataTypeConversion15;

    /* SignalConversion: '<S17>/Signal Conversion15' */
    FuSysM_agEndInjS2Ref = locallocalAdd32_m_idx;

    /* SignalConversion: '<S17>/Signal Conversion2' */
    FuSysM_agBegInjH2RefPrev = locallocalAdd26_d_idx_1;

    /* SignalConversion: '<S17>/Signal Conversion3' */
    FuSysM_agEndInjH2RefPrev = (localDataTypeConversion15 +
      locallocalAdd26_d_idx_2) - localDataTypeConversion9_k;

    /* SignalConversion: '<S17>/Signal Conversion4' */
    FuSysM_agBegInjH1Ref = locallocalAdd7_b_idx;

    /* SignalConversion: '<S17>/Signal Conversion5' */
    FuSysM_agEndInjH1Ref = locallocalAdd7_b_idx_0;

    /* SignalConversion: '<S17>/Signal Conversion6' */
    FuSysM_agBegInjH2Ref = locallocalAdd7_b_idx_1;

    /* SignalConversion: '<S17>/Signal Conversion7' */
    FuSysM_agEndInjH2Ref = localDataTypeConversion;

    /* SignalConversion: '<S17>/Signal Conversion8' */
    FuSysM_agBegInjH1RefNxt = locallocalAdd1_ja_idx;

    /* SignalConversion: '<S17>/Signal Conversion9' */
    FuSysM_agEndInjH1RefNxt = locallocalAdd1_ja_idx_0;
  }

  /* end of Outputs for SubSystem: '<S15>/F01_pFuSyncIn_EveClcn' */
}

/* Start for exported function: FuSysM_EveSpl_pFuM */
void FuSysM_EveSpl_pFuM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S6>/fc_demux1'
   */
}

/* Output and update for exported function: FuSysM_EveSpl_pFuM */
void FuSysM_EveSpl_pFuM(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S6>/fc_demux1'
   */

  /* S-Function (fcncallgen): '<S10>/Function-Call Generator' incorporates:
   *  SubSystem: '<S7>/F01_pFuSyncIn_EveClcn'
   *  SubSystem: '<S8>/F03_FctEveSpl'
   */
  pFuM_F01_pFuSyncIn_EveClcn();

  /* Outputs for enable SubSystem: '<S25>/F03_FctEveSpl' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Constant: '<S25>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S412>/Enable'
   *  RelationalOperator: '<S25>/Relational Operator'
   */
  if (PFUM_u8Inhib != 90) {
    /* Outputs for enable SubSystem: '<S412>/F01_EveSpl' incorporates:
     *  EnablePort: '<S413>/Enable'
     *  Inport: '<Root>/FRM_bAcvPFuMDftMod'
     *  Logic: '<S412>/Logical Operator'
     */
    if (!GDGAR_bGetFRM(FRM_FRM_ACVPFUMDFTMOD)) {
      /* S-Function (fcncallgen): '<S413>/Function-Call Generator' */
      pFuM_ASYNC3(1);
    }

    /* end of Outputs for SubSystem: '<S412>/F01_EveSpl' */
  }

  /* end of Outputs for SubSystem: '<S25>/F03_FctEveSpl' */
  pFuM_ASYNC2(1);
}

/* Model initialize function */
void pFuM_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  FuSysM_EveRst_pFuM_Start();
  FuSysM_EveCkSnOn_pFuM_Start();
  FuSysM_SdlFast_pFuM_Start();
  FuSysM_EveInj_pFuM_Start();
  FuSysM_EveSpl_pFuM_Start();
}

#define PFUM_STOP_SEC_CODE
#include "pFuM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
