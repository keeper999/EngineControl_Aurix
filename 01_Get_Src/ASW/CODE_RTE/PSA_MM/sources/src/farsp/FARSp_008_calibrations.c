/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name: FARSp_008_calibrations.c %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:54:54 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_008_calibrations.c-4.0.build1:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_008_CALIBRATIONS_C_
#define _FARSP_008_CALIBRATIONS_C_
#include "FARSp_008_calibrations.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilFullLdNeg_C=655;
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilFullLdPos_C=3277;
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtOfsAcvFilPos_C=4;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bFlexAdpAuth_C=1;
#define FARSP_STOP_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngFullLdDlyX_A[6]={1000,2000,3000,4000,
5000,6000};AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngFullLdX_A[12]={1000,1500,
2000,2500,3000,3500,4000,4500,5000,5500,6000,7500};AR_MERGEABLE_CARTO_16BIT 
UInt16 FARSp_pAirExtEstimFullLdY_A[6]={10000,11000,11500,12000,12500,13000};
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirCorLdFullLdDlyY_A[6]={0,8192,14746,
16384,19661,22938};AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtFullLdGsl_M[12][6]
={{4710,4710,4710,4710,4710,4710},{4710,4710,4710,4710,4710,4710},{4710,4710,
4710,4710,4710,4710},{4710,4710,4710,4710,4710,4710},{4710,4710,4710,4710,4710,
4710},{4710,4710,4710,4710,4710,4710},{4710,4710,4710,4710,4301,4301},{4710,4710
,4710,4710,4301,4301},{4710,4710,4710,4710,4710,4710},{4710,4710,4710,4710,4710,
4710},{4710,4710,4710,4710,4710,4710},{4710,4710,4710,4710,4710,4710}};
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_tiFullLdDly_M[6][6]={{0,0,0,0,0,0},{0,0,0,0,
0,0},{10,10,10,10,10,10},{10,10,10,10,10,10},{0,0,0,0,0,0},{0,0,0,0,0,0}};
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtFullLdSpFlex;
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtFullLdSpGas;
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtFullLdSpGsl;
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtFullLdSp_out;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtFullLdFlex_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facFullLdSpFlex;AR_INTERNAL_VAR_DISP_8BIT 
UInt8 FARSp_facFullLdSpGas;AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_tiFullLdDly;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvRichFullLd;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvRichFullLdDly;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bInhFilTranFullLd_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

