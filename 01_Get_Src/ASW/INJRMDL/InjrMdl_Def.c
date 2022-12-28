/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjrMdl                                                 */
/* !Description     : InjSys - MODELE INJECTEUR (GDI)                         */
/*                                                                            */
/* !Module          : InjrMdl                                                 */
/*                                                                            */
/* !File            : InjrMdl_Def.c                                           */
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
/*   Code generated on: Wed Mar 13 19:55:28 2013                              */
/*   Model name       : InjrMdl_AUTOCODE.mdl                                  */
/*   Model version    : 1.280                                                 */
/*   Root subsystem   : /InjrMdl                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjrMdl/5-SOFT-LIV/InjrMdl_D$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   18 Mar 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjrMdl.h"
#include "InjrMdl_private.h"

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
#define INJRMDL_START_SEC_CALIB_16BIT
#include "InjrMdl_MemMap.h"

CONST(UInt16, INJRMDL_CALIB) InjrM_facCorGainLnrInjTFu_T[16] = { 29491U,
  29819U, 30147U, 30638U, 31130U, 31785U, 32276U, 32768U, 33096U, 34079U, 35389U,
  36045U, 36700U, 37683U, 39322U, 40960U } ;

CONST(UInt16, INJRMDL_CALIB) InjrM_facCorOfsuBatt_T[9] = { 19661U, 22938U,
  26214U, 29491U, 32768U, 36045U, 39322U, 42598U, 45875U } ;

CONST(UInt16, INJRMDL_CALIB) InjrM_facGainInjH1ETB_C = 6400U;
CONST(UInt16, INJRMDL_CALIB) InjrM_facGainInjH2ETB_C = 6400U;
CONST(UInt16, INJRMDL_CALIB) InjrM_facGainInjS1ETB_C = 6400U;
CONST(UInt16, INJRMDL_CALIB) InjrM_facGainInjS2ETB_C = 6400U;
CONST(SInt16, INJRMDL_CALIB) InjrM_tiInjOfsInjH1ETB_C = 9;
CONST(SInt16, INJRMDL_CALIB) InjrM_tiInjOfsInjH2ETB_C = 9;
CONST(SInt16, INJRMDL_CALIB) InjrM_tiInjOfsInjS1ETB_C = 9;
CONST(SInt16, INJRMDL_CALIB) InjrM_tiInjOfsInjS2ETB_C = 9;

#define INJRMDL_STOP_SEC_CALIB_16BIT
#include "InjrMdl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define INJRMDL_START_SEC_CALIB_8BIT
#include "InjrMdl_MemMap.h"

CONST(UInt8, INJRMDL_CALIB) INJRMDL_u8Inhib = 0U;

#define INJRMDL_STOP_SEC_CALIB_8BIT
#include "InjrMdl_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define INJRMDL_START_SEC_CALIB_BOOLEAN
#include "InjrMdl_MemMap.h"

CONST(Boolean, INJRMDL_CALIB) InjrM_bAcvInjMdlETB_C = 0;

#define INJRMDL_STOP_SEC_CALIB_BOOLEAN
#include "InjrMdl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define INJRMDL_START_SEC_VAR_16BIT
#include "InjrMdl_MemMap.h"

VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainH1CylPrev[6];
VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainH2CylPrev[6];
VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInj[4];
VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInjH1Cyl[6];
VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInjH2Cyl[6];
VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInjS1Cyl[6];
VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainInjS2Cyl[6];
VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainS1CylPrev[6];
VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainS2CylPrev[6];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsH1CylPrev[6];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsH2CylPrev[6];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInj[4];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInjH1Cyl[6];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInjH2Cyl[6];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInjS1Cyl[6];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsInjS2Cyl[6];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsS1CylPrev[6];
VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsS2CylPrev[6];

#define INJRMDL_STOP_SEC_VAR_16BIT
#include "InjrMdl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define INJRMDL_START_SEC_VAR_BOOLEAN
#include "InjrMdl_MemMap.h"

VAR(Boolean, INJRMDL_VAR) InjrM_bInhInjrMUpd;

#define INJRMDL_STOP_SEC_VAR_BOOLEAN
#include "InjrMdl_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define INJRMDL_START_SEC_VAR_32BIT
#include "InjrMdl_MemMap.h"

VAR(Float32, INJRMDL_VAR) InjrM_prm_facGainLnrInj[4];
VAR(Float32, INJRMDL_VAR) InjrM_prm_mfFuStndAdp_MP[4];

#define INJRMDL_STOP_SEC_VAR_32BIT
#include "InjrMdl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
