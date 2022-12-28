/***************************************************************************
;**
;** FILE NAME      : RLYACTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "RLYACTEST.H"
#include "RLYACTEST_L.H"
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
const uint8  ActrTstRly_Tempo_C = 0;
const uint8  RLYACTEST_u8Inhib = 0;
const uint8  TpsOff_ActrTstPwrRly = 0;
const uint8  TpsOn_ActrTstPwrRly = 0;
const uint16  TpsTot_ActrTstPwrRly = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Rly_stActrTst;
boolean Rly_bActrTstCmd;
boolean Rly_bActrTstCmpl;
boolean Rly_bTstInProgress;
uint8 ActrTstRly_CumulTime;
uint8 ActrTstRly_IntTime;
uint8 ActrTstRly_Tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

