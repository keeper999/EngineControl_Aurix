/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngMGslLim                                              */
/* !Description     : EngMGslLim Software Component                           */
/*                                                                            */
/* !Module          : EngMGslLim                                              */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : EngMGslLim_private.h                                    */
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
/*   Model name       : EngMGslLim_AUTOSAR.mdl                                */
/*   Root subsystem   : /EngMGslLim                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M16-EngMGslLim/5$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   08 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_EngMGslLim_private_h_
#define RTW_HEADER_EngMGslLim_private_h_
#include "Std_Types.h"
#include "EngMGslLim_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define OvbCtl_tiSampleFast_SC         ((UInt16) 10U)
#define EngMTrb_tiSampleFast_SC        ((UInt16) 20U)
#define CALL_EVENT                     (-1)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define EngMGslLim_START_SEC_CODE
#include "EngMGslLim_MemMap.h"

extern void EngMGslLim_F01_Init(void);
extern void RE_EngMGslLim_001_MSE(void);
extern void EngMGslLim_F02_Compute(void);
extern void RE_EngMGslLim_002_TEV(void);
extern void EngMGslLim_Subsystem1(Boolean rtu_0, Boolean rtu_SelChg,
  Float32 rtu_TrkTe, rtB_Subsystem1_EngMGslLim *localB);
extern void EngMGslLim_Subsystem_Init(rtDW_Subsystem_EngMGslLim *localDW);
extern void EngMGslLim_Subsystem_Start(rtDW_Subsystem_EngMGslLim *localDW);
extern void EngMGslLim_Subsystem_Disable(rtDW_Subsystem_EngMGslLim *localDW);
extern void EngMGslLim_Subsystem(Boolean rtu_0, Float32 rtu_Ini, Float32
  rtu_Inj, Float32 rtu_Te, Float32 rtu_TrkTe, rtB_Subsystem_EngMGslLim *localB,
  rtDW_Subsystem_EngMGslLim *localDW);
extern void EngMGslLim_F02_Compute1_Start(void);
extern void EngMGslLim_F02_Compute1_Disable(void);
extern void EngMGslLim_F02_Compute1(void);
extern void RE_EngMGslLim_003_TEV_Start(void);
extern void RE_EngMGslLim_003_TEV_Disable(void);
extern void RE_EngMGslLim_003_TEV(void);
void EngMGslLim_ASYNC1(int controlPortIdx);
void EngMGslLim_ASYNC2(int controlPortIdx);
void EngMGslLim_ASYNC3(int controlPortIdx);

#define EngMGslLim_STOP_SEC_CODE
#include "EngMGslLim_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define EngMGslLim_START_SEC_CALIB_32BIT
#include "EngMGslLim_MemMap.h"

extern CONST(UInt32, ENGMGSLLIM_CALIB) EngMTrb_mFuMaxEth_C;
extern CONST(UInt32, ENGMGSLLIM_CALIB) EngMTrb_mFuMax_C;

#define EngMGslLim_STOP_SEC_CALIB_32BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define EngMGslLim_START_SEC_CARTO_16BIT
#include "EngMGslLim_MemMap.h"

extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_facCorTInVlv_T[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_facCorT_T[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_facSlopIncRblIrv_T[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_facSlopIncRbl_T[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngFilGain_A[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdCmprOverSpdY_A[16];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdIncKnk_A[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdInhTrb_A[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdIrvRbl_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdLoRonY_A[10];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdLockVlv_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdLostSenKnk_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdRedMax_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdRef_A[16];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdTAirX_A[12];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngLdTmpRblY_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngRedLdKnk_A[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngRedStepKnk_A[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngSlopIncRblIrv_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEngSlopIncRbl_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_nEng_A[9];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rCmprOverSpdLim_M[8][16];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rFilGainLoRon_T[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdIncProtKnk_T[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdInhTrb_T[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdIrvLimRbl_T[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdKnkLoRon_M[16][10];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdLimTmpRbl_M[4][8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdLockVlv_T[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdLostSenKnk_T[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdMaxRef2_T[16];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdMaxRef_T[16];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdMaxTAirLim_M[12][6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rLdRedMax_T[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rMaxIgEfcX_A[16];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_rRedStepProtKnk_T[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_tAirUsInVlv_A[8];
extern CONST(SInt16, ENGMGSLLIM_CARTO) EngMTrb_tCoMes_A[8];
extern CONST(SInt16, ENGMGSLLIM_CARTO) EngMTrb_tCoRef_A[9];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_tThrMesY_A[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_tUsCmprX_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) EngMTrb_tiRedLdKnkCtl_T[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_ctTiOvbAcv_A[8];
extern CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_facOvbBas_M[4][6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_nEngY_A[6];
extern CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_tThrMesX_A[4];
extern CONST(UInt16, ENGMGSLLIM_CARTO) OvbCtl_tiDlyInh_T[8];

#define EngMGslLim_STOP_SEC_CARTO_16BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define EngMGslLim_START_SEC_CALIB_16BIT
#include "EngMGslLim_MemMap.h"

extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facOvbAcvIni_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facOvbReqIni_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facProtKnkInh_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facProtKnkIni_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_facProtKnkMin_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_pDsCmprMax_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxIni_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxIrvRblIni_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxLoRonIni_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxOvbAcvIni_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxOvbAcv_B;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxTiInjEs_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMaxTotIni_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdMax_B;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdRblIrvMin_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_rLdRblTmpMin_C;
extern CONST(SInt16, ENGMGSLLIM_CALIB) EngMTrb_tCoThd_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiDlyEndProtKnk_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiDlyEndProtRblIrv_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiDlyEndProtRbl_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiEthDftTran_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiSample_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) EngMTrb_tiSlopFrzTPM_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) Eng_facStoichEth_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) OvbCtl_facOvbMax_C;
extern CONST(SInt16, ENGMGSLLIM_CALIB) OvbCtl_tCoThdAcvOvb_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) OvbCtl_tiDlyMax_C;
extern CONST(UInt16, ENGMGSLLIM_CALIB) OvbCtl_tiMaxAcv_C;

#define EngMGslLim_STOP_SEC_CALIB_16BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define EngMGslLim_START_SEC_CARTO_8BIT
#include "EngMGslLim_MemMap.h"

extern CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_ctInjCutOffPtlX_A[4];
extern CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_facCorColdTCo_M[9][8];
extern CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_facCorLdMaxRef_M[9][8];
extern CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_facCorOvbAcv_M[9][8];
extern CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_facCorOvbReq_M[9][8];
extern CONST(UInt8, ENGMGSLLIM_CARTO) EngMTrb_rEthRef_A[8];

#define EngMGslLim_STOP_SEC_CARTO_8BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define EngMGslLim_START_SEC_CALIB_8BIT
#include "EngMGslLim_MemMap.h"

extern CONST(UInt8, ENGMGSLLIM_CALIB) EngMTrb_rEthDft_C;
extern CONST(UInt8, ENGMGSLLIM_CALIB) EngMTrb_rEthThd_C;
extern CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbAcv_C;
extern CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbInh_C;
extern CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbIni_C;
extern CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbStopReq_C;
extern CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvbStop_C;
extern CONST(UInt8, ENGMGSLLIM_CALIB) OvbCtl_stOvb_C;

#define EngMGslLim_STOP_SEC_CALIB_8BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define EngMGslLim_START_SEC_CALIB_BOOLEAN
#include "EngMGslLim_MemMap.h"

extern CONST(Boolean, ENGMGSLLIM_CALIB) ENGMGSLLIM_ACTIVE_BYP_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bAcvProtKnkIni_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bAcvProtKnk_B;
extern CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bAcvTPMMod_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bFlex_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bRatEthRcvAcv_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) EngMTrb_bWupFlexAcv_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bAcvOvb_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bAcvTPMMod_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bMPMOvbStop_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bPresExServo_C;
extern CONST(Boolean, ENGMGSLLIM_CALIB) OvbCtl_bPresInServo_C;

#define EngMGslLim_STOP_SEC_CALIB_BOOLEAN
#include "EngMGslLim_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define EngMGslLim_START_SEC_INTERNAL_VAR_32BIT
#include "EngMGslLim_MemMap.h"

extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facOvbAcvFlex;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facOvbReqFlex;
extern VAR(UInt32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facProtKnk_IRV_MP;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facStoichFlex;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_mFuMaxFlex;
extern VAR(UInt32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_mFuMaxInter_MP;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxCord[2];
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxRef[2];
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rEth;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxBas;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxGsl;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxLoRon;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxRefFlex;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxRefFlexCor;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxRefGsl;
extern VAR(Float32, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxTiInjMax;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_32BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define EngMGslLim_START_SEC_INTERNAL_VAR_16BIT
#include "EngMGslLim_MemMap.h"

extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facOvbAcv_IRV_MP;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facOvbReq_IRV_MP;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_facProt_MP;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_pCmprOverSp_MP;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_pDsCmprMax_MP;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxIrvRbl_001;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxIrvRbl_002;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxProt_MP[2];
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxTot_001;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdMaxTot_002;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdRblIrv_MP[2];
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_prm_rLdRbl_MP[2];
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdLimTmpRbl;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxLoRonIni_IRV_MP;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdMaxTAirLim;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdProtTPM;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_rLdProtTPMFrz_IRV_MP;
extern VAR(SInt16, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_facOvbDec_MP;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_facOvbStop;
extern VAR(UInt16, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_tiDly;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_16BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define EngMGslLim_START_SEC_INTERNAL_VAR_8BIT
#include "EngMGslLim_MemMap.h"

extern VAR(UInt8, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_stOvb_IRV_MP;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_8BIT
#include "EngMGslLim_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define EngMGslLim_START_SEC_INTERNAL_VAR_BOOLEAN
#include "EngMGslLim_MemMap.h"

extern VAR(Boolean, ENGMGSLLIM_INTERNAL_VAR) EngMTrb_bWupClcAcv;
extern VAR(Boolean, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_bAcvEngProt;
extern VAR(Boolean, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_bAcvVlvServo;
extern VAR(Boolean, ENGMGSLLIM_INTERNAL_VAR) OvbCtl_bInhMaxTiThd;

#define EngMGslLim_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "EngMGslLim_MemMap.h"
#endif                                 /* RTW_HEADER_EngMGslLim_private_h_ */

/*-------------------------------- end of file -------------------------------*/
