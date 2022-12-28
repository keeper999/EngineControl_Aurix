/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpCtl                                                */
/* !Description     : HPPmpCtl - RÉGULATION DE LA PRESSION RAIL               */
/*                                                                            */
/* !Module          : HPPmpCtl                                                */
/*                                                                            */
/* !File            : HPPmpCtl_private.h                                      */
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
/*   Code generated on: Tue Jul 10 10:40:13 2012                              */
/*   Model name       : HPPmpCtl_AUTOCODE.mdl                                 */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /HPPmpCtl                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPCTL/HPPmpCtl_private$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_HPPmpCtl_private_h_
#define RTW_HEADER_HPPmpCtl_private_h_
#include "Std_Types.h"
#include "HPPmpCtl_types.h"
#include "HPPmpCtl_import.h"
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
#define HPPMPCTL_START_SEC_CODE
#include "HPPmpCtl_MemMap.h"

extern UInt32 plook_u32u16f_binc(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp2d_iu16n15ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride);
extern Float32 look1_iu16lftu8n8If_binlcns(UInt16 localu0, const UInt16
  localbp0[], const UInt8 localtable[], UInt32 localmaxIndex);
extern Float32 intrp1d_iu16n14ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern void HPPmpCtl_F01_HPPmpCtl(Float32 *rty_PFuCtl_pFuRailDifDClCtl,
  rtB_F01_HPPmpCtl_HPPmpCtl *localB);
extern void HPPmpCtl_F01_HPPmpCtl_c(void);
extern void PFuCtl_EveRTSt_HPPmpCtl(void);
extern void HPPmpCtl_F01_HPPmpCtl_Ini(void);
extern void PFuCtl_EveRst_HPPmpCtl(void);
extern void HPPmpCtl_F03_HPPmpCtl(void);
extern void PFuCtl_EveSpl_HPPmpCtl(void);
extern void HPPmpCtl_F02_HPPmpCtl_ETB(void);
extern void PFuCtl_SdlMid_HPPmpCtl(void);
void HPPmpCtl_ASYNC1(int controlPortIdx);

#define HPPMPCTL_STOP_SEC_CODE
#include "HPPmpCtl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define HPPMPCTL_START_SEC_CALIB_8BIT
#include "HPPmpCtl_MemMap.h"

extern CONST(UInt8, HPPMPCTL_CALIB) HPPMPCTL_u8Inhib;

#define HPPMPCTL_STOP_SEC_CALIB_8BIT
#include "HPPmpCtl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define HPPMPCTL_START_SEC_VAR_32BIT
#include "HPPmpCtl_MemMap.h"

extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_facGainPPFuCtlErrCor_MP;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_facGainPPFuCtlErrW_MP;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_facGainPPFuCtl_MP;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_mFuPmpReqCtl;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_mFuPmpReqOpl;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifClCtl;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifCtl;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifDClCtl;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifDClCtl_prev;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifIClCtl_prev;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifIncIClCtl;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifOplCtl;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifOplCtl_prev;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDifPClCtl;
extern VAR(Float32, HPPMPCTL_VAR) PFuCtl_pFuRailDif_prev;

#define HPPMPCTL_STOP_SEC_VAR_32BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define HPPMPCTL_START_SEC_VAR_16BIT
#include "HPPmpCtl_MemMap.h"

extern VAR(UInt16, HPPMPCTL_VAR) PFuCtl_tiETB;
extern VAR(UInt16, HPPMPCTL_VAR) PFuCtl_tiETB_Prev;

#define HPPMPCTL_STOP_SEC_VAR_16BIT
#include "HPPmpCtl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define HPPMPCTL_START_SEC_VAR_BOOLEAN
#include "HPPmpCtl_MemMap.h"

extern VAR(Boolean, HPPMPCTL_VAR) PFuCtl_bPFuRailClCtlIni;

#define HPPMPCTL_STOP_SEC_VAR_BOOLEAN
#include "HPPmpCtl_MemMap.h"
#endif                                 /* RTW_HEADER_HPPmpCtl_private_h_ */

/*-------------------------------- end of file -------------------------------*/
