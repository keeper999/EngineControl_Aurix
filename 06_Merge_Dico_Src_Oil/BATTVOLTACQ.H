/***************************************************************************
;**
;** FILE NAME      : BATTVOLTACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BATTVOLTACQ_H
#define BATTVOLTACQ_H

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

extern const boolean  Pwr_bEnaEve2ms_C;
extern const boolean  Pwr_bEnaEveInj_C;
extern const uint8  Gain_tension_batterie_filt;
extern const uint8  Pwr_rSample1_C;
extern const uint8  Pwr_rSample2_C;
extern const uint8  Pwr_rSample3_C;
extern const uint8  Pwr_rSample4_C;
extern const uint8  Pwr_rSample5_C;
extern const uint8  Seuil_filtre_anti_progression;
extern const uint8  Seuil_regime_batterie_batt_basse;
extern const uint16  B_v_slew_variation;
extern const uint16  Pwr_nEngHysThd_uBattFil_C;
extern const uint16  Pwr_nEngThd_uBattFil_C;
extern const uint16  Pwr_uBattMinSpc_C;
extern const uint16  Pwr_uBattOfsSpc_C;
extern const uint16  Tension_batterie_brute_max;
extern const uint16  Tension_batterie_brute_min;
extern const uint16  Tension_batterie_par_defaut;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Tension_batterie;
extern uint16 Tension_batterie_brute;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Pwr_EveInj_BattVotlAcq(void);
void Pwr_EveRst_BattVoltAcq(void);
void Pwr_Sdl2ms_BattVotlAcq(void);
void Pwr_SdlFast_BattVoltAcq(void);


#endif /* BATTVOLTACQ_H */

/*-------------------------------- end of file -------------------------------*/
