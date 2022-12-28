/***************************************************************************
;**
;** FILE NAME      : KNKADPCOR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKADPCOR_L_H
#define KNKADPCOR_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AV_BMAX_ADAP_AVT_SLEW_RATE_CYL_COLS    ( 4 )
#define AV_BMAX_ADAPT_ANTI_K_CYL_PREV_COLS     ( 4 )
#define AV_BMAX_ADAPT_AVANT_MOY_CYL_COLS       ( 4 )
#define AV_BMAX_ADAPT_AVANT_MOY_CYL_PREV_COLS  ( 4 )
#define AV_BMAX_ADAPT_MOYENNEE_CYL_COLS        ( 4 )
#define AV_BMAX_COR_ADPT_ANTI_K_RAW_CYL_COLS   ( 4 )
#define AV_BMAX_CORR_ADAPT_ANTI_K_CYL1_COLS    ( 15 )
#define AV_BMAX_CORR_ADAPT_ANTI_K_CYL2_COLS    ( 15 )
#define AV_BMAX_CORR_ADAPT_ANTI_K_CYL3_COLS    ( 15 )
#define AV_BMAX_CORR_ADAPT_ANTI_K_CYL4_COLS    ( 15 )
#define AV_BMAX_DECREM_CPTR_CYL_COLS           ( 4 )
#define AV_BMAX_RETARD_CPTR_CYL_COLS           ( 4 )
#define KNK_ADAPT_ZONE_FCT_CYL_COLS            ( 4 )
#define KNK_ENGINE_AIR_LOAD_CYL_COLS           ( 4 )
#define KNK_REGIME_MOTEUR_CYL_COLS             ( 4 )
#define KNKADPCOR_BTREATZONETRAN_COLS          ( 4 )
#define KNKADPCOR_u32ADP_ARRAY_LENGTH     6
#define KNKADPCOR_u32ADV_ARRAY_LENGTH     4
#define KNKADPCOR_U8KNKADAPTZONECYLPREV_COLS   ( 4 )
#define KNKMGT_AGIGKNKADPOFSCYLFINERSL_COLS    ( 4 )

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Av_bmax_autorise_adaptation;
extern boolean Av_bmax_conditions_raz_cptr;
extern boolean Av_bmax_ena_temperature_basse;
extern boolean Av_bmax_ena_temperature_haute;
extern boolean Knk_adapt_engine_stable;
extern boolean Knk_adapt_load_stable;
extern boolean Knk_adapt_n_stable;
extern boolean KNKADPCOR_bAdaptHyst01;
extern boolean KNKADPCOR_bAdaptHyst02;
extern boolean KNKADPCOR_bAdaptHyst03;
extern boolean KNKADPCOR_bAdaptHyst04;
extern boolean KNKADPCOR_bBvmp_inh_cliqacqPrev;
extern boolean KNKADPCOR_boutputHysteresis1;
extern boolean KNKADPCOR_boutputHysteresis2;
extern boolean KNKADPCOR_boutputHysteresis3;
extern boolean KNKADPCOR_boutputHysteresis4;
extern boolean KNKADPCOR_bRFuDetRstAdpPrev;
extern boolean KnkAdpCor_bTreatZoneTran[KNKADPCOR_BTREATZONETRAN_COLS];
extern boolean KNKADPCOR_bZone_critiquePrev;
extern sint8 Av_bmax_cor_adpt_anti_k_raw_cyl[AV_BMAX_COR_ADPT_ANTI_K_RAW_CYL_COLS];
extern sint8 Av_bmax_corr_adapt_anti_k_cyl1[AV_BMAX_CORR_ADAPT_ANTI_K_CYL1_COLS];
extern sint8 Av_bmax_corr_adapt_anti_k_cyl2[AV_BMAX_CORR_ADAPT_ANTI_K_CYL2_COLS];
extern sint8 Av_bmax_corr_adapt_anti_k_cyl3[AV_BMAX_CORR_ADAPT_ANTI_K_CYL3_COLS];
extern sint8 Av_bmax_corr_adapt_anti_k_cyl4[AV_BMAX_CORR_ADAPT_ANTI_K_CYL4_COLS];
extern uint8 Av_bmax_ecart_max;
extern uint8 Knk_adapt_filt_gain;
extern uint8 Knk_adapt_load_zone;
extern uint8 Knk_adapt_n_zone;
extern uint8 Knk_adapt_nb_n_zone;
extern uint8 Knk_adapt_zone_fct;
extern uint8 Knk_adapt_zone_fct_cyl[KNK_ADAPT_ZONE_FCT_CYL_COLS];
extern uint8 KNKADPCOR_u8adapt_zone_fctPrev;
extern uint8 KNKADPCOR_u8KnkAdaptZoneCylPrev[KNKADPCOR_U8KNKADAPTZONECYLPREV_COLS];
extern sint16 Av_bmax_adap_avt_slew_rate_cyl[AV_BMAX_ADAP_AVT_SLEW_RATE_CYL_COLS];
extern sint16 Av_bmax_adapt_anti_k_cyl_prev[AV_BMAX_ADAPT_ANTI_K_CYL_PREV_COLS];
extern sint16 Av_bmax_adapt_anti_k_zone_cyl1;
extern sint16 Av_bmax_adapt_anti_k_zone_cyl2;
extern sint16 Av_bmax_adapt_anti_k_zone_cyl3;
extern sint16 Av_bmax_adapt_anti_k_zone_cyl4;
extern sint16 Av_bmax_adapt_avant_moy_cyl[AV_BMAX_ADAPT_AVANT_MOY_CYL_COLS];
extern sint16 Av_bmax_adapt_avant_moy_cyl_prev[AV_BMAX_ADAPT_AVANT_MOY_CYL_PREV_COLS];
extern sint16 Av_bmax_adapt_avant_moy_k;
extern sint16 Av_bmax_adapt_moyennee_cyl[AV_BMAX_ADAPT_MOYENNEE_CYL_COLS];
extern sint16 KnkAdpCor_agActAvmaxFineResl;
extern sint16 KnkAdpCor_agRawAvmaxFineResl;
extern sint16 KnkMgt_agIgKnkAdpOfsCylFineRsl[KNKMGT_AGIGKNKADPOFSCYLFINERSL_COLS];
extern uint16 Av_bmax_decrem_cptr_cyl[AV_BMAX_DECREM_CPTR_CYL_COLS];
extern uint16 Av_bmax_retard_cptr_cyl[AV_BMAX_RETARD_CPTR_CYL_COLS];
extern uint16 Knk_adapt_load_max;
extern uint16 Knk_adapt_load_min;
extern uint16 Knk_adapt_n_max;
extern uint16 Knk_adapt_n_min;
extern uint16 Knk_adapt_stable_counter;
extern uint16 Knk_engine_air_load;
extern uint16 Knk_engine_air_load_cyl[KNK_ENGINE_AIR_LOAD_CYL_COLS];
extern uint16 Knk_regime_moteur;
extern uint16 Knk_regime_moteur_cyl[KNK_REGIME_MOTEUR_CYL_COLS];
extern uint16 KNKADPCOR_u16Ext_rAirLdPrev;
extern uint16 KNKADPCOR_u16Regime_moteurPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKADPCOR_vidAdapComputeStrategy(void);
void KNKADPCOR_vidAdaptativeCompute(void);
void KNKADPCOR_vidAdaptativeReading(void);
void KNKADPCOR_vidAdaptDec(void);
void KNKADPCOR_vidAdaptSlewRate(void);
void KNKADPCOR_vidAdaptWriteCond(void);
void KNKADPCOR_vidAntiKnockPrevention(void);
void KNKADPCOR_vidCalcAvBmaxMoyen(void);
void KNKADPCOR_vidConditionalVarReset(void);
void KNKADPCOR_vidCounterReset(void);
void KNKADPCOR_vidCylAdaptation(void);
void KNKADPCOR_vidDecrementation(void);
void KNKADPCOR_vidEngLoadStable(void);
void KNKADPCOR_vidEngSpdEngLoadSaving(void);
void KNKADPCOR_vidEngSpdStable(void);
void KNKADPCOR_vidFiltering(void);
void KNKADPCOR_vidFuelDetection(void);
void KNKADPCOR_vidHighTemperature(void);
void KNKADPCOR_vidIncrementation(void);
void KNKADPCOR_vidInitMaxAdvance(void);
void KNKADPCOR_vidInitOutput(void);
void KNKADPCOR_vidInitRFuelDetection(void);
void KNKADPCOR_vidLowTemperature(void);
void KNKADPCOR_vidMajAvBmax(void);
void KNKADPCOR_vidTreatment(void);
void KNKADPCOR_vidUpdatApplAdaptShift(void);
void KNKADPCOR_vidZoneDetermination(void);


#endif /* KNKADPCOR_L_H */

/*-------------------------------- end of file -------------------------------*/
