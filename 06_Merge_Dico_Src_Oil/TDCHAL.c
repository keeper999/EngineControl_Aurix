/***************************************************************************
;**
;** FILE NAME      : TDCHAL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TDCHAL_CFG.h"
#include "TDCHAL_E.h"
#include "TDCHAL.H"
#include "TDCHAL_L.H"
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
const uint8  TDCHAL_ku8NbSetPoints = 0;
const uint8  TDCHAL_ku8NumberOfCylinders = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
volatile boolean TDCHAL_vbEnabled;
volatile boolean TDCHAL_vbFirstBdc;
volatile boolean TDCHAL_vbFirstTdc;
uint32 TDCHAL_u32LastBdcDate;
uint32 TDCHAL_u32LastTdcDate;
volatile uint32 TDCHAL_vu32Period;
uint8 TDCHAL_u8CurrentSetpoint;
volatile uint8 TDCHAL_vu8Counter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

