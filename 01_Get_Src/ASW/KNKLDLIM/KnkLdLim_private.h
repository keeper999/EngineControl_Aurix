/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : KnkLdLim                                                */
/* !Description     : LOAD LIMITATION IN KNOCK SITUATION                      */
/*                                                                            */
/* !Module          : KnkLdLim                                                */
/*                                                                            */
/* !File            : KnkLdLim_private.h                                      */
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
/*   Code generated on: Thu Mar 28 15:46:24 2013                              */
/*   Model name       : KnkLdLim_AUTOCODE.mdl                                 */
/*   Model version    : 1.206                                                 */
/*   Root subsystem   : /KnkLdLim                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKLDLIM/KnkLdLim$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   etsasson                               $$Date::   29 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_KnkLdLim_private_h_
#define RTW_HEADER_KnkLdLim_private_h_
#include "Std_Types.h"
#include "KnkLdLim_types.h"
#include "KnkLdLim_import.h"
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
#define KNKLDLIM_START_SEC_CODE
#include "KnkLdLim_MemMap.h"


extern void KnkLdLim_IfActionSubsystem(Boolean rtu_0, Boolean *rty_Out1);
extern void KnkLdLim_IfActionSubsystem1(Boolean rtu_0, Boolean *rty_Out1);
extern void KnkLdLim_F02_LoadLimCalc(void);
extern void KnkTreat_EveBDC_LdLim(void);
extern void KnkLdLim_F01_Init(void);
extern void KnkTreat_EveRst_LdLim(void);
void KnkLdLim_ASYNC1(int controlPortIdx);

#define KNKLDLIM_STOP_SEC_CODE
#include "KnkLdLim_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define KNKLDLIM_START_SEC_CALIB_8BIT
#include "KnkLdLim_MemMap.h"

extern CONST(UInt8, KNKLDLIM_CALIB) KNKLDLIM_u8Inhib;

#define KNKLDLIM_STOP_SEC_CALIB_8BIT
#include "KnkLdLim_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define KNKLDLIM_START_SEC_VAR_32BIT
#include "KnkLdLim_MemMap.h"

extern VAR(Float32, KNKLDLIM_VAR) KnkMgt_agIgKnkCorFil;

#define KNKLDLIM_STOP_SEC_VAR_32BIT
#include "KnkLdLim_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define KNKLDLIM_START_SEC_VAR_16BIT
#include "KnkLdLim_MemMap.h"

extern VAR(UInt16, KNKLDLIM_VAR) KnkMgt_ctKnkDetLdLim;
extern VAR(UInt16, KNKLDLIM_VAR) KnkMgt_ctSuperKnkDetLdLim;

#define KNKLDLIM_STOP_SEC_VAR_16BIT
#include "KnkLdLim_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define KNKLDLIM_START_SEC_VAR_BOOLEAN
#include "KnkLdLim_MemMap.h"

extern VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bAcvTmpLdLimKnkRaw;
extern VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bAcvTmpLdLimSuperKnkRaw;
extern VAR(Boolean, KNKLDLIM_VAR) KnkMgt_bLdLimKnkAdvCor;

#define KNKLDLIM_STOP_SEC_VAR_BOOLEAN
#include "KnkLdLim_MemMap.h"
#endif                                 /* RTW_HEADER_KnkLdLim_private_h_ */

/*-------------------------------- end of file -------------------------------*/
