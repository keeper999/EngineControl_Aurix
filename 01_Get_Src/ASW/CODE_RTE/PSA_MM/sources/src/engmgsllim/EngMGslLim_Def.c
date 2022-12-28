/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngMGslLim                                              */
/* !Description     : EngMGslLim Software Component                           */
/*                                                                            */
/* !Module          : EngMGslLim                                              */
/*                                                                            */
/* !File            : EngMGslLim_Def.c                                        */
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
/*   Model name       : EngMGslLim_AUTOSAR.mdl                                */
/*   Root subsystem   : /EngMGslLim                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M16-EngMGslLim/5$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   08 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "EngMGslLim.h"
#include "EngMGslLim_private.h"

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
#define EngMGslLim_START_SEC_CALIB_32BIT
#include "EngMGslLim_MemMap.h"

CONST(UInt32, ENGMGSLLIM_CALIB) EngMTrb_mFuMaxEth_C = 557056U;
CONST(UInt32, ENGMGSLLIM_CALIB) EngMTrb_mFuMax_C = 557056U;

#define EngMGslLim_STOP_SEC_CALIB_32BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define EngMGslLim_START_SEC_CARTO_16BIT
#include "EngMGslLim_MemMap.h"

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_facCorTInVlv_T[8] = { 16384U, 16384U,
  16384U, 16384U, 16384U, 16384U, 16384U, 16384U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_facCorT_T[8] = { 17408U, 16967U,
  16384U, 15743U, 15616U, 15360U, 14913U, 14464U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_facSlopIncRblIrv_T[8] = { 8U, 8U, 8U,
  8U, 8U, 8U, 4U, 4U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_facSlopIncRbl_T[8] = { 164U, 164U,
  164U, 164U, 328U, 328U, 410U, 410U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngFilGain_A[6] = { 1000U, 2000U,
  3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdCmprOverSpdY_A[16] = { 1600U,
  2000U, 2520U, 3000U, 3520U, 4000U, 4520U, 4760U, 5000U, 5240U, 5520U, 5800U,
  6000U, 6240U, 6520U, 6800U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdIncKnk_A[6] = { 1000U, 2000U,
  3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdInhTrb_A[6] = { 2000U, 3000U,
  4000U, 4500U, 5000U, 6520U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdIrvRbl_A[8] = { 1000U, 1500U,
  2000U, 2500U, 3000U, 4000U, 5000U, 6520U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdLoRonY_A[10] = { 600U, 1000U,
  1520U, 1760U, 2000U, 2520U, 3000U, 3520U, 4520U, 5520U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdLockVlv_A[8] = { 2000U, 3000U,
  4000U, 4500U, 5000U, 6520U, 7000U, 7250U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdLostSenKnk_A[8] = { 2000U, 3000U,
  4000U, 4500U, 5000U, 6520U, 7000U, 7250U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdRedMax_A[8] = { 2000U, 3000U,
  4000U, 4500U, 5000U, 5500U, 6000U, 6500U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdRef_A[16] = { 750U, 1000U, 1250U,
  1500U, 1750U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 5500U, 5800U,
  6000U, 6500U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdTAirX_A[12] = { 1000U, 1520U,
  1760U, 2000U, 2240U, 2520U, 3000U, 4000U, 5000U, 5520U, 6000U, 6520U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdTmpRblY_A[8] = { 920U, 1520U,
  2000U, 2520U, 3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngRedLdKnk_A[6] = { 1000U, 2000U,
  3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngRedStepKnk_A[6] = { 1000U, 2000U,
  3000U, 4000U, 5000U, 6000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngSlopIncRblIrv_A[8] = { 1000U,
  1500U, 2000U, 2500U, 3000U, 4000U, 5000U, 6520U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngSlopIncRbl_A[8] = { 1000U, 1500U,
  2000U, 2500U, 3000U, 4000U, 5000U, 6520U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEng_A[9] = { 300U, 700U, 1000U, 2000U,
  3000U, 4000U, 5000U, 6000U, 7000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rCmprOverSpdLim_M[8][16] = { { 31130U,
  31130U, 31130U, 31130U, 31130U, 31130U, 31130U, 31130U, 36864U, 36864U, 36864U,
  36864U, 36864U, 36864U, 36864U, 36864U },{ 41780U, 41780U, 41780U, 41780U, 41780U,
  41780U, 41780U, 41780U, 60670U, 57294U, 53904U, 51364U, 48824U, 46760U, 44400U,
  41910U },{ 60620U, 57344U, 54068U, 51610U, 49152U, 47088U, 44728U, 42124U, 59850U,
  56804U, 53740U, 51446U, 49152U, 47170U, 44892U, 42222U },{ 57884U, 55164U, 52428U,
  50380U, 48332U, 46498U, 44400U, 41762U, 52872U, 50872U, 48874U, 47382U, 45876U,
  44352U, 42598U, 40222U },{ 49774U, 48202U, 46612U, 45432U, 44236U, 42942U, 41452U,
  39240U, 47956U, 46612U, 45268U, 44270U, 43254U, 42074U, 40714U, 38568U },{ 46908U,
  45678U, 44450U, 43516U, 42598U, 41452U, 40140U, 38076U, 44924U, 43876U, 42844U,
  42074U, 41288U, 40288U, 39158U, 37240U },{ 43712U, 42796U, 41862U, 41172U, 40468U,
  39550U, 38502U, 36668U, 42976U, 42058U, 41124U, 40436U, 39732U, 38928U, 38010U,
  36258U },{ 41698U, 40878U, 40058U, 39452U, 38830U, 38060U, 37192U, 35586U, 39928U,
  39370U, 38830U, 38420U, 38010U, 37322U, 36536U, 35012U } } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rFilGainLoRon_T[6] = { 3000U, 3000U,
  3000U, 3000U, 3000U, 3000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdIncProtKnk_T[6] = { 819U, 328U,
  328U, 328U, 164U, 164U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdInhTrb_T[6] = { 18022U, 13107U,
  9830U, 9011U, 8192U, 6554U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdIrvLimRbl_T[8] = { 19661U, 19661U,
  20480U, 21299U, 22118U, 20480U, 20316U, 19661U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdKnkLoRon_M[16][10] = { { 19661U, 19661U,
  19661U, 19661U, 19661U, 19661U, 19661U, 19661U, 24576U, 24576U },{ 24576U, 24576U,
  24576U, 24576U, 24576U, 28672U, 19661U, 19661U, 19661U, 19661U },{ 19661U, 19661U,
  19661U, 19661U, 24576U, 24576U, 24576U, 24576U, 24576U, 24576U },{ 24576U, 28672U,
  19661U, 19661U, 19661U, 19661U, 19661U, 19661U, 19661U, 19661U },{ 24576U, 24576U,
  24576U, 24576U, 24576U, 24576U, 24576U, 28672U, 19661U, 19661U },{ 19661U, 19661U,
  19661U, 19661U, 19661U, 19661U, 24576U, 24576U, 24576U, 24576U },{ 24576U, 24576U,
  24576U, 30310U, 19661U, 19661U, 19661U, 19661U, 19661U, 19661U },{ 19661U, 19661U,
  24576U, 24576U, 24576U, 24576U, 24576U, 24576U, 24576U, 30310U },{ 19661U, 19661U,
  19661U, 19661U, 19661U, 19661U, 19661U, 19661U, 24576U, 24576U },{ 24576U, 24576U,
  24576U, 24576U, 24576U, 30474U, 19661U, 19661U, 19661U, 19661U },{ 19661U, 19661U,
  19661U, 19661U, 24576U, 24576U, 24576U, 24576U, 24576U, 24576U },{ 24576U, 30638U,
  19661U, 19661U, 19661U, 19661U, 19661U, 19661U, 19661U, 19661U },{ 24576U, 24576U,
  24576U, 24576U, 24576U, 24576U, 24576U, 30802U, 19661U, 19661U },{ 19661U, 19661U,
  19661U, 19661U, 19661U, 19661U, 24576U, 24576U, 24576U, 24576U },{ 24576U, 24576U,
  27034U, 30966U, 19661U, 19661U, 19661U, 19661U, 19661U, 19661U },{ 19661U, 19661U,
  24576U, 24576U, 24576U, 24576U, 24576U, 24576U, 27034U, 31130U } } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdLimTmpRbl_M[4][8] = { { 18022U, 17203U,
  17203U, 17203U, 18022U, 17203U, 17203U, 17203U },{ 18842U, 18186U, 18022U, 17695U,
  22938U, 21299U, 20480U, 19661U },{ 21299U, 20480U, 19661U, 18842U, 20480U, 19661U,
  18842U, 18022U },{ 19661U, 18842U, 18022U, 17203U, 18842U, 18022U, 16712U, 16712U} };

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdLockVlv_T[8] = { 20480U, 21299U,
  22282U, 25395U, 24576U, 22938U, 22938U, 22938U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdLostSenKnk_T[8] = { 18022U, 17203U,
  16712U, 16384U, 16384U, 16384U, 16384U, 16384U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdMaxRef2_T[16] = { 14746U, 18514U,
  20972U, 26378U, 25682U, 24073U, 23713U, 24702U, 24910U, 25267U, 25277U, 26160U,
  25379U, 25723U, 24166U, 24625U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdMaxRef_T[16] = { 14746U, 18514U,
  20972U, 26378U, 25682U, 24073U, 23713U, 24702U, 24910U, 25267U, 25277U, 26160U,
  25379U, 25723U, 24166U, 24625U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdMaxTAirLim_M[12][6] = { { 29491U, 29491U,
  29491U, 29491U, 29491U, 29491U },{ 29491U, 29491U, 29491U, 29491U, 29491U, 29491U },
{ 29491U, 29491U, 29491U, 29491U, 29491U, 29491U },{ 29491U, 29491U, 29491U, 29491U,
  29491U, 29491U },{ 29491U, 29491U, 27197U, 26706U, 26542U, 25723U },{ 25559U, 24904U,
  22938U, 22118U, 21299U, 19988U },{ 29491U, 29491U, 26378U, 25887U, 25723U, 24904U },
{ 24740U, 24084U, 22118U, 21299U, 20480U, 19169U },{ 21955U, 21955U, 20316U, 19825U,
  19825U, 19169U },{ 19005U, 18514U, 16876U, 15892U, 15401U, 14254U },{ 21955U, 21955U,
  21955U, 21955U, 21955U, 21955U },{ 21955U, 21955U, 21955U, 21955U, 21955U, 21955U} };

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdRedMax_T[8] = { 8192U, 8192U, 8192U,
  9472U, 9856U, 9856U, 9856U, 9856U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rMaxIgEfcX_A[16] = { 614U, 635U, 655U,
  676U, 696U, 717U, 737U, 758U, 778U, 799U, 819U, 840U, 860U, 881U, 901U, 922U }
;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rRedStepProtKnk_T[6] = { 1311U, 1311U,
  1311U, 1638U, 1638U, 1638U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_tAirUsInVlv_A[8] = { 1536U, 4096U,
  6656U, 8192U, 9856U, 11776U, 16256U, 19456U } ;

CONST(SInt16, ENGMGSLLIM_CARTO) EngMTrb_tCoMes_A[8] = { -30, -20, 0, 20, 30, 40,
  60, 80 } ;

CONST(SInt16, ENGMGSLLIM_CARTO) EngMTrb_tCoRef_A[9] = { -40, -30, -20, -10, 0,
  10, 20, 30, 40 } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_tThrMesY_A[6] = { 14758U, 15334U,
  17254U, 19174U, 21760U, 22656U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_tUsCmprX_A[8] = { 4064U, 6656U, 9824U,
  11744U, 14336U, 16928U, 19424U, 22016U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_tiRedLdKnkCtl_T[6] = { 1000U, 1000U,
  1200U, 1500U, 1200U, 1000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_ctTiOvbAcv_A[8] = { 0U, 200U, 400U,
  600U, 1000U, 1200U, 1600U, 2000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_facOvbBas_M[4][6] = { { 0U, 0U, 0U, 0U,
  3840U, 3840U },{ 1792U, 0U, 2560U, 2560U, 1280U, 0U },{ 3072U, 3072U, 1536U, 0U,
  3584U, 3584U },{ 1024U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_nEngY_A[6] = { 1560U, 1600U, 2240U,
  2520U, 4520U, 5000U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_tThrMesX_A[4] = { 10259U, 14099U,
  14778U, 15635U } ;

CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_tiDlyInh_T[8] = { 0U, 40U, 700U, 840U,
  1200U, 1600U, 1800U, 2000U } ;

#define EngMGslLim_STOP_SEC_CARTO_16BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define EngMGslLim_START_SEC_CALIB_16BIT
#include "EngMGslLim_MemMap.h"

CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facOvbAcvIni_C = 0U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facOvbReqIni_C = 0U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facProtKnkInh_C = 16384U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facProtKnkIni_C = 16384U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facProtKnkMin_C = 8192U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_pDsCmprMax_C = 32500U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxIni_C = 16384U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxIrvRblIni_C = 32768U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxLoRonIni_C = 32768U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxOvbAcvIni_C = 16384U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxOvbAcv_B = 0U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxTiInjEs_C = 65535U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxTotIni_C = 16384U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMax_B = 0U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdRblIrvMin_C = 8192U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdRblTmpMin_C = 8192U;
CONST(SInt16, ENGMGSLLIM_CALIB) EngMTrb_tCoThd_C = 25;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiDlyEndProtKnk_C = 910U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiDlyEndProtRblIrv_C = 27307U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiDlyEndProtRbl_C = 910U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiEthDftTran_C = 2000U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiSample_C = 10U;
CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiSlopFrzTPM_C = 12000U;
CONST(UInt16, ENGMGSLLIM_CALIB) Eng_facStoichEth_C = 17347U;
CONST(UInt16, ENGMGSLLIM_CALIB) OvbCtl_facOvbMax_C = 32768U;
CONST(SInt16, ENGMGSLLIM_CALIB) OvbCtl_tCoThdAcvOvb_C = 80;
CONST(UInt16, ENGMGSLLIM_CALIB) OvbCtl_tiDlyMax_C = 2400U;
CONST(UInt16, ENGMGSLLIM_CALIB) OvbCtl_tiMaxAcv_C = 1000U;

#define EngMGslLim_STOP_SEC_CALIB_16BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define EngMGslLim_START_SEC_CARTO_8BIT
#include "EngMGslLim_MemMap.h"

CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_ctInjCutOffPtlX_A[4] = { 64U, 65U, 70U,
  80U } ;

CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_facCorColdTCo_M[9][8] = { { 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U } } ;

CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_facCorLdMaxRef_M[9][8] = { { 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U } } ;

CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_facCorOvbAcv_M[9][8] = { { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },
{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U } } ;

CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_facCorOvbReq_M[9][8] = { { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },
{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U },{ 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U },{ 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U } } ;

CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_rEthRef_A[8] = { 0U, 77U, 90U, 102U,
  109U, 115U, 122U, 128U } ;

#define EngMGslLim_STOP_SEC_CARTO_8BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define EngMGslLim_START_SEC_CALIB_8BIT
#include "EngMGslLim_MemMap.h"

CONST(UInt8, ENGMGSLLIM_CALIB) EngMTrb_rEthDft_C = 128U;
CONST(UInt8, ENGMGSLLIM_CALIB) EngMTrb_rEthThd_C = 102U;
CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbAcv_C = 1U;
CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbInh_C = 4U;
CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbIni_C = 0U;
CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbStopReq_C = 2U;
CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbStop_C = 3U;
CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvb_C = 0U;

#define EngMGslLim_STOP_SEC_CALIB_8BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define EngMGslLim_START_SEC_CALIB_BOOLEAN
#include "EngMGslLim_MemMap.h"

CONST(Boolean, ENGMGSLLIM_CALIB) ENGMGSLLIM_ACTIVE_BYP_C = 0;
CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bAcvProtKnkIni_C = 0;
CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bAcvProtKnk_B = 0;
CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bAcvTPMMod_C = 1;
CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bFlex_C = 1;
CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bRatEthRcvAcv_C = 1;
CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bWupFlexAcv_C = 1;
CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bAcvOvb_C = 1;
CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bAcvTPMMod_C = 1;
CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bMPMOvbStop_C = 0;
CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bPresExServo_C = 1;
CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bPresInServo_C = 1;

#define EngMGslLim_STOP_SEC_CALIB_BOOLEAN
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define EngMGslLim_START_SEC_INTERNAL_VAR_32BIT
#include "EngMGslLim_MemMap.h"

VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facOvbAcvFlex = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facOvbReqFlex = 0.0F;
VAR(UInt32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facProtKnk_IRV_MP = 0U;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facStoichFlex = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_mFuMaxFlex = 0.0F;
VAR(UInt32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_mFuMaxInter_MP = 0U;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxCord[2] = { 0.0F, 0.0F
};

VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxRef[2] = { 0.0F, 0.0F };

VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rEth = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxBas = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxGsl = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxLoRon = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxRefFlex = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxRefFlexCor = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxRefGsl = 0.0F;
VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxTiInjMax = 0.0F;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_32BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define EngMGslLim_START_SEC_INTERNAL_VAR_16BIT
#include "EngMGslLim_MemMap.h"

VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facOvbAcv_IRV_MP = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facOvbReq_IRV_MP = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facProt_MP = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_pCmprOverSp_MP = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_pDsCmprMax_MP = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxIrvRbl_001 = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxIrvRbl_002 = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxProt_MP[2] = { 0U, 0U };

VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxTot_001 = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxTot_002 = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdRblIrv_MP[2] = { 0U, 0U };

VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdRbl_MP[2] = { 0U, 0U };

VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdLimTmpRbl = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxLoRonIni_IRV_MP = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxTAirLim = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdProtTPM = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdProtTPMFrz_IRV_MP = 0U;
VAR(SInt16, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_facOvbDec_MP = 0;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_facOvbStop = 0U;
VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_tiDly = 0U;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_16BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define EngMGslLim_START_SEC_INTERNAL_VAR_8BIT
#include "EngMGslLim_MemMap.h"

VAR(UInt8, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_stOvb_IRV_MP = 0U;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_8BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define EngMGslLim_START_SEC_INTERNAL_VAR_BOOLEAN
#include "EngMGslLim_MemMap.h"

VAR(Boolean, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_bWupClcAcv = FALSE;
VAR(Boolean, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_bAcvEngProt = FALSE;
VAR(Boolean, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_bAcvVlvServo = FALSE;
VAR(Boolean, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_bInhMaxTiThd = FALSE;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "EngMGslLim_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
