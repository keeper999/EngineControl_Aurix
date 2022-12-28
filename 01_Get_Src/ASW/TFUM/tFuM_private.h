/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tFuM                                                    */
/* !Description     : tFuM – Fuel temperature estimation                      */
/*                                                                            */
/* !Module          : tFuM                                                    */
/*                                                                            */
/* !File            : tFuM_private.h                                          */
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
/*   Code generated on: Thu Aug 30 11:09:41 2012                              */
/*   Model name       : tFuM_AUTOCODE.mdl                                     */
/*   Model version    : 1.502                                                 */
/*   Root subsystem   : /tFuM                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/tFuM/5-SOFT-LIV/tFuM_private$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   30 Aug 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_tFuM_private_h_
#define RTW_HEADER_tFuM_private_h_
#include "Std_Types.h"
#include "tFuM_types.h"
#include "tFuM_import.h"
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
#define TFUM_START_SEC_CODE
#include "tFuM_MemMap.h"

extern UInt32 div_u32_near(UInt32 localnumerator, UInt32 localdenominator);
extern UInt32 div_repeat_u32_near(UInt32 localnumerator, UInt32
  localdenominator, UInt32 localnRepeatSub);
extern UInt32 plook_u32u8u16n15_binc_n(UInt8 localu, const UInt8 localbp[],
  UInt32 localmaxIndex, UInt16 *localfraction);
extern Float32 intrp2d_iu16n16ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride);
extern Float32 intrp2d_iu16n15ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride);
extern UInt32 binsearch_u32u8(UInt8 localu, const UInt8 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern UInt32 plook_u32u16u16n15_binc_n(UInt16 localu, const UInt16
  localbp[], UInt32 localmaxIndex, UInt16 *localfraction);
extern Float32 intrp2d_iu16n6ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride);
extern Float32 intrp1d_iu8n7ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt8 localtable[]);
extern Float32 intrp2d_iu8ff_u32f_l_s(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt8 localtable[], UInt32 localstride);
extern Float32 intrp1d_iu16n16ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern UInt32 plook_u32u32u16n15_binc_n(UInt32 localu, const UInt32
  localbp[], UInt32 localmaxIndex, UInt16 *localfraction);
extern Float32 intrp2d_iu8n7ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt8 localtable[], UInt32 localstride);
extern UInt32 binsearch_u32u32(UInt32 localu, const UInt32 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern void tFuM_F01_Ini_tEng(void);
extern void tFuM_F00_Ini_acvTFu(void);
extern void FuSysM_EveRst_tFuM_Start(void);
extern void FuSysM_EveRst_tFuM(void);
extern void tFuM_F02_Calc_tEng(void);
extern void tFuM_F02_Sdl_Calc_fuel_temp(void);
extern void FuSysM_SdlSlow_tFuM_Start(void);
extern void FuSysM_SdlSlow_tFuM(void);
extern void tFuM_F03_save_fuel_temp_EEPROM(void);
extern void FuSysM_EvePwrl_tFuM(void);
extern void tFuM_F01_Init_fuel_temp(void);
extern void FuSysM_EveRxn552_tFuM_Start(void);
extern void FuSysM_EveRxn552_tFuM(void);
void tFuM_ASYNC1(int controlPortIdx);
void tFuM_ASYNC2(int controlPortIdx);
void tFuM_ASYNC3(int controlPortIdx);
void tFuM_ASYNC4(int controlPortIdx);

#define TFUM_STOP_SEC_CODE
#include "tFuM_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define TFUM_START_SEC_CALIB_8BIT
#include "tFuM_MemMap.h"

extern CONST(UInt8, TFUM_CALIB) TFUM_u8Inhib;

#define TFUM_STOP_SEC_CALIB_8BIT
#include "tFuM_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define TFUM_START_SEC_VAR_32BIT
#include "tFuM_MemMap.h"

extern VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFu;
extern VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFuExgWa;
extern VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFuUsPmp;
extern VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFuUsPmpEng;
extern VAR(Float32, TFUM_VAR) FuSysM_facCormfFutFuUsPmpExt;
extern VAR(Float32, TFUM_VAR) FuSysM_facExgAirtFuUsPmp;
extern VAR(Float32, TFUM_VAR) FuSysM_facExgUndHo;
extern VAR(Float32, TFUM_VAR) FuSysM_facExgmfFu;
extern VAR(Float32, TFUM_VAR) FuSysM_facExgtEngtFu;
extern VAR(Float32, TFUM_VAR) FuSysM_facExgtEngtFuUsPmp;
extern VAR(Float32, TFUM_VAR) FuSysM_facExgtExttFuUsPmp;
extern VAR(Float32, TFUM_VAR) FuSysM_factFuExgAirStall;
extern VAR(Float32, TFUM_VAR) FuSysM_rCorTFuIni;
extern VAR(Float32, TFUM_VAR) FuSysM_rCorTFuUsPmpIni;
extern VAR(Float32, TFUM_VAR) FuSysM_rGainFilUndHo;
extern VAR(Float32, TFUM_VAR) FuSysM_tEng;
extern VAR(Float32, TFUM_VAR) FuSysM_tEngPrev;
extern VAR(Float32, TFUM_VAR) FuSysM_tEngRaw;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuExgAirStallCor;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuExgWaCor;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuExgWaStallCor;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuExgmfFuCor;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuExgtEngCor;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuExgtEngRaw;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuFineRsl;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuPrev;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpAirDif;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpAirDifStall;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpBasCorRaw;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpBasFil;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpBasRaw;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpEngCorFil;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpEngCorRaw;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpEngRaw;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExgAirCor;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExgWaCor;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExtCorFil;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExtCorRaw;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpExtRaw;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpFineRsl;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpPrev;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmpWaDifStall;
extern VAR(Float32, TFUM_VAR) FuSysM_tFuUsPmptEngDif;
extern VAR(Float32, TFUM_VAR) FuSysM_tFutAirDifStall;
extern VAR(Float32, TFUM_VAR) FuSysM_tFutEngDif;
extern VAR(Float32, TFUM_VAR) FuSysM_tFutFuUsPmpDif;
extern VAR(Float32, TFUM_VAR) FuSysM_tFutWaDif;
extern VAR(Float32, TFUM_VAR) FuSysM_tFutWaDifStall;
extern VAR(Float32, TFUM_VAR) FuSysM_tOiltAirDif;
extern VAR(UInt32, TFUM_VAR) FuSysM_tiEcuStop;
extern VAR(Float32, TFUM_VAR) FuSysM_tiFilBastFuUsPmp;
extern VAR(Float32, TFUM_VAR) FuSysM_tiFilExgtFuUsPmp;

#define TFUM_STOP_SEC_VAR_32BIT
#include "tFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define TFUM_START_SEC_VAR_16BIT
#include "tFuM_MemMap.h"

extern VAR(UInt16, TFUM_VAR) FuSysM_mfFuEstim;

#define TFUM_STOP_SEC_VAR_16BIT
#include "tFuM_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define TFUM_START_SEC_VAR_BOOLEAN
#include "tFuM_MemMap.h"

extern VAR(Boolean, TFUM_VAR) FuSysM_bAcvTFuInit;
extern VAR(Boolean, TFUM_VAR) FuSysM_bRstFil;

#define TFUM_STOP_SEC_VAR_BOOLEAN
#include "tFuM_MemMap.h"
#endif                                 /* RTW_HEADER_tFuM_private_h_ */

/*-------------------------------- end of file -------------------------------*/
