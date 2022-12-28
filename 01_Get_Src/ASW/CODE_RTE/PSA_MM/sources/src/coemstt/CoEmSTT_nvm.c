/**************************************************************************************************\

 Fichier a creer manuellement


//\**************************************************************************************************/

#ifndef _COEMSTT_NVM__C_
#define _COEMSTT_NVM__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "CoEmSTT_nvm.h"

#define COEMSTT_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "CoEmSTT_MemMap.h"
CoEmSTT_sNV_Z1_8BIT_1 CoEmSTT_sNV_Z1_CST_8BIT_1;
#define COEMSTT_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "CoEmSTT_MemMap.h"
const CoEmSTT_sNV_Z1_8BIT_1 CoEmSTT_sNV_Z1_CST_8BIT_1_r={0,0,208,208,208,208,208,208,208,208,208,0};
#define COEMSTT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "CoEmSTT_MemMap.h"


#define COEMSTT_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "CoEmSTT_MemMap.h"
CoEmSTT_sNV_Z1_16BIT_1 CoEmSTT_sNV_Z1_CST_16BIT_1;
#define COEMSTT_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "CoEmSTT_MemMap.h"
const CoEmSTT_sNV_Z1_16BIT_1 CoEmSTT_sNV_Z1_CST_16BIT_1_r={0,0,0};
#define COEMSTT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "CoEmSTT_MemMap.h"


#define COEMSTT_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "CoEmSTT_MemMap.h"
CoEmSTT_sNV_Z1_32BIT_1 CoEmSTT_sNV_Z1_CST_32BIT_1;
#define COEMSTT_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "CoEmSTT_MemMap.h"
const CoEmSTT_sNV_Z1_32BIT_1 CoEmSTT_sNV_Z1_CST_32BIT_1_r={0};
#define COEMSTT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "CoEmSTT_MemMap.h"

#endif /*_COEMSTT_NVM__C_ */
/*----------------------------------------------------------------------------*/
/*  END OF FILE */
/*-----------*/
