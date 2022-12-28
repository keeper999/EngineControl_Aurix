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
* %name: FARSp_008_calibrations.h %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:54:55 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_008_calibrations.h-4.0.build1:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_008_CALIBRATIONS_H_
#define _FARSP_008_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilFullLdNeg_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilFullLdPos_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtOfsAcvFilPos_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bFlexAdpAuth_C;
#define FARSP_STOP_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngFullLdDlyX_A[6];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngFullLdX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_pAirExtEstimFullLdY_A[6];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirCorLdFullLdDlyY_A[6];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtFullLdGsl_M[12][6];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_tiFullLdDly_M[6][6];
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtFullLdSpFlex;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtFullLdSpGas;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtFullLdSpGsl;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtFullLdSp_out;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtFullLdFlex_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facFullLdSpFlex;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facFullLdSpGas;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_tiFullLdDly;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvRichFullLd;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvRichFullLdDly;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bInhFilTranFullLd_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

