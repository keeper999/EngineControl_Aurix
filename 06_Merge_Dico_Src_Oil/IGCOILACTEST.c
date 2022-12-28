/***************************************************************************
;**
;** FILE NAME      : IGCOILACTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGCOILACTEST.H"
#include "IGCOILACTEST_L.H"
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
const uint8  ActrTstCoil_OnTime = 0;
const uint8  IGCOILACTEST_u8Inhib = 0;
const uint16  ActrTstCoil_OffTime = 0;
const uint16  ActrTstCoil_TempoIdle_C = 0;
const uint16  ActrTstCoil_TotTime = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 IgCmd_stActrTst;
boolean IgCmd_bCoil1TstCmpl;
boolean IgCmd_bCoil2TstCmpl;
boolean IgCmd_bCoil3TstCmpl;
boolean IgCmd_bCoil4TstCmpl;
boolean IgCmd_bCoilTstCmpl;
uint8 ActrTstCoil_CmdTime;
uint8 ICD_current_mode;
uint8 IgCmd_CurTestCoil;
uint8 IGCOILACTEST_u8CodeTestActPrev;
uint8 IGCOILACTEST_u8IgCmdActrTstPrev;
uint16 ActrTstCoil_CumulTime;
uint16 ActrTstCoil_IntTime;
uint16 ActrTstCoil_TempoIdle;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

