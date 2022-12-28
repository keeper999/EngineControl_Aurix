/***************************************************************************
;**
;** FILE NAME      : INJFARCTLDSCTL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJFARCTLDSCTL_H
#define INJFARCTLDSCTL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DNSTR_DWN_STRM_REF_VOLT_EMIS_MAP_LNS  ( 9 )
#define DNSTR_DWN_STRM_REF_VOLT_EMIS_MAP_COLS  ( 9 )
#define DNSTR_DWN_STRM_REF_VOLT_NEUF_MAP_LNS  ( 9 )
#define DNSTR_DWN_STRM_REF_VOLT_NEUF_MAP_COLS  ( 9 )
#define DNSTR_ERR_TENSION_GAIN_BKPT_MAP_COLS   ( 9 )
#define DNSTR_ERR_TENSION_INT_GAIN_MAP_COLS    ( 9 )
#define DNSTR_ERR_TENSION_PRO_GAIN_MAP_COLS    ( 9 )
#define DNSTR_INT_GAIN_MAP_COLS                ( 9 )
#define DNSTR_PRO_GAIN_MAP_COLS                ( 9 )
#define ENGINE_LOAD_2_BKPT_MAP_COLS            ( 9 )
#define ENGM_MFTOTEXCOR_BKPT_MAP_COLS          ( 9 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st49 */
#define INIT_CTRL_DNSTR_CORRECTION        1
#define WAITING_DNSTR_GENERAL_CONDS       2
#define WAITING_FOR_DNSTR_CTRL_CONDS      4
#define WAITING_FOR_OFFSET_DELAY          8
#define DOWNSTREAM_SENSOR_CTRL            16
#define DNSTR_PURGE_CATA                  32
/*extern uint8 Current_dnstr_correction_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  EEPROM_Feedback_correction_C;
extern const boolean  Manu_inh_delta_sonde_aval_gaz;
extern const boolean  Manu_inh_reset_dnstr_int;
extern const boolean  Test_bed_pi_feedback_correction;
extern const boolean  Test_bed_tension_cns_sonde_aval;
extern const uint8  Dnstr_err_tension_int_gain_map[DNSTR_ERR_TENSION_INT_GAIN_MAP_COLS];
extern const uint8  Dnstr_err_tension_pro_gain_map[DNSTR_ERR_TENSION_PRO_GAIN_MAP_COLS];
extern const uint8  Dnstr_lambda_water_temp_thresh_c;
extern const sint16  Feedback_correction_c;
extern const sint16  Init_Calib_Feedback_correction_C;
extern const uint16  Dnstr_down_stream_ref_voltage_c;
extern const uint16  Dnstr_dwn_strm_ref_volt_emis_map[DNSTR_DWN_STRM_REF_VOLT_EMIS_MAP_LNS][DNSTR_DWN_STRM_REF_VOLT_EMIS_MAP_COLS];
extern const uint16  Dnstr_dwn_strm_ref_volt_neuf_map[DNSTR_DWN_STRM_REF_VOLT_NEUF_MAP_LNS][DNSTR_DWN_STRM_REF_VOLT_NEUF_MAP_COLS];
extern const uint16  Dnstr_entry_delay_c;
extern const uint16  Dnstr_err_tension_gain_bkpt_map[DNSTR_ERR_TENSION_GAIN_BKPT_MAP_COLS];
extern const uint16  Dnstr_fenetre_activation_bas;
extern const uint16  Dnstr_fenetre_activation_haut;
extern const uint16  Dnstr_int_gain_map[DNSTR_INT_GAIN_MAP_COLS];
extern const uint16  Dnstr_lambda_load_max_thresh_c;
extern const uint16  Dnstr_lambda_load_min_thresh_c;
extern const uint16  Dnstr_lambda_speed_max_thresh_c;
extern const uint16  Dnstr_lambda_speed_min_thresh_c;
extern const uint16  Dnstr_pro_gain_map[DNSTR_PRO_GAIN_MAP_COLS];
extern const uint16  Dnstr_retard_purge_pauvre_max;
extern const uint16  Dnstr_retard_purge_pauvre_pas;
extern const uint16  Dnstr_retard_purge_riche_max;
extern const uint16  Dnstr_retard_purge_riche_pas;
extern const uint16  Dnstr_settling_delay_c;
extern const uint16  Dnstr_seuil_tension_av_bas_hyst;
extern const uint16  Dnstr_seuil_tension_av_haut_hyst;
extern const uint16  Dnstr_seuil_tension_aval_bas;
extern const uint16  Dnstr_seuil_tension_aval_haut;
extern const uint16  Dnstr_time_in_high_volt_delay;
extern const uint16  Dnstr_time_in_low_volt_delay;
extern const uint16  Engine_load_2_bkpt_map[ENGINE_LOAD_2_BKPT_MAP_COLS];
extern const uint16  EngM_mfTotExCor_bkpt_map[ENGM_MFTOTEXCOR_BKPT_MAP_COLS];
extern const uint16  Fb_corr_max_lim_c;
extern const uint16  Fb_corr_min_lim_c;
extern const uint16  Fb_correction_int_max;
extern const uint16  Fb_correction_int_min;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Current_dnstr_correction_state;
extern boolean Dnstr_conds_met;
extern boolean Dnstr_purge_cata_low;
extern boolean Dnstr_purge_cata_rich;
extern uint8 Dnstr_add_pmh_modifier;
extern uint8 Dnstr_substract_pmh_modifier;
extern sint16 Feedback_correction;
extern uint16 Dnstr_add_s_modifier;
extern uint16 Dnstr_retard_purge_pauvre;
extern uint16 Dnstr_retard_purge_riche;
extern uint16 Dnstr_substract_s_modifier;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void InjCtl_EveRst_InjFarCtlDsCtl(void);
void InjCtl_SdlFast_InjFarCtlDsCtl(void);
void InjCtl_SdlMid_InjFarCtlDsCtl(void);


#endif /* INJFARCTLDSCTL_H */

/*-------------------------------- end of file -------------------------------*/
