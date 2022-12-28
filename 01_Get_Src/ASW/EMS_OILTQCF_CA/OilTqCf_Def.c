/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : OilTqCf                                                 */
/* !Description     : OIL TORQUE CONFIGURATION                                */
/*                                                                            */
/* !Module          : OilTqCf                                                 */
/*                                                                            */
/* !File            : OilTqCf_Def.c                                           */
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
/*   Code generated on: Sun Oct 21 15:29:22 2012                              */
/*   Model name       : OilTqCf_AUTOCODE.mdl                                  */
/*   Model version    : 1.64                                                  */
/*   Root subsystem   : /OilTqCf                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/OILTQCF_CA/OilTqC$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   25 Oct 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "OilTqCf.h"
#include "OilTqCf_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define OILTQCF_START_SEC_CALIB_16BIT
#include "OilTqCf_MemMap.h"

CONST(SInt16, OILTQCF_CALIB) OilTqCf_facDen_C = 16;
CONST(SInt16, OILTQCF_CALIB) OilTqCf_facNum_C = 16;
CONST(UInt16, OILTQCF_CALIB) OilTqCf_nEng_rLdHiX_A[9] = { 750U, 1000U, 1500U,
  2000U, 2500U, 3000U, 3500U, 4000U, 5000U } ;

CONST(UInt16, OILTQCF_CALIB) OilTqCf_nEng_rLdLoX_A[9] = { 750U, 1000U, 1500U,
  2000U, 2500U, 3000U, 3500U, 4000U, 5000U } ;

CONST(UInt16, OILTQCF_CALIB) OilTqCf_pAirExtMes_rLdHiY_A[4] = { 500U, 1000U,
  1300U, 1500U } ;

CONST(UInt16, OILTQCF_CALIB) OilTqCf_pAirExtMes_rLdLoY_A[4] = { 500U, 1000U,
  1300U, 1500U } ;

CONST(UInt16, OILTQCF_CALIB) OilTqCf_rLdHi_M[36] = { 700U, 700U, 700U, 700U,
  700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U,
  700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U, 700U,
  700U, 700U, 700U, 700U, 700U, 700U } ;

CONST(UInt16, OILTQCF_CALIB) OilTqCf_rLdLo_M[36] = { 500U, 500U, 500U, 500U,
  500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U,
  500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U, 500U,
  500U, 500U, 500U, 500U, 500U, 500U } ;

#define OILTQCF_STOP_SEC_CALIB_16BIT
#include "OilTqCf_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define OILTQCF_START_SEC_CALIB_8BIT
#include "OilTqCf_MemMap.h"

CONST(UInt8, OILTQCF_CALIB) OILTQCF_u8Inhib = 0U;
CONST(UInt8, OILTQCF_CALIB) OilTqCf_stPrmDen_C = 1U;
CONST(UInt8, OILTQCF_CALIB) OilTqCf_stPrmNum_C = 1U;
CONST(UInt8, OILTQCF_CALIB) OilTqCf_tiDlyHysCfm_C = 10U;

#define OILTQCF_STOP_SEC_CALIB_8BIT
#include "OilTqCf_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define OILTQCF_START_SEC_CALIB_BOOLEAN
#include "OilTqCf_MemMap.h"

CONST(Boolean, OILTQCF_CALIB) OilTqCf_bAcvSIPCordCdnDen_C = 0;
CONST(Boolean, OILTQCF_CALIB) OilTqCf_bAcvSIPCordCdnNum_C = 0;
CONST(Boolean, OILTQCF_CALIB) OilTqCf_bAcvrLdNormCdn_C = 1;
CONST(Boolean, OILTQCF_CALIB) OilTqCf_bPresOilReqCf_C = 0;

#define OILTQCF_STOP_SEC_CALIB_BOOLEAN
#include "OilTqCf_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define OILTQCF_START_SEC_VAR_32BIT
#include "OilTqCf_MemMap.h"

VAR(Float32, OILTQCF_VAR) OilTqCf_rLdHi_MP;
VAR(Float32, OILTQCF_VAR) OilTqCf_rLdLo_MP;
VAR(Float32, OILTQCF_VAR) OilTqCf_rLdNorm_MP;

#define OILTQCF_STOP_SEC_VAR_32BIT
#include "OilTqCf_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define OILTQCF_START_SEC_VAR_16BIT
#include "OilTqCf_MemMap.h"

VAR(SInt16, OILTQCF_VAR) OilTqCf_facDen;
VAR(SInt16, OILTQCF_VAR) OilTqCf_facDen_MP;
VAR(SInt16, OILTQCF_VAR) OilTqCf_facNum;
VAR(SInt16, OILTQCF_VAR) OilTqCf_facNum_MP;

#define OILTQCF_STOP_SEC_VAR_16BIT
#include "OilTqCf_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define OILTQCF_START_SEC_VAR_BOOLEAN
#include "OilTqCf_MemMap.h"

VAR(Boolean, OILTQCF_VAR) OilTqCf_bPresOilReqCf;

#define OILTQCF_STOP_SEC_VAR_BOOLEAN
#include "OilTqCf_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
