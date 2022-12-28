/***************************************************************************
;**
;** FILE NAME      : KNKDETRBL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKDETRBL_H
#define KNKDETRBL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BRUIT_MOYEN_RBL_CYL_COLS               ( 4 )
#define BRUIT_MOYEN_RBL_MAX_THRESH_COLS        ( 4 )
#define DETECTION_RBL_COLS                     ( 4 )
#define KNK_DET_RBL_GAIN_CYL1_AGIG_MAP_COLS    ( 16 )
#define KNK_DET_RBL_GAIN_CYL1_EAL_MAP_COLS     ( 17 )
#define KNK_DET_RBL_GAIN_CYL1_N_MAP_COLS       ( 16 )
#define KNK_DET_RBL_GAIN_CYL2_AGIG_MAP_COLS    ( 16 )
#define KNK_DET_RBL_GAIN_CYL2_EAL_MAP_COLS     ( 17 )
#define KNK_DET_RBL_GAIN_CYL2_N_MAP_COLS       ( 16 )
#define KNK_DET_RBL_GAIN_CYL3_AGIG_MAP_COLS    ( 16 )
#define KNK_DET_RBL_GAIN_CYL3_EAL_MAP_COLS     ( 17 )
#define KNK_DET_RBL_GAIN_CYL3_N_MAP_COLS       ( 16 )
#define KNK_DET_RBL_GAIN_CYL4_AGIG_MAP_COLS    ( 16 )
#define KNK_DET_RBL_GAIN_CYL4_EAL_MAP_COLS     ( 17 )
#define KNK_DET_RBL_GAIN_CYL4_N_MAP_COLS       ( 16 )
#define KNK_RBL_INDEX_COLS                     ( 4 )
#define KNKRBL_AGIGDETRBLGAINCYL_A_COLS        ( 16 )

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

extern const boolean  Knk_bInhKnkBvmp;
extern const boolean  KnkMgt_bAcvInstNoiNormWiWind_C;
extern const uint8  Facteur_filtrage_rbl_dyn;
extern const uint8  Facteur_filtrage_rbl_stat;
extern const uint8  Knk_ctCylInhRblDet_C;
extern const uint8  Knk_det_rbl_gain_cyl1_agig_map[KNK_DET_RBL_GAIN_CYL1_AGIG_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl1_eal_map[KNK_DET_RBL_GAIN_CYL1_EAL_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl1_n_map[KNK_DET_RBL_GAIN_CYL1_N_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl2_agig_map[KNK_DET_RBL_GAIN_CYL2_AGIG_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl2_eal_map[KNK_DET_RBL_GAIN_CYL2_EAL_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl2_n_map[KNK_DET_RBL_GAIN_CYL2_N_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl3_agig_map[KNK_DET_RBL_GAIN_CYL3_AGIG_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl3_eal_map[KNK_DET_RBL_GAIN_CYL3_EAL_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl3_n_map[KNK_DET_RBL_GAIN_CYL3_N_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl4_agig_map[KNK_DET_RBL_GAIN_CYL4_AGIG_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl4_eal_map[KNK_DET_RBL_GAIN_CYL4_EAL_MAP_COLS];
extern const uint8  Knk_det_rbl_gain_cyl4_n_map[KNK_DET_RBL_GAIN_CYL4_N_MAP_COLS];
extern const uint8  Knk_rbl_dyn_filt_delay;
extern const uint8  KnkMgt_agIgRblWinLengthRef_C;
extern const uint8  KnkRbl_agIgDetRblGainCyl_A[KNKRBL_AGIGDETRBLGAINCYL_A_COLS];
extern const uint8  Longueur_table_sortie_rbl;
extern const uint16  Bruit_moyen_rbl_max_thresh[BRUIT_MOYEN_RBL_MAX_THRESH_COLS];
extern const uint16  Engine_load_rbl_seuil;
extern const uint16  Knk_Bruit_moyen_rbl_init_c;
extern const uint16  Knk_n_rbl_dyn_filt_thresh_uacn0;
extern const uint16  Knk_rbl_noi_inc_step_uacn0;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Detection_rbl[DETECTION_RBL_COLS];
extern uint8 Knk_rbl_index[KNK_RBL_INDEX_COLS];
extern uint16 Bruit_moyen_rbl_cyl[BRUIT_MOYEN_RBL_CYL_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveCkSnOn_KnkDetRbl(void);
void KnkTreat_EveRbl_KnkDetRbl(void);
void KnkTreat_EveRst_KnkDetRbl(void);
void KnkTreat_SdlMid_KnkDetRbl(void);
void KnkTreat_SdlSlow_KnkDetRbl(void);


#endif /* KNKDETRBL_H */

/*-------------------------------- end of file -------------------------------*/
