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
* %name: FARSp_014_calibrations.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:55 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_014_calibrations.c-3.0:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_014_CALIBRATIONS_C_
#define _FARSP_014_CALIBRATIONS_C_
#include "FARSp_014_calibrations.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilLih_C=4915;AR_MERGEABLE_CALIB_16BIT 
UInt16 FARSp_rMixtAflLihSp_C=3891;AR_MERGEABLE_CALIB_16BIT UInt16 
FARSp_rMixtAfrLihSp_C=4301;AR_MERGEABLE_CALIB_16BIT UInt16 
FARSp_rMixtDeltaThdLih_C=82;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 FARSp_noMixtLihSpPrio_C=2;
#define FARSP_STOP_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLihSp;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bLihAcv;AR_INTERNAL_VAR_DISP_BOOLEAN 
Boolean FARSp_bLihAuth;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

