/***************************************************************************
;**
;** FILE NAME      : ACTRTSTDV.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACTRTSTDV.H"
#include "ACTRTSTDV_L.H"
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
const uint8  ACTRTSTDV_u8Inhib = 0;
const uint16  ActrTstDV_OffTime_C = 0;
const uint16  ActrTstDV_OnTime_C = 0;
const uint16  ActrTstDV_Tempo_C = 0;
const uint16  DmpVlv_rSpActrTstPos1_C = 0;
const uint16  DmpVlv_rSpActrTstPos2_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 DmpVlv_stActrTst;
boolean DmpVlv_bActrTstCmpl;
boolean DmpVlv_bActrTstInProgs;
uint16 ActrTstDV_IntTime;
uint16 ActrTstDV_Tempo;
uint16 DmpVlv_rSpReqPosnActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

