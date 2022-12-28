/***************************************************************************
;**
;** FILE NAME      : IGCOILMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGCOILMNG.H"
#include "IGCOILMNG_L.H"
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
const boolean  Manu_coupure_bob_1 = 0;
const boolean  Manu_coupure_bob_2 = 0;
const boolean  Manu_coupure_bob_3 = 0;
const boolean  Manu_coupure_bob_4 = 0;
const uint8  Icd_energy_ratio_nom = 0;
const uint8  Icd_ratio_energy_map[ICD_RATIO_ENERGY_MAP_LNS][ICD_RATIO_ENERGY_MAP_COLS] = {0};
const uint8  Icd_ratio_energy_map_2[ICD_RATIO_ENERGY_MAP_2_LNS][ICD_RATIO_ENERGY_MAP_2_COLS] = {0};
const uint8  Icd_ratio_energy_map_RegLd[ICD_RATIO_ENERGY_MAP_REGLD_LNS][ICD_RATIO_ENERGY_MAP_REGLD_COLS] = {0};
const uint8  Icd_water_temp_thresh = 0;
const uint8  IGCOILMNG_u8Inhib = 0;
const uint8  Regime_dwell_demarrage_hyst_bas = 0;
const uint8  Regime_dwell_demarrage_hyst_haut = 0;
const uint8  SenAct_tIGBTAcqHyst_C = 0;
const uint8  SenAct_tIGBTAcqMax_C = 0;
const uint8  Temperature_eau_2_bkpt_map[TEMPERATURE_EAU_2_BKPT_MAP_COLS] = {0};
const uint16  Engine_load_bkpt_bobine[ENGINE_LOAD_BKPT_BOBINE_COLS] = {0};
const uint16  Icd_max_current_coils = 0;
const uint16  Regime_moteur_bkpt_2_bobine[REGIME_MOTEUR_BKPT_2_BOBINE_COLS] = {0};
const uint16  Regime_moteur_bkpt_bobine[REGIME_MOTEUR_BKPT_BOBINE_COLS] = {0};
const uint16  Table_dwell_dem[TABLE_DWELL_DEM_LNS][TABLE_DWELL_DEM_COLS] = {0};
const uint16  Tension_batterie_bkpt_16pts[TENSION_BATTERIE_BKPT_16PTS_COLS] = {0};
const uint16  Tension_batterie_bkpt_bobine[TENSION_BATTERIE_BKPT_BOBINE_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
boolean IgCmd_bInhIgCoilCmd;
boolean IgCmd_bInhIgCoilNxtCmd;
boolean IGCOILMNG_bIGBTAcqOuthyst;
uint8 IgCmd_stCurIgCoil;
uint8 IgCmd_stCurNxtIgCoil;
uint8 Ign_mode_status;
uint16 Icd_desired_current;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

