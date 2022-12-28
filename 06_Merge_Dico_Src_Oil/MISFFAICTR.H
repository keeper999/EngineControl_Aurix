/***************************************************************************
;**
;** FILE NAME      : MISFFAICTR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFFAICTR_H
#define MISFFAICTR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENGINE_CYCLE_IN_CAT_DAM_SAMPLE_L  100
#define ENGINE_CYCLE_IN_EMISS_SAMPLE_L    500
#define MF_CAT_DAM_WGHT_MAP_UACN2_LNS         ( 7 )
#define MF_CAT_DAM_WGHT_MAP_UACN2_COLS         ( 16 )
#define MF_CAT_DAM_WGHT_OLD_MAP_UACN2_LNS     ( 7 )
#define MF_CAT_DAM_WGHT_OLD_MAP_UACN2_COLS     ( 16 )
#define MISFFAICTR_u8CYL_LENGTH           4
#define TABLE_CYL_PHYS_MISFIRE_DETECTED_COLS   ( 6 )

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

extern const boolean  Misf_bTypRoughnsRoadSel_C;
extern const uint8  Mf_cat_dam_sum_cyl_cutoff_uacn0;
extern const uint8  Mf_det_cat_dam_n_max_uacn0;
extern const uint8  Mf_det_emiss_n_max_uacn0;
extern const uint8  Misf_noAuthCutDmgCat3Cyl_C;
extern const uint8  Misf_noAuthCutDmgCat4Cyl_C;
extern const uint8  Table_cyl_phys_misfire_detected[TABLE_CYL_PHYS_MISFIRE_DETECTED_COLS];
extern const uint16  Flev_low_fuel_level_tempo;
extern const uint16  Mf_AirInjDistThd_C;
extern const uint16  Mf_cat_dam_wght_map_uacn2[MF_CAT_DAM_WGHT_MAP_UACN2_LNS][MF_CAT_DAM_WGHT_MAP_UACN2_COLS];
extern const uint16  Mf_cat_dam_wght_old_map_uacn2[MF_CAT_DAM_WGHT_OLD_MAP_UACN2_LNS][MF_CAT_DAM_WGHT_OLD_MAP_UACN2_COLS];
extern const uint16  Mf_cat_dam_wght_sum_thd_tq_lim;
extern const uint16  Mf_cat_dam_wght_sum_thresh;
extern const uint16  Mf_cat_dam_wght_thresh_uacn0;
extern const uint16  Mf_emiss_min_thresh_uacn0;
extern const uint16  Mf_emiss_thresh_uacn0;
extern const uint16  Mf_rough_road_cat_thresh_uacn0;
extern const uint16  Mf_rough_road_emiss_thresh_uacn0;
extern const uint16  Mf_sum_min_thresh_tq_lim_uacn0;
extern const uint16  Mf_sum_min_thresh_uacn0;
extern const uint16  Misf_pFuRailMinLowFuLvl_C;
extern const uint16  Misf_TotalMisf_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Mf_cat_dam_det_uavb0;
extern boolean Mf_cat_dam_horizon_uavb0;
extern boolean Mf_cat_dam_test_achi_uavb0;
extern boolean Mf_emiss_det_fail_uavb0;
extern boolean Mf_emiss_horizon_uavb0;
extern boolean Mf_emiss_test_achi_uavb0;
extern boolean MonMisf_bAcvMonMisfOBD;
extern boolean MonMisf_bClcMisfOBD;
extern uint8 Mf_cat_dam_mf_rate_uavn0;
extern uint8 Mf_emiss_mf_rate_uavn0;
extern uint16 Mf_emiss_sum_uavn0;
extern uint16 MonMisf_rMisfOBD;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfFaiCtr(void);
void Misf_EveRst_MisfFaiCtr(void);
void Misf_SdlSlow_MisfFaiCtr(void);


#endif /* MISFFAICTR_H */

/*-------------------------------- end of file -------------------------------*/
