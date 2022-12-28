/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvSpT                                                  */
/* !Description     : AdvSpT Software Component                               */
/*                                                                            */
/* !Module          : AdvSpT                                                  */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AdvSpT_private.h                                        */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
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
/*   Model name       : AdvSpT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /AdvSpT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M06-AdvSpT/5-SO$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   02 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvSpT_private_h_
#define RTW_HEADER_AdvSpT_private_h_
#include "Std_Types.h"
#include "AdvSpT_types.h"
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
#define AdvSpT_START_SEC_CODE
#include "AdvSpT_MemMap.h"

extern void RE_AdvSpT_003_MSE(void);
extern void RE_AdvSpT_001_MSE_Start(void);
extern void RE_AdvSpT_001_MSE(void);
extern void RE_AdvSpT_005_MSE_Start(void);
extern void RE_AdvSpT_005_MSE(void);
extern void RE_AdvSpT_002_DRE_Start(void);
extern void RE_AdvSpT_002_DRE(void);
extern void RE_AdvSpT_006_DRE_Start(void);
extern void RE_AdvSpT_006_DRE(void);
extern void RE_AdvSpT_004_DRE_Start(void);
extern void RE_AdvSpT_004_DRE(void);
void AdvSpT_ASYNC1(int controlPortIdx);
void AdvSpT_ASYNC2(int controlPortIdx);
void AdvSpT_ASYNC3(int controlPortIdx);

#define AdvSpT_STOP_SEC_CODE
#include "AdvSpT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_16BIT" */
#define AdvSpT_START_SEC_CALIB_16BIT
#include "AdvSpT_MemMap.h"

extern CONST(UInt16, ADVSPT_CALIB) IgSys_nEngThd_CutOff_C;
extern CONST(UInt16, ADVSPT_CALIB) IgSys_r80PercTq_C;
extern CONST(SInt16, ADVSPT_CALIB) IgSys_tCoMesSftyVal_C;
extern CONST(SInt16, ADVSPT_CALIB) IgSys_tCoThd_CutOff_C;
extern CONST(UInt16, ADVSPT_CALIB) IgSys_tOxCThdMax_CutOff_C;
extern CONST(UInt16, ADVSPT_CALIB) IgSys_tOxCThdMin_CutOff_C;
extern CONST(SInt16, ADVSPT_CALIB) IgSys_tqIdcEngCurMinThdNoRcvSC_C;
extern CONST(SInt16, ADVSPT_CALIB) IgSys_tqIdcEngCurMinThd_NoRcv_C;
extern CONST(SInt16, ADVSPT_CALIB) IgSys_tqIdcEngCurMinThd_Rcv_C;

#define AdvSpT_STOP_SEC_CALIB_16BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define AdvSpT_START_SEC_CARTO_16BIT
#include "AdvSpT_MemMap.h"

extern CONST(UInt16, ADVSPT_CARTO) IgSys_rTar_OfsAgIg_A[104];

#define AdvSpT_STOP_SEC_CARTO_16BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define AdvSpT_START_SEC_CALIB_8BIT
#include "AdvSpT_MemMap.h"

extern CONST(UInt8, ADVSPT_CALIB) IgSys_agIg80PercTq_B;
extern CONST(UInt8, ADVSPT_CALIB) IgSys_agIgOfs80PrecTq_B;
extern CONST(UInt8, ADVSPT_CALIB) IgSys_agIgTarWiCllTar_B;
extern CONST(UInt8, ADVSPT_CALIB) IgSys_agIgTarWoutAntiJerk_B;
extern CONST(UInt8, ADVSPT_CALIB) IgSys_noCylCutOffTar_B;
extern CONST(UInt8, ADVSPT_CALIB) IgSys_noCylMaxCutOff_C;
extern CONST(UInt8, ADVSPT_CALIB) IgSys_rtqIdcEngCurMinNoRcvSC_C;
extern CONST(UInt8, ADVSPT_CALIB) IgSys_rtqIdcEngCurMin_NoRcv_C;
extern CONST(UInt8, ADVSPT_CALIB) IgSys_rtqIdcEngCurMin_Rcv_C;

#define AdvSpT_STOP_SEC_CALIB_8BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AdvSpT_START_SEC_CALIB_BOOLEAN
#include "AdvSpT_MemMap.h"

extern CONST(Boolean, ADVSPT_CALIB) ADVSPT_ACTIVE_BYP_C;
extern CONST(Boolean, ADVSPT_CALIB) IgSys_bInh_SelCutOff_C;

#define AdvSpT_STOP_SEC_CALIB_BOOLEAN
#include "AdvSpT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define AdvSpT_START_SEC_CARTO_8BIT
#include "AdvSpT_MemMap.h"

extern CONST(UInt8, ADVSPT_CARTO) IgSys_agIgTarOfs_OfsAgIg_T[104];

#define AdvSpT_STOP_SEC_CARTO_8BIT
#include "AdvSpT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define AdvSpT_START_SEC_INTERNAL_VAR_16BIT
#include "AdvSpT_MemMap.h"

extern VAR(SInt16, ADVSPT_INTERNAL_VAR) IgSys_agIgTar_AgIg_MP;
extern VAR(SInt16, ADVSPT_INTERNAL_VAR) IgSys_agIgTar_MP;
extern VAR(SInt16, ADVSPT_INTERNAL_VAR) IgSys_agIg_AntiJerk_MP;
extern VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_facAgCorSwtTar_MP;
extern VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_facTarAgCorSwtAntiJ_MP;
extern VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_rTarEfcMux_MP[2];
extern VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_rTarEfcWoutAntiJerk_IRV_MP;
extern VAR(UInt16, ADVSPT_INTERNAL_VAR) IgSys_rTarEfc_IRV_MP;
extern VAR(SInt16, ADVSPT_INTERNAL_VAR) IgSys_tSelTCoUsr_MP;

#define AdvSpT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define AdvSpT_START_SEC_INTERNAL_VAR_8BIT
#include "AdvSpT_MemMap.h"

extern VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_agIgAntiJerkOfs_MP;
extern VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_agIgTarOfs_MP;
extern VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_noCylCutOffInc_MP;
extern VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_noCylCutOffSwt_MP;
extern VAR(UInt8, ADVSPT_INTERNAL_VAR) IgSys_noCylCutOff_MP;
extern VAR(UInt8, ADVSPT_INTERNAL_VAR) InjSys_noCylCutOffDly;
extern VAR(UInt8, ADVSPT_INTERNAL_VAR) InjSys_noCylCutOffDlyOut;

#define AdvSpT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AdvSpT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvSpT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvSpT_MemMap.h"

extern VAR(Boolean, ADVSPT_INTERNAL_VAR) InjSys_bCylCutOff;
extern VAR(Boolean, ADVSPT_INTERNAL_VAR) InjSys_bCylCutOffTrig;

#define AdvSpT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvSpT_MemMap.h"
#endif                                 /* RTW_HEADER_AdvSpT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
