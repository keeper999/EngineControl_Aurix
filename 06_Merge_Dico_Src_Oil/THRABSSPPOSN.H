/***************************************************************************
;**
;** FILE NAME      : THRABSSPPOSN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRABSSPPOSN_H
#define THRABSSPPOSN_H

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

extern const boolean  Tpac_closed_throttle_manu_inh;
extern const uint8  Tpac_ecu_temp_thresh_cold;
extern const uint8  Tpac_ecu_temp_thresh_warm;
extern const uint16  Thr_FLrnClCtl_posnHiThruRise_C;
extern const uint16  Thr_FLrnClCtl_posnLoThruLowr_C;
extern const uint16  Tpac_throttle_closed_thresh;
extern const uint16  Tpac_throttle_open_thresh_cold;
extern const uint16  Tpac_throttle_open_thresh_warm;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Tpac_ecu_temp_protected;
extern uint16 Tpac_throttle_position_reference;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveOplCllEna_ThrAbsSpPosn(void);
void Thr_EveRst_AbsSpPosn(void);
void Thr_SdlMid_AbsSpPosn(void);
void Thr_SdlSlow_AbsSpPosn(void);


#endif /* THRABSSPPOSN_H */

/*-------------------------------- end of file -------------------------------*/
