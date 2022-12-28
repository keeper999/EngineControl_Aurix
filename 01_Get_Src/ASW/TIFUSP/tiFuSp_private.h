/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tiFuSp                                                  */
/* !Description     : CALCUL DU TEMPS D INJECTION                             */
/*                                                                            */
/* !Module          : tiFuSp                                                  */
/*                                                                            */
/* !File            : tiFuSp_private.h                                        */
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
/*   Code generated on: Sun Nov 17 20:13:35 2013                              */
/*   Model name       : tiFuSp_AUTOCODE.mdl                                   */
/*   Model version    : 1.766                                                 */
/*   Root subsystem   : /tiFuSp                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/TIFUSP/tiFuSp_private.h_v $*/
/* $Revision::   1.19                                                        $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Nov 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_tiFuSp_private_h_
#define RTW_HEADER_tiFuSp_private_h_
#include "Std_Types.h"
#include "tiFuSp_types.h"
#include "tiFuSp_import.h"
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
#define TIFUSP_START_SEC_CODE
#include "tiFuSp_MemMap.h"

extern SInt32 div_s32_floor(SInt32 localnumerator, SInt32 localdenominator);
extern Float32 look2_1fcv2bcvbcvbfbba5nfbbnx(UInt16 localu0, UInt16 localu1,
  const UInt16 localbp0[], const UInt16 localbp1[], const UInt32
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern UInt32 plook_u32u16f_binc(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp1d_iu8n7ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt8 localtable[]);
extern Float32 look2_1hcwlbcvbcvbfbbt5nfbbnx(UInt32 localu0, UInt16 localu1,
  const UInt32 localbp0[], const UInt16 localbp1[], const SInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern Float32 look2_iu16u8lftu16n19If_binlcns(UInt16 localu0, UInt8
  localu1, const UInt16 localbp0[], const UInt8 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern Float32 look1_iu16lftu16n4If_binlcns(UInt16 localu0, const UInt16
  localbp0[], const UInt16 localtable[], UInt32 localmaxIndex);
extern Float32 look2_iu16u16lftu16n4If_binlcns(UInt16 localu0, UInt16
  localu1, const UInt16 localbp0[], const UInt16 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern UInt32 plook_u32u32f_binc(UInt32 localu, const UInt32 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 intrp2d_iu8n7ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt8 localtable[], UInt32 localstride);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern UInt32 binsearch_u32u32(UInt32 localu, const UInt32 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern Float32 look2_1fdv2bdvbcvbfbbr3nfbbnx(UInt16 localu0, UInt32 localu1,
  const UInt16 localbp0[], const UInt32 localbp1[], const UInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern void tiFuSp_F01_tiFuSpSyncInEveClcn(void);
extern void tiFuSp_F02_tiFuSpClcn(void);
extern void tiFuSp_F03_InjtiSyncEveClcn(void);
extern void InjrSys_EveCkSnOn_tiFuSp_Start(void);
extern void InjrSys_EveCkSnOn_tiFuSp(void);
extern void InjrSys_EveCkSnOn_tiFuSp(void);
extern void InjrSys_EveCkSnOn_tiFuSp(void);
extern void tiFuSp_F02_tiFuSpSyncInEveInj(void);
extern void tiFuSp_F02_InjtiSyncEveInj(void);
extern void tiFuSp_F02_InjmFu(void);
extern void InjrSys_EveInj_tiFuSp_Start(void);
extern void InjrSys_EveInj_tiFuSp(void);
extern void InjrSys_EveInj_tiFuSp(void);
extern void tiFuSp_F01_tiFuSpRst(void);
extern void tiFuSp_F01_InjtiSyncIni(void);
extern void tiFuSp_F01_InjmFuIni(void);
extern void InjrSys_EveRst_tiFuSp_Start(void);
extern void InjrSys_EveRst_tiFuSp(void);
extern void InjrSys_EveSpl_tiFuSp(void);
extern void InjrSys_SdlFast_tiFuSp(void);
void tiFuSp_ASYNC1(int controlPortIdx);
void tiFuSp_ASYNC2(int controlPortIdx);
void tiFuSp_ASYNC3(int controlPortIdx);
void tiFuSp_ASYNC4(int controlPortIdx);
void tiFuSp_ASYNC5(int controlPortIdx);
void tiFuSp_ASYNC6(int controlPortIdx);

#define TIFUSP_STOP_SEC_CODE
#include "tiFuSp_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define TIFUSP_START_SEC_CALIB_8BIT
#include "tiFuSp_MemMap.h"

extern CONST(UInt8, TIFUSP_CALIB) TIFUSP_u8Inhib;

#define TIFUSP_STOP_SEC_CALIB_8BIT
#include "tiFuSp_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define TIFUSP_START_SEC_VAR_32BIT
#include "tiFuSp_MemMap.h"

extern VAR(Float32, TIFUSP_VAR) InjrSys_agBegInjH1;
extern VAR(Float32, TIFUSP_VAR) InjrSys_agWdInjSpcModMax;
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjH1[2];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjH2[2];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjS1[2];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjS1Prev[2];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjS2Prev[2];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_facGain[6];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_facGainCor[6];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_mFuInjReq[6];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_tiEfcInj_MP[6];
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiH2ReqCylPrev[6];
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH1TmpCyl[6];
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH1TmpCylPrev[6];
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjMFu[4];
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjReq[6];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_tiInjReqSat[6];
extern VAR(Float32, TIFUSP_VAR) InjrSys_prm_tiInjReqSatMin[6];
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiS1ReqCylPrev[6];
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiS2ReqCylPrev[6];
extern VAR(Float32, TIFUSP_VAR) InjrSys_tiInjSpcModMax;

#define TIFUSP_STOP_SEC_VAR_32BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define TIFUSP_START_SEC_VAR_16BIT
#include "tiFuSp_MemMap.h"

extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjH1[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjH2[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjS1[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjS1Prev[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjS2[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjS2Prev[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_mFuInjH2Req[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_mFuInjS1Req[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_mFuInjS2Req[2];
extern VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiInjOfs[6];
extern VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiInjOfsCor[6];
extern VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsCor[6];
extern VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsH2Cor[2];
extern VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsS1Cor[2];
extern VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsS2Cor[2];
extern VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsS2CorPrev[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_tiWoutInjPrevH2[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_tiWoutInjPrevS1[2];
extern VAR(UInt16, TIFUSP_VAR) InjrSys_prm_tiWoutInjPrevS2[2];

#define TIFUSP_STOP_SEC_VAR_16BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define TIFUSP_START_SEC_VAR_BOOLEAN
#include "tiFuSp_MemMap.h"

extern VAR(Boolean, TIFUSP_VAR) InjrSys_bAcvRstrtSTT;
extern VAR(Boolean, TIFUSP_VAR) InjrSys_prm_bDettiInjMin[6];

#define TIFUSP_STOP_SEC_VAR_BOOLEAN
#include "tiFuSp_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define TIFUSP_START_SEC_VAR_8BIT
#include "tiFuSp_MemMap.h"

extern VAR(UInt8, TIFUSP_VAR) InjrSys_facCorInjETBCmpr;
extern VAR(UInt8, TIFUSP_VAR) InjrSys_facCorInjETBIn;

#define TIFUSP_STOP_SEC_VAR_8BIT
#include "tiFuSp_MemMap.h"
#endif                                 /* RTW_HEADER_tiFuSp_private_h_ */

/*-------------------------------- end of file -------------------------------*/
