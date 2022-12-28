/***************************************************************************
;**
;** FILE NAME      : SENO2DSACTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SENO2DSACTEST.H"
#include "SENO2DSACTEST_L.H"
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
const uint32  ActrTstSO2_DsTempo_C = 0;
const uint32  ActrTstSO2Ds_TotTime = 0;
const uint8  SENO2DSACTEST_u8Inhib = 0;
const uint16  ActrTstSO2Ds_OffTime = 0;
const uint16  ActrTstSO2Ds_OnTime = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 SO2Ds_stActrTst;
boolean HeatSenO2_bDsPwrRlyCmd;
boolean HeatSenO2_bDsTstCmd;
boolean HeatSenO2_bDsTstCmpl;
uint32 ActrTstSO2_DsTempo;
uint32 ActrTstSO2Ds_CumulTime;
uint16 ActrTstSO2Ds_IntTime;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

