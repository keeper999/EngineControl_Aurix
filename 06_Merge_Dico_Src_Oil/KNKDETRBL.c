/***************************************************************************
;**
;** FILE NAME      : KNKDETRBL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKDETRBL.H"
#include "KNKDETRBL_L.H"
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
const boolean  Knk_bInhKnkBvmp = 0;
const boolean  KnkMgt_bAcvInstNoiNormWiWind_C = 0;
const uint8  Facteur_filtrage_rbl_dyn = 0;
const uint8  Facteur_filtrage_rbl_stat = 0;
const uint8  Knk_ctCylInhRblDet_C = 0;
const uint8  Knk_det_rbl_gain_cyl1_agig_map[KNK_DET_RBL_GAIN_CYL1_AGIG_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl1_eal_map[KNK_DET_RBL_GAIN_CYL1_EAL_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl1_n_map[KNK_DET_RBL_GAIN_CYL1_N_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl2_agig_map[KNK_DET_RBL_GAIN_CYL2_AGIG_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl2_eal_map[KNK_DET_RBL_GAIN_CYL2_EAL_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl2_n_map[KNK_DET_RBL_GAIN_CYL2_N_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl3_agig_map[KNK_DET_RBL_GAIN_CYL3_AGIG_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl3_eal_map[KNK_DET_RBL_GAIN_CYL3_EAL_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl3_n_map[KNK_DET_RBL_GAIN_CYL3_N_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl4_agig_map[KNK_DET_RBL_GAIN_CYL4_AGIG_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl4_eal_map[KNK_DET_RBL_GAIN_CYL4_EAL_MAP_COLS] = {0};
const uint8  Knk_det_rbl_gain_cyl4_n_map[KNK_DET_RBL_GAIN_CYL4_N_MAP_COLS] = {0};
const uint8  Knk_rbl_dyn_filt_delay = 0;
const uint8  KnkDetRbl_u8Inhib = 0;
const uint8  KnkMgt_agIgRblWinLengthRef_C = 0;
const uint8  KnkRbl_agIgDetRblGainCyl_A[KNKRBL_AGIGDETRBLGAINCYL_A_COLS] = {0};
const uint8  Longueur_table_sortie_rbl = 0;
const uint16  Bruit_moyen_rbl_max_thresh[BRUIT_MOYEN_RBL_MAX_THRESH_COLS] = {0};
const uint16  Engine_load_rbl_seuil = 0;
const uint16  Knk_Bruit_moyen_rbl_init_c = 0;
const uint16  Knk_n_rbl_dyn_filt_thresh_uacn0 = 0;
const uint16  Knk_rbl_noi_inc_step_uacn0 = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Auth_rbl_bruit_moy;
boolean Detection_fort_cliquetis_cyl;
boolean Detection_rbl[DETECTION_RBL_COLS];
boolean Detection_rbl_cyl;
boolean Detection_rbl_cyl_raw;
boolean Detection_rbl_cyl_wo_diag;
boolean Detection_rbl_prev[DETECTION_RBL_PREV_COLS];
boolean Etat_capteur;
boolean Knk_n_rbl_dyn_filt_uavb0;
boolean KNKDETRBL_bCompteur_cyl_prev;
boolean KNKDETRBL_bDetect_cylPrev;
boolean KnkMgt_bInjCutOffCyl;
uint8 Compteur_cyl_inh_rbl_det;
uint8 Facteur_filtrage_rbl;
uint8 Knk_det_rbl_gain_cyl1_regime;
uint8 Knk_det_rbl_gain_cyl2_regime;
uint8 Knk_det_rbl_gain_cyl3_regime;
uint8 Knk_det_rbl_gain_cyl4_regime;
uint8 Knk_det_rbl_gain_regime;
uint8 Knk_rbl_dyn_filt_counter;
uint8 Knk_rbl_dyn_filt_counter_prev;
uint8 Knk_rbl_index[KNK_RBL_INDEX_COLS];
uint8 Knk_rbl_index_cyl_temp;
uint8 Knk_rbl_index_det_cyl;
uint8 Knk_rbl_index_prev[KNK_RBL_INDEX_PREV_COLS];
uint8 KnkMgt_agIgKnkAdpOfs;
uint16 Bruit_instantane_rbl_cyl[BRUIT_INSTANTANE_RBL_CYL_COLS];
uint16 Bruit_moyen_rbl;
uint16 Bruit_moyen_rbl_cyl[BRUIT_MOYEN_RBL_CYL_COLS];
uint16 Bruit_moyen_rbl_cyl_max_thresh;
uint16 Bruit_moyen_rbl_cyl_prev[BRUIT_MOYEN_RBL_CYL_PREV_COLS];
uint16 Bruit_moyen_rbl_prev;
uint16 Ext_rTotLd_rbl_prev;
uint16 Knk_det_rbl_thr_uavn0_cyl_prev[KNK_DET_RBL_THR_UAVN0_CYL_PREV_COLS];
uint16 Knk_det_rbl_thresh_uavn0;
uint16 Knk_det_rbl_thresh_uavn0_cyl[KNK_DET_RBL_THRESH_UAVN0_CYL_COLS];
uint16 KnkMgt_ctInjCutOffRbl_cyl;
uint16 Regime_moteur_rbl_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

