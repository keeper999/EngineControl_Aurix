/***************************************************************************
;**
;** FILE NAME      : UPLSACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "UPLSACQ.H"
#include "UPLSACQ_L.H"
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
const uint8  Ldsen_active_dead_zone_temp = 0;
const uint8  Ldsen_sensor_dead_zone_dec_step = 0;
const uint8  Ldsen_sensor_dead_zone_inc_step = 0;
const uint8  Ldsen_seuil_temp_eau_diag_masse = 0;
const uint8  Ldsen_tension_so2_filter_gain = 0;
const uint8  Seuil_regime_moteur_filt_so2_am = 0;
const uint8  UPLSACQ_u8Inhib = 0;
const uint16  Inhibe_extrema_sonde_delay = 0;
const uint16  Ldsen_active_dead_zone_delay = 0;
const uint16  Ldsen_confirm_def_so2_am_delay = 0;
const uint16  Ldsen_gas_course_so2_am_delay = 0;
const uint16  Ldsen_masse_diag_mf_emiss_thresh = 0;
const uint16  Ldsen_sensor_dead_zone_hi_thresh = 0;
const uint16  Ldsen_sensor_dead_zone_lo_thresh = 0;
const uint16  Ldsen_sensor_dead_zone_thresh = 0;
const uint16  Ldsen_seuil_tension_so2_masse = 0;
const uint16  Seuil_maxi_tension_sonde = 0;
const uint16  Seuil_sonde_amont_pauvre = 0;
const uint16  Seuil_sonde_amont_riche = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoOc_uUpLs;
boolean Ext_bDgoScg_uUpLs;
boolean Ext_bDgoScp_uUpLs;
boolean Ext_bMonRunOc_uUpLs;
boolean Ext_bMonRunScg_uUpLs;
boolean Ext_bMonRunScp_uUpLs;
boolean Ext_bMonWaitOc_uUpLs;
boolean Ext_bMonWaitScg_uUpLs;
boolean Ext_bMonWaitScp_uUpLs;
boolean Panne_so2_am_presente;
boolean Tension_so2_am_first_computed;
boolean UPLSACQ_bFiltSondeEnablePrev;
uint32 UPLSACQ_u32FiltredVoltageMem;
uint8 Compteur_transition_sonde_amont;
uint16 Inhibe_extrema_sonde_count;
uint16 Ldsen_active_dead_zone_count;
uint16 Ldsen_confirm_def_so2_am_count;
uint16 Ldsen_gas_course_so2_am_count;
uint16 Ldsen_sensor_dead_zone_count;
uint16 Tension_sonde_am_max_dc;
uint16 Tension_sonde_am_min_dc;
uint16 Tension_sonde_amont;
uint16 Tension_sonde_amont_brute;
uint16 Tension_sonde_amont_filtree;
uint16 UPLSACQ_u16SenO2UsFiltred;
uint16 UPLSACQ_u16SenO2UsVoltagePrev1;
uint16 UPLSACQ_u16SenO2UsVoltagePrev2;
uint16 UPLSACQ_u16SenO2UsVoltagePrev3;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

