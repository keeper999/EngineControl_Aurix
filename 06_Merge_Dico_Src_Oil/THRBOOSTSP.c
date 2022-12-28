/***************************************************************************
;**
;** FILE NAME      : THRBOOSTSP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRBOOSTSP.H"
#include "THRBOOSTSP_L.H"
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
const boolean  Dtc_throt_pos_ref_boost_manu_inh = 0;
const uint8  Dtc_throt_pos_ref_boost_gain_map[DTC_THROT_POS_REF_BOOST_GAIN_MAP_COLS] = {0};
const uint8  THRBOOSTSP_u8Inhib = 0;
const uint16  Dtc_max_distance_to_limp_home = 0;
const uint16  Dtc_throt_pos_ref_raw_bkpt[DTC_THROT_POS_REF_RAW_BKPT_COLS] = {0};
const uint16  Dtc_throttle_pos_ref_raw_max_var = 0;
const uint16  Dtc_throttle_pos_ref_raw_min_var = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Dtc_throt_pos_ref_boost_enable;
sint16 Dtc_throttle_pos_ref_raw_deriv;
uint16 Dtc_position_ref_raw_prev;
uint16 Dtc_throt_pos_ref_boost_temp;
uint16 Dtc_throt_pos_ref_raw_abs_deriv;
uint16 Dtc_throttle_pos_ref_raw_drv_uw;
uint16 Dtc_throttle_position_reference;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

