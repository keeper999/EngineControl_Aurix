/***************************************************************************
;**
;** FILE NAME      : IGNHAL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGNHAL_H
#define IGNHAL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGNHAL_Cfg.h"
#include "IGNHAL_E.h"
#include "IGNHAL_GATEWAY.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGN_HAL_CYLINDER_A                0
#define IGN_HAL_CYLINDER_B                1
#define IGN_HAL_CYLINDER_C                2
#define IGN_HAL_CYLINDER_D                3
#define IGNHAL_u8COIL_A                   0
#define IGNHAL_u8COIL_A_C                 4
#define IGNHAL_u8COIL_B                   1
#define IGNHAL_u8COIL_B_D                 5
#define IGNHAL_u8COIL_C                   2
#define IGNHAL_u8COIL_D                   3

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st27 */
#define IGN_HAL_MODE_FIXED                1
#define IGN_HAL_MODE_ADAP                 2
#define IGN_HAL_MODE_TEST                 4
/*extern uint8 IgnHALMode;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern uint8 IgnHALMode;
extern sint8 IGNHAL_s8TrimGainOutput_CM_24;
extern sint8 IGNHAL_s8TrimGainOutput_CM_3;
extern sint8 IGNHAL_s8TrimGainOutput_CM_45;
extern sint8 IGNHAL_s8TrimGainOutput_CM_66;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* IGNHAL_H */

/*-------------------------------- end of file -------------------------------*/
