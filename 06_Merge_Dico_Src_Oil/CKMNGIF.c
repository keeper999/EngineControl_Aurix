/***************************************************************************
;**
;** FILE NAME      : CKMNGIF.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CKMNGIF.H"
#include "CKMNGIF_L.H"
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
const boolean  Cipd_inh_dephia = 0;
const boolean  Sync_bAcvBDCEngSpdClcn_C = 0;
const boolean  Sync_bAcvTest_CpuSfty_C = 0;
const uint8  CKMNGIF_u8Inhib = 0;
const uint8  Engine_spd_der_filter_gain = 0;
const uint8  Regime_accel_max_thresh_map[REGIME_ACCEL_MAX_THRESH_MAP_COLS] = {0};
const uint8  Table_cyl_phys_ordre_allumage[TABLE_CYL_PHYS_ORDRE_ALLUMAGE_COLS] = {0};
const uint16  Regime_moteur_max_thresh = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoHi_aEng;
boolean Ext_bDgoHi_nEng;
boolean Ext_bMonRunHi_aEng;
boolean Ext_bMonRunHi_nEng;
boolean Moteur_tournant;
boolean Sync_bRotDetEng;
uint32 CKMNGIF_u32FiltredEngSpdMem;
sint8 Engine_speed_derivate;
sint8 Engine_speed_derivate_filt;
uint8 Eng_noCmbNxtCyl;
uint8 Ext_ctTDC;
uint8 Regime_moteur_accel_max_thresh;
sint16 Ext_aEng;
uint16 CKMNGIF_u16EngSpdClcn;
uint16 CKMNGIF_u16RegimeMoteurPrev[CKMNGIF_U16REGIMEMOTEURPREV_COLS];
uint16 Compteur_de_pmh;
uint16 Duree_dent;
uint16 Ext_nEngBDC;
uint16 Ext_nEngFineResl;
uint16 Ext_nEngTDC;
uint16 Offset_reperes_ang;
uint16 Periode_angulaire;
uint16 Periode_moteur;
uint16 Periode_moteur_calc;
uint16 Periode_moteur_calc_prev;
uint16 Periode_moteur_hold;
uint16 Regime_moteur_0_125;
uint16 Regime_moteur_filtre;
uint16 Sync_agCkPosnRef1;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

