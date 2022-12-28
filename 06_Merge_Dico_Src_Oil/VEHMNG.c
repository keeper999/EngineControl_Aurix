/***************************************************************************
;**
;** FILE NAME      : VEHMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VEHMNG.H"
#include "VEHMNG_L.H"
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
const uint8  VEHMNG_u8Inhib = 0;
const uint8  Vitesse_vehicule_gain = 0;
const uint16  Eng_spdVeh_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Emetteur_vitesse_vehicule_state;
boolean Vehicule_roulant;
boolean VEHMNG_bInhClcnDstCoveredPrev;
uint32 Distance_parcourue_totale;
uint32 Distance_parcourue_totale_prev;
uint32 VEHMNG_u32VitesseVehFiltreeMem;
uint8 Acceleration_vehicule;
uint8 Vitesse_vehicule;
uint16 Distance_parcourue;
uint16 Distance_parcourue_hecto_prev;
uint16 Distance_parcourue_hectometre;
uint16 Distance_parcourue_prev;
uint16 Eng_spdVeh;
uint16 VEHMNG_u16DistanceParcourue;
uint16 Vitesse_vehicule_filtree;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

