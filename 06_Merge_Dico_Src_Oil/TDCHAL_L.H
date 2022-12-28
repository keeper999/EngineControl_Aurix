/***************************************************************************
;**
;** FILE NAME      : TDCHAL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TDCHAL_L_H
#define TDCHAL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TDCHAL_CFG.h"
#include "TDCHAL_E.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TDCHAL_coBDC_CALC_PER_ON_ENABLED  1
#define TDCHAL_coBDC_ENABLED              1
#define TDCHAL_u16ANGLE_RESOL             64
#define TDCHAL_u16ANGULAR_MARGIN          256
#define TDCHAL_u16COEF_DESIRED_RESOL      2
#define TDCHAL_u16COEF_TIMER_RESOL        1
#define TDCHAL_u16COEF_TOOTH_DURATION_RESOL  1
#define TDCHAL_u16ENGINE_CYCLE            46080
#define TDCHAL_u32TOOTH_EDGE_DATE_MASK    16777215
#define TDCHAL_u8FOUR_CYLINDERS           4
#define TDCHAL_u8MAX_NB_SETPOINTS         6
#define TDCHAL_u8NB_ACTIONS_ON_SETPOINT   2
#define TDCHAL_u8THREE_CYLINDERS          3
#define TDCHAL_u8TOOTH_INFO_BUF_SIZE      3

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

extern const uint8  TDCHAL_ku8NbSetPoints;
extern const uint8  TDCHAL_ku8NumberOfCylinders;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern volatile boolean TDCHAL_vbEnabled;
extern volatile boolean TDCHAL_vbFirstBdc;
extern volatile boolean TDCHAL_vbFirstTdc;
extern uint32 TDCHAL_u32LastBdcDate;
extern uint32 TDCHAL_u32LastTdcDate;
extern volatile uint32 TDCHAL_vu32Period;
extern uint8 TDCHAL_u8CurrentSetpoint;
extern volatile uint8 TDCHAL_vu8Counter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TDCHAL_vidApproximatePeriod(void);
void TDCHAL_vidDriverInitialisation(void);
void TDCHAL_vidOnBDC(void);
void TDCHAL_vidOnTDC(void);


#endif /* TDCHAL_L_H */

/*-------------------------------- end of file -------------------------------*/
