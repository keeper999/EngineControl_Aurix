/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : ThrSpT                                                  */
/* !Description     : ThrSpT Software Component                               */
/*                                                                            */
/* !Module          : ThrSpT                                                  */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : ThrSpT_private.h                                        */
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
/*   Model name       : ThrSpT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /ThrSpT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M09-ThrSpT/5-SOF$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   plchinaz                               $$Date::   03 May 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ThrSpT_private_h_
#define RTW_HEADER_ThrSpT_private_h_
#include "Std_Types.h"
#include "ThrSpT_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define ThrSys_tiSampleFast_SC         ((UInt16) 20U)
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
#define ThrSpT_START_SEC_CODE
#include "ThrSpT_MemMap.h"

extern void RE_ThrSpT_003_TEV_Start(void);
extern void RE_ThrSpT_003_TEV(void);
extern void RE_ThrSpT_002_TEV_Start(void);
extern void RE_ThrSpT_002_TEV(void);
extern void RE_ThrSpT_001_MSE_Start(void);
extern void RE_ThrSpT_001_MSE(void);
void ThrSpT_ASYNC1(int controlPortIdx);
void ThrSpT_ASYNC2(int controlPortIdx);
void ThrSpT_ASYNC3(int controlPortIdx);

#define ThrSpT_STOP_SEC_CODE
#include "ThrSpT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_16BIT" */
#define ThrSpT_START_SEC_CALIB_16BIT
#include "ThrSpT_MemMap.h"

extern CONST(SInt16, THRSPT_CALIB) ThrSys_arMaxSpdAdpThr_C;
extern CONST(SInt16, THRSPT_CALIB) ThrSys_arMinSpdAdpThr_C;
extern CONST(UInt16, THRSPT_CALIB) ThrSys_arStepSpdAdpThr_C;
extern CONST(UInt16, THRSPT_CALIB) ThrSys_rOpThrReq_B;
extern CONST(UInt16, THRSPT_CALIB) ThrSys_tiDlyStabSign_mAirInt_C;

#define ThrSpT_STOP_SEC_CALIB_16BIT
#include "ThrSpT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define ThrSpT_START_SEC_CALIB_BOOLEAN
#include "ThrSpT_MemMap.h"

extern CONST(Boolean, THRSPT_CALIB) THRSPT_ACTIVE_BYP_C;

#define ThrSpT_STOP_SEC_CALIB_BOOLEAN
#include "ThrSpT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define ThrSpT_START_SEC_INTERNAL_VAR_32BIT
#include "ThrSpT_MemMap.h"

extern VAR(Float32, THRSPT_INTERNAL_VAR) ThrSys_arOpEffThrOfs;
extern VAR(SInt32, THRSPT_INTERNAL_VAR) ThrSys_arSpdAdpThr_IRV_MP;

#define ThrSpT_STOP_SEC_INTERNAL_VAR_32BIT
#include "ThrSpT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define ThrSpT_START_SEC_INTERNAL_VAR_16BIT
#include "ThrSpT_MemMap.h"

extern VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_arThrCor_MP;
extern VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_rOpThrNom;
extern VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_rOpThrNomRef2_MP;
extern VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_rOpThrNomRef3_MP;
extern VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_rOpThrNomSat_MP;
extern VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_tiStabSign_mAirInt;
extern VAR(UInt16, THRSPT_INTERNAL_VAR) ThrSys_tiStabSign_mIntPrev;

#define ThrSpT_STOP_SEC_INTERNAL_VAR_16BIT
#include "ThrSpT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define ThrSpT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ThrSpT_MemMap.h"

extern VAR(Boolean, THRSPT_INTERNAL_VAR) ThrSys_bAcvSpdAdpThr;
extern VAR(Boolean, THRSPT_INTERNAL_VAR) ThrSys_bAdpThrSign_mAirInt;
extern VAR(Boolean, THRSPT_INTERNAL_VAR) ThrSys_bAdpThrSign_mIntPrev;

#define ThrSpT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ThrSpT_MemMap.h"
#endif                                 /* RTW_HEADER_ThrSpT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
