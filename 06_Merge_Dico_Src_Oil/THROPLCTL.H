/***************************************************************************
;**
;** FILE NAME      : THROPLCTL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THROPLCTL_H
#define THROPLCTL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TPAC_NULL_CONTROL_VOLTAGE         0

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

extern const uint8  Tpac_exit_low_thrust_delay2;
extern const uint8  Tpac_exit_low_thrust_volt_step;
extern const uint8  Tpac_exit_low_thrust_volt_step2;
extern const uint8  Tpac_open_loop_control_volt_step;
extern const sint16  Tpac_closed_thrust_control_volt;
extern const sint16  Tpac_exit_low_thrust_volt_max;
extern const sint16  Tpac_mcw_inh_test_control_volt;
extern const sint16  Tpac_open_thrust_control_volt;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Tpac_open_loop_control;
extern sint16 Tpac_open_loop_control_voltage;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveRst_OplCtl(void);
void Thr_SdlFast_OplCtl(void);
void Thr_SdlMid_OplCtl(void);


#endif /* THROPLCTL_H */

/*-------------------------------- end of file -------------------------------*/
