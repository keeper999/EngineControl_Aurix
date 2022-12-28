/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : OilTqCf                                                 */
/* !Description     : OIL TORQUE CONFIGURATION                                */
/*                                                                            */
/* !Module          : OilTqCf                                                 */
/*                                                                            */
/* !File            : OilTqCf_private.h                                       */
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
/*   Code generated on: Sun Oct 21 15:29:22 2012                              */
/*   Model name       : OilTqCf_AUTOCODE.mdl                                  */
/*   Model version    : 1.64                                                  */
/*   Root subsystem   : /OilTqCf                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/OILTQCF_CA/OilTqC$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   25 Oct 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_OilTqCf_private_h_
#define RTW_HEADER_OilTqCf_private_h_
#include "Std_Types.h"
#include "OilTqCf_types.h"
#include "OilTqCf_import.h"
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
#define OILTQCF_START_SEC_CODE
#include "OilTqCf_MemMap.h"

extern Float32 look2_iu16lftu16n4If_binlcns(UInt16 localu0, UInt16 localu1,
  const UInt16 localbp0[], const UInt16 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern void OilTqCf_F00_OilTqCf_Init(void);
extern void OilTqCf_EveRst_OilTqCf(void);
extern void OilTqCf_Mem(Boolean rtu_Hld, SInt16 rtu_In, rtB_Mem_OilTqCf
  *localB, rtDW_Mem_OilTqCf *localDW);
extern void OilTqCf_F0_OilTqCf_Start(void);
extern void OilTqCf_F0_OilTqCf(void);
extern void OilTqCf_Sdl20ms_OilTqCf_Start(void);
extern void OilTqCf_Sdl20ms_OilTqCf(void);
void OilTqCf_ASYNC1(int controlPortIdx);

#define OILTQCF_STOP_SEC_CODE
#include "OilTqCf_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define OILTQCF_START_SEC_CALIB_8BIT
#include "OilTqCf_MemMap.h"

extern CONST(UInt8, OILTQCF_CALIB) OILTQCF_u8Inhib;

#define OILTQCF_STOP_SEC_CALIB_8BIT
#include "OilTqCf_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define OILTQCF_START_SEC_VAR_32BIT
#include "OilTqCf_MemMap.h"

extern VAR(Float32, OILTQCF_VAR) OilTqCf_rLdHi_MP;
extern VAR(Float32, OILTQCF_VAR) OilTqCf_rLdLo_MP;
extern VAR(Float32, OILTQCF_VAR) OilTqCf_rLdNorm_MP;

#define OILTQCF_STOP_SEC_VAR_32BIT
#include "OilTqCf_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define OILTQCF_START_SEC_VAR_16BIT
#include "OilTqCf_MemMap.h"

extern VAR(SInt16, OILTQCF_VAR) OilTqCf_facDen_MP;
extern VAR(SInt16, OILTQCF_VAR) OilTqCf_facNum_MP;

#define OILTQCF_STOP_SEC_VAR_16BIT
#include "OilTqCf_MemMap.h"
#endif                                 /* RTW_HEADER_OilTqCf_private_h_ */

/*-------------------------------- end of file -------------------------------*/
