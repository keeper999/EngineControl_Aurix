/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : UsThrMT                                                 */
/* !Description     : UsThrMT Software Component                              */
/*                                                                            */
/* !Module          : UsThrMT                                                 */
/* !Description     : UsThrMT Software Component                              */
/*                                                                            */
/* !File            : UsThrMT.c                                               */
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
/*   Model name       : UsThrMT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /UsThrMT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M01-UsThrMT/5-SO$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   14 Nov 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "UsThrMT.h"
#include "UsThrMT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S82>/F01_Sensors_offset_chart' */
#define IN_SENSORS_OFFSET_AVAILABLE    (1U)
#define IN_SENSORS_OFFSET_FREEZE       (2U)
#define IN_SENSORS_OFFSET_UNAVAILABLE  (3U)
#define IN_TIMER_CALCULATION           (4U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define UsThrMT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "UsThrMT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_UsThrMT UsThrMT_B;

/* Block states (auto storage) */
D_Work_UsThrMT UsThrMT_DWork;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "UsThrMT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define USTHRMT_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define USTHRMT_VEMSRTLIBT_MINOR_VERSION_REQ 14
#define USTHRMT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define USTHRMT_VEMSRTLIBT_VERSION_REQ (USTHRMT_VEMSRTLIBT_PATCH_VERSION_REQ + USTHRMT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + USTHRMT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if USTHRMT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define UsThrMT_START_SEC_CODE
#include "UsThrMT_MemMap.h"

void UsThrMT_ASYNC1(int controlPortIdx)
{
}

void UsThrMT_ASYNC2(int controlPortIdx)
{
}

void UsThrMT_ASYNC3(int controlPortIdx)
{
}

void UsThrMT_ASYNC4(int controlPortIdx)
{
}

void UsThrMT_ASYNC5(int controlPortIdx)
{
}

void UsThrMT_ASYNC6(int controlPortIdx)
{
}

void UsThrMT_ASYNC7(int controlPortIdx)
{
}

void UsThrMT_ASYNC8(int controlPortIdx)
{
}

void UsThrMT_ASYNC9(int controlPortIdx)
{
}

void UsThrMT_ASYNC10(int controlPortIdx)
{
}

/* Output and update for exported function: RE_UsThrMT_008_DRE */
void RE_UsThrMT_008_DRE(void)
{
  UInt16 localUsThrM_pLossAirFil;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Air_filter_pressure_loss_Eve'
   *
   * Block requirements for '<S1>/F01_Air_filter_pressure_loss_Eve':
   *  1. SubSystem "F01_Air_filter_pressure_loss_Eve" !Trace_To : VEMS_R_11_04300_001.01 ;
   *  2. SubSystem "F01_Air_filter_pressure_loss_Eve" !Trace_To : VEMS_R_11_04300_002.01 ;
   *  3. SubSystem "F01_Air_filter_pressure_loss_Eve" !Trace_To : VEMS_R_11_04300_003.01 ;
   *  4. SubSystem "F01_Air_filter_pressure_loss_Eve" !Trace_To : VEMS_R_11_04300_004.01 ;
   *  5. SubSystem "F01_Air_filter_pressure_loss_Eve" !Trace_To : VEMS_R_11_04300_077.01 ;
   *  6. SubSystem "F01_Air_filter_pressure_loss_Eve" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  7. SubSystem "F01_Air_filter_pressure_loss_Eve" !Trace_To : VEMS_R_11_04300_130.02 ;
   *  8. SubSystem "F01_Air_filter_pressure_loss_Eve" !Trace_To : VEMS_R_11_04300_090.01 ;
   */

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_mfAirCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfAirCor'
   */
  Rte_Read_R_EngM_mfAirCor_EngM_mfAirCor
    (&UsThrMT_B.TmpSignalConversionAtEngM_mfA_o);

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S26>/offset'
   *  Constant: '<S26>/offset1'
   *  Constant: '<S26>/one_on_slope'
   *  Constant: '<S28>/Byp_Fonction_SC'
   *  Constant: '<S28>/Int_BypC'
   *  DataTypeConversion: '<S26>/OutDTConv'
   *  Lookup_n-D: '<S27>/Lookup Table (n-D)'
   *  Product: '<S26>/Product4'
   *  Sum: '<S26>/Add1'
   *  Sum: '<S26>/Add2'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localUsThrM_pLossAirFil = UsThrM_pLossAirFil_B;
  } else {
    localtmp = (0.125F * look1_iu16lftu16p3If_binlcs
                (UsThrMT_B.TmpSignalConversionAtEngM_mfA_o, (&(Air_mfAirRef1_A[0])),
                 (&(UsThrM_pLossAirFil_T[0])), 15U)) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localUsThrM_pLossAirFil = (UInt16)localtmp;
      } else {
        localUsThrM_pLossAirFil = 0U;
      }
    } else {
      localUsThrM_pLossAirFil = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S14>/TmpSignal ConversionAtUsThrM_pLossAirFilInport2' */
  Rte_Write_P_UsThrM_pLossAirFil_UsThrM_pLossAirFil(localUsThrM_pLossAirFil);
}

/* Output and update for exported function: RE_UsThrMT_009_DRE */
void RE_UsThrMT_009_DRE(void)
{
  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Stall_counter_initialization'
   *
   * Block requirements for '<S1>/F02_Stall_counter_initialization':
   *  1. SubSystem "F02_Stall_counter_initialization" !Trace_To : VEMS_R_11_04300_005.01 ;
   *  2. SubSystem "F02_Stall_counter_initialization" !Trace_To : VEMS_R_11_04300_001.01 ;
   *  3. SubSystem "F02_Stall_counter_initialization" !Trace_To : VEMS_R_11_04300_007.01 ;
   *  4. SubSystem "F02_Stall_counter_initialization" !Trace_To : VEMS_R_11_04300_131.01 ;
   *  5. SubSystem "F02_Stall_counter_initialization" !Trace_To : VEMS_R_11_04300_119.02 ;
   *  6. SubSystem "F02_Stall_counter_initialization" !Trace_To : VEMS_R_11_04300_087.01 ;
   */

  /* SignalConversion: '<S21>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresStall_irvInport2' incorporates:
   *  Constant: '<S21>/UsThrM_tiDlyUpdAirExtPresStall_C'
   */
  Rte_IrvWrite_RE_UsThrMT_009_DRE_UsThrM_ctUpdAirExtPresStall_irv
    (UsThrM_tiDlyUpdAirExtPresStall_C);
}

/* Start for exported function: RE_UsThrMT_001_MSE */
void RE_UsThrMT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_PresSenAdj_initialization'
   *
   * Block requirements for '<S1>/F01_PresSenAdj_initialization':
   *  1. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_039.01 ;
   *  2. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_040.01 ;
   *  3. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_041.01 ;
   *  4. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  5. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_084.01 ;
   *  6. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_063.01 ;
   *  7. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_064.01 ;
   *  8. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_123.01 ;
   *  9. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_113.02 ;
   *  10. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_114.02 ;
   *  11. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_115.02 ;
   *  12. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_116.02 ;
   */
}

/* Output and update for exported function: RE_UsThrMT_001_MSE */
void RE_UsThrMT_001_MSE(void)
{
  UInt16 localTmpSignalConversionAtExt_p;
  UInt16 localSwitch;
  UInt16 localTmpSignalConversionAtExt_m;
  UInt16 localTmpSignalConversionAtExt_i;

  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_PresSenAdj_initialization'
   *
   * Block requirements for '<S1>/F01_PresSenAdj_initialization':
   *  1. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_039.01 ;
   *  2. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_040.01 ;
   *  3. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_041.01 ;
   *  4. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  5. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_084.01 ;
   *  6. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_063.01 ;
   *  7. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_064.01 ;
   *  8. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_123.01 ;
   *  9. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_113.02 ;
   *  10. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_114.02 ;
   *  11. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_115.02 ;
   *  12. SubSystem "F01_PresSenAdj_initialization" !Trace_To : VEMS_R_11_04300_116.02 ;
   */

  /* SignalConversion: '<S16>/TmpSignal ConversionAtExt_pDsThrMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_pDsThrMesSI'
   */
  Rte_Read_R_Ext_pDsThrMesSI_Ext_pDsThrMesSI(&localTmpSignalConversionAtExt_p);

  /* SignalConversion: '<S33>/copy' */
  UsThrM_pDsThrMesSIFil_IRV_MP = localTmpSignalConversionAtExt_p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S33>/autosar_testpoint1' */

  /* S-Function Block: <S33>/autosar_testpoint1 */

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/Byp_Fonction_SC'
   *  Constant: '<S36>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localSwitch = UsThrM_pDsThrMesCor_B;
  } else {
    localSwitch = localTmpSignalConversionAtExt_p;
  }

  /* SignalConversion: '<S16>/TmpSignal ConversionAtUsThrM_pDsThrMesCorInport2' */
  Rte_Write_P_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor(localSwitch);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtUsThrM_pDsThrMesSIFil_irvInport2' incorporates:
   *  SignalConversion: '<S16>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_UsThrMT_001_MSE_UsThrM_pDsThrMesSIFil_irv
    (localTmpSignalConversionAtExt_p);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtExt_pAirExtMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_pAirExtMesSI'
   */
  Rte_Read_R_Ext_pAirExtMesSI_Ext_pAirExtMesSI(&localTmpSignalConversionAtExt_m);

  /* SignalConversion: '<S32>/copy' */
  UsThrM_pAirExtMesSIFil_IRV_MP = localTmpSignalConversionAtExt_m;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S32>/autosar_testpoint1' */

  /* S-Function Block: <S32>/autosar_testpoint1 */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Byp_Fonction_SC'
   *  Constant: '<S37>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_p = UsThrM_pAirExtMesCor_B;
  } else {
    localTmpSignalConversionAtExt_p = localTmpSignalConversionAtExt_m;
  }

  /* SignalConversion: '<S16>/TmpSignal ConversionAtUsThrM_pAirExtMesCorInport2' */
  Rte_Write_P_UsThrM_pAirExtMesCor_UsThrM_pAirExtMesCor
    (localTmpSignalConversionAtExt_p);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtUsThrM_pAirExtMesSIFil_irvInport2' incorporates:
   *  SignalConversion: '<S16>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_UsThrMT_001_MSE_UsThrM_pAirExtMesSIFil_irv
    (localTmpSignalConversionAtExt_m);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtExt_pUsThrMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_pUsThrMesSI'
   */
  Rte_Read_R_Ext_pUsThrMesSI_Ext_pUsThrMesSI(&localTmpSignalConversionAtExt_i);

  /* SignalConversion: '<S35>/copy' */
  UsThrM_pUsThrMesSIFil_IRV_MP = localTmpSignalConversionAtExt_i;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S35>/autosar_testpoint1' */

  /* S-Function Block: <S35>/autosar_testpoint1 */

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Byp_Fonction_SC'
   *  Constant: '<S38>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_p = UsThrM_pUsThrMesCor_B;
  } else {
    localTmpSignalConversionAtExt_p = localTmpSignalConversionAtExt_i;
  }

  /* SignalConversion: '<S16>/TmpSignal ConversionAtUsThrM_pUsThrMesCorInport2' */
  Rte_Write_P_UsThrM_pUsThrMesCor_UsThrM_pUsThrMesCor
    (localTmpSignalConversionAtExt_p);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtUsThrM_pUsThrMesSIFil_irvInport2' incorporates:
   *  SignalConversion: '<S16>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_UsThrMT_001_MSE_UsThrM_pUsThrMesSIFil_irv
    (localTmpSignalConversionAtExt_i);

  /* SignalConversion: '<S34>/copy' incorporates:
   *  Constant: '<S16>/UsThrM_tiTmrDifPres_C'
   */
  UsThrM_tiTmrDifPres_IRV_MP = UsThrM_tiTmrDifPres_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S34>/autosar_testpoint1' */

  /* S-Function Block: <S34>/autosar_testpoint1 */

  /* SignalConversion: '<S16>/TmpSignal ConversionAtUsThrM_tiTmrDifPres_irvInport2' incorporates:
   *  Constant: '<S16>/UsThrM_tiTmrDifPres_C'
   *  SignalConversion: '<S16>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_UsThrMT_001_MSE_UsThrM_tiTmrDifPres_irv(UsThrM_tiTmrDifPres_C);
}

/*
 * Output and update for atomic system:
 *    '<S199>/filtrage'
 *    '<S108>/filtrage'
 *    '<S111>/filtrage'
 *    '<S114>/filtrage'
 */
void UsThrMT_filtrage(Float32 rtu_INPUT, Float32 rtu_Init_IRV, UInt16
                      rtu_GAIN, rtB_filtrage_UsThrMT *localB)
{
  /* Sum: '<S201>/Sum1' incorporates:
   *  Product: '<S201>/Product'
   *  Sum: '<S201>/Sum'
   */
  localB->Sum1 = ((Float32)((((Float32d)rtu_GAIN) * 1.5259021896696422E-005F) *
    ((Float32d)(rtu_INPUT - rtu_Init_IRV)))) + rtu_Init_IRV;
}

/* Start for exported function: RE_UsThrMT_010_TEV */
void RE_UsThrMT_010_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F03_Atmospheric_pressure_and_altimetric_factor_calculation'
   *
   * Block requirements for '<S1>/F03_Atmospheric_pressure_and_altimetric_factor_calculation':
   *  1. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_001.01 ;
   *  2. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_002.01 ;
   *  3. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_005.01 ;
   *  4. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_008.01 ;
   *  5. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_065.01 ;
   *  6. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_074.01 ;
   *  7. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_075.01 ;
   *  8. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_077.01 ;
   *  9. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_078.01 ;
   *  10. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  11. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  12. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_082.01 ;
   *  13. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_083.01 ;
   *  14. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_084.01 ;
   *  15. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_132.02 ;
   *  16. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_118.02 ;
   *  17. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_119.02 ;
   *  18. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_120.02 ;
   *  19. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_121.02 ;
   *  20. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_122.02 ;
   *  21. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_106.01 ;
   *  22. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_105.01 ;
   *  23. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_107.01 ;
   *  24. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_085.01 ;
   *  25. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_086.01 ;
   *  26. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_088.01 ;
   *  27. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_089.01 ;
   *  28. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_091.01 ;
   *  29. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_092.01 ;
   *  30. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_093.01 ;
   *  31. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_097.01 ;
   *  32. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_098.01 ;
   *  33. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_099.01 ;
   *  34. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_135.02 ;
   */

  /* Start for enable SubSystem: '<S23>/F02_Atmospheric_pressure_estimation' *
   * Block requirements for '<S23>/F02_Atmospheric_pressure_estimation':
   *  1. SubSystem "F02_Atmospheric_pressure_estimation" !Trace_To : VEMS_R_11_04300_010.01 ;
   */

  /* Start for Embedded MATLAB: '<S143>/Task_sceduler' incorporates:
   *  Start for SubSystem: '<S143>/F02_Atmospheric_pressure_estimation_calcul'
   *  Start for SubSystem: '<S143>/F02_Atmospheric_pressure_estimation_default'
   */

  /* Start for enable SubSystem: '<S157>/F03_Running_engine_turbo' *
   * Block requirements for '<S157>/F03_Running_engine_turbo':
   *  1. SubSystem "F03_Running_engine_turbo" !Trace_To : VEMS_R_11_04300_017.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S163>/F01_Turbo_conditions' *
   * Block requirements for '<S163>/F01_Turbo_conditions':
   *  1. SubSystem "F01_Turbo_conditions" !Trace_To : VEMS_R_11_04300_018.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S170>/F03_Turbo_low_load_condition' *
   * Block requirements for '<S170>/F03_Turbo_low_load_condition':
   *  1. SubSystem "F03_Turbo_low_load_condition" !Trace_To : VEMS_R_11_04300_027.01 ;
   */

  /* InitializeConditions for Memory: '<S187>/Memory' */
  UsThrMT_DWork.Memory_PreviousInput = TRUE;

  /* end of InitializeConditions for SubSystem: '<S170>/F03_Turbo_low_load_condition' */

  /* end of InitializeConditions for SubSystem: '<S163>/F01_Turbo_conditions' */

  /* end of Start for SubSystem: '<S157>/F03_Running_engine_turbo' */

  /* end of Start for SubSystem: '<S23>/F02_Atmospheric_pressure_estimation' */
}

/* Output and update for exported function: RE_UsThrMT_010_TEV */
void RE_UsThrMT_010_TEV(void)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion;
  UInt16 localSwitch_p;
  Boolean localLogic[2];
  Boolean localMemory;
  Boolean localLogicalOperator3_p;
  Boolean localAutosarServer;
  Boolean localR;
  Boolean localLogicalOperator;
  SInt32 localrtmax;
  Float32 localExt_nEng_Ext_nEngRef1_A_16;
  Float32 localfractionTmp_0d;
  UInt32 localExt_nEng_Ext_nEngRef1_A__n;
  Float32 localTe;
  Float32 localSwitch2;
  UInt16 localTmpSignalConversionAtUsT_j;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt16 localMerge1_d;
  UInt16 localMerge1;
  Boolean localNot_0;
  Boolean localNot_p;
  UInt16 localtmp;
  UInt16 locallocalTmpSignalConversionAt;
  UInt32 localtmp_0;
  SInt16 locallocalSum1_n;

  /* S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_Atmospheric_pressure_and_altimetric_factor_calculation'
   *
   * Block requirements for '<S1>/F03_Atmospheric_pressure_and_altimetric_factor_calculation':
   *  1. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_001.01 ;
   *  2. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_002.01 ;
   *  3. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_005.01 ;
   *  4. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_008.01 ;
   *  5. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_065.01 ;
   *  6. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_074.01 ;
   *  7. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_075.01 ;
   *  8. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_077.01 ;
   *  9. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_078.01 ;
   *  10. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  11. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  12. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_082.01 ;
   *  13. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_083.01 ;
   *  14. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_084.01 ;
   *  15. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_132.02 ;
   *  16. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_118.02 ;
   *  17. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_119.02 ;
   *  18. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_120.02 ;
   *  19. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_121.02 ;
   *  20. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_122.02 ;
   *  21. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_106.01 ;
   *  22. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_105.01 ;
   *  23. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_107.01 ;
   *  24. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_085.01 ;
   *  25. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_086.01 ;
   *  26. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_088.01 ;
   *  27. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_089.01 ;
   *  28. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_091.01 ;
   *  29. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_092.01 ;
   *  30. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_093.01 ;
   *  31. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_097.01 ;
   *  32. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_098.01 ;
   *  33. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_099.01 ;
   *  34. SubSystem "F03_Atmospheric_pressure_and_altimetric_factor_calculation" !Trace_To : VEMS_R_11_04300_135.02 ;
   */

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pAirExtMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExtMesCor_INPUT'
   */
  Rte_Read_R_UsThrM_pAirExtMesCor_UsThrM_pAirExtMesCor
    (&localTmpSignalConversionAtUsThr);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresStall_prevOutport2' */
  UsThrM_ctUpdAirExtPresStall_prev =
    Rte_IrvRead_RE_UsThrMT_010_TEV_UsThrM_ctUpdAirExtPresStall_irv();

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresRun_prevOutport2' */
  UsThrM_ctUpdAirExtPresRun_prev =
    Rte_IrvRead_RE_UsThrMT_010_TEV_UsThrM_ctUpdAirExtPresRun_irv();

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresIdl_prevOutport2' */
  UsThrM_ctUpdAirExtPresIdl_prev =
    Rte_IrvRead_RE_UsThrMT_010_TEV_UsThrM_ctUpdAirExtPresIdl_irv();

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresCut_prevOutport2' */
  UsThrM_ctUpdAirExtPresCut_prev =
    Rte_IrvRead_RE_UsThrMT_010_TEV_UsThrM_ctUpdAirExtPresCut_irv();

  /* S-Function (sfun_autosar_clientop): '<S146>/AutosarServer' */
  Rte_Call_R_FRM_bInhMes_pAirExt_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S23>/Logical Operator' incorporates:
   *  Constant: '<S23>/Ext_bPresSen_pAirExt_SC'
   *  Logic: '<S146>/Not'
   *  Logic: '<S23>/Logical Operator1'
   */
  localLogicalOperator = ((!(!localAutosarServer)) && Ext_bPresSen_pAirExt_SC);

  /* Outputs for enable SubSystem: '<S23>/F01_Atmospheric_pressure_measure' incorporates:
   *  EnablePort: '<S142>/Enable'
   *
   * Block requirements for '<S23>/F01_Atmospheric_pressure_measure':
   *  1. SubSystem "F01_Atmospheric_pressure_measure" !Trace_To : VEMS_R_11_04300_009.01 ;
   */
  if (localLogicalOperator) {
    /* SignalConversion: '<S142>/Signal Conversion1' */
    UsThrMT_B.Merge = localTmpSignalConversionAtUsThr;

    /* SignalConversion: '<S142>/Signal Conversion2' */
    UsThrMT_B.Merge1 = UsThrM_ctUpdAirExtPresStall_prev;

    /* SignalConversion: '<S142>/Signal Conversion3' */
    UsThrMT_B.Merge2 = UsThrM_ctUpdAirExtPresRun_prev;

    /* SignalConversion: '<S142>/Signal Conversion4' */
    UsThrMT_B.Merge3 = UsThrM_ctUpdAirExtPresIdl_prev;

    /* SignalConversion: '<S142>/Signal Conversion5' */
    UsThrMT_B.Merge4 = UsThrM_ctUpdAirExtPresCut_prev;
  }

  /* end of Outputs for SubSystem: '<S23>/F01_Atmospheric_pressure_measure' */

  /* S-Function (sfun_autosar_clientop): '<S147>/AutosarServer' */
  Rte_Call_R_FRM_bInhMes_pDsThrMes_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S147>/Not' */
  localNot_0 = !localAutosarServer;

  /* S-Function (sfun_autosar_clientop): '<S148>/AutosarServer' */
  Rte_Call_R_FRM_bInhMes_pUsThrMes_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S148>/Not' */
  localNot_p = !localAutosarServer;

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor_INPUT'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_p_h);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pUsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrMesCor_INPUT'
   */
  Rte_Read_R_UsThrM_pUsThrMesCor_UsThrM_pUsThrMesCor
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_p_i);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&UsThrMT_B.TmpSignalConversionAtExt_nEng_i);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtECU_stPwrECUOutport2' incorporates:
   *  Inport: '<Root>/ECU_stPwrECU'
   */
  Rte_Read_R_ECU_stPwrECU_ECU_stPwrECU
    (&UsThrMT_B.TmpSignalConversionAtECU_stPwrE);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&UsThrMT_B.TmpSignalConversionAtEng_stEruO);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtEng_stRunOutport2' incorporates:
   *  Inport: '<Root>/Eng_stRun'
   */
  Rte_Read_R_Eng_stRun_Eng_stRun(&UsThrMT_B.TmpSignalConversionAtEng_stRunO);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtThrLrn_rOpSIOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpSI'
   */
  Rte_Read_R_ThrLrn_rOpSI_ThrLrn_rOpSI
    (&UsThrMT_B.TmpSignalConversionAtThrLrn_rOp);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pLossAirFilOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pLossAirFil_INPUT'
   */
  Rte_Read_R_UsThrM_pLossAirFil_UsThrM_pLossAirFil
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_pLo);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pLossCACOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pLossCAC_INPUT'
   */
  Rte_Read_R_UsThrM_pLossCAC_UsThrM_pLossCAC
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_p_k);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pLossCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pLossCmpr_INPUT'
   */
  Rte_Read_R_UsThrM_pLossCmpr_UsThrM_pLossCmpr
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_p_a);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIdlSys_bAcvIdlCtlOutport2' incorporates:
   *  Inport: '<Root>/IdlSys_bAcvIdlCtl'
   */
  Rte_Read_R_IdlSys_bAcvIdlCtl_IdlSys_bAcvIdlCtl
    (&UsThrMT_B.TmpSignalConversionAtIdlSys_bAc);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pAirExtRaw_prevOutport2' */
  UsThrM_pAirExtRaw_prev = Rte_IrvRead_RE_UsThrMT_010_TEV_UsThrM_pAirExtRaw_irv();

  /* Outputs for enable SubSystem: '<S23>/F02_Atmospheric_pressure_estimation' incorporates:
   *  EnablePort: '<S143>/Enable'
   *  Logic: '<S23>/Logical Operator2'
   *
   * Block requirements for '<S23>/F02_Atmospheric_pressure_estimation':
   *  1. SubSystem "F02_Atmospheric_pressure_estimation" !Trace_To : VEMS_R_11_04300_010.01 ;
   */
  if (!localLogicalOperator) {
    /* Embedded MATLAB: '<S143>/Task_sceduler' incorporates:
     *  SubSystem: '<S143>/F02_Atmospheric_pressure_estimation_calcul'
     *  SubSystem: '<S143>/F02_Atmospheric_pressure_estimation_default'
     */
    /* Embedded MATLAB Function 'UsThrMT/F03_Atmospheric_pressure_and_altimetric_factor_calculation/F02_Atmospheric_pressure_estimation/Task_sceduler': '<S159>:1' */
    /* '<S159>:1:5' */

    /* SignalConversion: '<S158>/Signal Conversion5' */
    UsThrMT_B.Merge4 = UsThrM_ctUpdAirExtPresCut_prev;

    /* SignalConversion: '<S158>/Signal Conversion4' */
    UsThrMT_B.Merge3 = UsThrM_ctUpdAirExtPresIdl_prev;

    /* SignalConversion: '<S158>/Signal Conversion3' */
    UsThrMT_B.Merge2 = UsThrM_ctUpdAirExtPresRun_prev;

    /* SignalConversion: '<S158>/Signal Conversion2' */
    UsThrMT_B.Merge1 = UsThrM_ctUpdAirExtPresStall_prev;

    /* SignalConversion: '<S158>/Signal Conversion1' */
    UsThrMT_B.Merge = UsThrM_pAirExtRaw_prev;

    /* '<S159>:1:7' */

    /* PreLookup: '<S160>/Prelookup' */
    localExt_nEng_Ext_nEngRef1_A__n = plook_u32u16f_binc
      (UsThrMT_B.TmpSignalConversionAtExt_nEng_i, (&(Ext_nEngRef1_A[0])), 15U,
       &localExt_nEng_Ext_nEngRef1_A_16);

    /* Outputs for atomic SubSystem: '<S157>/F01_Stopped_engine' *
     * Block requirements for '<S157>/F01_Stopped_engine':
     *  1. SubSystem "F01_Stopped_engine" !Trace_To : VEMS_R_11_04300_011.01 ;
     */

    /* RelationalOperator: '<S161>/Relational Operator' incorporates:
     *  Constant: '<S161>/Ext_stStall_SC'
     */
    localLogicalOperator = (UsThrMT_B.TmpSignalConversionAtEng_stEruO ==
      Ext_stStall_SC);

    /* Outputs for enable SubSystem: '<S161>/F01_Stall_condition' incorporates:
     *  EnablePort: '<S164>/Enable'
     *
     * Block requirements for '<S161>/F01_Stall_condition':
     *  1. SubSystem "F01_Stall_condition" !Trace_To : VEMS_R_11_04300_012.01 ;
     */
    if (localLogicalOperator) {
      /* MinMax: '<S164>/MinMax' incorporates:
       *  Constant: '<S164>/ConstVal'
       *  Constant: '<S164>/UsThrM_tiSampleFast_SC'
       *  Sum: '<S164>/Sum'
       */
      localrtmax = UsThrM_ctUpdAirExtPresStall_prev - UsThrM_tiSampleFast_SC;
      if (0 > localrtmax) {
        localrtmax = 0;
      }

      if (localrtmax <= 0) {
        locallocalTmpSignalConversionAt = 0U;
      } else {
        locallocalTmpSignalConversionAt = (UInt16)localrtmax;
      }

      /* Logic: '<S164>/Logical Operator10' incorporates:
       *  Constant: '<S164>/ConstVal_1'
       *  Constant: '<S164>/Ext_stWaitRstrt_SC'
       *  RelationalOperator: '<S164>/Relational Operator'
       *  RelationalOperator: '<S164>/Relational Operator2'
       */
      UsThrM_bUpdAirExtPresStall = ((UsThrMT_B.TmpSignalConversionAtECU_stPwrE
        != Ext_stWaitRstrt_SC) && (locallocalTmpSignalConversionAt == 0));

      /* SignalConversion: '<S164>/Signal Conversion15' */
      UsThrMT_B.Merge1 = locallocalTmpSignalConversionAt;
    }

    /* end of Outputs for SubSystem: '<S161>/F01_Stall_condition' */

    /* Outputs for enable SubSystem: '<S161>/F02_Stall_atmospheric_pressure_update' incorporates:
     *  EnablePort: '<S165>/Enable'
     *  Logic: '<S161>/Logical Operator10'
     *
     * Block requirements for '<S161>/F02_Stall_atmospheric_pressure_update':
     *  1. SubSystem "F02_Stall_atmospheric_pressure_update" !Trace_To : VEMS_R_11_04300_013.01 ;
     */
    if ((localLogicalOperator) && UsThrM_bUpdAirExtPresStall) {
      /* Switch: '<S165>/Switch1' incorporates:
       *  Constant: '<S165>/UsThrM_pAirExtDft_C'
       *  Constant: '<S165>/UsThrM_pStallThd_C'
       *  Logic: '<S165>/Logical Operator2'
       *  Logic: '<S165>/Logical Operator3'
       *  RelationalOperator: '<S165>/Relational Operator1'
       */
      if ((!localNot_0) && (UsThrMT_B.TmpSignalConversionAtUsThrM_p_h >
                            UsThrM_pStallThd_C)) {
        localTmpSignalConversionAtUsThr =
          UsThrMT_B.TmpSignalConversionAtUsThrM_p_h;
      } else {
        localTmpSignalConversionAtUsThr = UsThrM_pAirExtDft_C;
      }

      /* Switch: '<S165>/Switch' incorporates:
       *  Constant: '<S165>/Ext_bPresSen_pUsThr_SC'
       *  Logic: '<S165>/Logical Operator1'
       *  Logic: '<S165>/Logical Operator8'
       */
      if ((!localNot_p) && Ext_bPresSen_pUsThr_SC) {
        UsThrMT_B.Merge = UsThrMT_B.TmpSignalConversionAtUsThrM_p_i;
      } else {
        UsThrMT_B.Merge = localTmpSignalConversionAtUsThr;
      }
    }

    /* end of Outputs for SubSystem: '<S161>/F02_Stall_atmospheric_pressure_update' */

    /* end of Outputs for SubSystem: '<S157>/F01_Stopped_engine' */

    /* RelationalOperator: '<S157>/Relational Operator' incorporates:
     *  Constant: '<S157>/Ext_stRun_SC'
     */
    localLogicalOperator = (UsThrMT_B.TmpSignalConversionAtEng_stEruO ==
      Ext_stRun_SC);

    /* Outputs for enable SubSystem: '<S157>/F02_Running_engine_atmo' incorporates:
     *  Constant: '<S157>/Ext_bEngTrbMod_SC'
     *  EnablePort: '<S162>/Enable'
     *  Logic: '<S157>/Logical Operator1'
     *  Logic: '<S157>/Logical Operator5'
     *
     * Block requirements for '<S157>/F02_Running_engine_atmo':
     *  1. SubSystem "F02_Running_engine_atmo" !Trace_To : VEMS_R_11_04300_014.01 ;
     */
    if ((localLogicalOperator) && (!Ext_bEngTrbMod_SC)) {
      /* Outputs for enable SubSystem: '<S162>/F01_Atmospheric_pressure_update' incorporates:
       *  Constant: '<S162>/UsThrM_nUpdAirExtPresThd_C'
       *  EnablePort: '<S166>/Enable'
       *  Logic: '<S162>/Logical Operator2'
       *  Logic: '<S162>/Logical Operator3'
       *  RelationalOperator: '<S162>/Relational Operator1'
       *
       * Block requirements for '<S162>/F01_Atmospheric_pressure_update':
       *  1. SubSystem "F01_Atmospheric_pressure_update" !Trace_To : VEMS_R_11_04300_015.01 ;
       */
      if ((!localNot_0) && (UsThrMT_B.TmpSignalConversionAtExt_nEng_i >
                            UsThrM_nUpdAirExtPresThd_C)) {
        /* MinMax: '<S166>/MinMax' incorporates:
         *  Constant: '<S166>/ConstVal_1'
         *  Constant: '<S166>/UsThrM_tiSampleFast_SC'
         *  Sum: '<S166>/Sum'
         */
        localrtmax = UsThrM_ctUpdAirExtPresRun_prev - UsThrM_tiSampleFast_SC;
        if (0 > localrtmax) {
          localrtmax = 0;
        }

        if (localrtmax <= 0) {
          localTmpSignalConversionAtUsThr = 0U;
        } else {
          localTmpSignalConversionAtUsThr = (UInt16)localrtmax;
        }

        /* MinMax: '<S166>/MinMax1' incorporates:
         *  Constant: '<S166>/UsThrM_pOfsMaxAirExtPres_C'
         *  Sum: '<S166>/Sum2'
         */
        localtmp_0 = (UInt32)(UsThrMT_B.TmpSignalConversionAtUsThrM_p_h +
          UsThrM_pOfsMaxAirExtPres_C);
        if (localtmp_0 > 65535U) {
          locallocalTmpSignalConversionAt = MAX_uint16_T;
        } else {
          locallocalTmpSignalConversionAt = (UInt16)localtmp_0;
        }

        if (UsThrM_pAirExtRaw_prev > locallocalTmpSignalConversionAt) {
          locallocalTmpSignalConversionAt = UsThrM_pAirExtRaw_prev;
        }

        /* Interpolation_n-D: '<S169>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localExt_nEng_Ext_nEngRef1_A_16;
        localfractionTmp_0d = intrp1d_iu16n10ff_u32f_l_ns
          (localExt_nEng_Ext_nEngRef1_A__n, localfractionTmp_0d,
           (&(UsThrM_rMinThrUpdAirExtPres_T[0])));

        /* Switch: '<S166>/Switch' incorporates:
         *  Constant: '<S166>/UsThrM_tiDlyUpdAirExtPres_C'
         *  Constant: '<S168>/offset'
         *  Constant: '<S168>/offset1'
         *  Constant: '<S168>/one_on_slope'
         *  DataTypeConversion: '<S168>/OutDTConv'
         *  Product: '<S168>/Product4'
         *  RelationalOperator: '<S166>/Relational Operator4'
         *  Sum: '<S168>/Add1'
         *  Sum: '<S168>/Add2'
         */
        localfractionTmp_0d = (1024.0F * localfractionTmp_0d) + 0.5F;
        if (localfractionTmp_0d < 65536.0F) {
          if (localfractionTmp_0d >= 0.0F) {
            localtmp = (UInt16)localfractionTmp_0d;
          } else {
            localtmp = 0U;
          }
        } else {
          localtmp = MAX_uint16_T;
        }

        if (!(UsThrMT_B.TmpSignalConversionAtThrLrn_rOp > localtmp)) {
          localTmpSignalConversionAtUsThr = UsThrM_tiDlyUpdAirExtPres_C;
        }

        /* SignalConversion: '<S166>/Signal Conversion15' */
        UsThrMT_B.Merge2 = localTmpSignalConversionAtUsThr;

        /* Switch: '<S166>/Switch1' incorporates:
         *  Constant: '<S166>/ConstVal'
         *  RelationalOperator: '<S166>/Relational Operator1'
         *  Sum: '<S166>/Sum1'
         */
        if (localTmpSignalConversionAtUsThr == 0) {
          localtmp_0 = (UInt32)(UsThrMT_B.TmpSignalConversionAtUsThrM_pLo +
            UsThrMT_B.TmpSignalConversionAtUsThrM_p_h);
          if (localtmp_0 > 65535U) {
            UsThrMT_B.Merge = MAX_uint16_T;
          } else {
            UsThrMT_B.Merge = (UInt16)localtmp_0;
          }
        } else {
          UsThrMT_B.Merge = locallocalTmpSignalConversionAt;
        }
      }

      /* end of Outputs for SubSystem: '<S162>/F01_Atmospheric_pressure_update' */

      /* Outputs for enable SubSystem: '<S162>/F02_Atmospheric_pressure_default_value' incorporates:
       *  EnablePort: '<S167>/Enable'
       *
       * Block requirements for '<S162>/F02_Atmospheric_pressure_default_value':
       *  1. SubSystem "F02_Atmospheric_pressure_default_value" !Trace_To : VEMS_R_11_04300_016.01 ;
       */
      if (localNot_0) {
        /* Constant: '<S167>/UsThrM_pAirExtDft_C' */
        UsThrMT_B.Merge = UsThrM_pAirExtDft_C;
      }

      /* end of Outputs for SubSystem: '<S162>/F02_Atmospheric_pressure_default_value' */
    }

    /* end of Outputs for SubSystem: '<S157>/F02_Running_engine_atmo' */

    /* Outputs for enable SubSystem: '<S157>/F03_Running_engine_turbo' incorporates:
     *  Constant: '<S157>/Ext_bEngTrbMod_SC'
     *  EnablePort: '<S163>/Enable'
     *  Logic: '<S157>/Logical Operator2'
     *
     * Block requirements for '<S157>/F03_Running_engine_turbo':
     *  1. SubSystem "F03_Running_engine_turbo" !Trace_To : VEMS_R_11_04300_017.01 ;
     */
    if (Ext_bEngTrbMod_SC && (localLogicalOperator)) {
      /* Outputs for atomic SubSystem: '<S163>/F01_Turbo_conditions' *
       * Block requirements for '<S163>/F01_Turbo_conditions':
       *  1. SubSystem "F01_Turbo_conditions" !Trace_To : VEMS_R_11_04300_018.01 ;
       */

      /* Outputs for atomic SubSystem: '<S170>/F01_Turbo_idle_condition' *
       * Block requirements for '<S170>/F01_Turbo_idle_condition':
       *  1. SubSystem "F01_Turbo_idle_condition" !Trace_To : VEMS_R_11_04300_019.01 ;
       */

      /* Outputs for enable SubSystem: '<S173>/F01_Idle_counter' incorporates:
       *  EnablePort: '<S176>/Enable'
       *
       * Block requirements for '<S173>/F01_Idle_counter':
       *  1. SubSystem "F01_Idle_counter" !Trace_To : VEMS_R_11_04300_020.01 ;
       */
      if (UsThrMT_B.TmpSignalConversionAtIdlSys_bAc) {
        /* MinMax: '<S176>/MinMax' incorporates:
         *  Constant: '<S176>/ConstVal'
         *  Constant: '<S176>/UsThrM_tiSampleFast_SC'
         *  Sum: '<S176>/Sum'
         */
        localrtmax = UsThrM_ctUpdAirExtPresIdl_prev - UsThrM_tiSampleFast_SC;
        if (0 > localrtmax) {
          localrtmax = 0;
        }

        if (localrtmax <= 0) {
          localMerge1_d = 0U;
        } else {
          localMerge1_d = (UInt16)localrtmax;
        }
      }

      /* end of Outputs for SubSystem: '<S173>/F01_Idle_counter' */

      /* Outputs for enable SubSystem: '<S173>/F02_Idle_counter_initialization' incorporates:
       *  EnablePort: '<S177>/Enable'
       *  Logic: '<S173>/Logical Operator5'
       *
       * Block requirements for '<S173>/F02_Idle_counter_initialization':
       *  1. SubSystem "F02_Idle_counter_initialization" !Trace_To : VEMS_R_11_04300_021.01 ;
       */
      if (!UsThrMT_B.TmpSignalConversionAtIdlSys_bAc) {
        /* Constant: '<S177>/UsThrM_tiDlyUpdAirExtPresIdl_C' */
        localMerge1_d = UsThrM_tiDlyUpdAirExtPresIdl_C;
      }

      /* end of Outputs for SubSystem: '<S173>/F02_Idle_counter_initialization' */

      /* Outputs for atomic SubSystem: '<S173>/F03_Idle_condition' *
       * Block requirements for '<S173>/F03_Idle_condition':
       *  1. SubSystem "F03_Idle_condition" !Trace_To : VEMS_R_11_04300_022.01 ;
       */

      /* Logic: '<S178>/Logical Operator3' incorporates:
       *  Constant: '<S178>/ConstVal'
       *  Constant: '<S178>/UsThrM_nIdlThd_C'
       *  RelationalOperator: '<S178>/Relational Operator1'
       *  RelationalOperator: '<S178>/Relational Operator8'
       */
      UsThrM_bAcvUpdAirExtPresIdl = ((localMerge1_d == 0) &&
        (UsThrMT_B.TmpSignalConversionAtExt_nEng_i < UsThrM_nIdlThd_C));

      /* end of Outputs for SubSystem: '<S173>/F03_Idle_condition' */

      /* SignalConversion: '<S173>/Signal Conversion15' */
      UsThrMT_B.Merge3 = localMerge1_d;

      /* end of Outputs for SubSystem: '<S170>/F01_Turbo_idle_condition' */

      /* Outputs for atomic SubSystem: '<S170>/F02_Turbo_injection_cutoff_condition' *
       * Block requirements for '<S170>/F02_Turbo_injection_cutoff_condition':
       *  1. SubSystem "F02_Turbo_injection_cutoff_condition" !Trace_To : VEMS_R_11_04300_023.01 ;
       */

      /* RelationalOperator: '<S174>/Relational Operator6' incorporates:
       *  Constant: '<S174>/Eng_stOverRun_SC'
       */
      localLogicalOperator = (UsThrMT_B.TmpSignalConversionAtEng_stRunO ==
        Eng_stOverRun_SC);

      /* Outputs for enable SubSystem: '<S174>/F01_Injection_cutoff_counter' incorporates:
       *  EnablePort: '<S179>/Enable'
       *
       * Block requirements for '<S174>/F01_Injection_cutoff_counter':
       *  1. SubSystem "F01_Injection_cutoff_counter" !Trace_To : VEMS_R_11_04300_024.01 ;
       */
      if (localLogicalOperator) {
        /* MinMax: '<S179>/MinMax1' incorporates:
         *  Constant: '<S179>/ConstVal'
         *  Constant: '<S179>/UsThrM_tiSampleFast_SC'
         *  Sum: '<S179>/Sum1'
         */
        localrtmax = UsThrM_ctUpdAirExtPresCut_prev - UsThrM_tiSampleFast_SC;
        if (0 > localrtmax) {
          localrtmax = 0;
        }

        if (localrtmax <= 0) {
          localMerge1 = 0U;
        } else {
          localMerge1 = (UInt16)localrtmax;
        }
      }

      /* end of Outputs for SubSystem: '<S174>/F01_Injection_cutoff_counter' */

      /* Outputs for enable SubSystem: '<S174>/F02_Injection_cutoff_counter_initialization' incorporates:
       *  EnablePort: '<S180>/Enable'
       *  Logic: '<S174>/Logical Operator5'
       *
       * Block requirements for '<S174>/F02_Injection_cutoff_counter_initialization':
       *  1. SubSystem "F02_Injection_cutoff_counter_initialization" !Trace_To : VEMS_R_11_04300_025.01 ;
       */
      if (!localLogicalOperator) {
        /* Constant: '<S180>/UsThrM_tiUpdAirExtPresInjCut_C' */
        localMerge1 = UsThrM_tiUpdAirExtPresInjCut_C;
      }

      /* end of Outputs for SubSystem: '<S174>/F02_Injection_cutoff_counter_initialization' */

      /* Outputs for atomic SubSystem: '<S174>/F03_Injection_cutoff_condition' *
       * Block requirements for '<S174>/F03_Injection_cutoff_condition':
       *  1. SubSystem "F03_Injection_cutoff_condition" !Trace_To : VEMS_R_11_04300_026.01 ;
       */

      /* Logic: '<S181>/Logical Operator1' incorporates:
       *  Constant: '<S181>/ConstVal'
       *  Constant: '<S181>/UsThrM_nCutThd_C'
       *  RelationalOperator: '<S181>/Relational Operator3'
       *  RelationalOperator: '<S181>/Relational Operator7'
       */
      UsThrM_bAcvUpdAirExtPresCut = ((UsThrMT_B.TmpSignalConversionAtExt_nEng_i <
        UsThrM_nCutThd_C) && (localMerge1 == 0));

      /* end of Outputs for SubSystem: '<S174>/F03_Injection_cutoff_condition' */

      /* SignalConversion: '<S174>/Signal Conversion15' */
      UsThrMT_B.Merge4 = localMerge1;

      /* end of Outputs for SubSystem: '<S170>/F02_Turbo_injection_cutoff_condition' */

      /* Outputs for atomic SubSystem: '<S170>/F03_Turbo_low_load_condition' *
       * Block requirements for '<S170>/F03_Turbo_low_load_condition':
       *  1. SubSystem "F03_Turbo_low_load_condition" !Trace_To : VEMS_R_11_04300_027.01 ;
       */

      /* Sum: '<S175>/Sum1' incorporates:
       *  UnitDelay: '<S184>/Unit Delay'
       */
      localrtmax = UsThrMT_B.TmpSignalConversionAtThrLrn_rOp -
        UsThrMT_DWork.UnitDelay_DSTATE_p;
      if (localrtmax > 32767) {
        locallocalSum1_n = MAX_int16_T;
      } else if (localrtmax <= -32768) {
        locallocalSum1_n = MIN_int16_T;
      } else {
        locallocalSum1_n = (SInt16)localrtmax;
      }

      /* Abs: '<S175>/Abs' */
      if (locallocalSum1_n < 0) {
        localTmpSignalConversionAtUsThr = (UInt16)(-locallocalSum1_n);
      } else {
        localTmpSignalConversionAtUsThr = (UInt16)locallocalSum1_n;
      }

      /* DataTypeConversion: '<S175>/DTC3' incorporates:
       *  Constant: '<S175>/UsThrM_tiSampleFast_SC'
       */
      localTe = ((Float32)UsThrM_tiSampleFast_SC) * 1.000000047E-003F;

      /* Interpolation_n-D: '<S185>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_nEng_Ext_nEngRef1_A_16;
      localfractionTmp_0d = intrp1d_iu16n10ff_u32f_l_ns
        (localExt_nEng_Ext_nEngRef1_A__n, localfractionTmp_0d,
         (&(UsThrM_rMinTrbThrUpdAirExtPres_T[0])));

      /* RelationalOperator: '<S175>/Relational Operator1' incorporates:
       *  Constant: '<S175>/UsThrM_rMaxThrStabThd_C'
       */
      UsThrM_bAcvUpdThrStab_MP = (localTmpSignalConversionAtUsThr <
        UsThrM_rMaxThrStabThd_C);

      /* RelationalOperator: '<S175>/Relational Operator2' incorporates:
       *  Constant: '<S175>/UsThrM_pLossThd_C'
       *  Sum: '<S175>/Sum'
       */
      localR = (((UInt32)(UsThrMT_B.TmpSignalConversionAtUsThrM_p_i +
                            UsThrM_pLossThd_C)) > ((UInt32)
                 UsThrM_pAirExtRaw_prev));

      /* Logic: '<S175>/Logical Operator1' incorporates:
       *  Constant: '<S182>/offset'
       *  Constant: '<S182>/offset1'
       *  Constant: '<S182>/one_on_slope'
       *  DataTypeConversion: '<S182>/OutDTConv'
       *  Product: '<S182>/Product4'
       *  RelationalOperator: '<S175>/Relational Operator4'
       *  Sum: '<S182>/Add1'
       *  Sum: '<S182>/Add2'
       */
      localfractionTmp_0d = (1024.0F * localfractionTmp_0d) + 0.5F;
      if (localfractionTmp_0d < 65536.0F) {
        if (localfractionTmp_0d >= 0.0F) {
          locallocalTmpSignalConversionAt = (UInt16)localfractionTmp_0d;
        } else {
          locallocalTmpSignalConversionAt = 0U;
        }
      } else {
        locallocalTmpSignalConversionAt = MAX_uint16_T;
      }

      UsThrM_bAcvUpdAirExtPresTrb = (((UsThrMT_B.TmpSignalConversionAtThrLrn_rOp
        < locallocalTmpSignalConversionAt) && UsThrM_bAcvUpdThrStab_MP) &&
        (localR));

      /* UnitDelay: '<S188>/Unit Delay' */
      localfractionTmp_0d = UsThrMT_DWork.UnitDelay_DSTATE;

      /* Sum: '<S183>/Sum2' incorporates:
       *  Constant: '<S175>/UsThrM_tiDlyThrStab_C'
       *  Constant: '<S183>/Constant1'
       *  Constant: '<S183>/Constant6'
       *  MinMax: '<S183>/MinMax1'
       *  Product: '<S190>/Divide'
       */
      localSwitch2 = (((Float32)UsThrM_tiDlyThrStab_C) * 9.999999776E-003F) +
        (10.0F * localTe);

      /* Switch: '<S195>/Switch' incorporates:
       *  Constant: '<S183>/Constant3'
       *  RelationalOperator: '<S195>/UpperRelop'
       */
      if (UsThrMT_DWork.UnitDelay_DSTATE < 0.0F) {
        localfractionTmp_0d = 0.0F;
      }

      /* Switch: '<S195>/Switch2' incorporates:
       *  RelationalOperator: '<S195>/LowerRelop1'
       */
      if (!(UsThrMT_DWork.UnitDelay_DSTATE > localSwitch2)) {
        localSwitch2 = localfractionTmp_0d;
      }

      /* RelationalOperator: '<S183>/Relational Operator1' incorporates:
       *  Constant: '<S183>/Constant2'
       *  MinMax: '<S183>/MinMax1'
       */
      localNot_0 = (UsThrM_tiDlyThrStab_C == 0);

      /* UnitDelay: '<S189>/Unit Delay' */
      localR = UsThrMT_DWork.UnitDelay_DSTATE_e;

      /* UnitDelay: '<S196>/Unit Delay' */
      localLogicalOperator3_p = UsThrMT_DWork.UnitDelay_DSTATE_es;

      /* Logic: '<S191>/Logical Operator' incorporates:
       *  Logic: '<S191>/Logical Operator1'
       */
      localLogicalOperator = (UsThrM_bAcvUpdAirExtPresTrb &&
        (!localLogicalOperator3_p));

      /* Logic: '<S183>/Logical Operator3' */
      localLogicalOperator3_p = !UsThrM_bAcvUpdAirExtPresTrb;

      /* Switch: '<S183>/Switch1' incorporates:
       *  Constant: '<S183>/Constant4'
       *  Constant: '<S183>/Constant7'
       *  Logic: '<S183>/Logical Operator2'
       *  Sum: '<S183>/Sum1'
       */
      if ((localR) || (localLogicalOperator)) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = (localTe + localSwitch2) + 2.220446049E-016F;
      }

      /* RelationalOperator: '<S183>/Relational Operator2' incorporates:
       *  MinMax: '<S183>/MinMax1'
       */
      localLogicalOperator = (localfractionTmp_0d >= (((Float32)
        UsThrM_tiDlyThrStab_C) * 9.999999776E-003F));

      /* UnitDelay: '<S197>/Unit Delay' */
      localR = UsThrMT_DWork.UnitDelay_DSTATE_esp;

      /* Switch: '<S183>/Switch' incorporates:
       *  Constant: '<S183>/Constant5'
       *  Logic: '<S183>/Logical Operator1'
       *  Logic: '<S192>/Logical Operator'
       *  Logic: '<S192>/Logical Operator1'
       */
      if (!localNot_0) {
        localR = ((localLogicalOperator) && (!localR));
      } else {
        localR = TRUE;
      }

      /* Memory: '<S187>/Memory' */
      localMemory = UsThrMT_DWork.Memory_PreviousInput;

      /* CombinatorialLogic: '<S187>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_p != 0);
        rowidx = (rowidx << 1) + (UInt32)(localR != 0);
        rowidx = (rowidx << 1) + (UInt32)(localMemory != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic[0] = UsThrMT_ConstP.Logic_table[rowidx];
        localLogic[1] = UsThrMT_ConstP.Logic_table[rowidx + 8];
      }

      /* Update for UnitDelay: '<S184>/Unit Delay' */
      UsThrMT_DWork.UnitDelay_DSTATE_p =
        UsThrMT_B.TmpSignalConversionAtThrLrn_rOp;

      /* Update for UnitDelay: '<S188>/Unit Delay' */
      UsThrMT_DWork.UnitDelay_DSTATE = localfractionTmp_0d;

      /* Update for UnitDelay: '<S189>/Unit Delay' */
      UsThrMT_DWork.UnitDelay_DSTATE_e = localNot_0;

      /* Update for UnitDelay: '<S196>/Unit Delay' */
      UsThrMT_DWork.UnitDelay_DSTATE_es = UsThrM_bAcvUpdAirExtPresTrb;

      /* Update for UnitDelay: '<S197>/Unit Delay' */
      UsThrMT_DWork.UnitDelay_DSTATE_esp = localLogicalOperator;

      /* Update for Memory: '<S187>/Memory' */
      UsThrMT_DWork.Memory_PreviousInput = localLogic[0];

      /* end of Outputs for SubSystem: '<S170>/F03_Turbo_low_load_condition' */

      /* Logic: '<S170>/Logical Operator2' */
      UsThrM_bAcvTrbUpdAirExtPres = ((UsThrM_bAcvUpdAirExtPresIdl ||
        UsThrM_bAcvUpdAirExtPresCut) || (localLogic[1]));

      /* end of Outputs for SubSystem: '<S163>/F01_Turbo_conditions' */

      /* Outputs for enable SubSystem: '<S163>/F02_Atmospheric_pressure_update' incorporates:
       *  EnablePort: '<S171>/Enable'
       *  Logic: '<S163>/Logical Operator1'
       *  Logic: '<S163>/Logical Operator4'
       *
       * Block requirements for '<S163>/F02_Atmospheric_pressure_update':
       *  1. SubSystem "F02_Atmospheric_pressure_update" !Trace_To : VEMS_R_11_04300_028.01 ;
       */
      if (UsThrM_bAcvTrbUpdAirExtPres && (!localNot_p)) {
        /* Sum: '<S171>/Sum1' */
        localrtmax = ((UsThrMT_B.TmpSignalConversionAtUsThrM_p_i +
                       UsThrMT_B.TmpSignalConversionAtUsThrM_pLo) +
                      UsThrMT_B.TmpSignalConversionAtUsThrM_p_a) +
          UsThrMT_B.TmpSignalConversionAtUsThrM_p_k;
        if (localrtmax <= 0) {
          UsThrMT_B.Merge = 0U;
        } else if (localrtmax > 65535) {
          UsThrMT_B.Merge = MAX_uint16_T;
        } else {
          UsThrMT_B.Merge = (UInt16)localrtmax;
        }
      }

      /* end of Outputs for SubSystem: '<S163>/F02_Atmospheric_pressure_update' */

      /* Outputs for enable SubSystem: '<S163>/F03_Atmospheric_pressure_default_value' incorporates:
       *  EnablePort: '<S172>/Enable'
       *
       * Block requirements for '<S163>/F03_Atmospheric_pressure_default_value':
       *  1. SubSystem "F03_Atmospheric_pressure_default_value" !Trace_To : VEMS_R_11_04300_029.01 ;
       */
      if (localNot_p) {
        /* Constant: '<S172>/UsThrM_pAirExtDft_C' */
        UsThrMT_B.Merge = UsThrM_pAirExtDft_C;
      }

      /* end of Outputs for SubSystem: '<S163>/F03_Atmospheric_pressure_default_value' */
    }

    /* end of Outputs for SubSystem: '<S157>/F03_Running_engine_turbo' */
  }

  /* end of Outputs for SubSystem: '<S23>/F02_Atmospheric_pressure_estimation' */

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pAirExt_prevOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt_INPUT'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsT_j);

  /* DataTypeConversion: '<S23>/DTC19' */
  UsThrM_pAirExt_prev = ((Float32)localTmpSignalConversionAtUsT_j) * 8.0F;

  /* Outputs for atomic SubSystem: '<S23>/F03_Atmospheric_pressure_filtering' *
   * Block requirements for '<S23>/F03_Atmospheric_pressure_filtering':
   *  1. SubSystem "F03_Atmospheric_pressure_filtering" !Trace_To : VEMS_R_11_04300_030.01 ;
   */

  /* DataTypeConversion: '<S144>/Data Type Conversion' */
  localDataTypeConversion = ((Float32)UsThrMT_B.Merge) * 8.0F;

  /* Switch: '<S144>/Switch' incorporates:
   *  Constant: '<S144>/ConstVal'
   *  Constant: '<S144>/Ext_stStall_SC'
   *  Constant: '<S144>/UsThrM_rFilPresAirExt_C'
   *  RelationalOperator: '<S144>/Relational Operator'
   */
  if (UsThrMT_B.TmpSignalConversionAtEng_stEruO == Ext_stStall_SC) {
    localSwitch_p = MAX_uint16_T;
  } else {
    localSwitch_p = UsThrM_rFilPresAirExt_C;
  }

  /* Outputs for atomic SubSystem: '<S199>/filtrage' */
  UsThrMT_filtrage(localDataTypeConversion, UsThrM_pAirExt_prev, localSwitch_p,
                   &UsThrMT_B.filtrage);

  /* end of Outputs for SubSystem: '<S199>/filtrage' */

  /* end of Outputs for SubSystem: '<S23>/F03_Atmospheric_pressure_filtering' */

  /* DataTypeConversion: '<S149>/OutDTConv' incorporates:
   *  Constant: '<S149>/offset'
   *  Constant: '<S149>/offset1'
   *  Constant: '<S149>/one_on_slope'
   *  Product: '<S149>/Product4'
   *  Sum: '<S149>/Add1'
   *  Sum: '<S149>/Add2'
   */
  localfractionTmp_0d = (0.125F * UsThrMT_B.filtrage.Sum1) + 0.5F;
  if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      UsThrMT_B.OutDTConv = (UInt16)localfractionTmp_0d;
    } else {
      UsThrMT_B.OutDTConv = 0U;
    }
  } else {
    UsThrMT_B.OutDTConv = MAX_uint16_T;
  }

  /* S-Function (NvRamWriteAccess): '<S23>/EepromWriteAccess' */
  UsThrMT_sNV_Z1_CALIB_16BIT.UsThrM_pAirExt_NV = UsThrMT_B.OutDTConv;

  /* SignalConversion: '<S150>/copy' */
  UsThrM_pAirExtRaw_IRV_MP = UsThrMT_B.Merge;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S150>/autosar_testpoint1' */

  /* S-Function Block: <S150>/autosar_testpoint1 */

  /* SignalConversion: '<S151>/copy' */
  UsThrM_ctUpdAirExtPresStall = UsThrMT_B.Merge1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S151>/autosar_testpoint1' */

  /* S-Function Block: <S151>/autosar_testpoint1 */

  /* SignalConversion: '<S152>/copy' */
  UsThrM_ctUpdAirExtPresRun_IRV_MP = UsThrMT_B.Merge2;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S152>/autosar_testpoint1' */

  /* S-Function Block: <S152>/autosar_testpoint1 */

  /* SignalConversion: '<S153>/copy' */
  UsThrM_ctUpdAirExtPresIdl_IRV_MP = UsThrMT_B.Merge3;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S153>/autosar_testpoint1' */

  /* S-Function Block: <S153>/autosar_testpoint1 */

  /* SignalConversion: '<S154>/copy' */
  UsThrM_ctUpdAirExtPresCut_IRV_MP = UsThrMT_B.Merge4;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S154>/autosar_testpoint1' */

  /* S-Function Block: <S154>/autosar_testpoint1 */

  /* Outputs for atomic SubSystem: '<S23>/F04_Altimetric_factor' *
   * Block requirements for '<S23>/F04_Altimetric_factor':
   *  1. SubSystem "F04_Altimetric_factor" !Trace_To : VEMS_R_11_04300_031.01 ;
   */

  /* Product: '<S203>/Divide' incorporates:
   *  Constant: '<S145>/Air_pAirExtRef_C'
   *  DataTypeConversion: '<S145>/DTC6'
   */
  localfractionTmp_0d = (((Float32)Air_pAirExtRef_C) * 8.0F) /
    UsThrMT_B.filtrage.Sum1;

  /* Outputs for atomic SubSystem: '<S203>/If Action Subsystem3' */

  /* Switch: '<S205>/Switch1' incorporates:
   *  Constant: '<S205>/Constant1'
   *  Constant: '<S205>/Constant2'
   *  Constant: '<S205>/Constant3'
   *  Logic: '<S205>/Logical Operator1'
   *  RelationalOperator: '<S205>/Relational Operator'
   *  RelationalOperator: '<S205>/Relational Operator1'
   *  RelationalOperator: '<S205>/Relational Operator3'
   */
  if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
        3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
    localfractionTmp_0d = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S203>/If Action Subsystem3' */

  /* Switch: '<S145>/Switch1' incorporates:
   *  Constant: '<S145>/ConstVal'
   *  Constant: '<S145>/UsThrM_bAcvAltiCor_C'
   *  Constant: '<S202>/offset'
   *  Constant: '<S202>/offset1'
   *  Constant: '<S202>/one_on_slope'
   *  DataTypeConversion: '<S202>/OutDTConv'
   *  Product: '<S202>/Product4'
   *  Sum: '<S202>/Add1'
   *  Sum: '<S202>/Add2'
   */
  if (UsThrM_bAcvAltiCor_C) {
    localfractionTmp_0d = (32768.0F * localfractionTmp_0d) + 0.5F;
    if (localfractionTmp_0d < 65536.0F) {
      if (localfractionTmp_0d >= 0.0F) {
        localTmpSignalConversionAtUsThr = (UInt16)localfractionTmp_0d;
      } else {
        localTmpSignalConversionAtUsThr = 0U;
      }
    } else {
      localTmpSignalConversionAtUsThr = MAX_uint16_T;
    }
  } else {
    localTmpSignalConversionAtUsThr = 32768U;
  }

  /* end of Outputs for SubSystem: '<S23>/F04_Altimetric_factor' */

  /* SignalConversion: '<S23>/Signal Conversion1' */
  locallocalTmpSignalConversionAt = UsThrMT_B.Merge;

  /* SignalConversion: '<S23>/Signal Conversion10' */
  localMerge1_d = UsThrMT_B.Merge2;

  /* SignalConversion: '<S23>/Signal Conversion2' */
  localMerge1 = UsThrMT_B.Merge1;

  /* SignalConversion: '<S23>/Signal Conversion4' */
  localTmpSignalConversionAtUsT_j = UsThrMT_B.Merge3;

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresCut_irvInport2' incorporates:
   *  SignalConversion: '<S23>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_UsThrMT_010_TEV_UsThrM_ctUpdAirExtPresCut_irv(UsThrMT_B.Merge4);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresIdl_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_010_TEV_UsThrM_ctUpdAirExtPresIdl_irv
    (localTmpSignalConversionAtUsT_j);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresRun_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_010_TEV_UsThrM_ctUpdAirExtPresRun_irv(localMerge1_d);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresStall_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_010_TEV_UsThrM_ctUpdAirExtPresStall_irv(localMerge1);

  /* Switch: '<S155>/Switch' incorporates:
   *  Constant: '<S155>/Byp_Fonction_SC'
   *  Constant: '<S155>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsThr = UsThrM_facPresAltiCor_B;
  }

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_facPresAltiCorInport2' */
  Rte_Write_P_UsThrM_facPresAltiCor_UsThrM_facPresAltiCor
    (localTmpSignalConversionAtUsThr);

  /* Switch: '<S156>/Switch' incorporates:
   *  Constant: '<S156>/Byp_Fonction_SC'
   *  Constant: '<S156>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsThr = UsThrM_pAirExt_B;
  } else {
    localTmpSignalConversionAtUsThr = UsThrMT_B.OutDTConv;
  }

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pAirExtInport2' */
  Rte_Write_P_UsThrM_pAirExt_UsThrM_pAirExt(localTmpSignalConversionAtUsThr);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtUsThrM_pAirExtRaw_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_010_TEV_UsThrM_pAirExtRaw_irv
    (locallocalTmpSignalConversionAt);
}

/* Output and update for exported function: RE_UsThrMT_011_TEV */
void RE_UsThrMT_011_TEV(void)
{
  Float32 localSum1_b;
  Float32 localSwitch2_p;
  Float32 localAdd2_o;
  Boolean localRelationalOperator_o;
  UInt8 localTmpSignalConversionAtEng_s;
  UInt16 localTmpSignalConversionAtUsT_a;
  UInt16 localTmpSignalConversionAtUsT_b;
  UInt16 locallocalTmpSignalConversionAt;

  /* S-Function (fcncallgen): '<S9>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Manage_pressure_observer'
   *
   * Block requirements for '<S1>/F02_Manage_pressure_observer':
   *  1. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_032.01 ;
   *  2. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_033.01 ;
   *  3. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_037.01 ;
   *  4. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_065.01 ;
   *  5. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_076.01 ;
   *  6. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_078.01 ;
   *  7. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  8. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_133.01 ;
   *  9. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_086.01 ;
   *  10. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_096.01 ;
   *  11. SubSystem "F02_Manage_pressure_observer" !Trace_To : VEMS_R_11_04300_111.01 ;
   */

  /* SignalConversion: '<S18>/TmpSignal ConversionAtUsThrM_pUsThrCorPrevOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor_INPUT'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor((&(UsThrM_pUsThrCorPrev)));

  /* DataTypeConversion: '<S18>/DTC2' */
  localSum1_b = ((Float32)UsThrM_pUsThrCorPrev) * 8.0F;

  /* Sum: '<S18>/Sum' incorporates:
   *  Constant: '<S18>/UsThrM_pDeUsThr_C'
   *  Constant: '<S18>/UsThrM_tiSampleFast_SC'
   *  DataTypeConversion: '<S18>/DTC4'
   *  DataTypeConversion: '<S18>/DTC5'
   *  Product: '<S64>/Divide'
   */
  localSwitch2_p = ((((Float32)UsThrM_pDeUsThr_C) * 250.0F) * (((Float32)
    UsThrM_tiSampleFast_SC) * 1.000000047E-003F)) + localSum1_b;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt_INPUT'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtUsThrM_pLossAirFilOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pLossAirFil_INPUT'
   */
  Rte_Read_R_UsThrM_pLossAirFil_UsThrM_pLossAirFil
    (&localTmpSignalConversionAtUsT_a);

  /* Sum: '<S18>/Add' incorporates:
   *  DataTypeConversion: '<S18>/DTC6'
   *  DataTypeConversion: '<S18>/DTC7'
   */
  localAdd2_o = (Float32)((locallocalTmpSignalConversionAt << 3) -
    (localTmpSignalConversionAtUsT_a << 3));

  /* RelationalOperator: '<S18>/Relational Operator' */
  localRelationalOperator_o = (((Float32d)localAdd2_o) > ((Float32d)localSum1_b));

  /* Sum: '<S18>/Sum1' incorporates:
   *  Constant: '<S18>/UsThrM_pDeUsThr_C_1'
   *  Constant: '<S18>/UsThrM_tiSampleFast_SC_1'
   *  DataTypeConversion: '<S18>/DTC1'
   *  DataTypeConversion: '<S18>/DTC3'
   *  Product: '<S63>/Divide'
   */
  localSum1_b -= (((Float32)UsThrM_pDeUsThr_C) * 250.0F) * (((Float32)
    UsThrM_tiSampleFast_SC) * 1.000000047E-003F);

  /* Switch: '<S18>/Switch1' incorporates:
   *  MinMax: '<S18>/MinMax'
   *  MinMax: '<S18>/MinMax1'
   */
  if (localRelationalOperator_o) {
    localSwitch2_p = rt_MINf(localSwitch2_p, localAdd2_o);
  } else {
    localSwitch2_p = rt_MAXf(localAdd2_o, localSum1_b);
  }

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* Switch: '<S18>/Switch2' incorporates:
   *  Constant: '<S18>/Ext_stRun_SC'
   *  RelationalOperator: '<S18>/Relational Operator1'
   */
  if (localTmpSignalConversionAtEng_s != Ext_stRun_SC) {
    localSwitch2_p = localAdd2_o;
  }

  /* DataTypeConversion: '<S61>/OutDTConv' incorporates:
   *  Constant: '<S61>/offset'
   *  Constant: '<S61>/offset1'
   *  Constant: '<S61>/one_on_slope'
   *  Product: '<S61>/Product4'
   *  Sum: '<S61>/Add1'
   *  Sum: '<S61>/Add2'
   */
  localSum1_b = (0.125F * localSwitch2_p) + 0.5F;
  if (localSum1_b >= 0.0F) {
    locallocalTmpSignalConversionAt = (UInt16)localSum1_b;
  } else {
    locallocalTmpSignalConversionAt = 0U;
  }

  /* DataStoreWrite: '<S18>/UsThrM_pUsThrAtmCor_MP_DSW' */
  UsThrM_pUsThrAtmCor_MP = locallocalTmpSignalConversionAt;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtUsThrM_pUsThrTrbCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrTrbCor_INPUT'
   */
  Rte_Read_R_UsThrM_pUsThrTrbCor_UsThrM_pUsThrTrbCor
    (&localTmpSignalConversionAtUsT_b);

  /* Switch: '<S18>/Switch3' incorporates:
   *  Constant: '<S18>/Ext_bEngTrbMod_SC'
   */
  if (Ext_bEngTrbMod_SC) {
    locallocalTmpSignalConversionAt = localTmpSignalConversionAtUsT_b;
  }

  /* Switch: '<S62>/Switch' incorporates:
   *  Constant: '<S62>/Byp_Fonction_SC'
   *  Constant: '<S62>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversionAt = UsThrM_pUsThrCor_B;
  }

  /* SignalConversion: '<S18>/TmpSignal ConversionAtUsThrM_pUsThrCorInport2' */
  Rte_Write_P_UsThrM_pUsThrCor_UsThrM_pUsThrCor(locallocalTmpSignalConversionAt);
}

/* Initial conditions for exported function: RE_UsThrMT_007_TEV */
void RE_UsThrMT_007_TEV_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S10>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/F02_EngCtlMod_calculation'
   *
   * Block requirements for '<S1>/F02_EngCtlMod_calculation':
   *  1. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_059.02 ;
   *  2. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_060.02 ;
   *  3. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_062.03 ;
   *  4. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_081.01 ;
   *  5. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_082.01 ;
   *  6. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_083.01 ;
   *  7. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_084.01 ;
   *  8. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_129.02 ;
   *  9. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_091.01 ;
   *  10. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_098.01 ;
   *  11. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_144.01 ;
   *  12. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_145.01 ;
   *  13. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_103.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S17>/F05_Engine_air_pressure_mode' *
   * Block requirements for '<S17>/F05_Engine_air_pressure_mode':
   *  1. SubSystem "F05_Engine_air_pressure_mode" !Trace_To : VEMS_R_11_04300_062.03 ;
   */

  /* InitializeConditions for UnitDelay: '<S58>/UnitDelay' */
  UsThrMT_DWork.UnitDelay = TRUE;

  /* end of InitializeConditions for SubSystem: '<S17>/F05_Engine_air_pressure_mode' */
}

/* Output and update for exported function: RE_UsThrMT_007_TEV */
void RE_UsThrMT_007_TEV(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_c;
  Boolean localRelationalOperator1_a;
  Boolean localLogic_p[2];
  Boolean localUnitDelay1;
  Float32 localExt_nEng_UsThrM_nEng_A_9_f;
  Float32 localfractionTmp_0d;
  UInt32 localExt_nEng_UsThrM_nEng_A_9_k;
  Float32 localInterpolationUsingPrelooku;
  Float32 localAfuA_rEthWoutExct_UsThrM_r;
  UInt32 localAfuA_rEthWoutExct_UsThrM_c;
  Boolean localSwitch2_h;
  UInt16 localTmpSignalConversionAtUsT_p;
  UInt8 localTmpSignalConversionAtAfuA_;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S10>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_EngCtlMod_calculation'
   *
   * Block requirements for '<S1>/F02_EngCtlMod_calculation':
   *  1. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_059.02 ;
   *  2. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_060.02 ;
   *  3. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_062.03 ;
   *  4. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_081.01 ;
   *  5. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_082.01 ;
   *  6. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_083.01 ;
   *  7. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_084.01 ;
   *  8. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_129.02 ;
   *  9. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_091.01 ;
   *  10. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_098.01 ;
   *  11. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_144.01 ;
   *  12. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_145.01 ;
   *  13. SubSystem "F02_EngCtlMod_calculation" !Trace_To : VEMS_R_11_04300_103.01 ;
   */

  /* SignalConversion: '<S17>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&UsThrMT_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtAfuA_rEthWoutExctOutport2' incorporates:
   *  Inport: '<Root>/AfuA_rEthWoutExct'
   */
  Rte_Read_R_AfuA_rEthWoutExct_AfuA_rEthWoutExct
    (&localTmpSignalConversionAtAfuA_);

  /* Outputs for atomic SubSystem: '<S17>/F01_Index_maps_calculation' *
   * Block requirements for '<S17>/F01_Index_maps_calculation':
   *  1. SubSystem "F01_Index_maps_calculation" !Trace_To : VEMS_R_11_04300_146.01 ;
   */

  /* PreLookup: '<S46>/Prelookup' */
  localExt_nEng_UsThrM_nEng_A_9_k = plook_u32u16f_binc
    (UsThrMT_B.TmpSignalConversionAtExt_nEngOu, (&(UsThrM_nEng_A[0])), 8U,
     &localExt_nEng_UsThrM_nEng_A_9_f);

  /* PreLookup: '<S47>/Prelookup' */
  localAfuA_rEthWoutExct_UsThrM_c = plook_u32u8f_binc
    (localTmpSignalConversionAtAfuA_, (&(UsThrM_rEthWoutExct_A[0])), 7U,
     &localAfuA_rEthWoutExct_UsThrM_r);

  /* end of Outputs for SubSystem: '<S17>/F01_Index_maps_calculation' */

  /* Outputs for atomic SubSystem: '<S17>/F02_Pressure_threshlod_Gsl_table' *
   * Block requirements for '<S17>/F02_Pressure_threshlod_Gsl_table':
   *  1. SubSystem "F02_Pressure_threshlod_Gsl_table" !Trace_To : VEMS_R_11_04300_147.01 ;
   */

  /* Interpolation_n-D: '<S48>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localExt_nEng_UsThrM_nEng_A_9_f;
  UsThrM_pDsThrMesThdGsl = intrp1d_iu16p3ff_u32f_l_s
    (localExt_nEng_UsThrM_nEng_A_9_k, localfractionTmp_0d,
     (&(UsThrM_pDsThrMesThd_T[0])));

  /* end of Outputs for SubSystem: '<S17>/F02_Pressure_threshlod_Gsl_table' */

  /* If: '<S17>/If' incorporates:
   *  ActionPort: '<S41>/Action Port'
   *  ActionPort: '<S42>/Action Port'
   *  Constant: '<S17>/UsThrM_bAcvEth_C'
   *  SubSystem: '<S17>/F03_Downstream_throttle_pressure_threshlod_Afu'
   *  SubSystem: '<S17>/F04_Downstream_throttle_pressure_threshlod_Gsl'
   *
   * Block requirements for '<S17>/F03_Downstream_throttle_pressure_threshlod_Afu':
   *  1. SubSystem "F03_Downstream_throttle_pressure_threshlod_Afu" !Trace_To : VEMS_R_11_04300_148.01 ;
   *
   * Block requirements for '<S17>/F04_Downstream_throttle_pressure_threshlod_Gsl':
   *  1. SubSystem "F04_Downstream_throttle_pressure_threshlod_Gsl" !Trace_To : VEMS_R_11_04300_149.01 ;
   */
  if (UsThrM_bAcvEth_C) {
    /* Interpolation_n-D: '<S51>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_nEng_UsThrM_nEng_A_9_f;
    localInterpolationUsingPrelooku = intrp1d_iu16p3ff_u32f_l_s
      (localExt_nEng_UsThrM_nEng_A_9_k, localfractionTmp_0d,
       (&(UsThrM_pDsThrMesThdAfu_T[0])));

    /* DataStoreWrite: '<S41>/UsThrM_pDsThrMesThdAfu_MP_DSW' incorporates:
     *  Constant: '<S50>/offset'
     *  Constant: '<S50>/offset1'
     *  Constant: '<S50>/one_on_slope'
     *  DataTypeConversion: '<S50>/OutDTConv'
     *  Product: '<S50>/Product4'
     *  Sum: '<S50>/Add1'
     *  Sum: '<S50>/Add2'
     */
    localfractionTmp_0d = (0.125F * localInterpolationUsingPrelooku) + 0.5F;
    if (localfractionTmp_0d < 65536.0F) {
      if (localfractionTmp_0d >= 0.0F) {
        UsThrM_pDsThrMesThdAfu_MP = (UInt16)localfractionTmp_0d;
      } else {
        UsThrM_pDsThrMesThdAfu_MP = 0U;
      }
    } else {
      UsThrM_pDsThrMesThdAfu_MP = MAX_uint16_T;
    }

    /* Interpolation_n-D: '<S52>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localAfuA_rEthWoutExct_UsThrM_r;
    localfractionTmp_0d = intrp1d_iu8n7ff_u32f_l_ns
      (localAfuA_rEthWoutExct_UsThrM_c, localfractionTmp_0d,
       (&(UsThrM_rEthWoutExctCor_T[0])));

    /* DataStoreWrite: '<S41>/UsThrM_rEthWoutExctCor_MP_DSW' incorporates:
     *  Constant: '<S49>/offset'
     *  Constant: '<S49>/offset1'
     *  Constant: '<S49>/one_on_slope'
     *  DataTypeConversion: '<S49>/OutDTConv'
     *  Product: '<S49>/Product4'
     *  Sum: '<S49>/Add1'
     *  Sum: '<S49>/Add2'
     */
    localtmp = (128.0F * localfractionTmp_0d) + 0.5F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        UsThrM_rEthWoutExctCor_MP = (UInt8)localtmp;
      } else {
        UsThrM_rEthWoutExctCor_MP = 0U;
      }
    } else {
      UsThrM_rEthWoutExctCor_MP = MAX_uint8_T;
    }

    /* Sum: '<S41>/Sum' incorporates:
     *  Constant: '<S41>/ConstVal'
     *  Product: '<S53>/Divide'
     *  Product: '<S54>/Divide'
     *  Sum: '<S41>/Sum1'
     */
    UsThrM_pDsThrMesThd = ((1.0F - localfractionTmp_0d) * UsThrM_pDsThrMesThdGsl)
      + (localfractionTmp_0d * localInterpolationUsingPrelooku);
  } else {
    /* SignalConversion: '<S42>/Signal Conversion' */
    UsThrM_pDsThrMesThd = UsThrM_pDsThrMesThdGsl;
  }

  /* SignalConversion: '<S17>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor_INPUT'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_pDs);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtUsThrM_facPresAltiCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_facPresAltiCor_INPUT'
   */
  Rte_Read_R_UsThrM_facPresAltiCor_UsThrM_facPresAltiCor
    (&localTmpSignalConversionAtUsT_p);

  /* Outputs for atomic SubSystem: '<S17>/F05_Engine_air_pressure_mode' *
   * Block requirements for '<S17>/F05_Engine_air_pressure_mode':
   *  1. SubSystem "F05_Engine_air_pressure_mode" !Trace_To : VEMS_R_11_04300_062.03 ;
   */

  /* DataTypeConversion: '<S43>/DTConv_Single_To_UFix_2' */
  localfractionTmp_0d = ((Float32)UsThrMT_B.TmpSignalConversionAtUsThrM_pDs) *
    8.0F;

  /* Product: '<S57>/Divide' incorporates:
   *  DataTypeConversion: '<S43>/DTConv_Single_To_UFix_1'
   */
  localInterpolationUsingPrelooku = UsThrM_pDsThrMesThd / (((Float32)
    localTmpSignalConversionAtUsT_p) * 3.051757813E-005F);

  /* Outputs for atomic SubSystem: '<S57>/If Action Subsystem3' */

  /* Switch: '<S60>/Switch1' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Constant: '<S60>/Constant2'
   *  Constant: '<S60>/Constant3'
   *  Logic: '<S60>/Logical Operator1'
   *  RelationalOperator: '<S60>/Relational Operator'
   *  RelationalOperator: '<S60>/Relational Operator1'
   *  RelationalOperator: '<S60>/Relational Operator3'
   */
  if (((localInterpolationUsingPrelooku != localInterpolationUsingPrelooku) ||
       (localInterpolationUsingPrelooku > 3.000000005E+038F)) ||
      (-3.000000005E+038F > localInterpolationUsingPrelooku)) {
    localInterpolationUsingPrelooku = 101300.0F;
  }

  /* end of Outputs for SubSystem: '<S57>/If Action Subsystem3' */

  /* RelationalOperator: '<S55>/Relational Operator' */
  localRelationalOperator_c = (localfractionTmp_0d >=
    localInterpolationUsingPrelooku);

  /* RelationalOperator: '<S55>/Relational Operator1' incorporates:
   *  Constant: '<S43>/UsThrM_pDsThrMesHys_C'
   *  DataTypeConversion: '<S43>/DTConv_Single_To_UFix_3'
   *  Sum: '<S43>/Sum'
   */
  localRelationalOperator1_a = (localfractionTmp_0d <=
    (localInterpolationUsingPrelooku - (((Float32)UsThrM_pDsThrMesHys_C) * 8.0F)));

  /* UnitDelay: '<S58>/UnitDelay' */
  localUnitDelay1 = UsThrMT_DWork.UnitDelay;

  /* CombinatorialLogic: '<S58>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_c != 0);
    rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_a != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_p[0] = UsThrMT_ConstP.Logic_table_i[rowidx];
    localLogic_p[1] = UsThrMT_ConstP.Logic_table_i[rowidx + 8];
  }

  /* UnitDelay: '<S58>/UnitDelay1' */
  localUnitDelay1 = UsThrMT_DWork.UnitDelay_h;

  /* Switch: '<S58>/Switch2' incorporates:
   *  Constant: '<S58>/NotCLR3'
   */
  if (localUnitDelay1) {
    localSwitch2_h = localLogic_p[0];
  } else {
    localSwitch2_h = TRUE;
  }

  /* Sum: '<S56>/Add2' incorporates:
   *  Constant: '<S56>/offset'
   *  Constant: '<S56>/offset1'
   *  Constant: '<S56>/one_on_slope'
   *  Product: '<S56>/Product4'
   *  Sum: '<S56>/Add1'
   */
  localfractionTmp_0d = (0.125F * localInterpolationUsingPrelooku) + 0.5F;

  /* Update for UnitDelay: '<S58>/UnitDelay' */
  UsThrMT_DWork.UnitDelay = localSwitch2_h;

  /* Update for UnitDelay: '<S58>/UnitDelay1' incorporates:
   *  Constant: '<S58>/NotCLR2'
   */
  UsThrMT_DWork.UnitDelay_h = TRUE;

  /* end of Outputs for SubSystem: '<S17>/F05_Engine_air_pressure_mode' */

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Byp_Fonction_SC'
   *  Constant: '<S45>/Int_BypC'
   *  Logic: '<S43>/Logical Operator'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localSwitch2_h = UsThrM_bAcvAirExtCtlMod_B;
  } else {
    localSwitch2_h = !localSwitch2_h;
  }

  /* SignalConversion: '<S17>/TmpSignal ConversionAtUsThrM_bAcvAirExtCtlModInport2' */
  Rte_Write_P_UsThrM_bAcvAirExtCtlMod_UsThrM_bAcvAirExtCtlMod(localSwitch2_h);

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Byp_Fonction_SC'
   *  Constant: '<S44>/Int_BypC'
   *  DataTypeConversion: '<S56>/OutDTConv'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_p = UsThrM_pDsThrAcvAirExtCtlMod_B;
  } else if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      localTmpSignalConversionAtUsT_p = (UInt16)localfractionTmp_0d;
    } else {
      localTmpSignalConversionAtUsT_p = 0U;
    }
  } else {
    localTmpSignalConversionAtUsT_p = MAX_uint16_T;
  }

  /* SignalConversion: '<S17>/TmpSignal ConversionAtUsThrM_pDsThrAcvAirExtCtlModInport2' */
  Rte_Write_P_UsThrM_pDsThrAcvAirExtCtlMod_UsThrM_pDsThrAcvAirExtCtlMod
    (localTmpSignalConversionAtUsT_p);
}

/* Start for exported function: RE_UsThrMT_006_TEV */
void RE_UsThrMT_006_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S11>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_PCmpr_calculation'
   *
   * Block requirements for '<S1>/F02_PCmpr_calculation':
   *  1. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_074.01 ;
   *  2. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_075.01 ;
   *  3. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_076.01 ;
   *  4. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_077.01 ;
   *  5. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_078.01 ;
   *  6. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  7. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  8. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_128.01 ;
   *  9. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_105.01 ;
   *  10. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_135.02 ;
   *  11. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_136.01 ;
   *  12. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_138.01 ;
   *  13. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_099.01 ;
   *  14. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_101.01 ;
   *  15. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_102.01 ;
   */
}

/* Output and update for exported function: RE_UsThrMT_006_TEV */
void RE_UsThrMT_006_TEV(void)
{
  /* local block i/o variables */
  Boolean localAutosarServer_p;
  Boolean localNot_n;
  Float32 localInterpolationUsingPreloo_n;
  Float32 localSwitch_i;
  Float32 localEngM_mfAirCor_UsThrM_mfAir;
  Float32 localfractionTmp_0d;
  UInt32 localEngM_mfAirCor_UsThrM_mfA_g;
  SInt16 localOutDTConv_k3;
  UInt16 localUsThrM_pDsCmpr;
  UInt16 localTmpSignalConversionAtUsT_o;
  UInt16 localTmpSignalConversionAtUs_ge;
  UInt16 localTmpSignalConversionAtUsT_l;
  Float32 localtmp;
  SInt32 localtmp_0;

  /* S-Function (fcncallgen): '<S11>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_PCmpr_calculation'
   *
   * Block requirements for '<S1>/F02_PCmpr_calculation':
   *  1. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_074.01 ;
   *  2. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_075.01 ;
   *  3. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_076.01 ;
   *  4. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_077.01 ;
   *  5. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_078.01 ;
   *  6. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  7. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  8. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_128.01 ;
   *  9. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_105.01 ;
   *  10. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_135.02 ;
   *  11. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_136.01 ;
   *  12. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_138.01 ;
   *  13. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_099.01 ;
   *  14. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_101.01 ;
   *  15. SubSystem "F02_PCmpr_calculation" !Trace_To : VEMS_R_11_04300_102.01 ;
   */

  /* SignalConversion: '<S19>/TmpSignal ConversionAtEngM_mfAirCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfAirCor'
   */
  Rte_Read_R_EngM_mfAirCor_EngM_mfAirCor
    (&UsThrMT_B.TmpSignalConversionAtEngM_mfAir);

  /* Outputs for atomic SubSystem: '<S19>/F01_CAC_and_compressor_pressure_loss' *
   * Block requirements for '<S19>/F01_CAC_and_compressor_pressure_loss':
   *  1. SubSystem "F01_CAC_and_compressor_pressure_loss" !Trace_To : VEMS_R_11_04300_139.01 ;
   */

  /* PreLookup: '<S78>/Prelookup' */
  localEngM_mfAirCor_UsThrM_mfA_g = plook_u32u16f_binc
    (UsThrMT_B.TmpSignalConversionAtEngM_mfAir, (&(UsThrM_mfAirThr_A[0])), 15U,
     &localEngM_mfAirCor_UsThrM_mfAir);

  /* Interpolation_n-D: '<S79>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localEngM_mfAirCor_UsThrM_mfAir;
  localInterpolationUsingPreloo_n = intrp1d_iu16p3ff_u32f_l_s
    (localEngM_mfAirCor_UsThrM_mfA_g, localfractionTmp_0d,
     (&(UsThrM_pDifCACAirThr_T[0])));

  /* Interpolation_n-D: '<S80>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localEngM_mfAirCor_UsThrM_mfAir;
  localfractionTmp_0d = intrp1d_is16p3ff_u32f_l_s
    (localEngM_mfAirCor_UsThrM_mfA_g, localfractionTmp_0d,
     (&(UsThrM_pDifCmprAirThr_T[0])));

  /* end of Outputs for SubSystem: '<S19>/F01_CAC_and_compressor_pressure_loss' */

  /* SignalConversion: '<S19>/TmpSignal ConversionAtUsThrM_pUsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrMesCor_INPUT'
   */
  Rte_Read_R_UsThrM_pUsThrMesCor_UsThrM_pUsThrMesCor
    (&localTmpSignalConversionAtUsT_l);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt_INPUT'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsT_o);

  /* S-Function (sfun_autosar_clientop): '<S69>/AutosarServer' */
  Rte_Call_R_FRM_bInhMes_pUsThrMes_GetFunctionPermission(&localAutosarServer_p);

  /* Logic: '<S69>/Not' */
  localNot_n = !localAutosarServer_p;

  /* SignalConversion: '<S19>/TmpSignal ConversionAtUsThrM_pLossAirFilOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pLossAirFil_INPUT'
   */
  Rte_Read_R_UsThrM_pLossAirFil_UsThrM_pLossAirFil
    (&localTmpSignalConversionAtUs_ge);

  /* Outputs for atomic SubSystem: '<S19>/F02_Throttle_upstream_pressure' *
   * Block requirements for '<S19>/F02_Throttle_upstream_pressure':
   *  1. SubSystem "F02_Throttle_upstream_pressure" !Trace_To : VEMS_R_11_04300_140.01 ;
   */

  /* Switch: '<S66>/Switch' incorporates:
   *  DataTypeConversion: '<S66>/DTC1'
   *  DataTypeConversion: '<S66>/DTC2'
   *  DataTypeConversion: '<S66>/DTC3'
   *  Logic: '<S66>/Logical Operator1'
   *  Sum: '<S66>/Add'
   */
  if (!localNot_n) {
    localSwitch_i = ((Float32)localTmpSignalConversionAtUsT_l) * 8.0F;
  } else {
    localSwitch_i = (((Float32)((localTmpSignalConversionAtUsT_o << 3) -
      (localTmpSignalConversionAtUs_ge << 3))) - localfractionTmp_0d) -
      localInterpolationUsingPreloo_n;
  }

  /* end of Outputs for SubSystem: '<S19>/F02_Throttle_upstream_pressure' */

  /* DataTypeConversion: '<S70>/OutDTConv' incorporates:
   *  Constant: '<S70>/offset'
   *  Constant: '<S70>/offset1'
   *  Constant: '<S70>/one_on_slope'
   *  Product: '<S70>/Product4'
   *  Sum: '<S70>/Add1'
   *  Sum: '<S70>/Add2'
   */
  localtmp = (0.125F * localInterpolationUsingPreloo_n) + 0.5F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localTmpSignalConversionAtUsT_l = (UInt16)localtmp;
    } else {
      localTmpSignalConversionAtUsT_l = 0U;
    }
  } else {
    localTmpSignalConversionAtUsT_l = MAX_uint16_T;
  }

  /* Product: '<S71>/Product4' incorporates:
   *  Constant: '<S71>/offset'
   *  Constant: '<S71>/one_on_slope'
   *  Sum: '<S71>/Add1'
   */
  localfractionTmp_0d *= 0.125F;

  /* Switch: '<S71>/Switch1' incorporates:
   *  Constant: '<S71>/offset2'
   *  Constant: '<S71>/offset3'
   *  Constant: '<S71>/offset4'
   *  RelationalOperator: '<S71>/Relational Operator'
   *  Sum: '<S71>/Add3'
   *  Sum: '<S71>/Add4'
   */
  if (localfractionTmp_0d >= 0.0F) {
    localfractionTmp_0d += 0.5F;
  } else {
    localfractionTmp_0d -= 0.5F;
  }

  /* DataTypeConversion: '<S71>/OutDTConv' */
  if (localfractionTmp_0d < 32768.0F) {
    if (localfractionTmp_0d >= -32768.0F) {
      localOutDTConv_k3 = (SInt16)localfractionTmp_0d;
    } else {
      localOutDTConv_k3 = MIN_int16_T;
    }
  } else {
    localOutDTConv_k3 = MAX_int16_T;
  }

  /* Sum: '<S72>/Add2' incorporates:
   *  Constant: '<S72>/offset'
   *  Constant: '<S72>/offset1'
   *  Constant: '<S72>/one_on_slope'
   *  Product: '<S72>/Product4'
   *  Sum: '<S72>/Add1'
   */
  localfractionTmp_0d = (0.125F * localSwitch_i) + 0.5F;

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S73>/Byp_Fonction_SC'
   *  Constant: '<S73>/Int_BypC'
   *  Constant: '<S81>/offset'
   *  Constant: '<S81>/offset1'
   *  Constant: '<S81>/one_on_slope'
   *  DataTypeConversion: '<S81>/OutDTConv'
   *  Product: '<S81>/Product4'
   *  Sum: '<S68>/Subtract'
   *  Sum: '<S81>/Add1'
   *  Sum: '<S81>/Add2'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localUsThrM_pDsCmpr = UsThrM_pDsCmpr_B;
  } else {
    localInterpolationUsingPreloo_n = ((localSwitch_i +
      localInterpolationUsingPreloo_n) * 0.125F) + 0.5F;
    if (localInterpolationUsingPreloo_n < 65536.0F) {
      if (localInterpolationUsingPreloo_n >= 0.0F) {
        localUsThrM_pDsCmpr = (UInt16)localInterpolationUsingPreloo_n;
      } else {
        localUsThrM_pDsCmpr = 0U;
      }
    } else {
      localUsThrM_pDsCmpr = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S19>/TmpSignal ConversionAtUsThrM_pDsCmprInport2' */
  Rte_Write_P_UsThrM_pDsCmpr_UsThrM_pDsCmpr(localUsThrM_pDsCmpr);

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/Byp_Fonction_SC'
   *  Constant: '<S76>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_l = UsThrM_pLossCAC_B;
  }

  /* SignalConversion: '<S19>/TmpSignal ConversionAtUsThrM_pLossCACInport2' */
  Rte_Write_P_UsThrM_pLossCAC_UsThrM_pLossCAC(localTmpSignalConversionAtUsT_l);

  /* Switch: '<S77>/Switch' incorporates:
   *  Constant: '<S77>/Byp_Fonction_SC'
   *  Constant: '<S77>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localOutDTConv_k3 = UsThrM_pLossCmpr_B;
  }

  /* SignalConversion: '<S19>/TmpSignal ConversionAtUsThrM_pLossCmprInport2' */
  Rte_Write_P_UsThrM_pLossCmpr_UsThrM_pLossCmpr(localOutDTConv_k3);

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S75>/Byp_Fonction_SC'
   *  Constant: '<S75>/Int_BypC'
   *  Sum: '<S67>/Subtract'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_l = UsThrM_pUsCmpr_B;
  } else {
    localtmp_0 = localTmpSignalConversionAtUsT_o -
      localTmpSignalConversionAtUs_ge;
    if (localtmp_0 <= 0) {
      localTmpSignalConversionAtUsT_l = 0U;
    } else {
      localTmpSignalConversionAtUsT_l = (UInt16)localtmp_0;
    }
  }

  /* SignalConversion: '<S19>/TmpSignal ConversionAtUsThrM_pUsCmprInport2' */
  Rte_Write_P_UsThrM_pUsCmpr_UsThrM_pUsCmpr(localTmpSignalConversionAtUsT_l);

  /* Switch: '<S74>/Switch' incorporates:
   *  Constant: '<S74>/Byp_Fonction_SC'
   *  Constant: '<S74>/Int_BypC'
   *  DataTypeConversion: '<S72>/OutDTConv'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_l = UsThrM_pUsThrTrbCor_B;
  } else if (localfractionTmp_0d < 65536.0F) {
    if (localfractionTmp_0d >= 0.0F) {
      localTmpSignalConversionAtUsT_l = (UInt16)localfractionTmp_0d;
    } else {
      localTmpSignalConversionAtUsT_l = 0U;
    }
  } else {
    localTmpSignalConversionAtUsT_l = MAX_uint16_T;
  }

  /* SignalConversion: '<S19>/TmpSignal ConversionAtUsThrM_pUsThrTrbCorInport2' */
  Rte_Write_P_UsThrM_pUsThrTrbCor_UsThrM_pUsThrTrbCor
    (localTmpSignalConversionAtUsT_l);
}

/* Start for exported function: RE_UsThrMT_002_TEV */
void RE_UsThrMT_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S12>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_PresSenAdj_SdlFast'
   *
   * Block requirements for '<S1>/F02_PresSenAdj_SdlFast':
   *  1. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_039.01 ;
   *  2. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_040.01 ;
   *  3. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_042.01 ;
   *  4. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_063.01 ;
   *  5. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_064.01 ;
   *  6. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_065.01 ;
   *  7. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_066.01 ;
   *  8. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  9. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_124.01 ;
   *  10. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_113.02 ;
   *  11. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_114.02 ;
   *  12. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_115.02 ;
   *  13. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_116.02 ;
   *  14. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_117.02 ;
   *  15. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_104.01 ;
   *  16. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_086.01 ;
   */
}

/* Output and update for exported function: RE_UsThrMT_002_TEV */
void RE_UsThrMT_002_TEV(void)
{
  /* local block i/o variables */
  Float32 localDTC4_j;
  Float32 localDTC1_n;
  Float32 localDTC2_b;
  UInt16 localOutDTConv_mg;
  UInt16 localOutDTConv_p;
  UInt16 localOutDTConv_b;
  Boolean localAutosarServer_j;
  Boolean localNot_k;
  Float32 localMerge;
  Float32 localMerge1_b;
  Float32 localMerge2;
  UInt8 localTmpSignalConversionAtEng_m;
  UInt16 localTmpSignalConversionAtExt_l;
  UInt16 localTmpSignalConversionAtEx_ir;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localUsThrM_tiTmrDifPres_irv_b;
  UInt16 localUsThrM_pUsThrMesSIFil_ir_o;

  /* S-Function (fcncallgen): '<S12>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_PresSenAdj_SdlFast'
   *
   * Block requirements for '<S1>/F02_PresSenAdj_SdlFast':
   *  1. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_039.01 ;
   *  2. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_040.01 ;
   *  3. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_042.01 ;
   *  4. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_063.01 ;
   *  5. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_064.01 ;
   *  6. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_065.01 ;
   *  7. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_066.01 ;
   *  8. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  9. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_124.01 ;
   *  10. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_113.02 ;
   *  11. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_114.02 ;
   *  12. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_115.02 ;
   *  13. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_116.02 ;
   *  14. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_117.02 ;
   *  15. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_104.01 ;
   *  16. SubSystem "F02_PresSenAdj_SdlFast" !Trace_To : VEMS_R_11_04300_086.01 ;
   */

  /* SignalConversion: '<S20>/TmpSignal ConversionAtExt_pAirExtMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_pAirExtMesSI'
   */
  Rte_Read_R_Ext_pAirExtMesSI_Ext_pAirExtMesSI(&localTmpSignalConversionAtExt_l);

  /* DataTypeConversion: '<S20>/DTC4' */
  localDTC4_j = ((Float32)localTmpSignalConversionAtExt_l) * 8.0F;

  /* SignalConversion: '<S20>/TmpSignal ConversionAtExt_pUsThrMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_pUsThrMesSI'
   */
  Rte_Read_R_Ext_pUsThrMesSI_Ext_pUsThrMesSI(&localTmpSignalConversionAtEx_ir);

  /* DataTypeConversion: '<S20>/DTC1' */
  localDTC1_n = ((Float32)localTmpSignalConversionAtEx_ir) * 8.0F;

  /* SignalConversion: '<S20>/TmpSignal ConversionAtExt_pDsThrMesSIOutport2' incorporates:
   *  Inport: '<Root>/Ext_pDsThrMesSI'
   */
  Rte_Read_R_Ext_pDsThrMesSI_Ext_pDsThrMesSI(&localTmpSignalConversionAtExt_n);

  /* DataTypeConversion: '<S20>/DTC2' */
  localDTC2_b = ((Float32)localTmpSignalConversionAtExt_n) * 8.0F;

  /* DataTypeConversion: '<S20>/DTC7' incorporates:
   *  SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pAirExtMesSIFilPrevOutport2'
   */
  UsThrM_pAirExtMesSIFilPrev = ((Float32)
    Rte_IrvRead_RE_UsThrMT_002_TEV_UsThrM_pAirExtMesSIFil_irv()) * 8.0F;

  /* DataTypeConversion: '<S20>/DTC8' incorporates:
   *  SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pUsThrMesSIFilPrevOutport2'
   */
  UsThrM_pUsThrMesSIFilPrev = ((Float32)
    Rte_IrvRead_RE_UsThrMT_002_TEV_UsThrM_pUsThrMesSIFil_irv()) * 8.0F;

  /* DataTypeConversion: '<S20>/DTC9' incorporates:
   *  SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pDsThrMesSIFilPrevOutport2'
   */
  UsThrM_pDsThrMesSIFilPrev = ((Float32)
    Rte_IrvRead_RE_UsThrMT_002_TEV_UsThrM_pDsThrMesSIFil_irv()) * 8.0F;

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_tiTmrDifPresPrevOutport2' */
  UsThrM_tiTmrDifPresPrev =
    Rte_IrvRead_RE_UsThrMT_002_TEV_UsThrM_tiTmrDifPres_irv();

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_m);

  /* S-Function (sfun_autosar_clientop): '<S87>/AutosarServer' */
  Rte_Call_R_FRM_bInhPresSenAdj_GetFunctionPermission(&localAutosarServer_j);

  /* Logic: '<S87>/Not' */
  localNot_k = !localAutosarServer_j;

  /* Outputs for atomic SubSystem: '<S20>/F01_Sensors_offset_manager' *
   * Block requirements for '<S20>/F01_Sensors_offset_manager':
   *  1. SubSystem "F01_Sensors_offset_manager" !Trace_To : VEMS_R_11_04300_043.01 ;
   */

  /* Stateflow: '<S82>/F01_Sensors_offset_chart' incorporates:
   *  Constant: '<S82>/Ext_stStall_SC'
   *  Constant: '<S82>/UsThrM_tiSampleFast_SC'
   */
  /* Gateway: UsThrMT/F02_PresSenAdj_SdlFast/F01_Sensors_offset_manager/F01_Sensors_offset_chart */
  /* During: UsThrMT/F02_PresSenAdj_SdlFast/F01_Sensors_offset_manager/F01_Sensors_offset_chart */
  if (UsThrMT_DWork.is_active_c2_UsThrMT == 0) {
    /* Entry: UsThrMT/F02_PresSenAdj_SdlFast/F01_Sensors_offset_manager/F01_Sensors_offset_chart */
    UsThrMT_DWork.is_active_c2_UsThrMT = 1U;

    /* Transition: '<S101>:5' */
    if ((localTmpSignalConversionAtEng_m != Ext_stStall_SC) || (((SInt32)
          localNot_k) == 1)) {
      /* Transition: '<S101>:7' */
      /* Entry 'SENSORS_OFFSET_UNAVAILABLE': '<S101>:2' */
      UsThrMT_DWork.is_c2_UsThrMT = IN_SENSORS_OFFSET_UNAVAILABLE;
      UsThrM_bDifPresClcEna_SF = FALSE;
      UsThrM_bDifPresAvl_SF = FALSE;
    } else {
      if (localTmpSignalConversionAtEng_m == Ext_stStall_SC) {
        /* Transition: '<S101>:6' */
        /* Entry 'TIMER_CALCULATION': '<S101>:1' */
        UsThrMT_DWork.is_c2_UsThrMT = IN_TIMER_CALCULATION;
        UsThrM_tiTmrDifPres_SF = (UInt16)rt_MAX(UsThrM_tiTmrDifPresPrev -
          (UsThrM_tiSampleFast_SC << 1), 0);
        UsThrM_bDifPresClcEna_SF = TRUE;
        UsThrM_bDifPresAvl_SF = FALSE;
      }
    }
  } else {
    switch (UsThrMT_DWork.is_c2_UsThrMT) {
     case IN_SENSORS_OFFSET_AVAILABLE:
      /* During 'SENSORS_OFFSET_AVAILABLE': '<S101>:3' */
      /* Transition: '<S101>:9' */
      /* Exit 'SENSORS_OFFSET_AVAILABLE': '<S101>:3' */
      /* Entry 'SENSORS_OFFSET_FREEZE': '<S101>:4' */
      UsThrMT_DWork.is_c2_UsThrMT = IN_SENSORS_OFFSET_FREEZE;
      UsThrM_bDifPresClcEna_SF = FALSE;
      UsThrM_bDifPresAvl_SF = TRUE;
      break;

     case IN_SENSORS_OFFSET_FREEZE:
      break;

     case IN_SENSORS_OFFSET_UNAVAILABLE:
      break;

     case IN_TIMER_CALCULATION:
      /* During 'TIMER_CALCULATION': '<S101>:1' */
      if ((localTmpSignalConversionAtEng_m != Ext_stStall_SC) || (((SInt32)
            localNot_k) == 1)) {
        /* Transition: '<S101>:10' */
        /* Exit 'TIMER_CALCULATION': '<S101>:1' */
        /* Entry 'SENSORS_OFFSET_UNAVAILABLE': '<S101>:2' */
        UsThrMT_DWork.is_c2_UsThrMT = IN_SENSORS_OFFSET_UNAVAILABLE;
        UsThrM_bDifPresClcEna_SF = FALSE;
        UsThrM_bDifPresAvl_SF = FALSE;
      } else if ((localTmpSignalConversionAtEng_m == Ext_stStall_SC) &&
                 (((SInt32)(((UInt32)(UsThrM_tiTmrDifPres_SF * 16777)) >> 1))
                  == 0)) {
        /* Transition: '<S101>:8' */
        /* Exit 'TIMER_CALCULATION': '<S101>:1' */
        /* Entry 'SENSORS_OFFSET_AVAILABLE': '<S101>:3' */
        UsThrMT_DWork.is_c2_UsThrMT = IN_SENSORS_OFFSET_AVAILABLE;
        UsThrM_bDifPresClcEna_SF = TRUE;
        UsThrM_bDifPresAvl_SF = TRUE;
      } else {
        UsThrM_tiTmrDifPres_SF = (UInt16)rt_MAX(UsThrM_tiTmrDifPresPrev -
          (UsThrM_tiSampleFast_SC << 1), 0);
        UsThrM_bDifPresClcEna_SF = TRUE;
        UsThrM_bDifPresAvl_SF = FALSE;
      }
      break;

     default:
      /* Transition: '<S101>:5' */
      if ((localTmpSignalConversionAtEng_m != Ext_stStall_SC) || (((SInt32)
            localNot_k) == 1)) {
        /* Transition: '<S101>:7' */
        /* Entry 'SENSORS_OFFSET_UNAVAILABLE': '<S101>:2' */
        UsThrMT_DWork.is_c2_UsThrMT = IN_SENSORS_OFFSET_UNAVAILABLE;
        UsThrM_bDifPresClcEna_SF = FALSE;
        UsThrM_bDifPresAvl_SF = FALSE;
      } else {
        if (localTmpSignalConversionAtEng_m == Ext_stStall_SC) {
          /* Transition: '<S101>:6' */
          /* Entry 'TIMER_CALCULATION': '<S101>:1' */
          UsThrMT_DWork.is_c2_UsThrMT = IN_TIMER_CALCULATION;
          UsThrM_tiTmrDifPres_SF = (UInt16)rt_MAX(UsThrM_tiTmrDifPresPrev -
            (UsThrM_tiSampleFast_SC << 1), 0);
          UsThrM_bDifPresClcEna_SF = TRUE;
          UsThrM_bDifPresAvl_SF = FALSE;
        }
      }
      break;
    }
  }

  /* SignalConversion: '<S82>/Signal Conversion' */
  UsThrM_bDifPresAvl = UsThrM_bDifPresAvl_SF;

  /* SignalConversion: '<S82>/Signal Conversion1' */
  UsThrM_bDifPresClcEna = UsThrM_bDifPresClcEna_SF;

  /* end of Outputs for SubSystem: '<S20>/F01_Sensors_offset_manager' */

  /* Outputs for enable SubSystem: '<S20>/F02_Sensors_offset_calculation' incorporates:
   *  EnablePort: '<S83>/UsThrM_bDifPresClcEna'
   *  EnablePort: '<S84>/UsThrM_bDifPresClcEna'
   *  Logic: '<S20>/Logical Operator2'
   *  SubSystem: '<S20>/F03_Default'
   *
   * Block requirements for '<S20>/F02_Sensors_offset_calculation':
   *  1. SubSystem "F02_Sensors_offset_calculation" !Trace_To : VEMS_R_11_04300_044.01 ;
   */
  if (UsThrM_bDifPresClcEna) {
    /* Outputs for atomic SubSystem: '<S83>/F01_Measures_filtering' *
     * Block requirements for '<S83>/F01_Measures_filtering':
     *  1. SubSystem "F01_Measures_filtering" !Trace_To : VEMS_R_11_04300_045.01 ;
     */

    /* Outputs for atomic SubSystem: '<S108>/filtrage' */
    UsThrMT_filtrage(localDTC4_j, UsThrM_pAirExtMesSIFilPrev, UsThrM_rFilMes_C,
                     &UsThrMT_B.filtrage_n);

    /* end of Outputs for SubSystem: '<S108>/filtrage' */

    /* Outputs for atomic SubSystem: '<S111>/filtrage' */
    UsThrMT_filtrage(localDTC1_n, UsThrM_pUsThrMesSIFilPrev, UsThrM_rFilMes_C,
                     &UsThrMT_B.filtrage_na);

    /* end of Outputs for SubSystem: '<S111>/filtrage' */

    /* Outputs for atomic SubSystem: '<S114>/filtrage' */
    UsThrMT_filtrage(localDTC2_b, UsThrM_pDsThrMesSIFilPrev, UsThrM_rFilMes_C,
                     &UsThrMT_B.filtrage_f);

    /* end of Outputs for SubSystem: '<S114>/filtrage' */

    /* end of Outputs for SubSystem: '<S83>/F01_Measures_filtering' */

    /* Outputs for atomic SubSystem: '<S83>/F02_Reference_selection' *
     * Block requirements for '<S83>/F02_Reference_selection':
     *  1. SubSystem "F02_Reference_selection" !Trace_To : VEMS_R_11_04300_046.01 ;
     */

    /* Switch: '<S103>/Switch1' incorporates:
     *  Constant: '<S103>/UsThrM_bPresUsThrSenRef_C'
     */
    if (UsThrM_bPresUsThrSenRef_C) {
      localMerge = UsThrMT_B.filtrage_na.Sum1;
    } else {
      localMerge = UsThrMT_B.filtrage_n.Sum1;
    }

    /* Switch: '<S103>/Switch' incorporates:
     *  Constant: '<S103>/UsThrM_bPresDsThrSenRef_C'
     */
    if (UsThrM_bPresDsThrSenRef_C) {
      UsThrM_pSenRef = UsThrMT_B.filtrage_f.Sum1;
    } else {
      UsThrM_pSenRef = localMerge;
    }

    /* end of Outputs for SubSystem: '<S83>/F02_Reference_selection' */

    /* Outputs for atomic SubSystem: '<S83>/F03_Sensors_offset_calculation' *
     * Block requirements for '<S83>/F03_Sensors_offset_calculation':
     *  1. SubSystem "F03_Sensors_offset_calculation" !Trace_To : VEMS_R_11_04300_047.01 ;
     */

    /* Sum: '<S104>/Add' */
    UsThrM_pDifPresRefAirExtClc = UsThrMT_B.filtrage_n.Sum1 - UsThrM_pSenRef;

    /* Sum: '<S104>/Add1' */
    UsThrM_pDifPresRefUsThrClc = UsThrMT_B.filtrage_na.Sum1 - UsThrM_pSenRef;

    /* Sum: '<S104>/Add2' */
    UsThrM_pDifPresRefDsThrClc = UsThrMT_B.filtrage_f.Sum1 - UsThrM_pSenRef;

    /* end of Outputs for SubSystem: '<S83>/F03_Sensors_offset_calculation' */

    /* SignalConversion: '<S83>/Signal Conversion' */
    localMerge = UsThrMT_B.filtrage_n.Sum1;

    /* SignalConversion: '<S83>/Signal Conversion1' */
    localMerge1_b = UsThrMT_B.filtrage_na.Sum1;

    /* SignalConversion: '<S83>/Signal Conversion2' */
    localMerge2 = UsThrMT_B.filtrage_f.Sum1;
  } else {
    /* SignalConversion: '<S84>/Signal Conversion2' */
    localMerge = UsThrM_pAirExtMesSIFilPrev;

    /* SignalConversion: '<S84>/Signal Conversion1' */
    localMerge1_b = UsThrM_pUsThrMesSIFilPrev;

    /* SignalConversion: '<S84>/Signal Conversion3' */
    localMerge2 = UsThrM_pDsThrMesSIFilPrev;
  }

  /* end of Outputs for SubSystem: '<S20>/F02_Sensors_offset_calculation' */

  /* DataTypeConversion: '<S90>/OutDTConv' incorporates:
   *  Constant: '<S90>/offset'
   *  Constant: '<S90>/offset1'
   *  Constant: '<S90>/one_on_slope'
   *  Product: '<S90>/Product4'
   *  Sum: '<S90>/Add1'
   *  Sum: '<S90>/Add2'
   */
  localMerge = (0.125F * localMerge) + 0.5F;
  if (localMerge < 65536.0F) {
    if (localMerge >= 0.0F) {
      localOutDTConv_mg = (UInt16)localMerge;
    } else {
      localOutDTConv_mg = 0U;
    }
  } else {
    localOutDTConv_mg = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S94>/autosar_testpoint1' */

  /* S-Function Block: <S94>/autosar_testpoint1 */
  UsThrM_pAirExtMesSIFil_IRV_MP = localOutDTConv_mg;

  /* DataTypeConversion: '<S91>/OutDTConv' incorporates:
   *  Constant: '<S91>/offset'
   *  Constant: '<S91>/offset1'
   *  Constant: '<S91>/one_on_slope'
   *  Product: '<S91>/Product4'
   *  Sum: '<S91>/Add1'
   *  Sum: '<S91>/Add2'
   */
  localMerge = (0.125F * localMerge1_b) + 0.5F;
  if (localMerge < 65536.0F) {
    if (localMerge >= 0.0F) {
      localOutDTConv_p = (UInt16)localMerge;
    } else {
      localOutDTConv_p = 0U;
    }
  } else {
    localOutDTConv_p = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S95>/autosar_testpoint1' */

  /* S-Function Block: <S95>/autosar_testpoint1 */
  UsThrM_pUsThrMesSIFil_IRV_MP = localOutDTConv_p;

  /* DataTypeConversion: '<S92>/OutDTConv' incorporates:
   *  Constant: '<S92>/offset'
   *  Constant: '<S92>/offset1'
   *  Constant: '<S92>/one_on_slope'
   *  Product: '<S92>/Product4'
   *  Sum: '<S92>/Add1'
   *  Sum: '<S92>/Add2'
   */
  localMerge = (0.125F * localMerge2) + 0.5F;
  if (localMerge < 65536.0F) {
    if (localMerge >= 0.0F) {
      localOutDTConv_b = (UInt16)localMerge;
    } else {
      localOutDTConv_b = 0U;
    }
  } else {
    localOutDTConv_b = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S96>/autosar_testpoint1' */

  /* S-Function Block: <S96>/autosar_testpoint1 */
  UsThrM_pDsThrMesSIFil_IRV_MP = localOutDTConv_b;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S97>/autosar_testpoint1' */

  /* S-Function Block: <S97>/autosar_testpoint1 */
  UsThrM_tiTmrDifPres_IRV_MP = UsThrM_tiTmrDifPres_SF;

  /* Outputs for atomic SubSystem: '<S20>/F03_Sensors_offset_application' *
   * Block requirements for '<S20>/F03_Sensors_offset_application':
   *  1. SubSystem "F03_Sensors_offset_application" !Trace_To : VEMS_R_11_04300_048.01 ;
   */

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S85>/ConstVal'
   */
  if (UsThrM_bDifPresAvl) {
    UsThrM_pDifPresRefAirExt = UsThrM_pDifPresRefAirExtClc;
  } else {
    UsThrM_pDifPresRefAirExt = 0.0F;
  }

  /* Switch: '<S85>/Switch1' incorporates:
   *  Constant: '<S85>/ConstVal_1'
   */
  if (UsThrM_bDifPresAvl) {
    UsThrM_pDifPresRefUsThr = UsThrM_pDifPresRefUsThrClc;
  } else {
    UsThrM_pDifPresRefUsThr = 0.0F;
  }

  /* Switch: '<S85>/Switch2' incorporates:
   *  Constant: '<S85>/ConstVal_2'
   */
  if (UsThrM_bDifPresAvl) {
    UsThrM_pDifPresRefDsThr = UsThrM_pDifPresRefDsThrClc;
  } else {
    UsThrM_pDifPresRefDsThr = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S20>/F03_Sensors_offset_application' */

  /* Outputs for atomic SubSystem: '<S20>/F04_Measures_correction' *
   * Block requirements for '<S20>/F04_Measures_correction':
   *  1. SubSystem "F04_Measures_correction" !Trace_To : VEMS_R_11_04300_049.01 ;
   */

  /* If: '<S86>/If' incorporates:
   *  ActionPort: '<S117>/Action Port'
   *  ActionPort: '<S118>/Action Port'
   *  Constant: '<S86>/UsThrM_bInhPresSenAdj_C'
   *  SubSystem: '<S86>/F01_IF'
   *  SubSystem: '<S86>/F02_Else'
   */
  if (UsThrM_bInhPresSenAdj_C) {
    /* SignalConversion: '<S117>/Signal Conversion1' */
    localMerge = localDTC4_j;

    /* SignalConversion: '<S117>/Signal Conversion2' */
    localMerge1_b = localDTC1_n;

    /* SignalConversion: '<S117>/Signal Conversion3' */
    localMerge2 = localDTC2_b;
  } else {
    /* Sum: '<S118>/Add' */
    localMerge = localDTC4_j - UsThrM_pDifPresRefAirExt;

    /* Sum: '<S118>/Add1' */
    localMerge1_b = localDTC1_n - UsThrM_pDifPresRefUsThr;

    /* Sum: '<S118>/Add2' */
    localMerge2 = localDTC2_b - UsThrM_pDifPresRefDsThr;
  }

  /* end of Outputs for SubSystem: '<S20>/F04_Measures_correction' */

  /* SignalConversion: '<S20>/Signal Conversion1' */
  localUsThrM_tiTmrDifPres_irv_b = UsThrM_tiTmrDifPres_SF;

  /* SignalConversion: '<S20>/Signal Conversion3' */
  localTmpSignalConversionAtExt_l = localOutDTConv_mg;

  /* SignalConversion: '<S20>/Signal Conversion4' */
  localUsThrM_pUsThrMesSIFil_ir_o = localOutDTConv_p;

  /* SignalConversion: '<S20>/Signal Conversion5' */
  localTmpSignalConversionAtExt_n = localOutDTConv_b;

  /* DataTypeConversion: '<S88>/OutDTConv' incorporates:
   *  Constant: '<S88>/offset'
   *  Constant: '<S88>/offset1'
   *  Constant: '<S88>/one_on_slope'
   *  Product: '<S88>/Product4'
   *  Sum: '<S88>/Add1'
   *  Sum: '<S88>/Add2'
   */
  localMerge = (0.125F * localMerge) + 0.5F;
  if (localMerge < 65536.0F) {
    if (localMerge >= 0.0F) {
      localOutDTConv_b = (UInt16)localMerge;
    } else {
      localOutDTConv_b = 0U;
    }
  } else {
    localOutDTConv_b = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S89>/OutDTConv' incorporates:
   *  Constant: '<S89>/offset'
   *  Constant: '<S89>/offset1'
   *  Constant: '<S89>/one_on_slope'
   *  Product: '<S89>/Product4'
   *  Sum: '<S89>/Add1'
   *  Sum: '<S89>/Add2'
   */
  localMerge = (0.125F * localMerge1_b) + 0.5F;
  if (localMerge < 65536.0F) {
    if (localMerge >= 0.0F) {
      localOutDTConv_p = (UInt16)localMerge;
    } else {
      localOutDTConv_p = 0U;
    }
  } else {
    localOutDTConv_p = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S93>/OutDTConv' incorporates:
   *  Constant: '<S93>/offset'
   *  Constant: '<S93>/offset1'
   *  Constant: '<S93>/one_on_slope'
   *  Product: '<S93>/Product4'
   *  Sum: '<S93>/Add1'
   *  Sum: '<S93>/Add2'
   */
  localMerge = (0.125F * localMerge2) + 0.5F;
  if (localMerge < 65536.0F) {
    if (localMerge >= 0.0F) {
      localOutDTConv_mg = (UInt16)localMerge;
    } else {
      localOutDTConv_mg = 0U;
    }
  } else {
    localOutDTConv_mg = MAX_uint16_T;
  }

  /* Switch: '<S98>/Switch' incorporates:
   *  Constant: '<S98>/Byp_Fonction_SC'
   *  Constant: '<S98>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEx_ir = UsThrM_pAirExtMesCor_B;
  } else {
    localTmpSignalConversionAtEx_ir = localOutDTConv_b;
  }

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pAirExtMesCorInport2' */
  Rte_Write_P_UsThrM_pAirExtMesCor_UsThrM_pAirExtMesCor
    (localTmpSignalConversionAtEx_ir);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pAirExtMesSIFil_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_002_TEV_UsThrM_pAirExtMesSIFil_irv
    (localTmpSignalConversionAtExt_l);

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S100>/Byp_Fonction_SC'
   *  Constant: '<S100>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_l = UsThrM_pDsThrMesCor_B;
  } else {
    localTmpSignalConversionAtExt_l = localOutDTConv_mg;
  }

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pDsThrMesCorInport2' */
  Rte_Write_P_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (localTmpSignalConversionAtExt_l);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pDsThrMesSIFil_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_002_TEV_UsThrM_pDsThrMesSIFil_irv
    (localTmpSignalConversionAtExt_n);

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Byp_Fonction_SC'
   *  Constant: '<S99>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_l = UsThrM_pUsThrMesCor_B;
  } else {
    localTmpSignalConversionAtExt_l = localOutDTConv_p;
  }

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pUsThrMesCorInport2' */
  Rte_Write_P_UsThrM_pUsThrMesCor_UsThrM_pUsThrMesCor
    (localTmpSignalConversionAtExt_l);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pUsThrMesSIFil_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_002_TEV_UsThrM_pUsThrMesSIFil_irv
    (localUsThrM_pUsThrMesSIFil_ir_o);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_tiTmrDifPres_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_002_TEV_UsThrM_tiTmrDifPres_irv
    (localUsThrM_tiTmrDifPres_irv_b);
}

/* Output and update for exported function: RE_UsThrMT_012_TEV */
void RE_UsThrMT_012_TEV(void)
{
  Float32 localDTC1_m;
  Float32 localDTC3_c;
  SInt16 localTmpSignalConversionAtExt_t;
  SInt16 localTmpSignalConversionAtExt_f;
  Float32 localAdd2_ep;
  Float32 localSwitch3_o;
  Float32 localSum2;
  UInt16 localOutDTConv_bl;
  UInt8 localUsThrM_tSqrtInAir;

  /* S-Function (fcncallgen): '<S13>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_Manage_temperature_observer'
   *
   * Block requirements for '<S1>/F03_Manage_temperature_observer':
   *  1. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_032.01 ;
   *  2. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_033.01 ;
   *  3. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_038.01 ;
   *  4. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_072.01 ;
   *  5. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_134.01 ;
   *  6. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_094.01 ;
   *  7. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_095.01 ;
   *  8. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_108.01 ;
   *  9. SubSystem "F03_Manage_temperature_observer" !Trace_To : VEMS_R_11_04300_109.01 ;
   */

  /* DataTypeConversion: '<S24>/DTC1' incorporates:
   *  Constant: '<S24>/Ext_rSqrtOfs_SC'
   */
  localDTC1_m = ((Float32)Ext_rSqrtOfs_SC) * 3.725290298E-009F;

  /* DataTypeConversion: '<S24>/DTC3' incorporates:
   *  Constant: '<S24>/Ext_rSqrtGain_SC'
   */
  localDTC3_c = ((Float32)Ext_rSqrtGain_SC) * 2.328306437E-010F;

  /* SignalConversion: '<S24>/TmpSignal ConversionAtExt_tUsThrMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tUsThrMes'
   */
  Rte_Read_R_Ext_tUsThrMes_Ext_tUsThrMes(&localTmpSignalConversionAtExt_t);

  /* Sum: '<S24>/Sum4' incorporates:
   *  Constant: '<S24>/ConstVal_1'
   */
  localSwitch3_o = ((Float32)localTmpSignalConversionAtExt_t) + 273.0F;

  /* SignalConversion: '<S24>/TmpSignal ConversionAtExt_tDsThrMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tDsThrMes'
   */
  Rte_Read_R_Ext_tDsThrMes_Ext_tDsThrMes(&localTmpSignalConversionAtExt_f);

  /* Sum: '<S24>/Sum2' incorporates:
   *  Constant: '<S24>/ConstVal'
   */
  localSum2 = ((Float32)localTmpSignalConversionAtExt_f) + 273.0F;

  /* Switch: '<S24>/Switch2' incorporates:
   *  Constant: '<S24>/UsThrM_bSelTSen1_C'
   */
  if (UsThrM_bSelTSen1_C) {
    localAdd2_ep = localSwitch3_o;
  } else {
    localAdd2_ep = localSum2;
  }

  /* DataTypeConversion: '<S206>/OutDTConv' incorporates:
   *  Constant: '<S206>/offset'
   *  Constant: '<S206>/offset1'
   *  Constant: '<S206>/one_on_slope'
   *  Product: '<S206>/Product4'
   *  Sum: '<S206>/Add1'
   *  Sum: '<S206>/Add2'
   */
  localAdd2_ep = ((localAdd2_ep - 223.0F) * 128.0F) + 0.5F;
  if (localAdd2_ep < 65536.0F) {
    if (localAdd2_ep >= 0.0F) {
      localOutDTConv_bl = (UInt16)localAdd2_ep;
    } else {
      localOutDTConv_bl = 0U;
    }
  } else {
    localOutDTConv_bl = MAX_uint16_T;
  }

  /* Switch: '<S24>/Switch3' incorporates:
   *  Constant: '<S24>/UsThrM_bSelTSen2_C'
   */
  if (!UsThrM_bSelTSen2_C) {
    localSwitch3_o = localSum2;
  }

  /* Switch: '<S208>/Switch' incorporates:
   *  Constant: '<S207>/offset'
   *  Constant: '<S207>/offset1'
   *  Constant: '<S207>/one_on_slope'
   *  Constant: '<S208>/Byp_Fonction_SC'
   *  Constant: '<S208>/Int_BypC'
   *  DataTypeConversion: '<S207>/OutDTConv'
   *  Product: '<S207>/Product4'
   *  Product: '<S210>/Divide'
   *  Sum: '<S207>/Add1'
   *  Sum: '<S207>/Add2'
   *  Sum: '<S24>/Sum1'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localUsThrM_tSqrtInAir = UsThrM_tSqrtInAir_B;
  } else {
    localAdd2_ep = (((localSwitch3_o * localDTC3_c) + localDTC1_m) * 8.0F) +
      0.5F;
    if (localAdd2_ep < 256.0F) {
      if (localAdd2_ep >= 0.0F) {
        localUsThrM_tSqrtInAir = (UInt8)localAdd2_ep;
      } else {
        localUsThrM_tSqrtInAir = 0U;
      }
    } else {
      localUsThrM_tSqrtInAir = MAX_uint8_T;
    }
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtUsThrM_tSqrtInAirInport2' */
  Rte_Write_P_UsThrM_tSqrtInAir_UsThrM_tSqrtInAir(localUsThrM_tSqrtInAir);

  /* Switch: '<S209>/Switch' incorporates:
   *  Constant: '<S209>/Byp_Fonction_SC'
   *  Constant: '<S209>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localOutDTConv_bl = UsThrM_tThrMes_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtUsThrM_tThrMesInport2' */
  Rte_Write_P_UsThrM_tThrMes_UsThrM_tThrMes(localOutDTConv_bl);
}

/*
 * Output and update for atomic system:
 *    '<S134>/filtrage'
 *    '<S139>/filtrage'
 */
void UsThrMT_filtrage_a(Float32 rtu_GAIN, Float32 rtu_INPUT, Float32
  rtu_Init_IRV, rtB_filtrage_UsThrMT_c *localB)
{
  /* Sum: '<S136>/Sum1' incorporates:
   *  Product: '<S136>/Product'
   *  Saturate: '<S136>/Saturation [0-1]'
   *  Sum: '<S136>/Sum'
   */
  localB->Sum1 = ((rtu_INPUT - rtu_Init_IRV) * rt_SATURATE(rtu_GAIN, 0.0F, 1.0F))
    + rtu_Init_IRV;
}

/* Start for exported function: RE_UsThrMT_005_TEV */
void RE_UsThrMT_005_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_TUsCmprEstim_calculation'
   *
   * Block requirements for '<S1>/F02_TUsCmprEstim_calculation':
   *  1. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_052.01 ;
   *  2. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_054.01 ;
   *  3. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_068.01 ;
   *  4. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_069.01 ;
   *  5. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_070.01 ;
   *  6. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_071.01 ;
   *  7. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_073.01 ;
   *  8. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_127.01 ;
   *  9. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_112.02 ;
   *  10. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_110.01 ;
   *  11. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_100.01 ;
   */
}

/* Output and update for exported function: RE_UsThrMT_005_TEV */
void RE_UsThrMT_005_TEV(void)
{
  /* local block i/o variables */
  Float32 localInterpolationUsingPrelo_nh;
  Float32 localAdd3_d;
  Float32 localInterpolationUsingPreloo_f;
  SInt16 localTmpSignalConversionAtExt_o;
  SInt8 localTmpSignalConversionAtExt_h;
  Float32 localSwitch_ea;
  Float32 localVeh_spdVeh_UsThrM_spdVeh_A;
  Float32 localfrac[2];
  Float32 localThMgt_rSpdFanReq_UsThrM_rS;
  UInt32 localVeh_spdVeh_UsThrM_spdVeh_i;
  UInt32 localbpIndex[2];
  UInt32 localThMgt_rSpdFanReq_UsThrM__f;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  UInt8 localTmpSignalConversionAtThMgt;
  SInt16 localTmpSignalConversionAtEng_t;
  UInt16 localTmpSignalConversionAtUsT_n;
  UInt16 localTmpSignalConversionAtVeh_s;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_TUsCmprEstim_calculation'
   *
   * Block requirements for '<S1>/F02_TUsCmprEstim_calculation':
   *  1. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_052.01 ;
   *  2. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_054.01 ;
   *  3. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_068.01 ;
   *  4. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_069.01 ;
   *  5. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_070.01 ;
   *  6. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_071.01 ;
   *  7. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_073.01 ;
   *  8. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_127.01 ;
   *  9. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_112.02 ;
   *  10. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_110.01 ;
   *  11. SubSystem "F02_TUsCmprEstim_calculation" !Trace_To : VEMS_R_11_04300_100.01 ;
   */

  /* SignalConversion: '<S22>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_o);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEng_tOilEstimOutport2' incorporates:
   *  Inport: '<Root>/Eng_tOilEstim'
   */
  Rte_Read_R_Eng_tOilEstim_Eng_tOilEstim(&localTmpSignalConversionAtEng_t);

  /* Outputs for atomic SubSystem: '<S22>/F01_Engine_temperature' *
   * Block requirements for '<S22>/F01_Engine_temperature':
   *  1. SubSystem "F01_Engine_temperature" !Trace_To : VEMS_R_11_04300_055.01 ;
   */

  /* Switch: '<S119>/Switch' incorporates:
   *  Constant: '<S119>/UsThrM_bInhTOil_C'
   *  DataTypeConversion: '<S22>/DTC1'
   *  DataTypeConversion: '<S22>/DTC4'
   */
  if (UsThrM_bInhTOil_C) {
    localSwitch_ea = (Float32)localTmpSignalConversionAtExt_o;
  } else {
    localSwitch_ea = ((Float32)localTmpSignalConversionAtEng_t) * 0.25F;
  }

  /* Sum: '<S119>/Sum1' incorporates:
   *  Constant: '<S119>/ConstVal'
   */
  UsThrM_tEng = localSwitch_ea + 2.731499939E+002F;

  /* end of Outputs for SubSystem: '<S22>/F01_Engine_temperature' */

  /* SignalConversion: '<S22>/TmpSignal ConversionAtExt_tAirOutport2' incorporates:
   *  Inport: '<Root>/Ext_tAir'
   */
  Rte_Read_R_Ext_tAir_Ext_tAir(&localTmpSignalConversionAtExt_h);

  /* Outputs for atomic SubSystem: '<S22>/F02_Exterior_temperature' *
   * Block requirements for '<S22>/F02_Exterior_temperature':
   *  1. SubSystem "F02_Exterior_temperature" !Trace_To : VEMS_R_11_04300_056.01 ;
   */

  /* Sum: '<S120>/Sum2' incorporates:
   *  Constant: '<S120>/ConstVal'
   *  DataTypeConversion: '<S22>/DTC2'
   */
  UsThrM_tAirExt = ((Float32)localTmpSignalConversionAtExt_h) +
    2.731499939E+002F;

  /* end of Outputs for SubSystem: '<S22>/F02_Exterior_temperature' */

  /* DataTypeConversion: '<S22>/DTC6' incorporates:
   *  SignalConversion: '<S22>/TmpSignal ConversionAtUsThrM_tUndHoPrevOutport2'
   */
  UsThrM_tUndHoPrev = ((Float32)
                       Rte_IrvRead_RE_UsThrMT_005_TEV_UsThrM_tUndHo_irv()) *
    0.0078125F;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtVeh_spdVehOutport2' incorporates:
   *  Inport: '<Root>/Veh_spdVeh'
   */
  Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&localTmpSignalConversionAtVeh_s);

  /* PreLookup: '<S126>/Prelookup' */
  localVeh_spdVeh_UsThrM_spdVeh_i = plook_u32u16f_binc
    (localTmpSignalConversionAtVeh_s, (&(UsThrM_spdVeh_A[0])), 8U,
     &localVeh_spdVeh_UsThrM_spdVeh_A);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtThMgt_rSpdFanReqOutport2' incorporates:
   *  Inport: '<Root>/ThMgt_rSpdFanReq'
   */
  Rte_Read_R_ThMgt_rSpdFanReq_ThMgt_rSpdFanReq(&localTmpSignalConversionAtThMgt);

  /* PreLookup: '<S125>/Prelookup' */
  localThMgt_rSpdFanReq_UsThrM__f = plook_u32u8f_binc
    (localTmpSignalConversionAtThMgt, (&(UsThrM_rSpdFan_A[0])), 2U,
     &localThMgt_rSpdFanReq_UsThrM_rS);

  /* Outputs for atomic SubSystem: '<S22>/F03_Under_hood_temperature' *
   * Block requirements for '<S22>/F03_Under_hood_temperature':
   *  1. SubSystem "F03_Under_hood_temperature" !Trace_To : VEMS_R_11_04300_057.01 ;
   */

  /* Interpolation_n-D: '<S131>/Interpolation Using Prelookup3' */
  localSwitch_ea = localVeh_spdVeh_UsThrM_spdVeh_A;
  localfrac[0] = localSwitch_ea;
  localSwitch_ea = localThMgt_rSpdFanReq_UsThrM_rS;
  localfrac[1] = localSwitch_ea;
  localbpIndex[0] = localVeh_spdVeh_UsThrM_spdVeh_i;
  localbpIndex[1] = localThMgt_rSpdFanReq_UsThrM__f;
  localSwitch_ea = intrp2d_iu8n8ff_u32f_l_ns(localbpIndex, localfrac,
    (&(UsThrM_rFacTUndHo_M[0])), 9U);

  /* Sum: '<S121>/Add3' incorporates:
   *  Product: '<S133>/Divide'
   *  Sum: '<S121>/Add2'
   */
  localAdd3_d = ((UsThrM_tEng - UsThrM_tAirExt) * localSwitch_ea) +
    UsThrM_tAirExt;

  /* DataStoreWrite: '<S121>/UsThrM_tUndHoRaw_MP_DSW' incorporates:
   *  Constant: '<S130>/offset'
   *  Constant: '<S130>/offset1'
   *  Constant: '<S130>/one_on_slope'
   *  DataTypeConversion: '<S130>/OutDTConv'
   *  Product: '<S130>/Product4'
   *  Sum: '<S130>/Add1'
   *  Sum: '<S130>/Add2'
   */
  localSwitch_ea = ((localAdd3_d - 223.0F) * 128.0F) + 0.5F;
  if (localSwitch_ea < 65536.0F) {
    if (localSwitch_ea >= 0.0F) {
      UsThrM_tUndHoRaw_MP = (UInt16)localSwitch_ea;
    } else {
      UsThrM_tUndHoRaw_MP = 0U;
    }
  } else {
    UsThrM_tUndHoRaw_MP = MAX_uint16_T;
  }

  /* Interpolation_n-D: '<S132>/Interpolation Using Prelookup3' */
  localSwitch_ea = localVeh_spdVeh_UsThrM_spdVeh_A;
  localfrac_0[0] = localSwitch_ea;
  localSwitch_ea = localThMgt_rSpdFanReq_UsThrM_rS;
  localfrac_0[1] = localSwitch_ea;
  localbpIndex_0[0] = localVeh_spdVeh_UsThrM_spdVeh_i;
  localbpIndex_0[1] = localThMgt_rSpdFanReq_UsThrM__f;
  localInterpolationUsingPreloo_f = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex_0,
    localfrac_0, (&(UsThrM_rFilTUndHo_M[0])), 9U);

  /* Outputs for atomic SubSystem: '<S134>/filtrage' */
  UsThrMT_filtrage_a(localInterpolationUsingPreloo_f, localAdd3_d,
                     UsThrM_tUndHoPrev, &UsThrMT_B.filtrage_a);

  /* end of Outputs for SubSystem: '<S134>/filtrage' */

  /* end of Outputs for SubSystem: '<S22>/F03_Under_hood_temperature' */

  /* SignalConversion: '<S127>/copy' */
  UsThrM_tUndHo_IRV_MP = UsThrMT_B.filtrage_a.Sum1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S127>/autosar_testpoint1' */

  /* S-Function Block: <S127>/autosar_testpoint1 */

  /* SignalConversion: '<S22>/TmpSignal ConversionAtUsThrM_tUsCmprPrevOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tUsCmpr_INPUT'
   */
  Rte_Read_R_UsThrM_tUsCmpr_UsThrM_tUsCmpr(&localTmpSignalConversionAtUsT_n);

  /* DataTypeConversion: '<S22>/DTC7' */
  UsThrM_tUsCmprPrev = (((Float32)localTmpSignalConversionAtUsT_n) * 0.0078125F)
    + 223.0F;

  /* Outputs for atomic SubSystem: '<S22>/F04_Upstream_compressor_temperature' *
   * Block requirements for '<S22>/F04_Upstream_compressor_temperature':
   *  1. SubSystem "F04_Upstream_compressor_temperature" !Trace_To : VEMS_R_11_04300_058.01 ;
   */

  /* Interpolation_n-D: '<S138>/Interpolation Using Prelookup3' */
  localSwitch_ea = localVeh_spdVeh_UsThrM_spdVeh_A;
  localfrac_1[0] = localSwitch_ea;
  localSwitch_ea = localThMgt_rSpdFanReq_UsThrM_rS;
  localfrac_1[1] = localSwitch_ea;
  localbpIndex_1[0] = localVeh_spdVeh_UsThrM_spdVeh_i;
  localbpIndex_1[1] = localThMgt_rSpdFanReq_UsThrM__f;
  localInterpolationUsingPrelo_nh = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex_1,
    localfrac_1, (&(UsThrM_rFilTUsCmpr_M[0])), 9U);

  /* Outputs for atomic SubSystem: '<S139>/filtrage' */
  UsThrMT_filtrage_a(localInterpolationUsingPrelo_nh, UsThrMT_B.filtrage_a.Sum1,
                     UsThrM_tUsCmprPrev, &UsThrMT_B.filtrage_m);

  /* end of Outputs for SubSystem: '<S139>/filtrage' */

  /* Switch: '<S122>/Switch' incorporates:
   *  Constant: '<S122>/UsThrM_bInhTUsCmprEstim_C'
   */
  if (UsThrM_bInhTUsCmprEstim_C) {
    localSwitch_ea = UsThrM_tAirExt;
  } else {
    localSwitch_ea = UsThrMT_B.filtrage_m.Sum1;
  }

  /* end of Outputs for SubSystem: '<S22>/F04_Upstream_compressor_temperature' */

  /* DataTypeConversion: '<S123>/OutDTConv' incorporates:
   *  Constant: '<S123>/offset'
   *  Constant: '<S123>/offset1'
   *  Constant: '<S123>/one_on_slope'
   *  Product: '<S123>/Product4'
   *  Sum: '<S123>/Add1'
   *  Sum: '<S123>/Add2'
   */
  localSwitch_ea = ((localSwitch_ea - 223.0F) * 128.0F) + 0.5F;
  if (localSwitch_ea < 65536.0F) {
    if (localSwitch_ea >= 0.0F) {
      localTmpSignalConversionAtVeh_s = (UInt16)localSwitch_ea;
    } else {
      localTmpSignalConversionAtVeh_s = 0U;
    }
  } else {
    localTmpSignalConversionAtVeh_s = MAX_uint16_T;
  }

  /* SignalConversion: '<S22>/TmpSignal ConversionAtUsThrM_tUndHo_irvInport2' incorporates:
   *  Constant: '<S124>/offset'
   *  Constant: '<S124>/offset1'
   *  Constant: '<S124>/one_on_slope'
   *  DataTypeConversion: '<S124>/OutDTConv'
   *  Product: '<S124>/Product4'
   *  Sum: '<S124>/Add1'
   *  Sum: '<S124>/Add2'
   */
  localSwitch_ea = (128.0F * UsThrMT_B.filtrage_a.Sum1) + 0.5F;
  if (localSwitch_ea < 4.294967296E+009F) {
    if (localSwitch_ea >= 0.0F) {
      localVeh_spdVeh_UsThrM_spdVeh_i = (UInt32)localSwitch_ea;
    } else {
      localVeh_spdVeh_UsThrM_spdVeh_i = 0U;
    }
  } else {
    localVeh_spdVeh_UsThrM_spdVeh_i = MAX_uint32_T;
  }

  Rte_IrvWrite_RE_UsThrMT_005_TEV_UsThrM_tUndHo_irv
    (localVeh_spdVeh_UsThrM_spdVeh_i);

  /* Switch: '<S128>/Switch' incorporates:
   *  Constant: '<S128>/Byp_Fonction_SC'
   *  Constant: '<S128>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtVeh_s = UsThrM_tUsCmpr_B;
  }

  /* SignalConversion: '<S22>/TmpSignal ConversionAtUsThrM_tUsCmprInport2' */
  Rte_Write_P_UsThrM_tUsCmpr_UsThrM_tUsCmpr(localTmpSignalConversionAtVeh_s);
}

/* Start for exported function: RE_UsThrMT_004_MSE */
void RE_UsThrMT_004_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/Init'
   *
   * Block requirements for '<S1>/Init':
   *  1. SubSystem "Init" !Trace_To : VEMS_R_11_04300_051.01 ;
   *  2. SubSystem "Init" !Trace_To : VEMS_R_11_04300_052.01 ;
   *  3. SubSystem "Init" !Trace_To : VEMS_R_11_04300_053.01 ;
   *  4. SubSystem "Init" !Trace_To : VEMS_R_11_04300_059.01 ;
   *  5. SubSystem "Init" !Trace_To : VEMS_R_11_04300_060.01 ;
   *  6. SubSystem "Init" !Trace_To : VEMS_R_11_04300_061.01 ;
   *  7. SubSystem "Init" !Trace_To : VEMS_R_11_04300_005.01 ;
   *  8. SubSystem "Init" !Trace_To : VEMS_R_11_04300_001.01 ;
   *  9. SubSystem "Init" !Trace_To : VEMS_R_11_04300_006.01 ;
   *  10. SubSystem "Init" !Trace_To : VEMS_R_11_04300_032.01 ;
   *  11. SubSystem "Init" !Trace_To : VEMS_R_11_04300_033.01 ;
   *  12. SubSystem "Init" !Trace_To : VEMS_R_11_04300_072.01 ;
   *  13. SubSystem "Init" !Trace_To : VEMS_R_11_04300_075.01 ;
   *  14. SubSystem "Init" !Trace_To : VEMS_R_11_04300_076.01 ;
   *  15. SubSystem "Init" !Trace_To : VEMS_R_11_04300_078.01 ;
   *  16. SubSystem "Init" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  17. SubSystem "Init" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  18. SubSystem "Init" !Trace_To : VEMS_R_11_04300_081.01 ;
   *  19. SubSystem "Init" !Trace_To : VEMS_R_11_04300_083.01 ;
   *  20. SubSystem "Init" !Trace_To : VEMS_R_11_04300_126.01 ;
   *  21. SubSystem "Init" !Trace_To : VEMS_R_11_04300_112.02 ;
   *  22. SubSystem "Init" !Trace_To : VEMS_R_11_04300_118.02 ;
   *  23. SubSystem "Init" !Trace_To : VEMS_R_11_04300_119.02 ;
   *  24. SubSystem "Init" !Trace_To : VEMS_R_11_04300_120.02 ;
   *  25. SubSystem "Init" !Trace_To : VEMS_R_11_04300_121.02 ;
   *  26. SubSystem "Init" !Trace_To : VEMS_R_11_04300_122.02 ;
   *  27. SubSystem "Init" !Trace_To : VEMS_R_11_04300_106.01 ;
   *  28. SubSystem "Init" !Trace_To : VEMS_R_11_04300_135.02 ;
   *  29. SubSystem "Init" !Trace_To : VEMS_R_11_04300_136.01 ;
   *  30. SubSystem "Init" !Trace_To : VEMS_R_11_04300_137.01 ;
   *  31. SubSystem "Init" !Trace_To : VEMS_R_11_04300_094.01 ;
   *  32. SubSystem "Init" !Trace_To : VEMS_R_11_04300_095.01 ;
   *  33. SubSystem "Init" !Trace_To : VEMS_R_11_04300_096.01 ;
   *  34. SubSystem "Init" !Trace_To : VEMS_R_11_04300_097.01 ;
   *  35. SubSystem "Init" !Trace_To : VEMS_R_11_04300_099.01 ;
   *  36. SubSystem "Init" !Trace_To : VEMS_R_11_04300_108.01 ;
   *  37. SubSystem "Init" !Trace_To : VEMS_R_11_04300_109.01 ;
   *  38. SubSystem "Init" !Trace_To : VEMS_R_11_04300_110.01 ;
   *  39. SubSystem "Init" !Trace_To : VEMS_R_11_04300_111.01 ;
   *  40. SubSystem "Init" !Trace_To : VEMS_R_11_04300_101.01 ;
   *  41. SubSystem "Init" !Trace_To : VEMS_R_11_04300_102.01 ;
   *  42. SubSystem "Init" !Trace_To : VEMS_R_11_04300_103.01 ;
   *  43. SubSystem "Init" !Trace_To : VEMS_R_11_04300_100.01 ;
   */
}

/* Output and update for exported function: RE_UsThrMT_004_MSE */
void RE_UsThrMT_004_MSE(void)
{
  /* local block i/o variables */
  Float32 localAdd2_oq;
  Boolean localAutosarServer_n;
  Boolean localLogicalOperator_p;
  SInt16 localTmpSignalConversionAtExt_d;
  SInt16 localTmpSignalConversionAtEx_le;
  Float32 localDTC1_np;
  Float32 localSwitch2_o;
  Float32 localSum_a;
  Float32 localSum2_m;
  UInt16 localUsThrM_pUsCmpr_p;
  SInt16 localUsThrM_pLossCmpr_f;
  UInt8 localUsThrM_tSqrtInAir_c;
  UInt16 localSwitch3_g;
  UInt16 localTmpSignalConversionAtUsT_k;
  UInt16 locallocalUsThrM_pDsThrAcvAirEx;
  SInt32 localq;
  UInt32 localqY;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/Init'
   *
   * Block requirements for '<S1>/Init':
   *  1. SubSystem "Init" !Trace_To : VEMS_R_11_04300_051.01 ;
   *  2. SubSystem "Init" !Trace_To : VEMS_R_11_04300_052.01 ;
   *  3. SubSystem "Init" !Trace_To : VEMS_R_11_04300_053.01 ;
   *  4. SubSystem "Init" !Trace_To : VEMS_R_11_04300_059.01 ;
   *  5. SubSystem "Init" !Trace_To : VEMS_R_11_04300_060.01 ;
   *  6. SubSystem "Init" !Trace_To : VEMS_R_11_04300_061.01 ;
   *  7. SubSystem "Init" !Trace_To : VEMS_R_11_04300_005.01 ;
   *  8. SubSystem "Init" !Trace_To : VEMS_R_11_04300_001.01 ;
   *  9. SubSystem "Init" !Trace_To : VEMS_R_11_04300_006.01 ;
   *  10. SubSystem "Init" !Trace_To : VEMS_R_11_04300_032.01 ;
   *  11. SubSystem "Init" !Trace_To : VEMS_R_11_04300_033.01 ;
   *  12. SubSystem "Init" !Trace_To : VEMS_R_11_04300_072.01 ;
   *  13. SubSystem "Init" !Trace_To : VEMS_R_11_04300_075.01 ;
   *  14. SubSystem "Init" !Trace_To : VEMS_R_11_04300_076.01 ;
   *  15. SubSystem "Init" !Trace_To : VEMS_R_11_04300_078.01 ;
   *  16. SubSystem "Init" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  17. SubSystem "Init" !Trace_To : VEMS_R_11_04300_080.01 ;
   *  18. SubSystem "Init" !Trace_To : VEMS_R_11_04300_081.01 ;
   *  19. SubSystem "Init" !Trace_To : VEMS_R_11_04300_083.01 ;
   *  20. SubSystem "Init" !Trace_To : VEMS_R_11_04300_126.01 ;
   *  21. SubSystem "Init" !Trace_To : VEMS_R_11_04300_112.02 ;
   *  22. SubSystem "Init" !Trace_To : VEMS_R_11_04300_118.02 ;
   *  23. SubSystem "Init" !Trace_To : VEMS_R_11_04300_119.02 ;
   *  24. SubSystem "Init" !Trace_To : VEMS_R_11_04300_120.02 ;
   *  25. SubSystem "Init" !Trace_To : VEMS_R_11_04300_121.02 ;
   *  26. SubSystem "Init" !Trace_To : VEMS_R_11_04300_122.02 ;
   *  27. SubSystem "Init" !Trace_To : VEMS_R_11_04300_106.01 ;
   *  28. SubSystem "Init" !Trace_To : VEMS_R_11_04300_135.02 ;
   *  29. SubSystem "Init" !Trace_To : VEMS_R_11_04300_136.01 ;
   *  30. SubSystem "Init" !Trace_To : VEMS_R_11_04300_137.01 ;
   *  31. SubSystem "Init" !Trace_To : VEMS_R_11_04300_094.01 ;
   *  32. SubSystem "Init" !Trace_To : VEMS_R_11_04300_095.01 ;
   *  33. SubSystem "Init" !Trace_To : VEMS_R_11_04300_096.01 ;
   *  34. SubSystem "Init" !Trace_To : VEMS_R_11_04300_097.01 ;
   *  35. SubSystem "Init" !Trace_To : VEMS_R_11_04300_099.01 ;
   *  36. SubSystem "Init" !Trace_To : VEMS_R_11_04300_108.01 ;
   *  37. SubSystem "Init" !Trace_To : VEMS_R_11_04300_109.01 ;
   *  38. SubSystem "Init" !Trace_To : VEMS_R_11_04300_110.01 ;
   *  39. SubSystem "Init" !Trace_To : VEMS_R_11_04300_111.01 ;
   *  40. SubSystem "Init" !Trace_To : VEMS_R_11_04300_101.01 ;
   *  41. SubSystem "Init" !Trace_To : VEMS_R_11_04300_102.01 ;
   *  42. SubSystem "Init" !Trace_To : VEMS_R_11_04300_103.01 ;
   *  43. SubSystem "Init" !Trace_To : VEMS_R_11_04300_100.01 ;
   */

  /* user code (Output function Body for TID12) */
  Runnable_UsThrMT_Init();

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pAirExt_INPUTOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt_INPUT'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_pAi);

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pUsThrTrbCor_INPUTOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrTrbCor_INPUT'
   */
  Rte_Read_R_UsThrM_pUsThrTrbCor_UsThrM_pUsThrTrbCor
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_pUs);

  /* Outputs for atomic SubSystem: '<S25>/F01_Init_pressure_observer' *
   * Block requirements for '<S25>/F01_Init_pressure_observer':
   *  1. SubSystem "F01_Init_pressure_observer" !Trace_To : VEMS_R_11_04300_034.01 ;
   *  2. SubSystem "F01_Init_pressure_observer" !Trace_To : VEMS_R_11_04300_035.01 ;
   */

  /* Switch: '<S211>/Switch3' incorporates:
   *  Constant: '<S211>/Ext_bEngTrbMod_SC'
   */
  if (Ext_bEngTrbMod_SC) {
    localSwitch3_g = UsThrMT_B.TmpSignalConversionAtUsThrM_pUs;
  } else {
    localSwitch3_g = UsThrMT_B.TmpSignalConversionAtUsThrM_pAi;
  }

  /* end of Outputs for SubSystem: '<S25>/F01_Init_pressure_observer' */

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S225>/Byp_Fonction_SC'
   *  Constant: '<S225>/Int_BypC'
   *  DataTypeConversion: '<S225>/Data Type Conversion'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrM_pDsThrAcvAirExtCtlMod_B;
  } else {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrMT_B.TmpSignalConversionAtUsThrM_pAi;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pDsThrAcvAirExtCtlModInport2' */
  Rte_Write_P_UsThrM_pDsThrAcvAirExtCtlMod_UsThrM_pDsThrAcvAirExtCtlMod
    (locallocalUsThrM_pDsThrAcvAirEx);

  /* Switch: '<S235>/Switch' incorporates:
   *  Constant: '<S235>/Byp_Fonction_SC'
   *  Constant: '<S235>/Int_BypC'
   *  DataTypeConversion: '<S235>/Data Type Conversion'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localUsThrM_pUsCmpr_p = UsThrM_pUsCmpr_B;
  } else {
    localUsThrM_pUsCmpr_p = UsThrMT_B.TmpSignalConversionAtUsThrM_pAi;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pUsCmprInport2' */
  Rte_Write_P_UsThrM_pUsCmpr_UsThrM_pUsCmpr(localUsThrM_pUsCmpr_p);

  /* Switch: '<S222>/Switch' incorporates:
   *  Constant: '<S222>/Byp_Fonction_SC'
   *  Constant: '<S222>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localSwitch3_g = UsThrM_pUsThrCor_B;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pUsThrCorInport2' */
  Rte_Write_P_UsThrM_pUsThrCor_UsThrM_pUsThrCor(localSwitch3_g);

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pUsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrMesCor_INPUT'
   */
  Rte_Read_R_UsThrM_pUsThrMesCor_UsThrM_pUsThrMesCor
    (&UsThrMT_B.TmpSignalConversionAtUsThrM_p_l);

  /* Switch: '<S233>/Switch' incorporates:
   *  Constant: '<S233>/Byp_Fonction_SC'
   *  Constant: '<S233>/Int_BypC'
   *  DataTypeConversion: '<S233>/Data Type Conversion'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrM_pDsCmpr_B;
  } else {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrMT_B.TmpSignalConversionAtUsThrM_p_l;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pDsCmprInport2' */
  Rte_Write_P_UsThrM_pDsCmpr_UsThrM_pDsCmpr(locallocalUsThrM_pDsThrAcvAirEx);

  /* Switch: '<S234>/Switch' incorporates:
   *  Constant: '<S234>/Byp_Fonction_SC'
   *  Constant: '<S234>/Int_BypC'
   *  DataTypeConversion: '<S234>/Data Type Conversion'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrM_pUsThrTrbCor_B;
  } else {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrMT_B.TmpSignalConversionAtUsThrM_p_l;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pUsThrTrbCorInport2' */
  Rte_Write_P_UsThrM_pUsThrTrbCor_UsThrM_pUsThrTrbCor
    (locallocalUsThrM_pDsThrAcvAirEx);

  /* Switch: '<S231>/Switch' incorporates:
   *  Constant: '<S231>/Byp_Fonction_SC'
   *  Constant: '<S231>/Int_BypC'
   *  Constant: '<S25>/ConstVal_1'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrM_pLossCAC_B;
  } else {
    locallocalUsThrM_pDsThrAcvAirEx = 0U;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pLossCACInport2' */
  Rte_Write_P_UsThrM_pLossCAC_UsThrM_pLossCAC(locallocalUsThrM_pDsThrAcvAirEx);

  /* Switch: '<S232>/Switch' incorporates:
   *  Constant: '<S232>/Byp_Fonction_SC'
   *  Constant: '<S232>/Int_BypC'
   *  Constant: '<S25>/ConstVal'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localUsThrM_pLossCmpr_f = UsThrM_pLossCmpr_B;
  } else {
    localUsThrM_pLossCmpr_f = 0;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pLossCmprInport2' */
  Rte_Write_P_UsThrM_pLossCmpr_UsThrM_pLossCmpr(localUsThrM_pLossCmpr_f);

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pAirExtMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExtMesCor_INPUT'
   */
  Rte_Read_R_UsThrM_pAirExtMesCor_UsThrM_pAirExtMesCor
    (&localTmpSignalConversionAtUsT_k);

  /* S-Function (sfun_autosar_clientop): '<S213>/AutosarServer' */
  Rte_Call_R_FRM_bInhMes_pAirExt_GetFunctionPermission(&localAutosarServer_n);

  /* Logic: '<S25>/Logical Operator' incorporates:
   *  Constant: '<S25>/Ext_bPresSen_pAirExt_SC'
   *  Logic: '<S213>/Not'
   *  Logic: '<S25>/Logical Operator1'
   */
  localLogicalOperator_p = ((!(!localAutosarServer_n)) &&
    Ext_bPresSen_pAirExt_SC);

  /* S-Function (NvRamReadAccess): '<S25>/EepromReadAccess' */
  UsThrMT_B.EepromReadAccess = UsThrMT_sNV_Z1_CALIB_16BIT.UsThrM_pAirExt_NV;

  /* Switch: '<S25>/Switch' */
  if (localLogicalOperator_p) {
    UsThrMT_B.Switch = localTmpSignalConversionAtUsT_k;
  } else {
    UsThrMT_B.Switch = UsThrMT_B.EepromReadAccess;
  }

  /* S-Function (NvRamWriteAccess): '<S25>/EepromWriteAccess' */
  UsThrMT_sNV_Z1_CALIB_16BIT.UsThrM_pAirExt_NV = UsThrMT_B.Switch;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S216>/autosar_testpoint1' */

  /* S-Function Block: <S216>/autosar_testpoint1 */
  UsThrM_pAirExtRaw_IRV_MP = UsThrMT_B.Switch;

  /* SignalConversion: '<S25>/Signal Conversion4' */
  locallocalUsThrM_pDsThrAcvAirEx = UsThrMT_B.Switch;

  /* Switch: '<S223>/Switch' incorporates:
   *  Constant: '<S223>/Byp_Fonction_SC'
   *  Constant: '<S223>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localUsThrM_pUsCmpr_p = UsThrM_pAirExt_B;
  } else {
    localUsThrM_pUsCmpr_p = UsThrMT_B.Switch;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pAirExtInport2' */
  Rte_Write_P_UsThrM_pAirExt_UsThrM_pAirExt(localUsThrM_pUsCmpr_p);

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pAirExtRaw_irvInport2' */
  Rte_IrvWrite_RE_UsThrMT_004_MSE_UsThrM_pAirExtRaw_irv
    (locallocalUsThrM_pDsThrAcvAirEx);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S217>/autosar_testpoint1' incorporates:
   *  Constant: '<S25>/ConstVal_2'
   */

  /* S-Function Block: <S217>/autosar_testpoint1 */
  UsThrM_ctUpdAirExtPresStall = 0U;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresStall_irvInport2' incorporates:
   *  Constant: '<S25>/ConstVal_2'
   *  SignalConversion: '<S25>/Signal Conversion10'
   */
  Rte_IrvWrite_RE_UsThrMT_004_MSE_UsThrM_ctUpdAirExtPresStall_irv(0U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S218>/autosar_testpoint1' incorporates:
   *  Constant: '<S25>/UsThrM_tiDlyUpdAirExtPres_C'
   */

  /* S-Function Block: <S218>/autosar_testpoint1 */
  UsThrM_ctUpdAirExtPresRun_IRV_MP = UsThrM_tiDlyUpdAirExtPres_C;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresRun_irvInport2' incorporates:
   *  Constant: '<S25>/UsThrM_tiDlyUpdAirExtPres_C'
   *  SignalConversion: '<S25>/Signal Conversion8'
   */
  Rte_IrvWrite_RE_UsThrMT_004_MSE_UsThrM_ctUpdAirExtPresRun_irv
    (UsThrM_tiDlyUpdAirExtPres_C);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S219>/autosar_testpoint1' incorporates:
   *  Constant: '<S25>/UsThrM_tiDlyUpdAirExtPresIdl_C'
   */

  /* S-Function Block: <S219>/autosar_testpoint1 */
  UsThrM_ctUpdAirExtPresIdl_IRV_MP = UsThrM_tiDlyUpdAirExtPresIdl_C;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresIdl_irvInport2' incorporates:
   *  Constant: '<S25>/UsThrM_tiDlyUpdAirExtPresIdl_C'
   *  SignalConversion: '<S25>/Signal Conversion9'
   */
  Rte_IrvWrite_RE_UsThrMT_004_MSE_UsThrM_ctUpdAirExtPresIdl_irv
    (UsThrM_tiDlyUpdAirExtPresIdl_C);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S220>/autosar_testpoint1' incorporates:
   *  Constant: '<S25>/UsThrM_tiUpdAirExtPresInjCut_C'
   */

  /* S-Function Block: <S220>/autosar_testpoint1 */
  UsThrM_ctUpdAirExtPresCut_IRV_MP = UsThrM_tiUpdAirExtPresInjCut_C;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_ctUpdAirExtPresCut_irvInport2' incorporates:
   *  Constant: '<S25>/UsThrM_tiUpdAirExtPresInjCut_C'
   *  SignalConversion: '<S25>/Signal Conversion11'
   */
  Rte_IrvWrite_RE_UsThrMT_004_MSE_UsThrM_ctUpdAirExtPresCut_irv
    (UsThrM_tiUpdAirExtPresInjCut_C);

  /* Switch: '<S224>/Switch' incorporates:
   *  Constant: '<S224>/Byp_Fonction_SC'
   *  Constant: '<S224>/Int_BypC'
   *  Constant: '<S25>/ConstVal_3'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrM_facPresAltiCor_B;
  } else {
    locallocalUsThrM_pDsThrAcvAirEx = 32768U;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_facPresAltiCorInport2' */
  Rte_Write_P_UsThrM_facPresAltiCor_UsThrM_facPresAltiCor
    (locallocalUsThrM_pDsThrAcvAirEx);

  /* Switch: '<S226>/Switch' incorporates:
   *  Constant: '<S226>/Byp_Fonction_SC'
   *  Constant: '<S226>/Int_BypC'
   *  Constant: '<S25>/ConstVal_5'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localLogicalOperator_p = UsThrM_bAcvAirExtCtlMod_B;
  } else {
    localLogicalOperator_p = TRUE;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_bAcvAirExtCtlModInport2' */
  Rte_Write_P_UsThrM_bAcvAirExtCtlMod_UsThrM_bAcvAirExtCtlMod
    (localLogicalOperator_p);

  /* SignalConversion: '<S25>/TmpSignal ConversionAtExt_tDsThrMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tDsThrMes'
   */
  Rte_Read_R_Ext_tDsThrMes_Ext_tDsThrMes(&localTmpSignalConversionAtExt_d);

  /* SignalConversion: '<S25>/TmpSignal ConversionAtExt_tUsThrMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tUsThrMes'
   */
  Rte_Read_R_Ext_tUsThrMes_Ext_tUsThrMes(&localTmpSignalConversionAtEx_le);

  /* Outputs for atomic SubSystem: '<S25>/F02_Init_temperature_observer' *
   * Block requirements for '<S25>/F02_Init_temperature_observer':
   *  1. SubSystem "F02_Init_temperature_observer" !Trace_To : VEMS_R_11_04300_034.01 ;
   *  2. SubSystem "F02_Init_temperature_observer" !Trace_To : VEMS_R_11_04300_036.01 ;
   */

  /* DataTypeConversion: '<S212>/DTC1' incorporates:
   *  Constant: '<S212>/Ext_rSqrtOfs_SC'
   */
  localDTC1_np = ((Float32)Ext_rSqrtOfs_SC) * 3.725290298E-009F;

  /* Sum: '<S212>/Sum' incorporates:
   *  Constant: '<S212>/ConstVal'
   *  DataTypeConversion: '<S25>/DTC3'
   */
  localSum_a = ((Float32)localTmpSignalConversionAtExt_d) + 273.0F;

  /* Sum: '<S212>/Sum2' incorporates:
   *  Constant: '<S212>/ConstVal_1'
   *  DataTypeConversion: '<S25>/DTC5'
   */
  localSum2_m = ((Float32)localTmpSignalConversionAtEx_le) + 273.0F;

  /* Switch: '<S212>/Switch2' incorporates:
   *  Constant: '<S212>/UsThrM_bSelTSen2_C'
   */
  if (UsThrM_bSelTSen2_C) {
    localSwitch2_o = localSum2_m;
  } else {
    localSwitch2_o = localSum_a;
  }

  /* Product: '<S236>/Divide' incorporates:
   *  Constant: '<S212>/Ext_rSqrtGain_SC'
   *  DataTypeConversion: '<S212>/DTC3'
   */
  localSwitch2_o *= ((Float32)Ext_rSqrtGain_SC) * 2.328306437E-010F;

  /* Switch: '<S212>/Switch1' incorporates:
   *  Constant: '<S212>/UsThrM_bSelTSen1_C'
   */
  if (UsThrM_bSelTSen1_C) {
    localSum_a = localSum2_m;
  }

  /* end of Outputs for SubSystem: '<S25>/F02_Init_temperature_observer' */

  /* Sum: '<S214>/Add2' incorporates:
   *  Constant: '<S214>/offset'
   *  Constant: '<S214>/offset1'
   *  Constant: '<S214>/one_on_slope'
   *  Product: '<S214>/Product4'
   *  Sum: '<S214>/Add1'
   */
  localAdd2_oq = ((localSum_a - 223.0F) * 128.0F) + 0.5F;

  /* DataTypeConversion: '<S214>/OutDTConv' */
  if (localAdd2_oq < 65536.0F) {
    if (localAdd2_oq >= 0.0F) {
      locallocalUsThrM_pDsThrAcvAirEx = (UInt16)localAdd2_oq;
    } else {
      locallocalUsThrM_pDsThrAcvAirEx = 0U;
    }
  } else {
    locallocalUsThrM_pDsThrAcvAirEx = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S25>/DTC7' */
  localAdd2_oq = (((Float32)locallocalUsThrM_pDsThrAcvAirEx) * 0.0078125F) +
    223.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S221>/autosar_testpoint1' */

  /* S-Function Block: <S221>/autosar_testpoint1 */
  UsThrM_tUndHo_IRV_MP = localAdd2_oq;

  /* Sum: '<S215>/Add2' incorporates:
   *  Constant: '<S215>/offset'
   *  Constant: '<S215>/offset1'
   *  Constant: '<S215>/one_on_slope'
   *  Product: '<S215>/Product4'
   *  Sum: '<S212>/Sum1'
   *  Sum: '<S215>/Add1'
   */
  localAdd2_oq = ((localSwitch2_o + localDTC1_np) * 8.0F) + 0.5F;

  /* Switch: '<S230>/Switch' incorporates:
   *  Constant: '<S230>/Byp_Fonction_SC'
   *  Constant: '<S230>/Int_BypC'
   *  DataTypeConversion: '<S215>/OutDTConv'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localUsThrM_tSqrtInAir_c = UsThrM_tSqrtInAir_B;
  } else if (localAdd2_oq < 256.0F) {
    if (localAdd2_oq >= 0.0F) {
      localUsThrM_tSqrtInAir_c = (UInt8)localAdd2_oq;
    } else {
      localUsThrM_tSqrtInAir_c = 0U;
    }
  } else {
    localUsThrM_tSqrtInAir_c = MAX_uint8_T;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_tSqrtInAirInport2' */
  Rte_Write_P_UsThrM_tSqrtInAir_UsThrM_tSqrtInAir(localUsThrM_tSqrtInAir_c);

  /* Switch: '<S229>/Switch' incorporates:
   *  Constant: '<S229>/Byp_Fonction_SC'
   *  Constant: '<S229>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localUsThrM_pUsCmpr_p = UsThrM_tThrMes_B;
  } else {
    localUsThrM_pUsCmpr_p = locallocalUsThrM_pDsThrAcvAirEx;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_tThrMesInport2' */
  Rte_Write_P_UsThrM_tThrMes_UsThrM_tThrMes(localUsThrM_pUsCmpr_p);

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_tUndHo_irvInport2' incorporates:
   *  DataTypeConversion: '<S25>/DTC6'
   */
  localq = locallocalUsThrM_pDsThrAcvAirEx;
  localqY = (UInt32)(localq + 28544);
  if (localqY < ((UInt32)localq)) {
    localqY = MAX_uint32_T;
  }

  Rte_IrvWrite_RE_UsThrMT_004_MSE_UsThrM_tUndHo_irv(localqY);

  /* Switch: '<S228>/Switch' incorporates:
   *  Constant: '<S228>/Byp_Fonction_SC'
   *  Constant: '<S228>/Int_BypC'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrM_tUsCmpr_B;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_tUsCmprInport2' */
  Rte_Write_P_UsThrM_tUsCmpr_UsThrM_tUsCmpr(locallocalUsThrM_pDsThrAcvAirEx);

  /* Switch: '<S227>/Switch' incorporates:
   *  Constant: '<S227>/Byp_Fonction_SC'
   *  Constant: '<S227>/Int_BypC'
   *  Constant: '<S25>/ConstVal_4'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    locallocalUsThrM_pDsThrAcvAirEx = UsThrM_pLossAirFil_B;
  } else {
    locallocalUsThrM_pDsThrAcvAirEx = 0U;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtUsThrM_pLossAirFilInport2' */
  Rte_Write_P_UsThrM_pLossAirFil_UsThrM_pLossAirFil
    (locallocalUsThrM_pDsThrAcvAirEx);
}

/* Output and update for exported function: RE_UsThrMT_008_TEV */
void RE_UsThrMT_008_TEV(void)
{
  UInt16 localTmpSignalConversionAtEngM_;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Air_filter_pressure_loss_SdlMid'
   *
   * Block requirements for '<S1>/F01_Air_filter_pressure_loss_SdlMid':
   *  1. SubSystem "F01_Air_filter_pressure_loss_SdlMid" !Trace_To : VEMS_R_11_04300_001.01 ;
   *  2. SubSystem "F01_Air_filter_pressure_loss_SdlMid" !Trace_To : VEMS_R_11_04300_002.01 ;
   *  3. SubSystem "F01_Air_filter_pressure_loss_SdlMid" !Trace_To : VEMS_R_11_04300_003.01 ;
   *  4. SubSystem "F01_Air_filter_pressure_loss_SdlMid" !Trace_To : VEMS_R_11_04300_004.01 ;
   *  5. SubSystem "F01_Air_filter_pressure_loss_SdlMid" !Trace_To : VEMS_R_11_04300_077.01 ;
   *  6. SubSystem "F01_Air_filter_pressure_loss_SdlMid" !Trace_To : VEMS_R_11_04300_079.01 ;
   *  7. SubSystem "F01_Air_filter_pressure_loss_SdlMid" !Trace_To : VEMS_R_11_04300_130.02 ;
   *  8. SubSystem "F01_Air_filter_pressure_loss_SdlMid" !Trace_To : VEMS_R_11_04300_143.02 ;
   */

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_mfAirCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfAirCor'
   */
  Rte_Read_R_EngM_mfAirCor_EngM_mfAirCor(&localTmpSignalConversionAtEngM_);

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S29>/offset'
   *  Constant: '<S29>/offset1'
   *  Constant: '<S29>/one_on_slope'
   *  Constant: '<S31>/Byp_Fonction_SC'
   *  Constant: '<S31>/Int_BypC'
   *  DataTypeConversion: '<S29>/OutDTConv'
   *  Lookup_n-D: '<S30>/Lookup Table (n-D)'
   *  Product: '<S29>/Product4'
   *  Sum: '<S29>/Add1'
   *  Sum: '<S29>/Add2'
   */
  if (USTHRMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEngM_ = UsThrM_pLossAirFil_B;
  } else {
    localtmp = (0.125F * look1_iu16lftu16p3If_binlcs
                (localTmpSignalConversionAtEngM_, (&(Air_mfAirRef1_A[0])),
                 (&(UsThrM_pLossAirFil_T[0])), 15U)) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtEngM_ = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtEngM_ = 0U;
      }
    } else {
      localTmpSignalConversionAtEngM_ = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtUsThrM_pLossAirFilInport2' */
  Rte_Write_P_UsThrM_pLossAirFil_UsThrM_pLossAirFil
    (localTmpSignalConversionAtEngM_);
}

/* Model initialize function */
void Runnable_UsThrMT_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__10'
   *  Start for SubSystem: '<Root>/__ExpFcn__11'
   *  Start for SubSystem: '<Root>/__ExpFcn__12'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   *  Start for SubSystem: '<Root>/__ExpFcn__7'
   *  Start for SubSystem: '<Root>/__ExpFcn__8'
   *  Start for SubSystem: '<Root>/__ExpFcn__9'
   */
  RE_UsThrMT_001_MSE_Start();
  RE_UsThrMT_010_TEV_Start();
  RE_UsThrMT_006_TEV_Start();
  RE_UsThrMT_002_TEV_Start();
  RE_UsThrMT_005_TEV_Start();
  RE_UsThrMT_004_MSE_Start();

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__10'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__11'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__12'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__3'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__4'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__5'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__6'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__7'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__8'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__9'
   */
  RE_UsThrMT_007_TEV_Init();
}

#define UsThrMT_STOP_SEC_CODE
#include "UsThrMT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
