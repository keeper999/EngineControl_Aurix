/***************************************************************************
;**
;** FILE NAME      : DSO2SEN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DSO2SEN_H
#define DSO2SEN_H

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

extern const boolean  Mode_banc_sonde_aval;
extern const uint8  Ldsd_sensor_dead_zone_dec_step;
extern const uint8  Ldsd_sensor_dead_zone_inc_step;
extern const uint8  Ldsd_seuil_temp_eau_diag_masse;
extern const uint8  Ldsd_tension_so2_filter_gain;
extern const uint16  Ldsd_confirm_def_so2_av_delay;
extern const uint16  Ldsd_destockage_so2_av_delay;
extern const uint16  Ldsd_mass_diag_mf_emiss_thresh;
extern const uint16  Ldsd_sensor_dead_zone_hi_thresh;
extern const uint16  Ldsd_sensor_dead_zone_lo_thresh;
extern const uint16  Ldsd_sensor_dead_zone_thresh;
extern const uint16  Ldsd_seuil_tension_so2_masse;
extern const uint16  Seuil_sonde_aval_pauvre;
extern const uint16  Seuil_sonde_aval_riche;
extern const uint16  Sonde_aval_slew_rate;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Compteur_transition_sonde_aval;
extern uint16 So2_av_signal_failure;
extern uint16 So2_av_signal_no_fail;
extern uint16 Tension_sonde_aval_brute;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SenO2Ds_EveCrTR_DsLsAcq(void);
void SenO2Ds_EveRst_DsLsAcq(void);
void SenO2Ds_SdlFast_DsLsAcq(void);
void SenO2Ds_SdlLow_DsLsAcq(void);
void SenO2Ds_SdlMid_DsLsAcq(void);


#endif /* DSO2SEN_H */

/*-------------------------------- end of file -------------------------------*/
