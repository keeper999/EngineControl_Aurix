/***************************************************************************
;**
;** FILE NAME      : FUPMPMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FUPMPMNG.H"
#include "FUPMPMNG_L.H"
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
const uint32  Fuel_pump_long_stop_delay = 0;
const uint8  Fuel_pump_after_reset_delay = 0;
const uint8  Fuel_pump_eng_speed_cmd = 0;
const uint8  Fuel_pump_engine_speed_map[FUEL_PUMP_ENGINE_SPEED_MAP_COLS] = {0};
const uint8  FUPMPMNG_u8Inhib = 0;
const uint16  Fuel_pump_after_stall_delay = 0;
const uint16  Fuel_pump_long_delay = 0;
const uint16  Fuel_pump_off_delay = 0;
const uint16  Fuel_pump_short_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 FuPmp_stCtl;
uint8 FuPmp_stInitCallMng;
uint8 FuPmp_stInitFuPmpPctl;
boolean Commande_pompe_ess;
boolean Fuel_pump_bEveKOn_Mng;
boolean Fuel_pump_bEveRxnIdDaRcdDml;
boolean Fuel_pump_init_delay_ok;
boolean Fuel_pump_pre_control_active;
boolean Fuel_pump_pre_control_ok;
boolean FuPmp_bafter_stall_ena;
boolean FuPmp_bPerdPctl_Ena;
uint8 Fuel_pump_counter;
uint8 Fuel_pump_engine_speed_thresh;
uint16 Fuel_pump_delay;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

