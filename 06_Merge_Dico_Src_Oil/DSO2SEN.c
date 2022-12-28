/***************************************************************************
;**
;** FILE NAME      : DSO2SEN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DSO2SEN.H"
#include "DSO2SEN_L.H"
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
const boolean  Mode_banc_sonde_aval = 0;
const uint8  DSO2SEN_u8Inhib = 0;
const uint8  Ldsd_sensor_dead_zone_dec_step = 0;
const uint8  Ldsd_sensor_dead_zone_inc_step = 0;
const uint8  Ldsd_seuil_temp_eau_diag_masse = 0;
const uint8  Ldsd_tension_so2_filter_gain = 0;
const uint16  Ldsd_confirm_def_so2_av_delay = 0;
const uint16  Ldsd_destockage_so2_av_delay = 0;
const uint16  Ldsd_mass_diag_mf_emiss_thresh = 0;
const uint16  Ldsd_sensor_dead_zone_hi_thresh = 0;
const uint16  Ldsd_sensor_dead_zone_lo_thresh = 0;
const uint16  Ldsd_sensor_dead_zone_thresh = 0;
const uint16  Ldsd_seuil_tension_so2_masse = 0;
const uint16  Seuil_sonde_aval_pauvre = 0;
const uint16  Seuil_sonde_aval_riche = 0;
const uint16  Sonde_aval_slew_rate = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoOc_uDsLs;
boolean Ext_bDgoScg_uDsLs;
boolean Ext_bDgoScp_uDsLs;
boolean Ext_bMonRunOc_uDsLs;
boolean Ext_bMonRunScg_uDsLs;
boolean Ext_bMonRunScp_uDsLs;
boolean Ext_bMonWaitOc_DsO2Sen;
boolean Ext_bMonWaitScg_uDsLs;
boolean Ext_bMonWaitScp_uDsLs;
uint32 DSO2SEN_FiltredPositionMem;
uint8 Compteur_transition_sonde_aval;
uint16 Ldsd_confirm_def_so2_av_count;
uint16 Ldsd_destockage_so2_av_count;
uint16 Ldsd_sensor_dead_zone_count;
uint16 Plus_sonde_o2_av_result_ad_conv;
uint16 So2_av_signal_failure;
uint16 So2_av_signal_no_fail;
uint16 Tension_sonde_av_max_dc;
uint16 Tension_sonde_av_min_dc;
uint16 Tension_sonde_aval_brute;
uint16 Tension_sonde_aval_filtre;
uint16 Tension_sonde_aval_int;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

