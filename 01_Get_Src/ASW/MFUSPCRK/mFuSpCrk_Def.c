/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuSpCrk                                                */
/* !Description     : INJECTED FUEL MASS SET POINT DURING CRANKING            */
/*                                                                            */
/* !Module          : mFuSpCrk                                                */
/*                                                                            */
/* !File            : mFuSpCrk_Def.c                                          */
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
/*   Code generated on: Sun Jun 02 16:30:57 2013                              */
/*   Model name       : mFuSpCrk_AUTOCODE.mdl                                 */
/*   Model version    : 1.387                                                 */
/*   Root subsystem   : /mFuSpCrk                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUSPCRK/mFuSpCrk_Def.c_v $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   03 Jul 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "mFuSpCrk.h"
#include "mFuSpCrk_private.h"

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
#define MFUSPCRK_START_SEC_CALIB_32BIT
#include "mFuSpCrk_MemMap.h"

CONST(UInt32, MFUSPCRK_CALIB) EOM_tiEngStopRst_A[9] = { 0U, 23U, 45U, 68U, 90U,
  113U, 135U, 158U, 180U } ;

CONST(UInt32, MFUSPCRK_CALIB) InjSys_tiEngStop_A[9] = { 0U, 23U, 45U, 68U, 90U,
  113U, 135U, 158U, 180U } ;

#define MFUSPCRK_STOP_SEC_CALIB_32BIT
#include "mFuSpCrk_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define MFUSPCRK_START_SEC_CALIB_16BIT
#include "mFuSpCrk_MemMap.h"

CONST(UInt16, MFUSPCRK_CALIB) Ext_pFuRailMesRef2_A[9] = { 3840U, 6400U, 8960U,
  11520U, 14080U, 16640U, 19200U, 21760U, 23040U } ;

CONST(UInt16, MFUSPCRK_CALIB) InjSys_ctTDCThdAcvDecSTTst_T[16] = { 15U, 15U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U } ;

CONST(UInt16, MFUSPCRK_CALIB) InjSys_ctTDCThdAcvDecst_T[16] = { 15U, 15U, 10U,
  10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U, 10U } ;

CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuCrkActrTstHPPmp_C = 671U;
CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuDecStepSTTst_C = 2U;
CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuDecStepst_C = 2U;
CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuReqCrkMinSTTst_M[144] = { 1879U, 1879U,
  1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U,
  1879U, 1879U, 1879U, 1879U, 1879U, 940U, 940U, 940U, 940U, 940U, 940U, 940U,
  940U, 940U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 376U, 376U,
  376U, 376U, 376U, 376U, 376U, 376U, 376U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 113U, 113U, 113U, 113U, 113U, 113U, 113U, 113U, 113U, 113U,
  113U, 113U, 113U, 113U, 113U, 113U, 113U, 113U, 107U, 107U, 107U, 107U, 107U,
  107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U,
  86U, 86U, 86U, 86U, 86U, 86U, 86U, 86U, 86U, 75U, 75U, 75U, 75U, 75U, 75U, 75U,
  75U, 75U, 64U, 64U, 64U, 64U, 64U, 64U, 64U, 64U, 64U, 54U, 54U, 54U, 54U, 54U,
  54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U,
  54U, 54U, 54U, 54U, 54U, 54U } ;

CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuReqCrkMinst_M[144] = { 1879U, 1879U,
  1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U,
  1879U, 1879U, 1879U, 1879U, 1879U, 940U, 940U, 940U, 940U, 940U, 940U, 940U,
  940U, 940U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 376U, 376U,
  376U, 376U, 376U, 376U, 376U, 376U, 376U, 188U, 188U, 188U, 188U, 188U, 188U,
  188U, 188U, 188U, 113U, 113U, 113U, 113U, 113U, 113U, 113U, 113U, 113U, 113U,
  113U, 113U, 113U, 113U, 113U, 113U, 113U, 113U, 107U, 107U, 107U, 107U, 107U,
  107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 107U,
  86U, 86U, 86U, 86U, 86U, 86U, 86U, 86U, 86U, 75U, 75U, 75U, 75U, 75U, 75U, 75U,
  75U, 75U, 64U, 64U, 64U, 64U, 64U, 64U, 64U, 64U, 64U, 54U, 54U, 54U, 54U, 54U,
  54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U, 54U,
  54U, 54U, 54U, 54U, 54U, 54U } ;

CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuReqCrkSTTst_M[144] = { 9395U, 9395U,
  9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U,
  9395U, 9395U, 9395U, 9395U, 9395U, 4698U, 4698U, 4698U, 4698U, 4698U, 4698U,
  4698U, 4698U, 4698U, 2819U, 2819U, 2819U, 2819U, 2819U, 2819U, 2819U, 2819U,
  2819U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 940U,
  940U, 940U, 940U, 940U, 940U, 940U, 940U, 940U, 564U, 564U, 564U, 564U, 564U,
  564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U,
  537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U,
  537U, 537U, 537U, 537U, 537U, 429U, 429U, 429U, 429U, 429U, 429U, 429U, 429U,
  429U, 376U, 376U, 376U, 376U, 376U, 376U, 376U, 376U, 376U, 322U, 322U, 322U,
  322U, 322U, 322U, 322U, 322U, 322U, 268U, 268U, 268U, 268U, 268U, 268U, 268U,
  268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U,
  268U, 268U, 268U, 268U, 268U, 268U, 268U } ;

CONST(UInt16, MFUSPCRK_CALIB) InjSys_mFuReqCrkst_M[144] = { 9395U, 9395U,
  9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U, 9395U,
  9395U, 9395U, 9395U, 9395U, 9395U, 4698U, 4698U, 4698U, 4698U, 4698U, 4698U,
  4698U, 4698U, 4698U, 2819U, 2819U, 2819U, 2819U, 2819U, 2819U, 2819U, 2819U,
  2819U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 940U,
  940U, 940U, 940U, 940U, 940U, 940U, 940U, 940U, 564U, 564U, 564U, 564U, 564U,
  564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U, 564U,
  537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U, 537U,
  537U, 537U, 537U, 537U, 537U, 429U, 429U, 429U, 429U, 429U, 429U, 429U, 429U,
  429U, 376U, 376U, 376U, 376U, 376U, 376U, 376U, 376U, 376U, 322U, 322U, 322U,
  322U, 322U, 322U, 322U, 322U, 322U, 268U, 268U, 268U, 268U, 268U, 268U, 268U,
  268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U, 268U,
  268U, 268U, 268U, 268U, 268U, 268U, 268U } ;

CONST(UInt16, MFUSPCRK_CALIB) InjSys_mO2Cat_A[16] = { 0U, 500U, 1000U, 1500U,
  2000U, 3000U, 4000U, 5000U, 6000U, 7000U, 8000U, 10000U, 12500U, 15000U,
  22500U, 25000U } ;

CONST(UInt16, MFUSPCRK_CALIB) InjSys_pAirExt_A[9] = { 0U, 2500U, 5000U, 10000U,
  11875U, 13750U, 16250U, 20000U, 25000U } ;

#define MFUSPCRK_STOP_SEC_CALIB_16BIT
#include "mFuSpCrk_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define MFUSPCRK_START_SEC_CALIB_8BIT
#include "mFuSpCrk_MemMap.h"

CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacCorRstrtSTT_cntTDC_T[16] = { 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacCorRstrtSTT_mO2Cat_T[16] = { 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacCorRstrtSTT_nEng_tCo_M[256] = { 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacMaxCorRstrtSTT_C = 255U;
CONST(UInt8, MFUSPCRK_CALIB) InjSys_FacMinCorRstrtSTT_C = 127U;
CONST(UInt8, MFUSPCRK_CALIB) InjSys_bCorRstrtSTT_pAirExt_T[9] = { 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_ctTDCStrt_A[16] = { 0U, 1U, 2U, 3U, 4U, 5U,
  6U, 8U, 10U, 15U, 20U, 25U, 30U, 35U, 40U, 50U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_facCorMassFuRstrtSTT_M[144] = { 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_facCorMassFuRstrt_M[144] = { 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_facCorpAirMassFu_T[9] = { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_facCorpFuMassFu_T[9] = { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_rFilGainMassFuSTTst_T[16] = { 230U, 230U,
  230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U,
  230U } ;

CONST(UInt8, MFUSPCRK_CALIB) InjSys_rFilGainMassFust_T[16] = { 230U, 230U,
  230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U, 230U,
  230U } ;

CONST(UInt8, MFUSPCRK_CALIB) MFUSPCRK_u8Inhib = 0U;

#define MFUSPCRK_STOP_SEC_CALIB_8BIT
#include "mFuSpCrk_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define MFUSPCRK_START_SEC_CALIB_BOOLEAN
#include "mFuSpCrk_MemMap.h"

CONST(Boolean, MFUSPCRK_CALIB) InjSys_bInhFISAAntiFlood_C = 0;
CONST(Boolean, MFUSPCRK_CALIB) InjSys_bInhFISACalcMFu_C = 0;
CONST(Boolean, MFUSPCRK_CALIB) InjSys_bSelSdlClcnMassFuCrk_C = 1;

#define MFUSPCRK_STOP_SEC_CALIB_BOOLEAN
#include "mFuSpCrk_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define MFUSPCRK_START_SEC_VAR_32BIT
#include "mFuSpCrk_MemMap.h"

VAR(Float32, MFUSPCRK_VAR) InjSys_facCorMassFuRstrt;
VAR(Float32, MFUSPCRK_VAR) InjSys_mFuFacCorRstrtSTT;
VAR(Float32, MFUSPCRK_VAR) InjSys_mFuReqCrkMin;
VAR(Float32, MFUSPCRK_VAR) InjSys_mFuReqCrkMinPrev;

#define MFUSPCRK_STOP_SEC_VAR_32BIT
#include "mFuSpCrk_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define MFUSPCRK_START_SEC_VAR_16BIT
#include "mFuSpCrk_MemMap.h"

VAR(UInt16, MFUSPCRK_VAR) InjSys_ctTDCThdAcvDecMassFu;
VAR(UInt16, MFUSPCRK_VAR) InjSys_mFuCrkSp;
VAR(UInt16, MFUSPCRK_VAR) InjSys_mFuCrkSpPrev;

#define MFUSPCRK_STOP_SEC_VAR_16BIT
#include "mFuSpCrk_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
