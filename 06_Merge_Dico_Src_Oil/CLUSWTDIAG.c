/***************************************************************************
;**
;** FILE NAME      : CLUSWTDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CLUSWTDIAG.H"
#include "CLUSWTDIAG_L.H"
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
const uint8  Clu_spdMaxStuck_C = 0;
const uint8  CLUSWTDIAG_u8Inhib = 0;
const uint8  Cps_controle_coh_delay = 0;
const uint8  Cps_reg_mot_min_init_diag = 0;
const uint8  Cps_vit_veh_max_init_diag = 0;
const uint8  Cps_vit_veh_min_init_diag = 0;
const uint8  Cps_vitesse_max_diag_desac = 0;
const uint8  Cps_vitesse_max_sans_debrayage = 0;
const uint16  Cps_req_fuel_min_init_diag = 0;
const uint16  Cps_tempo_emb_max = 0;
const uint16  Cps_vitesse_vehicule_init_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Clu_stDiagCoh;
boolean Clu_bDftCohCtr;
boolean Clu_bDgoCoh_CluSt;
boolean Clu_bDgoStuck_CluSt;
boolean Clu_bDiagCohCdn;
boolean Clu_bDiagCohCtrAcvn;
boolean Clu_bDiagCohCtrInin;
boolean Clu_bDiagCohDacvn;
boolean Clu_bDiagCohIninCdn;
boolean Clu_bDiagStuckCtrAcvn;
boolean Clu_bDiagStuckCtrDacvn;
boolean Clu_bDiagStuckCtrInin;
boolean Clu_bMonRunCoh_CluSt;
boolean Clu_bMonRunStuck_CluSt;
boolean CLUSWTDIAG_bAllowCohRunnigToInit;
boolean CLUSWTDIAG_bExtBCluPedPrssPrev;
boolean CLUSWTDIAG_bMonRunStuck_prev;
boolean CLUSWTDIAG_bRisingCompInit_prev;
boolean Cps_controle_ok;
uint8 Cps_controle_coh_tempo;
uint16 Cps_emb_tempo;
uint16 Cps_vitesse_vehicule_init_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

