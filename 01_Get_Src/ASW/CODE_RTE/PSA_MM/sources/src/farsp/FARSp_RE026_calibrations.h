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
* %name: FARSp_RE026_calibrations.h %
*
* %version: 5.0.build1 %
*
* %date_modified: Tue Aug  7 11:15:00 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: FARSp_RE026_calibrations.h-5.0.build1:incl:2 %
*
*******************************************************************************/


#ifndef _FARSP_RE026_CALIBRATIONS_H_
#define _FARSP_RE026_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtThdAfsWupSTTEnaEth_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 FARSp_tCoMesThdAfsWupSTTEnaEth_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_tEthDftTran_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 FARSp_rEthDft_C;
#define FARSP_STOP_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bInvldEthRatAcv_C;
#define FARSP_STOP_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_ctNbCmbAstNormEthY_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_ctNbCmbAstSTTEthY_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngSatMaxEthX_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngSatMinEthX_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngTWCHeatEthCal1_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngTWCHeatEthCal2_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngTWCHeatEthCal3_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdSatMaxEthY_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdSatMinEthY_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdTWCHeatEthCal1_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdTWCHeatEthCal2_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdTWCHeatEthCal3_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtAstNormEthSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtAstSTTEthSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtLimSatMaxEth_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtLimSatMinEth_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtTWCHeatEthCal1_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtTWCHeatEthCal2_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtTWCHeatEthCal3_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtWupNormEthSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtWupSTTEthSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesAstNormEthX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesWupNormEthX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesWupSTTEthX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoStrtMesWupNormEthY_A[12];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facAstWupEth_T[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facMixtLimMaxEth_T[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facMixtLimMinEth_T[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facTWCHeatEth_T[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_rAstWupEth_A[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_rMixtLimMaxEth_A[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_rMixtLimMinEth_A[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_rTWCHeatEth_A[8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_tCoMesRStrtAstSTTEthX_A[12];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_tCoMesRStrtWupSTTEthY_A[12];
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtGasFlexSp_out[24];extern
 AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAstWupEthSpRaw;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtNormEthSp_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSTTEthSp_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatBas1EthCur;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatBas1EthTar;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatBas2EthCur;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtTWCHeatBas2EthTar;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facAstWupEthSpRaw;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_prm_facGasFlexSp_out[24];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_rEthWiExct;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvRatMixtAstWupEthSp;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvTWCHeatCal1;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvTWCHeatCal2;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvTWCHeatCal3;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

