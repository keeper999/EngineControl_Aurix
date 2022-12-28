/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActSys                                               */
/* !Description     : TrbActSys Software Component                            */
/*                                                                            */
/* !Module          : TrbActSys                                               */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : TrbActSys_private.h                                     */
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
/*   Model name       : TrbActSys_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActSys                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M14-TrbActSys/5-$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   15 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_TrbActSys_private_h_
#define RTW_HEADER_TrbActSys_private_h_
#include "Std_Types.h"
#include "TrbActSys_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define TrbAct_tiSampleFast_SC         ((UInt16) 10U)
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
#define TrbActSys_START_SEC_CODE
#include "TrbActSys_MemMap.h"

extern void TrbActSys_if_s(Boolean rtu_bMonRun, Boolean rtu_bDgo,
  rtDW_if_s_TrbActSys *localDW);
extern void RE_TrbActSys_001_MSE_Start(void);
extern void RE_TrbActSys_001_MSE(void);
extern void RE_TrbActSys_002_TEV_Start(void);
extern void RE_TrbActSys_002_TEV(void);
extern void RE_TrbActSys_005_TEV(void);
extern void RE_TrbActSys_003_TEV_Init(void);
extern void RE_TrbActSys_003_TEV_Start(void);
extern void RE_TrbActSys_003_TEV(void);
extern void RE_TrbActSys_004_TEV_Start(void);
extern void RE_TrbActSys_004_TEV(void);
void TrbActSys_ASYNC1(int controlPortIdx);
void TrbActSys_ASYNC2(int controlPortIdx);
void TrbActSys_ASYNC3(int controlPortIdx);
void TrbActSys_ASYNC4(int controlPortIdx);
void TrbActSys_ASYNC5(int controlPortIdx);
void TrbActSys_ASYNC6(int controlPortIdx);
void TrbActSys_ASYNC7(int controlPortIdx);

#define TrbActSys_STOP_SEC_CODE
#include "TrbActSys_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define TrbActSys_START_SEC_CALIB_32BIT
#include "TrbActSys_MemMap.h"

extern CONST(SInt32, TRBACTSYS_CALIB) TrbAct_facAdpArTrbActErrMin_C;

#define TrbActSys_STOP_SEC_CALIB_32BIT
#include "TrbActSys_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define TrbActSys_START_SEC_CARTO_16BIT
#include "TrbActSys_MemMap.h"

extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_arTrbActAdpDeltaCor_A[4];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_arTrbActReq_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_cppEg_T[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_effCmpr_M[16][16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_effTrb_M[16][16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facAdpTrbActDeltaCor_T[4];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facAdp_A[12];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facAdp_T[12];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facCfeTrbAct_T[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facCfeTrb_T[19];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facFilGradUsThrMes_T[9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facFilOpTrbActAir_T[9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facFltPred_M[16][9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facPresTrb_T[21];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_facTUsTrb_T[9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_mfAirThrCorReq_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_mfGrd_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_mfRatPresTrbActInter_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_mfTrbCorEstim_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_mfTrbCorReq_T[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_nEng2_A[9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_nThdAdp_T[9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_pThdAdp_M[9][9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_pwrCmprInter_T[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rAirLdAltiCorReq2_A[9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rAirLdAltiCorReq_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rOpRelTrbActAirExtReq_M[9][16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rOpRelTrbActExtReq1_M[9][9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rOpRelTrbActExtReq2_M[9][9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rOpTrbActTrbMod_M[16][9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresCfeTrbAct_A[19];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresCmprReqRef1_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresCmprReqRef2_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresTrbEstimIvsRef1_A[9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresTrbEstimIvsRef2_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresTrbEstim_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresTrbReq_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresTrbReq_M[16][16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rPresTrb_A[21];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rTCmprSqrt_T[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rTCmpr_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rTTrbSqrt_T[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_rTTrb_A[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_tUsTrbAdp_A[9];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_tUsTrbEstimSqrt_T[16];
extern CONST(UInt16, TRBACTSYS_CARTO) TrbAct_tUsTrbEstim_A[16];

#define TrbActSys_STOP_SEC_CARTO_16BIT
#include "TrbActSys_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define TrbActSys_START_SEC_CALIB_16BIT
#include "TrbActSys_MemMap.h"

extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_arTrbActAdp_B;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_arTrbActFrzSp_B;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_arTrbActReqMax_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_facAdpArTrbActErrMax_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_facArAdpGain_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_facFilGainRatOpTrbAct_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_facFilGradUsThrReq_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_facFilPExMnfReq_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_facFltMfEg_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_facFltPred1_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_facFltPred2_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_pCmprRef_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_pDeltaUsThrHiThd_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_pDeltaUsThrLoThd_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_pDeltaUsThrThd1_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_pDeltaUsThrThd2_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_pDeltaUsThrThd3_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_pExMnfReq_B;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_pTrbRef_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_rOpMaxTrbAct_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_rOpMinTrbAct_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_rOpRelTrbActExtReq_B;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_rOpTrbActReqDft_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_rOpTrbActReqTest_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_rOpTrbActReq_B;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_tCmprRef_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_tTrbRef_C;
extern CONST(UInt16, TRBACTSYS_CALIB) TrbAct_tiDlyArAdp_C;

#define TrbActSys_STOP_SEC_CALIB_16BIT
#include "TrbActSys_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define TrbActSys_START_SEC_CALIB_BOOLEAN
#include "TrbActSys_MemMap.h"

extern CONST(Boolean, TRBACTSYS_CALIB) TRBACTSYS_ACTIVE_BYP_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bAcvOpRelTWCMgt_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bAcvOpRelTrbActExt_B;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bAcvPExMnfReq_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bAcvTrbActAdp_B;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bAcvTrbMod_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bInhAdpTrbAct_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bInhCtlExt_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bInhHiThd_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bInhPresThd_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bInhTrbActAdpPrev_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bPresAltiCor_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bSelPresExMnf_C;
extern CONST(Boolean, TRBACTSYS_CALIB) TrbAct_bTestModRatOpReq_C;

#define TrbActSys_STOP_SEC_CALIB_BOOLEAN
#include "TrbActSys_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define TrbActSys_START_SEC_INTERNAL_VAR_32BIT
#include "TrbActSys_MemMap.h"

extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) ExM_mfEgTotFlt;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_facAdpArErrFilPrev;
extern VAR(SInt32, TRBACTSYS_INTERNAL_VAR) TrbAct_facAdpArTrbActErrFil;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_facAdpArTrbActErrPrev;
extern VAR(SInt32, TRBACTSYS_INTERNAL_VAR) TrbAct_facAdpArTrbActErr_IRV_MP;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_facArTrbAct1;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_facArTrbAct2;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_mfTrbActReq;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_mfTrbEstim;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_pGradUsThrMesCorPrev;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_pGradUsThrReqPrev;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_pwrCmprReq;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_rOpTrbActAirExtPrev;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_rOpTrbActReqPrev;
extern VAR(Float32, TRBACTSYS_INTERNAL_VAR) TrbAct_rOpTrbActTrbModReq;

#define TrbActSys_STOP_SEC_INTERNAL_VAR_32BIT
#include "TrbActSys_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define TrbActSys_START_SEC_INTERNAL_VAR_16BIT
#include "TrbActSys_MemMap.h"

extern VAR(SInt16, TRBACTSYS_INTERNAL_VAR) ExM_mfEgTotGrdFlt_MP;
extern VAR(SInt16, TRBACTSYS_INTERNAL_VAR) ExM_mfEgTotGrdPrev_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_arTrbActReq_IRV_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_effCmpr_IRV_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_effTrb_IRV_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_facAdp_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_facCfeTrbAct_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_facFltPred_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_facUsTrbMfCor_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_mfAirThrCorReq_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_mfRatPresTrbInter_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_mfTrbCorEstim_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_mfTrbCorReq_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_pExMnf_MP;
extern VAR(SInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_pGradUsThrMesCorFil;
extern VAR(SInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_pGradUsThrReqFil_IRV_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_rAirLdAltiCorReq_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_rOpTrbActAirExtModReq;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_rPresCmprReq_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_rPresTrbReq_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_rTCmprEstim_MP;
extern VAR(UInt16, TRBACTSYS_INTERNAL_VAR) TrbAct_rTTrbEstim_MP;

#define TrbActSys_STOP_SEC_INTERNAL_VAR_16BIT
#include "TrbActSys_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define TrbActSys_START_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActSys_MemMap.h"

extern VAR(Boolean, TRBACTSYS_INTERNAL_VAR) TrbAct_bAcvTrbActAdpPrev;
extern VAR(Boolean, TRBACTSYS_INTERNAL_VAR) TrbAct_bAdpCdn_MP;

#define TrbActSys_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActSys_MemMap.h"
#endif                                 /* RTW_HEADER_TrbActSys_private_h_ */

/*-------------------------------- end of file -------------------------------*/
