/***************************************************************************
;**
;** FILE NAME      : KNKNOISEADP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKNOISEADP.H"
#include "KNKNOISEADP_L.H"
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
const boolean  Knk_noi_ad_manu_inh_uacb0 = 0;
const uint8  Knk_noi_ad_cdn_load_hthrsh_uacn0 = 0;
const uint8  Knk_noi_ad_cdn_load_lthrsh_uacn0 = 0;
const uint8  Knk_noi_ad_cdn_n_hthresh_uacn0 = 0;
const uint8  Knk_noi_ad_cdn_n_lthresh_uacn0 = 0;
const uint8  Knk_noi_ad_cdn_tco_lthresh_uacn0 = 0;
const uint8  Knk_noi_ad_diag_tco_thresh_uacn0 = 0;
const uint8  Knk_noi_ad_gain_hclmp_uacn0 = 0;
const uint8  Knk_noi_ad_gain_hthr_uacn0 = 0;
const uint8  Knk_noi_ad_gain_lclmp_uacn0 = 0;
const uint8  Knk_noi_ad_gain_lthr_uacn0 = 0;
const uint8  KNKNOISEADP_u8Inhib = 0;
const uint16  Knk_noi_ad_diag_delay_uacn0 = 0;
const uint16  Knk_noi_ad_dz_uacn0 = 0;
const uint16  Knk_noi_ad_filt_gain_uacn0 = 0;
const uint16  Knk_noi_ad_gain_init_uacn1[KNK_NOI_AD_GAIN_INIT_UACN1_COLS] = {0};
const uint16  Knk_noi_ad_var_clmp_uacn0 = 0;
const uint16  Knk_noi_mv_sp_uacn0 = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Knk_noi_ad_cdn_ok_uavb0;
boolean Knk_noi_ad_h_hit_uavb1[KNK_NOI_AD_H_HIT_UAVB1_COLS];
boolean Knk_noi_ad_high_uavb1[KNK_NOI_AD_HIGH_UAVB1_COLS];
boolean Knk_noi_ad_l_hit_uavb1[KNK_NOI_AD_L_HIT_UAVB1_COLS];
boolean Knk_noi_ad_low_uavb1[KNK_NOI_AD_LOW_UAVB1_COLS];
boolean KNKNOISEADP_bInitTimerPrev;
boolean KnkTreat_bDgoHHit_NoiseAdp;
boolean KnkTreat_bDgoHSld_NoiseAdp;
boolean KnkTreat_bDgoLHit_NoiseAdp;
boolean KnkTreat_bDgoLSld_NoiseAdp;
boolean KnkTreat_bMonRun_NoiseAdp;
uint16 Knk_noi_ad_diag_tempo_uavn0;
uint16 Knk_noi_ad_gain_uavn1[KNK_NOI_AD_GAIN_UAVN1_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

