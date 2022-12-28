/***************************************************************************
;**
;** FILE NAME      : COSYNC_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COSYNC_L_H
#define COSYNC_L_H

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoSync_bAcvCalcDetEs;
extern boolean CoSync_bAcvCalcDgoPosEs;
extern boolean CoSync_bAcvCalcStuckEng;
extern boolean CoSync_bAcvDetEsIni;
extern boolean CoSync_bAcvDgoPosEsIni;
extern boolean CoSync_bAcvElSys;
extern boolean CoSync_bAcvStuckEngIni;
extern boolean CoSync_bCfmVldSigCk;
extern boolean COSYNC_bCfmVldSigCkCntInput;
extern boolean CoSync_bCfmVldSigCm;
extern boolean COSYNC_bCfmVldSigCmCntInput;
extern boolean CoSync_bDemMissSyncRaw;
extern boolean CoSync_bDetCkAcvElSys;
extern boolean CoSync_bDetCmExAcvElSys;
extern boolean COSYNC_bDetCmExElSys;
extern boolean CoSync_bDetCmInAcvElSys;
extern boolean COSYNC_bDetCmInElSys;
extern boolean CoSync_bDetErrSigCk;
extern boolean CoSync_bDetErrSigCm;
extern boolean CoSync_bDetEsCmf;
extern boolean CoSync_bDetEsCmfRaw;
extern boolean COSYNC_bDetEsCmfRawCntInput;
extern boolean CoSync_bDetEsRaw;
extern boolean CoSync_bDetNNullBas;
extern boolean COSYNC_bDetNNullBasCntInput;
extern boolean CoSync_bDetNNullCmf;
extern boolean CoSync_bDetNNullDgoCk;
extern boolean COSYNC_bDetNNullDgoCkCntInput;
extern boolean CoSync_bDetNNullRaw;
extern boolean CoSync_bDifCntEdgeCk;
extern boolean CoSync_bDifCntEdgeCmEx;
extern boolean CoSync_bDifCntEdgeCmIn;
extern boolean CoSync_bEngSyncAccu_MP;
extern boolean CoSync_bForcEngNotSyncRaw;
extern boolean COSYNC_bMissSigAACExCntInput;
extern boolean COSYNC_bMissSigAACInCntInput;
extern boolean CoSync_bMissSigCk;
extern boolean COSYNC_bMissSigCkCntInput;
extern boolean CoSync_bMissSigCmEx;
extern boolean CoSync_bMissSigCmIn;
extern boolean CoSync_bSelTiDetNulBas_MP;
extern boolean CoSync_bStrtAcvElSys;
extern boolean CoSync_bStuckEngStaAcvRaw;
extern uint8 CoSync_agEng_MP;
extern uint8 CoSync_ctEdgeCk_MP;
extern uint8 CoSync_ctEdgeCmEx_MP;
extern uint8 CoSync_ctEdgeCmIn_MP;
extern uint8 CoSync_ctTDCRaw;
extern uint8 CoSync_stCoSync;
extern uint8 COSYNC_u8CoSyncStCoSyncPrev;
extern uint8 COSYNC_u8ctEdgeCmInEx;
extern uint8 COSYNC_u8ExtCtEdgeCkPrev;
extern uint8 COSYNC_u8SyncCtTDCPrev;
extern uint16 CoSync_ctCfmVldSigCk_MP;
extern uint16 CoSync_ctCfmVldSigCm_MP;
extern uint16 CoSync_ctDetNNullBas_MP;
extern uint16 CoSync_ctDetNNullDgoCk_MP;
extern uint16 CoSync_ctMissSigCk_MP;
extern uint16 CoSync_ctMissSigCmEx_MP;
extern uint16 CoSync_ctMissSigCmIn_MP;
extern uint16 CoSync_tiDetNNullBas_MP;
extern uint16 COSYNC_u16DetEsCmfRawCntOutput;
extern uint16 COSYNC_u16DetEsCmfRawThd;
extern uint16 COSYNC_u16DetEsRawCntOutput;
extern uint16 COSYNC_u16DetEsRawThd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COSYNC_vidActvCalcDetectionArret(void);
void COSYNC_vidActvCalcDiagPosArret(void);
void COSYNC_vidActvCalcRisqGrippgeVil(void);
void COSYNC_vidBouchSortiesDetecArret(void);
void COSYNC_vidBouchSortiesDgPosArret(void);
void COSYNC_vidBouchSortiesGrippgeVil(void);
void COSYNC_vidCalcAbsenceFrontsAAC(void);
void COSYNC_vidCalcAbsenceFrontsVil(void);
void COSYNC_vidCalculerComptrPMHa10ms(void);
void COSYNC_vidCnfrmValidSignAACOuVil(void);
void COSYNC_vidConnaitreEtatMoteur(void);
void COSYNC_vidCreerInfoArretMoteur(void);
void COSYNC_vidDetectArretAvcBckupVil(void);
void COSYNC_vidDetectArretSnsBckupVil(void);
void COSYNC_vidDetecterGererArretMotr(void);
void COSYNC_vidEvalAbsnceSignVilEtAAC(void);
void COSYNC_vidEvalDefailSignAACEtVil(void);
void COSYNC_vidEvalSignalAACAUtiliser(void);
void COSYNC_vidGenererSortiesFonction(void);
void COSYNC_vidInfrmRsqClcErrPosArret(void);
void COSYNC_vidInitOutput(void);
void COSYNC_vidPrevenirRisqGrippgeVil(void);
void COSYNC_vidSuperviseurFctSynchro(void);
void COSYNC_vidTraitInfoCmptFrontsAAC(void);
void COSYNC_vidTraitInfoCmptFrontsVil(void);


#endif /* COSYNC_L_H */

/*-------------------------------- end of file -------------------------------*/
