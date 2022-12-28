/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : InThMdlT                                                */
/* !Description     : InThMdlT Software Component                             */
/*                                                                            */
/* !Module          : InThMdlT                                                */
/* !Description     : InThMdlT Software Component                             */
/*                                                                            */
/* !File            : InThMdlT.c                                              */
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
/*   Model name       : InThMdlT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /InThMdlT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M03-InThMdlT/5-S$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   17 Nov 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InThMdlT.h"
#include "InThMdlT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define InThMdlT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "InThMdlT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InThMdlT InThMdlT_B;

#define InThMdlT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "InThMdlT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define INTHMDLT_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define INTHMDLT_VEMSRTLIBT_MINOR_VERSION_REQ 8
#define INTHMDLT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define INTHMDLT_VEMSRTLIBT_VERSION_REQ (INTHMDLT_VEMSRTLIBT_PATCH_VERSION_REQ + INTHMDLT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + INTHMDLT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if INTHMDLT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define InThMdlT_START_SEC_CODE
#include "InThMdlT_MemMap.h"

void InThMdlT_ASYNC1(int controlPortIdx)
{
}

void InThMdlT_ASYNC2(int controlPortIdx)
{
}

void InThMdlT_ASYNC3(int controlPortIdx)
{
}

void InThMdlT_ASYNC4(int controlPortIdx)
{
}

void InThMdlT_ASYNC5(int controlPortIdx)
{
}

void InThMdlT_ASYNC6(int controlPortIdx)
{
}

void InThMdlT_ASYNC7(int controlPortIdx)
{
}

/*
 * Output and update for action system:
 *    '<S9>/If Action Subsystem1'
 *    '<S14>/If Action Subsystem1'
 *    '<S15>/If Action Subsystem1'
 */
void InThMdlT_IfActionSubsystem1(UInt16 rtu_InThM_tEGRInMnf1, UInt16
  *rty_InThM_tEGRInMnf)
{
  /* SignalConversion: '<S17>/Signal Conversion' */
  (*rty_InThM_tEGRInMnf) = rtu_InThM_tEGRInMnf1;
}

/* Start for exported function: RE_InThMdlT_001_MSE */
void RE_InThMdlT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Reset_manifold_parameters'
   *
   * Block requirements for '<S1>/F01_Reset_manifold_parameters':
   *  1. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  2. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_039.01 ;
   *  3. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_050.01 ;
   *  4. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_040.01 ;
   *  5. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_051.02 ;
   *  6. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_036.01 ;
   *  7. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_049.01 ;
   *  8. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_048.01 ;
   *  9. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_047.01 ;
   *  10. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_045.02 ;
   *  11. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_041.01 ;
   *  12. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_060.02 ;
   *  13. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_059.02 ;
   *  14. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_061.02 ;
   *  15. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_062.02 ;
   *  16. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_076.01 ;
   *  17. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_075.01 ;
   *  18. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_074.01 ;
   *  19. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_014.01 ;
   *  20. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_011.01 ;
   *  21. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_012.01 ;
   *  22. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_013.01 ;
   *  23. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_007.01 ;
   *  24. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_008.01 ;
   *  25. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_009.01 ;
   *  26. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_003.01 ;
   *  27. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_002.01 ;
   *  28. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_001.01 ;
   *  29. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_101.01 ;
   */
}

/* Output and update for exported function: RE_InThMdlT_001_MSE */
void RE_InThMdlT_001_MSE(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtInThM;
  UInt16 localMerge3;
  UInt8 localTmpSignalConversionAtEng_s;
  Boolean localRelationalOperator;
  Float32 localSum;
  SInt16 localTmpSignalConversionAtExt_t;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt16 localDataTypeConversion4;
  Float32d localtmp;
  SInt32 localtmp_0;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Reset_manifold_parameters'
   *
   * Block requirements for '<S1>/F01_Reset_manifold_parameters':
   *  1. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  2. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_039.01 ;
   *  3. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_050.01 ;
   *  4. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_040.01 ;
   *  5. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_051.02 ;
   *  6. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_036.01 ;
   *  7. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_049.01 ;
   *  8. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_048.01 ;
   *  9. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_047.01 ;
   *  10. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_045.02 ;
   *  11. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_041.01 ;
   *  12. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_060.02 ;
   *  13. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_059.02 ;
   *  14. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_061.02 ;
   *  15. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_062.02 ;
   *  16. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_076.01 ;
   *  17. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_075.01 ;
   *  18. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_074.01 ;
   *  19. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_014.01 ;
   *  20. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_011.01 ;
   *  21. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_012.01 ;
   *  22. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_013.01 ;
   *  23. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_007.01 ;
   *  24. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_008.01 ;
   *  25. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_009.01 ;
   *  26. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_003.01 ;
   *  27. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_002.01 ;
   *  28. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_001.01 ;
   *  29. SubSystem "F01_Reset_manifold_parameters" !Trace_To : VEMS_R_10_07130_101.01 ;
   */

  /* user code (Output function Body for TID14) */
  RE_InThMdl_Init();

  /* SignalConversion: '<S9>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&localTmpSignalConversionAtUsThr);

  /* DataTypeConversion: '<S9>/Data Type Conversion4' */
  localDataTypeConversion4 = (UInt16)((SInt32)(((UInt32)((SInt32)
    localTmpSignalConversionAtUsThr)) >> 2));

  /* SignalConversion: '<S18>/copy' */
  InThM_tEGRUsEGRVlv_IRV_MP = localDataTypeConversion4;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S18>/autosar_testpoint1' */

  /* S-Function Block: <S18>/autosar_testpoint1 */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* RelationalOperator: '<S9>/Relational Operator' incorporates:
   *  Constant: '<S9>/Ext_stRun_SC'
   */
  localRelationalOperator = (localTmpSignalConversionAtEng_s == Ext_stRun_SC);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tEGRInMnf1Outport2' incorporates:
   *  Inport: '<Root>/InThM_tEGRInMnf_INPUT'
   */
  Rte_Read_R_InThM_tEGRInMnf_InThM_tEGRInMnf(&localTmpSignalConversionAtInThM);

  /* If: '<S9>/If' incorporates:
   *  ActionPort: '<S16>/Action Port'
   *  ActionPort: '<S17>/Action Port'
   *  Logic: '<S9>/Logical Operator'
   *  SubSystem: '<S9>/F01_01_Reset_egr_manifold_temperature'
   *  SubSystem: '<S9>/If Action Subsystem1'
   *
   * Block requirements for '<S9>/F01_01_Reset_egr_manifold_temperature':
   *  1. SubSystem "F01_01_Reset_egr_manifold_temperature" !Trace_To : VEMS_R_10_07130_004.01 ;
   */
  if (!localRelationalOperator) {
    /* SignalConversion: '<S16>/Signal Conversion' */
    localMerge3 = localDataTypeConversion4;
  } else {
    InThMdlT_IfActionSubsystem1(localTmpSignalConversionAtInThM, &localMerge3);
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S9>/Ext_rSqrtGainRef2_SC'
   *  Constant: '<S9>/Ext_rSqrtOfsRef2_SC'
   *  Product: '<S27>/Divide'
   */
  localSum = ((Float32)((ACTEMS_LdexpF((Float32d)localTmpSignalConversionAtUsThr,
    -7) + 223.0F) * ACTEMS_LdexpF((Float32d)Ext_rSqrtGainRef2_SC, -32))) +
    (((Float32)Ext_rSqrtOfsRef2_SC) * 3.725290298E-009F);

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Byp_Fonction_SC'
   *  Constant: '<S20>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsThr = InThM_tEGRInMnf_B;
  } else {
    localTmpSignalConversionAtUsThr = localMerge3;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tEGRInMnfInport2' */
  Rte_Write_P_InThM_tEGRInMnf_InThM_tEGRInMnf(localTmpSignalConversionAtUsThr);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tEGRUsEGRVlv_irvInport2' incorporates:
   *  SignalConversion: '<S9>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_InThMdlT_001_MSE_InThM_tEGRUsEGRVlv_irv
    (localDataTypeConversion4);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Byp_Fonction_SC'
   *  Constant: '<S22>/Int_BypC'
   *  DataTypeConversion: '<S22>/Data Type Conversion'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEng_s = InThM_tSqrtEgUsEGRVlv_B;
  } else {
    localtmp = ACTEMS_LdexpF((Float32d)localSum, 3);
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtEng_s = (UInt8)localtmp;
      } else {
        localTmpSignalConversionAtEng_s = 0U;
      }
    } else {
      localTmpSignalConversionAtEng_s = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tSqrtEgUsEGRVlvInport2' */
  Rte_Write_P_InThM_tSqrtEgUsEGRVlv_InThM_tSqrtEgUsEGRVlv
    (localTmpSignalConversionAtEng_s);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Byp_Fonction_SC'
   *  Constant: '<S26>/Int_BypC'
   *  Constant: '<S9>/Constant9'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsThr = InThM_tMixtInMnf_B;
  } else {
    localTmpSignalConversionAtUsThr = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tMixtInMnfInport2' */
  Rte_Write_P_InThM_tMixtInMnf_InThM_tMixtInMnf(localTmpSignalConversionAtUsThr);

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Byp_Fonction_SC'
   *  Constant: '<S25>/Int_BypC'
   *  Constant: '<S9>/Constant8'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsThr = InThM_tAirUsInVlvEstim_B;
  } else {
    localTmpSignalConversionAtUsThr = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimInport2' */
  Rte_Write_P_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (localTmpSignalConversionAtUsThr);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Byp_Fonction_SC'
   *  Constant: '<S23>/Int_BypC'
   *  Constant: '<S9>/Constant7'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsThr = InThM_tInMnfEstim_B;
  } else {
    localTmpSignalConversionAtUsThr = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tInMnfEstimInport2' */
  Rte_Write_P_InThM_tInMnfEstim_InThM_tInMnfEstim
    (localTmpSignalConversionAtUsThr);

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Byp_Fonction_SC'
   *  Constant: '<S21>/Int_BypC'
   *  Constant: '<S9>/Constant5'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEng_s = InThM_facHeatExcWallInMnf_B;
  } else {
    localTmpSignalConversionAtEng_s = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_facHeatExcWallInMnfInport2' */
  Rte_Write_P_InThM_facHeatExcWallInMnf_InThM_facHeatExcWallInMnf
    (localTmpSignalConversionAtEng_s);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtUsThrM_tDsThrCorMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tDsThrCorMes'
   */
  Rte_Read_R_UsThrM_tDsThrCorMes_UsThrM_tDsThrCorMes
    (&InThMdlT_B.TmpSignalConversionAtUsThrM_tDs);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsThr = InThM_tWallInMnf_B;
  } else {
    localTmpSignalConversionAtUsThr = InThMdlT_B.TmpSignalConversionAtUsThrM_tDs;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tWallInMnfInport2' */
  Rte_Write_P_InThM_tWallInMnf_InThM_tWallInMnf(localTmpSignalConversionAtUsThr);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* Sum: '<S9>/Sum2' incorporates:
   *  Constant: '<S9>/Constant3'
   */
  localtmp_0 = localTmpSignalConversionAtExt_t + 50;
  if (localtmp_0 <= 0) {
    localTmpSignalConversionAtUsThr = 0U;
  } else if (localtmp_0 > 511) {
    localTmpSignalConversionAtUsThr = MAX_uint16_T;
  } else {
    localTmpSignalConversionAtUsThr = (UInt16)(localtmp_0 << 7);
  }

  /* SignalConversion: '<S19>/copy' */
  InThM_tWallInCylHead_IRV_MP = localTmpSignalConversionAtUsThr;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S19>/autosar_testpoint1' */

  /* S-Function Block: <S19>/autosar_testpoint1 */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtInThM_tWallInCylHead_irvInport2' incorporates:
   *  SignalConversion: '<S9>/Signal Conversion'
   */
  Rte_IrvWrite_RE_InThMdlT_001_MSE_InThM_tWallInCylHead_irv
    (localTmpSignalConversionAtUsThr);
}

/* Start for exported function: RE_InThMdlT_002_TEV */
void RE_InThMdlT_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F06_Egr_manifold_temp'
   *
   * Block requirements for '<S1>/F06_Egr_manifold_temp':
   *  1. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_005.01 ;
   *  2. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_051.02 ;
   *  3. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_038.01 ;
   *  4. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_039.01 ;
   *  5. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  6. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_060.02 ;
   *  7. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_061.02 ;
   *  8. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_036.01 ;
   *  9. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_063.01 ;
   */
}

/* Output and update for exported function: RE_InThMdlT_002_TEV */
void RE_InThMdlT_002_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtInM_m;
  UInt16 localTmpSignalConversionAtInT_i;
  UInt16 localMerge3_c;
  UInt8 localLookUpTable;
  UInt8 localTmpSignalConversionAtEng_k;
  Boolean localRelationalOperator_h;
  Float32 localDataTypeConversion2;
  Float32 localSum8;
  UInt16 localTmpSignalConversionAtInT_p;
  UInt16 localTmpSignalConversionAtUsT_a;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F06_Egr_manifold_temp'
   *
   * Block requirements for '<S1>/F06_Egr_manifold_temp':
   *  1. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_005.01 ;
   *  2. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_051.02 ;
   *  3. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_038.01 ;
   *  4. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_039.01 ;
   *  5. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  6. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_060.02 ;
   *  7. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_061.02 ;
   *  8. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_036.01 ;
   *  9. SubSystem "F06_Egr_manifold_temp" !Trace_To : VEMS_R_10_07130_063.01 ;
   */

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&localTmpSignalConversionAtInM_m);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInThM_tEGRUsEGRVlv_irvOutport2' */
  localTmpSignalConversionAtInT_p =
    Rte_IrvRead_RE_InThMdlT_002_TEV_InThM_tEGRUsEGRVlv_irv();

  /* SignalConversion: '<S14>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&localTmpSignalConversionAtUsT_a);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_k);

  /* RelationalOperator: '<S14>/Relational Operator' incorporates:
   *  Constant: '<S14>/Ext_stRun_SC'
   */
  localRelationalOperator_h = (localTmpSignalConversionAtEng_k == Ext_stRun_SC);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInThM_tEGRInMnf1Outport2' incorporates:
   *  Inport: '<Root>/InThM_tEGRInMnf_INPUT'
   */
  Rte_Read_R_InThM_tEGRInMnf_InThM_tEGRInMnf(&localTmpSignalConversionAtInT_i);

  /* If: '<S14>/If' incorporates:
   *  ActionPort: '<S89>/Action Port'
   *  ActionPort: '<S90>/Action Port'
   *  SubSystem: '<S14>/F06_01_Egr_mnfld_temp'
   *  SubSystem: '<S14>/If Action Subsystem1'
   *
   * Block requirements for '<S14>/F06_01_Egr_mnfld_temp':
   *  1. SubSystem "F06_01_Egr_mnfld_temp" !Trace_To : VEMS_R_10_07130_006.01 ;
   */
  if (localRelationalOperator_h) {
    /* Lookup: '<S92>/Look-Up Table'
     * About '<S92>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U8  2^-7
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable), (&(InThM_facHeatExgWallEGRPipe_T[0])),
                  localTmpSignalConversionAtInM_m, (&(Air_mfEGR_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S92>/Data Type Duplicate1'
     *
     * Regarding '<S92>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataStoreWrite: '<S89>/Data Store Write1' */
    InThM_facHeatExcWallEGRPipe_MP = localLookUpTable;

    /* DataTypeConversion: '<S89>/Data Type Conversion2' */
    localDataTypeConversion2 = (((Float32)localTmpSignalConversionAtUsT_a) *
      0.0078125F) + 223.0F;

    /* Sum: '<S89>/Sum8' incorporates:
     *  Product: '<S93>/Divide'
     *  SignalConversion: '<S14>/TmpSignal ConversionAtInThM_tWallInCylHead_irvOutport2'
     *  Sum: '<S89>/Sum7'
     */
    localSum8 = (223.0F - (((((Float32)localTmpSignalConversionAtInT_p) *
      0.03125F) - (((Float32)
                    Rte_IrvRead_RE_InThMdlT_002_TEV_InThM_tWallInCylHead_irv()) *
                   0.0078125F)) * (((Float32)localLookUpTable) * 0.0078125F)))
      + (((Float32)localTmpSignalConversionAtInT_p) * 0.03125F);

    /* MinMax: '<S89>/MinMax' */
    localtmp = ACTEMS_LdexpF(((Float32d)rt_MAXf(localSum8,
      localDataTypeConversion2)) - 223.0F, 5);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localMerge3_c = (UInt16)localtmp;
      } else {
        localMerge3_c = 0U;
      }
    } else {
      localMerge3_c = MAX_uint16_T;
    }
  } else {
    InThMdlT_IfActionSubsystem1(localTmpSignalConversionAtInT_i, &localMerge3_c);
  }

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Byp_Fonction_SC'
   *  Constant: '<S91>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtInT_p = InThM_tEGRInMnf_B;
  } else {
    localTmpSignalConversionAtInT_p = localMerge3_c;
  }

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInThM_tEGRInMnfInport2' */
  Rte_Write_P_InThM_tEGRInMnf_InThM_tEGRInMnf(localTmpSignalConversionAtInT_p);
}

/* Start for exported function: RE_InThMdlT_007_TEV */
void RE_InThMdlT_007_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F04_Calc_manifold'
   *
   * Block requirements for '<S1>/F04_Calc_manifold':
   *  1. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_078.01 ;
   *  2. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_044.02 ;
   *  3. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_056.01 ;
   *  4. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  5. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_038.01 ;
   *  6. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_055.01 ;
   *  7. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_060.02 ;
   *  8. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_051.02 ;
   *  9. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_045.02 ;
   *  10. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_047.01 ;
   *  11. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_048.01 ;
   *  12. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_049.01 ;
   *  13. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_067.02 ;
   *  14. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_080.01 ;
   *  15. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_079.01 ;
   *  16. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_103.01 ;
   *  17. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_104.01 ;
   *  18. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_039.01 ;
   *  19. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_052.01 ;
   *  20. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_101.01 ;
   *  21. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_102.01 ;
   */
}

/* Output and update for exported function: RE_InThMdlT_007_TEV */
void RE_InThMdlT_007_TEV(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion_l;
  UInt16 localDataTypeConversion_p;
  UInt16 localSwitch2;
  UInt16 localLookUpTable2D;
  UInt16 localDataTypeConversion_n;
  UInt16 localDataTypeConversion_o;
  UInt16 localTmpSignalConversionAtInM_p;
  UInt16 localDataTypeConversion2_fd;
  SInt16 localLookUpTable2D_p;
  SInt16 localDataTypeConversion3_k;
  Boolean localRte_Call_R_FRM_bInhInThMEn;
  UInt8 localLookUpTable2D_i;
  UInt8 localLookUpTable_n;
  UInt8 localLookUpTable_l;
  UInt16 localMerge;
  Float32 localSwitch_h;
  Float32 localDivide_kn;
  Boolean localTmpSignalConversionAtEGRVl;
  UInt16 localMerge_n;
  UInt16 localMerge_c;
  UInt16 localInThM_tMixtInMnf;
  UInt8 localTmpSignalConversionAtInT_n;
  UInt8 localSwitch_o;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F04_Calc_manifold'
   *
   * Block requirements for '<S1>/F04_Calc_manifold':
   *  1. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_078.01 ;
   *  2. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_044.02 ;
   *  3. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_056.01 ;
   *  4. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  5. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_038.01 ;
   *  6. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_055.01 ;
   *  7. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_060.02 ;
   *  8. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_051.02 ;
   *  9. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_045.02 ;
   *  10. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_047.01 ;
   *  11. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_048.01 ;
   *  12. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_049.01 ;
   *  13. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_067.02 ;
   *  14. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_080.01 ;
   *  15. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_079.01 ;
   *  16. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_103.01 ;
   *  17. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_104.01 ;
   *  18. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_039.01 ;
   *  19. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_052.01 ;
   *  20. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_101.01 ;
   *  21. SubSystem "F04_Calc_manifold" !Trace_To : VEMS_R_10_07130_102.01 ;
   */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&InThMdlT_B.TmpSignalConversionAtEng_stEruO);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes
    (&InThMdlT_B.TmpSignalConversionAtUsThrM_tTh);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&InThMdlT_B.TmpSignalConversionAtInM_mfEGRE);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mfTotExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfTotExCor'
   */
  Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor
    (&InThMdlT_B.TmpSignalConversionAtEngM_mfTot);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEGRVlv_bClnEGRFoulOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_bClnEGRFoul'
   */
  Rte_Read_R_EGRVlv_bClnEGRFoul_EGRVlv_bClnEGRFoul
    (&localTmpSignalConversionAtEGRVl);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_tEGRInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_tEGRInMnf_INPUT'
   */
  Rte_Read_R_InThM_tEGRInMnf_InThM_tEGRInMnf
    (&InThMdlT_B.TmpSignalConversionAtInThM_tEGR);

  /* Outputs for atomic SubSystem: '<S12>/F04_1_Calc_manifold_raw_temperature' *
   * Block requirements for '<S12>/F04_1_Calc_manifold_raw_temperature':
   *  1. SubSystem "F04_1_Calc_manifold_raw_temperature" !Trace_To : VEMS_R_10_07130_081.01 ;
   */

  /* If: '<S35>/If' incorporates:
   *  ActionPort: '<S49>/Action Port'
   *  ActionPort: '<S50>/Action Port'
   *  Constant: '<S35>/Ext_stRun_SC'
   *  RelationalOperator: '<S35>/Relational Operator'
   *  SubSystem: '<S35>/F04_1_1_Reset_manifold_raw_temperature'
   *  SubSystem: '<S35>/F04_1_2_Manifold_raw_temperature'
   *
   * Block requirements for '<S35>/F04_1_1_Reset_manifold_raw_temperature':
   *  1. SubSystem "F04_1_1_Reset_manifold_raw_temperature" !Trace_To : VEMS_R_10_07130_082.01 ;
   *
   * Block requirements for '<S35>/F04_1_2_Manifold_raw_temperature':
   *  1. SubSystem "F04_1_2_Manifold_raw_temperature" !Trace_To : VEMS_R_10_07130_083.01 ;
   */
  if (InThMdlT_B.TmpSignalConversionAtEng_stEruO == Ext_stRun_SC) {
    /* DataTypeConversion: '<S50>/Data Type Conversion4' */
    localSwitch_h = (((Float32)InThMdlT_B.TmpSignalConversionAtUsThrM_tTh) *
                     0.0078125F) + 223.0F;

    /* Product: '<S51>/Divide' incorporates:
     *  DataTypeConversion: '<S50>/Data Type Conversion1'
     *  DataTypeConversion: '<S50>/Data Type Conversion2'
     */
    localDivide_kn = (((Float32)InThMdlT_B.TmpSignalConversionAtInM_mfEGRE) *
                      1.525878906E-005F) / (((Float32)
      InThMdlT_B.TmpSignalConversionAtEngM_mfTot) * 1.525878906E-005F);

    /* Outputs for atomic SubSystem: '<S51>/If Action Subsystem3' */

    /* Switch: '<S55>/Switch1' incorporates:
     *  Constant: '<S55>/Constant1'
     *  Constant: '<S55>/Constant2'
     *  Constant: '<S55>/Constant3'
     *  Logic: '<S55>/Logical Operator1'
     *  RelationalOperator: '<S55>/Relational Operator'
     *  RelationalOperator: '<S55>/Relational Operator1'
     *  RelationalOperator: '<S55>/Relational Operator3'
     */
    if (((localDivide_kn != localDivide_kn) || (localDivide_kn >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_kn)) {
      localDivide_kn = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S51>/If Action Subsystem3' */

    /* Switch: '<S50>/Switch' incorporates:
     *  Constant: '<S50>/Constant'
     *  DataTypeConversion: '<S50>/Data Type Conversion3'
     *  Product: '<S52>/Divide'
     *  Product: '<S53>/Divide'
     *  Sum: '<S50>/Sum10'
     *  Sum: '<S50>/Sum8'
     */
    if (!localTmpSignalConversionAtEGRVl) {
      localSwitch_h = (((((Float32)InThMdlT_B.TmpSignalConversionAtInThM_tEGR) *
                         0.03125F) + 223.0F) * localDivide_kn) + ((1.0F -
        localDivide_kn) * localSwitch_h);
    }

    /* DataTypeConversion: '<S50>/Data Type Conversion5' */
    localtmp = ACTEMS_LdexpF(((Float32d)localSwitch_h) - 223.0F, 7);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localInThM_tMixtInMnf = (UInt16)localtmp;
      } else {
        localInThM_tMixtInMnf = 0U;
      }
    } else {
      localInThM_tMixtInMnf = MAX_uint16_T;
    }
  } else {
    /* SignalConversion: '<S49>/Signal Conversion' */
    localInThM_tMixtInMnf = InThMdlT_B.TmpSignalConversionAtUsThrM_tTh;
  }

  /* end of Outputs for SubSystem: '<S12>/F04_1_Calc_manifold_raw_temperature' */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_facHeatExcWallInMnf_INPUTOutport2' incorporates:
   *  Inport: '<Root>/InThM_facHeatExcWallInMnf_INPUT'
   */
  Rte_Read_R_InThM_facHeatExcWallInMnf_InThM_facHeatExcWallInMnf
    (&localTmpSignalConversionAtInT_n);

  /* Outputs for atomic SubSystem: '<S12>/F04_2_Manifold_heat_transfert_factor' *
   * Block requirements for '<S12>/F04_2_Manifold_heat_transfert_factor':
   *  1. SubSystem "F04_2_Manifold_heat_transfert_factor" !Trace_To : VEMS_R_10_07130_084.01 ;
   */

  /* If: '<S36>/If' incorporates:
   *  ActionPort: '<S56>/Action Port'
   *  ActionPort: '<S57>/Action Port'
   *  Constant: '<S36>/Ext_stRun_SC'
   *  RelationalOperator: '<S36>/Relational Operator'
   *  SubSystem: '<S36>/F04_2_1_Calc_manifold_heat_transfert_factor'
   *  SubSystem: '<S36>/F04_2_2_Calc_manifold_heat_transfer_factor_Default'
   *
   * Block requirements for '<S36>/F04_2_1_Calc_manifold_heat_transfert_factor':
   *  1. SubSystem "F04_2_1_Calc_manifold_heat_transfert_factor" !Trace_To : VEMS_R_10_07130_085.01 ;
   *
   * Block requirements for '<S36>/F04_2_2_Calc_manifold_heat_transfer_factor_Default':
   *  1. SubSystem "F04_2_2_Calc_manifold_heat_transfer_factor_Default" !Trace_To : VEMS_R_10_07130_082.01 ;
   */
  if (InThMdlT_B.TmpSignalConversionAtEng_stEruO == Ext_stRun_SC) {
    /* DataTypeConversion: '<S58>/Data Type Conversion' */
    localDataTypeConversion_o = InThMdlT_B.TmpSignalConversionAtEngM_mfTot;

    /* Lookup: '<S58>/Look-Up Table'
     * About '<S58>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U8  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_l), (&(InThM_facHeatExcWallInMnf_T[0])),
                  localDataTypeConversion_o, (&(Air_mfAir_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate1'
     *
     * Regarding '<S58>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* SignalConversion: '<S56>/Signal Conversion1' */
    localTmpSignalConversionAtInT_n = localLookUpTable_l;
  }

  /* end of Outputs for SubSystem: '<S12>/F04_2_Manifold_heat_transfert_factor' */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_tWallInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_tWallInMnf_INPUT'
   */
  Rte_Read_R_InThM_tWallInMnf_InThM_tWallInMnf
    (&InThMdlT_B.TmpSignalConversionAtInThM_tWal);

  /* Outputs for atomic SubSystem: '<S12>/F04_3_Calc_manifold_temperature' *
   * Block requirements for '<S12>/F04_3_Calc_manifold_temperature':
   *  1. SubSystem "F04_3_Calc_manifold_temperature" !Trace_To : VEMS_R_10_07130_086.01 ;
   */

  /* If: '<S37>/If' incorporates:
   *  ActionPort: '<S59>/Action Port'
   *  ActionPort: '<S60>/Action Port'
   *  Constant: '<S37>/Ext_stRun_SC'
   *  RelationalOperator: '<S37>/Relational Operator1'
   *  SubSystem: '<S37>/F04_3_1_Reset_manifold_temperature'
   *  SubSystem: '<S37>/F04_3_2_Manifold_temperature'
   *
   * Block requirements for '<S37>/F04_3_1_Reset_manifold_temperature':
   *  1. SubSystem "F04_3_1_Reset_manifold_temperature" !Trace_To : VEMS_R_10_07130_087.01 ;
   *
   * Block requirements for '<S37>/F04_3_2_Manifold_temperature':
   *  1. SubSystem "F04_3_2_Manifold_temperature" !Trace_To : VEMS_R_10_07130_088.01 ;
   */
  if (InThMdlT_B.TmpSignalConversionAtEng_stEruO == Ext_stRun_SC) {
    /* DataTypeConversion: '<S60>/Data Type Conversion' incorporates:
     *  Product: '<S61>/Divide'
     *  Sum: '<S60>/Sum10'
     *  Sum: '<S60>/Sum3'
     */
    localtmp = ACTEMS_LdexpF(((Float32d)(((((((Float32)
      InThMdlT_B.TmpSignalConversionAtInThM_tWal) * 0.0078125F) - (((Float32)
      localInThM_tMixtInMnf) * 0.0078125F)) * (((Float32)
      localTmpSignalConversionAtInT_n) * 0.00390625F)) + 223.0F) + (((Float32)
      localInThM_tMixtInMnf) * 0.0078125F))) - 223.0F, 7);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localMerge_c = (UInt16)localtmp;
      } else {
        localMerge_c = 0U;
      }
    } else {
      localMerge_c = MAX_uint16_T;
    }
  } else {
    /* SignalConversion: '<S59>/Signal Conversion' */
    localMerge_c = InThMdlT_B.TmpSignalConversionAtUsThrM_tTh;
  }

  /* end of Outputs for SubSystem: '<S12>/F04_3_Calc_manifold_temperature' */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&InThMdlT_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInM_pDsThrCorOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrCor'
   */
  Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&localTmpSignalConversionAtInM_p);

  /* Outputs for atomic SubSystem: '<S12>/F04_6_Calc_Corrected_Engine_Speed' *
   * Block requirements for '<S12>/F04_6_Calc_Corrected_Engine_Speed':
   *  1. SubSystem "F04_6_Calc_Corrected_Engine_Speed" !Trace_To : VEMS_R_10_07130_095.01 ;
   */

  /* If: '<S40>/If' incorporates:
   *  ActionPort: '<S69>/Action Port'
   *  ActionPort: '<S70>/Action Port'
   *  Constant: '<S40>/Ext_stRun_SC'
   *  RelationalOperator: '<S40>/Relational Operator1'
   *  SubSystem: '<S40>/F04_6_1_Reset_corrected_engine_speed'
   *  SubSystem: '<S40>/F04_6_2_Corrected_Engine_Speed'
   *
   * Block requirements for '<S40>/F04_6_1_Reset_corrected_engine_speed':
   *  1. SubSystem "F04_6_1_Reset_corrected_engine_speed" !Trace_To : VEMS_R_10_07130_096.01 ;
   *
   * Block requirements for '<S40>/F04_6_2_Corrected_Engine_Speed':
   *  1. SubSystem "F04_6_2_Corrected_Engine_Speed" !Trace_To : VEMS_R_10_07130_097.01 ;
   */
  if (InThMdlT_B.TmpSignalConversionAtEng_stEruO == Ext_stRun_SC) {
    /* DataTypeConversion: '<S71>/Data Type Conversion' */
    localDataTypeConversion_l = InThMdlT_B.TmpSignalConversionAtExt_nEngOu;

    /* Lookup2D: '<S71>/Look-Up Table (2-D)'
     * About '<S71>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^3
     * Output0 Data Type:  Fixed Point    U16  2^-7  Bias 223.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D), (&(InThM_tInMnfRef_M[0])),
                       localDataTypeConversion_l, (&(Ext_nEngRef1_A[0])), 15U,
                       localTmpSignalConversionAtInM_p, (&(Air_pAir_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S71>/Data Type Duplicate2'
     *
     * Regarding '<S71>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S74>/Divide' incorporates:
     *  DataTypeConversion: '<S70>/Data Type Conversion1'
     *  DataTypeConversion: '<S71>/Data Type Conversion'
     *  DataTypeConversion: '<S74>/Data Type Conversion'
     *  Lookup2D: '<S71>/Look-Up Table (2-D)'
     */
    localSwitch_h = ((((Float32)localMerge_c) * 0.0078125F) + 223.0F) /
      ((((Float32)localLookUpTable2D) * 0.0078125F) + 223.0F);

    /* Outputs for atomic SubSystem: '<S74>/If Action Subsystem3' */

    /* Switch: '<S77>/Switch1' incorporates:
     *  Constant: '<S77>/Constant1'
     *  Constant: '<S77>/Constant2'
     *  Constant: '<S77>/Constant3'
     *  Logic: '<S77>/Logical Operator1'
     *  RelationalOperator: '<S77>/Relational Operator'
     *  RelationalOperator: '<S77>/Relational Operator1'
     *  RelationalOperator: '<S77>/Relational Operator3'
     */
    if (localSwitch_h != localSwitch_h) {
      localSwitch_h = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S74>/If Action Subsystem3' */

    /* DataTypeConversion: '<S74>/Data Type Conversion2' */
    localtmp = ACTEMS_LdexpF(((Float32d)localSwitch_h) - 3.0517578125000000E-005F,
      15);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion2_fd = (UInt16)localtmp;
      } else {
        localDataTypeConversion2_fd = 0U;
      }
    } else {
      localDataTypeConversion2_fd = MAX_uint16_T;
    }

    /* DataStoreWrite: '<S70>/Data Store Write1' */
    InThM_rtInMnf_MP = localDataTypeConversion2_fd;

    /* DataTypeConversion: '<S72>/Data Type Conversion' */
    localDataTypeConversion_p = InThMdlT_B.TmpSignalConversionAtExt_nEngOu;

    /* Lookup2D: '<S72>/Look-Up Table (2-D)'
     * About '<S72>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-15  Bias 3.0517578125000000E-005
     * Output0 Data Type:  Fixed Point    S16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_S16_U16_U16( &(localLookUpTable2D_p), (&(InThM_rEngSpdCor_M[0])),
                       localDataTypeConversion_p, (&(Ext_nEngRef1_A[0])), 15U,
                       localDataTypeConversion2_fd, (&(InThM_rtInMnf_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S72>/Data Type Duplicate2'
     *
     * Regarding '<S72>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S73>/Data Type Conversion'
     *
     * Regarding '<S73>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataStoreWrite: '<S70>/Data Store Write2' */
    InThM_rEngSpdCor_MP = localLookUpTable2D_p;

    /* Lookup: '<S73>/Look-Up Table'
     * About '<S73>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    S16  2^-16
     * Output0 Data Type:  Fixed Point    S16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S16_S16( &(localDataTypeConversion3_k), (&(InThM_rEngSpdCorDB_T[0])),
                   localLookUpTable2D_p, (&(InThM_rEngSpdCor_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S73>/Data Type Duplicate1'
     *
     * Regarding '<S73>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataStoreWrite: '<S70>/Data Store Write3' */
    InThM_rEngSpdCorDB_MP = localDataTypeConversion3_k;

    /* Product: '<S75>/Divide' */
    localSwitch_h = (((Float32)localDataTypeConversion3_k) * 1.525878906E-005F)
      * ((Float32)InThMdlT_B.TmpSignalConversionAtExt_nEngOu);

    /* DataTypeConversion: '<S70>/Data Type Conversion3' */
    localDataTypeConversion3_k = (SInt16)((SInt32)((Float32)ACTEMS_FloorF
      (localSwitch_h)));

    /* DataStoreWrite: '<S70>/Data Store Write4' */
    InThM_nDeltaEngSpd_MP = localDataTypeConversion3_k;

    /* DataTypeConversion: '<S70>/Data Type Conversion' incorporates:
     *  Sum: '<S70>/Sum8'
     */
    localSwitch_h += (Float32)InThMdlT_B.TmpSignalConversionAtExt_nEngOu;
    if (localSwitch_h < 65536.0F) {
      if (localSwitch_h >= 0.0F) {
        InThM_nEngCorWoutDiag = (UInt16)localSwitch_h;
      } else {
        InThM_nEngCorWoutDiag = 0U;
      }
    } else {
      InThM_nEngCorWoutDiag = MAX_uint16_T;
    }
  } else {
    /* SignalConversion: '<S69>/Signal Conversion' */
    InThM_nEngCorWoutDiag = InThMdlT_B.TmpSignalConversionAtExt_nEngOu;
  }

  /* end of Outputs for SubSystem: '<S12>/F04_6_Calc_Corrected_Engine_Speed' */

  /* S-Function (sfun_autosar_clientop): '<S43>/Rte_Call_R_FRM_bInhInThM_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bInhInThM_GetFunctionPermission
    (&localRte_Call_R_FRM_bInhInThMEn);

  /* Logic: '<S43>/Not' */
  localTmpSignalConversionAtEGRVl = !localRte_Call_R_FRM_bInhInThMEn;

  /* S-Function (sfun_autosar_clientop): '<S42>/Rte_Call_R_FRM_bInhInThMEngSpdCor_GetFunctionPermission_sf' */
  Rte_Call_R_FRM_bInhInThMEngSpdCor_GetFunctionPermission
    (&localRte_Call_R_FRM_bInhInThMEn);

  /* Outputs for atomic SubSystem: '<S12>/F04_7_Calc_downgraded_mode_engine_speed' *
   * Block requirements for '<S12>/F04_7_Calc_downgraded_mode_engine_speed':
   *  1. SubSystem "F04_7_Calc_downgraded_mode_engine_speed" !Trace_To : VEMS_R_10_07130_098.01 ;
   */

  /* If: '<S41>/If' incorporates:
   *  ActionPort: '<S78>/Action Port'
   *  ActionPort: '<S79>/Action Port'
   *  Constant: '<S41>/Ext_stRun_SC'
   *  RelationalOperator: '<S41>/Relational Operator1'
   *  SubSystem: '<S41>/F04_7_1_Reset_corrected_engine_speed'
   *  SubSystem: '<S41>/F04_7_2_Corrected_engine_speed'
   *
   * Block requirements for '<S41>/F04_7_1_Reset_corrected_engine_speed':
   *  1. SubSystem "F04_7_1_Reset_corrected_engine_speed" !Trace_To : VEMS_R_10_07130_099.01 ;
   *
   * Block requirements for '<S41>/F04_7_2_Corrected_engine_speed':
   *  1. SubSystem "F04_7_2_Corrected_engine_speed" !Trace_To : VEMS_R_10_07130_100.01 ;
   */
  if (InThMdlT_B.TmpSignalConversionAtEng_stEruO == Ext_stRun_SC) {
    /* Switch: '<S79>/Switch' incorporates:
     *  Logic: '<S42>/Not'
     *  Logic: '<S79>/Logical Operator'
     */
    if ((localTmpSignalConversionAtEGRVl) || (!localRte_Call_R_FRM_bInhInThMEn))
    {
      localMerge = InThMdlT_B.TmpSignalConversionAtExt_nEngOu;
    } else {
      localMerge = InThM_nEngCorWoutDiag;
    }
  } else {
    /* SignalConversion: '<S78>/Signal Conversion' */
    localMerge = InThMdlT_B.TmpSignalConversionAtExt_nEngOu;
  }

  /* end of Outputs for SubSystem: '<S12>/F04_7_Calc_downgraded_mode_engine_speed' */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_tWallInCylHead_irvOutport2' */
  InThMdlT_B.TmpSignalConversionAtInThM_tW_b =
    Rte_IrvRead_RE_InThMdlT_007_TEV_InThM_tWallInCylHead_irv();

  /* Outputs for atomic SubSystem: '<S12>/F04_4_Calc_cylinder_intake_temperature' *
   * Block requirements for '<S12>/F04_4_Calc_cylinder_intake_temperature':
   *  1. SubSystem "F04_4_Calc_cylinder_intake_temperature" !Trace_To : VEMS_R_10_07130_089.01 ;
   */

  /* If: '<S38>/If' incorporates:
   *  ActionPort: '<S62>/Action Port'
   *  ActionPort: '<S63>/Action Port'
   *  Constant: '<S38>/Ext_stRun_SC'
   *  RelationalOperator: '<S38>/Relational Operator1'
   *  SubSystem: '<S38>/F04_4_1_Reset_cylinder_intake_temperature'
   *  SubSystem: '<S38>/F04_4_2_Cylinder_intake_temperature'
   *
   * Block requirements for '<S38>/F04_4_1_Reset_cylinder_intake_temperature':
   *  1. SubSystem "F04_4_1_Reset_cylinder_intake_temperature" !Trace_To : VEMS_R_10_07130_090.01 ;
   *
   * Block requirements for '<S38>/F04_4_2_Cylinder_intake_temperature':
   *  1. SubSystem "F04_4_2_Cylinder_intake_temperature" !Trace_To : VEMS_R_10_07130_091.01 ;
   */
  if (InThMdlT_B.TmpSignalConversionAtEng_stEruO == Ext_stRun_SC) {
    /* Switch: '<S63>/Switch2' incorporates:
     *  Constant: '<S63>/InThM_bAcvEngSpdCor_C'
     */
    if (InThM_bAcvEngSpdCor_C) {
      localSwitch2 = localMerge;
    } else {
      localSwitch2 = InThMdlT_B.TmpSignalConversionAtExt_nEngOu;
    }

    /* Lookup2D: '<S65>/Look-Up Table (2-D)'
     * About '<S65>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^3
     * Output0 Data Type:  Fixed Point    U8  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localLookUpTable2D_i),
                      (&(InThM_facHeatExcWallInMnfPipe_M[0])), localSwitch2,
                      (&(Ext_nEngRef1_A[0])), 15U,
                      localTmpSignalConversionAtInM_p, (&(Air_pAir_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S65>/Data Type Duplicate2'
     *
     * Regarding '<S65>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S64>/Data Type Conversion' */
    localDataTypeConversion_n = InThMdlT_B.TmpSignalConversionAtEngM_mfTot;

    /* Lookup: '<S64>/Look-Up Table'
     * About '<S64>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U8  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_n), (&(InThM_facHeatExcWallInMnfPipe_T[0])),
                  localDataTypeConversion_n, (&(Air_mfAir_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate1'
     *
     * Regarding '<S64>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/InThM_bSelHtfClcMod_C'
     *  DataTypeConversion: '<S64>/Data Type Conversion'
     *  Lookup2D: '<S65>/Look-Up Table (2-D)'
     *  Lookup: '<S64>/Look-Up Table'
     */
    if (InThM_bSelHtfClcMod_C) {
      localSwitch_o = localLookUpTable2D_i;
    } else {
      localSwitch_o = localLookUpTable_n;
    }

    /* DataStoreWrite: '<S63>/Data Store Write1' */
    InThM_facHeatExcWallInPipe_MP = localSwitch_o;

    /* DataStoreWrite: '<S63>/Data Store Write2' */
    InThM_nEng_MP = localSwitch2;

    /* Switch: '<S63>/Switch1' incorporates:
     *  Constant: '<S63>/InThM_bAcvETB_tCylEstim_C'
     *  Constant: '<S63>/InThM_tCylEstimETB_C'
     *  DataTypeConversion: '<S63>/Data Type Conversion1'
     *  Product: '<S66>/Divide'
     *  Sum: '<S63>/Sum1'
     *  Sum: '<S63>/Sum3'
     */
    if (InThM_bAcvETB_tCylEstim_C) {
      localtmp = ACTEMS_LdexpF(((Float32d)(((((((Float32)
        InThMdlT_B.TmpSignalConversionAtInThM_tW_b) * 0.0078125F) - (((Float32)
        localMerge_c) * 0.0078125F)) * (((Float32)localSwitch_o) * 0.00390625F))
        + 223.0F) + (((Float32)localMerge_c) * 0.0078125F))) - 223.0F, 7);
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          InThM_tAirUsInVlvEstimRaw = (UInt16)localtmp;
        } else {
          InThM_tAirUsInVlvEstimRaw = 0U;
        }
      } else {
        InThM_tAirUsInVlvEstimRaw = MAX_uint16_T;
      }
    } else {
      InThM_tAirUsInVlvEstimRaw = InThM_tCylEstimETB_C;
    }
  } else {
    /* SignalConversion: '<S62>/Signal Conversion' */
    InThM_tAirUsInVlvEstimRaw = InThMdlT_B.TmpSignalConversionAtUsThrM_tTh;
  }

  /* end of Outputs for SubSystem: '<S12>/F04_4_Calc_cylinder_intake_temperature' */

  /* Outputs for atomic SubSystem: '<S12>/F04_5_Calc_downgraded_mode' *
   * Block requirements for '<S12>/F04_5_Calc_downgraded_mode':
   *  1. SubSystem "F04_5_Calc_downgraded_mode" !Trace_To : VEMS_R_10_07130_092.01 ;
   */

  /* If: '<S39>/If' incorporates:
   *  ActionPort: '<S67>/Action Port'
   *  ActionPort: '<S68>/Action Port'
   *  Constant: '<S39>/Ext_stRun_SC'
   *  RelationalOperator: '<S39>/Relational Operator1'
   *  SubSystem: '<S39>/F04_5_1_Reset_corrected_cyl_intake_temperature'
   *  SubSystem: '<S39>/F04_5_2_Corrected_cyl_intake_temperature'
   *
   * Block requirements for '<S39>/F04_5_1_Reset_corrected_cyl_intake_temperature':
   *  1. SubSystem "F04_5_1_Reset_corrected_cyl_intake_temperature" !Trace_To : VEMS_R_10_07130_093.01 ;
   *
   * Block requirements for '<S39>/F04_5_2_Corrected_cyl_intake_temperature':
   *  1. SubSystem "F04_5_2_Corrected_cyl_intake_temperature" !Trace_To : VEMS_R_10_07130_094.01 ;
   */
  if (InThMdlT_B.TmpSignalConversionAtEng_stEruO == Ext_stRun_SC) {
    /* Switch: '<S68>/Switch' */
    if (localTmpSignalConversionAtEGRVl) {
      localMerge_n = InThMdlT_B.TmpSignalConversionAtUsThrM_tTh;
    } else {
      localMerge_n = InThM_tAirUsInVlvEstimRaw;
    }
  } else {
    /* SignalConversion: '<S67>/Signal Conversion' */
    localMerge_n = InThMdlT_B.TmpSignalConversionAtUsThrM_tTh;
  }

  /* end of Outputs for SubSystem: '<S12>/F04_5_Calc_downgraded_mode' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/Byp_Fonction_SC'
   *  Constant: '<S47>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtInT_n = InThM_facHeatExcWallInMnf_B;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_facHeatExcWallInMnfInport2' */
  Rte_Write_P_InThM_facHeatExcWallInMnf_InThM_facHeatExcWallInMnf
    (localTmpSignalConversionAtInT_n);

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Byp_Fonction_SC'
   *  Constant: '<S45>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localMerge = InThM_nEngCor_B;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_nEngCorInport2' */
  Rte_Write_P_InThM_nEngCor_InThM_nEngCor(localMerge);

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Byp_Fonction_SC'
   *  Constant: '<S46>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localMerge_n = InThM_tAirUsInVlvEstim_B;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimInport2' */
  Rte_Write_P_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim(localMerge_n);

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Byp_Fonction_SC'
   *  Constant: '<S44>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localMerge_c = InThM_tInMnfEstim_B;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_tInMnfEstimInport2' */
  Rte_Write_P_InThM_tInMnfEstim_InThM_tInMnfEstim(localMerge_c);

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S48>/Byp_Fonction_SC'
   *  Constant: '<S48>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localInThM_tMixtInMnf = InThM_tMixtInMnf_B;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInThM_tMixtInMnfInport2' */
  Rte_Write_P_InThM_tMixtInMnf_InThM_tMixtInMnf(localInThM_tMixtInMnf);
}

/* Start for exported function: RE_InThMdlT_008_TEV */
void RE_InThMdlT_008_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F05_Egr_temp'
   *
   * Block requirements for '<S1>/F05_Egr_temp':
   *  1. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_055.01 ;
   *  2. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_038.01 ;
   *  3. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_058.01 ;
   *  4. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_061.02 ;
   *  5. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_059.02 ;
   *  6. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_068.02 ;
   *  7. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_077.01 ;
   *  8. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_075.01 ;
   *  9. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_074.01 ;
   */
}

/* Output and update for exported function: RE_InThMdlT_008_TEV */
void RE_InThMdlT_008_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localTmpSignalConversionAtInM_i;
  UInt16 localTmpSignalConversionAtEngM_;
  UInt16 localDataTypeConversion3_p;
  UInt16 localLookUpTable2D_ix;
  Float32 localSum1;
  UInt8 localSwitch_nt;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F05_Egr_temp'
   *
   * Block requirements for '<S1>/F05_Egr_temp':
   *  1. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_055.01 ;
   *  2. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_038.01 ;
   *  3. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_058.01 ;
   *  4. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_061.02 ;
   *  5. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_059.02 ;
   *  6. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_068.02 ;
   *  7. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_077.01 ;
   *  8. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_075.01 ;
   *  9. SubSystem "F05_Egr_temp" !Trace_To : VEMS_R_10_07130_074.01 ;
   */

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/InThM_facGainHeatFil_tEGR_C'
   */
  localSum1 = ((Float32)InThM_facGainHeatFil_tEGR_C) * 0.00390625F;

  /* Saturate: '<S88>/Saturation [0-1]' */
  localSum1 = rt_SATURATE(localSum1, 0.0F, 1.0F);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_rTotLdExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rTotLdExCor'
   */
  Rte_Read_R_EngM_rTotLdExCor_EngM_rTotLdExCor(&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* Lookup2D: '<S81>/Look-Up Table (2-D)'
   * About '<S81>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-14
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-5  Bias -1024.0
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_ix), (&(InThM_tOfsCorUsEGRVlv_M[0])),
                     localTmpSignalConversionAtEngM_, (&(Eng_rAirLdRef2_A[0])),
                     8U, localTmpSignalConversionAtExt_n, (&(Ext_nEngRef2_A[0])),
                     8U);

  /* DataTypeDuplicate Block: '<S81>/Data Type Duplicate2'
   *
   * Regarding '<S81>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* SignalConversion: '<S13>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&localTmpSignalConversionAtInM_i);

  /* Lookup: '<S82>/Look-Up Table'
   * About '<S82>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-5  Bias 223.0
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localDataTypeConversion3_p), (&(InThM_tUsEGRVlv_T[0])),
                 localTmpSignalConversionAtInM_i, (&(Air_mfEGR_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S82>/Data Type Duplicate1'
   *
   * Regarding '<S82>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Sum: '<S13>/Sum' incorporates:
   *  Lookup2D: '<S81>/Look-Up Table (2-D)'
   */
  InThM_tEgRawUsEGRVlv = ((((Float32)localLookUpTable2D_ix) * 0.03125F) +
    -801.0F) + (((Float32)localDataTypeConversion3_p) * 0.03125F);

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  SignalConversion: '<S13>/TmpSignal ConversionAtInThM_tEGRUsEGRVlvPrevOutport2'
   */
  InThM_tEGRUsEGRVlvPrev = (((Float32)
    Rte_IrvRead_RE_InThMdlT_008_TEV_InThM_tEGRUsEGRVlv_irv()) * 0.03125F) +
    223.0F;

  /* Sum: '<S88>/Sum1' incorporates:
   *  Product: '<S88>/Product'
   *  Sum: '<S88>/Sum'
   */
  localSum1 = ((InThM_tEgRawUsEGRVlv - InThM_tEGRUsEGRVlvPrev) * localSum1) +
    InThM_tEGRUsEGRVlvPrev;

  /* DataTypeConversion: '<S13>/Data Type Conversion3' */
  localtmp = ACTEMS_LdexpF(((Float32d)localSum1) - 223.0F, 5);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion3_p = (UInt16)localtmp;
    } else {
      localDataTypeConversion3_p = 0U;
    }
  } else {
    localDataTypeConversion3_p = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S83>/autosar_testpoint1' */

  /* S-Function Block: <S83>/autosar_testpoint1 */
  InThM_tEGRUsEGRVlv_IRV_MP = localDataTypeConversion3_p;

  /* Sum: '<S13>/Sum1' incorporates:
   *  Constant: '<S13>/Ext_rSqrtGainRef2_SC'
   *  Constant: '<S13>/Ext_rSqrtOfsRef2_SC'
   *  Product: '<S85>/Divide'
   */
  localSum1 = ((Float32)(((Float32d)localSum1) * ACTEMS_LdexpF((Float32d)
    Ext_rSqrtGainRef2_SC, -32))) + (((Float32)Ext_rSqrtOfsRef2_SC) *
    3.725290298E-009F);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtInThM_tEGRUsEGRVlvInport2' incorporates:
   *  SignalConversion: '<S13>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_InThMdlT_008_TEV_InThM_tEGRUsEGRVlv_irv
    (localDataTypeConversion3_p);

  /* Switch: '<S84>/Switch' incorporates:
   *  Constant: '<S84>/Byp_Fonction_SC'
   *  Constant: '<S84>/Int_BypC'
   *  DataTypeConversion: '<S84>/Data Type Conversion'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localSwitch_nt = InThM_tSqrtEgUsEGRVlv_B;
  } else {
    localtmp = localSum1;
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 3);
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        localSwitch_nt = (UInt8)localtmp;
      } else {
        localSwitch_nt = 0U;
      }
    } else {
      localSwitch_nt = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtInThM_tSqrtEgUsEGRVlvInport2' */
  Rte_Write_P_InThM_tSqrtEgUsEGRVlv_InThM_tSqrtEgUsEGRVlv(localSwitch_nt);
}

/* Start for exported function: RE_InThMdlT_005_TEV */
void RE_InThMdlT_005_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Calcul_cylinder_head_wall_temp'
   *
   * Block requirements for '<S1>/F02_Calcul_cylinder_head_wall_temp':
   *  1. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_040.01 ;
   *  2. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_060.02 ;
   *  3. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_065.01 ;
   *  4. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_010.01 ;
   *  5. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_009.01 ;
   *  6. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_008.01 ;
   *  7. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_007.01 ;
   */
}

/* Output and update for exported function: RE_InThMdlT_005_TEV */
void RE_InThMdlT_005_TEV(void)
{
  /* local block i/o variables */
  UInt16 localSum1_m;
  SInt16 localTmpSignalConversionAtExt_f;
  SInt32 localtmp;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Calcul_cylinder_head_wall_temp'
   *
   * Block requirements for '<S1>/F02_Calcul_cylinder_head_wall_temp':
   *  1. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_040.01 ;
   *  2. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_060.02 ;
   *  3. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_065.01 ;
   *  4. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_010.01 ;
   *  5. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_009.01 ;
   *  6. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_008.01 ;
   *  7. SubSystem "F02_Calcul_cylinder_head_wall_temp" !Trace_To : VEMS_R_10_07130_007.01 ;
   */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_f);

  /* Sum: '<S10>/Sum1' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  localtmp = localTmpSignalConversionAtExt_f + 50;
  if (localtmp <= 0) {
    localSum1_m = 0U;
  } else if (localtmp > 511) {
    localSum1_m = MAX_uint16_T;
  } else {
    localSum1_m = (UInt16)(localtmp << 7);
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S28>/autosar_testpoint1' */

  /* S-Function Block: <S28>/autosar_testpoint1 */
  InThM_tWallInCylHead_IRV_MP = localSum1_m;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInThM_tWallInCylHead_irvInport2' incorporates:
   *  SignalConversion: '<S10>/Signal Conversion'
   */
  Rte_IrvWrite_RE_InThMdlT_005_TEV_InThM_tWallInCylHead_irv(localSum1_m);
}

/* Output and update for exported function: RE_InThMdlT_004_TEV */
void RE_InThMdlT_004_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtInT_a;
  UInt16 localMerge3_f;
  UInt8 localTmpSignalConversionAtEng_h;
  Boolean localRelationalOperator_a;
  UInt16 localTmpSignalConversionAtUsT_g;

  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/F07_Reset_egr_manifold_temp'
   *
   * Block requirements for '<S1>/F07_Reset_egr_manifold_temp':
   *  1. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_003.01 ;
   *  2. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_039.01 ;
   *  3. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  4. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_036.01 ;
   *  5. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_064.01 ;
   *  6. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_002.01 ;
   *  7. SubSystem "F07_Reset_egr_manifold_temp" !Trace_To : VEMS_R_10_07130_001.01 ;
   */

  /* SignalConversion: '<S15>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&localTmpSignalConversionAtUsT_g);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_h);

  /* RelationalOperator: '<S15>/Relational Operator' incorporates:
   *  Constant: '<S15>/Ext_stRun_SC'
   */
  localRelationalOperator_a = (localTmpSignalConversionAtEng_h == Ext_stRun_SC);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInThM_tEGRInMnf1Outport2' incorporates:
   *  Inport: '<Root>/InThM_tEGRInMnf_INPUT'
   */
  Rte_Read_R_InThM_tEGRInMnf_InThM_tEGRInMnf(&localTmpSignalConversionAtInT_a);

  /* If: '<S15>/If' incorporates:
   *  ActionPort: '<S94>/Action Port'
   *  ActionPort: '<S95>/Action Port'
   *  Logic: '<S15>/Logical Operator'
   *  SubSystem: '<S15>/F07_01_Reset_egr_manifold_temperature'
   *  SubSystem: '<S15>/If Action Subsystem1'
   *
   * Block requirements for '<S15>/F07_01_Reset_egr_manifold_temperature':
   *  1. SubSystem "F07_01_Reset_egr_manifold_temperature" !Trace_To : VEMS_R_10_07130_004.01 ;
   */
  if (!localRelationalOperator_a) {
    /* DataTypeConversion: '<S94>/Data Type Conversion2' */
    localMerge3_f = (UInt16)((SInt32)(((UInt32)((SInt32)
      localTmpSignalConversionAtUsT_g)) >> 2));
  } else {
    InThMdlT_IfActionSubsystem1(localTmpSignalConversionAtInT_a, &localMerge3_f);
  }

  /* Switch: '<S96>/Switch' incorporates:
   *  Constant: '<S96>/Byp_Fonction_SC'
   *  Constant: '<S96>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_g = InThM_tEGRInMnf_B;
  } else {
    localTmpSignalConversionAtUsT_g = localMerge3_f;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInThM_tEGRInMnfInport2' */
  Rte_Write_P_InThM_tEGRInMnf_InThM_tEGRInMnf(localTmpSignalConversionAtUsT_g);
}

/* Start for exported function: RE_InThMdlT_006_TEV */
void RE_InThMdlT_006_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F03_Manifold_wall_temp'
   *
   * Block requirements for '<S1>/F03_Manifold_wall_temp':
   *  1. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_050.01 ;
   *  2. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  3. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_044.02 ;
   *  4. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_043.01 ;
   *  5. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_042.01 ;
   *  6. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_041.01 ;
   *  7. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_066.01 ;
   *  8. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_015.01 ;
   *  9. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_011.01 ;
   *  10. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_012.01 ;
   *  11. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_013.01 ;
   */
}

/* Output and update for exported function: RE_InThMdlT_006_TEV */
void RE_InThMdlT_006_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtEng_b;
  UInt8 localLookUpTable_g;
  UInt8 localTmpSignalConversionAtEn_k2;
  Boolean localRelationalOperator_l;
  Float32 localDivide_kt;
  UInt16 localTmpSignalConversionAtIn_nu;
  UInt16 localTmpSignalConversionAtIn_a0;
  UInt16 localTmpSignalConversionAtUsT_m;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_Manifold_wall_temp'
   *
   * Block requirements for '<S1>/F03_Manifold_wall_temp':
   *  1. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_050.01 ;
   *  2. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_037.01 ;
   *  3. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_044.02 ;
   *  4. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_043.01 ;
   *  5. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_042.01 ;
   *  6. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_041.01 ;
   *  7. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_066.01 ;
   *  8. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_015.01 ;
   *  9. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_011.01 ;
   *  10. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_012.01 ;
   *  11. SubSystem "F03_Manifold_wall_temp" !Trace_To : VEMS_R_10_07130_013.01 ;
   */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtUsThrM_tDsThrCorMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tDsThrCorMes'
   */
  Rte_Read_R_UsThrM_tDsThrCorMes_UsThrM_tDsThrCorMes
    (&localTmpSignalConversionAtUsT_m);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEn_k2);

  /* RelationalOperator: '<S11>/Relational Operator' incorporates:
   *  Constant: '<S11>/Ext_stRun_SC'
   */
  localRelationalOperator_l = (localTmpSignalConversionAtEn_k2 == Ext_stRun_SC);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_mfTotExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfTotExCor'
   */
  Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor(&localTmpSignalConversionAtEng_b);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInThM_tMixtInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_tMixtInMnf_INPUT'
   */
  Rte_Read_R_InThM_tMixtInMnf_InThM_tMixtInMnf(&localTmpSignalConversionAtIn_nu);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInThM_tWallInMnf1Outport2' incorporates:
   *  Inport: '<Root>/InThM_tWallInMnf_INPUT'
   */
  Rte_Read_R_InThM_tWallInMnf_InThM_tWallInMnf(&localTmpSignalConversionAtIn_a0);

  /* If: '<S11>/If' incorporates:
   *  ActionPort: '<S29>/Action Port'
   *  ActionPort: '<S30>/Action Port'
   *  SubSystem: '<S11>/F03_1_Reset_manifold_wall_temperature'
   *  SubSystem: '<S11>/F03_2_Manifold_wall_temperature'
   *
   * Block requirements for '<S11>/F03_1_Reset_manifold_wall_temperature':
   *  1. SubSystem "F03_1_Reset_manifold_wall_temperature" !Trace_To : VEMS_R_10_07130_016.01 ;
   *
   * Block requirements for '<S11>/F03_2_Manifold_wall_temperature':
   *  1. SubSystem "F03_2_Manifold_wall_temperature" !Trace_To : VEMS_R_10_07130_017.01 ;
   */
  if (localRelationalOperator_l) {
    /* Lookup: '<S32>/Look-Up Table'
     * About '<S32>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U8  2^-2
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_g), (&(InThM_facHeatFil_tWallInMnf_M[0])),
                  localTmpSignalConversionAtEng_b, (&(Air_mfAir_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate1'
     *
     * Regarding '<S32>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S33>/Divide' */
    localDivide_kt = (((Float32)localLookUpTable_g) * 0.25F) * (((Float32)
      localTmpSignalConversionAtEng_b) * 1.525878906E-005F);

    /* DataStoreWrite: '<S30>/Data Store Write1' incorporates:
     *  DataTypeConversion: '<S30>/Data Type Conversion5'
     */
    localtmp = localDivide_kt;
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        InThM_facHeatFil_tWallInMnf_MP = (UInt16)localtmp;
      } else {
        InThM_facHeatFil_tWallInMnf_MP = 0U;
      }
    } else {
      InThM_facHeatFil_tWallInMnf_MP = MAX_uint16_T;
    }

    /* DataStoreWrite: '<S30>/Data Store Write2' */
    InThM_facNormHeat_tWallInMnf_MP = localLookUpTable_g;

    /* Sum: '<S30>/Sum3' incorporates:
     *  Product: '<S34>/Divide'
     *  Sum: '<S30>/Sum1'
     */
    localtmp = ACTEMS_LdexpF(((Float32d)(((((((Float32)
      localTmpSignalConversionAtIn_nu) * 0.0078125F) - (((Float32)
      localTmpSignalConversionAtIn_a0) * 0.0078125F)) * localDivide_kt) + 223.0F)
      + (((Float32)localTmpSignalConversionAtIn_a0) * 0.0078125F))) - 223.0F, 7);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtUsT_m = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtUsT_m = 0U;
      }
    } else {
      localTmpSignalConversionAtUsT_m = MAX_uint16_T;
    }
  }

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/Byp_Fonction_SC'
   *  Constant: '<S31>/Int_BypC'
   */
  if (INTHMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_m = InThM_tWallInMnf_B;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInThM_tWallInMnfInport2' */
  Rte_Write_P_InThM_tWallInMnf_InThM_tWallInMnf(localTmpSignalConversionAtUsT_m);
}

/* Model initialize function */
void RE_InThMdl_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   *  Start for SubSystem: '<Root>/__ExpFcn__7'
   */
  RE_InThMdlT_001_MSE_Start();
  RE_InThMdlT_002_TEV_Start();
  RE_InThMdlT_007_TEV_Start();
  RE_InThMdlT_008_TEV_Start();
  RE_InThMdlT_005_TEV_Start();
  RE_InThMdlT_006_TEV_Start();
}

#define InThMdlT_STOP_SEC_CODE
#include "InThMdlT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
