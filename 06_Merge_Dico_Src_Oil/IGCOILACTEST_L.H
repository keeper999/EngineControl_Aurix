/***************************************************************************
;**
;** FILE NAME      : IGCOILACTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGCOILACTEST_L_H
#define IGCOILACTEST_L_H

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

/* enum st84 */
#define IGCMD_ACTRTEST_IDLE               1
#define IGCMD_ACTRTEST_ON                 2
#define IGCMD_ACTRTEST_OFF                3
#define IGCMD_ACTRTEST_END                4
#define IGCMD_ACTRTEST_START              5
#define IGCMD_ACTRTEST_STOP               6
#define IGCMD_ACTRTEST_LDB_RECONF         7
/*extern uint8 IgCmd_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  IGCOILACTEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 IgCmd_stActrTst;
extern boolean IgCmd_bCoilTstCmpl;
extern uint8 ActrTstCoil_CmdTime;
extern uint8 ICD_current_mode;
extern uint8 IgCmd_CurTestCoil;
extern uint8 IGCOILACTEST_u8CodeTestActPrev;
extern uint8 IGCOILACTEST_u8IgCmdActrTstPrev;
extern uint16 ActrTstCoil_CumulTime;
extern uint16 ActrTstCoil_IntTime;
extern uint16 ActrTstCoil_TempoIdle;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IGCOILACTEST_vidCoilEntryMode(void);
void IGCOILACTEST_vidCoilTestEnd(void);
void IGCOILACTEST_vidCoilTestMode(void);
void IGCOILACTEST_vidEntryMode(void);
void IGCOILACTEST_vidIgnTime(void);
void IGCOILACTEST_vidInitOutput(void);
void IGCOILACTEST_vidTestEnd(void);
void IGCOILACTEST_vidTestMode(void);
void IGCOILACTEST_vidTestRealisation(void);


#endif /* IGCOILACTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
