/***************************************************************************
;**
;** FILE NAME      : ENGSTAB.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ENGSTAB.H"
#include "ENGSTAB_L.H"
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
const uint8  Engine_load_e_s_limit_c = 0;
const uint8  Engine_load_e_s_window_c = 0;
const uint8  Engine_stable_delay_c = 0;
const uint8  ENGSTAB_u8Inhib = 0;
const uint8  Gear_engaged_e_s_window_c = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Engine_conditions;
boolean Engine_load_not_stable;
boolean Engine_stabilised;
boolean Engine_stabilised_eng_running;
boolean ENGSTAB_bVehicleRunning;
boolean Gear_engaged_not_stable;
uint8 Engine_load_last;
uint8 Engine_load_t_d_c;
uint8 Engine_stable_t_d_c;
uint8 Gear_engaged_last;
uint8 Gear_engaged_t_d_c;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

