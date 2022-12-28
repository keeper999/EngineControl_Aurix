/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjCutOffMgr                                            */
/* !Description     : GESTION DE LA COUPURE DES INJECTEURS                    */
/*                                                                            */
/* !Module          : InjCutOffMgr                                            */
/*                                                                            */
/* !File            : InjCutOffMgr_Def.c                                      */
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
/*   Code generated on: Mon Mar 25 22:22:41 2013                              */
/*   Model name       : InjCutOffMgr_AUTOCODE.mdl                             */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /InjCutOffMgr                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJCUTOFFMGR/InjCutOffMgr_$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   27 Mar 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjCutOffMgr.h"
#include "InjCutOffMgr_private.h"

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
#define INJCUTOFFMGR_START_SEC_CALIB_16BIT
#include "InjCutOffMgr_MemMap.h"

CONST(SInt16, INJCUTOFFMGR_CALIB) InjSys_mAirMinInhCutOff_C = 2097;
CONST(UInt16, INJCUTOFFMGR_CALIB) InjSys_tiDlyInjCutOff_T[9] = { 12000U,
  10000U, 8000U, 6000U, 4000U, 2000U, 1000U, 500U, 0U } ;

#define INJCUTOFFMGR_STOP_SEC_CALIB_16BIT
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define INJCUTOFFMGR_START_SEC_CALIB_8BIT
#include "InjCutOffMgr_MemMap.h"

CONST(UInt8, INJCUTOFFMGR_CALIB) Fco_regul_rich_regime_thresh = 125U;
CONST(UInt8, INJCUTOFFMGR_CALIB) INJCUTOFFMGR_u8Inhib = 0U;
CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_GearEgd_A[6] = { 0U, 1U, 2U, 3U, 4U,
  5U } ;

CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_bInhCylCutOff_T[6] = { 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_bInhTWCTotCutOff_T[6] = { 0U, 0U, 0U,
  0U, 0U, 0U } ;

CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_noInNxtCyl_A[6] = { 1U, 2U, 3U, 4U, 5U,
  6U } ;

CONST(UInt8, INJCUTOFFMGR_CALIB) InjSys_noInNxtNxtNxtCyl_T[6] = { 2U, 3U, 1U,
  4U, 4U, 4U } ;

#define INJCUTOFFMGR_STOP_SEC_CALIB_8BIT
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define INJCUTOFFMGR_START_SEC_CALIB_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

CONST(Boolean, INJCUTOFFMGR_CALIB) InjCutOff_bAcvInjCutOffSTTEs_C = 0;
CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bAcvPrioProtAC_C = 0;
CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bETBAcvTotCutOff_C = 0;
CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaSelCutASRSecu_C = 1;
CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaSelCutASR_C = 1;
CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaSelCutSIP_C = 1;
CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaTotCutASRSecu_C = 1;
CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaTotCutASR_C = 1;
CONST(Boolean, INJCUTOFFMGR_CALIB) InjSys_bEnaTotCutSIP_C = 1;

#define INJCUTOFFMGR_STOP_SEC_CALIB_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define INJCUTOFFMGR_START_SEC_VAR_8BIT
#include "InjCutOffMgr_MemMap.h"

VAR(UInt8, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj;
VAR(UInt8, INJCUTOFFMGR_VAR) InjSys_noCylCutOff;
VAR(SInt8, INJCUTOFFMGR_VAR) InjSys_noCylCutOffTarSub;
VAR(UInt8, INJCUTOFFMGR_VAR) InjSys_noInNxtNxtNxtCyl;

#define INJCUTOFFMGR_STOP_SEC_VAR_8BIT
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define INJCUTOFFMGR_START_SEC_VAR_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

VAR(Boolean, INJCUTOFFMGR_VAR) Auto_injection;
VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj_cyl1;
VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj_cyl2;
VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj_cyl3;
VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj_cyl4;
VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_inj_ess_1;
VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_inj_ess_2;
VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_inj_ess_3;
VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_inj_ess_4;
VAR(Boolean, INJCUTOFFMGR_VAR) Fco_for_mf_cat_dam_actif;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bAcvCutOffTyp1;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bAcvCutOff_MP;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bCutOffCyl1Raw;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bCutOffCyl2Raw;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bCutOffCyl3Raw;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bCutOffCyl4Raw;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bForcFuCutOff;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bFuCutOff;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bInhCutOffAirMin;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bInhCutOffTar;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bInjCutOffRaw;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bTotCutOff;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bTotCutOffDftMod;
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_prm_bAcvCutOffTarCyl[4];
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_prm_bAcvCutOffTarCylPrev[4];
VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_prm_bCylCutOff[6];

#define INJCUTOFFMGR_STOP_SEC_VAR_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
