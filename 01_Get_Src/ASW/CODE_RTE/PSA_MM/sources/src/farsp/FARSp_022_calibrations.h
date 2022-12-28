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
* %name: FARSp_022_calibrations.h %
*
* %version: 5.0.build1 %
*
* %date_modified: Tue Aug  7 11:14:56 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: FARSp_022_calibrations.h-5.0.build1:incl:5 %
*
*******************************************************************************/


#ifndef _FARSP_022_CALIBRATIONS_H_
#define _FARSP_022_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_facFilStiBlby_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtAfsDeltaMax_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtAmpStiBlbyMax_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtAmpStiBlbyMin_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtBlbyAuthBasOfs_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtBlbyAuthBas_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtBlbyAuthTWCOfs_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtLoTqReqAuthOfs_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtManModSp_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtRichScvInvldOfs_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtStiBlbyTran_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtThermoProtAuthOfs_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_tiDlyLoTqReqNotAuth_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_tiDlyRichScvInvld_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_tiDlyThermoProtNotAuth_C;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bInhProtManMod_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bManModAcv_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bSenO2PropUsTWC_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bStiBlbyAcv_C;
#define FARSP_STOP_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngLimSatMaxX_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_nEngLimSatMinX_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdCorLimSatMaxY_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rAirLdCorLimSatMinY_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtLimSatMax_M[8][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 FARSp_rMixtLimSatMin_M[8][8];
#define FARSP_STOP_SEC_CARTO_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtCordCmb_MP[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtCordLih[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtCordManModSp[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtCordRaw[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtCordTWCMon_MP[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtCordThermo_MP[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtLimCmbSp[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_prm_rMixtStiBlbySp[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtCordLih[2];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLimMaxSpGsl;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 FARSp_rMixtLimMinSpGsl;
#define FARSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_prm_rMixtCmbSpFil_MP[2];extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtLimMax;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtLimMaxFlex_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtLimMin;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 FARSp_rMixtLimMinFlex_MP;
#define FARSP_STOP_SEC_INTERNAL_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAcvStiTWC;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bAmpStiBlbyAuth;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bExtReqStiBlbyAuth;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bManModAcv;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bRMixtDif_MP[2];extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FARSp_bRMixtStiBlbyAuth;
#define FARSP_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#endif

