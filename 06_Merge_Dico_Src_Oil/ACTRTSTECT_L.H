/***************************************************************************
;**
;** FILE NAME      : ACTRTSTECT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTECT_L_H
#define ACTRTSTECT_L_H

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

/* enum st127 */
#define CTRLTHER_ACTRTEST_END             1
#define CTRLTHER_ACTRTEST_IDLE            2
#define CTRLTHER_ACTRTEST_MAX             4
#define CTRLTHER_ACTRTEST_MIN             8
/*extern uint8 ThMgt_stECTActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  ACTRTSTECT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 ThMgt_stECTActrTst;
extern boolean ACTRTSTECT_bTestEna;
extern uint8 ActrTstECT_IntTime;
extern uint16 ActrTstECT_CumulTime;
extern uint16 ActrTstECT_Tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACTRTSTECT_vidECTTst(void);
void ACTRTSTECT_vidInitOutput(void);


#endif /* ACTRTSTECT_L_H */

/*-------------------------------- end of file -------------------------------*/
