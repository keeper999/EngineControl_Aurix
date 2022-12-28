/***************************************************************************
;**
;** FILE NAME      : ACTRTSTECT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACTRTSTECT.H"
#include "ACTRTSTECT_L.H"
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
const uint8  ActrTstECT_OffTime_C = 0;
const uint8  ActrTstECT_OnTime_C = 0;
const uint8  ACTRTSTECT_u8Inhib = 0;
const uint8  ThMgt_rSpECTActrTstPos1_C = 0;
const uint8  ThMgt_rSpECTActrTstPos2_C = 0;
const uint16  ActrTstECT_Tempo_C = 0;
const uint16  ActrTstECT_TotTime_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 ThMgt_stECTActrTst;
boolean ACTRTSTECT_bTestEna;
boolean ThMgt_bECTActrTstInProgs;
boolean ThMgt_bECTTstCmpl;
uint8 ActrTstECT_IntTime;
uint8 ThMgt_rSpECTReqPosnActrTst;
uint16 ActrTstECT_CumulTime;
uint16 ActrTstECT_Tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

