/***************************************************************************
;**
;** FILE NAME      : INJFARCTLDSCTL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INJFARCTLDSCTL.H"
#include "INJFARCTLDSCTL_L.H"
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
const boolean  EEPROM_Feedback_correction_C = 0;
const boolean  Manu_inh_delta_sonde_aval_gaz = 0;
const boolean  Manu_inh_reset_dnstr_int = 0;
const boolean  Test_bed_pi_feedback_correction = 0;
const boolean  Test_bed_tension_cns_sonde_aval = 0;
const uint8  Dnstr_err_tension_int_gain_map[DNSTR_ERR_TENSION_INT_GAIN_MAP_COLS] = {0};
const uint8  Dnstr_err_tension_pro_gain_map[DNSTR_ERR_TENSION_PRO_GAIN_MAP_COLS] = {0};
const uint8  Dnstr_lambda_water_temp_thresh_c = 0;
const uint8  INJFARCTLDSCTL_u8Inhib = 0;
const sint16  Feedback_correction_c = 0;
const sint16  Init_Calib_Feedback_correction_C = 0;
const uint16  Dnstr_down_stream_ref_voltage_c = 0;
const uint16  Dnstr_dwn_strm_ref_volt_emis_map[DNSTR_DWN_STRM_REF_VOLT_EMIS_MAP_LNS][DNSTR_DWN_STRM_REF_VOLT_EMIS_MAP_COLS] = {0};
const uint16  Dnstr_dwn_strm_ref_volt_neuf_map[DNSTR_DWN_STRM_REF_VOLT_NEUF_MAP_LNS][DNSTR_DWN_STRM_REF_VOLT_NEUF_MAP_COLS] = {0};
const uint16  Dnstr_entry_delay_c = 0;
const uint16  Dnstr_err_tension_gain_bkpt_map[DNSTR_ERR_TENSION_GAIN_BKPT_MAP_COLS] = {0};
const uint16  Dnstr_fenetre_activation_bas = 0;
const uint16  Dnstr_fenetre_activation_haut = 0;
const uint16  Dnstr_int_gain_map[DNSTR_INT_GAIN_MAP_COLS] = {0};
const uint16  Dnstr_lambda_load_max_thresh_c = 0;
const uint16  Dnstr_lambda_load_min_thresh_c = 0;
const uint16  Dnstr_lambda_speed_max_thresh_c = 0;
const uint16  Dnstr_lambda_speed_min_thresh_c = 0;
const uint16  Dnstr_pro_gain_map[DNSTR_PRO_GAIN_MAP_COLS] = {0};
const uint16  Dnstr_retard_purge_pauvre_max = 0;
const uint16  Dnstr_retard_purge_pauvre_pas = 0;
const uint16  Dnstr_retard_purge_riche_max = 0;
const uint16  Dnstr_retard_purge_riche_pas = 0;
const uint16  Dnstr_settling_delay_c = 0;
const uint16  Dnstr_seuil_tension_av_bas_hyst = 0;
const uint16  Dnstr_seuil_tension_av_haut_hyst = 0;
const uint16  Dnstr_seuil_tension_aval_bas = 0;
const uint16  Dnstr_seuil_tension_aval_haut = 0;
const uint16  Dnstr_time_in_high_volt_delay = 0;
const uint16  Dnstr_time_in_low_volt_delay = 0;
const uint16  Engine_load_2_bkpt_map[ENGINE_LOAD_2_BKPT_MAP_COLS] = {0};
const uint16  EngM_mfTotExCor_bkpt_map[ENGM_MFTOTEXCOR_BKPT_MAP_COLS] = {0};
const uint16  Fb_corr_max_lim_c = 0;
const uint16  Fb_corr_min_lim_c = 0;
const uint16  Fb_correction_int_max = 0;
const uint16  Fb_correction_int_min = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Current_dnstr_correction_state;
boolean Dnstr_conds_met;
boolean Dnstr_purge_cata_done_wo_result;
boolean Dnstr_purge_cata_low;
boolean Dnstr_purge_cata_rich;
boolean Enable_decre_low_count;
boolean Enable_decre_rich_count;
boolean INJFARCTLDSCTL_bEnableCalcModif;
boolean INJFARCTLDSCTL_bHystOutputLow;
boolean INJFARCTLDSCTL_bHystOutputRich;
uint8 Dnstr_add_pmh_modifier;
uint8 Dnstr_err_tension_int_gain;
uint8 Dnstr_err_tension_pro_gain;
uint8 Dnstr_substract_pmh_modifier;
sint16 Feedback_correction;
sint16 Feedback_correction_int;
sint16 Feedback_correction_pro;
uint16 Dnstr_add_s_modifier;
uint16 Dnstr_down_stream_ref_voltage;
uint16 Dnstr_entry_delay;
uint16 Dnstr_err_tension;
uint16 Dnstr_err_tension_prec;
uint16 Dnstr_int_gain;
uint16 Dnstr_pro_gain;
uint16 Dnstr_retard_purge_pauvre;
uint16 Dnstr_retard_purge_riche;
uint16 Dnstr_retard_s_purge_pauvre;
uint16 Dnstr_retard_s_purge_riche;
uint16 Dnstr_settling_delay;
uint16 Dnstr_substract_s_modifier;
uint16 Dnstr_time_in_high_volt_count;
uint16 Dnstr_time_in_low_volt_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

