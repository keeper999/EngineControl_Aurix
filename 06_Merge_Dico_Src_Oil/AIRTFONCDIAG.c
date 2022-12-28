/***************************************************************************
;**
;** FILE NAME      : AIRTFONCDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "AIRTFONCDIAG.H"
#include "AIRTFONCDIAG_L.H"
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
const uint32  AirT_tiDlyTDsThrStallCoh_C = 0;
const uint8  AirT_spdVehThdMaxTNegOfs_C = 0;
const uint8  AirT_spdVehThdMinTPosOfs_C = 0;
const uint8  AirT_tAirExtMes_A[AIRT_TAIREXTMES_A_COLS] = {0};
const uint8  AirT_tDsThr_pAirExtMes_T[AIRT_TDSTHR_PAIREXTMES_T_COLS] = {0};
const uint8  AirT_tDsThrStallCoh_C = 0;
const uint8  AIRTFONCDIAG_u8Inhib = 0;
const sint16  AirT_tCoThdMaxTNegOfs_C = 0;
const sint16  AirT_tDsThrThdMaxPosOfs_C = 0;
const sint16  AirT_tDsThrThdORngMax_C = 0;
const sint16  AirT_tDsThrThdORngMin_C = 0;
const uint16  AirT_mfAirThdMinTPosOfs_C = 0;
const uint16  AirT_tiDlyEngrunTNegOfs_C = 0;
const uint16  AirT_tiDlyIdlCtlTNegOfs_C = 0;
const uint16  AirT_tiDlymaxTDsThrStallCoh_C = 0;
const uint16  AirT_tiDlymfAirCorPosOfs_C = 0;
const uint16  AirT_tiDlyTPosOfs_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AirT_bDgoNegOfs_tAirMes;
boolean AirT_bDgoORng_tAirMes;
boolean AirT_bDgoPosOfs_tAirMes;
boolean AirT_bDgoStallCoh_tAirMes;
boolean AirT_bMonRunNegOfs_tAirMes;
boolean AirT_bMonRunORng_tAirMes;
boolean AirT_bMonRunPosOfs_tAirMes;
boolean AirT_bMonRunStallCoh_tAirMes;
boolean AirT_bTmfAirCorPosOfs;
boolean AIRTFONCDIAG_bTimerInit_prev;
uint16 AirT_tiEngrunTNegOfs;
uint16 AirT_tiIdlCtlTNegOfs;
uint16 AirT_timfAirCorPosOfs;
uint16 AirT_tiTPosOfs;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

