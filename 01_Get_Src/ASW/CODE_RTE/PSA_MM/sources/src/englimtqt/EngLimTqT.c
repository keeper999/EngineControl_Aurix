/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngLimTqT                                               */
/* !Description     : EngLimTqT Software Component                            */
/*                                                                            */
/* !Module          : EngLimTqT                                               */
/* !Description     : EngLimTqT Software Component                            */
/*                                                                            */
/* !File            : EngLimTqT.c                                             */
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
/*   Model name       : EngLimTqT_AUTOSAR.mdl                                 */
/*   Root subsystem   : /EngLimTqT                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M01-EngLimTqT/5$*/
/* $Revision::   1.14                                                        $*/
/* $Author::   adelvare                               $$Date::   12 Sep 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "EngLimTqT.h"
#include "EngLimTqT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define EngLimTqT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "EngLimTqT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_EngLimTqT EngLimTqT_B;

/* Block states (auto storage) */
D_Work_EngLimTqT EngLimTqT_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_EngLimTqT EngLimTqT_PrevZCSigState;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "EngLimTqT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define ENGLIMTQT_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define ENGLIMTQT_VEMSRTLIBT_MINOR_VERSION_REQ 38
#define ENGLIMTQT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define ENGLIMTQT_VEMSRTLIBT_VERSION_REQ (ENGLIMTQT_VEMSRTLIBT_PATCH_VERSION_REQ + ENGLIMTQT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + ENGLIMTQT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if ENGLIMTQT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define EngLimTqT_START_SEC_CODE
#include "EngLimTqT_MemMap.h"

void EngLimTqT_ASYNC1(int controlPortIdx)
{
}

void EngLimTqT_ASYNC2(int controlPortIdx)
{
}

void EngLimTqT_ASYNC3(int controlPortIdx)
{
}

void EngLimTqT_ASYNC4(int controlPortIdx)
{
}

void EngLimTqT_ASYNC5(int controlPortIdx)
{
}

void EngLimTqT_ASYNC6(int controlPortIdx)
{
}

void EngLimTqT_ASYNC7(int controlPortIdx)
{
}

void EngLimTqT_ASYNC8(int controlPortIdx)
{
}

void EngLimTqT_ASYNC9(int controlPortIdx)
{
}

void EngLimTqT_ASYNC10(int controlPortIdx)
{
}

void EngLimTqT_ASYNC11(int controlPortIdx)
{
}

void EngLimTqT_ASYNC12(int controlPortIdx)
{
}

void EngLimTqT_ASYNC13(int controlPortIdx)
{
}

void EngLimTqT_ASYNC14(int controlPortIdx)
{
}

void EngLimTqT_ASYNC15(int controlPortIdx)
{
}

void EngLimTqT_ASYNC16(int controlPortIdx)
{
}

void EngLimTqT_ASYNC17(int controlPortIdx)
{
}

void EngLimTqT_ASYNC18(int controlPortIdx)
{
}

void EngLimTqT_ASYNC19(int controlPortIdx)
{
}

void EngLimTqT_ASYNC20(int controlPortIdx)
{
}

/* Start for exported function: RE_EngLimTqT_011_MSE */
void RE_EngLimTqT_011_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Initialisation1'
   *
   * Block requirements for '<S1>/F01_Initialisation1':
   *  1. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_114.02 ;
   *  2. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_010.02 ;
   *  3. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_011.02 ;
   *  4. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_012.02 ;
   *  5. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_120.02 ;
   *  6. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_121.02 ;
   *  7. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_122.02 ;
   *  8. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_123.02 ;
   *  9. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_124.02 ;
   *  10. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_125.02 ;
   *  11. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_144.01 ;
   *  12. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_145.01 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_011_MSE */
void RE_EngLimTqT_011_MSE(void)
{
  /* local block i/o variables */
  UInt16 localMultiportSwitch[6];
  UInt16 localIgSys_rMinIgEfc;
  UInt16 localIgSys_prm_rMaxIgSpEfcCyl_d;
  UInt16 localIgSys_prm_rMaxIgSpEfcCyl_i;
  UInt16 localIgSys_prm_rMaxIgSpEfcCyl_e;
  UInt16 localIgSys_prm_rMaxIgSpEfcCyl_p;
  SInt32 locali;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Initialisation1'
   *
   * Block requirements for '<S1>/F01_Initialisation1':
   *  1. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_114.02 ;
   *  2. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_010.02 ;
   *  3. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_011.02 ;
   *  4. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_012.02 ;
   *  5. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_120.02 ;
   *  6. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_121.02 ;
   *  7. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_122.02 ;
   *  8. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_123.02 ;
   *  9. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_124.02 ;
   *  10. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_125.02 ;
   *  11. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_144.01 ;
   *  12. SubSystem "F01_Initialisation1" !Trace_To : VEMS_R_10_06438_145.01 ;
   */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S17>/Cste_2'
   *  Constant: '<S42>/Byp_Fonction_SC'
   *  Constant: '<S42>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localIgSys_rMinIgEfc = IgSys_rMinIgEfc_B;
  } else {
    localIgSys_rMinIgEfc = 1024U;
  }

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_rMinIgEfcInport2' */
  Rte_Write_P_IgSys_rMinIgEfc_IgSys_rMinIgEfc(localIgSys_rMinIgEfc);

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S17>/Cste_1'
   *  Constant: '<S41>/Byp_Fonction_SC'
   *  Constant: '<S41>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localIgSys_rMinIgEfc = IgSys_rMaxIgEfc_B;
  } else {
    localIgSys_rMinIgEfc = 1024U;
  }

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_rMaxIgEfcInport2' */
  Rte_Write_P_IgSys_rMaxIgEfc_IgSys_rMaxIgEfc(localIgSys_rMinIgEfc);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S34>/autosar_testpoint1' incorporates:
   *  Constant: '<S17>/Cste_0'
   */

  /* S-Function Block: <S34>/autosar_testpoint1 */
  IgSys_noCylInc1_IRV_MP = ((UInt8)6U);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_noCylInc1_irvInport2' incorporates:
   *  Constant: '<S17>/Cste_0'
   *  SignalConversion: '<S17>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_EngLimTqT_011_MSE_IgSys_noCylInc1_irv(6U);

  /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
   *  Constant: '<S17>/Cste_0_0_0_0_0_0_1'
   *  Constant: '<S17>/Cste_0_0_0_0_0_0_2'
   *  Constant: '<S17>/Cste_0_0_0_0_0_0_3'
   *  Constant: '<S17>/Cste_0_0_0_0_0_0_4'
   *  Constant: '<S17>/Cste_0_0_0_0_0_0_5'
   *  Constant: '<S17>/Cste_0_0_0_0_0_0_6'
   *  Constant: '<S17>/Cste_3'
   */
  switch (Ext_noCylEng_SC) {
   case 1:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch[locali] = EngLimTqT_ConstP.pooled14[(locali)];
    }
    break;

   case 2:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch[locali] = EngLimTqT_ConstP.pooled15[(locali)];
    }
    break;

   case 3:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch[locali] = EngLimTqT_ConstP.pooled16[(locali)];
    }
    break;

   case 4:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch[locali] = EngLimTqT_ConstP.pooled17[(locali)];
    }
    break;

   case 5:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch[locali] = EngLimTqT_ConstP.pooled18[(locali)];
    }
    break;

   default:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch[locali] = EngLimTqT_ConstP.pooled19[(locali)];
    }
    break;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S35>/autosar_testpoint1' */

  /* S-Function Block: <S35>/autosar_testpoint1 */
  IgSys_prm_rMaxIgSpEfcCyl_01 = localMultiportSwitch[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S36>/autosar_testpoint1' */

  /* S-Function Block: <S36>/autosar_testpoint1 */
  IgSys_prm_rMaxIgSpEfcCyl_02 = localMultiportSwitch[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S37>/autosar_testpoint1' */

  /* S-Function Block: <S37>/autosar_testpoint1 */
  IgSys_prm_rMaxIgSpEfcCyl_03 = localMultiportSwitch[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S38>/autosar_testpoint1' */

  /* S-Function Block: <S38>/autosar_testpoint1 */
  IgSys_prm_rMaxIgSpEfcCyl_04 = localMultiportSwitch[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S39>/autosar_testpoint1' */

  /* S-Function Block: <S39>/autosar_testpoint1 */
  IgSys_prm_rMaxIgSpEfcCyl_05 = localMultiportSwitch[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S40>/autosar_testpoint1' */

  /* S-Function Block: <S40>/autosar_testpoint1 */
  IgSys_prm_rMaxIgSpEfcCyl_06 = localMultiportSwitch[5];

  /* SignalConversion: '<S17>/Signal Conversion1' */
  localIgSys_rMinIgEfc = localMultiportSwitch[4];

  /* SignalConversion: '<S17>/Signal Conversion2' */
  localIgSys_prm_rMaxIgSpEfcCyl_d = localMultiportSwitch[3];

  /* SignalConversion: '<S17>/Signal Conversion4' */
  localIgSys_prm_rMaxIgSpEfcCyl_i = localMultiportSwitch[2];

  /* SignalConversion: '<S17>/Signal Conversion5' */
  localIgSys_prm_rMaxIgSpEfcCyl_e = localMultiportSwitch[1];

  /* SignalConversion: '<S17>/Signal Conversion6' */
  localIgSys_prm_rMaxIgSpEfcCyl_p = localMultiportSwitch[0];

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_006_irvInport2' incorporates:
   *  SignalConversion: '<S17>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_EngLimTqT_011_MSE_IgSys_prm_rMaxIgSpEfcCyl_06_irv
    (localMultiportSwitch[5]);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_01_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_011_MSE_IgSys_prm_rMaxIgSpEfcCyl_01_irv
    (localIgSys_prm_rMaxIgSpEfcCyl_p);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_02_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_011_MSE_IgSys_prm_rMaxIgSpEfcCyl_02_irv
    (localIgSys_prm_rMaxIgSpEfcCyl_e);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_03_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_011_MSE_IgSys_prm_rMaxIgSpEfcCyl_03_irv
    (localIgSys_prm_rMaxIgSpEfcCyl_i);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_04_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_011_MSE_IgSys_prm_rMaxIgSpEfcCyl_04_irv
    (localIgSys_prm_rMaxIgSpEfcCyl_d);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_05_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_011_MSE_IgSys_prm_rMaxIgSpEfcCyl_05_irv
    (localIgSys_rMinIgEfc);
}

/* Start for exported function: RE_EngLimTqT_013_MSE */
void RE_EngLimTqT_013_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Initialisation2'
   *
   * Block requirements for '<S1>/F01_Initialisation2':
   *  1. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_116.04 ;
   *  2. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_010.02 ;
   *  3. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_011.02 ;
   *  4. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_012.02 ;
   *  5. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_098.01 ;
   *  6. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_126.02 ;
   *  7. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_127.02 ;
   *  8. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_128.02 ;
   *  9. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_129.02 ;
   *  10. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_130.02 ;
   *  11. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_131.02 ;
   *  12. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_132.02 ;
   *  13. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_133.02 ;
   *  14. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_134.02 ;
   *  15. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_135.02 ;
   *  16. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_136.02 ;
   *  17. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_137.01 ;
   *  18. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_146.01 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_013_MSE */
void RE_EngLimTqT_013_MSE(void)
{
  /* local block i/o variables */
  UInt16 localMultiportSwitch_m[6];
  UInt16 localIgSys_rDynIgSpEfc;
  UInt16 localIgSys_prm_rDynIgSpEfcCyl_0;
  UInt16 localIgSys_prm_rDynIgSpEfcCyl_g;
  UInt16 localIgSys_prm_rStatIgSpEfcCy_g;
  UInt16 localIgSys_prm_rStatIgSpEfcC_gc;
  UInt16 localIgSys_prm_rStatIgSpEfcCy_l;
  UInt16 localIgSys_prm_rStatIgSpEfcCy_e;
  UInt16 localIgSys_prm_rStatIgSpEfcCy_a;
  UInt16 localIgSys_prm_rDynIgSpEfcCyl_e;
  UInt16 localIgSys_prm_rDynIgSpEfcCyl_m;
  UInt16 localIgSys_prm_rDynIgSpEfcCyl_l;
  SInt32 locali;

  /* S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Initialisation2'
   *
   * Block requirements for '<S1>/F01_Initialisation2':
   *  1. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_116.04 ;
   *  2. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_010.02 ;
   *  3. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_011.02 ;
   *  4. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_012.02 ;
   *  5. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_098.01 ;
   *  6. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_126.02 ;
   *  7. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_127.02 ;
   *  8. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_128.02 ;
   *  9. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_129.02 ;
   *  10. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_130.02 ;
   *  11. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_131.02 ;
   *  12. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_132.02 ;
   *  13. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_133.02 ;
   *  14. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_134.02 ;
   *  15. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_135.02 ;
   *  16. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_136.02 ;
   *  17. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_137.01 ;
   *  18. SubSystem "F01_Initialisation2" !Trace_To : VEMS_R_10_06438_146.01 ;
   */

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S18>/Cste_1_1'
   *  Constant: '<S58>/Byp_Fonction_SC'
   *  Constant: '<S58>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localIgSys_rDynIgSpEfc = IgSys_rDynIgSpEfc_B;
  } else {
    localIgSys_rDynIgSpEfc = 1024U;
  }

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_rDynIgSpEfcInport2' */
  Rte_Write_P_IgSys_rDynIgSpEfc_IgSys_rDynIgSpEfc(localIgSys_rDynIgSpEfc);

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S18>/Cste_3'
   *  Constant: '<S57>/Byp_Fonction_SC'
   *  Constant: '<S57>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localIgSys_rDynIgSpEfc = IgSys_rStatIgSpEfc_B;
  } else {
    localIgSys_rDynIgSpEfc = 1024U;
  }

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_rStatIgSpEfcInport2' */
  Rte_Write_P_IgSys_rStatIgSpEfc_IgSys_rStatIgSpEfc(localIgSys_rDynIgSpEfc);

  /* MultiPortSwitch: '<S18>/Multiport Switch' incorporates:
   *  Constant: '<S18>/Cste_0_0_0_0_0_0_1'
   *  Constant: '<S18>/Cste_0_0_0_0_0_0_2'
   *  Constant: '<S18>/Cste_0_0_0_0_0_0_3'
   *  Constant: '<S18>/Cste_0_0_0_0_0_0_4'
   *  Constant: '<S18>/Cste_0_0_0_0_0_0_5'
   *  Constant: '<S18>/Cste_0_0_0_0_0_0_6'
   *  Constant: '<S18>/Cste_2'
   */
  switch (Ext_noCylEng_SC) {
   case 1:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch_m[locali] = EngLimTqT_ConstP.pooled14[(locali)];
    }
    break;

   case 2:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch_m[locali] = EngLimTqT_ConstP.pooled15[(locali)];
    }
    break;

   case 3:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch_m[locali] = EngLimTqT_ConstP.pooled16[(locali)];
    }
    break;

   case 4:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch_m[locali] = EngLimTqT_ConstP.pooled17[(locali)];
    }
    break;

   case 5:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch_m[locali] = EngLimTqT_ConstP.pooled18[(locali)];
    }
    break;

   default:
    for (locali = 0; locali < 6; locali++) {
      localMultiportSwitch_m[locali] = EngLimTqT_ConstP.pooled19[(locali)];
    }
    break;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S44>/autosar_testpoint1' */

  /* S-Function Block: <S44>/autosar_testpoint1 */
  IgSys_prm_rStatIgSpEfcCyl_02 = localMultiportSwitch_m[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S45>/autosar_testpoint1' */

  /* S-Function Block: <S45>/autosar_testpoint1 */
  IgSys_prm_rStatIgSpEfcCyl_03 = localMultiportSwitch_m[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S46>/autosar_testpoint1' */

  /* S-Function Block: <S46>/autosar_testpoint1 */
  IgSys_prm_rStatIgSpEfcCyl_04 = localMultiportSwitch_m[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S47>/autosar_testpoint1' */

  /* S-Function Block: <S47>/autosar_testpoint1 */
  IgSys_prm_rStatIgSpEfcCyl_05 = localMultiportSwitch_m[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S48>/autosar_testpoint1' */

  /* S-Function Block: <S48>/autosar_testpoint1 */
  IgSys_prm_rStatIgSpEfcCyl_06 = localMultiportSwitch_m[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S50>/autosar_testpoint1' */

  /* S-Function Block: <S50>/autosar_testpoint1 */
  IgSys_prm_rDynIgSpEfcCyl_01 = localMultiportSwitch_m[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S51>/autosar_testpoint1' */

  /* S-Function Block: <S51>/autosar_testpoint1 */
  IgSys_prm_rStatIgSpEfcCyl_01 = localMultiportSwitch_m[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S52>/autosar_testpoint1' */

  /* S-Function Block: <S52>/autosar_testpoint1 */
  IgSys_prm_rDynIgSpEfcCyl_02 = localMultiportSwitch_m[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S53>/autosar_testpoint1' */

  /* S-Function Block: <S53>/autosar_testpoint1 */
  IgSys_prm_rDynIgSpEfcCyl_03 = localMultiportSwitch_m[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S54>/autosar_testpoint1' */

  /* S-Function Block: <S54>/autosar_testpoint1 */
  IgSys_prm_rDynIgSpEfcCyl_04 = localMultiportSwitch_m[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S55>/autosar_testpoint1' */

  /* S-Function Block: <S55>/autosar_testpoint1 */
  IgSys_prm_rDynIgSpEfcCyl_05 = localMultiportSwitch_m[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S56>/autosar_testpoint1' */

  /* S-Function Block: <S56>/autosar_testpoint1 */
  IgSys_prm_rDynIgSpEfcCyl_06 = localMultiportSwitch_m[5];

  /* SignalConversion: '<S18>/Signal Conversion1' */
  localIgSys_rDynIgSpEfc = localMultiportSwitch_m[4];

  /* SignalConversion: '<S18>/Signal Conversion10' */
  localIgSys_prm_rDynIgSpEfcCyl_0 = localMultiportSwitch_m[2];

  /* SignalConversion: '<S18>/Signal Conversion11' */
  localIgSys_prm_rDynIgSpEfcCyl_g = localMultiportSwitch_m[1];

  /* SignalConversion: '<S18>/Signal Conversion2' */
  localIgSys_prm_rStatIgSpEfcCy_g = localMultiportSwitch_m[3];

  /* SignalConversion: '<S18>/Signal Conversion3' */
  localIgSys_prm_rStatIgSpEfcC_gc = localMultiportSwitch_m[5];

  /* SignalConversion: '<S18>/Signal Conversion4' */
  localIgSys_prm_rStatIgSpEfcCy_l = localMultiportSwitch_m[2];

  /* SignalConversion: '<S18>/Signal Conversion5' */
  localIgSys_prm_rStatIgSpEfcCy_e = localMultiportSwitch_m[1];

  /* SignalConversion: '<S18>/Signal Conversion6' */
  localIgSys_prm_rStatIgSpEfcCy_a = localMultiportSwitch_m[0];

  /* SignalConversion: '<S18>/Signal Conversion7' */
  localIgSys_prm_rDynIgSpEfcCyl_e = localMultiportSwitch_m[5];

  /* SignalConversion: '<S18>/Signal Conversion8' */
  localIgSys_prm_rDynIgSpEfcCyl_m = localMultiportSwitch_m[4];

  /* SignalConversion: '<S18>/Signal Conversion9' */
  localIgSys_prm_rDynIgSpEfcCyl_l = localMultiportSwitch_m[3];

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_01_irvInport2' incorporates:
   *  SignalConversion: '<S18>/Signal Conversion12'
   */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rDynIgSpEfcCyl_01_irv
    (localMultiportSwitch_m[0]);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_02_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rDynIgSpEfcCyl_02_irv
    (localIgSys_prm_rDynIgSpEfcCyl_g);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_03_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rDynIgSpEfcCyl_03_irv
    (localIgSys_prm_rDynIgSpEfcCyl_0);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_04_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rDynIgSpEfcCyl_04_irv
    (localIgSys_prm_rDynIgSpEfcCyl_l);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_05_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rDynIgSpEfcCyl_05_irv
    (localIgSys_prm_rDynIgSpEfcCyl_m);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_06_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rDynIgSpEfcCyl_06_irv
    (localIgSys_prm_rDynIgSpEfcCyl_e);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCy_05l_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rStatIgSpEfcCyl_05_irv
    (localIgSys_rDynIgSpEfc);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_01_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rStatIgSpEfcCyl_01_irv
    (localIgSys_prm_rStatIgSpEfcCy_a);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_02_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rStatIgSpEfcCyl_02_irv
    (localIgSys_prm_rStatIgSpEfcCy_e);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_03_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rStatIgSpEfcCyl_03_irv
    (localIgSys_prm_rStatIgSpEfcCy_l);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_04_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rStatIgSpEfcCyl_04_irv
    (localIgSys_prm_rStatIgSpEfcCy_g);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_06_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_prm_rStatIgSpEfcCyl_06_irv
    (localIgSys_prm_rStatIgSpEfcC_gc);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S43>/autosar_testpoint1' incorporates:
   *  Constant: '<S18>/Cste_1'
   */

  /* S-Function Block: <S43>/autosar_testpoint1 */
  IgSys_rDynIgSpEfcWoutMv_IRV_MP = 1024U;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_rDynIgSpEfcWoutMv_irvInport2' incorporates:
   *  Constant: '<S18>/Cste_1'
   *  SignalConversion: '<S18>/Signal Conversion13'
   */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_rDynIgSpEfcWoutMv_irv(1024U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S49>/autosar_testpoint1' incorporates:
   *  Constant: '<S18>/Cste_4'
   */

  /* S-Function Block: <S49>/autosar_testpoint1 */
  IgSys_rStatIgSpEfcWoutMv_IRV_MP = 1024U;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtIgSys_rStatIgSpEfcWoutMv_irvInport2' incorporates:
   *  Constant: '<S18>/Cste_4'
   *  SignalConversion: '<S18>/Signal Conversion14'
   */
  Rte_IrvWrite_RE_EngLimTqT_013_MSE_IgSys_rStatIgSpEfcWoutMv_irv(1024U);
}

/* Start for exported function: RE_EngLimTqT_009_MSE */
void RE_EngLimTqT_009_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S9>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Initialisation'
   *
   * Block requirements for '<S1>/F01_Initialisation':
   *  1. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_112.01 ;
   *  2. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_001.01 ;
   *  3. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_002.01 ;
   *  4. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_003.01 ;
   *  5. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_076.01 ;
   *  6. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_077.02 ;
   *  7. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_138.01 ;
   *  8. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_139.01 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_009_MSE */
void RE_EngLimTqT_009_MSE(void)
{
  UInt16 localSwitch_c;
  UInt32 localSwitch;

  /* S-Function (fcncallgen): '<S9>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Initialisation'
   *
   * Block requirements for '<S1>/F01_Initialisation':
   *  1. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_112.01 ;
   *  2. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_001.01 ;
   *  3. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_002.01 ;
   *  4. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_003.01 ;
   *  5. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_076.01 ;
   *  6. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_077.02 ;
   *  7. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_138.01 ;
   *  8. SubSystem "F01_Initialisation" !Trace_To : VEMS_R_10_06438_139.01 ;
   */

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S16>/Cste_1_1'
   *  Constant: '<S32>/Byp_Fonction_SC'
   *  Constant: '<S32>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localSwitch_c = IgSys_rlamClc_B;
  } else {
    localSwitch_c = 4464U;
  }

  /* SignalConversion: '<S16>/TmpSignal ConversionAtIgSys_rlamClcInport2' */
  Rte_Write_P_IgSys_rlamClc_IgSys_rlamClc(localSwitch_c);

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S16>/Cste_1'
   *  Constant: '<S33>/Byp_Fonction_SC'
   *  Constant: '<S33>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localSwitch = IgSys_lamClc_B;
  } else {
    localSwitch = 8192U;
  }

  /* SignalConversion: '<S16>/TmpSignal ConversionAtIgSys_lamClcInport2' */
  Rte_Write_P_IgSys_lamClc_IgSys_lamClc(localSwitch);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S31>/autosar_testpoint1' incorporates:
   *  Constant: '<S16>/Cste_2'
   */

  /* S-Function Block: <S31>/autosar_testpoint1 */
  IgSys_rAirLdPred_IRV_MP = 0U;

  /* SignalConversion: '<S16>/TmpSignal ConversionAtIgSys_rAirLdPred_irvInport2' incorporates:
   *  Constant: '<S16>/Cste_2'
   *  SignalConversion: '<S16>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_EngLimTqT_009_MSE_IgSys_rAirLdPred_irv(0U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S30>/autosar_testpoint1' incorporates:
   *  Constant: '<S16>/Cste_3'
   */

  /* S-Function Block: <S30>/autosar_testpoint1 */
  IgSys_rlamEngCorReq_IRV_MP = 0U;

  /* SignalConversion: '<S16>/TmpSignal ConversionAtIgSys_rlamEngCorReq_irvInport2' incorporates:
   *  Constant: '<S16>/Cste_3'
   *  SignalConversion: '<S16>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_EngLimTqT_009_MSE_IgSys_rlamEngCorReq_irv(0U);
}

/* Start for exported function: RE_EngLimTqT_001_MSE */
void RE_EngLimTqT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S10>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/IgAdvTq1_init'
   *
   * Block requirements for '<S1>/IgAdvTq1_init':
   *  1. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_104.02 ;
   *  2. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_022.02 ;
   *  5. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_071.01 ;
   *  6. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_090.01 ;
   *  7. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_091.01 ;
   *  8. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_072.01 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_001_MSE */
void RE_EngLimTqT_001_MSE(void)
{
  UInt8 localIgSys_noTDCOutCutOffDly;

  /* S-Function (fcncallgen): '<S10>/expFcn' incorporates:
   *  SubSystem: '<S1>/IgAdvTq1_init'
   *
   * Block requirements for '<S1>/IgAdvTq1_init':
   *  1. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_104.02 ;
   *  2. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_022.02 ;
   *  5. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_071.01 ;
   *  6. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_090.01 ;
   *  7. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_091.01 ;
   *  8. SubSystem "IgAdvTq1_init" !Trace_To : VEMS_R_10_06438_072.01 ;
   */

  /* user code (Output function Body for TID31) */
  Runnable_EngLimTqT_Init();

  /* Switch: '<S261>/Switch' incorporates:
   *  Constant: '<S261>/Byp_Fonction_SC'
   *  Constant: '<S261>/Int_BypC'
   *  Constant: '<S26>/Cste_15'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localIgSys_noTDCOutCutOffDly = IgSys_noTDCOutCutOffDly_B;
  } else {
    localIgSys_noTDCOutCutOffDly = 0U;
  }

  /* SignalConversion: '<S26>/TmpSignal ConversionAtIgSys_noTDCOutCutOffDlyInport2' */
  Rte_Write_P_IgSys_noTDCOutCutOffDly_IgSys_noTDCOutCutOffDly
    (localIgSys_noTDCOutCutOffDly);

  /* SignalConversion: '<S258>/copy' incorporates:
   *  Constant: '<S26>/Cste_1'
   */
  IgSys_noCylCutOffDlyOutSat = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S258>/autosar_testpoint1' */

  /* S-Function Block: <S258>/autosar_testpoint1 */

  /* SignalConversion: '<S26>/TmpSignal ConversionAtIgSys_noCylCutOffDlyOutSat_irvInport2' incorporates:
   *  Constant: '<S26>/Cste_1'
   *  SignalConversion: '<S26>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_EngLimTqT_001_MSE_IgSys_noCylCutOffDlyOutSat_irv(0U);

  /* SignalConversion: '<S259>/copy' incorporates:
   *  Constant: '<S26>/Cste_2'
   */
  IgSys_bTqIdcCutOff_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S259>/autosar_testpoint1' */

  /* S-Function Block: <S259>/autosar_testpoint1 */

  /* SignalConversion: '<S26>/TmpSignal ConversionAtIgSys_bTqIdcCutOff_irvInport2' incorporates:
   *  Constant: '<S26>/Cste_2'
   *  SignalConversion: '<S26>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_EngLimTqT_001_MSE_IgSys_bTqIdcCutOff_irv(FALSE);

  /* Switch: '<S260>/Switch' incorporates:
   *  Constant: '<S260>/Byp_Fonction_SC'
   *  Constant: '<S260>/Int_BypC'
   *  Constant: '<S26>/Cste_3'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localIgSys_noTDCOutCutOffDly = IgSys_noTDCCutOffDly_B;
  } else {
    localIgSys_noTDCOutCutOffDly = 0U;
  }

  /* SignalConversion: '<S26>/TmpSignal ConversionAtIgSys_noTDCCutOffDlyInport2' */
  Rte_Write_P_IgSys_noTDCCutOffDly_IgSys_noTDCCutOffDly
    (localIgSys_noTDCOutCutOffDly);
}

/* Start for exported function: RE_EngLimTqT_003_MSE */
void RE_EngLimTqT_003_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S11>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/IgAdvTq2_init'
   *
   * Block requirements for '<S1>/IgAdvTq2_init':
   *  1. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_106.02 ;
   *  2. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_022.02 ;
   *  5. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_068.02 ;
   *  6. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_070.01 ;
   *  7. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_092.01 ;
   *  8. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_093.01 ;
   *  9. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_094.01 ;
   *  10. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_095.01 ;
   *  11. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_101.01 ;
   *  12. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_096.01 ;
   *  13. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_102.01 ;
   *  14. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_097.01 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_003_MSE */
void RE_EngLimTqT_003_MSE(void)
{
  SInt16 localEngLim_tqIdcAirTqWoutTotCu;

  /* S-Function (fcncallgen): '<S11>/expFcn' incorporates:
   *  SubSystem: '<S1>/IgAdvTq2_init'
   *
   * Block requirements for '<S1>/IgAdvTq2_init':
   *  1. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_106.02 ;
   *  2. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_022.02 ;
   *  5. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_068.02 ;
   *  6. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_070.01 ;
   *  7. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_092.01 ;
   *  8. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_093.01 ;
   *  9. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_094.01 ;
   *  10. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_095.01 ;
   *  11. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_101.01 ;
   *  12. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_096.01 ;
   *  13. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_102.01 ;
   *  14. SubSystem "IgAdvTq2_init" !Trace_To : VEMS_R_10_06438_097.01 ;
   */

  /* Switch: '<S270>/Switch' incorporates:
   *  Constant: '<S270>/Byp_Fonction_SC'
   *  Constant: '<S270>/Int_BypC'
   *  Constant: '<S27>/Cste_3'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcAirTqWoutTotCu = EngLim_tqIdcAirTqWoutTotCutOf_B;
  } else {
    localEngLim_tqIdcAirTqWoutTotCu = 0;
  }

  /* SignalConversion: '<S27>/TmpSignal ConversionAtEngLim_tqIdcAirTqWoutTotCutOfInport2' */
  Rte_Write_P_EngLim_tqIdcAirTqWoutTotCutOf_EngLim_tqIdcAirTqWoutTotCutOf
    (localEngLim_tqIdcAirTqWoutTotCu);

  /* Switch: '<S272>/Switch' incorporates:
   *  Constant: '<S272>/Byp_Fonction_SC'
   *  Constant: '<S272>/Int_BypC'
   *  Constant: '<S27>/Cste_1'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcAirTqWoutTotCu = EngLim_tqIdcAdvOptmTrbMax_B;
  } else {
    localEngLim_tqIdcAirTqWoutTotCu = 0;
  }

  /* SignalConversion: '<S27>/TmpSignal ConversionAtEngLim_tqIdcAdvOptmTrbMaxInport2' */
  Rte_Write_P_EngLim_tqIdcAdvOptmTrbMax_EngLim_tqIdcAdvOptmTrbMax
    (localEngLim_tqIdcAirTqWoutTotCu);

  /* SignalConversion: '<S269>/copy' incorporates:
   *  Constant: '<S27>/Cste_5'
   */
  EngLim_tqIdcPresUsMax_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S269>/autosar_testpoint1' */

  /* S-Function Block: <S269>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/TmpSignal ConversionAtEngLim_tqIdcPresUsMax_irvInport2' incorporates:
   *  Constant: '<S27>/Cste_5'
   *  SignalConversion: '<S27>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_EngLimTqT_003_MSE_EngLim_tqIdcPresUsMax_irv(0);

  /* SignalConversion: '<S262>/copy' incorporates:
   *  Constant: '<S27>/Cste_4'
   */
  EngLim_tqIdcMinAirLd_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S262>/autosar_testpoint1' */

  /* S-Function Block: <S262>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/TmpSignal ConversionAtEngLim_tqIdcMinAirLd_irvInport2' incorporates:
   *  Constant: '<S27>/Cste_4'
   *  SignalConversion: '<S27>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_EngLimTqT_003_MSE_EngLim_tqIdcMinAirLd_irv(0);

  /* SignalConversion: '<S263>/copy' incorporates:
   *  Constant: '<S27>/Cste_2'
   */
  IgSys_tqIdcEstimAvgCyl_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S263>/autosar_testpoint1' */

  /* S-Function Block: <S263>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCyl_irvInport2' incorporates:
   *  Constant: '<S27>/Cste_2'
   *  SignalConversion: '<S27>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_EngLimTqT_003_MSE_IgSys_tqIdcEstimAvgCyl_irv(0);

  /* SignalConversion: '<S264>/copy' incorporates:
   *  Constant: '<S27>/Cste_6'
   */
  EngLim_tqIdcAdvOptmMaxWoutOfs = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S264>/autosar_testpoint1' */

  /* S-Function Block: <S264>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/TmpSignal ConversionAtEngLim_tqIdcAdvOptmMaxWoutOf_irvInport2' incorporates:
   *  Constant: '<S27>/Cste_6'
   *  SignalConversion: '<S27>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_EngLimTqT_003_MSE_EngLim_tqIdcAdvOptmMaxWoutOf_irv(0);

  /* SignalConversion: '<S265>/copy' incorporates:
   *  Constant: '<S27>/Cste_7'
   */
  EngLim_tqIdcMinAirLdAvgCyl = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S265>/autosar_testpoint1' */

  /* S-Function Block: <S265>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/TmpSignal ConversionAtEngLim_tqIdcMinAirLdAvgCyl_irvInport2' incorporates:
   *  Constant: '<S27>/Cste_7'
   *  SignalConversion: '<S27>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_EngLimTqT_003_MSE_EngLim_tqIdcMinAirLdAvgCyl_irv(0);

  /* SignalConversion: '<S266>/copy' incorporates:
   *  Constant: '<S27>/Cste_8'
   */
  EngLim_tqIdcTrbMaxWoutOvb_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S266>/autosar_testpoint1' */

  /* S-Function Block: <S266>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/TmpSignal ConversionAtEngLim_tqIdcTrbMaxWoutOvb_irvInport2' incorporates:
   *  Constant: '<S27>/Cste_8'
   *  SignalConversion: '<S27>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_EngLimTqT_003_MSE_EngLim_tqIdcTrbMaxWoutOvb_irv(0);

  /* SignalConversion: '<S267>/copy' incorporates:
   *  Constant: '<S27>/Cste_9'
   */
  IgSys_tqIdcEstimAvgCylWoutLam = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S267>/autosar_testpoint1' */

  /* S-Function Block: <S267>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylWoutLa_irvInport2' incorporates:
   *  Constant: '<S27>/Cste_9'
   *  SignalConversion: '<S27>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_EngLimTqT_003_MSE_IgSys_tqIdcEstimAvgCylWoutLa_irv(0);

  /* SignalConversion: '<S268>/copy' incorporates:
   *  Constant: '<S27>/Cste_10'
   */
  IgSys_tqIdcEstimAvgCylWiLam = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S268>/autosar_testpoint1' */

  /* S-Function Block: <S268>/autosar_testpoint1 */

  /* SignalConversion: '<S27>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylWiLam_irvInport2' incorporates:
   *  Constant: '<S27>/Cste_10'
   *  SignalConversion: '<S27>/Signal Conversion8'
   */
  Rte_IrvWrite_RE_EngLimTqT_003_MSE_IgSys_tqIdcEstimAvgCylWiLam_irv(0);

  /* Switch: '<S271>/Switch' incorporates:
   *  Constant: '<S271>/Byp_Fonction_SC'
   *  Constant: '<S271>/Int_BypC'
   *  Constant: '<S27>/Cste_11'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcAirTqWoutTotCu = IgSys_tqIdcEstim_B;
  } else {
    localEngLim_tqIdcAirTqWoutTotCu = 0;
  }

  /* SignalConversion: '<S27>/TmpSignal ConversionAtIgSys_tqIdcEstimInport2' */
  Rte_Write_P_IgSys_tqIdcEstim_IgSys_tqIdcEstim(localEngLim_tqIdcAirTqWoutTotCu);
}

/* Output and update for exported function: RE_EngLimTqT_005_MSE */
void RE_EngLimTqT_005_MSE(void)
{
  UInt8 localSwitch_b;
  SInt16 localEngLim_tqIdcPresUsThrMax;

  /* S-Function (fcncallgen): '<S12>/expFcn' incorporates:
   *  SubSystem: '<S1>/IgAdvTq3_init'
   *
   * Block requirements for '<S1>/IgAdvTq3_init':
   *  1. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_108.02 ;
   *  2. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_022.02 ;
   *  5. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_059.02 ;
   *  6. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_060.01 ;
   *  7. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_061.01 ;
   *  8. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_062.01 ;
   *  9. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_063.02 ;
   *  10. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_064.01 ;
   *  11. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_065.01 ;
   *  12. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_069.01 ;
   *  13. SubSystem "IgAdvTq3_init" !Trace_To : VEMS_R_10_06438_071.01 ;
   */

  /* Switch: '<S275>/Switch' incorporates:
   *  Constant: '<S275>/Byp_Fonction_SC'
   *  Constant: '<S275>/Int_BypC'
   *  Constant: '<S28>/Cste_9'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcPresUsThrMax_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcPresUsThrMaxInport2' */
  Rte_Write_P_EngLim_tqIdcPresUsThrMax_EngLim_tqIdcPresUsThrMax
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S273>/Switch' incorporates:
   *  Constant: '<S273>/Byp_Fonction_SC'
   *  Constant: '<S273>/Int_BypC'
   *  Constant: '<S28>/Cste_1'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcLdMinAdvMinSelc_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcLdMinAdvMinSelcInport2' */
  Rte_Write_P_EngLim_tqIdcLdMinAdvMinSelc_EngLim_tqIdcLdMinAdvMinSelc
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S276>/Switch' incorporates:
   *  Constant: '<S276>/Byp_Fonction_SC'
   *  Constant: '<S276>/Int_BypC'
   *  Constant: '<S28>/Cste_2'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcLdMinAdvMin_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcLdMinAdvMinInport2' */
  Rte_Write_P_EngLim_tqIdcLdMinAdvMin_EngLim_tqIdcLdMinAdvMin
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S277>/Switch' incorporates:
   *  Constant: '<S277>/Byp_Fonction_SC'
   *  Constant: '<S277>/Int_BypC'
   *  Constant: '<S28>/Cste_3'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcLdMaxTrbMaxNoOvb_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcLdMaxTrbMaxNoOvbInport2' */
  Rte_Write_P_EngLim_tqIdcLdMaxTrbMaxNoOvb_EngLim_tqIdcLdMaxTrbMaxNoOvb
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S278>/Switch' incorporates:
   *  Constant: '<S278>/Byp_Fonction_SC'
   *  Constant: '<S278>/Int_BypC'
   *  Constant: '<S28>/Cste_4'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcLdMaxTrbMax_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcLdMaxTrbMaxInport2' */
  Rte_Write_P_EngLim_tqIdcLdMaxTrbMax_EngLim_tqIdcLdMaxTrbMax
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S279>/Switch' incorporates:
   *  Constant: '<S279>/Byp_Fonction_SC'
   *  Constant: '<S279>/Int_BypC'
   *  Constant: '<S28>/Cste_5'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcEngCurMinSelc_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcEngCurMinSelcutOffInport2' */
  Rte_Write_P_EngLim_tqIdcEngCurMinSelc_EngLim_tqIdcEngCurMinSelc
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S280>/Switch' incorporates:
   *  Constant: '<S280>/Byp_Fonction_SC'
   *  Constant: '<S280>/Int_BypC'
   *  Constant: '<S28>/Cste_6'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcEngCurMin_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcEngCurMinInport2' */
  Rte_Write_P_EngLim_tqIdcEngCurMin_EngLim_tqIdcEngCurMin
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S281>/Switch' incorporates:
   *  Constant: '<S281>/Byp_Fonction_SC'
   *  Constant: '<S281>/Int_BypC'
   *  Constant: '<S28>/Cste_7'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcEngCurMax_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcEngCurMaxInport2' */
  Rte_Write_P_EngLim_tqIdcEngCurMax_EngLim_tqIdcEngCurMax
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S282>/Switch' incorporates:
   *  Constant: '<S282>/Byp_Fonction_SC'
   *  Constant: '<S282>/Int_BypC'
   *  Constant: '<S28>/Cste_8'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcPresUsThrMax = EngLim_tqIdcAirResMax_B;
  } else {
    localEngLim_tqIdcPresUsThrMax = 0;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtEngLim_tqIdcAirResMaxInport2' */
  Rte_Write_P_EngLim_tqIdcAirResMax_EngLim_tqIdcAirResMax
    (localEngLim_tqIdcPresUsThrMax);

  /* Switch: '<S274>/Switch' incorporates:
   *  Constant: '<S274>/Byp_Fonction_SC'
   *  Constant: '<S274>/Int_BypC'
   *  Constant: '<S28>/Cste_10'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localSwitch_b = IgSys_noTDCOutCutOffDly_B;
  } else {
    localSwitch_b = 0U;
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtIgSys_noTDCOutCutOffDlyInport2' */
  Rte_Write_P_IgSys_noTDCOutCutOffDly_IgSys_noTDCOutCutOffDly(localSwitch_b);
}

/* Output and update for exported function: RE_EngLimTqT_007_MSE */
void RE_EngLimTqT_007_MSE(void)
{
  SInt16 localEngLim_tqIdcEngCurGBx;

  /* S-Function (fcncallgen): '<S13>/expFcn' incorporates:
   *  SubSystem: '<S1>/IgAdvTq4_init'
   *
   * Block requirements for '<S1>/IgAdvTq4_init':
   *  1. SubSystem "IgAdvTq4_init" !Trace_To : VEMS_R_10_06438_110.01 ;
   *  2. SubSystem "IgAdvTq4_init" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "IgAdvTq4_init" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "IgAdvTq4_init" !Trace_To : VEMS_R_10_06438_022.02 ;
   *  5. SubSystem "IgAdvTq4_init" !Trace_To : VEMS_R_10_06438_067.01 ;
   *  6. SubSystem "IgAdvTq4_init" !Trace_To : VEMS_R_10_06438_066.01 ;
   */

  /* Switch: '<S283>/Switch' incorporates:
   *  Constant: '<S283>/Byp_Fonction_SC'
   *  Constant: '<S283>/Int_BypC'
   *  Constant: '<S29>/Cste_1'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcEngCurGBx = EngLim_tqIdcEngCurGBx_B;
  } else {
    localEngLim_tqIdcEngCurGBx = 0;
  }

  /* SignalConversion: '<S29>/TmpSignal ConversionAtEngLim_tqIdcEngCurGBxInport2' */
  Rte_Write_P_EngLim_tqIdcEngCurGBx_EngLim_tqIdcEngCurGBx
    (localEngLim_tqIdcEngCurGBx);

  /* Switch: '<S284>/Switch' incorporates:
   *  Constant: '<S284>/Byp_Fonction_SC'
   *  Constant: '<S284>/Int_BypC'
   *  Constant: '<S29>/Cste_2'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localEngLim_tqIdcEngCurGBx = EngLim_tqIdcEngCur_B;
  } else {
    localEngLim_tqIdcEngCurGBx = 0;
  }

  /* SignalConversion: '<S29>/TmpSignal ConversionAtEngLim_tqIdcEngCurInport2' */
  Rte_Write_P_EngLim_tqIdcEngCur_EngLim_tqIdcEngCur(localEngLim_tqIdcEngCurGBx);
}

/* Start for exported function: RE_EngLimTqT_012_DRE */
void RE_EngLimTqT_012_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S14>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Calcul_rendement_avance_min_max'
   *
   * Block requirements for '<S1>/F02_Calcul_rendement_avance_min_max':
   *  1. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_115.04 ;
   *  2. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_010.02 ;
   *  3. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_011.02 ;
   *  4. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_013.01 ;
   *  5. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_045.01 ;
   *  6. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_085.01 ;
   *  7. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_086.01 ;
   *  8. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_089.01 ;
   *  9. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_087.01 ;
   *  10. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_084.01 ;
   *  11. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_088.01 ;
   *  12. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_119.01 ;
   *  13. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_120.01 ;
   *  14. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_121.01 ;
   *  15. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_122.01 ;
   *  16. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_123.01 ;
   *  17. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_124.01 ;
   *  18. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_125.01 ;
   *  19. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_141.01 ;
   *  20. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_142.01 ;
   *  21. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_144.01 ;
   *  22. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_145.01 ;
   *  23. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_120.02 ;
   *  24. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_121.02 ;
   *  25. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_122.02 ;
   *  26. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_123.02 ;
   *  27. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_124.02 ;
   *  28. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_125.02 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_012_DRE */
void RE_EngLimTqT_012_DRE(void)
{
  Float32 localDataTypeConversion5;
  Float32 localDataTypeConversion1;
  Float32 localDataTypeConversion2;
  Boolean localTmpSignalConversionAtIgS_o;
  UInt16 localMerge4[6];
  Float32 localDataTypeConversion8[6];
  Float32 localAdd;
  Float32 localSwitch_m;
  Float32 localLookupTablenD;
  UInt8 localTmpSignalConversionAtEng_n;
  Float32 localSwitch6;
  UInt8 localTmpSignalConversionAtIg_j4;
  UInt16 localTmpSignalConversionAtIgSys;
  UInt8 localTmpSignalConversionAtIgS_h;
  UInt8 localTmpSignalConversionAtIg_fs;
  UInt8 localTmpSignalConversionAtIg_f1;
  UInt16 localMerge2;
  UInt16 localMerge1;
  UInt16 localTmpSignalConversionAtIg_bv;
  UInt16 localTmpSignalConversionAtIg_c4;
  SInt32 locali;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S14>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Calcul_rendement_avance_min_max'
   *
   * Block requirements for '<S1>/F02_Calcul_rendement_avance_min_max':
   *  1. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_115.04 ;
   *  2. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_010.02 ;
   *  3. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_011.02 ;
   *  4. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_013.01 ;
   *  5. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_045.01 ;
   *  6. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_085.01 ;
   *  7. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_086.01 ;
   *  8. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_089.01 ;
   *  9. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_087.01 ;
   *  10. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_084.01 ;
   *  11. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_088.01 ;
   *  12. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_119.01 ;
   *  13. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_120.01 ;
   *  14. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_121.01 ;
   *  15. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_122.01 ;
   *  16. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_123.01 ;
   *  17. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_124.01 ;
   *  18. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_125.01 ;
   *  19. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_141.01 ;
   *  20. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_142.01 ;
   *  21. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_144.01 ;
   *  22. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_145.01 ;
   *  23. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_120.02 ;
   *  24. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_121.02 ;
   *  25. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_122.02 ;
   *  26. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_123.02 ;
   *  27. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_124.02 ;
   *  28. SubSystem "F02_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_125.02 ;
   */

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_agIgMinOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMin'
   */
  Rte_Read_R_IgSys_agIgMin_IgSys_agIgMin(&localTmpSignalConversionAtIg_j4);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_facTarAgCorOutport2' incorporates:
   *  Inport: '<Root>/IgSys_facTarAgCor'
   */
  Rte_Read_R_IgSys_facTarAgCor_IgSys_facTarAgCor
    (&localTmpSignalConversionAtIgSys);

  /* DataTypeConversion: '<S19>/Data Type Conversion5' */
  localDataTypeConversion5 = ((Float32)localTmpSignalConversionAtIgSys) *
    0.00390625F;

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_agIgOfs80PrecTqOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgOfs80PrecTq'
   */
  Rte_Read_R_IgSys_agIgOfs80PrecTq_IgSys_agIgOfs80PrecTq
    (&localTmpSignalConversionAtIgS_h);

  /* DataTypeConversion: '<S19>/Data Type Conversion1' */
  localDataTypeConversion1 = (((Float32)localTmpSignalConversionAtIgS_h) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_agIg80PercTqOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIg80PercTq'
   */
  Rte_Read_R_IgSys_agIg80PercTq_IgSys_agIg80PercTq
    (&localTmpSignalConversionAtIg_fs);

  /* DataTypeConversion: '<S19>/Data Type Conversion2' */
  localDataTypeConversion2 = (((Float32)localTmpSignalConversionAtIg_fs) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_agIgMaxOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgMax'
   */
  Rte_Read_R_IgSys_agIgMax_IgSys_agIgMax(&localTmpSignalConversionAtIg_f1);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtEng_noCmprCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprCyl'
   */
  Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl(&localTmpSignalConversionAtEng_n);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_noCylIncPrev1Outport2' */
  IgSys_noCylIncPrev1 = Rte_IrvRead_RE_EngLimTqT_012_DRE_IgSys_noCylInc1_irv();

  /* SignalConversion: '<S19>/Signal Conversion1' incorporates:
   *  SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcPrevCyl_01Outport2'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcPrevCyl_02Outport2'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcPrevCyl_03Outport2'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcPrevCyl_04Outport2'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcPrevCyl_05Outport2'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcPrevCyl_06Outport2'
   */
  IgSys_prm_rMaxIgSpEfcPrevCyl[0] =
    Rte_IrvRead_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_01_irv();
  IgSys_prm_rMaxIgSpEfcPrevCyl[1] =
    Rte_IrvRead_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_02_irv();
  IgSys_prm_rMaxIgSpEfcPrevCyl[2] =
    Rte_IrvRead_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_03_irv();
  IgSys_prm_rMaxIgSpEfcPrevCyl[3] =
    Rte_IrvRead_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_04_irv();
  IgSys_prm_rMaxIgSpEfcPrevCyl[4] =
    Rte_IrvRead_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_05_irv();
  IgSys_prm_rMaxIgSpEfcPrevCyl[5] =
    Rte_IrvRead_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_06_irv();

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIgS_o);

  /* Outputs for enable SubSystem: '<S19>/F01_Calcul_rendement_avance_min_max' incorporates:
   *  EnablePort: '<S59>/IgSys_bAcvStructAdv'
   *
   * Block requirements for '<S19>/F01_Calcul_rendement_avance_min_max':
   *  1. SubSystem "F01_Calcul_rendement_avance_min_max" !Trace_To : VEMS_R_10_06438_014.02 ;
   */
  if (localTmpSignalConversionAtIgS_o) {
    /* DataTypeConversion: '<S59>/Data Type Conversion8' */
    for (locali = 0; locali < 6; locali++) {
      localDataTypeConversion8[locali] = ((Float32)
        IgSys_prm_rMaxIgSpEfcPrevCyl[(locali)]) * 0.0009765625F;
    }

    /* Outputs for atomic SubSystem: '<S59>/F01_Rendement_avance_min' *
     * Block requirements for '<S59>/F01_Rendement_avance_min':
     *  1. SubSystem "F01_Rendement_avance_min" !Trace_To : VEMS_R_10_06438_015.01 ;
     *  2. SubSystem "F01_Rendement_avance_min" !Trace_To : VEMS_R_10_06438_153.01 ;
     *  3. SubSystem "F01_Rendement_avance_min" !Trace_To : VEMS_R_10_06438_154.01 ;
     */

    /* Sum: '<S70>/Add' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion'
     */
    localAdd = localDataTypeConversion2 - ((((Float32)
      localTmpSignalConversionAtIg_j4) * 0.375F) - 36.0F);

    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S70>/Constant'
     *  Constant: '<S70>/Constant3'
     *  Constant: '<S70>/IgSys_bAcvLimTarAgCor_C'
     *  Logic: '<S70>/Logical Operator'
     *  RelationalOperator: '<S70>/Relational Operator'
     */
    if (IgSys_bAcvLimTarAgCor_C && (localAdd <= 0.0F)) {
      localSwitch_m = 1.0F;
    } else {
      localSwitch_m = localDataTypeConversion5;
    }

    /* DataStoreWrite: '<S70>/Data Store Write2' incorporates:
     *  Constant: '<S78>/offset'
     *  Constant: '<S78>/offset1'
     *  Constant: '<S78>/one_on_slope'
     *  DataTypeConversion: '<S78>/OutDTConv'
     *  Product: '<S78>/Product4'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Add2'
     */
    IgSys_facTarAgCorSwtMin_MP = (UInt16)((1.282051239E+002F * localSwitch_m)
      + 0.5F);

    /* Sum: '<S77>/Add2' incorporates:
     *  Constant: '<S77>/offset'
     *  Constant: '<S77>/offset1'
     *  Constant: '<S77>/one_on_slope'
     *  Product: '<S77>/Product4'
     *  Product: '<S79>/Divide'
     *  Sum: '<S70>/Add1'
     *  Sum: '<S77>/Add1'
     */
    localLookupTablenD = (((localAdd * localSwitch_m) + localDataTypeConversion1)
                          * 2.666666746E+000F) + 0.5F;

    /* DataTypeConversion: '<S77>/OutDTConv' */
    if (localLookupTablenD < 256.0F) {
      if (localLookupTablenD >= 0.0F) {
        IgSys_agIgEfcMin_MP = (UInt8)localLookupTablenD;
      } else {
        IgSys_agIgEfcMin_MP = 0U;
      }
    } else {
      IgSys_agIgEfcMin_MP = MAX_uint8_T;
    }

    /* Lookup_n-D: '<S76>/Lookup Table (n-D)' */
    localLookupTablenD = look1_iu8lftu16n10If_binlcns(IgSys_agIgEfcMin_MP,
      (&(IgSys_agIg_EfcIg_A[0])), (&(IgSys_rIgEfc_EfcIg_T[0])), 103U);

    /* end of Outputs for SubSystem: '<S59>/F01_Rendement_avance_min' */

    /* Outputs for atomic SubSystem: '<S59>/F02_Rendement_avance_max' *
     * Block requirements for '<S59>/F02_Rendement_avance_max':
     *  1. SubSystem "F02_Rendement_avance_max" !Trace_To : VEMS_R_10_06438_015.01 ;
     *  2. SubSystem "F02_Rendement_avance_max" !Trace_To : VEMS_R_10_06438_153.01 ;
     *  3. SubSystem "F02_Rendement_avance_max" !Trace_To : VEMS_R_10_06438_155.01 ;
     */

    /* Sum: '<S71>/Add' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion4'
     */
    localAdd = localDataTypeConversion2 - ((((Float32)
      localTmpSignalConversionAtIg_f1) * 0.375F) - 36.0F);

    /* Switch: '<S71>/Switch' incorporates:
     *  Constant: '<S71>/Constant'
     *  Constant: '<S71>/Constant3'
     *  Constant: '<S71>/IgSys_bAcvLimTarAgCor_C'
     *  Logic: '<S71>/Logical Operator'
     *  RelationalOperator: '<S71>/Relational Operator'
     */
    if (IgSys_bAcvLimTarAgCor_C && (localAdd <= 0.0F)) {
      localDataTypeConversion5 = 1.0F;
    }

    /* Sum: '<S81>/Add2' incorporates:
     *  Constant: '<S81>/offset'
     *  Constant: '<S81>/offset1'
     *  Constant: '<S81>/one_on_slope'
     *  Product: '<S81>/Product4'
     *  Product: '<S84>/Divide'
     *  Sum: '<S71>/Add1'
     *  Sum: '<S81>/Add1'
     */
    localAdd = (((localAdd * localDataTypeConversion5) +
                 localDataTypeConversion1) * 2.666666746E+000F) + 0.5F;

    /* DataTypeConversion: '<S81>/OutDTConv' */
    if (localAdd < 256.0F) {
      if (localAdd >= 0.0F) {
        IgSys_agIgEfcMax_MP = (UInt8)localAdd;
      } else {
        IgSys_agIgEfcMax_MP = 0U;
      }
    } else {
      IgSys_agIgEfcMax_MP = MAX_uint8_T;
    }

    /* Lookup_n-D: '<S80>/Lookup Table (n-D)' */
    localAdd = look1_iu8lftu16n10If_binlcns(IgSys_agIgEfcMax_MP,
      (&(IgSys_agIg_EfcIg_A[0])), (&(IgSys_rIgEfc_EfcIg_T[0])), 103U);

    /* MinMax: '<S71>/MinMax' incorporates:
     *  Constant: '<S71>/Constant4'
     */
    IgSys_rMaxIgEfcWoutMv = rt_MINf(1.0F, localAdd);

    /* DataStoreWrite: '<S71>/Data Store Write1' incorporates:
     *  Constant: '<S82>/offset'
     *  Constant: '<S82>/offset1'
     *  Constant: '<S82>/one_on_slope'
     *  DataTypeConversion: '<S82>/OutDTConv'
     *  Product: '<S82>/Product4'
     *  Sum: '<S82>/Add1'
     *  Sum: '<S82>/Add2'
     */
    localtmp = (1024.0F * IgSys_rMaxIgEfcWoutMv) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        IgSys_rMaxIgEfcWoutMv_MP = (UInt16)localtmp;
      } else {
        IgSys_rMaxIgEfcWoutMv_MP = 0U;
      }
    } else {
      IgSys_rMaxIgEfcWoutMv_MP = MAX_uint16_T;
    }

    /* DataStoreWrite: '<S71>/Data Store Write2' incorporates:
     *  Constant: '<S83>/offset'
     *  Constant: '<S83>/offset1'
     *  Constant: '<S83>/one_on_slope'
     *  DataTypeConversion: '<S83>/OutDTConv'
     *  Product: '<S83>/Product4'
     *  Sum: '<S83>/Add1'
     *  Sum: '<S83>/Add2'
     */
    IgSys_facTarAgCorSwtMax_MP = (UInt16)((1.282051239E+002F *
      localDataTypeConversion5) + 0.5F);

    /* end of Outputs for SubSystem: '<S59>/F02_Rendement_avance_max' */

    /* Outputs for atomic SubSystem: '<S59>/F03_Rendement_applique_max' *
     * Block requirements for '<S59>/F03_Rendement_applique_max':
     *  1. SubSystem "F03_Rendement_applique_max" !Trace_To : VEMS_R_10_06438_016.02 ;
     */

    /* MinMax: '<S72>/MinMax' incorporates:
     *  Constant: '<S72>/Ext_noCylEng_SC'
     */
    localTmpSignalConversionAtIg_j4 = (UInt8)rt_MIN(Ext_noCylEng_SC,
      IgSys_noCylIncPrev1);

    /* Sum: '<S72>/Add1' incorporates:
     *  Constant: '<S72>/Cste_1_1'
     */
    locali = 1 + localTmpSignalConversionAtIg_j4;
    if (((UInt32)locali) > 255U) {
      EngLimTqT_B.Merge3_m = MAX_uint8_T;
    } else {
      EngLimTqT_B.Merge3_m = (UInt8)locali;
    }

    /* Switch: '<S72>/Switch1' incorporates:
     *  Constant: '<S72>/Cste_1'
     *  RelationalOperator: '<S72>/Relational Operator1'
     */
    if (localTmpSignalConversionAtEng_n == 1) {
      localAdd = IgSys_rMaxIgEfcWoutMv;
    } else {
      localAdd = localDataTypeConversion8[0];
    }

    /* Switch: '<S72>/Switch4' incorporates:
     *  Constant: '<S72>/Cste_2'
     *  RelationalOperator: '<S72>/Relational Operator2'
     */
    if (localTmpSignalConversionAtEng_n == 2) {
      localSwitch_m = IgSys_rMaxIgEfcWoutMv;
    } else {
      localSwitch_m = localDataTypeConversion8[1];
    }

    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S72>/Cste_3'
     *  RelationalOperator: '<S72>/Relational Operator4'
     */
    if (localTmpSignalConversionAtEng_n == 3) {
      localDataTypeConversion2 = IgSys_rMaxIgEfcWoutMv;
    } else {
      localDataTypeConversion2 = localDataTypeConversion8[2];
    }

    /* Switch: '<S72>/Switch5' incorporates:
     *  Constant: '<S72>/Cste_4'
     *  RelationalOperator: '<S72>/Relational Operator6'
     */
    if (localTmpSignalConversionAtEng_n == 4) {
      localDataTypeConversion5 = IgSys_rMaxIgEfcWoutMv;
    } else {
      localDataTypeConversion5 = localDataTypeConversion8[3];
    }

    /* Switch: '<S72>/Switch3' incorporates:
     *  Constant: '<S72>/Cste_5'
     *  RelationalOperator: '<S72>/Relational Operator7'
     */
    if (localTmpSignalConversionAtEng_n == 5) {
      localDataTypeConversion1 = IgSys_rMaxIgEfcWoutMv;
    } else {
      localDataTypeConversion1 = localDataTypeConversion8[4];
    }

    /* Switch: '<S72>/Switch6' incorporates:
     *  Constant: '<S72>/Cste_6'
     *  RelationalOperator: '<S72>/Relational Operator8'
     */
    if (localTmpSignalConversionAtEng_n == 6) {
      localSwitch6 = IgSys_rMaxIgEfcWoutMv;
    } else {
      localSwitch6 = localDataTypeConversion8[5];
    }

    /* end of Outputs for SubSystem: '<S59>/F03_Rendement_applique_max' */

    /* DataTypeConversion: '<S73>/OutDTConv' incorporates:
     *  Constant: '<S70>/Constant4'
     *  Constant: '<S73>/offset'
     *  Constant: '<S73>/offset1'
     *  Constant: '<S73>/one_on_slope'
     *  MinMax: '<S70>/MinMax'
     *  Product: '<S73>/Product4'
     *  Sum: '<S73>/Add1'
     *  Sum: '<S73>/Add2'
     */
    localtmp = (1024.0F * rt_MINf(1.0F, localLookupTablenD)) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localMerge2 = (UInt16)localtmp;
      } else {
        localMerge2 = 0U;
      }
    } else {
      localMerge2 = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S74>/OutDTConv' incorporates:
     *  Constant: '<S72>/Cste_7'
     *  Constant: '<S74>/offset'
     *  Constant: '<S74>/offset1'
     *  Constant: '<S74>/one_on_slope'
     *  DataTypeConversion: '<S72>/Data Type Conversion2'
     *  MinMax: '<S72>/MinMax1'
     *  Product: '<S74>/Product4'
     *  Product: '<S85>/Divide'
     *  Sum: '<S72>/Add2'
     *  Sum: '<S74>/Add1'
     *  Sum: '<S74>/Add2'
     */
    localtmp = (((((((localAdd + localSwitch_m) + localDataTypeConversion2) +
                    localDataTypeConversion5) + localDataTypeConversion1) +
                  localSwitch6) / ((Float32)((UInt8)rt_MAX(1U,
      localTmpSignalConversionAtIg_j4)))) * 1024.0F) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localMerge1 = (UInt16)localtmp;
      } else {
        localMerge1 = 0U;
      }
    } else {
      localMerge1 = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S75>/OutDTConv' incorporates:
     *  Constant: '<S75>/offset'
     *  Constant: '<S75>/offset1'
     *  Constant: '<S75>/one_on_slope'
     *  Product: '<S75>/Product4'
     *  Sum: '<S75>/Add1'
     *  Sum: '<S75>/Add2'
     */
    localtmp = (1024.0F * localAdd) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgSys = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtIgSys = 0U;
      }
    } else {
      localTmpSignalConversionAtIgSys = MAX_uint16_T;
    }

    localMerge4[0] = localTmpSignalConversionAtIgSys;
    localtmp = (1024.0F * localSwitch_m) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgSys = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtIgSys = 0U;
      }
    } else {
      localTmpSignalConversionAtIgSys = MAX_uint16_T;
    }

    localMerge4[1] = localTmpSignalConversionAtIgSys;
    localtmp = (1024.0F * localDataTypeConversion2) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgSys = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtIgSys = 0U;
      }
    } else {
      localTmpSignalConversionAtIgSys = MAX_uint16_T;
    }

    localMerge4[2] = localTmpSignalConversionAtIgSys;
    localtmp = (1024.0F * localDataTypeConversion5) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgSys = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtIgSys = 0U;
      }
    } else {
      localTmpSignalConversionAtIgSys = MAX_uint16_T;
    }

    localMerge4[3] = localTmpSignalConversionAtIgSys;
    localtmp = (1024.0F * localDataTypeConversion1) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgSys = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtIgSys = 0U;
      }
    } else {
      localTmpSignalConversionAtIgSys = MAX_uint16_T;
    }

    localMerge4[4] = localTmpSignalConversionAtIgSys;
    localtmp = (1024.0F * localSwitch6) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtIgSys = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtIgSys = 0U;
      }
    } else {
      localTmpSignalConversionAtIgSys = MAX_uint16_T;
    }

    localMerge4[5] = localTmpSignalConversionAtIgSys;
  }

  /* end of Outputs for SubSystem: '<S19>/F01_Calcul_rendement_avance_min_max' */

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_rMinIgEfc_PrevOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rMinIgEfc_INPUT'
   */
  Rte_Read_R_IgSys_rMinIgEfc_IgSys_rMinIgEfc(&localTmpSignalConversionAtIg_bv);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_rMaxIgEfc_PrevOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rMaxIgEfc_INPUT'
   */
  Rte_Read_R_IgSys_rMaxIgEfc_IgSys_rMaxIgEfc(&localTmpSignalConversionAtIg_c4);

  /* Outputs for enable SubSystem: '<S19>/F01_Calcul_rendement_avance_min_max_Default' incorporates:
   *  EnablePort: '<S60>/IgSys_bAcvStructAdv'
   *  Logic: '<S19>/Logical Operator'
   */
  if (!localTmpSignalConversionAtIgS_o) {
    /* SignalConversion: '<S60>/Signal Conversion4' */
    localMerge2 = localTmpSignalConversionAtIg_bv;

    /* SignalConversion: '<S60>/Signal Conversion2' */
    localMerge1 = localTmpSignalConversionAtIg_c4;

    /* SignalConversion: '<S60>/Signal Conversion3' */
    EngLimTqT_B.Merge3_m = IgSys_noCylIncPrev1;

    /* SignalConversion: '<S60>/Signal Conversion1' */
    for (locali = 0; locali < 6; locali++) {
      localMerge4[locali] = IgSys_prm_rMaxIgSpEfcPrevCyl[(locali)];
    }
  }

  /* end of Outputs for SubSystem: '<S19>/F01_Calcul_rendement_avance_min_max_Default' */

  /* SignalConversion: '<S61>/copy' */
  IgSys_prm_rMaxIgSpEfcCyl_06 = localMerge4[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S61>/autosar_testpoint1' */

  /* S-Function Block: <S61>/autosar_testpoint1 */

  /* SignalConversion: '<S62>/copy' */
  IgSys_noCylInc1_IRV_MP = EngLimTqT_B.Merge3_m;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S62>/autosar_testpoint1' */

  /* S-Function Block: <S62>/autosar_testpoint1 */

  /* SignalConversion: '<S63>/copy' */
  IgSys_prm_rMaxIgSpEfcCyl_01 = localMerge4[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S63>/autosar_testpoint1' */

  /* S-Function Block: <S63>/autosar_testpoint1 */

  /* SignalConversion: '<S64>/copy' */
  IgSys_prm_rMaxIgSpEfcCyl_02 = localMerge4[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S64>/autosar_testpoint1' */

  /* S-Function Block: <S64>/autosar_testpoint1 */

  /* SignalConversion: '<S65>/copy' */
  IgSys_prm_rMaxIgSpEfcCyl_03 = localMerge4[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S65>/autosar_testpoint1' */

  /* S-Function Block: <S65>/autosar_testpoint1 */

  /* SignalConversion: '<S66>/copy' */
  IgSys_prm_rMaxIgSpEfcCyl_04 = localMerge4[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S66>/autosar_testpoint1' */

  /* S-Function Block: <S66>/autosar_testpoint1 */

  /* SignalConversion: '<S67>/copy' */
  IgSys_prm_rMaxIgSpEfcCyl_05 = localMerge4[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S67>/autosar_testpoint1' */

  /* S-Function Block: <S67>/autosar_testpoint1 */

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_noCylInc1_irvInport2' incorporates:
   *  SignalConversion: '<S19>/Signal Conversion9'
   */
  Rte_IrvWrite_RE_EngLimTqT_012_DRE_IgSys_noCylInc1_irv(EngLimTqT_B.Merge3_m);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_006_irvInport2' incorporates:
   *  SignalConversion: '<S19>/Signal Conversion10'
   */
  Rte_IrvWrite_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_06_irv(localMerge4
    [5]);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_01_irvInport2' incorporates:
   *  SignalConversion: '<S19>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_01_irv(localMerge4
    [0]);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_02_irvInport2' incorporates:
   *  SignalConversion: '<S19>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_02_irv(localMerge4
    [1]);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_03_irvInport2' incorporates:
   *  SignalConversion: '<S19>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_03_irv(localMerge4
    [2]);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_04_irvInport2' incorporates:
   *  SignalConversion: '<S19>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_04_irv(localMerge4
    [3]);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_prm_rMaxIgSpEfcCyl_05_rvInport2' incorporates:
   *  SignalConversion: '<S19>/Signal Conversion8'
   */
  Rte_IrvWrite_RE_EngLimTqT_012_DRE_IgSys_prm_rMaxIgSpEfcCyl_05_irv(localMerge4
    [4]);

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S68>/Byp_Fonction_SC'
   *  Constant: '<S68>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localMerge1 = IgSys_rMaxIgEfc_B;
  }

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_rMaxIgEfcInport2' */
  Rte_Write_P_IgSys_rMaxIgEfc_IgSys_rMaxIgEfc(localMerge1);

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/Byp_Fonction_SC'
   *  Constant: '<S69>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localMerge2 = IgSys_rMinIgEfc_B;
  }

  /* SignalConversion: '<S19>/TmpSignal ConversionAtIgSys_rMinIgEfcInport2' */
  Rte_Write_P_IgSys_rMinIgEfc_IgSys_rMinIgEfc(localMerge2);
}

/* Start for exported function: RE_EngLimTqT_014_DRE */
void RE_EngLimTqT_014_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S15>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F03_Calcul_rendement_avance_courante'
   *
   * Block requirements for '<S1>/F03_Calcul_rendement_avance_courante':
   *  1. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_117.05 ;
   *  2. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_010.02 ;
   *  3. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_011.02 ;
   *  4. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_016.05 ;
   *  5. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_045.01 ;
   *  6. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_089.01 ;
   *  7. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_087.01 ;
   *  8. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_084.01 ;
   *  9. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_083.01 ;
   *  10. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_082.01 ;
   *  11. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_088.01 ;
   *  12. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_119.01 ;
   *  13. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_126.02 ;
   *  14. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_127.02 ;
   *  15. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_128.02 ;
   *  16. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_129.02 ;
   *  17. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_130.02 ;
   *  18. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_131.02 ;
   *  19. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_103.01 ;
   *  20. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_098.01 ;
   *  21. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_098.01 ;
   *  22. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_143.01 ;
   *  23. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_146.01 ;
   *  24. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_147.01 ;
   *  25. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_148.01 ;
   *  26. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_132.02 ;
   *  27. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_133.02 ;
   *  28. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_134.02 ;
   *  29. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_134.02 ;
   *  30. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_135.02 ;
   *  31. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_136.02 ;
   *  32. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_137.02 ;
   *  33. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_158.01 ;
   *  34. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_159.01 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_014_DRE */
void RE_EngLimTqT_014_DRE(void)
{
  Float32 localDataTypeConversion5_k;
  Float32 localDataTypeConversion1_d;
  Float32 localDataTypeConversion2_m;
  Boolean localTmpSignalConversionAtIg_jn;
  Float32 localDataTypeConversion1_m[6];
  Float32 localDataTypeConversion8_k[6];
  Float32 localAdd_kv;
  Float32 localSwitch_f;
  Float32 localmin;
  Float32 localSwitch1_ip;
  Float32 localSwitch4_e;
  Float32 localSwitch2_k;
  Float32 localSwitch5_p;
  Float32 localSwitch3_h;
  Float32 localSwitch6_o;
  Float32 localSwitch3_o;
  Float32 localSwitch6_a;
  UInt16 localTmpSignalConversionAtIgS_p;
  UInt8 localTmpSignalConversionAtIg_mq;
  UInt8 localTmpSignalConversionAtIg_hz;
  UInt8 localTmpSignalConversionAtIg_hf;
  UInt8 localTmpSignalConversionAtIg_bb;
  UInt16 localIgSys_prm_rDynIgSpEfcCy_pi;
  UInt16 localIgSys_prm_rDynIgSpEfcCyl_k;
  UInt16 localIgSys_rDynIgSpEfcWoutMv__h;
  UInt16 localIgSys_rStatIgSpEfcWoutMv_d;
  UInt16 localIgSys_prm_rStatIgSpEfcC_gb;
  UInt16 localIgSys_prm_rStatIgSpEfcC_gy;
  UInt16 localIgSys_prm_rStatIgSpEfcC_em;
  UInt16 localIgSys_prm_rStatIgSpEfcCy_m;
  UInt16 localIgSys_prm_rStatIgSpEfcCy_c;
  UInt16 localIgSys_prm_rStatIgSpEfcCy_o;
  UInt16 localTmpSignalConversionAtIg_d3;
  UInt16 localTmpSignalConversionAtIg_kd;
  SInt32 locali;

  /* S-Function (fcncallgen): '<S15>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_Calcul_rendement_avance_courante'
   *
   * Block requirements for '<S1>/F03_Calcul_rendement_avance_courante':
   *  1. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_117.05 ;
   *  2. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_010.02 ;
   *  3. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_011.02 ;
   *  4. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_016.05 ;
   *  5. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_045.01 ;
   *  6. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_089.01 ;
   *  7. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_087.01 ;
   *  8. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_084.01 ;
   *  9. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_083.01 ;
   *  10. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_082.01 ;
   *  11. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_088.01 ;
   *  12. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_119.01 ;
   *  13. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_126.02 ;
   *  14. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_127.02 ;
   *  15. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_128.02 ;
   *  16. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_129.02 ;
   *  17. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_130.02 ;
   *  18. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_131.02 ;
   *  19. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_103.01 ;
   *  20. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_098.01 ;
   *  21. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_098.01 ;
   *  22. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_143.01 ;
   *  23. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_146.01 ;
   *  24. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_147.01 ;
   *  25. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_148.01 ;
   *  26. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_132.02 ;
   *  27. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_133.02 ;
   *  28. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_134.02 ;
   *  29. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_134.02 ;
   *  30. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_135.02 ;
   *  31. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_136.02 ;
   *  32. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_137.02 ;
   *  33. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_158.01 ;
   *  34. SubSystem "F03_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_159.01 ;
   */

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_facTarAgCorOutport2' incorporates:
   *  Inport: '<Root>/IgSys_facTarAgCor'
   */
  Rte_Read_R_IgSys_facTarAgCor_IgSys_facTarAgCor
    (&localTmpSignalConversionAtIgS_p);

  /* DataTypeConversion: '<S23>/Data Type Conversion5' */
  localDataTypeConversion5_k = ((Float32)localTmpSignalConversionAtIgS_p) *
    0.00390625F;

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_agIg80PercTqOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIg80PercTq'
   */
  Rte_Read_R_IgSys_agIg80PercTq_IgSys_agIg80PercTq
    (&localTmpSignalConversionAtIg_mq);

  /* DataTypeConversion: '<S23>/Data Type Conversion1' */
  localDataTypeConversion1_d = (((Float32)localTmpSignalConversionAtIg_mq) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_agIgOfs80PrecTqOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgOfs80PrecTq'
   */
  Rte_Read_R_IgSys_agIgOfs80PrecTq_IgSys_agIgOfs80PrecTq
    (&localTmpSignalConversionAtIg_hz);

  /* DataTypeConversion: '<S23>/Data Type Conversion2' */
  localDataTypeConversion2_m = (((Float32)localTmpSignalConversionAtIg_hz) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_agIgSpOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgSp'
   */
  Rte_Read_R_IgSys_agIgSp_IgSys_agIgSp(&localTmpSignalConversionAtIg_hf);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_agIgSpWoutKnkDetOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgSpWoutKnkDet'
   */
  Rte_Read_R_IgSys_agIgSpWoutKnkDet_IgSys_agIgSpWoutKnkDet
    (&localTmpSignalConversionAtIg_bb);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtEng_noCmprCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprCyl'
   */
  Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl
    (&EngLimTqT_B.TmpSignalConversionAtEng_noCmpr);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_noCylIncPrev1Outport2' */
  localTmpSignalConversionAtIg_mq =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_noCylInc1_irv();

  /* SignalConversion: '<S23>/Signal Conversion1' incorporates:
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcPrevCy_01Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcPrevCyl_02Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcPrevCyl_03Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcPrevCyl_04Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcPrevCyl_05Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcPrevCyl_06Outport2'
   */
  IgSys_prm_rStatIgSpEfcPrevCyl[0] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_01_irv();
  IgSys_prm_rStatIgSpEfcPrevCyl[1] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_02_irv();
  IgSys_prm_rStatIgSpEfcPrevCyl[2] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_03_irv();
  IgSys_prm_rStatIgSpEfcPrevCyl[3] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_04_irv();
  IgSys_prm_rStatIgSpEfcPrevCyl[4] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_05_irv();
  IgSys_prm_rStatIgSpEfcPrevCyl[5] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_06_irv();

  /* SignalConversion: '<S23>/Signal Conversion3' incorporates:
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcPrevCyl_01Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcPrevCyl_02Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcPrevCyl_03Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcPrevCyl_04Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcPrevCyl_05Outport2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcPrevCyl_06Outport2'
   */
  IgSys_prm_rDynIgSpEfcPrevCyl[0] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_01_irv();
  IgSys_prm_rDynIgSpEfcPrevCyl[1] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_02_irv();
  IgSys_prm_rDynIgSpEfcPrevCyl[2] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_03_irv();
  IgSys_prm_rDynIgSpEfcPrevCyl[3] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_04_irv();
  IgSys_prm_rDynIgSpEfcPrevCyl[4] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_05_irv();
  IgSys_prm_rDynIgSpEfcPrevCyl[5] =
    Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_06_irv();

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIg_jn);

  /* Outputs for enable SubSystem: '<S23>/F01_Calcul_rendement_avance_courante' incorporates:
   *  EnablePort: '<S180>/IgSys_bAcvStructAdv'
   *
   * Block requirements for '<S23>/F01_Calcul_rendement_avance_courante':
   *  1. SubSystem "F01_Calcul_rendement_avance_courante" !Trace_To : VEMS_R_10_06438_017.02 ;
   */
  if (localTmpSignalConversionAtIg_jn) {
    for (locali = 0; locali < 6; locali++) {
      /* DataTypeConversion: '<S180>/Data Type Conversion1' */
      localDataTypeConversion1_m[locali] = ((Float32)
        IgSys_prm_rDynIgSpEfcPrevCyl[(locali)]) * 0.0009765625F;

      /* DataTypeConversion: '<S180>/Data Type Conversion8' */
      localDataTypeConversion8_k[locali] = ((Float32)
        IgSys_prm_rStatIgSpEfcPrevCyl[(locali)]) * 0.0009765625F;
    }

    /* Outputs for atomic SubSystem: '<S180>/F01_Rendement_avance_dyn' *
     * Block requirements for '<S180>/F01_Rendement_avance_dyn':
     *  1. SubSystem "F01_Rendement_avance_dyn" !Trace_To : VEMS_R_10_06438_015.01 ;
     *  2. SubSystem "F01_Rendement_avance_dyn" !Trace_To : VEMS_R_10_06438_153.01 ;
     *  3. SubSystem "F01_Rendement_avance_dyn" !Trace_To : VEMS_R_10_06438_156.01 ;
     */

    /* Sum: '<S198>/Add' incorporates:
     *  DataTypeConversion: '<S23>/Data Type Conversion3'
     */
    localAdd_kv = localDataTypeConversion1_d - ((((Float32)
      localTmpSignalConversionAtIg_hf) * 0.375F) - 36.0F);

    /* Switch: '<S198>/Switch' incorporates:
     *  Constant: '<S198>/Constant'
     *  Constant: '<S198>/Constant3'
     *  Constant: '<S198>/IgSys_bAcvLimTarAgCor_C'
     *  Logic: '<S198>/Logical Operator'
     *  RelationalOperator: '<S198>/Relational Operator'
     */
    if (IgSys_bAcvLimTarAgCor_C && (localAdd_kv <= 0.0F)) {
      localSwitch_f = 1.0F;
    } else {
      localSwitch_f = localDataTypeConversion5_k;
    }

    /* DataStoreWrite: '<S198>/Data Store Write2' incorporates:
     *  Constant: '<S210>/offset'
     *  Constant: '<S210>/offset1'
     *  Constant: '<S210>/one_on_slope'
     *  DataTypeConversion: '<S210>/OutDTConv'
     *  Product: '<S210>/Product4'
     *  Sum: '<S210>/Add1'
     *  Sum: '<S210>/Add2'
     */
    IgSys_facTarAgCorSwtDyn_MP = (UInt16)((1.282051239E+002F * localSwitch_f)
      + 0.5F);

    /* Sum: '<S209>/Add2' incorporates:
     *  Constant: '<S209>/offset'
     *  Constant: '<S209>/offset1'
     *  Constant: '<S209>/one_on_slope'
     *  Product: '<S209>/Product4'
     *  Product: '<S211>/Divide'
     *  Sum: '<S198>/Add1'
     *  Sum: '<S209>/Add1'
     */
    localAdd_kv = (((localAdd_kv * localSwitch_f) + localDataTypeConversion2_m) *
                   2.666666746E+000F) + 0.5F;

    /* DataTypeConversion: '<S209>/OutDTConv' */
    if (localAdd_kv < 256.0F) {
      if (localAdd_kv >= 0.0F) {
        IgSys_agIgEfcDyn_MP = (UInt8)localAdd_kv;
      } else {
        IgSys_agIgEfcDyn_MP = 0U;
      }
    } else {
      IgSys_agIgEfcDyn_MP = MAX_uint8_T;
    }

    /* Lookup_n-D: '<S208>/Lookup Table (n-D)' */
    localAdd_kv = look1_iu8lftu16n10If_binlcns(IgSys_agIgEfcDyn_MP,
      (&(IgSys_agIg_EfcIg_A[0])), (&(IgSys_rIgEfc_EfcIg_T[0])), 103U);

    /* MinMax: '<S198>/MinMax' incorporates:
     *  Constant: '<S198>/Constant4'
     */
    localmin = rt_MINf(1.0F, localAdd_kv);

    /* end of Outputs for SubSystem: '<S180>/F01_Rendement_avance_dyn' */

    /* Outputs for atomic SubSystem: '<S180>/F02_Rendement_applique_dyn' *
     * Block requirements for '<S180>/F02_Rendement_applique_dyn':
     *  1. SubSystem "F02_Rendement_applique_dyn" !Trace_To : VEMS_R_10_06438_018.01 ;
     */

    /* Switch: '<S199>/Switch1' incorporates:
     *  Constant: '<S199>/Cste_1'
     *  RelationalOperator: '<S199>/Relational Operator1'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 1) {
      localSwitch1_ip = localmin;
    } else {
      localSwitch1_ip = localDataTypeConversion1_m[0];
    }

    /* Switch: '<S199>/Switch4' incorporates:
     *  Constant: '<S199>/Cste_2'
     *  RelationalOperator: '<S199>/Relational Operator2'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 2) {
      localSwitch4_e = localmin;
    } else {
      localSwitch4_e = localDataTypeConversion1_m[1];
    }

    /* Switch: '<S199>/Switch2' incorporates:
     *  Constant: '<S199>/Cste_3'
     *  RelationalOperator: '<S199>/Relational Operator4'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 3) {
      localSwitch2_k = localmin;
    } else {
      localSwitch2_k = localDataTypeConversion1_m[2];
    }

    /* Switch: '<S199>/Switch5' incorporates:
     *  Constant: '<S199>/Cste_4'
     *  RelationalOperator: '<S199>/Relational Operator6'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 4) {
      localSwitch5_p = localmin;
    } else {
      localSwitch5_p = localDataTypeConversion1_m[3];
    }

    /* Switch: '<S199>/Switch3' incorporates:
     *  Constant: '<S199>/Cste_5'
     *  RelationalOperator: '<S199>/Relational Operator7'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 5) {
      localSwitch3_h = localmin;
    } else {
      localSwitch3_h = localDataTypeConversion1_m[4];
    }

    /* Switch: '<S199>/Switch6' incorporates:
     *  Constant: '<S199>/Cste_6'
     *  RelationalOperator: '<S199>/Relational Operator8'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 6) {
      localSwitch6_o = localmin;
    } else {
      localSwitch6_o = localDataTypeConversion1_m[5];
    }

    /* MinMax: '<S199>/MinMax' incorporates:
     *  Constant: '<S199>/Ext_noCylEng_SC'
     */
    localTmpSignalConversionAtIg_hz = (UInt8)rt_MIN(Ext_noCylEng_SC,
      localTmpSignalConversionAtIg_mq);

    /* end of Outputs for SubSystem: '<S180>/F02_Rendement_applique_dyn' */

    /* Outputs for atomic SubSystem: '<S180>/F03_Rendement_avance_stat' *
     * Block requirements for '<S180>/F03_Rendement_avance_stat':
     *  1. SubSystem "F03_Rendement_avance_stat" !Trace_To : VEMS_R_10_06438_015.01 ;
     *  2. SubSystem "F03_Rendement_avance_stat" !Trace_To : VEMS_R_10_06438_153.01 ;
     *  3. SubSystem "F03_Rendement_avance_stat" !Trace_To : VEMS_R_10_06438_157.01 ;
     */

    /* Sum: '<S200>/Add' incorporates:
     *  DataTypeConversion: '<S23>/Data Type Conversion4'
     */
    localAdd_kv = localDataTypeConversion1_d - ((((Float32)
      localTmpSignalConversionAtIg_bb) * 0.375F) - 36.0F);

    /* Switch: '<S200>/Switch' incorporates:
     *  Constant: '<S200>/Constant'
     *  Constant: '<S200>/Constant3'
     *  Constant: '<S200>/IgSys_bAcvLimTarAgCor_C'
     *  Logic: '<S200>/Logical Operator'
     *  RelationalOperator: '<S200>/Relational Operator'
     */
    if (IgSys_bAcvLimTarAgCor_C && (localAdd_kv <= 0.0F)) {
      localDataTypeConversion5_k = 1.0F;
    }

    /* DataStoreWrite: '<S200>/Data Store Write1' incorporates:
     *  Constant: '<S215>/offset'
     *  Constant: '<S215>/offset1'
     *  Constant: '<S215>/one_on_slope'
     *  DataTypeConversion: '<S215>/OutDTConv'
     *  Product: '<S215>/Product4'
     *  Sum: '<S215>/Add1'
     *  Sum: '<S215>/Add2'
     */
    IgSys_facTarAgCorSwtStat_MP = (UInt16)((1.282051239E+002F *
      localDataTypeConversion5_k) + 0.5F);

    /* Sum: '<S214>/Add2' incorporates:
     *  Constant: '<S214>/offset'
     *  Constant: '<S214>/offset1'
     *  Constant: '<S214>/one_on_slope'
     *  Product: '<S214>/Product4'
     *  Product: '<S216>/Divide'
     *  Sum: '<S200>/Add1'
     *  Sum: '<S214>/Add1'
     */
    localAdd_kv = (((localAdd_kv * localDataTypeConversion5_k) +
                    localDataTypeConversion2_m) * 2.666666746E+000F) + 0.5F;

    /* DataTypeConversion: '<S214>/OutDTConv' */
    if (localAdd_kv < 256.0F) {
      if (localAdd_kv >= 0.0F) {
        IgSys_agIgEfcStat_MP = (UInt8)localAdd_kv;
      } else {
        IgSys_agIgEfcStat_MP = 0U;
      }
    } else {
      IgSys_agIgEfcStat_MP = MAX_uint8_T;
    }

    /* Lookup_n-D: '<S213>/Lookup Table (n-D)' */
    localAdd_kv = look1_iu8lftu16n10If_binlcns(IgSys_agIgEfcStat_MP,
      (&(IgSys_agIg_EfcIg_A[0])), (&(IgSys_rIgEfc_EfcIg_T[0])), 103U);

    /* MinMax: '<S200>/MinMax' incorporates:
     *  Constant: '<S200>/Constant4'
     */
    localAdd_kv = rt_MINf(1.0F, localAdd_kv);

    /* end of Outputs for SubSystem: '<S180>/F03_Rendement_avance_stat' */

    /* Outputs for atomic SubSystem: '<S180>/F04_Rendement_applique_stat' *
     * Block requirements for '<S180>/F04_Rendement_applique_stat':
     *  1. SubSystem "F04_Rendement_applique_stat" !Trace_To : VEMS_R_10_06438_019.01 ;
     */

    /* Switch: '<S201>/Switch1' incorporates:
     *  Constant: '<S201>/Cste_1'
     *  RelationalOperator: '<S201>/Relational Operator1'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 1) {
      localSwitch_f = localAdd_kv;
    } else {
      localSwitch_f = localDataTypeConversion8_k[0];
    }

    /* Switch: '<S201>/Switch4' incorporates:
     *  Constant: '<S201>/Cste_2'
     *  RelationalOperator: '<S201>/Relational Operator2'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 2) {
      localDataTypeConversion1_d = localAdd_kv;
    } else {
      localDataTypeConversion1_d = localDataTypeConversion8_k[1];
    }

    /* Switch: '<S201>/Switch2' incorporates:
     *  Constant: '<S201>/Cste_3'
     *  RelationalOperator: '<S201>/Relational Operator4'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 3) {
      localDataTypeConversion5_k = localAdd_kv;
    } else {
      localDataTypeConversion5_k = localDataTypeConversion8_k[2];
    }

    /* Switch: '<S201>/Switch5' incorporates:
     *  Constant: '<S201>/Cste_4'
     *  RelationalOperator: '<S201>/Relational Operator6'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 4) {
      localDataTypeConversion2_m = localAdd_kv;
    } else {
      localDataTypeConversion2_m = localDataTypeConversion8_k[3];
    }

    /* Switch: '<S201>/Switch3' incorporates:
     *  Constant: '<S201>/Cste_5'
     *  RelationalOperator: '<S201>/Relational Operator7'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 5) {
      localSwitch3_o = localAdd_kv;
    } else {
      localSwitch3_o = localDataTypeConversion8_k[4];
    }

    /* Switch: '<S201>/Switch6' incorporates:
     *  Constant: '<S201>/Cste_6'
     *  RelationalOperator: '<S201>/Relational Operator8'
     */
    if (EngLimTqT_B.TmpSignalConversionAtEng_noCmpr == 6) {
      localSwitch6_a = localAdd_kv;
    } else {
      localSwitch6_a = localDataTypeConversion8_k[5];
    }

    /* MinMax: '<S201>/MinMax' incorporates:
     *  Constant: '<S201>/Ext_noCylEng_SC'
     */
    localTmpSignalConversionAtIg_mq = (UInt8)rt_MIN(Ext_noCylEng_SC,
      localTmpSignalConversionAtIg_mq);

    /* end of Outputs for SubSystem: '<S180>/F04_Rendement_applique_stat' */

    /* DataTypeConversion: '<S202>/OutDTConv' incorporates:
     *  Constant: '<S202>/offset'
     *  Constant: '<S202>/offset1'
     *  Constant: '<S202>/one_on_slope'
     *  Product: '<S202>/Product4'
     *  Sum: '<S202>/Add1'
     *  Sum: '<S202>/Add2'
     */
    localmin = (1024.0F * localmin) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        EngLimTqT_B.Merge5_b = (UInt16)localmin;
      } else {
        EngLimTqT_B.Merge5_b = 0U;
      }
    } else {
      EngLimTqT_B.Merge5_b = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S203>/OutDTConv' incorporates:
     *  Constant: '<S203>/offset'
     *  Constant: '<S203>/offset1'
     *  Constant: '<S203>/one_on_slope'
     *  Product: '<S203>/Product4'
     *  Sum: '<S203>/Add1'
     *  Sum: '<S203>/Add2'
     */
    localmin = (1024.0F * localAdd_kv) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        EngLimTqT_B.Merge6_d = (UInt16)localmin;
      } else {
        EngLimTqT_B.Merge6_d = 0U;
      }
    } else {
      EngLimTqT_B.Merge6_d = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S204>/OutDTConv' incorporates:
     *  Constant: '<S199>/Cste_1_1'
     *  Constant: '<S204>/offset'
     *  Constant: '<S204>/offset1'
     *  Constant: '<S204>/one_on_slope'
     *  DataTypeConversion: '<S199>/Data Type Conversion1'
     *  MinMax: '<S199>/MinMax1'
     *  Product: '<S204>/Product4'
     *  Product: '<S212>/Divide'
     *  Sum: '<S199>/Add2'
     *  Sum: '<S204>/Add1'
     *  Sum: '<S204>/Add2'
     */
    localmin = (((((((localSwitch1_ip + localSwitch4_e) + localSwitch2_k) +
                    localSwitch5_p) + localSwitch3_h) + localSwitch6_o) /
                 ((Float32)((UInt8)rt_MAX(1U, localTmpSignalConversionAtIg_hz))))
                * 1024.0F) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        EngLimTqT_B.Merge2_o = (UInt16)localmin;
      } else {
        EngLimTqT_B.Merge2_o = 0U;
      }
    } else {
      EngLimTqT_B.Merge2_o = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S205>/OutDTConv' incorporates:
     *  Constant: '<S205>/offset'
     *  Constant: '<S205>/offset1'
     *  Constant: '<S205>/one_on_slope'
     *  Product: '<S205>/Product4'
     *  Sum: '<S205>/Add1'
     *  Sum: '<S205>/Add2'
     */
    localmin = (1024.0F * localSwitch1_ip) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge4_g[0] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localSwitch4_e) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge4_g[1] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localSwitch2_k) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge4_g[2] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localSwitch5_p) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge4_g[3] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localSwitch3_h) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge4_g[4] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localSwitch6_o) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge4_g[5] = localTmpSignalConversionAtIgS_p;

    /* DataTypeConversion: '<S206>/OutDTConv' incorporates:
     *  Constant: '<S201>/Cste_1_1'
     *  Constant: '<S206>/offset'
     *  Constant: '<S206>/offset1'
     *  Constant: '<S206>/one_on_slope'
     *  DataTypeConversion: '<S201>/Data Type Conversion1'
     *  MinMax: '<S201>/MinMax1'
     *  Product: '<S206>/Product4'
     *  Product: '<S217>/Divide'
     *  Sum: '<S201>/Add2'
     *  Sum: '<S206>/Add1'
     *  Sum: '<S206>/Add2'
     */
    localmin = (((((((localSwitch_f + localDataTypeConversion1_d) +
                     localDataTypeConversion5_k) + localDataTypeConversion2_m) +
                   localSwitch3_o) + localSwitch6_a) / ((Float32)((UInt8)
      rt_MAX(1U, localTmpSignalConversionAtIg_mq)))) * 1024.0F) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        EngLimTqT_B.Merge1_l = (UInt16)localmin;
      } else {
        EngLimTqT_B.Merge1_l = 0U;
      }
    } else {
      EngLimTqT_B.Merge1_l = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S207>/OutDTConv' incorporates:
     *  Constant: '<S207>/offset'
     *  Constant: '<S207>/offset1'
     *  Constant: '<S207>/one_on_slope'
     *  Product: '<S207>/Product4'
     *  Sum: '<S207>/Add1'
     *  Sum: '<S207>/Add2'
     */
    localmin = (1024.0F * localSwitch_f) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge3_b[0] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localDataTypeConversion1_d) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge3_b[1] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localDataTypeConversion5_k) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge3_b[2] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localDataTypeConversion2_m) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge3_b[3] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localSwitch3_o) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge3_b[4] = localTmpSignalConversionAtIgS_p;
    localmin = (1024.0F * localSwitch6_a) + 0.5F;
    if (localmin < 65536.0F) {
      if (localmin >= 0.0F) {
        localTmpSignalConversionAtIgS_p = (UInt16)localmin;
      } else {
        localTmpSignalConversionAtIgS_p = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_p = MAX_uint16_T;
    }

    EngLimTqT_B.Merge3_b[5] = localTmpSignalConversionAtIgS_p;
  }

  /* end of Outputs for SubSystem: '<S23>/F01_Calcul_rendement_avance_courante' */

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_rDynIgSpEfcPrevOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rDynIgSpEfc_INPUT'
   */
  Rte_Read_R_IgSys_rDynIgSpEfc_IgSys_rDynIgSpEfc
    (&localTmpSignalConversionAtIg_d3);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_rStatIgSpEfc_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rStatIgSpEfc_INPUT'
   */
  Rte_Read_R_IgSys_rStatIgSpEfc_IgSys_rStatIgSpEfc
    (&localTmpSignalConversionAtIg_kd);

  /* Outputs for enable SubSystem: '<S23>/F01_Calcul_rendement_avance_courante_Default' incorporates:
   *  EnablePort: '<S181>/IgSys_bAcvStructAdv'
   *  Logic: '<S23>/Logical Operator'
   *
   * Block requirements for '<S23>/F01_Calcul_rendement_avance_courante_Default':
   *  1. SubSystem "F01_Calcul_rendement_avance_courante_Default" !Trace_To : VEMS_R_10_06438_017.02 ;
   */
  if (!localTmpSignalConversionAtIg_jn) {
    /* SignalConversion: '<S181>/Signal Conversion7' */
    EngLimTqT_B.Merge2_o = localTmpSignalConversionAtIg_d3;

    /* SignalConversion: '<S181>/Signal Conversion1' */
    EngLimTqT_B.Merge1_l = localTmpSignalConversionAtIg_kd;
    for (locali = 0; locali < 6; locali++) {
      /* SignalConversion: '<S181>/Signal Conversion2' */
      EngLimTqT_B.Merge3_b[(locali)] = IgSys_prm_rStatIgSpEfcPrevCyl[(locali)];

      /* SignalConversion: '<S181>/Signal Conversion3' */
      EngLimTqT_B.Merge4_g[(locali)] = IgSys_prm_rDynIgSpEfcPrevCyl[(locali)];
    }

    /* SignalConversion: '<S181>/Signal Conversion4' incorporates:
     *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_rDynIgSpEfcWoutMvPrevOutport2'
     */
    EngLimTqT_B.Merge5_b =
      Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_rDynIgSpEfcWoutMv_irv();

    /* SignalConversion: '<S181>/Signal Conversion5' incorporates:
     *  SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_rStatIgSpEfcWoutMvPrevOutport2'
     */
    EngLimTqT_B.Merge6_d =
      Rte_IrvRead_RE_EngLimTqT_014_DRE_IgSys_rStatIgSpEfcWoutMv_irv();
  }

  /* end of Outputs for SubSystem: '<S23>/F01_Calcul_rendement_avance_courante_Default' */

  /* SignalConversion: '<S182>/copy' */
  IgSys_rDynIgSpEfcWoutMv_IRV_MP = EngLimTqT_B.Merge5_b;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S182>/autosar_testpoint1' */

  /* S-Function Block: <S182>/autosar_testpoint1 */

  /* SignalConversion: '<S183>/copy' */
  IgSys_prm_rStatIgSpEfcCyl_02 = EngLimTqT_B.Merge3_b[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S183>/autosar_testpoint1' */

  /* S-Function Block: <S183>/autosar_testpoint1 */

  /* SignalConversion: '<S184>/copy' */
  IgSys_prm_rStatIgSpEfcCyl_03 = EngLimTqT_B.Merge3_b[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S184>/autosar_testpoint1' */

  /* S-Function Block: <S184>/autosar_testpoint1 */

  /* SignalConversion: '<S185>/copy' */
  IgSys_prm_rStatIgSpEfcCyl_04 = EngLimTqT_B.Merge3_b[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S185>/autosar_testpoint1' */

  /* S-Function Block: <S185>/autosar_testpoint1 */

  /* SignalConversion: '<S186>/copy' */
  IgSys_prm_rStatIgSpEfcCyl_05 = EngLimTqT_B.Merge3_b[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S186>/autosar_testpoint1' */

  /* S-Function Block: <S186>/autosar_testpoint1 */

  /* SignalConversion: '<S187>/copy' */
  IgSys_prm_rStatIgSpEfcCyl_06 = EngLimTqT_B.Merge3_b[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S187>/autosar_testpoint1' */

  /* S-Function Block: <S187>/autosar_testpoint1 */

  /* SignalConversion: '<S188>/copy' */
  IgSys_prm_rDynIgSpEfcCyl_05 = EngLimTqT_B.Merge4_g[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S188>/autosar_testpoint1' */

  /* S-Function Block: <S188>/autosar_testpoint1 */

  /* SignalConversion: '<S189>/copy' */
  IgSys_prm_rDynIgSpEfcCyl_06 = EngLimTqT_B.Merge4_g[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S189>/autosar_testpoint1' */

  /* S-Function Block: <S189>/autosar_testpoint1 */

  /* SignalConversion: '<S190>/copy' */
  IgSys_rStatIgSpEfcWoutMv_IRV_MP = EngLimTqT_B.Merge6_d;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S190>/autosar_testpoint1' */

  /* S-Function Block: <S190>/autosar_testpoint1 */

  /* SignalConversion: '<S191>/copy' */
  IgSys_prm_rDynIgSpEfcCyl_01 = EngLimTqT_B.Merge4_g[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S191>/autosar_testpoint1' */

  /* S-Function Block: <S191>/autosar_testpoint1 */

  /* SignalConversion: '<S192>/copy' */
  IgSys_prm_rStatIgSpEfcCyl_01 = EngLimTqT_B.Merge3_b[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S192>/autosar_testpoint1' */

  /* S-Function Block: <S192>/autosar_testpoint1 */

  /* SignalConversion: '<S193>/copy' */
  IgSys_prm_rDynIgSpEfcCyl_02 = EngLimTqT_B.Merge4_g[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S193>/autosar_testpoint1' */

  /* S-Function Block: <S193>/autosar_testpoint1 */

  /* SignalConversion: '<S194>/copy' */
  IgSys_prm_rDynIgSpEfcCyl_03 = EngLimTqT_B.Merge4_g[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S194>/autosar_testpoint1' */

  /* S-Function Block: <S194>/autosar_testpoint1 */

  /* SignalConversion: '<S195>/copy' */
  IgSys_prm_rDynIgSpEfcCyl_04 = EngLimTqT_B.Merge4_g[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S195>/autosar_testpoint1' */

  /* S-Function Block: <S195>/autosar_testpoint1 */

  /* SignalConversion: '<S23>/Signal Conversion10' */
  localTmpSignalConversionAtIgS_p = EngLimTqT_B.Merge4_g[1];

  /* SignalConversion: '<S23>/Signal Conversion11' */
  localTmpSignalConversionAtIg_d3 = EngLimTqT_B.Merge4_g[2];

  /* SignalConversion: '<S23>/Signal Conversion12' */
  localTmpSignalConversionAtIg_kd = EngLimTqT_B.Merge4_g[3];

  /* SignalConversion: '<S23>/Signal Conversion13' */
  localIgSys_prm_rDynIgSpEfcCy_pi = EngLimTqT_B.Merge4_g[4];

  /* SignalConversion: '<S23>/Signal Conversion14' */
  localIgSys_prm_rDynIgSpEfcCyl_k = EngLimTqT_B.Merge4_g[5];

  /* SignalConversion: '<S23>/Signal Conversion15' */
  localIgSys_rDynIgSpEfcWoutMv__h = EngLimTqT_B.Merge5_b;

  /* SignalConversion: '<S23>/Signal Conversion17' */
  localIgSys_rStatIgSpEfcWoutMv_d = EngLimTqT_B.Merge6_d;

  /* SignalConversion: '<S23>/Signal Conversion2' */
  localIgSys_prm_rStatIgSpEfcC_gb = EngLimTqT_B.Merge3_b[0];

  /* SignalConversion: '<S23>/Signal Conversion4' */
  localIgSys_prm_rStatIgSpEfcC_gy = EngLimTqT_B.Merge3_b[1];

  /* SignalConversion: '<S23>/Signal Conversion5' */
  localIgSys_prm_rStatIgSpEfcC_em = EngLimTqT_B.Merge3_b[2];

  /* SignalConversion: '<S23>/Signal Conversion6' */
  localIgSys_prm_rStatIgSpEfcCy_m = EngLimTqT_B.Merge3_b[3];

  /* SignalConversion: '<S23>/Signal Conversion7' */
  localIgSys_prm_rStatIgSpEfcCy_c = EngLimTqT_B.Merge3_b[4];

  /* SignalConversion: '<S23>/Signal Conversion8' */
  localIgSys_prm_rStatIgSpEfcCy_o = EngLimTqT_B.Merge3_b[5];

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_01_irvInport2' incorporates:
   *  SignalConversion: '<S23>/Signal Conversion9'
   */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_01_irv
    (EngLimTqT_B.Merge4_g[0]);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_02_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_02_irv
    (localTmpSignalConversionAtIgS_p);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_03_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_03_irv
    (localTmpSignalConversionAtIg_d3);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_04_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_04_irv
    (localTmpSignalConversionAtIg_kd);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_05_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_05_irv
    (localIgSys_prm_rDynIgSpEfcCy_pi);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rDynIgSpEfcCyl_06_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rDynIgSpEfcCyl_06_irv
    (localIgSys_prm_rDynIgSpEfcCyl_k);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCy_05l_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_05_irv
    (localIgSys_prm_rStatIgSpEfcCy_c);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_01_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_01_irv
    (localIgSys_prm_rStatIgSpEfcC_gb);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_02_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_02_irv
    (localIgSys_prm_rStatIgSpEfcC_gy);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_03_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_03_irv
    (localIgSys_prm_rStatIgSpEfcC_em);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_04_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_04_irv
    (localIgSys_prm_rStatIgSpEfcCy_m);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_prm_rStatIgSpEfcCyl_06_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_prm_rStatIgSpEfcCyl_06_irv
    (localIgSys_prm_rStatIgSpEfcCy_o);

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S197>/Byp_Fonction_SC'
   *  Constant: '<S197>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_p = IgSys_rDynIgSpEfc_B;
  } else {
    localTmpSignalConversionAtIgS_p = EngLimTqT_B.Merge2_o;
  }

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_rDynIgSpEfcInport2' */
  Rte_Write_P_IgSys_rDynIgSpEfc_IgSys_rDynIgSpEfc
    (localTmpSignalConversionAtIgS_p);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_rDynIgSpEfcWoutMv_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_rDynIgSpEfcWoutMv_irv
    (localIgSys_rDynIgSpEfcWoutMv__h);

  /* Switch: '<S196>/Switch' incorporates:
   *  Constant: '<S196>/Byp_Fonction_SC'
   *  Constant: '<S196>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_p = IgSys_rStatIgSpEfc_B;
  } else {
    localTmpSignalConversionAtIgS_p = EngLimTqT_B.Merge1_l;
  }

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_rStatIgSpEfcInport2' */
  Rte_Write_P_IgSys_rStatIgSpEfc_IgSys_rStatIgSpEfc
    (localTmpSignalConversionAtIgS_p);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtIgSys_rStatIgSpEfcWoutMv_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_014_DRE_IgSys_rStatIgSpEfcWoutMv_irv
    (localIgSys_rStatIgSpEfcWoutMv_d);
}

/* Start for exported function: RE_EngLimTqT_002_DRE */
void RE_EngLimTqT_002_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Retarder_coupure_reinj'
   *
   * Block requirements for '<S1>/F02_Retarder_coupure_reinj':
   *  1. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_105.04 ;
   *  2. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_023.01 ;
   *  5. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_041.01 ;
   *  6. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_042.01 ;
   *  7. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_046.01 ;
   *  8. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_043.01 ;
   *  9. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_071.01 ;
   *  10. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_090.01 ;
   *  11. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_091.01 ;
   *  12. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_072.01 ;
   *  13. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_151.01 ;
   *  14. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_152.01 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_002_DRE */
void RE_EngLimTqT_002_DRE(void)
{
  Boolean localTmpSignalConversionAtIgS_i;
  UInt8 localTmpSignalConversionAtIg_bl;
  UInt8 localTmpSignalConversionAtIg_l2;
  UInt8 localSwitch2_e;
  UInt8 localTmpSignalConversionAtInjSy;
  Boolean localUnitDelay_k;
  Boolean localUnitDelay_a;
  Boolean localUnitDelay_n;
  Boolean localUnitDelay_p;
  Boolean localUnitDelay_d;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt8 localUnitDelay_i;
  UInt8 localUnitDelay_g;
  UInt8 localUnitDelay_h;
  UInt8 localUnitDelay_j;
  SInt32 localtmp;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Retarder_coupure_reinj'
   *
   * Block requirements for '<S1>/F02_Retarder_coupure_reinj':
   *  1. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_105.04 ;
   *  2. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_023.01 ;
   *  5. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_041.01 ;
   *  6. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_042.01 ;
   *  7. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_046.01 ;
   *  8. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_043.01 ;
   *  9. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_071.01 ;
   *  10. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_090.01 ;
   *  11. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_091.01 ;
   *  12. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_072.01 ;
   *  13. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_151.01 ;
   *  14. SubSystem "F02_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_152.01 ;
   */

  /* SignalConversion: '<S21>/TmpSignal ConversionAtInjSys_noCylCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_noCylCutOff'
   */
  Rte_Read_R_InjSys_noCylCutOff_InjSys_noCylCutOff
    (&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtInjSys_bTotCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bTotCutOff'
   */
  Rte_Read_R_InjSys_bTotCutOff_InjSys_bTotCutOff
    (&EngLimTqT_B.TmpSignalConversionAtInjSys_bTo);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_bAcvStructAirOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAir'
   */
  Rte_Read_R_IgSys_bAcvStructAir_IgSys_bAcvStructAir
    (&localTmpSignalConversionAtIgS_i);

  /* Outputs for enable SubSystem: '<S21>/F01_Retarder_coupure_reinj' incorporates:
   *  EnablePort: '<S111>/IgSys_bAcvStructAir'
   *
   * Block requirements for '<S21>/F01_Retarder_coupure_reinj':
   *  1. SubSystem "F01_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_024.01 ;
   */
  if (localTmpSignalConversionAtIgS_i) {
    /* Outputs for atomic SubSystem: '<S111>/F01_Preparer_detection_coupure' *
     * Block requirements for '<S111>/F01_Preparer_detection_coupure':
     *  1. SubSystem "F01_Preparer_detection_coupure" !Trace_To : VEMS_R_10_06438_025.01 ;
     */

    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S117>/Cste_3'
     *  Constant: '<S117>/Ext_noCylEng_SC'
     *  RelationalOperator: '<S126>/UpperRelop'
     */
    if (Ext_noCylEng_SC < 3) {
      localSwitch2_e = 3U;
    } else {
      localSwitch2_e = Ext_noCylEng_SC;
    }

    /* Switch: '<S126>/Switch2' incorporates:
     *  Constant: '<S117>/Cste_6'
     *  Constant: '<S117>/Ext_noCylEng_SC'
     *  RelationalOperator: '<S126>/LowerRelop1'
     */
    if (Ext_noCylEng_SC > 6) {
      localSwitch2_e = 6U;
    }

    /* Sum: '<S117>/Subtract1' incorporates:
     *  Constant: '<S117>/Cste_1'
     */
    localtmp = localSwitch2_e - 1;
    if (localtmp <= 0) {
      localSwitch2_e = 0U;
    } else {
      localSwitch2_e = (UInt8)localtmp;
    }

    /* MinMax: '<S117>/MinMax1' */
    IgSys_noCylCutOffSat = (UInt8)rt_MIN(localSwitch2_e,
      localTmpSignalConversionAtInjSy);

    /* UnitDelay: '<S123>/Unit Delay' */
    IgSys_noCylCutOffSatDly = EngLimTqT_DWork.UnitDelay_DSTATE_o;

    /* RelationalOperator: '<S117>/Relational Operator' */
    IgSys_bCylCutOffSat = (IgSys_noCylCutOffSat != IgSys_noCylCutOffSatDly);

    /* Update for UnitDelay: '<S123>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_o = IgSys_noCylCutOffSat;

    /* end of Outputs for SubSystem: '<S111>/F01_Preparer_detection_coupure' */

    /* Outputs for trigger SubSystem: '<S111>/F02_Detecter_coupure' incorporates:
     *  TriggerPort: '<S118>/IgSys_bCylCutOffSat'
     *
     * Block requirements for '<S111>/F02_Detecter_coupure':
     *  1. SubSystem "F02_Detecter_coupure" !Trace_To : VEMS_R_10_06438_026.01 ;
     */
    if (IgSys_bCylCutOffSat &&
        (EngLimTqT_PrevZCSigState.F02_Detecter_coupure_Trig_ZCE != POS_ZCSIG)) {
      /* RelationalOperator: '<S118>/Relational Operator' */
      IgSys_bCylCutOffTrigSat = (IgSys_noCylCutOffSat > IgSys_noCylCutOffSatDly);
    }

    EngLimTqT_PrevZCSigState.F02_Detecter_coupure_Trig_ZCE = (UInt8)
      (IgSys_bCylCutOffSat ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

    /* end of Outputs for SubSystem: '<S111>/F02_Detecter_coupure' */

    /* Outputs for atomic SubSystem: '<S111>/F03_Retarder_coupure_reinj' *
     * Block requirements for '<S111>/F03_Retarder_coupure_reinj':
     *  1. SubSystem "F03_Retarder_coupure_reinj" !Trace_To : VEMS_R_10_06438_027.01 ;
     */

    /* Switch: '<S119>/Switch' incorporates:
     *  Constant: '<S119>/IgSys_noTDCCutOffDly_C'
     *  Constant: '<S119>/IgSys_noTDCOutCutOffDly_C'
     */
    if (EngLimTqT_B.TmpSignalConversionAtInjSys_bTo) {
      localSwitch2_e = IgSys_noTDCCutOffDly_C;
    } else {
      localSwitch2_e = IgSys_noTDCOutCutOffDly_C;
    }

    /* UnitDelay: '<S132>/Unit Delay' */
    localUnitDelay_k = EngLimTqT_DWork.UnitDelay_DSTATE_c;

    /* UnitDelay: '<S131>/Unit Delay' */
    localUnitDelay_a = EngLimTqT_DWork.UnitDelay_DSTATE_n;

    /* UnitDelay: '<S130>/Unit Delay' */
    localUnitDelay_n = EngLimTqT_DWork.UnitDelay_DSTATE_do;

    /* UnitDelay: '<S129>/Unit Delay' */
    localUnitDelay_p = EngLimTqT_DWork.UnitDelay_DSTATE_p;

    /* UnitDelay: '<S128>/Unit Delay' */
    localUnitDelay_d = EngLimTqT_DWork.UnitDelay_DSTATE_bj;

    /* MultiPortSwitch: '<S119>/Multiport Switch' incorporates:
     *  UnitDelay: '<S127>/Unit Delay'
     */
    switch (localSwitch2_e) {
     case 0:
      IgSys_bTotCutOffDly = EngLimTqT_B.TmpSignalConversionAtInjSys_bTo;
      break;

     case 1:
      IgSys_bTotCutOffDly = EngLimTqT_DWork.UnitDelay_DSTATE_c;
      break;

     case 2:
      IgSys_bTotCutOffDly = EngLimTqT_DWork.UnitDelay_DSTATE_n;
      break;

     case 3:
      IgSys_bTotCutOffDly = EngLimTqT_DWork.UnitDelay_DSTATE_do;
      break;

     case 4:
      IgSys_bTotCutOffDly = EngLimTqT_DWork.UnitDelay_DSTATE_p;
      break;

     case 5:
      IgSys_bTotCutOffDly = EngLimTqT_DWork.UnitDelay_DSTATE_bj;
      break;

     default:
      IgSys_bTotCutOffDly = EngLimTqT_DWork.UnitDelay_DSTATE_cd;
      break;
    }

    /* Update for UnitDelay: '<S132>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_c =
      EngLimTqT_B.TmpSignalConversionAtInjSys_bTo;

    /* Update for UnitDelay: '<S131>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_n = localUnitDelay_k;

    /* Update for UnitDelay: '<S130>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_do = localUnitDelay_a;

    /* Update for UnitDelay: '<S129>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_p = localUnitDelay_n;

    /* Update for UnitDelay: '<S128>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_bj = localUnitDelay_p;

    /* Update for UnitDelay: '<S127>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_cd = localUnitDelay_d;

    /* end of Outputs for SubSystem: '<S111>/F03_Retarder_coupure_reinj' */

    /* Outputs for atomic SubSystem: '<S111>/F04_Annuler_couples' *
     * Block requirements for '<S111>/F04_Annuler_couples':
     *  1. SubSystem "F04_Annuler_couples" !Trace_To : VEMS_R_10_06438_028.01 ;
     */

    /* Logic: '<S120>/Logical Operator' incorporates:
     *  Constant: '<S120>/IgSys_nEngStallThd_C'
     *  RelationalOperator: '<S120>/Relational Operator1'
     */
    EngLimTqT_B.Merge3_e = (IgSys_bTotCutOffDly ||
      (localTmpSignalConversionAtExt_n <= IgSys_nEngStallThd_C));

    /* end of Outputs for SubSystem: '<S111>/F04_Annuler_couples' */

    /* Outputs for atomic SubSystem: '<S111>/F05_Appliquer_retard' *
     * Block requirements for '<S111>/F05_Appliquer_retard':
     *  1. SubSystem "F05_Appliquer_retard" !Trace_To : VEMS_R_10_06438_029.01 ;
     */

    /* Switch: '<S121>/Switch' incorporates:
     *  Constant: '<S119>/IgSys_noTDCCutOffDly_C'
     *  Constant: '<S119>/IgSys_noTDCOutCutOffDly_C'
     */
    if (IgSys_bCylCutOffTrigSat) {
      localSwitch2_e = IgSys_noTDCCutOffDly_C;
    } else {
      localSwitch2_e = IgSys_noTDCOutCutOffDly_C;
    }

    /* UnitDelay: '<S136>/Unit Delay' */
    localTmpSignalConversionAtInjSy = EngLimTqT_DWork.UnitDelay_DSTATE;

    /* UnitDelay: '<S137>/Unit Delay' */
    localUnitDelay_i = EngLimTqT_DWork.UnitDelay_DSTATE_b;

    /* UnitDelay: '<S138>/Unit Delay' */
    localUnitDelay_g = EngLimTqT_DWork.UnitDelay_DSTATE_l;

    /* UnitDelay: '<S133>/Unit Delay' */
    localUnitDelay_h = EngLimTqT_DWork.UnitDelay_DSTATE_d;

    /* UnitDelay: '<S134>/Unit Delay' */
    localUnitDelay_j = EngLimTqT_DWork.UnitDelay_DSTATE_br;

    /* MultiPortSwitch: '<S121>/Multiport Switch' incorporates:
     *  UnitDelay: '<S135>/Unit Delay'
     */
    switch (localSwitch2_e) {
     case 0:
      EngLimTqT_B.Merge2_j = IgSys_noCylCutOffSat;
      break;

     case 1:
      EngLimTqT_B.Merge2_j = EngLimTqT_DWork.UnitDelay_DSTATE;
      break;

     case 2:
      EngLimTqT_B.Merge2_j = EngLimTqT_DWork.UnitDelay_DSTATE_b;
      break;

     case 3:
      EngLimTqT_B.Merge2_j = EngLimTqT_DWork.UnitDelay_DSTATE_l;
      break;

     case 4:
      EngLimTqT_B.Merge2_j = EngLimTqT_DWork.UnitDelay_DSTATE_d;
      break;

     case 5:
      EngLimTqT_B.Merge2_j = EngLimTqT_DWork.UnitDelay_DSTATE_br;
      break;

     default:
      EngLimTqT_B.Merge2_j = EngLimTqT_DWork.UnitDelay_DSTATE_e;
      break;
    }

    /* Update for UnitDelay: '<S136>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE = IgSys_noCylCutOffSat;

    /* Update for UnitDelay: '<S137>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_b = localTmpSignalConversionAtInjSy;

    /* Update for UnitDelay: '<S138>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_l = localUnitDelay_i;

    /* Update for UnitDelay: '<S133>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_d = localUnitDelay_g;

    /* Update for UnitDelay: '<S134>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_br = localUnitDelay_h;

    /* Update for UnitDelay: '<S135>/Unit Delay' */
    EngLimTqT_DWork.UnitDelay_DSTATE_e = localUnitDelay_j;

    /* end of Outputs for SubSystem: '<S111>/F05_Appliquer_retard' */

    /* SignalConversion: '<S111>/Signal Conversion1' incorporates:
     *  Constant: '<S119>/IgSys_noTDCOutCutOffDly_C'
     */
    EngLimTqT_B.Merge1_n = IgSys_noTDCOutCutOffDly_C;

    /* SignalConversion: '<S111>/Signal Conversion2' incorporates:
     *  Constant: '<S119>/IgSys_noTDCCutOffDly_C'
     */
    EngLimTqT_B.Merge5_i = IgSys_noTDCCutOffDly_C;
  }

  /* end of Outputs for SubSystem: '<S21>/F01_Retarder_coupure_reinj' */

  /* SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_noTDCOutCutOffDlyPrevOutport2' incorporates:
   *  Inport: '<Root>/IgSys_noTDCOutCutOffDly_INPUT'
   */
  Rte_Read_R_IgSys_noTDCOutCutOffDly_IgSys_noTDCOutCutOffDly
    (&localTmpSignalConversionAtIg_bl);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_bTqIdcCutOffPrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtIgSys_bT_k =
    Rte_IrvRead_RE_EngLimTqT_002_DRE_IgSys_bTqIdcCutOff_irv();

  /* SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_noTDCCutOffDlyPrevOutport2' incorporates:
   *  Inport: '<Root>/IgSys_noTDCCutOffDly_INPUT'
   */
  Rte_Read_R_IgSys_noTDCCutOffDly_IgSys_noTDCCutOffDly
    (&localTmpSignalConversionAtIg_l2);

  /* Outputs for enable SubSystem: '<S21>/F01_Retarder_coupure_reinj_Default' incorporates:
   *  EnablePort: '<S112>/IgSys_bAcvStructAir'
   *  Logic: '<S21>/Logical Operator'
   *
   * Block requirements for '<S21>/F01_Retarder_coupure_reinj_Default':
   *  1. SubSystem "F01_Retarder_coupure_reinj_Default" !Trace_To : VEMS_R_10_06438_024.01 ;
   */
  if (!localTmpSignalConversionAtIgS_i) {
    /* SignalConversion: '<S112>/Signal Conversion3' incorporates:
     *  SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_noCylCutOffDlyOutSatPrevOutport2'
     */
    EngLimTqT_B.Merge2_j =
      Rte_IrvRead_RE_EngLimTqT_002_DRE_IgSys_noCylCutOffDlyOutSat_irv();

    /* SignalConversion: '<S112>/Signal Conversion1' */
    EngLimTqT_B.Merge1_n = localTmpSignalConversionAtIg_bl;

    /* SignalConversion: '<S112>/Signal Conversion2' */
    EngLimTqT_B.Merge3_e = EngLimTqT_B.TmpSignalConversionAtIgSys_bT_k;

    /* SignalConversion: '<S112>/Signal Conversion4' */
    EngLimTqT_B.Merge5_i = localTmpSignalConversionAtIg_l2;
  }

  /* end of Outputs for SubSystem: '<S21>/F01_Retarder_coupure_reinj_Default' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S113>/autosar_testpoint1' */

  /* S-Function Block: <S113>/autosar_testpoint1 */
  IgSys_noCylCutOffDlyOutSat = EngLimTqT_B.Merge2_j;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S114>/autosar_testpoint1' */

  /* S-Function Block: <S114>/autosar_testpoint1 */
  IgSys_bTqIdcCutOff_IRV_MP = EngLimTqT_B.Merge3_e;

  /* SignalConversion: '<S21>/Signal Conversion1' */
  localSwitch2_e = EngLimTqT_B.Merge2_j;

  /* SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_bTqIdcCutOff_irvInport2' incorporates:
   *  SignalConversion: '<S21>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_EngLimTqT_002_DRE_IgSys_bTqIdcCutOff_irv(EngLimTqT_B.Merge3_e);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_noCylCutOffDlyOutSat_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_002_DRE_IgSys_noCylCutOffDlyOutSat_irv
    (localSwitch2_e);

  /* Switch: '<S115>/Switch' incorporates:
   *  Constant: '<S115>/Byp_Fonction_SC'
   *  Constant: '<S115>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localSwitch2_e = IgSys_noTDCCutOffDly_B;
  } else {
    localSwitch2_e = EngLimTqT_B.Merge5_i;
  }

  /* SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_noTDCCutOffDlyInport2' */
  Rte_Write_P_IgSys_noTDCCutOffDly_IgSys_noTDCCutOffDly(localSwitch2_e);

  /* Switch: '<S116>/Switch' incorporates:
   *  Constant: '<S116>/Byp_Fonction_SC'
   *  Constant: '<S116>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localSwitch2_e = IgSys_noTDCOutCutOffDly_B;
  } else {
    localSwitch2_e = EngLimTqT_B.Merge1_n;
  }

  /* SignalConversion: '<S21>/TmpSignal ConversionAtIgSys_noTDCOutCutOffDlyInport2' */
  Rte_Write_P_IgSys_noTDCOutCutOffDly_IgSys_noTDCOutCutOffDly(localSwitch2_e);
}

/* Start for exported function: RE_EngLimTqT_004_DRE */
void RE_EngLimTqT_004_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F03_Calcul_couple_optimal'
   *
   * Block requirements for '<S1>/F03_Calcul_couple_optimal':
   *  1. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_107.03 ;
   *  2. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_041.01 ;
   *  5. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_053.01 ;
   *  6. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_057.01 ;
   *  7. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_054.01 ;
   *  8. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_050.01 ;
   *  9. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_047.01 ;
   *  10. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_051.01 ;
   *  11. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_048.01 ;
   *  12. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_049.01 ;
   *  13. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_090.01 ;
   *  14. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_055.02 ;
   *  15. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_056.02 ;
   *  16. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_052.01 ;
   *  17. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_040.01 ;
   *  18. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_092.01 ;
   *  19. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_093.01 ;
   *  20. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_094.01 ;
   *  21. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_095.01 ;
   *  22. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_101.01 ;
   *  23. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_096.01 ;
   *  24. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_070.01 ;
   *  25. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_068.02 ;
   *  26. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_102.01 ;
   *  27. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_097.01 ;
   *  28. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_030.02 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_004_DRE */
void RE_EngLimTqT_004_DRE(void)
{
  Float32 localDataTypeConversion_j;
  Float32 localDataTypeConversion1_nq;
  Float32 localDataTypeConversion2_e;
  Float32 localDataTypeConversion9;
  Float32 localDataTypeConversion10;
  Float32 localDataTypeConversion11;
  Boolean localTmpSignalConversionAtIgS_n;
  Float32 localDivide_i;
  UInt32 localTmpSignalConversionAtAirSy;
  UInt16 localTmpSignalConversionAtAir_b;
  UInt32 localTmpSignalConversionAtAir_p;
  UInt32 localTmpSignalConversionAtEngM_;
  UInt32 localTmpSignalConversionAtEng_p;
  UInt16 localTmpSignalConversionAtEng_m;
  UInt32 localTmpSignalConversionAtEng_l;
  UInt32 localTmpSignalConversionAtEng_e;
  UInt8 localTmpSignalConversionAtAir_l;
  UInt16 localTmpSignalConversionAtAir_c;
  SInt16 localTmpSignalConversionAtEngLi;
  SInt16 localIgSys_tqIdcEstimAvgCyl_i_b;
  SInt16 localIgSys_tqIdcEstimAvgCylWi_f;
  SInt16 localEngLim_tqIdcMinAirLd_irv_m;
  SInt16 localEngLim_tqIdcMinAirLdAvgC_m;
  SInt16 localEngLim_tqIdcTrbMaxWoutOv_l;
  SInt16 localEngLim_tqIdcPresUsMax_ir_i;
  SInt16 localIgSys_tqIdcEstimAvgCylWo_e;
  Float32 locallocalDivide_e_idx;
  Float32 locallocalDivide_e_idx_0;
  Float32 locallocalDivide_e_idx_1;
  Float32 locallocalDivide_e_idx_2;
  Float32 locallocalDivide_e_idx_3;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_Calcul_couple_optimal'
   *
   * Block requirements for '<S1>/F03_Calcul_couple_optimal':
   *  1. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_107.03 ;
   *  2. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_041.01 ;
   *  5. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_053.01 ;
   *  6. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_057.01 ;
   *  7. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_054.01 ;
   *  8. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_050.01 ;
   *  9. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_047.01 ;
   *  10. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_051.01 ;
   *  11. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_048.01 ;
   *  12. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_049.01 ;
   *  13. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_090.01 ;
   *  14. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_055.02 ;
   *  15. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_056.02 ;
   *  16. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_052.01 ;
   *  17. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_040.01 ;
   *  18. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_092.01 ;
   *  19. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_093.01 ;
   *  20. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_094.01 ;
   *  21. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_095.01 ;
   *  22. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_101.01 ;
   *  23. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_096.01 ;
   *  24. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_070.01 ;
   *  25. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_068.02 ;
   *  26. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_102.01 ;
   *  27. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_097.01 ;
   *  28. SubSystem "F03_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_030.02 ;
   */

  /* SignalConversion: '<S22>/TmpSignal ConversionAtAirSys_rFullLdLamEfcOutport2' incorporates:
   *  Inport: '<Root>/AirSys_rFullLdLamEfc'
   */
  Rte_Read_R_AirSys_rFullLdLamEfc_AirSys_rFullLdLamEfc
    (&localTmpSignalConversionAtAirSy);

  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  localDataTypeConversion_j = ((Float32)localTmpSignalConversionAtAirSy) *
    3.051757813E-005F;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtAirSys_effAfrOutport2' incorporates:
   *  Inport: '<Root>/AirSys_effAfr'
   */
  Rte_Read_R_AirSys_effAfr_AirSys_effAfr(&localTmpSignalConversionAtAir_b);

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  localDataTypeConversion1_nq = ((Float32)localTmpSignalConversionAtAir_b) *
    3.051757813E-005F;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtAirSys_rClcLamEfcOutport2' incorporates:
   *  Inport: '<Root>/AirSys_rClcLamEfc'
   */
  Rte_Read_R_AirSys_rClcLamEfc_AirSys_rClcLamEfc
    (&localTmpSignalConversionAtAir_p);

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  localDataTypeConversion2_e = ((Float32)localTmpSignalConversionAtAir_p) *
    3.051757813E-005F;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngM_mAirEngCylMaxOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirEngCylMax'
   */
  Rte_Read_R_EngM_mAirEngCylMax_EngM_mAirEngCylMax
    (&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngM_mAirPresUsThrOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirPresUsThr'
   */
  Rte_Read_R_EngM_mAirPresUsThr_EngM_mAirPresUsThr
    (&localTmpSignalConversionAtEng_p);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngM_mAirCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirCor'
   */
  Rte_Read_R_EngM_mAirCor_EngM_mAirCor(&localTmpSignalConversionAtEng_m);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngM_mAirEngCylTrbMaxOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirEngCylTrbMax'
   */
  Rte_Read_R_EngM_mAirEngCylTrbMax_EngM_mAirEngCylTrbMax
    (&localTmpSignalConversionAtEng_l);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngM_mAirEngCylMinOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirEngCylMin'
   */
  Rte_Read_R_EngM_mAirEngCylMin_EngM_mAirEngCylMin
    (&localTmpSignalConversionAtEng_e);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtAirSys_effEGROutport2' incorporates:
   *  Inport: '<Root>/AirSys_effEGR'
   */
  Rte_Read_R_AirSys_effEGR_AirSys_effEGR(&localTmpSignalConversionAtAir_l);

  /* DataTypeConversion: '<S22>/Data Type Conversion9' */
  localDataTypeConversion9 = (((Float32)localTmpSignalConversionAtAir_l) *
    0.001953125F) + 0.75F;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtAirSys_effCycOutport2' incorporates:
   *  Inport: '<Root>/AirSys_effCyc'
   */
  Rte_Read_R_AirSys_effCyc_AirSys_effCyc(&localTmpSignalConversionAtAir_c);

  /* DataTypeConversion: '<S22>/Data Type Conversion10' */
  localDataTypeConversion10 = (((Float32)localTmpSignalConversionAtAir_c) *
    1.220703122E-010F) + 1.500000053E-006F;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcLimMinOutport2' incorporates:
   *  Inport: '<Root>/EngLim_tqIdcLimMin'
   */
  Rte_Read_R_EngLim_tqIdcLimMin_EngLim_tqIdcLimMin
    (&localTmpSignalConversionAtEngLi);

  /* DataTypeConversion: '<S22>/Data Type Conversion11' */
  localDataTypeConversion11 = ((Float32)localTmpSignalConversionAtEngLi) *
    0.0625F;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_bAcvStructAirOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAir'
   */
  Rte_Read_R_IgSys_bAcvStructAir_IgSys_bAcvStructAir
    (&localTmpSignalConversionAtIgS_n);

  /* Outputs for enable SubSystem: '<S22>/F02_Calcul_couple_optimal' incorporates:
   *  EnablePort: '<S140>/IgSys_bAcvStructAir'
   *
   * Block requirements for '<S22>/F02_Calcul_couple_optimal':
   *  1. SubSystem "F02_Calcul_couple_optimal" !Trace_To : VEMS_R_10_06438_032.02 ;
   */
  if (localTmpSignalConversionAtIgS_n) {
    /* Product: '<S167>/Divide' incorporates:
     *  DataTypeConversion: '<S22>/Data Type Conversion3'
     *  DataTypeConversion: '<S22>/Data Type Conversion4'
     *  DataTypeConversion: '<S22>/Data Type Conversion5'
     *  DataTypeConversion: '<S22>/Data Type Conversion6'
     *  DataTypeConversion: '<S22>/Data Type Conversion7'
     *  Product: '<S179>/Divide'
     */
    locallocalDivide_e_idx = ((((Float32)localTmpSignalConversionAtEng_l) *
      5.960464478E-008F) * localDataTypeConversion9) / localDataTypeConversion10;
    locallocalDivide_e_idx_0 = ((((Float32)localTmpSignalConversionAtEngM_) *
      5.960464478E-008F) * localDataTypeConversion9) / localDataTypeConversion10;
    locallocalDivide_e_idx_1 = ((((Float32)localTmpSignalConversionAtEng_p) *
      5.960464478E-008F) * localDataTypeConversion9) / localDataTypeConversion10;
    locallocalDivide_e_idx_2 = ((((Float32)localTmpSignalConversionAtEng_m) *
      1.192016583E-007F) * localDataTypeConversion9) / localDataTypeConversion10;
    locallocalDivide_e_idx_3 = ((((Float32)localTmpSignalConversionAtEng_e) *
      5.960464478E-008F) * localDataTypeConversion9) / localDataTypeConversion10;

    /* Switch: '<S162>/Switch1' incorporates:
     *  Constant: '<S162>/offset'
     *  Constant: '<S162>/offset2'
     *  Constant: '<S162>/offset3'
     *  Constant: '<S162>/offset4'
     *  Constant: '<S162>/one_on_slope'
     *  Product: '<S162>/Product4'
     *  RelationalOperator: '<S162>/Relational Operator'
     *  Sum: '<S162>/Add1'
     *  Sum: '<S162>/Add3'
     *  Sum: '<S162>/Add4'
     */
    localDivide_i = (16.0F * locallocalDivide_e_idx_3) + 0.5F;

    /* DataStoreWrite: '<S140>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S162>/OutDTConv'
     */
    if (localDivide_i < 32768.0F) {
      EngLim_tqIdcPresMinEstim_MP = (SInt16)localDivide_i;
    } else {
      EngLim_tqIdcPresMinEstim_MP = MAX_int16_T;
    }

    /* Switch: '<S161>/Switch1' incorporates:
     *  Constant: '<S161>/offset'
     *  Constant: '<S161>/offset2'
     *  Constant: '<S161>/offset3'
     *  Constant: '<S161>/offset4'
     *  Constant: '<S161>/one_on_slope'
     *  Product: '<S161>/Product4'
     *  RelationalOperator: '<S161>/Relational Operator'
     *  Sum: '<S161>/Add1'
     *  Sum: '<S161>/Add3'
     *  Sum: '<S161>/Add4'
     */
    localDivide_i = (16.0F * locallocalDivide_e_idx_2) + 0.5F;

    /* DataStoreWrite: '<S140>/Data Store Write1' incorporates:
     *  DataTypeConversion: '<S161>/OutDTConv'
     */
    if (localDivide_i < 32768.0F) {
      EngLim_tqIdcEstim_MP = (SInt16)localDivide_i;
    } else {
      EngLim_tqIdcEstim_MP = MAX_int16_T;
    }

    /* Switch: '<S152>/Switch1' incorporates:
     *  Constant: '<S152>/offset'
     *  Constant: '<S152>/offset2'
     *  Constant: '<S152>/offset3'
     *  Constant: '<S152>/offset4'
     *  Constant: '<S152>/one_on_slope'
     *  Product: '<S152>/Product4'
     *  RelationalOperator: '<S152>/Relational Operator'
     *  Sum: '<S152>/Add1'
     *  Sum: '<S152>/Add3'
     *  Sum: '<S152>/Add4'
     */
    localDivide_i = (16.0F * locallocalDivide_e_idx) + 0.5F;

    /* DataStoreWrite: '<S140>/Data Store Write3' incorporates:
     *  DataTypeConversion: '<S152>/OutDTConv'
     */
    if (localDivide_i < 32768.0F) {
      EngLim_tqIdcEstimMax_MP = (SInt16)localDivide_i;
    } else {
      EngLim_tqIdcEstimMax_MP = MAX_int16_T;
    }

    /* Switch: '<S160>/Switch1' incorporates:
     *  Constant: '<S160>/offset'
     *  Constant: '<S160>/offset2'
     *  Constant: '<S160>/offset3'
     *  Constant: '<S160>/offset4'
     *  Constant: '<S160>/one_on_slope'
     *  Product: '<S160>/Product4'
     *  RelationalOperator: '<S160>/Relational Operator'
     *  Sum: '<S160>/Add1'
     *  Sum: '<S160>/Add3'
     *  Sum: '<S160>/Add4'
     */
    localDivide_i = (16.0F * locallocalDivide_e_idx_0) + 0.5F;

    /* DataStoreWrite: '<S140>/Data Store Write4' incorporates:
     *  DataTypeConversion: '<S160>/OutDTConv'
     */
    if (localDivide_i < 32768.0F) {
      EngLim_tqIdcMaxWoutOvb_MP = (SInt16)localDivide_i;
    } else {
      EngLim_tqIdcMaxWoutOvb_MP = MAX_int16_T;
    }

    /* DataTypeConversion: '<S140>/Data Type Conversion17' incorporates:
     *  Constant: '<S140>/IgSys_tqIdcLimMin_C'
     */
    localDivide_i = ((Float32)IgSys_tqIdcLimMin_C) * 0.0625F;

    /* MinMax: '<S140>/MinMax1' */
    localDataTypeConversion9 = rt_MAXf(localDivide_i, localDataTypeConversion11);

    /* Product: '<S172>/Divide' */
    localDataTypeConversion10 = locallocalDivide_e_idx *
      localDataTypeConversion_j;

    /* Sum: '<S140>/Subtract' incorporates:
     *  Constant: '<S140>/Cste_1'
     *  Constant: '<S140>/Ext_noCylEng_SC'
     *  DataTypeConversion: '<S140>/Data Type Conversion4'
     *  DataTypeConversion: '<S22>/Data Type Conversion8'
     *  Product: '<S168>/Divide'
     *  SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_noCylCutOffDlyOutSatOutport2'
     */
    localDataTypeConversion11 = 1.0F - (((Float32)
      Rte_IrvRead_RE_EngLimTqT_004_DRE_IgSys_noCylCutOffDlyOutSat_irv()) /
      ((Float32)Ext_noCylEng_SC));

    /* Product: '<S176>/Divide' */
    localDivide_i = locallocalDivide_e_idx_2 * localDataTypeConversion11;

    /* Product: '<S153>/Product4' incorporates:
     *  Constant: '<S153>/offset'
     *  Constant: '<S153>/one_on_slope'
     *  Sum: '<S153>/Add1'
     */
    locallocalDivide_e_idx = 16.0F * localDivide_i;

    /* Switch: '<S153>/Switch1' incorporates:
     *  Constant: '<S153>/offset2'
     *  Constant: '<S153>/offset3'
     *  Constant: '<S153>/offset4'
     *  RelationalOperator: '<S153>/Relational Operator'
     *  Sum: '<S153>/Add3'
     *  Sum: '<S153>/Add4'
     */
    if (locallocalDivide_e_idx >= 0.0F) {
      locallocalDivide_e_idx += 0.5F;
    } else {
      locallocalDivide_e_idx -= 0.5F;
    }

    /* DataTypeConversion: '<S153>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      if (locallocalDivide_e_idx >= -32768.0F) {
        EngLimTqT_B.Merge3_p = (SInt16)locallocalDivide_e_idx;
      } else {
        EngLimTqT_B.Merge3_p = MIN_int16_T;
      }
    } else {
      EngLimTqT_B.Merge3_p = MAX_int16_T;
    }

    /* Product: '<S154>/Product4' incorporates:
     *  Constant: '<S154>/offset'
     *  Constant: '<S154>/one_on_slope'
     *  Product: '<S173>/Divide'
     *  Sum: '<S154>/Add1'
     */
    locallocalDivide_e_idx = (localDivide_i * localDataTypeConversion1_nq) *
      16.0F;

    /* Switch: '<S154>/Switch1' incorporates:
     *  Constant: '<S154>/offset2'
     *  Constant: '<S154>/offset3'
     *  Constant: '<S154>/offset4'
     *  RelationalOperator: '<S154>/Relational Operator'
     *  Sum: '<S154>/Add3'
     *  Sum: '<S154>/Add4'
     */
    if (locallocalDivide_e_idx >= 0.0F) {
      locallocalDivide_e_idx += 0.5F;
    } else {
      locallocalDivide_e_idx -= 0.5F;
    }

    /* DataTypeConversion: '<S154>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      if (locallocalDivide_e_idx >= -32768.0F) {
        EngLimTqT_B.Merge6_g = (SInt16)locallocalDivide_e_idx;
      } else {
        EngLimTqT_B.Merge6_g = MIN_int16_T;
      }
    } else {
      EngLimTqT_B.Merge6_g = MAX_int16_T;
    }

    /* Switch: '<S140>/Switch1' incorporates:
     *  Constant: '<S140>/IgSys_bLam2_C'
     */
    if (IgSys_bLam2_C) {
      locallocalDivide_e_idx = localDataTypeConversion1_nq;
    } else {
      locallocalDivide_e_idx = localDataTypeConversion2_e;
    }

    /* Product: '<S155>/Product4' incorporates:
     *  Constant: '<S155>/offset'
     *  Constant: '<S155>/one_on_slope'
     *  Product: '<S174>/Divide'
     *  Sum: '<S155>/Add1'
     */
    locallocalDivide_e_idx = (localDivide_i * locallocalDivide_e_idx) * 16.0F;

    /* Switch: '<S155>/Switch1' incorporates:
     *  Constant: '<S155>/offset2'
     *  Constant: '<S155>/offset3'
     *  Constant: '<S155>/offset4'
     *  RelationalOperator: '<S155>/Relational Operator'
     *  Sum: '<S155>/Add3'
     *  Sum: '<S155>/Add4'
     */
    if (locallocalDivide_e_idx >= 0.0F) {
      locallocalDivide_e_idx += 0.5F;
    } else {
      locallocalDivide_e_idx -= 0.5F;
    }

    /* DataTypeConversion: '<S155>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      if (locallocalDivide_e_idx >= -32768.0F) {
        EngLimTqT_B.Merge = (SInt16)locallocalDivide_e_idx;
      } else {
        EngLimTqT_B.Merge = MIN_int16_T;
      }
    } else {
      EngLimTqT_B.Merge = MAX_int16_T;
    }

    /* Switch: '<S156>/Switch1' incorporates:
     *  Constant: '<S156>/offset'
     *  Constant: '<S156>/offset2'
     *  Constant: '<S156>/offset3'
     *  Constant: '<S156>/offset4'
     *  Constant: '<S156>/one_on_slope'
     *  Product: '<S156>/Product4'
     *  Product: '<S177>/Divide'
     *  RelationalOperator: '<S156>/Relational Operator'
     *  Sum: '<S156>/Add1'
     *  Sum: '<S156>/Add3'
     *  Sum: '<S156>/Add4'
     */
    locallocalDivide_e_idx = ((localDataTypeConversion_j *
      locallocalDivide_e_idx_0) * 16.0F) + 0.5F;

    /* DataTypeConversion: '<S156>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      EngLimTqT_B.Merge10_o = (SInt16)locallocalDivide_e_idx;
    } else {
      EngLimTqT_B.Merge10_o = MAX_int16_T;
    }

    /* Switch: '<S157>/Switch1' incorporates:
     *  Constant: '<S157>/offset'
     *  Constant: '<S157>/offset2'
     *  Constant: '<S157>/offset3'
     *  Constant: '<S157>/offset4'
     *  Constant: '<S157>/one_on_slope'
     *  Product: '<S157>/Product4'
     *  RelationalOperator: '<S157>/Relational Operator'
     *  Sum: '<S157>/Add1'
     *  Sum: '<S157>/Add3'
     *  Sum: '<S157>/Add4'
     */
    locallocalDivide_e_idx = (16.0F * localDataTypeConversion10) + 0.5F;

    /* DataTypeConversion: '<S157>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      EngLimTqT_B.Merge8_h = (SInt16)locallocalDivide_e_idx;
    } else {
      EngLimTqT_B.Merge8_h = MAX_int16_T;
    }

    /* Product: '<S158>/Product4' incorporates:
     *  Constant: '<S158>/offset'
     *  Constant: '<S158>/one_on_slope'
     *  MinMax: '<S140>/MinMax'
     *  Sum: '<S158>/Add1'
     */
    locallocalDivide_e_idx = 16.0F * rt_MINf(localDataTypeConversion9,
      localDataTypeConversion10);

    /* Switch: '<S158>/Switch1' incorporates:
     *  Constant: '<S158>/offset2'
     *  Constant: '<S158>/offset3'
     *  Constant: '<S158>/offset4'
     *  RelationalOperator: '<S158>/Relational Operator'
     *  Sum: '<S158>/Add3'
     *  Sum: '<S158>/Add4'
     */
    if (locallocalDivide_e_idx >= 0.0F) {
      locallocalDivide_e_idx += 0.5F;
    } else {
      locallocalDivide_e_idx -= 0.5F;
    }

    /* DataTypeConversion: '<S158>/OutDTConv' */
    if (locallocalDivide_e_idx >= -32768.0F) {
      EngLimTqT_B.Merge2_i = (SInt16)locallocalDivide_e_idx;
    } else {
      EngLimTqT_B.Merge2_i = MIN_int16_T;
    }

    /* Product: '<S170>/Divide' */
    locallocalDivide_e_idx = locallocalDivide_e_idx_3 *
      localDataTypeConversion1_nq;

    /* Product: '<S159>/Product4' incorporates:
     *  Constant: '<S159>/offset'
     *  Constant: '<S159>/one_on_slope'
     *  Product: '<S178>/Divide'
     *  Sum: '<S159>/Add1'
     */
    localDataTypeConversion10 = (localDataTypeConversion11 *
      locallocalDivide_e_idx) * 16.0F;

    /* Switch: '<S159>/Switch1' incorporates:
     *  Constant: '<S159>/offset2'
     *  Constant: '<S159>/offset3'
     *  Constant: '<S159>/offset4'
     *  RelationalOperator: '<S159>/Relational Operator'
     *  Sum: '<S159>/Add3'
     *  Sum: '<S159>/Add4'
     */
    if (localDataTypeConversion10 >= 0.0F) {
      localDataTypeConversion10 += 0.5F;
    } else {
      localDataTypeConversion10 -= 0.5F;
    }

    /* DataTypeConversion: '<S159>/OutDTConv' */
    if (localDataTypeConversion10 < 32768.0F) {
      if (localDataTypeConversion10 >= -32768.0F) {
        EngLimTqT_B.Merge9 = (SInt16)localDataTypeConversion10;
      } else {
        EngLimTqT_B.Merge9 = MIN_int16_T;
      }
    } else {
      EngLimTqT_B.Merge9 = MAX_int16_T;
    }

    /* Product: '<S163>/Product4' incorporates:
     *  Constant: '<S163>/offset'
     *  Constant: '<S163>/one_on_slope'
     *  Sum: '<S163>/Add1'
     */
    locallocalDivide_e_idx *= 16.0F;

    /* Switch: '<S163>/Switch1' incorporates:
     *  Constant: '<S163>/offset2'
     *  Constant: '<S163>/offset3'
     *  Constant: '<S163>/offset4'
     *  RelationalOperator: '<S163>/Relational Operator'
     *  Sum: '<S163>/Add3'
     *  Sum: '<S163>/Add4'
     */
    locallocalDivide_e_idx += 0.5F;

    /* DataTypeConversion: '<S163>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      EngLimTqT_B.Merge5_n = (SInt16)locallocalDivide_e_idx;
    } else {
      EngLimTqT_B.Merge5_n = MAX_int16_T;
    }

    /* Switch: '<S164>/Switch1' incorporates:
     *  Constant: '<S164>/offset'
     *  Constant: '<S164>/offset2'
     *  Constant: '<S164>/offset3'
     *  Constant: '<S164>/offset4'
     *  Constant: '<S164>/one_on_slope'
     *  Product: '<S164>/Product4'
     *  Product: '<S169>/Divide'
     *  RelationalOperator: '<S164>/Relational Operator'
     *  Sum: '<S164>/Add1'
     *  Sum: '<S164>/Add3'
     *  Sum: '<S164>/Add4'
     */
    locallocalDivide_e_idx = ((locallocalDivide_e_idx_1 *
      localDataTypeConversion1_nq) * 16.0F) + 0.5F;

    /* DataTypeConversion: '<S164>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      EngLimTqT_B.Merge4_p = (SInt16)locallocalDivide_e_idx;
    } else {
      EngLimTqT_B.Merge4_p = MAX_int16_T;
    }

    /* Switch: '<S165>/Switch1' incorporates:
     *  Constant: '<S165>/offset'
     *  Constant: '<S165>/offset2'
     *  Constant: '<S165>/offset3'
     *  Constant: '<S165>/offset4'
     *  Constant: '<S165>/one_on_slope'
     *  Product: '<S165>/Product4'
     *  Product: '<S171>/Divide'
     *  RelationalOperator: '<S165>/Relational Operator'
     *  Sum: '<S165>/Add1'
     *  Sum: '<S165>/Add3'
     *  Sum: '<S165>/Add4'
     */
    locallocalDivide_e_idx = ((localDataTypeConversion1_nq *
      locallocalDivide_e_idx_2) * 16.0F) + 0.5F;

    /* DataTypeConversion: '<S165>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      EngLimTqT_B.Merge1_e = (SInt16)locallocalDivide_e_idx;
    } else {
      EngLimTqT_B.Merge1_e = MAX_int16_T;
    }

    /* Switch: '<S140>/Switch3' incorporates:
     *  Constant: '<S140>/IgSys_bLam1_C'
     */
    if (IgSys_bLam1_C) {
      locallocalDivide_e_idx = localDataTypeConversion1_nq;
    } else {
      locallocalDivide_e_idx = localDataTypeConversion2_e;
    }

    /* Product: '<S166>/Product4' incorporates:
     *  Constant: '<S166>/offset'
     *  Constant: '<S166>/one_on_slope'
     *  Product: '<S175>/Divide'
     *  Sum: '<S166>/Add1'
     */
    locallocalDivide_e_idx = (locallocalDivide_e_idx * localDivide_i) * 16.0F;

    /* Switch: '<S166>/Switch1' incorporates:
     *  Constant: '<S166>/offset2'
     *  Constant: '<S166>/offset3'
     *  Constant: '<S166>/offset4'
     *  RelationalOperator: '<S166>/Relational Operator'
     *  Sum: '<S166>/Add3'
     *  Sum: '<S166>/Add4'
     */
    if (locallocalDivide_e_idx >= 0.0F) {
      locallocalDivide_e_idx += 0.5F;
    } else {
      locallocalDivide_e_idx -= 0.5F;
    }

    /* DataTypeConversion: '<S166>/OutDTConv' */
    if (locallocalDivide_e_idx < 32768.0F) {
      if (locallocalDivide_e_idx >= -32768.0F) {
        EngLimTqT_B.Merge7_g = (SInt16)locallocalDivide_e_idx;
      } else {
        EngLimTqT_B.Merge7_g = MIN_int16_T;
      }
    } else {
      EngLimTqT_B.Merge7_g = MAX_int16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S22>/F02_Calcul_couple_optimal' */

  /* SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylWoutLmPrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtIgSys_tqId =
    Rte_IrvRead_RE_EngLimTqT_004_DRE_IgSys_tqIdcEstimAvgCylWoutLa_irv();

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcPresUsMax_PrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtEngLim_tqI =
    Rte_IrvRead_RE_EngLimTqT_004_DRE_EngLim_tqIdcPresUsMax_irv();

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcMinAirLdPrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtEngLim_t_o =
    Rte_IrvRead_RE_EngLimTqT_004_DRE_EngLim_tqIdcMinAirLd_irv();

  /* SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylPrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtIgSys_tq_k =
    Rte_IrvRead_RE_EngLimTqT_004_DRE_IgSys_tqIdcEstimAvgCyl_irv();

  /* SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylWiLamPrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtIgSys_tq_c =
    Rte_IrvRead_RE_EngLimTqT_004_DRE_IgSys_tqIdcEstimAvgCylWiLam_irv();

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcAdvOptmMaxWoutOsPrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtEngLim_t_j =
    Rte_IrvRead_RE_EngLimTqT_004_DRE_EngLim_tqIdcAdvOptmMaxWoutOf_irv();

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcMinAirLdAvgCylPrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtEngLim_t_l =
    Rte_IrvRead_RE_EngLimTqT_004_DRE_EngLim_tqIdcMinAirLdAvgCyl_irv();

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcTrbMaxWoutOvbPrevOutport2' */
  EngLimTqT_B.TmpSignalConversionAtEngLim_t_p =
    Rte_IrvRead_RE_EngLimTqT_004_DRE_EngLim_tqIdcTrbMaxWoutOvb_irv();

  /* Outputs for enable SubSystem: '<S22>/F01_Annule_couple_optimal' incorporates:
   *  EnablePort: '<S139>/enable'
   *  Logic: '<S22>/Logical Operator'
   *
   * Block requirements for '<S22>/F01_Annule_couple_optimal':
   *  1. SubSystem "F01_Annule_couple_optimal" !Trace_To : VEMS_R_10_06438_031.02 ;
   */
  if (!localTmpSignalConversionAtIgS_n) {
    /* Constant: '<S139>/Cste_0' */
    EngLimTqT_B.Merge = 0;

    /* Constant: '<S139>/Cste_1' */
    EngLimTqT_B.Merge1_e = 0;

    /* Constant: '<S139>/Cste_2' */
    EngLimTqT_B.Merge2_i = 0;

    /* SignalConversion: '<S139>/Signal Conversion1' */
    EngLimTqT_B.Merge4_p = EngLimTqT_B.TmpSignalConversionAtEngLim_tqI;

    /* SignalConversion: '<S139>/Signal Conversion2' */
    EngLimTqT_B.Merge5_n = EngLimTqT_B.TmpSignalConversionAtEngLim_t_o;

    /* SignalConversion: '<S139>/Signal Conversion3' */
    EngLimTqT_B.Merge6_g = EngLimTqT_B.TmpSignalConversionAtIgSys_tq_k;

    /* SignalConversion: '<S139>/Signal Conversion5' */
    EngLimTqT_B.Merge8_h = EngLimTqT_B.TmpSignalConversionAtEngLim_t_j;

    /* SignalConversion: '<S139>/Signal Conversion6' */
    EngLimTqT_B.Merge9 = EngLimTqT_B.TmpSignalConversionAtEngLim_t_l;

    /* SignalConversion: '<S139>/Signal Conversion8' */
    EngLimTqT_B.Merge10_o = EngLimTqT_B.TmpSignalConversionAtEngLim_t_p;

    /* SignalConversion: '<S139>/Signal Conversion7' */
    EngLimTqT_B.Merge3_p = EngLimTqT_B.TmpSignalConversionAtIgSys_tqId;

    /* SignalConversion: '<S139>/Signal Conversion4' */
    EngLimTqT_B.Merge7_g = EngLimTqT_B.TmpSignalConversionAtIgSys_tq_c;
  }

  /* end of Outputs for SubSystem: '<S22>/F01_Annule_couple_optimal' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S141>/autosar_testpoint1' */

  /* S-Function Block: <S141>/autosar_testpoint1 */
  EngLim_tqIdcMinAirLd_IRV_MP = EngLimTqT_B.Merge5_n;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S142>/autosar_testpoint1' */

  /* S-Function Block: <S142>/autosar_testpoint1 */
  IgSys_tqIdcEstimAvgCyl_IRV_MP = EngLimTqT_B.Merge6_g;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S143>/autosar_testpoint1' */

  /* S-Function Block: <S143>/autosar_testpoint1 */
  EngLim_tqIdcAdvOptmMaxWoutOfs = EngLimTqT_B.Merge8_h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S144>/autosar_testpoint1' */

  /* S-Function Block: <S144>/autosar_testpoint1 */
  EngLim_tqIdcMinAirLdAvgCyl = EngLimTqT_B.Merge9;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S145>/autosar_testpoint1' */

  /* S-Function Block: <S145>/autosar_testpoint1 */
  EngLim_tqIdcTrbMaxWoutOvb_IRV_MP = EngLimTqT_B.Merge10_o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S146>/autosar_testpoint1' */

  /* S-Function Block: <S146>/autosar_testpoint1 */
  IgSys_tqIdcEstimAvgCylWoutLam = EngLimTqT_B.Merge3_p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S147>/autosar_testpoint1' */

  /* S-Function Block: <S147>/autosar_testpoint1 */
  IgSys_tqIdcEstimAvgCylWiLam = EngLimTqT_B.Merge7_g;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S148>/autosar_testpoint1' */

  /* S-Function Block: <S148>/autosar_testpoint1 */
  EngLim_tqIdcPresUsMax_IRV_MP = EngLimTqT_B.Merge4_p;

  /* SignalConversion: '<S22>/Signal Conversion1' */
  localIgSys_tqIdcEstimAvgCyl_i_b = EngLimTqT_B.Merge6_g;

  /* SignalConversion: '<S22>/Signal Conversion2' */
  localIgSys_tqIdcEstimAvgCylWi_f = EngLimTqT_B.Merge7_g;

  /* SignalConversion: '<S22>/Signal Conversion3' */
  localEngLim_tqIdcMinAirLd_irv_m = EngLimTqT_B.Merge5_n;

  /* SignalConversion: '<S22>/Signal Conversion5' */
  localEngLim_tqIdcMinAirLdAvgC_m = EngLimTqT_B.Merge9;

  /* SignalConversion: '<S22>/Signal Conversion6' */
  localEngLim_tqIdcTrbMaxWoutOv_l = EngLimTqT_B.Merge10_o;

  /* SignalConversion: '<S22>/Signal Conversion7' */
  localEngLim_tqIdcPresUsMax_ir_i = EngLimTqT_B.Merge4_p;

  /* SignalConversion: '<S22>/Signal Conversion8' */
  localIgSys_tqIdcEstimAvgCylWo_e = EngLimTqT_B.Merge3_p;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcAdvOptmMaxWoutOf_irvInport2' incorporates:
   *  SignalConversion: '<S22>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_EngLimTqT_004_DRE_EngLim_tqIdcAdvOptmMaxWoutOf_irv
    (EngLimTqT_B.Merge8_h);

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S149>/Byp_Fonction_SC'
   *  Constant: '<S149>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEngLi = EngLim_tqIdcAdvOptmTrbMax_B;
  } else {
    localTmpSignalConversionAtEngLi = EngLimTqT_B.Merge2_i;
  }

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcAdvOptmTrbMaxInport2' */
  Rte_Write_P_EngLim_tqIdcAdvOptmTrbMax_EngLim_tqIdcAdvOptmTrbMax
    (localTmpSignalConversionAtEngLi);

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S151>/Byp_Fonction_SC'
   *  Constant: '<S151>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEngLi = EngLim_tqIdcAirTqWoutTotCutOf_B;
  } else {
    localTmpSignalConversionAtEngLi = EngLimTqT_B.Merge;
  }

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcAirTqWoutTotCutOfInport2' */
  Rte_Write_P_EngLim_tqIdcAirTqWoutTotCutOf_EngLim_tqIdcAirTqWoutTotCutOf
    (localTmpSignalConversionAtEngLi);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcMinAirLdAvgCyl_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_004_DRE_EngLim_tqIdcMinAirLdAvgCyl_irv
    (localEngLim_tqIdcMinAirLdAvgC_m);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcMinAirLd_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_004_DRE_EngLim_tqIdcMinAirLd_irv
    (localEngLim_tqIdcMinAirLd_irv_m);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcPresUsMax_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_004_DRE_EngLim_tqIdcPresUsMax_irv
    (localEngLim_tqIdcPresUsMax_ir_i);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtEngLim_tqIdcTrbMaxWoutOvb_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_004_DRE_EngLim_tqIdcTrbMaxWoutOvb_irv
    (localEngLim_tqIdcTrbMaxWoutOv_l);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylWiLam_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_004_DRE_IgSys_tqIdcEstimAvgCylWiLam_irv
    (localIgSys_tqIdcEstimAvgCylWi_f);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylWoutLa_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_004_DRE_IgSys_tqIdcEstimAvgCylWoutLa_irv
    (localIgSys_tqIdcEstimAvgCylWo_e);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCyl_irvInport2' */
  Rte_IrvWrite_RE_EngLimTqT_004_DRE_IgSys_tqIdcEstimAvgCyl_irv
    (localIgSys_tqIdcEstimAvgCyl_i_b);

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Byp_Fonction_SC'
   *  Constant: '<S150>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEngLi = IgSys_tqIdcEstim_B;
  } else {
    localTmpSignalConversionAtEngLi = EngLimTqT_B.Merge1_e;
  }

  /* SignalConversion: '<S22>/TmpSignal ConversionAtIgSys_tqIdcEstimInport2' */
  Rte_Write_P_IgSys_tqIdcEstim_IgSys_tqIdcEstim(localTmpSignalConversionAtEngLi);
}

/* Output and update for exported function: RE_EngLimTqT_006_DRE */
void RE_EngLimTqT_006_DRE(void)
{
  Float32 localDataTypeConversion1_j;
  Float32 localDataTypeConversion6_i;
  Boolean localTmpSignalConversionAtIg_cn;
  UInt16 localTmpSignalConversionAtI_hfk;
  SInt16 localTmpSignalConversionAtIg_pn;
  UInt16 localTmpSignalConversionAtIg_fd;
  SInt16 localTmpSignalConversionAtTqSys;
  SInt16 localOutDTConv_hn;
  SInt16 localOutDTConv_ah;
  SInt16 localOutDTConv_nn;
  SInt16 localOutDTConv_c2;
  SInt16 localOutDTConv_b;
  SInt16 localOutDTConv_m;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F04_Calcul_couple_max_min'
   *
   * Block requirements for '<S1>/F04_Calcul_couple_max_min':
   *  1. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_109.05 ;
   *  2. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_045.01 ;
   *  3. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_039.01 ;
   *  4. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_091.01 ;
   *  5. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_092.01 ;
   *  6. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_093.01 ;
   *  7. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_094.01 ;
   *  8. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_095.01 ;
   *  9. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_101.01 ;
   *  10. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_096.01 ;
   *  11. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_061.01 ;
   *  12. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_063.02 ;
   *  13. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_064.01 ;
   *  14. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_065.01 ;
   *  15. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_060.01 ;
   *  16. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_062.01 ;
   *  17. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_058.01 ;
   *  18. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_069.01 ;
   *  19. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_059.02 ;
   *  20. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_140.01 ;
   *  21. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_141.01 ;
   *  22. SubSystem "F04_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_142.01 ;
   */

  /* SignalConversion: '<S24>/TmpSignal ConversionAtIgSys_rMaxIgEfcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rMaxIgEfc_INPUT'
   */
  Rte_Read_R_IgSys_rMaxIgEfc_IgSys_rMaxIgEfc(&localTmpSignalConversionAtI_hfk);

  /* DataTypeConversion: '<S24>/Data Type Conversion1' */
  localDataTypeConversion1_j = ((Float32)localTmpSignalConversionAtI_hfk) *
    0.0009765625F;

  /* SignalConversion: '<S24>/TmpSignal ConversionAtIgSys_tqIdcEstimPrevOutport2' incorporates:
   *  Inport: '<Root>/IgSys_tqIdcEstim_INPUT'
   */
  Rte_Read_R_IgSys_tqIdcEstim_IgSys_tqIdcEstim(&localTmpSignalConversionAtIg_pn);

  /* DataTypeConversion: '<S24>/Data Type Conversion5' */
  IgSys_tqIdcEstimPrev = ((Float32)localTmpSignalConversionAtIg_pn) * 0.0625F;

  /* SignalConversion: '<S24>/TmpSignal ConversionAtIgSys_rMinIgEfcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rMinIgEfc_INPUT'
   */
  Rte_Read_R_IgSys_rMinIgEfc_IgSys_rMinIgEfc(&localTmpSignalConversionAtIg_fd);

  /* DataTypeConversion: '<S24>/Data Type Conversion6' */
  localDataTypeConversion6_i = ((Float32)localTmpSignalConversionAtIg_fd) *
    0.0009765625F;

  /* SignalConversion: '<S24>/TmpSignal ConversionAtTqSys_tqIdcAirLimCordWoutResOutport2' incorporates:
   *  Inport: '<Root>/TqSys_tqIdcAirLimCordWoutRes'
   */
  Rte_Read_R_TqSys_tqIdcAirLimCordWoutRes_TqSys_tqIdcAirLimCordWoutRes
    (&localTmpSignalConversionAtTqSys);

  /* SignalConversion: '<S24>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIg_cn);

  /* Outputs for enable SubSystem: '<S24>/F01_Annule_couple_max_min' incorporates:
   *  EnablePort: '<S218>/enable'
   *  Logic: '<S24>/Logical Operator'
   *
   * Block requirements for '<S24>/F01_Annule_couple_max_min':
   *  1. SubSystem "F01_Annule_couple_max_min" !Trace_To : VEMS_R_10_06438_022.02 ;
   */
  if (!localTmpSignalConversionAtIg_cn) {
    /* Constant: '<S218>/Cste_9' */
    EngLimTqT_B.Merge10 = 0.0F;

    /* Constant: '<S218>/Cste_7' */
    EngLimTqT_B.Merge7 = 0.0F;

    /* Constant: '<S218>/Cste_6' */
    EngLimTqT_B.Merge6 = 0.0F;

    /* Constant: '<S218>/Cste_5' */
    EngLimTqT_B.Merge5 = 0.0F;

    /* Constant: '<S218>/Cste_4' */
    EngLimTqT_B.Merge4_c = 0.0F;

    /* Constant: '<S218>/Cste_3' */
    EngLimTqT_B.Merge3 = 0.0F;

    /* Constant: '<S218>/Cste_2' */
    EngLimTqT_B.Merge2 = 0.0F;

    /* Constant: '<S218>/Cste_1' */
    EngLimTqT_B.Merge1_i = 0.0F;

    /* Constant: '<S218>/Cste_8' */
    EngLimTqT_B.Merge8 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S24>/F01_Annule_couple_max_min' */

  /* SignalConversion: '<S24>/TmpSignal ConversionAtIgSys_bTqIdcCutOffOutport2' */
  EngLimTqT_B.TmpSignalConversionAtIgSys_bTqI =
    Rte_IrvRead_RE_EngLimTqT_006_DRE_IgSys_bTqIdcCutOff_irv();

  /* SignalConversion: '<S24>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&EngLimTqT_B.TmpSignalConversionAtExt_nEngOu);

  /* Outputs for enable SubSystem: '<S24>/F02_Calcul_couple_max_min' incorporates:
   *  EnablePort: '<S219>/IgSys_bAcvStructAdv'
   *
   * Block requirements for '<S24>/F02_Calcul_couple_max_min':
   *  1. SubSystem "F02_Calcul_couple_max_min" !Trace_To : VEMS_R_10_06438_023.01 ;
   */
  if (localTmpSignalConversionAtIg_cn) {
    /* Sum: '<S219>/Add' incorporates:
     *  Constant: '<S219>/Cste_2'
     *  Constant: '<S219>/IgSys_tqIdcThdMin_C'
     *  DataTypeConversion: '<S219>/Data Type Conversion1'
     *  DataTypeConversion: '<S24>/Data Type Conversion8'
     *  MinMax: '<S219>/MinMax'
     *  Product: '<S239>/Divide'
     */
    EngLimTqT_B.Merge6 = ((((Float32)localTmpSignalConversionAtTqSys) * 0.0625F)
                          / rt_MAXf(1.000000047E-003F,
      localDataTypeConversion6_i)) - (((Float32)IgSys_tqIdcThdMin_C) * 0.0625F);

    /* Switch: '<S219>/Switch1' incorporates:
     *  Constant: '<S219>/IgSys_btqIdcPresUsThrMax_C'
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  Lookup_n-D: '<S238>/Lookup Table (n-D)'
     *  Product: '<S242>/Divide'
     *  SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcPresUsMaxOutport2'
     */
    if (IgSys_btqIdcPresUsThrMax_C) {
      EngLimTqT_B.Merge3 = look1_iu16lfts16n4If_binlcns
        (EngLimTqT_B.TmpSignalConversionAtExt_nEngOu, (&(Ext_nEng_A[0])),
         (&(EngLim_tqIdcPresUsThrMax_T[0])), 15U);
    } else {
      EngLimTqT_B.Merge3 = (((Float32)
        Rte_IrvRead_RE_EngLimTqT_006_DRE_EngLim_tqIdcPresUsMax_irv()) * 0.0625F)
        * localDataTypeConversion1_j;
    }

    /* Switch: '<S219>/Switch4' incorporates:
     *  Constant: '<S219>/Cste_0'
     *  DataTypeConversion: '<S24>/Data Type Conversion7'
     *  Product: '<S241>/Divide'
     *  SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcMinAirLdAvgCylOutport2'
     */
    if (EngLimTqT_B.TmpSignalConversionAtIgSys_bTqI) {
      EngLimTqT_B.Merge10 = 0.0F;
    } else {
      EngLimTqT_B.Merge10 = (((Float32)
        Rte_IrvRead_RE_EngLimTqT_006_DRE_EngLim_tqIdcMinAirLdAvgCyl_irv()) *
        0.0625F) * localDataTypeConversion6_i;
    }

    /* Switch: '<S219>/Switch5' incorporates:
     *  Constant: '<S219>/Cste_1'
     *  DataTypeConversion: '<S24>/Data Type Conversion10'
     *  Product: '<S246>/Divide'
     *  SignalConversion: '<S24>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylOutport2'
     */
    if (EngLimTqT_B.TmpSignalConversionAtIgSys_bTqI) {
      EngLimTqT_B.Merge4_c = 0.0F;
    } else {
      EngLimTqT_B.Merge4_c = (((Float32)
        Rte_IrvRead_RE_EngLimTqT_006_DRE_IgSys_tqIdcEstimAvgCyl_irv()) * 0.0625F)
        * localDataTypeConversion6_i;
    }

    /* Product: '<S240>/Divide' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion4'
     *  SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcAdvOptmMaxWoutOfsOutport2'
     */
    EngLimTqT_B.Merge1_i = (((Float32)
      Rte_IrvRead_RE_EngLimTqT_006_DRE_EngLim_tqIdcAdvOptmMaxWoutOf_irv()) *
      0.0625F) * localDataTypeConversion1_j;

    /* Product: '<S243>/Divide' */
    EngLimTqT_B.Merge2 = localDataTypeConversion1_j * IgSys_tqIdcEstimPrev;

    /* Product: '<S244>/Divide' */
    EngLimTqT_B.Merge5 = IgSys_tqIdcEstimPrev * localDataTypeConversion6_i;

    /* Product: '<S245>/Divide' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion11'
     *  SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcTrbMaxWoutOvbOutport2'
     */
    EngLimTqT_B.Merge8 = (((Float32)
      Rte_IrvRead_RE_EngLimTqT_006_DRE_EngLim_tqIdcTrbMaxWoutOvb_irv()) *
                          0.0625F) * localDataTypeConversion1_j;

    /* Product: '<S247>/Divide' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion9'
     *  SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcMinAirLdOutport2'
     */
    EngLimTqT_B.Merge7 = (((Float32)
      Rte_IrvRead_RE_EngLimTqT_006_DRE_EngLim_tqIdcMinAirLd_irv()) * 0.0625F) *
      localDataTypeConversion6_i;
  }

  /* end of Outputs for SubSystem: '<S24>/F02_Calcul_couple_max_min' */

  /* Product: '<S220>/Product4' incorporates:
   *  Constant: '<S220>/offset'
   *  Constant: '<S220>/one_on_slope'
   *  Sum: '<S220>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge1_i;

  /* Switch: '<S220>/Switch1' incorporates:
   *  Constant: '<S220>/offset2'
   *  Constant: '<S220>/offset3'
   *  Constant: '<S220>/offset4'
   *  RelationalOperator: '<S220>/Relational Operator'
   *  Sum: '<S220>/Add3'
   *  Sum: '<S220>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* DataTypeConversion: '<S220>/OutDTConv' */
  if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localTmpSignalConversionAtIg_pn = (SInt16)localDataTypeConversion1_j;
    } else {
      localTmpSignalConversionAtIg_pn = MIN_int16_T;
    }
  } else {
    localTmpSignalConversionAtIg_pn = MAX_int16_T;
  }

  /* Product: '<S221>/Product4' incorporates:
   *  Constant: '<S221>/offset'
   *  Constant: '<S221>/one_on_slope'
   *  Sum: '<S221>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge2;

  /* Switch: '<S221>/Switch1' incorporates:
   *  Constant: '<S221>/offset2'
   *  Constant: '<S221>/offset3'
   *  Constant: '<S221>/offset4'
   *  RelationalOperator: '<S221>/Relational Operator'
   *  Sum: '<S221>/Add3'
   *  Sum: '<S221>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* DataTypeConversion: '<S221>/OutDTConv' */
  if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localTmpSignalConversionAtTqSys = (SInt16)localDataTypeConversion1_j;
    } else {
      localTmpSignalConversionAtTqSys = MIN_int16_T;
    }
  } else {
    localTmpSignalConversionAtTqSys = MAX_int16_T;
  }

  /* Product: '<S222>/Product4' incorporates:
   *  Constant: '<S222>/offset'
   *  Constant: '<S222>/one_on_slope'
   *  Sum: '<S222>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge3;

  /* Switch: '<S222>/Switch1' incorporates:
   *  Constant: '<S222>/offset2'
   *  Constant: '<S222>/offset3'
   *  Constant: '<S222>/offset4'
   *  RelationalOperator: '<S222>/Relational Operator'
   *  Sum: '<S222>/Add3'
   *  Sum: '<S222>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* DataTypeConversion: '<S222>/OutDTConv' */
  if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localOutDTConv_hn = (SInt16)localDataTypeConversion1_j;
    } else {
      localOutDTConv_hn = MIN_int16_T;
    }
  } else {
    localOutDTConv_hn = MAX_int16_T;
  }

  /* Product: '<S223>/Product4' incorporates:
   *  Constant: '<S223>/offset'
   *  Constant: '<S223>/one_on_slope'
   *  Sum: '<S223>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge8;

  /* Switch: '<S223>/Switch1' incorporates:
   *  Constant: '<S223>/offset2'
   *  Constant: '<S223>/offset3'
   *  Constant: '<S223>/offset4'
   *  RelationalOperator: '<S223>/Relational Operator'
   *  Sum: '<S223>/Add3'
   *  Sum: '<S223>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* DataTypeConversion: '<S223>/OutDTConv' */
  if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localOutDTConv_ah = (SInt16)localDataTypeConversion1_j;
    } else {
      localOutDTConv_ah = MIN_int16_T;
    }
  } else {
    localOutDTConv_ah = MAX_int16_T;
  }

  /* Product: '<S224>/Product4' incorporates:
   *  Constant: '<S224>/offset'
   *  Constant: '<S224>/one_on_slope'
   *  Sum: '<S224>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge4_c;

  /* Switch: '<S224>/Switch1' incorporates:
   *  Constant: '<S224>/offset2'
   *  Constant: '<S224>/offset3'
   *  Constant: '<S224>/offset4'
   *  RelationalOperator: '<S224>/Relational Operator'
   *  Sum: '<S224>/Add3'
   *  Sum: '<S224>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* DataTypeConversion: '<S224>/OutDTConv' */
  if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localOutDTConv_nn = (SInt16)localDataTypeConversion1_j;
    } else {
      localOutDTConv_nn = MIN_int16_T;
    }
  } else {
    localOutDTConv_nn = MAX_int16_T;
  }

  /* Product: '<S225>/Product4' incorporates:
   *  Constant: '<S225>/offset'
   *  Constant: '<S225>/one_on_slope'
   *  Sum: '<S225>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge5;

  /* Switch: '<S225>/Switch1' incorporates:
   *  Constant: '<S225>/offset2'
   *  Constant: '<S225>/offset3'
   *  Constant: '<S225>/offset4'
   *  RelationalOperator: '<S225>/Relational Operator'
   *  Sum: '<S225>/Add3'
   *  Sum: '<S225>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* DataTypeConversion: '<S225>/OutDTConv' */
  if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localOutDTConv_c2 = (SInt16)localDataTypeConversion1_j;
    } else {
      localOutDTConv_c2 = MIN_int16_T;
    }
  } else {
    localOutDTConv_c2 = MAX_int16_T;
  }

  /* Product: '<S226>/Product4' incorporates:
   *  Constant: '<S226>/offset'
   *  Constant: '<S226>/one_on_slope'
   *  Sum: '<S226>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge6;

  /* Switch: '<S226>/Switch1' incorporates:
   *  Constant: '<S226>/offset2'
   *  Constant: '<S226>/offset3'
   *  Constant: '<S226>/offset4'
   *  RelationalOperator: '<S226>/Relational Operator'
   *  Sum: '<S226>/Add3'
   *  Sum: '<S226>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* DataTypeConversion: '<S226>/OutDTConv' */
  if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localOutDTConv_b = (SInt16)localDataTypeConversion1_j;
    } else {
      localOutDTConv_b = MIN_int16_T;
    }
  } else {
    localOutDTConv_b = MAX_int16_T;
  }

  /* Product: '<S227>/Product4' incorporates:
   *  Constant: '<S227>/offset'
   *  Constant: '<S227>/one_on_slope'
   *  Sum: '<S227>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge7;

  /* Switch: '<S227>/Switch1' incorporates:
   *  Constant: '<S227>/offset2'
   *  Constant: '<S227>/offset3'
   *  Constant: '<S227>/offset4'
   *  RelationalOperator: '<S227>/Relational Operator'
   *  Sum: '<S227>/Add3'
   *  Sum: '<S227>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* DataTypeConversion: '<S227>/OutDTConv' */
  if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localOutDTConv_m = (SInt16)localDataTypeConversion1_j;
    } else {
      localOutDTConv_m = MIN_int16_T;
    }
  } else {
    localOutDTConv_m = MAX_int16_T;
  }

  /* Product: '<S228>/Product4' incorporates:
   *  Constant: '<S228>/offset'
   *  Constant: '<S228>/one_on_slope'
   *  Sum: '<S228>/Add1'
   */
  localDataTypeConversion1_j = 16.0F * EngLimTqT_B.Merge10;

  /* Switch: '<S228>/Switch1' incorporates:
   *  Constant: '<S228>/offset2'
   *  Constant: '<S228>/offset3'
   *  Constant: '<S228>/offset4'
   *  RelationalOperator: '<S228>/Relational Operator'
   *  Sum: '<S228>/Add3'
   *  Sum: '<S228>/Add4'
   */
  if (localDataTypeConversion1_j >= 0.0F) {
    localDataTypeConversion1_j += 0.5F;
  } else {
    localDataTypeConversion1_j -= 0.5F;
  }

  /* Switch: '<S235>/Switch' incorporates:
   *  Constant: '<S235>/Byp_Fonction_SC'
   *  Constant: '<S235>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localOutDTConv_b = EngLim_tqIdcAirResMax_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcAirResMaxInport2' */
  Rte_Write_P_EngLim_tqIdcAirResMax_EngLim_tqIdcAirResMax(localOutDTConv_b);

  /* Switch: '<S229>/Switch' incorporates:
   *  Constant: '<S229>/Byp_Fonction_SC'
   *  Constant: '<S229>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtTqSys = EngLim_tqIdcEngCurMax_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcEngCurMaxInport2' */
  Rte_Write_P_EngLim_tqIdcEngCurMax_EngLim_tqIdcEngCurMax
    (localTmpSignalConversionAtTqSys);

  /* Switch: '<S234>/Switch' incorporates:
   *  Constant: '<S234>/Byp_Fonction_SC'
   *  Constant: '<S234>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localOutDTConv_c2 = EngLim_tqIdcEngCurMin_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcEngCurMinInport2' */
  Rte_Write_P_EngLim_tqIdcEngCurMin_EngLim_tqIdcEngCurMin(localOutDTConv_c2);

  /* Switch: '<S233>/Switch' incorporates:
   *  Constant: '<S233>/Byp_Fonction_SC'
   *  Constant: '<S233>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localOutDTConv_nn = EngLim_tqIdcEngCurMinSelc_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcEngCurMinSelcInport2' */
  Rte_Write_P_EngLim_tqIdcEngCurMinSelc_EngLim_tqIdcEngCurMinSelc
    (localOutDTConv_nn);

  /* Switch: '<S231>/Switch' incorporates:
   *  Constant: '<S231>/Byp_Fonction_SC'
   *  Constant: '<S231>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIg_pn = EngLim_tqIdcLdMaxTrbMax_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcLdMaxTrbMaxInport2' */
  Rte_Write_P_EngLim_tqIdcLdMaxTrbMax_EngLim_tqIdcLdMaxTrbMax
    (localTmpSignalConversionAtIg_pn);

  /* Switch: '<S230>/Switch' incorporates:
   *  Constant: '<S230>/Byp_Fonction_SC'
   *  Constant: '<S230>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localOutDTConv_ah = EngLim_tqIdcLdMaxTrbMaxNoOvb_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcLdMaxTrbMaxNoOvbInport2' */
  Rte_Write_P_EngLim_tqIdcLdMaxTrbMaxNoOvb_EngLim_tqIdcLdMaxTrbMaxNoOvb
    (localOutDTConv_ah);

  /* Switch: '<S236>/Switch' incorporates:
   *  Constant: '<S236>/Byp_Fonction_SC'
   *  Constant: '<S236>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localOutDTConv_m = EngLim_tqIdcLdMinAdvMin_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcLdMinAdvMinInport2' */
  Rte_Write_P_EngLim_tqIdcLdMinAdvMin_EngLim_tqIdcLdMinAdvMin(localOutDTConv_m);

  /* Switch: '<S237>/Switch' incorporates:
   *  Constant: '<S237>/Byp_Fonction_SC'
   *  Constant: '<S237>/Int_BypC'
   *  DataTypeConversion: '<S228>/OutDTConv'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIg_pn = EngLim_tqIdcLdMinAdvMinSelc_B;
  } else if (localDataTypeConversion1_j < 32768.0F) {
    if (localDataTypeConversion1_j >= -32768.0F) {
      localTmpSignalConversionAtIg_pn = (SInt16)localDataTypeConversion1_j;
    } else {
      localTmpSignalConversionAtIg_pn = MIN_int16_T;
    }
  } else {
    localTmpSignalConversionAtIg_pn = MAX_int16_T;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcLdMinAdvMinSelcInport2' */
  Rte_Write_P_EngLim_tqIdcLdMinAdvMinSelc_EngLim_tqIdcLdMinAdvMinSelc
    (localTmpSignalConversionAtIg_pn);

  /* Switch: '<S232>/Switch' incorporates:
   *  Constant: '<S232>/Byp_Fonction_SC'
   *  Constant: '<S232>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localOutDTConv_hn = EngLim_tqIdcPresUsThrMax_B;
  }

  /* SignalConversion: '<S24>/TmpSignal ConversionAtEngLim_tqIdcPresUsThrMaxInport2' */
  Rte_Write_P_EngLim_tqIdcPresUsThrMax_EngLim_tqIdcPresUsThrMax
    (localOutDTConv_hn);
}

/* Output and update for exported function: RE_EngLimTqT_008_DRE */
void RE_EngLimTqT_008_DRE(void)
{
  Float32 localDataTypeConversion1_dj;
  Float32 localDataTypeConversion2_b;
  Float32 localDataTypeConversion3_ic;
  Float32 localDataTypeConversion4_g;
  Float32 localDataTypeConversion5_ow;
  Float32 localDataTypeConversion6_n;
  Boolean localTmpSignalConversionAtIg_a2;
  Boolean localTmpSignalConversionAtIg_a3;
  Float32 localMultiportSwitch_f;
  UInt16 localTmpSignalConversionAtIg_kv;
  UInt16 localTmpSignalConversionAtIg_nw;
  SInt16 localOutDTConv_mj;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F05_Calcul_couple_reel'
   *
   * Block requirements for '<S1>/F05_Calcul_couple_reel':
   *  1. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_111.04 ;
   *  2. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_020.02 ;
   *  3. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_021.02 ;
   *  4. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_102.01 ;
   *  5. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_097.01 ;
   *  6. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_098.01 ;
   *  7. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_045.01 ;
   *  8. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_091.01 ;
   *  9. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_066.01 ;
   *  10. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_067.01 ;
   *  11. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_143.01 ;
   *  12. SubSystem "F05_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_147.01 ;
   */

  /* SignalConversion: '<S25>/TmpSignal ConversionAtIgSys_rStatIgSpEfc_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rStatIgSpEfc_INPUT'
   */
  Rte_Read_R_IgSys_rStatIgSpEfc_IgSys_rStatIgSpEfc
    (&localTmpSignalConversionAtIg_kv);

  /* DataTypeConversion: '<S25>/Data Type Conversion1' */
  localDataTypeConversion1_dj = ((Float32)localTmpSignalConversionAtIg_kv) *
    0.0009765625F;

  /* DataTypeConversion: '<S25>/Data Type Conversion2' incorporates:
   *  SignalConversion: '<S25>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylWoutLamOutport2'
   */
  localDataTypeConversion2_b = ((Float32)
    Rte_IrvRead_RE_EngLimTqT_008_DRE_IgSys_tqIdcEstimAvgCylWoutLa_irv()) *
    0.0625F;

  /* DataTypeConversion: '<S25>/Data Type Conversion3' incorporates:
   *  SignalConversion: '<S25>/TmpSignal ConversionAtIgSys_tqIdcEstimAvgCylWiLamOutport2'
   */
  localDataTypeConversion3_ic = ((Float32)
    Rte_IrvRead_RE_EngLimTqT_008_DRE_IgSys_tqIdcEstimAvgCylWiLam_irv()) *
    0.0625F;

  /* DataTypeConversion: '<S25>/Data Type Conversion4' incorporates:
   *  SignalConversion: '<S25>/TmpSignal ConversionAtIgSys_rStatIgSpEfcWoutMv_irvOutport2'
   */
  localDataTypeConversion4_g = ((Float32)
    Rte_IrvRead_RE_EngLimTqT_008_DRE_IgSys_rStatIgSpEfcWoutMv_irv()) *
    0.0009765625F;

  /* DataTypeConversion: '<S25>/Data Type Conversion5' incorporates:
   *  SignalConversion: '<S25>/TmpSignal ConversionAtIgSys_rDynIgSpEfcWoutMv_irvOutport2'
   */
  localDataTypeConversion5_ow = ((Float32)
    Rte_IrvRead_RE_EngLimTqT_008_DRE_IgSys_rDynIgSpEfcWoutMv_irv()) *
    0.0009765625F;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtIgSys_rDynIgSpEfcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rDynIgSpEfc_INPUT'
   */
  Rte_Read_R_IgSys_rDynIgSpEfc_IgSys_rDynIgSpEfc
    (&localTmpSignalConversionAtIg_nw);

  /* DataTypeConversion: '<S25>/Data Type Conversion6' */
  localDataTypeConversion6_n = ((Float32)localTmpSignalConversionAtIg_nw) *
    0.0009765625F;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIg_a2);

  /* Outputs for enable SubSystem: '<S25>/F01_Annule_couple_reel' incorporates:
   *  EnablePort: '<S248>/enable'
   *  Logic: '<S25>/Logical Operator'
   *
   * Block requirements for '<S25>/F01_Annule_couple_reel':
   *  1. SubSystem "F01_Annule_couple_reel" !Trace_To : VEMS_R_10_06438_022.02 ;
   */
  if (!localTmpSignalConversionAtIg_a2) {
    /* Constant: '<S248>/Cste_0' */
    EngLimTqT_B.Merge1 = 0.0F;

    /* Constant: '<S248>/Cste_1' */
    EngLimTqT_B.Merge4 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S25>/F01_Annule_couple_reel' */

  /* SignalConversion: '<S25>/TmpSignal ConversionAtIgSys_bTqIdcCutOffOutport2' */
  localTmpSignalConversionAtIg_a3 =
    Rte_IrvRead_RE_EngLimTqT_008_DRE_IgSys_bTqIdcCutOff_irv();

  /* Outputs for enable SubSystem: '<S25>/F02_Calcul_couple_reel' incorporates:
   *  EnablePort: '<S249>/IgSys_bAcvStructAdv'
   *
   * Block requirements for '<S25>/F02_Calcul_couple_reel':
   *  1. SubSystem "F02_Calcul_couple_reel" !Trace_To : VEMS_R_10_06438_023.01 ;
   */
  if (localTmpSignalConversionAtIg_a2) {
    /* MultiPortSwitch: '<S249>/Multiport Switch' incorporates:
     *  Constant: '<S249>/IgSys_stIgAgEfc_C'
     */
    switch (IgSys_stIgAgEfc_C) {
     case 0:
      localMultiportSwitch_f = localDataTypeConversion6_n;
      break;

     case 1:
      localMultiportSwitch_f = localDataTypeConversion1_dj;
      break;

     case 2:
      localMultiportSwitch_f = localDataTypeConversion4_g;
      break;

     default:
      localMultiportSwitch_f = localDataTypeConversion5_ow;
      break;
    }

    /* MultiPortSwitch: '<S249>/Multiport Switch1' incorporates:
     *  Constant: '<S249>/IgSys_stIgAgEfcGBx_C'
     */
    switch (IgSys_stIgAgEfcGBx_C) {
     case 0:
      localDataTypeConversion5_ow = localDataTypeConversion6_n;
      break;

     case 1:
      localDataTypeConversion5_ow = localDataTypeConversion1_dj;
      break;

     case 2:
      localDataTypeConversion5_ow = localDataTypeConversion4_g;
      break;
    }

    /* Switch: '<S249>/Switch1' incorporates:
     *  Constant: '<S249>/IgSys_bLamEfc_C'
     */
    if (IgSys_bLamEfc_C) {
      localDataTypeConversion1_dj = localDataTypeConversion3_ic;
    } else {
      localDataTypeConversion1_dj = localDataTypeConversion2_b;
    }

    /* Switch: '<S249>/Switch4' incorporates:
     *  Constant: '<S249>/Cste_1'
     *  Product: '<S256>/Divide'
     */
    if (localTmpSignalConversionAtIg_a3) {
      localDataTypeConversion1_dj = 0.0F;
    } else {
      localDataTypeConversion1_dj *= localMultiportSwitch_f;
    }

    /* SignalConversion: '<S249>/Signal Conversion' */
    EngLimTqT_B.Merge4 = localDataTypeConversion1_dj;

    /* DataTypeConversion: '<S254>/OutDTConv' incorporates:
     *  Constant: '<S249>/IgSys_facTqtoPresIdc_C'
     *  Constant: '<S254>/offset'
     *  Constant: '<S254>/offset1'
     *  Constant: '<S254>/one_on_slope'
     *  DataTypeConversion: '<S249>/Data Type Conversion4'
     *  Product: '<S254>/Product4'
     *  Product: '<S257>/Divide'
     *  Sum: '<S254>/Add1'
     *  Sum: '<S254>/Add2'
     */
    localDataTypeConversion1_dj = (((((((Float32)IgSys_facTqtoPresIdc_C) *
      0.0625F) - 2000.0F) * localDataTypeConversion1_dj) - -2000.0F) * 16.0F) +
      0.5F;
    if (localDataTypeConversion1_dj < 65536.0F) {
      if (localDataTypeConversion1_dj >= 0.0F) {
        EngLim_presIdcEngCur = (UInt16)localDataTypeConversion1_dj;
      } else {
        EngLim_presIdcEngCur = 0U;
      }
    } else {
      EngLim_presIdcEngCur = MAX_uint16_T;
    }

    /* Switch: '<S249>/Switch2' incorporates:
     *  Constant: '<S249>/IgSys_bLamEfcGBx_C'
     */
    if (IgSys_bLamEfcGBx_C) {
      localDataTypeConversion1_dj = localDataTypeConversion3_ic;
    } else {
      localDataTypeConversion1_dj = localDataTypeConversion2_b;
    }

    /* Switch: '<S249>/Switch3' incorporates:
     *  Constant: '<S249>/Cste_2'
     *  Product: '<S255>/Divide'
     */
    if (localTmpSignalConversionAtIg_a3) {
      EngLimTqT_B.Merge1 = 0.0F;
    } else {
      EngLimTqT_B.Merge1 = localDataTypeConversion5_ow *
        localDataTypeConversion1_dj;
    }
  }

  /* end of Outputs for SubSystem: '<S25>/F02_Calcul_couple_reel' */

  /* Product: '<S250>/Product4' incorporates:
   *  Constant: '<S250>/offset'
   *  Constant: '<S250>/one_on_slope'
   *  Sum: '<S250>/Add1'
   */
  localDataTypeConversion1_dj = 16.0F * EngLimTqT_B.Merge1;

  /* Switch: '<S250>/Switch1' incorporates:
   *  Constant: '<S250>/offset2'
   *  Constant: '<S250>/offset3'
   *  Constant: '<S250>/offset4'
   *  RelationalOperator: '<S250>/Relational Operator'
   *  Sum: '<S250>/Add3'
   *  Sum: '<S250>/Add4'
   */
  if (localDataTypeConversion1_dj >= 0.0F) {
    localDataTypeConversion1_dj += 0.5F;
  } else {
    localDataTypeConversion1_dj -= 0.5F;
  }

  /* DataTypeConversion: '<S250>/OutDTConv' */
  if (localDataTypeConversion1_dj < 32768.0F) {
    if (localDataTypeConversion1_dj >= -32768.0F) {
      localOutDTConv_mj = (SInt16)localDataTypeConversion1_dj;
    } else {
      localOutDTConv_mj = MIN_int16_T;
    }
  } else {
    localOutDTConv_mj = MAX_int16_T;
  }

  /* Product: '<S251>/Product4' incorporates:
   *  Constant: '<S251>/offset'
   *  Constant: '<S251>/one_on_slope'
   *  Sum: '<S251>/Add1'
   */
  localDataTypeConversion1_dj = 16.0F * EngLimTqT_B.Merge4;

  /* Switch: '<S251>/Switch1' incorporates:
   *  Constant: '<S251>/offset2'
   *  Constant: '<S251>/offset3'
   *  Constant: '<S251>/offset4'
   *  RelationalOperator: '<S251>/Relational Operator'
   *  Sum: '<S251>/Add3'
   *  Sum: '<S251>/Add4'
   */
  if (localDataTypeConversion1_dj >= 0.0F) {
    localDataTypeConversion1_dj += 0.5F;
  } else {
    localDataTypeConversion1_dj -= 0.5F;
  }

  /* Switch: '<S252>/Switch' incorporates:
   *  Constant: '<S252>/Byp_Fonction_SC'
   *  Constant: '<S252>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localOutDTConv_mj = EngLim_tqIdcEngCurGBx_B;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtEngLim_tqIdcEngCurGBxInport2' */
  Rte_Write_P_EngLim_tqIdcEngCurGBx_EngLim_tqIdcEngCurGBx(localOutDTConv_mj);

  /* Switch: '<S253>/Switch' incorporates:
   *  Constant: '<S253>/Byp_Fonction_SC'
   *  Constant: '<S253>/Int_BypC'
   *  DataTypeConversion: '<S251>/OutDTConv'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localOutDTConv_mj = EngLim_tqIdcEngCur_B;
  } else if (localDataTypeConversion1_dj < 32768.0F) {
    if (localDataTypeConversion1_dj >= -32768.0F) {
      localOutDTConv_mj = (SInt16)localDataTypeConversion1_dj;
    } else {
      localOutDTConv_mj = MIN_int16_T;
    }
  } else {
    localOutDTConv_mj = MAX_int16_T;
  }

  /* SignalConversion: '<S25>/TmpSignal ConversionAtEngLim_tqIdcEngCurInport2' */
  Rte_Write_P_EngLim_tqIdcEngCur_EngLim_tqIdcEngCur(localOutDTConv_mj);
}

/* Start for exported function: RE_EngLimTqT_010_TEV */
void RE_EngLimTqT_010_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_Calcul_richesse'
   *
   * Block requirements for '<S1>/F02_Calcul_richesse':
   *  1. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_113.01 ;
   *  2. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_001.01 ;
   *  3. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_002.01 ;
   *  4. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_004.01 ;
   *  5. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_041.01 ;
   *  6. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_078.01 ;
   *  7. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_043.01 ;
   *  8. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_080.01 ;
   *  9. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_079.01 ;
   *  10. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_076.01 ;
   *  11. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_077.02 ;
   *  12. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_138.01 ;
   *  13. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_139.01 ;
   *  14. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_149.02 ;
   *  15. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_150.02 ;
   */
}

/* Output and update for exported function: RE_EngLimTqT_010_TEV */
void RE_EngLimTqT_010_TEV(void)
{
  Boolean localTmpSignalConversionAtIg_az;
  Float32 localDataTypeConversion2_bs;
  Float32 localDivide_l5;
  Float32 localDivide_ld;
  Boolean localTmpSignalConversionAtInj_d;
  UInt16 localTmpSignalConversionAtEng_f;
  UInt32 localMerge1_m;
  UInt16 localMerge2_l;
  UInt32 localMerge3;
  UInt16 localMerge4_h;
  UInt16 localTmpSignalConversionAtEng_d;
  UInt16 localTmpSignalConversionAtFARSp;
  UInt32 localTmpSignalConversionAtIg_l0;
  UInt16 localTmpSignalConversionAtIg_ct;

  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_Calcul_richesse'
   *
   * Block requirements for '<S1>/F02_Calcul_richesse':
   *  1. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_113.01 ;
   *  2. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_001.01 ;
   *  3. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_002.01 ;
   *  4. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_004.01 ;
   *  5. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_041.01 ;
   *  6. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_078.01 ;
   *  7. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_043.01 ;
   *  8. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_080.01 ;
   *  9. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_079.01 ;
   *  10. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_076.01 ;
   *  11. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_077.02 ;
   *  12. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_138.01 ;
   *  13. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_139.01 ;
   *  14. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_149.02 ;
   *  15. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_150.02 ;
   */

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEng_f);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&localTmpSignalConversionAtFARSp);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEngM_rAirLdPredOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdPred'
   */
  Rte_Read_R_EngM_rAirLdPred_EngM_rAirLdPred(&localTmpSignalConversionAtEng_d);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_rlamEngCorReqPrevOutport2' */
  IgSys_rlamEngCorReqPrev =
    Rte_IrvRead_RE_EngLimTqT_010_TEV_IgSys_rlamEngCorReq_irv();

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_rAirLdPredPrevOutport2' */
  IgSys_rAirLdPredPrev = Rte_IrvRead_RE_EngLimTqT_010_TEV_IgSys_rAirLdPred_irv();

  /* SignalConversion: '<S20>/TmpSignal ConversionAtInjSys_bTotCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bTotCutOff'
   */
  Rte_Read_R_InjSys_bTotCutOff_InjSys_bTotCutOff
    (&localTmpSignalConversionAtInj_d);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_bAcvStructAirOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAir'
   */
  Rte_Read_R_IgSys_bAcvStructAir_IgSys_bAcvStructAir
    (&localTmpSignalConversionAtIg_az);

  /* Outputs for enable SubSystem: '<S20>/F02_Calcul_richesse' incorporates:
   *  EnablePort: '<S87>/IgSys_bAcvStructAir'
   *
   * Block requirements for '<S20>/F02_Calcul_richesse':
   *  1. SubSystem "F02_Calcul_richesse" !Trace_To : VEMS_R_10_06438_006.01 ;
   */
  if (localTmpSignalConversionAtIg_az) {
    /* Outputs for atomic SubSystem: '<S87>/F01_Calcul_richesse' *
     * Block requirements for '<S87>/F01_Calcul_richesse':
     *  1. SubSystem "F01_Calcul_richesse" !Trace_To : VEMS_R_10_06438_007.01 ;
     */

    /* Outputs for atomic SubSystem: '<S92>/F01_calcul_lambda_consigne_corrige' *
     * Block requirements for '<S92>/F01_calcul_lambda_consigne_corrige':
     *  1. SubSystem "F01_calcul_lambda_consigne_corrige" !Trace_To : VEMS_R_10_06438_008.01 ;
     */

    /* DataTypeConversion: '<S95>/Data Type Conversion2' */
    localDataTypeConversion2_bs = ((Float32)IgSys_rlamEngCorReqPrev) *
      0.0001220703125F;

    /* Product: '<S97>/Divide' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion2'
     */
    localDivide_l5 = (((Float32)localTmpSignalConversionAtEng_f) *
                      6.103515625E-005F) / localDataTypeConversion2_bs;

    /* Outputs for atomic SubSystem: '<S97>/If Action Subsystem3' */

    /* Switch: '<S101>/Switch1' incorporates:
     *  Constant: '<S101>/Constant1'
     *  Constant: '<S101>/Constant2'
     *  Constant: '<S101>/Constant3'
     *  Logic: '<S101>/Logical Operator1'
     *  RelationalOperator: '<S101>/Relational Operator'
     *  RelationalOperator: '<S101>/Relational Operator1'
     *  RelationalOperator: '<S101>/Relational Operator3'
     */
    if (((localDivide_l5 != localDivide_l5) || (localDivide_l5 >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_l5)) {
      localDivide_l5 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S97>/If Action Subsystem3' */

    /* Product: '<S98>/Divide' incorporates:
     *  DataTypeConversion: '<S95>/Data Type Conversion1'
     */
    localDivide_ld = localDivide_l5 / (((Float32)IgSys_rAirLdPredPrev) *
      6.103515625E-005F);

    /* Outputs for atomic SubSystem: '<S98>/If Action Subsystem3' */

    /* Switch: '<S103>/Switch1' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Constant: '<S103>/Constant2'
     *  Constant: '<S103>/Constant3'
     *  Logic: '<S103>/Logical Operator1'
     *  RelationalOperator: '<S103>/Relational Operator'
     *  RelationalOperator: '<S103>/Relational Operator1'
     *  RelationalOperator: '<S103>/Relational Operator3'
     */
    if (((localDivide_ld != localDivide_ld) || (localDivide_ld >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_ld)) {
      localDivide_ld = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S98>/If Action Subsystem3' */

    /* Product: '<S99>/Divide' incorporates:
     *  Constant: '<S95>/Cste_1'
     */
    localDivide_l5 = 1.0F / localDataTypeConversion2_bs;

    /* Outputs for atomic SubSystem: '<S99>/If Action Subsystem3' */

    /* Switch: '<S105>/Switch1' incorporates:
     *  Constant: '<S105>/Constant1'
     *  Constant: '<S105>/Constant2'
     *  Constant: '<S105>/Constant3'
     *  Logic: '<S105>/Logical Operator1'
     *  RelationalOperator: '<S105>/Relational Operator'
     *  RelationalOperator: '<S105>/Relational Operator1'
     *  RelationalOperator: '<S105>/Relational Operator3'
     */
    if (((localDivide_l5 != localDivide_l5) || (localDivide_l5 >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_l5)) {
      localDivide_l5 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S99>/If Action Subsystem3' */

    /* Switch: '<S95>/Switch4' incorporates:
     *  Constant: '<S95>/IgSys_bLamClc_C'
     */
    if (IgSys_bLamClc_C) {
      IgSys_facLamReqCor = localDivide_l5;
    } else {
      IgSys_facLamReqCor = localDivide_ld;
    }

    /* end of Outputs for SubSystem: '<S92>/F01_calcul_lambda_consigne_corrige' */

    /* Outputs for atomic SubSystem: '<S92>/F02_calcul_richesse' *
     * Block requirements for '<S92>/F02_calcul_richesse':
     *  1. SubSystem "F02_calcul_richesse" !Trace_To : VEMS_R_10_06438_009.01 ;
     */

    /* Switch: '<S96>/Switch2' incorporates:
     *  Constant: '<S96>/Cste_1_1'
     */
    if (localTmpSignalConversionAtInj_d) {
      localDivide_l5 = 1.0F;
    } else {
      localDivide_l5 = IgSys_facLamReqCor;
    }

    /* RelationalOperator: '<S110>/LowerRelop1' incorporates:
     *  Constant: '<S96>/Cste_2'
     */
    localTmpSignalConversionAtInj_d = (localDivide_l5 > 10.0F);

    /* Switch: '<S110>/Switch' incorporates:
     *  Constant: '<S96>/Cste'
     *  RelationalOperator: '<S110>/UpperRelop'
     */
    if (localDivide_l5 < 7.000000030E-002F) {
      localDivide_l5 = 7.000000030E-002F;
    }

    /* Switch: '<S110>/Switch2' incorporates:
     *  Constant: '<S96>/Cste_2'
     */
    if (localTmpSignalConversionAtInj_d) {
      localDivide_l5 = 10.0F;
    }

    /* end of Outputs for SubSystem: '<S92>/F02_calcul_richesse' */

    /* end of Outputs for SubSystem: '<S87>/F01_Calcul_richesse' */

    /* DataTypeConversion: '<S93>/OutDTConv' incorporates:
     *  Constant: '<S93>/offset'
     *  Constant: '<S93>/offset1'
     *  Constant: '<S93>/one_on_slope'
     *  Product: '<S93>/Product4'
     *  Sum: '<S93>/Add1'
     *  Sum: '<S93>/Add2'
     */
    localDataTypeConversion2_bs = (8192.0F * localDivide_l5) + 0.5F;
    if (localDataTypeConversion2_bs < 4.294967296E+009F) {
      localMerge3 = (UInt32)localDataTypeConversion2_bs;
    } else {
      localMerge3 = MAX_uint32_T;
    }

    /* DataTypeConversion: '<S94>/OutDTConv' incorporates:
     *  Constant: '<S94>/offset'
     *  Constant: '<S94>/offset1'
     *  Constant: '<S94>/one_on_slope'
     *  Constant: '<S96>/Cste_1'
     *  Product: '<S107>/Divide'
     *  Product: '<S94>/Product4'
     *  Sum: '<S94>/Add1'
     *  Sum: '<S94>/Add2'
     */
    localDataTypeConversion2_bs = ((1.0F / localDivide_l5) * 4.464305176E+003F)
      + 0.5F;
    if (localDataTypeConversion2_bs < 65536.0F) {
      localMerge4_h = (UInt16)localDataTypeConversion2_bs;
    } else {
      localMerge4_h = MAX_uint16_T;
    }

    /* SignalConversion: '<S87>/Signal Conversion2' */
    localMerge2_l = localTmpSignalConversionAtEng_d;

    /* DataTypeConversion: '<S87>/Data Type Conversion4' */
    localMerge1_m = (UInt32)(localTmpSignalConversionAtFARSp << 1);
  }

  /* end of Outputs for SubSystem: '<S20>/F02_Calcul_richesse' */

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_rlamClcPrevOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rlamClc_INPUT'
   */
  Rte_Read_R_IgSys_rlamClc_IgSys_rlamClc(&localTmpSignalConversionAtIg_ct);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_lamClcPrevOutport2' incorporates:
   *  Inport: '<Root>/IgSys_lamClc_INPUT'
   */
  Rte_Read_R_IgSys_lamClc_IgSys_lamClc(&localTmpSignalConversionAtIg_l0);

  /* Outputs for enable SubSystem: '<S20>/F01_Initialisation_remplissage' incorporates:
   *  EnablePort: '<S86>/IgSys_bNoAcvStructAir'
   *  Logic: '<S20>/Logical Operator3'
   *
   * Block requirements for '<S20>/F01_Initialisation_remplissage':
   *  1. SubSystem "F01_Initialisation_remplissage" !Trace_To : VEMS_R_10_06438_005.01 ;
   */
  if (!localTmpSignalConversionAtIg_az) {
    /* Constant: '<S86>/Cste_1' */
    localMerge1_m = 8192U;

    /* SignalConversion: '<S86>/Signal Conversion2' */
    localMerge2_l = localTmpSignalConversionAtEng_f;

    /* SignalConversion: '<S86>/Signal Conversion1' */
    localMerge3 = localTmpSignalConversionAtIg_l0;

    /* SignalConversion: '<S86>/Signal Conversion3' */
    localMerge4_h = localTmpSignalConversionAtIg_ct;
  }

  /* end of Outputs for SubSystem: '<S20>/F01_Initialisation_remplissage' */

  /* SignalConversion: '<S88>/copy' */
  IgSys_rlamEngCorReq_IRV_MP = localMerge1_m;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S88>/autosar_testpoint1' */

  /* S-Function Block: <S88>/autosar_testpoint1 */

  /* SignalConversion: '<S89>/copy' */
  IgSys_rAirLdPred_IRV_MP = localMerge2_l;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S89>/autosar_testpoint1' */

  /* S-Function Block: <S89>/autosar_testpoint1 */

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Byp_Fonction_SC'
   *  Constant: '<S91>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localMerge3 = IgSys_lamClc_B;
  }

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_lamClcInport2' */
  Rte_Write_P_IgSys_lamClc_IgSys_lamClc(localMerge3);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_rAirLdPred_irvInport2' incorporates:
   *  SignalConversion: '<S20>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_EngLimTqT_010_TEV_IgSys_rAirLdPred_irv(localMerge2_l);

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S90>/Byp_Fonction_SC'
   *  Constant: '<S90>/Int_BypC'
   */
  if (ENGLIMTQT_ACTIVE_BYP_C) {
    localMerge4_h = IgSys_rlamClc_B;
  }

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_rlamClcInport2' */
  Rte_Write_P_IgSys_rlamClc_IgSys_rlamClc(localMerge4_h);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtIgSys_rlamEngCorReq_irvInport2' incorporates:
   *  SignalConversion: '<S20>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_EngLimTqT_010_TEV_IgSys_rlamEngCorReq_irv(localMerge1_m);
}

/* Model initialize function */
void Runnable_EngLimTqT_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__10'
   *  Start for SubSystem: '<Root>/__ExpFcn__11'
   *  Start for SubSystem: '<Root>/__ExpFcn__12'
   *  Start for SubSystem: '<Root>/__ExpFcn__13'
   *  Start for SubSystem: '<Root>/__ExpFcn__14'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   *  Start for SubSystem: '<Root>/__ExpFcn__7'
   *  Start for SubSystem: '<Root>/__ExpFcn__8'
   *  Start for SubSystem: '<Root>/__ExpFcn__9'
   */
  RE_EngLimTqT_011_MSE_Start();
  RE_EngLimTqT_013_MSE_Start();
  RE_EngLimTqT_009_MSE_Start();
  RE_EngLimTqT_001_MSE_Start();
  RE_EngLimTqT_003_MSE_Start();
  RE_EngLimTqT_012_DRE_Start();
  RE_EngLimTqT_014_DRE_Start();
  RE_EngLimTqT_002_DRE_Start();
  RE_EngLimTqT_004_DRE_Start();
  RE_EngLimTqT_010_TEV_Start();
  EngLimTqT_PrevZCSigState.F02_Detecter_coupure_Trig_ZCE = POS_ZCSIG;
}

#define EngLimTqT_STOP_SEC_CODE
#include "EngLimTqT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
