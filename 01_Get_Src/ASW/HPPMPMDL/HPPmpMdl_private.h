/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpMdl                                                */
/* !Description     : HPPmpMdl - Modèle de la pompe haute pression            */
/*                                                                            */
/* !Module          : HPPmpMdl                                                */
/*                                                                            */
/* !File            : HPPmpMdl_private.h                                      */
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
/*   Code generated on: Thu Apr 04 17:41:39 2013                              */
/*   Model name       : HPPmpMdl_AUTOCODE.mdl                                 */
/*   Model version    : 1.167                                                 */
/*   Root subsystem   : /HPPmpMdl                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPMDL/HPPmpMdl_private$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   09 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPPmpMdl_private_h_
#define RTW_HEADER_HPPmpMdl_private_h_
#include "Std_Types.h"
#include "HPPmpMdl_types.h"
#include "HPPmpMdl_import.h"
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
#define HPPMPMDL_START_SEC_CODE
#include "HPPmpMdl_MemMap.h"

extern SInt32 div_ssu32(SInt32 localnumerator, UInt32 localdenominator);
extern UInt32 div_repeat_u32(UInt32 localnumerator, UInt32
  localdenominator, UInt32 localnRepeatSub);
extern void mul_wide_u32(UInt32 localin0, UInt32 localin2, UInt32
  *localptrOutBitsHi, UInt32 *localptrOutBitsLo);
extern UInt32 mul_u32_u32_u32_sr31(UInt32 locala, UInt32 localb);
extern void HPPmpMd_F01_HPPmpMdl_RTSt_inhib(rtB_F01_HPPmpMdl_RTSt_inhib_HPP
  *localB);
extern void HPPmpMdl_F01_HPPmpMdl_Ini(void);
extern void PFuCtl_EveRst_HPPmpMdl(void);
extern void HPPmpMdl_F01_HPPmpMdl_RTSt(void);
extern void PFuCtl_EveRTSt_HPPmpMdl(void);
extern void HPPmpMdl_F02_HPPmpMdl_StTR(void);
extern void PFuCtl_EveStTR_HPPmpMdl(void);
extern void HPPmpMdl_F03_HPPmpMdl(void);
extern void HPPmpMdl_F04_HPPmpDecel(void);
extern void PFuCtl_EveSpl_HPPmpMdl_Start(void);
extern void PFuCtl_EveSpl_HPPmpMdl(void);
void HPPmpMdl_ASYNC1(int controlPortIdx);
void HPPmpMdl_ASYNC2(int controlPortIdx);

#define HPPMPMDL_STOP_SEC_CODE
#include "HPPmpMdl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPPMPMDL_START_SEC_CALIB_8BIT
#include "HPPmpMdl_MemMap.h"

extern CONST(UInt8, HPPMPMDL_CALIB) HPPMPMDL_u8Inhib;

#define HPPMPMDL_STOP_SEC_CALIB_8BIT
#include "HPPmpMdl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define HPPMPMDL_START_SEC_VAR_32BIT
#include "HPPmpMdl_MemMap.h"

extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_OfsVolPmpCor;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_agOfsPmpCmdDly;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_agPmpCmdEfcReqRaw;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_agPmpCmdOfs;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_agPmpCmdReqRaw;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_agWdPmpCmdMin;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_densEstim;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_mFuPmpEstimErrRaw;
extern VAR(UInt32, HPPMPMDL_VAR) PFuCtl_mFuPmpEstimTmp;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_rVolEfcPmp;
extern VAR(Float32, HPPMPMDL_VAR) PFuCtl_volFuReq;
extern VAR(UInt32, HPPMPMDL_VAR) PFuCtl_volFuReqEfc;

#define HPPMPMDL_STOP_SEC_VAR_32BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define HPPMPMDL_START_SEC_VAR_16BIT
#include "HPPmpMdl_MemMap.h"

extern VAR(SInt16, HPPMPMDL_VAR) PFuCtl_agBeg2PulseDif;
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agWdPmpCmdReqRaw;
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiOfsPmpCmd;
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmd;
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdReqRaw;
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_tiPmpCmdReq_prev;

#define HPPMPMDL_STOP_SEC_VAR_16BIT
#include "HPPmpMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define HPPMPMDL_START_SEC_VAR_BOOLEAN
#include "HPPmpMdl_MemMap.h"

extern VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bAcvLrnCondPmpCmdLim;
extern VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bDetAgWdPmpCmdMax;
extern VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bDetAgWdPmpCmdMin;
extern VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bInhPmpCmdMinDet;
extern VAR(Boolean, HPPMPMDL_VAR) PFuCtl_bPmpCmdDecelZone;

#define HPPMPMDL_STOP_SEC_VAR_BOOLEAN
#include "HPPmpMdl_MemMap.h"
#endif                                 /* RTW_HEADER_HPPmpMdl_private_h_ */

/*-------------------------------- end of file -------------------------------*/
