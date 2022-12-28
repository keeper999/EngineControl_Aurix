/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : DmpVlv_H                                                */
/* !Description     : DmpVlv_H Software Component                             */
/*                                                                            */
/* !Module          : DmpVlv_H                                                */
/*                                                                            */
/* !File            : DmpVlv_H_Def.c                                          */
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
/*   Model name       : DmpVlv_H_AUTOSAR.mdl                                  */
/*   Root subsystem   : /DmpVlv_H                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M12-DmpVlvH/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "DmpVlv_H.h"
#include "DmpVlv_H_private.h"

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
#define DmpVlv_H_START_SEC_CALIB_32BIT
#include "DmpVlv_H_MemMap.h"

CONST(UInt32, DMPVLV_H_CALIB) DmpVlv_mfAirThrReqThd_C = 65552U;

#define DmpVlv_H_STOP_SEC_CALIB_32BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define DmpVlv_H_START_SEC_CARTO_16BIT
#include "DmpVlv_H_MemMap.h"

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_facFilMv_M[8][7] = { { 400U, 400U, 400U, 400U,
  400U, 400U, 400U },{ 400U, 400U, 400U, 400U, 400U, 400U, 400U },{ 400U, 400U, 400U,
  400U, 400U, 400U, 400U },{ 400U, 400U, 400U, 400U, 400U, 400U, 400U },{ 400U, 400U,
  400U, 400U, 400U, 400U, 400U },{ 400U, 400U, 400U, 400U, 400U, 400U, 400U },{ 400U,
  400U, 400U, 400U, 400U, 400U, 400U },{ 400U, 400U, 400U, 400U, 400U, 400U, 400U } }
;

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_mfCmprCorAnt_A[16] = { 0U, 655U, 983U,
  1210U, 1437U, 1664U, 1890U, 2117U, 2344U, 2571U, 2798U, 3025U, 3252U, 3478U,
  3705U, 3932U } ;

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_mfCmprCor_A[16] = { 0U, 655U, 983U, 1210U,
  1437U, 1664U, 1890U, 2117U, 2344U, 2571U, 2798U, 3025U, 3252U, 3478U, 3705U,
  3932U } ;

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_mfDeltaAirReqFil_A[7] = { 0U, 13107U,
  19661U, 26214U, 32768U, 39322U, 65535U } ;

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_nEng_A[8] = { 800U, 1800U, 2000U, 3000U,
  4000U, 5000U, 6000U, 6500U } ;

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_rPresCmprAnt_T[16] = { 8438U, 8438U,
  10240U, 11530U, 12569U, 12681U, 13626U, 14485U, 15298U, 16112U, 16820U, 17746U,
  18672U, 19595U, 20521U, 21447U } ;

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_rPresCmpr_T[16] = { 8192U, 8192U, 10240U,
  11530U, 12569U, 13872U, 15264U, 16472U, 17503U, 18644U, 20133U, 21506U, 22719U,
  23931U, 25371U, 26842U } ;

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_rTCmprCor_A[16] = { 6390U, 6646U, 6903U,
  7160U, 7416U, 7673U, 7930U, 8187U, 8443U, 8700U, 8957U, 9213U, 9470U, 9727U,
  9983U, 10240U } ;

CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_rTCmprSqrt_T[16] = { 7235U, 7379U, 7520U,
  7659U, 7795U, 7928U, 8060U, 8189U, 8317U, 8442U, 8566U, 8688U, 8808U, 8926U,
  9043U, 9159U } ;

CONST(SInt16, DMPVLV_H_CARTO) DmpVlv_tqLoThd_T[8] = { 160, 160, 160, 160, 160,
  160, 160, 160 } ;

#define DmpVlv_H_STOP_SEC_CARTO_16BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define DmpVlv_H_START_SEC_CALIB_16BIT
#include "DmpVlv_H_MemMap.h"

CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilMfAirThrReq1_C = 30U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilMfAirThrReq2_C = 70U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilMfAirThrReq_C = 60U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilRateDownUp_C = 1000U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilRateUpDown_C = 50U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facGainSat_C = 1000U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_mfAirThrSatMin_C = 0U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_pCmprRef_C = 12663U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_rAirLdLimSurgeReq_B = 0U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_rPresCmprHysAnt_C = 819U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_rPresCmprHys_C = 819U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_tCmprRef_C = 9600U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_tiDmpVlvTmrAnt_C = 4096U;
CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_tiDmpVlvTmr_C = 2458U;
CONST(SInt16, DMPVLV_H_CALIB) DmpVlv_tqOfsHiThd_C = 160;

#define DmpVlv_H_STOP_SEC_CALIB_16BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define DmpVlv_H_START_SEC_CALIB_BOOLEAN
#include "DmpVlv_H_MemMap.h"

CONST(Boolean, DMPVLV_H_CALIB) DMPVLV_H_ACTIVE_BYP_C = 0;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvCdnTq_C = 1;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvDetPmp_C = 0;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvDftMod_C = 0;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvDmpVlvTestMod_C = 1;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvDmpVlv_B = 0;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvTestMod_C = 0;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bDmpVlvDftMod_C = 0;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bSelCdnTq_C = 1;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bSelDetPmp_C = 1;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bSelMfCmprAnt_C = 0;
CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bSelMfCmpr_C = 1;

#define DmpVlv_H_STOP_SEC_CALIB_BOOLEAN
#include "DmpVlv_H_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define DmpVlv_H_START_SEC_INTERNAL_VAR_32BIT
#include "DmpVlv_H_MemMap.h"

VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_facFilRate = 0.0F;
VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReq = 0.0F;
VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReqAnt = 0.0F;
VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReqAntSat = 0.0F;
VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReqFil = 0.0F;
VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfCmprCor = 0.0F;
VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfCmprCorFil = 0.0F;
VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_rPresCmpr = 0.0F;

#define DmpVlv_H_STOP_SEC_INTERNAL_VAR_32BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define DmpVlv_H_START_SEC_INTERNAL_VAR_16BIT
#include "DmpVlv_H_MemMap.h"

VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReqOfs_MP = 0U;
VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfDeltaAirReqFil_MP = 0U;
VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_rTCmprCor_MP = 0U;
VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_tiDmpVlvAcvTmrPrev = 0U;
VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_tiDmpVlvAcvTmr_IRV_MP = 0U;

#define DmpVlv_H_STOP_SEC_INTERNAL_VAR_16BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define DmpVlv_H_START_SEC_INTERNAL_VAR_BOOLEAN
#include "DmpVlv_H_MemMap.h"

VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bAcvDmpVlvRaw = FALSE;
VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bDetPmpAr = FALSE;
VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bDetPmpArAnt_MP = FALSE;
VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bDetPmpAr_MP = FALSE;
VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bDetTqThd = FALSE;

#define DmpVlv_H_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "DmpVlv_H_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
