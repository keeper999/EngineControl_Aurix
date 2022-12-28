/***************************************************************************
;**
;** FILE NAME      : KNKMVNOISEADPRBL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKMVNOISEADPRBL_H
#define KNKMVNOISEADPRBL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNK_RBL_NOI_AD_GAIN_UAVN1_COLS         ( 4 )

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

extern const boolean  Knk_rbl_noi_ad_knk_manu_inh_uacb;
extern const boolean  Knk_rbl_noi_ad_manu_inh_uacb0;
extern const boolean  Knk_rbl_noi_ad_risknk_manu_inh_u;
extern const uint8  Knk_rbl_noi_ad_cdn_n_hthresh;
extern const uint8  Knk_rbl_noi_ad_cdn_n_lthresh;
extern const uint8  Knk_rbl_noi_ad_cdn_tco_lthresh;
extern const uint8  Knk_rbl_noi_ad_gain_hclmp_uacn0;
extern const uint8  Knk_rbl_noi_ad_gain_lclmp_uacn0;
extern const uint16  Knk_rbl_noi_ad_cdn_load_hthrsh;
extern const uint16  Knk_rbl_noi_ad_cdn_load_lthrsh;
extern const uint16  Knk_rbl_noi_ad_dz_uacn0;
extern const uint16  Knk_rbl_noi_ad_filt_gain_uacn0;
extern const uint16  Knk_rbl_noi_ad_var_clmp_uacn0;
extern const uint16  Knk_rbl_noi_mv_sp_uacn0;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Knk_rbl_noi_ad_gain_uavn1[KNK_RBL_NOI_AD_GAIN_UAVN1_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveRbl_KnkMvNoiseAdpRbl(void);
void KnkTreat_EveStTR_KnkMvNoisAdpRbl(void);


#endif /* KNKMVNOISEADPRBL_H */

/*-------------------------------- end of file -------------------------------*/
