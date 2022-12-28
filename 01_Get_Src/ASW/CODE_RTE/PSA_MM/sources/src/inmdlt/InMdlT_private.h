/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : InMdlT                                                  */
/* !Description     : InMdlT Software Component                               */
/*                                                                            */
/* !Module          : InMdlT                                                  */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : InMdlT_private.h                                        */
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
/*   Model name       : InMdlT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /InMdlT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M02-InMdlT/5-SOF$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   18 Jun 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InMdlT_private_h_
#define RTW_HEADER_InMdlT_private_h_
#include "Std_Types.h"
#include "InMdlT_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define InM_tiSampleFast_SC            ((UInt16) 10U)
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
#define InMdlT_START_SEC_CODE
#include "InMdlT_MemMap.h"

extern void RE_InMdlT_008_TEV_Start(void);
extern void RE_InMdlT_008_TEV(void);
extern void RE_InMdlT_004_TEV_Start(void);
extern void RE_InMdlT_004_TEV(void);
extern void RE_InMdlT_037_MSE_Start(void);
extern void RE_InMdlT_037_MSE(void);
extern void RE_InMdlT_039_MSE_Start(void);
extern void RE_InMdlT_039_MSE(void);
extern void RE_InMdlT_031_TEV_Start(void);
extern void RE_InMdlT_031_TEV(void);
extern void RE_InMdlT_038_MSE_Start(void);
extern void RE_InMdlT_038_MSE(void);
extern void RE_InMdlT_027_TEV_Start(void);
extern void RE_InMdlT_027_TEV(void);
extern void RE_InMdlT_045_MSE(void);
extern void RE_InMdlT_029_TEV_Start(void);
extern void RE_InMdlT_029_TEV(void);
extern void RE_InMdlT_035_MSE(void);
extern void RE_InMdlT_002_TEV_Start(void);
extern void RE_InMdlT_002_TEV(void);
extern void RE_InMdlT_040_MSE_Start(void);
extern void RE_InMdlT_040_MSE(void);
extern void RE_InMdlT_006_TEV_Start(void);
extern void RE_InMdlT_006_TEV(void);
extern void RE_InMdlT_042_MSE_Start(void);
extern void RE_InMdlT_042_MSE(void);
extern void RE_InMdlT_028_TEV_Start(void);
extern void RE_InMdlT_028_TEV(void);
extern void RE_InMdlT_046_MSE_Start(void);
extern void RE_InMdlT_046_MSE(void);
extern void RE_InMdlT_013_DRE_Start(void);
extern void RE_InMdlT_013_DRE(void);
extern void RE_InMdlT_012_TEV_Start(void);
extern void RE_InMdlT_012_TEV(void);
extern void RE_InMdlT_041_MSE_Start(void);
extern void RE_InMdlT_041_MSE(void);
extern void RE_InMdlT_010_TEV_Start(void);
extern void RE_InMdlT_010_TEV(void);
extern void RE_InMdlT_047_MSE_Start(void);
extern void RE_InMdlT_047_MSE(void);
extern void RE_InMdlT_015_DRE_Start(void);
extern void RE_InMdlT_015_DRE(void);
extern void RE_InMdlT_014_TEV_Start(void);
extern void RE_InMdlT_014_TEV(void);
extern void RE_InMdlT_032_TEV(void);
extern void RE_InMdlT_016_TEV_Start(void);
extern void RE_InMdlT_016_TEV(void);
extern void RE_InMdlT_026_TEV_Start(void);
extern void RE_InMdlT_026_TEV(void);
extern void RE_InMdlT_033_TEV_Start(void);
extern void RE_InMdlT_033_TEV(void);
extern void RE_InMdlT_018_TEV_Start(void);
extern void RE_InMdlT_018_TEV(void);
extern void RE_InMdlT_044_MSE_Start(void);
extern void RE_InMdlT_044_MSE(void);
extern void RE_InMdlT_022_TEV_Start(void);
extern void RE_InMdlT_022_TEV(void);
extern void RE_InMdlT_024_DRE_Start(void);
extern void RE_InMdlT_024_DRE(void);
extern void RE_InMdlT_043_MSE(void);
extern void RE_InMdlT_020_TEV_Start(void);
extern void RE_InMdlT_020_TEV(void);
extern void RE_InMdlT_001_MSE_Start(void);
extern void RE_InMdlT_001_MSE(void);
extern void RE_InMdlT_036_MSE(void);
extern void RE_InMdlT_034_TEV_Start(void);
extern void RE_InMdlT_034_TEV(void);
extern void RE_InMdlT_037_TEV_Start(void);
extern void RE_InMdlT_037_TEV(void);
void InMdlT_ASYNC1(int controlPortIdx);
void InMdlT_ASYNC2(int controlPortIdx);
void InMdlT_ASYNC3(int controlPortIdx);
void InMdlT_ASYNC4(int controlPortIdx);
void InMdlT_ASYNC5(int controlPortIdx);
void InMdlT_ASYNC6(int controlPortIdx);
void InMdlT_ASYNC7(int controlPortIdx);
void InMdlT_ASYNC8(int controlPortIdx);
void InMdlT_ASYNC9(int controlPortIdx);
void InMdlT_ASYNC10(int controlPortIdx);
void InMdlT_ASYNC11(int controlPortIdx);
void InMdlT_ASYNC12(int controlPortIdx);
void InMdlT_ASYNC13(int controlPortIdx);
void InMdlT_ASYNC14(int controlPortIdx);
void InMdlT_ASYNC15(int controlPortIdx);
void InMdlT_ASYNC16(int controlPortIdx);
void InMdlT_ASYNC17(int controlPortIdx);
void InMdlT_ASYNC18(int controlPortIdx);
void InMdlT_ASYNC19(int controlPortIdx);
void InMdlT_ASYNC20(int controlPortIdx);
void InMdlT_ASYNC21(int controlPortIdx);
void InMdlT_ASYNC22(int controlPortIdx);
void InMdlT_ASYNC23(int controlPortIdx);
void InMdlT_ASYNC24(int controlPortIdx);
void InMdlT_ASYNC25(int controlPortIdx);
void InMdlT_ASYNC26(int controlPortIdx);
void InMdlT_ASYNC27(int controlPortIdx);
void InMdlT_ASYNC28(int controlPortIdx);
void InMdlT_ASYNC29(int controlPortIdx);
void InMdlT_ASYNC30(int controlPortIdx);
void InMdlT_ASYNC31(int controlPortIdx);
void InMdlT_ASYNC32(int controlPortIdx);
void InMdlT_ASYNC33(int controlPortIdx);
void InMdlT_ASYNC34(int controlPortIdx);
void InMdlT_ASYNC35(int controlPortIdx);
void InMdlT_ASYNC36(int controlPortIdx);
void InMdlT_ASYNC37(int controlPortIdx);
void InMdlT_ASYNC38(int controlPortIdx);
void InMdlT_ASYNC39(int controlPortIdx);
void InMdlT_ASYNC40(int controlPortIdx);
void InMdlT_ASYNC41(int controlPortIdx);
void InMdlT_ASYNC42(int controlPortIdx);
void InMdlT_ASYNC43(int controlPortIdx);
void InMdlT_ASYNC44(int controlPortIdx);
void InMdlT_ASYNC45(int controlPortIdx);
void InMdlT_ASYNC46(int controlPortIdx);
void InMdlT_ASYNC47(int controlPortIdx);
void InMdlT_ASYNC48(int controlPortIdx);
void InMdlT_ASYNC49(int controlPortIdx);
void InMdlT_ASYNC50(int controlPortIdx);
void InMdlT_ASYNC51(int controlPortIdx);
void InMdlT_ASYNC52(int controlPortIdx);
void InMdlT_ASYNC53(int controlPortIdx);
void InMdlT_ASYNC54(int controlPortIdx);

#define InMdlT_STOP_SEC_CODE
#include "InMdlT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define InMdlT_START_SEC_CALIB_32BIT
#include "InMdlT_MemMap.h"

extern CONST(UInt32, INMDLT_CALIB) InM_mAirEstim_B;
extern CONST(UInt32, INMDLT_CALIB) InM_mEGREstim_B;
extern CONST(SInt32, INMDLT_CALIB) InM_mfFuStmBlbyThd_C;
extern CONST(UInt32, INMDLT_CALIB) InM_pDsThrEstim_B;
extern CONST(UInt32, INMDLT_CALIB) InM_tiDlyEGRCls_C;
extern CONST(UInt32, INMDLT_CALIB) InM_tiDlyFuStmClsBbly_C;
extern CONST(UInt32, INMDLT_CALIB) InM_tiDlyFuStmCls_C;

#define InMdlT_STOP_SEC_CALIB_32BIT
#include "InMdlT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define InMdlT_START_SEC_CARTO_16BIT
#include "InMdlT_MemMap.h"

extern CONST(UInt16, INMDLT_CARTO) Air_arEffEGRVlv_T[9];
extern CONST(UInt16, INMDLT_CARTO) Air_concFuStm_A[9];
extern CONST(UInt16, INMDLT_CARTO) Air_mfEg_A[17];
extern CONST(UInt16, INMDLT_CARTO) InM_arEffCanPurg_T[11];
extern CONST(UInt16, INMDLT_CARTO) InM_facCfeVlv1_T[22];
extern CONST(UInt16, INMDLT_CARTO) InM_pBackEgPUsEGRVlv_T[17];
extern CONST(UInt16, INMDLT_CARTO) InM_pDrpLossUsEGRVlv_T[9];
extern CONST(SInt16, INMDLT_CARTO) InM_tOilEstim_A[8];
extern CONST(UInt16, INMDLT_CARTO) InM_tOilEstim_T[8];

#define InMdlT_STOP_SEC_CARTO_16BIT
#include "InMdlT_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define InMdlT_START_SEC_CALIB_16BIT
#include "InMdlT_MemMap.h"

extern CONST(UInt16, INMDLT_CALIB) InM_agCkHiTDCRef2_C;
extern CONST(UInt16, INMDLT_CALIB) InM_agCkLoTDCRef2_C;
extern CONST(UInt16, INMDLT_CALIB) InM_arEffAdpEGRVlv_B;
extern CONST(UInt16, INMDLT_CALIB) InM_arEffAdpEGRVlv_C;
extern CONST(UInt16, INMDLT_CALIB) InM_arEffAdpThr_B;
extern CONST(UInt16, INMDLT_CALIB) InM_arEffEGRVlv_B;
extern CONST(UInt16, INMDLT_CALIB) InM_arEffEGRVlv_C;
extern CONST(UInt16, INMDLT_CALIB) InM_concAirCor_B;
extern CONST(UInt16, INMDLT_CALIB) InM_concAirPredCor_B;
extern CONST(UInt16, INMDLT_CALIB) InM_concAirPredInCylCor_B;
extern CONST(UInt16, INMDLT_CALIB) InM_concEGREstim_B;
extern CONST(UInt16, INMDLT_CALIB) InM_concFuCor_B;
extern CONST(UInt16, INMDLT_CALIB) InM_concFuPredCor_B;
extern CONST(UInt16, INMDLT_CALIB) InM_concFuPredInCylCor_B;
extern CONST(UInt16, INMDLT_CALIB) InM_facCfeGradThr_B;
extern CONST(UInt16, INMDLT_CALIB) InM_facCoplMassPres_B;
extern CONST(UInt16, INMDLT_CALIB) InM_facKK1Acc_C;
extern CONST(UInt16, INMDLT_CALIB) InM_facKK1Dec_C;
extern CONST(UInt16, INMDLT_CALIB) InM_facRelaxCplMassPresEstim_B;
extern CONST(UInt16, INMDLT_CALIB) InM_mEGREstimDec_C;
extern CONST(UInt16, INMDLT_CALIB) InM_mEGREstimLoResl_B;
extern CONST(UInt16, INMDLT_CALIB) InM_mFuStmEstimDec_C;
extern CONST(UInt16, INMDLT_CALIB) InM_mfAirCanPurgEstim_B;
extern CONST(SInt16, INMDLT_CALIB) InM_mfAirDifIn_B;
extern CONST(UInt16, INMDLT_CALIB) InM_mfAirEstim_B;
extern CONST(UInt16, INMDLT_CALIB) InM_mfAirThrEstim_B;
extern CONST(UInt16, INMDLT_CALIB) InM_mfEGREstimEGRVlv_B;
extern CONST(UInt16, INMDLT_CALIB) InM_mfEGREstimEGRVlv_C;
extern CONST(UInt16, INMDLT_CALIB) InM_mfEGRReq_arEGR_B;
extern CONST(UInt16, INMDLT_CALIB) InM_mfEGRReq_arEGR_C;
extern CONST(UInt16, INMDLT_CALIB) InM_mfTotCanPurgEstim_B;
extern CONST(UInt16, INMDLT_CALIB) InM_nEngCor_B;
extern CONST(UInt16, INMDLT_CALIB) InM_pBackEgPUsEGRVlv_B;
extern CONST(UInt16, INMDLT_CALIB) InM_pBackEgPUsEGRVlv_C;
extern CONST(UInt16, INMDLT_CALIB) InM_pDsThrCor_B;
extern CONST(SInt16, INMDLT_CALIB) InM_pDsThrEstimErr_B;
extern CONST(UInt16, INMDLT_CALIB) InM_pDsThrPredInCyl_B;
extern CONST(UInt16, INMDLT_CALIB) InM_pDsThrPred_B;
extern CONST(UInt16, INMDLT_CALIB) InM_pDsThrPred_facVlvOvlp_B;
extern CONST(SInt16, INMDLT_CALIB) InM_pDynCorPres_B;
extern CONST(UInt16, INMDLT_CALIB) InM_pSenHiThd_C;
extern CONST(UInt16, INMDLT_CALIB) InM_pSenLoThd_C;
extern CONST(UInt16, INMDLT_CALIB) InM_pUsEGRVlv_B;
extern CONST(UInt16, INMDLT_CALIB) InM_pUsEGRVlv_C;
extern CONST(UInt16, INMDLT_CALIB) InM_prm_concAirPredCyl_B[6];
extern CONST(UInt16, INMDLT_CALIB) InM_prm_concFuPredCyl_B[6];
extern CONST(UInt16, INMDLT_CALIB) InM_prm_pDsThrPredCyl_B[6];
extern CONST(UInt16, INMDLT_CALIB) InM_prm_pDsThrPredOvlpCyl_B[6];
extern CONST(UInt16, INMDLT_CALIB) InM_rAirPres_B;
extern CONST(UInt16, INMDLT_CALIB) InM_rCohMnfMf_B;
extern CONST(UInt16, INMDLT_CALIB) InM_rTotLdExEstim_B;
extern CONST(UInt16, INMDLT_CALIB) InM_tiInvEigVal_mAir_B;
extern CONST(UInt16, INMDLT_CALIB) InM_tiInvEigVal_pDsThr_B;

#define InMdlT_STOP_SEC_CALIB_16BIT
#include "InMdlT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define InMdlT_START_SEC_CARTO_8BIT
#include "InMdlT_MemMap.h"

extern CONST(UInt8, INMDLT_CARTO) Air_rOpEGR_A[9];
extern CONST(UInt8, INMDLT_CARTO) InM_facCfeCanPurgCor_T[9];
extern CONST(UInt8, INMDLT_CARTO) InM_mfAirStabToTranThd_T[9];
extern CONST(UInt8, INMDLT_CARTO) InM_mfAirTranToStabThd_T[9];
extern CONST(UInt8, INMDLT_CARTO) InM_rOpCanPurg_A[11];

#define InMdlT_STOP_SEC_CARTO_8BIT
#include "InMdlT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define InMdlT_START_SEC_CALIB_8BIT
#include "InMdlT_MemMap.h"

extern CONST(UInt8, INMDLT_CALIB) InM_facCfeCanPurgCor_B;
extern CONST(UInt8, INMDLT_CALIB) InM_pSenFilGain1_C;
extern CONST(UInt8, INMDLT_CALIB) InM_pSenFilGain2_C;
extern CONST(UInt8, INMDLT_CALIB) InM_stModeMng_B;
extern CONST(UInt8, INMDLT_CALIB) InM_stTranLd_B;
extern CONST(UInt8, INMDLT_CALIB) InM_tiRelax_mTotEstim_B;
extern CONST(UInt8, INMDLT_CALIB) InM_tiRelax_pDsThrEstim_B;

#define InMdlT_STOP_SEC_CALIB_8BIT
#include "InMdlT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define InMdlT_START_SEC_CALIB_BOOLEAN
#include "InMdlT_MemMap.h"

extern CONST(Boolean, INMDLT_CALIB) INMDLT_ACTIVE_BYP_C;
extern CONST(Boolean, INMDLT_CALIB) InM_bAcceEng_B;
extern CONST(Boolean, INMDLT_CALIB) InM_bHrznClcMod_C;
extern CONST(Boolean, INMDLT_CALIB) InM_bInhCmpAirBby_C;
extern CONST(Boolean, INMDLT_CALIB) InM_bInhEGRPresEstim_C;
extern CONST(Boolean, INMDLT_CALIB) InM_bInhHeatTrf_C;
extern CONST(Boolean, INMDLT_CALIB) InM_bInhInMDynCor_C;
extern CONST(Boolean, INMDLT_CALIB) InM_bInhInMNomMod_C;
extern CONST(Boolean, INMDLT_CALIB) InM_bInhSenMdl_C;
extern CONST(Boolean, INMDLT_CALIB) InM_bSelCanPurgClc_C;

#define InMdlT_STOP_SEC_CALIB_BOOLEAN
#include "InMdlT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define InMdlT_START_SEC_INTERNAL_VAR_32BIT
#include "InMdlT_MemMap.h"

extern VAR(Float32, INMDLT_INTERNAL_VAR) AirEfc_facChrExpFilEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) AirEfc_facChrExpScvFilEstim;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkClsInVlvEstimRef2_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkOvlpEstimRef2;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkPhaHrznOvlpPred;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkPhaHrznPred;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_agCkPhaHrznPredInCyl;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_arEffThrOfs;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_concAirEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_concAirPredInCyl_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_concAirPred_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_concAirRaw_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_concFuPredInCyl_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_concFuPred_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_concFuStmEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_concFuStmRaw_IRV_MP;
extern VAR(UInt32, INMDLT_INTERNAL_VAR) InM_ctEGRVlvCls_IRV_MP;
extern VAR(UInt32, INMDLT_INTERNAL_VAR) InM_facCfeEGREstim_MP;
extern VAR(UInt32, INMDLT_INTERNAL_VAR) InM_facCfeEGR_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_facRelaxCoplMassPresPred[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_facSlopEfcEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirCylPred_MP[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirEstimInt;
extern VAR(UInt32, INMDLT_INTERNAL_VAR) InM_mAirEstimPres_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirEstimPrev_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirPred[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirPredInt[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mAirPredPres_MP[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mBurnInMnfPred[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mEGREstimPrev_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mFuInMnfMnfPred[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mFuStmEstimPrev_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mFuStmEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mGradAirEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mGradEGREstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mGradFuStmEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mTotEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mTotPred[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mfAirStabToTranThd;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mfAirTranToStabThd;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_mfFuStmCanPurgEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrEstimLoResl_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrEstimPrev_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrPredInCylRaw_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrPredRawNoSat_MP[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrPredRawTmp[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrPredRaw_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThrSenEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pDsThr_facVlvOvlp_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pGradDsThrEstim_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrev1SenFil_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenBuffer_01_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenBuffer_02_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenBuffer_03_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenBuffer_04_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenFil_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_pPrevSenSat_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_prm_concAirPredRef[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_prm_concFuPredRef[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_prm_pDsThrPredRawRef[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiHrznPredInCyl_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiHrznPred_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiHrznPred_facVlvOvlp_IRV_MP;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mAirEstim;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mAirPred[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mEGREstim;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mEGRPred[3];
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mFuStmEstim;
extern VAR(Float32, INMDLT_INTERNAL_VAR) InM_tiRelax_mFuStmPred[3];

#define InMdlT_STOP_SEC_INTERNAL_VAR_32BIT
#include "InMdlT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define InMdlT_START_SEC_INTERNAL_VAR_16BIT
#include "InMdlT_MemMap.h"

extern VAR(UInt16, INMDLT_INTERNAL_VAR) AFA_rOpThrMax_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) AFA_rOpThrRef2_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) AFA_rOpThrRef3_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_agCkPosnCurCor_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_agCkPosnCurRef2Cor_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_arEffCanPurg_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_arEffThr_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_concAirRawNoSat_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_concFuStmRawNoSat_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_facCfeCanPurg_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_facCfeThr_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_facMfThr_MP;
extern VAR(SInt16, INMDLT_INTERNAL_VAR) InM_mGradAirEstimRaw_MP;
extern VAR(SInt16, INMDLT_INTERNAL_VAR) InM_mGradEGREstimRaw_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_mfSel_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_mfTotExEstim_IRV_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_nEngPred_IRV_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_pDrpLossUsEGRVlv_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_pSenBufferRaw_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_pSenFilRaw_MP;
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_tiRelaxMassAir_MP[3];
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_tiRelax_mTotPred[3];
extern VAR(UInt16, INMDLT_INTERNAL_VAR) InM_tiRelax_pDsThrPred[3];

#define InMdlT_STOP_SEC_INTERNAL_VAR_16BIT
#include "InMdlT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define InMdlT_START_SEC_INTERNAL_VAR_8BIT
#include "InMdlT_MemMap.h"

extern VAR(UInt8, INMDLT_INTERNAL_VAR) InM_cntPrevSenPres_IRV_MP;
extern VAR(UInt8, INMDLT_INTERNAL_VAR) InM_facKK1_MP;
extern VAR(UInt8, INMDLT_INTERNAL_VAR) InM_stTranLd_SF;

#define InMdlT_STOP_SEC_INTERNAL_VAR_8BIT
#include "InMdlT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define InMdlT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "InMdlT_MemMap.h"

extern VAR(Boolean, INMDLT_INTERNAL_VAR) InM_bAcceEng_SF;
extern VAR(Boolean, INMDLT_INTERNAL_VAR) InM_bSelFacRelaxCop_MP[3];

#define InMdlT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "InMdlT_MemMap.h"
#endif                                 /* RTW_HEADER_InMdlT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
