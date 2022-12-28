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
* %name:  ThMgt_nvm.h %
*
* %version:  12.1.build1 %
*
* %date_modified:  Thu Oct 27 17:25:23 2011 %
*
*
* %derived_by:  u380306 %
* %release:ThMgt/12.1 %
* %full_filespec:  ThMgt_nvm.h-12.1.build1:incl:8 %
*
*******************************************************************************/


#ifndef _THMGT_NVM_H_
#define _THMGT_NVM_H_
/*----------------------------------------------------------------------------
  INCLUDES
----------------------------------------------------------------------------*/
#include "tl_basetypes.h"
#include "tl_defines.h"

typedef struct
{
Boolean ThMgt_bRefFSFReq_NV;
}ThMgt_SNV_Z1_CST_BOOLEAN;

typedef struct
{
UInt8 ThMgt_stDiagFctFSF_NV;
}ThMgt_SNV_Z1_CST_8BIT;

#define THMGT_START_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "ThMgt_MemMap.h"
extern ThMgt_SNV_Z1_CST_BOOLEAN ThMgt_sNV_Z1_CST_BOOLEAN;
#define THMGT_STOP_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "ThMgt_MemMap.h"
extern ThMgt_SNV_Z1_CST_8BIT ThMgt_sNV_Z1_CST_8BIT;
#define THMGT_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "ThMgt_MemMap.h"
extern const ThMgt_SNV_Z1_CST_BOOLEAN ThMgt_sNV_Z1_CST_BOOLEAN_r;
#define THMGT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "ThMgt_MemMap.h"
extern const ThMgt_SNV_Z1_CST_8BIT ThMgt_sNV_Z1_CST_8BIT_r;
#define THMGT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "ThMgt_MemMap.h"



#endif /*_THMGT_NVM_H_ */
/*----------------------------------------------------------------------------*/
/* END OF FILE */
/*----------------------------------------------------------------------------*/
