/***************************************************************************
;**
;** FILE NAME      : MISFDET.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFDET.H"
#include "MISFDET_L.H"
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
const boolean  Flex_bInhDiagMisfAlcEst_C = 0;
const boolean  Flex_bInhDiagMisfBlby_C = 0;
const boolean  Manu_inh_mf_alg_cond_cps = 0;
const boolean  Mf_pfilt_comb_ena_uacb0 = 0;
const boolean  Misf_bAcvAlgoEgdIdle_C = 0;
const boolean  Misf_bAcvAlgoIdle_C = 0;
const boolean  Misf_bAcvSIPCond = 0;
const uint8  Mf_comb_algo_n_max_uacn0 = 0;
const uint8  Mf_eng_spd_neut_bkpt_uacn1[MF_ENG_SPD_NEUT_BKPT_UACN1_COLS] = {0};
const uint8  Mf_gain_thresh_map_uacn1[MF_GAIN_THRESH_MAP_UACN1_COLS] = {0};
const uint8  Mf_gain_thresh_map_UT_uacn1[MF_GAIN_THRESH_MAP_UT_UACN1_COLS] = {0};
const uint8  Mf_min_air_temp_uacn0 = 0;
const uint8  Mf_min_water_temp_uacn0 = 0;
const uint8  Mf_n_max_algo_cond_uacn0 = 0;
const uint8  Mf_n_min_algo_cond_uacn0 = 0;
const uint8  Misf_noTDCAcvDet_C = 0;
const uint8  Misf_noTDCIdleAcvDet_C = 0;
const uint8  MISFDET_u8Inhib = 0;
const uint8  Regime_moteur_3_bkpt_map[REGIME_MOTEUR_3_BKPT_MAP_COLS] = {0};
const sint16  Mf_cmi_min_hyst_uacn0 = 0;
const sint16  Mf_cmi_min_idle_hyst_uacn0 = 0;
const uint16  Flex_tiDiagMisfAlcEst_C = 0;
const uint16  Indicated_torque_3_bkpt_map[INDICATED_TORQUE_3_BKPT_MAP_COLS] = {0};
const uint16  Mf_cmi_min_idle_map_uacn1[MF_CMI_MIN_IDLE_MAP_UACN1_COLS] = {0};
const uint16  Mf_cmi_min_map_uacn1[MF_CMI_MIN_MAP_UACN1_COLS] = {0};
const uint16  Mf_cmi_neut_bkpt_uacn1[MF_CMI_NEUT_BKPT_UACN1_COLS] = {0};
const uint16  Mf_comb_algo_neut_map_uacn2[MF_COMB_ALGO_NEUT_MAP_UACN2_LNS][MF_COMB_ALGO_NEUT_MAP_UACN2_COLS] = {0};
const uint16  Mf_comb_algo_thresh_map_uacn2[MF_COMB_ALGO_THRESH_MAP_UACN2_LNS][MF_COMB_ALGO_THRESH_MAP_UACN2_COLS] = {0};
const uint16  Mf_p_filt_algo_neut_map_uacn2[MF_P_FILT_ALGO_NEUT_MAP_UACN2_LNS][MF_P_FILT_ALGO_NEUT_MAP_UACN2_COLS] = {0};
const uint16  Mf_p_filt_algo_thresh_map_uacn2[MF_P_FILT_ALGO_THRESH_MAP_UACN2_LNS][MF_P_FILT_ALGO_THRESH_MAP_UACN2_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Flex_bEnaDiagMisfAlcEst;
boolean Mf_algo_cond_ok_temp;
boolean Mf_algo_cond_ok_uavb0;
boolean Mf_algo_idle_cond_ok;
boolean Mf_algo_Norm_cond_ok;
boolean Mf_bAcvCondGlobal;
boolean Mf_bAcvCondIdle;
boolean Mf_bAcvCondIdleRaw;
boolean Mf_bAcvCondNorm;
boolean Mf_bAcvCondNormRaw;
boolean MISFDET_bAcvCondIdlePrev;
boolean MISFDET_bAcvCondNormPrev;
boolean MISFDET_bOutMinHyst;
boolean MISFDET_bOutMinIdleHyst;
boolean MISFDET_bTimeOut;
boolean MISFDET_bTimeOut1;
uint32 Misf_tiDlyLongWinAdpPrev;
uint8 MISFDET_u8CounternoTDCAcv;
uint8 MISFDET_u8CounternoTDCIdleAcv;
sint16 Mf_comb_algo_out_uavn0;
sint16 Mf_comb_algo_trust_uavn0;
sint16 Mf_comb_crite_next_uavn0;
sint16 Mf_comb_crite_prev_prev_uavn0;
sint16 Mf_comb_crite_prev_uavn0;
sint16 Mf_comb_crite_uavn0;
sint16 Mf_p_filt_algo_out_uavn0;
sint16 Mf_p_filt_algo_trust_uavn0;
sint16 Mf_p_filt_crite_next_uavn0;
sint16 Mf_p_filt_crite_prev_prev_uavn0;
sint16 Mf_p_filt_crite_prev_uavn0;
sint16 Mf_p_filt_crite_uavn0;
uint16 Mf_comb_algo_neut;
uint16 Mf_comb_algo_thresh;
uint16 Mf_comb_algo_thresh_uavn0;
uint16 Mf_duree_demi_tour_n;
uint16 Mf_duree_demi_tour_n_less_1;
uint16 Mf_duree_demi_tour_n_less_2;
uint16 Mf_duree_demi_tour_n_less_3;
uint16 Mf_p_filt_algo_neut;
uint16 Mf_p_filt_algo_thresh;
uint16 Mf_p_filt_algo_thresh_uavn0;
uint16 Misf_HalfRevSum;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

