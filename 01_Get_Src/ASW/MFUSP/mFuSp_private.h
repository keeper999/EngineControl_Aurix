/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuSp                                                   */
/* !Description     : INJECTION MASS PER CYLINDER                             */
/*                                                                            */
/* !Module          : mFuSp                                                   */
/*                                                                            */
/* !File            : mFuSp_private.h                                         */
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
/*   Code generated on: Wed Jul 17 12:40:01 2013                              */
/*   Model name       : mFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.274                                                 */
/*   Root subsystem   : /mFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUSP/mFuSp_private.h_v   $*/
/* $Revision::   1.6                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   22 Jul 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_mFuSp_private_h_
#define RTW_HEADER_mFuSp_private_h_
#include "Std_Types.h"
#include "mFuSp_types.h"
#include "mFuSp_import.h"
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
#define MFUSP_START_SEC_CODE
#include "mFuSp_MemMap.h"

extern void mFuSp_F02_mFuSpSyncEve2(void);
extern void InjSys_EveInj_mFuSp(void);
extern void mFuSp_F01_Initialize(void);
extern void InjSys_EveRst_mFuSp(void);
extern void mF_F01_Calculate_Injection_Mass(void);
extern void mFuSp_F02_mFuSpSyncEve1(void);
extern void InjSys_SdlFast_mFuSp_Start(void);
extern void InjSys_SdlFast_mFuSp(void);
void mFuSp_ASYNC1(int controlPortIdx);

#define MFUSP_STOP_SEC_CODE
#include "mFuSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define MFUSP_START_SEC_CALIB_8BIT
#include "mFuSp_MemMap.h"

extern CONST(UInt8, MFUSP_CALIB) MFUSP_u8Inhib;

#define MFUSP_STOP_SEC_CALIB_8BIT
#include "mFuSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define MFUSP_START_SEC_VAR_32BIT
#include "mFuSp_MemMap.h"

extern VAR(Float32, MFUSP_VAR) InjSys_facStoichFlex_MP;
extern VAR(Float32, MFUSP_VAR) InjSys_facStoichGas_MP;
extern VAR(Float32, MFUSP_VAR) InjSys_prm_facInjCmp[2];
extern VAR(Float32, MFUSP_VAR) InjSys_prm_facStoich[2];
extern VAR(Float32, MFUSP_VAR) InjSys_prm_mAirPred[2];
extern VAR(Float32, MFUSP_VAR) InjSys_prm_mFuRawTmp_MP[2];
extern VAR(Float32, MFUSP_VAR) InjSys_prm_mFuReqCmp_MP[2];
extern VAR(Float32, MFUSP_VAR) InjSys_prm_mFuReq_MP[2];
extern VAR(Float32, MFUSP_VAR) InjSys_prm_mFuSp[2];

#define MFUSP_STOP_SEC_VAR_32BIT
#include "mFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define MFUSP_START_SEC_VAR_16BIT
#include "mFuSp_MemMap.h"

extern VAR(UInt16, MFUSP_VAR) InjSys_prm_facInjCmpCylPrev[6];
extern VAR(UInt16, MFUSP_VAR) InjSys_prm_mFuSpCylPrev[6];

#define MFUSP_STOP_SEC_VAR_16BIT
#include "mFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define MFUSP_START_SEC_VAR_BOOLEAN
#include "mFuSp_MemMap.h"

extern VAR(Boolean, MFUSP_VAR) InjSys_bFuSpCylNull;

#define MFUSP_STOP_SEC_VAR_BOOLEAN
#include "mFuSp_MemMap.h"
#endif                                 /* RTW_HEADER_mFuSp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
