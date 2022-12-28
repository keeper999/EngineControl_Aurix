/***************************************************************************
;**
;** FILE NAME      : ACTRTSTCTP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACTRTSTCTP.H"
#include "ACTRTSTCTP_L.H"
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
const uint8  ActrTstCTP_tiDlyTestMem0_C = 0;
const uint8  ActrTstCTP_tiDlyTestMem1_C = 0;
const uint8  ActrTstCTP_tiDlyTestMem2_C = 0;
const uint8  ACTRTSTCTP_u8Inhib = 0;
const uint16  ActrTstCTP_Tempo_C = 0;
const uint16  ActrTstCTP_uMaxBattMem1_C = 0;
const uint16  ActrTstCTP_uMaxBattMem2_C = 0;
const uint16  ActrTstCTP_uMinBattMem1_C = 0;
const uint16  ActrTstCTP_uMinBattMem2_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 CTP_stActrTst;
boolean ACTRTSTCTP_bAcvDft1dActrTstPrev;
boolean ACTRTSTCTP_bAcvDft2dActrTstPrev;
boolean CTP_bActrTstCmpl;
boolean CTP_bActrTstInProgs;
boolean CTP_bAcvCTP1ActrTstReq;
boolean CTP_bAcvCTP2ActrTstReq;
boolean CTP_bAcvDft1dActrTst;
boolean CTP_bAcvDft2dActrTst;
boolean CTP_bDft1dActrTst;
boolean CTP_bDft2dActrTst;
uint8 ActrTstCTP_IntTime;
uint16 ActrTstCTP_Tempo;
uint16 ActrTstCTP_uBattMesMem0;
uint16 ActrTstCTP_uBattMesMem1;
uint16 ActrTstCTP_uBattMesMem2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

