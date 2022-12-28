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
* %name: MPM_nvm.h %
*
* %version: 2.0_OBS %
*
* %date_modified: Fri Aug 10 10:45:38 2012 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC3 %
* %full_filespec: MPM_nvm.h-2.0_OBS:incl:2 %
*
*******************************************************************************/


#ifndef _MPM_NVM_H_
#define _MPM_NVM_H_
#include "tl_basetypes.h"
#include "tl_defines.h"
typedef struct{UInt16 DmgMSI_rCylHdInjDmgCnt_NV;}MPM_SNV_Z1_CST_16BIT;typedef 
struct{UInt32 DmgMSI_rCylBlockDmg_NV;UInt32 DmgMSI_rCylHdInjDmgInter_NV;UInt32 
DmgMSI_rCylHdDmg_NV;}MPM_SNV_Z1_CST_32BIT;typedef struct{UInt32 
DmgMSI_rTrbCaseDmg_NV;}MPM_SNV_Z1_CST_32BIT_1;typedef struct{UInt32 
DmgMSI_rExMnfDmg_NV;}MPM_SNV_Z1_CST_32BIT_2;
#define MPM_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "MPM_MemMap.h"
extern MPM_SNV_Z1_CST_16BIT MPM_sNV_Z1_CST_16BIT;
#define MPM_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "MPM_MemMap.h"
extern MPM_SNV_Z1_CST_32BIT MPM_sNV_Z1_CST_32BIT;extern MPM_SNV_Z1_CST_32BIT_1 
MPM_sNV_Z1_CST_32BIT_1;extern MPM_SNV_Z1_CST_32BIT_2 MPM_sNV_Z1_CST_32BIT_2;
#define MPM_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "MPM_MemMap.h"
extern const MPM_SNV_Z1_CST_16BIT MPM_sNV_Z1_CST_16BIT_r;
#define MPM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "MPM_MemMap.h"
extern const MPM_SNV_Z1_CST_32BIT MPM_sNV_Z1_CST_32BIT_r;extern const 
MPM_SNV_Z1_CST_32BIT_1 MPM_sNV_Z1_CST_32BIT_1_r;extern const 
MPM_SNV_Z1_CST_32BIT_2 MPM_sNV_Z1_CST_32BIT_2_r;
#define MPM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "MPM_MemMap.h"
#endif 

