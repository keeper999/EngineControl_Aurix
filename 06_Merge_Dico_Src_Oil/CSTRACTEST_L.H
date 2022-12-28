/***************************************************************************
;**
;** FILE NAME      : CSTRACTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRACTEST_L_H
#define CSTRACTEST_L_H

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

/* enum st54 */
#define CSTR_ACTRTEST_END                 1
#define CSTR_ACTRTEST_IDLE                2
#define CSTR_ACTRTEST_MAX                 3
#define CSTR_ACTRTEST_MIN                 4
/*extern uint8 Cstr_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Cstr_stActrTst;
extern uint8 ActrTstCstr_IntTime;
extern uint16 ActrTstCstr_CumulTime;
extern uint16 ActrTstCstr_Tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CSTRACTEST_vidCmdState(void);
void CSTRACTEST_vidInitOutput(void);


#endif /* CSTRACTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
