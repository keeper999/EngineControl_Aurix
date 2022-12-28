/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : CatAcvDiagT                                             */
/* !Description     : CatAcvDiagT Software Component                          */
/*                                                                            */
/* !Module          : CatAcvDiagT                                             */
/* !Description     : CatAcvDiagT Software Component                          */
/*                                                                            */
/* !File            : CatAcvDiagT.c                                           */
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
/* !Reference       : PTS_DOC_5059959 / 06                                    */
/* !Reference       : PTS_DOC_5060314 / 07                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : CatAcvDiagT_AUTOSAR.mdl                               */
/*   Root subsystem   : /CatAcvDiagT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/SWC_PSA/3.1/CATMON/CATACVDIAGT/CatA$*/
/* $Revision::   1.25                                                        $*/
/* $Author::   etsasson                               $$Date::   08 Nov 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "CatAcvDiagT.h"
#include "CatAcvDiagT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S357>/2_Automate_diag_cata_intrusif1' */
#define IN_CAT_DIAG_INTRU_CATA_READY   (1U)
#define IN_CAT_DIAG_INTRU_OSC_INTEGRATI (2U)
#define IN_CAT_DIAG_INTRU_START        (3U)
#define IN_CAT_DIAG_INTRU_SWITCH_LAMBDA (4U)
#define IN_LSMON_ITRSV_SEN02DS_DIAG    (1U)
#define IN_LSMON_ITRSV_SEN02DS_DIAG_NOK (1U)
#define IN_LSMON_ITRSV_SEN02DS_DIAG_OK (2U)
#define IN_LSMON_ITRSV_SEN02DS_DIAG_RUN (3U)
#define IN_LSMON_ITRSV_SEN02DS_WAIT_RES (4U)
#define IN_NO_ACTIVE_CHILD             (0U)
#define IN_OXC_MON_RUNNING             (2U)
#define IN_OXC_MON_WAIT                (3U)
#define IN_OXC_MON_WAITING_TO_START    (4U)
#define event_FIN_INTEGRATION          (0)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "CatAcvDiagT_MemMap.h"

SInt32 _sfEvent_;

/* Block signals (auto storage) */
BlockIO_CatAcvDiagT CatAcvDiagT_B;

/* Block states (auto storage) */
D_Work_CatAcvDiagT CatAcvDiagT_DWork;

/* Forward declaration for local functions */
static void CatA_End_integration_management(void);
static void CatAcvDiagT_OXC_MON_RUNNING(void);

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "CatAcvDiagT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define CATACVDIAGT_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define CATACVDIAGT_VEMSRTLIBT_MINOR_VERSION_REQ 15
#define CATACVDIAGT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define CATACVDIAGT_VEMSRTLIBT_VERSION_REQ (CATACVDIAGT_VEMSRTLIBT_PATCH_VERSION_REQ + CATACVDIAGT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + CATACVDIAGT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if CATACVDIAGT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define CatAcvDiagT_START_SEC_CODE
#include "CatAcvDiagT_MemMap.h"

void CatAcvDiagT_ASYNC1(int controlPortIdx)
{
}

void CatAcvDiagT_ASYNC2(int controlPortIdx)
{
}

void CatAcvDiagT_ASYNC3(int controlPortIdx)
{
}

void CatAcvDiagT_ASYNC4(int controlPortIdx)
{
}

void CatAcvDiagT_ASYNC5(int controlPortIdx)
{
}

/* Start for exported function: RE_CatMon_EveRst_CatAcvDiag */
void RE_CatMon_EveRst_CatAcvDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/01_Initialisation1'
   *
   * Block requirements for '<S1>/01_Initialisation1':
   *  1. SubSystem "01_Initialisation1" !Trace_To : VEMS_R_09_02846_001.03 ;
   */
}

/* Output and update for exported function: RE_CatMon_EveRst_CatAcvDiag */
void RE_CatMon_EveRst_CatAcvDiag(void)
{
  Boolean localSwitch1;
  UInt8 localSwitch_j;
  UInt16 localSwitch;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/01_Initialisation1'
   *
   * Block requirements for '<S1>/01_Initialisation1':
   *  1. SubSystem "01_Initialisation1" !Trace_To : VEMS_R_09_02846_001.03 ;
   */

  /* user code (Output function Body for TID9) */
  RE_Init();

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/Byp_Fonction_SC1'
   *  Constant: '<S27>/Int_BypC1'
   *  Constant: '<S6>/ConstVal'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localSwitch1 = OxC_bMonRunORngIntr_B;
  } else {
    localSwitch1 = FALSE;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_bMonRunORngIntrInport2' */
  Rte_Write_P_OxC_bMonRunORngIntr_OxC_bMonRunORngIntr(localSwitch1);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_bMonRunORngIntr_irvInport2' */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_bMonRunORngIntr_irv(FALSE);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Byp_Fonction_SC'
   *  Constant: '<S23>/Int_BypC'
   *  Constant: '<S6>/ConstVal_10'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localSwitch1 = OxC_bMonEndORngIntr_B;
  } else {
    localSwitch1 = FALSE;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_bMonEndORngIntrInport2' */
  Rte_Write_P_OxC_bMonEndORngIntr_OxC_bMonEndORngIntr(localSwitch1);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   *  Constant: '<S6>/ConstVal_8'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localSwitch = OxC_rMixtReqMonIntr_B;
  } else {
    localSwitch = 8916U;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_rMixtReqMonIntrInport2' */
  Rte_Write_P_OxC_rMixtReqMonIntr_OxC_rMixtReqMonIntr(localSwitch);

  /* SignalConversion: '<S16>/copy' incorporates:
   *  Constant: '<S6>/ConstVal_1'
   */
  OxC_ctMonORngIntr_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S16>/autosar_testpoint1' */

  /* S-Function Block: <S16>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_ctMonORngIntr_irvInport2' incorporates:
   *  Constant: '<S6>/ConstVal_1'
   *  SignalConversion: '<S6>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_ctMonORngIntr_irv(0U);

  /* SignalConversion: '<S15>/copy' incorporates:
   *  Constant: '<S6>/ConstVal_2'
   */
  OxC_mO2StgSumEstim_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S15>/autosar_testpoint1' */

  /* S-Function Block: <S15>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_mO2StgSumEstim_irvInport2' incorporates:
   *  Constant: '<S6>/ConstVal_2'
   *  SignalConversion: '<S6>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_mO2StgSumEstim_irv(0U);

  /* SignalConversion: '<S17>/copy' incorporates:
   *  Constant: '<S6>/ConstVal_3'
   */
  OxC_mO2StgTotEstim_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S17>/autosar_testpoint1' */

  /* S-Function Block: <S17>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_mO2StgTotEstim_irvInport2' incorporates:
   *  Constant: '<S6>/ConstVal_3'
   *  SignalConversion: '<S6>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_mO2StgTotEstim_irv(0U);

  /* SignalConversion: '<S18>/copy' incorporates:
   *  Constant: '<S6>/OXC_MON_WAITING_TO_START'
   */
  OxC_stMonIntrAcv_IRV_MP = OXC_MON_WAITING_TO_START;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S18>/autosar_testpoint1' */

  /* S-Function Block: <S18>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_stMonIntrAcv_irvInport2' incorporates:
   *  Constant: '<S6>/OXC_MON_WAITING_TO_START'
   *  SignalConversion: '<S6>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_stMonIntrAcv_irv
    (OXC_MON_WAITING_TO_START);

  /* SignalConversion: '<S19>/copy' incorporates:
   *  Constant: '<S6>/CAT_DIAG_INTRU_START'
   */
  OxC_stMonIntrRun_IRV_MP = CAT_DIAG_INTRU_START;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S19>/autosar_testpoint1' */

  /* S-Function Block: <S19>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_stMonIntrRun_irvInport2' incorporates:
   *  Constant: '<S6>/CAT_DIAG_INTRU_START'
   *  SignalConversion: '<S6>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_stMonIntrRun_irv
    (CAT_DIAG_INTRU_START);

  /* SignalConversion: '<S20>/copy' incorporates:
   *  Constant: '<S6>/ConstVal_7'
   */
  OxC_tiTmrScdnMonORngIntr_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S20>/autosar_testpoint1' */

  /* S-Function Block: <S20>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_tiTmrScdnMonORngIntr_irvInport2' incorporates:
   *  Constant: '<S6>/ConstVal_7'
   *  SignalConversion: '<S6>/Signal Conversion8'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_tiTmrScdnMonORngIntr_irv(0U);

  /* SignalConversion: '<S22>/copy' incorporates:
   *  Constant: '<S6>/OxC_tiTmrIniMonORngIntr_C'
   */
  OxC_tiTmrIniMonORngIntr_IRV_MP = OxC_tiTmrIniMonORngIntr_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S22>/autosar_testpoint1' */

  /* S-Function Block: <S22>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_tiTmrIniMonORngIntr_irvInport2' incorporates:
   *  Constant: '<S6>/OxC_tiTmrIniMonORngIntr_C'
   *  SignalConversion: '<S6>/Signal Conversion9'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_tiTmrIniMonORngIntr_irv
    (OxC_tiTmrIniMonORngIntr_C);

  /* SignalConversion: '<S21>/copy' incorporates:
   *  Constant: '<S6>/OxC_tiPha1MaxDlyProt_C'
   */
  OxC_tiDlyMaxProt_rMixtPha1 = OxC_tiPha1MaxDlyProt_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S21>/autosar_testpoint1' */

  /* S-Function Block: <S21>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_tiDlyMaxProt_rMixtPha1_irvInport2' incorporates:
   *  Constant: '<S6>/OxC_tiPha1MaxDlyProt_C'
   *  SignalConversion: '<S6>/Signal Conversion10'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_tiDlyMaxProt_rMixtPha1_irv
    (OxC_tiPha1MaxDlyProt_C);

  /* SignalConversion: '<S11>/copy' incorporates:
   *  Constant: '<S6>/OxC_tiTmrMonStabSlowCdn_C'
   */
  OxC_tiTmrMonStabSlowCdn_IRV_MP = OxC_tiTmrMonStabSlowCdn_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S11>/autosar_testpoint1' */

  /* S-Function Block: <S11>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_tiTmrMonStabSlowCdn_irvInport2' incorporates:
   *  Constant: '<S6>/OxC_tiTmrMonStabSlowCdn_C'
   *  SignalConversion: '<S6>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_tiTmrMonStabSlowCdn_irv
    (OxC_tiTmrMonStabSlowCdn_C);

  /* DataTypeConversion: '<S6>/Data Type Conversion7' incorporates:
   *  Constant: '<S6>/OxC_tiTmrMonStabFastCdn_C'
   */
  localSwitch = OxC_tiTmrMonStabFastCdn_C;

  /* SignalConversion: '<S10>/copy' */
  OxC_tiTmrMonStabFastCdn_IRV_MP = localSwitch;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S10>/autosar_testpoint1' */

  /* S-Function Block: <S10>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_tiTmrMonStabFastCdn_irvInport2' incorporates:
   *  SignalConversion: '<S6>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_tiTmrMonStabFastCdn_irv
    (localSwitch);

  /* SignalConversion: '<S12>/copy' incorporates:
   *  Constant: '<S6>/ConstVal_4'
   */
  LsMon_tiItrsvSenO2DsDiag_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S12>/autosar_testpoint1' */

  /* S-Function Block: <S12>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtLsMon_tiItrsvSenO2DsDiag_irvInport2' incorporates:
   *  Constant: '<S6>/ConstVal_4'
   *  SignalConversion: '<S6>/Signal Conversion11'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_LsMon_tiItrsvSenO2DsDiag_irv(0U);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Byp_Fonction_SC'
   *  Constant: '<S26>/Int_BypC'
   *  Constant: '<S6>/LSMON_ITRSV_SENO2DS_DIAG_INIT'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localSwitch_j = LsMon_stItrsvSenO2DsDiag_B;
  } else {
    localSwitch_j = LSMON_ITRSV_SENO2DS_DIAG_INIT;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtLsMon_stItrsvSenO2DsDiagInport2' */
  Rte_Write_P_LsMon_stItrsvSenO2DsDiag_LsMon_stItrsvSenO2DsDiag(localSwitch_j);

  /* SignalConversion: '<S13>/copy' incorporates:
   *  Constant: '<S6>/ConstVal_5'
   */
  LsMon_tiItrsvWaitSenO2DsDiag = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S13>/autosar_testpoint1' */

  /* S-Function Block: <S13>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtLsMon_tiItrsvWaitSenO2DsDiag_irvInport2' incorporates:
   *  Constant: '<S6>/ConstVal_5'
   *  SignalConversion: '<S6>/Signal Conversion12'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_LsMon_tiItrsvWaitSenO2DsDiag_irv(0U);

  /* SignalConversion: '<S14>/copy' incorporates:
   *  Constant: '<S6>/ConstVal_6'
   */
  OxC_bMonORngIntrStabCdn_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S14>/autosar_testpoint1' */

  /* S-Function Block: <S14>/autosar_testpoint1 */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_bMonORngIntrStabCdn_irvInport2' incorporates:
   *  Constant: '<S6>/ConstVal_6'
   *  SignalConversion: '<S6>/Signal Conversion13'
   */
  Rte_IrvWrite_RE_CatMon_EveRst_CatAcvDiag_OxC_bMonORngIntrStabCdn_irv(FALSE);

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Byp_Fonction_SC'
   *  Constant: '<S25>/Int_BypC'
   *  Constant: '<S6>/ConstVal_9'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localSwitch1 = OxC_bRlamAdpReq_B;
  } else {
    localSwitch1 = FALSE;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtOxC_bRlamAdpReqInport2' */
  Rte_Write_P_OxC_bRlamAdpReq_OxC_bRlamAdpReq(localSwitch1);
}

/* Function for Stateflow: '<S357>/2_Automate_diag_cata_intrusif1' */
static void CatA_End_integration_management(void)
{
  SInt32 localsf_previousEvent;
  Boolean localsf_guard;
  Boolean localsf_guard_0;

  /* Graphical Function 'End_integration_management': '<S382>:6' */
  /* Transition: '<S382>:29' */
  localsf_guard = FALSE;
  localsf_guard_0 = FALSE;
  if ((CatAcvDiagT_B.OxC_mO2StgTotEstim >= ((UInt32)OxC_mO2StgMaxTmp)) ||
      ((CatAcvDiagT_B.OxC_mO2StgTotEstim > ((UInt32)OxC_mO2StgMinPlausTmp)) &&
       (((OxC_rMixtPha2Tmp > 1.0F) && (((SInt32)
           CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) == 1)) ||
        ((OxC_rMixtPha2Tmp < 1.0F) && (((SInt32)
           CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) == 0))))) {
    /* Transition: '<S382>:19' */
    CatAcvDiagT_B.OxC_ctMonORngIntr = (UInt8)((UInt32)
      (CatAcvDiagT_B.OxC_ctMonORngIntr + 1));
    CatAcvDiagT_B.OxC_mO2StgSumEstim = CatAcvDiagT_B.OxC_mO2StgSumEstim +
      CatAcvDiagT_B.OxC_mO2StgTotEstim;
    if (CatAcvDiagT_B.OxC_ctMonORngIntr < OxC_ctMinMonORngIntrTmp) {
      /* Transition: '<S382>:22' */
      localsf_guard = TRUE;
    } else if ((CatAcvDiagT_B.OxC_ctMonORngIntr >= OxC_ctMinMonORngIntrTmp) &&
               (CatAcvDiagT_B.OxC_ctMonORngIntr <= OxC_ctMaxMonORngIntrTmp)) {
      /* Transition: '<S382>:25' */
      CatAcvDiagT_B.OxC_mO2StgMvEstim = (UInt16)
        (CatAcvDiagT_B.OxC_mO2StgSumEstim / ((UInt32)
          CatAcvDiagT_B.OxC_ctMonORngIntr));
      localsf_guard = TRUE;
    } else {
      localsf_guard_0 = TRUE;
    }
  } else {
    localsf_guard_0 = TRUE;
  }

  if ((localsf_guard_0) && ((CatAcvDiagT_B.OxC_mO2StgTotEstim <= ((UInt32)
         OxC_mO2StgMinPlausTmp)) && (((OxC_rMixtPha2Tmp > 1.0F) && (((SInt32)
           CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) == 1)) ||
        ((OxC_rMixtPha2Tmp < 1.0F) && (((SInt32)
           CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) == 0))))) {
    /* Transition: '<S382>:15' */
    localsf_guard = TRUE;
  }

  if (localsf_guard) {
    /* Transition: '<S382>:17' */
    OxC_bEndInt = TRUE;
    localsf_previousEvent = _sfEvent_;
    _sfEvent_ = event_FIN_INTEGRATION;
    CatAcvDiagT_OXC_MON_RUNNING();
    _sfEvent_ = localsf_previousEvent;
  }
}

/* Function for Stateflow: '<S357>/2_Automate_diag_cata_intrusif1' */
static void CatAcvDiagT_OXC_MON_RUNNING(void)
{
  /* During 'OXC_MON_RUNNING': '<S382>:7' */
  if (CatAcvDiagT_DWork.is_c1_CatAcvDiagT == IN_OXC_MON_RUNNING) {
    if (_sfEvent_ == event_FIN_INTEGRATION) {
      /* Transition: '<S382>:28' */
      /* Exit 'CAT_DIAG_INTRU_CATA_READY': '<S382>:3' */
      CatAcvDiagT_DWork.is_OXC_MON_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;

      /* Exit 'CAT_DIAG_INTRU_OSC_INTEGRATION': '<S382>:5' */
      /* Exit 'CAT_DIAG_INTRU_START': '<S382>:2' */
      /* Exit 'CAT_DIAG_INTRU_SWITCH_LAMBDA': '<S382>:4' */
      /* Exit 'OXC_MON_RUNNING': '<S382>:7' */
      CatAcvDiagT_DWork.is_c1_CatAcvDiagT = (UInt8)IN_NO_ACTIVE_CHILD;

      /* Entry 'OXC_MON_WAITING_TO_START': '<S382>:1' */
      if (CatAcvDiagT_DWork.is_c1_CatAcvDiagT != IN_OXC_MON_WAITING_TO_START) {
        CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAITING_TO_START;
        CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAITING_TO_START;
        CatAcvDiagT_B.OxC_bMonRunORngIntr_o = FALSE;
        CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = OxC_tiTmrIniMonORngIntrTmp;
        OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F + CatAcvDiagT_B.DataTypeConversion8;
        CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
          OxC_rFbLsclFil_ItrsvSenO2Strt;
        CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_INIT;
      }
    } else if ((((SInt32)CatAcvDiagT_B.TmpSignalConversionAtOxC_bMon_l) == 0) ||
               (((SInt32)OxC_bAcvMonItrsv) == 0)) {
      /* Transition: '<S382>:20' */
      /* Exit 'CAT_DIAG_INTRU_CATA_READY': '<S382>:3' */
      CatAcvDiagT_DWork.is_OXC_MON_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;

      /* Exit 'CAT_DIAG_INTRU_OSC_INTEGRATION': '<S382>:5' */
      /* Exit 'CAT_DIAG_INTRU_START': '<S382>:2' */
      /* Exit 'CAT_DIAG_INTRU_SWITCH_LAMBDA': '<S382>:4' */
      /* Exit 'OXC_MON_RUNNING': '<S382>:7' */
      /* Entry 'OXC_MON_WAITING_TO_START': '<S382>:1' */
      CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAITING_TO_START;
      CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAITING_TO_START;
      CatAcvDiagT_B.OxC_bMonRunORngIntr_o = FALSE;
      CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = OxC_tiTmrIniMonORngIntrTmp;
      OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F + CatAcvDiagT_B.DataTypeConversion8;
      CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
        OxC_rFbLsclFil_ItrsvSenO2Strt;
      CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_INIT;
    } else {
      switch (CatAcvDiagT_DWork.is_OXC_MON_RUNNING) {
       case IN_CAT_DIAG_INTRU_CATA_READY:
        /* During 'CAT_DIAG_INTRU_CATA_READY': '<S382>:3' */
        if ((((SInt32)OxC_bAcvMonItrsv) == 1) &&
            (CatAcvDiagT_B.OxC_tiTmrScdnMonORngIntr < CatMon_SampleTiFast_SC)) {
          /* Transition: '<S382>:21' */
          /* Exit 'CAT_DIAG_INTRU_CATA_READY': '<S382>:3' */
          /* Entry 'CAT_DIAG_INTRU_SWITCH_LAMBDA': '<S382>:4' */
          CatAcvDiagT_DWork.is_OXC_MON_RUNNING = IN_CAT_DIAG_INTRU_SWITCH_LAMBDA;
          CatAcvDiagT_B.OxC_stMonIntrRun = CAT_DIAG_INTRU_SWITCH_LAMBDA;
          CatAcvDiagT_B.OxC_rMixtReqMonIntr = OxC_rMixtPha2Tmp *
            OxC_rFbLsclFil_rMonItrsvStrt;
          OxC_tiPha2ChgDly = OxC_tiPha2ChgMaxDly_C;
        } else if ((((OxC_rMixtPha1Tmp > 1.0F) && ((((SInt32)
            CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p) == 0) || (((SInt32)
            CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) == 0))) ||
                    ((OxC_rMixtPha1Tmp < 1.0F) && ((((SInt32)
            CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p) == 1) || (((SInt32)
            CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) == 1)))) &&
                   (OxC_tiTmrMinMonORngIntr == 0)) {
          /* Transition: '<S382>:16' */
          /* Transition: '<S382>:26' */
          /* Exit 'CAT_DIAG_INTRU_CATA_READY': '<S382>:3' */
          CatAcvDiagT_DWork.is_OXC_MON_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;

          /* Exit 'OXC_MON_RUNNING': '<S382>:7' */
          /* Entry 'OXC_MON_WAITING_TO_START': '<S382>:1' */
          CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAITING_TO_START;
          CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAITING_TO_START;
          CatAcvDiagT_B.OxC_bMonRunORngIntr_o = FALSE;
          CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = OxC_tiTmrIniMonORngIntrTmp;
          OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F +
            CatAcvDiagT_B.DataTypeConversion8;
          CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
            OxC_rFbLsclFil_ItrsvSenO2Strt;
          CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_INIT;
        } else {
          CatAcvDiagT_B.OxC_tiTmrScdnMonORngIntr = (UInt16)rt_MAX(0,
            CatAcvDiagT_B.OxC_tiTmrScdnMonORngIntr - CatMon_SampleTiFast_SC);
          OxC_tiTmrMinMonORngIntr = (UInt16)rt_MAX(0, OxC_tiTmrMinMonORngIntr
            - CatMon_SampleTiFast_SC);
        }
        break;

       case IN_CAT_DIAG_INTRU_OSC_INTEGRATI:
        /* During 'CAT_DIAG_INTRU_OSC_INTEGRATION': '<S382>:5' */
        if (CatAcvDiagT_DWork.is_OXC_MON_RUNNING ==
            IN_CAT_DIAG_INTRU_OSC_INTEGRATI) {
          if (((OxC_rMixtPha2Tmp < 1.0F) && (((SInt32)
                 CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p) == 1)) ||
              ((OxC_rMixtPha2Tmp > 1.0F) && (((SInt32)
                 CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p) == 0))) {
            /* Transition: '<S382>:27' */
            /* Transition: '<S382>:26' */
            /* Exit 'CAT_DIAG_INTRU_OSC_INTEGRATION': '<S382>:5' */
            CatAcvDiagT_DWork.is_OXC_MON_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;

            /* Exit 'OXC_MON_RUNNING': '<S382>:7' */
            /* Entry 'OXC_MON_WAITING_TO_START': '<S382>:1' */
            CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAITING_TO_START;
            CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAITING_TO_START;
            CatAcvDiagT_B.OxC_bMonRunORngIntr_o = FALSE;
            CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = OxC_tiTmrIniMonORngIntrTmp;
            OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F +
              CatAcvDiagT_B.DataTypeConversion8;
            CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
              OxC_rFbLsclFil_ItrsvSenO2Strt;
            CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_INIT;
          } else {
            CatAcvDiagT_B.OxC_mO2StgTotEstim = CatAcvDiagT_B.OxC_mO2StgTotEstim
              + ((UInt32)OxC_mO2StgEstim);
            CatA_End_integration_management();
          }
        }
        break;

       case IN_CAT_DIAG_INTRU_START:
        /* During 'CAT_DIAG_INTRU_START': '<S382>:2' */
        if (CatAcvDiagT_DWork.is_OXC_MON_RUNNING == IN_CAT_DIAG_INTRU_START) {
          if (CatAcvDiagT_B.OxC_tiDlyMaxProt_rMixtPha1_p <
              CatMon_SampleTiFast_SC) {
            /* Transition: '<S382>:14' */
            /* Transition: '<S382>:26' */
            /* Exit 'CAT_DIAG_INTRU_START': '<S382>:2' */
            CatAcvDiagT_DWork.is_OXC_MON_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;

            /* Exit 'OXC_MON_RUNNING': '<S382>:7' */
            /* Entry 'OXC_MON_WAITING_TO_START': '<S382>:1' */
            CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAITING_TO_START;
            CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAITING_TO_START;
            CatAcvDiagT_B.OxC_bMonRunORngIntr_o = FALSE;
            CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = OxC_tiTmrIniMonORngIntrTmp;
            OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F +
              CatAcvDiagT_B.DataTypeConversion8;
            CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
              OxC_rFbLsclFil_ItrsvSenO2Strt;
            CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_INIT;
          } else if ((((SInt32)OxC_bAcvMonItrsv) == 1) && ((((OxC_rMixtPha1Tmp >
            1.0F) && (((SInt32)CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p) ==
                      1)) && (((SInt32)
                               CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) ==
                              1)) || (((OxC_rMixtPha1Tmp < 1.0F) && (((SInt32)
              CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p) == 0)) &&
                       (((SInt32)CatAcvDiagT_B.TmpSignalConversionAtSonde_rich)
                        == 0)))) {
            /* Transition: '<S382>:18' */
            /* Exit 'CAT_DIAG_INTRU_START': '<S382>:2' */
            /* Entry 'CAT_DIAG_INTRU_CATA_READY': '<S382>:3' */
            CatAcvDiagT_DWork.is_OXC_MON_RUNNING = IN_CAT_DIAG_INTRU_CATA_READY;
            CatAcvDiagT_B.OxC_stMonIntrRun = CAT_DIAG_INTRU_CATA_READY;
            CatAcvDiagT_B.OxC_tiTmrScdnMonORngIntr = OxC_tiTmrScdnMonORngIntrIni;
            OxC_tiTmrMinMonORngIntr = OxC_tiTmrMinMonORngIntrIni_C;
          } else {
            CatAcvDiagT_B.OxC_tiDlyMaxProt_rMixtPha1_p = (UInt16)rt_MAX(0,
              CatAcvDiagT_B.OxC_tiDlyMaxProt_rMixtPha1_p -
              CatMon_SampleTiFast_SC);
          }
        }
        break;

       case IN_CAT_DIAG_INTRU_SWITCH_LAMBDA:
        /* During 'CAT_DIAG_INTRU_SWITCH_LAMBDA': '<S382>:4' */
        if (CatAcvDiagT_DWork.is_OXC_MON_RUNNING ==
            IN_CAT_DIAG_INTRU_SWITCH_LAMBDA) {
          if ((((SInt32)OxC_bAcvMonItrsv) == 1) && (((OxC_rMixtPha2Tmp < 1.0F) &&
                (((SInt32)CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p) == 0))
               || ((OxC_rMixtPha2Tmp > 1.0F) && (((SInt32)
                  CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p) == 1)))) {
            /* Transition: '<S382>:24' */
            /* Exit 'CAT_DIAG_INTRU_SWITCH_LAMBDA': '<S382>:4' */
            /* Entry 'CAT_DIAG_INTRU_OSC_INTEGRATION': '<S382>:5' */
            CatAcvDiagT_DWork.is_OXC_MON_RUNNING =
              IN_CAT_DIAG_INTRU_OSC_INTEGRATI;
            CatAcvDiagT_B.OxC_stMonIntrRun = CAT_DIAG_INTRU_OSC_INTEGRATION;
            CatAcvDiagT_B.OxC_mO2StgTotEstim = 0U;
            OxC_bEndInt = FALSE;
          } else if ((((OxC_rMixtPha1Tmp > 1.0F) && (((SInt32)
              CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) == 0)) ||
                      ((OxC_rMixtPha1Tmp < 1.0F) && (((SInt32)
              CatAcvDiagT_B.TmpSignalConversionAtSonde_rich) == 1))) ||
                     (OxC_tiPha2ChgDly == 0)) {
            /* Transition: '<S382>:31' */
            /* Transition: '<S382>:26' */
            /* Exit 'CAT_DIAG_INTRU_SWITCH_LAMBDA': '<S382>:4' */
            CatAcvDiagT_DWork.is_OXC_MON_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;

            /* Exit 'OXC_MON_RUNNING': '<S382>:7' */
            /* Entry 'OXC_MON_WAITING_TO_START': '<S382>:1' */
            CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAITING_TO_START;
            CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAITING_TO_START;
            CatAcvDiagT_B.OxC_bMonRunORngIntr_o = FALSE;
            CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = OxC_tiTmrIniMonORngIntrTmp;
            OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F +
              CatAcvDiagT_B.DataTypeConversion8;
            CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
              OxC_rFbLsclFil_ItrsvSenO2Strt;
            CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_INIT;
          } else {
            OxC_tiPha2ChgDly = (UInt16)rt_MAX(0, OxC_tiPha2ChgDly -
              CatMon_SampleTiFast_SC);
          }
        }
        break;

       default:
        CatAcvDiagT_DWork.is_OXC_MON_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;
        break;
      }
    }
  }
}

/* Initial conditions for exported function: RE_CatMon_SdlFast_CatAcvDiag */
void RE_CatMon_SdlFast_CatAcvDiag_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/CatMon_SdlFast_CatAcvDiag1'
   *
   * Block requirements for '<S1>/CatMon_SdlFast_CatAcvDiag1':
   *  1. SubSystem "CatMon_SdlFast_CatAcvDiag1" !Trace_To : VEMS_R_09_02846_001.03 ;
   */

  /* InitializeConditions for Embedded MATLAB: '<S9>/Embedded MATLAB Function' incorporates:
   *  InitializeConditions for SubSystem: '<S9>/011_Trig_Init_CmbModTran1'
   *  InitializeConditions for SubSystem: '<S9>/04_Calcul_osc_et_diagnostic1'
   *  InitializeConditions for SubSystem: '<S9>/05_DataStoreManagement'
   */

  /* InitializeConditions for atomic SubSystem: '<S328>/02_sorties_GD' */

  /* InitializeConditions for UnitDelay: '<S406>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_gi = TRUE;

  /* end of InitializeConditions for SubSystem: '<S328>/02_sorties_GD' */
}

/* Start for exported function: RE_CatMon_SdlFast_CatAcvDiag */
void RE_CatMon_SdlFast_CatAcvDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/CatMon_SdlFast_CatAcvDiag1'
   *
   * Block requirements for '<S1>/CatMon_SdlFast_CatAcvDiag1':
   *  1. SubSystem "CatMon_SdlFast_CatAcvDiag1" !Trace_To : VEMS_R_09_02846_001.03 ;
   */
}

/* Output and update for exported function: RE_CatMon_SdlFast_CatAcvDiag */
void RE_CatMon_SdlFast_CatAcvDiag(void)
{
  /* local block i/o variables */
  Boolean localIn;
  Boolean localLogic[2];
  Boolean localIn_d;
  Boolean localLogic_g[2];
  Boolean localMemory;
  Boolean localR;
  UInt8 localLookUpTable2D;
  UInt8 localOxC_ctMonORngIntr_irv_k;
  UInt8 localOxC_stMonIntrAcv_irv_g;
  UInt8 localOxC_stMonIntrRun_irv_k;
  UInt8 localLsMon_stItrsvSenO2DsDiag;
  Float32 localTe;
  UInt32 localAdd;
  Float32 localSwitch2;
  Float32 localSwitch_m0;
  Float32 localSwitch1_c;
  Boolean localRelationalOperator2_n;
  Boolean localRelationalOperator1_k;
  SInt32 localrtmax;
  Boolean localRelationalOperator2_m;
  Boolean localRelationalOperator1_h;
  Float32 localInterpolationUsingPrelooku;
  Float32 localDataTypeConversion1;
  Float32 localDataTypeConversion2;
  Float32 localDataTypeConversion3;
  Float32 localDataTypeConversion4;
  Float32 localfrac[2];
  Float32 localSwitch3;
  UInt32 localAirSys_mfAirMesThrEstim_sw;
  UInt32 localbpIndex[2];
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  UInt16 localTmpSignalConversionAtLSA_l;
  UInt16 localOxC_tiTmrMonStabFastCdn__g;
  UInt16 localLsMon_tiItrsvWaitSenO2Ds_j;
  UInt16 localOxC_tiTmrScdnMonORngIntr_e;
  UInt16 localOxC_tiTmrIniMonORngIntr__j;
  UInt16 localLsMon_tiItrsvSenO2DsDiag_k;
  UInt16 localMerge;
  Boolean localTmpSignalConversionAtOxC_0;
  Boolean localMerge_g;
  Boolean localMerge1_o;
  UInt8 locallocalMinMax1_n;
  UInt16 locallocalMinMax;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/CatMon_SdlFast_CatAcvDiag1'
   *
   * Block requirements for '<S1>/CatMon_SdlFast_CatAcvDiag1':
   *  1. SubSystem "CatMon_SdlFast_CatAcvDiag1" !Trace_To : VEMS_R_09_02846_001.03 ;
   */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_stSysGasOutport2' incorporates:
   *  Inport: '<Root>/Ext_stSysGas'
   */
  Rte_Read_R_Ext_stSysGas_Ext_stSysGas
    (&CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_l);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtLsMon_stItrsvSenO2DsDiag_INPUTOutport2' incorporates:
   *  Inport: '<Root>/LsMon_stItrsvSenO2DsDiag_INPUT'
   */
  Rte_Read_R_LsMon_stItrsvSenO2DsDiag_LsMon_stItrsvSenO2DsDiag
    (&CatAcvDiagT_B.TmpSignalConversionAtLsMon_stIt);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_rMixtReqMonIntr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/OxC_rMixtReqMonIntr_INPUT'
   */
  Rte_Read_R_OxC_rMixtReqMonIntr_OxC_rMixtReqMonIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtOxC_rMixtR);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_bMonEndORngIntr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonEndORngIntr_INPUT'
   */
  Rte_Read_R_OxC_bMonEndORngIntr_OxC_bMonEndORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtOxC_bMo_e5);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_bMonRunORngIntr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonRunORngIntr_INPUT'
   */
  Rte_Read_R_OxC_bMonRunORngIntr_OxC_bMonRunORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtOxC_bMonRu);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtCatMon_bMonRunORngIntr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/CatMon_bMonRunORngIntr_INPUT'
   */
  Rte_Read_R_CatMon_bMonRunORngIntr_CatMon_bMonRunORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtCatMon_bMo);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtCatMon_bDgoORngIntr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/CatMon_bDgoORngIntr_INPUT'
   */
  Rte_Read_R_CatMon_bDgoORngIntr_CatMon_bDgoORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtCatMon_bDg);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtCatMon_bMonWaitORngIntr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/CatMon_bMonWaitORngIntr_INPUT'
   */
  Rte_Read_R_CatMon_bMonWaitORngIntr_CatMon_bMonWaitORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtCatMon_b_e);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_mO2StgMvEstim_INPUTOutport2' incorporates:
   *  Inport: '<Root>/OxC_mO2StgMvEstim_INPUT'
   */
  Rte_Read_R_OxC_mO2StgMvEstim_OxC_mO2StgMvEstim
    (&CatAcvDiagT_B.TmpSignalConversionAtOxC_mO2S_d);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_bMonReqORngIntrOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonReqORngIntr'
   */
  Rte_Read_R_OxC_bMonReqORngIntr_OxC_bMonReqORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtOxC_bMonRe);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_mfAirMesThrEstim_swcOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mfAirMesThrEstim_swc'
   */
  Rte_Read_R_AirSys_mfAirMesThrEstim_swc_AirSys_mfAirMesThrEstim_swc
    (&CatAcvDiagT_B.TmpSignalConversionAtAirSys_m_l);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_tOxCEstimOutport2' incorporates:
   *  Inport: '<Root>/Ext_tOxCEstim'
   */
  Rte_Read_R_Ext_tOxCEstim_Ext_tOxCEstim
    (&CatAcvDiagT_B.TmpSignalConversionAtExt_tOxC_f);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtSonde_riche_avalOutport2' incorporates:
   *  Inport: '<Root>/Sonde_riche_aval'
   */
  Rte_Read_R_Sonde_riche_aval_Sonde_riche_aval
    (&CatAcvDiagT_B.TmpSignalConversionAtSonde_rich);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtSonde_riche_amontOutport2' incorporates:
   *  Inport: '<Root>/Sonde_riche_amont'
   */
  Rte_Read_R_Sonde_riche_amont_Sonde_riche_amont
    (&CatAcvDiagT_B.TmpSignalConversionAtSonde_ri_p);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtLSA_lamUsMesOutport2' incorporates:
   *  Inport: '<Root>/LSA_lamUsMes'
   */
  Rte_Read_R_LSA_lamUsMes_LSA_lamUsMes(&localTmpSignalConversionAtLSA_l);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_bMonEnaORngIntr_irvOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonEnaORngIntr_INPUT'
   */
  Rte_Read_R_OxC_bMonEnaORngIntr_OxC_bMonEnaORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtOxC_bMon_l);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtLsMon_bAcvItrsvSenO2DsDiagOutport2' incorporates:
   *  Inport: '<Root>/LsMon_bAcvItrsvSenO2DsDiag'
   */
  Rte_Read_R_LsMon_bAcvItrsvSenO2DsDiag_LsMon_bAcvItrsvSenO2DsDiag
    (&CatAcvDiagT_B.TmpSignalConversionAtLsMon_bA_d);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTension_sonde_avalOutport2' incorporates:
   *  Inport: '<Root>/Tension_sonde_aval'
   */
  Rte_Read_R_Tension_sonde_aval_Tension_sonde_aval
    (&CatAcvDiagT_B.TmpSignalConversionAtTension_so);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtLsMon_bCaseItrsvSenO2DsDiagOutport2' incorporates:
   *  Inport: '<Root>/LsMon_bCaseItrsvSenO2DsDiag'
   */
  Rte_Read_R_LsMon_bCaseItrsvSenO2DsDiag_LsMon_bCaseItrsvSenO2DsDiag
    (&CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtClef_de_contactOutport2' incorporates:
   *  Inport: '<Root>/Clef_de_contact'
   */
  Rte_Read_R_Clef_de_contact_Clef_de_contact
    (&CatAcvDiagT_B.TmpSignalConversionAtClef_de_co);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFReg_rFbLsclFilOutport2' incorporates:
   *  Inport: '<Root>/AFReg_rFbLsclFil'
   */
  Rte_Read_R_AFReg_rFbLsclFil_AFReg_rFbLsclFil
    (&CatAcvDiagT_B.TmpSignalConversionAtAFReg_rF_i);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtFARSp_prm_bRlamSpAcvOutport2' incorporates:
   *  Inport: '<Root>/FARSp_prm_bRlamSpAcv'
   */
  Rte_Read_R_FARSp_prm_bRlamSpAcv_FARSp_prm_bRlamSpAcv
    (&CatAcvDiagT_B.TmpSignalConversionAtFARSp_prm_);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_bMonRunORngIntrPrevOutport2' */
  localTmpSignalConversionAtOxC_0 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_bMonRunORngIntr_irv();

  /* Embedded MATLAB: '<S9>/Embedded MATLAB Function' incorporates:
   *  SubSystem: '<S9>/011_Trig_Init_CmbModTran1'
   *  SubSystem: '<S9>/04_Calcul_osc_et_diagnostic1'
   *  SubSystem: '<S9>/05_DataStoreManagement'
   */
  /* Embedded MATLAB Function 'CatAcvDiagT/CatMon_SdlFast_CatAcvDiag1/Embedded MATLAB Function': '<S330>:1' */
  /* '<S330>:1:3' */

  /* SignalConversion: '<S329>/Signal Conversion14' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_ctMonORngIntr_irv1Outport2'
   */
  CatAcvDiagT_B.Merge12_o =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_ctMonORngIntr_irv();

  /* SignalConversion: '<S329>/Signal Conversion17' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_mO2StgSumEstim_irv1Outport2'
   */
  CatAcvDiagT_B.Merge3 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_mO2StgSumEstim_irv();

  /* SignalConversion: '<S329>/Signal Conversion9' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_mO2StgTotEstim_irv1Outport2'
   */
  CatAcvDiagT_B.Merge4 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_mO2StgTotEstim_irv();

  /* SignalConversion: '<S329>/Signal Conversion12' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_stMonIntrAcv_irv1Outport2'
   */
  CatAcvDiagT_B.Merge5 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_stMonIntrAcv_irv();

  /* SignalConversion: '<S329>/Signal Conversion7' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_stMonIntrRun_irv1Outport2'
   */
  CatAcvDiagT_B.Merge6_b =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_stMonIntrRun_irv();

  /* SignalConversion: '<S329>/Signal Conversion15' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiTmrIniMonORngIntr_irv1Outport2'
   */
  CatAcvDiagT_B.Merge8 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiTmrIniMonORngIntr_irv();

  /* SignalConversion: '<S329>/Signal Conversion16' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiDlyMaxProt_rMixtPha1_irv1Outport2'
   */
  CatAcvDiagT_B.Merge9 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiDlyMaxProt_rMixtPha1_irv();

  /* SignalConversion: '<S329>/Signal Conversion11' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiTmrScdnMonORngIntr_irv1Outport2'
   */
  CatAcvDiagT_B.Merge7 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiTmrScdnMonORngIntr_irv();

  /* SignalConversion: '<S329>/Signal Conversion5' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtLsMon_tiItrsvSenO2DsDiag_irv1Outport2'
   */
  CatAcvDiagT_B.Merge11 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_LsMon_tiItrsvSenO2DsDiag_irv();

  /* SignalConversion: '<S329>/Signal Conversion1' */
  CatAcvDiagT_B.Merge10_d = CatAcvDiagT_B.TmpSignalConversionAtLsMon_stIt;

  /* SignalConversion: '<S329>/Signal Conversion2' */
  localMerge = CatAcvDiagT_B.TmpSignalConversionAtOxC_rMixtR;

  /* SignalConversion: '<S329>/Signal Conversion18' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiTmrMonStabSlowCdn_irv1Outport2'
   */
  CatAcvDiagT_B.Merge17 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiTmrMonStabSlowCdn_irv();

  /* SignalConversion: '<S329>/Signal Conversion19' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiTmrMonStabFastCdn_irv1Outport2'
   */
  CatAcvDiagT_B.Merge18 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiTmrMonStabFastCdn_irv();

  /* SignalConversion: '<S329>/Signal Conversion20' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtLsMon_tiItrsvWaitSenO2DsDiag_irv1Outport2'
   */
  CatAcvDiagT_B.Merge19 =
    Rte_IrvRead_RE_CatMon_SdlFast_CatAcvDiag_LsMon_tiItrsvWaitSenO2DsDiag_irv();

  /* '<S330>:1:5' */

  /* Outputs for atomic SubSystem: '<S328>/00_Extraire_booleen_prise_en_compte_consigne_diag_catalyseur' */

  /* DataTypeConversion: '<S356>/Data Type Conversion1' incorporates:
   *  Constant: '<S356>/CatMon_SampleTiFast_SC'
   */
  localTe = ((Float32)CatMon_SampleTiFast_SC) * 9.999999776E-003F;

  /* Sum: '<S360>/Add' incorporates:
   *  Constant: '<S356>/OxC_idxRlamSpAcv_C'
   *  Constant: '<S360>/Constant1'
   *  DataTypeConversion: '<S356>/Data Type Conversion5'
   */
  localAdd = ((UInt32)OxC_idxRlamSpAcv_C) - 1U;

  /* Selector: '<S360>/Selector' incorporates:
   *  Constant: '<S360>/Constant'
   *  MinMax: '<S360>/MinMax'
   */
  localIn = CatAcvDiagT_B.TmpSignalConversionAtFARSp_prm_[rt_MIN(localAdd, 19U)];

  /* UnitDelay: '<S362>/Unit Delay' */
  localMemory = CatAcvDiagT_DWork.UnitDelay_DSTATE_j3;

  /* UnitDelay: '<S368>/UnitDelay' */
  localR = CatAcvDiagT_DWork.UnitDelay_b;

  /* MinMax: '<S362>/MinMax1' incorporates:
   *  Constant: '<S356>/OxC_tiDlySdlCord_C'
   *  Constant: '<S362>/Constant1'
   */
  localrtmax = mul_s32_s32_s32_sr10_sat_near(OxC_tiDlySdlCord_C * 41, 25);
  if (localrtmax <= 0) {
    locallocalMinMax1_n = 0U;
  } else if (localrtmax > 255) {
    locallocalMinMax1_n = MAX_uint8_T;
  } else {
    locallocalMinMax1_n = (UInt8)localrtmax;
  }

  /* Sum: '<S362>/Sum2' incorporates:
   *  Constant: '<S362>/Constant6'
   *  Product: '<S362>/Product'
   */
  localSwitch_m0 = (((Float32)locallocalMinMax1_n) * 9.999999776E-003F) +
    (10.0F * localTe);

  /* UnitDelay: '<S367>/Unit Delay' */
  localSwitch2 = CatAcvDiagT_DWork.UnitDelay_DSTATE_py;

  /* Switch: '<S372>/Switch' incorporates:
   *  Constant: '<S362>/Constant3'
   *  RelationalOperator: '<S372>/UpperRelop'
   */
  if (CatAcvDiagT_DWork.UnitDelay_DSTATE_py < 0.0F) {
    localSwitch2 = 0.0F;
  }

  /* Switch: '<S372>/Switch2' incorporates:
   *  RelationalOperator: '<S372>/LowerRelop1'
   */
  if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_py > localSwitch_m0)) {
    localSwitch_m0 = localSwitch2;
  }

  /* Switch: '<S362>/Switch1' incorporates:
   *  Constant: '<S362>/Constant4'
   *  Constant: '<S362>/Constant7'
   *  Logic: '<S362>/Logical Operator2'
   *  Logic: '<S368>/Logical Operator'
   *  Logic: '<S368>/Logical Operator1'
   *  Sum: '<S362>/Sum1'
   */
  if ((localMemory) || ((!localIn) && (localR))) {
    localSwitch1_c = 0.0F;
  } else {
    localSwitch1_c = (localTe + localSwitch_m0) + 2.220446049E-016F;
  }

  /* RelationalOperator: '<S362>/Relational Operator2' */
  localRelationalOperator2_n = (localSwitch1_c >= (((Float32)
    locallocalMinMax1_n) * 9.999999776E-003F));

  /* UnitDelay: '<S369>/UnitDelay' */
  localR = CatAcvDiagT_DWork.UnitDelay_a;

  /* RelationalOperator: '<S362>/Relational Operator1' incorporates:
   *  Constant: '<S362>/Constant2'
   */
  localRelationalOperator1_k = ((locallocalMinMax1_n * 41) == 0);

  /* Switch: '<S362>/Switch' incorporates:
   *  Constant: '<S362>/Constant5'
   *  Logic: '<S362>/Logical Operator1'
   *  Logic: '<S369>/Logical Operator'
   *  Logic: '<S369>/Logical Operator1'
   */
  if (!localRelationalOperator1_k) {
    localR = ((localRelationalOperator2_n) && (!localR));
  } else {
    localR = TRUE;
  }

  /* Memory: '<S366>/Memory' */
  localMemory = CatAcvDiagT_DWork.Memory_PreviousInput_eq;

  /* CombinatorialLogic: '<S366>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localIn != 0);
    rowidx = (rowidx << 1) + (UInt32)(localR != 0);
    rowidx = (rowidx << 1) + (UInt32)(localMemory != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
    localLogic[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
  }

  /* UnitDelay: '<S364>/Unit Delay' */
  localR = CatAcvDiagT_DWork.UnitDelay_DSTATE_lx4;

  /* Logic: '<S361>/Logical Operator' incorporates:
   *  Logic: '<S361>/Logical Operator1'
   */
  localIn_d = ((localTmpSignalConversionAtOxC_0) && (!localR));

  /* UnitDelay: '<S363>/Unit Delay' */
  localR = CatAcvDiagT_DWork.UnitDelay_DSTATE_cy;

  /* UnitDelay: '<S376>/UnitDelay' */
  localMemory = CatAcvDiagT_DWork.UnitDelay_d;

  /* MinMax: '<S363>/MinMax1' incorporates:
   *  Constant: '<S356>/OxC_tiAcvReqDlySdlCord_C'
   *  Constant: '<S363>/Constant1'
   */
  localrtmax = OxC_tiAcvReqDlySdlCord_C;
  if (localrtmax <= 0) {
    locallocalMinMax = 0U;
  } else {
    locallocalMinMax = (UInt16)localrtmax;
  }

  /* Sum: '<S363>/Sum2' incorporates:
   *  Constant: '<S363>/Constant6'
   *  Product: '<S363>/Product'
   */
  localSwitch2 = (((Float32)locallocalMinMax) * 9.999999776E-003F) + (10.0F *
    localTe);

  /* UnitDelay: '<S375>/Unit Delay' */
  localSwitch_m0 = CatAcvDiagT_DWork.UnitDelay_DSTATE_ph;

  /* Switch: '<S380>/Switch' incorporates:
   *  Constant: '<S363>/Constant3'
   *  RelationalOperator: '<S380>/UpperRelop'
   */
  if (CatAcvDiagT_DWork.UnitDelay_DSTATE_ph < 0.0F) {
    localSwitch_m0 = 0.0F;
  }

  /* Switch: '<S380>/Switch2' incorporates:
   *  RelationalOperator: '<S380>/LowerRelop1'
   */
  if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_ph > localSwitch2)) {
    localSwitch2 = localSwitch_m0;
  }

  /* Switch: '<S363>/Switch1' incorporates:
   *  Constant: '<S363>/Constant4'
   *  Constant: '<S363>/Constant7'
   *  Logic: '<S363>/Logical Operator2'
   *  Logic: '<S376>/Logical Operator'
   *  Logic: '<S376>/Logical Operator1'
   *  Sum: '<S363>/Sum1'
   */
  if ((localR) || ((!localIn_d) && (localMemory))) {
    localTe = 0.0F;
  } else {
    localTe = (localTe + localSwitch2) + 2.220446049E-016F;
  }

  /* RelationalOperator: '<S363>/Relational Operator2' */
  localRelationalOperator2_m = (localTe >= (((Float32)locallocalMinMax) *
    9.999999776E-003F));

  /* UnitDelay: '<S377>/UnitDelay' */
  localR = CatAcvDiagT_DWork.UnitDelay_h;

  /* RelationalOperator: '<S363>/Relational Operator1' incorporates:
   *  Constant: '<S363>/Constant2'
   */
  localRelationalOperator1_h = (locallocalMinMax == 0);

  /* Switch: '<S363>/Switch' incorporates:
   *  Constant: '<S363>/Constant5'
   *  Logic: '<S363>/Logical Operator1'
   *  Logic: '<S377>/Logical Operator'
   *  Logic: '<S377>/Logical Operator1'
   */
  if (!localRelationalOperator1_h) {
    localR = ((localRelationalOperator2_m) && (!localR));
  } else {
    localR = TRUE;
  }

  /* Memory: '<S374>/Memory' */
  localMemory = CatAcvDiagT_DWork.Memory_PreviousInput_lc;

  /* CombinatorialLogic: '<S374>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localIn_d != 0);
    rowidx = (rowidx << 1) + (UInt32)(localR != 0);
    rowidx = (rowidx << 1) + (UInt32)(localMemory != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_g[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
    localLogic_g[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
  }

  /* Logic: '<S356>/Logical Operator' */
  OxC_bAcvMonItrsv = ((localLogic[0]) || (localLogic_g[0]));

  /* Update for UnitDelay: '<S362>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_j3 = localRelationalOperator1_k;

  /* Update for UnitDelay: '<S368>/UnitDelay' */
  CatAcvDiagT_DWork.UnitDelay_b = localIn;

  /* Update for UnitDelay: '<S367>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_py = localSwitch1_c;

  /* Update for UnitDelay: '<S369>/UnitDelay' */
  CatAcvDiagT_DWork.UnitDelay_a = localRelationalOperator2_n;

  /* Update for Memory: '<S366>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_eq = localLogic[0];

  /* Update for UnitDelay: '<S364>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_lx4 = localTmpSignalConversionAtOxC_0;

  /* Update for UnitDelay: '<S363>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_cy = localRelationalOperator1_h;

  /* Update for UnitDelay: '<S376>/UnitDelay' */
  CatAcvDiagT_DWork.UnitDelay_d = localIn_d;

  /* Update for UnitDelay: '<S375>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_ph = localTe;

  /* Update for UnitDelay: '<S377>/UnitDelay' */
  CatAcvDiagT_DWork.UnitDelay_h = localRelationalOperator2_m;

  /* Update for Memory: '<S374>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_lc = localLogic_g[0];

  /* end of Outputs for SubSystem: '<S328>/00_Extraire_booleen_prise_en_compte_consigne_diag_catalyseur' */

  /* Outputs for enable SubSystem: '<S328>/01_Calcul_osc_et_diagnostic' incorporates:
   *  EnablePort: '<S357>/Enable'
   *  Logic: '<S328>/Logical Operator'
   *  UnitDelay: '<S359>/Unit Delay'
   */
  if ((CatAcvDiagT_B.TmpSignalConversionAtOxC_bMonRe ||
       CatAcvDiagT_B.TmpSignalConversionAtLsMon_bA_d) ||
      CatAcvDiagT_DWork.UnitDelay_DSTATE_kh3) {
    /* RelationalOperator: '<S357>/Relational Operator23' incorporates:
     *  Constant: '<S357>/Ext_stGasMod_SC'
     */
    localTmpSignalConversionAtOxC_0 =
      (CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_l == Ext_stGasMod_SC);

    /* Logic: '<S357>/Logical Operator' incorporates:
     *  Logic: '<S357>/Logical Operator1'
     *  UnitDelay: '<S384>/Unit Delay'
     */
    OxC_bAcvCalcmO2Stg = (CatAcvDiagT_DWork.UnitDelay_DSTATE_hy &&
                          (!CatAcvDiagT_B.TmpSignalConversionAtLsMon_bA_d));

    /* Outputs for enable SubSystem: '<S357>/1_Calculs_osc1' incorporates:
     *  EnablePort: '<S381>/OxC_bAcvCalcmO2Stg'
     */
    if (OxC_bAcvCalcmO2Stg) {
      /* Product: '<S394>/Divide' incorporates:
       *  Constant: '<S381>/ConstVal'
       *  Constant: '<S381>/OxC_bLsUsProp_C3'
       *  DataTypeConversion: '<S381>/Data Type Conversion5'
       */
      localTe = 1.0F / (((Float32)OxC_rMixtPha2_C) * 1.121520982E-004F);

      /* Outputs for atomic SubSystem: '<S394>/If Action Subsystem3' */

      /* Switch: '<S403>/Switch1' incorporates:
       *  Constant: '<S403>/Constant1'
       *  Constant: '<S403>/Constant2'
       *  Constant: '<S403>/Constant3'
       *  Logic: '<S403>/Logical Operator1'
       *  RelationalOperator: '<S403>/Relational Operator'
       *  RelationalOperator: '<S403>/Relational Operator1'
       *  RelationalOperator: '<S403>/Relational Operator3'
       */
      if (((localTe != localTe) || (localTe > 3.000000005E+038F)) ||
          (-3.000000005E+038F > localTe)) {
        localTe = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S394>/If Action Subsystem3' */

      /* Switch: '<S381>/Switch' incorporates:
       *  Constant: '<S381>/OxC_bLsUsProp_C'
       *  DataTypeConversion: '<S9>/Data Type Conversion4'
       */
      if (OxC_bLsUsProp_C) {
        localInterpolationUsingPrelooku = ((Float32)
          localTmpSignalConversionAtLSA_l) * 1.121520982E-004F;
      } else {
        localInterpolationUsingPrelooku = localTe;
      }

      /* Sum: '<S381>/Sum' incorporates:
       *  Constant: '<S381>/ConstVal_5'
       */
      localInterpolationUsingPrelooku--;

      /* Abs: '<S381>/Abs' */
      localSwitch1_c = ACTEMS_FabsF(localInterpolationUsingPrelooku);

      /* Lookup2D: '<S385>/Look-Up Table (2-D)'
       * About '<S385>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U16  2^-7  FSlope 1.28
       * Input1  Data Type:  Integer        S16
       * Output0 Data Type:  Fixed Point    U8  2^-1  FSlope 1.5625
       * Lookup Method: Below
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      {
        UInt32 iRowIndex1, iColumnIndex1;
        BINARYSEARCH_U16_iL( &(iRowIndex1),
                            CatAcvDiagT_B.TmpSignalConversionAtAirSys_m_l,
                            (&(OxC_mfDsThr_A[0])), 15U);
        BINARYSEARCH_S16_iL( &(iColumnIndex1),
                            CatAcvDiagT_B.TmpSignalConversionAtExt_tOxC_f,
                            (&(OxC_tOxC_A[0])), 15U);
         /*-MD :  Fix indexing issue as Matlab accesses the carto in 1D whereas its a 2D 
        localLookUpTable2D = OxC_rO2StgEstimCorIndex_M[iRowIndex1+16*iColumnIndex1]; */
        localLookUpTable2D = OxC_rO2StgEstimCorIndex_M[iColumnIndex1][iRowIndex1]; /*-MA */
        
      }

      /* DataTypeDuplicate Block: '<S385>/Data Type Duplicate2'
       *
       * Regarding '<S385>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S381>/Data Type Conversion1' */
      localDataTypeConversion1 = ((Float32)
        CatAcvDiagT_B.TmpSignalConversionAtAirSys_m_l) * 9.999999776E-003F;

      /* DataTypeConversion: '<S381>/Data Type Conversion2' incorporates:
       *  Constant: '<S381>/CatMon_SampleTiFast_SC'
       */
      localDataTypeConversion2 = ((Float32)CatMon_SampleTiFast_SC) *
        9.999999776E-003F;

      /* DataTypeConversion: '<S381>/Data Type Conversion3' incorporates:
       *  Constant: '<S381>/OxC_rO2_mfDsThr_C'
       */
      localDataTypeConversion3 = ((Float32)OxC_rO2_mfDsThr_C) * 0.390625F;

      /* DataTypeConversion: '<S381>/Data Type Conversion4' incorporates:
       *  Lookup2D: '<S385>/Look-Up Table (2-D)'
       */
      localDataTypeConversion4 = ((Float32)localLookUpTable2D) * 0.78125F;

      /* PreLookup: '<S386>/Prelookup' */
      localAirSys_mfAirMesThrEstim_sw = plook_u32u16f_binc
        (CatAcvDiagT_B.TmpSignalConversionAtAirSys_m_l, (&(OxC_mfDsThr_A[0])),
         15U, &localInterpolationUsingPrelooku);

      /* PreLookup: '<S389>/Prelookup' */
      localAdd = plook_u32s16f_binc
        (CatAcvDiagT_B.TmpSignalConversionAtExt_tOxC_f, (&(OxC_tOxC_A[0])), 15U,
         &localSwitch3);

      /* Interpolation_n-D: '<S387>/Interpolation Using Prelookup3' */
      localTe = localInterpolationUsingPrelooku;
      localfrac[0] = localTe;
      localTe = localSwitch3;
      localfrac[1] = localTe;
      localbpIndex[0] = localAirSys_mfAirMesThrEstim_sw;
      localbpIndex[1] = localAdd;
      localSwitch2 = intrp2d_iu8n1ff_u32f_l_ns(localbpIndex, localfrac,
        (&(OxC_rO2StgEstimCorInterpGas_M[0])), 16U);

      /* Interpolation_n-D: '<S388>/Interpolation Using Prelookup3' */
      localTe = localInterpolationUsingPrelooku;
      localfrac_0[0] = localTe;
      localTe = localSwitch3;
      localfrac_0[1] = localTe;
      localbpIndex_0[0] = localAirSys_mfAirMesThrEstim_sw;
      localbpIndex_0[1] = localAdd;
      localSwitch3 = intrp2d_iu8n1ff_u32f_l_ns(localbpIndex_0, localfrac_0,
        (&(OxC_rO2StgEstimCorInterp_M[0])), 16U);

      /* Interpolation_n-D: '<S390>/Interpolation Using Prelookup3' */
      localTe = localInterpolationUsingPrelooku;
      localTe = intrp1d_iu16n7ff_u32f_l_ns(localAirSys_mfAirMesThrEstim_sw,
        localTe, (&(OxC_tiTmrScdnGas_T[0])));

      /* Interpolation_n-D: '<S391>/Interpolation Using Prelookup3' */
      localSwitch_m0 = localInterpolationUsingPrelooku;
      localInterpolationUsingPrelooku = intrp1d_iu16n7ff_u32f_l_ns
        (localAirSys_mfAirMesThrEstim_sw, localSwitch_m0, (&(OxC_tiTmrScdn_T[0])));

      /* Switch: '<S381>/Switch3' incorporates:
       *  Constant: '<S381>/OxC_bItpolClc_C'
       */
      if (OxC_bItpolClc_C) {
        localSwitch3 = localDataTypeConversion4;
      }

      /* Switch: '<S381>/Switch1' */
      if (localTmpSignalConversionAtOxC_0) {
        OxC_rO2StgEstimCor = localSwitch2;
      } else {
        OxC_rO2StgEstimCor = localSwitch3;
      }

      /* DataTypeConversion: '<S392>/OutDTConv' incorporates:
       *  Constant: '<S381>/ConstVal_1'
       *  Constant: '<S381>/ConstVal_2'
       *  Constant: '<S381>/ConstVal_3'
       *  Constant: '<S392>/offset'
       *  Constant: '<S392>/offset1'
       *  Constant: '<S392>/one_on_slope'
       *  Product: '<S392>/Product4'
       *  Product: '<S395>/Divide'
       *  Product: '<S396>/Divide'
       *  Product: '<S397>/Divide'
       *  Product: '<S398>/Divide'
       *  Product: '<S399>/Divide'
       *  Product: '<S400>/Divide'
       *  Product: '<S401>/Divide'
       *  Sum: '<S392>/Add1'
       *  Sum: '<S392>/Add2'
       */
      localSwitch_m0 = ((((((localDataTypeConversion1 * localDataTypeConversion2)
                            * localSwitch1_c) * 1000.0F) * (OxC_rO2StgEstimCor /
        100.0F)) * (localDataTypeConversion3 / 100.0F)) * 64.0F) + 0.5F;
      if (localSwitch_m0 < 65536.0F) {
        if (localSwitch_m0 >= 0.0F) {
          OxC_mO2StgEstim = (UInt16)localSwitch_m0;
        } else {
          OxC_mO2StgEstim = 0U;
        }
      } else {
        OxC_mO2StgEstim = MAX_uint16_T;
      }

      /* Switch: '<S381>/Switch2' */
      if (!localTmpSignalConversionAtOxC_0) {
        localTe = localInterpolationUsingPrelooku;
      }

      /* DataTypeConversion: '<S393>/OutDTConv' incorporates:
       *  Constant: '<S393>/offset'
       *  Constant: '<S393>/offset1'
       *  Constant: '<S393>/one_on_slope'
       *  Product: '<S393>/Product4'
       *  Sum: '<S393>/Add1'
       *  Sum: '<S393>/Add2'
       */
      localSwitch_m0 = (100.0F * localTe) + 0.5F;
      if (localSwitch_m0 < 65536.0F) {
        if (localSwitch_m0 >= 0.0F) {
          OxC_tiTmrScdnMonORngIntrIni = (UInt16)localSwitch_m0;
        } else {
          OxC_tiTmrScdnMonORngIntrIni = 0U;
        }
      } else {
        OxC_tiTmrScdnMonORngIntrIni = MAX_uint16_T;
      }
    }

    /* end of Outputs for SubSystem: '<S357>/1_Calculs_osc1' */

    /* Switch: '<S357>/Switch8' incorporates:
     *  Constant: '<S357>/OxC_bDiagUnlimInhGas_C'
     *  Constant: '<S357>/OxC_bDiagUnlimInh_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      OxC_bDiagUnlimInhTmp = OxC_bDiagUnlimInhGas_C;
    } else {
      OxC_bDiagUnlimInhTmp = OxC_bDiagUnlimInh_C;
    }

    /* Switch: '<S357>/Switch1' incorporates:
     *  Constant: '<S357>/OxC_ctMaxMonORngIntrGas_C'
     *  Constant: '<S357>/OxC_ctMaxMonORngIntr_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      OxC_ctMaxMonORngIntrTmp = OxC_ctMaxMonORngIntrGas_C;
    } else {
      OxC_ctMaxMonORngIntrTmp = OxC_ctMaxMonORngIntr_C;
    }

    /* Switch: '<S357>/Switch2' incorporates:
     *  Constant: '<S357>/OxC_ctMinMonORngIntrGas_C'
     *  Constant: '<S357>/OxC_ctMinMonORngIntr_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      OxC_ctMinMonORngIntrTmp = OxC_ctMinMonORngIntrGas_C;
    } else {
      OxC_ctMinMonORngIntrTmp = OxC_ctMinMonORngIntr_C;
    }

    /* Switch: '<S357>/Switch3' incorporates:
     *  Constant: '<S357>/OxC_mO2StgMinPlausGas_C'
     *  Constant: '<S357>/OxC_mO2StgMinPlaus_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      OxC_mO2StgMinPlausTmp = OxC_mO2StgMinPlausGas_C;
    } else {
      OxC_mO2StgMinPlausTmp = OxC_mO2StgMinPlaus_C;
    }

    /* Switch: '<S357>/Switch4' incorporates:
     *  Constant: '<S357>/OxC_mO2StgMaxGas_C'
     *  Constant: '<S357>/OxC_mO2StgMax_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      OxC_mO2StgMaxTmp = OxC_mO2StgMaxGas_C;
    } else {
      OxC_mO2StgMaxTmp = OxC_mO2StgMax_C;
    }

    /* Switch: '<S357>/Switch6' incorporates:
     *  Constant: '<S357>/OxC_rMixtPha1Gas_C'
     *  Constant: '<S357>/OxC_rMixtPha1_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      localTmpSignalConversionAtLSA_l = OxC_rMixtPha1Gas_C;
    } else {
      localTmpSignalConversionAtLSA_l = OxC_rMixtPha1_C;
    }

    /* DataTypeConversion: '<S357>/Data Type Conversion5' */
    OxC_rMixtPha1Tmp = ((Float32)localTmpSignalConversionAtLSA_l) *
      1.121520982E-004F;

    /* Switch: '<S357>/Switch7' incorporates:
     *  Constant: '<S357>/OxC_rMixtPha2Gas_C'
     *  Constant: '<S357>/OxC_rMixtPha2_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      localTmpSignalConversionAtLSA_l = OxC_rMixtPha2Gas_C;
    } else {
      localTmpSignalConversionAtLSA_l = OxC_rMixtPha2_C;
    }

    /* DataTypeConversion: '<S357>/Data Type Conversion4' */
    OxC_rMixtPha2Tmp = ((Float32)localTmpSignalConversionAtLSA_l) *
      1.121520982E-004F;

    /* Switch: '<S357>/Switch9' incorporates:
     *  Constant: '<S357>/OxC_tiPha1MaxDlyProtGas_C'
     *  Constant: '<S357>/OxC_tiPha1MaxDlyProt_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      OxC_tiPha1MaxDlyProtTmp = OxC_tiPha1MaxDlyProtGas_C;
    } else {
      OxC_tiPha1MaxDlyProtTmp = OxC_tiPha1MaxDlyProt_C;
    }

    /* Switch: '<S357>/Switch10' incorporates:
     *  Constant: '<S357>/OxC_tiTmrIniMonORngIntrGas_C'
     *  Constant: '<S357>/OxC_tiTmrIniMonORngIntr_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      localTmpSignalConversionAtLSA_l = OxC_tiTmrIniMonORngIntrGas_C;
    } else {
      localTmpSignalConversionAtLSA_l = OxC_tiTmrIniMonORngIntr_C;
    }

    /* DataTypeConversion: '<S357>/Data Type Conversion7' */
    OxC_tiTmrIniMonORngIntrTmp = localTmpSignalConversionAtLSA_l;

    /* Switch: '<S357>/Switch11' incorporates:
     *  Constant: '<S357>/LsMon_rMixtSenO2DsDiagLean_C'
     *  Constant: '<S357>/LsMon_rMixtSenO2DsDiagRich_C'
     */
    if (CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas) {
      localTmpSignalConversionAtLSA_l = LsMon_rMixtSenO2DsDiagRich_C;
    } else {
      localTmpSignalConversionAtLSA_l = LsMon_rMixtSenO2DsDiagLean_C;
    }

    /* DataTypeConversion: '<S357>/Data Type Conversion3' */
    LsMon_rMixtItrsvSenO2DsDiagTmp = ((Float32)localTmpSignalConversionAtLSA_l)
      * 1.121520982E-004F;

    /* Switch: '<S357>/Switch12' incorporates:
     *  Constant: '<S357>/LsMon_uThdItrsvSenO2DsDiagLean_C'
     *  Constant: '<S357>/LsMon_uThdItrsvSenO2DsDiagRich_C'
     */
    if (CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas) {
      localTmpSignalConversionAtLSA_l = LsMon_uThdItrsvSenO2DsDiagRich_C;
    } else {
      localTmpSignalConversionAtLSA_l = LsMon_uThdItrsvSenO2DsDiagLean_C;
    }

    /* DataTypeConversion: '<S357>/Data Type Conversion1' */
    LsMon_uThdItrsvSenO2DsDiagTmp = ((Float32)localTmpSignalConversionAtLSA_l) *
      0.0048828125F;

    /* DataTypeConversion: '<S357>/Data Type Conversion8' */
    CatAcvDiagT_B.DataTypeConversion8 = ((Float32)
      CatAcvDiagT_B.TmpSignalConversionAtAFReg_rF_i) * 7.629394531E-006F;

    /* Switch: '<S357>/Switch13' incorporates:
     *  Constant: '<S357>/ConstVal'
     *  Constant: '<S357>/LsMon_uThdItrsvSenO2DsDiagLean_C1'
     */
    if (OxC_bAcvFbL_rMonItrv_C) {
      OxC_rFbL_rMonItrv = CatAcvDiagT_B.DataTypeConversion8;
    } else {
      OxC_rFbL_rMonItrv = 0.0F;
    }

    /* Stateflow: '<S357>/2_Automate_diag_cata_intrusif1' incorporates:
     *  Constant: '<S357>/CAT_DIAG_INTRU_START'
     *  Constant: '<S357>/CatMon_SampleTiFast_SC'
     *  Constant: '<S357>/LSMON_ITRSV_SEN02DS_WAIT_RESULT'
     *  Constant: '<S357>/LSMON_ITRSV_SENO2DS_DIAG_INIT'
     *  Constant: '<S357>/LSMON_ITRSV_SENO2DS_DIAG_NOK'
     *  Constant: '<S357>/LSMON_ITRSV_SENO2DS_DIAG_OK'
     *  Constant: '<S357>/LSMON_ITRSV_SENO2DS_DIAG_RUNNING'
     *  Constant: '<S357>/LsMon_tiItrsvSenO2DsDiag_C'
     *  Constant: '<S357>/LsMon_tiItrsvWaitSenO2DsDiag_C'
     *  Constant: '<S357>/OXC_MON_RUNNING'
     *  Constant: '<S357>/OXC_MON_WAIT'
     *  Constant: '<S357>/OXC_MON_WAITING_TO_START'
     */
    localrtmax = _sfEvent_;
    _sfEvent_ = CALL_EVENT;

    /* Gateway: CatAcvDiagT/CatMon_SdlFast_CatAcvDiag1/04_Calcul_osc_et_diagnostic1/01_Calcul_osc_et_diagnostic/2_Automate_diag_cata_intrusif1 */
    /* During: CatAcvDiagT/CatMon_SdlFast_CatAcvDiag1/04_Calcul_osc_et_diagnostic1/01_Calcul_osc_et_diagnostic/2_Automate_diag_cata_intrusif1 */
    if (CatAcvDiagT_DWork.is_active_c1_CatAcvDiagT == 0) {
      /* Entry: CatAcvDiagT/CatMon_SdlFast_CatAcvDiag1/04_Calcul_osc_et_diagnostic1/01_Calcul_osc_et_diagnostic/2_Automate_diag_cata_intrusif1 */
      CatAcvDiagT_DWork.is_active_c1_CatAcvDiagT = 1U;

      /* Transition: '<S382>:13' */
      CatAcvDiagT_B.OxC_ctMonORngIntr = 0U;
      First_diag_Sen02 = TRUE;

      /* Entry 'OXC_MON_WAITING_TO_START': '<S382>:1' */
      if (CatAcvDiagT_DWork.is_c1_CatAcvDiagT != IN_OXC_MON_WAITING_TO_START) {
        CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAITING_TO_START;
        CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAITING_TO_START;
        CatAcvDiagT_B.OxC_bMonRunORngIntr_o = FALSE;
        CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = OxC_tiTmrIniMonORngIntrTmp;
        OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F + CatAcvDiagT_B.DataTypeConversion8;
        CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
          OxC_rFbLsclFil_ItrsvSenO2Strt;
        CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_INIT;
      }
    } else {
      switch (CatAcvDiagT_DWork.is_c1_CatAcvDiagT) {
       case IN_LSMON_ITRSV_SEN02DS_DIAG:
        /* During 'LSMON_ITRSV_SEN02DS_DIAG': '<S382>:11' */
        if (CatAcvDiagT_DWork.is_c1_CatAcvDiagT == IN_LSMON_ITRSV_SEN02DS_DIAG)
        {
          if (((SInt32)CatAcvDiagT_B.TmpSignalConversionAtLsMon_bA_d) == 0) {
            /* Transition: '<S382>:30' */
            /* Exit 'LSMON_ITRSV_SEN02DS_DIAG_NOK': '<S382>:12' */
            CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG = (UInt8)
              IN_NO_ACTIVE_CHILD;

            /* Exit 'LSMON_ITRSV_SEN02DS_DIAG_OK': '<S382>:10' */
            /* Exit 'LSMON_ITRSV_SEN02DS_DIAG_RUNNING': '<S382>:9' */
            /* Exit 'LSMON_ITRSV_SEN02DS_WAIT_RESULT': '<S382>:89' */
            /* Exit 'LSMON_ITRSV_SEN02DS_DIAG': '<S382>:11' */
            /* Entry 'OXC_MON_WAITING_TO_START': '<S382>:1' */
            CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAITING_TO_START;
            CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAITING_TO_START;
            CatAcvDiagT_B.OxC_bMonRunORngIntr_o = FALSE;
            CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = OxC_tiTmrIniMonORngIntrTmp;
            OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F +
              CatAcvDiagT_B.DataTypeConversion8;
            CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
              OxC_rFbLsclFil_ItrsvSenO2Strt;
            CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_INIT;
          } else {
            switch (CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG) {
             case IN_LSMON_ITRSV_SEN02DS_DIAG_NOK:
              /* During 'LSMON_ITRSV_SEN02DS_DIAG_NOK': '<S382>:12' */
              break;

             case IN_LSMON_ITRSV_SEN02DS_DIAG_OK:
              /* During 'LSMON_ITRSV_SEN02DS_DIAG_OK': '<S382>:10' */
              break;

             case IN_LSMON_ITRSV_SEN02DS_DIAG_RUN:
              /* During 'LSMON_ITRSV_SEN02DS_DIAG_RUNNING': '<S382>:9' */
              if (((((((Float32)CatAcvDiagT_B.TmpSignalConversionAtTension_so) *
                      0.0048828125F) > LsMon_uThdItrsvSenO2DsDiagTmp) &&
                    CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas) ||
                   (((((Float32)CatAcvDiagT_B.TmpSignalConversionAtTension_so) *
                      0.0048828125F) < LsMon_uThdItrsvSenO2DsDiagTmp) &&
                    (!CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas))) &&
                  (CatAcvDiagT_B.LsMon_tiItrsvSenO2DsDiag != 0)) {
                /* Transition: '<S382>:33' */
                /* Exit 'LSMON_ITRSV_SEN02DS_DIAG_RUNNING': '<S382>:9' */
                /* Entry 'LSMON_ITRSV_SEN02DS_DIAG_OK': '<S382>:10' */
                CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG =
                  IN_LSMON_ITRSV_SEN02DS_DIAG_OK;
                CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_OK;
              } else if (CatAcvDiagT_B.LsMon_tiItrsvSenO2DsDiag == 0) {
                /* Transition: '<S382>:90' */
                /* Exit 'LSMON_ITRSV_SEN02DS_DIAG_RUNNING': '<S382>:9' */
                /* Entry 'LSMON_ITRSV_SEN02DS_WAIT_RESULT': '<S382>:89' */
                CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG =
                  IN_LSMON_ITRSV_SEN02DS_WAIT_RES;
                CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SEN02DS_WAIT_RESULT;
                CatAcvDiagT_B.OxC_rMixtReqMonIntr =
                  OxC_rFbLsclFil_ItrsvSenO2Strt;
              } else {
                CatAcvDiagT_B.LsMon_tiItrsvSenO2DsDiag = (UInt16)rt_MAX(0,
                  CatAcvDiagT_B.LsMon_tiItrsvSenO2DsDiag -
                  CatMon_SampleTiFast_SC);
                CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o = (UInt16)rt_MAX
                  (0, CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o -
                   CatMon_SampleTiFast_SC);
              }
              break;

             case IN_LSMON_ITRSV_SEN02DS_WAIT_RES:
              /* During 'LSMON_ITRSV_SEN02DS_WAIT_RESULT': '<S382>:89' */
              /* Transition: '<S382>:101' */
              if (((((((Float32)CatAcvDiagT_B.TmpSignalConversionAtTension_so) *
                      0.0048828125F) < LsMon_uThdItrsvSenO2DsDiagTmp) &&
                    CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas) ||
                   (((((Float32)CatAcvDiagT_B.TmpSignalConversionAtTension_so) *
                      0.0048828125F) > LsMon_uThdItrsvSenO2DsDiagTmp) &&
                    (!CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas))) &&
                  (CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o == 0)) {
                /* Transition: '<S382>:92' */
                /* Exit 'LSMON_ITRSV_SEN02DS_WAIT_RESULT': '<S382>:89' */
                /* Entry 'LSMON_ITRSV_SEN02DS_DIAG_NOK': '<S382>:12' */
                CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG =
                  IN_LSMON_ITRSV_SEN02DS_DIAG_NOK;
                CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_NOK;
              } else if (((((((Float32)
                              CatAcvDiagT_B.TmpSignalConversionAtTension_so) *
                             0.0048828125F) > LsMon_uThdItrsvSenO2DsDiagTmp) &&
                           CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas) ||
                          (((((Float32)
                              CatAcvDiagT_B.TmpSignalConversionAtTension_so) *
                             0.0048828125F) < LsMon_uThdItrsvSenO2DsDiagTmp) &&
                           (!CatAcvDiagT_B.TmpSignalConversionAtLsMon_bCas))) &&
                         (CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o != 0)) {
                /* Transition: '<S382>:104' */
                /* Exit 'LSMON_ITRSV_SEN02DS_WAIT_RESULT': '<S382>:89' */
                /* Entry 'LSMON_ITRSV_SEN02DS_DIAG_OK': '<S382>:10' */
                CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG =
                  IN_LSMON_ITRSV_SEN02DS_DIAG_OK;
                CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_OK;
              } else {
                CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o = (UInt16)rt_MAX
                  (0, CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o -
                   CatMon_SampleTiFast_SC);
              }
              break;

             default:
              CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG = (UInt8)
                IN_NO_ACTIVE_CHILD;
              break;
            }
          }
        }
        break;

       case IN_OXC_MON_RUNNING:
        CatAcvDiagT_OXC_MON_RUNNING();
        break;

       case IN_OXC_MON_WAIT:
        /* During 'OXC_MON_WAIT': '<S382>:8' */
        if (!((CatAcvDiagT_DWork.is_c1_CatAcvDiagT != IN_OXC_MON_WAIT) ||
              (!(((CatAcvDiagT_B.OxC_ctMonORngIntr < OxC_ctMaxMonORngIntrTmp) ||
                  (((SInt32)OxC_bDiagUnlimInhTmp) == 0)) && (((SInt32)
                 CatAcvDiagT_B.TmpSignalConversionAtOxC_bMon_l) == 1))))) {
          /* Transition: '<S382>:35' */
          /* Exit 'OXC_MON_WAIT': '<S382>:8' */
          /* Entry 'OXC_MON_RUNNING': '<S382>:7' */
          CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_RUNNING;
          CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_RUNNING;
          CatAcvDiagT_B.OxC_bMonRunORngIntr_o = TRUE;
          OxC_rFbLsclFil_rMonItrsvStrt = 1.0F + OxC_rFbL_rMonItrv;

          /* Transition: '<S382>:23' */
          /* Entry 'CAT_DIAG_INTRU_START': '<S382>:2' */
          if (CatAcvDiagT_DWork.is_OXC_MON_RUNNING != IN_CAT_DIAG_INTRU_START) {
            CatAcvDiagT_DWork.is_OXC_MON_RUNNING = IN_CAT_DIAG_INTRU_START;
            CatAcvDiagT_B.OxC_stMonIntrRun = CAT_DIAG_INTRU_START;
            CatAcvDiagT_B.OxC_rMixtReqMonIntr = OxC_rMixtPha1Tmp *
              OxC_rFbLsclFil_rMonItrsvStrt;
            CatAcvDiagT_B.OxC_tiDlyMaxProt_rMixtPha1_p = OxC_tiPha1MaxDlyProtTmp;
          }
        }
        break;

       case IN_OXC_MON_WAITING_TO_START:
        /* During 'OXC_MON_WAITING_TO_START': '<S382>:1' */
        if (((CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr < CatMon_SampleTiFast_SC) &&
             (((SInt32)CatAcvDiagT_B.TmpSignalConversionAtLsMon_bA_d) == 0)) &&
            (((SInt32)CatAcvDiagT_B.TmpSignalConversionAtOxC_bMon_l) == 1)) {
          /* Transition: '<S382>:34' */
          /* Exit 'OXC_MON_WAITING_TO_START': '<S382>:1' */
          First_diag_Sen02 = FALSE;

          /* Entry 'OXC_MON_WAIT': '<S382>:8' */
          CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_OXC_MON_WAIT;
          CatAcvDiagT_B.OxC_stMonIntrAcv = OXC_MON_WAIT;
          CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr = 0;
        } else if ((((SInt32)CatAcvDiagT_B.TmpSignalConversionAtLsMon_bA_d) ==
                    1) && (((SInt32)First_diag_Sen02) == 0)) {
          /* Transition: '<S382>:32' */
          /* Exit 'OXC_MON_WAITING_TO_START': '<S382>:1' */
          OxC_rFbLsclFil_ItrsvSenO2Strt = 1.0F +
            CatAcvDiagT_B.DataTypeConversion8;
          CatAcvDiagT_B.OxC_rMixtReqMonIntr = LsMon_rMixtItrsvSenO2DsDiagTmp *
            OxC_rFbLsclFil_ItrsvSenO2Strt;

          /* Entry 'LSMON_ITRSV_SEN02DS_DIAG': '<S382>:11' */
          CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_LSMON_ITRSV_SEN02DS_DIAG;

          /* Transition: '<S382>:37' */
          /* Entry 'LSMON_ITRSV_SEN02DS_DIAG_RUNNING': '<S382>:9' */
          if (CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG !=
              IN_LSMON_ITRSV_SEN02DS_DIAG_RUN) {
            CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG =
              IN_LSMON_ITRSV_SEN02DS_DIAG_RUN;
            CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_RUNNING;
            CatAcvDiagT_B.LsMon_tiItrsvSenO2DsDiag = LsMon_tiItrsvSenO2DsDiag_C;
            CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o = (UInt16)((UInt32)
              (LsMon_tiItrsvSenO2DsDiag_C + LsMon_tiItrsvWaitSenO2DsDiag_C));
          }
        } else if ((((SInt32)CatAcvDiagT_B.TmpSignalConversionAtLsMon_bA_d) ==
                    1) && (((SInt32)First_diag_Sen02) == 1)) {
          /* Transition: '<S382>:144' */
          /* Exit 'OXC_MON_WAITING_TO_START': '<S382>:1' */
          First_diag_Sen02 = FALSE;

          /* Entry 'LSMON_ITRSV_SEN02DS_DIAG': '<S382>:11' */
          CatAcvDiagT_DWork.is_c1_CatAcvDiagT = IN_LSMON_ITRSV_SEN02DS_DIAG;

          /* Transition: '<S382>:37' */
          /* Entry 'LSMON_ITRSV_SEN02DS_DIAG_RUNNING': '<S382>:9' */
          if (CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG !=
              IN_LSMON_ITRSV_SEN02DS_DIAG_RUN) {
            CatAcvDiagT_DWork.is_LSMON_ITRSV_SEN02DS_DIAG =
              IN_LSMON_ITRSV_SEN02DS_DIAG_RUN;
            CatAcvDiagT_B.Merge10_d = LSMON_ITRSV_SENO2DS_DIAG_RUNNING;
            CatAcvDiagT_B.LsMon_tiItrsvSenO2DsDiag = LsMon_tiItrsvSenO2DsDiag_C;
            CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o = (UInt16)((UInt32)
              (LsMon_tiItrsvSenO2DsDiag_C + LsMon_tiItrsvWaitSenO2DsDiag_C));
          }
        } else {
          CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr =
            CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr - CatMon_SampleTiFast_SC;
          First_diag_Sen02 = FALSE;
        }
        break;

       default:
        CatAcvDiagT_DWork.is_c1_CatAcvDiagT = (UInt8)IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    _sfEvent_ = localrtmax;

    /* DataTypeConversion: '<S357>/Data Type Conversion6' */
    if (CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr <= 0) {
      CatAcvDiagT_B.Merge8 = 0U;
    } else if (CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr > 65535) {
      CatAcvDiagT_B.Merge8 = MAX_uint16_T;
    } else {
      CatAcvDiagT_B.Merge8 = (UInt16)CatAcvDiagT_B.OxC_tiTmrIniMonORngIntr;
    }

    /* SignalConversion: '<S357>/Signal Conversion1' */
    CatAcvDiagT_B.Merge19 = CatAcvDiagT_B.LsMon_tiItrsvWaitSenO2DsDiag_o;

    /* SignalConversion: '<S357>/Signal Conversion10' */
    CatAcvDiagT_B.Merge9 = CatAcvDiagT_B.OxC_tiDlyMaxProt_rMixtPha1_p;

    /* SignalConversion: '<S357>/Signal Conversion2' */
    CatAcvDiagT_B.Merge7 = CatAcvDiagT_B.OxC_tiTmrScdnMonORngIntr;

    /* SignalConversion: '<S357>/Signal Conversion3' */
    CatAcvDiagT_B.Merge11 = CatAcvDiagT_B.LsMon_tiItrsvSenO2DsDiag;

    /* SignalConversion: '<S357>/Signal Conversion4' */
    CatAcvDiagT_B.OxC_bMonRunORngIntr = CatAcvDiagT_B.OxC_bMonRunORngIntr_o;

    /* SignalConversion: '<S357>/Signal Conversion5' */
    CatAcvDiagT_B.Merge12_o = CatAcvDiagT_B.OxC_ctMonORngIntr;

    /* SignalConversion: '<S357>/Signal Conversion6' */
    CatAcvDiagT_B.Merge3 = CatAcvDiagT_B.OxC_mO2StgSumEstim;

    /* SignalConversion: '<S357>/Signal Conversion7' */
    CatAcvDiagT_B.Merge4 = CatAcvDiagT_B.OxC_mO2StgTotEstim;

    /* SignalConversion: '<S357>/Signal Conversion8' */
    CatAcvDiagT_B.Merge5 = CatAcvDiagT_B.OxC_stMonIntrAcv;

    /* SignalConversion: '<S357>/Signal Conversion9' */
    CatAcvDiagT_B.Merge6_b = CatAcvDiagT_B.OxC_stMonIntrRun;

    /* DataTypeConversion: '<S383>/OutDTConv' incorporates:
     *  Constant: '<S383>/offset'
     *  Constant: '<S383>/offset1'
     *  Constant: '<S383>/one_on_slope'
     *  Product: '<S383>/Product4'
     *  Sum: '<S383>/Add1'
     *  Sum: '<S383>/Add2'
     */
    localSwitch_m0 = (8.916462891E+003F * CatAcvDiagT_B.OxC_rMixtReqMonIntr) +
      0.5F;
    if (localSwitch_m0 < 65536.0F) {
      if (localSwitch_m0 >= 0.0F) {
        localMerge = (UInt16)localSwitch_m0;
      } else {
        localMerge = 0U;
      }
    } else {
      localMerge = MAX_uint16_T;
    }

    /* Switch: '<S357>/Switch5' incorporates:
     *  Constant: '<S357>/OxC_mO2StgThdGas_C'
     *  Constant: '<S357>/OxC_mO2StgThd_C'
     */
    if (localTmpSignalConversionAtOxC_0) {
      OxC_mO2StgThdTmp = OxC_mO2StgThdGas_C;
    } else {
      OxC_mO2StgThdTmp = OxC_mO2StgThd_C;
    }

    /* Update for UnitDelay: '<S384>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_hy = CatAcvDiagT_B.OxC_bMonRunORngIntr_o;
  }

  /* end of Outputs for SubSystem: '<S328>/01_Calcul_osc_et_diagnostic' */

  /* Outputs for atomic SubSystem: '<S328>/02_sorties_GD' */

  /* Logic: '<S358>/Logical Operator5' incorporates:
   *  RelationalOperator: '<S358>/Relational Operator3'
   */
  localTmpSignalConversionAtOxC_0 = ((CatAcvDiagT_B.OxC_ctMonORngIntr ==
    OxC_ctMaxMonORngIntrTmp) && OxC_bEndInt);

  /* Logic: '<S358>/Logical Operator3' incorporates:
   *  Logic: '<S358>/Logical Operator2'
   *  Logic: '<S404>/Logical Operator'
   *  Logic: '<S404>/Logical Operator1'
   *  Logic: '<S405>/Logical Operator'
   *  Logic: '<S405>/Logical Operator1'
   *  RelationalOperator: '<S358>/Relational Operator2'
   *  UnitDelay: '<S408>/Unit Delay'
   *  UnitDelay: '<S409>/Unit Delay'
   */
  localRelationalOperator2_m =
    ((((!CatAcvDiagT_B.TmpSignalConversionAtClef_de_co) &&
       CatAcvDiagT_DWork.UnitDelay_DSTATE_j0k) &&
      (CatAcvDiagT_B.OxC_ctMonORngIntr >= OxC_ctMinMonORngIntrTmp)) ||
     ((localTmpSignalConversionAtOxC_0) &&
      (!CatAcvDiagT_DWork.UnitDelay_DSTATE_lpr)));

  /* Switch: '<S358>/Switch2' incorporates:
   *  RelationalOperator: '<S358>/Relational Operator1'
   *  UnitDelay: '<S406>/Unit Delay'
   */
  if (localRelationalOperator2_m) {
    localRelationalOperator1_k = (CatAcvDiagT_B.OxC_mO2StgMvEstim >=
      OxC_mO2StgThdTmp);
  } else {
    localRelationalOperator1_k = CatAcvDiagT_DWork.UnitDelay_DSTATE_gi;
  }

  /* Switch: '<S358>/Switch' incorporates:
   *  UnitDelay: '<S407>/Unit Delay'
   */
  if (localRelationalOperator2_m) {
    localRelationalOperator1_h = TRUE;
  } else {
    localRelationalOperator1_h = CatAcvDiagT_DWork.UnitDelay_DSTATE_lm;
  }

  /* SignalConversion: '<S358>/Signal Conversion4' */
  localMerge1_o = localRelationalOperator1_h;

  /* Update for UnitDelay: '<S408>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_j0k =
    CatAcvDiagT_B.TmpSignalConversionAtClef_de_co;

  /* Update for UnitDelay: '<S409>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_lpr = localTmpSignalConversionAtOxC_0;

  /* Update for UnitDelay: '<S406>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_gi = localRelationalOperator1_k;

  /* Update for UnitDelay: '<S407>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_lm = localRelationalOperator1_h;

  /* end of Outputs for SubSystem: '<S328>/02_sorties_GD' */

  /* SignalConversion: '<S328>/Signal Conversion1' */
  localMerge_g = CatAcvDiagT_B.OxC_bMonRunORngIntr;

  /* SignalConversion: '<S328>/Signal Conversion5' */
  localTmpSignalConversionAtLSA_l = CatAcvDiagT_B.OxC_mO2StgMvEstim;

  /* Update for UnitDelay: '<S359>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_kh3 =
    CatAcvDiagT_B.TmpSignalConversionAtLsMon_bA_d;

  /* '<S330>:1:7' */

  /* Logic: '<S327>/Logical Operator2' incorporates:
   *  Constant: '<S327>/Ext_stGasMod_SC'
   *  Constant: '<S327>/Ext_stTranGasGsl_SC'
   *  RelationalOperator: '<S327>/Relational Operator2'
   *  RelationalOperator: '<S327>/Relational Operator3'
   *  UnitDelay: '<S355>/Unit Delay'
   */
  localTmpSignalConversionAtOxC_0 = ((Ext_stGasMod_SC ==
    CatAcvDiagT_DWork.UnitDelay_DSTATE_de) &&
    (CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_l == Ext_stTranGasGsl_SC));

  /* Outputs for enable SubSystem: '<S327>/01_Init_CmbModTran_GasGsl' incorporates:
   *  EnablePort: '<S351>/Enable'
   */
  if (localTmpSignalConversionAtOxC_0) {
    /* SignalConversion: '<S351>/Signal Conversion14' incorporates:
     *  Constant: '<S351>/ConstVal'
     */
    /*-CC Modification for non autosar model implementation */
    /*-MD CatAcvDiagT_B.Merge12_h = 0U; */
	 CatAcvDiagT_B.Merge12_o = 0U; /*-MA*/

    /* SignalConversion: '<S351>/Signal Conversion17' incorporates:
     *  Constant: '<S351>/ConstVal_2'
     */
    /*-MD CatAcvDiagT_B.Merge1 = 0U; */
    CatAcvDiagT_B.Merge3 = 0U; /*-MA*/

    /* SignalConversion: '<S351>/Signal Conversion10' incorporates:
     *  Constant: '<S351>/ConstVal_4'
     */
    /*-MD CatAcvDiagT_B.Merge3_n = 0U */
    CatAcvDiagT_B.Merge4 = 0U; /*-MA*/

    /* SignalConversion: '<S351>/Signal Conversion11' incorporates:
     *  Constant: '<S351>/OXC_MON_WAITING_TO_START'
     */
    /*-MD CatAcvDiagT_B.Merge4_j = OXC_MON_WAITING_TO_START; */
    CatAcvDiagT_B.Merge5 = OXC_MON_WAITING_TO_START; /*-MA*/

    /* SignalConversion: '<S351>/Signal Conversion1' incorporates:
     *  Constant: '<S351>/CAT_DIAG_INTRU_START'
     */
    /*-MD CatAcvDiagT_B.Merge5_j = CAT_DIAG_INTRU_START; */
    CatAcvDiagT_B.Merge6_b = CAT_DIAG_INTRU_START; /*-MA*/

    /* SignalConversion: '<S351>/Signal Conversion13' incorporates:
     *  Constant: '<S351>/ConstVal_1'
     */
    /*-MD CatAcvDiagT_B.Merge6 = 0U; */
    CatAcvDiagT_B.Merge7 = 0U; /*-MA*/

    /* SignalConversion: '<S351>/Signal Conversion15' incorporates:
     *  Constant: '<S351>/OxC_tiTmrIniMonORngIntr_C'
     */
    /*-MD CatAcvDiagT_B.Merge7_b = OxC_tiTmrIniMonORngIntr_C; */
    CatAcvDiagT_B.Merge8 = OxC_tiTmrIniMonORngIntr_C; /*-MA*/

    /* SignalConversion: '<S351>/Signal Conversion16' incorporates:
     *  Constant: '<S351>/OxC_tiPha1MaxDlyProt_C'
     */
    /*-MD CatAcvDiagT_B.Merge8_l = OxC_tiPha1MaxDlyProt_C; */
    CatAcvDiagT_B.Merge9 = OxC_tiPha1MaxDlyProt_C; /*-MA*/

    /* SignalConversion: '<S351>/Signal Conversion8' incorporates:
     *  Constant: '<S351>/OxC_tiTmrMonStabSlowCdn_C'
     */
    /*-MD CatAcvDiagT_B.Merge9_m = OxC_tiTmrMonStabSlowCdn_C; */
    CatAcvDiagT_B.Merge17 = OxC_tiTmrMonStabSlowCdn_C; /*-MA*/

    /* DataTypeConversion: '<S351>/Data Type Conversion7' incorporates:
     *  Constant: '<S351>/OxC_tiTmrMonStabFastCdn_C'
     */
    /*-MD CatAcvDiagT_B.Merge10 = OxC_tiTmrMonStabFastCdn_C; */
    CatAcvDiagT_B.Merge18 = OxC_tiTmrMonStabFastCdn_C; /*-MA*/
  }

  /* end of Outputs for SubSystem: '<S327>/01_Init_CmbModTran_GasGsl' */

  /* Logic: '<S327>/Logical Operator1' incorporates:
   *  Constant: '<S327>/Ext_stGslMod_SC'
   *  Constant: '<S327>/Ext_stTranGslGas_SC'
   *  RelationalOperator: '<S327>/Relational Operator1'
   *  RelationalOperator: '<S327>/Relational Operator12'
   *  UnitDelay: '<S354>/Unit Delay'
   */
  localRelationalOperator2_n = ((Ext_stGslMod_SC ==
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ob) &&
    (CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_l == Ext_stTranGslGas_SC));

  /* Outputs for enable SubSystem: '<S327>/02_Init_CmbModTran_GslGas' incorporates:
   *  EnablePort: '<S352>/Enable'
   */
  if (localRelationalOperator2_n) {
    /* SignalConversion: '<S352>/Signal Conversion4' incorporates:
     *  Constant: '<S352>/ConstVal'
     */
    /*-MD CatAcvDiagT_B.Merge12_h = 0U; */
    CatAcvDiagT_B.Merge12_o = 0U; /*-MA*/

    /* SignalConversion: '<S352>/Signal Conversion9' incorporates:
     *  Constant: '<S352>/ConstVal_2'
     */
    /*-MD CatAcvDiagT_B.Merge1 = 0U; */
    CatAcvDiagT_B.Merge3 = 0U; /*-MA*/

    /* SignalConversion: '<S352>/Signal Conversion1' incorporates:
     *  Constant: '<S352>/ConstVal_4'
     */
    /*-MD CatAcvDiagT_B.Merge3_n = 0U; */
    CatAcvDiagT_B.Merge4 = 0U; /*-MA*/

    /* SignalConversion: '<S352>/Signal Conversion2' incorporates:
     *  Constant: '<S352>/OXC_MON_WAITING_TO_START'
     */
    /*-MD CatAcvDiagT_B.Merge4_j = OXC_MON_WAITING_TO_START; */
    CatAcvDiagT_B.Merge5 = OXC_MON_WAITING_TO_START; /*-MA*/

    /* SignalConversion: '<S352>/Signal Conversion8' incorporates:
     *  Constant: '<S352>/CAT_DIAG_INTRU_START'
     */
    /*-MD CatAcvDiagT_B.Merge5_j = CAT_DIAG_INTRU_START; */
    CatAcvDiagT_B.Merge6_b = CAT_DIAG_INTRU_START; /*-MA*/

    /* SignalConversion: '<S352>/Signal Conversion3' incorporates:
     *  Constant: '<S352>/ConstVal_1'
     */
    /*-MD CatAcvDiagT_B.Merge6 = 0U; */
    CatAcvDiagT_B.Merge7 = 0U; /*-MA*/

    /* SignalConversion: '<S352>/Signal Conversion5' incorporates:
     *  Constant: '<S352>/OxC_tiTmrIniMonORngIntrGas_C'
     */
    /*-MD CatAcvDiagT_B.Merge7_b = OxC_tiTmrIniMonORngIntrGas_C; */
    CatAcvDiagT_B.Merge8 = OxC_tiTmrIniMonORngIntrGas_C; /*-MA*/

    /* SignalConversion: '<S352>/Signal Conversion6' incorporates:
     *  Constant: '<S352>/OxC_tiPha1MaxDlyProtGas_C'
     */
    /*-MD CatAcvDiagT_B.Merge8_l = OxC_tiPha1MaxDlyProtGas_C; */
    CatAcvDiagT_B.Merge9 = OxC_tiPha1MaxDlyProtGas_C; /*-MA*/

    /* SignalConversion: '<S352>/Signal Conversion18' incorporates:
     *  Constant: '<S352>/OxC_tiTmrMonStabSlowCdnGas_C'
     */
    /*-MD CatAcvDiagT_B.Merge9_m = OxC_tiTmrMonStabSlowCdnGas_C; */
    CatAcvDiagT_B.Merge17 = OxC_tiTmrMonStabSlowCdnGas_C; /*-MA*/

    /* DataTypeConversion: '<S352>/Data Type Conversion7' incorporates:
     *  Constant: '<S352>/OxC_tiTmrMonStabFastCdnGas_C'
     */
    /*-MD CatAcvDiagT_B.Merge10 = OxC_tiTmrMonStabFastCdnGas_C; */
    CatAcvDiagT_B.Merge18 = OxC_tiTmrMonStabFastCdnGas_C; /*-MA*/
  }

  /* end of Outputs for SubSystem: '<S327>/02_Init_CmbModTran_GslGas' */

  /* Outputs for enable SubSystem: '<S327>/03_Init_CmbModTran_OxC' incorporates:
   *  EnablePort: '<S353>/Enable'
   *  Logic: '<S327>/Logical Operator3'
   */
  if ((localRelationalOperator2_n) || (localTmpSignalConversionAtOxC_0)) {
    /* SignalConversion: '<S353>/Signal Conversion1' incorporates:
     *  Constant: '<S353>/ConstVal'
     */
    localMerge_g = FALSE;

    /* Constant: '<S353>/ConstVal_3' */
    localMerge1_o = FALSE;

    /* Constant: '<S353>/ConstVal_1' */
    localMerge = 8916U;
  }

  /* end of Outputs for SubSystem: '<S327>/03_Init_CmbModTran_OxC' */

  /* SignalConversion: '<S42>/Signal Conversion1' */
  /*-MD CatAcvDiagT_B.Merge3 = CatAcvDiagT_B.Merge1; */

  /* SignalConversion: '<S42>/Signal Conversion10' */
  /*-MD CatAcvDiagT_B.Merge18 = CatAcvDiagT_B.Merge10; */

  /* SignalConversion: '<S42>/Signal Conversion2' */
  /*-MD CatAcvDiagT_B.Merge4 = CatAcvDiagT_B.Merge3_n; */

  /* SignalConversion: '<S42>/Signal Conversion3' */
  /*-MD CatAcvDiagT_B.Merge5 = CatAcvDiagT_B.Merge4_j; */

  /* SignalConversion: '<S42>/Signal Conversion4' */
  /*-MD CatAcvDiagT_B.Merge6_b = CatAcvDiagT_B.Merge5_j; */

  /* SignalConversion: '<S42>/Signal Conversion5' */
  /*-MD CatAcvDiagT_B.Merge7 = CatAcvDiagT_B.Merge6; */

  /* SignalConversion: '<S42>/Signal Conversion6' */
  /*-MD CatAcvDiagT_B.Merge8 = CatAcvDiagT_B.Merge7_b; */

  /* SignalConversion: '<S42>/Signal Conversion7' */
  /*-MD CatAcvDiagT_B.Merge9 = CatAcvDiagT_B.Merge8_l; */

  /* SignalConversion: '<S42>/Signal Conversion8' */
  /*-MD CatAcvDiagT_B.Merge17 = CatAcvDiagT_B.Merge9_m; */

  /* SignalConversion: '<S42>/Signal Conversion9' */
  /*-MD CatAcvDiagT_B.Merge12_o = CatAcvDiagT_B.Merge12_h; */

  /* Update for UnitDelay: '<S355>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_de =
    CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_l;

  /* Update for UnitDelay: '<S354>/Unit Delay' */
  CatAcvDiagT_DWork.UnitDelay_DSTATE_ob =
    CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_l;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S331>/autosar_testpoint1' */

  /* S-Function Block: <S331>/autosar_testpoint1 */
  OxC_tiTmrMonStabFastCdn_IRV_MP = CatAcvDiagT_B.Merge18;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S332>/autosar_testpoint1' */

  /* S-Function Block: <S332>/autosar_testpoint1 */
  OxC_tiTmrMonStabSlowCdn_IRV_MP = CatAcvDiagT_B.Merge17;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S333>/autosar_testpoint1' */

  /* S-Function Block: <S333>/autosar_testpoint1 */
  LsMon_tiItrsvSenO2DsDiag_IRV_MP = CatAcvDiagT_B.Merge11;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S334>/autosar_testpoint1' */

  /* S-Function Block: <S334>/autosar_testpoint1 */
  LsMon_tiItrsvWaitSenO2DsDiag = CatAcvDiagT_B.Merge19;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S335>/autosar_testpoint1' */

  /* S-Function Block: <S335>/autosar_testpoint1 */
  OxC_mO2StgSumEstim_IRV_MP = CatAcvDiagT_B.Merge3;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S336>/autosar_testpoint1' */

  /* S-Function Block: <S336>/autosar_testpoint1 */
  OxC_ctMonORngIntr_IRV_MP = CatAcvDiagT_B.Merge12_o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S337>/autosar_testpoint1' */

  /* S-Function Block: <S337>/autosar_testpoint1 */
  OxC_mO2StgTotEstim_IRV_MP = CatAcvDiagT_B.Merge4;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S338>/autosar_testpoint1' */

  /* S-Function Block: <S338>/autosar_testpoint1 */
  OxC_stMonIntrAcv_IRV_MP = CatAcvDiagT_B.Merge5;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S339>/autosar_testpoint1' */

  /* S-Function Block: <S339>/autosar_testpoint1 */
  OxC_stMonIntrRun_IRV_MP = CatAcvDiagT_B.Merge6_b;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S340>/autosar_testpoint1' */

  /* S-Function Block: <S340>/autosar_testpoint1 */
  OxC_tiTmrScdnMonORngIntr_IRV_MP = CatAcvDiagT_B.Merge7;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S341>/autosar_testpoint1' */

  /* S-Function Block: <S341>/autosar_testpoint1 */
  OxC_tiDlyMaxProt_rMixtPha1 = CatAcvDiagT_B.Merge9;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S342>/autosar_testpoint1' */

  /* S-Function Block: <S342>/autosar_testpoint1 */
  OxC_tiTmrIniMonORngIntr_IRV_MP = CatAcvDiagT_B.Merge8;

  /* SignalConversion: '<S9>/Signal Conversion1' */
  locallocalMinMax1_n = CatAcvDiagT_B.Merge17;

  /* SignalConversion: '<S9>/Signal Conversion10' */
  locallocalMinMax = CatAcvDiagT_B.Merge9;

  /* SignalConversion: '<S9>/Signal Conversion11' */
  localOxC_tiTmrMonStabFastCdn__g = CatAcvDiagT_B.Merge18;

  /* SignalConversion: '<S9>/Signal Conversion12' */
  localLsMon_tiItrsvWaitSenO2Ds_j = CatAcvDiagT_B.Merge19;

  /* SignalConversion: '<S9>/Signal Conversion2' */
  localOxC_ctMonORngIntr_irv_k = CatAcvDiagT_B.Merge12_o;

  /* SignalConversion: '<S9>/Signal Conversion3' */
  localAdd = CatAcvDiagT_B.Merge3;

  /* SignalConversion: '<S9>/Signal Conversion4' */
  localAirSys_mfAirMesThrEstim_sw = CatAcvDiagT_B.Merge4;

  /* SignalConversion: '<S9>/Signal Conversion5' */
  localOxC_stMonIntrAcv_irv_g = CatAcvDiagT_B.Merge5;

  /* SignalConversion: '<S9>/Signal Conversion6' */
  localOxC_stMonIntrRun_irv_k = CatAcvDiagT_B.Merge6_b;

  /* SignalConversion: '<S9>/Signal Conversion7' */
  localOxC_tiTmrScdnMonORngIntr_e = CatAcvDiagT_B.Merge7;

  /* SignalConversion: '<S9>/Signal Conversion8' */
  localOxC_tiTmrIniMonORngIntr__j = CatAcvDiagT_B.Merge8;

  /* SignalConversion: '<S9>/Signal Conversion9' */
  localLsMon_tiItrsvSenO2DsDiag_k = CatAcvDiagT_B.Merge11;

  /* Switch: '<S345>/Switch' incorporates:
   *  Constant: '<S345>/Byp_Fonction_SC'
   *  Constant: '<S345>/Int_BypC'
   *  Logic: '<S358>/Logical Operator1'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtOxC_0 = CatMon_bDgoORngIntr_B;
  } else {
    localTmpSignalConversionAtOxC_0 = !localRelationalOperator1_k;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtCatMon_bDgoORngIntrInport2' */
  Rte_Write_P_CatMon_bDgoORngIntr_CatMon_bDgoORngIntr
    (localTmpSignalConversionAtOxC_0);

  /* Switch: '<S348>/Switch' incorporates:
   *  Constant: '<S348>/Byp_Fonction_SC'
   *  Constant: '<S348>/Int_BypC'
   *  SignalConversion: '<S358>/Signal Conversion1'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localRelationalOperator2_m = CatMon_bMonRunORngIntr_B;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtCatMon_bMonRunORngIntrInport2' */
  Rte_Write_P_CatMon_bMonRunORngIntr_CatMon_bMonRunORngIntr
    (localRelationalOperator2_m);

  /* Switch: '<S347>/Switch' incorporates:
   *  Constant: '<S347>/Byp_Fonction_SC'
   *  Constant: '<S347>/Int_BypC'
   *  Logic: '<S358>/Logical Operator4'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtOxC_0 = CatMon_bMonWaitORngIntr_B;
  } else {
    localTmpSignalConversionAtOxC_0 = !localRelationalOperator1_h;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtCatMon_bMonWaitORngIntrInport2' */
  Rte_Write_P_CatMon_bMonWaitORngIntr_CatMon_bMonWaitORngIntr
    (localTmpSignalConversionAtOxC_0);

  /* Switch: '<S349>/Switch' incorporates:
   *  Constant: '<S349>/Byp_Fonction_SC'
   *  Constant: '<S349>/Int_BypC'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localLsMon_stItrsvSenO2DsDiag = LsMon_stItrsvSenO2DsDiag_B;
  } else {
    localLsMon_stItrsvSenO2DsDiag = CatAcvDiagT_B.Merge10_d;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtLsMon_stItrsvSenO2DsDiagInport2' */
  Rte_Write_P_LsMon_stItrsvSenO2DsDiag_LsMon_stItrsvSenO2DsDiag
    (localLsMon_stItrsvSenO2DsDiag);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtLsMon_tiItrsvSenO2DsDiag_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_LsMon_tiItrsvSenO2DsDiag_irv
    (localLsMon_tiItrsvSenO2DsDiag_k);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtLsMon_tiItrsvWaitSenO2DsDiag_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_LsMon_tiItrsvWaitSenO2DsDiag_irv
    (localLsMon_tiItrsvWaitSenO2Ds_j);

  /* Switch: '<S343>/Switch' incorporates:
   *  Constant: '<S343>/Byp_Fonction_SC'
   *  Constant: '<S343>/Int_BypC'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localMerge1_o = OxC_bMonEndORngIntr_B;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_bMonEndORngIntrInport2' */
  Rte_Write_P_OxC_bMonEndORngIntr_OxC_bMonEndORngIntr(localMerge1_o);

  /* Switch: '<S350>/Switch1' incorporates:
   *  Constant: '<S350>/Byp_Fonction_SC1'
   *  Constant: '<S350>/Int_BypC1'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtOxC_0 = OxC_bMonRunORngIntr_B;
  } else {
    localTmpSignalConversionAtOxC_0 = localMerge_g;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_bMonRunORngIntrInport2' */
  Rte_Write_P_OxC_bMonRunORngIntr_OxC_bMonRunORngIntr
    (localTmpSignalConversionAtOxC_0);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_bMonRunORngIntr_irvInport2' incorporates:
   *  SignalConversion: '<S9>/Signal Conversion13'
   */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_bMonRunORngIntr_irv(localMerge_g);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_ctMonORngIntr_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_ctMonORngIntr_irv
    (localOxC_ctMonORngIntr_irv_k);

  /* Switch: '<S346>/Switch' incorporates:
   *  Constant: '<S346>/Byp_Fonction_SC'
   *  Constant: '<S346>/Int_BypC'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtLSA_l = OxC_mO2StgMvEstim_B;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_mO2StgMvEstimInport2' */
  Rte_Write_P_OxC_mO2StgMvEstim_OxC_mO2StgMvEstim
    (localTmpSignalConversionAtLSA_l);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_mO2StgSumEstim_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_mO2StgSumEstim_irv(localAdd);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_mO2StgTotEstim_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_mO2StgTotEstim_irv
    (localAirSys_mfAirMesThrEstim_sw);

  /* Switch: '<S344>/Switch' incorporates:
   *  Constant: '<S344>/Byp_Fonction_SC'
   *  Constant: '<S344>/Int_BypC'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localMerge = OxC_rMixtReqMonIntr_B;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_rMixtReqMonIntrInport2' */
  Rte_Write_P_OxC_rMixtReqMonIntr_OxC_rMixtReqMonIntr(localMerge);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_stMonIntrAcv_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_stMonIntrAcv_irv
    (localOxC_stMonIntrAcv_irv_g);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_stMonIntrRun_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_stMonIntrRun_irv
    (localOxC_stMonIntrRun_irv_k);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiDlyMaxProt_rMixtPha1_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiDlyMaxProt_rMixtPha1_irv
    (locallocalMinMax);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiTmrIniMonORngIntr_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiTmrIniMonORngIntr_irv
    (localOxC_tiTmrIniMonORngIntr__j);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiTmrMonStabFastCdn_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiTmrMonStabFastCdn_irv
    (localOxC_tiTmrMonStabFastCdn__g);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiTmrMonStabSlowCdn_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiTmrMonStabSlowCdn_irv
    (locallocalMinMax1_n);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtOxC_tiTmrScdnMonORngIntr_irvInport2' */
  Rte_IrvWrite_RE_CatMon_SdlFast_CatAcvDiag_OxC_tiTmrScdnMonORngIntr_irv
    (localOxC_tiTmrScdnMonORngIntr_e);
}

/* Start for exported function: RE_CatMon_SdlMid_CatAcvDiag */
void RE_CatMon_SdlMid_CatAcvDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/03_Conditions_activation_diag_intrusif1'
   *
   * Block requirements for '<S1>/03_Conditions_activation_diag_intrusif1':
   *  1. SubSystem "03_Conditions_activation_diag_intrusif1" !Trace_To : VEMS_R_09_02846_001.03 ;
   */

  /* Start for enable SubSystem: '<S8>/Conditions_activation_diag_intrusif' */

  /* InitializeConditions for atomic SubSystem: '<S270>/01_Tester_regul_richesse' */

  /* InitializeConditions for Memory: '<S309>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_d = TRUE;

  /* end of InitializeConditions for SubSystem: '<S270>/01_Tester_regul_richesse' */

  /* InitializeConditions for Memory: '<S318>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_h = TRUE;

  /* end of Start for SubSystem: '<S8>/Conditions_activation_diag_intrusif' */
}

/* Output and update for exported function: RE_CatMon_SdlMid_CatAcvDiag */
void RE_CatMon_SdlMid_CatAcvDiag(void)
{
  /* local block i/o variables */
  SInt16 localDataTypeConversion;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localDataTypeConversion1_n;
  UInt16 localTmpSignalConversionAtEngin;
  UInt8 localLookUpTable2D_b;
  UInt8 localLookUpTable2D_l;
  Boolean localLogic_e[2];
  Boolean localLogic_ea[2];
  Boolean localIn_l;
  Boolean localLogic_c[2];
  Boolean localMemory_g;
  Boolean localLogicalOperator3_d;
  Boolean localAutosarServer;
  Boolean localLogicalOperator3_n;
  Boolean localMemory_j;
  Boolean localMemory_e;
  Boolean localR_i;
  Boolean localR_g;
  Boolean localR_k;
  Boolean localNot;
  Boolean localNot_e;
  Boolean localTmpSignalConversionAtOx_bs;
  Float32 localTe_e;
  Boolean localTmpSignalConversionAtBlby_;
  SInt16 localTmpSignalConversionAtExt_j;
  SInt16 localSwitch5;
  SInt16 localTmpSignalConversionAtExt_t;
  Boolean localTmpSignalConversionAtExt_b;
  Boolean localTmpSignalConversionAtVlvAc;
  Boolean localTmpSignalConversionAtAFA_b;
  Boolean localTmpSignalConversionAtLshd_;
  Boolean localTmpSignalConversionAtLsh_k;
  Boolean localTmpSignalConversionAtOxC_b;
  Boolean localTmpSignalConversionAtOxC_p;
  Boolean localTmpSignalConversionAtOx_bf;
  Boolean localTmpSignalConversionAtOxC_e;
  Boolean localTmpSignalConversionAtOxC_a;
  Boolean localUnitDelay1;
  Boolean localTmpSignalConversionAtInjSy;
  Float32 localSwitch_md;
  Float32 localSwitch2_m;
  Float32 localSwitch1_pb;
  Boolean localRelationalOperator2_d;
  Boolean localRelationalOperator1_jf;
  Boolean localLogicalOperator1_i1;
  Boolean localTmpSignalConversionAtFle_f;
  Boolean localTmpSignalConversionAtFlev_;
  SInt32 localrtmax;
  Boolean localRelationalOperator1_c;
  UInt16 localrtmax_0;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/03_Conditions_activation_diag_intrusif1'
   *
   * Block requirements for '<S1>/03_Conditions_activation_diag_intrusif1':
   *  1. SubSystem "03_Conditions_activation_diag_intrusif1" !Trace_To : VEMS_R_09_02846_001.03 ;
   */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtFlev_low_fuel_levelOutport2' incorporates:
   *  Inport: '<Root>/Flev_low_fuel_level'
   */
  Rte_Read_R_Flev_low_fuel_level_Flev_low_fuel_level
    (&localTmpSignalConversionAtFlev_);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtEngine_loadOutport2' incorporates:
   *  Inport: '<Root>/Engine_load'
   */
  Rte_Read_R_Engine_load_Engine_load(&localTmpSignalConversionAtEngin);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_mfAirMesThrEstim_swcOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mfAirMesThrEstim_swc'
   */
  Rte_Read_R_AirSys_mfAirMesThrEstim_swc_AirSys_mfAirMesThrEstim_swc
    (&CatAcvDiagT_B.TmpSignalConversionAtAirSys_m_n);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_tDsThrMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tDsThrMes'
   */
  Rte_Read_R_Ext_tDsThrMes_Ext_tDsThrMes(&localTmpSignalConversionAtExt_t);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_j);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_tOxCEstimOutport2' incorporates:
   *  Inport: '<Root>/Ext_tOxCEstim'
   */
  Rte_Read_R_Ext_tOxCEstim_Ext_tOxCEstim
    (&CatAcvDiagT_B.TmpSignalConversionAtExt_tOxC_i);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtLshd_down_stream_lbda_sensor_hotOutport2' incorporates:
   *  Inport: '<Root>/Lshd_down_strm_lbda_sens_hot'
   */
  Rte_Read_R_Lshd_down_strm_lbda_sens_hot_Lshd_down_strm_lbda_sens_hot
    (&localTmpSignalConversionAtLshd_);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtLshd_up_stream_lbda_sensor_hotOutport2' incorporates:
   *  Inport: '<Root>/Lshd_up_strm_lbda_sens_hot'
   */
  Rte_Read_R_Lshd_up_strm_lbda_sens_hot_Lshd_up_strm_lbda_sens_hot
    (&localTmpSignalConversionAtLsh_k);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bOptmEfcldc_tOxCEstimOutport2' incorporates:
   *  Inport: '<Root>/OxC_bOptmEfcldc_tOxCEstim'
   */
  Rte_Read_R_OxC_bOptmEfcldc_tOxCEstim_OxC_bOptmEfcldc_tOxCEstim
    (&localTmpSignalConversionAtOxC_b);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_bPresGazOutport2' incorporates:
   *  Inport: '<Root>/Ext_bPresGaz'
   */
  Rte_Read_R_Ext_bPresGaz_Ext_bPresGaz(&localTmpSignalConversionAtExt_b);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_stSysGasOutport2' incorporates:
   *  Inport: '<Root>/Ext_stSysGas'
   */
  Rte_Read_R_Ext_stSysGas_Ext_stSysGas
    (&CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_h);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtVlvAct_bInhDiagPresScavOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_bInhDiagPresScav'
   */
  Rte_Read_R_VlvAct_bInhDiagPresScav_VlvAct_bInhDiagPresScav
    (&localTmpSignalConversionAtVlvAc);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtFlev_low_gas_levelOutport2' incorporates:
   *  Inport: '<Root>/Flev_low_gas_level'
   */
  Rte_Read_R_Flev_low_gas_level_Flev_low_gas_level
    (&localTmpSignalConversionAtFle_f);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtLsMon_bAcvItrsvSenO2DsDiagOutport2' incorporates:
   *  Inport: '<Root>/LsMon_bAcvItrsvSenO2DsDiag'
   */
  Rte_Read_R_LsMon_bAcvItrsvSenO2DsDiag_LsMon_bAcvItrsvSenO2DsDiag
    (&CatAcvDiagT_B.TmpSignalConversionAtLsMon_bAcv);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFA_bAuthClsCanPurgOutport2' incorporates:
   *  Inport: '<Root>/AFA_bAuthClsCanPurg'
   */
  Rte_Read_R_AFA_bAuthClsCanPurg_AFA_bAuthClsCanPurg
    (&localTmpSignalConversionAtAFA_b);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAFReg_rFbLsclFilOutport2' incorporates:
   *  Inport: '<Root>/AFReg_rFbLsclFil'
   */
  Rte_Read_R_AFReg_rFbLsclFil_AFReg_rFbLsclFil
    (&CatAcvDiagT_B.TmpSignalConversionAtAFReg_rF_d);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtBlby_bIdcWoutBlbyCndOutport2' incorporates:
   *  Inport: '<Root>/Blby_bIdcWoutBlbyCnd'
   */
  Rte_Read_R_Blby_bIdcWoutBlbyCnd_Blby_bIdcWoutBlbyCnd
    (&localTmpSignalConversionAtBlby_);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtInjSys_bAcvFuCllOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bAcvFuCll'
   */
  Rte_Read_R_InjSys_bAcvFuCll_InjSys_bAcvFuCll(&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bMonEndORngIntrOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonEndORngIntr_INPUT'
   */
  Rte_Read_R_OxC_bMonEndORngIntr_OxC_bMonEndORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtOxC_bMonEn);

  /* S-Function (sfun_autosar_clientop): '<S271>/AutosarServer' */
  Rte_Call_R_FRM_bInhIrvOxCMon_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S271>/Not' */
  localNot = !localAutosarServer;

  /* S-Function (sfun_autosar_clientop): '<S272>/AutosarServer' */
  Rte_Call_R_FRM_bInhRvOxCMon_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S272>/Not' */
  localNot_e = !localAutosarServer;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_stMonIntrAcvOutport2' */
  CatAcvDiagT_B.TmpSignalConversionAtOxC_stMo_i =
    Rte_IrvRead_RE_CatMon_SdlMid_CatAcvDiag_OxC_stMonIntrAcv_irv();

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bMonReqORngIntrOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonReqORngIntr'
   */
  Rte_Read_R_OxC_bMonReqORngIntr_OxC_bMonReqORngIntr
    (&localTmpSignalConversionAtOx_bs);

  /* Outputs for enable SubSystem: '<S8>/Conditions_activation_diag_intrusif' incorporates:
   *  EnablePort: '<S270>/OxC_bMonReqORngIntr'
   */
  if (localTmpSignalConversionAtOx_bs) {
    /* DataTypeConversion: '<S270>/DTConv_Single_To_UFix_1' incorporates:
     *  Constant: '<S270>/SenO2Us_SampleTiFast_SC(1)7'
     */
    localTe_e = ((Float32)CatMon_SampleTiMid_SC) * 3.999999911E-002F;

    /* Outputs for atomic SubSystem: '<S270>/01_Tester_regul_richesse' */

    /* UnitDelay: '<S286>/Unit Delay1' */
    localUnitDelay1 = CatAcvDiagT_DWork.UnitDelay1_DSTATE_j;

    /* Logic: '<S288>/Logical Operator3' */
    localLogicalOperator3_d = !localTmpSignalConversionAtInjSy;

    /* UnitDelay: '<S312>/Unit Delay' */
    localMemory_j = CatAcvDiagT_DWork.UnitDelay_DSTATE_il;

    /* UnitDelay: '<S316>/Unit Delay' */
    localR_i = CatAcvDiagT_DWork.UnitDelay_DSTATE_dlq;

    /* MinMax: '<S288>/MinMax1' incorporates:
     *  Constant: '<S287>/offset'
     *  Constant: '<S287>/offset1'
     *  Constant: '<S287>/one_on_slope'
     *  Constant: '<S288>/Constant1'
     *  DataTypeConversion: '<S287>/OutDTConv'
     *  Lookup_n-D: '<S285>/Lookup Table (n-D)'
     *  Product: '<S287>/Product4'
     *  Sum: '<S287>/Add1'
     *  Sum: '<S287>/Add2'
     */
    localSwitch2_m = (25.0F * look1_iu16lftu16n5If_binlcns
                      (CatAcvDiagT_B.TmpSignalConversionAtAirSys_m_n,
                       (&(OxC_tiLamRegStabInput_A[0])), (&(OxC_tiLamRegStab_T[0])),
                       15U)) + 0.5F;
    if (localSwitch2_m < 65536.0F) {
      if (localSwitch2_m >= 0.0F) {
        localrtmax_0 = (UInt16)localSwitch2_m;
      } else {
        localrtmax_0 = 0U;
      }
    } else {
      localrtmax_0 = MAX_uint16_T;
    }

    /* Sum: '<S288>/Sum2' incorporates:
     *  Constant: '<S288>/Constant6'
     *  Product: '<S313>/Divide'
     */
    localSwitch2_m = (((Float32)localrtmax_0) * 3.999999911E-002F) + (10.0F *
      localTe_e);

    /* UnitDelay: '<S311>/Unit Delay' */
    localSwitch_md = CatAcvDiagT_DWork.UnitDelay_DSTATE_n;

    /* Switch: '<S310>/Switch' incorporates:
     *  Constant: '<S288>/Constant3'
     *  RelationalOperator: '<S310>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_n < 0.0F) {
      localSwitch_md = 0.0F;
    }

    /* Switch: '<S310>/Switch2' incorporates:
     *  RelationalOperator: '<S310>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_n > localSwitch2_m)) {
      localSwitch2_m = localSwitch_md;
    }

    /* Switch: '<S288>/Switch1' incorporates:
     *  Constant: '<S288>/Constant4'
     *  Constant: '<S288>/Constant7'
     *  Logic: '<S288>/Logical Operator2'
     *  Logic: '<S314>/Logical Operator'
     *  Logic: '<S314>/Logical Operator1'
     *  Sum: '<S288>/Sum1'
     */
    if ((localMemory_j) || ((localTmpSignalConversionAtInjSy) && (!localR_i))) {
      localSwitch1_pb = 0.0F;
    } else {
      localSwitch1_pb = (localTe_e + localSwitch2_m) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S288>/Relational Operator2' */
    localRelationalOperator2_d = (localSwitch1_pb >= (((Float32)localrtmax_0) *
      3.999999911E-002F));

    /* UnitDelay: '<S317>/Unit Delay' */
    localR_i = CatAcvDiagT_DWork.UnitDelay_DSTATE_krj;

    /* RelationalOperator: '<S288>/Relational Operator1' incorporates:
     *  Constant: '<S288>/Constant2'
     */
    localRelationalOperator1_jf = (localrtmax_0 == 0);

    /* Switch: '<S288>/Switch' incorporates:
     *  Constant: '<S288>/Constant5'
     *  Logic: '<S288>/Logical Operator1'
     *  Logic: '<S315>/Logical Operator'
     *  Logic: '<S315>/Logical Operator1'
     */
    if (!localRelationalOperator1_jf) {
      localR_i = ((localRelationalOperator2_d) && (!localR_i));
    } else {
      localR_i = TRUE;
    }

    /* Memory: '<S309>/Memory' */
    localMemory_j = CatAcvDiagT_DWork.Memory_PreviousInput_d;

    /* CombinatorialLogic: '<S309>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_d != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_i != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_j != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_ea[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_ea[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* Logic: '<S286>/Logical Operator1' incorporates:
     *  Logic: '<S278>/Logical Operator1'
     *  Logic: '<S286>/Logical Operator'
     */
    localLogicalOperator1_i1 = !((!((localUnitDelay1) || (localLogic_ea[1]))) ||
                                 (!localTmpSignalConversionAtInjSy));

    /* If: '<S278>/If' incorporates:
     *  ActionPort: '<S283>/Action Port'
     *  ActionPort: '<S284>/Action Port'
     *  SubSystem: '<S278>/01_Tester_regul_richesse_active'
     *  SubSystem: '<S278>/02_Tester_regul_richesse_non_activ'
     */
    if (localLogicalOperator1_i1) {
      /* If: '<S283>/If' incorporates:
       *  ActionPort: '<S289>/Action Port'
       *  ActionPort: '<S290>/Action Port'
       *  Constant: '<S283>/OxC_mfDsThrHiThd_C(1)2'
       *  RelationalOperator: '<S283>/Relational Operator17'
       *  SubSystem: '<S283>/01_Tester_regul_richesse_active_mon_running'
       *  SubSystem: '<S283>/02_Tester_regul_richesse_active_mon_not_running'
       */
      if (CatAcvDiagT_B.TmpSignalConversionAtOxC_stMo_i == 2) {
        /* Constant: '<S289>/OxC_mfDsThrHiThd_C(1)2' */
        OxC_bRlamFilOxCCdn = TRUE;
      } else {
        /* DataTypeConversion: '<S290>/DTConv_Single_To_UFix_2' */
        localSwitch2_m = ((Float32)
                          CatAcvDiagT_B.TmpSignalConversionAtAFReg_rF_d) *
          7.629394531E-006F;

        /* Outputs for atomic SubSystem: '<S290>/DLowPassFilter_TypeT_tOxC' */

        /* UnitDelay: '<S299>/Unit Delay' */
        localSwitch_md = CatAcvDiagT_DWork.UnitDelay_DSTATE_hu;

        /* Switch: '<S294>/Switch' incorporates:
         *  UnitDelay: '<S298>/Unit Delay'
         */
        if (!CatAcvDiagT_DWork.UnitDelay_DSTATE_hui) {
          localSwitch_md = localSwitch2_m;
        }

        /* Switch: '<S291>/Switch' incorporates:
         *  Constant: '<S290>/OxC_nCkHiThd_C(1)10'
         *  Constant: '<S290>/OxC_nCkHiThd_C(1)9'
         *  DataTypeConversion: '<S290>/DTConv_Single_To_UFix_1'
         *  Logic: '<S291>/Logical Operator'
         *  Product: '<S295>/Divide'
         *  Product: '<S296>/Divide'
         *  Sum: '<S291>/Sum1'
         *  Sum: '<S291>/Sum2'
         *  Sum: '<S291>/Sum3'
         */
        if (!OxC_bRlamFiLpfRst_C) {
          localSwitch_md -= (localTe_e / ((((Float32)OxC_tiRlamFiLpfTau_C) *
            3.999999911E-002F) + localTe_e)) * (localSwitch_md - localSwitch2_m);
        } else {
          localSwitch_md = localSwitch2_m;
        }

        /* Switch: '<S293>/Switch' incorporates:
         *  UnitDelay: '<S297>/Unit Delay'
         */
        if (CatAcvDiagT_DWork.UnitDelay_DSTATE_mj) {
          localSwitch2_m = localSwitch_md;
        }

        /* Update for UnitDelay: '<S297>/Unit Delay' incorporates:
         *  Constant: '<S293>/Constant3'
         */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_mj = TRUE;

        /* Update for UnitDelay: '<S299>/Unit Delay' */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hu = localSwitch_md;

        /* Update for UnitDelay: '<S298>/Unit Delay' incorporates:
         *  Constant: '<S294>/Constant3'
         */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hui = TRUE;

        /* end of Outputs for SubSystem: '<S290>/DLowPassFilter_TypeT_tOxC' */

        /* Product: '<S292>/Product4' incorporates:
         *  Constant: '<S292>/offset'
         *  Constant: '<S292>/one_on_slope'
         *  Sum: '<S292>/Add1'
         */
        localSwitch_md = 131072.0F * localSwitch2_m;

        /* Switch: '<S292>/Switch1' incorporates:
         *  Constant: '<S292>/offset2'
         *  Constant: '<S292>/offset3'
         *  Constant: '<S292>/offset4'
         *  RelationalOperator: '<S292>/Relational Operator'
         *  Sum: '<S292>/Add3'
         *  Sum: '<S292>/Add4'
         */
        if (localSwitch_md >= 0.0F) {
          localSwitch_md += 0.5F;
        } else {
          localSwitch_md -= 0.5F;
        }

        /* DataTypeConversion: '<S292>/OutDTConv' */
        if (localSwitch_md < 32768.0F) {
          if (localSwitch_md >= -32768.0F) {
            Lambda_feedback_filt = (SInt16)localSwitch_md;
          } else {
            Lambda_feedback_filt = MIN_int16_T;
          }
        } else {
          Lambda_feedback_filt = MAX_int16_T;
        }

        /* Logic: '<S290>/Logical Operator9' incorporates:
         *  Constant: '<S290>/OxC_mfDsThrHiThd_C(1)2'
         *  Constant: '<S290>/OxC_mfDsThrLoThd_C(1)2'
         *  RelationalOperator: '<S290>/Relational Operator17'
         *  RelationalOperator: '<S290>/Relational Operator30'
         */
        OxC_bRlamFilOxCCdn = ((OxC_rlamFilThrHiThd_C >= Lambda_feedback_filt) &&
                              (Lambda_feedback_filt >= OxC_rlamFilThrLoThd_C));
      }
    } else {
      /* RelationalOperator: '<S284>/Relational Operator17' incorporates:
       *  Constant: '<S284>/OxC_mfDsThrHiThd_C(1)2'
       */
      localIn_l = (CatAcvDiagT_B.TmpSignalConversionAtOxC_stMo_i == 2);

      /* UnitDelay: '<S300>/Unit Delay' */
      localMemory_e = CatAcvDiagT_DWork.UnitDelay_DSTATE_dq;

      /* UnitDelay: '<S304>/UnitDelay' */
      localR_g = CatAcvDiagT_DWork.UnitDelay_o;

      /* MinMax: '<S300>/MinMax1' incorporates:
       *  Constant: '<S284>/SenO2Us_SampleTiFast_SC(1)1'
       *  Constant: '<S300>/Constant1'
       */
      localrtmax = OxC_tiAcvRunDlyOff_C;
      if (localrtmax <= 0) {
        localrtmax_0 = 0U;
      } else {
        localrtmax_0 = (UInt16)localrtmax;
      }

      /* Sum: '<S300>/Sum2' incorporates:
       *  Constant: '<S300>/Constant6'
       *  Product: '<S300>/Product'
       */
      localSwitch_md = (((Float32)localrtmax_0) * 3.999999911E-002F) + (10.0F *
        localTe_e);

      /* UnitDelay: '<S303>/Unit Delay' */
      localSwitch2_m = CatAcvDiagT_DWork.UnitDelay_DSTATE_j;

      /* Switch: '<S308>/Switch' incorporates:
       *  Constant: '<S300>/Constant3'
       *  RelationalOperator: '<S308>/UpperRelop'
       */
      if (CatAcvDiagT_DWork.UnitDelay_DSTATE_j < 0.0F) {
        localSwitch2_m = 0.0F;
      }

      /* Switch: '<S308>/Switch2' incorporates:
       *  RelationalOperator: '<S308>/LowerRelop1'
       */
      if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_j > localSwitch_md)) {
        localSwitch_md = localSwitch2_m;
      }

      /* Switch: '<S300>/Switch1' incorporates:
       *  Constant: '<S300>/Constant4'
       *  Constant: '<S300>/Constant7'
       *  Logic: '<S300>/Logical Operator2'
       *  Logic: '<S304>/Logical Operator'
       *  Logic: '<S304>/Logical Operator1'
       *  Sum: '<S300>/Sum1'
       */
      if ((localMemory_e) || ((!localIn_l) && (localR_g))) {
        localSwitch_md = 0.0F;
      } else {
        localSwitch_md = (localTe_e + localSwitch_md) + 2.220446049E-016F;
      }

      /* RelationalOperator: '<S300>/Relational Operator2' */
      localUnitDelay1 = (localSwitch_md >= (((Float32)localrtmax_0) *
        3.999999911E-002F));

      /* UnitDelay: '<S305>/UnitDelay' */
      localR_g = CatAcvDiagT_DWork.UnitDelay_j;

      /* RelationalOperator: '<S300>/Relational Operator1' incorporates:
       *  Constant: '<S300>/Constant2'
       */
      localRelationalOperator1_c = (localrtmax_0 == 0);

      /* Switch: '<S300>/Switch' incorporates:
       *  Constant: '<S300>/Constant5'
       *  Logic: '<S300>/Logical Operator1'
       *  Logic: '<S305>/Logical Operator'
       *  Logic: '<S305>/Logical Operator1'
       */
      if (!localRelationalOperator1_c) {
        localR_g = ((localUnitDelay1) && (!localR_g));
      } else {
        localR_g = TRUE;
      }

      /* Memory: '<S302>/Memory' */
      localMemory_e = CatAcvDiagT_DWork.Memory_PreviousInput_e;

      /* CombinatorialLogic: '<S302>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localIn_l != 0);
        rowidx = (rowidx << 1) + (UInt32)(localR_g != 0);
        rowidx = (rowidx << 1) + (UInt32)(localMemory_e != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_c[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
        localLogic_c[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
      }

      /* SignalConversion: '<S284>/Signal Conversion2' */
      OxC_bRlamFilOxCCdn = localLogic_c[0];

      /* Update for UnitDelay: '<S300>/Unit Delay' */
      CatAcvDiagT_DWork.UnitDelay_DSTATE_dq = localRelationalOperator1_c;

      /* Update for UnitDelay: '<S304>/UnitDelay' */
      CatAcvDiagT_DWork.UnitDelay_o = localIn_l;

      /* Update for UnitDelay: '<S303>/Unit Delay' */
      CatAcvDiagT_DWork.UnitDelay_DSTATE_j = localSwitch_md;

      /* Update for UnitDelay: '<S305>/UnitDelay' */
      CatAcvDiagT_DWork.UnitDelay_j = localUnitDelay1;

      /* Update for Memory: '<S302>/Memory' */
      CatAcvDiagT_DWork.Memory_PreviousInput_e = localLogic_c[0];
    }

    /* Update for UnitDelay: '<S286>/Unit Delay1' */
    CatAcvDiagT_DWork.UnitDelay1_DSTATE_j = localLogicalOperator1_i1;

    /* Update for UnitDelay: '<S312>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_il = localRelationalOperator1_jf;

    /* Update for UnitDelay: '<S316>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_dlq = localTmpSignalConversionAtInjSy;

    /* Update for UnitDelay: '<S311>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_n = localSwitch1_pb;

    /* Update for UnitDelay: '<S317>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_krj = localRelationalOperator2_d;

    /* Update for Memory: '<S309>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_d = localLogic_ea[0];

    /* end of Outputs for SubSystem: '<S270>/01_Tester_regul_richesse' */

    /* Lookup2D: '<S279>/Look-Up Table (2-D)'
     * About '<S279>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-9  FSlope 1.5625
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Nearest
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    {
      UInt32 iRowIndex1, iColumnIndex1;
      BINARYSEARCH_U16_Near_iL( &(iRowIndex1), localTmpSignalConversionAtExt_n,
                               (&(OxC_bAirLdNAuthRowInput_A[0])), 15U);
      BINARYSEARCH_U16_Near_iL( &(iColumnIndex1),
        localTmpSignalConversionAtEngin, (&(OxC_bAirLdNAuthColInput_A[0])), 14U);
      /*-MD localLookUpTable2D_b = OxC_bAirLdNAuth_M[iRowIndex1+16*iColumnIndex1];*/
      localLookUpTable2D_b = OxC_bAirLdNAuth_M[iColumnIndex1][iRowIndex1];
    }

    /* DataTypeDuplicate Block: '<S279>/Data Type Duplicate2'
     *
     * Regarding '<S279>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S280>/Data Type Conversion' */
    localDataTypeConversion = CatAcvDiagT_B.TmpSignalConversionAtExt_tOxC_i;

    /* DataTypeConversion: '<S280>/Data Type Conversion1' */
    localDataTypeConversion1_n = CatAcvDiagT_B.TmpSignalConversionAtAirSys_m_n;

    /* Lookup2D: '<S280>/Look-Up Table (2-D)'
     * About '<S280>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        S16
     * Input1  Data Type:  Fixed Point    U16  2^-7  FSlope 1.28
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Nearest
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    {
      UInt32 iRowIndex1, iColumnIndex1;
      BINARYSEARCH_S16_Near_iL( &(iRowIndex1), localDataTypeConversion,
        (&(OxC_tOxC_A[0])), 15U);
      BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), localDataTypeConversion1_n,
                               (&(OxC_mfDsThr_A[0])), 15U);
      /*-MD localLookUpTable2D_l = OxC_bAirMfTAuth_M[iRowIndex1+16*iColumnIndex1];*/
      localLookUpTable2D_l = OxC_bAirMfTAuth_M[iColumnIndex1][iRowIndex1];
    }

    /* DataTypeDuplicate Block: '<S280>/Data Type Duplicate2'
     *
     * Regarding '<S280>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S270>/DTConv_Single_To_UFix_2' */
    OxC_bAirMfTAuth = (localLookUpTable2D_l != 0);

    /* DataTypeConversion: '<S270>/DTConv_Single_To_UFix_3' */
    OxC_bAirLdNAuth = (localLookUpTable2D_b != 0);

    /* RelationalOperator: '<S270>/Relational Operator22' incorporates:
     *  Constant: '<S270>/SenO2Us_SampleTiFast_SC(1)11'
     */
    localR_k = (CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_h == Ext_stGasMod_SC);

    /* Switch: '<S270>/Switch7' incorporates:
     *  Constant: '<S270>/OxC_tCoMesHiThd_C(1)'
     *  Constant: '<S270>/OxC_tCoMesHiThd_C(1)1'
     */
    if (localR_k) {
      localSwitch5 = OxC_tCoMesHiThdGas_C;
    } else {
      localSwitch5 = OxC_tCoMesHiThd_C;
    }

    /* RelationalOperator: '<S270>/Relational Operator2' */
    localRelationalOperator1_c = (localSwitch5 >=
      localTmpSignalConversionAtExt_j);

    /* Switch: '<S270>/Switch1' incorporates:
     *  Constant: '<S270>/OxC_tCoMesLoThd_C(1)'
     *  Constant: '<S270>/OxC_tCoMesLoThd_C(1)1'
     */
    if (localR_k) {
      localSwitch5 = OxC_tCoMesLoThdGas_C;
    } else {
      localSwitch5 = OxC_tCoMesLoThd_C;
    }

    /* RelationalOperator: '<S270>/Relational Operator1' */
    localUnitDelay1 = (localTmpSignalConversionAtExt_j >= localSwitch5);

    /* Switch: '<S270>/Switch2' incorporates:
     *  Constant: '<S270>/OxC_tAirMnfMesHiThd_C(1)'
     *  Constant: '<S270>/OxC_tAirMnfMesHiThd_C(1)1'
     */
    if (localR_k) {
      localSwitch5 = OxC_tAirMnfMesHiThdGas_C;
    } else {
      localSwitch5 = OxC_tAirMnfMesHiThd_C;
    }

    /* RelationalOperator: '<S270>/Relational Operator4' */
    localTmpSignalConversionAtInjSy = (localSwitch5 >=
      localTmpSignalConversionAtExt_t);

    /* Switch: '<S270>/Switch5' incorporates:
     *  Constant: '<S270>/OxC_tAirMnfMesLoThd_C(1)'
     *  Constant: '<S270>/OxC_tAirMnfMesLoThd_C(1)1'
     */
    if (localR_k) {
      localSwitch5 = OxC_tAirMnfMesLoThdGas_C;
    } else {
      localSwitch5 = OxC_tAirMnfMesLoThd_C;
    }

    /* Switch: '<S270>/Switch6' */
    if (localR_k) {
      localR_k = localTmpSignalConversionAtFle_f;
    } else {
      localR_k = localTmpSignalConversionAtFlev_;
    }

    /* Logic: '<S270>/Logical Operator1' */
    localLogicalOperator1_i1 = !localR_k;

    /* Logic: '<S270>/Logical Operator13' incorporates:
     *  Constant: '<S270>/SenO2Us_SampleTiFast_SC(1)5'
     *  Constant: '<S270>/SenO2Us_SampleTiFast_SC(1)6'
     *  RelationalOperator: '<S270>/Relational Operator13'
     *  RelationalOperator: '<S270>/Relational Operator14'
     */
    localR_k = ((CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_h !=
                 Ext_stTranGslGas_SC) &&
                (CatAcvDiagT_B.TmpSignalConversionAtExt_stSy_h !=
                 Ext_stTranGasGsl_SC));

    /* Sum: '<S270>/Sum1' incorporates:
     *  Constant: '<S270>/SenO2Us_SampleTiFast_SC(1)3'
     *  UnitDelay: '<S282>/Unit Delay'
     */
    localrtmax = CatAcvDiagT_DWork.UnitDelay_DSTATE_dy - CatMon_SampleTiMid_SC;
    if (localrtmax <= 0) {
      localrtmax_0 = 0U;
    } else {
      localrtmax_0 = (UInt16)localrtmax;
    }

    /* Switch: '<S270>/Switch4' incorporates:
     *  Constant: '<S270>/SenO2Us_SampleTiFast_SC(1)4'
     */
    if (!localR_k) {
      localrtmax_0 = CatMon_tiInhDiagIntr_C;
    }

    /* MinMax: '<S270>/MinMax' incorporates:
     *  Constant: '<S270>/Constant3'
     */
    CatMon_tiInhDiagIntr = localrtmax_0;

    /* Switch: '<S270>/Switch3' incorporates:
     *  Constant: '<S270>/Constant2'
     *  Constant: '<S270>/Constant4'
     *  Logic: '<S270>/Logical Operator11'
     *  Logic: '<S270>/Logical Operator12'
     *  RelationalOperator: '<S270>/Relational Operator16'
     */
    if (!localTmpSignalConversionAtExt_b) {
      localR_k = TRUE;
    } else {
      localR_k = ((localR_k) && (CatMon_tiInhDiagIntr == 0));
    }

    /* Switch: '<S270>/Switch16' incorporates:
     *  Constant: '<S270>/Constant1'
     *  Constant: '<S270>/SenO2Us_SampleTiFast_SC(1)2'
     *  Logic: '<S270>/Logical Operator14'
     */
    if (CatMon_bInhDiagPresScav_C) {
      localLogicalOperator3_n = TRUE;
    } else {
      localLogicalOperator3_n = !localTmpSignalConversionAtVlvAc;
    }

    /* Logic: '<S270>/Logical Operator' incorporates:
     *  Constant: '<S270>/OxC_mfDsThrLoThd_C(1)3'
     *  Constant: '<S270>/OxC_mfDsThrLoThd_C(1)4'
     *  Logic: '<S270>/Logical Operator10'
     *  Logic: '<S270>/Logical Operator15'
     *  Logic: '<S270>/Logical Operator16'
     *  Logic: '<S270>/Logical Operator2'
     *  Logic: '<S270>/Logical Operator3'
     *  Logic: '<S270>/Logical Operator6'
     *  Logic: '<S270>/Logical Operator7'
     *  RelationalOperator: '<S270>/Relational Operator3'
     */
    localLogicalOperator1_i1 = ((((((((((((((OxC_bAirLdNAuth &&
      (localTmpSignalConversionAtLshd_)) && ((localTmpSignalConversionAtBlby_) ||
      OxC_bInhBlbyCdn_C)) && (localTmpSignalConversionAtLsh_k)) &&
      ((localRelationalOperator1_c) && (localUnitDelay1))) &&
      ((localTmpSignalConversionAtInjSy) && (localTmpSignalConversionAtExt_t >=
      localSwitch5))) && (localLogicalOperator1_i1)) && OxC_bAirMfTAuth) &&
      (localTmpSignalConversionAtOxC_b)) && (localR_k)) &&
      (localLogicalOperator3_n)) &&
      (!CatAcvDiagT_B.TmpSignalConversionAtLsMon_bAcv)) &&
      ((localTmpSignalConversionAtAFA_b) || OxC_bInhAFACdn_C)) &&
      OxC_bRlamFilOxCCdn) && (!((CatAcvDiagT_B.TmpSignalConversionAtOxC_bMonEn ||
                                   (localNot_e)) || (localNot))));

    /* Logic: '<S281>/Logical Operator3' */
    localLogicalOperator3_n = !localLogicalOperator1_i1;

    /* Sum: '<S281>/Sum2' incorporates:
     *  Constant: '<S270>/OxC_nCkHiThd_C(1)8'
     *  Constant: '<S281>/Constant1'
     *  Constant: '<S281>/Constant6'
     *  MinMax: '<S281>/MinMax1'
     *  Product: '<S322>/Divide'
     */
    localSwitch_md = (((Float32)OxC_tiAcvCdnDlyOn_C) * 3.999999911E-002F) +
      (10.0F * localTe_e);

    /* Switch: '<S319>/Switch' incorporates:
     *  Constant: '<S281>/Constant3'
     *  RelationalOperator: '<S319>/UpperRelop'
     *  UnitDelay: '<S320>/Unit Delay'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_i < 0.0F) {
      localSwitch2_m = 0.0F;
    } else {
      localSwitch2_m = CatAcvDiagT_DWork.UnitDelay_DSTATE_i;
    }

    /* Switch: '<S319>/Switch2' incorporates:
     *  RelationalOperator: '<S319>/LowerRelop1'
     *  UnitDelay: '<S320>/Unit Delay'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_i > localSwitch_md)) {
      localSwitch_md = localSwitch2_m;
    }

    /* Switch: '<S281>/Switch1' incorporates:
     *  Constant: '<S281>/Constant4'
     *  Constant: '<S281>/Constant7'
     *  Logic: '<S281>/Logical Operator2'
     *  Logic: '<S323>/Logical Operator'
     *  Logic: '<S323>/Logical Operator1'
     *  Sum: '<S281>/Sum1'
     *  UnitDelay: '<S321>/Unit Delay'
     *  UnitDelay: '<S325>/Unit Delay'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_ed || ((localLogicalOperator1_i1) &&
         (!CatAcvDiagT_DWork.UnitDelay_DSTATE_iu))) {
      localSwitch_md = 0.0F;
    } else {
      localSwitch_md = (localTe_e + localSwitch_md) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S281>/Relational Operator2' incorporates:
     *  MinMax: '<S281>/MinMax1'
     */
    localUnitDelay1 = (localSwitch_md >= (((Float32)OxC_tiAcvCdnDlyOn_C) *
      3.999999911E-002F));

    /* RelationalOperator: '<S281>/Relational Operator1' incorporates:
     *  Constant: '<S281>/Constant2'
     *  MinMax: '<S281>/MinMax1'
     */
    localRelationalOperator1_c = (OxC_tiAcvCdnDlyOn_C == 0);

    /* Switch: '<S281>/Switch' incorporates:
     *  Constant: '<S281>/Constant5'
     *  Logic: '<S281>/Logical Operator1'
     *  Logic: '<S324>/Logical Operator'
     *  Logic: '<S324>/Logical Operator1'
     *  UnitDelay: '<S326>/Unit Delay'
     */
    if (!localRelationalOperator1_c) {
      localR_k = ((localUnitDelay1) && (!CatAcvDiagT_DWork.UnitDelay_DSTATE_jz));
    } else {
      localR_k = TRUE;
    }

    /* Memory: '<S318>/Memory' */
    localMemory_g = CatAcvDiagT_DWork.Memory_PreviousInput_h;

    /* CombinatorialLogic: '<S318>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_n != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_k != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_g != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_e[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_e[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* SignalConversion: '<S270>/Signal Conversion2' */
    CatAcvDiagT_B.Merge1_n = localLogic_e[1];

    /* Update for UnitDelay: '<S282>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_dy = CatMon_tiInhDiagIntr;

    /* Update for UnitDelay: '<S321>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ed = localRelationalOperator1_c;

    /* Update for UnitDelay: '<S325>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_iu = localLogicalOperator1_i1;

    /* Update for UnitDelay: '<S320>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_i = localSwitch_md;

    /* Update for UnitDelay: '<S326>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_jz = localUnitDelay1;

    /* Update for Memory: '<S318>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_h = localLogic_e[0];
  }

  /* end of Outputs for SubSystem: '<S8>/Conditions_activation_diag_intrusif' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bMonORngIntrAcvCdn_INPUTOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonORngIntrAcvCdn_INPUT'
   */
  Rte_Read_R_OxC_bMonORngIntrAcvCdn_OxC_bMonORngIntrAcvCdn
    (&localTmpSignalConversionAtOxC_p);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bRlamAdpReq_INPUTOutport2' incorporates:
   *  Inport: '<Root>/OxC_bRlamAdpReq_INPUT'
   */
  Rte_Read_R_OxC_bRlamAdpReq_OxC_bRlamAdpReq(&localTmpSignalConversionAtOx_bf);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bMonEnaORngIntr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonEnaORngIntr_INPUT'
   */
  Rte_Read_R_OxC_bMonEnaORngIntr_OxC_bMonEnaORngIntr
    (&CatAcvDiagT_B.TmpSignalConversionAtOxC_bMon_e);

  /* Outputs for enable SubSystem: '<S8>/Subsystem' incorporates:
   *  EnablePort: '<S273>/OxC_bMonReqORngIntr_NOT'
   *  Logic: '<S8>/Logical Operator'
   */
  if (!localTmpSignalConversionAtOx_bs) {
    /* SignalConversion: '<S273>/Signal Conversion1' */
    CatAcvDiagT_B.Merge1_n = localTmpSignalConversionAtOxC_p;

    /* SignalConversion: '<S273>/Signal Conversion3' */
    CatAcvDiagT_B.Merge3_l = CatAcvDiagT_B.TmpSignalConversionAtOxC_bMon_e;

    /* SignalConversion: '<S273>/Signal Conversion2' */
    CatAcvDiagT_B.Merge2_g = localTmpSignalConversionAtOx_bf;
  }

  /* end of Outputs for SubSystem: '<S8>/Subsystem' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bAcvPrioMgtOutport2' incorporates:
   *  Inport: '<Root>/OxC_bAcvPrioMgt'
   */
  Rte_Read_R_OxC_bAcvPrioMgt_OxC_bAcvPrioMgt(&localTmpSignalConversionAtOxC_e);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bRlamAdaptFrzOutport2' incorporates:
   *  Inport: '<Root>/OxC_bRlamAdaptFrz'
   */
  Rte_Read_R_OxC_bRlamAdaptFrz_OxC_bRlamAdaptFrz
    (&localTmpSignalConversionAtOxC_a);

  /* Outputs for enable SubSystem: '<S8>/Synthese_cdn_autorisation' incorporates:
   *  EnablePort: '<S274>/OxC_bMonReqORngIntr'
   */
  if (localTmpSignalConversionAtOx_bs) {
    /* Logic: '<S274>/Logical Operator9' incorporates:
     *  SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bMonORngIntrStabCdnOutport2'
     */
    localLogicalOperator1_i1 = ((CatAcvDiagT_B.Merge1_n &&
      (Rte_IrvRead_RE_CatMon_SdlMid_CatAcvDiag_OxC_bMonORngIntrStabCdn_irv())) &&
                                (localTmpSignalConversionAtOxC_e));

    /* Logic: '<S274>/Logical Operator1' */
    CatAcvDiagT_B.Merge3_l = ((localLogicalOperator1_i1) &&
      (localTmpSignalConversionAtOxC_a));

    /* SignalConversion: '<S274>/Signal Conversion2' */
    CatAcvDiagT_B.Merge2_g = localLogicalOperator1_i1;
  }

  /* end of Outputs for SubSystem: '<S8>/Synthese_cdn_autorisation' */

  /* Switch: '<S277>/Switch' incorporates:
   *  Constant: '<S277>/Byp_Fonction_SC'
   *  Constant: '<S277>/Int_BypC'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localLogicalOperator1_i1 = OxC_bMonEnaORngIntr_B;
  } else {
    localLogicalOperator1_i1 = CatAcvDiagT_B.Merge3_l;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bMonEnaORngIntrInport2' */
  Rte_Write_P_OxC_bMonEnaORngIntr_OxC_bMonEnaORngIntr(localLogicalOperator1_i1);

  /* Switch: '<S275>/Switch' incorporates:
   *  Constant: '<S275>/Byp_Fonction_SC'
   *  Constant: '<S275>/Int_BypC'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localLogicalOperator1_i1 = OxC_bMonORngIntrAcvCdn_B;
  } else {
    localLogicalOperator1_i1 = CatAcvDiagT_B.Merge1_n;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bMonORngIntrAcvCdnInport2' */
  Rte_Write_P_OxC_bMonORngIntrAcvCdn_OxC_bMonORngIntrAcvCdn
    (localLogicalOperator1_i1);

  /* Switch: '<S276>/Switch' incorporates:
   *  Constant: '<S276>/Byp_Fonction_SC'
   *  Constant: '<S276>/Int_BypC'
   */
  if (CATACVDIAGT_ACTIVE_BYP_C) {
    localLogicalOperator1_i1 = OxC_bRlamAdpReq_B;
  } else {
    localLogicalOperator1_i1 = CatAcvDiagT_B.Merge2_g;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtOxC_bRlamAdpReqInport2' */
  Rte_Write_P_OxC_bRlamAdpReq_OxC_bRlamAdpReq(localLogicalOperator1_i1);
}

/* Start for exported function: RE_CatMon_SdlSlow_CatAcvDiag */
void RE_CatMon_SdlSlow_CatAcvDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/02_Conditions_stabilite_diag_intrusif'
   *
   * Block requirements for '<S1>/02_Conditions_stabilite_diag_intrusif':
   *  1. SubSystem "02_Conditions_stabilite_diag_intrusif" !Trace_To : VEMS_R_09_02846_001.03 ;
   *  2. SubSystem "02_Conditions_stabilite_diag_intrusif" !Trace_To : VEMS_R_09_02846_002.01 ;
   */

  /* Start for enable SubSystem: '<S7>/Conditions_stabilite_diag_intrusif' */

  /* Start for atomic SubSystem: '<S28>/01_Tester_cdn_Stablilite' */

  /* Start for atomic SubSystem: '<S31>/05_Tester_stab_regul_richesse' */

  /* Start for ifaction SubSystem: '<S37>/01_Tester_stab_regul_richesse_activee' */

  /* Start for ifaction SubSystem: '<S162>/02_Tester_stab_regul_richesse_active_mon_not_running' */

  /* InitializeConditions for atomic SubSystem: '<S172>/01_Tester_Filtrage_regul_richesse' */

  /* InitializeConditions for Memory: '<S190>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_m = TRUE;

  /* end of InitializeConditions for SubSystem: '<S172>/01_Tester_Filtrage_regul_richesse' */

  /* end of Start for SubSystem: '<S162>/02_Tester_stab_regul_richesse_active_mon_not_running' */

  /* end of Start for SubSystem: '<S37>/01_Tester_stab_regul_richesse_activee' */

  /* end of Start for SubSystem: '<S31>/05_Tester_stab_regul_richesse' */

  /* end of Start for SubSystem: '<S28>/01_Tester_cdn_Stablilite' */

  /* InitializeConditions for atomic SubSystem: '<S28>/01_Tester_cdn_Stablilite' */

  /* InitializeConditions for atomic SubSystem: '<S31>/01_Tester_stab_regime_moteur' */

  /* InitializeConditions for atomic SubSystem: '<S33>/01_Tester_Filtrage_regime_moteur' */

  /* InitializeConditions for Memory: '<S62>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_l = TRUE;

  /* end of InitializeConditions for SubSystem: '<S33>/01_Tester_Filtrage_regime_moteur' */

  /* end of InitializeConditions for SubSystem: '<S31>/01_Tester_stab_regime_moteur' */

  /* InitializeConditions for atomic SubSystem: '<S31>/02_Tester_stab_charge_moteur' */

  /* InitializeConditions for atomic SubSystem: '<S34>/01_Tester_Filtrage_charge_moteur' */

  /* InitializeConditions for Memory: '<S91>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_n = TRUE;

  /* end of InitializeConditions for SubSystem: '<S34>/01_Tester_Filtrage_charge_moteur' */

  /* end of InitializeConditions for SubSystem: '<S31>/02_Tester_stab_charge_moteur' */

  /* InitializeConditions for atomic SubSystem: '<S31>/03_Tester_stab_temp_cata' */

  /* InitializeConditions for atomic SubSystem: '<S35>/01_Tester_Filtrage_temp_cata' */

  /* InitializeConditions for Memory: '<S120>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_b = TRUE;

  /* end of InitializeConditions for SubSystem: '<S35>/01_Tester_Filtrage_temp_cata' */

  /* end of InitializeConditions for SubSystem: '<S31>/03_Tester_stab_temp_cata' */

  /* InitializeConditions for atomic SubSystem: '<S31>/04_Tester_stab_debit_moteur' */

  /* InitializeConditions for atomic SubSystem: '<S36>/01_Tester_Filtrage_debit_moteur' */

  /* InitializeConditions for Memory: '<S149>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_g = TRUE;

  /* end of InitializeConditions for SubSystem: '<S36>/01_Tester_Filtrage_debit_moteur' */

  /* end of InitializeConditions for SubSystem: '<S31>/04_Tester_stab_debit_moteur' */

  /* InitializeConditions for atomic SubSystem: '<S31>/08_Tester_stab_transition_mode' */

  /* InitializeConditions for Memory: '<S239>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_a = TRUE;

  /* end of InitializeConditions for SubSystem: '<S31>/08_Tester_stab_transition_mode' */

  /* InitializeConditions for atomic SubSystem: '<S31>/05_Tester_stab_regul_richesse' */

  /* InitializeConditions for Memory: '<S207>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_jn = TRUE;

  /* end of InitializeConditions for SubSystem: '<S31>/05_Tester_stab_regul_richesse' */

  /* InitializeConditions for atomic SubSystem: '<S31>/06_Tester_stab_purge_canister' */

  /* InitializeConditions for Memory: '<S219>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_o = TRUE;

  /* end of InitializeConditions for SubSystem: '<S31>/06_Tester_stab_purge_canister' */

  /* InitializeConditions for atomic SubSystem: '<S31>/07_Tester_stab_coupure_injection' */

  /* InitializeConditions for Memory: '<S229>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput_j = TRUE;

  /* end of InitializeConditions for SubSystem: '<S31>/07_Tester_stab_coupure_injection' */

  /* end of InitializeConditions for SubSystem: '<S28>/01_Tester_cdn_Stablilite' */

  /* InitializeConditions for atomic SubSystem: '<S28>/02_Compiler_tests_stabilite' */

  /* InitializeConditions for Memory: '<S261>/Memory' */
  CatAcvDiagT_DWork.Memory_PreviousInput = TRUE;

  /* end of InitializeConditions for SubSystem: '<S28>/02_Compiler_tests_stabilite' */

  /* end of Start for SubSystem: '<S7>/Conditions_stabilite_diag_intrusif' */
}

/* Output and update for exported function: RE_CatMon_SdlSlow_CatAcvDiag */
void RE_CatMon_SdlSlow_CatAcvDiag(void)
{
  /* local block i/o variables */
  Boolean localLogic_g2[2];
  Boolean localIn_a;
  Boolean localLogic_a[2];
  Boolean localLogic_k[2];
  Boolean localLogic_am[2];
  Boolean localLogic_b[2];
  Boolean localLogic_kb[2];
  Boolean localLogic_l[2];
  Boolean localLogic_ej[2];
  Boolean localLogic_i[2];
  Boolean localLogic_g2q[2];
  Boolean localLogic_n[2];
  Boolean localLogicalOperator3_nt;
  Boolean localLogicalOperator3_f1;
  Boolean localLogicalOperator3_nl;
  Boolean localLogicalOperator3_fa;
  Boolean localLogicalOperator3_e;
  Boolean localMemory_k;
  Boolean localMemory_jh;
  Boolean localMemory_a;
  Boolean localMemory_kw;
  Boolean localMemory_e1;
  Boolean localMemory_d;
  Boolean localLogicalOperator3_npl;
  Boolean localMemory_n;
  Boolean localLogicalOperator3_g;
  Boolean localMemory_l;
  Boolean localLogicalOperator3_ds;
  Boolean localMemory_la;
  Boolean localLogicalOperator3_p;
  Boolean localMemory_nh;
  Boolean localLogicalOperator3_l;
  Boolean localMemory_h;
  Boolean localR_l;
  Boolean localR_gl;
  Boolean localR_m;
  Boolean localR_i5;
  Boolean localR_f;
  Boolean localR_fu;
  Boolean localR_ik;
  Boolean localR_h;
  Boolean localR_e;
  Boolean localR_c;
  Boolean localR_kt;
  Boolean localTmpSignalConversionAtOxC_k;
  Float32 localTe_j;
  Float32 localSwitch_n;
  Float32 localSwitch2_f;
  Float32 localSwitch1_n;
  Boolean localRelationalOperator2_mg;
  Boolean localRelationalOperator1_f;
  Boolean localLogicalOperator3_o;
  Boolean localRelationalOperator12_h;
  Boolean localLogicalOperator4_d;
  Boolean localLogicalOperator4_f;
  Boolean localTmpSignalConversionAtEOM_b;
  Boolean localIn_dz;
  Float32 localSwitch_he;
  Boolean localRelationalOperator2_ca;
  Boolean localRelationalOperator1_ij;
  UInt8 localTmpSignalConversionAtInj_e;
  Float32 localDTConv_Single_To_UFix_3_n;
  UInt16 localSwitch4;
  Boolean localIn_ka;
  Boolean localRelationalOperator2_k;
  Boolean localRelationalOperator1_aw;
  SInt16 localSwitch5_f;
  Boolean localRelationalOperator1_k1;
  UInt8 localTmpSignalConversionAtCanPu;
  SInt32 localtmp;
  UInt8 locallocalMinMax1_l;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/02_Conditions_stabilite_diag_intrusif'
   *
   * Block requirements for '<S1>/02_Conditions_stabilite_diag_intrusif':
   *  1. SubSystem "02_Conditions_stabilite_diag_intrusif" !Trace_To : VEMS_R_09_02846_001.03 ;
   *  2. SubSystem "02_Conditions_stabilite_diag_intrusif" !Trace_To : VEMS_R_09_02846_002.01 ;
   */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAFReg_rFbLsclFilOutport2' incorporates:
   *  Inport: '<Root>/AFReg_rFbLsclFil'
   */
  Rte_Read_R_AFReg_rFbLsclFil_AFReg_rFbLsclFil
    (&CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEngine_loadOutport2' incorporates:
   *  Inport: '<Root>/Engine_load'
   */
  Rte_Read_R_Engine_load_Engine_load
    (&CatAcvDiagT_B.TmpSignalConversionAtEngine_loa);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&CatAcvDiagT_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_tOxCEstimOutport2' incorporates:
   *  Inport: '<Root>/Ext_tOxCEstim'
   */
  Rte_Read_R_Ext_tOxCEstim_Ext_tOxCEstim
    (&CatAcvDiagT_B.TmpSignalConversionAtExt_tOxCEs);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtExt_stSysGasOutport2' incorporates:
   *  Inport: '<Root>/Ext_stSysGas'
   */
  Rte_Read_R_Ext_stSysGas_Ext_stSysGas
    (&CatAcvDiagT_B.TmpSignalConversionAtExt_stSysG);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_mfAirMesThrEstim_swcOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mfAirMesThrEstim_swc'
   */
  Rte_Read_R_AirSys_mfAirMesThrEstim_swc_AirSys_mfAirMesThrEstim_swc
    (&CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInjSys_noCylCutOffOutport2' incorporates:
   *  Inport: '<Root>/InjSys_noCylCutOff'
   */
  Rte_Read_R_InjSys_noCylCutOff_InjSys_noCylCutOff
    (&localTmpSignalConversionAtInj_e);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtInjSys_bAcvFuCllOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bAcvFuCll'
   */
  Rte_Read_R_InjSys_bAcvFuCll_InjSys_bAcvFuCll
    (&CatAcvDiagT_B.TmpSignalConversionAtInjSys_bAc);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtEOM_bTranModOutport2' incorporates:
   *  Inport: '<Root>/EOM_bTranMod'
   */
  Rte_Read_R_EOM_bTranMod_EOM_bTranMod(&localTmpSignalConversionAtEOM_b);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtCanPurg_rOpCanPurgReqOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_rOpCanPurgReq'
   */
  Rte_Read_R_CanPurg_rOpCanPurgReq_CanPurg_rOpCanPurgReq
    (&localTmpSignalConversionAtCanPu);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtOxC_stMonIntrAcv_irvOutport2' */
  CatAcvDiagT_B.TmpSignalConversionAtOxC_stMonI =
    Rte_IrvRead_RE_CatMon_SdlSlow_CatAcvDiag_OxC_stMonIntrAcv_irv();

  /* SignalConversion: '<S7>/TmpSignal ConversionAtOxC_bMonReqORngIntrOutport2' incorporates:
   *  Inport: '<Root>/OxC_bMonReqORngIntr'
   */
  Rte_Read_R_OxC_bMonReqORngIntr_OxC_bMonReqORngIntr
    (&localTmpSignalConversionAtOxC_k);

  /* Outputs for enable SubSystem: '<S7>/Conditions_stabilite_diag_intrusif' incorporates:
   *  EnablePort: '<S28>/OxC_bMonReqORngIntr'
   */
  if (localTmpSignalConversionAtOxC_k) {
    /* Outputs for atomic SubSystem: '<S28>/01_Tester_cdn_Stablilite' */

    /* RelationalOperator: '<S31>/Relational Operator17' incorporates:
     *  Constant: '<S31>/OxC_mfDsThrHiThd_C(1)2'
     */
    localIn_a = (CatAcvDiagT_B.TmpSignalConversionAtOxC_stMonI == 2);

    /* UnitDelay: '<S45>/Unit Delay' */
    localMemory_jh = CatAcvDiagT_DWork.UnitDelay_DSTATE_ha;

    /* UnitDelay: '<S255>/UnitDelay' */
    localR_gl = CatAcvDiagT_DWork.UnitDelay;

    /* DataTypeConversion: '<S31>/DTConv_Single_To_UFix_1' incorporates:
     *  Constant: '<S31>/SenO2Us_SampleTiFast_SC(1)7'
     */
    localTe_j = ((Float32)CatMon_SampleTiSlow_SC) * 2.000000030E-001F;

    /* MinMax: '<S45>/MinMax1' incorporates:
     *  Constant: '<S31>/OxC_nCkHiThd_C(1)1'
     *  Constant: '<S45>/Constant1'
     */
    localtmp = mul_s32_s32_s32_sr10_sat_near(Oxc_tiStabRstOff_C * 205, 5);
    if (localtmp <= 0) {
      locallocalMinMax1_l = 0U;
    } else if (localtmp > 255) {
      locallocalMinMax1_l = MAX_uint8_T;
    } else {
      locallocalMinMax1_l = (UInt8)localtmp;
    }

    /* Sum: '<S45>/Sum2' incorporates:
     *  Constant: '<S45>/Constant6'
     *  Product: '<S45>/Product'
     */
    localSwitch2_f = (((Float32)locallocalMinMax1_l) * 2.000000030E-001F) +
      (10.0F * localTe_j);

    /* UnitDelay: '<S254>/Unit Delay' */
    localSwitch_n = CatAcvDiagT_DWork.UnitDelay_DSTATE_k;

    /* Switch: '<S259>/Switch' incorporates:
     *  Constant: '<S45>/Constant3'
     *  RelationalOperator: '<S259>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_k < 0.0F) {
      localSwitch_n = 0.0F;
    }

    /* Switch: '<S259>/Switch2' incorporates:
     *  RelationalOperator: '<S259>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_k > localSwitch2_f)) {
      localSwitch2_f = localSwitch_n;
    }

    /* Switch: '<S45>/Switch1' incorporates:
     *  Constant: '<S45>/Constant4'
     *  Constant: '<S45>/Constant7'
     *  Logic: '<S255>/Logical Operator'
     *  Logic: '<S255>/Logical Operator1'
     *  Logic: '<S45>/Logical Operator2'
     *  Sum: '<S45>/Sum1'
     */
    if ((localMemory_jh) || ((!localIn_a) && (localR_gl))) {
      localSwitch1_n = 0.0F;
    } else {
      localSwitch1_n = (localTe_j + localSwitch2_f) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S45>/Relational Operator2' */
    localRelationalOperator2_mg = (localSwitch1_n >= (((Float32)
      locallocalMinMax1_l) * 2.000000030E-001F));

    /* UnitDelay: '<S256>/UnitDelay' */
    localR_gl = CatAcvDiagT_DWork.UnitDelay_l;

    /* RelationalOperator: '<S45>/Relational Operator1' incorporates:
     *  Constant: '<S45>/Constant2'
     */
    localRelationalOperator1_f = ((locallocalMinMax1_l * 205) == 0);

    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S45>/Constant5'
     *  Logic: '<S256>/Logical Operator'
     *  Logic: '<S256>/Logical Operator1'
     *  Logic: '<S45>/Logical Operator1'
     */
    if (!localRelationalOperator1_f) {
      localR_gl = ((localRelationalOperator2_mg) && (!localR_gl));
    } else {
      localR_gl = TRUE;
    }

    /* Memory: '<S253>/Memory' */
    localMemory_jh = CatAcvDiagT_DWork.Memory_PreviousInput_k;

    /* CombinatorialLogic: '<S253>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localIn_a != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_gl != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_jh != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_a[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_a[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* Logic: '<S31>/Logical Operator3' incorporates:
     *  Constant: '<S31>/SenO2Us_SampleTiFast_SC(1)1'
     */
    localLogicalOperator3_o = ((localLogic_a[0]) && Oxc_stMonItrsvAcvTunRst_C);

    /* RelationalOperator: '<S31>/Relational Operator12' incorporates:
     *  Constant: '<S31>/SenO2Us_SampleTiFast_SC(1)8'
     */
    localRelationalOperator12_h = (CatAcvDiagT_B.TmpSignalConversionAtExt_stSysG
      == Ext_stGasMod_SC);

    /* Outputs for atomic SubSystem: '<S31>/01_Tester_stab_regime_moteur' */

    /* UnitDelay: '<S49>/Unit Delay' */
    OxC_nEngMaxPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_ek;

    /* UnitDelay: '<S48>/Unit Delay' */
    OxC_nEngMinPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_bw;

    /* UnitDelay: '<S50>/Unit Delay' */
    OxC_tiCntStabNEngPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_my;

    /* Outputs for atomic SubSystem: '<S33>/02_Tester_Tunnel_regime_moteur' */

    /* If: '<S47>/If' incorporates:
     *  ActionPort: '<S71>/Action Port'
     *  ActionPort: '<S72>/Action Port'
     *  Constant: '<S47>/OxC_nCkHiThd_C(1)2'
     *  Constant: '<S47>/SenO2Us_SampleTiFast_SC(1)2'
     *  DataTypeConversion: '<S47>/DTConv_Single_To_UFix_2'
     *  Logic: '<S47>/Logical Operator2'
     *  RelationalOperator: '<S47>/Relational Operator1'
     *  SubSystem: '<S47>/01_Tester_Tunnel_regime_moteur_no_check'
     *  SubSystem: '<S47>/02_Tester_Tunnel_regime_moteur_check'
     *  Sum: '<S47>/Sum6'
     */
    if (((OxC_nEngMaxPrev - OxC_nEngMinPrev) > OxC_nEngDeltaMaxThd_C) ||
        ((localLogicalOperator3_o) || OxC_bIdcInhChknEng_C)) {
      /* Constant: '<S71>/SenO2Us_SampleTiFast_SC(1)1' */
      OxC_tiCntStabNEng = OxC_tiDlyStabNEng_C;

      /* SignalConversion: '<S71>/Signal Conversion1' */
      OxC_nEngMax = CatAcvDiagT_B.TmpSignalConversionAtExt_nEngOu;

      /* SignalConversion: '<S71>/Signal Conversion2' */
      OxC_nEngMin = CatAcvDiagT_B.TmpSignalConversionAtExt_nEngOu;

      /* Constant: '<S71>/SenO2Us_SampleTiFast_SC(1)2' */
      OxC_bDetStabNEng = FALSE;

      /* Constant: '<S71>/SenO2Us_SampleTiFast_SC(1)3' */
      OxC_bRstFilNEng = TRUE;
    } else {
      /* If: '<S72>/If1' incorporates:
       *  ActionPort: '<S73>/Action Port'
       *  ActionPort: '<S74>/Action Port'
       *  Constant: '<S72>/SenO2Us_SampleTiFast_SC(1)1'
       *  RelationalOperator: '<S72>/Relational Operator1'
       *  SubSystem: '<S72>/01_Tester_Tunnel_regime_moteur_check_stable'
       *  SubSystem: '<S72>/02_Tester_Tunnel_regime_moteur_check_wait'
       */
      if (OxC_tiCntStabNEngPrev <= 0) {
        /* Constant: '<S73>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bDetStabNEng = TRUE;
      } else {
        /* Constant: '<S74>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bDetStabNEng = FALSE;

        /* Sum: '<S74>/Sum6' incorporates:
         *  Constant: '<S74>/SenO2Us_SampleTiFast_SC(1)7'
         */
        localtmp = OxC_tiCntStabNEngPrev - CatMon_SampleTiSlow_SC;
        if (localtmp <= 0) {
          OxC_tiCntStabNEng = 0U;
        } else {
          OxC_tiCntStabNEng = (UInt8)localtmp;
        }
      }

      /* MinMax: '<S72>/MinMax' */
      OxC_nEngMax = (UInt16)rt_MAX(OxC_nEngMaxPrev,
        CatAcvDiagT_B.TmpSignalConversionAtExt_nEngOu);

      /* MinMax: '<S72>/MinMax1' */
      OxC_nEngMin = (UInt16)rt_MIN
        (CatAcvDiagT_B.TmpSignalConversionAtExt_nEngOu, OxC_nEngMinPrev);

      /* Constant: '<S72>/SenO2Us_SampleTiFast_SC(1)2' */
      OxC_bRstFiltNEng = FALSE;

      /* SignalConversion: '<S72>/Signal Conversion2' */
      OxC_bRstFilNEng = OxC_bRstFiltNEng;
    }

    /* Logic: '<S47>/Logical Operator1' incorporates:
     *  Constant: '<S47>/OxC_nCkHiThd_C(1)3'
     */
    OxC_bStabDeltaMaxNEng = (OxC_bDetStabNEng || OxC_bInhDeltaNEng_C);

    /* Logic: '<S47>/Logical Operator4' incorporates:
     *  Constant: '<S47>/OxC_nCkHiThd_C(1)3'
     *  Logic: '<S47>/Logical Operator5'
     */
    OxC_bRstFilNEngCdn = ((!OxC_bInhDeltaNEng_C) && OxC_bRstFilNEng);

    /* end of Outputs for SubSystem: '<S33>/02_Tester_Tunnel_regime_moteur' */

    /* Outputs for atomic SubSystem: '<S33>/01_Tester_Filtrage_regime_moteur' */

    /* DataTypeConversion: '<S46>/DTConv_Single_To_UFix_3' */
    localDTConv_Single_To_UFix_3_n = (Float32)
      CatAcvDiagT_B.TmpSignalConversionAtExt_nEngOu;

    /* UnitDelay: '<S52>/Unit Delay' */
    localLogicalOperator3_l = CatAcvDiagT_DWork.UnitDelay_DSTATE_pj;

    /* Outputs for atomic SubSystem: '<S46>/DLowPassFilter_TypeT_nEng' */

    /* UnitDelay: '<S61>/Unit Delay' */
    localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_ln;

    /* Switch: '<S56>/Switch' incorporates:
     *  UnitDelay: '<S54>/Unit Delay'
     *  UnitDelay: '<S60>/Unit Delay'
     */
    if (!CatAcvDiagT_DWork.UnitDelay_DSTATE_nl) {
      localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_b3;
    }

    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S46>/OxC_nCkHiThd_C(1)3'
     *  Constant: '<S46>/OxC_nCkHiThd_C(1)9'
     *  DataTypeConversion: '<S46>/DTConv_Single_To_UFix_2'
     *  Logic: '<S46>/Logical Operator1'
     *  Logic: '<S46>/Logical Operator7'
     *  Logic: '<S51>/Logical Operator'
     *  Product: '<S57>/Divide'
     *  Product: '<S58>/Divide'
     *  Sum: '<S51>/Sum1'
     *  Sum: '<S51>/Sum2'
     *  Sum: '<S51>/Sum3'
     *  UnitDelay: '<S54>/Unit Delay'
     */
    if (!(((!localLogicalOperator3_l) || OxC_bRstFilNEngCdn) ||
          OxC_bIdcInhChknEng_C)) {
      localSwitch2_f -= (localTe_j / ((((Float32)OxC_tiNEngLpfTau_C) *
        2.000000030E-001F) + localTe_j)) * (localSwitch2_f -
        localDTConv_Single_To_UFix_3_n);
    } else {
      localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_b3;
    }

    /* Switch: '<S55>/Switch' incorporates:
     *  UnitDelay: '<S54>/Unit Delay'
     *  UnitDelay: '<S59>/Unit Delay'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_or) {
      Ext_nEngFil = localSwitch2_f;
    } else {
      Ext_nEngFil = CatAcvDiagT_DWork.UnitDelay_DSTATE_b3;
    }

    /* Update for UnitDelay: '<S59>/Unit Delay' incorporates:
     *  Constant: '<S55>/Constant3'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_or = TRUE;

    /* Update for UnitDelay: '<S61>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ln = localSwitch2_f;

    /* Update for UnitDelay: '<S60>/Unit Delay' incorporates:
     *  Constant: '<S56>/Constant3'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_nl = TRUE;

    /* end of Outputs for SubSystem: '<S46>/DLowPassFilter_TypeT_nEng' */

    /* Sum: '<S46>/Sum1' */
    localSwitch2_f = localDTConv_Single_To_UFix_3_n - Ext_nEngFil;

    /* Switch: '<S46>/Switch4' incorporates:
     *  Constant: '<S46>/OxC_nCkDeltaMax_C(1)'
     *  Constant: '<S46>/OxC_nCkDeltaMax_C(1)1'
     */
    if (localRelationalOperator12_h) {
      localSwitch4 = OxC_nCkDeltaMaxGas_C;
    } else {
      localSwitch4 = OxC_nCkDeltaMax_C;
    }

    /* RelationalOperator: '<S46>/Relational Operator9' incorporates:
     *  Abs: '<S46>/Abs1'
     *  DataTypeConversion: '<S46>/DTConv_Single_To_UFix_1'
     */
    localIn_ka = (ACTEMS_FabsF(localSwitch2_f) < ((Float32)localSwitch4));

    /* Logic: '<S53>/Logical Operator3' */
    localLogicalOperator3_l = !localIn_ka;

    /* UnitDelay: '<S65>/Unit Delay' */
    localMemory_h = CatAcvDiagT_DWork.UnitDelay_DSTATE_f0;

    /* UnitDelay: '<S69>/Unit Delay' */
    localR_kt = CatAcvDiagT_DWork.UnitDelay_DSTATE_j0;

    /* Sum: '<S53>/Sum2' incorporates:
     *  Constant: '<S46>/OxC_nCkHiThd_C(1)2'
     *  Constant: '<S53>/Constant1'
     *  Constant: '<S53>/Constant6'
     *  MinMax: '<S53>/MinMax1'
     *  Product: '<S66>/Divide'
     */
    localSwitch_n = (((Float32)OxC_tiNEngDlyOn_C) * 2.000000030E-001F) + (10.0F
      * localTe_j);

    /* UnitDelay: '<S64>/Unit Delay' */
    localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_e;

    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S53>/Constant3'
     *  RelationalOperator: '<S63>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_e < 0.0F) {
      localSwitch2_f = 0.0F;
    }

    /* Switch: '<S63>/Switch2' incorporates:
     *  RelationalOperator: '<S63>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_e > localSwitch_n)) {
      localSwitch_n = localSwitch2_f;
    }

    /* Switch: '<S53>/Switch1' incorporates:
     *  Constant: '<S53>/Constant4'
     *  Constant: '<S53>/Constant7'
     *  Logic: '<S53>/Logical Operator2'
     *  Logic: '<S67>/Logical Operator'
     *  Logic: '<S67>/Logical Operator1'
     *  Sum: '<S53>/Sum1'
     */
    if ((localMemory_h) || ((localIn_ka) && (!localR_kt))) {
      localSwitch2_f = 0.0F;
    } else {
      localSwitch2_f = (localTe_j + localSwitch_n) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S53>/Relational Operator2' incorporates:
     *  MinMax: '<S53>/MinMax1'
     */
    localRelationalOperator2_k = (localSwitch2_f >= (((Float32)
      OxC_tiNEngDlyOn_C) * 2.000000030E-001F));

    /* UnitDelay: '<S70>/Unit Delay' */
    localR_kt = CatAcvDiagT_DWork.UnitDelay_DSTATE_p5;

    /* RelationalOperator: '<S53>/Relational Operator1' incorporates:
     *  Constant: '<S53>/Constant2'
     *  MinMax: '<S53>/MinMax1'
     */
    localRelationalOperator1_aw = (OxC_tiNEngDlyOn_C == 0);

    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S53>/Constant5'
     *  Logic: '<S53>/Logical Operator1'
     *  Logic: '<S68>/Logical Operator'
     *  Logic: '<S68>/Logical Operator1'
     */
    if (!localRelationalOperator1_aw) {
      localR_kt = ((localRelationalOperator2_k) && (!localR_kt));
    } else {
      localR_kt = TRUE;
    }

    /* Memory: '<S62>/Memory' */
    localMemory_h = CatAcvDiagT_DWork.Memory_PreviousInput_l;

    /* CombinatorialLogic: '<S62>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_l != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_kt != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_h != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_n[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_n[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* Logic: '<S46>/Logical Operator2' incorporates:
     *  Constant: '<S46>/OxC_nCkHiThd_C(1)1'
     *  Constant: '<S46>/OxC_nCkHiThd_C(1)4'
     *  Logic: '<S46>/Logical Operator3'
     *  Logic: '<S46>/Logical Operator4'
     */
    OxC_bStabFilNEng = (OxC_bInhFilNEng_C || ((localLogic_n[1]) &&
      (!OxC_bIdcInhChknEng_C)));

    /* Update for UnitDelay: '<S54>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_b3 = localDTConv_Single_To_UFix_3_n;

    /* Update for UnitDelay: '<S52>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_pj = localIn_ka;

    /* Update for UnitDelay: '<S65>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_f0 = localRelationalOperator1_aw;

    /* Update for UnitDelay: '<S69>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_j0 = localIn_ka;

    /* Update for UnitDelay: '<S64>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_e = localSwitch2_f;

    /* Update for UnitDelay: '<S70>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_p5 = localRelationalOperator2_k;

    /* Update for Memory: '<S62>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_l = localLogic_n[0];

    /* end of Outputs for SubSystem: '<S33>/01_Tester_Filtrage_regime_moteur' */

    /* Logic: '<S33>/Logical Operator4' */
    localLogicalOperator4_f = (OxC_bStabFilNEng && OxC_bStabDeltaMaxNEng);

    /* Update for UnitDelay: '<S49>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ek = OxC_nEngMax;

    /* Update for UnitDelay: '<S48>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_bw = OxC_nEngMin;

    /* Update for UnitDelay: '<S50>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_my = OxC_tiCntStabNEng;

    /* end of Outputs for SubSystem: '<S31>/01_Tester_stab_regime_moteur' */

    /* Outputs for atomic SubSystem: '<S31>/02_Tester_stab_charge_moteur' */

    /* UnitDelay: '<S79>/Unit Delay' */
    OxC_rAirLdMaxPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_a;

    /* UnitDelay: '<S78>/Unit Delay' */
    OxC_rAirLdMinPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_dz;

    /* UnitDelay: '<S77>/Unit Delay' */
    OxC_tiCntStabRatAirLdPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_anj;

    /* Outputs for atomic SubSystem: '<S34>/02_Tester_Tunnel_charge_moteur' */

    /* If: '<S76>/If' incorporates:
     *  ActionPort: '<S100>/Action Port'
     *  ActionPort: '<S101>/Action Port'
     *  Constant: '<S76>/OxC_nCkHiThd_C(1)2'
     *  Constant: '<S76>/SenO2Us_SampleTiFast_SC(1)2'
     *  DataTypeConversion: '<S76>/DTConv_Single_To_UFix_2'
     *  Logic: '<S76>/Logical Operator2'
     *  RelationalOperator: '<S76>/Relational Operator1'
     *  SubSystem: '<S76>/01_Tester_Tunnel_charge_moteur_no_check'
     *  SubSystem: '<S76>/02_Tester_Tunnel_charge_moteur_check'
     *  Sum: '<S76>/Sum6'
     */
    if (((OxC_rAirLdMaxPrev - OxC_rAirLdMinPrev) > OxC_rAirLdDeltaMaxThd_C) ||
        ((localLogicalOperator3_o) || OxC_bIdcInhChkrAirLd_C)) {
      /* Constant: '<S100>/SenO2Us_SampleTiFast_SC(1)1' */
      OxC_tiCntStabRatAirLd = OxC_tiDlyStabRatAirLd_C;

      /* SignalConversion: '<S100>/Signal Conversion1' */
      OxC_rAirLdMax = CatAcvDiagT_B.TmpSignalConversionAtEngine_loa;

      /* SignalConversion: '<S100>/Signal Conversion2' */
      OxC_rAirLdMin = CatAcvDiagT_B.TmpSignalConversionAtEngine_loa;

      /* Constant: '<S100>/SenO2Us_SampleTiFast_SC(1)2' */
      OxC_bStabRatAirLdCor = FALSE;

      /* Constant: '<S100>/SenO2Us_SampleTiFast_SC(1)3' */
      OxC_bRstFilAirLd = TRUE;
    } else {
      /* If: '<S101>/If1' incorporates:
       *  ActionPort: '<S102>/Action Port'
       *  ActionPort: '<S103>/Action Port'
       *  Constant: '<S101>/SenO2Us_SampleTiFast_SC(1)1'
       *  RelationalOperator: '<S101>/Relational Operator1'
       *  SubSystem: '<S101>/01_Tester_Tunnel_charge_moteur_check_stable'
       *  SubSystem: '<S101>/02_Tester_Tunnel_charge_moteur_check_wait'
       */
      if (OxC_tiCntStabRatAirLdPrev <= 0) {
        /* Constant: '<S102>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bStabRatAirLdCor = TRUE;
      } else {
        /* Constant: '<S103>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bStabRatAirLdCor = FALSE;

        /* Sum: '<S103>/Sum6' incorporates:
         *  Constant: '<S103>/SenO2Us_SampleTiFast_SC(1)7'
         */
        localtmp = OxC_tiCntStabRatAirLdPrev - CatMon_SampleTiSlow_SC;
        if (localtmp <= 0) {
          OxC_tiCntStabRatAirLd = 0U;
        } else {
          OxC_tiCntStabRatAirLd = (UInt8)localtmp;
        }
      }

      /* MinMax: '<S101>/MinMax' */
      localSwitch4 = OxC_rAirLdMaxPrev;
      if (CatAcvDiagT_B.TmpSignalConversionAtEngine_loa > OxC_rAirLdMaxPrev) {
        localSwitch4 = CatAcvDiagT_B.TmpSignalConversionAtEngine_loa;
      }

      OxC_rAirLdMax = localSwitch4;

      /* MinMax: '<S101>/MinMax1' */
      localSwitch4 = CatAcvDiagT_B.TmpSignalConversionAtEngine_loa;
      if (OxC_rAirLdMinPrev < CatAcvDiagT_B.TmpSignalConversionAtEngine_loa) {
        localSwitch4 = OxC_rAirLdMinPrev;
      }

      OxC_rAirLdMin = localSwitch4;

      /* Constant: '<S101>/SenO2Us_SampleTiFast_SC(1)2' */
      OxC_bRstFilAirLd = FALSE;
    }

    /* Logic: '<S76>/Logical Operator1' incorporates:
     *  Constant: '<S76>/OxC_nCkHiThd_C(1)3'
     */
    OxC_bStabDeltaMaxAirLd = (OxC_bStabRatAirLdCor || OxC_bInhDeltaAirLd_C);

    /* Logic: '<S76>/Logical Operator4' incorporates:
     *  Constant: '<S76>/OxC_nCkHiThd_C(1)3'
     *  Logic: '<S76>/Logical Operator5'
     */
    OxC_bRstFilAirLdCdn = ((!OxC_bInhDeltaAirLd_C) && OxC_bRstFilAirLd);

    /* end of Outputs for SubSystem: '<S34>/02_Tester_Tunnel_charge_moteur' */

    /* Outputs for atomic SubSystem: '<S34>/01_Tester_Filtrage_charge_moteur' */

    /* DataTypeConversion: '<S75>/DTConv_Single_To_UFix_3' */
    localDTConv_Single_To_UFix_3_n = ((Float32)
      CatAcvDiagT_B.TmpSignalConversionAtEngine_loa) * 3.051757813E-003F;

    /* UnitDelay: '<S81>/Unit Delay' */
    localLogicalOperator3_p = CatAcvDiagT_DWork.UnitDelay_DSTATE_fc;

    /* Outputs for atomic SubSystem: '<S75>/DLowPassFilter_TypeT_rAirLd' */

    /* UnitDelay: '<S90>/Unit Delay' */
    localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_lx;

    /* Switch: '<S85>/Switch' incorporates:
     *  UnitDelay: '<S83>/Unit Delay'
     *  UnitDelay: '<S89>/Unit Delay'
     */
    if (!CatAcvDiagT_DWork.UnitDelay_DSTATE_cl) {
      localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_kq;
    }

    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S75>/OxC_nCkHiThd_C(1)3'
     *  Constant: '<S75>/OxC_nCkHiThd_C(1)6'
     *  DataTypeConversion: '<S75>/DTConv_Single_To_UFix_2'
     *  Logic: '<S75>/Logical Operator1'
     *  Logic: '<S75>/Logical Operator7'
     *  Logic: '<S80>/Logical Operator'
     *  Product: '<S86>/Divide'
     *  Product: '<S87>/Divide'
     *  Sum: '<S80>/Sum1'
     *  Sum: '<S80>/Sum2'
     *  Sum: '<S80>/Sum3'
     *  UnitDelay: '<S83>/Unit Delay'
     */
    if (!(((!localLogicalOperator3_p) || OxC_bRstFilAirLdCdn) ||
          OxC_bIdcInhChkrAirLd_C)) {
      localSwitch2_f -= (localTe_j / ((((Float32)OxC_tiAirLdLpfTau_C) *
        2.000000030E-001F) + localTe_j)) * (localSwitch2_f -
        localDTConv_Single_To_UFix_3_n);
    } else {
      localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_kq;
    }

    /* Switch: '<S84>/Switch' incorporates:
     *  UnitDelay: '<S83>/Unit Delay'
     *  UnitDelay: '<S88>/Unit Delay'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_i0) {
      Engine_load_filt = localSwitch2_f;
    } else {
      Engine_load_filt = CatAcvDiagT_DWork.UnitDelay_DSTATE_kq;
    }

    /* Update for UnitDelay: '<S88>/Unit Delay' incorporates:
     *  Constant: '<S84>/Constant3'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_i0 = TRUE;

    /* Update for UnitDelay: '<S90>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_lx = localSwitch2_f;

    /* Update for UnitDelay: '<S89>/Unit Delay' incorporates:
     *  Constant: '<S85>/Constant3'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_cl = TRUE;

    /* end of Outputs for SubSystem: '<S75>/DLowPassFilter_TypeT_rAirLd' */

    /* Sum: '<S75>/Sum6' */
    localSwitch2_f = localDTConv_Single_To_UFix_3_n - Engine_load_filt;

    /* Switch: '<S75>/Switch3' incorporates:
     *  Constant: '<S75>/OxC_ldEstimDeltaMax_C(1)'
     *  Constant: '<S75>/OxC_ldEstimDeltaMax_C(1)1'
     */
    if (localRelationalOperator12_h) {
      localSwitch4 = OxC_ldEstimDeltaMaxGas_C;
    } else {
      localSwitch4 = OxC_ldEstimDeltaMax_C;
    }

    /* RelationalOperator: '<S75>/Relational Operator8' incorporates:
     *  Abs: '<S75>/Abs'
     *  DataTypeConversion: '<S75>/DTConv_Single_To_UFix_1'
     */
    localIn_ka = (ACTEMS_FabsF(localSwitch2_f) < (((Float32)localSwitch4) *
      3.051757813E-003F));

    /* Logic: '<S82>/Logical Operator3' */
    localLogicalOperator3_p = !localIn_ka;

    /* UnitDelay: '<S94>/Unit Delay' */
    localMemory_nh = CatAcvDiagT_DWork.UnitDelay_DSTATE_jf;

    /* UnitDelay: '<S98>/Unit Delay' */
    localR_c = CatAcvDiagT_DWork.UnitDelay_DSTATE_aw;

    /* Sum: '<S82>/Sum2' incorporates:
     *  Constant: '<S75>/OxC_nCkHiThd_C(1)2'
     *  Constant: '<S82>/Constant1'
     *  Constant: '<S82>/Constant6'
     *  MinMax: '<S82>/MinMax1'
     *  Product: '<S95>/Divide'
     */
    localSwitch_n = (((Float32)OxC_tiAirLdDlyOn_C) * 2.000000030E-001F) +
      (10.0F * localTe_j);

    /* UnitDelay: '<S93>/Unit Delay' */
    localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_h2;

    /* Switch: '<S92>/Switch' incorporates:
     *  Constant: '<S82>/Constant3'
     *  RelationalOperator: '<S92>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_h2 < 0.0F) {
      localSwitch2_f = 0.0F;
    }

    /* Switch: '<S92>/Switch2' incorporates:
     *  RelationalOperator: '<S92>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_h2 > localSwitch_n)) {
      localSwitch_n = localSwitch2_f;
    }

    /* Switch: '<S82>/Switch1' incorporates:
     *  Constant: '<S82>/Constant4'
     *  Constant: '<S82>/Constant7'
     *  Logic: '<S82>/Logical Operator2'
     *  Logic: '<S96>/Logical Operator'
     *  Logic: '<S96>/Logical Operator1'
     *  Sum: '<S82>/Sum1'
     */
    if ((localMemory_nh) || ((localIn_ka) && (!localR_c))) {
      localSwitch2_f = 0.0F;
    } else {
      localSwitch2_f = (localTe_j + localSwitch_n) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S82>/Relational Operator2' incorporates:
     *  MinMax: '<S82>/MinMax1'
     */
    localRelationalOperator2_k = (localSwitch2_f >= (((Float32)
      OxC_tiAirLdDlyOn_C) * 2.000000030E-001F));

    /* UnitDelay: '<S99>/Unit Delay' */
    localR_c = CatAcvDiagT_DWork.UnitDelay_DSTATE_gb;

    /* RelationalOperator: '<S82>/Relational Operator1' incorporates:
     *  Constant: '<S82>/Constant2'
     *  MinMax: '<S82>/MinMax1'
     */
    localRelationalOperator1_aw = (OxC_tiAirLdDlyOn_C == 0);

    /* Switch: '<S82>/Switch' incorporates:
     *  Constant: '<S82>/Constant5'
     *  Logic: '<S82>/Logical Operator1'
     *  Logic: '<S97>/Logical Operator'
     *  Logic: '<S97>/Logical Operator1'
     */
    if (!localRelationalOperator1_aw) {
      localR_c = ((localRelationalOperator2_k) && (!localR_c));
    } else {
      localR_c = TRUE;
    }

    /* Memory: '<S91>/Memory' */
    localMemory_nh = CatAcvDiagT_DWork.Memory_PreviousInput_n;

    /* CombinatorialLogic: '<S91>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_p != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_c != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_nh != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_g2q[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_g2q[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* Logic: '<S75>/Logical Operator2' incorporates:
     *  Constant: '<S75>/OxC_nCkHiThd_C(1)1'
     *  Constant: '<S75>/OxC_nCkHiThd_C(1)4'
     *  Logic: '<S75>/Logical Operator3'
     *  Logic: '<S75>/Logical Operator4'
     */
    OxC_bStabFilAirLd = (OxC_bInhFilAirLd_C || ((localLogic_g2q[1]) &&
      (!OxC_bIdcInhChkrAirLd_C)));

    /* Update for UnitDelay: '<S83>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_kq = localDTConv_Single_To_UFix_3_n;

    /* Update for UnitDelay: '<S81>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_fc = localIn_ka;

    /* Update for UnitDelay: '<S94>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_jf = localRelationalOperator1_aw;

    /* Update for UnitDelay: '<S98>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_aw = localIn_ka;

    /* Update for UnitDelay: '<S93>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_h2 = localSwitch2_f;

    /* Update for UnitDelay: '<S99>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_gb = localRelationalOperator2_k;

    /* Update for Memory: '<S91>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_n = localLogic_g2q[0];

    /* end of Outputs for SubSystem: '<S34>/01_Tester_Filtrage_charge_moteur' */

    /* Logic: '<S34>/Logical Operator4' */
    OxC_bStabAirLd = (OxC_bStabFilAirLd && OxC_bStabDeltaMaxAirLd);

    /* Update for UnitDelay: '<S79>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_a = OxC_rAirLdMax;

    /* Update for UnitDelay: '<S78>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_dz = OxC_rAirLdMin;

    /* Update for UnitDelay: '<S77>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_anj = OxC_tiCntStabRatAirLd;

    /* end of Outputs for SubSystem: '<S31>/02_Tester_stab_charge_moteur' */

    /* Outputs for atomic SubSystem: '<S31>/10_Reinit_cdn_stab_temp_cata' */

    /* Logic: '<S250>/Logical Operator' incorporates:
     *  Logic: '<S250>/Logical Operator1'
     *  UnitDelay: '<S251>/Unit Delay'
     *  UnitDelay: '<S43>/Unit Delay'
     */
    OxC_bIdcInhChkTOxC = ((!CatAcvDiagT_DWork.UnitDelay_DSTATE_lp) &&
                          CatAcvDiagT_DWork.UnitDelay_DSTATE_bwk);

    /* Update for UnitDelay: '<S251>/Unit Delay' incorporates:
     *  UnitDelay: '<S43>/Unit Delay'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_bwk =
      CatAcvDiagT_DWork.UnitDelay_DSTATE_lp;

    /* end of Outputs for SubSystem: '<S31>/10_Reinit_cdn_stab_temp_cata' */

    /* Outputs for atomic SubSystem: '<S31>/03_Tester_stab_temp_cata' */

    /* UnitDelay: '<S108>/Unit Delay' */
    OxC_tOxCMaxPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_g2;

    /* UnitDelay: '<S107>/Unit Delay' */
    OxC_tOxCMinPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_e2;

    /* UnitDelay: '<S106>/Unit Delay' */
    OxC_tiCntOxCPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_ni;

    /* Outputs for atomic SubSystem: '<S35>/02_Tester_Tunnel_temp_cata' */

    /* If: '<S105>/If' incorporates:
     *  ActionPort: '<S129>/Action Port'
     *  ActionPort: '<S130>/Action Port'
     *  Constant: '<S105>/SenO2Us_SampleTiFast_SC(1)2'
     *  DataTypeConversion: '<S105>/DTConv_Single_To_UFix_2'
     *  Logic: '<S105>/Logical Operator2'
     *  RelationalOperator: '<S105>/Relational Operator1'
     *  SubSystem: '<S105>/01_Tester_Tunnel_temp_cata_no_check'
     *  SubSystem: '<S105>/02_Tester_Tunnel_temp_cata_check'
     *  Sum: '<S105>/Sum6'
     */
    if (((OxC_tOxCMaxPrev - OxC_tOxCMinPrev) > OxC_tOxCDeltaMaxThd_C) ||
        ((localLogicalOperator3_o) || OxC_bIdcInhChkTOxC)) {
      /* Constant: '<S129>/SenO2Us_SampleTiFast_SC(1)1' */
      OxC_tiCntStabOxCT = OxC_tiDlyStabOxCT_C;

      /* SignalConversion: '<S129>/Signal Conversion1' */
      OxC_tOxCMax = CatAcvDiagT_B.TmpSignalConversionAtExt_tOxCEs;

      /* SignalConversion: '<S129>/Signal Conversion2' */
      OxC_tOxCMin = CatAcvDiagT_B.TmpSignalConversionAtExt_tOxCEs;

      /* Constant: '<S129>/SenO2Us_SampleTiFast_SC(1)2' */
      OxC_bDetStabOxCT = FALSE;

      /* Constant: '<S129>/SenO2Us_SampleTiFast_SC(1)3' */
      OxC_bRstFilOxCT = TRUE;
    } else {
      /* If: '<S130>/If' incorporates:
       *  ActionPort: '<S131>/Action Port'
       *  ActionPort: '<S132>/Action Port'
       *  Constant: '<S130>/SenO2Us_SampleTiFast_SC(1)1'
       *  RelationalOperator: '<S130>/Relational Operator1'
       *  SubSystem: '<S130>/01_Tester_Tunnel_temp_cata_check_stable'
       *  SubSystem: '<S130>/02_Tester_Tunnel_temp_cata_check_wait'
       */
      if (OxC_tiCntOxCPrev <= 0) {
        /* Constant: '<S131>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bDetStabOxCT = TRUE;
      } else {
        /* Constant: '<S132>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bDetStabOxCT = FALSE;

        /* Sum: '<S132>/Sum6' incorporates:
         *  Constant: '<S132>/SenO2Us_SampleTiFast_SC(1)7'
         */
        localtmp = OxC_tiCntOxCPrev - CatMon_SampleTiSlow_SC;
        if (localtmp <= 0) {
          OxC_tiCntStabOxCT = 0U;
        } else {
          OxC_tiCntStabOxCT = (UInt8)localtmp;
        }
      }

      /* MinMax: '<S130>/MinMax' */
      OxC_tOxCMax = (SInt16)rt_MAX(OxC_tOxCMaxPrev,
        CatAcvDiagT_B.TmpSignalConversionAtExt_tOxCEs);

      /* MinMax: '<S130>/MinMax1' */
      OxC_tOxCMin = (SInt16)rt_MIN
        (CatAcvDiagT_B.TmpSignalConversionAtExt_tOxCEs, OxC_tOxCMinPrev);

      /* Constant: '<S130>/SenO2Us_SampleTiFast_SC(1)2' */
      OxC_bRstFilOxCT = FALSE;
    }

    /* Logic: '<S105>/Logical Operator1' incorporates:
     *  Constant: '<S105>/OxC_nCkHiThd_C(1)3'
     */
    OxC_bStabDeltaMaxOxCT = (OxC_bDetStabOxCT || OxC_bInhDeltaTOxC_C);

    /* Logic: '<S105>/Logical Operator4' incorporates:
     *  Constant: '<S105>/OxC_nCkHiThd_C(1)3'
     *  Logic: '<S105>/Logical Operator5'
     */
    OxC_bRstFilOxCTCdn = ((!OxC_bInhDeltaTOxC_C) && OxC_bRstFilOxCT);

    /* end of Outputs for SubSystem: '<S35>/02_Tester_Tunnel_temp_cata' */

    /* Outputs for atomic SubSystem: '<S35>/01_Tester_Filtrage_temp_cata' */

    /* DataTypeConversion: '<S104>/DTConv_Single_To_UFix_1' */
    localDTConv_Single_To_UFix_3_n = (Float32)
      CatAcvDiagT_B.TmpSignalConversionAtExt_tOxCEs;

    /* UnitDelay: '<S110>/Unit Delay' */
    localLogicalOperator3_ds = CatAcvDiagT_DWork.UnitDelay_DSTATE_nv;

    /* Outputs for atomic SubSystem: '<S104>/DLowPassFilter_TypeT_rAirLd' */

    /* UnitDelay: '<S119>/Unit Delay' */
    localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_d;

    /* Switch: '<S114>/Switch' incorporates:
     *  UnitDelay: '<S112>/Unit Delay'
     *  UnitDelay: '<S118>/Unit Delay'
     */
    if (!CatAcvDiagT_DWork.UnitDelay_DSTATE_na) {
      localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_le;
    }

    /* Switch: '<S109>/Switch' incorporates:
     *  Constant: '<S104>/OxC_nCkHiThd_C(1)5'
     *  DataTypeConversion: '<S104>/DTConv_Single_To_UFix_2'
     *  Logic: '<S104>/Logical Operator1'
     *  Logic: '<S104>/Logical Operator7'
     *  Logic: '<S109>/Logical Operator'
     *  Product: '<S115>/Divide'
     *  Product: '<S116>/Divide'
     *  Sum: '<S109>/Sum1'
     *  Sum: '<S109>/Sum2'
     *  Sum: '<S109>/Sum3'
     *  UnitDelay: '<S112>/Unit Delay'
     */
    if (!(((!localLogicalOperator3_ds) || OxC_bRstFilOxCTCdn) ||
          OxC_bIdcInhChkTOxC)) {
      localSwitch2_f -= (localTe_j / ((((Float32)OxC_tiOxCTLpfTau_C) *
        2.000000030E-001F) + localTe_j)) * (localSwitch2_f -
        localDTConv_Single_To_UFix_3_n);
    } else {
      localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_le;
    }

    /* Switch: '<S113>/Switch' incorporates:
     *  UnitDelay: '<S112>/Unit Delay'
     *  UnitDelay: '<S117>/Unit Delay'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_a1) {
      Ext_tOxCEstimFil = localSwitch2_f;
    } else {
      Ext_tOxCEstimFil = CatAcvDiagT_DWork.UnitDelay_DSTATE_le;
    }

    /* Update for UnitDelay: '<S117>/Unit Delay' incorporates:
     *  Constant: '<S113>/Constant3'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_a1 = TRUE;

    /* Update for UnitDelay: '<S119>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_d = localSwitch2_f;

    /* Update for UnitDelay: '<S118>/Unit Delay' incorporates:
     *  Constant: '<S114>/Constant3'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_na = TRUE;

    /* end of Outputs for SubSystem: '<S104>/DLowPassFilter_TypeT_rAirLd' */

    /* Sum: '<S104>/Sum4' */
    localSwitch2_f = localDTConv_Single_To_UFix_3_n - Ext_tOxCEstimFil;

    /* Switch: '<S104>/Switch5' incorporates:
     *  Constant: '<S104>/OxC_tOxCUsMesDeltaMax_C(1)'
     *  Constant: '<S104>/OxC_tOxCUsMesDeltaMax_C(1)1'
     */
    if (localRelationalOperator12_h) {
      localSwitch5_f = OxC_tOxCUsMesDeltaMaxGas_C;
    } else {
      localSwitch5_f = OxC_tOxCUsMesDeltaMax_C;
    }

    /* RelationalOperator: '<S104>/Relational Operator13' incorporates:
     *  Abs: '<S104>/Abs2'
     *  DataTypeConversion: '<S104>/DTConv_Single_To_UFix_3'
     */
    localIn_ka = (ACTEMS_FabsF(localSwitch2_f) < ((Float32)localSwitch5_f));

    /* Logic: '<S111>/Logical Operator3' */
    localLogicalOperator3_ds = !localIn_ka;

    /* UnitDelay: '<S123>/Unit Delay' */
    localMemory_la = CatAcvDiagT_DWork.UnitDelay_DSTATE_gj;

    /* UnitDelay: '<S127>/Unit Delay' */
    localR_e = CatAcvDiagT_DWork.UnitDelay_DSTATE_d2;

    /* Sum: '<S111>/Sum2' incorporates:
     *  Constant: '<S104>/OxC_nCkHiThd_C(1)2'
     *  Constant: '<S111>/Constant1'
     *  Constant: '<S111>/Constant6'
     *  MinMax: '<S111>/MinMax1'
     *  Product: '<S124>/Divide'
     */
    localSwitch_n = (((Float32)OxC_tiOxCTDlyOn_C) * 2.000000030E-001F) + (10.0F
      * localTe_j);

    /* UnitDelay: '<S122>/Unit Delay' */
    localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_kr;

    /* Switch: '<S121>/Switch' incorporates:
     *  Constant: '<S111>/Constant3'
     *  RelationalOperator: '<S121>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_kr < 0.0F) {
      localSwitch2_f = 0.0F;
    }

    /* Switch: '<S121>/Switch2' incorporates:
     *  RelationalOperator: '<S121>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_kr > localSwitch_n)) {
      localSwitch_n = localSwitch2_f;
    }

    /* Switch: '<S111>/Switch1' incorporates:
     *  Constant: '<S111>/Constant4'
     *  Constant: '<S111>/Constant7'
     *  Logic: '<S111>/Logical Operator2'
     *  Logic: '<S125>/Logical Operator'
     *  Logic: '<S125>/Logical Operator1'
     *  Sum: '<S111>/Sum1'
     */
    if ((localMemory_la) || ((localIn_ka) && (!localR_e))) {
      localSwitch2_f = 0.0F;
    } else {
      localSwitch2_f = (localTe_j + localSwitch_n) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S111>/Relational Operator2' incorporates:
     *  MinMax: '<S111>/MinMax1'
     */
    localRelationalOperator2_k = (localSwitch2_f >= (((Float32)
      OxC_tiOxCTDlyOn_C) * 2.000000030E-001F));

    /* UnitDelay: '<S128>/Unit Delay' */
    localR_e = CatAcvDiagT_DWork.UnitDelay_DSTATE_nu;

    /* RelationalOperator: '<S111>/Relational Operator1' incorporates:
     *  Constant: '<S111>/Constant2'
     *  MinMax: '<S111>/MinMax1'
     */
    localRelationalOperator1_aw = (OxC_tiOxCTDlyOn_C == 0);

    /* Switch: '<S111>/Switch' incorporates:
     *  Constant: '<S111>/Constant5'
     *  Logic: '<S111>/Logical Operator1'
     *  Logic: '<S126>/Logical Operator'
     *  Logic: '<S126>/Logical Operator1'
     */
    if (!localRelationalOperator1_aw) {
      localR_e = ((localRelationalOperator2_k) && (!localR_e));
    } else {
      localR_e = TRUE;
    }

    /* Memory: '<S120>/Memory' */
    localMemory_la = CatAcvDiagT_DWork.Memory_PreviousInput_b;

    /* CombinatorialLogic: '<S120>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_ds != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_e != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_la != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_i[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_i[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* Logic: '<S104>/Logical Operator2' incorporates:
     *  Constant: '<S104>/OxC_nCkHiThd_C(1)1'
     *  Logic: '<S104>/Logical Operator3'
     *  Logic: '<S104>/Logical Operator4'
     */
    OxC_bStabFilOxCT = (OxC_bInhFilTOxC_C || ((localLogic_i[1]) &&
      (!OxC_bIdcInhChkTOxC)));

    /* Update for UnitDelay: '<S112>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_le = localDTConv_Single_To_UFix_3_n;

    /* Update for UnitDelay: '<S110>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_nv = localIn_ka;

    /* Update for UnitDelay: '<S123>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_gj = localRelationalOperator1_aw;

    /* Update for UnitDelay: '<S127>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_d2 = localIn_ka;

    /* Update for UnitDelay: '<S122>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_kr = localSwitch2_f;

    /* Update for UnitDelay: '<S128>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_nu = localRelationalOperator2_k;

    /* Update for Memory: '<S120>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_b = localLogic_i[0];

    /* end of Outputs for SubSystem: '<S35>/01_Tester_Filtrage_temp_cata' */

    /* Logic: '<S35>/Logical Operator4' */
    localLogicalOperator4_d = (OxC_bStabFilOxCT && OxC_bStabDeltaMaxOxCT);

    /* Update for UnitDelay: '<S108>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_g2 = OxC_tOxCMax;

    /* Update for UnitDelay: '<S107>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_e2 = OxC_tOxCMin;

    /* Update for UnitDelay: '<S106>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ni = OxC_tiCntStabOxCT;

    /* end of Outputs for SubSystem: '<S31>/03_Tester_stab_temp_cata' */

    /* Outputs for atomic SubSystem: '<S31>/09_Reinit_cdn_stab_debit_moteur' */

    /* Logic: '<S248>/Logical Operator' incorporates:
     *  Logic: '<S248>/Logical Operator1'
     *  UnitDelay: '<S249>/Unit Delay'
     *  UnitDelay: '<S44>/Unit Delay'
     */
    OxC_bIdcInhChkMfAir = ((!CatAcvDiagT_DWork.UnitDelay_DSTATE_gm) &&
      CatAcvDiagT_DWork.UnitDelay_DSTATE_fb);

    /* Update for UnitDelay: '<S249>/Unit Delay' incorporates:
     *  UnitDelay: '<S44>/Unit Delay'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_fb =
      CatAcvDiagT_DWork.UnitDelay_DSTATE_gm;

    /* end of Outputs for SubSystem: '<S31>/09_Reinit_cdn_stab_debit_moteur' */

    /* Outputs for atomic SubSystem: '<S31>/04_Tester_stab_debit_moteur' */

    /* UnitDelay: '<S137>/Unit Delay' */
    OxC_mfAirThrMaxPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_nn;

    /* UnitDelay: '<S136>/Unit Delay' */
    OxC_mfAirThrMinPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_f;

    /* UnitDelay: '<S135>/Unit Delay' */
    OxC_tiCntMfAirThrPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_kd;

    /* Outputs for atomic SubSystem: '<S36>/02_Tester_Tunnel_debit_moteur' */

    /* If: '<S134>/If' incorporates:
     *  ActionPort: '<S158>/Action Port'
     *  ActionPort: '<S159>/Action Port'
     *  Constant: '<S134>/SenO2Us_SampleTiFast_SC(1)2'
     *  DataTypeConversion: '<S134>/DTConv_Single_To_UFix_2'
     *  Logic: '<S134>/Logical Operator2'
     *  RelationalOperator: '<S134>/Relational Operator1'
     *  SubSystem: '<S134>/01_Tester_Tunnel_debit_moteur_no_check'
     *  SubSystem: '<S134>/02_Tester_Tunnel_debit_moteur_check'
     *  Sum: '<S134>/Sum6'
     */
    if (((OxC_mfAirThrMaxPrev - OxC_mfAirThrMinPrev) > OxC_mfAirDeltaMaxThd_C) ||
        ((localLogicalOperator3_o) || OxC_bIdcInhChkMfAir)) {
      /* Constant: '<S158>/SenO2Us_SampleTiFast_SC(1)1' */
      OxC_tiCntStabMfAirThr = OxC_tiDlyStabMfAir_C;

      /* SignalConversion: '<S158>/Signal Conversion1' */
      OxC_mfAirThrMax = CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA;

      /* SignalConversion: '<S158>/Signal Conversion2' */
      OxC_mfAirThrMin = CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA;

      /* Constant: '<S158>/SenO2Us_SampleTiFast_SC(1)2' */
      OxC_bStabMfAirThr = FALSE;

      /* Constant: '<S158>/SenO2Us_SampleTiFast_SC(1)3' */
      OxC_bRstFilMfAir = TRUE;
    } else {
      /* If: '<S159>/If' incorporates:
       *  ActionPort: '<S160>/Action Port'
       *  ActionPort: '<S161>/Action Port'
       *  Constant: '<S159>/SenO2Us_SampleTiFast_SC(1)1'
       *  RelationalOperator: '<S159>/Relational Operator1'
       *  SubSystem: '<S159>/01_Tester_Tunnel_debit_moteur_check_stable'
       *  SubSystem: '<S159>/02_Tester_Tunnel_debit_moteur_check_wait'
       */
      if (OxC_tiCntMfAirThrPrev <= 0) {
        /* Constant: '<S160>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bStabMfAirThr = TRUE;
      } else {
        /* Constant: '<S161>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bStabMfAirThr = FALSE;

        /* Sum: '<S161>/Sum6' incorporates:
         *  Constant: '<S161>/SenO2Us_SampleTiFast_SC(1)7'
         */
        localtmp = OxC_tiCntMfAirThrPrev - CatMon_SampleTiSlow_SC;
        if (localtmp <= 0) {
          OxC_tiCntStabMfAirThr = 0U;
        } else {
          OxC_tiCntStabMfAirThr = (UInt8)localtmp;
        }
      }

      /* MinMax: '<S159>/MinMax' */
      localSwitch4 = OxC_mfAirThrMaxPrev;
      if (CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA > OxC_mfAirThrMaxPrev) {
        localSwitch4 = CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA;
      }

      OxC_mfAirThrMax = localSwitch4;

      /* MinMax: '<S159>/MinMax1' */
      localSwitch4 = CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA;
      if (OxC_mfAirThrMinPrev < CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA) {
        localSwitch4 = OxC_mfAirThrMinPrev;
      }

      OxC_mfAirThrMin = localSwitch4;

      /* Constant: '<S159>/SenO2Us_SampleTiFast_SC(1)2' */
      OxC_bRstFilMfAir = FALSE;
    }

    /* Logic: '<S134>/Logical Operator1' incorporates:
     *  Constant: '<S134>/OxC_nCkHiThd_C(1)3'
     */
    OxC_bStabDeltaMaxMfAir = (OxC_bStabMfAirThr || OxC_bInhDeltaMfAir_C);

    /* Logic: '<S134>/Logical Operator4' incorporates:
     *  Constant: '<S134>/OxC_nCkHiThd_C(1)3'
     *  Logic: '<S134>/Logical Operator5'
     */
    OxC_bRstFilMfAirCdn = ((!OxC_bInhDeltaMfAir_C) && OxC_bRstFilMfAir);

    /* end of Outputs for SubSystem: '<S36>/02_Tester_Tunnel_debit_moteur' */

    /* Outputs for atomic SubSystem: '<S36>/01_Tester_Filtrage_debit_moteur' */

    /* DataTypeConversion: '<S133>/DTConv_Single_To_UFix_3' */
    localDTConv_Single_To_UFix_3_n = ((Float32)
      CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA) * 9.999999776E-003F;

    /* UnitDelay: '<S139>/Unit Delay' */
    localLogicalOperator3_g = CatAcvDiagT_DWork.UnitDelay_DSTATE_bn;

    /* Outputs for atomic SubSystem: '<S133>/DLowPassFilter_TypeT_rAirLd' */

    /* UnitDelay: '<S148>/Unit Delay' */
    localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_g;

    /* Switch: '<S143>/Switch' incorporates:
     *  UnitDelay: '<S141>/Unit Delay'
     *  UnitDelay: '<S147>/Unit Delay'
     */
    if (!CatAcvDiagT_DWork.UnitDelay_DSTATE_ay) {
      localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_lr;
    }

    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S133>/OxC_nCkHiThd_C(1)5'
     *  DataTypeConversion: '<S133>/DTConv_Single_To_UFix_1'
     *  Logic: '<S133>/Logical Operator1'
     *  Logic: '<S133>/Logical Operator7'
     *  Logic: '<S138>/Logical Operator'
     *  Product: '<S144>/Divide'
     *  Product: '<S145>/Divide'
     *  Sum: '<S138>/Sum1'
     *  Sum: '<S138>/Sum2'
     *  Sum: '<S138>/Sum3'
     *  UnitDelay: '<S141>/Unit Delay'
     */
    if (!(((!localLogicalOperator3_g) || OxC_bRstFilMfAirCdn) ||
          OxC_bIdcInhChkMfAir)) {
      localSwitch2_f -= (localTe_j / ((((Float32)OxC_tiMfAirLpfTau_C) *
        2.000000030E-001F) + localTe_j)) * (localSwitch2_f -
        localDTConv_Single_To_UFix_3_n);
    } else {
      localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_lr;
    }

    /* Switch: '<S142>/Switch' incorporates:
     *  UnitDelay: '<S141>/Unit Delay'
     *  UnitDelay: '<S146>/Unit Delay'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_ja) {
      OxC_mfAirMesThrEstimFil = localSwitch2_f;
    } else {
      OxC_mfAirMesThrEstimFil = CatAcvDiagT_DWork.UnitDelay_DSTATE_lr;
    }

    /* Update for UnitDelay: '<S146>/Unit Delay' incorporates:
     *  Constant: '<S142>/Constant3'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ja = TRUE;

    /* Update for UnitDelay: '<S148>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_g = localSwitch2_f;

    /* Update for UnitDelay: '<S147>/Unit Delay' incorporates:
     *  Constant: '<S143>/Constant3'
     */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ay = TRUE;

    /* end of Outputs for SubSystem: '<S133>/DLowPassFilter_TypeT_rAirLd' */

    /* Sum: '<S133>/Sum4' */
    localSwitch2_f = localDTConv_Single_To_UFix_3_n - OxC_mfAirMesThrEstimFil;

    /* Switch: '<S133>/Switch5' incorporates:
     *  Constant: '<S133>/OxC_tOxCUsMesDeltaMax_C(1)'
     *  Constant: '<S133>/OxC_tOxCUsMesDeltaMax_C(1)1'
     */
    if (localRelationalOperator12_h) {
      localSwitch4 = OxC_mfAirDeltaMaxGas_C;
    } else {
      localSwitch4 = OxC_mfAirDeltaMax_C;
    }

    /* RelationalOperator: '<S133>/Relational Operator13' incorporates:
     *  Abs: '<S133>/Abs2'
     *  DataTypeConversion: '<S133>/DTConv_Single_To_UFix_2'
     */
    localIn_ka = (ACTEMS_FabsF(localSwitch2_f) < (((Float32)localSwitch4) *
      9.999999776E-003F));

    /* Logic: '<S140>/Logical Operator3' */
    localLogicalOperator3_g = !localIn_ka;

    /* UnitDelay: '<S152>/Unit Delay' */
    localMemory_l = CatAcvDiagT_DWork.UnitDelay_DSTATE_pr;

    /* UnitDelay: '<S156>/Unit Delay' */
    localR_h = CatAcvDiagT_DWork.UnitDelay_DSTATE_dl;

    /* Sum: '<S140>/Sum2' incorporates:
     *  Constant: '<S133>/OxC_nCkHiThd_C(1)2'
     *  Constant: '<S140>/Constant1'
     *  Constant: '<S140>/Constant6'
     *  MinMax: '<S140>/MinMax1'
     *  Product: '<S153>/Divide'
     */
    localSwitch_n = (((Float32)OxC_tiMfAirDlyOn_C) * 2.000000030E-001F) +
      (10.0F * localTe_j);

    /* UnitDelay: '<S151>/Unit Delay' */
    localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_b;

    /* Switch: '<S150>/Switch' incorporates:
     *  Constant: '<S140>/Constant3'
     *  RelationalOperator: '<S150>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_b < 0.0F) {
      localSwitch2_f = 0.0F;
    }

    /* Switch: '<S150>/Switch2' incorporates:
     *  RelationalOperator: '<S150>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_b > localSwitch_n)) {
      localSwitch_n = localSwitch2_f;
    }

    /* Switch: '<S140>/Switch1' incorporates:
     *  Constant: '<S140>/Constant4'
     *  Constant: '<S140>/Constant7'
     *  Logic: '<S140>/Logical Operator2'
     *  Logic: '<S154>/Logical Operator'
     *  Logic: '<S154>/Logical Operator1'
     *  Sum: '<S140>/Sum1'
     */
    if ((localMemory_l) || ((localIn_ka) && (!localR_h))) {
      localSwitch2_f = 0.0F;
    } else {
      localSwitch2_f = (localTe_j + localSwitch_n) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S140>/Relational Operator2' incorporates:
     *  MinMax: '<S140>/MinMax1'
     */
    localRelationalOperator2_k = (localSwitch2_f >= (((Float32)
      OxC_tiMfAirDlyOn_C) * 2.000000030E-001F));

    /* UnitDelay: '<S157>/Unit Delay' */
    localR_h = CatAcvDiagT_DWork.UnitDelay_DSTATE_kh;

    /* RelationalOperator: '<S140>/Relational Operator1' incorporates:
     *  Constant: '<S140>/Constant2'
     *  MinMax: '<S140>/MinMax1'
     */
    localRelationalOperator1_aw = (OxC_tiMfAirDlyOn_C == 0);

    /* Switch: '<S140>/Switch' incorporates:
     *  Constant: '<S140>/Constant5'
     *  Logic: '<S140>/Logical Operator1'
     *  Logic: '<S155>/Logical Operator'
     *  Logic: '<S155>/Logical Operator1'
     */
    if (!localRelationalOperator1_aw) {
      localR_h = ((localRelationalOperator2_k) && (!localR_h));
    } else {
      localR_h = TRUE;
    }

    /* Memory: '<S149>/Memory' */
    localMemory_l = CatAcvDiagT_DWork.Memory_PreviousInput_g;

    /* CombinatorialLogic: '<S149>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_g != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_h != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_l != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_ej[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_ej[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* Logic: '<S133>/Logical Operator2' incorporates:
     *  Constant: '<S133>/OxC_nCkHiThd_C(1)1'
     *  Logic: '<S133>/Logical Operator3'
     *  Logic: '<S133>/Logical Operator4'
     */
    OxC_bStabFilMfAir = (OxC_bInhFilMfAir_C || ((localLogic_ej[1]) &&
      (!OxC_bIdcInhChkMfAir)));

    /* Update for UnitDelay: '<S141>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_lr = localDTConv_Single_To_UFix_3_n;

    /* Update for UnitDelay: '<S139>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_bn = localIn_ka;

    /* Update for UnitDelay: '<S152>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_pr = localRelationalOperator1_aw;

    /* Update for UnitDelay: '<S156>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_dl = localIn_ka;

    /* Update for UnitDelay: '<S151>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_b = localSwitch2_f;

    /* Update for UnitDelay: '<S157>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_kh = localRelationalOperator2_k;

    /* Update for Memory: '<S149>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_g = localLogic_ej[0];

    /* end of Outputs for SubSystem: '<S36>/01_Tester_Filtrage_debit_moteur' */

    /* Logic: '<S36>/Logical Operator4' */
    OxC_bStabMfAir = (OxC_bStabFilMfAir && OxC_bStabDeltaMaxMfAir);

    /* Update for UnitDelay: '<S137>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_nn = OxC_mfAirThrMax;

    /* Update for UnitDelay: '<S136>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_f = OxC_mfAirThrMin;

    /* Update for UnitDelay: '<S135>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_kd = OxC_tiCntStabMfAirThr;

    /* end of Outputs for SubSystem: '<S31>/04_Tester_stab_debit_moteur' */

    /* Outputs for atomic SubSystem: '<S31>/08_Tester_stab_transition_mode' */

    /* Logic: '<S40>/Logical Operator1' */
    localIn_ka = !localTmpSignalConversionAtEOM_b;

    /* Logic: '<S238>/Logical Operator3' */
    localLogicalOperator3_f1 = !localIn_ka;

    /* UnitDelay: '<S242>/Unit Delay' */
    localMemory_a = CatAcvDiagT_DWork.UnitDelay_DSTATE_bv;

    /* UnitDelay: '<S246>/Unit Delay' */
    localR_m = CatAcvDiagT_DWork.UnitDelay_DSTATE_an;

    /* Sum: '<S238>/Sum2' incorporates:
     *  Constant: '<S238>/Constant1'
     *  Constant: '<S238>/Constant6'
     *  Constant: '<S40>/SenO2Us_SampleTiFast_SC(1)1'
     *  MinMax: '<S238>/MinMax1'
     *  Product: '<S243>/Divide'
     */
    localSwitch2_f = (((Float32)OxC_tiTranModDlyOn_C) * 2.000000030E-001F) +
      (10.0F * localTe_j);

    /* UnitDelay: '<S241>/Unit Delay' */
    localSwitch_n = CatAcvDiagT_DWork.UnitDelay_DSTATE_l;

    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S238>/Constant3'
     *  RelationalOperator: '<S240>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_l < 0.0F) {
      localSwitch_n = 0.0F;
    }

    /* Switch: '<S240>/Switch2' incorporates:
     *  RelationalOperator: '<S240>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_l > localSwitch2_f)) {
      localSwitch2_f = localSwitch_n;
    }

    /* Switch: '<S238>/Switch1' incorporates:
     *  Constant: '<S238>/Constant4'
     *  Constant: '<S238>/Constant7'
     *  Logic: '<S238>/Logical Operator2'
     *  Logic: '<S244>/Logical Operator'
     *  Logic: '<S244>/Logical Operator1'
     *  Sum: '<S238>/Sum1'
     */
    if ((localMemory_a) || ((localIn_ka) && (!localR_m))) {
      localDTConv_Single_To_UFix_3_n = 0.0F;
    } else {
      localDTConv_Single_To_UFix_3_n = (localTe_j + localSwitch2_f) +
        2.220446049E-016F;
    }

    /* RelationalOperator: '<S238>/Relational Operator2' incorporates:
     *  MinMax: '<S238>/MinMax1'
     */
    localRelationalOperator2_k = (localDTConv_Single_To_UFix_3_n >= (((Float32)
      OxC_tiTranModDlyOn_C) * 2.000000030E-001F));

    /* UnitDelay: '<S247>/Unit Delay' */
    localR_m = CatAcvDiagT_DWork.UnitDelay_DSTATE_he;

    /* RelationalOperator: '<S238>/Relational Operator1' incorporates:
     *  Constant: '<S238>/Constant2'
     *  MinMax: '<S238>/MinMax1'
     */
    localRelationalOperator1_aw = (OxC_tiTranModDlyOn_C == 0);

    /* Switch: '<S238>/Switch' incorporates:
     *  Constant: '<S238>/Constant5'
     *  Logic: '<S238>/Logical Operator1'
     *  Logic: '<S245>/Logical Operator'
     *  Logic: '<S245>/Logical Operator1'
     */
    if (!localRelationalOperator1_aw) {
      localR_m = ((localRelationalOperator2_k) && (!localR_m));
    } else {
      localR_m = TRUE;
    }

    /* Memory: '<S239>/Memory' */
    localMemory_a = CatAcvDiagT_DWork.Memory_PreviousInput_a;

    /* CombinatorialLogic: '<S239>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_f1 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_m != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_a != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_k[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_k[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* SignalConversion: '<S40>/Signal Conversion3' */
    OxC_bStabTranMod = localLogic_k[1];

    /* Update for UnitDelay: '<S242>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_bv = localRelationalOperator1_aw;

    /* Update for UnitDelay: '<S246>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_an = localIn_ka;

    /* Update for UnitDelay: '<S241>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_l = localDTConv_Single_To_UFix_3_n;

    /* Update for UnitDelay: '<S247>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_he = localRelationalOperator2_k;

    /* Update for Memory: '<S239>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_a = localLogic_k[0];

    /* end of Outputs for SubSystem: '<S31>/08_Tester_stab_transition_mode' */

    /* Outputs for atomic SubSystem: '<S31>/05_Tester_stab_regul_richesse' */

    /* UnitDelay: '<S169>/Unit Delay' */
    OxC_rlamFilMaxPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_c;

    /* UnitDelay: '<S168>/Unit Delay' */
    OxC_rlamFilMinPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_p2;

    /* UnitDelay: '<S167>/Unit Delay' */
    OxC_tiCntRlamFilPrev = CatAcvDiagT_DWork.UnitDelay_DSTATE_fjz;

    /* UnitDelay: '<S165>/Unit Delay1' */
    localIn_ka = CatAcvDiagT_DWork.UnitDelay1_DSTATE;

    /* SignalConversion: '<S37>/Signal Conversion12' */
    localIn_dz = CatAcvDiagT_B.TmpSignalConversionAtInjSys_bAc;

    /* Logic: '<S170>/Logical Operator3' */
    localLogicalOperator3_e = !CatAcvDiagT_B.TmpSignalConversionAtInjSys_bAc;

    /* UnitDelay: '<S210>/Unit Delay' */
    localMemory_d = CatAcvDiagT_DWork.UnitDelay_DSTATE_ox;

    /* UnitDelay: '<S214>/Unit Delay' */
    localR_fu = CatAcvDiagT_DWork.UnitDelay_DSTATE_cx;

    /* MinMax: '<S170>/MinMax1' incorporates:
     *  Constant: '<S166>/offset'
     *  Constant: '<S166>/offset1'
     *  Constant: '<S166>/one_on_slope'
     *  Constant: '<S170>/Constant1'
     *  DataTypeConversion: '<S166>/OutDTConv'
     *  Lookup_n-D: '<S164>/Lookup Table (n-D)'
     *  Product: '<S166>/Product4'
     *  Sum: '<S166>/Add1'
     *  Sum: '<S166>/Add2'
     */
    localSwitch_n = (25.0F * look1_iu16lftu16n5If_binlcns
                     (CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA,
                      (&(OxC_tiLamRegStabInput_A[0])), (&(OxC_tiLamRegStab_T[0])),
                      15U)) + 0.5F;
    if (localSwitch_n < 65536.0F) {
      if (localSwitch_n >= 0.0F) {
        localSwitch4 = (UInt16)localSwitch_n;
      } else {
        localSwitch4 = 0U;
      }
    } else {
      localSwitch4 = MAX_uint16_T;
    }

    /* Sum: '<S170>/Sum2' incorporates:
     *  Constant: '<S170>/Constant6'
     *  Product: '<S211>/Divide'
     */
    localSwitch2_f = (((Float32)localSwitch4) * 3.999999911E-002F) + (10.0F *
      localTe_j);

    /* UnitDelay: '<S209>/Unit Delay' */
    localSwitch_he = CatAcvDiagT_DWork.UnitDelay_DSTATE_p;

    /* Switch: '<S208>/Switch' incorporates:
     *  Constant: '<S170>/Constant3'
     *  RelationalOperator: '<S208>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_p < 0.0F) {
      localSwitch_he = 0.0F;
    }

    /* Switch: '<S208>/Switch2' incorporates:
     *  RelationalOperator: '<S208>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_p > localSwitch2_f)) {
      localSwitch2_f = localSwitch_he;
    }

    /* Switch: '<S170>/Switch1' incorporates:
     *  Constant: '<S170>/Constant4'
     *  Constant: '<S170>/Constant7'
     *  Logic: '<S170>/Logical Operator2'
     *  Logic: '<S212>/Logical Operator'
     *  Logic: '<S212>/Logical Operator1'
     *  Sum: '<S170>/Sum1'
     */
    if ((localMemory_d) || (CatAcvDiagT_B.TmpSignalConversionAtInjSys_bAc &&
                            (!localR_fu))) {
      localDTConv_Single_To_UFix_3_n = 0.0F;
    } else {
      localDTConv_Single_To_UFix_3_n = (localTe_j + localSwitch2_f) +
        2.220446049E-016F;
    }

    /* RelationalOperator: '<S170>/Relational Operator2' */
    localRelationalOperator2_ca = (localDTConv_Single_To_UFix_3_n >= (((Float32)
      localSwitch4) * 3.999999911E-002F));

    /* UnitDelay: '<S215>/Unit Delay' */
    localR_fu = CatAcvDiagT_DWork.UnitDelay_DSTATE_fj;

    /* RelationalOperator: '<S170>/Relational Operator1' incorporates:
     *  Constant: '<S170>/Constant2'
     */
    localRelationalOperator1_ij = (localSwitch4 == 0);

    /* Switch: '<S170>/Switch' incorporates:
     *  Constant: '<S170>/Constant5'
     *  Logic: '<S170>/Logical Operator1'
     *  Logic: '<S213>/Logical Operator'
     *  Logic: '<S213>/Logical Operator1'
     */
    if (!localRelationalOperator1_ij) {
      localR_fu = ((localRelationalOperator2_ca) && (!localR_fu));
    } else {
      localR_fu = TRUE;
    }

    /* Memory: '<S207>/Memory' */
    localMemory_d = CatAcvDiagT_DWork.Memory_PreviousInput_jn;

    /* CombinatorialLogic: '<S207>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_e != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_fu != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_d != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_kb[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_kb[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* Logic: '<S165>/Logical Operator1' incorporates:
     *  Logic: '<S165>/Logical Operator'
     *  Logic: '<S37>/Logical Operator1'
     */
    localTmpSignalConversionAtEOM_b = !((!((localIn_ka) || (localLogic_kb[1]))) ||
                                        (!localIn_dz));

    /* If: '<S37>/If' incorporates:
     *  ActionPort: '<S162>/Action Port'
     *  ActionPort: '<S163>/Action Port'
     *  SubSystem: '<S37>/01_Tester_stab_regul_richesse_activee'
     *  SubSystem: '<S37>/02_Tester_stab_regul_richesse_non_active'
     */
    if (localTmpSignalConversionAtEOM_b) {
      /* RelationalOperator: '<S162>/Relational Operator1' incorporates:
       *  Constant: '<S162>/OxC_mfDsThrHiThd_C(1)1'
       */
      localRelationalOperator1_k1 = (((UInt32)
        CatAcvDiagT_B.TmpSignalConversionAtOxC_stMonI) == 1U);

      /* Logic: '<S162>/Logical Operator4' incorporates:
       *  Logic: '<S173>/Logical Operator'
       *  Logic: '<S173>/Logical Operator1'
       *  Logic: '<S174>/Logical Operator'
       *  Logic: '<S174>/Logical Operator1'
       *  Logic: '<S175>/Logical Operator'
       *  Logic: '<S175>/Logical Operator1'
       *  Logic: '<S176>/Logical Operator'
       *  Logic: '<S176>/Logical Operator1'
       *  UnitDelay: '<S203>/Unit Delay'
       *  UnitDelay: '<S204>/Unit Delay'
       *  UnitDelay: '<S205>/Unit Delay'
       *  UnitDelay: '<S206>/Unit Delay'
       */
      OxC_bIdcInhChkrLamFil = (((((localRelationalOperator1_k1) &&
        (!CatAcvDiagT_DWork.UnitDelay_DSTATE_dd)) || ((!localLogicalOperator4_f)
        && CatAcvDiagT_DWork.UnitDelay_DSTATE_pb)) || ((!OxC_bStabAirLd) &&
        CatAcvDiagT_DWork.UnitDelay_DSTATE_m)) || (OxC_bStabTranMod &&
        (!CatAcvDiagT_DWork.UnitDelay_DSTATE_iv)));

      /* If: '<S162>/If' incorporates:
       *  ActionPort: '<S171>/Action Port'
       *  ActionPort: '<S172>/Action Port'
       *  Constant: '<S162>/OxC_mfDsThrHiThd_C(1)2'
       *  RelationalOperator: '<S162>/Relational Operator17'
       *  SubSystem: '<S162>/01_Tester_stab_regul_richesse_active_mon_running'
       *  SubSystem: '<S162>/02_Tester_stab_regul_richesse_active_mon_not_running'
       */
      if (CatAcvDiagT_B.TmpSignalConversionAtOxC_stMonI == 2) {
        /* Constant: '<S171>/SenO2Us_SampleTiFast_SC(1)2' */
        OxC_bStabRlamFilOxC = TRUE;

        /* SignalConversion: '<S171>/Signal Conversion1' */
        OxC_rlamFilMax = CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL;

        /* SignalConversion: '<S171>/Signal Conversion2' */
        OxC_rlamFilMin = CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL;

        /* Constant: '<S171>/SenO2Us_SampleTiFast_SC(1)1' */
        OxC_tiCntRlamFil = OxC_tiDlyStablamFbFil_C;
      } else {
        /* Outputs for atomic SubSystem: '<S172>/02_Tester_Tunnel_regul_richesse' */

        /* If: '<S178>/If' incorporates:
         *  ActionPort: '<S199>/Action Port'
         *  ActionPort: '<S200>/Action Port'
         *  Constant: '<S178>/SenO2Us_SampleTiFast_SC(1)2'
         *  DataTypeConversion: '<S178>/DTConv_Single_To_UFix_2'
         *  Logic: '<S178>/Logical Operator2'
         *  RelationalOperator: '<S178>/Relational Operator1'
         *  SubSystem: '<S178>/01_Tester_Tunnel_regul_richesse_no_check'
         *  SubSystem: '<S178>/02_Tester_Tunnel_regul_richesse_check'
         *  Sum: '<S178>/Sum6'
         */
        if (((OxC_rlamFilMaxPrev - OxC_rlamFilMinPrev) >
             OxC_lamFbFilDeltaMaxThd_C) || ((localLogicalOperator3_o) ||
             OxC_bIdcInhChkrLamFil)) {
          /* Constant: '<S199>/SenO2Us_SampleTiFast_SC(1)1' */
          OxC_tiCntRlamFil = OxC_tiDlyStablamFbFil_C;

          /* SignalConversion: '<S199>/Signal Conversion1' */
          OxC_rlamFilMax = CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL;

          /* SignalConversion: '<S199>/Signal Conversion2' */
          OxC_rlamFilMin = CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL;

          /* Constant: '<S199>/SenO2Us_SampleTiFast_SC(1)2' */
          OxC_bStabRlam = FALSE;

          /* Constant: '<S199>/SenO2Us_SampleTiFast_SC(1)3' */
          OxC_bRstFilRlam = TRUE;
        } else {
          /* If: '<S200>/If' incorporates:
           *  ActionPort: '<S201>/Action Port'
           *  ActionPort: '<S202>/Action Port'
           *  Constant: '<S200>/SenO2Us_SampleTiFast_SC(1)1'
           *  RelationalOperator: '<S200>/Relational Operator1'
           *  SubSystem: '<S200>/01_Tester_Tunnel_regul_richesse_check_stable'
           *  SubSystem: '<S200>/02_Tester_Tunnel_regul_richesse_check_wait'
           */
          if (OxC_tiCntRlamFilPrev <= 0) {
            /* Constant: '<S201>/SenO2Us_SampleTiFast_SC(1)2' */
            OxC_bStabRlam = TRUE;
          } else {
            /* Constant: '<S202>/SenO2Us_SampleTiFast_SC(1)2' */
            OxC_bStabRlam = FALSE;

            /* Sum: '<S202>/Sum6' incorporates:
             *  Constant: '<S202>/SenO2Us_SampleTiFast_SC(1)7'
             */
            localtmp = OxC_tiCntRlamFilPrev - CatMon_SampleTiSlow_SC;
            if (localtmp <= 0) {
              OxC_tiCntRlamFil = 0U;
            } else {
              OxC_tiCntRlamFil = (UInt8)localtmp;
            }
          }

          /* MinMax: '<S200>/MinMax' */
          localSwitch5_f = OxC_rlamFilMaxPrev;
          if (CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL > OxC_rlamFilMaxPrev)
          {
            localSwitch5_f = CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL;
          }

          OxC_rlamFilMax = localSwitch5_f;

          /* MinMax: '<S200>/MinMax1' */
          localSwitch5_f = CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL;
          if (OxC_rlamFilMinPrev < CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL)
          {
            localSwitch5_f = OxC_rlamFilMinPrev;
          }

          OxC_rlamFilMin = localSwitch5_f;

          /* Constant: '<S200>/SenO2Us_SampleTiFast_SC(1)2' */
          OxC_bRstFilRlam = FALSE;
        }

        /* Logic: '<S178>/Logical Operator1' incorporates:
         *  Constant: '<S178>/OxC_nCkHiThd_C(1)3'
         */
        OxC_bStabDeltaMaxRlam = (OxC_bStabRlam || OxC_bInhDeltaRLamFil_C);

        /* Logic: '<S178>/Logical Operator4' incorporates:
         *  Constant: '<S178>/OxC_nCkHiThd_C(1)3'
         *  Logic: '<S178>/Logical Operator5'
         */
        OxC_bRstFilRlamCdn = ((!OxC_bInhDeltaRLamFil_C) && OxC_bRstFilRlam);

        /* end of Outputs for SubSystem: '<S172>/02_Tester_Tunnel_regul_richesse' */

        /* Outputs for atomic SubSystem: '<S172>/01_Tester_Filtrage_regul_richesse' */

        /* DataTypeConversion: '<S177>/DTConv_Single_To_UFix_1' */
        localSwitch_he = ((Float32)
                          CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL) *
          7.629394531E-006F;

        /* UnitDelay: '<S180>/Unit Delay' */
        localLogicalOperator3_npl = CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4;

        /* Outputs for atomic SubSystem: '<S177>/DLowPassFilter_TypeT_Rlam' */

        /* UnitDelay: '<S189>/Unit Delay' */
        localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx;

        /* Switch: '<S184>/Switch' incorporates:
         *  UnitDelay: '<S182>/Unit Delay'
         *  UnitDelay: '<S188>/Unit Delay'
         */
        if (!CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4lrjjr) {
          localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_h;
        }

        /* Switch: '<S179>/Switch' incorporates:
         *  Constant: '<S177>/OxC_nCkHiThd_C(1)12'
         *  DataTypeConversion: '<S177>/DTConv_Single_To_UFix_2'
         *  Logic: '<S177>/Logical Operator1'
         *  Logic: '<S177>/Logical Operator7'
         *  Logic: '<S179>/Logical Operator'
         *  Product: '<S185>/Divide'
         *  Product: '<S186>/Divide'
         *  Sum: '<S179>/Sum1'
         *  Sum: '<S179>/Sum2'
         *  Sum: '<S179>/Sum3'
         *  UnitDelay: '<S182>/Unit Delay'
         */
        if (!(((!localLogicalOperator3_npl) || OxC_bRstFilRlamCdn) ||
              OxC_bIdcInhChkrLamFil)) {
          localSwitch2_f -= (localTe_j / ((((Float32)OxC_tiRlamLpfTau_C) *
            2.000000030E-001F) + localTe_j)) * (localSwitch2_f - localSwitch_he);
        } else {
          localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_h;
        }

        /* Switch: '<S183>/Switch' incorporates:
         *  UnitDelay: '<S182>/Unit Delay'
         *  UnitDelay: '<S187>/Unit Delay'
         */
        if (CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4lrjj) {
          AFReg_rFbLsclFilFil = localSwitch2_f;
        } else {
          AFReg_rFbLsclFilFil = CatAcvDiagT_DWork.UnitDelay_DSTATE_h;
        }

        /* Update for UnitDelay: '<S187>/Unit Delay' incorporates:
         *  Constant: '<S183>/Constant3'
         */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4lrjj = TRUE;

        /* Update for UnitDelay: '<S189>/Unit Delay' */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx = localSwitch2_f;

        /* Update for UnitDelay: '<S188>/Unit Delay' incorporates:
         *  Constant: '<S184>/Constant3'
         */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4lrjjr = TRUE;

        /* end of Outputs for SubSystem: '<S177>/DLowPassFilter_TypeT_Rlam' */

        /* Sum: '<S177>/Sum2' */
        localSwitch2_f = localSwitch_he - AFReg_rFbLsclFilFil;

        /* Switch: '<S177>/Switch6' incorporates:
         *  Constant: '<S177>/OxC_rFbLsclDeltaMax_C(1)'
         *  Constant: '<S177>/OxC_rFbLsclDeltaMax_C(1)1'
         */
        if (localRelationalOperator12_h) {
          localSwitch4 = OxC_rFbLsclDeltaMaxGas_C;
        } else {
          localSwitch4 = OxC_rFbLsclDeltaMax_C;
        }

        /* RelationalOperator: '<S177>/Relational Operator1' incorporates:
         *  Abs: '<S177>/Abs3'
         *  DataTypeConversion: '<S177>/DTConv_Single_To_UFix_3'
         */
        localIn_ka = (ACTEMS_FabsF(localSwitch2_f) < (((Float32)localSwitch4) *
          7.629394531E-006F));

        /* Logic: '<S181>/Logical Operator3' */
        localLogicalOperator3_npl = !localIn_ka;

        /* UnitDelay: '<S193>/Unit Delay' */
        localMemory_n = CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4l;

        /* UnitDelay: '<S197>/Unit Delay' */
        localR_ik = CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4lr;

        /* Sum: '<S181>/Sum2' incorporates:
         *  Constant: '<S177>/OxC_nCkHiThd_C(1)2'
         *  Constant: '<S181>/Constant1'
         *  Constant: '<S181>/Constant6'
         *  MinMax: '<S181>/MinMax1'
         *  Product: '<S194>/Divide'
         */
        localSwitch_n = (((Float32)OxC_tiRlamDlyOn_C) * 2.000000030E-001F) +
          (10.0F * localTe_j);

        /* UnitDelay: '<S192>/Unit Delay' */
        localSwitch2_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_hx;

        /* Switch: '<S191>/Switch' incorporates:
         *  Constant: '<S181>/Constant3'
         *  RelationalOperator: '<S191>/UpperRelop'
         */
        if (CatAcvDiagT_DWork.UnitDelay_DSTATE_hx < 0.0F) {
          localSwitch2_f = 0.0F;
        }

        /* Switch: '<S191>/Switch2' incorporates:
         *  RelationalOperator: '<S191>/LowerRelop1'
         */
        if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_hx > localSwitch_n)) {
          localSwitch_n = localSwitch2_f;
        }

        /* Switch: '<S181>/Switch1' incorporates:
         *  Constant: '<S181>/Constant4'
         *  Constant: '<S181>/Constant7'
         *  Logic: '<S181>/Logical Operator2'
         *  Logic: '<S195>/Logical Operator'
         *  Logic: '<S195>/Logical Operator1'
         *  Sum: '<S181>/Sum1'
         */
        if ((localMemory_n) || ((localIn_ka) && (!localR_ik))) {
          localSwitch2_f = 0.0F;
        } else {
          localSwitch2_f = (localTe_j + localSwitch_n) + 2.220446049E-016F;
        }

        /* RelationalOperator: '<S181>/Relational Operator2' incorporates:
         *  MinMax: '<S181>/MinMax1'
         */
        localRelationalOperator2_k = (localSwitch2_f >= (((Float32)
          OxC_tiRlamDlyOn_C) * 2.000000030E-001F));

        /* UnitDelay: '<S198>/Unit Delay' */
        localR_ik = CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4lrj;

        /* RelationalOperator: '<S181>/Relational Operator1' incorporates:
         *  Constant: '<S181>/Constant2'
         *  MinMax: '<S181>/MinMax1'
         */
        localRelationalOperator1_aw = (OxC_tiRlamDlyOn_C == 0);

        /* Switch: '<S181>/Switch' incorporates:
         *  Constant: '<S181>/Constant5'
         *  Logic: '<S181>/Logical Operator1'
         *  Logic: '<S196>/Logical Operator'
         *  Logic: '<S196>/Logical Operator1'
         */
        if (!localRelationalOperator1_aw) {
          localR_ik = ((localRelationalOperator2_k) && (!localR_ik));
        } else {
          localR_ik = TRUE;
        }

        /* Memory: '<S190>/Memory' */
        localMemory_n = CatAcvDiagT_DWork.Memory_PreviousInput_m;

        /* CombinatorialLogic: '<S190>/Logic' */
        {
          UInt32 rowidx= 0;

          /* Compute the truth table row index corresponding to the input */
          rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_npl != 0);
          rowidx = (rowidx << 1) + (UInt32)(localR_ik != 0);
          rowidx = (rowidx << 1) + (UInt32)(localMemory_n != 0);

          /* Copy the appropriate row of the table into the block output vector */
          localLogic_l[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
          localLogic_l[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
        }

        /* Logic: '<S177>/Logical Operator2' incorporates:
         *  Constant: '<S177>/OxC_nCkHiThd_C(1)1'
         *  Logic: '<S177>/Logical Operator3'
         *  Logic: '<S177>/Logical Operator4'
         */
        OxC_bStabFilRlam = (OxC_bInhFilRlamFilOxC_C || ((localLogic_l[1]) &&
          (!OxC_bIdcInhChkrLamFil)));

        /* Update for UnitDelay: '<S182>/Unit Delay' */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_h = localSwitch_he;

        /* Update for UnitDelay: '<S180>/Unit Delay' */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4 = localIn_ka;

        /* Update for UnitDelay: '<S193>/Unit Delay' */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4l = localRelationalOperator1_aw;

        /* Update for UnitDelay: '<S197>/Unit Delay' */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4lr = localIn_ka;

        /* Update for UnitDelay: '<S192>/Unit Delay' */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hx = localSwitch2_f;

        /* Update for UnitDelay: '<S198>/Unit Delay' */
        CatAcvDiagT_DWork.UnitDelay_DSTATE_hxx4lrj = localRelationalOperator2_k;

        /* Update for Memory: '<S190>/Memory' */
        CatAcvDiagT_DWork.Memory_PreviousInput_m = localLogic_l[0];

        /* end of Outputs for SubSystem: '<S172>/01_Tester_Filtrage_regul_richesse' */

        /* Logic: '<S172>/Logical Operator4' */
        OxC_bStabRlamFilOxC = (OxC_bStabFilRlam && OxC_bStabDeltaMaxRlam);
      }

      /* Update for UnitDelay: '<S206>/Unit Delay' */
      CatAcvDiagT_DWork.UnitDelay_DSTATE_dd = localRelationalOperator1_k1;

      /* Update for UnitDelay: '<S204>/Unit Delay' */
      CatAcvDiagT_DWork.UnitDelay_DSTATE_pb = localLogicalOperator4_f;

      /* Update for UnitDelay: '<S203>/Unit Delay' */
      CatAcvDiagT_DWork.UnitDelay_DSTATE_m = OxC_bStabAirLd;

      /* Update for UnitDelay: '<S205>/Unit Delay' */
      CatAcvDiagT_DWork.UnitDelay_DSTATE_iv = OxC_bStabTranMod;
    } else {
      /* RelationalOperator: '<S163>/Relational Operator17' incorporates:
       *  Constant: '<S163>/OxC_mfDsThrHiThd_C(1)2'
       */
      OxC_bStabRlamFilOxC = (CatAcvDiagT_B.TmpSignalConversionAtOxC_stMonI == 2);

      /* SignalConversion: '<S163>/Signal Conversion1' */
      OxC_rlamFilMin = CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL;

      /* SignalConversion: '<S163>/Signal Conversion2' */
      OxC_rlamFilMax = CatAcvDiagT_B.TmpSignalConversionAtAFReg_rFbL;

      /* Constant: '<S163>/OxC_mfDsThrHiThd_C(1)1' */
      OxC_tiCntRlamFil = OxC_tiDlyStablamFbFil_C;
    }

    /* Update for UnitDelay: '<S169>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_c = OxC_rlamFilMax;

    /* Update for UnitDelay: '<S168>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_p2 = OxC_rlamFilMin;

    /* Update for UnitDelay: '<S167>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_fjz = OxC_tiCntRlamFil;

    /* Update for UnitDelay: '<S165>/Unit Delay1' */
    CatAcvDiagT_DWork.UnitDelay1_DSTATE = localTmpSignalConversionAtEOM_b;

    /* Update for UnitDelay: '<S210>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ox = localRelationalOperator1_ij;

    /* Update for UnitDelay: '<S214>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_cx = localIn_dz;

    /* Update for UnitDelay: '<S209>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_p = localDTConv_Single_To_UFix_3_n;

    /* Update for UnitDelay: '<S215>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_fj = localRelationalOperator2_ca;

    /* Update for Memory: '<S207>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_jn = localLogic_kb[0];

    /* end of Outputs for SubSystem: '<S31>/05_Tester_stab_regul_richesse' */

    /* Outputs for atomic SubSystem: '<S31>/06_Tester_stab_purge_canister' */

    /* RelationalOperator: '<S38>/Relational Operator1' incorporates:
     *  Constant: '<S38>/SenO2Us_SampleTiFast_SC(1)2'
     */
    localIn_ka = (localTmpSignalConversionAtCanPu <= OxC_rOpCanPurgReqThd_C);

    /* Logic: '<S218>/Logical Operator3' */
    localLogicalOperator3_fa = !localIn_ka;

    /* UnitDelay: '<S222>/Unit Delay' */
    localMemory_e1 = CatAcvDiagT_DWork.UnitDelay_DSTATE_ht5;

    /* UnitDelay: '<S226>/Unit Delay' */
    localR_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_gy;

    /* MinMax: '<S218>/MinMax1' incorporates:
     *  Constant: '<S217>/offset'
     *  Constant: '<S217>/offset1'
     *  Constant: '<S217>/one_on_slope'
     *  Constant: '<S218>/Constant1'
     *  DataTypeConversion: '<S217>/OutDTConv'
     *  Lookup_n-D: '<S216>/Lookup Table (n-D)'
     *  Product: '<S217>/Product4'
     *  Sum: '<S217>/Add1'
     *  Sum: '<S217>/Add2'
     */
    localSwitch_n = (5.0F * look1_iu16lftu8n3If_binlcns
                     (CatAcvDiagT_B.TmpSignalConversionAtAirSys_mfA,
                      (&(OxC_tiCanPurgClsInput_A[0])), (&(OxC_tiCanPurgCls_T[0])),
                      15U)) + 0.5F;
    if (localSwitch_n < 256.0F) {
      if (localSwitch_n >= 0.0F) {
        localTmpSignalConversionAtCanPu = (UInt8)localSwitch_n;
      } else {
        localTmpSignalConversionAtCanPu = 0U;
      }
    } else {
      localTmpSignalConversionAtCanPu = MAX_uint8_T;
    }

    /* Sum: '<S218>/Sum2' incorporates:
     *  Constant: '<S218>/Constant6'
     *  Product: '<S223>/Divide'
     */
    localSwitch2_f = (((Float32)localTmpSignalConversionAtCanPu) *
                      2.000000030E-001F) + (10.0F * localTe_j);

    /* UnitDelay: '<S221>/Unit Delay' */
    localSwitch_n = CatAcvDiagT_DWork.UnitDelay_DSTATE_o;

    /* Switch: '<S220>/Switch' incorporates:
     *  Constant: '<S218>/Constant3'
     *  RelationalOperator: '<S220>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_o < 0.0F) {
      localSwitch_n = 0.0F;
    }

    /* Switch: '<S220>/Switch2' incorporates:
     *  RelationalOperator: '<S220>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_o > localSwitch2_f)) {
      localSwitch2_f = localSwitch_n;
    }

    /* Switch: '<S218>/Switch1' incorporates:
     *  Constant: '<S218>/Constant4'
     *  Constant: '<S218>/Constant7'
     *  Logic: '<S218>/Logical Operator2'
     *  Logic: '<S224>/Logical Operator'
     *  Logic: '<S224>/Logical Operator1'
     *  Sum: '<S218>/Sum1'
     */
    if ((localMemory_e1) || ((localIn_ka) && (!localR_f))) {
      localSwitch2_f = 0.0F;
    } else {
      localSwitch2_f = (localTe_j + localSwitch2_f) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S218>/Relational Operator2' */
    localRelationalOperator2_k = (localSwitch2_f >= (((Float32)
      localTmpSignalConversionAtCanPu) * 2.000000030E-001F));

    /* UnitDelay: '<S227>/Unit Delay' */
    localR_f = CatAcvDiagT_DWork.UnitDelay_DSTATE_nf;

    /* RelationalOperator: '<S218>/Relational Operator1' incorporates:
     *  Constant: '<S218>/Constant2'
     */
    localRelationalOperator1_aw = (localTmpSignalConversionAtCanPu == 0);

    /* Switch: '<S218>/Switch' incorporates:
     *  Constant: '<S218>/Constant5'
     *  Logic: '<S218>/Logical Operator1'
     *  Logic: '<S225>/Logical Operator'
     *  Logic: '<S225>/Logical Operator1'
     */
    if (!localRelationalOperator1_aw) {
      localR_f = ((localRelationalOperator2_k) && (!localR_f));
    } else {
      localR_f = TRUE;
    }

    /* Memory: '<S219>/Memory' */
    localMemory_e1 = CatAcvDiagT_DWork.Memory_PreviousInput_o;

    /* CombinatorialLogic: '<S219>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_fa != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_f != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_e1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_b[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_b[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* SignalConversion: '<S38>/Signal Conversion3' */
    OxC_bStabCanPurg = localLogic_b[1];

    /* Update for UnitDelay: '<S222>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ht5 = localRelationalOperator1_aw;

    /* Update for UnitDelay: '<S226>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_gy = localIn_ka;

    /* Update for UnitDelay: '<S221>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_o = localSwitch2_f;

    /* Update for UnitDelay: '<S227>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_nf = localRelationalOperator2_k;

    /* Update for Memory: '<S219>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_o = localLogic_b[0];

    /* end of Outputs for SubSystem: '<S31>/06_Tester_stab_purge_canister' */

    /* Outputs for atomic SubSystem: '<S31>/07_Tester_stab_coupure_injection' */

    /* RelationalOperator: '<S39>/Relational Operator1' incorporates:
     *  Constant: '<S39>/SenO2Us_SampleTiFast_SC(1)2'
     */
    localIn_ka = (localTmpSignalConversionAtInj_e == 0);

    /* Logic: '<S228>/Logical Operator3' */
    localLogicalOperator3_nl = !localIn_ka;

    /* UnitDelay: '<S232>/Unit Delay' */
    localMemory_kw = CatAcvDiagT_DWork.UnitDelay_DSTATE_g5;

    /* UnitDelay: '<S236>/Unit Delay' */
    localR_i5 = CatAcvDiagT_DWork.UnitDelay_DSTATE_on;

    /* Sum: '<S228>/Sum2' incorporates:
     *  Constant: '<S228>/Constant1'
     *  Constant: '<S228>/Constant6'
     *  Constant: '<S39>/SenO2Us_SampleTiFast_SC(1)1'
     *  MinMax: '<S228>/MinMax1'
     *  Product: '<S233>/Divide'
     */
    localSwitch_n = (((Float32)OxC_tiCylNotCutOffDlyOn_C) * 2.000000030E-001F)
      + (10.0F * localTe_j);

    /* UnitDelay: '<S231>/Unit Delay' */
    localDTConv_Single_To_UFix_3_n = CatAcvDiagT_DWork.UnitDelay_DSTATE_ld;

    /* Switch: '<S230>/Switch' incorporates:
     *  Constant: '<S228>/Constant3'
     *  RelationalOperator: '<S230>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE_ld < 0.0F) {
      localDTConv_Single_To_UFix_3_n = 0.0F;
    }

    /* Switch: '<S230>/Switch2' incorporates:
     *  RelationalOperator: '<S230>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE_ld > localSwitch_n)) {
      localSwitch_n = localDTConv_Single_To_UFix_3_n;
    }

    /* Switch: '<S228>/Switch1' incorporates:
     *  Constant: '<S228>/Constant4'
     *  Constant: '<S228>/Constant7'
     *  Logic: '<S228>/Logical Operator2'
     *  Logic: '<S234>/Logical Operator'
     *  Logic: '<S234>/Logical Operator1'
     *  Sum: '<S228>/Sum1'
     */
    if ((localMemory_kw) || ((localIn_ka) && (!localR_i5))) {
      localSwitch2_f = 0.0F;
    } else {
      localSwitch2_f = (localTe_j + localSwitch_n) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S228>/Relational Operator2' incorporates:
     *  MinMax: '<S228>/MinMax1'
     */
    localRelationalOperator2_k = (localSwitch2_f >= (((Float32)
      OxC_tiCylNotCutOffDlyOn_C) * 2.000000030E-001F));

    /* UnitDelay: '<S237>/Unit Delay' */
    localR_i5 = CatAcvDiagT_DWork.UnitDelay_DSTATE_ht;

    /* RelationalOperator: '<S228>/Relational Operator1' incorporates:
     *  Constant: '<S228>/Constant2'
     *  MinMax: '<S228>/MinMax1'
     */
    localRelationalOperator1_aw = (OxC_tiCylNotCutOffDlyOn_C == 0);

    /* Switch: '<S228>/Switch' incorporates:
     *  Constant: '<S228>/Constant5'
     *  Logic: '<S228>/Logical Operator1'
     *  Logic: '<S235>/Logical Operator'
     *  Logic: '<S235>/Logical Operator1'
     */
    if (!localRelationalOperator1_aw) {
      localR_i5 = ((localRelationalOperator2_k) && (!localR_i5));
    } else {
      localR_i5 = TRUE;
    }

    /* Memory: '<S229>/Memory' */
    localMemory_kw = CatAcvDiagT_DWork.Memory_PreviousInput_j;

    /* CombinatorialLogic: '<S229>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_nl != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_i5 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_kw != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_am[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_am[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* SignalConversion: '<S39>/Signal Conversion3' */
    OxC_bStabnoCylCutOff = localLogic_am[1];

    /* Update for UnitDelay: '<S232>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_g5 = localRelationalOperator1_aw;

    /* Update for UnitDelay: '<S236>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_on = localIn_ka;

    /* Update for UnitDelay: '<S231>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ld = localSwitch2_f;

    /* Update for UnitDelay: '<S237>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ht = localRelationalOperator2_k;

    /* Update for Memory: '<S229>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_j = localLogic_am[0];

    /* end of Outputs for SubSystem: '<S31>/07_Tester_stab_coupure_injection' */

    /* Update for UnitDelay: '<S45>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_ha = localRelationalOperator1_f;

    /* Update for UnitDelay: '<S255>/UnitDelay' */
    CatAcvDiagT_DWork.UnitDelay = localIn_a;

    /* Update for UnitDelay: '<S254>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_k = localSwitch1_n;

    /* Update for UnitDelay: '<S256>/UnitDelay' */
    CatAcvDiagT_DWork.UnitDelay_l = localRelationalOperator2_mg;

    /* Update for Memory: '<S253>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput_k = localLogic_a[0];

    /* Update for UnitDelay: '<S43>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_lp = OxC_bStabMfAir;

    /* Update for UnitDelay: '<S44>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_gm = localLogicalOperator4_d;

    /* end of Outputs for SubSystem: '<S28>/01_Tester_cdn_Stablilite' */

    /* Outputs for atomic SubSystem: '<S28>/02_Compiler_tests_stabilite' */

    /* DataTypeConversion: '<S32>/DTConv_Single_To_UFix_1' incorporates:
     *  Constant: '<S32>/SenO2Us_SampleTiFast_SC(1)14'
     */
    localSwitch2_f = ((Float32)CatMon_SampleTiSlow_SC) * 2.000000030E-001F;

    /* Logic: '<S32>/Logical Operator4' */
    localIn_ka = ((((((((localLogicalOperator4_f) && OxC_bStabAirLd) &&
                       (localLogicalOperator4_d)) && OxC_bStabMfAir) &&
                     OxC_bStabRlamFilOxC) && OxC_bStabCanPurg) &&
                   OxC_bStabTranMod) && OxC_bStabnoCylCutOff);

    /* Logic: '<S260>/Logical Operator3' */
    localLogicalOperator3_nt = !localIn_ka;

    /* UnitDelay: '<S264>/Unit Delay' */
    localMemory_k = CatAcvDiagT_DWork.UnitDelay_DSTATE_h5;

    /* UnitDelay: '<S268>/Unit Delay' */
    localR_l = CatAcvDiagT_DWork.UnitDelay_DSTATE_i3;

    /* Sum: '<S260>/Sum2' incorporates:
     *  Constant: '<S260>/Constant1'
     *  Constant: '<S260>/Constant6'
     *  Constant: '<S32>/OxC_nCkHiThd_C(1)13'
     *  MinMax: '<S260>/MinMax1'
     *  Product: '<S265>/Divide'
     */
    localSwitch_n = (((Float32)OxC_tiStabCdnDlyOn_C) * 2.000000030E-001F) +
      (10.0F * localSwitch2_f);

    /* UnitDelay: '<S263>/Unit Delay' */
    localDTConv_Single_To_UFix_3_n = CatAcvDiagT_DWork.UnitDelay_DSTATE;

    /* Switch: '<S262>/Switch' incorporates:
     *  Constant: '<S260>/Constant3'
     *  RelationalOperator: '<S262>/UpperRelop'
     */
    if (CatAcvDiagT_DWork.UnitDelay_DSTATE < 0.0F) {
      localDTConv_Single_To_UFix_3_n = 0.0F;
    }

    /* Switch: '<S262>/Switch2' incorporates:
     *  RelationalOperator: '<S262>/LowerRelop1'
     */
    if (!(CatAcvDiagT_DWork.UnitDelay_DSTATE > localSwitch_n)) {
      localSwitch_n = localDTConv_Single_To_UFix_3_n;
    }

    /* Switch: '<S260>/Switch1' incorporates:
     *  Constant: '<S260>/Constant4'
     *  Constant: '<S260>/Constant7'
     *  Logic: '<S260>/Logical Operator2'
     *  Logic: '<S266>/Logical Operator'
     *  Logic: '<S266>/Logical Operator1'
     *  Sum: '<S260>/Sum1'
     */
    if ((localMemory_k) || ((localIn_ka) && (!localR_l))) {
      localSwitch2_f = 0.0F;
    } else {
      localSwitch2_f = (localSwitch2_f + localSwitch_n) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S260>/Relational Operator2' incorporates:
     *  MinMax: '<S260>/MinMax1'
     */
    localRelationalOperator2_k = (localSwitch2_f >= (((Float32)
      OxC_tiStabCdnDlyOn_C) * 2.000000030E-001F));

    /* UnitDelay: '<S269>/Unit Delay' */
    localR_l = CatAcvDiagT_DWork.UnitDelay_DSTATE_i1;

    /* RelationalOperator: '<S260>/Relational Operator1' incorporates:
     *  Constant: '<S260>/Constant2'
     *  MinMax: '<S260>/MinMax1'
     */
    localRelationalOperator1_aw = (OxC_tiStabCdnDlyOn_C == 0);

    /* Switch: '<S260>/Switch' incorporates:
     *  Constant: '<S260>/Constant5'
     *  Logic: '<S260>/Logical Operator1'
     *  Logic: '<S267>/Logical Operator'
     *  Logic: '<S267>/Logical Operator1'
     */
    if (!localRelationalOperator1_aw) {
      localR_l = ((localRelationalOperator2_k) && (!localR_l));
    } else {
      localR_l = TRUE;
    }

    /* Memory: '<S261>/Memory' */
    localMemory_k = CatAcvDiagT_DWork.Memory_PreviousInput;

    /* CombinatorialLogic: '<S261>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_nt != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR_l != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory_k != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_g2[0] = CatAcvDiagT_ConstP.pooled17[rowidx];
      localLogic_g2[1] = CatAcvDiagT_ConstP.pooled17[rowidx + 8];
    }

    /* SignalConversion: '<S32>/Signal Conversion2' */
    CatAcvDiagT_B.Merge2_p = localLogic_g2[1];

    /* Update for UnitDelay: '<S264>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_h5 = localRelationalOperator1_aw;

    /* Update for UnitDelay: '<S268>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_i3 = localIn_ka;

    /* Update for UnitDelay: '<S263>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE = localSwitch2_f;

    /* Update for UnitDelay: '<S269>/Unit Delay' */
    CatAcvDiagT_DWork.UnitDelay_DSTATE_i1 = localRelationalOperator2_k;

    /* Update for Memory: '<S261>/Memory' */
    CatAcvDiagT_DWork.Memory_PreviousInput = localLogic_g2[0];

    /* end of Outputs for SubSystem: '<S28>/02_Compiler_tests_stabilite' */
  }

  /* end of Outputs for SubSystem: '<S7>/Conditions_stabilite_diag_intrusif' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtOxC_bMonORngIntrStabCdn_irv1Outport2' */
  CatAcvDiagT_B.TmpSignalConversionAtOxC_bMonOR =
    Rte_IrvRead_RE_CatMon_SdlSlow_CatAcvDiag_OxC_bMonORngIntrStabCdn_irv();

  /* Outputs for enable SubSystem: '<S7>/Subsystem' incorporates:
   *  EnablePort: '<S29>/OxC_bMonReqORngIntr_NOT'
   *  Logic: '<S7>/Logical Operator'
   */
  if (!localTmpSignalConversionAtOxC_k) {
    /* SignalConversion: '<S29>/Signal Conversion2' */
    CatAcvDiagT_B.Merge2_p = CatAcvDiagT_B.TmpSignalConversionAtOxC_bMonOR;
  }

  /* end of Outputs for SubSystem: '<S7>/Subsystem' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S30>/autosar_testpoint1' */

  /* S-Function Block: <S30>/autosar_testpoint1 */
  OxC_bMonORngIntrStabCdn_IRV_MP = CatAcvDiagT_B.Merge2_p;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtOxC_bMonORngIntrStabCdn_irvInport2' incorporates:
   *  SignalConversion: '<S7>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_CatMon_SdlSlow_CatAcvDiag_OxC_bMonORngIntrStabCdn_irv
    (CatAcvDiagT_B.Merge2_p);
}

/* Model initialize function */
void RE_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  RE_CatMon_EveRst_CatAcvDiag_Start();
  RE_CatMon_SdlFast_CatAcvDiag_Start();
  RE_CatMon_SdlMid_CatAcvDiag_Start();
  RE_CatMon_SdlSlow_CatAcvDiag_Start();

  /* Machine initializer */
  _sfEvent_ = CALL_EVENT;

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__3'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__4'
   */
  RE_CatMon_SdlFast_CatAcvDiag_Init();
}

#define CatAcvDiagT_STOP_SEC_CODE
#include "CatAcvDiagT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
