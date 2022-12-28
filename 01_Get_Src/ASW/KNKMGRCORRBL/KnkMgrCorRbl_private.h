/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : KnkMgrCorRbl                                            */
/* !Description     : CORRECTION RUMBLE                                       */
/*                                                                            */
/* !Module          : KnkMgrCorRbl                                            */
/*                                                                            */
/* !File            : KnkMgrCorRbl_private.h                                  */
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
/*   Code generated on: Mon Mar 03 16:32:53 2014                              */
/*   Model name       : KnkMgrCorRbl_AUTOCODE.mdl                             */
/*   Model version    : 1.302                                                 */
/*   Root subsystem   : /KnkMgrCorRbl                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKMGRCORRBL/KnkM$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   mbenfrad                               $$Date::   04 Mar 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_KnkMgrCorRbl_private_h_
#define RTW_HEADER_KnkMgrCorRbl_private_h_
#include "Std_Types.h"
#include "KnkMgrCorRbl_types.h"
#include "KnkMgrCorRbl_import.h"
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
#define KNKMGRCORRBL_START_SEC_CODE
#include "KnkMgrCorRbl_MemMap.h"

extern UInt32 div_repeat_u32(UInt32 localnumerator, UInt32
  localdenominator, UInt32 localnRepeatSub);
extern UInt8 plook_u8u16u32n31_binca_f(UInt16 localu, const UInt16
  localbp[], UInt32 localmaxIndex, UInt32 *localfraction);
extern UInt8 binsearch_u8u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern void KnkMgrCorRbl_F06_Previous(void);
extern void KnkMgrCorRb_F01_BenchMode_Start(void);
extern void KnkMgrCorRbl_F01_BenchMode(void);
extern void KnkMgrCorRbl_IfActionSubsystem(Boolean rtu_0, Boolean *rty_Out1);
extern void KnkMgrCorRbl_IfActionSubsystem1(Boolean rtu_0, Boolean *rty_Out1);
extern void KnkMgrCorRbl_F02_RblCount(void);
extern void KnkMgrCorRbl_F03_RblCorr(void);
extern void KnkMgrCorRbl_F05_Interface(void);
extern void KnkTreat_EveRbl_KnkMgrCorRbl_Start(void);
extern void KnkTreat_EveRbl_KnkMgrCorRbl(void);
extern void KnkMgrCorRbl_F01_Init(void);
extern void KnkMgrCorRbl_F01_InitBis(void);
extern void KnkTreat_EveRst_KnkMgrCorRbl_Start(void);
extern void KnkTreat_EveRst_KnkMgrCorRbl(void);
void KnkMgrCorRbl_ASYNC1(int controlPortIdx);

#define KNKMGRCORRBL_STOP_SEC_CODE
#include "KnkMgrCorRbl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define KNKMGRCORRBL_START_SEC_CALIB_8BIT
#include "KnkMgrCorRbl_MemMap.h"

extern CONST(UInt8, KNKMGRCORRBL_CALIB) KNKMGRCORRBL_u8Inhib;

#define KNKMGRCORRBL_STOP_SEC_CALIB_8BIT
#include "KnkMgrCorRbl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define KNKMGRCORRBL_START_SEC_VAR_16BIT
#include "KnkMgrCorRbl_MemMap.h"

extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctInjCutOffRbl_prev[4];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl1_prev[9];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl2_prev[9];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl3_prev[9];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl4_prev[9];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl1_prev[9];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl2_prev[9];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl3_prev[9];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl4_prev[9];
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctTotRbl_prev[4];
extern VAR(SInt16, KNKMGRCORRBL_VAR) KnkMgt_tqGlblTqRawSpThd;

#define KNKMGRCORRBL_STOP_SEC_VAR_16BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define KNKMGRCORRBL_START_SEC_VAR_8BIT
#include "KnkMgrCorRbl_MemMap.h"

extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl1;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl1Prev;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl2;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl2Prev;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl3;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl3Prev;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl4;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctIdxETBCyl4Prev;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctPerdRblCyl_prev;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctPerdRbl_prev[4];
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTDCInjCutOffCyl_prev;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTDCInjCutOff_prev[4];
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTotNbCycDecRbl[4];
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_ctTotNbCycDecRbl_prev[4];
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxETBCyl1;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxETBCyl2;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxETBCyl3;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxETBCyl4;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_idxMinPosnRbl_prev[4];
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_nbNEngZoneRbl;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_nbRLdZoneRbl;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCurCyl;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCyl1;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCyl2;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCyl3;
extern VAR(UInt8, KNKMGRCORRBL_VAR) KnkMgt_stRblCyl4;
extern VAR(UInt8, KNKMGRCORRBL_VAR) Knk_rbl_index_cyl;

#define KNKMGRCORRBL_STOP_SEC_VAR_8BIT
#include "KnkMgrCorRbl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define KNKMGRCORRBL_START_SEC_VAR_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"

extern VAR(Boolean, KNKMGRCORRBL_VAR) Detection_cliquetis_CurCyl;
extern VAR(Boolean, KNKMGRCORRBL_VAR) Detection_fort_cliq_CurCyl;
extern VAR(Boolean, KNKMGRCORRBL_VAR) Detection_fort_cliquetis_Cfm[4];
extern VAR(Boolean, KNKMGRCORRBL_VAR) Detection_fort_cliquetis_bench[4];
extern VAR(Boolean, KNKMGRCORRBL_VAR) Detection_rbl_Cfm[4];
extern VAR(Boolean, KNKMGRCORRBL_VAR) Detection_rbl_CurCyl;
extern VAR(Boolean, KNKMGRCORRBL_VAR) Detection_rbl_bench[4];
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bDgoORng_RblIrvLdLim;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bDgoORng_RblTmpLdLim;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bDgoORng_RblVlvPosn;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bInjCutOffCylReq;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bInjCutOffRblCurCyl;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bKnkRblDetnCyl;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bMonRunORng_RblIrvLdLim;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bMonRunORng_RblTmpLdLim;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bMonRunORng_RblVlvPosn;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bRblAcvWin3;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bRblDetnCyl;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_bRblInhWin;
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkMgt_prm_bInjCutOffRblCyl_prev[4];
extern VAR(Boolean, KNKMGRCORRBL_VAR) KnkRbl_bNEngHiSuperKnk;

#define KNKMGRCORRBL_STOP_SEC_VAR_BOOLEAN
#include "KnkMgrCorRbl_MemMap.h"
#endif                                 /* RTW_HEADER_KnkMgrCorRbl_private_h_ */

/*-------------------------------- end of file -------------------------------*/
