/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSysSpCrk                                             */
/* !Description     : InjSysSpCrk : INJECTION SETPOINTS FOR START             */
/*                                                                            */
/* !Module          : InjSysSpCrk                                             */
/*                                                                            */
/* !File            : InjSysSpCrk_private.h                                   */
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
/*   Code generated on: Thu Feb 14 12:28:19 2013                              */
/*   Model name       : InjSysSpCrk_AUTOCODE.mdl                              */
/*   Model version    : 1.113                                                 */
/*   Root subsystem   : /InjSysSpCrk                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJSYSSPCRK/InjSysSpCrk_pr$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   21 Feb 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjSysSpCrk_private_h_
#define RTW_HEADER_InjSysSpCrk_private_h_
#include "Std_Types.h"
#include "InjSysSpCrk_types.h"
#include "InjSysSpCrk_import.h"
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
#define INJSYSSPCRK_START_SEC_CODE
#include "InjSysSpCrk_MemMap.h"

extern void InjSysSpCrk_F00_Init(void);
extern void InjSys_EveRst_InjSysSpCrk(void);
extern void InjSysSpCrk_F03_PfurailClcn(void);
extern void InjSys_EveSpl_InjSysSpCrk(void);
extern void InjSys_EveSpl_InjSysSpCrk(void);
extern void InjSysSpCrk_F01_AuthFrstInjAdap(void);
extern void InjSysSpCrk_F01_InjPhaClcn(void);
extern void InjSysSpCrk_F02_rInjSpClcn(void);
extern void InjSys_EveStTR_InjSysSpCrk_Start(void);
extern void InjSys_EveStTR_InjSysSpCrk(void);
extern void InjSys_EveStTR_InjSysSpCrk(void);
extern void InjSys_SdlFast_InjSysSpCrk(void);
void InjSysSpCrk_ASYNC1(int controlPortIdx);
void InjSysSpCrk_ASYNC2(int controlPortIdx);
void InjSysSpCrk_ASYNC4(int controlPortIdx);

#define INJSYSSPCRK_STOP_SEC_CODE
#include "InjSysSpCrk_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJSYSSPCRK_START_SEC_CALIB_8BIT
#include "InjSysSpCrk_MemMap.h"

extern CONST(UInt8, INJSYSSPCRK_CALIB) INJSYSSPCRK_u8Inhib;

#define INJSYSSPCRK_STOP_SEC_CALIB_8BIT
#include "InjSysSpCrk_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#endif                                 /* RTW_HEADER_InjSysSpCrk_private_h_ */

/*-------------------------------- end of file -------------------------------*/
