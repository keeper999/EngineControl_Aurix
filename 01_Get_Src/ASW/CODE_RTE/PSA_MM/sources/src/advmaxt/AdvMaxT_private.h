/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMaxT                                                 */
/* !Description     : AdvMaxT Software Component                              */
/*                                                                            */
/* !Module          : AdvMaxT                                                 */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : AdvMaxT_private.h                                       */
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
/*   Model name       : AdvMaxT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMaxT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M04-AdvMaxT/5-S$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   11 Apr 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AdvMaxT_private_h_
#define RTW_HEADER_AdvMaxT_private_h_
#include "Std_Types.h"
#include "AdvMaxT_types.h"
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
#define AdvMaxT_START_SEC_CODE
#include "AdvMaxT_MemMap.h"

extern void RE_AdvMaxT_001_MSE_Start(void);
extern void RE_AdvMaxT_001_MSE(void);
extern void RE_AdvMaxT_002_DRE(void);
void AdvMaxT_ASYNC1(int controlPortIdx);

#define AdvMaxT_STOP_SEC_CODE
#include "AdvMaxT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CARTO_32BIT" */
#define AdvMaxT_START_SEC_CARTO_32BIT
#include "AdvMaxT_MemMap.h"

extern CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxExVlvMax_M[16][16];
extern CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxExVlvMin_M[16][16];
extern CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxInVlvMax_M[16][16];
extern CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxInVlvMin_M[16][16];
extern CONST(Float32, ADVMAXT_CARTO) IgSys_agIgMaxVlvRef_M[16][16];
extern CONST(Float32, ADVMAXT_CARTO) IgSys_rAdvMaxExVlv_M[17][17];
extern CONST(Float32, ADVMAXT_CARTO) IgSys_rAdvMaxInVlv_M[17][17];
extern CONST(Float32, ADVMAXT_CARTO) Vlv_agCkExVlvNorm_A[17];
extern CONST(Float32, ADVMAXT_CARTO) Vlv_agCkInVlvNorm_A[17];

#define AdvMaxT_STOP_SEC_CARTO_32BIT
#include "AdvMaxT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AdvMaxT_START_SEC_CALIB_BOOLEAN
#include "AdvMaxT_MemMap.h"

extern CONST(Boolean, ADVMAXT_CALIB) ADVMAXT_ACTIVE_BYP_C;
extern CONST(Boolean, ADVMAXT_CALIB) IgSys_bFlexMaxOfs_C;
extern CONST(Boolean, ADVMAXT_CALIB) IgSys_bGasMaxOfs_C;

#define AdvMaxT_STOP_SEC_CALIB_BOOLEAN
#include "AdvMaxT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define AdvMaxT_START_SEC_CALIB_8BIT
#include "AdvMaxT_MemMap.h"

extern CONST(UInt8, ADVMAXT_CALIB) IgSys_agIgKnkAdpOfsMv_B;
extern CONST(UInt8, ADVMAXT_CALIB) IgSys_agIgMaxWiPrevAdpMv_B;
extern CONST(UInt8, ADVMAXT_CALIB) IgSys_agIgMaxWiPrevMv_B;
extern CONST(UInt8, ADVMAXT_CALIB) IgSys_prm_agIgMaxWiPrevAdpCyl_B[6];

#define AdvMaxT_STOP_SEC_CALIB_8BIT
#include "AdvMaxT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define AdvMaxT_START_SEC_INTERNAL_VAR_32BIT
#include "AdvMaxT_MemMap.h"

extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agCkClsExVlvWrmAdvMax_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agCkDeltaExVlv_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agCkDeltaInVlv_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agCkOpInVlvWrmAdvMax_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgDynExVlvMax_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgDynExVlvMin_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgDynInVlvMax_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgDynInVlvMin_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgKnkBasDyn;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgKnkBasStat;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxDynExVlvMax;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxDynExVlvMin;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxDynInVlvMax;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxDynInVlvMin;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxStatExVlvMax;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxStatExVlvMin;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxStatInVlvMax;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxStatInVlvMin;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxVlvDynRef;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxVlvStatRef;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxWiFlexCor_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxWiOfs;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgMaxWoutPrevAdpMv;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgStatExVlvMax_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgStatExVlvMin_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgStatInVlvMax_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_agIgStatInVlvMin_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_facAdvMaxExVlv;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_facAdvMaxInVlv;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_rAdvMaxExVlv;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_rAdvMaxInVlv;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_rDeltaExVlv_MP;
extern VAR(Float32, ADVMAXT_INTERNAL_VAR) IgSys_rDeltaInVlv_MP;

#define AdvMaxT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AdvMaxT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define AdvMaxT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvMaxT_MemMap.h"

extern VAR(Boolean, ADVMAXT_INTERNAL_VAR) IgSys_bAcvAdvMax;

#define AdvMaxT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AdvMaxT_MemMap.h"
#endif                                 /* RTW_HEADER_AdvMaxT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
