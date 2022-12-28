/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngLimTqT                                               */
/* !Description     : EngLimTqT Software Component                            */
/*                                                                            */
/* !Module          : EngLimTqT                                               */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : EngLimTqT_private.h                                     */
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
/*   Model name       : EngLimTqT_AUTOSAR.mdl                                 */
/*   Root subsystem   : /EngLimTqT                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M01-EngLimTqT/5$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Sep 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_EngLimTqT_private_h_
#define RTW_HEADER_EngLimTqT_private_h_
#include "Std_Types.h"
#include "EngLimTqT_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
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
#define EngLimTqT_START_SEC_CODE
#include "EngLimTqT_MemMap.h"

extern void RE_EngLimTqT_011_MSE_Start(void);
extern void RE_EngLimTqT_011_MSE(void);
extern void RE_EngLimTqT_013_MSE_Start(void);
extern void RE_EngLimTqT_013_MSE(void);
extern void RE_EngLimTqT_009_MSE_Start(void);
extern void RE_EngLimTqT_009_MSE(void);
extern void RE_EngLimTqT_001_MSE_Start(void);
extern void RE_EngLimTqT_001_MSE(void);
extern void RE_EngLimTqT_003_MSE_Start(void);
extern void RE_EngLimTqT_003_MSE(void);
extern void RE_EngLimTqT_005_MSE(void);
extern void RE_EngLimTqT_007_MSE(void);
extern void RE_EngLimTqT_012_DRE_Start(void);
extern void RE_EngLimTqT_012_DRE(void);
extern void RE_EngLimTqT_014_DRE_Start(void);
extern void RE_EngLimTqT_014_DRE(void);
extern void RE_EngLimTqT_002_DRE_Start(void);
extern void RE_EngLimTqT_002_DRE(void);
extern void RE_EngLimTqT_004_DRE_Start(void);
extern void RE_EngLimTqT_004_DRE(void);
extern void RE_EngLimTqT_006_DRE(void);
extern void RE_EngLimTqT_008_DRE(void);
extern void RE_EngLimTqT_010_TEV_Start(void);
extern void RE_EngLimTqT_010_TEV(void);
void EngLimTqT_ASYNC1(int controlPortIdx);
void EngLimTqT_ASYNC2(int controlPortIdx);
void EngLimTqT_ASYNC3(int controlPortIdx);
void EngLimTqT_ASYNC4(int controlPortIdx);
void EngLimTqT_ASYNC5(int controlPortIdx);
void EngLimTqT_ASYNC6(int controlPortIdx);
void EngLimTqT_ASYNC7(int controlPortIdx);
void EngLimTqT_ASYNC8(int controlPortIdx);
void EngLimTqT_ASYNC9(int controlPortIdx);
void EngLimTqT_ASYNC10(int controlPortIdx);
void EngLimTqT_ASYNC11(int controlPortIdx);
void EngLimTqT_ASYNC12(int controlPortIdx);
void EngLimTqT_ASYNC13(int controlPortIdx);
void EngLimTqT_ASYNC14(int controlPortIdx);
void EngLimTqT_ASYNC15(int controlPortIdx);
void EngLimTqT_ASYNC16(int controlPortIdx);
void EngLimTqT_ASYNC17(int controlPortIdx);
void EngLimTqT_ASYNC18(int controlPortIdx);
void EngLimTqT_ASYNC19(int controlPortIdx);
void EngLimTqT_ASYNC20(int controlPortIdx);

#define EngLimTqT_STOP_SEC_CODE
#include "EngLimTqT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define EngLimTqT_START_SEC_CALIB_32BIT
#include "EngLimTqT_MemMap.h"

extern CONST(UInt32, ENGLIMTQT_CALIB) IgSys_lamClc_B;

#define EngLimTqT_STOP_SEC_CALIB_32BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define EngLimTqT_START_SEC_CARTO_16BIT
#include "EngLimTqT_MemMap.h"

extern CONST(SInt16, ENGLIMTQT_CARTO) EngLim_tqIdcPresUsThrMax_T[16];
extern CONST(UInt16, ENGLIMTQT_CARTO) IgSys_rIgEfc_EfcIg_T[104];

#define EngLimTqT_STOP_SEC_CARTO_16BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define EngLimTqT_START_SEC_CALIB_16BIT
#include "EngLimTqT_MemMap.h"

extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcAdvOptmTrbMax_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcAirResMax_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcAirTqWoutTotCutOf_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCurGBx_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCurMax_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCurMinSelc_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCurMin_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcEngCur_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcLdMaxTrbMaxNoOvb_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcLdMaxTrbMax_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcLdMinAdvMinSelc_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcLdMinAdvMin_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) EngLim_tqIdcPresUsThrMax_B;
extern CONST(UInt16, ENGLIMTQT_CALIB) IgSys_facTqtoPresIdc_C;
extern CONST(UInt16, ENGLIMTQT_CALIB) IgSys_nEngStallThd_C;
extern CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rDynIgSpEfc_B;
extern CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rMaxIgEfc_B;
extern CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rMinIgEfc_B;
extern CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rStatIgSpEfc_B;
extern CONST(UInt16, ENGLIMTQT_CALIB) IgSys_rlamClc_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) IgSys_tqIdcEstim_B;
extern CONST(SInt16, ENGLIMTQT_CALIB) IgSys_tqIdcLimMin_C;
extern CONST(SInt16, ENGLIMTQT_CALIB) IgSys_tqIdcThdMin_C;

#define EngLimTqT_STOP_SEC_CALIB_16BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define EngLimTqT_START_SEC_CALIB_8BIT
#include "EngLimTqT_MemMap.h"

extern CONST(UInt8, ENGLIMTQT_CALIB) IgSys_noTDCCutOffDly_B;
extern CONST(UInt8, ENGLIMTQT_CALIB) IgSys_noTDCCutOffDly_C;
extern CONST(UInt8, ENGLIMTQT_CALIB) IgSys_noTDCOutCutOffDly_B;
extern CONST(UInt8, ENGLIMTQT_CALIB) IgSys_noTDCOutCutOffDly_C;
extern CONST(UInt8, ENGLIMTQT_CALIB) IgSys_stIgAgEfcGBx_C;
extern CONST(UInt8, ENGLIMTQT_CALIB) IgSys_stIgAgEfc_C;

#define EngLimTqT_STOP_SEC_CALIB_8BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define EngLimTqT_START_SEC_CALIB_BOOLEAN
#include "EngLimTqT_MemMap.h"

extern CONST(Boolean, ENGLIMTQT_CALIB) ENGLIMTQT_ACTIVE_BYP_C;
extern CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLam1_C;
extern CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLam2_C;
extern CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLamClc_C;
extern CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLamEfcGBx_C;
extern CONST(Boolean, ENGLIMTQT_CALIB) IgSys_bLamEfc_C;
extern CONST(Boolean, ENGLIMTQT_CALIB) IgSys_btqIdcPresUsThrMax_C;

#define EngLimTqT_STOP_SEC_CALIB_BOOLEAN
#include "EngLimTqT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define EngLimTqT_START_SEC_CARTO_8BIT
#include "EngLimTqT_MemMap.h"

extern CONST(UInt8, ENGLIMTQT_CARTO) IgSys_agIg_EfcIg_A[104];

#define EngLimTqT_STOP_SEC_CARTO_8BIT
#include "EngLimTqT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define EngLimTqT_START_SEC_INTERNAL_VAR_32BIT
#include "EngLimTqT_MemMap.h"

extern VAR(Float32, ENGLIMTQT_INTERNAL_VAR) IgSys_facLamReqCor;
extern VAR(Float32, ENGLIMTQT_INTERNAL_VAR) IgSys_rMaxIgEfcWoutMv;
extern VAR(UInt32, ENGLIMTQT_INTERNAL_VAR) IgSys_rlamEngCorReqPrev;
extern VAR(UInt32, ENGLIMTQT_INTERNAL_VAR) IgSys_rlamEngCorReq_IRV_MP;
extern VAR(Float32, ENGLIMTQT_INTERNAL_VAR) IgSys_tqIdcEstimPrev;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_32BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define EngLimTqT_START_SEC_INTERNAL_VAR_16BIT
#include "EngLimTqT_MemMap.h"

extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_presIdcEngCur;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcAdvOptmMaxWoutOfs;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcEstimMax_MP;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcEstim_MP;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcMaxWoutOvb_MP;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcMinAirLdAvgCyl;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcMinAirLd_IRV_MP;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcPresMinEstim_MP;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcPresUsMax_IRV_MP;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) EngLim_tqIdcTrbMaxWoutOvb_IRV_MP;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_facTarAgCorSwtDyn_MP;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_facTarAgCorSwtMax_MP;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_facTarAgCorSwtMin_MP;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_facTarAgCorSwtStat_MP;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_01;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_02;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_03;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_04;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_05;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcCyl_06;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rDynIgSpEfcPrevCyl[6];
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_01;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_02;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_03;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_04;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_05;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcCyl_06;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rMaxIgSpEfcPrevCyl[6];
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_01;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_02;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_03;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_04;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_05;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcCyl_06;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_prm_rStatIgSpEfcPrevCyl[6];
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rAirLdPredPrev;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rAirLdPred_IRV_MP;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rDynIgSpEfcWoutMv_IRV_MP;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rMaxIgEfcWoutMv_MP;
extern VAR(UInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_rStatIgSpEfcWoutMv_IRV_MP;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_tqIdcEstimAvgCylWiLam;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_tqIdcEstimAvgCylWoutLam;
extern VAR(SInt16, ENGLIMTQT_INTERNAL_VAR) IgSys_tqIdcEstimAvgCyl_IRV_MP;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_16BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define EngLimTqT_START_SEC_INTERNAL_VAR_8BIT
#include "EngLimTqT_MemMap.h"

extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_agIgEfcDyn_MP;
extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_agIgEfcMax_MP;
extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_agIgEfcMin_MP;
extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_agIgEfcStat_MP;
extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylCutOffDlyOutSat;
extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylCutOffSat;
extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylCutOffSatDly;
extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylInc1_IRV_MP;
extern VAR(UInt8, ENGLIMTQT_INTERNAL_VAR) IgSys_noCylIncPrev1;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_8BIT
#include "EngLimTqT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define EngLimTqT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "EngLimTqT_MemMap.h"

extern VAR(Boolean, ENGLIMTQT_INTERNAL_VAR) IgSys_bCylCutOffSat;
extern VAR(Boolean, ENGLIMTQT_INTERNAL_VAR) IgSys_bCylCutOffTrigSat;
extern VAR(Boolean, ENGLIMTQT_INTERNAL_VAR) IgSys_bTotCutOffDly;
extern VAR(Boolean, ENGLIMTQT_INTERNAL_VAR) IgSys_bTqIdcCutOff_IRV_MP;

#define EngLimTqT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "EngLimTqT_MemMap.h"
#endif                                 /* RTW_HEADER_EngLimTqT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
