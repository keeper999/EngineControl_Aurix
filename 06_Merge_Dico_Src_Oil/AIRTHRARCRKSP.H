/***************************************************************************
;**
;** FILE NAME      : AIRTHRARCRKSP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIRTHRARCRKSP_H
#define AIRTHRARCRKSP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIR_DENSITY_GAIN_PRES_MAP_COLS         ( 17 )
#define AIR_DENSITY_GAIN_PRES_MAP_BKPT_COLS    ( 17 )
#define AIR_DENSITY_GAIN_TEMP_MAP_COLS         ( 17 )
#define AIR_DENSITY_GAIN_TEMP_MAP_BKPT_COLS    ( 17 )
#define DTC_DV_SURF_DEBOUCLE_MAP_LNS          ( 16 )
#define DTC_DV_SURF_DEBOUCLE_MAP_COLS          ( 16 )
#define DTC_DV_SURF_STT_MAP_LNS               ( 16 )
#define DTC_DV_SURF_STT_MAP_COLS               ( 16 )
#define DTC_FIRST_CRANK_DECAY_MAP_COLS         ( 16 )
#define DTC_FIRST_CRANK_DECAY_RETRY_MAP_COLS   ( 16 )
#define DTC_FIRST_CRANK_DELAY_MAP_COLS         ( 16 )
#define DTC_FIRST_CRANK_DELAY_RETRY_MAP_COLS   ( 16 )
#define DTC_FIRST_CRANK_OFFSET_MAP_COLS        ( 16 )
#define DTC_FIRST_CRANK_OFFSET_RETRY_MAP_COLS  ( 16 )
#define DTC_STT_CRANK_DECAY_RETRY_MAP_COLS     ( 16 )
#define DTC_STT_CRANK_DELAY_RETRY_MAP_COLS     ( 16 )
#define DTC_STT_CRANK_OFFSET_RETRY_MAP_COLS    ( 16 )
#define DTC_SURF_STOP_MAP_COLS                 ( 16 )
#define DTC_SURF_STOP_NENG_BKPT_MAP_COLS       ( 16 )
#define DTC_SURF_STT_NENG_BKPT_MAP_COLS        ( 16 )
#define DTC_SURF_STT_STOP_MAP_COLS             ( 16 )
#define DTC_SURF_STT_STOP_RSTRTINH_MAP_COLS    ( 16 )
#define DTC_TEAU_TOIL_SURF_DEBOUCLE_MAP_LNS   ( 16 )
#define DTC_TEAU_TOIL_SURF_DEBOUCLE_MAP_COLS   ( 16 )
#define DTC_TEAU_TOIL_SURF_STT_MAP_LNS        ( 16 )
#define DTC_TEAU_TOIL_SURF_STT_MAP_COLS        ( 16 )
#define DTC_TRANS_COUPLE_SURF_MAP_COLS         ( 16 )
#define DV_SURF_POS_PED_BKPT_MAP_COLS          ( 16 )
#define ENGST_RGAINSPTHRFCTPAIR_M_COLS         ( 17 )
#define TOIL_OR_TEAU_BKPT_MAP_COLS             ( 16 )

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

extern const boolean  CrkMgt_bInhCkEngLoss_C;
extern const boolean  CrkMng_bAcvThrClsEngStop_C;
extern const boolean  Dtc_deboucle_config_toil;
extern const uint8  Air_density_gain_pres_map[AIR_DENSITY_GAIN_PRES_MAP_COLS];
extern const uint8  Air_density_gain_temp_map[AIR_DENSITY_GAIN_TEMP_MAP_COLS];
extern const uint8  Air_density_gain_temp_map_bkpt[AIR_DENSITY_GAIN_TEMP_MAP_BKPT_COLS];
extern const uint8  Dtc_facTranRStrtAuth_C;
extern const uint8  Dtc_first_crank_delay_map[DTC_FIRST_CRANK_DELAY_MAP_COLS];
extern const uint8  Dtc_first_crank_delay_retry_map[DTC_FIRST_CRANK_DELAY_RETRY_MAP_COLS];
extern const uint8  Dtc_STT_crank_delay_retry_map[DTC_STT_CRANK_DELAY_RETRY_MAP_COLS];
extern const uint8  Dv_surf_pos_ped_bkpt_map[DV_SURF_POS_PED_BKPT_MAP_COLS];
extern const uint8  Toil_or_teau_bkpt_map[TOIL_OR_TEAU_BKPT_MAP_COLS];
extern const uint16  Air_density_gain_pres_map_bkpt[AIR_DENSITY_GAIN_PRES_MAP_BKPT_COLS];
extern const uint16  Dtc_dv_surf_deboucle_map[DTC_DV_SURF_DEBOUCLE_MAP_LNS][DTC_DV_SURF_DEBOUCLE_MAP_COLS];
extern const uint16  Dtc_dv_surf_STT_map[DTC_DV_SURF_STT_MAP_LNS][DTC_DV_SURF_STT_MAP_COLS];
extern const uint16  Dtc_first_crank_decay_map[DTC_FIRST_CRANK_DECAY_MAP_COLS];
extern const uint16  Dtc_first_crank_decay_retry_map[DTC_FIRST_CRANK_DECAY_RETRY_MAP_COLS];
extern const uint16  Dtc_first_crank_offset_map[DTC_FIRST_CRANK_OFFSET_MAP_COLS];
extern const uint16  Dtc_first_crank_offset_retry_map[DTC_FIRST_CRANK_OFFSET_RETRY_MAP_COLS];
extern const uint16  Dtc_STT_crank_decay_retry_map[DTC_STT_CRANK_DECAY_RETRY_MAP_COLS];
extern const uint16  Dtc_STT_crank_offset_retry_map[DTC_STT_CRANK_OFFSET_RETRY_MAP_COLS];
extern const uint16  Dtc_surf_stop_map[DTC_SURF_STOP_MAP_COLS];
extern const uint16  Dtc_surf_stop_nEng_bkpt_map[DTC_SURF_STOP_NENG_BKPT_MAP_COLS];
extern const uint16  Dtc_surf_STT_nEng_bkpt_map[DTC_SURF_STT_NENG_BKPT_MAP_COLS];
extern const uint16  Dtc_surf_STT_stop_map[DTC_SURF_STT_STOP_MAP_COLS];
extern const uint16  Dtc_surf_STT_stop_RStrtInh_map[DTC_SURF_STT_STOP_RSTRTINH_MAP_COLS];
extern const uint16  Dtc_teau_toil_surf_deboucle_map[DTC_TEAU_TOIL_SURF_DEBOUCLE_MAP_LNS][DTC_TEAU_TOIL_SURF_DEBOUCLE_MAP_COLS];
extern const uint16  Dtc_teau_toil_surf_STT_map[DTC_TEAU_TOIL_SURF_STT_MAP_LNS][DTC_TEAU_TOIL_SURF_STT_MAP_COLS];
extern const uint16  Dtc_trans_couple_surf_map[DTC_TRANS_COUPLE_SURF_MAP_COLS];
extern const uint16  EngSt_rGainSpThrFctPAir_M[ENGST_RGAINSPTHRFCTPAIR_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Dtc_first_crank_offset;
extern uint16 Dtc_surf_hors_struc_couple;
extern uint16 Dtc_trans_couple_surf;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AIRTHRARCRKSP_vidEntryInit(void);
void CrkMgt_SdlFast_AirThrArCrkSp(void);
void CrkMgt_SdlMid_AirThrArCrkSp(void);


#endif /* AIRTHRARCRKSP_H */

/*-------------------------------- end of file -------------------------------*/
