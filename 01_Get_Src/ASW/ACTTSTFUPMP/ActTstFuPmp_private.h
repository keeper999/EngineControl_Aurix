/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstFuPmp                                             */
/* !Description     : Test actionneur Pompe de Gavage                         */
/*                                                                            */
/* !Module          : ActTstFuPmp                                             */
/*                                                                            */
/* !File            : ActTstFuPmp_private.h                                   */
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
/*   Code generated on: Tue Jan 17 08:03:35 2012                              */
/*   Model name       : ActTstFuPmp_AUTOCODE.mdl                              */
/*   Model version    : 1.68                                                  */
/*   Root subsystem   : /ActTstFuPmp                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUPMP/ACTTSTFUPMP/ActTstFuPmp_pr$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   23 Jan 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ActTstFuPmp_private_h_
#define RTW_HEADER_ActTstFuPmp_private_h_
#include "Std_Types.h"
#include "ActTstFuPmp_types.h"
#include "ActTstFuPmp_import.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
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

/* !Comment: Define code in section "SEC_CODE" */
#define ACTTSTFUPMP_START_SEC_CODE
#include "ActTstFuPmp_MemMap.h"

extern void ActTstFuPmp_F01_FuTnkPmpTst(void);
extern void FuPmp_EveRst_ActrTstFuTnkPmp(void);
extern void FuPmp_EveRst_ActrTstFuTnkPmp(void);
extern void FuPmp_SdlMid_ActrTstFuTnkPmp(void);
void ActTstFuPmp_ASYNC1(int controlPortIdx);

#define ACTTSTFUPMP_STOP_SEC_CODE
#include "ActTstFuPmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define ACTTSTFUPMP_START_SEC_VAR_16BIT
#include "ActTstFuPmp_MemMap.h"

extern VAR(UInt16, ACTTSTFUPMP_VAR) ActrTstFuTnkPmp_CumulTime;
extern VAR(UInt16, ACTTSTFUPMP_VAR) ActrTstFuTnkPmp_IntTime;
extern VAR(UInt16, ACTTSTFUPMP_VAR) ActrTstFuTnkPmp_Tempo;

#define ACTTSTFUPMP_STOP_SEC_VAR_16BIT
#include "ActTstFuPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define ACTTSTFUPMP_START_SEC_VAR_8BIT
#include "ActTstFuPmp_MemMap.h"

extern VAR(UInt8, ACTTSTFUPMP_VAR) FuPmp_stActrTst;

#define ACTTSTFUPMP_STOP_SEC_VAR_8BIT
#include "ActTstFuPmp_MemMap.h"
#endif                                 /* RTW_HEADER_ActTstFuPmp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
