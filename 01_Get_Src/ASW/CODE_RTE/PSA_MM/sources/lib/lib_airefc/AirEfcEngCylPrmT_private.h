/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirEfcEngCylPrmT                                        */
/* !Description     : AirEfcEngCylPrmT Software Component                     */
/*                                                                            */
/* !Module          : AirEfcEngCylPrmT                                        */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AirEfcEngCylPrmT_private.h                              */
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
/*   Model name       : AirEfcEngCylPrmT_AUTOSAR.mdl                          */
/*   Root subsystem   : /AirEfcEngCylPrmT                                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M04-AirEfcEngCyl$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   29 May 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AirEfcEngCylPrmT_private_h_
#define RTW_HEADER_AirEfcEngCylPrmT_private_h_
#include "Std_Types.h"
#include "AirEfcEngCylPrmT_types.h"
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
#define AirEfcEngCylPrmT_START_SEC_CODE
#include "AirEfcEngCylPrmT_MemMap.h"

extern void Subsystem(UInt16 rtu_In_Ext_nEngRef, Float32
                      rtu_In_EngM_agCkClsInVlvRef1, UInt16
                      rtu_In_InM_tAirUsInVlvEstimRef, UInt16 rtu_In_InM_pDsThr,
                      UInt8 rtu_In_EngM_noAcvMPVal, UInt16
                      rtu_In_InjSys_tFuRef, Float32
                      rtu_In_UsThrM_pAirExtEstimRef, UInt16
                      rtu_In_InThM_nEngCorRef, Float32
                      rtu_In_EngM_agCkOpInVlvRef1, Float32
                      rtu_In_EngM_agCkClsExVlvRef1, Float32
                      rtu_In_InM_pDsThrPred_facVlvOvl, Float32
                      rtu_In_ExM_pExMnfEstimRef, Float32
                      rtu_In_ExM_tExMnfEstimRef, Float32
                      rtu_In_AirEfc_facChrExpFilPrev, Float32
                      rtu_In_AirEfc_facChrExpScvFilPr, UInt16
                      rtu_In_InjSys_rlamEngCorReqRef, SInt16 rtu_In_Ext_tCoMes,
                      Float32 rtu_In_InjSys_agInj1BegRef, Float32
                      rtu_In_InjSys_agInj1EndRef, Float32 rtu_In_InjSys_mFu1Inj,
                      Float32 rtu_In_EngM_facCorOfsEfcRef, Float32
                      rtu_In_EngM_facCorSlopEfcRef, Float32
                      *rty_Out_AirEfc_rMassBurn, Float32
                      *rty_Out_AirEfc_rMassAirResi, Float32
                      *rty_Out_AirEfc_facChrExpScvFil, Float32
                      *rty_Out_AirEfc_facMassAirScv, Float32
                      *rty_Out_AirEfc_agInj1End, Float32
                      *rty_Out_AirEfc_rFuMassInj1InPha, Float32
                      *rty_Out_AirEfc_rDeltaLdInjPhaRe, Float32
                      *rty_Out_AirEfc_facTAirUsInVlv, Float32
                      *rty_Out_AirEfc_facTCo, Float32
                      *rty_Out_AirEfc_facCorAtmSlopEfc, Float32
                      *rty_Out_AirEfc_facCorBoostSlopE, Float32
                      *rty_Out_AirEfc_pBegCorBoostSlop, Float32
                      *rty_Out_AirEfc_facSlopEfc, Float32
                      *rty_Out_AirEfc_pDeltaCorSlopEfc, Float32
                      *rty_Out_AirEfc_facOfsEfc, Float32
                      *rty_Out_AirEfc_rMassAirScv, Float32
                      *rty_Out_AirEfc_pDsThrCorClsInVl, Float32
                      *rty_Out_AirEfc_tBurnCyl, Float32
                      *rty_Out_AirEfc_rVolCylClsInVlv, Float32
                      *rty_Out_AirEfc_facMassFlowLd, Float32
                      *rty_Out_AirEfc_facChrExpFil,
                      rtB_Subsystem_AirEfcEngCylPrmT *localB,
                      rtDW_Subsystem_AirEfcEngCylPrmT *localDW);
extern void OP_LibAirEfc_Start(void);

extern void Subsystem_o(UInt8 rtu_In_EngM_noAcvMPVal, Float32
  rtu_In_AirEfc_rMassBurn, Float32 rtu_In_AirEfc_rMassAirResi, Float32
  rtu_In_InM_concAir, UInt16 rtu_In_Ext_nEngRef, UInt16 rtu_In_InM_pDsThr,
  Float32 rtu_In_AirEfc_facSlopEfc, Float32 rtu_In_AirEfc_facOfsEfc, UInt16
  rtu_In_InM_tAirUsInVlvEstimRef, Float32 rtu_In_AirEfc_agInj1End, Float32
  rtu_In_EngM_agCkClsInVlvRef1, UInt16 rtu_In_InjSys_tFuRef, Float32
  rtu_In_AirEfc_rFuMassInj1InPha, Float32 rtu_In_AirEfc_tBurnCyl, Float32
  rtu_In_AirEfc_pDsThrCorClsInVlv, Float32 rtu_In_AirEfc_rVolCylClsInVlv,
  Float32 rtu_In_AirEfc_rMassAirScv, Float32 rtu_In_AirEfc_facMassFlowLd,
  Float32 *rty_Out_EngM_rItBurnRate, Float32 *rty_Out_EngM_tMixtCyl, Float32 *
  rty_Out_EngM_mAirScv, Float32 *rty_Out_EngM_tMixtCylGDI, Float32
  *rty_Out_EngM_rltMassAirScv, Float32 *rty_Out_EngM_rAirLd, Float32
  *rty_Out_EngM_rTotLdEx, Float32 *rty_Out_EngM_mfAirScv, Float32
  *rty_Out_EngM_mAir, Float32 *rty_Out_EngM_mfAir, Float32
  *rty_Out_EngM_mTotEx, Float32 *rty_Out_EngM_mfTotEx, Float32
  *rty_Out_EngM_mBurn, rtB_Subsystem_AirEfcEngCylPrm_l *localB,
  rtDW_Subsystem_AirEfcEngCylPr_p *localDW);
extern void OP_LibEngCylPrm_Start(void);

extern void Subsystem_a(UInt8 rtu_In_EngM_noAcvVlvMPVal, UInt32
  rtu_In_EOM_tiEngRun, SInt16 rtu_In_Ext_tCoStrtMes, Float32
  rtu_In_EngM_dstInVlvClrCor, Float32 rtu_In_AFA_agCkOpInVlvOfs, Float32
  rtu_In_EngM_agCkOpInVlvRef0, Float32 rtu_In_EngM_dstExVlvClrCor, Float32
  rtu_In_AFA_agCkClsExVlvOfs, Float32 rtu_In_EngM_agCkClsExVlvRef0, Float32
  *rty_Out_EngM_agCkOpInVlvRef1, Float32 *rty_Out_EngM_agCkClsInVlvRef1,
  Float32 *rty_Out_EngM_agCkClsInVlvRef0, Float32
  *rty_Out_EngM_agCkClsExVlvRef1, Float32 *rty_Out_EngM_agCkOpExVlvRef1,
  Float32 *rty_Out_EngM_agCkOpExVlvRef0, Float32
  *rty_Out_EngM_agCkClsExVlvOfsRef, Float32 *rty_Out_EngM_agCkOpInVlvOfsRef0,
  rtDW_Subsystem_AirEfcEngCylPr_h *localDW);


#define AirEfcEngCylPrmT_STOP_SEC_CODE
#include "AirEfcEngCylPrmT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define AirEfcEngCylPrmT_START_SEC_INTERNAL_VAR_32BIT
#include "AirEfcEngCylPrmT_MemMap.h"

extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_agCkInj_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_agCkVlvOvlp_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_agCk_facTDC_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facAirScv1_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facAirScv2_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facAirScv_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR)
  AirEfc_facChgCorSlopEfcMax_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR)
  AirEfc_facChgCorSlopEfcMin_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facChgCorSlopEfc_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facCorAtmSlopEfc_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facCorBoostSlopEfc_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facCorMassBurnRg_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facCorSlopEfc_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facMassFlowCor_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTAirUsInVlv_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTBurnCyl_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTCo_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTExSqrt_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTInSqrt_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_mfAirScvRed_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_mfBurnRspgRedBas_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_mfBurnRspgRedCor_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rFuStmMass_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassAirScvTot_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR)
  AirEfc_rMassBurnRgBoostCorSat_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR)
  AirEfc_rMassBurnRgBoostCor_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRgCorSat_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRgCor_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRgTot_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRspgTot_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRspg_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurn_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rPresDsThr_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rPresEngScv_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rPresEng_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rPresExMnf_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rVolCyl_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_SumcppBurnMass_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_SumcppMass_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_agCkClsExVlvClrOfs_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_agCkClsInVlvClrOfs_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_agCkOpExVlvClrOfs_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_agCkOpInVlvClrOfs_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_facAirtMixt_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_facFuSteam_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_facFutMixt_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_rTotLdExMax_MP;
extern VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_rTotLd_MP;

#define AirEfcEngCylPrmT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AirEfcEngCylPrmT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define AirEfcEngCylPrmT_START_SEC_INTERNAL_VAR_16BIT
#include "AirEfcEngCylPrmT_MemMap.h"

extern VAR(SInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_agCkPosnVlvOvlp_MP;
extern VAR(UInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_nEngScv_MP;
extern VAR(UInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_nEngSlop_MP;
extern VAR(UInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_dstExVlvClr_MP;
extern VAR(UInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_dstInVlvClr_MP;

#define AirEfcEngCylPrmT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AirEfcEngCylPrmT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AirEfcEngCylPrmT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AirEfcEngCylPrmT_MemMap.h"

extern VAR(Boolean, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_bMassBurnRgCor_MP;

#define AirEfcEngCylPrmT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AirEfcEngCylPrmT_MemMap.h"
#endif                                 /* RTW_HEADER_AirEfcEngCylPrmT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
