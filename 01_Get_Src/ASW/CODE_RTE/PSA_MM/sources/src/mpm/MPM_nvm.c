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
* %name: MPM_nvm.c %
*
* %version: 2.0_OBS %
*
* %date_modified: Fri Aug 10 10:45:37 2012 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC3 %
* %full_filespec: MPM_nvm.c-2.0_OBS:csrc:2 %
*
*******************************************************************************/


#ifndef _MPM_NVM_C_
#define _MPM_NVM_C_
#include "MPM_nvm.h"
#define MPM_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "MPM_MemMap.h"
MPM_SNV_Z1_CST_16BIT MPM_sNV_Z1_CST_16BIT;
#define MPM_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "MPM_MemMap.h"
MPM_SNV_Z1_CST_32BIT MPM_sNV_Z1_CST_32BIT;MPM_SNV_Z1_CST_32BIT_1 
MPM_sNV_Z1_CST_32BIT_1;MPM_SNV_Z1_CST_32BIT_2 MPM_sNV_Z1_CST_32BIT_2;
#define MPM_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "MPM_MemMap.h"
const MPM_SNV_Z1_CST_16BIT MPM_sNV_Z1_CST_16BIT_r={16384};
#define MPM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "MPM_MemMap.h"
const MPM_SNV_Z1_CST_32BIT MPM_sNV_Z1_CST_32BIT_r={100000000,0,134217728};const 
MPM_SNV_Z1_CST_32BIT_1 MPM_sNV_Z1_CST_32BIT_1_r={134217728};const 
MPM_SNV_Z1_CST_32BIT_2 MPM_sNV_Z1_CST_32BIT_2_r={134217728};
#define MPM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "MPM_MemMap.h"
#endif 

