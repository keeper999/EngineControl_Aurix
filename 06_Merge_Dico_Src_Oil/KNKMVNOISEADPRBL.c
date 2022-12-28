/***************************************************************************
;**
;** FILE NAME      : KNKMVNOISEADPRBL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKMVNOISEADPRBL.H"
#include "KNKMVNOISEADPRBL_L.H"
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
const boolean  Knk_rbl_noi_ad_knk_manu_inh_uacb = 0;
const boolean  Knk_rbl_noi_ad_manu_inh_uacb0 = 0;
const boolean  Knk_rbl_noi_ad_risknk_manu_inh_u = 0;
const uint8  Knk_rbl_noi_ad_cdn_n_hthresh = 0;
const uint8  Knk_rbl_noi_ad_cdn_n_lthresh = 0;
const uint8  Knk_rbl_noi_ad_cdn_tco_lthresh = 0;
const uint8  Knk_rbl_noi_ad_gain_hclmp_uacn0 = 0;
const uint8  Knk_rbl_noi_ad_gain_lclmp_uacn0 = 0;
const uint8  KnkMvNoiseAdpRbl_u8Inhib = 0;
const uint16  Knk_rbl_noi_ad_cdn_load_hthrsh = 0;
const uint16  Knk_rbl_noi_ad_cdn_load_lthrsh = 0;
const uint16  Knk_rbl_noi_ad_dz_uacn0 = 0;
const uint16  Knk_rbl_noi_ad_filt_gain_uacn0 = 0;
const uint16  Knk_rbl_noi_ad_var_clmp_uacn0 = 0;
const uint16  Knk_rbl_noi_mv_sp_uacn0 = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Knk_rbl_noi_ad_cdn_ok_uavb0;
boolean Knk_rbl_noi_ad_h_hit_uavb0;
boolean Knk_rbl_noi_ad_l_hit_uavb0;
uint16 Knk_rbl_noi_ad_gain_uavn0;
uint16 Knk_rbl_noi_ad_gain_uavn1[KNK_RBL_NOI_AD_GAIN_UAVN1_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

