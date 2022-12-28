/***************************************************************************
;**
;** FILE NAME      : HEATSENO2HOTDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2HOTDIAG.H"
#include "HEATSENO2HOTDIAG_L.H"
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
const boolean  HeatSenO2_bAcvEuro6DsHeat_C = 0;
const boolean  HeatSenO2_bAcvEuro6UsHeat_C = 0;
const uint32  HeatSenO2_tiInhDsDiag_C = 0;
const uint32  HeatSenO2_tiInhUsDiag_C = 0;
const uint8  HEATSENO2HOTDIAG_u8Inhib = 0;
const uint16  Cata_temp_bkpt_map[CATA_TEMP_BKPT_MAP_COLS] = {0};
const uint16  Ds_heat_seuil_cata_temp_g_map[DS_HEAT_SEUIL_CATA_TEMP_G_MAP_COLS] = {0};
const uint16  Ds_heat_seuil_cata_temp_map[DS_HEAT_SEUIL_CATA_TEMP_MAP_COLS] = {0};
const uint16  Ds_heat_transit_delay_c = 0;
const uint16  Exhaust_gas_temp_bkpt_map[EXHAUST_GAS_TEMP_BKPT_MAP_COLS] = {0};
const uint16  Us_heat_seuil_ex_gas_temp_g_map[US_HEAT_SEUIL_EX_GAS_TEMP_G_MAP_COLS] = {0};
const uint16  Us_heat_seuil_ex_gas_temp_map[US_HEAT_SEUIL_EX_GAS_TEMP_MAP_COLS] = {0};
const uint16  Us_heat_transit_delay_c = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Autorise_diag_ds_heat;
boolean Autorise_diag_us_heat;
boolean HeatSenO2_bDgoORng_DsHeat;
boolean HeatSenO2_bDgoORng_UsHeat;
boolean HeatSenO2_bMonRunORng_DsHeat;
boolean HeatSenO2_bMonRunORng_UsHeat;
uint32 HeatSenO2_tiInhDsDiag;
uint32 HeatSenO2_tiInhUsDiag;
uint8 HEATSENO2HOTDIAG_u8ExtStSsGasPrv;
uint16 Ds_heat_transit_count;
uint16 HeatSenO2_DsFacMax_Obd6Mod;
uint16 HeatSenO2_DsFacMaxRaw;
uint16 HeatSenO2_DsFacMes_Obd6Mod;
uint16 HeatSenO2_DsFacMesRaw;
uint16 HeatSenO2_UsFacMax_Obd6Mod;
uint16 HeatSenO2_UsFacMaxRaw;
uint16 HeatSenO2_UsFacMes_Obd6Mod;
uint16 HeatSenO2_UsFacMesRaw;
uint16 Us_heat_transit_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

