/***************************************************************************
;**
;** FILE NAME      : PMPHAL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PMPHAL_L_H
#define PMPHAL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PMPHAL_CFG_E.h"
#include "PMPHAL_E.h"
#include "TYPE.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define PMPHAL_u16_1_DEGREE               64
#define PMPHAL_u16_6_DEG_FOR_1ST_EVENT    384
#define PMPHAL_u16ENGINE_CYCLE            46080
#define PMPHAL_u16UNKNOWN_ANGLE           65535

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st3pmp */
#define PMPHAL_enuSWITCH_CMD_PROFILE      1
#define PMPHAL_enuSWITCH_DECEL_PROFILE    2
#define PMPHAL_enuDECEL_DELAY_STATE       4
/*extern uint8 PMPHAL_enuCapcomDelayState;*/

/* enum st2pmp */
#define PMPHAL_enuCONTINUOUS_MODE         1
#define PMPHAL_enuSEQUENTIAL_MODE         2
/*extern uint8 PMPHAL_enuCommandMode;*/

/* enum st1pmp */
#define PMPHAL_enuINIT_STATE              1
#define PMPHAL_enuDISABLED                2
#define PMPHAL_enuEVENT_ON_CMD_ON         4
#define PMPHAL_enuEVENT_ON_CMD_OFF        8
#define PMPHAL_enuEVENT_OFF_CMD_OFF       16
#define PMPHAL_enuEVENT_OFF_CMD_ON        32
/*extern uint8 PMPHAL_enuComponentStatus;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  PMPHAL_ku8NbSpillEventsRqstd;
extern const uint16  PMPHAL_ku16SpillEventAngleRqstd;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern uint8 PMPHAL_enuCapcomDelayState;
extern uint8 PMPHAL_enuCommandMode;
extern uint8 PMPHAL_enuComponentStatus;
extern boolean PMPHAL_bActuationProgrammed;
extern boolean PMPHAL_bFirstSpillEventOk;
extern boolean PMPHAL_bGioCmdLevel;
extern boolean PMPHAL_bProfSwitchProgrammed;
extern boolean PMPHAL_bSpillCmdRequested;
extern boolean PMPHAL_bSpillEventParamOk;
extern uint32 PMPHAL_u32PrevSpillDecelTime;
extern uint32 PMPHAL_u32PrevSwitchDlyTime;
extern uint32 PMPHAL_u32ProfSwitchDlyTime;
extern uint32 PMPHAL_u32RelDecelDelayValue;
extern uint32 PMPHAL_u32SpillCmdTime;
extern uint32 PMPHAL_u32SpillDecelDelay;
extern uint32 PMPHAL_u32SpillDecelTime;
extern Std_ReturnType PMPHAL_udtCurrentProfileStatus;
extern Std_ReturnType PMPHAL_udtProfileSwitchRqstStatus;
extern uint8 PMPHAL_u8CmdPulseProfileId;
extern uint8 PMPHAL_u8CurrentProfileId;
extern uint8 PMPHAL_u8DecelPulseProfileId;
extern uint8 PMPHAL_u8DecelPulseProfileIdMem;
extern uint8 PMPHAL_u8NbSpillEventsRqstd;
extern uint8 PMPHAL_u8SpillEventCounter;
extern uint16 PMPHAL_u16InterSpillEventAngle;
extern uint16 PMPHAL_u16NextSpillCmdAngle;
extern uint16 PMPHAL_u16NextSpillEventAngle;
extern uint16 PMPHAL_u16PrevSpillEventAngle;
extern uint16 PMPHAL_u16SpillCmdAngle;
extern uint16 PMPHAL_u16SpillEventAngleRqstd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* PMPHAL_L_H */

/*-------------------------------- end of file -------------------------------*/
