/***************************************************************************
;**
;** FILE NAME      : VEHST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHST_H
#define VEHST_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CRANK_TO_RUN_ENGINE_RPM_HIGH_MAP_LNS  ( 16 )
#define CRANK_TO_RUN_ENGINE_RPM_HIGH_MAP_COLS  ( 5 )
#define CRANK_TO_RUN_ENGINE_RPM_LOW_MAP_LNS   ( 16 )
#define CRANK_TO_RUN_ENGINE_RPM_LOW_MAP_COLS   ( 5 )
#define Ext_stCrk_SC                      64

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st23 */
#define VS_RUNNING                        32
#define VS_CRANKING                       64
#define VS_STALL                          128
/*extern uint8 Vehicle_active_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Manu_inh_run_to_crank;
extern const uint8  Crank_exit_delay;
extern const uint8  Crank_to_run_engine_rpm_high_map[CRANK_TO_RUN_ENGINE_RPM_HIGH_MAP_LNS][CRANK_TO_RUN_ENGINE_RPM_HIGH_MAP_COLS];
extern const uint8  Crank_to_run_engine_rpm_low_map[CRANK_TO_RUN_ENGINE_RPM_LOW_MAP_LNS][CRANK_TO_RUN_ENGINE_RPM_LOW_MAP_COLS];
extern const uint8  Demarrage_en_cours_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Vehicle_active_state;
extern boolean EngSt_CrkIp;
extern boolean Ext_bAcvInjSys;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void EngSt_EveKOn_VehSt(void);
void EngSt_EveRst_VehSt(void);
void EngSt_EveStTR_VehSt(void);
void EngSt_SdlFast_VehSt(void);
void EngSt_SdlMid_VehSt(void);


#endif /* VEHST_H */

/*-------------------------------- end of file -------------------------------*/
