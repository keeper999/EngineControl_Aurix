/***************************************************************************
;**
;** FILE NAME      : VLVACTINACTRTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINACTRTEST_H
#define VLVACTINACTRTEST_H

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

/* enum st114 */
#define VLV_INACTRTST_PHASE1              1
#define VLV_INACTRTST_PHASE2              2
#define VLV_INACTRTST_PHASE3              3
#define VLV_INACTRTST_PHASE4              4
#define VLV_INACTRTST_PHASE5              5
#define VLV_INACTRTST_PHASE6              6
#define VLV_INACTRTST_PHASE7              7
#define VLV_INACTRTST_PHASE8              8
#define VLV_INACTRTST_PHASE9              9
#define VLV_INACTRTST_PHASE10             10
#define VLV_INACTRTST_END                 11
#define VLV_INACTRTST_IDLE                12
/*extern uint8 VlvAct_stInActrTst;*/

/* enum st117 */
#define VLVACT_INACTRTST_PHASE1           1
#define VLVACT_INACTRTST_PHASE2           2
#define VLVACT_INACTRTST_PHASE3           3
#define VLVACT_INACTRTST_PHASE4           4
#define VLVACT_INACTRTST_PHASE5           5
#define VLVACT_INACTRTST_PHASE6           6
#define VLVACT_INACTRTST_PHASE7           7
#define VLVACT_INACTRTST_PHASE8           8
#define VLVACT_INACTRTST_PHASE9           9
#define VLVACT_INACTRTST_PHASE10          10
#define VLVACT_INACTRTST_END              11
#define VLVACT_INACTRTST_IDLE             12
/*extern uint8 VlvAct_stInActrTstLstSt;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  VlvAct_InActrTestSpdErrSpThd1_C;
extern const uint8  VlvAct_InActrTestSpdErrSpThd2_C;
extern const uint8  VlvAct_InActrTestSpdErrSpThd3_C;
extern const uint8  VlvAct_InActrTestSpdErrSpThd4_C;
extern const uint16  VlvAct_agInActrTestMaxPosSp_C;
extern const uint16  VlvAct_agInActrTestMinPosSp_C;
extern const uint16  VlvAct_agInActrTestStaErrThd_C;
extern const uint16  VlvAct_tiInActrSpdTest1RampThd_C;
extern const uint16  VlvAct_tiInActrSpdTest2RampThd_C;
extern const uint16  VlvAct_tiInActrSpdTest3RampThd_C;
extern const uint16  VlvAct_tiInActrSpdTest4RampThd_C;
extern const uint16  VlvAct_tiInActrTest10SplSp_C;
extern const uint16  VlvAct_tiInActrTest1SplSp_C;
extern const uint16  VlvAct_tiInActrTest2SplSp_C;
extern const uint16  VlvAct_tiInActrTest3SplSp_C;
extern const uint16  VlvAct_tiInActrTest4SplSp_C;
extern const uint16  VlvAct_tiInActrTest5SplSp_C;
extern const uint16  VlvAct_tiInActrTest6SplSp_C;
extern const uint16  VlvAct_tiInActrTest7SplSp_C;
extern const uint16  VlvAct_tiInActrTest8SplSp_C;
extern const uint16  VlvAct_tiInActrTest9SplSp_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 VlvAct_stInActrTst;
extern uint8 VlvAct_stInActrTstLstSt;
extern boolean Srv_bActrTstInVVTEna;
extern boolean VlvAct_bInActrTest1RampSpdErrIdc;
extern boolean VlvAct_bInActrTest2RampSpdErrIdc;
extern boolean VlvAct_bInActrTest3RampSpdErrIdc;
extern boolean VlvAct_bInActrTest4RampSpdErrIdc;
extern boolean VlvAct_bInActrTestNotRun;
extern boolean VlvAct_bInActrTestSpEndIdc;
extern boolean VlvAct_bInActrTestStatErrMax1;
extern boolean VlvAct_bInActrTestStatErrMax2;
extern boolean VlvAct_bInActrTestStatErrRef1;
extern boolean VlvAct_bInActrTestStatErrRef2;
extern boolean VlvAct_bInActrTestStatErrRef3;
extern uint16 VlvAct_agInActrTestPosSp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveRst_InActrTest(void);
void VlvAct_SdlFast_InActrTest(void);


#endif /* VLVACTINACTRTEST_H */

/*-------------------------------- end of file -------------------------------*/
