/**************************************************************************************************\

    PROTOTYPE DES FONCTIONS DE LECTURE ET D'ECRITURE DES VARIABLES NVM

\**************************************************************************************************/

#ifndef _COEMSTT_NVM__H_
#define _COEMSTT_NVM__H_

#include "tl_defines.h"
#include "tl_basetypes.h"

typedef struct {
SInt8 CoEmSTT_iDevRstrt1_NV;
SInt8 CoEmSTT_iDevRstrt2_NV;
UInt8 CoEmSTT_uBattStrtMin1_NV;
UInt8 CoEmSTT_uBattStrtMin2_NV;
UInt8 CoEmSTT_uBattStrtMin3_NV;
UInt8 CoEmSTT_uBattStrtMin4_NV;
UInt8 CoEmSTT_uBattStrtMin5_NV;
UInt8 CoEmSTT_uBattStrtMin6_NV;
UInt8 CoEmSTT_uBattStrtMin7_NV;
UInt8 CoEmSTT_uBattStrtMin8_NV;
UInt8 CoEmSTT_uBattStrtMin9_NV;
SInt8 CoEmSTT_tiDevRstrt_NV;
}CoEmSTT_sNV_Z1_8BIT_1;

typedef struct {
SInt16 CoEmSTT_iElNwStop1_NV;
SInt16 CoEmSTT_iElNwStop2_NV;
SInt16 CoEmSTT_iElNwStop3_NV;
}CoEmSTT_sNV_Z1_16BIT_1;

typedef struct {
UInt32 CoEmSTT_ctBoostUcap_NV;
}CoEmSTT_sNV_Z1_32BIT_1;
//NVRAM Data with recovery values are constants

#define COEMSTT_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "CoEmSTT_MemMap.h"
extern CoEmSTT_sNV_Z1_8BIT_1 CoEmSTT_sNV_Z1_CST_8BIT_1;
#define COEMSTT_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "CoEmSTT_MemMap.h"
extern const CoEmSTT_sNV_Z1_8BIT_1 CoEmSTT_sNV_Z1_CST_8BIT_1_r;
#define COEMSTT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "CoEmSTT_MemMap.h"


#define COEMSTT_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "CoEmSTT_MemMap.h"
extern CoEmSTT_sNV_Z1_16BIT_1 CoEmSTT_sNV_Z1_CST_16BIT_1;
#define COEMSTT_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "CoEmSTT_MemMap.h"
extern const CoEmSTT_sNV_Z1_16BIT_1 CoEmSTT_sNV_Z1_CST_16BIT_1_r;
#define COEMSTT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "CoEmSTT_MemMap.h"


#define COEMSTT_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "CoEmSTT_MemMap.h"
extern CoEmSTT_sNV_Z1_32BIT_1 CoEmSTT_sNV_Z1_CST_32BIT_1;
#define COEMSTT_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "CoEmSTT_MemMap.h"
extern const CoEmSTT_sNV_Z1_32BIT_1 CoEmSTT_sNV_Z1_CST_32BIT_1_r;
#define COEMSTT_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "CoEmSTT_MemMap.h"


#endif/*_COEMSTT_NVM__H_ */
/*----------------------------------------------------------------------------*/
/*  END OF FILE */
/*-----------*/
