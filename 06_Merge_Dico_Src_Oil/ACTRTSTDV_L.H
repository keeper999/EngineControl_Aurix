/***************************************************************************
;**
;** FILE NAME      : ACTRTSTDV_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTDV_L_H
#define ACTRTSTDV_L_H

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

/* enum st131 */
#define DMPVLV_ACTRTEST_END               1
#define DMPVLV_ACTRTEST_IDLE              2
#define DMPVLV_ACTRTEST_P1                4
#define DMPVLV_ACTRTEST_P2                8
/*extern uint8 DmpVlv_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  ACTRTSTDV_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 DmpVlv_stActrTst;
extern uint16 ActrTstDV_IntTime;
extern uint16 ActrTstDV_Tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACTRTSTDV_vidDVTST(void);
void ACTRTSTDV_vidInitOutput(void);


#endif /* ACTRTSTDV_L_H */

/*-------------------------------- end of file -------------------------------*/
