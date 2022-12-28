/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvOptmT                                                */
/* !Description     : AdvOptmT Software Component                             */
/*                                                                            */
/* !Module          : AdvOptmT                                                */
/* !Description     : AdvOptmT Software Component                             */
/*                                                                            */
/* !File            : AdvOptmT.c                                              */
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
/*   Model name       : AdvOptmT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /AdvOptmT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M03-AdvOptmT/5-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Nov 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvOptmT.h"
#include "AdvOptmT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AdvOptmT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvOptmT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AdvOptmT AdvOptmT_B;

/* Block states (auto storage) */
D_Work_AdvOptmT AdvOptmT_DWork;

#define AdvOptmT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvOptmT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define ADVOPTMT_VEMSRTLIBT_MAJOR_VERSION_REQ 3
#define ADVOPTMT_VEMSRTLIBT_MINOR_VERSION_REQ 7
#define ADVOPTMT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define ADVOPTMT_VEMSRTLIBT_VERSION_REQ (ADVOPTMT_VEMSRTLIBT_PATCH_VERSION_REQ + ADVOPTMT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + ADVOPTMT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if ADVOPTMT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AdvOptmT_START_SEC_CODE
#include "AdvOptmT_MemMap.h"

void AdvOptmT_ASYNC1(int controlPortIdx)
{
}

void AdvOptmT_ASYNC2(int controlPortIdx)
{
}

/* Start for exported function: RE_AdvOptmT_001_MSE */
void RE_AdvOptmT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_WrmUp_init'
   */
}

/* Output and update for exported function: RE_AdvOptmT_001_MSE */
void RE_AdvOptmT_001_MSE(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_WrmUp_init'
   */

  /* user code (Output function Body for TID6) */
  EV_AdvOptm_AUTOSAR_Init();

  /* SignalConversion: '<S13>/copy' incorporates:
   *  Constant: '<S7>/Constant'
   */
  IgSys_agIgWup_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S13>/autosar_testpoint1' */

  /* S-Function Block: <S13>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIgSys_agIgWup_irvInport2' incorporates:
   *  Constant: '<S7>/Constant'
   *  SignalConversion: '<S7>/Signal Conversion'
   */
  Rte_IrvWrite_RE_AdvOptmT_001_MSE_IgSys_agIgWup_irv(0.0F);
}

/* Start for exported function: RE_AdvOptmT_004_MSE */
void RE_AdvOptmT_004_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_AdvOptm_Init'
   */
}

/* Output and update for exported function: RE_AdvOptmT_004_MSE */
void RE_AdvOptmT_004_MSE(void)
{
  UInt8 localIgSys_agIgBas;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_AdvOptm_Init'
   */

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Byp_Fonction_SC'
   *  Constant: '<S11>/Int_BypC'
   *  Constant: '<S6>/Constant1'
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   */
  if (ADVOPTMT_ACTIVE_BYP_C) {
    localIgSys_agIgBas = IgSys_agIgBas_B;
  } else {
    localIgSys_agIgBas = 96U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtIgSys_agIgBasInport2' */
  Rte_Write_P_IgSys_agIgBas_IgSys_agIgBas(localIgSys_agIgBas);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Byp_Fonction_SC'
   *  Constant: '<S12>/Int_BypC'
   *  Constant: '<S6>/Constant'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   */
  if (ADVOPTMT_ACTIVE_BYP_C) {
    localIgSys_agIgBas = IgSys_agIgOptm_B;
  } else {
    localIgSys_agIgBas = 96U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtIgSys_agIgOptmInport2' */
  Rte_Write_P_IgSys_agIgOptm_IgSys_agIgOptm(localIgSys_agIgBas);

  /* SignalConversion: '<S10>/copy' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  IgSys_bAcvClsLoop_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S10>/autosar_testpoint1' */

  /* S-Function Block: <S10>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtIgSys_bAcvClsLoop_irvInport2' incorporates:
   *  Constant: '<S6>/Constant2'
   *  SignalConversion: '<S6>/Signal Conversion'
   */
  Rte_IrvWrite_RE_AdvOptmT_004_MSE_IgSys_bAcvClsLoop_irv(FALSE);
}

/* Start for exported function: RE_AdvOptmT_002_DRE */
void RE_AdvOptmT_002_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F0_Avance_Warm_Up'
   */
}

/* Output and update for exported function: RE_AdvOptmT_002_DRE */
void RE_AdvOptmT_002_DRE(void)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion1;
  Float32 localDataTypeConversion2;
  Float32 localSwitch;
  Float32 localLookUpTable2D;
  Float32 localLookUpTable2D_n;
  Float32 localSwitch1;
  Float32 localLookUpTable2D_i;
  Boolean localAutosarServer;
  SInt8 localTmpSignalConversionAtTqCmp;
  UInt16 localTmpSignalConversionAtExt_n;
  SInt16 localTmpSignalConversionAtExt_t;
  Boolean localNot;
  Boolean localNot_n;
  Float32 localAdd1;
  Boolean localTmpSignalConversionAtIgSys;
  UInt16 localTmpSignalConversionAtEngM_;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F0_Avance_Warm_Up'
   */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTqCmp_tAirOutport2' incorporates:
   *  Inport: '<Root>/TqCmp_tAir'
   */
  Rte_Read_R_TqCmp_tAir_TqCmp_tAir(&localTmpSignalConversionAtTqCmp);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEngM_);

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  localDataTypeConversion1 = ((Float32)localTmpSignalConversionAtEngM_) *
    6.103515625E-005F;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  localDataTypeConversion2 = (Float32)localTmpSignalConversionAtExt_n;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* S-Function (sfun_autosar_clientop): '<S204>/AutosarServer' */
  Rte_Call_R_FRM_bLimAgIgWup_tAir_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S204>/Not' */
  localNot = !localAutosarServer;

  /* S-Function (sfun_autosar_clientop): '<S205>/AutosarServer' */
  Rte_Call_R_FRM_bLimAgIgWup_tCo_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S205>/Not' */
  localNot_n = !localAutosarServer;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_bAcvStructAdvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAcvStructAdv'
   */
  Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv
    (&localTmpSignalConversionAtIgSys);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&AdvOptmT_B.TmpSignalConversionAtEng_stEruO);

  /* Outputs for atomic SubSystem: '<S9>/F01_Condition_d_activation' */

  /* RelationalOperator: '<S201>/Relational Operator' incorporates:
   *  Constant: '<S201>/Ext_stRun_SC'
   */
  IgSys_bAcvWup = (AdvOptmT_B.TmpSignalConversionAtEng_stEruO == Ext_stRun_SC);

  /* end of Outputs for SubSystem: '<S9>/F01_Condition_d_activation' */

  /* Outputs for enable SubSystem: '<S9>/F02_Calcul_avance_warm_up' incorporates:
   *  EnablePort: '<S202>/IgSys_bAcvWup'
   */
  if (IgSys_bAcvWup) {
    /* Switch: '<S202>/Switch2' incorporates:
     *  Constant: '<S202>/constant1'
     *  UnitDelay: '<S210>/Unit Delay'
     */
    if (localTmpSignalConversionAtIgSys) {
      IgSys_tiEngRunWup_MP = AdvOptmT_DWork.UnitDelay_DSTATE_d;
    } else {
      IgSys_tiEngRunWup_MP = 0.0F;
    }

    /* Sum: '<S202>/Add1' incorporates:
     *  Constant: '<S202>/constant'
     */
    localAdd1 = IgSys_tiEngRunWup_MP + 1.0F;

    /* Switch: '<S202>/Switch' incorporates:
     *  Constant: '<S202>/IgSys_tCoWup_C'
     *  DataTypeConversion: '<S9>/Data Type Conversion3'
     */
    if (localNot_n) {
      localSwitch = IgSys_tCoWup_C;
    } else {
      localSwitch = (Float32)localTmpSignalConversionAtExt_t;
    }

    /* Lookup2D: '<S207>/Look-Up Table (2-D)'
     * About '<S207>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D),
      (&(IgSys_facWup_tCo_M[0])), localSwitch, (&(IgSys_tCoWupX_A[0])), 7U,
      IgSys_tiEngRunWup_MP, (&(IgSys_tiEngRunWupY_A[0])), 5U);

    /* DataTypeDuplicate Block: '<S207>/Data Type Duplicate2'
     *
     * Regarding '<S207>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S208>/Look-Up Table (2-D)'
     * About '<S208>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_n),
      (&(IgSys_facWup_tAir_M[0])), localDataTypeConversion2,
      (&(IgSys_nCkFilWupX_A[0])), 7U, localDataTypeConversion1,
      (&(IgSys_rAirLdWupY_A[0])), 5U);

    /* DataTypeDuplicate Block: '<S208>/Data Type Duplicate2'
     *
     * Regarding '<S208>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Switch: '<S202>/Switch1' incorporates:
     *  Constant: '<S202>/IgSys_tAirWup_C'
     *  DataTypeConversion: '<S9>/Data Type Conversion'
     */
    if (localNot) {
      localSwitch1 = IgSys_tAirWup_C;
    } else {
      localSwitch1 = (Float32)localTmpSignalConversionAtTqCmp;
    }

    /* Lookup2D: '<S209>/Look-Up Table (2-D)'
     * About '<S209>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_i),
      (&(IgSys_agIgWupOfs_tAir_M[0])), localDataTypeConversion2,
      (&(IgSys_nCkFilWupOfsX_A[0])), 7U, localSwitch1, (&(IgSys_tAirWupOfsY_A[0])),
      5U);

    /* DataTypeDuplicate Block: '<S209>/Data Type Duplicate2'
     *
     * Regarding '<S209>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S212>/Divide' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion1'
     *  Lookup2D: '<S208>/Look-Up Table (2-D)'
     *  Lookup2D: '<S209>/Look-Up Table (2-D)'
     */
    IgSys_agIgWup_nEng_MP = localLookUpTable2D_n * localLookUpTable2D_i;

    /* Product: '<S211>/Divide' incorporates:
     *  Lookup2D: '<S207>/Look-Up Table (2-D)'
     */
    AdvOptmT_B.Merge = localLookUpTable2D * IgSys_agIgWup_nEng_MP;

    /* Update for UnitDelay: '<S210>/Unit Delay' */
    AdvOptmT_DWork.UnitDelay_DSTATE_d = localAdd1;
  }

  /* end of Outputs for SubSystem: '<S9>/F02_Calcul_avance_warm_up' */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_agIgWupOutport2' */
  AdvOptmT_B.TmpSignalConversionAtIgSys_agIg =
    Rte_IrvRead_RE_AdvOptmT_002_DRE_IgSys_agIgWup_irv();

  /* Outputs for enable SubSystem: '<S9>/NOT' incorporates:
   *  EnablePort: '<S203>/Enable'
   *  Logic: '<S9>/Logical Operator'
   */
  if (!IgSys_bAcvWup) {
    /* SignalConversion: '<S203>/Signal Conversion' */
    AdvOptmT_B.Merge = AdvOptmT_B.TmpSignalConversionAtIgSys_agIg;
  }

  /* end of Outputs for SubSystem: '<S9>/NOT' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S206>/autosar_testpoint1' */

  /* S-Function Block: <S206>/autosar_testpoint1 */
  IgSys_agIgWup_IRV_MP = AdvOptmT_B.Merge;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtIgSys_agIgWup_irvInport2' incorporates:
   *  SignalConversion: '<S9>/Signal Conversion'
   */
  Rte_IrvWrite_RE_AdvOptmT_002_DRE_IgSys_agIgWup_irv(AdvOptmT_B.Merge);
}

/* Start for exported function: RE_AdvOptmT_003_DRE */
void RE_AdvOptmT_003_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_IgAdvOptm'
   */

  /* Start for enable SubSystem: '<S8>/NOT' */

  /* VirtualOutportStart for Outport: '<S16>/IgSys_agIgBas' */
  AdvOptmT_B.Merge2 = 96U;

  /* VirtualOutportStart for Outport: '<S16>/IgSys_agIgOptm' */
  AdvOptmT_B.Merge_i = 96U;

  /* end of Start for SubSystem: '<S8>/NOT' */
}

/* Output and update for exported function: RE_AdvOptmT_003_DRE */
void RE_AdvOptmT_003_DRE(void)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion_i;
  Float32 localDataTypeConversion2_d;
  Float32 localDataTypeConversion6;
  Float32 localDataTypeConversion7;
  Float32 localLookUpTable2D_g;
  Float32 localDivide_nz;
  Float32 localLookUpTable;
  Float32 localLookUpTable_l;
  Float32 localLookUpTable_b;
  Float32 localLookUpTable2D_k;
  Float32 localLookUpTable2D_c;
  Float32 localLookUpTable_k;
  Float32 localDivide_c;
  Float32 localSum_n;
  Float32 localLookUpTable2D_e;
  Float32 localDivide_ex;
  Float32 localLookUpTable_j;
  Float32 localDivide_pg;
  Float32 localLookUpTable_i;
  Float32 localLookUpTable_n;
  Float32 localLookUpTable2D_nf;
  Float32 localLookUpTable2D_m;
  Float32 localLookUpTable_g;
  Float32 localSum1_j;
  Float32 localLookUpTable2D_f;
  Float32 localSum_e;
  Float32 localLookUpTable2D_cg;
  Float32 localDivide_fvh;
  Boolean localTmpSignalConversionAtIgS_n;
  Boolean localUnitDelay_c;
  UInt16 localTmpSignalConversionAtExt_c;
  Float32 localDataTypeConversion10;
  Float32 localDataTypeConversion11;
  Float32 localDataTypeConversion12;
  Float32 localDataTypeConversion16;
  Float32 localDataTypeConversion19;
  SInt16 localTmpSignalConversionAtEx_n5;
  UInt8 localTmpSignalConversionAtEng_s;
  Float32 localDivide_nw;
  Boolean localLowerRelop1;
  Float32 localSwitch1_n;
  UInt16 localTmpSignalConversionAtExM_g;
  UInt16 localTmpSignalConversionAtExM_m;
  UInt16 localTmpSignalConversionAtEn_ha;
  UInt16 localTmpSignalConversionAtEng_n;
  UInt32 localTmpSignalConversionAtInM_m;
  UInt8 localTmpSignalConversionAtIgS_g;
  UInt8 localTmpSignalConversionAtIg_gu;
  UInt8 localTmpSignalConversionAtIgS_f[10];
  UInt8 localTmpSignalConversionAtIg_d1[10];
  UInt8 localTmpSignalConversionAtIgS_d;
  UInt16 localTmpSignalConversionAtEng_h;
  UInt16 localTmpSignalConversionAtIgS_p;
  UInt16 localTmpSignalConversionAtFARSp;
  UInt16 localTmpSignalConversionAtEng_l;
  UInt16 localTmpSignalConversionAtEng_i;
  SInt16 localTmpSignalConversionAtExt_a;
  UInt8 localTmpSignalConversionAtIgS_j;
  UInt8 localTmpSignalConversionAtIgS_a;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_IgAdvOptm'
   */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_c);

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  localDataTypeConversion_i = (Float32)localTmpSignalConversionAtExt_c;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_gmaInMixtOutport2' incorporates:
   *  Inport: '<Root>/ExM_gmaInMixt'
   */
  Rte_Read_R_ExM_gmaInMixt_ExM_gmaInMixt(&localTmpSignalConversionAtExM_g);

  /* DataTypeConversion: '<S8>/Data Type Conversion10' */
  localDataTypeConversion10 = ((Float32)localTmpSignalConversionAtExM_g) *
    0.0009765625F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_molMassInMixtOutport2' incorporates:
   *  Inport: '<Root>/ExM_molMassInMixt'
   */
  Rte_Read_R_ExM_molMassInMixt_ExM_molMassInMixt
    (&localTmpSignalConversionAtExM_m);

  /* DataTypeConversion: '<S8>/Data Type Conversion11' */
  localDataTypeConversion11 = ((Float32)localTmpSignalConversionAtExM_m) *
    0.0078125F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEngM_mAirCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mAirCor'
   */
  Rte_Read_R_EngM_mAirCor_EngM_mAirCor(&localTmpSignalConversionAtEn_ha);

  /* DataTypeConversion: '<S8>/Data Type Conversion12' */
  localDataTypeConversion12 = ((Float32)localTmpSignalConversionAtEn_ha) *
    1.192016583E-007F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEngM_mBurnCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mBurnCor'
   */
  Rte_Read_R_EngM_mBurnCor_EngM_mBurnCor(&localTmpSignalConversionAtEng_n);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtInM_mEGREstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mEGREstim'
   */
  Rte_Read_R_InM_mEGREstim_InM_mEGREstim(&localTmpSignalConversionAtInM_m);

  /* DataTypeConversion: '<S8>/Data Type Conversion14' */
  AdvOptmT_B.DataTypeConversion14 = ((Float32)localTmpSignalConversionAtInM_m) *
    1.862645149E-009F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgCmbModOfsOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgCmbModOfs'
   */
  Rte_Read_R_IgSys_agIgCmbModOfs_IgSys_agIgCmbModOfs
    (&localTmpSignalConversionAtIgS_g);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgOptmFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgOptmFlex'
   */
  Rte_Read_R_IgSys_agIgOptmFlex_IgSys_agIgOptmFlex
    (&localTmpSignalConversionAtIg_gu);

  /* DataTypeConversion: '<S8>/Data Type Conversion16' */
  localDataTypeConversion16 = (((Float32)localTmpSignalConversionAtIg_gu) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_prm_facFlexOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_facFlex'
   */
  Rte_Read_R_IgSys_prm_facFlex_IgSys_prm_facFlex
    (&localTmpSignalConversionAtIgS_f);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_prm_facGasOutport2' incorporates:
   *  Inport: '<Root>/IgSys_prm_facGas'
   */
  Rte_Read_R_IgSys_prm_facGas_IgSys_prm_facGas(&localTmpSignalConversionAtIg_d1);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgOptmGasOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgOptmGas'
   */
  Rte_Read_R_IgSys_agIgOptmGas_IgSys_agIgOptmGas
    (&localTmpSignalConversionAtIgS_d);

  /* DataTypeConversion: '<S8>/Data Type Conversion19' */
  localDataTypeConversion19 = (((Float32)localTmpSignalConversionAtIgS_d) *
    0.375F) - 36.0F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEng_h);

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  localDataTypeConversion2_d = ((Float32)localTmpSignalConversionAtEng_h) *
    6.103515625E-005F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_rlamClcOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rlamClc'
   */
  Rte_Read_R_IgSys_rlamClc_IgSys_rlamClc(&localTmpSignalConversionAtIgS_p);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&localTmpSignalConversionAtFARSp);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEngM_rItBurnRateCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rItBurnRateCor'
   */
  Rte_Read_R_EngM_rItBurnRateCor_EngM_rItBurnRateCor
    (&localTmpSignalConversionAtEng_l);

  /* DataTypeConversion: '<S8>/Data Type Conversion6' */
  localDataTypeConversion6 = ((Float32)localTmpSignalConversionAtEng_l) *
    6.103515625E-005F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtEx_n5);

  /* DataTypeConversion: '<S8>/Data Type Conversion7' */
  localDataTypeConversion7 = (Float32)localTmpSignalConversionAtEx_n5;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEngM_tMixtCylCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_tMixtCylCor'
   */
  Rte_Read_R_EngM_tMixtCylCor_EngM_tMixtCylCor(&localTmpSignalConversionAtEng_i);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_agCkOpInVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkOpInVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0
    (&localTmpSignalConversionAtExt_a);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* Outputs for atomic SubSystem: '<S8>/F0_01_Condition_d_activation' */

  /* RelationalOperator: '<S14>/Relational Operator' incorporates:
   *  Constant: '<S14>/Ext_stRun_SC'
   */
  IgSys_bAcvAdvOptm = (localTmpSignalConversionAtEng_s == Ext_stRun_SC);

  /* end of Outputs for SubSystem: '<S8>/F0_01_Condition_d_activation' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_bAcvClsLoopOutport2' */
  localTmpSignalConversionAtIgS_n =
    Rte_IrvRead_RE_AdvOptmT_003_DRE_IgSys_bAcvClsLoop_irv();

  /* Outputs for enable SubSystem: '<S8>/F0_02_Calcul_avance_optimale' incorporates:
   *  EnablePort: '<S15>/IgSys_bActAdvOptm'
   */
  if (IgSys_bAcvAdvOptm) {
    /* Outputs for atomic SubSystem: '<S15>/F01_Calcul_Richesse' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/IgSys_bLamEng_C'
     *  DataTypeConversion: '<S8>/Data Type Conversion3'
     *  DataTypeConversion: '<S8>/Data Type Conversion4'
     */
    if (IgSys_bLamEng_C) {
      IgSys_rlamSel = ((Float32)localTmpSignalConversionAtIgS_p) *
        2.240000031E-004F;
    } else {
      IgSys_rlamSel = ((Float32)localTmpSignalConversionAtFARSp) *
        0.000244140625F;
    }

    /* end of Outputs for SubSystem: '<S15>/F01_Calcul_Richesse' */

    /* Outputs for atomic SubSystem: '<S15>/F02_Calcul_Masse_Melange_et_Carburant_dans_Cylindre' */

    /* Product: '<S34>/Divide' incorporates:
     *  Constant: '<S20>/Eng_rAfs_C'
     *  Product: '<S37>/Divide'
     */
    localDivide_nw = (IgSys_rlamSel * localDataTypeConversion12) / Eng_rAfs_C;

    /* Outputs for atomic SubSystem: '<S34>/If Action Subsystem3' */

    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant2'
     *  RelationalOperator: '<S39>/Relational Operator'
     *  Saturate: '<S39>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      localSwitch1_n = 0.0F;
    } else {
      localSwitch1_n = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S34>/If Action Subsystem3' */

    /* Product: '<S35>/Divide' incorporates:
     *  Constant: '<S20>/Eng_rAfs_C'
     *  Constant: '<S20>/IgSys_rlamMaxMsFuCyl_C'
     *  MinMax: '<S20>/MinMax'
     *  Product: '<S36>/Divide'
     */
    localDivide_nw = (localDataTypeConversion12 * rt_MINf(IgSys_rlamSel,
      IgSys_rlamMaxMsFuCyl_C)) / Eng_rAfs_C;

    /* Outputs for atomic SubSystem: '<S35>/If Action Subsystem3' */

    /* Switch: '<S41>/Switch1' incorporates:
     *  Constant: '<S41>/Constant2'
     *  RelationalOperator: '<S41>/Relational Operator'
     *  Saturate: '<S41>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_mFuCyl = 0.0F;
    } else {
      IgSys_mFuCyl = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S35>/If Action Subsystem3' */

    /* Sum: '<S20>/Sum1' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion13'
     */
    IgSys_mMixtCyl = (localSwitch1_n + localDataTypeConversion12) + (((Float32)
      localTmpSignalConversionAtEng_n) * 1.192016583E-007F);

    /* end of Outputs for SubSystem: '<S15>/F02_Calcul_Masse_Melange_et_Carburant_dans_Cylindre' */

    /* Outputs for atomic SubSystem: '<S15>/F03_Calcul_angles_utiles' */

    /* Sum: '<S21>/Sum1' incorporates:
     *  Constant: '<S21>/IgSys_agCkClsInVlvRef1Delta_C'
     *  Constant: '<S21>/IgSys_agCkOpClsInVlvDelta_C'
     *  DataTypeConversion: '<S8>/Data Type Conversion9'
     */
    IgSys_agCkClsInVlvEstimRef1 = ((((Float32)localTmpSignalConversionAtExt_a) *
      0.09375F) + IgSys_agCkOpClsInVlvDelta_C) + IgSys_agCkClsInVlvRef1Delta_C;

    /* end of Outputs for SubSystem: '<S15>/F03_Calcul_angles_utiles' */

    /* Outputs for atomic SubSystem: '<S15>/F04_Calcul_temperature_fermeture_admission' */

    /* SignalConversion: '<S22>/TmpSignal ConversionAtSignal ConversionInport1' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion8'
     */
    IgSys_tMixtCylIVCRef1 = (((Float32)localTmpSignalConversionAtEng_i) *
      0.03125F) + 223.0F;

    /* end of Outputs for SubSystem: '<S15>/F04_Calcul_temperature_fermeture_admission' */

    /* Outputs for atomic SubSystem: '<S15>/F05_Calcul_preliminaire_des_parametres_de_calibration' */

    /* Outputs for atomic SubSystem: '<S23>/F0_02_05_01_Angle_de_reference' */

    /* Lookup2D: '<S44>/Look-Up Table (2-D)'
     * About '<S44>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(IgSys_agIgOptmRef),
      (&(IgSys_agIgOptmRef_M[0])), localDataTypeConversion_i,
      (&(IgSys_nEng_AgIgOptmRefX_A[0])), 15U, localDataTypeConversion2_d,
      (&(IgSys_rAirLd_AgIgOptmRefY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S44>/Data Type Duplicate2'
     *
     * Regarding '<S44>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S45>/Look-Up Table (2-D)'
     * About '<S45>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(IgSys_agCkMFB5Ref),
      (&(IgSys_agCkMFB5Ref_M[0])), localDataTypeConversion_i,
      (&(IgSys_nEng_AgCkMFB5RefX_A[0])), 15U, localDataTypeConversion2_d,
      (&(IgSys_rAirLd_AgCkMFB5RefY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S45>/Data Type Duplicate2'
     *
     * Regarding '<S45>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S46>/Look-Up Table (2-D)'
     * About '<S46>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(IgSys_agCkMFB50Ref),
      (&(IgSys_agCkMFB50Ref_M[0])), localDataTypeConversion_i,
      (&(IgSys_nEng_AgCkMFB50RefX_A[0])), 15U, localDataTypeConversion2_d,
      (&(IgSys_rAirLd_AgCkMFB50RefY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S46>/Data Type Duplicate2'
     *
     * Regarding '<S46>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S49>/Data Type Conversion'
     *
     * Regarding '<S49>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* end of Outputs for SubSystem: '<S23>/F0_02_05_01_Angle_de_reference' */

    /* Outputs for atomic SubSystem: '<S23>/F0_02_05_02_Calcul_Constante_de_reference' */

    /* Lookup2D: '<S47>/Look-Up Table (2-D)'
     * About '<S47>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(IgSys_facCmbRef), (&(IgSys_facCmbRef_M
      [0])), localDataTypeConversion_i, (&(IgSys_nEng_FacCmbRefX_A[0])), 15U,
      localDataTypeConversion2_d, (&(IgSys_rAirLd_FacCmbRefY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S47>/Data Type Duplicate2'
     *
     * Regarding '<S47>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S48>/Look-Up Table (2-D)'
     * About '<S48>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(IgSys_facIniRef), (&(IgSys_facIniRef_M
      [0])), localDataTypeConversion_i, (&(IgSys_nEng_FacIniRefX_A[0])), 15U,
      localDataTypeConversion2_d, (&(IgSys_rAirLd_FacIniRefY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S48>/Data Type Duplicate2'
     *
     * Regarding '<S48>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S23>/F0_02_05_02_Calcul_Constante_de_reference' */

    /* end of Outputs for SubSystem: '<S15>/F05_Calcul_preliminaire_des_parametres_de_calibration' */

    /* Outputs for atomic SubSystem: '<S15>/F06_Calcul_Hauteur_Volume_Chambre_Reference' */

    /* Lookup: '<S50>/Look-Up Table'
     * About '<S50>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(IgSys_volCylIVCRef1), (&(IgSys_volCylIVCRef1_T[0])),
      IgSys_agCkClsInVlvEstimRef1, (&(IgSys_agCkClsInVlvEstimRef1_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S50>/Data Type Duplicate1'
     *
     * Regarding '<S50>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S75>/Data Type Propagation'
     *
     * Regarding '<S75>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S89>/Data Type Propagation'
     *
     * Regarding '<S89>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S134>/Data Type Propagation'
     *
     * Regarding '<S134>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S75>/Data Type Conversion'
     *
     * Regarding '<S75>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S89>/Data Type Conversion'
     *
     * Regarding '<S89>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S134>/Data Type Conversion'
     *
     * Regarding '<S134>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Lookup: '<S49>/Look-Up Table'
     * About '<S49>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(IgSys_volCylMFB50Ref),
      (&(IgSys_volCylMFB50Ref_T[0])), IgSys_agCkMFB50Ref, (&(IgSys_agCkMFB50_A[0])),
      15U);

    /* DataTypeDuplicate Block: '<S49>/Data Type Duplicate1'
     *
     * Regarding '<S49>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S51>/Data Type Propagation'
     *
     * Regarding '<S51>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S134>/Data Type Propagation1'
     *
     * Regarding '<S134>/Data Type Propagation1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S145>/Data Type Conversion'
     *
     * Regarding '<S145>/Data Type Conversion':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S145>/Data Type Propagation'
     *
     * Regarding '<S145>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S145>/Data Type Conversion1'
     *
     * Regarding '<S145>/Data Type Conversion1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S135>/Data Type Propagation1'
     *
     * Regarding '<S135>/Data Type Propagation1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S147>/Data Type Conversion'
     *
     * Regarding '<S147>/Data Type Conversion':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S147>/Data Type Propagation'
     *
     * Regarding '<S147>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S147>/Data Type Conversion1'
     *
     * Regarding '<S147>/Data Type Conversion1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S153>/Data Type Propagation1'
     *
     * Regarding '<S153>/Data Type Propagation1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S156>/Data Type Conversion'
     *
     * Regarding '<S156>/Data Type Conversion':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S156>/Data Type Propagation'
     *
     * Regarding '<S156>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S156>/Data Type Conversion1'
     *
     * Regarding '<S156>/Data Type Conversion1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S51>/Data Type Conversion'
     *
     * Regarding '<S51>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S134>/Data Type Conversion1'
     *
     * Regarding '<S134>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S135>/Data Type Conversion1'
     *
     * Regarding '<S135>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S153>/Data Type Conversion1'
     *
     * Regarding '<S153>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* Constant: '<S24>/IgSys_surProjPist_C' */
    IgSys_surProjPist = IgSys_surProjPist_C;

    /* Product: '<S51>/Divide' */
    localDivide_nw = IgSys_volCylMFB50Ref / IgSys_surProjPist;

    /* Outputs for atomic SubSystem: '<S51>/If Action Subsystem3' */

    /* Switch: '<S53>/Switch1' incorporates:
     *  Constant: '<S53>/Constant2'
     *  RelationalOperator: '<S53>/Relational Operator'
     *  Saturate: '<S53>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_dstCylMFB50Ref = 0.0F;
    } else {
      IgSys_dstCylMFB50Ref = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S51>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S15>/F06_Calcul_Hauteur_Volume_Chambre_Reference' */

    /* Outputs for atomic SubSystem: '<S15>/F07_Calcul_Parametres_Communs' */

    /* Constant: '<S25>/Constant2' */
    IgSys_ra = 8.314000130E+000F;

    /* Constant: '<S25>/IgSys_facPCI_C' */
    IgSys_facPCI = IgSys_facPCI_C;

    /* Lookup: '<S54>/Look-Up Table'
     * About '<S54>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(IgSys_velLamiFlameT0),
      (&(IgSys_velLamiFlameT0_T[0])), IgSys_rlamSel,
      (&(IgSys_rlamSel_VelLamiFlameT0_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate1'
     *
     * Regarding '<S54>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S55>/Look-Up Table (2-D)'
     * About '<S55>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(IgSys_facAeroCor),
      (&(IgSys_facAeroCor_M[0])), localDataTypeConversion_i,
      (&(IgSys_nEng_FacAeroCorX_A[0])), 15U, IgSys_agCkClsInVlvEstimRef1,
      (&(IgSys_agCkClsInVlvRef1Y_A[0])), 7U);

    /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate2'
     *
     * Regarding '<S55>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S15>/F07_Calcul_Parametres_Communs' */

    /* Outputs for atomic SubSystem: '<S15>/F08_Selection_Angles_Depart' */

    /* Switch: '<S26>/Switch' incorporates:
     *  UnitDelay: '<S57>/Unit Delay'
     */
    if (localTmpSignalConversionAtIgS_n) {
      IgSys_agIgOptmSel = AdvOptmT_DWork.UnitDelay_DSTATE;
    } else {
      IgSys_agIgOptmSel = IgSys_agIgOptmRef;
    }

    /* Switch: '<S26>/Switch1' incorporates:
     *  UnitDelay: '<S58>/Unit Delay'
     */
    if (localTmpSignalConversionAtIgS_n) {
      IgSys_agCkMFB5Sel = AdvOptmT_DWork.UnitDelay_DSTATE_g;
    } else {
      IgSys_agCkMFB5Sel = IgSys_agCkMFB5Ref;
    }

    /* UnitDelay: '<S56>/Unit Delay' */
    localUnitDelay_c = AdvOptmT_DWork.UnitDelay_DSTATE_n;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S59>/autosar_testpoint1' */

    /* S-Function Block: <S59>/autosar_testpoint1 */
    IgSys_bAcvClsLoop_IRV_MP = localUnitDelay_c;

    /* SignalConversion: '<S26>/Signal Conversion' */
    AdvOptmT_B.IgSys_bAcvClsLoop_irv_e = localUnitDelay_c;

    /* end of Outputs for SubSystem: '<S15>/F08_Selection_Angles_Depart' */

    /* Outputs for atomic SubSystem: '<S15>/F09_Calcul_Delai_d_initialisation' */

    /* Outputs for atomic SubSystem: '<S27>/F01_Calcul_du_volume_chambre' */

    /* Lookup: '<S67>/Look-Up Table'
     * About '<S67>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(IgSys_volCylSAOptmSel), (&(IgSys_volCylSAOptm_T
      [0])), IgSys_agIgOptmSel, (&(IgSys_agIgOptm_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S67>/Data Type Duplicate1'
     *
     * Regarding '<S67>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S75>/Data Type Propagation1'
     *
     * Regarding '<S75>/Data Type Propagation1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S82>/Data Type Conversion'
     *
     * Regarding '<S82>/Data Type Conversion':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S82>/Data Type Propagation'
     *
     * Regarding '<S82>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S82>/Data Type Conversion1'
     *
     * Regarding '<S82>/Data Type Conversion1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S77>/Data Type Propagation1'
     *
     * Regarding '<S77>/Data Type Propagation1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S86>/Data Type Conversion'
     *
     * Regarding '<S86>/Data Type Conversion':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S86>/Data Type Propagation'
     *
     * Regarding '<S86>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S86>/Data Type Conversion1'
     *
     * Regarding '<S86>/Data Type Conversion1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S75>/Data Type Conversion1'
     *
     * Regarding '<S75>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S77>/Data Type Conversion1'
     *
     * Regarding '<S77>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* Product: '<S71>/Divide' incorporates:
     *  Constant: '<S60>/Cste_2'
     *  Sum: '<S60>/Sum'
     */
    localDivide_fvh = (IgSys_agCkMFB5Sel - IgSys_agIgOptmSel) / 2.0F;

    /* Lookup: '<S68>/Look-Up Table'
     * About '<S68>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(IgSys_volCylIni), (&(IgSys_volCylAgCkIni_T[0])),
      localDivide_fvh, (&(IgSys_agCkIni_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S68>/Data Type Duplicate1'
     *
     * Regarding '<S68>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S70>/Data Type Propagation'
     *
     * Regarding '<S70>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S109>/Data Type Propagation1'
     *
     * Regarding '<S109>/Data Type Propagation1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S111>/Data Type Conversion'
     *
     * Regarding '<S111>/Data Type Conversion':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S111>/Data Type Propagation'
     *
     * Regarding '<S111>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S111>/Data Type Conversion1'
     *
     * Regarding '<S111>/Data Type Conversion1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S70>/Data Type Conversion'
     *
     * Regarding '<S70>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S109>/Data Type Conversion1'
     *
     * Regarding '<S109>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* Lookup: '<S69>/Look-Up Table'
     * About '<S69>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(IgSys_volCylMFB5Sel), (&(IgSys_volCylMFB5_T[0])),
      IgSys_agCkMFB5Sel, (&(IgSys_agCkMFB5_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S69>/Data Type Duplicate1'
     *
     * Regarding '<S69>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S89>/Data Type Propagation1'
     *
     * Regarding '<S89>/Data Type Propagation1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S100>/Data Type Conversion'
     *
     * Regarding '<S100>/Data Type Conversion':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S100>/Data Type Propagation'
     *
     * Regarding '<S100>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S100>/Data Type Conversion1'
     *
     * Regarding '<S100>/Data Type Conversion1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S90>/Data Type Propagation1'
     *
     * Regarding '<S90>/Data Type Propagation1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S102>/Data Type Conversion'
     *
     * Regarding '<S102>/Data Type Conversion':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S102>/Data Type Propagation'
     *
     * Regarding '<S102>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S102>/Data Type Conversion1'
     *
     * Regarding '<S102>/Data Type Conversion1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S89>/Data Type Conversion1'
     *
     * Regarding '<S89>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S90>/Data Type Conversion1'
     *
     * Regarding '<S90>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* Product: '<S70>/Divide' */
    localSwitch1_n = IgSys_volCylIni / IgSys_surProjPist;

    /* Outputs for atomic SubSystem: '<S70>/If Action Subsystem3' */

    /* Switch: '<S73>/Switch1' incorporates:
     *  Constant: '<S73>/Constant2'
     *  RelationalOperator: '<S73>/Relational Operator'
     *  Saturate: '<S73>/Saturation'
     */
    if (localSwitch1_n != localSwitch1_n) {
      IgSys_dstCylIni = 0.0F;
    } else {
      IgSys_dstCylIni = rt_SATURATE(localSwitch1_n, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S70>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S27>/F01_Calcul_du_volume_chambre' */

    /* Outputs for atomic SubSystem: '<S27>/F02_Calcul_Conditions_melange_Allumage' */

    /* Product: '<S75>/Divide' */
    localDivide_nw = IgSys_volCylIVCRef1 / IgSys_volCylSAOptmSel;

    /* Outputs for atomic SubSystem: '<S75>/If Action Subsystem3' */

    /* Switch: '<S83>/Switch1' incorporates:
     *  Constant: '<S83>/Constant2'
     *  RelationalOperator: '<S83>/Relational Operator'
     *  Saturate: '<S83>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_rVolCmprSAOSel_MP = 0.0F;
    } else {
      IgSys_rVolCmprSAOSel_MP = rt_SATURATE(localDivide_nw, -1.0E+007F,
        1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S75>/If Action Subsystem3' */

    /* Sum: '<S61>/Sum' incorporates:
     *  Constant: '<S61>/Cste_1'
     */
    localSum_e = localDataTypeConversion10 - 1.0F;

    /* Lookup2D: '<S74>/Look-Up Table (2-D)'
     * About '<S74>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_cg),
      (&(IgSys_facPwLawGma1_M[0])), IgSys_rVolCmprSAOSel_MP,
      (&(IgSys_rVolCmprX_A[0])), 15U, localSum_e, (&(IgSys_gma1Y_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S74>/Data Type Duplicate2'
     *
     * Regarding '<S74>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S81>/Divide' incorporates:
     *  Constant: '<S61>/Cste_1'
     *  Lookup2D: '<S74>/Look-Up Table (2-D)'
     *  Sum: '<S61>/Sum'
     */
    IgSys_tMixtCylSAOptm = IgSys_tMixtCylIVCRef1 * localLookUpTable2D_cg;

    /* Product: '<S76>/Divide' incorporates:
     *  Constant: '<S61>/Cste_0_01'
     *  Constant: '<S61>/Cste_4'
     *  MinMax: '<S61>/MinMax2'
     *  Product: '<S78>/Divide'
     *  Product: '<S79>/Divide'
     *  Product: '<S80>/Divide'
     */
    localDivide_nw = ((IgSys_mMixtCyl * IgSys_ra) * IgSys_tMixtCylSAOptm) /
      (rt_MAXf(localDataTypeConversion11, 9.999999776E-003F) / 1000.0F);

    /* Outputs for atomic SubSystem: '<S76>/If Action Subsystem3' */

    /* Switch: '<S85>/Switch1' incorporates:
     *  Constant: '<S85>/Constant1'
     *  Constant: '<S85>/Constant2'
     *  Constant: '<S85>/Constant3'
     *  Logic: '<S85>/Logical Operator1'
     *  RelationalOperator: '<S85>/Relational Operator'
     *  RelationalOperator: '<S85>/Relational Operator1'
     *  RelationalOperator: '<S85>/Relational Operator3'
     */
    if (((localDivide_nw != localDivide_nw) || (localDivide_nw >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_nw)) {
      localDivide_nw = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S76>/If Action Subsystem3' */

    /* Product: '<S77>/Divide' */
    localDivide_nw /= IgSys_volCylSAOptmSel;

    /* Outputs for atomic SubSystem: '<S77>/If Action Subsystem3' */

    /* Switch: '<S87>/Switch1' incorporates:
     *  Constant: '<S87>/Constant1'
     *  Constant: '<S87>/Constant2'
     *  Constant: '<S87>/Constant3'
     *  Logic: '<S87>/Logical Operator1'
     *  RelationalOperator: '<S87>/Relational Operator'
     *  RelationalOperator: '<S87>/Relational Operator1'
     *  RelationalOperator: '<S87>/Relational Operator3'
     */
    if (((localDivide_nw != localDivide_nw) || (localDivide_nw >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_nw)) {
      IgSys_pMixtCylSAOptm = 0.0F;
    } else {
      IgSys_pMixtCylSAOptm = localDivide_nw;
    }

    /* end of Outputs for SubSystem: '<S77>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S27>/F02_Calcul_Conditions_melange_Allumage' */

    /* Outputs for atomic SubSystem: '<S27>/F03_Calcul_Conditions_melange_MFB5comb' */

    /* Product: '<S89>/Divide' */
    localDivide_nw = IgSys_volCylIVCRef1 / IgSys_volCylMFB5Sel;

    /* Outputs for atomic SubSystem: '<S89>/If Action Subsystem3' */

    /* Switch: '<S101>/Switch1' incorporates:
     *  Constant: '<S101>/Constant2'
     *  RelationalOperator: '<S101>/Relational Operator'
     *  Saturate: '<S101>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_rVolCmprMFB5Sel_MP = 0.0F;
    } else {
      IgSys_rVolCmprMFB5Sel_MP = rt_SATURATE(localDivide_nw, -1.0E+007F,
        1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S89>/If Action Subsystem3' */

    /* Sum: '<S62>/Sum1' incorporates:
     *  Constant: '<S62>/Cste_1'
     */
    localSum1_j = localDataTypeConversion10 - 1.0F;

    /* Lookup2D: '<S88>/Look-Up Table (2-D)'
     * About '<S88>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_f),
      (&(IgSys_facPwLawGma1_M[0])), IgSys_rVolCmprMFB5Sel_MP,
      (&(IgSys_rVolCmprX_A[0])), 15U, localSum1_j, (&(IgSys_gma1Y_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S88>/Data Type Duplicate2'
     *
     * Regarding '<S88>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S97>/Divide' incorporates:
     *  Constant: '<S62>/Cste_1'
     *  Lookup2D: '<S88>/Look-Up Table (2-D)'
     *  Sum: '<S62>/Sum1'
     */
    IgSys_tMixtCylMFB5wCmb_MP = IgSys_tMixtCylIVCRef1 * localLookUpTable2D_f;

    /* Sum: '<S62>/Sum2' incorporates:
     *  Constant: '<S62>/Cste_0_1'
     *  Constant: '<S62>/Cste_1_1'
     *  Constant: '<S62>/Cste_1e_1'
     *  MinMax: '<S62>/MinMax2'
     *  Product: '<S92>/Divide'
     *  Product: '<S93>/Divide'
     *  Product: '<S96>/Divide'
     *  Product: '<S98>/Divide'
     */
    IgSys_tMixtCylMFB5 = ((((5.000000075E-002F * IgSys_facPCI) * IgSys_mFuCyl) /
      rt_MAXf(IgSys_mMixtCyl, 1.000000012E-007F)) / 1.200000048E+000F) +
      IgSys_tMixtCylMFB5wCmb_MP;

    /* Product: '<S91>/Divide' incorporates:
     *  Constant: '<S62>/Cste_0_2'
     *  Constant: '<S62>/Cste_4'
     *  MinMax: '<S62>/MinMax1'
     *  Product: '<S94>/Divide'
     *  Product: '<S95>/Divide'
     *  Product: '<S99>/Divide'
     */
    localDivide_nw = ((IgSys_mMixtCyl * IgSys_ra) * IgSys_tMixtCylMFB5) /
      (rt_MAXf(localDataTypeConversion11, 9.999999776E-003F) / 1000.0F);

    /* Outputs for atomic SubSystem: '<S91>/If Action Subsystem3' */

    /* Switch: '<S105>/Switch1' incorporates:
     *  Constant: '<S105>/Constant1'
     *  Constant: '<S105>/Constant2'
     *  Constant: '<S105>/Constant3'
     *  Logic: '<S105>/Logical Operator1'
     *  RelationalOperator: '<S105>/Relational Operator'
     *  RelationalOperator: '<S105>/Relational Operator1'
     *  RelationalOperator: '<S105>/Relational Operator3'
     */
    if (((localDivide_nw != localDivide_nw) || (localDivide_nw >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_nw)) {
      localDivide_nw = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S91>/If Action Subsystem3' */

    /* Product: '<S90>/Divide' */
    localDivide_nw /= IgSys_volCylMFB5Sel;

    /* Outputs for atomic SubSystem: '<S90>/If Action Subsystem3' */

    /* Switch: '<S103>/Switch1' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Constant: '<S103>/Constant2'
     *  Constant: '<S103>/Constant3'
     *  Logic: '<S103>/Logical Operator1'
     *  RelationalOperator: '<S103>/Relational Operator'
     *  RelationalOperator: '<S103>/Relational Operator1'
     *  RelationalOperator: '<S103>/Relational Operator3'
     */
    if (((localDivide_nw != localDivide_nw) || (localDivide_nw >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_nw)) {
      IgSys_pMixtCylMFB5 = 0.0F;
    } else {
      IgSys_pMixtCylMFB5 = localDivide_nw;
    }

    /* end of Outputs for SubSystem: '<S90>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S27>/F03_Calcul_Conditions_melange_MFB5comb' */

    /* Outputs for atomic SubSystem: '<S27>/F04_Calcul_Conditions_moyennes_Initialisation' */

    /* Product: '<S107>/Divide' incorporates:
     *  Constant: '<S63>/Cste_2'
     *  Sum: '<S63>/Sum2'
     */
    IgSys_tMixtCylIni = (IgSys_tMixtCylSAOptm + IgSys_tMixtCylMFB5) / 2.0F;

    /* Product: '<S106>/Divide' incorporates:
     *  Constant: '<S63>/Cste_2_1'
     *  Sum: '<S63>/Sum1'
     */
    IgSys_pMixtCylIni = (IgSys_pMixtCylSAOptm + IgSys_pMixtCylMFB5) / 2.0F;

    /* end of Outputs for SubSystem: '<S27>/F04_Calcul_Conditions_moyennes_Initialisation' */

    /* Outputs for atomic SubSystem: '<S27>/F05_Calcul_NU_viscosite_cinematique_Initialisation' */

    /* Lookup: '<S108>/Look-Up Table'
     * About '<S108>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(localLookUpTable_g), (&(IgSys_visDInMixt_T[0])),
      IgSys_tMixtCylIni, (&(IgSys_tMixtCyl_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S108>/Data Type Duplicate1'
     *
     * Regarding '<S108>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S110>/Data Type Propagation'
     *
     * Regarding '<S110>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S110>/Data Type Conversion'
     *
     * Regarding '<S110>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Product: '<S109>/Divide' incorporates:
     *  Constant: '<S64>/Cste_1e_7'
     *  MinMax: '<S64>/MinMax2'
     */
    localDivide_nw = rt_MAXf(IgSys_mMixtCyl, 1.000000012E-007F) /
      IgSys_volCylIni;

    /* Outputs for atomic SubSystem: '<S109>/If Action Subsystem3' */

    /* Switch: '<S112>/Switch1' incorporates:
     *  Constant: '<S112>/Constant2'
     *  RelationalOperator: '<S112>/Relational Operator'
     *  Saturate: '<S112>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_densMixtIni_MP = 0.0F;
    } else {
      IgSys_densMixtIni_MP = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S109>/If Action Subsystem3' */

    /* Product: '<S110>/Divide' incorporates:
     *  Lookup: '<S108>/Look-Up Table'
     */
    localDivide_nw = localLookUpTable_g / IgSys_densMixtIni_MP;

    /* Outputs for atomic SubSystem: '<S110>/If Action Subsystem3' */

    /* Switch: '<S114>/Switch1' incorporates:
     *  Constant: '<S114>/Constant2'
     *  RelationalOperator: '<S114>/Relational Operator'
     *  Saturate: '<S114>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_visKIni = 0.0F;
    } else {
      IgSys_visKIni = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S110>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S27>/F05_Calcul_NU_viscosite_cinematique_Initialisation' */

    /* Outputs for atomic SubSystem: '<S27>/F06_Calcul_SL_Vitesse_de_flamme_laminaire_Initialisation' */

    /* Lookup: '<S115>/Look-Up Table'
     * About '<S115>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(localLookUpTable_n),
      (&(IgSys_facPwLawDeltaIni_T[0])), localDataTypeConversion6,
      (&(IgSys_rItBurnRateCor_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S115>/Data Type Duplicate1'
     *
     * Regarding '<S115>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S116>/Look-Up Table (2-D)'
     * About '<S116>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_nf),
      (&(IgSys_facPwLawAlpha_M[0])), IgSys_tMixtCylIni, (&(IgSys_tMixtCylX_A[0])),
      15U, IgSys_rlamSel, (&(IgSys_rAfrSelY_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S116>/Data Type Duplicate2'
     *
     * Regarding '<S116>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S117>/Look-Up Table (2-D)'
     * About '<S117>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_m),
      (&(IgSys_facPwLawBeta_M[0])), IgSys_pMixtCylIni, (&(IgSys_pMixtCylX_A[0])),
      15U, IgSys_rlamSel, (&(IgSys_rAfrSelY_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S117>/Data Type Duplicate2'
     *
     * Regarding '<S117>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S119>/Divide' incorporates:
     *  Lookup2D: '<S116>/Look-Up Table (2-D)'
     *  Lookup2D: '<S117>/Look-Up Table (2-D)'
     *  Lookup: '<S115>/Look-Up Table'
     *  Product: '<S118>/Divide'
     *  Product: '<S120>/Divide'
     */
    IgSys_velLamiFlameIni = ((IgSys_velLamiFlameT0 * localLookUpTable2D_nf) *
      localLookUpTable2D_m) * localLookUpTable_n;

    /* end of Outputs for SubSystem: '<S27>/F06_Calcul_SL_Vitesse_de_flamme_laminaire_Initialisation' */

    /* Outputs for atomic SubSystem: '<S27>/F07_Calcul_Delai_initialisation_et_MFB5' */

    /* Product: '<S126>/Divide' */
    localDivide_ex = IgSys_facAeroCor * IgSys_visKIni;

    /* Lookup: '<S121>/Look-Up Table'
     * About '<S121>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(localLookUpTable_j), (&(IgSys_facPwLaw033Prod_T
      [0])), localDivide_ex, (&(IgSys_facVisKFacAeroCorProd_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S121>/Data Type Duplicate1'
     *
     * Regarding '<S121>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S123>/Divide' incorporates:
     *  Constant: '<S66>/Cste_0_01'
     *  MinMax: '<S66>/MinMax1'
     */
    localDivide_pg = IgSys_dstCylIni / rt_MAXf(IgSys_velLamiFlameIni,
      9.999999776E-003F);

    /* Lookup: '<S122>/Look-Up Table'
     * About '<S122>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(localLookUpTable_i), (&(IgSys_facPwLaw067Prod_T
      [0])), localDivide_pg, (&(IgSys_facDstCylVelLamiDiv_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S122>/Data Type Duplicate1'
     *
     * Regarding '<S122>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S125>/Divide' incorporates:
     *  Constant: '<S66>/Cste_0_01'
     *  Lookup: '<S121>/Look-Up Table'
     *  Lookup: '<S122>/Look-Up Table'
     *  MinMax: '<S66>/MinMax1'
     *  Product: '<S123>/Divide'
     *  Product: '<S124>/Divide'
     *  Product: '<S126>/Divide'
     */
    IgSys_agCkSAOptmMFB5DeltaCalc = (localLookUpTable_j * localLookUpTable_i) *
      IgSys_facIniRef;

    /* Sum: '<S66>/Sum3' */
    IgSys_agCkMFB5Calc = IgSys_agCkSAOptmMFB5DeltaCalc - IgSys_agIgOptmSel;

    /* end of Outputs for SubSystem: '<S27>/F07_Calcul_Delai_initialisation_et_MFB5' */

    /* end of Outputs for SubSystem: '<S15>/F09_Calcul_Delai_d_initialisation' */

    /* Outputs for atomic SubSystem: '<S15>/F10_Calculs_Delai_Combustion' */

    /* Outputs for atomic SubSystem: '<S28>/F01_Calcul_Conditions_melange_MFB50combf' */

    /* Product: '<S134>/Divide' */
    localDivide_nw = IgSys_volCylIVCRef1 / IgSys_volCylMFB50Ref;

    /* Outputs for atomic SubSystem: '<S134>/If Action Subsystem3' */

    /* Switch: '<S146>/Switch1' incorporates:
     *  Constant: '<S146>/Constant2'
     *  RelationalOperator: '<S146>/Relational Operator'
     *  Saturate: '<S146>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_rVolCmprMFB50Ref_MP = 0.0F;
    } else {
      IgSys_rVolCmprMFB50Ref_MP = rt_SATURATE(localDivide_nw, -1.0E+007F,
        1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S134>/If Action Subsystem3' */

    /* Sum: '<S127>/Sum' incorporates:
     *  Constant: '<S127>/Cste_1'
     */
    localSum_n = localDataTypeConversion10 - 1.0F;

    /* Lookup2D: '<S133>/Look-Up Table (2-D)'
     * About '<S133>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_e),
      (&(IgSys_facPwLawGma1_M[0])), IgSys_rVolCmprMFB50Ref_MP,
      (&(IgSys_rVolCmprX_A[0])), 15U, localSum_n, (&(IgSys_gma1Y_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S133>/Data Type Duplicate2'
     *
     * Regarding '<S133>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S144>/Divide' incorporates:
     *  Constant: '<S127>/Cste_1'
     *  Lookup2D: '<S133>/Look-Up Table (2-D)'
     *  Sum: '<S127>/Sum'
     */
    IgSys_tMixtCylMFB50RefwCmb_MP = IgSys_tMixtCylIVCRef1 * localLookUpTable2D_e;

    /* Sum: '<S127>/Sum2' incorporates:
     *  Constant: '<S127>/Cste_0_1'
     *  Constant: '<S127>/Cste_1_1'
     *  Constant: '<S127>/Cste_1e_1'
     *  MinMax: '<S127>/MinMax'
     *  Product: '<S137>/Divide'
     *  Product: '<S138>/Divide'
     *  Product: '<S141>/Divide'
     *  Product: '<S142>/Divide'
     */
    IgSys_tMixtCylMFB50 = ((((0.5F * IgSys_facPCI) * IgSys_mFuCyl) / rt_MAXf
      (IgSys_mMixtCyl, 1.000000012E-007F)) / 1.200000048E+000F) +
      IgSys_tMixtCylMFB50RefwCmb_MP;

    /* Product: '<S136>/Divide' incorporates:
     *  Constant: '<S127>/Cste_0_01'
     *  Constant: '<S127>/Cste_1000'
     *  MinMax: '<S127>/MinMax1'
     *  Product: '<S139>/Divide'
     *  Product: '<S140>/Divide'
     *  Product: '<S143>/Divide'
     */
    localDivide_nw = ((IgSys_tMixtCylMFB50 * IgSys_ra) * IgSys_mMixtCyl) /
      (rt_MAXf(localDataTypeConversion11, 9.999999776E-003F) / 1000.0F);

    /* Outputs for atomic SubSystem: '<S136>/If Action Subsystem3' */

    /* Switch: '<S150>/Switch1' incorporates:
     *  Constant: '<S150>/Constant1'
     *  Constant: '<S150>/Constant2'
     *  Constant: '<S150>/Constant3'
     *  Logic: '<S150>/Logical Operator1'
     *  RelationalOperator: '<S150>/Relational Operator'
     *  RelationalOperator: '<S150>/Relational Operator1'
     *  RelationalOperator: '<S150>/Relational Operator3'
     */
    if (((localDivide_nw != localDivide_nw) || (localDivide_nw >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_nw)) {
      localDivide_nw = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S136>/If Action Subsystem3' */

    /* Product: '<S135>/Divide' */
    localDivide_nw /= IgSys_volCylMFB50Ref;

    /* Outputs for atomic SubSystem: '<S135>/If Action Subsystem3' */

    /* Switch: '<S148>/Switch1' incorporates:
     *  Constant: '<S148>/Constant1'
     *  Constant: '<S148>/Constant2'
     *  Constant: '<S148>/Constant3'
     *  Logic: '<S148>/Logical Operator1'
     *  RelationalOperator: '<S148>/Relational Operator'
     *  RelationalOperator: '<S148>/Relational Operator1'
     *  RelationalOperator: '<S148>/Relational Operator3'
     */
    if (((localDivide_nw != localDivide_nw) || (localDivide_nw >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_nw)) {
      IgSys_pMixtCylMFB50 = 0.0F;
    } else {
      IgSys_pMixtCylMFB50 = localDivide_nw;
    }

    /* end of Outputs for SubSystem: '<S135>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S28>/F01_Calcul_Conditions_melange_MFB50combf' */

    /* Outputs for atomic SubSystem: '<S28>/F02_Calcul_condition_moyenne_Combustion' */

    /* SignalConversion: '<S128>/Signal Conversion' */
    IgSys_tMixtCylCmb = IgSys_tMixtCylMFB50;

    /* SignalConversion: '<S128>/Signal Conversion1' */
    IgSys_pMixtCylCmb = IgSys_pMixtCylMFB50;

    /* end of Outputs for SubSystem: '<S28>/F02_Calcul_condition_moyenne_Combustion' */

    /* Outputs for atomic SubSystem: '<S28>/F03_Calcul_Puissance_1tiers_Combustion' */

    /* Lookup: '<S152>/Look-Up Table'
     * About '<S152>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(localLookUpTable_k), (&(IgSys_visDInMixt_T[0])),
      IgSys_tMixtCylCmb, (&(IgSys_tMixtCyl_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S152>/Data Type Duplicate1'
     *
     * Regarding '<S152>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S154>/Data Type Propagation'
     *
     * Regarding '<S154>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S154>/Data Type Conversion'
     *
     * Regarding '<S154>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Product: '<S153>/Divide' incorporates:
     *  Constant: '<S129>/Cste_1e_7'
     *  MinMax: '<S129>/MinMax2'
     */
    localDivide_nw = rt_MAXf(IgSys_mMixtCyl, 1.000000012E-007F) /
      IgSys_volCylMFB50Ref;

    /* Outputs for atomic SubSystem: '<S153>/If Action Subsystem3' */

    /* Switch: '<S157>/Switch1' incorporates:
     *  Constant: '<S157>/Constant2'
     *  RelationalOperator: '<S157>/Relational Operator'
     *  Saturate: '<S157>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      localDivide_nw = 0.0F;
    } else {
      localDivide_nw = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S153>/If Action Subsystem3' */

    /* Product: '<S154>/Divide' incorporates:
     *  Lookup: '<S152>/Look-Up Table'
     */
    localDivide_nw = localLookUpTable_k / localDivide_nw;

    /* Outputs for atomic SubSystem: '<S154>/If Action Subsystem3' */

    /* Switch: '<S159>/Switch1' incorporates:
     *  Constant: '<S159>/Constant2'
     *  RelationalOperator: '<S159>/Relational Operator'
     *  Saturate: '<S159>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_visKCmb_MP = 0.0F;
    } else {
      IgSys_visKCmb_MP = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S154>/If Action Subsystem3' */

    /* Product: '<S155>/Divide' */
    localDivide_c = IgSys_visKCmb_MP * IgSys_facAeroCor;

    /* Lookup: '<S151>/Look-Up Table'
     * About '<S151>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(IgSys_facPwLaw033ProdCmb),
      (&(IgSys_facPwLaw033Prod_T[0])), localDivide_c,
      (&(IgSys_facVisKFacAeroCorProd_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S151>/Data Type Duplicate1'
     *
     * Regarding '<S151>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S28>/F03_Calcul_Puissance_1tiers_Combustion' */

    /* Outputs for atomic SubSystem: '<S28>/F04_Calcul_SL_Vitesse_de_flamme_laminaire_Combustion' */

    /* Lookup: '<S160>/Look-Up Table'
     * About '<S160>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(localLookUpTable_b),
      (&(IgSys_facPwLawDeltaCmb_T[0])), localDataTypeConversion6,
      (&(IgSys_rItBurnRateCor_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S160>/Data Type Duplicate1'
     *
     * Regarding '<S160>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S161>/Look-Up Table (2-D)'
     * About '<S161>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_k),
      (&(IgSys_facPwLawBeta_M[0])), IgSys_pMixtCylCmb, (&(IgSys_pMixtCylX_A[0])),
      15U, IgSys_rlamSel, (&(IgSys_rAfrSelY_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S161>/Data Type Duplicate2'
     *
     * Regarding '<S161>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S162>/Look-Up Table (2-D)'
     * About '<S162>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_c),
      (&(IgSys_facPwLawAlpha_M[0])), IgSys_tMixtCylCmb, (&(IgSys_tMixtCylX_A[0])),
      15U, IgSys_rlamSel, (&(IgSys_rAfrSelY_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S162>/Data Type Duplicate2'
     *
     * Regarding '<S162>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S165>/Divide' incorporates:
     *  Lookup2D: '<S161>/Look-Up Table (2-D)'
     *  Lookup2D: '<S162>/Look-Up Table (2-D)'
     *  Lookup: '<S160>/Look-Up Table'
     *  Product: '<S163>/Divide'
     *  Product: '<S164>/Divide'
     */
    IgSys_velLamiFlameCmb = ((IgSys_velLamiFlameT0 * localLookUpTable2D_c) *
      localLookUpTable2D_k) * localLookUpTable_b;

    /* end of Outputs for SubSystem: '<S28>/F04_Calcul_SL_Vitesse_de_flamme_laminaire_Combustion' */

    /* Outputs for atomic SubSystem: '<S28>/F05_Calcul_du_volume_chambre' */

    /* Lookup: '<S166>/Look-Up Table'
     * About '<S166>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(localLookUpTable_l), (&(IgSys_volCylMFB5_T[0])),
      IgSys_agCkMFB5Calc, (&(IgSys_agCkMFB5_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S166>/Data Type Duplicate1'
     *
     * Regarding '<S166>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S167>/Data Type Propagation'
     *
     * Regarding '<S167>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S167>/Data Type Conversion'
     *
     * Regarding '<S167>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Product: '<S167>/Divide' incorporates:
     *  Lookup: '<S166>/Look-Up Table'
     */
    localDivide_nw = localLookUpTable_l / IgSys_surProjPist;

    /* Outputs for atomic SubSystem: '<S167>/If Action Subsystem3' */

    /* Switch: '<S169>/Switch1' incorporates:
     *  Constant: '<S169>/Constant2'
     *  RelationalOperator: '<S169>/Relational Operator'
     *  Saturate: '<S169>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      IgSys_dstCylMFB5Calc = 0.0F;
    } else {
      IgSys_dstCylMFB5Calc = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S167>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S28>/F05_Calcul_du_volume_chambre' */

    /* Outputs for atomic SubSystem: '<S28>/F06_Calcul_Delai_combustion_et_AAO' */

    /* Product: '<S172>/Divide' incorporates:
     *  Constant: '<S132>/Cste_0_01'
     *  MinMax: '<S132>/MinMax1'
     */
    localDivide_nz = IgSys_dstCylMFB5Calc / rt_MAXf(IgSys_velLamiFlameCmb,
      9.999999776E-003F);

    /* Lookup: '<S170>/Look-Up Table'
     * About '<S170>/Look-Up Table':
     * Input0  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(localLookUpTable), (&(IgSys_facPwLaw067Prod_T[0])),
      localDivide_nz, (&(IgSys_facDstCylVelLamiDiv_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S170>/Data Type Duplicate1'
     *
     * Regarding '<S170>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S171>/Divide' incorporates:
     *  Constant: '<S132>/Cste_1'
     */
    localDivide_nw = 1.0F / IgSys_dstCylMFB50Ref;

    /* Outputs for atomic SubSystem: '<S171>/If Action Subsystem3' */

    /* Switch: '<S177>/Switch1' incorporates:
     *  Constant: '<S177>/Constant2'
     *  RelationalOperator: '<S177>/Relational Operator'
     *  Saturate: '<S177>/Saturation'
     */
    if (localDivide_nw != localDivide_nw) {
      localDivide_nw = 0.0F;
    } else {
      localDivide_nw = rt_SATURATE(localDivide_nw, -1.0E+007F, 1.0E+007F);
    }

    /* end of Outputs for SubSystem: '<S171>/If Action Subsystem3' */

    /* Product: '<S175>/Divide' incorporates:
     *  Constant: '<S132>/Cste_0_01'
     *  Lookup: '<S170>/Look-Up Table'
     *  MinMax: '<S132>/MinMax1'
     *  Product: '<S172>/Divide'
     *  Product: '<S173>/Divide'
     *  Product: '<S174>/Divide'
     */
    IgSys_agCkMFB5MFB50Delta_MP = ((IgSys_facCmbRef * localDivide_nw) *
      IgSys_facPwLaw033ProdCmb) * localLookUpTable;

    /* Sum: '<S132>/Sum1' incorporates:
     *  Sum: '<S132>/Sum3'
     */
    IgSys_agIgOptmCalc = (IgSys_agCkMFB5MFB50Delta_MP +
                          IgSys_agCkSAOptmMFB5DeltaCalc) - IgSys_agCkMFB50Ref;

    /* end of Outputs for SubSystem: '<S28>/F06_Calcul_Delai_combustion_et_AAO' */

    /* end of Outputs for SubSystem: '<S15>/F10_Calculs_Delai_Combustion' */

    /* Outputs for atomic SubSystem: '<S15>/F11_Selection_Angles_Fin' */

    /* Sum: '<S29>/Sum4' incorporates:
     *  Constant: '<S29>/IgSys_agIgOptmMBSatOfs_C'
     */
    localDivide_nw = IgSys_agIgOptmMBSatOfs_C + IgSys_agIgOptmRef;

    /* Sum: '<S29>/Sum1' incorporates:
     *  Constant: '<S29>/IgSys_agIgOptmMBSatOfs_C'
     */
    localSwitch1_n = IgSys_agIgOptmRef - IgSys_agIgOptmMBSatOfs_C;

    /* Switch: '<S182>/Switch' incorporates:
     *  RelationalOperator: '<S182>/UpperRelop'
     */
    if (!(IgSys_agIgOptmCalc < localSwitch1_n)) {
      localSwitch1_n = IgSys_agIgOptmCalc;
    }

    /* Switch: '<S182>/Switch2' incorporates:
     *  RelationalOperator: '<S182>/LowerRelop1'
     */
    if (IgSys_agIgOptmCalc > localDivide_nw) {
      IgSys_agIgOptmCalcSat = localDivide_nw;
    } else {
      IgSys_agIgOptmCalcSat = localSwitch1_n;
    }

    /* Sum: '<S29>/Sum2' incorporates:
     *  Constant: '<S29>/IgSys_agCkMFB5MBSatOfs_C'
     */
    localSwitch1_n = IgSys_agCkMFB5MBSatOfs_C + IgSys_agCkMFB5Ref;

    /* Sum: '<S29>/Sum3' incorporates:
     *  Constant: '<S29>/IgSys_agCkMFB5MBSatOfs_C'
     */
    localDivide_nw = IgSys_agCkMFB5Ref - IgSys_agCkMFB5MBSatOfs_C;

    /* Switch: '<S185>/Switch' incorporates:
     *  RelationalOperator: '<S185>/UpperRelop'
     */
    if (!(IgSys_agCkMFB5Calc < localDivide_nw)) {
      localDivide_nw = IgSys_agCkMFB5Calc;
    }

    /* Switch: '<S185>/Switch2' incorporates:
     *  RelationalOperator: '<S185>/LowerRelop1'
     */
    if (IgSys_agCkMFB5Calc > localSwitch1_n) {
      IgSys_agCkMFB5CalcSat = localSwitch1_n;
    } else {
      IgSys_agCkMFB5CalcSat = localDivide_nw;
    }

    /* end of Outputs for SubSystem: '<S15>/F11_Selection_Angles_Fin' */

    /* Outputs for atomic SubSystem: '<S15>/F12_Correction_de_l_AAO' */

    /* Lookup2D: '<S186>/Look-Up Table (2-D)'
     * About '<S186>/Look-Up Table (2-D)':
     * Input0  Data Type:  Floating Point Float32
     * Input1  Data Type:  Floating Point Float32
     * Output0 Data Type:  Floating Point Float32
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real32_T_real32_T_real32_T( &(localLookUpTable2D_g),
      (&(IgSys_agIgOptmOfs_M[0])), localDataTypeConversion7,
      (&(IgSys_tCoMes_AgIgOptmOfsX_A[0])), 15U, localDataTypeConversion2_d,
      (&(IgSys_rAirLd_AgIgOptmOfsY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S186>/Data Type Duplicate2'
     *
     * Regarding '<S186>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Sum: '<S30>/Sum3' incorporates:
     *  Lookup2D: '<S186>/Look-Up Table (2-D)'
     *  SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgWup_irvOutport2'
     *  Sum: '<S30>/Sum1'
     */
    IgSys_agIgOptmWiCor = (IgSys_agIgOptmCalcSat + localLookUpTable2D_g) +
      Rte_IrvRead_RE_AdvOptmT_003_DRE_IgSys_agIgWup_irv();

    /* end of Outputs for SubSystem: '<S15>/F12_Correction_de_l_AAO' */

    /* Outputs for atomic SubSystem: '<S15>/F13_Correctifs_externes' */

    /* Selector: '<S189>/Selector' incorporates:
     *  Constant: '<S189>/Constant'
     *  Constant: '<S189>/Constant1'
     *  Constant: '<S31>/Cste_1'
     *  DataTypeConversion: '<S8>/Data Type Conversion17'
     *  MinMax: '<S189>/MinMax'
     *  Sum: '<S189>/Add'
     */
    localDivide_nw = ((Float32)localTmpSignalConversionAtIgS_f[0]) * 0.0078125F;

    /* Switch: '<S195>/Switch2' incorporates:
     *  Constant: '<S187>/Constant'
     *  RelationalOperator: '<S195>/LowerRelop1'
     */
    if (localDivide_nw > 1.0F) {
      localDivide_nw = 1.0F;
    }

    /* Sum: '<S31>/Sum3' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion15'
     */
    localSwitch1_n = ((((Float32)localTmpSignalConversionAtIgS_g) * 0.375F) -
                      36.0F) + IgSys_agIgOptmWiCor;

    /* Switch: '<S31>/Switch1' incorporates:
     *  Constant: '<S31>/IgSys_bFlexOptmOfs_C'
     *  Sum: '<S31>/Sum'
     */
    if (!IgSys_bFlexOptmOfs_C) {
      localDataTypeConversion16 += IgSys_agIgOptmWiCor;
    }

    /* Sum: '<S187>/Sum2' incorporates:
     *  Product: '<S187>/Divide'
     *  Sum: '<S187>/Sum3'
     */
    IgSys_agIgOptmWiFlexCor_MP = ((localDataTypeConversion16 - localSwitch1_n) *
      localDivide_nw) + localSwitch1_n;

    /* Selector: '<S190>/Selector' incorporates:
     *  Constant: '<S190>/Constant'
     *  Constant: '<S190>/Constant1'
     *  Constant: '<S31>/Cste_1_1'
     *  DataTypeConversion: '<S8>/Data Type Conversion18'
     *  MinMax: '<S190>/MinMax'
     *  Sum: '<S190>/Add'
     */
    localDataTypeConversion16 = ((Float32)localTmpSignalConversionAtIg_d1[0]) *
      0.0078125F;

    /* Switch: '<S199>/Switch2' incorporates:
     *  Constant: '<S188>/Constant'
     *  RelationalOperator: '<S199>/LowerRelop1'
     */
    if (localDataTypeConversion16 > 1.0F) {
      localDataTypeConversion16 = 1.0F;
    }

    /* Switch: '<S31>/Switch3' incorporates:
     *  Constant: '<S31>/IgSys_bGasOptmOfs_C'
     *  Sum: '<S31>/Sum1'
     */
    if (IgSys_bGasOptmOfs_C) {
      localSwitch1_n = localDataTypeConversion19;
    } else {
      localSwitch1_n = localDataTypeConversion19 + IgSys_agIgOptmWiFlexCor_MP;
    }

    /* DataTypeConversion: '<S191>/OutDTConv' incorporates:
     *  Constant: '<S191>/offset'
     *  Constant: '<S191>/offset1'
     *  Constant: '<S191>/one_on_slope'
     *  Product: '<S188>/Divide'
     *  Product: '<S191>/Product4'
     *  Sum: '<S188>/Sum2'
     *  Sum: '<S188>/Sum3'
     *  Sum: '<S191>/Add1'
     *  Sum: '<S191>/Add2'
     */
    localDataTypeConversion10 = (((((localSwitch1_n - IgSys_agIgOptmWiFlexCor_MP)
      * localDataTypeConversion16) + IgSys_agIgOptmWiFlexCor_MP) - -36.0F) *
      2.666666746E+000F) + 0.5F;
    if (localDataTypeConversion10 < 256.0F) {
      if (localDataTypeConversion10 >= 0.0F) {
        localTmpSignalConversionAtIgS_g = (UInt8)localDataTypeConversion10;
      } else {
        localTmpSignalConversionAtIgS_g = 0U;
      }
    } else {
      localTmpSignalConversionAtIgS_g = MAX_uint8_T;
    }

    /* end of Outputs for SubSystem: '<S15>/F13_Correctifs_externes' */

    /* Outputs for atomic SubSystem: '<S15>/F14_Calcul_Avance_de_Base' */

    /* SignalConversion: '<S32>/Signal Conversion1' */
    AdvOptmT_B.Merge2 = localTmpSignalConversionAtIgS_g;

    /* end of Outputs for SubSystem: '<S15>/F14_Calcul_Avance_de_Base' */

    /* SignalConversion: '<S15>/Signal Conversion' */
    AdvOptmT_B.Merge_i = localTmpSignalConversionAtIgS_g;

    /* Update for atomic SubSystem: '<S15>/F08_Selection_Angles_Depart' */

    /* Update for UnitDelay: '<S57>/Unit Delay' */
    AdvOptmT_DWork.UnitDelay_DSTATE = IgSys_agIgOptmCalcSat;

    /* Update for UnitDelay: '<S58>/Unit Delay' */
    AdvOptmT_DWork.UnitDelay_DSTATE_g = IgSys_agCkMFB5CalcSat;

    /* Update for UnitDelay: '<S56>/Unit Delay' incorporates:
     *  Constant: '<S26>/Cste_1'
     */
    AdvOptmT_DWork.UnitDelay_DSTATE_n = TRUE;

    /* end of Update for SubSystem: '<S15>/F08_Selection_Angles_Depart' */
  }

  /* end of Outputs for SubSystem: '<S8>/F0_02_Calcul_avance_optimale' */

  /* Logic: '<S8>/Logical Operator' */
  localLowerRelop1 = !IgSys_bAcvAdvOptm;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgOptm_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgOptm_INPUT'
   */
  Rte_Read_R_IgSys_agIgOptm_IgSys_agIgOptm(&localTmpSignalConversionAtIgS_a);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgBas_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgBas_INPUT'
   */
  Rte_Read_R_IgSys_agIgBas_IgSys_agIgBas(&localTmpSignalConversionAtIgS_j);

  /* Outputs for enable SubSystem: '<S8>/NOT' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (localLowerRelop1) {
    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S200>/autosar_testpoint1' */
    /* S-Function Block: <S200>/autosar_testpoint1 */
    IgSys_bAcvClsLoop_IRV_MP = localTmpSignalConversionAtIgS_n;

    /* SignalConversion: '<S16>/Signal Conversion2' */
    AdvOptmT_B.IgSys_bAcvClsLoop_irv_e = localTmpSignalConversionAtIgS_n;

    /* SignalConversion: '<S16>/Signal Conversion1' */
    AdvOptmT_B.Merge2 = localTmpSignalConversionAtIgS_j;

    /* SignalConversion: '<S16>/Signal Conversion' */
    AdvOptmT_B.Merge_i = localTmpSignalConversionAtIgS_a;
  }

  /* end of Outputs for SubSystem: '<S8>/NOT' */

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Byp_Fonction_SC'
   *  Constant: '<S17>/Int_BypC'
   */
  if (ADVOPTMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_g = IgSys_agIgBas_B;
  } else {
    localTmpSignalConversionAtIgS_g = AdvOptmT_B.Merge2;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgBasInport2' */
  Rte_Write_P_IgSys_agIgBas_IgSys_agIgBas(localTmpSignalConversionAtIgS_g);

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Byp_Fonction_SC'
   *  Constant: '<S18>/Int_BypC'
   */
  if (ADVOPTMT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIgS_g = IgSys_agIgOptm_B;
  } else {
    localTmpSignalConversionAtIgS_g = AdvOptmT_B.Merge_i;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_agIgOptmInport2' */
  Rte_Write_P_IgSys_agIgOptm_IgSys_agIgOptm(localTmpSignalConversionAtIgS_g);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtIgSys_bAcvClsLoop_irvInport2' */
  Rte_IrvWrite_RE_AdvOptmT_003_DRE_IgSys_bAcvClsLoop_irv
    (AdvOptmT_B.IgSys_bAcvClsLoop_irv_e);
}

/* Model initialize function */
void EV_AdvOptm_AUTOSAR_Init(void)
{
  /* Registration code */

  /* block I/O */
  {
    AdvOptmT_B.Merge_i = 96U;
    AdvOptmT_B.Merge2 = 96U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  RE_AdvOptmT_001_MSE_Start();
  RE_AdvOptmT_004_MSE_Start();
  RE_AdvOptmT_002_DRE_Start();
  RE_AdvOptmT_003_DRE_Start();
}

#define AdvOptmT_STOP_SEC_CODE
#include "AdvOptmT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
