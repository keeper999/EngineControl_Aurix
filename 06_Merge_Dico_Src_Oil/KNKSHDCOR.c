/***************************************************************************
;**
;** FILE NAME      : KNKSHDCOR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKSHDCOR.H"
#include "KNKSHDCOR_L.H"
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
const boolean  Knk_deg_bv_chgt_inh_uacb0 = 0;
const boolean  Knk_deg_zc_manu_inh_uacb0 = 0;
const uint8  Knk_deg_cor_dec_uacn0 = 0;
const uint8  Knk_deg_cor_in_filt_uacn0 = 0;
const uint8  Knk_deg_cor_inc_uacn0 = 0;
const uint8  Knk_deg_cor_offset_uacn0 = 0;
const uint8  Knk_deg_cor_out_filt_uacn0 = 0;
const uint8  Knk_deg_det_count_thr_uacn0 = 0;
const uint8  Knk_deg_obs_win_length_uacn1[KNK_DEG_OBS_WIN_LENGTH_UACN1_COLS] = {0};
const uint8  KNKSHDCOR_u8Inhib = 0;
const uint16  Knk_deg_cor_dec_delay_uacn1[KNK_DEG_COR_DEC_DELAY_UACN1_COLS] = {0};
const uint16  Knk_deg_cor_delay_uacn1[KNK_DEG_COR_DELAY_UACN1_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean knk_corr_inc_uavb0;
uint8 Knk_deg_app_count_eep;
uint8 Knk_deg_cor_av_filt_uavn0;
uint8 Knk_deg_cor_uavn0;
uint8 Knk_deg_det_count_uavn1[KNK_DEG_DET_COUNT_UAVN1_COLS];
uint8 Knk_deg_obs_win_uavn1[KNK_DEG_OBS_WIN_UAVN1_COLS];
uint16 Knk_deg_cor_tempo_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

