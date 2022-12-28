/***************************************************************************
;**
;** FILE NAME      : CSTRMGR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRMGR_H
#define CSTRMGR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CPC_EFFECTIVE_AREA_MAP_COLS            ( 11 )
#define CPC_PURGE_DC_MAP_COLS                  ( 11 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st66 */
#define CPC_PURGE_MIN                     2
#define CPC_FULL_LOAD                     4
#define CPC_NORMAL_BOUNDING               8
#define CPC_PURGE_HOLDING                 16
#define CPC_LAMBDA_PURGE_CLOSING          32
#define CPC_GSM_PURGE_CLOSING             64
#define CPC_PURGE_CLOSED                  128
/*extern uint8 Cpc_purge_control_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Cpc_bAcvClsCanPurgSTTLbdaCdn_C;
extern const boolean  Purge_test_banc;
extern const uint8  Cpc_decreasing_ratio;
extern const uint8  Cpc_diff_purge_ratio_thresh;
extern const uint8  Cpc_full_load_purge_rco;
extern const uint8  Cpc_min_purge_rco;
extern const uint8  Cpc_purge_dc_map[CPC_PURGE_DC_MAP_COLS];
extern const uint8  Cpc_purge_inh_high_lambda_thresh;
extern const uint8  Cpc_purge_inh_low_lambda_thresh;
extern const uint8  Cpc_test_bed_purge_rco;
extern const sint16  Cpc_water_temp_thresh;
extern const uint16  Cpc_effective_area_map[CPC_EFFECTIVE_AREA_MAP_COLS];
extern const uint16  Cpc_purge_ratio_step_min;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Cpc_purge_control_state;
extern boolean Demande_purge_dormant;
extern boolean OxC_bMonIntrPurgeCdn;
extern uint8 Rco_applique_purge;
extern uint8 Rco_demande_purge;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Cstr_EveKOf_CstrMgr(void);
void Cstr_EveRst_CstrMgr(void);
void Cstr_SdlMid_CstrMgr(void);


#endif /* CSTRMGR_H */

/*-------------------------------- end of file -------------------------------*/
