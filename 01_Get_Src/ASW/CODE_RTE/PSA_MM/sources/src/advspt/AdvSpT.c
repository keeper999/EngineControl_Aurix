/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvSpT                                                  */
/* !Description     : AdvSpT Software Component                               */
/*                                                                            */
/* !Module          : AdvSpT                                                  */
/* !Description     : AdvSpT Software Component                               */
/*                                                                            */
/* !File            : AdvSpT.c                                                */
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
/*   Model name       : AdvSpT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /AdvSpT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M06-AdvSpT/5-SO$*/
/* $Revision::   1.14                                                        $*/
/* $Author::   adelvare                               $$Date::   02 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvSpT.h"
#include "AdvSpT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AdvSpT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvSpT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AdvSpT AdvSpT_B;

/* Block states (auto storage) */
D_Work_AdvSpT AdvSpT_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_AdvSpT AdvSpT_PrevZCSigState;

#define AdvSpT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvSpT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define ADVSPT_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define ADVSPT_VEMSRTLIBT_MINOR_VERSION_REQ 4
#define ADVSPT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define ADVSPT_VEMSRTLIBT_VERSION_REQ (ADVSPT_VEMSRTLIBT_PATCH_VERSION_REQ + ADVSPT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + ADVSPT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if ADVSPT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AdvSpT_START_SEC_CODE
#include "AdvSpT_MemMap.h"

void AdvSpT_ASYNC1(int controlPortIdx)
{
}

void AdvSpT_ASYNC2(int controlPortIdx)
{
}

void AdvSpT_ASYNC3(int controlPortIdx)
{
}

/* Output and update for exported function: RE_AdvSpT_003_MSE */
void RE_AdvSpT_003_MSE(void)
{
  UInt8 localIgSys_noCylCutOffTar;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_IgAdvSelCutOff_Init'
   *
   * Block requirements for '<S1>/F00_IgAdvSelCutOff_Init':
   *  1. SubSystem "F00_IgAdvSelCutOff_Init" !Trace_To : VEMS_R_10_06437_010.01 ;
   *  2. SubSystem "F00_IgAdvSelCutOff_Init" !Trace_To : VEMS_R_10_06437_009.01 ;
   *  3. SubSystem "F00_IgAdvSelCutOff_Init" !Trace_To : VEMS_R_10_06437_008.01 ;
   *  4. SubSystem "F00_IgAdvSelCutOff_Init" !Trace_To : VEMS_R_10_06437_051.01 ;
   */

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S10>/Constant8'
   *  Constant: '<S20>/Byp_Fonction_SC'
   *  Constant: '<S20>/Int_BypC'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localIgSys_noCylCutOffTar = IgSys_noCylCutOffTar_B;
  } else {
    localIgSys_noCylCutOffTar = 0U;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtIgSys_noCylCutOffTarInport2' */
  Rte_Write_P_IgSys_noCylCutOffTar_IgSys_noCylCutOffTar
    (localIgSys_noCylCutOffTar);
}

/* Start for exported function: RE_AdvSpT_001_MSE */
void RE_AdvSpT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_IgAdvEffSp_Init'
   *
   * Block requirements for '<S1>/F00_IgAdvEffSp_Init':
   *  1. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_049.01 ;
   *  2. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_044.01 ;
   *  3. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_043.01 ;
   */
}

/* Output and update for exported function: RE_AdvSpT_001_MSE */
void RE_AdvSpT_001_MSE(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_IgAdvEffSp_Init'
   *
   * Block requirements for '<S1>/F00_IgAdvEffSp_Init':
   *  1. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_049.01 ;
   *  2. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_044.01 ;
   *  3. SubSystem "F00_IgAdvEffSp_Init" !Trace_To : VEMS_R_10_06437_043.01 ;
   */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S18>/autosar_testpoint1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  /* S-Function Block: <S18>/autosar_testpoint1 */
  IgSys_rTarEfcWoutAntiJerk_IRV_MP = 0U;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_rTarEfcWoutAntiJerk_irvInport2' incorporates:
   *  Constant: '<S9>/Constant1'
   *  SignalConversion: '<S9>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_AdvSpT_001_MSE_IgSys_rTarEfcWoutAntiJerk_irv(0U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S19>/autosar_testpoint1' incorporates:
   *  Constant: '<S9>/Constant3'
   */

  /* S-Function Block: <S19>/autosar_testpoint1 */
  IgSys_rTarEfc_IRV_MP = 0U;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_rTarEfc_irvInport2' incorporates:
   *  Constant: '<S9>/Constant3'
   *  SignalConversion: '<S9>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_AdvSpT_001_MSE_IgSys_rTarEfc_irv(0U);
}

/* Start for exported function: RE_AdvSpT_005_MSE */
void RE_AdvSpT_005_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_AdvSp_Init'
   *
   * Block requirements for '<S1>/F00_AdvSp_Init':
   *  1. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_053.01 ;
   *  2. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_038.01 ;
   *  3. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_037.01 ;
   *  4. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_036.01 ;
   *  5. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_034.01 ;
   */
}

/* Output and update for exported function: RE_AdvSpT_005_MSE */
void RE_AdvSpT_005_MSE(void)
{
  UInt8 localIgSys_agIgTarWoutAntiJerk;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_AdvSp_Init'
   *
   * Block requirements for '<S1>/F00_AdvSp_Init':
   *  1. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_053.01 ;
   *  2. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_038.01 ;
   *  3. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_037.01 ;
   *  4. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_036.01 ;
   *  5. SubSystem "F00_AdvSp_Init" !Trace_To : VEMS_R_10_06437_034.01 ;
   */

  /* user code (Output function Body for TID7) */
  Runnable_AdvSp_Init();

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Byp_Fonction_SC'
   *  Constant: '<S17>/Int_BypC'
   *  Constant: '<S8>/Constant4'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localIgSys_agIgTarWoutAntiJerk = IgSys_agIgTarWoutAntiJerk_B;
  } else {
    localIgSys_agIgTarWoutAntiJerk = 149U;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgTarWoutAntiJerkInport2' */
  Rte_Write_P_IgSys_agIgTarWoutAntiJerk_IgSys_agIgTarWoutAntiJerk
    (localIgSys_agIgTarWoutAntiJerk);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Byp_Fonction_SC'
   *  Constant: '<S15>/Int_BypC'
   *  Constant: '<S8>/Constant5'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localIgSys_agIgTarWoutAntiJerk = IgSys_agIg80PercTq_B;
  } else {
    localIgSys_agIgTarWoutAntiJerk = 101U;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIg80PercTqInport2' */
  Rte_Write_P_IgSys_agIg80PercTq_IgSys_agIg80PercTq
    (localIgSys_agIgTarWoutAntiJerk);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Byp_Fonction_SC'
   *  Constant: '<S16>/Int_BypC'
   *  Constant: '<S8>/Constant6'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localIgSys_agIgTarWoutAntiJerk = IgSys_agIgOfs80PrecTq_B;
  } else {
    localIgSys_agIgTarWoutAntiJerk = 144U;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgOfs80PrecTqInport2' */
  Rte_Write_P_IgSys_agIgOfs80PrecTq_IgSys_agIgOfs80PrecTq
    (localIgSys_agIgTarWoutAntiJerk);

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Byp_Fonction_SC'
   *  Constant: '<S14>/Int_BypC'
   *  Constant: '<S8>/Constant7'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localIgSys_agIgTarWoutAntiJerk = IgSys_agIgTarWiCllTar_B;
  } else {
    localIgSys_agIgTarWoutAntiJerk = 149U;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgTarWiCllTarInport2' */
  Rte_Write_P_IgSys_agIgTarWiCllTar_IgSys_agIgTarWiCllTar
    (localIgSys_agIgTarWoutAntiJerk);
}

/* Start for exported function: RE_AdvSpT_002_DRE */
void RE_AdvSpT_002_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F0_CSMT_CGMT08_2013_v1_1'
   *
   * Block requirements for '<S1>/F0_CSMT_CGMT08_2013_v1_1':
   *  1. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_001.01 ;
   *  2. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_050.01 ;
   *  3. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_044.01 ;
   *  4. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_043.01 ;
   *  5. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_041.01 ;
   *  6. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_040.01 ;
   *  7. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_039.02 ;
   *  8. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_023.01 ;
   */
}

/* Output and update for exported function: RE_AdvSpT_002_DRE */
void RE_AdvSpT_002_DRE(void)
{
  Boolean localTmpSignalConversionAtIgSys;
  SInt16 localrtmax;
  SInt16 localTmpSignalConversionAtEngLi;
  SInt16 localTmpSignalConversionAtTqSys;
  UInt16 localrtmin;
  Float32 localtmp;
  UInt32 localtmp_0;
  UInt16 localrtmin_0;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F0_CSMT_CGMT08_2013_v1_1'
   *
   * Block requirements for '<S1>/F0_CSMT_CGMT08_2013_v1_1':
   *  1. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_001.01 ;
   *  2. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_050.01 ;
   *  3. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_044.01 ;
   *  4. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_043.01 ;
   *  5. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_041.01 ;
   *  6. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_040.01 ;
   *  7. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_039.02 ;
   *  8. SubSystem "F0_CSMT_CGMT08_2013_v1_1" !Trace_To : VEMS_R_10_06437_023.01 ;
   */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtTqSys_tqCkEngLimCordOutport2' incorporates:
   *  Inport: '<Root>/TqSys_tqCkEngLimCord'
   */
  Rte_Read_R_TqSys_tqCkEngLimCord_TqSys_tqCkEngLimCord
    (&localTmpSignalConversionAtTqSys);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtTqSys_tqIdcReqOutport2' incorporates:
   *  Inport: '<Root>/TqSys_tqIdcReq'
   */
  Rte_Read_R_TqSys_tqIdcReq_TqSys_tqIdcReq
    (&AdvSpT_B.TmpSignalConversionAtTqSys_tqId);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngLim_tqIdcAirTqWoutTotCutOfOutport2' incorporates:
   *  Inport: '<Root>/EngLim_tqIdcAirTqWoutTotCutOf'
   */
  Rte_Read_R_EngLim_tqIdcAirTqWoutTotCutOf_EngLim_tqIdcAirTqWoutTotCutOf
    (&localTmpSignalConversionAtEngLi);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIgSys);

  /* Outputs for enable SubSystem: '<S11>/F01_Cal_rendement_consigne_d_avance' incorporates:
   *  EnablePort: '<S21>/IgSys_bAcvStructAdv'
   *
   * Block requirements for '<S11>/F01_Cal_rendement_consigne_d_avance':
   *  1. SubSystem "F01_Cal_rendement_consigne_d_avance" !Trace_To : VEMS_R_10_06437_003.01 ;
   *  2. SubSystem "F01_Cal_rendement_consigne_d_avance" !Trace_To : VEMS_R_10_06437_002.01 ;
   */
  if (localTmpSignalConversionAtIgSys) {
    /* MinMax: '<S21>/MinMax2' incorporates:
     *  Constant: '<S21>/Constant1'
     */
    localrtmax = 16;
    if (localTmpSignalConversionAtEngLi > 16) {
      localrtmax = localTmpSignalConversionAtEngLi;
    }

    /* DataTypeConversion: '<S25>/OutDTConv' incorporates:
     *  Constant: '<S25>/offset'
     *  Constant: '<S25>/offset1'
     *  Constant: '<S25>/one_on_slope'
     *  Product: '<S25>/Product4'
     *  Product: '<S26>/Divide'
     *  Sum: '<S25>/Add1'
     *  Sum: '<S25>/Add2'
     */
    localtmp = (((((Float32)localTmpSignalConversionAtTqSys) * 0.0625F) /
                 (((Float32)localrtmax) * 0.0625F)) * 1000.0F) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localrtmin_0 = (UInt16)localtmp;
      } else {
        localrtmin_0 = 0U;
      }
    } else {
      localrtmin_0 = MAX_uint16_T;
    }

    IgSys_rTarEfcMux_MP[0] = localrtmin_0;
    localtmp = (((((Float32)AdvSpT_B.TmpSignalConversionAtTqSys_tqId) * 0.0625F)
                 / (((Float32)localrtmax) * 0.0625F)) * 1000.0F) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localrtmin_0 = (UInt16)localtmp;
      } else {
        localrtmin_0 = 0U;
      }
    } else {
      localrtmin_0 = MAX_uint16_T;
    }

    IgSys_rTarEfcMux_MP[1] = localrtmin_0;

    /* MinMax: '<S21>/MinMax1' incorporates:
     *  Constant: '<S21>/Constant11'
     *  DataTypeConversion: '<S21>/Data Type Conversion1'
     *  SignalConversion: '<S21>/Signal Conversion4'
     */
    localrtmin = 1024U;
    localtmp_0 = (UInt32)((SInt32)(((UInt32)(IgSys_rTarEfcMux_MP[0] * 16777))
      >> 14));
    if (localtmp_0 > 65535U) {
      localrtmin_0 = MAX_uint16_T;
    } else {
      localrtmin_0 = (UInt16)localtmp_0;
    }

    if (localrtmin_0 < 1024) {
      localrtmin = localrtmin_0;
    }

    AdvSpT_B.Merge2 = localrtmin;
    localrtmin = 1024U;
    localtmp_0 = (UInt32)((SInt32)(((UInt32)(IgSys_rTarEfcMux_MP[1] * 16777))
      >> 14));
    if (localtmp_0 > 65535U) {
      localrtmin_0 = MAX_uint16_T;
    } else {
      localrtmin_0 = (UInt16)localtmp_0;
    }

    if (localrtmin_0 < 1024) {
      localrtmin = localrtmin_0;
    }

    /* SignalConversion: '<S21>/Signal Conversion1' */
    AdvSpT_B.Merge1 = localrtmin;
  }

  /* end of Outputs for SubSystem: '<S11>/F01_Cal_rendement_consigne_d_avance' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_rTarEfc_PrevOutport2' */
  AdvSpT_B.TmpSignalConversionAtIgSys_rTar =
    Rte_IrvRead_RE_AdvSpT_002_DRE_IgSys_rTarEfc_irv();

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_rTarEfcWoutAntiJerk_PrevOutport2' */
  AdvSpT_B.TmpSignalConversionAtIgSys_rT_g =
    Rte_IrvRead_RE_AdvSpT_002_DRE_IgSys_rTarEfcWoutAntiJerk_irv();

  /* Outputs for enable SubSystem: '<S11>/F01_Cal_rendement_consigne_d_avance_Default' incorporates:
   *  EnablePort: '<S22>/IgSys_bAcvStructAdv_NOT'
   *  Logic: '<S11>/Logical Operator'
   *
   * Block requirements for '<S11>/F01_Cal_rendement_consigne_d_avance_Default':
   *  1. SubSystem "F01_Cal_rendement_consigne_d_avance_Default" !Trace_To : VEMS_R_10_06437_003.01 ;
   *  2. SubSystem "F01_Cal_rendement_consigne_d_avance_Default" !Trace_To : VEMS_R_10_06437_002.01 ;
   */
  if (!localTmpSignalConversionAtIgSys) {
    /* SignalConversion: '<S22>/Signal Conversion1' */
    AdvSpT_B.Merge1 = AdvSpT_B.TmpSignalConversionAtIgSys_rTar;

    /* SignalConversion: '<S22>/Signal Conversion4' */
    AdvSpT_B.Merge2 = AdvSpT_B.TmpSignalConversionAtIgSys_rT_g;
  }

  /* end of Outputs for SubSystem: '<S11>/F01_Cal_rendement_consigne_d_avance_Default' */

  /* SignalConversion: '<S23>/copy' */
  IgSys_rTarEfcWoutAntiJerk_IRV_MP = AdvSpT_B.Merge2;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S23>/autosar_testpoint1' */

  /* S-Function Block: <S23>/autosar_testpoint1 */

  /* SignalConversion: '<S24>/copy' */
  IgSys_rTarEfc_IRV_MP = AdvSpT_B.Merge1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S24>/autosar_testpoint1' */

  /* S-Function Block: <S24>/autosar_testpoint1 */

  /* SignalConversion: '<S11>/Signal Conversion1' */
  localrtmin_0 = AdvSpT_B.Merge1;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_rTarEfcWoutAntiJerk_irvInport2' incorporates:
   *  SignalConversion: '<S11>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_AdvSpT_002_DRE_IgSys_rTarEfcWoutAntiJerk_irv(AdvSpT_B.Merge2);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_rTarEfc_irvInport2' */
  Rte_IrvWrite_RE_AdvSpT_002_DRE_IgSys_rTarEfc_irv(localrtmin_0);
}

/* Start for exported function: RE_AdvSpT_006_DRE */
void RE_AdvSpT_006_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F0_CSMT_CGMT08_2144_2_v1_0'
   *
   * Block requirements for '<S1>/F0_CSMT_CGMT08_2144_2_v1_0':
   *  1. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_004.01 ;
   *  2. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_055.01 ;
   *  3. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_048.01 ;
   *  4. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_044.01 ;
   *  5. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_043.01 ;
   *  6. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_042.01 ;
   *  7. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_035.01 ;
   *  8. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_038.01 ;
   *  9. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_037.01 ;
   *  10. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_036.01 ;
   *  11. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_034.01 ;
   *  12. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_033.01 ;
   *  13. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_032.01 ;
   *  14. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_031.01 ;
   *  15. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_030.01 ;
   *  16. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_023.01 ;
   */
}

/* Output and update for exported function: RE_AdvSpT_006_DRE */
void RE_AdvSpT_006_DRE(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtIgS_h;
  UInt16 localTmpSignalConversionAtIgS_l;
  Boolean localAutosarServer;
  UInt8 localLookUpTable[3];
  Boolean localNot;
  Boolean localTmpSignalConversionAtIgS_c;
  Float32 localMerge;
  Float32 localMerge_i;
  Boolean localTmpSignalConversionAtTqCll;
  UInt8 localTmpSignalConversionAtIgS_f;
  UInt8 localTmpSignalConversionAtIgS_i;
  UInt8 localTmpSignalConversionAtIg_if;
  UInt8 localTmpSignalConversionAtIgS_a;
  UInt16 localTmpSignalConversionAtIgS_p;
  UInt8 localTmpSignalConversionAtIgS_k;
  UInt8 localTmpSignalConversionAtIg_kw;
  SInt32 localtmp;
  UInt8 locallocalDataTypeConversion1_a;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F0_CSMT_CGMT08_2144_2_v1_0'
   *
   * Block requirements for '<S1>/F0_CSMT_CGMT08_2144_2_v1_0':
   *  1. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_004.01 ;
   *  2. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_055.01 ;
   *  3. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_048.01 ;
   *  4. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_044.01 ;
   *  5. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_043.01 ;
   *  6. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_042.01 ;
   *  7. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_035.01 ;
   *  8. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_038.01 ;
   *  9. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_037.01 ;
   *  10. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_036.01 ;
   *  11. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_034.01 ;
   *  12. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_033.01 ;
   *  13. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_032.01 ;
   *  14. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_031.01 ;
   *  15. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_030.01 ;
   *  16. SubSystem "F0_CSMT_CGMT08_2144_2_v1_0" !Trace_To : VEMS_R_10_06437_023.01 ;
   */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_facTarAgCorOutport2' incorporates:
   *  Inport: '<Root>/IgSys_facTarAgCor'
   */
  Rte_Read_R_IgSys_facTarAgCor_IgSys_facTarAgCor
    (&localTmpSignalConversionAtIgS_p);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_rTarEfc_irvOutport2' */
  localTmpSignalConversionAtIgS_h =
    Rte_IrvRead_RE_AdvSpT_006_DRE_IgSys_rTarEfc_irv();

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_rTarEfcWoutAntiJerk_irvOutport2' */
  localTmpSignalConversionAtIgS_l =
    Rte_IrvRead_RE_AdvSpT_006_DRE_IgSys_rTarEfcWoutAntiJerk_irv();

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIgOptmOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgOptm'
   */
  Rte_Read_R_IgSys_agIgOptm_IgSys_agIgOptm(&localTmpSignalConversionAtIgS_k);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIgBasOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgBas'
   */
  Rte_Read_R_IgSys_agIgBas_IgSys_agIgBas(&localTmpSignalConversionAtIg_kw);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtTqCll_bAcvCllOutport2' incorporates:
   *  Inport: '<Root>/TqCll_bAcvCll'
   */
  Rte_Read_R_TqCll_bAcvCll_TqCll_bAcvCll(&localTmpSignalConversionAtTqCll);

  /* S-Function (sfun_autosar_clientop): '<S29>/AutosarServer' */
  Rte_Call_R_FRM_bAcvCll_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S29>/Not' */
  localNot = !localAutosarServer;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIgS_c);

  /* Outputs for enable SubSystem: '<S12>/F0_01_Calcul_consigne_avance' incorporates:
   *  EnablePort: '<S27>/IgSys_bAcvStructAdv'
   *
   * Block requirements for '<S12>/F0_01_Calcul_consigne_avance':
   *  1. SubSystem "F0_01_Calcul_consigne_avance" !Trace_To : VEMS_R_10_06437_005.01 ;
   *  2. SubSystem "F0_01_Calcul_consigne_avance" !Trace_To : VEMS_R_10_06437_006.02 ;
   */
  if (localTmpSignalConversionAtIgS_c) {
    /* Outputs for atomic SubSystem: '<S27>/F01_Rendement_avance_inverse' *
     * Block requirements for '<S27>/F01_Rendement_avance_inverse':
     *  1. SubSystem "F01_Rendement_avance_inverse" !Trace_To : VEMS_R_10_06437_056.01 ;
     */

    /* Lookup: '<S36>/Look-Up Table'
     * About '<S36>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-10
     * Output0 Data Type:  Fixed Point    U8  2^-2  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable[0]), (&(IgSys_agIgTarOfs_OfsAgIg_T[0])),
                  IgSys_r80PercTq_C, (&(IgSys_rTar_OfsAgIg_A[0])), 103U);
    LookUp_U8_U16( &(localLookUpTable[1]), (&(IgSys_agIgTarOfs_OfsAgIg_T[0])),
                  localTmpSignalConversionAtIgS_h, (&(IgSys_rTar_OfsAgIg_A[0])),
                  103U);
    LookUp_U8_U16( &(localLookUpTable[2]), (&(IgSys_agIgTarOfs_OfsAgIg_T[0])),
                  localTmpSignalConversionAtIgS_l, (&(IgSys_rTar_OfsAgIg_A[0])),
                  103U);

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate1'
     *
     * Regarding '<S36>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S34>/Data Type Conversion1' */
    localtmp = localLookUpTable[0] + 96;
    if (((UInt32)localtmp) > 255U) {
      locallocalDataTypeConversion1_a = MAX_uint8_T;
    } else {
      locallocalDataTypeConversion1_a = (UInt8)localtmp;
    }

    /* DataTypeConversion: '<S34>/Data Type Conversion4' */
    localTmpSignalConversionAtIgS_p = (UInt16)((((UInt32)
      localTmpSignalConversionAtIgS_p) * 32821U) >> 16U);

    /* Switch: '<S34>/Switch1' incorporates:
     *  Constant: '<S34>/Cste_2'
     *  Constant: '<S34>/IgSys_r80PercTq_C1'
     *  Constant: '<S34>/IgSys_r80PercTq_C2'
     *  Logic: '<S34>/Logical Operator1'
     *  RelationalOperator: '<S34>/Relational Operator2'
     */
    if (IgSys_bAcvLimTarAgCor_C && (localTmpSignalConversionAtIgS_h >=
         IgSys_r80PercTq_C)) {
      IgSys_facAgCorSwtTar_MP = 128U;
    } else {
      IgSys_facAgCorSwtTar_MP = localTmpSignalConversionAtIgS_p;
    }

    /* SignalConversion: '<S34>/Signal Conversion3' */
    IgSys_agIgTarOfs_MP = localLookUpTable[1];

    /* Sum: '<S34>/Subtract1' */
    IgSys_agIgTar_AgIg_MP = (SInt16)((96 + IgSys_agIgTarOfs_MP) -
      locallocalDataTypeConversion1_a);

    /* If: '<S37>/If2' incorporates:
     *  ActionPort: '<S43>/Action Port'
     *  ActionPort: '<S44>/Action Port'
     *  Constant: '<S37>/Constant7'
     *  RelationalOperator: '<S37>/Relational Operator'
     *  SubSystem: '<S37>/If Action Subsystem2'
     *  SubSystem: '<S37>/If Action Subsystem3'
     */
    if (IgSys_facAgCorSwtTar_MP == 0) {
      /* Constant: '<S43>/Byp_Fonction_SC' */
      localMerge = 0.0F;
    } else {
      /* Product: '<S44>/Divide1' */
      localMerge = (Float32)((((Float32d)IgSys_agIgTar_AgIg_MP) * 0.375F) /
        (((Float32d)IgSys_facAgCorSwtTar_MP) * 0.0078F));
    }

    /* Switch: '<S34>/Switch2' incorporates:
     *  Constant: '<S34>/Cste_1'
     *  Constant: '<S34>/IgSys_r80PercTq_C1'
     *  Constant: '<S34>/IgSys_r80PercTq_C2'
     *  Logic: '<S34>/Logical Operator2'
     *  RelationalOperator: '<S34>/Relational Operator1'
     */
    if (IgSys_bAcvLimTarAgCor_C && (localTmpSignalConversionAtIgS_l >=
         IgSys_r80PercTq_C)) {
      IgSys_facTarAgCorSwtAntiJ_MP = 128U;
    } else {
      IgSys_facTarAgCorSwtAntiJ_MP = localTmpSignalConversionAtIgS_p;
    }

    /* SignalConversion: '<S34>/Signal Conversion4' */
    IgSys_agIgAntiJerkOfs_MP = localLookUpTable[2];

    /* Sum: '<S34>/Subtract2' */
    IgSys_agIg_AntiJerk_MP = (SInt16)((96 + IgSys_agIgAntiJerkOfs_MP) -
      locallocalDataTypeConversion1_a);

    /* If: '<S38>/If2' incorporates:
     *  ActionPort: '<S47>/Action Port'
     *  ActionPort: '<S48>/Action Port'
     *  Constant: '<S38>/Constant7'
     *  RelationalOperator: '<S38>/Relational Operator'
     *  SubSystem: '<S38>/If Action Subsystem2'
     *  SubSystem: '<S38>/If Action Subsystem3'
     */
    if (IgSys_facTarAgCorSwtAntiJ_MP == 0) {
      /* Constant: '<S47>/Byp_Fonction_SC' */
      localMerge_i = 0.0F;
    } else {
      /* Product: '<S48>/Divide1' */
      localMerge_i = (Float32)((((Float32d)IgSys_agIg_AntiJerk_MP) * 0.375F) /
        (((Float32d)IgSys_facTarAgCorSwtAntiJ_MP) * 0.0078F));
    }

    /* Sum: '<S34>/Subtract4' */
    localtmp = (96 + localTmpSignalConversionAtIgS_k) -
      locallocalDataTypeConversion1_a;
    if (localtmp <= 0) {
      localTmpSignalConversionAtIgS_k = 0U;
    } else {
      localTmpSignalConversionAtIgS_k = (UInt8)localtmp;
    }

    /* SignalConversion: '<S34>/Signal Conversion1' */
    AdvSpT_B.Merge3 = localTmpSignalConversionAtIgS_k;

    /* SignalConversion: '<S34>/Signal Conversion2' */
    AdvSpT_B.Merge2_f = locallocalDataTypeConversion1_a;

    /* Product: '<S39>/Product4' incorporates:
     *  Constant: '<S39>/offset'
     *  Constant: '<S39>/one_on_slope'
     *  Sum: '<S34>/Subtract5'
     *  Sum: '<S39>/Add1'
     */
    localMerge = (((((Float32)localTmpSignalConversionAtIgS_k) * 0.375F) +
                   -36.0F) - localMerge) * 2.666666746E+000F;

    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/offset2'
     *  Constant: '<S39>/offset3'
     *  Constant: '<S39>/offset4'
     *  RelationalOperator: '<S39>/Relational Operator'
     *  Sum: '<S39>/Add3'
     *  Sum: '<S39>/Add4'
     */
    if (localMerge >= 0.0F) {
      localMerge += 0.5F;
    } else {
      localMerge -= 0.5F;
    }

    /* DataTypeConversion: '<S39>/OutDTConv' */
    if (localMerge < 32768.0F) {
      if (localMerge >= -32768.0F) {
        IgSys_agIgTar_MP = (SInt16)localMerge;
      } else {
        IgSys_agIgTar_MP = MIN_int16_T;
      }
    } else {
      IgSys_agIgTar_MP = MAX_int16_T;
    }

    /* DataTypeConversion: '<S40>/OutDTConv' incorporates:
     *  Constant: '<S40>/offset'
     *  Constant: '<S40>/offset1'
     *  Constant: '<S40>/one_on_slope'
     *  Product: '<S40>/Product4'
     *  Sum: '<S34>/Subtract6'
     *  Sum: '<S40>/Add1'
     *  Sum: '<S40>/Add2'
     */
    localMerge = (((((((Float32)localTmpSignalConversionAtIgS_k) * 0.375F) +
                     -36.0F) - localMerge_i) - -36.0F) * 2.666666746E+000F) +
      0.5F;
    if (localMerge < 256.0F) {
      if (localMerge >= 0.0F) {
        AdvSpT_B.Merge4 = (UInt8)localMerge;
      } else {
        AdvSpT_B.Merge4 = 0U;
      }
    } else {
      AdvSpT_B.Merge4 = MAX_uint8_T;
    }

    /* end of Outputs for SubSystem: '<S27>/F01_Rendement_avance_inverse' */

    /* Outputs for atomic SubSystem: '<S27>/F0_03_BouclageSC' *
     * Block requirements for '<S27>/F0_03_BouclageSC':
     *  1. SubSystem "F0_03_BouclageSC" !Trace_To : VEMS_R_10_06437_007.01 ;
     */

    /* Switch: '<S35>/Switch3' incorporates:
     *  DataTypeConversion: '<S35>/Data Type Conversion3'
     *  Logic: '<S35>/Logical Operator'
     */
    if ((localTmpSignalConversionAtTqCll) || (localNot)) {
      localtmp = IgSys_agIgTar_MP + 96;
      if (localtmp <= 0) {
        AdvSpT_B.Merge1_g = 0U;
      } else if (localtmp > 255) {
        AdvSpT_B.Merge1_g = MAX_uint8_T;
      } else {
        AdvSpT_B.Merge1_g = (UInt8)localtmp;
      }
    } else {
      AdvSpT_B.Merge1_g = localTmpSignalConversionAtIg_kw;
    }

    /* end of Outputs for SubSystem: '<S27>/F0_03_BouclageSC' */
  }

  /* end of Outputs for SubSystem: '<S12>/F0_01_Calcul_consigne_avance' */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIgTarWiCllTar_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgTarWiCllTar_INPUT'
   */
  Rte_Read_R_IgSys_agIgTarWiCllTar_IgSys_agIgTarWiCllTar
    (&localTmpSignalConversionAtIgS_f);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIgOfs80PrecTq_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgOfs80PrecTq_INPUT'
   */
  Rte_Read_R_IgSys_agIgOfs80PrecTq_IgSys_agIgOfs80PrecTq
    (&localTmpSignalConversionAtIgS_i);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIg80PercTq_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIg80PercTq_INPUT'
   */
  Rte_Read_R_IgSys_agIg80PercTq_IgSys_agIg80PercTq
    (&localTmpSignalConversionAtIg_if);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIgTarWoutAntiJerk_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgTarWoutAntiJerk_INPUT'
   */
  Rte_Read_R_IgSys_agIgTarWoutAntiJerk_IgSys_agIgTarWoutAntiJerk
    (&localTmpSignalConversionAtIgS_a);

  /* Outputs for enable SubSystem: '<S12>/F0_01_Calcul_consigne_avance_Default' incorporates:
   *  EnablePort: '<S28>/IgSys_bAcvStructAdv_NOT'
   *  Logic: '<S12>/Logical Operator'
   *
   * Block requirements for '<S12>/F0_01_Calcul_consigne_avance_Default':
   *  1. SubSystem "F0_01_Calcul_consigne_avance_Default" !Trace_To : VEMS_R_10_06437_005.01 ;
   */
  if (!localTmpSignalConversionAtIgS_c) {
    /* SignalConversion: '<S28>/Signal Conversion3' */
    AdvSpT_B.Merge1_g = localTmpSignalConversionAtIgS_f;

    /* SignalConversion: '<S28>/Signal Conversion2' */
    AdvSpT_B.Merge2_f = localTmpSignalConversionAtIgS_i;

    /* SignalConversion: '<S28>/Signal Conversion1' */
    AdvSpT_B.Merge3 = localTmpSignalConversionAtIg_if;

    /* SignalConversion: '<S28>/Signal Conversion4' */
    AdvSpT_B.Merge4 = localTmpSignalConversionAtIgS_a;
  }

  /* end of Outputs for SubSystem: '<S12>/F0_01_Calcul_consigne_avance_Default' */

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/Byp_Fonction_SC'
   *  Constant: '<S31>/Int_BypC'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_k = IgSys_agIg80PercTq_B;
  } else {
    localTmpSignalConversionAtIgS_k = AdvSpT_B.Merge3;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIg80PercTqInport2' */
  Rte_Write_P_IgSys_agIg80PercTq_IgSys_agIg80PercTq
    (localTmpSignalConversionAtIgS_k);

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Byp_Fonction_SC'
   *  Constant: '<S32>/Int_BypC'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_k = IgSys_agIgOfs80PrecTq_B;
  } else {
    localTmpSignalConversionAtIgS_k = AdvSpT_B.Merge2_f;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIgOfs80PrecTqInport2' */
  Rte_Write_P_IgSys_agIgOfs80PrecTq_IgSys_agIgOfs80PrecTq
    (localTmpSignalConversionAtIgS_k);

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Byp_Fonction_SC'
   *  Constant: '<S33>/Int_BypC'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_k = IgSys_agIgTarWiCllTar_B;
  } else {
    localTmpSignalConversionAtIgS_k = AdvSpT_B.Merge1_g;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIgTarWiCllTarInport2' */
  Rte_Write_P_IgSys_agIgTarWiCllTar_IgSys_agIgTarWiCllTar
    (localTmpSignalConversionAtIgS_k);

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Byp_Fonction_SC'
   *  Constant: '<S30>/Int_BypC'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_k = IgSys_agIgTarWoutAntiJerk_B;
  } else {
    localTmpSignalConversionAtIgS_k = AdvSpT_B.Merge4;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIgSys_agIgTarWoutAntiJerkInport2' */
  Rte_Write_P_IgSys_agIgTarWoutAntiJerk_IgSys_agIgTarWoutAntiJerk
    (localTmpSignalConversionAtIgS_k);
}

/* Start for exported function: RE_AdvSpT_004_DRE */
void RE_AdvSpT_004_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F0_CSMT_CGMT08_2145_v1_1'
   *
   * Block requirements for '<S1>/F0_CSMT_CGMT08_2145_v1_1':
   *  1. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_009.01 ;
   *  2. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_008.01 ;
   *  3. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_052.01 ;
   *  4. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_047.01 ;
   *  5. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_028.01 ;
   *  6. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_029.01 ;
   *  7. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_027.01 ;
   *  8. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_026.01 ;
   *  9. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_025.01 ;
   *  10. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_024.01 ;
   *  11. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_023.01 ;
   *  12. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_022.01 ;
   *  13. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_021.01 ;
   *  14. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_020.01 ;
   *  15. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_019.01 ;
   *  16. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_018.01 ;
   */
}

/* Output and update for exported function: RE_AdvSpT_004_DRE */
void RE_AdvSpT_004_DRE(void)
{
  /* local block i/o variables */
  Boolean localAutosarServer_p;
  Boolean localNot_h;
  Boolean localTmpSignalConversionAtIgS_j;
  UInt8 localTmpSignalConversionAtIgS_n;
  Float32 localSwitch2_d;
  Float32 localSwitch2_a;
  Float32 localDataTypeConversion7;
  Float32 localDataTypeConversion4_h;
  Boolean localLowerRelop1;
  Float32 localProduct2;
  Float32 localSwitch2;
  Float32 localDataTypeConversion2;
  Float32 localProduct4_b;
  Float32 localProduct3;
  SInt32 localAdd12;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt8 localTmpSignalConversionAtTqS_d;
  UInt8 localTmpSignalConversionAtInjSy;
  UInt8 localUnitDelay;
  UInt8 localUnitDelay_l;
  UInt8 localUnitDelay_p;
  UInt8 localUnitDelay_f;
  SInt16 localTmpSignalConversionAtExt_t;
  UInt8 localTmpSignalConversionAtIg_f2;
  UInt8 localTmpSignalConversionAtIg_fj;
  SInt16 localTmpSignalConversionAtTqS_f;
  SInt16 localTmpSignalConversionAtEng_p;
  SInt16 localTmpSignalConversionAtEng_i;
  UInt16 localTmpSignalConversionAtExM_t;

  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/F0_CSMT_CGMT08_2145_v1_1'
   *
   * Block requirements for '<S1>/F0_CSMT_CGMT08_2145_v1_1':
   *  1. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_009.01 ;
   *  2. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_008.01 ;
   *  3. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_052.01 ;
   *  4. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_047.01 ;
   *  5. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_028.01 ;
   *  6. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_029.01 ;
   *  7. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_027.01 ;
   *  8. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_026.01 ;
   *  9. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_025.01 ;
   *  10. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_024.01 ;
   *  11. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_023.01 ;
   *  12. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_022.01 ;
   *  13. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_021.01 ;
   *  14. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_020.01 ;
   *  15. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_019.01 ;
   *  16. SubSystem "F0_CSMT_CGMT08_2145_v1_1" !Trace_To : VEMS_R_10_06437_018.01 ;
   */

  /* SignalConversion: '<S13>/TmpSignal ConversionAtExM_tUsMainOxCEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_tUsMainOxCEstim'
   */
  Rte_Read_R_ExM_tUsMainOxCEstim_ExM_tUsMainOxCEstim
    (&localTmpSignalConversionAtExM_t);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtIgSys_noTDCCutOffDlyOutport2' incorporates:
   *  Inport: '<Root>/IgSys_noTDCCutOffDly'
   */
  Rte_Read_R_IgSys_noTDCCutOffDly_IgSys_noTDCCutOffDly
    (&localTmpSignalConversionAtIg_f2);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtIgSys_noTDCOutCutOffDlyOutport2' incorporates:
   *  Inport: '<Root>/IgSys_noTDCOutCutOffDly'
   */
  Rte_Read_R_IgSys_noTDCOutCutOffDly_IgSys_noTDCOutCutOffDly
    (&localTmpSignalConversionAtIg_fj);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtInjSys_noCylCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_noCylCutOff'
   */
  Rte_Read_R_InjSys_noCylCutOff_InjSys_noCylCutOff
    (&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtTqSys_noCylCutAuthCordOutport2' incorporates:
   *  Inport: '<Root>/TqSys_noCylCutAuthCord'
   */
  Rte_Read_R_TqSys_noCylCutAuthCord_TqSys_noCylCutAuthCord
    (&localTmpSignalConversionAtTqS_d);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* S-Function (sfun_autosar_clientop): '<S51>/AutosarServer' */
  Rte_Call_R_FRM_bLimSelCutOff_GetFunctionPermission(&localAutosarServer_p);

  /* Logic: '<S51>/Not' */
  localNot_h = !localAutosarServer_p;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtTqSys_tqIdcReqOutport2' incorporates:
   *  Inport: '<Root>/TqSys_tqIdcReq'
   */
  Rte_Read_R_TqSys_tqIdcReq_TqSys_tqIdcReq(&localTmpSignalConversionAtTqS_f);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngLim_tqIdcEngCurMinOutport2' incorporates:
   *  Inport: '<Root>/EngLim_tqIdcEngCurMin'
   */
  Rte_Read_R_EngLim_tqIdcEngCurMin_EngLim_tqIdcEngCurMin
    (&localTmpSignalConversionAtEng_i);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngLim_tqIdcEngCurMaxOutport2' incorporates:
   *  Inport: '<Root>/EngLim_tqIdcEngCurMax'
   */
  Rte_Read_R_EngLim_tqIdcEngCurMax_EngLim_tqIdcEngCurMax
    (&localTmpSignalConversionAtEng_p);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIgS_j);

  /* Outputs for enable SubSystem: '<S13>/F01_01_activation_calcul_consigne_coupure' incorporates:
   *  EnablePort: '<S49>/IgSys_bAcvStructAdv'
   *
   * Block requirements for '<S13>/F01_01_activation_calcul_consigne_coupure':
   *  1. SubSystem "F01_01_activation_calcul_consigne_coupure" !Trace_To : VEMS_R_10_06437_011.01 ;
   */
  if (localTmpSignalConversionAtIgS_j) {
    /* Outputs for atomic SubSystem: '<S49>/F01_01_01_retarder_coupure_reinj' *
     * Block requirements for '<S49>/F01_01_01_retarder_coupure_reinj':
     *  1. SubSystem "F01_01_01_retarder_coupure_reinj" !Trace_To : VEMS_R_10_06437_013.01 ;
     *  2. SubSystem "F01_01_01_retarder_coupure_reinj" !Trace_To : VEMS_R_10_06437_012.01 ;
     */

    /* Outputs for atomic SubSystem: '<S53>/F1_01_01_01_Preparer_detection_coupure' *
     * Block requirements for '<S53>/F1_01_01_01_Preparer_detection_coupure':
     *  1. SubSystem "F1_01_01_01_Preparer_detection_coupure" !Trace_To : VEMS_R_10_06437_014.01 ;
     */

    /* UnitDelay: '<S58>/Unit Delay' */
    InjSys_noCylCutOffDly = AdvSpT_DWork.UnitDelay_DSTATE_n;

    /* RelationalOperator: '<S55>/Relational Operator' */
    InjSys_bCylCutOff = (localTmpSignalConversionAtInjSy !=
                         InjSys_noCylCutOffDly);

    /* Update for UnitDelay: '<S58>/Unit Delay' */
    AdvSpT_DWork.UnitDelay_DSTATE_n = localTmpSignalConversionAtInjSy;

    /* end of Outputs for SubSystem: '<S53>/F1_01_01_01_Preparer_detection_coupure' */

    /* Outputs for trigger SubSystem: '<S53>/F1_01_01_02_Detecter_coupure' incorporates:
     *  TriggerPort: '<S56>/InjSys_bCylCutOff'
     *
     * Block requirements for '<S53>/F1_01_01_02_Detecter_coupure':
     *  1. SubSystem "F1_01_01_02_Detecter_coupure" !Trace_To : VEMS_R_10_06437_015.01 ;
     */
    if (InjSys_bCylCutOff &&
        (AdvSpT_PrevZCSigState.F1_01_01_02_Detecter_coupure_Tr != POS_ZCSIG)) {
      /* RelationalOperator: '<S56>/Relational Operator' */
      InjSys_bCylCutOffTrig = (localTmpSignalConversionAtInjSy >
        InjSys_noCylCutOffDly);
    }

    AdvSpT_PrevZCSigState.F1_01_01_02_Detecter_coupure_Tr = (UInt8)
      (InjSys_bCylCutOff ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

    /* end of Outputs for SubSystem: '<S53>/F1_01_01_02_Detecter_coupure' */

    /* Outputs for atomic SubSystem: '<S53>/F1_01_01_03_Appliquer_retard' *
     * Block requirements for '<S53>/F1_01_01_03_Appliquer_retard':
     *  1. SubSystem "F1_01_01_03_Appliquer_retard" !Trace_To : VEMS_R_10_06437_016.01 ;
     */

    /* Switch: '<S57>/Switch' */
    if (InjSys_bCylCutOffTrig) {
      localTmpSignalConversionAtIg_fj = localTmpSignalConversionAtIg_f2;
    }

    /* UnitDelay: '<S63>/Unit Delay' */
    localUnitDelay = AdvSpT_DWork.UnitDelay_DSTATE;

    /* UnitDelay: '<S60>/Unit Delay' */
    localTmpSignalConversionAtIg_f2 = AdvSpT_DWork.UnitDelay_DSTATE_e;

    /* UnitDelay: '<S61>/Unit Delay' */
    localUnitDelay_l = AdvSpT_DWork.UnitDelay_DSTATE_g;

    /* UnitDelay: '<S62>/Unit Delay' */
    localUnitDelay_p = AdvSpT_DWork.UnitDelay_DSTATE_c;

    /* UnitDelay: '<S64>/Unit Delay' */
    localUnitDelay_f = AdvSpT_DWork.UnitDelay_DSTATE_k;

    /* MultiPortSwitch: '<S57>/Multiport Switch' incorporates:
     *  UnitDelay: '<S59>/Unit Delay'
     */
    switch (localTmpSignalConversionAtIg_fj) {
     case 0:
      InjSys_noCylCutOffDlyOut = localTmpSignalConversionAtInjSy;
      break;

     case 1:
      InjSys_noCylCutOffDlyOut = AdvSpT_DWork.UnitDelay_DSTATE;
      break;

     case 2:
      InjSys_noCylCutOffDlyOut = AdvSpT_DWork.UnitDelay_DSTATE_e;
      break;

     case 3:
      InjSys_noCylCutOffDlyOut = AdvSpT_DWork.UnitDelay_DSTATE_g;
      break;

     case 4:
      InjSys_noCylCutOffDlyOut = AdvSpT_DWork.UnitDelay_DSTATE_c;
      break;

     case 5:
      InjSys_noCylCutOffDlyOut = AdvSpT_DWork.UnitDelay_DSTATE_k;
      break;

     default:
      InjSys_noCylCutOffDlyOut = AdvSpT_DWork.UnitDelay_DSTATE_m;
      break;
    }

    /* Update for UnitDelay: '<S63>/Unit Delay' */
    AdvSpT_DWork.UnitDelay_DSTATE = localTmpSignalConversionAtInjSy;

    /* Update for UnitDelay: '<S60>/Unit Delay' */
    AdvSpT_DWork.UnitDelay_DSTATE_e = localUnitDelay;

    /* Update for UnitDelay: '<S61>/Unit Delay' */
    AdvSpT_DWork.UnitDelay_DSTATE_g = localTmpSignalConversionAtIg_f2;

    /* Update for UnitDelay: '<S62>/Unit Delay' */
    AdvSpT_DWork.UnitDelay_DSTATE_c = localUnitDelay_l;

    /* Update for UnitDelay: '<S64>/Unit Delay' */
    AdvSpT_DWork.UnitDelay_DSTATE_k = localUnitDelay_p;

    /* Update for UnitDelay: '<S59>/Unit Delay' */
    AdvSpT_DWork.UnitDelay_DSTATE_m = localUnitDelay_f;

    /* end of Outputs for SubSystem: '<S53>/F1_01_01_03_Appliquer_retard' */

    /* end of Outputs for SubSystem: '<S49>/F01_01_01_retarder_coupure_reinj' */

    /* Outputs for atomic SubSystem: '<S49>/F01_01_02_Consigne_coupure_selective' *
     * Block requirements for '<S49>/F01_01_02_Consigne_coupure_selective':
     *  1. SubSystem "F01_01_02_Consigne_coupure_selective" !Trace_To : VEMS_R_10_06437_017.01 ;
     *  2. SubSystem "F01_01_02_Consigne_coupure_selective" !Trace_To : VEMS_R_10_06437_012.01 ;
     */

    /* DataTypeConversion: '<S54>/Data Type Conversion15' */
    localSwitch2_d = (Float32)InjSys_noCylCutOffDlyOut;

    /* DataTypeConversion: '<S54>/Data Type Conversion16' incorporates:
     *  Constant: '<S54>/Ext_noCylEng_SC1'
     */
    localSwitch2_a = (Float32)Ext_noCylEng_SC;

    /* Sum: '<S54>/Add10' incorporates:
     *  Constant: '<S54>/Constant16'
     *  Constant: '<S54>/Constant17'
     *  Product: '<S71>/Divide'
     *  Sum: '<S54>/Add11'
     */
    localSwitch2 = 1.0F - ((localSwitch2_d - 1.0F) / localSwitch2_a);

    /* Sum: '<S54>/Add9' */
    localSwitch2_d = localSwitch2_a - localSwitch2_d;

    /* Sum: '<S54>/Add12' incorporates:
     *  Constant: '<S54>/Constant18'
     */
    localAdd12 = ((SInt32)localSwitch2_d) - 1;

    /* DataTypeConversion: '<S54>/Data Type Conversion7' */
    localDataTypeConversion7 = ((Float32)localTmpSignalConversionAtTqS_f) *
      0.0625F;

    /* DataTypeConversion: '<S54>/Data Type Conversion4' */
    localDataTypeConversion4_h = ((Float32)localTmpSignalConversionAtEng_p) *
      0.0625F;

    /* Product: '<S72>/Divide' */
    localSwitch2_d /= localSwitch2_a;

    /* RelationalOperator: '<S79>/LowerRelop1' incorporates:
     *  Constant: '<S54>/Constant10'
     */
    localLowerRelop1 = (localSwitch2_d > 1.0F);

    /* Switch: '<S79>/Switch' incorporates:
     *  Constant: '<S54>/Constant11'
     *  RelationalOperator: '<S79>/UpperRelop'
     */
    if (localSwitch2_d < 0.0F) {
      localSwitch2_d = 0.0F;
    }

    /* Switch: '<S79>/Switch2' incorporates:
     *  Constant: '<S54>/Constant10'
     */
    if (localLowerRelop1) {
      localSwitch2_d = 1.0F;
    }

    /* Product: '<S54>/Product2' */
    localProduct2 = localDataTypeConversion4_h * localSwitch2_d;

    /* RelationalOperator: '<S82>/LowerRelop1' incorporates:
     *  Constant: '<S54>/Constant12'
     */
    localLowerRelop1 = (localSwitch2 > 1.0F);

    /* Switch: '<S82>/Switch' incorporates:
     *  Constant: '<S54>/Constant14'
     *  RelationalOperator: '<S82>/UpperRelop'
     */
    if (localSwitch2 < 0.0F) {
      localSwitch2 = 0.0F;
    }

    /* Switch: '<S82>/Switch2' incorporates:
     *  Constant: '<S54>/Constant12'
     */
    if (localLowerRelop1) {
      localSwitch2 = 1.0F;
    }

    /* DataTypeConversion: '<S54>/Data Type Conversion2' */
    localDataTypeConversion2 = ((Float32)localTmpSignalConversionAtEng_i) *
      0.0625F;

    /* Product: '<S54>/Product4' */
    localProduct4_b = localSwitch2 * localDataTypeConversion2;

    /* Product: '<S54>/Product3' */
    localProduct3 = localSwitch2_d * localDataTypeConversion2;

    /* Product: '<S73>/Divide' */
    localSwitch2_a = ((Float32)localAdd12) / localSwitch2_a;

    /* RelationalOperator: '<S85>/LowerRelop1' incorporates:
     *  Constant: '<S54>/Constant13'
     */
    localLowerRelop1 = (localSwitch2_a > 1.0F);

    /* Switch: '<S85>/Switch' incorporates:
     *  Constant: '<S54>/Constant15'
     *  RelationalOperator: '<S85>/UpperRelop'
     */
    if (localSwitch2_a < 0.0F) {
      localSwitch2_a = 0.0F;
    }

    /* Switch: '<S85>/Switch2' incorporates:
     *  Constant: '<S54>/Constant13'
     */
    if (localLowerRelop1) {
      localSwitch2_a = 1.0F;
    }

    /* Product: '<S54>/Product5' */
    localSwitch2_a *= localDataTypeConversion4_h;

    /* If: '<S54>/If' incorporates:
     *  ActionPort: '<S69>/Action Port'
     *  ActionPort: '<S70>/Action Port'
     *  Constant: '<S54>/IgSys_bInh_SelCutOff_C'
     *  SubSystem: '<S54>/F01_If'
     *  SubSystem: '<S54>/F02_Else'
     */
    if (IgSys_bInh_SelCutOff_C) {
      /* Constant: '<S69>/Constant2' */
      IgSys_noCylCutOffSwt_MP = 0U;
    } else {
      /* Sum: '<S70>/Add2' */
      localSwitch2_d = localProduct4_b - localProduct2;

      /* If: '<S70>/If' incorporates:
       *  ActionPort: '<S86>/Action Port'
       *  ActionPort: '<S87>/Action Port'
       *  Constant: '<S70>/Constant4'
       *  RelationalOperator: '<S70>/Relational Operator4'
       *  SubSystem: '<S70>/F01_Condition1'
       *  SubSystem: '<S70>/F01_Condition1_else'
       */
      if (localSwitch2_d > 0.0F) {
        /* DataTypeConversion: '<S86>/Data Type Conversion6' incorporates:
         *  Constant: '<S86>/IgSys_tqIdcEngCurMinThd_NoRcv_C'
         */
        localSwitch2 = ((Float32)IgSys_tqIdcEngCurMinThd_NoRcv_C) * 0.0625F;

        /* Product: '<S86>/Product6' incorporates:
         *  Constant: '<S86>/IgSys_noCylMaxCutOff_C1'
         *  DataTypeConversion: '<S86>/Data Type Conversion9'
         *  MinMax: '<S86>/MinMax1'
         */
        localDataTypeConversion2 = (((Float32)IgSys_rtqIdcEngCurMin_NoRcv_C) *
          9.999999776E-003F) * rt_MAXf(localSwitch2, localSwitch2_d);
      } else {
        /* DataTypeConversion: '<S87>/Data Type Conversion8' incorporates:
         *  Constant: '<S87>/IgSys_tqIdcEngCurMinThd_Rcv_C'
         */
        localSwitch2 = ((Float32)IgSys_tqIdcEngCurMinThd_Rcv_C) * 0.0625F;

        /* Product: '<S87>/Product1' incorporates:
         *  Abs: '<S87>/Abs1'
         *  Constant: '<S87>/IgSys_noCylMaxCutOff_C2'
         *  DataTypeConversion: '<S87>/Data Type Conversion10'
         *  MinMax: '<S87>/MinMax3'
         */
        localDataTypeConversion2 = (((Float32)IgSys_rtqIdcEngCurMin_Rcv_C) *
          9.999999776E-003F) * ACTEMS_FabsF(rt_MINf(localSwitch2_d, localSwitch2));
      }

      /* Sum: '<S70>/Add3' */
      localSwitch2 = localProduct3 - localSwitch2_a;

      /* If: '<S70>/If1' incorporates:
       *  ActionPort: '<S88>/Action Port'
       *  ActionPort: '<S89>/Action Port'
       *  Constant: '<S70>/Constant6'
       *  RelationalOperator: '<S70>/Relational Operator8'
       *  SubSystem: '<S70>/F02_Condition2'
       *  SubSystem: '<S70>/F02_Condition2_else'
       */
      if (localSwitch2 > 0.0F) {
        /* DataTypeConversion: '<S88>/Data Type Conversion12' incorporates:
         *  Constant: '<S88>/IgSys_tqIdcEngCurMinThdNoRcvSC_C'
         */
        localSwitch2_d = ((Float32)IgSys_tqIdcEngCurMinThdNoRcvSC_C) * 0.0625F;

        /* Product: '<S88>/Product7' incorporates:
         *  Constant: '<S88>/IgSys_rtqIdcEngCurMinNoRcvSC_C'
         *  DataTypeConversion: '<S88>/Data Type Conversion11'
         *  MinMax: '<S88>/MinMax5'
         */
        localSwitch2 = (((Float32)IgSys_rtqIdcEngCurMinNoRcvSC_C) *
                        9.999999776E-003F) * rt_MAXf(localSwitch2_d,
          localSwitch2);
      } else {
        /* Constant: '<S89>/Constant5' */
        localSwitch2 = 0.0F;
      }

      /* Sum: '<S70>/Add4' */
      localSwitch2 += localSwitch2_a;

      /* Sum: '<S70>/Add13' incorporates:
       *  DataTypeConversion: '<S70>/Data Type Conversion13'
       *  DataTypeConversion: '<S70>/Data Type Conversion14'
       *  MinMax: '<S70>/MinMax'
       *  MinMax: '<S70>/MinMax4'
       *  RelationalOperator: '<S70>/Relational Operator2'
       *  RelationalOperator: '<S70>/Relational Operator7'
       *  Sum: '<S70>/Add1'
       */
      localAdd12 = (InjSys_noCylCutOffDlyOut - (localDataTypeConversion7 >=
        (rt_MINf(localProduct2, localProduct4_b) + localDataTypeConversion2))) +
        (localDataTypeConversion7 <= rt_MINf(localProduct3, localSwitch2));
      if (localAdd12 <= 0) {
        IgSys_noCylCutOffInc_MP = 0U;
      } else if (localAdd12 > 255) {
        IgSys_noCylCutOffInc_MP = MAX_uint8_T;
      } else {
        IgSys_noCylCutOffInc_MP = (UInt8)localAdd12;
      }

      /* SignalConversion: '<S70>/Signal Conversion2' */
      IgSys_noCylCutOffSwt_MP = IgSys_noCylCutOffInc_MP;
    }

    /* Switch: '<S54>/Switch1' incorporates:
     *  Constant: '<S54>/IgSys_tCoMesSftyVal_C'
     */
    if (localNot_h) {
      IgSys_tSelTCoUsr_MP = IgSys_tCoMesSftyVal_C;
    } else {
      IgSys_tSelTCoUsr_MP = localTmpSignalConversionAtExt_t;
    }

    /* Switch: '<S54>/Switch2' incorporates:
     *  Constant: '<S54>/Constant1'
     *  Constant: '<S54>/Ext_noCylEng_SC'
     *  Constant: '<S54>/IgSys_nEngThd_CutOff_C'
     *  Constant: '<S54>/IgSys_noCylMaxCutOff_C'
     *  Constant: '<S54>/IgSys_tCoThd_CutOff_C'
     *  Constant: '<S54>/IgSys_tOxCThdMax_CutOff_C'
     *  Constant: '<S54>/IgSys_tOxCThdMin_CutOff_C'
     *  Logic: '<S54>/Logical Operator'
     *  RelationalOperator: '<S54>/Relational Operator1'
     *  RelationalOperator: '<S54>/Relational Operator3'
     *  RelationalOperator: '<S54>/Relational Operator5'
     *  RelationalOperator: '<S54>/Relational Operator6'
     *  Sum: '<S54>/Add3'
     */
    if ((((localTmpSignalConversionAtExt_n > IgSys_nEngThd_CutOff_C) &&
          (IgSys_tSelTCoUsr_MP > IgSys_tCoThd_CutOff_C)) &&
         (localTmpSignalConversionAtExM_t > IgSys_tOxCThdMin_CutOff_C)) &&
        (localTmpSignalConversionAtExM_t < IgSys_tOxCThdMax_CutOff_C)) {
      localAdd12 = Ext_noCylEng_SC - 1;
      if (localAdd12 <= 0) {
        IgSys_noCylCutOff_MP = 0U;
      } else {
        IgSys_noCylCutOff_MP = (UInt8)localAdd12;
      }
    } else {
      IgSys_noCylCutOff_MP = IgSys_noCylMaxCutOff_C;
    }

    /* MinMax: '<S54>/MinMax2' */
    localTmpSignalConversionAtIg_f2 = (UInt8)rt_MIN(IgSys_noCylCutOff_MP,
      localTmpSignalConversionAtTqS_d);

    /* Switch: '<S76>/Switch2' incorporates:
     *  Constant: '<S54>/Constant3'
     *  RelationalOperator: '<S76>/LowerRelop1'
     *  RelationalOperator: '<S76>/UpperRelop'
     *  Switch: '<S76>/Switch'
     */
    if (!(IgSys_noCylCutOffSwt_MP > localTmpSignalConversionAtIg_f2)) {
      localTmpSignalConversionAtIg_f2 = IgSys_noCylCutOffSwt_MP;
    }

    /* SignalConversion: '<S54>/Signal Conversion' */
    AdvSpT_B.Merge1_c = localTmpSignalConversionAtIg_f2;

    /* end of Outputs for SubSystem: '<S49>/F01_01_02_Consigne_coupure_selective' */
  }

  /* end of Outputs for SubSystem: '<S13>/F01_01_activation_calcul_consigne_coupure' */

  /* SignalConversion: '<S13>/TmpSignal ConversionAtIgSys_noCylCutOffTar_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_noCylCutOffTar_INPUT'
   */
  Rte_Read_R_IgSys_noCylCutOffTar_IgSys_noCylCutOffTar
    (&localTmpSignalConversionAtIgS_n);

  /* Outputs for enable SubSystem: '<S13>/F01_01_activation_calcul_consigne_coupure_Default' incorporates:
   *  EnablePort: '<S50>/IgSys_bAcvStructAdv_NOT'
   *  Logic: '<S13>/Logical Operator'
   *
   * Block requirements for '<S13>/F01_01_activation_calcul_consigne_coupure_Default':
   *  1. SubSystem "F01_01_activation_calcul_consigne_coupure_Default" !Trace_To : VEMS_R_10_06437_011.01 ;
   */
  if (!localTmpSignalConversionAtIgS_j) {
    /* SignalConversion: '<S50>/Signal Conversion4' */
    AdvSpT_B.Merge1_c = localTmpSignalConversionAtIgS_n;
  }

  /* end of Outputs for SubSystem: '<S13>/F01_01_activation_calcul_consigne_coupure_Default' */

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Byp_Fonction_SC'
   *  Constant: '<S52>/Int_BypC'
   */
  if (ADVSPT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIg_f2 = IgSys_noCylCutOffTar_B;
  } else {
    localTmpSignalConversionAtIg_f2 = AdvSpT_B.Merge1_c;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtIgSys_noCylCutOffTarInport2' */
  Rte_Write_P_IgSys_noCylCutOffTar_IgSys_noCylCutOffTar
    (localTmpSignalConversionAtIg_f2);
}

/* Model initialize function */
void Runnable_AdvSp_Init(void)
{
  /* Registration code */

  /* block I/O */
  {
    AdvSpT_B.Merge1_g = 96U;
    AdvSpT_B.Merge2_f = 96U;
    AdvSpT_B.Merge3 = 96U;
    AdvSpT_B.Merge4 = 96U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   */
  RE_AdvSpT_001_MSE_Start();
  RE_AdvSpT_005_MSE_Start();
  RE_AdvSpT_002_DRE_Start();
  RE_AdvSpT_006_DRE_Start();
  RE_AdvSpT_004_DRE_Start();
  AdvSpT_PrevZCSigState.F1_01_01_02_Detecter_coupure_Tr = POS_ZCSIG;
}

#define AdvSpT_STOP_SEC_CODE
#include "AdvSpT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
