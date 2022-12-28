/***************************************************************************
;**
;** FILE NAME      : KNKFASTCOR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKFASTCOR.H"
#include "KNKFASTCOR_L.H"
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
const boolean  Cliquetis_cor_avance_type = 0;
const uint8  Cliq_cor_boucle_rapide_dec_map[CLIQ_COR_BOUCLE_RAPIDE_DEC_MAP_COLS] = {0};
const uint8  Cliq_pas_boucle_rapide_map[CLIQ_PAS_BOUCLE_RAPIDE_MAP_LNS][CLIQ_PAS_BOUCLE_RAPIDE_MAP_COLS] = {0};
const uint8  Cliquetis_cor_avance_defaut = 0;
const uint8  Cliquetis_cor_avance_delay = 0;
const uint8  Correction_max_rapide_map[CORRECTION_MAX_RAPIDE_MAP_LNS][CORRECTION_MAX_RAPIDE_MAP_COLS] = {0};
const uint8  Duree_correction_superCliq_map[DUREE_CORRECTION_SUPERCLIQ_MAP_COLS] = {0};
const uint8  Duree_decrem_boucle_rapide_map[DUREE_DECREM_BOUCLE_RAPIDE_MAP_LNS][DUREE_DECREM_BOUCLE_RAPIDE_MAP_COLS] = {0};
const uint8  Duree_maintien_boucle_rapide_map[DUREE_MAINTIEN_BOUCLE_RAPIDE_MAP_COLS] = {0};
const uint8  FastCor_agFastCorLoopOfs_C = 0;
const uint8  Gain_filtre_cor_avance = 0;
const uint8  Gain_filtre_cor_boucle_rapide = 0;
const uint8  KNKFASTCOR_u8Inhib = 0;
const uint8  SuperCliq_pas_bouclRapide_map[SUPERCLIQ_PAS_BOUCLRAPIDE_MAP_LNS][SUPERCLIQ_PAS_BOUCLRAPIDE_MAP_COLS] = {0};
const uint16  IgLim_rAirLd_A[IGLIM_RAIRLD_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean KnkMgt_bSuperKnkCurCyl;
uint8 Cliquetis_cor_avance[CLIQUETIS_COR_AVANCE_COLS];
uint8 Cliquetis_cor_avance_count;
uint8 Correction_boucle_rapide[CORRECTION_BOUCLE_RAPIDE_COLS];
uint8 Correction_boucle_rapide_Cyl1;
uint8 Correction_boucle_rapide_Cyl2;
uint8 Correction_boucle_rapide_Cyl3;
uint8 Correction_boucle_rapide_Cyl4;
uint8 Correction_max_rapide;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_1;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_2;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_3;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_4;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_5;
uint8 KnkMgt_prm_agIgKnkDetOfsCyl_6;
uint8 Tempo_boucle_rapide[TEMPO_BOUCLE_RAPIDE_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

