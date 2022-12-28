/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjCutOffMgr                                            */
/* !Description     : GESTION DE LA COUPURE DES INJECTEURS                    */
/*                                                                            */
/* !Module          : InjCutOffMgr                                            */
/*                                                                            */
/* !File            : InjCutOffMgr_private.h                                  */
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
/*   Code generated on: Mon Mar 25 22:22:41 2013                              */
/*   Model name       : InjCutOffMgr_AUTOCODE.mdl                             */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /InjCutOffMgr                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJCUTOFFMGR/InjCutOffMgr_$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   27 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjCutOffMgr_private_h_
#define RTW_HEADER_InjCutOffMgr_private_h_
#include "Std_Types.h"
#include "InjCutOffMgr_types.h"
#include "InjCutOffMgr_import.h"
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
#define INJCUTOFFMGR_START_SEC_CODE
#include "InjCutOffMgr_MemMap.h"


extern void InjC__Gestion_coupure_injection(void);
extern void InjCutOff_EveInj_CutOff(void);
extern void InjCutOff_EveInj_CutOff(void);
extern void InjCutOffMgr__Initialisation(void);
extern void InjCutOff_EveRst_CutOff(void);
extern void InjCutOff_SdlFast_CutOff(void);
extern void InjCutOffMg__InjCutOffMgrDftMod(void);
extern void InjCutOff_EveStTCr_CutOff(void);
void InjCutOffMgr_ASYNC1(int controlPortIdx);
void InjCutOffMgr_ASYNC2(int controlPortIdx);
void InjCutOffMgr_ASYNC4(int controlPortIdx);

#define INJCUTOFFMGR_STOP_SEC_CODE
#include "InjCutOffMgr_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJCUTOFFMGR_START_SEC_CALIB_8BIT
#include "InjCutOffMgr_MemMap.h"

extern CONST(UInt8, INJCUTOFFMGR_CALIB) INJCUTOFFMGR_u8Inhib;

#define INJCUTOFFMGR_STOP_SEC_CALIB_8BIT
#include "InjCutOffMgr_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define INJCUTOFFMGR_START_SEC_VAR_8BIT
#include "InjCutOffMgr_MemMap.h"

extern VAR(SInt8, INJCUTOFFMGR_VAR) InjSys_noCylCutOffTarSub;
extern VAR(UInt8, INJCUTOFFMGR_VAR) InjSys_noInNxtNxtNxtCyl;

#define INJCUTOFFMGR_STOP_SEC_VAR_8BIT
#include "InjCutOffMgr_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJCUTOFFMGR_START_SEC_VAR_BOOLEAN
#include "InjCutOffMgr_MemMap.h"

extern VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj_cyl1;
extern VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj_cyl2;
extern VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj_cyl3;
extern VAR(Boolean, INJCUTOFFMGR_VAR) Coupure_decel_progr_inj_cyl4;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bAcvCutOffTyp1;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bAcvCutOff_MP;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bCutOffCyl1Raw;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bCutOffCyl2Raw;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bCutOffCyl3Raw;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bCutOffCyl4Raw;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bForcFuCutOff;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bInhCutOffTar;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bInjCutOffRaw;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_bTotCutOffDftMod;
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_prm_bAcvCutOffTarCyl[4];
extern VAR(Boolean, INJCUTOFFMGR_VAR) InjSys_prm_bAcvCutOffTarCylPrev[4];

#define INJCUTOFFMGR_STOP_SEC_VAR_BOOLEAN
#include "InjCutOffMgr_MemMap.h"
#endif                                 /* RTW_HEADER_InjCutOffMgr_private_h_ */

/*-------------------------------- end of file -------------------------------*/
