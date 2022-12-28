/***************************************************************************
;**
;** FILE NAME      : ACTRTSTDV.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTDV_H
#define ACTRTSTDV_H

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

extern const uint16  ActrTstDV_OffTime_C;
extern const uint16  ActrTstDV_OnTime_C;
extern const uint16  ActrTstDV_Tempo_C;
extern const uint16  DmpVlv_rSpActrTstPos1_C;
extern const uint16  DmpVlv_rSpActrTstPos2_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DmpVlv_bActrTstCmpl;
extern boolean DmpVlv_bActrTstInProgs;
extern uint16 DmpVlv_rSpReqPosnActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DmpVlv_EveRst_ActrTstDV(void);
void DmpVlv_SdlFast_ActrTstDV(void);


#endif /* ACTRTSTDV_H */

/*-------------------------------- end of file -------------------------------*/
