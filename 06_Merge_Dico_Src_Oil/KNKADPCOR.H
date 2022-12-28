/***************************************************************************
;**
;** FILE NAME      : KNKADPCOR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKADPCOR_H
#define KNKADPCOR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AV_BMAX_ADAPT_ANTI_K_CYL1_C_COLS       ( 15 )
#define AV_BMAX_ADAPT_ANTI_K_CYL2_C_COLS       ( 15 )
#define AV_BMAX_ADAPT_ANTI_K_CYL3_C_COLS       ( 15 )
#define AV_BMAX_ADAPT_ANTI_K_CYL4_C_COLS       ( 15 )
#define AV_BMAX_ADAPT_ANTI_K_ZONE_CYL_COLS     ( 4 )
#define AV_BMAX_CORR_ADAPT_ANTI_K_COLS         ( 15 )
#define AV_BMAX_CORR_APPLIQUEE_CYL_COLS        ( 4 )
#define AV_BMAX_DECREM_DELAI_MAP_COLS          ( 16 )
#define AV_BMAX_ECART_MAX_T_COLS               ( 6 )
#define AV_BMAX_MAX_SLEW_RATE_MAP_COLS         ( 16 )
#define AV_BMAX_PAS_DEC_ADAPT_MAP_COLS         ( 16 )
#define AV_BMAX_RETARD_DELAI_MAP_COLS          ( 16 )
#define ENGINE_LOAD_5_BKPT_MAP_COLS            ( 4 )
#define IGLIM_AGIGMAXADPTHRESH_M_LNS          ( 4 )
#define IGLIM_AGIGMAXADPTHRESH_M_COLS          ( 6 )
#define IGLIM_AGIGMINADPTHRESH_M_LNS          ( 4 )
#define IGLIM_AGIGMINADPTHRESH_M_COLS          ( 6 )
#define KNK_ADAPT_FILT_GAIN_MAP_LNS           ( 4 )
#define KNK_ADAPT_FILT_GAIN_MAP_COLS           ( 6 )
#define KNKMGT_PRM_AGIGKNKADPOFSCYL_COLS       ( 6 )
#define REGIME_MOTEUR_6_BKPT_MAP_COLS          ( 6 )

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

extern const boolean  Av_bmax_inh_reset_chgt_zone;
extern const boolean  Av_bmax_inh_reset_zone_crit;
extern const boolean  Manu_inh_avance_adapt;
extern const uint8  Av_bmax_adapt_anti_k_cyl1_C[AV_BMAX_ADAPT_ANTI_K_CYL1_C_COLS];
extern const uint8  Av_bmax_adapt_anti_k_cyl2_C[AV_BMAX_ADAPT_ANTI_K_CYL2_C_COLS];
extern const uint8  Av_bmax_adapt_anti_k_cyl3_C[AV_BMAX_ADAPT_ANTI_K_CYL3_C_COLS];
extern const uint8  Av_bmax_adapt_anti_k_cyl4_C[AV_BMAX_ADAPT_ANTI_K_CYL4_C_COLS];
extern const uint8  Av_bmax_adapt_anti_k_gain;
extern const uint8  Av_bmax_adapt_anti_k_teau_seuil;
extern const uint8  Av_bmax_corr_adapt_defaut_anti_k;
extern const uint8  Av_bmax_corr_decal_pas_dec;
extern const uint8  Av_bmax_corr_decal_pas_inc;
extern const uint8  Av_bmax_ecart_max_T[AV_BMAX_ECART_MAX_T_COLS];
extern const uint8  Av_bmax_regime_moteur_seuil;
extern const uint8  Knk_adapt_dec_delta_min;
extern const uint8  Knk_adapt_filt_gain_map[KNK_ADAPT_FILT_GAIN_MAP_LNS][KNK_ADAPT_FILT_GAIN_MAP_COLS];
extern const uint8  Knk_adapt_inc_delta_min;
extern const uint8  Knk_adapt_load_hysteresis;
extern const uint8  Knk_adapt_load_hysteresis_zone0;
extern const uint8  Knk_adapt_n_hysteresis;
extern const uint8  Knk_adapt_n_hysteresis_zone0;
extern const uint8  KnkAdpCor_agActRawDeltaThd_C;
extern const uint8  KNKADPCOR_u8Inhib;
extern const uint8  Regime_moteur_6_bkpt_map[REGIME_MOTEUR_6_BKPT_MAP_COLS];
extern const sint16  Av_bmax_adapt_anti_k_min;
extern const uint16  Av_bmax_decrem_delai_map[AV_BMAX_DECREM_DELAI_MAP_COLS];
extern const uint16  Av_bmax_max_slew_rate_map[AV_BMAX_MAX_SLEW_RATE_MAP_COLS];
extern const uint16  Av_bmax_pas_dec_adapt_map[AV_BMAX_PAS_DEC_ADAPT_MAP_COLS];
extern const uint16  Av_bmax_retard_delai_map[AV_BMAX_RETARD_DELAI_MAP_COLS];
extern const uint16  Engine_load_5_bkpt_map[ENGINE_LOAD_5_BKPT_MAP_COLS];
extern const uint16  IgLim_agIgMaxAdpThresh_M[IGLIM_AGIGMAXADPTHRESH_M_LNS][IGLIM_AGIGMAXADPTHRESH_M_COLS];
extern const uint16  IgLim_agIgMinAdpThresh_M[IGLIM_AGIGMINADPTHRESH_M_LNS][IGLIM_AGIGMINADPTHRESH_M_COLS];
extern const uint16  Knk_adapt_load_stab_thresh;
extern const uint16  Knk_adapt_n_stab_thresh;
extern const uint16  Knk_adapt_stable_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint8 Av_bmax_corr_adapt_anti_k[AV_BMAX_CORR_ADAPT_ANTI_K_COLS];
extern sint8 Av_bmax_corr_appliquee_cyl[AV_BMAX_CORR_APPLIQUEE_CYL_COLS];
extern sint16 Av_bmax_adapt_anti_k_zone_cyl[AV_BMAX_ADAPT_ANTI_K_ZONE_CYL_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgLim_EveBDC_KnkAdpCor(void);
void IgLim_EveRst_KnkAdpCor(void);
void IgLim_SdlFast_KnkAdpCor(void);
void IgLim_SdlMid_KnkAdpCor(void);
void IgLim_SdlSlow_KnkAdpCor(void);


#endif /* KNKADPCOR_H */

/*-------------------------------- end of file -------------------------------*/
