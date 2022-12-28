/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : FuSysExtLeakDiag                                        */
/* !Description     : Functional diagnosis of external leak on Fuel System    */
/*                                                                            */
/* !Module          : FuSysExtLeakDiag                                        */
/*                                                                            */
/* !File            : FuSysExtLeakDiag_private.h                              */
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
/*   Code generated on: Tue Jun 18 17:18:14 2013                              */
/*   Model name       : FuSysExtLeakDiag_AUTOCODE.mdl                         */
/*   Model version    : 1.278                                                 */
/*   Root subsystem   : /FuSysExtLeakDiag                                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FUSYSEXTLEAKDIAG/FuSysExtLeak$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Jun 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_FuSysExtLeakDiag_private_h_
#define RTW_HEADER_FuSysExtLeakDiag_private_h_
#include "Std_Types.h"
#include "FuSysExtLeakDiag_types.h"
#include "FuSysExtLeakDiag_import.h"
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
#define FUSYSEXTLEAKDIAG_START_SEC_CODE
#include "FuSysExtLeakDiag_MemMap.h"

extern void FuSysExt_u_FuSysExtLeakDiagInit(void);
extern void Fu_EveRst_ExtLeakDiag(void);
extern void FuSysExt_u_DlyAcvDiagRun_Update(void);
extern void FuSysExtLeakDia_u_DlyAcvDiagRun(void);
extern void FuSysExtLeakDi_u_SavePFuRailRun(void);
extern void FuSysExtLeakDiag_u_IfGARRun(void);
extern void u_FuSysExtLeakEngRunDiag_Update(void);
extern void FuSysE_u_FuSysExtLeakEngRunDiag(void);
extern void FuSysE_u_DlyAcvDiagStall_Update(void);
extern void FuSysExtLeakD_u_DlyAcvDiagStall(void);
extern void FuSysExtLeak_u_SavePFuRailStall(void);
extern void FuSysExtLeakDiag_u_IfGARStall(void);
extern void u_FuSysExtLeakEngStallDi_Update(void);
extern void FuSy_u_FuSysExtLeakEngStallDiag(void);
extern void FuSysExtLeakDi_u_FuSysStabPrail(void);
extern void FuSys_u_FuSysExtLeakDiag_Update(void);
extern void FuSysExtLeak_u_FuSysExtLeakDiag(void);
extern void FuSysExtLe_u_FuSysExtLeakDiag_l(void);
extern void Fu_SdlMid_ExtLeakDiag_Start(void);
extern void Fu_SdlMid_ExtLeakDiag(void);

#define FUSYSEXTLEAKDIAG_STOP_SEC_CODE
#include "FuSysExtLeakDiag_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_CALIB_8BIT
#include "FuSysExtLeakDiag_MemMap.h"

extern CONST(UInt8, FUSYSEXTLEAKDIAG_CALIB) FUSYSEXTLEAKDIAG_u8Inhib;

#define FUSYSEXTLEAKDIAG_STOP_SEC_CALIB_8BIT
#include "FuSysExtLeakDiag_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_VAR_32BIT
#include "FuSysExtLeakDiag_MemMap.h"

extern VAR(UInt32, FUSYSEXTLEAKDIAG_VAR) Fu_tiTransPFuReqDly;

#define FUSYSEXTLEAKDIAG_STOP_SEC_VAR_32BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define FUSYSEXTLEAKDIAG_START_SEC_VAR_16BIT
#include "FuSysExtLeakDiag_MemMap.h"

extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuRailExtLeakEngRunMem;
extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuRailExtLeakEngStallMem;
extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuRailGrdExtLeakEngRun;
extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuRailGrdExtLeakEngStall;
extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_pFuReqDiff;
extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_tiPFuRailExtLeakEngRunDly;
extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_tiPFuRailExtLeakEngRunDlyIn;
extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_tiPFuRailExtLeakEngStallDly;
extern VAR(UInt16, FUSYSEXTLEAKDIAG_VAR) Fu_tiPFuRailExtLeakEngStallDlyIn;

#define FUSYSEXTLEAKDIAG_STOP_SEC_VAR_16BIT
#include "FuSysExtLeakDiag_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define FUSYSEXTLEAKDIAG_START_SEC_VAR_BOOLEAN
#include "FuSysExtLeakDiag_MemMap.h"

extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bActrTstInjr;
extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bAcvExtLeakEngRunDiag;
extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bAcvExtLeakEngStallDiag;
extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bDgoExtLeak_FuSys;
extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bMonRunExtLeak_FuSys;
extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bStabMFuReq;
extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bStabPFuReq;
extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bStrtDiagExtLeakEngRun;
extern VAR(Boolean, FUSYSEXTLEAKDIAG_VAR) Fu_bStrtDiagExtLeakEngStall;

#define FUSYSEXTLEAKDIAG_STOP_SEC_VAR_BOOLEAN
#include "FuSysExtLeakDiag_MemMap.h"
#endif                                 /* RTW_HEADER_FuSysExtLeakDiag_private_h_ */

/*-------------------------------- end of file -------------------------------*/
