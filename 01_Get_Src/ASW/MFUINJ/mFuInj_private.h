/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuInj                                                  */
/* !Description     : INJECTION MASS PER INJECTION                            */
/*                                                                            */
/* !Module          : mFuInj                                                  */
/*                                                                            */
/* !File            : mFuInj_private.h                                        */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
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
/*   Code generated on: Thu Jul 18 15:02:19 2013                              */
/*   Model name       : mFuInj_AUTOCODE.mdl                                   */
/*   Model version    : 1.302                                                 */
/*   Root subsystem   : /mFuInj                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUINJ/mFuInj_private.h_v $*/
/* $Revision::   1.7                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   29 Jul 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_mFuInj_private_h_
#define RTW_HEADER_mFuInj_private_h_
#include "Std_Types.h"
#include "mFuInj_types.h"
#include "mFuInj_import.h"
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
#define MFUINJ_START_SEC_CODE
#include "mFuInj_MemMap.h"

extern void mFuInj_F02_mFuInjCrkClcn(void);
extern void mFuInj_F03_mFuInj_SdlSync(void);
extern void InjSys_EveCkSnNtAc_mFuInj_Start(void);
extern void InjSys_EveCkSnNtAc_mFuInj(void);
extern void InjSys_EveCkSnNtAc_mFuInj(void);
extern void mFuInj_F02_mFuInj_EveSync(void);
extern void InjSys_EveInj_mFuInj(void);
extern void mFuInj_F01_Initialization(void);
extern void InjSys_EveRst_mFuInj(void);
extern void mFuInj_F01_mFuInjRunClcn(void);
extern void InjSys_SdlFast_mFuInj_Start(void);
extern void InjSys_SdlFast_mFuInj(void);
void mFuInj_ASYNC1(int controlPortIdx);
void mFuInj_ASYNC2(int controlPortIdx);
void mFuInj_ASYNC3(int controlPortIdx);

#define MFUINJ_STOP_SEC_CODE
#include "mFuInj_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define MFUINJ_START_SEC_CALIB_8BIT
#include "mFuInj_MemMap.h"

extern CONST(UInt8, MFUINJ_CALIB) MFUINJ_u8Inhib;

#define MFUINJ_STOP_SEC_CALIB_8BIT
#include "mFuInj_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define MFUINJ_START_SEC_VAR_32BIT
#include "mFuInj_MemMap.h"

extern VAR(Float32, MFUINJ_VAR) InjSys_mFuInjH1CrkReq;
extern VAR(Float32, MFUINJ_VAR) InjSys_mFuInjH2CrkReq;
extern VAR(Float32, MFUINJ_VAR) InjSys_mFuInjS1CrkReq;
extern VAR(Float32, MFUINJ_VAR) InjSys_mFuInjS2CrkReq;
extern VAR(Float32, MFUINJ_VAR) InjSys_prm_mFuInjH1Req[2];
extern VAR(Float32, MFUINJ_VAR) InjSys_prm_mFuInjH2Req[2];
extern VAR(Float32, MFUINJ_VAR) InjSys_prm_mFuInjS1Req[2];
extern VAR(Float32, MFUINJ_VAR) InjSys_prm_mFuInjS2Req[2];

#define MFUINJ_STOP_SEC_VAR_32BIT
#include "mFuInj_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define MFUINJ_START_SEC_VAR_16BIT
#include "mFuInj_MemMap.h"

extern VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjH1ReqCylPre[6];
extern VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjH2ReqCylPre[6];
extern VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjS1ReqCylPre[6];
extern VAR(UInt16, MFUINJ_VAR) InjSys_prm_mFuInjS2ReqCylPre[6];

#define MFUINJ_STOP_SEC_VAR_16BIT
#include "mFuInj_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define MFUINJ_START_SEC_VAR_8BIT
#include "mFuInj_MemMap.h"

extern VAR(UInt8, MFUINJ_VAR) InjSys_noCylmFuInjCrk;

#define MFUINJ_STOP_SEC_VAR_8BIT
#include "mFuInj_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define MFUINJ_START_SEC_VAR_BOOLEAN
#include "mFuInj_MemMap.h"

extern VAR(Boolean, MFUINJ_VAR) InjSys_bEngStall;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bInhFrstInjSTTCmprCyl;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bInhFrstInjSTTInCyl;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bInhSTTSync;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bInjPatCond;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bMFuH1SpNull;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bMFuH2SpNull;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bMFuS1SpNull;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bMFuS2SpNull;
extern VAR(Boolean, MFUINJ_VAR) InjSys_bMufInjTotNull;

#define MFUINJ_STOP_SEC_VAR_BOOLEAN
#include "mFuInj_MemMap.h"
#endif                                 /* RTW_HEADER_mFuInj_private_h_ */

/*-------------------------------- end of file -------------------------------*/
