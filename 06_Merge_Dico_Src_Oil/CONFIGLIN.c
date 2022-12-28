/***************************************************************************
;**
;** FILE NAME      : CONFIGLIN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CONFIGLIN.H"
#include "CONFIGLIN_L.H"
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
const uint8  CONFIGLIN_u8DecAlt1Absent = 0;
const uint8  CONFIGLIN_u8DecAlt2Absent = 0;
const uint8  CONFIGLIN_u8DecAltAbsent = 0;
const uint8  CONFIGLIN_u8DecEcmMute = 0;
const uint8  CONFIGLIN_u8IncAlt1Absent = 0;
const uint8  CONFIGLIN_u8IncAlt2Absent = 0;
const uint8  CONFIGLIN_u8IncAltAbsent = 0;
const uint8  CONFIGLIN_u8IncEcmMute = 0;
const uint8  CONFIGLIN_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 CONFIGLIN_stAltStatus;
uint8 CONFIGLIN_stBusBlockedStatus;
boolean CONFIGLIN_bDgoAltAbsent;
boolean CONFIGLIN_bDgoLinBlocked;
boolean CONFIGLIN_bDiag_on_pred;
boolean CONFIGLIN_bMonRun;
uint8 CONFIGLIN_u8AltCnt_prev;
uint8 CONFIGLIN_u8AltEcuCnt_prev;
uint8 CONFIGLIN_u8Cnt_prev[CONFIGLIN_U8CNT_PREV_COLS];
uint8 CONFIGLIN_u8Compteur;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

