/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuSpCrk                                                */
/* !Description     : INJECTED FUEL MASS SET POINT DURING CRANKING            */
/*                                                                            */
/* !Module          : mFuSpCrk                                                */
/*                                                                            */
/* !File            : mFuSpCrk_private.h                                      */
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
/*   Code generated on: Sun Jun 02 16:30:57 2013                              */
/*   Model name       : mFuSpCrk_AUTOCODE.mdl                                 */
/*   Model version    : 1.387                                                 */
/*   Root subsystem   : /mFuSpCrk                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUSPCRK/mFuSpCrk_private.$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_mFuSpCrk_private_h_
#define RTW_HEADER_mFuSpCrk_private_h_
#include "Std_Types.h"
#include "mFuSpCrk_types.h"
#include "mFuSpCrk_import.h"
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
#define MFUSPCRK_START_SEC_CODE
#include "mFuSpCrk_MemMap.h"

extern UInt32 div_repeat_u32(UInt32 localnumerator, UInt32
  localdenominator, UInt32 localnRepeatSub);
extern void mul_wide_u32(UInt32 localin0, UInt32 localin2, UInt32
  *localptrOutBitsHi, UInt32 *localptrOutBitsLo);
extern UInt32 mul_u32_u32_u32_sr31(UInt32 locala, UInt32 localb);
extern Float32 look1_iu16lftu8n7If_binlcns(UInt16 localu0, const UInt16
  localbp0[], const UInt8 localtable[], UInt32 localmaxIndex);
extern Float32 look2_iu16u8lftu8n7If_binlcns(UInt16 localu0, UInt8 localu1,
  const UInt16 localbp0[], const UInt8 localbp1[], const UInt8 localtable[],
  const UInt32 localmaxIndex[], UInt32 localstride);
extern Float32 look1_iu8lftu8n7If_binlcns(UInt8 localu0, const UInt8
  localbp0[], const UInt8 localtable[], UInt32 localmaxIndex);
extern UInt32 plook_u32u16_bincka(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex);
extern UInt32 plook_u32u16f_binc(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern UInt32 plook_u32u8f_binc(UInt8 localu, const UInt8 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern UInt32 binsearch_u32u8(UInt8 localu, const UInt8 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern Float32 intrp1d_iu16ff_u32f_l_s(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern Float32 intrp2d_iu16n27ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride);
extern Float32 intrp1d_iu8n8ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt8 localtable[]);
extern void F01_mFuFacCorRstrtSTT_Reusable(UInt16 rtu_Eng_mO2Cat, SInt16
  rtu_Ext_tCoMes, UInt16 rtu_Ext_nEng, UInt8 rtu_Eng_ctTDCStrt, Boolean
  rtu_CoPTSt_bRStrtSTT, UInt16 rtu_UsThrM_pAirExt,
  rtB_F01_mFuFacCorRstrtSTT_Reusa *localB);
extern void InjSys_EveRst_mFuSpCrk_Start(void);
extern void InjSys_EveRst_mFuSpCrk(void);
extern void mFuSpCrk_F01_IniCrkfacCor(SInt32 controlPortIdx);
extern void mFuSpCrk_F02_IniCrkMass(SInt32 controlPortIdx);
extern void InjSys_EveKOn_mFuSpCrk_Start(void);
extern void InjSys_EveKOn_mFuSpCrk(void);
extern void InjSys_EveKOn_mFuSpCrk(void);
extern void InjSys_EveKOn_mFuSpCrk(void);
extern void mFuSpCrk_F01_mFuFacCorRstrtSTT(SInt32 controlPortIdx);
extern void InjSys_EveStTR_mFuSpCrk_Start(void);
extern void InjSys_EveStTR_mFuSpCrk(void);
extern void InjSys_EveStTR_mFuSpCrk(void);
extern void InjSys_EveRTCr_mFuSpCrk(void);
extern void mFuSpCrk_F01_mFuInjCutOff(UInt16 *rty_InjSys_mFuCrkSp);
extern void InjSys_SdlFast_mFuSpCrk_Start(void);
extern void InjSys_SdlFast_mFuSpCrk(void);
extern void InjSys_EveInj_mFuSpCrk_Start(void);
extern void InjSys_EveInj_mFuSpCrk(void);
void mFuSpCrk_ASYNC1(int controlPortIdx);
void mFuSpCrk_ASYNC2(int controlPortIdx);
void mFuSpCrk_ASYNC3(int controlPortIdx);
void mFuSpCrk_ASYNC4(int controlPortIdx);
void mFuSpCrk_ASYNC7(int controlPortIdx);
void mFuSpCrk_ASYNC9(int controlPortIdx);

#define MFUSPCRK_STOP_SEC_CODE
#include "mFuSpCrk_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define MFUSPCRK_START_SEC_CALIB_8BIT
#include "mFuSpCrk_MemMap.h"

extern CONST(UInt8, MFUSPCRK_CALIB) MFUSPCRK_u8Inhib;

#define MFUSPCRK_STOP_SEC_CALIB_8BIT
#include "mFuSpCrk_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define MFUSPCRK_START_SEC_VAR_32BIT
#include "mFuSpCrk_MemMap.h"

extern VAR(Float32, MFUSPCRK_VAR) InjSys_facCorMassFuRstrt;
extern VAR(Float32, MFUSPCRK_VAR) InjSys_mFuFacCorRstrtSTT;
extern VAR(Float32, MFUSPCRK_VAR) InjSys_mFuReqCrkMin;
extern VAR(Float32, MFUSPCRK_VAR) InjSys_mFuReqCrkMinPrev;

#define MFUSPCRK_STOP_SEC_VAR_32BIT
#include "mFuSpCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define MFUSPCRK_START_SEC_VAR_16BIT
#include "mFuSpCrk_MemMap.h"

extern VAR(UInt16, MFUSPCRK_VAR) InjSys_ctTDCThdAcvDecMassFu;
extern VAR(UInt16, MFUSPCRK_VAR) InjSys_mFuCrkSpPrev;

#define MFUSPCRK_STOP_SEC_VAR_16BIT
#include "mFuSpCrk_MemMap.h"
#endif                                 /* RTW_HEADER_mFuSpCrk_private_h_ */

/*-------------------------------- end of file -------------------------------*/
