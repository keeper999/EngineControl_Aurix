/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjrPrmMdl                                              */
/* !Description     : INJECTOR MODEL PARAMETERS SPECIFICATION                 */
/*                                                                            */
/* !Module          : InjrPrmMdl                                              */
/*                                                                            */
/* !File            : InjrPrmMdl_private.h                                    */
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
/*   Code generated on: Wed Sep 12 10:33:08 2012                              */
/*   Model name       : InjrPrmMdl_AUTOCODE.mdl                               */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /InjrPrmMdl                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjrPrmMdl/5-SOFT-LIV/InjrPr$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   25 Sep 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_InjrPrmMdl_private_h_
#define RTW_HEADER_InjrPrmMdl_private_h_
#include "Std_Types.h"
#include "InjrPrmMdl_types.h"
#include "InjrPrmMdl_import.h"
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
#define INJRPRMMDL_START_SEC_CODE
#include "InjrPrmMdl_MemMap.h"

extern Float32 look2_iu16lfts16p9If_binlcs(UInt16 localu0, UInt16 localu1,
  const UInt16 localbp0[], const UInt16 localbp1[], const SInt16
  localtable[], const UInt32 localmaxIndex[], UInt32 localstride);
extern UInt32 plook_u32u16f_binc(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern Float32 look1_iu8lfIf_binlcs(UInt8 localu0, const UInt8 localbp0[],
  const UInt8 localtable[], UInt32 localmaxIndex);
extern Float32 intrp2d_iu16n6ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride);
extern Float32 intrp2d_is16n19ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const SInt16 localtable[], UInt32 localstride);
extern Float32 intrp2d_iu16n15ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride);
extern UInt32 binsearch_u32u16(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern UInt32 plook_u32u8f_binc(UInt8 localu, const UInt8 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction);
extern UInt32 binsearch_u32u8(UInt8 localu, const UInt8 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex);
extern Float32 intrp1d_iu16n15ff_u32f_l_ns(UInt32 localbpIndex, Float32
  localfrac, const UInt16 localtable[]);
extern void InjrPrmMdl_F02_SyncIn1(UInt8 rtu_Eng_noInNxtCyl, UInt8
  rtu_Eng_noInCyl, const UInt16 rtu_FuSysM_prm_pFuEstimInjS2Cyl[6], const
  UInt16 rtu_InjSys_prm_mFuInjH2ReqCyl[6], const UInt16
  rtu_InjSys_prm_mFuInjS1ReqCyl[6], const UInt16
  rtu_InjSys_prm_mFuInjS2ReqCyl[6], const UInt16
  rtu_FuSysM_prm_pFuEstimInjS1Cyl[6], const UInt16
  rtu_FuSysM_prm_pFuEstimInjH2Cyl[6], const UInt16
  rtu_FuSysM_prm_pFuEstimInjH1Cyl[6], const UInt16
  rtu_CylM_prm_pCylEstimInjH1Cyl[6], const UInt16
  rtu_CylM_prm_pCylEstimInjH2Cyl[6], const UInt16
  rtu_CylM_prm_pCylEstimInjS1Cyl[6], const UInt16
  rtu_CylM_prm_pCylEstimInjS2Cyl[6], const UInt16
  rtu_InjSys_prm_mFuInjH1ReqCyl[6], UInt16 *rty_InjrM_prm_pCylEstimInj,
  UInt16 *rty_InjrM_prm_pFuEstimInj, UInt16 *rty_InjrM_prm_pFuEstimInj_l,
  UInt16 *rty_InjrM_prm_pFuEstimInj_a, UInt16 *rty_InjrM_prm_pCylEstimInj_j,
  UInt16 *rty_InjrM_prm_pCylEstimInj_i, UInt16 *rty_InjrM_prm_mFuInjReq,
  UInt16 *rty_InjrM_prm_mFuInjReq_k, UInt16 *rty_InjrM_prm_mFuInjReq_l,
  UInt16 *rty_InjrM_prm_pCylEstimInj_l, UInt16 *rty_InjrM_prm_mFuInjReq_n,
  UInt16 *rty_InjrM_prm_pFuEstimInj_m);
extern void InjrPrmMdl_F02_SyncIn2(void);
extern void InjrPr_F01_InjrMdlCylCorSyncRst(void);
extern void InjrPrmMdl_F03_InjrPrmMdlFct(const UInt16
  rtu_InjrM_prm_pFuEstimInj[4], const UInt16 rtu_InjrM_prm_pCylEstimInj[4],
  const Float32 rtu_InjrM_prm_facCorCylPFuInj[4], UInt16 rtu_FuSysM_tFu,
  UInt8 rtu_InjSys_stTypElCmdInjrReq, const Float32
  rtu_InjrM_prm_facCorCylOfs[4], UInt16 rtu_Ext_nEng, const UInt16
  rtu_InjrM_prm_mFuInjReq[4], const Float32 rtu_InjrM_prm_facCorCylGainLnr[4],
  rtB_F03_InjrPrmMdlFct_InjrPrmMd *localB);
extern void InjrPrmMdl_F03_InjrPrmMdlFct1(void);
extern void InjrM_EveRst_InjrPrmMdl_Start(void);
extern void InjrM_EveRst_InjrPrmMdl(void);
extern void InjrPrmMdl_F01_SyncIn(void);
extern void InjrPr_F03_InjrMdlCylCorSyncEve(void);
extern void InjrPrmMdl_F03_InjrPrmMdlFct_e(void);
extern void InjrM_EveCkSnOn_InjrPrmMdl_Start(void);
extern void InjrM_EveCkSnOn_InjrPrmMdl(void);
extern void InjrM_EveCkSnOn_InjrPrmMdl(void);
extern void InjrM_EveCkSnOn_InjrPrmMdl(void);
extern void InjrM_SdlFast_InjrPrmMdl(void);
extern void InjrPrmMdl_F02_SyncIn1_k(void);
extern void Inj_F02_InjrMdlCylCorSyncEveInj(void);
extern void InjrM_EveInj_InjrPrmMdl_Start(void);
extern void InjrM_EveInj_InjrPrmMdl(void);
extern void InjrM_EveSpl_InjrPrmMdl(void);
void InjrPrmMdl_ASYNC1(int controlPortIdx);
void InjrPrmMdl_ASYNC2(int controlPortIdx);
void InjrPrmMdl_ASYNC3(int controlPortIdx);

#define INJRPRMMDL_STOP_SEC_CODE
#include "InjrPrmMdl_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define INJRPRMMDL_START_SEC_CALIB_8BIT
#include "InjrPrmMdl_MemMap.h"

extern CONST(UInt8, INJRPRMMDL_CALIB) INJRPRMMDL_u8Inhib;

#define INJRPRMMDL_STOP_SEC_CALIB_8BIT
#include "InjrPrmMdl_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define INJRPRMMDL_START_SEC_VAR_32BIT
#include "InjrPrmMdl_MemMap.h"

extern VAR(Float32, INJRPRMMDL_VAR) InjrM_prm_facCorCylGainLnr[4];
extern VAR(Float32, INJRPRMMDL_VAR) InjrM_prm_facCorCylOfs[4];
extern VAR(Float32, INJRPRMMDL_VAR) InjrM_prm_facCorCylPFuInj[4];
extern VAR(Float32, INJRPRMMDL_VAR) InjrM_prm_facGainLnrInjCal[4];
extern VAR(Float32, INJRPRMMDL_VAR) InjrM_prm_pDsInjrCor[4];
extern VAR(Float32, INJRPRMMDL_VAR) InjrM_prm_pFuEstimInjCor[4];
extern VAR(Float32, INJRPRMMDL_VAR) InjrM_prm_tiInjOfsCal[4];

#define INJRPRMMDL_STOP_SEC_VAR_32BIT
#include "InjrPrmMdl_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define INJRPRMMDL_START_SEC_VAR_16BIT
#include "InjrPrmMdl_MemMap.h"

extern VAR(UInt16, INJRPRMMDL_VAR) InjrM_prm_facCorGainLnrCal[4];
extern VAR(UInt16, INJRPRMMDL_VAR) InjrM_prm_mFuInjReq[4];
extern VAR(UInt16, INJRPRMMDL_VAR) InjrM_prm_pCylEstimInj[4];
extern VAR(UInt16, INJRPRMMDL_VAR) InjrM_prm_pFuEstimInj[4];

#define INJRPRMMDL_STOP_SEC_VAR_16BIT
#include "InjrPrmMdl_MemMap.h"
#endif                                 /* RTW_HEADER_InjrPrmMdl_private_h_ */

/*-------------------------------- end of file -------------------------------*/
