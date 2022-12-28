/***************************************************************************
;**
;** FILE NAME      : KNKRBLACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKRBLACQ.H"
#include "KNKRBLACQ_L.H"
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
const boolean  Autorise_rbl_num = 0;
const boolean  KnkRblAcq_bAvbmaxWinDec_ManuInh = 0;
const boolean  KnkRblAcq_bAvDerWinDec_ManuInh = 0;
const uint8  Debut_fenetre_limite_rbl = 0;
const uint8  KNKRBLACQ_u8Inhib = 0;
const uint8  Seuil_max_reg_detect_rbl = 0;
const uint8  Seuil_min_reg_detect_rbl = 0;
const uint8  Table_deb_rbl_offset_transitoire[TABLE_DEB_RBL_OFFSET_TRANSITOIRE_LNS][TABLE_DEB_RBL_OFFSET_TRANSITOIRE_COLS] = {0};
const uint8  Table_debut_fenetre_rumble[TABLE_DEBUT_FENETRE_RUMBLE_LNS][TABLE_DEBUT_FENETRE_RUMBLE_COLS] = {0};
const uint8  Table_dec_rbl_num_av_corr[TABLE_DEC_RBL_NUM_AV_CORR_LNS][TABLE_DEC_RBL_NUM_AV_CORR_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Autorise_detection_rbl;
uint32 KNKRBLACQ_u32FilterOutputMem;
uint8 Debut_fenetre_rumble;
uint8 Duree_fenetre_rumble;
uint8 KNKRBLACQ_u8RblFilterInput;
uint8 KNKRBLACQ_u8SdlFilterInput;
uint8 Rbl_av_corr_prev_adpt_k;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

