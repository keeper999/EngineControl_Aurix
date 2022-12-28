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
* %name: FARSp_004_calibrations.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:48 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_004_calibrations.h-3.0:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_004_CALIBRATIONS_H_
#define _FARSP_004_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilThermoProt_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtMaxAuth_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtMinCmbSp_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtProtTWCMin_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtSatO2Max_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtThermoProtThd_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_facTEgCorReqX_A[12];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_32BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_32BIT UInt32 FARSp_mfTotExCorY_A[12];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 FARSp_rMixtThermoProtReq_M[12][12];
#define FARSP_STOP_SEC_CARTO_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtMaxThermoProt_irv_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtThermoProtSpFlex;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtThermoProtSpGas;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtThermoProtSp_irv_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_facTEgCorReq_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtThermoProtFlex_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtThermoProtReq;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtThermoProtSpGsl;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtThermoProtSpRaw;
#define FARSP_STOP_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facThermoProtSpFlex;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facThermoProtSpGas;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bInvldThermoProt;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bThermoProtAuth;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

