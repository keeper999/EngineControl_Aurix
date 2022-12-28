/***************************************************************************
;**
;** FILE NAME      : ENGSTAB_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGSTAB_L_H
#define ENGSTAB_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  ENGSTAB_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Engine_conditions;
extern boolean Engine_load_not_stable;
extern boolean Engine_stabilised_eng_running;
extern boolean ENGSTAB_bVehicleRunning;
extern boolean Gear_engaged_not_stable;
extern uint8 Engine_load_last;
extern uint8 Engine_load_t_d_c;
extern uint8 Engine_stable_t_d_c;
extern uint8 Gear_engaged_last;
extern uint8 Gear_engaged_t_d_c;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ENGSTAB_vidCalcEngineStabilised(void);
void ENGSTAB_vidCheckEngineLoadStable(void);
void ENGSTAB_vidCheckGearEngagedStab(void);
void ENGSTAB_vidEngCondTimer(void);
void ENGSTAB_vidEngCondTimerOut(void);
void ENGSTAB_vidEngineConditions(void);
void ENGSTAB_vidEngineCondNotStable(void);
void ENGSTAB_vidEngineCondStable(void);
void ENGSTAB_vidEngLoadTimer(void);
void ENGSTAB_vidEngLoadTimerOut(void);
void ENGSTAB_vidGearEngagedTimer(void);
void ENGSTAB_vidGearEngagedTimerOut(void);
void ENGSTAB_vidInitEngineStabilised(void);
void ENGSTAB_vidVehicleNotRunning(void);
void ENGSTAB_vidVehicleRunning(void);
void ENGSTAB_vidVehicleRunningCond(void);


#endif /* ENGSTAB_L_H */

/*-------------------------------- end of file -------------------------------*/
