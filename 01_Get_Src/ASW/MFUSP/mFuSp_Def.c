/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuSp                                                   */
/* !Description     : INJECTION MASS PER CYLINDER                             */
/*                                                                            */
/* !Module          : mFuSp                                                   */
/*                                                                            */
/* !File            : mFuSp_Def.c                                             */
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
/*   Code generated on: Wed Jul 17 12:40:01 2013                              */
/*   Model name       : mFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.274                                                 */
/*   Root subsystem   : /mFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUSP/mFuSp_Def.c_v       $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   22 Jul 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "mFuSp.h"
#include "mFuSp_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define MFUSP_START_SEC_CALIB_16BIT
#include "mFuSp_MemMap.h"

CONST(UInt16, MFUSP_CALIB) Ext_nEngX_A[16] = { 500U, 700U, 850U, 1000U, 1250U,
  1500U, 1750U, 2000U, 2500U, 3000U, 3500U, 4000U, 4500U, 5000U, 6000U, 6500U } ;

CONST(UInt16, MFUSP_CALIB) Ext_pDsThrMesSIY_A[16] = { 2500U, 3750U, 6250U,
  7500U, 8750U, 10000U, 11250U, 12500U, 13750U, 15000U, 16250U, 17500U, 18750U,
  20000U, 21250U, 22500U } ;

CONST(UInt16, MFUSP_CALIB) InjSys_facInjCmpETB_C = 4000U;
CONST(UInt16, MFUSP_CALIB) InjSys_facStoichBasGas_C = 50790U;
CONST(UInt16, MFUSP_CALIB) InjSys_facStoichFlex1_C = 0U;
CONST(UInt16, MFUSP_CALIB) InjSys_facStoichFlex2_C = 0U;
CONST(UInt16, MFUSP_CALIB) InjSys_facStoichGsl_C = 48169U;
CONST(UInt16, MFUSP_CALIB) InjSys_facStoichRichGas_C = 53740U;
CONST(UInt16, MFUSP_CALIB) InjSys_mETBFuMassSlewRate_C = 26844U;
CONST(UInt16, MFUSP_CALIB) InjSys_mETBFuMass_C = 0U;
CONST(UInt16, MFUSP_CALIB) InjSys_mFuMax_C = 26844U;
CONST(UInt16, MFUSP_CALIB) InjSys_mFuMin_C = 0U;
CONST(UInt16, MFUSP_CALIB) InjSys_mFuSpETB_M[256] = { 470U, 470U, 470U, 470U,
  470U, 470U, 470U, 470U, 201U, 201U, 201U, 201U, 201U, 201U, 201U, 201U, 671U,
  671U, 671U, 671U, 671U, 671U, 671U, 671U, 403U, 403U, 403U, 403U, 403U, 403U,
  403U, 403U, 940U, 940U, 940U, 940U, 940U, 940U, 940U, 940U, 403U, 403U, 403U,
  403U, 403U, 403U, 403U, 403U, 1409U, 1409U, 1409U, 1409U, 1409U, 1409U, 1409U,
  1409U, 671U, 671U, 671U, 671U, 671U, 671U, 671U, 671U, 2147U, 2147U, 2147U,
  2147U, 2147U, 2147U, 2147U, 2147U, 1074U, 1074U, 1074U, 1074U, 1074U, 1074U,
  1074U, 1074U, 2684U, 2684U, 2684U, 2684U, 2684U, 2684U, 2684U, 2684U, 1342U,
  1342U, 1342U, 1342U, 1342U, 1342U, 1342U, 1342U, 3087U, 3087U, 3087U, 3087U,
  3087U, 3087U, 3087U, 3087U, 1611U, 1611U, 1611U, 1611U, 1611U, 1611U, 1611U,
  1611U, 3355U, 3355U, 3355U, 3355U, 3355U, 3355U, 3355U, 3355U, 1745U, 1745U,
  1745U, 1745U, 1745U, 1745U, 1745U, 1745U, 3758U, 3758U, 3758U, 3758U, 3758U,
  3758U, 3758U, 3758U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U, 1879U,
  4027U, 4027U, 4027U, 4027U, 4027U, 4027U, 4027U, 4027U, 2013U, 2013U, 2013U,
  2013U, 2013U, 2013U, 2013U, 2013U, 4295U, 4295U, 4295U, 4295U, 4295U, 4295U,
  4295U, 4295U, 2147U, 2147U, 2147U, 2147U, 2147U, 2147U, 2147U, 2147U, 4698U,
  4698U, 4698U, 4698U, 4698U, 4698U, 4698U, 4698U, 2282U, 2282U, 2282U, 2282U,
  2282U, 2282U, 2282U, 2282U, 5100U, 5100U, 5100U, 5100U, 5100U, 5100U, 5100U,
  5100U, 2416U, 2416U, 2416U, 2416U, 2416U, 2416U, 2416U, 2416U, 5369U, 5369U,
  5369U, 5369U, 5369U, 5369U, 5369U, 5369U, 2550U, 2550U, 2550U, 2550U, 2550U,
  2550U, 2550U, 2550U, 5637U, 5637U, 5637U, 5637U, 5637U, 5637U, 5637U, 5637U,
  2684U, 2684U, 2684U, 2684U, 2684U, 2684U, 2684U, 2684U, 6040U, 6040U, 6040U,
  6040U, 6040U, 6040U, 6040U, 6040U, 2819U, 2819U, 2819U, 2819U, 2819U, 2819U,
  2819U, 2819U } ;

#define MFUSP_STOP_SEC_CALIB_16BIT
#include "mFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define MFUSP_START_SEC_CALIB_8BIT
#include "mFuSp_MemMap.h"

CONST(UInt8, MFUSP_CALIB) InjSys_noETBSelMassFuSp_C = 1U;
CONST(UInt8, MFUSP_CALIB) MFUSP_u8Inhib = 1U;

#define MFUSP_STOP_SEC_CALIB_8BIT
#include "mFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define MFUSP_START_SEC_CALIB_BOOLEAN
#include "mFuSp_MemMap.h"

CONST(Boolean, MFUSP_CALIB) InjSys_bAcvETBFuMass_C = 0;
CONST(Boolean, MFUSP_CALIB) InjSys_bInhCorRichETBFuMass_C = 0;

#define MFUSP_STOP_SEC_CALIB_BOOLEAN
#include "mFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define MFUSP_START_SEC_VAR_32BIT
#include "mFuSp_MemMap.h"

VAR(Float32, MFUSP_VAR) InjSys_facStoichFlex_MP;
VAR(Float32, MFUSP_VAR) InjSys_facStoichGas_MP;
VAR(Float32, MFUSP_VAR) InjSys_prm_facInjCmp[2];
VAR(Float32, MFUSP_VAR) InjSys_prm_facStoich[2];
VAR(Float32, MFUSP_VAR) InjSys_prm_mAirPred[2];
VAR(Float32, MFUSP_VAR) InjSys_prm_mFuRawTmp_MP[2];
VAR(Float32, MFUSP_VAR) InjSys_prm_mFuReqCmp_MP[2];
VAR(Float32, MFUSP_VAR) InjSys_prm_mFuReq_MP[2];
VAR(Float32, MFUSP_VAR) InjSys_prm_mFuSp[2];

#define MFUSP_STOP_SEC_VAR_32BIT
#include "mFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define MFUSP_START_SEC_VAR_16BIT
#include "mFuSp_MemMap.h"

VAR(UInt16, MFUSP_VAR) InjSys_mFuSp;
VAR(UInt16, MFUSP_VAR) InjSys_prm_facInjCmpCyl[6];
VAR(UInt16, MFUSP_VAR) InjSys_prm_facInjCmpCylPrev[6];
VAR(UInt16, MFUSP_VAR) InjSys_prm_mCanPurg[2];
VAR(UInt16, MFUSP_VAR) InjSys_prm_mFuSpCyl[6];
VAR(UInt16, MFUSP_VAR) InjSys_prm_mFuSpCylPrev[6];

#define MFUSP_STOP_SEC_VAR_16BIT
#include "mFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define MFUSP_START_SEC_VAR_BOOLEAN
#include "mFuSp_MemMap.h"

VAR(Boolean, MFUSP_VAR) InjSys_bFuSpCylNull;

#define MFUSP_STOP_SEC_VAR_BOOLEAN
#include "mFuSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
