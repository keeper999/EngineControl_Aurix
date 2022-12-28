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
* %name: FARSp_012_calibrations.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:54 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_012_calibrations.h-3.0:incl:3 %
*
*******************************************************************************/


#ifndef _FARSP_012_CALIBRATIONS_H_
#define _FARSP_012_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngTWCHeatCal1X_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngTWCHeatCal2X_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngTWCHeatCal3X_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdTWCHeatCal1Y_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdTWCHeatCal2Y_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdTWCHeatCal3Y_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtTWCHeatCal1_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtTWCHeatCal2_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtTWCHeatCal3_M[8][8];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtTWCHeatCal[4];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatBas1ModCur;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatBas1ModTar;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatBas2ModCur;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatBas2ModTar;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatCal1;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatCal2;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatCal3;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatFlex_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatSp;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatSpFlex;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatSpGas;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatSpGsl;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatSpRaw;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facBasModCur;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facBasModTar;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facTWCHeatSpFlex;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facTWCHeatSpGas;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facTranMod;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_idxBas1ModCur;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_idxBas1ModTar;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_idxBas2ModCur;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_idxBas2ModTar;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvCal1;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvCal2;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvCal3;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvCal4;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvRatMixtTWCHeat;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_prm_bAcvTWCHeatCal[4];
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

