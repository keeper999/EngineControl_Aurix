/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpVlvCmdLrn                                          */
/* !Description     : HPPMPVLVCMDLRN - LEARNING STRATEGY OF THE HP PUMP SPILL VALVE COMMAND PROFILE*/
/*                                                                            */
/* !Module          : HPPmpVlvCmdLrn                                          */
/*                                                                            */
/* !File            : HPPmpVlvCmdLrn_private.h                                */
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
/*   Code generated on: Sun Dec 16 22:51:52 2012                              */
/*   Model name       : HPPmpVlvCmdLrn_AUTOCODE.mdl                           */
/*   Model version    : 1.448                                                 */
/*   Root subsystem   : /HPPmpVlvCmdLrn                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPVLVCMDLRN/HPPmpVlvCm$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Dec 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPPmpVlvCmdLrn_private_h_
#define RTW_HEADER_HPPmpVlvCmdLrn_private_h_
#include "Std_Types.h"
#include "HPPmpVlvCmdLrn_types.h"
#include "HPPmpVlvCmdLrn_import.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

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
#define HPPMPVLVCMDLRN_START_SEC_CODE
#include "HPPmpVlvCmdLrn_MemMap.h"

extern Float32 look1_iu16lftu16If_binlcs(UInt16 localu0, const UInt16
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern Float32 look1_iu16lftu8If_binlcs(UInt16 localu0, const UInt16
  localbp0[], const UInt8 localtable[], UInt32 localmaxIndex);
extern Float32 look2_1fcv2bcvbcvbfbba7xfbbnx(UInt16 localu0, UInt16 localu1,
  const UInt16 localbp0[], const UInt16 localbp1[], const UInt32
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern void HPPmpVlvCmdLrn_F01_Init(void);
extern void PFuCtl_EveRst_HPPmpVlvCmdLrn(void);
extern void HPPmpV_F02_HPPmpVlvCmdLrn_Start(void);
extern void HPPm_F02_HPPmpVlvCmdLrn_Disable(void);
extern void HPPmpVlvCmdL_F02_HPPmpVlvCmdLrn(void);
extern void PFuCtl_EveSpl_HPPmpVlvCmdLrn_Start(void);
extern void PFuCtl_EveSpl_HPPmpVlvCmdLrn_Disable(void);
extern void PFuCtl_EveSpl_HPPmpVlvCmdLrn(void);
void HPPmpVlvCmdLrn_ASYNC1(int controlPortIdx);

#define HPPMPVLVCMDLRN_STOP_SEC_CODE
#include "HPPmpVlvCmdLrn_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPPMPVLVCMDLRN_START_SEC_CALIB_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

extern CONST(UInt8, HPPMPVLVCMDLRN_CALIB) HPPMPVLVCMDLRN_u8Inhib;

#define HPPMPVLVCMDLRN_STOP_SEC_CALIB_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_32BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

extern VAR(Float32, HPPMPVLVCMDLRN_VAR) PFuCtl_tideltaT;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_32BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) Ext_nEngLrn;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) Ext_pDsThrMesSILrn;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) Ext_pFuRailSplMesLrn;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) Ext_uBattLrn;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) InjSys_pFuReqLrn;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_NrAppl;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_NrLrnIt;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_NrLrnIt_prev;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_OfsNrProfCmd;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_ctNrAppl;
extern VAR(UInt16, HPPMPVLVCMDLRN_VAR) PFuCtl_pRailSpDifAbs;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_16BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

extern VAR(UInt8, HPPMPVLVCMDLRN_VAR) PFuCtl_NrProfCmdRaw;
extern VAR(UInt8, HPPMPVLVCMDLRN_VAR) PFuCtl_NrProfCmdRawSat;
extern VAR(UInt8, HPPMPVLVCMDLRN_VAR) PFuCtl_NrProfCmdRaw_prev;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_8BIT
#include "HPPmpVlvCmdLrn_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define HPPMPVLVCMDLRN_START_SEC_VAR_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"

extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvFaildPmpStk;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvFaildPmpStks;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvHPPmpBgnLrn;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvLrnInProgs_prev;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvPFuIncTst;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bAcvRstLrnPFuInc;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnFaild;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnIt;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnIt_prev;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bHPPmpVlvCmdLrnVld_prev;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bLrnVldFaildPmpStk;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bPmpCmdLrnRst;
extern VAR(Boolean, HPPMPVLVCMDLRN_VAR) PFuCtl_bRunHPPmpLrn;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_BOOLEAN
#include "HPPmpVlvCmdLrn_MemMap.h"
#endif                                 /* RTW_HEADER_HPPmpVlvCmdLrn_private_h_ */

/*-------------------------------- end of file -------------------------------*/
