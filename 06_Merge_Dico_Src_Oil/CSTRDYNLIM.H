/***************************************************************************
;**
;** FILE NAME      : CSTRDYNLIM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRDYNLIM_H
#define CSTRDYNLIM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CPC_FPW_LIM_MAX_MFR_MAX_VAL       65535
#define CPC_FUEL_CONSTRAINT_MAX_MAP_LNS       ( 9 )
#define CPC_FUEL_CONSTRAINT_MAX_MAP_COLS       ( 9 )
#define CPC_LIM_MAX_PURGE_RATIO_MAX_VAL   65535
#define CPC_PURGE_RATE_GAIN_MAP_COLS           ( 9 )
#define CPC_PURGE_RATE_GAIN_STT_MAP_COLS       ( 9 )

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

extern const boolean  Cpc_bAcvClsCanPurgSTTRamp_C;
extern const uint8  Cpc_fuel_constraint_max_map[CPC_FUEL_CONSTRAINT_MAX_MAP_LNS][CPC_FUEL_CONSTRAINT_MAX_MAP_COLS];
extern const uint8  Cpc_max_amfr_thresh;
extern const uint8  Cpc_max_purge_ratio_max_step;
extern const uint8  Cpc_max_purge_ratio_max_step_stt;
extern const uint8  Cpc_min_fuel_pulse_width;
extern const uint16  Cpc_cat_diag_max_purge_ratio;
extern const uint16  Cpc_purge_rate_gain_map[CPC_PURGE_RATE_GAIN_MAP_COLS];
extern const uint16  Cpc_purge_rate_gain_stt_map[CPC_PURGE_RATE_GAIN_STT_MAP_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Cpc_constraints_max_purge_ratio;
extern uint16 Cpc_current_purge_ratio;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Cstr_EveRst_CstrDynLim(void);
void Cstr_SdlMid_CstrDynLim(void);


#endif /* CSTRDYNLIM_H */

/*-------------------------------- end of file -------------------------------*/
