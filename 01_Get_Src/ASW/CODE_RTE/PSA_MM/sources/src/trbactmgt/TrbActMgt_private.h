/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActMgt                                               */
/* !Description     : TrbActMgt Software Component                            */
/*                                                                            */
/* !Module          : TrbActMgt                                               */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : TrbActMgt_private.h                                     */
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
/*   Model name       : TrbActMgt_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActMgt                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M13-TrbActMgt/5-$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_TrbActMgt_private_h_
#define RTW_HEADER_TrbActMgt_private_h_
#include "Std_Types.h"
#include "TrbActMgt_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define TrbAct_tiSampleFast_SC         ((UInt16) 20U)
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
#define TrbActMgt_START_SEC_CODE
#include "TrbActMgt_MemMap.h"

extern void RE_TrbActMgt_001_MSE_Start(void);
extern void RE_TrbActMgt_001_MSE(void);
extern void TrbActMgt_F01_NatBoostPresRef(void);
extern void TrbActMgt_F03_NatEthBoostPres(void);
extern void TrbActMgt_F02_NatBoostPres(void);
extern void TrbActMgt_F04_NatBoostPres(void);
extern void RE_TrbActMgt_002_TEV_Init(void);
extern void RE_TrbActMgt_002_TEV_Start(void);
extern void RE_TrbActMgt_002_TEV(void);
extern void TrbActMgt_F01_IndCtlGain(void);
extern void TrbActMgt_F02_CtlGainRef(void);
extern void TrbActMgt_F04_EthCtlGain(void);
extern void TrbActMgt_F03_CtlGain(void);
extern void RE_TrbActMgt_003_TEV_Init(void);
extern void RE_TrbActMgt_003_TEV_Start(void);
extern void RE_TrbActMgt_003_TEV(void);
void TrbActMgt_ASYNC1(int controlPortIdx);
void TrbActMgt_ASYNC2(int controlPortIdx);

#define TrbActMgt_STOP_SEC_CODE
#include "TrbActMgt_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CARTO_16BIT" */
#define TrbActMgt_START_SEC_CARTO_16BIT
#include "TrbActMgt_MemMap.h"

extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facFfGain_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facFilGainUsThrPresMes_T[9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facPresAltiCor_T[9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain1ErrPresEth_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain1ErrPres_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain1_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain2ErrPresEth_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain2ErrPres_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facdGain2_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_faciGainErrPresEth_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_faciGainErrPres_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_faciGain_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facpGainErrPresEth_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facpGainErrPres_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_facpGain_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_nEngCtl_A[9];
extern CONST(SInt16, TRBACTMGT_CARTO) TrbAct_nEngGrd_A[9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_nEngRef2_A[9];
extern CONST(SInt16, TRBACTMGT_CARTO) TrbAct_pErrUsThr2_A[9];
extern CONST(SInt16, TRBACTMGT_CARTO) TrbAct_pErrUsThrGrd_A[9];
extern CONST(SInt16, TRBACTMGT_CARTO) TrbAct_pErrUsThr_A[9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_pInMnfReqThdEth_T[9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_pInMnfReqThd_T[9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_pUsThrCllAcvThd_T[9];
extern CONST(SInt16, TRBACTMGT_CARTO) TrbAct_tCoMes_A[9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_tiStrtThd_M[9][9];
extern CONST(UInt16, TRBACTMGT_CARTO) TrbAct_tiStrtThd_T[9];

#define TrbActMgt_STOP_SEC_CARTO_16BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Declare data in section "CALIB_16BIT" */
#define TrbActMgt_START_SEC_CALIB_16BIT
#include "TrbActMgt_MemMap.h"

extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_facFltErrPres_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_facPresAltiCor_B;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_facPresRCOCnv_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_nEngTrbActCmdHys_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_nEngTrbActCmdThd_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pAirExtHys_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pDifUsThrPresHiThd_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pDifUsThrPresLoThd_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pInMnfReqHys_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pOilMesThd_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrCorReqTest_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrCorReq_B;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrFil_B;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrICorReqHiThd_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_pUsThrICorReqLoThd_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_rOpTrbActHiThd_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_rOpTrbActLoThd_C;
extern CONST(SInt16, TRBACTMGT_CALIB) TrbAct_rRCOICorReq_B;
extern CONST(SInt16, TRBACTMGT_CALIB) TrbAct_rRCOICorReq_C;
extern CONST(SInt16, TRBACTMGT_CALIB) TrbAct_rRCOPIDCorReq_B;
extern CONST(SInt16, TRBACTMGT_CALIB) TrbAct_rRCOPIDCorReq_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_tiDlyPosnTrbActMod_C;
extern CONST(UInt16, TRBACTMGT_CALIB) TrbAct_tiStrtThd_C;

#define TrbActMgt_STOP_SEC_CALIB_16BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define TrbActMgt_START_SEC_CARTO_8BIT
#include "TrbActMgt_MemMap.h"

extern CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctCor_T[8];
extern CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctCtl_A[8];
extern CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctDftl1_T[8];
extern CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctDftl2_T[8];
extern CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctInt_T[8];
extern CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExctProp_T[8];
extern CONST(UInt8, TRBACTMGT_CARTO) TrbAct_rEthWoutExct_A[8];
extern CONST(SInt8, TRBACTMGT_CARTO) TrbAct_tAir_A[9];

#define TrbActMgt_STOP_SEC_CARTO_8BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define TrbActMgt_START_SEC_CALIB_BOOLEAN
#include "TrbActMgt_MemMap.h"

extern CONST(Boolean, TRBACTMGT_CALIB) TRBACTMGT_ACTIVE_BYP_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvCtlEth_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvEth_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvInhICor_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvOilPresCtl_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvTrbActCmd_B;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bAcvUsThrPresCorTest_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bBoostPresClCtlAcv_B;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bInhCllCtl_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bInhICor_B;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bInhUsReg_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bPosnTrbActMod_B;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bSelInhICnd_C;
extern CONST(Boolean, TRBACTMGT_CALIB) TrbAct_bSelPresErrReq_C;

#define TrbActMgt_STOP_SEC_CALIB_BOOLEAN
#include "TrbActMgt_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define TrbActMgt_START_SEC_INTERNAL_VAR_32BIT
#include "TrbActMgt_MemMap.h"

extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facFfGain;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facdGain1;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facdGain1Ref;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facdGain2;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facdGain2Ref;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_faciGain;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_faciGainRef;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facpGain;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_facpGainRef;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pErrUsThr;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pInMnfReqThd;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pInMnfReqThdEth;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrCorReqPrev;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrDCorReq;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrFfCorReq;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrICorReqIni;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrICorReqPrev;
extern VAR(Float32, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrPCorReq;

#define TrbActMgt_STOP_SEC_INTERNAL_VAR_32BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define TrbActMgt_START_SEC_INTERNAL_VAR_16BIT
#include "TrbActMgt_MemMap.h"

extern VAR(SInt16, TRBACTMGT_INTERNAL_VAR) TrbAct_pErrFltGrd_MP;
extern VAR(SInt16, TRBACTMGT_INTERNAL_VAR) TrbAct_pUsThrICorReq_IRV_MP;

#define TrbActMgt_STOP_SEC_INTERNAL_VAR_16BIT
#include "TrbActMgt_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define TrbActMgt_START_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActMgt_MemMap.h"

extern VAR(Boolean, TRBACTMGT_INTERNAL_VAR) TrbAct_bDetTran;
extern VAR(Boolean, TRBACTMGT_INTERNAL_VAR) TrbAct_bRstICor;

#define TrbActMgt_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "TrbActMgt_MemMap.h"
#endif                                 /* RTW_HEADER_TrbActMgt_private_h_ */

/*-------------------------------- end of file -------------------------------*/
