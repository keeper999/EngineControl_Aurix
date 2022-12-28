/***************************************************************************
;**
;** FILE NAME      : AIRTHRARCRKSP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "AIRTHRARCRKSP.H"
#include "AIRTHRARCRKSP_L.H"
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
const boolean  CrkMgt_bInhCkEngLoss_C = 0;
const boolean  CrkMng_bAcvThrClsEngStop_C = 0;
const boolean  Dtc_deboucle_config_toil = 0;
const uint8  Air_density_gain_pres_map[AIR_DENSITY_GAIN_PRES_MAP_COLS] = {0};
const uint8  Air_density_gain_temp_map[AIR_DENSITY_GAIN_TEMP_MAP_COLS] = {0};
const uint8  Air_density_gain_temp_map_bkpt[AIR_DENSITY_GAIN_TEMP_MAP_BKPT_COLS] = {0};
const uint8  AIRTHRARCRKSP_u8Inhib = 0;
const uint8  Dtc_facTranRStrtAuth_C = 0;
const uint8  Dtc_first_crank_delay_map[DTC_FIRST_CRANK_DELAY_MAP_COLS] = {0};
const uint8  Dtc_first_crank_delay_retry_map[DTC_FIRST_CRANK_DELAY_RETRY_MAP_COLS] = {0};
const uint8  Dtc_STT_crank_delay_retry_map[DTC_STT_CRANK_DELAY_RETRY_MAP_COLS] = {0};
const uint8  Dv_surf_pos_ped_bkpt_map[DV_SURF_POS_PED_BKPT_MAP_COLS] = {0};
const uint8  Toil_or_teau_bkpt_map[TOIL_OR_TEAU_BKPT_MAP_COLS] = {0};
const uint16  Air_density_gain_pres_map_bkpt[AIR_DENSITY_GAIN_PRES_MAP_BKPT_COLS] = {0};
const uint16  Dtc_dv_surf_deboucle_map[DTC_DV_SURF_DEBOUCLE_MAP_LNS][DTC_DV_SURF_DEBOUCLE_MAP_COLS] = {0};
const uint16  Dtc_dv_surf_STT_map[DTC_DV_SURF_STT_MAP_LNS][DTC_DV_SURF_STT_MAP_COLS] = {0};
const uint16  Dtc_first_crank_decay_map[DTC_FIRST_CRANK_DECAY_MAP_COLS] = {0};
const uint16  Dtc_first_crank_decay_retry_map[DTC_FIRST_CRANK_DECAY_RETRY_MAP_COLS] = {0};
const uint16  Dtc_first_crank_offset_map[DTC_FIRST_CRANK_OFFSET_MAP_COLS] = {0};
const uint16  Dtc_first_crank_offset_retry_map[DTC_FIRST_CRANK_OFFSET_RETRY_MAP_COLS] = {0};
const uint16  Dtc_STT_crank_decay_retry_map[DTC_STT_CRANK_DECAY_RETRY_MAP_COLS] = {0};
const uint16  Dtc_STT_crank_offset_retry_map[DTC_STT_CRANK_OFFSET_RETRY_MAP_COLS] = {0};
const uint16  Dtc_surf_stop_map[DTC_SURF_STOP_MAP_COLS] = {0};
const uint16  Dtc_surf_stop_nEng_bkpt_map[DTC_SURF_STOP_NENG_BKPT_MAP_COLS] = {0};
const uint16  Dtc_surf_STT_nEng_bkpt_map[DTC_SURF_STT_NENG_BKPT_MAP_COLS] = {0};
const uint16  Dtc_surf_STT_stop_map[DTC_SURF_STT_STOP_MAP_COLS] = {0};
const uint16  Dtc_surf_STT_stop_RStrtInh_map[DTC_SURF_STT_STOP_RSTRTINH_MAP_COLS] = {0};
const uint16  Dtc_teau_toil_surf_deboucle_map[DTC_TEAU_TOIL_SURF_DEBOUCLE_MAP_LNS][DTC_TEAU_TOIL_SURF_DEBOUCLE_MAP_COLS] = {0};
const uint16  Dtc_teau_toil_surf_STT_map[DTC_TEAU_TOIL_SURF_STT_MAP_LNS][DTC_TEAU_TOIL_SURF_STT_MAP_COLS] = {0};
const uint16  Dtc_trans_couple_surf_map[DTC_TRANS_COUPLE_SURF_MAP_COLS] = {0};
const uint16  EngSt_rGainSpThrFctPAir_M[ENGST_RGAINSPTHRFCTPAIR_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 AIRTHRARCRKSP_u8SlewRateOutput;
uint8 Dtc_first_crank_offset_delay;
uint8 Dtc_first_crank_offset_torque;
uint8 Dtc_toil_or_teau;
sint16 CrkMgt_tqLoss_ThrArCrkAdp;
uint16 Air_density_gain;
uint16 Dtc_first_crank_decay_step;
uint16 Dtc_first_crank_offset;
uint16 Dtc_surf_hors_struc_couple;
uint16 Dtc_trans_couple_surf;
uint16 EngSt_rGainSpThrFctPAir;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

