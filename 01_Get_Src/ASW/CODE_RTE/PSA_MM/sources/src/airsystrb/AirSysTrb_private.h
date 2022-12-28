/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysTrb                                               */
/* !Description     : AirSysTrb Software Component                            */
/*                                                                            */
/* !Module          : AirSysTrb                                               */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AirSysTrb_private.h                                     */
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
/*   Model name       : AirSysTrb_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysTrb                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M18-AirSysTrb/5-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   PLCHINAZ                               $$Date::   30 Jun 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AirSysTrb_private_h_
#define RTW_HEADER_AirSysTrb_private_h_
#include "Std_Types.h"
#include "AirSysTrb_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define AirSys_tiSampleFast_SC         ((UInt16) 19U)
#ifndef PORTABLE_WORDSIZES
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
#endif                                 /* PORTABLE_WORDSIZES */

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
#define AirSysTrb_START_SEC_CODE
#include "AirSysTrb_MemMap.h"

extern void RE_AirSysTrb_005_TEV_Start(void);
extern void RE_AirSysTrb_005_TEV(void);
extern void RE_AirSysTrb_004_TEV_Start(void);
extern void RE_AirSysTrb_004_TEV(void);
extern void RE_AirSysTrb_003_TEV_Start(void);
extern void RE_AirSysTrb_003_TEV(void);
extern void RE_AirSysTrb_002_TEV_Start(void);
extern void RE_AirSysTrb_002_TEV(void);
extern void RE_AirSysTrb_001_MSE_Start(void);
extern void RE_AirSysTrb_001_MSE(void);
void AirSysTrb_ASYNC1(int controlPortIdx);
void AirSysTrb_ASYNC2(int controlPortIdx);
void AirSysTrb_ASYNC3(int controlPortIdx);
void AirSysTrb_ASYNC4(int controlPortIdx);
void AirSysTrb_ASYNC5(int controlPortIdx);

#define AirSysTrb_STOP_SEC_CODE
#include "AirSysTrb_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CARTO_16BIT" */
#define AirSysTrb_START_SEC_CARTO_16BIT
#include "AirSysTrb_MemMap.h"

extern CONST(UInt16, AIRSYSTRB_CARTO) AirSys_facFilGainTrbMod_T[9];
extern CONST(UInt16, AIRSYSTRB_CARTO) AirSys_facFilGainUsThrPres_T[9];
extern CONST(UInt16, AIRSYSTRB_CARTO) AirSys_facRatPresThrClcn_A[9];
extern CONST(UInt16, AIRSYSTRB_CARTO) AirSys_rAirPresThr_T[9];
extern CONST(UInt16, AIRSYSTRB_CARTO) Air_pLossAirFil_T[16];
extern CONST(UInt16, AIRSYSTRB_CARTO) Air_pLossCAC_T[16];

#define AirSysTrb_STOP_SEC_CARTO_16BIT
#include "AirSysTrb_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define AirSysTrb_START_SEC_CALIB_16BIT
#include "AirSysTrb_MemMap.h"

extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_mfAirThrReqFil_B;
extern CONST(SInt16, AIRSYSTRB_CALIB) AirSys_pDifDsCmprUsThrReq_B;
extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pDsCmprReqFil_B;
extern CONST(SInt16, AIRSYSTRB_CALIB) AirSys_pGrdUsThrHiThd_C;
extern CONST(SInt16, AIRSYSTRB_CALIB) AirSys_pGrdUsThrInhFrzThd_C;
extern CONST(SInt16, AIRSYSTRB_CALIB) AirSys_pGrdUsThrLoThd_C;
extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pLossAirThrMax_C;
extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pUsCmprReqFil_B;
extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pUsThrReqFil_B;
extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_pUsThrReq_B;
extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_tiDlyDetAccPNull_C;
extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_tiDlyDetPGrdUsThr_C;
extern CONST(UInt16, AIRSYSTRB_CALIB) AirSys_tiDlyFrz_C;

#define AirSysTrb_STOP_SEC_CALIB_16BIT
#include "AirSysTrb_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AirSysTrb_START_SEC_CALIB_BOOLEAN
#include "AirSysTrb_MemMap.h"

extern CONST(Boolean, AIRSYSTRB_CALIB) AIRSYSTRB_ACTIVE_BYP_C;
extern CONST(Boolean, AIRSYSTRB_CALIB) AirSys_bAcvFrzMod_B;
extern CONST(Boolean, AIRSYSTRB_CALIB) AirSys_bAcvFrzMod_C;
extern CONST(Boolean, AIRSYSTRB_CALIB) AirSys_bAcvStraLimSurgeFrz_C;
extern CONST(Boolean, AIRSYSTRB_CALIB) AirSys_bDetMT_C;

#define AirSysTrb_STOP_SEC_CALIB_BOOLEAN
#include "AirSysTrb_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define AirSysTrb_START_SEC_INTERNAL_VAR_32BIT
#include "AirSysTrb_MemMap.h"

extern VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_mfAirThrReqFilPrev;
extern VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pDsCmprReqFilPrev;
extern VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pDsCmprReq_IRV_MP;
extern VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pUsCmprReqFilPrev;
extern VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pUsCmprReq_IRV_MP;
extern VAR(Float32, AIRSYSTRB_INTERNAL_VAR) AirSys_pUsThrReqFilPrev;

#define AirSysTrb_STOP_SEC_INTERNAL_VAR_32BIT
#include "AirSysTrb_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define AirSysTrb_START_SEC_INTERNAL_VAR_16BIT
#include "AirSysTrb_MemMap.h"

extern VAR(UInt16, AIRSYSTRB_INTERNAL_VAR) AirSys_facRatPresThrClcn_MP;

#define AirSysTrb_STOP_SEC_INTERNAL_VAR_16BIT
#include "AirSysTrb_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AirSysTrb_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AirSysTrb_MemMap.h"

extern VAR(Boolean, AIRSYSTRB_INTERNAL_VAR) AirSys_bInhFrzMod_MP;

#define AirSysTrb_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AirSysTrb_MemMap.h"
#endif                                 /* RTW_HEADER_AirSysTrb_private_h_ */

/*-------------------------------- end of file -------------------------------*/
