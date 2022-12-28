/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : IfEOMInjSp                                              */
/* !Description     : CALCUL DES MASSES D ESSENCE À INJECTER                  */
/*                                                                            */
/* !Module          : IfEOMInjSp                                              */
/*                                                                            */
/* !File            : IfEOMInjSp_Def.c                                        */
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
/*   Code generated on: Fri Jun 01 12:04:59 2012                              */
/*   Model name       : IfEOMInjSp_AUTOCODE.mdl                               */
/*   Model version    : 1.102                                                 */
/*   Root subsystem   : /IfEOMInjSp                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/IFEOMINJSP/IfEOMInjSp_Def.$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   06 Jun 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "IfEOMInjSp.h"
#include "IfEOMInjSp_private.h"

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
#define IFEOMINJSP_START_SEC_CALIB_16BIT
#include "IfEOMInjSp_MemMap.h"

CONST(UInt16, IFEOMINJSP_CALIB) InjSys_mAirDBInjSp_C = 0U;
CONST(UInt16, IFEOMINJSP_CALIB) InjSys_nEngDBInjSp_C = 20U;

#define IFEOMINJSP_STOP_SEC_CALIB_16BIT
#include "IfEOMInjSp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define IFEOMINJSP_START_SEC_CALIB_8BIT
#include "IfEOMInjSp_MemMap.h"

CONST(UInt8, IFEOMINJSP_CALIB) IfEOMInjSp_u8Inhib = 0U;

#define IFEOMINJSP_STOP_SEC_CALIB_8BIT
#include "IfEOMInjSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define IFEOMINJSP_START_SEC_VAR_16BIT
#include "IfEOMInjSp_MemMap.h"

VAR(UInt16, IFEOMINJSP_VAR) InjSys_mAirPredInjSp;
VAR(UInt16, IFEOMINJSP_VAR) InjSys_nEngInjSp;

#define IFEOMINJSP_STOP_SEC_VAR_16BIT
#include "IfEOMInjSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define IFEOMINJSP_START_SEC_VAR_8BIT
#include "IfEOMInjSp_MemMap.h"

VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModCurAgInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModCurPfuSp;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModCurRatInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModTarAgInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModTarPfuSp;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_facBasModTarRatInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_facTranModAgInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_facTranModPfuSp;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_facTranModRatInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModCurAgInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModCurPfuSp;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModCurRatInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModTarAgInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModTarPfuSp;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas1ModTarRatInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModCurAgInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModCurPfuSp;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModCurRatInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModTarAgInj;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModTarPfuSp;
VAR(UInt8, IFEOMINJSP_VAR) InjSys_idxBas2ModTarRatInj;

#define IFEOMINJSP_STOP_SEC_VAR_8BIT
#include "IfEOMInjSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
