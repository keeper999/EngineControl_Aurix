/***************************************************************************
;**
;** FILE NAME      : KNKDET.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKDET_H
#define KNKDET_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BRUIT_MOYEN_CYL_COLS                   ( 4 )
#define BRUIT_MOYEN_CYL_MIN_THRESH_COLS        ( 4 )
#define DETECTION_CLIQUETIS_COLS               ( 4 )
#define DETECTION_FORT_CLIQUETIS_COLS          ( 4 )
#define KNK_DET_FORT_DYN_N_MAP_UACN1_COLS      ( 16 )
#define KNK_DET_FORT_STAT_N_MAP_UACN1_COLS     ( 16 )
#define KNK_DET_GAIN_CYL1_N_MAP_UACN2_LNS     ( 17 )
#define KNK_DET_GAIN_CYL1_N_MAP_UACN2_COLS     ( 16 )
#define KNK_DET_GAIN_CYL2_N_MAP_UACN2_LNS     ( 17 )
#define KNK_DET_GAIN_CYL2_N_MAP_UACN2_COLS     ( 16 )
#define KNK_DET_GAIN_CYL3_N_MAP_UACN2_LNS     ( 17 )
#define KNK_DET_GAIN_CYL3_N_MAP_UACN2_COLS     ( 16 )
#define KNK_DET_GAIN_CYL4_N_MAP_UACN2_LNS     ( 17 )
#define KNK_DET_GAIN_CYL4_N_MAP_UACN2_COLS     ( 16 )
#define KNK_DET_RIS_DYN_N_MAP_UACN1_COLS       ( 16 )
#define KNK_DET_RIS_KNK_CYL_UAVB1_COLS         ( 4 )
#define KNK_DET_RIS_STAT_N_MAP_UACN1_COLS      ( 16 )

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

extern const boolean  Cipd_det_knk_2cyl_manu_inh;
extern const boolean  Knk_det_fort_knk_inh_uacb0;
extern const boolean  Knk_det_ris_knk_inh_uacb0;
extern const uint8  Facteur_filtrage_cliquetis_dyn;
extern const uint8  Facteur_filtrage_cliquetis_stat;
extern const uint8  Knk_det_dyn_filt_delay;
extern const uint8  Knk_det_gain_cyl1_n_map_uacn2[KNK_DET_GAIN_CYL1_N_MAP_UACN2_LNS][KNK_DET_GAIN_CYL1_N_MAP_UACN2_COLS];
extern const uint8  Knk_det_gain_cyl2_n_map_uacn2[KNK_DET_GAIN_CYL2_N_MAP_UACN2_LNS][KNK_DET_GAIN_CYL2_N_MAP_UACN2_COLS];
extern const uint8  Knk_det_gain_cyl3_n_map_uacn2[KNK_DET_GAIN_CYL3_N_MAP_UACN2_LNS][KNK_DET_GAIN_CYL3_N_MAP_UACN2_COLS];
extern const uint8  Knk_det_gain_cyl4_n_map_uacn2[KNK_DET_GAIN_CYL4_N_MAP_UACN2_LNS][KNK_DET_GAIN_CYL4_N_MAP_UACN2_COLS];
extern const uint8  Knk_det_ris_dyn_n_map_uacn1[KNK_DET_RIS_DYN_N_MAP_UACN1_COLS];
extern const uint8  Knk_det_ris_stat_n_map_uacn1[KNK_DET_RIS_STAT_N_MAP_UACN1_COLS];
extern const uint8  KnkDet_agDeltaAdvInhDetKnk_C;
extern const uint16  Bruit_moyen_cyl_min_thresh[BRUIT_MOYEN_CYL_MIN_THRESH_COLS];
extern const uint16  Engine_load_cliq_seuil;
extern const uint16  Knk_det_fort_dyn_n_map_uacn1[KNK_DET_FORT_DYN_N_MAP_UACN1_COLS];
extern const uint16  Knk_det_fort_stat_n_map_uacn1[KNK_DET_FORT_STAT_N_MAP_UACN1_COLS];
extern const uint16  Knk_det_noi_inc_step_uacn0;
extern const uint16  Knk_n_dyn_filt_thresh_uacn0;
extern const uint16  KnkDet_tiInhDetKnkAfterGc_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Bvmp_inh_cliq_acquisition;
extern boolean Detection_cliquetis[DETECTION_CLIQUETIS_COLS];
extern boolean Detection_fort_cliquetis[DETECTION_FORT_CLIQUETIS_COLS];
extern boolean Knk_det_ris_knk_cyl_uavb1[KNK_DET_RIS_KNK_CYL_UAVB1_COLS];
extern uint16 Bruit_moyen_cyl[BRUIT_MOYEN_CYL_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveCkSnOn_KnkDet(void);
void KnkTreat_EveKnk_KnkDet(void);
void KnkTreat_EveRst_KnkDet(void);
void KnkTreat_SdlFast_KnkDet(void);
void KnkTreat_SdlMid_KnkDet(void);
void KnkTreat_SdlSlow_KnkDet(void);


#endif /* KNKDET_H */

/*-------------------------------- end of file -------------------------------*/
