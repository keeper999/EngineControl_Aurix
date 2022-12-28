/***************************************************************************
;**
;** FILE NAME      : WKU.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "WKU.H"
#include "WKU_L.H"
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
const boolean  Rcd_auto_reveil_princ_req_diag = 0;
const boolean  Rcd_bAcv_KeyOn_event_on_reset_C = 0;
const boolean  Rcd_inh_anticipation_adc = 0;
const boolean  Rcd_inh_anticipation_adc_bloque = 0;
const boolean  Rcd_inh_mes_huile_moteur = 0;
const boolean  Rcd_inh_mes_huile_moteur_bloque = 0;
const boolean  Rcd_inh_post_ventil_mot = 0;
const boolean  Rcd_inh_post_ventil_mot_bloque = 0;
const boolean  Rcd_inh_prepa_moteur_bloque = 0;
const boolean  Rcd_inh_preparation_moteur = 0;
const uint8  Rcd_clef_off_default_delay = 0;
const uint8  Rcd_nbr_trame_432_max = 0;
const uint8  Rcd_nbr_trame_432_min = 0;
const uint8  Rcd_retour_power_on_nb = 0;
const uint8  Rcd_reveil_partiel_count_off = 0;
const uint8  Rcd_reveil_partiel_count_on = 0;
const uint8  Rcd_reveil_principal_count_off = 0;
const uint8  Rcd_reveil_principal_count_on = 0;
const uint8  Rcd_seuil_regime_clef_off = 0;
const uint8  Rcd_seuil_regime_clef_off_def = 0;
const uint8  Rcd_seuil_vvh_clef_off = 0;
const uint8  Rcd_seuil_vvh_clef_off_def = 0;
const uint8  Rcd_surveil_trame_C = 0;
const uint8  WKU_u8Inhib = 0;
const uint16  Rcd_bascule_vers_principal_delay = 0;
const uint16  Rcd_reveil_partiel_max_delay = 0;
const uint16  Rcd_reveil_partiel_pvm_max_delay = 0;
const uint16  Rcd_tempo_boot_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Clef_de_contact_ss_coh;
boolean ECU_bOilWkuSt;
boolean ECU_bPrepIgEngWkuSt;
boolean ECU_bStopEngCoWkuSt;
boolean ECU_bUcapWkuSt;
boolean ECU_bWkuPtEngStrt;
boolean EcuSt_bDgoF432Lost;
boolean EcuSt_bDgoMainWkuDisrd;
boolean EcuSt_bDgoMainWkuIncst;
boolean EcuSt_bEngFanReq;
boolean EcuSt_bEngPrep;
boolean EcuSt_bImmoUnlockReq;
boolean EcuSt_bMonRunF432Lost;
boolean EcuSt_bMonRunMainWkuDisrd;
boolean EcuSt_bMonRunMainWkuIncst;
boolean EcuSt_bOilMesEng;
boolean EcuSt_bWkuMain;
boolean Ext_bDgoRCDLineScg;
boolean Ext_bMonRunRCDLineScg;
boolean Rcd_anticipation_adc;
boolean Rcd_demand_anticip_adc;
boolean Rcd_demand_mes_huile_moteur;
boolean Rcd_demand_post_ventil_mot;
boolean Rcd_demand_prepa_moteur;
boolean Rcd_mes_huile_moteur;
boolean Rcd_post_ventil_mot;
boolean Rcd_preparation_moteur;
boolean Temp_panne_coh_1;
boolean Temp_panne_coh_2;
uint8 Rcd_anticipation_adc_count;
uint8 Rcd_autoris_surveil_trame_compt;
uint8 Rcd_clef_off_default_count;
uint8 Rcd_mes_huile_moteur_count;
uint8 Rcd_post_ventil_mot_count;
uint8 Rcd_preparation_moteur_count;
uint8 Rcd_reception_trame_compteur;
uint8 Rcd_retour_power_on_count;
uint8 Rcd_reveil_principal_count;
uint16 Ext_bfSlavePtlWkuSt;
uint16 Rcd_anticipation_adc_max_count;
uint16 Rcd_bascule_vers_principal_count;
uint16 Rcd_mes_huile_moteur_max_count;
uint16 Rcd_post_ventil_mot_max_count;
uint16 Rcd_prepa_mot_max_count;
uint16 Rcd_tempo_boot_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

