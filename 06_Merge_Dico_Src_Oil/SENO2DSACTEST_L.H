/***************************************************************************
;**
;** FILE NAME      : SENO2DSACTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SENO2DSACTEST_L_H
#define SENO2DSACTEST_L_H

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

/* enum st55 */
#define SO2Ds_ACTRTEST_IDLE               1
#define SO2Ds_ACTRTEST_ON                 2
#define SO2Ds_ACTRTEST_OFF                3
#define SO2Ds_ACTRTEST_END                4
/*extern uint8 SO2Ds_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  SENO2DSACTEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 SO2Ds_stActrTst;
extern uint32 ActrTstSO2_DsTempo;
extern uint32 ActrTstSO2Ds_CumulTime;
extern uint16 ActrTstSO2Ds_IntTime;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SENO2DSACTEST_vidInitOutput(void);
void SENO2DSACTEST_vidSO2DsTst(void);


#endif /* SENO2DSACTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
