/***************************************************************************
;**
;** FILE NAME      : SENO2USACTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SENO2USACTEST.H"
#include "SENO2USACTEST_L.H"
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
const uint32  ActrTstSO2_UsTempo_C = 0;
const uint32  ActrTstSO2Us_TotTime = 0;
const uint8  SENO2USACTEST_u8Inhib = 0;
const uint16  ActrTstSO2Us_OffTime = 0;
const uint16  ActrTstSO2Us_OnTime = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 SO2Us_stActrTst;
boolean HeatSenO2_bUsPwrRlyCmd;
boolean HeatSenO2_bUsTstCmd;
boolean HeatSenO2_bUsTstCmpl;
uint32 ActrTstSO2_UsTempo;
uint32 ActrTstSO2Us_CumulTime;
uint16 ActrTstSO2Us_IntTime;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

