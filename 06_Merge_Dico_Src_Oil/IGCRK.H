/***************************************************************************
;**
;** FILE NAME      : IGCRK.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGCRK_H
#define IGCRK_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CRANK_IGN_ADV_MAP_LNS                 ( 9 )
#define CRANK_IGN_ADV_MAP_COLS                 ( 16 )
#define CRANK_IGN_ADV_STT_INTR_MAP_LNS        ( 9 )
#define CRANK_IGN_ADV_STT_INTR_MAP_COLS        ( 16 )
#define CRANK_IGN_ADV_STT_MAP_LNS             ( 9 )
#define CRANK_IGN_ADV_STT_MAP_COLS             ( 16 )
#define REGIME_MOTEUR_9_BKPT_MAP_COLS          ( 9 )

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

extern const uint8  Crank_ign_adv_map[CRANK_IGN_ADV_MAP_LNS][CRANK_IGN_ADV_MAP_COLS];
extern const uint8  Crank_ign_adv_STT_Intr_map[CRANK_IGN_ADV_STT_INTR_MAP_LNS][CRANK_IGN_ADV_STT_INTR_MAP_COLS];
extern const uint8  Crank_ign_adv_STT_map[CRANK_IGN_ADV_STT_MAP_LNS][CRANK_IGN_ADV_STT_MAP_COLS];
extern const uint8  Regime_moteur_9_bkpt_map[REGIME_MOTEUR_9_BKPT_MAP_COLS];
extern const uint16  IgCrk_seuil_regime_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgSys_EveBDC_IgCrk(void);
void IgSys_EveRst_IgCrk(void);
void IgSys_EveRTSt_IgCrk(void);


#endif /* IGCRK_H */

/*-------------------------------- end of file -------------------------------*/
