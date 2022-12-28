/***************************************************************************
;**
;** FILE NAME      : KNKDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKDIAG_H
#define KNKDIAG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define REGIME_MOTEUR_A_COLS                   ( 8 )
#define SEUIL_DEFAUT_CAPTEUR_K_COLS            ( 8 )

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

extern const boolean  Knk_bInhVlvCdn_KnkDgo_C;
extern const uint8  Seuil_temp_eau_diag_k;
extern const uint8  Seuil_throttle_diag_k;
extern const uint16  Cliq_diag_knk_tdc_nr;
extern const uint16  Regime_moteur_A[REGIME_MOTEUR_A_COLS];
extern const uint16  Seuil_defaut_capteur_k[SEUIL_DEFAUT_CAPTEUR_K_COLS];
extern const uint16  Seuil_regime_diag_k;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Knk_sens_diag_dmd_uavb0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKDIAG_vidEntryInit(void);
void KnkTreat_EveKnk_KnkDiag(void);


#endif /* KNKDIAG_H */

/*-------------------------------- end of file -------------------------------*/
