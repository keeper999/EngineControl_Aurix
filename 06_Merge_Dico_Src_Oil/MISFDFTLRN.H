/***************************************************************************
;**
;** FILE NAME      : MISFDFTLRN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDFTLRN_H
#define MISFDFTLRN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_ADAP_AUTH_UACN1_COLS                ( 9 )
#define MF_ADAP_BDC_CORR_BKUP_GAIN_COLS        ( 9 )
#define MF_ADAP_BDC_CORR_DLTA_MAX_LNS         ( 4 )
#define MF_ADAP_BDC_CORR_DLTA_MAX_COLS         ( 9 )
#define MF_ADAP_BDC_CORR_PRECAL_UACN2_LNS     ( 4 )
#define MF_ADAP_BDC_CORR_PRECAL_UACN2_COLS     ( 9 )
#define MF_ADAP_BDC_ERR_DIF_HTH_UACN1_COLS     ( 9 )
#define MF_ADAP_BDC_ERR_DIF_HTH_UT_UACN1_COLS  ( 9 )
#define MF_ADAP_BDC_RANGE_MAX_LNS             ( 4 )
#define MF_ADAP_BDC_RANGE_MAX_COLS             ( 9 )
#define MF_ADAP_DELTA_COUNT_MIN_UACN1_COLS     ( 4 )
#define MF_ADAP_EXP_CORR_BKUP_GAIN_COLS        ( 9 )
#define MF_ADAP_EXP_CORR_DLTA_MAX_LNS         ( 4 )
#define MF_ADAP_EXP_CORR_DLTA_MAX_COLS         ( 9 )
#define MF_ADAP_EXP_CORR_PRECAL_UACN2_LNS     ( 4 )
#define MF_ADAP_EXP_CORR_PRECAL_UACN2_COLS     ( 9 )
#define MF_ADAP_EXP_ERR_DIF_HTH_UACN1_COLS     ( 9 )
#define MF_ADAP_EXP_ERR_DIF_HTH_UT_UACN1_COLS  ( 9 )
#define MF_ADAP_EXP_RANGE_MAX_LNS             ( 4 )
#define MF_ADAP_EXP_RANGE_MAX_COLS             ( 9 )
#define MF_ADAP_LW_CORR_BKUP_GAIN_UACN1_COLS   ( 9 )
#define MF_ADAP_LW_CORR_DLTA_MAX_UACN1_LNS    ( 4 )
#define MF_ADAP_LW_CORR_DLTA_MAX_UACN1_COLS    ( 9 )
#define MF_ADAP_LW_CORR_PRECAL_UACN2_LNS      ( 4 )
#define MF_ADAP_LW_CORR_PRECAL_UACN2_COLS      ( 9 )
#define MF_ADAP_LW_ERR_DIF_HTH_UACN1_COLS      ( 9 )
#define MF_ADAP_LW_ERR_DIF_HTH_UT_UACN1_COLS   ( 9 )
#define MF_ADAP_LW_RANGE_MAX_LNS              ( 4 )
#define MF_ADAP_LW_RANGE_MAX_COLS              ( 9 )
#define MF_ADAP_N_BKPT_UACN1_COLS              ( 9 )
#define MF_ADAP_RLZD_UAVB1_COLS                ( 9 )
#define MF_ADAP_TDC_CORR_BKUP_GAIN_COLS        ( 9 )
#define MF_ADAP_TDC_CORR_DLTA_MAX_LNS         ( 4 )
#define MF_ADAP_TDC_CORR_DLTA_MAX_COLS         ( 9 )
#define MF_ADAP_TDC_CORR_PRECAL_UACN2_LNS     ( 4 )
#define MF_ADAP_TDC_CORR_PRECAL_UACN2_COLS     ( 9 )
#define MF_ADAP_TDC_ERR_DIF_HTH_UACN1_COLS     ( 9 )
#define MF_ADAP_TDC_ERR_DIF_HTH_UT_UACN1_COLS  ( 9 )
#define MF_ADAP_TDC_RANGE_MAX_LNS             ( 4 )
#define MF_ADAP_TDC_RANGE_MAX_COLS             ( 9 )
#define MISF_NOWINSAMPLE_NOM_T_COLS            ( 4 )
#define MISF_NOWINSAMPLE_UT_T_COLS             ( 4 )
#define TABLE_BOITE_VITESSE_MISF_INH_COLS      ( 7 )
#define TABLE_BOITE_VITESSE_MISF_UT_INH_COLS   ( 7 )

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

extern const boolean  Mf_adap_auth_uacn1[MF_ADAP_AUTH_UACN1_COLS];
extern const boolean  Mf_adap_inh_corr_precal_uacb0;
extern const boolean  Mf_adap_inh_no_rlzd_uacn0;
extern const boolean  Mf_adap_manu_inh_auth_uacb0;
extern const boolean  Mf_adap_manu_inh_uacb0;
extern const boolean  Misf_bRstNoRlzd_C;
extern const boolean  Table_boite_vitesse_Misf_inh[TABLE_BOITE_VITESSE_MISF_INH_COLS];
extern const boolean  Table_boite_vitesse_Misf_UT_inh[TABLE_BOITE_VITESSE_MISF_UT_INH_COLS];
extern const sint8  Mf_adap_n_derv_max_uacn0;
extern const sint8  Mf_adap_n_derv_min_uacn0;
extern const uint8  Mf_adap_Bdc_corr_bkup_gain[MF_ADAP_BDC_CORR_BKUP_GAIN_COLS];
extern const uint8  Mf_adap_Bdc_er_dif_gain_ut_uacn;
extern const uint8  Mf_adap_Bdc_err_dif_gain_uacn0;
extern const uint8  Mf_adap_Bdc_err_gain_uacn0;
extern const uint8  Mf_adap_Bdc_err_gain_ut_uacn0;
extern const uint8  Mf_adap_corr_gain_uacn0;
extern const uint8  Mf_adap_corr_precal_n_max_uacb0;
extern const uint8  Mf_adap_corr_precal_n_min_uacb0;
extern const uint8  Mf_adap_delta_count_min_uacn1[MF_ADAP_DELTA_COUNT_MIN_UACN1_COLS];
extern const uint8  Mf_adap_Exp_corr_bkup_gain[MF_ADAP_EXP_CORR_BKUP_GAIN_COLS];
extern const uint8  Mf_adap_Exp_er_dif_gain_ut_uacn0;
extern const uint8  Mf_adap_Exp_err_dif_gain_uacn0;
extern const uint8  Mf_adap_Exp_err_gain_uacn0;
extern const uint8  Mf_adap_Exp_err_gain_ut_uacn0;
extern const uint8  Mf_adap_lw_corr_bkup_gain_uacn1[MF_ADAP_LW_CORR_BKUP_GAIN_UACN1_COLS];
extern const uint8  Mf_adap_lw_err_dif_gain_uacn0;
extern const uint8  Mf_adap_lw_err_dif_gain_ut_uacn0;
extern const uint8  Mf_adap_lw_err_gain_uacn0;
extern const uint8  Mf_adap_lw_err_gain_ut_uacn0;
extern const uint8  Mf_adap_lw_nb_mv_calc_uacn0;
extern const uint8  Mf_adap_n_bkpt_diff_hth_uacn0;
extern const uint8  Mf_adap_n_bkpt_diff_lth_uacn0;
extern const uint8  Mf_adap_n_bkpt_uacn1[MF_ADAP_N_BKPT_UACN1_COLS];
extern const uint8  Mf_adap_n_max_uacn0;
extern const uint8  Mf_adap_n_min_uacn0;
extern const uint8  Mf_adap_shrt_nb_mv_calc_uacn0;
extern const uint8  Mf_adap_TDC_corr_bkup_gain[MF_ADAP_TDC_CORR_BKUP_GAIN_COLS];
extern const uint8  Mf_adap_TDC_er_dif_gain_ut_uacn0;
extern const uint8  Mf_adap_TDC_err_dif_gain_uacn0;
extern const uint8  Mf_adap_TDC_err_gain_uacn0;
extern const uint8  Mf_adap_TDC_err_gain_ut_uacn0;
extern const uint8  Mf_adap_win_count_thresh_uavn0;
extern const uint8  Misf_noWinSample_Nom_T[MISF_NOWINSAMPLE_NOM_T_COLS];
extern const uint8  Misf_noWinSample_Ut_T[MISF_NOWINSAMPLE_UT_T_COLS];
extern const sint16  Mf_adap_tco_min_uacn0;
extern const sint16  Mf_adap_tco_min_ut_uacn0;
extern const uint16  Mf_adap_Bdc_corr_dlta_max[MF_ADAP_BDC_CORR_DLTA_MAX_LNS][MF_ADAP_BDC_CORR_DLTA_MAX_COLS];
extern const uint16  Mf_adap_Bdc_corr_precal_uacn2[MF_ADAP_BDC_CORR_PRECAL_UACN2_LNS][MF_ADAP_BDC_CORR_PRECAL_UACN2_COLS];
extern const uint16  Mf_adap_Bdc_err_dif_hth_uacn1[MF_ADAP_BDC_ERR_DIF_HTH_UACN1_COLS];
extern const uint16  Mf_adap_Bdc_err_dif_hth_ut_uacn1[MF_ADAP_BDC_ERR_DIF_HTH_UT_UACN1_COLS];
extern const uint16  Mf_adap_Bdc_err_dif_init_uacn0;
extern const uint16  Mf_adap_Bdc_err_dif_lth_uacn0;
extern const uint16  Mf_adap_Bdc_err_dif_lth_ut_uacn0;
extern const uint16  Mf_adap_Bdc_range_max[MF_ADAP_BDC_RANGE_MAX_LNS][MF_ADAP_BDC_RANGE_MAX_COLS];
extern const uint16  Mf_adap_Exp_corr_dlta_max[MF_ADAP_EXP_CORR_DLTA_MAX_LNS][MF_ADAP_EXP_CORR_DLTA_MAX_COLS];
extern const uint16  Mf_adap_Exp_corr_precal_uacn2[MF_ADAP_EXP_CORR_PRECAL_UACN2_LNS][MF_ADAP_EXP_CORR_PRECAL_UACN2_COLS];
extern const uint16  Mf_adap_Exp_err_dif_hth_uacn1[MF_ADAP_EXP_ERR_DIF_HTH_UACN1_COLS];
extern const uint16  Mf_adap_Exp_err_dif_hth_ut_uacn1[MF_ADAP_EXP_ERR_DIF_HTH_UT_UACN1_COLS];
extern const uint16  Mf_adap_Exp_err_dif_init_uacn0;
extern const uint16  Mf_adap_Exp_err_dif_lth_uacn0;
extern const uint16  Mf_adap_Exp_err_dif_lth_ut_uacn0;
extern const uint16  Mf_adap_Exp_range_max[MF_ADAP_EXP_RANGE_MAX_LNS][MF_ADAP_EXP_RANGE_MAX_COLS];
extern const uint16  Mf_adap_lw_corr_dlta_max_uacn1[MF_ADAP_LW_CORR_DLTA_MAX_UACN1_LNS][MF_ADAP_LW_CORR_DLTA_MAX_UACN1_COLS];
extern const uint16  Mf_adap_lw_corr_precal_uacn2[MF_ADAP_LW_CORR_PRECAL_UACN2_LNS][MF_ADAP_LW_CORR_PRECAL_UACN2_COLS];
extern const uint16  Mf_adap_lw_err_dif_hth_uacn1[MF_ADAP_LW_ERR_DIF_HTH_UACN1_COLS];
extern const uint16  Mf_adap_lw_err_dif_hth_ut_uacn1[MF_ADAP_LW_ERR_DIF_HTH_UT_UACN1_COLS];
extern const uint16  Mf_adap_lw_err_dif_init_uacn0;
extern const uint16  Mf_adap_lw_err_dif_lth_uacn0;
extern const uint16  Mf_adap_lw_err_dif_lth_ut_uacn0;
extern const uint16  Mf_adap_lw_range_max[MF_ADAP_LW_RANGE_MAX_LNS][MF_ADAP_LW_RANGE_MAX_COLS];
extern const uint16  Mf_adap_TDC_corr_dlta_max[MF_ADAP_TDC_CORR_DLTA_MAX_LNS][MF_ADAP_TDC_CORR_DLTA_MAX_COLS];
extern const uint16  Mf_adap_TDC_corr_precal_uacn2[MF_ADAP_TDC_CORR_PRECAL_UACN2_LNS][MF_ADAP_TDC_CORR_PRECAL_UACN2_COLS];
extern const uint16  Mf_adap_TDC_err_dif_hth_uacn1[MF_ADAP_TDC_ERR_DIF_HTH_UACN1_COLS];
extern const uint16  Mf_adap_TDC_err_dif_hth_ut_uacn1[MF_ADAP_TDC_ERR_DIF_HTH_UT_UACN1_COLS];
extern const uint16  Mf_adap_TDC_err_dif_init_uacn0;
extern const uint16  Mf_adap_TDC_err_dif_lth_uacn0;
extern const uint16  Mf_adap_TDC_err_dif_lth_ut_uacn0;
extern const uint16  Mf_adap_Tdc_range_max[MF_ADAP_TDC_RANGE_MAX_LNS][MF_ADAP_TDC_RANGE_MAX_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Mf_adap_no_rlzd_UT_uavb0;
extern boolean Mf_adap_rlzd_uavb1[MF_ADAP_RLZD_UAVB1_COLS];
extern boolean Mf_win_1_uavb0;
extern uint8 Mf_adap_bkpt_ind_uavn0;
extern uint8 Misf_noCyl;
extern uint8 Misf_noCylIg;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfDftLrn(void);
void Misf_EveRst_MisfDftLrn(void);
void Misf_EveRstLrn_MisfDftLrn(void);
void Misf_SdlSlow_MisfDftLrn(void);


#endif /* MISFDFTLRN_H */

/*-------------------------------- end of file -------------------------------*/
