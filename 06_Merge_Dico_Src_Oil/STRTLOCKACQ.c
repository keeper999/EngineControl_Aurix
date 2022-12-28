/***************************************************************************
;**
;** FILE NAME      : STRTLOCKACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "STRTLOCKACQ.H"
#include "STRTLOCKACQ_L.H"
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
const boolean  Inv_bStrtLock_C = 0;
const uint8  StrtLock_ThdHi_C = 0;
const uint8  StrtLock_ThdLo_C = 0;
const uint8  STRTLOCKACQ_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoCoh_StrtLock;
boolean Ext_bMonRunCoh_StrtLock;
boolean Ext_bStrtAuth;
boolean Ext_bStrtLockAcqRaw;
boolean STRTLOCKACQ_bDebouncingFilSig;
uint8 STRTLOCKACQ_u8DebouncingFiltCnt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

