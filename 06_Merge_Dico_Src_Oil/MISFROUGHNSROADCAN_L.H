/***************************************************************************
;**
;** FILE NAME      : MISFROUGHNSROADCAN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFROUGHNSROADCAN_L_H
#define MISFROUGHNSROADCAN_L_H

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

extern const uint8  MISFROUGHNSROADCAN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Misf_bDgoLostMisfRoughnsRoad;
extern boolean Misf_bMonRunLostMisfRoughnsRoad;
extern uint16 Acceleration_vehicule_ard_mux;
extern uint16 Acceleration_vehicule_arg_mux;
extern uint16 Acceleration_vehicule_avd_mux;
extern uint16 Acceleration_vehicule_avg_mux;
extern uint16 Misf_aRoughnRoadDetThd;
extern uint16 MISFROUGHNSROADCAN_u16ArdSpPrev;
extern uint16 MISFROUGHNSROADCAN_u16ArgSpPrev;
extern uint16 MISFROUGHNSROADCAN_u16AvdSpPrev;
extern uint16 MISFROUGHNSROADCAN_u16AvgSpPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFROUGHNSROADCAN_vidClcn(void);
void MISFROUGHNSROADCAN_vidInitOutput(void);


#endif /* MISFROUGHNSROADCAN_L_H */

/*-------------------------------- end of file -------------------------------*/
