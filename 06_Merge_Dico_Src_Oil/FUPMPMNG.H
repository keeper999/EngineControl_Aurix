/***************************************************************************
;**
;** FILE NAME      : FUPMPMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FUPMPMNG_H
#define FUPMPMNG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define FUEL_PUMP_ENGINE_SPEED_MAP_COLS        ( 16 )

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

extern const uint32  Fuel_pump_long_stop_delay;
extern const uint8  Fuel_pump_after_reset_delay;
extern const uint8  Fuel_pump_eng_speed_cmd;
extern const uint8  Fuel_pump_engine_speed_map[FUEL_PUMP_ENGINE_SPEED_MAP_COLS];
extern const uint16  Fuel_pump_after_stall_delay;
extern const uint16  Fuel_pump_long_delay;
extern const uint16  Fuel_pump_off_delay;
extern const uint16  Fuel_pump_short_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Commande_pompe_ess;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FuPmp_EveKOn_Mng(void);
void FuPmp_EveRst_Mng(void);
void FuPmp_EveRTSt_Mng(void);
void FuPmp_EveRxnIdDaRcdDml(void);
void FuPmp_EveStTR_Mng(void);
void FuPmp_SdlFast_Mng(void);
void FuPmp_SdlMid_Mng(void);


#endif /* FUPMPMNG_H */

/*-------------------------------- end of file -------------------------------*/
