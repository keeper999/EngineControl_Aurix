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
* %name: FARSp_014_calibrations.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:56 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_014_calibrations.h-3.0:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_014_CALIBRATIONS_H_
#define _FARSP_014_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilLih_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtAflLihSp_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtAfrLihSp_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtDeltaThdLih_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 FARSp_noMixtLihSpPrio_C;
#define FARSP_STOP_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLihSp;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bLihAcv;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bLihAuth;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

