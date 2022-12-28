/***************************************************************************
;**
;** FILE NAME      : KNKDET.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKDET.H"
#include "KNKDET_L.H"
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
const boolean  Cipd_det_knk_2cyl_manu_inh = 0;
const boolean  Knk_det_fort_knk_inh_uacb0 = 0;
const boolean  Knk_det_ris_knk_inh_uacb0 = 0;
const uint8  Facteur_filtrage_cliquetis_dyn = 0;
const uint8  Facteur_filtrage_cliquetis_stat = 0;
const uint8  Knk_det_dyn_filt_delay = 0;
const uint8  Knk_det_gain_cyl1_n_map_uacn2[KNK_DET_GAIN_CYL1_N_MAP_UACN2_LNS][KNK_DET_GAIN_CYL1_N_MAP_UACN2_COLS] = {0};
const uint8  Knk_det_gain_cyl2_n_map_uacn2[KNK_DET_GAIN_CYL2_N_MAP_UACN2_LNS][KNK_DET_GAIN_CYL2_N_MAP_UACN2_COLS] = {0};
const uint8  Knk_det_gain_cyl3_n_map_uacn2[KNK_DET_GAIN_CYL3_N_MAP_UACN2_LNS][KNK_DET_GAIN_CYL3_N_MAP_UACN2_COLS] = {0};
const uint8  Knk_det_gain_cyl4_n_map_uacn2[KNK_DET_GAIN_CYL4_N_MAP_UACN2_LNS][KNK_DET_GAIN_CYL4_N_MAP_UACN2_COLS] = {0};
const uint8  Knk_det_ris_dyn_n_map_uacn1[KNK_DET_RIS_DYN_N_MAP_UACN1_COLS] = {0};
const uint8  Knk_det_ris_stat_n_map_uacn1[KNK_DET_RIS_STAT_N_MAP_UACN1_COLS] = {0};
const uint8  KnkDet_agDeltaAdvInhDetKnk_C = 0;
const uint8  KNKDET_u8Inhib = 0;
const uint16  Bruit_moyen_cyl_min_thresh[BRUIT_MOYEN_CYL_MIN_THRESH_COLS] = {0};
const uint16  Engine_load_cliq_seuil = 0;
const uint16  Knk_det_fort_dyn_n_map_uacn1[KNK_DET_FORT_DYN_N_MAP_UACN1_COLS] = {0};
const uint16  Knk_det_fort_stat_n_map_uacn1[KNK_DET_FORT_STAT_N_MAP_UACN1_COLS] = {0};
const uint16  Knk_det_noi_inc_step_uacn0 = 0;
const uint16  Knk_n_dyn_filt_thresh_uacn0 = 0;
const uint16  KnkDet_tiInhDetKnkAfterGc_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean active_conditions_clq;
boolean active_conditions_clq_14;
boolean active_conditions_clq_23;
boolean Bvmp_inh_cliq_acquisition;
boolean Detection_cliquetis[DETECTION_CLIQUETIS_COLS];
boolean Detection_fort_cliquetis[DETECTION_FORT_CLIQUETIS_COLS];
boolean Knk_det_ris_knk_cyl_uavb1[KNK_DET_RIS_KNK_CYL_UAVB1_COLS];
boolean Knk_eal_dyn_filt_det_uavb0;
boolean Knk_n_dyn_filt_det_uavb0;
uint8 Facteur_filtrage_cliquetis[FACTEUR_FILTRAGE_CLIQUETIS_COLS];
uint8 Knk_det_dyn_filt_counter[KNK_DET_DYN_FILT_COUNTER_COLS];
uint8 Knk_det_ris_knk_thrsh_gain[KNK_DET_RIS_KNK_THRSH_GAIN_COLS];
uint16 Bruit_moyen_cyl[BRUIT_MOYEN_CYL_COLS];
uint16 Ext_rTotLd_cliq_prev;
uint16 Knk_det_fort_knk_thrsh_gain[KNK_DET_FORT_KNK_THRSH_GAIN_COLS];
uint16 Knk_det_thresh_cyl[KNK_DET_THRESH_CYL_COLS];
uint16 KNKDET_u16InhDetKnkAfterCounter;
uint16 Regime_moteur_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

