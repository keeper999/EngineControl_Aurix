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
* %name:  EOMGsl_nvm.c %
*
* %version:  4.0.build1 %
*
* %date_modified:  Wed Aug 29 08:16:52 2012 %
*
*
* %derived_by:  u391752 %
* %release:EPflex/Vf-1 %
* %full_filespec:  EOMGsl_nvm.c-4.0.build1:csrc:2 %
*
*******************************************************************************/


#ifndef _EOMGSL_NVM_C_
#define _EOMGSL_NVM_C_
/*----------------------------------------------------------------------------
  INCLUDES
----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "EOMGsl_nvm.h"

#define EOMGSL_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "EOMGsl_MemMap.h"
EOMGsl_SNV_Z1_CST_32BIT EOMGsl_sNV_Z1_CST_32BIT;
#define EOMGSL_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "EOMGsl_MemMap.h"


#define EOMGSL_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "EOMGsl_MemMap.h"
const EOMGsl_SNV_Z1_CST_32BIT EOMGsl_sNV_Z1_CST_32BIT_r = {0};
#define EOMGSL_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "EOMGsl_MemMap.h"


#endif /*_EOMGSL_NVM_C_ */
/*----------------------------------------------------------------------------*/
/* END OF FILE */
/*----------------------------------------------------------------------------*/
