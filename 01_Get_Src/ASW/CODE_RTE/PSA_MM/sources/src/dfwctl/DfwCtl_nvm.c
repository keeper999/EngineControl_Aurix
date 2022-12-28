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
* %name: DfwCtl_nvm.c %
*
* %version: 1.3.build4 %
*
* %date_modified: Thu Nov 17 16:46:29 2011 %
*
*
* %derived_by: e360487 %
* %release: DfwCtl/1.0 %
* %full_filespec: DfwCtl_nvm.c-1.3.build4:csrc:1 %
*
*******************************************************************************/

#ifndef _DFWCTL_NVM_C_
#define _DFWCTL_NVM_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "tl_basetypes.h"
#include "tl_defines.h"
#include "DfwCtl_nvm.h"

#define DFWCTL_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "DfwCtl_MemMap.h"
DfwCtl_SNV_Z1_CST_16BIT DfwCtl_sNV_Z1_CST_16BIT;
#define DFWCTL_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "DfwCtl_MemMap.h"

#define DFWCTL_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "DfwCtl_MemMap.h"
const DfwCtl_SNV_Z1_CST_16BIT DfwCtl_sNV_Z1_CST_16BIT_r = {{0,0}};
#define DFWCTL_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "DfwCtl_MemMap.h"


#endif /*_DFWCTL_NVM_C_ */
/*----------------------------------------------------------------------------*/
/* END OF FILE */
/*----------------------------------------------------------------------------*/
