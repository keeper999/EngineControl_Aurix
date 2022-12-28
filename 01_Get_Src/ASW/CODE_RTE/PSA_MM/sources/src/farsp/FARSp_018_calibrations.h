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
* %name: FARSp_018_calibrations.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:59 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_018_calibrations.h-3.0:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_018_CALIBRATIONS_H_
#define _FARSP_018_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_mAirO2MinThd_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_pAirExtMinThd_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_uLsDsThd_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_mO2StgEngStopCor_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngTWCPurgeX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtTWCPurgeRaw_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesRStrtSTTCor_A[8];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_32BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_32BIT UInt32 FARSp_rAirLdCorTWCPurgeY_A[12];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 FARSp_tiAstCor_A[8];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 FARSp_tiAstThd_T[8];
#define FARSP_STOP_SEC_CARTO_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facAstMixtCor_T[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facO2StgMixtCor_T[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facRStrtSTTMixtCor_T[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_tCoMesRStrtSTTAst_A[8];
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_facMixtSTTWupSpCor_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCPurgeFlex_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCPurgeSp;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCPurgeSpFlex;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCPurgeSpGas;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCPurgeSpGsl;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCPurgeSpRaw;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCPurgeSpRaw_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facTWCPurgeSpFlex;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facTWCPurgeSpGas;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvRichTWCPurgeSTT;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

