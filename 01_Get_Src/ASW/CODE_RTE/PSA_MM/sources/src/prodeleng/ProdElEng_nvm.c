/**************************************************************************************************\

 Fichier a creer manuellement


//\**************************************************************************************************/

#ifndef _PRODELENG_NVM__C_
#define _PRODELENG_NVM__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "ProdElEng_nvm.h"


#define PRODELENG_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEng_MemMap.h"
ProdElEng_StructNvm_1 ProdElEng_sNV_Z1_CST_32BIT_1;
#define PRODELENG_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEng_MemMap.h"
const ProdElEng_StructNvm_1 ProdElEng_sNV_Z1_CST_32BIT_1_r = {0};
#define PRODELENG_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEng_MemMap.h"

#endif/*_PRODELENG_NVM__C_ */
/*----------------------------------------------------------------------------*/
/*  END OF FILE */
/*-----------*/
