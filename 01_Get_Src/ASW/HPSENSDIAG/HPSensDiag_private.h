/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPSensDiag                                              */
/* !Description     : Functional diagnosis of HP Sensor                       */
/*                                                                            */
/* !Module          : HPSensDiag                                              */
/*                                                                            */
/* !File            : HPSensDiag_private.h                                    */
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
/*   Code generated on: Thu Oct 17 18:16:02 2013                              */
/*   Model name       : HPSensDiag_Autocode.mdl                               */
/*   Model version    : 1.418                                                 */
/*   Root subsystem   : /HPSensDiag                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/HPSENSDIAG/HPSensDiag_private$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   21 Oct 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPSensDiag_private_h_
#define RTW_HEADER_HPSensDiag_private_h_
#include "Std_Types.h"
#include "HPSensDiag_types.h"
#include "HPSensDiag_import.h"
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
#define HPSENSDIAG_START_SEC_CODE
#include "HPSensDiag_MemMap.h"

extern UInt32 div_repeat_us32_floor(SInt32 localnumerator, SInt32
  localdenominator, UInt32 localnRepeatSub);
extern UInt32 div_repeat_u32_ceiling(UInt32 localnumerator, UInt32
  localdenominator, UInt32 localnRepeatSub);
extern UInt32 div_repeat_u32(UInt32 localnumerator, UInt32
  localdenominator, UInt32 localnRepeatSub);
extern void mul_wide_u32(UInt32 localin0, UInt32 localin2, UInt32
  *localptrOutBitsHi, UInt32 *localptrOutBitsLo);
extern UInt32 mul_u32_u32_u32_sr31(UInt32 locala, UInt32 localb);
extern Float32 look1_is32lftu16p9If_binlcs(SInt32 localu0, const SInt32
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern void HPSensDiag_F03_HPSensDiagInit(void);
extern void Fu_EveRst_HPSensDiag(void);
extern void HPSensDiag_F01_HPSensDiag_Start(void);
extern void HPSensDiag_F01_HPSensDiag(void);
extern void HPSensDiag_GDGAR_vidGdu(void);
extern void HPSensDiag_demux_fc1_Start(void);
extern void HPSensDiag_demux_fc1(void);
extern void Fu_SdlFast_HPSensDiag_Start(void);
extern void Fu_SdlFast_HPSensDiag(void);
extern void HPSensDiag_F00_mFuBtwEveInj(void);
extern void HPSensDiag_F02_CohTest(void);
extern void HPSensDiag_GDGAR_vidGdu1(void);
extern void HPSensDiag_demux_fc_Start(void);
extern void HPSensDiag_demux_fc(void);
extern void Fu_EveSpl_HPSensDiag_Start(void);
extern void Fu_EveSpl_HPSensDiag(void);

#define HPSENSDIAG_STOP_SEC_CODE
#include "HPSensDiag_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPSENSDIAG_START_SEC_CALIB_8BIT
#include "HPSensDiag_MemMap.h"

extern CONST(UInt8, HPSENSDIAG_CALIB) HPSENSDIAG_u8Inhib;

#define HPSENSDIAG_STOP_SEC_CALIB_8BIT
#include "HPSensDiag_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define HPSENSDIAG_START_SEC_VAR_32BIT
#include "HPSensDiag_MemMap.h"

extern VAR(SInt32, HPSENSDIAG_VAR) Fu_mFuDifBtwSpl;

#define HPSENSDIAG_STOP_SEC_VAR_32BIT
#include "HPSensDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define HPSENSDIAG_START_SEC_VAR_16BIT
#include "HPSensDiag_MemMap.h"

extern VAR(UInt16, HPSENSDIAG_VAR) Fu_mFuInjBtwEveSpl;
extern VAR(SInt16, HPSENSDIAG_VAR) Fu_pFuDifHPSensDiag;
extern VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuRailGrdHPSensDiag;
extern VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuRailHPSensDiagMem;
extern VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuReqDiagMem;
extern VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuReqGrdHPSensDiag;
extern VAR(SInt16, HPSENSDIAG_VAR) Fu_pFuReqGrdHPSensDiagRaw;
extern VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuReqPrev;
extern VAR(UInt16, HPSENSDIAG_VAR) Fu_pFuReqPrevIni;
extern VAR(UInt16, HPSENSDIAG_VAR) Fu_tiPFuRailStabHPSensDiagDly;

#define HPSENSDIAG_STOP_SEC_VAR_16BIT
#include "HPSensDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define HPSENSDIAG_START_SEC_VAR_BOOLEAN
#include "HPSensDiag_MemMap.h"

extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bAcvHPSensDiag_pFuRailCond;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bAcvPFuRailSenDiag;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bAcvStuck_HPSens;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bAcvStuck_HPSens_prev;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bCondDiag_HPSens;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bDgoCoh_HPSens;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bDgoStuck_HPSens;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bMonRunCoh_HPSens;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bMonRunStuck_HPSens;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bPFuRailStabHPSensDiag;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bPFuRailStabHPSensDiag_prev;
extern VAR(Boolean, HPSENSDIAG_VAR) Fu_bRawDgoStuck_HPSens;

#define HPSENSDIAG_STOP_SEC_VAR_BOOLEAN
#include "HPSensDiag_MemMap.h"
#endif                                 /* RTW_HEADER_HPSensDiag_private_h_ */

/*-------------------------------- end of file -------------------------------*/
