/***************************************************************************
;**
;** FILE NAME      : KNKADPCOR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKADPCOR.H"
#include "KNKADPCOR_L.H"
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
const boolean  Av_bmax_inh_reset_chgt_zone = 0;
const boolean  Av_bmax_inh_reset_zone_crit = 0;
const boolean  Manu_inh_avance_adapt = 0;
const uint8  Av_bmax_adapt_anti_k_cyl1_C[AV_BMAX_ADAPT_ANTI_K_CYL1_C_COLS] = {0};
const uint8  Av_bmax_adapt_anti_k_cyl2_C[AV_BMAX_ADAPT_ANTI_K_CYL2_C_COLS] = {0};
const uint8  Av_bmax_adapt_anti_k_cyl3_C[AV_BMAX_ADAPT_ANTI_K_CYL3_C_COLS] = {0};
const uint8  Av_bmax_adapt_anti_k_cyl4_C[AV_BMAX_ADAPT_ANTI_K_CYL4_C_COLS] = {0};
const uint8  Av_bmax_adapt_anti_k_gain = 0;
const uint8  Av_bmax_adapt_anti_k_teau_seuil = 0;
const uint8  Av_bmax_corr_adapt_defaut_anti_k = 0;
const uint8  Av_bmax_corr_decal_pas_dec = 0;
const uint8  Av_bmax_corr_decal_pas_inc = 0;
const uint8  Av_bmax_ecart_max_T[AV_BMAX_ECART_MAX_T_COLS] = {0};
const uint8  Av_bmax_regime_moteur_seuil = 0;
const uint8  Knk_adapt_dec_delta_min = 0;
const uint8  Knk_adapt_filt_gain_map[KNK_ADAPT_FILT_GAIN_MAP_LNS][KNK_ADAPT_FILT_GAIN_MAP_COLS] = {0};
const uint8  Knk_adapt_inc_delta_min = 0;
const uint8  Knk_adapt_load_hysteresis = 0;
const uint8  Knk_adapt_load_hysteresis_zone0 = 0;
const uint8  Knk_adapt_n_hysteresis = 0;
const uint8  Knk_adapt_n_hysteresis_zone0 = 0;
const uint8  KnkAdpCor_agActRawDeltaThd_C = 0;
const uint8  KNKADPCOR_u8Inhib = 0;
const uint8  Regime_moteur_6_bkpt_map[REGIME_MOTEUR_6_BKPT_MAP_COLS] = {0};
const sint16  Av_bmax_adapt_anti_k_min = 0;
const uint16  Av_bmax_decrem_delai_map[AV_BMAX_DECREM_DELAI_MAP_COLS] = {0};
const uint16  Av_bmax_max_slew_rate_map[AV_BMAX_MAX_SLEW_RATE_MAP_COLS] = {0};
const uint16  Av_bmax_pas_dec_adapt_map[AV_BMAX_PAS_DEC_ADAPT_MAP_COLS] = {0};
const uint16  Av_bmax_retard_delai_map[AV_BMAX_RETARD_DELAI_MAP_COLS] = {0};
const uint16  Engine_load_5_bkpt_map[ENGINE_LOAD_5_BKPT_MAP_COLS] = {0};
const uint16  IgLim_agIgMaxAdpThresh_M[IGLIM_AGIGMAXADPTHRESH_M_LNS][IGLIM_AGIGMAXADPTHRESH_M_COLS] = {0};
const uint16  IgLim_agIgMinAdpThresh_M[IGLIM_AGIGMINADPTHRESH_M_LNS][IGLIM_AGIGMINADPTHRESH_M_COLS] = {0};
const uint16  Knk_adapt_load_stab_thresh = 0;
const uint16  Knk_adapt_n_stab_thresh = 0;
const uint16  Knk_adapt_stable_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Av_bmax_autorise_adaptation;
boolean Av_bmax_conditions_raz_cptr;
boolean Av_bmax_ena_temperature_basse;
boolean Av_bmax_ena_temperature_haute;
boolean Knk_adapt_engine_stable;
boolean Knk_adapt_load_stable;
boolean Knk_adapt_n_stable;
boolean KNKADPCOR_bAdaptHyst01;
boolean KNKADPCOR_bAdaptHyst02;
boolean KNKADPCOR_bAdaptHyst03;
boolean KNKADPCOR_bAdaptHyst04;
boolean KNKADPCOR_bBvmp_inh_cliqacqPrev;
boolean KNKADPCOR_boutputHysteresis1;
boolean KNKADPCOR_boutputHysteresis2;
boolean KNKADPCOR_boutputHysteresis3;
boolean KNKADPCOR_boutputHysteresis4;
boolean KNKADPCOR_bRFuDetRstAdpPrev;
boolean KnkAdpCor_bTreatZoneTran[KNKADPCOR_BTREATZONETRAN_COLS];
boolean KNKADPCOR_bZone_critiquePrev;
sint8 Av_bmax_cor_adpt_anti_k_raw_cyl[AV_BMAX_COR_ADPT_ANTI_K_RAW_CYL_COLS];
sint8 Av_bmax_corr_adapt_anti_k[AV_BMAX_CORR_ADAPT_ANTI_K_COLS];
sint8 Av_bmax_corr_adapt_anti_k_cyl1[AV_BMAX_CORR_ADAPT_ANTI_K_CYL1_COLS];
sint8 Av_bmax_corr_adapt_anti_k_cyl2[AV_BMAX_CORR_ADAPT_ANTI_K_CYL2_COLS];
sint8 Av_bmax_corr_adapt_anti_k_cyl3[AV_BMAX_CORR_ADAPT_ANTI_K_CYL3_COLS];
sint8 Av_bmax_corr_adapt_anti_k_cyl4[AV_BMAX_CORR_ADAPT_ANTI_K_CYL4_COLS];
sint8 Av_bmax_corr_appliquee_cyl[AV_BMAX_CORR_APPLIQUEE_CYL_COLS];
uint8 Av_bmax_ecart_max;
uint8 Knk_adapt_filt_gain;
uint8 Knk_adapt_load_zone;
uint8 Knk_adapt_n_zone;
uint8 Knk_adapt_nb_n_zone;
uint8 Knk_adapt_zone_fct;
uint8 Knk_adapt_zone_fct_cyl[KNK_ADAPT_ZONE_FCT_CYL_COLS];
uint8 KNKADPCOR_u8adapt_zone_fctPrev;
uint8 KNKADPCOR_u8KnkAdaptZoneCylPrev[KNKADPCOR_U8KNKADAPTZONECYLPREV_COLS];
sint16 Av_bmax_adap_avt_slew_rate_cyl[AV_BMAX_ADAP_AVT_SLEW_RATE_CYL_COLS];
sint16 Av_bmax_adapt_anti_k_cyl_prev[AV_BMAX_ADAPT_ANTI_K_CYL_PREV_COLS];
sint16 Av_bmax_adapt_anti_k_zone_cyl[AV_BMAX_ADAPT_ANTI_K_ZONE_CYL_COLS];
sint16 Av_bmax_adapt_anti_k_zone_cyl1;
sint16 Av_bmax_adapt_anti_k_zone_cyl2;
sint16 Av_bmax_adapt_anti_k_zone_cyl3;
sint16 Av_bmax_adapt_anti_k_zone_cyl4;
sint16 Av_bmax_adapt_avant_moy_cyl[AV_BMAX_ADAPT_AVANT_MOY_CYL_COLS];
sint16 Av_bmax_adapt_avant_moy_cyl_prev[AV_BMAX_ADAPT_AVANT_MOY_CYL_PREV_COLS];
sint16 Av_bmax_adapt_avant_moy_k;
sint16 Av_bmax_adapt_moyennee_cyl[AV_BMAX_ADAPT_MOYENNEE_CYL_COLS];
sint16 KnkAdpCor_agActAvmaxFineResl;
sint16 KnkAdpCor_agRawAvmaxFineResl;
sint16 KnkMgt_agIgKnkAdpOfsCylFineRsl[KNKMGT_AGIGKNKADPOFSCYLFINERSL_COLS];
uint16 Av_bmax_decrem_cptr_cyl[AV_BMAX_DECREM_CPTR_CYL_COLS];
uint16 Av_bmax_retard_cptr_cyl[AV_BMAX_RETARD_CPTR_CYL_COLS];
uint16 Knk_adapt_load_max;
uint16 Knk_adapt_load_min;
uint16 Knk_adapt_n_max;
uint16 Knk_adapt_n_min;
uint16 Knk_adapt_stable_counter;
uint16 Knk_engine_air_load;
uint16 Knk_engine_air_load_cyl[KNK_ENGINE_AIR_LOAD_CYL_COLS];
uint16 Knk_regime_moteur;
uint16 Knk_regime_moteur_cyl[KNK_REGIME_MOTEUR_CYL_COLS];
uint16 KNKADPCOR_u16Ext_rAirLdPrev;
uint16 KNKADPCOR_u16Regime_moteurPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

