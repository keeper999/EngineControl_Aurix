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
* %name: FARSp_002_calibrations.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:47 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_002_calibrations.c-3.0:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_002_CALIBRATIONS_C_
#define _FARSP_002_CALIBRATIONS_C_
#include "FARSp_002_calibrations.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilBasAfs_C=655;
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rAirLdThdAflScvHys_C=3277;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngAirLdThdAflScv_A[8]={500,1000,1500,
2000,2500,3000,3500,7500};AR_MERGEABLE_CARTO_16BIT UInt16 
FARSp_rAirLdThdAflScv_T[8]={16384,16384,17203,18022,19661,20480,0,0};
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtBasSp;AR_INTERNAL_VAR_DISP_16BIT 
UInt16 FARSp_rMixtScvExAfs;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvAflScvGDI;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

