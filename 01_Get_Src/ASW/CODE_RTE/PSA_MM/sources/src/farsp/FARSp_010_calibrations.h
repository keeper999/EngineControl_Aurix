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
* %name: FARSp_010_calibrations.h %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:54:56 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_010_calibrations.h-4.0.build1:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_010_CALIBRATIONS_H_
#define _FARSP_010_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facTranDecWupCoHeat_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facTranIncWupCoHeat_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtAstWupSpLihIni_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtSpGrdNegWupLih_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtThdAfsWupSTTEna_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 FARSp_tCoMesThdAfsWupSTTEna_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_tiAstDeacAstWupLih_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 FARSp_tiSdlFARSp_C;
#define FARSP_STOP_SEC_CALIB_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_ctNbCmbAstCoHeatY_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_ctNbCmbAstNormY_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_ctNbCmbAstSTTY_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtAstCoHeatSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtAstNormSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtAstSTTSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtWupCoHeatSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtWupNormSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtWupSTTSp_M[12][12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesAstCoHeatX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesAstNormX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesRStrtAstSTTX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesRStrtWupSTTY_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesWupCoHeatX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesWupNormX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesWupSTTX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoStrtMesWupCoHeatY_A[12];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoStrtMesWupNormY_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_tiEngModSTT_A[16];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facRatMixtSTTCor_T[16];
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAstWupCoHeatSp_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAstWupNormSp_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAstWupSTTSp_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAstWupSpFlex;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAstWupSpGas;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT SInt32 FARSp_facTranAstWupCoHeat_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtAstWupFlex_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtAstWupSTTSp;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtAstWupSTTSpPrev;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtAstWupSpGsl;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 FARSp_rMixtAstWupSpLih;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 FARSp_rMixtAstWupSpRaw;
#define FARSP_STOP_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facAstWupSpFlex;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facAstWupSpGas;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvRatMixtAstWupSTTSp;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAstWupRatLimAcv_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

