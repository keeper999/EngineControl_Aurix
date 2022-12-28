#ifndef _MAN_EEPROM_PRODELEM__H_
#define _MAN_EEPROM_PRODELEM__H_

//#include "tl_defines.h"
#include "tl_basetypes.h"
typedef struct
{
Boolean BatMgt_bBattSoCSub_NV;
} ProdElEm_StructNvm_1;

typedef struct
{
Boolean BatMgt_bAcvMemSoH_NV;
} ProdElEm_StructNvm_1_2;


typedef struct
{
SInt8 ElProdMgt_uOfsSpMesProdMv_NV;
UInt8 BatMgt_ctStcCnclAntiAgiStra_NV;
} ProdElEm_StructNvm_2;

typedef struct
{
UInt8 BatMgt_stLastMemSoH_NV;
UInt8 BatMgt_noAcvFastMemSoH_NV;
UInt8 BatMgt_ctStcEndAntiAgiStra_NV;
} ProdElEm_StructNvm_2_2;

typedef struct
{
UInt16 CoOptmEl_noMaxAcvTHom_NV;
UInt16 ElProdMgt_resWireEstim_NV[4];
UInt16 CoOptmEl_rBattSoCWup_NV;
} ProdElEm_StructNvm_3;

typedef struct
{
UInt16 BatMgt_tiVehAntiAgiNotRun_NV;
SInt16 BatMgt_iOfsBattSoC1_NV;
SInt16 BatMgt_iOfsBattSoC2_NV;
SInt16 BatMgt_iOfsBattSoC3_NV;
SInt16 BatMgt_iOfsBattSoC4_NV;
SInt16 BatMgt_iOfsBattSoC5_NV;
SInt16 BatMgt_iOfsBattSoC6_NV;
SInt16 BatMgt_iOfsBattSoC7_NV;
SInt16 BatMgt_iOfsBattSoC8_NV;
UInt16 BatMgt_resBattIt1_NV;
UInt16 BatMgt_resBattIt2_NV;
UInt16 BatMgt_resBattIt3_NV;
UInt16 BatMgt_tiVehAntiAgi_NV;
UInt16 BatMgt_rStcSoCMax_NV;
UInt16 BatMgt_rStcSoCMin_NV;
} ProdElEm_StructNvm_3_2;


typedef struct
{
UInt32 BatMgt_dstVeh_NV;
UInt32 BatMgt_dstVehAntiAgi_NV;
UInt32 CoOptmEl_tiEngrunBackUp_NV;
UInt32 CoOptmEl_tiElReqBackUp_NV;
UInt32 BatMgt_ctSec_NV;
UInt32 BatMgt_tiOfsVoltAntiAgiStra_NV;
UInt32 CoOptmEl_dstAfterPwtOp_NV;
} ProdElEm_StructNvm_4;

typedef struct
{
UInt32 BatMgt_tiAntiAgiStra_NV;
UInt32 BatMgt_tiStcVoltBattDmg_NV;
} ProdElEm_StructNvm_4_2;

typedef struct
{
UInt32 BatMgt_tiBattSoCClcLrn_NV;
UInt32 BatMgt_rBattSocClc_NV;
} ProdElEm_StructNvm_4_3;

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_1 ProdElEm_sNV_Z1_CST_BOOLEAN_1;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_1_2 ProdElEm_sNV_Z1_CST_BOOLEAN_2;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_1 ProdElEm_sNV_Z1_CST_BOOLEAN_1_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_1_2 ProdElEm_sNV_Z1_CST_BOOLEAN_2_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_2 ProdElEm_sNV_Z1_CST_8BIT_1;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_2_2 ProdElEm_sNV_Z1_CST_8BIT_2;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_2 ProdElEm_sNV_Z1_CST_8BIT_1_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_2_2 ProdElEm_sNV_Z1_CST_8BIT_2_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_3 ProdElEm_sNV_Z1_CST_16BIT_1;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_3_2 ProdElEm_sNV_Z1_CST_16BIT_2;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_3 ProdElEm_sNV_Z1_CST_16BIT_1_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_3_2 ProdElEm_sNV_Z1_CST_16BIT_2_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_4 ProdElEm_sNV_Z1_CST_32BIT_1;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_4_2 ProdElEm_sNV_Z1_CST_32BIT_2;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"
extern ProdElEm_StructNvm_4_3 ProdElEm_sNV_Z1_CST_32BIT_3;
#define PRODELEM_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_4 ProdElEm_sNV_Z1_CST_32BIT_1_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_4_2 ProdElEm_sNV_Z1_CST_32BIT_2_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"
extern const ProdElEm_StructNvm_4_3 ProdElEm_sNV_Z1_CST_32BIT_3_r;
#define PRODELEM_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEm_MemMap.h"

#endif/*_COSTOPSTART_NVM__H_ */
/*----------------------------------------------------------------------------*/
/*  END OF FILE */
/*-----------*/
