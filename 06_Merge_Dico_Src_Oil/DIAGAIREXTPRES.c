/***************************************************************************
;**
;** FILE NAME      : DIAGAIREXTPRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DIAGAIREXTPRES.H"
#include "DIAGAIREXTPRES_L.H"
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
const uint8  AirPres_pAirExtThdMin_C = 0;
const uint8  DIAGAIREXTPRES_u8Inhib = 0;
const uint16  AirPres_pAirExtThdGrdMax_C = 0;
const uint16  AirPres_pAirExtThdGrdOldMax_C = 0;
const uint16  AirPres_pAirExtThdMax_C = 0;
const uint16  AirPres_tiDlyGrd_pAirExt_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AirPres_bDgoGrd_pAirExt;
boolean AirPres_bDgoGrd_pAirExtOld;
boolean AirPres_bDgoMax_pAirExt;
boolean AirPres_bDgoMin_pAirExt;
boolean AirPres_bEnaClcGrdExtAirPres;
boolean AirPres_bMonRunGrd_pAirExt;
boolean AirPres_bMonRunGrd_pAirExtOld;
boolean AirPres_bMonRunMax_pAirExt;
boolean AirPres_bMonRunMin_pAirExt;
boolean AirPres_bPresAirExtKOnMem;
boolean DIAGAIREXTPRES_bExtKOnMemPrev;
boolean DIAGAIREXTPRES_bTimeout;
uint16 AirPres_ctTiDlyGrd_pAirExt;
uint16 AirPres_pAirExtGrd;
uint16 AirPres_pAirExtGrdOld;
uint16 AirPres_pAirExtMemDly;
uint16 AirPres_pAirExtRefOld;
uint16 AirPres_pAirExtStrtPresSens;
uint16 DIAGAIREXTPRES_u16OutPutSwitch2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

