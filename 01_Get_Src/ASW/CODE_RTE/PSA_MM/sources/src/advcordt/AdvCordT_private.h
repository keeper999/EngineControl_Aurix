/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvCordT                                                */
/* !Description     : AdvCordT Software Component                             */
/*                                                                            */
/* !Module          : AdvCordT                                                */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AdvCordT_private.h                                      */
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
/*   Model name       : AdvCordT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /AdvCordT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M07-AdvCordT/5-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvCordT_private_h_
#define RTW_HEADER_AdvCordT_private_h_
#include "Std_Types.h"
#include "AdvCordT_types.h"
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
#define AdvCordT_START_SEC_CODE
#include "AdvCordT_MemMap.h"

extern void AdvCordT_F01_IgAdvMap(void);
extern void RE_AdvCordT_001_MSE(void);
extern void AdvCordT_F01_AdvCordT_Init(void);
extern void RE_AdvCordT_003_MSE(void);
extern void AdvCordT_F02_IgAdvMap(void);
extern void RE_AdvCordT_002_DRE(void);
extern void F03_coordination_Avance_maxi_tr(void);
extern void RE_AdvCordT_007_DRE(void);
extern void AdvCo_F04_Calcul_avance_running(void);
extern void RE_AdvCordT_005_DRE(void);
void AdvCordT_ASYNC1(int controlPortIdx);
void AdvCordT_ASYNC2(int controlPortIdx);
void AdvCordT_ASYNC3(int controlPortIdx);
void AdvCordT_ASYNC4(int controlPortIdx);
void AdvCordT_ASYNC5(int controlPortIdx);

#define AdvCordT_STOP_SEC_CODE
#include "AdvCordT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_16BIT" */
#define AdvCordT_START_SEC_CALIB_16BIT
#include "AdvCordT_MemMap.h"

extern CONST(UInt16, ADVCORDT_CALIB) IgSys_agIgOfsTest_C;
extern CONST(SInt16, ADVCORDT_CALIB) IgSys_agIgSTTEsOfsDown_C;
extern CONST(SInt16, ADVCORDT_CALIB) IgSys_agIgSTTEsOfsUp_C;
extern CONST(SInt16, ADVCORDT_CALIB) IgSys_agIgTCoThdOfs_C;
extern CONST(SInt16, ADVCORDT_CALIB) IgSys_pDsThrMesRef_C;

#define AdvCordT_STOP_SEC_CALIB_16BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define AdvCordT_START_SEC_CARTO_16BIT
#include "AdvCordT_MemMap.h"

extern CONST(UInt16, ADVCORDT_CARTO) IgSys_nCkFilTestY_A[16];
extern CONST(UInt16, ADVCORDT_CARTO) IgSys_rAirLdTestX_A[16];

#define AdvCordT_STOP_SEC_CARTO_16BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define AdvCordT_START_SEC_CALIB_8BIT
#include "AdvCordT_MemMap.h"

extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgColdOfs_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgDeltaMaxThd_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgDynIgSpEfc_B;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgLimKnkMax_B;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgLimKnkMin_B;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgLimKnkMv_B;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgMaxMod_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgMax_B;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgSpNxt_B;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgSpWoutKnkDet_B;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgSp_B;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl1_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl2_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl3_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl4_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl5_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgTestCyl6_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_agIgWarmOfs_C;
extern CONST(UInt8, ADVCORDT_CALIB) IgSys_noAdvETBMod_C;

#define AdvCordT_STOP_SEC_CALIB_8BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AdvCordT_START_SEC_CALIB_BOOLEAN
#include "AdvCordT_MemMap.h"

extern CONST(Boolean, ADVCORDT_CALIB) ADVCORDT_ACTIVE_BYP_C;
extern CONST(Boolean, ADVCORDT_CALIB) IgSys_bAirLdSel_C;
extern CONST(Boolean, ADVCORDT_CALIB) IgSys_bKnkAdvETB_C;
extern CONST(Boolean, ADVCORDT_CALIB) IgSys_bSelAgIgCordTyp_C;

#define AdvCordT_STOP_SEC_CALIB_BOOLEAN
#include "AdvCordT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define AdvCordT_START_SEC_CARTO_8BIT
#include "AdvCordT_MemMap.h"

extern CONST(UInt8, ADVCORDT_CARTO) IgSys_agIgTest_M[16][16];
extern CONST(UInt8, ADVCORDT_CARTO) IgSys_prm_agIgLimKnk_B[6];
extern CONST(UInt8, ADVCORDT_CARTO) IgSys_prm_agIgSpCyl_B[6];

#define AdvCordT_STOP_SEC_CARTO_8BIT
#include "AdvCordT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define AdvCordT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvCordT_MemMap.h"

extern VAR(Float32, ADVCORDT_INTERNAL_VAR) IgSys_agIgMaxAfterStrt;
extern VAR(Float32, ADVCORDT_INTERNAL_VAR) IgSys_agIgMaxAfterStrtOfs;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define AdvCordT_START_SEC_INTERNAL_VAR_16BIT
#include "AdvCordT_MemMap.h"

extern VAR(UInt16, ADVCORDT_INTERNAL_VAR) IgSys_agIgOfsTest_IRV_MP;
extern VAR(UInt16, ADVCORDT_INTERNAL_VAR) IgSys_rAirLdSel_MP;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AdvCordT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvCordT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvCordT_MemMap.h"

extern VAR(Boolean, ADVCORDT_INTERNAL_VAR) IgSys_bSelAgIgOfs_MP;
extern VAR(Boolean, ADVCORDT_INTERNAL_VAR) IgSys_bSelAgIgTarThd_MP;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvCordT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define AdvCordT_START_SEC_INTERNAL_VAR_8BIT
#include "AdvCordT_MemMap.h"

extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgCord1Next_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgCord2Next_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgCord3Next_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgDeltaMaxAfterStrt_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCyl1_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCylMv_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCylSel1_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCylSel_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgKnkDetOfsCyl_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgLimKnkCyl1_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgLimKnkCyl_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgMaxAgIgMinMax1_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgMaxWiPrevAdpCyl_IRV_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgOfs;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgOfsPrev_IRV_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgSpSel1_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgSpSel_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgTestCyl1_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgTestCyl_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_agIgTest_IRV_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgCord1_MP[3];
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgCord2_MP[3];
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgCord3_MP[3];
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgKnkSatMax_MP[6];
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgKnkSatMin_MP[6];
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgMaxAgIgMinMax_MP[3];
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgMaxCord_MP[3];
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_001_IRV_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_002_IRV_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_003_IRV_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_004_IRV_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_005_IRV_MP;
extern VAR(UInt8, ADVCORDT_INTERNAL_VAR) IgSys_prm_agIgTestCyl_006_IRV_MP;

#define AdvCordT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AdvCordT_MemMap.h"
#endif                                 /* RTW_HEADER_AdvCordT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
