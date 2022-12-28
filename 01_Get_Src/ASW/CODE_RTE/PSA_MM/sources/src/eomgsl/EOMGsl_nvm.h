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
* %name:  EOMGsl_nvm.h %
*
* %version:  4.0.build1 %
*
* %date_modified:  Wed Aug 29 08:16:52 2012 %
*
*
* %derived_by:  u391752 %
* %release:EPflex/Vf-1 %
* %full_filespec:  EOMGsl_nvm.h-4.0.build1:incl:2 %
*
*******************************************************************************/


#ifndef _EOMGSL_NVM_H_
#define _EOMGSL_NVM_H_
/*----------------------------------------------------------------------------
  INCLUDES
----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"

typedef struct
{
UInt32 Ext_dstVehTotMes_NV;
} EOMGsl_SNV_Z1_CST_32BIT;
//NVRAM Data with recovery values are constants

#define EOMGSL_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "EOMGsl_MemMap.h"
extern EOMGsl_SNV_Z1_CST_32BIT EOMGsl_sNV_Z1_CST_32BIT;
#define EOMGSL_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "EOMGsl_MemMap.h"

#define EOMGSL_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "EOMGsl_MemMap.h"
extern const EOMGsl_SNV_Z1_CST_32BIT EOMGsl_sNV_Z1_CST_32BIT_r;
#define EOMGSL_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "EOMGsl_MemMap.h"

#endif /*_EOMGSL_NVM_H_ */
/*----------------------------------------------------------------------------*/
/* END OF FILE */
/*----------------------------------------------------------------------------*/
