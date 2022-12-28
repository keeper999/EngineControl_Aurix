/***************************************************************************
;**
;** FILE NAME      : FULVL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FULVL_H
#define FULVL_H

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

extern const boolean  Flev_etat_haut_en_reserve;
extern const boolean  Flev_fuel_inc_run_manu_inh;
extern const boolean  FuLvl_bAcvDiagLoFuLvl_C;
extern const uint8  Flev_fuel_level_filtered_gain;
extern const uint8  Flev_fuel_level_inc_run_thresh;
extern const uint8  Flev_fuel_level_inc_thresh;
extern const uint8  Fuel_level_state_max;
extern const uint8  Fuel_level_state_min;
extern const uint16  Flev_fuel_level_delay;
extern const uint16  Flev_fuel_level_last_delay;
extern const uint16  Flev_low_fuel_level_sw_tempo;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Flev_fuel_level_increase;
extern boolean Flev_low_fuel_level_sw_inj;
extern boolean Flev_low_fuel_level_sw_lfbk;
extern boolean Flev_low_fuel_level_sw_mf;
extern uint8 Flev_fuel_level;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Fu_EveKOf_FuLvl(void);
void Fu_EveKOn_FuLvl(void);
void Fu_EvePwrl_FuLvl(void);
void Fu_EveRst_FuLvl(void);
void Fu_EveRTSt_FuLvl(void);
void Fu_EveRxn412_FuLvl(void);
void Fu_EveRxn612_FuLvl(void);
void Fu_EveStTR_FuLvl(void);
void Fu_SdlFast_FuLvl(void);
void Fu_SdlMid_FuLvl(void);
void Fu_SdlSlow_FuLvl(void);


#endif /* FULVL_H */

/*-------------------------------- end of file -------------------------------*/
