/***************************************************************************
;**
;** FILE NAME      : PMPHAL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PMPHAL_CFG_E.h"
#include "PMPHAL_E.h"
#include "TYPE.h"
#include "PMPHAL.H"
#include "PMPHAL_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#pragma section ".calib" a
const uint8  PMPHAL_ku8NbSpillEventsRqstd = 0;
const uint16  PMPHAL_ku16SpillEventAngleRqstd = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
uint8 PMPHAL_enuCapcomDelayState;
uint8 PMPHAL_enuCommandMode;
uint8 PMPHAL_enuComponentStatus;
boolean PMPHAL_bActuationProgrammed;
boolean PMPHAL_bFirstSpillEventOk;
boolean PMPHAL_bGioCmdLevel;
boolean PMPHAL_bProfSwitchProgrammed;
boolean PMPHAL_bSpillCmdRequested;
boolean PMPHAL_bSpillEventParamOk;
uint32 PMPHAL_u32PrevSpillDecelTime;
uint32 PMPHAL_u32PrevSwitchDlyTime;
uint32 PMPHAL_u32ProfSwitchDlyTime;
uint32 PMPHAL_u32RelDecelDelayValue;
uint32 PMPHAL_u32SpillCmdTime;
uint32 PMPHAL_u32SpillDecelDelay;
uint32 PMPHAL_u32SpillDecelTime;
Std_ReturnType PMPHAL_udtCurrentProfileStatus;
Std_ReturnType PMPHAL_udtProfileSwitchRqstStatus;
uint8 PMPHAL_u8CmdPulseProfileId;
uint8 PMPHAL_u8CurrentProfileId;
uint8 PMPHAL_u8DecelPulseProfileId;
uint8 PMPHAL_u8DecelPulseProfileIdMem;
uint8 PMPHAL_u8NbSpillEventsRqstd;
uint8 PMPHAL_u8SpillEventCounter;
uint16 PMPHAL_u16InterSpillEventAngle;
uint16 PMPHAL_u16NextSpillCmdAngle;
uint16 PMPHAL_u16NextSpillEventAngle;
uint16 PMPHAL_u16PrevSpillEventAngle;
uint16 PMPHAL_u16SpillCmdAngle;
uint16 PMPHAL_u16SpillEventAngleRqstd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

