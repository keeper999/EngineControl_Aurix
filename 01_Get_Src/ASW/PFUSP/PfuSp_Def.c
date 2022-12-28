/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pFuSp                                                   */
/* !Description     : pFuSp : Fuel Pressure Set Point                         */
/*                                                                            */
/* !Module          : pFuSp                                                   */
/*                                                                            */
/* !File            : pFuSp_Def.c                                             */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
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
/*   Code generated on: Thu Dec 20 19:22:07 2012                              */
/*   Model name       : pFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.341                                                 */
/*   Root subsystem   : /pFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PFUSP/pFuSp_Def.c_v       $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "pFuSp.h"
#include "pFuSp_private.h"

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
#define PFUSP_START_SEC_CALIB_16BIT
#include "pFuSp_MemMap.h"

CONST(UInt16, PFUSP_CALIB) InjSys_facPresDifMaxInj_T[8] = { 5140U, 5140U,
  5140U, 5140U, 5140U, 5140U, 5140U, 5140U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_nMaxGrdLdSat_C = 4500U;
CONST(UInt16, PFUSP_CALIB) InjSys_pFuDifMaxRailDcha_C = 0U;
CONST(UInt16, PFUSP_CALIB) InjSys_pFuMinRailDcha_C = 0U;
CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal10_M[64] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal11_M[64] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal12_M[64] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal13_M[64] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal14_C = 6400U;
CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal15_C = 6400U;
CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal1_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal2_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal3_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal4_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal5_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal6_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal7_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal8_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpCal9_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpETBSlewRate_C = 19200U;
CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpETB_C = 6400U;
CONST(UInt16, PFUSP_CALIB) InjSys_pFuSpETB_M[256] = { 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U,
  6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U, 6400U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pPresDifLowHys_C = 0U;
CONST(UInt16, PFUSP_CALIB) InjSys_pPresDifMaxInj_A[10] = { 0U, 3200U, 6400U,
  9600U, 12800U, 16000U, 19200U, 22400U, 25600U, 28800U } ;

CONST(UInt16, PFUSP_CALIB) InjSys_pPresDifMaxInj_T[10] = { 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U } ;

CONST(SInt16, PFUSP_CALIB) InjSys_tqMaxNegGrdDcha_C = 3200;
CONST(SInt16, PFUSP_CALIB) InjSys_tqMaxPosGrdDcha_C = 3200;

#define PFUSP_STOP_SEC_CALIB_16BIT
#include "pFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define PFUSP_START_SEC_CALIB_8BIT
#include "pFuSp_MemMap.h"

CONST(UInt8, PFUSP_CALIB) InjSys_idxModPfuSatMax_C = 20U;
CONST(UInt8, PFUSP_CALIB) InjSys_idxModPfuSatMin_C = 1U;
CONST(UInt8, PFUSP_CALIB) InjSys_idxTiPerSplEve_C = 0U;
CONST(UInt8, PFUSP_CALIB) InjSys_noETBSelpFuSp_C = 0U;
CONST(UInt8, PFUSP_CALIB) InjSys_stManAirLdMinSat_C = 0U;
CONST(UInt8, PFUSP_CALIB) InjSys_stManInhInjCutOff_C = 0U;
CONST(UInt8, PFUSP_CALIB) InjSys_stManSpcInjMod_C = 0U;
CONST(UInt8, PFUSP_CALIB) InjSys_tCo_facPresDifMaxInj_A[8] = { 41U, 42U, 43U,
  44U, 45U, 46U, 47U, 48U } ;

CONST(UInt8, PFUSP_CALIB) InjSys_tiDlyAcvSpcInjMod_C = 60U;
CONST(UInt8, PFUSP_CALIB) InjSys_tiPmpCutOffTqLimEM_C = 5U;
CONST(UInt8, PFUSP_CALIB) PFUSP_u8Inhib = 0U;

#define PFUSP_STOP_SEC_CALIB_8BIT
#include "pFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define PFUSP_START_SEC_CALIB_BOOLEAN
#include "pFuSp_MemMap.h"

CONST(Boolean, PFUSP_CALIB) InjSys_bAcvAirLdMinSatDcha_C = 0;
CONST(Boolean, PFUSP_CALIB) InjSys_bAcvAirLdMinSat_C = 0;
CONST(Boolean, PFUSP_CALIB) InjSys_bAcvETBpFuSp_C = 0;
CONST(Boolean, PFUSP_CALIB) InjSys_bAcvMonMisfSpcInjMod_C = 0;
CONST(Boolean, PFUSP_CALIB) InjSys_bAcvPmpCutTqLimEM_C = 1;
CONST(Boolean, PFUSP_CALIB) InjSys_bAcvSpcInjMod_C = 0;
CONST(Boolean, PFUSP_CALIB) InjSys_bAuthAirLdMinSat_C = 1;
CONST(Boolean, PFUSP_CALIB) InjSys_bInhDifFuRailDCha_C = 1;
CONST(Boolean, PFUSP_CALIB) InjSys_bInhInjCutOff_C = 0;

#define PFUSP_STOP_SEC_CALIB_BOOLEAN
#include "pFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define PFUSP_START_SEC_VAR_32BIT
#include "pFuSp_MemMap.h"

VAR(Float32, PFUSP_VAR) InjSys_pFuSpBas1ModCur;
VAR(Float32, PFUSP_VAR) InjSys_pFuSpBas1ModTar;
VAR(Float32, PFUSP_VAR) InjSys_pFuSpBas2ModCur;
VAR(Float32, PFUSP_VAR) InjSys_pFuSpBas2ModTar;
VAR(Float32, PFUSP_VAR) InjSys_pFuSpModCur_MP;
VAR(Float32, PFUSP_VAR) InjSys_pFuSpModTar_MP;
VAR(Float32, PFUSP_VAR) InjSys_tiTDCPmp;
VAR(Float32, PFUSP_VAR) TqLimEM_tqLimEMPrec;

#define PFUSP_STOP_SEC_VAR_32BIT
#include "pFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define PFUSP_START_SEC_VAR_16BIT
#include "pFuSp_MemMap.h"

VAR(UInt16, PFUSP_VAR) InjSys_pFuSp;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal1;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal10;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal11;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal12;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal13;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal14;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal15;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal2;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal3;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal4;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal5;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal6;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal7;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal8;
VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal9;
VAR(UInt16, PFUSP_VAR) InjSys_prm_pFuSpCal[15];

#define PFUSP_STOP_SEC_VAR_16BIT
#include "pFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define PFUSP_START_SEC_VAR_BOOLEAN
#include "pFuSp_MemMap.h"

VAR(Boolean, PFUSP_VAR) InjSys_bAcvAirLdMinSat;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvAirLdMinSatTmp;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvCllRailDcha;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal1;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal10;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal11;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal12;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal13;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal14;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal15;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal2;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal3;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal4;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal5;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal6;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal7;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal8;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal9;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvSpcInjMod;
VAR(Boolean, PFUSP_VAR) InjSys_bAcvSpcInjModTmp;
VAR(Boolean, PFUSP_VAR) InjSys_bCanPurgCutOff;
VAR(Boolean, PFUSP_VAR) InjSys_bHPPmpCutOff;
VAR(Boolean, PFUSP_VAR) InjSys_bInhAirLdMinSat;
VAR(Boolean, PFUSP_VAR) InjSys_bInhInjCutOffPFuDcha;
VAR(Boolean, PFUSP_VAR) InjSys_bInhInjCutOffTmp;
VAR(Boolean, PFUSP_VAR) InjSys_bInhSpcInjMod;
VAR(Boolean, PFUSP_VAR) InjSys_bInjSpNotAccu;
VAR(Boolean, PFUSP_VAR) InjSys_prm_bAcvPfuSpCal[15];

#define PFUSP_STOP_SEC_VAR_BOOLEAN
#include "pFuSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/