/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : InThMdlT                                                */
/* !Description     : InThMdlT Software Component                             */
/*                                                                            */
/* !Module          : InThMdlT                                                */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : InThMdlT_private.h                                      */
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
/*   Model name       : InThMdlT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /InThMdlT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M03-InThMdlT/5-S$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   17 Nov 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InThMdlT_private_h_
#define RTW_HEADER_InThMdlT_private_h_
#include "Std_Types.h"
#include "InThMdlT_types.h"
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
#define InThMdlT_START_SEC_CODE
#include "InThMdlT_MemMap.h"

extern void InThMdlT_IfActionSubsystem1(UInt16 rtu_InThM_tEGRInMnf1, UInt16 *
  rty_InThM_tEGRInMnf);
extern void RE_InThMdlT_001_MSE_Start(void);
extern void RE_InThMdlT_001_MSE(void);
extern void RE_InThMdlT_002_TEV_Start(void);
extern void RE_InThMdlT_002_TEV(void);
extern void RE_InThMdlT_007_TEV_Start(void);
extern void RE_InThMdlT_007_TEV(void);
extern void RE_InThMdlT_008_TEV_Start(void);
extern void RE_InThMdlT_008_TEV(void);
extern void RE_InThMdlT_005_TEV_Start(void);
extern void RE_InThMdlT_005_TEV(void);
extern void RE_InThMdlT_004_TEV(void);
extern void RE_InThMdlT_006_TEV_Start(void);
extern void RE_InThMdlT_006_TEV(void);
void InThMdlT_ASYNC1(int controlPortIdx);
void InThMdlT_ASYNC2(int controlPortIdx);
void InThMdlT_ASYNC3(int controlPortIdx);
void InThMdlT_ASYNC4(int controlPortIdx);
void InThMdlT_ASYNC5(int controlPortIdx);
void InThMdlT_ASYNC6(int controlPortIdx);
void InThMdlT_ASYNC7(int controlPortIdx);

#define InThMdlT_STOP_SEC_CODE
#include "InThMdlT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CARTO_16BIT" */
#define InThMdlT_START_SEC_CARTO_16BIT
#include "InThMdlT_MemMap.h"

extern CONST(SInt16, INTHMDLT_CARTO) InThM_rEngSpdCorDB_T[16];
extern CONST(SInt16, INTHMDLT_CARTO) InThM_rEngSpdCor_A[16];
extern CONST(SInt16, INTHMDLT_CARTO) InThM_rEngSpdCor_M[16][16];
extern CONST(UInt16, INTHMDLT_CARTO) InThM_rtInMnf_A[16];
extern CONST(UInt16, INTHMDLT_CARTO) InThM_tInMnfRef_M[16][16];
extern CONST(UInt16, INTHMDLT_CARTO) InThM_tOfsCorUsEGRVlv_M[9][9];
extern CONST(UInt16, INTHMDLT_CARTO) InThM_tUsEGRVlv_T[9];

#define InThMdlT_STOP_SEC_CARTO_16BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define InThMdlT_START_SEC_CALIB_16BIT
#include "InThMdlT_MemMap.h"

extern CONST(UInt16, INTHMDLT_CALIB) Eng_rAirLdRef2_A[9];
extern CONST(UInt16, INTHMDLT_CALIB) InThM_nEngCor_B;
extern CONST(UInt16, INTHMDLT_CALIB) InThM_tAirUsInVlvEstim_B;
extern CONST(UInt16, INTHMDLT_CALIB) InThM_tCylEstimETB_C;
extern CONST(UInt16, INTHMDLT_CALIB) InThM_tEGRInMnf_B;
extern CONST(UInt16, INTHMDLT_CALIB) InThM_tInMnfEstim_B;
extern CONST(UInt16, INTHMDLT_CALIB) InThM_tMixtInMnf_B;
extern CONST(UInt16, INTHMDLT_CALIB) InThM_tWallInMnf_B;

#define InThMdlT_STOP_SEC_CALIB_16BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define InThMdlT_START_SEC_CALIB_BOOLEAN
#include "InThMdlT_MemMap.h"

extern CONST(Boolean, INTHMDLT_CALIB) INTHMDLT_ACTIVE_BYP_C;
extern CONST(Boolean, INTHMDLT_CALIB) InThM_bAcvETB_tCylEstim_C;
extern CONST(Boolean, INTHMDLT_CALIB) InThM_bAcvEngSpdCor_C;
extern CONST(Boolean, INTHMDLT_CALIB) InThM_bSelHtfClcMod_C;

#define InThMdlT_STOP_SEC_CALIB_BOOLEAN
#include "InThMdlT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define InThMdlT_START_SEC_CALIB_8BIT
#include "InThMdlT_MemMap.h"

extern CONST(UInt8, INTHMDLT_CALIB) InThM_facGainHeatFil_tEGR_C;
extern CONST(UInt8, INTHMDLT_CALIB) InThM_facHeatExcWallInMnf_B;
extern CONST(UInt8, INTHMDLT_CALIB) InThM_tSqrtEgUsEGRVlv_B;

#define InThMdlT_STOP_SEC_CALIB_8BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define InThMdlT_START_SEC_CARTO_8BIT
#include "InThMdlT_MemMap.h"

extern CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatExcWallInMnfPipe_M[16][16];
extern CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatExcWallInMnfPipe_T[9];
extern CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatExcWallInMnf_T[9];
extern CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatExgWallEGRPipe_T[9];
extern CONST(UInt8, INTHMDLT_CARTO) InThM_facHeatFil_tWallInMnf_M[9];

#define InThMdlT_STOP_SEC_CARTO_8BIT
#include "InThMdlT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define InThMdlT_START_SEC_INTERNAL_VAR_32BIT
#include "InThMdlT_MemMap.h"

extern VAR(Float32, INTHMDLT_INTERNAL_VAR) InThM_tEGRUsEGRVlvPrev;
extern VAR(Float32, INTHMDLT_INTERNAL_VAR) InThM_tEgRawUsEGRVlv;

#define InThMdlT_STOP_SEC_INTERNAL_VAR_32BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define InThMdlT_START_SEC_INTERNAL_VAR_16BIT
#include "InThMdlT_MemMap.h"

extern VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_facHeatFil_tWallInMnf_MP;
extern VAR(SInt16, INTHMDLT_INTERNAL_VAR) InThM_nDeltaEngSpd_MP;
extern VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_nEngCorWoutDiag;
extern VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_nEng_MP;
extern VAR(SInt16, INTHMDLT_INTERNAL_VAR) InThM_rEngSpdCorDB_MP;
extern VAR(SInt16, INTHMDLT_INTERNAL_VAR) InThM_rEngSpdCor_MP;
extern VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_rtInMnf_MP;
extern VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_tAirUsInVlvEstimRaw;
extern VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_tEGRUsEGRVlv_IRV_MP;
extern VAR(UInt16, INTHMDLT_INTERNAL_VAR) InThM_tWallInCylHead_IRV_MP;

#define InThMdlT_STOP_SEC_INTERNAL_VAR_16BIT
#include "InThMdlT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define InThMdlT_START_SEC_INTERNAL_VAR_8BIT
#include "InThMdlT_MemMap.h"

extern VAR(UInt8, INTHMDLT_INTERNAL_VAR) InThM_facHeatExcWallEGRPipe_MP;
extern VAR(UInt8, INTHMDLT_INTERNAL_VAR) InThM_facHeatExcWallInPipe_MP;
extern VAR(UInt8, INTHMDLT_INTERNAL_VAR) InThM_facNormHeat_tWallInMnf_MP;

#define InThMdlT_STOP_SEC_INTERNAL_VAR_8BIT
#include "InThMdlT_MemMap.h"
#endif                                 /* RTW_HEADER_InThMdlT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
