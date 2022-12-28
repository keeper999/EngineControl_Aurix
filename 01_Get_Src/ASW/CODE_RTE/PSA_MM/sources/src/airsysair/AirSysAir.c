/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysAir                                               */
/* !Description     : AirSysAir Software Component                            */
/*                                                                            */
/* !Module          : AirSysAir                                               */
/* !Description     : AirSysAir Software Component                            */
/*                                                                            */
/* !File            : AirSysAir.c                                             */
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
/*   Model name       : AirSysAir_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysAir                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M17-AirSysAir/5-$*/
/* $Revision::   1.15                                                        $*/
/* $Author::   adelvare                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirSysAir.h"
#include "AirSysAir_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AirSysAir_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirSysAir_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AirSysAir AirSysAir_B;

/* Block states (auto storage) */
D_Work_AirSysAir AirSysAir_DWork;

#define AirSysAir_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirSysAir_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define AIRSYSAIR_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define AIRSYSAIR_VEMSRTLIBT_MINOR_VERSION_REQ 13
#define AIRSYSAIR_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define AIRSYSAIR_VEMSRTLIBT_VERSION_REQ (AIRSYSAIR_VEMSRTLIBT_PATCH_VERSION_REQ + AIRSYSAIR_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + AIRSYSAIR_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if AIRSYSAIR_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AirSysAir_START_SEC_CODE
#include "AirSysAir_MemMap.h"

void AirSysAir_ASYNC1(int controlPortIdx)
{
}

void AirSysAir_ASYNC2(int controlPortIdx)
{
}

void AirSysAir_ASYNC3(int controlPortIdx)
{
}

void AirSysAir_ASYNC4(int controlPortIdx)
{
}

void AirSysAir_ASYNC5(int controlPortIdx)
{
}

void AirSysAir_ASYNC6(int controlPortIdx)
{
}

void AirSysAir_ASYNC7(int controlPortIdx)
{
}

void AirSysAir_ASYNC8(int controlPortIdx)
{
}

void AirSysAir_ASYNC9(int controlPortIdx)
{
}

void AirSysAir_ASYNC10(int controlPortIdx)
{
}

/* Start for exported function: RE_AirSysAir_001_MSE */
void RE_AirSysAir_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_Init'
   *
   * Block requirements for '<S1>/F00_Init':
   *  1. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_099.02 ;
   *  2. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_030.02 ;
   *  3. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_031.02 ;
   *  4. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_032.01 ;
   *  5. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_001.01 ;
   *  6. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_002.01 ;
   *  7. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_003.01 ;
   *  8. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_095.03 ;
   *  9. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_110.02 ;
   *  10. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_056.01 ;
   *  11. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_057.01 ;
   *  12. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_055.01 ;
   *  13. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_092.02 ;
   *  14. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_094.02 ;
   *  15. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_096.01 ;
   *  16. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_047.01 ;
   *  17. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_077.01 ;
   *  18. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_070.01 ;
   *  19. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_090.03 ;
   *  20. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_115.01 ;
   *  21. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_093.02 ;
   */
}

/* Output and update for exported function: RE_AirSysAir_001_MSE */
void RE_AirSysAir_001_MSE(void)
{
  Boolean localAirSys_bInhPiAirEngCor;
  UInt16 localAirSys_prm_mAirCylReq_02_i;
  UInt32 localSwitch;
  UInt16 localSwitch_h[2];

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_Init'
   *
   * Block requirements for '<S1>/F00_Init':
   *  1. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_099.02 ;
   *  2. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_030.02 ;
   *  3. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_031.02 ;
   *  4. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_032.01 ;
   *  5. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_001.01 ;
   *  6. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_002.01 ;
   *  7. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_003.01 ;
   *  8. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_095.03 ;
   *  9. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_110.02 ;
   *  10. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_056.01 ;
   *  11. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_057.01 ;
   *  12. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_055.01 ;
   *  13. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_092.02 ;
   *  14. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_094.02 ;
   *  15. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_096.01 ;
   *  16. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_047.01 ;
   *  17. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_077.01 ;
   *  18. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_070.01 ;
   *  19. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_090.03 ;
   *  20. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_115.01 ;
   *  21. SubSystem "F00_Init" !Trace_To : VEMS_R_10_07030_093.02 ;
   */

  /* user code (Output function Body for TID17) */
  RE_AirSysAir_Init();

  /* SignalConversion: '<S16>/copy' incorporates:
   *  Constant: '<S9>/ConstVal_5'
   */
  AirSys_rAirPresReq_IRV_MP = MAX_uint16_T;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S16>/autosar_testpoint1' */

  /* S-Function Block: <S16>/autosar_testpoint1 */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_rAirPresReq_irvInport2' incorporates:
   *  Constant: '<S9>/ConstVal_5'
   *  SignalConversion: '<S9>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_AirSysAir_001_MSE_AirSys_rAirPresReq_irv(MAX_uint16_T);

  /* SignalConversion: '<S17>/copy' incorporates:
   *  Constant: '<S9>/ConstMat'
   */
  AirSys_prm_mAirCylReq_IRV_MP[0] = 0U;
  AirSys_prm_mAirCylReq_IRV_MP[1] = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S17>/autosar_testpoint1' */

  /* S-Function Block: <S17>/autosar_testpoint1 */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_prm_mAirCylReq_01_irvInport2' incorporates:
   *  Constant: '<S9>/ConstMat'
   *  SignalConversion: '<S9>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_AirSysAir_001_MSE_AirSys_prm_mAirCylReq_01_irv(0U);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_prm_mAirCylReq_02_irvInport2' */
  Rte_IrvWrite_RE_AirSysAir_001_MSE_AirSys_prm_mAirCylReq_02_irv(0U);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Byp_Fonction_SC'
   *  Constant: '<S23>/Int_BypC'
   *  Constant: '<S9>/ConstVal_4'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localAirSys_bInhPiAirEngCor = AirSys_bInhPiAirEngCor_B;
  } else {
    localAirSys_bInhPiAirEngCor = FALSE;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_bInhPiAirEngCorInport2' */
  Rte_Write_P_AirSys_bInhPiAirEngCor_AirSys_bInhPiAirEngCor
    (localAirSys_bInhPiAirEngCor);

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Byp_Fonction_SC'
   *  Constant: '<S28>/Int_BypC'
   *  Constant: '<S9>/ConstVal'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localSwitch = AirSys_mAirEngIntCor_B;
  } else {
    localSwitch = 2147456160U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_mAirEngIntCorInport2' */
  Rte_Write_P_AirSys_mAirEngIntCor_AirSys_mAirEngIntCor(localSwitch);

  /* SignalConversion: '<S18>/copy' incorporates:
   *  Constant: '<S9>/ConstVal_9'
   */
  AirSys_bActStraLimSurgeDmpSw = FALSE;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S18>/autosar_testpoint1' */

  /* S-Function Block: <S18>/autosar_testpoint1 */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_bActStraLimSurgeDmpSw_irvInport2' incorporates:
   *  Constant: '<S9>/ConstVal_9'
   *  SignalConversion: '<S9>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_AirSysAir_001_MSE_AirSys_bActStraLimSurgeDmpSw_irv(FALSE);

  /* SignalConversion: '<S19>/copy' incorporates:
   *  Constant: '<S9>/ConstVal_1'
   */
  AirSys_mAirEngCorReq_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S19>/autosar_testpoint1' */

  /* S-Function Block: <S19>/autosar_testpoint1 */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_mAirEngCorReq_irvInport2' incorporates:
   *  Constant: '<S9>/ConstVal_1'
   *  SignalConversion: '<S9>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_AirSysAir_001_MSE_AirSys_mAirEngCorReq_irv(0U);

  /* SignalConversion: '<S21>/copy' incorporates:
   *  Constant: '<S9>/ConstVal_3'
   */
  AirSys_tiDlyAftEgrFoul_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S21>/autosar_testpoint1' */

  /* S-Function Block: <S21>/autosar_testpoint1 */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_tiDlyAftEgrFoul_irvInport2' incorporates:
   *  Constant: '<S9>/ConstVal_3'
   *  SignalConversion: '<S9>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_AirSysAir_001_MSE_AirSys_tiDlyAftEgrFoul_irv(0U);

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Byp_Fonction_SC'
   *  Constant: '<S29>/Int_BypC'
   *  Constant: '<S9>/ConstVal_8'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localAirSys_prm_mAirCylReq_02_i = AirSys_arThrReq_B;
  } else {
    localAirSys_prm_mAirCylReq_02_i = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_arThrReqInport2' */
  Rte_Write_P_AirSys_arThrReq_AirSys_arThrReq(localAirSys_prm_mAirCylReq_02_i);

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Byp_Fonction_SC'
   *  Constant: '<S25>/Int_BypC'
   *  Constant: '<S9>/ConstMat_3'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localSwitch_h[0] = AirSys_prm_pInMnfReq_B[0];
    localSwitch_h[1] = AirSys_prm_pInMnfReq_B[1];
  } else {
    localSwitch_h[0] = 0U;
    localSwitch_h[1] = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_prm_pInMnfReqInport2' */
  Rte_Write_P_AirSys_prm_pInMnfReq_AirSys_prm_pInMnfReq(&localSwitch_h);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Byp_Fonction_SC'
   *  Constant: '<S27>/Int_BypC'
   *  Constant: '<S9>/ConstMat_1'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localSwitch_h[0] = AirSys_prm_mfAirThrReq_B[0];
    localSwitch_h[1] = AirSys_prm_mfAirThrReq_B[1];
  } else {
    localSwitch_h[0] = 0U;
    localSwitch_h[1] = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_prm_mfAirThrReqInport2' */
  Rte_Write_P_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq(&localSwitch_h);

  /* SignalConversion: '<S20>/copy' incorporates:
   *  Constant: '<S9>/ConstVal_2'
   */
  AirSys_arEfcThrReqTqSys_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S20>/autosar_testpoint1' */

  /* S-Function Block: <S20>/autosar_testpoint1 */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_arEfcThrReqTqSys_irvInport2' incorporates:
   *  Constant: '<S9>/ConstVal_2'
   *  SignalConversion: '<S9>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_AirSysAir_001_MSE_AirSys_arEfcThrReqTqSys_irv(0U);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   *  Constant: '<S9>/ConstVal_6'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localAirSys_bInhPiAirEngCor = AirSys_bActStraLimSurge_B;
  } else {
    localAirSys_bInhPiAirEngCor = FALSE;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_bActStraLimSurgeInport2' */
  Rte_Write_P_AirSys_bActStraLimSurge_AirSys_bActStraLimSurge
    (localAirSys_bInhPiAirEngCor);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Byp_Fonction_SC'
   *  Constant: '<S22>/Int_BypC'
   *  Constant: '<S9>/ConstVal_7'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localAirSys_prm_mAirCylReq_02_i = AirSys_rAirLdReq_B;
  } else {
    localAirSys_prm_mAirCylReq_02_i = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_rAirLdReqInport2' */
  Rte_Write_P_AirSys_rAirLdReq_AirSys_rAirLdReq(localAirSys_prm_mAirCylReq_02_i);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Byp_Fonction_SC'
   *  Constant: '<S26>/Int_BypC'
   *  Constant: '<S9>/ConstVal_10'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localAirSys_prm_mAirCylReq_02_i = AirSys_mAirEngCylReq_tqEng_B;
  } else {
    localAirSys_prm_mAirCylReq_02_i = 0U;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_mAirEngCylReq_tqEngInport2' */
  Rte_Write_P_AirSys_mAirEngCylReq_tqEng_AirSys_mAirEngCylReq_tqEng
    (localAirSys_prm_mAirCylReq_02_i);
}

/* Start for exported function: RE_AirSysAir_003_TEV */
void RE_AirSysAir_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Calc_dtc_fafr_pam_run'
   *
   * Block requirements for '<S1>/F02_Calc_dtc_fafr_pam_run':
   *  1. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_101.02 ;
   *  2. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_001.01 ;
   *  3. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_002.01 ;
   *  4. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_004.01 ;
   *  5. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_089.01 ;
   *  6. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_062.01 ;
   *  7. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_064.02 ;
   *  8. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_066.02 ;
   *  9. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_059.01 ;
   *  10. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_060.01 ;
   *  11. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_065.01 ;
   *  12. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_069.02 ;
   *  13. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_068.01 ;
   *  14. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_058.01 ;
   *  15. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_063.01 ;
   *  16. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_067.01 ;
   *  17. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_091.01 ;
   *  18. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_094.02 ;
   *  19. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_056.01 ;
   *  20. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_057.02 ;
   *  21. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_055.01 ;
   *  22. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_092.02 ;
   *  23. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_097.01 ;
   *  24. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_116.01 ;
   *  25. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_114.01 ;
   */

  /* Start for atomic SubSystem: '<S14>/F02_Correction_de_la_masse' *
   * Block requirements for '<S14>/F02_Correction_de_la_masse':
   *  1. SubSystem "F02_Correction_de_la_masse" !Trace_To : VEMS_R_10_07030_006.01 ;
   */

  /* Start for enable SubSystem: '<S85>/F03_Correcteur_PI_masse_air' *
   * Block requirements for '<S85>/F03_Correcteur_PI_masse_air':
   *  1. SubSystem "F03_Correcteur_PI_masse_air" !Trace_To : VEMS_R_10_07030_009.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S95>/F01_Condition_integrateur' *
   * Block requirements for '<S95>/F01_Condition_integrateur':
   *  1. SubSystem "F01_Condition_integrateur" !Trace_To : VEMS_R_10_07030_010.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S99>/F03_Papillon_butte' *
   * Block requirements for '<S99>/F03_Papillon_butte':
   *  1. SubSystem "F03_Papillon_butte" !Trace_To : VEMS_R_10_07030_013.02 ;
   */

  /* InitializeConditions for UnitDelay: '<S110>/UnitDelay' */
  AirSysAir_DWork.UnitDelay_ed = TRUE;

  /* end of InitializeConditions for SubSystem: '<S99>/F03_Papillon_butte' */

  /* end of InitializeConditions for SubSystem: '<S95>/F01_Condition_integrateur' */

  /* end of Start for SubSystem: '<S85>/F03_Correcteur_PI_masse_air' */

  /* end of Start for SubSystem: '<S14>/F02_Correction_de_la_masse' */
}

/* Output and update for exported function: RE_AirSysAir_003_TEV */
void RE_AirSysAir_003_TEV(void)
{
  /* local block i/o variables */
  UInt16 localOutDTConv_m;
  UInt16 localSwitch2_n;
  Boolean localRelationalOperator1_bt;
  Boolean localAutosarServer;
  Boolean localRelationalOperator;
  Boolean localRelationalOperator1_g;
  Boolean localLogic[2];
  Boolean localUnitDelay1;
  Float32 localDTC1;
  Float32 localDTC2;
  Boolean localNot;
  UInt8 localTmpSignalConversionAtEGRVl;
  Boolean localTmpSignalConversionAtAir_n;
  Float32 localSum1_k;
  Boolean localLogicalOperator_o;
  Boolean localTmpSignalConversionAtIdlSy;
  Boolean localTmpSignalConversionAtInjSy[6];
  Boolean localTmpSignalConversionAtAccP_;
  Float32 localSwitch2_f;
  UInt8 localTmpSignalConversionAtEng_s;
  UInt16 localTmpSignalConversionAtAir_f;
  UInt16 localTmpSignalConversionAtEngM_;
  UInt32 localTmpSignalConversionAtAirSy;
  UInt16 localTmpSignalConversionAtDmpVl;
  UInt16 localTmpSignalConversionAtEng_d;
  UInt16 localTmpSignalConversionAtThr_r;
  UInt16 localTmpSignalConversionAtThrLr;
  Float32 localtmp;
  SInt32 localrtmax;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Calc_dtc_fafr_pam_run'
   *
   * Block requirements for '<S1>/F02_Calc_dtc_fafr_pam_run':
   *  1. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_101.02 ;
   *  2. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_001.01 ;
   *  3. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_002.01 ;
   *  4. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_004.01 ;
   *  5. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_089.01 ;
   *  6. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_062.01 ;
   *  7. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_064.02 ;
   *  8. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_066.02 ;
   *  9. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_059.01 ;
   *  10. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_060.01 ;
   *  11. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_065.01 ;
   *  12. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_069.02 ;
   *  13. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_068.01 ;
   *  14. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_058.01 ;
   *  15. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_063.01 ;
   *  16. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_067.01 ;
   *  17. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_091.01 ;
   *  18. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_094.02 ;
   *  19. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_056.01 ;
   *  20. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_057.02 ;
   *  21. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_055.01 ;
   *  22. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_092.02 ;
   *  23. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_097.01 ;
   *  24. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_116.01 ;
   *  25. SubSystem "F02_Calc_dtc_fafr_pam_run" !Trace_To : VEMS_R_10_07030_114.01 ;
   */

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_tiDlyAftEgrFoulPrevOutport2' */
  AirSys_tiDlyAftEgrFoulPrev =
    Rte_IrvRead_RE_AirSysAir_003_TEV_AirSys_tiDlyAftEgrFoul_irv();

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_mAirEngCylReq_tqEngOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mAirEngCylReq_tqEng_INPUT'
   */
  Rte_Read_R_AirSys_mAirEngCylReq_tqEng_AirSys_mAirEngCylReq_tqEng
    (&localTmpSignalConversionAtAir_f);

  /* DataTypeConversion: '<S14>/DTC1' */
  localDTC1 = ((Float32)localTmpSignalConversionAtAir_f) * 1.192016583E-007F;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_mAirCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirCor'
   */
  Rte_Read_R_EngM_mAirCor_EngM_mAirCor(&localTmpSignalConversionAtEngM_);

  /* DataTypeConversion: '<S14>/DTC2' */
  localDTC2 = ((Float32)localTmpSignalConversionAtEngM_) * 1.192016583E-007F;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtThrLrn_rOpSIOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpSI'
   */
  Rte_Read_R_ThrLrn_rOpSI_ThrLrn_rOpSI(&localTmpSignalConversionAtThrLr);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_facTranAirOutport2' incorporates:
   *  Inport: '<Root>/AirSys_facTranAir'
   */
  Rte_Read_R_AirSys_facTranAir_AirSys_facTranAir
    (&AirSysAir_B.TmpSignalConversionAtAirSys_fac);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtCrkMgt_stThr_arThrEffOutport2' incorporates:
   *  Inport: '<Root>/CrkMgt_stThr_arThrEff'
   */
  Rte_Read_R_CrkMgt_stThr_arThrEff_CrkMgt_stThr_arThrEff
    (&AirSysAir_B.TmpSignalConversionAtCrkMgt_stT);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAccP_bAccPMinOutport2' incorporates:
   *  Inport: '<Root>/AccP_bAccPMin'
   */
  Rte_Read_R_AccP_bAccPMin_AccP_bAccPMin(&localTmpSignalConversionAtAccP_);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInjSys_prm_bInjCutOffCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_bInjCutOffCyl'
   */
  Rte_Read_R_InjSys_prm_bInjCutOffCyl_InjSys_prm_bInjCutOffCyl
    (&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtIdlSys_bAcvIdlCtlOutport2' incorporates:
   *  Inport: '<Root>/IdlSys_bAcvIdlCtl'
   */
  Rte_Read_R_IdlSys_bAcvIdlCtl_IdlSys_bAcvIdlCtl
    (&localTmpSignalConversionAtIdlSy);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtThr_rOpThrReqMaxThdOutport2' incorporates:
   *  Inport: '<Root>/Thr_rOpThrReqMaxThd'
   */
  Rte_Read_R_Thr_rOpThrReqMaxThd_Thr_rOpThrReqMaxThd
    (&localTmpSignalConversionAtThr_r);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_mAirEngIntCor_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mAirEngIntCor_INPUT'
   */
  Rte_Read_R_AirSys_mAirEngIntCor_AirSys_mAirEngIntCor
    (&localTmpSignalConversionAtAirSy);

  /* DataTypeConversion: '<S14>/DTC11' */
  AirSys_mAirEngIntCorPrev = (((Float32)localTmpSignalConversionAtAirSy) *
    9.094947018E-013F) - 1.953099971E-003F;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtDmpVlv_rAirLdLimSurgeReqOutport2' incorporates:
   *  Inport: '<Root>/DmpVlv_rAirLdLimSurgeReq'
   */
  Rte_Read_R_DmpVlv_rAirLdLimSurgeReq_DmpVlv_rAirLdLimSurgeReq
    (&localTmpSignalConversionAtDmpVl);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_rMassAirScvCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rMassAirScvCor'
   */
  Rte_Read_R_EngM_rMassAirScvCor_EngM_rMassAirScvCor
    (&localTmpSignalConversionAtEng_d);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_bInhPiAirEngCor_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_bInhPiAirEngCor_INPUT'
   */
  Rte_Read_R_AirSys_bInhPiAirEngCor_AirSys_bInhPiAirEngCor
    (&localTmpSignalConversionAtAir_n);

  /* S-Function (sfun_autosar_clientop): '<S86>/AutosarServer' */
  Rte_Call_R_FRM_bInhPIAirSys_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S86>/Not' */
  localNot = !localAutosarServer;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&AirSysAir_B.TmpSignalConversionAtExt_nEngOu);

  /* Outputs for atomic SubSystem: '<S14>/F02_Correction_de_la_masse' *
   * Block requirements for '<S14>/F02_Correction_de_la_masse':
   *  1. SubSystem "F02_Correction_de_la_masse" !Trace_To : VEMS_R_10_07030_006.01 ;
   */

  /* Outputs for enable SubSystem: '<S85>/F01_Calc_dtc_fafr_pam_init' incorporates:
   *  EnablePort: '<S93>/FRM_bInhPIAirSys'
   *
   * Block requirements for '<S85>/F01_Calc_dtc_fafr_pam_init':
   *  1. SubSystem "F01_Calc_dtc_fafr_pam_init" !Trace_To : VEMS_R_10_07030_007.01 ;
   */
  if (localNot) {
    /* Constant: '<S93>/ConstVal' */
    localSwitch2_f = 0.0F;

    /* SignalConversion: '<S93>/Signal Conversion' */
    localLogicalOperator_o = localTmpSignalConversionAtAir_n;
  }

  /* end of Outputs for SubSystem: '<S85>/F01_Calc_dtc_fafr_pam_init' */

  /* Outputs for atomic SubSystem: '<S85>/F02_Choix_de_la_masse_de_consigne' *
   * Block requirements for '<S85>/F02_Choix_de_la_masse_de_consigne':
   *  1. SubSystem "F02_Choix_de_la_masse_de_consigne" !Trace_To : VEMS_R_10_07030_008.01 ;
   */

  /* Product: '<S98>/Divide' incorporates:
   *  Constant: '<S94>/Eng_mRef_C'
   *  DataTypeConversion: '<S14>/DTC12'
   *  DataTypeConversion: '<S14>/DTC13'
   *  DataTypeConversion: '<S94>/DTC1'
   *  Sum: '<S94>/Sum3'
   */
  localSum1_k = ((((Float32)localTmpSignalConversionAtDmpVl) *
                  6.103515625E-005F) - (((Float32)
    localTmpSignalConversionAtEng_d) * 6.103515625E-005F)) * (((Float32)
    Eng_mRef_C) * 1.192016583E-007F);

  /* DataStoreWrite: '<S94>/Data Store Write' incorporates:
   *  Constant: '<S97>/offset'
   *  Constant: '<S97>/offset1'
   *  Constant: '<S97>/one_on_slope'
   *  DataTypeConversion: '<S97>/OutDTConv'
   *  Product: '<S97>/Product4'
   *  Sum: '<S97>/Add1'
   *  Sum: '<S97>/Add2'
   */
  localtmp = (8.389145E+006F * localSum1_k) + 0.5F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      AirSys_mAirEngCylSurgeLimReq_MP = (UInt16)localtmp;
    } else {
      AirSys_mAirEngCylSurgeLimReq_MP = 0U;
    }
  } else {
    AirSys_mAirEngCylSurgeLimReq_MP = MAX_uint16_T;
  }

  /* Switch: '<S94>/Switch1' incorporates:
   *  Constant: '<S94>/AirSys_bSelMAirEngCylReq_C'
   *  MinMax: '<S94>/MinMax'
   */
  if (AirSys_bSelMAirEngCylReq_C) {
    AirSys_mAirEngSelReq = localDTC1;
  } else {
    AirSys_mAirEngSelReq = rt_MAXf(localDTC1, localSum1_k);
  }

  /* Sum: '<S94>/Sum1' */
  localSum1_k = AirSys_mAirEngSelReq - localSum1_k;

  /* RelationalOperator: '<S94>/Relational Operator1' incorporates:
   *  Abs: '<S94>/Abs'
   *  Constant: '<S94>/AirSys_mAirEngCylThd_C'
   *  DataTypeConversion: '<S94>/DTC2'
   */
  localRelationalOperator1_bt = (ACTEMS_FabsF(localSum1_k) <= (((Float32)
    AirSys_mAirEngCylThd_C) * 1.192016583E-007F));

  /* end of Outputs for SubSystem: '<S85>/F02_Choix_de_la_masse_de_consigne' */

  /* Outputs for enable SubSystem: '<S85>/F03_Correcteur_PI_masse_air' incorporates:
   *  EnablePort: '<S95>/AirSys_bEnaPICor'
   *  Logic: '<S85>/Logical Operator4'
   *
   * Block requirements for '<S85>/F03_Correcteur_PI_masse_air':
   *  1. SubSystem "F03_Correcteur_PI_masse_air" !Trace_To : VEMS_R_10_07030_009.01 ;
   */
  if (!localNot) {
    /* Outputs for atomic SubSystem: '<S95>/F01_Condition_integrateur' *
     * Block requirements for '<S95>/F01_Condition_integrateur':
     *  1. SubSystem "F01_Condition_integrateur" !Trace_To : VEMS_R_10_07030_010.01 ;
     */

    /* Outputs for atomic SubSystem: '<S99>/F01_Structure_Couple_non_boucle' *
     * Block requirements for '<S99>/F01_Structure_Couple_non_boucle':
     *  1. SubSystem "F01_Structure_Couple_non_boucle" !Trace_To : VEMS_R_10_07030_011.01 ;
     */

    /* RelationalOperator: '<S101>/Relational Operator2' incorporates:
     *  Constant: '<S101>/ConstVal'
     */
    AirSys_bInhPIStructAirOpl = (AirSysAir_B.TmpSignalConversionAtAirSys_fac !=
      0);

    /* end of Outputs for SubSystem: '<S99>/F01_Structure_Couple_non_boucle' */

    /* Outputs for atomic SubSystem: '<S99>/F02_Plein_charge_pied_leve' *
     * Block requirements for '<S99>/F02_Plein_charge_pied_leve':
     *  1. SubSystem "F02_Plein_charge_pied_leve" !Trace_To : VEMS_R_10_07030_012.01 ;
     */

    /* Logic: '<S102>/Logical Operator3' incorporates:
     *  Constant: '<S102>/CrkMgt_stOplTq_SC'
     *  RelationalOperator: '<S102>/Relational Operator1'
     */
    AirSys_bInhPIAccPMin = ((AirSysAir_B.TmpSignalConversionAtCrkMgt_stT ==
      CrkMgt_stOplTq_SC) && (localTmpSignalConversionAtAccP_));

    /* end of Outputs for SubSystem: '<S99>/F02_Plein_charge_pied_leve' */

    /* Outputs for atomic SubSystem: '<S99>/F03_Papillon_butte' *
     * Block requirements for '<S99>/F03_Papillon_butte':
     *  1. SubSystem "F03_Papillon_butte" !Trace_To : VEMS_R_10_07030_013.02 ;
     */

    /* Lookup_n-D: '<S108>/Lookup Table (n-D)' */
    localSum1_k = look1_iu16lftu16n10If_binlcns
      (AirSysAir_B.TmpSignalConversionAtExt_nEngOu, (&(AirSys_nEng_A[0])),
       (&(AirSys_rMaxThrPosn_T[0])), 9U);

    /* Switch: '<S103>/Switch2' incorporates:
     *  Constant: '<S103>/AirSys_rOpThrReqMaxOfs_C1'
     *  DataTypeConversion: '<S103>/DTC1'
     */
    if (!AirSys_bSelMaxThrPosn_C) {
      localSum1_k = ((Float32)localTmpSignalConversionAtThr_r) * 0.0009765625F;
    }

    /* DataTypeConversion: '<S103>/DTC3' */
    localDTC1 = ((Float32)localTmpSignalConversionAtThrLr) * 0.0009765625F;

    /* Logic: '<S103>/Logical Operator3' incorporates:
     *  Constant: '<S103>/AirSys_bInhFullLdCtl_C1'
     *  RelationalOperator: '<S103>/Relational Operator9'
     */
    localTmpSignalConversionAtAccP_ = ((AirSys_mAirEngSelReq >= localDTC2) ||
      AirSys_bPresTrb_C);

    /* RelationalOperator: '<S109>/Relational Operator' */
    localRelationalOperator = (localDTC1 >= localSum1_k);

    /* RelationalOperator: '<S109>/Relational Operator1' incorporates:
     *  Constant: '<S103>/AirSys_rOpThrReqMaxOfs_C'
     *  DataTypeConversion: '<S103>/DTC2'
     *  Sum: '<S103>/Add1'
     */
    localRelationalOperator1_g = (localDTC1 <= (localSum1_k - (((Float32)
      AirSys_rOpThrReqMaxOfs_C) * 0.0009765625F)));

    /* UnitDelay: '<S110>/UnitDelay' */
    localUnitDelay1 = AirSysAir_DWork.UnitDelay_ed;

    /* CombinatorialLogic: '<S110>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_g != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = AirSysAir_ConstP.pooled17[rowidx];
      localLogic[1] = AirSysAir_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S110>/UnitDelay1' */
    localUnitDelay1 = AirSysAir_DWork.UnitDelay_dz;

    /* Switch: '<S110>/Switch2' incorporates:
     *  Constant: '<S110>/NotCLR3'
     */
    if (localUnitDelay1) {
      localTmpSignalConversionAtAir_n = localLogic[0];
    } else {
      localTmpSignalConversionAtAir_n = TRUE;
    }

    /* Logic: '<S103>/Logical Operator2' incorporates:
     *  Constant: '<S103>/AirSys_bInhFullLdCtl_C'
     *  Constant: '<S103>/AirSys_rMinThrPosn_C'
     *  Logic: '<S103>/Logical Operator1'
     *  Logic: '<S103>/Logical Operator5'
     *  RelationalOperator: '<S103>/Relational Operator2'
     *  RelationalOperator: '<S103>/Relational Operator6'
     */
    AirSys_bInhPIThrLim = (((localTmpSignalConversionAtThrLr <
      AirSys_rMinThrPosn_C) && (localDTC2 > AirSys_mAirEngSelReq)) ||
      (((localTmpSignalConversionAtAccP_) && AirSys_bInhFullLdCtl_C) &&
       (localTmpSignalConversionAtAir_n)));

    /* Update for UnitDelay: '<S110>/UnitDelay' */
    AirSysAir_DWork.UnitDelay_ed = localTmpSignalConversionAtAir_n;

    /* Update for UnitDelay: '<S110>/UnitDelay1' incorporates:
     *  Constant: '<S110>/NotCLR2'
     */
    AirSysAir_DWork.UnitDelay_dz = TRUE;

    /* end of Outputs for SubSystem: '<S99>/F03_Papillon_butte' */

    /* Outputs for atomic SubSystem: '<S99>/F04_Transitoire_charge' *
     * Block requirements for '<S99>/F04_Transitoire_charge':
     *  1. SubSystem "F04_Transitoire_charge" !Trace_To : VEMS_R_10_07030_014.01 ;
     */

    /* Logic: '<S104>/Logical Operator' incorporates:
     *  Abs: '<S104>/Abs'
     *  Abs: '<S104>/Abs1'
     *  Constant: '<S104>/AirSys_mAirEngCylThdReq_C'
     *  Constant: '<S104>/AirSys_mEngAirThd_C'
     *  DataTypeConversion: '<S104>/DTC1'
     *  DataTypeConversion: '<S104>/DTC2'
     *  RelationalOperator: '<S104>/Relational Operator3'
     *  RelationalOperator: '<S104>/Relational Operator5'
     *  Sum: '<S104>/Sum'
     *  Sum: '<S104>/Sum1'
     *  UnitDelay: '<S111>/Unit Delay'
     *  UnitDelay: '<S112>/Unit Delay'
     */
    AirSys_bInhPITranLdDet = ((ACTEMS_FabsF(localDTC2 -
      AirSysAir_DWork.UnitDelay_DSTATE_j) > (((Float32)AirSys_mEngAirThd_C) *
      1.192016583E-007F)) || (ACTEMS_FabsF(AirSys_mAirEngSelReq -
      AirSysAir_DWork.UnitDelay_DSTATE_i) > (((Float32)
      AirSys_mAirEngCylThdReq_C) * 1.192016583E-007F)));

    /* Update for UnitDelay: '<S111>/Unit Delay' */
    AirSysAir_DWork.UnitDelay_DSTATE_j = localDTC2;

    /* Update for UnitDelay: '<S112>/Unit Delay' */
    AirSysAir_DWork.UnitDelay_DSTATE_i = AirSys_mAirEngSelReq;

    /* end of Outputs for SubSystem: '<S99>/F04_Transitoire_charge' */

    /* Outputs for atomic SubSystem: '<S99>/F05_Attente_delai_degrassage_EGR' *
     * Block requirements for '<S99>/F05_Attente_delai_degrassage_EGR':
     *  1. SubSystem "F05_Attente_delai_degrassage_EGR" !Trace_To : VEMS_R_10_07030_015.01 ;
     */

    /* RelationalOperator: '<S105>/Relational Operator8' incorporates:
     *  Constant: '<S105>/ConstVal'
     */
    AirSys_bInhPIEgrFoul = (AirSys_tiDlyAftEgrFoulPrev != 0);

    /* end of Outputs for SubSystem: '<S99>/F05_Attente_delai_degrassage_EGR' */

    /* Outputs for atomic SubSystem: '<S99>/F07_Activation_limitation_pompage' *
     * Block requirements for '<S99>/F07_Activation_limitation_pompage':
     *  1. SubSystem "F07_Activation_limitation_pompage" !Trace_To : VEMS_R_10_07030_017.01 ;
     */

    /* Logic: '<S107>/Logical Operator3' incorporates:
     *  Constant: '<S107>/AirSys_bInhPILimSurge_C'
     */
    AirSys_bInhPILimSurge = ((localRelationalOperator1_bt) &&
      AirSys_bInhPILimSurge_C);

    /* end of Outputs for SubSystem: '<S99>/F07_Activation_limitation_pompage' */

    /* Outputs for atomic SubSystem: '<S99>/F06_Condition_inhibition_integrateur' *
     * Block requirements for '<S99>/F06_Condition_inhibition_integrateur':
     *  1. SubSystem "F06_Condition_inhibition_integrateur" !Trace_To : VEMS_R_10_07030_016.01 ;
     */

    /* Logic: '<S106>/Logical Operator' */
    localLogicalOperator_o = (((((AirSys_bInhPIStructAirOpl ||
      AirSys_bInhPIAccPMin) || AirSys_bInhPIThrLim) || AirSys_bInhPITranLdDet) ||
      AirSys_bInhPIEgrFoul) || AirSys_bInhPILimSurge);

    /* end of Outputs for SubSystem: '<S99>/F06_Condition_inhibition_integrateur' */

    /* end of Outputs for SubSystem: '<S95>/F01_Condition_integrateur' */

    /* Outputs for atomic SubSystem: '<S95>/F02_Calcul_correction_PI' *
     * Block requirements for '<S95>/F02_Calcul_correction_PI':
     *  1. SubSystem "F02_Calcul_correction_PI" !Trace_To : VEMS_R_10_07030_018.01 ;
     */

    /* Outputs for atomic SubSystem: '<S100>/F01_Calcul_erreur_PI' *
     * Block requirements for '<S100>/F01_Calcul_erreur_PI':
     *  1. SubSystem "F01_Calcul_erreur_PI" !Trace_To : VEMS_R_10_07030_019.01 ;
     */

    /* Sum: '<S113>/Sum' */
    AirSys_mEngAirErr = AirSys_mAirEngSelReq - localDTC2;

    /* end of Outputs for SubSystem: '<S100>/F01_Calcul_erreur_PI' */

    /* Outputs for atomic SubSystem: '<S100>/F02_Calcul_terme_integral' *
     * Block requirements for '<S100>/F02_Calcul_terme_integral':
     *  1. SubSystem "F02_Calcul_terme_integral" !Trace_To : VEMS_R_10_07030_020.01 ;
     */

    /* Sum: '<S119>/Add2' incorporates:
     *  Constant: '<S119>/offset'
     *  Constant: '<S119>/offset1'
     *  Constant: '<S119>/one_on_slope'
     *  Product: '<S119>/Product4'
     *  Sum: '<S119>/Add1'
     */
    localDTC1 = ((AirSys_mEngAirErr - -3.905999940E-003F) * 8.389145E+006F) +
      0.5F;

    /* DataTypeConversion: '<S119>/OutDTConv' */
    if (localDTC1 < 65536.0F) {
      if (localDTC1 >= 0.0F) {
        localTmpSignalConversionAtAir_f = (UInt16)localDTC1;
      } else {
        localTmpSignalConversionAtAir_f = 0U;
      }
    } else {
      localTmpSignalConversionAtAir_f = MAX_uint16_T;
    }

    /* Switch: '<S114>/Switch2' incorporates:
     *  Constant: '<S114>/ConstVal_2'
     *  Lookup_n-D: '<S117>/Lookup Table (n-D)'
     *  Product: '<S120>/Divide'
     */
    if (localLogicalOperator_o) {
      localDTC1 = 0.0F;
    } else {
      localDTC1 = look1_iu16lftu16n16If_binlcns(localTmpSignalConversionAtAir_f,
        (&(AirSys_mEngAirErr_A[0])), (&(AirSys_faciMassIntCorRef1_T[0])), 8U) *
        AirSys_mEngAirErr;
    }

    /* Sum: '<S114>/Sum2' */
    localDTC1 += AirSys_mAirEngIntCorPrev;

    /* DataTypeConversion: '<S114>/DTC1' incorporates:
     *  Constant: '<S114>/AirSys_mEngAirIntCorMax_C'
     */
    localSwitch2_f = ((Float32)AirSys_mEngAirIntCorMax_C) * 7.629394531E-006F;

    /* DataTypeConversion: '<S114>/DTC2' incorporates:
     *  Constant: '<S114>/AirSys_mEngAirIntCorMin_C'
     */
    localSum1_k = ((Float32)AirSys_mEngAirIntCorMin_C) * 7.629394531E-006F;

    /* Switch: '<S123>/Switch' incorporates:
     *  RelationalOperator: '<S123>/UpperRelop'
     */
    if (!(localDTC1 < localSum1_k)) {
      localSum1_k = localDTC1;
    }

    /* Switch: '<S123>/Switch2' incorporates:
     *  RelationalOperator: '<S123>/LowerRelop1'
     */
    if (!(localDTC1 > localSwitch2_f)) {
      localSwitch2_f = localSum1_k;
    }

    /* Switch: '<S114>/Switch' incorporates:
     *  Constant: '<S114>/ConstVal'
     *  Constant: '<S114>/Ext_stStall_SC'
     *  RelationalOperator: '<S114>/Relational Operator3'
     */
    if (localTmpSignalConversionAtEng_s == Ext_stStall_SC) {
      localSwitch2_f = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S100>/F02_Calcul_terme_integral' */

    /* Outputs for atomic SubSystem: '<S100>/F03_Calcul_terme_proportionnel' *
     * Block requirements for '<S100>/F03_Calcul_terme_proportionnel':
     *  1. SubSystem "F03_Calcul_terme_proportionnel" !Trace_To : VEMS_R_10_07030_021.01 ;
     */

    /* Sum: '<S125>/Add2' incorporates:
     *  Constant: '<S125>/offset'
     *  Constant: '<S125>/offset1'
     *  Constant: '<S125>/one_on_slope'
     *  Product: '<S125>/Product4'
     *  Sum: '<S125>/Add1'
     */
    localDTC1 = ((AirSys_mEngAirErr - -3.905999940E-003F) * 8.389145E+006F) +
      0.5F;

    /* DataTypeConversion: '<S125>/OutDTConv' */
    if (localDTC1 < 65536.0F) {
      if (localDTC1 >= 0.0F) {
        localTmpSignalConversionAtAir_f = (UInt16)localDTC1;
      } else {
        localTmpSignalConversionAtAir_f = 0U;
      }
    } else {
      localTmpSignalConversionAtAir_f = MAX_uint16_T;
    }

    /* Product: '<S126>/Divide' incorporates:
     *  Lookup_n-D: '<S124>/Lookup Table (n-D)'
     */
    AirSys_mAirEngPropCor = look2_1fcv2bcvbcvbfbbr6nfbbnx
      (AirSysAir_B.TmpSignalConversionAtExt_nEngOu,
       localTmpSignalConversionAtAir_f, (&(AirSys_nEng_A[0])),
       (&(AirSys_mEngAirErr_A[0])), (&(AirSys_facpMassIntCorRef1_M[0])),
       &AirSysAir_ConstP.LookupTablenD_maxInde[0], 10U) * AirSys_mEngAirErr;

    /* end of Outputs for SubSystem: '<S100>/F03_Calcul_terme_proportionnel' */

    /* Outputs for atomic SubSystem: '<S100>/F04_Calcul_du_correctif' *
     * Block requirements for '<S100>/F04_Calcul_du_correctif':
     *  1. SubSystem "F04_Calcul_du_correctif" !Trace_To : VEMS_R_10_07030_022.01 ;
     */

    /* Sum: '<S116>/Sum3' */
    AirSys_mEngAirCorOfs = localSwitch2_f + AirSys_mAirEngPropCor;

    /* end of Outputs for SubSystem: '<S100>/F04_Calcul_du_correctif' */

    /* end of Outputs for SubSystem: '<S95>/F02_Calcul_correction_PI' */
  }

  /* end of Outputs for SubSystem: '<S85>/F03_Correcteur_PI_masse_air' */

  /* Outputs for atomic SubSystem: '<S85>/F04_Calcul_de_la_masse_corrigee' *
   * Block requirements for '<S85>/F04_Calcul_de_la_masse_corrigee':
   *  1. SubSystem "F04_Calcul_de_la_masse_corrigee" !Trace_To : VEMS_R_10_07030_023.01 ;
   */

  /* Switch: '<S96>/Switch2' incorporates:
   *  Constant: '<S96>/AirSys_bInhPIIdl_C'
   *  Constant: '<S96>/CrkMgt_stCllTq_SC'
   *  Logic: '<S96>/Logical Operator1'
   *  Logic: '<S96>/Logical Operator2'
   *  RelationalOperator: '<S96>/Relational Operator1'
   *  Sum: '<S96>/Sum1'
   */
  if (((localNot) || (AirSysAir_B.TmpSignalConversionAtCrkMgt_stT !=
                      CrkMgt_stCllTq_SC)) || ((localTmpSignalConversionAtIdlSy) &&
       AirSys_bInhPIIdl_C)) {
    localDTC1 = AirSys_mAirEngSelReq;
  } else {
    localDTC1 = AirSys_mAirEngSelReq + AirSys_mEngAirCorOfs;
  }

  /* DataTypeConversion: '<S96>/DTC1' incorporates:
   *  Constant: '<S96>/AirSys_mAirEngCylMaxReq_C'
   */
  localSum1_k = ((Float32)AirSys_mAirEngCylMaxReq_C) * 1.192016583E-007F;

  /* Switch: '<S131>/Switch' incorporates:
   *  Constant: '<S96>/ConstVal'
   *  RelationalOperator: '<S131>/UpperRelop'
   */
  if (localDTC1 < 0.0F) {
    localDTC2 = 0.0F;
  } else {
    localDTC2 = localDTC1;
  }

  /* Switch: '<S131>/Switch2' incorporates:
   *  RelationalOperator: '<S131>/LowerRelop1'
   */
  if (!(localDTC1 > localSum1_k)) {
    localSum1_k = localDTC2;
  }

  /* Switch: '<S96>/Switch3' incorporates:
   *  Constant: '<S96>/ConstVal_2'
   *  Logic: '<S96>/Logical Operator'
   *  RelationalOperator: '<S96>/Relational Operator7'
   */
  if (!((((((localTmpSignalConversionAtInjSy[0]) ||
            (localTmpSignalConversionAtInjSy[1])) ||
           (localTmpSignalConversionAtInjSy[2])) ||
          (localTmpSignalConversionAtInjSy[3])) ||
         (localTmpSignalConversionAtInjSy[4])) ||
        (localTmpSignalConversionAtInjSy[5]))) {
    localSum1_k = localDTC1;
  }

  /* DataTypeConversion: '<S128>/OutDTConv' incorporates:
   *  Constant: '<S128>/offset'
   *  Constant: '<S128>/offset1'
   *  Constant: '<S128>/one_on_slope'
   *  Product: '<S128>/Product4'
   *  Sum: '<S128>/Add1'
   *  Sum: '<S128>/Add2'
   */
  localSum1_k = (8.389145E+006F * localSum1_k) + 0.5F;
  if (localSum1_k < 65536.0F) {
    if (localSum1_k >= 0.0F) {
      localOutDTConv_m = (UInt16)localSum1_k;
    } else {
      localOutDTConv_m = 0U;
    }
  } else {
    localOutDTConv_m = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S85>/F04_Calcul_de_la_masse_corrigee' */

  /* end of Outputs for SubSystem: '<S14>/F02_Correction_de_la_masse' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S88>/autosar_testpoint1' */

  /* S-Function Block: <S88>/autosar_testpoint1 */
  AirSys_bActStraLimSurgeDmpSw = localRelationalOperator1_bt;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S89>/autosar_testpoint1' */

  /* S-Function Block: <S89>/autosar_testpoint1 */
  AirSys_mAirEngCorReq_IRV_MP = localOutDTConv_m;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEGRVlv_stEGRModOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_stEGRMod'
   */
  Rte_Read_R_EGRVlv_stEGRMod_EGRVlv_stEGRMod(&localTmpSignalConversionAtEGRVl);

  /* Outputs for atomic SubSystem: '<S14>/F01_Calc_count_after_egr_fouling' *
   * Block requirements for '<S14>/F01_Calc_count_after_egr_fouling':
   *  1. SubSystem "F01_Calc_count_after_egr_fouling" !Trace_To : VEMS_R_10_07030_005.01 ;
   */

  /* MinMax: '<S84>/MinMax' incorporates:
   *  Constant: '<S84>/AirSys_tiSampleFast_SC'
   *  Constant: '<S84>/ConstVal'
   *  DataTypeConversion: '<S84>/DTC1'
   *  DataTypeConversion: '<S84>/DTC3'
   *  Sum: '<S84>/Sum2'
   */
  localrtmax = AirSys_tiDlyAftEgrFoulPrev - AirSys_tiSampleFast_SC;
  if (0 > localrtmax) {
    localrtmax = 0;
  }

  /* Switch: '<S84>/Switch2' incorporates:
   *  Constant: '<S84>/AirSys_tiDlyAftEgrFoul_C'
   *  Constant: '<S84>/EGRVlv_stEgrPrvtFoul_SC'
   *  DataTypeConversion: '<S84>/DTC2'
   *  RelationalOperator: '<S84>/Relational Operator7'
   */
  if (localTmpSignalConversionAtEGRVl == EGRVlv_stEgrPrvtFoul_SC) {
    localSwitch2_n = AirSys_tiDlyAftEgrFoul_C;
  } else if (localrtmax <= 0) {
    localSwitch2_n = 0U;
  } else if (localrtmax > 65535) {
    localSwitch2_n = MAX_uint16_T;
  } else {
    localSwitch2_n = (UInt16)localrtmax;
  }

  /* end of Outputs for SubSystem: '<S14>/F01_Calc_count_after_egr_fouling' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S90>/autosar_testpoint1' */

  /* S-Function Block: <S90>/autosar_testpoint1 */
  AirSys_tiDlyAftEgrFoul_IRV_MP = localSwitch2_n;

  /* SignalConversion: '<S14>/Signal Conversion2' */
  localTmpSignalConversionAtAir_f = localSwitch2_n;

  /* SignalConversion: '<S14>/Signal Conversion3' */
  localTmpSignalConversionAtEngM_ = localOutDTConv_m;

  /* Sum: '<S87>/Add2' incorporates:
   *  Constant: '<S87>/offset'
   *  Constant: '<S87>/offset1'
   *  Constant: '<S87>/one_on_slope'
   *  Product: '<S87>/Product4'
   *  Sum: '<S87>/Add1'
   */
  localDTC1 = ((localSwitch2_f - -1.953099971E-003F) * 1.099511628E+012F) + 0.5F;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_bActStraLimSurgeDmpSw_irvInport2' incorporates:
   *  SignalConversion: '<S14>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_AirSysAir_003_TEV_AirSys_bActStraLimSurgeDmpSw_irv
    (localRelationalOperator1_bt);

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Byp_Fonction_SC'
   *  Constant: '<S91>/Int_BypC'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localLogicalOperator_o = AirSys_bInhPiAirEngCor_B;
  }

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_bInhPiAirEngCorInport2' */
  Rte_Write_P_AirSys_bInhPiAirEngCor_AirSys_bInhPiAirEngCor
    (localLogicalOperator_o);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_mAirEngCorReq_irvInport2' */
  Rte_IrvWrite_RE_AirSysAir_003_TEV_AirSys_mAirEngCorReq_irv
    (localTmpSignalConversionAtEngM_);

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S92>/Byp_Fonction_SC'
   *  Constant: '<S92>/Int_BypC'
   *  DataTypeConversion: '<S87>/OutDTConv'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAirSy = AirSys_mAirEngIntCor_B;
  } else if (localDTC1 < 4.294967296E+009F) {
    if (localDTC1 >= 0.0F) {
      localTmpSignalConversionAtAirSy = (UInt32)localDTC1;
    } else {
      localTmpSignalConversionAtAirSy = 0U;
    }
  } else {
    localTmpSignalConversionAtAirSy = MAX_uint32_T;
  }

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_mAirEngIntCorInport2' */
  Rte_Write_P_AirSys_mAirEngIntCor_AirSys_mAirEngIntCor
    (localTmpSignalConversionAtAirSy);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirSys_tiDlyAftEgrFoul_irvInport2' */
  Rte_IrvWrite_RE_AirSysAir_003_TEV_AirSys_tiDlyAftEgrFoul_irv
    (localTmpSignalConversionAtAir_f);
}

/* Start for exported function: RE_AirSysAir_004_TEV */
void RE_AirSysAir_004_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_AirFlowMnfldSp'
   *
   * Block requirements for '<S1>/F01_AirFlowMnfldSp':
   *  1. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_102.03 ;
   *  2. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_028.01 ;
   *  3. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_029.01 ;
   *  4. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_074.01 ;
   *  5. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_075.01 ;
   *  6. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_071.02 ;
   *  7. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_072.01 ;
   *  8. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_076.01 ;
   *  9. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_073.02 ;
   *  10. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_092.02 ;
   *  11. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_110.02 ;
   *  12. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_070.01 ;
   *  13. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_116.01 ;
   *  14. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_093.02 ;
   */
}

/* Output and update for exported function: RE_AirSysAir_004_TEV */
void RE_AirSysAir_004_TEV(void)
{
  /* local block i/o variables */
  UInt16 localOutDTConv_k[2];
  UInt16 localTmpSignalConversionAtExt_n;
  Float32 localDTC45;
  Float32 localDivide_i;
  Float32 localLookupTablenD_c;
  UInt16 localOutDTConv_p3[2];
  UInt16 localTmpSignalConversionAtAir_i;
  UInt16 localTmpSignalConversionAtEng_j;
  UInt16 localTmpSignalConversionAtEn_d0;
  UInt16 localTmpSignalConversionAtInM_m;
  SInt32 localTmpSignalConversionAtBlby_;
  UInt16 localTmpSignalConversionAtCanPu;
  UInt16 localTmpSignalConversionAtEGRSy;
  Float32 locallocalDivide_d_idx;
  Float32 locallocalSum1_h_idx;
  Float32 locallocalDivide_d_idx_0;
  Float32 locallocalSum1_h_idx_0;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_AirFlowMnfldSp'
   *
   * Block requirements for '<S1>/F01_AirFlowMnfldSp':
   *  1. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_102.03 ;
   *  2. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_028.01 ;
   *  3. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_029.01 ;
   *  4. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_074.01 ;
   *  5. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_075.01 ;
   *  6. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_071.02 ;
   *  7. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_072.01 ;
   *  8. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_076.01 ;
   *  9. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_073.02 ;
   *  10. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_092.02 ;
   *  11. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_110.02 ;
   *  12. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_070.01 ;
   *  13. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_116.01 ;
   *  14. SubSystem "F01_AirFlowMnfldSp" !Trace_To : VEMS_R_10_07030_093.02 ;
   */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* DataTypeConversion: '<S10>/DTC45' */
  localDTC45 = (Float32)localTmpSignalConversionAtExt_n;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_mAirEngCylReq_tqEngOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mAirEngCylReq_tqEng_INPUT'
   */
  Rte_Read_R_AirSys_mAirEngCylReq_tqEng_AirSys_mAirEngCylReq_tqEng
    (&localTmpSignalConversionAtAir_i);

  /* DataTypeConversion: '<S10>/DTC6' incorporates:
   *  SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_mAirEngCorReqOutport2'
   */
  AirSys_prm_mAirEngReq_MP[0] = localTmpSignalConversionAtAir_i;
  AirSys_prm_mAirEngReq_MP[1] =
    Rte_IrvRead_RE_AirSysAir_004_TEV_AirSys_mAirEngCorReq_irv();

  /* DataTypeConversion: '<S10>/DTC7' */
  locallocalSum1_h_idx = ((Float32)AirSys_prm_mAirEngReq_MP[0]) *
    1.192016583E-007F;
  locallocalSum1_h_idx_0 = ((Float32)AirSys_prm_mAirEngReq_MP[1]) *
    1.192016583E-007F;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEngM_rMassAirResiCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rMassAirResiCor'
   */
  Rte_Read_R_EngM_rMassAirResiCor_EngM_rMassAirResiCor
    (&localTmpSignalConversionAtEng_j);

  /* Product: '<S41>/Divide' incorporates:
   *  Constant: '<S10>/Eng_mRef_C'
   *  DataTypeConversion: '<S10>/DTC10'
   *  DataTypeConversion: '<S10>/DTC5'
   */
  localDivide_i = (((Float32)localTmpSignalConversionAtEng_j) *
                   6.103515625E-005F) * (((Float32)Eng_mRef_C) *
    1.192016583E-007F);

  /* Product: '<S40>/Divide' incorporates:
   *  Sum: '<S10>/Sum4'
   */
  locallocalDivide_d_idx = (locallocalSum1_h_idx - localDivide_i) * localDTC45;
  locallocalDivide_d_idx_0 = (locallocalSum1_h_idx_0 - localDivide_i) *
    localDTC45;

  /* Product: '<S38>/Divide' incorporates:
   *  Constant: '<S10>/Ext_noCylEng_SC'
   *  Constant: '<S10>/Ext_noCylRev_SC'
   *  DataTypeConversion: '<S10>/DTC8'
   *  DataTypeConversion: '<S10>/DTC9'
   */
  localDivide_i = ((Float32)Ext_noCylRev_SC) / ((Float32)Ext_noCylEng_SC);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEngM_mfAirScvCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfAirScvCor'
   */
  Rte_Read_R_EngM_mfAirScvCor_EngM_mfAirScvCor(&localTmpSignalConversionAtEn_d0);

  /* DataTypeConversion: '<S10>/DTC4' */
  localLookupTablenD_c = ((Float32)localTmpSignalConversionAtEn_d0) *
    1.525878906E-005F;

  /* Sum: '<S10>/Sum3' incorporates:
   *  Product: '<S37>/Divide'
   */
  locallocalDivide_d_idx = (locallocalDivide_d_idx / localDivide_i) +
    localLookupTablenD_c;
  locallocalDivide_d_idx_0 = (locallocalDivide_d_idx_0 / localDivide_i) +
    localLookupTablenD_c;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_mfAirCanPurgEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirCanPurgEstim'
   */
  Rte_Read_R_InM_mfAirCanPurgEstim_InM_mfAirCanPurgEstim
    (&localTmpSignalConversionAtInM_m);

  /* DataTypeConversion: '<S10>/DTC3' */
  localLookupTablenD_c = ((Float32)localTmpSignalConversionAtInM_m) *
    9.536743164E-007F;

  /* DataTypeConversion: '<S31>/OutDTConv' incorporates:
   *  Constant: '<S31>/offset'
   *  Constant: '<S31>/offset1'
   *  Constant: '<S31>/one_on_slope'
   *  Product: '<S31>/Product4'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S31>/Add1'
   *  Sum: '<S31>/Add2'
   */
  locallocalDivide_d_idx = ((locallocalDivide_d_idx - localLookupTablenD_c) *
    65536.0F) + 0.5F;
  if (locallocalDivide_d_idx < 65536.0F) {
    if (locallocalDivide_d_idx >= 0.0F) {
      localTmpSignalConversionAtExt_n = (UInt16)locallocalDivide_d_idx;
    } else {
      localTmpSignalConversionAtExt_n = 0U;
    }
  } else {
    localTmpSignalConversionAtExt_n = MAX_uint16_T;
  }

  localOutDTConv_p3[0] = localTmpSignalConversionAtExt_n;

  /* DataTypeConversion: '<S31>/OutDTConv' incorporates:
   *  Constant: '<S31>/offset'
   *  Constant: '<S31>/offset1'
   *  Constant: '<S31>/one_on_slope'
   *  Product: '<S31>/Product4'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S31>/Add1'
   *  Sum: '<S31>/Add2'
   */
  locallocalDivide_d_idx = ((locallocalDivide_d_idx_0 - localLookupTablenD_c) *
    65536.0F) + 0.5F;
  if (locallocalDivide_d_idx < 65536.0F) {
    if (locallocalDivide_d_idx >= 0.0F) {
      localTmpSignalConversionAtExt_n = (UInt16)locallocalDivide_d_idx;
    } else {
      localTmpSignalConversionAtExt_n = 0U;
    }
  } else {
    localTmpSignalConversionAtExt_n = MAX_uint16_T;
  }

  localOutDTConv_p3[1] = localTmpSignalConversionAtExt_n;

  /* Lookup_n-D: '<S30>/Lookup Table (n-D)' */
  localLookupTablenD_c = look1_iu16lftu16n23If_binlcns(localOutDTConv_p3[0],
    (&(AirSys_mfAirThrReq_A[0])), (&(AirSys_mfFuStmMax_T[0])), 7U);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtBlby_mfFuStmCmpAirSysOutport2' incorporates:
   *  Inport: '<Root>/Blby_mfFuStmCmpAirSys'
   */
  Rte_Read_R_Blby_mfFuStmCmpAirSys_Blby_mfFuStmCmpAirSys
    (&localTmpSignalConversionAtBlby_);

  /* DataTypeConversion: '<S10>/DTC11' */
  locallocalDivide_d_idx = ((Float32)localTmpSignalConversionAtBlby_) *
    1.192092896E-007F;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtCanPurg_mfFuStmEstimOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_mfFuStmEstim'
   */
  Rte_Read_R_CanPurg_mfFuStmEstim_CanPurg_mfFuStmEstim
    (&localTmpSignalConversionAtCanPu);

  /* Product: '<S34>/Divide' incorporates:
   *  DataTypeConversion: '<S10>/DTC1'
   *  MinMax: '<S10>/MinMax'
   *  Sum: '<S10>/Sum5'
   */
  localDTC45 = ((((Float32)localTmpSignalConversionAtCanPu) * 9.536743164E-007F)
                + rt_MINf(localLookupTablenD_c, locallocalDivide_d_idx)) /
    localDTC45;

  /* Outputs for atomic SubSystem: '<S34>/If Action Subsystem3' */

  /* Switch: '<S45>/Switch1' incorporates:
   *  Constant: '<S45>/Constant1'
   *  Constant: '<S45>/Constant2'
   *  Constant: '<S45>/Constant3'
   *  Logic: '<S45>/Logical Operator1'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  RelationalOperator: '<S45>/Relational Operator1'
   *  RelationalOperator: '<S45>/Relational Operator3'
   */
  if (((localDTC45 != localDTC45) || (localDTC45 > 3.000000005E+038F)) ||
      (-3.000000005E+038F > localDTC45)) {
    localDTC45 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S34>/If Action Subsystem3' */

  /* Product: '<S39>/Divide' */
  localDivide_i *= localDTC45;

  /* Sum: '<S10>/Sum1' */
  locallocalSum1_h_idx += localDivide_i;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEGRSys_rEGRReqOutport2' incorporates:
   *  Inport: '<Root>/EGRSys_rEGRReq'
   */
  Rte_Read_R_EGRSys_rEGRReq_EGRSys_rEGRReq(&localTmpSignalConversionAtEGRSy);

  /* Sum: '<S10>/Sum2' incorporates:
   *  Constant: '<S10>/ConstVal'
   *  DataTypeConversion: '<S10>/DTC2'
   */
  localDTC45 = 1.0F - (((Float32)localTmpSignalConversionAtEGRSy) *
                       0.001953125F);

  /* Product: '<S33>/Divide' */
  locallocalDivide_d_idx = locallocalSum1_h_idx / localDTC45;

  /* DataTypeConversion: '<S32>/OutDTConv' incorporates:
   *  Constant: '<S32>/offset'
   *  Constant: '<S32>/offset1'
   *  Constant: '<S32>/one_on_slope'
   *  Constant: '<S43>/Constant1'
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  Logic: '<S43>/Logical Operator1'
   *  Product: '<S32>/Product4'
   *  RelationalOperator: '<S43>/Relational Operator'
   *  RelationalOperator: '<S43>/Relational Operator1'
   *  RelationalOperator: '<S43>/Relational Operator3'
   *  Sum: '<S32>/Add1'
   *  Sum: '<S32>/Add2'
   *  Switch: '<S43>/Switch1'
   */
  if (((locallocalDivide_d_idx != locallocalDivide_d_idx) ||
       (locallocalDivide_d_idx > 3.000000005E+038F)) || (-3.000000005E+038F >
       locallocalDivide_d_idx)) {
    locallocalDivide_d_idx = 0.0F;
  }

  locallocalDivide_d_idx = (8.389145E+006F * locallocalDivide_d_idx) + 0.5F;
  if (locallocalDivide_d_idx < 65536.0F) {
    if (locallocalDivide_d_idx >= 0.0F) {
      localTmpSignalConversionAtExt_n = (UInt16)locallocalDivide_d_idx;
    } else {
      localTmpSignalConversionAtExt_n = 0U;
    }
  } else {
    localTmpSignalConversionAtExt_n = MAX_uint16_T;
  }

  localOutDTConv_k[0] = localTmpSignalConversionAtExt_n;

  /* Product: '<S33>/Divide' */
  locallocalDivide_d_idx = (localDivide_i + locallocalSum1_h_idx_0) / localDTC45;

  /* DataTypeConversion: '<S32>/OutDTConv' incorporates:
   *  Constant: '<S32>/offset'
   *  Constant: '<S32>/offset1'
   *  Constant: '<S32>/one_on_slope'
   *  Constant: '<S43>/Constant1'
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  Logic: '<S43>/Logical Operator1'
   *  Product: '<S32>/Product4'
   *  RelationalOperator: '<S43>/Relational Operator'
   *  RelationalOperator: '<S43>/Relational Operator1'
   *  RelationalOperator: '<S43>/Relational Operator3'
   *  Sum: '<S32>/Add1'
   *  Sum: '<S32>/Add2'
   *  Switch: '<S43>/Switch1'
   */
  if (((locallocalDivide_d_idx != locallocalDivide_d_idx) ||
       (locallocalDivide_d_idx > 3.000000005E+038F)) || (-3.000000005E+038F >
       locallocalDivide_d_idx)) {
    locallocalDivide_d_idx = 0.0F;
  }

  locallocalDivide_d_idx = (8.389145E+006F * locallocalDivide_d_idx) + 0.5F;
  if (locallocalDivide_d_idx < 65536.0F) {
    if (locallocalDivide_d_idx >= 0.0F) {
      localTmpSignalConversionAtExt_n = (UInt16)locallocalDivide_d_idx;
    } else {
      localTmpSignalConversionAtExt_n = 0U;
    }
  } else {
    localTmpSignalConversionAtExt_n = MAX_uint16_T;
  }

  localOutDTConv_k[1] = localTmpSignalConversionAtExt_n;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S35>/autosar_testpoint1' */

  /* S-Function Block: <S35>/autosar_testpoint1 */
  AirSys_prm_mAirCylReq_IRV_MP[0] = localOutDTConv_k[0];
  AirSys_prm_mAirCylReq_IRV_MP[1] = localOutDTConv_k[1];

  /* SignalConversion: '<S10>/Signal Conversion2' */
  localTmpSignalConversionAtExt_n = localOutDTConv_k[1];

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_prm_mAirCylReq1_irvInport2' incorporates:
   *  SignalConversion: '<S10>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_AirSysAir_004_TEV_AirSys_prm_mAirCylReq_01_irv
    (localOutDTConv_k[0]);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_prm_mAirCylReq2_irvInport2' */
  Rte_IrvWrite_RE_AirSysAir_004_TEV_AirSys_prm_mAirCylReq_02_irv
    (localTmpSignalConversionAtExt_n);

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/Byp_Fonction_SC'
   *  Constant: '<S36>/Int_BypC'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localOutDTConv_p3[0] = AirSys_prm_mfAirThrReq_B[0];
    localOutDTConv_p3[1] = AirSys_prm_mfAirThrReq_B[1];
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_prm_mfAirThrReqInport2' */
  Rte_Write_P_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq(&localOutDTConv_p3);
}

/* Start for exported function: RE_AirSysAir_006_TEV */
void RE_AirSysAir_006_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Calcul_consigne_surface'
   *
   * Block requirements for '<S1>/F02_Calcul_consigne_surface':
   *  1. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_104.04 ;
   *  2. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_030.02 ;
   *  3. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_031.02 ;
   *  4. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_033.02 ;
   *  5. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_086.03 ;
   *  6. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_087.01 ;
   *  7. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_085.01 ;
   *  8. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_095.03 ;
   *  9. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_096.01 ;
   *  10. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_112.01 ;
   *  11. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_113.01 ;
   *  12. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_119.01 ;
   */

  /* Start for atomic SubSystem: '<S15>/F01_Calcul_obj_flux_surfacique' *
   * Block requirements for '<S15>/F01_Calcul_obj_flux_surfacique':
   *  1. SubSystem "F01_Calcul_obj_flux_surfacique" !Trace_To : VEMS_R_10_07030_034.02 ;
   */

  /* Start for atomic SubSystem: '<S132>/F01_Compute_air_pressure_ratio' *
   * Block requirements for '<S132>/F01_Compute_air_pressure_ratio':
   *  1. SubSystem "F01_Compute_air_pressure_ratio" !Trace_To : VEMS_R_10_07030_035.02 ;
   */

  /* Start for ifaction SubSystem: '<S142>/F02_Filtering' *
   * Block requirements for '<S142>/F02_Filtering':
   *  1. SubSystem "F02_Filtering" !Trace_To : VEMS_R_10_07030_037.03 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S145>/F01_Compute_pressure_ratio' *
   * Block requirements for '<S145>/F01_Compute_pressure_ratio':
   *  1. SubSystem "F01_Compute_pressure_ratio" !Trace_To : VEMS_R_10_07030_038.02 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S155>/F01_Control_conditions' *
   * Block requirements for '<S155>/F01_Control_conditions':
   *  1. SubSystem "F01_Control_conditions" !Trace_To : VEMS_R_10_07030_039.02 ;
   */

  /* InitializeConditions for UnitDelay: '<S162>/UnitDelay' */
  AirSysAir_DWork.UnitDelay_f = TRUE;

  /* end of InitializeConditions for SubSystem: '<S155>/F01_Control_conditions' */

  /* InitializeConditions for atomic SubSystem: '<S155>/F03_Compute_pressure_ratio' *
   * Block requirements for '<S155>/F03_Compute_pressure_ratio':
   *  1. SubSystem "F03_Compute_pressure_ratio" !Trace_To : VEMS_R_10_07030_041.01 ;
   */

  /* InitializeConditions for UnitDelay: '<S174>/UnitDelay' */
  AirSysAir_DWork.UnitDelay_l = TRUE;

  /* InitializeConditions for UnitDelay: '<S175>/UnitDelay' */
  AirSysAir_DWork.UnitDelay_h = TRUE;

  /* end of InitializeConditions for SubSystem: '<S155>/F03_Compute_pressure_ratio' */

  /* end of InitializeConditions for SubSystem: '<S145>/F01_Compute_pressure_ratio' */

  /* InitializeConditions for atomic SubSystem: '<S145>/F02_Compute_filtering_condition' *
   * Block requirements for '<S145>/F02_Compute_filtering_condition':
   *  1. SubSystem "F02_Compute_filtering_condition" !Trace_To : VEMS_R_10_07030_042.02 ;
   */

  /* InitializeConditions for UnitDelay: '<S177>/UnitDelay' */
  AirSysAir_DWork.UnitDelay_j4 = TRUE;

  /* end of InitializeConditions for SubSystem: '<S145>/F02_Compute_filtering_condition' */

  /* end of Start for SubSystem: '<S142>/F02_Filtering' */

  /* end of Start for SubSystem: '<S132>/F01_Compute_air_pressure_ratio' */

  /* end of Start for SubSystem: '<S15>/F01_Calcul_obj_flux_surfacique' */
}

/* Output and update for exported function: RE_AirSysAir_006_TEV */
void RE_AirSysAir_006_TEV(void)
{
  /* local block i/o variables */
  UInt16 localMerge;
  UInt16 localOutDTConv_kq;
  Boolean localAutosarServer_p;
  Boolean localRelationalOperator1_n;
  Boolean localRelationalOperator_p;
  Boolean localUnitDelay_o;
  Boolean localLogic_p[2];
  Boolean localRelationalOperator_hg;
  Boolean localRelationalOperator1_fs;
  Boolean localLogic_a[2];
  Boolean localLogicalOperator5_m;
  Boolean localRelationalOperator4_d;
  Boolean localLogic_b[2];
  Boolean localUnitDelay1_g;
  Boolean localUnitDelay_h;
  Boolean localRelationalOperator1_a;
  Boolean localLogic_ah[2];
  Boolean localUnitDelay1_i;
  Boolean localUnitDelay1_j;
  Float32 localDTC45_f;
  Boolean localNot_n;
  Float32 localDTC1_k;
  Boolean localTmpSignalConversionAtCoCha;
  Boolean localTmpSignalConversionAtUsT_c;
  Boolean localLogicalOperator1_f3;
  Boolean localTmpSignalConversionAtDmp_b;
  Float32 localLookupTablenD_l;
  Float32 localLookupTablenD_h;
  Float32 localSum2_j;
  Float32 localExt_nEng_AirSys_nEngDec_A_;
  Float32 localAirSys_rAirPresCor_MP_AirS;
  Float32 localInterpolationUsingPreloo_o;
  Float32 localfrac[2];
  UInt32 localAirSys_rAirPres_MP_AirSys_;
  UInt32 localbpIndex[2];
  UInt32 localAirSys_rAirPresCor_MP_Ai_m;
  Float32 localInterpolationUsingPrelooku;
  Float32 localfrac_0[2];
  UInt32 localExt_nEng_AirSys_nEngFilGai;
  UInt32 localbpIndex_0[2];
  UInt16 localTmpSignalConversionAtExt_m;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt8 localTmpSignalConversionAtUsT_i;
  UInt16 localTmpSignalConversionAtAir_c[2];
  UInt16 localTmpSignalConversionAtAir_h[2];
  SInt16 localTmpSignalConversionAtTqLim;
  UInt16 localTmpSignalConversionAtInM_p;
  UInt16 locallocalOutDTConv_h;
  SInt32 localq;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Calcul_consigne_surface'
   *
   * Block requirements for '<S1>/F02_Calcul_consigne_surface':
   *  1. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_104.04 ;
   *  2. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_030.02 ;
   *  3. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_031.02 ;
   *  4. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_033.02 ;
   *  5. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_086.03 ;
   *  6. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_087.01 ;
   *  7. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_085.01 ;
   *  8. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_095.03 ;
   *  9. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_096.01 ;
   *  10. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_112.01 ;
   *  11. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_113.01 ;
   *  12. SubSystem "F02_Calcul_consigne_surface" !Trace_To : VEMS_R_10_07030_119.01 ;
   */

  /* SignalConversion: '<S15>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor(&localTmpSignalConversionAtUsThr);

  /* DataTypeConversion: '<S15>/DTC45' */
  localDTC45_f = ((Float32)localTmpSignalConversionAtUsThr) * 8.0F;

  /* SignalConversion: '<S15>/TmpSignal ConversionAtUsThrM_tSqrtInAirOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tSqrtInAir'
   */
  Rte_Read_R_UsThrM_tSqrtInAir_UsThrM_tSqrtInAir
    (&localTmpSignalConversionAtUsT_i);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirSys_prm_pInMnfReq_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_pInMnfReq_INPUT'
   */
  Rte_Read_R_AirSys_prm_pInMnfReq_AirSys_prm_pInMnfReq
    (&localTmpSignalConversionAtAir_c);

  /* DataTypeConversion: '<S15>/DTC2' */
  AirSysAir_B.DTC2[0] = ((Float32)localTmpSignalConversionAtAir_c[0]) * 8.0F;
  AirSysAir_B.DTC2[1] = ((Float32)localTmpSignalConversionAtAir_c[1]) * 8.0F;

  /* SignalConversion: '<S15>/TmpSignal ConversionAtUsThrM_bAcvAirExtCtlModOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_bAcvAirExtCtlMod'
   */
  Rte_Read_R_UsThrM_bAcvAirExtCtlMod_UsThrM_bAcvAirExtCtlMod
    (&localTmpSignalConversionAtUsT_c);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirSys_rAirPresReqPrevOutport2' */
  AirSys_rAirPresReqPrev =
    Rte_IrvRead_RE_AirSysAir_006_TEV_AirSys_rAirPresReq_irv();

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInM_pDsThrCorOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrCor'
   */
  Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&localTmpSignalConversionAtInM_p);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_m);

  /* Outputs for enable SubSystem: '<S15>/F03_Boolean_inhibition' incorporates:
   *  Constant: '<S15>/AirSys_bAcvFilAr_C'
   *  EnablePort: '<S134>/Enable'
   *  Logic: '<S15>/Logical Operator1'
   *
   * Block description for '<S15>/F03_Boolean_inhibition':
   *  CSMT_CGMT09_0481_2.FR.20.0
   */
  if (!AirSys_bAcvFilAr_C) {
    /* Constant: '<S134>/Cste_1' */
    AirSys_bAcvDmp = FALSE;

    /* Constant: '<S134>/Cste_2' */
    AirSys_bAcvTq = FALSE;
  }

  /* end of Outputs for SubSystem: '<S15>/F03_Boolean_inhibition' */

  /* SignalConversion: '<S15>/TmpSignal ConversionAtDmpVlv_bAcvDmpVlvOutport2' incorporates:
   *  Inport: '<Root>/DmpVlv_bAcvDmpVlv'
   */
  Rte_Read_R_DmpVlv_bAcvDmpVlv_DmpVlv_bAcvDmpVlv
    (&localTmpSignalConversionAtDmp_b);

  /* S-Function (sfun_autosar_clientop): '<S138>/AutosarServer' */
  Rte_Call_R_FRM_bInhDmpVlvCtlThr_GetFunctionPermission(&localAutosarServer_p);

  /* Logic: '<S138>/Not' */
  localNot_n = !localAutosarServer_p;

  /* SignalConversion: '<S15>/TmpSignal ConversionAtCoCha_bTqReqASROutport2' incorporates:
   *  Inport: '<Root>/CoCha_bTqReqASR'
   */
  Rte_Read_R_CoCha_bTqReqASR_CoCha_bTqReqASR(&localTmpSignalConversionAtCoCha);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtTqLimEM_tqIdcLimEMOutport2' incorporates:
   *  Inport: '<Root>/TqLimEM_tqIdcLimEM'
   */
  Rte_Read_R_TqLimEM_tqIdcLimEM_TqLimEM_tqIdcLimEM
    (&localTmpSignalConversionAtTqLim);

  /* Outputs for enable SubSystem: '<S15>/F04_Boolean_request' incorporates:
   *  Constant: '<S15>/AirSys_bAcvFilAr_C'
   *  EnablePort: '<S135>/Enable'
   *
   * Block description for '<S15>/F04_Boolean_request':
   *  CSMT_CGMT09_0481_2.FR.21.0
   */
  if (AirSys_bAcvFilAr_C) {
    /* DataTypeConversion: '<S135>/DTC1' */
    localDTC1_k = ((Float32)localTmpSignalConversionAtTqLim) * 0.0625F;

    /* S-Function (fcncallgen): '<S221>/Function-Call Generator' incorporates:
     *  SubSystem: '<S221>/Subsystem'
     */

    /* Sum: '<S224>/Add1' incorporates:
     *  Constant: '<S135>/AirSys_tiSampleFastThr_C'
     *  DataTypeConversion: '<S135>/DTC4'
     *  Inport: '<S224>/Timer_prev'
     */
    if (AirSys_tiSampleFastThr_C > 2147483647U) {
      localq = MAX_int32_T;
    } else {
      localq = (SInt32)AirSys_tiSampleFastThr_C;
    }

    localq = AirSysAir_B.MinMax - localq;
    if ((AirSysAir_B.MinMax < 0) && (localq >= 0)) {
      localq = MIN_int32_T;
    }

    /* Switch: '<S224>/Switch' incorporates:
     *  Constant: '<S135>/AirSys_tiAcvDlyDmp_C'
     *  DataTypeConversion: '<S135>/DTC2'
     *  Logic: '<S225>/Logical Operator4'
     *  Logic: '<S225>/Logical Operator7'
     *  UnitDelay: '<S225>/Unit Delay1'
     */
    if ((localTmpSignalConversionAtDmp_b) && (!AirSysAir_DWork.UnitDelay1_DSTATE))
    {
      if (AirSys_tiAcvDlyDmp_C > 2147483647U) {
        localq = MAX_int32_T;
      } else {
        localq = (SInt32)AirSys_tiAcvDlyDmp_C;
      }
    }

    /* MinMax: '<S224>/MinMax' incorporates:
     *  Constant: '<S224>/Constant'
     */
    if (0 > localq) {
      localq = 0;
    }

    AirSysAir_B.MinMax = localq;

    /* Update for UnitDelay: '<S225>/Unit Delay1' */
    AirSysAir_DWork.UnitDelay1_DSTATE = localTmpSignalConversionAtDmp_b;

    /* Logic: '<S135>/Logical Operator1' incorporates:
     *  Constant: '<S135>/AirSys_bAcvTqReqASR_C'
     *  Logic: '<S135>/Logical Operator2'
     *  Logic: '<S135>/Logical Operator4'
     *  Logic: '<S135>/Logical Operator5'
     *  Logic: '<S135>/Logical Operator6'
     */
    localLogicalOperator1_f3 = (((AirSys_bAcvTqReqASR_C ||
      (!localTmpSignalConversionAtCoCha)) && (!localNot_n)) &&
      (!localTmpSignalConversionAtUsT_c));

    /* Logic: '<S135>/Logical Operator8' incorporates:
     *  Constant: '<S135>/Cste_1'
     *  Logic: '<S224>/Logical Operator4'
     *  RelationalOperator: '<S135>/Relational Operator1'
     *  RelationalOperator: '<S224>/Relational Operator'
     */
    AirSys_bAcvDmpRaw_MP = ((localTmpSignalConversionAtDmp_b) &&
      (!((AirSysAir_B.MinMax <= 0) && (localTmpSignalConversionAtDmp_b))));

    /* Logic: '<S135>/Logical Operator3' */
    AirSys_bAcvDmp = ((localLogicalOperator1_f3) && AirSys_bAcvDmpRaw_MP);

    /* Lookup_n-D: '<S222>/Lookup Table (n-D)' */
    localLookupTablenD_l = look1_iu16lfts16n4If_binlcns
      (localTmpSignalConversionAtExt_m, (&(AirSys_nEngTq_A[0])),
       (&(AirSys_tqLoThd_T[0])), 7U);

    /* RelationalOperator: '<S223>/Relational Operator1' */
    localRelationalOperator1_n = (localLookupTablenD_l >= localDTC1_k);

    /* RelationalOperator: '<S223>/Relational Operator' incorporates:
     *  Constant: '<S135>/AirSys_tqOfsHiThd_C'
     *  DataTypeConversion: '<S135>/DTC3'
     *  Sum: '<S135>/x2'
     */
    localRelationalOperator_p = (localDTC1_k >= ((((Float32)AirSys_tqOfsHiThd_C)
      * 0.0625F) + localLookupTablenD_l));

    /* UnitDelay: '<S226>/UnitDelay' */
    localUnitDelay_o = AirSysAir_DWork.UnitDelay_o;

    /* CombinatorialLogic: '<S226>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_n != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_p != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_p[0] = AirSysAir_ConstP.pooled17[rowidx];
      localLogic_p[1] = AirSysAir_ConstP.pooled17[rowidx + 8];
    }

    /* Switch: '<S226>/Switch2' incorporates:
     *  Constant: '<S226>/NotCLR3'
     *  UnitDelay: '<S226>/UnitDelay1'
     */
    if (AirSysAir_DWork.UnitDelay_p) {
      AirSys_bAcvTqRaw_MP = localLogic_p[0];
    } else {
      AirSys_bAcvTqRaw_MP = FALSE;
    }

    /* Logic: '<S135>/Logical Operator7' */
    AirSys_bAcvTq = (AirSys_bAcvTqRaw_MP && (localLogicalOperator1_f3));

    /* Update for UnitDelay: '<S226>/UnitDelay' */
    AirSysAir_DWork.UnitDelay_o = AirSys_bAcvTqRaw_MP;

    /* Update for UnitDelay: '<S226>/UnitDelay1' incorporates:
     *  Constant: '<S226>/NotCLR2'
     */
    AirSysAir_DWork.UnitDelay_p = TRUE;
  }

  /* end of Outputs for SubSystem: '<S15>/F04_Boolean_request' */

  /* Outputs for atomic SubSystem: '<S15>/F01_Calcul_obj_flux_surfacique' *
   * Block requirements for '<S15>/F01_Calcul_obj_flux_surfacique':
   *  1. SubSystem "F01_Calcul_obj_flux_surfacique" !Trace_To : VEMS_R_10_07030_034.02 ;
   */

  /* Outputs for atomic SubSystem: '<S132>/F01_Compute_air_pressure_ratio' *
   * Block requirements for '<S132>/F01_Compute_air_pressure_ratio':
   *  1. SubSystem "F01_Compute_air_pressure_ratio" !Trace_To : VEMS_R_10_07030_035.02 ;
   */

  /* If: '<S142>/If' incorporates:
   *  ActionPort: '<S144>/Action Port'
   *  ActionPort: '<S145>/Action Port'
   *  Constant: '<S142>/AirSys_bInhFilRat_C'
   *  SubSystem: '<S142>/F01_No_filtering'
   *  SubSystem: '<S142>/F02_Filtering'
   *
   * Block requirements for '<S142>/F01_No_filtering':
   *  1. SubSystem "F01_No_filtering" !Trace_To : VEMS_R_10_07030_036.01 ;
   *
   * Block requirements for '<S142>/F02_Filtering':
   *  1. SubSystem "F02_Filtering" !Trace_To : VEMS_R_10_07030_037.03 ;
   */
  if (AirSys_bInhFilRat_C) {
    /* Product: '<S148>/Divide' */
    localDTC1_k = AirSysAir_B.DTC2[1] / localDTC45_f;

    /* Outputs for atomic SubSystem: '<S148>/If Action Subsystem3' */

    /* Switch: '<S154>/Switch1' incorporates:
     *  Constant: '<S154>/Constant1'
     *  Constant: '<S154>/Constant2'
     *  Constant: '<S154>/Constant3'
     *  Logic: '<S154>/Logical Operator1'
     *  RelationalOperator: '<S154>/Relational Operator'
     *  RelationalOperator: '<S154>/Relational Operator1'
     *  RelationalOperator: '<S154>/Relational Operator3'
     */
    if (((localDTC1_k != localDTC1_k) || (localDTC1_k > 3.000000005E+038F)) || (
         -3.000000005E+038F > localDTC1_k)) {
      localDTC1_k = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S148>/If Action Subsystem3' */

    /* Switch: '<S152>/Switch' incorporates:
     *  Constant: '<S144>/ConstVal_2'
     *  RelationalOperator: '<S152>/UpperRelop'
     */
    if (localDTC1_k < 0.0F) {
      localLookupTablenD_l = 0.0F;
    } else {
      localLookupTablenD_l = localDTC1_k;
    }

    /* Switch: '<S152>/Switch2' incorporates:
     *  Constant: '<S144>/ConstVal'
     *  RelationalOperator: '<S152>/LowerRelop1'
     */
    if (localDTC1_k > 1.0F) {
      AirSys_rAirPresReqNoFil = 1.0F;
    } else {
      AirSys_rAirPresReqNoFil = localLookupTablenD_l;
    }

    /* SignalConversion: '<S144>/Signal Conversion2' */
    localDTC1_k = AirSys_rAirPresReqNoFil;
  } else {
    /* SignalConversion: '<S145>/Signal Conversion1' */
    AirSys_pInMnfReq_tqEng = AirSysAir_B.DTC2[0];

    /* SignalConversion: '<S145>/Signal Conversion' */
    AirSys_pInMnfReq = AirSysAir_B.DTC2[1];

    /* Outputs for atomic SubSystem: '<S145>/F01_Compute_pressure_ratio' *
     * Block requirements for '<S145>/F01_Compute_pressure_ratio':
     *  1. SubSystem "F01_Compute_pressure_ratio" !Trace_To : VEMS_R_10_07030_038.02 ;
     */

    /* Outputs for atomic SubSystem: '<S155>/F01_Control_conditions' *
     * Block requirements for '<S155>/F01_Control_conditions':
     *  1. SubSystem "F01_Control_conditions" !Trace_To : VEMS_R_10_07030_039.02 ;
     */

    /* DataTypeConversion: '<S159>/Data Type Conversion' incorporates:
     *  Constant: '<S159>/AirSys_pNoiseThd_C'
     */
    localDTC1_k = ((Float32)AirSys_pNoiseThd_C) * 8.0F;

    /* RelationalOperator: '<S159>/Relational Operator5' incorporates:
     *  Sum: '<S159>/Sum1'
     *  UnitDelay: '<S164>/Unit Delay'
     */
    localTmpSignalConversionAtDmp_b = ((AirSys_pInMnfReq_tqEng -
      AirSysAir_DWork.UnitDelay_DSTATE_h) > localDTC1_k);

    /* Sum: '<S159>/Sum5' */
    localDTC1_k = AirSys_pInMnfReq_tqEng - localDTC1_k;

    /* Logic: '<S159>/Logical Operator5' incorporates:
     *  RelationalOperator: '<S159>/Relational Operator3'
     */
    localLogicalOperator5_m = ((localTmpSignalConversionAtDmp_b) ||
      (localDTC45_f < localDTC1_k));

    /* RelationalOperator: '<S159>/Relational Operator4' incorporates:
     *  Constant: '<S159>/AirSys_pNoiseNegThd_C'
     *  DataTypeConversion: '<S159>/Data Type Conversion1'
     *  Sum: '<S159>/Sum6'
     *  UnitDelay: '<S163>/Unit Delay'
     */
    localRelationalOperator4_d = ((AirSysAir_DWork.UnitDelay_DSTATE_f -
      AirSys_pInMnfReq_tqEng) > (((Float32)AirSys_pNoiseNegThd_C) * 8.0F));

    /* UnitDelay: '<S162>/UnitDelay' */
    localUnitDelay1_i = AirSysAir_DWork.UnitDelay_f;

    /* CombinatorialLogic: '<S162>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator5_m != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator4_d != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_i != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_b[0] = AirSysAir_ConstP.pooled17[rowidx];
      localLogic_b[1] = AirSysAir_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S162>/UnitDelay1' */
    localUnitDelay1_i = AirSysAir_DWork.UnitDelay_m;

    /* Switch: '<S162>/Switch2' incorporates:
     *  Constant: '<S162>/NotCLR3'
     */
    if (localUnitDelay1_i) {
      localTmpSignalConversionAtDmp_b = localLogic_b[0];
    } else {
      localTmpSignalConversionAtDmp_b = TRUE;
    }

    /* Switch: '<S159>/Switch1' incorporates:
     *  Constant: '<S159>/AirSys_bAcvDeceThrCtl_C'
     *  Logic: '<S159>/Logical Operator2'
     *  Logic: '<S159>/Logical Operator4'
     *  Logic: '<S162>/LO3'
     *  RelationalOperator: '<S159>/Relational Operator2'
     */
    if (AirSys_bAcvDeceThrCtl_C) {
      AirSys_bInhTrbAirPresRatCtl = ((!localTmpSignalConversionAtDmp_b) ||
        (localTmpSignalConversionAtUsT_c));
    } else {
      AirSys_bInhTrbAirPresRatCtl = ((localDTC45_f < localDTC1_k) ||
        (localTmpSignalConversionAtUsT_c));
    }

    /* Update for UnitDelay: '<S164>/Unit Delay' */
    AirSysAir_DWork.UnitDelay_DSTATE_h = AirSys_pInMnfReq_tqEng;

    /* Update for UnitDelay: '<S163>/Unit Delay' */
    AirSysAir_DWork.UnitDelay_DSTATE_f = AirSys_pInMnfReq_tqEng;

    /* Update for UnitDelay: '<S162>/UnitDelay' */
    AirSysAir_DWork.UnitDelay_f = localTmpSignalConversionAtDmp_b;

    /* Update for UnitDelay: '<S162>/UnitDelay1' incorporates:
     *  Constant: '<S162>/NotCLR2'
     */
    AirSysAir_DWork.UnitDelay_m = TRUE;

    /* end of Outputs for SubSystem: '<S155>/F01_Control_conditions' */

    /* Outputs for atomic SubSystem: '<S155>/F02_Pressure_ratios_calculation' *
     * Block requirements for '<S155>/F02_Pressure_ratios_calculation':
     *  1. SubSystem "F02_Pressure_ratios_calculation" !Trace_To : VEMS_R_10_07030_040.02 ;
     */

    /* Sum: '<S160>/Sum1' incorporates:
     *  Constant: '<S160>/AirSys_pCllThrThd_C'
     *  DataTypeConversion: '<S160>/Data Type Conversion'
     */
    AirSys_pInMnfOplReq = (((Float32)AirSys_pCllThrThd_C) * 8.0F) +
      AirSys_pInMnfReq_tqEng;

    /* Switch: '<S160>/Switch1' */
    if (AirSys_bInhTrbAirPresRatCtl) {
      localDTC1_k = AirSys_pInMnfReq;
    } else {
      localDTC1_k = AirSys_pInMnfOplReq;
    }

    /* Product: '<S166>/Divide' */
    localLookupTablenD_l = localDTC1_k / localDTC45_f;

    /* Outputs for atomic SubSystem: '<S166>/If Action Subsystem3' */

    /* Switch: '<S171>/Switch1' incorporates:
     *  Constant: '<S171>/Constant1'
     *  Constant: '<S171>/Constant2'
     *  Constant: '<S171>/Constant3'
     *  Logic: '<S171>/Logical Operator1'
     *  RelationalOperator: '<S171>/Relational Operator'
     *  RelationalOperator: '<S171>/Relational Operator1'
     *  RelationalOperator: '<S171>/Relational Operator3'
     */
    if (((localLookupTablenD_l != localLookupTablenD_l) || (localLookupTablenD_l
          > 3.000000005E+038F)) || (-3.000000005E+038F > localLookupTablenD_l))
    {
      localLookupTablenD_l = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S166>/If Action Subsystem3' */

    /* Switch: '<S169>/Switch' incorporates:
     *  Constant: '<S160>/ConstVal_2'
     *  RelationalOperator: '<S169>/UpperRelop'
     */
    if (localLookupTablenD_l < 0.0F) {
      localDTC1_k = 0.0F;
    } else {
      localDTC1_k = localLookupTablenD_l;
    }

    /* Switch: '<S169>/Switch2' incorporates:
     *  Constant: '<S160>/ConstVal'
     *  RelationalOperator: '<S169>/LowerRelop1'
     */
    if (localLookupTablenD_l > 1.0F) {
      AirSys_rAirPresRaw = 1.0F;
    } else {
      AirSys_rAirPresRaw = localDTC1_k;
    }

    /* end of Outputs for SubSystem: '<S155>/F02_Pressure_ratios_calculation' */

    /* Outputs for atomic SubSystem: '<S155>/F03_Compute_pressure_ratio' *
     * Block requirements for '<S155>/F03_Compute_pressure_ratio':
     *  1. SubSystem "F03_Compute_pressure_ratio" !Trace_To : VEMS_R_10_07030_041.01 ;
     */

    /* DataTypeConversion: '<S161>/Data Type Conversion2' incorporates:
     *  Constant: '<S161>/AirSys_pCllThrHyst_C'
     */
    localDTC1_k = ((Float32)AirSys_pCllThrHyst_C) * 8.0F;

    /* DataTypeConversion: '<S161>/Data Type Conversion3' incorporates:
     *  Constant: '<S161>/AirSys_rFrzPres_C'
     */
    localLookupTablenD_l = (((Float32)AirSys_rFrzPres_C) * 0.00390625F) +
      0.00390625F;

    /* RelationalOperator: '<S172>/Relational Operator' incorporates:
     *  Constant: '<S161>/AirSys_rFrzHiThd_C'
     *  Constant: '<S161>/ConstVal_2'
     *  DataTypeConversion: '<S161>/Data Type Conversion'
     *  Sum: '<S161>/Sum9'
     */
    localUnitDelay_h = (AirSys_rAirPresRaw >= (1.0F - ((((Float32)
      AirSys_rFrzHiThd_C) * 7.629394531E-006F) - 0.25F)));

    /* RelationalOperator: '<S172>/Relational Operator1' incorporates:
     *  Constant: '<S161>/AirSys_rFrzLoThd_C'
     *  Constant: '<S161>/ConstVal'
     *  DataTypeConversion: '<S161>/Data Type Conversion1'
     *  Sum: '<S161>/Sum8'
     */
    localRelationalOperator1_a = (AirSys_rAirPresRaw <= (1.0F - ((((Float32)
      AirSys_rFrzLoThd_C) * 7.629394531E-006F) - 0.25F)));

    /* UnitDelay: '<S174>/UnitDelay' */
    localUnitDelay1_j = AirSysAir_DWork.UnitDelay_l;

    /* CombinatorialLogic: '<S174>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_h != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_a != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_j != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_ah[0] = AirSysAir_ConstP.pooled17[rowidx];
      localLogic_ah[1] = AirSysAir_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S174>/UnitDelay1' */
    localUnitDelay1_j = AirSysAir_DWork.UnitDelay_j5;

    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S174>/NotCLR3'
     */
    if (localUnitDelay1_j) {
      localTmpSignalConversionAtDmp_b = localLogic_ah[0];
    } else {
      localTmpSignalConversionAtDmp_b = TRUE;
    }

    /* RelationalOperator: '<S173>/Relational Operator' */
    localUnitDelay1_j = (localDTC45_f >= AirSys_pInMnfOplReq);

    /* RelationalOperator: '<S173>/Relational Operator1' incorporates:
     *  Sum: '<S161>/Sum2'
     */
    localRelationalOperator1_a = (localDTC45_f <= (AirSys_pInMnfOplReq -
      localDTC1_k));

    /* UnitDelay: '<S175>/UnitDelay' */
    localUnitDelay_h = AirSysAir_DWork.UnitDelay_h;

    /* CombinatorialLogic: '<S175>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_j != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_a != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_h != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_ah[0] = AirSysAir_ConstP.pooled17[rowidx];
      localLogic_ah[1] = AirSysAir_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S175>/UnitDelay1' */
    localUnitDelay1_j = AirSysAir_DWork.UnitDelay_b;

    /* Switch: '<S175>/Switch2' incorporates:
     *  Constant: '<S175>/NotCLR3'
     */
    if (localUnitDelay1_j) {
      localLogicalOperator1_f3 = localLogic_ah[0];
    } else {
      localLogicalOperator1_f3 = TRUE;
    }

    /* Switch: '<S161>/Switch' */
    if (localTmpSignalConversionAtDmp_b) {
      localDTC1_k = localLookupTablenD_l;
    } else {
      localDTC1_k = AirSys_rAirPresRaw;
    }

    /* Switch: '<S161>/Switch2' */
    if (localLogicalOperator1_f3) {
      localLookupTablenD_l = AirSys_rAirPresRaw;
    }

    /* Switch: '<S161>/Switch3' */
    if (AirSys_bInhTrbAirPresRatCtl) {
      AirSys_rAirPresFinal = localDTC1_k;
    } else {
      AirSys_rAirPresFinal = localLookupTablenD_l;
    }

    /* Update for UnitDelay: '<S174>/UnitDelay' */
    AirSysAir_DWork.UnitDelay_l = localTmpSignalConversionAtDmp_b;

    /* Update for UnitDelay: '<S174>/UnitDelay1' incorporates:
     *  Constant: '<S174>/NotCLR2'
     */
    AirSysAir_DWork.UnitDelay_j5 = TRUE;

    /* Update for UnitDelay: '<S175>/UnitDelay' */
    AirSysAir_DWork.UnitDelay_h = localLogicalOperator1_f3;

    /* Update for UnitDelay: '<S175>/UnitDelay1' incorporates:
     *  Constant: '<S175>/NotCLR2'
     */
    AirSysAir_DWork.UnitDelay_b = TRUE;

    /* end of Outputs for SubSystem: '<S155>/F03_Compute_pressure_ratio' */

    /* end of Outputs for SubSystem: '<S145>/F01_Compute_pressure_ratio' */

    /* Outputs for atomic SubSystem: '<S145>/F02_Compute_filtering_condition' *
     * Block requirements for '<S145>/F02_Compute_filtering_condition':
     *  1. SubSystem "F02_Compute_filtering_condition" !Trace_To : VEMS_R_10_07030_042.02 ;
     */

    /* Sum: '<S156>/Sum6' incorporates:
     *  DataTypeConversion: '<S156>/Data Type Conversion2'
     */
    localDTC1_k = AirSys_rAirPresRaw - ((((Float32)AirSys_rAirPresReqPrev) *
      1.525878906E-005F) + 1.525878906E-005F);

    /* DataTypeConversion: '<S156>/DTC45' incorporates:
     *  Constant: '<S156>/AirSys_rAirPresMaxDif_C'
     */
    localLookupTablenD_l = ((Float32)AirSys_rAirPresMaxDif_C) * 0.00390625F;

    /* RelationalOperator: '<S176>/Relational Operator' incorporates:
     *  Constant: '<S156>/AirSys_pFilInhHiThd_C'
     *  DataTypeConversion: '<S156>/Data Type Conversion1'
     *  Sum: '<S156>/Sum2'
     */
    localRelationalOperator_hg = (localDTC45_f >= ((((Float32)
      AirSys_pFilInhHiThd_C) * 8.0F) + AirSys_pInMnfReq_tqEng));

    /* RelationalOperator: '<S176>/Relational Operator1' incorporates:
     *  Constant: '<S156>/AirSys_pFilInhLoThd_C'
     *  DataTypeConversion: '<S156>/Data Type Conversion'
     *  Sum: '<S156>/Sum1'
     */
    localRelationalOperator1_fs = (localDTC45_f <= ((((Float32)
      AirSys_pFilInhLoThd_C) * 8.0F) + AirSys_pInMnfReq_tqEng));

    /* UnitDelay: '<S177>/UnitDelay' */
    localUnitDelay1_g = AirSysAir_DWork.UnitDelay_j4;

    /* CombinatorialLogic: '<S177>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_hg != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_fs != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_g != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_a[0] = AirSysAir_ConstP.pooled17[rowidx];
      localLogic_a[1] = AirSysAir_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S177>/UnitDelay1' */
    localUnitDelay1_g = AirSysAir_DWork.UnitDelay_c;

    /* Switch: '<S177>/Switch2' incorporates:
     *  Constant: '<S177>/NotCLR3'
     */
    if (localUnitDelay1_g) {
      localTmpSignalConversionAtDmp_b = localLogic_a[0];
    } else {
      localTmpSignalConversionAtDmp_b = TRUE;
    }

    /* Logic: '<S156>/Logical Operator' incorporates:
     *  Abs: '<S156>/Abs1'
     *  Constant: '<S156>/AirSys_bAcvInhCfeFilDmp_C'
     *  Constant: '<S156>/AirSys_bAcvInhCfeFilTq_C'
     *  Logic: '<S156>/Logical Operator1'
     *  Logic: '<S156>/Logical Operator2'
     *  Logic: '<S156>/Logical Operator3'
     *  Logic: '<S156>/Logical Operator4'
     *  RelationalOperator: '<S156>/Relational Operator4'
     */
    AirSys_bInhCfeFil = (((((localTmpSignalConversionAtDmp_b) &&
      (!localTmpSignalConversionAtUsT_c)) || (ACTEMS_FabsF(localDTC1_k) >
      localLookupTablenD_l)) || (AirSys_bAcvInhCfeFilDmp_C && AirSys_bAcvDmp)) ||
                         (AirSys_bAcvInhCfeFilTq_C && AirSys_bAcvTq));

    /* Update for UnitDelay: '<S177>/UnitDelay' */
    AirSysAir_DWork.UnitDelay_j4 = localTmpSignalConversionAtDmp_b;

    /* Update for UnitDelay: '<S177>/UnitDelay1' incorporates:
     *  Constant: '<S177>/NotCLR2'
     */
    AirSysAir_DWork.UnitDelay_c = TRUE;

    /* end of Outputs for SubSystem: '<S145>/F02_Compute_filtering_condition' */

    /* Outputs for atomic SubSystem: '<S145>/F03_Compute_filtering_gain' *
     * Block requirements for '<S145>/F03_Compute_filtering_gain':
     *  1. SubSystem "F03_Compute_filtering_gain" !Trace_To : VEMS_R_10_07030_117.01 ;
     */

    /* Outputs for enable SubSystem: '<S157>/F01_filtering_gain_request' incorporates:
     *  Constant: '<S157>/AirSys_bFilGain_C'
     *  EnablePort: '<S178>/Enable'
     *  EnablePort: '<S179>/Enable'
     *  Logic: '<S157>/Logical Operator3'
     *  SubSystem: '<S157>/F02_filtering_gain_request_&_corrected'
     *
     * Block requirements for '<S157>/F01_filtering_gain_request':
     *  1. SubSystem "F01_filtering_gain_request" !Trace_To : VEMS_R_10_07030_043.02 ;
     *
     * Block requirements for '<S157>/F02_filtering_gain_request_&_corrected':
     *  1. SubSystem "F02_filtering_gain_request_&_corrected" !Trace_To : VEMS_R_10_07030_118.01 ;
     */
    if (AirSys_bFilGain_C) {
      /* Switch: '<S178>/Switch' incorporates:
       *  RelationalOperator: '<S178>/Relational Operator'
       *  UnitDelay: '<S182>/Unit Delay'
       */
      if (AirSys_rAirPresRaw < AirSysAir_DWork.UnitDelay_DSTATE_b) {
        localDTC1_k = AirSys_rAirPresRaw;
      } else {
        localDTC1_k = AirSysAir_DWork.UnitDelay_DSTATE_b;
      }

      /* DataTypeConversion: '<S181>/OutDTConv' incorporates:
       *  Constant: '<S181>/offset'
       *  Constant: '<S181>/offset1'
       *  Constant: '<S181>/one_on_slope'
       *  Product: '<S181>/Product4'
       *  Sum: '<S181>/Add1'
       *  Sum: '<S181>/Add2'
       */
      localDTC1_k = ((localDTC1_k - 1.525878906E-005F) * 65536.0F) + 0.5F;
      if (localDTC1_k < 65536.0F) {
        if (localDTC1_k >= 0.0F) {
          AirSys_rAirPresInter_MP = (UInt16)localDTC1_k;
        } else {
          AirSys_rAirPresInter_MP = 0U;
        }
      } else {
        AirSys_rAirPresInter_MP = MAX_uint16_T;
      }

      /* Lookup_n-D: '<S180>/Lookup Table (n-D)' */
      AirSys_rFilGainPresRat = look1_iu16lfIf_binlcns(AirSys_rAirPresInter_MP, (
        &(AirSys_rAirPresFilGain_A[0])), (&(AirSys_rAirPresFilGain_T[0])), 8U);

      /* Update for UnitDelay: '<S182>/Unit Delay' */
      AirSysAir_DWork.UnitDelay_DSTATE_b = AirSys_rAirPresRaw;
    } else {
      /* PreLookup: '<S183>/Prelookup' */
      localExt_nEng_AirSys_nEngFilGai = plook_u32u16f_binc
        (localTmpSignalConversionAtExt_m, (&(AirSys_nEngFilGainX_A[0])), 9U,
         &localInterpolationUsingPrelooku);

      /* Product: '<S192>/Divide' incorporates:
       *  DataTypeConversion: '<S179>/DTC45'
       */
      localDTC1_k = (((Float32)localTmpSignalConversionAtInM_p) * 8.0F) /
        localDTC45_f;

      /* Outputs for atomic SubSystem: '<S192>/If Action Subsystem3' */

      /* Switch: '<S202>/Switch1' incorporates:
       *  Constant: '<S202>/Constant1'
       *  Constant: '<S202>/Constant2'
       *  Constant: '<S202>/Constant3'
       *  Logic: '<S202>/Logical Operator1'
       *  RelationalOperator: '<S202>/Relational Operator'
       *  RelationalOperator: '<S202>/Relational Operator1'
       *  RelationalOperator: '<S202>/Relational Operator3'
       */
      if (((localDTC1_k != localDTC1_k) || (localDTC1_k > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDTC1_k)) {
        localDTC1_k = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S192>/If Action Subsystem3' */

      /* Switch: '<S200>/Switch' incorporates:
       *  Constant: '<S179>/ConstVal_3'
       *  RelationalOperator: '<S200>/UpperRelop'
       */
      if (localDTC1_k < 0.0F) {
        localAirSys_rAirPresCor_MP_AirS = 0.0F;
      } else {
        localAirSys_rAirPresCor_MP_AirS = localDTC1_k;
      }

      /* Switch: '<S200>/Switch2' incorporates:
       *  Constant: '<S179>/ConstVal_2'
       *  RelationalOperator: '<S200>/LowerRelop1'
       */
      if (localDTC1_k > 1.0F) {
        localAirSys_rAirPresCor_MP_AirS = 1.0F;
      }

      /* Sum: '<S190>/Add1' incorporates:
       *  Constant: '<S190>/offset'
       */
      localDTC1_k = localAirSys_rAirPresCor_MP_AirS - 1.525878906E-005F;

      /* Sum: '<S190>/Add2' incorporates:
       *  Constant: '<S190>/offset1'
       *  Constant: '<S190>/one_on_slope'
       *  Product: '<S190>/Product4'
       */
      localAirSys_rAirPresCor_MP_AirS = (65536.0F * localDTC1_k) + 0.5F;

      /* DataTypeConversion: '<S190>/OutDTConv' */
      localDTC1_k = localAirSys_rAirPresCor_MP_AirS;
      if (localDTC1_k < 65536.0F) {
        if (localDTC1_k >= 0.0F) {
          AirSys_rAirPresCor_MP = (UInt16)localDTC1_k;
        } else {
          AirSys_rAirPresCor_MP = 0U;
        }
      } else {
        AirSys_rAirPresCor_MP = MAX_uint16_T;
      }

      /* PreLookup: '<S184>/Prelookup' */
      localAirSys_rAirPresCor_MP_Ai_m = plook_u32u16f_binc(AirSys_rAirPresCor_MP,
        (&(AirSys_rAirPresCorFilGainY_A[0])), 11U,
        &localAirSys_rAirPresCor_MP_AirS);

      /* Product: '<S193>/Divide' */
      localDTC1_k = AirSys_pInMnfReq_tqEng / localDTC45_f;

      /* Outputs for atomic SubSystem: '<S193>/If Action Subsystem3' */

      /* Switch: '<S204>/Switch1' incorporates:
       *  Constant: '<S204>/Constant1'
       *  Constant: '<S204>/Constant2'
       *  Constant: '<S204>/Constant3'
       *  Logic: '<S204>/Logical Operator1'
       *  RelationalOperator: '<S204>/Relational Operator'
       *  RelationalOperator: '<S204>/Relational Operator1'
       *  RelationalOperator: '<S204>/Relational Operator3'
       */
      if (((localDTC1_k != localDTC1_k) || (localDTC1_k > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDTC1_k)) {
        localDTC1_k = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S193>/If Action Subsystem3' */

      /* Switch: '<S197>/Switch' incorporates:
       *  Constant: '<S179>/ConstVal_1'
       *  RelationalOperator: '<S197>/UpperRelop'
       */
      if (localDTC1_k < 0.0F) {
        localInterpolationUsingPreloo_o = 0.0F;
      } else {
        localInterpolationUsingPreloo_o = localDTC1_k;
      }

      /* Switch: '<S197>/Switch2' incorporates:
       *  Constant: '<S179>/ConstVal'
       *  RelationalOperator: '<S197>/LowerRelop1'
       */
      if (localDTC1_k > 1.0F) {
        localInterpolationUsingPreloo_o = 1.0F;
      }

      /* Sum: '<S191>/Add1' incorporates:
       *  Constant: '<S191>/offset'
       */
      localDTC1_k = localInterpolationUsingPreloo_o - 1.525878906E-005F;

      /* Sum: '<S191>/Add2' incorporates:
       *  Constant: '<S191>/offset1'
       *  Constant: '<S191>/one_on_slope'
       *  Product: '<S191>/Product4'
       */
      localInterpolationUsingPreloo_o = (65536.0F * localDTC1_k) + 0.5F;

      /* DataTypeConversion: '<S191>/OutDTConv' */
      localDTC1_k = localInterpolationUsingPreloo_o;
      if (localDTC1_k < 65536.0F) {
        if (localDTC1_k >= 0.0F) {
          AirSys_rAirPres_MP = (UInt16)localDTC1_k;
        } else {
          AirSys_rAirPres_MP = 0U;
        }
      } else {
        AirSys_rAirPres_MP = MAX_uint16_T;
      }

      /* PreLookup: '<S187>/Prelookup' */
      localAirSys_rAirPres_MP_AirSys_ = plook_u32u16f_binc(AirSys_rAirPres_MP, (
        &(AirSys_rAirPresRawFilGainX_A[0])), 9U,
        &localInterpolationUsingPreloo_o);

      /* Interpolation_n-D: '<S185>/Interpolation Using Prelookup3' */
      localDTC1_k = localInterpolationUsingPreloo_o;
      localfrac[0] = localDTC1_k;
      localDTC1_k = localAirSys_rAirPresCor_MP_AirS;
      localfrac[1] = localDTC1_k;
      localbpIndex[0] = localAirSys_rAirPres_MP_AirSys_;
      localbpIndex[1] = localAirSys_rAirPresCor_MP_Ai_m;
      localInterpolationUsingPreloo_o = intrp2d_iu16n16ff_u32f_l_ns__1(localbpIndex,
        localfrac, (&(AirSys_rAirPresFilGain_M[0])), 10U);

      /* Interpolation_n-D: '<S186>/Interpolation Using Prelookup3' */
      localDTC1_k = localInterpolationUsingPrelooku;
      localfrac_0[0] = localDTC1_k;
      localDTC1_k = localAirSys_rAirPresCor_MP_AirS;
      localfrac_0[1] = localDTC1_k;
      localbpIndex_0[0] = localExt_nEng_AirSys_nEngFilGai;
      localbpIndex_0[1] = localAirSys_rAirPresCor_MP_Ai_m;
      localInterpolationUsingPrelooku = intrp2d_iu16n16ff_u32f_l_ns__1
        (localbpIndex_0, localfrac_0, (&(AirSys_facFilGain_M[0])), 10U);

      /* Product: '<S194>/Divide' */
      AirSys_rFilGainPresRat = localInterpolationUsingPreloo_o *
        localInterpolationUsingPrelooku;
    }

    /* end of Outputs for SubSystem: '<S157>/F01_filtering_gain_request' */

    /* end of Outputs for SubSystem: '<S145>/F03_Compute_filtering_gain' */

    /* Outputs for atomic SubSystem: '<S145>/F04_Compute_filtering_pressure_ratio' *
     * Block requirements for '<S145>/F04_Compute_filtering_pressure_ratio':
     *  1. SubSystem "F04_Compute_filtering_pressure_ratio" !Trace_To : VEMS_R_10_07030_044.02 ;
     */

    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S158>/ConstVal_3'
     */
    if (AirSys_bInhCfeFil) {
      localDTC1_k = 1.0F;
    } else {
      localDTC1_k = AirSys_rFilGainPresRat;
    }

    /* Saturate: '<S209>/Saturation [0-1]' */
    localLookupTablenD_l = rt_SATURATE(localDTC1_k, 0.0F, 1.0F);

    /* UnitDelay: '<S208>/UnitDelay' */
    localDTC1_k = AirSysAir_DWork.UnitDelay_jm;

    /* Switch: '<S208>/Switch' incorporates:
     *  Constant: '<S158>/ConstVal_1'
     *  UnitDelay: '<S208>/UnitDelay1'
     */
    if (!AirSysAir_DWork.UnitDelay_a) {
      localDTC1_k = 1.0F;
    }

    /* Sum: '<S209>/Sum1' incorporates:
     *  Product: '<S209>/Product'
     *  Sum: '<S209>/Sum'
     */
    localDTC1_k += (AirSys_rAirPresFinal - localDTC1_k) * localLookupTablenD_l;

    /* Switch: '<S206>/Switch' incorporates:
     *  Constant: '<S158>/ConstVal_1'
     *  UnitDelay: '<S206>/UnitDelay'
     */
    if (AirSysAir_DWork.UnitDelay_DSTATE_pb) {
      AirSys_rAirPresReqFil = localDTC1_k;
    } else {
      AirSys_rAirPresReqFil = 1.0F;
    }

    /* Update for UnitDelay: '<S208>/UnitDelay' */
    AirSysAir_DWork.UnitDelay_jm = localDTC1_k;

    /* Update for UnitDelay: '<S208>/UnitDelay1' incorporates:
     *  Constant: '<S208>/Constant3'
     */
    AirSysAir_DWork.UnitDelay_a = TRUE;

    /* Update for UnitDelay: '<S206>/UnitDelay' incorporates:
     *  Constant: '<S206>/Constant3'
     */
    AirSysAir_DWork.UnitDelay_DSTATE_pb = TRUE;

    /* end of Outputs for SubSystem: '<S145>/F04_Compute_filtering_pressure_ratio' */

    /* SignalConversion: '<S145>/Signal Conversion2' */
    localDTC1_k = AirSys_rAirPresReqFil;
  }

  /* DataTypeConversion: '<S146>/OutDTConv' incorporates:
   *  Constant: '<S146>/offset'
   *  Constant: '<S146>/offset1'
   *  Constant: '<S146>/one_on_slope'
   *  Product: '<S146>/Product4'
   *  Sum: '<S146>/Add1'
   *  Sum: '<S146>/Add2'
   */
  localDTC1_k = ((localDTC1_k - 1.525878906E-005F) * 65536.0F) + 0.5F;
  if (localDTC1_k < 65536.0F) {
    if (localDTC1_k >= 0.0F) {
      localOutDTConv_kq = (UInt16)localDTC1_k;
    } else {
      localOutDTConv_kq = 0U;
    }
  } else {
    localOutDTConv_kq = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S132>/F01_Compute_air_pressure_ratio' */

  /* Outputs for atomic SubSystem: '<S132>/F02_Compute_surfacic_flowrate_obj' *
   * Block requirements for '<S132>/F02_Compute_surfacic_flowrate_obj':
   *  1. SubSystem "F02_Compute_surfacic_flowrate_obj" !Trace_To : VEMS_R_10_07030_045.01 ;
   */

  /* DataTypeConversion: '<S143>/Data Type Conversion1' */
  localExt_nEng_AirSys_nEngFilGai = (UInt32)(localOutDTConv_kq + 1);
  if (localExt_nEng_AirSys_nEngFilGai > 65535U) {
    localTmpSignalConversionAtUsThr = MAX_uint16_T;
  } else {
    localTmpSignalConversionAtUsThr = (UInt16)localExt_nEng_AirSys_nEngFilGai;
  }

  /* Lookup_n-D: '<S210>/Lookup Table (n-D)' */
  localLookupTablenD_h = look1_iu16lftu32n20If_binlcns
    (localTmpSignalConversionAtUsThr, (&(Air_rAirPres_A[0])),
     (&(AirSys_facCfe_T[0])), 21U);

  /* DataStoreWrite: '<S143>/Data Store Write' incorporates:
   *  Constant: '<S211>/offset'
   *  Constant: '<S211>/offset1'
   *  Constant: '<S211>/one_on_slope'
   *  DataTypeConversion: '<S211>/OutDTConv'
   *  Product: '<S211>/Product4'
   *  Sum: '<S211>/Add1'
   *  Sum: '<S211>/Add2'
   */
  localDTC1_k = (1.048576E+006F * localLookupTablenD_h) + 0.5F;
  if (localDTC1_k < 65536.0F) {
    if (localDTC1_k >= 0.0F) {
      AirSys_facCfe_MP = (UInt16)localDTC1_k;
    } else {
      AirSys_facCfe_MP = 0U;
    }
  } else {
    AirSys_facCfe_MP = MAX_uint16_T;
  }

  /* Product: '<S212>/Divide' incorporates:
   *  DataTypeConversion: '<S15>/DTC1'
   *  Product: '<S213>/Divide'
   */
  localDTC1_k = (localLookupTablenD_h * localDTC45_f) / (((Float32)
    localTmpSignalConversionAtUsT_i) * 0.125F);

  /* Outputs for atomic SubSystem: '<S212>/If Action Subsystem3' */

  /* Switch: '<S215>/Switch1' incorporates:
   *  Constant: '<S215>/Constant1'
   *  Constant: '<S215>/Constant2'
   *  Constant: '<S215>/Constant3'
   *  Logic: '<S215>/Logical Operator1'
   *  RelationalOperator: '<S215>/Relational Operator'
   *  RelationalOperator: '<S215>/Relational Operator1'
   *  RelationalOperator: '<S215>/Relational Operator3'
   */
  if (((localDTC1_k != localDTC1_k) || (localDTC1_k > 3.000000005E+038F)) ||
      (-3.000000005E+038F > localDTC1_k)) {
    AirSys_mfAirThrReq_arThr = 0.0F;
  } else {
    AirSys_mfAirThrReq_arThr = localDTC1_k;
  }

  /* end of Outputs for SubSystem: '<S212>/If Action Subsystem3' */

  /* end of Outputs for SubSystem: '<S132>/F02_Compute_surfacic_flowrate_obj' */

  /* end of Outputs for SubSystem: '<S15>/F01_Calcul_obj_flux_surfacique' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S139>/autosar_testpoint1' */

  /* S-Function Block: <S139>/autosar_testpoint1 */
  AirSys_rAirPresReq_IRV_MP = localOutDTConv_kq;

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirSys_prm_mfAirThrReq_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_mfAirThrReq_INPUT'
   */
  Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq
    (&localTmpSignalConversionAtAir_h);

  /* DataTypeConversion: '<S15>/DTC4' */
  AirSysAir_B.DTC4[0] = ((Float32)localTmpSignalConversionAtAir_h[0]) *
    1.525878906E-005F;
  AirSysAir_B.DTC4[1] = ((Float32)localTmpSignalConversionAtAir_h[1]) *
    1.525878906E-005F;

  /* Outputs for atomic SubSystem: '<S15>/F02_Calcul_de_la_surface_structure_couple' *
   * Block requirements for '<S15>/F02_Calcul_de_la_surface_structure_couple':
   *  1. SubSystem "F02_Calcul_de_la_surface_structure_couple" !Trace_To : VEMS_R_10_07030_046.01 ;
   */

  /* Product: '<S217>/Divide' */
  localDTC1_k = AirSysAir_B.DTC4[1] / AirSys_mfAirThrReq_arThr;

  /* Outputs for atomic SubSystem: '<S217>/If Action Subsystem3' */

  /* Switch: '<S220>/Switch1' incorporates:
   *  Constant: '<S220>/Constant1'
   *  Constant: '<S220>/Constant2'
   *  Constant: '<S220>/Constant3'
   *  Logic: '<S220>/Logical Operator1'
   *  RelationalOperator: '<S220>/Relational Operator'
   *  RelationalOperator: '<S220>/Relational Operator1'
   *  RelationalOperator: '<S220>/Relational Operator3'
   */
  if (((localDTC1_k != localDTC1_k) || (localDTC1_k > 3.000000005E+038F)) ||
      (-3.000000005E+038F > localDTC1_k)) {
    AirSys_arEfcThrReqTqSysRaw = 0.0F;
  } else {
    AirSys_arEfcThrReqTqSysRaw = localDTC1_k;
  }

  /* end of Outputs for SubSystem: '<S217>/If Action Subsystem3' */

  /* DataTypeConversion: '<S216>/OutDTConv' incorporates:
   *  Constant: '<S216>/offset'
   *  Constant: '<S216>/offset1'
   *  Constant: '<S216>/one_on_slope'
   *  Product: '<S216>/Product4'
   *  Sum: '<S216>/Add1'
   *  Sum: '<S216>/Add2'
   */
  localDTC1_k = (1.6777216E+007F * AirSys_arEfcThrReqTqSysRaw) + 0.5F;
  if (localDTC1_k < 65536.0F) {
    if (localDTC1_k >= 0.0F) {
      locallocalOutDTConv_h = (UInt16)localDTC1_k;
    } else {
      locallocalOutDTConv_h = 0U;
    }
  } else {
    locallocalOutDTConv_h = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S15>/F02_Calcul_de_la_surface_structure_couple' */

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirSys_bActStraLimSurgeDmpSwOutport2' */
  localLogicalOperator1_f3 =
    Rte_IrvRead_RE_AirSysAir_006_TEV_AirSys_bActStraLimSurgeDmpSw_irv();

  /* Outputs for enable SubSystem: '<S15>/F05_Raw_area_request' incorporates:
   *  Constant: '<S15>/AirSys_bAcvFilAr_C'
   *  EnablePort: '<S136>/Enable'
   *  EnablePort: '<S137>/Enable'
   *  Logic: '<S15>/Logical Operator2'
   *  SubSystem: '<S15>/F06_Filtering_area_request'
   *
   * Block description for '<S15>/F05_Raw_area_request':
   *  CSMT_CGMT09_0481_2.FR.22.0
   *
   * Block description for '<S15>/F06_Filtering_area_request':
   *  CSMT_CGMT09_0481_2.FR.23.0
   */
  if (!AirSys_bAcvFilAr_C) {
    /* SignalConversion: '<S136>/Signal Conversion' */
    localMerge = locallocalOutDTConv_h;

    /* SignalConversion: '<S136>/Signal Conversion1' */
    AirSysAir_B.Merge1 = localLogicalOperator1_f3;
  } else {
    /* Outputs for atomic SubSystem: '<S137>/F01_Filtering_Throttle'
     * Block description for '<S137>/F01_Filtering_Throttle':
     *  CSMT_CGMT09_0481_2.FR.24.0
     */

    /* MinMax: '<S227>/MinMax' incorporates:
     *  Constant: '<S227>/AirSys_arEfcThrMax_C'
     */
    localTmpSignalConversionAtUsThr = locallocalOutDTConv_h;
    if (AirSys_arEfcThrMax_C < locallocalOutDTConv_h) {
      localTmpSignalConversionAtUsThr = AirSys_arEfcThrMax_C;
    }

    AirSys_arEfcThrReqTqSysSat = localTmpSignalConversionAtUsThr;

    /* Switch: '<S227>/Switch3' incorporates:
     *  Constant: '<S227>/AirSys_bAcvDlyThr_C'
     *  UnitDelay: '<S233>/Unit Delay'
     */
    if (AirSys_bAcvDlyThr_C) {
      localTmpSignalConversionAtUsThr = AirSys_arEfcThrReqTqSysSat;
    } else {
      localTmpSignalConversionAtUsThr = AirSysAir_DWork.UnitDelay_DSTATE_m;
    }

    /* UnitDelay: '<S235>/Unit Delay' */
    localTmpSignalConversionAtInM_p = AirSysAir_DWork.UnitDelay_DSTATE_im;

    /* Switch: '<S227>/Switch2' incorporates:
     *  Constant: '<S227>/AirSys_bAcvDlyThr2_C'
     */
    if (AirSys_bAcvDlyThr2_C) {
      localTmpSignalConversionAtInM_p = localTmpSignalConversionAtUsThr;
    }

    /* DataTypeConversion: '<S227>/DTC1' */
    localDTC45_f = ((Float32)localTmpSignalConversionAtInM_p) *
      5.960464478E-008F;

    /* DataTypeConversion: '<S227>/DTC2' incorporates:
     *  Constant: '<S227>/AirSys_facFilArEfcThr_C'
     */
    localDTC1_k = ((Float32)AirSys_facFilArEfcThr_C) * 1.525878906E-005F;

    /* Saturate: '<S239>/Saturation [0-1]' */
    localLookupTablenD_l = rt_SATURATE(localDTC1_k, 0.0F, 1.0F);

    /* UnitDelay: '<S238>/UnitDelay' */
    localDTC1_k = AirSysAir_DWork.UnitDelay_j;

    /* Switch: '<S238>/Switch' incorporates:
     *  UnitDelay: '<S238>/UnitDelay1'
     */
    if (!AirSysAir_DWork.UnitDelay_d) {
      localDTC1_k = localDTC45_f;
    }

    /* Sum: '<S239>/Sum1' incorporates:
     *  Product: '<S239>/Product'
     *  Sum: '<S239>/Sum'
     */
    localDTC1_k += (localDTC45_f - localDTC1_k) * localLookupTablenD_l;

    /* Switch: '<S236>/Switch' incorporates:
     *  UnitDelay: '<S236>/UnitDelay'
     */
    if (AirSysAir_DWork.UnitDelay_DSTATE_i5) {
      AirSys_arEfcThrReqTqSysFil = localDTC1_k;
    } else {
      AirSys_arEfcThrReqTqSysFil = localDTC45_f;
    }

    /* Update for UnitDelay: '<S233>/Unit Delay' */
    AirSysAir_DWork.UnitDelay_DSTATE_m = AirSys_arEfcThrReqTqSysSat;

    /* Update for UnitDelay: '<S235>/Unit Delay' incorporates:
     *  UnitDelay: '<S234>/Unit Delay'
     */
    AirSysAir_DWork.UnitDelay_DSTATE_im = AirSysAir_DWork.UnitDelay_DSTATE_p;

    /* Update for UnitDelay: '<S238>/UnitDelay' */
    AirSysAir_DWork.UnitDelay_j = localDTC1_k;

    /* Update for UnitDelay: '<S238>/UnitDelay1' incorporates:
     *  Constant: '<S238>/Constant3'
     */
    AirSysAir_DWork.UnitDelay_d = TRUE;

    /* Update for UnitDelay: '<S236>/UnitDelay' incorporates:
     *  Constant: '<S236>/Constant3'
     */
    AirSysAir_DWork.UnitDelay_DSTATE_i5 = TRUE;

    /* Update for UnitDelay: '<S234>/Unit Delay' */
    AirSysAir_DWork.UnitDelay_DSTATE_p = localTmpSignalConversionAtUsThr;

    /* end of Outputs for SubSystem: '<S137>/F01_Filtering_Throttle' */

    /* Outputs for atomic SubSystem: '<S137>/F02_Throttle_area_request_dmp_activation'
     * Block description for '<S137>/F02_Throttle_area_request_dmp_activation':
     *  CSMT_CGMT09_0481_2.FR.25.0
     */

    /* DataTypeConversion: '<S228>/DTC4' */
    localSum2_j = ((Float32)AirSys_arEfcThrReqTqSysSat) * 5.960464478E-008F;

    /* Sum: '<S240>/Sum3' */
    localDTC45_f = AirSys_arEfcThrReqTqSysFil - localSum2_j;

    /* Switch: '<S228>/Switch3' incorporates:
     *  Constant: '<S228>/AirSys_bAcvFilArEfcThr_C'
     */
    if (AirSys_bAcvFilArEfcThr_C) {
      localLookupTablenD_l = AirSys_arEfcThrReqTqSysFil;
    } else {
      localLookupTablenD_l = localSum2_j;
    }

    /* DataTypeConversion: '<S249>/OutDTConv' incorporates:
     *  Constant: '<S249>/offset'
     *  Constant: '<S249>/offset1'
     *  Constant: '<S249>/one_on_slope'
     *  Product: '<S249>/Product4'
     *  Sum: '<S249>/Add1'
     *  Sum: '<S249>/Add2'
     */
    localDTC1_k = (1.6777216E+007F * localLookupTablenD_l) + 0.5F;
    if (localDTC1_k < 65536.0F) {
      if (localDTC1_k >= 0.0F) {
        localTmpSignalConversionAtUsThr = (UInt16)localDTC1_k;
      } else {
        localTmpSignalConversionAtUsThr = 0U;
      }
    } else {
      localTmpSignalConversionAtUsThr = MAX_uint16_T;
    }

    /* Lookup_n-D: '<S247>/Lookup Table (n-D)' */
    AirSys_facArEfcThrFilGain = look2_1fcv2bcvbcvbfbbr6dfbbnx__1
      (localTmpSignalConversionAtExt_m, localTmpSignalConversionAtUsThr,
       (&(AirSys_nEngArFilGainX_A[0])), (&(AirSys_arEfcThrReqTqY_A[0])),
       (&(AirSys_facArEfcThrFil_M[0])), &AirSysAir_ConstP.LookupTablenD_maxIn_j
       [0], 8U);

    /* Logic: '<S228>/Logical Operator4' incorporates:
     *  Constant: '<S228>/Cste_4'
     *  RelationalOperator: '<S228>/Relational Operator3'
     */
    localTmpSignalConversionAtDmp_b = (AirSys_bAcvTq &&
      (AirSys_facArEfcThrFilGain >= 1.0F));

    /* UnitDelay: '<S252>/Unit Delay' */
    localLookupTablenD_l = AirSysAir_DWork.UnitDelay_DSTATE;

    /* DataTypeConversion: '<S228>/DTC2' incorporates:
     *  Constant: '<S228>/AirSys_tiSampleFastThr_C'
     */
    localLookupTablenD_h = ((Float32)AirSys_tiSampleFastThr_C) *
      1.525878906E-005F;

    /* PreLookup: '<S248>/Prelookup' */
    localExt_nEng_AirSys_nEngFilGai = plook_u32u16f_binc
      (localTmpSignalConversionAtExt_m, (&(AirSys_nEngDec_A[0])), 7U,
       &localExt_nEng_AirSys_nEngDec_A_);

    /* If: '<S228>/If1' incorporates:
     *  ActionPort: '<S244>/Action Port'
     *  ActionPort: '<S245>/Action Port'
     *  SubSystem: '<S228>/F02_Else'
     *  SubSystem: '<S228>/F02_IF'
     */
    if (localTmpSignalConversionAtDmp_b) {
      /* Constant: '<S245>/Cste_5' */
      AirSys_facAcvTq = 1.0F;
    } else {
      /* Interpolation_n-D: '<S266>/Interpolation Using Prelookup3' */
      localDTC1_k = localExt_nEng_AirSys_nEngDec_A_;
      localDTC1_k = intrp1d_iu32n16ff_u32f_l_ns(localExt_nEng_AirSys_nEngFilGai,
        localDTC1_k, (&(AirSys_tiTqDec_T[0])));

      /* Product: '<S267>/Divide' incorporates:
       *  Sum: '<S244>/Sum4'
       */
      localDTC1_k = localLookupTablenD_h / (localLookupTablenD_h + localDTC1_k);

      /* Outputs for atomic SubSystem: '<S267>/If Action Subsystem3' */

      /* Switch: '<S269>/Switch1' incorporates:
       *  Constant: '<S269>/Constant1'
       *  Constant: '<S269>/Constant2'
       *  Constant: '<S269>/Constant3'
       *  Logic: '<S269>/Logical Operator1'
       *  RelationalOperator: '<S269>/Relational Operator'
       *  RelationalOperator: '<S269>/Relational Operator1'
       *  RelationalOperator: '<S269>/Relational Operator3'
       */
      if (((localDTC1_k != localDTC1_k) || (localDTC1_k > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDTC1_k)) {
        localDTC1_k = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S267>/If Action Subsystem3' */

      /* Sum: '<S244>/Sum3' */
      localDTC1_k = localLookupTablenD_l - localDTC1_k;

      /* MinMax: '<S244>/MinMax1' incorporates:
       *  Constant: '<S244>/Cste_7'
       */
      AirSys_facAcvTq = rt_MAXf(localDTC1_k, 0.0F);
    }

    /* Switch: '<S257>/Switch' incorporates:
     *  RelationalOperator: '<S257>/UpperRelop'
     */
    if (AirSys_facAcvTq < 0.0F) {
      localLookupTablenD_l = 0.0F;
    } else {
      localLookupTablenD_l = AirSys_facAcvTq;
    }

    /* Switch: '<S257>/Switch2' incorporates:
     *  RelationalOperator: '<S257>/LowerRelop1'
     */
    if (AirSys_facAcvTq > 1.0F) {
      localLookupTablenD_l = 1.0F;
    }

    /* Sum: '<S240>/Sum2' incorporates:
     *  Product: '<S240>/Divide'
     */
    localSum2_j += localDTC45_f * localLookupTablenD_l;

    /* DataStoreWrite: '<S228>/Data Store Write' incorporates:
     *  Constant: '<S250>/offset'
     *  Constant: '<S250>/offset1'
     *  Constant: '<S250>/one_on_slope'
     *  DataTypeConversion: '<S250>/OutDTConv'
     *  Product: '<S250>/Product4'
     *  Sum: '<S250>/Add1'
     *  Sum: '<S250>/Add2'
     */
    localDTC1_k = (1.6777216E+007F * localSum2_j) + 0.5F;
    if (localDTC1_k < 65536.0F) {
      if (localDTC1_k >= 0.0F) {
        AirSys_arEfcThrReqDmpSys_MP = (UInt16)localDTC1_k;
      } else {
        AirSys_arEfcThrReqDmpSys_MP = 0U;
      }
    } else {
      AirSys_arEfcThrReqDmpSys_MP = MAX_uint16_T;
    }

    /* Sum: '<S241>/Sum3' incorporates:
     *  Constant: '<S228>/Cste_1'
     */
    localDTC45_f = AirSys_facArEfcThrFilGain - 1.0F;

    /* UnitDelay: '<S253>/Unit Delay' */
    localLookupTablenD_l = AirSysAir_DWork.UnitDelay_DSTATE_e;

    /* If: '<S228>/If' incorporates:
     *  ActionPort: '<S242>/Action Port'
     *  ActionPort: '<S243>/Action Port'
     *  SubSystem: '<S228>/F01_Else'
     *  SubSystem: '<S228>/F01_IF'
     */
    if (AirSys_bAcvDmp) {
      /* Constant: '<S243>/Cste_3' */
      AirSys_facAcvDmp = 1.0F;
    } else {
      /* Interpolation_n-D: '<S262>/Interpolation Using Prelookup3' */
      localDTC1_k = localExt_nEng_AirSys_nEngDec_A_;
      localDTC1_k = intrp1d_iu32n16ff_u32f_l_ns(localExt_nEng_AirSys_nEngFilGai,
        localDTC1_k, (&(AirSys_tiDmpDec_T[0])));

      /* Product: '<S263>/Divide' incorporates:
       *  Sum: '<S242>/Sum2'
       */
      localDTC1_k = localLookupTablenD_h / (localLookupTablenD_h + localDTC1_k);

      /* Outputs for atomic SubSystem: '<S263>/If Action Subsystem3' */

      /* Switch: '<S265>/Switch1' incorporates:
       *  Constant: '<S265>/Constant1'
       *  Constant: '<S265>/Constant2'
       *  Constant: '<S265>/Constant3'
       *  Logic: '<S265>/Logical Operator1'
       *  RelationalOperator: '<S265>/Relational Operator'
       *  RelationalOperator: '<S265>/Relational Operator1'
       *  RelationalOperator: '<S265>/Relational Operator3'
       */
      if (((localDTC1_k != localDTC1_k) || (localDTC1_k > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localDTC1_k)) {
        localDTC1_k = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S263>/If Action Subsystem3' */

      /* Sum: '<S242>/Sum1' */
      localDTC1_k = localLookupTablenD_l - localDTC1_k;

      /* MinMax: '<S242>/MinMax' incorporates:
       *  Constant: '<S242>/Cste_6'
       */
      AirSys_facAcvDmp = rt_MAXf(localDTC1_k, 0.0F);
    }

    /* Switch: '<S261>/Switch' incorporates:
     *  RelationalOperator: '<S261>/UpperRelop'
     */
    if (AirSys_facAcvDmp < 0.0F) {
      localLookupTablenD_l = 0.0F;
    } else {
      localLookupTablenD_l = AirSys_facAcvDmp;
    }

    /* Switch: '<S261>/Switch2' incorporates:
     *  RelationalOperator: '<S261>/LowerRelop1'
     */
    if (AirSys_facAcvDmp > 1.0F) {
      localLookupTablenD_l = 1.0F;
    }

    /* Sum: '<S241>/Sum2' incorporates:
     *  Constant: '<S228>/Cste_1'
     *  Product: '<S241>/Divide'
     */
    localLookupTablenD_l = (localDTC45_f * localLookupTablenD_l) + 1.0F;

    /* DataStoreWrite: '<S228>/Data Store Write1' incorporates:
     *  Constant: '<S251>/offset'
     *  Constant: '<S251>/offset1'
     *  Constant: '<S251>/one_on_slope'
     *  DataTypeConversion: '<S251>/OutDTConv'
     *  Product: '<S251>/Product4'
     *  Sum: '<S251>/Add1'
     *  Sum: '<S251>/Add2'
     */
    localDTC1_k = ((localLookupTablenD_l - 1.525878906E-005F) * 65536.0F) + 0.5F;
    if (localDTC1_k < 65536.0F) {
      if (localDTC1_k >= 0.0F) {
        AirSys_facArEfcThrFilGain_MP = (UInt16)localDTC1_k;
      } else {
        AirSys_facArEfcThrFilGain_MP = 0U;
      }
    } else {
      AirSys_facArEfcThrFilGain_MP = MAX_uint16_T;
    }

    /* UnitDelay: '<S272>/UnitDelay' */
    localDTC1_k = AirSysAir_DWork.UnitDelay;

    /* Switch: '<S272>/Switch' incorporates:
     *  UnitDelay: '<S272>/UnitDelay1'
     */
    if (!AirSysAir_DWork.UnitDelay_e) {
      localDTC1_k = localSum2_j;
    }

    /* Sum: '<S273>/Sum1' incorporates:
     *  Product: '<S273>/Product'
     *  Saturate: '<S273>/Saturation [0-1]'
     *  Sum: '<S273>/Sum'
     */
    localDTC1_k += (localSum2_j - localDTC1_k) * rt_SATURATE
      (localLookupTablenD_l, 0.0F, 1.0F);

    /* Switch: '<S270>/Switch' incorporates:
     *  UnitDelay: '<S270>/UnitDelay'
     */
    if (AirSysAir_DWork.UnitDelay_DSTATE_pe) {
      AirSys_arEfcThrReqDmpSysFil = localDTC1_k;
    } else {
      AirSys_arEfcThrReqDmpSysFil = localSum2_j;
    }

    /* Update for UnitDelay: '<S252>/Unit Delay' */
    AirSysAir_DWork.UnitDelay_DSTATE = AirSys_facAcvTq;

    /* Update for UnitDelay: '<S253>/Unit Delay' */
    AirSysAir_DWork.UnitDelay_DSTATE_e = AirSys_facAcvDmp;

    /* Update for UnitDelay: '<S272>/UnitDelay' */
    AirSysAir_DWork.UnitDelay = localDTC1_k;

    /* Update for UnitDelay: '<S272>/UnitDelay1' incorporates:
     *  Constant: '<S272>/Constant3'
     */
    AirSysAir_DWork.UnitDelay_e = TRUE;

    /* Update for UnitDelay: '<S270>/UnitDelay' incorporates:
     *  Constant: '<S270>/Constant3'
     */
    AirSysAir_DWork.UnitDelay_DSTATE_pe = TRUE;

    /* end of Outputs for SubSystem: '<S137>/F02_Throttle_area_request_dmp_activation' */

    /* Outputs for atomic SubSystem: '<S137>/F03_Default_configuration'
     * Block description for '<S137>/F03_Default_configuration':
     *  CSMT_CGMT09_0481_2.FR.27.0
     */

    /* Switch: '<S229>/Switch1' incorporates:
     *  DataTypeConversion: '<S229>/DTC1'
     *  Logic: '<S229>/Logical Operator6'
     */
    if ((localNot_n) || (localTmpSignalConversionAtCoCha)) {
      localDTC1_k = ((Float32)locallocalOutDTConv_h) * 5.960464478E-008F;
    } else {
      localDTC1_k = AirSys_arEfcThrReqDmpSysFil;
    }

    /* end of Outputs for SubSystem: '<S137>/F03_Default_configuration' */

    /* Outputs for atomic SubSystem: '<S137>/F04_Torque_structure_enable_request'
     * Block description for '<S137>/F04_Torque_structure_enable_request':
     *  CSMT_CGMT09_0481_2.FR.26.0
     */

    /* RelationalOperator: '<S230>/Relational Operator1' incorporates:
     *  Constant: '<S230>/Cste_1'
     */
    localTmpSignalConversionAtDmp_b = (AirSys_facAcvDmp > 0.0F);

    /* Switch: '<S230>/Switch1' incorporates:
     *  Constant: '<S230>/AirSys_bAcvStraTqReq_C'
     *  Constant: '<S230>/Cste_2'
     *  Constant: '<S230>/Cste_3'
     *  Logic: '<S230>/Logical Operator4'
     *  Logic: '<S230>/Logical Operator5'
     *  RelationalOperator: '<S230>/Relational Operator2'
     *  RelationalOperator: '<S230>/Relational Operator3'
     */
    if (!AirSys_bAcvStraTqReq_C) {
      localTmpSignalConversionAtDmp_b = (((localTmpSignalConversionAtDmp_b) &&
        (AirSys_facArEfcThrFilGain < 1.0F)) || (AirSys_facAcvTq > 0.0F));
    }

    /* Logic: '<S230>/Logical Operator6' incorporates:
     *  Constant: '<S230>/AirSys_bAcvTqReq_C'
     *  Logic: '<S230>/Logical Operator1'
     *  Logic: '<S230>/Logical Operator2'
     *  Logic: '<S230>/Logical Operator3'
     */
    AirSysAir_B.Merge1 = ((((!((localNot_n) || (localTmpSignalConversionAtCoCha)))
      && (localTmpSignalConversionAtDmp_b)) && AirSys_bAcvTqReq_C) ||
                          (localLogicalOperator1_f3));

    /* end of Outputs for SubSystem: '<S137>/F04_Torque_structure_enable_request' */

    /* DataTypeConversion: '<S231>/OutDTConv' incorporates:
     *  Constant: '<S231>/offset'
     *  Constant: '<S231>/offset1'
     *  Constant: '<S231>/one_on_slope'
     *  Product: '<S231>/Product4'
     *  Sum: '<S231>/Add1'
     *  Sum: '<S231>/Add2'
     */
    localDTC1_k = (1.6777216E+007F * localDTC1_k) + 0.5F;
    if (localDTC1_k < 65536.0F) {
      if (localDTC1_k >= 0.0F) {
        localMerge = (UInt16)localDTC1_k;
      } else {
        localMerge = 0U;
      }
    } else {
      localMerge = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S15>/F05_Raw_area_request' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S140>/autosar_testpoint1' */

  /* S-Function Block: <S140>/autosar_testpoint1 */
  AirSys_arEfcThrReqTqSys_IRV_MP = localMerge;

  /* SignalConversion: '<S15>/Signal Conversion1' */
  localTmpSignalConversionAtUsThr = localOutDTConv_kq;

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirSys_arEfcThrReqTqSys_irvInport2' incorporates:
   *  SignalConversion: '<S15>/Signal Conversion'
   */
  Rte_IrvWrite_RE_AirSysAir_006_TEV_AirSys_arEfcThrReqTqSys_irv(localMerge);

  /* Switch: '<S141>/Switch' incorporates:
   *  Constant: '<S141>/Byp_Fonction_SC'
   *  Constant: '<S141>/Int_BypC'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localTmpSignalConversionAtDmp_b = AirSys_bActStraLimSurge_B;
  } else {
    localTmpSignalConversionAtDmp_b = AirSysAir_B.Merge1;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirSys_bActStraLimSurgeInport2' */
  Rte_Write_P_AirSys_bActStraLimSurge_AirSys_bActStraLimSurge
    (localTmpSignalConversionAtDmp_b);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirSys_rAirPresReq_irvInport2' */
  Rte_IrvWrite_RE_AirSysAir_006_TEV_AirSys_rAirPresReq_irv
    (localTmpSignalConversionAtUsThr);
}

/* Start for exported function: RE_AirSysAir_007_TEV */
void RE_AirSysAir_007_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_ThrArCoorn'
   *
   * Block requirements for '<S1>/F01_ThrArCoorn':
   *  1. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_105.02 ;
   *  2. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_106.01 ;
   *  3. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_107.01 ;
   *  4. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_108.01 ;
   *  5. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_096.01 ;
   *  6. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_062.01 ;
   *  7. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_088.01 ;
   *  8. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_090.03 ;
   *  9. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_089.01 ;
   *  10. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_098.01 ;
   */
}

/* Output and update for exported function: RE_AirSysAir_007_TEV */
void RE_AirSysAir_007_TEV(void)
{
  /* local block i/o variables */
  Boolean localAutosarServer_d;
  Float32 localDTC1_j;
  Float32 localSwitch4;
  UInt8 localTmpSignalConversionAtCrkMg;
  Float32 localSwitch3_j;
  Float32 localAdd2_mh;
  UInt32 localTmpSignalConversionAtAir_g;
  UInt16 localTmpSignalConversionAtAir_d;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_ThrArCoorn'
   *
   * Block requirements for '<S1>/F01_ThrArCoorn':
   *  1. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_105.02 ;
   *  2. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_106.01 ;
   *  3. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_107.01 ;
   *  4. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_108.01 ;
   *  5. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_096.01 ;
   *  6. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_062.01 ;
   *  7. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_088.01 ;
   *  8. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_090.03 ;
   *  9. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_089.01 ;
   *  10. SubSystem "F01_ThrArCoorn" !Trace_To : VEMS_R_10_07030_098.01 ;
   */

  /* DataTypeConversion: '<S13>/DTC1' incorporates:
   *  SignalConversion: '<S13>/TmpSignal ConversionAtAirSys_arEfcThrReqTqSysOutport2'
   */
  localDTC1_j = ((Float32)
                 Rte_IrvRead_RE_AirSysAir_007_TEV_AirSys_arEfcThrReqTqSys_irv())
    * 5.960464478E-008F;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAirSys_arEfcThrReqWoutTqSysOutport2' incorporates:
   *  Inport: '<Root>/AirSys_arEfcThrReqWoutTqSys'
   */
  Rte_Read_R_AirSys_arEfcThrReqWoutTqSys_AirSys_arEfcThrReqWoutTqSys
    (&localTmpSignalConversionAtAir_g);

  /* DataTypeConversion: '<S13>/DTC45' */
  localSwitch4 = ((Float32)localTmpSignalConversionAtAir_g) * 5.960464478E-008F;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtCrkMgt_stThr_arThrEffOutport2' incorporates:
   *  Inport: '<Root>/CrkMgt_stThr_arThrEff'
   */
  Rte_Read_R_CrkMgt_stThr_arThrEff_CrkMgt_stThr_arThrEff
    (&localTmpSignalConversionAtCrkMg);

  /* Logic: '<S13>/Logical Operator1' incorporates:
   *  Constant: '<S13>/AirSys_bArMaxInh_C'
   *  Constant: '<S13>/CrkMgt_stCllTq_SC'
   *  Constant: '<S13>/CrkMgt_stOplTq_SC'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S13>/Logical Operator2'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  RelationalOperator: '<S13>/Relational Operator2'
   */
  AirSys_bThrEff_MP = (((CrkMgt_stOplTq_SC == localTmpSignalConversionAtCrkMg) ||
                        (localTmpSignalConversionAtCrkMg == CrkMgt_stCllTq_SC)) &&
                       (!AirSys_bArMaxInh_C));

  /* Switch: '<S13>/Switch3' incorporates:
   *  MinMax: '<S13>/MinMax1'
   */
  if (AirSys_bThrEff_MP) {
    localSwitch3_j = rt_MAXf(localDTC1_j, localSwitch4);
  } else {
    localSwitch3_j = localSwitch4;
  }

  /* DataStoreWrite: '<S13>/Data Store Write' incorporates:
   *  Constant: '<S80>/offset'
   *  Constant: '<S80>/offset1'
   *  Constant: '<S80>/one_on_slope'
   *  DataTypeConversion: '<S80>/OutDTConv'
   *  Product: '<S80>/Product4'
   *  Sum: '<S80>/Add1'
   *  Sum: '<S80>/Add2'
   */
  localAdd2_mh = (1.6777216E+007F * localSwitch3_j) + 0.5F;
  if (localAdd2_mh < 65536.0F) {
    AirSys_arEfcThrTq_MP = (UInt16)localAdd2_mh;
  } else {
    AirSys_arEfcThrTq_MP = MAX_uint16_T;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAirSys_facTranAirOutport2' incorporates:
   *  Inport: '<Root>/AirSys_facTranAir'
   */
  Rte_Read_R_AirSys_facTranAir_AirSys_facTranAir
    (&localTmpSignalConversionAtAir_d);

  /* DataTypeConversion: '<S13>/DTC3' */
  localAdd2_mh = ((Float32)localTmpSignalConversionAtAir_d) * 0.00390625F;

  /* S-Function (sfun_autosar_clientop): '<S78>/AutosarServer' */
  Rte_Call_R_FRM_bAcvAirThrArSpByp_GetFunctionPermission(&localAutosarServer_d);

  /* Switch: '<S13>/Switch4' incorporates:
   *  Constant: '<S13>/ConstVal'
   *  Logic: '<S13>/Logical Operator3'
   *  Logic: '<S78>/Not'
   *  Product: '<S82>/Divide'
   *  Product: '<S83>/Divide'
   *  Sum: '<S13>/Sum5'
   *  Sum: '<S13>/Sum7'
   */
  if (!(!localAutosarServer_d)) {
    localSwitch4 = ((1.0F - localAdd2_mh) * localDTC1_j) + (localAdd2_mh *
      localSwitch3_j);
  }

  /* Switch: '<S81>/Switch' incorporates:
   *  Constant: '<S79>/offset'
   *  Constant: '<S79>/offset1'
   *  Constant: '<S79>/one_on_slope'
   *  Constant: '<S81>/Byp_Fonction_SC'
   *  Constant: '<S81>/Int_BypC'
   *  DataTypeConversion: '<S79>/OutDTConv'
   *  Product: '<S79>/Product4'
   *  Sum: '<S79>/Add1'
   *  Sum: '<S79>/Add2'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAir_d = AirSys_arThrReq_B;
  } else {
    localAdd2_mh = (1.6777216E+007F * localSwitch4) + 0.5F;
    if (localAdd2_mh < 65536.0F) {
      if (localAdd2_mh >= 0.0F) {
        localTmpSignalConversionAtAir_d = (UInt16)localAdd2_mh;
      } else {
        localTmpSignalConversionAtAir_d = 0U;
      }
    } else {
      localTmpSignalConversionAtAir_d = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAirSys_arThrReqInport2' */
  Rte_Write_P_AirSys_arThrReq_AirSys_arThrReq(localTmpSignalConversionAtAir_d);
}

/* Output and update for exported function: RE_AirSysAir_005_TEV */
void RE_AirSysAir_005_TEV(void)
{
  Float32 localDTC2_eg;
  Float32 localDTC45_m;
  Float32 localDTC5_d;
  Float32 localDTC8;
  Float32 localDTC9;
  UInt8 localTmpSignalConversionAtEng_k;
  UInt16 localTmpSignalConversionAtEng_f;
  UInt16 localTmpSignalConversionAtEng_b;
  UInt16 localTmpSignalConversionAtEng_m;
  UInt16 localTmpSignalConversionAtEng_n;
  UInt16 localTmpSignalConversionAtEn_fn;
  UInt16 localSwitch_l[2];
  Float32 locallocalDivide_bz_idx;
  Float32 locallocalDivide_bz_idx_0;

  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_AirMnfldPSp'
   *
   * Block requirements for '<S1>/F01_AirMnfldPSp':
   *  1. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_103.02 ;
   *  2. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_026.01 ;
   *  3. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_027.01 ;
   *  4. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_074.01 ;
   *  5. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_110.02 ;
   *  6. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_078.02 ;
   *  7. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_079.01 ;
   *  8. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_081.02 ;
   *  9. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_080.01 ;
   *  10. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_082.02 ;
   *  11. SubSystem "F01_AirMnfldPSp" !Trace_To : VEMS_R_10_07030_077.01 ;
   */

  /* DataTypeConversion: '<S12>/DTC2' incorporates:
   *  Constant: '<S12>/Eng_mRef_C'
   */
  localDTC2_eg = ((Float32)Eng_mRef_C) * 1.192016583E-007F;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facACorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facACor'
   */
  Rte_Read_R_EngM_facACor_EngM_facACor(&localTmpSignalConversionAtEng_k);

  /* DataTypeConversion: '<S12>/DTC45' */
  localDTC45_m = (((Float32)localTmpSignalConversionAtEng_k) * 0.00390625F) +
    0.5F;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rMassAirResiCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rMassAirResiCor'
   */
  Rte_Read_R_EngM_rMassAirResiCor_EngM_rMassAirResiCor
    (&localTmpSignalConversionAtEng_f);

  /* DataTypeConversion: '<S12>/DTC5' */
  localDTC5_d = ((Float32)localTmpSignalConversionAtEng_f) * 6.103515625E-005F;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facOfsEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facOfsEfcCor'
   */
  Rte_Read_R_EngM_facOfsEfcCor_EngM_facOfsEfcCor
    (&localTmpSignalConversionAtEng_b);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facOfsEfcReqOutport2' incorporates:
   *  Inport: '<Root>/EngM_facOfsEfcReq'
   */
  Rte_Read_R_EngM_facOfsEfcReq_EngM_facOfsEfcReq
    (&localTmpSignalConversionAtEng_m);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/AirSys_bSelClcMod_pDsThrReq_C'
   */
  if (AirSys_bSelClcMod_pDsThrReq_C) {
    localTmpSignalConversionAtEng_m = localTmpSignalConversionAtEng_b;
  }

  /* DataTypeConversion: '<S12>/DTC8' */
  localDTC8 = ((Float32)localTmpSignalConversionAtEng_m) * 6.103515625E-005F;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facSlopEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facSlopEfcCor'
   */
  Rte_Read_R_EngM_facSlopEfcCor_EngM_facSlopEfcCor
    (&localTmpSignalConversionAtEng_n);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facSlopEfcReqOutport2' incorporates:
   *  Inport: '<Root>/EngM_facSlopEfcReq'
   */
  Rte_Read_R_EngM_facSlopEfcReq_EngM_facSlopEfcReq
    (&localTmpSignalConversionAtEn_fn);

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/AirSys_bSelClcMod_pDsThrReq_C_2'
   */
  if (AirSys_bSelClcMod_pDsThrReq_C) {
    localTmpSignalConversionAtEng_m = localTmpSignalConversionAtEng_n;
  } else {
    localTmpSignalConversionAtEng_m = localTmpSignalConversionAtEn_fn;
  }

  /* DataTypeConversion: '<S12>/DTC9' */
  localDTC9 = ((Float32)localTmpSignalConversionAtEng_m) * 3.356933620E-010F;

  /* Product: '<S70>/Divide' incorporates:
   *  DataTypeConversion: '<S12>/DTC1'
   *  SignalConversion: '<S12>/TmpSignal ConversionAtAirSys_prm_mAirCylReq1_irvOutport2'
   *  SignalConversion: '<S12>/TmpSignal ConversionAtAirSys_prm_mAirCylReq2_irvOutport2'
   */
  locallocalDivide_bz_idx = (((Float32)
    Rte_IrvRead_RE_AirSysAir_005_TEV_AirSys_prm_mAirCylReq_01_irv()) *
    1.192016583E-007F) / localDTC2_eg;
  locallocalDivide_bz_idx_0 = (((Float32)
    Rte_IrvRead_RE_AirSysAir_005_TEV_AirSys_prm_mAirCylReq_02_irv()) *
    1.192016583E-007F) / localDTC2_eg;

  /* Product: '<S69>/Divide' incorporates:
   *  Constant: '<S77>/Constant1'
   *  Constant: '<S77>/Constant2'
   *  Constant: '<S77>/Constant3'
   *  Logic: '<S77>/Logical Operator1'
   *  RelationalOperator: '<S77>/Relational Operator'
   *  RelationalOperator: '<S77>/Relational Operator1'
   *  RelationalOperator: '<S77>/Relational Operator3'
   *  Sum: '<S12>/Sum1'
   *  Switch: '<S77>/Switch1'
   */
  if (((locallocalDivide_bz_idx != locallocalDivide_bz_idx) ||
       (locallocalDivide_bz_idx > 3.000000005E+038F)) || (-3.000000005E+038F >
       locallocalDivide_bz_idx)) {
    locallocalDivide_bz_idx = 0.0F;
  }

  locallocalDivide_bz_idx = (locallocalDivide_bz_idx - localDTC5_d) /
    localDTC45_m;
  if (((locallocalDivide_bz_idx_0 != locallocalDivide_bz_idx_0) ||
       (locallocalDivide_bz_idx_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
       locallocalDivide_bz_idx_0)) {
    locallocalDivide_bz_idx_0 = 0.0F;
  }

  localDTC2_eg = (locallocalDivide_bz_idx_0 - localDTC5_d) / localDTC45_m;

  /* Product: '<S68>/Divide' incorporates:
   *  Constant: '<S75>/Constant1'
   *  Constant: '<S75>/Constant2'
   *  Constant: '<S75>/Constant3'
   *  Logic: '<S75>/Logical Operator1'
   *  RelationalOperator: '<S75>/Relational Operator'
   *  RelationalOperator: '<S75>/Relational Operator1'
   *  RelationalOperator: '<S75>/Relational Operator3'
   *  Sum: '<S12>/Sum'
   *  Switch: '<S75>/Switch1'
   */
  if (((locallocalDivide_bz_idx != locallocalDivide_bz_idx) ||
       (locallocalDivide_bz_idx > 3.000000005E+038F)) || (-3.000000005E+038F >
       locallocalDivide_bz_idx)) {
    locallocalDivide_bz_idx = 0.0F;
  }

  locallocalDivide_bz_idx = (locallocalDivide_bz_idx + localDTC8) / localDTC9;
  if (((localDTC2_eg != localDTC2_eg) || (localDTC2_eg > 3.000000005E+038F)) ||
      (-3.000000005E+038F > localDTC2_eg)) {
    localDTC2_eg = 0.0F;
  }

  locallocalDivide_bz_idx_0 = (localDTC2_eg + localDTC8) / localDTC9;

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S67>/offset'
   *  Constant: '<S67>/offset1'
   *  Constant: '<S67>/one_on_slope'
   *  Constant: '<S71>/Byp_Fonction_SC'
   *  Constant: '<S71>/Int_BypC'
   *  Constant: '<S73>/Constant1'
   *  Constant: '<S73>/Constant2'
   *  Constant: '<S73>/Constant3'
   *  DataTypeConversion: '<S67>/OutDTConv'
   *  Logic: '<S73>/Logical Operator1'
   *  Product: '<S67>/Product4'
   *  RelationalOperator: '<S73>/Relational Operator'
   *  RelationalOperator: '<S73>/Relational Operator1'
   *  RelationalOperator: '<S73>/Relational Operator3'
   *  Sum: '<S67>/Add1'
   *  Sum: '<S67>/Add2'
   *  Switch: '<S73>/Switch1'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localSwitch_l[0] = AirSys_prm_pInMnfReq_B[0];
    localSwitch_l[1] = AirSys_prm_pInMnfReq_B[1];
  } else {
    if (((locallocalDivide_bz_idx != locallocalDivide_bz_idx) ||
         (locallocalDivide_bz_idx > 3.000000005E+038F)) || (-3.000000005E+038F >
         locallocalDivide_bz_idx)) {
      locallocalDivide_bz_idx = 0.0F;
    }

    localDTC2_eg = (0.125F * locallocalDivide_bz_idx) + 0.5F;
    if (localDTC2_eg < 65536.0F) {
      if (localDTC2_eg >= 0.0F) {
        localTmpSignalConversionAtEng_f = (UInt16)localDTC2_eg;
      } else {
        localTmpSignalConversionAtEng_f = 0U;
      }
    } else {
      localTmpSignalConversionAtEng_f = MAX_uint16_T;
    }

    localSwitch_l[0] = localTmpSignalConversionAtEng_f;
    if (((locallocalDivide_bz_idx_0 != locallocalDivide_bz_idx_0) ||
         (locallocalDivide_bz_idx_0 > 3.000000005E+038F)) || (-3.000000005E+038F
         > locallocalDivide_bz_idx_0)) {
      locallocalDivide_bz_idx = 0.0F;
    } else {
      locallocalDivide_bz_idx = locallocalDivide_bz_idx_0;
    }

    localDTC2_eg = (0.125F * locallocalDivide_bz_idx) + 0.5F;
    if (localDTC2_eg < 65536.0F) {
      if (localDTC2_eg >= 0.0F) {
        localTmpSignalConversionAtEng_f = (UInt16)localDTC2_eg;
      } else {
        localTmpSignalConversionAtEng_f = 0U;
      }
    } else {
      localTmpSignalConversionAtEng_f = MAX_uint16_T;
    }

    localSwitch_l[1] = localTmpSignalConversionAtEng_f;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAirSys_prm_pInMnfReqInport2' */
  Rte_Write_P_AirSys_prm_pInMnfReq_AirSys_prm_pInMnfReq(&localSwitch_l);
}

/* Output and update for exported function: RE_AirSysAir_002_TEV */
void RE_AirSysAir_002_TEV(void)
{
  Float32 localDivide_h5;
  Float32 localSwitch2_o;
  Float32 localAdd2_i;
  SInt16 localTmpSignalConversionAtTqSys;
  UInt16 localTmpSignalConversionAtAi_gg;
  UInt16 localTmpSignalConversionAtAir_e;
  UInt8 localTmpSignalConversionAtAi_gi;
  UInt16 localTmpSignalConversionAtIgSys;
  UInt32 localTmpSignalConversionAtEng_e;
  UInt32 localTmpSignalConversionAtEn_fx;

  /* S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_AirMPmpSp'
   *
   * Block requirements for '<S1>/F01_AirMPmpSp':
   *  1. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_100.02 ;
   *  2. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_024.01 ;
   *  3. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_025.01 ;
   *  4. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_054.01 ;
   *  5. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_048.01 ;
   *  6. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_053.01 ;
   *  7. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_049.01 ;
   *  8. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_050.01 ;
   *  9. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_052.01 ;
   *  10. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_051.01 ;
   *  11. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_047.01 ;
   *  12. SubSystem "F01_AirMPmpSp" !Trace_To : VEMS_R_10_07030_115.01 ;
   */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtTqSys_tqIdcAirReqOutport2' incorporates:
   *  Inport: '<Root>/TqSys_tqIdcAirReq'
   */
  Rte_Read_R_TqSys_tqIdcAirReq_TqSys_tqIdcAirReq
    (&localTmpSignalConversionAtTqSys);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_effCycOutport2' incorporates:
   *  Inport: '<Root>/AirSys_effCyc'
   */
  Rte_Read_R_AirSys_effCyc_AirSys_effCyc(&localTmpSignalConversionAtAi_gg);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_effAfrOutport2' incorporates:
   *  Inport: '<Root>/AirSys_effAfr'
   */
  Rte_Read_R_AirSys_effAfr_AirSys_effAfr(&localTmpSignalConversionAtAir_e);

  /* Product: '<S51>/Divide' incorporates:
   *  DataTypeConversion: '<S11>/DTC3'
   *  DataTypeConversion: '<S11>/DTC4'
   *  DataTypeConversion: '<S11>/DTC7'
   *  Product: '<S55>/Divide'
   */
  localDivide_h5 = (((((Float32)localTmpSignalConversionAtAi_gg) *
                      1.220703122E-010F) + 1.500000053E-006F) * (((Float32)
    localTmpSignalConversionAtTqSys) * 0.0625F)) / (((Float32)
    localTmpSignalConversionAtAir_e) * 3.051757813E-005F);

  /* Outputs for atomic SubSystem: '<S51>/If Action Subsystem3' */

  /* Switch: '<S64>/Switch1' incorporates:
   *  Constant: '<S64>/Constant1'
   *  Constant: '<S64>/Constant2'
   *  Constant: '<S64>/Constant3'
   *  Logic: '<S64>/Logical Operator1'
   *  RelationalOperator: '<S64>/Relational Operator'
   *  RelationalOperator: '<S64>/Relational Operator1'
   *  RelationalOperator: '<S64>/Relational Operator3'
   */
  if (((localDivide_h5 != localDivide_h5) || (localDivide_h5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_h5)) {
    localDivide_h5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S51>/If Action Subsystem3' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_effEGROutport2' incorporates:
   *  Inport: '<Root>/AirSys_effEGR'
   */
  Rte_Read_R_AirSys_effEGR_AirSys_effEGR(&localTmpSignalConversionAtAi_gi);

  /* Product: '<S49>/Divide' incorporates:
   *  DataTypeConversion: '<S11>/DTC2'
   */
  localDivide_h5 /= (((Float32)localTmpSignalConversionAtAi_gi) * 0.001953125F)
    + 0.75F;

  /* Outputs for atomic SubSystem: '<S49>/If Action Subsystem3' */

  /* Switch: '<S60>/Switch1' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Constant: '<S60>/Constant2'
   *  Constant: '<S60>/Constant3'
   *  Logic: '<S60>/Logical Operator1'
   *  RelationalOperator: '<S60>/Relational Operator'
   *  RelationalOperator: '<S60>/Relational Operator1'
   *  RelationalOperator: '<S60>/Relational Operator3'
   */
  if (((localDivide_h5 != localDivide_h5) || (localDivide_h5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_h5)) {
    localDivide_h5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S49>/If Action Subsystem3' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtIgSys_rTarStatIgSpEffOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rTarStatIgSpEff'
   */
  Rte_Read_R_IgSys_rTarStatIgSpEff_IgSys_rTarStatIgSpEff
    (&localTmpSignalConversionAtIgSys);

  /* Product: '<S50>/Divide' incorporates:
   *  DataTypeConversion: '<S11>/DTC1'
   */
  localDivide_h5 /= ((Float32)localTmpSignalConversionAtIgSys) * 0.0009765625F;

  /* Outputs for atomic SubSystem: '<S50>/If Action Subsystem3' */

  /* Switch: '<S62>/Switch1' incorporates:
   *  Constant: '<S62>/Constant1'
   *  Constant: '<S62>/Constant2'
   *  Constant: '<S62>/Constant3'
   *  Logic: '<S62>/Logical Operator1'
   *  RelationalOperator: '<S62>/Relational Operator'
   *  RelationalOperator: '<S62>/Relational Operator1'
   *  RelationalOperator: '<S62>/Relational Operator3'
   */
  if (((localDivide_h5 != localDivide_h5) || (localDivide_h5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_h5)) {
    localDivide_h5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S50>/If Action Subsystem3' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_mAirEngCylMaxOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirEngCylMax'
   */
  Rte_Read_R_EngM_mAirEngCylMax_EngM_mAirEngCylMax
    (&localTmpSignalConversionAtEng_e);

  /* DataTypeConversion: '<S11>/DTC5' */
  localSwitch2_o = ((Float32)localTmpSignalConversionAtEng_e) *
    5.960464478E-008F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_mAirEngCylMinOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirEngCylMin'
   */
  Rte_Read_R_EngM_mAirEngCylMin_EngM_mAirEngCylMin
    (&localTmpSignalConversionAtEn_fx);

  /* DataTypeConversion: '<S11>/DTC6' */
  localAdd2_i = ((Float32)localTmpSignalConversionAtEn_fx) * 5.960464478E-008F;

  /* Switch: '<S58>/Switch' incorporates:
   *  RelationalOperator: '<S58>/UpperRelop'
   */
  if (!(localDivide_h5 < localAdd2_i)) {
    localAdd2_i = localDivide_h5;
  }

  /* Switch: '<S58>/Switch2' incorporates:
   *  RelationalOperator: '<S58>/LowerRelop1'
   */
  if (!(localDivide_h5 > localSwitch2_o)) {
    localSwitch2_o = localAdd2_i;
  }

  /* Product: '<S52>/Divide' incorporates:
   *  Constant: '<S11>/Eng_mRef_C'
   *  DataTypeConversion: '<S11>/DTC8'
   */
  localDivide_h5 = localSwitch2_o / (((Float32)Eng_mRef_C) * 1.192016583E-007F);

  /* Outputs for atomic SubSystem: '<S52>/If Action Subsystem3' */

  /* Switch: '<S66>/Switch1' incorporates:
   *  Constant: '<S66>/Constant1'
   *  Constant: '<S66>/Constant2'
   *  Constant: '<S66>/Constant3'
   *  Logic: '<S66>/Logical Operator1'
   *  RelationalOperator: '<S66>/Relational Operator'
   *  RelationalOperator: '<S66>/Relational Operator1'
   *  RelationalOperator: '<S66>/Relational Operator3'
   */
  if (((localDivide_h5 != localDivide_h5) || (localDivide_h5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_h5)) {
    localDivide_h5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S52>/If Action Subsystem3' */

  /* DataTypeConversion: '<S47>/OutDTConv' incorporates:
   *  Constant: '<S47>/offset'
   *  Constant: '<S47>/offset1'
   *  Constant: '<S47>/one_on_slope'
   *  Product: '<S47>/Product4'
   *  Sum: '<S47>/Add1'
   *  Sum: '<S47>/Add2'
   */
  localDivide_h5 = (16384.0F * localDivide_h5) + 0.5F;
  if (localDivide_h5 < 65536.0F) {
    if (localDivide_h5 >= 0.0F) {
      localTmpSignalConversionAtAi_gg = (UInt16)localDivide_h5;
    } else {
      localTmpSignalConversionAtAi_gg = 0U;
    }
  } else {
    localTmpSignalConversionAtAi_gg = MAX_uint16_T;
  }

  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S48>/offset'
   *  Constant: '<S48>/offset1'
   *  Constant: '<S48>/one_on_slope'
   *  Constant: '<S54>/Byp_Fonction_SC'
   *  Constant: '<S54>/Int_BypC'
   *  DataTypeConversion: '<S48>/OutDTConv'
   *  Product: '<S48>/Product4'
   *  Sum: '<S48>/Add1'
   *  Sum: '<S48>/Add2'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAir_e = AirSys_mAirEngCylReq_tqEng_B;
  } else {
    localDivide_h5 = (8.389145E+006F * localSwitch2_o) + 0.5F;
    if (localDivide_h5 < 65536.0F) {
      localTmpSignalConversionAtAir_e = (UInt16)localDivide_h5;
    } else {
      localTmpSignalConversionAtAir_e = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_mAirEngCylReq_tqEngInport2' */
  Rte_Write_P_AirSys_mAirEngCylReq_tqEng_AirSys_mAirEngCylReq_tqEng
    (localTmpSignalConversionAtAir_e);

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S53>/Byp_Fonction_SC'
   *  Constant: '<S53>/Int_BypC'
   */
  if (AIRSYSAIR_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAi_gg = AirSys_rAirLdReq_B;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_rAirLdReqInport2' */
  Rte_Write_P_AirSys_rAirLdReq_AirSys_rAirLdReq(localTmpSignalConversionAtAi_gg);
}

/* Model initialize function */
void RE_AirSysAir_Init(void)
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
  RE_AirSysAir_001_MSE_Start();
  RE_AirSysAir_003_TEV_Start();
  RE_AirSysAir_004_TEV_Start();
  RE_AirSysAir_006_TEV_Start();
  RE_AirSysAir_007_TEV_Start();
}

#define AirSysAir_STOP_SEC_CODE
#include "AirSysAir_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
