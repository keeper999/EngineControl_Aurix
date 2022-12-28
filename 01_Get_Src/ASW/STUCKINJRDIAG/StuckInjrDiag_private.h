/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : StuckInjrDiag                                           */
/* !Description     : Diagnosis of stuck injectors                            */
/*                                                                            */
/* !Module          : StuckInjrDiag                                           */
/*                                                                            */
/* !File            : StuckInjrDiag_private.h                                 */
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
/*   Code generated on: Sun Oct 20 10:36:43 2013                              */
/*   Model name       : StuckInjrDiag_AUTOCODE.mdl                            */
/*   Model version    : 1.223                                                 */
/*   Root subsystem   : /StuckInjrDiag                                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/STUCKINJRDIAG/StuckInjrDiag_p$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   28 Oct 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_StuckInjrDiag_private_h_
#define RTW_HEADER_StuckInjrDiag_private_h_
#include "Std_Types.h"
#include "StuckInjrDiag_types.h"
#include "StuckInjrDiag_import.h"
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

/* !Comment: Define code in section "SEC_CODE" */
#define STUCKINJRDIAG_START_SEC_CODE
#include "StuckInjrDiag_MemMap.h"

extern Float32 look2_iu16u16lftu16p9If_binlcs(UInt16 localu0, UInt16
  localu1, const UInt16 localbp0[], const UInt16 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern void StuckInjrDi_u_StuckOpenInjrDiag(void);
extern void Fu_SdlFast_StuckInjrDiag_Start(void);
extern void Fu_SdlFast_StuckInjrDiag(void);

#define STUCKINJRDIAG_STOP_SEC_CODE
#include "StuckInjrDiag_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define STUCKINJRDIAG_START_SEC_CALIB_8BIT
#include "StuckInjrDiag_MemMap.h"

extern CONST(UInt8, STUCKINJRDIAG_CALIB) STUCKINJRDIAG_u8Inhib;

#define STUCKINJRDIAG_STOP_SEC_CALIB_8BIT
#include "StuckInjrDiag_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define STUCKINJRDIAG_START_SEC_VAR_32BIT
#include "StuckInjrDiag_MemMap.h"

extern VAR(Float32, STUCKINJRDIAG_VAR) Fu_pFuReqGrdStckOpInjr_irv;

#define STUCKINJRDIAG_STOP_SEC_VAR_32BIT
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define STUCKINJRDIAG_START_SEC_VAR_16BIT
#include "StuckInjrDiag_MemMap.h"

extern VAR(SInt16, STUCKINJRDIAG_VAR) Fu_pFuRailDifStckOpInjrThd_MP;
extern VAR(UInt16, STUCKINJRDIAG_VAR) Fu_tiPFuRailStabDly;

#define STUCKINJRDIAG_STOP_SEC_VAR_16BIT
#include "StuckInjrDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define STUCKINJRDIAG_START_SEC_VAR_BOOLEAN
#include "StuckInjrDiag_MemMap.h"

extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bAcvDiagStuckInjr;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bDgoStuckOp_InjrCyl1;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bDgoStuckOp_InjrCyl2;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bDgoStuckOp_InjrCyl3;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bDgoStuckOp_InjrCyl4;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bFuRailStabStckInjr;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bMonRunStuckOp_InjrCyl1;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bMonRunStuckOp_InjrCyl2;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bMonRunStuckOp_InjrCyl3;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bMonRunStuckOp_InjrCyl4;
extern VAR(Boolean, STUCKINJRDIAG_VAR) Fu_bPFuRailStab;

#define STUCKINJRDIAG_STOP_SEC_VAR_BOOLEAN
#include "StuckInjrDiag_MemMap.h"
#endif                                 /* RTW_HEADER_StuckInjrDiag_private_h_ */

/*-------------------------------- end of file -------------------------------*/
