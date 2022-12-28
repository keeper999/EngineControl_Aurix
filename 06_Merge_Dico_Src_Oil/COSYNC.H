/***************************************************************************
;**
;** FILE NAME      : COSYNC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COSYNC_H
#define COSYNC_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const boolean  CoSync_bAcvDetEs_C;
extern const boolean  CoSync_bAcvDgoPosEs_C;
extern const boolean  CoSync_bAcvForc0Sync_C;
extern const boolean  CoSync_bAcvStuckEng_C;
extern const boolean  CoSync_bPresSigCmEx_C;
extern const boolean  CoSync_bPresSigCmIn_C;
extern const uint8  CoSync_agNearMissCgt_C;
extern const uint8  CoSync_agNearTDC_C;
extern const uint8  CoSync_nAcvDetEs_C;
extern const uint8  CoSync_nAcvDgoPosEs_C;
extern const uint8  CoSync_noSigCm2SyncBas_C;
extern const uint8  CoSync_tiCmfVldSigCk_C;
extern const uint8  CoSync_tiCmfVldSigCm_C;
extern const uint8  CoSync_tiDetEsCgt_C;
extern const uint8  CoSync_tiDetEsCm_C;
extern const uint8  CoSync_tiDetEsCmf_C;
extern const uint8  CoSync_tiDetEsMissCgt_C;
extern const uint8  CoSync_tiDetEsTDC_C;
extern const uint8  CoSync_tiMaxDetEdgeCk_C;
extern const uint8  CoSync_tiMaxDetEdgeCkIni_C;
extern const uint8  CoSync_tiMaxDetEdgeCm_C;
extern const uint8  CoSync_tiMaxDetEdgeCmIni_C;
extern const uint8  CoSync_tiRbm_C;
extern const uint8  CoSync_u8Inhib;
extern const uint16  CoSync_nAcvStuckEng_C;
extern const uint16  CoSync_tiForcNNull_C;
extern const uint16  PredEs_agMissCgt_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoSync_bDemMissSync;
extern boolean CoSync_bDetEs;
extern boolean CoSync_bForcEngNotSync;
extern uint8 CoSync_agUncrtEs;
extern uint8 CoSync_ctTDC;
extern uint16 CoSync_agEs;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COSYNC_vidEntry_10ms(void);
void COSYNC_vidEntryInit(void);


#endif /* COSYNC_H */

/*-------------------------------- end of file -------------------------------*/
