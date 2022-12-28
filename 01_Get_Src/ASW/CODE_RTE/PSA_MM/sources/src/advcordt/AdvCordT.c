/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvCordT                                                */
/* !Description     : AdvCordT Software Component                             */
/*                                                                            */
/* !Module          : AdvCordT                                                */
/* !Description     : AdvCordT Software Component                             */
/*                                                                            */
/* !File            : AdvCordT.c                                              */
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
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AdvCordT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /AdvCordT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M07-AdvCordT/5-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvCordT.h"
#include "AdvCordT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AdvCordT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvCordT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AdvCordT AdvCordT_B;

/* Block states (auto storage) */
D_Work_AdvCordT AdvCordT_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_AdvCordT AdvCordT_PrevZCSigState;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvCordT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define ADVCORDT_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define ADVCORDT_VEMSRTLIBT_MINOR_VERSION_REQ 4
#define ADVCORDT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define ADVCORDT_VEMSRTLIBT_VERSION_REQ (ADVCORDT_VEMSRTLIBT_PATCH_VERSION_REQ + ADVCORDT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + ADVCORDT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if ADVCORDT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AdvCordT_START_SEC_CODE
#include "AdvCordT_MemMap.h"

void AdvCordT_ASYNC1(int controlPortIdx)
{
}

void AdvCordT_ASYNC2(int controlPortIdx)
{
}

void AdvCordT_ASYNC3(int controlPortIdx)
{
}

void AdvCordT_ASYNC4(int controlPortIdx)
{
}

void AdvCordT_ASYNC5(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S1>/F01_IgAdvMap' */
void AdvCordT_F01_IgAdvMap(void)
{
  /* SignalConversion: '<S31>/copy' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  IgSys_agIgOfsTest_IRV_MP = 266U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S31>/autosar_testpoint1' */

  /* S-Function Block: <S31>/autosar_testpoint1 */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgOfsTest_irvInport2' incorporates:
   *  Constant: '<S8>/Constant4'
   *  SignalConversion: '<S8>/SignalConversion'
   */
  Rte_IrvWrite_RE_AdvCordT_001_MSE_IgSys_agIgOfsTest_irv(266U);

  /* SignalConversion: '<S24>/copy' incorporates:
   *  Constant: '<S8>/Constant3'
   */
  IgSys_agIgTest_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S24>/autosar_testpoint1' */

  /* S-Function Block: <S24>/autosar_testpoint1 */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgTest_irvInport2' incorporates:
   *  Constant: '<S8>/Constant3'
   *  SignalConversion: '<S8>/SignalConversion1'
   */
  Rte_IrvWrite_RE_AdvCordT_001_MSE_IgSys_agIgTest_irv(96U);

  /* SignalConversion: '<S25>/copy' incorporates:
   *  Constant: '<S8>/Constant5'
   */
  IgSys_prm_agIgTestCyl_001_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S25>/autosar_testpoint1' */

  /* S-Function Block: <S25>/autosar_testpoint1 */

  /* SignalConversion: '<S26>/copy' incorporates:
   *  Constant: '<S8>/Constant5'
   */
  IgSys_prm_agIgTestCyl_002_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S26>/autosar_testpoint1' */

  /* S-Function Block: <S26>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/copy' incorporates:
   *  Constant: '<S8>/Constant5'
   */
  IgSys_prm_agIgTestCyl_003_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S27>/autosar_testpoint1' */

  /* S-Function Block: <S27>/autosar_testpoint1 */

  /* SignalConversion: '<S28>/copy' incorporates:
   *  Constant: '<S8>/Constant5'
   */
  IgSys_prm_agIgTestCyl_004_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S28>/autosar_testpoint1' */

  /* S-Function Block: <S28>/autosar_testpoint1 */

  /* SignalConversion: '<S29>/copy' incorporates:
   *  Constant: '<S8>/Constant5'
   */
  IgSys_prm_agIgTestCyl_005_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S29>/autosar_testpoint1' */

  /* S-Function Block: <S29>/autosar_testpoint1 */

  /* SignalConversion: '<S30>/copy' incorporates:
   *  Constant: '<S8>/Constant5'
   */
  IgSys_prm_agIgTestCyl_006_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S30>/autosar_testpoint1' */

  /* S-Function Block: <S30>/autosar_testpoint1 */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_001_irvInport2' incorporates:
   *  Constant: '<S8>/Constant5'
   *  SignalConversion: '<S8>/SignalConversion6'
   */
  Rte_IrvWrite_RE_AdvCordT_001_MSE_IgSys_prm_agIgTestCyl_001_irv(96U);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_002_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_001_MSE_IgSys_prm_agIgTestCyl_002_irv(96U);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_003_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_001_MSE_IgSys_prm_agIgTestCyl_003_irv(96U);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_004_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_001_MSE_IgSys_prm_agIgTestCyl_004_irv(96U);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_005_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_001_MSE_IgSys_prm_agIgTestCyl_005_irv(96U);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_006_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_001_MSE_IgSys_prm_agIgTestCyl_006_irv(96U);
}

/* Output and update for exported function: RE_AdvCordT_001_MSE */
void RE_AdvCordT_001_MSE(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_IgAdvMap'
   *
   * Block requirements for '<S1>/F01_IgAdvMap':
   *  1. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_069.01 ;
   *  2. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_052.03 ;
   *  3. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_053.02 ;
   *  4. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_054.02 ;
   *  5. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_055.02 ;
   *  6. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_056.02 ;
   *  7. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_057.02 ;
   *  8. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_058.02 ;
   *  9. SubSystem "F01_IgAdvMap" !Trace_To : VEMS_R_10_06425_059.02 ;
   */
  AdvCordT_F01_IgAdvMap();
}

/* Output and update for function-call system: '<S1>/F01_AdvCordT_Init' */
void AdvCordT_F01_AdvCordT_Init(void)
{
  UInt8 localIgSys_agIgDynIgSpEfc;
  UInt8 localIgSys_prm_agIgLimKnk[6];
  SInt32 locali;

  /* user code (Output function Body for TID9) */
  Runnable_AdvCordT_Init();

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Byp_Fonction_SC'
   *  Constant: '<S17>/Int_BypC'
   *  Constant: '<S7>/Constant13'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localIgSys_agIgDynIgSpEfc = IgSys_agIgDynIgSpEfc_B;
  } else {
    localIgSys_agIgDynIgSpEfc = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgDynIgSpEfcInport2' */
  Rte_Write_P_IgSys_agIgDynIgSpEfc_IgSys_agIgDynIgSpEfc
    (localIgSys_agIgDynIgSpEfc);

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Byp_Fonction_SC'
   *  Constant: '<S18>/Int_BypC'
   *  Constant: '<S7>/Constant2'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localIgSys_agIgDynIgSpEfc = IgSys_agIgLimKnkMax_B;
  } else {
    localIgSys_agIgDynIgSpEfc = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgLimKnkMaxInport2' */
  Rte_Write_P_IgSys_agIgLimKnkMax_IgSys_agIgLimKnkMax(localIgSys_agIgDynIgSpEfc);

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Byp_Fonction_SC'
   *  Constant: '<S19>/Int_BypC'
   *  Constant: '<S7>/Constant3'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localIgSys_agIgDynIgSpEfc = IgSys_agIgLimKnkMin_B;
  } else {
    localIgSys_agIgDynIgSpEfc = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgLimKnkMinInport2' */
  Rte_Write_P_IgSys_agIgLimKnkMin_IgSys_agIgLimKnkMin(localIgSys_agIgDynIgSpEfc);

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Byp_Fonction_SC'
   *  Constant: '<S20>/Int_BypC'
   *  Constant: '<S7>/Constant4'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localIgSys_agIgDynIgSpEfc = IgSys_agIgLimKnkMv_B;
  } else {
    localIgSys_agIgDynIgSpEfc = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgLimKnkMvInport2' */
  Rte_Write_P_IgSys_agIgLimKnkMv_IgSys_agIgLimKnkMv(localIgSys_agIgDynIgSpEfc);

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Byp_Fonction_SC'
   *  Constant: '<S21>/Int_BypC'
   *  Constant: '<S7>/Constant5'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localIgSys_agIgDynIgSpEfc = IgSys_agIgMax_B;
  } else {
    localIgSys_agIgDynIgSpEfc = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgMaxInport2' */
  Rte_Write_P_IgSys_agIgMax_IgSys_agIgMax(localIgSys_agIgDynIgSpEfc);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Byp_Fonction_SC'
   *  Constant: '<S22>/Int_BypC'
   *  Constant: '<S7>/Constant6'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localIgSys_agIgDynIgSpEfc = IgSys_agIgSp_B;
  } else {
    localIgSys_agIgDynIgSpEfc = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgSpInport2' */
  Rte_Write_P_IgSys_agIgSp_IgSys_agIgSp(localIgSys_agIgDynIgSpEfc);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Byp_Fonction_SC'
   *  Constant: '<S23>/Int_BypC'
   *  Constant: '<S7>/Constant7'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localIgSys_agIgDynIgSpEfc = IgSys_agIgSpNxt_B;
  } else {
    localIgSys_agIgDynIgSpEfc = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgSpNxtInport2' */
  Rte_Write_P_IgSys_agIgSpNxt_IgSys_agIgSpNxt(localIgSys_agIgDynIgSpEfc);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Byp_Fonction_SC'
   *  Constant: '<S15>/Int_BypC'
   *  Constant: '<S7>/Constant8'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localIgSys_agIgDynIgSpEfc = IgSys_agIgSpWoutKnkDet_B;
  } else {
    localIgSys_agIgDynIgSpEfc = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgSpWoutKnkDetInport2' */
  Rte_Write_P_IgSys_agIgSpWoutKnkDet_IgSys_agIgSpWoutKnkDet
    (localIgSys_agIgDynIgSpEfc);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Byp_Fonction_SC'
   *  Constant: '<S16>/Int_BypC'
   *  Constant: '<S7>/Constant9'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localIgSys_prm_agIgLimKnk[locali] = IgSys_prm_agIgLimKnk_B[(locali)];
    }
  } else {
    localIgSys_prm_agIgLimKnk[0] = 96U;
    localIgSys_prm_agIgLimKnk[1] = 96U;
    localIgSys_prm_agIgLimKnk[2] = 96U;
    localIgSys_prm_agIgLimKnk[3] = 96U;
    localIgSys_prm_agIgLimKnk[4] = 96U;
    localIgSys_prm_agIgLimKnk[5] = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_prm_agIgLimKnkInport2' */
  Rte_Write_P_IgSys_prm_agIgLimKnk_IgSys_prm_agIgLimKnk
    (&localIgSys_prm_agIgLimKnk);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Byp_Fonction_SC'
   *  Constant: '<S12>/Int_BypC'
   *  Constant: '<S7>/Constant10'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localIgSys_prm_agIgLimKnk[locali] = IgSys_prm_agIgSpCyl_B[(locali)];
    }
  } else {
    localIgSys_prm_agIgLimKnk[0] = 96U;
    localIgSys_prm_agIgLimKnk[1] = 96U;
    localIgSys_prm_agIgLimKnk[2] = 96U;
    localIgSys_prm_agIgLimKnk[3] = 96U;
    localIgSys_prm_agIgLimKnk[4] = 96U;
    localIgSys_prm_agIgLimKnk[5] = 96U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_prm_agIgSpCylInport2' */
  Rte_Write_P_IgSys_prm_agIgSpCyl_IgSys_prm_agIgSpCyl(&localIgSys_prm_agIgLimKnk);

  /* SignalConversion: '<S13>/copy' incorporates:
   *  Constant: '<S7>/Cste_0'
   */
  IgSys_agIgOfsPrev_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S13>/autosar_testpoint1' */

  /* S-Function Block: <S13>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgOfsPrev_irvInport2' incorporates:
   *  Constant: '<S7>/Cste_0'
   *  SignalConversion: '<S7>/SignalConversion3'
   */
  Rte_IrvWrite_RE_AdvCordT_003_MSE_IgSys_agIgOfsPrev_irv(96U);

  /* SignalConversion: '<S14>/copy' incorporates:
   *  Constant: '<S7>/Cste_1'
   */
  IgSys_agIgMaxWiPrevAdpCyl_IRV_MP = 96U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S14>/autosar_testpoint1' */

  /* S-Function Block: <S14>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevAdpCyl_irvInport2' incorporates:
   *  Constant: '<S7>/Cste_1'
   *  SignalConversion: '<S7>/SignalConversion5'
   */
  Rte_IrvWrite_RE_AdvCordT_003_MSE_IgSys_agIgMaxWiPrevAdpCyl_irv(96U);
}

/* Output and update for exported function: RE_AdvCordT_003_MSE */
void RE_AdvCordT_003_MSE(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_AdvCordT_Init'
   *
   * Block requirements for '<S1>/F01_AdvCordT_Init':
   *  1. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_004.02 ;
   *  2. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_005.02 ;
   *  3. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_009.02 ;
   *  4. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_023.02 ;
   *  5. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_024.02 ;
   *  6. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_025.02 ;
   *  7. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_027.02 ;
   *  8. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_028.02 ;
   *  9. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_046.02 ;
   *  10. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_047.02 ;
   *  11. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_048.02 ;
   *  12. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_049.01 ;
   *  13. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_051.02 ;
   *  14. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_060.02 ;
   *  15. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_067.02 ;
   *  16. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_071.01 ;
   *  17. SubSystem "F01_AdvCordT_Init" !Trace_To : VEMS_R_10_06425_050.03 ;
   */
  AdvCordT_F01_AdvCordT_Init();
}

/* Output and update for function-call system: '<S1>/F02_IgAdvMap' */
void AdvCordT_F02_IgAdvMap(void)
{
  /* local block i/o variables */
  UInt16 localMerge1;
  UInt8 localMerge2[6];
  UInt8 localMerge;
  Boolean localTmpSignalConversionAtIgS_m;
  SInt16 localTmpSignalConversionAtExt_p;
  Float32 localAdd2;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localTmpSignalConversionAtEngM_;
  UInt8 localIgSys_agIgTest_irv_h;
  UInt8 localIgSys_prm_agIgTestCyl_00_m;
  UInt8 localIgSys_prm_agIgTestCyl_00_c;
  UInt8 localIgSys_prm_agIgTestCyl_00_d;
  UInt8 localIgSys_prm_agIgTestCyl_00_e;
  UInt8 localIgSys_prm_agIgTestCyl_00_b;
  UInt8 localIgSys_prm_agIgTestCyl_00_a;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_pDsThrMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_pDsThrMes'
   */
  Rte_Read_R_Ext_pDsThrMes_Ext_pDsThrMes(&localTmpSignalConversionAtExt_p);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIgS_m);

  /* If: '<S9>/If' incorporates:
   *  ActionPort: '<S40>/Action Port'
   *  ActionPort: '<S41>/Action Port'
   *  SubSystem: '<S9>/F01_Calcul_avance_MAP'
   *  SubSystem: '<S9>/F02_Calcul_avance_MAP_Default'
   *
   * Block requirements for '<S9>/F01_Calcul_avance_MAP':
   *  1. SubSystem "F01_Calcul_avance_MAP" !Trace_To : VEMS_R_10_06425_003.01 ;
   */
  if (localTmpSignalConversionAtIgS_m) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/IgSys_bAirLdSel_C'
     *  Constant: '<S40>/IgSys_pDsThrMesRef_C'
     *  Constant: '<S40>/constant6'
     *  DataTypeConversion: '<S40>/Data Type Conversion2'
     *  DataTypeConversion: '<S40>/Data Type Conversion3'
     *  DataTypeConversion: '<S9>/Data Type Conversion19'
     *  MinMax: '<S40>/MinMax3'
     *  Product: '<S45>/Divide'
     */
    if (IgSys_bAirLdSel_C) {
      localAdd2 = ((Float32)localTmpSignalConversionAtExt_p) / ((Float32)
        ((SInt16)rt_MAX(IgSys_pDsThrMesRef_C, 1)));
    } else {
      localAdd2 = ((Float32)localTmpSignalConversionAtEngM_) *
        6.103515625E-005F;
    }

    /* Sum: '<S43>/Add2' incorporates:
     *  Constant: '<S43>/offset'
     *  Constant: '<S43>/offset1'
     *  Constant: '<S43>/one_on_slope'
     *  Product: '<S43>/Product4'
     *  Sum: '<S43>/Add1'
     */
    localAdd2 = (16384.0F * localAdd2) + 0.5F;

    /* DataTypeConversion: '<S43>/OutDTConv' */
    if (localAdd2 < 65536.0F) {
      if (localAdd2 >= 0.0F) {
        localTmpSignalConversionAtEngM_ = (UInt16)localAdd2;
      } else {
        localTmpSignalConversionAtEngM_ = 0U;
      }
    } else {
      localTmpSignalConversionAtEngM_ = MAX_uint16_T;
    }

    /* DataStoreWrite: '<S40>/Data Store Write' */
    IgSys_rAirLdSel_MP = localTmpSignalConversionAtEngM_;

    /* SignalConversion: '<S40>/SignalConversion2' incorporates:
     *  Constant: '<S40>/IgSys_agIgTestCyl1_C'
     *  Constant: '<S40>/IgSys_agIgTestCyl2_C'
     *  Constant: '<S40>/IgSys_agIgTestCyl3_C'
     *  Constant: '<S40>/IgSys_agIgTestCyl4_C'
     *  Constant: '<S40>/IgSys_agIgTestCyl5_C'
     *  Constant: '<S40>/IgSys_agIgTestCyl6_C'
     */
    localMerge2[0] = IgSys_agIgTestCyl1_C;
    localMerge2[1] = IgSys_agIgTestCyl2_C;
    localMerge2[2] = IgSys_agIgTestCyl3_C;
    localMerge2[3] = IgSys_agIgTestCyl4_C;
    localMerge2[4] = IgSys_agIgTestCyl5_C;
    localMerge2[5] = IgSys_agIgTestCyl6_C;

    /* SignalConversion: '<S40>/SignalConversion1' incorporates:
     *  Constant: '<S40>/IgSys_agIgOfsTest_C'
     */
    localMerge1 = IgSys_agIgOfsTest_C;

    /* DataTypeConversion: '<S44>/OutDTConv' incorporates:
     *  Constant: '<S44>/offset'
     *  Constant: '<S44>/offset1'
     *  Constant: '<S44>/one_on_slope'
     *  Lookup_n-D: '<S42>/Lookup Table (n-D)'
     *  Product: '<S44>/Product4'
     *  Sum: '<S44>/Add1'
     *  Sum: '<S44>/Add2'
     */
    localAdd2 = ((look2_iu16u16lftu8n2If_binlcns(localTmpSignalConversionAtEngM_,
      localTmpSignalConversionAtExt_n, (&(IgSys_rAirLdTestX_A[0])),
      (&(IgSys_nCkFilTestY_A[0])), (&(IgSys_agIgTest_M[0])),
      &AdvCordT_ConstP.LookupTablenD_maxInde[0], 16U) - -36.0F) *
                 2.666666746E+000F) + 0.5F;
    if (localAdd2 < 256.0F) {
      if (localAdd2 >= 0.0F) {
        localMerge = (UInt8)localAdd2;
      } else {
        localMerge = 0U;
      }
    } else {
      localMerge = MAX_uint8_T;
    }
  } else {
    /* SignalConversion: '<S41>/SignalConversion2' incorporates:
     *  SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_agIgTest_irv1Outport2'
     */
    localMerge = Rte_IrvRead_RE_AdvCordT_002_DRE_IgSys_agIgTest_irv();

    /* SignalConversion: '<S41>/SignalConversion1' incorporates:
     *  SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_agIgOfsTest_irv1Outport2'
     */
    localMerge1 = Rte_IrvRead_RE_AdvCordT_002_DRE_IgSys_agIgOfsTest_irv();

    /* SignalConversion: '<S41>/SignalConversion' incorporates:
     *  SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_001_irv1Outport2'
     *  SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_002_irv1Outport2'
     *  SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_003_irv1Outport2'
     *  SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_004_irv1Outport2'
     *  SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_005_irv1Outport2'
     *  SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_006_irv1Outport2'
     */
    localMerge2[0] =
      Rte_IrvRead_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_001_irv();
    localMerge2[1] =
      Rte_IrvRead_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_002_irv();
    localMerge2[2] =
      Rte_IrvRead_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_003_irv();
    localMerge2[3] =
      Rte_IrvRead_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_004_irv();
    localMerge2[4] =
      Rte_IrvRead_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_005_irv();
    localMerge2[5] =
      Rte_IrvRead_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_006_irv();
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S32>/autosar_testpoint1' */

  /* S-Function Block: <S32>/autosar_testpoint1 */
  IgSys_prm_agIgTestCyl_001_IRV_MP = localMerge2[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S33>/autosar_testpoint1' */

  /* S-Function Block: <S33>/autosar_testpoint1 */
  IgSys_agIgTest_IRV_MP = localMerge;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S34>/autosar_testpoint1' */

  /* S-Function Block: <S34>/autosar_testpoint1 */
  IgSys_prm_agIgTestCyl_002_IRV_MP = localMerge2[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S35>/autosar_testpoint1' */

  /* S-Function Block: <S35>/autosar_testpoint1 */
  IgSys_prm_agIgTestCyl_003_IRV_MP = localMerge2[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S36>/autosar_testpoint1' */

  /* S-Function Block: <S36>/autosar_testpoint1 */
  IgSys_prm_agIgTestCyl_004_IRV_MP = localMerge2[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S37>/autosar_testpoint1' */

  /* S-Function Block: <S37>/autosar_testpoint1 */
  IgSys_prm_agIgTestCyl_005_IRV_MP = localMerge2[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S38>/autosar_testpoint1' */

  /* S-Function Block: <S38>/autosar_testpoint1 */
  IgSys_prm_agIgTestCyl_006_IRV_MP = localMerge2[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S39>/autosar_testpoint1' */

  /* S-Function Block: <S39>/autosar_testpoint1 */
  IgSys_agIgOfsTest_IRV_MP = localMerge1;

  /* SignalConversion: '<S9>/SignalConversion1' */
  localIgSys_agIgTest_irv_h = localMerge;

  /* SignalConversion: '<S9>/SignalConversion10' */
  localIgSys_prm_agIgTestCyl_00_m = localMerge2[5];

  /* SignalConversion: '<S9>/SignalConversion2' */
  localIgSys_prm_agIgTestCyl_00_c = localMerge2[1];

  /* SignalConversion: '<S9>/SignalConversion6' */
  localIgSys_prm_agIgTestCyl_00_d = localMerge2[0];

  /* SignalConversion: '<S9>/SignalConversion7' */
  localIgSys_prm_agIgTestCyl_00_e = localMerge2[2];

  /* SignalConversion: '<S9>/SignalConversion8' */
  localIgSys_prm_agIgTestCyl_00_b = localMerge2[3];

  /* SignalConversion: '<S9>/SignalConversion9' */
  localIgSys_prm_agIgTestCyl_00_a = localMerge2[4];

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_agIgOfsTest_irvInport2' incorporates:
   *  SignalConversion: '<S9>/SignalConversion'
   */
  Rte_IrvWrite_RE_AdvCordT_002_DRE_IgSys_agIgOfsTest_irv(localMerge1);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_agIgTest_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_002_DRE_IgSys_agIgTest_irv(localIgSys_agIgTest_irv_h);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_001_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_001_irv
    (localIgSys_prm_agIgTestCyl_00_d);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_002_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_002_irv
    (localIgSys_prm_agIgTestCyl_00_c);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_003_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_003_irv
    (localIgSys_prm_agIgTestCyl_00_e);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_004_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_004_irv
    (localIgSys_prm_agIgTestCyl_00_b);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_005_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_005_irv
    (localIgSys_prm_agIgTestCyl_00_a);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_006_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_002_DRE_IgSys_prm_agIgTestCyl_006_irv
    (localIgSys_prm_agIgTestCyl_00_m);
}

/* Output and update for exported function: RE_AdvCordT_002_DRE */
void RE_AdvCordT_002_DRE(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_IgAdvMap'
   *
   * Block requirements for '<S1>/F02_IgAdvMap':
   *  1. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_001.01 ;
   *  2. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_070.02 ;
   *  3. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_018.02 ;
   *  4. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_019.01 ;
   *  5. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_020.01 ;
   *  6. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_022.01 ;
   *  7. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_052.03 ;
   *  8. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_053.02 ;
   *  9. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_054.02 ;
   *  10. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_055.02 ;
   *  11. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_056.02 ;
   *  12. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_057.02 ;
   *  13. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_058.02 ;
   *  14. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_059.02 ;
   *  15. SubSystem "F02_IgAdvMap" !Trace_To : VEMS_R_10_06425_002.01 ;
   */
  AdvCordT_F02_IgAdvMap();
}

/* Output and update for function-call system: '<S1>/F03_coordination_Avance_maxi_trig' */
void F03_coordination_Avance_maxi_tr(void)
{
  /* local block i/o variables */
  UInt8 localOutDTConv_m;
  Float32 localDataTypeConversion4;
  Float32 localDivide_h[6];
  Float32 localAdd2_e;
  Float32 localDivide_d[6];
  Float32 localSum3[6];
  Float32 localSum5[6];
  UInt8 localTmpSignalConversionAtEng_n;
  UInt32 localAdd;
  Float32 localmin;
  Float32 localmin_0;
  UInt8 localTmpSignalConversionAtKnkMg[6];
  UInt8 localTmpSignalConversionAtKnk_p;
  UInt8 localTmpSignalConversionAtIg_ay[6];
  UInt8 localSwitch;
  UInt8 localSwitch_j;
  UInt8 localTmpSignalConversionAtIg_d0;
  UInt8 localTmpSignalConversionAtIgS_j;
  SInt32 locali;
  Float32 locallocalSum;
  UInt8 locallocalTmpSignalConversionAt;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevAdpMvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMaxWiPrevAdpMv'
   */
  Rte_Read_R_IgSys_agIgMaxWiPrevAdpMv_IgSys_agIgMaxWiPrevAdpMv
    (&locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtKnkMgt_prm_agIgKnkDetOfsCylOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_prm_agIgKnkDetOfsCyl'
   */
  Rte_Read_R_KnkMgt_prm_agIgKnkDetOfsCyl_KnkMgt_prm_agIgKnkDetOfsCyl
    (&localTmpSignalConversionAtKnkMg);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtKnkMgt_agIgOfsKnkDftOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_agIgOfsKnkDft'
   */
  Rte_Read_R_KnkMgt_agIgOfsKnkDft_KnkMgt_agIgOfsKnkDft
    (&localTmpSignalConversionAtKnk_p);

  /* DataTypeConversion: '<S10>/Data Type Conversion4' */
  localDataTypeConversion4 = (((Float32)localTmpSignalConversionAtKnk_p) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_prm_agIgMaxWiPrevAdpCylOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_agIgMaxWiPrevAdpCyl'
   */
  Rte_Read_R_IgSys_prm_agIgMaxWiPrevAdpCyl_IgSys_prm_agIgMaxWiPrevAdpCyl
    (&localTmpSignalConversionAtIg_ay);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEng_noCmprCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprCyl'
   */
  Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl(&localTmpSignalConversionAtEng_n);

  /* Outputs for atomic SubSystem: '<S10>/F01_Limite_cliquetis' *
   * Block requirements for '<S10>/F01_Limite_cliquetis':
   *  1. SubSystem "F01_Limite_cliquetis" !Trace_To : VEMS_R_10_06425_007.02 ;
   */

  /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
   *  Constant: '<S52>/Cste_1_0_0_0_0_0'
   *  Constant: '<S52>/Cste_1_1_0_0_0_0'
   *  Constant: '<S52>/Cste_1_1_1_0_0_0'
   *  Constant: '<S52>/Cste_1_1_1_1_0_0'
   *  Constant: '<S52>/Cste_1_1_1_1_1_0'
   *  Constant: '<S52>/Cste_1_1_1_1_1_1'
   *  Constant: '<S52>/Ext_noCylEng_SC'
   */
  switch (Ext_noCylEng_SC) {
   case 1:
    for (locali = 0; locali < 6; locali++) {
      localDivide_h[locali] = AdvCordT_ConstP.pooled5[(locali)];
    }
    break;

   case 2:
    for (locali = 0; locali < 6; locali++) {
      localDivide_h[locali] = AdvCordT_ConstP.pooled6[(locali)];
    }
    break;

   case 3:
    for (locali = 0; locali < 6; locali++) {
      localDivide_h[locali] = AdvCordT_ConstP.pooled7[(locali)];
    }
    break;

   case 4:
    for (locali = 0; locali < 6; locali++) {
      localDivide_h[locali] = AdvCordT_ConstP.pooled8[(locali)];
    }
    break;

   case 5:
    for (locali = 0; locali < 6; locali++) {
      localDivide_h[locali] = AdvCordT_ConstP.pooled9[(locali)];
    }
    break;

   default:
    for (locali = 0; locali < 6; locali++) {
      localDivide_h[locali] = AdvCordT_ConstP.pooled10[(locali)];
    }
    break;
  }

  /* Product: '<S65>/Divide' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion5'
   */
  for (locali = 0; locali < 6; locali++) {
    localDivide_h[locali] *= (((Float32)localTmpSignalConversionAtKnkMg[locali])
      * 0.375F) - 36.0F;
  }

  /* Sum: '<S52>/Sum2' incorporates:
   *  Constant: '<S52>/Ext_noCylEng_SC'
   *  Product: '<S63>/Divide'
   *  Sum: '<S52>/Sum4'
   */
  localAdd2_e = (-0.0F - ((((((localDivide_h[0] + localDivide_h[1]) +
    localDivide_h[2]) + localDivide_h[3]) + localDivide_h[4]) + localDivide_h[5])
    / ((Float32)Ext_noCylEng_SC))) - localDataTypeConversion4;

  /* DataStoreWrite: '<S52>/Data Store Write' incorporates:
   *  Constant: '<S58>/offset'
   *  Constant: '<S58>/offset1'
   *  Constant: '<S58>/one_on_slope'
   *  DataTypeConversion: '<S58>/OutDTConv'
   *  Product: '<S58>/Product4'
   *  Sum: '<S58>/Add1'
   *  Sum: '<S58>/Add2'
   */
  locallocalSum = ((localAdd2_e - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (locallocalSum < 256.0F) {
    if (locallocalSum >= 0.0F) {
      IgSys_agIgKnkDetOfsCylMv_MP = (UInt8)locallocalSum;
    } else {
      IgSys_agIgKnkDetOfsCylMv_MP = 0U;
    }
  } else {
    IgSys_agIgKnkDetOfsCylMv_MP = MAX_uint8_T;
  }

  /* MultiPortSwitch: '<S52>/Multiport Switch1' incorporates:
   *  Constant: '<S52>/Cste_1_0_0_0_0_0_1'
   *  Constant: '<S52>/Cste_1_1_0_0_0_0_1'
   *  Constant: '<S52>/Cste_1_1_1_0_0_0_1'
   *  Constant: '<S52>/Cste_1_1_1_1_0_0_1'
   *  Constant: '<S52>/Cste_1_1_1_1_1_0_1'
   *  Constant: '<S52>/Cste_1_1_1_1_1_1_1'
   *  Constant: '<S52>/Ext_noCylEng_SC_1'
   */
  switch (Ext_noCylEng_SC) {
   case 1:
    for (locali = 0; locali < 6; locali++) {
      localDivide_d[locali] = AdvCordT_ConstP.pooled5[(locali)];
    }
    break;

   case 2:
    for (locali = 0; locali < 6; locali++) {
      localDivide_d[locali] = AdvCordT_ConstP.pooled6[(locali)];
    }
    break;

   case 3:
    for (locali = 0; locali < 6; locali++) {
      localDivide_d[locali] = AdvCordT_ConstP.pooled7[(locali)];
    }
    break;

   case 4:
    for (locali = 0; locali < 6; locali++) {
      localDivide_d[locali] = AdvCordT_ConstP.pooled8[(locali)];
    }
    break;

   case 5:
    for (locali = 0; locali < 6; locali++) {
      localDivide_d[locali] = AdvCordT_ConstP.pooled9[(locali)];
    }
    break;

   default:
    for (locali = 0; locali < 6; locali++) {
      localDivide_d[locali] = AdvCordT_ConstP.pooled10[(locali)];
    }
    break;
  }

  /* Product: '<S64>/Divide' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion3'
   */
  for (locali = 0; locali < 6; locali++) {
    localDivide_d[locali] *= (((Float32)localTmpSignalConversionAtIg_ay[locali])
      * 0.375F) - 36.0F;
  }

  /* MultiPortSwitch: '<S52>/Multiport Switch2' incorporates:
   *  Constant: '<S52>/Cste_0_0_0_0_0_0'
   *  Constant: '<S52>/Cste_0_0_0_0_0_60'
   *  Constant: '<S52>/Cste_0_0_0_0_60_60'
   *  Constant: '<S52>/Cste_0_0_0_60_60_60'
   *  Constant: '<S52>/Cste_0_0_60_60_60_60'
   *  Constant: '<S52>/Cste_0_60_60_60_60_60'
   *  Constant: '<S52>/Ext_noCylEng_SC_2'
   */
  switch (Ext_noCylEng_SC) {
   case 1:
    for (locali = 0; locali < 6; locali++) {
      localSum3[locali] = AdvCordT_ConstP.Cste_0_60_60_60_60_60[(locali)];
    }
    break;

   case 2:
    for (locali = 0; locali < 6; locali++) {
      localSum3[locali] = AdvCordT_ConstP.Cste_0_0_60_60_60_60_[(locali)];
    }
    break;

   case 3:
    for (locali = 0; locali < 6; locali++) {
      localSum3[locali] = AdvCordT_ConstP.Cste_0_0_0_60_60_60_V[(locali)];
    }
    break;

   case 4:
    for (locali = 0; locali < 6; locali++) {
      localSum3[locali] = AdvCordT_ConstP.Cste_0_0_0_0_60_60_Va[(locali)];
    }
    break;

   case 5:
    for (locali = 0; locali < 6; locali++) {
      localSum3[locali] = AdvCordT_ConstP.Cste_0_0_0_0_0_60_Val[(locali)];
    }
    break;

   default:
    for (locali = 0; locali < 6; locali++) {
      localSum3[locali] = AdvCordT_ConstP.pooled11[(locali)];
    }
    break;
  }

  for (locali = 0; locali < 6; locali++) {
    /* Sum: '<S52>/Sum6' */
    locallocalSum = localDivide_d[locali] + localSum3[locali];

    /* DataStoreWrite: '<S52>/Data Store Write1' incorporates:
     *  Constant: '<S60>/offset'
     *  Constant: '<S60>/offset1'
     *  Constant: '<S60>/one_on_slope'
     *  DataTypeConversion: '<S60>/OutDTConv'
     *  Product: '<S60>/Product4'
     *  Sum: '<S60>/Add1'
     *  Sum: '<S60>/Add2'
     */
    localmin_0 = ((locallocalSum - -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localmin_0 < 256.0F) {
      if (localmin_0 >= 0.0F) {
        localTmpSignalConversionAtKnk_p = (UInt8)localmin_0;
      } else {
        localTmpSignalConversionAtKnk_p = 0U;
      }
    } else {
      localTmpSignalConversionAtKnk_p = MAX_uint8_T;
    }

    IgSys_prm_agIgKnkSatMax_MP[(locali)] = localTmpSignalConversionAtKnk_p;
    localSum3[locali] = locallocalSum;
  }

  /* MultiPortSwitch: '<S52>/Multiport Switch3' incorporates:
   *  Constant: '<S52>/Cste_0_0_0_0_0_0_1'
   *  Constant: '<S52>/Cste_0_0_0_0_0_36'
   *  Constant: '<S52>/Cste_0_0_0_0_36_36'
   *  Constant: '<S52>/Cste_0_0_0_36_36_36'
   *  Constant: '<S52>/Cste_0_0_36_36_36_36'
   *  Constant: '<S52>/Cste_0_36_36_36_36_36'
   *  Constant: '<S52>/Ext_noCylEng_SC_3'
   */
  switch (Ext_noCylEng_SC) {
   case 1:
    for (locali = 0; locali < 6; locali++) {
      localSum5[locali] = AdvCordT_ConstP.Cste_0_36_36_36_36_36[(locali)];
    }
    break;

   case 2:
    for (locali = 0; locali < 6; locali++) {
      localSum5[locali] = AdvCordT_ConstP.Cste_0_0_36_36_36_36_[(locali)];
    }
    break;

   case 3:
    for (locali = 0; locali < 6; locali++) {
      localSum5[locali] = AdvCordT_ConstP.Cste_0_0_0_36_36_36_V[(locali)];
    }
    break;

   case 4:
    for (locali = 0; locali < 6; locali++) {
      localSum5[locali] = AdvCordT_ConstP.Cste_0_0_0_0_36_36_Va[(locali)];
    }
    break;

   case 5:
    for (locali = 0; locali < 6; locali++) {
      localSum5[locali] = AdvCordT_ConstP.Cste_0_0_0_0_0_36_Val[(locali)];
    }
    break;

   default:
    for (locali = 0; locali < 6; locali++) {
      localSum5[locali] = AdvCordT_ConstP.pooled11[(locali)];
    }
    break;
  }

  /* MinMax: '<S52>/MinMax' incorporates:
   *  Sum: '<S52>/Sum3'
   */
  for (locali = 0; locali < 6; locali++) {
    /* Sum: '<S52>/Sum8' */
    locallocalSum = localDivide_d[locali] + localSum5[locali];

    /* DataStoreWrite: '<S52>/Data Store Write2' incorporates:
     *  Constant: '<S59>/offset'
     *  Constant: '<S59>/offset1'
     *  Constant: '<S59>/one_on_slope'
     *  DataTypeConversion: '<S59>/OutDTConv'
     *  Product: '<S59>/Product4'
     *  Sum: '<S59>/Add1'
     *  Sum: '<S59>/Add2'
     */
    localmin_0 = ((locallocalSum - -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localmin_0 < 256.0F) {
      if (localmin_0 >= 0.0F) {
        localTmpSignalConversionAtKnk_p = (UInt8)localmin_0;
      } else {
        localTmpSignalConversionAtKnk_p = 0U;
      }
    } else {
      localTmpSignalConversionAtKnk_p = MAX_uint8_T;
    }

    IgSys_prm_agIgKnkSatMin_MP[(locali)] = localTmpSignalConversionAtKnk_p;

    /* Sum: '<S52>/Sum5' */
    locallocalSum = (locallocalSum - localDivide_h[locali]) -
      localDataTypeConversion4;
    localSum3[locali] = (localSum3[locali] - localDivide_h[locali]) -
      localDataTypeConversion4;
    localSum5[locali] = locallocalSum;
  }

  localmin = rt_MINf(localSum3[0], localSum3[1]);
  localmin = rt_MINf(localmin, localSum3[2]);
  localmin = rt_MINf(localmin, localSum3[3]);
  localmin_0 = rt_MINf(localmin, localSum3[4]);

  /* MinMax: '<S52>/MinMax1' */
  localmin = rt_MAXf(localSum5[0], localSum5[1]);
  localmin = rt_MAXf(localmin, localSum5[2]);
  localmin = rt_MAXf(localmin, localSum5[3]);
  localmin = rt_MAXf(localmin, localSum5[4]);

  /* Sum: '<S57>/Add' incorporates:
   *  Constant: '<S57>/Constant1'
   *  DataTypeConversion: '<S52>/Data Type Conversion3'
   */
  localAdd = ((UInt32)localTmpSignalConversionAtEng_n) - 1U;

  /* DataTypeConversion: '<S61>/OutDTConv' incorporates:
   *  Constant: '<S61>/offset'
   *  Constant: '<S61>/offset1'
   *  Constant: '<S61>/one_on_slope'
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   *  Product: '<S61>/Product4'
   *  Sum: '<S52>/Sum7'
   *  Sum: '<S61>/Add1'
   *  Sum: '<S61>/Add2'
   */
  locallocalSum = (((((((Float32)locallocalTmpSignalConversionAt) * 0.375F) -
                      36.0F) + localAdd2_e) - -36.0F) * 2.666666746E+000F) +
    0.5F;
  if (locallocalSum < 256.0F) {
    if (locallocalSum >= 0.0F) {
      locallocalTmpSignalConversionAt = (UInt8)locallocalSum;
    } else {
      locallocalTmpSignalConversionAt = 0U;
    }
  } else {
    locallocalTmpSignalConversionAt = MAX_uint8_T;
  }

  /* DataTypeConversion: '<S62>/OutDTConv' incorporates:
   *  Constant: '<S57>/Constant'
   *  Constant: '<S62>/offset'
   *  Constant: '<S62>/offset1'
   *  Constant: '<S62>/one_on_slope'
   *  MinMax: '<S57>/MinMax'
   *  Product: '<S62>/Product4'
   *  Selector: '<S57>/Selector'
   *  Sum: '<S62>/Add1'
   *  Sum: '<S62>/Add2'
   */
  locallocalSum = ((localDivide_d[(SInt32)rt_MIN(localAdd, 5U)] - -36.0F) *
                   2.666666746E+000F) + 0.5F;
  if (locallocalSum < 256.0F) {
    if (locallocalSum >= 0.0F) {
      localOutDTConv_m = (UInt8)locallocalSum;
    } else {
      localOutDTConv_m = 0U;
    }
  } else {
    localOutDTConv_m = MAX_uint8_T;
  }

  /* end of Outputs for SubSystem: '<S10>/F01_Limite_cliquetis' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S47>/autosar_testpoint1' */

  /* S-Function Block: <S47>/autosar_testpoint1 */
  IgSys_agIgMaxWiPrevAdpCyl_IRV_MP = localOutDTConv_m;

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Byp_Fonction_SC'
   *  Constant: '<S46>/Int_BypC'
   *  Constant: '<S55>/offset'
   *  Constant: '<S55>/offset1'
   *  Constant: '<S55>/one_on_slope'
   *  DataTypeConversion: '<S55>/OutDTConv'
   *  Product: '<S55>/Product4'
   *  Sum: '<S55>/Add1'
   *  Sum: '<S55>/Add2'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localSwitch = IgSys_agIgLimKnkMin_B;
  } else {
    locallocalSum = ((rt_MINf(localmin_0, localSum3[5]) - -36.0F) *
                     2.666666746E+000F) + 0.5F;
    if (locallocalSum < 256.0F) {
      if (locallocalSum >= 0.0F) {
        localSwitch = (UInt8)locallocalSum;
      } else {
        localSwitch = 0U;
      }
    } else {
      localSwitch = MAX_uint8_T;
    }
  }

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S48>/Byp_Fonction_SC'
   *  Constant: '<S48>/Int_BypC'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localSwitch_j = IgSys_agIgLimKnkMv_B;
  } else {
    localSwitch_j = locallocalTmpSignalConversionAt;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_agIgOptmOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgOptm'
   */
  Rte_Read_R_IgSys_agIgOptm_IgSys_agIgOptm(&localTmpSignalConversionAtIg_d0);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_agIgCylPresMaxFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgCylPresMaxFlex'
   */
  Rte_Read_R_IgSys_agIgCylPresMaxFlex_IgSys_agIgCylPresMaxFlex
    (&localTmpSignalConversionAtIgS_j);

  /* Outputs for atomic SubSystem: '<S10>/F02_Avance_maxi' *
   * Block requirements for '<S10>/F02_Avance_maxi':
   *  1. SubSystem "F02_Avance_maxi" !Trace_To : VEMS_R_10_06425_008.02 ;
   */

  /* MultiPortSwitch: '<S53>/Multiport Switch' incorporates:
   *  Constant: '<S53>/IgSys_agIgMaxMod_C'
   */
  if (IgSys_agIgMaxMod_C == 0) {
    locallocalTmpSignalConversionAt = localOutDTConv_m;
  }

  /* MinMax: '<S53>/MinMax' */
  if (locallocalTmpSignalConversionAt < localTmpSignalConversionAtIg_d0) {
    localTmpSignalConversionAtIg_d0 = locallocalTmpSignalConversionAt;
  }

  if (localTmpSignalConversionAtIgS_j < localTmpSignalConversionAtIg_d0) {
    localTmpSignalConversionAtIg_d0 = localTmpSignalConversionAtIgS_j;
  }

  /* end of Outputs for SubSystem: '<S10>/F02_Avance_maxi' */

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Byp_Fonction_SC'
   *  Constant: '<S49>/Int_BypC'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversionAt = IgSys_agIgMax_B;
  } else {
    locallocalTmpSignalConversionAt = localTmpSignalConversionAtIg_d0;
  }

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Byp_Fonction_SC'
   *  Constant: '<S50>/Int_BypC'
   *  Constant: '<S54>/offset'
   *  Constant: '<S54>/offset1'
   *  Constant: '<S54>/one_on_slope'
   *  DataTypeConversion: '<S54>/OutDTConv'
   *  Product: '<S54>/Product4'
   *  Sum: '<S52>/Sum1'
   *  Sum: '<S54>/Add1'
   *  Sum: '<S54>/Add2'
   */
  for (locali = 0; locali < 6; locali++) {
    if (ADVCORDT_ACTIVE_BYP_C) {
      localTmpSignalConversionAtKnkMg[locali] = IgSys_prm_agIgLimKnk_B[(locali)];
    } else {
      locallocalSum = ((((localDivide_d[locali] - localDataTypeConversion4) -
                         localDivide_h[locali]) - -36.0F) * 2.666666746E+000F) +
        0.5F;
      if (locallocalSum < 256.0F) {
        if (locallocalSum >= 0.0F) {
          localTmpSignalConversionAtKnk_p = (UInt8)locallocalSum;
        } else {
          localTmpSignalConversionAtKnk_p = 0U;
        }
      } else {
        localTmpSignalConversionAtKnk_p = MAX_uint8_T;
      }

      localTmpSignalConversionAtKnkMg[locali] = localTmpSignalConversionAtKnk_p;
    }
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Byp_Fonction_SC'
   *  Constant: '<S51>/Int_BypC'
   *  Constant: '<S56>/offset'
   *  Constant: '<S56>/offset1'
   *  Constant: '<S56>/one_on_slope'
   *  DataTypeConversion: '<S56>/OutDTConv'
   *  Product: '<S56>/Product4'
   *  Sum: '<S56>/Add1'
   *  Sum: '<S56>/Add2'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtKnk_p = IgSys_agIgLimKnkMax_B;
  } else {
    locallocalSum = ((rt_MAXf(localmin, localSum5[5]) - -36.0F) *
                     2.666666746E+000F) + 0.5F;
    if (locallocalSum < 256.0F) {
      if (locallocalSum >= 0.0F) {
        localTmpSignalConversionAtKnk_p = (UInt8)locallocalSum;
      } else {
        localTmpSignalConversionAtKnk_p = 0U;
      }
    } else {
      localTmpSignalConversionAtKnk_p = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S10>/SignalConversion5' */
  localTmpSignalConversionAtEng_n = localOutDTConv_m;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_agIgLimKnkMaxInport2' */
  Rte_Write_P_IgSys_agIgLimKnkMax_IgSys_agIgLimKnkMax
    (localTmpSignalConversionAtKnk_p);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_agIgLimKnkMinInport2' */
  Rte_Write_P_IgSys_agIgLimKnkMin_IgSys_agIgLimKnkMin(localSwitch);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_agIgLimKnkMvInport2' */
  Rte_Write_P_IgSys_agIgLimKnkMv_IgSys_agIgLimKnkMv(localSwitch_j);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_agIgMaxInport2' */
  Rte_Write_P_IgSys_agIgMax_IgSys_agIgMax(locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevAdpCyl_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_007_DRE_IgSys_agIgMaxWiPrevAdpCyl_irv
    (localTmpSignalConversionAtEng_n);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_prm_agIgLimKnkInport2' */
  Rte_Write_P_IgSys_prm_agIgLimKnk_IgSys_prm_agIgLimKnk
    (&localTmpSignalConversionAtKnkMg);
}

/* Output and update for exported function: RE_AdvCordT_007_DRE */
void RE_AdvCordT_007_DRE(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_coordination_Avance_maxi_trig'
   *
   * Block requirements for '<S1>/F03_coordination_Avance_maxi_trig':
   *  1. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_073.02 ;
   *  2. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_004.02 ;
   *  3. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_005.02 ;
   *  4. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_006.02 ;
   *  5. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_032.01 ;
   *  6. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_037.01 ;
   *  7. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_039.01 ;
   *  8. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_043.01 ;
   *  9. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_044.01 ;
   *  10. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_045.02 ;
   *  11. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_067.02 ;
   *  12. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_024.02 ;
   *  13. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_025.02 ;
   *  14. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_027.02 ;
   *  15. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_028.02 ;
   *  16. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_050.03 ;
   *  17. SubSystem "F03_coordination_Avance_maxi_trig" !Trace_To : VEMS_R_10_06425_075.01 ;
   */
  F03_coordination_Avance_maxi_tr();
}

/* Output and update for function-call system: '<S1>/F04_Calcul_avance_running' */
void AdvCo_F04_Calcul_avance_running(void)
{
  Float32 localDataTypeConversion6_i;
  Float32 localDataTypeConversion20;
  Boolean localTmpSignalConversionAtCoEs_;
  Boolean localTmpSignalConversionAtIg_ph;
  Boolean localLogicalOperator1;
  Float32 localDataTypeConversion12;
  Float32 localDataTypeConversion13[6];
  Float32 localDataTypeConversion15[6];
  Float32 localDataTypeConversion16;
  Float32 localDataTypeConversion1[6];
  Float32 localDataTypeConversion3_a;
  Float32 localDataTypeConversion4_o;
  SInt16 localTmpSignalConversionAtExt_t;
  Float32 localDataTypeConversion3_l;
  UInt8 localTmpSignalConversionAtEng_h;
  Float32 localDataTypeConversion7_m;
  Float32 localUnitDelay_e;
  UInt32 localAdd_i;
  UInt32 localAdd_g;
  Float32 localSelector_c;
  Float32 localSelector_f;
  Boolean localTmpSignalConversionAtCo_k1;
  Boolean localTmpSignalConversionAtCoE_k;
  UInt8 localTmpSignalConversionAtIgS_l;
  UInt8 localTmpSignalConversionAtIg_mj;
  UInt8 localTmpSignalConversionAtIg_an[6];
  UInt8 localTmpSignalConversionAtIg_al;
  UInt8 localTmpSignalConversionAtKnk_d[6];
  UInt8 localTmpSignalConversionAtKnk_k;
  UInt8 localTmpSignalConversionAtIg_ar[6];
  UInt8 localTmpSignalConversionAtIg_c4;
  SInt32 locali;
  Float32 localmin;
  Float32 localmin_1_idx;
  Float32 localmin_1_idx_0;
  Float32 localmin_1_idx_1;
  Float32 locallocalAdd2_h_idx;
  Float32 locallocalAdd2_h_idx_0;
  UInt8 locallocalTmpSignalConversionAt;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgTarWiCllTarOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgTarWiCllTar'
   */
  Rte_Read_R_IgSys_agIgTarWiCllTar_IgSys_agIgTarWiCllTar
    (&localTmpSignalConversionAtIgS_l);

  /* DataTypeConversion: '<S11>/Data Type Conversion6' */
  localDataTypeConversion6_i = (((Float32)localTmpSignalConversionAtIgS_l) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgStrtSpOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgStrtSp'
   */
  Rte_Read_R_IgSys_agIgStrtSp_IgSys_agIgStrtSp(&locallocalTmpSignalConversionAt);

  /* DataTypeConversion: '<S11>/Data Type Conversion20' */
  localDataTypeConversion20 = (((Float32)locallocalTmpSignalConversionAt) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIg_ph);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtCoEs_bIntrSTTEsLoEngSpdOutport2' incorporates:
   *  Inport: '<Root>/CoEs_bIntrSTTEsLoEngSpd'
   */
  Rte_Read_R_CoEs_bIntrSTTEsLoEngSpd_CoEs_bIntrSTTEsLoEngSpd
    (&localTmpSignalConversionAtCoEs_);

  /* Logic: '<S11>/Logical Operator1' incorporates:
   *  Logic: '<S11>/Logical Operator2'
   */
  localLogicalOperator1 = ((localTmpSignalConversionAtIg_ph) &&
    (!localTmpSignalConversionAtCoEs_));

  /* Outputs for trigger SubSystem: '<S11>/F01_Init_decalage_avance' incorporates:
   *  TriggerPort: '<S72>/IgSys_bAcvStructAdv'
   *
   * Block requirements for '<S11>/F01_Init_decalage_avance':
   *  1. SubSystem "F01_Init_decalage_avance" !Trace_To : VEMS_R_10_06425_011.01 ;
   */
  if ((localLogicalOperator1) &&
      (AdvCordT_PrevZCSigState.F01_Init_decalage_avance_Trig_Z != POS_ZCSIG)) {
    /* Switch: '<S72>/Switch1' incorporates:
     *  Constant: '<S72>/IgSys_agIgColdOfs_C'
     *  Constant: '<S72>/IgSys_agIgTCoThdOfs_C'
     *  Constant: '<S72>/IgSys_agIgWarmOfs_C'
     *  RelationalOperator: '<S72>/Relational Operator'
     */
    if (localTmpSignalConversionAtExt_t > IgSys_agIgTCoThdOfs_C) {
      localTmpSignalConversionAtIgS_l = IgSys_agIgWarmOfs_C;
    } else {
      localTmpSignalConversionAtIgS_l = IgSys_agIgColdOfs_C;
    }

    /* DataTypeConversion: '<S72>/Data Type Conversion1' */
    IgSys_agIgMaxAfterStrtOfs = (((Float32)localTmpSignalConversionAtIgS_l) *
      0.375F) - 36.0F;

    /* SignalConversion: '<S72>/Signal Conversion5' */
    IgSys_agIgMaxAfterStrt = localDataTypeConversion20;

    /* DataTypeConversion: '<S78>/OutDTConv' incorporates:
     *  Constant: '<S78>/offset'
     *  Constant: '<S78>/offset1'
     *  Constant: '<S78>/one_on_slope'
     *  Product: '<S78>/Product4'
     *  Sum: '<S72>/Sum5'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Add2'
     */
    localmin = (((localDataTypeConversion6_i - localDataTypeConversion20) -
                 -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localmin < 256.0F) {
      if (localmin >= 0.0F) {
        IgSys_agIgOfs = (UInt8)localmin;
      } else {
        IgSys_agIgOfs = 0U;
      }
    } else {
      IgSys_agIgOfs = MAX_uint8_T;
    }
  }

  AdvCordT_PrevZCSigState.F01_Init_decalage_avance_Trig_Z = (UInt8)
    (localLogicalOperator1 ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

  /* end of Outputs for SubSystem: '<S11>/F01_Init_decalage_avance' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgOfsPrev_irv1Outport2' */
  localTmpSignalConversionAtIgS_l =
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_agIgOfsPrev_irv();

  /* Outputs for enable SubSystem: '<S11>/F02_Decalage_avance' incorporates:
   *  Constant: '<S11>/Cste_0'
   *  EnablePort: '<S73>/IgSys_bAcvStructAdv'
   *  Logic: '<S11>/Logical Operator3'
   *  RelationalOperator: '<S11>/Relational Operator'
   *  UnitDelay: '<S77>/Unit Delay'
   *
   * Block requirements for '<S11>/F02_Decalage_avance':
   *  1. SubSystem "F02_Decalage_avance" !Trace_To : VEMS_R_10_06425_012.01 ;
   */
  if ((localLogicalOperator1) && AdvCordT_DWork.UnitDelay_DSTATE_iv) {
    /* Outputs for atomic SubSystem: '<S73>/F01_Compute_decalage' *
     * Block requirements for '<S73>/F01_Compute_decalage':
     *  1. SubSystem "F01_Compute_decalage" !Trace_To : VEMS_R_10_06425_013.01 ;
     */

    /* Sum: '<S79>/Sum5' incorporates:
     *  DataTypeConversion: '<S79>/Data Type Conversion7'
     */
    IgSys_agIgMaxAfterStrt = localDataTypeConversion6_i - ((((Float32)
      localTmpSignalConversionAtIgS_l) * 0.375F) - 36.0F);

    /* end of Outputs for SubSystem: '<S73>/F01_Compute_decalage' */

    /* If: '<S73>/If' incorporates:
     *  ActionPort: '<S80>/Action Port'
     *  ActionPort: '<S81>/Action Port'
     *  Constant: '<S73>/Cste_0'
     *  RelationalOperator: '<S73>/Relational Operator'
     *  SubSystem: '<S73>/F02_Compute_decalage'
     *  SubSystem: '<S73>/F03_Compute_decalage_default'
     *
     * Block requirements for '<S73>/F02_Compute_decalage':
     *  1. SubSystem "F02_Compute_decalage" !Trace_To : VEMS_R_10_06425_014.01 ;
     */
    if (localTmpSignalConversionAtIgS_l != 96) {
      /* DataTypeConversion: '<S80>/Data Type Conversion7' */
      localDataTypeConversion7_m = (((Float32)localTmpSignalConversionAtIgS_l) *
        0.375F) - 36.0F;

      /* Switch: '<S80>/Switch' incorporates:
       *  Constant: '<S80>/Cste_0'
       *  RelationalOperator: '<S80>/Relational Operator'
       *  Sum: '<S80>/Sum3'
       *  Sum: '<S80>/Sum4'
       */
      if (localDataTypeConversion7_m >= 0.0F) {
        localUnitDelay_e = localDataTypeConversion7_m -
          IgSys_agIgMaxAfterStrtOfs;
      } else {
        localUnitDelay_e = localDataTypeConversion7_m +
          IgSys_agIgMaxAfterStrtOfs;
      }

      /* DataTypeConversion: '<S82>/OutDTConv' incorporates:
       *  Constant: '<S82>/offset'
       *  Constant: '<S82>/offset1'
       *  Constant: '<S82>/one_on_slope'
       *  Product: '<S82>/Product4'
       *  Sum: '<S82>/Add1'
       *  Sum: '<S82>/Add2'
       */
      localmin = ((localUnitDelay_e - -36.0F) * 2.666666746E+000F) + 0.5F;
      if (localmin < 256.0F) {
        if (localmin >= 0.0F) {
          locallocalTmpSignalConversionAt = (UInt8)localmin;
        } else {
          locallocalTmpSignalConversionAt = 0U;
        }
      } else {
        locallocalTmpSignalConversionAt = MAX_uint8_T;
      }

      /* DataStoreWrite: '<S80>/Data Store Write2' */
      IgSys_agIgDeltaMaxAfterStrt_MP = locallocalTmpSignalConversionAt;

      /* RelationalOperator: '<S80>/Relational Operator1' incorporates:
       *  Abs: '<S80>/Abs'
       */
      IgSys_bSelAgIgOfs_MP = (ACTEMS_FabsF(localDataTypeConversion7_m) <
        IgSys_agIgMaxAfterStrtOfs);

      /* RelationalOperator: '<S80>/Relational Operator2' incorporates:
       *  Constant: '<S80>/IgSys_agIgDeltaMaxThd_C'
       *  DataTypeConversion: '<S80>/Data Type Conversion1'
       *  Sum: '<S80>/Sum5'
       *  UnitDelay: '<S83>/Unit Delay'
       */
      IgSys_bSelAgIgTarThd_MP = ((AdvCordT_DWork.UnitDelay_DSTATE_j -
        localDataTypeConversion6_i) > ((((Float32)IgSys_agIgDeltaMaxThd_C) *
        0.375F) - 36.0F));

      /* Switch: '<S80>/Switch1' incorporates:
       *  Constant: '<S80>/Cste_1'
       *  Logic: '<S80>/Logical Operator'
       */
      if (IgSys_bSelAgIgOfs_MP || IgSys_bSelAgIgTarThd_MP) {
        locallocalTmpSignalConversionAt = 96U;
      }

      /* Update for UnitDelay: '<S83>/Unit Delay' */
      AdvCordT_DWork.UnitDelay_DSTATE_j = localDataTypeConversion6_i;
    } else {
      /* SignalConversion: '<S81>/Signal Conversion' */
      locallocalTmpSignalConversionAt = 96U;
    }

    /* SignalConversion: '<S73>/Signal Conversion1' */
    IgSys_agIgOfs = locallocalTmpSignalConversionAt;
  }

  /* end of Outputs for SubSystem: '<S11>/F02_Decalage_avance' */

  /* Outputs for enable SubSystem: '<S11>/F03_Decalage_avance_default' incorporates:
   *  EnablePort: '<S75>/Enable'
   *  Logic: '<S11>/Logical Operator4'
   */
  if (!localLogicalOperator1) {
    /* SignalConversion: '<S75>/Signal Conversion' */
    IgSys_agIgOfs = localTmpSignalConversionAtIgS_l;
  }

  /* end of Outputs for SubSystem: '<S11>/F03_Decalage_avance_default' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S70>/autosar_testpoint1' */

  /* S-Function Block: <S70>/autosar_testpoint1 */
  IgSys_agIgOfsPrev_IRV_MP = IgSys_agIgOfs;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMinOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMin'
   */
  Rte_Read_R_IgSys_agIgMin_IgSys_agIgMin(&localTmpSignalConversionAtIg_mj);

  /* DataTypeConversion: '<S11>/Data Type Conversion12' */
  localDataTypeConversion12 = (((Float32)localTmpSignalConversionAtIg_mj) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgLimKnkOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_agIgLimKnk_INPUT'
   */
  Rte_Read_R_IgSys_prm_agIgLimKnk_IgSys_prm_agIgLimKnk
    (&localTmpSignalConversionAtIg_an);

  /* DataTypeConversion: '<S11>/Data Type Conversion13' */
  for (locali = 0; locali < 6; locali++) {
    localDataTypeConversion13[locali] = (((Float32)
      localTmpSignalConversionAtIg_an[locali]) * 0.375F) - 36.0F;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgLimKnkMvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgLimKnkMv_INPUT'
   */
  Rte_Read_R_IgSys_agIgLimKnkMv_IgSys_agIgLimKnkMv
    (&localTmpSignalConversionAtIg_al);

  /* DataTypeConversion: '<S11>/Data Type Conversion14' */
  localDataTypeConversion7_m = (((Float32)localTmpSignalConversionAtIg_al) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtKnkMgt_prm_agIgKnkDetOfsCylOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_prm_agIgKnkDetOfsCyl'
   */
  Rte_Read_R_KnkMgt_prm_agIgKnkDetOfsCyl_KnkMgt_prm_agIgKnkDetOfsCyl
    (&localTmpSignalConversionAtKnk_d);

  /* DataTypeConversion: '<S11>/Data Type Conversion15' */
  for (locali = 0; locali < 6; locali++) {
    localDataTypeConversion15[locali] = (((Float32)
      localTmpSignalConversionAtKnk_d[locali]) * 0.375F) - 36.0F;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEng_noCmprCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprCyl'
   */
  Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl
    (&AdvCordT_B.TmpSignalConversionAtEng_noCmpr);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEng_noCmprNxtCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprNxtCyl'
   */
  Rte_Read_R_Eng_noCmprNxtCyl_Eng_noCmprNxtCyl(&localTmpSignalConversionAtEng_h);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtKnkMgt_agIgOfsKnkDftOutport2' incorporates:
   *  Inport: '<Root>/KnkMgt_agIgOfsKnkDft'
   */
  Rte_Read_R_KnkMgt_agIgOfsKnkDft_KnkMgt_agIgOfsKnkDft
    (&localTmpSignalConversionAtKnk_k);

  /* DataTypeConversion: '<S11>/Data Type Conversion16' */
  localDataTypeConversion16 = (((Float32)localTmpSignalConversionAtKnk_k) *
    0.375F) - 36.0F;

  /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_001_irvOutport2'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_002_irvOutport2'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_003_irvOutport2'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_004_irvOutport2'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_005_irvOutport2'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgTestCyl_006_irvOutport2'
   */
  localDataTypeConversion1[0] = (((Float32)
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_prm_agIgTestCyl_001_irv()) * 0.375F) -
    36.0F;
  localDataTypeConversion1[1] = (((Float32)
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_prm_agIgTestCyl_002_irv()) * 0.375F) -
    36.0F;
  localDataTypeConversion1[2] = (((Float32)
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_prm_agIgTestCyl_003_irv()) * 0.375F) -
    36.0F;
  localDataTypeConversion1[3] = (((Float32)
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_prm_agIgTestCyl_004_irv()) * 0.375F) -
    36.0F;
  localDataTypeConversion1[4] = (((Float32)
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_prm_agIgTestCyl_005_irv()) * 0.375F) -
    36.0F;
  localDataTypeConversion1[5] = (((Float32)
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_prm_agIgTestCyl_006_irv()) * 0.375F) -
    36.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgStrtSpNxtOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgStrtSpNxt'
   */
  Rte_Read_R_IgSys_agIgStrtSpNxt_IgSys_agIgStrtSpNxt
    (&localTmpSignalConversionAtIg_c4);

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgOfsTest_irvOutport2'
   */
  localDataTypeConversion3_a = (((Float32)
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_agIgOfsTest_irv()) * 0.375F) - 100.0F;

  /* DataTypeConversion: '<S11>/Data Type Conversion4' incorporates:
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgTest_irvOutport2'
   */
  localDataTypeConversion4_o = (((Float32)
    Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_agIgTest_irv()) * 0.375F) - 36.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtCoEs_bAcvIgSysSTTEsOutport2' incorporates:
   *  Inport: '<Root>/CoEs_bAcvIgSysSTTEs'
   */
  Rte_Read_R_CoEs_bAcvIgSysSTTEs_CoEs_bAcvIgSysSTTEs
    (&localTmpSignalConversionAtCoE_k);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtCoEs_bIntrSTTEsHiEngSpdOutport2' incorporates:
   *  Inport: '<Root>/CoEs_bIntrSTTEsHiEngSpd'
   */
  Rte_Read_R_CoEs_bIntrSTTEsHiEngSpd_CoEs_bIntrSTTEsHiEngSpd
    (&localTmpSignalConversionAtCo_k1);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgCylPresMaxFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgCylPresMaxFlex'
   */
  Rte_Read_R_IgSys_agIgCylPresMaxFlex_IgSys_agIgCylPresMaxFlex
    (&AdvCordT_B.TmpSignalConversionAtIgSys_agIg);

  /* Outputs for atomic SubSystem: '<S11>/F03_Calcul_avance_running_enable' *
   * Block requirements for '<S11>/F03_Calcul_avance_running_enable':
   *  1. SubSystem "F03_Calcul_avance_running_enable" !Trace_To : VEMS_R_10_06425_015.02 ;
   */

  /* DataTypeConversion: '<S74>/Data Type Conversion3' */
  localDataTypeConversion3_l = (((Float32)
    AdvCordT_B.TmpSignalConversionAtIgSys_agIg) * 0.375F) - 36.0F;

  /* Outputs for atomic SubSystem: '<S74>/F01_Calc_avance_finale' *
   * Block requirements for '<S74>/F01_Calc_avance_finale':
   *  1. SubSystem "F01_Calc_avance_finale" !Trace_To : VEMS_R_10_06425_016.02 ;
   */

  /* DataTypeConversion: '<S84>/Data Type Conversion1' incorporates:
   *  Constant: '<S84>/IgSys_agIgSTTEsOfsUp_C'
   */
  localDataTypeConversion6_i = ((Float32)IgSys_agIgSTTEsOfsUp_C) *
    1.000000015E-001F;

  /* Sum: '<S84>/Sum11' incorporates:
   *  UnitDelay: '<S102>/Unit Delay'
   */
  locallocalAdd2_h_idx = AdvCordT_DWork.UnitDelay_DSTATE_i[0] +
    localDataTypeConversion6_i;
  locallocalAdd2_h_idx_0 = AdvCordT_DWork.UnitDelay_DSTATE_i[1] +
    localDataTypeConversion6_i;
  localUnitDelay_e = AdvCordT_DWork.UnitDelay_DSTATE_i[2] +
    localDataTypeConversion6_i;

  /* Switch: '<S84>/Switch4' */
  if (!localTmpSignalConversionAtCo_k1) {
    locallocalAdd2_h_idx = IgSys_agIgMaxAfterStrt;
    locallocalAdd2_h_idx_0 = IgSys_agIgMaxAfterStrt;
    localUnitDelay_e = IgSys_agIgMaxAfterStrt;
  }

  /* MinMax: '<S84>/MinMax4' */
  localmin_1_idx = rt_MINf(locallocalAdd2_h_idx, IgSys_agIgMaxAfterStrt);
  localmin_1_idx_0 = rt_MINf(locallocalAdd2_h_idx_0, IgSys_agIgMaxAfterStrt);
  localmin_1_idx_1 = rt_MINf(localUnitDelay_e, IgSys_agIgMaxAfterStrt);
  locallocalAdd2_h_idx = localmin_1_idx;

  /* DataStoreWrite: '<S84>/Data Store Write' incorporates:
   *  Constant: '<S97>/offset'
   *  Constant: '<S97>/offset1'
   *  Constant: '<S97>/one_on_slope'
   *  DataTypeConversion: '<S97>/OutDTConv'
   *  Product: '<S97>/Product4'
   *  Sum: '<S97>/Add1'
   *  Sum: '<S97>/Add2'
   */
  localmin = ((localmin_1_idx - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord1_MP[0] = localTmpSignalConversionAtIgS_l;
  locallocalAdd2_h_idx_0 = localmin_1_idx_0;

  /* DataStoreWrite: '<S84>/Data Store Write' incorporates:
   *  Constant: '<S97>/offset'
   *  Constant: '<S97>/offset1'
   *  Constant: '<S97>/one_on_slope'
   *  DataTypeConversion: '<S97>/OutDTConv'
   *  Product: '<S97>/Product4'
   *  Sum: '<S97>/Add1'
   *  Sum: '<S97>/Add2'
   */
  localmin = ((localmin_1_idx_0 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord1_MP[1] = localTmpSignalConversionAtIgS_l;
  localUnitDelay_e = localmin_1_idx_1;

  /* DataStoreWrite: '<S84>/Data Store Write' incorporates:
   *  Constant: '<S97>/offset'
   *  Constant: '<S97>/offset1'
   *  Constant: '<S97>/one_on_slope'
   *  DataTypeConversion: '<S97>/OutDTConv'
   *  Product: '<S97>/Product4'
   *  Sum: '<S97>/Add1'
   *  Sum: '<S97>/Add2'
   */
  localmin = ((localmin_1_idx_1 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord1_MP[2] = localTmpSignalConversionAtIgS_l;

  /* DataTypeConversion: '<S84>/Data Type Conversion2' incorporates:
   *  Constant: '<S84>/IgSys_agIgSTTEsOfsDown_C'
   */
  localDataTypeConversion6_i = ((Float32)IgSys_agIgSTTEsOfsDown_C) *
    1.000000015E-001F;

  /* Switch: '<S84>/Switch3' incorporates:
   *  Sum: '<S84>/Sum9'
   *  UnitDelay: '<S102>/Unit Delay'
   */
  if (localTmpSignalConversionAtCoE_k) {
    locallocalAdd2_h_idx = AdvCordT_DWork.UnitDelay_DSTATE_i[0] -
      localDataTypeConversion6_i;
    locallocalAdd2_h_idx_0 = AdvCordT_DWork.UnitDelay_DSTATE_i[1] -
      localDataTypeConversion6_i;
    localUnitDelay_e = AdvCordT_DWork.UnitDelay_DSTATE_i[2] -
      localDataTypeConversion6_i;
  }

  /* DataTypeConversion: '<S84>/Data Type Conversion3' */
  localAdd_i = AdvCordT_B.TmpSignalConversionAtEng_noCmpr;

  /* Sum: '<S86>/Add' incorporates:
   *  Constant: '<S86>/Constant1'
   */
  localAdd_g = localAdd_i - 1U;

  /* Selector: '<S86>/Selector' incorporates:
   *  Constant: '<S86>/Constant'
   *  MinMax: '<S86>/MinMax'
   */
  localSelector_c = localDataTypeConversion13[(SInt32)rt_MIN(localAdd_g, 5U)];

  /* DataTypeConversion: '<S84>/Data Type Conversion' incorporates:
   *  SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgMaxWiPrevAdpCyl_irvOutport2'
   */
  localSelector_f = (((Float32)
                      Rte_IrvRead_RE_AdvCordT_005_DRE_IgSys_agIgMaxWiPrevAdpCyl_irv
                      ()) * 0.375F) - 36.0F;

  /* MinMax: '<S84>/MinMax9' incorporates:
   *  MinMax: '<S84>/MinMax5'
   */

  /* DataStoreWrite: '<S84>/Data Store Write1' incorporates:
   *  Constant: '<S96>/offset'
   *  Constant: '<S96>/offset1'
   *  Constant: '<S96>/one_on_slope'
   *  DataTypeConversion: '<S96>/OutDTConv'
   *  Product: '<S96>/Product4'
   *  Sum: '<S96>/Add1'
   *  Sum: '<S96>/Add2'
   */
  localmin = ((locallocalAdd2_h_idx - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord2_MP[0] = localTmpSignalConversionAtIgS_l;
  localmin = rt_MAXf(localDataTypeConversion12, locallocalAdd2_h_idx);
  locallocalAdd2_h_idx = rt_MINf(locallocalAdd2_h_idx, localSelector_c);
  localmin_1_idx = localmin;

  /* DataStoreWrite: '<S84>/Data Store Write1' incorporates:
   *  Constant: '<S96>/offset'
   *  Constant: '<S96>/offset1'
   *  Constant: '<S96>/one_on_slope'
   *  DataTypeConversion: '<S96>/OutDTConv'
   *  Product: '<S96>/Product4'
   *  Sum: '<S96>/Add1'
   *  Sum: '<S96>/Add2'
   */
  localmin = ((locallocalAdd2_h_idx_0 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord2_MP[1] = localTmpSignalConversionAtIgS_l;
  localmin = rt_MAXf(localDataTypeConversion12, locallocalAdd2_h_idx_0);
  locallocalAdd2_h_idx_0 = rt_MINf(locallocalAdd2_h_idx_0, localSelector_f);
  localmin_1_idx_0 = localmin;

  /* DataStoreWrite: '<S84>/Data Store Write1' incorporates:
   *  Constant: '<S96>/offset'
   *  Constant: '<S96>/offset1'
   *  Constant: '<S96>/one_on_slope'
   *  DataTypeConversion: '<S96>/OutDTConv'
   *  Product: '<S96>/Product4'
   *  Sum: '<S96>/Add1'
   *  Sum: '<S96>/Add2'
   */
  localmin = ((localUnitDelay_e - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord2_MP[2] = localTmpSignalConversionAtIgS_l;
  localmin = rt_MAXf(localDataTypeConversion12, localUnitDelay_e);
  localUnitDelay_e = rt_MINf(localUnitDelay_e, localDataTypeConversion7_m);

  /* Switch: '<S84>/Switch6' incorporates:
   *  Constant: '<S84>/IgSys_bSelAgIgCordTyp_C'
   */
  if (IgSys_bSelAgIgCordTyp_C) {
    locallocalAdd2_h_idx = localmin_1_idx;
    locallocalAdd2_h_idx_0 = localmin_1_idx_0;
    localUnitDelay_e = localmin;
  }

  /* MinMax: '<S84>/MinMax6' */

  /* DataStoreWrite: '<S84>/Data Store Write2' incorporates:
   *  Constant: '<S98>/offset'
   *  Constant: '<S98>/offset1'
   *  Constant: '<S98>/one_on_slope'
   *  DataTypeConversion: '<S98>/OutDTConv'
   *  Product: '<S98>/Product4'
   *  Sum: '<S98>/Add1'
   *  Sum: '<S98>/Add2'
   */
  localmin = ((locallocalAdd2_h_idx - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord3_MP[0] = localTmpSignalConversionAtIgS_l;
  localmin_1_idx = rt_MINf(localSelector_c, locallocalAdd2_h_idx);

  /* DataStoreWrite: '<S84>/Data Store Write2' incorporates:
   *  Constant: '<S98>/offset'
   *  Constant: '<S98>/offset1'
   *  Constant: '<S98>/one_on_slope'
   *  DataTypeConversion: '<S98>/OutDTConv'
   *  Product: '<S98>/Product4'
   *  Sum: '<S98>/Add1'
   *  Sum: '<S98>/Add2'
   */
  localmin = ((locallocalAdd2_h_idx_0 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord3_MP[1] = localTmpSignalConversionAtIgS_l;
  localmin_1_idx_0 = rt_MINf(localSelector_f, locallocalAdd2_h_idx_0);

  /* DataStoreWrite: '<S84>/Data Store Write2' incorporates:
   *  Constant: '<S98>/offset'
   *  Constant: '<S98>/offset1'
   *  Constant: '<S98>/one_on_slope'
   *  DataTypeConversion: '<S98>/OutDTConv'
   *  Product: '<S98>/Product4'
   *  Sum: '<S98>/Add1'
   *  Sum: '<S98>/Add2'
   */
  localmin = ((localUnitDelay_e - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgCord3_MP[2] = localTmpSignalConversionAtIgS_l;
  localmin_1_idx_1 = rt_MINf(localDataTypeConversion7_m, localUnitDelay_e);

  /* Switch: '<S84>/Switch5' incorporates:
   *  Constant: '<S84>/IgSys_bSelAgIgCordTyp_C'
   *  MinMax: '<S84>/MinMax8'
   */
  if (!IgSys_bSelAgIgCordTyp_C) {
    localmin_1_idx = rt_MAXf(locallocalAdd2_h_idx, localDataTypeConversion12);
    localmin_1_idx_0 = rt_MAXf(locallocalAdd2_h_idx_0, localDataTypeConversion12);
    localmin_1_idx_1 = rt_MAXf(localUnitDelay_e, localDataTypeConversion12);
  }

  /* DataStoreWrite: '<S84>/Data Store Write3' incorporates:
   *  Constant: '<S99>/offset'
   *  Constant: '<S99>/offset1'
   *  Constant: '<S99>/one_on_slope'
   *  DataTypeConversion: '<S99>/OutDTConv'
   *  Product: '<S99>/Product4'
   *  Sum: '<S99>/Add1'
   *  Sum: '<S99>/Add2'
   */
  localmin = ((localmin_1_idx - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgMaxAgIgMinMax_MP[0] = localTmpSignalConversionAtIgS_l;
  localmin = ((localmin_1_idx_0 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgMaxAgIgMinMax_MP[1] = localTmpSignalConversionAtIgS_l;
  localmin = ((localmin_1_idx_1 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  IgSys_prm_agIgMaxAgIgMinMax_MP[2] = localTmpSignalConversionAtIgS_l;

  /* DataStoreWrite: '<S84>/Data Store Write4' incorporates:
   *  Constant: '<S89>/offset'
   *  Constant: '<S89>/offset1'
   *  Constant: '<S89>/one_on_slope'
   *  DataTypeConversion: '<S89>/OutDTConv'
   *  Product: '<S89>/Product4'
   *  Sum: '<S89>/Add1'
   *  Sum: '<S89>/Add2'
   */
  IgSys_prm_agIgMaxCord_MP[0] = (UInt8)(((localSelector_c - -36.0F) *
    2.666666746E+000F) + 0.5F);
  IgSys_prm_agIgMaxCord_MP[1] = (UInt8)(((localSelector_f - -36.0F) *
    2.666666746E+000F) + 0.5F);
  IgSys_prm_agIgMaxCord_MP[2] = (UInt8)(((localDataTypeConversion7_m - -36.0F)
    * 2.666666746E+000F) + 0.5F);

  /* Sum: '<S87>/Add' incorporates:
   *  Constant: '<S87>/Constant1'
   */
  localAdd_g = localAdd_i - 1U;

  /* Selector: '<S87>/Selector' incorporates:
   *  Constant: '<S87>/Constant'
   *  MinMax: '<S87>/MinMax'
   */
  localSelector_f = localDataTypeConversion15[(SInt32)rt_MIN(localAdd_g, 5U)];

  /* Switch: '<S84>/Switch1' incorporates:
   *  Constant: '<S84>/Cste_0'
   *  Constant: '<S84>/IgSys_bKnkAdvETB_C'
   *  Sum: '<S84>/Sum8'
   */
  if (IgSys_bKnkAdvETB_C) {
    localDataTypeConversion6_i = localSelector_f + localDataTypeConversion16;
  } else {
    localDataTypeConversion6_i = 0.0F;
  }

  /* DataStoreWrite: '<S84>/Data Store Write5' incorporates:
   *  Constant: '<S100>/offset'
   *  Constant: '<S100>/offset1'
   *  Constant: '<S100>/one_on_slope'
   *  DataTypeConversion: '<S100>/OutDTConv'
   *  Product: '<S100>/Product4'
   *  Sum: '<S100>/Add1'
   *  Sum: '<S100>/Add2'
   */
  localmin = ((localDataTypeConversion6_i - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      IgSys_agIgKnkDetOfsCylSel_MP = (UInt8)localmin;
    } else {
      IgSys_agIgKnkDetOfsCylSel_MP = 0U;
    }
  } else {
    IgSys_agIgKnkDetOfsCylSel_MP = MAX_uint8_T;
  }

  /* Sum: '<S88>/Add' incorporates:
   *  Constant: '<S88>/Constant1'
   */
  localAdd_i--;

  /* Selector: '<S88>/Selector' incorporates:
   *  Constant: '<S88>/Constant'
   *  MinMax: '<S88>/MinMax'
   */
  localDataTypeConversion7_m = localDataTypeConversion1[(SInt32)rt_MIN
    (localAdd_i, 5U)];

  /* DataStoreWrite: '<S84>/Data Store Write6' incorporates:
   *  Constant: '<S94>/offset'
   *  Constant: '<S94>/offset1'
   *  Constant: '<S94>/one_on_slope'
   *  DataTypeConversion: '<S94>/OutDTConv'
   *  Product: '<S94>/Product4'
   *  Sum: '<S94>/Add1'
   *  Sum: '<S94>/Add2'
   */
  IgSys_agIgTestCyl_MP = (UInt8)(((localDataTypeConversion7_m - -36.0F) *
    2.666666746E+000F) + 0.5F);

  /* Sum: '<S84>/Sum10' */
  localUnitDelay_e = localDataTypeConversion4_o - localDataTypeConversion6_i;

  /* Sum: '<S84>/Sum1' */
  localDataTypeConversion6_i = (localUnitDelay_e + localDataTypeConversion7_m) +
    localDataTypeConversion3_a;

  /* MinMax: '<S84>/MinMax' */
  localmin_1_idx = rt_MINf(localmin_1_idx, localDataTypeConversion3_l);
  localmin_1_idx_0 = rt_MINf(localmin_1_idx_0, localDataTypeConversion3_l);
  locallocalAdd2_h_idx = rt_MINf(localmin_1_idx_1, localDataTypeConversion3_l);

  /* MultiPortSwitch: '<S84>/Multiport Switch2' incorporates:
   *  Constant: '<S84>/IgSys_noAdvETBMod_C'
   *  Sum: '<S84>/Sum3'
   */
  switch (IgSys_noAdvETBMod_C) {
   case 0:
    break;

   case 1:
    localUnitDelay_e = localDataTypeConversion6_i;
    break;

   case 2:
    localUnitDelay_e = localDataTypeConversion6_i + localmin_1_idx;
    break;

   default:
    localUnitDelay_e = localmin_1_idx;
    break;
  }

  /* DataStoreWrite: '<S84>/Data Store Write7' incorporates:
   *  Constant: '<S101>/offset'
   *  Constant: '<S101>/offset1'
   *  Constant: '<S101>/one_on_slope'
   *  DataTypeConversion: '<S101>/OutDTConv'
   *  Product: '<S101>/Product4'
   *  Sum: '<S101>/Add1'
   *  Sum: '<S101>/Add2'
   */
  localmin = ((localUnitDelay_e - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      IgSys_agIgSpSel_MP = (UInt8)localmin;
    } else {
      IgSys_agIgSpSel_MP = 0U;
    }
  } else {
    IgSys_agIgSpSel_MP = MAX_uint8_T;
  }

  /* DataStoreWrite: '<S84>/Data Store Write8' incorporates:
   *  Constant: '<S95>/offset'
   *  Constant: '<S95>/offset1'
   *  Constant: '<S95>/one_on_slope'
   *  DataTypeConversion: '<S95>/OutDTConv'
   *  Product: '<S95>/Product4'
   *  Sum: '<S95>/Add1'
   *  Sum: '<S95>/Add2'
   */
  IgSys_agIgKnkDetOfsCyl_MP = (UInt8)(((localSelector_f - -36.0F) *
    2.666666746E+000F) + 0.5F);

  /* DataStoreWrite: '<S84>/Data Store Write9' incorporates:
   *  Constant: '<S90>/offset'
   *  Constant: '<S90>/offset1'
   *  Constant: '<S90>/one_on_slope'
   *  DataTypeConversion: '<S90>/OutDTConv'
   *  Product: '<S90>/Product4'
   *  Sum: '<S90>/Add1'
   *  Sum: '<S90>/Add2'
   */
  IgSys_agIgLimKnkCyl_MP = (UInt8)(((localSelector_c - -36.0F) *
    2.666666746E+000F) + 0.5F);

  /* Switch: '<S84>/Switch2' incorporates:
   *  Logic: '<S84>/Logical Operator1'
   *  Logic: '<S84>/Logical Operator2'
   */
  if ((!localTmpSignalConversionAtIg_ph) || (localTmpSignalConversionAtCoEs_)) {
    localUnitDelay_e = localDataTypeConversion20;
  }

  /* DataTypeConversion: '<S93>/OutDTConv' incorporates:
   *  Constant: '<S93>/offset'
   *  Constant: '<S93>/offset1'
   *  Constant: '<S93>/one_on_slope'
   *  Product: '<S93>/Product4'
   *  Sum: '<S93>/Add1'
   *  Sum: '<S93>/Add2'
   */
  localmin = ((localUnitDelay_e - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      localTmpSignalConversionAtIgS_l = (UInt8)localmin;
    } else {
      localTmpSignalConversionAtIgS_l = 0U;
    }
  } else {
    localTmpSignalConversionAtIgS_l = MAX_uint8_T;
  }

  /* Update for UnitDelay: '<S102>/Unit Delay' */
  AdvCordT_DWork.UnitDelay_DSTATE_i[0] = localmin_1_idx;
  AdvCordT_DWork.UnitDelay_DSTATE_i[1] = localmin_1_idx_0;
  AdvCordT_DWork.UnitDelay_DSTATE_i[2] = locallocalAdd2_h_idx;

  /* end of Outputs for SubSystem: '<S74>/F01_Calc_avance_finale' */

  /* Outputs for atomic SubSystem: '<S74>/F02_Calc_avance_finale_next' *
   * Block requirements for '<S74>/F02_Calc_avance_finale_next':
   *  1. SubSystem "F02_Calc_avance_finale_next" !Trace_To : VEMS_R_10_06425_068.02 ;
   */

  /* Switch: '<S85>/Switch7' incorporates:
   *  Constant: '<S85>/IgSys_agIgSTTEsOfsUp_C'
   *  DataTypeConversion: '<S85>/Data Type Conversion1'
   *  Sum: '<S85>/Sum1'
   *  UnitDelay: '<S115>/Unit Delay'
   */
  if (localTmpSignalConversionAtCo_k1) {
    localDataTypeConversion20 = (((Float32)IgSys_agIgSTTEsOfsUp_C) *
      1.000000015E-001F) + AdvCordT_DWork.UnitDelay_DSTATE;
  } else {
    localDataTypeConversion20 = IgSys_agIgMaxAfterStrt;
  }

  /* MinMax: '<S85>/MinMax2' */
  localDataTypeConversion20 = rt_MINf(localDataTypeConversion20,
    IgSys_agIgMaxAfterStrt);

  /* DataStoreWrite: '<S85>/Data Store Write' incorporates:
   *  Constant: '<S112>/offset'
   *  Constant: '<S112>/offset1'
   *  Constant: '<S112>/one_on_slope'
   *  DataTypeConversion: '<S112>/OutDTConv'
   *  Product: '<S112>/Product4'
   *  Sum: '<S112>/Add1'
   *  Sum: '<S112>/Add2'
   */
  localmin = ((localDataTypeConversion20 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      IgSys_agIgCord1Next_MP = (UInt8)localmin;
    } else {
      IgSys_agIgCord1Next_MP = 0U;
    }
  } else {
    IgSys_agIgCord1Next_MP = MAX_uint8_T;
  }

  /* Switch: '<S85>/Switch6' incorporates:
   *  Constant: '<S85>/IgSys_agIgSTTEsOfsDown_C'
   *  DataTypeConversion: '<S85>/Data Type Conversion2'
   *  Sum: '<S85>/Sum6'
   *  UnitDelay: '<S115>/Unit Delay'
   */
  if (localTmpSignalConversionAtCoE_k) {
    localDataTypeConversion20 = AdvCordT_DWork.UnitDelay_DSTATE - (((Float32)
      IgSys_agIgSTTEsOfsDown_C) * 1.000000015E-001F);
  }

  /* DataStoreWrite: '<S85>/Data Store Write1' incorporates:
   *  Constant: '<S111>/offset'
   *  Constant: '<S111>/offset1'
   *  Constant: '<S111>/one_on_slope'
   *  DataTypeConversion: '<S111>/OutDTConv'
   *  Product: '<S111>/Product4'
   *  Sum: '<S111>/Add1'
   *  Sum: '<S111>/Add2'
   */
  localmin = ((localDataTypeConversion20 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      IgSys_agIgCord2Next_MP = (UInt8)localmin;
    } else {
      IgSys_agIgCord2Next_MP = 0U;
    }
  } else {
    IgSys_agIgCord2Next_MP = MAX_uint8_T;
  }

  /* DataTypeConversion: '<S85>/Data Type Conversion3' */
  localAdd_i = localTmpSignalConversionAtEng_h;

  /* Sum: '<S103>/Add' incorporates:
   *  Constant: '<S103>/Constant1'
   */
  localAdd_g = localAdd_i - 1U;

  /* Selector: '<S103>/Selector' incorporates:
   *  Constant: '<S103>/Constant'
   *  MinMax: '<S103>/MinMax'
   */
  locallocalAdd2_h_idx_0 = localDataTypeConversion13[(SInt32)rt_MIN(localAdd_g,
    5U)];

  /* Switch: '<S85>/Switch9' incorporates:
   *  Constant: '<S85>/IgSys_bSelAgIgCordTyp_C'
   *  MinMax: '<S85>/MinMax3'
   *  MinMax: '<S85>/MinMax9'
   */
  if (IgSys_bSelAgIgCordTyp_C) {
    localDataTypeConversion20 = rt_MAXf(localDataTypeConversion12,
      localDataTypeConversion20);
  } else {
    localDataTypeConversion20 = rt_MINf(localDataTypeConversion20,
      locallocalAdd2_h_idx_0);
  }

  /* DataStoreWrite: '<S85>/Data Store Write2' incorporates:
   *  Constant: '<S110>/offset'
   *  Constant: '<S110>/offset1'
   *  Constant: '<S110>/one_on_slope'
   *  DataTypeConversion: '<S110>/OutDTConv'
   *  Product: '<S110>/Product4'
   *  Sum: '<S110>/Add1'
   *  Sum: '<S110>/Add2'
   */
  localmin = ((localDataTypeConversion20 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      IgSys_agIgCord3Next_MP = (UInt8)localmin;
    } else {
      IgSys_agIgCord3Next_MP = 0U;
    }
  } else {
    IgSys_agIgCord3Next_MP = MAX_uint8_T;
  }

  /* Sum: '<S104>/Add' incorporates:
   *  Constant: '<S104>/Constant1'
   */
  localAdd_g = localAdd_i - 1U;

  /* Selector: '<S104>/Selector' incorporates:
   *  Constant: '<S104>/Constant'
   *  MinMax: '<S104>/MinMax'
   */
  localmin_1_idx_1 = localDataTypeConversion15[(SInt32)rt_MIN(localAdd_g, 5U)];

  /* Switch: '<S85>/Switch1' incorporates:
   *  Constant: '<S85>/Cste_0'
   *  Constant: '<S85>/IgSys_bKnkAdvETB_C'
   *  Sum: '<S85>/Sum8'
   */
  if (IgSys_bKnkAdvETB_C) {
    localSelector_f = localmin_1_idx_1 + localDataTypeConversion16;
  } else {
    localSelector_f = 0.0F;
  }

  /* Sum: '<S85>/Sum2' */
  localUnitDelay_e = localDataTypeConversion4_o - localSelector_f;

  /* Sum: '<S105>/Add' incorporates:
   *  Constant: '<S105>/Constant1'
   */
  localAdd_i--;

  /* Selector: '<S105>/Selector' incorporates:
   *  Constant: '<S105>/Constant'
   *  MinMax: '<S105>/MinMax'
   */
  localSelector_c = localDataTypeConversion1[(SInt32)rt_MIN(localAdd_i, 5U)];

  /* Sum: '<S85>/Sum4' */
  localDataTypeConversion7_m = (localUnitDelay_e + localSelector_c) +
    localDataTypeConversion3_a;

  /* Switch: '<S85>/Switch8' incorporates:
   *  Constant: '<S85>/IgSys_bSelAgIgCordTyp_C'
   *  MinMax: '<S85>/MinMax6'
   *  MinMax: '<S85>/MinMax8'
   */
  if (IgSys_bSelAgIgCordTyp_C) {
    localDataTypeConversion20 = rt_MINf(locallocalAdd2_h_idx_0,
      localDataTypeConversion20);
  } else {
    localDataTypeConversion20 = rt_MAXf(localDataTypeConversion20,
      localDataTypeConversion12);
  }

  /* MinMax: '<S85>/MinMax' */
  localDataTypeConversion6_i = rt_MINf(localDataTypeConversion20,
    localDataTypeConversion3_l);

  /* MultiPortSwitch: '<S85>/Multiport Switch2' incorporates:
   *  Constant: '<S85>/IgSys_noAdvETBMod_C'
   *  Sum: '<S85>/Sum3'
   */
  switch (IgSys_noAdvETBMod_C) {
   case 0:
    break;

   case 1:
    localUnitDelay_e = localDataTypeConversion7_m;
    break;

   case 2:
    localUnitDelay_e = localDataTypeConversion7_m + localDataTypeConversion6_i;
    break;

   default:
    localUnitDelay_e = localDataTypeConversion6_i;
    break;
  }

  /* DataTypeConversion: '<S108>/OutDTConv' incorporates:
   *  Constant: '<S108>/offset'
   *  Constant: '<S108>/offset1'
   *  Constant: '<S108>/one_on_slope'
   *  Product: '<S108>/Product4'
   *  Sum: '<S108>/Add1'
   *  Sum: '<S108>/Add2'
   */
  localmin = ((localUnitDelay_e - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      locallocalTmpSignalConversionAt = (UInt8)localmin;
    } else {
      locallocalTmpSignalConversionAt = 0U;
    }
  } else {
    locallocalTmpSignalConversionAt = MAX_uint8_T;
  }

  /* DataStoreWrite: '<S85>/Data Store Write3' */
  IgSys_agIgSpSel1_MP = locallocalTmpSignalConversionAt;

  /* DataStoreWrite: '<S85>/Data Store Write4' incorporates:
   *  Constant: '<S113>/offset'
   *  Constant: '<S113>/offset1'
   *  Constant: '<S113>/one_on_slope'
   *  DataTypeConversion: '<S113>/OutDTConv'
   *  Product: '<S113>/Product4'
   *  Sum: '<S113>/Add1'
   *  Sum: '<S113>/Add2'
   */
  IgSys_agIgTestCyl1_MP = (UInt8)(((localSelector_c - -36.0F) *
    2.666666746E+000F) + 0.5F);

  /* DataStoreWrite: '<S85>/Data Store Write5' incorporates:
   *  Constant: '<S109>/offset'
   *  Constant: '<S109>/offset1'
   *  Constant: '<S109>/one_on_slope'
   *  DataTypeConversion: '<S109>/OutDTConv'
   *  Product: '<S109>/Product4'
   *  Sum: '<S109>/Add1'
   *  Sum: '<S109>/Add2'
   */
  localmin = ((localSelector_f - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      IgSys_agIgKnkDetOfsCylSel1_MP = (UInt8)localmin;
    } else {
      IgSys_agIgKnkDetOfsCylSel1_MP = 0U;
    }
  } else {
    IgSys_agIgKnkDetOfsCylSel1_MP = MAX_uint8_T;
  }

  /* DataStoreWrite: '<S85>/Data Store Write6' incorporates:
   *  Constant: '<S107>/offset'
   *  Constant: '<S107>/offset1'
   *  Constant: '<S107>/one_on_slope'
   *  DataTypeConversion: '<S107>/OutDTConv'
   *  Product: '<S107>/Product4'
   *  Sum: '<S107>/Add1'
   *  Sum: '<S107>/Add2'
   */
  IgSys_agIgKnkDetOfsCyl1_MP = (UInt8)(((localmin_1_idx_1 - -36.0F) *
    2.666666746E+000F) + 0.5F);

  /* DataStoreWrite: '<S85>/Data Store Write7' incorporates:
   *  Constant: '<S106>/offset'
   *  Constant: '<S106>/offset1'
   *  Constant: '<S106>/one_on_slope'
   *  DataTypeConversion: '<S106>/OutDTConv'
   *  Product: '<S106>/Product4'
   *  Sum: '<S106>/Add1'
   *  Sum: '<S106>/Add2'
   */
  IgSys_agIgLimKnkCyl1_MP = (UInt8)(((locallocalAdd2_h_idx_0 - -36.0F) *
    2.666666746E+000F) + 0.5F);

  /* DataStoreWrite: '<S85>/Data Store Write8' incorporates:
   *  Constant: '<S114>/offset'
   *  Constant: '<S114>/offset1'
   *  Constant: '<S114>/one_on_slope'
   *  DataTypeConversion: '<S114>/OutDTConv'
   *  Product: '<S114>/Product4'
   *  Sum: '<S114>/Add1'
   *  Sum: '<S114>/Add2'
   */
  localmin = ((localDataTypeConversion20 - -36.0F) * 2.666666746E+000F) + 0.5F;
  if (localmin < 256.0F) {
    if (localmin >= 0.0F) {
      IgSys_agIgMaxAgIgMinMax1_MP = (UInt8)localmin;
    } else {
      IgSys_agIgMaxAgIgMinMax1_MP = 0U;
    }
  } else {
    IgSys_agIgMaxAgIgMinMax1_MP = MAX_uint8_T;
  }

  /* Switch: '<S85>/Switch2' incorporates:
   *  Logic: '<S85>/Logical Operator1'
   *  Logic: '<S85>/Logical Operator2'
   */
  if ((!localTmpSignalConversionAtIg_ph) || (localTmpSignalConversionAtCoEs_)) {
    locallocalTmpSignalConversionAt = localTmpSignalConversionAtIg_c4;
  }

  /* Update for UnitDelay: '<S115>/Unit Delay' */
  AdvCordT_DWork.UnitDelay_DSTATE = localDataTypeConversion6_i;

  /* end of Outputs for SubSystem: '<S74>/F02_Calc_avance_finale_next' */

  /* end of Outputs for SubSystem: '<S11>/F03_Calcul_avance_running_enable' */

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Byp_Fonction_SC'
   *  Constant: '<S66>/Int_BypC'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIg_mj = IgSys_agIgSp_B;
  } else {
    localTmpSignalConversionAtIg_mj = localTmpSignalConversionAtIgS_l;
  }

  /* Switch: '<S67>/Switch' incorporates:
   *  Constant: '<S67>/Byp_Fonction_SC'
   *  Constant: '<S67>/Int_BypC'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIg_al = IgSys_agIgSpNxt_B;
  } else {
    localTmpSignalConversionAtIg_al = locallocalTmpSignalConversionAt;
  }

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S68>/Byp_Fonction_SC'
   *  Constant: '<S68>/Int_BypC'
   *  Constant: '<S91>/offset'
   *  Constant: '<S91>/offset1'
   *  Constant: '<S91>/one_on_slope'
   *  DataTypeConversion: '<S91>/OutDTConv'
   *  Product: '<S91>/Product4'
   *  Sum: '<S91>/Add1'
   *  Sum: '<S91>/Add2'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtKnk_k = IgSys_agIgSpWoutKnkDet_B;
  } else {
    localmin = ((localmin_1_idx_0 - -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localmin < 256.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtKnk_k = (UInt8)localmin;
      } else {
        localTmpSignalConversionAtKnk_k = 0U;
      }
    } else {
      localTmpSignalConversionAtKnk_k = MAX_uint8_T;
    }
  }

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/Byp_Fonction_SC'
   *  Constant: '<S69>/Int_BypC'
   *  Constant: '<S92>/offset'
   *  Constant: '<S92>/offset1'
   *  Constant: '<S92>/one_on_slope'
   *  DataTypeConversion: '<S92>/OutDTConv'
   *  Product: '<S92>/Product4'
   *  Sum: '<S92>/Add1'
   *  Sum: '<S92>/Add2'
   */
  if (ADVCORDT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIg_c4 = IgSys_agIgDynIgSpEfc_B;
  } else {
    localmin = ((locallocalAdd2_h_idx - -36.0F) * 2.666666746E+000F) + 0.5F;
    if (localmin < 256.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIg_c4 = (UInt8)localmin;
      } else {
        localTmpSignalConversionAtIg_c4 = 0U;
      }
    } else {
      localTmpSignalConversionAtIg_c4 = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgSpCyl_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_agIgSpCyl_INPUT'
   */
  Rte_Read_R_IgSys_prm_agIgSpCyl_IgSys_prm_agIgSpCyl
    (&localTmpSignalConversionAtIg_ar);

  /* Outputs for atomic SubSystem: '<S11>/F04_Vecteur_avance' *
   * Block requirements for '<S11>/F04_Vecteur_avance':
   *  1. SubSystem "F04_Vecteur_avance" !Trace_To : VEMS_R_10_06425_017.01 ;
   */

  /* Assignment: '<S76>/Assignment' */
  localTmpSignalConversionAtIg_ar[AdvCordT_B.TmpSignalConversionAtEng_noCmpr - 1]
    = localTmpSignalConversionAtIgS_l;

  /* Assignment: '<S76>/Assignment1' */
  localTmpSignalConversionAtIg_ar[localTmpSignalConversionAtEng_h - 1] =
    locallocalTmpSignalConversionAt;

  /* end of Outputs for SubSystem: '<S11>/F04_Vecteur_avance' */

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S71>/Byp_Fonction_SC'
   *  Constant: '<S71>/Int_BypC'
   */
  for (locali = 0; locali < 6; locali++) {
    if (ADVCORDT_ACTIVE_BYP_C) {
      localTmpSignalConversionAtIg_ar[locali] = IgSys_prm_agIgSpCyl_B[(locali)];
    }
  }

  /* SignalConversion: '<S11>/SignalConversion' */
  localTmpSignalConversionAtIgS_l = IgSys_agIgOfs;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgDynIgSpEfcInport2' */
  Rte_Write_P_IgSys_agIgDynIgSpEfc_IgSys_agIgDynIgSpEfc
    (localTmpSignalConversionAtIg_c4);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgOfsPrev_irvInport2' */
  Rte_IrvWrite_RE_AdvCordT_005_DRE_IgSys_agIgOfsPrev_irv
    (localTmpSignalConversionAtIgS_l);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgSpInport2' */
  Rte_Write_P_IgSys_agIgSp_IgSys_agIgSp(localTmpSignalConversionAtIg_mj);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgSpNxtInport2' */
  Rte_Write_P_IgSys_agIgSpNxt_IgSys_agIgSpNxt(localTmpSignalConversionAtIg_al);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_agIgSpWoutKnkDetInport2' */
  Rte_Write_P_IgSys_agIgSpWoutKnkDet_IgSys_agIgSpWoutKnkDet
    (localTmpSignalConversionAtKnk_k);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_prm_agIgSpCylInport2' */
  Rte_Write_P_IgSys_prm_agIgSpCyl_IgSys_prm_agIgSpCyl
    (&localTmpSignalConversionAtIg_ar);

  /* Update for UnitDelay: '<S77>/Unit Delay' */
  AdvCordT_DWork.UnitDelay_DSTATE_iv = localLogicalOperator1;
}

/* Output and update for exported function: RE_AdvCordT_005_DRE */
void RE_AdvCordT_005_DRE(void)
{
  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F04_Calcul_avance_running'
   *
   * Block requirements for '<S1>/F04_Calcul_avance_running':
   *  1. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_004.02 ;
   *  2. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_005.02 ;
   *  3. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_010.02 ;
   *  4. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_072.02 ;
   *  5. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_029.01 ;
   *  6. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_030.01 ;
   *  7. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_031.01 ;
   *  8. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_032.01 ;
   *  9. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_033.01 ;
   *  10. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_034.01 ;
   *  11. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_038.01 ;
   *  12. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_040.01 ;
   *  13. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_041.01 ;
   *  14. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_042.01 ;
   *  15. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_022.01 ;
   *  16. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_044.01 ;
   *  17. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_045.02 ;
   *  18. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_067.01 ;
   *  19. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_060.01 ;
   *  20. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_053.02 ;
   *  21. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_054.02 ;
   *  22. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_055.02 ;
   *  23. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_056.02 ;
   *  24. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_057.02 ;
   *  25. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_058.02 ;
   *  26. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_059.02 ;
   *  27. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_023.02 ;
   *  28. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_046.02 ;
   *  29. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_047.02 ;
   *  30. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_048.02 ;
   *  31. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_051.02 ;
   *  32. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_060.01 ;
   *  33. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_026.02 ;
   *  34. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_074.01 ;
   *  35. SubSystem "F04_Calcul_avance_running" !Trace_To : VEMS_R_10_06425_075.01 ;
   */
  AdvCo_F04_Calcul_avance_running();
}

/* Model initialize function */
void Runnable_AdvCordT_Init(void)
{
  /* Registration code */

  /* block I/O */
  {
    AdvCordT_B.TmpSignalConversionAtIgSys_agIg = 96U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  AdvCordT_PrevZCSigState.F01_Init_decalage_avance_Trig_Z = POS_ZCSIG;
}

#define AdvCordT_STOP_SEC_CODE
#include "AdvCordT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
