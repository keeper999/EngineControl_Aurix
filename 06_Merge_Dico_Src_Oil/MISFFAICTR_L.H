/***************************************************************************
;**
;** FILE NAME      : MISFFAICTR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFFAICTR_L_H
#define MISFFAICTR_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_CAT_DAM_CYL_UAVB0_COLS              ( 4 )
#define MF_CAT_DAM_WGHT_COUNT_CYL_UAVN1_COLS   ( 4 )
#define MF_CAT_DAM_WGHT_COUNT_REAL_RED_COLS    ( 4 )
#define MF_CAT_DAM_WGHT_COUNT_REAL_UAVN1_COLS  ( 4 )
#define MF_EMISS_COUNT_CYL_UAVN1_COLS          ( 4 )
#define MF_EMISS_COUNT_REAL_UAVN1_COLS         ( 4 )
#define MF_EMISS_CYL_UAVB1_COLS                ( 4 )

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

extern const uint8  MISFFAICTR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Coup_decel_progr_inj_a_catdam;
extern boolean Coup_decel_progr_inj_a_emiss;
extern boolean Coup_decel_progr_inj_b_catdam;
extern boolean Coup_decel_progr_inj_b_emiss;
extern boolean Coup_decel_progr_inj_c_catdam;
extern boolean Coup_decel_progr_inj_c_emiss;
extern boolean Coup_decel_progr_inj_d_catdam;
extern boolean Coup_decel_progr_inj_d_emiss;
extern boolean Flev_low_fuel_level_cat_dam;
extern boolean Mf_1_mf_cat_dam_uavb0;
extern boolean Mf_1_mf_emiss_uavb0;
extern boolean Mf_2_mf_cat_dam_uavb0;
extern boolean Mf_2_mf_emiss_uavb0;
extern boolean Mf_bInhTotDef;
extern boolean Mf_cat_dam_3cyl1_uavb0;
extern boolean Mf_cat_dam_3cyl2_uavb0;
extern boolean Mf_cat_dam_3cyl3_uavb0;
extern boolean Mf_cat_dam_4cyl1_uavb0;
extern boolean Mf_cat_dam_4cyl2_uavb0;
extern boolean Mf_cat_dam_4cyl3_uavb0;
extern boolean Mf_cat_dam_4cyl4_uavb0;
extern boolean Mf_cat_dam_glob_def_uavb0;
extern boolean Mf_cat_dam_wgth_sum_diag_ena;
extern boolean Misf_bAcvDetDmgCat;
extern boolean Misf_bAcvLowFuLvlCatDam;
extern boolean Misf_bDgoORngDmgCat1;
extern boolean Misf_bDgoORngDmgCat2;
extern boolean Misf_bDgoORngDmgCat3;
extern boolean Misf_bDgoORngDmgCat4;
extern boolean Misf_bDgoORngDmgCatMDAll;
extern boolean Misf_bDgoORngMisfEmi1;
extern boolean Misf_bDgoORngMisfEmi2;
extern boolean Misf_bDgoORngMisfEmi3;
extern boolean Misf_bDgoORngMisfEmi4;
extern boolean Misf_bDgoORngMisfEmiAll;
extern boolean Misf_bInhDetNoMisf;
extern boolean Misf_bMonRunORngDmgCat1;
extern boolean Misf_bMonRunORngDmgCat2;
extern boolean Misf_bMonRunORngDmgCat3;
extern boolean Misf_bMonRunORngDmgCat4;
extern boolean Misf_bMonRunORngDmgCatMDAll;
extern boolean Misf_bMonRunORngMisfEmi1;
extern boolean Misf_bMonRunORngMisfEmi2;
extern boolean Misf_bMonRunORngMisfEmi3;
extern boolean Misf_bMonRunORngMisfEmi4;
extern boolean Misf_bMonRunORngMisfEmiAll;
extern boolean Misf_bMonWaitORngDmgCatDTC1;
extern boolean Misf_bMonWaitORngDmgCatDTC2;
extern boolean Misf_bMonWaitORngDmgCatDTC3;
extern boolean Misf_bMonWaitORngDmgCatDTC4;
extern boolean Misf_bMonWaitORngDmgCatDTCAll;
extern boolean Misf_Defaut_TotalMisf_perCy1;
extern boolean Misf_Defaut_TotalMisf_perCy2;
extern boolean Misf_Defaut_TotalMisf_perCy3;
extern boolean Misf_Defaut_TotalMisf_perCy4;
extern boolean MISFFAICTR_bEmissHorizonPrev;
extern boolean MISFFAICTR_bFuelLevelTimeOut;
extern boolean MISFFAICTR_bLowFuelLevelPrev;
extern boolean MISFFAICTR_bMfCatDamHorizonPrev;
extern boolean MISFFAICTR_bMfMisfDetectedPrev;
extern boolean MISFFAICTR_bMisfAcvDetDmgCatPrev;
extern uint8 Coup_decel_progr_inj_cat_dam;
extern uint8 Coup_decel_progr_inj_emiss;
extern uint8 Coupure_decel_progr_inj_prev;
extern uint8 Mf_cat_dam_cyl_uavb0[MF_CAT_DAM_CYL_UAVB0_COLS];
extern uint8 Mf_cat_dam_nb_cyl_max_uavn1;
extern uint8 Mf_cat_dam_nb_cyl_max_uavn2;
extern uint8 Mf_cat_dam_nb_cyl_max_uavn3;
extern uint8 Mf_cat_dam_nb_cyl_max_uavn4;
extern uint8 Mf_cyl_cat_dam_uavb0;
extern uint8 Mf_cyl_emis_uavb0;
extern uint8 Mf_emiss_cyl_uavb1[MF_EMISS_CYL_UAVB1_COLS];
extern uint8 Mf_rough_road_sum_2mf_cat_uavn0;
extern uint8 Mf_rough_road_sum_2mf_emi_uavn0;
extern uint8 MISFFAICTR_u8CoupDecProgrInjprev;
extern uint8 MISFFAICTR_u8MfCylCatDamUavbprev;
extern uint8 MISFFAICTR_u8MfCylEmisUavb0prev;
extern uint8 MISFFAICTR_u8MfRoughCatUavn0;
extern uint8 MISFFAICTR_u8MfRoughEmiUavn0;
extern uint16 Flev_low_fuel_level_count;
extern uint16 Mf_cat_dam_4cyl1_int;
extern uint16 Mf_cat_dam_4cyl2_int;
extern uint16 Mf_cat_dam_4cyl3_int;
extern uint16 Mf_cat_dam_4cyl4_int;
extern uint16 Mf_cat_dam_count_uavn0;
extern uint16 Mf_cat_dam_no_cyl_max1_uavn;
extern uint16 Mf_cat_dam_no_cyl_max2_uavn;
extern uint16 Mf_cat_dam_sum_real_uavn0;
extern uint16 Mf_cat_dam_sum1_uavn0;
extern uint16 Mf_cat_dam_sum2_uavn0;
extern uint16 Mf_cat_dam_sum3_uavn0;
extern uint16 Mf_cat_dam_sum4_uavn0;
extern uint16 Mf_cat_dam_wght_count_1_uavn0;
extern uint16 Mf_cat_dam_wght_count_2_uavn0;
extern uint16 Mf_cat_dam_wght_count_3_uavn0;
extern uint16 Mf_cat_dam_wght_count_4_uavn0;
extern uint16 Mf_cat_dam_wght_count_cyl_uavn1[MF_CAT_DAM_WGHT_COUNT_CYL_UAVN1_COLS];
extern uint16 Mf_cat_dam_wght_count_max_uavn;
extern uint16 Mf_cat_dam_wght_count_max2_uavn;
extern uint16 Mf_cat_dam_wght_count_real_red[MF_CAT_DAM_WGHT_COUNT_REAL_RED_COLS];
extern uint16 Mf_cat_dam_wght_count_real_uavn1[MF_CAT_DAM_WGHT_COUNT_REAL_UAVN1_COLS];
extern uint16 Mf_cat_dam_wgth_sum_uavn0;
extern uint16 Mf_emiss_count_1_uavn0;
extern uint16 Mf_emiss_count_2_uavn0;
extern uint16 Mf_emiss_count_3_uavn0;
extern uint16 Mf_emiss_count_4_uavn0;
extern uint16 Mf_emiss_count_cyl_uavn1[MF_EMISS_COUNT_CYL_UAVN1_COLS];
extern uint16 Mf_emiss_count_real_uavn1[MF_EMISS_COUNT_REAL_UAVN1_COLS];
extern uint16 Mf_emiss_count_uavn0;
extern uint16 Mf_rough_road_cat_sum_uavn0;
extern uint16 Mf_rough_road_emiss_sum_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFFAICTR_vidCataDamage(void);
void MISFFAICTR_vidCataDamagePerCyl(void);
void MISFFAICTR_vidCataDamageSum(void);
void MISFFAICTR_vidCataEmissPerCyl(void);
void MISFFAICTR_vidCataRoughRdEmisCnt(void);
void MISFFAICTR_vidCataRoughRoadCnt(void);
void MISFFAICTR_vidCatDamCylCalc(void);
void MISFFAICTR_vidCatDamWghtRealCnt(void);
void MISFFAICTR_vidCatDmgCylCutMgt(void);
void MISFFAICTR_vidEmission(void);
void MISFFAICTR_vidEmissRealCount(void);
void MISFFAICTR_vidEmissSum(void);
void MISFFAICTR_vidEssenceDefault(void);
void MISFFAICTR_vidFailDetCatDam(void);
void MISFFAICTR_vidFailDetCatDamage(void);
void MISFFAICTR_vidFailDetCatDamage1(void);
void MISFFAICTR_vidFailDetEmiss(void);
void MISFFAICTR_vidFailDetEmission(void);
void MISFFAICTR_vidFuelLowLevelComput(void);
void MISFFAICTR_vidGazDefault(void);
void MISFFAICTR_vidHorizonCalcCatDam(void);
void MISFFAICTR_vidHorizonsCalcEmiss(void);
void MISFFAICTR_vidInhDetNoMisfEnable(void);
void MISFFAICTR_vidInit(void);
void MISFFAICTR_vidInitCatDam(void);
void MISFFAICTR_vidInitEmiss(void);
void MISFFAICTR_vidInitOutput(void);
void MISFFAICTR_vidMfCatDamRealSum(void);
void MISFFAICTR_vidMfCyl_1(void);
void MISFFAICTR_vidMfCyl_1_P2(void);
void MISFFAICTR_vidMfCyl_2(void);
void MISFFAICTR_vidMfCyl_2_P2(void);
void MISFFAICTR_vidMfCyl_3(void);
void MISFFAICTR_vidMfCyl_3_P2(void);
void MISFFAICTR_vidMfCyl_4(void);
void MISFFAICTR_vidMfCyl_4_P2(void);
void MISFFAICTR_vidMfDet4Cyl(void);
void MISFFAICTR_vidMfDetected3Cyl(void);
void MISFFAICTR_vidMfDetected4Cyl(void);
void MISFFAICTR_vidMfDetectedCatDam(void);
void MISFFAICTR_vidMfDetectedEmiss(void);
void MISFFAICTR_vidMfEmissCyl(void);
void MISFFAICTR_vidMisfFaiCtrEnable(void);
void MISFFAICTR_vidMisfireDefault(void);
void MISFFAICTR_vidMisfireRateCatDam(void);
void MISFFAICTR_vidMisfireRateEmiss(void);
void MISFFAICTR_vidMisfireTotal(void);
void MISFFAICTR_vidRoughRdNoDetCatDam(void);
void MISFFAICTR_vidRoughRdNoDetEmiss(void);
void MISFFAICTR_vidRoughRoadDetCatDam(void);
void MISFFAICTR_vidRoughRoadDetEmiss(void);


#endif /* MISFFAICTR_L_H */

/*-------------------------------- end of file -------------------------------*/
