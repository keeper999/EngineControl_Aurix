/***************************************************************************
;**
;** FILE NAME      : KNKACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKACQ_H
#define KNKACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CLIQ_AV_CORR_BKPT_MAP_COLS             ( 10 )
#define CLIQ_EAL_COLS                          ( 17 )
#define CLIQ_INTK_VVT_ERR_BKPT_MAP_COLS        ( 10 )
#define CLIQ_N_COLS                            ( 20 )
#define KNK_SEN_DYN_FILT_DET_UAVB1_COLS        ( 4 )
#define TABLE_DEB_CLQ_OFFSET_TRANSITOIRE_LNS  ( 17 )
#define TABLE_DEB_CLQ_OFFSET_TRANSITOIRE_COLS  ( 10 )
#define TABLE_DEBUT_FENETRE_CLIQUETIS_LNS     ( 17 )
#define TABLE_DEBUT_FENETRE_CLIQUETIS_COLS     ( 20 )
#define TABLE_DEC_CLQ_NUM_AV_CORR_LNS         ( 10 )
#define TABLE_DEC_CLQ_NUM_AV_CORR_COLS         ( 20 )
#define TABLE_DUREE_FENETRE_CLIQUETIS_COLS     ( 20 )
#define TABLE_FREQ_CENTRALE_CLQ_CYL1_LNS      ( 17 )
#define TABLE_FREQ_CENTRALE_CLQ_CYL1_COLS      ( 20 )
#define TABLE_FREQ_CENTRALE_CLQ_CYL2_LNS      ( 17 )
#define TABLE_FREQ_CENTRALE_CLQ_CYL2_COLS      ( 20 )
#define TABLE_FREQ_CENTRALE_CLQ_CYL3_LNS      ( 17 )
#define TABLE_FREQ_CENTRALE_CLQ_CYL3_COLS      ( 20 )
#define TABLE_FREQ_CENTRALE_CLQ_CYL4_LNS      ( 17 )
#define TABLE_FREQ_CENTRALE_CLQ_CYL4_COLS      ( 20 )

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

extern const boolean  Autorise_clq_num;
extern const boolean  KnkAcq_bAvbmaxWinDec_ManuInh;
extern const boolean  KnkAcq_bAvDerWinDec_ManuInh;
extern const uint8  Cliq_av_corr_bkpt_map[CLIQ_AV_CORR_BKPT_MAP_COLS];
extern const uint8  Cliq_av_corr_filt_gain;
extern const uint8  Cliq_intk_vvt_err_bkpt_map[CLIQ_INTK_VVT_ERR_BKPT_MAP_COLS];
extern const uint8  Debut_fenetre_elargie;
extern const uint8  Debut_fenetre_limite;
extern const uint8  Duree_fenetre_elargie;
extern const uint8  Frequence_centrale_cliq_diag;
extern const uint8  KnkAcq_EngSpdThd_C;
extern const uint8  KnkAcq_rAirLdThd_C;
extern const uint8  Offset_debut_fenetre_defaut_VVT;
extern const uint8  Seuil_max_reg_detect_cliq;
extern const uint8  Seuil_min_reg_detect_cliq;
extern const uint8  Table_deb_clq_offset_transitoire[TABLE_DEB_CLQ_OFFSET_TRANSITOIRE_LNS][TABLE_DEB_CLQ_OFFSET_TRANSITOIRE_COLS];
extern const uint8  Table_debut_fenetre_cliquetis[TABLE_DEBUT_FENETRE_CLIQUETIS_LNS][TABLE_DEBUT_FENETRE_CLIQUETIS_COLS];
extern const uint8  Table_dec_clq_num_av_corr[TABLE_DEC_CLQ_NUM_AV_CORR_LNS][TABLE_DEC_CLQ_NUM_AV_CORR_COLS];
extern const uint8  Table_duree_fenetre_cliquetis[TABLE_DUREE_FENETRE_CLIQUETIS_COLS];
extern const uint8  Table_freq_centrale_clq_cyl1[TABLE_FREQ_CENTRALE_CLQ_CYL1_LNS][TABLE_FREQ_CENTRALE_CLQ_CYL1_COLS];
extern const uint8  Table_freq_centrale_clq_cyl2[TABLE_FREQ_CENTRALE_CLQ_CYL2_LNS][TABLE_FREQ_CENTRALE_CLQ_CYL2_COLS];
extern const uint8  Table_freq_centrale_clq_cyl3[TABLE_FREQ_CENTRALE_CLQ_CYL3_LNS][TABLE_FREQ_CENTRALE_CLQ_CYL3_COLS];
extern const uint8  Table_freq_centrale_clq_cyl4[TABLE_FREQ_CENTRALE_CLQ_CYL4_LNS][TABLE_FREQ_CENTRALE_CLQ_CYL4_COLS];
extern const uint16  Cliq_eal[CLIQ_EAL_COLS];
extern const uint16  Cliq_n[CLIQ_N_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Autorise_detection_clq;
extern boolean Knk_sen_dyn_filt_det_uavb1[KNK_SEN_DYN_FILT_DET_UAVB1_COLS];
extern boolean Knk_sens_diag_act_uavb0;
extern uint8 Debut_fenetre_cliquetis;
extern uint8 Duree_fenetre_cliquetis;
extern uint8 Frequence_centrale_passe_bande;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveCkSnOf_KnkAcq(void);
void KnkTreat_EveCkSnOn_KnkAcq(void);
void KnkTreat_EveKnk_KnkAcqLst(void);
void KnkTreat_EveRst_KnkAcq(void);
void KnkTreat_EveRTSt_KnkAcq(void);
void KnkTreat_SdlFast_KnkAcq(void);


#endif /* KNKACQ_H */

/*-------------------------------- end of file -------------------------------*/
