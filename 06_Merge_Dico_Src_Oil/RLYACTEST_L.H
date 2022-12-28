/***************************************************************************
;**
;** FILE NAME      : RLYACTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RLYACTEST_L_H
#define RLYACTEST_L_H

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

/* enum st52 */
#define RLY_ACTRTEST_IDLE                 1
#define RLY_ACTRTEST_ON                   2
#define RLY_ACTRTEST_OFF                  3
#define RLY_ACTRTEST_END                  4
/*extern uint8 Rly_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  RLYACTEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Rly_stActrTst;
extern uint8 ActrTstRly_CumulTime;
extern uint8 ActrTstRly_IntTime;
extern uint8 ActrTstRly_Tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RLYACTEST_vidInitOutput(void);
void RLYACTEST_vidTimeCmdPwrRly(void);


#endif /* RLYACTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
