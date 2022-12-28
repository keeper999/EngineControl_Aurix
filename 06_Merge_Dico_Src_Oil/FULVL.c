/***************************************************************************
;**
;** FILE NAME      : FULVL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FULVL.H"
#include "FULVL_L.H"
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
const boolean  Flev_etat_haut_en_reserve = 0;
const boolean  Flev_fuel_inc_run_manu_inh = 0;
const boolean  FuLvl_bAcvDiagLoFuLvl_C = 0;
const uint8  Flev_fuel_level_filtered_gain = 0;
const uint8  Flev_fuel_level_inc_run_thresh = 0;
const uint8  Flev_fuel_level_inc_thresh = 0;
const uint8  Fuel_level_state_max = 0;
const uint8  Fuel_level_state_min = 0;
const uint8  FULVL_u8Inhib = 0;
const uint16  Flev_fuel_level_delay = 0;
const uint16  Flev_fuel_level_last_delay = 0;
const uint16  Flev_low_fuel_level_sw_tempo = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Flev_fuel_level_inc_next;
boolean Flev_fuel_level_inc_running;
boolean Flev_fuel_level_increase;
boolean Flev_last_stall_or_key_off;
boolean Flev_low_fuel_level_can;
boolean Flev_low_fuel_level_sw_inj;
boolean Flev_low_fuel_level_sw_lfbk;
boolean Flev_low_fuel_level_sw_mf;
boolean Fu_bDgoOc_FuGauge;
boolean Fu_bDgoORng_FuGauge;
boolean Fu_bDgoORng_FuGaugeLvl;
boolean Fu_bDgoScg_FuGauge;
boolean Fu_bMonRunOc_FuGauge;
boolean Fu_bMonRunORng_FuGauge;
boolean Fu_bMonRunORng_FuGaugeLvl;
boolean Fu_bMonRunScg_FuGauge;
boolean FuLvl_bDgoLoFuLvl;
boolean FULVL_bFlevFuelLevelCountPrev;
boolean FULVL_bFlevFuelLevelThrshPrev;
boolean FULVL_bFlevLowFuelInjInit;
boolean FULVL_bFlevLowFuelInjInitPrev;
boolean FULVL_bFlevLowFuelLfbkInit;
boolean FULVL_bFlevLowFuelLfbkInitPrev;
boolean FULVL_bMfCatDamDetUavb0Prev;
boolean FuLvl_bMonRunLoFuLvl;
uint32 Conso_carbu_totale_ref;
uint32 FULVL_u32FiltredFlevFuelLevelMux;
uint8 Flev_fuel_level;
uint8 Flev_fuel_level_count;
uint8 Flev_fuel_level_delta;
uint8 Flev_fuel_level_filtered_ref;
uint8 Flev_fuel_level_last;
uint8 FULVL_u8FlevFuelLevelCountPrev;
uint16 Flev_fuel_level_filtered;
uint16 Flev_fuel_level_last_count;
uint16 Flev_fuel_level_ref;
uint16 Flev_low_level_sw_inj_counter;
uint16 Flev_low_level_sw_lfbk_counter;
uint16 Flev_low_level_sw_mf_counter;
uint16 FULVL_u16FlevFuelLvlLastCntPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

