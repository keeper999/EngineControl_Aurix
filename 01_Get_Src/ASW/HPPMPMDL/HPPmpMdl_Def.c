/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpMdl                                                */
/* !Description     : HPPmpMdl - Modèle de la pompe haute pression            */
/*                                                                            */
/* !Module          : HPPmpMdl                                                */
/*                                                                            */
/* !File            : HPPmpMdl_Def.c                                          */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
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
/*   Code generated on: Thu Apr 04 17:41:39 2013                              */
/*   Model name       : HPPmpMdl_AUTOCODE.mdl                                 */
/*   Model version    : 1.167                                                 */
/*   Root subsystem   : /HPPmpMdl                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPMDL/HPPmpMdl_Def.c_v$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   09 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPPmpMdl.h"
#include "HPPmpMdl_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "SEC_CALIB_32BIT" */
#define HPPMPMDL_START_SEC_CALIB_32BIT
#include "HPPmpMdl_MemMap.h"

CONST(UInt32, HPPMPMDL_CALIB) PFuCtl_OfsVolPmpCor_T[16] = { 2097152U, 2097152U,
  2097152U, 2097152U, 2097420U, 2097689U, 2097957U, 2098092U, 2098226U, 2098494U,
  2099031U, 2099434U, 2099836U, 2099971U, 2100105U, 2100910U } ;

CONST(UInt32, HPPMPMDL_CALIB) PFuCtl_volFuReqEfc_A[16] = { 2097152U, 2097190U,
  2097410U, 2097813U, 2098640U, 2099796U, 2101261U, 2103436U, 2125488U, 2130271U,
  2132784U, 2134890U, 2136825U, 2138206U, 2139040U, 2139316U } ;

CONST(UInt32, HPPMPMDL_CALIB) PFuCtl_volFuReqEfc_T[16] = { 2097152U, 2097190U,
  2097410U, 2097813U, 2098640U, 2099796U, 2101261U, 2103436U, 2125488U, 2130271U,
  2132784U, 2134890U, 2136825U, 2138206U, 2139040U, 2139316U } ;

#define HPPMPMDL_STOP_SEC_CALIB_32BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define HPPMPMDL_START_SEC_CALIB_16BIT
#include "HPPmpMdl_MemMap.h"

CONST(UInt16, HPPMPMDL_CALIB) Ext_uBatt_A[9] = { 254U, 297U, 339U, 381U, 424U,
  466U, 508U, 551U, 593U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agPmpCmdDecelReq_T[16] = { 107U, 107U,
  107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U,
  107U } ;

CONST(SInt16, HPPMPMDL_CALIB) PFuCtl_agPmpCmdMin_C = 0;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agPmpCmdReqIni_C = 3200U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agPmpCmdReqRawBum_C = 1920U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdMax_C = 1280U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdMin_C = 0U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdReqOpl_T[16] = { 1067U, 1067U,
  1067U, 1067U, 1067U, 1067U, 1067U, 1067U, 1067U, 1067U, 1067U, 1067U, 1067U,
  1067U, 1067U, 1067U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdReqRawBum_C = 213U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdReq_A[16] = { 0U, 21U, 53U, 85U,
  128U, 171U, 213U, 267U, 747U, 853U, 917U, 981U, 1056U, 1131U, 1205U, 1280U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdReq_T[16] = { 0U, 21U, 53U, 85U,
  128U, 171U, 213U, 267U, 747U, 853U, 917U, 981U, 1056U, 1131U, 1205U, 1280U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdSpil_C = 2016U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_dens_T[16] = { 24412U, 24412U, 24412U,
  24412U, 24412U, 24412U, 24412U, 24412U, 24412U, 24412U, 24412U, 24412U, 24412U,
  24412U, 24412U, 24412U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_mFuPmpCtlMin_C = 0U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEngHiDecelThdHi_C = 2100U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEngHiDecelThdLo_C = 980U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEngLoDecelThdHi_C = 2050U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEngLoDecelThdLo_C = 890U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_nEng_A[16] = { 0U, 100U, 200U, 500U,
  1000U, 1500U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 5500U, 6000U,
  6500U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pDsThrMesHiDecelThdHi_C = 18750U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pDsThrMesHiDecelThdLo_C = 15000U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pDsThrMesLoDecelThdHi_C = 17500U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pDsThrMesLoDecelThdLo_C = 13750U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pFuRailSplMes_A[16] = { 0U, 1280U, 2560U,
  3840U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U, 15360U,
  16640U, 17920U, 19200U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pHiThdPresTiPmpCmd_C = 1152U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pLoThdPresTiPmpCmd_C = 1152U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_pPrailThdMFuPmpEstim_C = 1152U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_rVolEfcPmpCor_T[16] = { 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_rVolEfcPmp_M[256] = { 12352U, 16675U,
  19763U, 22851U, 25321U, 27174U, 29027U, 30108U, 30416U, 30571U, 30880U, 30787U,
  30694U, 30602U, 30509U, 30509U, 12352U, 16675U, 19763U, 22851U, 25321U, 27174U,
  29027U, 30108U, 30416U, 30571U, 30880U, 30787U, 30694U, 30602U, 30509U, 30509U,
  12352U, 16675U, 19763U, 22851U, 25321U, 27174U, 29027U, 30108U, 30416U, 30571U,
  30880U, 30787U, 30694U, 30602U, 30509U, 30509U, 12352U, 16675U, 19763U, 22851U,
  25321U, 27174U, 29027U, 30108U, 30416U, 30571U, 30880U, 30787U, 30694U, 30602U,
  30509U, 30509U, 12352U, 16675U, 19763U, 22851U, 25321U, 27174U, 29027U, 30108U,
  30416U, 30571U, 30880U, 30787U, 30694U, 30602U, 30509U, 30509U, 12352U, 16675U,
  19763U, 22851U, 25321U, 27174U, 29027U, 30108U, 30416U, 30571U, 30880U, 30787U,
  30694U, 30602U, 30509U, 30509U, 12352U, 16675U, 19763U, 22851U, 25321U, 27174U,
  29027U, 30108U, 30416U, 30571U, 30880U, 30787U, 30694U, 30602U, 30509U, 30509U,
  12352U, 16675U, 19763U, 22851U, 25321U, 27174U, 29027U, 30108U, 30416U, 30571U,
  30880U, 30787U, 30694U, 30602U, 30509U, 30509U, 12352U, 16675U, 19763U, 22851U,
  25321U, 27174U, 29027U, 30108U, 30416U, 30571U, 30880U, 30787U, 30694U, 30602U,
  30509U, 30509U, 12352U, 16675U, 19763U, 22851U, 25321U, 27174U, 29027U, 30108U,
  30416U, 30571U, 30880U, 30787U, 30694U, 30602U, 30509U, 30509U, 12352U, 16675U,
  19763U, 22851U, 25321U, 27174U, 29027U, 30108U, 30416U, 30571U, 30880U, 30787U,
  30694U, 30602U, 30509U, 30509U, 12352U, 16675U, 19763U, 22851U, 25321U, 27174U,
  29027U, 30108U, 30416U, 30571U, 30880U, 30787U, 30694U, 30602U, 30509U, 30509U,
  12352U, 16675U, 19763U, 22851U, 25321U, 27174U, 29027U, 30108U, 30416U, 30571U,
  30880U, 30787U, 30694U, 30602U, 30509U, 30509U, 12352U, 16675U, 19763U, 22851U,
  25321U, 27174U, 29027U, 30108U, 30416U, 30571U, 30880U, 30787U, 30694U, 30602U,
  30509U, 30509U, 12352U, 16675U, 19763U, 22851U, 25321U, 27174U, 29027U, 30108U,
  30416U, 30571U, 30880U, 30787U, 30694U, 30602U, 30509U, 30509U, 12352U, 16675U,
  19763U, 22851U, 25321U, 27174U, 29027U, 30108U, 30416U, 30571U, 30880U, 30787U,
  30694U, 30602U, 30509U, 30509U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiCmdEndTDCPmp_C = 78U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiOfsPmpCmdHyd_M[256] = { 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiOfsPmpCmdN_M[225] = { 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 34U, 29U, 25U, 20U, 19U, 18U, 16U, 15U, 15U, 67U, 60U, 50U,
  43U, 38U, 34U, 32U, 29U, 28U, 168U, 149U, 125U, 105U, 94U, 85U, 79U, 75U, 72U,
  337U, 299U, 249U, 211U, 188U, 170U, 158U, 149U, 142U, 505U, 447U, 372U, 316U,
  281U, 256U, 237U, 224U, 214U, 674U, 596U, 497U, 422U, 375U, 341U, 316U, 299U,
  286U, 841U, 746U, 621U, 527U, 469U, 426U, 395U, 374U, 356U, 1009U, 895U, 746U,
  633U, 563U, 511U, 475U, 450U, 428U, 1178U, 1043U, 870U, 738U, 656U, 598U, 555U,
  524U, 498U, 1346U, 1192U, 993U, 844U, 750U, 683U, 634U, 599U, 570U, 1515U,
  1342U, 1118U, 949U, 844U, 768U, 713U, 674U, 642U, 1683U, 1491U, 1242U, 1055U,
  938U, 853U, 793U, 749U, 712U, 1852U, 1639U, 1367U, 1160U, 1031U, 939U, 872U,
  823U, 784U, 2020U, 1789U, 1491U, 1266U, 1125U, 1024U, 951U, 898U, 855U, 505U,
  447U, 372U, 316U, 281U, 256U, 237U, 224U, 214U, 674U, 596U, 497U, 422U, 375U,
  341U, 316U, 299U, 286U, 841U, 746U, 621U, 527U, 469U, 426U, 395U, 374U, 356U,
  1009U, 895U, 746U, 633U, 563U, 511U, 475U, 450U, 428U, 1178U, 1043U, 870U,
  738U, 656U, 598U, 555U, 524U, 498U, 1346U, 1192U, 993U, 844U, 750U, 683U, 634U,
  599U, 570U, 1515U, 1342U, 1118U, 949U, 844U, 768U, 713U, 674U, 642U, 1683U,
  1491U, 1242U, 1055U, 938U, 853U, 793U, 749U, 712U, 1852U, 1639U, 1367U, 1160U,
  1031U, 939U, 872U, 823U, 784U, 2020U, 1789U, 1491U, 1266U, 1125U, 1024U, 951U,
  898U, 855U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPeakDurnCmd_T[25] = { 469U, 469U, 469U,
  469U, 469U, 469U, 469U, 469U, 469U, 469U, 469U, 469U, 469U, 469U, 469U, 469U,
  469U, 469U, 469U, 469U, 469U, 469U, 469U, 469U, 469U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPeakDurnOfs_C = 3U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdDecelGap_M[256] = { 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 188U, 188U, 188U, 188U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdDecel_T[16] = { 1875U, 1875U,
  1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U,
  1875U, 1875U, 1875U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdLo_M[144] = { 39999U, 39999U,
  39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 39999U,
  39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 18229U, 18229U, 18229U, 18229U,
  18229U, 18229U, 18229U, 18229U, 18229U, 7813U, 7813U, 7813U, 7813U, 7813U,
  7813U, 7813U, 7813U, 7813U, 2266U, 2266U, 2266U, 2266U, 2266U, 2266U, 2266U,
  2266U, 2266U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U,
  1289U, 1289U, 1289U, 1289U, 1289U, 1289U, 1289U, 1289U, 1289U, 801U, 801U,
  801U, 801U, 801U, 801U, 801U, 801U, 801U, 638U, 638U, 638U, 638U, 638U, 638U,
  638U, 638U, 638U, 557U, 557U, 557U, 557U, 557U, 557U, 557U, 557U, 557U, 508U,
  508U, 508U, 508U, 508U, 508U, 508U, 508U, 508U, 475U, 475U, 475U, 475U, 475U,
  475U, 475U, 475U, 475U, 452U, 452U, 452U, 452U, 452U, 452U, 452U, 452U, 452U,
  435U, 435U, 435U, 435U, 435U, 435U, 435U, 435U, 435U, 421U, 421U, 421U, 421U,
  421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U,
  421U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdReqIni_C = 0U;
CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmdReqRawBum_T[16] = { 39999U,
  39999U, 18229U, 7813U, 2266U, 1875U, 1289U, 801U, 638U, 557U, 508U, 475U, 452U,
  435U, 421U, 421U } ;

CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_tiPmpCmd_M[144] = { 39999U, 39999U,
  39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 39999U,
  39999U, 39999U, 39999U, 39999U, 39999U, 39999U, 18229U, 18229U, 18229U, 18229U,
  18229U, 18229U, 18229U, 18229U, 18229U, 7813U, 7813U, 7813U, 7813U, 7813U,
  7813U, 7813U, 7813U, 7813U, 2266U, 2266U, 2266U, 2266U, 2266U, 2266U, 2266U,
  2266U, 2266U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U, 1875U,
  1289U, 1289U, 1289U, 1289U, 1289U, 1289U, 1289U, 1289U, 1289U, 801U, 801U,
  801U, 801U, 801U, 801U, 801U, 801U, 801U, 638U, 638U, 638U, 638U, 638U, 638U,
  638U, 638U, 638U, 557U, 557U, 557U, 557U, 557U, 557U, 557U, 557U, 557U, 508U,
  508U, 508U, 508U, 508U, 508U, 508U, 508U, 508U, 475U, 475U, 475U, 475U, 475U,
  475U, 475U, 475U, 475U, 452U, 452U, 452U, 452U, 452U, 452U, 452U, 452U, 452U,
  435U, 435U, 435U, 435U, 435U, 435U, 435U, 435U, 435U, 421U, 421U, 421U, 421U,
  421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U, 421U,
  421U } ;

#define HPPMPMDL_STOP_SEC_CALIB_16BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define HPPMPMDL_START_SEC_CALIB_8BIT
#include "HPPmpMdl_MemMap.h"

CONST(UInt8, HPPMPMDL_CALIB) HPPMPMDL_u8Inhib = 0U;
CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_NrProfCmd_A[25] = { 1U, 2U, 3U, 4U, 5U, 6U,
  7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U,
  23U, 24U, 25U } ;

CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_NumProfilCmd_A[25] = { 1U, 2U, 3U, 4U, 5U,
  6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U,
  22U, 23U, 24U, 25U } ;

CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_noSplInLrnCond_C = 15U;
CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_tFuEstim_A[16] = { 10U, 20U, 30U, 40U, 50U,
  60U, 70U, 80U, 90U, 100U, 110U, 120U, 130U, 140U, 150U, 160U } ;

CONST(UInt8, HPPMPMDL_CALIB) PFuCtl_tFuUsPmp_A[16] = { 0U, 7U, 17U, 27U, 42U,
  67U, 92U, 107U, 117U, 142U, 167U, 192U, 207U, 217U, 242U, 255U } ;

#define HPPMPMDL_STOP_SEC_CALIB_8BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define HPPMPMDL_START_SEC_CALIB_BOOLEAN
#include "HPPmpMdl_MemMap.h"

CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bAcvLrnCondPmpCmdLim_C = 1;
CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bAcvPmpCmdEndTDC_C = 0;
CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bAcvPmpMinFrzI_C = 0;
CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bChoCmdAg_C = 1;
CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bForcAcvDecelZone_C = 0;
CONST(Boolean, HPPMPMDL_CALIB) PFuCtl_bmFuPmpEstim_C = 1;

#define HPPMPMDL_STOP_SEC_CALIB_BOOLEAN
#include "HPPmpMdl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define HPPMPMDL_START_SEC_VAR_32BIT
#include "HPPmpMdl_MemMap.h"

VAR(Float32, HPPMPMDL_VAR) PFuCtl_OfsVolPmpCor;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_agOfsPmpCmdDly;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_agPmpCmdEfcReqRaw;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_agPmpCmdOfs;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_agPmpCmdReqRaw;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_agWdPmpCmdMin;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_densEstim;
VAR(UInt32, HPPMPMDL_VAR) PFuCtl_mFuPmpEstim;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_mFuPmpEstimErrRaw;
VAR(UInt32, HPPMPMDL_VAR) PFuCtl_mFuPmpEstimRaw;
VAR(UInt32, HPPMPMDL_VAR) PFuCtl_mFuPmpEstimTmp;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_rVolEfcPmp;
VAR(Float32, HPPMPMDL_VAR) PFuCtl_volFuReq;
VAR(UInt32, HPPMPMDL_VAR) PFuCtl_volFuReqEfc;

#define HPPMPMDL_STOP_SEC_VAR_32BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define HPPMPMDL_START_SEC_VAR_16BIT
#include "HPPmpMdl_MemMap.h"

VAR(SInt16, HPPMPMDL_VAR) PFuCtl_agBeg2PulseDif;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agPmpCmdEfcReq;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agPmpCmdReq;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agWdPmpCmdReq;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agWdPmpCmdReqRaw;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiBeg2PulseDif;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiOfsPmpCmd;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPeakDurnCmd;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmd;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdDecelGap;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdDecelReq;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdReq;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdReqRaw;
VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdReq_prev;

#define HPPMPMDL_STOP_SEC_VAR_16BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define HPPMPMDL_START_SEC_VAR_BOOLEAN
#include "HPPmpMdl_MemMap.h"

VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bAcvLrnCondPmpCmdLim;
VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bDetAgWdPmpCmdLim;
VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bDetAgWdPmpCmdMax;
VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bDetAgWdPmpCmdMin;
VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bInhPmpCmdMinDet;
VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bPmpCmdDecelZone;

#define HPPMPMDL_STOP_SEC_VAR_BOOLEAN
#include "HPPmpMdl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
