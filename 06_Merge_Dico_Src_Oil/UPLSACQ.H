/***************************************************************************
;**
;** FILE NAME      : UPLSACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef UPLSACQ_H
#define UPLSACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SenO2Us_SampleTiFast_SC           10
#define SenO2Us_SampleTiMid_SC            40
#define SenO2Us_SampleTiSlow_SC           1000

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

extern const uint8  Ldsen_active_dead_zone_temp;
extern const uint8  Ldsen_sensor_dead_zone_dec_step;
extern const uint8  Ldsen_sensor_dead_zone_inc_step;
extern const uint8  Ldsen_seuil_temp_eau_diag_masse;
extern const uint8  Ldsen_tension_so2_filter_gain;
extern const uint8  Seuil_regime_moteur_filt_so2_am;
extern const uint16  Inhibe_extrema_sonde_delay;
extern const uint16  Ldsen_active_dead_zone_delay;
extern const uint16  Ldsen_confirm_def_so2_am_delay;
extern const uint16  Ldsen_gas_course_so2_am_delay;
extern const uint16  Ldsen_masse_diag_mf_emiss_thresh;
extern const uint16  Ldsen_sensor_dead_zone_hi_thresh;
extern const uint16  Ldsen_sensor_dead_zone_lo_thresh;
extern const uint16  Ldsen_sensor_dead_zone_thresh;
extern const uint16  Ldsen_seuil_tension_so2_masse;
extern const uint16  Seuil_maxi_tension_sonde;
extern const uint16  Seuil_sonde_amont_pauvre;
extern const uint16  Seuil_sonde_amont_riche;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Compteur_transition_sonde_amont;
extern uint16 Inhibe_extrema_sonde_count;
extern uint16 Tension_sonde_amont;
extern uint16 Tension_sonde_amont_brute;
extern uint16 Tension_sonde_amont_filtree;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SenO2Us_EveCrTR_UpLsAcq(void);
void SenO2Us_EveRst_UpLsAcq(void);
void SenO2Us_EveTDC_UpLsAcq(void);
void SenO2Us_SdlFast_UpLsAcq(void);
void SenO2Us_SdlMid_UpLsAcq(void);
void SenO2Us_SdlSlow_UpLsAcq(void);


#endif /* UPLSACQ_H */

/*-------------------------------- end of file -------------------------------*/
