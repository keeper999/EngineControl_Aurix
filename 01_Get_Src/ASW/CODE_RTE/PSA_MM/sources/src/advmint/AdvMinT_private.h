/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMinT                                                 */
/* !Description     : AdvMinT Software Component                              */
/*                                                                            */
/* !Module          : AdvMinT                                                 */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AdvMinT_private.h                                       */
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
/*   Model name       : AdvMinT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMinT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M02-AdvMinT/5-S$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   23 Oct 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvMinT_private_h_
#define RTW_HEADER_AdvMinT_private_h_
#include "Std_Types.h"
#include "AdvMinT_types.h"
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
#define AdvMinT_START_SEC_CODE
#include "AdvMinT_MemMap.h"

extern void RE_AdvMinT_005_MSE_Start(void);
extern void RE_AdvMinT_005_MSE(void);
extern void RE_AdvMinT_006_DRE_Start(void);
extern void RE_AdvMinT_006_DRE(void);
extern void RE_AdvMinT_008_DRE_Start(void);
extern void RE_AdvMinT_008_DRE(void);
extern void RE_AdvMinT_001_MSE(void);
extern void RE_AdvMinT_002_DRE_Start(void);
extern void RE_AdvMinT_002_DRE(void);
void AdvMinT_ASYNC1(int controlPortIdx);
void AdvMinT_ASYNC2(int controlPortIdx);
void AdvMinT_ASYNC3(int controlPortIdx);
void AdvMinT_ASYNC4(int controlPortIdx);

#define AdvMinT_STOP_SEC_CODE
#include "AdvMinT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_16BIT" */
#define AdvMinT_START_SEC_CALIB_16BIT
#include "AdvMinT_MemMap.h"

extern CONST(UInt16, ADVMINT_CALIB) EngM_rAirLdCor_A[12];
extern CONST(UInt16, ADVMINT_CALIB) FARSp_rMixtAgIgMinProtRef_C;
extern CONST(UInt16, ADVMINT_CALIB) IgSys_agIgMinDrivIncOfs_C;
extern CONST(UInt16, ADVMINT_CALIB) IgSys_agIgMinThermoDecOfs_C;
extern CONST(UInt16, ADVMINT_CALIB) IgSys_agIgMinThermoIncOfs_C;
extern CONST(UInt16, ADVMINT_CALIB) IgSys_nEngMinStrt_A[16];
extern CONST(UInt16, ADVMINT_CALIB) IgSys_nEng_Cor_A[6];
extern CONST(UInt16, ADVMINT_CALIB) IgSys_rAirLdCor_Cor_A[7];
extern CONST(UInt16, ADVMINT_CALIB) IgSys_rMixt_facAgIgMinProt_A[11];
extern CONST(SInt16, ADVMINT_CALIB) IgSys_tCoAgIgMinX_A[8];
extern CONST(SInt16, ADVMINT_CALIB) IgSys_tCoMes_A[16];
extern CONST(UInt16, ADVMINT_CALIB) IgSys_tExMaxASR_C;
extern CONST(UInt16, ADVMINT_CALIB) IgSys_tExMax_C;

#define AdvMinT_STOP_SEC_CALIB_16BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define AdvMinT_START_SEC_CARTO_16BIT
#include "AdvMinT_MemMap.h"

extern CONST(SInt16, ADVMINT_CARTO) IgSys_agIgColdCor_M[16][16];
extern CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinDriv_M[16][16];
extern CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinExVlvMax_M[16][16];
extern CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinExVlvMin_M[16][16];
extern CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinInVlvMax_M[16][16];
extern CONST(SInt16, ADVMINT_CARTO) IgSys_agIgMinInVlvMin_M[16][16];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_agIgMinStrtDecOfs_T[8];
extern CONST(SInt16, ADVMINT_CARTO) IgSys_agIgNotCorMinThdReac_M[16][16];
extern CONST(SInt16, ADVMINT_CARTO) IgSys_agIgNotCorMinThd_M[16][16];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinAOSAcv_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinAOSInh_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinESPAcv_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinESPInh_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinGcAcv_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinGcInh_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinLimSurgeAcv_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinLimSurgeInh_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinPrevAcv_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyAdvMinPrevInh_M[6][7];
extern CONST(UInt16, ADVMINT_CARTO) IgSys_tiDlyIgLim_T[7];

#define AdvMinT_STOP_SEC_CARTO_16BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define AdvMinT_START_SEC_CALIB_8BIT
#include "AdvMinT_MemMap.h"

extern CONST(UInt8, ADVMINT_CALIB) IgSys_agCkVlvEstim_A[9];
extern CONST(UInt8, ADVMINT_CALIB) IgSys_agIgLimMinKnk_B;
extern CONST(UInt8, ADVMINT_CALIB) IgSys_agIgLimMinRef_B;
extern CONST(UInt8, ADVMINT_CALIB) IgSys_agIgMinCmb_B;
extern CONST(UInt8, ADVMINT_CALIB) IgSys_agIgMinThermo_B;
extern CONST(UInt8, ADVMINT_CALIB) IgSys_agIgMin_B;
extern CONST(UInt8, ADVMINT_CALIB) IgSys_noGear6_A[7];
extern CONST(UInt8, ADVMINT_CALIB) IgSys_tAgIgMinDriv_C;
extern CONST(UInt8, ADVMINT_CALIB) InjSys_noCylCutOffInh_C;

#define AdvMinT_STOP_SEC_CALIB_8BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AdvMinT_START_SEC_CALIB_BOOLEAN
#include "AdvMinT_MemMap.h"

extern CONST(Boolean, ADVMINT_CALIB) ADVMINT_ACTIVE_BYP_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinCurAAMin_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinESPASR_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinLimSurge_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinPrevAAMin_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAdvMinSIP_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bAcvAgIgMinDrivOfs_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bFlexMinCmbOfs_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bFlexMinThermoOfs_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bGasMinCmbOfs_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bGasMinThermoOfs_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_bRichLoTqAuth_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_idxAdvMinESPASR_C;
extern CONST(Boolean, ADVMINT_CALIB) IgSys_idxAdvMinSIP_C;

#define AdvMinT_STOP_SEC_CALIB_BOOLEAN
#include "AdvMinT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define AdvMinT_START_SEC_CARTO_8BIT
#include "AdvMinT_MemMap.h"

extern CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinCANESP_M[16][12];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinCANSIP_M[16][12];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinGsl_M[16][16];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinKnk_M[16][16];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_agIgMinStrt_M[16][16];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_facAgIgMinProt_T[11];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_facMinDriv_M[16][16];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_rAdvMinExVlvMax_T[9];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_rAdvMinExVlvMin_T[9];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_rAdvMinInVlvMax_T[9];
extern CONST(UInt8, ADVMINT_CARTO) IgSys_rAdvMinInVlvMin_T[9];

#define AdvMinT_STOP_SEC_CARTO_8BIT
#include "AdvMinT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define AdvMinT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvMinT_MemMap.h"

extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinCmbWoutOfs;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinExVlvMax;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinExVlvMin;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinInVlvMax;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinInVlvMin;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgMinThermoWoutOfs;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgWrmMin;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_agIgWrmUpCor;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_rAdvMinExVlvMax;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_rAdvMinExVlvMin;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_rAdvMinInVlvMax;
extern VAR(Float32, ADVMINT_INTERNAL_VAR) IgSys_rAdvMinInVlvMin;

#define AdvMinT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define AdvMinT_START_SEC_INTERNAL_VAR_16BIT
#include "AdvMinT_MemMap.h"

extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agCkDeltaExVlv3_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agCkDeltaExVlv4_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agCkDeltaInVlv3_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agCkDeltaInVlv4_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgColdCor_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgMinCmbWiFlexCor_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgMinDriv_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgMinThermoWiFlex_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgNotCorMinThdReac_MP;
extern VAR(SInt16, ADVMINT_INTERNAL_VAR) IgSys_agIgNotCorMinThd_MP;
extern VAR(UInt16, ADVMINT_INTERNAL_VAR) IgSys_rMixtAgIgMinLim_MP;

#define AdvMinT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define AdvMinT_START_SEC_INTERNAL_VAR_8BIT
#include "AdvMinT_MemMap.h"

extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgMinCmbWiCANSpcReq;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgMinDriv_IRV_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgMinStrt_IRV_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSlopDrivInc;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSlopStrtDec;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSlopThermoDec;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSlopThermoInc;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_agIgSpDriv_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_ctLimAdvReact_IRV_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_facAgIgMinProt_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_facMinDriv_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_rDeltaExVlv3_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_rDeltaExVlv4_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_rDeltaInVlv3_MP;
extern VAR(UInt8, ADVMINT_INTERNAL_VAR) IgSys_rDeltaInVlv4_MP;

#define AdvMinT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AdvMinT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvMinT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvMinT_MemMap.h"

extern VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_bAcvMinMgr;
extern VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_bDriv;
extern VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_bDriv_MP;
extern VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_bExThermoProt;
extern VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_prmInhThermoProt_MP[5];
extern VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_prmTimerIn1_MP[5];
extern VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_prmTimerOut1_MP[5];
extern VAR(Boolean, ADVMINT_INTERNAL_VAR) IgSys_prmTimerOut2_MP[5];

#define AdvMinT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvMinT_MemMap.h"
#endif                                 /* RTW_HEADER_AdvMinT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
