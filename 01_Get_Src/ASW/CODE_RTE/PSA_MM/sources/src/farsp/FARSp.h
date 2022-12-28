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
* %name: FARSp.h %
*
* %version: 6.0.build1 %
*
* %date_modified: Wed Dec 19 11:03:23 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: FARSp.h-6.0.build1:incl:3 %
*
*******************************************************************************/

#ifndef _FARSP_H_
#define _FARSP_H_

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define FARSP_START_SEC_CONST_VERSION_MODULE_8BIT
#include "FARSp_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 FARSp_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 FARSp_ModuleVersion_Minor_MP;
#define FARSP_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "FARSp_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define FARSP_START_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_002_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_004_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_006_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_008_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_010_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_012_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_014_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_016_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_018_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_022_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_024_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_026_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bDeacAntiStall_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bEnaAntiStall_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bRichLoTqReqNotAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bRichMixtAcv_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bRichScvThermoInvld_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bSatMaxRatMixt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bSatMinRatMixt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bThermoProtReqNotAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bStiBlbyNotAcv_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_prm_bRlamSpAcv_B[20];
#define FARSP_STOP_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"

#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_prm_rMixtCylSp_B[6];
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtCylSp_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtCylSpWiStiTWC_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtFullLdSpRaw_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtThermoProtSp_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtCylSpWoutStiBlby_B;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"

#endif/*_FARSP_H_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
