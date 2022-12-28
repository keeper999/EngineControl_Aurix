/***************************************************************************
;**
;** FILE NAME      : CLUSWTDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CLUSWTDIAG_L_H
#define CLUSWTDIAG_L_H

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

/* enum st48 */
#define CLU_INIT                          0
#define CLU_DIAG_COH_INIT                 1
#define CLU_DIAG_COH_RUNNING              2
#define CLU_DIAG_COH_NOK                  3
#define CLU_DIAG_COH_OK                   4
/*extern uint8 Clu_stDiagCoh;*/


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
extern uint8 Clu_stDiagCoh;
extern boolean Clu_bDftCohCtr;
extern boolean Clu_bDgoCoh_CluSt;
extern boolean Clu_bDgoStuck_CluSt;
extern boolean Clu_bDiagCohCdn;
extern boolean Clu_bDiagCohCtrAcvn;
extern boolean Clu_bDiagCohCtrInin;
extern boolean Clu_bDiagCohDacvn;
extern boolean Clu_bDiagCohIninCdn;
extern boolean Clu_bDiagStuckCtrAcvn;
extern boolean Clu_bDiagStuckCtrDacvn;
extern boolean Clu_bDiagStuckCtrInin;
extern boolean Clu_bMonRunCoh_CluSt;
extern boolean Clu_bMonRunStuck_CluSt;
extern boolean CLUSWTDIAG_bAllowCohRunnigToInit;
extern boolean CLUSWTDIAG_bExtBCluPedPrssPrev;
extern boolean CLUSWTDIAG_bMonRunStuck_prev;
extern boolean CLUSWTDIAG_bRisingCompInit_prev;
extern boolean Cps_controle_ok;
extern uint8 Cps_controle_coh_tempo;
extern uint16 Cps_emb_tempo;
extern uint16 Cps_vitesse_vehicule_init_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CLUSWTDIAG_vidCounter(void);
void CLUSWTDIAG_vidCps_switch_mal_cpt(void);
void CLUSWTDIAG_vidDgoCoh_CluSt(void);
void CLUSWTDIAG_vidDiagCoh(void);
void CLUSWTDIAG_vidDiagCohMonitoring(void);
void CLUSWTDIAG_vidDiagStuck(void);
void CLUSWTDIAG_vidDiagStuck_CluSt(void);
void CLUSWTDIAG_vidDiagStuckAcvn(void);
void CLUSWTDIAG_vidDiagStuckDft(void);
void CLUSWTDIAG_vidDiagStuckInitTempo(void);
void CLUSWTDIAG_vidEventFlagOn(void);
void CLUSWTDIAG_vidInit(void);
void CLUSWTDIAG_vidInitDiagStuck(void);
void CLUSWTDIAG_vidInitOutput(void);
void CLUSWTDIAG_vidStateCluInit(void);
void CLUSWTDIAG_vidTempo(void);
void CLUSWTDIAG_vidTempoCoh(void);
void CLUSWTDIAG_vidTempoStuck(void);


#endif /* CLUSWTDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
