/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : ExMGslT2                                                */
/* !Description     : ExMGslT2 Software Component                             */
/*                                                                            */
/* !Module          : ExMGslT2                                                */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : ExMGslT2_private.h                                      */
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
/*   Model name       : ExMGslT2_AUTOSAR.mdl                                  */
/*   Root subsystem   : /ExMGslT2                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M06-ExMGslT2/5-S$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   05 Jul 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ExMGslT2_private_h_
#define RTW_HEADER_ExMGslT2_private_h_
#include "Std_Types.h"
#include "ExMGslT2_types.h"
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
#define ExMGslT2_START_SEC_CODE
#include "ExMGslT2_MemMap.h"

extern void RE_ExMGslT2_001_MSE_Start(void);
extern void RE_ExMGslT2_001_MSE(void);
extern void ExMGslT2_LibP(const UInt8 *rtu_ExM_noIdxPresPrev, const Float32
  rtu_ExM_prm_pEgInterPrev[12], const Float32 *rtu_ExM_pDsBs, Boolean
  rtu_FRM_bSenPres, UInt8 rtu_ExM_prm_stElement, UInt8
  rtu_ExM_prm_stElement_d, UInt8 rtu_ExM_prm_stElement_j, UInt8
  rtu_ExM_prm_stElement_a, UInt8 rtu_ExM_prm_stElement_i, UInt8
  rtu_ExM_prm_stElement_e, UInt8 rtu_ExM_prm_stElement_g, UInt8
  rtu_ExM_prm_stElement_h, UInt8 rtu_ExM_prm_stNbTypElement, UInt8
  rtu_ExM_prm_stNbTypElement_m, UInt8 rtu_ExM_prm_stNbTypElement_b, UInt8
  rtu_ExM_prm_stNbTypElement_h, UInt8 rtu_ExM_prm_stNbTypElement_ho, UInt8
  rtu_ExM_prm_stNbTypElement_f, UInt8 rtu_ExM_prm_stNbTypElement_a, UInt8
  rtu_ExM_prm_stNbTypElement_ao, Float32 rtu_ExM_prm_tEgPrev, Float32
  rtu_ExM_prm_tEgPrev_j, Float32 rtu_ExM_prm_tEgPrev_a, Float32
  rtu_ExM_prm_tEgPrev_k, Float32 rtu_ExM_prm_tEgPrev_i, Float32
  rtu_ExM_prm_tEgPrev_h, Float32 rtu_ExM_prm_tEgPrev_k0, Float32
  rtu_ExM_prm_tEgPrev_aa, Float32 rtu_ExM_prm_tEgPrev_m, Float32
  rtu_ExM_prm_tEgPrev_l, Float32 rtu_ExM_prm_tEgPrev_d, Float32
  rtu_ExM_prm_tEgPrev_b, UInt16 rtu_ExM_mfEgWoutEGR, UInt16
  rtu_UsThrM_pAirExt, Boolean rtu_FRM_bTrbAct, UInt16 rtu_TrbAct_rOpTrbAct,
  UInt16 rtu_Ext_nEng, SInt16 rtu_EngM_agCkOpInVlvEstimRef1, SInt16
  rtu_EngM_agCkClsExVlvEstimRef1, UInt16 rtu_ExM_pMes, Float32
  rtu_ExM_mfWgEstim_irv, Float32 rtu_ExM_mfTrbEstimSat_irv, const Float32
  rtu_ExM_prm_pEgPrev[12], Float32 *rty_ExM_pUs, UInt8 *rty_ExM_noIdxPres,
  Float32 rty_ExM_prm_pEgInter[12], rtB_LibP_ExMGslT2 *localB,
  rtDW_LibP_ExMGslT2 *localDW);
extern void RE_ExMGslT2_006_TEV_Start(void);
extern void RE_ExMGslT2_006_TEV(void);
extern void ExMGslT2_Resetdufiltre(Boolean rtu_0, Float32 rtu_INIT_OUTPUT,
  rtB_Resetdufiltre_ExMGslT2 *localB);
extern void ExMGslT2_LibT(const UInt8 *rtu_ExM_noIdxTPrev, const Float32
  rtu_ExM_prm_tEgOxCPrev[3], const UInt8 *rtu_ExM_noIdxOxCPrev, Boolean
  rtu_FRM_bSenTEg, Float32 rtu_ExM_prm_pEg, Float32 rtu_ExM_prm_pEg_l,
  Float32 rtu_ExM_prm_pEg_i, Float32 rtu_ExM_prm_pEg_d, Float32
  rtu_ExM_prm_pEg_n, Float32 rtu_ExM_prm_pEg_in, Float32 rtu_ExM_prm_pEg_p,
  Float32 rtu_ExM_prm_pEg_b, Float32 rtu_ExM_prm_pEg_e, Float32
  rtu_ExM_prm_pEg_c, Float32 rtu_ExM_prm_pEg_h, Float32 rtu_ExM_prm_pEg_o,
  const Float32 rtu_ExM_prm_tWallInterPrev[12], UInt8 rtu_ExM_prm_stElement,
  UInt8 rtu_ExM_prm_stElement_c, UInt8 rtu_ExM_prm_stElement_d, UInt8
  rtu_ExM_prm_stElement_f, UInt8 rtu_ExM_prm_stElement_k, UInt8
  rtu_ExM_prm_stElement_f4, UInt8 rtu_ExM_prm_stElement_k2, UInt8
  rtu_ExM_prm_stElement_g, UInt8 rtu_ExM_prm_stNbTypElement, UInt8
  rtu_ExM_prm_stNbTypElement_m, UInt8 rtu_ExM_prm_stNbTypElement_h, UInt8
  rtu_ExM_prm_stNbTypElement_f, UInt8 rtu_ExM_prm_stNbTypElement_n, UInt8
  rtu_ExM_prm_stNbTypElement_e, UInt8 rtu_ExM_prm_stNbTypElement_o, UInt8
  rtu_ExM_prm_stNbTypElement_d, Float32 rtu_ExM_prm_tEgPrev, Float32
  rtu_ExM_prm_tEgPrev_e, Float32 rtu_ExM_prm_tEgPrev_l, Float32
  rtu_ExM_prm_tEgPrev_i, Float32 rtu_ExM_prm_tEgPrev_h, Float32
  rtu_ExM_prm_tEgPrev_g, Float32 rtu_ExM_prm_tEgPrev_m, Float32
  rtu_ExM_prm_tEgPrev_d, Float32 rtu_ExM_prm_tEgPrev_f, Float32
  rtu_ExM_prm_tEgPrev_p, Float32 rtu_ExM_prm_tEgPrev_ld, Float32
  rtu_ExM_prm_tEgPrev_ij, SInt16 rtu_Ext_tCoMes, SInt8 rtu_Ext_tAir, const
  Float32 *rtu_ExM_tEgInp, UInt16 rtu_ExM_mfEgWoutEGR, UInt16
  rtu_Veh_spdVeh, UInt8 rtu_Ext_rSpdFanAct, UInt16 rtu_Ext_nEng, Float32
  rtu_ExM_mfTrbEstimSatRef, Float32 rtu_ExM_mfWgEstimRef, UInt16
  rtu_FARSp_rMixtCylSp, UInt16 rtu_EngM_mfAirCor, UInt8
  rtu_InjSys_noCylCutOff, Boolean rtu_AfuA_bInvldEthRat, UInt8
  rtu_AfuA_rEthWiExct, UInt16 rtu_IgSys_rDynIgSpEfc, Boolean
  rtu_ThMgt_bPosnFSF, Boolean rtu_Ext_bAdFanAct, UInt8 rtu_Ext_stTypInjSysCf,
  UInt16 rtu_EngM_mfAirScvCor, Float32 rtu_ExM_rMixtInp, UInt16
  rtu_ExM_tEgMes, const Float32 rtu_ExM_prm_tEgInterPrev[12], Float32
  rty_ExM_prm_tEgOxC[3], UInt8 *rty_ExM_noIdxOxC, Float32 *rty_ExM_tEgOut,
  UInt8 *rty_ExM_noIdxT, Float32 rty_ExM_prm_tEgInter[12], Float32
  rty_ExM_prm_tWallInter[12], rtB_LibT_ExMGslT2 *localB, rtDW_LibT_ExMGslT2
  *localDW);
extern void RE_ExMGslT2_007_TEV_Start(void);
extern void RE_ExMGslT2_007_TEV(void);
void ExMGslT2_ASYNC1(int controlPortIdx);
void ExMGslT2_ASYNC2(int controlPortIdx);

#define ExMGslT2_STOP_SEC_CODE
#include "ExMGslT2_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_16BIT" */
#define ExMGslT2_START_SEC_CALIB_16BIT
#include "ExMGslT2_MemMap.h"

extern CONST(SInt16, EXMGSLT2_CALIB) ExM_agCkClsExVlvLimThd_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_agCkClsExVlvMax_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_agCkClsExVlvMid_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_agCkClsExVlvMin_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_agCkOpInVlvLimThd_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_agCkOpInVlvMax_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_agCkOpInVlvMid_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_agCkOpInVlvMin_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_cppMassTWC1_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_cppMassTWC2_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_cppMassTWC3_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facClsExVlvMidMaxEqu_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facClsExVlvMinMidEqu_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facFilExoInjCutOff1_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facFilExoInjCutOff2_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facFilExoInjCutOff3_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facIgEffFil_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facInMidMax_A[11];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facInMinMid_A[11];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facMassFlowToAirLdCnv_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facOpInVlvMidMaxEqu_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facOpInVlvMinMidEqu_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_facPresUsPipeSq_A[24];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfEgFacPresLossTWC_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfEgFlt_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfEgTot_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfEgTrbNorm_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfEgWoutEGRInit_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfEgWoutEGR_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfEg_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfScvThd_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfTrbActrInit_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfTrbEstimSat_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfTrbInit_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_mfWgEstim_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_nEng1Y_A[18];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_nEngTExoTWCAfs_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_nEngTExoTWCWiScvOpt2_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_nEngThdLdCorClc_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_nEngThdTEgTrb_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_nEngY_A[18];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_pDsTrbEstimMin_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_pDsTrbEstimSI_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_pExMnfEstimMin_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_pExMnfEstim_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_pSqPresSqrt_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_prm_pEgFlt_B[12];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_prm_pEg_B[12];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_prm_tEgFlt_B[12];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_prm_tEg_B[12];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_prm_tExMnfEstimCyl_B[6];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_prm_tWall_B[12];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rAirLdTExoTWCAfs_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rAirLdTExoTWCWiScvOpt2_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rEgTotLdCorX_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rEgTotLdCor_nEngThd_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rEgTrbLdCor_nEngThd_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rEgTrbLdX_A[20];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rIgSpEfcFil_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rMixtFacCorRatMixt_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rPresDsOverUs_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rPresInit_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rPresTrbEstimIvs_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rPresTrbEstim_A[11];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rPresTrbEstim_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rTEgNorm_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_rTbrActrPosnX_A[20];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_spdVehFacExtExgTWC_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_spdVehX_A[9];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tExMnfEstim_B;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_tExoInjCutOff1_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_tExoInjCutOff2_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_tExoInjCutOff3_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_tExoTWCNoLiOffDone1_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_tExoTWCNoLiOffDone2_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_tExoTWCNoLiOffDone3_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tManTNearTWC_C;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_tOxCEstim_B;
extern CONST(SInt16, EXMGSLT2_CALIB) ExM_tPreOxCEstim_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tSwitchAirUndHo_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tSwitchWallPipe_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tTWCLiOffThd1_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tTWCLiOffThd2_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tTWCLiOffThd3_C;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tTWCMvTCorPresLossTWC_A[8];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tUsMainOxCEstim_B;
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tUsPipe_A[14];
extern CONST(UInt16, EXMGSLT2_CALIB) ExM_tiEngStop_A[16];
extern CONST(UInt16, EXMGSLT2_CALIB) Exm_facEOxdEmiEth_C;
extern CONST(UInt16, EXMGSLT2_CALIB) Exm_facEOxdEmiGsl_C;

#define ExMGslT2_STOP_SEC_CALIB_16BIT
#include "ExMGslT2_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define ExMGslT2_START_SEC_CARTO_16BIT
#include "ExMGslT2_MemMap.h"

extern CONST(UInt16, EXMGSLT2_CARTO) ExM_effTrb_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExgExtCoUndHoPipe1_M[9][11];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExgExtCoUndHoPipe2_M[9][11];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExgExtCoUndHoPipe3_M[9][11];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExgExtCoUndHoPipe4_M[9][11];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgAdFanFSFopTWC1_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgAdFanFSFopTWC2_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgAdFanFSFopTWC3_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgAdFanTWC1_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgAdFanTWC2_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgAdFanTWC3_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgFSFopTWC1_M[8][3];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgFSFopTWC2_M[8][3];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgFSFopTWC3_M[8][3];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgPipe1_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgPipe2_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgPipe3_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgPipe4_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgTWC1_M[8][3];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgTWC2_M[8][3];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgTWC3_M[8][3];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgWallUndHoPipe1_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgWallUndHoPipe2_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgWallUndHoPipe3_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facExtExgWallUndHoPipe4_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facFltPres_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facFltT_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facInMidMaxAdjExMax_T[11];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facInMidMaxAdjExMid_T[11];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facInMinMidAdjExMax_T[11];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facItExgOverMfPipe1_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facItExgOverMfPipe2_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facItExgOverMfPipe3_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facItExgOverMfPipe4_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facJHeatWallPipe1_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facJHeatWallPipe2_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facJHeatWallPipe3_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facJHeatWallPipe4_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facNatCnvcTEg_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facNatCnvcTWall_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresLossPipe1_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresLossPipe2_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresLossPipe3_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresLossPipe4_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresLossTWC1_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresLossTWC2_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresLossTWC3_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresTrb_M[20][18];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facPresUsPipe_T[24];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facTPresLossPipe1_T[14];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facTPresLossPipe2_T[14];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facTPresLossPipe3_T[14];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facTPresLossPipe4_T[14];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_facTbrActrRedEstim_M[20][18];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_mfTrbEstimCor_T[11];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_pSqrt_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_rTDsOverUs_T[16];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_rTEgNormSqrt_T[16];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tCorIgEff_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_tCorPresLossTWC1_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_tCorPresLossTWC2_T[8];
extern CONST(UInt16, EXMGSLT2_CARTO) ExM_tCorPresLossTWC3_T[8];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tExoTWCAfs1_M[8][8];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tExoTWCAfs2_M[8][8];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tExoTWCAfs3_M[8][8];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tExoTWCAfsEth1_M[8][8];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tExoTWCAfsEth2_M[8][8];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tExoTWCAfsEth3_M[8][8];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tExoTWCWiScvEthOpt2_M[8][8];
extern CONST(SInt16, EXMGSLT2_CARTO) ExM_tExoTWCWiScvGslOpt2_M[8][8];

#define ExMGslT2_STOP_SEC_CARTO_16BIT
#include "ExMGslT2_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define ExMGslT2_START_SEC_CALIB_8BIT
#include "ExMGslT2_MemMap.h"

extern CONST(UInt8, EXMGSLT2_CALIB) ExM_noPresSenTEg_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_noSelPresDsTrb_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_noSelPresExMnf_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_noSelTEgOxC_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_noSelTEgPreOxC_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_noSelTEgUsMainOxC_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_noSelTExMnf_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_rEthRatDft_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_rEth_A[8];
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_rSpdFanFacExtExgTWC_A[3];
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_rSpdFanY_A[11];
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_stElement1_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_stElement2_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_stElement3_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_stElement4_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_stElement5_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_stElement6_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_stElement7_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_stElement8_C;
extern CONST(UInt8, EXMGSLT2_CALIB) ExM_tiSdlThermo_C;
extern CONST(UInt8, EXMGSLT2_CALIB) Exm_conc02Air_C;

#define ExMGslT2_STOP_SEC_CALIB_8BIT
#include "ExMGslT2_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define ExMGslT2_START_SEC_CALIB_BOOLEAN
#include "ExMGslT2_MemMap.h"

extern CONST(Boolean, EXMGSLT2_CALIB) EXMGSLT2_ACTIVE_BYP_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bAcvEGRHPCtl_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bAcvExoInjCutOffFil_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bCalcPresRvs_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bEnaEthRatDft_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bExoCutInj_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bInhManTNearTWC_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bPresFlt_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSelMapUndHoPipe1_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSelMapUndHoPipe2_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSelMapUndHoPipe3_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSelMapUndHoPipe4_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSelTCalcPipe1_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSelTCalcPipe2_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSelTCalcPipe3_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSelTCalcPipe4_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSwitchTAirUndHo_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bSwitchTWallPipe_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bTEgFlt_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bThdTWCNoLiOffTSel_C;
extern CONST(Boolean, EXMGSLT2_CALIB) ExM_bTrbActEstimPresent_C;

#define ExMGslT2_STOP_SEC_CALIB_BOOLEAN
#include "ExMGslT2_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define ExMGslT2_START_SEC_CARTO_8BIT
#include "ExMGslT2_MemMap.h"

extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facAdFanFSFopTNearTWC1_T[8];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facAdFanFSFopTNearTWC2_T[8];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facAdFanFSFopTNearTWC3_T[8];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facAdFanTNearTWC1_T[8];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facAdFanTNearTWC3_T[8];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facAdFan_TNearTWC2_T[8];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facCorRatMix_T[8];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facEthCor_T[8];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facFSFopTNearTWC1_M[8][3];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facFSFopTNearTWC2_M[8][3];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facFSFopTNearTWC3_M[8][3];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facTNearTWC1_M[8][3];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facTNearTWC2_M[8][3];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_facTNearTWC3_M[8][3];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rMfTbrActr_M[20][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMaxExMax_M[16][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMaxExMid_M[16][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMaxExMin_M[16][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMidExMax_M[16][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMidExMid_M[16][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMidExMin_M[16][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMinExMax_M[16][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMinExMid_M[16][18];
extern CONST(UInt8, EXMGSLT2_CARTO) ExM_rPresInMinExMin_M[16][18];

#define ExMGslT2_STOP_SEC_CARTO_8BIT
#include "ExMGslT2_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define ExMGslT2_START_SEC_INTERNAL_VAR_32BIT
#include "ExMGslT2_MemMap.h"

extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_agCkExDeltaMaxMid_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_agCkExDeltaMidMin_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_agCkInDeltaMaxMid_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_agCkInDeltaMidMin_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_cppEg;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_cppMassTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_effTrb;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facClsExVlvMidMax_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facClsExVlvMinMid_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facEthCor;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExgUndHo;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExgUndHo1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExgUndHo2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExgUndHo3;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExgUndHo4;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExtExg;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExtExg1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExtExg2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExtExg3;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExtExg4;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facExtExgTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facFltPres_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facFltT_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facItExgOverMf;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facItExgOverMf1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facItExgOverMf2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facItExgOverMf3;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facItExgOverMf4;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facJHeatWall;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facJHeatWall1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facJHeatWall2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facJHeatWall3;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facJHeatWall4;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facMassFlowLd1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facMassFlowLd2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facNormMfTrb_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facOpInVlvMidMax_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facOpInVlvMinMid_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facPresAirExt1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facPresAirExt2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facPresLossPipeCal;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facPresLossPipeCal1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facPresLossPipeCal2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facPresLossPipeCal3;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facPresLossPipeCal4;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facPresLossTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facRatMixtTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facSatClsExVlvMidMax;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facSatClsExVlvMinMid;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facSatOpInVlvMidMax;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facSatOpInVlvMinMid;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facTEgSqrtIvs1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facTEgSqrtIvs2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facTNearTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facTPresLossPipeCal;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facTPresLossPipeCal1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facTPresLossPipeCal2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facTPresLossPipeCal3;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_facTPresLossPipeCal4;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfEgTrbNorm;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfTbrActrEstimWoutCor_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfTbrActrEstim_posnWgMainMdl;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfTbrActrEstim_posnWgOpMdl;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfTrbEstimSatRef;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfTrbEstimSat_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfTrbEstimWoutSat_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfTrbTot_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfWgEstimRef;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_mfWgEstim_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pDs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pDsBs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pInp;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pOut;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pOxCatUs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pPipeUs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pTrbUs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pUs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pUsPrev;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pVoidUs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgFltPrev[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgInter[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgInterPrev[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgPrev[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_01_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_02_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_03_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_04_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_05_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_06_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_07_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_08_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_09_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_10_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_11_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_pEgRaw_12_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgFltPrev[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgInter[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgInterPrev[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgOxC[3];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgOxCPrev[3];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgOxC_01_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgOxC_02_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgOxC_03_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgPrev[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_01_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_02_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_03_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_04_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_05_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_06_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_07_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_08_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_09_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_10_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_11_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tEgRaw_12_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tExMnfEstimCylPrev[6];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWallInter[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWallInterPrev[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWallPrev[12];
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_01_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_02_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_03_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_04_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_05_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_06_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_07_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_08_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_09_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_10_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_11_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_prm_tWall_12_IRV_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pwrCnvcTWC_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pwrExoTWC_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pwrSumTWC_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pwrThermo_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_pwrTrfHeatTWC_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rAirLdCorTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rEgTotLdCor_nEng;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rEgTotLd_nEng_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rEgTrbLdCor_nEng;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rEgTrbLd_nEng_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rIgSpEfcFil;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rMixtInp;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMax;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMax1_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMax2_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMid;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMid1_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMid2_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMin;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMin1_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresClsExVlvMin2_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresDsOverUs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresExMnf;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresExMnf_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMaxExMax;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMaxExMid;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMaxExMin;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMidExMax;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMidExMid;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMidExMin;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMinExMax;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMinExMid;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_rPresInMinExMin;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tAirNearTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tAirUndHo;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tCorIgEff;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tCorPresLossTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tDeltaTTWC_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tDsPrev;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgBasTrbOut;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgInp;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgInpPrev;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgOut;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgOutOxC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgOutPrev;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgOxCOutPrev;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgOxCatOut;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgPipeOut;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgTrbOut;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgTrbOutWoutLoss;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tEgVoidOut;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoInjCutOff;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWC;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCAfsWoutScv;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCLiOffNotDone;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCWiScv;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCWiScvCorOpt2_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCWiScvEthOpt2_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCWiScvGslOpt2_MP;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCWiScvOpt1;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCWiScvOpt2;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tExoTWCWoutScv;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tTWCLiOffThd;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tTWCMv;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tUs;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tUsPrev;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tWall;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tWallOxCat;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tWallPipe;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tWallPrev;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tWallTrb;
extern VAR(Float32, EXMGSLT2_INTERNAL_VAR) ExM_tWallVoid;

#define ExMGslT2_STOP_SEC_INTERNAL_VAR_32BIT
#include "ExMGslT2_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define ExMGslT2_START_SEC_INTERNAL_VAR_8BIT
#include "ExMGslT2_MemMap.h"

extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_noIdxOxC;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_noIdxOxCPrev;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_noIdxPres;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_noIdxPresPrev;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_noIdxT;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_noIdxTPrev;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stElement_01_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stElement_02_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stElement_03_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stElement_04_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stElement_05_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stElement_06_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stElement_07_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stElement_08_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stNbTypElement_01_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stNbTypElement_02_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stNbTypElement_03_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stNbTypElement_04_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stNbTypElement_05_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stNbTypElement_06_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stNbTypElement_07_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_prm_stNbTypElement_08_IRV_MP;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_stElementPres;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_stElementT;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_stNbTypElementPres;
extern VAR(UInt8, EXMGSLT2_INTERNAL_VAR) ExM_stNbTypElementT;

#define ExMGslT2_STOP_SEC_INTERNAL_VAR_8BIT
#include "ExMGslT2_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define ExMGslT2_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ExMGslT2_MemMap.h"

extern VAR(Boolean, EXMGSLT2_INTERNAL_VAR) ExM_bAcvExoTWCWiScv;
extern VAR(Boolean, EXMGSLT2_INTERNAL_VAR) ExM_bExoInjCutOff;
extern VAR(Boolean, EXMGSLT2_INTERNAL_VAR) ExM_bSelTCalc;
extern VAR(Boolean, EXMGSLT2_INTERNAL_VAR) ExM_bSelTCalc1;
extern VAR(Boolean, EXMGSLT2_INTERNAL_VAR) ExM_bSelTCalc2;
extern VAR(Boolean, EXMGSLT2_INTERNAL_VAR) ExM_bSelTCalc3;
extern VAR(Boolean, EXMGSLT2_INTERNAL_VAR) ExM_bSelTCalc4;

#define ExMGslT2_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ExMGslT2_MemMap.h"
#endif                                 /* RTW_HEADER_ExMGslT2_private_h_ */

/*-------------------------------- end of file -------------------------------*/
