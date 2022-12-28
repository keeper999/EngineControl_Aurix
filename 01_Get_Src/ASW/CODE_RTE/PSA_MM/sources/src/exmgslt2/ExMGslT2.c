/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : ExMGslT2                                                */
/* !Description     : ExMGslT2 Software Component                             */
/*                                                                            */
/* !Module          : ExMGslT2                                                */
/* !Description     : ExMGslT2 Software Component                             */
/*                                                                            */
/* !File            : ExMGslT2.c                                              */
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
/*   Model name       : ExMGslT2_AUTOSAR.mdl                                  */
/*   Root subsystem   : /ExMGslT2                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M06-ExMGslT2/5-S$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   05 Jul 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ExMGslT2.h"
#include "ExMGslT2_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define ExMGslT2_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ExMGslT2_MemMap.h"

/* Block signals (auto storage) */
BlockIO_ExMGslT2 ExMGslT2_B;

/* Block states (auto storage) */
D_Work_ExMGslT2 ExMGslT2_DWork;

#define ExMGslT2_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ExMGslT2_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define EXMGSLT2_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define EXMGSLT2_VEMSRTLIBT_MINOR_VERSION_REQ 13
#define EXMGSLT2_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define EXMGSLT2_VEMSRTLIBT_VERSION_REQ (EXMGSLT2_VEMSRTLIBT_PATCH_VERSION_REQ + EXMGSLT2_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + EXMGSLT2_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if EXMGSLT2_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define ExMGslT2_START_SEC_CODE
#include "ExMGslT2_MemMap.h"

void ExMGslT2_ASYNC1(int controlPortIdx)
{
}

void ExMGslT2_ASYNC2(int controlPortIdx)
{
}

/* Start for exported function: RE_ExMGslT2_001_MSE */
void RE_ExMGslT2_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Initialization'
   */
}

/* Output and update for exported function: RE_ExMGslT2_001_MSE */
void RE_ExMGslT2_001_MSE(void)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion[12];
  Float32 localSum2[12];
  Float32 localSum2_p[12];
  Float32 localSelector_h;
  Float32 localDataTypeConversion1;
  Float32 localDataTypeConversion2;
  UInt8 localSum4;
  UInt8 localSum1_o;
  UInt8 localSum2_a;
  UInt8 localSum11;
  UInt8 localSum12;
  UInt8 localSum13;
  UInt8 localSum14;
  SInt8 localTmpSignalConversionAtExt_t;
  SInt32 localDataTypeConversion3;
  Float32 localSelector;
  Float32 localSelector_i;
  Float32 localSum;
  SInt16 localOutDTConv;
  Float32 localProduct4[6];
  Float32 localSum8;
  SInt16 localOutDTConv_l;
  UInt32 localTmpSignalConversionAtEOM_t;
  UInt16 localDataTypeConversion1_c;
  Float32 localDataTypeConversion3_m[12];
  Float32 localPrelookup_o2;
  Float32 localfractionTmp_0d;
  SInt32 localPrelookup_o1;
  Float32 localSum3_d;
  SInt32 localDataTypeConversion2_i;
  SInt32 localAdd_j;
  SInt32 localAdd_g;
  SInt32 localAdd_a;
  UInt8 localAssignment[4];
  UInt16 localOutDTConv_p2;
  UInt16 localSwitch_ga[12];
  UInt16 localSwitch_a[6];
  UInt16 localSwitch_fl[12];
  SInt32 locali;
  Float32 localtmp;
  UInt16 locallocalDataTypeConversion1_c;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Initialization'
   */

  /* user code (Output function Body for TID5) */
  RE_ExMGslT2_Init();

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEOM_tiEngStopOutport2' incorporates:
   *  Inport: '<Root>/EOM_tiEngStop'
   */
  Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&localTmpSignalConversionAtEOM_t);

  /* Outputs for atomic SubSystem: '<S5>/F01_Initialization_map_index' */

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  if (localTmpSignalConversionAtEOM_t > 65535U) {
    locallocalDataTypeConversion1_c = MAX_uint16_T;
  } else {
    locallocalDataTypeConversion1_c = (UInt16)localTmpSignalConversionAtEOM_t;
  }

  /* PreLookup: '<S59>/Prelookup' */
  localPrelookup_o1 = plook_s32u16f_bincpa(locallocalDataTypeConversion1_c,
    (&(ExM_tiEngStop_A[0])), 15U, &localPrelookup_o2,
    &ExMGslT2_DWork.Prelookup_DWORK1_n);

  /* end of Outputs for SubSystem: '<S5>/F01_Initialization_map_index' */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_tAirOutport2' incorporates:
   *  Inport: '<Root>/Ext_tAir'
   */
  Rte_Read_R_Ext_tAir_Ext_tAir(&localTmpSignalConversionAtExt_t);

  /* DataTypeConversion: '<S5>/Data Type Conversion3' */
  localDataTypeConversion3 = localTmpSignalConversionAtExt_t;

  /* S-Function (NvRamReadAccess): '<S5>/S-Function2' */
  {
    UInt32 locali;
    for (locali=0 ; locali <12; locali++) {
      ExMGslT2_B.SFunction2[locali] =
        ExMGslT2_sNV_Z1_CONST_16BIT.ExM_prm_tEg_NV[locali];
    }
  }

  /* Outputs for atomic SubSystem: '<S5>/F03_Gas_temperature_initialization' */

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  for (locali = 0; locali < 12; locali++) {
    localDataTypeConversion3_m[locali] = (((Float32)ExMGslT2_B.SFunction2
      [(locali)]) * 0.03125F) + 223.0F;
  }

  /* Sum: '<S11>/Sum4' incorporates:
   *  Constant: '<S11>/Cste_86'
   *  Constant: '<S11>/ExM_noSelTExMnf_C'
   */
  locali = ExM_noSelTExMnf_C;
  localTmpSignalConversionAtEOM_t = ((UInt32)locali) - 1U;
  if (localTmpSignalConversionAtEOM_t > ((UInt32)locali)) {
    localTmpSignalConversionAtEOM_t = 0U;
  }

  /* Interpolation_n-D: '<S78>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2;
  localfractionTmp_0d = intrp1d_iu16n16ff_s32f_la_n(localPrelookup_o1,
    localfractionTmp_0d, (&(ExM_facNatCnvcTEg_T[0])), 15U);

  /* Sum: '<S11>/Sum3' incorporates:
   *  Constant: '<S11>/Cste_87'
   */
  localSum3_d = 2.731499939E+002F + ((Float32)localDataTypeConversion3);

  /* Selector: '<S74>/Selector' incorporates:
   *  Constant: '<S74>/Constant'
   *  MinMax: '<S74>/MinMax'
   */
  for (locali = 0; locali < 12; locali++) {
    /* Sum: '<S11>/Sum2' incorporates:
     *  Product: '<S79>/Divide'
     *  Sum: '<S11>/Sum1'
     */
    localSum2_p[locali] = ((localDataTypeConversion3_m[locali] - localSum3_d) *
      localfractionTmp_0d) + localSum3_d;

    /* DataTypeConversion: '<S26>/OutDTConv' incorporates:
     *  Constant: '<S26>/offset'
     *  Constant: '<S26>/one_on_slope'
     *  Product: '<S26>/Product4'
     *  Sum: '<S26>/Add1'
     */
    localSelector = (localSum2_p[locali] - 223.0F) * 32.0F;
    if (localSelector < 65536.0F) {
      if (localSelector >= 0.0F) {
        locallocalDataTypeConversion1_c = (UInt16)localSelector;
      } else {
        locallocalDataTypeConversion1_c = 0U;
      }
    } else {
      locallocalDataTypeConversion1_c = MAX_uint16_T;
    }

    ExMGslT2_B.OutDTConv_ip[(locali)] = locallocalDataTypeConversion1_c;
  }

  localSelector = localSum2_p[(SInt32)rt_MIN(localTmpSignalConversionAtEOM_t,
    11U)];

  /* Sum: '<S11>/Sum5' incorporates:
   *  Constant: '<S11>/Cste_88'
   *  Constant: '<S11>/ExM_noSelTEgUsMainOxC_C'
   */
  locali = ExM_noSelTEgUsMainOxC_C;
  localTmpSignalConversionAtEOM_t = ((UInt32)locali) - 1U;
  if (localTmpSignalConversionAtEOM_t > ((UInt32)locali)) {
    localTmpSignalConversionAtEOM_t = 0U;
  }

  /* Selector: '<S75>/Selector' incorporates:
   *  Constant: '<S75>/Constant'
   *  MinMax: '<S75>/MinMax'
   */
  localSelector_i = localSum2_p[(SInt32)rt_MIN(localTmpSignalConversionAtEOM_t,
    11U)];

  /* Sum: '<S11>/Sum6' incorporates:
   *  Constant: '<S11>/Cste_89'
   *  Constant: '<S11>/ExM_noSelTEgOxC_C'
   */
  locali = ExM_noSelTEgOxC_C;
  localTmpSignalConversionAtEOM_t = ((UInt32)locali) - 1U;
  if (localTmpSignalConversionAtEOM_t > ((UInt32)locali)) {
    localTmpSignalConversionAtEOM_t = 0U;
  }

  /* Selector: '<S76>/Selector' incorporates:
   *  Constant: '<S76>/Constant'
   *  MinMax: '<S76>/MinMax'
   */
  localSelector_h = localSum2_p[(SInt32)rt_MIN(localTmpSignalConversionAtEOM_t,
    11U)];

  /* Sum: '<S11>/Sum7' incorporates:
   *  Constant: '<S11>/Cste_90'
   *  Constant: '<S11>/ExM_noSelTEgPreOxC_C'
   */
  locali = ExM_noSelTEgPreOxC_C;
  localTmpSignalConversionAtEOM_t = ((UInt32)locali) - 1U;
  if (localTmpSignalConversionAtEOM_t > ((UInt32)locali)) {
    localTmpSignalConversionAtEOM_t = 0U;
  }

  /* Sum: '<S11>/Sum' incorporates:
   *  Constant: '<S11>/Cste_60'
   */
  localSum = localSelector_h - 2.731499939E+002F;

  /* Sum: '<S11>/Sum8' incorporates:
   *  Constant: '<S11>/Cste_1'
   *  Constant: '<S77>/Constant'
   *  MinMax: '<S77>/MinMax'
   *  Selector: '<S77>/Selector'
   */
  localSum8 = localSum2_p[(SInt32)rt_MIN(localTmpSignalConversionAtEOM_t, 11U)]
    - 2.731499939E+002F;

  /* end of Outputs for SubSystem: '<S5>/F03_Gas_temperature_initialization' */

  /* S-Function (NvRamWriteAccess): '<S5>/EepromWriteAccess' */
  {
    UInt32 locali;
    for (locali=0 ; locali <12; locali++) {
      ExMGslT2_sNV_Z1_CONST_16BIT.ExM_prm_tEg_NV[locali] =
        ExMGslT2_B.OutDTConv_ip[locali];
    }
  }

  /* S-Function (NvRamReadAccess): '<S5>/S-Function1' */
  {
    UInt32 locali;
    for (locali=0 ; locali <12; locali++) {
      ExMGslT2_B.SFunction1[locali] =
        ExMGslT2_sNV_Z1_CONST_16BIT.ExM_prm_tWall_NV[locali];
    }
  }

  /* Outputs for atomic SubSystem: '<S5>/F04_Wall_temperature_initialization' */

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  for (locali = 0; locali < 12; locali++) {
    localDataTypeConversion3_m[locali] = (((Float32)ExMGslT2_B.SFunction1
      [(locali)]) * 0.03125F) + 223.0F;
  }

  /* Interpolation_n-D: '<S80>/Interpolation Using Prelookup3' */
  localfractionTmp_0d = localPrelookup_o2;
  localSum3_d = intrp1d_iu16n16ff_s32f_la_n(localPrelookup_o1,
    localfractionTmp_0d, (&(ExM_facNatCnvcTWall_T[0])), 15U);

  /* Sum: '<S12>/Sum3' incorporates:
   *  Constant: '<S12>/Cste_87'
   */
  localfractionTmp_0d = 2.731499939E+002F + ((Float32)localDataTypeConversion3);

  /* end of Outputs for SubSystem: '<S5>/F04_Wall_temperature_initialization' */
  for (locali = 0; locali < 12; locali++) {
    /* Sum: '<S12>/Sum2' incorporates:
     *  Product: '<S81>/Divide'
     *  Sum: '<S12>/Sum1'
     */
    localSum2[locali] = ((localDataTypeConversion3_m[locali] -
                          localfractionTmp_0d) * localSum3_d) +
      localfractionTmp_0d;

    /* DataTypeConversion: '<S25>/OutDTConv' incorporates:
     *  Constant: '<S25>/offset'
     *  Constant: '<S25>/one_on_slope'
     *  Product: '<S25>/Product4'
     *  Sum: '<S25>/Add1'
     */
    localtmp = (localSum2[locali] - 223.0F) * 32.0F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalDataTypeConversion1_c = (UInt16)localtmp;
      } else {
        locallocalDataTypeConversion1_c = 0U;
      }
    } else {
      locallocalDataTypeConversion1_c = MAX_uint16_T;
    }

    ExMGslT2_B.OutDTConv_j[(locali)] = locallocalDataTypeConversion1_c;
  }

  /* S-Function (NvRamWriteAccess): '<S5>/EepromWriteAccess1' */
  {
    UInt32 locali;
    for (locali=0 ; locali <12; locali++) {
      ExMGslT2_sNV_Z1_CONST_16BIT.ExM_prm_tWall_NV[locali] =
        ExMGslT2_B.OutDTConv_j[locali];
    }
  }

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write1' */

  /* S-Function Block: <S8>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_01_irv(localSum2[0]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write10' */

  /* S-Function Block: <S8>/autosar_irv_write10 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_10_irv(localSum2[9]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write11' */

  /* S-Function Block: <S8>/autosar_irv_write11 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_11_irv(localSum2[10]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write12' */

  /* S-Function Block: <S8>/autosar_irv_write12 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_12_irv(localSum2[11]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write2' */

  /* S-Function Block: <S8>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_02_irv(localSum2[1]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write3' */

  /* S-Function Block: <S8>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_03_irv(localSum2[2]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write4' */

  /* S-Function Block: <S8>/autosar_irv_write4 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_04_irv(localSum2[3]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write5' */

  /* S-Function Block: <S8>/autosar_irv_write5 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_05_irv(localSum2[4]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write6' */

  /* S-Function Block: <S8>/autosar_irv_write6 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_06_irv(localSum2[5]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write7' */

  /* S-Function Block: <S8>/autosar_irv_write7 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_07_irv(localSum2[6]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write8' */

  /* S-Function Block: <S8>/autosar_irv_write8 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_08_irv(localSum2[7]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_write9' */

  /* S-Function Block: <S8>/autosar_irv_write9 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tWall_09_irv(localSum2[8]);

  /* SignalConversion: '<S47>/copy' */
  ExM_prm_tWall_01_IRV_MP = localSum2[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S47>/autosar_testpoint1' */

  /* S-Function Block: <S47>/autosar_testpoint1 */

  /* SignalConversion: '<S48>/copy' */
  ExM_prm_tWall_10_IRV_MP = localSum2[9];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S48>/autosar_testpoint1' */

  /* S-Function Block: <S48>/autosar_testpoint1 */

  /* SignalConversion: '<S49>/copy' */
  ExM_prm_tWall_11_IRV_MP = localSum2[10];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S49>/autosar_testpoint1' */

  /* S-Function Block: <S49>/autosar_testpoint1 */

  /* SignalConversion: '<S50>/copy' */
  ExM_prm_tWall_12_IRV_MP = localSum2[11];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S50>/autosar_testpoint1' */

  /* S-Function Block: <S50>/autosar_testpoint1 */

  /* SignalConversion: '<S51>/copy' */
  ExM_prm_tWall_02_IRV_MP = localSum2[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S51>/autosar_testpoint1' */

  /* S-Function Block: <S51>/autosar_testpoint1 */

  /* SignalConversion: '<S52>/copy' */
  ExM_prm_tWall_03_IRV_MP = localSum2[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S52>/autosar_testpoint1' */

  /* S-Function Block: <S52>/autosar_testpoint1 */

  /* SignalConversion: '<S53>/copy' */
  ExM_prm_tWall_04_IRV_MP = localSum2[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S53>/autosar_testpoint1' */

  /* S-Function Block: <S53>/autosar_testpoint1 */

  /* SignalConversion: '<S54>/copy' */
  ExM_prm_tWall_05_IRV_MP = localSum2[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S54>/autosar_testpoint1' */

  /* S-Function Block: <S54>/autosar_testpoint1 */

  /* SignalConversion: '<S55>/copy' */
  ExM_prm_tWall_06_IRV_MP = localSum2[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S55>/autosar_testpoint1' */

  /* S-Function Block: <S55>/autosar_testpoint1 */

  /* SignalConversion: '<S56>/copy' */
  ExM_prm_tWall_07_IRV_MP = localSum2[6];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S56>/autosar_testpoint1' */

  /* S-Function Block: <S56>/autosar_testpoint1 */

  /* SignalConversion: '<S57>/copy' */
  ExM_prm_tWall_08_IRV_MP = localSum2[7];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S57>/autosar_testpoint1' */

  /* S-Function Block: <S57>/autosar_testpoint1 */

  /* SignalConversion: '<S58>/copy' */
  ExM_prm_tWall_09_IRV_MP = localSum2[8];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S58>/autosar_testpoint1' */

  /* S-Function Block: <S58>/autosar_testpoint1 */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write1' */

  /* S-Function Block: <S17>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_01_irv(localSum2_p[0]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write10' */

  /* S-Function Block: <S17>/autosar_irv_write10 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_10_irv(localSum2_p[9]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write11' */

  /* S-Function Block: <S17>/autosar_irv_write11 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_11_irv(localSum2_p[10]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write12' */

  /* S-Function Block: <S17>/autosar_irv_write12 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_12_irv(localSum2_p[11]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write2' */

  /* S-Function Block: <S17>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_02_irv(localSum2_p[1]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write3' */

  /* S-Function Block: <S17>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_03_irv(localSum2_p[2]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write4' */

  /* S-Function Block: <S17>/autosar_irv_write4 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_04_irv(localSum2_p[3]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write5' */

  /* S-Function Block: <S17>/autosar_irv_write5 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_05_irv(localSum2_p[4]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write6' */

  /* S-Function Block: <S17>/autosar_irv_write6 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_06_irv(localSum2_p[5]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write7' */

  /* S-Function Block: <S17>/autosar_irv_write7 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_07_irv(localSum2_p[6]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write8' */

  /* S-Function Block: <S17>/autosar_irv_write8 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_08_irv(localSum2_p[7]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S17>/autosar_irv_write9' */

  /* S-Function Block: <S17>/autosar_irv_write9 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgRaw_09_irv(localSum2_p[8]);

  /* SignalConversion: '<S103>/copy' */
  ExM_prm_tEgRaw_01_IRV_MP = localSum2_p[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S103>/autosar_testpoint1' */

  /* S-Function Block: <S103>/autosar_testpoint1 */

  /* SignalConversion: '<S104>/copy' */
  ExM_prm_tEgRaw_10_IRV_MP = localSum2_p[9];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S104>/autosar_testpoint1' */

  /* S-Function Block: <S104>/autosar_testpoint1 */

  /* SignalConversion: '<S105>/copy' */
  ExM_prm_tEgRaw_11_IRV_MP = localSum2_p[10];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S105>/autosar_testpoint1' */

  /* S-Function Block: <S105>/autosar_testpoint1 */

  /* SignalConversion: '<S106>/copy' */
  ExM_prm_tEgRaw_12_IRV_MP = localSum2_p[11];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S106>/autosar_testpoint1' */

  /* S-Function Block: <S106>/autosar_testpoint1 */

  /* SignalConversion: '<S107>/copy' */
  ExM_prm_tEgRaw_02_IRV_MP = localSum2_p[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S107>/autosar_testpoint1' */

  /* S-Function Block: <S107>/autosar_testpoint1 */

  /* SignalConversion: '<S108>/copy' */
  ExM_prm_tEgRaw_03_IRV_MP = localSum2_p[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S108>/autosar_testpoint1' */

  /* S-Function Block: <S108>/autosar_testpoint1 */

  /* SignalConversion: '<S109>/copy' */
  ExM_prm_tEgRaw_04_IRV_MP = localSum2_p[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S109>/autosar_testpoint1' */

  /* S-Function Block: <S109>/autosar_testpoint1 */

  /* SignalConversion: '<S110>/copy' */
  ExM_prm_tEgRaw_05_IRV_MP = localSum2_p[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S110>/autosar_testpoint1' */

  /* S-Function Block: <S110>/autosar_testpoint1 */

  /* SignalConversion: '<S111>/copy' */
  ExM_prm_tEgRaw_06_IRV_MP = localSum2_p[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S111>/autosar_testpoint1' */

  /* S-Function Block: <S111>/autosar_testpoint1 */

  /* SignalConversion: '<S112>/copy' */
  ExM_prm_tEgRaw_07_IRV_MP = localSum2_p[6];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S112>/autosar_testpoint1' */

  /* S-Function Block: <S112>/autosar_testpoint1 */

  /* SignalConversion: '<S113>/copy' */
  ExM_prm_tEgRaw_08_IRV_MP = localSum2_p[7];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S113>/autosar_testpoint1' */

  /* S-Function Block: <S113>/autosar_testpoint1 */

  /* SignalConversion: '<S114>/copy' */
  ExM_prm_tEgRaw_09_IRV_MP = localSum2_p[8];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S114>/autosar_testpoint1' */

  /* S-Function Block: <S114>/autosar_testpoint1 */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S19>/autosar_irv_write1' */

  /* S-Function Block: <S19>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgOxC_01_irv(localSelector_h);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S19>/autosar_irv_write2' */

  /* S-Function Block: <S19>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgOxC_02_irv(localSelector_h);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S19>/autosar_irv_write3' */

  /* S-Function Block: <S19>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_tEgOxC_03_irv(localSelector_h);

  /* SignalConversion: '<S127>/copy' */
  ExM_prm_tEgOxC_01_IRV_MP = localSelector_h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S127>/autosar_testpoint1' */

  /* S-Function Block: <S127>/autosar_testpoint1 */

  /* SignalConversion: '<S128>/copy' */
  ExM_prm_tEgOxC_02_IRV_MP = localSelector_h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S128>/autosar_testpoint1' */

  /* S-Function Block: <S128>/autosar_testpoint1 */

  /* SignalConversion: '<S129>/copy' */
  ExM_prm_tEgOxC_03_IRV_MP = localSelector_h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S129>/autosar_testpoint1' */

  /* S-Function Block: <S129>/autosar_testpoint1 */

  /* Product: '<S21>/Product4' incorporates:
   *  Constant: '<S21>/offset'
   *  Constant: '<S21>/one_on_slope'
   *  Sum: '<S21>/Add1'
   */
  localDataTypeConversion2 = (localSelector - 223.0F) * 32.0F;

  /* DataTypeConversion: '<S21>/OutDTConv' */
  if (localDataTypeConversion2 < 65536.0F) {
    if (localDataTypeConversion2 >= 0.0F) {
      localDataTypeConversion1_c = (UInt16)localDataTypeConversion2;
    } else {
      localDataTypeConversion1_c = 0U;
    }
  } else {
    localDataTypeConversion1_c = MAX_uint16_T;
  }

  /* Product: '<S22>/Product4' incorporates:
   *  Constant: '<S22>/offset'
   *  Constant: '<S22>/one_on_slope'
   *  Sum: '<S22>/Add1'
   */
  localDataTypeConversion2 = (localSelector_i - 223.0F) * 32.0F;

  /* DataTypeConversion: '<S22>/OutDTConv' */
  if (localDataTypeConversion2 < 65536.0F) {
    if (localDataTypeConversion2 >= 0.0F) {
      localOutDTConv_p2 = (UInt16)localDataTypeConversion2;
    } else {
      localOutDTConv_p2 = 0U;
    }
  } else {
    localOutDTConv_p2 = MAX_uint16_T;
  }

  /* Product: '<S23>/Product4' incorporates:
   *  Constant: '<S23>/offset'
   *  Constant: '<S23>/one_on_slope'
   *  Sum: '<S23>/Add1'
   */
  localDataTypeConversion2 = localSum;

  /* DataTypeConversion: '<S23>/OutDTConv' */
  if (localDataTypeConversion2 < 32768.0F) {
    if (localDataTypeConversion2 >= -32768.0F) {
      localOutDTConv = (SInt16)localDataTypeConversion2;
    } else {
      localOutDTConv = MIN_int16_T;
    }
  } else {
    localOutDTConv = MAX_int16_T;
  }

  /* Product: '<S24>/Product4' incorporates:
   *  Constant: '<S24>/offset'
   *  Constant: '<S24>/one_on_slope'
   *  Sum: '<S24>/Add1'
   */
  localProduct4[0] = (localSelector - 223.0F) * 32.0F;
  localProduct4[1] = (localSelector - 223.0F) * 32.0F;
  localProduct4[2] = (localSelector - 223.0F) * 32.0F;
  localProduct4[3] = (localSelector - 223.0F) * 32.0F;
  localProduct4[4] = (localSelector - 223.0F) * 32.0F;
  localProduct4[5] = (localSelector - 223.0F) * 32.0F;

  /* Product: '<S27>/Product4' incorporates:
   *  Constant: '<S27>/offset'
   *  Constant: '<S27>/one_on_slope'
   *  Sum: '<S27>/Add1'
   */
  localDataTypeConversion2 = localSum8;

  /* DataTypeConversion: '<S27>/OutDTConv' */
  if (localDataTypeConversion2 < 32768.0F) {
    if (localDataTypeConversion2 >= -32768.0F) {
      localOutDTConv_l = (SInt16)localDataTypeConversion2;
    } else {
      localOutDTConv_l = MIN_int16_T;
    }
  } else {
    localOutDTConv_l = MAX_int16_T;
  }

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S20>/offset'
   *  Constant: '<S20>/one_on_slope'
   *  Constant: '<S38>/Byp_Fonction_SC'
   *  Constant: '<S38>/Int_BypC'
   *  DataTypeConversion: '<S20>/OutDTConv'
   *  Product: '<S20>/Product4'
   *  Sum: '<S20>/Add1'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_ga[locali] = ExM_prm_tEgFlt_B[(locali)];
    } else {
      localSelector = (localSum2_p[locali] - 223.0F) * 32.0F;
      if (localSelector < 65536.0F) {
        if (localSelector >= 0.0F) {
          locallocalDataTypeConversion1_c = (UInt16)localSelector;
        } else {
          locallocalDataTypeConversion1_c = 0U;
        }
      } else {
        locallocalDataTypeConversion1_c = MAX_uint16_T;
      }

      localSwitch_ga[locali] = locallocalDataTypeConversion1_c;
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_prm_tEgFltInport2' */
  Rte_Write_P_ExM_prm_tEgFlt_ExM_prm_tEgFlt(&localSwitch_ga);

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Byp_Fonction_SC'
   *  Constant: '<S39>/Int_BypC'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_ga[locali] = ExM_prm_tEg_B[(locali)];
    } else {
      localSwitch_ga[locali] = ExMGslT2_B.OutDTConv_ip[(locali)];
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_prm_tEgInport2' */
  Rte_Write_P_ExM_prm_tEg_ExM_prm_tEg(&localSwitch_ga);

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Byp_Fonction_SC'
   *  Constant: '<S33>/Int_BypC'
   *  DataTypeConversion: '<S24>/OutDTConv'
   */
  for (locali = 0; locali < 6; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_a[locali] = ExM_prm_tExMnfEstimCyl_B[(locali)];
    } else {
      if (localProduct4[locali] < 65536.0F) {
        if (localProduct4[locali] >= 0.0F) {
          locallocalDataTypeConversion1_c = (UInt16)localProduct4[locali];
        } else {
          locallocalDataTypeConversion1_c = 0U;
        }
      } else {
        locallocalDataTypeConversion1_c = MAX_uint16_T;
      }

      localSwitch_a[locali] = locallocalDataTypeConversion1_c;
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_prm_tExMnfEstimCylInport2' */
  Rte_Write_P_ExM_prm_tExMnfEstimCyl_ExM_prm_tExMnfEstimCyl(&localSwitch_a);

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Byp_Fonction_SC'
   *  Constant: '<S30>/Int_BypC'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_ga[locali] = ExM_prm_tWall_B[(locali)];
    } else {
      localSwitch_ga[locali] = ExMGslT2_B.OutDTConv_j[(locali)];
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_prm_tWallInport2' */
  Rte_Write_P_ExM_prm_tWall_ExM_prm_tWall(&localSwitch_ga);

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Byp_Fonction_SC'
   *  Constant: '<S43>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localDataTypeConversion1_c = ExM_tExMnfEstim_B;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_tExMnfEstimInport2' */
  Rte_Write_P_ExM_tExMnfEstim_ExM_tExMnfEstim(localDataTypeConversion1_c);

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Byp_Fonction_SC'
   *  Constant: '<S45>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv = ExM_tOxCEstim_B;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_tOxCEstimInport2' */
  Rte_Write_P_ExM_tOxCEstim_ExM_tOxCEstim(localOutDTConv);

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Byp_Fonction_SC'
   *  Constant: '<S46>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv_l = ExM_tPreOxCEstim_B;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_tPreOxCEstimInport2' */
  Rte_Write_P_ExM_tPreOxCEstim_ExM_tPreOxCEstim(localOutDTConv_l);

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Byp_Fonction_SC'
   *  Constant: '<S44>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv_p2 = ExM_tUsMainOxCEstim_B;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_tUsMainOxCEstimInport2' */
  Rte_Write_P_ExM_tUsMainOxCEstim_ExM_tUsMainOxCEstim(localOutDTConv_p2);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n);

  /* Outputs for atomic SubSystem: '<S5>/F05_Pressure_initialization' */

  /* SignalConversion: '<S13>/Signal Conversion2' */
  localSwitch_ga[0] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[1] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[2] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[3] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[4] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[5] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[6] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[7] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[8] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[9] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[10] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;
  localSwitch_ga[11] = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  for (locali = 0; locali < 12; locali++) {
    localDataTypeConversion[locali] = ((Float32)localSwitch_ga[locali]) * 8.0F;
  }

  /* SignalConversion: '<S13>/Signal Conversion' */
  localDataTypeConversion1_c = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;

  /* SignalConversion: '<S13>/Signal Conversion1' */
  localOutDTConv_p2 = ExMGslT2_B.TmpSignalConversionAtUsThrM_p_n;

  /* If: '<S82>/If2' incorporates:
   *  ActionPort: '<S85>/Action Port'
   *  ActionPort: '<S86>/Action Port'
   *  Constant: '<S13>/ExM_rPresInit_C'
   *  Constant: '<S82>/Constant7'
   *  RelationalOperator: '<S82>/Relational Operator'
   *  SubSystem: '<S82>/If Action Subsystem2'
   *  SubSystem: '<S82>/If Action Subsystem3'
   */
  if (ExM_rPresInit_C == 0) {
    /* Constant: '<S85>/Byp_Fonction_SC' */
    locallocalDataTypeConversion1_c = MAX_uint16_T;
  } else {
    /* Product: '<S86>/Divide1' incorporates:
     *  Constant: '<S13>/Cste_92'
     *  Constant: '<S13>/ExM_rPresInit_C'
     */
    localTmpSignalConversionAtEOM_t = div_u32(67108864U, (UInt32)
      ExM_rPresInit_C);
    if (localTmpSignalConversionAtEOM_t > 65535U) {
      locallocalDataTypeConversion1_c = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion1_c = (UInt16)
        localTmpSignalConversionAtEOM_t;
    }
  }

  /* end of Outputs for SubSystem: '<S5>/F05_Pressure_initialization' */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write1' */

  /* S-Function Block: <S18>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_01_irv
    (localDataTypeConversion[0]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write10' */

  /* S-Function Block: <S18>/autosar_irv_write10 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_10_irv
    (localDataTypeConversion[9]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write11' */

  /* S-Function Block: <S18>/autosar_irv_write11 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_11_irv
    (localDataTypeConversion[10]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write12' */

  /* S-Function Block: <S18>/autosar_irv_write12 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_12_irv
    (localDataTypeConversion[11]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write2' */

  /* S-Function Block: <S18>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_02_irv
    (localDataTypeConversion[1]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write3' */

  /* S-Function Block: <S18>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_03_irv
    (localDataTypeConversion[2]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write4' */

  /* S-Function Block: <S18>/autosar_irv_write4 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_04_irv
    (localDataTypeConversion[3]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write5' */

  /* S-Function Block: <S18>/autosar_irv_write5 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_05_irv
    (localDataTypeConversion[4]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write6' */

  /* S-Function Block: <S18>/autosar_irv_write6 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_06_irv
    (localDataTypeConversion[5]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write7' */

  /* S-Function Block: <S18>/autosar_irv_write7 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_07_irv
    (localDataTypeConversion[6]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write8' */

  /* S-Function Block: <S18>/autosar_irv_write8 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_08_irv
    (localDataTypeConversion[7]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S18>/autosar_irv_write9' */

  /* S-Function Block: <S18>/autosar_irv_write9 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_pEgRaw_09_irv
    (localDataTypeConversion[8]);

  /* SignalConversion: '<S115>/copy' */
  ExM_prm_pEgRaw_01_IRV_MP = localDataTypeConversion[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S115>/autosar_testpoint1' */

  /* S-Function Block: <S115>/autosar_testpoint1 */

  /* SignalConversion: '<S116>/copy' */
  ExM_prm_pEgRaw_10_IRV_MP = localDataTypeConversion[9];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S116>/autosar_testpoint1' */

  /* S-Function Block: <S116>/autosar_testpoint1 */

  /* SignalConversion: '<S117>/copy' */
  ExM_prm_pEgRaw_11_IRV_MP = localDataTypeConversion[10];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S117>/autosar_testpoint1' */

  /* S-Function Block: <S117>/autosar_testpoint1 */

  /* SignalConversion: '<S118>/copy' */
  ExM_prm_pEgRaw_12_IRV_MP = localDataTypeConversion[11];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S118>/autosar_testpoint1' */

  /* S-Function Block: <S118>/autosar_testpoint1 */

  /* SignalConversion: '<S119>/copy' */
  ExM_prm_pEgRaw_02_IRV_MP = localDataTypeConversion[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S119>/autosar_testpoint1' */

  /* S-Function Block: <S119>/autosar_testpoint1 */

  /* SignalConversion: '<S120>/copy' */
  ExM_prm_pEgRaw_03_IRV_MP = localDataTypeConversion[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S120>/autosar_testpoint1' */

  /* S-Function Block: <S120>/autosar_testpoint1 */

  /* SignalConversion: '<S121>/copy' */
  ExM_prm_pEgRaw_04_IRV_MP = localDataTypeConversion[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S121>/autosar_testpoint1' */

  /* S-Function Block: <S121>/autosar_testpoint1 */

  /* SignalConversion: '<S122>/copy' */
  ExM_prm_pEgRaw_05_IRV_MP = localDataTypeConversion[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S122>/autosar_testpoint1' */

  /* S-Function Block: <S122>/autosar_testpoint1 */

  /* SignalConversion: '<S123>/copy' */
  ExM_prm_pEgRaw_06_IRV_MP = localDataTypeConversion[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S123>/autosar_testpoint1' */

  /* S-Function Block: <S123>/autosar_testpoint1 */

  /* SignalConversion: '<S124>/copy' */
  ExM_prm_pEgRaw_07_IRV_MP = localDataTypeConversion[6];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S124>/autosar_testpoint1' */

  /* S-Function Block: <S124>/autosar_testpoint1 */

  /* SignalConversion: '<S125>/copy' */
  ExM_prm_pEgRaw_08_IRV_MP = localDataTypeConversion[7];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S125>/autosar_testpoint1' */

  /* S-Function Block: <S125>/autosar_testpoint1 */

  /* SignalConversion: '<S126>/copy' */
  ExM_prm_pEgRaw_09_IRV_MP = localDataTypeConversion[8];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S126>/autosar_testpoint1' */

  /* S-Function Block: <S126>/autosar_testpoint1 */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Byp_Fonction_SC'
   *  Constant: '<S41>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv_p2 = ExM_pDsTrbEstimSI_B;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_pDsTrbEstimSIInport2' */
  Rte_Write_P_ExM_pDsTrbEstimSI_ExM_pDsTrbEstimSI(localOutDTConv_p2);

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Byp_Fonction_SC'
   *  Constant: '<S40>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localDataTypeConversion1_c = ExM_pExMnfEstim_B;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_pExMnfEstimInport2' */
  Rte_Write_P_ExM_pExMnfEstim_ExM_pExMnfEstim(localDataTypeConversion1_c);

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Byp_Fonction_SC'
   *  Constant: '<S37>/Int_BypC'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_fl[locali] = ExM_prm_pEgFlt_B[(locali)];
    } else {
      localSwitch_fl[locali] = localSwitch_ga[locali];
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_prm_pEgFltInport2' */
  Rte_Write_P_ExM_prm_pEgFlt_ExM_prm_pEgFlt(&localSwitch_fl);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Byp_Fonction_SC'
   *  Constant: '<S42>/Int_BypC'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_ga[locali] = ExM_prm_pEg_B[(locali)];
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_prm_pEgInport2' */
  Rte_Write_P_ExM_prm_pEg_ExM_prm_pEg(&localSwitch_ga);

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S13>/ExM_rPresInit_C'
   *  Constant: '<S31>/Byp_Fonction_SC'
   *  Constant: '<S31>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localDataTypeConversion1_c = ExM_rPresTrbEstim_B;
  } else {
    localDataTypeConversion1_c = ExM_rPresInit_C;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_rPresTrbEstimInport2' */
  Rte_Write_P_ExM_rPresTrbEstim_ExM_rPresTrbEstim(localDataTypeConversion1_c);

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Byp_Fonction_SC'
   *  Constant: '<S32>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    locallocalDataTypeConversion1_c = ExM_rPresTrbEstimIvs_B;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_rPresTrbEstimIvsInport2' */
  Rte_Write_P_ExM_rPresTrbEstimIvs_ExM_rPresTrbEstimIvs
    (locallocalDataTypeConversion1_c);

  /* DataTypeConversion: '<S5>/Data Type Conversion2' incorporates:
   *  Constant: '<S14>/ExM_mfTrbInit_C'
   */
  localDataTypeConversion2 = ((Float32)ExM_mfTrbInit_C) * 1.525878906E-005F;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write1' */

  /* S-Function Block: <S5>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_mfTrbEstimSat_irv
    (localDataTypeConversion2);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  Constant: '<S14>/ExM_mfTrbActrInit_C'
   */
  localDataTypeConversion1 = ((Float32)ExM_mfTrbActrInit_C) * 1.525878906E-005F;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write2' */

  /* S-Function Block: <S5>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_mfWgEstim_irv(localDataTypeConversion1);

  /* SignalConversion: '<S28>/copy' */
  ExM_mfTrbEstimSat_IRV_MP = localDataTypeConversion2;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S28>/autosar_testpoint1' */

  /* S-Function Block: <S28>/autosar_testpoint1 */

  /* SignalConversion: '<S29>/copy' */
  ExM_mfWgEstim_IRV_MP = localDataTypeConversion1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S29>/autosar_testpoint1' */

  /* S-Function Block: <S29>/autosar_testpoint1 */

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S14>/ExM_mfEgWoutEGRInit_C'
   *  Constant: '<S35>/Byp_Fonction_SC'
   *  Constant: '<S35>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localDataTypeConversion1_c = ExM_mfEgWoutEGR_B;
  } else {
    localDataTypeConversion1_c = ExM_mfEgWoutEGRInit_C;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_mfEgWoutEGRInport2' */
  Rte_Write_P_ExM_mfEgWoutEGR_ExM_mfEgWoutEGR(localDataTypeConversion1_c);

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S14>/ExM_mfTrbInit_C'
   *  Constant: '<S34>/Byp_Fonction_SC'
   *  Constant: '<S34>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localDataTypeConversion1_c = ExM_mfTrbEstimSat_B;
  } else {
    localDataTypeConversion1_c = ExM_mfTrbInit_C;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_mfTrbEstimSatInport2' */
  Rte_Write_P_ExM_mfTrbEstimSat_ExM_mfTrbEstimSat(localDataTypeConversion1_c);

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S14>/ExM_mfTrbActrInit_C'
   *  Constant: '<S36>/Byp_Fonction_SC'
   *  Constant: '<S36>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localDataTypeConversion1_c = ExM_mfWgEstim_B;
  } else {
    localDataTypeConversion1_c = ExM_mfTrbActrInit_C;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExM_mfWgEstimInport2' */
  Rte_Write_P_ExM_mfWgEstim_ExM_mfWgEstim(localDataTypeConversion1_c);

  /* Outputs for atomic SubSystem: '<S5>/F02_Architecture' */

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Constant: '<S10>/ExM_stElement3_C'
   */
  localTmpSignalConversionAtEOM_t = ExM_stElement3_C;

  /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
   *  Constant: '<S10>/ExM_stElement2_C'
   */
  localDataTypeConversion2_i = ExM_stElement2_C;

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/ExM_stElement4_C'
   */
  locali = ExM_stElement4_C;

  /* DataTypeConversion: '<S10>/Data Type Conversion4' incorporates:
   *  Constant: '<S10>/ExM_stElement5_C'
   */
  localPrelookup_o1 = ExM_stElement5_C;

  /* DataTypeConversion: '<S10>/Data Type Conversion5' incorporates:
   *  Constant: '<S10>/ExM_stElement6_C'
   */
  localAdd_j = ExM_stElement6_C;

  /* DataTypeConversion: '<S10>/Data Type Conversion6' incorporates:
   *  Constant: '<S10>/ExM_stElement7_C'
   */
  localAdd_g = ExM_stElement7_C;

  /* DataTypeConversion: '<S10>/Data Type Conversion7' incorporates:
   *  Constant: '<S10>/ExM_stElement8_C'
   */
  localAdd_a = ExM_stElement8_C;

  /* MinMax: '<S60>/MinMax' incorporates:
   *  Constant: '<S60>/Constant'
   */
  localDataTypeConversion3 = (SInt32)rt_MIN((UInt32)locali, 3U);

  /* SignalConversion: '<S67>/TmpSignal ConversionAtAssignmentInport1' incorporates:
   *  Constant: '<S10>/Cste_66'
   *  Constant: '<S10>/Cste_67'
   *  Constant: '<S10>/Cste_68'
   *  Constant: '<S10>/Cste_69'
   */
  localAssignment[0] = 0U;
  localAssignment[1] = 0U;
  localAssignment[2] = 0U;
  localAssignment[3] = 0U;

  /* Sum: '<S67>/Add' incorporates:
   *  Constant: '<S10>/Cste_80'
   *  Constant: '<S10>/ExM_stElement1_C'
   *  Constant: '<S67>/Constant1'
   *  Sum: '<S10>/Sum5'
   */
  locali = ExM_stElement1_C;

  /* Assignment: '<S67>/Assignment' incorporates:
   *  Constant: '<S10>/Cste_74'
   *  Constant: '<S67>/Constant'
   *  MinMax: '<S67>/MinMax'
   */
  localAssignment[(SInt32)rt_MIN((UInt32)locali, 3U)] = 1U;

  /* Sum: '<S10>/Sum4' incorporates:
   *  Constant: '<S10>/Cste_81'
   *  Constant: '<S65>/Constant'
   *  MinMax: '<S65>/MinMax'
   *  Selector: '<S65>/Selector'
   */
  localSum4 = (UInt8)(localAssignment[(SInt32)rt_MIN((UInt32)
    localDataTypeConversion2_i, 3U)] + 1);

  /* Sum: '<S68>/Add' incorporates:
   *  Constant: '<S10>/Cste_82'
   *  Constant: '<S10>/ExM_stElement2_C'
   *  Constant: '<S68>/Constant1'
   *  Sum: '<S10>/Sum6'
   */
  locali = ExM_stElement2_C;

  /* Assignment: '<S68>/Assignment' incorporates:
   *  Constant: '<S68>/Constant'
   *  MinMax: '<S68>/MinMax'
   */
  localAssignment[(SInt32)rt_MIN((UInt32)locali, 3U)] = localSum4;

  /* Sum: '<S10>/Sum1' incorporates:
   *  Constant: '<S10>/Cste_73'
   *  Constant: '<S66>/Constant'
   *  MinMax: '<S66>/MinMax'
   *  Selector: '<S66>/Selector'
   */
  locali = localAssignment[(SInt32)rt_MIN(localTmpSignalConversionAtEOM_t, 3U)]
    + 1;
  if (((UInt32)locali) > 255U) {
    localSum1_o = MAX_uint8_T;
  } else {
    localSum1_o = (UInt8)locali;
  }

  /* Sum: '<S69>/Add' incorporates:
   *  Constant: '<S10>/Cste_83'
   *  Constant: '<S10>/ExM_stElement3_C'
   *  Constant: '<S69>/Constant1'
   *  Sum: '<S10>/Sum7'
   */
  locali = ExM_stElement3_C;

  /* Assignment: '<S69>/Assignment' incorporates:
   *  Constant: '<S69>/Constant'
   *  MinMax: '<S69>/MinMax'
   */
  localAssignment[(SInt32)rt_MIN((UInt32)locali, 3U)] = localSum1_o;

  /* MinMax: '<S61>/MinMax' incorporates:
   *  Constant: '<S61>/Constant'
   */
  localDataTypeConversion2_i = (SInt32)rt_MIN((UInt32)localPrelookup_o1, 3U);

  /* Sum: '<S10>/Sum2' incorporates:
   *  Constant: '<S10>/Cste_75'
   *  Selector: '<S60>/Selector'
   */
  locali = localAssignment[localDataTypeConversion3] + 1;
  if (((UInt32)locali) > 255U) {
    localSum2_a = MAX_uint8_T;
  } else {
    localSum2_a = (UInt8)locali;
  }

  /* Sum: '<S70>/Add' incorporates:
   *  Constant: '<S10>/Cste_84'
   *  Constant: '<S10>/ExM_stElement4_C'
   *  Constant: '<S70>/Constant1'
   *  Sum: '<S10>/Sum8'
   */
  localPrelookup_o1 = ExM_stElement4_C;

  /* Assignment: '<S70>/Assignment' incorporates:
   *  Constant: '<S70>/Constant'
   *  MinMax: '<S70>/MinMax'
   */
  localAssignment[(SInt32)rt_MIN((UInt32)localPrelookup_o1, 3U)] =
    localSum2_a;

  /* MinMax: '<S62>/MinMax' incorporates:
   *  Constant: '<S62>/Constant'
   */
  localTmpSignalConversionAtEOM_t = rt_MIN((UInt32)localAdd_j, 3U);

  /* Sum: '<S10>/Sum11' incorporates:
   *  Constant: '<S10>/Cste_76'
   *  Selector: '<S61>/Selector'
   */
  locali = localAssignment[localDataTypeConversion2_i] + 1;
  if (((UInt32)locali) > 255U) {
    localSum11 = MAX_uint8_T;
  } else {
    localSum11 = (UInt8)locali;
  }

  /* Sum: '<S71>/Add' incorporates:
   *  Constant: '<S10>/Cste_85'
   *  Constant: '<S10>/ExM_stElement5_C'
   *  Constant: '<S71>/Constant1'
   *  Sum: '<S10>/Sum9'
   */
  localAdd_j = ExM_stElement5_C;

  /* Assignment: '<S71>/Assignment' incorporates:
   *  Constant: '<S71>/Constant'
   *  MinMax: '<S71>/MinMax'
   */
  localAssignment[(SInt32)rt_MIN((UInt32)localAdd_j, 3U)] = localSum11;

  /* MinMax: '<S63>/MinMax' incorporates:
   *  Constant: '<S63>/Constant'
   */
  localDataTypeConversion2_i = (SInt32)rt_MIN((UInt32)localAdd_g, 3U);

  /* Sum: '<S10>/Sum12' incorporates:
   *  Constant: '<S10>/Cste_77'
   *  Selector: '<S62>/Selector'
   */
  locali = localAssignment[(SInt32)localTmpSignalConversionAtEOM_t] + 1;
  if (((UInt32)locali) > 255U) {
    localSum12 = MAX_uint8_T;
  } else {
    localSum12 = (UInt8)locali;
  }

  /* Sum: '<S72>/Add' incorporates:
   *  Constant: '<S10>/Cste_71'
   *  Constant: '<S10>/ExM_stElement6_C'
   *  Constant: '<S72>/Constant1'
   *  Sum: '<S10>/Sum10'
   */
  localAdd_g = ExM_stElement6_C;

  /* Assignment: '<S72>/Assignment' incorporates:
   *  Constant: '<S72>/Constant'
   *  MinMax: '<S72>/MinMax'
   */
  localAssignment[(SInt32)rt_MIN((UInt32)localAdd_g, 3U)] = localSum12;

  /* MinMax: '<S64>/MinMax' incorporates:
   *  Constant: '<S64>/Constant'
   */
  localTmpSignalConversionAtEOM_t = rt_MIN((UInt32)localAdd_a, 3U);

  /* Sum: '<S10>/Sum13' incorporates:
   *  Constant: '<S10>/Cste_78'
   *  Selector: '<S63>/Selector'
   */
  locali = localAssignment[localDataTypeConversion2_i] + 1;
  if (((UInt32)locali) > 255U) {
    localSum13 = MAX_uint8_T;
  } else {
    localSum13 = (UInt8)locali;
  }

  /* Sum: '<S73>/Add' incorporates:
   *  Constant: '<S10>/Cste_72'
   *  Constant: '<S10>/ExM_stElement7_C'
   *  Constant: '<S73>/Constant1'
   *  Sum: '<S10>/Sum15'
   */
  localAdd_a = ExM_stElement7_C;

  /* Assignment: '<S73>/Assignment' incorporates:
   *  Constant: '<S73>/Constant'
   *  MinMax: '<S73>/MinMax'
   */
  localAssignment[(SInt32)rt_MIN((UInt32)localAdd_a, 3U)] = localSum13;

  /* Sum: '<S10>/Sum14' incorporates:
   *  Constant: '<S10>/Cste_79'
   *  Selector: '<S64>/Selector'
   */
  locali = localAssignment[(SInt32)localTmpSignalConversionAtEOM_t] + 1;
  if (((UInt32)locali) > 255U) {
    localSum14 = MAX_uint8_T;
  } else {
    localSum14 = (UInt8)locali;
  }

  /* end of Outputs for SubSystem: '<S5>/F02_Architecture' */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write1' incorporates:
   *  Constant: '<S10>/ExM_stElement1_C'
   */

  /* S-Function Block: <S15>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stElement_01_irv(ExM_stElement1_C);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write2' incorporates:
   *  Constant: '<S10>/ExM_stElement2_C'
   */

  /* S-Function Block: <S15>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stElement_02_irv(ExM_stElement2_C);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write3' incorporates:
   *  Constant: '<S10>/ExM_stElement3_C'
   */

  /* S-Function Block: <S15>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stElement_03_irv(ExM_stElement3_C);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write4' incorporates:
   *  Constant: '<S10>/ExM_stElement4_C'
   */

  /* S-Function Block: <S15>/autosar_irv_write4 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stElement_04_irv(ExM_stElement4_C);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write5' incorporates:
   *  Constant: '<S10>/ExM_stElement5_C'
   */

  /* S-Function Block: <S15>/autosar_irv_write5 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stElement_05_irv(ExM_stElement5_C);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write6' incorporates:
   *  Constant: '<S10>/ExM_stElement6_C'
   */

  /* S-Function Block: <S15>/autosar_irv_write6 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stElement_06_irv(ExM_stElement6_C);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write7' incorporates:
   *  Constant: '<S10>/ExM_stElement7_C'
   */

  /* S-Function Block: <S15>/autosar_irv_write7 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stElement_07_irv(ExM_stElement7_C);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write8' incorporates:
   *  Constant: '<S10>/ExM_stElement8_C'
   */

  /* S-Function Block: <S15>/autosar_irv_write8 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stElement_08_irv(ExM_stElement8_C);

  /* SignalConversion: '<S87>/copy' incorporates:
   *  Constant: '<S10>/ExM_stElement1_C'
   */
  ExM_prm_stElement_01_IRV_MP = ExM_stElement1_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S87>/autosar_testpoint1' */

  /* S-Function Block: <S87>/autosar_testpoint1 */

  /* SignalConversion: '<S88>/copy' incorporates:
   *  Constant: '<S10>/ExM_stElement2_C'
   */
  ExM_prm_stElement_02_IRV_MP = ExM_stElement2_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S88>/autosar_testpoint1' */

  /* S-Function Block: <S88>/autosar_testpoint1 */

  /* SignalConversion: '<S89>/copy' incorporates:
   *  Constant: '<S10>/ExM_stElement3_C'
   */
  ExM_prm_stElement_03_IRV_MP = ExM_stElement3_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S89>/autosar_testpoint1' */

  /* S-Function Block: <S89>/autosar_testpoint1 */

  /* SignalConversion: '<S90>/copy' incorporates:
   *  Constant: '<S10>/ExM_stElement4_C'
   */
  ExM_prm_stElement_04_IRV_MP = ExM_stElement4_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S90>/autosar_testpoint1' */

  /* S-Function Block: <S90>/autosar_testpoint1 */

  /* SignalConversion: '<S91>/copy' incorporates:
   *  Constant: '<S10>/ExM_stElement5_C'
   */
  ExM_prm_stElement_05_IRV_MP = ExM_stElement5_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S91>/autosar_testpoint1' */

  /* S-Function Block: <S91>/autosar_testpoint1 */

  /* SignalConversion: '<S92>/copy' incorporates:
   *  Constant: '<S10>/ExM_stElement6_C'
   */
  ExM_prm_stElement_06_IRV_MP = ExM_stElement6_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S92>/autosar_testpoint1' */

  /* S-Function Block: <S92>/autosar_testpoint1 */

  /* SignalConversion: '<S93>/copy' incorporates:
   *  Constant: '<S10>/ExM_stElement7_C'
   */
  ExM_prm_stElement_07_IRV_MP = ExM_stElement7_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S93>/autosar_testpoint1' */

  /* S-Function Block: <S93>/autosar_testpoint1 */

  /* SignalConversion: '<S94>/copy' incorporates:
   *  Constant: '<S10>/ExM_stElement8_C'
   */
  ExM_prm_stElement_08_IRV_MP = ExM_stElement8_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S94>/autosar_testpoint1' */

  /* S-Function Block: <S94>/autosar_testpoint1 */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_write1' incorporates:
   *  Constant: '<S10>/Cste_70'
   */

  /* S-Function Block: <S16>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stNbTypElement_01_irv(((UInt8)1U));

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_write2' */

  /* S-Function Block: <S16>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stNbTypElement_02_irv(localSum4);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_write3' */

  /* S-Function Block: <S16>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stNbTypElement_03_irv(localSum1_o);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_write4' */

  /* S-Function Block: <S16>/autosar_irv_write4 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stNbTypElement_04_irv(localSum2_a);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_write5' */

  /* S-Function Block: <S16>/autosar_irv_write5 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stNbTypElement_05_irv(localSum11);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_write6' */

  /* S-Function Block: <S16>/autosar_irv_write6 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stNbTypElement_06_irv(localSum12);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_write7' */

  /* S-Function Block: <S16>/autosar_irv_write7 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stNbTypElement_07_irv(localSum13);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_write8' */

  /* S-Function Block: <S16>/autosar_irv_write8 */
  Rte_IrvWrite_RE_ExMGslT2_001_MSE_ExM_prm_stNbTypElement_08_irv(localSum14);

  /* SignalConversion: '<S95>/copy' incorporates:
   *  Constant: '<S10>/Cste_70'
   */
  ExM_prm_stNbTypElement_01_IRV_MP = 1U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S95>/autosar_testpoint1' */

  /* S-Function Block: <S95>/autosar_testpoint1 */

  /* SignalConversion: '<S96>/copy' */
  ExM_prm_stNbTypElement_02_IRV_MP = localSum4;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S96>/autosar_testpoint1' */

  /* S-Function Block: <S96>/autosar_testpoint1 */

  /* SignalConversion: '<S97>/copy' */
  ExM_prm_stNbTypElement_03_IRV_MP = localSum1_o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S97>/autosar_testpoint1' */

  /* S-Function Block: <S97>/autosar_testpoint1 */

  /* SignalConversion: '<S98>/copy' */
  ExM_prm_stNbTypElement_04_IRV_MP = localSum2_a;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S98>/autosar_testpoint1' */

  /* S-Function Block: <S98>/autosar_testpoint1 */

  /* SignalConversion: '<S99>/copy' */
  ExM_prm_stNbTypElement_05_IRV_MP = localSum11;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S99>/autosar_testpoint1' */

  /* S-Function Block: <S99>/autosar_testpoint1 */

  /* SignalConversion: '<S100>/copy' */
  ExM_prm_stNbTypElement_06_IRV_MP = localSum12;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S100>/autosar_testpoint1' */

  /* S-Function Block: <S100>/autosar_testpoint1 */

  /* SignalConversion: '<S101>/copy' */
  ExM_prm_stNbTypElement_07_IRV_MP = localSum13;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S101>/autosar_testpoint1' */

  /* S-Function Block: <S101>/autosar_testpoint1 */

  /* SignalConversion: '<S102>/copy' */
  ExM_prm_stNbTypElement_08_IRV_MP = localSum14;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S102>/autosar_testpoint1' */

  /* S-Function Block: <S102>/autosar_testpoint1 */
}

/* Output and update for function-call system: '<S6>/LibP' */
void ExMGslT2_LibP(const UInt8 *rtu_ExM_noIdxPresPrev, const Float32
                   rtu_ExM_prm_pEgInterPrev[12], const Float32 *rtu_ExM_pDsBs,
                   Boolean rtu_FRM_bSenPres, UInt8 rtu_ExM_prm_stElement,
                   UInt8 rtu_ExM_prm_stElement_d, UInt8
                   rtu_ExM_prm_stElement_j, UInt8 rtu_ExM_prm_stElement_a,
                   UInt8 rtu_ExM_prm_stElement_i, UInt8
                   rtu_ExM_prm_stElement_e, UInt8 rtu_ExM_prm_stElement_g,
                   UInt8 rtu_ExM_prm_stElement_h, UInt8
                   rtu_ExM_prm_stNbTypElement, UInt8
                   rtu_ExM_prm_stNbTypElement_m, UInt8
                   rtu_ExM_prm_stNbTypElement_b, UInt8
                   rtu_ExM_prm_stNbTypElement_h, UInt8
                   rtu_ExM_prm_stNbTypElement_ho, UInt8
                   rtu_ExM_prm_stNbTypElement_f, UInt8
                   rtu_ExM_prm_stNbTypElement_a, UInt8
                   rtu_ExM_prm_stNbTypElement_ao, Float32 rtu_ExM_prm_tEgPrev,
                   Float32 rtu_ExM_prm_tEgPrev_j, Float32
                   rtu_ExM_prm_tEgPrev_a, Float32 rtu_ExM_prm_tEgPrev_k,
                   Float32 rtu_ExM_prm_tEgPrev_i, Float32
                   rtu_ExM_prm_tEgPrev_h, Float32 rtu_ExM_prm_tEgPrev_k0,
                   Float32 rtu_ExM_prm_tEgPrev_aa, Float32
                   rtu_ExM_prm_tEgPrev_m, Float32 rtu_ExM_prm_tEgPrev_l,
                   Float32 rtu_ExM_prm_tEgPrev_d, Float32
                   rtu_ExM_prm_tEgPrev_b, UInt16 rtu_ExM_mfEgWoutEGR, UInt16
                   rtu_UsThrM_pAirExt, Boolean rtu_FRM_bTrbAct, UInt16
                   rtu_TrbAct_rOpTrbAct, UInt16 rtu_Ext_nEng, SInt16
                   rtu_EngM_agCkOpInVlvEstimRef1, SInt16
                   rtu_EngM_agCkClsExVlvEstimRef1, UInt16 rtu_ExM_pMes,
                   Float32 rtu_ExM_mfWgEstim_irv, Float32
                   rtu_ExM_mfTrbEstimSat_irv, const Float32
                   rtu_ExM_prm_pEgPrev[12], Float32 *rty_ExM_pUs, UInt8
                   *rty_ExM_noIdxPres, Float32 rty_ExM_prm_pEgInter[12],
                   rtB_LibP_ExMGslT2 *localB, rtDW_LibP_ExMGslT2 *localDW)
{
  Boolean localLogicalOperator1;
  UInt32 localDataTypeConversion4_p3;
  Float32 localTmpSignalConversionAtSelec[12];
  Float32 localDataTypeConversion3_n;
  Boolean localLogicalOperator1_l;
  Float32 localDataTypeConversion1_k;
  Float32 localDivide_mm;
  Float32 localDataTypeConversion2_d;
  Float32 localPrelookup_o2_g;
  Float32 localfractionTmp_0d;
  Float32 localPrelookup_o2_a;
  Float32 localSwitch1_b;
  Float32 localInterpolationUsingPrelo_nv;
  Float32 localPrelookup_o2_p;
  SInt32 localPrelookup_o1_e;
  Float32 localPrelookup_o2_e;
  Float32 localfrac[2];
  Float32 localPrelookup_o2_d;
  SInt32 localPrelookup_o1_a;
  SInt32 localbpIndex[2];
  SInt32 localPrelookup_o1_g;
  Float32 localInterpolationUsingPreloo_o;
  Float32 localfrac_0[2];
  SInt32 localbpIndex_0[2];
  Float32 localSwitch2_g;
  Float32 localPrelookup_o2_l;
  Float32 localInterpolationUsingPreloo_n;
  Float32 localfrac_1[2];
  Float32 localPrelookup_o2_kx;
  SInt32 localbpIndex_1[2];
  Float32 localPrelookup1_o2_g;
  Float32 localfrac_2[2];
  Float32 localPrelookup1_o2;
  SInt32 localbpIndex_2[2];
  Float32 localfrac_3[2];
  SInt32 localbpIndex_3[2];
  Float32 localfrac_4[2];
  SInt32 localbpIndex_4[2];
  Float32 localfrac_5[2];
  SInt32 localbpIndex_5[2];
  Float32 localfrac_6[2];
  SInt32 localbpIndex_6[2];
  Float32 localfrac_7[2];
  SInt32 localbpIndex_7[2];
  Float32 localfrac_8[2];
  SInt32 localbpIndex_8[2];
  Float32 localfrac_9[2];
  SInt32 localbpIndex_9[2];
  Float32 localfrac_a[2];
  SInt32 localbpIndex_a[2];
  Float32 localInterpolationUsingPrelo_j1;
  Float32 localInterpolationUsingPreloo_l;
  Float32 localPrelookup_o2_h;
  Float32 localPrelookup_o2_c;
  SInt32 locali;
  UInt8 localtmp[8];
  Float32 localtmp_0;
  UInt16 locallocalOutDTConv_nj;
  UInt32 localqY;
  UInt8 locallocalDataTypeConversion1_m;

  /* SignalConversion: '<S138>/Signal Conversion' */
  ExM_noIdxPresPrev = (*rtu_ExM_noIdxPresPrev);

  /* SignalConversion: '<S138>/Signal Conversion4' */
  for (locali = 0; locali < 12; locali++) {
    ExM_prm_pEgInterPrev[(locali)] = rtu_ExM_prm_pEgInterPrev[(locali)];
  }

  /* Outputs for atomic SubSystem: '<S138>/F01_Element_input_conditions_for_pressure_models' */

  /* DataTypeConversion: '<S185>/Data Type Conversion4' */
  localDataTypeConversion4_p3 = ExM_noIdxPresPrev;

  /* Sum: '<S185>/Sum' incorporates:
   *  Constant: '<S185>/Cste_4'
   */
  locali = (SInt32)localDataTypeConversion4_p3;
  localqY = ((UInt32)locali) - 1U;
  if (localqY > ((UInt32)locali)) {
    localqY = 0U;
  }

  locali = (SInt32)localqY;

  /* DataTypeConversion: '<S185>/Data Type Conversion1' */
  locallocalDataTypeConversion1_m = (UInt8)locali;

  /* Selector: '<S191>/Selector' incorporates:
   *  Constant: '<S191>/Constant'
   *  MinMax: '<S191>/MinMax'
   *  SignalConversion: '<S191>/TmpSignal ConversionAtSelectorInport1'
   */
  localtmp[0] = rtu_ExM_prm_stElement;
  localtmp[1] = rtu_ExM_prm_stElement_d;
  localtmp[2] = rtu_ExM_prm_stElement_j;
  localtmp[3] = rtu_ExM_prm_stElement_a;
  localtmp[4] = rtu_ExM_prm_stElement_i;
  localtmp[5] = rtu_ExM_prm_stElement_e;
  localtmp[6] = rtu_ExM_prm_stElement_g;
  localtmp[7] = rtu_ExM_prm_stElement_h;
  ExM_stElementPres = localtmp[(SInt32)rt_MIN((UInt32)locali, 7U)];

  /* Selector: '<S192>/Selector' incorporates:
   *  Constant: '<S192>/Constant'
   *  MinMax: '<S192>/MinMax'
   *  SignalConversion: '<S192>/TmpSignal ConversionAtSelectorInport1'
   */
  localtmp[0] = rtu_ExM_prm_stNbTypElement;
  localtmp[1] = rtu_ExM_prm_stNbTypElement_m;
  localtmp[2] = rtu_ExM_prm_stNbTypElement_b;
  localtmp[3] = rtu_ExM_prm_stNbTypElement_h;
  localtmp[4] = rtu_ExM_prm_stNbTypElement_ho;
  localtmp[5] = rtu_ExM_prm_stNbTypElement_f;
  localtmp[6] = rtu_ExM_prm_stNbTypElement_a;
  localtmp[7] = rtu_ExM_prm_stNbTypElement_ao;
  ExM_stNbTypElementPres = localtmp[(SInt32)rt_MIN((UInt32)locali, 7U)];

  /* Selector: '<S193>/Selector' incorporates:
   *  Constant: '<S193>/Constant'
   *  MinMax: '<S193>/MinMax'
   */
  ExM_pUsPrev = ExM_prm_pEgInterPrev[rt_MIN(locali, 11U)];

  /* SignalConversion: '<S194>/TmpSignal ConversionAtSelectorInport1' */
  localTmpSignalConversionAtSelec[0] = rtu_ExM_prm_tEgPrev;
  localTmpSignalConversionAtSelec[1] = rtu_ExM_prm_tEgPrev_j;
  localTmpSignalConversionAtSelec[2] = rtu_ExM_prm_tEgPrev_a;
  localTmpSignalConversionAtSelec[3] = rtu_ExM_prm_tEgPrev_k;
  localTmpSignalConversionAtSelec[4] = rtu_ExM_prm_tEgPrev_i;
  localTmpSignalConversionAtSelec[5] = rtu_ExM_prm_tEgPrev_h;
  localTmpSignalConversionAtSelec[6] = rtu_ExM_prm_tEgPrev_k0;
  localTmpSignalConversionAtSelec[7] = rtu_ExM_prm_tEgPrev_aa;
  localTmpSignalConversionAtSelec[8] = rtu_ExM_prm_tEgPrev_m;
  localTmpSignalConversionAtSelec[9] = rtu_ExM_prm_tEgPrev_l;
  localTmpSignalConversionAtSelec[10] = rtu_ExM_prm_tEgPrev_d;
  localTmpSignalConversionAtSelec[11] = rtu_ExM_prm_tEgPrev_b;

  /* Selector: '<S194>/Selector' incorporates:
   *  Constant: '<S194>/Constant'
   *  MinMax: '<S194>/MinMax'
   */
  ExM_tUs = localTmpSignalConversionAtSelec[(SInt32)rt_MIN((UInt32)locali,
    11U)];

  /* Selector: '<S195>/Selector' incorporates:
   *  Constant: '<S195>/Constant'
   *  MinMax: '<S195>/MinMax'
   */
  ExM_tDsPrev = localTmpSignalConversionAtSelec[(SInt32)rt_MIN
    (localDataTypeConversion4_p3, 11U)];

  /* SignalConversion: '<S185>/Signal Conversion1' */
  ExM_tUsPrev = ExM_tUs;

  /* end of Outputs for SubSystem: '<S138>/F01_Element_input_conditions_for_pressure_models' */

  /* SignalConversion: '<S138>/Signal Conversion3' */
  ExM_pDsBs = (*rtu_ExM_pDsBs);

  /* If: '<S138>/If' incorporates:
   *  ActionPort: '<S186>/Action Port'
   *  ActionPort: '<S187>/Action Port'
   *  Constant: '<S138>/ExM_bCalcPresRvs_C'
   *  SubSystem: '<S138>/F02_Indirect_calculation_sense'
   *  SubSystem: '<S138>/F03_Direct_calculation_sense'
   */
  if (ExM_bCalcPresRvs_C) {
    /* DataTypeConversion: '<S186>/Data Type Conversion2' */
    localDataTypeConversion4_p3 = ExM_noIdxPresPrev;

    /* Selector: '<S196>/Selector' incorporates:
     *  Constant: '<S196>/Constant'
     *  MinMax: '<S196>/MinMax'
     */
    ExM_pDs = rtu_ExM_prm_pEgPrev[rt_MIN(localDataTypeConversion4_p3, 11U)];
  } else {
    /* Inport: '<S187>/ExM_pDsBs' */
    ExM_pDs = ExM_pDsBs;
  }

  /* Outputs for enable SubSystem: '<S138>/F04_Pressure_models' incorporates:
   *  Constant: '<S138>/ExM_noPresSenPres_C'
   *  EnablePort: '<S188>/Enable'
   *  EnablePort: '<S189>/Enable'
   *  Logic: '<S138>/Logical Operator'
   *  Logic: '<S138>/Logical Operator1'
   *  Logic: '<S138>/Logical Operator2'
   *  RelationalOperator: '<S138>/Relational Operator'
   *  SubSystem: '<S138>/F05_Pressure_measures'
   */
  if (!((ExM_noIdxPresPrev == ExM_noPresSenPres_C) && (!rtu_FRM_bSenPres))) {
    /* SwitchCase: '<S188>/Switch Case' incorporates:
     *  ActionPort: '<S197>/ExM_Sdl_OxCatPres'
     *  ActionPort: '<S198>/ExM_Sdl_PipePres'
     *  ActionPort: '<S199>/ExM_Sdl_TrbPres'
     *  ActionPort: '<S200>/ExM_Sdl_VoidPres'
     *  SubSystem: '<S188>/OxCatMdlP'
     *  SubSystem: '<S188>/PipeMdlP'
     *  SubSystem: '<S188>/TrbMdlP'
     *  SubSystem: '<S188>/VoidMdlP'
     */
    switch (ExM_stElementPres) {
     case 1:
      /* Outputs for atomic SubSystem: '<S198>/F01_Pipe_thermal_model_parameters' */

      /* DataTypeConversion: '<S236>/OutDTConv' incorporates:
       *  Constant: '<S236>/offset'
       *  Constant: '<S236>/one_on_slope'
       *  Product: '<S236>/Product4'
       *  Sum: '<S236>/Add1'
       */
      localtmp_0 = (ExM_tUs - 223.0F) * 32.0F;
      if (localtmp_0 < 65536.0F) {
        if (localtmp_0 >= 0.0F) {
          locallocalOutDTConv_nj = (UInt16)localtmp_0;
        } else {
          locallocalOutDTConv_nj = 0U;
        }
      } else {
        locallocalOutDTConv_nj = MAX_uint16_T;
      }

      /* PreLookup: '<S234>/Prelookup' */
      localDataTypeConversion4_p3 = plook_u32u16f_bincpa(locallocalOutDTConv_nj,
        (&(ExM_tUsPipe_A[0])), 13U, &localPrelookup_o2_a,
        &localDW->Prelookup_DWORK1_ly);

      /* PreLookup: '<S235>/Prelookup' */
      locali = plook_s32u16f_bincpa(rtu_ExM_mfEgWoutEGR, (&(ExM_mfEg_A[0])), 15U,
        &localPrelookup_o2_g, &localDW->Prelookup_DWORK1_k);

      /* SwitchCase: '<S227>/Switch Case' incorporates:
       *  ActionPort: '<S230>/Action Port'
       *  ActionPort: '<S231>/Action Port'
       *  ActionPort: '<S232>/Action Port'
       *  ActionPort: '<S233>/Action Port'
       *  SubSystem: '<S227>/F02_Pipe1_parameters_of_thermal_model'
       *  SubSystem: '<S227>/F03_Pipe2_parameters_of_thermal_model'
       *  SubSystem: '<S227>/F04_Pipe3_parameters_of_thermal_model'
       *  SubSystem: '<S227>/F05_Pipe4_parameters_of_thermal_model'
       */
      switch (ExM_stNbTypElementPres) {
       case 1:
        /* Interpolation_n-D: '<S237>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_g;
        ExM_facPresLossPipeCal1 = intrp1d_iu16n16ff_s32f_la_n(locali,
          localfractionTmp_0d, (&(ExM_facPresLossPipe1_T[0])), 15U);

        /* SignalConversion: '<S230>/Signal Conversion' */
        ExM_facPresLossPipeCal = ExM_facPresLossPipeCal1;

        /* Interpolation_n-D: '<S238>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_a;
        ExM_facTPresLossPipeCal1 = intrp1d_iu16n14ff_u32f_la_n
          (localDataTypeConversion4_p3, localfractionTmp_0d,
           (&(ExM_facTPresLossPipe1_T[0])), 13U);

        /* SignalConversion: '<S230>/Signal Conversion1' */
        ExM_facTPresLossPipeCal = ExM_facTPresLossPipeCal1;
        break;

       case 2:
        /* Interpolation_n-D: '<S239>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_g;
        ExM_facPresLossPipeCal2 = intrp1d_iu16n16ff_s32f_la_n(locali,
          localfractionTmp_0d, (&(ExM_facPresLossPipe2_T[0])), 15U);

        /* SignalConversion: '<S231>/Signal Conversion' */
        ExM_facPresLossPipeCal = ExM_facPresLossPipeCal2;

        /* Interpolation_n-D: '<S240>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_a;
        ExM_facTPresLossPipeCal2 = intrp1d_iu16n14ff_u32f_la_n
          (localDataTypeConversion4_p3, localfractionTmp_0d,
           (&(ExM_facTPresLossPipe2_T[0])), 13U);

        /* SignalConversion: '<S231>/Signal Conversion1' */
        ExM_facTPresLossPipeCal = ExM_facTPresLossPipeCal2;
        break;

       case 3:
        /* Interpolation_n-D: '<S241>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_g;
        ExM_facPresLossPipeCal3 = intrp1d_iu16n16ff_s32f_la_n(locali,
          localfractionTmp_0d, (&(ExM_facPresLossPipe3_T[0])), 15U);

        /* SignalConversion: '<S232>/Signal Conversion' */
        ExM_facPresLossPipeCal = ExM_facPresLossPipeCal3;

        /* Interpolation_n-D: '<S242>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_a;
        ExM_facTPresLossPipeCal3 = intrp1d_iu16n14ff_u32f_la_n
          (localDataTypeConversion4_p3, localfractionTmp_0d,
           (&(ExM_facTPresLossPipe3_T[0])), 13U);

        /* SignalConversion: '<S232>/Signal Conversion1' */
        ExM_facTPresLossPipeCal = ExM_facTPresLossPipeCal3;
        break;

       case 4:
        /* Interpolation_n-D: '<S243>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_g;
        ExM_facPresLossPipeCal4 = intrp1d_iu16n16ff_s32f_la_n(locali,
          localfractionTmp_0d, (&(ExM_facPresLossPipe4_T[0])), 15U);

        /* SignalConversion: '<S233>/Signal Conversion' */
        ExM_facPresLossPipeCal = ExM_facPresLossPipeCal4;

        /* Interpolation_n-D: '<S244>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_a;
        ExM_facTPresLossPipeCal4 = intrp1d_iu16n14ff_u32f_la_n
          (localDataTypeConversion4_p3, localfractionTmp_0d,
           (&(ExM_facTPresLossPipe4_T[0])), 13U);

        /* SignalConversion: '<S233>/Signal Conversion1' */
        ExM_facTPresLossPipeCal = ExM_facTPresLossPipeCal4;
        break;
      }

      /* end of Outputs for SubSystem: '<S198>/F01_Pipe_thermal_model_parameters' */

      /* Outputs for atomic SubSystem: '<S198>/F02_Pipe_upstream_pressure' */

      /* DataTypeConversion: '<S228>/Data Type Conversion1' incorporates:
       *  Constant: '<S228>/AirEfc_pRef_C'
       */
      localDataTypeConversion1_k = ((Float32)AirEfc_pRef_C) * 8.0F;

      /* Product: '<S248>/Divide' */
      localDivide_mm = ExM_pDs / localDataTypeConversion1_k;

      /* Product: '<S249>/Divide' */
      localfractionTmp_0d = localDivide_mm * localDivide_mm;

      /* Product: '<S247>/Product4' incorporates:
       *  Constant: '<S228>/AirEfc_tRef_C'
       *  Constant: '<S247>/offset'
       *  Constant: '<S247>/one_on_slope'
       *  DataTypeConversion: '<S228>/Data Type Conversion2'
       *  Product: '<S250>/Divide'
       *  Product: '<S251>/Divide'
       *  Sum: '<S228>/Add'
       *  Sum: '<S247>/Add1'
       */
      localDivide_mm = ((((((Float32)AirEfc_tRef_C) * 0.0078125F) *
                          (ExM_facPresLossPipeCal * ExM_facTPresLossPipeCal)) +
                         localfractionTmp_0d) - 3.600000143E-001F) *
        6.798340332E+003F;

      /* DataTypeConversion: '<S247>/OutDTConv' */
      localtmp_0 = localDivide_mm;
      if (localtmp_0 < 65536.0F) {
        if (localtmp_0 >= 0.0F) {
          locallocalOutDTConv_nj = (UInt16)localtmp_0;
        } else {
          locallocalOutDTConv_nj = 0U;
        }
      } else {
        locallocalOutDTConv_nj = MAX_uint16_T;
      }

      /* PreLookup: '<S246>/Prelookup' */
      localDataTypeConversion4_p3 = plook_u32u16f_bincpa(locallocalOutDTConv_nj,
        (&(ExM_facPresUsPipeSq_A[0])), 23U, &localDivide_mm,
        &localDW->Prelookup_DWORK1_e);

      /* Interpolation_n-D: '<S245>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localDivide_mm;
      localDivide_mm = intrp1d_iu16n15ff_u32f_la_n(localDataTypeConversion4_p3,
        localfractionTmp_0d, (&(ExM_facPresUsPipe_T[0])), 23U);

      /* Product: '<S252>/Divide' */
      localDivide_mm *= localDataTypeConversion1_k;

      /* MinMax: '<S228>/x' */
      ExM_pPipeUs = rt_MAXf(ExM_pDs, localDivide_mm);

      /* SignalConversion: '<S228>/Signal Conversion' */
      localB->Merge4 = ExM_pPipeUs;

      /* end of Outputs for SubSystem: '<S198>/F02_Pipe_upstream_pressure' */
      break;

     case 2:
      /* DataTypeConversion: '<S199>/Data Type Conversion3' */
      localDataTypeConversion3_n = ((Float32)rtu_UsThrM_pAirExt) * 8.0F;

      /* Outputs for atomic SubSystem: '<S199>/F01_MAP_index_of_turbine_thermal_model' */

      /* DataTypeConversion: '<S259>/OutDTConv' incorporates:
       *  Constant: '<S259>/offset'
       *  Constant: '<S259>/one_on_slope'
       *  Product: '<S259>/Product4'
       *  Sum: '<S259>/Add1'
       */
      localtmp_0 = 32.0F * ExM_tUs;
      if (localtmp_0 < 65536.0F) {
        if (localtmp_0 >= 0.0F) {
          locallocalOutDTConv_nj = (UInt16)localtmp_0;
        } else {
          locallocalOutDTConv_nj = 0U;
        }
      } else {
        locallocalOutDTConv_nj = MAX_uint16_T;
      }

      /* PreLookup: '<S256>/Prelookup' */
      localPrelookup_o1_e = plook_s32u16f_bincpa(locallocalOutDTConv_nj,
        (&(AirEfc_tExMnf_A[0])), 15U, &localPrelookup_o2_p,
        &localDW->Prelookup_DWORK1_c);

      /* PreLookup: '<S257>/Prelookup' */
      localPrelookup_o1_a = plook_s32u16f_bincpa(rtu_TrbAct_rOpTrbAct,
        (&(ExM_rTbrActrPosnX_A[0])), 19U, &localPrelookup_o2_e,
        &localDW->Prelookup_DWORK1_a);

      /* PreLookup: '<S258>/Prelookup' */
      localPrelookup_o1_g = plook_s32u16f_bincpa(rtu_Ext_nEng, (&(ExM_nEng1Y_A[0])),
        17U, &localPrelookup_o2_d, &localDW->Prelookup_DWORK1_an);

      /* end of Outputs for SubSystem: '<S199>/F01_MAP_index_of_turbine_thermal_model' */

      /* Logic: '<S199>/Logical Operator1' incorporates:
       *  Constant: '<S199>/ExM_bTrbActEstimPresent_C'
       *  Logic: '<S199>/Logical Operator3'
       */
      localLogicalOperator1_l = (ExM_bTrbActEstimPresent_C && (!rtu_FRM_bTrbAct));

      /* Outputs for enable SubSystem: '<S199>/F02_Turbine_pressure_model_with_WG_position' incorporates:
       *  EnablePort: '<S254>/Enable'
       */
      if (localLogicalOperator1_l) {
        /* DataTypeConversion: '<S254>/Data Type Conversion2' */
        localDataTypeConversion2_d = ((Float32)rtu_ExM_mfEgWoutEGR) *
          1.525878906E-005F;

        /* Outputs for atomic SubSystem: '<S254>/F01_WG_MFR_by_BSV_method' */

        /* Product: '<S264>/Divide' */
        localfractionTmp_0d = ExM_pUsPrev / localDataTypeConversion3_n;

        /* Outputs for atomic SubSystem: '<S264>/If Action Subsystem3' */

        /* Switch: '<S276>/Switch1' incorporates:
         *  Constant: '<S276>/Constant2'
         *  RelationalOperator: '<S276>/Relational Operator'
         *  Saturate: '<S276>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          localSwitch1_b = 0.0F;
        } else {
          localSwitch1_b = rt_SATURATE(localfractionTmp_0d, -3.000000005E+038F,
            3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S264>/If Action Subsystem3' */

        /* Product: '<S266>/Divide' */
        localfractionTmp_0d = ExM_pDs / localDataTypeConversion3_n;

        /* Outputs for atomic SubSystem: '<S266>/If Action Subsystem3' */

        /* Switch: '<S280>/Switch1' incorporates:
         *  Constant: '<S280>/Constant2'
         *  RelationalOperator: '<S280>/Relational Operator'
         *  Saturate: '<S280>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          localfractionTmp_0d = 0.0F;
        } else {
          localfractionTmp_0d = rt_SATURATE(localfractionTmp_0d,
            -3.000000005E+038F, 3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S266>/If Action Subsystem3' */

        /* Product: '<S265>/Divide' */
        localfractionTmp_0d /= localSwitch1_b;

        /* Outputs for atomic SubSystem: '<S265>/If Action Subsystem3' */

        /* Switch: '<S278>/Switch1' incorporates:
         *  Constant: '<S278>/Constant2'
         *  RelationalOperator: '<S278>/Relational Operator'
         *  Saturate: '<S278>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          localfractionTmp_0d = 0.0F;
        } else {
          localfractionTmp_0d = rt_SATURATE(localfractionTmp_0d,
            -3.000000005E+038F, 3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S265>/If Action Subsystem3' */

        /* Product: '<S271>/Product4' incorporates:
         *  Constant: '<S271>/offset'
         *  Constant: '<S271>/one_on_slope'
         *  Sum: '<S271>/Add1'
         */
        localInterpolationUsingPrelo_nv = 65536.0F * localfractionTmp_0d;

        /* DataTypeConversion: '<S271>/OutDTConv' */
        localtmp_0 = localInterpolationUsingPrelo_nv;
        if (localtmp_0 < 4.294967296E+009F) {
          if (localtmp_0 >= 0.0F) {
            localDataTypeConversion4_p3 = (UInt32)localtmp_0;
          } else {
            localDataTypeConversion4_p3 = 0U;
          }
        } else {
          localDataTypeConversion4_p3 = MAX_uint32_T;
        }

        /* PreLookup: '<S270>/Prelookup' */
        locali = plook_s32u32f_bincpa(localDataTypeConversion4_p3,
          (&(AirEfc_rPresEngX_A[0])), 10U, &localInterpolationUsingPrelo_nv,
          &localDW->Prelookup_DWORK1_p);

        /* Interpolation_n-D: '<S267>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInterpolationUsingPrelo_nv;
        localInterpolationUsingPrelo_nv = intrp1d_iu16n16ff_s32f_la_n(locali,
          localfractionTmp_0d, (&(AirEfc_facChrExp_T[0])), 10U);

        /* Interpolation_n-D: '<S268>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_p;
        localInterpolationUsingPreloo_o = intrp1d_iu32n15ff_s32f_la_n
          (localPrelookup_o1_e, localfractionTmp_0d, (&(AirEfc_facTExSqrt_T[0])),
           15U);

        /* Interpolation_n-D: '<S269>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_e;
        localfrac[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_d;
        localfrac[1] = localfractionTmp_0d;
        localbpIndex[0] = localPrelookup_o1_a;
        localbpIndex[1] = localPrelookup_o1_g;
        localDataTypeConversion1_k = intrp2d_iu16n7ff_s32f_la_n(localbpIndex,
          localfrac, (&(ExM_facTbrActrRedEstim_M[0])), 20U,
          &ExMGslT2_ConstP.pooled29[0]);

        /* Product: '<S272>/Divide' */
        localfractionTmp_0d = localInterpolationUsingPrelo_nv * localSwitch1_b;

        /* Product: '<S273>/Divide' */
        ExM_mfTbrActrEstimWoutCor_MP = localfractionTmp_0d *
          localInterpolationUsingPreloo_o;

        /* Product: '<S274>/Divide' */
        ExM_mfTbrActrEstim_posnWgMainMdl = ExM_mfTbrActrEstimWoutCor_MP *
          localDataTypeConversion1_k;

        /* end of Outputs for SubSystem: '<S254>/F01_WG_MFR_by_BSV_method' */

        /* Outputs for atomic SubSystem: '<S254>/F02_WG_MFR_by_map_method' */

        /* Interpolation_n-D: '<S281>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_e;
        localfrac_0[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_d;
        localfrac_0[1] = localfractionTmp_0d;
        localbpIndex_0[0] = localPrelookup_o1_a;
        localbpIndex_0[1] = localPrelookup_o1_g;
        localfractionTmp_0d = intrp2d_iu8n8ff_s32f_la_n(localbpIndex_0,
          localfrac_0, (&(ExM_rMfTbrActr_M[0])), 20U, &ExMGslT2_ConstP.pooled29
          [0]);

        /* Product: '<S282>/Divide' */
        ExM_mfTbrActrEstim_posnWgOpMdl = localDataTypeConversion2_d *
          localfractionTmp_0d;

        /* end of Outputs for SubSystem: '<S254>/F02_WG_MFR_by_map_method' */

        /* Outputs for atomic SubSystem: '<S254>/F03_WG_and_turbine_MFR' */

        /* Outputs for atomic SubSystem: '<S262>/F01_WG_MFR_selection' */

        /* MinMax: '<S283>/MinMax2' */
        localfractionTmp_0d = rt_MAXf(ExM_mfTbrActrEstim_posnWgOpMdl,
          ExM_mfTbrActrEstim_posnWgMainMdl);

        /* end of Outputs for SubSystem: '<S262>/F01_WG_MFR_selection' */

        /* Outputs for atomic SubSystem: '<S262>/F02_Turbine_MFR' */

        /* Sum: '<S284>/Q_turb_bfsat' */
        localDataTypeConversion1_k = localDataTypeConversion2_d -
          localfractionTmp_0d;

        /* RelationalOperator: '<S288>/LowerRelop1' */
        localLogicalOperator1 = (localDataTypeConversion1_k >
          localDataTypeConversion2_d);

        /* Switch: '<S288>/Switch' incorporates:
         *  Constant: '<S284>/Cste_1'
         *  RelationalOperator: '<S288>/UpperRelop'
         */
        if (localDataTypeConversion1_k < 0.0F) {
          localDataTypeConversion1_k = 0.0F;
        }

        /* Switch: '<S288>/Switch2' */
        if (localLogicalOperator1) {
          localDataTypeConversion1_k = localDataTypeConversion2_d;
        }

        /* end of Outputs for SubSystem: '<S262>/F02_Turbine_MFR' */

        /* SignalConversion: '<S262>/Signal Conversion' */
        localB->Merge1 = localfractionTmp_0d;

        /* end of Outputs for SubSystem: '<S254>/F03_WG_and_turbine_MFR' */

        /* Outputs for atomic SubSystem: '<S254>/F04_Turbine_upstream_pressure' */

        /* Outputs for atomic SubSystem: '<S263>/F01_Corrected_turbine_load' */

        /* RelationalOperator: '<S289>/Relational Operator' incorporates:
         *  Constant: '<S289>/ExM_nEngThdLdCorClc_C'
         */
        localLogicalOperator1 = (rtu_Ext_nEng < ExM_nEngThdLdCorClc_C);

        /* Outputs for enable SubSystem: '<S289>/F01_Corrected_exhaust_load_for_low_engine_speed' incorporates:
         *  EnablePort: '<S291>/Enable'
         */
        if (localLogicalOperator1) {
          /* DataTypeConversion: '<S291>/Data Type Conversion' incorporates:
           *  Constant: '<S291>/ExM_rEgTrbLdCor_nEngThd_C'
           */
          ExM_rEgTrbLdCor_nEng = ((Float32)ExM_rEgTrbLdCor_nEngThd_C) *
            1.525878906E-004F;
        }

        /* end of Outputs for SubSystem: '<S289>/F01_Corrected_exhaust_load_for_low_engine_speed' */

        /* Outputs for enable SubSystem: '<S289>/F02_Corrected_exhaust_load_for_engine_running' incorporates:
         *  EnablePort: '<S292>/Enable'
         *  Logic: '<S289>/Logical Operator'
         */
        if (!localLogicalOperator1) {
          /* Outputs for atomic SubSystem: '<S292>/F01_MFR_to_load_conversion_factor' */

          /* Product: '<S299>/Divide' incorporates:
           *  Constant: '<S293>/AirEfc_densAir_C'
           *  Constant: '<S293>/AirEfc_noCylEng_C'
           *  Constant: '<S293>/AirEfc_volRef_C'
           *  Constant: '<S293>/Cste_2'
           *  Constant: '<S293>/Cste_3'
           *  DataTypeConversion: '<S293>/Data Type Conversion1'
           *  DataTypeConversion: '<S293>/Data Type Conversion2'
           *  DataTypeConversion: '<S293>/Data Type Conversion3'
           *  DataTypeConversion: '<S293>/Data Type Conversion4'
           *  Product: '<S296>/Divide'
           *  Product: '<S297>/Divide'
           *  Product: '<S298>/Divide'
           *  Product: '<S300>/Divide'
           */
          ExM_facMassFlowLd1 = (((((Float32)AirEfc_volRef_C) *
            7.629394894E-009F) * (((Float32)AirEfc_noCylEng_C) / 2.0F)) *
                                (((Float32)AirEfc_densAir_C) *
            1.525878906E-005F)) * (((Float32)rtu_Ext_nEng) / 60.0F);

          /* end of Outputs for SubSystem: '<S292>/F01_MFR_to_load_conversion_factor' */

          /* Outputs for atomic SubSystem: '<S292>/F02_Thermodynamical_factors' */

          /* Interpolation_n-D: '<S301>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_p;
          ExM_facTEgSqrtIvs1 = intrp1d_iu32n15ff_s32f_la_n(localPrelookup_o1_e,
            localfractionTmp_0d, (&(AirEfc_facTExSqrt_T[0])), 15U);

          /* Product: '<S302>/Divide' incorporates:
           *  Constant: '<S294>/AirEfc_pRef_C'
           *  Constant: '<S294>/Cste_4'
           *  DataTypeConversion: '<S294>/Data Type Conversion4'
           *  MinMax: '<S294>/MinMax'
           */
          ExM_facPresAirExt1 = (((Float32)AirEfc_pRef_C) * 8.0F) / rt_MAXf
            (localDataTypeConversion3_n, 1.000000004E-015F);

          /* end of Outputs for SubSystem: '<S292>/F02_Thermodynamical_factors' */

          /* Outputs for atomic SubSystem: '<S292>/F03_Corrected_exhaust_load_calculation' */

          /* Product: '<S303>/Divide' incorporates:
           *  Constant: '<S295>/Cste_6'
           *  MinMax: '<S295>/MinMax'
           */
          ExM_rEgTrbLd_nEng_MP = localDataTypeConversion1_k / rt_MAXf
            (ExM_facMassFlowLd1, 1.000000004E-015F);

          /* Product: '<S304>/Divide' incorporates:
           *  Constant: '<S295>/Cste_5'
           *  MinMax: '<S295>/MinMax1'
           *  Product: '<S305>/Divide'
           */
          ExM_rEgTrbLdCor_nEng = (ExM_facPresAirExt1 * ExM_rEgTrbLd_nEng_MP) /
            rt_MAXf(ExM_facTEgSqrtIvs1, 1.000000004E-015F);

          /* end of Outputs for SubSystem: '<S292>/F03_Corrected_exhaust_load_calculation' */
        }

        /* end of Outputs for SubSystem: '<S289>/F02_Corrected_exhaust_load_for_engine_running' */

        /* end of Outputs for SubSystem: '<S263>/F01_Corrected_turbine_load' */

        /* Outputs for atomic SubSystem: '<S263>/F02_Turbine_upstream_pressure_calculation' */

        /* Product: '<S309>/Product4' incorporates:
         *  Constant: '<S309>/offset'
         *  Constant: '<S309>/one_on_slope'
         *  Sum: '<S309>/Add1'
         */
        localInterpolationUsingPreloo_n = 6.553600098E+003F *
          ExM_rEgTrbLdCor_nEng;

        /* DataTypeConversion: '<S309>/OutDTConv' */
        localtmp_0 = localInterpolationUsingPreloo_n;
        if (localtmp_0 < 65536.0F) {
          if (localtmp_0 >= 0.0F) {
            locallocalOutDTConv_nj = (UInt16)localtmp_0;
          } else {
            locallocalOutDTConv_nj = 0U;
          }
        } else {
          locallocalOutDTConv_nj = MAX_uint16_T;
        }

        /* PreLookup: '<S307>/Prelookup' */
        locali = plook_s32u16f_bincpa(locallocalOutDTConv_nj,
          (&(ExM_rEgTrbLdX_A[0])), 19U, &localInterpolationUsingPreloo_n,
          &localDW->Prelookup_DWORK1_j);

        /* PreLookup: '<S308>/Prelookup' */
        localPrelookup_o1_a = plook_s32u16f_bincpa(rtu_Ext_nEng,
          (&(ExM_nEng1Y_A[0])), 17U, &localPrelookup_o2_kx,
          &localDW->Prelookup_DWORK1_o);

        /* Interpolation_n-D: '<S306>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInterpolationUsingPreloo_n;
        localfrac_1[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_kx;
        localfrac_1[1] = localfractionTmp_0d;
        localbpIndex_1[0] = locali;
        localbpIndex_1[1] = localPrelookup_o1_a;
        localInterpolationUsingPreloo_n = intrp2d_iu16n16ff_s32f_la_n
          (localbpIndex_1, localfrac_1, (&(ExM_facPresTrb_M[0])), 20U,
           &ExMGslT2_ConstP.pooled29[0]);

        /* Product: '<S310>/Divide' */
        ExM_pTrbUs = localInterpolationUsingPreloo_n * ExM_pDs;

        /* end of Outputs for SubSystem: '<S263>/F02_Turbine_upstream_pressure_calculation' */

        /* end of Outputs for SubSystem: '<S254>/F04_Turbine_upstream_pressure' */

        /* SignalConversion: '<S254>/Signal Conversion' */
        localB->Merge2 = localDataTypeConversion1_k;
      }

      /* end of Outputs for SubSystem: '<S199>/F02_Turbine_pressure_model_with_WG_position' */

      /* Outputs for enable SubSystem: '<S199>/F03_Turbine_pressure_model_without_WG_position' incorporates:
       *  EnablePort: '<S255>/Enable'
       *  Logic: '<S199>/Logical Operator2'
       */
      if (!localLogicalOperator1_l) {
        /* DataTypeConversion: '<S255>/Data Type Conversion3' */
        localDataTypeConversion2_d = ((Float32)rtu_ExM_mfEgWoutEGR) *
          1.525878906E-005F;

        /* Outputs for atomic SubSystem: '<S255>/F01_Pressure_ratio' */

        /* Outputs for atomic SubSystem: '<S311>/F01_Specific_pressure_ratios' */

        /* Outputs for atomic SubSystem: '<S314>/F01_Corrected_exhaust_load' */

        /* RelationalOperator: '<S317>/Relational Operator' incorporates:
         *  Constant: '<S317>/ExM_nEngThdLdCorClc_C'
         */
        localLogicalOperator1 = (rtu_Ext_nEng < ExM_nEngThdLdCorClc_C);

        /* Outputs for enable SubSystem: '<S317>/F01_Corrected_exhaust_load_for_low_engine_speed' incorporates:
         *  EnablePort: '<S319>/Enable'
         */
        if (localLogicalOperator1) {
          /* DataTypeConversion: '<S319>/Data Type Conversion' incorporates:
           *  Constant: '<S319>/ExM_rEgTotLdCor_nEngThd_C'
           */
          ExM_rEgTotLdCor_nEng = ((Float32)ExM_rEgTotLdCor_nEngThd_C) *
            1.525878906E-004F;
        }

        /* end of Outputs for SubSystem: '<S317>/F01_Corrected_exhaust_load_for_low_engine_speed' */

        /* Outputs for enable SubSystem: '<S317>/F02_Corrected_exhaust_load_for_engine_running' incorporates:
         *  EnablePort: '<S320>/Enable'
         *  Logic: '<S317>/Logical Operator'
         */
        if (!localLogicalOperator1) {
          /* Outputs for atomic SubSystem: '<S320>/F01_MFR_to_load_conversion_factor' */

          /* Product: '<S328>/Divide' incorporates:
           *  Constant: '<S321>/AirEfc_densAir_C'
           *  Constant: '<S321>/AirEfc_noCylEng_C'
           *  Constant: '<S321>/AirEfc_volRef_C'
           *  Constant: '<S321>/Cste_7'
           *  Constant: '<S321>/Cste_8'
           *  DataTypeConversion: '<S321>/Data Type Conversion1'
           *  DataTypeConversion: '<S321>/Data Type Conversion2'
           *  DataTypeConversion: '<S321>/Data Type Conversion3'
           *  DataTypeConversion: '<S321>/Data Type Conversion4'
           *  Product: '<S324>/Divide'
           *  Product: '<S325>/Divide'
           *  Product: '<S326>/Divide'
           *  Product: '<S327>/Divide'
           */
          ExM_facMassFlowLd2 = (((((Float32)AirEfc_volRef_C) *
            7.629394894E-009F) * (((Float32)AirEfc_noCylEng_C) / 2.0F)) *
                                (((Float32)AirEfc_densAir_C) *
            1.525878906E-005F)) * (((Float32)rtu_Ext_nEng) / 60.0F);

          /* end of Outputs for SubSystem: '<S320>/F01_MFR_to_load_conversion_factor' */

          /* Outputs for atomic SubSystem: '<S320>/F02_Thermodynamical_factors' */

          /* Interpolation_n-D: '<S330>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_p;
          ExM_facTEgSqrtIvs2 = intrp1d_iu32n15ff_s32f_la_n(localPrelookup_o1_e,
            localfractionTmp_0d, (&(AirEfc_facTExSqrt_T[0])), 15U);

          /* Product: '<S329>/Divide' incorporates:
           *  Constant: '<S322>/AirEfc_pRef_C'
           *  DataTypeConversion: '<S322>/Data Type Conversion4'
           */
          localfractionTmp_0d = (((Float32)AirEfc_pRef_C) * 8.0F) /
            localDataTypeConversion3_n;

          /* Outputs for atomic SubSystem: '<S329>/If Action Subsystem3' */

          /* Switch: '<S332>/Switch1' incorporates:
           *  Constant: '<S332>/Constant2'
           *  RelationalOperator: '<S332>/Relational Operator'
           *  Saturate: '<S332>/Saturation'
           */
          if (localfractionTmp_0d != localfractionTmp_0d) {
            ExM_facPresAirExt2 = 0.0F;
          } else {
            ExM_facPresAirExt2 = rt_SATURATE(localfractionTmp_0d,
              -3.000000005E+038F, 3.000000005E+038F);
          }

          /* end of Outputs for SubSystem: '<S329>/If Action Subsystem3' */

          /* end of Outputs for SubSystem: '<S320>/F02_Thermodynamical_factors' */

          /* Outputs for atomic SubSystem: '<S320>/F03_Corrected_exhaust_load_calculation' */

          /* Product: '<S334>/Divide' */
          localfractionTmp_0d = localDataTypeConversion2_d / ExM_facMassFlowLd2;

          /* Outputs for atomic SubSystem: '<S334>/If Action Subsystem3' */

          /* Switch: '<S339>/Switch1' incorporates:
           *  Constant: '<S339>/Constant2'
           *  RelationalOperator: '<S339>/Relational Operator'
           *  Saturate: '<S339>/Saturation'
           */
          if (localfractionTmp_0d != localfractionTmp_0d) {
            ExM_rEgTotLd_nEng_MP = 0.0F;
          } else {
            ExM_rEgTotLd_nEng_MP = rt_SATURATE(localfractionTmp_0d,
              -3.000000005E+038F, 3.000000005E+038F);
          }

          /* end of Outputs for SubSystem: '<S334>/If Action Subsystem3' */

          /* Product: '<S333>/Divide' incorporates:
           *  Product: '<S335>/Divide'
           */
          localfractionTmp_0d = (ExM_facPresAirExt2 * ExM_rEgTotLd_nEng_MP) /
            ExM_facTEgSqrtIvs2;

          /* Outputs for atomic SubSystem: '<S333>/If Action Subsystem3' */

          /* Switch: '<S337>/Switch1' incorporates:
           *  Constant: '<S337>/Constant2'
           *  DataTypeConversion: '<S333>/Data Type Conversion2'
           *  RelationalOperator: '<S337>/Relational Operator'
           *  Saturate: '<S337>/Saturation'
           */
          if (localfractionTmp_0d != localfractionTmp_0d) {
            ExM_rEgTotLdCor_nEng = 0.0F;
          } else {
            ExM_rEgTotLdCor_nEng = rt_SATURATE(localfractionTmp_0d,
              -3.000000005E+038F, 3.000000005E+038F);
          }

          /* end of Outputs for SubSystem: '<S333>/If Action Subsystem3' */

          /* end of Outputs for SubSystem: '<S320>/F03_Corrected_exhaust_load_calculation' */
        }

        /* end of Outputs for SubSystem: '<S317>/F02_Corrected_exhaust_load_for_engine_running' */

        /* end of Outputs for SubSystem: '<S314>/F01_Corrected_exhaust_load' */

        /* Outputs for atomic SubSystem: '<S314>/F02_MAPS_of_specific_pressure_ratios' */

        /* Product: '<S351>/Product4' incorporates:
         *  Constant: '<S351>/offset'
         *  Constant: '<S351>/one_on_slope'
         *  Sum: '<S351>/Add1'
         */
        localPrelookup1_o2_g = 6.553600098E+003F * ExM_rEgTotLdCor_nEng;

        /* DataTypeConversion: '<S351>/OutDTConv' */
        localtmp_0 = localPrelookup1_o2_g;
        if (localtmp_0 < 65536.0F) {
          if (localtmp_0 >= 0.0F) {
            locallocalOutDTConv_nj = (UInt16)localtmp_0;
          } else {
            locallocalOutDTConv_nj = 0U;
          }
        } else {
          locallocalOutDTConv_nj = MAX_uint16_T;
        }

        /* PreLookup: '<S349>/Prelookup1' */
        locali = plook_s32u16f_lincpa(locallocalOutDTConv_nj,
          (&(ExM_rEgTotLdCorX_A[0])), 15U, &localPrelookup1_o2_g,
          &localDW->Prelookup1_DWORK1);

        /* PreLookup: '<S350>/Prelookup1' */
        localPrelookup_o1_a = plook_s32u16f_lincpa(rtu_Ext_nEng, (&(ExM_nEngY_A
          [0])), 17U, &localPrelookup1_o2, &localDW->Prelookup1_DWORK1_o);

        /* Interpolation_n-D: '<S340>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_2[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_2[1] = localfractionTmp_0d;
        localbpIndex_2[0] = locali;
        localbpIndex_2[1] = localPrelookup_o1_a;
        ExM_rPresInMaxExMid = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_2,
          localfrac_2, (&(ExM_rPresInMaxExMid_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* Interpolation_n-D: '<S341>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_3[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_3[1] = localfractionTmp_0d;
        localbpIndex_3[0] = locali;
        localbpIndex_3[1] = localPrelookup_o1_a;
        ExM_rPresInMaxExMax = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_3,
          localfrac_3, (&(ExM_rPresInMaxExMax_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* Interpolation_n-D: '<S342>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_4[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_4[1] = localfractionTmp_0d;
        localbpIndex_4[0] = locali;
        localbpIndex_4[1] = localPrelookup_o1_a;
        ExM_rPresInMaxExMin = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_4,
          localfrac_4, (&(ExM_rPresInMaxExMin_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* Interpolation_n-D: '<S343>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_5[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_5[1] = localfractionTmp_0d;
        localbpIndex_5[0] = locali;
        localbpIndex_5[1] = localPrelookup_o1_a;
        ExM_rPresInMidExMax = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_5,
          localfrac_5, (&(ExM_rPresInMidExMax_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* Interpolation_n-D: '<S344>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_6[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_6[1] = localfractionTmp_0d;
        localbpIndex_6[0] = locali;
        localbpIndex_6[1] = localPrelookup_o1_a;
        ExM_rPresInMidExMid = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_6,
          localfrac_6, (&(ExM_rPresInMidExMid_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* Interpolation_n-D: '<S345>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_7[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_7[1] = localfractionTmp_0d;
        localbpIndex_7[0] = locali;
        localbpIndex_7[1] = localPrelookup_o1_a;
        ExM_rPresInMidExMin = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_7,
          localfrac_7, (&(ExM_rPresInMidExMin_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* Interpolation_n-D: '<S346>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_8[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_8[1] = localfractionTmp_0d;
        localbpIndex_8[0] = locali;
        localbpIndex_8[1] = localPrelookup_o1_a;
        ExM_rPresInMinExMax = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_8,
          localfrac_8, (&(ExM_rPresInMinExMax_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* Interpolation_n-D: '<S347>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_9[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_9[1] = localfractionTmp_0d;
        localbpIndex_9[0] = locali;
        localbpIndex_9[1] = localPrelookup_o1_a;
        ExM_rPresInMinExMid = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_9,
          localfrac_9, (&(ExM_rPresInMinExMid_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* Interpolation_n-D: '<S348>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup1_o2_g;
        localfrac_a[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup1_o2;
        localfrac_a[1] = localfractionTmp_0d;
        localbpIndex_a[0] = locali;
        localbpIndex_a[1] = localPrelookup_o1_a;
        ExM_rPresInMinExMin = intrp2d_iu8n6ff_s32f_la_n(localbpIndex_a,
          localfrac_a, (&(ExM_rPresInMinExMin_M[0])), 16U,
          &ExMGslT2_ConstP.pooled30[0]);

        /* end of Outputs for SubSystem: '<S314>/F02_MAPS_of_specific_pressure_ratios' */

        /* end of Outputs for SubSystem: '<S311>/F01_Specific_pressure_ratios' */

        /* Outputs for atomic SubSystem: '<S311>/F02_Interpolations_on_IVO' */

        /* Outputs for atomic SubSystem: '<S315>/F01_Interpolation_factors_on_IVO' */

        /* DataTypeConversion: '<S352>/Data Type Conversion' incorporates:
         *  Constant: '<S352>/ExM_agCkOpInVlvMid_C'
         */
        localDataTypeConversion1_k = ((Float32)ExM_agCkOpInVlvMid_C) * 0.09375F;

        /* DataTypeConversion: '<S352>/Data Type Conversion1' incorporates:
         *  Constant: '<S352>/ExM_agCkOpInVlvLimThd_C'
         */
        localInterpolationUsingPreloo_o = ((Float32)ExM_agCkOpInVlvLimThd_C) *
          0.09375F;

        /* DataTypeConversion: '<S352>/Data Type Conversion2' */
        localSwitch1_b = ((Float32)rtu_EngM_agCkOpInVlvEstimRef1) * 0.09375F;

        /* Sum: '<S352>/Sum' incorporates:
         *  Constant: '<S352>/ExM_agCkOpInVlvMin_C'
         *  DataTypeConversion: '<S352>/Data Type Conversion3'
         */
        ExM_agCkInDeltaMidMin_MP = localDataTypeConversion1_k - (((Float32)
          ExM_agCkOpInVlvMin_C) * 0.09375F);

        /* Outputs for enable SubSystem: '<S352>/F01_Default_interpolation_factor_for_IVO_MinMid' incorporates:
         *  EnablePort: '<S355>/Enable'
         *  EnablePort: '<S356>/Enable'
         *  Logic: '<S352>/Logical Operator'
         *  RelationalOperator: '<S352>/Relational Operator'
         *  SubSystem: '<S352>/F02_Interpolation_factor_for_IVO_MinMid'
         */
        if (!(ExM_agCkInDeltaMidMin_MP >= localInterpolationUsingPreloo_o)) {
          /* DataTypeConversion: '<S355>/Data Type Conversion2' incorporates:
           *  Constant: '<S355>/ExM_facOpInVlvMinMidEqu_C'
           */
          ExM_facSatOpInVlvMinMid = ((Float32)ExM_facOpInVlvMinMidEqu_C) *
            1.525878906E-005F;
        } else {
          /* DataTypeConversion: '<S356>/Data Type Conversion2' incorporates:
           *  Constant: '<S356>/ExM_agCkOpInVlvMid_C'
           */
          localfractionTmp_0d = ((Float32)ExM_agCkOpInVlvMid_C) * 0.09375F;

          /* Product: '<S359>/Divide' incorporates:
           *  Constant: '<S356>/ExM_agCkOpInVlvMin_C'
           *  DataTypeConversion: '<S356>/Data Type Conversion1'
           *  Sum: '<S356>/Add1'
           *  Sum: '<S356>/Add4'
           */
          localfractionTmp_0d = (localfractionTmp_0d - localSwitch1_b) /
            (localfractionTmp_0d - (((Float32)ExM_agCkOpInVlvMin_C) * 0.09375F));

          /* Outputs for atomic SubSystem: '<S359>/If Action Subsystem3' */

          /* Switch: '<S361>/Switch1' incorporates:
           *  Constant: '<S361>/Constant2'
           *  RelationalOperator: '<S361>/Relational Operator'
           *  Saturate: '<S361>/Saturation'
           */
          if (localfractionTmp_0d != localfractionTmp_0d) {
            ExM_facOpInVlvMinMid_MP = 0.0F;
          } else {
            ExM_facOpInVlvMinMid_MP = rt_SATURATE(localfractionTmp_0d,
              -3.000000005E+038F, 3.000000005E+038F);
          }

          /* end of Outputs for SubSystem: '<S359>/If Action Subsystem3' */

          /* MinMax: '<S356>/MinMax2' incorporates:
           *  Constant: '<S356>/Cste_9'
           */
          localfractionTmp_0d = rt_MAXf(0.0F, ExM_facOpInVlvMinMid_MP);

          /* MinMax: '<S356>/MinMax3' incorporates:
           *  Constant: '<S356>/Cste_10'
           */
          ExM_facSatOpInVlvMinMid = rt_MINf(1.0F, localfractionTmp_0d);
        }

        /* end of Outputs for SubSystem: '<S352>/F01_Default_interpolation_factor_for_IVO_MinMid' */

        /* Sum: '<S352>/Sum1' incorporates:
         *  Constant: '<S352>/ExM_agCkOpInVlvMax_C'
         *  DataTypeConversion: '<S352>/Data Type Conversion4'
         */
        ExM_agCkInDeltaMaxMid_MP = (((Float32)ExM_agCkOpInVlvMax_C) * 0.09375F)
          - localDataTypeConversion1_k;

        /* Outputs for enable SubSystem: '<S352>/F03_Default_interpolation_factor_for_IVO_MidMax' incorporates:
         *  EnablePort: '<S357>/Enable'
         *  EnablePort: '<S358>/Enable'
         *  Logic: '<S352>/Logical Operator1'
         *  RelationalOperator: '<S352>/Relational Operator1'
         *  SubSystem: '<S352>/F04_Interpolation_factor_for_IVO_MidMax'
         */
        if (!(ExM_agCkInDeltaMaxMid_MP >= localInterpolationUsingPreloo_o)) {
          /* DataTypeConversion: '<S357>/Data Type Conversion1' incorporates:
           *  Constant: '<S357>/ExM_facOpInVlvMidMaxEqu_C'
           */
          ExM_facSatOpInVlvMidMax = ((Float32)ExM_facOpInVlvMidMaxEqu_C) *
            1.525878906E-005F;
        } else {
          /* DataTypeConversion: '<S358>/Data Type Conversion1' incorporates:
           *  Constant: '<S358>/ExM_agCkOpInVlvMax_C'
           */
          localfractionTmp_0d = ((Float32)ExM_agCkOpInVlvMax_C) * 0.09375F;

          /* Product: '<S362>/Divide' incorporates:
           *  Constant: '<S358>/ExM_agCkOpInVlvMid_C'
           *  DataTypeConversion: '<S358>/Data Type Conversion2'
           *  Sum: '<S358>/Add2'
           *  Sum: '<S358>/Add3'
           */
          localfractionTmp_0d = (localfractionTmp_0d - localSwitch1_b) /
            (localfractionTmp_0d - (((Float32)ExM_agCkOpInVlvMid_C) * 0.09375F));

          /* Outputs for atomic SubSystem: '<S362>/If Action Subsystem3' */

          /* Switch: '<S364>/Switch1' incorporates:
           *  Constant: '<S364>/Constant2'
           *  RelationalOperator: '<S364>/Relational Operator'
           *  Saturate: '<S364>/Saturation'
           */
          if (localfractionTmp_0d != localfractionTmp_0d) {
            ExM_facOpInVlvMidMax_MP = 0.0F;
          } else {
            ExM_facOpInVlvMidMax_MP = rt_SATURATE(localfractionTmp_0d,
              -3.000000005E+038F, 3.000000005E+038F);
          }

          /* end of Outputs for SubSystem: '<S362>/If Action Subsystem3' */

          /* MinMax: '<S358>/MinMax' incorporates:
           *  Constant: '<S358>/Cste_11'
           */
          localfractionTmp_0d = rt_MAXf(ExM_facOpInVlvMidMax_MP, 0.0F);

          /* MinMax: '<S358>/MinMax1' incorporates:
           *  Constant: '<S358>/Cste_12'
           */
          ExM_facSatOpInVlvMidMax = rt_MINf(localfractionTmp_0d, 1.0F);
        }

        /* end of Outputs for SubSystem: '<S352>/F03_Default_interpolation_factor_for_IVO_MidMax' */

        /* end of Outputs for SubSystem: '<S315>/F01_Interpolation_factors_on_IVO' */

        /* Outputs for enable SubSystem: '<S315>/F02_Specific_EVC_pressure_ratios_for_current_IVO_superior_to_IVOmid' incorporates:
         *  Constant: '<S315>/ExM_agCkOpInVlvMid_C'
         *  EnablePort: '<S353>/Enable'
         *  EnablePort: '<S354>/Enable'
         *  Logic: '<S315>/Logical Operator'
         *  RelationalOperator: '<S315>/Relational Operator'
         *  SubSystem: '<S315>/F03_Specific_EVC_pressure_ratios_for_current_IVO_inferior_to_IVOmid'
         */
        if (rtu_EngM_agCkOpInVlvEstimRef1 >= ExM_agCkOpInVlvMid_C) {
          /* Sum: '<S353>/Add1' */
          localInterpolationUsingPreloo_o = ExM_rPresInMidExMax -
            ExM_rPresInMaxExMax;

          /* Sum: '<S353>/Add3' */
          localDataTypeConversion1_k = ExM_rPresInMidExMid - ExM_rPresInMaxExMid;

          /* Product: '<S368>/Product4' incorporates:
           *  Constant: '<S368>/offset'
           *  Constant: '<S368>/one_on_slope'
           *  Sum: '<S368>/Add1'
           */
          localInterpolationUsingPrelo_j1 = 65536.0F * ExM_facSatOpInVlvMidMax;

          /* DataTypeConversion: '<S368>/OutDTConv' */
          localtmp_0 = localInterpolationUsingPrelo_j1;
          if (localtmp_0 < 65536.0F) {
            if (localtmp_0 >= 0.0F) {
              locallocalOutDTConv_nj = (UInt16)localtmp_0;
            } else {
              locallocalOutDTConv_nj = 0U;
            }
          } else {
            locallocalOutDTConv_nj = MAX_uint16_T;
          }

          /* PreLookup: '<S367>/Prelookup' */
          locali = plook_s32u16f_bincpa(locallocalOutDTConv_nj,
            (&(ExM_facInMidMax_A[0])), 10U, &localInterpolationUsingPrelo_j1,
            &localDW->Prelookup_DWORK1_fo);

          /* Interpolation_n-D: '<S366>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localInterpolationUsingPrelo_j1;
          localfractionTmp_0d = intrp1d_iu16n16ff_s32f_la_n(locali,
            localfractionTmp_0d, (&(ExM_facInMidMaxAdjExMid_T[0])), 10U);

          /* Sum: '<S353>/Add10' incorporates:
           *  Product: '<S370>/Divide'
           */
          ExM_rPresClsExVlvMid1_MP = (localDataTypeConversion1_k *
            localfractionTmp_0d) + ExM_rPresInMaxExMid;

          /* Interpolation_n-D: '<S365>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localInterpolationUsingPrelo_j1;
          localInterpolationUsingPrelo_j1 = intrp1d_iu16n16ff_s32f_la_n(locali,
            localfractionTmp_0d, (&(ExM_facInMidMaxAdjExMax_T[0])), 10U);

          /* Product: '<S369>/Divide' */
          localfractionTmp_0d = localInterpolationUsingPreloo_o *
            localInterpolationUsingPrelo_j1;

          /* Sum: '<S353>/Add2' */
          ExM_rPresClsExVlvMax1_MP = ExM_rPresInMaxExMax + localfractionTmp_0d;

          /* Sum: '<S353>/Add6' incorporates:
           *  Product: '<S371>/Divide'
           *  Sum: '<S353>/Add4'
           */
          ExM_rPresClsExVlvMin1_MP = ((ExM_rPresInMidExMin - ExM_rPresInMaxExMin)
            * ExM_facSatOpInVlvMidMax) + ExM_rPresInMaxExMin;

          /* SignalConversion: '<S353>/Signal Conversion' */
          ExM_rPresClsExVlvMax = ExM_rPresClsExVlvMax1_MP;

          /* SignalConversion: '<S353>/Signal Conversion1' */
          ExM_rPresClsExVlvMid = ExM_rPresClsExVlvMid1_MP;

          /* SignalConversion: '<S353>/Signal Conversion2' */
          ExM_rPresClsExVlvMin = ExM_rPresClsExVlvMin1_MP;
        } else {
          /* Sum: '<S354>/Add12' incorporates:
           *  Product: '<S376>/Divide'
           *  Sum: '<S354>/Add1'
           */
          ExM_rPresClsExVlvMid2_MP = ((ExM_rPresInMinExMid - ExM_rPresInMidExMid)
            * ExM_facSatOpInVlvMinMid) + ExM_rPresInMidExMid;

          /* Sum: '<S354>/Add2' */
          localInterpolationUsingPreloo_o = ExM_rPresInMinExMin -
            ExM_rPresInMidExMin;

          /* Sum: '<S354>/Add3' */
          localfractionTmp_0d = ExM_rPresInMinExMax - ExM_rPresInMidExMax;

          /* Product: '<S374>/Product4' incorporates:
           *  Constant: '<S374>/offset'
           *  Constant: '<S374>/one_on_slope'
           *  Sum: '<S374>/Add1'
           */
          localInterpolationUsingPreloo_l = 65536.0F * ExM_facSatOpInVlvMinMid;

          /* DataTypeConversion: '<S374>/OutDTConv' */
          localtmp_0 = localInterpolationUsingPreloo_l;
          if (localtmp_0 < 65536.0F) {
            if (localtmp_0 >= 0.0F) {
              locallocalOutDTConv_nj = (UInt16)localtmp_0;
            } else {
              locallocalOutDTConv_nj = 0U;
            }
          } else {
            locallocalOutDTConv_nj = MAX_uint16_T;
          }

          /* PreLookup: '<S373>/Prelookup' */
          locali = plook_s32u16f_bincpa(locallocalOutDTConv_nj,
            (&(ExM_facInMinMid_A[0])), 10U, &localInterpolationUsingPreloo_l,
            &localDW->Prelookup_DWORK1_f);

          /* Interpolation_n-D: '<S372>/Interpolation Using Prelookup3' */
          localDataTypeConversion1_k = localInterpolationUsingPreloo_l;
          localInterpolationUsingPreloo_l = intrp1d_iu16n16ff_s32f_la_n(locali,
            localDataTypeConversion1_k, (&(ExM_facInMinMidAdjExMax_T[0])), 10U);

          /* Product: '<S375>/Divide' */
          localfractionTmp_0d *= localInterpolationUsingPreloo_l;

          /* Sum: '<S354>/Add4' */
          ExM_rPresClsExVlvMax2_MP = ExM_rPresInMidExMax + localfractionTmp_0d;

          /* Sum: '<S354>/Add8' incorporates:
           *  Product: '<S377>/Divide'
           */
          ExM_rPresClsExVlvMin2_MP = (localInterpolationUsingPreloo_o *
            ExM_facSatOpInVlvMinMid) + ExM_rPresInMidExMin;

          /* SignalConversion: '<S354>/Signal Conversion' */
          ExM_rPresClsExVlvMax = ExM_rPresClsExVlvMax2_MP;

          /* SignalConversion: '<S354>/Signal Conversion1' */
          ExM_rPresClsExVlvMid = ExM_rPresClsExVlvMid2_MP;

          /* SignalConversion: '<S354>/Signal Conversion2' */
          ExM_rPresClsExVlvMin = ExM_rPresClsExVlvMin2_MP;
        }

        /* end of Outputs for SubSystem: '<S315>/F02_Specific_EVC_pressure_ratios_for_current_IVO_superior_to_IVOmid' */

        /* end of Outputs for SubSystem: '<S311>/F02_Interpolations_on_IVO' */

        /* Outputs for atomic SubSystem: '<S311>/F03_Interpolations_on_EVC' */

        /* Outputs for atomic SubSystem: '<S316>/F01_Interpolation_factors_on_EVC' */

        /* DataTypeConversion: '<S378>/Data Type Conversion' incorporates:
         *  Constant: '<S378>/ExM_agCkClsExVlvMid_C'
         */
        localDataTypeConversion1_k = ((Float32)ExM_agCkClsExVlvMid_C) *
          0.09375F;

        /* DataTypeConversion: '<S378>/Data Type Conversion1' incorporates:
         *  Constant: '<S378>/ExM_agCkClsExVlvLimThd_C'
         */
        localInterpolationUsingPreloo_o = ((Float32)ExM_agCkClsExVlvLimThd_C) *
          0.09375F;

        /* DataTypeConversion: '<S378>/Data Type Conversion3' */
        localSwitch1_b = ((Float32)rtu_EngM_agCkClsExVlvEstimRef1) * 0.09375F;

        /* Sum: '<S378>/Sum' incorporates:
         *  Constant: '<S378>/ExM_agCkClsExVlvMin_C'
         *  DataTypeConversion: '<S378>/Data Type Conversion4'
         */
        ExM_agCkExDeltaMidMin_MP = localDataTypeConversion1_k - (((Float32)
          ExM_agCkClsExVlvMin_C) * 0.09375F);

        /* Outputs for enable SubSystem: '<S378>/F01_Default_interpolation_factor_for_EVC_MinMid' incorporates:
         *  EnablePort: '<S381>/Enable'
         *  EnablePort: '<S382>/Enable'
         *  Logic: '<S378>/Logical Operator'
         *  RelationalOperator: '<S378>/Relational Operator'
         *  SubSystem: '<S378>/F02_Interpolation_factor_for_EVC_MinMid'
         */
        if (!(ExM_agCkExDeltaMidMin_MP >= localInterpolationUsingPreloo_o)) {
          /* DataTypeConversion: '<S381>/Data Type Conversion3' incorporates:
           *  Constant: '<S381>/ExM_facClsExVlvMinMidEqu_C'
           */
          ExM_facSatClsExVlvMinMid = ((Float32)ExM_facClsExVlvMinMidEqu_C) *
            1.525878906E-005F;
        } else {
          /* DataTypeConversion: '<S382>/Data Type Conversion3' incorporates:
           *  Constant: '<S382>/ExM_agCkClsExVlvMid_C'
           */
          localfractionTmp_0d = ((Float32)ExM_agCkClsExVlvMid_C) * 0.09375F;

          /* Product: '<S385>/Divide' incorporates:
           *  Constant: '<S382>/ExM_agCkClsExVlvMin_C'
           *  DataTypeConversion: '<S382>/Data Type Conversion1'
           *  Sum: '<S382>/Add2'
           *  Sum: '<S382>/Add5'
           */
          localfractionTmp_0d = (localfractionTmp_0d - localSwitch1_b) /
            (localfractionTmp_0d - (((Float32)ExM_agCkClsExVlvMin_C) * 0.09375F));

          /* Outputs for atomic SubSystem: '<S385>/If Action Subsystem3' */

          /* Switch: '<S387>/Switch1' incorporates:
           *  Constant: '<S387>/Constant2'
           *  RelationalOperator: '<S387>/Relational Operator'
           *  Saturate: '<S387>/Saturation'
           */
          if (localfractionTmp_0d != localfractionTmp_0d) {
            ExM_facClsExVlvMinMid_MP = 0.0F;
          } else {
            ExM_facClsExVlvMinMid_MP = rt_SATURATE(localfractionTmp_0d,
              -3.000000005E+038F, 3.000000005E+038F);
          }

          /* end of Outputs for SubSystem: '<S385>/If Action Subsystem3' */

          /* MinMax: '<S382>/MinMax' incorporates:
           *  Constant: '<S382>/Cste_13'
           */
          localfractionTmp_0d = rt_MAXf(0.0F, ExM_facClsExVlvMinMid_MP);

          /* MinMax: '<S382>/MinMax1' incorporates:
           *  Constant: '<S382>/Cste_14'
           */
          ExM_facSatClsExVlvMinMid = rt_MINf(1.0F, localfractionTmp_0d);
        }

        /* end of Outputs for SubSystem: '<S378>/F01_Default_interpolation_factor_for_EVC_MinMid' */

        /* Sum: '<S378>/Sum1' incorporates:
         *  Constant: '<S378>/ExM_agCkClsExVlvMax_C'
         *  DataTypeConversion: '<S378>/Data Type Conversion2'
         */
        ExM_agCkExDeltaMaxMid_MP = (((Float32)ExM_agCkClsExVlvMax_C) * 0.09375F)
          - localDataTypeConversion1_k;

        /* Outputs for enable SubSystem: '<S378>/F03_Default_interpolation_factor_for_EVC_MidMax' incorporates:
         *  EnablePort: '<S383>/Enable'
         *  EnablePort: '<S384>/Enable'
         *  Logic: '<S378>/Logical Operator1'
         *  RelationalOperator: '<S378>/Relational Operator1'
         *  SubSystem: '<S378>/F04_Interpolation_factor_for_EVC_MidMax'
         */
        if (!(ExM_agCkExDeltaMaxMid_MP >= localInterpolationUsingPreloo_o)) {
          /* DataTypeConversion: '<S383>/Data Type Conversion3' incorporates:
           *  Constant: '<S383>/ExM_facClsExVlvMidMaxEqu_C'
           */
          ExM_facSatClsExVlvMidMax = ((Float32)ExM_facClsExVlvMidMaxEqu_C) *
            1.525878906E-005F;
        } else {
          /* DataTypeConversion: '<S384>/Data Type Conversion3' incorporates:
           *  Constant: '<S384>/ExM_agCkClsExVlvMax_C'
           */
          localfractionTmp_0d = ((Float32)ExM_agCkClsExVlvMax_C) * 0.09375F;

          /* Product: '<S388>/Divide' incorporates:
           *  Constant: '<S384>/ExM_agCkClsExVlvMid_C'
           *  DataTypeConversion: '<S384>/Data Type Conversion1'
           *  Sum: '<S384>/Add1'
           *  Sum: '<S384>/Add4'
           */
          localfractionTmp_0d = (localfractionTmp_0d - localSwitch1_b) /
            (localfractionTmp_0d - (((Float32)ExM_agCkClsExVlvMid_C) * 0.09375F));

          /* Outputs for atomic SubSystem: '<S388>/If Action Subsystem3' */

          /* Switch: '<S390>/Switch1' incorporates:
           *  Constant: '<S390>/Constant2'
           *  RelationalOperator: '<S390>/Relational Operator'
           *  Saturate: '<S390>/Saturation'
           */
          if (localfractionTmp_0d != localfractionTmp_0d) {
            ExM_facClsExVlvMidMax_MP = 0.0F;
          } else {
            ExM_facClsExVlvMidMax_MP = rt_SATURATE(localfractionTmp_0d,
              -3.000000005E+038F, 3.000000005E+038F);
          }

          /* end of Outputs for SubSystem: '<S388>/If Action Subsystem3' */

          /* MinMax: '<S384>/MinMax2' incorporates:
           *  Constant: '<S384>/Cste_15'
           */
          localfractionTmp_0d = rt_MAXf(ExM_facClsExVlvMidMax_MP, 0.0F);

          /* MinMax: '<S384>/MinMax3' incorporates:
           *  Constant: '<S384>/Cste_16'
           */
          ExM_facSatClsExVlvMidMax = rt_MINf(localfractionTmp_0d, 1.0F);
        }

        /* end of Outputs for SubSystem: '<S378>/F03_Default_interpolation_factor_for_EVC_MidMax' */

        /* end of Outputs for SubSystem: '<S316>/F01_Interpolation_factors_on_EVC' */

        /* Outputs for enable SubSystem: '<S316>/F02_Current_pressure_ratios_for_current_EVC_superior_to_EVCmid' incorporates:
         *  Constant: '<S316>/ExM_agCkClsExVlvMid_C'
         *  EnablePort: '<S379>/Enable'
         *  EnablePort: '<S380>/Enable'
         *  Logic: '<S316>/Logical Operator'
         *  RelationalOperator: '<S316>/Relational Operator'
         *  SubSystem: '<S316>/F03_Current_pressure_ratios_for_current_EVC_inferior_to_EVCmid'
         */
        if (rtu_EngM_agCkClsExVlvEstimRef1 >= ExM_agCkClsExVlvMid_C) {
          /* Sum: '<S379>/Add12' incorporates:
           *  Product: '<S391>/Divide'
           *  Sum: '<S379>/Add11'
           */
          ExM_rPresExMnf_MP = ((ExM_rPresClsExVlvMid - ExM_rPresClsExVlvMax) *
                               ExM_facSatClsExVlvMidMax) + ExM_rPresClsExVlvMax;

          /* SignalConversion: '<S379>/Signal Conversion' */
          ExM_rPresExMnf = ExM_rPresExMnf_MP;
        } else {
          /* SignalConversion: '<S380>/Signal Conversion' incorporates:
           *  Product: '<S392>/Divide'
           *  Sum: '<S380>/Add10'
           *  Sum: '<S380>/Add9'
           */
          ExM_rPresExMnf = ((ExM_rPresClsExVlvMin - ExM_rPresClsExVlvMid) *
                            ExM_facSatClsExVlvMinMid) + ExM_rPresClsExVlvMid;
        }

        /* end of Outputs for SubSystem: '<S316>/F02_Current_pressure_ratios_for_current_EVC_superior_to_EVCmid' */

        /* end of Outputs for SubSystem: '<S311>/F03_Interpolations_on_EVC' */

        /* end of Outputs for SubSystem: '<S255>/F01_Pressure_ratio' */

        /* Outputs for atomic SubSystem: '<S255>/F02_Turbine_upstream_pressure' */

        /* Product: '<S393>/Divide' */
        localInterpolationUsingPreloo_o = ExM_rPresExMnf * ExM_pDs;

        /* end of Outputs for SubSystem: '<S255>/F02_Turbine_upstream_pressure' */

        /* Outputs for atomic SubSystem: '<S255>/F03_MFR_through_turbine_and_WG' */

        /* Interpolation_n-D: '<S397>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_p;
        localDataTypeConversion1_k = intrp1d_iu32n15ff_s32f_la_n
          (localPrelookup_o1_e, localfractionTmp_0d, (&(AirEfc_facTExSqrt_T[0])),
           15U);

        /* Product: '<S395>/Divide' */
        localfractionTmp_0d = localInterpolationUsingPreloo_o / ExM_pDs;

        /* Outputs for atomic SubSystem: '<S395>/If Action Subsystem3' */

        /* Switch: '<S407>/Switch1' incorporates:
         *  Constant: '<S407>/Constant2'
         *  RelationalOperator: '<S407>/Relational Operator'
         *  Saturate: '<S407>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          localfractionTmp_0d = 0.0F;
        } else {
          localfractionTmp_0d = rt_SATURATE(localfractionTmp_0d,
            -3.000000005E+038F, 3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S395>/If Action Subsystem3' */

        /* Product: '<S399>/Product4' incorporates:
         *  Constant: '<S399>/offset'
         *  Constant: '<S399>/one_on_slope'
         *  Sum: '<S399>/Add1'
         */
        localSwitch2_g = 1.310720020E+004F * localfractionTmp_0d;

        /* DataTypeConversion: '<S399>/OutDTConv' */
        localtmp_0 = localSwitch2_g;
        if (localtmp_0 < 65536.0F) {
          if (localtmp_0 >= 0.0F) {
            locallocalOutDTConv_nj = (UInt16)localtmp_0;
          } else {
            locallocalOutDTConv_nj = 0U;
          }
        } else {
          locallocalOutDTConv_nj = MAX_uint16_T;
        }

        /* PreLookup: '<S398>/Prelookup' */
        locali = plook_s32u16f_bincpa(locallocalOutDTConv_nj,
          (&(ExM_rPresTrbEstim_A[0])), 10U, &localSwitch2_g,
          &localDW->Prelookup_DWORK1_l);

        /* Interpolation_n-D: '<S396>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localSwitch2_g;
        localSwitch2_g = intrp1d_iu16n16ff_s32f_la_n(locali, localfractionTmp_0d,
          (&(ExM_mfTrbEstimCor_T[0])), 10U);

        /* Product: '<S401>/Divide' */
        localfractionTmp_0d = localSwitch2_g * localInterpolationUsingPreloo_o;

        /* Product: '<S402>/Divide' incorporates:
         *  Constant: '<S313>/AirEfc_pRef_C'
         *  DataTypeConversion: '<S313>/Data Type Conversion2'
         *  Product: '<S400>/Divide'
         */
        ExM_mfTrbEstimWoutSat_MP = (localfractionTmp_0d / (((Float32)
          AirEfc_pRef_C) * 8.0F)) * localDataTypeConversion1_k;

        /* Switch: '<S405>/Switch' incorporates:
         *  Constant: '<S313>/Cste_17'
         *  RelationalOperator: '<S405>/UpperRelop'
         */
        if (ExM_mfTrbEstimWoutSat_MP < 0.0F) {
          localSwitch2_g = 0.0F;
        } else {
          localSwitch2_g = ExM_mfTrbEstimWoutSat_MP;
        }

        /* Switch: '<S405>/Switch2' incorporates:
         *  RelationalOperator: '<S405>/LowerRelop1'
         */
        if (ExM_mfTrbEstimWoutSat_MP > localDataTypeConversion2_d) {
          localSwitch2_g = localDataTypeConversion2_d;
        }

        /* Sum: '<S313>/Add' */
        localB->Merge1 = localDataTypeConversion2_d - localSwitch2_g;

        /* SignalConversion: '<S313>/Signal Conversion' */
        localB->Merge2 = localSwitch2_g;

        /* end of Outputs for SubSystem: '<S255>/F03_MFR_through_turbine_and_WG' */

        /* SignalConversion: '<S255>/Signal Conversion' */
        ExM_pTrbUs = localInterpolationUsingPreloo_o;
      }

      /* end of Outputs for SubSystem: '<S199>/F03_Turbine_pressure_model_without_WG_position' */

      /* SignalConversion: '<S199>/Signal Conversion' */
      localB->Merge4 = ExM_pTrbUs;
      break;

     case 3:
      /* Outputs for atomic SubSystem: '<S197>/F01_Catalyst_P_model' */

      /* Outputs for atomic SubSystem: '<S201>/F01_TWC_System_and_Brick_specific_parameters' */

      /* Outputs for atomic SubSystem: '<S202>/F01_Mean_TWC_Temperature_Calculation' */

      /* Product: '<S207>/Divide' incorporates:
       *  Constant: '<S204>/Constant'
       *  Sum: '<S204>/Sum'
       */
      ExM_tTWCMv = (ExM_tDsPrev + ExM_tUsPrev) / 2.0F;

      /* end of Outputs for SubSystem: '<S202>/F01_Mean_TWC_Temperature_Calculation' */

      /* Outputs for atomic SubSystem: '<S202>/F02_Axis_interpolation' */

      /* DataTypeConversion: '<S210>/OutDTConv' incorporates:
       *  Constant: '<S210>/offset'
       *  Constant: '<S210>/one_on_slope'
       *  Product: '<S210>/Product4'
       *  Sum: '<S210>/Add1'
       */
      localtmp_0 = (ExM_tTWCMv - 223.0F) * 32.0F;
      if (localtmp_0 < 65536.0F) {
        if (localtmp_0 >= 0.0F) {
          locallocalOutDTConv_nj = (UInt16)localtmp_0;
        } else {
          locallocalOutDTConv_nj = 0U;
        }
      } else {
        locallocalOutDTConv_nj = MAX_uint16_T;
      }

      /* PreLookup: '<S208>/Prelookup' */
      localPrelookup_o1_a = plook_s32u16f_bincpa(locallocalOutDTConv_nj,
        (&(ExM_tTWCMvTCorPresLossTWC_A[0])), 7U, &localPrelookup_o2_c,
        &localDW->Prelookup_DWORK1_m);

      /* PreLookup: '<S209>/Prelookup' */
      locali = plook_s32u16f_bincpa(rtu_ExM_mfEgWoutEGR,
        (&(ExM_mfEgFacPresLossTWC_A[0])), 7U, &localPrelookup_o2_h,
        &localDW->Prelookup_DWORK1_g);

      /* end of Outputs for SubSystem: '<S202>/F02_Axis_interpolation' */

      /* Outputs for atomic SubSystem: '<S202>/F03_Brick_specific_parameters_calculation' */

      /* SwitchCase: '<S206>/Switch Case' incorporates:
       *  ActionPort: '<S211>/Action Port'
       *  ActionPort: '<S212>/Action Port'
       *  ActionPort: '<S213>/Action Port'
       *  SubSystem: '<S206>/F01_First_TWC_Parameters'
       *  SubSystem: '<S206>/F02_Second_TWC_Parameters'
       *  SubSystem: '<S206>/F03_Third_TWC_Parameters'
       */
      switch (ExM_stNbTypElementPres) {
       case 1:
        /* Interpolation_n-D: '<S215>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_h;
        localfractionTmp_0d = intrp1d_iu16p7ff_s32f_la(locali,
          localfractionTmp_0d, (&(ExM_facPresLossTWC1_T[0])), 7U);

        /* SignalConversion: '<S211>/Signal Conversion' */
        ExM_facPresLossTWC = localfractionTmp_0d;

        /* Interpolation_n-D: '<S216>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_c;
        localfractionTmp_0d = intrp1d_iu16n5ff_s32f_la_n(localPrelookup_o1_a,
          localfractionTmp_0d, (&(ExM_tCorPresLossTWC1_T[0])), 7U);

        /* SignalConversion: '<S211>/Signal Conversion1' */
        ExM_tCorPresLossTWC = localfractionTmp_0d;
        break;

       case 2:
        /* Interpolation_n-D: '<S217>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_h;
        localfractionTmp_0d = intrp1d_iu16p7ff_s32f_la(locali,
          localfractionTmp_0d, (&(ExM_facPresLossTWC2_T[0])), 7U);

        /* SignalConversion: '<S212>/Signal Conversion1' */
        ExM_facPresLossTWC = localfractionTmp_0d;

        /* Interpolation_n-D: '<S218>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_c;
        localfractionTmp_0d = intrp1d_iu16n5ff_s32f_la_n(localPrelookup_o1_a,
          localfractionTmp_0d, (&(ExM_tCorPresLossTWC2_T[0])), 7U);

        /* SignalConversion: '<S212>/Signal Conversion2' */
        ExM_tCorPresLossTWC = localfractionTmp_0d;
        break;

       case 3:
        /* Interpolation_n-D: '<S219>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_h;
        localfractionTmp_0d = intrp1d_iu16p7ff_s32f_la(locali,
          localfractionTmp_0d, (&(ExM_facPresLossTWC3_T[0])), 7U);

        /* SignalConversion: '<S213>/Signal Conversion1' */
        ExM_facPresLossTWC = localfractionTmp_0d;

        /* Interpolation_n-D: '<S220>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_c;
        localfractionTmp_0d = intrp1d_iu16n5ff_s32f_la_n(localPrelookup_o1_a,
          localfractionTmp_0d, (&(ExM_tCorPresLossTWC3_T[0])), 7U);

        /* SignalConversion: '<S213>/Signal Conversion2' */
        ExM_tCorPresLossTWC = localfractionTmp_0d;
        break;
      }

      /* end of Outputs for SubSystem: '<S202>/F03_Brick_specific_parameters_calculation' */

      /* end of Outputs for SubSystem: '<S201>/F01_TWC_System_and_Brick_specific_parameters' */

      /* Outputs for atomic SubSystem: '<S201>/F02_Upstream_TWC_pressure_estimation' */

      /* Product: '<S223>/Product4' incorporates:
       *  Constant: '<S203>/Constant3'
       *  Constant: '<S223>/offset'
       *  Constant: '<S223>/one_on_slope'
       *  Product: '<S224>/Divide'
       *  Product: '<S225>/Divide'
       *  Product: '<S226>/Divide'
       *  Sum: '<S203>/Add2'
       *  Sum: '<S223>/Add1'
       */
      localPrelookup_o2_l = ((((ExM_facPresLossTWC * ExM_tCorPresLossTWC) * 2.0F)
        + (ExM_pDs * ExM_pDs)) - 1.0E+009F) * 1.666666662E-006F;

      /* DataTypeConversion: '<S223>/OutDTConv' */
      localtmp_0 = localPrelookup_o2_l;
      if (localtmp_0 < 65536.0F) {
        if (localtmp_0 >= 0.0F) {
          locallocalOutDTConv_nj = (UInt16)localtmp_0;
        } else {
          locallocalOutDTConv_nj = 0U;
        }
      } else {
        locallocalOutDTConv_nj = MAX_uint16_T;
      }

      /* PreLookup: '<S222>/Prelookup' */
      localPrelookup_o1_g = plook_s32u16f_bincpa(locallocalOutDTConv_nj,
        (&(ExM_pSqPresSqrt_A[0])), 15U, &localPrelookup_o2_l,
        &localDW->Prelookup_DWORK1);

      /* Interpolation_n-D: '<S221>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localPrelookup_o2_l;
      ExM_pOxCatUs = intrp1d_iu16p3ff_s32f_la(localPrelookup_o1_g,
        localfractionTmp_0d, (&(ExM_pSqrt_T[0])), 15U);

      /* SignalConversion: '<S203>/Signal Conversion' */
      localB->Merge4 = ExM_pOxCatUs;

      /* end of Outputs for SubSystem: '<S201>/F02_Upstream_TWC_pressure_estimation' */

      /* end of Outputs for SubSystem: '<S197>/F01_Catalyst_P_model' */
      break;

     default:
      /* SignalConversion: '<S200>/Signal Conversion1' */
      ExM_pVoidUs = ExM_pDs;

      /* SignalConversion: '<S200>/Signal Conversion' */
      localB->Merge4 = ExM_pVoidUs;
      break;
    }
  } else {
    /* DataTypeConversion: '<S189>/Data Type Conversion2' */
    localB->Merge4 = ((Float32)rtu_ExM_pMes) * 8.0F;

    /* Inport: '<S189>/ExM_mfWgEstim_irv' */
    localB->Merge1 = rtu_ExM_mfWgEstim_irv;

    /* Inport: '<S189>/ExM_mfTrbEstimSat_irv' */
    localB->Merge2 = rtu_ExM_mfTrbEstimSat_irv;
  }

  /* end of Outputs for SubSystem: '<S138>/F04_Pressure_models' */

  /* Outputs for atomic SubSystem: '<S138>/F06_Update_pressure_array' */

  /* Sum: '<S408>/Add' incorporates:
   *  Constant: '<S190>/Cste_24'
   *  Constant: '<S408>/Constant1'
   *  Sum: '<S190>/Sum1'
   */
  localDataTypeConversion4_p3 = locallocalDataTypeConversion1_m;

  /* Assignment: '<S408>/Assignment' incorporates:
   *  Constant: '<S408>/Constant'
   *  MinMax: '<S408>/MinMax'
   */
  for (locali = 0; locali < 12; locali++) {
    localTmpSignalConversionAtSelec[locali] = ExM_prm_pEgInterPrev[(locali)];
  }

  localTmpSignalConversionAtSelec[(SInt32)rt_MIN(localDataTypeConversion4_p3,
    11U)] = localB->Merge4;

  /* SignalConversion: '<S190>/Signal Conversion3' */
  for (locali = 0; locali < 12; locali++) {
    rty_ExM_prm_pEgInter[(locali)] = localTmpSignalConversionAtSelec[locali];
  }

  /* end of Outputs for SubSystem: '<S138>/F06_Update_pressure_array' */

  /* SignalConversion: '<S138>/Signal Conversion1' */
  (*rty_ExM_pUs) = localB->Merge4;

  /* SignalConversion: '<S138>/Signal Conversion2' */
  (*rty_ExM_noIdxPres) = locallocalDataTypeConversion1_m;
}

/* Start for exported function: RE_ExMGslT2_006_TEV */
void RE_ExMGslT2_006_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_ExM2P'
   */
}

/* Output and update for exported function: RE_ExMGslT2_006_TEV */
void RE_ExMGslT2_006_TEV(void)
{
  /* local block i/o variables */
  Boolean localAutosarServer;
  Float32 localSwitch2;
  Float32 localProduct;
  Float32 localProduct4_fh;
  Float32 localProduct4_i;
  Float32 localmax;
  Float32 localDataTypeConversion1_cu;
  Float32 localAssignment_m[12];
  SInt32 localAdd_o;
  UInt16 localTmpSignalConversionAtExM_p[12];
  UInt16 localOutDTConv_a;
  UInt16 localSwitch_f5;
  Float32 localSwitch_g_0[12];
  UInt16 localOutDTConv_n_0;
  SInt32 locali;
  Float32 locallocalAssignment_m;
  Float32d localtmp;
  UInt32 localqY;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_ExM2P'
   */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_mfEgWoutEGR_INPUTOutport2' incorporates:
   *  Inport: '<Root>/ExM_mfEgWoutEGR_INPUT'
   */
  Rte_Read_R_ExM_mfEgWoutEGR_ExM_mfEgWoutEGR
    (&ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_prm_pEgFltPrevOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_pEgFlt_INPUT'
   */
  Rte_Read_R_ExM_prm_pEgFlt_ExM_prm_pEgFlt(&localTmpSignalConversionAtExM_p);

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  for (locali = 0; locali < 12; locali++) {
    ExM_prm_pEgFltPrev[(locali)] = ((Float32)
      localTmpSignalConversionAtExM_p[locali]) * 8.0F;
  }

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S135>/autosar_irv_read8' */

  /* S-Function Block: <S135>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8_j =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stElement_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S135>/autosar_irv_read7' */

  /* S-Function Block: <S135>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7_g =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stElement_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S135>/autosar_irv_read6' */

  /* S-Function Block: <S135>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6_f =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stElement_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S135>/autosar_irv_read5' */

  /* S-Function Block: <S135>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5_ks =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stElement_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S135>/autosar_irv_read4' */

  /* S-Function Block: <S135>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_o =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stElement_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S135>/autosar_irv_read3' */

  /* S-Function Block: <S135>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_a =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stElement_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S135>/autosar_irv_read2' */

  /* S-Function Block: <S135>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_pl =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stElement_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S135>/autosar_irv_read1' */

  /* S-Function Block: <S135>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_c =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stElement_01_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S136>/autosar_irv_read8' */

  /* S-Function Block: <S136>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8_k =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stNbTypElement_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S136>/autosar_irv_read7' */

  /* S-Function Block: <S136>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7_n =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stNbTypElement_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S136>/autosar_irv_read6' */

  /* S-Function Block: <S136>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6_k =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stNbTypElement_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S136>/autosar_irv_read5' */

  /* S-Function Block: <S136>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5_m =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stNbTypElement_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S136>/autosar_irv_read4' */

  /* S-Function Block: <S136>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_f =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stNbTypElement_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S136>/autosar_irv_read3' */

  /* S-Function Block: <S136>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_i =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stNbTypElement_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S136>/autosar_irv_read2' */

  /* S-Function Block: <S136>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_o =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stNbTypElement_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S136>/autosar_irv_read1' */

  /* S-Function Block: <S136>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_dh =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_stNbTypElement_01_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read12' */

  /* S-Function Block: <S137>/autosar_irv_read12 */
  ExMGslT2_B.autosar_irv_read12_ia =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_12_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read11' */

  /* S-Function Block: <S137>/autosar_irv_read11 */
  ExMGslT2_B.autosar_irv_read11_a =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_11_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read10' */

  /* S-Function Block: <S137>/autosar_irv_read10 */
  ExMGslT2_B.autosar_irv_read10_o =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_10_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read9' */

  /* S-Function Block: <S137>/autosar_irv_read9 */
  ExMGslT2_B.autosar_irv_read9_g =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_09_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read8' */

  /* S-Function Block: <S137>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8_g =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read7' */

  /* S-Function Block: <S137>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7_b =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read6' */

  /* S-Function Block: <S137>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6_n =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read5' */

  /* S-Function Block: <S137>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5_p =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read4' */

  /* S-Function Block: <S137>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_g =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read3' */

  /* S-Function Block: <S137>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_l =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read2' */

  /* S-Function Block: <S137>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_j =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S137>/autosar_irv_read1' */

  /* S-Function Block: <S137>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_f =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_tEgRaw_01_irv();

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&ExMGslT2_B.TmpSignalConversionAtExt_nEng_p);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtTrbAct_rOpTrbActOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rOpTrbAct'
   */
  Rte_Read_R_TrbAct_rOpTrbAct_TrbAct_rOpTrbAct
    (&ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkOpInVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (&ExMGslT2_B.TmpSignalConversionAtEngM_agCkO);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsExVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (&ExMGslT2_B.TmpSignalConversionAtEngM_agCkC);

  /* S-Function (sfun_autosar_clientop): '<S140>/AutosarServer' */
  Rte_Call_R_FRM_bTrbAct_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S140>/Not' */
  ExMGslT2_B.Not_m = !localAutosarServer;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_pMesOutport2' incorporates:
   *  Inport: '<Root>/ExM_pMes'
   */
  Rte_Read_R_ExM_pMes_ExM_pMes(&ExMGslT2_B.TmpSignalConversionAtExM_pMesOu);

  /* S-Function (sfun_autosar_clientop): '<S139>/AutosarServer' */
  Rte_Call_R_FRM_bSenPres_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S139>/Not' */
  ExMGslT2_B.Not_k = !localAutosarServer;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read1' */

  /* S-Function Block: <S133>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_d =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_01_irv();

  /* DataTypeDuplicate Block: '<S157>/Data Type Duplicate'
   *
   * Regarding '<S157>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S157>/Data Type Duplicate1'
   *
   * Regarding '<S157>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read2' */

  /* S-Function Block: <S133>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_l =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read3' */

  /* S-Function Block: <S133>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_m =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read4' */

  /* S-Function Block: <S133>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_e =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read5' */

  /* S-Function Block: <S133>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5_c =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read6' */

  /* S-Function Block: <S133>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6_p =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read7' */

  /* S-Function Block: <S133>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7_f =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read8' */

  /* S-Function Block: <S133>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8_d3 =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read9' */

  /* S-Function Block: <S133>/autosar_irv_read9 */
  ExMGslT2_B.autosar_irv_read9_p =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_09_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read10' */

  /* S-Function Block: <S133>/autosar_irv_read10 */
  ExMGslT2_B.autosar_irv_read10_c =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_10_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read11' */

  /* S-Function Block: <S133>/autosar_irv_read11 */
  ExMGslT2_B.autosar_irv_read11_ne =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_11_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S133>/autosar_irv_read12' */

  /* S-Function Block: <S133>/autosar_irv_read12 */
  ExMGslT2_B.autosar_irv_read12_n =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_12_irv();

  /* SignalConversion: '<S6>/Signal Conversion3' */
  ExM_prm_pEgPrev[0] = ExMGslT2_B.autosar_irv_read1_d;
  ExM_prm_pEgPrev[1] = ExMGslT2_B.autosar_irv_read2_l;
  ExM_prm_pEgPrev[2] = ExMGslT2_B.autosar_irv_read3_m;
  ExM_prm_pEgPrev[3] = ExMGslT2_B.autosar_irv_read4_e;
  ExM_prm_pEgPrev[4] = ExMGslT2_B.autosar_irv_read5_c;
  ExM_prm_pEgPrev[5] = ExMGslT2_B.autosar_irv_read6_p;
  ExM_prm_pEgPrev[6] = ExMGslT2_B.autosar_irv_read7_f;
  ExM_prm_pEgPrev[7] = ExMGslT2_B.autosar_irv_read8_d3;
  ExM_prm_pEgPrev[8] = ExMGslT2_B.autosar_irv_read9_p;
  ExM_prm_pEgPrev[9] = ExMGslT2_B.autosar_irv_read10_c;
  ExM_prm_pEgPrev[10] = ExMGslT2_B.autosar_irv_read11_ne;
  ExM_prm_pEgPrev[11] = ExMGslT2_B.autosar_irv_read12_n;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S6>/autosar_irv_read1' */

  /* S-Function Block: <S6>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_h =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_mfWgEstim_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S6>/autosar_irv_read4' */

  /* S-Function Block: <S6>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_i =
    Rte_IrvRead_RE_ExMGslT2_006_TEV_ExM_mfTrbEstimSat_irv();

  /* SignalConversion: '<S6>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&ExMGslT2_B.TmpSignalConversionAtInM_mfEGRE);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_mfEgTotOutport2' incorporates:
   *  Inport: '<Root>/ExM_mfEgTot'
   */
  Rte_Read_R_ExM_mfEgTot_ExM_mfEgTot(&ExMGslT2_B.TmpSignalConversionAtExM_mfEgTo);

  /* Embedded MATLAB: '<S6>/F01__ExM2P_Task_sceduler' incorporates:
   *  SubSystem: '<S6>/F02_ExM2P_Library_input'
   *  SubSystem: '<S6>/F03_ExM2P_Library_output'
   *  SubSystem: '<S6>/LibP'
   */
  /* Embedded MATLAB Function 'ExMGslT2/F02_ExM2P/F01__ExM2P_Task_sceduler': '<S130>:1' */
  /* '<S130>:1:5' */

  /* Outputs for atomic SubSystem: '<S131>/F01_Exhaust_MFR_without_EGR_calculation' */

  /* Switch: '<S155>/Switch' incorporates:
   *  Constant: '<S155>/Cste_1'
   *  Constant: '<S155>/ExM_bAcvEGRHPCtl_C'
   */
  if (ExM_bAcvEGRHPCtl_C) {
    localSwitch_f5 = 0U;
  } else {
    localSwitch_f5 = ExMGslT2_B.TmpSignalConversionAtInM_mfEGRE;
  }

  /* Sum: '<S155>/Sum3' */
  locali = ExMGslT2_B.TmpSignalConversionAtExM_mfEgTo - localSwitch_f5;
  if (locali <= 0) {
    localSwitch_f5 = 0U;
  } else {
    localSwitch_f5 = (UInt16)locali;
  }

  /* end of Outputs for SubSystem: '<S131>/F01_Exhaust_MFR_without_EGR_calculation' */

  /* Outputs for atomic SubSystem: '<S131>/F02_Input_conditions_for_pressure_library' */

  /* DataTypeConversion: '<S156>/Data Type Conversion1' */
  localDataTypeConversion1_cu = ((Float32)
    ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi) * 8.0F;

  /* SignalConversion: '<S157>/TmpSignal ConversionAtAssignmentInport1' */
  localAssignment_m[0] = ExMGslT2_B.autosar_irv_read1_d;
  localAssignment_m[1] = ExMGslT2_B.autosar_irv_read2_l;
  localAssignment_m[2] = ExMGslT2_B.autosar_irv_read3_m;
  localAssignment_m[3] = ExMGslT2_B.autosar_irv_read4_e;
  localAssignment_m[4] = ExMGslT2_B.autosar_irv_read5_c;
  localAssignment_m[5] = ExMGslT2_B.autosar_irv_read6_p;
  localAssignment_m[6] = ExMGslT2_B.autosar_irv_read7_f;
  localAssignment_m[7] = ExMGslT2_B.autosar_irv_read8_d3;
  localAssignment_m[8] = ExMGslT2_B.autosar_irv_read9_p;
  localAssignment_m[9] = ExMGslT2_B.autosar_irv_read10_c;
  localAssignment_m[10] = ExMGslT2_B.autosar_irv_read11_ne;
  localAssignment_m[11] = ExMGslT2_B.autosar_irv_read12_n;

  /* Assignment: '<S157>/Assignment' incorporates:
   *  Constant: '<S157>/Constant'
   *  MinMax: '<S157>/MinMax'
   */
  localAssignment_m[8] = localDataTypeConversion1_cu;

  /* SignalConversion: '<S156>/Signal Conversion1' */
  ExM_pUs = localDataTypeConversion1_cu;

  /* SignalConversion: '<S156>/Signal Conversion3' */
  for (locali = 0; locali < 12; locali++) {
    ExM_prm_pEgInter[(locali)] = localAssignment_m[locali];
  }

  /* Sum: '<S156>/Sum' incorporates:
   *  Constant: '<S156>/Cste_2'
   *  Constant: '<S156>/Cste_3'
   */
  ExM_noIdxPres = 8U;

  /* end of Outputs for SubSystem: '<S131>/F02_Input_conditions_for_pressure_library' */
  /* '<S130>:1:7' */
  ExMGslT2_LibP(&ExM_noIdxPres, (&(ExM_prm_pEgInter[0])), &ExM_pUs,
                ExMGslT2_B.Not_k, ExMGslT2_B.autosar_irv_read1_c,
                ExMGslT2_B.autosar_irv_read2_pl, ExMGslT2_B.autosar_irv_read3_a,
                ExMGslT2_B.autosar_irv_read4_o, ExMGslT2_B.autosar_irv_read5_ks,
                ExMGslT2_B.autosar_irv_read6_f, ExMGslT2_B.autosar_irv_read7_g,
                ExMGslT2_B.autosar_irv_read8_j, ExMGslT2_B.autosar_irv_read1_dh,
                ExMGslT2_B.autosar_irv_read2_o, ExMGslT2_B.autosar_irv_read3_i,
                ExMGslT2_B.autosar_irv_read4_f, ExMGslT2_B.autosar_irv_read5_m,
                ExMGslT2_B.autosar_irv_read6_k, ExMGslT2_B.autosar_irv_read7_n,
                ExMGslT2_B.autosar_irv_read8_k, ExMGslT2_B.autosar_irv_read1_f,
                ExMGslT2_B.autosar_irv_read2_j, ExMGslT2_B.autosar_irv_read3_l,
                ExMGslT2_B.autosar_irv_read4_g, ExMGslT2_B.autosar_irv_read5_p,
                ExMGslT2_B.autosar_irv_read6_n, ExMGslT2_B.autosar_irv_read7_b,
                ExMGslT2_B.autosar_irv_read8_g, ExMGslT2_B.autosar_irv_read9_g,
                ExMGslT2_B.autosar_irv_read10_o, ExMGslT2_B.autosar_irv_read11_a,
                ExMGslT2_B.autosar_irv_read12_ia,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
                ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi, ExMGslT2_B.Not_m,
                ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp,
                ExMGslT2_B.TmpSignalConversionAtExt_nEng_p,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkO,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkC,
                ExMGslT2_B.TmpSignalConversionAtExM_pMesOu,
                ExMGslT2_B.autosar_irv_read1_h, ExMGslT2_B.autosar_irv_read4_i,
                (&(ExM_prm_pEgPrev[0])), &ExM_pUs, &ExM_noIdxPres,
                (&(ExM_prm_pEgInter[0])), &ExMGslT2_B.LibP, &ExMGslT2_DWork.LibP);

  /* '<S130>:1:8' */
  ExMGslT2_LibP(&ExM_noIdxPres, (&(ExM_prm_pEgInter[0])), &ExM_pUs,
                ExMGslT2_B.Not_k, ExMGslT2_B.autosar_irv_read1_c,
                ExMGslT2_B.autosar_irv_read2_pl, ExMGslT2_B.autosar_irv_read3_a,
                ExMGslT2_B.autosar_irv_read4_o, ExMGslT2_B.autosar_irv_read5_ks,
                ExMGslT2_B.autosar_irv_read6_f, ExMGslT2_B.autosar_irv_read7_g,
                ExMGslT2_B.autosar_irv_read8_j, ExMGslT2_B.autosar_irv_read1_dh,
                ExMGslT2_B.autosar_irv_read2_o, ExMGslT2_B.autosar_irv_read3_i,
                ExMGslT2_B.autosar_irv_read4_f, ExMGslT2_B.autosar_irv_read5_m,
                ExMGslT2_B.autosar_irv_read6_k, ExMGslT2_B.autosar_irv_read7_n,
                ExMGslT2_B.autosar_irv_read8_k, ExMGslT2_B.autosar_irv_read1_f,
                ExMGslT2_B.autosar_irv_read2_j, ExMGslT2_B.autosar_irv_read3_l,
                ExMGslT2_B.autosar_irv_read4_g, ExMGslT2_B.autosar_irv_read5_p,
                ExMGslT2_B.autosar_irv_read6_n, ExMGslT2_B.autosar_irv_read7_b,
                ExMGslT2_B.autosar_irv_read8_g, ExMGslT2_B.autosar_irv_read9_g,
                ExMGslT2_B.autosar_irv_read10_o, ExMGslT2_B.autosar_irv_read11_a,
                ExMGslT2_B.autosar_irv_read12_ia,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
                ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi, ExMGslT2_B.Not_m,
                ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp,
                ExMGslT2_B.TmpSignalConversionAtExt_nEng_p,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkO,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkC,
                ExMGslT2_B.TmpSignalConversionAtExM_pMesOu,
                ExMGslT2_B.autosar_irv_read1_h, ExMGslT2_B.autosar_irv_read4_i,
                (&(ExM_prm_pEgPrev[0])), &ExM_pUs, &ExM_noIdxPres,
                (&(ExM_prm_pEgInter[0])), &ExMGslT2_B.LibP, &ExMGslT2_DWork.LibP);

  /* '<S130>:1:9' */
  ExMGslT2_LibP(&ExM_noIdxPres, (&(ExM_prm_pEgInter[0])), &ExM_pUs,
                ExMGslT2_B.Not_k, ExMGslT2_B.autosar_irv_read1_c,
                ExMGslT2_B.autosar_irv_read2_pl, ExMGslT2_B.autosar_irv_read3_a,
                ExMGslT2_B.autosar_irv_read4_o, ExMGslT2_B.autosar_irv_read5_ks,
                ExMGslT2_B.autosar_irv_read6_f, ExMGslT2_B.autosar_irv_read7_g,
                ExMGslT2_B.autosar_irv_read8_j, ExMGslT2_B.autosar_irv_read1_dh,
                ExMGslT2_B.autosar_irv_read2_o, ExMGslT2_B.autosar_irv_read3_i,
                ExMGslT2_B.autosar_irv_read4_f, ExMGslT2_B.autosar_irv_read5_m,
                ExMGslT2_B.autosar_irv_read6_k, ExMGslT2_B.autosar_irv_read7_n,
                ExMGslT2_B.autosar_irv_read8_k, ExMGslT2_B.autosar_irv_read1_f,
                ExMGslT2_B.autosar_irv_read2_j, ExMGslT2_B.autosar_irv_read3_l,
                ExMGslT2_B.autosar_irv_read4_g, ExMGslT2_B.autosar_irv_read5_p,
                ExMGslT2_B.autosar_irv_read6_n, ExMGslT2_B.autosar_irv_read7_b,
                ExMGslT2_B.autosar_irv_read8_g, ExMGslT2_B.autosar_irv_read9_g,
                ExMGslT2_B.autosar_irv_read10_o, ExMGslT2_B.autosar_irv_read11_a,
                ExMGslT2_B.autosar_irv_read12_ia,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
                ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi, ExMGslT2_B.Not_m,
                ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp,
                ExMGslT2_B.TmpSignalConversionAtExt_nEng_p,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkO,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkC,
                ExMGslT2_B.TmpSignalConversionAtExM_pMesOu,
                ExMGslT2_B.autosar_irv_read1_h, ExMGslT2_B.autosar_irv_read4_i,
                (&(ExM_prm_pEgPrev[0])), &ExM_pUs, &ExM_noIdxPres,
                (&(ExM_prm_pEgInter[0])), &ExMGslT2_B.LibP, &ExMGslT2_DWork.LibP);

  /* '<S130>:1:10' */
  ExMGslT2_LibP(&ExM_noIdxPres, (&(ExM_prm_pEgInter[0])), &ExM_pUs,
                ExMGslT2_B.Not_k, ExMGslT2_B.autosar_irv_read1_c,
                ExMGslT2_B.autosar_irv_read2_pl, ExMGslT2_B.autosar_irv_read3_a,
                ExMGslT2_B.autosar_irv_read4_o, ExMGslT2_B.autosar_irv_read5_ks,
                ExMGslT2_B.autosar_irv_read6_f, ExMGslT2_B.autosar_irv_read7_g,
                ExMGslT2_B.autosar_irv_read8_j, ExMGslT2_B.autosar_irv_read1_dh,
                ExMGslT2_B.autosar_irv_read2_o, ExMGslT2_B.autosar_irv_read3_i,
                ExMGslT2_B.autosar_irv_read4_f, ExMGslT2_B.autosar_irv_read5_m,
                ExMGslT2_B.autosar_irv_read6_k, ExMGslT2_B.autosar_irv_read7_n,
                ExMGslT2_B.autosar_irv_read8_k, ExMGslT2_B.autosar_irv_read1_f,
                ExMGslT2_B.autosar_irv_read2_j, ExMGslT2_B.autosar_irv_read3_l,
                ExMGslT2_B.autosar_irv_read4_g, ExMGslT2_B.autosar_irv_read5_p,
                ExMGslT2_B.autosar_irv_read6_n, ExMGslT2_B.autosar_irv_read7_b,
                ExMGslT2_B.autosar_irv_read8_g, ExMGslT2_B.autosar_irv_read9_g,
                ExMGslT2_B.autosar_irv_read10_o, ExMGslT2_B.autosar_irv_read11_a,
                ExMGslT2_B.autosar_irv_read12_ia,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
                ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi, ExMGslT2_B.Not_m,
                ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp,
                ExMGslT2_B.TmpSignalConversionAtExt_nEng_p,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkO,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkC,
                ExMGslT2_B.TmpSignalConversionAtExM_pMesOu,
                ExMGslT2_B.autosar_irv_read1_h, ExMGslT2_B.autosar_irv_read4_i,
                (&(ExM_prm_pEgPrev[0])), &ExM_pUs, &ExM_noIdxPres,
                (&(ExM_prm_pEgInter[0])), &ExMGslT2_B.LibP, &ExMGslT2_DWork.LibP);

  /* '<S130>:1:11' */
  ExMGslT2_LibP(&ExM_noIdxPres, (&(ExM_prm_pEgInter[0])), &ExM_pUs,
                ExMGslT2_B.Not_k, ExMGslT2_B.autosar_irv_read1_c,
                ExMGslT2_B.autosar_irv_read2_pl, ExMGslT2_B.autosar_irv_read3_a,
                ExMGslT2_B.autosar_irv_read4_o, ExMGslT2_B.autosar_irv_read5_ks,
                ExMGslT2_B.autosar_irv_read6_f, ExMGslT2_B.autosar_irv_read7_g,
                ExMGslT2_B.autosar_irv_read8_j, ExMGslT2_B.autosar_irv_read1_dh,
                ExMGslT2_B.autosar_irv_read2_o, ExMGslT2_B.autosar_irv_read3_i,
                ExMGslT2_B.autosar_irv_read4_f, ExMGslT2_B.autosar_irv_read5_m,
                ExMGslT2_B.autosar_irv_read6_k, ExMGslT2_B.autosar_irv_read7_n,
                ExMGslT2_B.autosar_irv_read8_k, ExMGslT2_B.autosar_irv_read1_f,
                ExMGslT2_B.autosar_irv_read2_j, ExMGslT2_B.autosar_irv_read3_l,
                ExMGslT2_B.autosar_irv_read4_g, ExMGslT2_B.autosar_irv_read5_p,
                ExMGslT2_B.autosar_irv_read6_n, ExMGslT2_B.autosar_irv_read7_b,
                ExMGslT2_B.autosar_irv_read8_g, ExMGslT2_B.autosar_irv_read9_g,
                ExMGslT2_B.autosar_irv_read10_o, ExMGslT2_B.autosar_irv_read11_a,
                ExMGslT2_B.autosar_irv_read12_ia,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
                ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi, ExMGslT2_B.Not_m,
                ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp,
                ExMGslT2_B.TmpSignalConversionAtExt_nEng_p,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkO,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkC,
                ExMGslT2_B.TmpSignalConversionAtExM_pMesOu,
                ExMGslT2_B.autosar_irv_read1_h, ExMGslT2_B.autosar_irv_read4_i,
                (&(ExM_prm_pEgPrev[0])), &ExM_pUs, &ExM_noIdxPres,
                (&(ExM_prm_pEgInter[0])), &ExMGslT2_B.LibP, &ExMGslT2_DWork.LibP);

  /* '<S130>:1:12' */
  ExMGslT2_LibP(&ExM_noIdxPres, (&(ExM_prm_pEgInter[0])), &ExM_pUs,
                ExMGslT2_B.Not_k, ExMGslT2_B.autosar_irv_read1_c,
                ExMGslT2_B.autosar_irv_read2_pl, ExMGslT2_B.autosar_irv_read3_a,
                ExMGslT2_B.autosar_irv_read4_o, ExMGslT2_B.autosar_irv_read5_ks,
                ExMGslT2_B.autosar_irv_read6_f, ExMGslT2_B.autosar_irv_read7_g,
                ExMGslT2_B.autosar_irv_read8_j, ExMGslT2_B.autosar_irv_read1_dh,
                ExMGslT2_B.autosar_irv_read2_o, ExMGslT2_B.autosar_irv_read3_i,
                ExMGslT2_B.autosar_irv_read4_f, ExMGslT2_B.autosar_irv_read5_m,
                ExMGslT2_B.autosar_irv_read6_k, ExMGslT2_B.autosar_irv_read7_n,
                ExMGslT2_B.autosar_irv_read8_k, ExMGslT2_B.autosar_irv_read1_f,
                ExMGslT2_B.autosar_irv_read2_j, ExMGslT2_B.autosar_irv_read3_l,
                ExMGslT2_B.autosar_irv_read4_g, ExMGslT2_B.autosar_irv_read5_p,
                ExMGslT2_B.autosar_irv_read6_n, ExMGslT2_B.autosar_irv_read7_b,
                ExMGslT2_B.autosar_irv_read8_g, ExMGslT2_B.autosar_irv_read9_g,
                ExMGslT2_B.autosar_irv_read10_o, ExMGslT2_B.autosar_irv_read11_a,
                ExMGslT2_B.autosar_irv_read12_ia,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
                ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi, ExMGslT2_B.Not_m,
                ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp,
                ExMGslT2_B.TmpSignalConversionAtExt_nEng_p,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkO,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkC,
                ExMGslT2_B.TmpSignalConversionAtExM_pMesOu,
                ExMGslT2_B.autosar_irv_read1_h, ExMGslT2_B.autosar_irv_read4_i,
                (&(ExM_prm_pEgPrev[0])), &ExM_pUs, &ExM_noIdxPres,
                (&(ExM_prm_pEgInter[0])), &ExMGslT2_B.LibP, &ExMGslT2_DWork.LibP);

  /* '<S130>:1:13' */
  ExMGslT2_LibP(&ExM_noIdxPres, (&(ExM_prm_pEgInter[0])), &ExM_pUs,
                ExMGslT2_B.Not_k, ExMGslT2_B.autosar_irv_read1_c,
                ExMGslT2_B.autosar_irv_read2_pl, ExMGslT2_B.autosar_irv_read3_a,
                ExMGslT2_B.autosar_irv_read4_o, ExMGslT2_B.autosar_irv_read5_ks,
                ExMGslT2_B.autosar_irv_read6_f, ExMGslT2_B.autosar_irv_read7_g,
                ExMGslT2_B.autosar_irv_read8_j, ExMGslT2_B.autosar_irv_read1_dh,
                ExMGslT2_B.autosar_irv_read2_o, ExMGslT2_B.autosar_irv_read3_i,
                ExMGslT2_B.autosar_irv_read4_f, ExMGslT2_B.autosar_irv_read5_m,
                ExMGslT2_B.autosar_irv_read6_k, ExMGslT2_B.autosar_irv_read7_n,
                ExMGslT2_B.autosar_irv_read8_k, ExMGslT2_B.autosar_irv_read1_f,
                ExMGslT2_B.autosar_irv_read2_j, ExMGslT2_B.autosar_irv_read3_l,
                ExMGslT2_B.autosar_irv_read4_g, ExMGslT2_B.autosar_irv_read5_p,
                ExMGslT2_B.autosar_irv_read6_n, ExMGslT2_B.autosar_irv_read7_b,
                ExMGslT2_B.autosar_irv_read8_g, ExMGslT2_B.autosar_irv_read9_g,
                ExMGslT2_B.autosar_irv_read10_o, ExMGslT2_B.autosar_irv_read11_a,
                ExMGslT2_B.autosar_irv_read12_ia,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
                ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi, ExMGslT2_B.Not_m,
                ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp,
                ExMGslT2_B.TmpSignalConversionAtExt_nEng_p,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkO,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkC,
                ExMGslT2_B.TmpSignalConversionAtExM_pMesOu,
                ExMGslT2_B.autosar_irv_read1_h, ExMGslT2_B.autosar_irv_read4_i,
                (&(ExM_prm_pEgPrev[0])), &ExM_pUs, &ExM_noIdxPres,
                (&(ExM_prm_pEgInter[0])), &ExMGslT2_B.LibP, &ExMGslT2_DWork.LibP);

  /* '<S130>:1:14' */
  ExMGslT2_LibP(&ExM_noIdxPres, (&(ExM_prm_pEgInter[0])), &ExM_pUs,
                ExMGslT2_B.Not_k, ExMGslT2_B.autosar_irv_read1_c,
                ExMGslT2_B.autosar_irv_read2_pl, ExMGslT2_B.autosar_irv_read3_a,
                ExMGslT2_B.autosar_irv_read4_o, ExMGslT2_B.autosar_irv_read5_ks,
                ExMGslT2_B.autosar_irv_read6_f, ExMGslT2_B.autosar_irv_read7_g,
                ExMGslT2_B.autosar_irv_read8_j, ExMGslT2_B.autosar_irv_read1_dh,
                ExMGslT2_B.autosar_irv_read2_o, ExMGslT2_B.autosar_irv_read3_i,
                ExMGslT2_B.autosar_irv_read4_f, ExMGslT2_B.autosar_irv_read5_m,
                ExMGslT2_B.autosar_irv_read6_k, ExMGslT2_B.autosar_irv_read7_n,
                ExMGslT2_B.autosar_irv_read8_k, ExMGslT2_B.autosar_irv_read1_f,
                ExMGslT2_B.autosar_irv_read2_j, ExMGslT2_B.autosar_irv_read3_l,
                ExMGslT2_B.autosar_irv_read4_g, ExMGslT2_B.autosar_irv_read5_p,
                ExMGslT2_B.autosar_irv_read6_n, ExMGslT2_B.autosar_irv_read7_b,
                ExMGslT2_B.autosar_irv_read8_g, ExMGslT2_B.autosar_irv_read9_g,
                ExMGslT2_B.autosar_irv_read10_o, ExMGslT2_B.autosar_irv_read11_a,
                ExMGslT2_B.autosar_irv_read12_ia,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
                ExMGslT2_B.TmpSignalConversionAtUsThrM_pAi, ExMGslT2_B.Not_m,
                ExMGslT2_B.TmpSignalConversionAtTrbAct_rOp,
                ExMGslT2_B.TmpSignalConversionAtExt_nEng_p,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkO,
                ExMGslT2_B.TmpSignalConversionAtEngM_agCkC,
                ExMGslT2_B.TmpSignalConversionAtExM_pMesOu,
                ExMGslT2_B.autosar_irv_read1_h, ExMGslT2_B.autosar_irv_read4_i,
                (&(ExM_prm_pEgPrev[0])), &ExM_pUs, &ExM_noIdxPres,
                (&(ExM_prm_pEgInter[0])), &ExMGslT2_B.LibP, &ExMGslT2_DWork.LibP);

  /* '<S130>:1:16' */

  /* DataTypeConversion: '<S132>/Data Type Conversion1' incorporates:
   *  Constant: '<S132>/ExM_pExMnfEstimMin_C'
   */
  localSwitch2 = ((Float32)ExM_pExMnfEstimMin_C) * 8.0F;

  /* DataTypeConversion: '<S132>/Data Type Conversion2' incorporates:
   *  Constant: '<S132>/ExM_pDsTrbEstimMin_C'
   */
  localProduct = ((Float32)ExM_pDsTrbEstimMin_C) * 8.0F;

  /* DataTypeConversion: '<S132>/Data Type Conversion6' */
  for (locali = 0; locali < 12; locali++) {
    ExMGslT2_B.DataTypeConversion6[(locali)] = ExM_prm_pEgInter[(locali)];
  }

  /* Sum: '<S132>/Sum1' incorporates:
   *  Constant: '<S132>/Cste_25'
   *  Constant: '<S132>/ExM_noSelPresExMnf_C'
   */
  locali = ExM_noSelPresExMnf_C;
  localqY = ((UInt32)locali) - 1U;
  if (localqY > ((UInt32)locali)) {
    localqY = 0U;
  }

  localAdd_o = (SInt32)localqY;

  /* MinMax: '<S158>/MinMax' incorporates:
   *  Constant: '<S158>/Constant'
   */
  localAdd_o = (SInt32)rt_MIN((UInt32)localAdd_o, 11U);

  /* PreLookup: '<S161>/Prelookup' */
  locali = plook_s32u16f_bincpa(ExMGslT2_B.TmpSignalConversionAtExM_mfEg_n,
    (&(ExM_mfEgFlt_A[0])), 15U, &localProduct4_fh,
    &ExMGslT2_DWork.Prelookup_DWORK1_a);

  /* Interpolation_n-D: '<S160>/Interpolation Using Prelookup3' */
  localDataTypeConversion1_cu = localProduct4_fh;
  ExM_facFltPres_MP = intrp1d_iu16n16ff_s32f_la_n(locali,
    localDataTypeConversion1_cu, (&(ExM_facFltPres_T[0])), 15U);

  /* Sum: '<S132>/Sum7' incorporates:
   *  Constant: '<S132>/Cste_1'
   */
  localDataTypeConversion1_cu = 1.0F - ExM_facFltPres_MP;
  for (locali = 0; locali < 12; locali++) {
    /* Sum: '<S132>/Sum6' incorporates:
     *  Product: '<S167>/Divide'
     *  Product: '<S168>/Divide'
     */
    locallocalAssignment_m = (ExM_prm_pEgFltPrev[(locali)] *
      localDataTypeConversion1_cu) + (ExM_facFltPres_MP * ExM_prm_pEgInter
      [(locali)]);

    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S132>/ExM_bPresFlt_C'
     */
    if (ExM_bPresFlt_C) {
      localSwitch_g_0[locali] = ExM_prm_pEgInter[(locali)];
    } else {
      localSwitch_g_0[locali] = locallocalAssignment_m;
    }

    localAssignment_m[locali] = locallocalAssignment_m;
  }

  /* Selector: '<S158>/Selector' */
  localProduct4_fh = localSwitch_g_0[localAdd_o];

  /* Sum: '<S132>/Sum5' incorporates:
   *  Constant: '<S132>/Cste_26'
   *  Constant: '<S132>/ExM_noSelPresDsTrb_C'
   */
  locali = ExM_noSelPresDsTrb_C;
  localqY = ((UInt32)locali) - 1U;
  if (localqY > ((UInt32)locali)) {
    localqY = 0U;
  }

  localAdd_o = (SInt32)localqY;

  /* Selector: '<S159>/Selector' incorporates:
   *  Constant: '<S159>/Constant'
   *  MinMax: '<S159>/MinMax'
   */
  localProduct4_i = localSwitch_g_0[(SInt32)rt_MIN((UInt32)localAdd_o, 11U)];

  /* MinMax: '<S132>/MinMax' */
  localmax = rt_MAXf(localProduct4_i, localProduct);

  /* MinMax: '<S132>/MinMax1' */
  localDataTypeConversion1_cu = localProduct4_fh;
  localDataTypeConversion1_cu = rt_MAXf(localDataTypeConversion1_cu,
    localSwitch2);

  /* Switch: '<S162>/Switch' incorporates:
   *  Constant: '<S162>/ '
   *  Constant: '<S162>/ 1'
   *  Constant: '<S162>/constant'
   *  RelationalOperator: '<S162>/Relational Operator'
   */
  if (localmax >= 0.0F) {
    localSwitch2 = 3.051757813E-005F;
  } else {
    localSwitch2 = -3.051757813E-005F;
  }

  /* Switch: '<S162>/Switch2' incorporates:
   *  Abs: '<S162>/Abs'
   *  Constant: '<S162>/ '
   *  RelationalOperator: '<S162>/Relational Operator1'
   */
  if (!(localmax < 3.051757813E-005F)) {
    localSwitch2 = localmax;
  }

  /* Product: '<S162>/Product' */
  localSwitch2 = localDataTypeConversion1_cu / localSwitch2;

  /* Switch: '<S170>/Switch' incorporates:
   *  Constant: '<S162>/SatMinDiv'
   *  RelationalOperator: '<S170>/UpperRelop'
   */
  if (localSwitch2 < -1.0E+005F) {
    localProduct = -1.0E+005F;
  } else {
    localProduct = localSwitch2;
  }

  /* Switch: '<S170>/Switch2' incorporates:
   *  Constant: '<S162>/SatMaxDiv'
   *  RelationalOperator: '<S170>/LowerRelop1'
   */
  if (localSwitch2 > 1.0E+005F) {
    localProduct = 1.0E+005F;
  }

  /* Switch: '<S162>/Switch1' incorporates:
   *  Constant: '<S162>/Constant2'
   *  RelationalOperator: '<S162>/Relational Operator2'
   */
  if (localSwitch2 != localSwitch2) {
    localmax = 0.0F;
  } else {
    localmax = localProduct;
  }

  /* Switch: '<S163>/Switch' incorporates:
   *  Constant: '<S163>/ '
   *  Constant: '<S163>/ 1'
   *  Constant: '<S163>/constant'
   *  RelationalOperator: '<S163>/Relational Operator'
   */
  if (localmax >= 0.0F) {
    localProduct = 3.051757813E-005F;
  } else {
    localProduct = -3.051757813E-005F;
  }

  /* Switch: '<S163>/Switch2' incorporates:
   *  Abs: '<S163>/Abs'
   *  Constant: '<S163>/ '
   *  RelationalOperator: '<S163>/Relational Operator1'
   */
  if (!(ACTEMS_FabsF(localmax) < 3.051757813E-005F)) {
    localProduct = localmax;
  }

  /* Product: '<S163>/Product' incorporates:
   *  Constant: '<S132>/Cste_29'
   */
  localProduct = 1.0F / localProduct;

  /* Switch: '<S172>/Switch' incorporates:
   *  Constant: '<S163>/SatMinDiv'
   *  RelationalOperator: '<S172>/UpperRelop'
   */
  if (localProduct < -1.0E+005F) {
    localSwitch2 = -1.0E+005F;
  } else {
    localSwitch2 = localProduct;
  }

  /* Switch: '<S172>/Switch2' incorporates:
   *  Constant: '<S163>/SatMaxDiv'
   *  RelationalOperator: '<S172>/LowerRelop1'
   */
  if (localProduct > 1.0E+005F) {
    localSwitch2 = 1.0E+005F;
  }

  /* Switch: '<S163>/Switch1' incorporates:
   *  Constant: '<S163>/Constant2'
   *  RelationalOperator: '<S163>/Relational Operator2'
   */
  if (localProduct != localProduct) {
    localSwitch2 = 0.0F;
  }

  /* Product: '<S164>/Product4' incorporates:
   *  Constant: '<S164>/offset'
   *  Constant: '<S164>/one_on_slope'
   *  Sum: '<S164>/Add1'
   */
  for (locali = 0; locali < 12; locali++) {
    localAssignment_m[locali] *= 0.125F;
  }

  /* Sum: '<S165>/Add1' incorporates:
   *  Constant: '<S165>/offset'
   */
  localDataTypeConversion1_cu = localProduct4_fh;

  /* Product: '<S165>/Product4' incorporates:
   *  Constant: '<S165>/one_on_slope'
   */
  localProduct4_fh = 0.125F * localDataTypeConversion1_cu;

  /* DataTypeConversion: '<S165>/OutDTConv' */
  locallocalAssignment_m = localProduct4_fh;
  if (locallocalAssignment_m < 65536.0F) {
    if (locallocalAssignment_m >= 0.0F) {
      localOutDTConv_n_0 = (UInt16)locallocalAssignment_m;
    } else {
      localOutDTConv_n_0 = 0U;
    }
  } else {
    localOutDTConv_n_0 = MAX_uint16_T;
  }

  /* Product: '<S166>/Product4' incorporates:
   *  Constant: '<S166>/offset'
   *  Constant: '<S166>/one_on_slope'
   *  Sum: '<S166>/Add1'
   */
  localProduct4_i *= 0.125F;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write1' */

  /* S-Function Block: <S134>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_01_irv
    (ExMGslT2_B.DataTypeConversion6[0]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write10' */

  /* S-Function Block: <S134>/autosar_irv_write10 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_10_irv
    (ExMGslT2_B.DataTypeConversion6[9]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write11' */

  /* S-Function Block: <S134>/autosar_irv_write11 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_11_irv
    (ExMGslT2_B.DataTypeConversion6[10]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write12' */

  /* S-Function Block: <S134>/autosar_irv_write12 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_12_irv
    (ExMGslT2_B.DataTypeConversion6[11]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write2' */

  /* S-Function Block: <S134>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_02_irv
    (ExMGslT2_B.DataTypeConversion6[1]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write3' */

  /* S-Function Block: <S134>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_03_irv
    (ExMGslT2_B.DataTypeConversion6[2]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write4' */

  /* S-Function Block: <S134>/autosar_irv_write4 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_04_irv
    (ExMGslT2_B.DataTypeConversion6[3]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write5' */

  /* S-Function Block: <S134>/autosar_irv_write5 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_05_irv
    (ExMGslT2_B.DataTypeConversion6[4]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write6' */

  /* S-Function Block: <S134>/autosar_irv_write6 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_06_irv
    (ExMGslT2_B.DataTypeConversion6[5]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write7' */

  /* S-Function Block: <S134>/autosar_irv_write7 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_07_irv
    (ExMGslT2_B.DataTypeConversion6[6]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write8' */

  /* S-Function Block: <S134>/autosar_irv_write8 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_08_irv
    (ExMGslT2_B.DataTypeConversion6[7]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S134>/autosar_irv_write9' */

  /* S-Function Block: <S134>/autosar_irv_write9 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_prm_pEgRaw_09_irv
    (ExMGslT2_B.DataTypeConversion6[8]);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S173>/autosar_testpoint1' */

  /* S-Function Block: <S173>/autosar_testpoint1 */
  ExM_prm_pEgRaw_01_IRV_MP = ExMGslT2_B.DataTypeConversion6[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S174>/autosar_testpoint1' */

  /* S-Function Block: <S174>/autosar_testpoint1 */
  ExM_prm_pEgRaw_10_IRV_MP = ExMGslT2_B.DataTypeConversion6[9];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S175>/autosar_testpoint1' */

  /* S-Function Block: <S175>/autosar_testpoint1 */
  ExM_prm_pEgRaw_11_IRV_MP = ExMGslT2_B.DataTypeConversion6[10];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S176>/autosar_testpoint1' */

  /* S-Function Block: <S176>/autosar_testpoint1 */
  ExM_prm_pEgRaw_12_IRV_MP = ExMGslT2_B.DataTypeConversion6[11];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S177>/autosar_testpoint1' */

  /* S-Function Block: <S177>/autosar_testpoint1 */
  ExM_prm_pEgRaw_02_IRV_MP = ExMGslT2_B.DataTypeConversion6[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S178>/autosar_testpoint1' */

  /* S-Function Block: <S178>/autosar_testpoint1 */
  ExM_prm_pEgRaw_03_IRV_MP = ExMGslT2_B.DataTypeConversion6[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S179>/autosar_testpoint1' */

  /* S-Function Block: <S179>/autosar_testpoint1 */
  ExM_prm_pEgRaw_04_IRV_MP = ExMGslT2_B.DataTypeConversion6[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S180>/autosar_testpoint1' */

  /* S-Function Block: <S180>/autosar_testpoint1 */
  ExM_prm_pEgRaw_05_IRV_MP = ExMGslT2_B.DataTypeConversion6[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S181>/autosar_testpoint1' */

  /* S-Function Block: <S181>/autosar_testpoint1 */
  ExM_prm_pEgRaw_06_IRV_MP = ExMGslT2_B.DataTypeConversion6[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S182>/autosar_testpoint1' */

  /* S-Function Block: <S182>/autosar_testpoint1 */
  ExM_prm_pEgRaw_07_IRV_MP = ExMGslT2_B.DataTypeConversion6[6];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S183>/autosar_testpoint1' */

  /* S-Function Block: <S183>/autosar_testpoint1 */
  ExM_prm_pEgRaw_08_IRV_MP = ExMGslT2_B.DataTypeConversion6[7];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S184>/autosar_testpoint1' */

  /* S-Function Block: <S184>/autosar_testpoint1 */
  ExM_prm_pEgRaw_09_IRV_MP = ExMGslT2_B.DataTypeConversion6[8];

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S6>/autosar_irv_write1' */

  /* S-Function Block: <S6>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_mfTrbEstimSat_irv(ExMGslT2_B.LibP.Merge2);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S6>/autosar_irv_write2' */

  /* S-Function Block: <S6>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_006_TEV_ExM_mfWgEstim_irv(ExMGslT2_B.LibP.Merge1);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S144>/autosar_testpoint1' */

  /* S-Function Block: <S144>/autosar_testpoint1 */
  ExM_mfTrbEstimSat_IRV_MP = ExMGslT2_B.LibP.Merge2;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S145>/autosar_testpoint1' */

  /* S-Function Block: <S145>/autosar_testpoint1 */
  ExM_mfWgEstim_IRV_MP = ExMGslT2_B.LibP.Merge1;

  /* DataTypeConversion: '<S141>/OutDTConv' incorporates:
   *  Constant: '<S141>/offset'
   *  Constant: '<S141>/one_on_slope'
   *  Product: '<S141>/Product4'
   *  Sum: '<S141>/Add1'
   */
  locallocalAssignment_m = 8192.0F * localmax;
  if (locallocalAssignment_m < 65536.0F) {
    if (locallocalAssignment_m >= 0.0F) {
      localOutDTConv_a = (UInt16)locallocalAssignment_m;
    } else {
      localOutDTConv_a = 0U;
    }
  } else {
    localOutDTConv_a = MAX_uint16_T;
  }

  /* Product: '<S142>/Product4' incorporates:
   *  Constant: '<S142>/offset'
   *  Constant: '<S142>/one_on_slope'
   *  Sum: '<S142>/Add1'
   */
  localDataTypeConversion1_cu = 8192.0F * localSwitch2;

  /* Product: '<S143>/Product4' incorporates:
   *  Constant: '<S143>/offset'
   *  Constant: '<S143>/one_on_slope'
   *  Sum: '<S143>/Add1'
   */
  for (locali = 0; locali < 12; locali++) {
    localSwitch_g_0[locali] *= 0.125F;
  }

  /* Switch: '<S148>/Switch' incorporates:
   *  Constant: '<S148>/Byp_Fonction_SC'
   *  Constant: '<S148>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localSwitch_f5 = ExM_mfEgWoutEGR_B;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_mfEgWoutEGRInport2' */
  Rte_Write_P_ExM_mfEgWoutEGR_ExM_mfEgWoutEGR(localSwitch_f5);

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S146>/Byp_Fonction_SC'
   *  Constant: '<S146>/Int_BypC'
   *  DataTypeConversion: '<S146>/Data Type Conversion'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localSwitch_f5 = ExM_mfTrbEstimSat_B;
  } else {
    localtmp = ACTEMS_LdexpF((Float32d)ExMGslT2_B.LibP.Merge2, 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localSwitch_f5 = (UInt16)localtmp;
      } else {
        localSwitch_f5 = 0U;
      }
    } else {
      localSwitch_f5 = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_mfTrbEstimSatInport2' */
  Rte_Write_P_ExM_mfTrbEstimSat_ExM_mfTrbEstimSat(localSwitch_f5);

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S149>/Byp_Fonction_SC'
   *  Constant: '<S149>/Int_BypC'
   *  DataTypeConversion: '<S149>/Data Type Conversion'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localSwitch_f5 = ExM_mfWgEstim_B;
  } else {
    localtmp = ACTEMS_LdexpF((Float32d)ExMGslT2_B.LibP.Merge1, 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localSwitch_f5 = (UInt16)localtmp;
      } else {
        localSwitch_f5 = 0U;
      }
    } else {
      localSwitch_f5 = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_mfWgEstimInport2' */
  Rte_Write_P_ExM_mfWgEstim_ExM_mfWgEstim(localSwitch_f5);

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S151>/Byp_Fonction_SC'
   *  Constant: '<S151>/Int_BypC'
   *  DataTypeConversion: '<S166>/OutDTConv'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localSwitch_f5 = ExM_pDsTrbEstimSI_B;
  } else if (localProduct4_i < 65536.0F) {
    if (localProduct4_i >= 0.0F) {
      localSwitch_f5 = (UInt16)localProduct4_i;
    } else {
      localSwitch_f5 = 0U;
    }
  } else {
    localSwitch_f5 = MAX_uint16_T;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_pDsTrbEstimSIInport2' */
  Rte_Write_P_ExM_pDsTrbEstimSI_ExM_pDsTrbEstimSI(localSwitch_f5);

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Byp_Fonction_SC'
   *  Constant: '<S150>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv_n_0 = ExM_pExMnfEstim_B;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_pExMnfEstimInport2' */
  Rte_Write_P_ExM_pExMnfEstim_ExM_pExMnfEstim(localOutDTConv_n_0);

  /* Switch: '<S153>/Switch' incorporates:
   *  Constant: '<S153>/Byp_Fonction_SC'
   *  Constant: '<S153>/Int_BypC'
   *  DataTypeConversion: '<S164>/OutDTConv'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localTmpSignalConversionAtExM_p[locali] = ExM_prm_pEgFlt_B[(locali)];
    } else {
      if (localAssignment_m[locali] < 65536.0F) {
        if (localAssignment_m[locali] >= 0.0F) {
          localSwitch_f5 = (UInt16)localAssignment_m[locali];
        } else {
          localSwitch_f5 = 0U;
        }
      } else {
        localSwitch_f5 = MAX_uint16_T;
      }

      localTmpSignalConversionAtExM_p[locali] = localSwitch_f5;
    }
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_prm_pEgFltInport2' */
  Rte_Write_P_ExM_prm_pEgFlt_ExM_prm_pEgFlt(&localTmpSignalConversionAtExM_p);

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S152>/Byp_Fonction_SC'
   *  Constant: '<S152>/Int_BypC'
   *  DataTypeConversion: '<S143>/OutDTConv'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localTmpSignalConversionAtExM_p[locali] = ExM_prm_pEg_B[(locali)];
    } else {
      if (localSwitch_g_0[locali] < 65536.0F) {
        if (localSwitch_g_0[locali] >= 0.0F) {
          localSwitch_f5 = (UInt16)localSwitch_g_0[locali];
        } else {
          localSwitch_f5 = 0U;
        }
      } else {
        localSwitch_f5 = MAX_uint16_T;
      }

      localTmpSignalConversionAtExM_p[locali] = localSwitch_f5;
    }
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_prm_pEgInport2' */
  Rte_Write_P_ExM_prm_pEg_ExM_prm_pEg(&localTmpSignalConversionAtExM_p);

  /* Switch: '<S154>/Switch' incorporates:
   *  Constant: '<S154>/Byp_Fonction_SC'
   *  Constant: '<S154>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv_a = ExM_rPresTrbEstim_B;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_rPresTrbEstimInport2' */
  Rte_Write_P_ExM_rPresTrbEstim_ExM_rPresTrbEstim(localOutDTConv_a);

  /* Switch: '<S147>/Switch' incorporates:
   *  Constant: '<S147>/Byp_Fonction_SC'
   *  Constant: '<S147>/Int_BypC'
   *  DataTypeConversion: '<S142>/OutDTConv'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localSwitch_f5 = ExM_rPresTrbEstimIvs_B;
  } else if (localDataTypeConversion1_cu < 65536.0F) {
    if (localDataTypeConversion1_cu >= 0.0F) {
      localSwitch_f5 = (UInt16)localDataTypeConversion1_cu;
    } else {
      localSwitch_f5 = 0U;
    }
  } else {
    localSwitch_f5 = MAX_uint16_T;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtExM_rPresTrbEstimIvsInport2' */
  Rte_Write_P_ExM_rPresTrbEstimIvs_ExM_rPresTrbEstimIvs(localSwitch_f5);
}

/*
 * Output and update for enable system:
 *    '<S567>/Reset du filtre'
 *    '<S602>/Reset du filtre'
 *    '<S637>/Reset du filtre'
 */
void ExMGslT2_Resetdufiltre(Boolean rtu_0, Float32 rtu_INIT_OUTPUT,
  rtB_Resetdufiltre_ExMGslT2 *localB)
{
  if (rtu_0) {
    /* DataTypeConversion: '<S570>/Data Type Conversion' */
    localB->DataTypeConversion = rtu_INIT_OUTPUT;
  }
}

/* Output and update for function-call system: '<S7>/LibT' */
void ExMGslT2_LibT(const UInt8 *rtu_ExM_noIdxTPrev, const Float32
                   rtu_ExM_prm_tEgOxCPrev[3], const UInt8
                   *rtu_ExM_noIdxOxCPrev, Boolean rtu_FRM_bSenTEg, Float32
                   rtu_ExM_prm_pEg, Float32 rtu_ExM_prm_pEg_l, Float32
                   rtu_ExM_prm_pEg_i, Float32 rtu_ExM_prm_pEg_d, Float32
                   rtu_ExM_prm_pEg_n, Float32 rtu_ExM_prm_pEg_in, Float32
                   rtu_ExM_prm_pEg_p, Float32 rtu_ExM_prm_pEg_b, Float32
                   rtu_ExM_prm_pEg_e, Float32 rtu_ExM_prm_pEg_c, Float32
                   rtu_ExM_prm_pEg_h, Float32 rtu_ExM_prm_pEg_o, const Float32
                   rtu_ExM_prm_tWallInterPrev[12], UInt8 rtu_ExM_prm_stElement,
                   UInt8 rtu_ExM_prm_stElement_c, UInt8
                   rtu_ExM_prm_stElement_d, UInt8 rtu_ExM_prm_stElement_f,
                   UInt8 rtu_ExM_prm_stElement_k, UInt8
                   rtu_ExM_prm_stElement_f4, UInt8 rtu_ExM_prm_stElement_k2,
                   UInt8 rtu_ExM_prm_stElement_g, UInt8
                   rtu_ExM_prm_stNbTypElement, UInt8
                   rtu_ExM_prm_stNbTypElement_m, UInt8
                   rtu_ExM_prm_stNbTypElement_h, UInt8
                   rtu_ExM_prm_stNbTypElement_f, UInt8
                   rtu_ExM_prm_stNbTypElement_n, UInt8
                   rtu_ExM_prm_stNbTypElement_e, UInt8
                   rtu_ExM_prm_stNbTypElement_o, UInt8
                   rtu_ExM_prm_stNbTypElement_d, Float32 rtu_ExM_prm_tEgPrev,
                   Float32 rtu_ExM_prm_tEgPrev_e, Float32
                   rtu_ExM_prm_tEgPrev_l, Float32 rtu_ExM_prm_tEgPrev_i,
                   Float32 rtu_ExM_prm_tEgPrev_h, Float32
                   rtu_ExM_prm_tEgPrev_g, Float32 rtu_ExM_prm_tEgPrev_m,
                   Float32 rtu_ExM_prm_tEgPrev_d, Float32
                   rtu_ExM_prm_tEgPrev_f, Float32 rtu_ExM_prm_tEgPrev_p,
                   Float32 rtu_ExM_prm_tEgPrev_ld, Float32
                   rtu_ExM_prm_tEgPrev_ij, SInt16 rtu_Ext_tCoMes, SInt8
                   rtu_Ext_tAir, const Float32 *rtu_ExM_tEgInp, UInt16
                   rtu_ExM_mfEgWoutEGR, UInt16 rtu_Veh_spdVeh, UInt8
                   rtu_Ext_rSpdFanAct, UInt16 rtu_Ext_nEng, Float32
                   rtu_ExM_mfTrbEstimSatRef, Float32 rtu_ExM_mfWgEstimRef,
                   UInt16 rtu_FARSp_rMixtCylSp, UInt16 rtu_EngM_mfAirCor,
                   UInt8 rtu_InjSys_noCylCutOff, Boolean
                   rtu_AfuA_bInvldEthRat, UInt8 rtu_AfuA_rEthWiExct, UInt16
                   rtu_IgSys_rDynIgSpEfc, Boolean rtu_ThMgt_bPosnFSF,
                   Boolean rtu_Ext_bAdFanAct, UInt8 rtu_Ext_stTypInjSysCf,
                   UInt16 rtu_EngM_mfAirScvCor, Float32 rtu_ExM_rMixtInp,
                   UInt16 rtu_ExM_tEgMes, const Float32
                   rtu_ExM_prm_tEgInterPrev[12], Float32 rty_ExM_prm_tEgOxC[3],
                   UInt8 *rty_ExM_noIdxOxC, Float32 *rty_ExM_tEgOut, UInt8 *
                   rty_ExM_noIdxT, Float32 rty_ExM_prm_tEgInter[12], Float32
                   rty_ExM_prm_tWallInter[12], rtB_LibT_ExMGslT2 *localB,
                   rtDW_LibT_ExMGslT2 *localDW)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion1_pi;
  Float32 localDataTypeConversion1_ar;
  Float32 localDataTypeConversion1_l;
  Boolean localLogicalOperator_bg;
  Boolean localLogicalOperator_go;
  Boolean localLogicalOperator_k;
  Boolean localLogicalOperator1_c;
  SInt32 localDataTypeConversion2_ij;
  Float32 localTmpSignalConversionAtSel_b[12];
  SInt32 localDataTypeConversion1_a;
  SInt32 localDataTypeConversion4_pk;
  Float32 localAssignment_g[3];
  Float32 localAssignment_a[12];
  Boolean localRelationalOperator_jg;
  Float32 localInterpolationUsingPrelo_gc;
  Float32 localDataTypeConversion2_b;
  Float32 localDataTypeConversion3_cj;
  Float32 localDataTypeConversion5;
  Float32 localInterpolationUsingPreloo_i;
  Float32 localInterpolationUsingPrelo_ba;
  Float32 localPrelookup_o2_or;
  Float32 localPrelookup_o2_n;
  Float32 localPrelookup_o2_ax;
  Float32 localfractionTmp_0d;
  Float32 localfrac[2];
  Float32 localPrelookup_o2_oo;
  Float32 localfractionTmp_1d;
  SInt32 localPrelookup_o1_px;
  SInt32 localbpIndex[2];
  SInt32 localPrelookup_o1_n0;
  Float32 localPrelookup_o2_ch;
  Float32 localDataTypeConversion1_lv;
  Float32 localPrelookup_o2_o;
  Float32 localfrac_0[2];
  Float32 localPrelookup_o2_i;
  SInt32 localPrelookup_o1_p;
  SInt32 localbpIndex_0[2];
  SInt32 localPrelookup_o1_m3;
  Float32 localfrac_1[2];
  SInt32 localbpIndex_1[2];
  Float32 localPrelookup_o2_hi;
  Float32 localPrelookup_o2_hu;
  Float32 localPrelookup_o2_gx;
  Float32 localfrac_2[2];
  Float32 localPrelookup_o2_gx1;
  SInt32 localbpIndex_2[2];
  Float32 localfrac_3[2];
  SInt32 localbpIndex_3[2];
  Float32 localPrelookup_o2_gy;
  Float32 localfrac_4[2];
  SInt32 localbpIndex_4[2];
  Float32 localInterpolationUsingPrelo_me;
  UInt8 localtmp[8];
  UInt16 locallocalDataTypeConversion1_a;
  UInt16 locallocalDataTypeConversion1_0;
  UInt32 localqY;
  UInt8 locallocalDataTypeConversion3_a;

  /* SignalConversion: '<S421>/Signal Conversion2' */
  ExM_noIdxTPrev = (*rtu_ExM_noIdxTPrev);

  /* Outputs for atomic SubSystem: '<S421>/F01_Element_input_conditions_for_temperature_models' */

  /* DataTypeConversion: '<S485>/Data Type Conversion2' */
  localDataTypeConversion2_ij = ExM_noIdxTPrev;

  /* Sum: '<S485>/Sum' incorporates:
   *  Constant: '<S485>/Cste_54'
   */
  localqY = (UInt32)(1 + localDataTypeConversion2_ij);

  /* DataTypeConversion: '<S485>/Data Type Conversion' */
  if (localqY > 255U) {
    (*rty_ExM_noIdxT) = MAX_uint8_T;
  } else {
    (*rty_ExM_noIdxT) = (UInt8)localqY;
  }

  /* SignalConversion: '<S494>/TmpSignal ConversionAtSelectorInport1' */
  localTmpSignalConversionAtSel_b[0] = rtu_ExM_prm_pEg;
  localTmpSignalConversionAtSel_b[1] = rtu_ExM_prm_pEg_l;
  localTmpSignalConversionAtSel_b[2] = rtu_ExM_prm_pEg_i;
  localTmpSignalConversionAtSel_b[3] = rtu_ExM_prm_pEg_d;
  localTmpSignalConversionAtSel_b[4] = rtu_ExM_prm_pEg_n;
  localTmpSignalConversionAtSel_b[5] = rtu_ExM_prm_pEg_in;
  localTmpSignalConversionAtSel_b[6] = rtu_ExM_prm_pEg_p;
  localTmpSignalConversionAtSel_b[7] = rtu_ExM_prm_pEg_b;
  localTmpSignalConversionAtSel_b[8] = rtu_ExM_prm_pEg_e;
  localTmpSignalConversionAtSel_b[9] = rtu_ExM_prm_pEg_c;
  localTmpSignalConversionAtSel_b[10] = rtu_ExM_prm_pEg_h;
  localTmpSignalConversionAtSel_b[11] = rtu_ExM_prm_pEg_o;

  /* Selector: '<S494>/Selector' incorporates:
   *  Constant: '<S494>/Constant'
   *  MinMax: '<S494>/MinMax'
   */
  ExM_pOut = localTmpSignalConversionAtSel_b[(SInt32)rt_MIN(localqY, 11U)];

  /* Selector: '<S495>/Selector' incorporates:
   *  Constant: '<S495>/Constant'
   *  MinMax: '<S495>/MinMax'
   */
  ExM_tWallPrev = rtu_ExM_prm_tWallInterPrev[rt_MIN(localqY, 11U)];

  /* Selector: '<S496>/Selector' incorporates:
   *  Constant: '<S496>/Constant'
   *  MinMax: '<S496>/MinMax'
   *  SignalConversion: '<S496>/TmpSignal ConversionAtSelectorInport1'
   */
  localtmp[0] = rtu_ExM_prm_stElement;
  localtmp[1] = rtu_ExM_prm_stElement_c;
  localtmp[2] = rtu_ExM_prm_stElement_d;
  localtmp[3] = rtu_ExM_prm_stElement_f;
  localtmp[4] = rtu_ExM_prm_stElement_k;
  localtmp[5] = rtu_ExM_prm_stElement_f4;
  localtmp[6] = rtu_ExM_prm_stElement_k2;
  localtmp[7] = rtu_ExM_prm_stElement_g;
  ExM_stElementT = localtmp[(SInt32)rt_MIN((UInt32)
    localDataTypeConversion2_ij, 7U)];

  /* Selector: '<S497>/Selector' incorporates:
   *  Constant: '<S497>/Constant'
   *  MinMax: '<S497>/MinMax'
   *  SignalConversion: '<S497>/TmpSignal ConversionAtSelectorInport1'
   */
  localtmp[0] = rtu_ExM_prm_stNbTypElement;
  localtmp[1] = rtu_ExM_prm_stNbTypElement_m;
  localtmp[2] = rtu_ExM_prm_stNbTypElement_h;
  localtmp[3] = rtu_ExM_prm_stNbTypElement_f;
  localtmp[4] = rtu_ExM_prm_stNbTypElement_n;
  localtmp[5] = rtu_ExM_prm_stNbTypElement_e;
  localtmp[6] = rtu_ExM_prm_stNbTypElement_o;
  localtmp[7] = rtu_ExM_prm_stNbTypElement_d;
  ExM_stNbTypElementT = localtmp[(SInt32)rt_MIN((UInt32)
    localDataTypeConversion2_ij, 7U)];

  /* Selector: '<S498>/Selector' incorporates:
   *  Constant: '<S498>/Constant'
   *  MinMax: '<S498>/MinMax'
   */
  ExM_pInp = localTmpSignalConversionAtSel_b[(SInt32)rt_MIN((UInt32)
    localDataTypeConversion2_ij, 11U)];

  /* SignalConversion: '<S499>/TmpSignal ConversionAtSelectorInport1' */
  localTmpSignalConversionAtSel_b[0] = rtu_ExM_prm_tEgPrev;
  localTmpSignalConversionAtSel_b[1] = rtu_ExM_prm_tEgPrev_e;
  localTmpSignalConversionAtSel_b[2] = rtu_ExM_prm_tEgPrev_l;
  localTmpSignalConversionAtSel_b[3] = rtu_ExM_prm_tEgPrev_i;
  localTmpSignalConversionAtSel_b[4] = rtu_ExM_prm_tEgPrev_h;
  localTmpSignalConversionAtSel_b[5] = rtu_ExM_prm_tEgPrev_g;
  localTmpSignalConversionAtSel_b[6] = rtu_ExM_prm_tEgPrev_m;
  localTmpSignalConversionAtSel_b[7] = rtu_ExM_prm_tEgPrev_d;
  localTmpSignalConversionAtSel_b[8] = rtu_ExM_prm_tEgPrev_f;
  localTmpSignalConversionAtSel_b[9] = rtu_ExM_prm_tEgPrev_p;
  localTmpSignalConversionAtSel_b[10] = rtu_ExM_prm_tEgPrev_ld;
  localTmpSignalConversionAtSel_b[11] = rtu_ExM_prm_tEgPrev_ij;

  /* Selector: '<S499>/Selector' incorporates:
   *  Constant: '<S499>/Constant'
   *  MinMax: '<S499>/MinMax'
   */
  ExM_tEgOutPrev = localTmpSignalConversionAtSel_b[(SInt32)rt_MIN(localqY, 11U)];

  /* Selector: '<S500>/Selector' incorporates:
   *  Constant: '<S500>/Constant'
   *  MinMax: '<S500>/MinMax'
   */
  ExM_tEgInpPrev = localTmpSignalConversionAtSel_b[(SInt32)rt_MIN((UInt32)
    localDataTypeConversion2_ij, 11U)];

  /* end of Outputs for SubSystem: '<S421>/F01_Element_input_conditions_for_temperature_models' */

  /* SignalConversion: '<S421>/Signal Conversion4' */
  ExM_prm_tEgOxCPrev[0] = rtu_ExM_prm_tEgOxCPrev[0];
  ExM_prm_tEgOxCPrev[1] = rtu_ExM_prm_tEgOxCPrev[1];
  ExM_prm_tEgOxCPrev[2] = rtu_ExM_prm_tEgOxCPrev[2];

  /* SignalConversion: '<S421>/Signal Conversion3' */
  ExM_noIdxOxCPrev = (*rtu_ExM_noIdxOxCPrev);

  /* Outputs for atomic SubSystem: '<S421>/F05_OxC_spec_5' */

  /* DataTypeConversion: '<S493>/Data Type Conversion1' */
  localqY = ExM_noIdxOxCPrev;

  /* Selector: '<S800>/Selector' incorporates:
   *  Constant: '<S800>/Constant'
   *  MinMax: '<S800>/MinMax'
   */
  ExM_tEgOxCOutPrev = ExM_prm_tEgOxCPrev[rt_MIN(localqY, 2U)];

  /* end of Outputs for SubSystem: '<S421>/F05_OxC_spec_5' */

  /* Logic: '<S421>/Logical Operator1' incorporates:
   *  Constant: '<S421>/Cste_55'
   *  Constant: '<S421>/ExM_noPresSenTEg_C'
   *  Logic: '<S421>/Logical Operator2'
   *  RelationalOperator: '<S421>/Relational Operator'
   *  Sum: '<S421>/Sum'
   */
  localDataTypeConversion2_ij = 2 + ExM_noIdxTPrev;
  if (((UInt32)localDataTypeConversion2_ij) > 255U) {
    locallocalDataTypeConversion3_a = MAX_uint8_T;
  } else {
    locallocalDataTypeConversion3_a = (UInt8)localDataTypeConversion2_ij;
  }

  localLogicalOperator1_c = ((locallocalDataTypeConversion3_a ==
    ExM_noPresSenTEg_C) && (!rtu_FRM_bSenTEg));

  /* Outputs for enable SubSystem: '<S421>/F02_Temperature_models' incorporates:
   *  EnablePort: '<S488>/Enable'
   *  Logic: '<S421>/Logical Operator'
   */
  if (!localLogicalOperator1_c) {
    /* DataTypeConversion: '<S488>/Data Type Conversion1' */
    localDataTypeConversion1_a = rtu_Ext_tCoMes;

    /* DataTypeConversion: '<S488>/Data Type Conversion4' */
    localDataTypeConversion4_pk = rtu_Ext_tAir;

    /* SignalConversion: '<S488>/Signal Conversion1' */
    ExM_tEgInp = (*rtu_ExM_tEgInp);

    /* SwitchCase: '<S488>/Switch Case' incorporates:
     *  ActionPort: '<S502>/ExM_Sdl_OxCatT'
     *  ActionPort: '<S503>/ExM_Sdl_PipeT'
     *  ActionPort: '<S504>/ExM_Sdl_TrbT'
     *  ActionPort: '<S505>/ExM_Sdl_VoidT'
     *  SubSystem: '<S488>/OxCatMdlT'
     *  SubSystem: '<S488>/PipeMdl'
     *  SubSystem: '<S488>/TrbMdlT'
     *  SubSystem: '<S488>/VoidMdlT'
     */
    switch (ExM_stElementT) {
     case 1:
      /* Outputs for atomic SubSystem: '<S503>/F01_Pipe_pressure_model_parameters' */

      /* Outputs for atomic SubSystem: '<S701>/F01_MAP_index_of_pipe_thermal_model' */

      /* PreLookup: '<S710>/Prelookup' */
      localDataTypeConversion2_ij = plook_s32u16f_bincpa(rtu_ExM_mfEgWoutEGR,
        (&(ExM_mfEgTot_A[0])), 15U, &localPrelookup_o2_n,
        &localDW->Prelookup_DWORK1_ne);

      /* PreLookup: '<S711>/Prelookup' incorporates:
       *  DataTypeConversion: '<S705>/Data Type Conversion1'
       */
      localPrelookup_o1_px = plook_s32u16f_bincpa((UInt16)((SInt32)
        (((UInt32)((SInt32)rtu_Veh_spdVeh)) >> 7)), (&(ExM_spdVehX_A[0])), 8U,
        &localPrelookup_o2_ax, &localDW->Prelookup_DWORK1_l);

      /* DataTypeConversion: '<S705>/Data Type Conversion3' */
      if (rtu_Ext_rSpdFanAct > 127) {
        locallocalDataTypeConversion3_a = MAX_uint8_T;
      } else {
        locallocalDataTypeConversion3_a = (UInt8)(rtu_Ext_rSpdFanAct << 1);
      }

      /* PreLookup: '<S712>/Prelookup' */
      localPrelookup_o1_n0 = plook_s32u8f_bincpa(locallocalDataTypeConversion3_a,
        (&(ExM_rSpdFanY_A[0])), 10U, &localPrelookup_o2_oo,
        &localDW->Prelookup_DWORK1_ob);

      /* end of Outputs for SubSystem: '<S701>/F01_MAP_index_of_pipe_thermal_model' */

      /* SwitchCase: '<S701>/Switch Case' incorporates:
       *  ActionPort: '<S706>/Action Port'
       *  ActionPort: '<S707>/Action Port'
       *  ActionPort: '<S708>/Action Port'
       *  ActionPort: '<S709>/Action Port'
       *  SubSystem: '<S701>/F02_Pipe1_parameters_of_pressure_model'
       *  SubSystem: '<S701>/F03_Pipe2_parameters_of_pressure_model'
       *  SubSystem: '<S701>/F04_Pipe3_parameters_of_pressure_model'
       *  SubSystem: '<S701>/F05_Pipe4_parameters_of_pressure_model'
       */
      switch (ExM_stNbTypElementT) {
       case 1:
        /* If: '<S706>/If' incorporates:
         *  ActionPort: '<S713>/Action Port'
         *  ActionPort: '<S714>/Action Port'
         *  Constant: '<S706>/ExM_bSelMapUndHoPipe1_C'
         *  SubSystem: '<S706>/F01_Pipe1_under_hood_factor_with_MFR'
         *  SubSystem: '<S706>/F02_Pipe1_under_hood_factor_with_vehicle_and_fan_speed'
         */
        if (ExM_bSelMapUndHoPipe1_C) {
          /* Interpolation_n-D: '<S716>/Interpolation Using Prelookup3' incorporates:
           *  SignalConversion: '<S713>/Signal Conversion'
           */
          localfractionTmp_0d = localPrelookup_o2_n;
          ExM_facExgUndHo1 = intrp1d_iu16n14ff_s32f_la_n__1
            (localDataTypeConversion2_ij, localfractionTmp_0d,
             (&(ExM_facExtExgWallUndHoPipe1_T[0])), 15U);
        } else {
          /* Interpolation_n-D: '<S717>/Interpolation Using Prelookup3' incorporates:
           *  SignalConversion: '<S714>/Signal Conversion'
           */
          localfractionTmp_0d = localPrelookup_o2_ax;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_1d = localPrelookup_o2_oo;
          localfrac[1] = localfractionTmp_1d;
          localbpIndex[0] = localPrelookup_o1_px;
          localbpIndex[1] = localPrelookup_o1_n0;
          ExM_facExgUndHo1 = intrp2d_iu16n14ff_s32f_la_n(localbpIndex, localfrac,
            (&(ExM_facExgExtCoUndHoPipe1_M[0])), 9U, &ExMGslT2_ConstP.pooled33[0]);
        }

        /* Outputs for atomic SubSystem: '<S706>/F03_Pipe1_heat_exchange_factors' */

        /* Constant: '<S715>/ExM_bSelTCalcPipe1_C' */
        ExM_bSelTCalc1 = ExM_bSelTCalcPipe1_C;

        /* SignalConversion: '<S715>/Signal Conversion3' */
        ExM_bSelTCalc = ExM_bSelTCalc1;

        /* Interpolation_n-D: '<S718>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facItExgOverMf1 = intrp1d_iu16n7ff_s32f_la_n
          (localDataTypeConversion2_ij, localfractionTmp_0d,
           (&(ExM_facItExgOverMfPipe1_T[0])), 15U);

        /* Interpolation_n-D: '<S719>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facExtExg1 = intrp1d_iu16n11ff_s32f_la_n(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_facExtExgPipe1_T[0])), 15U);

        /* Interpolation_n-D: '<S720>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facJHeatWall1 = intrp1d_iu16ff_s32f_la__1(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_facJHeatWallPipe1_T[0])), 15U);

        /* SignalConversion: '<S715>/Signal Conversion' */
        ExM_facItExgOverMf = ExM_facItExgOverMf1;

        /* SignalConversion: '<S715>/Signal Conversion1' */
        ExM_facExtExg = ExM_facExtExg1;

        /* SignalConversion: '<S715>/Signal Conversion2' */
        ExM_facJHeatWall = ExM_facJHeatWall1;

        /* end of Outputs for SubSystem: '<S706>/F03_Pipe1_heat_exchange_factors' */

        /* SignalConversion: '<S706>/Signal Conversion' */
        ExM_facExgUndHo = ExM_facExgUndHo1;
        break;

       case 2:
        /* If: '<S707>/If' incorporates:
         *  ActionPort: '<S721>/Action Port'
         *  ActionPort: '<S722>/Action Port'
         *  Constant: '<S707>/ExM_bSelMapUndHoPipe2_C'
         *  SubSystem: '<S707>/F01_Pipe2_under_hood_factor_with_MFR'
         *  SubSystem: '<S707>/F02_Pipe2_under_hood_factor_with_vehicle_and_fan_speed'
         */
        if (ExM_bSelMapUndHoPipe2_C) {
          /* Interpolation_n-D: '<S724>/Interpolation Using Prelookup3' incorporates:
           *  SignalConversion: '<S721>/Signal Conversion'
           */
          localfractionTmp_0d = localPrelookup_o2_n;
          ExM_facExgUndHo2 = intrp1d_iu16n14ff_s32f_la_n__1
            (localDataTypeConversion2_ij, localfractionTmp_0d,
             (&(ExM_facExtExgWallUndHoPipe2_T[0])), 15U);
        } else {
          /* Interpolation_n-D: '<S725>/Interpolation Using Prelookup3' incorporates:
           *  SignalConversion: '<S722>/Signal Conversion'
           */
          localfractionTmp_0d = localPrelookup_o2_ax;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_oo;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_px;
          localbpIndex[1] = localPrelookup_o1_n0;
          ExM_facExgUndHo2 = intrp2d_iu16n14ff_s32f_la_n(localbpIndex, localfrac,
            (&(ExM_facExgExtCoUndHoPipe2_M[0])), 9U, &ExMGslT2_ConstP.pooled33[0]);
        }

        /* Outputs for atomic SubSystem: '<S707>/F03_Pipe2_heat_exchange_factors' */

        /* Constant: '<S723>/ExM_bSelTCalcPipe2_C' */
        ExM_bSelTCalc2 = ExM_bSelTCalcPipe2_C;

        /* SignalConversion: '<S723>/Signal Conversion3' */
        ExM_bSelTCalc = ExM_bSelTCalc2;

        /* Interpolation_n-D: '<S726>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facItExgOverMf2 = intrp1d_iu16n7ff_s32f_la_n
          (localDataTypeConversion2_ij, localfractionTmp_0d,
           (&(ExM_facItExgOverMfPipe2_T[0])), 15U);

        /* Interpolation_n-D: '<S727>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facExtExg2 = intrp1d_iu16n11ff_s32f_la_n(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_facExtExgPipe2_T[0])), 15U);

        /* Interpolation_n-D: '<S728>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facJHeatWall2 = intrp1d_iu16ff_s32f_la__1(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_facJHeatWallPipe2_T[0])), 15U);

        /* SignalConversion: '<S723>/Signal Conversion' */
        ExM_facItExgOverMf = ExM_facItExgOverMf2;

        /* SignalConversion: '<S723>/Signal Conversion1' */
        ExM_facExtExg = ExM_facExtExg2;

        /* SignalConversion: '<S723>/Signal Conversion2' */
        ExM_facJHeatWall = ExM_facJHeatWall2;

        /* end of Outputs for SubSystem: '<S707>/F03_Pipe2_heat_exchange_factors' */

        /* SignalConversion: '<S707>/Signal Conversion' */
        ExM_facExgUndHo = ExM_facExgUndHo2;
        break;

       case 3:
        /* If: '<S708>/If' incorporates:
         *  ActionPort: '<S729>/Action Port'
         *  ActionPort: '<S730>/Action Port'
         *  Constant: '<S708>/ExM_bSelMapUndHoPipe3_C'
         *  SubSystem: '<S708>/F01_Pipe3_under_hood_factor_with_MFR'
         *  SubSystem: '<S708>/F02_Pipe3_under_hood_factor_with_vehicle_and_fan_speed'
         */
        if (ExM_bSelMapUndHoPipe3_C) {
          /* Interpolation_n-D: '<S732>/Interpolation Using Prelookup3' incorporates:
           *  SignalConversion: '<S729>/Signal Conversion'
           */
          localfractionTmp_0d = localPrelookup_o2_n;
          ExM_facExgUndHo3 = intrp1d_iu16n14ff_s32f_la_n__1
            (localDataTypeConversion2_ij, localfractionTmp_0d,
             (&(ExM_facExtExgWallUndHoPipe3_T[0])), 15U);
        } else {
          /* Interpolation_n-D: '<S733>/Interpolation Using Prelookup3' incorporates:
           *  SignalConversion: '<S730>/Signal Conversion'
           */
          localfractionTmp_0d = localPrelookup_o2_ax;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_oo;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_px;
          localbpIndex[1] = localPrelookup_o1_n0;
          ExM_facExgUndHo3 = intrp2d_iu16n14ff_s32f_la_n(localbpIndex, localfrac,
            (&(ExM_facExgExtCoUndHoPipe3_M[0])), 9U, &ExMGslT2_ConstP.pooled33[0]);
        }

        /* Outputs for atomic SubSystem: '<S708>/F03_Pipe3_heat_exchange_factors' */

        /* Constant: '<S731>/ExM_bSelTCalcPipe3_C' */
        ExM_bSelTCalc3 = ExM_bSelTCalcPipe3_C;

        /* SignalConversion: '<S731>/Signal Conversion3' */
        ExM_bSelTCalc = ExM_bSelTCalc3;

        /* Interpolation_n-D: '<S734>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facItExgOverMf3 = intrp1d_iu16n7ff_s32f_la_n
          (localDataTypeConversion2_ij, localfractionTmp_0d,
           (&(ExM_facItExgOverMfPipe3_T[0])), 15U);

        /* Interpolation_n-D: '<S735>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facExtExg3 = intrp1d_iu16n11ff_s32f_la_n(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_facExtExgPipe3_T[0])), 15U);

        /* Interpolation_n-D: '<S736>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facJHeatWall3 = intrp1d_iu16ff_s32f_la__1(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_facJHeatWallPipe3_T[0])), 15U);

        /* SignalConversion: '<S731>/Signal Conversion' */
        ExM_facItExgOverMf = ExM_facItExgOverMf3;

        /* SignalConversion: '<S731>/Signal Conversion1' */
        ExM_facExtExg = ExM_facExtExg3;

        /* SignalConversion: '<S731>/Signal Conversion2' */
        ExM_facJHeatWall = ExM_facJHeatWall3;

        /* end of Outputs for SubSystem: '<S708>/F03_Pipe3_heat_exchange_factors' */

        /* SignalConversion: '<S708>/Signal Conversion' */
        ExM_facExgUndHo = ExM_facExgUndHo3;
        break;

       case 4:
        /* If: '<S709>/If' incorporates:
         *  ActionPort: '<S737>/Action Port'
         *  ActionPort: '<S738>/Action Port'
         *  Constant: '<S709>/ExM_bSelMapUndHoPipe4_C'
         *  SubSystem: '<S709>/F01_Pipe4_under_hood_factor_with_MFR'
         *  SubSystem: '<S709>/F02_Pipe4_under_hood_factor_with_vehicle_and_fan_speed'
         */
        if (ExM_bSelMapUndHoPipe4_C) {
          /* Interpolation_n-D: '<S740>/Interpolation Using Prelookup3' incorporates:
           *  SignalConversion: '<S737>/Signal Conversion'
           */
          localfractionTmp_0d = localPrelookup_o2_n;
          ExM_facExgUndHo4 = intrp1d_iu16n14ff_s32f_la_n__1
            (localDataTypeConversion2_ij, localfractionTmp_0d,
             (&(ExM_facExtExgWallUndHoPipe4_T[0])), 15U);
        } else {
          /* Interpolation_n-D: '<S741>/Interpolation Using Prelookup3' incorporates:
           *  SignalConversion: '<S738>/Signal Conversion'
           */
          localfractionTmp_0d = localPrelookup_o2_ax;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_oo;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_px;
          localbpIndex[1] = localPrelookup_o1_n0;
          ExM_facExgUndHo4 = intrp2d_iu16n14ff_s32f_la_n(localbpIndex, localfrac,
            (&(ExM_facExgExtCoUndHoPipe4_M[0])), 9U, &ExMGslT2_ConstP.pooled33[0]);
        }

        /* Outputs for atomic SubSystem: '<S709>/F03_Pipe4_heat_exchange_factors' */

        /* Constant: '<S739>/ExM_bSelTCalcPipe4_C' */
        ExM_bSelTCalc4 = ExM_bSelTCalcPipe4_C;

        /* SignalConversion: '<S739>/Signal Conversion3' */
        ExM_bSelTCalc = ExM_bSelTCalc4;

        /* Interpolation_n-D: '<S742>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facItExgOverMf4 = intrp1d_iu16n7ff_s32f_la_n
          (localDataTypeConversion2_ij, localfractionTmp_0d,
           (&(ExM_facItExgOverMfPipe4_T[0])), 15U);

        /* Interpolation_n-D: '<S743>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facExtExg4 = intrp1d_iu16n11ff_s32f_la_n(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_facExtExgPipe4_T[0])), 15U);

        /* Interpolation_n-D: '<S744>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_n;
        ExM_facJHeatWall4 = intrp1d_iu16ff_s32f_la__1(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_facJHeatWallPipe4_T[0])), 15U);

        /* SignalConversion: '<S739>/Signal Conversion' */
        ExM_facItExgOverMf = ExM_facItExgOverMf4;

        /* SignalConversion: '<S739>/Signal Conversion1' */
        ExM_facExtExg = ExM_facExtExg4;

        /* SignalConversion: '<S739>/Signal Conversion2' */
        ExM_facJHeatWall = ExM_facJHeatWall4;

        /* end of Outputs for SubSystem: '<S709>/F03_Pipe4_heat_exchange_factors' */

        /* SignalConversion: '<S709>/Signal Conversion' */
        ExM_facExgUndHo = ExM_facExgUndHo4;
        break;
      }

      /* end of Outputs for SubSystem: '<S503>/F01_Pipe_pressure_model_parameters' */

      /* Outputs for atomic SubSystem: '<S503>/F02_Under_hood_temperature' */

      /* Sum: '<S702>/Sum1' incorporates:
       *  Constant: '<S702>/Cste_51'
       */
      localfractionTmp_1d = ((Float32)localDataTypeConversion4_pk) +
        2.731499939E+002F;

      /* Switch: '<S702>/Switch2' incorporates:
       *  Constant: '<S702>/Cste_51'
       *  Sum: '<S702>/Sum'
       */
      if (ExM_bSelTCalc) {
        localfractionTmp_0d = 2.731499939E+002F + ((Float32)
          localDataTypeConversion1_a);
      } else {
        localfractionTmp_0d = ExM_tWallPrev;
      }

      /* Switch: '<S702>/Switch1' incorporates:
       *  Constant: '<S702>/ExM_bSwitchTAirUndHo_C'
       *  Constant: '<S702>/ExM_tSwitchAirUndHo_C'
       *  DataTypeConversion: '<S702>/Data Type Conversion1'
       *  Product: '<S745>/Divide'
       *  Sum: '<S702>/Sum4'
       *  Sum: '<S702>/Sum5'
       */
      if (ExM_bSwitchTAirUndHo_C) {
        ExM_tAirUndHo = ((localfractionTmp_0d - localfractionTmp_1d) *
                         ExM_facExgUndHo) + localfractionTmp_1d;
      } else {
        ExM_tAirUndHo = (((Float32)ExM_tSwitchAirUndHo_C) * 0.03125F) + 223.0F;
      }

      /* end of Outputs for SubSystem: '<S503>/F02_Under_hood_temperature' */

      /* Outputs for atomic SubSystem: '<S503>/F03_Pipe_wall_temperature' */

      /* Product: '<S746>/Divide' incorporates:
       *  DataTypeConversion: '<S703>/Data Type Conversion4'
       *  Product: '<S748>/Divide'
       */
      localfractionTmp_0d = ((((Float32)rtu_ExM_mfEgWoutEGR) *
        1.525878906E-005F) * ExM_facItExgOverMf) / ExM_facJHeatWall;

      /* Outputs for atomic SubSystem: '<S746>/If Action Subsystem3' */

      /* Switch: '<S753>/Switch1' incorporates:
       *  Constant: '<S753>/Constant2'
       *  RelationalOperator: '<S753>/Relational Operator'
       *  Saturate: '<S753>/Saturation'
       */
      if (localfractionTmp_0d != localfractionTmp_0d) {
        localfractionTmp_1d = 0.0F;
      } else {
        localfractionTmp_1d = rt_SATURATE(localfractionTmp_0d,
          -3.000000005E+038F, 3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S746>/If Action Subsystem3' */

      /* Product: '<S747>/Divide' */
      localfractionTmp_0d = ExM_facExtExg / ExM_facJHeatWall;

      /* Outputs for atomic SubSystem: '<S747>/If Action Subsystem3' */

      /* Switch: '<S755>/Switch1' incorporates:
       *  Constant: '<S755>/Constant2'
       *  RelationalOperator: '<S755>/Relational Operator'
       *  Saturate: '<S755>/Saturation'
       */
      if (localfractionTmp_0d != localfractionTmp_0d) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = rt_SATURATE(localfractionTmp_0d,
          -3.000000005E+038F, 3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S747>/If Action Subsystem3' */

      /* Switch: '<S703>/Switch1' incorporates:
       *  Constant: '<S703>/Cste_50'
       *  Constant: '<S703>/ExM_bSwitchTWallPipe_C'
       *  Constant: '<S703>/ExM_tSwitchWallPipe_C'
       *  DataTypeConversion: '<S703>/Data Type Conversion5'
       *  Product: '<S749>/Divide'
       *  Product: '<S750>/Divide'
       *  Product: '<S751>/Divide'
       *  Sum: '<S703>/Sum2'
       *  Sum: '<S703>/Sum3'
       *  Sum: '<S703>/Sum6'
       *  Sum: '<S703>/Sum7'
       */
      if (ExM_bSwitchTWallPipe_C) {
        ExM_tWallPipe = ((((1.0F - localfractionTmp_0d) - localfractionTmp_1d) *
                          ExM_tWallPrev) + (ExM_tEgInp * localfractionTmp_1d)) +
          (localfractionTmp_0d * ExM_tAirUndHo);
      } else {
        ExM_tWallPipe = (((Float32)ExM_tSwitchWallPipe_C) * 0.03125F) + 223.0F;
      }

      /* SignalConversion: '<S703>/Signal Conversion' */
      ExM_tWall = ExM_tWallPipe;

      /* end of Outputs for SubSystem: '<S503>/F03_Pipe_wall_temperature' */

      /* Outputs for atomic SubSystem: '<S503>/F04_Gas_temperature_at_pipe_out' */

      /* Product: '<S759>/Product4' incorporates:
       *  Constant: '<S759>/offset'
       *  Constant: '<S759>/one_on_slope'
       *  Sum: '<S759>/Add1'
       */
      localInterpolationUsingPrelo_gc = 32.0F * ExM_tEgInp;

      /* DataTypeConversion: '<S759>/OutDTConv' */
      localfractionTmp_1d = localInterpolationUsingPrelo_gc;
      if (localfractionTmp_1d < 65536.0F) {
        if (localfractionTmp_1d >= 0.0F) {
          locallocalDataTypeConversion1_a = (UInt16)localfractionTmp_1d;
        } else {
          locallocalDataTypeConversion1_a = 0U;
        }
      } else {
        locallocalDataTypeConversion1_a = MAX_uint16_T;
      }

      /* PreLookup: '<S758>/Prelookup' */
      localqY = plook_u32u16f_bincpa(locallocalDataTypeConversion1_a,
        (&(ExM_tEg_A[0])), 10U, &localInterpolationUsingPrelo_gc,
        &localDW->Prelookup_DWORK1_g);

      /* Interpolation_n-D: '<S757>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localInterpolationUsingPrelo_gc;
      localInterpolationUsingPrelo_gc = intrp1d_iu16n4ff_u32f_la_n(localqY,
        localfractionTmp_0d, (&(ExM_cppEg_T[0])), 10U);

      /* Product: '<S756>/Divide' */
      localfractionTmp_0d = ExM_facItExgOverMf / localInterpolationUsingPrelo_gc;

      /* Outputs for atomic SubSystem: '<S756>/If Action Subsystem3' */

      /* Switch: '<S763>/Switch1' incorporates:
       *  Constant: '<S763>/Constant2'
       *  RelationalOperator: '<S763>/Relational Operator'
       *  Saturate: '<S763>/Saturation'
       */
      if (localfractionTmp_0d != localfractionTmp_0d) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = rt_SATURATE(localfractionTmp_0d,
          -3.000000005E+038F, 3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S756>/If Action Subsystem3' */

      /* Sum: '<S704>/Sum1' incorporates:
       *  Constant: '<S704>/Cste_49'
       *  Product: '<S760>/Divide'
       *  Product: '<S761>/Divide'
       *  Sum: '<S704>/Sum'
       */
      ExM_tEgPipeOut = ((1.0F - localfractionTmp_0d) * ExM_tEgInp) +
        (localfractionTmp_0d * ExM_tWallPrev);

      /* SignalConversion: '<S704>/Signal Conversion' */
      localB->Merge1 = ExM_tEgPipeOut;

      /* end of Outputs for SubSystem: '<S503>/F04_Gas_temperature_at_pipe_out' */
      break;

     case 2:
      /* RelationalOperator: '<S504>/Relational Operator' incorporates:
       *  Constant: '<S504>/ExM_nEngThdTEgTrb_C'
       */
      localRelationalOperator_jg = (rtu_Ext_nEng < ExM_nEngThdTEgTrb_C);

      /* Outputs for enable SubSystem: '<S504>/F01_Turbine_temperature_for_low_engine_speed' incorporates:
       *  EnablePort: '<S764>/Enable'
       */
      if (localRelationalOperator_jg) {
        /* SignalConversion: '<S764>/Signal Conversion' */
        ExM_tEgTrbOut = ExM_tEgInp;
      }

      /* end of Outputs for SubSystem: '<S504>/F01_Turbine_temperature_for_low_engine_speed' */

      /* Outputs for enable SubSystem: '<S504>/F02_Turbine_temperature_for_engine_running' incorporates:
       *  EnablePort: '<S765>/Enable'
       *  Logic: '<S504>/Logical Operator'
       */
      if (!localRelationalOperator_jg) {
        /* Outputs for atomic SubSystem: '<S765>/F01_Pressure_ratio' */

        /* Product: '<S773>/Divide' */
        localfractionTmp_0d = ExM_pOut / ExM_pInp;

        /* Outputs for atomic SubSystem: '<S773>/If Action Subsystem3' */

        /* Switch: '<S775>/Switch1' incorporates:
         *  Constant: '<S775>/Constant2'
         *  RelationalOperator: '<S775>/Relational Operator'
         *  Saturate: '<S775>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          ExM_rPresDsOverUs = 0.0F;
        } else {
          ExM_rPresDsOverUs = rt_SATURATE(localfractionTmp_0d,
            -3.000000005E+038F, 3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S773>/If Action Subsystem3' */

        /* end of Outputs for SubSystem: '<S765>/F01_Pressure_ratio' */

        /* Outputs for atomic SubSystem: '<S765>/F02_Non_dimensionnal_turbine_MFR' */

        /* DataTypeConversion: '<S768>/Data Type Conversion4' incorporates:
         *  Constant: '<S768>/AirEfc_pRef_C'
         */
        localfractionTmp_0d = ((Float32)AirEfc_pRef_C) * 8.0F;

        /* Product: '<S779>/Product4' incorporates:
         *  Constant: '<S768>/AirEfc_tRef_C'
         *  Constant: '<S779>/offset'
         *  Constant: '<S779>/one_on_slope'
         *  DataTypeConversion: '<S768>/Data Type Conversion1'
         *  Product: '<S780>/Divide'
         *  Sum: '<S779>/Add1'
         */
        localInterpolationUsingPreloo_i = (ExM_tEgInp / (((Float32)
          AirEfc_tRef_C) * 0.0078125F)) * 6.553600098E+003F;

        /* DataTypeConversion: '<S779>/OutDTConv' */
        localfractionTmp_1d = localInterpolationUsingPreloo_i;
        if (localfractionTmp_1d < 65536.0F) {
          if (localfractionTmp_1d >= 0.0F) {
            locallocalDataTypeConversion1_a = (UInt16)localfractionTmp_1d;
          } else {
            locallocalDataTypeConversion1_a = 0U;
          }
        } else {
          locallocalDataTypeConversion1_a = MAX_uint16_T;
        }

        /* PreLookup: '<S778>/Prelookup' */
        localPrelookup_o1_px = plook_s32u16f_bincpa
          (locallocalDataTypeConversion1_a, (&(ExM_rTEgNorm_A[0])), 15U,
           &localInterpolationUsingPreloo_i, &localDW->Prelookup_DWORK1_hg);

        /* Interpolation_n-D: '<S777>/Interpolation Using Prelookup3' */
        localfractionTmp_1d = localInterpolationUsingPreloo_i;
        localInterpolationUsingPreloo_i = intrp1d_iu16n14ff_s32f_la_n__1
          (localPrelookup_o1_px, localfractionTmp_1d, (&(ExM_rTEgNormSqrt_T[0])),
           15U);

        /* Product: '<S776>/Divide' incorporates:
         *  Product: '<S781>/Divide'
         */
        localfractionTmp_0d = localInterpolationUsingPreloo_i / (ExM_pInp /
          localfractionTmp_0d);

        /* Outputs for atomic SubSystem: '<S776>/If Action Subsystem3' */

        /* Switch: '<S784>/Switch1' incorporates:
         *  Constant: '<S784>/Constant2'
         *  RelationalOperator: '<S784>/Relational Operator'
         *  Saturate: '<S784>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          ExM_facNormMfTrb_MP = 0.0F;
        } else {
          ExM_facNormMfTrb_MP = rt_SATURATE(localfractionTmp_0d,
            -3.000000005E+038F, 3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S776>/If Action Subsystem3' */

        /* Product: '<S782>/Divide' */
        ExM_mfEgTrbNorm = rtu_ExM_mfTrbEstimSatRef * ExM_facNormMfTrb_MP;

        /* end of Outputs for SubSystem: '<S765>/F02_Non_dimensionnal_turbine_MFR' */

        /* Outputs for atomic SubSystem: '<S765>/F03_Isentropic_expansion_temperature' */

        /* Product: '<S787>/Product4' incorporates:
         *  Constant: '<S787>/offset'
         *  Constant: '<S787>/one_on_slope'
         *  Sum: '<S787>/Add1'
         */
        localInterpolationUsingPrelo_ba = 1.310720020E+004F * ExM_rPresDsOverUs;

        /* DataTypeConversion: '<S787>/OutDTConv' */
        localfractionTmp_1d = localInterpolationUsingPrelo_ba;
        if (localfractionTmp_1d < 65536.0F) {
          if (localfractionTmp_1d >= 0.0F) {
            locallocalDataTypeConversion1_a = (UInt16)localfractionTmp_1d;
          } else {
            locallocalDataTypeConversion1_a = 0U;
          }
        } else {
          locallocalDataTypeConversion1_a = MAX_uint16_T;
        }

        /* PreLookup: '<S786>/Prelookup' */
        localPrelookup_o1_n0 = plook_s32u16f_bincpa
          (locallocalDataTypeConversion1_a, (&(ExM_rPresDsOverUs_A[0])), 15U,
           &localInterpolationUsingPrelo_ba, &localDW->Prelookup_DWORK1_jt);

        /* Interpolation_n-D: '<S785>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInterpolationUsingPrelo_ba;
        localInterpolationUsingPrelo_ba = intrp1d_iu16n15ff_s32f_la_n__1
          (localPrelookup_o1_n0, localfractionTmp_0d, (&(ExM_rTDsOverUs_T[0])),
           15U);

        /* Product: '<S788>/Divide' */
        ExM_tEgTrbOutWoutLoss = localInterpolationUsingPrelo_ba * ExM_tEgInp;

        /* end of Outputs for SubSystem: '<S765>/F03_Isentropic_expansion_temperature' */

        /* Outputs for atomic SubSystem: '<S765>/F04_Turbine_efficiency_factor' */

        /* Product: '<S791>/Product4' incorporates:
         *  Constant: '<S791>/offset'
         *  Constant: '<S791>/one_on_slope'
         *  Sum: '<S791>/Add1'
         */
        localPrelookup_o2_or = 65536.0F * ExM_mfEgTrbNorm;

        /* DataTypeConversion: '<S791>/OutDTConv' */
        localfractionTmp_1d = localPrelookup_o2_or;
        if (localfractionTmp_1d < 65536.0F) {
          if (localfractionTmp_1d >= 0.0F) {
            locallocalDataTypeConversion1_a = (UInt16)localfractionTmp_1d;
          } else {
            locallocalDataTypeConversion1_a = 0U;
          }
        } else {
          locallocalDataTypeConversion1_a = MAX_uint16_T;
        }

        /* PreLookup: '<S790>/Prelookup' */
        localDataTypeConversion2_ij = plook_s32u16f_bincpa
          (locallocalDataTypeConversion1_a, (&(ExM_mfEgTrbNorm_A[0])), 15U,
           &localPrelookup_o2_or, &localDW->Prelookup_DWORK1_j);

        /* Interpolation_n-D: '<S789>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_or;
        ExM_effTrb = intrp1d_iu16n14ff_s32f_la_n__1(localDataTypeConversion2_ij,
          localfractionTmp_0d, (&(ExM_effTrb_T[0])), 15U);

        /* end of Outputs for SubSystem: '<S765>/F04_Turbine_efficiency_factor' */

        /* Outputs for atomic SubSystem: '<S765>/F05_Temperature_with_loss' */

        /* Sum: '<S771>/Sum1' incorporates:
         *  Product: '<S792>/Divide'
         *  Sum: '<S771>/Sum'
         */
        ExM_tEgBasTrbOut = ((ExM_tEgTrbOutWoutLoss - ExM_tEgInp) * ExM_effTrb) +
          ExM_tEgInp;

        /* end of Outputs for SubSystem: '<S765>/F05_Temperature_with_loss' */

        /* Outputs for atomic SubSystem: '<S765>/F06_Mixed_temperature' */

        /* Sum: '<S772>/Sum' incorporates:
         *  Product: '<S794>/Divide'
         *  Product: '<S795>/Divide'
         */
        ExM_pwrThermo_MP = (ExM_tEgBasTrbOut * rtu_ExM_mfTrbEstimSatRef) +
          (ExM_tEgInp * rtu_ExM_mfWgEstimRef);

        /* Sum: '<S772>/Sum1' */
        ExM_mfTrbTot_MP = rtu_ExM_mfWgEstimRef + rtu_ExM_mfTrbEstimSatRef;

        /* Product: '<S793>/Divide' */
        localfractionTmp_0d = ExM_pwrThermo_MP / ExM_mfTrbTot_MP;

        /* Outputs for atomic SubSystem: '<S793>/If Action Subsystem3' */

        /* Switch: '<S797>/Switch1' incorporates:
         *  Constant: '<S797>/Constant2'
         *  DataTypeConversion: '<S793>/Data Type Conversion2'
         *  RelationalOperator: '<S797>/Relational Operator'
         *  Saturate: '<S797>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          ExM_tEgTrbOut = 0.0F;
        } else {
          ExM_tEgTrbOut = rt_SATURATE(localfractionTmp_0d, -3.000000005E+038F,
            3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S793>/If Action Subsystem3' */

        /* end of Outputs for SubSystem: '<S765>/F06_Mixed_temperature' */
      }

      /* end of Outputs for SubSystem: '<S504>/F02_Turbine_temperature_for_engine_running' */

      /* SignalConversion: '<S504>/Signal Conversion' */
      localB->Merge1 = ExM_tEgTrbOut;

      /* Outputs for atomic SubSystem: '<S504>/F03_Turbine_wall_temperature' */

      /* SignalConversion: '<S766>/Signal Conversion1' */
      ExM_tWallTrb = ExM_tWallPrev;

      /* SignalConversion: '<S766>/Signal Conversion' */
      ExM_tWall = ExM_tWallTrb;

      /* end of Outputs for SubSystem: '<S504>/F03_Turbine_wall_temperature' */
      break;

     case 3:
      /* Outputs for atomic SubSystem: '<S502>/F01_Catalyst_T_model' */

      /* DataTypeConversion: '<S506>/Data Type Conversion1' */
      localPrelookup_o1_px = ExM_stNbTypElementT;

      /* DataTypeConversion: '<S506>/Data Type Conversion2' */
      localDataTypeConversion2_b = ((Float32)rtu_FARSp_rMixtCylSp) *
        0.000244140625F;

      /* DataTypeConversion: '<S506>/Data Type Conversion3' */
      localDataTypeConversion3_cj = ((Float32)rtu_EngM_mfAirCor) *
        1.525878906E-005F;

      /* DataTypeConversion: '<S506>/Data Type Conversion5' */
      localDataTypeConversion5 = ((Float32)rtu_ExM_mfEgWoutEGR) *
        1.525878906E-005F;

      /* Outputs for atomic SubSystem: '<S506>/F01_TWC_System_and_Brick_specific_parameters' */

      /* Outputs for atomic SubSystem: '<S507>/F01_System_parameters_calculation' */

      /* Outputs for atomic SubSystem: '<S509>/F01_Exhaust_Gas_Cp_Estimation' */

      /* Product: '<S520>/Product4' incorporates:
       *  Constant: '<S520>/offset'
       *  Constant: '<S520>/one_on_slope'
       *  Sum: '<S520>/Add1'
       */
      localPrelookup_o2_ch = 32.0F * ExM_tEgInp;

      /* DataTypeConversion: '<S520>/OutDTConv' */
      localfractionTmp_1d = localPrelookup_o2_ch;
      if (localfractionTmp_1d < 65536.0F) {
        if (localfractionTmp_1d >= 0.0F) {
          locallocalDataTypeConversion1_a = (UInt16)localfractionTmp_1d;
        } else {
          locallocalDataTypeConversion1_a = 0U;
        }
      } else {
        locallocalDataTypeConversion1_a = MAX_uint16_T;
      }

      /* PreLookup: '<S519>/Prelookup' */
      localqY = plook_u32u16f_bincpa(locallocalDataTypeConversion1_a,
        (&(ExM_tEg_A[0])), 10U, &localPrelookup_o2_ch,
        &localDW->Prelookup_DWORK1_nh);

      /* Interpolation_n-D: '<S518>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localPrelookup_o2_ch;
      ExM_cppEg = intrp1d_iu16n4ff_u32f_la_n(localqY, localfractionTmp_0d,
        (&(ExM_cppEg_T[0])), 10U);

      /* end of Outputs for SubSystem: '<S509>/F01_Exhaust_Gas_Cp_Estimation' */

      /* Outputs for atomic SubSystem: '<S509>/F02_Current_Engine_Air_load_estimation' */

      /* Product: '<S521>/Divide' incorporates:
       *  Constant: '<S513>/ExM_facMassFlowToAirLdCnv_C'
       *  DataTypeConversion: '<S513>/Data Type Conversion1'
       *  DataTypeConversion: '<S513>/Data Type Conversion3'
       *  Product: '<S522>/Divide'
       */
      localfractionTmp_0d = localDataTypeConversion3_cj / ((((Float32)
        ExM_facMassFlowToAirLdCnv_C) * 4.999999970E-009F) * ((Float32)
        rtu_Ext_nEng));

      /* Outputs for atomic SubSystem: '<S521>/If Action Subsystem3' */

      /* Switch: '<S524>/Switch1' incorporates:
       *  Constant: '<S524>/Constant2'
       *  RelationalOperator: '<S524>/Relational Operator'
       *  Saturate: '<S524>/Saturation'
       */
      if (localfractionTmp_0d != localfractionTmp_0d) {
        ExM_rAirLdCorTWC = 0.0F;
      } else {
        ExM_rAirLdCorTWC = rt_SATURATE(localfractionTmp_0d, -3.000000005E+038F,
          3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S521>/If Action Subsystem3' */

      /* end of Outputs for SubSystem: '<S509>/F02_Current_Engine_Air_load_estimation' */

      /* DataTypeConversion: '<S517>/OutDTConv' incorporates:
       *  Constant: '<S517>/offset'
       *  Constant: '<S517>/one_on_slope'
       *  Product: '<S517>/Product4'
       *  Sum: '<S517>/Add1'
       */
      localfractionTmp_1d = 16384.0F * ExM_rAirLdCorTWC;
      if (localfractionTmp_1d < 65536.0F) {
        if (localfractionTmp_1d >= 0.0F) {
          locallocalDataTypeConversion1_0 = (UInt16)localfractionTmp_1d;
        } else {
          locallocalDataTypeConversion1_0 = 0U;
        }
      } else {
        locallocalDataTypeConversion1_0 = MAX_uint16_T;
      }

      /* Outputs for atomic SubSystem: '<S509>/F03_Injection_cut_off_exotherm_activation' */

      /* Logic: '<S514>/Logical Operator3' incorporates:
       *  Constant: '<S514>/Constant'
       *  Constant: '<S514>/ExM_bExoCutInj_C'
       *  RelationalOperator: '<S514>/Relational Operator'
       */
      ExM_bExoInjCutOff = ((0 != rtu_InjSys_noCylCutOff) && ExM_bExoCutInj_C);

      /* end of Outputs for SubSystem: '<S509>/F03_Injection_cut_off_exotherm_activation' */

      /* Outputs for atomic SubSystem: '<S509>/F04_Alternative_fuels_correction_factor' */

      /* Switch: '<S515>/Switch' incorporates:
       *  Constant: '<S515>/ExM_bEnaEthRatDft_C'
       *  Constant: '<S515>/ExM_rEthRatDft_C'
       *  Logic: '<S515>/Logical Operator'
       */
      if (rtu_AfuA_bInvldEthRat && ExM_bEnaEthRatDft_C) {
        locallocalDataTypeConversion3_a = ExM_rEthRatDft_C;
      } else {
        locallocalDataTypeConversion3_a = rtu_AfuA_rEthWiExct;
      }

      /* Lookup_n-D: '<S525>/Lookup Table (n-D)' */
      ExM_facEthCor = look1_iu8lfIf_binlcns__1(locallocalDataTypeConversion3_a,
        (&(ExM_rEth_A[0])), (&(ExM_facEthCor_T[0])), 7U);

      /* end of Outputs for SubSystem: '<S509>/F04_Alternative_fuels_correction_factor' */

      /* Outputs for atomic SubSystem: '<S509>/F05_Ignition_Effeciency_filter' */

      /* DataTypeConversion: '<S516>/Data Type Conversion1' */
      localDataTypeConversion1_lv = ((Float32)rtu_IgSys_rDynIgSpEfc) *
        0.0009765625F;

      /* DataTypeConversion: '<S516>/Data Type Conversion2' incorporates:
       *  Constant: '<S516>/ExM_facIgEffFil_C'
       */
      localfractionTmp_0d = (((Float32)ExM_facIgEffFil_C) * 1.525878906E-005F)
        + 1.525878906E-005F;

      /* Saturate: '<S530>/Saturation [0-1]' */
      localfractionTmp_1d = rt_SATURATE(localfractionTmp_0d, 0.0F, 1.0F);

      /* UnitDelay: '<S529>/UnitDelay' */
      localfractionTmp_0d = localDW->UnitDelay_hz;

      /* Switch: '<S529>/Switch' incorporates:
       *  UnitDelay: '<S529>/UnitDelay1'
       */
      if (!localDW->UnitDelay_hz3) {
        localfractionTmp_0d = localDataTypeConversion1_lv;
      }

      /* Sum: '<S530>/Sum1' incorporates:
       *  Product: '<S530>/Product'
       *  Sum: '<S530>/Sum'
       */
      localfractionTmp_0d += (localDataTypeConversion1_lv - localfractionTmp_0d)
        * localfractionTmp_1d;

      /* Switch: '<S527>/Switch' incorporates:
       *  UnitDelay: '<S527>/UnitDelay'
       */
      if (localDW->UnitDelay_DSTATE_d) {
        ExM_rIgSpEfcFil = localfractionTmp_0d;
      } else {
        ExM_rIgSpEfcFil = localDataTypeConversion1_lv;
      }

      /* Update for UnitDelay: '<S529>/UnitDelay' */
      localDW->UnitDelay_hz = localfractionTmp_0d;

      /* Update for UnitDelay: '<S529>/UnitDelay1' incorporates:
       *  Constant: '<S529>/Constant3'
       */
      localDW->UnitDelay_hz3 = TRUE;

      /* Update for UnitDelay: '<S527>/UnitDelay' incorporates:
       *  Constant: '<S527>/Constant3'
       */
      localDW->UnitDelay_DSTATE_d = TRUE;

      /* end of Outputs for SubSystem: '<S509>/F05_Ignition_Effeciency_filter' */

      /* end of Outputs for SubSystem: '<S507>/F01_System_parameters_calculation' */

      /* Outputs for atomic SubSystem: '<S507>/F02_Axis_interpolation' */

      /* PreLookup: '<S531>/Prelookup' */
      localPrelookup_o1_m3 = plook_s32u16f_bincpa
        (locallocalDataTypeConversion1_0, (&(ExM_rAirLdTExoTWCAfs_A[0])), 7U,
         &localPrelookup_o2_i, &localDW->Prelookup_DWORK1_a);

      /* PreLookup: '<S532>/Prelookup' */
      localPrelookup_o1_p = plook_s32u16f_bincpa(rtu_Ext_nEng,
        (&(ExM_nEngTExoTWCAfs_A[0])), 7U, &localPrelookup_o2_o,
        &localDW->Prelookup_DWORK1_o);

      /* PreLookup: '<S533>/Prelookup' */
      localDataTypeConversion2_ij = plook_s32u8f_bincpa(rtu_Ext_rSpdFanAct,
        (&(ExM_rSpdFanFacExtExgTWC_A[0])), 2U, &localPrelookup_o2_hi,
        &localDW->Prelookup_DWORK1_f);

      /* PreLookup: '<S534>/Prelookup' */
      localPrelookup_o1_n0 = plook_s32u16f_bincpa(rtu_Veh_spdVeh,
        (&(ExM_spdVehFacExtExgTWC_A[0])), 7U, &localPrelookup_o2_gy,
        &localDW->Prelookup_DWORK1_n);

      /* end of Outputs for SubSystem: '<S507>/F02_Axis_interpolation' */

      /* Outputs for atomic SubSystem: '<S507>/F03_Brick_specific_parameters_calculation' */

      /* SwitchCase: '<S511>/Switch Case' incorporates:
       *  ActionPort: '<S535>/Action Port'
       *  ActionPort: '<S536>/Action Port'
       *  ActionPort: '<S537>/Action Port'
       *  SubSystem: '<S511>/F01_First_TWC_Parameters'
       *  SubSystem: '<S511>/F02_Second_TWC_Parameters'
       *  SubSystem: '<S511>/F03_Third_TWC_Parameters'
       */
      switch (localPrelookup_o1_px) {
       case 1:
        /* Outputs for atomic SubSystem: '<S535>/F01_Underhood_parameters_calculation' */

        /* If: '<S539>/If' incorporates:
         *  ActionPort: '<S544>/Action Port'
         *  ActionPort: '<S545>/Action Port'
         *  SubSystem: '<S539>/F01_Underhood_parameters_for_FSF_position_1'
         *  SubSystem: '<S539>/F02_Underhood_parameters_for_FSF_position_2'
         */
        if (rtu_ThMgt_bPosnFSF) {
          /* Outputs for atomic SubSystem: '<S544>/F01_Raw_parameters_for_FSF_position_1' */

          /* Interpolation_n-D: '<S549>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_hi;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_n0;
          localbpIndex[1] = localDataTypeConversion2_ij;
          localInterpolationUsingPrelo_me = intrp2d_iu8n7ff_s32f_la_n
            (localbpIndex, localfrac, (&(ExM_facFSFopTNearTWC1_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* Interpolation_n-D: '<S550>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac_4[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_hi;
          localfrac_4[1] = localfractionTmp_0d;
          localbpIndex_4[0] = localPrelookup_o1_n0;
          localbpIndex_4[1] = localDataTypeConversion2_ij;
          localDataTypeConversion1_lv = intrp2d_iu16n10ff_s32f_la_n
            (localbpIndex_4, localfrac_4, (&(ExM_facExtExgFSFopTWC1_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* end of Outputs for SubSystem: '<S544>/F01_Raw_parameters_for_FSF_position_1' */

          /* If: '<S544>/If' incorporates:
           *  ActionPort: '<S547>/Action Port'
           *  ActionPort: '<S548>/Action Port'
           *  SubSystem: '<S544>/F02_Underhood_parameters_FSF_position_1_Active_fan'
           *  SubSystem: '<S544>/F03_Underhood_parameters_FSF_position_1_Inactive_fan'
           */
          if (rtu_Ext_bAdFanAct) {
            /* Interpolation_n-D: '<S551>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_1d = intrp1d_iu16n10ff_s32f_la_n
              (localPrelookup_o1_n0, localfractionTmp_0d,
               (&(ExM_facExtExgAdFanFSFopTWC1_T[0])), 7U);

            /* Interpolation_n-D: '<S552>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_0d = intrp1d_iu8n7ff_s32f_la_n(localPrelookup_o1_n0,
              localfractionTmp_0d, (&(ExM_facAdFanFSFopTNearTWC1_T[0])), 7U);

            /* Sum: '<S547>/Sum1' */
            ExM_facExtExgTWC = localfractionTmp_1d + localDataTypeConversion1_lv;

            /* Sum: '<S547>/Sum2' */
            ExM_facTNearTWC = localfractionTmp_0d +
              localInterpolationUsingPrelo_me;
          } else {
            /* SignalConversion: '<S548>/Signal Conversion1' */
            ExM_facTNearTWC = localInterpolationUsingPrelo_me;

            /* SignalConversion: '<S548>/Signal Conversion' */
            ExM_facExtExgTWC = localDataTypeConversion1_lv;
          }
        } else {
          /* Outputs for atomic SubSystem: '<S545>/F01_Raw_parameters_for_FSF_position_2' */

          /* Interpolation_n-D: '<S556>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_hi;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_n0;
          localbpIndex[1] = localDataTypeConversion2_ij;
          localInterpolationUsingPrelo_me = intrp2d_iu8n7ff_s32f_la_n
            (localbpIndex, localfrac, (&(ExM_facTNearTWC1_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* Interpolation_n-D: '<S557>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac_4[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_hi;
          localfrac_4[1] = localfractionTmp_0d;
          localbpIndex_4[0] = localPrelookup_o1_n0;
          localbpIndex_4[1] = localDataTypeConversion2_ij;
          localDataTypeConversion1_lv = intrp2d_iu16n10ff_s32f_la_n
            (localbpIndex_4, localfrac_4, (&(ExM_facExtExgTWC1_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* end of Outputs for SubSystem: '<S545>/F01_Raw_parameters_for_FSF_position_2' */

          /* If: '<S545>/If' incorporates:
           *  ActionPort: '<S554>/Action Port'
           *  ActionPort: '<S555>/Action Port'
           *  SubSystem: '<S545>/F02_Underhood_parameters_FSF_position_2_Active_fan'
           *  SubSystem: '<S545>/F03_Underhood_parameters_FSF_position_2_Inactive_fan'
           */
          if (rtu_Ext_bAdFanAct) {
            /* Interpolation_n-D: '<S558>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_1d = intrp1d_iu16n10ff_s32f_la_n
              (localPrelookup_o1_n0, localfractionTmp_0d,
               (&(ExM_facExtExgAdFanTWC1_T[0])), 7U);

            /* Interpolation_n-D: '<S559>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_0d = intrp1d_iu8n7ff_s32f_la_n(localPrelookup_o1_n0,
              localfractionTmp_0d, (&(ExM_facAdFanTNearTWC1_T[0])), 7U);

            /* Sum: '<S554>/Sum' */
            ExM_facTNearTWC = localfractionTmp_0d +
              localInterpolationUsingPrelo_me;

            /* Sum: '<S554>/Sum2' */
            ExM_facExtExgTWC = localfractionTmp_1d + localDataTypeConversion1_lv;
          } else {
            /* SignalConversion: '<S555>/Signal Conversion1' */
            ExM_facTNearTWC = localInterpolationUsingPrelo_me;

            /* SignalConversion: '<S555>/Signal Conversion' */
            ExM_facExtExgTWC = localDataTypeConversion1_lv;
          }
        }

        /* end of Outputs for SubSystem: '<S535>/F01_Underhood_parameters_calculation' */

        /* Outputs for atomic SubSystem: '<S535>/F02_Base_exotherm_calculation' */

        /* Switch: '<S566>/Switch' incorporates:
         *  RelationalOperator: '<S566>/UpperRelop'
         */
        if (ExM_facEthCor < 0.0F) {
          localDataTypeConversion1_lv = 0.0F;
        } else {
          localDataTypeConversion1_lv = ExM_facEthCor;
        }

        /* Switch: '<S566>/Switch2' incorporates:
         *  RelationalOperator: '<S566>/LowerRelop1'
         */
        if (ExM_facEthCor > 1.0F) {
          localDataTypeConversion1_lv = 1.0F;
        }

        /* Interpolation_n-D: '<S561>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_o;
        localfrac_0[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_i;
        localfrac_0[1] = localfractionTmp_0d;
        localbpIndex_0[0] = localPrelookup_o1_p;
        localbpIndex_0[1] = localPrelookup_o1_m3;
        localfractionTmp_1d = intrp2d_is16n5ff_s32f_la_n(localbpIndex_0,
          localfrac_0, (&(ExM_tExoTWCAfs1_M[0])), 8U, &ExMGslT2_ConstP.pooled35
          [0]);

        /* Interpolation_n-D: '<S562>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_o;
        localfrac_1[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_i;
        localfrac_1[1] = localfractionTmp_0d;
        localbpIndex_1[0] = localPrelookup_o1_p;
        localbpIndex_1[1] = localPrelookup_o1_m3;
        localfractionTmp_0d = intrp2d_is16n5ff_s32f_la_n(localbpIndex_1,
          localfrac_1, (&(ExM_tExoTWCAfsEth1_M[0])), 8U,
          &ExMGslT2_ConstP.pooled35[0]);

        /* Sum: '<S560>/Sum2' incorporates:
         *  Product: '<S560>/Divide'
         *  Sum: '<S560>/Sum3'
         */
        ExM_tExoTWCAfsWoutScv = ((localfractionTmp_0d - localfractionTmp_1d) *
          localDataTypeConversion1_lv) + localfractionTmp_1d;

        /* end of Outputs for SubSystem: '<S535>/F02_Base_exotherm_calculation' */

        /* Outputs for atomic SubSystem: '<S535>/F03_Switched_off_TWC_parameters' */

        /* DataTypeConversion: '<S541>/Data Type Conversion2' incorporates:
         *  Constant: '<S541>/ExM_tExoTWCNoLiOffDone1_C'
         */
        ExM_tExoTWCLiOffNotDone = ((Float32)ExM_tExoTWCNoLiOffDone1_C) *
          0.03125F;

        /* DataTypeConversion: '<S541>/Data Type Conversion1' incorporates:
         *  Constant: '<S541>/ExM_tTWCLiOffThd1_C'
         */
        ExM_tTWCLiOffThd = (((Float32)ExM_tTWCLiOffThd1_C) * 0.03125F) + 223.0F;

        /* end of Outputs for SubSystem: '<S535>/F03_Switched_off_TWC_parameters' */

        /* Outputs for atomic SubSystem: '<S535>/F04_Injection_cut_off_exotherm' */

        /* DataTypeConversion: '<S542>/Data Type Conversion1' incorporates:
         *  Constant: '<S542>/ExM_tExoInjCutOff1_C'
         */
        localDataTypeConversion1_l = ((Float32)ExM_tExoInjCutOff1_C) * 0.03125F;

        /* DataTypeConversion: '<S542>/Data Type Conversion2' incorporates:
         *  Constant: '<S542>/ExM_facFilExoInjCutOff1_C'
         */
        localfractionTmp_0d = ((Float32)ExM_facFilExoInjCutOff1_C) *
          9.999999747E-005F;

        /* Logic: '<S568>/Logical Operator' incorporates:
         *  Logic: '<S568>/Logical Operator1'
         *  UnitDelay: '<S573>/Unit Delay'
         */
        localLogicalOperator_k = (ExM_bExoInjCutOff &&
          (!localDW->UnitDelay_DSTATE_a));

        /* Outputs for enable SubSystem: '<S567>/Reset du filtre' incorporates:
         *  EnablePort: '<S570>/Enable'
         */
        ExMGslT2_Resetdufiltre(localLogicalOperator_k,
          localDataTypeConversion1_l, &localB->Resetdufiltre_g);

        /* end of Outputs for SubSystem: '<S567>/Reset du filtre' */

        /* Saturate: '<S572>/Saturation [0-1]' */
        localfractionTmp_1d = rt_SATURATE(localfractionTmp_0d, 0.0F, 1.0F);

        /* UnitDelay: '<S571>/UnitDelay' */
        localfractionTmp_0d = localDW->UnitDelay_e;

        /* Switch: '<S571>/Switch' incorporates:
         *  UnitDelay: '<S571>/UnitDelay1'
         */
        if (!localDW->UnitDelay_ed) {
          localfractionTmp_0d = localDataTypeConversion1_l;
        }

        /* Switch: '<S567>/Switch' incorporates:
         *  Constant: '<S542>/Constant1'
         *  Product: '<S572>/Product'
         *  Sum: '<S572>/Sum'
         *  Sum: '<S572>/Sum1'
         */
        if (localLogicalOperator_k) {
          localfractionTmp_0d = localB->Resetdufiltre_g.DataTypeConversion;
        } else {
          localfractionTmp_0d += (0.0F - localfractionTmp_0d) *
            localfractionTmp_1d;
        }

        /* Switch: '<S569>/Switch' incorporates:
         *  UnitDelay: '<S569>/UnitDelay'
         */
        if (localDW->UnitDelay_DSTATE_h) {
          ExM_tExoInjCutOff = localfractionTmp_0d;
        } else {
          ExM_tExoInjCutOff = localDataTypeConversion1_l;
        }

        /* Update for UnitDelay: '<S573>/Unit Delay' */
        localDW->UnitDelay_DSTATE_a = ExM_bExoInjCutOff;

        /* Update for UnitDelay: '<S571>/UnitDelay' */
        localDW->UnitDelay_e = localfractionTmp_0d;

        /* Update for UnitDelay: '<S571>/UnitDelay1' incorporates:
         *  Constant: '<S571>/Constant3'
         */
        localDW->UnitDelay_ed = TRUE;

        /* Update for UnitDelay: '<S569>/UnitDelay' incorporates:
         *  Constant: '<S569>/Constant3'
         */
        localDW->UnitDelay_DSTATE_h = TRUE;

        /* end of Outputs for SubSystem: '<S535>/F04_Injection_cut_off_exotherm' */

        /* Outputs for atomic SubSystem: '<S535>/F05_TWC_MCp' */

        /* DataTypeConversion: '<S543>/Data Type Conversion1' incorporates:
         *  Constant: '<S543>/ExM_cppMassTWC1_C'
         */
        ExM_cppMassTWC = ((Float32)ExM_cppMassTWC1_C) * 1.000000015E-001F;

        /* end of Outputs for SubSystem: '<S535>/F05_TWC_MCp' */
        break;

       case 2:
        /* Outputs for atomic SubSystem: '<S536>/F01_Underhood_parameters_calculation' */

        /* If: '<S574>/If' incorporates:
         *  ActionPort: '<S579>/Action Port'
         *  ActionPort: '<S580>/Action Port'
         *  SubSystem: '<S574>/F01_Underhood_parameters_for_FSF_position_1'
         *  SubSystem: '<S574>/F02_Underhood_parameters_for_FSF_position_2'
         */
        if (rtu_ThMgt_bPosnFSF) {
          /* Outputs for atomic SubSystem: '<S579>/F01_Raw_parameters_for_FSF_position_1' */

          /* Interpolation_n-D: '<S584>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_hi;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_n0;
          localbpIndex[1] = localDataTypeConversion2_ij;
          localInterpolationUsingPrelo_me = intrp2d_iu8n7ff_s32f_la_n
            (localbpIndex, localfrac, (&(ExM_facFSFopTNearTWC2_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* Interpolation_n-D: '<S585>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac_4[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_hi;
          localfrac_4[1] = localfractionTmp_0d;
          localbpIndex_4[0] = localPrelookup_o1_n0;
          localbpIndex_4[1] = localDataTypeConversion2_ij;
          localDataTypeConversion1_lv = intrp2d_iu16n10ff_s32f_la_n
            (localbpIndex_4, localfrac_4, (&(ExM_facExtExgFSFopTWC2_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* end of Outputs for SubSystem: '<S579>/F01_Raw_parameters_for_FSF_position_1' */

          /* If: '<S579>/If' incorporates:
           *  ActionPort: '<S582>/Action Port'
           *  ActionPort: '<S583>/Action Port'
           *  SubSystem: '<S579>/F02_Underhood_parameters_FSF_position_1_Active_fan'
           *  SubSystem: '<S579>/F03_Underhood_parameters_FSF_position_1_Inactive_fan'
           */
          if (rtu_Ext_bAdFanAct) {
            /* Interpolation_n-D: '<S586>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_1d = intrp1d_iu16n10ff_s32f_la_n
              (localPrelookup_o1_n0, localfractionTmp_0d,
               (&(ExM_facExtExgAdFanFSFopTWC2_T[0])), 7U);

            /* Interpolation_n-D: '<S587>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_0d = intrp1d_iu8n7ff_s32f_la_n(localPrelookup_o1_n0,
              localfractionTmp_0d, (&(ExM_facAdFanFSFopTNearTWC2_T[0])), 7U);

            /* Sum: '<S582>/Sum1' */
            ExM_facExtExgTWC = localfractionTmp_1d + localDataTypeConversion1_lv;

            /* Sum: '<S582>/Sum2' */
            ExM_facTNearTWC = localfractionTmp_0d +
              localInterpolationUsingPrelo_me;
          } else {
            /* SignalConversion: '<S583>/Signal Conversion1' */
            ExM_facTNearTWC = localInterpolationUsingPrelo_me;

            /* SignalConversion: '<S583>/Signal Conversion' */
            ExM_facExtExgTWC = localDataTypeConversion1_lv;
          }
        } else {
          /* Outputs for atomic SubSystem: '<S580>/F01_Raw_parameters_for_FSF_position_2' */

          /* Interpolation_n-D: '<S591>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_hi;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_n0;
          localbpIndex[1] = localDataTypeConversion2_ij;
          localInterpolationUsingPrelo_me = intrp2d_iu8n7ff_s32f_la_n
            (localbpIndex, localfrac, (&(ExM_facTNearTWC2_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* Interpolation_n-D: '<S592>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac_4[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_hi;
          localfrac_4[1] = localfractionTmp_0d;
          localbpIndex_4[0] = localPrelookup_o1_n0;
          localbpIndex_4[1] = localDataTypeConversion2_ij;
          localDataTypeConversion1_lv = intrp2d_iu16n10ff_s32f_la_n
            (localbpIndex_4, localfrac_4, (&(ExM_facExtExgTWC2_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* end of Outputs for SubSystem: '<S580>/F01_Raw_parameters_for_FSF_position_2' */

          /* If: '<S580>/If' incorporates:
           *  ActionPort: '<S589>/Action Port'
           *  ActionPort: '<S590>/Action Port'
           *  SubSystem: '<S580>/F02_Underhood_parameters_FSF_position_2_Active_fan'
           *  SubSystem: '<S580>/F03_Underhood_parameters_FSF_position_2_Inactive_fan'
           */
          if (rtu_Ext_bAdFanAct) {
            /* Interpolation_n-D: '<S593>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_1d = intrp1d_iu16n10ff_s32f_la_n
              (localPrelookup_o1_n0, localfractionTmp_0d,
               (&(ExM_facExtExgAdFanTWC2_T[0])), 7U);

            /* Interpolation_n-D: '<S594>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_0d = intrp1d_iu8n7ff_s32f_la_n(localPrelookup_o1_n0,
              localfractionTmp_0d, (&(ExM_facAdFan_TNearTWC2_T[0])), 7U);

            /* Sum: '<S589>/Sum' */
            ExM_facTNearTWC = localfractionTmp_0d +
              localInterpolationUsingPrelo_me;

            /* Sum: '<S589>/Sum2' */
            ExM_facExtExgTWC = localfractionTmp_1d + localDataTypeConversion1_lv;
          } else {
            /* SignalConversion: '<S590>/Signal Conversion1' */
            ExM_facTNearTWC = localInterpolationUsingPrelo_me;

            /* SignalConversion: '<S590>/Signal Conversion' */
            ExM_facExtExgTWC = localDataTypeConversion1_lv;
          }
        }

        /* end of Outputs for SubSystem: '<S536>/F01_Underhood_parameters_calculation' */

        /* Outputs for atomic SubSystem: '<S536>/F02_Base_exotherm_calculation' */

        /* Switch: '<S601>/Switch' incorporates:
         *  RelationalOperator: '<S601>/UpperRelop'
         */
        if (ExM_facEthCor < 0.0F) {
          localDataTypeConversion1_lv = 0.0F;
        } else {
          localDataTypeConversion1_lv = ExM_facEthCor;
        }

        /* Switch: '<S601>/Switch2' incorporates:
         *  RelationalOperator: '<S601>/LowerRelop1'
         */
        if (ExM_facEthCor > 1.0F) {
          localDataTypeConversion1_lv = 1.0F;
        }

        /* Interpolation_n-D: '<S596>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_o;
        localfrac_0[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_i;
        localfrac_0[1] = localfractionTmp_0d;
        localbpIndex_0[0] = localPrelookup_o1_p;
        localbpIndex_0[1] = localPrelookup_o1_m3;
        localfractionTmp_1d = intrp2d_is16n5ff_s32f_la_n(localbpIndex_0,
          localfrac_0, (&(ExM_tExoTWCAfs2_M[0])), 8U, &ExMGslT2_ConstP.pooled35
          [0]);

        /* Interpolation_n-D: '<S597>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_o;
        localfrac_1[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_i;
        localfrac_1[1] = localfractionTmp_0d;
        localbpIndex_1[0] = localPrelookup_o1_p;
        localbpIndex_1[1] = localPrelookup_o1_m3;
        localfractionTmp_0d = intrp2d_is16n5ff_s32f_la_n(localbpIndex_1,
          localfrac_1, (&(ExM_tExoTWCAfsEth2_M[0])), 8U,
          &ExMGslT2_ConstP.pooled35[0]);

        /* Sum: '<S595>/Sum2' incorporates:
         *  Product: '<S595>/Divide'
         *  Sum: '<S595>/Sum3'
         */
        ExM_tExoTWCAfsWoutScv = ((localfractionTmp_0d - localfractionTmp_1d) *
          localDataTypeConversion1_lv) + localfractionTmp_1d;

        /* end of Outputs for SubSystem: '<S536>/F02_Base_exotherm_calculation' */

        /* Outputs for atomic SubSystem: '<S536>/F03_Switched_off_TWC_parameters' */

        /* DataTypeConversion: '<S576>/Data Type Conversion2' incorporates:
         *  Constant: '<S576>/ExM_tExoTWCNoLiOffDone2_C'
         */
        ExM_tExoTWCLiOffNotDone = ((Float32)ExM_tExoTWCNoLiOffDone2_C) *
          0.03125F;

        /* DataTypeConversion: '<S576>/Data Type Conversion1' incorporates:
         *  Constant: '<S576>/ExM_tTWCLiOffThd2_C'
         */
        ExM_tTWCLiOffThd = (((Float32)ExM_tTWCLiOffThd2_C) * 0.03125F) + 223.0F;

        /* end of Outputs for SubSystem: '<S536>/F03_Switched_off_TWC_parameters' */

        /* Outputs for atomic SubSystem: '<S536>/F04_Injection_cut_off_exothrm' */

        /* DataTypeConversion: '<S577>/Data Type Conversion1' incorporates:
         *  Constant: '<S577>/ExM_tExoInjCutOff2_C'
         */
        localDataTypeConversion1_ar = ((Float32)ExM_tExoInjCutOff2_C) *
          0.03125F;

        /* DataTypeConversion: '<S577>/Data Type Conversion2' incorporates:
         *  Constant: '<S577>/ExM_facFilExoInjCutOff2_C'
         */
        localfractionTmp_0d = ((Float32)ExM_facFilExoInjCutOff2_C) *
          9.999999747E-005F;

        /* Logic: '<S603>/Logical Operator' incorporates:
         *  Logic: '<S603>/Logical Operator1'
         *  UnitDelay: '<S608>/Unit Delay'
         */
        localLogicalOperator_go = (ExM_bExoInjCutOff &&
          (!localDW->UnitDelay_DSTATE_g));

        /* Outputs for enable SubSystem: '<S602>/Reset du filtre' */
        ExMGslT2_Resetdufiltre(localLogicalOperator_go,
          localDataTypeConversion1_ar, &localB->Resetdufiltre_l);

        /* end of Outputs for SubSystem: '<S602>/Reset du filtre' */

        /* Saturate: '<S607>/Saturation [0-1]' */
        localfractionTmp_1d = rt_SATURATE(localfractionTmp_0d, 0.0F, 1.0F);

        /* UnitDelay: '<S606>/UnitDelay' */
        localfractionTmp_0d = localDW->UnitDelay_h;

        /* Switch: '<S606>/Switch' incorporates:
         *  UnitDelay: '<S606>/UnitDelay1'
         */
        if (!localDW->UnitDelay_h5) {
          localfractionTmp_0d = localDataTypeConversion1_ar;
        }

        /* Switch: '<S602>/Switch' incorporates:
         *  Constant: '<S577>/Constant3'
         *  Product: '<S607>/Product'
         *  Sum: '<S607>/Sum'
         *  Sum: '<S607>/Sum1'
         */
        if (localLogicalOperator_go) {
          localfractionTmp_0d = localB->Resetdufiltre_l.DataTypeConversion;
        } else {
          localfractionTmp_0d += (0.0F - localfractionTmp_0d) *
            localfractionTmp_1d;
        }

        /* Switch: '<S604>/Switch' incorporates:
         *  UnitDelay: '<S604>/UnitDelay'
         */
        if (localDW->UnitDelay_DSTATE_e) {
          ExM_tExoInjCutOff = localfractionTmp_0d;
        } else {
          ExM_tExoInjCutOff = localDataTypeConversion1_ar;
        }

        /* Update for UnitDelay: '<S608>/Unit Delay' */
        localDW->UnitDelay_DSTATE_g = ExM_bExoInjCutOff;

        /* Update for UnitDelay: '<S606>/UnitDelay' */
        localDW->UnitDelay_h = localfractionTmp_0d;

        /* Update for UnitDelay: '<S606>/UnitDelay1' incorporates:
         *  Constant: '<S606>/Constant3'
         */
        localDW->UnitDelay_h5 = TRUE;

        /* Update for UnitDelay: '<S604>/UnitDelay' incorporates:
         *  Constant: '<S604>/Constant3'
         */
        localDW->UnitDelay_DSTATE_e = TRUE;

        /* end of Outputs for SubSystem: '<S536>/F04_Injection_cut_off_exothrm' */

        /* Outputs for atomic SubSystem: '<S536>/F05_TWC_MCp' */

        /* DataTypeConversion: '<S578>/Data Type Conversion1' incorporates:
         *  Constant: '<S578>/ExM_cppMassTWC2_C'
         */
        ExM_cppMassTWC = ((Float32)ExM_cppMassTWC2_C) * 1.000000015E-001F;

        /* end of Outputs for SubSystem: '<S536>/F05_TWC_MCp' */
        break;

       case 3:
        /* Outputs for atomic SubSystem: '<S537>/F01_Underhood_parameters_calculation' */

        /* If: '<S609>/If' incorporates:
         *  ActionPort: '<S614>/Action Port'
         *  ActionPort: '<S615>/Action Port'
         *  SubSystem: '<S609>/F01_Underhood_parameters_for_FSF_position_1'
         *  SubSystem: '<S609>/F02_Underhood_parameters_for_FSF_position_2'
         */
        if (rtu_ThMgt_bPosnFSF) {
          /* Outputs for atomic SubSystem: '<S614>/F01_Raw_parameters_for_FSF_position_1' */

          /* Interpolation_n-D: '<S619>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_i;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_n0;
          localbpIndex[1] = localDataTypeConversion2_ij;
          localInterpolationUsingPrelo_me = intrp2d_iu8n7ff_s32f_la_n
            (localbpIndex, localfrac, (&(ExM_facFSFopTNearTWC3_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* Interpolation_n-D: '<S620>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac_4[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_i;
          localfrac_4[1] = localfractionTmp_0d;
          localbpIndex_4[0] = localPrelookup_o1_n0;
          localbpIndex_4[1] = localDataTypeConversion2_ij;
          localDataTypeConversion1_lv = intrp2d_iu16n10ff_s32f_la_n
            (localbpIndex_4, localfrac_4, (&(ExM_facExtExgFSFopTWC3_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* end of Outputs for SubSystem: '<S614>/F01_Raw_parameters_for_FSF_position_1' */

          /* If: '<S614>/If' incorporates:
           *  ActionPort: '<S617>/Action Port'
           *  ActionPort: '<S618>/Action Port'
           *  SubSystem: '<S614>/F02_Underhood_parameters_FSF_position_1_Active_fan'
           *  SubSystem: '<S614>/F03_Underhood_parameters_FSF_position_1_Inactive_fan'
           */
          if (rtu_Ext_bAdFanAct) {
            /* Interpolation_n-D: '<S621>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_1d = intrp1d_iu16n10ff_s32f_la_n
              (localPrelookup_o1_n0, localfractionTmp_0d,
               (&(ExM_facExtExgAdFanFSFopTWC3_T[0])), 7U);

            /* Interpolation_n-D: '<S622>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_0d = intrp1d_iu8n7ff_s32f_la_n(localPrelookup_o1_n0,
              localfractionTmp_0d, (&(ExM_facAdFanFSFopTNearTWC3_T[0])), 7U);

            /* Sum: '<S617>/Sum1' */
            ExM_facExtExgTWC = localfractionTmp_1d + localDataTypeConversion1_lv;

            /* Sum: '<S617>/Sum2' */
            ExM_facTNearTWC = localfractionTmp_0d +
              localInterpolationUsingPrelo_me;
          } else {
            /* SignalConversion: '<S618>/Signal Conversion1' */
            ExM_facTNearTWC = localInterpolationUsingPrelo_me;

            /* SignalConversion: '<S618>/Signal Conversion' */
            ExM_facExtExgTWC = localDataTypeConversion1_lv;
          }
        } else {
          /* Outputs for atomic SubSystem: '<S615>/F01_Raw_parameters_for_FSF_position_2' */

          /* Interpolation_n-D: '<S626>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_i;
          localfrac[1] = localfractionTmp_0d;
          localbpIndex[0] = localPrelookup_o1_n0;
          localbpIndex[1] = localDataTypeConversion2_ij;
          localInterpolationUsingPrelo_me = intrp2d_iu8n7ff_s32f_la_n
            (localbpIndex, localfrac, (&(ExM_facTNearTWC3_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* Interpolation_n-D: '<S627>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localPrelookup_o2_gy;
          localfrac_4[0] = localfractionTmp_0d;
          localfractionTmp_0d = localPrelookup_o2_i;
          localfrac_4[1] = localfractionTmp_0d;
          localbpIndex_4[0] = localPrelookup_o1_n0;
          localbpIndex_4[1] = localDataTypeConversion2_ij;
          localDataTypeConversion1_lv = intrp2d_iu16n10ff_s32f_la_n
            (localbpIndex_4, localfrac_4, (&(ExM_facExtExgTWC3_M[0])), 8U,
             &ExMGslT2_ConstP.pooled34[0]);

          /* end of Outputs for SubSystem: '<S615>/F01_Raw_parameters_for_FSF_position_2' */

          /* If: '<S615>/If' incorporates:
           *  ActionPort: '<S624>/Action Port'
           *  ActionPort: '<S625>/Action Port'
           *  SubSystem: '<S615>/F02_Underhood_parameters_FSF_position_2_Active_fan'
           *  SubSystem: '<S615>/F03_Underhood_parameters_FSF_position_2_Inactive_fan'
           */
          if (rtu_Ext_bAdFanAct) {
            /* Interpolation_n-D: '<S628>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_1d = intrp1d_iu16n10ff_s32f_la_n
              (localPrelookup_o1_n0, localfractionTmp_0d,
               (&(ExM_facExtExgAdFanTWC3_T[0])), 7U);

            /* Interpolation_n-D: '<S629>/Interpolation Using Prelookup3' */
            localfractionTmp_0d = localPrelookup_o2_gy;
            localfractionTmp_0d = intrp1d_iu8n7ff_s32f_la_n(localPrelookup_o1_n0,
              localfractionTmp_0d, (&(ExM_facAdFanTNearTWC3_T[0])), 7U);

            /* Sum: '<S624>/Sum' */
            ExM_facTNearTWC = localfractionTmp_0d +
              localInterpolationUsingPrelo_me;

            /* Sum: '<S624>/Sum2' */
            ExM_facExtExgTWC = localfractionTmp_1d + localDataTypeConversion1_lv;
          } else {
            /* SignalConversion: '<S625>/Signal Conversion1' */
            ExM_facTNearTWC = localInterpolationUsingPrelo_me;

            /* SignalConversion: '<S625>/Signal Conversion' */
            ExM_facExtExgTWC = localDataTypeConversion1_lv;
          }
        }

        /* end of Outputs for SubSystem: '<S537>/F01_Underhood_parameters_calculation' */

        /* Outputs for atomic SubSystem: '<S537>/F02_Base_exotherm_calculation' */

        /* Switch: '<S636>/Switch' incorporates:
         *  RelationalOperator: '<S636>/UpperRelop'
         */
        if (ExM_facEthCor < 0.0F) {
          localDataTypeConversion1_lv = 0.0F;
        } else {
          localDataTypeConversion1_lv = ExM_facEthCor;
        }

        /* Switch: '<S636>/Switch2' incorporates:
         *  RelationalOperator: '<S636>/LowerRelop1'
         */
        if (ExM_facEthCor > 1.0F) {
          localDataTypeConversion1_lv = 1.0F;
        }

        /* Interpolation_n-D: '<S631>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_o;
        localfrac_0[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_hi;
        localfrac_0[1] = localfractionTmp_0d;
        localbpIndex_0[0] = localPrelookup_o1_p;
        localbpIndex_0[1] = localPrelookup_o1_m3;
        localfractionTmp_1d = intrp2d_is16n5ff_s32f_la_n(localbpIndex_0,
          localfrac_0, (&(ExM_tExoTWCAfs3_M[0])), 8U, &ExMGslT2_ConstP.pooled35
          [0]);

        /* Interpolation_n-D: '<S632>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_o;
        localfrac_1[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_hi;
        localfrac_1[1] = localfractionTmp_0d;
        localbpIndex_1[0] = localPrelookup_o1_p;
        localbpIndex_1[1] = localPrelookup_o1_m3;
        localfractionTmp_0d = intrp2d_is16n5ff_s32f_la_n(localbpIndex_1,
          localfrac_1, (&(ExM_tExoTWCAfsEth3_M[0])), 8U,
          &ExMGslT2_ConstP.pooled35[0]);

        /* Sum: '<S630>/Sum2' incorporates:
         *  Product: '<S630>/Divide'
         *  Sum: '<S630>/Sum3'
         */
        ExM_tExoTWCAfsWoutScv = ((localfractionTmp_0d - localfractionTmp_1d) *
          localDataTypeConversion1_lv) + localfractionTmp_1d;

        /* end of Outputs for SubSystem: '<S537>/F02_Base_exotherm_calculation' */

        /* Outputs for atomic SubSystem: '<S537>/F03_Switched_off_TWC_parameters' */

        /* DataTypeConversion: '<S611>/Data Type Conversion2' incorporates:
         *  Constant: '<S611>/ExM_tExoTWCNoLiOffDone3_C'
         */
        ExM_tExoTWCLiOffNotDone = ((Float32)ExM_tExoTWCNoLiOffDone3_C) *
          0.03125F;

        /* DataTypeConversion: '<S611>/Data Type Conversion1' incorporates:
         *  Constant: '<S611>/ExM_tTWCLiOffThd3_C'
         */
        ExM_tTWCLiOffThd = (((Float32)ExM_tTWCLiOffThd3_C) * 0.03125F) + 223.0F;

        /* end of Outputs for SubSystem: '<S537>/F03_Switched_off_TWC_parameters' */

        /* Outputs for atomic SubSystem: '<S537>/F04_Injection_cut_off_exotherm' */

        /* DataTypeConversion: '<S612>/Data Type Conversion1' incorporates:
         *  Constant: '<S612>/ExM_tExoInjCutOff3_C'
         */
        localDataTypeConversion1_pi = ((Float32)ExM_tExoInjCutOff3_C) *
          0.03125F;

        /* DataTypeConversion: '<S612>/Data Type Conversion2' incorporates:
         *  Constant: '<S612>/ExM_facFilExoInjCutOff3_C'
         */
        localfractionTmp_0d = ((Float32)ExM_facFilExoInjCutOff3_C) *
          9.999999747E-005F;

        /* Logic: '<S638>/Logical Operator' incorporates:
         *  Logic: '<S638>/Logical Operator1'
         *  UnitDelay: '<S643>/Unit Delay'
         */
        localLogicalOperator_bg = (ExM_bExoInjCutOff &&
          (!localDW->UnitDelay_DSTATE));

        /* Outputs for enable SubSystem: '<S637>/Reset du filtre' */
        ExMGslT2_Resetdufiltre(localLogicalOperator_bg,
          localDataTypeConversion1_pi, &localB->Resetdufiltre_i);

        /* end of Outputs for SubSystem: '<S637>/Reset du filtre' */

        /* Saturate: '<S642>/Saturation [0-1]' */
        localfractionTmp_1d = rt_SATURATE(localfractionTmp_0d, 0.0F, 1.0F);

        /* UnitDelay: '<S641>/UnitDelay' */
        localfractionTmp_0d = localDW->UnitDelay;

        /* Switch: '<S641>/Switch' incorporates:
         *  UnitDelay: '<S641>/UnitDelay1'
         */
        if (!localDW->UnitDelay_m) {
          localfractionTmp_0d = localDataTypeConversion1_pi;
        }

        /* Switch: '<S637>/Switch' incorporates:
         *  Constant: '<S612>/Constant14'
         *  Product: '<S642>/Product'
         *  Sum: '<S642>/Sum'
         *  Sum: '<S642>/Sum1'
         */
        if (localLogicalOperator_bg) {
          localfractionTmp_0d = localB->Resetdufiltre_i.DataTypeConversion;
        } else {
          localfractionTmp_0d += (0.0F - localfractionTmp_0d) *
            localfractionTmp_1d;
        }

        /* Switch: '<S639>/Switch' incorporates:
         *  UnitDelay: '<S639>/UnitDelay'
         */
        if (localDW->UnitDelay_DSTATE_b) {
          ExM_tExoInjCutOff = localfractionTmp_0d;
        } else {
          ExM_tExoInjCutOff = localDataTypeConversion1_pi;
        }

        /* Update for UnitDelay: '<S643>/Unit Delay' */
        localDW->UnitDelay_DSTATE = ExM_bExoInjCutOff;

        /* Update for UnitDelay: '<S641>/UnitDelay' */
        localDW->UnitDelay = localfractionTmp_0d;

        /* Update for UnitDelay: '<S641>/UnitDelay1' incorporates:
         *  Constant: '<S641>/Constant3'
         */
        localDW->UnitDelay_m = TRUE;

        /* Update for UnitDelay: '<S639>/UnitDelay' incorporates:
         *  Constant: '<S639>/Constant3'
         */
        localDW->UnitDelay_DSTATE_b = TRUE;

        /* end of Outputs for SubSystem: '<S537>/F04_Injection_cut_off_exotherm' */

        /* Outputs for atomic SubSystem: '<S537>/F05_TWC_MCp' */

        /* DataTypeConversion: '<S613>/Data Type Conversion1' incorporates:
         *  Constant: '<S613>/ExM_cppMassTWC3_C'
         */
        ExM_cppMassTWC = ((Float32)ExM_cppMassTWC3_C) * 1.000000015E-001F;

        /* end of Outputs for SubSystem: '<S537>/F05_TWC_MCp' */
        break;
      }

      /* end of Outputs for SubSystem: '<S507>/F03_Brick_specific_parameters_calculation' */

      /* end of Outputs for SubSystem: '<S506>/F01_TWC_System_and_Brick_specific_parameters' */

      /* Outputs for atomic SubSystem: '<S506>/F02_TWC_temperatures_estimation' */

      /* Outputs for atomic SubSystem: '<S508>/F01_Calculation_of_catalyst_exothermy' */

      /* Outputs for atomic SubSystem: '<S644>/F01_Manage_scavenging_mode' */

      /* Logic: '<S647>/Logical Operator1' incorporates:
       *  Constant: '<S647>/Constant1'
       *  Constant: '<S647>/Constant3'
       *  Constant: '<S647>/ExM_mfScvThd_C'
       *  RelationalOperator: '<S647>/Relational Operator2'
       *  RelationalOperator: '<S647>/Relational Operator3'
       *  RelationalOperator: '<S647>/Relational Operator4'
       */
      ExM_bAcvExoTWCWiScv = (((rtu_Ext_stTypInjSysCf == 1) &&
        (rtu_EngM_mfAirScvCor > ExM_mfScvThd_C)) && (localPrelookup_o1_px == 1));

      /* end of Outputs for SubSystem: '<S644>/F01_Manage_scavenging_mode' */

      /* Outputs for atomic SubSystem: '<S644>/F02_Calculation_Of_Exotherm_in_no_scavenging_mode_condition' */

      /* If: '<S648>/If' incorporates:
       *  ActionPort: '<S651>/Action Port'
       *  ActionPort: '<S652>/Action Port'
       *  SubSystem: '<S648>/F01_FAR_and_SA_correction_for_Brick1_Exotherm'
       *  SubSystem: '<S648>/F02_FAR_correction_for_other_Bricks_Exotherm'
       */
      if (localPrelookup_o1_px == 1) {
        /* Product: '<S656>/Product4' incorporates:
         *  Constant: '<S656>/offset'
         *  Constant: '<S656>/one_on_slope'
         *  Sum: '<S656>/Add1'
         */
        localPrelookup_o2_hu = 1024.0F * ExM_rIgSpEfcFil;

        /* DataTypeConversion: '<S656>/OutDTConv' */
        localfractionTmp_1d = localPrelookup_o2_hu;
        if (localfractionTmp_1d < 65536.0F) {
          if (localfractionTmp_1d >= 0.0F) {
            locallocalDataTypeConversion1_a = (UInt16)localfractionTmp_1d;
          } else {
            locallocalDataTypeConversion1_a = 0U;
          }
        } else {
          locallocalDataTypeConversion1_a = MAX_uint16_T;
        }

        /* Lookup_n-D: '<S654>/Lookup Table (n-D)' */
        ExM_tCorIgEff = look1_iu16lfts16n5If_binlcns
          (locallocalDataTypeConversion1_a, (&(ExM_rIgSpEfcFil_A[0])),
           (&(ExM_tCorIgEff_T[0])), 7U);

        /* Sum: '<S651>/Add' */
        localfractionTmp_0d = ExM_tExoTWCAfsWoutScv - ExM_tCorIgEff;

        /* Product: '<S657>/Product4' incorporates:
         *  Constant: '<S657>/offset'
         *  Constant: '<S657>/one_on_slope'
         *  Sum: '<S657>/Add1'
         */
        localPrelookup_o2_hu = 32768.0F * rtu_ExM_rMixtInp;

        /* DataTypeConversion: '<S657>/OutDTConv' */
        localfractionTmp_1d = localPrelookup_o2_hu;
        if (localfractionTmp_1d < 65536.0F) {
          if (localfractionTmp_1d >= 0.0F) {
            locallocalDataTypeConversion1_a = (UInt16)localfractionTmp_1d;
          } else {
            locallocalDataTypeConversion1_a = 0U;
          }
        } else {
          locallocalDataTypeConversion1_a = MAX_uint16_T;
        }

        /* PreLookup: '<S655>/Prelookup' */
        localDataTypeConversion2_ij = plook_s32u16f_bincpa
          (locallocalDataTypeConversion1_a, (&(ExM_rMixtFacCorRatMixt_A[0])), 7U,
           &localPrelookup_o2_hu, &localDW->Prelookup_DWORK1_p);

        /* Interpolation_n-D: '<S653>/Interpolation Using Prelookup3' */
        localfractionTmp_1d = localPrelookup_o2_hu;
        ExM_facRatMixtTWC = intrp1d_iu8n7ff_s32f_la_n
          (localDataTypeConversion2_ij, localfractionTmp_1d,
           (&(ExM_facCorRatMix_T[0])), 7U);

        /* Product: '<S658>/Divide' */
        ExM_tExoTWCWoutScv = ExM_facRatMixtTWC * localfractionTmp_0d;
      } else {
        /* SignalConversion: '<S652>/Signal Conversion' */
        ExM_tExoTWCWoutScv = ExM_tExoTWCAfsWoutScv;
      }

      /* end of Outputs for SubSystem: '<S644>/F02_Calculation_Of_Exotherm_in_no_scavenging_mode_condition' */

      /* Outputs for enable SubSystem: '<S644>/F03_Calculation_Of_Exotherm_in_scavenging_mode_condition' incorporates:
       *  EnablePort: '<S649>/Enable'
       */
      if (ExM_bAcvExoTWCWiScv) {
        /* DataTypeConversion: '<S649>/Data Type Conversion3' */
        localInterpolationUsingPrelo_me = ((Float32)rtu_EngM_mfAirScvCor) *
          1.525878906E-005F;

        /* Outputs for atomic SubSystem: '<S649>/F01_Calculation_Of_Exotherm_in_scavenging_mode_approach_1' */

        /* Switch: '<S671>/Switch' incorporates:
         *  RelationalOperator: '<S671>/UpperRelop'
         */
        if (ExM_facEthCor < 0.0F) {
          localfractionTmp_0d = 0.0F;
        } else {
          localfractionTmp_0d = ExM_facEthCor;
        }

        /* Switch: '<S671>/Switch2' incorporates:
         *  RelationalOperator: '<S671>/LowerRelop1'
         */
        if (ExM_facEthCor > 1.0F) {
          localfractionTmp_0d = 1.0F;
        }

        /* DataTypeConversion: '<S659>/Data Type Conversion1' incorporates:
         *  Constant: '<S659>/Exm_facEOxdEmiGsl_C'
         */
        localfractionTmp_1d = ((Float32)Exm_facEOxdEmiGsl_C) * 50000.0F;

        /* Sum: '<S662>/Sum2' incorporates:
         *  Constant: '<S659>/Exm_facEOxdEmiEth_C'
         *  DataTypeConversion: '<S659>/Data Type Conversion3'
         *  Product: '<S662>/Divide'
         *  Sum: '<S662>/Sum3'
         */
        localDataTypeConversion1_lv = (((((Float32)Exm_facEOxdEmiEth_C) *
          50000.0F) - localfractionTmp_1d) * localfractionTmp_0d) +
          localfractionTmp_1d;

        /* Switch: '<S659>/Switch' incorporates:
         *  Constant: '<S659>/Constant'
         *  Constant: '<S659>/Constant4'
         *  Product: '<S664>/Divide'
         *  RelationalOperator: '<S659>/Relational Operator'
         *  Sum: '<S659>/Subtract'
         */
        if (rtu_ExM_rMixtInp >= 1.0F) {
          localfractionTmp_1d = localInterpolationUsingPrelo_me;
        } else {
          localfractionTmp_1d = (localDataTypeConversion2_b - 1.0F) *
            localDataTypeConversion3_cj;
        }

        /* Product: '<S663>/Divide' incorporates:
         *  Constant: '<S659>/Exm_conc02Air_C'
         *  DataTypeConversion: '<S659>/Data Type Conversion2'
         *  Product: '<S665>/Divide'
         *  Product: '<S666>/Divide'
         */
        localfractionTmp_0d = ((((Float32)Exm_conc02Air_C) * 0.00390625F) *
          localfractionTmp_1d) / (localDataTypeConversion5 * ExM_cppEg);

        /* Outputs for atomic SubSystem: '<S663>/If Action Subsystem3' */

        /* Switch: '<S673>/Switch1' incorporates:
         *  Constant: '<S673>/Constant2'
         *  RelationalOperator: '<S673>/Relational Operator'
         *  Saturate: '<S673>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          localfractionTmp_0d = 1.0F;
        } else {
          localfractionTmp_0d = rt_SATURATE(localfractionTmp_0d,
            -3.000000005E+038F, 3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S663>/If Action Subsystem3' */

        /* Product: '<S667>/Divide' */
        ExM_tExoTWCWiScvOpt1 = localfractionTmp_0d * localDataTypeConversion1_lv;

        /* end of Outputs for SubSystem: '<S649>/F01_Calculation_Of_Exotherm_in_scavenging_mode_approach_1' */

        /* Outputs for atomic SubSystem: '<S649>/F02_Calculation_Of_Exotherm_in_scavenging_mode_approach_2' */

        /* Switch: '<S685>/Switch' incorporates:
         *  RelationalOperator: '<S685>/UpperRelop'
         */
        if (ExM_facEthCor < 0.0F) {
          localfractionTmp_1d = 0.0F;
        } else {
          localfractionTmp_1d = ExM_facEthCor;
        }

        /* Switch: '<S685>/Switch2' incorporates:
         *  RelationalOperator: '<S685>/LowerRelop1'
         */
        if (ExM_facEthCor > 1.0F) {
          localfractionTmp_1d = 1.0F;
        }

        /* PreLookup: '<S678>/Prelookup' */
        localDataTypeConversion2_ij = plook_s32u16f_bincpa(rtu_Ext_nEng,
          (&(ExM_nEngTExoTWCWiScvOpt2_A[0])), 7U, &localPrelookup_o2_gx,
          &localDW->Prelookup_DWORK1);

        /* PreLookup: '<S679>/Prelookup' */
        localPrelookup_o1_px = plook_s32u16f_bincpa
          (locallocalDataTypeConversion1_0, (&(ExM_rAirLdTExoTWCWiScvOpt2_A[0])),
           7U, &localPrelookup_o2_gx1, &localDW->Prelookup_DWORK1_h);

        /* Interpolation_n-D: '<S677>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_gx;
        localfrac_2[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_gx1;
        localfrac_2[1] = localfractionTmp_0d;
        localbpIndex_2[0] = localDataTypeConversion2_ij;
        localbpIndex_2[1] = localPrelookup_o1_px;
        ExM_tExoTWCWiScvGslOpt2_MP = intrp2d_is16n5ff_s32f_la_n(localbpIndex_2,
          localfrac_2, (&(ExM_tExoTWCWiScvGslOpt2_M[0])), 8U,
          &ExMGslT2_ConstP.pooled35[0]);

        /* Interpolation_n-D: '<S676>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_gx;
        localfrac_3[0] = localfractionTmp_0d;
        localfractionTmp_0d = localPrelookup_o2_gx1;
        localfrac_3[1] = localfractionTmp_0d;
        localbpIndex_3[0] = localDataTypeConversion2_ij;
        localbpIndex_3[1] = localPrelookup_o1_px;
        ExM_tExoTWCWiScvEthOpt2_MP = intrp2d_is16n5ff_s32f_la_n(localbpIndex_3,
          localfrac_3, (&(ExM_tExoTWCWiScvEthOpt2_M[0])), 8U,
          &ExMGslT2_ConstP.pooled35[0]);

        /* Sum: '<S674>/Sum2' incorporates:
         *  Product: '<S674>/Divide'
         *  Sum: '<S674>/Sum3'
         */
        ExM_tExoTWCWiScvCorOpt2_MP = ((ExM_tExoTWCWiScvEthOpt2_MP -
          ExM_tExoTWCWiScvGslOpt2_MP) * localfractionTmp_1d) +
          ExM_tExoTWCWiScvGslOpt2_MP;

        /* Product: '<S675>/Divide' incorporates:
         *  Sum: '<S660>/Subtract'
         */
        localfractionTmp_0d = (localDataTypeConversion5 -
          localInterpolationUsingPrelo_me) / localDataTypeConversion5;

        /* Outputs for atomic SubSystem: '<S675>/If Action Subsystem3' */

        /* Switch: '<S687>/Switch1' incorporates:
         *  Constant: '<S687>/Constant2'
         *  RelationalOperator: '<S687>/Relational Operator'
         *  Saturate: '<S687>/Saturation'
         */
        if (localfractionTmp_0d != localfractionTmp_0d) {
          localfractionTmp_0d = 0.0F;
        } else {
          localfractionTmp_0d = rt_SATURATE(localfractionTmp_0d,
            -3.000000005E+038F, 3.000000005E+038F);
        }

        /* end of Outputs for SubSystem: '<S675>/If Action Subsystem3' */

        /* Product: '<S680>/Divide' incorporates:
         *  Product: '<S681>/Divide'
         *  Sum: '<S660>/Sum'
         */
        ExM_tExoTWCWiScvOpt2 = ((ExM_tExoTWCWiScvCorOpt2_MP - ExM_tCorIgEff) *
          localfractionTmp_0d) * ExM_facRatMixtTWC;

        /* end of Outputs for SubSystem: '<S649>/F02_Calculation_Of_Exotherm_in_scavenging_mode_approach_2' */

        /* Outputs for atomic SubSystem: '<S649>/F03_Maximum_exotherm_selection' */

        /* MinMax: '<S661>/MinMax' */
        ExM_tExoTWCWiScv = rt_MAXf(ExM_tExoTWCWiScvOpt1, ExM_tExoTWCWiScvOpt2);

        /* end of Outputs for SubSystem: '<S649>/F03_Maximum_exotherm_selection' */
      }

      /* end of Outputs for SubSystem: '<S644>/F03_Calculation_Of_Exotherm_in_scavenging_mode_condition' */

      /* Outputs for atomic SubSystem: '<S644>/F04_Coordination_of_exothermy' */

      /* Switch: '<S650>/Switch5' incorporates:
       *  Constant: '<S650>/ExM_bThdTWCNoLiOffTSel_C'
       */
      if (ExM_bThdTWCNoLiOffTSel_C) {
        localfractionTmp_0d = ExM_tEgInpPrev;
      } else {
        localfractionTmp_0d = ExM_tEgOxCOutPrev;
      }

      /* RelationalOperator: '<S650>/Relational Operator' */
      localRelationalOperator_jg = (localfractionTmp_0d > ExM_tTWCLiOffThd);

      /* Switch: '<S650>/Switch1' */
      if (ExM_bAcvExoTWCWiScv) {
        localfractionTmp_0d = ExM_tExoTWCWiScv;
      } else {
        localfractionTmp_0d = ExM_tExoTWCWoutScv;
      }

      /* Switch: '<S650>/Switch4' incorporates:
       *  Constant: '<S650>/Constant2'
       *  Constant: '<S650>/ExM_bAcvExoInjCutOffFil_C'
       */
      if (ExM_bAcvExoInjCutOffFil_C) {
        localfractionTmp_1d = ExM_tExoInjCutOff;
      } else {
        localfractionTmp_1d = 0.0F;
      }

      /* Switch: '<S650>/Switch6' */
      if (!localRelationalOperator_jg) {
        localfractionTmp_0d = ExM_tExoTWCLiOffNotDone;
      }

      /* Switch: '<S650>/Switch2' */
      if (ExM_bExoInjCutOff) {
        ExM_tExoTWC = localfractionTmp_1d;
      } else {
        ExM_tExoTWC = localfractionTmp_0d;
      }

      /* end of Outputs for SubSystem: '<S644>/F04_Coordination_of_exothermy' */

      /* end of Outputs for SubSystem: '<S508>/F01_Calculation_of_catalyst_exothermy' */

      /* Outputs for atomic SubSystem: '<S508>/F02_Computation_of_under_hood_temperature_near_TWC' */

      /* Switch: '<S692>/Switch' incorporates:
       *  RelationalOperator: '<S692>/UpperRelop'
       */
      if (ExM_facTNearTWC < 0.0F) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = ExM_facTNearTWC;
      }

      /* Switch: '<S692>/Switch2' incorporates:
       *  RelationalOperator: '<S692>/LowerRelop1'
       */
      if (ExM_facTNearTWC > 1.0F) {
        localfractionTmp_0d = 1.0F;
      }

      /* Switch: '<S645>/Switch1' incorporates:
       *  Constant: '<S645>/Constant'
       *  Constant: '<S645>/ExM_bInhManTNearTWC_C'
       *  Constant: '<S645>/ExM_tManTNearTWC_C'
       *  DataTypeConversion: '<S645>/Data Type Conversion2'
       *  Product: '<S688>/Divide'
       *  Sum: '<S645>/Sum5'
       *  Sum: '<S688>/Sum2'
       *  Sum: '<S688>/Sum3'
       */
      if (ExM_bInhManTNearTWC_C) {
        ExM_tAirNearTWC = ((((Float32)(localDataTypeConversion1_a -
          localDataTypeConversion4_pk)) * localfractionTmp_0d) + ((Float32)
          localDataTypeConversion4_pk)) + 2.731499939E+002F;
      } else {
        ExM_tAirNearTWC = (((Float32)ExM_tManTNearTWC_C) * 0.03125F) + 223.0F;
      }

      /* end of Outputs for SubSystem: '<S508>/F02_Computation_of_under_hood_temperature_near_TWC' */

      /* Outputs for atomic SubSystem: '<S508>/F03_Calculation_of_thermal_equilibrium' */

      /* Product: '<S698>/Divide' */
      localfractionTmp_0d = localDataTypeConversion5 * ExM_cppEg;

      /* Product: '<S694>/Divide' incorporates:
       *  Sum: '<S646>/Subtract'
       */
      ExM_pwrTrfHeatTWC_MP = (ExM_tEgInp - ExM_tEgOxCOutPrev) *
        localfractionTmp_0d;

      /* Product: '<S695>/Divide' */
      ExM_pwrExoTWC_MP = localfractionTmp_0d * ExM_tExoTWC;

      /* Product: '<S696>/Divide' incorporates:
       *  Sum: '<S646>/Subtract1'
       */
      ExM_pwrCnvcTWC_MP = (ExM_tEgOxCOutPrev - ExM_tAirNearTWC) *
        ExM_facExtExgTWC;

      /* Sum: '<S646>/add1' incorporates:
       *  Sum: '<S646>/add'
       */
      ExM_pwrSumTWC_MP = (ExM_pwrTrfHeatTWC_MP + ExM_pwrExoTWC_MP) -
        ExM_pwrCnvcTWC_MP;

      /* Product: '<S693>/Divide' */
      localfractionTmp_0d = ExM_pwrSumTWC_MP / ExM_cppMassTWC;

      /* Outputs for atomic SubSystem: '<S693>/If Action Subsystem3' */

      /* Switch: '<S700>/Switch1' incorporates:
       *  Constant: '<S700>/Constant2'
       *  RelationalOperator: '<S700>/Relational Operator'
       *  Saturate: '<S700>/Saturation'
       */
      if (localfractionTmp_0d != localfractionTmp_0d) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = rt_SATURATE(localfractionTmp_0d,
          -3.000000005E+038F, 3.000000005E+038F);
      }

      /* end of Outputs for SubSystem: '<S693>/If Action Subsystem3' */

      /* Product: '<S697>/Divide' incorporates:
       *  Constant: '<S646>/ExM_tiSdlThermo_C'
       *  DataTypeConversion: '<S646>/Data Type Conversion4'
       */
      ExM_tDeltaTTWC_MP = (((Float32)ExM_tiSdlThermo_C) * 9.999999776E-003F) *
        localfractionTmp_0d;

      /* Sum: '<S646>/add2' */
      ExM_tEgOutOxC = ExM_tDeltaTTWC_MP + ExM_tEgOxCOutPrev;

      /* end of Outputs for SubSystem: '<S508>/F03_Calculation_of_thermal_equilibrium' */

      /* SignalConversion: '<S508>/Signal Conversion' */
      ExM_tWallOxCat = ExM_tEgOutOxC;

      /* SignalConversion: '<S508>/Signal Conversion1' */
      ExM_tEgOxCatOut = ExM_tEgOutOxC;

      /* SignalConversion: '<S508>/Signal Conversion2' */
      ExM_tWall = ExM_tWallOxCat;

      /* SignalConversion: '<S508>/Signal Conversion3' */
      localB->Merge1 = ExM_tEgOxCatOut;

      /* end of Outputs for SubSystem: '<S506>/F02_TWC_temperatures_estimation' */

      /* end of Outputs for SubSystem: '<S502>/F01_Catalyst_T_model' */
      break;

     default:
      /* SignalConversion: '<S505>/Signal Conversion2' */
      ExM_tEgVoidOut = ExM_tEgInp;

      /* SignalConversion: '<S505>/Signal Conversion' */
      localB->Merge1 = ExM_tEgVoidOut;

      /* SignalConversion: '<S505>/Signal Conversion3' */
      ExM_tWallVoid = ExM_tWallPrev;

      /* SignalConversion: '<S505>/Signal Conversion1' */
      ExM_tWall = ExM_tWallVoid;
      break;
    }
  }

  /* end of Outputs for SubSystem: '<S421>/F02_Temperature_models' */

  /* RelationalOperator: '<S421>/Relational Operator1' incorporates:
   *  Constant: '<S421>/Cste_1'
   */
  localRelationalOperator_jg = (ExM_stElementT == 3);

  /* Outputs for enable SubSystem: '<S421>/F01_OxC_spec_1' incorporates:
   *  EnablePort: '<S486>/Enable'
   */
  if (localRelationalOperator_jg) {
    /* Sum: '<S501>/Add' incorporates:
     *  Constant: '<S486>/Cste_54'
     *  Constant: '<S501>/Constant1'
     *  Sum: '<S486>/Sum'
     */
    localqY = ExM_noIdxOxCPrev;

    /* Assignment: '<S501>/Assignment' incorporates:
     *  Constant: '<S501>/Constant'
     *  MinMax: '<S501>/MinMax'
     */
    localAssignment_g[0] = ExM_prm_tEgOxCPrev[0];
    localAssignment_g[1] = ExM_prm_tEgOxCPrev[1];
    localAssignment_g[2] = ExM_prm_tEgOxCPrev[2];
    localAssignment_g[(SInt32)rt_MIN(localqY, 2U)] = ExM_tEgOutOxC;

    /* SignalConversion: '<S486>/Signal Conversion' */
    rty_ExM_prm_tEgOxC[0] = localAssignment_g[0];
    rty_ExM_prm_tEgOxC[1] = localAssignment_g[1];
    rty_ExM_prm_tEgOxC[2] = localAssignment_g[2];
  }

  /* end of Outputs for SubSystem: '<S421>/F01_OxC_spec_1' */

  /* Outputs for enable SubSystem: '<S421>/F02_OxC_spec_2' incorporates:
   *  Constant: '<S421>/Cste_2'
   *  EnablePort: '<S487>/Enable'
   *  EnablePort: '<S489>/Enable'
   *  Logic: '<S421>/Logical Operator4'
   *  RelationalOperator: '<S421>/Relational Operator2'
   *  SubSystem: '<S421>/F03_OxC_spec_3'
   */
  if (ExM_stElementT == 3) {
    /* Sum: '<S487>/Sum' incorporates:
     *  Constant: '<S487>/Cste_54'
     */
    localDataTypeConversion2_ij = ExM_noIdxOxCPrev + 1;
    if (((UInt32)localDataTypeConversion2_ij) > 255U) {
      (*rty_ExM_noIdxOxC) = MAX_uint8_T;
    } else {
      (*rty_ExM_noIdxOxC) = (UInt8)localDataTypeConversion2_ij;
    }
  } else {
    /* SignalConversion: '<S489>/Signal Conversion' */
    (*rty_ExM_noIdxOxC) = ExM_noIdxOxCPrev;
  }

  /* end of Outputs for SubSystem: '<S421>/F02_OxC_spec_2' */

  /* Outputs for enable SubSystem: '<S421>/F03_Temperature_measures' incorporates:
   *  EnablePort: '<S490>/Enable'
   */
  if (localLogicalOperator1_c) {
    /* DataTypeConversion: '<S490>/Data Type Conversion' */
    localfractionTmp_0d = (((Float32)rtu_ExM_tEgMes) * 0.03125F) + 223.0F;

    /* SignalConversion: '<S490>/Signal Conversion' */
    localB->Merge1 = localfractionTmp_0d;

    /* SignalConversion: '<S490>/Signal Conversion1' */
    ExM_tWall = localfractionTmp_0d;
  }

  /* end of Outputs for SubSystem: '<S421>/F03_Temperature_measures' */

  /* Outputs for enable SubSystem: '<S421>/F04_OxC_spec_4' incorporates:
   *  EnablePort: '<S491>/Enable'
   *  Logic: '<S421>/Logical Operator3'
   */
  if (!localRelationalOperator_jg) {
    /* SignalConversion: '<S491>/Signal Conversion' */
    rty_ExM_prm_tEgOxC[0] = ExM_prm_tEgOxCPrev[0];
    rty_ExM_prm_tEgOxC[1] = ExM_prm_tEgOxCPrev[1];
    rty_ExM_prm_tEgOxC[2] = ExM_prm_tEgOxCPrev[2];
  }

  /* end of Outputs for SubSystem: '<S421>/F04_OxC_spec_4' */

  /* Outputs for atomic SubSystem: '<S421>/F04_Update_temperature_arrays' */

  /* Sum: '<S492>/Sum' incorporates:
   *  Constant: '<S492>/Cste_52'
   */
  localqY = (UInt32)(ExM_noIdxTPrev + 2);

  /* Sum: '<S798>/Add' incorporates:
   *  Constant: '<S798>/Constant1'
   */
  localDataTypeConversion2_ij = ((SInt32)localqY) - 1;

  /* Assignment: '<S798>/Assignment' incorporates:
   *  Constant: '<S798>/Constant'
   *  MinMax: '<S798>/MinMax'
   */
  for (localPrelookup_o1_px = 0; localPrelookup_o1_px < 12; localPrelookup_o1_px
       ++) {
    /* SignalConversion: '<S492>/Signal Conversion3' */
    ExM_prm_tEgInterPrev[(localPrelookup_o1_px)] = rtu_ExM_prm_tEgInterPrev
      [(localPrelookup_o1_px)];
    localTmpSignalConversionAtSel_b[localPrelookup_o1_px] =
      ExM_prm_tEgInterPrev[(localPrelookup_o1_px)];

    /* SignalConversion: '<S492>/Signal Conversion1' */
    ExM_prm_tWallInterPrev[(localPrelookup_o1_px)] = rtu_ExM_prm_tWallInterPrev
      [(localPrelookup_o1_px)];
    localAssignment_a[localPrelookup_o1_px] = ExM_prm_tWallInterPrev
      [(localPrelookup_o1_px)];
  }

  localTmpSignalConversionAtSel_b[(SInt32)rt_MIN((UInt32)
    localDataTypeConversion2_ij, 11U)] = localB->Merge1;

  /* Sum: '<S799>/Add' incorporates:
   *  Constant: '<S799>/Constant1'
   */
  localqY = (UInt32)(((SInt32)localqY) - 1);

  /* Assignment: '<S799>/Assignment' incorporates:
   *  Constant: '<S799>/Constant'
   *  MinMax: '<S799>/MinMax'
   */
  localAssignment_a[(SInt32)rt_MIN(localqY, 11U)] = ExM_tWall;
  for (localDataTypeConversion2_ij = 0; localDataTypeConversion2_ij < 12;
       localDataTypeConversion2_ij++) {
    /* SignalConversion: '<S492>/Signal Conversion2' */
    rty_ExM_prm_tEgInter[(localDataTypeConversion2_ij)] =
      localTmpSignalConversionAtSel_b[localDataTypeConversion2_ij];

    /* SignalConversion: '<S492>/Signal Conversion4' */
    rty_ExM_prm_tWallInter[(localDataTypeConversion2_ij)] =
      localAssignment_a[localDataTypeConversion2_ij];
  }

  /* end of Outputs for SubSystem: '<S421>/F04_Update_temperature_arrays' */

  /* SignalConversion: '<S421>/Signal Conversion1' */
  (*rty_ExM_tEgOut) = localB->Merge1;
}

/* Start for exported function: RE_ExMGslT2_007_TEV */
void RE_ExMGslT2_007_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F03_ExM2T'
   */
}

/* Output and update for exported function: RE_ExMGslT2_007_TEV */
void RE_ExMGslT2_007_TEV(void)
{
  /* local block i/o variables */
  Boolean localAutosarServer_a;
  SInt16 localOutDTConv_j;
  SInt16 localOutDTConv_o;
  Float32 localDataTypeConversion_n;
  Float32 localAssignment_l[12];
  Float32 localAssignment_m1[12];
  Float32 localProduct_g;
  UInt32 localAdd_n;
  UInt32 localAdd_e;
  SInt32 localmin;
  Float32 localPrelookup_o2_k;
  SInt32 localmin_0;
  SInt32 localmin_1;
  Float32 localAssignment_b[6];
  UInt16 localOutDTConv_l4;
  UInt16 localSwitch_nd;
  UInt16 localSwitch_dm[12];
  UInt16 localSwitch_gy[6];
  Float32 localSum_0;
  SInt32 locali;
  Float32 locallocalAssignment_l;
  UInt32 localqY;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_ExM2T'
   */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&ExMGslT2_B.TmpSignalConversionAtEng_noExCy);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEng_noExNxtCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExNxtCyl'
   */
  Rte_Read_R_Eng_noExNxtCyl_Eng_noExNxtCyl
    (&ExMGslT2_B.TmpSignalConversionAtEng_noExNx);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_prm_tExMnfEstimCylPrevOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_tExMnfEstimCyl_INPUT'
   */
  Rte_Read_R_ExM_prm_tExMnfEstimCyl_ExM_prm_tExMnfEstimCyl
    (&ExMGslT2_B.TmpSignalConversionAtExM_prm_tE);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_mfEgWoutEGROutport2' incorporates:
   *  Inport: '<Root>/ExM_mfEgWoutEGR_INPUT'
   */
  Rte_Read_R_ExM_mfEgWoutEGR_ExM_mfEgWoutEGR
    (&ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_prm_tEgFltPrevOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_tEgFlt_INPUT'
   */
  Rte_Read_R_ExM_prm_tEgFlt_ExM_prm_tEgFlt
    (&ExMGslT2_B.TmpSignalConversionAtExM_prm__g);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S416>/autosar_irv_read8' */

  /* S-Function Block: <S416>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8_dh =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stElement_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S416>/autosar_irv_read7' */

  /* S-Function Block: <S416>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7_j =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stElement_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S416>/autosar_irv_read6' */

  /* S-Function Block: <S416>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6_pl =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stElement_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S416>/autosar_irv_read5' */

  /* S-Function Block: <S416>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5_a =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stElement_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S416>/autosar_irv_read4' */

  /* S-Function Block: <S416>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_k =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stElement_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S416>/autosar_irv_read3' */

  /* S-Function Block: <S416>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_n =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stElement_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S416>/autosar_irv_read2' */

  /* S-Function Block: <S416>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_f =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stElement_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S416>/autosar_irv_read1' */

  /* S-Function Block: <S416>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_df =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stElement_01_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S417>/autosar_irv_read8' */

  /* S-Function Block: <S417>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8_h =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stNbTypElement_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S417>/autosar_irv_read7' */

  /* S-Function Block: <S417>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7_j2 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stNbTypElement_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S417>/autosar_irv_read6' */

  /* S-Function Block: <S417>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6_ii =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stNbTypElement_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S417>/autosar_irv_read5' */

  /* S-Function Block: <S417>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5_cj =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stNbTypElement_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S417>/autosar_irv_read4' */

  /* S-Function Block: <S417>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_gj =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stNbTypElement_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S417>/autosar_irv_read3' */

  /* S-Function Block: <S417>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_dr =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stNbTypElement_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S417>/autosar_irv_read2' */

  /* S-Function Block: <S417>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_d =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stNbTypElement_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S417>/autosar_irv_read1' */

  /* S-Function Block: <S417>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_m =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_stNbTypElement_01_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read12' */

  /* S-Function Block: <S415>/autosar_irv_read12 */
  ExMGslT2_B.autosar_irv_read12 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_12_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read11' */

  /* S-Function Block: <S415>/autosar_irv_read11 */
  ExMGslT2_B.autosar_irv_read11 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_11_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read10' */

  /* S-Function Block: <S415>/autosar_irv_read10 */
  ExMGslT2_B.autosar_irv_read10 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_10_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read9' */

  /* S-Function Block: <S415>/autosar_irv_read9 */
  ExMGslT2_B.autosar_irv_read9 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_09_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read8' */

  /* S-Function Block: <S415>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read7' */

  /* S-Function Block: <S415>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read6' */

  /* S-Function Block: <S415>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read5' */

  /* S-Function Block: <S415>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read4' */

  /* S-Function Block: <S415>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read3' */

  /* S-Function Block: <S415>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read2' */

  /* S-Function Block: <S415>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S415>/autosar_irv_read1' */

  /* S-Function Block: <S415>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1 =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_pEgRaw_01_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read12' */

  /* S-Function Block: <S418>/autosar_irv_read12 */
  ExMGslT2_B.autosar_irv_read12_i =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_12_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read11' */

  /* S-Function Block: <S418>/autosar_irv_read11 */
  ExMGslT2_B.autosar_irv_read11_n =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_11_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read10' */

  /* S-Function Block: <S418>/autosar_irv_read10 */
  ExMGslT2_B.autosar_irv_read10_e =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_10_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read9' */

  /* S-Function Block: <S418>/autosar_irv_read9 */
  ExMGslT2_B.autosar_irv_read9_m =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_09_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read8' */

  /* S-Function Block: <S418>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8_a =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read7' */

  /* S-Function Block: <S418>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7_k =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read6' */

  /* S-Function Block: <S418>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6_l =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read5' */

  /* S-Function Block: <S418>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5_k =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read4' */

  /* S-Function Block: <S418>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_c =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read3' */

  /* S-Function Block: <S418>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_d =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read2' */

  /* S-Function Block: <S418>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_g =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S418>/autosar_irv_read1' */

  /* S-Function Block: <S418>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_n =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_01_irv();

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_mfAirScvCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfAirScvCor'
   */
  Rte_Read_R_EngM_mfAirScvCor_EngM_mfAirScvCor
    (&ExMGslT2_B.TmpSignalConversionAtEngM_mfAir);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInjSys_noCylCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_noCylCutOff'
   */
  Rte_Read_R_InjSys_noCylCutOff_InjSys_noCylCutOff
    (&ExMGslT2_B.TmpSignalConversionAtInjSys_noC);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp
    (&ExMGslT2_B.TmpSignalConversionAtFARSp_rMix);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngM_mfAirCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfAirCor'
   */
  Rte_Read_R_EngM_mfAirCor_EngM_mfAirCor
    (&ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_bAdFanActOutport2' incorporates:
   *  Inport: '<Root>/Ext_bAdFanAct'
   */
  Rte_Read_R_Ext_bAdFanAct_Ext_bAdFanAct
    (&ExMGslT2_B.TmpSignalConversionAtExt_bAdFan);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtThMgt_bPosnFSFOutport2' incorporates:
   *  Inport: '<Root>/ThMgt_bPosnFSF'
   */
  Rte_Read_R_ThMgt_bPosnFSF_ThMgt_bPosnFSF
    (&ExMGslT2_B.TmpSignalConversionAtThMgt_bPos);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_stTypInjSysCfOutport2' incorporates:
   *  Inport: '<Root>/Ext_stTypInjSysCf'
   */
  Rte_Read_R_Ext_stTypInjSysCf_Ext_stTypInjSysCf
    (&ExMGslT2_B.TmpSignalConversionAtExt_stTypI);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_tAirOutport2' incorporates:
   *  Inport: '<Root>/Ext_tAir'
   */
  Rte_Read_R_Ext_tAir_Ext_tAir(&ExMGslT2_B.TmpSignalConversionAtExt_tAirOu);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ExMGslT2_B.TmpSignalConversionAtExt_tCoMes);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtVeh_spdVehOutport2' incorporates:
   *  Inport: '<Root>/Veh_spdVeh'
   */
  Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_rSpdFanActOutport2' incorporates:
   *  Inport: '<Root>/Ext_rSpdFanAct'
   */
  Rte_Read_R_Ext_rSpdFanAct_Ext_rSpdFanAct
    (&ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&ExMGslT2_B.TmpSignalConversionAtExt_nEngOu);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S7>/autosar_irv_read4' */

  /* S-Function Block: <S7>/autosar_irv_read4 */
  ExM_mfTrbEstimSatRef = Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_mfTrbEstimSat_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S7>/autosar_irv_read1' */

  /* S-Function Block: <S7>/autosar_irv_read1 */
  ExM_mfWgEstimRef = Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_mfWgEstim_irv();

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tEgMesOutport2' incorporates:
   *  Inport: '<Root>/ExM_tEgMes'
   */
  Rte_Read_R_ExM_tEgMes_ExM_tEgMes(&ExMGslT2_B.TmpSignalConversionAtExM_tEgMes);

  /* S-Function (sfun_autosar_clientop): '<S422>/AutosarServer' */
  Rte_Call_R_FRM_bSenTEg_GetFunctionPermission(&localAutosarServer_a);

  /* Logic: '<S422>/Not' */
  ExMGslT2_B.Not = !localAutosarServer_a;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAfuA_rEthWiExctOutport2' incorporates:
   *  Inport: '<Root>/AfuA_rEthWiExct'
   */
  Rte_Read_R_AfuA_rEthWiExct_AfuA_rEthWiExct
    (&ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_rDynIgSpEfcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rDynIgSpEfc'
   */
  Rte_Read_R_IgSys_rDynIgSpEfc_IgSys_rDynIgSpEfc
    (&ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAfuA_bInvldEthRatOutport2' incorporates:
   *  Inport: '<Root>/AfuA_bInvldEthRat'
   */
  Rte_Read_R_AfuA_bInvldEthRat_AfuA_bInvldEthRat
    (&ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExDynOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExDyn'
   */
  Rte_Read_R_ExM_tExDyn_ExM_tExDyn(&ExMGslT2_B.TmpSignalConversionAtExM_tExDyn);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read12' */

  /* S-Function Block: <S409>/autosar_irv_read12 */
  ExMGslT2_B.autosar_irv_read12_p =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_12_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read11' */

  /* S-Function Block: <S409>/autosar_irv_read11 */
  ExMGslT2_B.autosar_irv_read11_i =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_11_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read10' */

  /* S-Function Block: <S409>/autosar_irv_read10 */
  ExMGslT2_B.autosar_irv_read10_i =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_10_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read9' */

  /* S-Function Block: <S409>/autosar_irv_read9 */
  ExMGslT2_B.autosar_irv_read9_i =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_09_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read8' */

  /* S-Function Block: <S409>/autosar_irv_read8 */
  ExMGslT2_B.autosar_irv_read8_d =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_08_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read7' */

  /* S-Function Block: <S409>/autosar_irv_read7 */
  ExMGslT2_B.autosar_irv_read7_e =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_07_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read6' */

  /* S-Function Block: <S409>/autosar_irv_read6 */
  ExMGslT2_B.autosar_irv_read6_i =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_06_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read5' */

  /* S-Function Block: <S409>/autosar_irv_read5 */
  ExMGslT2_B.autosar_irv_read5_i =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_05_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read4' */

  /* S-Function Block: <S409>/autosar_irv_read4 */
  ExMGslT2_B.autosar_irv_read4_cs =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_04_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read3' */

  /* S-Function Block: <S409>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_h =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read2' */

  /* S-Function Block: <S409>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_m =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S409>/autosar_irv_read1' */

  /* S-Function Block: <S409>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_o =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tWall_01_irv();

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_lamTotOutport2' incorporates:
   *  Inport: '<Root>/ExM_lamTot'
   */
  Rte_Read_R_ExM_lamTot_ExM_lamTot(&ExMGslT2_B.TmpSignalConversionAtExM_lamTot);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S419>/autosar_irv_read3' */

  /* S-Function Block: <S419>/autosar_irv_read3 */
  ExMGslT2_B.autosar_irv_read3_f =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgOxC_03_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S419>/autosar_irv_read2' */

  /* S-Function Block: <S419>/autosar_irv_read2 */
  ExMGslT2_B.autosar_irv_read2_p =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgOxC_02_irv();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S419>/autosar_irv_read1' */

  /* S-Function Block: <S419>/autosar_irv_read1 */
  ExMGslT2_B.autosar_irv_read1_od =
    Rte_IrvRead_RE_ExMGslT2_007_TEV_ExM_prm_tEgOxC_01_irv();

  /* Embedded MATLAB: '<S7>/F01_ExM2T_Task_sceduler' incorporates:
   *  SubSystem: '<S7>/F02_ExM2T_Library_input'
   *  SubSystem: '<S7>/F03_ExM2T_Library_output'
   *  SubSystem: '<S7>/LibT'
   */
  /* Embedded MATLAB Function 'ExMGslT2/F03_ExM2T/F01_ExM2T_Task_sceduler': '<S411>:1' */
  /* '<S411>:1:5' */

  /* Outputs for atomic SubSystem: '<S412>/F02_Input_conditions_for_temperature_library' */

  /* DataTypeConversion: '<S451>/Data Type Conversion' */
  localDataTypeConversion_n = (((Float32)
    ExMGslT2_B.TmpSignalConversionAtExM_tExDyn) * 0.03125F) + 223.0F;

  /* SignalConversion: '<S451>/Signal Conversion2' */
  ExM_prm_tWallPrev[0] = ExMGslT2_B.autosar_irv_read1_o;
  ExM_prm_tWallPrev[1] = ExMGslT2_B.autosar_irv_read2_m;
  ExM_prm_tWallPrev[2] = ExMGslT2_B.autosar_irv_read3_h;
  ExM_prm_tWallPrev[3] = ExMGslT2_B.autosar_irv_read4_cs;
  ExM_prm_tWallPrev[4] = ExMGslT2_B.autosar_irv_read5_i;
  ExM_prm_tWallPrev[5] = ExMGslT2_B.autosar_irv_read6_i;
  ExM_prm_tWallPrev[6] = ExMGslT2_B.autosar_irv_read7_e;
  ExM_prm_tWallPrev[7] = ExMGslT2_B.autosar_irv_read8_d;
  ExM_prm_tWallPrev[8] = ExMGslT2_B.autosar_irv_read9_i;
  ExM_prm_tWallPrev[9] = ExMGslT2_B.autosar_irv_read10_i;
  ExM_prm_tWallPrev[10] = ExMGslT2_B.autosar_irv_read11_i;
  ExM_prm_tWallPrev[11] = ExMGslT2_B.autosar_irv_read12_p;

  /* Assignment: '<S455>/Assignment' incorporates:
   *  Constant: '<S451>/Cste_31'
   *  Constant: '<S455>/Constant'
   *  Constant: '<S455>/Constant1'
   *  MinMax: '<S455>/MinMax'
   *  Sum: '<S455>/Add'
   */
  for (locali = 0; locali < 12; locali++) {
    localAssignment_l[locali] = ExM_prm_tWallPrev[(locali)];
  }

  localAssignment_l[0] = localDataTypeConversion_n;

  /* SignalConversion: '<S451>/Signal Conversion3' */
  ExM_prm_tEgPrev[0] = ExMGslT2_B.autosar_irv_read1_n;
  ExM_prm_tEgPrev[1] = ExMGslT2_B.autosar_irv_read2_g;
  ExM_prm_tEgPrev[2] = ExMGslT2_B.autosar_irv_read3_d;
  ExM_prm_tEgPrev[3] = ExMGslT2_B.autosar_irv_read4_c;
  ExM_prm_tEgPrev[4] = ExMGslT2_B.autosar_irv_read5_k;
  ExM_prm_tEgPrev[5] = ExMGslT2_B.autosar_irv_read6_l;
  ExM_prm_tEgPrev[6] = ExMGslT2_B.autosar_irv_read7_k;
  ExM_prm_tEgPrev[7] = ExMGslT2_B.autosar_irv_read8_a;
  ExM_prm_tEgPrev[8] = ExMGslT2_B.autosar_irv_read9_m;
  ExM_prm_tEgPrev[9] = ExMGslT2_B.autosar_irv_read10_e;
  ExM_prm_tEgPrev[10] = ExMGslT2_B.autosar_irv_read11_n;
  ExM_prm_tEgPrev[11] = ExMGslT2_B.autosar_irv_read12_i;

  /* Assignment: '<S456>/Assignment' incorporates:
   *  Constant: '<S451>/Cste_32'
   *  Constant: '<S456>/Constant'
   *  Constant: '<S456>/Constant1'
   *  MinMax: '<S456>/MinMax'
   *  Sum: '<S456>/Add'
   */
  for (locali = 0; locali < 12; locali++) {
    localAssignment_m1[locali] = ExM_prm_tEgPrev[(locali)];
  }

  localAssignment_m1[0] = localDataTypeConversion_n;

  /* SignalConversion: '<S451>/Signal Conversion1' */
  ExM_tEgOut = localDataTypeConversion_n;
  for (locali = 0; locali < 12; locali++) {
    /* SignalConversion: '<S451>/Signal Conversion5' */
    ExM_prm_tEgInter[(locali)] = localAssignment_m1[locali];

    /* SignalConversion: '<S451>/Signal Conversion6' */
    ExM_prm_tWallInter[(locali)] = localAssignment_l[locali];
  }

  /* SignalConversion: '<S451>/Signal Conversion7' incorporates:
   *  Constant: '<S451>/Cste_30'
   */
  ExM_noIdxOxC = 0U;

  /* SignalConversion: '<S451>/Signal Conversion8' incorporates:
   *  Constant: '<S451>/Cste_30'
   */
  ExM_noIdxT = 0U;

  /* SignalConversion: '<S451>/Signal Conversion4' */
  ExM_prm_tEgOxC[0] = ExMGslT2_B.autosar_irv_read1_od;
  ExM_prm_tEgOxC[1] = ExMGslT2_B.autosar_irv_read2_p;
  ExM_prm_tEgOxC[2] = ExMGslT2_B.autosar_irv_read3_f;

  /* end of Outputs for SubSystem: '<S412>/F02_Input_conditions_for_temperature_library' */

  /* Outputs for atomic SubSystem: '<S412>/F01_Air_fuel_ratio' */

  /* DataTypeConversion: '<S450>/Data Type Conversion1' */
  localDataTypeConversion_n = ((Float32)
    ExMGslT2_B.TmpSignalConversionAtExM_lamTot) * 0.0001220703125F;

  /* Switch: '<S452>/Switch' incorporates:
   *  Constant: '<S452>/ '
   *  Constant: '<S452>/ 1'
   *  Constant: '<S452>/constant'
   *  RelationalOperator: '<S452>/Relational Operator'
   */
  localProduct_g = 3.051757813E-005F;

  /* Switch: '<S452>/Switch2' incorporates:
   *  Abs: '<S452>/Abs'
   *  Constant: '<S452>/ '
   *  RelationalOperator: '<S452>/Relational Operator1'
   */
  if (!(localDataTypeConversion_n < 3.051757813E-005F)) {
    localProduct_g = localDataTypeConversion_n;
  }

  /* Product: '<S452>/Product' incorporates:
   *  Constant: '<S450>/Cste_33'
   */
  localProduct_g = 1.0F / localProduct_g;

  /* Switch: '<S454>/Switch' incorporates:
   *  Constant: '<S452>/SatMinDiv'
   *  RelationalOperator: '<S454>/UpperRelop'
   */
  if (localProduct_g < -1.0E+005F) {
    localDataTypeConversion_n = -1.0E+005F;
  } else {
    localDataTypeConversion_n = localProduct_g;
  }

  /* Switch: '<S454>/Switch2' incorporates:
   *  Constant: '<S452>/SatMaxDiv'
   *  RelationalOperator: '<S454>/LowerRelop1'
   */
  if (localProduct_g > 1.0E+005F) {
    localDataTypeConversion_n = 1.0E+005F;
  }

  /* Switch: '<S452>/Switch1' incorporates:
   *  Constant: '<S452>/Constant2'
   *  RelationalOperator: '<S452>/Relational Operator2'
   */
  if (localProduct_g != localProduct_g) {
    ExM_rMixtInp = 0.0F;
  } else {
    ExM_rMixtInp = localDataTypeConversion_n;
  }

  /* end of Outputs for SubSystem: '<S412>/F01_Air_fuel_ratio' */
  /* '<S411>:1:7' */
  ExMGslT2_LibT(&ExM_noIdxT, (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC,
                ExMGslT2_B.Not, ExMGslT2_B.autosar_irv_read1,
                ExMGslT2_B.autosar_irv_read2, ExMGslT2_B.autosar_irv_read3,
                ExMGslT2_B.autosar_irv_read4, ExMGslT2_B.autosar_irv_read5,
                ExMGslT2_B.autosar_irv_read6, ExMGslT2_B.autosar_irv_read7,
                ExMGslT2_B.autosar_irv_read8, ExMGslT2_B.autosar_irv_read9,
                ExMGslT2_B.autosar_irv_read10, ExMGslT2_B.autosar_irv_read11,
                ExMGslT2_B.autosar_irv_read12, (&(ExM_prm_tWallInter[0])),
                ExMGslT2_B.autosar_irv_read1_df, ExMGslT2_B.autosar_irv_read2_f,
                ExMGslT2_B.autosar_irv_read3_n, ExMGslT2_B.autosar_irv_read4_k,
                ExMGslT2_B.autosar_irv_read5_a, ExMGslT2_B.autosar_irv_read6_pl,
                ExMGslT2_B.autosar_irv_read7_j, ExMGslT2_B.autosar_irv_read8_dh,
                ExMGslT2_B.autosar_irv_read1_m, ExMGslT2_B.autosar_irv_read2_d,
                ExMGslT2_B.autosar_irv_read3_dr, ExMGslT2_B.autosar_irv_read4_gj,
                ExMGslT2_B.autosar_irv_read5_cj, ExMGslT2_B.autosar_irv_read6_ii,
                ExMGslT2_B.autosar_irv_read7_j2, ExMGslT2_B.autosar_irv_read8_h,
                ExMGslT2_B.autosar_irv_read1_n, ExMGslT2_B.autosar_irv_read2_g,
                ExMGslT2_B.autosar_irv_read3_d, ExMGslT2_B.autosar_irv_read4_c,
                ExMGslT2_B.autosar_irv_read5_k, ExMGslT2_B.autosar_irv_read6_l,
                ExMGslT2_B.autosar_irv_read7_k, ExMGslT2_B.autosar_irv_read8_a,
                ExMGslT2_B.autosar_irv_read9_m, ExMGslT2_B.autosar_irv_read10_e,
                ExMGslT2_B.autosar_irv_read11_n, ExMGslT2_B.autosar_irv_read12_i,
                ExMGslT2_B.TmpSignalConversionAtExt_tCoMes,
                ExMGslT2_B.TmpSignalConversionAtExt_tAirOu, &ExM_tEgOut,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
                ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh,
                ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa,
                ExMGslT2_B.TmpSignalConversionAtExt_nEngOu, ExM_mfTrbEstimSatRef,
                ExM_mfWgEstimRef, ExMGslT2_B.TmpSignalConversionAtFARSp_rMix,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j,
                ExMGslT2_B.TmpSignalConversionAtInjSys_noC,
                ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl,
                ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW,
                ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn,
                ExMGslT2_B.TmpSignalConversionAtThMgt_bPos,
                ExMGslT2_B.TmpSignalConversionAtExt_bAdFan,
                ExMGslT2_B.TmpSignalConversionAtExt_stTypI,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfAir, ExM_rMixtInp,
                ExMGslT2_B.TmpSignalConversionAtExM_tEgMes, (&(ExM_prm_tEgInter
    [0])), (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC, &ExM_tEgOut, &ExM_noIdxT,
                (&(ExM_prm_tEgInter[0])), (&(ExM_prm_tWallInter[0])),
                &ExMGslT2_B.LibT, &ExMGslT2_DWork.LibT);

  /* '<S411>:1:8' */
  ExMGslT2_LibT(&ExM_noIdxT, (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC,
                ExMGslT2_B.Not, ExMGslT2_B.autosar_irv_read1,
                ExMGslT2_B.autosar_irv_read2, ExMGslT2_B.autosar_irv_read3,
                ExMGslT2_B.autosar_irv_read4, ExMGslT2_B.autosar_irv_read5,
                ExMGslT2_B.autosar_irv_read6, ExMGslT2_B.autosar_irv_read7,
                ExMGslT2_B.autosar_irv_read8, ExMGslT2_B.autosar_irv_read9,
                ExMGslT2_B.autosar_irv_read10, ExMGslT2_B.autosar_irv_read11,
                ExMGslT2_B.autosar_irv_read12, (&(ExM_prm_tWallInter[0])),
                ExMGslT2_B.autosar_irv_read1_df, ExMGslT2_B.autosar_irv_read2_f,
                ExMGslT2_B.autosar_irv_read3_n, ExMGslT2_B.autosar_irv_read4_k,
                ExMGslT2_B.autosar_irv_read5_a, ExMGslT2_B.autosar_irv_read6_pl,
                ExMGslT2_B.autosar_irv_read7_j, ExMGslT2_B.autosar_irv_read8_dh,
                ExMGslT2_B.autosar_irv_read1_m, ExMGslT2_B.autosar_irv_read2_d,
                ExMGslT2_B.autosar_irv_read3_dr, ExMGslT2_B.autosar_irv_read4_gj,
                ExMGslT2_B.autosar_irv_read5_cj, ExMGslT2_B.autosar_irv_read6_ii,
                ExMGslT2_B.autosar_irv_read7_j2, ExMGslT2_B.autosar_irv_read8_h,
                ExMGslT2_B.autosar_irv_read1_n, ExMGslT2_B.autosar_irv_read2_g,
                ExMGslT2_B.autosar_irv_read3_d, ExMGslT2_B.autosar_irv_read4_c,
                ExMGslT2_B.autosar_irv_read5_k, ExMGslT2_B.autosar_irv_read6_l,
                ExMGslT2_B.autosar_irv_read7_k, ExMGslT2_B.autosar_irv_read8_a,
                ExMGslT2_B.autosar_irv_read9_m, ExMGslT2_B.autosar_irv_read10_e,
                ExMGslT2_B.autosar_irv_read11_n, ExMGslT2_B.autosar_irv_read12_i,
                ExMGslT2_B.TmpSignalConversionAtExt_tCoMes,
                ExMGslT2_B.TmpSignalConversionAtExt_tAirOu, &ExM_tEgOut,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
                ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh,
                ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa,
                ExMGslT2_B.TmpSignalConversionAtExt_nEngOu, ExM_mfTrbEstimSatRef,
                ExM_mfWgEstimRef, ExMGslT2_B.TmpSignalConversionAtFARSp_rMix,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j,
                ExMGslT2_B.TmpSignalConversionAtInjSys_noC,
                ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl,
                ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW,
                ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn,
                ExMGslT2_B.TmpSignalConversionAtThMgt_bPos,
                ExMGslT2_B.TmpSignalConversionAtExt_bAdFan,
                ExMGslT2_B.TmpSignalConversionAtExt_stTypI,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfAir, ExM_rMixtInp,
                ExMGslT2_B.TmpSignalConversionAtExM_tEgMes, (&(ExM_prm_tEgInter
    [0])), (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC, &ExM_tEgOut, &ExM_noIdxT,
                (&(ExM_prm_tEgInter[0])), (&(ExM_prm_tWallInter[0])),
                &ExMGslT2_B.LibT, &ExMGslT2_DWork.LibT);

  /* '<S411>:1:9' */
  ExMGslT2_LibT(&ExM_noIdxT, (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC,
                ExMGslT2_B.Not, ExMGslT2_B.autosar_irv_read1,
                ExMGslT2_B.autosar_irv_read2, ExMGslT2_B.autosar_irv_read3,
                ExMGslT2_B.autosar_irv_read4, ExMGslT2_B.autosar_irv_read5,
                ExMGslT2_B.autosar_irv_read6, ExMGslT2_B.autosar_irv_read7,
                ExMGslT2_B.autosar_irv_read8, ExMGslT2_B.autosar_irv_read9,
                ExMGslT2_B.autosar_irv_read10, ExMGslT2_B.autosar_irv_read11,
                ExMGslT2_B.autosar_irv_read12, (&(ExM_prm_tWallInter[0])),
                ExMGslT2_B.autosar_irv_read1_df, ExMGslT2_B.autosar_irv_read2_f,
                ExMGslT2_B.autosar_irv_read3_n, ExMGslT2_B.autosar_irv_read4_k,
                ExMGslT2_B.autosar_irv_read5_a, ExMGslT2_B.autosar_irv_read6_pl,
                ExMGslT2_B.autosar_irv_read7_j, ExMGslT2_B.autosar_irv_read8_dh,
                ExMGslT2_B.autosar_irv_read1_m, ExMGslT2_B.autosar_irv_read2_d,
                ExMGslT2_B.autosar_irv_read3_dr, ExMGslT2_B.autosar_irv_read4_gj,
                ExMGslT2_B.autosar_irv_read5_cj, ExMGslT2_B.autosar_irv_read6_ii,
                ExMGslT2_B.autosar_irv_read7_j2, ExMGslT2_B.autosar_irv_read8_h,
                ExMGslT2_B.autosar_irv_read1_n, ExMGslT2_B.autosar_irv_read2_g,
                ExMGslT2_B.autosar_irv_read3_d, ExMGslT2_B.autosar_irv_read4_c,
                ExMGslT2_B.autosar_irv_read5_k, ExMGslT2_B.autosar_irv_read6_l,
                ExMGslT2_B.autosar_irv_read7_k, ExMGslT2_B.autosar_irv_read8_a,
                ExMGslT2_B.autosar_irv_read9_m, ExMGslT2_B.autosar_irv_read10_e,
                ExMGslT2_B.autosar_irv_read11_n, ExMGslT2_B.autosar_irv_read12_i,
                ExMGslT2_B.TmpSignalConversionAtExt_tCoMes,
                ExMGslT2_B.TmpSignalConversionAtExt_tAirOu, &ExM_tEgOut,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
                ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh,
                ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa,
                ExMGslT2_B.TmpSignalConversionAtExt_nEngOu, ExM_mfTrbEstimSatRef,
                ExM_mfWgEstimRef, ExMGslT2_B.TmpSignalConversionAtFARSp_rMix,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j,
                ExMGslT2_B.TmpSignalConversionAtInjSys_noC,
                ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl,
                ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW,
                ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn,
                ExMGslT2_B.TmpSignalConversionAtThMgt_bPos,
                ExMGslT2_B.TmpSignalConversionAtExt_bAdFan,
                ExMGslT2_B.TmpSignalConversionAtExt_stTypI,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfAir, ExM_rMixtInp,
                ExMGslT2_B.TmpSignalConversionAtExM_tEgMes, (&(ExM_prm_tEgInter
    [0])), (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC, &ExM_tEgOut, &ExM_noIdxT,
                (&(ExM_prm_tEgInter[0])), (&(ExM_prm_tWallInter[0])),
                &ExMGslT2_B.LibT, &ExMGslT2_DWork.LibT);

  /* '<S411>:1:10' */
  ExMGslT2_LibT(&ExM_noIdxT, (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC,
                ExMGslT2_B.Not, ExMGslT2_B.autosar_irv_read1,
                ExMGslT2_B.autosar_irv_read2, ExMGslT2_B.autosar_irv_read3,
                ExMGslT2_B.autosar_irv_read4, ExMGslT2_B.autosar_irv_read5,
                ExMGslT2_B.autosar_irv_read6, ExMGslT2_B.autosar_irv_read7,
                ExMGslT2_B.autosar_irv_read8, ExMGslT2_B.autosar_irv_read9,
                ExMGslT2_B.autosar_irv_read10, ExMGslT2_B.autosar_irv_read11,
                ExMGslT2_B.autosar_irv_read12, (&(ExM_prm_tWallInter[0])),
                ExMGslT2_B.autosar_irv_read1_df, ExMGslT2_B.autosar_irv_read2_f,
                ExMGslT2_B.autosar_irv_read3_n, ExMGslT2_B.autosar_irv_read4_k,
                ExMGslT2_B.autosar_irv_read5_a, ExMGslT2_B.autosar_irv_read6_pl,
                ExMGslT2_B.autosar_irv_read7_j, ExMGslT2_B.autosar_irv_read8_dh,
                ExMGslT2_B.autosar_irv_read1_m, ExMGslT2_B.autosar_irv_read2_d,
                ExMGslT2_B.autosar_irv_read3_dr, ExMGslT2_B.autosar_irv_read4_gj,
                ExMGslT2_B.autosar_irv_read5_cj, ExMGslT2_B.autosar_irv_read6_ii,
                ExMGslT2_B.autosar_irv_read7_j2, ExMGslT2_B.autosar_irv_read8_h,
                ExMGslT2_B.autosar_irv_read1_n, ExMGslT2_B.autosar_irv_read2_g,
                ExMGslT2_B.autosar_irv_read3_d, ExMGslT2_B.autosar_irv_read4_c,
                ExMGslT2_B.autosar_irv_read5_k, ExMGslT2_B.autosar_irv_read6_l,
                ExMGslT2_B.autosar_irv_read7_k, ExMGslT2_B.autosar_irv_read8_a,
                ExMGslT2_B.autosar_irv_read9_m, ExMGslT2_B.autosar_irv_read10_e,
                ExMGslT2_B.autosar_irv_read11_n, ExMGslT2_B.autosar_irv_read12_i,
                ExMGslT2_B.TmpSignalConversionAtExt_tCoMes,
                ExMGslT2_B.TmpSignalConversionAtExt_tAirOu, &ExM_tEgOut,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
                ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh,
                ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa,
                ExMGslT2_B.TmpSignalConversionAtExt_nEngOu, ExM_mfTrbEstimSatRef,
                ExM_mfWgEstimRef, ExMGslT2_B.TmpSignalConversionAtFARSp_rMix,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j,
                ExMGslT2_B.TmpSignalConversionAtInjSys_noC,
                ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl,
                ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW,
                ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn,
                ExMGslT2_B.TmpSignalConversionAtThMgt_bPos,
                ExMGslT2_B.TmpSignalConversionAtExt_bAdFan,
                ExMGslT2_B.TmpSignalConversionAtExt_stTypI,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfAir, ExM_rMixtInp,
                ExMGslT2_B.TmpSignalConversionAtExM_tEgMes, (&(ExM_prm_tEgInter
    [0])), (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC, &ExM_tEgOut, &ExM_noIdxT,
                (&(ExM_prm_tEgInter[0])), (&(ExM_prm_tWallInter[0])),
                &ExMGslT2_B.LibT, &ExMGslT2_DWork.LibT);

  /* '<S411>:1:11' */
  ExMGslT2_LibT(&ExM_noIdxT, (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC,
                ExMGslT2_B.Not, ExMGslT2_B.autosar_irv_read1,
                ExMGslT2_B.autosar_irv_read2, ExMGslT2_B.autosar_irv_read3,
                ExMGslT2_B.autosar_irv_read4, ExMGslT2_B.autosar_irv_read5,
                ExMGslT2_B.autosar_irv_read6, ExMGslT2_B.autosar_irv_read7,
                ExMGslT2_B.autosar_irv_read8, ExMGslT2_B.autosar_irv_read9,
                ExMGslT2_B.autosar_irv_read10, ExMGslT2_B.autosar_irv_read11,
                ExMGslT2_B.autosar_irv_read12, (&(ExM_prm_tWallInter[0])),
                ExMGslT2_B.autosar_irv_read1_df, ExMGslT2_B.autosar_irv_read2_f,
                ExMGslT2_B.autosar_irv_read3_n, ExMGslT2_B.autosar_irv_read4_k,
                ExMGslT2_B.autosar_irv_read5_a, ExMGslT2_B.autosar_irv_read6_pl,
                ExMGslT2_B.autosar_irv_read7_j, ExMGslT2_B.autosar_irv_read8_dh,
                ExMGslT2_B.autosar_irv_read1_m, ExMGslT2_B.autosar_irv_read2_d,
                ExMGslT2_B.autosar_irv_read3_dr, ExMGslT2_B.autosar_irv_read4_gj,
                ExMGslT2_B.autosar_irv_read5_cj, ExMGslT2_B.autosar_irv_read6_ii,
                ExMGslT2_B.autosar_irv_read7_j2, ExMGslT2_B.autosar_irv_read8_h,
                ExMGslT2_B.autosar_irv_read1_n, ExMGslT2_B.autosar_irv_read2_g,
                ExMGslT2_B.autosar_irv_read3_d, ExMGslT2_B.autosar_irv_read4_c,
                ExMGslT2_B.autosar_irv_read5_k, ExMGslT2_B.autosar_irv_read6_l,
                ExMGslT2_B.autosar_irv_read7_k, ExMGslT2_B.autosar_irv_read8_a,
                ExMGslT2_B.autosar_irv_read9_m, ExMGslT2_B.autosar_irv_read10_e,
                ExMGslT2_B.autosar_irv_read11_n, ExMGslT2_B.autosar_irv_read12_i,
                ExMGslT2_B.TmpSignalConversionAtExt_tCoMes,
                ExMGslT2_B.TmpSignalConversionAtExt_tAirOu, &ExM_tEgOut,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
                ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh,
                ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa,
                ExMGslT2_B.TmpSignalConversionAtExt_nEngOu, ExM_mfTrbEstimSatRef,
                ExM_mfWgEstimRef, ExMGslT2_B.TmpSignalConversionAtFARSp_rMix,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j,
                ExMGslT2_B.TmpSignalConversionAtInjSys_noC,
                ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl,
                ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW,
                ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn,
                ExMGslT2_B.TmpSignalConversionAtThMgt_bPos,
                ExMGslT2_B.TmpSignalConversionAtExt_bAdFan,
                ExMGslT2_B.TmpSignalConversionAtExt_stTypI,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfAir, ExM_rMixtInp,
                ExMGslT2_B.TmpSignalConversionAtExM_tEgMes, (&(ExM_prm_tEgInter
    [0])), (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC, &ExM_tEgOut, &ExM_noIdxT,
                (&(ExM_prm_tEgInter[0])), (&(ExM_prm_tWallInter[0])),
                &ExMGslT2_B.LibT, &ExMGslT2_DWork.LibT);

  /* '<S411>:1:12' */
  ExMGslT2_LibT(&ExM_noIdxT, (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC,
                ExMGslT2_B.Not, ExMGslT2_B.autosar_irv_read1,
                ExMGslT2_B.autosar_irv_read2, ExMGslT2_B.autosar_irv_read3,
                ExMGslT2_B.autosar_irv_read4, ExMGslT2_B.autosar_irv_read5,
                ExMGslT2_B.autosar_irv_read6, ExMGslT2_B.autosar_irv_read7,
                ExMGslT2_B.autosar_irv_read8, ExMGslT2_B.autosar_irv_read9,
                ExMGslT2_B.autosar_irv_read10, ExMGslT2_B.autosar_irv_read11,
                ExMGslT2_B.autosar_irv_read12, (&(ExM_prm_tWallInter[0])),
                ExMGslT2_B.autosar_irv_read1_df, ExMGslT2_B.autosar_irv_read2_f,
                ExMGslT2_B.autosar_irv_read3_n, ExMGslT2_B.autosar_irv_read4_k,
                ExMGslT2_B.autosar_irv_read5_a, ExMGslT2_B.autosar_irv_read6_pl,
                ExMGslT2_B.autosar_irv_read7_j, ExMGslT2_B.autosar_irv_read8_dh,
                ExMGslT2_B.autosar_irv_read1_m, ExMGslT2_B.autosar_irv_read2_d,
                ExMGslT2_B.autosar_irv_read3_dr, ExMGslT2_B.autosar_irv_read4_gj,
                ExMGslT2_B.autosar_irv_read5_cj, ExMGslT2_B.autosar_irv_read6_ii,
                ExMGslT2_B.autosar_irv_read7_j2, ExMGslT2_B.autosar_irv_read8_h,
                ExMGslT2_B.autosar_irv_read1_n, ExMGslT2_B.autosar_irv_read2_g,
                ExMGslT2_B.autosar_irv_read3_d, ExMGslT2_B.autosar_irv_read4_c,
                ExMGslT2_B.autosar_irv_read5_k, ExMGslT2_B.autosar_irv_read6_l,
                ExMGslT2_B.autosar_irv_read7_k, ExMGslT2_B.autosar_irv_read8_a,
                ExMGslT2_B.autosar_irv_read9_m, ExMGslT2_B.autosar_irv_read10_e,
                ExMGslT2_B.autosar_irv_read11_n, ExMGslT2_B.autosar_irv_read12_i,
                ExMGslT2_B.TmpSignalConversionAtExt_tCoMes,
                ExMGslT2_B.TmpSignalConversionAtExt_tAirOu, &ExM_tEgOut,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
                ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh,
                ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa,
                ExMGslT2_B.TmpSignalConversionAtExt_nEngOu, ExM_mfTrbEstimSatRef,
                ExM_mfWgEstimRef, ExMGslT2_B.TmpSignalConversionAtFARSp_rMix,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j,
                ExMGslT2_B.TmpSignalConversionAtInjSys_noC,
                ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl,
                ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW,
                ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn,
                ExMGslT2_B.TmpSignalConversionAtThMgt_bPos,
                ExMGslT2_B.TmpSignalConversionAtExt_bAdFan,
                ExMGslT2_B.TmpSignalConversionAtExt_stTypI,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfAir, ExM_rMixtInp,
                ExMGslT2_B.TmpSignalConversionAtExM_tEgMes, (&(ExM_prm_tEgInter
    [0])), (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC, &ExM_tEgOut, &ExM_noIdxT,
                (&(ExM_prm_tEgInter[0])), (&(ExM_prm_tWallInter[0])),
                &ExMGslT2_B.LibT, &ExMGslT2_DWork.LibT);

  /* '<S411>:1:13' */
  ExMGslT2_LibT(&ExM_noIdxT, (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC,
                ExMGslT2_B.Not, ExMGslT2_B.autosar_irv_read1,
                ExMGslT2_B.autosar_irv_read2, ExMGslT2_B.autosar_irv_read3,
                ExMGslT2_B.autosar_irv_read4, ExMGslT2_B.autosar_irv_read5,
                ExMGslT2_B.autosar_irv_read6, ExMGslT2_B.autosar_irv_read7,
                ExMGslT2_B.autosar_irv_read8, ExMGslT2_B.autosar_irv_read9,
                ExMGslT2_B.autosar_irv_read10, ExMGslT2_B.autosar_irv_read11,
                ExMGslT2_B.autosar_irv_read12, (&(ExM_prm_tWallInter[0])),
                ExMGslT2_B.autosar_irv_read1_df, ExMGslT2_B.autosar_irv_read2_f,
                ExMGslT2_B.autosar_irv_read3_n, ExMGslT2_B.autosar_irv_read4_k,
                ExMGslT2_B.autosar_irv_read5_a, ExMGslT2_B.autosar_irv_read6_pl,
                ExMGslT2_B.autosar_irv_read7_j, ExMGslT2_B.autosar_irv_read8_dh,
                ExMGslT2_B.autosar_irv_read1_m, ExMGslT2_B.autosar_irv_read2_d,
                ExMGslT2_B.autosar_irv_read3_dr, ExMGslT2_B.autosar_irv_read4_gj,
                ExMGslT2_B.autosar_irv_read5_cj, ExMGslT2_B.autosar_irv_read6_ii,
                ExMGslT2_B.autosar_irv_read7_j2, ExMGslT2_B.autosar_irv_read8_h,
                ExMGslT2_B.autosar_irv_read1_n, ExMGslT2_B.autosar_irv_read2_g,
                ExMGslT2_B.autosar_irv_read3_d, ExMGslT2_B.autosar_irv_read4_c,
                ExMGslT2_B.autosar_irv_read5_k, ExMGslT2_B.autosar_irv_read6_l,
                ExMGslT2_B.autosar_irv_read7_k, ExMGslT2_B.autosar_irv_read8_a,
                ExMGslT2_B.autosar_irv_read9_m, ExMGslT2_B.autosar_irv_read10_e,
                ExMGslT2_B.autosar_irv_read11_n, ExMGslT2_B.autosar_irv_read12_i,
                ExMGslT2_B.TmpSignalConversionAtExt_tCoMes,
                ExMGslT2_B.TmpSignalConversionAtExt_tAirOu, &ExM_tEgOut,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
                ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh,
                ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa,
                ExMGslT2_B.TmpSignalConversionAtExt_nEngOu, ExM_mfTrbEstimSatRef,
                ExM_mfWgEstimRef, ExMGslT2_B.TmpSignalConversionAtFARSp_rMix,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j,
                ExMGslT2_B.TmpSignalConversionAtInjSys_noC,
                ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl,
                ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW,
                ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn,
                ExMGslT2_B.TmpSignalConversionAtThMgt_bPos,
                ExMGslT2_B.TmpSignalConversionAtExt_bAdFan,
                ExMGslT2_B.TmpSignalConversionAtExt_stTypI,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfAir, ExM_rMixtInp,
                ExMGslT2_B.TmpSignalConversionAtExM_tEgMes, (&(ExM_prm_tEgInter
    [0])), (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC, &ExM_tEgOut, &ExM_noIdxT,
                (&(ExM_prm_tEgInter[0])), (&(ExM_prm_tWallInter[0])),
                &ExMGslT2_B.LibT, &ExMGslT2_DWork.LibT);

  /* '<S411>:1:14' */
  ExMGslT2_LibT(&ExM_noIdxT, (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC,
                ExMGslT2_B.Not, ExMGslT2_B.autosar_irv_read1,
                ExMGslT2_B.autosar_irv_read2, ExMGslT2_B.autosar_irv_read3,
                ExMGslT2_B.autosar_irv_read4, ExMGslT2_B.autosar_irv_read5,
                ExMGslT2_B.autosar_irv_read6, ExMGslT2_B.autosar_irv_read7,
                ExMGslT2_B.autosar_irv_read8, ExMGslT2_B.autosar_irv_read9,
                ExMGslT2_B.autosar_irv_read10, ExMGslT2_B.autosar_irv_read11,
                ExMGslT2_B.autosar_irv_read12, (&(ExM_prm_tWallInter[0])),
                ExMGslT2_B.autosar_irv_read1_df, ExMGslT2_B.autosar_irv_read2_f,
                ExMGslT2_B.autosar_irv_read3_n, ExMGslT2_B.autosar_irv_read4_k,
                ExMGslT2_B.autosar_irv_read5_a, ExMGslT2_B.autosar_irv_read6_pl,
                ExMGslT2_B.autosar_irv_read7_j, ExMGslT2_B.autosar_irv_read8_dh,
                ExMGslT2_B.autosar_irv_read1_m, ExMGslT2_B.autosar_irv_read2_d,
                ExMGslT2_B.autosar_irv_read3_dr, ExMGslT2_B.autosar_irv_read4_gj,
                ExMGslT2_B.autosar_irv_read5_cj, ExMGslT2_B.autosar_irv_read6_ii,
                ExMGslT2_B.autosar_irv_read7_j2, ExMGslT2_B.autosar_irv_read8_h,
                ExMGslT2_B.autosar_irv_read1_n, ExMGslT2_B.autosar_irv_read2_g,
                ExMGslT2_B.autosar_irv_read3_d, ExMGslT2_B.autosar_irv_read4_c,
                ExMGslT2_B.autosar_irv_read5_k, ExMGslT2_B.autosar_irv_read6_l,
                ExMGslT2_B.autosar_irv_read7_k, ExMGslT2_B.autosar_irv_read8_a,
                ExMGslT2_B.autosar_irv_read9_m, ExMGslT2_B.autosar_irv_read10_e,
                ExMGslT2_B.autosar_irv_read11_n, ExMGslT2_B.autosar_irv_read12_i,
                ExMGslT2_B.TmpSignalConversionAtExt_tCoMes,
                ExMGslT2_B.TmpSignalConversionAtExt_tAirOu, &ExM_tEgOut,
                ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
                ExMGslT2_B.TmpSignalConversionAtVeh_spdVeh,
                ExMGslT2_B.TmpSignalConversionAtExt_rSpdFa,
                ExMGslT2_B.TmpSignalConversionAtExt_nEngOu, ExM_mfTrbEstimSatRef,
                ExM_mfWgEstimRef, ExMGslT2_B.TmpSignalConversionAtFARSp_rMix,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfA_j,
                ExMGslT2_B.TmpSignalConversionAtInjSys_noC,
                ExMGslT2_B.TmpSignalConversionAtAfuA_bInvl,
                ExMGslT2_B.TmpSignalConversionAtAfuA_rEthW,
                ExMGslT2_B.TmpSignalConversionAtIgSys_rDyn,
                ExMGslT2_B.TmpSignalConversionAtThMgt_bPos,
                ExMGslT2_B.TmpSignalConversionAtExt_bAdFan,
                ExMGslT2_B.TmpSignalConversionAtExt_stTypI,
                ExMGslT2_B.TmpSignalConversionAtEngM_mfAir, ExM_rMixtInp,
                ExMGslT2_B.TmpSignalConversionAtExM_tEgMes, (&(ExM_prm_tEgInter
    [0])), (&(ExM_prm_tEgOxC[0])), &ExM_noIdxOxC, &ExM_tEgOut, &ExM_noIdxT,
                (&(ExM_prm_tEgInter[0])), (&(ExM_prm_tWallInter[0])),
                &ExMGslT2_B.LibT, &ExMGslT2_DWork.LibT);

  /* '<S411>:1:16' */

  /* DataTypeConversion: '<S413>/Data Type Conversion' */
  for (locali = 0; locali < 12; locali++) {
    ExM_prm_tEgFltPrev[(locali)] = (((Float32)
      ExMGslT2_B.TmpSignalConversionAtExM_prm__g[(locali)]) * 0.03125F) + 223.0F;
  }

  /* DataTypeConversion: '<S413>/Data Type Conversion1' */
  for (locali = 0; locali < 6; locali++) {
    ExM_prm_tExMnfEstimCylPrev[(locali)] = (((Float32)
      ExMGslT2_B.TmpSignalConversionAtExM_prm_tE[(locali)]) * 0.03125F) + 223.0F;
  }

  /* Outputs for atomic SubSystem: '<S413>/F01_Gas_temperature_output' incorporates:
   *  Constant: '<S467>/offset'
   *  Constant: '<S467>/one_on_slope'
   *  Product: '<S467>/Product4'
   *  Sum: '<S467>/Add1'
   */

  /* DataTypeConversion: '<S457>/Data Type Conversion3' */
  localAdd_n = ExMGslT2_B.TmpSignalConversionAtEng_noExNx;

  /* DataTypeConversion: '<S457>/Data Type Conversion5' */
  localAdd_e = ExMGslT2_B.TmpSignalConversionAtEng_noExCy;

  /* Sum: '<S457>/Sum5' incorporates:
   *  Constant: '<S457>/Cste_59'
   *  Constant: '<S457>/ExM_noSelTEgUsMainOxC_C'
   */
  locali = ExM_noSelTEgUsMainOxC_C;
  localqY = ((UInt32)locali) - 1U;
  if (localqY > ((UInt32)locali)) {
    localqY = 0U;
  }

  locali = (SInt32)localqY;

  /* MinMax: '<S459>/MinMax' incorporates:
   *  Constant: '<S459>/Constant'
   */
  localmin = (SInt32)rt_MIN((UInt32)locali, 11U);

  /* PreLookup: '<S466>/Prelookup' */
  locali = plook_s32u16f_bincpa(ExMGslT2_B.TmpSignalConversionAtExM_mfEgWo,
    (&(ExM_mfEgFlt_A[0])), 15U, &localPrelookup_o2_k,
    &ExMGslT2_DWork.Prelookup_DWORK1);

  /* Interpolation_n-D: '<S463>/Interpolation Using Prelookup3' */
  localDataTypeConversion_n = localPrelookup_o2_k;
  ExM_facFltT_MP = intrp1d_iu16n16ff_s32f_la_n(locali, localDataTypeConversion_n,
    (&(ExM_facFltT_T[0])), 15U);

  /* Sum: '<S457>/Sum7' incorporates:
   *  Constant: '<S457>/Cste_1'
   */
  localDataTypeConversion_n = 1.0F - ExM_facFltT_MP;
  for (locali = 0; locali < 12; locali++) {
    /* Sum: '<S457>/Sum6' incorporates:
     *  Product: '<S468>/Divide'
     *  Product: '<S469>/Divide'
     */
    locallocalAssignment_l = (ExM_prm_tEgFltPrev[(locali)] *
      localDataTypeConversion_n) + (ExM_facFltT_MP * ExM_prm_tEgInter[(locali)]);

    /* Switch: '<S457>/Switch' incorporates:
     *  Constant: '<S457>/ExM_bTEgFlt_C'
     */
    if (ExM_bTEgFlt_C) {
      localAssignment_m1[locali] = ExM_prm_tEgInter[(locali)];
    } else {
      localAssignment_m1[locali] = locallocalAssignment_l;
    }

    localAssignment_l[locali] = locallocalAssignment_l;
  }

  /* Sum: '<S457>/Sum3' incorporates:
   *  Constant: '<S457>/Cste_57'
   *  Constant: '<S457>/ExM_noSelTEgPreOxC_C'
   */
  locali = ExM_noSelTEgPreOxC_C;
  localqY = ((UInt32)locali) - 1U;
  if (localqY > ((UInt32)locali)) {
    localqY = 0U;
  }

  locali = (SInt32)localqY;

  /* MinMax: '<S460>/MinMax' incorporates:
   *  Constant: '<S460>/Constant'
   */
  localmin_0 = (SInt32)rt_MIN((UInt32)locali, 11U);

  /* Sum: '<S457>/Sum4' incorporates:
   *  Constant: '<S457>/Cste_58'
   *  Constant: '<S457>/ExM_noSelTEgOxC_C'
   */
  locali = ExM_noSelTEgOxC_C;
  localqY = ((UInt32)locali) - 1U;
  if (localqY > ((UInt32)locali)) {
    localqY = 0U;
  }

  locali = (SInt32)localqY;

  /* MinMax: '<S461>/MinMax' incorporates:
   *  Constant: '<S461>/Constant'
   */
  localmin_1 = (SInt32)rt_MIN((UInt32)locali, 11U);

  /* Sum: '<S457>/Sum1' incorporates:
   *  Constant: '<S457>/Cste_56'
   *  Constant: '<S457>/ExM_noSelTExMnf_C'
   */
  locali = ExM_noSelTExMnf_C;
  localqY = ((UInt32)locali) - 1U;
  if (localqY > ((UInt32)locali)) {
    localqY = 0U;
  }

  locali = (SInt32)localqY;

  /* Selector: '<S462>/Selector' incorporates:
   *  Constant: '<S462>/Constant'
   *  MinMax: '<S462>/MinMax'
   */
  localDataTypeConversion_n = localAssignment_m1[(SInt32)rt_MIN((UInt32)
    locali, 11U)];

  /* Sum: '<S464>/Add' incorporates:
   *  Constant: '<S464>/Constant1'
   */
  localAdd_e--;

  /* Assignment: '<S464>/Assignment' incorporates:
   *  Constant: '<S464>/Constant'
   *  MinMax: '<S464>/MinMax'
   */
  for (locali = 0; locali < 6; locali++) {
    localAssignment_b[locali] = ExM_prm_tExMnfEstimCylPrev[(locali)];
  }

  localAssignment_b[(SInt32)rt_MIN(localAdd_e, 5U)] = localDataTypeConversion_n;

  /* Sum: '<S465>/Add' incorporates:
   *  Constant: '<S465>/Constant1'
   */
  localAdd_n--;

  /* Assignment: '<S465>/Assignment' incorporates:
   *  Constant: '<S465>/Constant'
   *  MinMax: '<S465>/MinMax'
   */
  localAssignment_b[(SInt32)rt_MIN(localAdd_n, 5U)] = localDataTypeConversion_n;
  for (locali = 0; locali < 12; locali++) {
    /* SignalConversion: '<S457>/Signal Conversion1' */
    ExMGslT2_B.SignalConversion1[(locali)] = ExM_prm_tEgInter[(locali)];
    localAssignment_l[locali] = (localAssignment_l[locali] - 223.0F) * 32.0F;
  }

  /* Sum: '<S457>/Sum' incorporates:
   *  Constant: '<S457>/Cste_60'
   *  Selector: '<S461>/Selector'
   */
  localProduct_g = localAssignment_m1[localmin_1] - 2.731499939E+002F;

  /* Sum: '<S457>/Sum2' incorporates:
   *  Constant: '<S457>/Cste_61'
   *  Selector: '<S460>/Selector'
   */
  localSum_0 = localAssignment_m1[localmin_0] - 2.731499939E+002F;

  /* SignalConversion: '<S457>/Signal Conversion4' */
  ExMGslT2_B.SignalConversion4[0] = ExM_prm_tEgOxC[0];
  ExMGslT2_B.SignalConversion4[1] = ExM_prm_tEgOxC[1];
  ExMGslT2_B.SignalConversion4[2] = ExM_prm_tEgOxC[2];

  /* end of Outputs for SubSystem: '<S413>/F01_Gas_temperature_output' */
  for (locali = 0; locali < 12; locali++) {
    /* Outputs for atomic SubSystem: '<S413>/F02_Wall_temperature_output' */

    /* SignalConversion: '<S458>/Signal Conversion' */
    ExMGslT2_B.SignalConversion[(locali)] = ExM_prm_tWallInter[(locali)];

    /* end of Outputs for SubSystem: '<S413>/F02_Wall_temperature_output' */

    /* DataTypeConversion: '<S426>/OutDTConv' incorporates:
     *  Constant: '<S426>/offset'
     *  Constant: '<S426>/one_on_slope'
     *  Product: '<S426>/Product4'
     *  Sum: '<S426>/Add1'
     */
    locallocalAssignment_l = (localAssignment_m1[locali] - 223.0F) * 32.0F;
    if (locallocalAssignment_l < 65536.0F) {
      if (locallocalAssignment_l >= 0.0F) {
        localSwitch_nd = (UInt16)locallocalAssignment_l;
      } else {
        localSwitch_nd = 0U;
      }
    } else {
      localSwitch_nd = MAX_uint16_T;
    }

    ExMGslT2_B.OutDTConv_m[(locali)] = localSwitch_nd;
  }

  /* S-Function (NvRamWriteAccess): '<S7>/EepromWriteAccess' */
  {
    UInt32 locali;
    for (locali=0 ; locali <12; locali++) {
      ExMGslT2_sNV_Z1_CONST_16BIT.ExM_prm_tEg_NV[locali] =
        ExMGslT2_B.OutDTConv_m[locali];
    }
  }

  /* DataTypeConversion: '<S425>/OutDTConv' incorporates:
   *  Constant: '<S425>/offset'
   *  Constant: '<S425>/one_on_slope'
   *  Product: '<S425>/Product4'
   *  Sum: '<S425>/Add1'
   */
  for (locali = 0; locali < 12; locali++) {
    locallocalAssignment_l = (ExMGslT2_B.SignalConversion[(locali)] - 223.0F) *
      32.0F;
    if (locallocalAssignment_l < 65536.0F) {
      if (locallocalAssignment_l >= 0.0F) {
        localSwitch_nd = (UInt16)locallocalAssignment_l;
      } else {
        localSwitch_nd = 0U;
      }
    } else {
      localSwitch_nd = MAX_uint16_T;
    }

    ExMGslT2_B.OutDTConv_g[(locali)] = localSwitch_nd;
  }

  /* S-Function (NvRamWriteAccess): '<S7>/EepromWriteAccess1' */
  {
    UInt32 locali;
    for (locali=0 ; locali <12; locali++) {
      ExMGslT2_sNV_Z1_CONST_16BIT.ExM_prm_tWall_NV[locali] =
        ExMGslT2_B.OutDTConv_g[locali];
    }
  }

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write1' */

  /* S-Function Block: <S410>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_01_irv
    (ExMGslT2_B.SignalConversion[0]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write10' */

  /* S-Function Block: <S410>/autosar_irv_write10 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_10_irv
    (ExMGslT2_B.SignalConversion[9]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write11' */

  /* S-Function Block: <S410>/autosar_irv_write11 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_11_irv
    (ExMGslT2_B.SignalConversion[10]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write12' */

  /* S-Function Block: <S410>/autosar_irv_write12 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_12_irv
    (ExMGslT2_B.SignalConversion[11]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write2' */

  /* S-Function Block: <S410>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_02_irv
    (ExMGslT2_B.SignalConversion[1]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write3' */

  /* S-Function Block: <S410>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_03_irv
    (ExMGslT2_B.SignalConversion[2]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write4' */

  /* S-Function Block: <S410>/autosar_irv_write4 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_04_irv
    (ExMGslT2_B.SignalConversion[3]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write5' */

  /* S-Function Block: <S410>/autosar_irv_write5 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_05_irv
    (ExMGslT2_B.SignalConversion[4]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write6' */

  /* S-Function Block: <S410>/autosar_irv_write6 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_06_irv
    (ExMGslT2_B.SignalConversion[5]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write7' */

  /* S-Function Block: <S410>/autosar_irv_write7 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_07_irv
    (ExMGslT2_B.SignalConversion[6]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write8' */

  /* S-Function Block: <S410>/autosar_irv_write8 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_08_irv
    (ExMGslT2_B.SignalConversion[7]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S410>/autosar_irv_write9' */

  /* S-Function Block: <S410>/autosar_irv_write9 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tWall_09_irv
    (ExMGslT2_B.SignalConversion[8]);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S438>/autosar_testpoint1' */

  /* S-Function Block: <S438>/autosar_testpoint1 */
  ExM_prm_tWall_01_IRV_MP = ExMGslT2_B.SignalConversion[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S439>/autosar_testpoint1' */

  /* S-Function Block: <S439>/autosar_testpoint1 */
  ExM_prm_tWall_10_IRV_MP = ExMGslT2_B.SignalConversion[9];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S440>/autosar_testpoint1' */

  /* S-Function Block: <S440>/autosar_testpoint1 */
  ExM_prm_tWall_11_IRV_MP = ExMGslT2_B.SignalConversion[10];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S441>/autosar_testpoint1' */

  /* S-Function Block: <S441>/autosar_testpoint1 */
  ExM_prm_tWall_12_IRV_MP = ExMGslT2_B.SignalConversion[11];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S442>/autosar_testpoint1' */

  /* S-Function Block: <S442>/autosar_testpoint1 */
  ExM_prm_tWall_02_IRV_MP = ExMGslT2_B.SignalConversion[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S443>/autosar_testpoint1' */

  /* S-Function Block: <S443>/autosar_testpoint1 */
  ExM_prm_tWall_03_IRV_MP = ExMGslT2_B.SignalConversion[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S444>/autosar_testpoint1' */

  /* S-Function Block: <S444>/autosar_testpoint1 */
  ExM_prm_tWall_04_IRV_MP = ExMGslT2_B.SignalConversion[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S445>/autosar_testpoint1' */

  /* S-Function Block: <S445>/autosar_testpoint1 */
  ExM_prm_tWall_05_IRV_MP = ExMGslT2_B.SignalConversion[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S446>/autosar_testpoint1' */

  /* S-Function Block: <S446>/autosar_testpoint1 */
  ExM_prm_tWall_06_IRV_MP = ExMGslT2_B.SignalConversion[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S447>/autosar_testpoint1' */

  /* S-Function Block: <S447>/autosar_testpoint1 */
  ExM_prm_tWall_07_IRV_MP = ExMGslT2_B.SignalConversion[6];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S448>/autosar_testpoint1' */

  /* S-Function Block: <S448>/autosar_testpoint1 */
  ExM_prm_tWall_08_IRV_MP = ExMGslT2_B.SignalConversion[7];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S449>/autosar_testpoint1' */

  /* S-Function Block: <S449>/autosar_testpoint1 */
  ExM_prm_tWall_09_IRV_MP = ExMGslT2_B.SignalConversion[8];

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write1' */

  /* S-Function Block: <S414>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_01_irv
    (ExMGslT2_B.SignalConversion1[0]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write10' */

  /* S-Function Block: <S414>/autosar_irv_write10 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_10_irv
    (ExMGslT2_B.SignalConversion1[9]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write11' */

  /* S-Function Block: <S414>/autosar_irv_write11 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_11_irv
    (ExMGslT2_B.SignalConversion1[10]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write12' */

  /* S-Function Block: <S414>/autosar_irv_write12 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_12_irv
    (ExMGslT2_B.SignalConversion1[11]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write2' */

  /* S-Function Block: <S414>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_02_irv
    (ExMGslT2_B.SignalConversion1[1]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write3' */

  /* S-Function Block: <S414>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_03_irv
    (ExMGslT2_B.SignalConversion1[2]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write4' */

  /* S-Function Block: <S414>/autosar_irv_write4 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_04_irv
    (ExMGslT2_B.SignalConversion1[3]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write5' */

  /* S-Function Block: <S414>/autosar_irv_write5 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_05_irv
    (ExMGslT2_B.SignalConversion1[4]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write6' */

  /* S-Function Block: <S414>/autosar_irv_write6 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_06_irv
    (ExMGslT2_B.SignalConversion1[5]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write7' */

  /* S-Function Block: <S414>/autosar_irv_write7 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_07_irv
    (ExMGslT2_B.SignalConversion1[6]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write8' */

  /* S-Function Block: <S414>/autosar_irv_write8 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_08_irv
    (ExMGslT2_B.SignalConversion1[7]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S414>/autosar_irv_write9' */

  /* S-Function Block: <S414>/autosar_irv_write9 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgRaw_09_irv
    (ExMGslT2_B.SignalConversion1[8]);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S470>/autosar_testpoint1' */

  /* S-Function Block: <S470>/autosar_testpoint1 */
  ExM_prm_tEgRaw_01_IRV_MP = ExMGslT2_B.SignalConversion1[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S471>/autosar_testpoint1' */

  /* S-Function Block: <S471>/autosar_testpoint1 */
  ExM_prm_tEgRaw_10_IRV_MP = ExMGslT2_B.SignalConversion1[9];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S472>/autosar_testpoint1' */

  /* S-Function Block: <S472>/autosar_testpoint1 */
  ExM_prm_tEgRaw_11_IRV_MP = ExMGslT2_B.SignalConversion1[10];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S473>/autosar_testpoint1' */

  /* S-Function Block: <S473>/autosar_testpoint1 */
  ExM_prm_tEgRaw_12_IRV_MP = ExMGslT2_B.SignalConversion1[11];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S474>/autosar_testpoint1' */

  /* S-Function Block: <S474>/autosar_testpoint1 */
  ExM_prm_tEgRaw_02_IRV_MP = ExMGslT2_B.SignalConversion1[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S475>/autosar_testpoint1' */

  /* S-Function Block: <S475>/autosar_testpoint1 */
  ExM_prm_tEgRaw_03_IRV_MP = ExMGslT2_B.SignalConversion1[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S476>/autosar_testpoint1' */

  /* S-Function Block: <S476>/autosar_testpoint1 */
  ExM_prm_tEgRaw_04_IRV_MP = ExMGslT2_B.SignalConversion1[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S477>/autosar_testpoint1' */

  /* S-Function Block: <S477>/autosar_testpoint1 */
  ExM_prm_tEgRaw_05_IRV_MP = ExMGslT2_B.SignalConversion1[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S478>/autosar_testpoint1' */

  /* S-Function Block: <S478>/autosar_testpoint1 */
  ExM_prm_tEgRaw_06_IRV_MP = ExMGslT2_B.SignalConversion1[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S479>/autosar_testpoint1' */

  /* S-Function Block: <S479>/autosar_testpoint1 */
  ExM_prm_tEgRaw_07_IRV_MP = ExMGslT2_B.SignalConversion1[6];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S480>/autosar_testpoint1' */

  /* S-Function Block: <S480>/autosar_testpoint1 */
  ExM_prm_tEgRaw_08_IRV_MP = ExMGslT2_B.SignalConversion1[7];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S481>/autosar_testpoint1' */

  /* S-Function Block: <S481>/autosar_testpoint1 */
  ExM_prm_tEgRaw_09_IRV_MP = ExMGslT2_B.SignalConversion1[8];

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S420>/autosar_irv_write1' */

  /* S-Function Block: <S420>/autosar_irv_write1 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgOxC_01_irv
    (ExMGslT2_B.SignalConversion4[0]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S420>/autosar_irv_write2' */

  /* S-Function Block: <S420>/autosar_irv_write2 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgOxC_02_irv
    (ExMGslT2_B.SignalConversion4[1]);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S420>/autosar_irv_write3' */

  /* S-Function Block: <S420>/autosar_irv_write3 */
  Rte_IrvWrite_RE_ExMGslT2_007_TEV_ExM_prm_tEgOxC_03_irv
    (ExMGslT2_B.SignalConversion4[2]);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S482>/autosar_testpoint1' */

  /* S-Function Block: <S482>/autosar_testpoint1 */
  ExM_prm_tEgOxC_01_IRV_MP = ExMGslT2_B.SignalConversion4[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S483>/autosar_testpoint1' */

  /* S-Function Block: <S483>/autosar_testpoint1 */
  ExM_prm_tEgOxC_02_IRV_MP = ExMGslT2_B.SignalConversion4[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S484>/autosar_testpoint1' */

  /* S-Function Block: <S484>/autosar_testpoint1 */
  ExM_prm_tEgOxC_03_IRV_MP = ExMGslT2_B.SignalConversion4[2];

  /* DataTypeConversion: '<S423>/OutDTConv' incorporates:
   *  Constant: '<S423>/offset'
   *  Constant: '<S423>/one_on_slope'
   *  Product: '<S423>/Product4'
   *  Sum: '<S423>/Add1'
   */
  if (localProduct_g < 32768.0F) {
    if (localProduct_g >= -32768.0F) {
      localOutDTConv_j = (SInt16)localProduct_g;
    } else {
      localOutDTConv_j = MIN_int16_T;
    }
  } else {
    localOutDTConv_j = MAX_int16_T;
  }

  /* DataTypeConversion: '<S424>/OutDTConv' incorporates:
   *  Constant: '<S424>/offset'
   *  Constant: '<S424>/one_on_slope'
   *  Product: '<S424>/Product4'
   *  Sum: '<S424>/Add1'
   */
  if (localSum_0 < 32768.0F) {
    if (localSum_0 >= -32768.0F) {
      localOutDTConv_o = (SInt16)localSum_0;
    } else {
      localOutDTConv_o = MIN_int16_T;
    }
  } else {
    localOutDTConv_o = MAX_int16_T;
  }

  /* DataTypeConversion: '<S427>/OutDTConv' incorporates:
   *  Constant: '<S427>/offset'
   *  Constant: '<S427>/one_on_slope'
   *  Product: '<S427>/Product4'
   *  Selector: '<S459>/Selector'
   *  Sum: '<S427>/Add1'
   */
  locallocalAssignment_l = (localAssignment_m1[localmin] - 223.0F) * 32.0F;
  if (locallocalAssignment_l < 65536.0F) {
    if (locallocalAssignment_l >= 0.0F) {
      localOutDTConv_l4 = (UInt16)locallocalAssignment_l;
    } else {
      localOutDTConv_l4 = 0U;
    }
  } else {
    localOutDTConv_l4 = MAX_uint16_T;
  }

  /* Product: '<S428>/Product4' incorporates:
   *  Constant: '<S428>/offset'
   *  Constant: '<S428>/one_on_slope'
   *  Sum: '<S428>/Add1'
   */
  localDataTypeConversion_n = (localDataTypeConversion_n - 223.0F) * 32.0F;

  /* Product: '<S429>/Product4' incorporates:
   *  Constant: '<S429>/offset'
   *  Constant: '<S429>/one_on_slope'
   *  Sum: '<S429>/Add1'
   */
  for (locali = 0; locali < 6; locali++) {
    localAssignment_b[locali] = (localAssignment_b[locali] - 223.0F) * 32.0F;
  }

  /* Switch: '<S436>/Switch' incorporates:
   *  Constant: '<S436>/Byp_Fonction_SC'
   *  Constant: '<S436>/Int_BypC'
   *  DataTypeConversion: '<S467>/OutDTConv'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_dm[locali] = ExM_prm_tEgFlt_B[(locali)];
    } else {
      if (localAssignment_l[locali] < 65536.0F) {
        if (localAssignment_l[locali] >= 0.0F) {
          localSwitch_nd = (UInt16)localAssignment_l[locali];
        } else {
          localSwitch_nd = 0U;
        }
      } else {
        localSwitch_nd = MAX_uint16_T;
      }

      localSwitch_dm[locali] = localSwitch_nd;
    }
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_prm_tEgFltInport2' */
  Rte_Write_P_ExM_prm_tEgFlt_ExM_prm_tEgFlt(&localSwitch_dm);

  /* Switch: '<S431>/Switch' incorporates:
   *  Constant: '<S431>/Byp_Fonction_SC'
   *  Constant: '<S431>/Int_BypC'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_dm[locali] = ExM_prm_tEg_B[(locali)];
    } else {
      localSwitch_dm[locali] = ExMGslT2_B.OutDTConv_m[(locali)];
    }
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_prm_tEgInport2' */
  Rte_Write_P_ExM_prm_tEg_ExM_prm_tEg(&localSwitch_dm);

  /* Switch: '<S434>/Switch' incorporates:
   *  Constant: '<S434>/Byp_Fonction_SC'
   *  Constant: '<S434>/Int_BypC'
   *  DataTypeConversion: '<S429>/OutDTConv'
   */
  for (locali = 0; locali < 6; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_gy[locali] = ExM_prm_tExMnfEstimCyl_B[(locali)];
    } else {
      if (localAssignment_b[locali] < 65536.0F) {
        if (localAssignment_b[locali] >= 0.0F) {
          localSwitch_nd = (UInt16)localAssignment_b[locali];
        } else {
          localSwitch_nd = 0U;
        }
      } else {
        localSwitch_nd = MAX_uint16_T;
      }

      localSwitch_gy[locali] = localSwitch_nd;
    }
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_prm_tExMnfEstimCylInport2' */
  Rte_Write_P_ExM_prm_tExMnfEstimCyl_ExM_prm_tExMnfEstimCyl(&localSwitch_gy);

  /* Switch: '<S430>/Switch' incorporates:
   *  Constant: '<S430>/Byp_Fonction_SC'
   *  Constant: '<S430>/Int_BypC'
   */
  for (locali = 0; locali < 12; locali++) {
    if (EXMGSLT2_ACTIVE_BYP_C) {
      localSwitch_dm[locali] = ExM_prm_tWall_B[(locali)];
    } else {
      localSwitch_dm[locali] = ExMGslT2_B.OutDTConv_g[(locali)];
    }
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_prm_tWallInport2' */
  Rte_Write_P_ExM_prm_tWall_ExM_prm_tWall(&localSwitch_dm);

  /* Switch: '<S435>/Switch' incorporates:
   *  Constant: '<S435>/Byp_Fonction_SC'
   *  Constant: '<S435>/Int_BypC'
   *  DataTypeConversion: '<S428>/OutDTConv'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localSwitch_nd = ExM_tExMnfEstim_B;
  } else if (localDataTypeConversion_n < 65536.0F) {
    if (localDataTypeConversion_n >= 0.0F) {
      localSwitch_nd = (UInt16)localDataTypeConversion_n;
    } else {
      localSwitch_nd = 0U;
    }
  } else {
    localSwitch_nd = MAX_uint16_T;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tExMnfEstimInport2' */
  Rte_Write_P_ExM_tExMnfEstim_ExM_tExMnfEstim(localSwitch_nd);

  /* Switch: '<S433>/Switch' incorporates:
   *  Constant: '<S433>/Byp_Fonction_SC'
   *  Constant: '<S433>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv_j = ExM_tOxCEstim_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tOxCEstimInport2' */
  Rte_Write_P_ExM_tOxCEstim_ExM_tOxCEstim(localOutDTConv_j);

  /* Switch: '<S437>/Switch' incorporates:
   *  Constant: '<S437>/Byp_Fonction_SC'
   *  Constant: '<S437>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv_o = ExM_tPreOxCEstim_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tPreOxCEstimInport2' */
  Rte_Write_P_ExM_tPreOxCEstim_ExM_tPreOxCEstim(localOutDTConv_o);

  /* Switch: '<S432>/Switch' incorporates:
   *  Constant: '<S432>/Byp_Fonction_SC'
   *  Constant: '<S432>/Int_BypC'
   */
  if (EXMGSLT2_ACTIVE_BYP_C) {
    localOutDTConv_l4 = ExM_tUsMainOxCEstim_B;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExM_tUsMainOxCEstimInport2' */
  Rte_Write_P_ExM_tUsMainOxCEstim_ExM_tUsMainOxCEstim(localOutDTConv_l4);
}

/* Model initialize function */
void RE_ExMGslT2_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  RE_ExMGslT2_001_MSE_Start();
  RE_ExMGslT2_006_TEV_Start();
  RE_ExMGslT2_007_TEV_Start();
}

#define ExMGslT2_STOP_SEC_CODE
#include "ExMGslT2_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
