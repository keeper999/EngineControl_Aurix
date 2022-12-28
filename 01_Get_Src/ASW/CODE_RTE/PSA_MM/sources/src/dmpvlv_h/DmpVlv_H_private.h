/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : DmpVlv_H                                                */
/* !Description     : DmpVlv_H Software Component                             */
/*                                                                            */
/* !Module          : DmpVlv_H                                                */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : DmpVlv_H_private.h                                      */
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
/*   Model name       : DmpVlv_H_AUTOSAR.mdl                                  */
/*   Root subsystem   : /DmpVlv_H                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M12-DmpVlvH/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_DmpVlv_H_private_h_
#define RTW_HEADER_DmpVlv_H_private_h_
#include "Std_Types.h"
#include "DmpVlv_H_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define DmpVlv_tiFastDly_SC            ((UInt16) 82U)
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
#define DmpVlv_H_START_SEC_CODE
#include "DmpVlv_H_MemMap.h"

extern void RE_DmpVlv_H_001_MSE_Start(void);
extern void RE_DmpVlv_H_001_MSE(void);
extern void RE_DmpVlv_H_002_TEV_Start(void);
extern void RE_DmpVlv_H_002_TEV(void);
void DmpVlv_H_ASYNC1(int controlPortIdx);

#define DmpVlv_H_STOP_SEC_CODE
#include "DmpVlv_H_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_32BIT" */
#define DmpVlv_H_START_SEC_CALIB_32BIT
#include "DmpVlv_H_MemMap.h"

extern CONST(UInt32, DMPVLV_H_CALIB) DmpVlv_mfAirThrReqThd_C;

#define DmpVlv_H_STOP_SEC_CALIB_32BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define DmpVlv_H_START_SEC_CARTO_16BIT
#include "DmpVlv_H_MemMap.h"

extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_facFilMv_M[8][7];
extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_mfCmprCorAnt_A[16];
extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_mfCmprCor_A[16];
extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_mfDeltaAirReqFil_A[7];
extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_nEng_A[8];
extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_rPresCmprAnt_T[16];
extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_rPresCmpr_T[16];
extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_rTCmprCor_A[16];
extern CONST(UInt16, DMPVLV_H_CARTO) DmpVlv_rTCmprSqrt_T[16];
extern CONST(SInt16, DMPVLV_H_CARTO) DmpVlv_tqLoThd_T[8];

#define DmpVlv_H_STOP_SEC_CARTO_16BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define DmpVlv_H_START_SEC_CALIB_16BIT
#include "DmpVlv_H_MemMap.h"

extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilMfAirThrReq1_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilMfAirThrReq2_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilMfAirThrReq_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilRateDownUp_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facFilRateUpDown_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_facGainSat_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_mfAirThrSatMin_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_pCmprRef_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_rAirLdLimSurgeReq_B;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_rPresCmprHysAnt_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_rPresCmprHys_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_tCmprRef_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_tiDmpVlvTmrAnt_C;
extern CONST(UInt16, DMPVLV_H_CALIB) DmpVlv_tiDmpVlvTmr_C;
extern CONST(SInt16, DMPVLV_H_CALIB) DmpVlv_tqOfsHiThd_C;

#define DmpVlv_H_STOP_SEC_CALIB_16BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define DmpVlv_H_START_SEC_CALIB_BOOLEAN
#include "DmpVlv_H_MemMap.h"

extern CONST(Boolean, DMPVLV_H_CALIB) DMPVLV_H_ACTIVE_BYP_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvCdnTq_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvDetPmp_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvDftMod_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvDmpVlvTestMod_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvDmpVlv_B;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bAcvTestMod_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bDmpVlvDftMod_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bSelCdnTq_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bSelDetPmp_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bSelMfCmprAnt_C;
extern CONST(Boolean, DMPVLV_H_CALIB) DmpVlv_bSelMfCmpr_C;

#define DmpVlv_H_STOP_SEC_CALIB_BOOLEAN
#include "DmpVlv_H_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define DmpVlv_H_START_SEC_INTERNAL_VAR_32BIT
#include "DmpVlv_H_MemMap.h"

extern VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_facFilRate;
extern VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReq;
extern VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReqAnt;
extern VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReqAntSat;
extern VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReqFil;
extern VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfCmprCor;
extern VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfCmprCorFil;
extern VAR(Float32, DMPVLV_H_INTERNAL_VAR) DmpVlv_rPresCmpr;

#define DmpVlv_H_STOP_SEC_INTERNAL_VAR_32BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define DmpVlv_H_START_SEC_INTERNAL_VAR_16BIT
#include "DmpVlv_H_MemMap.h"

extern VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfAirThrReqOfs_MP;
extern VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_mfDeltaAirReqFil_MP;
extern VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_rTCmprCor_MP;
extern VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_tiDmpVlvAcvTmrPrev;
extern VAR(UInt16, DMPVLV_H_INTERNAL_VAR) DmpVlv_tiDmpVlvAcvTmr_IRV_MP;

#define DmpVlv_H_STOP_SEC_INTERNAL_VAR_16BIT
#include "DmpVlv_H_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define DmpVlv_H_START_SEC_INTERNAL_VAR_BOOLEAN
#include "DmpVlv_H_MemMap.h"

extern VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bAcvDmpVlvRaw;
extern VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bDetPmpAr;
extern VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bDetPmpArAnt_MP;
extern VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bDetPmpAr_MP;
extern VAR(Boolean, DMPVLV_H_INTERNAL_VAR) DmpVlv_bDetTqThd;

#define DmpVlv_H_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "DmpVlv_H_MemMap.h"
#endif                                 /* RTW_HEADER_DmpVlv_H_private_h_ */

/*-------------------------------- end of file -------------------------------*/
