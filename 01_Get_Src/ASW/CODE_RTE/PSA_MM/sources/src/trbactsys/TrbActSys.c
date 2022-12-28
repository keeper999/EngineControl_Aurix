/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActSys                                               */
/* !Description     : TrbActSys Software Component                            */
/*                                                                            */
/* !Module          : TrbActSys                                               */
/* !Description     : TrbActSys Software Component                            */
/*                                                                            */
/* !File            : TrbActSys.c                                             */
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
/*   Model name       : TrbActSys_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActSys                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M14-TrbActSys/5-$*/
/* $Revision::   1.16                                                        $*/
/* $Author::   adelvare                               $$Date::   15 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TrbActSys.h"
#include "TrbActSys_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define TrbActSys_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActSys_MemMap.h"

/* Block signals (auto storage) */
BlockIO_TrbActSys TrbActSys_B;

/* Block states (auto storage) */
D_Work_TrbActSys TrbActSys_DWork;

#define TrbActSys_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "TrbActSys_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define TRBACTSYS_VEMSRTLIBT_MAJOR_VERSION_REQ 3
#define TRBACTSYS_VEMSRTLIBT_MINOR_VERSION_REQ 12
#define TRBACTSYS_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define TRBACTSYS_VEMSRTLIBT_VERSION_REQ (TRBACTSYS_VEMSRTLIBT_PATCH_VERSION_REQ + TRBACTSYS_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + TRBACTSYS_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if TRBACTSYS_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define TrbActSys_START_SEC_CODE
#include "TrbActSys_MemMap.h"

void TrbActSys_ASYNC1(int controlPortIdx)
{
}

void TrbActSys_ASYNC2(int controlPortIdx)
{
}

void TrbActSys_ASYNC3(int controlPortIdx)
{
}

void TrbActSys_ASYNC4(int controlPortIdx)
{
}

void TrbActSys_ASYNC5(int controlPortIdx)
{
}

void TrbActSys_ASYNC6(int controlPortIdx)
{
}

void TrbActSys_ASYNC7(int controlPortIdx)
{
}

/*
 * Output and update for action system:
 *    '<S12>/if_s'
 *    '<S140>/if_s'
 */
void TrbActSys_if_s(Boolean rtu_bMonRun, Boolean rtu_bDgo,
                    rtDW_if_s_TrbActSys *localDW)
{
  /* If: '<S28>/If' incorporates:
   *  ActionPort: '<S29>/Action Port'
   *  ActionPort: '<S30>/Action Port'
   *  SubSystem: '<S28>/if_s1'
   *  SubSystem: '<S28>/if_s2'
   */
  if (rtu_bMonRun) {
    /* If: '<S29>/If' incorporates:
     *  ActionPort: '<S31>/Action Port'
     *  ActionPort: '<S32>/Action Port'
     *  SubSystem: '<S29>/if_s1'
     *  SubSystem: '<S29>/if_s2'
     */
    if (rtu_bDgo) {
      /* S-Function (sfun_autosar_clientop): '<S31>/AutosarServer' incorporates:
       *  Constant: '<S31>/Constant1'
       */
      Rte_Call_R_TrbAct_ArDeltaCorLim_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
    } else {
      /* S-Function (sfun_autosar_clientop): '<S32>/AutosarServer' incorporates:
       *  Constant: '<S32>/Constant2'
       */
      Rte_Call_R_TrbAct_ArDeltaCorLim_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
    }
  } else {
    /* If: '<S30>/If' incorporates:
     *  ActionPort: '<S33>/Action Port'
     *  Memory: '<S28>/Memory'
     *  SubSystem: '<S30>/if_s'
     */
    if (localDW->Memory_PreviousInput) {
      /* S-Function (sfun_autosar_clientop): '<S33>/AutosarServer' incorporates:
       *  Constant: '<S33>/Constant3'
       */
      Rte_Call_R_TrbAct_ArDeltaCorLim_SetEventStatus(DEM_EVENT_STATUS_INIT);
    }
  }

  /* Update for Memory: '<S28>/Memory' */
  localDW->Memory_PreviousInput = rtu_bMonRun;
}

/* Start for exported function: RE_TrbActSys_001_MSE */
void RE_TrbActSys_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_TrbActAdpSysinit'
   *
   * Block requirements for '<S1>/F00_TrbActAdpSysinit':
   *  1. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_054.03 ;
   *  2. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_008.02 ;
   *  3. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_078.02 ;
   *  4. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_007.02 ;
   *  5. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_006.02 ;
   *  6. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_018.02 ;
   *  7. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_017.02 ;
   *  8. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_016.02 ;
   *  9. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_062.01 ;
   *  10. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_061.01 ;
   *  11. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_060.01 ;
   *  12. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_079.02 ;
   *  13. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_047.02 ;
   *  14. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_048.02 ;
   *  15. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_076.02 ;
   *  16. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_075.02 ;
   *  17. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  18. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_080.02 ;
   *  19. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_041.01 ;
   *  20. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_043.01 ;
   *  21. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_071.01 ;
   *  22. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_069.01 ;
   *  23. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_082.01 ;
   *  24. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_083.01 ;
   */
}

/* Output and update for exported function: RE_TrbActSys_001_MSE */
void RE_TrbActSys_001_MSE(void)
{
  Boolean localTrbAct_bAcvTrbActAdp;
  SInt32 localTrbAct_facAdpArTrbActErr_i;
  UInt16 localTrbAct_arTrbActAdp;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_TrbActAdpSysinit'
   *
   * Block requirements for '<S1>/F00_TrbActAdpSysinit':
   *  1. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_054.03 ;
   *  2. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_008.02 ;
   *  3. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_078.02 ;
   *  4. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_007.02 ;
   *  5. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_006.02 ;
   *  6. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_018.02 ;
   *  7. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_017.02 ;
   *  8. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_016.02 ;
   *  9. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_062.01 ;
   *  10. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_061.01 ;
   *  11. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_060.01 ;
   *  12. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_079.02 ;
   *  13. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_047.02 ;
   *  14. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_048.02 ;
   *  15. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_076.02 ;
   *  16. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_075.02 ;
   *  17. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  18. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_080.02 ;
   *  19. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_041.01 ;
   *  20. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_043.01 ;
   *  21. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_071.01 ;
   *  22. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_069.01 ;
   *  23. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_082.01 ;
   *  24. SubSystem "F00_TrbActAdpSysinit" !Trace_To : VEMS_R_10_07018_083.01 ;
   */

  /* user code (Output function Body for TID12) */
  RE_TrbActSys_Init();

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   *  Constant: '<S7>/ConstVal_7'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTrbAct_bAcvTrbActAdp = TrbAct_bAcvTrbActAdp_B;
  } else {
    localTrbAct_bAcvTrbActAdp = FALSE;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_bAcvTrbActAdpInport2' */
  Rte_Write_P_TrbAct_bAcvTrbActAdp_TrbAct_bAcvTrbActAdp
    (localTrbAct_bAcvTrbActAdp);

  /* S-Function (NvRamReadAccess): '<S7>/S-Function1' */
  TrbActSys_B.SFunction1 =
    TrbActSys_sNV_Z1_CONST_32BIT.TrbAct_facAdpArTrbActErr_NV;

  /* SignalConversion: '<S13>/copy' */
  TrbAct_facAdpArTrbActErr_IRV_MP = TrbActSys_B.SFunction1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S13>/autosar_testpoint1' */

  /* S-Function Block: <S13>/autosar_testpoint1 */

  /* SignalConversion: '<S19>/copy' */
  TrbAct_facAdpArTrbActErrFil = TrbActSys_B.SFunction1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S19>/autosar_testpoint1' */

  /* S-Function Block: <S19>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/Signal Conversion9' */
  localTrbAct_facAdpArTrbActErr_i = TrbActSys_B.SFunction1;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_facAdpArTrbActErrFil_irvInport2' incorporates:
   *  SignalConversion: '<S7>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_TrbActSys_001_MSE_TrbAct_facAdpArTrbActErrFil_irv
    (TrbActSys_B.SFunction1);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_facAdpArTrbActErr_irvInport2' */
  Rte_IrvWrite_RE_TrbActSys_001_MSE_TrbAct_facAdpArTrbActErr_irv
    (localTrbAct_facAdpArTrbActErr_i);

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Byp_Fonction_SC'
   *  Constant: '<S25>/Int_BypC'
   *  Constant: '<S7>/ConstVal_4'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTrbAct_arTrbActAdp = TrbAct_arTrbActAdp_B;
  } else {
    localTrbAct_arTrbActAdp = 0U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_arTrbActAdpInport2' */
  Rte_Write_P_TrbAct_arTrbActAdp_TrbAct_arTrbActAdp(localTrbAct_arTrbActAdp);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Byp_Fonction_SC'
   *  Constant: '<S27>/Int_BypC'
   *  Constant: '<S7>/ConstVal_9'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTrbAct_arTrbActAdp = TrbAct_arTrbActFrzSp_B;
  } else {
    localTrbAct_arTrbActAdp = 0U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_arTrbActFrzSpInport2' */
  Rte_Write_P_TrbAct_arTrbActFrzSp_TrbAct_arTrbActFrzSp(localTrbAct_arTrbActAdp);

  /* SignalConversion: '<S15>/copy' incorporates:
   *  Constant: '<S7>/ConstVal_12'
   */
  TrbAct_pGradUsThrReqFil_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S15>/autosar_testpoint1' */

  /* S-Function Block: <S15>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pGradUsThrReqFil_irvInport2' incorporates:
   *  Constant: '<S7>/ConstVal_12'
   *  SignalConversion: '<S7>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_TrbActSys_001_MSE_TrbAct_pGradUsThrReqFil_irv(0);

  /* SignalConversion: '<S20>/copy' incorporates:
   *  Constant: '<S7>/ConstVal_1'
   */
  TrbAct_pGradUsThrMesCorFil = 0;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S20>/autosar_testpoint1' */

  /* S-Function Block: <S20>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pGradUsThrMesCorFil_irvInport2' incorporates:
   *  Constant: '<S7>/ConstVal_1'
   *  SignalConversion: '<S7>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_TrbActSys_001_MSE_TrbAct_pGradUsThrMesCorFil_irv(0);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Byp_Fonction_SC'
   *  Constant: '<S26>/Int_BypC'
   *  Constant: '<S7>/ConstVal_2'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTrbAct_arTrbActAdp = TrbAct_rOpTrbActReq_B;
  } else {
    localTrbAct_arTrbActAdp = 0U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_rOpTrbActReqInport2' */
  Rte_Write_P_TrbAct_rOpTrbActReq_TrbAct_rOpTrbActReq(localTrbAct_arTrbActAdp);

  /* SignalConversion: '<S16>/copy' incorporates:
   *  Constant: '<S7>/ConstVal_3'
   */
  TrbAct_rOpTrbActAirExtModReq = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S16>/autosar_testpoint1' */

  /* S-Function Block: <S16>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_rOpTrbActAirExtModReq_irvInport2' incorporates:
   *  Constant: '<S7>/ConstVal_3'
   *  SignalConversion: '<S7>/Signal Conversion11'
   */
  Rte_IrvWrite_RE_TrbActSys_001_MSE_TrbAct_rOpTrbActAirExtModReq_irv(0U);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Byp_Fonction_SC'
   *  Constant: '<S22>/Int_BypC'
   *  Constant: '<S7>/ConstVal'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTrbAct_bAcvTrbActAdp = TrbAct_bAcvOpRelTrbActExt_B;
  } else {
    localTrbAct_bAcvTrbActAdp = TRUE;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_bAcvOpRelTrbActExtInport2' */
  Rte_Write_P_TrbAct_bAcvOpRelTrbActExt_TrbAct_bAcvOpRelTrbActExt
    (localTrbAct_bAcvTrbActAdp);

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Byp_Fonction_SC'
   *  Constant: '<S21>/Int_BypC'
   *  Constant: '<S7>/ConstVal_11'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTrbAct_arTrbActAdp = TrbAct_rOpRelTrbActExtReq_B;
  } else {
    localTrbAct_arTrbActAdp = MAX_uint16_T;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_rOpRelTrbActExtReqInport2' */
  Rte_Write_P_TrbAct_rOpRelTrbActExtReq_TrbAct_rOpRelTrbActExtReq
    (localTrbAct_arTrbActAdp);

  /* SignalConversion: '<S17>/copy' incorporates:
   *  Constant: '<S7>/ConstVal_6'
   */
  TrbAct_effCmpr_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S17>/autosar_testpoint1' */

  /* S-Function Block: <S17>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_effCmpr_irvInport2' incorporates:
   *  Constant: '<S7>/ConstVal_6'
   *  SignalConversion: '<S7>/Signal Conversion14'
   */
  Rte_IrvWrite_RE_TrbActSys_001_MSE_TrbAct_effCmpr_irv(0U);

  /* SignalConversion: '<S18>/copy' incorporates:
   *  Constant: '<S7>/ConstVal_5'
   */
  TrbAct_effTrb_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S18>/autosar_testpoint1' */

  /* S-Function Block: <S18>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_effTrb_irvInport2' incorporates:
   *  Constant: '<S7>/ConstVal_5'
   *  SignalConversion: '<S7>/Signal Conversion15'
   */
  Rte_IrvWrite_RE_TrbActSys_001_MSE_TrbAct_effTrb_irv(0U);

  /* SignalConversion: '<S14>/copy' incorporates:
   *  Constant: '<S7>/ConstVal_10'
   */
  TrbAct_arTrbActReq_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S14>/autosar_testpoint1' */

  /* S-Function Block: <S14>/autosar_testpoint1 */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_arTrbActReq_irvInport2' incorporates:
   *  Constant: '<S7>/ConstVal_10'
   *  SignalConversion: '<S7>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_TrbActSys_001_MSE_TrbAct_arTrbActReq_irv(0U);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Byp_Fonction_SC'
   *  Constant: '<S23>/Int_BypC'
   *  Constant: '<S7>/ConstVal_8'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTrbAct_arTrbActAdp = TrbAct_pExMnfReq_B;
  } else {
    localTrbAct_arTrbActAdp = 6331U;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtTrbAct_pExMnfReqInport2' */
  Rte_Write_P_TrbAct_pExMnfReq_TrbAct_pExMnfReq(localTrbAct_arTrbActAdp);

  /* If: '<S12>/If' incorporates:
   *  ActionPort: '<S28>/Action Port'
   *  Constant: '<S7>/TRBACTSYS_ACTIVE_BYP_C'
   *  SubSystem: '<S12>/if_s'
   */
  if (!TRBACTSYS_ACTIVE_BYP_C) {
    TrbActSys_if_s(FALSE, FALSE, &TrbActSys_DWork.if_s);
  }
}

/* Start for exported function: RE_TrbActSys_002_TEV */
void RE_TrbActSys_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_ArTrbActClcn'
   *
   * Block requirements for '<S1>/F01_ArTrbActClcn':
   *  1. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_055.01 ;
   *  2. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_001.01 ;
   *  3. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_002.01 ;
   *  4. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_033.01 ;
   *  5. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_023.01 ;
   *  6. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_024.02 ;
   *  7. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_025.01 ;
   *  8. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_026.01 ;
   *  9. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_027.01 ;
   *  10. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_028.01 ;
   *  11. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_029.01 ;
   *  12. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_030.01 ;
   *  13. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_031.02 ;
   *  14. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_032.01 ;
   *  15. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_034.02 ;
   *  16. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  17. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_047.02 ;
   *  18. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_048.02 ;
   */
}

/* Output and update for exported function: RE_TrbActSys_002_TEV */
void RE_TrbActSys_002_TEV(void)
{
  /* local block i/o variables */
  UInt16 localOutDTConv;
  UInt16 localLookUpTable2D;
  UInt16 localLookUpTable;
  UInt16 localOutDTConv_ow;
  UInt16 localLookUpTable_n;
  Float32 localDataTypeConversion6;
  Float32 localDataTypeConversion7;
  Float32 localDataTypeConversion8;
  Float32 localDataTypeConversion10;
  Float32 localDataTypeConversion13;
  Float32 localDataTypeConversion;
  Float32 localDivide_m5;
  Float32 localDataTypeConversion3_d;
  Float32 localLookupTablenD_j;
  Float32 localLookupTablenD_jt;
  UInt32 localExM_tExMnfEstim_TrbAct_tUs;
  Float32 localAdd2_c;
  Float32 localfrac[2];
  UInt32 localTrbAct_mfRatPresTrbInter_M;
  UInt32 localbpIndex[2];
  Float32 localLookupTablenD;
  UInt16 localTmpSignalConversionAtTrbAc;
  SInt16 localTmpSignalConversionAtAir_d;
  UInt16 localTmpSignalConversionAtAir_a;
  UInt16 localTmpSignalConversionAtAirSy;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt16 localTmpSignalConversionAtExM_m;
  UInt16 localTmpSignalConversionAtExM_p;
  UInt16 localTmpSignalConversionAtExM_j;
  UInt16 localTmpSignalConversionAtTrb_m;
  UInt16 localTmpSignalConversionAtExM_e;
  UInt16 localTmpSignalConversionAtExM_r;
  Float32d localtmp;
  SInt32 localtmp_0;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_ArTrbActClcn'
   *
   * Block requirements for '<S1>/F01_ArTrbActClcn':
   *  1. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_055.01 ;
   *  2. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_001.01 ;
   *  3. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_002.01 ;
   *  4. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_033.01 ;
   *  5. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_023.01 ;
   *  6. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_024.02 ;
   *  7. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_025.01 ;
   *  8. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_026.01 ;
   *  9. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_027.01 ;
   *  10. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_028.01 ;
   *  11. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_029.01 ;
   *  12. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_030.01 ;
   *  13. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_031.02 ;
   *  14. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_032.01 ;
   *  15. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_034.02 ;
   *  16. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  17. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_047.02 ;
   *  18. SubSystem "F01_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_048.02 ;
   */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_pUsThrCorReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pUsThrCorReq'
   */
  Rte_Read_R_TrbAct_pUsThrCorReq_TrbAct_pUsThrCorReq
    (&localTmpSignalConversionAtTrbAc);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_pDifDsCmprUsThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pDifDsCmprUsThrReq'
   */
  Rte_Read_R_AirSys_pDifDsCmprUsThrReq_AirSys_pDifDsCmprUsThrReq
    (&localTmpSignalConversionAtAir_d);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_pUsCmprReqFilOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsCmprReqFil'
   */
  Rte_Read_R_AirSys_pUsCmprReqFil_AirSys_pUsCmprReqFil
    (&localTmpSignalConversionAtAir_a);

  /* DataTypeConversion: '<S8>/Data Type Conversion6' */
  localDataTypeConversion6 = ((Float32)localTmpSignalConversionAtAir_a) * 8.0F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_mfAirThrReqFilOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mfAirThrReqFil'
   */
  Rte_Read_R_AirSys_mfAirThrReqFil_AirSys_mfAirThrReqFil
    (&localTmpSignalConversionAtAirSy);

  /* DataTypeConversion: '<S8>/Data Type Conversion7' */
  localDataTypeConversion7 = ((Float32)localTmpSignalConversionAtAirSy) *
    1.525878906E-005F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtUsThrM_tUsCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tUsCmpr'
   */
  Rte_Read_R_UsThrM_tUsCmpr_UsThrM_tUsCmpr(&localTmpSignalConversionAtUsThr);

  /* DataTypeConversion: '<S8>/Data Type Conversion8' */
  localDataTypeConversion8 = (((Float32)localTmpSignalConversionAtUsThr) *
    0.0078125F) + 223.0F;

  /* Outputs for atomic SubSystem: '<S8>/F01_pwrCmpr' *
   * Block requirements for '<S8>/F01_pwrCmpr':
   *  1. SubSystem "F01_pwrCmpr" !Trace_To : VEMS_R_10_07018_003.01 ;
   */

  /* DataTypeConversion: '<S43>/OutDTConv' incorporates:
   *  Constant: '<S34>/TrbAct_tCmprRef_C'
   *  Constant: '<S43>/offset'
   *  Constant: '<S43>/offset1'
   *  Constant: '<S43>/one_on_slope'
   *  Product: '<S43>/Product4'
   *  Product: '<S52>/Divide'
   *  Sum: '<S43>/Add1'
   *  Sum: '<S43>/Add2'
   */
  localLookupTablenD = (((Float32)(((Float32d)localDataTypeConversion8) /
    (ACTEMS_LdexpF((Float32d)TrbAct_tCmprRef_C, -7) + 223.0F))) * 16384.0F) + 0.5F;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_rTCmprEstim_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_rTCmprEstim_MP = 0U;
    }
  } else {
    TrbAct_rTCmprEstim_MP = MAX_uint16_T;
  }

  /* Lookup: '<S51>/Look-Up Table'
   * About '<S51>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-14
   * Output0 Data Type:  Fixed Point    U16  2^-15
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable), (&(TrbAct_rTCmprSqrt_T[0])),
                 TrbAct_rTCmprEstim_MP, (&(TrbAct_rTCmpr_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate1'
   *
   * Regarding '<S51>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S34>/Data Type Conversion' incorporates:
   *  Lookup: '<S51>/Look-Up Table'
   */
  localDataTypeConversion = ((Float32)localLookUpTable) * 3.051757813E-005F;

  /* Product: '<S47>/Divide' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion4'
   *  DataTypeConversion: '<S8>/Data Type Conversion5'
   *  Sum: '<S34>/Add'
   */
  localDivide_m5 = ((Float32)((localTmpSignalConversionAtTrbAc << 3) +
    (localTmpSignalConversionAtAir_d << 3))) / localDataTypeConversion6;

  /* Outputs for atomic SubSystem: '<S47>/If Action Subsystem3' */

  /* Switch: '<S60>/Switch1' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Constant: '<S60>/Constant2'
   *  Constant: '<S60>/Constant3'
   *  Logic: '<S60>/Logical Operator1'
   *  RelationalOperator: '<S60>/Relational Operator'
   *  RelationalOperator: '<S60>/Relational Operator1'
   *  RelationalOperator: '<S60>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S47>/If Action Subsystem3' */

  /* DataTypeConversion: '<S44>/OutDTConv' incorporates:
   *  Constant: '<S44>/offset'
   *  Constant: '<S44>/offset1'
   *  Constant: '<S44>/one_on_slope'
   *  Product: '<S44>/Product4'
   *  Sum: '<S44>/Add1'
   *  Sum: '<S44>/Add2'
   */
  localLookupTablenD = (8192.0F * localDivide_m5) + 0.5F;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_rPresCmprReq_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_rPresCmprReq_MP = 0U;
    }
  } else {
    TrbAct_rPresCmprReq_MP = MAX_uint16_T;
  }

  /* Lookup: '<S50>/Look-Up Table'
   * About '<S50>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-13
   * Output0 Data Type:  Fixed Point    U16  2^-4
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_n), (&(TrbAct_pwrCmprInter_T[0])),
                 TrbAct_rPresCmprReq_MP, (&(TrbAct_rPresCmprReqRef2_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S50>/Data Type Duplicate1'
   *
   * Regarding '<S50>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S34>/Data Type Conversion3' incorporates:
   *  Lookup: '<S50>/Look-Up Table'
   */
  localDataTypeConversion3_d = ((Float32)localLookUpTable_n) * 0.0625F;

  /* Product: '<S46>/Divide' incorporates:
   *  Constant: '<S34>/TrbAct_pCmprRef_C'
   *  DataTypeConversion: '<S46>/Data Type Conversion'
   */
  localDivide_m5 = (((Float32)TrbAct_pCmprRef_C) * 8.0F) /
    localDataTypeConversion6;

  /* Outputs for atomic SubSystem: '<S46>/If Action Subsystem3' */

  /* Switch: '<S58>/Switch1' incorporates:
   *  Constant: '<S58>/Constant1'
   *  Constant: '<S58>/Constant2'
   *  Constant: '<S58>/Constant3'
   *  Logic: '<S58>/Logical Operator1'
   *  RelationalOperator: '<S58>/Relational Operator'
   *  RelationalOperator: '<S58>/Relational Operator1'
   *  RelationalOperator: '<S58>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S46>/If Action Subsystem3' */

  /* DataTypeConversion: '<S45>/OutDTConv' incorporates:
   *  Constant: '<S45>/offset'
   *  Constant: '<S45>/offset1'
   *  Constant: '<S45>/one_on_slope'
   *  Product: '<S45>/Product4'
   *  Product: '<S53>/Divide'
   *  Product: '<S54>/Divide'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Add2'
   */
  localLookupTablenD = (((localDataTypeConversion * localDivide_m5) *
    localDataTypeConversion7) * 65536.0F) + 0.5F;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_mfAirThrCorReq_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_mfAirThrCorReq_MP = 0U;
    }
  } else {
    TrbAct_mfAirThrCorReq_MP = MAX_uint16_T;
  }

  /* Lookup2D: '<S49>/Look-Up Table (2-D)'
   * About '<S49>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Input1  Data Type:  Fixed Point    U16  2^-13
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D), (&(TrbAct_effCmpr_M[0])),
                     TrbAct_mfAirThrCorReq_MP, (&(TrbAct_mfAirThrCorReq_A[0])),
                     15U, TrbAct_rPresCmprReq_MP, (&(TrbAct_rPresCmprReqRef1_A[0])),
                     15U);

  /* DataTypeDuplicate Block: '<S49>/Data Type Duplicate2'
   *
   * Regarding '<S49>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* SignalConversion Block: '<S39>/copy'
   *
   * Regarding '<S39>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* Product: '<S48>/Divide' incorporates:
   *  DataTypeConversion: '<S34>/Data Type Conversion4'
   */
  localDivide_m5 = localDataTypeConversion3_d / (((Float32)localLookUpTable2D) *
    1.525878906E-005F);

  /* Outputs for atomic SubSystem: '<S48>/If Action Subsystem3' */

  /* Switch: '<S62>/Switch1' incorporates:
   *  Constant: '<S62>/Constant1'
   *  Constant: '<S62>/Constant2'
   *  Constant: '<S62>/Constant3'
   *  Logic: '<S62>/Logical Operator1'
   *  RelationalOperator: '<S62>/Relational Operator'
   *  RelationalOperator: '<S62>/Relational Operator1'
   *  RelationalOperator: '<S62>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S48>/If Action Subsystem3' */

  /* Product: '<S56>/Divide' incorporates:
   *  Product: '<S55>/Divide'
   */
  TrbAct_pwrCmprReq = (localDivide_m5 * localDataTypeConversion7) *
    localDataTypeConversion8;

  /* end of Outputs for SubSystem: '<S8>/F01_pwrCmpr' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S39>/autosar_testpoint1' */

  /* S-Function Block: <S39>/autosar_testpoint1 */
  TrbAct_effCmpr_IRV_MP = localLookUpTable2D;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_mfTrbEstimSatOutport2' incorporates:
   *  Inport: '<Root>/ExM_mfTrbEstimSat'
   */
  Rte_Read_R_ExM_mfTrbEstimSat_ExM_mfTrbEstimSat
    (&localTmpSignalConversionAtExM_m);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_pDsTrbEstimSIOutport2' incorporates:
   *  Inport: '<Root>/ExM_pDsTrbEstimSI'
   */
  Rte_Read_R_ExM_pDsTrbEstimSI_ExM_pDsTrbEstimSI
    (&localTmpSignalConversionAtExM_p);

  /* DataTypeConversion: '<S8>/Data Type Conversion10' */
  localDataTypeConversion10 = ((Float32)localTmpSignalConversionAtExM_p) * 8.0F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_rPresTrbEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_rPresTrbEstim'
   */
  Rte_Read_R_ExM_rPresTrbEstim_ExM_rPresTrbEstim
    (&localTmpSignalConversionAtExM_r);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_mfEgTotOutport2' incorporates:
   *  Inport: '<Root>/ExM_mfEgTot'
   */
  Rte_Read_R_ExM_mfEgTot_ExM_mfEgTot
    (&TrbActSys_B.TmpSignalConversionAtExM_mfEgTo);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&TrbActSys_B.TmpSignalConversionAtExt_nEng_f);

  /* Outputs for atomic SubSystem: '<S8>/F04_mfEgTotFlt' *
   * Block requirements for '<S8>/F04_mfEgTotFlt':
   *  1. SubSystem "F03_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_005.01 ;
   */

  /* DataTypeConversion: '<S37>/Data Type Conversion2' incorporates:
   *  Constant: '<S37>/TrbAct_facFltMfEg_C'
   */
  localDataTypeConversion6 = ((Float32)TrbAct_facFltMfEg_C) * 1.525878906E-005F;

  /* Saturate: '<S131>/Saturation [0-1]' */
  localDivide_m5 = rt_SATURATE(localDataTypeConversion6, 0.0F, 1.0F);

  /* DataTypeConversion: '<S37>/Data Type Conversion1' */
  localDataTypeConversion3_d = ((Float32)
    TrbActSys_B.TmpSignalConversionAtExM_mfEgTo) * 1.525878906E-005F;

  /* UnitDelay: '<S133>/Unit Delay' */
  localDataTypeConversion6 = TrbActSys_DWork.UnitDelay_DSTATE_g;

  /* Switch: '<S124>/Switch' incorporates:
   *  UnitDelay: '<S132>/Unit Delay'
   */
  if (!TrbActSys_DWork.UnitDelay_DSTATE_m) {
    localDataTypeConversion6 = localDataTypeConversion3_d;
  }

  /* Sum: '<S37>/Sum1' */
  localDataTypeConversion6 = localDataTypeConversion3_d -
    localDataTypeConversion6;

  /* UnitDelay: '<S130>/UnitDelay' */
  localDataTypeConversion = TrbActSys_DWork.UnitDelay;

  /* Switch: '<S130>/Switch' incorporates:
   *  UnitDelay: '<S130>/UnitDelay1'
   */
  if (!TrbActSys_DWork.UnitDelay_k) {
    localDataTypeConversion = localDataTypeConversion6;
  }

  /* Sum: '<S131>/Sum1' incorporates:
   *  Product: '<S131>/Product'
   *  Sum: '<S131>/Sum'
   */
  localDivide_m5 = ((localDataTypeConversion6 - localDataTypeConversion) *
                    localDivide_m5) + localDataTypeConversion;

  /* Switch: '<S128>/Switch' incorporates:
   *  UnitDelay: '<S128>/UnitDelay'
   */
  if (TrbActSys_DWork.UnitDelay_DSTATE_a) {
    localDataTypeConversion6 = localDivide_m5;
  }

  /* Product: '<S122>/Product4' incorporates:
   *  Constant: '<S122>/offset'
   *  Constant: '<S122>/one_on_slope'
   *  Sum: '<S122>/Add1'
   */
  localDataTypeConversion = 32768.0F * localDataTypeConversion6;

  /* Switch: '<S122>/Switch1' incorporates:
   *  Constant: '<S122>/offset2'
   *  Constant: '<S122>/offset3'
   *  Constant: '<S122>/offset4'
   *  RelationalOperator: '<S122>/Relational Operator'
   *  Sum: '<S122>/Add3'
   *  Sum: '<S122>/Add4'
   */
  if (localDataTypeConversion >= 0.0F) {
    localDataTypeConversion += 0.5F;
  } else {
    localDataTypeConversion -= 0.5F;
  }

  /* DataTypeConversion: '<S122>/OutDTConv' */
  if (localDataTypeConversion < 32768.0F) {
    if (localDataTypeConversion >= -32768.0F) {
      ExM_mfEgTotGrdFlt_MP = (SInt16)localDataTypeConversion;
    } else {
      ExM_mfEgTotGrdFlt_MP = MIN_int16_T;
    }
  } else {
    ExM_mfEgTotGrdFlt_MP = MAX_int16_T;
  }

  /* DataTypeConversion: '<S37>/Data Type Conversion7' */
  localtmp_0 = ExM_mfEgTotGrdFlt_MP + 16383;
  if (localtmp_0 <= 0) {
    localTmpSignalConversionAtTrbAc = 0U;
  } else {
    localTmpSignalConversionAtTrbAc = (UInt16)localtmp_0;
  }

  /* Lookup_n-D: '<S120>/Lookup Table (n-D)' */
  localDataTypeConversion = look2_1fcv2bcvbcvbfbbr7xfbbnx
    (TrbActSys_B.TmpSignalConversionAtExt_nEng_f,
     localTmpSignalConversionAtTrbAc, (&(TrbAct_nEng_A[0])), (&(TrbAct_mfGrd_A[0])),
     (&(TrbAct_facFltPred_M[0])), &TrbActSys_ConstP.LookupTablenD_maxIn_o[0], 9U);

  /* DataStoreWrite: '<S37>/TrbAct_facUsTrbMfCor_MP_Write1' incorporates:
   *  Constant: '<S121>/offset'
   *  Constant: '<S121>/offset1'
   *  Constant: '<S121>/one_on_slope'
   *  DataTypeConversion: '<S121>/OutDTConv'
   *  Product: '<S121>/Product4'
   *  Sum: '<S121>/Add1'
   *  Sum: '<S121>/Add2'
   */
  localLookupTablenD = (6.553599854E+002F * localDataTypeConversion) + 0.5F;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_facFltPred_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_facFltPred_MP = 0U;
    }
  } else {
    TrbAct_facFltPred_MP = MAX_uint16_T;
  }

  /* UnitDelay: '<S123>/Unit Delay' */
  ExM_mfEgTotGrdPrev_MP = TrbActSys_DWork.UnitDelay_DSTATE_n;

  /* Sum: '<S37>/Sum3' incorporates:
   *  Constant: '<S37>/TrbAct_facFltPred1_C'
   *  Constant: '<S37>/TrbAct_facFltPred2_C'
   *  DataTypeConversion: '<S37>/Data Type Conversion3'
   *  DataTypeConversion: '<S37>/Data Type Conversion4'
   *  DataTypeConversion: '<S37>/Data Type Conversion5'
   *  Product: '<S125>/Divide'
   *  Product: '<S126>/Divide'
   *  Product: '<S127>/Divide'
   *  Sum: '<S37>/Sum2'
   */
  ExM_mfEgTotFlt = ((((((Float32)TrbAct_facFltPred1_C) * 1.525878906E-005F) *
                      localDataTypeConversion6) + ((((Float32)
    ExM_mfEgTotGrdPrev_MP) * 3.051757813E-005F) * (((Float32)
    TrbAct_facFltPred2_C) * 1.525878906E-005F))) * localDataTypeConversion) +
    localDataTypeConversion3_d;

  /* Update for UnitDelay: '<S133>/Unit Delay' */
  TrbActSys_DWork.UnitDelay_DSTATE_g = localDataTypeConversion3_d;

  /* Update for UnitDelay: '<S132>/Unit Delay' incorporates:
   *  Constant: '<S124>/Constant3'
   */
  TrbActSys_DWork.UnitDelay_DSTATE_m = TRUE;

  /* Update for UnitDelay: '<S130>/UnitDelay' */
  TrbActSys_DWork.UnitDelay = localDivide_m5;

  /* Update for UnitDelay: '<S130>/UnitDelay1' incorporates:
   *  Constant: '<S130>/Constant3'
   */
  TrbActSys_DWork.UnitDelay_k = TRUE;

  /* Update for UnitDelay: '<S128>/UnitDelay' incorporates:
   *  Constant: '<S128>/Constant3'
   */
  TrbActSys_DWork.UnitDelay_DSTATE_a = TRUE;

  /* Update for UnitDelay: '<S123>/Unit Delay' */
  TrbActSys_DWork.UnitDelay_DSTATE_n = ExM_mfEgTotGrdFlt_MP;

  /* end of Outputs for SubSystem: '<S8>/F04_mfEgTotFlt' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_pExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_pExMnfEstim'
   */
  Rte_Read_R_ExM_pExMnfEstim_ExM_pExMnfEstim(&localTmpSignalConversionAtExM_j);

  /* DataTypeConversion: '<S8>/Data Type Conversion13' */
  localDataTypeConversion13 = ((Float32)localTmpSignalConversionAtExM_j) * 8.0F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_tExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExMnfEstim'
   */
  Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim
    (&TrbActSys_B.TmpSignalConversionAtExM_tExMnf);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_pExMnfReqPrevOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pExMnfReq_INPUT'
   */
  Rte_Read_R_TrbAct_pExMnfReq_TrbAct_pExMnfReq(&localTmpSignalConversionAtTrb_m);

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  localDataTypeConversion = ((Float32)localTmpSignalConversionAtTrb_m) * 16.0F;

  /* Outputs for atomic SubSystem: '<S8>/F02_mfTrbAct' *
   * Block requirements for '<S8>/F02_mfTrbAct':
   *  1. SubSystem "F02_mfTrbAct" !Trace_To : VEMS_R_10_07018_004.01 ;
   */

  /* DataTypeConversion: '<S35>/Data Type Conversion4' */
  localDataTypeConversion3_d = (((Float32)
    TrbActSys_B.TmpSignalConversionAtExM_tExMnf) * 0.03125F) + 223.0F;

  /* Sum: '<S72>/Add2' incorporates:
   *  Constant: '<S35>/TrbAct_tTrbRef_C'
   *  Constant: '<S72>/offset'
   *  Constant: '<S72>/offset1'
   *  Constant: '<S72>/one_on_slope'
   *  DataTypeConversion: '<S35>/Data Type Conversion8'
   *  Product: '<S72>/Product4'
   *  Product: '<S84>/Divide'
   *  Sum: '<S72>/Add1'
   */
  localLookupTablenD_j = ((localDataTypeConversion3_d / ((((Float32)
    TrbAct_tTrbRef_C) * 0.03125F) + 223.0F)) * 8192.0F) + 0.5F;

  /* DataTypeConversion: '<S72>/OutDTConv' */
  if (localLookupTablenD_j < 65536.0F) {
    TrbAct_rTTrbEstim_MP = (UInt16)localLookupTablenD_j;
  } else {
    TrbAct_rTTrbEstim_MP = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S67>/Lookup Table (n-D)' */
  localLookupTablenD_j = look1_iu16lftu16n14If_binlcns(TrbAct_rTTrbEstim_MP,
    (&(TrbAct_rTTrb_A[0])), (&(TrbAct_rTTrbSqrt_T[0])), 15U);

  /* DataTypeConversion: '<S35>/Data Type Conversion7' incorporates:
   *  Constant: '<S35>/TrbAct_pTrbRef_C'
   */
  localDataTypeConversion7 = ((Float32)TrbAct_pTrbRef_C) * 8.0F;

  /* Product: '<S80>/Divide' */
  localDivide_m5 = localDataTypeConversion7 / localDataTypeConversion13;

  /* Outputs for atomic SubSystem: '<S80>/If Action Subsystem3' */

  /* Switch: '<S97>/Switch1' incorporates:
   *  Constant: '<S97>/Constant1'
   *  Constant: '<S97>/Constant2'
   *  Constant: '<S97>/Constant3'
   *  Logic: '<S97>/Logical Operator1'
   *  RelationalOperator: '<S97>/Relational Operator'
   *  RelationalOperator: '<S97>/Relational Operator1'
   *  RelationalOperator: '<S97>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S80>/If Action Subsystem3' */

  /* Product: '<S87>/Divide' */
  localLookupTablenD_jt = localLookupTablenD_j * localDivide_m5;

  /* Sum: '<S74>/Add1' incorporates:
   *  Constant: '<S74>/offset'
   */
  localDivide_m5 = localLookupTablenD_jt;

  /* DataStoreWrite: '<S35>/TrbAct_facUsTrbMfCor_MP_Write' incorporates:
   *  Constant: '<S74>/offset1'
   *  Constant: '<S74>/one_on_slope'
   *  DataTypeConversion: '<S74>/OutDTConv'
   *  Product: '<S74>/Product4'
   *  Sum: '<S74>/Add2'
   */
  localLookupTablenD = (1.310720020E+004F * localDivide_m5) + 0.5F;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_facUsTrbMfCor_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_facUsTrbMfCor_MP = 0U;
    }
  } else {
    TrbAct_facUsTrbMfCor_MP = MAX_uint16_T;
  }

  /* Product: '<S81>/Divide' */
  localDataTypeConversion6 = localDataTypeConversion7 /
    localDataTypeConversion10;

  /* Outputs for atomic SubSystem: '<S81>/If Action Subsystem3' */

  /* Switch: '<S99>/Switch1' incorporates:
   *  Constant: '<S99>/Constant1'
   *  Constant: '<S99>/Constant2'
   *  Constant: '<S99>/Constant3'
   *  Logic: '<S99>/Logical Operator1'
   *  RelationalOperator: '<S99>/Relational Operator'
   *  RelationalOperator: '<S99>/Relational Operator1'
   *  RelationalOperator: '<S99>/Relational Operator3'
   */
  if (((localDataTypeConversion6 != localDataTypeConversion6) ||
       (localDataTypeConversion6 > 3.000000005E+038F)) || (-3.000000005E+038F >
       localDataTypeConversion6)) {
    localDataTypeConversion6 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S81>/If Action Subsystem3' */

  /* Product: '<S90>/Divide' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion9'
   */
  localDivide_m5 = (((Float32)localTmpSignalConversionAtExM_m) *
                    1.525878906E-005F) * localLookupTablenD_jt;

  /* Sum: '<S73>/Add2' incorporates:
   *  Constant: '<S73>/offset'
   *  Constant: '<S73>/offset1'
   *  Constant: '<S73>/one_on_slope'
   *  Product: '<S73>/Product4'
   *  Sum: '<S73>/Add1'
   */
  localDataTypeConversion8 = (65536.0F * localDivide_m5) + 0.5F;

  /* DataTypeConversion: '<S73>/OutDTConv' */
  if (localDataTypeConversion8 < 65536.0F) {
    if (localDataTypeConversion8 >= 0.0F) {
      TrbAct_mfTrbCorEstim_MP = (UInt16)localDataTypeConversion8;
    } else {
      TrbAct_mfTrbCorEstim_MP = 0U;
    }
  } else {
    TrbAct_mfTrbCorEstim_MP = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S69>/Lookup Table (n-D)' */
  localDataTypeConversion8 = look2_1fcv2bcvbcvbfbbr6dfbbnx
    (TrbAct_mfTrbCorEstim_MP, localTmpSignalConversionAtExM_r,
     (&(TrbAct_mfTrbCorEstim_A[0])), (&(TrbAct_rPresTrbEstim_A[0])),
     (&(TrbAct_effTrb_M[0])), &TrbActSys_ConstP.LookupTablenD_maxInde[0], 16U);

  /* PreLookup: '<S70>/Prelookup' */
  localExM_tExMnfEstim_TrbAct_tUs = plook_u32u16f_binc
    (TrbActSys_B.TmpSignalConversionAtExM_tExMnf, (&(TrbAct_tUsTrbEstim_A[0])),
     15U, &localLookupTablenD_jt);

  /* Interpolation_n-D: '<S65>/Interpolation Using Prelookup3' */
  localDivide_m5 = localLookupTablenD_jt;
  localAdd2_c = intrp1d_iu16n4ff_u32f_l_ns__1(localExM_tExMnfEstim_TrbAct_tUs,
    localDivide_m5, (&(TrbAct_cppEg_T[0])));

  /* Product: '<S85>/Divide' */
  localDivide_m5 = localAdd2_c * localDataTypeConversion3_d;

  /* Product: '<S82>/Divide' incorporates:
   *  Product: '<S86>/Divide'
   */
  localDivide_m5 = TrbAct_pwrCmprReq / (localDataTypeConversion8 *
    localDivide_m5);

  /* Outputs for atomic SubSystem: '<S82>/If Action Subsystem3' */

  /* Switch: '<S101>/Switch1' incorporates:
   *  Constant: '<S101>/Constant1'
   *  Constant: '<S101>/Constant2'
   *  Constant: '<S101>/Constant3'
   *  Logic: '<S101>/Logical Operator1'
   *  RelationalOperator: '<S101>/Relational Operator'
   *  RelationalOperator: '<S101>/Relational Operator1'
   *  RelationalOperator: '<S101>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S82>/If Action Subsystem3' */

  /* Sum: '<S75>/Add2' incorporates:
   *  Constant: '<S75>/offset'
   *  Constant: '<S75>/offset1'
   *  Constant: '<S75>/one_on_slope'
   *  Product: '<S75>/Product4'
   *  Product: '<S88>/Divide'
   *  Product: '<S89>/Divide'
   *  Sum: '<S75>/Add1'
   */
  localAdd2_c = (((localDataTypeConversion6 * localLookupTablenD_j) *
                  localDivide_m5) * 65536.0F) + 0.5F;

  /* DataTypeConversion: '<S75>/OutDTConv' */
  localLookupTablenD = localAdd2_c;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_mfRatPresTrbInter_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_mfRatPresTrbInter_MP = 0U;
    }
  } else {
    TrbAct_mfRatPresTrbInter_MP = MAX_uint16_T;
  }

  /* PreLookup: '<S71>/Prelookup' */
  localTrbAct_mfRatPresTrbInter_M = plook_u32u16f_binc
    (TrbAct_mfRatPresTrbInter_MP, (&(TrbAct_mfRatPresTrbActInter_A[0])), 15U,
     &localAdd2_c);

  /* Interpolation_n-D: '<S66>/Interpolation Using Prelookup3' */
  localDivide_m5 = localAdd2_c;
  localfrac[0] = localDivide_m5;
  localDivide_m5 = localLookupTablenD_jt;
  localfrac[1] = localDivide_m5;
  localbpIndex[0] = localTrbAct_mfRatPresTrbInter_M;
  localbpIndex[1] = localExM_tExMnfEstim_TrbAct_tUs;
  localAdd2_c = intrp2d_iu16n13ff_u32f_l_ns__2(localbpIndex, localfrac,
    (&(TrbAct_rPresTrbReq_M[0])), 16U);

  /* Sum: '<S78>/Add1' incorporates:
   *  Constant: '<S78>/offset'
   */
  localDivide_m5 = localAdd2_c;

  /* Sum: '<S78>/Add2' incorporates:
   *  Constant: '<S78>/offset1'
   *  Constant: '<S78>/one_on_slope'
   *  Product: '<S78>/Product4'
   */
  localLookupTablenD_jt = (8192.0F * localDivide_m5) + 0.5F;

  /* DataTypeConversion: '<S78>/OutDTConv' */
  localLookupTablenD = localLookupTablenD_jt;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_rPresTrbReq_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_rPresTrbReq_MP = 0U;
    }
  } else {
    TrbAct_rPresTrbReq_MP = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S68>/Lookup Table (n-D)' */
  localLookupTablenD_jt = look1_iu16lftu16n16If_binlcns(TrbAct_rPresTrbReq_MP, (
    &(TrbAct_rPresTrbReq_A[0])), (&(TrbAct_mfTrbCorReq_T[0])), 15U);

  /* Sum: '<S79>/Add1' incorporates:
   *  Constant: '<S79>/offset'
   */
  localDivide_m5 = localLookupTablenD_jt;

  /* DataStoreWrite: '<S35>/TrbAct_facUsTrbMfCor_MP_Write2' incorporates:
   *  Constant: '<S79>/offset1'
   *  Constant: '<S79>/one_on_slope'
   *  DataTypeConversion: '<S79>/OutDTConv'
   *  Product: '<S79>/Product4'
   *  Sum: '<S79>/Add2'
   */
  localLookupTablenD = (65536.0F * localDivide_m5) + 0.5F;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_mfTrbCorReq_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_mfTrbCorReq_MP = 0U;
    }
  } else {
    TrbAct_mfTrbCorReq_MP = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S35>/Data Type Conversion3' incorporates:
   *  Constant: '<S35>/TrbAct_facFilPExMnfReq_C'
   */
  localDataTypeConversion3_d = ((Float32)TrbAct_facFilPExMnfReq_C) *
    1.525878906E-005F;

  /* Product: '<S35>/Product' */
  localDivide_m5 = localAdd2_c * localDataTypeConversion10;

  /* Sum: '<S95>/Sum1' incorporates:
   *  Product: '<S95>/Product'
   *  Saturate: '<S95>/Saturation [0-1]'
   *  Sum: '<S95>/Sum'
   */
  localDataTypeConversion6 = ((localDivide_m5 - localDataTypeConversion) *
    rt_SATURATE(localDataTypeConversion3_d, 0.0F, 1.0F)) +
    localDataTypeConversion;

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/TrbAct_bAcvPExMnfReq_C'
   */
  if (TrbAct_bAcvPExMnfReq_C) {
    localAdd2_c = localDataTypeConversion6;
  } else {
    localAdd2_c = localDataTypeConversion13;
  }

  /* Sum: '<S77>/Add1' incorporates:
   *  Constant: '<S77>/offset'
   */
  localDivide_m5 = localAdd2_c;

  /* DataStoreWrite: '<S35>/TrbAct_pExMnf_MP_Write' incorporates:
   *  Constant: '<S77>/offset1'
   *  Constant: '<S77>/one_on_slope'
   *  DataTypeConversion: '<S77>/OutDTConv'
   *  Product: '<S77>/Product4'
   *  Sum: '<S77>/Add2'
   */
  localLookupTablenD = (0.0625F * localDivide_m5) + 0.5F;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      TrbAct_pExMnf_MP = (UInt16)localLookupTablenD;
    } else {
      TrbAct_pExMnf_MP = 0U;
    }
  } else {
    TrbAct_pExMnf_MP = MAX_uint16_T;
  }

  /* Product: '<S63>/Divide' */
  localDivide_m5 = localDataTypeConversion7 / localAdd2_c;

  /* Outputs for atomic SubSystem: '<S63>/If Action Subsystem3' */

  /* Switch: '<S92>/Switch1' incorporates:
   *  Constant: '<S92>/Constant2'
   *  RelationalOperator: '<S92>/Relational Operator'
   *  Saturate: '<S92>/Saturation'
   */
  if (localDivide_m5 != localDivide_m5) {
    localDivide_m5 = 0.0F;
  } else {
    localDivide_m5 = rt_SATURATE(localDivide_m5, -3.000000005E+038F,
      3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S63>/If Action Subsystem3' */

  /* Product: '<S83>/Divide' incorporates:
   *  Product: '<S35>/Product3'
   */
  localDivide_m5 = localLookupTablenD_jt / (localLookupTablenD_j *
    localDivide_m5);

  /* Outputs for atomic SubSystem: '<S83>/If Action Subsystem3' */

  /* Switch: '<S103>/Switch1' incorporates:
   *  Constant: '<S103>/Constant1'
   *  Constant: '<S103>/Constant2'
   *  Constant: '<S103>/Constant3'
   *  Logic: '<S103>/Logical Operator1'
   *  RelationalOperator: '<S103>/Relational Operator'
   *  RelationalOperator: '<S103>/Relational Operator1'
   *  RelationalOperator: '<S103>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S83>/If Action Subsystem3' */

  /* Sum: '<S35>/Add' */
  TrbAct_mfTrbActReq = ExM_mfEgTotFlt - localDivide_m5;

  /* Sum: '<S76>/Add2' incorporates:
   *  Constant: '<S76>/offset'
   *  Constant: '<S76>/offset1'
   *  Constant: '<S76>/one_on_slope'
   *  Product: '<S76>/Product4'
   *  Sum: '<S76>/Add1'
   */
  localAdd2_c = (65536.0F * localDataTypeConversion8) + 0.5F;

  /* DataTypeConversion: '<S76>/OutDTConv' */
  localLookupTablenD = localAdd2_c;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      localOutDTConv = (UInt16)localLookupTablenD;
    } else {
      localOutDTConv = 0U;
    }
  } else {
    localOutDTConv = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S8>/F02_mfTrbAct' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S40>/autosar_testpoint1' */

  /* S-Function Block: <S40>/autosar_testpoint1 */
  TrbAct_effTrb_IRV_MP = localOutDTConv;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtExM_rPresTrbEstimIvsOutport2' incorporates:
   *  Inport: '<Root>/ExM_rPresTrbEstimIvs'
   */
  Rte_Read_R_ExM_rPresTrbEstimIvs_ExM_rPresTrbEstimIvs
    (&localTmpSignalConversionAtExM_e);

  /* DataTypeConversion: '<S8>/Data Type Conversion11' */
  if (localTmpSignalConversionAtExM_e > 8191) {
    TrbActSys_B.DataTypeConversion11 = MAX_uint16_T;
  } else {
    TrbActSys_B.DataTypeConversion11 = (UInt16)
      (localTmpSignalConversionAtExM_e << 3);
  }

  /* Outputs for atomic SubSystem: '<S8>/F03_ArTrbActClcn' *
   * Block requirements for '<S8>/F03_ArTrbActClcn':
   *  1. SubSystem "F03_ArTrbActClcn" !Trace_To : VEMS_R_10_07018_005.01 ;
   */

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/TrbAct_bSelPresExMnf_C'
   */
  if (TrbAct_bSelPresExMnf_C) {
    localDataTypeConversion13 = localDataTypeConversion6;
  }

  /* Product: '<S110>/Divide' */
  localDivide_m5 = localDataTypeConversion10 / localDataTypeConversion13;

  /* Outputs for atomic SubSystem: '<S110>/If Action Subsystem3' */

  /* Switch: '<S118>/Switch1' incorporates:
   *  Constant: '<S118>/Constant1'
   *  Constant: '<S118>/Constant2'
   *  Constant: '<S118>/Constant3'
   *  Logic: '<S118>/Logical Operator1'
   *  RelationalOperator: '<S118>/Relational Operator'
   *  RelationalOperator: '<S118>/Relational Operator1'
   *  RelationalOperator: '<S118>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = 1.0F;
  }

  /* end of Outputs for SubSystem: '<S110>/If Action Subsystem3' */

  /* DataTypeConversion: '<S110>/Data Type Conversion2' */
  localtmp = ACTEMS_LdexpF((Float32d)localDivide_m5, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localTmpSignalConversionAtTrbAc = (UInt16)localtmp;
    } else {
      localTmpSignalConversionAtTrbAc = 0U;
    }
  } else {
    localTmpSignalConversionAtTrbAc = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S105>/Lookup Table (n-D)' */
  localLookupTablenD = look1_iu16lftu16n20If_binlcns
    (localTmpSignalConversionAtTrbAc, (&(TrbAct_rPresTrbEstimIvsRef2_A[0])),
     (&(TrbAct_facCfeTrbAct_T[0])), 15U);

  /* Sum: '<S107>/Add2' incorporates:
   *  Constant: '<S107>/offset'
   *  Constant: '<S107>/offset1'
   *  Constant: '<S107>/one_on_slope'
   *  Product: '<S107>/Product4'
   *  Sum: '<S107>/Add1'
   */
  localDivide_m5 = ((localLookupTablenD - 9.536743164E-007F) * 1.048576E+006F) +
    0.5F;

  /* DataStoreWrite: '<S36>/TrbAct_pExMnf_MP_Write1' incorporates:
   *  DataTypeConversion: '<S107>/OutDTConv'
   */
  if (localDivide_m5 < 65536.0F) {
    if (localDivide_m5 >= 0.0F) {
      TrbAct_facCfeTrbAct_MP = (UInt16)localDivide_m5;
    } else {
      TrbAct_facCfeTrbAct_MP = 0U;
    }
  } else {
    TrbAct_facCfeTrbAct_MP = MAX_uint16_T;
  }

  /* Lookup_n-D: '<S104>/Lookup Table (n-D)' */
  localDivide_m5 = look1_iu16lftu16n10If_binlcns
    (TrbActSys_B.TmpSignalConversionAtExM_tExMnf, (&(TrbAct_tUsTrbEstim_A[0])),
     (&(TrbAct_tUsTrbEstimSqrt_T[0])), 15U);

  /* Product: '<S108>/Divide' incorporates:
   *  Product: '<S112>/Divide'
   */
  localDivide_m5 = (TrbAct_mfTrbActReq * localDivide_m5) /
    localDataTypeConversion13;

  /* Outputs for atomic SubSystem: '<S108>/If Action Subsystem3' */

  /* Switch: '<S114>/Switch1' incorporates:
   *  Constant: '<S114>/Constant1'
   *  Constant: '<S114>/Constant2'
   *  Constant: '<S114>/Constant3'
   *  Logic: '<S114>/Logical Operator1'
   *  RelationalOperator: '<S114>/Relational Operator'
   *  RelationalOperator: '<S114>/Relational Operator1'
   *  RelationalOperator: '<S114>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = 9.999999747E-006F;
  }

  /* end of Outputs for SubSystem: '<S108>/If Action Subsystem3' */

  /* Product: '<S109>/Divide' */
  localDivide_m5 /= localLookupTablenD;

  /* Outputs for atomic SubSystem: '<S109>/If Action Subsystem3' */

  /* Switch: '<S116>/Switch1' incorporates:
   *  Constant: '<S116>/Constant1'
   *  Constant: '<S116>/Constant2'
   *  Constant: '<S116>/Constant3'
   *  Logic: '<S116>/Logical Operator1'
   *  RelationalOperator: '<S116>/Relational Operator'
   *  RelationalOperator: '<S116>/Relational Operator1'
   *  RelationalOperator: '<S116>/Relational Operator3'
   */
  if (((localDivide_m5 != localDivide_m5) || (localDivide_m5 > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_m5)) {
    localDivide_m5 = ((Float32)TrbAct_arTrbActReqMax_C) * 9.536743164E-007F;
  }

  /* end of Outputs for SubSystem: '<S109>/If Action Subsystem3' */

  /* DataTypeConversion: '<S106>/OutDTConv' incorporates:
   *  Constant: '<S106>/offset'
   *  Constant: '<S106>/offset1'
   *  Constant: '<S106>/one_on_slope'
   *  Product: '<S106>/Product4'
   *  Sum: '<S106>/Add1'
   *  Sum: '<S106>/Add2'
   */
  localLookupTablenD = (1.048576E+006F * localDivide_m5) + 0.5F;
  if (localLookupTablenD < 65536.0F) {
    if (localLookupTablenD >= 0.0F) {
      localOutDTConv_ow = (UInt16)localLookupTablenD;
    } else {
      localOutDTConv_ow = 0U;
    }
  } else {
    localOutDTConv_ow = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S8>/F03_ArTrbActClcn' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S41>/autosar_testpoint1' */

  /* S-Function Block: <S41>/autosar_testpoint1 */
  TrbAct_arTrbActReq_IRV_MP = localOutDTConv_ow;

  /* SignalConversion: '<S8>/Signal Conversion1' */
  localTmpSignalConversionAtAir_a = localLookUpTable2D;

  /* SignalConversion: '<S8>/Signal Conversion2' */
  localTmpSignalConversionAtTrbAc = localOutDTConv;

  /* Sum: '<S38>/Add2' incorporates:
   *  Constant: '<S38>/offset'
   *  Constant: '<S38>/offset1'
   *  Constant: '<S38>/one_on_slope'
   *  Product: '<S38>/Product4'
   *  Sum: '<S38>/Add1'
   */
  localDivide_m5 = (0.0625F * localDataTypeConversion6) + 0.5F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_arTrbActReq_irvInport2' incorporates:
   *  SignalConversion: '<S8>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_TrbActSys_002_TEV_TrbAct_arTrbActReq_irv(localOutDTConv_ow);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_effCmpr_irvInport2' */
  Rte_IrvWrite_RE_TrbActSys_002_TEV_TrbAct_effCmpr_irv
    (localTmpSignalConversionAtAir_a);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_effTrb_irvInport2' */
  Rte_IrvWrite_RE_TrbActSys_002_TEV_TrbAct_effTrb_irv
    (localTmpSignalConversionAtTrbAc);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Byp_Fonction_SC'
   *  Constant: '<S42>/Int_BypC'
   *  DataTypeConversion: '<S38>/OutDTConv'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAir_a = TrbAct_pExMnfReq_B;
  } else if (localDivide_m5 < 65536.0F) {
    if (localDivide_m5 >= 0.0F) {
      localTmpSignalConversionAtAir_a = (UInt16)localDivide_m5;
    } else {
      localTmpSignalConversionAtAir_a = 0U;
    }
  } else {
    localTmpSignalConversionAtAir_a = MAX_uint16_T;
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtTrbAct_pExMnfReqInport2' */
  Rte_Write_P_TrbAct_pExMnfReq_TrbAct_pExMnfReq(localTmpSignalConversionAtAir_a);
}

/* Output and update for exported function: RE_TrbActSys_005_TEV */
void RE_TrbActSys_005_TEV(void)
{
  Float32 localDataTypeConversion1_j;
  UInt8 localTmpSignalConversionAtTWCMg;
  Boolean localTmpSignalConversionAtLsSys;
  Boolean localLogicalOperator3;
  Float32 localTrbAct_rAirLdAltiCorReq_Tr;
  Float32 localInterpolationUsingPrelooku;
  Float32 localfrac[2];
  UInt32 localExt_nEng_TrbAct_nEng2_A_9_;
  UInt32 localbpIndex[2];
  UInt32 localTrbAct_rAirLdAltiCorReq__n;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localAdd2_n;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localTmpSignalConversionAtAir_n;
  UInt16 localTmpSignalConversionAtTrb_b;
  UInt16 localMerge1;
  UInt16 localTmpSignalConversionAtTrb_c;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F04_posnRelTrbActTWCMgtMod'
   *
   * Block requirements for '<S1>/F04_posnRelTrbActTWCMgtMod':
   *  1. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_077.02 ;
   *  2. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_061.01 ;
   *  3. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_060.01 ;
   *  4. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_063.01 ;
   *  5. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_036.01 ;
   *  6. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_039.02 ;
   *  7. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_044.01 ;
   *  8. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_074.01 ;
   *  9. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_072.01 ;
   *  10. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_073.01 ;
   *  11. SubSystem "F04_posnRelTrbActTWCMgtMod" !Trace_To : VEMS_R_10_07018_071.01 ;
   */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_rAirLdReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_rAirLdReq'
   */
  Rte_Read_R_AirSys_rAirLdReq_AirSys_rAirLdReq(&localTmpSignalConversionAtAir_n);

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  localDataTypeConversion1_j = ((Float32)localTmpSignalConversionAtAir_n) *
    6.103515625E-005F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtTrbAct_facPresAltiCorOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_facPresAltiCor'
   */
  Rte_Read_R_TrbAct_facPresAltiCor_TrbAct_facPresAltiCor
    (&localTmpSignalConversionAtTrb_b);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtLsSys_bLsUsMainOxCDewProtReqOutport2' incorporates:
   *  Inport: '<Root>/LsSys_bLsUsMainOxCDewProtReq'
   */
  Rte_Read_R_LsSys_bLsUsMainOxCDewProtReq_LsSys_bLsUsMainOxCDewProtReq
    (&localTmpSignalConversionAtLsSys);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtTWCMgt_stTrbActPosnReqOutport2' incorporates:
   *  Inport: '<Root>/TWCMgt_stTrbActPosnReq'
   */
  Rte_Read_R_TWCMgt_stTrbActPosnReq_TWCMgt_stTrbActPosnReq
    (&localTmpSignalConversionAtTWCMg);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* Logic: '<S11>/Logical Operator3' incorporates:
   *  Constant: '<S11>/ConstVal'
   *  Constant: '<S11>/TrbAct_bAcvOpRelTWCMgt_C'
   *  Logic: '<S11>/Logical Operator1'
   *  RelationalOperator: '<S11>/Relational Operator'
   */
  localLogicalOperator3 = (((localTmpSignalConversionAtTWCMg != 0) ||
    (localTmpSignalConversionAtLsSys)) && TrbAct_bAcvOpRelTWCMgt_C);

  /* Outputs for enable SubSystem: '<S11>/F01_posnRelTrbActTWCMgtReq' incorporates:
   *  EnablePort: '<S249>/Enable'
   *
   * Block requirements for '<S11>/F01_posnRelTrbActTWCMgtReq':
   *  1. SubSystem "F01_posnRelTrbActTWCMgtReq" !Trace_To : VEMS_R_10_07018_064.01 ;
   */
  if (localLogicalOperator3) {
    /* PreLookup: '<S255>/Prelookup' */
    localExt_nEng_TrbAct_nEng2_A_9_ = plook_u32u16f_binc
      (localTmpSignalConversionAtExt_n, (&(TrbAct_nEng2_A[0])), 8U,
       &localInterpolationUsingPrelooku);

    /* Switch: '<S249>/Switch' incorporates:
     *  Constant: '<S249>/TrbAct_bPresAltiCor_C'
     *  DataTypeConversion: '<S11>/Data Type Conversion3'
     *  Product: '<S259>/Divide'
     */
    if (TrbAct_bPresAltiCor_C) {
      localTrbAct_rAirLdAltiCorReq_Tr = (((Float32)
        localTmpSignalConversionAtTrb_b) * 3.051757813E-005F) *
        localDataTypeConversion1_j;
    } else {
      localTrbAct_rAirLdAltiCorReq_Tr = localDataTypeConversion1_j;
    }

    /* Sum: '<S257>/Add1' incorporates:
     *  Constant: '<S257>/offset'
     */
    localDataTypeConversion1_j = localTrbAct_rAirLdAltiCorReq_Tr;

    /* Sum: '<S257>/Add2' incorporates:
     *  Constant: '<S257>/offset1'
     *  Constant: '<S257>/one_on_slope'
     *  Product: '<S257>/Product4'
     */
    localTrbAct_rAirLdAltiCorReq_Tr = (16384.0F * localDataTypeConversion1_j) +
      0.5F;

    /* DataTypeConversion: '<S257>/OutDTConv' */
    localDataTypeConversion1_j = localTrbAct_rAirLdAltiCorReq_Tr;
    if (localDataTypeConversion1_j < 65536.0F) {
      if (localDataTypeConversion1_j >= 0.0F) {
        localTmpSignalConversionAtAir_n = (UInt16)localDataTypeConversion1_j;
      } else {
        localTmpSignalConversionAtAir_n = 0U;
      }
    } else {
      localTmpSignalConversionAtAir_n = MAX_uint16_T;
    }

    /* PreLookup: '<S256>/Prelookup' */
    localTrbAct_rAirLdAltiCorReq__n = plook_u32u16f_binc
      (localTmpSignalConversionAtAir_n, (&(TrbAct_rAirLdAltiCorReq2_A[0])), 8U,
       &localTrbAct_rAirLdAltiCorReq_Tr);

    /* Interpolation_n-D: '<S253>/Interpolation Using Prelookup3' */
    localDataTypeConversion1_j = localInterpolationUsingPrelooku;
    localfrac[0] = localDataTypeConversion1_j;
    localDataTypeConversion1_j = localTrbAct_rAirLdAltiCorReq_Tr;
    localfrac[1] = localDataTypeConversion1_j;
    localbpIndex[0] = localExt_nEng_TrbAct_nEng2_A_9_;
    localbpIndex[1] = localTrbAct_rAirLdAltiCorReq__n;
    localAdd2_n = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex, localfrac,
      (&(TrbAct_rOpRelTrbActExtReq1_M[0])), 9U);

    /* Interpolation_n-D: '<S254>/Interpolation Using Prelookup3' */
    localDataTypeConversion1_j = localInterpolationUsingPrelooku;
    localfrac_0[0] = localDataTypeConversion1_j;
    localDataTypeConversion1_j = localTrbAct_rAirLdAltiCorReq_Tr;
    localfrac_0[1] = localDataTypeConversion1_j;
    localbpIndex_0[0] = localExt_nEng_TrbAct_nEng2_A_9_;
    localbpIndex_0[1] = localTrbAct_rAirLdAltiCorReq__n;
    localInterpolationUsingPrelooku = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(TrbAct_rOpRelTrbActExtReq2_M[0])), 9U);

    /* Switch: '<S249>/Switch1' incorporates:
     *  Constant: '<S249>/ConstVal'
     *  Logic: '<S249>/Logical Operator1'
     *  RelationalOperator: '<S249>/Relational Operator'
     */
    if (!((localTmpSignalConversionAtLsSys) || (localTmpSignalConversionAtTWCMg ==
          1))) {
      localAdd2_n = localInterpolationUsingPrelooku;
    }

    /* DataTypeConversion: '<S258>/OutDTConv' incorporates:
     *  Constant: '<S258>/offset'
     *  Constant: '<S258>/offset1'
     *  Constant: '<S258>/one_on_slope'
     *  Product: '<S258>/Product4'
     *  Sum: '<S258>/Add1'
     *  Sum: '<S258>/Add2'
     */
    localDataTypeConversion1_j = (65536.0F * localAdd2_n) + 0.5F;
    if (localDataTypeConversion1_j < 65536.0F) {
      if (localDataTypeConversion1_j >= 0.0F) {
        localMerge1 = (UInt16)localDataTypeConversion1_j;
      } else {
        localMerge1 = 0U;
      }
    } else {
      localMerge1 = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S11>/F01_posnRelTrbActTWCMgtReq' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtTrbAct_rOpRelTrbActExtReqPrevOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rOpRelTrbActExtReq_INPUT'
   */
  Rte_Read_R_TrbAct_rOpRelTrbActExtReq_TrbAct_rOpRelTrbActExtReq
    (&localTmpSignalConversionAtTrb_c);

  /* Outputs for enable SubSystem: '<S11>/F01_posnRelTrbActTWCMgtReq_Default' incorporates:
   *  EnablePort: '<S250>/Enable'
   *  Logic: '<S11>/Logical Operator2'
   */
  if (!localLogicalOperator3) {
    /* SignalConversion: '<S250>/Signal Conversion1' */
    localMerge1 = localTmpSignalConversionAtTrb_c;
  }

  /* end of Outputs for SubSystem: '<S11>/F01_posnRelTrbActTWCMgtReq_Default' */

  /* Switch: '<S252>/Switch' incorporates:
   *  Constant: '<S252>/Byp_Fonction_SC'
   *  Constant: '<S252>/Int_BypC'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localLogicalOperator3 = TrbAct_bAcvOpRelTrbActExt_B;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtTrbAct_bAcvOpRelTrbActExtInport2' */
  Rte_Write_P_TrbAct_bAcvOpRelTrbActExt_TrbAct_bAcvOpRelTrbActExt
    (localLogicalOperator3);

  /* Switch: '<S251>/Switch' incorporates:
   *  Constant: '<S251>/Byp_Fonction_SC'
   *  Constant: '<S251>/Int_BypC'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localMerge1 = TrbAct_rOpRelTrbActExtReq_B;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtTrbAct_rOpRelTrbActExtReqInport2' */
  Rte_Write_P_TrbAct_rOpRelTrbActExtReq_TrbAct_rOpRelTrbActExtReq(localMerge1);
}

/* Initial conditions for exported function: RE_TrbActSys_003_TEV */
void RE_TrbActSys_003_TEV_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/F02_TrbActAdp'
   *
   * Block requirements for '<S1>/F02_TrbActAdp':
   *  1. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_056.03 ;
   *  2. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_007.02 ;
   *  3. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_006.02 ;
   *  4. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_009.02 ;
   *  5. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_052.01 ;
   *  6. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_053.01 ;
   *  7. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_023.01 ;
   *  8. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_025.01 ;
   *  9. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_026.01 ;
   *  10. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_029.01 ;
   *  11. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_031.02 ;
   *  12. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_032.01 ;
   *  13. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_033.01 ;
   *  14. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_034.02 ;
   *  15. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_035.01 ;
   *  16. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_036.01 ;
   *  17. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_037.01 ;
   *  18. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_038.01 ;
   *  19. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_039.02 ;
   *  20. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_066.01 ;
   *  21. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_070.01 ;
   *  22. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_067.01 ;
   *  23. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_069.01 ;
   *  24. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  25. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_047.02 ;
   *  26. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_048.02 ;
   *  27. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_080.02 ;
   *  28. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_075.02 ;
   *  29. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_076.02 ;
   *  30. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_082.01 ;
   *  31. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_083.01 ;
   *  32. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_084.01 ;
   *  33. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_085.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S9>/F01_cond_adap' *
   * Block requirements for '<S9>/F01_cond_adap':
   *  1. SubSystem "F01_cond_adap" !Trace_To : VEMS_R_10_07018_010.02 ;
   */

  /* InitializeConditions for UnitDelay: '<S162>/Unit Delay' */
  TrbActSys_DWork.UnitDelay_DSTATE = 101300.0F;

  /* InitializeConditions for UnitDelay: '<S163>/Unit Delay' */
  TrbActSys_DWork.UnitDelay_DSTATE_o = 101300.0F;

  /* end of InitializeConditions for SubSystem: '<S9>/F01_cond_adap' */
}

/* Start for exported function: RE_TrbActSys_003_TEV */
void RE_TrbActSys_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_TrbActAdp'
   *
   * Block requirements for '<S1>/F02_TrbActAdp':
   *  1. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_056.03 ;
   *  2. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_007.02 ;
   *  3. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_006.02 ;
   *  4. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_009.02 ;
   *  5. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_052.01 ;
   *  6. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_053.01 ;
   *  7. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_023.01 ;
   *  8. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_025.01 ;
   *  9. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_026.01 ;
   *  10. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_029.01 ;
   *  11. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_031.02 ;
   *  12. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_032.01 ;
   *  13. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_033.01 ;
   *  14. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_034.02 ;
   *  15. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_035.01 ;
   *  16. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_036.01 ;
   *  17. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_037.01 ;
   *  18. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_038.01 ;
   *  19. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_039.02 ;
   *  20. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_066.01 ;
   *  21. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_070.01 ;
   *  22. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_067.01 ;
   *  23. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_069.01 ;
   *  24. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  25. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_047.02 ;
   *  26. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_048.02 ;
   *  27. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_080.02 ;
   *  28. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_075.02 ;
   *  29. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_076.02 ;
   *  30. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_082.01 ;
   *  31. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_083.01 ;
   *  32. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_084.01 ;
   *  33. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_085.01 ;
   */
}

/* Output and update for exported function: RE_TrbActSys_003_TEV */
void RE_TrbActSys_003_TEV(void)
{
  /* local block i/o variables */
  SInt32 localOutDTConv_d;
  UInt16 localLookUpTable_n3;
  UInt16 localDataTypeConversion1_h0;
  SInt16 localOutDTConv_a;
  SInt16 localOutDTConv_k;
  UInt16 localTmpSignalConversionAtExM_t;
  UInt16 localDataTypeConversion_nx;
  UInt16 localOutDTConv_k2;
  UInt16 localLookUpTable_d;
  UInt16 localLookUpTable_j;
  UInt16 localLookUpTable_o;
  UInt16 localLookUpTable_g;
  Boolean localLogicalOperator_g;
  Boolean localAutosarServer;
  SInt32 localpluIdx;
  Boolean localNot;
  Float32 localDataTypeConversion2;
  Float32 localMerge1_m;
  Float32 localInterpolationUsingPrelo_ga;
  Float32 localAdd4_c;
  Boolean localRelationalOperator_e;
  UInt32 localExt_nEng_TrbAct_nEng_A_9_k;
  Float32 localDataTypeConversion2_n;
  Float32 localTrbAct_facPresAltiCor_TrbA;
  UInt32 localTrbAct_facPresAltiCor_Tr_p;
  Boolean localRelationalOperator6;
  Float32 localfrac[2];
  UInt32 localbpIndex[2];
  Boolean localRelationalOperator1_j;
  Boolean localTmpSignalConversionAtTr_lx;
  Boolean localTmpSignalConversionAtExt_b;
  Boolean localTmpSignalConversionAtTrb_a;
  Float32 localAdd3_l;
  UInt16 localTmpSignalConversionAtAir_o;
  UInt16 localTmpSignalConversionAtEx_eb;
  UInt16 localTmpSignalConversionAtUsT_i;
  UInt16 localTmpSignalConversionAtAir_i;
  UInt16 localTmpSignalConversionAtEx_ew;
  UInt16 localTmpSignalConversionAtAir_f;
  UInt16 localTmpSignalConversionAtTrb_k;
  UInt16 localTmpSignalConversionAtTrb_g;
  UInt16 localTmpSignalConversionAtTrb_p;
  UInt16 localTmpSignalConversionAtTr_bc;
  SInt32 localAbs1;
  SInt16 localAbs3;
  SInt16 localAbs2;
  UInt16 locallocalTmpSignalConversionAt;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_TrbActAdp'
   *
   * Block requirements for '<S1>/F02_TrbActAdp':
   *  1. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_056.03 ;
   *  2. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_007.02 ;
   *  3. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_006.02 ;
   *  4. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_009.02 ;
   *  5. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_052.01 ;
   *  6. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_053.01 ;
   *  7. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_023.01 ;
   *  8. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_025.01 ;
   *  9. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_026.01 ;
   *  10. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_029.01 ;
   *  11. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_031.02 ;
   *  12. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_032.01 ;
   *  13. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_033.01 ;
   *  14. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_034.02 ;
   *  15. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_035.01 ;
   *  16. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_036.01 ;
   *  17. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_037.01 ;
   *  18. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_038.01 ;
   *  19. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_039.02 ;
   *  20. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_066.01 ;
   *  21. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_070.01 ;
   *  22. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_067.01 ;
   *  23. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_069.01 ;
   *  24. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  25. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_047.02 ;
   *  26. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_048.02 ;
   *  27. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_080.02 ;
   *  28. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_075.02 ;
   *  29. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_076.02 ;
   *  30. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_082.01 ;
   *  31. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_083.01 ;
   *  32. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_084.01 ;
   *  33. SubSystem "F02_TrbActAdp" !Trace_To : VEMS_R_10_07018_085.01 ;
   */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_bBoostPresClCtlAcvOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bBoostPresClCtlAcv'
   */
  Rte_Read_R_TrbAct_bBoostPresClCtlAcv_TrbAct_bBoostPresClCtlAcv
    (&localTmpSignalConversionAtTrb_a);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_bAcvTrbActAdpPrevOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bAcvTrbActAdp_INPUT'
   */
  Rte_Read_R_TrbAct_bAcvTrbActAdp_TrbAct_bAcvTrbActAdp
    ((&(TrbAct_bAcvTrbActAdpPrev)));

  /* S-Function (sfun_autosar_clientop): '<S139>/AutosarServer' */
  Rte_Call_R_FRM_bInhArAdpTrbAct_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S139>/Not' */
  localNot = !localAutosarServer;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_bInhICorOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bInhICor'
   */
  Rte_Read_R_TrbAct_bInhICor_TrbAct_bInhICor(&localTmpSignalConversionAtTr_lx);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_facPresAltiCorOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_facPresAltiCor'
   */
  Rte_Read_R_TrbAct_facPresAltiCor_TrbAct_facPresAltiCor
    (&TrbActSys_B.TmpSignalConversionAtTrbAct_fac);

  /* DataTypeConversion: '<S9>/Data Type Conversion7' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_pGradUsThrMesCorPrevOutport2'
   */
  TrbAct_pGradUsThrMesCorPrev = ((Float32)
    Rte_IrvRead_RE_TrbActSys_003_TEV_TrbAct_pGradUsThrMesCorFil_irv()) * 8.0F;

  /* DataTypeConversion: '<S9>/Data Type Conversion4' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_pGradUsThrReqPrevOutport2'
   */
  TrbAct_pGradUsThrReqPrev = ((Float32)
    Rte_IrvRead_RE_TrbActSys_003_TEV_TrbAct_pGradUsThrReqFil_irv()) * 8.0F;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&TrbActSys_B.TmpSignalConversionAtExt_nEng_a);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_pUsThrFilOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pUsThrFil'
   */
  Rte_Read_R_TrbAct_pUsThrFil_TrbAct_pUsThrFil(&localTmpSignalConversionAtTrb_p);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_pUsThrReqFilOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsThrReqFil'
   */
  Rte_Read_R_AirSys_pUsThrReqFil_AirSys_pUsThrReqFil
    (&localTmpSignalConversionAtAir_o);

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  localDataTypeConversion2 = ((Float32)localTmpSignalConversionAtAir_o) * 8.0F;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_pUsThrCorReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_pUsThrCorReq'
   */
  Rte_Read_R_TrbAct_pUsThrCorReq_TrbAct_pUsThrCorReq
    (&localTmpSignalConversionAtTr_bc);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExt_bAcvCtlExtOutport2' incorporates:
   *  Inport: '<Root>/Ext_bAcvCtlExt'
   */
  Rte_Read_R_Ext_bAcvCtlExt_Ext_bAcvCtlExt(&localTmpSignalConversionAtExt_b);

  /* Outputs for atomic SubSystem: '<S9>/F01_cond_adap' *
   * Block requirements for '<S9>/F01_cond_adap':
   *  1. SubSystem "F01_cond_adap" !Trace_To : VEMS_R_10_07018_010.02 ;
   */

  /* Sum: '<S134>/Add2' */
  localAbs1 = localTmpSignalConversionAtTrb_p - localTmpSignalConversionAtAir_o;

  /* Abs: '<S134>/Abs1' */
  if (localAbs1 < 0) {
    localAbs1 = -localAbs1;
  }

  /* DataTypeConversion: '<S134>/Data Type Conversion5' incorporates:
   *  Constant: '<S134>/TrbAct_facFilGradUsThrReq_C'
   */
  localInterpolationUsingPrelo_ga = (((Float32)TrbAct_facFilGradUsThrReq_C) *
    1.525878906E-005F) + 1.525878906E-005F;

  /* Saturate: '<S168>/Saturation [0-1]' */
  localAdd3_l = localInterpolationUsingPrelo_ga;

  /* UnitDelay: '<S162>/Unit Delay' */
  localInterpolationUsingPrelo_ga = TrbActSys_DWork.UnitDelay_DSTATE;

  /* Sum: '<S134>/Add4' */
  localAdd4_c = localDataTypeConversion2 - localInterpolationUsingPrelo_ga;

  /* Product: '<S160>/Product4' incorporates:
   *  Constant: '<S160>/offset'
   *  Constant: '<S160>/one_on_slope'
   *  Product: '<S168>/Product'
   *  Sum: '<S160>/Add1'
   *  Sum: '<S168>/Sum'
   *  Sum: '<S168>/Sum1'
   */
  localInterpolationUsingPrelo_ga = (((localAdd4_c - TrbAct_pGradUsThrReqPrev) *
    rt_SATURATE(localAdd3_l, 0.0F, 1.0F)) + TrbAct_pGradUsThrReqPrev) * 0.125F;

  /* Sum: '<S160>/Add3' incorporates:
   *  Constant: '<S160>/offset3'
   */
  localAdd3_l = localInterpolationUsingPrelo_ga + 0.5F;

  /* RelationalOperator: '<S160>/Relational Operator' incorporates:
   *  Constant: '<S160>/offset2'
   */
  localRelationalOperator_e = (localInterpolationUsingPrelo_ga >= 0.0F);

  /* Sum: '<S160>/Add4' incorporates:
   *  Constant: '<S160>/offset4'
   */
  localAdd4_c = localInterpolationUsingPrelo_ga - 0.5F;

  /* Switch: '<S160>/Switch1' */
  if (localRelationalOperator_e) {
    localInterpolationUsingPrelo_ga = localAdd3_l;
  } else {
    localInterpolationUsingPrelo_ga = localAdd4_c;
  }

  /* DataTypeConversion: '<S160>/OutDTConv' */
  localAdd4_c = localInterpolationUsingPrelo_ga;
  if (localAdd4_c < 32768.0F) {
    if (localAdd4_c >= -32768.0F) {
      localOutDTConv_a = (SInt16)localAdd4_c;
    } else {
      localOutDTConv_a = MIN_int16_T;
    }
  } else {
    localOutDTConv_a = MAX_int16_T;
  }

  /* Abs: '<S134>/Abs2' */
  if (localOutDTConv_a < 0) {
    localTrbAct_facPresAltiCor_Tr_p = (UInt32)(-localOutDTConv_a);
    if (localTrbAct_facPresAltiCor_Tr_p > 32767U) {
      localAbs2 = MAX_int16_T;
    } else {
      localAbs2 = (SInt16)localTrbAct_facPresAltiCor_Tr_p;
    }
  } else {
    localAbs2 = localOutDTConv_a;
  }

  /* PreLookup: '<S159>/Prelookup' */
  localExt_nEng_TrbAct_nEng_A_9_k = plook_u32u16f_binc
    (TrbActSys_B.TmpSignalConversionAtExt_nEng_a, (&(TrbAct_nEng_A[0])), 8U,
     &localInterpolationUsingPrelo_ga);

  /* Interpolation_n-D: '<S156>/Interpolation Using Prelookup3' */
  localAdd3_l = localInterpolationUsingPrelo_ga;
  localAdd3_l = intrp1d_iu16n16ff_u32f_l_ns(localExt_nEng_TrbAct_nEng_A_9_k,
    localAdd3_l, (&(TrbAct_facFilGradUsThrMes_T[0])));

  /* DataTypeConversion: '<S134>/Data Type Conversion2' */
  localDataTypeConversion2_n = ((Float32)localTmpSignalConversionAtTrb_p) *
    8.0F;

  /* Product: '<S161>/Product4' incorporates:
   *  Constant: '<S161>/offset'
   *  Constant: '<S161>/one_on_slope'
   *  Product: '<S171>/Product'
   *  Saturate: '<S171>/Saturation [0-1]'
   *  Sum: '<S134>/Add3'
   *  Sum: '<S161>/Add1'
   *  Sum: '<S171>/Sum'
   *  Sum: '<S171>/Sum1'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  localAdd3_l = ((((localDataTypeConversion2_n -
                    TrbActSys_DWork.UnitDelay_DSTATE_o) -
                   TrbAct_pGradUsThrMesCorPrev) * rt_SATURATE(localAdd3_l, 0.0F,
    1.0F)) + TrbAct_pGradUsThrMesCorPrev) * 0.125F;

  /* Switch: '<S161>/Switch1' incorporates:
   *  Constant: '<S161>/offset2'
   *  Constant: '<S161>/offset3'
   *  Constant: '<S161>/offset4'
   *  RelationalOperator: '<S161>/Relational Operator'
   *  Sum: '<S161>/Add3'
   *  Sum: '<S161>/Add4'
   */
  if (localAdd3_l >= 0.0F) {
    localAdd3_l += 0.5F;
  } else {
    localAdd3_l -= 0.5F;
  }

  /* DataTypeConversion: '<S161>/OutDTConv' */
  if (localAdd3_l < 32768.0F) {
    if (localAdd3_l >= -32768.0F) {
      localOutDTConv_k = (SInt16)localAdd3_l;
    } else {
      localOutDTConv_k = MIN_int16_T;
    }
  } else {
    localOutDTConv_k = MAX_int16_T;
  }

  /* Abs: '<S134>/Abs3' */
  if (localOutDTConv_k < 0) {
    localTrbAct_facPresAltiCor_Tr_p = (UInt32)(-localOutDTConv_k);
    if (localTrbAct_facPresAltiCor_Tr_p > 32767U) {
      localAbs3 = MAX_int16_T;
    } else {
      localAbs3 = (SInt16)localTrbAct_facPresAltiCor_Tr_p;
    }
  } else {
    localAbs3 = localOutDTConv_k;
  }

  /* Sum: '<S134>/Add1' */
  localpluIdx = localTmpSignalConversionAtTr_bc -
    localTmpSignalConversionAtAir_o;

  /* Abs: '<S134>/Abs5' */
  if (localpluIdx < 0) {
    localpluIdx = -localpluIdx;
  }

  /* DataTypeConversion: '<S134>/Data Type Conversion1' */
  localAdd3_l = (Float32)TrbActSys_B.TmpSignalConversionAtExt_nEng_a;

  /* DataTypeConversion: '<S134>/Data Type Conversion7' */
  if (localpluIdx <= 0) {
    locallocalTmpSignalConversionAt = 0U;
  } else if (localpluIdx > 65535) {
    locallocalTmpSignalConversionAt = MAX_uint16_T;
  } else {
    locallocalTmpSignalConversionAt = (UInt16)localpluIdx;
  }

  /* RelationalOperator: '<S134>/Relational Operator2' incorporates:
   *  Constant: '<S134>/TrbAct_pDeltaUsThrThd1_C'
   *  DataTypeConversion: '<S134>/Data Type Conversion3'
   */
  if (localAbs1 <= 0) {
    localTmpSignalConversionAtTrb_p = 0U;
  } else if (localAbs1 > 65535) {
    localTmpSignalConversionAtTrb_p = MAX_uint16_T;
  } else {
    localTmpSignalConversionAtTrb_p = (UInt16)localAbs1;
  }

  localRelationalOperator_e = (localTmpSignalConversionAtTrb_p <
    TrbAct_pDeltaUsThrThd1_C);

  /* PreLookup: '<S158>/Prelookup' */
  localTrbAct_facPresAltiCor_Tr_p = plook_u32u16f_binc
    (TrbActSys_B.TmpSignalConversionAtTrbAct_fac, (&(TrbAct_facPresAltiCor_A[0])),
     8U, &localTrbAct_facPresAltiCor_TrbA);

  /* Interpolation_n-D: '<S155>/Interpolation Using Prelookup3' */
  localAdd4_c = localTrbAct_facPresAltiCor_TrbA;
  localAdd4_c = intrp1d_iu16ff_u32f_l_s(localTrbAct_facPresAltiCor_Tr_p,
    localAdd4_c, (&(TrbAct_nThdAdp_T[0])));

  /* RelationalOperator: '<S134>/Relational Operator6' */
  localRelationalOperator6 = (localAdd3_l > localAdd4_c);

  /* Interpolation_n-D: '<S157>/Interpolation Using Prelookup3' */
  localAdd4_c = localInterpolationUsingPrelo_ga;
  localfrac[0] = localAdd4_c;
  localAdd4_c = localTrbAct_facPresAltiCor_TrbA;
  localfrac[1] = localAdd4_c;
  localbpIndex[0] = localExt_nEng_TrbAct_nEng_A_9_k;
  localbpIndex[1] = localTrbAct_facPresAltiCor_Tr_p;
  localInterpolationUsingPrelo_ga = intrp2d_iu16p3ff_u32f_l_s(localbpIndex,
    localfrac, (&(TrbAct_pThdAdp_M[0])), 9U);

  /* RelationalOperator: '<S134>/Relational Operator1' */
  localRelationalOperator1_j = (localDataTypeConversion2_n <=
    localInterpolationUsingPrelo_ga);

  /* Logic: '<S134>/Logical Operator2' incorporates:
   *  Constant: '<S134>/TrbAct_bInhAdpTrbAct_C'
   *  Constant: '<S134>/TrbAct_bInhCtlExt_C'
   *  Constant: '<S134>/TrbAct_bInhHiThd_C'
   *  Constant: '<S134>/TrbAct_bInhPresThd_C'
   *  Constant: '<S134>/TrbAct_bInhTrbActAdpPrev_C'
   *  Constant: '<S134>/TrbAct_pDeltaUsThrHiThd_C'
   *  Constant: '<S134>/TrbAct_pDeltaUsThrLoThd_C'
   *  Constant: '<S134>/TrbAct_pDeltaUsThrThd2_C'
   *  Constant: '<S134>/TrbAct_pDeltaUsThrThd3_C'
   *  DataTypeConversion: '<S134>/Data Type Conversion4'
   *  DataTypeConversion: '<S134>/Data Type Conversion6'
   *  Logic: '<S134>/Logical Operator'
   *  Logic: '<S134>/Logical Operator1'
   *  Logic: '<S134>/Logical Operator10'
   *  Logic: '<S134>/Logical Operator11'
   *  Logic: '<S134>/Logical Operator3'
   *  Logic: '<S134>/Logical Operator4'
   *  Logic: '<S134>/Logical Operator5'
   *  Logic: '<S134>/Logical Operator6'
   *  Logic: '<S134>/Logical Operator7'
   *  Logic: '<S134>/Logical Operator8'
   *  Logic: '<S134>/Logical Operator9'
   *  RelationalOperator: '<S134>/Relational Operator3'
   *  RelationalOperator: '<S134>/Relational Operator4'
   *  RelationalOperator: '<S134>/Relational Operator5'
   *  RelationalOperator: '<S134>/Relational Operator7'
   */
  if (localAbs3 <= 0) {
    localTmpSignalConversionAtTrb_p = 0U;
  } else {
    localTmpSignalConversionAtTrb_p = (UInt16)localAbs3;
  }

  if (localAbs2 <= 0) {
    localTmpSignalConversionAtAir_o = 0U;
  } else {
    localTmpSignalConversionAtAir_o = (UInt16)localAbs2;
  }

  TrbAct_bAdpCdn_MP = ((((((((((((localRelationalOperator_e) &&
    ((localRelationalOperator6) || (((!localRelationalOperator6) &&
    (localRelationalOperator1_j)) && TrbAct_bInhPresThd_C))) &&
    (localTmpSignalConversionAtTrb_p < TrbAct_pDeltaUsThrThd2_C)) &&
    (localTmpSignalConversionAtAir_o < TrbAct_pDeltaUsThrThd3_C)) &&
    (locallocalTmpSignalConversionAt < TrbAct_pDeltaUsThrLoThd_C)) &&
    ((locallocalTmpSignalConversionAt > TrbAct_pDeltaUsThrHiThd_C) ||
     TrbAct_bInhHiThd_C)) && (localTmpSignalConversionAtTrb_a)) &&
    (!localTmpSignalConversionAtTr_lx)) && ((!TrbAct_bAcvTrbActAdpPrev) ||
    TrbAct_bInhTrbActAdpPrev_C)) && ((localTmpSignalConversionAtExt_b) ||
    TrbAct_bInhCtlExt_C)) && (!localNot)) && (!TrbAct_bInhAdpTrbAct_C));

  /* S-Function (fcncallgen): '<S152>/Function-Call Generator' incorporates:
   *  SubSystem: '<S152>/Subsystem'
   */

  /* Sum: '<S164>/Add1' incorporates:
   *  Constant: '<S134>/TrbAct_tiSampleFast_SC'
   *  Inport: '<S164>/Timer_prev'
   */
  localAbs1 = TrbActSys_B.MinMax - ((SInt32)((((UInt32)TrbAct_tiSampleFast_SC)
    * 53687U) >> 13U));
  if (localAbs1 <= 0) {
    localTmpSignalConversionAtTrb_p = 0U;
  } else if (localAbs1 > 65535) {
    localTmpSignalConversionAtTrb_p = MAX_uint16_T;
  } else {
    localTmpSignalConversionAtTrb_p = (UInt16)localAbs1;
  }

  /* Switch: '<S164>/Switch' incorporates:
   *  Constant: '<S134>/TrbAct_tiDlyArAdp_C'
   *  Logic: '<S165>/Logical Operator4'
   *  Logic: '<S165>/Logical Operator7'
   *  UnitDelay: '<S165>/Unit Delay1'
   */
  if (TrbAct_bAdpCdn_MP && (!TrbActSys_DWork.UnitDelay1_DSTATE)) {
    localTmpSignalConversionAtTrb_p = TrbAct_tiDlyArAdp_C;
  }

  /* MinMax: '<S164>/MinMax' incorporates:
   *  Constant: '<S164>/Constant'
   */
  localAbs1 = mul_s32_s32_s32_sr32_sat((SInt32)((UInt32)
    (localTmpSignalConversionAtTrb_p * 5)), 858993459);
  if (localAbs1 <= 0) {
    TrbActSys_B.MinMax = 0U;
  } else if (localAbs1 > 65535) {
    TrbActSys_B.MinMax = MAX_uint16_T;
  } else {
    TrbActSys_B.MinMax = (UInt16)localAbs1;
  }

  /* Logic: '<S164>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S164>/Relational Operator'
   */
  localRelationalOperator_e = ((TrbActSys_B.MinMax <= 0) && TrbAct_bAdpCdn_MP);

  /* Update for UnitDelay: '<S165>/Unit Delay1' */
  TrbActSys_DWork.UnitDelay1_DSTATE = TrbAct_bAdpCdn_MP;

  /* Update for UnitDelay: '<S162>/Unit Delay' */
  TrbActSys_DWork.UnitDelay_DSTATE = localDataTypeConversion2;

  /* Update for UnitDelay: '<S163>/Unit Delay' */
  TrbActSys_DWork.UnitDelay_DSTATE_o = localDataTypeConversion2_n;

  /* end of Outputs for SubSystem: '<S9>/F01_cond_adap' */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_arTrbActReq_irvOutport2' */
  TrbActSys_B.TmpSignalConversionAtTrbAct_arT =
    Rte_IrvRead_RE_TrbActSys_003_TEV_TrbAct_arTrbActReq_irv();

  /* DataTypeConversion: '<S9>/Data Type Conversion20' */
  localAdd4_c = ((Float32)TrbActSys_B.TmpSignalConversionAtTrbAct_arT) *
    9.536743164E-007F;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_rPresTrbEstimIvsOutport2' incorporates:
   *  Inport: '<Root>/ExM_rPresTrbEstimIvs'
   */
  Rte_Read_R_ExM_rPresTrbEstimIvs_ExM_rPresTrbEstimIvs
    (&TrbActSys_B.TmpSignalConversionAtExM_rPresT);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_pExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_pExMnfEstim'
   */
  Rte_Read_R_ExM_pExMnfEstim_ExM_pExMnfEstim(&localTmpSignalConversionAtEx_eb);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_tExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExMnfEstim'
   */
  Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim(&localTmpSignalConversionAtExM_t);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtUsThrM_tUsCmprOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tUsCmpr'
   */
  Rte_Read_R_UsThrM_tUsCmpr_UsThrM_tUsCmpr(&localTmpSignalConversionAtUsT_i);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_mfAirThrReqFilOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mfAirThrReqFil'
   */
  Rte_Read_R_AirSys_mfAirThrReqFil_AirSys_mfAirThrReqFil
    (&localTmpSignalConversionAtAir_i);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtExM_mfEgTotOutport2' incorporates:
   *  Inport: '<Root>/ExM_mfEgTot'
   */
  Rte_Read_R_ExM_mfEgTot_ExM_mfEgTot(&localTmpSignalConversionAtEx_ew);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_pUsCmprReqFilOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsCmprReqFil'
   */
  Rte_Read_R_AirSys_pUsCmprReqFil_AirSys_pUsCmprReqFil
    (&localTmpSignalConversionAtAir_f);

  /* Outputs for enable SubSystem: '<S9>/F02_calc_section' incorporates:
   *  EnablePort: '<S135>/TrbAct_bAcvTrbActAdp'
   *
   * Block requirements for '<S9>/F02_calc_section':
   *  1. SubSystem "F02_calc_section" !Trace_To : VEMS_R_10_07018_011.02 ;
   */
  if (localRelationalOperator_e) {
    /* DataTypeConversion: '<S135>/Data Type Conversion1' */
    localAdd3_l = (((Float32)localTmpSignalConversionAtExM_t) * 0.03125F) +
      223.0F;

    /* Outputs for atomic SubSystem: '<S135>/F01_CalcInter1' *
     * Block requirements for '<S135>/F01_CalcInter1':
     *  1. SubSystem "F01_CalcInter1" !Trace_To : VEMS_R_10_07018_012.01 ;
     */

    /* DataTypeConversion: '<S176>/Data Type Conversion' */
    localDataTypeConversion_nx = TrbActSys_B.TmpSignalConversionAtExM_rPresT;

    /* Lookup: '<S176>/Look-Up Table'
     * About '<S176>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-13
     * Output0 Data Type:  Fixed Point    U16  2^-15  Bias -9.9996948242187500E-001
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_d), (&(TrbAct_facPresTrb_T[0])),
                   localDataTypeConversion_nx, (&(TrbAct_rPresTrb_A[0])), 20U);

    /* DataTypeDuplicate Block: '<S176>/Data Type Duplicate1'
     *
     * Regarding '<S176>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S175>/Divide' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion15'
     *  DataTypeConversion: '<S9>/Data Type Conversion16'
     *  DataTypeConversion: '<S9>/Data Type Conversion21'
     *  DataTypeConversion: '<S9>/Data Type Conversion22'
     *  Product: '<S177>/Divide'
     *  Product: '<S178>/Divide'
     *  Product: '<S179>/Divide'
     *  Product: '<S180>/Divide'
     *  SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_effCmpr_irvOutport2'
     *  SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_effTrb_irvOutport2'
     */
    localAdd3_l = ((((Float32)(((Float32d)(((Float32)
      Rte_IrvRead_RE_TrbActSys_003_TEV_TrbAct_effTrb_irv()) * 1.525878906E-005F))
      * (ACTEMS_LdexpF((Float32d)localLookUpTable_d, -15) -
         9.9996948242187500E-001F))) * (((Float32)
      Rte_IrvRead_RE_TrbActSys_003_TEV_TrbAct_effCmpr_irv()) * 1.525878906E-005F))
                   * localAdd3_l) / (((((Float32)
      localTmpSignalConversionAtUsT_i) * 0.0078125F) + 223.0F) * (((Float32)
      localTmpSignalConversionAtAir_i) * 1.525878906E-005F));

    /* Outputs for atomic SubSystem: '<S175>/If Action Subsystem3' */

    /* Switch: '<S182>/Switch1' incorporates:
     *  Constant: '<S182>/Constant1'
     *  Constant: '<S182>/Constant2'
     *  Constant: '<S182>/Constant3'
     *  Logic: '<S182>/Logical Operator1'
     *  RelationalOperator: '<S182>/Relational Operator'
     *  RelationalOperator: '<S182>/Relational Operator1'
     *  RelationalOperator: '<S182>/Relational Operator3'
     */
    if (((localAdd3_l != localAdd3_l) || (localAdd3_l > 3.000000005E+038F)) || (
         -3.000000005E+038F > localAdd3_l)) {
      TrbAct_facArTrbAct2 = 0.0F;
    } else {
      TrbAct_facArTrbAct2 = localAdd3_l;
    }

    /* end of Outputs for SubSystem: '<S175>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S135>/F01_CalcInter1' */

    /* Outputs for atomic SubSystem: '<S135>/F02_CalcInter2' *
     * Block requirements for '<S135>/F02_CalcInter2':
     *  1. SubSystem "F02_CalcInter2" !Trace_To : VEMS_R_10_07018_013.01 ;
     */

    /* DataTypeConversion: '<S173>/Data Type Conversion1' */
    if (TrbActSys_B.TmpSignalConversionAtExM_rPresT > 8191) {
      localDataTypeConversion1_h0 = MAX_uint16_T;
    } else {
      localDataTypeConversion1_h0 = (UInt16)
        (TrbActSys_B.TmpSignalConversionAtExM_rPresT << 3);
    }

    /* Lookup: '<S184>/Look-Up Table'
     * About '<S184>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U16  2^-20  Bias 9.5367E-007
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_j), (&(TrbAct_facCfeTrb_T[0])),
                   localDataTypeConversion1_h0, (&(TrbAct_rPresCfeTrbAct_A[0])),
                   18U);

    /* DataTypeDuplicate Block: '<S184>/Data Type Duplicate1'
     *
     * Regarding '<S184>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S186>/Divide' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion13'
     */
    localAdd3_l = (Float32)((((Float32d)localTmpSignalConversionAtEx_eb) * 8.0F) *
                             (ACTEMS_LdexpF((Float32d)localLookUpTable_j, -20) +
      9.5367E-007F));

    /* Lookup: '<S185>/Look-Up Table'
     * About '<S185>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-5  Bias 223.0
     * Output0 Data Type:  Fixed Point    U16  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_o), (&(TrbAct_facTUsTrb_T[0])),
                   localTmpSignalConversionAtExM_t, (&(TrbAct_tUsTrbAdp_A[0])),
                   8U);

    /* DataTypeDuplicate Block: '<S185>/Data Type Duplicate1'
     *
     * Regarding '<S185>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S183>/Divide' incorporates:
     *  DataTypeConversion: '<S173>/Data Type Conversion20'
     *  Lookup: '<S185>/Look-Up Table'
     */
    localAdd3_l /= ((Float32)localLookUpTable_o) * 0.00390625F;

    /* Outputs for atomic SubSystem: '<S183>/If Action Subsystem3' */

    /* Switch: '<S189>/Switch1' incorporates:
     *  Constant: '<S189>/Constant1'
     *  Constant: '<S189>/Constant2'
     *  Constant: '<S189>/Constant3'
     *  Logic: '<S189>/Logical Operator1'
     *  RelationalOperator: '<S189>/Relational Operator'
     *  RelationalOperator: '<S189>/Relational Operator1'
     *  RelationalOperator: '<S189>/Relational Operator3'
     */
    if (((localAdd3_l != localAdd3_l) || (localAdd3_l > 3.000000005E+038F)) || (
         -3.000000005E+038F > localAdd3_l)) {
      TrbAct_facArTrbAct1 = 0.0F;
    } else {
      TrbAct_facArTrbAct1 = localAdd3_l;
    }

    /* end of Outputs for SubSystem: '<S183>/If Action Subsystem3' */

    /* Sum: '<S173>/Add' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion17'
     *  Product: '<S187>/Divide'
     */
    TrbAct_mfTrbEstim = (((Float32)localTmpSignalConversionAtEx_ew) *
                         1.525878906E-005F) - (localAdd4_c * TrbAct_facArTrbAct1);

    /* SignalConversion: '<S173>/Signal Conversion2' */
    TrbActSys_B.Merge4 = localAdd4_c;

    /* end of Outputs for SubSystem: '<S135>/F02_CalcInter2' */

    /* Outputs for atomic SubSystem: '<S135>/F03_calcul_deltaS' *
     * Block requirements for '<S135>/F03_calcul_deltaS':
     *  1. SubSystem "F03_calcul_deltaS" !Trace_To : VEMS_R_10_07018_014.01 ;
     */

    /* DataTypeConversion: '<S190>/OutDTConv' incorporates:
     *  Constant: '<S174>/ConstVal_1'
     *  Constant: '<S190>/offset'
     *  Constant: '<S190>/offset1'
     *  Constant: '<S190>/one_on_slope'
     *  Product: '<S190>/Product4'
     *  Product: '<S200>/Divide'
     *  Sum: '<S174>/Add1'
     *  Sum: '<S190>/Add1'
     *  Sum: '<S190>/Add2'
     */
    localAdd4_c = ((((TrbAct_facArTrbAct2 * TrbAct_mfTrbEstim) + 1.0F) - 0.5F) *
                   32768.0F) + 0.5F;
    if (localAdd4_c < 65536.0F) {
      if (localAdd4_c >= 0.0F) {
        TrbAct_facAdp_MP = (UInt16)localAdd4_c;
      } else {
        TrbAct_facAdp_MP = 0U;
      }
    } else {
      TrbAct_facAdp_MP = MAX_uint16_T;
    }

    /* Lookup: '<S195>/Look-Up Table'
     * About '<S195>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-15  Bias 0.5
     * Output0 Data Type:  Fixed Point    U16  2^-13  Bias 0.0001220703125
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_g), (&(TrbAct_facAdp_T[0])),
                   TrbAct_facAdp_MP, (&(TrbAct_facAdp_A[0])), 11U);

    /* DataTypeDuplicate Block: '<S195>/Data Type Duplicate1'
     *
     * Regarding '<S195>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S193>/Divide' incorporates:
     *  Constant: '<S174>/ConstVal'
     *  Product: '<S199>/Divide'
     */
    localAdd4_c = 1.0F / (TrbAct_facArTrbAct2 * TrbAct_facArTrbAct1);

    /* Outputs for atomic SubSystem: '<S193>/If Action Subsystem3' */

    /* Switch: '<S205>/Switch1' incorporates:
     *  Constant: '<S205>/Constant1'
     *  Constant: '<S205>/Constant2'
     *  Constant: '<S205>/Constant3'
     *  Logic: '<S205>/Logical Operator1'
     *  RelationalOperator: '<S205>/Relational Operator'
     *  RelationalOperator: '<S205>/Relational Operator1'
     *  RelationalOperator: '<S205>/Relational Operator3'
     */
    if (((localAdd4_c != localAdd4_c) || (localAdd4_c > 3.000000005E+038F)) || (
         -3.000000005E+038F > localAdd4_c)) {
      localAdd4_c = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S193>/If Action Subsystem3' */

    /* Product: '<S192>/Divide' incorporates:
     *  Constant: '<S174>/TrbAct_facEgTrb_SC'
     *  DataTypeConversion: '<S174>/Data Type Conversion5'
     *  DataTypeConversion: '<S9>/Data Type Conversion18'
     *  Product: '<S196>/Divide'
     *  Sum: '<S174>/Add1 1'
     */
    localAdd3_l = ((Float32)((((Float32d)localDataTypeConversion2) - (((Float32d)
      localTmpSignalConversionAtTr_bc) * 8.0F)) * (((Float32d)TrbAct_facEgTrb_SC) *
      0.001F))) / (((Float32)localTmpSignalConversionAtAir_f) * 8.0F);

    /* Outputs for atomic SubSystem: '<S192>/If Action Subsystem3' */

    /* Switch: '<S203>/Switch1' incorporates:
     *  Constant: '<S203>/Constant1'
     *  Constant: '<S203>/Constant2'
     *  Constant: '<S203>/Constant3'
     *  Logic: '<S203>/Logical Operator1'
     *  RelationalOperator: '<S203>/Relational Operator'
     *  RelationalOperator: '<S203>/Relational Operator1'
     *  RelationalOperator: '<S203>/Relational Operator3'
     */
    if (((localAdd3_l != localAdd3_l) || (localAdd3_l > 3.000000005E+038F)) || (
         -3.000000005E+038F > localAdd3_l)) {
      localAdd3_l = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S192>/If Action Subsystem3' */

    /* Product: '<S197>/Divide' incorporates:
     *  DataTypeConversion: '<S174>/Data Type Conversion1'
     *  Lookup: '<S195>/Look-Up Table'
     *  Product: '<S198>/Divide'
     */
    localAdd3_l *= ((((Float32)localLookUpTable_g) * 0.0001220703125F) +
                    0.0001220703125F) * localAdd4_c;

    /* DataTypeConversion: '<S191>/OutDTConv' incorporates:
     *  Constant: '<S191>/offset'
     *  Constant: '<S191>/offset1'
     *  Constant: '<S191>/one_on_slope'
     *  Product: '<S191>/Product4'
     *  Sum: '<S191>/Add1'
     *  Sum: '<S191>/Add2'
     */
    localAdd4_c = (1.048576E+006F * localAdd3_l) + 0.5F;
    if (localAdd4_c < 65536.0F) {
      if (localAdd4_c >= 0.0F) {
        localOutDTConv_k2 = (UInt16)localAdd4_c;
      } else {
        localOutDTConv_k2 = 0U;
      }
    } else {
      localOutDTConv_k2 = MAX_uint16_T;
    }

    /* Lookup: '<S194>/Look-Up Table'
     * About '<S194>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-20
     * Output0 Data Type:  Fixed Point    U16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_n3), (&(TrbAct_facAdpTrbActDeltaCor_T[0])),
                   localOutDTConv_k2, (&(TrbAct_arTrbActAdpDeltaCor_A[0])), 3U);

    /* DataTypeDuplicate Block: '<S194>/Data Type Duplicate1'
     *
     * Regarding '<S194>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S135>/F03_calcul_deltaS' */

    /* SignalConversion: '<S135>/Signal Conversion' incorporates:
     *  Product: '<S201>/Divide'
     */
    localMerge1_m = (((Float32)localLookUpTable_n3) * 1.525878906E-005F) *
      localAdd3_l;
  }

  /* end of Outputs for SubSystem: '<S9>/F02_calc_section' */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_arTrbActAdpPrevOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_arTrbActAdp_INPUT'
   */
  Rte_Read_R_TrbAct_arTrbActAdp_TrbAct_arTrbActAdp
    (&localTmpSignalConversionAtTrb_k);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_arTrbActFrzSpPrevOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_arTrbActFrzSp_INPUT'
   */
  Rte_Read_R_TrbAct_arTrbActFrzSp_TrbAct_arTrbActFrzSp
    (&localTmpSignalConversionAtTrb_g);

  /* Outputs for enable SubSystem: '<S9>/F02_calc_section_default' incorporates:
   *  EnablePort: '<S136>/TrbAct_bAcvTrbActAdp'
   *  Logic: '<S9>/Logical Operator'
   */
  if (!localRelationalOperator_e) {
    /* SignalConversion: '<S136>/Signal Conversion1' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion1'
     */
    localMerge1_m = ((Float32)localTmpSignalConversionAtTrb_k) *
      9.536743164E-007F;

    /* SignalConversion: '<S136>/Signal Conversion2' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion24'
     */
    TrbActSys_B.Merge4 = ((Float32)localTmpSignalConversionAtTrb_g) *
      9.536743164E-007F;
  }

  /* end of Outputs for SubSystem: '<S9>/F02_calc_section_default' */

  /* DataTypeConversion: '<S9>/Data Type Conversion19' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_facAdpArErrFil_irvOutport2'
   */
  TrbAct_facAdpArErrFilPrev = ((Float32)
    Rte_IrvRead_RE_TrbActSys_003_TEV_TrbAct_facAdpArTrbActErrFil_irv()) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S9>/Data Type Conversion3' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_facAdpArTrbActErrPrevOutport2'
   */
  TrbAct_facAdpArTrbActErrPrev = ((Float32)
    Rte_IrvRead_RE_TrbActSys_003_TEV_TrbAct_facAdpArTrbActErr_irv()) *
    1.525878906E-005F;

  /* Outputs for atomic SubSystem: '<S9>/F03_calc_rel_section' *
   * Block requirements for '<S9>/F03_calc_rel_section':
   *  1. SubSystem "F03_calc_rel_section" !Trace_To : VEMS_R_10_07018_058.01 ;
   */

  /* Product: '<S208>/Divide' */
  localAdd4_c = localMerge1_m / TrbActSys_B.Merge4;

  /* Outputs for atomic SubSystem: '<S208>/If Action Subsystem3' */

  /* Switch: '<S216>/Switch1' incorporates:
   *  Constant: '<S216>/Constant1'
   *  Constant: '<S216>/Constant2'
   *  Constant: '<S216>/Constant3'
   *  Logic: '<S216>/Logical Operator1'
   *  RelationalOperator: '<S216>/Relational Operator'
   *  RelationalOperator: '<S216>/Relational Operator1'
   *  RelationalOperator: '<S216>/Relational Operator3'
   */
  if (((localAdd4_c != localAdd4_c) || (localAdd4_c > 3.000000005E+038F)) ||
      (-3.000000005E+038F > localAdd4_c)) {
    localAdd4_c = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S208>/If Action Subsystem3' */

  /* DataTypeConversion: '<S209>/Conversion' incorporates:
   *  Constant: '<S137>/TrbAct_facAdpArTrbActErrMax_C'
   */
  localAdd3_l = ((Float32)TrbAct_facAdpArTrbActErrMax_C) * 1.525878906E-005F;

  /* DataTypeConversion: '<S210>/Conversion' incorporates:
   *  Constant: '<S137>/TrbAct_facAdpArTrbActErrMin_C'
   */
  localDataTypeConversion2_n = ((Float32)TrbAct_facAdpArTrbActErrMin_C) *
    1.525878906E-005F;

  /* Switch: '<S137>/Switch' incorporates:
   *  Sum: '<S137>/Add3'
   */
  if (localRelationalOperator_e) {
    localAdd4_c += TrbAct_facAdpArTrbActErrPrev;
  } else {
    localAdd4_c = TrbAct_facAdpArTrbActErrPrev;
  }

  /* Switch: '<S211>/Switch' incorporates:
   *  RelationalOperator: '<S211>/UpperRelop'
   */
  if (!(localAdd4_c < localDataTypeConversion2_n)) {
    localDataTypeConversion2_n = localAdd4_c;
  }

  /* Switch: '<S211>/Switch2' incorporates:
   *  RelationalOperator: '<S211>/LowerRelop1'
   */
  if (localAdd4_c > localAdd3_l) {
    localDataTypeConversion2_n = localAdd3_l;
  }

  /* Sum: '<S214>/Sum1' incorporates:
   *  Constant: '<S137>/TrbAct_facArAdpGain_C'
   *  Product: '<S214>/Product'
   *  Sum: '<S214>/Sum'
   */
  localAdd4_c = ((((Float32)TrbAct_facArAdpGain_C) * 1.525878906E-005F) *
                 (localDataTypeConversion2_n - TrbAct_facAdpArErrFilPrev)) +
    TrbAct_facAdpArErrFilPrev;

  /* end of Outputs for SubSystem: '<S9>/F03_calc_rel_section' */

  /* Product: '<S141>/Product4' incorporates:
   *  Constant: '<S141>/offset'
   *  Constant: '<S141>/one_on_slope'
   *  Sum: '<S141>/Add1'
   */
  localAdd3_l = 65536.0F * localDataTypeConversion2_n;

  /* Switch: '<S141>/Switch1' incorporates:
   *  Constant: '<S141>/offset2'
   *  Constant: '<S141>/offset3'
   *  Constant: '<S141>/offset4'
   *  RelationalOperator: '<S141>/Relational Operator'
   *  Sum: '<S141>/Add3'
   *  Sum: '<S141>/Add4'
   */
  if (localAdd3_l >= 0.0F) {
    localAdd3_l += 0.5F;
  } else {
    localAdd3_l -= 0.5F;
  }

  /* DataTypeConversion: '<S141>/OutDTConv' */
  if (localAdd3_l < 2.147483648E+009F) {
    if (localAdd3_l >= -2.147483648E+009F) {
      TrbActSys_B.OutDTConv = (SInt32)localAdd3_l;
    } else {
      TrbActSys_B.OutDTConv = MIN_int32_T;
    }
  } else {
    TrbActSys_B.OutDTConv = MAX_int32_T;
  }

  /* S-Function (NvRamWriteAccess): '<S9>/EepromWriteAccess' */
  TrbActSys_sNV_Z1_CONST_32BIT.TrbAct_facAdpArTrbActErr_NV =
    TrbActSys_B.OutDTConv;

  /* Outputs for atomic SubSystem: '<S9>/F04_diag' *
   * Block requirements for '<S9>/F04_diag':
   *  1. SubSystem "F04_diag" !Trace_To : VEMS_R_10_07018_059.01 ;
   */

  /* Logic: '<S138>/Logical Operator' incorporates:
   *  Constant: '<S138>/TrbAct_facAdpArTrbActErrMax_C'
   *  Constant: '<S138>/TrbAct_facAdpArTrbActErrMin_C'
   *  RelationalOperator: '<S138>/Relational Operator'
   *  RelationalOperator: '<S138>/Relational Operator1'
   */
  localLogicalOperator_g = ((TrbActSys_B.OutDTConv <=
    TrbAct_facAdpArTrbActErrMin_C) || (TrbActSys_B.OutDTConv >=
    TrbAct_facAdpArTrbActErrMax_C));

  /* end of Outputs for SubSystem: '<S9>/F04_diag' */

  /* If: '<S140>/If' incorporates:
   *  ActionPort: '<S217>/Action Port'
   *  Constant: '<S9>/TRBACTSYS_ACTIVE_BYP_C'
   *  SubSystem: '<S140>/if_s'
   */
  if (!TRBACTSYS_ACTIVE_BYP_C) {
    TrbActSys_if_s(TRUE, localLogicalOperator_g, &TrbActSys_DWork.if_s_g);
  }

  /* Product: '<S144>/Product4' incorporates:
   *  Constant: '<S144>/offset'
   *  Constant: '<S144>/one_on_slope'
   *  Sum: '<S144>/Add1'
   */
  localAdd3_l = 65536.0F * localAdd4_c;

  /* Switch: '<S144>/Switch1' incorporates:
   *  Constant: '<S144>/offset2'
   *  Constant: '<S144>/offset3'
   *  Constant: '<S144>/offset4'
   *  RelationalOperator: '<S144>/Relational Operator'
   *  Sum: '<S144>/Add3'
   *  Sum: '<S144>/Add4'
   */
  if (localAdd3_l >= 0.0F) {
    localAdd3_l += 0.5F;
  } else {
    localAdd3_l -= 0.5F;
  }

  /* DataTypeConversion: '<S144>/OutDTConv' */
  if (localAdd3_l < 2.147483648E+009F) {
    if (localAdd3_l >= -2.147483648E+009F) {
      localOutDTConv_d = (SInt32)localAdd3_l;
    } else {
      localOutDTConv_d = MIN_int32_T;
    }
  } else {
    localOutDTConv_d = MAX_int32_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S145>/autosar_testpoint1' */

  /* S-Function Block: <S145>/autosar_testpoint1 */
  TrbAct_facAdpArTrbActErrFil = localOutDTConv_d;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S146>/autosar_testpoint1' */

  /* S-Function Block: <S146>/autosar_testpoint1 */
  TrbAct_pGradUsThrReqFil_IRV_MP = localOutDTConv_a;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S147>/autosar_testpoint1' */

  /* S-Function Block: <S147>/autosar_testpoint1 */
  TrbAct_pGradUsThrMesCorFil = localOutDTConv_k;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S148>/autosar_testpoint1' */

  /* S-Function Block: <S148>/autosar_testpoint1 */
  TrbAct_facAdpArTrbActErr_IRV_MP = TrbActSys_B.OutDTConv;

  /* SignalConversion: '<S9>/Signal Conversion1' */
  localpluIdx = TrbActSys_B.OutDTConv;

  /* SignalConversion: '<S9>/Signal Conversion2' */
  localAbs2 = localOutDTConv_a;

  /* SignalConversion: '<S9>/Signal Conversion4' */
  localAbs3 = localOutDTConv_k;

  /* SignalConversion: '<S9>/Signal Conversion9' */
  localAbs1 = localOutDTConv_d;

  /* Sum: '<S143>/Add2' incorporates:
   *  Constant: '<S143>/offset'
   *  Constant: '<S143>/offset1'
   *  Constant: '<S143>/one_on_slope'
   *  Product: '<S143>/Product4'
   *  Sum: '<S143>/Add1'
   */
  localAdd3_l = (1.048576E+006F * TrbActSys_B.Merge4) + 0.5F;

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S142>/offset'
   *  Constant: '<S142>/offset1'
   *  Constant: '<S142>/one_on_slope'
   *  Constant: '<S151>/Byp_Fonction_SC'
   *  Constant: '<S151>/Int_BypC'
   *  DataTypeConversion: '<S142>/OutDTConv'
   *  Product: '<S142>/Product4'
   *  Sum: '<S142>/Add1'
   *  Sum: '<S142>/Add2'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTmpSignalConversionAtTrb_p = TrbAct_arTrbActAdp_B;
  } else {
    localAdd4_c = (1.048576E+006F * localMerge1_m) + 0.5F;
    if (localAdd4_c < 65536.0F) {
      if (localAdd4_c >= 0.0F) {
        localTmpSignalConversionAtTrb_p = (UInt16)localAdd4_c;
      } else {
        localTmpSignalConversionAtTrb_p = 0U;
      }
    } else {
      localTmpSignalConversionAtTrb_p = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_arTrbActAdpInport2' */
  Rte_Write_P_TrbAct_arTrbActAdp_TrbAct_arTrbActAdp
    (localTmpSignalConversionAtTrb_p);

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Byp_Fonction_SC'
   *  Constant: '<S150>/Int_BypC'
   *  DataTypeConversion: '<S143>/OutDTConv'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTmpSignalConversionAtTrb_p = TrbAct_arTrbActFrzSp_B;
  } else if (localAdd3_l < 65536.0F) {
    if (localAdd3_l >= 0.0F) {
      localTmpSignalConversionAtTrb_p = (UInt16)localAdd3_l;
    } else {
      localTmpSignalConversionAtTrb_p = 0U;
    }
  } else {
    localTmpSignalConversionAtTrb_p = MAX_uint16_T;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_arTrbActFrzSpInport2' */
  Rte_Write_P_TrbAct_arTrbActFrzSp_TrbAct_arTrbActFrzSp
    (localTmpSignalConversionAtTrb_p);

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S149>/Byp_Fonction_SC'
   *  Constant: '<S149>/Int_BypC'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localRelationalOperator_e = TrbAct_bAcvTrbActAdp_B;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_bAcvTrbActAdpInport2' */
  Rte_Write_P_TrbAct_bAcvTrbActAdp_TrbAct_bAcvTrbActAdp
    (localRelationalOperator_e);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_facAdpArTrbActErrFilInport2' */
  Rte_IrvWrite_RE_TrbActSys_003_TEV_TrbAct_facAdpArTrbActErrFil_irv(localAbs1);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_facAdpArTrbActErr_irvInport2' */
  Rte_IrvWrite_RE_TrbActSys_003_TEV_TrbAct_facAdpArTrbActErr_irv(localpluIdx);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_pGradUsThrMesCorFil_irvInport2' */
  Rte_IrvWrite_RE_TrbActSys_003_TEV_TrbAct_pGradUsThrMesCorFil_irv(localAbs3);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtTrbAct_pGradUsThrReqFil_irvInport2' */
  Rte_IrvWrite_RE_TrbActSys_003_TEV_TrbAct_pGradUsThrReqFil_irv(localAbs2);
}

/* Start for exported function: RE_TrbActSys_004_TEV */
void RE_TrbActSys_004_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F03_posnRelTrbAct'
   *
   * Block requirements for '<S1>/F03_posnRelTrbAct':
   *  1. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_057.03 ;
   *  2. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_017.02 ;
   *  3. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_016.02 ;
   *  4. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_019.02 ;
   *  5. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_031.02 ;
   *  6. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_036.01 ;
   *  7. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_039.02 ;
   *  8. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_042.01 ;
   *  9. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_043.01 ;
   *  10. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_044.01 ;
   *  11. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_045.01 ;
   *  12. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_041.01 ;
   *  13. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_065.01 ;
   *  14. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_081.01 ;
   *  15. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  16. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_079.02 ;
   *  17. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_082.01 ;
   */
}

/* Output and update for exported function: RE_TrbActSys_004_TEV */
void RE_TrbActSys_004_TEV(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion_f;
  UInt16 localDataTypeConversion_m;
  UInt16 localLookUpTable2D_e;
  UInt16 localDataTypeConversion1_lc;
  UInt16 localLookUpTable2D_h;
  UInt16 localOutDTConv_kw;
  UInt16 localLookUpTable_g0;
  UInt16 localOutDTConv_b;
  Float32 localDataTypeConversion5_k;
  Float32 localDataTypeConversion1_js;
  Boolean localTmpSignalConversionAtTr_ck;
  Boolean localTmpSignalConversionAtTr_k3;
  Boolean localTmpSignalConversionAtTr_om;
  UInt16 localTmpSignalConversionAtTrb_n;
  UInt16 localTmpSignalConversionAtAir_p;
  UInt16 localTmpSignalConversionAtTr_mu;
  UInt16 localTmpSignalConversionAtExM_i;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_posnRelTrbAct'
   *
   * Block requirements for '<S1>/F03_posnRelTrbAct':
   *  1. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_057.03 ;
   *  2. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_017.02 ;
   *  3. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_016.02 ;
   *  4. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_019.02 ;
   *  5. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_031.02 ;
   *  6. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_036.01 ;
   *  7. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_039.02 ;
   *  8. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_042.01 ;
   *  9. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_043.01 ;
   *  10. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_044.01 ;
   *  11. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_045.01 ;
   *  12. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_041.01 ;
   *  13. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_065.01 ;
   *  14. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_081.01 ;
   *  15. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_046.02 ;
   *  16. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_079.02 ;
   *  17. SubSystem "F03_posnRelTrbAct" !Trace_To : VEMS_R_10_07018_082.01 ;
   */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_facPresAltiCorOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_facPresAltiCor'
   */
  Rte_Read_R_TrbAct_facPresAltiCor_TrbAct_facPresAltiCor
    (&localTmpSignalConversionAtTrb_n);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&TrbActSys_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_rAirLdReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_rAirLdReq'
   */
  Rte_Read_R_AirSys_rAirLdReq_AirSys_rAirLdReq(&localTmpSignalConversionAtAir_p);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_bAcvOpRelTrbActExtOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bAcvOpRelTrbActExt_INPUT'
   */
  Rte_Read_R_TrbAct_bAcvOpRelTrbActExt_TrbAct_bAcvOpRelTrbActExt
    (&localTmpSignalConversionAtTr_k3);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_rOpRelTrbActExtReqOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rOpRelTrbActExtReq_INPUT'
   */
  Rte_Read_R_TrbAct_rOpRelTrbActExtReq_TrbAct_rOpRelTrbActExtReq
    (&TrbActSys_B.TmpSignalConversionAtTrbAct_rOp);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
   *  SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_rOpTrbActAirExtPrevOutport2'
   */
  TrbAct_rOpTrbActAirExtPrev = ((Float32)
    Rte_IrvRead_RE_TrbActSys_004_TEV_TrbAct_rOpTrbActAirExtModReq_irv()) *
    1.525878906E-005F;

  /* Outputs for atomic SubSystem: '<S10>/F02_posnRelTrbActAtmMod' *
   * Block requirements for '<S10>/F02_posnRelTrbActAtmMod':
   *  1. SubSystem "F02_posnRelTrbActAtmMod" !Trace_To : VEMS_R_10_07018_021.02 ;
   */

  /* DataTypeConversion: '<S235>/Data Type Conversion' */
  localDataTypeConversion_f = TrbActSys_B.TmpSignalConversionAtExt_nEngOu;

  /* DataTypeConversion: '<S233>/OutDTConv' incorporates:
   *  Constant: '<S233>/offset'
   *  Constant: '<S233>/offset1'
   *  Constant: '<S233>/one_on_slope'
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   *  DataTypeConversion: '<S10>/Data Type Conversion8'
   *  Product: '<S233>/Product4'
   *  Product: '<S236>/Divide'
   *  Sum: '<S233>/Add1'
   *  Sum: '<S233>/Add2'
   */
  localDataTypeConversion5_k = (((((Float32)localTmpSignalConversionAtAir_p) *
    6.103515625E-005F) * (((Float32)localTmpSignalConversionAtTrb_n) *
    3.051757813E-005F)) * 16384.0F) + 0.5F;
  if (localDataTypeConversion5_k < 65536.0F) {
    TrbAct_rAirLdAltiCorReq_MP = (UInt16)localDataTypeConversion5_k;
  } else {
    TrbAct_rAirLdAltiCorReq_MP = MAX_uint16_T;
  }

  /* Lookup2D: '<S235>/Look-Up Table (2-D)'
   * About '<S235>/Look-Up Table (2-D)':
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Fixed Point    U16  2^-14
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_e),
                     (&(TrbAct_rOpRelTrbActAirExtReq_M[0])),
                     localDataTypeConversion_f, (&(TrbAct_nEng_A[0])), 8U,
                     TrbAct_rAirLdAltiCorReq_MP, (&(TrbAct_rAirLdAltiCorReq_A[0])),
                     15U);

  /* DataTypeDuplicate Block: '<S235>/Data Type Duplicate2'
   *
   * Regarding '<S235>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* Switch: '<S224>/Switch2' incorporates:
   *  DataTypeConversion: '<S235>/Data Type Conversion'
   *  Lookup2D: '<S235>/Look-Up Table (2-D)'
   */
  if (localTmpSignalConversionAtTr_k3) {
    localLookUpTable_g0 = TrbActSys_B.TmpSignalConversionAtTrbAct_rOp;
  } else {
    localLookUpTable_g0 = localLookUpTable2D_e;
  }

  /* DataTypeConversion: '<S224>/Data Type Conversion1' */
  localDataTypeConversion1_js = ((Float32)localLookUpTable_g0) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S234>/Data Type Conversion' */
  localDataTypeConversion_m = TrbActSys_B.TmpSignalConversionAtExt_nEngOu;

  /* Lookup: '<S234>/Look-Up Table'
   * About '<S234>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_g0), (&(TrbAct_facFilOpTrbActAir_T[0])),
                 localDataTypeConversion_m, (&(TrbAct_nEng_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S234>/Data Type Duplicate1'
   *
   * Regarding '<S234>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Saturate Block: '<S239>/Saturation [0-1]'
   *
   * Regarding '<S239>/Saturation [0-1]':
   *   Eliminated Saturate block
   */

  /* Sum: '<S239>/Sum1' incorporates:
   *  Product: '<S239>/Product'
   *  Sum: '<S239>/Sum'
   */
  localDataTypeConversion1_js = ((((Float32)localLookUpTable_g0) *
    1.525878906E-005F) * (localDataTypeConversion1_js -
    TrbAct_rOpTrbActAirExtPrev)) + TrbAct_rOpTrbActAirExtPrev;

  /* end of Outputs for SubSystem: '<S10>/F02_posnRelTrbActAtmMod' */

  /* DataTypeConversion: '<S226>/OutDTConv' incorporates:
   *  Constant: '<S226>/offset'
   *  Constant: '<S226>/offset1'
   *  Constant: '<S226>/one_on_slope'
   *  Product: '<S226>/Product4'
   *  Sum: '<S226>/Add1'
   *  Sum: '<S226>/Add2'
   */
  localDataTypeConversion5_k = (65536.0F * localDataTypeConversion1_js) + 0.5F;
  if (localDataTypeConversion5_k < 65536.0F) {
    if (localDataTypeConversion5_k >= 0.0F) {
      localOutDTConv_kw = (UInt16)localDataTypeConversion5_k;
    } else {
      localOutDTConv_kw = 0U;
    }
  } else {
    localOutDTConv_kw = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S227>/autosar_testpoint1' */

  /* S-Function Block: <S227>/autosar_testpoint1 */
  TrbAct_rOpTrbActAirExtModReq = localOutDTConv_kw;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_rOpTrbActReqPrevOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_rOpTrbActReq_INPUT'
   */
  Rte_Read_R_TrbAct_rOpTrbActReq_TrbAct_rOpTrbActReq
    (&localTmpSignalConversionAtTr_mu);

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  TrbAct_rOpTrbActReqPrev = ((Float32)localTmpSignalConversionAtTr_mu) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S10>/Data Type Conversion5' incorporates:
   *  SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_arTrbActReq_irvOutport2'
   */
  localDataTypeConversion5_k = ((Float32)
    Rte_IrvRead_RE_TrbActSys_004_TEV_TrbAct_arTrbActReq_irv()) *
    9.536743164E-007F;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExM_rPresTrbEstimIvsOutport2' incorporates:
   *  Inport: '<Root>/ExM_rPresTrbEstimIvs'
   */
  Rte_Read_R_ExM_rPresTrbEstimIvs_ExM_rPresTrbEstimIvs
    (&localTmpSignalConversionAtExM_i);

  /* Outputs for atomic SubSystem: '<S10>/F01_posnRelTrbActTrbMod' *
   * Block requirements for '<S10>/F01_posnRelTrbActTrbMod':
   *  1. SubSystem "F01_posnRelTrbActTrbMod" !Trace_To : VEMS_R_10_07018_020.02 ;
   */

  /* DataTypeConversion: '<S229>/OutDTConv' incorporates:
   *  Constant: '<S229>/offset'
   *  Constant: '<S229>/offset1'
   *  Constant: '<S229>/one_on_slope'
   *  DataTypeConversion: '<S10>/Data Type Conversion2'
   *  Product: '<S229>/Product4'
   *  Product: '<S231>/Divide'
   *  SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_facAdpArTrbActErrFil_irvOutport2'
   *  Sum: '<S223>/Add1'
   *  Sum: '<S229>/Add1'
   *  Sum: '<S229>/Add2'
   */
  localDataTypeConversion5_k = ((localDataTypeConversion5_k - ((((Float32)
    Rte_IrvRead_RE_TrbActSys_004_TEV_TrbAct_facAdpArTrbActErrFil_irv()) *
    1.525878906E-005F) * localDataTypeConversion5_k)) * 1.048576E+006F) + 0.5F;
  if (localDataTypeConversion5_k < 65536.0F) {
    if (localDataTypeConversion5_k >= 0.0F) {
      localOutDTConv_b = (UInt16)localDataTypeConversion5_k;
    } else {
      localOutDTConv_b = 0U;
    }
  } else {
    localOutDTConv_b = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S230>/Data Type Conversion1' */
  if (localTmpSignalConversionAtExM_i > 8191) {
    localDataTypeConversion1_lc = MAX_uint16_T;
  } else {
    localDataTypeConversion1_lc = (UInt16)(localTmpSignalConversionAtExM_i <<
      3);
  }

  /* Lookup2D: '<S230>/Look-Up Table (2-D)'
   * About '<S230>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-20
   * Input1  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U16_U16_U16( &(localLookUpTable2D_h), (&(TrbAct_rOpTrbActTrbMod_M[0])),
                     localOutDTConv_b, (&(TrbAct_arTrbActReq_A[0])), 15U,
                     localDataTypeConversion1_lc,
                     (&(TrbAct_rPresTrbEstimIvsRef1_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S230>/Data Type Duplicate2'
   *
   * Regarding '<S230>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S223>/Data Type Conversion1' incorporates:
   *  Lookup2D: '<S230>/Look-Up Table (2-D)'
   */
  TrbAct_rOpTrbActTrbModReq = ((Float32)localLookUpTable2D_h) *
    1.525878906E-005F;

  /* end of Outputs for SubSystem: '<S10>/F01_posnRelTrbActTrbMod' */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_bAcvTrbActCmdOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bAcvTrbActCmd'
   */
  Rte_Read_R_TrbAct_bAcvTrbActCmd_TrbAct_bAcvTrbActCmd
    (&localTmpSignalConversionAtTr_om);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_bPosnTrbActModOutport2' incorporates:
   *  Inport: '<Root>/TrbAct_bPosnTrbActMod'
   */
  Rte_Read_R_TrbAct_bPosnTrbActMod_TrbAct_bPosnTrbActMod
    (&localTmpSignalConversionAtTr_ck);

  /* Outputs for atomic SubSystem: '<S10>/F03_posnRelTrbActSp' *
   * Block requirements for '<S10>/F03_posnRelTrbActSp':
   *  1. SubSystem "F03_posnRelTrbActSp" !Trace_To : VEMS_R_10_07018_022.02 ;
   */

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S225>/TrbAct_bAcvTrbMod_C'
   *  Logic: '<S225>/Logical Operator'
   */
  if ((localTmpSignalConversionAtTr_ck) && TrbAct_bAcvTrbMod_C) {
    localDataTypeConversion1_js = TrbAct_rOpTrbActTrbModReq;
  }

  /* Sum: '<S248>/Sum' */
  localDataTypeConversion1_js -= TrbAct_rOpTrbActReqPrev;

  /* DataTypeConversion: '<S242>/OutDTConv' incorporates:
   *  Constant: '<S225>/TrbAct_facFilGainRatOpTrbAct_C'
   *  Constant: '<S242>/offset'
   *  Constant: '<S242>/offset1'
   *  Constant: '<S242>/one_on_slope'
   *  Product: '<S242>/Product4'
   *  Product: '<S248>/Product'
   *  Sum: '<S242>/Add1'
   *  Sum: '<S242>/Add2'
   *  Sum: '<S248>/Sum1'
   */
  localDataTypeConversion5_k = ((((((Float32)TrbAct_facFilGainRatOpTrbAct_C) *
    1.525878906E-005F) * localDataTypeConversion1_js) + TrbAct_rOpTrbActReqPrev)
    * 65536.0F) + 0.5F;
  if (localDataTypeConversion5_k < 65536.0F) {
    if (localDataTypeConversion5_k >= 0.0F) {
      localTmpSignalConversionAtAir_p = (UInt16)localDataTypeConversion5_k;
    } else {
      localTmpSignalConversionAtAir_p = 0U;
    }
  } else {
    localTmpSignalConversionAtAir_p = MAX_uint16_T;
  }

  localTmpSignalConversionAtTrb_n = localTmpSignalConversionAtAir_p;

  /* Switch: '<S245>/Switch' incorporates:
   *  Constant: '<S225>/TrbAct_rOpMinTrbAct_C'
   *  RelationalOperator: '<S245>/UpperRelop'
   */
  if (localTmpSignalConversionAtAir_p < TrbAct_rOpMinTrbAct_C) {
    localTmpSignalConversionAtTrb_n = TrbAct_rOpMinTrbAct_C;
  }

  /* Switch: '<S245>/Switch2' incorporates:
   *  Constant: '<S225>/TrbAct_rOpMaxTrbAct_C'
   *  RelationalOperator: '<S245>/LowerRelop1'
   */
  if (localTmpSignalConversionAtAir_p > TrbAct_rOpMaxTrbAct_C) {
    localTmpSignalConversionAtTrb_n = TrbAct_rOpMaxTrbAct_C;
  }

  /* Switch: '<S225>/Switch1' incorporates:
   *  Constant: '<S225>/TrbAct_rOpTrbActReqDft_C'
   */
  if (!localTmpSignalConversionAtTr_om) {
    localTmpSignalConversionAtTrb_n = TrbAct_rOpTrbActReqDft_C;
  }

  /* Switch: '<S225>/Switch3' incorporates:
   *  Constant: '<S225>/TrbAct_bTestModRatOpReq_C'
   *  Constant: '<S225>/TrbAct_rOpTrbActReqTest_C'
   */
  if (TrbAct_bTestModRatOpReq_C) {
    localTmpSignalConversionAtTrb_n = TrbAct_rOpTrbActReqTest_C;
  }

  /* end of Outputs for SubSystem: '<S10>/F03_posnRelTrbActSp' */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_rOpTrbActAirExtModReq_irvInport2' incorporates:
   *  SignalConversion: '<S10>/Signal Conversion9'
   */
  Rte_IrvWrite_RE_TrbActSys_004_TEV_TrbAct_rOpTrbActAirExtModReq_irv
    (localOutDTConv_kw);

  /* Switch: '<S228>/Switch' incorporates:
   *  Constant: '<S228>/Byp_Fonction_SC'
   *  Constant: '<S228>/Int_BypC'
   */
  if (TRBACTSYS_ACTIVE_BYP_C) {
    localTmpSignalConversionAtTrb_n = TrbAct_rOpTrbActReq_B;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtTrbAct_rOpTrbActReqInport2' */
  Rte_Write_P_TrbAct_rOpTrbActReq_TrbAct_rOpTrbActReq
    (localTmpSignalConversionAtTrb_n);
}

/* Model initialize function */
void RE_TrbActSys_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  RE_TrbActSys_001_MSE_Start();
  RE_TrbActSys_002_TEV_Start();
  RE_TrbActSys_003_TEV_Start();
  RE_TrbActSys_004_TEV_Start();

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__3'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__4'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__5'
   */
  RE_TrbActSys_003_TEV_Init();
}

#define TrbActSys_STOP_SEC_CODE
#include "TrbActSys_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
