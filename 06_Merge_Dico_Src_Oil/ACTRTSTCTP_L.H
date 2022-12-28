/***************************************************************************
;**
;** FILE NAME      : ACTRTSTCTP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTCTP_L_H
#define ACTRTSTCTP_L_H

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

/* enum st130 */
#define CTP_ACTRTEST_END                  0
#define CTP_ACTRTEST_IDLE                 2
#define CTP_ACTRTEST_MEM0                 4
#define CTP_ACTRTEST_MEM1                 8
#define CTP_ACTRTEST_MEM2                 16
/*extern uint8 CTP_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  ACTRTSTCTP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 CTP_stActrTst;
extern boolean ACTRTSTCTP_bAcvDft1dActrTstPrev;
extern boolean ACTRTSTCTP_bAcvDft2dActrTstPrev;
extern boolean CTP_bAcvDft1dActrTst;
extern boolean CTP_bAcvDft2dActrTst;
extern uint8 ActrTstCTP_IntTime;
extern uint16 ActrTstCTP_Tempo;
extern uint16 ActrTstCTP_uBattMesMem0;
extern uint16 ActrTstCTP_uBattMesMem1;
extern uint16 ActrTstCTP_uBattMesMem2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACTRTSTCTP_vidCPTChart(void);
void ACTRTSTCTP_vidCTPTst(void);
void ACTRTSTCTP_vidDft1dActrTst(void);
void ACTRTSTCTP_vidDft2dActrTst(void);
void ACTRTSTCTP_vidInitOutput(void);
void ACTRTSTCTP_vidRstDft(void);


#endif /* ACTRTSTCTP_L_H */

/*-------------------------------- end of file -------------------------------*/
