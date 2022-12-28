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
* %name: FARSp_016_calibrations.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:57 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_016_calibrations.h-3.0:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_016_CALIBRATIONS_H_
#define _FARSP_016_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtAgIgMinProtMin_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtAutIgPrvtRef_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtLoTqReqRef_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_agIgDif_LoTqReq_A[10];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_agIgDif_facAutIgPrvt_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEng_AgIgMinProtX_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEng_AutIgPrvtMaxX_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEng_LoTqReqMaxX_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLd_AgIgMinProtY_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLd_AutIgPrvtMaxY_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLd_LoTqReqMaxY_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtAgIgMinProtMax_M[10][10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtAutIgPrvtMax_M[10][10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtLoTqReqMax_M[10][10];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facAgIgMinProtCor_T[10];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facAutIgPrvtCor_T[10];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_facRichLoTqReqCor_T[10];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 FARSp_rAgIg_facAgIgMinProt_A[10];
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAgIgMinProtMax_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAgIgMinProtSp_irv_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAutIgPrvtMax_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAutIgPrvtSpFlex;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAutIgPrvtSpGas;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtAutIgPrvtSpGsl;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLoTqReqFlex_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLoTqReqMax_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLoTqReqSp;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLoTqReqSpFlex;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLoTqReqSpGas;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLoTqReqSpRaw;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtAgIgMinProtRaw;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtAutIgPrvtFlex_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtAutIgPrvtSp;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtLoTqReqSpGsl;
#define FARSP_STOP_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facAutIgPrvtSpFlex;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facAutIgPrvtSpGas;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facLoTqReqFlex;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facLoTqReqGas;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facRichAgIgMinProt_MP;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facRichAutIgPrvtCor_MP;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_facRichLoTqReqCor_MP;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 FARSp_rAgIgMinLim_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bRichAgIgMinProt;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bRichLoTqReq;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

