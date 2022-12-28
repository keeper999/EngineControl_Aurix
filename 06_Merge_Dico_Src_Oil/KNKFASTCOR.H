/***************************************************************************
;**
;** FILE NAME      : KNKFASTCOR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKFASTCOR_H
#define KNKFASTCOR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CLIQ_COR_BOUCLE_RAPIDE_DEC_MAP_COLS    ( 16 )
#define CLIQ_PAS_BOUCLE_RAPIDE_MAP_LNS        ( 16 )
#define CLIQ_PAS_BOUCLE_RAPIDE_MAP_COLS        ( 8 )
#define CLIQUETIS_COR_AVANCE_COLS              ( 4 )
#define CORRECTION_BOUCLE_RAPIDE_COLS          ( 4 )
#define CORRECTION_MAX_RAPIDE_MAP_LNS         ( 16 )
#define CORRECTION_MAX_RAPIDE_MAP_COLS         ( 8 )
#define DUREE_CORRECTION_SUPERCLIQ_MAP_COLS    ( 16 )
#define DUREE_DECREM_BOUCLE_RAPIDE_MAP_LNS    ( 16 )
#define DUREE_DECREM_BOUCLE_RAPIDE_MAP_COLS    ( 8 )
#define DUREE_MAINTIEN_BOUCLE_RAPIDE_MAP_COLS  ( 16 )
#define IGLIM_RAIRLD_A_COLS                    ( 8 )
#define KNKMGT_PRM_AGIGKNKDETOFSCYL_COLS       ( 6 )
#define SUPERCLIQ_PAS_BOUCLRAPIDE_MAP_LNS     ( 16 )
#define SUPERCLIQ_PAS_BOUCLRAPIDE_MAP_COLS     ( 8 )

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

extern const boolean  Cliquetis_cor_avance_type;
extern const uint8  Cliq_cor_boucle_rapide_dec_map[CLIQ_COR_BOUCLE_RAPIDE_DEC_MAP_COLS];
extern const uint8  Cliq_pas_boucle_rapide_map[CLIQ_PAS_BOUCLE_RAPIDE_MAP_LNS][CLIQ_PAS_BOUCLE_RAPIDE_MAP_COLS];
extern const uint8  Cliquetis_cor_avance_defaut;
extern const uint8  Cliquetis_cor_avance_delay;
extern const uint8  Correction_max_rapide_map[CORRECTION_MAX_RAPIDE_MAP_LNS][CORRECTION_MAX_RAPIDE_MAP_COLS];
extern const uint8  Duree_correction_superCliq_map[DUREE_CORRECTION_SUPERCLIQ_MAP_COLS];
extern const uint8  Duree_decrem_boucle_rapide_map[DUREE_DECREM_BOUCLE_RAPIDE_MAP_LNS][DUREE_DECREM_BOUCLE_RAPIDE_MAP_COLS];
extern const uint8  Duree_maintien_boucle_rapide_map[DUREE_MAINTIEN_BOUCLE_RAPIDE_MAP_COLS];
extern const uint8  FastCor_agFastCorLoopOfs_C;
extern const uint8  Gain_filtre_cor_avance;
extern const uint8  Gain_filtre_cor_boucle_rapide;
extern const uint8  SuperCliq_pas_bouclRapide_map[SUPERCLIQ_PAS_BOUCLRAPIDE_MAP_LNS][SUPERCLIQ_PAS_BOUCLRAPIDE_MAP_COLS];
extern const uint16  IgLim_rAirLd_A[IGLIM_RAIRLD_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Cliquetis_cor_avance[CLIQUETIS_COR_AVANCE_COLS];
extern uint8 Correction_boucle_rapide[CORRECTION_BOUCLE_RAPIDE_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgLim_EveBDC_FastCor(void);
void IgLim_EveCrTR_FastCor(void);
void IgLim_EveRst_FastCor(void);
void IgLim_EveRTCr_FastCor(void);


#endif /* KNKFASTCOR_H */

/*-------------------------------- end of file -------------------------------*/
