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
* %name: TPM_nvm.c %
*
* %version: 3.0 %
*
* %date_modified: Mon Dec  3 09:47:30 2012 %
*
*
* %derived_by: u260001 %
* %release: EPflex/Vf %
* %full_filespec: TPM_nvm.c-3.0:csrc:2 %
*
*******************************************************************************/


#ifndef _TPM_NVM_C_
#define _TPM_NVM_C_
#include "TPM_nvm.h"
#define TPM_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TPM_MemMap.h"
TPM_SNV_Z1_CST_16BIT TPM_sNV_Z1_CST_16BIT;
#define TPM_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "TPM_MemMap.h"
const TPM_SNV_Z1_CST_16BIT TPM_sNV_Z1_CST_16BIT_r={2240,2240};
#define TPM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "TPM_MemMap.h"
#endif 

