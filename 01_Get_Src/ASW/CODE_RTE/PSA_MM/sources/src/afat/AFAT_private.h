/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAT                                                    */
/* !Description     : AFAT Software component                                 */
/*                                                                            */
/* !Module          : AFAT                                                    */
/* !Description     : Private declarations                                    */
/*                                                                            */
/* !File            : AFAT_private.h                                          */
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
/*   Model name       : AFAT_SWC.mdl                                          */
/*   Root subsystem   : /AFAT                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFAT_private_h_
#define RTW_HEADER_AFAT_private_h_
#include "Std_Types.h"
#include "AFAT_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CALL_EVENT                     (-1)
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

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void RE_AFAT_001_MSE_Start(void);
extern void RE_AFAT_001_MSE(void);
extern void Diag_Vect2Mat(const UInt16 rtu_u[8], UInt16 rty_y[64]);
extern void F01_lire_adaptatifs_en_eeprom_0(SInt32 controlPortIdx);
extern void RE_AFAT_002_MSE_Start(void);
extern void RE_AFAT_002_MSE(void);
extern void RE_AFAT_003_MSE_Start(void);
extern void RE_AFAT_003_MSE(void);
extern void RE_AFAT_004_TEV_Start(void);
extern void RE_AFAT_004_TEV(void);
extern void RE_AFAT_005_TEV_Start(void);
extern void RE_AFAT_005_TEV(void);
extern void RE_AFAT_007_TEV_Start(void);
extern void RE_AFAT_007_TEV(void);
extern void RE_AFAT_006_TEV_Start(void);
extern void RE_AFAT_006_TEV(void);
void AFAT_ASYNC1(int controlPortIdx);
void AFAT_ASYNC2(int controlPortIdx);
void AFAT_ASYNC3(int controlPortIdx);
void AFAT_ASYNC4(int controlPortIdx);
void AFAT_ASYNC5(int controlPortIdx);
void AFAT_ASYNC6(int controlPortIdx);
void AFAT_ASYNC7(int controlPortIdx);
void AFAT_ASYNC8(int controlPortIdx);

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AFAT_START_SEC_CALIB_BOOLEAN
#include "AFAT_MemMap.h"

extern CONST(Boolean, AFAT_CALIB) AFAT_ACTIVE_BYP_C;

#define AFAT_STOP_SEC_CALIB_BOOLEAN
#include "AFAT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#endif                                 /* RTW_HEADER_AFAT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
