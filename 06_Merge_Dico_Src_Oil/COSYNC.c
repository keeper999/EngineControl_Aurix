/***************************************************************************
;**
;** FILE NAME      : COSYNC.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "COSYNC.H"
#include "COSYNC_L.H"
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
const boolean  CoSync_bAcvDetEs_C = 0;
const boolean  CoSync_bAcvDgoPosEs_C = 0;
const boolean  CoSync_bAcvForc0Sync_C = 0;
const boolean  CoSync_bAcvStuckEng_C = 0;
const boolean  CoSync_bPresSigCmEx_C = 0;
const boolean  CoSync_bPresSigCmIn_C = 0;
const uint8  CoSync_agNearMissCgt_C = 0;
const uint8  CoSync_agNearTDC_C = 0;
const uint8  CoSync_nAcvDetEs_C = 0;
const uint8  CoSync_nAcvDgoPosEs_C = 0;
const uint8  CoSync_noSigCm2SyncBas_C = 0;
const uint8  CoSync_tiCmfVldSigCk_C = 0;
const uint8  CoSync_tiCmfVldSigCm_C = 0;
const uint8  CoSync_tiDetEsCgt_C = 0;
const uint8  CoSync_tiDetEsCm_C = 0;
const uint8  CoSync_tiDetEsCmf_C = 0;
const uint8  CoSync_tiDetEsMissCgt_C = 0;
const uint8  CoSync_tiDetEsTDC_C = 0;
const uint8  CoSync_tiMaxDetEdgeCk_C = 0;
const uint8  CoSync_tiMaxDetEdgeCkIni_C = 0;
const uint8  CoSync_tiMaxDetEdgeCm_C = 0;
const uint8  CoSync_tiMaxDetEdgeCmIni_C = 0;
const uint8  CoSync_tiRbm_C = 0;
const uint8  CoSync_u8Inhib = 0;
const uint16  CoSync_nAcvStuckEng_C = 0;
const uint16  CoSync_tiForcNNull_C = 0;
const uint16  PredEs_agMissCgt_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CoSync_bAcvCalcDetEs;
boolean CoSync_bAcvCalcDgoPosEs;
boolean CoSync_bAcvCalcStuckEng;
boolean CoSync_bAcvDetEsIni;
boolean CoSync_bAcvDgoPosEsIni;
boolean CoSync_bAcvElSys;
boolean CoSync_bAcvStuckEngIni;
boolean CoSync_bCfmVldSigCk;
boolean COSYNC_bCfmVldSigCkCntInput;
boolean CoSync_bCfmVldSigCm;
boolean COSYNC_bCfmVldSigCmCntInput;
boolean CoSync_bDemMissSync;
boolean CoSync_bDemMissSyncRaw;
boolean CoSync_bDetCkAcvElSys;
boolean CoSync_bDetCmExAcvElSys;
boolean COSYNC_bDetCmExElSys;
boolean CoSync_bDetCmInAcvElSys;
boolean COSYNC_bDetCmInElSys;
boolean CoSync_bDetErrSigCk;
boolean CoSync_bDetErrSigCm;
boolean CoSync_bDetEs;
boolean CoSync_bDetEsCmf;
boolean CoSync_bDetEsCmfRaw;
boolean COSYNC_bDetEsCmfRawCntInput;
boolean CoSync_bDetEsRaw;
boolean CoSync_bDetNNullBas;
boolean COSYNC_bDetNNullBasCntInput;
boolean CoSync_bDetNNullCmf;
boolean CoSync_bDetNNullDgoCk;
boolean COSYNC_bDetNNullDgoCkCntInput;
boolean CoSync_bDetNNullRaw;
boolean CoSync_bDifCntEdgeCk;
boolean CoSync_bDifCntEdgeCmEx;
boolean CoSync_bDifCntEdgeCmIn;
boolean CoSync_bEngSyncAccu_MP;
boolean CoSync_bForcEngNotSync;
boolean CoSync_bForcEngNotSyncRaw;
boolean COSYNC_bMissSigAACExCntInput;
boolean COSYNC_bMissSigAACInCntInput;
boolean CoSync_bMissSigCk;
boolean COSYNC_bMissSigCkCntInput;
boolean CoSync_bMissSigCmEx;
boolean CoSync_bMissSigCmIn;
boolean CoSync_bSelTiDetNulBas_MP;
boolean CoSync_bStrtAcvElSys;
boolean CoSync_bStuckEngStaAcvRaw;
uint8 CoSync_agEng_MP;
uint8 CoSync_agUncrtEs;
uint8 CoSync_ctEdgeCk_MP;
uint8 CoSync_ctEdgeCmEx_MP;
uint8 CoSync_ctEdgeCmIn_MP;
uint8 CoSync_ctTDC;
uint8 CoSync_ctTDCRaw;
uint8 CoSync_stCoSync;
uint8 COSYNC_u8CoSyncStCoSyncPrev;
uint8 COSYNC_u8ctEdgeCmInEx;
uint8 COSYNC_u8ExtCtEdgeCkPrev;
uint8 COSYNC_u8SyncCtTDCPrev;
uint16 CoSync_agEs;
uint16 CoSync_ctCfmVldSigCk_MP;
uint16 CoSync_ctCfmVldSigCm_MP;
uint16 CoSync_ctDetNNullBas_MP;
uint16 CoSync_ctDetNNullDgoCk_MP;
uint16 CoSync_ctMissSigCk_MP;
uint16 CoSync_ctMissSigCmEx_MP;
uint16 CoSync_ctMissSigCmIn_MP;
uint16 CoSync_tiDetNNullBas_MP;
uint16 COSYNC_u16DetEsCmfRawCntOutput;
uint16 COSYNC_u16DetEsCmfRawThd;
uint16 COSYNC_u16DetEsRawCntOutput;
uint16 COSYNC_u16DetEsRawThd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

