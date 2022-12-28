/***************************************************************************
;**
;** FILE NAME      : THRSECUMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRSECUMNG.H"
#include "THRSECUMNG_L.H"
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
const boolean  Ssm_throt_pos_failure_on_coh_inh = 0;
const boolean  Tpac_pos_filt_med_inh = 0;
const uint8  THRSECUMNG_u8Inhib = 0;
const uint16  Ssm_default_closed_throttle_pos = 0;
const uint16  Ssm_default_limp_home_pos = 0;
const uint16  Ssm_default_open_throttle_pos = 0;
const uint16  Ssm_default_throttle_position = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Ssm_throttle_pos_sensing_status;
boolean THRSECUMNG_bIniSecuMngThrSenPrev;
uint8 Position_papillon;
uint16 Ssm_closed_throttle_pos;
uint16 Ssm_limp_home_throttle_pos;
uint16 Ssm_open_throttle_pos;
uint16 Ssm_raw_filt_throttle_position;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

