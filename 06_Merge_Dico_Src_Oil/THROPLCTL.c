/***************************************************************************
;**
;** FILE NAME      : THROPLCTL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THROPLCTL.H"
#include "THROPLCTL_L.H"
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
const uint8  THROPLCTL_u8Inhib = 0;
const uint8  Tpac_exit_low_thrust_delay2 = 0;
const uint8  Tpac_exit_low_thrust_volt_step = 0;
const uint8  Tpac_exit_low_thrust_volt_step2 = 0;
const uint8  Tpac_open_loop_control_volt_step = 0;
const sint16  Tpac_closed_thrust_control_volt = 0;
const sint16  Tpac_exit_low_thrust_volt_max = 0;
const sint16  Tpac_mcw_inh_test_control_volt = 0;
const sint16  Tpac_open_thrust_control_volt = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean THROPLCTL_bTpacOpenLoopCtrlPrev;
boolean Tpac_open_loop_control;
uint8 THROPLCTL_u8TpacThrotCtrlStPrev;
uint8 Tpac_exit_low_thrust_tempo;
sint16 Tpac_open_loop_control_voltage;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

