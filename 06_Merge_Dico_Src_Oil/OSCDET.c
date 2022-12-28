/***************************************************************************
;**
;** FILE NAME      : OSCDET.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "OSCDET.H"
#include "OSCDET_L.H"
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
const boolean  EngSt_bOscDetByp_C = 0;
const uint8  EngSt_nOscDetMod_C = 0;
const uint8  OSCDET_u8Inhib = 0;
const uint16  EngSt_nIdlSpdDeltaMaxThd_C = 0;
const uint16  EngSt_rAirLdDeltaMaxThd_C = 0;
const uint16  EngSt_tiDlyOscDet_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean EngSt_bAcvOscDetStab;
boolean EngSt_bEnaOscDet;
boolean EngSt_bOscDetAirLdCor;
boolean EngSt_bOscDetIdlSpd;
boolean OSCDET_bTimerInit;
uint16 EngSt_nIdlSpdOscMax;
uint16 EngSt_nIdlSpdOscMin;
uint16 EngSt_rAirLdOscMax;
uint16 EngSt_rAirLdOscMin;
uint16 EngSt_tiDlyOscDet;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

