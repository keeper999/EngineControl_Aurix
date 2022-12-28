/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : agInjSp                                                 */
/* !Description     : agInjSp : INJECTION ANGLE SETPOINTS                     */
/*                                                                            */
/* !Module          : agInjSp                                                 */
/*                                                                            */
/* !File            : agInjSp_private.h                                       */
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
/*   Code generated on: Wed Nov 16 18:31:21 2011                              */
/*   Model name       : agInjSp_AUTOCODE.mdl                                  */
/*   Model version    : 1.142                                                 */
/*   Root subsystem   : /agInjSp                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/AGINJSP/agInjSp_private.h_$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   05 Dec 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_agInjSp_private_h_
#define RTW_HEADER_agInjSp_private_h_
#include "Std_Types.h"
#include "agInjSp_types.h"
#include "agInjSp_import.h"
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
#define AGINJSP_START_SEC_CODE
#include "agInjSp_MemMap.h"

extern void InjSys_EveRst_agInjSp_Start(void);
extern void InjSys_EveRst_agInjSp(void);
extern void InjSys_SdlFast_agInjSp_Start(void);
extern void InjSys_SdlFast_agInjSp(void);
void agInjSp_ASYNC1(int controlPortIdx);

#define AGINJSP_STOP_SEC_CODE
#include "agInjSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define AGINJSP_START_SEC_VAR_32BIT
#include "agInjSp_MemMap.h"

extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpBas1ModCur;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpBas1ModTar;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpBas2ModCur;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpBas2ModTar;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal1;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal10;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal11;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal12;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal13;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal14;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal15;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal2;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal3;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal4;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal5;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal6;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal7;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal8;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpCal9;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpModCur_MP;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj1SpModTar_MP;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpBas1ModCur;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpBas1ModTar;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpBas2ModCur;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpBas2ModTar;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal1;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal10;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal11;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal12;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal13;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal14;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal15;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal2;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal3;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal4;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal5;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal6;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal7;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal8;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpCal9;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpModCur_MP;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj2SpModTar_MP;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpBas1ModCur;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpBas1ModTar;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpBas2ModCur;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpBas2ModTar;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal1;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal10;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal11;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal12;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal13;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal14;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal15;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal2;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal3;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal4;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal5;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal6;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal7;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal8;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpCal9;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpModCur_MP;
extern VAR(Float, AGINJSP_VAR) InjSys_agInj3SpModTar_MP;
extern VAR(Float, AGINJSP_VAR) InjSys_prm_agInj1SpCal[15];
extern VAR(Float, AGINJSP_VAR) InjSys_prm_agInj2SpCal[15];
extern VAR(Float, AGINJSP_VAR) InjSys_prm_agInj3SpCal[15];

#define AGINJSP_STOP_SEC_VAR_32BIT
#include "agInjSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define AGINJSP_START_SEC_VAR_BOOLEAN
#include "agInjSp_MemMap.h"

extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal1;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal10;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal11;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal12;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal13;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal14;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal15;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal2;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal3;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal4;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal5;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal6;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal7;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal8;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj1SpCal9;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal1;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal10;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal11;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal12;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal13;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal14;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal15;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal2;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal3;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal4;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal5;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal6;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal7;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal8;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj2SpCal9;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal1;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal10;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal11;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal12;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal13;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal14;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal15;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal2;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal3;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal4;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal5;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal6;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal7;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal8;
extern VAR(Boolean, AGINJSP_VAR) InjSys_bAcvAgInj3SpCal9;
extern VAR(Boolean, AGINJSP_VAR) InjSys_prm_bAcvAgInj1SpCal[15];
extern VAR(Boolean, AGINJSP_VAR) InjSys_prm_bAcvAgInj2SpCal[15];
extern VAR(Boolean, AGINJSP_VAR) InjSys_prm_bAcvAgInj3SpCal[15];

#define AGINJSP_STOP_SEC_VAR_BOOLEAN
#include "agInjSp_MemMap.h"
#endif                                 /* RTW_HEADER_agInjSp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
