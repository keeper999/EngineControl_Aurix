#ifndef _COSTOPSTART_NVM__C_
#define _COSTOPSTART_NVM__C_

/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "CoStopStart_nvm.h"

/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

#define COSTOPSTART_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "CoStopStart_MemMap.h"
CoStopStart_StructNvm_1 CoStopStart_sNV_Z1_CST_16BIT_1;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "CoStopStart_MemMap.h"
const CoStopStart_StructNvm_1 CoStopStart_sNV_Z1_CST_16BIT_1_r = {0,0,0,0,0,0,0};
#define COSTOPSTART_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "CoStopStart_MemMap.h"
CoStopStart_StructNvm_2 CoStopStart_sNV_Z1_CST_8BIT_1;
CoStopStart_StructNvm_3 CoStopStart_sNV_Z1_CST_8BIT_2;
CoStopStart_StructNvm_4 CoStopStart_sNV_Z1_CST_8BIT_3;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "CoStopStart_MemMap.h"
const CoStopStart_StructNvm_2 CoStopStart_sNV_Z1_CST_8BIT_1_r = {0,0,0,5,25,0,0,160,48,64,112,5};
const CoStopStart_StructNvm_3 CoStopStart_sNV_Z1_CST_8BIT_2_r = {0,0,0};
const CoStopStart_StructNvm_4 CoStopStart_sNV_Z1_CST_8BIT_3_r = {0};
#define COSTOPSTART_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "CoStopStart_MemMap.h"
CoStopStart_StructNvm_5 CoStopStart_sNV_Z1_CST_BOOLEAN_1;
CoStopStart_StructNvm_6 CoStopStart_sNV_Z1_CST_BOOLEAN_2;
#define COSTOPSTART_STOP_SEC_VAR_SAVED_ZONE1_CONST_BOOLEAN
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "CoStopStart_MemMap.h"
const CoStopStart_StructNvm_5 CoStopStart_sNV_Z1_CST_BOOLEAN_1_r = {0};
const CoStopStart_StructNvm_6 CoStopStart_sNV_Z1_CST_BOOLEAN_2_r = {0,0};
#define COSTOPSTART_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_BOOLEAN
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------*\
  FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

#endif/*_COSTOPSTART_NVM__C_ */
/*----------------------------------------------------------------------------*/
/*  END OF FILE */
/*-----------*/
