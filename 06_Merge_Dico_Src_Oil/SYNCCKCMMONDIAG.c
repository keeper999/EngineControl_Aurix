/***************************************************************************
;**
;** FILE NAME      : SYNCCKCMMONDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SYNCCKCMMONDIAG.H"
#include "SYNCCKCMMONDIAG_L.H"
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
const boolean  Acq_crk_no_sgnl_diag_ena_upcb0 = 0;
const boolean  Acq_excam_no_sgnl_diag_ena_upcb0 = 0;
const boolean  Acq_incam_no_sgnl_diag_ena_upcb0 = 0;
const uint8  Acq_excam_count_evnt_upcn0 = 0;
const uint8  Acq_incam_count_evnt_upcn0 = 0;
const uint8  Sync_CfmTimeStallEng = 0;
const uint8  SYNCCKCMMONDIAG_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Sync_bCmnCdnCkDiag;
boolean Sync_bCmnCdnExCmDiag;
boolean Sync_bCmnCdnInCmDiag;
boolean Sync_bDgoNoSigCk;
boolean Sync_bDgoNoSigExCm;
boolean Sync_bDgoNoSigInCm;
boolean Sync_bDgoSigLossCk;
boolean Sync_bDgoSigLossExCm;
boolean Sync_bDgoSigLossInCm;
boolean Sync_bEnaDiagNoSigCk;
boolean Sync_bEnaDiagNoSigExCam;
boolean Sync_bEnaDiagNoSigInCam;
boolean Sync_bMinTimeElpdExCam;
boolean Sync_bMinTimeElpdInCam;
boolean Sync_bMonRunNoSigCk;
boolean Sync_bMonRunNoSigExCm;
boolean Sync_bMonRunNoSigInCm;
boolean Sync_bMonRunSigLossCk;
boolean Sync_bMonRunSigLossExCm;
boolean Sync_bMonRunSigLossInCm;
boolean SYNCCKCMMONDIAG_bAcqCrkEngExPrev;
boolean SYNCCKCMMONDIAG_bAcqCrkEngInPrev;
boolean SYNCCKCMMONDIAG_bCrkExCamSynPrev;
boolean SYNCCKCMMONDIAG_bCrkExCamTimeout;
boolean SYNCCKCMMONDIAG_bCrkInCamSynPrev;
boolean SYNCCKCMMONDIAG_bCrkInCamTimeout;
uint8 SYNCCKCMMONDIAG_u8CrkExTimerCnt;
uint8 SYNCCKCMMONDIAG_u8CrkInTimerCnt;
uint8 SYNCCKCMMONDIAG_u8ExCmTimerCnt;
uint8 SYNCCKCMMONDIAG_u8InCmTimerCnt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

