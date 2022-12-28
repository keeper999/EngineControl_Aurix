/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpFctDiag                                            */
/* !Description     : HPPmpFctDiag– DIAGNOSTIC FONCTIONNEL DE LA REGULATION PRESSION RAIL*/
/*                                                                            */
/* !Module          : HPPmpFctDiag                                            */
/*                                                                            */
/* !File            : HPPmpFctDiag_private.h                                  */
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
/*   Code generated on: Wed Jul 17 22:17:33 2013                              */
/*   Model name       : HPPmpFctDiag_AUTOCODE.mdl                             */
/*   Model version    : 1.352                                                 */
/*   Root subsystem   : /HPPmpFctDiag                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPFCTDIAG/HPPmpFctDiag$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   24 Jul 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPPmpFctDiag_private_h_
#define RTW_HEADER_HPPmpFctDiag_private_h_
#include "Std_Types.h"
#include "HPPmpFctDiag_types.h"
#include "HPPmpFctDiag_import.h"
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
#define HPPMPFCTDIAG_START_SEC_CODE
#include "HPPmpFctDiag_MemMap.h"

extern void mul_wide_u32(UInt32 localin0, UInt32 localin2, UInt32
  *localptrOutBitsHi, UInt32 *localptrOutBitsLo);
extern UInt32 mul_u32_u32_u32_sat(UInt32 locala, UInt32 localb);
extern UInt32 plook_u32u8f_binc(UInt8 localu, const UInt8 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp1d_iu16p9ff_u32f_l_s(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern UInt32 plook_u32u16f_binc(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp1d_iu16n7ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern UInt32 binsearch_u32u8(UInt8 localu, const UInt8 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern void HPPmpFctD_HPPmpCtlFctDiag_Start(void);
extern void HPPmpFctDiag_HPPmpCtlFctDiag(void);
extern void HPPmpFctDiag_GDGAR_vidGdu1(void);
extern void HPPmpFctDiag_GDGAR_vidGdu2(void);
extern void HPPmpFctDiag_GDGAR_vidGdu3(void);
extern void HPPmpFctDiag_GDGAR_vidGdu4(void);
extern void HPPmpFctDiag_GDGAR_vidGdu5(void);
extern void PFuCtl_EveSpl_HPPmpFctDiag_Start(void);
extern void PFuCtl_EveSpl_HPPmpFctDiag(void);

#define HPPMPFCTDIAG_STOP_SEC_CODE
#include "HPPmpFctDiag_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPPMPFCTDIAG_START_SEC_CALIB_8BIT
#include "HPPmpFctDiag_MemMap.h"

extern CONST(UInt8, HPPMPFCTDIAG_CALIB) HPPMPFCTDIAG_u8Inhib;

#define HPPMPFCTDIAG_STOP_SEC_CALIB_8BIT
#include "HPPmpFctDiag_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define HPPMPFCTDIAG_START_SEC_VAR_32BIT
#include "HPPmpFctDiag_MemMap.h"

extern VAR(Float32, HPPMPFCTDIAG_VAR) PFuCtl_PrailLoopErr;
extern VAR(Float32, HPPMPFCTDIAG_VAR) PFuCtl_pFuReqDiff;
extern VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiAftrCutOffDly;
extern VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiPFuRailMesDly;
extern VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiPrailOvrThd_prev;
extern VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiThdDetDeICtlDlyNeg;
extern VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiThdDetDeICtlDlyPos;
extern VAR(UInt32, HPPMPFCTDIAG_VAR) PFuCtl_tiTransPFuReqDly;

#define HPPMPFCTDIAG_STOP_SEC_VAR_32BIT
#include "HPPmpFctDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define HPPMPFCTDIAG_START_SEC_VAR_BOOLEAN
#include "HPPmpFctDiag_MemMap.h"

extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bAcvDecCntDeICtlNeg;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bAcvDecCntDeICtlPos;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngIFrz_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngMax_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngNegDifI_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngNeg_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngPosDifI_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDgoORngPos_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDiagAcvCond;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bDlyAftrCutOff;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngDifI_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngIFrz_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngMax_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngNeg_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bMonRunORngPos_PFuCtl;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bTransDiagAcvCond;
extern VAR(Boolean, HPPMPFCTDIAG_VAR) PFuCtl_bTransPFuReq;

#define HPPMPFCTDIAG_STOP_SEC_VAR_BOOLEAN
#include "HPPmpFctDiag_MemMap.h"
#endif                                 /* RTW_HEADER_HPPmpFctDiag_private_h_ */

/*-------------------------------- end of file -------------------------------*/
