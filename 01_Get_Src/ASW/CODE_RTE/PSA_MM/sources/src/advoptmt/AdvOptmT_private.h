/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvOptmT                                                */
/* !Description     : AdvOptmT Software Component                             */
/*                                                                            */
/* !Module          : AdvOptmT                                                */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AdvOptmT_private.h                                      */
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
/*   Model name       : AdvOptmT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /AdvOptmT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M03-AdvOptmT/5-$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Nov 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvOptmT_private_h_
#define RTW_HEADER_AdvOptmT_private_h_
#include "Std_Types.h"
#include "AdvOptmT_types.h"
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
#define AdvOptmT_START_SEC_CODE
#include "AdvOptmT_MemMap.h"

extern void RE_AdvOptmT_001_MSE_Start(void);
extern void RE_AdvOptmT_001_MSE(void);
extern void RE_AdvOptmT_004_MSE_Start(void);
extern void RE_AdvOptmT_004_MSE(void);
extern void RE_AdvOptmT_002_DRE_Start(void);
extern void RE_AdvOptmT_002_DRE(void);
extern void RE_AdvOptmT_003_DRE_Start(void);
extern void RE_AdvOptmT_003_DRE(void);
void AdvOptmT_ASYNC1(int controlPortIdx);
void AdvOptmT_ASYNC2(int controlPortIdx);

#define AdvOptmT_STOP_SEC_CODE
#include "AdvOptmT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define AdvOptmT_START_SEC_CALIB_32BIT
#include "AdvOptmT_MemMap.h"

extern CONST(Float32, ADVOPTMT_CALIB) Eng_rAfs_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agCkClsInVlvEstimRef1_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agCkClsInVlvRef1Delta_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agCkClsInVlvRef1Y_A[8];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agCkIni_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agCkMFB50_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agCkMFB5MBSatOfs_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agCkMFB5_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agCkOpClsInVlvDelta_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agIgOptmMBSatOfs_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_agIgOptm_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_facDstCylVelLamiDiv_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_facPCI_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_facVisKFacAeroCorProd_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_gma1Y_A[12];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_nCkFilWupOfsX_A[8];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_nCkFilWupX_A[8];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_nEng_AgCkMFB50RefX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_nEng_AgCkMFB5RefX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_nEng_AgIgOptmRefX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_nEng_FacAeroCorX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_nEng_FacCmbRefX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_nEng_FacIniRefX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_pMixtCylX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rAfrSelY_A[12];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rAirLdWupY_A[6];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rAirLd_AgCkMFB50RefY_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rAirLd_AgCkMFB5RefY_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rAirLd_AgIgOptmOfsY_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rAirLd_AgIgOptmRefY_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rAirLd_FacCmbRefY_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rAirLd_FacIniRefY_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rItBurnRateCor_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rVolCmprX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rlamMaxMsFuCyl_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_rlamSel_VelLamiFlameT0_A[12];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_surProjPist_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_tAirWupOfsY_A[6];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_tAirWup_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_tCoMes_AgIgOptmOfsX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_tCoWupX_A[8];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_tCoWup_C;
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_tMixtCylX_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_tMixtCyl_A[16];
extern CONST(Float32, ADVOPTMT_CALIB) IgSys_tiEngRunWupY_A[6];

#define AdvOptmT_STOP_SEC_CALIB_32BIT
#include "AdvOptmT_MemMap.h"

/* !Comment: Declare data in section "CARTO_32BIT" */
#define AdvOptmT_START_SEC_CARTO_32BIT
#include "AdvOptmT_MemMap.h"

extern CONST(Float32, ADVOPTMT_CARTO) IgSys_agCkMFB50Ref_M[16][16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_agCkMFB5Ref_M[16][16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_agIgOptmOfs_M[16][16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_agIgOptmRef_M[16][16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_agIgWupOfs_tAir_M[8][6];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facAeroCor_M[16][8];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facCmbRef_M[16][16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facIniRef_M[16][16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facPwLaw033Prod_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facPwLaw067Prod_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facPwLawAlpha_M[16][12];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facPwLawBeta_M[16][12];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facPwLawDeltaCmb_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facPwLawDeltaIni_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facPwLawGma1_M[16][12];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facWup_tAir_M[8][6];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_facWup_tCo_M[8][6];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_velLamiFlameT0_T[12];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_visDInMixt_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_volCylAgCkIni_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_volCylIVCRef1_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_volCylMFB50Ref_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_volCylMFB5_T[16];
extern CONST(Float32, ADVOPTMT_CARTO) IgSys_volCylSAOptm_T[16];

#define AdvOptmT_STOP_SEC_CARTO_32BIT
#include "AdvOptmT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AdvOptmT_START_SEC_CALIB_BOOLEAN
#include "AdvOptmT_MemMap.h"

extern CONST(Boolean, ADVOPTMT_CALIB) ADVOPTMT_ACTIVE_BYP_C;
extern CONST(Boolean, ADVOPTMT_CALIB) IgSys_bFlexOptmOfs_C;
extern CONST(Boolean, ADVOPTMT_CALIB) IgSys_bGasOptmOfs_C;
extern CONST(Boolean, ADVOPTMT_CALIB) IgSys_bLamEng_C;

#define AdvOptmT_STOP_SEC_CALIB_BOOLEAN
#include "AdvOptmT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define AdvOptmT_START_SEC_CALIB_8BIT
#include "AdvOptmT_MemMap.h"

extern CONST(UInt8, ADVOPTMT_CALIB) IgSys_agIgBas_B;
extern CONST(UInt8, ADVOPTMT_CALIB) IgSys_agIgOptm_B;

#define AdvOptmT_STOP_SEC_CALIB_8BIT
#include "AdvOptmT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define AdvOptmT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvOptmT_MemMap.h"

extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agCkClsInVlvEstimRef1;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agCkMFB50Ref;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agCkMFB5Calc;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agCkMFB5CalcSat;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agCkMFB5MFB50Delta_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agCkMFB5Ref;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agCkMFB5Sel;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agCkSAOptmMFB5DeltaCalc;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agIgOptmCalc;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agIgOptmCalcSat;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agIgOptmRef;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agIgOptmSel;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agIgOptmWiCor;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agIgOptmWiFlexCor_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agIgWup_IRV_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_agIgWup_nEng_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_densMixtIni_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_dstCylIni;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_dstCylMFB50Ref;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_dstCylMFB5Calc;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_facAeroCor;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_facCmbRef;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_facIniRef;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_facPCI;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_facPwLaw033ProdCmb;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_mFuCyl;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_mMixtCyl;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_pMixtCylCmb;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_pMixtCylIni;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_pMixtCylMFB5;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_pMixtCylMFB50;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_pMixtCylSAOptm;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_rVolCmprMFB50Ref_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_rVolCmprMFB5Sel_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_rVolCmprSAOSel_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_ra;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_rlamSel;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_surProjPist;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tMixtCylCmb;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tMixtCylIVCRef1;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tMixtCylIni;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tMixtCylMFB5;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tMixtCylMFB50;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tMixtCylMFB50RefwCmb_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tMixtCylMFB5wCmb_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tMixtCylSAOptm;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_tiEngRunWup_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_velLamiFlameCmb;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_velLamiFlameIni;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_velLamiFlameT0;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_visKCmb_MP;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_visKIni;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_volCylIVCRef1;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_volCylIni;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_volCylMFB50Ref;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_volCylMFB5Sel;
extern VAR(Float32, ADVOPTMT_INTERNAL_VAR) IgSys_volCylSAOptmSel;

#define AdvOptmT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvOptmT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvOptmT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvOptmT_MemMap.h"

extern VAR(Boolean, ADVOPTMT_INTERNAL_VAR) IgSys_bAcvAdvOptm;
extern VAR(Boolean, ADVOPTMT_INTERNAL_VAR) IgSys_bAcvClsLoop_IRV_MP;
extern VAR(Boolean, ADVOPTMT_INTERNAL_VAR) IgSys_bAcvWup;

#define AdvOptmT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvOptmT_MemMap.h"
#endif                                 /* RTW_HEADER_AdvOptmT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
