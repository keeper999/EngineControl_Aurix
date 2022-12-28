/***************************************************************************
;**
;** FILE NAME      : CONFIGLIN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CONFIGLIN_H
#define CONFIGLIN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ALT_LIN                           1

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st113 */
#define LIN_PRESENT                       0
#define LIN_ABSENT                        1
#define LIN_CONFIRMED_ABSENT              2
/*extern uint8 CONFIGLIN_stAltStatus;*/

/* enum st114 */
#define LIN_NO_BLOCKED                    0
#define LIN_BLOCKED                       1
#define LIN_CONFIRMED_BLOCKED             2
/*extern uint8 CONFIGLIN_stBusBlockedStatus;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  CONFIGLIN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 CONFIGLIN_stAltStatus;
extern uint8 CONFIGLIN_stBusBlockedStatus;
extern boolean CONFIGLIN_bDiag_on_pred;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CONFIGLIN_vidMngEveRst(void);
void CONFIGLIN_vidMngSch_100MS(void);
void CONFIGLIN_vidMngSch_10MS(void);
void CONFIGLIN_vidMngSch_1S(void);


#endif /* CONFIGLIN_H */

/*-------------------------------- end of file -------------------------------*/
