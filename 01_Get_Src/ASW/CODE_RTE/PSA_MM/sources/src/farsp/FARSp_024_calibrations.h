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
* %name: FARSp_024_calibrations.h %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:55:05 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_024_calibrations.h-4.0.build1:incl:5 %
*
*******************************************************************************/


#ifndef _FARSP_024_CALIBRATIONS_H_
#define _FARSP_024_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtSpGrdPos_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 FARSp_tiSdlFARSp_C;
#define FARSP_STOP_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtSpAntiStall_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_rMixtSpGrdNeg_T[8];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesFARSpGrdNegX_A[8];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMes_rMixtSpASY_A[8];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMes_tiAntiStallX_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_tiAntiStall_T[8];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 IdlSys_noGearX_A[8];
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSpAcvAntiStall_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT SInt16 FARSp_rMixtSpGrdNeg_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSpRawAntiStall;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_tiAntiStall_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtSpAntiStallPrev;
#define FARSP_STOP_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvrMixtSpAntiStall;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bEnaClcAntiStall;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bToutAntiStall_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

