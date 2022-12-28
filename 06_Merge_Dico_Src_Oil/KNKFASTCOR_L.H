/***************************************************************************
;**
;** FILE NAME      : KNKFASTCOR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKFASTCOR_L_H
#define KNKFASTCOR_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNKFASTCOR_u32ARRAY_LENGTH        4
#define TEMPO_BOUCLE_RAPIDE_COLS               ( 4 )

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

extern const uint8  KNKFASTCOR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean KnkMgt_bSuperKnkCurCyl;
extern uint8 Cliquetis_cor_avance_count;
extern uint8 Correction_boucle_rapide_Cyl1;
extern uint8 Correction_boucle_rapide_Cyl2;
extern uint8 Correction_boucle_rapide_Cyl3;
extern uint8 Correction_boucle_rapide_Cyl4;
extern uint8 Correction_max_rapide;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_1;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_2;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_3;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_4;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_5;
extern uint8 KnkMgt_prm_agIgKnkDetOfsCyl_6;
extern uint8 Tempo_boucle_rapide[TEMPO_BOUCLE_RAPIDE_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKFASTCOR_vidCorNotInGearChange(void);
void KNKFASTCOR_vidCorrInGearChange(void);
void KNKFASTCOR_vidDecrementation(void);
void KNKFASTCOR_vidFastCorrDecre(void);
void KNKFASTCOR_vidFastCorrection(void);
void KNKFASTCOR_vidFastCorrectionCalc(void);
void KNKFASTCOR_vidFastCorrIncre(void);
void KNKFASTCOR_vidFastCorrOnCritZone(void);
void KNKFASTCOR_vidFastCorrOutCritZon(void);
void KNKFASTCOR_vidInitOutput(void);
void KNKFASTCOR_vidUncertainPhase(void);


#endif /* KNKFASTCOR_L_H */

/*-------------------------------- end of file -------------------------------*/
