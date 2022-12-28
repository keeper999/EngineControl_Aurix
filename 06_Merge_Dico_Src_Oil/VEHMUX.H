/***************************************************************************
;**
;** FILE NAME      : VEHMUX.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHMUX_H
#define VEHMUX_H

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Km_vehicle_first_552_received;
extern boolean Km_vehicle_first_7F2_received;
extern uint8 Acceleration_veh_rx_via_can;
extern uint16 Distance_covered_computed;
extern uint16 Distance_parcourue_mux;
extern uint16 Vitesse_vehicule_rx_via_can;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VehSpd_EveRst_VehMux(void);
void VehSpd_EveRxn552_VehMux(void);
void VehSpd_EveRxn7F2_VehMux(void);
void VehSpd_SdlMid_VehMux(void);


#endif /* VEHMUX_H */

/*-------------------------------- end of file -------------------------------*/
