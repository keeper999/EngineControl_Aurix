/***************************************************************************
;**
;** FILE NAME      : ACCPSWTACQDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACCPSWTACQDIAG.H"
#include "ACCPSWTACQDIAG_L.H"
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
const uint8  ACCPSWTACQDIAG_u8Inhib = 0;
const uint8  Lvv_nconf1_chg_etat_bas = 0;
const uint8  Lvv_nconf1_chg_etat_haut = 0;
const uint8  Lvv_nconf2_defaut_elec = 0;
const uint8  Lvv_nconf3_etat_valid_rehab_def = 0;
const uint16  AccP_point_dur_thd_C = 0;
const uint16  Delai_maintien_etat_pt_dur = 0;
const uint16  Lvv_seuil_detection_cc_masse = 0;
const uint16  Lvv_seuil_detection_cc_vbat = 0;
const uint16  Lvv_u_inf_plage_valide_basse = 0;
const uint16  Lvv_u_inf_plage_valide_haute = 0;
const uint16  Lvv_u_sup_plage_valide_basse = 0;
const uint16  Lvv_u_sup_plage_valide_haute = 0;
const uint16  Seuil_pedale_point_dur_bas = 0;
const uint16  Seuil_pedale_point_dur_haut = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Lvv_etat_capteur;
boolean AccP_bDgoCohAccPSwt;
boolean AccP_bDgoScgAccPSwt;
boolean AccP_bDgoScpAccPSwt;
boolean AccP_bDgoStuckAccPSwt;
boolean AccP_bMonRunCohAccPSwt;
boolean AccP_bMonRunScgAccPSwt;
boolean AccP_bMonRunScpAccPSwt;
boolean AccP_bMonRunStuckAccPSwt;
boolean Cc_accel_pedal_wot_request;
boolean Etat_point_dur;
boolean Etat_point_dur_prev;
boolean Etat_point_dur_raw;
boolean Lvv_pt_dur_ad_conv;
boolean Lvv_valid_basse;
boolean Lvv_valid_haute;
uint16 Lvv_cpt1_chg_etat_ou_rehab_def;
uint16 Lvv_cpt2_confirm_defaut_elec;
uint16 Lvv_pt_dur_result_ad_conv;
uint16 Tempo_maintien_etat_pt_dur;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

