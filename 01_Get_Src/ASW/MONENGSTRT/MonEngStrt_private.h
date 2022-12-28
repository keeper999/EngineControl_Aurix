/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : MonEngStrt                                              */
/* !Description     : Surveillance du démarrage                               */
/*                                                                            */
/* !Module          : MonEngStrt                                              */
/*                                                                            */
/* !File            : MonEngStrt_private.h                                    */
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
/*   Code generated on: Wed Sep 11 09:00:08 2013                              */
/*   Model name       : MonEngStrt_AUTOCODE.mdl                               */
/*   Model version    : 1.201                                                 */
/*   Root subsystem   : /MonEngStrt                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/MONENGSTRT/MonEngStrt_priv$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   16 Sep 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_MonEngStrt_private_h_
#define RTW_HEADER_MonEngStrt_private_h_
#include "Std_Types.h"
#include "MonEngStrt_types.h"
#include "MonEngStrt_import.h"
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
#define MONENGSTRT_START_SEC_CODE
#include "MonEngStrt_MemMap.h"

extern void MonEngStrt_F00_autorisationDiag(Boolean rtu_First_crank, Boolean
  rtu_EngSt_bCmdCranking, UInt16 rtu_IMMO_stEcuLockStTyp, Boolean
  rtu_Moteur_synchronise, UInt8 rtu_Vehicle_active_state, Boolean
  rtu_EngSt_bMonEngStrtEnd, Boolean rtu_Ctrl_bAcv_PFuAcq, Boolean
  rtu_InjSys_bDetPFuThdInjHPst, Boolean rtu_FRM_bInhMonEngStrt,
  rtB_F00_autorisationDiag_MonEng *localB, rtDW_F00_autorisationDiag_MonEn
  *localDW);
extern void MonEng_F02_autorisationDiag_Rst(void);
extern void MonEngStrt_F00_Init(void);
extern void EngSt_EveRst_MonEngStrt_Init(void);
extern void EngSt_EveRst_MonEngStrt_Start(void);
extern void EngSt_EveRst_MonEngStrt(void);
extern void MonEngStrt_F01_CmdCranking(void);
extern void MonEn_F02_autorisationDiag_Fast(void);
extern void MonEngStrt_F03_Diagnostic(void);
extern void EngSt_SdlFast_MonEngStrt_Start(void);
extern void EngSt_SdlFast_MonEngStrt(void);
void MonEngStrt_ASYNC1(int controlPortIdx);

#define MONENGSTRT_STOP_SEC_CODE
#include "MonEngStrt_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define MONENGSTRT_START_SEC_CALIB_8BIT
#include "MonEngStrt_MemMap.h"

extern CONST(UInt8, MONENGSTRT_CALIB) MONENGSTRT_u8Inhib;

#define MONENGSTRT_STOP_SEC_CALIB_8BIT
#include "MonEngStrt_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define MONENGSTRT_START_SEC_VAR_16BIT
#include "MonEngStrt_MemMap.h"

extern VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlyPFuMin;
extern VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlyStrt;
extern VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlyUnlockADC;
extern VAR(UInt16, MONENGSTRT_VAR) EngSt_uBattInit;

#define MONENGSTRT_STOP_SEC_VAR_16BIT
#include "MonEngStrt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define MONENGSTRT_START_SEC_VAR_BOOLEAN
#include "MonEngStrt_MemMap.h"

extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bAcvStrtDiag;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bCmdCranking;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bDgoORngPFuEngSt;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bDgoORngStrtEngSt;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bDgoORngSyncEngSt;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bDgoORngUnlockEngSt;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bFuLvlOK;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonEngStrtEnd;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonRunORngPFuEngSt;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonRunORngStrtEngSt;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonRunORngSyncEngSt;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonRunORngUnlockEngSt;
extern VAR(Boolean, MONENGSTRT_VAR) EngSt_bMonWaitORngEngSt;

#define MONENGSTRT_STOP_SEC_VAR_BOOLEAN
#include "MonEngStrt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define MONENGSTRT_START_SEC_VAR_8BIT
#include "MonEngStrt_MemMap.h"

extern VAR(UInt8, MONENGSTRT_VAR) EngSt_stMonEngStrt;
extern VAR(UInt8, MONENGSTRT_VAR) EngSt_volFuInit;

#define MONENGSTRT_STOP_SEC_VAR_8BIT
#include "MonEngStrt_MemMap.h"
#endif                                 /* RTW_HEADER_MonEngStrt_private_h_ */

/*-------------------------------- end of file -------------------------------*/
