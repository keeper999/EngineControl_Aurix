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
* %name:  StopStrtEm_nvm.c %
*
* %version:  4.4 %
*
* %date_modified:  Thu May 23 18:30:19 2013 %
*
*
* %derived_by:  u261238 %
* %release:StopStrtEm/5.0 %
* %full_filespec:  StopStrtEm_nvm.c-4.4:csrc:1 %
*
*******************************************************************************/


#ifndef _STOPSTRTEM_NVM_C_
#define _STOPSTRTEM_NVM_C_
/*----------------------------------------------------------------------------
  INCLUDES
----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "StopStrtEm_nvm.h"
#include "StopStrtEm_004_TEV_fct.h"

#define STOPSTRTEM_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "StopStrtEm_MemMap.h"
StopStrtEm_SNV_Z1_CST_32BIT_1 StopStrtEm_sNV_Z1_CST_32BIT_1;
StopStrtEm_SNV_Z1_CST_32BIT_2 StopStrtEm_sNV_Z1_CST_32BIT_2;
#define STOPSTRTEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "StopStrtEm_MemMap.h"
StopStrtEm_SNV_Z1_CST_16BIT_3 StopStrtEm_sNV_Z1_CST_16BIT_3;
#define STOPSTRTEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "StopStrtEm_MemMap.h"
const StopStrtEm_SNV_Z1_CST_32BIT_1 StopStrtEm_sNV_Z1_CST_32BIT_1_r = {0,0,0,0,0};
const StopStrtEm_SNV_Z1_CST_32BIT_2 StopStrtEm_sNV_Z1_CST_32BIT_2_r = {0,0};
#define STOPSTRTEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "StopStrtEm_MemMap.h"
const StopStrtEm_SNV_Z1_CST_16BIT_3 StopStrtEm_sNV_Z1_CST_16BIT_3_r = {{50,50,50}};
#define STOPSTRTEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "StopStrtEm_MemMap.h"

#endif /*_STOPSTRTEM_NVM_C_ */
/*----------------------------------------------------------------------------*/
/* END OF FILE */
/*----------------------------------------------------------------------------*/
