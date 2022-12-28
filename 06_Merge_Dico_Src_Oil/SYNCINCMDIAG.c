/***************************************************************************
;**
;** FILE NAME      : SYNCINCMDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SYNCINCMDIAG.H"
#include "SYNCINCMDIAG_L.H"
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
const boolean  Acq_incam_chr_diag_ena_upcb0 = 0;
const uint8  Sync_cntFrntThd_C = 0;
const uint8  SYNCINCMDIAG_u8Inhib = 0;
const uint16  Sync_nEngInhMonCohInCm_C = 0;
const uint16  Sync_nEngInhMonCohInCm_Hys_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Sync_bAcvInjIgDrv;
boolean Sync_bDgoCoh_InCm;
boolean Sync_bInCmAcqVld;
boolean Sync_bMonRunCoh_InCm;
boolean SYNCINCMDIAG_bHysteresisOutput;
uint8 Sync_cntFrntIncm;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

