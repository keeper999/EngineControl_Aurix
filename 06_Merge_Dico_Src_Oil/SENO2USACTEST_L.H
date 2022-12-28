/***************************************************************************
;**
;** FILE NAME      : SENO2USACTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SENO2USACTEST_L_H
#define SENO2USACTEST_L_H

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

/* enum st53 */
#define SO2Us_ACTRTEST_IDLE               1
#define SO2Us_ACTRTEST_ON                 2
#define SO2Us_ACTRTEST_OFF                3
#define SO2Us_ACTRTEST_END                4
/*extern uint8 SO2Us_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  SENO2USACTEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 SO2Us_stActrTst;
extern uint32 ActrTstSO2_UsTempo;
extern uint32 ActrTstSO2Us_CumulTime;
extern uint16 ActrTstSO2Us_IntTime;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SENO2USACTEST_vidInitOutput(void);
void SENO2USACTEST_vidSO2UsTst(void);


#endif /* SENO2USACTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
