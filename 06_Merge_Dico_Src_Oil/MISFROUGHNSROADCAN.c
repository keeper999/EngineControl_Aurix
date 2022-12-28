/***************************************************************************
;**
;** FILE NAME      : MISFROUGHNSROADCAN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFROUGHNSROADCAN.H"
#include "MISFROUGHNSROADCAN_L.H"
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
const uint8  MISFROUGHNSROADCAN_u8Inhib = 0;
const uint8  Tra_noGearMan_bkpt_map[TRA_NOGEARMAN_BKPT_MAP_COLS] = {0};
const uint8  Vitesse_vehicule_bkpt_map[VITESSE_VEHICULE_BKPT_MAP_COLS] = {0};
const uint16  Misf_aRoughnRoadDetThd_M[MISF_AROUGHNROADDETTHD_M_LNS][MISF_AROUGHNROADDETTHD_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Misf_bAcvRoughnsRoadMod;
boolean Misf_bDgoLostMisfRoughnsRoad;
boolean Misf_bMonRunLostMisfRoughnsRoad;
uint16 Acceleration_vehicule_ard_mux;
uint16 Acceleration_vehicule_arg_mux;
uint16 Acceleration_vehicule_avd_mux;
uint16 Acceleration_vehicule_avg_mux;
uint16 Misf_aRoughnRoadDetThd;
uint16 MISFROUGHNSROADCAN_u16ArdSpPrev;
uint16 MISFROUGHNSROADCAN_u16ArgSpPrev;
uint16 MISFROUGHNSROADCAN_u16AvdSpPrev;
uint16 MISFROUGHNSROADCAN_u16AvgSpPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

