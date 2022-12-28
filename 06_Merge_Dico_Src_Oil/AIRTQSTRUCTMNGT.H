/***************************************************************************
;**
;** FILE NAME      : AIRTQSTRUCTMNGT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIRTQSTRUCTMNGT_H
#define AIRTQSTRUCTMNGT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CrkMgt_SampleTiMid_SC             20
#define DTC_COEF_DE_TRANS_DEC_DEM_MAP_COLS     ( 16 )
#define DTC_COEF_DE_TRANS_DEC_STT_MAP_COLS     ( 16 )
#define DTC_SECOND_CRANK_DELAY_MAP_COLS        ( 16 )
#define DTC_SEUIL_RATIO_PRES_TRANS_MAP_COLS    ( 16 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st12 */
#define DTC_INIT_DEM_SURFACE              1
#define DTC_FIRST_CRANK_SURFACE           2
#define DTC_SECOND_CRANK_SURFACE          4
#define DTC_TRANS_DEM_SURFACE             8
#define DTC_VERS_ET_STRUCTURE_COUPLE      32
#define DTC_VERS_ARRET                    64
#define DTC_VERS_ET_DEBOUCLEE             128
/*extern uint8 Dtc_etat_structure;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  CrkMng_bAcvKeyEngStopThrFil_C;
extern const boolean  Manu_inh_dtc_filtrage_air;
extern const boolean  Manu_inh_esp_torq_reduction;
extern const uint8  Dtc_coef_air_STT_ReStrt_Hi;
extern const uint8  Dtc_coef_air_STT_ReStrt_Lo;
extern const uint8  Dtc_coef_de_trans_air_arret_STT;
extern const uint8  Dtc_coef_de_trans_air_dec;
extern const uint8  Dtc_coef_de_trans_air_inc;
extern const uint8  Dtc_coef_de_trans_dec_dem_map[DTC_COEF_DE_TRANS_DEC_DEM_MAP_COLS];
extern const uint8  Dtc_coef_de_trans_dec_STT_map[DTC_COEF_DE_TRANS_DEC_STT_MAP_COLS];
extern const uint8  Dtc_coef_trans_air_dec_p_min;
extern const uint8  Dtc_pres_ratio_hysteresis;
extern const uint8  Dtc_second_crank_delay_map[DTC_SECOND_CRANK_DELAY_MAP_COLS];
extern const uint8  Dtc_seuil_deboucle_vitesse_min;
extern const uint8  Dtc_seuil_ratio_pres_trans_map[DTC_SEUIL_RATIO_PRES_TRANS_MAP_COLS];
extern const uint16  CrkMng_nEngSpdHiThd_C;
extern const uint16  CrkMng_nEngSpdLoThd_C;
extern const uint16  Dtc_fafr_obj_man_p_min_offset;
extern const uint16  Dtc_seuil_regime_de_trans_dem;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Dtc_etat_structure;
extern uint8 Coef_de_transition_air;
extern uint8 Dtc_second_crank_offset_delay;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CrkMgt_EveRst_AirTqStructMngt(void);
void CrkMgt_SdlFast_AirTqStructMngt(void);
void CrkMgt_SdlMid_AirTqStructMngt(void);


#endif /* AIRTQSTRUCTMNGT_H */

/*-------------------------------- end of file -------------------------------*/
