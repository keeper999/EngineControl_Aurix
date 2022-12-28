/***************************************************************************
;**
;** FILE NAME      : ACTRTSTCTP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTCTP_H
#define ACTRTSTCTP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CTP_SampleTiMid_SC                100

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

extern const uint8  ActrTstCTP_tiDlyTestMem0_C;
extern const uint8  ActrTstCTP_tiDlyTestMem1_C;
extern const uint8  ActrTstCTP_tiDlyTestMem2_C;
extern const uint16  ActrTstCTP_Tempo_C;
extern const uint16  ActrTstCTP_uMaxBattMem1_C;
extern const uint16  ActrTstCTP_uMaxBattMem2_C;
extern const uint16  ActrTstCTP_uMinBattMem1_C;
extern const uint16  ActrTstCTP_uMinBattMem2_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CTP_bActrTstCmpl;
extern boolean CTP_bActrTstInProgs;
extern boolean CTP_bAcvCTP1ActrTstReq;
extern boolean CTP_bAcvCTP2ActrTstReq;
extern boolean CTP_bDft1dActrTst;
extern boolean CTP_bDft2dActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CTP_EveRst_ActrTstCTP(void);
void CTP_SdlMid_ActrTstCTP(void);


#endif /* ACTRTSTCTP_H */

/*-------------------------------- end of file -------------------------------*/
