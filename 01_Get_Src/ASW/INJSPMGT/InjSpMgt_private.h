/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSpMgt                                                */
/* !Description     : INJECTION PARAMETERS MANAGER                            */
/*                                                                            */
/* !Module          : InjSpMgt                                                */
/*                                                                            */
/* !File            : InjSpMgt_private.h                                      */
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
/*   Code generated on: Thu Mar 07 15:35:56 2013                              */
/*   Model name       : InjSpMgt_AUTOCODE.mdl                                 */
/*   Model version    : 1.1004                                                */
/*   Root subsystem   : /InjSpMgt                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjSpMgt/5-SOFT-LIV/InjSpMgt$*/
/* $Revision::   1.12                                                        $*/
/* $Author::   adelvare                               $$Date::   11 Mar 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjSpMgt_private_h_
#define RTW_HEADER_InjSpMgt_private_h_
#include "Std_Types.h"
#include "InjSpMgt_types.h"
#include "InjSpMgt_import.h"
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
#define INJSPMGT_START_SEC_CODE
#include "InjSpMgt_MemMap.h"

extern Float32 look1_iu8lftu16p9If_binlcs(UInt8 localu0, const UInt8
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern UInt32 plook_u32u16f_binc(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp1d_iu16n4ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern UInt32 plook_u32u16f_lincp(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction, UInt32 *localprevIndex);
extern Float32 intrp1d_iu16n19ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern Float32 look2_iu16u16lftu16n4If_binlcns(UInt16 localu0, UInt16
  localu1, const UInt16 localbp0[], const UInt16 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern Float32 look1_iu16lftu16n4If_binlcns(UInt16 localu0, const UInt16
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern Float32 look1_iu8lftu16n4If_binlcns(UInt8 localu0, const UInt8
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern UInt32 linsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex);
extern Float32 look1_iu16lftu8n8If_binlcns(UInt16 localu0, const UInt16
  localbp0[], const UInt8 localtable[], UInt32 localmaxIndex);
extern void InjSpMgt_F00_Init(void);
extern void InjSpMgt_F03a_PfurailInit(void);
extern void InjSys_EveRst_InjSpMgt_Start(void);
extern void InjSys_EveRst_InjSpMgt(void);
extern void InjSpMgt_F01_InjSpMgtFct_Start(void);
extern void InjSpMgt_F01_InjSpMgtFct(void);
extern void InjSpMgt_F03_InjSpMgtFct2(void);
extern void InjSpMg_F02_SdlEveClcn_InjSpMgt(void);
extern void InjSpMgt_F01_InhFrstInjCkOn(void);
extern void InjSys_EveCkSnNtAc_InjSpMgt_Start(void);
extern void InjSys_EveCkSnNtAc_InjSpMgt(void);
extern void InjSys_EveCkSnNtAc_InjSpMgt(void);
extern void InjSys_EveCkSnNtAc_InjSpMgt(void);
extern void InjSys_EveCkSnNtAc_InjSpMgt(void);
extern void InjSpMgt_F02_InhFrstInjSdlFast(void);
extern void InjSys_SdlFast_InjSpMgt_Start(void);
extern void InjSys_SdlFast_InjSpMgt(void);
extern void InjSys_EveSpl_InjSpMgt(void);
extern void InjSpM_F03_SyncEveClcn_InjSpMgt(void);
extern void InjSys_EveInj_InjSpMgt(void);
extern void InjSpMgt_F01_SyncRotToCrank(void);
extern void InjSys_EveStTCr_InjSpMgt_Start(void);
extern void InjSys_EveStTCr_InjSpMgt(void);
void InjSpMgt_ASYNC1(int controlPortIdx);
void InjSpMgt_ASYNC2(int controlPortIdx);
void InjSpMgt_ASYNC3(int controlPortIdx);
void InjSpMgt_ASYNC4(int controlPortIdx);
void InjSpMgt_ASYNC7(int controlPortIdx);
void InjSpMgt_ASYNC9(int controlPortIdx);

#define INJSPMGT_STOP_SEC_CODE
#include "InjSpMgt_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJSPMGT_START_SEC_CALIB_8BIT
#include "InjSpMgt_MemMap.h"

extern CONST(UInt8, INJSPMGT_CALIB) INJSPMGT_u8Inhib;

#define INJSPMGT_STOP_SEC_CALIB_8BIT
#include "InjSpMgt_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define INJSPMGT_START_SEC_VAR_32BIT
#include "InjSpMgt_MemMap.h"

extern VAR(Float32, INJSPMGT_VAR) Eng_AgCkOffFuInjStrt;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjH1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjH1Tmp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjH2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjH2Tmp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjS1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjS1Tmp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agBegInjS2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjH1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjH2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjS1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjS2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agEndInjS2Tmp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agFrstInjSTTReq;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agOfsPhaInjH1;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agOfsPhaInjH2;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agOfsPhaInjS1;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agOfsPhaInjS2;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agWdInjH1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agWdInjH2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agWdInjS1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_agWdInjS2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_facGainInjH1;
extern VAR(Float32, INJSPMGT_VAR) InjSys_facGainInjH2;
extern VAR(Float32, INJSPMGT_VAR) InjSys_facGainInjS1;
extern VAR(Float32, INJSPMGT_VAR) InjSys_facGainInjS2;
extern VAR(Float32, INJSPMGT_VAR) InjSys_mFuSpMgt;
extern VAR(Float32, INJSPMGT_VAR) InjSys_pFuReqRaw;
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agBegInjH1SpSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agBegInjH2SpSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agBegInjS1SpSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agBegInjS2SpSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agEndInjH1SpSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agEndInjH2SpSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agEndInjS1SpSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agEndInjS2SpSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agFrstInjSTTSp[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agMaxFrstInjSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_prm_agOfsFrstInjSTT[2];
extern VAR(Float32, INJSPMGT_VAR) InjSys_rFilGainPFuReq;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjH1Resi;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjH1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjH1Tmp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjH2Resi;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjH2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjH2Tmp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjResi;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjS1Resi;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjS1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjS1Tmp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjS2Resi;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjS2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_rInjS2Tmp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjH1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjH1TmpSat;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjH2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjH2TmpSat;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjMinHiThd;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjMinLoThd;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjOfsInjH1;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjOfsInjH2;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjOfsInjS1;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjOfsInjS2;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjS1Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjS1TmpSat;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjS2Sp;
extern VAR(Float32, INJSPMGT_VAR) InjSys_tiInjS2TmpSat;

#define INJSPMGT_STOP_SEC_VAR_32BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJSPMGT_START_SEC_VAR_16BIT
#include "InjSpMgt_MemMap.h"

extern VAR(UInt16, INJSPMGT_VAR) InjSys_agBegInjH1Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_agBegInjH2Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_agBegInjS1Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_agBegInjS2Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_agEndInjH1Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_agEndInjH2Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_agEndInjS1Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_agEndInjS2Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_mAirSpMgt;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_pFuReqPrev;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjH1CylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjH2CylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjS1CylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agBegInjS2CylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjH1CylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjH2CylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjS1CylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_agEndInjS2CylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjH1ReqCylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjH2ReqCylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjS1ReqCylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rInjS2ReqCylPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_prm_rMFuReqLPFuPrev[6];
extern VAR(UInt16, INJSPMGT_VAR) InjSys_rInjH1Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_rInjH2Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_rInjS1Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_rInjS2Req;
extern VAR(UInt16, INJSPMGT_VAR) InjSys_rMFuReqLPFu;

#define INJSPMGT_STOP_SEC_VAR_16BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define INJSPMGT_START_SEC_VAR_8BIT
#include "InjSpMgt_MemMap.h"

extern VAR(UInt8, INJSPMGT_VAR) InjSys_noCmprCylStopSTT;
extern VAR(UInt8, INJSPMGT_VAR) InjSys_noCylInjSp;

#define INJSPMGT_STOP_SEC_VAR_8BIT
#include "InjSpMgt_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define INJSPMGT_START_SEC_VAR_BOOLEAN
#include "InjSpMgt_MemMap.h"

extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetCylInjSp;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetPhaInjH1Max;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetPhaInjH2Max;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetPhaInjS1Max;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetPhaInjS2Max;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetSatInjH1Min;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetSatInjH2Min;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetSatInjS1Min;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bDetSatInjS2Min;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bHPFuRail;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bVldInjH1;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bVldInjH2;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bVldInjS1;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_bVldInjS2;
extern VAR(Boolean, INJSPMGT_VAR) InjSys_prm_bInhFrstInjSTTPrev[2];

#define INJSPMGT_STOP_SEC_VAR_BOOLEAN
#include "InjSpMgt_MemMap.h"
#endif                                 /* RTW_HEADER_InjSpMgt_private_h_ */

/*-------------------------------- end of file -------------------------------*/
