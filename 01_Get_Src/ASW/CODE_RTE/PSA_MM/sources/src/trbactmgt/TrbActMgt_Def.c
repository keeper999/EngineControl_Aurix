/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActMgt                                               */
/* !Description     : TrbActMgt Software Component                            */
/*                                                                            */
/* !Module          : TrbActMgt                                               */
/*                                                                            */
/* !File            : TrbActMgt_Def.c                                         */
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
/*   Model name       : TrbActMgt_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActMgt                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M13-TrbActMgt/5-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TrbActMgt.h"
#include "TrbActMgt_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CARTO_16BIT" */
#define TrbActMgt_START_SEC_CARTO_16BIT
#include "TrbActMgt_MemMap.h"

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facFfGain_M[9][9] = { { 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },
{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facFilGainUsThrPresMes_T[9] = { 65529U,
  65529U, 65529U, 65529U, 65529U, 65529U, 65529U, 65529U, 65529U } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facPresAltiCor_T[9] = { 32765U, 32765U,
  32765U, 32765U, 32765U, 32765U, 32765U, 32765U, 32765U } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain1ErrPresEth_M[9][9] = { { 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },
{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain1ErrPres_M[9][9] = { { 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain1_M[9][9] = { { 14534U, 14534U,
  14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U },{ 14534U, 14534U, 14534U,
  14534U, 14534U, 14534U, 14534U, 14534U, 14534U },{ 14534U, 14534U, 14534U, 14534U,
  14534U, 14534U, 14534U, 14534U, 14534U },{ 14534U, 14534U, 14534U, 14534U, 14534U,
  14534U, 14534U, 14534U, 14534U },{ 14534U, 14534U, 14534U, 14534U, 14534U, 14534U,
  14534U, 14534U, 14534U },{ 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U,
  14534U, 14534U },{ 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U,
  14534U },{ 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U },
{ 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U, 14534U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain2ErrPresEth_M[9][9] = { { 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },
{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain2ErrPres_M[9][9] = { { 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain2_M[9][9] = { { 6219U, 6219U, 6219U,
  6219U, 6219U, 6219U, 6219U, 6219U, 6219U },{ 6219U, 6219U, 6219U, 6219U, 6219U,
  6219U, 6219U, 6219U, 6219U },{ 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U,
  6219U, 6219U },{ 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U },
{ 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U },{ 6219U, 6219U,
  6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U },{ 6219U, 6219U, 6219U, 6219U,
  6219U, 6219U, 6219U, 6219U, 6219U },{ 6219U, 6219U, 6219U, 6219U, 6219U, 6219U,
  6219U, 6219U, 6219U },{ 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U, 6219U,
  6219U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_faciGainErrPresEth_M[9][9] = { { 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },
{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_faciGainErrPres_M[9][9] = { { 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U, 8192U, 8192U },{ 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U,
  8192U, 8192U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_faciGain_M[9][9] = { { 582U, 582U, 582U,
  582U, 582U, 582U, 582U, 582U, 582U },{ 582U, 582U, 582U, 582U, 582U, 582U, 582U,
  582U, 582U },{ 582U, 582U, 582U, 582U, 582U, 582U, 582U, 582U, 582U },{ 582U, 582U,
  582U, 582U, 582U, 582U, 582U, 582U, 582U },{ 582U, 582U, 582U, 582U, 582U, 582U,
  582U, 582U, 582U },{ 582U, 582U, 582U, 582U, 582U, 582U, 582U, 582U, 582U },{ 582U,
  582U, 582U, 582U, 582U, 582U, 582U, 582U, 582U },{ 582U, 582U, 582U, 582U, 582U,
  582U, 582U, 582U, 582U },{ 582U, 582U, 582U, 582U, 582U, 582U, 582U, 582U, 582U } }
;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facpGainErrPresEth_M[9][9] = { { 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },
{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facpGainErrPres_M[9][9] = { { 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U, 2048U, 2048U },{ 2048U, 2048U, 2048U, 2048U, 2048U, 2048U, 2048U,
  2048U, 2048U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facpGain_M[9][9] = { { 5568U, 5568U, 5568U,
  5568U, 5568U, 5568U, 5568U, 5568U, 5568U },{ 5568U, 5568U, 5568U, 5568U, 5568U,
  5568U, 5568U, 5568U, 5568U },{ 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U,
  5568U, 5568U },{ 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U },
{ 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U },{ 5568U, 5568U,
  5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U },{ 5568U, 5568U, 5568U, 5568U,
  5568U, 5568U, 5568U, 5568U, 5568U },{ 5568U, 5568U, 5568U, 5568U, 5568U, 5568U,
  5568U, 5568U, 5568U },{ 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U, 5568U,
  5568U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_nEngCtl_A[9] = { 800U, 1000U, 1500U,
  2000U, 2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(SInt16, TRBACTMGT_CARTO) TrbAct_nEngGrd_A[9] = { 100, 200, 300, 400, 500,
  600, 700, 800, 900 } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_nEngRef2_A[9] = { 800U, 1000U, 1500U,
  2000U, 2500U, 3000U, 4000U, 5000U, 6000U } ;

CONST(SInt16, TRBACTMGT_CARTO) TrbAct_pErrUsThr2_A[9] = { 1250, 2500, 3750,
  5000, 6250, 7500, 8750, 10000, 11250 } ;

CONST(SInt16, TRBACTMGT_CARTO) TrbAct_pErrUsThrGrd_A[9] = { -625, -375, -250,
  -125, 0, 125, 250, 375, 625 } ;

CONST(SInt16, TRBACTMGT_CARTO) TrbAct_pErrUsThr_A[9] = { 1250, 2500, 3750, 5000,
  6250, 7500, 8750, 10000, 11250 } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_pInMnfReqThdEth_T[9] = { 13750U, 13750U,
  13750U, 13750U, 13750U, 13750U, 13750U, 13750U, 13750U } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_pInMnfReqThd_T[9] = { 13750U, 13750U,
  13750U, 13750U, 13750U, 13750U, 13750U, 13750U, 13750U } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_pUsThrCllAcvThd_T[9] = { 13750U, 13750U,
  13750U, 13750U, 13750U, 13750U, 13750U, 13750U, 13750U } ;

CONST(SInt16, TRBACTMGT_CARTO) TrbAct_tCoMes_A[9] = { 60, 70, 80, 90, 100, 110,
  120, 130, 140 } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_tiStrtThd_M[9][9] = { { 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },
{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U } } ;

CONST(UInt16, TRBACTMGT_CARTO) TrbAct_tiStrtThd_T[9] = { 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U } ;

#define TrbActMgt_STOP_SEC_CARTO_16BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define TrbActMgt_START_SEC_CALIB_16BIT
#include "TrbActMgt_MemMap.h"

CONST(UInt16, TRBACTMGT_CALIB) TrbAct_facFltErrPres_C = 65535U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_facPresAltiCor_B = 0U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_facPresRCOCnv_C = 32768U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_nEngTrbActCmdHys_C = 50U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_nEngTrbActCmdThd_C = 800U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pAirExtHys_C = 625U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pDifUsThrPresHiThd_C = 750U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pDifUsThrPresLoThd_C = 1250U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pInMnfReqHys_C = 2500U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pOilMesThd_C = 3125U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrCorReqTest_C = 18750U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrCorReq_B = 0U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrFil_B = 0U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrICorReqHiThd_C = 37500U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrICorReqLoThd_C = 65535U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_rOpTrbActHiThd_C = 62259U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_rOpTrbActLoThd_C = 3277U;
CONST(SInt16, TRBACTMGT_CALIB) TrbAct_rRCOICorReq_B = 0;
CONST(SInt16, TRBACTMGT_CALIB) TrbAct_rRCOICorReq_C = 0;
CONST(SInt16, TRBACTMGT_CALIB) TrbAct_rRCOPIDCorReq_B = 0;
CONST(SInt16, TRBACTMGT_CALIB) TrbAct_rRCOPIDCorReq_C = 0;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_tiDlyPosnTrbActMod_C = 8192U;
CONST(UInt16, TRBACTMGT_CALIB) TrbAct_tiStrtThd_C = 1U;

#define TrbActMgt_STOP_SEC_CALIB_16BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define TrbActMgt_START_SEC_CARTO_8BIT
#include "TrbActMgt_MemMap.h"

CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctCor_T[8] = { 0U, 18U, 36U,
  54U, 72U, 90U, 108U, 128U } ;

CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctCtl_A[8] = { 0U, 18U, 36U,
  54U, 72U, 90U, 108U, 128U } ;

CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctDftl1_T[8] = { 0U, 18U, 36U,
  54U, 72U, 90U, 108U, 128U } ;

CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctDftl2_T[8] = { 0U, 18U, 36U,
  54U, 72U, 90U, 108U, 128U } ;

CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctInt_T[8] = { 0U, 18U, 36U,
  54U, 72U, 90U, 108U, 128U } ;

CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctProp_T[8] = { 0U, 18U, 36U,
  54U, 72U, 90U, 108U, 128U } ;

CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExct_A[8] = { 0U, 18U, 36U, 54U,
  72U, 90U, 108U, 128U } ;

CONST(SInt8, TRBACTMGT_CARTO) TrbAct_tAir_A[9] = { -40, -20, 0, 10, 20, 30, 40,
  60, 80 } ;

#define TrbActMgt_STOP_SEC_CARTO_8BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define TrbActMgt_START_SEC_CALIB_BOOLEAN
#include "TrbActMgt_MemMap.h"

CONST(Boolean, TRBACTMGT_CALIB) TRBACTMGT_ACTIVE_BYP_C = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvCtlEth_C = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvEth_C = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvInhICor_C = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvOilPresCtl_C = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvTrbActCmd_B = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvUsThrPresCorTest_C = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bBoostPresClCtlAcv_B = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bInhCllCtl_C = 1;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bInhICor_B = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bInhUsReg_C = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bPosnTrbActMod_B = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bSelInhICnd_C = 0;
CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bSelPresErrReq_C = 1;

#define TrbActMgt_STOP_SEC_CALIB_BOOLEAN
#include "TrbActMgt_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define TrbActMgt_START_SEC_INTERNAL_VAR_32BIT
#include "TrbActMgt_MemMap.h"

VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facFfGain = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facdGain1 = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facdGain1Ref = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facdGain2 = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facdGain2Ref = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_faciGain = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_faciGainRef = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facpGain = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facpGainRef = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pErrUsThr = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pInMnfReqThd = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pInMnfReqThdEth = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrCorReqPrev = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrDCorReq = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrFfCorReq = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrICorReqIni = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrICorReqPrev = 0.0F;
VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrPCorReq = 0.0F;

#define TrbActMgt_STOP_SEC_INTERNAL_VAR_32BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define TrbActMgt_START_SEC_INTERNAL_VAR_16BIT
#include "TrbActMgt_MemMap.h"

VAR(SInt16, TRBACTMGT_INTERNAL_VAR) TrbAct_pErrFltGrd_MP = 0;
VAR(SInt16, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrICorReq_IRV_MP = 0;

#define TrbActMgt_STOP_SEC_INTERNAL_VAR_16BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define TrbActMgt_START_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActMgt_MemMap.h"

VAR(Boolean, TRBACTMGT_INTERNAL_VAR) TrbAct_bDetTran = FALSE;
VAR(Boolean, TRBACTMGT_INTERNAL_VAR) TrbAct_bRstICor = FALSE;

#define TrbActMgt_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActMgt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
