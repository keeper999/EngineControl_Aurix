#ifndef _COSTOPSTART_NVM__H_
#define _COSTOPSTART_NVM__H_

/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
typedef struct
{
	SInt16 CoReqRstrt_tiRStrtSlowMem_NV;
	SInt16 CoReqRstrt_nTDC2SlowMem_NV;
	SInt16 CoReqRstrt_nTDC1SlowMem_NV;
	SInt16 CoReqRstrt_nTDC2FastMem_NV;
	SInt16 CoReqRstrt_nTDC1FastMem_NV;
	SInt16 CoReqRstrt_tiRStrtFastMem_NV;
	UInt16 CoReqRstrt_ctRStrtMem_NV;
} CoStopStart_StructNvm_1;

typedef struct
{
	SInt8 CoReqRstrt_nTDC1FastPoor_NV;
	SInt8 CoReqRstrt_nTDC1SlowPoor_NV;
	UInt8 CoReqRstrt_nTDC1PredPoor_NV;
	UInt8 CoReqRstrt_iElNwPoor_NV;
	UInt8 CoReqRstrt_nTDC1Poor_NV;
	UInt8 CoReqRstrt_tRvAltStatPoor_NV;
	UInt8 CoReqRstrt_agEsPoor_NV;
	UInt8 CoReqRstrt_uBattOcPoor_NV;
	UInt8 CoReqRstrt_uUcapMesPoor_NV;
	UInt8 CoReqRstrt_resBattPoor_NV;
	UInt8 CoReqRstrt_pAirExtMesPoor_NV;
	UInt8 CoReqRstrt_tMesPoor_NV;
}CoStopStart_StructNvm_2;

typedef struct
{
	UInt8 CoPtUH_stAftsRStrtSuc_NV;
	UInt8 CoPtUH_stFbSpcFactRStrtSuc_NV;
	UInt8 CoReqRstrt_ctRstrtFail_NV;
}CoStopStart_StructNvm_3;

typedef struct
{
	UInt8 DgoFct_noMemValHealLvl2_NV;
}CoStopStart_StructNvm_4;

typedef struct
{
	Boolean MgtDrv_bDftHld_NV;
}CoStopStart_StructNvm_5;

typedef struct
{
	Boolean DgoFct_bMemValPrvtLvl1_NV;
	Boolean DgoFct_bMemValHealLvl1_NV;
}CoStopStart_StructNvm_6;

/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/
#define COSTOPSTART_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "CoStopStart_MemMap.h"
extern CoStopStart_StructNvm_1 CoStopStart_sNV_Z1_CST_16BIT_1;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "CoStopStart_MemMap.h"
extern const CoStopStart_StructNvm_1 CoStopStart_sNV_Z1_CST_16BIT_1_r;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "CoStopStart_MemMap.h"
extern CoStopStart_StructNvm_2 CoStopStart_sNV_Z1_CST_8BIT_1;
extern CoStopStart_StructNvm_3 CoStopStart_sNV_Z1_CST_8BIT_2;
extern CoStopStart_StructNvm_4 CoStopStart_sNV_Z1_CST_8BIT_3;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "CoStopStart_MemMap.h"
extern const CoStopStart_StructNvm_2 CoStopStart_sNV_Z1_CST_8BIT_1_r;
extern const CoStopStart_StructNvm_3 CoStopStart_sNV_Z1_CST_8BIT_2_r;
extern const CoStopStart_StructNvm_4 CoStopStart_sNV_Z1_CST_8BIT_3_r;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "CoStopStart_MemMap.h"
extern CoStopStart_StructNvm_5 CoStopStart_sNV_Z1_CST_BOOLEAN_1;
extern CoStopStart_StructNvm_6 CoStopStart_sNV_Z1_CST_BOOLEAN_2;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "CoStopStart_MemMap.h"
extern const CoStopStart_StructNvm_5 CoStopStart_sNV_Z1_CST_BOOLEAN_1_r;
extern const CoStopStart_StructNvm_6 CoStopStart_sNV_Z1_CST_BOOLEAN_2_r;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

#endif/*_COSTOPSTART_NVM__H_ */
/*----------------------------------------------------------------------------*/
/*  END OF FILE */
/*-----------*/
