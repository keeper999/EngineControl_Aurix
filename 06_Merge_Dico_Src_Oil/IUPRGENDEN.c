/***************************************************************************
;**
;** FILE NAME      : IUPRGENDEN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "IUPRGENDEN.H"
#include "IUPRGENDEN_L.H"
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
const boolean  IUPR_bRstPrm_C = 0;
const uint8  Iupr_ambient_temp_thresh = 0;
const uint8  IUPRGENDEN_u8Inhib = 0;
const uint16  GOBD_nObdStrtThd_C = 0;
const uint16  Iupr_gen_denom_cumul_delay = 0;
const uint16  Iupr_gen_denom_idle_delay = 0;
const uint16  Iupr_gen_denom_over_40kph_delay = 0;
const uint16  Iupr_pressure_thresh = 0;
const uint16  IUPR_tiObdStrtThd_C = 0;
const uint16  Iupr_vitesse_veh_idle_thresh = 0;
const uint16  Iupr_vitesse_vehicule_thresh = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IUPR_bExtCond;
boolean IUPR_bIdle;
boolean IUPR_bObdStrt;
boolean IUPR_bRstPrm_prev;
boolean IUPR_bSinceEngStrt;
boolean IUPR_bVehIdle;
boolean IUPR_bVehSpdOver40;
boolean Iupr_gen_denom_ok_prev;
boolean Iupr_obd_Strt_ok_prev;
uint16 IUPR_tiObdStrt;
uint16 IUPR_tiSinceEngStrt;
uint16 IUPR_tiVehIdle;
uint16 IUPR_tiVehSpdOver40;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

