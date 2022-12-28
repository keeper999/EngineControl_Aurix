/***************************************************************************
;**
;** FILE NAME      : INJCRK_ANTIFLOOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INJCRK_ANTIFLOOD.H"
#include "INJCRK_ANTIFLOOD_L.H"
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
const uint8  Anti_flood_pedale_hysteresis = 0;
const uint8  Anti_flood_pedale_limit = 0;
const uint8  Anti_flood_regime_reinj = 0;
const uint8  INJCRK_ANTIFLOOD_u8Inhib = 0;
const uint16  Anti_flood_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Disable_inj_for_anti_flood;
boolean Function_anti_flood;
uint16 Anti_flood_delay_counter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

