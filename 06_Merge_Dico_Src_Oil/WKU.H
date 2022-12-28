/***************************************************************************
;**
;** FILE NAME      : WKU.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WKU_H
#define WKU_H

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

extern const boolean  Rcd_auto_reveil_princ_req_diag;
extern const boolean  Rcd_bAcv_KeyOn_event_on_reset_C;
extern const boolean  Rcd_inh_anticipation_adc;
extern const boolean  Rcd_inh_anticipation_adc_bloque;
extern const boolean  Rcd_inh_mes_huile_moteur;
extern const boolean  Rcd_inh_mes_huile_moteur_bloque;
extern const boolean  Rcd_inh_post_ventil_mot;
extern const boolean  Rcd_inh_post_ventil_mot_bloque;
extern const boolean  Rcd_inh_prepa_moteur_bloque;
extern const boolean  Rcd_inh_preparation_moteur;
extern const uint8  Rcd_clef_off_default_delay;
extern const uint8  Rcd_nbr_trame_432_max;
extern const uint8  Rcd_nbr_trame_432_min;
extern const uint8  Rcd_retour_power_on_nb;
extern const uint8  Rcd_reveil_partiel_count_off;
extern const uint8  Rcd_reveil_partiel_count_on;
extern const uint8  Rcd_reveil_principal_count_off;
extern const uint8  Rcd_reveil_principal_count_on;
extern const uint8  Rcd_seuil_regime_clef_off;
extern const uint8  Rcd_seuil_regime_clef_off_def;
extern const uint8  Rcd_seuil_vvh_clef_off;
extern const uint8  Rcd_seuil_vvh_clef_off_def;
extern const uint8  Rcd_surveil_trame_C;
extern const uint16  Rcd_bascule_vers_principal_delay;
extern const uint16  Rcd_reveil_partiel_max_delay;
extern const uint16  Rcd_reveil_partiel_pvm_max_delay;
extern const uint16  Rcd_tempo_boot_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ECU_bOilWkuSt;
extern boolean ECU_bPrepIgEngWkuSt;
extern boolean ECU_bStopEngCoWkuSt;
extern boolean ECU_bUcapWkuSt;
extern boolean ECU_bWkuPtEngStrt;
extern boolean Rcd_anticipation_adc;
extern boolean Rcd_mes_huile_moteur;
extern boolean Rcd_post_ventil_mot;
extern boolean Rcd_preparation_moteur;
extern uint8 Rcd_retour_power_on_count;
extern uint16 Ext_bfSlavePtlWkuSt;
extern uint16 Rcd_tempo_boot_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void EcuSt_EveIni_Wku(void);
void EcuSt_EveRst_Wku(void);
void EcuSt_EveRxn432_Wku(void);
void EcuSt_SdlFast_Wku(void);
void EcuSt_SdlMid_Wku(void);
void EcuSt_SdlSlow_Wku(void);


#endif /* WKU_H */

/*-------------------------------- end of file -------------------------------*/
