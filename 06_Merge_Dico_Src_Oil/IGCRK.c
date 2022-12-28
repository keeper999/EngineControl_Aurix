/***************************************************************************
;**
;** FILE NAME      : IGCRK.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGCRK.H"
#include "IGCRK_L.H"
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
const uint8  Crank_ign_adv_map[CRANK_IGN_ADV_MAP_LNS][CRANK_IGN_ADV_MAP_COLS] = {0};
const uint8  Crank_ign_adv_STT_Intr_map[CRANK_IGN_ADV_STT_INTR_MAP_LNS][CRANK_IGN_ADV_STT_INTR_MAP_COLS] = {0};
const uint8  Crank_ign_adv_STT_map[CRANK_IGN_ADV_STT_MAP_LNS][CRANK_IGN_ADV_STT_MAP_COLS] = {0};
const uint8  IGCRK_u8Inhib = 0;
const uint8  Regime_moteur_9_bkpt_map[REGIME_MOTEUR_9_BKPT_MAP_COLS] = {0};
const uint16  IgCrk_seuil_regime_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IGCRK_bAcvStructAdv_Prev;
boolean IGCRK_bIntrSTTEsHiEngSpd_Prev;
boolean IGCRK_bIntrSTTEsLoEngSpd_Prev;
boolean IGCRK_bRSAltCtlOut;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

