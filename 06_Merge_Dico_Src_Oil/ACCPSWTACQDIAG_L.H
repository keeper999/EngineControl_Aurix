/***************************************************************************
;**
;** FILE NAME      : ACCPSWTACQDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPSWTACQDIAG_L_H
#define ACCPSWTACQDIAG_L_H

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

extern const uint8  ACCPSWTACQDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AccP_bDgoCohAccPSwt;
extern boolean AccP_bDgoScgAccPSwt;
extern boolean AccP_bDgoScpAccPSwt;
extern boolean AccP_bDgoStuckAccPSwt;
extern boolean AccP_bMonRunCohAccPSwt;
extern boolean AccP_bMonRunScgAccPSwt;
extern boolean AccP_bMonRunScpAccPSwt;
extern boolean AccP_bMonRunStuckAccPSwt;
extern boolean Etat_point_dur_prev;
extern boolean Etat_point_dur_raw;
extern boolean Lvv_valid_basse;
extern boolean Lvv_valid_haute;
extern uint16 Lvv_cpt1_chg_etat_ou_rehab_def;
extern uint16 Lvv_cpt2_confirm_defaut_elec;
extern uint16 Lvv_pt_dur_result_ad_conv;
extern uint16 Tempo_maintien_etat_pt_dur;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACCPSWTACQDIAG_vidAccPedSwtAff(void);
void ACCPSWTACQDIAG_vidEndPointAffKD(void);
void ACCPSWTACQDIAG_vidEndPointCohAff(void);
void ACCPSWTACQDIAG_vidEndPointPedCoh(void);
void ACCPSWTACQDIAG_vidEndPtCounter(void);
void ACCPSWTACQDIAG_vidEndPtInstTempo(void);
void ACCPSWTACQDIAG_vidHightFailTrans(void);
void ACCPSWTACQDIAG_vidHightStabTrans(void);
void ACCPSWTACQDIAG_vidInitOutput(void);
void ACCPSWTACQDIAG_vidInitPointDur(void);
void ACCPSWTACQDIAG_vidInvFailTrans(void);
void ACCPSWTACQDIAG_vidLowFailTrans(void);
void ACCPSWTACQDIAG_vidLowStableTrans(void);
void ACCPSWTACQDIAG_vidLvvSwtAcq(void);
void ACCPSWTACQDIAG_vidLvvSwtAcqCond(void);
void ACCPSWTACQDIAG_vidLvvSwtDiag(void);
void ACCPSWTACQDIAG_vidLvvSwtDiagCond(void);
void ACCPSWTACQDIAG_vidMonitoringMng(void);
void ACCPSWTACQDIAG_vidMonitorMngCond(void);
void ACCPSWTACQDIAG_vidPtDurSensDetec(void);
void ACCPSWTACQDIAG_vidTempoHightTrans(void);
void ACCPSWTACQDIAG_vidTempoInvTrans(void);
void ACCPSWTACQDIAG_vidTempoLowTrans(void);


#endif /* ACCPSWTACQDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
