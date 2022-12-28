/***************************************************************************
;**
;** FILE NAME      : KNKACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKACQ.H"
#include "KNKACQ_L.H"
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
const boolean  Autorise_clq_num = 0;
const boolean  KnkAcq_bAvbmaxWinDec_ManuInh = 0;
const boolean  KnkAcq_bAvDerWinDec_ManuInh = 0;
const uint8  Cliq_av_corr_bkpt_map[CLIQ_AV_CORR_BKPT_MAP_COLS] = {0};
const uint8  Cliq_av_corr_filt_gain = 0;
const uint8  Cliq_intk_vvt_err_bkpt_map[CLIQ_INTK_VVT_ERR_BKPT_MAP_COLS] = {0};
const uint8  Debut_fenetre_elargie = 0;
const uint8  Debut_fenetre_limite = 0;
const uint8  Duree_fenetre_elargie = 0;
const uint8  Frequence_centrale_cliq_diag = 0;
const uint8  KnkAcq_EngSpdThd_C = 0;
const uint8  KnkAcq_rAirLdThd_C = 0;
const uint8  KNKACQ_u8Inhib = 0;
const uint8  Offset_debut_fenetre_defaut_VVT = 0;
const uint8  Seuil_max_reg_detect_cliq = 0;
const uint8  Seuil_min_reg_detect_cliq = 0;
const uint8  Table_deb_clq_offset_transitoire[TABLE_DEB_CLQ_OFFSET_TRANSITOIRE_LNS][TABLE_DEB_CLQ_OFFSET_TRANSITOIRE_COLS] = {0};
const uint8  Table_debut_fenetre_cliquetis[TABLE_DEBUT_FENETRE_CLIQUETIS_LNS][TABLE_DEBUT_FENETRE_CLIQUETIS_COLS] = {0};
const uint8  Table_dec_clq_num_av_corr[TABLE_DEC_CLQ_NUM_AV_CORR_LNS][TABLE_DEC_CLQ_NUM_AV_CORR_COLS] = {0};
const uint8  Table_duree_fenetre_cliquetis[TABLE_DUREE_FENETRE_CLIQUETIS_COLS] = {0};
const uint8  Table_freq_centrale_clq_cyl1[TABLE_FREQ_CENTRALE_CLQ_CYL1_LNS][TABLE_FREQ_CENTRALE_CLQ_CYL1_COLS] = {0};
const uint8  Table_freq_centrale_clq_cyl2[TABLE_FREQ_CENTRALE_CLQ_CYL2_LNS][TABLE_FREQ_CENTRALE_CLQ_CYL2_COLS] = {0};
const uint8  Table_freq_centrale_clq_cyl3[TABLE_FREQ_CENTRALE_CLQ_CYL3_LNS][TABLE_FREQ_CENTRALE_CLQ_CYL3_COLS] = {0};
const uint8  Table_freq_centrale_clq_cyl4[TABLE_FREQ_CENTRALE_CLQ_CYL4_LNS][TABLE_FREQ_CENTRALE_CLQ_CYL4_COLS] = {0};
const uint16  Cliq_eal[CLIQ_EAL_COLS] = {0};
const uint16  Cliq_n[CLIQ_N_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Autorise_detection_clq;
boolean Knk_sen_dyn_filt_det_uavb1[KNK_SEN_DYN_FILT_DET_UAVB1_COLS];
boolean Knk_sens_diag_act_uavb0;
uint32 KNKACQ_u32CliqAvCorAdptKFiltMem;
uint8 Cliq_av_corr_prev_adpt_k;
uint8 Debut_fenetre_cliquetis;
uint8 Duree_fenetre_cliquetis;
uint8 Frequence_centrale_passe_bande;
uint8 Table_freq_centrale_cyl1_sdl;
uint8 Table_freq_centrale_cyl1_win;
uint8 Table_freq_centrale_cyl2_sdl;
uint8 Table_freq_centrale_cyl2_win;
uint8 Table_freq_centrale_cyl3_sdl;
uint8 Table_freq_centrale_cyl3_win;
uint8 Table_freq_centrale_cyl4_sdl;
uint8 Table_freq_centrale_cyl4_win;
uint16 Charge_chgt_freq_cliq;
uint16 Regime_chgt_freq_cliq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

