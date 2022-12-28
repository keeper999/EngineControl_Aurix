/***************************************************************************
;**
;** FILE NAME      : MISFDET.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDET_H
#define MISFDET_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define INDICATED_TORQUE_3_BKPT_MAP_COLS       ( 7 )
#define MF_CMI_MIN_IDLE_MAP_UACN1_COLS         ( 16 )
#define MF_CMI_MIN_MAP_UACN1_COLS              ( 16 )
#define MF_CMI_NEUT_BKPT_UACN1_COLS            ( 7 )
#define MF_COMB_ALGO_NEUT_MAP_UACN2_LNS       ( 7 )
#define MF_COMB_ALGO_NEUT_MAP_UACN2_COLS       ( 16 )
#define MF_COMB_ALGO_THRESH_MAP_UACN2_LNS     ( 7 )
#define MF_COMB_ALGO_THRESH_MAP_UACN2_COLS     ( 16 )
#define MF_ENG_SPD_NEUT_BKPT_UACN1_COLS        ( 16 )
#define MF_GAIN_THRESH_MAP_UACN1_COLS          ( 16 )
#define MF_GAIN_THRESH_MAP_UT_UACN1_COLS       ( 16 )
#define MF_P_FILT_ALGO_NEUT_MAP_UACN2_LNS     ( 7 )
#define MF_P_FILT_ALGO_NEUT_MAP_UACN2_COLS     ( 16 )
#define MF_P_FILT_ALGO_THRESH_MAP_UACN2_LNS   ( 7 )
#define MF_P_FILT_ALGO_THRESH_MAP_UACN2_COLS   ( 16 )
#define REGIME_MOTEUR_3_BKPT_MAP_COLS          ( 16 )

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

extern const boolean  Flex_bInhDiagMisfAlcEst_C;
extern const boolean  Flex_bInhDiagMisfBlby_C;
extern const boolean  Manu_inh_mf_alg_cond_cps;
extern const boolean  Mf_pfilt_comb_ena_uacb0;
extern const boolean  Misf_bAcvAlgoEgdIdle_C;
extern const boolean  Misf_bAcvAlgoIdle_C;
extern const boolean  Misf_bAcvSIPCond;
extern const uint8  Mf_comb_algo_n_max_uacn0;
extern const uint8  Mf_eng_spd_neut_bkpt_uacn1[MF_ENG_SPD_NEUT_BKPT_UACN1_COLS];
extern const uint8  Mf_gain_thresh_map_uacn1[MF_GAIN_THRESH_MAP_UACN1_COLS];
extern const uint8  Mf_gain_thresh_map_UT_uacn1[MF_GAIN_THRESH_MAP_UT_UACN1_COLS];
extern const uint8  Mf_min_air_temp_uacn0;
extern const uint8  Mf_min_water_temp_uacn0;
extern const uint8  Mf_n_max_algo_cond_uacn0;
extern const uint8  Mf_n_min_algo_cond_uacn0;
extern const uint8  Misf_noTDCAcvDet_C;
extern const uint8  Misf_noTDCIdleAcvDet_C;
extern const uint8  Regime_moteur_3_bkpt_map[REGIME_MOTEUR_3_BKPT_MAP_COLS];
extern const sint16  Mf_cmi_min_hyst_uacn0;
extern const sint16  Mf_cmi_min_idle_hyst_uacn0;
extern const uint16  Flex_tiDiagMisfAlcEst_C;
extern const uint16  Indicated_torque_3_bkpt_map[INDICATED_TORQUE_3_BKPT_MAP_COLS];
extern const uint16  Mf_cmi_min_idle_map_uacn1[MF_CMI_MIN_IDLE_MAP_UACN1_COLS];
extern const uint16  Mf_cmi_min_map_uacn1[MF_CMI_MIN_MAP_UACN1_COLS];
extern const uint16  Mf_cmi_neut_bkpt_uacn1[MF_CMI_NEUT_BKPT_UACN1_COLS];
extern const uint16  Mf_comb_algo_neut_map_uacn2[MF_COMB_ALGO_NEUT_MAP_UACN2_LNS][MF_COMB_ALGO_NEUT_MAP_UACN2_COLS];
extern const uint16  Mf_comb_algo_thresh_map_uacn2[MF_COMB_ALGO_THRESH_MAP_UACN2_LNS][MF_COMB_ALGO_THRESH_MAP_UACN2_COLS];
extern const uint16  Mf_p_filt_algo_neut_map_uacn2[MF_P_FILT_ALGO_NEUT_MAP_UACN2_LNS][MF_P_FILT_ALGO_NEUT_MAP_UACN2_COLS];
extern const uint16  Mf_p_filt_algo_thresh_map_uacn2[MF_P_FILT_ALGO_THRESH_MAP_UACN2_LNS][MF_P_FILT_ALGO_THRESH_MAP_UACN2_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Flex_bEnaDiagMisfAlcEst;
extern boolean Mf_algo_cond_ok_uavb0;
extern boolean Mf_algo_idle_cond_ok;
extern boolean Mf_algo_Norm_cond_ok;
extern boolean Mf_bAcvCondIdle;
extern boolean Mf_bAcvCondIdleRaw;
extern boolean Mf_bAcvCondNorm;
extern boolean Mf_bAcvCondNormRaw;
extern sint16 Mf_comb_algo_trust_uavn0;
extern sint16 Mf_comb_crite_next_uavn0;
extern sint16 Mf_comb_crite_prev_prev_uavn0;
extern sint16 Mf_comb_crite_prev_uavn0;
extern sint16 Mf_comb_crite_uavn0;
extern sint16 Mf_p_filt_algo_trust_uavn0;
extern sint16 Mf_p_filt_crite_next_uavn0;
extern sint16 Mf_p_filt_crite_prev_prev_uavn0;
extern sint16 Mf_p_filt_crite_prev_uavn0;
extern sint16 Mf_p_filt_crite_uavn0;
extern uint16 Mf_comb_algo_thresh_uavn0;
extern uint16 Mf_p_filt_algo_thresh_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfDet(void);
void MISFDET_vidEntryInit(void);


#endif /* MISFDET_H */

/*-------------------------------- end of file -------------------------------*/
