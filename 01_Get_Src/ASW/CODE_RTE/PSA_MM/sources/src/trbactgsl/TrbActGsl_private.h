/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActGsl                                               */
/* !Description     : TrbActGsl Software Component                            */
/*                                                                            */
/* !Module          : TrbActGsl                                               */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : TrbActGsl_private.h                                     */
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
/*   Model name       : TrbActGsl_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActGsl                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M15-TrbActGsl/5-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   15 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_TrbActGsl_private_h_
#define RTW_HEADER_TrbActGsl_private_h_
#include "Std_Types.h"
#include "TrbActGsl_types.h"
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
#define TrbActGsl_START_SEC_CODE
#include "TrbActGsl_MemMap.h"

extern void RE_TrbActGsl_002_TEV_Start(void);
extern void RE_TrbActGsl_002_TEV(void);
extern void RE_TrbActGsl_003_TEV_Start(void);
extern void RE_TrbActGsl_003_TEV(void);
extern void RE_TrbActGsl_004_TEV(void);
extern void RE_TrbActGsl_001_MSE_Start(void);
extern void RE_TrbActGsl_001_MSE(void);
void TrbActGsl_ASYNC1(int controlPortIdx);
void TrbActGsl_ASYNC2(int controlPortIdx);
void TrbActGsl_ASYNC3(int controlPortIdx);
void TrbActGsl_ASYNC4(int controlPortIdx);

#define TrbActGsl_STOP_SEC_CODE
#include "TrbActGsl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CARTO_16BIT" */
#define TrbActGsl_START_SEC_CARTO_16BIT
#include "TrbActGsl_MemMap.h"

extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_facFltRCOReqWoutAdp_T[9];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_facFltUsPresCorErr_T[9];
extern CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifPnmActEstim_M[9][9];
extern CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifPnmActReq_A[16];
extern CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifTrbActEstim_A[16];
extern CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifTrbActReqAdd_M[9][16];
extern CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pDifTrbActReq_M[16][16];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_pDsCmpr_A[16];
extern CONST(SInt16, TRBACTGSL_CARTO) TrbAct_pUsThrCorErrFil_A[9];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rOpTrbActEstim_M[16][16];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rOpTrbActReq_A[16];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOReqAddCor_T[16];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOReqAdd_A[16];
extern CONST(SInt16, TRBACTGSL_CARTO) TrbAct_rRCOReqFastAddCor_T[9];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOReq_A[9];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOReq_M[16][9];
extern CONST(UInt16, TRBACTGSL_CARTO) TrbAct_rRCOTestMod_M[9][9];
extern CONST(SInt16, TRBACTGSL_CARTO) TrbAct_tqIdcAirReq_A[9];

#define TrbActGsl_STOP_SEC_CARTO_16BIT
#include "TrbActGsl_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define TrbActGsl_START_SEC_CALIB_16BIT
#include "TrbActGsl_MemMap.h"

extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facFilGainTrbActPosn_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facFltPresDsCmpr_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facPresReqAdpOfs_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facPresReqAdpRate_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facRCOReqAdpOfs_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_facRCOReqAdpRate_C;
extern CONST(SInt16, TRBACTGSL_CALIB) TrbAct_pDifMaxPnmActReq_B;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_pDifPnmActHys_C;
extern CONST(SInt16, TRBACTGSL_CALIB) TrbAct_pDifTrbActReq_B;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_pUsThrCorErrMax_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_pUsThrCorErrMin_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_pVacRef_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rCtlIntErrMax_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rCtlIntErrMin_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpRCOAdpOfsThd1_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpRCOAdpOfsThd2_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpRCOAdpRateThd1_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpRCOAdpRateThd2_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpTrbActEstimIni_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpTrbActEstim_B;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rOpTrbAct_B;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOMaxThd_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOMinThd_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpOfsMax_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpOfsMin_C;
extern CONST(SInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpOfs_B;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpRateMax_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpRateMin_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqAdpRate_B;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqIni_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReqRaw_B;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReq_B;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOReq_C;
extern CONST(UInt16, TRBACTGSL_CALIB) TrbAct_rRCOTestMod_C;

#define TrbActGsl_STOP_SEC_CALIB_16BIT
#include "TrbActGsl_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define TrbActGsl_START_SEC_CALIB_BOOLEAN
#include "TrbActGsl_MemMap.h"

extern CONST(Boolean, TRBACTGSL_CALIB) TRBACTGSL_ACTIVE_BYP_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bAcvRCOAdp_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bAcvRCOModTest_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bAcvRCOTestModRef1_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bAcvRCOTestModRef2_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bExtMnfPresSel_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bInhTrbActCtlIni_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bInhTrbActCtl_B;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bOpRCOAdpSel_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bPresDifSel_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bRCOAdpSel_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bRCOReqSel_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bSelRCOCorReq_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bSelRatOpTrbAct_C;
extern CONST(Boolean, TRBACTGSL_CALIB) TrbAct_bUpPresAdpSel_C;

#define TrbActGsl_STOP_SEC_CALIB_BOOLEAN
#include "TrbActGsl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define TrbActGsl_START_SEC_INTERNAL_VAR_32BIT
#include "TrbActGsl_MemMap.h"

extern VAR(Float32, TRBACTGSL_INTERNAL_VAR) TrbAct_rOpTrbActEstimPrev;
extern VAR(SInt32, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqAdpOfsErr_MP;
extern VAR(SInt32, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqAdpRateErr_MP;

#define TrbActGsl_STOP_SEC_INTERNAL_VAR_32BIT
#include "TrbActGsl_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define TrbActGsl_START_SEC_INTERNAL_VAR_16BIT
#include "TrbActGsl_MemMap.h"

extern VAR(UInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_facFltRCOReq_MP;
extern VAR(UInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_facFltUsPresCorErr_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifPnmActReq;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifTrbActEstim_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifTrbActReqAdd_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifTrbActReqBas_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pDifTrbEstim_IRV_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_pUsThrCorErr_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rCtlIntErr_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOFastAddCor_MP;
extern VAR(UInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqAddCor_MP;
extern VAR(UInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqAdd_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqFastAdpOfs_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqWoutAdpBas_MP;
extern VAR(SInt16, TRBACTGSL_INTERNAL_VAR) TrbAct_rRCOReqWoutAdpFlt_MP;
extern VAR(UInt16, TRBACTGSL_INTERNAL_VAR) UsThrM_pDsCmprFlt_MP;

#define TrbActGsl_STOP_SEC_INTERNAL_VAR_16BIT
#include "TrbActGsl_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define TrbActGsl_START_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActGsl_MemMap.h"

extern VAR(Boolean, TRBACTGSL_INTERNAL_VAR) TrbAct_bAcvOfsRCOAdp_MP;
extern VAR(Boolean, TRBACTGSL_INTERNAL_VAR) TrbAct_bAcvRateRCOAdp_MP;

#define TrbActGsl_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActGsl_MemMap.h"
#endif                                 /* RTW_HEADER_TrbActGsl_private_h_ */

/*-------------------------------- end of file -------------------------------*/
