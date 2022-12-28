/***************************************************************************
;**
;** FILE NAME      : ACTRTSTECT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTECT_H
#define ACTRTSTECT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  ActrTstECT_OffTime_C;
extern const uint8  ActrTstECT_OnTime_C;
extern const uint8  ThMgt_rSpECTActrTstPos1_C;
extern const uint8  ThMgt_rSpECTActrTstPos2_C;
extern const uint16  ActrTstECT_Tempo_C;
extern const uint16  ActrTstECT_TotTime_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ThMgt_bECTActrTstInProgs;
extern boolean ThMgt_bECTTstCmpl;
extern uint8 ThMgt_rSpECTReqPosnActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ThMgt_EveRst_ActrTstECT(void);
void ThMgt_SdlMid_ActrTstECT(void);


#endif /* ACTRTSTECT_H */

/*-------------------------------- end of file -------------------------------*/
