/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvPrevKnkT                                             */
/* !Description     : AdvPrevKnkT Software Component                          */
/*                                                                            */
/* !Module          : AdvPrevKnkT                                             */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AdvPrevKnkT_private.h                                   */
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
/*   Model name       : AdvPrevKnkT_AUTOSAR.mdl                               */
/*   Root subsystem   : /AdvPrevKnkT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M05-AdvPrevKnkT$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   11 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvPrevKnkT_private_h_
#define RTW_HEADER_AdvPrevKnkT_private_h_
#include "Std_Types.h"
#include "AdvPrevKnkT_types.h"
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
#define AdvPrevKnkT_START_SEC_CODE
#include "AdvPrevKnkT_MemMap.h"

extern void RE_AdvPrevKnkT_001_MSE_Start(void);
extern void RE_AdvPrevKnkT_001_MSE(void);
extern void RE_AdvPrevKnkT_002_Start(void);
extern void RE_AdvPrevKnkT_002(void);
void AdvPrevKnkT_ASYNC1(int controlPortIdx);

#define AdvPrevKnkT_STOP_SEC_CODE
#include "AdvPrevKnkT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CARTO_16BIT" */
#define AdvPrevKnkT_START_SEC_CARTO_16BIT
#include "AdvPrevKnkT_MemMap.h"

extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_AirLdDet_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_PrevDynX_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_PrevStatX_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_facFilAirldDynX_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_facFilDeltaAir_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_nEng_noDlyCalcAirLd_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_pAirExtMes_PrevStat_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_pDsThr_facFilAirLdDynY_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_rAirLdCor_PrevDynY_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_rAirLdCor_PrevStatY_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_rDeltaAirLdDynThd_T[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_rLamEngCorReq_PrevStaY_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_spdVeh_PrevDynY_A[6];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_tAirUsInVlv_PrevDynY_A[16];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_tAirUsInVlv_PrevStatY_A[9];
extern CONST(SInt16, ADVPREVKNKT_CARTO) IgSys_tCoMes_PrevStatX_A[9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_tRefTAirUsInVlvEstim_M[9][9];
extern CONST(UInt16, ADVPREVKNKT_CARTO) IgSys_tiAirLdDynDet_T[9];

#define AdvPrevKnkT_STOP_SEC_CARTO_16BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define AdvPrevKnkT_START_SEC_CALIB_16BIT
#include "AdvPrevKnkT_MemMap.h"

extern CONST(UInt16, ADVPREVKNKT_CALIB) IgSys_agIgPrevDynIncOfs_C;
extern CONST(UInt16, ADVPREVKNKT_CALIB) IgSys_pAirExtMesDft_C;
extern CONST(UInt16, ADVPREVKNKT_CALIB) IgSys_rAirLdClc_B;
extern CONST(SInt16, ADVPREVKNKT_CALIB) IgSys_tDifTAirUsInVlvEstim_B;

#define AdvPrevKnkT_STOP_SEC_CALIB_16BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define AdvPrevKnkT_START_SEC_CALIB_8BIT
#include "AdvPrevKnkT_MemMap.h"

extern CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_agIgKnkPrevOfs_B;
extern CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_agIgMaxPrevKnkOfsSat_C;
extern CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_agIgMinPrevKnkOfsSat_C;
extern CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_facFilDeltaAirLdDyn_C;
extern CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_idxModRatAirLdCalc_C;
extern CONST(UInt8, ADVPREVKNKT_CALIB) IgSys_tCoMesDft_C;

#define AdvPrevKnkT_STOP_SEC_CALIB_8BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define AdvPrevKnkT_START_SEC_CARTO_8BIT
#include "AdvPrevKnkT_MemMap.h"

extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevDynOfs_M[9][9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevEGROfs_M[9][9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevStatLamOfs_M[9][9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevStatPOfs_M[9][9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_agIgPrevStatTOfs_M[9][9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_facFil1DeltaAirLdDyn_T[9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_facFil2DeltaAirLdDyn_T[9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_facFilAirLdDyn_M[9][9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_knkAdp_PrevDynX_A[9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_noDlyCalcAirLdDyn_T[9];
extern CONST(UInt8, ADVPREVKNKT_CARTO) IgSys_noEgdGearCord_PrevDynX_A[6];
extern CONST(SInt8, ADVPREVKNKT_CARTO) IgSys_rCorPrevDyn1Ofs_M[9][16];
extern CONST(SInt8, ADVPREVKNKT_CARTO) IgSys_rCorPrevDyn2Ofs_M[6][6];
extern CONST(SInt8, ADVPREVKNKT_CARTO) IgSys_rCorPrevStatPOfs_T[9];
extern CONST(SInt8, ADVPREVKNKT_CARTO) IgSys_rCorPrevStatTOfs_M[9][9];

#define AdvPrevKnkT_STOP_SEC_CARTO_8BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AdvPrevKnkT_START_SEC_CALIB_BOOLEAN
#include "AdvPrevKnkT_MemMap.h"

extern CONST(Boolean, ADVPREVKNKT_CALIB) ADVPREVKNKT_ACTIVE_BYP_C;
extern CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bAcvAirLdDynDet_C;
extern CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bAcvAirLdDynPrevDet_C;
extern CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bAirLdDynDet_B;
extern CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bModDeltaAirLdDet_C;
extern CONST(Boolean, ADVPREVKNKT_CALIB) IgSys_bSelFilTypAirLd_C;

#define AdvPrevKnkT_STOP_SEC_CALIB_BOOLEAN
#include "AdvPrevKnkT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvPrevKnkT_MemMap.h"

extern VAR(Float32, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevDynCalcOfs;
extern VAR(Float32, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevDynSlopDrivInc;
extern VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rDeltaAirLdDyn;
extern VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rDeltaAirLdMod1_MP;
extern VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rDeltaAirLdMod2_MP;
extern VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rFil1DeltaAir_MP;
extern VAR(UInt32, ADVPREVKNKT_INTERNAL_VAR) IgSys_rFil2DeltaAir_MP;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_16BIT
#include "AdvPrevKnkT_MemMap.h"

extern VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_rAirLdClcRef;
extern VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_rAirLdDynWoutFil;
extern VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_rCorPrevStatPOfs_MP;
extern VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_rCorPrevStatTOfs_MP;
extern VAR(UInt16, ADVPREVKNKT_INTERNAL_VAR) IgSys_tiAirLdDynDet;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_8BIT
#include "AdvPrevKnkT_MemMap.h"

extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevDynOfs;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevDynOfsCor_MP;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevEGROfs;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatLamOfs;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatOfs;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatPOfs;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatPOfs_MP;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatTOfs;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_agIgPrevStatTOfs_MP;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_facFilAirLdDyn;
extern VAR(UInt8, ADVPREVKNKT_INTERNAL_VAR) IgSys_noDlyClcAirLdDyn;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AdvPrevKnkT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvPrevKnkT_MemMap.h"

extern VAR(Boolean, ADVPREVKNKT_INTERNAL_VAR) IgSys_bAcvAirLdDynDet2_MP;
extern VAR(Boolean, ADVPREVKNKT_INTERNAL_VAR) IgSys_bAcvKnkPrev;
extern VAR(Boolean, ADVPREVKNKT_INTERNAL_VAR) IgSys_bAirLdDynDetWoutTmr;
extern VAR(Boolean, ADVPREVKNKT_INTERNAL_VAR) IgSys_bAirLdDynPrevDynDet;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvPrevKnkT_MemMap.h"
#endif                                 /* RTW_HEADER_AdvPrevKnkT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
