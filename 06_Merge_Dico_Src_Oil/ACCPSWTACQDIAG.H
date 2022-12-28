/***************************************************************************
;**
;** FILE NAME      : ACCPSWTACQDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPSWTACQDIAG_H
#define ACCPSWTACQDIAG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENFONCE                           1
#define NON_FRANCHI                       0

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st11 */
#define LVV_STABLE_HAUT                   1
#define LVV_TRANSITOIRE_HAUT              2
#define LVV_TRANSITOIRE_INVALIDE          3
#define LVV_TRANSITOIRE_BAS               4
#define LVV_STABLE_BAS                    5
#define DEFAUT_HAUT                       6
#define DEFAUT_INVALIDE                   7
#define DEFAUT_BAS                        8
/*extern uint8 Lvv_etat_capteur;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  Lvv_nconf1_chg_etat_bas;
extern const uint8  Lvv_nconf1_chg_etat_haut;
extern const uint8  Lvv_nconf2_defaut_elec;
extern const uint8  Lvv_nconf3_etat_valid_rehab_def;
extern const uint16  AccP_point_dur_thd_C;
extern const uint16  Delai_maintien_etat_pt_dur;
extern const uint16  Lvv_seuil_detection_cc_masse;
extern const uint16  Lvv_seuil_detection_cc_vbat;
extern const uint16  Lvv_u_inf_plage_valide_basse;
extern const uint16  Lvv_u_inf_plage_valide_haute;
extern const uint16  Lvv_u_sup_plage_valide_basse;
extern const uint16  Lvv_u_sup_plage_valide_haute;
extern const uint16  Seuil_pedale_point_dur_bas;
extern const uint16  Seuil_pedale_point_dur_haut;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Lvv_etat_capteur;
extern boolean Cc_accel_pedal_wot_request;
extern boolean Etat_point_dur;
extern boolean Lvv_pt_dur_ad_conv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AccP_EveRst_SwtAcqDiag(void);
void AccP_SdlFast_SwtAcqDiag(void);


#endif /* ACCPSWTACQDIAG_H */

/*-------------------------------- end of file -------------------------------*/
