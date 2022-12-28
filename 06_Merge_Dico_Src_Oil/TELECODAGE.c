/***************************************************************************
;**
;** FILE NAME      : TELECODAGE.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TELECODAGE.H"
#include "TELECODAGE_L.H"
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
const uint32  Tele_available_uc = 0;
const uint32  Tele_program_uc_init_C = 0;
const uint8  Srv_TeleIndice_C = 0;
const uint8  Tele_available_add_heat = 0;
const uint8  Tele_available_car = 0;
const uint8  Tele_available_fric = 0;
const uint8  Tele_available_gear_box = 0;
const uint8  Tele_available_press_clim = 0;
const uint8  Tele_program_add_heat_init_C = 0;
const uint8  Tele_program_car_init_C = 0;
const uint8  Tele_program_fric_init_C = 0;
const uint8  Tele_program_gear_box_init_C = 0;
const uint8  Tele_program_press_clim_init_C = 0;
const uint8  TELECODAGE_u8Inhib = 0;
const uint16  Srv_tiDelayTele_C = 0;
const uint16  Tele_available_alternator = 0;
const uint16  Tele_program_alternator_init_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Srv_stTeleEcuStatus;
boolean Srv_bDaVld;
boolean Srv_bDgoInv_VarCod;
boolean Srv_bMonRunInv_VarCod;
boolean Tele_program_add_heat_vld;
boolean Tele_program_alternator_vld;
boolean Tele_program_car_vld;
boolean Tele_program_fric_vld;
boolean Tele_program_gear_box_vld;
boolean Tele_program_press_clim_vld;
uint32 TELECODAGE_u32Info_UC;
uint8 Tele_program_add_heat_int;
uint8 Tele_program_car_int;
uint8 Tele_program_fric_int;
uint8 Tele_program_gear_box_int;
uint8 Tele_program_press_clim_int;
uint8 TELECODAGE_u8SrvStTeleEcuStaPrev;
uint16 AppliKey;
uint16 Srv_tiWaitDelayTele;
uint16 Tele_program_alternator_int;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

