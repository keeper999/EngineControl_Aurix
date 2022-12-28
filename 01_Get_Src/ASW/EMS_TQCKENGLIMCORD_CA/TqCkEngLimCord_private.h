/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : TqCkEngLimCord                                          */
/* !Description     : SAFETY TMS : GERER LE BOUCLAGE                          */
/*                                                                            */
/* !Module          : TqCkEngLimCord                                          */
/*                                                                            */
/* !File            : TqCkEngLimCord_private.h                                */
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
/*   Code generated on: Tue Jun 19 17:16:01 2012                              */
/*   Model name       : TqCkEngLimCord_AUTOCODE.mdl                           */
/*   Model version    : 1.173                                                 */
/*   Root subsystem   : /TqCkEngLimCord                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKENGLIMCORD_CA/TqCk$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   27 Jun 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_TqCkEngLimCord_private_h_
#define RTW_HEADER_TqCkEngLimCord_private_h_
#include "Std_Types.h"
#include "TqCkEngLimCord_types.h"
#include "TqCkEngLimCord_import.h"
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
#define TQCKENGLIMCORD_START_SEC_CODE
#include "TqCkEngLimCord_MemMap.h"

extern void CSCT_CGMT09_2641_v2_4_Gerer_Bou(void);
extern void SftyMgt_SdlMid_tqCkEngLimCord(void);
extern void TqCkEngLimCord_Init(void);
extern void SftyMgt_Init_tqCkEngLimCord(void);
void TqCkEngLimCord_ASYNC1(int controlPortIdx);

#define TQCKENGLIMCORD_STOP_SEC_CODE
#include "TqCkEngLimCord_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define TQCKENGLIMCORD_START_SEC_CALIB_8BIT
#include "TqCkEngLimCord_MemMap.h"

extern CONST(UInt8, TQCKENGLIMCORD_CALIB) TQCKENGLIMCORD_u8Inhib;

#define TQCKENGLIMCORD_STOP_SEC_CALIB_8BIT
#include "TqCkEngLimCord_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define TQCKENGLIMCORD_START_SEC_VAR_16BIT
#include "TqCkEngLimCord_MemMap.h"

extern VAR(SInt16, TQCKENGLIMCORD_VAR) SftyMgt_tqCkAntiOscCord;
extern VAR(SInt16, TQCKENGLIMCORD_VAR) SftyMgt_tqCkEngLimCordRaw;
extern VAR(SInt16, TQCKENGLIMCORD_VAR) SftyMgt_tqIdcEngLimCordIgMin;

#define TQCKENGLIMCORD_STOP_SEC_VAR_16BIT
#include "TqCkEngLimCord_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define TQCKENGLIMCORD_START_SEC_VAR_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"

extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bAcvCllRaw_MP;
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDftAOS;
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDftAgIgMin;
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDftCll;
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDftIdcAir;
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoAOS_MP;
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoAgIgMin_MP;
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoCll_MP;
extern VAR(Boolean, TQCKENGLIMCORD_VAR) SftyMgt_bDgoIdcAir_MP;

#define TQCKENGLIMCORD_STOP_SEC_VAR_BOOLEAN
#include "TqCkEngLimCord_MemMap.h"
#endif                                 /* RTW_HEADER_TqCkEngLimCord_private_h_ */

/*-------------------------------- end of file -------------------------------*/
