/***************************************************************************
;**
;** FILE NAME      : MISFFAICTR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFFAICTR.H"
#include "MISFFAICTR_L.H"
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
const boolean  Misf_bTypRoughnsRoadSel_C = 0;
const uint8  Mf_cat_dam_sum_cyl_cutoff_uacn0 = 0;
const uint8  Mf_det_cat_dam_n_max_uacn0 = 0;
const uint8  Mf_det_emiss_n_max_uacn0 = 0;
const uint8  Misf_noAuthCutDmgCat3Cyl_C = 0;
const uint8  Misf_noAuthCutDmgCat4Cyl_C = 0;
const uint8  MISFFAICTR_u8Inhib = 0;
const uint8  Table_cyl_phys_misfire_detected[TABLE_CYL_PHYS_MISFIRE_DETECTED_COLS] = {0};
const uint16  Flev_low_fuel_level_tempo = 0;
const uint16  Mf_AirInjDistThd_C = 0;
const uint16  Mf_cat_dam_wght_map_uacn2[MF_CAT_DAM_WGHT_MAP_UACN2_LNS][MF_CAT_DAM_WGHT_MAP_UACN2_COLS] = {0};
const uint16  Mf_cat_dam_wght_old_map_uacn2[MF_CAT_DAM_WGHT_OLD_MAP_UACN2_LNS][MF_CAT_DAM_WGHT_OLD_MAP_UACN2_COLS] = {0};
const uint16  Mf_cat_dam_wght_sum_thd_tq_lim = 0;
const uint16  Mf_cat_dam_wght_sum_thresh = 0;
const uint16  Mf_cat_dam_wght_thresh_uacn0 = 0;
const uint16  Mf_emiss_min_thresh_uacn0 = 0;
const uint16  Mf_emiss_thresh_uacn0 = 0;
const uint16  Mf_rough_road_cat_thresh_uacn0 = 0;
const uint16  Mf_rough_road_emiss_thresh_uacn0 = 0;
const uint16  Mf_sum_min_thresh_tq_lim_uacn0 = 0;
const uint16  Mf_sum_min_thresh_uacn0 = 0;
const uint16  Misf_pFuRailMinLowFuLvl_C = 0;
const uint16  Misf_TotalMisf_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Coup_decel_progr_inj_a_catdam;
boolean Coup_decel_progr_inj_a_emiss;
boolean Coup_decel_progr_inj_b_catdam;
boolean Coup_decel_progr_inj_b_emiss;
boolean Coup_decel_progr_inj_c_catdam;
boolean Coup_decel_progr_inj_c_emiss;
boolean Coup_decel_progr_inj_d_catdam;
boolean Coup_decel_progr_inj_d_emiss;
boolean Flev_low_fuel_level_cat_dam;
boolean Mf_1_mf_cat_dam_uavb0;
boolean Mf_1_mf_emiss_uavb0;
boolean Mf_2_mf_cat_dam_uavb0;
boolean Mf_2_mf_emiss_uavb0;
boolean Mf_bInhTotDef;
boolean Mf_cat_dam_3cyl1_uavb0;
boolean Mf_cat_dam_3cyl2_uavb0;
boolean Mf_cat_dam_3cyl3_uavb0;
boolean Mf_cat_dam_4cyl1_uavb0;
boolean Mf_cat_dam_4cyl2_uavb0;
boolean Mf_cat_dam_4cyl3_uavb0;
boolean Mf_cat_dam_4cyl4_uavb0;
boolean Mf_cat_dam_det_uavb0;
boolean Mf_cat_dam_glob_def_uavb0;
boolean Mf_cat_dam_horizon_uavb0;
boolean Mf_cat_dam_test_achi_uavb0;
boolean Mf_cat_dam_wgth_sum_diag_ena;
boolean Mf_emiss_det_fail_uavb0;
boolean Mf_emiss_horizon_uavb0;
boolean Mf_emiss_test_achi_uavb0;
boolean Misf_bAcvDetDmgCat;
boolean Misf_bAcvLowFuLvlCatDam;
boolean Misf_bDgoORngDmgCat1;
boolean Misf_bDgoORngDmgCat2;
boolean Misf_bDgoORngDmgCat3;
boolean Misf_bDgoORngDmgCat4;
boolean Misf_bDgoORngDmgCatMDAll;
boolean Misf_bDgoORngMisfEmi1;
boolean Misf_bDgoORngMisfEmi2;
boolean Misf_bDgoORngMisfEmi3;
boolean Misf_bDgoORngMisfEmi4;
boolean Misf_bDgoORngMisfEmiAll;
boolean Misf_bInhDetNoMisf;
boolean Misf_bMonRunORngDmgCat1;
boolean Misf_bMonRunORngDmgCat2;
boolean Misf_bMonRunORngDmgCat3;
boolean Misf_bMonRunORngDmgCat4;
boolean Misf_bMonRunORngDmgCatMDAll;
boolean Misf_bMonRunORngMisfEmi1;
boolean Misf_bMonRunORngMisfEmi2;
boolean Misf_bMonRunORngMisfEmi3;
boolean Misf_bMonRunORngMisfEmi4;
boolean Misf_bMonRunORngMisfEmiAll;
boolean Misf_bMonWaitORngDmgCatDTC1;
boolean Misf_bMonWaitORngDmgCatDTC2;
boolean Misf_bMonWaitORngDmgCatDTC3;
boolean Misf_bMonWaitORngDmgCatDTC4;
boolean Misf_bMonWaitORngDmgCatDTCAll;
boolean Misf_Defaut_TotalMisf_perCy1;
boolean Misf_Defaut_TotalMisf_perCy2;
boolean Misf_Defaut_TotalMisf_perCy3;
boolean Misf_Defaut_TotalMisf_perCy4;
boolean MISFFAICTR_bEmissHorizonPrev;
boolean MISFFAICTR_bFuelLevelTimeOut;
boolean MISFFAICTR_bLowFuelLevelPrev;
boolean MISFFAICTR_bMfCatDamHorizonPrev;
boolean MISFFAICTR_bMfMisfDetectedPrev;
boolean MISFFAICTR_bMisfAcvDetDmgCatPrev;
boolean MonMisf_bAcvMonMisfOBD;
boolean MonMisf_bClcMisfOBD;
uint8 Coup_decel_progr_inj_cat_dam;
uint8 Coup_decel_progr_inj_emiss;
uint8 Coupure_decel_progr_inj_prev;
uint8 Mf_cat_dam_cyl_uavb0[MF_CAT_DAM_CYL_UAVB0_COLS];
uint8 Mf_cat_dam_mf_rate_uavn0;
uint8 Mf_cat_dam_nb_cyl_max_uavn1;
uint8 Mf_cat_dam_nb_cyl_max_uavn2;
uint8 Mf_cat_dam_nb_cyl_max_uavn3;
uint8 Mf_cat_dam_nb_cyl_max_uavn4;
uint8 Mf_cyl_cat_dam_uavb0;
uint8 Mf_cyl_emis_uavb0;
uint8 Mf_emiss_cyl_uavb1[MF_EMISS_CYL_UAVB1_COLS];
uint8 Mf_emiss_mf_rate_uavn0;
uint8 Mf_rough_road_sum_2mf_cat_uavn0;
uint8 Mf_rough_road_sum_2mf_emi_uavn0;
uint8 MISFFAICTR_u8CoupDecProgrInjprev;
uint8 MISFFAICTR_u8MfCylCatDamUavbprev;
uint8 MISFFAICTR_u8MfCylEmisUavb0prev;
uint8 MISFFAICTR_u8MfRoughCatUavn0;
uint8 MISFFAICTR_u8MfRoughEmiUavn0;
uint16 Flev_low_fuel_level_count;
uint16 Mf_cat_dam_4cyl1_int;
uint16 Mf_cat_dam_4cyl2_int;
uint16 Mf_cat_dam_4cyl3_int;
uint16 Mf_cat_dam_4cyl4_int;
uint16 Mf_cat_dam_count_uavn0;
uint16 Mf_cat_dam_no_cyl_max1_uavn;
uint16 Mf_cat_dam_no_cyl_max2_uavn;
uint16 Mf_cat_dam_sum_real_uavn0;
uint16 Mf_cat_dam_sum1_uavn0;
uint16 Mf_cat_dam_sum2_uavn0;
uint16 Mf_cat_dam_sum3_uavn0;
uint16 Mf_cat_dam_sum4_uavn0;
uint16 Mf_cat_dam_wght_count_1_uavn0;
uint16 Mf_cat_dam_wght_count_2_uavn0;
uint16 Mf_cat_dam_wght_count_3_uavn0;
uint16 Mf_cat_dam_wght_count_4_uavn0;
uint16 Mf_cat_dam_wght_count_cyl_uavn1[MF_CAT_DAM_WGHT_COUNT_CYL_UAVN1_COLS];
uint16 Mf_cat_dam_wght_count_max_uavn;
uint16 Mf_cat_dam_wght_count_max2_uavn;
uint16 Mf_cat_dam_wght_count_real_red[MF_CAT_DAM_WGHT_COUNT_REAL_RED_COLS];
uint16 Mf_cat_dam_wght_count_real_uavn1[MF_CAT_DAM_WGHT_COUNT_REAL_UAVN1_COLS];
uint16 Mf_cat_dam_wgth_sum_uavn0;
uint16 Mf_emiss_count_1_uavn0;
uint16 Mf_emiss_count_2_uavn0;
uint16 Mf_emiss_count_3_uavn0;
uint16 Mf_emiss_count_4_uavn0;
uint16 Mf_emiss_count_cyl_uavn1[MF_EMISS_COUNT_CYL_UAVN1_COLS];
uint16 Mf_emiss_count_real_uavn1[MF_EMISS_COUNT_REAL_UAVN1_COLS];
uint16 Mf_emiss_count_uavn0;
uint16 Mf_emiss_sum_uavn0;
uint16 Mf_rough_road_cat_sum_uavn0;
uint16 Mf_rough_road_emiss_sum_uavn0;
uint16 MonMisf_rMisfOBD;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

