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
* %name: FARSp_calibrations.h %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:55:06 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_calibrations.h-4.0.build1:incl:11 %
*
*******************************************************************************/


#ifndef _FARSP_CALIBRATIONS_H_
#define _FARSP_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 FARSp_tiSdlFARSp_C;
#define FARSP_STOP_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_EXT_CALIB_16BIT UInt16 FARSp_rMixtAfsTran_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#endif

