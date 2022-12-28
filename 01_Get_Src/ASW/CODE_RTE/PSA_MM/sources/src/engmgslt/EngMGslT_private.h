/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngMGslT                                                */
/* !Description     : EngMGslT Software Component                             */
/*                                                                            */
/* !Module          : EngMGslT                                                */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : EngMGslT_private.h                                      */
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
/*   Model name       : EngMGslT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /EngMGslT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M05-EngMGslT/5-S$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   31 May 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_EngMGslT_private_h_
#define RTW_HEADER_EngMGslT_private_h_
#include "Std_Types.h"
#include "EngMGslT_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define EngM_tiSampleFast_SC           ((UInt16) 19U)
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
#define EngMGslT_START_SEC_CODE
#include "EngMGslT_MemMap.h"

extern void RE_EngMGslT_001_MSE_Start(void);
extern void RE_EngMGslT_001_MSE(void);
extern void RE_EngMGslT_002_TEV(void);
extern void EngMGslT_F02_libEngLdM(UInt16 rtu_Ext_nEngRef, Float32
  rtu_EngM_agCkClsExVlvRef1, Float32 rtu_EngM_agCkClsInVlvRef1, Float32
  rtu_EngM_agCkOpInVlvRef1, UInt16 rtu_InM_tAirUsInVlvEstimRef, Float32
  rtu_ExM_tExMnfEstimRef, UInt16 rtu_InM_pDsThr, Float32
  rtu_ExM_pExMnfEstimRef, Float32 rtu_UsThrM_pAirExtEstimRef, UInt16
  rtu_InjSys_rlamEngCorReqRef, Float32 rtu_InM_pDsThrPred_facVlvOvlpRe, SInt16
  rtu_Ext_tCoMes, Float32 rtu_AirEfc_facChrExpFilPrev, Float32
  rtu_AirEfc_facChrExpScvFilPrev, UInt8 rtu_EngM_noAcvMPVal, Float32
  rtu_InjSys_agInj1BegRef, Float32 rtu_InjSys_agInj1EndRef, Float32
  rtu_InjSys_mFu1Inj, UInt16 rtu_InjSys_tFuRef, Float32
  rtu_EngM_facCorOfsEfcRef, Float32 rtu_EngM_facCorSlopEfcRef, UInt16
  rtu_InThM_nEngCorRef, Float32 rtu_InM_concAir, rtB_F02_libEngLdM_EngMGslT
  *localB);
extern void RE_EngMGslT_020_TEV_Start(void);
extern void RE_EngMGslT_020_TEV(void);
extern void EngMGslT_VlvBasChgT(Float32 rtu_EngM_agCkOpInVlvRef0, Float32
  rtu_EngM_agCkClsExVlvRef0, SInt16 rtu_Ext_tCoStrtMes, Float32
  rtu_AFA_agCkOpInVlvOfs, Float32 rtu_AFA_agCkClsExVlvOfs, UInt32
  rtu_EOM_tiEngRun, Float32 rtu_EngM_dstInVlvClrCor, Float32
  rtu_EngM_dstExVlvClrCor, UInt8 rtu_EngM_noAcvVlvMPVal,
  rtB_VlvBasChgT_EngMGslT *localB);
extern void RE_EngMGslT_012_TEV_Start(void);
extern void RE_EngMGslT_012_TEV(void);
extern void RE_EngMGslT_008_TEV_Start(void);
extern void RE_EngMGslT_008_TEV(void);
extern void RE_EngMGslT_018_TEV_Start(void);
extern void RE_EngMGslT_018_TEV(void);
extern void RE_EngMGslT_022_TEV_Start(void);
extern void RE_EngMGslT_022_TEV(void);
extern void RE_EngMGslT_004_TEV(void);
extern void EngMGslT_IfActionSubsystem(UInt16 rtu_0, UInt16 *rty_Out1);
extern void RE_EngMGslT_024_TEV_Start(void);
extern void RE_EngMGslT_024_TEV(void);
extern void RE_EngMGslT_026_TEV_Start(void);
extern void RE_EngMGslT_026_TEV(void);
void EngMGslT_ASYNC1(int controlPortIdx);
void EngMGslT_ASYNC2(int controlPortIdx);
void EngMGslT_ASYNC3(int controlPortIdx);
void EngMGslT_ASYNC4(int controlPortIdx);
void EngMGslT_ASYNC5(int controlPortIdx);
void EngMGslT_ASYNC6(int controlPortIdx);
void EngMGslT_ASYNC7(int controlPortIdx);
void EngMGslT_ASYNC8(int controlPortIdx);
void EngMGslT_ASYNC9(int controlPortIdx);
void EngMGslT_ASYNC10(int controlPortIdx);
void EngMGslT_ASYNC11(int controlPortIdx);
void EngMGslT_ASYNC12(int controlPortIdx);
void EngMGslT_ASYNC13(int controlPortIdx);
void EngMGslT_ASYNC14(int controlPortIdx);

#define EngMGslT_STOP_SEC_CODE
#include "EngMGslT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define EngMGslT_START_SEC_CALIB_32BIT
#include "EngMGslT_MemMap.h"

extern CONST(UInt32, ENGMGSLT_CALIB) EngM_facMassAirScvCor_B;
extern CONST(UInt32, ENGMGSLT_CALIB) EngM_facMassAirScvReq_B;
extern CONST(UInt32, ENGMGSLT_CALIB) EngM_mAirEngCylMax_B;
extern CONST(UInt32, ENGMGSLT_CALIB) EngM_mAirEngCylMin_B;
extern CONST(UInt32, ENGMGSLT_CALIB) EngM_mAirEngCylTrbMax_B;
extern CONST(UInt32, ENGMGSLT_CALIB) EngM_mAirPresUsThr_B;
extern CONST(UInt32, ENGMGSLT_CALIB) EngM_tiInjMin_C;

#define EngMGslT_STOP_SEC_CALIB_32BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Declare data in section "CARTO_32BIT" */
#define EngMGslT_START_SEC_CARTO_32BIT
#include "EngMGslT_MemMap.h"

extern CONST(UInt32, ENGMGSLT_CARTO) EngM_rPresX_A[11];

#define EngMGslT_STOP_SEC_CARTO_32BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define EngMGslT_START_SEC_CARTO_16BIT
#include "EngMGslT_MemMap.h"

extern CONST(UInt16, ENGMGSLT_CARTO) Air_rAirPresRef2_A[22];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_facChgCorSlopEfc_T[11];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_facCorRatPresExt_T[22];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_facCorT_T[8];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_mfFuInjMin_T[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_nEng_LfpPresAtmY_A[8];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_pFuLdMin_A[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_pInMnfMinReq_T[9];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mAirPredInCyl_B[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mAirScvCorCyl_B[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mfAirCorCyl_B[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mfAirPredInCyl_B[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mfAirScvCorCyl_B[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_mfTotExCorCyl_B[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_rAirLdPredInCyl_B[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_prm_rTotLdExCorCyl_B[6];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_rLdMinProt_M[16][17];
extern CONST(UInt16, ENGMGSLT_CARTO) EngM_rLdMinRef_M[16][17];
extern CONST(UInt16, ENGMGSLT_CARTO) Ext_tAirRef1_A[8];
extern CONST(SInt16, ENGMGSLT_CARTO) Ext_tCoRef1_A[17];

#define EngMGslT_STOP_SEC_CARTO_16BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define EngMGslT_START_SEC_CALIB_16BIT
#include "EngMGslT_MemMap.h"

extern CONST(SInt16, ENGMGSLT_CALIB) EngM_agCkClsExVlvEstimRef1_B;
extern CONST(SInt16, ENGMGSLT_CALIB) EngM_agCkClsExVlvReqRef1_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_agCkClsInVlvEstimRef0_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_agCkClsInVlvEstimRef1_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_agCkOpExVlvEstimRef0_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_agCkOpExVlvEstimRef1_B;
extern CONST(SInt16, ENGMGSLT_CALIB) EngM_agCkOpInVlvEstimRef1_B;
extern CONST(SInt16, ENGMGSLT_CALIB) EngM_agCkOpInVlvReqRef1_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_facChgCorSlopEfc_A[11];
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_facMassFlowLdCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_facOfsEfcCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_facOfsEfcPred_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_facOfsEfcReq_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_facSlopEfcCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_facSlopEfcPred_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_facSlopEfcReq_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mAirCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mAirPredIn_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mAirPred_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mAirScvCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mBurnCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mTotExPredIn_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mTotExPred_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mfAirCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mfAirPredIn_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mfAirPred_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mfAirScvCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mfTotExCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mfTotExPredIn_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_mfTotExPred_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_pInMnfMinReq_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rAirLdCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rAirLdPredIn_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rAirLdPred_B;
extern CONST(SInt16, ENGMGSLT_CALIB) EngM_rDeltaLdInjPha_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rItBurnRateCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rMassAirResiCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rMassAirScvCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rMaxTotLd_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rPresLostThrPosnInfo_C;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rTotLdExCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rTotLdExPred_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_rltMassAirScvCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_tBurnCylCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_tMixtCylCor_B;
extern CONST(UInt16, ENGMGSLT_CALIB) EngM_tMixtCylGDICor_B;

#define EngMGslT_STOP_SEC_CALIB_16BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define EngMGslT_START_SEC_CALIB_BOOLEAN
#include "EngMGslT_MemMap.h"

extern CONST(Boolean, ENGMGSLT_CALIB) ENGMGSLT_ACTIVE_BYP_C;
extern CONST(Boolean, ENGMGSLT_CALIB) EngM_bAcvMPMMod_C;
extern CONST(Boolean, ENGMGSLT_CALIB) EngM_bAcvReqPres_C;
extern CONST(Boolean, ENGMGSLT_CALIB) EngM_bAcvStraLdMin_C;
extern CONST(Boolean, ENGMGSLT_CALIB) EngM_bAcvTPMMod_C;
extern CONST(Boolean, ENGMGSLT_CALIB) EngM_bSelMaxLdClcMod_C;
extern CONST(Boolean, ENGMGSLT_CALIB) Ext_bAcvTrbMod_C;

#define EngMGslT_STOP_SEC_CALIB_BOOLEAN
#include "EngMGslT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define EngMGslT_START_SEC_CALIB_8BIT
#include "EngMGslT_MemMap.h"

extern CONST(UInt8, ENGMGSLT_CALIB) EngM_agCkClsInVlvReqRef0_B;
extern CONST(UInt8, ENGMGSLT_CALIB) EngM_agCkOpExVlvReqRef0_B;
extern CONST(UInt8, ENGMGSLT_CALIB) EngM_agCkOpExVlvReqRef1_B;
extern CONST(UInt8, ENGMGSLT_CALIB) EngM_facACor_B;
extern CONST(UInt8, ENGMGSLT_CALIB) EngM_facAPred_B;
extern CONST(UInt8, ENGMGSLT_CALIB) EngM_facDCor_B;
extern CONST(UInt8, ENGMGSLT_CALIB) EngM_noPhaInjLoaEstimn_C;
extern CONST(UInt8, ENGMGSLT_CALIB) EngM_noPhaInjLoaReq_C;
extern CONST(UInt8, ENGMGSLT_CALIB) EngM_noPhaInjPredLoaEstimn_C;

#define EngMGslT_STOP_SEC_CALIB_8BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define EngMGslT_START_SEC_CARTO_8BIT
#include "EngMGslT_MemMap.h"

extern CONST(UInt8, ENGMGSLT_CARTO) EngM_facLfpPresAtmBoost_M[11][8];

#define EngMGslT_STOP_SEC_CARTO_8BIT
#include "EngMGslT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define EngMGslT_START_SEC_INTERNAL_VAR_32BIT
#include "EngMGslT_MemMap.h"

extern VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_facAtmSlop_MP;
extern VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_facBoostSlop_MP;
extern VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_mFuStmEstim;
extern VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_rLdMinCord;
extern VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_rMinLd;
extern VAR(Float32, ENGMGSLT_INTERNAL_VAR) EngM_rTotLdExPredIn;

#define EngMGslT_STOP_SEC_INTERNAL_VAR_32BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define EngMGslT_START_SEC_INTERNAL_VAR_16BIT
#include "EngMGslT_MemMap.h"

extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpFilCor_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpFilPred_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpFilReq_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpScvFilCor_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpScvFilPred;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) AirEfc_facChrExpScvFilReq_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facCorAtmSlopEfcPrev_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facCorBoostSlopEfcPrev_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facECor_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facRLdMax_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facTAirUsInVlvPrev_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_facUsThr_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_mAirMin_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_pBegCorBoostSlopEfcPrev_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_pDeltaCorSlopEfcPrev_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_001_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_002_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_003_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_004_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_005_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_006_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirPredCyl_MP[6];
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mAirScvCorCyl_MP[6];
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirCorCyl_MP[6];
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_001_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_002_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_003_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_004_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_005_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_006_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirPredCyl_MP[6];
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_mfAirScvCorCyl_MP[6];
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_001;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_002;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_003;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_004;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_005;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_006;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rAirLdPredCyl_MP[6];
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_prm_rTotLdExCorCyl_MP[6];
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLdBas_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLdMaxBas_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLdMinBas_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLdMinCor_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rLd_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMaxAvlLd_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMaxLimLd;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMinCord_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMinLd_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rMinTotLd_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rTotLdEx_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) EngM_rVolCylClsInVlvPrev_IRV_MP;
extern VAR(UInt16, ENGMGSLT_INTERNAL_VAR) InM_pDsThrPrev_IRV_MP;

#define EngMGslT_STOP_SEC_INTERNAL_VAR_16BIT
#include "EngMGslT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define EngMGslT_START_SEC_INTERNAL_VAR_8BIT
#include "EngMGslT_MemMap.h"

extern VAR(UInt8, ENGMGSLT_INTERNAL_VAR) EngM_agCkClsInVlvReqRef1_IRV_MP;
extern VAR(SInt8, ENGMGSLT_INTERNAL_VAR) EngM_facD_MP;
extern VAR(UInt8, ENGMGSLT_INTERNAL_VAR) EngM_facLfpPresAtmBoost_MP;
extern VAR(UInt8, ENGMGSLT_INTERNAL_VAR) EngM_facTCoPrev_IRV_MP;

#define EngMGslT_STOP_SEC_INTERNAL_VAR_8BIT
#include "EngMGslT_MemMap.h"
#endif                                 /* RTW_HEADER_EngMGslT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
