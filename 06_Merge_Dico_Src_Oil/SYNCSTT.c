/***************************************************************************
;**
;** FILE NAME      : SYNCSTT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SYNCSTT.H"
#include "SYNCSTT_L.H"
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
const boolean  Sync_bDgoCkSig_C = 0;
const boolean  Sync_bDgoCmSig_C = 0;
const uint8  Sync_agWinAgCmTh_C = 0;
const uint8  Sync_agWinAgCmThLrn_C = 0;
const uint8  Sync_nEngDiagLoThd_C = 0;
const uint8  Sync_noEdgeCmAccuRstrt_C = 0;
const uint8  Sync_noEdgeCmAccuStrt_C = 0;
const uint8  Sync_noEdgeCmNotAccuRstrt_C = 0;
const uint8  Sync_noEdgeCmNotAccuStrt_C = 0;
const uint8  Sync_noToDft_C = 0;
const uint8  Sync_noToGapTar_C = 0;
const uint8  Sync_noToTar_C = 0;
const uint8  Sync_nSyncRstrt_C = 0;
const uint8  Sync_nSyncStrt_C = 0;
const uint8  SYNCSTT_u8Inhib = 0;
const uint16  Sync_prm_agRefExCmEdge_C[SYNC_PRM_AGREFEXCMEDGE_C_LNS] = {0};
const uint16  Sync_prm_agRefInCmEdge_C[SYNC_PRM_AGREFINCMEDGE_C_LNS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDetCgtMiss;
boolean Sync_bCalcOk;
boolean Sync_bDetEs;
boolean Sync_bDetLTo;
boolean Sync_bDetLTooth;
boolean Sync_bDgoCmSig;
boolean Sync_bDgoDistSig;
boolean Sync_bEngPosOk;
boolean Sync_bEngSyncNotAccu;
boolean Sync_bMonRunDistSig;
boolean Sync_bVldAgEs;
boolean SYNCSTT_bAcqStPosAngMoteur_Prev;
boolean SYNCSTT_bEngSyncAccu_Prev;
boolean SYNCSTT_bEngSyncNotAccu_Prev;
uint32 BufNEs_tiCgtLst;
uint32 Ext_tiCgt;
uint8 Ext_ctEdgeCk;
uint8 Sync_agEngRstrtExCmEdge;
uint8 Sync_agEngRstrtInCmEdge;
uint8 Sync_agEngStopToSync;
uint8 Sync_agEngStrtExCmEdge;
uint8 Sync_agEngStrtInCmEdge;
uint8 Sync_agEs;
uint8 Sync_agEsAfter;
uint8 Sync_agTDC;
uint8 Sync_ctCmExEdgeRstrtOk;
uint8 Sync_ctCmExEdgeStrtOk;
uint8 Sync_ctCmInEdgeRstrtOk;
uint8 Sync_ctCmInEdgeStrtOk;
uint8 Sync_ctTDC;
uint8 Sync_ctTeeth;
uint8 SYNCSTT_u8AcqStPosAngMoteur_Prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

