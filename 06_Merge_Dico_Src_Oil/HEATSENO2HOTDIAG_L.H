/***************************************************************************
;**
;** FILE NAME      : HEATSENO2HOTDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2HOTDIAG_L_H
#define HEATSENO2HOTDIAG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  HEATSENO2HOTDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Autorise_diag_ds_heat;
extern boolean Autorise_diag_us_heat;
extern boolean HeatSenO2_bDgoORng_DsHeat;
extern boolean HeatSenO2_bDgoORng_UsHeat;
extern boolean HeatSenO2_bMonRunORng_DsHeat;
extern boolean HeatSenO2_bMonRunORng_UsHeat;
extern uint32 HeatSenO2_tiInhDsDiag;
extern uint32 HeatSenO2_tiInhUsDiag;
extern uint8 HEATSENO2HOTDIAG_u8ExtStSsGasPrv;
extern uint16 Ds_heat_transit_count;
extern uint16 HeatSenO2_DsFacMaxRaw;
extern uint16 HeatSenO2_DsFacMesRaw;
extern uint16 HeatSenO2_UsFacMaxRaw;
extern uint16 HeatSenO2_UsFacMesRaw;
extern uint16 Us_heat_transit_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2HOTDIAG_vidDsHDiagCalc(void);
void HEATSENO2HOTDIAG_vidDsHDiagCond(void);
void HEATSENO2HOTDIAG_vidDsheat(void);
void HEATSENO2HOTDIAG_vidDsHeat_Euro6(void);
void HEATSENO2HOTDIAG_vidInit(void);
void HEATSENO2HOTDIAG_vidInitCbModTrn(void);
void HEATSENO2HOTDIAG_vidInitOutput(void);
void HEATSENO2HOTDIAG_vidTgInitCbMdTn(void);
void HEATSENO2HOTDIAG_vidUsHDiagCalc(void);
void HEATSENO2HOTDIAG_vidUsHDiagCond(void);
void HEATSENO2HOTDIAG_vidUsheat(void);
void HEATSENO2HOTDIAG_vidUsHeat_Euro6(void);


#endif /* HEATSENO2HOTDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
