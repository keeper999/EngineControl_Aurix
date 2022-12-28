/***************************************************************************
;**
;** FILE NAME      : ANGSCHED_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ANGSCHED_L_H
#define ANGSCHED_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ANGSCHED_CFG.h"
#include "ANGSCHED_TYPES.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ANGSCHED_u8CALLBACKS_NUMBER       2
#define ANGSCHED_u8MAX_SETPOINTS_ALARM_1  3
#define ANGSCHED_u8MAX_SETPOINTS_ALARM_2  2

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

extern const uint8  ANGSCHED_ku8AnglesNum_ALARM_1;
extern const uint8  ANGSCHED_ku8AnglesNum_ALARM_2;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean ANGSCHED_bEnabled_ALARM_1;
extern boolean ANGSCHED_bEnabled_ALARM_2;
extern uint8 ANGSCHED_u8NextAngleIdx_ALARM_1;
extern uint8 ANGSCHED_u8NextAngleIdx_ALARM_2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* ANGSCHED_L_H */

/*-------------------------------- end of file -------------------------------*/
