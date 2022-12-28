/***************************************************************************
;**
;** FILE NAME      : TELECODAGE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TELECODAGE_H
#define TELECODAGE_H

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

/* enum st57 */
#define SRV_TELEECU_IDLE                  0
#define SRV_TELEECU_NEEDACCESS            1
#define SRV_TELEECU_SEED                  2
#define SRV_TELEECU_WAIT                  4
#define SRV_TELEECU_WRITE                 8
#define SRV_TELEECU_ANTISCANNING          16
#define SRV_TELEECU_DATANOK               32
/*extern uint8 Srv_stTeleEcuStatus;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint32  Tele_available_uc;
extern const uint32  Tele_program_uc_init_C;
extern const uint8  Srv_TeleIndice_C;
extern const uint8  Tele_available_add_heat;
extern const uint8  Tele_available_car;
extern const uint8  Tele_available_fric;
extern const uint8  Tele_available_gear_box;
extern const uint8  Tele_available_press_clim;
extern const uint8  Tele_program_add_heat_init_C;
extern const uint8  Tele_program_car_init_C;
extern const uint8  Tele_program_fric_init_C;
extern const uint8  Tele_program_gear_box_init_C;
extern const uint8  Tele_program_press_clim_init_C;
extern const uint16  Srv_tiDelayTele_C;
extern const uint16  Tele_available_alternator;
extern const uint16  Tele_program_alternator_init_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Srv_stTeleEcuStatus;
extern uint16 AppliKey;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Srv_EveErrTeleWr_TeleSrv(void);
void Srv_EveRst_TeleSrv(void);
void Srv_EveSa_TeleSrv(void);
void Srv_EveTele_TeleSrv(void);
void Srv_SdlFast_TeleSrv(void);


#endif /* TELECODAGE_H */

/*-------------------------------- end of file -------------------------------*/
