/***************************************************************************
;**
;** FILE NAME      : KNKDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKDIAG.H"
#include "KNKDIAG_L.H"
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
const boolean  Knk_bInhVlvCdn_KnkDgo_C = 0;
const uint8  KNKDIAG_u8Inhib = 0;
const uint8  Seuil_temp_eau_diag_k = 0;
const uint8  Seuil_throttle_diag_k = 0;
const uint16  Cliq_diag_knk_tdc_nr = 0;
const uint16  Regime_moteur_A[REGIME_MOTEUR_A_COLS] = {0};
const uint16  Seuil_defaut_capteur_k[SEUIL_DEFAUT_CAPTEUR_K_COLS] = {0};
const uint16  Seuil_regime_diag_k = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Knk_sens_diag_stt_uavs0;
boolean Knk_sens_diag_dmd_uavb0;
boolean KnkTreat_bDgoORng_KnkDiag;
boolean KnkTreat_bMonRun_KnkDiag;
uint8 Knk_sens_diag_count_uavn0;
uint16 Compteur_diag_k;
uint16 Knk_diag_noi_inc_uavn0;
uint16 Seuil_defaut_capteur;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

