/***************************************************************************
;**
;** FILE NAME      : THRBOOSTSP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRBOOSTSP_L_H
#define THRBOOSTSP_L_H

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

extern const uint8  THRBOOSTSP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Dtc_throt_pos_ref_boost_enable;
extern sint16 Dtc_throttle_pos_ref_raw_deriv;
extern uint16 Dtc_position_ref_raw_prev;
extern uint16 Dtc_throt_pos_ref_boost_temp;
extern uint16 Dtc_throt_pos_ref_raw_abs_deriv;
extern uint16 Dtc_throttle_pos_ref_raw_drv_uw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRBOOSTSP_ActivationTest(void);
void THRBOOSTSP_BoostMode(void);
void THRBOOSTSP_BoostSetPointStrategy(void);
void THRBOOSTSP_InitReset(void);
void THRBOOSTSP_NominalMode(void);


#endif /* THRBOOSTSP_L_H */

/*-------------------------------- end of file -------------------------------*/
