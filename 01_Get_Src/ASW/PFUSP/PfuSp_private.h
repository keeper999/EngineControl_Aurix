/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pFuSp                                                   */
/* !Description     : pFuSp : Fuel Pressure Set Point                         */
/*                                                                            */
/* !Module          : pFuSp                                                   */
/*                                                                            */
/* !File            : pFuSp_private.h                                         */
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
/*   Code generated on: Thu Dec 20 19:22:07 2012                              */
/*   Model name       : pFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.341                                                 */
/*   Root subsystem   : /pFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PFUSP/pFuSp_private.h_v   $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_pFuSp_private_h_
#define RTW_HEADER_pFuSp_private_h_
#include "Std_Types.h"
#include "pFuSp_types.h"
#include "pFuSp_import.h"
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
#define PFUSP_START_SEC_CODE
#include "pFuSp_MemMap.h"

extern Float32 look1_iu16lfIf_binlcs(UInt16 localu0, const UInt16 localbp0[],
  const UInt16 localtable[], UInt32 localmaxIndex);
extern Float32 look1_iu8lftu16n13If_binlcns(UInt8 localu0, const UInt8
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern void pFuSp_F01_Initialization(void);
extern void InjSys_EveRst_pFuSp(void);
extern void pFuSp_F02_pFuSp_Start(void);
extern void pFuSp_F02_pFuSp(void);
extern void InjSys_EveSpl_pFuSp_Start(void);
extern void InjSys_EveSpl_pFuSp(void);
void pFuSp_ASYNC1(int controlPortIdx);

#define PFUSP_STOP_SEC_CODE
#include "pFuSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define PFUSP_START_SEC_CALIB_8BIT
#include "pFuSp_MemMap.h"

extern CONST(UInt8, PFUSP_CALIB) PFUSP_u8Inhib;

#define PFUSP_STOP_SEC_CALIB_8BIT
#include "pFuSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define PFUSP_START_SEC_VAR_32BIT
#include "pFuSp_MemMap.h"

extern VAR(Float32, PFUSP_VAR) InjSys_pFuSpBas1ModCur;
extern VAR(Float32, PFUSP_VAR) InjSys_pFuSpBas1ModTar;
extern VAR(Float32, PFUSP_VAR) InjSys_pFuSpBas2ModCur;
extern VAR(Float32, PFUSP_VAR) InjSys_pFuSpBas2ModTar;
extern VAR(Float32, PFUSP_VAR) InjSys_pFuSpModCur_MP;
extern VAR(Float32, PFUSP_VAR) InjSys_pFuSpModTar_MP;
extern VAR(Float32, PFUSP_VAR) InjSys_tiTDCPmp;
extern VAR(Float32, PFUSP_VAR) TqLimEM_tqLimEMPrec;

#define PFUSP_STOP_SEC_VAR_32BIT
#include "pFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define PFUSP_START_SEC_VAR_16BIT
#include "pFuSp_MemMap.h"

extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal1;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal10;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal11;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal12;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal13;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal14;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal15;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal2;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal3;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal4;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal5;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal6;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal7;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal8;
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSpCal9;
extern VAR(UInt16, PFUSP_VAR) InjSys_prm_pFuSpCal[15];

#define PFUSP_STOP_SEC_VAR_16BIT
#include "pFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define PFUSP_START_SEC_VAR_BOOLEAN
#include "pFuSp_MemMap.h"

extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvAirLdMinSatTmp;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal1;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal10;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal11;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal12;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal13;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal14;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal15;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal2;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal3;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal4;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal5;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal6;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal7;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal8;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvPfuSpCal9;
extern VAR(Boolean, PFUSP_VAR) InjSys_bAcvSpcInjModTmp;
extern VAR(Boolean, PFUSP_VAR) InjSys_bInhAirLdMinSat;
extern VAR(Boolean, PFUSP_VAR) InjSys_bInhInjCutOffTmp;
extern VAR(Boolean, PFUSP_VAR) InjSys_bInhSpcInjMod;
extern VAR(Boolean, PFUSP_VAR) InjSys_prm_bAcvPfuSpCal[15];

#define PFUSP_STOP_SEC_VAR_BOOLEAN
#include "pFuSp_MemMap.h"
#endif                                 /* RTW_HEADER_pFuSp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
