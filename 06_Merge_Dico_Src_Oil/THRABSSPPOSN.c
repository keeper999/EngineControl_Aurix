/***************************************************************************
;**
;** FILE NAME      : THRABSSPPOSN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRABSSPPOSN.H"
#include "THRABSSPPOSN_L.H"
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
const boolean  Tpac_closed_throttle_manu_inh = 0;
const uint8  THRABSSPPOSN_u8Inhib = 0;
const uint8  Tpac_ecu_temp_thresh_cold = 0;
const uint8  Tpac_ecu_temp_thresh_warm = 0;
const uint16  Thr_FLrnClCtl_posnHiThruRise_C = 0;
const uint16  Thr_FLrnClCtl_posnLoThruLowr_C = 0;
const uint16  Tpac_throttle_closed_thresh = 0;
const uint16  Tpac_throttle_open_thresh_cold = 0;
const uint16  Tpac_throttle_open_thresh_warm = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Tpac_ecu_temp_protect_mode;
boolean Tpac_ecu_temp_protected;
uint16 Ssm_closed_throttle_pos_tmp;
uint16 Ssm_open_throttle_pos_tmp;
uint16 Tpac_throttle_open_thresh;
uint16 Tpac_throttle_position_reference;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

