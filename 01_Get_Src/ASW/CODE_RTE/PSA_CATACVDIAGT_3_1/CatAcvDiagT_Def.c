/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : CatAcvDiagT                                             */
/* !Description     : CatAcvDiagT Software Component                          */
/*                                                                            */
/* !Module          : CatAcvDiagT                                             */
/*                                                                            */
/* !File            : CatAcvDiagT_Def.c                                       */
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
/*   Model name       : CatAcvDiagT_AUTOSAR.mdl                               */
/*   Root subsystem   : /CatAcvDiagT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/SWC_PSA/3.1/CATMON/CATACVDIAGT/CatA$*/
/* $Revision::   1.14                                                        $*/
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

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CALIB_16BIT" */
#define CatAcvDiagT_START_SEC_CALIB_16BIT
#include "CatAcvDiagT_MemMap.h"

CONST(UInt16, CATACVDIAGT_CALIB) CatMon_tiInhDiagIntr_C = 25U;
CONST(UInt16, CATACVDIAGT_CALIB) LsMon_rMixtSenO2DsDiagLean_C = 7133U;
CONST(UInt16, CATACVDIAGT_CALIB) LsMon_rMixtSenO2DsDiagRich_C = 10700U;
CONST(UInt16, CATACVDIAGT_CALIB) LsMon_tiItrsvSenO2DsDiag_C = 1000U;
CONST(UInt16, CATACVDIAGT_CALIB) LsMon_tiItrsvWaitSenO2DsDiag_C = 500U;
CONST(UInt16, CATACVDIAGT_CALIB) LsMon_uThdItrsvSenO2DsDiagLean_C = 143U;
CONST(UInt16, CATACVDIAGT_CALIB) LsMon_uThdItrsvSenO2DsDiagRich_C = 41U;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_lamFbFilDeltaMaxThd_C = 32767;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_ldEstimDeltaMaxGas_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_ldEstimDeltaMax_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMaxGas_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMax_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMinPlausGas_C = 0U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMinPlaus_C = 0U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMvEstim_B = 0U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgThdGas_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgThd_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mfAirDeltaMaxGas_C = 30000U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mfAirDeltaMaxThd_C = 30000U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_mfAirDeltaMax_C = 30000U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_nCkDeltaMaxGas_C = 7500U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_nCkDeltaMax_C = 7500U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_nEngDeltaMaxThd_C = 7500U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_rAirLdDeltaMaxThd_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_rFbLsclDeltaMaxGas_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_rFbLsclDeltaMax_C = 65535U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtPha1Gas_C = 10700U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtPha1_C = 10700U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtPha2Gas_C = 7133U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtPha2_C = 7133U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtReqMonIntr_B = 0U;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_rlamFilThrHiThd_C = 32767;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_rlamFilThrLoThd_C = 32767;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tAirMnfMesHiThdGas_C = 200;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tAirMnfMesHiThd_C = 200;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tAirMnfMesLoThdGas_C = -50;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tAirMnfMesLoThd_C = -50;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tCoMesHiThdGas_C = 214;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tCoMesHiThd_C = 214;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tCoMesLoThdGas_C = -40;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tCoMesLoThd_C = -40;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tOxCDeltaMaxThd_C = 1000;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tOxCUsMesDeltaMaxGas_C = 1000;
CONST(SInt16, CATACVDIAGT_CALIB) OxC_tOxCUsMesDeltaMax_C = 1000;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiAcvCdnDlyOn_C = 0U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiAcvReqDlySdlCord_C = 0U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiAcvRunDlyOff_C = 0U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiPha1MaxDlyProtGas_C = 1000U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiPha1MaxDlyProt_C = 1000U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiPha2ChgMaxDly_C = 1000U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiRlamFiLpfTau_C = 0U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiTmrIniMonORngIntrGas_C = 1000U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiTmrIniMonORngIntr_C = 1000U;
CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiTmrMinMonORngIntrIni_C = 200U;

#define CatAcvDiagT_STOP_SEC_CALIB_16BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define CatAcvDiagT_START_SEC_CARTO_16BIT
#include "CatAcvDiagT_MemMap.h"

CONST(UInt16, CATACVDIAGT_CARTO) OxC_bAirLdNAuthColInput_A[15] = { 0U, 3277U,
  6554U, 9830U, 13107U, 16384U, 19661U, 22938U, 26214U, 29491U, 32768U, 36045U,
  39322U, 42598U, 45875U } ;

CONST(UInt16, CATACVDIAGT_CARTO) OxC_bAirLdNAuthRowInput_A[16] = { 500U, 1000U,
  1250U, 1500U, 1750U, 2000U, 2250U, 2500U, 2750U, 3000U, 3250U, 3500U, 3750U,
  4000U, 4250U, 4500U } ;

CONST(UInt16, CATACVDIAGT_CARTO) OxC_mfDsThr_A[16] = { 0U, 1000U, 1500U, 2000U,
  2500U, 5000U, 7500U, 10000U, 12500U, 15000U, 17500U, 20000U, 22500U, 25000U,
  27500U, 30000U } ;

CONST(SInt16, CATACVDIAGT_CARTO) OxC_tOxC_A[16] = { 500, 525, 550, 575, 600,
  625, 650, 675, 700, 725, 750, 800, 850, 900, 950, 1000 } ;

CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiCanPurgClsInput_A[16] = { 0U, 2000U,
  4000U, 6000U, 8000U, 10000U, 12000U, 14000U, 16000U, 18000U, 20000U, 22000U,
  24000U, 26000U, 28000U, 30000U } ;

CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiLamRegStabInput_A[16] = { 0U, 2000U,
  4000U, 6000U, 8000U, 10000U, 12000U, 14000U, 16000U, 18000U, 20000U, 22000U,
  24000U, 26000U, 28000U, 30000U } ;

CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiLamRegStab_T[16] = { 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiTmrScdnGas_T[16] = { 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U }
;

CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiTmrScdn_T[16] = { 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U }
;

#define CatAcvDiagT_STOP_SEC_CARTO_16BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define CatAcvDiagT_START_SEC_CALIB_8BIT
#include "CatAcvDiagT_MemMap.h"

CONST(UInt8, CATACVDIAGT_CALIB) LsMon_stItrsvSenO2DsDiag_B = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_ctMaxMonORngIntrGas_C = 255U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_ctMaxMonORngIntr_C = 255U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_ctMinMonORngIntrGas_C = 255U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_ctMinMonORngIntr_C = 255U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_idxRlamSpAcv_C = 7U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_rO2_mfDsThr_C = 255U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_rOpCanPurgReqThd_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiAirLdDlyOn_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiAirLdLpfTau_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiCylNotCutOffDlyOn_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlySdlCord_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStabMfAir_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStabNEng_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStabOxCT_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStabRatAirLd_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStablamFbFil_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiMfAirDlyOn_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiMfAirLpfTau_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiNEngDlyOn_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiNEngLpfTau_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiOxCTDlyOn_C = 5U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiOxCTLpfTau_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiRlamDlyOn_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiRlamLpfTau_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiStabCdnDlyOn_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTmrMonStabFastCdnGas_C = 10U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTmrMonStabFastCdn_C = 10U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTmrMonStabSlowCdnGas_C = 10U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTmrMonStabSlowCdn_C = 10U;
CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTranModDlyOn_C = 0U;
CONST(UInt8, CATACVDIAGT_CALIB) Oxc_tiStabRstOff_C = 0U;

#define CatAcvDiagT_STOP_SEC_CALIB_8BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define CatAcvDiagT_START_SEC_CARTO_8BIT
#include "CatAcvDiagT_MemMap.h"

CONST(UInt8, CATACVDIAGT_CARTO) OxC_bAirLdNAuth_M[16][15] = { { 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },
{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },
{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },
{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },
{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U } } ;

CONST(UInt8, CATACVDIAGT_CARTO) OxC_bAirMfTAuth_M[16][16] = { { 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U } } ;

CONST(UInt8, CATACVDIAGT_CARTO) OxC_rO2StgEstimCorIndex_M[16][16] = { { 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },
{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U } } ;

CONST(UInt8, CATACVDIAGT_CARTO) OxC_rO2StgEstimCorInterpGas_M[16][16] = { { 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },
{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U } } ;

CONST(UInt8, CATACVDIAGT_CARTO) OxC_rO2StgEstimCorInterp_M[16][16] = { { 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },
{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U } } ;

CONST(UInt8, CATACVDIAGT_CARTO) OxC_tiCanPurgCls_T[16] = { 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

#define CatAcvDiagT_STOP_SEC_CARTO_8BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define CatAcvDiagT_START_SEC_CALIB_BOOLEAN
#include "CatAcvDiagT_MemMap.h"

CONST(Boolean, CATACVDIAGT_CALIB) CATACVDIAGT_ACTIVE_BYP_C = 0;
CONST(Boolean, CATACVDIAGT_CALIB) CatMon_bDgoORngIntr_B = 0;
CONST(Boolean, CATACVDIAGT_CALIB) CatMon_bMonRunORngIntr_B = 0;
CONST(Boolean, CATACVDIAGT_CALIB) CatMon_bMonWaitORngIntr_B = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bAcvFbL_rMonItrv_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bDiagUnlimInhGas_C = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bDiagUnlimInh_C = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bIdcInhChknEng_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bIdcInhChkrAirLd_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhAFACdn_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhBlbyCdn_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaAirLd_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaMfAir_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaNEng_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaRLamFil_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaTOxC_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilAirLd_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilMfAir_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilNEng_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilRlamFilOxC_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilTOxC_C = 1;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bItpolClc_C = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bLsUsProp_C = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bMonEnaORngIntr_B = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bMonEndORngIntr_B = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bMonORngIntrAcvCdn_B = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bMonRunORngIntr_B = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bRlamAdpReq_B = 0;
CONST(Boolean, CATACVDIAGT_CALIB) OxC_bRlamFiLpfRst_C = 0;
CONST(Boolean, CATACVDIAGT_CALIB) Oxc_stMonItrsvAcvTunRst_C = 0;

#define CatAcvDiagT_STOP_SEC_CALIB_BOOLEAN
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_32BIT
#include "CatAcvDiagT_MemMap.h"

VAR(Float32, CATACVDIAGT_INTERNAL_VAR) AFReg_rFbLsclFilFil = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) Engine_load_filt = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) Ext_nEngFil = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) Ext_tOxCEstimFil = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) LsMon_rMixtItrsvSenO2DsDiagTmp = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) LsMon_uThdItrsvSenO2DsDiagTmp = 0.0F;
VAR(UInt32, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgSumEstim_IRV_MP = 0U;
VAR(UInt32, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgTotEstim_IRV_MP = 0U;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirMesThrEstimFil = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rFbL_rMonItrv = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rFbLsclFil_ItrsvSenO2Strt = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rFbLsclFil_rMonItrsvStrt = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rMixtPha1Tmp = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rMixtPha2Tmp = 0.0F;
VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rO2StgEstimCor = 0.0F;
VAR(SInt32, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrIniMonORngIntrTmp = 0;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_32BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_16BIT
#include "CatAcvDiagT_MemMap.h"

VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) CatMon_tiInhDiagIntr = 0U;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) Lambda_feedback_filt = 0;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) LsMon_tiItrsvSenO2DsDiag_IRV_MP = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) LsMon_tiItrsvWaitSenO2DsDiag = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgEstim = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgMaxTmp = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgMinPlausTmp = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgThdTmp = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirThrMax = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirThrMaxPrev = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirThrMin = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirThrMinPrev = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_nEngMax = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_nEngMaxPrev = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_nEngMin = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_nEngMinPrev = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rAirLdMax = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rAirLdMaxPrev = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rAirLdMin = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rAirLdMinPrev = 0U;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rlamFilMax = 0;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rlamFilMaxPrev = 0;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rlamFilMin = 0;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rlamFilMinPrev = 0;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tOxCMax = 0;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tOxCMaxPrev = 0;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tOxCMin = 0;
VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tOxCMinPrev = 0;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiDlyMaxProt_rMixtPha1 = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiPha1MaxDlyProtTmp = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiPha2ChgDly = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrIniMonORngIntr_IRV_MP = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrMinMonORngIntr = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrMonStabFastCdn_IRV_MP = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrScdnMonORngIntrIni = 0U;
VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrScdnMonORngIntr_IRV_MP = 0U;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_16BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_8BIT
#include "CatAcvDiagT_MemMap.h"

VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_ctMaxMonORngIntrTmp = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_ctMinMonORngIntrTmp = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_ctMonORngIntr_IRV_MP = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_stMonIntrAcv_IRV_MP = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_stMonIntrRun_IRV_MP = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntMfAirThrPrev = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntOxCPrev = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntRlamFil = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntRlamFilPrev = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabMfAirThr = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabNEng = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabNEngPrev = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabOxCT = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabRatAirLd = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabRatAirLdPrev = 0U;
VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrMonStabSlowCdn_IRV_MP = 0U;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_8BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "CatAcvDiagT_MemMap.h"

VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) First_diag_Sen02 = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bAcvCalcmO2Stg = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bAcvMonItrsv = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bAirLdNAuth = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bAirMfTAuth = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bDetStabNEng = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bDetStabOxCT = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bDiagUnlimInhTmp = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bEndInt = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bIdcInhChkMfAir = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bIdcInhChkTOxC = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bIdcInhChkrLamFil = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bMonORngIntrStabCdn_IRV_MP = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRlamFilOxCCdn = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilAirLd = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilAirLdCdn = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilMfAir = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilMfAirCdn = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilNEng = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilNEngCdn = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilOxCT = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilOxCTCdn = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilRlam = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilRlamCdn = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFiltNEng = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabAirLd = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabCanPurg = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxAirLd = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxMfAir = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxNEng = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxOxCT = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxRlam = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilAirLd = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilMfAir = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilNEng = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilOxCT = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilRlam = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabMfAir = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabMfAirThr = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabRatAirLdCor = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabRlam = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabRlamFilOxC = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabTranMod = FALSE;
VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabnoCylCutOff = FALSE;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "CatAcvDiagT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
