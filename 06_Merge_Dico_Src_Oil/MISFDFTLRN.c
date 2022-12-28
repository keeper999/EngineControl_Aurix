/***************************************************************************
;**
;** FILE NAME      : MISFDFTLRN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFDFTLRN.H"
#include "MISFDFTLRN_L.H"
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
const boolean  Mf_adap_auth_uacn1[MF_ADAP_AUTH_UACN1_COLS] = {0};
const boolean  Mf_adap_inh_corr_precal_uacb0 = 0;
const boolean  Mf_adap_inh_no_rlzd_uacn0 = 0;
const boolean  Mf_adap_manu_inh_auth_uacb0 = 0;
const boolean  Mf_adap_manu_inh_uacb0 = 0;
const boolean  Misf_bRstNoRlzd_C = 0;
const boolean  Table_boite_vitesse_Misf_inh[TABLE_BOITE_VITESSE_MISF_INH_COLS] = {0};
const boolean  Table_boite_vitesse_Misf_UT_inh[TABLE_BOITE_VITESSE_MISF_UT_INH_COLS] = {0};
const sint8  Mf_adap_n_derv_max_uacn0 = 0;
const sint8  Mf_adap_n_derv_min_uacn0 = 0;
const uint8  Mf_adap_Bdc_corr_bkup_gain[MF_ADAP_BDC_CORR_BKUP_GAIN_COLS] = {0};
const uint8  Mf_adap_Bdc_er_dif_gain_ut_uacn = 0;
const uint8  Mf_adap_Bdc_err_dif_gain_uacn0 = 0;
const uint8  Mf_adap_Bdc_err_gain_uacn0 = 0;
const uint8  Mf_adap_Bdc_err_gain_ut_uacn0 = 0;
const uint8  Mf_adap_corr_gain_uacn0 = 0;
const uint8  Mf_adap_corr_precal_n_max_uacb0 = 0;
const uint8  Mf_adap_corr_precal_n_min_uacb0 = 0;
const uint8  Mf_adap_delta_count_min_uacn1[MF_ADAP_DELTA_COUNT_MIN_UACN1_COLS] = {0};
const uint8  Mf_adap_Exp_corr_bkup_gain[MF_ADAP_EXP_CORR_BKUP_GAIN_COLS] = {0};
const uint8  Mf_adap_Exp_er_dif_gain_ut_uacn0 = 0;
const uint8  Mf_adap_Exp_err_dif_gain_uacn0 = 0;
const uint8  Mf_adap_Exp_err_gain_uacn0 = 0;
const uint8  Mf_adap_Exp_err_gain_ut_uacn0 = 0;
const uint8  Mf_adap_lw_corr_bkup_gain_uacn1[MF_ADAP_LW_CORR_BKUP_GAIN_UACN1_COLS] = {0};
const uint8  Mf_adap_lw_err_dif_gain_uacn0 = 0;
const uint8  Mf_adap_lw_err_dif_gain_ut_uacn0 = 0;
const uint8  Mf_adap_lw_err_gain_uacn0 = 0;
const uint8  Mf_adap_lw_err_gain_ut_uacn0 = 0;
const uint8  Mf_adap_lw_nb_mv_calc_uacn0 = 0;
const uint8  Mf_adap_n_bkpt_diff_hth_uacn0 = 0;
const uint8  Mf_adap_n_bkpt_diff_lth_uacn0 = 0;
const uint8  Mf_adap_n_bkpt_uacn1[MF_ADAP_N_BKPT_UACN1_COLS] = {0};
const uint8  Mf_adap_n_max_uacn0 = 0;
const uint8  Mf_adap_n_min_uacn0 = 0;
const uint8  Mf_adap_shrt_nb_mv_calc_uacn0 = 0;
const uint8  Mf_adap_TDC_corr_bkup_gain[MF_ADAP_TDC_CORR_BKUP_GAIN_COLS] = {0};
const uint8  Mf_adap_TDC_er_dif_gain_ut_uacn0 = 0;
const uint8  Mf_adap_TDC_err_dif_gain_uacn0 = 0;
const uint8  Mf_adap_TDC_err_gain_uacn0 = 0;
const uint8  Mf_adap_TDC_err_gain_ut_uacn0 = 0;
const uint8  Mf_adap_win_count_thresh_uavn0 = 0;
const uint8  Misf_noWinSample_Nom_T[MISF_NOWINSAMPLE_NOM_T_COLS] = {0};
const uint8  Misf_noWinSample_Ut_T[MISF_NOWINSAMPLE_UT_T_COLS] = {0};
const uint8  MISFDFTLRN_u8Inhib = 0;
const sint16  Mf_adap_tco_min_uacn0 = 0;
const sint16  Mf_adap_tco_min_ut_uacn0 = 0;
const uint16  Mf_adap_Bdc_corr_dlta_max[MF_ADAP_BDC_CORR_DLTA_MAX_LNS][MF_ADAP_BDC_CORR_DLTA_MAX_COLS] = {0};
const uint16  Mf_adap_Bdc_corr_precal_uacn2[MF_ADAP_BDC_CORR_PRECAL_UACN2_LNS][MF_ADAP_BDC_CORR_PRECAL_UACN2_COLS] = {0};
const uint16  Mf_adap_Bdc_err_dif_hth_uacn1[MF_ADAP_BDC_ERR_DIF_HTH_UACN1_COLS] = {0};
const uint16  Mf_adap_Bdc_err_dif_hth_ut_uacn1[MF_ADAP_BDC_ERR_DIF_HTH_UT_UACN1_COLS] = {0};
const uint16  Mf_adap_Bdc_err_dif_init_uacn0 = 0;
const uint16  Mf_adap_Bdc_err_dif_lth_uacn0 = 0;
const uint16  Mf_adap_Bdc_err_dif_lth_ut_uacn0 = 0;
const uint16  Mf_adap_Bdc_range_max[MF_ADAP_BDC_RANGE_MAX_LNS][MF_ADAP_BDC_RANGE_MAX_COLS] = {0};
const uint16  Mf_adap_Exp_corr_dlta_max[MF_ADAP_EXP_CORR_DLTA_MAX_LNS][MF_ADAP_EXP_CORR_DLTA_MAX_COLS] = {0};
const uint16  Mf_adap_Exp_corr_precal_uacn2[MF_ADAP_EXP_CORR_PRECAL_UACN2_LNS][MF_ADAP_EXP_CORR_PRECAL_UACN2_COLS] = {0};
const uint16  Mf_adap_Exp_err_dif_hth_uacn1[MF_ADAP_EXP_ERR_DIF_HTH_UACN1_COLS] = {0};
const uint16  Mf_adap_Exp_err_dif_hth_ut_uacn1[MF_ADAP_EXP_ERR_DIF_HTH_UT_UACN1_COLS] = {0};
const uint16  Mf_adap_Exp_err_dif_init_uacn0 = 0;
const uint16  Mf_adap_Exp_err_dif_lth_uacn0 = 0;
const uint16  Mf_adap_Exp_err_dif_lth_ut_uacn0 = 0;
const uint16  Mf_adap_Exp_range_max[MF_ADAP_EXP_RANGE_MAX_LNS][MF_ADAP_EXP_RANGE_MAX_COLS] = {0};
const uint16  Mf_adap_lw_corr_dlta_max_uacn1[MF_ADAP_LW_CORR_DLTA_MAX_UACN1_LNS][MF_ADAP_LW_CORR_DLTA_MAX_UACN1_COLS] = {0};
const uint16  Mf_adap_lw_corr_precal_uacn2[MF_ADAP_LW_CORR_PRECAL_UACN2_LNS][MF_ADAP_LW_CORR_PRECAL_UACN2_COLS] = {0};
const uint16  Mf_adap_lw_err_dif_hth_uacn1[MF_ADAP_LW_ERR_DIF_HTH_UACN1_COLS] = {0};
const uint16  Mf_adap_lw_err_dif_hth_ut_uacn1[MF_ADAP_LW_ERR_DIF_HTH_UT_UACN1_COLS] = {0};
const uint16  Mf_adap_lw_err_dif_init_uacn0 = 0;
const uint16  Mf_adap_lw_err_dif_lth_uacn0 = 0;
const uint16  Mf_adap_lw_err_dif_lth_ut_uacn0 = 0;
const uint16  Mf_adap_lw_range_max[MF_ADAP_LW_RANGE_MAX_LNS][MF_ADAP_LW_RANGE_MAX_COLS] = {0};
const uint16  Mf_adap_TDC_corr_dlta_max[MF_ADAP_TDC_CORR_DLTA_MAX_LNS][MF_ADAP_TDC_CORR_DLTA_MAX_COLS] = {0};
const uint16  Mf_adap_TDC_corr_precal_uacn2[MF_ADAP_TDC_CORR_PRECAL_UACN2_LNS][MF_ADAP_TDC_CORR_PRECAL_UACN2_COLS] = {0};
const uint16  Mf_adap_TDC_err_dif_hth_uacn1[MF_ADAP_TDC_ERR_DIF_HTH_UACN1_COLS] = {0};
const uint16  Mf_adap_TDC_err_dif_hth_ut_uacn1[MF_ADAP_TDC_ERR_DIF_HTH_UT_UACN1_COLS] = {0};
const uint16  Mf_adap_TDC_err_dif_init_uacn0 = 0;
const uint16  Mf_adap_TDC_err_dif_lth_uacn0 = 0;
const uint16  Mf_adap_TDC_err_dif_lth_ut_uacn0 = 0;
const uint16  Mf_adap_Tdc_range_max[MF_ADAP_TDC_RANGE_MAX_LNS][MF_ADAP_TDC_RANGE_MAX_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Misf_stDftLrn;
uint8 Misf_stLrnWin;
boolean Mf_adap_auth_uavb0;
boolean Mf_adap_Bdc_cond_ok_uavb0;
boolean Mf_adap_Bdc_cond_ok_uavb1[MF_ADAP_BDC_COND_OK_UAVB1_COLS];
boolean Mf_adap_calc_init_uavb0;
boolean Mf_adap_ena_uavb0;
boolean Mf_adap_Exp_cond_ok_uavb0;
boolean Mf_adap_Exp_cond_ok_uavb1[MF_ADAP_EXP_COND_OK_UAVB1_COLS];
boolean Mf_adap_filt_calc_init_uavb0;
boolean Mf_adap_lw_cond_ok_uavb0;
boolean Mf_adap_lw_cond_ok_uavb1[MF_ADAP_LW_COND_OK_UAVB1_COLS];
boolean Mf_adap_no_rlzd_UT_uavb0;
boolean Mf_adap_rlzd_uavb1[MF_ADAP_RLZD_UAVB1_COLS];
boolean Mf_adap_TDC_cond_ok_uavb0;
boolean Mf_adap_TDC_cond_ok_uavb1[MF_ADAP_TDC_COND_OK_UAVB1_COLS];
boolean Mf_win_1_uavb0;
boolean Misf_bDgoORng_LongWinLrn;
boolean Misf_bDgoORng_LongWinLrnMax;
boolean Misf_bDgoORng_ShrtWinLrn;
boolean Misf_bDgoORng_ShrtWinLrnMax;
boolean Misf_bMonRunORng_LongWinLrn;
boolean Misf_bMonRunORng_LongWinLrnMax;
boolean Misf_bMonRunORng_ShrtWinLrn;
boolean Misf_bMonRunORng_ShrtWinLrnMax;
boolean MISFDFTLRN_bBdcHystOut;
boolean MISFDFTLRN_bExpHystOut;
boolean MISFDFTLRN_bFRMInhWinLrnORngPrev;
boolean MISFDFTLRN_bLwHystOut;
boolean MISFDFTLRN_blwnorlzduavb0Prev;
boolean MISFDFTLRN_blwnorlzdUTuavb0Prev;
boolean MISFDFTLRN_bshrtnorlzduavb0Prev;
boolean MISFDFTLRN_bshrtnorlzdUTuavb0Prv;
boolean MISFDFTLRN_bSrvAcvPlaModPrev;
boolean MISFDFTLRN_bTDCHystOut;
uint32 Misf_tiDlyBdcWin1;
uint32 Misf_tiDlyExpWin1;
uint32 Misf_tiDlyLongWin1;
uint32 Misf_tiDlyTDCWin1;
uint32 MISFDFTLRN_u32tiDlyBdcWinPrev;
uint32 MISFDFTLRN_u32tiDlyExpWinPrev;
uint32 MISFDFTLRN_u32tiDlyLongWinPrev;
uint32 MISFDFTLRN_u32tiDlyTDCWinPrev;
uint8 Mf_adap_bkpt_ind_prev_uavn0;
uint8 Mf_adap_bkpt_ind_uavn0;
uint8 Mf_adap_delta_count_uavn1[MF_ADAP_DELTA_COUNT_UAVN1_COLS];
uint8 Mf_adap_lw_corr_nxt_cnt_i_uavn0;
uint8 Mf_adap_lw_sample_count_uavn1[MF_ADAP_LW_SAMPLE_COUNT_UAVN1_COLS];
uint8 Mf_adap_n_index;
uint8 Mf_adap_shrt_corr_nxt_cnt_i;
uint8 Mf_adap_shrt_sample_count_uavn1[MF_ADAP_SHRT_SAMPLE_COUNT_UAVN1_COLS];
uint8 Misf_noCyl;
uint8 Misf_noCylIg;
uint8 Misf_noWinSample_T[MISF_NOWINSAMPLE_T_COLS];
sint16 Mf_adap_Bdc_corr_precal_uavn0;
sint16 Mf_adap_Bdc_delta_uavn1[MF_ADAP_BDC_DELTA_UAVN1_COLS];
sint16 Mf_adap_Bdc_err_dif_neg_uavn1[MF_ADAP_BDC_ERR_DIF_NEG_UAVN1_COLS];
sint16 Mf_adap_Bdc_err_dif_pos_uavn1[MF_ADAP_BDC_ERR_DIF_POS_UAVN1_COLS];
sint16 Mf_adap_Bdc_err_dif_raw_uavn1[MF_ADAP_BDC_ERR_DIF_RAW_UAVN1_COLS];
sint16 Mf_adap_Bdc_err_filt_uavn1[MF_ADAP_BDC_ERR_FILT_UAVN1_COLS];
sint16 Mf_adap_Bdc_err_mv_i_uavn1[MF_ADAP_BDC_ERR_MV_I_UAVN1_COLS];
sint16 Mf_adap_Exp_corr_precal_uavn0;
sint16 Mf_adap_Exp_delta_uavn1[MF_ADAP_EXP_DELTA_UAVN1_COLS];
sint16 Mf_adap_Exp_err_dif_neg_uavn1[MF_ADAP_EXP_ERR_DIF_NEG_UAVN1_COLS];
sint16 Mf_adap_Exp_err_dif_pos_uavn1[MF_ADAP_EXP_ERR_DIF_POS_UAVN1_COLS];
sint16 Mf_adap_Exp_err_dif_raw_uavn1[MF_ADAP_EXP_ERR_DIF_RAW_UAVN1_COLS];
sint16 Mf_adap_Exp_err_filt_uavn1[MF_ADAP_EXP_ERR_FILT_UAVN1_COLS];
sint16 Mf_adap_Exp_err_mv_i_uavn1[MF_ADAP_EXP_ERR_MV_I_UAVN1_COLS];
sint16 Mf_adap_lw_corr_precal_uavn0;
sint16 Mf_adap_lw_delta_uavn1[MF_ADAP_LW_DELTA_UAVN1_COLS];
sint16 Mf_adap_lw_err_dif_neg_uavn1[MF_ADAP_LW_ERR_DIF_NEG_UAVN1_COLS];
sint16 Mf_adap_lw_err_dif_pos_uavn1[MF_ADAP_LW_ERR_DIF_POS_UAVN1_COLS];
sint16 Mf_adap_lw_err_dif_raw_uavn1[MF_ADAP_LW_ERR_DIF_RAW_UAVN1_COLS];
sint16 Mf_adap_lw_err_mv_i_uavn1[MF_ADAP_LW_ERR_MV_I_UAVN1_COLS];
sint16 Mf_adap_TDC_corr_precal_uavn0;
sint16 Mf_adap_TDC_delta_uavn1[MF_ADAP_TDC_DELTA_UAVN1_COLS];
sint16 Mf_adap_TDC_err_dif_neg_uavn1[MF_ADAP_TDC_ERR_DIF_NEG_UAVN1_COLS];
sint16 Mf_adap_TDC_err_dif_pos_uavn1[MF_ADAP_TDC_ERR_DIF_POS_UAVN1_COLS];
sint16 Mf_adap_TDC_err_dif_raw_uavn1[MF_ADAP_TDC_ERR_DIF_RAW_UAVN1_COLS];
sint16 Mf_adap_TDC_err_filt_uavn1[MF_ADAP_TDC_ERR_FILT_UAVN1_COLS];
sint16 Mf_adap_TDC_err_mv_i_uavn1[MF_ADAP_TDC_ERR_MV_I_UAVN1_COLS];
sint16 Misf_BdcWin1Delta;
sint16 Misf_BdcWinErrRaw[MISF_BDCWINERRRAW_COLS];
sint16 Misf_ExpWin1Delta;
sint16 Misf_ExpWinErrRaw[MISF_EXPWINERRRAW_COLS];
sint16 Misf_LongWin1Delta;
sint16 Misf_TDCWin1Delta;
sint16 Misf_TDCWinErrRaw[MISF_TDCWINERRRAW_COLS];
uint16 Mf_adap_Bdc_err_dif_filt_uavn1[MF_ADAP_BDC_ERR_DIF_FILT_UAVN1_COLS];
uint16 Mf_adap_Exp_err_dif_filt_uavn1[MF_ADAP_EXP_ERR_DIF_FILT_UAVN1_COLS];
uint16 Mf_adap_lw_err_dif_filt_uavn1[MF_ADAP_LW_ERR_DIF_FILT_UAVN1_COLS];
uint16 Mf_adap_TDC_err_dif_filt_uavn1[MF_ADAP_TDC_ERR_DIF_FILT_UAVN1_COLS];
uint16 Misf_Delta;
sint32 Mf_adap_lw_err_filt_uavn1[MF_ADAP_LW_ERR_FILT_UAVN1_COLS];
sint32 Misf_LongWinErrRaw[MISF_LONGWINERRRAW_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

