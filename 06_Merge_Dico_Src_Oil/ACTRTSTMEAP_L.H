/***************************************************************************
;**
;** FILE NAME      : ACTRTSTMEAP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTMEAP_L_H
#define ACTRTSTMEAP_L_H

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

/* enum st129 */
#define MEAP_ACTRTEST_END                 0
#define MEAP_ACTRTEST_IDLE                2
#define MEAP_ACTRTEST_OPEN                4
#define MEAP_ACTRTEST_CLOS                8
/*extern uint8 Meap_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  ACTRTSTMEAP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Meap_stActrTst;
extern uint8 ActrTstMeap_ClosTime;
extern uint8 ActrTstMeap_OpenTime;
extern uint8 ActrTstMeap_Tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACTRTSTMEAP_vidEntryIdleState(void);
void ACTRTSTMEAP_vidInitOutput(void);
void ACTRTSTMEAP_vidMEAPTst(void);
void ACTRTSTMEAP_vidRstDft(void);


#endif /* ACTRTSTMEAP_L_H */

/*-------------------------------- end of file -------------------------------*/
