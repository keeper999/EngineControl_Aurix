/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : agPmpRefPFuM                                            */
/* !Description     : CALCULATION OF THE ANGULAR REFERENCES FOR THE PUMP STRIKES (GDI)*/
/*                                                                            */
/* !Module          : agPmpRefPFuM                                            */
/*                                                                            */
/* !File            : agPmpRefPFuM_private.h                                  */
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
/*   Code generated on: Thu Sep 12 10:58:54 2013                              */
/*   Model name       : agPmpRefPFuM_AUTOCODE.mdl                             */
/*   Model version    : 1.77                                                  */
/*   Root subsystem   : /agPmpRefPFuM                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/agPmpRefPFuM/5-SOFT-LIV/agPm$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Sep 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_agPmpRefPFuM_private_h_
#define RTW_HEADER_agPmpRefPFuM_private_h_
#include "Std_Types.h"
#include "agPmpRefPFuM_types.h"
#include "agPmpRefPFuM_import.h"
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
#define AGPMPREFPFUM_START_SEC_CODE
#include "agPmpRefPFuM_MemMap.h"

extern void agPmpRef_F01_agPmpStkRef_EveInj(void);
extern void FuSysM_EveCkSnOn_agPmpRefPFuM(void);
extern void FuSysM_EveCkSnOn_agPmpRefPFuM(void);
extern void FuSysM_EveInj_agPmpRefPFuM(void);
extern void agPmpRefPFu_F02_agPmpStkRef_Spl(void);
extern void FuSysM_EveSpl_agPmpRefPFuM(void);
void agPmpRefPFuM_ASYNC1(int controlPortIdx);
void agPmpRefPFuM_ASYNC3(int controlPortIdx);

#define AGPMPREFPFUM_STOP_SEC_CODE
#include "agPmpRefPFuM_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define AGPMPREFPFUM_START_SEC_CALIB_8BIT
#include "agPmpRefPFuM_MemMap.h"

extern CONST(UInt8, AGPMPREFPFUM_CALIB) AGPMPREFPFUM_u8Inhib;

#define AGPMPREFPFUM_STOP_SEC_CALIB_8BIT
#include "agPmpRefPFuM_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define AGPMPREFPFUM_START_SEC_VAR_BOOLEAN
#include "agPmpRefPFuM_MemMap.h"

extern VAR(Boolean, AGPMPREFPFUM_VAR) FuSysM_bAcvPmpCmdTDCCur;

#define AGPMPREFPFUM_STOP_SEC_VAR_BOOLEAN
#include "agPmpRefPFuM_MemMap.h"
#endif                                 /* RTW_HEADER_agPmpRefPFuM_private_h_ */

/*-------------------------------- end of file -------------------------------*/
