/***************************************************************************
;**
;** FILE NAME      : PTMHAL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PTMHAL_L_H
#define PTMHAL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PTMHAL_E.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define PTMHAL_AU32DURATIONPACKAGE_COLS        ( 4 )
#define PTMHAL_bEVLV_CFG_EN               0
#define PTMHAL_bPSA_3CYL_CFG_EN           1
#define PTMHAL_bPSA_4CYL_CFG1_EN          0
#define PTMHAL_bPSA_4CYL_CFG2_EN          0
#define PTMHAL_bRSA_3CYL_CFG_EN           0
#define PTMHAL_TIME_STAMP_TIMER_MASK      16777215
#define PTMHAL_u16ANGULAR_MARGIN          256
#define PTMHAL_u16COEF_DESIRED_RESOL      1
#define PTMHAL_u16COEF_TIMER_RESOL        1
#define PTMHAL_u16ENGINE_CYCLE            46080
#define PTMHAL_u16EVLV_8ACQ               4
#define PTMHAL_u16PSA_3CYL_CFG            1
#define PTMHAL_u16PSA_4CYL_CFG1           2
#define PTMHAL_u16PSA_4CYL_CFG2           3
#define PTMHAL_u16RSA_3CYL_CFG            5
#define PTMHAL_u8EVLV_CFG_NB_PACK         1
#define PTMHAL_u8MAX_ALARM_NB_PER_CYCLE   3
#define PTMHAL_u8MAX_NB_PACKS             4
#define PTMHAL_u8PSA_3CYL_CFG_NB_PACK     4
#define PTMHAL_u8PSA_4CYL_CFG1_NB_PACK    4
#define PTMHAL_u8PSA_4CYL_CFG2_NB_PACK    4
#define PTMHAL_u8RSA_3CYL_CFG_NB_PACK     8
#define PTMHAL_u8TIME_STAMP               1

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

extern const uint8  PTMHAL_ku8AlarmNbPerCycle;
extern const uint16  PTMHAL_ku16DurationsAlgo;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean PTMHAL_bEnabled;
extern boolean PTMHAL_bFirstCalculEvtOccured;
extern uint8 PTMHAL_u8CycleIndex;
extern uint8 PTMHAL_u8NbDurationPacksValid;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* PTMHAL_L_H */

/*-------------------------------- end of file -------------------------------*/
