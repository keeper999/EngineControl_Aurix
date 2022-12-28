/***************************************************************************
;**
;** FILE NAME      : THRBOOSTSP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRBOOSTSP_H
#define THRBOOSTSP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DTC_THROT_POS_REF_BOOST_GAIN_MAP_COLS  ( 7 )
#define DTC_THROT_POS_REF_RAW_BKPT_COLS        ( 7 )

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

extern const boolean  Dtc_throt_pos_ref_boost_manu_inh;
extern const uint8  Dtc_throt_pos_ref_boost_gain_map[DTC_THROT_POS_REF_BOOST_GAIN_MAP_COLS];
extern const uint16  Dtc_max_distance_to_limp_home;
extern const uint16  Dtc_throt_pos_ref_raw_bkpt[DTC_THROT_POS_REF_RAW_BKPT_COLS];
extern const uint16  Dtc_throttle_pos_ref_raw_max_var;
extern const uint16  Dtc_throttle_pos_ref_raw_min_var;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Dtc_throttle_position_reference;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveRst_BoostSp(void);
void Thr_SdlMid_BoostSp(void);


#endif /* THRBOOSTSP_H */

/*-------------------------------- end of file -------------------------------*/
