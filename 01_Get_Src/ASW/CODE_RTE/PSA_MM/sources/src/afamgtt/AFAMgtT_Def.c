/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT                                                 */
/*                                                                            */
/* !File            : AFAMgtT_Def.c                                           */
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
/*   Model name       : AFAMgtT_SWC.mdl                                       */
/*   Root subsystem   : /AFAMgtT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   05 May 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT.h"
#include "AFAMgtT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CARTO_32BIT" */
#define AFAMgtT_START_SEC_CARTO_32BIT
#include "AFAMgtT_MemMap.h"

CONST(UInt32, AFAMGTT_CARTO) AFAMgt_pDifInjr_A[9] = { 64U, 77U, 90U, 102U,
  115U, 128U, 141U, 154U, 166U } ;

CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyCanPurgClsFast_C = 1792U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyCanPurgClsSlow_C = 2611U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyLstObsDftThd_C = 2560U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyNotDynCorPres_C = 698U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabAirLd_C = 499U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabEOM_C = 400U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabEgdGear_C = 1798U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabFacStrt_C = 400U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabFuMod_C = 410U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabRatOpEGR_C = 6U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiInjLoThd_T[9] = { 313U, 313U, 313U, 313U,
  313U, 313U, 313U, 313U, 313U } ;

CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiMinDlyStabAirMod_C = 5990U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiObsThd1_C = 313U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiObsThd2_C = 313U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiObsThd3_C = 313U;
CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiObsThd4_C = 313U;

#define AFAMgtT_STOP_SEC_CARTO_32BIT
#include "AFAMgtT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define AFAMgtT_START_SEC_CARTO_16BIT
#include "AFAMgtT_MemMap.h"

CONST(UInt16, AFAMGTT_CARTO) AFAMgt_facCorGainLnrThd_T[9] = { 1638U, 1638U,
  1638U, 1638U, 1638U, 1638U, 1638U, 1638U, 1638U } ;

CONST(UInt16, AFAMGTT_CARTO) AFAMgt_facStrtCorCylThd_C = 4369U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_nEngLstObsThd_C = 480U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_noFirstObsDoneThd_C = 21U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_noObsDoneThd_C = 10U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_pDsThrMaxThd_C = 11250U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_pDsThrMinThd_C = 2496U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_pDynCorMaxThd_C = 438U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rAirLdDeltaMaxThd_C = 896U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rTotLdCorLstObsThd_C = 768U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rlamReqMaxThd_C = 4U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rlamReqMinThd_C = 4369U;
CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rltMassAirScvMaxThd_C = 0U;
CONST(UInt16, AFAMGTT_CARTO) Air_pRef_C = 164U;

#define AFAMgtT_STOP_SEC_CARTO_16BIT
#include "AFAMgtT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define AFAMgtT_START_SEC_CARTO_8BIT
#include "AFAMgtT_MemMap.h"

CONST(UInt8, AFAMGTT_CARTO) AFAMgt_rDeltaLdInjPhaObsThd_C = 8U;
CONST(UInt8, AFAMGTT_CARTO) AFAMgt_rOpEGRDeltaMaxThd_C = 255U;
CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tAirMaxThd_C = 125U;
CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tAirMinThd_C = 50U;
CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tCoMaxThd_C = 150U;
CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tCoMinThd_C = 85U;
CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tiDecAdpObsDft_C = 255U;
CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tiIncAdpObsDft_C = 1U;

#define AFAMgtT_STOP_SEC_CARTO_8BIT
#include "AFAMgtT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AFAMgtT_START_SEC_CALIB_BOOLEAN
#include "AFAMgtT_MemMap.h"

CONST(Boolean, AFAMGTT_CALIB) AFAMGTT_ACTIVE_BYP_C = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAcvAdpRstDiag_B = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAdpClcRstReq_B = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAdpEfcReq_B = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAdpObsReq_B = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAdpOfsRstReq_B = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAuthAdpReq_B = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bIdcInjrMdlCnd_B = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bIdcTmpObsCnd_B = 0;
CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bInhAFA_B = 0;

#define AFAMgtT_STOP_SEC_CALIB_BOOLEAN
#include "AFAMgtT_MemMap.h"

/* !Comment: Define data in section "CARTO_BOOLEAN" */
#define AFAMgtT_START_SEC_CARTO_BOOLEAN
#include "AFAMgtT_MemMap.h"

CONST(Boolean, AFAMGTT_CARTO) AFAMgt_bInhAFA_C = 0;
CONST(Boolean, AFAMGTT_CARTO) AFAMgt_bInhAdpEfc_C = 0;

#define AFAMgtT_STOP_SEC_CARTO_BOOLEAN
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
