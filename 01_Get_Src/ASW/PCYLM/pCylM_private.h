/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pCylM                                                   */
/* !Description     : CYLINDER PRESSURE ESTIMATOR                             */
/*                                                                            */
/* !Module          : pCylM                                                   */
/*                                                                            */
/* !File            : pCylM_private.h                                         */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
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
/*   Code generated on: Tue Dec 06 14:44:34 2011                              */
/*   Model name       : pCylM_AUTOCODE.mdl                                    */
/*   Model version    : 1.181                                                 */
/*   Root subsystem   : /pCylM                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PCYLM/pCylM_private.h_v   $*/
/* $Revision::   1.5                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   08 Dec 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_pCylM_private_h_
#define RTW_HEADER_pCylM_private_h_
#include "Std_Types.h"
#include "pCylM_types.h"
#include "pCylM_import.h"
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

/* !Comment: Define code in section "SEC_CODE" */
#define PCYLM_START_SEC_CODE
#include "pCylM_MemMap.h"

extern void pCylM_F02_CylMInSyncSdlFast(void);
extern void pCylM_F02_CylPMdl(void);
extern void pCylM_F03_CylMSyncEve(void);
extern void CylM_EveCkSnOn_pCylM_Start(void);
extern void CylM_EveCkSnOn_pCylM(void);
extern void CylM_EveCkSnOn_pCylM(void);
extern void CylM_EveCkSnOn_pCylM(void);
extern void pCylM_F01_CylMInSyncEve(void);
extern void pCylM_F02_CylMSyncEveInj(void);
extern void CylM_EveInj_pCylM_Start(void);
extern void CylM_EveInj_pCylM(void);
extern void pCylM_F01_CylPMdlIni(void);
extern void pCylM_F01_CylMSyncRst(void);
extern void CylM_EveRst_pCylM_Start(void);
extern void CylM_EveRst_pCylM(void);
extern void CylM_SdlFast_pCylM(void);
void pCylM_ASYNC1(int controlPortIdx);
void pCylM_ASYNC2(int controlPortIdx);
void pCylM_ASYNC3(int controlPortIdx);

#define PCYLM_STOP_SEC_CODE
#include "pCylM_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define PCYLM_START_SEC_VAR_32BIT
#include "pCylM_MemMap.h"

extern VAR(Float, PCYLM_VAR) CylM_agBegInjH1ReqRef;
extern VAR(Float, PCYLM_VAR) CylM_agBegInjH2ReqRef;
extern VAR(Float, PCYLM_VAR) CylM_agBegInjS1ReqRef;
extern VAR(Float, PCYLM_VAR) CylM_agBegInjS2ReqRef;
extern VAR(Float, PCYLM_VAR) CylM_agCkClsInVlvEstimRef1;
extern VAR(Float, PCYLM_VAR) CylM_agEndInjH1ReqRef;
extern VAR(Float, PCYLM_VAR) CylM_agEndInjH2ReqRef;
extern VAR(Float, PCYLM_VAR) CylM_agEndInjS1ReqRef;
extern VAR(Float, PCYLM_VAR) CylM_agEndInjS2ReqRef;
extern VAR(Float, PCYLM_VAR) CylM_pDsThrPredRefCmpr;
extern VAR(Float, PCYLM_VAR) CylM_pDsThrPredRefIn;

#define PCYLM_STOP_SEC_VAR_32BIT
#include "pCylM_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define PCYLM_START_SEC_VAR_16BIT
#include "pCylM_MemMap.h"

extern VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimH1CylPrev[6];
extern VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimH2CylPrev[6];
extern VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimS1CylPrev[6];
extern VAR(UInt16, PCYLM_VAR) CylM_prm_pCylEstimS2CylPrev[6];

#define PCYLM_STOP_SEC_VAR_16BIT
#include "pCylM_MemMap.h"
#endif                                 /* RTW_HEADER_pCylM_private_h_ */

/*-------------------------------- end of file -------------------------------*/
