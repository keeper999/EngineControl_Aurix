/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : InMdlT                                                  */
/* !Description     : InMdlT Software Component                               */
/*                                                                            */
/* !Module          : InMdlT                                                  */
/*                                                                            */
/* !File            : InMdlT_Def.c                                            */
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
/*   Model name       : InMdlT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /InMdlT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M02-InMdlT/5-SOF$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   18 Jun 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InMdlT.h"
#include "InMdlT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CALIB_32BIT" */
#define InMdlT_START_SEC_CALIB_32BIT
#include "InMdlT_MemMap.h"

CONST(UInt32, INMDLT_CALIB) InM_mAirEstim_B = 0U;
CONST(UInt32, INMDLT_CALIB) InM_mEGREstim_B = 0U;
CONST(SInt32, INMDLT_CALIB) InM_mfFuStmBlbyThd_C = 1280;
CONST(UInt32, INMDLT_CALIB) InM_pDsThrEstim_B = 12800000U;
CONST(UInt32, INMDLT_CALIB) InM_tiDlyEGRCls_C = 10000U;
CONST(UInt32, INMDLT_CALIB) InM_tiDlyFuStmClsBbly_C = 5000U;
CONST(UInt32, INMDLT_CALIB) InM_tiDlyFuStmCls_C = 10000U;

#define InMdlT_STOP_SEC_CALIB_32BIT
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define InMdlT_START_SEC_CARTO_16BIT
#include "InMdlT_MemMap.h"

CONST(UInt16, INMDLT_CARTO) Air_arEffEGRVlv_T[9] = { 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U } ;

CONST(UInt16, INMDLT_CARTO) Air_concFuStm_A[9] = { 0U, 8192U, 16384U, 24412U,
  32768U, 40960U, 49152U, 57344U, 65535U } ;

CONST(UInt16, INMDLT_CARTO) Air_mfEg_A[17] = { 0U, 299U, 597U, 898U, 1196U,
  1495U, 1793U, 2092U, 2390U, 2691U, 2989U, 3288U, 3586U, 3885U, 4184U, 4482U,
  4770U } ;

CONST(UInt16, INMDLT_CARTO) InM_arEffCanPurg_T[11] = { 0U, 1U, 40U, 81U, 134U,
  215U, 295U, 429U, 550U, 698U, 913U } ;

CONST(UInt16, INMDLT_CARTO) InM_facCfeVlv1_T[22] = { 42367U, 42367U, 41480U,
  37439U, 33867U, 28783U, 25401U, 21117U, 18448U, 15188U, 13221U, 10844U, 9489U,
  7752U, 6209U, 5715U, 4261U, 4037U, 3799U, 3546U, 3273U, 1U } ;

CONST(UInt16, INMDLT_CARTO) InM_pBackEgPUsEGRVlv_T[17] = { 0U, 76U, 189U, 338U,
  520U, 738U, 989U, 1276U, 1599U, 1959U, 2350U, 2779U, 3240U, 3738U, 4271U,
  4838U, 5418U } ;

CONST(UInt16, INMDLT_CARTO) InM_pDrpLossUsEGRVlv_T[9] = { 0U, 4U, 69U, 125U,
  231U, 369U, 590U, 1050U, 2238U } ;

CONST(SInt16, INMDLT_CARTO) InM_tOilEstim_A[8] = { -120, -40, 0, 80, 200, 400,
  600, 800 } ;

CONST(UInt16, INMDLT_CARTO) InM_tOilEstim_T[8] = { 2560U, 5120U, 6400U, 8960U,
  12800U, 19200U, 25600U, 32000U } ;

#define InMdlT_STOP_SEC_CARTO_16BIT
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define InMdlT_START_SEC_CALIB_16BIT
#include "InMdlT_MemMap.h"

CONST(UInt16, INMDLT_CALIB) InM_agCkHiTDCRef2_C = 5760U;
CONST(UInt16, INMDLT_CALIB) InM_agCkLoTDCRef2_C = 7680U;
CONST(UInt16, INMDLT_CALIB) InM_arEffAdpEGRVlv_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_arEffAdpEGRVlv_C = 0U;
CONST(UInt16, INMDLT_CALIB) InM_arEffAdpThr_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_arEffEGRVlv_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_arEffEGRVlv_C = 0U;
CONST(UInt16, INMDLT_CALIB) InM_concAirCor_B = 65535U;
CONST(UInt16, INMDLT_CALIB) InM_concAirPredCor_B = 65535U;
CONST(UInt16, INMDLT_CALIB) InM_concAirPredInCylCor_B = 65535U;
CONST(UInt16, INMDLT_CALIB) InM_concEGREstim_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_concFuCor_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_concFuPredCor_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_concFuPredInCylCor_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_facCfeGradThr_B = 65535U;
CONST(UInt16, INMDLT_CALIB) InM_facCoplMassPres_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_facKK1Acc_C = 14948U;
CONST(UInt16, INMDLT_CALIB) InM_facKK1Dec_C = 11956U;
CONST(UInt16, INMDLT_CALIB) InM_facRelaxCplMassPresEstim_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_mEGREstimDec_C = 0U;
CONST(UInt16, INMDLT_CALIB) InM_mEGREstimLoResl_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_mFuStmEstimDec_C = 1U;
CONST(UInt16, INMDLT_CALIB) InM_mfAirCanPurgEstim_B = 0U;
CONST(SInt16, INMDLT_CALIB) InM_mfAirDifIn_B = 0;
CONST(UInt16, INMDLT_CALIB) InM_mfAirEstim_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_mfAirThrEstim_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_mfEGREstimEGRVlv_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_mfEGREstimEGRVlv_C = 0U;
CONST(UInt16, INMDLT_CALIB) InM_mfEGRReq_arEGR_B = 128U;
CONST(UInt16, INMDLT_CALIB) InM_mfEGRReq_arEGR_C = 0U;
CONST(UInt16, INMDLT_CALIB) InM_mfTotCanPurgEstim_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_nEngCor_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_pBackEgPUsEGRVlv_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_pBackEgPUsEGRVlv_C = 0U;
CONST(UInt16, INMDLT_CALIB) InM_pDsThrCor_B = 0U;
CONST(SInt16, INMDLT_CALIB) InM_pDsThrEstimErr_B = 0;
CONST(UInt16, INMDLT_CALIB) InM_pDsThrPredInCyl_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_pDsThrPred_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_pDsThrPred_facVlvOvlp_B = 0U;
CONST(SInt16, INMDLT_CALIB) InM_pDynCorPres_B = 0;
CONST(UInt16, INMDLT_CALIB) InM_pSenHiThd_C = 14375U;
CONST(UInt16, INMDLT_CALIB) InM_pSenLoThd_C = 1375U;
CONST(UInt16, INMDLT_CALIB) InM_pUsEGRVlv_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_pUsEGRVlv_C = 0U;
CONST(UInt16, INMDLT_CALIB) InM_prm_concAirPredCyl_B[6] = { 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U } ;

CONST(UInt16, INMDLT_CALIB) InM_prm_concFuPredCyl_B[6] = { 0U, 0U, 0U, 0U, 0U,
  0U } ;

CONST(UInt16, INMDLT_CALIB) InM_prm_pDsThrPredCyl_B[6] = { 0U, 0U, 0U, 0U, 0U,
  0U } ;

CONST(UInt16, INMDLT_CALIB) InM_prm_pDsThrPredOvlpCyl_B[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, INMDLT_CALIB) InM_rAirPres_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_rCohMnfMf_B = 16384U;
CONST(UInt16, INMDLT_CALIB) InM_rTotLdExEstim_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_tiInvEigVal_mAir_B = 0U;
CONST(UInt16, INMDLT_CALIB) InM_tiInvEigVal_pDsThr_B = 0U;

#define InMdlT_STOP_SEC_CALIB_16BIT
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define InMdlT_START_SEC_CARTO_8BIT
#include "InMdlT_MemMap.h"

CONST(UInt8, INMDLT_CARTO) Air_rOpEGR_A[9] = { 0U, 16U, 32U, 48U, 64U, 80U,
  96U, 112U, 128U } ;

CONST(UInt8, INMDLT_CARTO) InM_facCfeCanPurgCor_T[9] = { 0U, 10U, 20U, 33U,
  51U, 72U, 97U, 133U, 187U } ;

CONST(UInt8, INMDLT_CARTO) InM_mfAirStabToTranThd_T[9] = { 10U, 12U, 15U, 16U,
  20U, 23U, 25U, 27U, 30U } ;

CONST(UInt8, INMDLT_CARTO) InM_mfAirTranToStabThd_T[9] = { 8U, 10U, 13U, 15U,
  17U, 20U, 22U, 23U, 26U } ;

CONST(UInt8, INMDLT_CARTO) InM_rOpCanPurg_A[11] = { 0U, 13U, 22U, 33U, 47U,
  64U, 91U, 125U, 161U, 201U, 255U } ;

#define InMdlT_STOP_SEC_CARTO_8BIT
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define InMdlT_START_SEC_CALIB_8BIT
#include "InMdlT_MemMap.h"

CONST(UInt8, INMDLT_CALIB) InM_facCfeCanPurgCor_B = 255U;
CONST(UInt8, INMDLT_CALIB) InM_pSenFilGain1_C = 210U;
CONST(UInt8, INMDLT_CALIB) InM_pSenFilGain2_C = 133U;
CONST(UInt8, INMDLT_CALIB) InM_stModeMng_B = 4U;
CONST(UInt8, INMDLT_CALIB) InM_stTranLd_B = 128U;
CONST(UInt8, INMDLT_CALIB) InM_tiRelax_mTotEstim_B = 0U;
CONST(UInt8, INMDLT_CALIB) InM_tiRelax_pDsThrEstim_B = 0U;

#define InMdlT_STOP_SEC_CALIB_8BIT
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define InMdlT_START_SEC_CALIB_BOOLEAN
#include "InMdlT_MemMap.h"

CONST(Boolean, INMDLT_CALIB) INMDLT_ACTIVE_BYP_C = 0;
CONST(Boolean, INMDLT_CALIB) InM_bAcceEng_B = 0;
CONST(Boolean, INMDLT_CALIB) InM_bHrznClcMod_C = 1;
CONST(Boolean, INMDLT_CALIB) InM_bInhCmpAirBby_C = 0;
CONST(Boolean, INMDLT_CALIB) InM_bInhEGRPresEstim_C = 0;
CONST(Boolean, INMDLT_CALIB) InM_bInhHeatTrf_C = 0;
CONST(Boolean, INMDLT_CALIB) InM_bInhInMDynCor_C = 0;
CONST(Boolean, INMDLT_CALIB) InM_bInhInMNomMod_C = 0;
CONST(Boolean, INMDLT_CALIB) InM_bInhSenMdl_C = 0;
CONST(Boolean, INMDLT_CALIB) InM_bSelCanPurgClc_C = 1;

#define InMdlT_STOP_SEC_CALIB_BOOLEAN
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define InMdlT_START_SEC_INTERNAL_VAR_32BIT
#include "InMdlT_MemMap.h"

VAR(Float32, INMDLT_INTERNAL_VAR) AirEfc_facChrExpFilEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) AirEfc_facChrExpScvFilEstim = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkClsInVlvEstimRef2_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkOvlpEstimRef2 = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkPhaHrznOvlpPred = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkPhaHrznPred = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkPhaHrznPredInCyl = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_arEffThrOfs = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_concAirEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_concAirPredInCyl_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_concAirPred_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_concAirRaw_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_concFuPredInCyl_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_concFuPred_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_concFuStmEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_concFuStmRaw_IRV_MP = 0.0F;
VAR(UInt32, INMDLT_INTERNAL_VAR) InM_ctEGRVlvCls_IRV_MP = 0U;
VAR(UInt32, INMDLT_INTERNAL_VAR) InM_facCfeEGREstim_MP = 0U;
VAR(UInt32, INMDLT_INTERNAL_VAR) InM_facCfeEGR_MP = 0U;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_facRelaxCoplMassPresPred[3] = { 0.0F,
  0.0F, 0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_facSlopEfcEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirCylPred_MP[3] = { 0.0F, 0.0F, 0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirEstimInt = 0.0F;
VAR(UInt32, INMDLT_INTERNAL_VAR) InM_mAirEstimPres_MP = 0U;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirEstimPrev_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirPred[3] = { 0.0F, 0.0F, 0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirPredInt[3] = { 0.0F, 0.0F, 0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirPredPres_MP[3] = { 0.0F, 0.0F, 0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_mBurnInMnfPred[3] = { 0.0F, 0.0F, 0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_mEGREstimPrev_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mFuInMnfMnfPred[3] = { 0.0F, 0.0F, 0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_mFuStmEstimPrev_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mFuStmEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mGradAirEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mGradEGREstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mGradFuStmEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mTotEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mTotPred[3] = { 0.0F, 0.0F, 0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_mfAirStabToTranThd = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mfAirTranToStabThd = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_mfFuStmCanPurgEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrEstimLoResl_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrEstimPrev_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrPredInCylRaw_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrPredRawNoSat_MP[3] = { 0.0F, 0.0F,
  0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrPredRawTmp[3] = { 0.0F, 0.0F, 0.0F
};

VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrPredRaw_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrSenEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThr_facVlvOvlp_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pGradDsThrEstim_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrev1SenFil_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenBuffer_01_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenBuffer_02_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenBuffer_03_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenBuffer_04_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenFil_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenSat_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_prm_concAirPredRef[3] = { 0.0F, 0.0F,
  0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_prm_concFuPredRef[3] = { 0.0F, 0.0F, 0.0F
};

VAR(Float32, INMDLT_INTERNAL_VAR) InM_prm_pDsThrPredRawRef[3] = { 0.0F, 0.0F,
  0.0F };

VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiHrznPredInCyl_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiHrznPred_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiHrznPred_facVlvOvlp_IRV_MP = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mAirEstim = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mAirPred[3] = { 0.0F, 0.0F, 0.0F
};

VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mEGREstim = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mEGRPred[3] = { 0.0F, 0.0F, 0.0F
};

VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mFuStmEstim = 0.0F;
VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mFuStmPred[3] = { 0.0F, 0.0F,
  0.0F };

#define InMdlT_STOP_SEC_INTERNAL_VAR_32BIT
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define InMdlT_START_SEC_INTERNAL_VAR_16BIT
#include "InMdlT_MemMap.h"

VAR(UInt16, INMDLT_INTERNAL_VAR) AFA_rOpThrMax_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) AFA_rOpThrRef2_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) AFA_rOpThrRef3_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_agCkPosnCurCor_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_agCkPosnCurRef2Cor_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_arEffCanPurg_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_arEffThr_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_concAirRawNoSat_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_concFuStmRawNoSat_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_facCfeCanPurg_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_facCfeThr_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_facMfThr_MP = 65535U;
VAR(SInt16, INMDLT_INTERNAL_VAR) InM_mGradAirEstimRaw_MP = 0;
VAR(SInt16, INMDLT_INTERNAL_VAR) InM_mGradEGREstimRaw_MP = 0;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_mfSel_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_mfTotExEstim_IRV_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_nEngPred_IRV_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_pDrpLossUsEGRVlv_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_pSenBufferRaw_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_pSenFilRaw_MP = 0U;
VAR(UInt16, INMDLT_INTERNAL_VAR) InM_tiRelaxMassAir_MP[3] = { 0U, 0U, 0U };

VAR(UInt16, INMDLT_INTERNAL_VAR) InM_tiRelax_mTotPred[3] = { 0U, 0U, 0U };

VAR(UInt16, INMDLT_INTERNAL_VAR) InM_tiRelax_pDsThrPred[3] = { 0U, 0U, 0U };

#define InMdlT_STOP_SEC_INTERNAL_VAR_16BIT
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define InMdlT_START_SEC_INTERNAL_VAR_8BIT
#include "InMdlT_MemMap.h"

VAR(UInt8, INMDLT_INTERNAL_VAR) InM_cntPrevSenPres_IRV_MP = 0U;
VAR(UInt8, INMDLT_INTERNAL_VAR) InM_facKK1_MP = 0U;
VAR(UInt8, INMDLT_INTERNAL_VAR) InM_stTranLd_SF = 0U;

#define InMdlT_STOP_SEC_INTERNAL_VAR_8BIT
#include "InMdlT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define InMdlT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "InMdlT_MemMap.h"

VAR(Boolean, INMDLT_INTERNAL_VAR) InM_bAcceEng_SF = FALSE;
VAR(Boolean, INMDLT_INTERNAL_VAR) InM_bSelFacRelaxCop_MP[3] = { FALSE, FALSE,
  FALSE };

#define InMdlT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "InMdlT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
