/***************************************************************************
;**
;** FILE NAME      : KNKNOISEADP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKNOISEADP_H
#define KNKNOISEADP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNK_NOI_AD_GAIN_INIT_UACN1_COLS        ( 4 )
#define KNK_NOI_AD_GAIN_UAVN1_COLS             ( 4 )

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

extern const boolean  Knk_noi_ad_manu_inh_uacb0;
extern const uint8  Knk_noi_ad_cdn_load_hthrsh_uacn0;
extern const uint8  Knk_noi_ad_cdn_load_lthrsh_uacn0;
extern const uint8  Knk_noi_ad_cdn_n_hthresh_uacn0;
extern const uint8  Knk_noi_ad_cdn_n_lthresh_uacn0;
extern const uint8  Knk_noi_ad_cdn_tco_lthresh_uacn0;
extern const uint8  Knk_noi_ad_diag_tco_thresh_uacn0;
extern const uint8  Knk_noi_ad_gain_hclmp_uacn0;
extern const uint8  Knk_noi_ad_gain_hthr_uacn0;
extern const uint8  Knk_noi_ad_gain_lclmp_uacn0;
extern const uint8  Knk_noi_ad_gain_lthr_uacn0;
extern const uint16  Knk_noi_ad_diag_delay_uacn0;
extern const uint16  Knk_noi_ad_dz_uacn0;
extern const uint16  Knk_noi_ad_filt_gain_uacn0;
extern const uint16  Knk_noi_ad_gain_init_uacn1[KNK_NOI_AD_GAIN_INIT_UACN1_COLS];
extern const uint16  Knk_noi_ad_var_clmp_uacn0;
extern const uint16  Knk_noi_mv_sp_uacn0;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Knk_noi_ad_gain_uavn1[KNK_NOI_AD_GAIN_UAVN1_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveKnk_NoiseAdp(void);
void KnkTreat_EveRst_NoiseAdp(void);
void KnkTreat_SdlSlow_NoiseAdp(void);


#endif /* KNKNOISEADP_H */

/*-------------------------------- end of file -------------------------------*/
