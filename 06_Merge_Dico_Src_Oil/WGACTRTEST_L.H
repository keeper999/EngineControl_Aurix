/***************************************************************************
;**
;** FILE NAME      : WGACTRTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WGACTRTEST_L_H
#define WGACTRTEST_L_H

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
extern boolean WGACTRTEST_bTestTrbEna;
extern boolean WGACTRTEST_bTimeout;
extern boolean WGACTRTEST_bTrbDrnDynCompPrev;
extern boolean WGACTRTEST_bTrbDrnStabCompPrev;
extern uint8 Wg_noTrbTestChgtSp;
extern uint8 Wg_tiDlyTestTrbPha;
extern uint8 Wg_tiTrbActPhaDrn;
extern uint8 WGACTRTEST_u8Timer;
extern uint16 TrbAct_rOpTrbActTmp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void WGACTRTEST_vidInitOutput(void);
void WGACTRTEST_vidState_END(void);
void WGACTRTEST_vidState_IDLE(void);
void WGACTRTEST_vidState_PHASE1(void);
void WGACTRTEST_vidState_PHASE2(void);
void WGACTRTEST_vidState_PHASE3(void);
void WGACTRTEST_vidState_PHASE4(void);
void WGACTRTEST_vidState_PHASE5(void);
void WGACTRTEST_vidTestTrbActMgr(void);
void WGACTRTEST_vidTrbDynTest(void);
void WGACTRTEST_vidTrbStabTest(void);
void WGACTRTEST_vidWgActrTest(void);


#endif /* WGACTRTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
