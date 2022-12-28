/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : CatAcvDiagT                                             */
/* !Description     : CatAcvDiagT Software Component                          */
/*                                                                            */
/* !Module          : CatAcvDiagT                                             */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : CatAcvDiagT_private.h                                   */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
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
/*   Model name       : CatAcvDiagT_AUTOSAR.mdl                               */
/*   Root subsystem   : /CatAcvDiagT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/SWC_PSA/3.1/CATMON/CATACVDIAGT/CatA$*/
/* $Revision::   1.17                                                        $*/
/* $Author::   etsasson                               $$Date::   08 Nov 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_CatAcvDiagT_private_h_
#define RTW_HEADER_CatAcvDiagT_private_h_
#include "Std_Types.h"
#include "CatAcvDiagT_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CAT_DIAG_INTRU_CATA_READY      ((UInt8) 2U)
#define CAT_DIAG_INTRU_OSC_INTEGRATION ((UInt8) 8U)
#define CAT_DIAG_INTRU_START           ((UInt8) 1U)
#define CAT_DIAG_INTRU_SWITCH_LAMBDA   ((UInt8) 4U)
#define Ext_stGslMod_SC                ((UInt8) 3U)
#define Ext_stTranGasGsl_SC            ((UInt8) 1U)
#define Ext_stTranGslGas_SC            ((UInt8) 2U)
#define LSMON_ITRSV_SEN02DS_WAIT_RESULT ((UInt8) 9U)
#define LSMON_ITRSV_SENO2DS_DIAG_INIT  ((UInt8) 1U)
#define LSMON_ITRSV_SENO2DS_DIAG_NOK   ((UInt8) 8U)
#define LSMON_ITRSV_SENO2DS_DIAG_OK    ((UInt8) 4U)
#define LSMON_ITRSV_SENO2DS_DIAG_RUNNING ((UInt8) 2U)
#define OXC_MON_RUNNING                ((UInt8) 2U)
#define OXC_MON_WAIT                   ((UInt8) 4U)
#define OXC_MON_WAITING_TO_START       ((UInt8) 1U)
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
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "CatAcvDiagT_MemMap.h"

extern SInt32 _sfEvent_;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "CatAcvDiagT_MemMap.h"
#define CatAcvDiagT_START_SEC_CODE
#include "CatAcvDiagT_MemMap.h"

extern void RE_CatMon_EveRst_CatAcvDiag_Start(void);
extern void RE_CatMon_EveRst_CatAcvDiag(void);
extern void RE_CatMon_SdlFast_CatAcvDiag_Init(void);
extern void RE_CatMon_SdlFast_CatAcvDiag_Start(void);
extern void RE_CatMon_SdlFast_CatAcvDiag(void);
extern void RE_CatMon_SdlMid_CatAcvDiag_Start(void);
extern void RE_CatMon_SdlMid_CatAcvDiag(void);
extern void RE_CatMon_SdlSlow_CatAcvDiag_Start(void);
extern void RE_CatMon_SdlSlow_CatAcvDiag(void);
void CatAcvDiagT_ASYNC1(int controlPortIdx);
void CatAcvDiagT_ASYNC2(int controlPortIdx);
void CatAcvDiagT_ASYNC3(int controlPortIdx);
void CatAcvDiagT_ASYNC4(int controlPortIdx);
void CatAcvDiagT_ASYNC5(int controlPortIdx);

#define CatAcvDiagT_STOP_SEC_CODE
#include "CatAcvDiagT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_16BIT" */
#define CatAcvDiagT_START_SEC_CALIB_16BIT
#include "CatAcvDiagT_MemMap.h"

extern CONST(UInt16, CATACVDIAGT_CALIB) CatMon_tiInhDiagIntr_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) LsMon_rMixtSenO2DsDiagLean_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) LsMon_rMixtSenO2DsDiagRich_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) LsMon_tiItrsvSenO2DsDiag_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) LsMon_tiItrsvWaitSenO2DsDiag_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) LsMon_uThdItrsvSenO2DsDiagLean_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) LsMon_uThdItrsvSenO2DsDiagRich_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_lamFbFilDeltaMaxThd_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_ldEstimDeltaMaxGas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_ldEstimDeltaMax_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMaxGas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMax_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMinPlausGas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMinPlaus_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_mO2StgMvEstim_B;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_mfAirDeltaMaxGas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_mfAirDeltaMaxThd_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_mfAirDeltaMax_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_nCkDeltaMaxGas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_nCkDeltaMax_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_nEngDeltaMaxThd_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_rAirLdDeltaMaxThd_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_rFbLsclDeltaMaxGas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_rFbLsclDeltaMax_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtPha1Gas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtPha1_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtPha2Gas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtPha2_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_rMixtReqMonIntr_B;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_rlamFilThrHiThd_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_rlamFilThrLoThd_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tAirMnfMesHiThdGas_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tAirMnfMesHiThd_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tAirMnfMesLoThdGas_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tAirMnfMesLoThd_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tCoMesHiThdGas_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tCoMesHiThd_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tCoMesLoThdGas_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tCoMesLoThd_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tOxCDeltaMaxThd_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tOxCUsMesDeltaMaxGas_C;
extern CONST(SInt16, CATACVDIAGT_CALIB) OxC_tOxCUsMesDeltaMax_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiAcvCdnDlyOn_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiAcvReqDlySdlCord_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiAcvRunDlyOff_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiPha1MaxDlyProtGas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiPha1MaxDlyProt_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiPha2ChgMaxDly_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiRlamFiLpfTau_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiTmrIniMonORngIntrGas_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiTmrIniMonORngIntr_C;
extern CONST(UInt16, CATACVDIAGT_CALIB) OxC_tiTmrMinMonORngIntrIni_C;

#define CatAcvDiagT_STOP_SEC_CALIB_16BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define CatAcvDiagT_START_SEC_CARTO_16BIT
#include "CatAcvDiagT_MemMap.h"

extern CONST(UInt16, CATACVDIAGT_CARTO) OxC_bAirLdNAuthColInput_A[15];
extern CONST(UInt16, CATACVDIAGT_CARTO) OxC_bAirLdNAuthRowInput_A[16];
extern CONST(UInt16, CATACVDIAGT_CARTO) OxC_mfDsThr_A[16];
extern CONST(SInt16, CATACVDIAGT_CARTO) OxC_tOxC_A[16];
extern CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiCanPurgClsInput_A[16];
extern CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiLamRegStabInput_A[16];
extern CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiLamRegStab_T[16];
extern CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiTmrScdnGas_T[16];
extern CONST(UInt16, CATACVDIAGT_CARTO) OxC_tiTmrScdn_T[16];

#define CatAcvDiagT_STOP_SEC_CARTO_16BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define CatAcvDiagT_START_SEC_CALIB_8BIT
#include "CatAcvDiagT_MemMap.h"

extern CONST(UInt8, CATACVDIAGT_CALIB) LsMon_stItrsvSenO2DsDiag_B;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_ctMaxMonORngIntrGas_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_ctMaxMonORngIntr_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_ctMinMonORngIntrGas_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_ctMinMonORngIntr_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_idxRlamSpAcv_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_rO2_mfDsThr_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_rOpCanPurgReqThd_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiAirLdDlyOn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiAirLdLpfTau_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiCylNotCutOffDlyOn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlySdlCord_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStabMfAir_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStabNEng_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStabOxCT_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStabRatAirLd_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiDlyStablamFbFil_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiMfAirDlyOn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiMfAirLpfTau_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiNEngDlyOn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiNEngLpfTau_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiOxCTDlyOn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiOxCTLpfTau_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiRlamDlyOn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiRlamLpfTau_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiStabCdnDlyOn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTmrMonStabFastCdnGas_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTmrMonStabFastCdn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTmrMonStabSlowCdnGas_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTmrMonStabSlowCdn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) OxC_tiTranModDlyOn_C;
extern CONST(UInt8, CATACVDIAGT_CALIB) Oxc_tiStabRstOff_C;

#define CatAcvDiagT_STOP_SEC_CALIB_8BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define CatAcvDiagT_START_SEC_CARTO_8BIT
#include "CatAcvDiagT_MemMap.h"

extern CONST(UInt8, CATACVDIAGT_CARTO) OxC_bAirLdNAuth_M[16][15];
extern CONST(UInt8, CATACVDIAGT_CARTO) OxC_bAirMfTAuth_M[16][16];
extern CONST(UInt8, CATACVDIAGT_CARTO) OxC_rO2StgEstimCorIndex_M[16][16];
extern CONST(UInt8, CATACVDIAGT_CARTO) OxC_rO2StgEstimCorInterpGas_M[16][16];
extern CONST(UInt8, CATACVDIAGT_CARTO) OxC_rO2StgEstimCorInterp_M[16][16];
extern CONST(UInt8, CATACVDIAGT_CARTO) OxC_tiCanPurgCls_T[16];

#define CatAcvDiagT_STOP_SEC_CARTO_8BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define CatAcvDiagT_START_SEC_CALIB_BOOLEAN
#include "CatAcvDiagT_MemMap.h"

extern CONST(Boolean, CATACVDIAGT_CALIB) CATACVDIAGT_ACTIVE_BYP_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) CatMon_bDgoORngIntr_B;
extern CONST(Boolean, CATACVDIAGT_CALIB) CatMon_bMonRunORngIntr_B;
extern CONST(Boolean, CATACVDIAGT_CALIB) CatMon_bMonWaitORngIntr_B;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bAcvFbL_rMonItrv_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bDiagUnlimInhGas_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bDiagUnlimInh_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bIdcInhChknEng_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bIdcInhChkrAirLd_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhAFACdn_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhBlbyCdn_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaAirLd_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaMfAir_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaNEng_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaRLamFil_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhDeltaTOxC_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilAirLd_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilMfAir_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilNEng_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilRlamFilOxC_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bInhFilTOxC_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bItpolClc_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bLsUsProp_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bMonEnaORngIntr_B;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bMonEndORngIntr_B;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bMonORngIntrAcvCdn_B;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bMonRunORngIntr_B;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bRlamAdpReq_B;
extern CONST(Boolean, CATACVDIAGT_CALIB) OxC_bRlamFiLpfRst_C;
extern CONST(Boolean, CATACVDIAGT_CALIB) Oxc_stMonItrsvAcvTunRst_C;

#define CatAcvDiagT_STOP_SEC_CALIB_BOOLEAN
#include "CatAcvDiagT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_32BIT
#include "CatAcvDiagT_MemMap.h"

extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) AFReg_rFbLsclFilFil;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) Engine_load_filt;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) Ext_nEngFil;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) Ext_tOxCEstimFil;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) LsMon_rMixtItrsvSenO2DsDiagTmp;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) LsMon_uThdItrsvSenO2DsDiagTmp;
extern VAR(UInt32, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgSumEstim_IRV_MP;
extern VAR(UInt32, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgTotEstim_IRV_MP;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirMesThrEstimFil;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rFbL_rMonItrv;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rFbLsclFil_ItrsvSenO2Strt;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rFbLsclFil_rMonItrsvStrt;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rMixtPha1Tmp;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rMixtPha2Tmp;
extern VAR(Float32, CATACVDIAGT_INTERNAL_VAR) OxC_rO2StgEstimCor;
extern VAR(SInt32, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrIniMonORngIntrTmp;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_32BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_16BIT
#include "CatAcvDiagT_MemMap.h"

extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) CatMon_tiInhDiagIntr;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) Lambda_feedback_filt;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) LsMon_tiItrsvSenO2DsDiag_IRV_MP;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) LsMon_tiItrsvWaitSenO2DsDiag;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgEstim;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgMaxTmp;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgMinPlausTmp;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mO2StgThdTmp;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirThrMax;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirThrMaxPrev;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirThrMin;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_mfAirThrMinPrev;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_nEngMax;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_nEngMaxPrev;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_nEngMin;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_nEngMinPrev;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rAirLdMax;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rAirLdMaxPrev;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rAirLdMin;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rAirLdMinPrev;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rlamFilMax;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rlamFilMaxPrev;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rlamFilMin;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_rlamFilMinPrev;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tOxCMax;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tOxCMaxPrev;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tOxCMin;
extern VAR(SInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tOxCMinPrev;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiDlyMaxProt_rMixtPha1;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiPha1MaxDlyProtTmp;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiPha2ChgDly;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrIniMonORngIntr_IRV_MP;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrMinMonORngIntr;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrMonStabFastCdn_IRV_MP;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrScdnMonORngIntrIni;
extern VAR(UInt16, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrScdnMonORngIntr_IRV_MP;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_16BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_8BIT
#include "CatAcvDiagT_MemMap.h"

extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_ctMaxMonORngIntrTmp;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_ctMinMonORngIntrTmp;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_ctMonORngIntr_IRV_MP;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_stMonIntrAcv_IRV_MP;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_stMonIntrRun_IRV_MP;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntMfAirThrPrev;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntOxCPrev;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntRlamFil;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntRlamFilPrev;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabMfAirThr;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabNEng;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabNEngPrev;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabOxCT;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabRatAirLd;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiCntStabRatAirLdPrev;
extern VAR(UInt8, CATACVDIAGT_INTERNAL_VAR) OxC_tiTmrMonStabSlowCdn_IRV_MP;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_8BIT
#include "CatAcvDiagT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define CatAcvDiagT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "CatAcvDiagT_MemMap.h"

extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) First_diag_Sen02;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bAcvCalcmO2Stg;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bAcvMonItrsv;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bAirLdNAuth;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bAirMfTAuth;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bDetStabNEng;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bDetStabOxCT;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bDiagUnlimInhTmp;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bEndInt;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bIdcInhChkMfAir;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bIdcInhChkTOxC;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bIdcInhChkrLamFil;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bMonORngIntrStabCdn_IRV_MP;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRlamFilOxCCdn;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilAirLd;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilAirLdCdn;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilMfAir;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilMfAirCdn;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilNEng;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilNEngCdn;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilOxCT;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilOxCTCdn;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilRlam;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFilRlamCdn;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bRstFiltNEng;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabAirLd;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabCanPurg;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxAirLd;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxMfAir;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxNEng;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxOxCT;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabDeltaMaxRlam;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilAirLd;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilMfAir;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilNEng;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilOxCT;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabFilRlam;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabMfAir;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabMfAirThr;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabRatAirLdCor;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabRlam;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabRlamFilOxC;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabTranMod;
extern VAR(Boolean, CATACVDIAGT_INTERNAL_VAR) OxC_bStabnoCylCutOff;

#define CatAcvDiagT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "CatAcvDiagT_MemMap.h"
#endif                                 /* RTW_HEADER_CatAcvDiagT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
