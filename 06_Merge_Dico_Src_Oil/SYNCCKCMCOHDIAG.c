/***************************************************************************
;**
;** FILE NAME      : SYNCCKCMCOHDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SYNCCKCMCOHDIAG.H"
#include "SYNCCKCMCOHDIAG_L.H"
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
const uint8  SYNCCKCMCOHDIAG_u8Inhib = 0;
const uint16  Sync_nEngDifMaxExCmCk_C = 0;
const uint16  Sync_nEngDifMaxInCmCk_C = 0;
const uint16  Sync_nEngDifMaxInCmExCm_C = 0;
const uint16  Sync_nEngInhMonEngSpd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Sync_bDgoEngSpdCohCk;
boolean Sync_bDgoEngSpdCohExCm;
boolean Sync_bDgoEngSpdCohInCm;
boolean Sync_bEngSpdDIfExCmCk;
boolean Sync_bEngSpdDIfInCmCk;
boolean Sync_bEngSpdDIfInCmExCm;
boolean Sync_bMonRunEngSpdCohCk;
boolean Sync_bMonRunEngSpdCohExCm;
boolean Sync_bMonRunEngSpdCohInCm;
boolean SYNCCKCMCOHDIAG_bEngineSyncPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

