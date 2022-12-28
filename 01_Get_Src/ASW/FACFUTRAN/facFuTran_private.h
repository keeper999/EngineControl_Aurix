/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : facFuTran                                               */
/* !Description     : FACFUTRAN : INJECTED FUEL MASS CORRECTION FACTOR DURING LOAD TRANSIENT*/
/*                                                                            */
/* !Module          : facFuTran                                               */
/*                                                                            */
/* !File            : facFuTran_private.h                                     */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
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
/*   Code generated on: Mon May 19 23:02:25 2014                              */
/*   Model name       : facFuTran_AUTOCODE.mdl                                */
/*   Model version    : 1.640                                                 */
/*   Root subsystem   : /facFuTran                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/FACFUTRAN/facFuTran_privat$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   etsasson                               $$Date::   02 Jun 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_facFuTran_private_h_
#define RTW_HEADER_facFuTran_private_h_
#include "Std_Types.h"
#include "facFuTran_types.h"
#include "facFuTran_import.h"
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
#define FACFUTRAN_START_SEC_CODE
#include "facFuTran_MemMap.h"

extern void facFuTran_rising_edge(Boolean rtu_Signal,
  rtB_rising_edge_facFuTran_i *localB, rtDW_rising_edge_facFuTran_j *localDW);
extern void fac_facFuTranFctInit_Inhib_Init(rtDW_facFuTranFctInit_Inhib_fac
  *localDW);
extern void facFuTra_facFuTranFctInit_Inhib(Float32
  rtu_InjSys_facTranCmpPrevRmp, Boolean rtu_Dv_detection_pied_leve, Boolean
  rtu_TqSys_bEngNOnIdl, UInt8 rtu_CoPTSt_stEngNew, UInt8 rtu_Ext_tiTDC,
  Boolean rtu_CoPTSt_bRStrtSTT, UInt32 rtu_InjSys_mFuReq, UInt8
  rtu_Eng_noInNxtCyl, Boolean rtu_InjSys_bTotCutOff, UInt16
  rtu_InjSys_nEngInjSp, Boolean rtu_EOM_bTranMod, const UInt16
  rtu_InjSys_prm_facInjResuCyl[6], rtB_facFuTranFctInit_Inhib_facF *localB,
  rtDW_facFuTranFctInit_Inhib_fac *localDW);
extern void F00_facFuTranFctInit_Inhi_Start(void);
extern void facF_F00_facFuTranFctInit_Inhib(void);
extern void facFuTran_rising_edge_l_Update(Boolean rtu_Signal,
  rtDW_rising_edge_facFuTran *localDW);
extern void facFuTran_rising_edge_m(Boolean rtu_Signal,
  rtB_rising_edge_facFuTran *localB, rtDW_rising_edge_facFuTran *localDW);
extern void facFuTra_F01_facFuTranFct_Start(void);
extern void facFuTran_F01_facFuTranFct(void);
extern void facFuTran_F02_facFuTranSync(void);
extern void facFuTran_F03_RstDetTran(void);
extern void InjSys_EveInj_facFuTran_Start(void);
extern void InjSys_EveInj_facFuTran(void);
extern void InjSys_EveInj_facFuTran(void);
extern void facFu_F00_facFuTranFctInit_Init(void);
extern void facFuTran_F00_facFuTranFctInit(void);
extern void facFuTran_F01_facFuTranRst(void);
extern void InjSys_EveRst_facFuTran_Init(void);
extern void InjSys_EveRst_facFuTran_Start(void);
extern void InjSys_EveRst_facFuTran(void);
extern void facFuTran_IfActionSubsystem(Boolean rtu_0, Boolean *rty_Out1);
extern void facFuTran_IfActionSubsystem1(Boolean rtu_0, Boolean *rty_Out1);
extern void facFuTran_F00b_DetTranFct(void);
extern void InjSys_SdlFast_facFuTran_Start(void);
extern void InjSys_SdlFast_facFuTran(void);
void facFuTran_ASYNC1(int controlPortIdx);
void facFuTran_ASYNC2(int controlPortIdx);
void facFuTran_ASYNC3(int controlPortIdx);

#define FACFUTRAN_STOP_SEC_CODE
#include "facFuTran_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_CALIB_8BIT" */
#define FACFUTRAN_START_SEC_CALIB_8BIT
#include "facFuTran_MemMap.h"

extern CONST(UInt8, FACFUTRAN_CALIB) FACFUTRAN_u8Inhib;

#define FACFUTRAN_STOP_SEC_CALIB_8BIT
#include "facFuTran_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "SEC_VAR_32BIT" */
#define FACFUTRAN_START_SEC_VAR_32BIT
#include "facFuTran_MemMap.h"

extern VAR(Float32, FACFUTRAN_VAR) InjSys_facBasModCurInjTran;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facBasModTarInjTran;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal1;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal2;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal3;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal4;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal5;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranAccSpCal6;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranCmpIni;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranCmpPrevRmp;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranCmpRawRmp;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranCmpRmp;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal1;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal2;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal3;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal4;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal5;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranDecSpCal6;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranModInjTran;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSp;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpBas1ModCur;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpBas1ModTar;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpBas2ModCur;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpBas2ModTar;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpModCur_MP;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_facTranSpModTar_MP;
extern VAR(Float32, FACFUTRAN_VAR) InjSys_prm_facTranAccSpCal[6];
extern VAR(Float32, FACFUTRAN_VAR) InjSys_prm_facTranDecSpCal[6];
extern VAR(Float32, FACFUTRAN_VAR) InjSys_prm_facTranSpCal[6];
extern VAR(Float32, FACFUTRAN_VAR) InjSys_rMAirPredMAirCor;

#define FACFUTRAN_STOP_SEC_VAR_32BIT
#include "facFuTran_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_16BIT" */
#define FACFUTRAN_START_SEC_VAR_16BIT
#include "facFuTran_MemMap.h"

extern VAR(UInt16, FACFUTRAN_VAR) InjSys_facTranCmp;
extern VAR(UInt16, FACFUTRAN_VAR) InjSys_prm_facTranCmpCylPrev[6];

#define FACFUTRAN_STOP_SEC_VAR_16BIT
#include "facFuTran_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_8BIT" */
#define FACFUTRAN_START_SEC_VAR_8BIT
#include "facFuTran_MemMap.h"

extern VAR(UInt8, FACFUTRAN_VAR) InjSys_ctNbCmbTran;
extern VAR(UInt8, FACFUTRAN_VAR) InjSys_idxBas1ModCurInjTran;
extern VAR(UInt8, FACFUTRAN_VAR) InjSys_idxBas1ModTarInjTran;
extern VAR(UInt8, FACFUTRAN_VAR) InjSys_idxBas2ModCurInjTran;
extern VAR(UInt8, FACFUTRAN_VAR) InjSys_idxBas2ModTarInjTran;
extern VAR(UInt8, FACFUTRAN_VAR) InjSys_noClcnAfterReInj;
extern VAR(UInt8, FACFUTRAN_VAR) InjSys_noCmbRmpTran;

#define FACFUTRAN_STOP_SEC_VAR_8BIT
#include "facFuTran_MemMap.h"

/* !Comment: Declare data in section "SEC_VAR_BOOLEAN" */
#define FACFUTRAN_START_SEC_VAR_BOOLEAN
#include "facFuTran_MemMap.h"

extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal1;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal2;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal3;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal4;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal5;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvInjTranSpCal6;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bAcvWfCmpSet_MP;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetAccTran;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetAccTranTmp;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetAcvWfCmp;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetDecTran;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetDecTranTmp;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bDetRmpTran;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bRstDetAccTran;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_bRstDetDecTran;
extern VAR(Boolean, FACFUTRAN_VAR) InjSys_prm_bAcvInjTranSpCal[6];

#define FACFUTRAN_STOP_SEC_VAR_BOOLEAN
#include "facFuTran_MemMap.h"
#endif                                 /* RTW_HEADER_facFuTran_private_h_ */

/*-------------------------------- end of file -------------------------------*/
