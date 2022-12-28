/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : CatPasDiagT                                             */
/* !Description     : CatPasDiagT Software Component                          */
/*                                                                            */
/* !Module          : CatPasDiagT                                             */
/* !Description     : CatPasDiagT Software Component                          */
/*                                                                            */
/* !File            : CatPasDiagT.c                                           */
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
/* !Reference       : PTS_DOC_5060363 / 04                                    */
/* !Reference       : PTS_DOC_5060291 / 05                                    */
/* !OtherRefs       : VEMS V02 ECU#067700                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : CatPasDiagT_AUTOSAR.mdl                               */
/*   Root subsystem   : /CatPasDiagT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/SWC_PSA/3.1/CATMON/CATPASDIAGT/CatP$*/
/* $Revision::   1.12                                                        $*/
/* $Author::   etsasson                               $$Date::   09 Dec 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "CatPasDiagT.h"
#include "CatPasDiagT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S58>/2_Diagnostic' */
#define IN_CAT_CALC                    (1U)
#define IN_CAT_INIT                    (2U)
#define IN_CAT_SOMME                   (3U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define CatPasDiagT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "CatPasDiagT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_CatPasDiagT CatPasDiagT_B;

/* Block states (auto storage) */
D_Work_CatPasDiagT CatPasDiagT_DWork;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "CatPasDiagT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define CATPASDIAGT_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define CATPASDIAGT_VEMSRTLIBT_MINOR_VERSION_REQ 15
#define CATPASDIAGT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define CATPASDIAGT_VEMSRTLIBT_VERSION_REQ (CATPASDIAGT_VEMSRTLIBT_PATCH_VERSION_REQ + CATPASDIAGT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + CATPASDIAGT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if CATPASDIAGT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define CatPasDiagT_START_SEC_CODE
#include "CatPasDiagT_MemMap.h"

/* Start for exported function: RE_CatMon_EveRst_CatPasDiag */
void RE_CatMon_EveRst_CatPasDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/Initialisation_00'
   */
}

/* Output and update for exported function: RE_CatMon_EveRst_CatPasDiag */
void RE_CatMon_EveRst_CatPasDiag(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/Initialisation_00'
   */

  /* user code (Output function Body for TID2) */
  RE_CatPasDiag_Init();

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write9' incorporates:
   *  Constant: '<S5>/Cat_stable_conditions_1_delay'
   */

  /* S-Function Block: <S5>/autosar_irv_write9 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_stable_cond_1_tempo_irv
    (Cat_stable_conditions_1_delay);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S265>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/Cat_stable_conditions_1_delay'
   */

  /* S-Function Block: <S265>/autosar_testpoint1 */
  Cat_stable_conditions_1_tempo = Cat_stable_conditions_1_delay;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write10' incorporates:
   *  Constant: '<S5>/Cat_stable_conditions_2_delay'
   */

  /* S-Function Block: <S5>/autosar_irv_write10 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_stable_cond_2_tempo_irv
    (Cat_stable_conditions_2_delay);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S266>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/Cat_stable_conditions_2_delay'
   */

  /* S-Function Block: <S266>/autosar_testpoint1 */
  Cat_stable_conditions_2_tempo = Cat_stable_conditions_2_delay;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write2' incorporates:
   *  Constant: '<S5>/ConstVal'
   */

  /* S-Function Block: <S5>/autosar_irv_write2 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_etat_defectueux_irv(FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S269>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal'
   */

  /* S-Function Block: <S269>/autosar_testpoint1 */
  Cat_etat_defectueux_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write7' incorporates:
   *  Constant: '<S5>/ConstVal_1'
   */

  /* S-Function Block: <S5>/autosar_irv_write7 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_degradation_count_irv(0);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S275>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_1'
   */

  /* S-Function Block: <S275>/autosar_testpoint1 */
  Cat_degradation_count_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write6' incorporates:
   *  Constant: '<S5>/ConstVal_10'
   */

  /* S-Function Block: <S5>/autosar_irv_write6 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_degradation_count_idle_irv(0);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S273>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_10'
   */

  /* S-Function Block: <S273>/autosar_testpoint1 */
  Cat_degradation_count_idle = 0;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write' incorporates:
   *  Constant: '<S5>/ConstVal_2'
   */

  /* S-Function Block: <S5>/autosar_irv_write */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_diagnostic_effectue_irv(FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S274>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_2'
   */

  /* S-Function Block: <S274>/autosar_testpoint1 */
  Cat_diagnostic_effectue_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write8' incorporates:
   *  Constant: '<S5>/ConstVal_3'
   */

  /* S-Function Block: <S5>/autosar_irv_write8 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_diagnostic_autorise_irv(FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S276>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_3'
   */

  /* S-Function Block: <S276>/autosar_testpoint1 */
  Cat_diagnostic_autorise_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write1' incorporates:
   *  Constant: '<S5>/ConstVal_4'
   */

  /* S-Function Block: <S5>/autosar_irv_write1 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_diagnostic_cycle_end_irv(FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S264>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_4'
   */

  /* S-Function Block: <S264>/autosar_testpoint1 */
  Cat_diagnostic_cycle_end_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write5' incorporates:
   *  Constant: '<S5>/ConstVal_5'
   */

  /* S-Function Block: <S5>/autosar_irv_write5 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_etat_defectueux_idle_irv(FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S272>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_5'
   */

  /* S-Function Block: <S272>/autosar_testpoint1 */
  Cat_etat_defectueux_idle_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write3' incorporates:
   *  Constant: '<S5>/ConstVal_6'
   */

  /* S-Function Block: <S5>/autosar_irv_write3 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_diagnostic_effectue_idle_irv
    (FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S270>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_6'
   */

  /* S-Function Block: <S270>/autosar_testpoint1 */
  Cat_diagnostic_effectue_idle = FALSE;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write4' incorporates:
   *  Constant: '<S5>/ConstVal_7'
   */

  /* S-Function Block: <S5>/autosar_irv_write4 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_diag_cycle_end_idle_irv(FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S271>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_7'
   */

  /* S-Function Block: <S271>/autosar_testpoint1 */
  Cat_diag_cycle_end_idle_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write12' incorporates:
   *  Constant: '<S5>/ConstVal_8'
   */

  /* S-Function Block: <S5>/autosar_irv_write12 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_Cat_calcul_count_irv(((UInt8)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S268>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/ConstVal_8'
   */

  /* S-Function Block: <S268>/autosar_testpoint1 */
  Cat_calcul_count_IRV_MP = ((UInt8)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S5>/autosar_irv_write11' incorporates:
   *  Constant: '<S5>/OxC_tiTmrPasIntr_C'
   */

  /* S-Function Block: <S5>/autosar_irv_write11 */
  Rte_IrvWrite_RE_CatMon_EveRst_CatPasDiag_OxC_tiTmrPasIntr_irv
    (OxC_tiTmrPasIntr_C);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S267>/autosar_testpoint1' incorporates:
   *  Constant: '<S5>/OxC_tiTmrPasIntr_C'
   */

  /* S-Function Block: <S267>/autosar_testpoint1 */
  OxC_tiTmrPasIntr_IRV_MP = OxC_tiTmrPasIntr_C;
}

/*
 * Output and update for action system:
 *    '<S245>/if_s1'
 *    '<S244>/if_s2'
 */
void CatPasDiagT_if_s1(void)
{
  /* S-Function (sfun_autosar_clientop): '<S247>/AutosarServer' incorporates:
   *  Constant: '<S247>/Constant3'
   */
  Rte_Call_R_CatMon_ORng_Cat_SetEventStatus(DEM_EVENT_STATUS_INIT);
}

/*
 * Output and update for action system:
 *    '<S253>/if_s1'
 *    '<S252>/if_s2'
 */
void CatPasDiagT_if_s1_j(void)
{
  /* S-Function (sfun_autosar_clientop): '<S255>/AutosarServer' incorporates:
   *  Constant: '<S255>/Constant3'
   */
  Rte_Call_R_CatMon_ORng_CatApv_SetEventStatus(DEM_EVENT_STATUS_INIT);
}

/* Initial conditions for exported function: RE_CatMon_SdlMid_CatPasDiag */
void RE_CatMon_SdlMid_CatPasDiag_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/CatMon_SdlMid_CatPasDiag_sub'
   */

  /* InitializeConditions for Embedded MATLAB: '<S4>/Embedded MATLAB Function' incorporates:
   *  InitializeConditions for SubSystem: '<S4>/001_TmrPasIntr'
   *  InitializeConditions for SubSystem: '<S4>/01_Activation'
   *  InitializeConditions for SubSystem: '<S4>/02_Conditions_stabilite_diag_passif'
   *  InitializeConditions for SubSystem: '<S4>/03_Controle'
   *  InitializeConditions for SubSystem: '<S4>/04_Filtre'
   *  InitializeConditions for SubSystem: '<S4>/05_Calculs'
   *  InitializeConditions for SubSystem: '<S4>/06_mode06'
   *  InitializeConditions for SubSystem: '<S4>/07_Reinit_degrad_count'
   *  InitializeConditions for SubSystem: '<S4>/08_Reinit_degrad_count_idle'
   *  InitializeConditions for SubSystem: '<S4>/09_Gestion_fast_tracking'
   *  InitializeConditions for SubSystem: '<S4>/10_SeqORngCat'
   *  InitializeConditions for SubSystem: '<S4>/12_Re_initialisation'
   *  InitializeConditions for SubSystem: '<S4>/13_Fco_Mode06_Euro6'
   *  InitializeConditions for SubSystem: '<S4>/14_GDU '
   *  InitializeConditions for SubSystem: '<S4>/15_GDU'
   */

  /* InitializeConditions for atomic SubSystem: '<S8>/01_Conditions_stabilite_passif' */

  /* InitializeConditions for UnitDelay: '<S55>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_il = 1600U;

  /* end of InitializeConditions for SubSystem: '<S8>/01_Conditions_stabilite_passif' */

  /* InitializeConditions for atomic SubSystem: '<S12>/01_calc_intrusif_mode06' */

  /* InitializeConditions for UnitDelay: '<S200>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_h = 256U;

  /* end of InitializeConditions for SubSystem: '<S12>/01_calc_intrusif_mode06' */
}

/* Start for exported function: RE_CatMon_SdlMid_CatPasDiag */
void RE_CatMon_SdlMid_CatPasDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/CatMon_SdlMid_CatPasDiag_sub'
   */

  /* Start for Embedded MATLAB: '<S4>/Embedded MATLAB Function' incorporates:
   *  Start for SubSystem: '<S4>/001_TmrPasIntr'
   *  Start for SubSystem: '<S4>/01_Activation'
   *  Start for SubSystem: '<S4>/02_Conditions_stabilite_diag_passif'
   *  Start for SubSystem: '<S4>/03_Controle'
   *  Start for SubSystem: '<S4>/04_Filtre'
   *  Start for SubSystem: '<S4>/05_Calculs'
   *  Start for SubSystem: '<S4>/06_mode06'
   *  Start for SubSystem: '<S4>/07_Reinit_degrad_count'
   *  Start for SubSystem: '<S4>/08_Reinit_degrad_count_idle'
   *  Start for SubSystem: '<S4>/09_Gestion_fast_tracking'
   *  Start for SubSystem: '<S4>/10_SeqORngCat'
   *  Start for SubSystem: '<S4>/12_Re_initialisation'
   *  Start for SubSystem: '<S4>/13_Fco_Mode06_Euro6'
   *  Start for SubSystem: '<S4>/14_GDU '
   *  Start for SubSystem: '<S4>/15_GDU'
   */

  /* Start for enable SubSystem: '<S11>/01_Puissance_degradation' */

  /* Start for atomic SubSystem: '<S139>/01_Puissance' */

  /* Start for DataStoreMemory: '<S140>/Cat_temperature_moy_1' */
  CatPasDiagT_DWork.Cat_temperature_moy = 1600U;

  /* end of Start for SubSystem: '<S139>/01_Puissance' */

  /* end of Start for SubSystem: '<S11>/01_Puissance_degradation' */
}

/* Output and update for exported function: RE_CatMon_SdlMid_CatPasDiag */
void RE_CatMon_SdlMid_CatPasDiag(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion_i;
  UInt16 localSwitch4_f[3];
  SInt16 localSwitch2_f;
  SInt16 localSwitch2_l;
  SInt16 localOutDTConv_j;
  SInt16 localOutDTConv_m;
  UInt8 localLookUpTable2D;
  UInt8 localLookUpTable2D_c;
  UInt8 localSum_n;
  UInt8 localLookUpTable2D_g;
  UInt8 localLookUpTable2D_k;
  UInt8 localSwitch_f;
  Boolean localautosar_irv_read3_k;
  Boolean localautosar_irv_read;
  Boolean localautosar_irv_read_n;
  Boolean localLogicalOperator1_h;
  Boolean localLogicalOperator3_p;
  Boolean localautosar_irv_read_p;
  Boolean localautosar_irv_read1_an;
  Boolean localautosar_irv_read2_h;
  Boolean localautosar_irv_read3_f;
  Boolean localMultiportSwitch[4];
  Boolean localLogicalOperator6_e;
  Boolean localLogicalOperator7_g;
  Boolean localLogic[2];
  Boolean localAutosarServer;
  Boolean localLogicalOperator1_o;
  UInt8 localSwitch1_e;
  UInt8 localSwitch5_d;
  UInt8 localSwitch1_fr;
  UInt8 localLookUpTable2D_d;
  UInt8 localLookUpTable2D_a;
  UInt8 localLookUpTable2D_l;
  UInt8 localLookUpTable2D_f;
  Boolean localSwitch2_fa;
  Boolean localSwitch3_jm;
  Boolean localLogicalOperator5_lz;
  Boolean localLogicalOperator3_j;
  Boolean localLogicalOperator4_j;
  Boolean localRelationalOperator3_m;
  Boolean localSwitch1_gu;
  Boolean localRelationalOperator3_cq;
  Boolean localSwitch1_h;
  Boolean localSwitch2_ln;
  Float32 localDataTypeConversion_f;
  Float32 localUnitDelay_ai;
  Float32 localUnitDelay_jy;
  Float32 localUnitDelay_c;
  Float32 localUnitDelay_c4;
  Float32 localSum2_m;
  Float32 localMerge_e;
  Float32 localMerge1;
  UInt8 localSwitch1_f;
  SInt32 localSwitch4;
  UInt32 localSwitch2;
  UInt8 localSwitch6_g5;
  Boolean localNot;
  Boolean localNot_k;
  UInt16 locallocalSwitch1_a_idx;
  UInt16 locallocalSwitch_a_idx;
  UInt16 locallocalSwitch_a_idx_0;
  UInt16 locallocalSwitch_a_idx_1;
  UInt16 locallocalSwitch3_j_idx;
  UInt16 locallocalSwitch3_j_idx_0;
  UInt16 locallocalSwitch3_j_idx_1;
  UInt32 locallocalSum;
  UInt32 locallocalSwitch;
  UInt16 locallocalSwitch_0;
  UInt16 locallocalAdd2_i;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/CatMon_SdlMid_CatPasDiag_sub'
   */

  /* SignalConversion: '<S4>/TmpSignal ConversionAtRegime_moteurOutport2' incorporates:
   *  Inport: '<Root>/Regime_moteur'
   */
  Rte_Read_R_Regime_moteur_Regime_moteur
    (&CatPasDiagT_B.TmpSignalConversionAtRegime_mot);

  /* S-Function (sfun_autosar_clientop): '<S22>/AutosarServer' */
  Rte_Call_R_FRM_bInhCatMonFacFrz_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S22>/Not' */
  localNot = !localAutosarServer;

  /* S-Function (sfun_autosar_clientop): '<S23>/AutosarServer' */
  Rte_Call_R_FRM_bInhPasCatMon_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S23>/Not' */
  localNot_k = !localAutosarServer;

  /* SignalConversion: '<S4>/TmpSignal ConversionAtExt_stSysGasOutport2' incorporates:
   *  Inport: '<Root>/Ext_stSysGas'
   */
  Rte_Read_R_Ext_stSysGas_Ext_stSysGas
    (&CatPasDiagT_B.TmpSignalConversionAtExt_stSysG);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_bEndDiagStORng_UsHt_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_bEndDiagStORng_UsHt_swc'
   */
  Rte_Read_R_GDU_bEndDiagStORng_UsHt_swc_GDU_bEndDiagStORng_UsHt_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_bEndDi);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_bEndDiagStORng_DsHt_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_bEndDiagStORng_DsHt_swc'
   */
  Rte_Read_R_GDU_bEndDiagStORng_DsHt_swc_GDU_bEndDiagStORng_DsHt_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_k);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_bEndDiagStORng_OxyApvPerdOutport2' incorporates:
   *  Inport: '<Root>/GDU_bEndDiagStORng_OxyApvPerd'
   */
  Rte_Read_R_GDU_bEndDiagStORng_OxyApvPerd_GDU_bEndDiagStORng_OxyApvPerd
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_i);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_bEndDiagStORng_OxySensPrdOutport2' incorporates:
   *  Inport: '<Root>/GDU_bEndDiagStORng_OxySensPrd'
   */
  Rte_Read_R_GDU_bEndDiagStORng_OxySensPrd_GDU_bEndDiagStORng_OxySensPrd
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_bEn_kt);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_bEndDiagStORng_DsPlausFcoOutport2' incorporates:
   *  Inport: '<Root>/GDU_bEndDiagStORng_DsPlausFco'
   */
  Rte_Read_R_GDU_bEndDiagStORng_DsPlausFco_GDU_bEndDiagStORng_DsPlausFco
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_f);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_bEndDiagStORng_UsPlausFcoOutport2' incorporates:
   *  Inport: '<Root>/GDU_bEndDiagStORng_UsPlausFco'
   */
  Rte_Read_R_GDU_bEndDiagStORng_UsPlausFco_GDU_bEndDiagStORng_UsPlausFco
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_l);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_bEndDiagStORngLf_Afr_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_bEndDiagStORngLf_Afr_swc'
   */
  Rte_Read_R_GDU_bEndDiagStORngLf_Afr_swc_GDU_bEndDiagStORngLf_Afr_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_a);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_bEndDiagStORngLf_Afl_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_bEndDiagStORngLf_Afl_swc'
   */
  Rte_Read_R_GDU_bEndDiagStORngLf_Afl_swc_GDU_bEndDiagStORngLf_Afl_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_bEn_iq);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_stDgoORng_UsHt_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_stDgoORng_UsHt_swc'
   */
  Rte_Read_R_GDU_stDgoORng_UsHt_swc_GDU_stDgoORng_UsHt_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_stDgoO);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_stDgoORng_DsHt_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_stDgoORng_DsHt_swc'
   */
  Rte_Read_R_GDU_stDgoORng_DsHt_swc_GDU_stDgoORng_DsHt_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_l);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_stDgoORng_OxyApvPrd_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_stDgoORng_OxyApvPrd_swc'
   */
  Rte_Read_R_GDU_stDgoORng_OxyApvPrd_swc_GDU_stDgoORng_OxyApvPrd_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_d);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_stDgoORng_OxySenPrd_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_stDgoORng_OxySenPrd_swc'
   */
  Rte_Read_R_GDU_stDgoORng_OxySenPrd_swc_GDU_stDgoORng_OxySenPrd_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_o);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_stDgoORng_DsPlsFco_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_stDgoORng_DsPlsFco_swc'
   */
  Rte_Read_R_GDU_stDgoORng_DsPlsFco_swc_GDU_stDgoORng_DsPlsFco_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_j);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_stDgoORng_UsPlsFco_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_stDgoORng_UsPlsFco_swc'
   */
  Rte_Read_R_GDU_stDgoORng_UsPlsFco_swc_GDU_stDgoORng_UsPlsFco_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_stD_or);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_stDgoORngLf_Afr_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_stDgoORngLf_Afr_swc'
   */
  Rte_Read_R_GDU_stDgoORngLf_Afr_swc_GDU_stDgoORngLf_Afr_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_m);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGDU_stDgoORngLf_Afl_swcOutport2' incorporates:
   *  Inport: '<Root>/GDU_stDgoORngLf_Afl_swc'
   */
  Rte_Read_R_GDU_stDgoORngLf_Afl_swc_GDU_stDgoORngLf_Afl_swc
    (&CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_p);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCatMon_bDgoORngIntrOutport2' incorporates:
   *  Inport: '<Root>/CatMon_bDgoORngIntr'
   */
  Rte_Read_R_CatMon_bDgoORngIntr_CatMon_bDgoORngIntr
    (&CatPasDiagT_B.TmpSignalConversionAtCatMon_bDg);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCatMon_bMonWaitORngIntrOutport2' incorporates:
   *  Inport: '<Root>/CatMon_bMonWaitORngIntr'
   */
  Rte_Read_R_CatMon_bMonWaitORngIntr_CatMon_bMonWaitORngIntr
    (&CatPasDiagT_B.TmpSignalConversionAtCatMon_bMo);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCatMon_bMonRunORngIntrOutport2' incorporates:
   *  Inport: '<Root>/CatMon_bMonRunORngIntr'
   */
  Rte_Read_R_CatMon_bMonRunORngIntr_CatMon_bMonRunORngIntr
    (&CatPasDiagT_B.TmpSignalConversionAtCatMon_b_c);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtOxC_bMonEnaORngIntrOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonEnaORngIntr'
   */
  Rte_Read_R_OxC_bMonEnaORngIntr_OxC_bMonEnaORngIntr
    (&CatPasDiagT_B.TmpSignalConversionAtOxC_bMonEn);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtOxC_bMonEndORngIntrOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonEndORngIntr'
   */
  Rte_Read_R_OxC_bMonEndORngIntr_OxC_bMonEndORngIntr
    (&CatPasDiagT_B.TmpSignalConversionAtOxC_bMon_d);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtOxC_mO2StgMvEstimOutport2' incorporates:
   *  Inport: '<Root>/OxC_mO2StgMvEstim'
   */
  Rte_Read_R_OxC_mO2StgMvEstim_OxC_mO2StgMvEstim
    (&CatPasDiagT_B.TmpSignalConversionAtOxC_mO2Stg);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtEngM_mfTotExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfTotExCor'
   */
  Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor
    (&CatPasDiagT_B.TmpSignalConversionAtEngM_mfTot);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCat_temperatureOutport2' incorporates:
   *  Inport: '<Root>/Cat_temperature'
   */
  Rte_Read_R_Cat_temperature_Cat_temperature
    (&CatPasDiagT_B.TmpSignalConversionAtCat_temper);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCat_seuil_obd_flexOutport2' incorporates:
   *  Inport: '<Root>/Cat_seuil_obd_flex'
   */
  Rte_Read_R_Cat_seuil_obd_flex_Cat_seuil_obd_flex
    (&CatPasDiagT_B.TmpSignalConversionAtCat_seui_d);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCat_seuil_obd_pond_flexOutport2' incorporates:
   *  Inport: '<Root>/Cat_seuil_obd_pond_flex'
   */
  Rte_Read_R_Cat_seuil_obd_pond_flex_Cat_seuil_obd_pond_flex
    (&CatPasDiagT_B.TmpSignalConversionAtCat_seuil_);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCf_bInhFlexOutport2' incorporates:
   *  Inport: '<Root>/Cf_bInhFlex'
   */
  Rte_Read_R_Cf_bInhFlex_Cf_bInhFlex
    (&CatPasDiagT_B.TmpSignalConversionAtCf_bInhFle);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtTension_sonde_avalOutport2' incorporates:
   *  Inport: '<Root>/Tension_sonde_aval'
   */
  Rte_Read_R_Tension_sonde_aval_Tension_sonde_aval
    (&CatPasDiagT_B.TmpSignalConversionAtTension_so);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCat_light_off_achievedOutport2' incorporates:
   *  Inport: '<Root>/Cat_light_off_achieved'
   */
  Rte_Read_R_Cat_light_off_achieved_Cat_light_off_achieved
    (&CatPasDiagT_B.TmpSignalConversionAtCat_light_);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtRegime_moteur_32Outport2' incorporates:
   *  Inport: '<Root>/Regime_moteur_32'
   */
  Rte_Read_R_Regime_moteur_32_Regime_moteur_32
    (&CatPasDiagT_B.TmpSignalConversionAtRegime_m_j);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtTemperature_eauOutport2' incorporates:
   *  Inport: '<Root>/Temperature_eau'
   */
  Rte_Read_R_Temperature_eau_Temperature_eau
    (&CatPasDiagT_B.TmpSignalConversionAtTemperatur);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtTemperature_airOutport2' incorporates:
   *  Inport: '<Root>/Temperature_air'
   */
  Rte_Read_R_Temperature_air_Temperature_air
    (&CatPasDiagT_B.TmpSignalConversionAtTemperat_g);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtLshd_down_strm_lbda_sens_hotOutport2' incorporates:
   *  Inport: '<Root>/Lshd_down_strm_lbda_sens_hot'
   */
  Rte_Read_R_Lshd_down_strm_lbda_sens_hot_Lshd_down_strm_lbda_sens_hot
    (&CatPasDiagT_B.TmpSignalConversionAtLshd_down_);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtLshd_up_strm_lbda_sens_hotOutport2' incorporates:
   *  Inport: '<Root>/Lshd_up_strm_lbda_sens_hot'
   */
  Rte_Read_R_Lshd_up_strm_lbda_sens_hot_Lshd_up_strm_lbda_sens_hot
    (&CatPasDiagT_B.TmpSignalConversionAtLshd_up_st);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtFlev_low_fuel_levelOutport2' incorporates:
   *  Inport: '<Root>/Flev_low_fuel_level'
   */
  Rte_Read_R_Flev_low_fuel_level_Flev_low_fuel_level
    (&CatPasDiagT_B.TmpSignalConversionAtFlev_low_f);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtEngine_loadOutport2' incorporates:
   *  Inport: '<Root>/Engine_load'
   */
  Rte_Read_R_Engine_load_Engine_load
    (&CatPasDiagT_B.TmpSignalConversionAtEngine_loa);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtMonitor_fdbk_cond_stat_swcOutport2' incorporates:
   *  Inport: '<Root>/Monitor_fdbk_cond_stat_swc'
   */
  Rte_Read_R_Monitor_fdbk_cond_stat_swc_Monitor_fdbk_cond_stat_swc
    (&CatPasDiagT_B.TmpSignalConversionAtMonitor_fd);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtEngine_running_state_swcOutport2' incorporates:
   *  Inport: '<Root>/Engine_running_state_swc'
   */
  Rte_Read_R_Engine_running_state_swc_Engine_running_state_swc
    (&CatPasDiagT_B.TmpSignalConversionAtEngine_run);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGear_engagedOutport2' incorporates:
   *  Inport: '<Root>/Gear_engaged'
   */
  Rte_Read_R_Gear_engaged_Gear_engaged
    (&CatPasDiagT_B.TmpSignalConversionAtGear_engag);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtFlev_low_gas_levelOutport2' incorporates:
   *  Inport: '<Root>/Flev_low_gas_level'
   */
  Rte_Read_R_Flev_low_gas_level_Flev_low_gas_level
    (&CatPasDiagT_B.TmpSignalConversionAtFlev_low_g);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtExt_bPresGazOutport2' incorporates:
   *  Inport: '<Root>/Ext_bPresGaz'
   */
  Rte_Read_R_Ext_bPresGaz_Ext_bPresGaz
    (&CatPasDiagT_B.TmpSignalConversionAtExt_bPresG);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtVlvAct_bInhDiagPresScavOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_bInhDiagPresScav'
   */
  Rte_Read_R_VlvAct_bInhDiagPresScav_VlvAct_bInhDiagPresScav
    (&CatPasDiagT_B.TmpSignalConversionAtVlvAct_bIn);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtEngSt_bOscDetStabOutport2' incorporates:
   *  Inport: '<Root>/EngSt_bOscDetStab'
   */
  Rte_Read_R_EngSt_bOscDetStab_EngSt_bOscDetStab
    (&CatPasDiagT_B.TmpSignalConversionAtEngSt_bOsc);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtAuto_injectionOutport2' incorporates:
   *  Inport: '<Root>/Auto_injection'
   */
  Rte_Read_R_Auto_injection_Auto_injection
    (&CatPasDiagT_B.TmpSignalConversionAtAuto_injec);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtFlex_bInhDiagOBDAlcEstOutport2' incorporates:
   *  Inport: '<Root>/Flex_bInhDiagOBDAlcEst'
   */
  Rte_Read_R_Flex_bInhDiagOBDAlcEst_Flex_bInhDiagOBDAlcEst
    (&CatPasDiagT_B.TmpSignalConversionAtFlex_bInhD);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtFlex_bInhDiagOBDAlcRateOutport2' incorporates:
   *  Inport: '<Root>/Flex_bInhDiagOBDAlcRate'
   */
  Rte_Read_R_Flex_bInhDiagOBDAlcRate_Flex_bInhDiagOBDAlcRate
    (&CatPasDiagT_B.TmpSignalConversionAtFlex_bIn_a);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtFlex_bInhDiagOBDBlbyOutport2' incorporates:
   *  Inport: '<Root>/Flex_bInhDiagOBDBlby'
   */
  Rte_Read_R_Flex_bInhDiagOBDBlby_Flex_bInhDiagOBDBlby
    (&CatPasDiagT_B.TmpSignalConversionAtFlex_bIn_f);

  /* Embedded MATLAB: '<S4>/Embedded MATLAB Function' incorporates:
   *  SubSystem: '<S4>/001_TmrPasIntr'
   *  SubSystem: '<S4>/01_Activation'
   *  SubSystem: '<S4>/02_Conditions_stabilite_diag_passif'
   *  SubSystem: '<S4>/03_Controle'
   *  SubSystem: '<S4>/04_Filtre'
   *  SubSystem: '<S4>/05_Calculs'
   *  SubSystem: '<S4>/06_mode06'
   *  SubSystem: '<S4>/07_Reinit_degrad_count'
   *  SubSystem: '<S4>/08_Reinit_degrad_count_idle'
   *  SubSystem: '<S4>/09_Gestion_fast_tracking'
   *  SubSystem: '<S4>/10_SeqORngCat'
   *  SubSystem: '<S4>/12_Re_initialisation'
   *  SubSystem: '<S4>/13_Fco_Mode06_Euro6'
   *  SubSystem: '<S4>/14_GDU '
   *  SubSystem: '<S4>/15_GDU'
   */
  /* Embedded MATLAB Function 'CatPasDiagT/CatMon_SdlMid_CatPasDiag_sub/Embedded MATLAB Function': '<S21>:1' */
  /* '<S21>:1:4' */

  /* Outputs for enable SubSystem: '<S6>/01_TiTmrPasIntr_Dec' incorporates:
   *  Constant: '<S6>/OxC_bEnaTmrPasIntr_C'
   *  Constant: '<S6>/OxC_nEngTmrPasIntr_C'
   *  EnablePort: '<S33>/Enable'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S6>/autosar_irv_read'
   */
  if ((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_autorise_irv() &&
       (CatPasDiagT_B.TmpSignalConversionAtRegime_mot >= OxC_nEngTmrPasIntr_C)) &&
      OxC_bEnaTmrPasIntr_C) {
    /* S-Function (sfun_autosar_extras_irv_read_write): '<S33>/autosar_irv_read11' */
    /* S-Function Block: <S33>/autosar_irv_read11 */
    localDataTypeConversion_i =
      Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_OxC_tiTmrPasIntr_irv();

    /* DataTypeConversion Block: '<S33>/Data Type Conversion4'
     *
     * Regarding '<S33>/Data Type Conversion4':
     *   Eliminate redundant data type conversion
     */

    /* MinMax: '<S33>/MinMax' incorporates:
     *  Constant: '<S33>/CatMon_SampleTiMid_SC'
     *  Constant: '<S33>/ConstVal'
     *  Sum: '<S33>/Add'
     */
    localSwitch4 = localDataTypeConversion_i - CatMon_SampleTiMid_SC;
    if (0 > localSwitch4) {
      localSwitch4 = 0;
    }

    /* DataTypeConversion: '<S33>/Data Type Conversion' */
    if (localSwitch4 <= 0) {
      localDataTypeConversion_i = 0U;
    } else {
      localDataTypeConversion_i = (UInt16)localSwitch4;
    }

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S33>/autosar_irv_write11' */

    /* S-Function Block: <S33>/autosar_irv_write11 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_OxC_tiTmrPasIntr_irv
      (localDataTypeConversion_i);

    /* SignalConversion: '<S35>/copy' */
    OxC_tiTmrPasIntr_IRV_MP = localDataTypeConversion_i;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S35>/autosar_testpoint1' */

    /* S-Function Block: <S35>/autosar_testpoint1 */
  }

  /* end of Outputs for SubSystem: '<S6>/01_TiTmrPasIntr_Dec' */
  /* '<S21>:1:6' */

  /* Outputs for enable SubSystem: '<S17>/re_init' incorporates:
   *  Constant: '<S17>/Ext_stGasMod_SC'
   *  Constant: '<S17>/Ext_stGslMod_SC'
   *  Constant: '<S17>/Ext_stTranGasGsl_SC'
   *  Constant: '<S17>/Ext_stTranGslGas_SC'
   *  EnablePort: '<S226>/Enable'
   *  Logic: '<S17>/Logical Operator'
   *  Logic: '<S17>/Logical Operator1'
   *  Logic: '<S17>/Logical Operator10'
   *  Logic: '<S17>/Logical Operator2'
   *  Logic: '<S17>/Logical Operator3'
   *  RelationalOperator: '<S17>/Relational Operator1'
   *  RelationalOperator: '<S17>/Relational Operator12'
   *  RelationalOperator: '<S17>/Relational Operator2'
   *  RelationalOperator: '<S17>/Relational Operator3'
   *  UnitDelay: '<S223>/Unit Delay'
   *  UnitDelay: '<S224>/Unit Delay'
   *  UnitDelay: '<S225>/Unit Delay'
   */
  if ((((localNot_k) && (!CatPasDiagT_DWork.UnitDelay_DSTATE_erz)) ||
       ((Ext_stGslMod_SC == CatPasDiagT_DWork.UnitDelay_DSTATE_ls) &&
        (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stTranGslGas_SC)))
      || ((Ext_stGasMod_SC == CatPasDiagT_DWork.UnitDelay_DSTATE_b5) &&
          (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stTranGasGsl_SC)))
  {
    /* Switch: '<S226>/Switch1' incorporates:
     *  Constant: '<S226>/Cat_stable_conditions_2_delay'
     *  Constant: '<S226>/Cat_stable_conditions_2_delay_g'
     *  Constant: '<S226>/Ext_stGasMod_SC'
     *  RelationalOperator: '<S226>/Relational Operator1'
     */
    if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
      localSwitch1_e = Cat_stable_conditions_2_delay_g;
    } else {
      localSwitch1_e = Cat_stable_conditions_2_delay;
    }

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write10' */

    /* S-Function Block: <S226>/autosar_irv_write10 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_stable_cond_2_tempo_irv
      (localSwitch1_e);

    /* Switch: '<S226>/Switch5' incorporates:
     *  Constant: '<S226>/Cat_stable_conditions_1_delay'
     *  Constant: '<S226>/Cat_stable_conditions_1_delay_g'
     *  Constant: '<S226>/Ext_stGasMod_SC_2'
     *  RelationalOperator: '<S226>/Relational Operator4'
     */
    if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
      localSwitch5_d = Cat_stable_conditions_1_delay_g;
    } else {
      localSwitch5_d = Cat_stable_conditions_1_delay;
    }

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write9' */

    /* S-Function Block: <S226>/autosar_irv_write9 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_stable_cond_1_tempo_irv
      (localSwitch5_d);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S232>/autosar_testpoint1' */

    /* S-Function Block: <S232>/autosar_testpoint1 */
    Cat_stable_conditions_1_tempo = localSwitch5_d;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S233>/autosar_testpoint1' */

    /* S-Function Block: <S233>/autosar_testpoint1 */
    Cat_stable_conditions_2_tempo = localSwitch1_e;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write2' incorporates:
     *  Constant: '<S226>/ConstVal'
     */

    /* S-Function Block: <S226>/autosar_irv_write2 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_irv(FALSE);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S234>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal'
     */

    /* S-Function Block: <S234>/autosar_testpoint1 */
    Cat_etat_defectueux_IRV_MP = FALSE;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write7' incorporates:
     *  Constant: '<S226>/ConstVal_1'
     */

    /* S-Function Block: <S226>/autosar_irv_write7 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv(0);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S240>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal_1'
     */

    /* S-Function Block: <S240>/autosar_testpoint1 */
    Cat_degradation_count_IRV_MP = 0;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write' incorporates:
     *  Constant: '<S226>/ConstVal_2'
     */

    /* S-Function Block: <S226>/autosar_irv_write */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_irv(FALSE);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S239>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal_2'
     */

    /* S-Function Block: <S239>/autosar_testpoint1 */
    Cat_diagnostic_effectue_IRV_MP = FALSE;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write8' incorporates:
     *  Constant: '<S226>/ConstVal_3'
     */

    /* S-Function Block: <S226>/autosar_irv_write8 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_autorise_irv(FALSE);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S241>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal_3'
     */

    /* S-Function Block: <S241>/autosar_testpoint1 */
    Cat_diagnostic_autorise_IRV_MP = FALSE;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write1' incorporates:
     *  Constant: '<S226>/ConstVal_4'
     */

    /* S-Function Block: <S226>/autosar_irv_write1 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_cycle_end_irv(FALSE);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S231>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal_4'
     */

    /* S-Function Block: <S231>/autosar_testpoint1 */
    Cat_diagnostic_cycle_end_IRV_MP = FALSE;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write5' incorporates:
     *  Constant: '<S226>/ConstVal_5'
     */

    /* S-Function Block: <S226>/autosar_irv_write5 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv(FALSE);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S237>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal_5'
     */

    /* S-Function Block: <S237>/autosar_testpoint1 */
    Cat_etat_defectueux_idle_IRV_MP = FALSE;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write3' incorporates:
     *  Constant: '<S226>/ConstVal_6'
     */

    /* S-Function Block: <S226>/autosar_irv_write3 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_idle_irv
      (FALSE);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S235>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal_6'
     */

    /* S-Function Block: <S235>/autosar_testpoint1 */
    Cat_diagnostic_effectue_idle = FALSE;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write4' incorporates:
     *  Constant: '<S226>/ConstVal_7'
     */

    /* S-Function Block: <S226>/autosar_irv_write4 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diag_cycle_end_idle_irv(FALSE);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S236>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal_7'
     */

    /* S-Function Block: <S236>/autosar_testpoint1 */
    Cat_diag_cycle_end_idle_IRV_MP = FALSE;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S226>/autosar_irv_write6' incorporates:
     *  Constant: '<S226>/ConstVal_9'
     */

    /* S-Function Block: <S226>/autosar_irv_write6 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv(0);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S238>/autosar_testpoint1' incorporates:
     *  Constant: '<S226>/ConstVal_9'
     */

    /* S-Function Block: <S238>/autosar_testpoint1 */
    Cat_degradation_count_idle = 0;
  }

  /* end of Outputs for SubSystem: '<S17>/re_init' */

  /* Update for UnitDelay: '<S225>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_erz = localNot_k;

  /* Update for UnitDelay: '<S223>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_ls =
    CatPasDiagT_B.TmpSignalConversionAtExt_stSysG;

  /* Update for UnitDelay: '<S224>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_b5 =
    CatPasDiagT_B.TmpSignalConversionAtExt_stSysG;

  /* '<S21>:1:8' */

  /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
   *  Constant: '<S7>/Ext_stGasMod_SC'
   */
  localSwitch2_fa = (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG ==
                     Ext_stGasMod_SC);

  /* Switch: '<S7>/Switch6' incorporates:
   *  Constant: '<S7>/Cat_diag_continu_manu_inh'
   *  Constant: '<S7>/Cat_diag_continu_manu_inh_gas'
   */
  if (localSwitch2_fa) {
    localSwitch3_jm = Cat_diag_continu_manu_inh_gas;
  } else {
    localSwitch3_jm = Cat_diag_continu_manu_inh;
  }

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S7>/Cat_diag_continu_manu_inh_idle'
   *  Constant: '<S7>/Cat_diag_continu_manu_inh_idle_g'
   */
  if (localSwitch2_fa) {
    localSwitch2_fa = Cat_diag_continu_manu_inh_idle_g;
  } else {
    localSwitch2_fa = Cat_diag_continu_manu_inh_idle;
  }

  /* Logic: '<S7>/Logical Operator5' incorporates:
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S7>/autosar_irv_read'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S7>/autosar_irv_read1'
   */
  localLogicalOperator5_lz =
    (((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_irv() &&
       (localSwitch3_jm)) &&
      Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_idle_irv())
     && (localSwitch2_fa));

  /* Logic: '<S7>/Logical Operator13' incorporates:
   *  Constant: '<S7>/Ext_stTranGasGsl_SC'
   *  Constant: '<S7>/Ext_stTranGslGas_SC'
   *  RelationalOperator: '<S7>/Relational Operator10'
   *  RelationalOperator: '<S7>/Relational Operator11'
   */
  localSwitch3_jm = ((CatPasDiagT_B.TmpSignalConversionAtExt_stSysG !=
                      Ext_stTranGslGas_SC) &&
                     (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG !=
                      Ext_stTranGasGsl_SC));

  /* Sum: '<S7>/Sum1' incorporates:
   *  Constant: '<S7>/CatMon_SampleTiMid_SC'
   *  UnitDelay: '<S39>/Unit Delay'
   */
  localSwitch4 = CatPasDiagT_DWork.UnitDelay_DSTATE_gm - CatMon_SampleTiMid_SC;

  /* Switch: '<S7>/Switch4' incorporates:
   *  Constant: '<S7>/CatMon_tiInhDiag_C'
   */
  if (!localSwitch3_jm) {
    localSwitch4 = CatMon_tiInhDiag_C;
  }

  /* MinMax: '<S7>/MinMax' incorporates:
   *  Constant: '<S7>/ConstVal_1'
   */
  if (0 > localSwitch4) {
    localSwitch4 = 0;
  }

  if (localSwitch4 <= 0) {
    CatMon_tiInhDiag = 0U;
  } else {
    CatMon_tiInhDiag = (UInt16)localSwitch4;
  }

  /* Switch: '<S7>/Switch3' incorporates:
   *  Constant: '<S7>/ConstVal_2'
   *  Constant: '<S7>/ConstVal_4'
   *  Logic: '<S7>/Logical Operator11'
   *  Logic: '<S7>/Logical Operator12'
   *  Logic: '<S7>/Logical Operator2'
   *  RelationalOperator: '<S7>/Relational Operator8'
   */
  if (!CatPasDiagT_B.TmpSignalConversionAtExt_bPresG) {
    localSwitch3_jm = FALSE;
  } else {
    localSwitch3_jm = !((localSwitch3_jm) && (CatMon_tiInhDiag == 0));
  }

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/CatMon_bInhDiagPresScav_C'
   *  Constant: '<S7>/ConstVal'
   */
  if (CatMon_bInhDiagPresScav_C) {
    localSwitch2_fa = FALSE;
  } else {
    localSwitch2_fa = CatPasDiagT_B.TmpSignalConversionAtVlvAct_bIn;
  }

  /* Logic: '<S7>/Logical Operator3' */
  localLogicalOperator3_j = !CatPasDiagT_B.TmpSignalConversionAtEngSt_bOsc;

  /* Logic: '<S7>/Logical Operator4' */
  localLogicalOperator4_j = !CatPasDiagT_B.TmpSignalConversionAtAuto_injec;

  /* Logic: '<S37>/Logical Operator2' incorporates:
   *  Logic: '<S37>/Logical Operator4'
   *  UnitDelay: '<S41>/Unit Delay'
   */
  localRelationalOperator3_m = ((localLogicalOperator4_j) &&
    (!CatPasDiagT_DWork.UnitDelay_DSTATE_kj));

  /* Switch: '<S37>/Switch1' incorporates:
   *  UnitDelay: '<S42>/Unit Delay'
   */
  if (localRelationalOperator3_m) {
    localSwitch1_gu = TRUE;
  } else {
    localSwitch1_gu = CatPasDiagT_DWork.UnitDelay_DSTATE_hn;
  }

  /* Sum: '<S37>/Sum1' incorporates:
   *  Constant: '<S7>/CatMon_SampleTiMid_SC_1'
   *  Constant: '<S7>/CatMon_tiDlyInjCutInhDiag_C'
   */
  localSwitch2 = (UInt32)(CatMon_tiDlyInjCutInhDiag_C + CatMon_SampleTiMid_SC);

  /* Switch: '<S37>/Switch2' incorporates:
   *  UnitDelay: '<S43>/Unit Delay'
   */
  if (!localRelationalOperator3_m) {
    localSwitch2 = CatPasDiagT_DWork.UnitDelay_DSTATE_ie;
  }

  /* Sum: '<S37>/Sum' incorporates:
   *  Constant: '<S7>/CatMon_SampleTiMid_SC_1'
   */
  locallocalSum = localSwitch2 - ((UInt32)CatMon_SampleTiMid_SC);
  if (locallocalSum > localSwitch2) {
    locallocalSum = 0U;
  }

  /* RelationalOperator: '<S37>/Relational Operator3' incorporates:
   *  Constant: '<S37>/Constant4'
   */
  localRelationalOperator3_m = (0U >= locallocalSum);

  /* Logic: '<S7>/Logical Operator6' incorporates:
   *  Logic: '<S37>/Logical Operator'
   */
  localLogicalOperator6_e = ((localLogicalOperator4_j) && ((localSwitch1_gu) &&
                              (localRelationalOperator3_m)));

  /* Logic: '<S38>/Logical Operator2' incorporates:
   *  Logic: '<S38>/Logical Operator4'
   *  UnitDelay: '<S44>/Unit Delay'
   */
  localRelationalOperator3_cq = (CatPasDiagT_B.TmpSignalConversionAtAuto_injec &&
                                 (!CatPasDiagT_DWork.UnitDelay_DSTATE_ag));

  /* Switch: '<S38>/Switch1' incorporates:
   *  UnitDelay: '<S45>/Unit Delay'
   */
  if (localRelationalOperator3_cq) {
    localSwitch1_h = TRUE;
  } else {
    localSwitch1_h = CatPasDiagT_DWork.UnitDelay_DSTATE_er;
  }

  /* Sum: '<S38>/Sum1' incorporates:
   *  Constant: '<S7>/CatMon_SampleTiMid_SC_2'
   *  Constant: '<S7>/CatMon_tiDlyAuthInjAcvDiag_C'
   */
  localSwitch2 = (UInt32)(CatMon_tiDlyAuthInjAcvDiag_C + CatMon_SampleTiMid_SC);

  /* Switch: '<S38>/Switch2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay'
   */
  if (!localRelationalOperator3_cq) {
    localSwitch2 = CatPasDiagT_DWork.UnitDelay_DSTATE_m;
  }

  /* Sum: '<S38>/Sum' incorporates:
   *  Constant: '<S7>/CatMon_SampleTiMid_SC_2'
   */
  locallocalSwitch = localSwitch2 - ((UInt32)CatMon_SampleTiMid_SC);
  if (locallocalSwitch > localSwitch2) {
    locallocalSwitch = 0U;
  }

  /* RelationalOperator: '<S38>/Relational Operator3' incorporates:
   *  Constant: '<S38>/Constant4'
   */
  localRelationalOperator3_cq = (0U >= locallocalSwitch);

  /* Logic: '<S7>/Logical Operator7' incorporates:
   *  Logic: '<S38>/Logical Operator'
   */
  localLogicalOperator7_g = (CatPasDiagT_B.TmpSignalConversionAtAuto_injec &&
    ((localSwitch1_h) && (localRelationalOperator3_cq)));

  /* UnitDelay: '<S36>/UnitDelay' */
  localLogicalOperator1_o = CatPasDiagT_DWork.UnitDelay;

  /* CombinatorialLogic: '<S36>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator6_e != 0);
    rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator7_g != 0);
    rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator1_o != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic[0] = CatPasDiagT_ConstP.Logic_table[rowidx];
    localLogic[1] = CatPasDiagT_ConstP.Logic_table[rowidx + 8];
  }

  /* Switch: '<S36>/Switch2' incorporates:
   *  Constant: '<S36>/NotCLR3'
   *  UnitDelay: '<S36>/UnitDelay1'
   */
  if (CatPasDiagT_DWork.UnitDelay_a) {
    localSwitch2_ln = localLogic[0];
  } else {
    localSwitch2_ln = FALSE;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S7>/Flex_bInhDiagCatPasDiagAlcEst_C'
   *  Constant: '<S7>/Flex_bInhDiagCatPasDiagAlcRate_C'
   *  Constant: '<S7>/Flex_bInhDiagCatPasDiagBlby_C'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator10'
   *  Logic: '<S7>/Logical Operator14'
   *  Logic: '<S7>/Logical Operator15'
   *  Logic: '<S7>/Logical Operator16'
   *  Logic: '<S7>/Logical Operator8'
   *  Logic: '<S7>/Logical Operator9'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S7>/autosar_irv_read2'
   */
  localLogicalOperator1_o = !((((((((((localNot_k) || (localLogicalOperator5_lz))
    || Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_irv()) ||
    (localSwitch3_jm)) || (localSwitch2_fa)) || (localLogicalOperator3_j)) ||
    (localSwitch2_ln)) || (CatPasDiagT_B.TmpSignalConversionAtFlex_bInhD &&
    (!Flex_bInhDiagCatPasDiagAlcEst_C))) ||
    (CatPasDiagT_B.TmpSignalConversionAtFlex_bIn_a &&
     (!Flex_bInhDiagCatPasDiagAlcRate_C))) ||
    (CatPasDiagT_B.TmpSignalConversionAtFlex_bIn_f ||
     (!Flex_bInhDiagCatPasDiagBlby_C)));

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S7>/autosar_irv_write' */

  /* S-Function Block: <S7>/autosar_irv_write */
  Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_autorise_irv
    (localLogicalOperator1_o);

  /* SignalConversion: '<S40>/copy' */
  Cat_diagnostic_autorise_IRV_MP = localLogicalOperator1_o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S40>/autosar_testpoint1' */

  /* S-Function Block: <S40>/autosar_testpoint1 */

  /* Switch: '<S37>/Switch3' incorporates:
   *  Constant: '<S37>/Constant1'
   */
  if (localRelationalOperator3_m) {
    CatMon_tiDlyInjCutInhDiag = 0U;
  } else {
    CatMon_tiDlyInjCutInhDiag = (UInt16)locallocalSum;
  }

  /* Switch: '<S38>/Switch3' incorporates:
   *  Constant: '<S38>/Constant1'
   */
  if (localRelationalOperator3_cq) {
    CatMon_tiDlyAuthInjAcvDiag = 0U;
  } else {
    CatMon_tiDlyAuthInjAcvDiag = (UInt16)locallocalSwitch;
  }

  /* Update for UnitDelay: '<S39>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_gm = CatMon_tiInhDiag;

  /* Update for UnitDelay: '<S41>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_kj = localLogicalOperator4_j;

  /* Update for UnitDelay: '<S42>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_hn = localSwitch1_gu;

  /* Update for UnitDelay: '<S43>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_ie = locallocalSum;

  /* Update for UnitDelay: '<S44>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_ag =
    CatPasDiagT_B.TmpSignalConversionAtAuto_injec;

  /* Update for UnitDelay: '<S45>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_er = localSwitch1_h;

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_m = locallocalSwitch;

  /* Update for UnitDelay: '<S36>/UnitDelay' */
  CatPasDiagT_DWork.UnitDelay = localSwitch2_ln;

  /* Update for UnitDelay: '<S36>/UnitDelay1' incorporates:
   *  Constant: '<S36>/NotCLR2'
   */
  CatPasDiagT_DWork.UnitDelay_a = TRUE;

  /* '<S21>:1:10' */

  /* Outputs for atomic SubSystem: '<S8>/01_Conditions_stabilite_passif' */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S47>/autosar_irv_read1' */

  /* S-Function Block: <S47>/autosar_irv_read1 */
  localSwitch_f =
    Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_stable_cond_1_tempo_irv();

  /* DataTypeConversion Block: '<S47>/Data Type Conversion4'
   *
   * Regarding '<S47>/Data Type Conversion4':
   *   Eliminate redundant data type conversion
   */

  /* MinMax: '<S47>/MinMax2' incorporates:
   *  Constant: '<S47>/CatMon_SampleTiMid_SC'
   *  Constant: '<S47>/ConstVal_2'
   *  Sum: '<S47>/Sum'
   */
  localSwitch4 = localSwitch_f - CatMon_SampleTiMid_SC;
  if (0 > localSwitch4) {
    localSwitch4 = 0;
  }

  if (localSwitch4 <= 0) {
    localSwitch_f = 0U;
  } else if (localSwitch4 > 255) {
    localSwitch_f = MAX_uint8_T;
  } else {
    localSwitch_f = (UInt8)localSwitch4;
  }

  /* Sum: '<S47>/Sum4' incorporates:
   *  UnitDelay: '<S55>/Unit Delay'
   */
  localSwitch4 = CatPasDiagT_B.TmpSignalConversionAtCat_temper -
    CatPasDiagT_DWork.UnitDelay_DSTATE_il;

  /* Abs: '<S47>/Abs2' */
  if (localSwitch4 < 0) {
    localSwitch4 = -localSwitch4;
  }

  /* Switch: '<S47>/Switch5' incorporates:
   *  Constant: '<S47>/Cat_delta_temperature_seuil'
   *  Constant: '<S47>/Cat_delta_temperature_seuil_gas'
   *  Constant: '<S47>/Ext_stGasMod_SC_3'
   *  RelationalOperator: '<S47>/Relational Operator12'
   */
  if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
    locallocalSwitch1_a_idx = Cat_delta_temperature_seuil_gas;
  } else {
    locallocalSwitch1_a_idx = Cat_delta_temperature_seuil;
  }

  /* RelationalOperator: '<S47>/Relational Operator11' */
  Cat_stable_cond_temperature = (localSwitch4 < locallocalSwitch1_a_idx);

  /* Logic: '<S47>/Logical Operator6' */
  localNot_k = !localNot_k;

  /* Switch: '<S47>/Switch4' incorporates:
   *  Constant: '<S47>/Cat_stable_conditions_1_delay'
   *  Constant: '<S47>/Cat_stable_conditions_1_delay_g'
   *  Constant: '<S47>/Ext_stGasMod_SC_1'
   *  RelationalOperator: '<S47>/Relational Operator3'
   */
  if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
    localSwitch1_fr = Cat_stable_conditions_1_delay_g;
  } else {
    localSwitch1_fr = Cat_stable_conditions_1_delay;
  }

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/ERUN_NORMAL_RUNNING'
   *  Constant: '<S47>/ERUN_ON_IDLE'
   *  Constant: '<S47>/FEEDBACK_ENABLED'
   *  Logic: '<S47>/Logical Operator1'
   *  Logic: '<S47>/Logical Operator2'
   *  RelationalOperator: '<S47>/Relational Operator13'
   *  RelationalOperator: '<S47>/Relational Operator5'
   *  RelationalOperator: '<S47>/Relational Operator6'
   */
  if (!((((CatPasDiagT_B.TmpSignalConversionAtMonitor_fd == FEEDBACK_ENABLED) &&
          ((CatPasDiagT_B.TmpSignalConversionAtEngine_run == ERUN_ON_IDLE) ||
           (CatPasDiagT_B.TmpSignalConversionAtEngine_run == ERUN_NORMAL_RUNNING)))
         && Cat_stable_cond_temperature) && (localNot_k))) {
    localSwitch_f = localSwitch1_fr;
  }

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S47>/autosar_irv_write' */

  /* S-Function Block: <S47>/autosar_irv_write */
  Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_stable_cond_1_tempo_irv
    (localSwitch_f);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S47>/autosar_irv_read' */

  /* S-Function Block: <S47>/autosar_irv_read */
  localSwitch1_fr =
    Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_stable_cond_2_tempo_irv();

  /* DataTypeConversion Block: '<S47>/Data Type Conversion2'
   *
   * Regarding '<S47>/Data Type Conversion2':
   *   Eliminate redundant data type conversion
   */

  /* MinMax: '<S47>/MinMax3' incorporates:
   *  Constant: '<S47>/CatMon_SampleTiMid_SC_1'
   *  Constant: '<S47>/ConstVal_4'
   *  Sum: '<S47>/Sum3'
   */
  localSwitch4 = localSwitch1_fr - CatMon_SampleTiMid_SC;
  if (0 > localSwitch4) {
    localSwitch4 = 0;
  }

  if (localSwitch4 <= 0) {
    localSwitch1_fr = 0U;
  } else if (localSwitch4 > 255) {
    localSwitch1_fr = MAX_uint8_T;
  } else {
    localSwitch1_fr = (UInt8)localSwitch4;
  }

  /* Sum: '<S47>/Sum1' incorporates:
   *  UnitDelay: '<S53>/Unit Delay'
   */
  localSwitch4 = CatPasDiagT_B.TmpSignalConversionAtEngine_loa -
    CatPasDiagT_DWork.UnitDelay_DSTATE_mf;

  /* Abs: '<S47>/Abs' */
  if (localSwitch4 < 0) {
    localSwitch4 = -localSwitch4;
  }

  /* Switch: '<S47>/Switch2' incorporates:
   *  Constant: '<S47>/Cat_delta_engine_load_seuil'
   *  Constant: '<S47>/Cat_delta_engine_load_seuil_gas'
   *  Constant: '<S47>/Ext_stGasMod_SC'
   *  RelationalOperator: '<S47>/Relational Operator1'
   */
  if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
    locallocalSwitch1_a_idx = Cat_delta_engine_load_seuil_gas;
  } else {
    locallocalSwitch1_a_idx = Cat_delta_engine_load_seuil;
  }

  /* RelationalOperator: '<S47>/Relational Operator8' */
  Cat_stable_cond_engine_load = (localSwitch4 < locallocalSwitch1_a_idx);

  /* Sum: '<S47>/Sum2' incorporates:
   *  UnitDelay: '<S54>/Unit Delay'
   */
  localSwitch4 = CatPasDiagT_B.TmpSignalConversionAtRegime_mot -
    CatPasDiagT_DWork.UnitDelay_DSTATE_ai;

  /* Abs: '<S47>/Abs1' */
  if (localSwitch4 < 0) {
    localSwitch4 = -localSwitch4;
  }

  /* Switch: '<S47>/Switch3' incorporates:
   *  Constant: '<S47>/Cat_delta_regime_moteur_seuil'
   *  Constant: '<S47>/Cat_delta_regime_moteur_seuil_g'
   *  Constant: '<S47>/Ext_stGasMod_SC_5'
   *  RelationalOperator: '<S47>/Relational Operator2'
   */
  if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
    locallocalSwitch1_a_idx = Cat_delta_regime_moteur_seuil_g;
  } else {
    locallocalSwitch1_a_idx = Cat_delta_regime_moteur_seuil;
  }

  /* RelationalOperator: '<S47>/Relational Operator9' */
  Cat_stable_cond_regime_moteur = (localSwitch4 < locallocalSwitch1_a_idx);

  /* Switch: '<S47>/Switch6' incorporates:
   *  Constant: '<S47>/Cat_stable_conditions_2_delay'
   *  Constant: '<S47>/Cat_stable_conditions_2_delay_g'
   *  Constant: '<S47>/Ext_stGasMod_SC_2'
   *  RelationalOperator: '<S47>/Relational Operator4'
   */
  if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
    localSwitch6_g5 = Cat_stable_conditions_2_delay_g;
  } else {
    localSwitch6_g5 = Cat_stable_conditions_2_delay;
  }

  /* Switch: '<S47>/Switch1' incorporates:
   *  Logic: '<S47>/Logical Operator3'
   */
  if (!(((localNot_k) && Cat_stable_cond_engine_load) &&
        Cat_stable_cond_regime_moteur)) {
    localSwitch1_fr = localSwitch6_g5;
  }

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S47>/autosar_irv_write1' */

  /* S-Function Block: <S47>/autosar_irv_write1 */
  Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_stable_cond_2_tempo_irv
    (localSwitch1_fr);

  /* SignalConversion: '<S56>/copy' */
  Cat_stable_conditions_1_tempo = localSwitch_f;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S56>/autosar_testpoint1' */

  /* S-Function Block: <S56>/autosar_testpoint1 */

  /* SignalConversion: '<S57>/copy' */
  Cat_stable_conditions_2_tempo = localSwitch1_fr;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S57>/autosar_testpoint1' */

  /* S-Function Block: <S57>/autosar_testpoint1 */

  /* Logic: '<S47>/Logical Operator4' incorporates:
   *  Constant: '<S47>/ConstVal'
   *  Constant: '<S47>/ConstVal_1'
   *  RelationalOperator: '<S47>/Relational Operator10'
   *  RelationalOperator: '<S47>/Relational Operator7'
   */
  Cat_conditions_stab = ((((UInt32)(localSwitch_f * 41)) == 0U) && (((UInt32)
                           (localSwitch1_fr * 41)) == 0U));

  /* Update for UnitDelay: '<S55>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_il =
    CatPasDiagT_B.TmpSignalConversionAtCat_temper;

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_mf =
    CatPasDiagT_B.TmpSignalConversionAtEngine_loa;

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_ai =
    CatPasDiagT_B.TmpSignalConversionAtRegime_mot;

  /* end of Outputs for SubSystem: '<S8>/01_Conditions_stabilite_passif' */

  /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
   *  Constant: '<S8>/Ext_stGasMod_SC'
   */
  localSwitch1_h = (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG ==
                    Ext_stGasMod_SC);

  /* Switch: '<S8>/Switch11' incorporates:
   *  Constant: '<S8>/CatMon_bEnaPasGas_C'
   *  Constant: '<S8>/CatMon_bEnaPas_C'
   */
  if (localSwitch1_h) {
    localNot_k = CatMon_bEnaPasGas_C;
  } else {
    localNot_k = CatMon_bEnaPas_C;
  }

  /* RelationalOperator: '<S8>/Relational Operator23' incorporates:
   *  Constant: '<S8>/ConstVal'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_read11'
   */
  localSwitch2_fa =
    (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_OxC_tiTmrPasIntr_irv() == 0);

  /* Logic: '<S8>/Logical Operator7' incorporates:
   *  Constant: '<S8>/Cat_calcul_count_max'
   *  Logic: '<S8>/Logical Operator6'
   *  Logic: '<S8>/Logical Operator8'
   *  RelationalOperator: '<S8>/Relational Operator24'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S8>/autosar_irv_read1'
   */
  localRelationalOperator3_cq = ((localNot_k) && (!((localSwitch2_fa) ||
    (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_calcul_count_irv() >
     Cat_calcul_count_max))));

  /* Outputs for atomic SubSystem: '<S8>/02_Conditions_activation_diag_passif_nominal' */

  /* Switch: '<S48>/Switch5' incorporates:
   *  Constant: '<S48>/Cat_regime_moteur_max'
   *  Constant: '<S48>/Cat_regime_moteur_max_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_regime_moteur_max_gas;
  } else {
    localSwitch6_g5 = Cat_regime_moteur_max;
  }

  /* RelationalOperator: '<S48>/Relational Operator8' */
  localSwitch3_jm = (localSwitch6_g5 >=
                     CatPasDiagT_B.TmpSignalConversionAtRegime_m_j);

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/Cat_regime_moteur_min'
   *  Constant: '<S48>/Cat_regime_moteur_min_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_regime_moteur_min_gas;
  } else {
    localSwitch6_g5 = Cat_regime_moteur_min;
  }

  /* RelationalOperator: '<S48>/Relational Operator7' */
  localLogicalOperator5_lz = (CatPasDiagT_B.TmpSignalConversionAtRegime_m_j >=
    localSwitch6_g5);

  /* Switch: '<S48>/Switch2' incorporates:
   *  Constant: '<S48>/Cat_engine_load_max'
   *  Constant: '<S48>/Cat_engine_load_max_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_engine_load_max_gas;
  } else {
    localSwitch6_g5 = Cat_engine_load_max;
  }

  /* RelationalOperator: '<S48>/Relational Operator6' */
  localNot_k = (((UInt32)(localSwitch6_g5 << 8)) >= ((UInt32)
    CatPasDiagT_B.TmpSignalConversionAtEngine_loa));

  /* Switch: '<S48>/Switch3' incorporates:
   *  Constant: '<S48>/Cat_engine_load_min'
   *  Constant: '<S48>/Cat_engine_load_min_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_engine_load_min_gas;
  } else {
    localSwitch6_g5 = Cat_engine_load_min;
  }

  /* Logic: '<S48>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S48>/Relational Operator5'
   */
  localNot_k = ((localNot_k) && (((UInt32)
    CatPasDiagT_B.TmpSignalConversionAtEngine_loa) >= ((UInt32)
    (localSwitch6_g5 << 8))));

  /* Switch: '<S48>/Switch4' incorporates:
   *  Constant: '<S48>/Cat_water_temp_thresh'
   *  Constant: '<S48>/Cat_water_temp_thresh_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_water_temp_thresh_gas;
  } else {
    localSwitch6_g5 = Cat_water_temp_thresh;
  }

  /* RelationalOperator: '<S48>/Relational Operator3' */
  localSwitch2_fa = (CatPasDiagT_B.TmpSignalConversionAtTemperatur >=
                     localSwitch6_g5);

  /* Switch: '<S48>/Switch6' incorporates:
   *  Constant: '<S48>/Cat_air_temp_thresh'
   *  Constant: '<S48>/Cat_air_temp_thresh_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_air_temp_thresh_gas;
  } else {
    localSwitch6_g5 = Cat_air_temp_thresh;
  }

  /* Switch: '<S48>/Switch12' */
  if (localSwitch1_h) {
    localLogicalOperator3_j = CatPasDiagT_B.TmpSignalConversionAtFlev_low_g;
  } else {
    localLogicalOperator3_j = CatPasDiagT_B.TmpSignalConversionAtFlev_low_f;
  }

  /* Switch: '<S48>/Switch7' incorporates:
   *  Constant: '<S48>/Cat_temperature_max'
   *  Constant: '<S48>/Cat_temperature_max_gas'
   */
  if (localSwitch1_h) {
    locallocalSwitch1_a_idx = Cat_temperature_max_gas;
  } else {
    locallocalSwitch1_a_idx = Cat_temperature_max;
  }

  /* RelationalOperator: '<S48>/Relational Operator10' */
  localLogicalOperator4_j = (locallocalSwitch1_a_idx >=
    CatPasDiagT_B.TmpSignalConversionAtCat_temper);

  /* Switch: '<S48>/Switch8' incorporates:
   *  Constant: '<S48>/Cat_temperature_min'
   *  Constant: '<S48>/Cat_temperature_min_gas'
   */
  if (localSwitch1_h) {
    locallocalSwitch1_a_idx = Cat_temperature_min_gas;
  } else {
    locallocalSwitch1_a_idx = Cat_temperature_min;
  }

  /* RelationalOperator: '<S48>/Relational Operator9' */
  localRelationalOperator3_m = (CatPasDiagT_B.TmpSignalConversionAtCat_temper >=
    locallocalSwitch1_a_idx);

  /* Switch: '<S48>/Switch9' incorporates:
   *  Constant: '<S48>/Cat_air_flow_rate_max'
   *  Constant: '<S48>/Cat_air_flow_rate_max_gas'
   */
  if (localSwitch1_h) {
    locallocalSwitch1_a_idx = Cat_air_flow_rate_max_gas;
  } else {
    locallocalSwitch1_a_idx = Cat_air_flow_rate_max;
  }

  /* RelationalOperator: '<S48>/Relational Operator11' */
  localSwitch1_gu = (locallocalSwitch1_a_idx >=
                     CatPasDiagT_B.TmpSignalConversionAtEngM_mfTot);

  /* Switch: '<S48>/Switch10' incorporates:
   *  Constant: '<S48>/Cat_air_flow_rate_min'
   *  Constant: '<S48>/Cat_air_flow_rate_min_gas'
   */
  if (localSwitch1_h) {
    locallocalSwitch1_a_idx = Cat_air_flow_rate_min_gas;
  } else {
    locallocalSwitch1_a_idx = Cat_air_flow_rate_min;
  }

  /* Logic: '<S48>/Logical Operator' incorporates:
   *  Logic: '<S48>/Logical Operator1'
   *  Logic: '<S48>/Logical Operator3'
   *  Logic: '<S48>/Logical Operator4'
   *  Logic: '<S48>/Logical Operator5'
   *  RelationalOperator: '<S48>/Relational Operator12'
   *  RelationalOperator: '<S48>/Relational Operator4'
   */
  Cat_conditions_activ = ((((((((((((localSwitch3_jm) &&
    (localLogicalOperator5_lz)) && CatPasDiagT_B.TmpSignalConversionAtLshd_down_)
    && (localNot_k)) && CatPasDiagT_B.TmpSignalConversionAtLshd_up_st) &&
    (localSwitch2_fa)) && (CatPasDiagT_B.TmpSignalConversionAtTemperat_g >=
    localSwitch6_g5)) && (!localLogicalOperator3_j)) &&
    ((localLogicalOperator4_j) && (localRelationalOperator3_m))) &&
    CatPasDiagT_B.TmpSignalConversionAtCat_light_) && ((localSwitch1_gu) &&
    (CatPasDiagT_B.TmpSignalConversionAtEngM_mfTot >= locallocalSwitch1_a_idx)))
    && (localRelationalOperator3_cq));

  /* end of Outputs for SubSystem: '<S8>/02_Conditions_activation_diag_passif_nominal' */

  /* Outputs for atomic SubSystem: '<S8>/03_Conditions_activation_diag_passif_ralenti' */

  /* Switch: '<S49>/Switch5' incorporates:
   *  Constant: '<S49>/Cat_regime_moteur_max_idle'
   *  Constant: '<S49>/Cat_regime_moteur_max_idle_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_regime_moteur_max_idle_gas;
  } else {
    localSwitch6_g5 = Cat_regime_moteur_max_idle;
  }

  /* RelationalOperator: '<S49>/Relational Operator13' */
  localNot_k = (localSwitch6_g5 >= CatPasDiagT_B.TmpSignalConversionAtRegime_m_j);

  /* Switch: '<S49>/Switch1' incorporates:
   *  Constant: '<S49>/Cat_regime_moteur_min_idle'
   *  Constant: '<S49>/Cat_regime_moteur_min_idle_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_regime_moteur_min_idle_gas;
  } else {
    localSwitch6_g5 = Cat_regime_moteur_min_idle;
  }

  /* RelationalOperator: '<S49>/Relational Operator8' */
  localSwitch2_fa = (CatPasDiagT_B.TmpSignalConversionAtRegime_m_j >=
                     localSwitch6_g5);

  /* Switch: '<S49>/Switch2' incorporates:
   *  Constant: '<S49>/Cat_water_temp_thresh_idle'
   *  Constant: '<S49>/Cat_water_temp_thresh_idle_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_water_temp_thresh_idle_gas;
  } else {
    localSwitch6_g5 = Cat_water_temp_thresh_idle;
  }

  /* RelationalOperator: '<S49>/Relational Operator3' */
  localLogicalOperator3_j = (CatPasDiagT_B.TmpSignalConversionAtTemperatur >=
    localSwitch6_g5);

  /* Switch: '<S49>/Switch3' incorporates:
   *  Constant: '<S49>/Cat_air_temp_thresh_idle'
   *  Constant: '<S49>/Cat_air_temp_thresh_idle_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_air_temp_thresh_idle_gas;
  } else {
    localSwitch6_g5 = Cat_air_temp_thresh_idle;
  }

  /* RelationalOperator: '<S49>/Relational Operator4' */
  localLogicalOperator4_j = (CatPasDiagT_B.TmpSignalConversionAtTemperat_g >=
    localSwitch6_g5);

  /* Switch: '<S49>/Switch4' */
  if (localSwitch1_h) {
    localRelationalOperator3_m = CatPasDiagT_B.TmpSignalConversionAtFlev_low_g;
  } else {
    localRelationalOperator3_m = CatPasDiagT_B.TmpSignalConversionAtFlev_low_f;
  }

  /* Switch: '<S49>/Switch6' incorporates:
   *  Constant: '<S49>/Cat_temperature_max_idle'
   *  Constant: '<S49>/Cat_temperature_max_idle_gas'
   */
  if (localSwitch1_h) {
    locallocalSwitch1_a_idx = Cat_temperature_max_idle_gas;
  } else {
    locallocalSwitch1_a_idx = Cat_temperature_max_idle;
  }

  /* RelationalOperator: '<S49>/Relational Operator10' */
  localSwitch1_gu = (locallocalSwitch1_a_idx >=
                     CatPasDiagT_B.TmpSignalConversionAtCat_temper);

  /* Switch: '<S49>/Switch7' incorporates:
   *  Constant: '<S49>/Cat_temperature_min_idle'
   *  Constant: '<S49>/Cat_temperature_min_idle_gas'
   */
  if (localSwitch1_h) {
    locallocalSwitch1_a_idx = Cat_temperature_min_idle_gas;
  } else {
    locallocalSwitch1_a_idx = Cat_temperature_min_idle;
  }

  /* Switch: '<S49>/Switch8' incorporates:
   *  Constant: '<S49>/Cat_gear_engaged_max_idle'
   *  Constant: '<S49>/Cat_gear_engaged_max_idle_gas'
   */
  if (localSwitch1_h) {
    localSwitch6_g5 = Cat_gear_engaged_max_idle_gas;
  } else {
    localSwitch6_g5 = Cat_gear_engaged_max_idle;
  }

  /* Logic: '<S49>/Logical Operator' incorporates:
   *  Constant: '<S49>/ERUN_ON_IDLE'
   *  Logic: '<S49>/Logical Operator2'
   *  Logic: '<S49>/Logical Operator3'
   *  Logic: '<S49>/Logical Operator4'
   *  RelationalOperator: '<S49>/Relational Operator11'
   *  RelationalOperator: '<S49>/Relational Operator7'
   *  RelationalOperator: '<S49>/Relational Operator9'
   */
  Cat_cond_activ_idle = ((((((((((((localNot_k) && (localSwitch2_fa)) &&
    (CatPasDiagT_B.TmpSignalConversionAtEngine_run == ERUN_ON_IDLE)) &&
    CatPasDiagT_B.TmpSignalConversionAtLshd_down_) &&
    CatPasDiagT_B.TmpSignalConversionAtLshd_up_st) && (localLogicalOperator3_j))
    && (localLogicalOperator4_j)) && (!localRelationalOperator3_m)) &&
    ((localSwitch1_gu) && (CatPasDiagT_B.TmpSignalConversionAtCat_temper >=
    locallocalSwitch1_a_idx))) && CatPasDiagT_B.TmpSignalConversionAtCat_light_)
    && (CatPasDiagT_B.TmpSignalConversionAtGear_engag <= localSwitch6_g5)) &&
    (localRelationalOperator3_cq));

  /* end of Outputs for SubSystem: '<S8>/03_Conditions_activation_diag_passif_ralenti' */

  /* Outputs for atomic SubSystem: '<S8>/04_Gestion_conditions' */

  /* Logic: '<S50>/Logical Operator6' */
  Cat_conditions_diagnostic = (Cat_conditions_activ && Cat_conditions_stab);

  /* Logic: '<S50>/Logical Operator7' */
  Cat_conditions_diagnostic_idle = (Cat_conditions_stab && Cat_cond_activ_idle);

  /* end of Outputs for SubSystem: '<S8>/04_Gestion_conditions' */
  /* '<S21>:1:12' */

  /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
   *  Constant: '<S9>/Cat_calcul_count_max'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S9>/autosar_irv_read12'
   */
  localNot_k = (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_calcul_count_irv() >
                Cat_calcul_count_max);

  /* Logic: '<S60>/Logical Operator' incorporates:
   *  Logic: '<S60>/Logical Operator1'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  localSwitch2_fa = ((localNot_k) && (!CatPasDiagT_DWork.UnitDelay_DSTATE_hx));

  /* Outputs for enable SubSystem: '<S9>/02_Forcer_status' incorporates:
   *  EnablePort: '<S59>/Cat_diagnostic_autorise'
   */
  if (localSwitch2_fa) {
    /* S-Function (sfun_autosar_extras_irv_read_write): '<S59>/autosar_irv_read' */
    /* S-Function Block: <S59>/autosar_irv_read */
    localautosar_irv_read_p =
      Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_idle_irv();

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S59>/autosar_irv_read1' */

    /* S-Function Block: <S59>/autosar_irv_read1 */
    localautosar_irv_read1_an =
      Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_irv();

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S59>/autosar_irv_read2' */

    /* S-Function Block: <S59>/autosar_irv_read2 */
    localautosar_irv_read2_h =
      Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv();

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S59>/autosar_irv_read3' */

    /* S-Function Block: <S59>/autosar_irv_read3 */
    localautosar_irv_read3_f =
      Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_irv();

    /* MultiPortSwitch: '<S59>/Multiport Switch' incorporates:
     *  Constant: '<S59>/CatMon_noSelModMaxCnt_C'
     *  Constant: '<S59>/ConstVal'
     *  Constant: '<S59>/ConstVal_1'
     *  Constant: '<S59>/ConstVal_2'
     *  Constant: '<S59>/ConstVal_3'
     *  Constant: '<S59>/ConstVal_4'
     *  Constant: '<S59>/ConstVal_5'
     *  Constant: '<S59>/ConstVal_6'
     *  Constant: '<S59>/ConstVal_7'
     */
    switch (CatMon_noSelModMaxCnt_C) {
     case 0:
      localMultiportSwitch[0] = TRUE;
      localMultiportSwitch[1] = TRUE;
      localMultiportSwitch[2] = FALSE;
      localMultiportSwitch[3] = FALSE;
      break;

     case 1:
      localMultiportSwitch[0] = TRUE;
      localMultiportSwitch[1] = TRUE;
      localMultiportSwitch[2] = TRUE;
      localMultiportSwitch[3] = TRUE;
      break;

     default:
      localMultiportSwitch[0] = localautosar_irv_read_p;
      localMultiportSwitch[1] = localautosar_irv_read1_an;
      localMultiportSwitch[2] = localautosar_irv_read2_h;
      localMultiportSwitch[3] = localautosar_irv_read3_f;
      break;
    }

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S59>/autosar_irv_write1' */

    /* S-Function Block: <S59>/autosar_irv_write1 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv
      (localMultiportSwitch[2]);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S59>/autosar_irv_write2' */

    /* S-Function Block: <S59>/autosar_irv_write2 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_idle_irv
      (localMultiportSwitch[0]);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S59>/autosar_irv_write4' */

    /* S-Function Block: <S59>/autosar_irv_write4 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_irv
      (localMultiportSwitch[3]);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S59>/autosar_irv_write5' */

    /* S-Function Block: <S59>/autosar_irv_write5 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_irv
      (localMultiportSwitch[1]);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S68>/autosar_testpoint1' */

    /* S-Function Block: <S68>/autosar_testpoint1 */
    Cat_etat_defectueux_IRV_MP = localMultiportSwitch[3];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S69>/autosar_testpoint1' */

    /* S-Function Block: <S69>/autosar_testpoint1 */
    Cat_diagnostic_effectue_idle = localMultiportSwitch[0];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S70>/autosar_testpoint1' */

    /* S-Function Block: <S70>/autosar_testpoint1 */
    Cat_etat_defectueux_idle_IRV_MP = localMultiportSwitch[2];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S71>/autosar_testpoint1' */

    /* S-Function Block: <S71>/autosar_testpoint1 */
    Cat_diagnostic_effectue_IRV_MP = localMultiportSwitch[1];
  }

  /* end of Outputs for SubSystem: '<S9>/02_Forcer_status' */

  /* Outputs for enable SubSystem: '<S9>/01_Diagnostic' incorporates:
   *  EnablePort: '<S58>/Cat_diagnostic_autorise_IRV_MP'
   *  Logic: '<S9>/Logical Operator1'
   *  Logic: '<S9>/Logical Operator2'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S9>/autosar_irv_read5'
   */
  if (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_autorise_irv() && (
       !localSwitch2_fa)) {
    /* RelationalOperator: '<S58>/Relational Operator3' incorporates:
     *  Constant: '<S58>/Ext_stGasMod_SC'
     */
    localLogicalOperator3_j = (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG ==
      Ext_stGasMod_SC);

    /* Switch: '<S58>/Switch5' incorporates:
     *  Constant: '<S58>/Cat_nombre_echant_idle'
     *  Constant: '<S58>/Cat_nombre_echant_idle_gas'
     */
    if (localLogicalOperator3_j) {
      Cat_nombre_echant_idle_temp = Cat_nombre_echant_idle_gas;
    } else {
      Cat_nombre_echant_idle_temp = Cat_nombre_echant_idle;
    }

    /* Switch: '<S58>/Switch1' incorporates:
     *  Constant: '<S58>/Cat_nombre_echant'
     *  Constant: '<S58>/Cat_nombre_echant_gas'
     */
    if (localLogicalOperator3_j) {
      Cat_nombre_echant_temp = Cat_nombre_echant_gas;
    } else {
      Cat_nombre_echant_temp = Cat_nombre_echant;
    }

    /* Switch: '<S58>/Switch2' incorporates:
     *  Constant: '<S58>/Cat_seuil_degradation_sup'
     *  Constant: '<S58>/Cat_seuil_degradation_sup_gas'
     */
    if (localLogicalOperator3_j) {
      Cat_seuil_degradation_sup_temp = Cat_seuil_degradation_sup_gas;
    } else {
      Cat_seuil_degradation_sup_temp = Cat_seuil_degradation_sup;
    }

    /* Switch: '<S58>/Switch3' incorporates:
     *  Constant: '<S58>/Cat_seuil_degradation_inf'
     *  Constant: '<S58>/Cat_seuil_degradation_inf_gas'
     */
    if (localLogicalOperator3_j) {
      Cat_seuil_degradation_inf_temp = Cat_seuil_degradation_inf_gas;
    } else {
      Cat_seuil_degradation_inf_temp = Cat_seuil_degradation_inf;
    }

    /* Switch: '<S58>/Switch4' incorporates:
     *  Constant: '<S58>/Cat_seuil_degradation_sup_idle'
     *  Constant: '<S58>/Cat_seuil_degradation_sup_idle_g'
     */
    if (localLogicalOperator3_j) {
      Cat_seuil_degradation_sup_idle_t = Cat_seuil_degradation_sup_idle_g;
    } else {
      Cat_seuil_degradation_sup_idle_t = Cat_seuil_degradation_sup_idle;
    }

    /* Switch: '<S58>/Switch6' incorporates:
     *  Constant: '<S58>/Cat_seuil_degradation_inf_idle'
     *  Constant: '<S58>/Cat_seuil_degradation_inf_idle_g'
     */
    if (localLogicalOperator3_j) {
      Cat_seuil_degradation_inf_idle_t = Cat_seuil_degradation_inf_idle_g;
    } else {
      Cat_seuil_degradation_inf_idle_t = Cat_seuil_degradation_inf_idle;
    }

    /* Switch: '<S58>/Switch7' incorporates:
     *  Constant: '<S58>/Cat_diag_continu_manu_inh'
     *  Constant: '<S58>/Cat_diag_continu_manu_inh_gas'
     */
    if (localLogicalOperator3_j) {
      Cat_diag_continu_manu_inh_temp = Cat_diag_continu_manu_inh_gas;
    } else {
      Cat_diag_continu_manu_inh_temp = Cat_diag_continu_manu_inh;
    }

    /* Switch: '<S58>/Switch11' incorporates:
     *  Constant: '<S58>/Cat_diag_continu_manu_inh_idle'
     *  Constant: '<S58>/Cat_diag_continu_manu_inh_idle_g'
     */
    if (localLogicalOperator3_j) {
      Cat_diag_continu_manu_inh_idle_t = Cat_diag_continu_manu_inh_idle_g;
    } else {
      Cat_diag_continu_manu_inh_idle_t = Cat_diag_continu_manu_inh_idle;
    }

    /* Stateflow: '<S58>/2_Diagnostic' incorporates:
     *  Constant: '<S58>/CAT_CALCUL'
     *  Constant: '<S58>/CAT_INIT'
     *  Constant: '<S58>/CAT_SOMME'
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_read1'
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_read2'
     */
    /* Gateway: CatPasDiagT/CatMon_SdlMid_CatPasDiag_sub/03_Controle/01_Diagnostic/2_Diagnostic */
    /* During: CatPasDiagT/CatMon_SdlMid_CatPasDiag_sub/03_Controle/01_Diagnostic/2_Diagnostic */
    if (CatPasDiagT_DWork.is_active_c3_CatPasDiagT == 0) {
      /* Entry: CatPasDiagT/CatMon_SdlMid_CatPasDiag_sub/03_Controle/01_Diagnostic/2_Diagnostic */
      CatPasDiagT_DWork.is_active_c3_CatPasDiagT = 1U;

      /* Transition: '<S61>:4' */
      /* Entry 'CAT_INIT': '<S61>:1' */
      CatPasDiagT_DWork.is_c3_CatPasDiagT = IN_CAT_INIT;
      Cat_diagnostic_state = CAT_INIT;
      CatPasDiagT_B.Cat_etat_defectueux =
        (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() >
         Cat_seuil_degradation_sup_temp);
      CatPasDiagT_B.Cat_diagnostic_effectue =
        (((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() >
           Cat_seuil_degradation_sup_temp) ||
          (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() <
           Cat_seuil_degradation_inf_temp)) ||
         CatPasDiagT_B.Cat_diagnostic_effectue);
      CatPasDiagT_B.Cat_diagnostic_cycle_end =
        ((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() >
          Cat_seuil_degradation_sup_temp) ||
         (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() <
          Cat_seuil_degradation_inf_temp));
      CatPasDiagT_B.Cat_etat_defectueux_idle =
        (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv()
         > Cat_seuil_degradation_sup_idle_t);
      CatPasDiagT_B.Cat_diagnostic_effectue_idle_m =
        (((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
           () > Cat_seuil_degradation_sup_idle_t) ||
          (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
           () < Cat_seuil_degradation_inf_idle_t)) ||
         CatPasDiagT_B.Cat_diagnostic_effectue_idle_m);
      CatPasDiagT_B.Cat_diag_cycle_end_idle =
        ((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
          () > Cat_seuil_degradation_sup_idle_t) ||
         (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
          () < Cat_seuil_degradation_inf_idle_t));
    } else {
      switch (CatPasDiagT_DWork.is_c3_CatPasDiagT) {
       case IN_CAT_CALC:
        /* During 'CAT_CALC': '<S61>:2' */
        /* Transition: '<S61>:5' */
        /* Exit 'CAT_CALC': '<S61>:2' */
        /* Entry 'CAT_INIT': '<S61>:1' */
        CatPasDiagT_DWork.is_c3_CatPasDiagT = IN_CAT_INIT;
        Cat_diagnostic_state = CAT_INIT;
        CatPasDiagT_B.Cat_etat_defectueux =
          (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() >
           Cat_seuil_degradation_sup_temp);
        CatPasDiagT_B.Cat_diagnostic_effectue =
          (((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv()
             > Cat_seuil_degradation_sup_temp) ||
            (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv()
             < Cat_seuil_degradation_inf_temp)) ||
           CatPasDiagT_B.Cat_diagnostic_effectue);
        CatPasDiagT_B.Cat_diagnostic_cycle_end =
          ((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() >
            Cat_seuil_degradation_sup_temp) ||
           (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() <
            Cat_seuil_degradation_inf_temp));
        CatPasDiagT_B.Cat_etat_defectueux_idle =
          (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
           () > Cat_seuil_degradation_sup_idle_t);
        CatPasDiagT_B.Cat_diagnostic_effectue_idle_m =
          (((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
             () > Cat_seuil_degradation_sup_idle_t) ||
            (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
             () < Cat_seuil_degradation_inf_idle_t)) ||
           CatPasDiagT_B.Cat_diagnostic_effectue_idle_m);
        CatPasDiagT_B.Cat_diag_cycle_end_idle =
          ((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
            () > Cat_seuil_degradation_sup_idle_t) ||
           (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
            () < Cat_seuil_degradation_inf_idle_t));
        break;

       case IN_CAT_INIT:
        /* During 'CAT_INIT': '<S61>:1' */
        /* Transition: '<S61>:6' */
        if ((((SInt32)Cat_conditions_diagnostic) == 1) && ((((SInt32)
               CatPasDiagT_B.Cat_diagnostic_effectue) == 0) || (((((SInt32)
                 Cat_diag_continu_manu_inh_temp) == 0) && (((SInt32)
                 CatPasDiagT_B.Cat_etat_defectueux) == 0)) && (((SInt32)
                CatPasDiagT_B.Cat_etat_defectueux_idle) == 0)))) {
          /* Transition: '<S61>:8' */
          /* Exit 'CAT_INIT': '<S61>:1' */
          Cat_nombre_acqui = 1U;
          Cat_diagnostic_ralenti = FALSE;
          CatPasDiagT_B.Cat_diagnostic_cycle_end = FALSE;

          /* Entry 'CAT_SOMME': '<S61>:3' */
          CatPasDiagT_DWork.is_c3_CatPasDiagT = IN_CAT_SOMME;
          Cat_diagnostic_state = CAT_SOMME;
          Cat_nombre_acqui = (UInt8)((UInt32)(Cat_nombre_acqui + 1));
        } else {
          if ((((SInt32)Cat_conditions_diagnostic_idle) == 1) && ((((SInt32)
                 CatPasDiagT_B.Cat_diagnostic_effectue_idle_m) == 0) ||
               ((((SInt32)Cat_diag_continu_manu_inh_idle_t) == 0) && (((SInt32)
                  CatPasDiagT_B.Cat_etat_defectueux_idle) == 0)))) {
            /* Transition: '<S61>:9' */
            /* Exit 'CAT_INIT': '<S61>:1' */
            Cat_nombre_acqui = 1U;
            Cat_diagnostic_ralenti = TRUE;
            CatPasDiagT_B.Cat_diag_cycle_end_idle = FALSE;

            /* Entry 'CAT_SOMME': '<S61>:3' */
            CatPasDiagT_DWork.is_c3_CatPasDiagT = IN_CAT_SOMME;
            Cat_diagnostic_state = CAT_SOMME;
            Cat_nombre_acqui = (UInt8)((UInt32)(Cat_nombre_acqui + 1));
          }
        }
        break;

       case IN_CAT_SOMME:
        /* During 'CAT_SOMME': '<S61>:3' */
        if (((((SInt32)Cat_diagnostic_ralenti) == 0) && ((((SInt32)
                Cat_conditions_diagnostic) == 0) || (Cat_nombre_acqui >=
               Cat_nombre_echant_temp))) || ((((SInt32)Cat_diagnostic_ralenti) ==
              1) && ((((SInt32)Cat_conditions_diagnostic_idle) == 0) ||
                     (Cat_nombre_acqui >= Cat_nombre_echant_idle_temp)))) {
          /* Transition: '<S61>:7' */
          /* Exit 'CAT_SOMME': '<S61>:3' */
          /* Entry 'CAT_CALC': '<S61>:2' */
          CatPasDiagT_DWork.is_c3_CatPasDiagT = IN_CAT_CALC;
          Cat_diagnostic_state = CAT_CALCUL;
        } else {
          Cat_nombre_acqui = (UInt8)((UInt32)(Cat_nombre_acqui + 1));
        }
        break;

       default:
        /* Transition: '<S61>:4' */
        /* Entry 'CAT_INIT': '<S61>:1' */
        CatPasDiagT_DWork.is_c3_CatPasDiagT = IN_CAT_INIT;
        Cat_diagnostic_state = CAT_INIT;
        CatPasDiagT_B.Cat_etat_defectueux =
          (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() >
           Cat_seuil_degradation_sup_temp);
        CatPasDiagT_B.Cat_diagnostic_effectue =
          (((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv()
             > Cat_seuil_degradation_sup_temp) ||
            (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv()
             < Cat_seuil_degradation_inf_temp)) ||
           CatPasDiagT_B.Cat_diagnostic_effectue);
        CatPasDiagT_B.Cat_diagnostic_cycle_end =
          ((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() >
            Cat_seuil_degradation_sup_temp) ||
           (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv() <
            Cat_seuil_degradation_inf_temp));
        CatPasDiagT_B.Cat_etat_defectueux_idle =
          (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
           () > Cat_seuil_degradation_sup_idle_t);
        CatPasDiagT_B.Cat_diagnostic_effectue_idle_m =
          (((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
             () > Cat_seuil_degradation_sup_idle_t) ||
            (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
             () < Cat_seuil_degradation_inf_idle_t)) ||
           CatPasDiagT_B.Cat_diagnostic_effectue_idle_m);
        CatPasDiagT_B.Cat_diag_cycle_end_idle =
          ((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
            () > Cat_seuil_degradation_sup_idle_t) ||
           (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
            () < Cat_seuil_degradation_inf_idle_t));
        break;
      }
    }

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_write' */

    /* S-Function Block: <S58>/autosar_irv_write */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_irv
      (CatPasDiagT_B.Cat_etat_defectueux);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_write1' */

    /* S-Function Block: <S58>/autosar_irv_write1 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv
      (CatPasDiagT_B.Cat_etat_defectueux_idle);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_write2' */

    /* S-Function Block: <S58>/autosar_irv_write2 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_idle_irv
      (CatPasDiagT_B.Cat_diagnostic_effectue_idle_m);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_write3' */

    /* S-Function Block: <S58>/autosar_irv_write3 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_cycle_end_irv
      (CatPasDiagT_B.Cat_diagnostic_cycle_end);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_write4' */

    /* S-Function Block: <S58>/autosar_irv_write4 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diag_cycle_end_idle_irv
      (CatPasDiagT_B.Cat_diag_cycle_end_idle);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_write5' */

    /* S-Function Block: <S58>/autosar_irv_write5 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_irv
      (CatPasDiagT_B.Cat_diagnostic_effectue);

    /* SignalConversion: '<S62>/copy' */
    Cat_diagnostic_cycle_end_IRV_MP = CatPasDiagT_B.Cat_diagnostic_cycle_end;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S62>/autosar_testpoint1' */

    /* S-Function Block: <S62>/autosar_testpoint1 */

    /* SignalConversion: '<S63>/copy' */
    Cat_etat_defectueux_IRV_MP = CatPasDiagT_B.Cat_etat_defectueux;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S63>/autosar_testpoint1' */

    /* S-Function Block: <S63>/autosar_testpoint1 */

    /* SignalConversion: '<S64>/copy' */
    Cat_diagnostic_effectue_idle = CatPasDiagT_B.Cat_diagnostic_effectue_idle_m;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S64>/autosar_testpoint1' */

    /* S-Function Block: <S64>/autosar_testpoint1 */

    /* SignalConversion: '<S65>/copy' */
    Cat_diag_cycle_end_idle_IRV_MP = CatPasDiagT_B.Cat_diag_cycle_end_idle;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S65>/autosar_testpoint1' */

    /* S-Function Block: <S65>/autosar_testpoint1 */

    /* SignalConversion: '<S66>/copy' */
    Cat_etat_defectueux_idle_IRV_MP = CatPasDiagT_B.Cat_etat_defectueux_idle;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S66>/autosar_testpoint1' */

    /* S-Function Block: <S66>/autosar_testpoint1 */

    /* SignalConversion: '<S67>/copy' */
    Cat_diagnostic_effectue_IRV_MP = CatPasDiagT_B.Cat_diagnostic_effectue;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S67>/autosar_testpoint1' */

    /* S-Function Block: <S67>/autosar_testpoint1 */

    /* Logic: '<S58>/Logical Operator7' */
    localLogicalOperator4_j = !CatPasDiagT_B.Cat_etat_defectueux_idle;

    /* Switch: '<S58>/Switch10' incorporates:
     *  Constant: '<S58>/Cat_priorite_intrusif'
     *  Constant: '<S58>/Cat_priorite_intrusif_gas'
     */
    if (localLogicalOperator3_j) {
      localRelationalOperator3_m = Cat_priorite_intrusif_gas;
    } else {
      localRelationalOperator3_m = Cat_priorite_intrusif;
    }

    /* Logic: '<S58>/Logical Operator8' */
    localSwitch1_gu = (CatPasDiagT_B.Cat_diagnostic_effectue_idle_m ||
                       (localRelationalOperator3_m));

    /* Switch: '<S58>/Switch9' incorporates:
     *  Constant: '<S58>/CatMon_bEnaIntrGas_C'
     *  Constant: '<S58>/CatMon_bEnaIntr_C'
     */
    if (localLogicalOperator3_j) {
      localRelationalOperator3_m = CatMon_bEnaIntrGas_C;
    } else {
      localRelationalOperator3_m = CatMon_bEnaIntr_C;
    }

    /* RelationalOperator: '<S58>/Relational Operator' incorporates:
     *  Constant: '<S58>/ConstVal_1'
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_read11'
     */
    localSwitch3_jm =
      (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_OxC_tiTmrPasIntr_irv() == 0);

    /* MultiPortSwitch: '<S58>/Multiport Switch' incorporates:
     *  Constant: '<S58>/CatMon_noSelModMaxCnt_C'
     *  Constant: '<S58>/ConstVal'
     *  Constant: '<S58>/ConstVal_2'
     *  Constant: '<S58>/ConstVal_3'
     */
    switch (CatMon_noSelModMaxCnt_C) {
     case 0:
      localLogicalOperator5_lz = FALSE;
      break;

     case 1:
      localLogicalOperator5_lz = FALSE;
      break;

     default:
      localLogicalOperator5_lz = TRUE;
      break;
    }

    /* Logic: '<S58>/Logical Operator9' incorporates:
     *  Constant: '<S58>/Cat_calcul_count_max'
     *  Logic: '<S58>/Logical Operator10'
     *  RelationalOperator: '<S58>/Relational Operator2'
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S58>/autosar_irv_read12'
     */
    localLogicalOperator5_lz = ((localSwitch3_jm) ||
      ((Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_calcul_count_irv() >
        Cat_calcul_count_max) && (localLogicalOperator5_lz)));

    /* Logic: '<S58>/Logical Operator4' */
    localRelationalOperator3_m = ((localRelationalOperator3_m) ||
      (localLogicalOperator5_lz));

    /* Switch: '<S58>/Switch8' incorporates:
     *  Constant: '<S58>/CatMon_bEnaPasGas_C'
     *  Constant: '<S58>/CatMon_bEnaPas_C'
     */
    if (localLogicalOperator3_j) {
      localLogicalOperator3_j = CatMon_bEnaPasGas_C;
    } else {
      localLogicalOperator3_j = CatMon_bEnaPas_C;
    }

    /* Logic: '<S58>/Logical Operator1' incorporates:
     *  Logic: '<S58>/Logical Operator2'
     *  Logic: '<S58>/Logical Operator3'
     *  Logic: '<S58>/Logical Operator5'
     *  Logic: '<S58>/Logical Operator6'
     */
    CatPasDiagT_B.LogicalOperator1 = (((((CatPasDiagT_B.Cat_diagnostic_effectue &&
      CatPasDiagT_B.Cat_etat_defectueux) && (localLogicalOperator4_j)) &&
      (localSwitch1_gu)) && (localRelationalOperator3_m)) ||
      ((localRelationalOperator3_m) && ((localLogicalOperator5_lz) ||
      (!localLogicalOperator3_j))));
  }

  /* end of Outputs for SubSystem: '<S9>/01_Diagnostic' */

  /* Switch: '<S9>/Switch8' incorporates:
   *  Constant: '<S9>/CatMon_noSelModMaxCnt_C'
   *  Constant: '<S9>/ConstVal'
   *  Constant: '<S9>/ConstVal_1'
   *  Constant: '<S9>/ConstVal_2'
   *  Constant: '<S9>/ConstVal_3'
   *  Constant: '<S9>/ConstVal_4'
   *  Logic: '<S9>/Logical Operator10'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if ((CatMon_noSelModMaxCnt_C != 2) && (localSwitch2_fa)) {
    localSwitch3_jm = TRUE;
    localLogicalOperator5_lz = TRUE;
  } else {
    localSwitch3_jm = FALSE;
    localLogicalOperator5_lz = FALSE;
  }

  /* Update for UnitDelay: '<S72>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_hx = localNot_k;

  /* '<S21>:1:14' */

  /* Outputs for enable SubSystem: '<S10>/01_Filtre' incorporates:
   *  EnablePort: '<S73>/Cat_diagnostic_autorise_IRV_MP'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_read5'
   */
  if (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_autorise_irv()) {
    /* DataTypeConversion: '<S73>/Data Type Conversion' */
    localDataTypeConversion_f = ((Float32)
      CatPasDiagT_B.TmpSignalConversionAtTension_so) * 0.0048828125F;

    /* RelationalOperator: '<S73>/Relational Operator12' incorporates:
     *  Constant: '<S73>/Ext_stGasMod_SC'
     */
    localNot_k = (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG ==
                  Ext_stGasMod_SC);

    /* Outputs for enable SubSystem: '<S73>/Filtre_sonde_aval_nominal' incorporates:
     *  EnablePort: '<S74>/Enable'
     *  EnablePort: '<S75>/Enable'
     *  Logic: '<S73>/Logical Operator1'
     *  SubSystem: '<S73>/Filtre_sonde_aval_nominal_gas'
     */
    if (!localNot_k) {
      /* UnitDelay: '<S85>/Unit Delay' */
      localUnitDelay_ai = CatPasDiagT_DWork.UnitDelay_DSTATE_bg;

      /* UnitDelay: '<S82>/Unit Delay' */
      localUnitDelay_jy = CatPasDiagT_DWork.UnitDelay_DSTATE_ab;

      /* UnitDelay: '<S81>/Unit Delay' */
      localUnitDelay_c = CatPasDiagT_DWork.UnitDelay_DSTATE_j;

      /* UnitDelay: '<S79>/Unit Delay' */
      localUnitDelay_c4 = CatPasDiagT_DWork.UnitDelay_DSTATE_cw;

      /* Sum: '<S74>/Sum2' incorporates:
       *  Constant: '<S74>/Cat_coef_den_ordre_1'
       *  Constant: '<S74>/Cat_coef_den_ordre_2'
       *  Constant: '<S74>/Cat_coef_den_ordre_3'
       *  Constant: '<S74>/Cat_coef_den_ordre_4'
       *  Constant: '<S74>/Cat_coef_num_ordre_0'
       *  Constant: '<S74>/Cat_coef_num_ordre_2'
       *  Constant: '<S74>/Cat_coef_num_ordre_4'
       *  DataTypeConversion: '<S74>/Data Type Conversion'
       *  DataTypeConversion: '<S74>/Data Type Conversion1'
       *  DataTypeConversion: '<S74>/Data Type Conversion2'
       *  DataTypeConversion: '<S74>/Data Type Conversion3'
       *  DataTypeConversion: '<S74>/Data Type Conversion4'
       *  DataTypeConversion: '<S74>/Data Type Conversion5'
       *  DataTypeConversion: '<S74>/Data Type Conversion6'
       *  Product: '<S87>/Divide'
       *  Product: '<S88>/Divide'
       *  Product: '<S89>/Divide'
       *  Product: '<S90>/Divide'
       *  Product: '<S91>/Divide'
       *  Product: '<S92>/Divide'
       *  Product: '<S93>/Divide'
       *  UnitDelay: '<S80>/Unit Delay'
       *  UnitDelay: '<S83>/Unit Delay'
       */
      localSum2_m = (((((((((Float32)Cat_coef_num_ordre_0) * 7.629394531E-006F)
                          * localDataTypeConversion_f) - ((((Float32)
        Cat_coef_num_ordre_2) * 7.629394531E-006F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_bg)) + ((((Float32)
        Cat_coef_num_ordre_4) * 7.629394531E-006F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_ap)) + (((((Float32)
        Cat_coef_den_ordre_1) * 1.525878906E-005F) + 2.0F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_ab)) - (((((Float32)
        Cat_coef_den_ordre_2) * 1.525878906E-005F) + 2.0F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_j)) + (((((Float32)
        Cat_coef_den_ordre_3) * 1.525878906E-005F) + 1.0F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_cw)) - ((((Float32)
        Cat_coef_den_ordre_4) * 1.525878906E-005F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_nlr);

      /* Abs: '<S74>/Abs' */
      localMerge1 = ACTEMS_FabsF(localSum2_m);

      /* Update for UnitDelay: '<S85>/Unit Delay' incorporates:
       *  UnitDelay: '<S86>/Unit Delay'
       */
      CatPasDiagT_DWork.UnitDelay_DSTATE_bg =
        CatPasDiagT_DWork.UnitDelay_DSTATE_jh;

      /* Update for UnitDelay: '<S83>/Unit Delay' incorporates:
       *  UnitDelay: '<S84>/Unit Delay'
       */
      CatPasDiagT_DWork.UnitDelay_DSTATE_ap =
        CatPasDiagT_DWork.UnitDelay_DSTATE_ej;

      /* Update for UnitDelay: '<S82>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_ab = localSum2_m;

      /* Update for UnitDelay: '<S81>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_j = localUnitDelay_jy;

      /* Update for UnitDelay: '<S79>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_cw = localUnitDelay_c;

      /* Update for UnitDelay: '<S80>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_nlr = localUnitDelay_c4;

      /* Update for UnitDelay: '<S84>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_ej = localUnitDelay_ai;

      /* Update for UnitDelay: '<S86>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_jh = localDataTypeConversion_f;
    } else {
      /* UnitDelay: '<S100>/Unit Delay' */
      localUnitDelay_ai = CatPasDiagT_DWork.UnitDelay_DSTATE_n;

      /* UnitDelay: '<S97>/Unit Delay' */
      localUnitDelay_jy = CatPasDiagT_DWork.UnitDelay_DSTATE_p1;

      /* UnitDelay: '<S96>/Unit Delay' */
      localUnitDelay_c = CatPasDiagT_DWork.UnitDelay_DSTATE_nn;

      /* UnitDelay: '<S94>/Unit Delay' */
      localUnitDelay_c4 = CatPasDiagT_DWork.UnitDelay_DSTATE_i;

      /* Sum: '<S75>/Sum2' incorporates:
       *  Constant: '<S75>/Cat_coef_den_ordre_1_gas'
       *  Constant: '<S75>/Cat_coef_den_ordre_2_gas'
       *  Constant: '<S75>/Cat_coef_den_ordre_3_gas'
       *  Constant: '<S75>/Cat_coef_den_ordre_4_gas'
       *  Constant: '<S75>/Cat_coef_num_ordre_0_gas'
       *  Constant: '<S75>/Cat_coef_num_ordre_2_gas'
       *  Constant: '<S75>/Cat_coef_num_ordre_4_gas'
       *  DataTypeConversion: '<S75>/Data Type Conversion'
       *  DataTypeConversion: '<S75>/Data Type Conversion1'
       *  DataTypeConversion: '<S75>/Data Type Conversion2'
       *  DataTypeConversion: '<S75>/Data Type Conversion3'
       *  DataTypeConversion: '<S75>/Data Type Conversion4'
       *  DataTypeConversion: '<S75>/Data Type Conversion5'
       *  DataTypeConversion: '<S75>/Data Type Conversion6'
       *  Product: '<S102>/Divide'
       *  Product: '<S103>/Divide'
       *  Product: '<S104>/Divide'
       *  Product: '<S105>/Divide'
       *  Product: '<S106>/Divide'
       *  Product: '<S107>/Divide'
       *  Product: '<S108>/Divide'
       *  UnitDelay: '<S95>/Unit Delay'
       *  UnitDelay: '<S98>/Unit Delay'
       */
      localSum2_m = (((((((((Float32)Cat_coef_num_ordre_0_gas) *
                           7.629394531E-006F) * localDataTypeConversion_f) -
                         ((((Float32)Cat_coef_num_ordre_2_gas) *
                           7.629394531E-006F) *
                          CatPasDiagT_DWork.UnitDelay_DSTATE_n)) + ((((Float32)
        Cat_coef_num_ordre_4_gas) * 7.629394531E-006F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_kr)) + (((((Float32)
        Cat_coef_den_ordre_1_gas) * 1.525878906E-005F) + 2.0F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_p1)) - (((((Float32)
        Cat_coef_den_ordre_2_gas) * 1.525878906E-005F) + 2.0F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_nn)) + (((((Float32)
        Cat_coef_den_ordre_3_gas) * 1.525878906E-005F) + 1.0F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_i)) - ((((Float32)
        Cat_coef_den_ordre_4_gas) * 1.525878906E-005F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_o);

      /* Abs: '<S75>/Abs' */
      localMerge1 = ACTEMS_FabsF(localSum2_m);

      /* Update for UnitDelay: '<S100>/Unit Delay' incorporates:
       *  UnitDelay: '<S101>/Unit Delay'
       */
      CatPasDiagT_DWork.UnitDelay_DSTATE_n =
        CatPasDiagT_DWork.UnitDelay_DSTATE_nl;

      /* Update for UnitDelay: '<S98>/Unit Delay' incorporates:
       *  UnitDelay: '<S99>/Unit Delay'
       */
      CatPasDiagT_DWork.UnitDelay_DSTATE_kr =
        CatPasDiagT_DWork.UnitDelay_DSTATE_iy;

      /* Update for UnitDelay: '<S97>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_p1 = localSum2_m;

      /* Update for UnitDelay: '<S96>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_nn = localUnitDelay_jy;

      /* Update for UnitDelay: '<S94>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_i = localUnitDelay_c;

      /* Update for UnitDelay: '<S95>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_o = localUnitDelay_c4;

      /* Update for UnitDelay: '<S99>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_iy = localUnitDelay_ai;

      /* Update for UnitDelay: '<S101>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_nl = localDataTypeConversion_f;
    }

    /* end of Outputs for SubSystem: '<S73>/Filtre_sonde_aval_nominal' */

    /* Outputs for enable SubSystem: '<S73>/Filtre_sonde_aval_ralenti' incorporates:
     *  EnablePort: '<S76>/Enable'
     *  EnablePort: '<S77>/Enable'
     *  Logic: '<S73>/Logical Operator'
     *  SubSystem: '<S73>/Filtre_sonde_aval_ralenti_gas'
     */
    if (!localNot_k) {
      /* UnitDelay: '<S115>/Unit Delay' */
      localUnitDelay_ai = CatPasDiagT_DWork.UnitDelay_DSTATE_b;

      /* UnitDelay: '<S112>/Unit Delay' */
      localUnitDelay_jy = CatPasDiagT_DWork.UnitDelay_DSTATE_p;

      /* UnitDelay: '<S111>/Unit Delay' */
      localUnitDelay_c = CatPasDiagT_DWork.UnitDelay_DSTATE_gr;

      /* UnitDelay: '<S109>/Unit Delay' */
      localUnitDelay_c4 = CatPasDiagT_DWork.UnitDelay_DSTATE_au;

      /* Sum: '<S76>/Sum2' incorporates:
       *  Constant: '<S76>/Cat_coef_den_ordre_1_idle'
       *  Constant: '<S76>/Cat_coef_den_ordre_2_idle'
       *  Constant: '<S76>/Cat_coef_den_ordre_3_idle'
       *  Constant: '<S76>/Cat_coef_den_ordre_4_idle'
       *  Constant: '<S76>/Cat_coef_num_ordre_0_idle'
       *  Constant: '<S76>/Cat_coef_num_ordre_2_idle'
       *  Constant: '<S76>/Cat_coef_num_ordre_4_idle'
       *  DataTypeConversion: '<S76>/Data Type Conversion'
       *  DataTypeConversion: '<S76>/Data Type Conversion1'
       *  DataTypeConversion: '<S76>/Data Type Conversion3'
       *  DataTypeConversion: '<S76>/Data Type Conversion4'
       *  DataTypeConversion: '<S76>/Data Type Conversion5'
       *  DataTypeConversion: '<S76>/Data Type Conversion6'
       *  DataTypeConversion: '<S76>/Data Type Conversion7'
       *  Product: '<S117>/Divide'
       *  Product: '<S118>/Divide'
       *  Product: '<S119>/Divide'
       *  Product: '<S120>/Divide'
       *  Product: '<S121>/Divide'
       *  Product: '<S122>/Divide'
       *  Product: '<S123>/Divide'
       *  UnitDelay: '<S110>/Unit Delay'
       *  UnitDelay: '<S113>/Unit Delay'
       */
      localSum2_m = (((((((((Float32)Cat_coef_num_ordre_0_idle) *
                           4.577636616E-007F) * localDataTypeConversion_f) -
                         ((((Float32)Cat_coef_num_ordre_2_idle) *
                           7.629394645E-007F) *
                          CatPasDiagT_DWork.UnitDelay_DSTATE_b)) + ((((Float32)
        Cat_coef_num_ordre_4_idle) * 4.577636616E-007F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_g)) + (((((Float32)
        Cat_coef_den_ordre_1_idle) * 1.525878906E-005F) + 3.0F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_p)) - (((((Float32)
        Cat_coef_den_ordre_2_idle) * 1.525878906E-005F) + 5.625F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_gr)) + (((((Float32)
        Cat_coef_den_ordre_3_idle) * 1.525878906E-005F) + 3.6875F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_au)) - ((((Float32)
        Cat_coef_den_ordre_4_idle) * 1.525878906E-005F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_k5);

      /* Abs: '<S76>/Abs' */
      localMerge_e = ACTEMS_FabsF(localSum2_m);

      /* Update for UnitDelay: '<S115>/Unit Delay' incorporates:
       *  UnitDelay: '<S116>/Unit Delay'
       */
      CatPasDiagT_DWork.UnitDelay_DSTATE_b =
        CatPasDiagT_DWork.UnitDelay_DSTATE_f;

      /* Update for UnitDelay: '<S113>/Unit Delay' incorporates:
       *  UnitDelay: '<S114>/Unit Delay'
       */
      CatPasDiagT_DWork.UnitDelay_DSTATE_g =
        CatPasDiagT_DWork.UnitDelay_DSTATE_bt;

      /* Update for UnitDelay: '<S112>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_p = localSum2_m;

      /* Update for UnitDelay: '<S111>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_gr = localUnitDelay_jy;

      /* Update for UnitDelay: '<S109>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_au = localUnitDelay_c;

      /* Update for UnitDelay: '<S110>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_k5 = localUnitDelay_c4;

      /* Update for UnitDelay: '<S114>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_bt = localUnitDelay_ai;

      /* Update for UnitDelay: '<S116>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_f = localDataTypeConversion_f;
    } else {
      /* UnitDelay: '<S130>/Unit Delay' */
      localUnitDelay_ai = CatPasDiagT_DWork.UnitDelay_DSTATE;

      /* UnitDelay: '<S127>/Unit Delay' */
      localUnitDelay_jy = CatPasDiagT_DWork.UnitDelay_DSTATE_k;

      /* UnitDelay: '<S126>/Unit Delay' */
      localUnitDelay_c = CatPasDiagT_DWork.UnitDelay_DSTATE_a;

      /* UnitDelay: '<S124>/Unit Delay' */
      localUnitDelay_c4 = CatPasDiagT_DWork.UnitDelay_DSTATE_c;

      /* Sum: '<S77>/Sum2' incorporates:
       *  Constant: '<S77>/Cat_coef_den_ordre_1_idle_gas'
       *  Constant: '<S77>/Cat_coef_den_ordre_2_idle_gas'
       *  Constant: '<S77>/Cat_coef_den_ordre_3_idle_gas'
       *  Constant: '<S77>/Cat_coef_den_ordre_4_idle_gas'
       *  Constant: '<S77>/Cat_coef_num_ordre_0_idle_gas'
       *  Constant: '<S77>/Cat_coef_num_ordre_2_idle_gas'
       *  Constant: '<S77>/Cat_coef_num_ordre_4_idle_gas'
       *  DataTypeConversion: '<S77>/Data Type Conversion'
       *  DataTypeConversion: '<S77>/Data Type Conversion1'
       *  DataTypeConversion: '<S77>/Data Type Conversion2'
       *  DataTypeConversion: '<S77>/Data Type Conversion3'
       *  DataTypeConversion: '<S77>/Data Type Conversion4'
       *  DataTypeConversion: '<S77>/Data Type Conversion5'
       *  DataTypeConversion: '<S77>/Data Type Conversion6'
       *  Product: '<S132>/Divide'
       *  Product: '<S133>/Divide'
       *  Product: '<S134>/Divide'
       *  Product: '<S135>/Divide'
       *  Product: '<S136>/Divide'
       *  Product: '<S137>/Divide'
       *  Product: '<S138>/Divide'
       *  UnitDelay: '<S125>/Unit Delay'
       *  UnitDelay: '<S128>/Unit Delay'
       */
      localSum2_m = (((((((((Float32)Cat_coef_num_ordre_0_idle_gas) *
                           4.577636616E-007F) * localDataTypeConversion_f) -
                         ((((Float32)Cat_coef_num_ordre_2_idle_gas) *
                           7.629394645E-007F) *
                          CatPasDiagT_DWork.UnitDelay_DSTATE)) + ((((Float32)
        Cat_coef_num_ordre_4_idle_gas) * 4.577636616E-007F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_e)) + (((((Float32)
        Cat_coef_den_ordre_1_idle_gas) * 1.525878906E-005F) + 3.0F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_k)) - (((((Float32)
        Cat_coef_den_ordre_2_idle_gas) * 1.525878906E-005F) + 5.625F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_a)) + (((((Float32)
        Cat_coef_den_ordre_3_idle_gas) * 1.525878906E-005F) + 3.6875F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_c)) - ((((Float32)
        Cat_coef_den_ordre_4_idle_gas) * 1.525878906E-005F) *
        CatPasDiagT_DWork.UnitDelay_DSTATE_l);

      /* Abs: '<S77>/Abs' */
      localMerge_e = ACTEMS_FabsF(localSum2_m);

      /* Update for UnitDelay: '<S130>/Unit Delay' incorporates:
       *  UnitDelay: '<S131>/Unit Delay'
       */
      CatPasDiagT_DWork.UnitDelay_DSTATE = CatPasDiagT_DWork.UnitDelay_DSTATE_d;

      /* Update for UnitDelay: '<S128>/Unit Delay' incorporates:
       *  UnitDelay: '<S129>/Unit Delay'
       */
      CatPasDiagT_DWork.UnitDelay_DSTATE_e =
        CatPasDiagT_DWork.UnitDelay_DSTATE_kl;

      /* Update for UnitDelay: '<S127>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_k = localSum2_m;

      /* Update for UnitDelay: '<S126>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_a = localUnitDelay_jy;

      /* Update for UnitDelay: '<S124>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_c = localUnitDelay_c;

      /* Update for UnitDelay: '<S125>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_l = localUnitDelay_c4;

      /* Update for UnitDelay: '<S129>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_kl = localUnitDelay_ai;

      /* Update for UnitDelay: '<S131>/Unit Delay' */
      CatPasDiagT_DWork.UnitDelay_DSTATE_d = localDataTypeConversion_f;
    }

    /* end of Outputs for SubSystem: '<S73>/Filtre_sonde_aval_ralenti' */

    /* Switch: '<S73>/Switch' */
    if (Cat_diagnostic_ralenti) {
      localMerge1 = localMerge_e;
    }

    /* Product: '<S78>/Divide' incorporates:
     *  Constant: '<S73>/ConstVal'
     */
    localDataTypeConversion_f = (Float32)ACTEMS_FloorF((1000.0F * localMerge1)
      + 0.5F);
    if (localDataTypeConversion_f < 256.0F) {
      Cat_energ_inst_aval = (UInt8)localDataTypeConversion_f;
    } else {
      Cat_energ_inst_aval = MAX_uint8_T;
    }
  }

  /* end of Outputs for SubSystem: '<S10>/01_Filtre' */
  /* '<S21>:1:16' */

  /* Outputs for enable SubSystem: '<S11>/01_Puissance_degradation' incorporates:
   *  EnablePort: '<S139>/Cat_diagnostic_autorise_IRV_MP'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_read'
   */
  if (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_autorise_irv()) {
    /* Outputs for atomic SubSystem: '<S139>/01_Puissance' */

    /* RelationalOperator: '<S140>/Relational Operator5' incorporates:
     *  Constant: '<S140>/CAT_SOMME'
     */
    Cond_for_somme = (Cat_diagnostic_state == CAT_SOMME);

    /* Outputs for enable SubSystem: '<S140>/02_Somme' incorporates:
     *  EnablePort: '<S143>/Cond_for_somme'
     */
    if (Cond_for_somme) {
      /* DataStoreWrite: '<S143>/Cat_energ_aval_DSW' incorporates:
       *  DataStoreRead: '<S143>/Cat_energ_aval_DSR'
       *  Sum: '<S143>/Sum'
       */
      localSwitch2 = (UInt32)(Cat_energ_inst_aval + Cat_energ_aval);
      if (localSwitch2 > 65535U) {
        Cat_energ_aval = MAX_uint16_T;
      } else {
        Cat_energ_aval = (UInt16)localSwitch2;
      }

      /* DataStoreWrite: '<S143>/Cat_debit_gaz_sum_DSW' incorporates:
       *  DataStoreRead: '<S143>/Cat_debit_gaz_sum_DSR'
       *  DataTypeConversion: '<S143>/Data Type Conversion1'
       *  Sum: '<S143>/Sum2'
       */
      Cat_debit_gaz_sum = (((Float32)
                            CatPasDiagT_B.TmpSignalConversionAtEngM_mfTot) *
                           1.525878906E-005F) + Cat_debit_gaz_sum;

      /* DataStoreWrite: '<S143>/Cat_temperature_sum_DSW' incorporates:
       *  DataStoreRead: '<S143>/Cat_temperature_sum_DSR'
       *  DataTypeConversion: '<S143>/Data Type Conversion2'
       *  Sum: '<S143>/Sum3'
       */
      Cat_temperature_sum = ((((Float32)
        CatPasDiagT_B.TmpSignalConversionAtCat_temper) * 0.03125F) - 50.0F) +
        Cat_temperature_sum;
    }

    /* end of Outputs for SubSystem: '<S140>/02_Somme' */

    /* RelationalOperator: '<S140>/Relational Operator4' incorporates:
     *  Constant: '<S140>/CAT_INIT'
     */
    Cond_for_init = (Cat_diagnostic_state == CAT_INIT);

    /* Outputs for enable SubSystem: '<S140>/01_Init' incorporates:
     *  EnablePort: '<S142>/Cond_for_init'
     */
    if (Cond_for_init) {
      /* DataStoreWrite: '<S142>/Cat_energ_aval_DSW' incorporates:
       *  DataTypeConversion: '<S142>/Data Type Conversion2'
       */
      Cat_energ_aval = Cat_energ_inst_aval;

      /* DataStoreWrite: '<S142>/Cat_debit_gaz_sum_DSW' incorporates:
       *  DataTypeConversion: '<S142>/Data Type Conversion1'
       */
      Cat_debit_gaz_sum = ((Float32)
                           CatPasDiagT_B.TmpSignalConversionAtEngM_mfTot) *
        1.525878906E-005F;

      /* DataStoreWrite: '<S142>/Cat_temperature_sum_DSW' incorporates:
       *  DataTypeConversion: '<S142>/Data Type Conversion'
       */
      Cat_temperature_sum = (((Float32)
        CatPasDiagT_B.TmpSignalConversionAtCat_temper) * 0.03125F) - 50.0F;

      /* Constant: '<S142>/ConstVal' */
      CatPasDiagT_B.ConstVal_j = FALSE;
    }

    /* end of Outputs for SubSystem: '<S140>/01_Init' */

    /* RelationalOperator: '<S140>/Relational Operator6' incorporates:
     *  Constant: '<S140>/CAT_CALCUL'
     */
    Cond_for_calcul = (Cat_diagnostic_state == CAT_CALCUL);

    /* Outputs for enable SubSystem: '<S140>/03_Calcul' incorporates:
     *  EnablePort: '<S144>/Cond_for_calcul'
     */
    if (Cond_for_calcul) {
      /* DataTypeConversion: '<S144>/Data Type Conversion4' */
      localUnitDelay_ai = (Float32)Cat_nombre_acqui;

      /* DataStoreWrite: '<S144>/Cat_debit_gaz_moy_DSW' incorporates:
       *  Constant: '<S145>/offset'
       *  Constant: '<S145>/offset1'
       *  Constant: '<S145>/one_on_slope'
       *  DataStoreRead: '<S144>/Cat_debit_gaz_sum_DSR'
       *  DataTypeConversion: '<S145>/OutDTConv'
       *  Product: '<S145>/Product4'
       *  Product: '<S148>/Divide'
       *  Sum: '<S145>/Add1'
       *  Sum: '<S145>/Add2'
       */
      localDataTypeConversion_f = ((Cat_debit_gaz_sum / localUnitDelay_ai) *
        65536.0F) + 0.5F;
      if (localDataTypeConversion_f < 65536.0F) {
        if (localDataTypeConversion_f >= 0.0F) {
          CatPasDiagT_DWork.Cat_debit_gaz_moy = (UInt16)
            localDataTypeConversion_f;
        } else {
          CatPasDiagT_DWork.Cat_debit_gaz_moy = 0U;
        }
      } else {
        CatPasDiagT_DWork.Cat_debit_gaz_moy = MAX_uint16_T;
      }

      /* DataStoreWrite: '<S144>/Cat_puissance_DSW' incorporates:
       *  DataStoreRead: '<S144>/Cat_energ_aval_DSR'
       *  DataTypeConversion: '<S144>/Data Type Conversion1'
       *  DataTypeConversion: '<S144>/Data Type Conversion5'
       *  Product: '<S147>/Divide'
       */
      localDataTypeConversion_f = (Float32)ACTEMS_FloorF((((Float32)
        Cat_energ_aval) / localUnitDelay_ai) + 0.5F);
      if (localDataTypeConversion_f < 256.0F) {
        if (localDataTypeConversion_f >= 0.0F) {
          Cat_puissance = (UInt8)localDataTypeConversion_f;
        } else {
          Cat_puissance = 0U;
        }
      } else {
        Cat_puissance = MAX_uint8_T;
      }

      /* DataStoreWrite: '<S144>/Cat_temperature_moy_DSW' incorporates:
       *  Constant: '<S146>/offset'
       *  Constant: '<S146>/offset1'
       *  Constant: '<S146>/one_on_slope'
       *  DataStoreRead: '<S144>/Cat_temperature_sum_DSR'
       *  DataTypeConversion: '<S146>/OutDTConv'
       *  Product: '<S146>/Product4'
       *  Product: '<S149>/Divide'
       *  Sum: '<S146>/Add1'
       *  Sum: '<S146>/Add2'
       */
      localDataTypeConversion_f = (((Cat_temperature_sum / localUnitDelay_ai) -
        -50.0F) * 32.0F) + 0.5F;
      if (localDataTypeConversion_f < 65536.0F) {
        if (localDataTypeConversion_f >= 0.0F) {
          CatPasDiagT_DWork.Cat_temperature_moy = (UInt16)
            localDataTypeConversion_f;
        } else {
          CatPasDiagT_DWork.Cat_temperature_moy = 0U;
        }
      } else {
        CatPasDiagT_DWork.Cat_temperature_moy = MAX_uint16_T;
      }

      /* Constant: '<S144>/ConstVal' */
      CatPasDiagT_B.ConstVal = TRUE;
    }

    /* end of Outputs for SubSystem: '<S140>/03_Calcul' */

    /* Switch: '<S140>/Switch1' incorporates:
     *  Constant: '<S140>/CAT_CALCUL_2'
     *  Constant: '<S140>/ConstVal'
     *  RelationalOperator: '<S140>/Relational Operator2'
     */
    if (Cat_diagnostic_state == CAT_CALCUL) {
      localNot_k = CatPasDiagT_B.ConstVal;
    } else {
      localNot_k = FALSE;
    }

    /* Switch: '<S140>/Switch' incorporates:
     *  Constant: '<S140>/CAT_INIT_2'
     *  RelationalOperator: '<S140>/Relational Operator1'
     */
    if (Cat_diagnostic_state == CAT_INIT) {
      Cat_puissance_calculee = CatPasDiagT_B.ConstVal_j;
    } else {
      Cat_puissance_calculee = localNot_k;
    }

    /* DataStoreRead: '<S140>/Cat_puissance_DSR' */
    localSwitch6_g5 = Cat_puissance;

    /* DataStoreRead: '<S140>/Cat_debit_gaz_moy_DSR' */
    CatPasDiagT_B.Cat_debit_gaz_moy_DSR = CatPasDiagT_DWork.Cat_debit_gaz_moy;

    /* DataStoreRead: '<S140>/Cat_temperature_moy_DSR' */
    CatPasDiagT_B.Cat_temperature_moy_DSR =
      CatPasDiagT_DWork.Cat_temperature_moy;

    /* end of Outputs for SubSystem: '<S139>/01_Puissance' */

    /* Outputs for enable SubSystem: '<S139>/02_Degradation' incorporates:
     *  EnablePort: '<S141>/Cat_puissance_calculee'
     */
    if (Cat_puissance_calculee) {
      /* RelationalOperator: '<S141>/Relational Operator12' incorporates:
       *  Constant: '<S141>/Ext_stGasMod_SC'
       */
      localNot_k = (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG ==
                    Ext_stGasMod_SC);

      /* Outputs for atomic SubSystem: '<S141>/01_Conditions_compteur_degradation' */

      /* Lookup2D: '<S152>/Look-Up Table (2-D)'
       * About '<S152>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U16  2^-16
       * Input1  Data Type:  Fixed Point    U16  2^-5  Bias -50.0
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Below
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      {
        UInt32 iRowIndex1, iColumnIndex1;
        BINARYSEARCH_U16_iL( &(iRowIndex1), CatPasDiagT_B.Cat_debit_gaz_moy_DSR,
                            (&(Cat_pumped_gas_bkpt_map[0])), 15U);
        BINARYSEARCH_U16_iL( &(iColumnIndex1),
                            CatPasDiagT_B.Cat_temperature_moy_DSR,
                            (&(Cat_temperature_bkpt_map[0])), 15U);
        /*-MD localLookUpTable2D = Cat_seuil_obd_gas_map[iRowIndex1+16*iColumnIndex1];*/
          localLookUpTable2D = Cat_seuil_obd_gas_map[iColumnIndex1][iRowIndex1]; /*-MA */
      }

      /* DataTypeDuplicate Block: '<S152>/Data Type Duplicate2'
       *
       * Regarding '<S152>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Lookup2D: '<S153>/Look-Up Table (2-D)'
       * About '<S153>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U16  2^-16
       * Input1  Data Type:  Fixed Point    U16  2^-5  Bias -50.0
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Below
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      {
        UInt32 iRowIndex1, iColumnIndex1;
        BINARYSEARCH_U16_iL( &(iRowIndex1), CatPasDiagT_B.Cat_debit_gaz_moy_DSR,
                            (&(Cat_pumped_gas_bkpt_map[0])), 15U);
        BINARYSEARCH_U16_iL( &(iColumnIndex1),
                            CatPasDiagT_B.Cat_temperature_moy_DSR,
                            (&(Cat_temperature_bkpt_map[0])), 15U);
        /*-MD localLookUpTable2D_c = Cat_seuil_obd_map[iRowIndex1+16*iColumnIndex1];*/
		/*-MA*/
		localLookUpTable2D_c = Cat_seuil_obd_map[iColumnIndex1][iRowIndex1];

      }

      /* DataTypeDuplicate Block: '<S153>/Data Type Duplicate2'
       *
       * Regarding '<S153>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Switch: '<S150>/Switch5' incorporates:
       *  Constant: '<S150>/Cat_nombre_acqui_min_idle'
       *  Constant: '<S150>/Cat_nombre_acqui_min_idle_gas'
       */
      if (localNot_k) {
        localSwitch1_f = Cat_nombre_acqui_min_idle_gas;
      } else {
        localSwitch1_f = Cat_nombre_acqui_min_idle;
      }

      /* RelationalOperator: '<S150>/Relational Operator6' */
      localSwitch2_fa = (localSwitch1_f <= Cat_nombre_acqui);

      /* Switch: '<S150>/Switch2' incorporates:
       *  Constant: '<S150>/Cat_nombre_acqui_min'
       *  Constant: '<S150>/Cat_nombre_acqui_min_gas'
       */
      if (localNot_k) {
        localSwitch1_f = Cat_nombre_acqui_min_gas;
      } else {
        localSwitch1_f = Cat_nombre_acqui_min;
      }

      /* Switch: '<S150>/Switch4' incorporates:
       *  RelationalOperator: '<S150>/Relational Operator5'
       */
      if (!Cat_diagnostic_ralenti) {
        localSwitch2_fa = (localSwitch1_f <= Cat_nombre_acqui);
      }

      /* Switch: '<S150>/Switch1' incorporates:
       *  Lookup2D: '<S152>/Look-Up Table (2-D)'
       *  Lookup2D: '<S153>/Look-Up Table (2-D)'
       */
      if (localNot_k) {
        localSwitch1_f = localLookUpTable2D;
      } else {
        localSwitch1_f = localLookUpTable2D_c;
      }

      /* Logic: '<S150>/Logical Operator' incorporates:
       *  Constant: '<S150>/Cat_pumped_gas_bkpt_map'
       *  Constant: '<S150>/Cat_pumped_gas_bkpt_map_1'
       *  Constant: '<S150>/Cat_temperature_bkpt_map'
       *  Constant: '<S150>/Cat_temperature_bkpt_map_1'
       *  Constant: '<S150>/ConstVal'
       *  Constant: '<S150>/ConstVal_1'
       *  Constant: '<S150>/ConstVal_3'
       *  Constant: '<S150>/ConstVal_5'
       *  Constant: '<S154>/Constant'
       *  Constant: '<S154>/Constant1'
       *  Constant: '<S156>/Constant'
       *  Constant: '<S156>/Constant1'
       *  Constant: '<S157>/Constant'
       *  Logic: '<S150>/Logical Operator1'
       *  MinMax: '<S154>/MinMax'
       *  MinMax: '<S156>/MinMax'
       *  MinMax: '<S157>/MinMax'
       *  RelationalOperator: '<S150>/Relational Operator'
       *  RelationalOperator: '<S150>/Relational Operator1'
       *  RelationalOperator: '<S150>/Relational Operator2'
       *  RelationalOperator: '<S150>/Relational Operator3'
       *  RelationalOperator: '<S150>/Relational Operator4'
       *  RelationalOperator: '<S150>/Relational Operator7'
       *  Selector: '<S154>/Selector'
       *  Selector: '<S155>/Selector'
       *  Selector: '<S156>/Selector'
       *  Selector: '<S157>/Selector'
       *  Sum: '<S154>/Add'
       *  Sum: '<S156>/Add'
       */
      Cat_analyse_autorisee = (((((((localSwitch2_fa) && (localSwitch1_f > 0)) &&
                                   (CatPasDiagT_B.Cat_debit_gaz_moy_DSR >=
        Cat_pumped_gas_bkpt_map[0])) && (CatPasDiagT_B.Cat_debit_gaz_moy_DSR <=
        Cat_pumped_gas_bkpt_map[15])) && (CatPasDiagT_B.Cat_temperature_moy_DSR >=
        Cat_temperature_bkpt_map[0])) && (CatPasDiagT_B.Cat_temperature_moy_DSR <=
        Cat_temperature_bkpt_map[15])) &&
        ((CatPasDiagT_B.TmpSignalConversionAtCat_seui_d > 0) ||
         CatPasDiagT_B.TmpSignalConversionAtCf_bInhFle));

      /* end of Outputs for SubSystem: '<S141>/01_Conditions_compteur_degradation' */

      /* Outputs for enable SubSystem: '<S141>/02_Compteur_degradation' incorporates:
       *  EnablePort: '<S151>/Cat_analyse_autorisee'
       */
      if (Cat_analyse_autorisee) {
        /* Outputs for atomic SubSystem: '<S151>/01_Calcul_seuil_obd_depasse' */

        /* If: '<S158>/If' incorporates:
         *  ActionPort: '<S162>/Action Port'
         *  ActionPort: '<S163>/Action Port'
         *  SubSystem: '<S158>/01_Cat_seuil_obd_gas_map_Selection'
         *  SubSystem: '<S158>/02_Cat_seuil_obd_map_BaryCentre_Sel'
         */
        if (localNot_k) {
          /* Lookup2D: '<S164>/Look-Up Table (2-D)'
           * About '<S164>/Look-Up Table (2-D)':
           * Input0  Data Type:  Fixed Point    U16  2^-16
           * Input1  Data Type:  Fixed Point    U16  2^-5  Bias -50.0
           * Output0 Data Type:  Integer        U8
           * Lookup Method: Below
           *
           * Row Data    parameter uses the same data type and scaling as Input0
           * Column Data parameter uses the same data type and scaling as Input1
           * Table Data  parameter uses the same data type and scaling as Output0
           */
          {
            UInt32 iRowIndex1, iColumnIndex1;
            BINARYSEARCH_U16_iL( &(iRowIndex1),
                                CatPasDiagT_B.Cat_debit_gaz_moy_DSR,
                                (&(Cat_pumped_gas_bkpt_map[0])), 15U);
            BINARYSEARCH_U16_iL( &(iColumnIndex1),
                                CatPasDiagT_B.Cat_temperature_moy_DSR,
                                (&(Cat_temperature_bkpt_map[0])), 15U);
            
			 /*-MD localLookUpTable2D_k = Cat_seuil_obd_gas_map[iRowIndex1+16*iColumnIndex1];*/
             /*-MA*/
			  localLookUpTable2D_k = Cat_seuil_obd_gas_map[iColumnIndex1][iRowIndex1];
          }

          /* DataTypeDuplicate Block: '<S164>/Data Type Duplicate2'
           *
           * Regarding '<S164>/Data Type Duplicate2':
           *   Unused code path elimination
           */

          /* DataTypeConversion: '<S162>/Data Type Conversion1' */
          localUnitDelay_ai = (Float32)localLookUpTable2D_k;
        } else {
          /* Lookup2D: '<S167>/Look-Up Table (2-D)'
           * About '<S167>/Look-Up Table (2-D)':
           * Input0  Data Type:  Fixed Point    U16  2^-16
           * Input1  Data Type:  Fixed Point    U16  2^-5  Bias -50.0
           * Output0 Data Type:  Integer        U8
           * Lookup Method: Below
           *
           * Row Data    parameter uses the same data type and scaling as Input0
           * Column Data parameter uses the same data type and scaling as Input1
           * Table Data  parameter uses the same data type and scaling as Output0
           */
          {
            UInt32 iRowIndex1, iColumnIndex1;
            BINARYSEARCH_U16_iL( &(iRowIndex1),
                                CatPasDiagT_B.Cat_debit_gaz_moy_DSR,
                                (&(Cat_pumped_gas_bkpt_map[0])), 15U);
            BINARYSEARCH_U16_iL( &(iColumnIndex1),
                                CatPasDiagT_B.Cat_temperature_moy_DSR,
                                (&(Cat_temperature_bkpt_map[0])), 15U);
            /*-MD localLookUpTable2D_g = Cat_seuil_obd_map[iRowIndex1+16*iColumnIndex1];*/
			/*-MA*/
			localLookUpTable2D_g = Cat_seuil_obd_map[iColumnIndex1][iRowIndex1];
          }

          /* DataTypeDuplicate Block: '<S167>/Data Type Duplicate2'
           *
           * Regarding '<S167>/Data Type Duplicate2':
           *   Unused code path elimination
           */

          /* DataTypeConversion: '<S163>/Data Type Conversion2' */
          localUnitDelay_ai = (Float32)localLookUpTable2D_g;

          /* If: '<S163>/If' incorporates:
           *  ActionPort: '<S165>/Action Port'
           *  ActionPort: '<S166>/Action Port'
           *  Logic: '<S163>/Logical Operator11'
           *  SubSystem: '<S163>/01_BaryCentre_Calc'
           *  SubSystem: '<S163>/02_Cat_seuil_obd_map_Calc'
           */
          if (!CatPasDiagT_B.TmpSignalConversionAtCf_bInhFle) {
            /* Switch: '<S172>/Switch' incorporates:
             *  RelationalOperator: '<S172>/UpperRelop'
             */
            locallocalSwitch1_a_idx =
              CatPasDiagT_B.TmpSignalConversionAtCat_seuil_;

            /* Switch: '<S172>/Switch2' incorporates:
             *  RelationalOperator: '<S172>/LowerRelop1'
             */
            if (CatPasDiagT_B.TmpSignalConversionAtCat_seuil_ > 256) {
              locallocalSwitch1_a_idx = 256U;
            }

            /* Sum: '<S168>/Sum2' incorporates:
             *  Product: '<S168>/Divide'
             *  Sum: '<S168>/Sum3'
             */
            localUnitDelay_ai += (((Float32)
              CatPasDiagT_B.TmpSignalConversionAtCat_seui_d) - localUnitDelay_ai)
              * (((Float32)locallocalSwitch1_a_idx) * 0.00390625F);
          }
        }

        /* RelationalOperator: '<S158>/Relational Operator' incorporates:
         *  DataTypeConversion: '<S158>/Data Type Conversion3'
         */
        Seuil_obd_depasse = (((Float32)localSwitch6_g5) > localUnitDelay_ai);

        /* end of Outputs for SubSystem: '<S151>/01_Calcul_seuil_obd_depasse' */

        /* Outputs for enable SubSystem: '<S151>/02_Compteur_diag_ralenti' incorporates:
         *  EnablePort: '<S159>/Cat_diagnostic_ralenti'
         */
        if (Cat_diagnostic_ralenti) {
          /* DataTypeConversion: '<S159>/DTConv_Single_To_UFix_1' incorporates:
           *  S-Function (sfun_autosar_extras_irv_read_write): '<S159>/autosar_irv_read3'
           */
          localUnitDelay_ai = ((Float32)
                               Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
                               ()) * 9.999999776E-003F;

          /* If: '<S159>/If' incorporates:
           *  ActionPort: '<S174>/Action Port'
           *  ActionPort: '<S175>/Action Port'
           *  SubSystem: '<S159>/F01_If'
           *  SubSystem: '<S159>/F02_Else'
           */
          if (Seuil_obd_depasse) {
            /* Lookup2D: '<S178>/Look-Up Table (2-D)'
             * About '<S178>/Look-Up Table (2-D)':
             * Input0  Data Type:  Fixed Point    U16  2^-16
             * Input1  Data Type:  Fixed Point    U16  2^-5  Bias -50.0
             * Output0 Data Type:  Fixed Point    U8  2^-7  FSlope 1.5
             * Lookup Method: Below
             *
             * Row Data    parameter uses the same data type and scaling as Input0
             * Column Data parameter uses the same data type and scaling as Input1
             * Table Data  parameter uses the same data type and scaling as Output0
             */
            {
              UInt32 iRowIndex1, iColumnIndex1;
              BINARYSEARCH_U16_iL( &(iRowIndex1),
                                  CatPasDiagT_B.Cat_debit_gaz_moy_DSR,
                                  (&(Cat_pumped_gas_bkpt_map[0])), 15U);
              BINARYSEARCH_U16_iL( &(iColumnIndex1),
                                  CatPasDiagT_B.Cat_temperature_moy_DSR,
                                  (&(Cat_temperature_bkpt_map[0])), 15U);
              /*-MD localLookUpTable2D_f = Cat_fac_inc_map[iRowIndex1+16*iColumnIndex1];*/
			 /*-MA*/
             localLookUpTable2D_f = Cat_fac_inc_map[iColumnIndex1][iRowIndex1];
            }

            /* DataTypeDuplicate Block: '<S178>/Data Type Duplicate2'
             *
             * Regarding '<S178>/Data Type Duplicate2':
             *   Unused code path elimination
             */

            /* Switch: '<S174>/Switch5' incorporates:
             *  Constant: '<S174>/Cat_degradation_inc_idle'
             *  Constant: '<S174>/Cat_degradation_inc_idle_gas'
             */
            if (localNot_k) {
              locallocalSwitch1_a_idx = Cat_degradation_inc_idle_gas;
            } else {
              locallocalSwitch1_a_idx = Cat_degradation_inc_idle;
            }

            /* Sum: '<S174>/INC' incorporates:
             *  DataTypeConversion: '<S174>/DTConv_Single_To_UFix_2'
             *  DataTypeConversion: '<S174>/DTConv_Single_To_UFix_5'
             *  Lookup2D: '<S178>/Look-Up Table (2-D)'
             *  Product: '<S179>/Divide'
             */
            localUnitDelay_ai += (((Float32)locallocalSwitch1_a_idx) *
                                  9.999999776E-003F) * (((Float32)
              localLookUpTable2D_f) * 0.01171875F);
          } else {
            /* Lookup2D: '<S180>/Look-Up Table (2-D)'
             * About '<S180>/Look-Up Table (2-D)':
             * Input0  Data Type:  Fixed Point    U16  2^-16
             * Input1  Data Type:  Fixed Point    U16  2^-5  Bias -50.0
             * Output0 Data Type:  Fixed Point    U8  2^-7  FSlope 1.5
             * Lookup Method: Below
             *
             * Row Data    parameter uses the same data type and scaling as Input0
             * Column Data parameter uses the same data type and scaling as Input1
             * Table Data  parameter uses the same data type and scaling as Output0
             */
            {
              UInt32 iRowIndex1, iColumnIndex1;
              BINARYSEARCH_U16_iL( &(iRowIndex1),
                                  CatPasDiagT_B.Cat_debit_gaz_moy_DSR,
                                  (&(Cat_pumped_gas_bkpt_map[0])), 15U);
              BINARYSEARCH_U16_iL( &(iColumnIndex1),
                                  CatPasDiagT_B.Cat_temperature_moy_DSR,
                                  (&(Cat_temperature_bkpt_map[0])), 15U);
              /*-MD localLookUpTable2D_l = Cat_fac_dec_map[iRowIndex1+16*iColumnIndex1];*/
			  /*-MA*/
			  localLookUpTable2D_l = Cat_fac_dec_map[iColumnIndex1][iRowIndex1];
            }

            /* DataTypeDuplicate Block: '<S180>/Data Type Duplicate2'
             *
             * Regarding '<S180>/Data Type Duplicate2':
             *   Unused code path elimination
             */

            /* Switch: '<S175>/Switch1' incorporates:
             *  Constant: '<S175>/Cat_degradation_dec_idle'
             *  Constant: '<S175>/Cat_degradation_dec_idle_gas'
             */
            if (localNot_k) {
              locallocalSwitch1_a_idx = Cat_degradation_dec_idle_gas;
            } else {
              locallocalSwitch1_a_idx = Cat_degradation_dec_idle;
            }

            /* Sum: '<S175>/INC1' incorporates:
             *  DataTypeConversion: '<S175>/DTConv_Single_To_UFix_3'
             *  DataTypeConversion: '<S175>/DTConv_Single_To_UFix_4'
             *  Lookup2D: '<S180>/Look-Up Table (2-D)'
             *  Product: '<S181>/Divide'
             */
            localUnitDelay_ai -= (((Float32)locallocalSwitch1_a_idx) *
                                  9.999999776E-003F) * (((Float32)
              localLookUpTable2D_l) * 0.01171875F);
          }

          /* Product: '<S176>/Product4' incorporates:
           *  Constant: '<S176>/offset'
           *  Constant: '<S176>/one_on_slope'
           *  Sum: '<S176>/Add1'
           */
          localUnitDelay_ai *= 100.0F;

          /* Switch: '<S176>/Switch1' incorporates:
           *  Constant: '<S176>/offset2'
           *  Constant: '<S176>/offset3'
           *  Constant: '<S176>/offset4'
           *  RelationalOperator: '<S176>/Relational Operator'
           *  Sum: '<S176>/Add3'
           *  Sum: '<S176>/Add4'
           */
          if (localUnitDelay_ai >= 0.0F) {
            localUnitDelay_ai += 0.5F;
          } else {
            localUnitDelay_ai -= 0.5F;
          }

          /* DataTypeConversion: '<S176>/OutDTConv' */
          if (localUnitDelay_ai < 32768.0F) {
            if (localUnitDelay_ai >= -32768.0F) {
              localOutDTConv_m = (SInt16)localUnitDelay_ai;
            } else {
              localOutDTConv_m = MIN_int16_T;
            }
          } else {
            localOutDTConv_m = MAX_int16_T;
          }

          /* S-Function (sfun_autosar_extras_irv_read_write): '<S159>/autosar_irv_write11' */

          /* S-Function Block: <S159>/autosar_irv_write11 */
          Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
            (localOutDTConv_m);

          /* SignalConversion: '<S177>/copy' */
          Cat_degradation_count_idle = localOutDTConv_m;

          /* S-Function (sfun_autosar_extras_dsm_read_write): '<S177>/autosar_testpoint1' */

          /* S-Function Block: <S177>/autosar_testpoint1 */
        }

        /* end of Outputs for SubSystem: '<S151>/02_Compteur_diag_ralenti' */

        /* Logic: '<S151>/Logical Operator' */
        Cat_diagnostic_passif = !Cat_diagnostic_ralenti;

        /* Outputs for enable SubSystem: '<S151>/03_Compteur_diag_passif' incorporates:
         *  EnablePort: '<S160>/Cat_diagnostic_passif'
         */
        if (Cat_diagnostic_passif) {
          /* DataTypeConversion: '<S160>/DTConv_Single_To_UFix_1' incorporates:
           *  S-Function (sfun_autosar_extras_irv_read_write): '<S160>/autosar_irv_read3'
           */
          localUnitDelay_ai = ((Float32)
                               Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv
                               ()) * 9.999999776E-003F;

          /* If: '<S160>/If' incorporates:
           *  ActionPort: '<S183>/Action Port'
           *  ActionPort: '<S184>/Action Port'
           *  SubSystem: '<S160>/F01_If'
           *  SubSystem: '<S160>/F02_Else'
           */
          if (Seuil_obd_depasse) {
            /* Lookup2D: '<S187>/Look-Up Table (2-D)'
             * About '<S187>/Look-Up Table (2-D)':
             * Input0  Data Type:  Fixed Point    U16  2^-16
             * Input1  Data Type:  Fixed Point    U16  2^-5  Bias -50.0
             * Output0 Data Type:  Fixed Point    U8  2^-7  FSlope 1.5
             * Lookup Method: Below
             *
             * Row Data    parameter uses the same data type and scaling as Input0
             * Column Data parameter uses the same data type and scaling as Input1
             * Table Data  parameter uses the same data type and scaling as Output0
             */
            {
              UInt32 iRowIndex1, iColumnIndex1;
              BINARYSEARCH_U16_iL( &(iRowIndex1),
                                  CatPasDiagT_B.Cat_debit_gaz_moy_DSR,
                                  (&(Cat_pumped_gas_bkpt_map[0])), 15U);
              BINARYSEARCH_U16_iL( &(iColumnIndex1),
                                  CatPasDiagT_B.Cat_temperature_moy_DSR,
                                  (&(Cat_temperature_bkpt_map[0])), 15U);
              /*-MD localLookUpTable2D_a = Cat_fac_inc_map[iRowIndex1+16*iColumnIndex1];*/
		      /*-MA*/
			  localLookUpTable2D_a = Cat_fac_inc_map[iColumnIndex1][iRowIndex1];
            }

            /* DataTypeDuplicate Block: '<S187>/Data Type Duplicate2'
             *
             * Regarding '<S187>/Data Type Duplicate2':
             *   Unused code path elimination
             */

            /* Switch: '<S183>/Switch2' incorporates:
             *  Constant: '<S183>/Cat_degradation_inc'
             *  Constant: '<S183>/Cat_degradation_inc_gas'
             */
            if (localNot_k) {
              locallocalSwitch1_a_idx = Cat_degradation_inc_gas;
            } else {
              locallocalSwitch1_a_idx = Cat_degradation_inc;
            }

            /* Sum: '<S183>/INC' incorporates:
             *  DataTypeConversion: '<S183>/DTConv_Single_To_UFix_2'
             *  DataTypeConversion: '<S183>/DTConv_Single_To_UFix_4'
             *  Lookup2D: '<S187>/Look-Up Table (2-D)'
             *  Product: '<S188>/Divide'
             */
            localUnitDelay_ai += (((Float32)locallocalSwitch1_a_idx) *
                                  9.999999776E-003F) * (((Float32)
              localLookUpTable2D_a) * 0.01171875F);
          } else {
            /* Lookup2D: '<S189>/Look-Up Table (2-D)'
             * About '<S189>/Look-Up Table (2-D)':
             * Input0  Data Type:  Fixed Point    U16  2^-16
             * Input1  Data Type:  Fixed Point    U16  2^-5  Bias -50.0
             * Output0 Data Type:  Fixed Point    U8  2^-7  FSlope 1.5
             * Lookup Method: Below
             *
             * Row Data    parameter uses the same data type and scaling as Input0
             * Column Data parameter uses the same data type and scaling as Input1
             * Table Data  parameter uses the same data type and scaling as Output0
             */
            {
              UInt32 iRowIndex1, iColumnIndex1;
              BINARYSEARCH_U16_iL( &(iRowIndex1),
                                  CatPasDiagT_B.Cat_debit_gaz_moy_DSR,
                                  (&(Cat_pumped_gas_bkpt_map[0])), 15U);
              BINARYSEARCH_U16_iL( &(iColumnIndex1),
                                  CatPasDiagT_B.Cat_temperature_moy_DSR,
                                  (&(Cat_temperature_bkpt_map[0])), 15U);
              /*-MD localLookUpTable2D_d = Cat_fac_dec_map[iRowIndex1+16*iColumnIndex1];*/
			  /*-MA*/
			  localLookUpTable2D_d = Cat_fac_dec_map[iColumnIndex1][iRowIndex1];
            }

            /* DataTypeDuplicate Block: '<S189>/Data Type Duplicate2'
             *
             * Regarding '<S189>/Data Type Duplicate2':
             *   Unused code path elimination
             */

            /* Switch: '<S184>/Switch1' incorporates:
             *  Constant: '<S184>/Cat_degradation_dec'
             *  Constant: '<S184>/Cat_degradation_dec_gas'
             */
            if (localNot_k) {
              locallocalSwitch1_a_idx = Cat_degradation_dec_gas;
            } else {
              locallocalSwitch1_a_idx = Cat_degradation_dec;
            }

            /* Sum: '<S184>/DEC' incorporates:
             *  DataTypeConversion: '<S184>/DTConv_Single_To_UFix_3'
             *  DataTypeConversion: '<S184>/DTConv_Single_To_UFix_5'
             *  Lookup2D: '<S189>/Look-Up Table (2-D)'
             *  Product: '<S190>/Divide'
             */
            localUnitDelay_ai -= (((Float32)locallocalSwitch1_a_idx) *
                                  9.999999776E-003F) * (((Float32)
              localLookUpTable2D_d) * 0.01171875F);
          }

          /* Product: '<S185>/Product4' incorporates:
           *  Constant: '<S185>/offset'
           *  Constant: '<S185>/one_on_slope'
           *  Sum: '<S185>/Add1'
           */
          localUnitDelay_ai *= 100.0F;

          /* Switch: '<S185>/Switch1' incorporates:
           *  Constant: '<S185>/offset2'
           *  Constant: '<S185>/offset3'
           *  Constant: '<S185>/offset4'
           *  RelationalOperator: '<S185>/Relational Operator'
           *  Sum: '<S185>/Add3'
           *  Sum: '<S185>/Add4'
           */
          if (localUnitDelay_ai >= 0.0F) {
            localUnitDelay_ai += 0.5F;
          } else {
            localUnitDelay_ai -= 0.5F;
          }

          /* DataTypeConversion: '<S185>/OutDTConv' */
          if (localUnitDelay_ai < 32768.0F) {
            if (localUnitDelay_ai >= -32768.0F) {
              localOutDTConv_j = (SInt16)localUnitDelay_ai;
            } else {
              localOutDTConv_j = MIN_int16_T;
            }
          } else {
            localOutDTConv_j = MAX_int16_T;
          }

          /* S-Function (sfun_autosar_extras_irv_read_write): '<S160>/autosar_irv_write11' */

          /* S-Function Block: <S160>/autosar_irv_write11 */
          Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv
            (localOutDTConv_j);

          /* SignalConversion: '<S186>/copy' */
          Cat_degradation_count_IRV_MP = localOutDTConv_j;

          /* S-Function (sfun_autosar_extras_dsm_read_write): '<S186>/autosar_testpoint1' */

          /* S-Function Block: <S186>/autosar_testpoint1 */
        }

        /* end of Outputs for SubSystem: '<S151>/03_Compteur_diag_passif' */

        /* Sum: '<S151>/Sum' incorporates:
         *  Constant: '<S151>/ConstVal'
         *  S-Function (sfun_autosar_extras_irv_read_write): '<S151>/autosar_irv_read12'
         */
        localSwitch4 =
          Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_calcul_count_irv() + 1;
        if (((UInt32)localSwitch4) > 255U) {
          localSum_n = MAX_uint8_T;
        } else {
          localSum_n = (UInt8)localSwitch4;
        }

        /* S-Function (sfun_autosar_extras_irv_read_write): '<S151>/autosar_irv_write12' */

        /* S-Function Block: <S151>/autosar_irv_write12 */
        Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_calcul_count_irv(localSum_n);

        /* SignalConversion: '<S161>/copy' */
        Cat_calcul_count_IRV_MP = localSum_n;

        /* S-Function (sfun_autosar_extras_dsm_read_write): '<S161>/autosar_testpoint1' */

        /* S-Function Block: <S161>/autosar_testpoint1 */
      }

      /* end of Outputs for SubSystem: '<S141>/02_Compteur_degradation' */
    }

    /* end of Outputs for SubSystem: '<S139>/02_Degradation' */
  }

  /* end of Outputs for SubSystem: '<S11>/01_Puissance_degradation' */
  /* '<S21>:1:18' */

  /* Outputs for atomic SubSystem: '<S12>/00_calc_passif_mode06' */

  /* Constant: '<S191>/CatMon_facMaxPas_Obd6Mod_C' */
  CatMon_facMaxPas_Obd6Mod = CatMon_facMaxPas_Obd6Mod_C;

  /* Sum: '<S191>/Add1' incorporates:
   *  Constant: '<S191>/CatMon_facMinPas_Obd6Mod_C'
   *  Constant: '<S191>/CatMon_facMinStep_Obd6Mod_C'
   */
  localSwitch4 = CatMon_facMinPas_Obd6Mod_C - CatMon_facMinStep_Obd6Mod_C;
  if (localSwitch4 <= 0) {
    locallocalSwitch_0 = 0U;
  } else {
    locallocalSwitch_0 = (UInt16)localSwitch4;
  }

  /* Sum: '<S191>/Add2' incorporates:
   *  Constant: '<S191>/CatMon_facMinPas_Obd6Mod_C_2'
   *  Constant: '<S191>/CatMon_facMinStep_Obd6Mod_C_1'
   */
  localSwitch2 = (UInt32)(CatMon_facMinPas_Obd6Mod_C +
    CatMon_facMinStep_Obd6Mod_C);
  if (localSwitch2 > 65535U) {
    locallocalAdd2_i = MAX_uint16_T;
  } else {
    locallocalAdd2_i = (UInt16)localSwitch2;
  }

  /* Switch: '<S191>/Switch1' incorporates:
   *  Logic: '<S191>/Logical Operator6'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S191>/autosar_irv_read'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S191>/autosar_irv_read1'
   */
  if (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_irv() ||
      Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv()) {
    CatMon_facMesPas_Obd6Mod = locallocalSwitch_0;
  } else {
    CatMon_facMesPas_Obd6Mod = locallocalAdd2_i;
  }

  /* Constant: '<S191>/CatMon_facMinPas_Obd6Mod_C_1' */
  CatMon_facMinPas_Obd6Mod = CatMon_facMinPas_Obd6Mod_C;

  /* end of Outputs for SubSystem: '<S12>/00_calc_passif_mode06' */

  /* RelationalOperator: '<S12>/Relational Operator2' incorporates:
   *  Constant: '<S12>/Ext_stGasMod_SC'
   */
  localSwitch2_fa = (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG ==
                     Ext_stGasMod_SC);

  /* Outputs for atomic SubSystem: '<S12>/01_calc_intrusif_mode06' */

  /* Switch: '<S193>/Switch2' incorporates:
   *  Constant: '<S193>/CatMon_mO2StgIniGas_Obd6Mod_C'
   *  Constant: '<S193>/CatMon_mO2StgIni_Obd6Mod_C'
   */
  if (localSwitch2_fa) {
    locallocalSwitch_0 = CatMon_mO2StgIniGas_Obd6Mod_C;
  } else {
    locallocalSwitch_0 = CatMon_mO2StgIni_Obd6Mod_C;
  }

  /* Switch: '<S193>/Switch1' incorporates:
   *  Constant: '<S193>/CatMon_mO2MaxGas_Obd6Mod'
   *  Constant: '<S193>/CatMon_mO2Max_Obd6Mod'
   */
  if (localSwitch2_fa) {
    locallocalSwitch1_a_idx = CatMon_mO2MaxGas_Obd6Mod;
  } else {
    locallocalSwitch1_a_idx = CatMon_mO2Max_Obd6Mod;
  }

  /* If: '<S197>/If2' incorporates:
   *  ActionPort: '<S203>/Action Port'
   *  ActionPort: '<S204>/Action Port'
   *  Constant: '<S197>/Constant7'
   *  RelationalOperator: '<S197>/Relational Operator'
   *  SubSystem: '<S197>/If Action Subsystem2'
   *  SubSystem: '<S197>/If Action Subsystem3'
   */
  if (locallocalSwitch_0 == 0) {
    /* Constant: '<S203>/Byp_Fonction_SC' */
    CatMon_facMaxIntr_Obd6Mod = 256U;
  } else {
    /* Product: '<S204>/Divide1' */
    localSwitch2 = div_u32((UInt32)(locallocalSwitch1_a_idx << 14), (UInt32)
      locallocalSwitch_0);
    if (localSwitch2 > 65535U) {
      CatMon_facMaxIntr_Obd6Mod = MAX_uint16_T;
    } else {
      CatMon_facMaxIntr_Obd6Mod = (UInt16)localSwitch2;
    }
  }

  /* If: '<S198>/If2' incorporates:
   *  ActionPort: '<S207>/Action Port'
   *  ActionPort: '<S208>/Action Port'
   *  Constant: '<S198>/Constant7'
   *  RelationalOperator: '<S198>/Relational Operator'
   *  SubSystem: '<S198>/If Action Subsystem2'
   *  SubSystem: '<S198>/If Action Subsystem3'
   */
  if (locallocalSwitch_0 == 0) {
    /* Constant: '<S207>/Byp_Fonction_SC' */
    locallocalSwitch1_a_idx = 64U;
  } else {
    /* Product: '<S208>/Divide1' */
    localSwitch2 = div_u32((UInt32)
      (CatPasDiagT_B.TmpSignalConversionAtOxC_mO2Stg << 6), (UInt32)
      locallocalSwitch_0);
    if (localSwitch2 > 65535U) {
      locallocalSwitch1_a_idx = MAX_uint16_T;
    } else {
      locallocalSwitch1_a_idx = (UInt16)localSwitch2;
    }
  }

  /* Switch: '<S193>/Switch3' incorporates:
   *  Constant: '<S193>/OxC_mO2StgThdGas_C'
   *  Constant: '<S193>/OxC_mO2StgThd_C'
   */
  if (localSwitch2_fa) {
    locallocalAdd2_i = OxC_mO2StgThdGas_C;
  } else {
    locallocalAdd2_i = OxC_mO2StgThd_C;
  }

  /* If: '<S199>/If2' incorporates:
   *  ActionPort: '<S211>/Action Port'
   *  ActionPort: '<S212>/Action Port'
   *  Constant: '<S199>/Constant7'
   *  RelationalOperator: '<S199>/Relational Operator'
   *  SubSystem: '<S199>/If Action Subsystem2'
   *  SubSystem: '<S199>/If Action Subsystem3'
   */
  if (locallocalSwitch_0 == 0) {
    /* Constant: '<S211>/Byp_Fonction_SC' */
    CatMon_facMinIntr_Obd6Mod = 256U;
  } else {
    /* Product: '<S212>/Divide1' */
    localSwitch2 = div_u32((UInt32)(locallocalAdd2_i << 8), (UInt32)
      locallocalSwitch_0);
    if (localSwitch2 > 65535U) {
      CatMon_facMinIntr_Obd6Mod = MAX_uint16_T;
    } else {
      CatMon_facMinIntr_Obd6Mod = (UInt16)localSwitch2;
    }
  }

  /* Switch: '<S193>/Switch4' incorporates:
   *  UnitDelay: '<S200>/Unit Delay'
   */
  if (CatPasDiagT_B.TmpSignalConversionAtOxC_bMon_d) {
    CatMon_facMesIntr_Obd6Mod = (UInt16)(locallocalSwitch1_a_idx << 2U);
  } else {
    CatMon_facMesIntr_Obd6Mod = CatPasDiagT_DWork.UnitDelay_DSTATE_h;
  }

  /* Update for UnitDelay: '<S200>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_h = CatMon_facMesIntr_Obd6Mod;

  /* end of Outputs for SubSystem: '<S12>/01_calc_intrusif_mode06' */

  /* Outputs for atomic SubSystem: '<S12>/00_envoi_mode06' */

  /* Logic: '<S192>/Logical Operator4' incorporates:
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S192>/autosar_irv_read'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S192>/autosar_irv_read1'
   */
  localNot_k =
    (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_irv() ||
     Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_idle_irv());

  /* Logic: '<S192>/Logical Operator1' */
  localLogicalOperator1_h = !localNot_k;

  /* Logic: '<S192>/Logical Operator3' */
  localLogicalOperator3_p = !CatPasDiagT_B.TmpSignalConversionAtOxC_bMon_d;

  /* UnitDelay: '<S194>/Unit Delay' */
  locallocalSwitch1_a_idx = CatPasDiagT_DWork.UnitDelay_DSTATE_el[0];
  locallocalSwitch_0 = CatPasDiagT_DWork.UnitDelay_DSTATE_el[1];
  locallocalAdd2_i = CatPasDiagT_DWork.UnitDelay_DSTATE_el[2];

  /* Switch: '<S192>/Switch' incorporates:
   *  Logic: '<S192>/Logical Operator2'
   *  UnitDelay: '<S196>/Unit Delay'
   */
  if (CatPasDiagT_B.TmpSignalConversionAtOxC_bMon_d &&
      CatPasDiagT_DWork.UnitDelay_DSTATE_b0) {
    locallocalSwitch_a_idx = CatMon_facMaxIntr_Obd6Mod;
    locallocalSwitch_a_idx_0 = CatMon_facMinIntr_Obd6Mod;
    locallocalSwitch_a_idx_1 = CatMon_facMesIntr_Obd6Mod;
  } else {
    locallocalSwitch_a_idx = CatPasDiagT_DWork.UnitDelay_DSTATE_el[0];
    locallocalSwitch_a_idx_0 = CatPasDiagT_DWork.UnitDelay_DSTATE_el[1];
    locallocalSwitch_a_idx_1 = CatPasDiagT_DWork.UnitDelay_DSTATE_el[2];
  }

  /* Switch: '<S192>/Switch1' incorporates:
   *  Logic: '<S192>/Logical Operator'
   *  UnitDelay: '<S195>/Unit Delay'
   */
  if ((localNot_k) && CatPasDiagT_DWork.UnitDelay_DSTATE_de) {
    locallocalSwitch1_a_idx = CatMon_facMaxPas_Obd6Mod;
    locallocalSwitch_0 = CatMon_facMinPas_Obd6Mod;
    locallocalAdd2_i = CatMon_facMesPas_Obd6Mod;
  }

  /* Switch: '<S192>/Switch2' */
  if (CatMon_bDgoORngPas) {
    locallocalSwitch3_j_idx = locallocalSwitch_a_idx;
    locallocalSwitch3_j_idx_0 = locallocalSwitch_a_idx_0;
    locallocalSwitch3_j_idx_1 = locallocalSwitch_a_idx_1;
  } else {
    locallocalSwitch3_j_idx = locallocalSwitch1_a_idx;
    locallocalSwitch3_j_idx_0 = locallocalSwitch_0;
    locallocalSwitch3_j_idx_1 = locallocalAdd2_i;
  }

  /* Switch: '<S192>/Switch5' incorporates:
   *  Constant: '<S192>/CatMon_bEnaPasGas_C'
   *  Constant: '<S192>/CatMon_bEnaPas_C'
   */
  if (localSwitch2_fa) {
    localNot_k = CatMon_bEnaPasGas_C;
  } else {
    localNot_k = CatMon_bEnaPas_C;
  }

  /* Switch: '<S192>/Switch3' */
  if (!localNot_k) {
    locallocalSwitch3_j_idx = locallocalSwitch_a_idx;
    locallocalSwitch3_j_idx_0 = locallocalSwitch_a_idx_0;
    locallocalSwitch3_j_idx_1 = locallocalSwitch_a_idx_1;
  }

  /* Switch: '<S192>/Switch6' incorporates:
   *  Constant: '<S192>/CatMon_bEnaIntrGas_C'
   *  Constant: '<S192>/CatMon_bEnaIntr_C'
   */
  if (localSwitch2_fa) {
    localNot_k = CatMon_bEnaIntrGas_C;
  } else {
    localNot_k = CatMon_bEnaIntr_C;
  }

  /* Switch: '<S192>/Switch4' */
  if (localNot_k) {
    localSwitch4_f[0] = locallocalSwitch3_j_idx;
    localSwitch4_f[1] = locallocalSwitch3_j_idx_0;
    localSwitch4_f[2] = locallocalSwitch3_j_idx_1;
  } else {
    localSwitch4_f[0] = locallocalSwitch1_a_idx;
    localSwitch4_f[1] = locallocalSwitch_0;
    localSwitch4_f[2] = locallocalAdd2_i;
  }

  /* end of Outputs for SubSystem: '<S12>/00_envoi_mode06' */

  /* SignalConversion: '<S12>/Signal Conversion' */
  CatMon_facMax_Obd6ModRaw = localSwitch4_f[0];

  /* SignalConversion: '<S12>/Signal Conversion1' */
  CatMon_facMin_Obd6ModRaw = localSwitch4_f[1];

  /* SignalConversion: '<S12>/Signal Conversion2' */
  CatMon_facMes_Obd6ModRaw = localSwitch4_f[2];

  /* Update for atomic SubSystem: '<S12>/00_envoi_mode06' */

  /* Update for UnitDelay: '<S195>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_de = localLogicalOperator1_h;

  /* Update for UnitDelay: '<S196>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_b0 = localLogicalOperator3_p;

  /* Update for UnitDelay: '<S194>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_el[0] = localSwitch4_f[0];
  CatPasDiagT_DWork.UnitDelay_DSTATE_el[1] = localSwitch4_f[1];
  CatPasDiagT_DWork.UnitDelay_DSTATE_el[2] = localSwitch4_f[2];

  /* end of Update for SubSystem: '<S12>/00_envoi_mode06' */
  /* '<S21>:1:20' */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_read' */

  /* S-Function Block: <S13>/autosar_irv_read */
  localautosar_irv_read_n =
    Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_cycle_end_irv();

  /* Logic: '<S13>/Logical Operator6' incorporates:
   *  Logic: '<S13>/Logical Operator7'
   *  UnitDelay: '<S214>/Unit Delay'
   */
  Cat_reinit_degrad_count = ((localautosar_irv_read_n) &&
    (!CatPasDiagT_DWork.UnitDelay_DSTATE_nh));

  /* Outputs for enable SubSystem: '<S13>/02_Reinit_degrad_count' incorporates:
   *  EnablePort: '<S213>/Cat_reinit_degrad_count'
   */
  if (Cat_reinit_degrad_count) {
    /* Logic: '<S213>/Logical Operator2' incorporates:
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S213>/autosar_irv_read'
     */
    localNot_k =
      !Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_irv();

    /* Logic: '<S213>/Logical Operator3' incorporates:
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S213>/autosar_irv_read1'
     */
    localSwitch2_fa =
      !Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv();

    /* Switch: '<S213>/Switch5' incorporates:
     *  Constant: '<S213>/Cat_diag_continu_manu_inh'
     *  Constant: '<S213>/Cat_diag_continu_manu_inh_gas'
     *  Constant: '<S213>/Ext_stGasMod_SC'
     *  RelationalOperator: '<S213>/Relational Operator4'
     */
    if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
      localLogicalOperator3_j = Cat_diag_continu_manu_inh_gas;
    } else {
      localLogicalOperator3_j = Cat_diag_continu_manu_inh;
    }

    /* Switch: '<S213>/Switch2' incorporates:
     *  Constant: '<S213>/ConstVal'
     *  Logic: '<S213>/Logical Operator1'
     *  Logic: '<S213>/Logical Operator5'
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S213>/autosar_irv_read2'
     */
    if (((localNot_k) && (localSwitch2_fa)) && (!localLogicalOperator3_j)) {
      localSwitch2_l = 0;
    } else {
      localSwitch2_l =
        Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv();
    }

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S213>/autosar_irv_write11' */

    /* S-Function Block: <S213>/autosar_irv_write11 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_irv
      (localSwitch2_l);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S216>/autosar_testpoint1' */

    /* S-Function Block: <S216>/autosar_testpoint1 */
    Cat_degradation_count_IRV_MP = localSwitch2_l;
  }

  /* end of Outputs for SubSystem: '<S13>/02_Reinit_degrad_count' */

  /* Update for UnitDelay: '<S214>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_nh = localautosar_irv_read_n;

  /* '<S21>:1:22' */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S14>/autosar_irv_read' */

  /* S-Function Block: <S14>/autosar_irv_read */
  localautosar_irv_read =
    Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diag_cycle_end_idle_irv();

  /* Logic: '<S14>/Logical Operator9' incorporates:
   *  Logic: '<S14>/Logical Operator10'
   *  UnitDelay: '<S218>/Unit Delay'
   */
  Cat_reinit_degrad_count_idle = ((localautosar_irv_read) &&
    (!CatPasDiagT_DWork.UnitDelay_DSTATE_ko));

  /* Outputs for enable SubSystem: '<S14>/02_Reinit_degrad_count_idle' incorporates:
   *  EnablePort: '<S217>/Cat_reinit_degrad_count_idle'
   */
  if (Cat_reinit_degrad_count_idle) {
    /* Logic: '<S217>/Logical Operator2' incorporates:
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S217>/autosar_irv_read1'
     */
    localNot_k =
      !Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv();

    /* Switch: '<S217>/Switch5' incorporates:
     *  Constant: '<S217>/Cat_diag_continu_manu_inh_idle'
     *  Constant: '<S217>/Cat_diag_continu_manu_inh_idle_g'
     *  Constant: '<S217>/Ext_stGasMod_SC'
     *  RelationalOperator: '<S217>/Relational Operator1'
     */
    if (CatPasDiagT_B.TmpSignalConversionAtExt_stSysG == Ext_stGasMod_SC) {
      localSwitch2_fa = Cat_diag_continu_manu_inh_idle_g;
    } else {
      localSwitch2_fa = Cat_diag_continu_manu_inh_idle;
    }

    /* Switch: '<S217>/Switch2' incorporates:
     *  Constant: '<S217>/ConstVal'
     *  Logic: '<S217>/Logical Operator1'
     *  Logic: '<S217>/Logical Operator5'
     *  S-Function (sfun_autosar_extras_irv_read_write): '<S217>/autosar_irv_read2'
     */
    if ((localNot_k) && (!localSwitch2_fa)) {
      localSwitch2_f = 0;
    } else {
      localSwitch2_f =
        Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv();
    }

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S217>/autosar_irv_write11' */

    /* S-Function Block: <S217>/autosar_irv_write11 */
    Rte_IrvWrite_RE_CatMon_SdlMid_CatPasDiag_Cat_degradation_count_idle_irv
      (localSwitch2_f);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S220>/autosar_testpoint1' */

    /* S-Function Block: <S220>/autosar_testpoint1 */
    Cat_degradation_count_idle = localSwitch2_f;
  }

  /* end of Outputs for SubSystem: '<S14>/02_Reinit_degrad_count_idle' */

  /* Update for UnitDelay: '<S218>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_ko = localautosar_irv_read;

  /* '<S21>:1:24' */

  /* Logic: '<S16>/Logical Operator1' incorporates:
   *  Logic: '<S16>/Logical Operator'
   */
  localLogicalOperator4_j =
    !(((((((CatPasDiagT_B.TmpSignalConversionAtGDU_bEn_iq &&
            CatPasDiagT_B.TmpSignalConversionAtGDU_bEndDi) &&
           CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_k) &&
          CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_i) &&
         CatPasDiagT_B.TmpSignalConversionAtGDU_bEn_kt) &&
        CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_f) &&
       CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_l) &&
      CatPasDiagT_B.TmpSignalConversionAtGDU_bEnd_a);

  /* Logic: '<S16>/Logical Operator3' incorporates:
   *  Constant: '<S16>/CatMon_bAcvSeqORngCat_C'
   *  Constant: '<S16>/GDU_ST_PRESENT'
   *  Logic: '<S16>/Logical Operator2'
   *  RelationalOperator: '<S16>/Relational Operator1'
   */
  localNot_k = (((((((((CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_p ==
                        GDU_ST_PRESENT) ||
                       (CatPasDiagT_B.TmpSignalConversionAtGDU_stDgoO ==
                        GDU_ST_PRESENT)) ||
                      (CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_l ==
                       GDU_ST_PRESENT)) ||
                     (CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_d ==
                      GDU_ST_PRESENT)) ||
                    (CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_o ==
                     GDU_ST_PRESENT)) ||
                   (CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_j ==
                    GDU_ST_PRESENT)) ||
                  (CatPasDiagT_B.TmpSignalConversionAtGDU_stD_or ==
                   GDU_ST_PRESENT)) ||
                 (CatPasDiagT_B.TmpSignalConversionAtGDU_stDg_m ==
                  GDU_ST_PRESENT)) && CatMon_bAcvSeqORngCat_C);

  /* Logic: '<S16>/Logical Operator4' incorporates:
   *  UnitDelay: '<S222>/Unit Delay'
   */
  localRelationalOperator3_m = (CatPasDiagT_DWork.UnitDelay_DSTATE_h3 ||
    (localLogicalOperator4_j));

  /* Switch: '<S16>/Switch10' incorporates:
   *  Constant: '<S16>/ConstVal_7'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_read1'
   */
  if (localNot_k) {
    localSwitch2_fa = FALSE;
  } else {
    localSwitch2_fa =
      Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv();
  }

  /* Switch: '<S16>/Switch5' incorporates:
   *  Constant: '<S16>/ConstVal'
   */
  if (Cat_conditions_diagnostic_idle) {
    CatMon_bDgoORngPasIdle = localSwitch2_fa;
  } else {
    CatMon_bDgoORngPasIdle = FALSE;
  }

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/ConstVal_3'
   */
  if (localNot_k) {
    localSwitch2_fa = FALSE;
  } else {
    localSwitch2_fa = CatPasDiagT_B.TmpSignalConversionAtCatMon_bDg;
  }

  /* Switch: '<S16>/Switch4' incorporates:
   *  Constant: '<S16>/ConstVal_5'
   */
  if (!CatPasDiagT_B.TmpSignalConversionAtOxC_bMonEn) {
    localSwitch2_fa = FALSE;
  }

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S16>/ConstVal_2'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_read4'
   */
  if (localNot_k) {
    localNot_k = FALSE;
  } else {
    localNot_k = Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_irv
      ();
  }

  /* Switch: '<S16>/Switch3' incorporates:
   *  Constant: '<S16>/ConstVal_4'
   */
  if (Cat_conditions_diagnostic) {
    CatMon_bDgoORngPas = localNot_k;
  } else {
    CatMon_bDgoORngPas = FALSE;
  }

  /* Switch: '<S16>/Switch6' */
  if (!CatPasDiagT_B.LogicalOperator1) {
    localSwitch2_fa = CatMon_bDgoORngPas;
  }

  /* Logic: '<S16>/Logical Operator5' */
  localSwitch1_gu = (CatMon_bDgoORngPasIdle || (localSwitch2_fa));

  /* SignalConversion: '<S16>/Signal Conversion1' */
  CatMon_bMonRunORngPas = Cat_conditions_diagnostic;

  /* SignalConversion: '<S16>/Signal Conversion2' */
  CatMon_bMonRunORngPasIdle = Cat_conditions_diagnostic_idle;

  /* Logic: '<S16>/Logical Operator6' */
  CatMon_bMonRunORngRaw_Cat = ((CatPasDiagT_B.TmpSignalConversionAtCatMon_b_c ||
    CatMon_bMonRunORngPas) || CatMon_bMonRunORngPasIdle);

  /* Switch: '<S16>/Switch7' incorporates:
   *  Constant: '<S16>/CatMon_bAcvSeqORngCat_C'
   *  Constant: '<S16>/ConstVal_1'
   */
  if (CatMon_bAcvSeqORngCat_C) {
    localSwitch2_fa = localLogicalOperator4_j;
  } else {
    localSwitch2_fa = FALSE;
  }

  /* Switch: '<S16>/Switch8' incorporates:
   *  Logic: '<S16>/Logical Operator9'
   *  UnitDelay: '<S221>/Unit Delay'
   */
  if (CatPasDiagT_B.LogicalOperator1) {
    localNot_k = !CatPasDiagT_B.TmpSignalConversionAtCatMon_bMo;
  } else {
    localNot_k = CatPasDiagT_DWork.UnitDelay_DSTATE_ez;
  }

  /* Logic: '<S16>/Logical Operator7' incorporates:
   *  Logic: '<S16>/Logical Operator8'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_read2'
   */
  CatMon_bMonWaitORngRaw_Cat = ((localSwitch2_fa) &&
    (!(Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_etat_defectueux_idle_irv() ||
       (localNot_k))));

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S16>/autosar_irv_read3' */

  /* S-Function Block: <S16>/autosar_irv_read3 */
  localautosar_irv_read3_k =
    Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_effectue_irv();

  /* Update for UnitDelay: '<S222>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_h3 = localRelationalOperator3_m;

  /* Update for UnitDelay: '<S221>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_ez = localautosar_irv_read3_k;

  /* '<S21>:1:26' */

  /* Logic: '<S15>/Logical Operator5' incorporates:
   *  Constant: '<S15>/CAT_INIT'
   *  RelationalOperator: '<S15>/Relational Operator4'
   *  S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_read5'
   */
  localNot_k =
    (Rte_IrvRead_RE_CatMon_SdlMid_CatPasDiag_Cat_diagnostic_autorise_irv() &&
     (Cat_diagnostic_state != CAT_INIT));

  /* '<S21>:1:28' */

  /* Switch: '<S18>/Switch2' incorporates:
   *  Constant: '<S18>/CatMon_bInhMonWait_Cat_C'
   *  Constant: '<S18>/DIAG_DISPO'
   */
  if (CatMon_bInhMonWait_Cat_C) {
    localSwitch2_fa = DIAG_DISPO;
  } else {
    localSwitch2_fa = CatMon_bMonWaitORngRaw_Cat;
  }

  /* Switch: '<S18>/Switch3' incorporates:
   *  Constant: '<S18>/CatMon_bInhMonWait_Cat_C_1'
   *  Logic: '<S18>/Logical Operator1'
   *  Logic: '<S18>/Logical Operator2'
   */
  if (CatMon_bInhMonWait_Cat_C) {
    localLogicalOperator3_j = ((!CatMon_bMonWaitORngRaw_Cat) &&
      CatMon_bMonRunORngRaw_Cat);
  } else {
    localLogicalOperator3_j = CatMon_bMonRunORngRaw_Cat;
  }

  /* UnitDelay: '<S242>/Unit Delay' */
  locallocalSwitch1_a_idx = CatPasDiagT_DWork.UnitDelay_DSTATE_f1[0];
  locallocalSwitch_0 = CatPasDiagT_DWork.UnitDelay_DSTATE_f1[1];
  locallocalAdd2_i = CatPasDiagT_DWork.UnitDelay_DSTATE_f1[2];

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<S18>/CatMon_bAcvEuro6Cat_C'
   *  Logic: '<S18>/Logical Operator5'
   */
  if (!(CatMon_bAcvEuro6Cat_C && (localSwitch1_gu))) {
    locallocalSwitch1_a_idx = CatMon_facMax_Obd6ModRaw;
    locallocalSwitch_0 = CatMon_facMin_Obd6ModRaw;
    locallocalAdd2_i = CatMon_facMes_Obd6ModRaw;
  }

  /* Switch: '<S18>/Switch5' */
  if (localNot) {
    locallocalSwitch1_a_idx = CatMon_facMax_Obd6ModRaw;
    locallocalSwitch_0 = CatMon_facMin_Obd6ModRaw;
    locallocalAdd2_i = CatMon_facMes_Obd6ModRaw;
  }

  /* Update for UnitDelay: '<S242>/Unit Delay' */
  CatPasDiagT_DWork.UnitDelay_DSTATE_f1[0] = locallocalSwitch1_a_idx;
  CatPasDiagT_DWork.UnitDelay_DSTATE_f1[1] = locallocalSwitch_0;
  CatPasDiagT_DWork.UnitDelay_DSTATE_f1[2] = locallocalAdd2_i;

  /* '<S21>:1:30' */

  /* If: '<S243>/If' incorporates:
   *  ActionPort: '<S244>/Action Port'
   *  Constant: '<S19>/CATPASDIAGT_ACTIVE_BYP_C'
   *  SubSystem: '<S243>/if_s'
   */
  if (!CATPASDIAGT_ACTIVE_BYP_C) {
    /* If: '<S244>/If' incorporates:
     *  ActionPort: '<S245>/Action Port'
     *  ActionPort: '<S246>/Action Port'
     *  SubSystem: '<S244>/if_s1'
     *  SubSystem: '<S244>/if_s2'
     */
    if (localLogicalOperator3_j) {
      /* If: '<S245>/If1' incorporates:
       *  ActionPort: '<S247>/Action Port'
       *  ActionPort: '<S248>/Action Port'
       *  SubSystem: '<S245>/if_s1'
       *  SubSystem: '<S245>/if_s2'
       */
      if (localSwitch2_fa) {
        CatPasDiagT_if_s1();
      } else {
        /* If: '<S248>/If' incorporates:
         *  ActionPort: '<S249>/Action Port'
         *  ActionPort: '<S250>/Action Port'
         *  SubSystem: '<S248>/if_s1'
         *  SubSystem: '<S248>/if_s2'
         */
        if (localSwitch1_gu) {
          /* S-Function (sfun_autosar_clientop): '<S249>/AutosarServer' incorporates:
           *  Constant: '<S249>/Constant1'
           */
          Rte_Call_R_CatMon_ORng_Cat_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
        } else {
          /* S-Function (sfun_autosar_clientop): '<S250>/AutosarServer' incorporates:
           *  Constant: '<S250>/Constant2'
           */
          Rte_Call_R_CatMon_ORng_Cat_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
        }
      }
    } else {
      CatPasDiagT_if_s1();
    }
  }

  /* '<S21>:1:32' */

  /* If: '<S251>/If' incorporates:
   *  ActionPort: '<S252>/Action Port'
   *  Constant: '<S20>/CATPASDIAGT_ACTIVE_BYP_C'
   *  SubSystem: '<S251>/if_s'
   */
  if (!CATPASDIAGT_ACTIVE_BYP_C) {
    /* If: '<S252>/If' incorporates:
     *  ActionPort: '<S253>/Action Port'
     *  ActionPort: '<S254>/Action Port'
     *  SignalConversion: '<S9>/Signal Conversion10'
     *  SubSystem: '<S252>/if_s1'
     *  SubSystem: '<S252>/if_s2'
     */
    if (localSwitch3_jm) {
      /* If: '<S253>/If1' incorporates:
       *  ActionPort: '<S255>/Action Port'
       *  ActionPort: '<S256>/Action Port'
       *  Constant: '<S20>/DIAG_DISPO'
       *  SubSystem: '<S253>/if_s1'
       *  SubSystem: '<S253>/if_s2'
       */
      if (DIAG_DISPO) {
        CatPasDiagT_if_s1_j();
      } else {
        /* If: '<S256>/If' incorporates:
         *  ActionPort: '<S257>/Action Port'
         *  ActionPort: '<S258>/Action Port'
         *  SignalConversion: '<S9>/Signal Conversion1'
         *  SubSystem: '<S256>/if_s1'
         *  SubSystem: '<S256>/if_s2'
         */
        if (localLogicalOperator5_lz) {
          /* S-Function (sfun_autosar_clientop): '<S257>/AutosarServer' incorporates:
           *  Constant: '<S257>/Constant1'
           */
          Rte_Call_R_CatMon_ORng_CatApv_SetEventStatus
            (DEM_EVENT_STATUS_PREFAILED);
        } else {
          /* S-Function (sfun_autosar_clientop): '<S258>/AutosarServer' incorporates:
           *  Constant: '<S258>/Constant2'
           */
          Rte_Call_R_CatMon_ORng_CatApv_SetEventStatus
            (DEM_EVENT_STATUS_PREPASSED);
        }
      }
    } else {
      CatPasDiagT_if_s1_j();
    }
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Byp_Fonction_SC'
   *  Constant: '<S30>/Int_BypC'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    localRelationalOperator3_m = CatMon_bAcvSeqMemORng_Cat_B;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCatMon_bAcvSeqMemORng_CatInport2' */
  Rte_Write_P_CatMon_bAcvSeqMemORng_Cat_CatMon_bAcvSeqMemORng_Cat
    (localRelationalOperator3_m);

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Byp_Fonction_SC'
   *  Constant: '<S29>/Int_BypC'
   *  SignalConversion: '<S16>/Signal Conversion'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    localLogicalOperator4_j = CatMon_bAcvSeqORng_Cat_B;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCatMon_bAcvSeqORng_CatInport2' */
  Rte_Write_P_CatMon_bAcvSeqORng_Cat_CatMon_bAcvSeqORng_Cat
    (localLogicalOperator4_j);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    locallocalSwitch1_a_idx = CatMon_facMax_Obd6Mod_B;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCatMon_facMax_Obd6ModInport2' */
  Rte_Write_P_CatMon_facMax_Obd6Mod_CatMon_facMax_Obd6Mod
    (locallocalSwitch1_a_idx);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Byp_Fonction_SC'
   *  Constant: '<S27>/Int_BypC'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    locallocalSwitch1_a_idx = CatMon_facMes_Obd6Mod_B;
  } else {
    locallocalSwitch1_a_idx = locallocalAdd2_i;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCatMon_facMes_Obd6ModInport2' */
  Rte_Write_P_CatMon_facMes_Obd6Mod_CatMon_facMes_Obd6Mod
    (locallocalSwitch1_a_idx);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Byp_Fonction_SC'
   *  Constant: '<S26>/Int_BypC'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    locallocalSwitch1_a_idx = CatMon_facMin_Obd6Mod_B;
  } else {
    locallocalSwitch1_a_idx = locallocalSwitch_0;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCatMon_facMin_Obd6ModInport2' */
  Rte_Write_P_CatMon_facMin_Obd6Mod_CatMon_facMin_Obd6Mod
    (locallocalSwitch1_a_idx);

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/Byp_Fonction_SC'
   *  Constant: '<S31>/Int_BypC'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    locallocalSwitch1_a_idx = Cat_debit_gaz_moy_B;
  } else {
    locallocalSwitch1_a_idx = CatPasDiagT_B.Cat_debit_gaz_moy_DSR;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCat_debit_gaz_moyInport2' */
  Rte_Write_P_Cat_debit_gaz_moy_Cat_debit_gaz_moy(locallocalSwitch1_a_idx);

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Byp_Fonction_SC'
   *  Constant: '<S28>/Int_BypC'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    localNot_k = Cat_mon_inhibe_fast_tracking_B;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCat_mon_inhibe_fast_trackingInport2' */
  Rte_Write_P_Cat_mon_inhibe_fast_tracking_Cat_mon_inhibe_fast_tracking
    (localNot_k);

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Byp_Fonction_SC'
   *  Constant: '<S32>/Int_BypC'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    locallocalSwitch1_a_idx = Cat_temperature_moy_B;
  } else {
    locallocalSwitch1_a_idx = CatPasDiagT_B.Cat_temperature_moy_DSR;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtCat_temperature_moyInport2' */
  Rte_Write_P_Cat_temperature_moy_Cat_temperature_moy(locallocalSwitch1_a_idx);

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Byp_Fonction_SC'
   *  Constant: '<S25>/Int_BypC'
   */
  if (CATPASDIAGT_ACTIVE_BYP_C) {
    localNot_k = OxC_bMonReqORngIntr_B;
  } else {
    localNot_k = CatPasDiagT_B.LogicalOperator1;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtOxC_bMonReqORngIntrInport2' */
  Rte_Write_P_OxC_bMonReqORngIntr_OxC_bMonReqORngIntr(localNot_k);
}

/* Model initialize function */
void RE_CatPasDiag_Init(void)
{
  /* Registration code */

  /* block I/O */
  {
    CatPasDiagT_B.TmpSignalConversionAtCat_temper = 1600U;
    CatPasDiagT_B.Cat_temperature_moy_DSR = 1600U;
    CatPasDiagT_B.TmpSignalConversionAtTemperatur = 64U;
    CatPasDiagT_B.TmpSignalConversionAtTemperat_g = 64U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  RE_CatMon_EveRst_CatPasDiag_Start();
  RE_CatMon_SdlMid_CatPasDiag_Start();

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   */
  RE_CatMon_SdlMid_CatPasDiag_Init();
}

#define CatPasDiagT_STOP_SEC_CODE
#include "CatPasDiagT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
