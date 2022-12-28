/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjAstWupCmp                                            */
/* !Description     : INJECTION CORRECTION IN AFTER START AND WARM UP         */
/*                                                                            */
/* !Module          : InjAstWupCmp                                            */
/*                                                                            */
/* !File            : InjAstWupCmp_private.h                                  */
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
/*   Code generated on: Mon Feb 18 18:51:55 2013                              */
/*   Model name       : InjAstWupCmp_AUTOCODE.mdl                             */
/*   Model version    : 1.510                                                 */
/*   Root subsystem   : /InjAstWupCmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJASTWUPCMP/InjAstWupCmp_$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   22 Feb 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjAstWupCmp_private_h_
#define RTW_HEADER_InjAstWupCmp_private_h_
#include "Std_Types.h"
#include "InjAstWupCmp_types.h"
#include "InjAstWupCmp_import.h"
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
#define INJASTWUPCMP_START_SEC_CODE
#include "InjAstWupCmp_MemMap.h"

extern UInt32 plook_u32u16f_binc(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp2d_iu16n13ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride);
extern UInt32 plook_u32u8f_binc(UInt8 localu, const UInt8 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 look1_iu8lftu16n13If_binlcns(UInt8 localu0, const UInt8
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern Float32 look2_is8s8lftu16n13If_binlcns(SInt8 localu0, SInt8 localu1,
  const SInt8 localbp0[], const SInt8 localbp1[], const UInt16 localtable[],
  const UInt32 localmaxIndex[], UInt32 localstride);
extern Float32 look1_is16lftu16n13If_binlcns(SInt16 localu0, const SInt16
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern Float32 look2_1fc22bc2bcvbfbbr64fbbnx(UInt16 localu0, SInt16 localu1,
  const UInt16 localbp0[], const SInt16 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern Float32 look2_1fcv2bcvbcvbfbbr64fbbnx(UInt16 localu0, UInt16 localu1,
  const UInt16 localbp0[], const UInt16 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern Float32 look2_iu32u8lftu16n13If_binlcns(UInt32 localu0, UInt8
  localu1, const UInt32 localbp0[], const UInt8 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern UInt32 binsearch_u32u8(UInt8 localu, const UInt8 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern void InjAstWupCmp_F01_Initialization(void);
extern void InjSys_EveRst_InjAstWupCmp(void);
extern void InjAstWu_F02_InjAstWupCmp_Start(void);
extern void InjAstWupCmp_F02_InjAstWupCmp(void);
extern void InjSys_EveInj_InjAstWupCmp_Start(void);
extern void InjSys_EveInj_InjAstWupCmp(void);
extern void InjSys_EveInj_InjAstWupCmp(void);
extern void InjAstWupCmp_F03_EventDetection(void);
extern void InjSys_SdlFast_InjAstWupCmp(void);
void InjAstWupCmp_ASYNC1(int controlPortIdx);
void InjAstWupCmp_ASYNC2(int controlPortIdx);

#define INJASTWUPCMP_STOP_SEC_CODE
#include "InjAstWupCmp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJASTWUPCMP_START_SEC_CALIB_8BIT
#include "InjAstWupCmp_MemMap.h"

extern CONST(UInt8, INJASTWUPCMP_CALIB) INJASTWUPCMP_u8Inhib;

#define INJASTWUPCMP_STOP_SEC_CALIB_8BIT
#include "InjAstWupCmp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define INJASTWUPCMP_START_SEC_VAR_32BIT
#include "InjAstWupCmp_MemMap.h"

extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_agCkPosnVlvOvlp;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_agCkVlvOvlp;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAst;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstAutn;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstAutnCorVVT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj0Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj0STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj0_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj1Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj1STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj1_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj2Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj2STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj2_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj3Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj3STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorInj3_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorRaw1Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorRaw1STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorRaw1Strt_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorRaw2Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorRaw2STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorRaw2Strt_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorTWCHeatHi_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorTWCHeatLo_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstCorTWCHeat_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj0Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj0STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj0_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj1Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj1STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj1_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj2Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj2STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj2_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj3Autn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj3STT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstInj3_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstSTT;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstSTTCorVVT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstStrt;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstStrtCorVVT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstTWCHeatHi_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstTWCHeatLo_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstTiEngStopSTT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstTiEngStop_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facAstTiStopAutn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facCorRichCold_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facCorRichNAirLd_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facCorRichNTAir_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facCorRichTAir_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facHotStrtCorAutn_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facHotStrtCorSTT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facHotStrtCor_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facStrtCor;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facStrtCorGsl;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facStrtCorRaw_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWup;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorAirT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorInj0_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorInj1_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorInj2_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorInj3_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorRaw_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorTWCHeatHi_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorTWCHeatLo_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorTWCHeat_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupCorVVT_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupInj0_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupInj1_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupInj2_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupInj3_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupTWCHeatHi_MP;
extern VAR(Float32, INJASTWUPCMP_VAR) InjSys_facWupTWCHeatLo_MP;
extern VAR(UInt32, INJASTWUPCMP_VAR) InjSys_tiEngStopRstSTT;

#define INJASTWUPCMP_STOP_SEC_VAR_32BIT
#include "InjAstWupCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJASTWUPCMP_START_SEC_VAR_16BIT
#include "InjAstWupCmp_MemMap.h"

extern VAR(UInt16, INJASTWUPCMP_VAR) EngM_mAirPred_InjAstWupCmp;

#define INJASTWUPCMP_STOP_SEC_VAR_16BIT
#include "InjAstWupCmp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define INJASTWUPCMP_START_SEC_VAR_8BIT
#include "InjAstWupCmp_MemMap.h"

extern VAR(UInt8, INJASTWUPCMP_VAR) InjSys_stAcvAst;

#define INJASTWUPCMP_STOP_SEC_VAR_8BIT
#include "InjAstWupCmp_MemMap.h"
#endif                                 /* RTW_HEADER_InjAstWupCmp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
