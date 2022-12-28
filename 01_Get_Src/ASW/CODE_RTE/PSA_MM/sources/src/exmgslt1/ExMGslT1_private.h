/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : ExMGslT1                                                */
/* !Description     : ExMGslT1 Software Component                             */
/*                                                                            */
/* !Module          : ExMGslT1                                                */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : ExMGslT1_private.h                                      */
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
/*   Model name       : ExMGslT1_AUTOSAR.mdl                                  */
/*   Root subsystem   : /ExMGslT1                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M06-ExMGslT1/5-S$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   05 Jan 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_ExMGslT1_private_h_
#define RTW_HEADER_ExMGslT1_private_h_
#include "Std_Types.h"
#include "ExMGslT1_types.h"
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
#define ExMGslT1_START_SEC_CODE
#include "ExMGslT1_MemMap.h"

extern void RE_ExMGslT1_005_MSE(void);
extern void RE_ExMGslT1_004_MSE_Start(void);
extern void RE_ExMGslT1_004_MSE(void);
extern void RE_ExMGslT1_003_TEV_Start(void);
extern void RE_ExMGslT1_003_TEV(void);
extern void RE_ExMGslT1_002_TEV_Start(void);
extern void RE_ExMGslT1_002_TEV(void);
void ExMGslT1_ASYNC1(int controlPortIdx);
void ExMGslT1_ASYNC2(int controlPortIdx);

#define ExMGslT1_STOP_SEC_CODE
#include "ExMGslT1_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define ExMGslT1_START_SEC_CALIB_32BIT
#include "ExMGslT1_MemMap.h"

extern CONST(UInt32, EXMGSLT1_CALIB) ExM_lamTot_B;

#define ExMGslT1_STOP_SEC_CALIB_32BIT
#include "ExMGslT1_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define ExMGslT1_START_SEC_CALIB_16BIT
#include "ExMGslT1_MemMap.h"

extern CONST(UInt16, EXMGSLT1_CALIB) ExM_PCIGas_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_facCorIgProtComp_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_facCorProtComp_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_facNEngTExStatAfs_T[16];
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_gmaInMixt_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_lamLeanLimPostOxGas_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_lamRichLimPostOxGas_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_mfAirIni_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_mfEgTot_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_mfSelMassFlowEgTot_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_molMassInMixt_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_molSelMolMassInMixt_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_nEngTExStatAfs_A[16];
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_pExMnfEstim_facVlvOvlp_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_prm_pExMnfEstimOvlpCyl_B[6];
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_rAfsGas_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_tExDyn_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_tExPostOxOfs_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_tExStatAfs_B;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_tSelTExDyn_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_wMassVlvHeatECoDown_C;
extern CONST(UInt16, EXMGSLT1_CALIB) ExM_wMassVlvHeatE_C;
extern CONST(SInt16, EXMGSLT1_CALIB) OvlpExP_agCkClsExVlvLimThd_C;
extern CONST(SInt16, EXMGSLT1_CALIB) OvlpExP_agCkClsExVlvMax_C;
extern CONST(SInt16, EXMGSLT1_CALIB) OvlpExP_agCkClsExVlvMid_C;
extern CONST(SInt16, EXMGSLT1_CALIB) OvlpExP_agCkClsExVlvMin_C;
extern CONST(SInt16, EXMGSLT1_CALIB) OvlpExP_agCkOpInVlvLimThd_C;
extern CONST(SInt16, EXMGSLT1_CALIB) OvlpExP_agCkOpInVlvMax_C;
extern CONST(SInt16, EXMGSLT1_CALIB) OvlpExP_agCkOpInVlvMid_C;
extern CONST(SInt16, EXMGSLT1_CALIB) OvlpExP_agCkOpInVlvMin_C;
extern CONST(UInt16, EXMGSLT1_CALIB) OvlpExP_facClsExVlvMidMaxEqu_C;
extern CONST(UInt16, EXMGSLT1_CALIB) OvlpExP_facClsExVlvMinMidEqu_C;
extern CONST(UInt16, EXMGSLT1_CALIB) OvlpExP_facOpInVlvMidMaxEqu_C;
extern CONST(UInt16, EXMGSLT1_CALIB) OvlpExP_facOpInVlvMinMidEqu_C;
extern CONST(UInt16, EXMGSLT1_CALIB) OvlpExP_nEngThdLdCorClc_C;
extern CONST(UInt16, EXMGSLT1_CALIB) OvlpExP_pExMnfOvlpIni_C;
extern CONST(UInt16, EXMGSLT1_CALIB) OvlpExP_rEgTotLdCor_nEngThd_C;

#define ExMGslT1_STOP_SEC_CALIB_16BIT
#include "ExMGslT1_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define ExMGslT1_START_SEC_CARTO_16BIT
#include "ExMGslT1_MemMap.h"

extern CONST(UInt16, EXMGSLT1_CARTO) ExM_PCICor_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkExCmMaxShiftEx_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkExCmMaxShiftIn_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkInCmMaxShiftEx_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkInCmMaxShiftIn_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkMaxOvlpEx_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkMaxOvlpIn_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkMidEx_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkMidIn_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkMinOvlpEx_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_agCkMinOvlpIn_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_cppEx_M[15][11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_cppIng_M[15][11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_facFlex_A[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_facMassFlowTotExCutOff_T[9];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_lamClcX_A[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_lamClcY_A[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_lamClc_A[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_lamLeanLimPostOxCor_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_lamRichLimPostOxCor_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_mfTotExCorY_A[9];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_mfTotExCor_A[9];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_molMassEx_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_molMassInMixt_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_nEngX_A[16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_rAfsCor_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_rAirY_A[16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_rDynIgSpEfcX_A[6];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_tAirRefX_A[15];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_tExCutOffStat_M[16][6];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_tExExCmMaxShift_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_tExInCmMaxShift_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_tExMaxOvlp_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_tExMid_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_tExMinOvlp_M[16][16];
extern CONST(UInt16, EXMGSLT1_CARTO) ExM_tExStatX_A[15];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_facInMidMaxAdjExMax_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_facInMidMaxAdjExMid_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_facInMidMax_A[11];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_facInMinMidAdjExMax_T[11];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_facInMinMid_A[11];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_nEngY_A[18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rEgTotLdCorX_A[16];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMaxExMax_M[16][18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMaxExMid_M[16][18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMaxExMin_M[16][18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMidExMax_M[16][18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMidExMid_M[16][18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMidExMin_M[16][18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMinExMax_M[16][18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMinExMid_M[16][18];
extern CONST(UInt16, EXMGSLT1_CARTO) OvlpExP_rPresInMinExMin_M[16][18];

#define ExMGslT1_STOP_SEC_CARTO_16BIT
#include "ExMGslT1_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define ExMGslT1_START_SEC_CALIB_8BIT
#include "ExMGslT1_MemMap.h"

extern CONST(UInt8, EXMGSLT1_CALIB) ExM_facPostOx_C;
extern CONST(UInt8, EXMGSLT1_CALIB) ExM_gmaSelGmaInMixt_C;
extern CONST(UInt8, EXMGSLT1_CALIB) ExM_tCoHot_C;
extern CONST(UInt8, EXMGSLT1_CALIB) ExM_tLimTExIni_C;

#define ExMGslT1_STOP_SEC_CALIB_8BIT
#include "ExMGslT1_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define ExMGslT1_START_SEC_CALIB_BOOLEAN
#include "ExMGslT1_MemMap.h"

extern CONST(Boolean, EXMGSLT1_CALIB) EXMGSLT1_ACTIVE_BYP_C;
extern CONST(Boolean, EXMGSLT1_CALIB) ExM_bAcvFlex_C;
extern CONST(Boolean, EXMGSLT1_CALIB) ExM_bAcvGas_C;
extern CONST(Boolean, EXMGSLT1_CALIB) ExM_bAcvPostOx_C;
extern CONST(Boolean, EXMGSLT1_CALIB) ExM_bLamClc_C;
extern CONST(Boolean, EXMGSLT1_CALIB) ExM_bSelGmaInMixt_C;
extern CONST(Boolean, EXMGSLT1_CALIB) ExM_bSelMassFlowEgTot_C;
extern CONST(Boolean, EXMGSLT1_CALIB) ExM_bSelMolMassInMixt_C;
extern CONST(Boolean, EXMGSLT1_CALIB) ExM_bSelTExDyn_C;
extern CONST(Boolean, EXMGSLT1_CALIB) OvlpExP_bSelMfEg_C;
extern CONST(Boolean, EXMGSLT1_CALIB) OvlpExP_bTrb_C;

#define ExMGslT1_STOP_SEC_CALIB_BOOLEAN
#include "ExMGslT1_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define ExMGslT1_START_SEC_CARTO_8BIT
#include "ExMGslT1_MemMap.h"

extern CONST(UInt8, EXMGSLT1_CARTO) ExM_facIgCorGsl_M[6][9];
extern CONST(UInt8, EXMGSLT1_CARTO) ExM_facLamCorGsl_M[11][9];
extern CONST(UInt8, EXMGSLT1_CARTO) ExM_facTCoCor_M[16][10];
extern CONST(UInt8, EXMGSLT1_CARTO) ExM_tCoDeltaY_A[10];
extern CONST(UInt8, EXMGSLT1_CARTO) ExM_tCoMesSwtY_A[6];

#define ExMGslT1_STOP_SEC_CARTO_8BIT
#include "ExMGslT1_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define ExMGslT1_START_SEC_INTERNAL_VAR_32BIT
#include "ExMGslT1_MemMap.h"

extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_EPostOx_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_PCI;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_PCICor_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkClsExVlvVirt_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkExCmDelta2_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkExCmDelta_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkExCmMaxShiftEx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkExCmMaxShiftIn;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkExCmPts2;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkExCmPts3;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkGrdMaxShift_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkGrdOvlp_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkInCmDelta2_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkInCmDelta_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkInCmMaxShiftEx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkInCmMaxShiftIn;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkInCmPts2;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkInCmPts3;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkMaxOvlpEx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkMaxOvlpIn;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkMaxShiftEx_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkMaxShiftIn_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkMidEx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkMidIn;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkMinOvlpEx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkMinOvlpIn;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkOpInVlvVirt_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkOvlpEx_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_agCkOvlpIn_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppEx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppExCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppExGslFlex_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppExMixt;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppIng;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppIngCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppIngGslFlex_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppIngMol_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cppIngWithRg_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_cpvIngMol_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_fac1;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_fac2;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_fac3;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_fac4;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_facIgCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_facIgCorGsl;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_facIgGslFlex_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_facLamCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_facLamCorGsl;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_facLamGslFlex_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_facTCoCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_facTotCutOffFil_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_lam;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_lamEx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_lamEx_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_lamLeanLimPostOx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_lamLeanLimPostOxCor_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_lamRichLimPostOx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_lamRichLimPostOxCor_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfAirCorPh;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfAirCylLe_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfAirEx_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfAirRg_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfAirScvCorPh;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfAirTot_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfEgTotWithScv;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfFuCyl;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfFuCylLe_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfFuCyl_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfFuEx_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfFuScv;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfFuScv_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfFuStoich_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfFuTot_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfScvMixt;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_mfTot_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_molMassEx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_molMassExCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_molMassExGslFlex_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_molMassInWoutRg;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_molMassInWoutRgCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_molMassWoutRgGslFlex_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_molTot_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_rAfs;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_rAfsGslFlex_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tAirRef;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tCoDelta_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tCoMesSwt;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tCutOffCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tDynPrev_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExAfterTran_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExBas;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExBasCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExBasGslFlex_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExCutOffStat_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExDelta2_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExDelta_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExExCmMaxShift;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExInCmMaxShift;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExMaxOvlp;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExMid;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExMinOvlp;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExPts2;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExPts3;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExScv;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExScvPostOx;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExStat;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tExStatCor;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tStepClc1_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_tStepClc2_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_wAbsTotHeat_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_wEx_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_wHeatEx_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_wHeatIng_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_wIng_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) ExM_wMassVlvHeatEShift_MP;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_facMassFlowLd;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_facPresAirExt;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_facSatClsExVlvMidMax;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_facSatClsExVlvMinMid;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_facSatOpInVlvMidMax;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_facSatOpInVlvMinMid;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_facTEgSqrtIvs;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_mfEg;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresClsExVlvMax;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresClsExVlvMid;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresClsExVlvMin;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresExMnf_facVlvOvlp;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMaxExMax;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMaxExMid;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMaxExMin;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMidExMax;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMidExMid;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMidExMin;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMinExMax;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMinExMid;
extern VAR(Float32, EXMGSLT1_INTERNAL_VAR) OvlpExP_rPresInMinExMin;

#define ExMGslT1_STOP_SEC_INTERNAL_VAR_32BIT
#include "ExMGslT1_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define ExMGslT1_START_SEC_INTERNAL_VAR_16BIT
#include "ExMGslT1_MemMap.h"

extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) ExM_prm_pExMnfEstimOvlpPrev[6];
extern VAR(SInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_agCkExDeltaMaxMid_MP;
extern VAR(SInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_agCkExDeltaMidMin_MP;
extern VAR(SInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_agCkInDeltaMaxMid_MP;
extern VAR(SInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_agCkInDeltaMidMin_MP;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_facClsExVlvMidMax_MP;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_facClsExVlvMinMid_MP;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_facInMidMaxAdjExMax_MP;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_facInMidMaxAdjExMid_MP;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_facInMinMidAdjExMax_MP;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_facOpInVlvMidMax_MP;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_facOpInVlvMinMid_MP;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_rEgTotLdCor_nEng;
extern VAR(UInt16, EXMGSLT1_INTERNAL_VAR) OvlpExP_rEgTotLd_nEng_MP;

#define ExMGslT1_STOP_SEC_INTERNAL_VAR_16BIT
#include "ExMGslT1_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define ExMGslT1_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ExMGslT1_MemMap.h"

extern VAR(Boolean, EXMGSLT1_INTERNAL_VAR) ExM_bAcvPts2_MP;
extern VAR(Boolean, EXMGSLT1_INTERNAL_VAR) ExM_bAcvPts3_MP;
extern VAR(Boolean, EXMGSLT1_INTERNAL_VAR) ExM_bDivZeroTExBas_MP;
extern VAR(Boolean, EXMGSLT1_INTERNAL_VAR) OvlpExP_bExOverMid_MP;
extern VAR(Boolean, EXMGSLT1_INTERNAL_VAR) OvlpExP_bInOverMidAdjExMax_MP;
extern VAR(Boolean, EXMGSLT1_INTERNAL_VAR) OvlpExP_bInOverMidAdjExMid_MP;
extern VAR(Boolean, EXMGSLT1_INTERNAL_VAR) OvlpExP_bInOverMidAdjExMin_MP;

#define ExMGslT1_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ExMGslT1_MemMap.h"
#endif                                 /* RTW_HEADER_ExMGslT1_private_h_ */

/*-------------------------------- end of file -------------------------------*/
