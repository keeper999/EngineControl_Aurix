/***************************************************************************
;**
;** FILE NAME      : KNKDETRBL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKDETRBL_L_H
#define KNKDETRBL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BRUIT_INSTANTANE_RBL_CYL_COLS          ( 16 )
#define BRUIT_MOYEN_RBL_CYL_PREV_COLS          ( 4 )
#define DETECTION_RBL_PREV_COLS                ( 4 )
#define KNK_DET_RBL_THR_UAVN0_CYL_PREV_COLS    ( 4 )
#define KNK_DET_RBL_THRESH_UAVN0_CYL_COLS      ( 4 )
#define KNK_RBL_INDEX_PREV_COLS                ( 4 )
#define KNKDETRBL_u8ARRAY_LENGTH          16
#define KNKTREAT_u8ARRAY_LENGTH           4

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

extern const uint8  KnkDetRbl_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Auth_rbl_bruit_moy;
extern boolean Detection_fort_cliquetis_cyl;
extern boolean Detection_rbl_cyl;
extern boolean Detection_rbl_cyl_raw;
extern boolean Detection_rbl_cyl_wo_diag;
extern boolean Detection_rbl_prev[DETECTION_RBL_PREV_COLS];
extern boolean Etat_capteur;
extern boolean Knk_n_rbl_dyn_filt_uavb0;
extern boolean KNKDETRBL_bCompteur_cyl_prev;
extern boolean KNKDETRBL_bDetect_cylPrev;
extern boolean KnkMgt_bInjCutOffCyl;
extern uint8 Compteur_cyl_inh_rbl_det;
extern uint8 Facteur_filtrage_rbl;
extern uint8 Knk_det_rbl_gain_cyl1_regime;
extern uint8 Knk_det_rbl_gain_cyl2_regime;
extern uint8 Knk_det_rbl_gain_cyl3_regime;
extern uint8 Knk_det_rbl_gain_cyl4_regime;
extern uint8 Knk_det_rbl_gain_regime;
extern uint8 Knk_rbl_dyn_filt_counter;
extern uint8 Knk_rbl_dyn_filt_counter_prev;
extern uint8 Knk_rbl_index_cyl_temp;
extern uint8 Knk_rbl_index_det_cyl;
extern uint8 Knk_rbl_index_prev[KNK_RBL_INDEX_PREV_COLS];
extern uint8 KnkMgt_agIgKnkAdpOfs;
extern uint16 Bruit_instantane_rbl_cyl[BRUIT_INSTANTANE_RBL_CYL_COLS];
extern uint16 Bruit_moyen_rbl;
extern uint16 Bruit_moyen_rbl_cyl_max_thresh;
extern uint16 Bruit_moyen_rbl_cyl_prev[BRUIT_MOYEN_RBL_CYL_PREV_COLS];
extern uint16 Bruit_moyen_rbl_prev;
extern uint16 Ext_rTotLd_rbl_prev;
extern uint16 Knk_det_rbl_thr_uavn0_cyl_prev[KNK_DET_RBL_THR_UAVN0_CYL_PREV_COLS];
extern uint16 Knk_det_rbl_thresh_uavn0;
extern uint16 Knk_det_rbl_thresh_uavn0_cyl[KNK_DET_RBL_THRESH_UAVN0_CYL_COLS];
extern uint16 KnkMgt_ctInjCutOffRbl_cyl;
extern uint16 Regime_moteur_rbl_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkDetRbl_vidAutoriseDetectRbl(void);
void KnkDetRbl_vidCalcBruitMoyenRbl(void);
void KnkDetRbl_vidCalcFactFiltrageN(void);
void KnkDetRbl_vidCalcFactFiltrLoad(void);
void KnkDetRbl_vidCyl1_rbl(void);
void KnkDetRbl_vidCyl2_rbl(void);
void KnkDetRbl_vidCyl3_rbl(void);
void KnkDetRbl_vidCyl4_rbl(void);
void KnkDetRbl_vidDetection_index(void);
void KnkDetRbl_vidDetection_rumble(void);
void KNKDETRBL_vidInit(void);
void KnkDetRbl_vidInitOutput(void);
void KnkDetRbl_vidKnkDetRblGainRegime(void);
void KNKDETRBL_vidReinitTacheSynchRbl(void);
void KnkDetRbl_vidTache_rumble(void);
void KnkDetRbl_vidTraitmntsDetectRrbl(void);


#endif /* KNKDETRBL_L_H */

/*-------------------------------- end of file -------------------------------*/
