/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pFuM                                                    */
/* !Description     : FUEL PRESSURE MODEL                                     */
/*                                                                            */
/* !Module          : pFuM                                                    */
/*                                                                            */
/* !File            : pFuM_private.h                                          */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
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
/*   Code generated on: Sun Jul 15 20:51:22 2012                              */
/*   Model name       : pFuM_AUTOCODE.mdl                                     */
/*   Model version    : 1.1269                                                */
/*   Root subsystem   : /pFuM                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/pFuM/5-SOFT-LIV/pFuM_private$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   16 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_pFuM_private_h_
#define RTW_HEADER_pFuM_private_h_
#include "Std_Types.h"
#include "pFuM_types.h"
#include "pFuM_import.h"
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

/* !Comment: Define code in section "SEC_CODE" */
#define PFUM_START_SEC_CODE
#include "pFuM_MemMap.h"

extern void pFuM_F01_init(UInt16 rtu_Ext_pFuRailSplMes, UInt16
  rtu_FuSysM_tFu, rtB_F01_init_pFuM *localB);
extern void pFuM_F01_init_o(void);
extern void pFuM_F00_pFuMSyncEveRst(UInt16 rtu_0, UInt16 rtu_1, UInt16
  rtu_2, UInt16 rtu_3, rtB_F00_pFuMSyncEveRst_pFuM *localB);
extern void pFuM_F00_pFuMSyncEveRst_a(void);
extern void FuSysM_EveRst_pFuM_Start(void);
extern void FuSysM_EveRst_pFuM(void);
extern void pFuM_F01_init1(void);
extern void pFuM_F01_pFuMSyncEveClcn(void);
extern void FuSysM_EveCkSnOn_pFuM_Start(void);
extern void FuSysM_EveCkSnOn_pFuM(void);
extern void FuSysM_EveCkSnOn_pFuM(void);
extern void FuSysM_EveCkSnOn_pFuM(void);
extern void pFuM_F00_pFuMSyncEveRst1(void);
extern void FuSysM_SdlFast_pFuM_Start(void);
extern void FuSysM_SdlFast_pFuM(void);
extern void pFuM_F02_pFuSyncIn_EveInj(void);
extern void pFuM_F02_PFuMdlClcn(void);
extern void pFuM_F02_PFuMdl(void);
extern void pFuM_F02_pFuMSyncEveInj(void);
extern void FuSysM_EveInj_pFuM_Start(void);
extern void FuSysM_EveInj_pFuM(void);
extern void FuSysM_EveInj_pFuM(void);
extern void pFuM_F01_pFuSyncIn_EveClcn(void);
extern void FuSysM_EveSpl_pFuM_Start(void);
extern void FuSysM_EveSpl_pFuM(void);
void pFuM_ASYNC1(int controlPortIdx);
void pFuM_ASYNC2(int controlPortIdx);
void pFuM_ASYNC3(int controlPortIdx);
void pFuM_ASYNC6(int controlPortIdx);

#define PFUM_STOP_SEC_CODE
#include "pFuM_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define PFUM_START_SEC_CALIB_8BIT
#include "pFuM_MemMap.h"

extern CONST(UInt8, PFUM_CALIB) PFUM_u8Inhib;

#define PFUM_STOP_SEC_CALIB_8BIT
#include "pFuM_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define PFUM_START_SEC_VAR_32BIT
#include "pFuM_MemMap.h"

extern VAR(Float32, PFUM_VAR) FuSysM_agBegInjH1Ref;
extern VAR(Float32, PFUM_VAR) FuSysM_agBegInjH1RefNxt;
extern VAR(Float32, PFUM_VAR) FuSysM_agBegInjH1RefPrev;
extern VAR(Float32, PFUM_VAR) FuSysM_agBegInjH2Ref;
extern VAR(Float32, PFUM_VAR) FuSysM_agBegInjH2RefNxt;
extern VAR(Float32, PFUM_VAR) FuSysM_agBegInjH2RefPrev;
extern VAR(Float32, PFUM_VAR) FuSysM_agBegInjS1Ref;
extern VAR(Float32, PFUM_VAR) FuSysM_agBegInjS2Ref;
extern VAR(Float32, PFUM_VAR) FuSysM_agEndInjH1Ref;
extern VAR(Float32, PFUM_VAR) FuSysM_agEndInjH1RefNxt;
extern VAR(Float32, PFUM_VAR) FuSysM_agEndInjH1RefPrev;
extern VAR(Float32, PFUM_VAR) FuSysM_agEndInjH2Ref;
extern VAR(Float32, PFUM_VAR) FuSysM_agEndInjH2RefNxt;
extern VAR(Float32, PFUM_VAR) FuSysM_agEndInjH2RefPrev;
extern VAR(Float32, PFUM_VAR) FuSysM_agEndInjS1Ref;
extern VAR(Float32, PFUM_VAR) FuSysM_agEndInjS2Ref;
extern VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH1;
extern VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH1Nxt;
extern VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH1Prev;
extern VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH2;
extern VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH2Nxt;
extern VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjH2Prev;
extern VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjS1;
extern VAR(Float32, PFUM_VAR) FuSysM_mFuReqInjS2;
extern VAR(Float32, PFUM_VAR) FuSysM_pFuEstimBegH1;
extern VAR(Float32, PFUM_VAR) FuSysM_pFuEstimBegH2;
extern VAR(Float32, PFUM_VAR) FuSysM_pFuEstimBegS1;
extern VAR(Float32, PFUM_VAR) FuSysM_pFuEstimBegS2;
extern VAR(Float32, PFUM_VAR) FuSysM_pFuEstimInjH1Prev;
extern VAR(Float32, PFUM_VAR) FuSysM_pFuEstimInjH2Prev;
extern VAR(Float32, PFUM_VAR) FuSysM_pFuEstimInjS1Prev;
extern VAR(Float32, PFUM_VAR) FuSysM_pFuEstimInjS2Prev;
extern VAR(Float32, PFUM_VAR) FuSysM_prm_fac1CorMassPmpInjH1[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_fac1CorMassPmpInjH2[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_fac1CorMassPmpInjS1[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_fac1CorMassPmpInjS2[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_fac2CorMassPmpInjH1[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_fac2CorMassPmpInjH2[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_fac2CorMassPmpInjS1[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_fac2CorMassPmpInjS2[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjBegH1[6];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjBegH2[6];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjBegS1[4];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjBegS2[4];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjOvlpH1[6];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjOvlpH2[6];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjOvlpS1[4];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuInjOvlpS2[4];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpBegH1[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpBegH2[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpBegS1[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpBegS2[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpOvlpH1[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpOvlpH2[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpOvlpS1[2];
extern VAR(Float32, PFUM_VAR) FuSysM_prm_mFuPmpOvlpS2[2];

#define PFUM_STOP_SEC_VAR_32BIT
#include "pFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define PFUM_START_SEC_VAR_16BIT
#include "pFuM_MemMap.h"

extern VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimH1CylPrev[6];
extern VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimH2CylPrev[6];
extern VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimS1CylPrev[6];
extern VAR(UInt16, PFUM_VAR) FuSysM_prm_pFuEstimS2CylPrev[6];

#define PFUM_STOP_SEC_VAR_16BIT
#include "pFuM_MemMap.h"
#endif                                 /* RTW_HEADER_pFuM_private_h_ */

/*-------------------------------- end of file -------------------------------*/
