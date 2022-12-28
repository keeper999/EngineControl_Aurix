/***************************************************************************
;**
;** FILE NAME      : KNKRBLACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKRBLACQ_H
#define KNKRBLACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TABLE_DEB_RBL_OFFSET_TRANSITOIRE_LNS  ( 17 )
#define TABLE_DEB_RBL_OFFSET_TRANSITOIRE_COLS  ( 10 )
#define TABLE_DEBUT_FENETRE_RUMBLE_LNS        ( 17 )
#define TABLE_DEBUT_FENETRE_RUMBLE_COLS        ( 20 )
#define TABLE_DEC_RBL_NUM_AV_CORR_LNS         ( 10 )
#define TABLE_DEC_RBL_NUM_AV_CORR_COLS         ( 20 )

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

extern const boolean  Autorise_rbl_num;
extern const boolean  KnkRblAcq_bAvbmaxWinDec_ManuInh;
extern const boolean  KnkRblAcq_bAvDerWinDec_ManuInh;
extern const uint8  Debut_fenetre_limite_rbl;
extern const uint8  KNKRBLACQ_u8Inhib;
extern const uint8  Seuil_max_reg_detect_rbl;
extern const uint8  Seuil_min_reg_detect_rbl;
extern const uint8  Table_deb_rbl_offset_transitoire[TABLE_DEB_RBL_OFFSET_TRANSITOIRE_LNS][TABLE_DEB_RBL_OFFSET_TRANSITOIRE_COLS];
extern const uint8  Table_debut_fenetre_rumble[TABLE_DEBUT_FENETRE_RUMBLE_LNS][TABLE_DEBUT_FENETRE_RUMBLE_COLS];
extern const uint8  Table_dec_rbl_num_av_corr[TABLE_DEC_RBL_NUM_AV_CORR_LNS][TABLE_DEC_RBL_NUM_AV_CORR_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Autorise_detection_rbl;
extern uint8 Debut_fenetre_rumble;
extern uint8 Duree_fenetre_rumble;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveCkSnOf_KnkRblAcq(void);
void KnkTreat_EveCkSnOn_KnkRblAcq(void);
void KnkTreat_EveRbl_KnkRblAcqLst(void);
void KnkTreat_EveRst_KnkRblAcq(void);
void KnkTreat_EveRTSt_KnkRblAcq(void);
void KnkTreat_SdlFast_KnkRblAcq(void);


#endif /* KNKRBLACQ_H */

/*-------------------------------- end of file -------------------------------*/
