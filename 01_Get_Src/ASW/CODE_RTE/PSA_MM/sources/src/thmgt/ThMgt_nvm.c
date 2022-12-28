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
* %name:  ThMgt_nvm.c %
*
* %version:  12.1.build1 %
*
* %date_modified:  Thu Oct 27 17:25:07 2011 %
*
*
* %derived_by:  u380306 %
* %release:ThMgt/12.1 %
* %full_filespec:  ThMgt_nvm.c-12.1.build1:csrc:6 %
*
*******************************************************************************/


#ifndef _THMGT_NVM_C_
#define _THMGT_NVM_C_
/*----------------------------------------------------------------------------
  INCLUDES
----------------------------------------------------------------------------*/
#include "ThMgt_nvm.h"

#define THMGT_START_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "ThMgt_MemMap.h"
ThMgt_SNV_Z1_CST_BOOLEAN ThMgt_sNV_Z1_CST_BOOLEAN;
#define THMGT_STOP_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "ThMgt_MemMap.h"
ThMgt_SNV_Z1_CST_8BIT ThMgt_sNV_Z1_CST_8BIT;
#define THMGT_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "ThMgt_MemMap.h"
const ThMgt_SNV_Z1_CST_BOOLEAN ThMgt_sNV_Z1_CST_BOOLEAN_r={0};
#define THMGT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "ThMgt_MemMap.h"
const ThMgt_SNV_Z1_CST_8BIT ThMgt_sNV_Z1_CST_8BIT_r={0};
#define THMGT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "ThMgt_MemMap.h"



#endif /*_THMGT_NVM_C_ */
/*----------------------------------------------------------------------------*/
/* END OF FILE */
/*----------------------------------------------------------------------------*/
