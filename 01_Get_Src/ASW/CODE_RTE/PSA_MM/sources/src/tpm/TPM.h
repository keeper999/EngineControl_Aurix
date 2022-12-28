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
* %name: TPM.h %
*
* %version: 2.1 %
*
* %date_modified: Tue Jun 26 17:55:58 2012 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC2 %
* %full_filespec: TPM.h-2.1:incl:1 %
*
*******************************************************************************/
#ifndef _TPM_H_
#define _TPM_H_

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define TPM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TPM_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TPM_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TPM_ModuleVersion_Minor_MP;
#define TPM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TPM_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define TPM_START_SEC_CALIB_BOOLEAN
#include "TPM_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bAcvRichProtOxdTWC_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bAcvRichThermoProt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bAirLdLimTExMgr_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bExThermoProt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bInhOvbReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bRichLimScv_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bInhInjCutOff_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bInhInjSelCutOff_B;
#define TPM_STOP_SEC_CALIB_BOOLEAN
#include "TPM_MemMap.h"

#define TPM_START_SEC_CALIB_8BIT
#include "TPM_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 ExM_stO2HcStgTWC_B;
#define TPM_STOP_SEC_CALIB_8BIT
#include "TPM_MemMap.h"

#define TPM_START_SEC_CALIB_16BIT
#include "TPM_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 TPM_rMixtLimMaxAflScv_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 TPM_tTarAcvThermoProtDev_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 TPM_mfAirScvLimMaxCor_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 TPM_tExReq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 TPM_rLdProtExThermo_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 PhyMSI_pwrCylHdEstim_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 PhyMSI_tExMnfEstim_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 PhyMSI_tTrbCaseEstim_B;
#define TPM_STOP_SEC_CALIB_16BIT
#include "TPM_MemMap.h"

#define TPM_START_SEC_CALIB_32BIT
#include "TPM_MemMap.h"
extern AR_MERGEABLE_CALIB_32BIT UInt32 PhyMSI_pCylMaxEstim_B;
#define TPM_STOP_SEC_CALIB_32BIT
#include "TPM_MemMap.h"

#endif/*_TPM_H_ */

/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/ 
