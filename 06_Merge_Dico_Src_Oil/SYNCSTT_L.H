/***************************************************************************
;**
;** FILE NAME      : SYNCSTT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCSTT_L_H
#define SYNCSTT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SYNCSTT_u8MAX_TAB_SIZE            5

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

extern const uint8  SYNCSTT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sync_bCalcOk;
extern boolean Sync_bDetLTo;
extern boolean Sync_bDetLTooth;
extern boolean Sync_bDgoDistSig;
extern boolean Sync_bMonRunDistSig;
extern boolean SYNCSTT_bAcqStPosAngMoteur_Prev;
extern boolean SYNCSTT_bEngSyncAccu_Prev;
extern boolean SYNCSTT_bEngSyncNotAccu_Prev;
extern uint8 Sync_agEngRstrtExCmEdge;
extern uint8 Sync_agEngRstrtInCmEdge;
extern uint8 Sync_agEngStopToSync;
extern uint8 Sync_agEngStrtExCmEdge;
extern uint8 Sync_agEngStrtInCmEdge;
extern uint8 Sync_agTDC;
extern uint8 Sync_ctCmExEdgeRstrtOk;
extern uint8 Sync_ctCmExEdgeStrtOk;
extern uint8 Sync_ctCmInEdgeRstrtOk;
extern uint8 Sync_ctCmInEdgeStrtOk;
extern uint8 SYNCSTT_u8AcqStPosAngMoteur_Prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SYNCSTT_vidBackUpAcv(void);
void SYNCSTT_vidBackUpCk(void);
void SYNCSTT_vidBackUpCm(void);
void SYNCSTT_vidChangeOfMind(void);
void SYNCSTT_vidCkOff(void);
void SYNCSTT_vidCkOn(void);
void SYNCSTT_vidCnt(void);
void SYNCSTT_vidctEdgeCmExRstrt(void);
void SYNCSTT_vidctEdgeCmExStrt(void);
void SYNCSTT_vidctEdgeCmInRstrt(void);
void SYNCSTT_vidctEdgeCmInStrt(void);
void SYNCSTT_vidDetLTo(void);
void SYNCSTT_vidDiag(void);
void SYNCSTT_vidDiagAuth(void);
void SYNCSTT_vidDiagResult(void);
void SYNCSTT_vidEngStopPosn(void);
void SYNCSTT_vidEngStopPosnAfter(void);
void SYNCSTT_vidEveProd(void);
void SYNCSTT_vidForcSyncOff(void);
void SYNCSTT_vidInit(void);
void SYNCSTT_vidIniTDCCnt(void);
void SYNCSTT_vidInitOutput(void);
void SYNCSTT_vidOS1(void);
void SYNCSTT_vidOS2(void);
void SYNCSTT_vidReadToothInfo(void);
void SYNCSTT_vidRstSyncVar(void);
void SYNCSTT_vidRstTeethCnt(void);
void SYNCSTT_vidSync_SdlMid_SyncSTT(void);
void SYNCSTT_vidSyncCalcRstrt(void);
void SYNCSTT_vidSyncCalcStrt(void);
void SYNCSTT_vidTDCCnt(void);
void SYNCSTT_vidTeethCnt(void);


#endif /* SYNCSTT_L_H */

/*-------------------------------- end of file -------------------------------*/
