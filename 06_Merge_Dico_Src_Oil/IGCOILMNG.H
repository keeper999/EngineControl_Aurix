/***************************************************************************
;**
;** FILE NAME      : IGCOILMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGCOILMNG_H
#define IGCOILMNG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENGINE_LOAD_BKPT_BOBINE_COLS           ( 12 )
#define ICD_RATIO_ENERGY_MAP_LNS              ( 9 )
#define ICD_RATIO_ENERGY_MAP_COLS              ( 6 )
#define ICD_RATIO_ENERGY_MAP_2_LNS            ( 9 )
#define ICD_RATIO_ENERGY_MAP_2_COLS            ( 6 )
#define ICD_RATIO_ENERGY_MAP_REGLD_LNS        ( 11 )
#define ICD_RATIO_ENERGY_MAP_REGLD_COLS        ( 12 )
#define IGNHAL_udtMODE_ADAP               2
#define IGNHAL_udtMODE_FIXED              1
#define REGIME_MOTEUR_BKPT_2_BOBINE_COLS       ( 11 )
#define REGIME_MOTEUR_BKPT_BOBINE_COLS         ( 9 )
#define TABLE_DWELL_DEM_LNS                   ( 6 )
#define TABLE_DWELL_DEM_COLS                   ( 16 )
#define TEMPERATURE_EAU_2_BKPT_MAP_COLS        ( 6 )
#define TENSION_BATTERIE_BKPT_16PTS_COLS       ( 16 )
#define TENSION_BATTERIE_BKPT_BOBINE_COLS      ( 6 )

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

extern const boolean  Manu_coupure_bob_1;
extern const boolean  Manu_coupure_bob_2;
extern const boolean  Manu_coupure_bob_3;
extern const boolean  Manu_coupure_bob_4;
extern const uint8  Icd_energy_ratio_nom;
extern const uint8  Icd_ratio_energy_map[ICD_RATIO_ENERGY_MAP_LNS][ICD_RATIO_ENERGY_MAP_COLS];
extern const uint8  Icd_ratio_energy_map_2[ICD_RATIO_ENERGY_MAP_2_LNS][ICD_RATIO_ENERGY_MAP_2_COLS];
extern const uint8  Icd_ratio_energy_map_RegLd[ICD_RATIO_ENERGY_MAP_REGLD_LNS][ICD_RATIO_ENERGY_MAP_REGLD_COLS];
extern const uint8  Icd_water_temp_thresh;
extern const uint8  Regime_dwell_demarrage_hyst_bas;
extern const uint8  Regime_dwell_demarrage_hyst_haut;
extern const uint8  SenAct_tIGBTAcqHyst_C;
extern const uint8  SenAct_tIGBTAcqMax_C;
extern const uint8  Temperature_eau_2_bkpt_map[TEMPERATURE_EAU_2_BKPT_MAP_COLS];
extern const uint16  Engine_load_bkpt_bobine[ENGINE_LOAD_BKPT_BOBINE_COLS];
extern const uint16  Icd_max_current_coils;
extern const uint16  Regime_moteur_bkpt_2_bobine[REGIME_MOTEUR_BKPT_2_BOBINE_COLS];
extern const uint16  Regime_moteur_bkpt_bobine[REGIME_MOTEUR_BKPT_BOBINE_COLS];
extern const uint16  Table_dwell_dem[TABLE_DWELL_DEM_LNS][TABLE_DWELL_DEM_COLS];
extern const uint16  Tension_batterie_bkpt_16pts[TENSION_BATTERIE_BKPT_16PTS_COLS];
extern const uint16  Tension_batterie_bkpt_bobine[TENSION_BATTERIE_BKPT_BOBINE_COLS];

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

void IgCmd_EveCkSnOf_IgCoilMng(void);
void IgCmd_EveICD_IgCoilMng(void);
void IgCmd_EveRst_IgCoilMng(void);
void IgCmd_EveStTR_IgCoilMng(void);
void IgCmd_EveSyncAccu_IgCoilMng(void);
void IgCmd_SdlFast_IgCoilMng(void);
void IgCmd_SdlSlow_IgCoilMng(void);
void IgSys_EveCkSnOn_IgCoilMng(void);


#endif /* IGCOILMNG_H */

/*-------------------------------- end of file -------------------------------*/
