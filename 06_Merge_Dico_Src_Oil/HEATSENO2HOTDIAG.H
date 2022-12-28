/***************************************************************************
;**
;** FILE NAME      : HEATSENO2HOTDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2HOTDIAG_H
#define HEATSENO2HOTDIAG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CATA_TEMP_BKPT_MAP_COLS                ( 10 )
#define DS_HEAT_SEUIL_CATA_TEMP_G_MAP_COLS     ( 10 )
#define DS_HEAT_SEUIL_CATA_TEMP_MAP_COLS       ( 10 )
#define EXHAUST_GAS_TEMP_BKPT_MAP_COLS         ( 10 )
#define US_HEAT_SEUIL_EX_GAS_TEMP_G_MAP_COLS   ( 10 )
#define US_HEAT_SEUIL_EX_GAS_TEMP_MAP_COLS     ( 10 )

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

extern const boolean  HeatSenO2_bAcvEuro6DsHeat_C;
extern const boolean  HeatSenO2_bAcvEuro6UsHeat_C;
extern const uint32  HeatSenO2_tiInhDsDiag_C;
extern const uint32  HeatSenO2_tiInhUsDiag_C;
extern const uint16  Cata_temp_bkpt_map[CATA_TEMP_BKPT_MAP_COLS];
extern const uint16  Ds_heat_seuil_cata_temp_g_map[DS_HEAT_SEUIL_CATA_TEMP_G_MAP_COLS];
extern const uint16  Ds_heat_seuil_cata_temp_map[DS_HEAT_SEUIL_CATA_TEMP_MAP_COLS];
extern const uint16  Ds_heat_transit_delay_c;
extern const uint16  Exhaust_gas_temp_bkpt_map[EXHAUST_GAS_TEMP_BKPT_MAP_COLS];
extern const uint16  Us_heat_seuil_ex_gas_temp_g_map[US_HEAT_SEUIL_EX_GAS_TEMP_G_MAP_COLS];
extern const uint16  Us_heat_seuil_ex_gas_temp_map[US_HEAT_SEUIL_EX_GAS_TEMP_MAP_COLS];
extern const uint16  Us_heat_transit_delay_c;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 HeatSenO2_DsFacMax_Obd6Mod;
extern uint16 HeatSenO2_DsFacMes_Obd6Mod;
extern uint16 HeatSenO2_UsFacMax_Obd6Mod;
extern uint16 HeatSenO2_UsFacMes_Obd6Mod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_EveRst_HeatSenO2Mon(void);
void HeatSenO2_SdlFast_HeatSenO2Mon(void);


#endif /* HEATSENO2HOTDIAG_H */

/*-------------------------------- end of file -------------------------------*/
