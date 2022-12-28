/***************************************************************************
;**
;** FILE NAME      : VEHMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHMNG_H
#define VEHMNG_H

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

/* enum st55 */
#define VITESSE_CAN_EMETTEUR              1
#define VITESSE_CMM_EMETTEUR              2
/*extern uint8 Emetteur_vitesse_vehicule_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  Vitesse_vehicule_gain;
extern const uint16  Eng_spdVeh_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Emetteur_vitesse_vehicule_state;
extern boolean Vehicule_roulant;
extern uint8 Acceleration_vehicule;
extern uint8 Vitesse_vehicule;
extern uint16 Distance_parcourue;
extern uint16 Distance_parcourue_hecto_prev;
extern uint16 Distance_parcourue_hectometre;
extern uint16 Eng_spdVeh;
extern uint16 Vitesse_vehicule_filtree;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VehSpd_EveRst_VehMng(void);
void VehSpd_SdlFast_VehMng(void);
void VehSpd_SdlMid_VehMng(void);


#endif /* VEHMNG_H */

/*-------------------------------- end of file -------------------------------*/
