/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActrTstHPPmp                                            */
/* !Description     : ACTRTSTHPPmp- HP PUMP ACTUATOR TEST                     */
/*                                                                            */
/* !Module          : ActrTstHPPmp                                            */
/*                                                                            */
/* !File            : ActrTstHPPmp_private.h                                  */
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
/*   Code generated on: Tue Mar 05 11:01:47 2013                              */
/*   Model name       : ActrTstHPPmp_AUTOCODE.mdl                             */
/*   Model version    : 1.89                                                  */
/*   Root subsystem   : /ActrTstHPPmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/ACTRTSTHPPMP/ActrTstHPPmp$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   08 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ActrTstHPPmp_private_h_
#define RTW_HEADER_ActrTstHPPmp_private_h_
#include "Std_Types.h"
#include "ActrTstHPPmp_types.h"
#include "ActrTstHPPmp_import.h"
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
#define ACTRTSTHPPMP_START_SEC_CODE
#include "ActrTstHPPmp_MemMap.h"

extern void ActrTstHPPmp_F00_HPPmpTst_Init(void);
extern void PFuCtl_EveRst_ActrTstHPPmp(void);
extern void ActrTstHPPmp_F01_HPPmpTst(void);
extern void PFuCtl_EveSpl_ActrTstHPPmp(void);
void ActrTstHPPmp_ASYNC1(int controlPortIdx);

#define ACTRTSTHPPMP_STOP_SEC_CODE
#include "ActrTstHPPmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define ACTRTSTHPPMP_START_SEC_CALIB_8BIT
#include "ActrTstHPPmp_MemMap.h"

extern CONST(UInt8, ACTRTSTHPPMP_CALIB) ACTRTSTHPPMP_u8Inhib;

#define ACTRTSTHPPMP_STOP_SEC_CALIB_8BIT
#include "ActrTstHPPmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define ACTRTSTHPPMP_START_SEC_VAR_32BIT
#include "ActrTstHPPmp_MemMap.h"

extern VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase0;
extern VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase1;
extern VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase1Bis;
extern VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase2;
extern VAR(UInt32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_Tempo_Phase3;
extern VAR(Float32, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pRailPerPmp;

#define ACTRTSTHPPMP_STOP_SEC_VAR_32BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define ACTRTSTHPPMP_START_SEC_VAR_16BIT
#include "ActrTstHPPmp_MemMap.h"

extern VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pFuRailMesBeg1;
extern VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pFuRailMesBeg2;
extern VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pFuRailMesEnd1;
extern VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pFuRailMesEnd2;
extern VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pRailPresDif2;
extern VAR(UInt16, ACTRTSTHPPMP_VAR) ActrTstHPPmp_pRailPresDiff;

#define ACTRTSTHPPMP_STOP_SEC_VAR_16BIT
#include "ActrTstHPPmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define ACTRTSTHPPMP_START_SEC_VAR_8BIT
#include "ActrTstHPPmp_MemMap.h"

extern VAR(UInt8, ACTRTSTHPPMP_VAR) ActrTstHPPmp_ctRstActTst;

#define ACTRTSTHPPMP_STOP_SEC_VAR_8BIT
#include "ActrTstHPPmp_MemMap.h"
#endif                                 /* RTW_HEADER_ActrTstHPPmp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
