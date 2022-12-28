/***************************************************************************
;**
;** FILE NAME      : FUCNS_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FUCNS_L_H
#define FUCNS_L_H

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

extern const uint8  FUCNS_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 FuCns_mFuInjTotTemp;
extern uint32 FUCNS_u32InstantUsedFuelMem;
extern uint32 FUCNS_u32InstantUsedFuelMem1;
extern uint32 FUCNS_u32UsedFuelPerHourMem;
extern uint8 Conso_carburant_can_InjDir;
extern uint8 Conso_carburant_can_InjInd;
extern uint8 Conso_Inst_InjDir;
extern uint8 Conso_Inst_InjInd;
extern uint16 Conso_carb_entre_trame_InjDir;
extern uint16 Conso_carburant_entre_trame;
extern uint16 FuCns_mFuWoutPurgeOxCTemp;
extern uint16 Fuel_used_between_frame_InjDir;
extern uint16 Fuel_used_not_counted_InjDir;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FUCNS_vidActTotalInjFuelInjDir(void);
void FUCNS_vidCalcFuelConsBwnFrInjDir(void);
void FUCNS_vidCalcFuelConsoInjDir(void);
void FUCNS_vidCalcFuelUsedBetweenFram(void);
void FUCNS_vidCalcFuelUsedNotCounted(void);
void FUCNS_vidCalcFuelUseNotCntInjDir(void);
void FUCNS_vidCalcInstantConsoInjDir(void);
void FUCNS_vidCalcInstantUsedFuel(void);
void FUCNS_vidCalcPseudoConso(void);
void FUCNS_vidCalcRealConso(void);
void FUCNS_vidCalcTotalMassInj(void);
void FUCNS_vidCalcUsedFuel(void);
void FUCNS_vidCalcUsedFuelPerHour(void);
void FUCNS_vidCalFuelUseBwnFrmeInjDir(void);
void FUCNS_vidDirectInjCount(void);
void FUCNS_vidFinalInstructionCalc(void);
void FUCNS_vidInit(void);
void FUCNS_vidInitOutput(void);
void FUCNS_vidSendFrame(void);
void FUCNS_vidUpdatingTotalInjTime(void);


#endif /* FUCNS_L_H */

/*-------------------------------- end of file -------------------------------*/
