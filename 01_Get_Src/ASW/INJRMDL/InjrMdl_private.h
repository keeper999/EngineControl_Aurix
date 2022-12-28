/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjrMdl                                                 */
/* !Description     : InjSys - MODELE INJECTEUR (GDI)                         */
/*                                                                            */
/* !Module          : InjrMdl                                                 */
/*                                                                            */
/* !File            : InjrMdl_private.h                                       */
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
/*   Code generated on: Wed Mar 13 19:55:28 2013                              */
/*   Model name       : InjrMdl_AUTOCODE.mdl                                  */
/*   Model version    : 1.280                                                 */
/*   Root subsystem   : /InjrMdl                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjrMdl/5-SOFT-LIV/InjrMdl_p$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   18 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjrMdl_private_h_
#define RTW_HEADER_InjrMdl_private_h_
#include "Std_Types.h"
#include "InjrMdl_types.h"
#include "InjrMdl_import.h"
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
#define INJRMDL_START_SEC_CODE
#include "InjrMdl_MemMap.h"

extern void InjrMdl_F01_InjrMdl(UInt16 rtu_FuSysM_tFu, const UInt16
  rtu_InjrM_prm_facGainLnrlnjRaw[4], const UInt16 rtu_InjrM_prm_pDifInjr[4],
  SInt32 rtu_AFA_facSlopInjGain, SInt16 rtu_AFA_facIvsInjGain, const UInt16
  rtu_InjrM_prm_facCorGainLnr[4], UInt16 rtu_Ext_uBatt, const SInt16
  rtu_InjrM_prm_tiInjOfsRaw[4], SInt8 rtu_AFA_tiOffInj, rtB_F01_InjrMdl_InjrMdl
  *localB);
extern void InjrMdl_F01_InjrMdl_EveRst(void);
extern void InjrMdl_F01_InjrMdlSyncRst(void);
extern void InjrM_EveRst_InjrMdl_Start(void);
extern void InjrM_EveRst_InjrMdl(void);
extern void InjrMdl_F01_InjrMdl_g(void);
extern void InjrMdl_F02_InjrMdlSyncEveClcn(void);
extern void InjrM_EveCkSnOn_InjrMdl_Start(void);
extern void InjrM_EveCkSnOn_InjrMdl(void);
extern void InjrM_EveCkSnOn_InjrMdl(void);
extern void InjrM_EveCkSnOn_InjrMdl(void);
extern void InjrM_SdlFast_InjrMdl(void);
extern void InjrMdl_F03_InjrMdlSyncEveInj(void);
extern void InjrM_EveInj_InjrMdl_Start(void);
extern void InjrM_EveInj_InjrMdl(void);
extern void InjrM_EveSpl_InjrMdl(void);
void InjrMdl_ASYNC1(int controlPortIdx);
void InjrMdl_ASYNC2(int controlPortIdx);
void InjrMdl_ASYNC3(int controlPortIdx);

#define INJRMDL_STOP_SEC_CODE
#include "InjrMdl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJRMDL_START_SEC_CALIB_8BIT
#include "InjrMdl_MemMap.h"

extern CONST(UInt8, INJRMDL_CALIB) INJRMDL_u8Inhib;

#define INJRMDL_STOP_SEC_CALIB_8BIT
#include "InjrMdl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJRMDL_START_SEC_VAR_16BIT
#include "InjrMdl_MemMap.h"

extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainH1CylPrev[6];
extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainH2CylPrev[6];
extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainS1CylPrev[6];
extern VAR(UInt16, INJRMDL_VAR) InjrM_prm_facGainS2CylPrev[6];
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsH1CylPrev[6];
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsH2CylPrev[6];
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsS1CylPrev[6];
extern VAR(SInt16, INJRMDL_VAR) InjrM_prm_tiInjOfsS2CylPrev[6];

#define INJRMDL_STOP_SEC_VAR_16BIT
#include "InjrMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define INJRMDL_START_SEC_VAR_32BIT
#include "InjrMdl_MemMap.h"

extern VAR(Float32, INJRMDL_VAR) InjrM_prm_facGainLnrInj[4];
extern VAR(Float32, INJRMDL_VAR) InjrM_prm_mfFuStndAdp_MP[4];

#define INJRMDL_STOP_SEC_VAR_32BIT
#include "InjrMdl_MemMap.h"
#endif                                 /* RTW_HEADER_InjrMdl_private_h_ */

/*-------------------------------- end of file -------------------------------*/
