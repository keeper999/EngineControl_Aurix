/***************************************************************************
;**
;** FILE NAME      : AIRTQSTRUCTMNGT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "AIRTQSTRUCTMNGT.H"
#include "AIRTQSTRUCTMNGT_L.H"
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
const boolean  CrkMng_bAcvKeyEngStopThrFil_C = 0;
const boolean  Manu_inh_dtc_filtrage_air = 0;
const boolean  Manu_inh_esp_torq_reduction = 0;
const uint8  AIRTQSTRUCTMNGT_u8Inhib = 0;
const uint8  Dtc_coef_air_STT_ReStrt_Hi = 0;
const uint8  Dtc_coef_air_STT_ReStrt_Lo = 0;
const uint8  Dtc_coef_de_trans_air_arret_STT = 0;
const uint8  Dtc_coef_de_trans_air_dec = 0;
const uint8  Dtc_coef_de_trans_air_inc = 0;
const uint8  Dtc_coef_de_trans_dec_dem_map[DTC_COEF_DE_TRANS_DEC_DEM_MAP_COLS] = {0};
const uint8  Dtc_coef_de_trans_dec_STT_map[DTC_COEF_DE_TRANS_DEC_STT_MAP_COLS] = {0};
const uint8  Dtc_coef_trans_air_dec_p_min = 0;
const uint8  Dtc_pres_ratio_hysteresis = 0;
const uint8  Dtc_second_crank_delay_map[DTC_SECOND_CRANK_DELAY_MAP_COLS] = {0};
const uint8  Dtc_seuil_deboucle_vitesse_min = 0;
const uint8  Dtc_seuil_ratio_pres_trans_map[DTC_SEUIL_RATIO_PRES_TRANS_MAP_COLS] = {0};
const uint16  CrkMng_nEngSpdHiThd_C = 0;
const uint16  CrkMng_nEngSpdLoThd_C = 0;
const uint16  Dtc_fafr_obj_man_p_min_offset = 0;
const uint16  Dtc_seuil_regime_de_trans_dem = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Dtc_etat_structure;
boolean CrkMng_bIntrKeyHiEngSpd;
boolean CrkMng_bIntrKeyLoEngSpd;
boolean Dtc_structure_debouclee;
boolean Manu_coef_de_transition;
uint8 Coef_de_transition_air;
uint8 Dtc_obj_pres_ratio;
uint8 Dtc_second_crank_offset_delay;
uint8 Dtc_seuil_ratio_pres_trans;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

