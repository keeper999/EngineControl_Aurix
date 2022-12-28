/***************************************************************************
;**
;** FILE NAME      : FULVL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FULVL_L_H
#define FULVL_L_H

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

extern const uint8  FULVL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Flev_fuel_level_inc_next;
extern boolean Flev_fuel_level_inc_running;
extern boolean Flev_last_stall_or_key_off;
extern boolean Flev_low_fuel_level_can;
extern boolean Fu_bDgoOc_FuGauge;
extern boolean Fu_bDgoORng_FuGauge;
extern boolean Fu_bDgoORng_FuGaugeLvl;
extern boolean Fu_bDgoScg_FuGauge;
extern boolean Fu_bMonRunOc_FuGauge;
extern boolean Fu_bMonRunORng_FuGauge;
extern boolean Fu_bMonRunORng_FuGaugeLvl;
extern boolean Fu_bMonRunScg_FuGauge;
extern boolean FuLvl_bDgoLoFuLvl;
extern boolean FULVL_bFlevFuelLevelCountPrev;
extern boolean FULVL_bFlevFuelLevelThrshPrev;
extern boolean FULVL_bFlevLowFuelInjInit;
extern boolean FULVL_bFlevLowFuelInjInitPrev;
extern boolean FULVL_bFlevLowFuelLfbkInit;
extern boolean FULVL_bFlevLowFuelLfbkInitPrev;
extern boolean FULVL_bMfCatDamDetUavb0Prev;
extern boolean FuLvl_bMonRunLoFuLvl;
extern uint32 Conso_carbu_totale_ref;
extern uint32 FULVL_u32FiltredFlevFuelLevelMux;
extern uint8 Flev_fuel_level_count;
extern uint8 Flev_fuel_level_delta;
extern uint8 Flev_fuel_level_filtered_ref;
extern uint8 Flev_fuel_level_last;
extern uint8 FULVL_u8FlevFuelLevelCountPrev;
extern uint16 Flev_fuel_level_filtered;
extern uint16 Flev_fuel_level_last_count;
extern uint16 Flev_fuel_level_ref;
extern uint16 Flev_low_level_sw_inj_counter;
extern uint16 Flev_low_level_sw_lfbk_counter;
extern uint16 Flev_low_level_sw_mf_counter;
extern uint16 FULVL_u16FlevFuelLvlLastCntPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FULVL_vid1BisDiagLowFuelLevel(void);
void FULVL_vidCounterDec(void);
void FULVL_vidDetectionRunningEngine(void);
void FULVL_vidEepromWrite(void);
void FULVL_vidFailureInv(void);
void FULVL_vidFailureOc(void);
void FULVL_vidFailureScg(void);
void FULVL_vidFilteringInfoMux(void);
void FULVL_vidFuelGaugeSt(void);
void FULVL_vidFuelGaugeState(void);
void FULVL_vidFuelIncComputeRunning(void);
void FULVL_vidFuelLevel(void);
void FULVL_vidFuelLevelCaleOrOff(void);
void FULVL_vidFuelLevelCompute(void);
void FULVL_vidFuelLevelCpteCaleOrOff(void);
void FULVL_vidFuelLevelIncComputeDem(void);
void FULVL_vidFuelLevelIncCpteDem(void);
void FULVL_vidFuelLevelIncRunning(void);
void FULVL_vidFuelLevelSt(void);
void FULVL_vidFuelLevelState(void);
void FULVL_vidInitEngineRunning(void);
void FULVL_vidInitKeyOffOn(void);
void FULVL_vidInitOutputs(void);
void FULVL_vidInitReset(void);
void FULVL_vidLowFuelLevelHardware(void);
void FULVL_vidLowFuelLevelSoftware(void);
void FULVL_vidLvlIncCaleRunning(void);
void FULVL_vidLvlIncCpeCaleRunning(void);
void FULVL_vidNoFaultMeasure(void);
void FULVL_vidRunningCounter(void);
void FULVL_vidTemporisation(void);


#endif /* FULVL_L_H */

/*-------------------------------- end of file -------------------------------*/
