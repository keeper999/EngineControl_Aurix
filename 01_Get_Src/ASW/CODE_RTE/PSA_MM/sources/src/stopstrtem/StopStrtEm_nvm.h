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
* %name:  StopStrtEm_nvm.h %
*
* %version:  4.2 %
*
* %date_modified:  Thu Dec 22 14:09:19 2011 %
*
*
* %derived_by:  e375697 %
* %release:StopStrtEm/4.0 %
* %full_filespec:  StopStrtEm_nvm.h-4.2:incl:1 %
*
*******************************************************************************/


#ifndef _STOPSTRTEM_NVM_H_
#define _STOPSTRTEM_NVM_H_
/*----------------------------------------------------------------------------
  INCLUDES
----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"

typedef struct
{
UInt32 StaStrtMgt_ctStaAcv_NV;
UInt32 StaStrtMgt_ctStaRstrtAcv_NV;
UInt32 StaStrtMgt_ctStaStrtAcv_NV;
UInt32 StaStrtMgt_dstStaSubMes_NV;
UInt32 StaStrtMgt_ctStaSubTi_NV;
} StopStrtEm_SNV_Z1_CST_32BIT_1;
//NVRAM Data with recovery values are constants

typedef struct
{
UInt32 StaStrtMgt_ctLastConnTi_NV;
UInt32 StaStrtMgt_ctTotTi_NV;
} StopStrtEm_SNV_Z1_CST_32BIT_2;
//NVRAM Data with recovery values are constants

typedef struct
{
SInt16 StaStrtMgt_tSta_NV[3];
} StopStrtEm_SNV_Z1_CST_16BIT_3;
//NVRAM Data with recovery values are constants

#define STOPSTRTEM_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "StopStrtEm_MemMap.h"
extern StopStrtEm_SNV_Z1_CST_32BIT_1 StopStrtEm_sNV_Z1_CST_32BIT_1;
extern StopStrtEm_SNV_Z1_CST_32BIT_2 StopStrtEm_sNV_Z1_CST_32BIT_2;
#define STOPSTRTEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "StopStrtEm_MemMap.h"
extern StopStrtEm_SNV_Z1_CST_16BIT_3 StopStrtEm_sNV_Z1_CST_16BIT_3;
#define STOPSTRTEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "StopStrtEm_MemMap.h"
extern const StopStrtEm_SNV_Z1_CST_32BIT_1 StopStrtEm_sNV_Z1_CST_32BIT_1_r;
extern const StopStrtEm_SNV_Z1_CST_32BIT_2 StopStrtEm_sNV_Z1_CST_32BIT_2_r;
#define STOPSTRTEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "StopStrtEm_MemMap.h"
extern const StopStrtEm_SNV_Z1_CST_16BIT_3 StopStrtEm_sNV_Z1_CST_16BIT_3_r;
#define STOPSTRTEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "StopStrtEm_MemMap.h"

#endif /*_STOPSTRTEM_NVM_H_ */
/*----------------------------------------------------------------------------*/
/* END OF FILE */
/*----------------------------------------------------------------------------*/
