/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSysMgrCrk                                            */
/* !Description     : InjSysMgrCrk : Start manager                            */
/*                                                                            */
/* !Module          : InjSysMgrCrk                                            */
/*                                                                            */
/* !File            : InjSysMgrCrk_private.h                                  */
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
/*   Code generated on: Wed May 01 18:07:07 2013                              */
/*   Model name       : InjSysMgrCrk_AUTOCODE.mdl                             */
/*   Model version    : 1.204                                                 */
/*   Root subsystem   : /InjSysMgrCrk                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJSYSMGRCRK/InjSysMgrCrk_$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   14 May 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjSysMgrCrk_private_h_
#define RTW_HEADER_InjSysMgrCrk_private_h_
#include "Std_Types.h"
#include "InjSysMgrCrk_types.h"
#include "InjSysMgrCrk_import.h"
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
#define INJSYSMGRCRK_START_SEC_CODE
#include "InjSysMgrCrk_MemMap.h"

extern void InjSysMgrC_F02_Inj_StrtHP_Start(void);
extern void InjSysMgrCrk_F02_Inj_StrtHP(void);
extern void InjSysMgrCrk_F03_InhInjSyncNtAc(void);
extern void InjSys_EveCkSnNtAc_InjSysMgrCrk_Start(void);
extern void InjSys_EveCkSnNtAc_InjSysMgrCrk(void);
extern void InjSys_EveCkSnNtAc_InjSysMgrCrk(void);
extern void InjSys_EveInj_InjSysMgrCrk(void);
extern void Inj_F01_StallToRot_StrtHP_Start(rtB_F01_StallToRot_StrtHP_InjSy
  *localB);
extern void InjSysMgr_F01_StallToRot_StrtHP(SInt16 rtu_Ext_tCoMes, Boolean
  rtu_CoEs_bIntrSTTEsLoEngSpd, Boolean rtu_CoPTSt_bRStrtSTT, UInt16
  rtu_FuSysM_tFu, Boolean rtu_FRM_bInhPfuCtl, Boolean rtu_FRM_bInhStrtHP,
  UInt8 rtu_Eng_stEru, Boolean rtu_Ext_bFrstCrk, Boolean
  rtu_Ext_bEngReStrt, UInt16 rtu_Ext_pFuRailSplMes, Boolean
  *rty_InjSys_bAuthHPst, rtB_F01_StallToRot_StrtHP_InjSy *localB);
extern void I_F01_StallToRot_StrtHP_l_Start(void);
extern void InjSysM_F01_StallToRot_StrtHP_c(void);
extern void InjSys_EveRTSt_InjSysMgrCrk(void);
extern void InjSys_EveRTSt_InjSysMgrCrk(void);
extern void F01_StallToRot_StrtHP_ini_Start(void);
extern void InjS_F01_StallToRot_StrtHP_init(void);
extern void InjSys_EveRst_InjSysMgrCrk_Start(void);
extern void InjSys_EveRst_InjSysMgrCrk(void);
extern void InjSys_EveStTR_InjSysMgrCrk_Start(void);
extern void InjSys_EveStTR_InjSysMgrCrk(void);
void InjSysMgrCrk_ASYNC1(int controlPortIdx);
void InjSysMgrCrk_ASYNC2(int controlPortIdx);
void InjSysMgrCrk_ASYNC3(int controlPortIdx);
void InjSysMgrCrk_ASYNC7(int controlPortIdx);

#define INJSYSMGRCRK_STOP_SEC_CODE
#include "InjSysMgrCrk_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJSYSMGRCRK_START_SEC_CALIB_8BIT
#include "InjSysMgrCrk_MemMap.h"

extern CONST(UInt8, INJSYSMGRCRK_CALIB) INJSYSMGRCRK_u8Inhib;

#define INJSYSMGRCRK_STOP_SEC_CALIB_8BIT
#include "InjSysMgrCrk_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define INJSYSMGRCRK_START_SEC_VAR_8BIT
#include "InjSysMgrCrk_MemMap.h"

extern VAR(UInt8, INJSYSMGRCRK_VAR) InjSys_ctTDCThdAcvInjHPPrev;

#define INJSYSMGRCRK_STOP_SEC_VAR_8BIT
#include "InjSysMgrCrk_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJSYSMGRCRK_START_SEC_VAR_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"

extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModHprev;
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModSplstPrev;
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAcvInjModSstPrev;
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAgStopNoInhHP;
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bAuthHPst;
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bDetPFuThdInjHPstPrev;
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_bDisaHPst;
extern VAR(Boolean, INJSYSMGRCRK_VAR) InjSys_prm_bInhInjHPCylPrev[6];

#define INJSYSMGRCRK_STOP_SEC_VAR_BOOLEAN
#include "InjSysMgrCrk_MemMap.h"
#endif                                 /* RTW_HEADER_InjSysMgrCrk_private_h_ */

/*-------------------------------- end of file -------------------------------*/
