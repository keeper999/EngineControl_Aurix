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
* %name: FARSp_024_calibrations.c %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:55:04 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_024_calibrations.c-4.0.build1:csrc:5 %
*
*******************************************************************************/


#ifndef _FARSP_024_CALIBRATIONS_C_
#define _FARSP_024_CALIBRATIONS_C_
#include "FARSp_024_calibrations.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtSpGrdPos_C=160;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtSpAntiStall_M[8][8]={{4465,4465,4465,
4465,4465,4465,4465,4465},{4465,4465,4465,4465,4465,4465,4465,4465},{4465,4465,
4465,4465,4465,4465,4465,4465},{4465,4465,4465,4465,4465,4465,4465,4465},{4465,
4465,4465,4465,4465,4465,4465,4465},{4465,4465,4465,4465,4465,4465,4465,4465},{
4465,4465,4465,4465,4465,4465,4465,4465},{4465,4465,4465,4465,4465,4465,4465,
4465}};AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_rMixtSpGrdNeg_T[8]={-2,-2,-2,-2,-2,
-2,-2,-2};AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMesFARSpGrdNegX_A[8]={-40,-20
,0,20,40,60,80,100};AR_MERGEABLE_CARTO_16BIT SInt16 FARSp_tCoMes_rMixtSpASY_A[8]
={-40,-20,0,20,40,60,80,100};AR_MERGEABLE_CARTO_16BIT SInt16 
FARSp_tCoMes_tiAntiStallX_A[8]={-40,-20,0,20,40,60,80,100};
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_tiAntiStall_T[8]={12,12,12,12,12,12,12,12}
;
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CARTO_8BIT UInt8 IdlSys_noGearX_A[8]={0,1,2,3,4,5,6,7};
#define FARSP_STOP_SEC_CARTO_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSpAcvAntiStall_MP;
AR_INTERNAL_VAR_DISP_16BIT SInt16 FARSp_rMixtSpGrdNeg_MP;
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtSpRawAntiStall;
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_tiAntiStall_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtSpAntiStallPrev;
#define FARSP_STOP_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvrMixtSpAntiStall;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bEnaClcAntiStall;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bToutAntiStall_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

