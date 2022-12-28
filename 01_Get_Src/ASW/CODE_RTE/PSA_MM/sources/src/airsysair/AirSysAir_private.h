/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysAir                                               */
/* !Description     : AirSysAir Software Component                            */
/*                                                                            */
/* !Module          : AirSysAir                                               */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AirSysAir_private.h                                     */
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
/*   Model name       : AirSysAir_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysAir                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M17-AirSysAir/5-$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AirSysAir_private_h_
#define RTW_HEADER_AirSysAir_private_h_
#include "Std_Types.h"
#include "AirSysAir_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define AirSys_tiSampleFast_SC         ((UInt16) 20U)
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
#define AirSysAir_START_SEC_CODE
#include "AirSysAir_MemMap.h"

extern void RE_AirSysAir_001_MSE_Start(void);
extern void RE_AirSysAir_001_MSE(void);
extern void RE_AirSysAir_003_TEV_Start(void);
extern void RE_AirSysAir_003_TEV(void);
extern void RE_AirSysAir_004_TEV_Start(void);
extern void RE_AirSysAir_004_TEV(void);
extern void RE_AirSysAir_006_TEV_Start(void);
extern void RE_AirSysAir_006_TEV(void);
extern void RE_AirSysAir_007_TEV_Start(void);
extern void RE_AirSysAir_007_TEV(void);
extern void RE_AirSysAir_005_TEV(void);
extern void RE_AirSysAir_002_TEV(void);
void AirSysAir_ASYNC1(int controlPortIdx);
void AirSysAir_ASYNC2(int controlPortIdx);
void AirSysAir_ASYNC3(int controlPortIdx);
void AirSysAir_ASYNC4(int controlPortIdx);
void AirSysAir_ASYNC5(int controlPortIdx);
void AirSysAir_ASYNC6(int controlPortIdx);
void AirSysAir_ASYNC7(int controlPortIdx);
void AirSysAir_ASYNC8(int controlPortIdx);
void AirSysAir_ASYNC9(int controlPortIdx);
void AirSysAir_ASYNC10(int controlPortIdx);

#define AirSysAir_STOP_SEC_CODE
#include "AirSysAir_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define AirSysAir_START_SEC_CALIB_32BIT
#include "AirSysAir_MemMap.h"

extern CONST(UInt32, AIRSYSAIR_CALIB) AirSys_mAirEngIntCor_B;
extern CONST(UInt32, AIRSYSAIR_CALIB) AirSys_tiAcvDlyDmp_C;
extern CONST(UInt32, AIRSYSAIR_CALIB) AirSys_tiSampleFastThr_C;

#define AirSysAir_STOP_SEC_CALIB_32BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Declare data in section "CARTO_32BIT" */
#define AirSysAir_START_SEC_CARTO_32BIT
#include "AirSysAir_MemMap.h"

extern CONST(UInt32, AIRSYSAIR_CARTO) AirSys_facCfe_T[22];
extern CONST(UInt32, AIRSYSAIR_CARTO) AirSys_tiDmpDec_T[8];
extern CONST(UInt32, AIRSYSAIR_CARTO) AirSys_tiTqDec_T[8];

#define AirSysAir_STOP_SEC_CARTO_32BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define AirSysAir_START_SEC_CARTO_16BIT
#include "AirSysAir_MemMap.h"

extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_arEfcThrReqTqY_A[6];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_facArEfcThrFil_M[8][6];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_facFilGain_M[10][12];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_faciMassIntCorRef1_T[9];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_facpMassIntCorRef1_M[10][9];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_mEngAirErr_A[9];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_mfAirThrReq_A[8];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_mfFuStmMax_T[8];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEngArFilGainX_A[8];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEngDec_A[8];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEngFilGainX_A[10];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEngTq_A[8];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_nEng_A[10];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_prm_mfAirThrReq_B[2];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_prm_pInMnfReq_B[2];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresCorFilGainY_A[12];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresFilGain_A[9];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresFilGain_M[10][12];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresFilGain_T[9];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rAirPresRawFilGainX_A[10];
extern CONST(UInt16, AIRSYSAIR_CARTO) AirSys_rMaxThrPosn_T[10];
extern CONST(SInt16, AIRSYSAIR_CARTO) AirSys_tqLoThd_T[8];

#define AirSysAir_STOP_SEC_CARTO_16BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define AirSysAir_START_SEC_CALIB_16BIT
#include "AirSysAir_MemMap.h"

extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_arEfcThrMax_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_arThrReq_B;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_facFilArEfcThr_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mAirEngCylMaxReq_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mAirEngCylReq_tqEng_B;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mAirEngCylThdReq_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mAirEngCylThd_C;
extern CONST(SInt16, AIRSYSAIR_CALIB) AirSys_mEngAirIntCorMin_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_mEngAirThd_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pCllThrHyst_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pCllThrThd_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pFilInhHiThd_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pFilInhLoThd_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pNoiseNegThd_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_pNoiseThd_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rAirLdReq_B;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rFrzHiThd_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rFrzLoThd_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rMinThrPosn_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_rOpThrReqMaxOfs_C;
extern CONST(UInt16, AIRSYSAIR_CALIB) AirSys_tiDlyAftEgrFoul_C;
extern CONST(SInt16, AIRSYSAIR_CALIB) AirSys_tqOfsHiThd_C;

#define AirSysAir_STOP_SEC_CALIB_16BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AirSysAir_START_SEC_CALIB_BOOLEAN
#include "AirSysAir_MemMap.h"

extern CONST(Boolean, AIRSYSAIR_CALIB) AIRSYSAIR_ACTIVE_BYP_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bActStraLimSurge_B;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvDeceThrCtl_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvDlyThr2_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvDlyThr_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvFilArEfcThr_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvFilAr_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvInhCfeFilDmp_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvInhCfeFilTq_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvStraTqReq_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvTqReqASR_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bAcvTqReq_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bArMaxInh_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bFilGain_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhFilRat_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhFullLdCtl_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhPIIdl_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhPILimSurge_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bInhPiAirEngCor_B;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bPresTrb_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bSelClcMod_pDsThrReq_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bSelMAirEngCylReq_C;
extern CONST(Boolean, AIRSYSAIR_CALIB) AirSys_bSelMaxThrPosn_C;

#define AirSysAir_STOP_SEC_CALIB_BOOLEAN
#include "AirSysAir_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define AirSysAir_START_SEC_CALIB_8BIT
#include "AirSysAir_MemMap.h"

extern CONST(UInt8, AIRSYSAIR_CALIB) AirSys_mEngAirIntCorMax_C;
extern CONST(UInt8, AIRSYSAIR_CALIB) AirSys_rAirPresMaxDif_C;
extern CONST(UInt8, AIRSYSAIR_CALIB) AirSys_rFrzPres_C;

#define AirSysAir_STOP_SEC_CALIB_8BIT
#include "AirSysAir_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define AirSysAir_START_SEC_INTERNAL_VAR_32BIT
#include "AirSysAir_MemMap.h"

extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqDmpSysFil;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqTqSysFil;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqTqSysRaw;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_facAcvDmp;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_facAcvTq;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_facArEfcThrFilGain;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngIntCorPrev;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngPropCor;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngSelReq;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mEngAirCorOfs;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mEngAirErr;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_mfAirThrReq_arThr;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_pInMnfOplReq;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_pInMnfReq;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_pInMnfReq_tqEng;
extern VAR(UInt32, AIRSYSAIR_INTERNAL_VAR) AirSys_prm_mAirEngReq_MP[2];
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresFinal;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresRaw;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresReqFil;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresReqNoFil;
extern VAR(Float32, AIRSYSAIR_INTERNAL_VAR) AirSys_rFilGainPresRat;

#define AirSysAir_STOP_SEC_INTERNAL_VAR_32BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define AirSysAir_START_SEC_INTERNAL_VAR_16BIT
#include "AirSysAir_MemMap.h"

extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqDmpSys_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqTqSysSat;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrReqTqSys_IRV_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_arEfcThrTq_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_facArEfcThrFilGain_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_facCfe_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngCorReq_IRV_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_mAirEngCylSurgeLimReq_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_prm_mAirCylReq_IRV_MP[2];
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresCor_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresInter_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresReqPrev;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPresReq_IRV_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_rAirPres_MP;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_tiDlyAftEgrFoulPrev;
extern VAR(UInt16, AIRSYSAIR_INTERNAL_VAR) AirSys_tiDlyAftEgrFoul_IRV_MP;

#define AirSysAir_STOP_SEC_INTERNAL_VAR_16BIT
#include "AirSysAir_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AirSysAir_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AirSysAir_MemMap.h"

extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bActStraLimSurgeDmpSw;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bAcvDmp;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bAcvDmpRaw_MP;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bAcvTq;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bAcvTqRaw_MP;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhCfeFil;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPIAccPMin;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPIEgrFoul;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPILimSurge;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPIStructAirOpl;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPIThrLim;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhPITranLdDet;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bInhTrbAirPresRatCtl;
extern VAR(Boolean, AIRSYSAIR_INTERNAL_VAR) AirSys_bThrEff_MP;

#define AirSysAir_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AirSysAir_MemMap.h"
#endif                                 /* RTW_HEADER_AirSysAir_private_h_ */

/*-------------------------------- end of file -------------------------------*/
