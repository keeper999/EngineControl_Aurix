/***************************************************************************
;**
;** FILE NAME      : SYNCSTT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCSTT_H
#define SYNCSTT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SYNC_PRM_AGREFEXCMEDGE_C_LNS          ( 6 )
#define SYNC_PRM_AGREFINCMEDGE_C_LNS          ( 6 )

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

extern const boolean  Sync_bDgoCkSig_C;
extern const boolean  Sync_bDgoCmSig_C;
extern const uint8  Sync_agWinAgCmTh_C;
extern const uint8  Sync_agWinAgCmThLrn_C;
extern const uint8  Sync_nEngDiagLoThd_C;
extern const uint8  Sync_noEdgeCmAccuRstrt_C;
extern const uint8  Sync_noEdgeCmAccuStrt_C;
extern const uint8  Sync_noEdgeCmNotAccuRstrt_C;
extern const uint8  Sync_noEdgeCmNotAccuStrt_C;
extern const uint8  Sync_noToDft_C;
extern const uint8  Sync_noToGapTar_C;
extern const uint8  Sync_noToTar_C;
extern const uint8  Sync_nSyncRstrt_C;
extern const uint8  Sync_nSyncStrt_C;
extern const uint16  Sync_prm_agRefExCmEdge_C[SYNC_PRM_AGREFEXCMEDGE_C_LNS];
extern const uint16  Sync_prm_agRefInCmEdge_C[SYNC_PRM_AGREFINCMEDGE_C_LNS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDetCgtMiss;
extern boolean Sync_bDetEs;
extern boolean Sync_bDgoCmSig;
extern boolean Sync_bEngPosOk;
extern boolean Sync_bEngSyncNotAccu;
extern boolean Sync_bVldAgEs;
extern uint32 BufNEs_tiCgtLst;
extern uint32 Ext_tiCgt;
extern uint8 Ext_ctEdgeCk;
extern uint8 Sync_agEs;
extern uint8 Sync_agEsAfter;
extern uint8 Sync_ctTDC;
extern uint8 Sync_ctTeeth;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Sync_EveCkLTo_SyncSTT(void);
void Sync_EveCkLTo1_SyncSTT(void);
void Sync_EveCkOff_SyncSTT(void);
void Sync_EveCkOn_SyncSTT(void);
void Sync_EveCkSnOf_SyncSTT(void);
void Sync_EveCkTo_SyncSTT(void);
void Sync_EveExCamEdge_SyncSTT(void);
void Sync_EveInCamEdge_SyncSTT(void);
void Sync_EveNInvOff_SyncSTT(void);
void Sync_EveRst_SyncSTT(void);
void Sync_EveTDC_SyncSTT(void);
void Sync_SdlFast_SyncSTT(void);
void Sync_SdlMid_SyncSTT(void);


#endif /* SYNCSTT_H */

/*-------------------------------- end of file -------------------------------*/
