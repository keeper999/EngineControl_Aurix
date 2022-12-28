/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : RblPvt                                                  */
/* !Description     : RUMBLE PREVENTION                                       */
/*                                                                            */
/* !Module          : RblPvt                                                  */
/*                                                                            */
/* !File            : RblPvt_private.h                                        */
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
/*   Code generated on: Thu Dec 13 15:30:24 2012                              */
/*   Model name       : RblPvt_AUTOCODE.mdl                                   */
/*   Model version    : 1.23                                                  */
/*   Root subsystem   : /RblPvt                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/RblPvt/5-SOFT-LIV/RblPvt_pri$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   14 Dec 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_RblPvt_private_h_
#define RTW_HEADER_RblPvt_private_h_
#include "Std_Types.h"
#include "RblPvt_types.h"
#include "RblPvt_import.h"
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
#define RBLPVT_START_SEC_CODE
#include "RblPvt_MemMap.h"

extern UInt32 plook_u32u16f_binc(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp2d_iu8ff_u32f_l_s(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt8 localtable[], UInt32 localstride);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern void RblPvt_u_RblPvt_init(void);
extern void KnkTreat_EveRst_RblPvt(void);
extern void RblPvt_IfActionSubsystem(Boolean rtu_0, Boolean *rty_Out1);
extern void RblPvt_IfActionSubsystem1(Boolean rtu_0, Boolean *rty_Out1);
extern void RblPvt_u_RblPvt_calc(void);
extern void KnkTreat_SdlSlow_RblPvt(void);
void RblPvt_ASYNC1(int controlPortIdx);

#define RBLPVT_STOP_SEC_CODE
#include "RblPvt_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define RBLPVT_START_SEC_CALIB_8BIT
#include "RblPvt_MemMap.h"

extern CONST(UInt8, RBLPVT_CALIB) RBLPVT_u8Inhib;

#define RBLPVT_STOP_SEC_CALIB_8BIT
#include "RblPvt_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define RBLPVT_START_SEC_VAR_32BIT
#include "RblPvt_MemMap.h"

extern VAR(Float32, RBLPVT_VAR) KnkMgt_facCtRblToil;

#define RBLPVT_STOP_SEC_VAR_32BIT
#include "RblPvt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define RBLPVT_START_SEC_VAR_16BIT
#include "RblPvt_MemMap.h"

extern VAR(UInt16, RBLPVT_VAR) KnkMgt_ctTotRblPvtInc;
extern VAR(UInt16, RBLPVT_VAR) KnkMgt_ctTotRblToil;

#define RBLPVT_STOP_SEC_VAR_16BIT
#include "RblPvt_MemMap.h"
#endif                                 /* RTW_HEADER_RblPvt_private_h_ */

/*-------------------------------- end of file -------------------------------*/
