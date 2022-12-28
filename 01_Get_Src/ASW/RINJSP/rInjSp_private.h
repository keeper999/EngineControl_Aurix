/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : rInjSp                                                  */
/* !Description     : V01NT1006234.001                                        */
/*                                                                            */
/* !Module          : rInjSp                                                  */
/*                                                                            */
/* !File            : rInjSp_private.h                                        */
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
/*   Code generated on: Sun Jan 13 20:30:13 2013                              */
/*   Model name       : rInjSp_AUTOCODE.mdl                                   */
/*   Model version    : 1.181                                                 */
/*   Root subsystem   : /rInjSp                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/RINJSP/rInjSp_private.h_v $*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Feb 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_rInjSp_private_h_
#define RTW_HEADER_rInjSp_private_h_
#include "Std_Types.h"
#include "rInjSp_types.h"
#include "rInjSp_import.h"
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
#define RINJSP_START_SEC_CODE
#include "rInjSp_MemMap.h"

extern void rInjSp_F01_Initialisation(void);
extern void InjSys_EveRst_rInjSp(void);
extern void rInjSp_F02_rInjSp(void);
extern void InjSys_SdlFast_rInjSp(void);
void rInjSp_ASYNC1(int controlPortIdx);

#define RINJSP_STOP_SEC_CODE
#include "rInjSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define RINJSP_START_SEC_CALIB_8BIT
#include "rInjSp_MemMap.h"

extern CONST(UInt8, RINJSP_CALIB) RINJSP_u8Inhib;

#define RINJSP_STOP_SEC_CALIB_8BIT
#include "rInjSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define RINJSP_START_SEC_VAR_32BIT
#include "rInjSp_MemMap.h"

extern VAR(Float32, RINJSP_VAR) InjSys_rInj21Tmp_MP;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj2SpBas1ModCur;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj2SpBas1ModTar;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj2SpBas2ModCur;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj2SpBas2ModTar;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj2SpETBTmp_MP;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj2SpModCur_MP;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj2SpModTar_MP;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj2Tmp;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj31Tmp_MP;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj3SpBas1ModCur;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj3SpBas1ModTar;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj3SpBas2ModCur;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj3SpBas2ModTar;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj3SpModCur_MP;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj3SpModTar_MP;
extern VAR(Float32, RINJSP_VAR) InjSys_rInj3Tmp;

#define RINJSP_STOP_SEC_VAR_32BIT
#include "rInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define RINJSP_START_SEC_VAR_16BIT
#include "rInjSp_MemMap.h"

extern VAR(UInt16, RINJSP_VAR) InjSys_prm_rInj2SpCal[13];
extern VAR(UInt16, RINJSP_VAR) InjSys_prm_rInj3SpCal[13];
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj1TmpSat;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal1;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal10;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal11;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal12;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal13;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal2;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal3;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal4;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal5;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal6;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal7;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal8;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2SpCal9;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj2TmpSat;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal1;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal10;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal11;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal12;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal13;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal2;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal3;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal4;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal5;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal6;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal7;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal8;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3SpCal9;
extern VAR(UInt16, RINJSP_VAR) InjSys_rInj3TmpSat;

#define RINJSP_STOP_SEC_VAR_16BIT
#include "rInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define RINJSP_START_SEC_VAR_8BIT
#include "rInjSp_MemMap.h"

extern VAR(UInt8, RINJSP_VAR) InjSys_facInjRemain;
extern VAR(UInt8, RINJSP_VAR) InjSys_noInjPatTmp1_MP;
extern VAR(UInt8, RINJSP_VAR) InjSys_noInjPatTmp2_MP;

#define RINJSP_STOP_SEC_VAR_8BIT
#include "rInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define RINJSP_START_SEC_VAR_BOOLEAN
#include "rInjSp_MemMap.h"

extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj21_MP;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal1;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal10;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal11;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal12;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal13;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal2;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal3;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal4;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal5;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal6;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal7;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal8;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj2SpCal9;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj31_MP;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal1;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal10;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal11;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal12;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal13;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal2;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal3;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal4;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal5;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal6;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal7;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal8;
extern VAR(Boolean, RINJSP_VAR) InjSys_bAcvRatInj3SpCal9;
extern VAR(Boolean, RINJSP_VAR) InjSys_bInj1Acv;
extern VAR(Boolean, RINJSP_VAR) InjSys_bTestInjPat2_MP;
extern VAR(Boolean, RINJSP_VAR) InjSys_prm_bAcvRatInj2SpCal[13];
extern VAR(Boolean, RINJSP_VAR) InjSys_prm_bAcvRatInj3SpCal[13];

#define RINJSP_STOP_SEC_VAR_BOOLEAN
#include "rInjSp_MemMap.h"
#endif                                 /* RTW_HEADER_rInjSp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
