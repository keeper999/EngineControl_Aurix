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
* %name: FARSp_006_calibrations.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:50 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_006_calibrations.h-3.0:incl:3 %
*
*******************************************************************************/


#ifndef _FARSP_006_CALIBRATIONS_H_
#define _FARSP_006_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtSelCutOffSpGsl_M[6][6];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_32BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_32BIT UInt32 FARSp_mfEgTotSelCutOffX_A[6];
#define FARSP_STOP_SEC_CARTO_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_noCylCutOffY_A[6];
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSelCutOffFlex_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSelCutOffSp;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSelCutOffSpFlex;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSelCutOffSpGas;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSelCutOffSpGsl;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facSelCutOffSpFlex;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facSelCutOffSpGas;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvSelCutOffSpcMixt;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

