/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : FuRailCtlMgr                                            */
/* !Description     : FuRailCtlMgr- RAIL PRESSURE CONTROL MANAGER             */
/*                                                                            */
/* !Module          : FuRailCtlMgr                                            */
/*                                                                            */
/* !File            : FuRailCtlMgr_private.h                                  */
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
/*   Code generated on: Wed Dec 19 10:34:55 2012                              */
/*   Model name       : FuRailCtlMgr_AUTOCODE.mdl                             */
/*   Model version    : 1.333                                                 */
/*   Root subsystem   : /FuRailCtlMgr                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/FuRailCtlMgr/5-SOFT-LIV/FuRa$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   19 Dec 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_FuRailCtlMgr_private_h_
#define RTW_HEADER_FuRailCtlMgr_private_h_
#include "Std_Types.h"
#include "FuRailCtlMgr_types.h"
#include "FuRailCtlMgr_import.h"
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
#define FURAILCTLMGR_START_SEC_CODE
#include "FuRailCtlMgr_MemMap.h"

extern UInt32 plook_u32u8f_binc(UInt8 localu, const UInt8 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp1d_iu16p9ff_u32f_l_s(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern UInt32 binsearch_u32u8(UInt8 localu, const UInt8 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern void FuRai_F01_F00_FuRailCtlMgr_init(Boolean rtu_FRM_bInhPfuCtl,
  rtB_F01_F00_FuRailCtlMgr_init_F *localB);
extern void FuRailCtl_F01_FuRailCtlMgr_init(void);
extern void FuRailCtlMgr_F04_FirstSplEveRst(rtB_F04_FirstSplEveRst_FuRailCt
  *localB);
extern void F_F04_FirstSplEveRst_inhibition(void);
extern void PFuCtl_EveRTSt_FuRailCtlMgr_Start(void);
extern void PFuCtl_EveRTSt_FuRailCtlMgr(void);
extern void PFuCtl_EveRTSt_FuRailCtlMgr(void);
extern void F01_FuRailCtlMgr_init_inhibitio(void);
extern void FuRailCtlM_F04_FirstSplEveRst_k(void);
extern void PFuCtl_EveRst_FuRailCtlMgr_Start(void);
extern void PFuCtl_EveRst_FuRailCtlMgr(void);
extern void FuRailCtlMgr_F03_FirstSplEveAcv(void);
extern void FuRailCtl_F02_FuRailCtlMgr_clcn(void);
extern void F_F05_FuRailCtlMgr_conti_Enable(SInt32 controlPortIdx);
extern void Fu_F05_FuRailCtlMgr_conti_Start(void);
extern void F05_FuRailCtlMgr_conti_Disable(SInt32 controlPortIdx);
extern void FuRailCt_F05_FuRailCtlMgr_conti(void);
extern void PFuCtl_EveSpl_FuRailCtlMgr_Enable(void);
extern void PFuCtl_EveSpl_FuRailCtlMgr_Start(void);
extern void PFuCtl_EveSpl_FuRailCtlMgr_Disable(void);
extern void PFuCtl_EveSpl_FuRailCtlMgr(void);
extern void PFuCtl_EveSpl_FuRailCtlMgr(void);
extern void PFuCtl_EveStTR_FuRailCtlMgr(void);
extern void PFuCtl_SdlFast_FuRailCtlMgr_Enable(void);
extern void PFuCtl_SdlFast_FuRailCtlMgr_Start(void);
extern void PFuCtl_SdlFast_FuRailCtlMgr_Disable(void);
extern void PFuCtl_SdlFast_FuRailCtlMgr(void);
void FuRailCtlMgr_ASYNC1(int controlPortIdx);
void FuRailCtlMgr_ASYNC2(int controlPortIdx);
void FuRailCtlMgr_ASYNC3(int controlPortIdx);
void FuRailCtlMgr_ASYNC5(int controlPortIdx);

#define FURAILCTLMGR_STOP_SEC_CODE
#include "FuRailCtlMgr_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define FURAILCTLMGR_START_SEC_CALIB_8BIT
#include "FuRailCtlMgr_MemMap.h"

extern CONST(UInt8, FURAILCTLMGR_CALIB) FURAILCTLMGR_u8Inhib;

#define FURAILCTLMGR_STOP_SEC_CALIB_8BIT
#include "FuRailCtlMgr_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define FURAILCTLMGR_START_SEC_VAR_16BIT
#include "FuRailCtlMgr_MemMap.h"

extern VAR(UInt16, FURAILCTLMGR_VAR) PFuCtl_pFuRailHiThdAcvClCtl;

#define FURAILCTLMGR_STOP_SEC_VAR_16BIT
#include "FuRailCtlMgr_MemMap.h"
#endif                                 /* RTW_HEADER_FuRailCtlMgr_private_h_ */

/*-------------------------------- end of file -------------------------------*/
