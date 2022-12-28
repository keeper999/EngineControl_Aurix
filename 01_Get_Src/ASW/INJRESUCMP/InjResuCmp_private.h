/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjResuCmp                                              */
/* !Description     : InjResuCmp : INJECTION COMPENSATION AFTER CUT OFF       */
/*                                                                            */
/* !Module          : InjResuCmp                                              */
/*                                                                            */
/* !File            : InjResuCmp_private.h                                    */
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
/*   Code generated on: Mon Dec 02 18:06:23 2013                              */
/*   Model name       : InjResuCmp_AUTOCODE.mdl                               */
/*   Model version    : 1.293                                                 */
/*   Root subsystem   : /InjResuCmp                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJRESUCMP/InjResuCmp_priv$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Dec 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjResuCmp_private_h_
#define RTW_HEADER_InjResuCmp_private_h_
#include "Std_Types.h"
#include "InjResuCmp_types.h"
#include "InjResuCmp_import.h"
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
#define INJRESUCMP_START_SEC_CODE
#include "InjResuCmp_MemMap.h"


extern void InjResuCmp_F01_Initialization(void);
extern void InjSys_EveRst_InjResuCmp(void);
extern void InjResuCmp_rising_edge10(Boolean rtu_Signal,
  rtB_rising_edge10_InjResuCmp *localB, rtDW_rising_edge10_InjResuCmp *localDW);
extern void InjRe_F01_Stall_indicator_Start(void);
extern void InjResuCmp_F01_Stall_indicator(void);
extern void InjResuCmp_Counter(UInt8 rtu_Inc, Boolean rtu_Ena, Boolean
  rtu_Rst, rtB_Counter_InjResuCmp *localB, rtDW_Counter_InjResuCmp *localDW,
  UInt16 rtp_Cnt_Max);
extern void InjResuCmp_falling_edge1(Boolean rtu_Signal,
  rtB_falling_edge1_InjResuCmp *localB, rtDW_falling_edge1_InjResuCmp *localDW);
extern void InjResuCmp_F02_InjResuCmp(void);
extern void InjSys_EveInj_InjResuCmp_Start(void);
extern void InjSys_EveInj_InjResuCmp(void);
extern void InjSys_EveInj_InjResuCmp(void);
extern void InjResuCmp_F03_Det_Stall(void);
extern void InjSys_EveRTSt_InjResuCmp(void);
extern void InjResuCmp_F00_RstDetStall(void);
extern void InjSys_EveStTR_InjResuCmp(void);
void InjResuCmp_ASYNC1(int controlPortIdx);
void InjResuCmp_ASYNC2(int controlPortIdx);
void InjResuCmp_ASYNC3(int controlPortIdx);

#define INJRESUCMP_STOP_SEC_CODE
#include "InjResuCmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJRESUCMP_START_SEC_CALIB_8BIT
#include "InjResuCmp_MemMap.h"

extern CONST(UInt8, INJRESUCMP_CALIB) INJRESUCMP_u8Inhib;

#define INJRESUCMP_STOP_SEC_CALIB_8BIT
#include "InjResuCmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define INJRESUCMP_START_SEC_VAR_32BIT
#include "InjResuCmp_MemMap.h"

extern VAR(Float32, INJRESUCMP_VAR) InjSys_facInjResuTCor_MP;
extern VAR(Float32, INJRESUCMP_VAR) InjSys_facTCorIntrSTT_MP;
extern VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facCorIntrSTT_MP[6];
extern VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facGslResuCyl[6];
extern VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facInjResuCor_MP[6];
extern VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facInjResuIdlCmp_MP[6];
extern VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facInjResuIntrSTT_MP[6];
extern VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facInjResuTqCmp_MP[6];
extern VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facResuIdl_MP[6];
extern VAR(Float32, INJRESUCMP_VAR) InjSys_prm_facResuTq_MP[6];

#define INJRESUCMP_STOP_SEC_VAR_32BIT
#include "InjResuCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJRESUCMP_START_SEC_VAR_16BIT
#include "InjResuCmp_MemMap.h"

extern VAR(UInt16, INJRESUCMP_VAR) InjSys_prm_ctAntCmpStopCyl[6];
extern VAR(UInt16, INJRESUCMP_VAR) InjSys_prm_ctInjResuCyl[6];
extern VAR(UInt16, INJRESUCMP_VAR) InjSys_prm_ctNbCmbCutOffCyl[6];

#define INJRESUCMP_STOP_SEC_VAR_16BIT
#include "InjResuCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJRESUCMP_START_SEC_VAR_BOOLEAN
#include "InjResuCmp_MemMap.h"

extern VAR(Boolean, INJRESUCMP_VAR) InjSys_bDetStall;
extern VAR(Boolean, INJRESUCMP_VAR) InjSys_prm_bDetStall[6];
extern VAR(Boolean, INJRESUCMP_VAR) InjSys_prm_bInjResuCyl[6];

#define INJRESUCMP_STOP_SEC_VAR_BOOLEAN
#include "InjResuCmp_MemMap.h"
#endif                                 /* RTW_HEADER_InjResuCmp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
