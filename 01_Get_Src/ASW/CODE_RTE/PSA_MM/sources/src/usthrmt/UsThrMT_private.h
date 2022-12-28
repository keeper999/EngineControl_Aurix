/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : UsThrMT                                                 */
/* !Description     : UsThrMT Software Component                              */
/*                                                                            */
/* !Module          : UsThrMT                                                 */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : UsThrMT_private.h                                       */
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
/*   Model name       : UsThrMT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /UsThrMT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M01-UsThrMT/5-SO$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   14 Nov 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_UsThrMT_private_h_
#define RTW_HEADER_UsThrMT_private_h_
#include "Std_Types.h"
#include "UsThrMT_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define UsThrM_tiSampleFast_SC         ((UInt16) 10U)
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
#define UsThrMT_START_SEC_CODE
#include "UsThrMT_MemMap.h"

extern void RE_UsThrMT_008_DRE(void);
extern void RE_UsThrMT_009_DRE(void);
extern void RE_UsThrMT_001_MSE_Start(void);
extern void RE_UsThrMT_001_MSE(void);
extern void UsThrMT_filtrage(Float32 rtu_INPUT, Float32 rtu_Init_IRV, UInt16
  rtu_GAIN, rtB_filtrage_UsThrMT *localB);
extern void RE_UsThrMT_010_TEV_Start(void);
extern void RE_UsThrMT_010_TEV(void);
extern void RE_UsThrMT_011_TEV(void);
extern void RE_UsThrMT_007_TEV_Init(void);
extern void RE_UsThrMT_007_TEV(void);
extern void RE_UsThrMT_006_TEV_Start(void);
extern void RE_UsThrMT_006_TEV(void);
extern void RE_UsThrMT_002_TEV_Start(void);
extern void RE_UsThrMT_002_TEV(void);
extern void RE_UsThrMT_012_TEV(void);
extern void UsThrMT_filtrage_a(Float32 rtu_GAIN, Float32 rtu_INPUT, Float32
  rtu_Init_IRV, rtB_filtrage_UsThrMT_c *localB);
extern void RE_UsThrMT_005_TEV_Start(void);
extern void RE_UsThrMT_005_TEV(void);
extern void RE_UsThrMT_004_MSE_Start(void);
extern void RE_UsThrMT_004_MSE(void);
extern void RE_UsThrMT_008_TEV(void);
void UsThrMT_ASYNC1(int controlPortIdx);
void UsThrMT_ASYNC2(int controlPortIdx);
void UsThrMT_ASYNC3(int controlPortIdx);
void UsThrMT_ASYNC4(int controlPortIdx);
void UsThrMT_ASYNC5(int controlPortIdx);
void UsThrMT_ASYNC6(int controlPortIdx);
void UsThrMT_ASYNC7(int controlPortIdx);
void UsThrMT_ASYNC8(int controlPortIdx);
void UsThrMT_ASYNC9(int controlPortIdx);
void UsThrMT_ASYNC10(int controlPortIdx);

#define UsThrMT_STOP_SEC_CODE
#include "UsThrMT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CARTO_16BIT" */
#define UsThrMT_START_SEC_CARTO_16BIT
#include "UsThrMT_MemMap.h"

extern CONST(UInt16, USTHRMT_CARTO) UsThrM_mfAirThr_A[16];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_nEng_A[9];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_pDifCACAirThr_T[16];
extern CONST(SInt16, USTHRMT_CARTO) UsThrM_pDifCmprAirThr_T[16];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_pDsThrMesThdAfu_T[9];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_pDsThrMesThd_T[9];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_pLossAirFil_T[16];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_rFilTUndHo_M[9][3];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_rFilTUsCmpr_M[9][3];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_rMinThrUpdAirExtPres_T[16];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_rMinTrbThrUpdAirExtPres_T[16];
extern CONST(UInt16, USTHRMT_CARTO) UsThrM_spdVeh_A[9];

#define UsThrMT_STOP_SEC_CARTO_16BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define UsThrMT_START_SEC_CALIB_16BIT
#include "UsThrMT_MemMap.h"

extern CONST(UInt16, USTHRMT_CALIB) Air_pAirExtRef_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_facPresAltiCor_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_nCutThd_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_nIdlThd_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_nUpdAirExtPresThd_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pAirExtDft_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pAirExtMesCor_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pAirExt_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pDsCmpr_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pDsThrAcvAirExtCtlMod_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pDsThrMesCor_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pDsThrMesHys_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pLossAirFil_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pLossCAC_B;
extern CONST(SInt16, USTHRMT_CALIB) UsThrM_pLossCmpr_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pLossThd_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pOfsMaxAirExtPres_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pStallThd_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pUsCmpr_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pUsThrCor_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pUsThrMesCor_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_pUsThrTrbCor_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_rFilMes_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_rFilPresAirExt_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_rMaxThrStabThd_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_tThrMes_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_tUsCmpr_B;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_tiDlyThrStab_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_tiDlyUpdAirExtPresIdl_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_tiDlyUpdAirExtPresStall_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_tiDlyUpdAirExtPres_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_tiTmrDifPres_C;
extern CONST(UInt16, USTHRMT_CALIB) UsThrM_tiUpdAirExtPresInjCut_C;

#define UsThrMT_STOP_SEC_CALIB_16BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define UsThrMT_START_SEC_CARTO_8BIT
#include "UsThrMT_MemMap.h"

extern CONST(UInt8, USTHRMT_CARTO) UsThrM_rEthWoutExctCor_T[8];
extern CONST(UInt8, USTHRMT_CARTO) UsThrM_rEthWoutExct_A[8];
extern CONST(UInt8, USTHRMT_CARTO) UsThrM_rFacTUndHo_M[9][3];
extern CONST(UInt8, USTHRMT_CARTO) UsThrM_rSpdFan_A[3];

#define UsThrMT_STOP_SEC_CARTO_8BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define UsThrMT_START_SEC_CALIB_BOOLEAN
#include "UsThrMT_MemMap.h"

extern CONST(Boolean, USTHRMT_CALIB) USTHRMT_ACTIVE_BYP_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bAcvAirExtCtlMod_B;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bAcvAltiCor_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bAcvEth_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bInhPresSenAdj_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bInhTOil_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bInhTUsCmprEstim_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bPresDsThrSenRef_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bPresUsThrSenRef_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bSelTSen1_C;
extern CONST(Boolean, USTHRMT_CALIB) UsThrM_bSelTSen2_C;

#define UsThrMT_STOP_SEC_CALIB_BOOLEAN
#include "UsThrMT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define UsThrMT_START_SEC_CALIB_8BIT
#include "UsThrMT_MemMap.h"

extern CONST(UInt8, USTHRMT_CALIB) UsThrM_pDeUsThr_C;
extern CONST(UInt8, USTHRMT_CALIB) UsThrM_tSqrtInAir_B;

#define UsThrMT_STOP_SEC_CALIB_8BIT
#include "UsThrMT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define UsThrMT_START_SEC_INTERNAL_VAR_32BIT
#include "UsThrMT_MemMap.h"

extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pAirExtMesSIFilPrev;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pAirExt_prev;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefAirExt;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefAirExtClc;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefDsThr;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefDsThrClc;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefUsThr;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDifPresRefUsThrClc;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesSIFilPrev;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesThd;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesThdGsl;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pSenRef;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_pUsThrMesSIFilPrev;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tAirExt;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tEng;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tUndHoPrev;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tUndHo_IRV_MP;
extern VAR(Float32, USTHRMT_INTERNAL_VAR) UsThrM_tUsCmprPrev;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_32BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define UsThrMT_START_SEC_INTERNAL_VAR_16BIT
#include "UsThrMT_MemMap.h"

extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresCut_IRV_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresCut_prev;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresIdl_IRV_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresIdl_prev;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresRun_IRV_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresRun_prev;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresStall;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_ctUpdAirExtPresStall_prev;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pAirExtMesSIFil_IRV_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pAirExtRaw_IRV_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pAirExtRaw_prev;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesSIFil_IRV_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pDsThrMesThdAfu_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pUsThrAtmCor_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pUsThrCorPrev;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_pUsThrMesSIFil_IRV_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_tUndHoRaw_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_tiTmrDifPresPrev;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_tiTmrDifPres_IRV_MP;
extern VAR(UInt16, USTHRMT_INTERNAL_VAR) UsThrM_tiTmrDifPres_SF;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_16BIT
#include "UsThrMT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define UsThrMT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "UsThrMT_MemMap.h"

extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvTrbUpdAirExtPres;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvUpdAirExtPresCut;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvUpdAirExtPresIdl;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvUpdAirExtPresTrb;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bAcvUpdThrStab_MP;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bDifPresAvl;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bDifPresAvl_SF;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bDifPresClcEna;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bDifPresClcEna_SF;
extern VAR(Boolean, USTHRMT_INTERNAL_VAR) UsThrM_bUpdAirExtPresStall;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "UsThrMT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define UsThrMT_START_SEC_INTERNAL_VAR_8BIT
#include "UsThrMT_MemMap.h"

extern VAR(UInt8, USTHRMT_INTERNAL_VAR) UsThrM_rEthWoutExctCor_MP;

#define UsThrMT_STOP_SEC_INTERNAL_VAR_8BIT
#include "UsThrMT_MemMap.h"
#endif                                 /* RTW_HEADER_UsThrMT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
