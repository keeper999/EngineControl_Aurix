/***************************************************************************
;**
;** FILE NAME      : VLVACTEXACTRTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXACTRTEST_H
#define VLVACTEXACTRTEST_H

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

/* enum st115 */
#define VLV_EXACTRTST_PHASE1              1
#define VLV_EXACTRTST_PHASE2              2
#define VLV_EXACTRTST_PHASE3              3
#define VLV_EXACTRTST_PHASE4              4
#define VLV_EXACTRTST_PHASE5              5
#define VLV_EXACTRTST_PHASE6              6
#define VLV_EXACTRTST_PHASE7              7
#define VLV_EXACTRTST_PHASE8              8
#define VLV_EXACTRTST_PHASE9              9
#define VLV_EXACTRTST_PHASE10             10
#define VLV_EXACTRTST_END                 11
#define VLV_EXACTRTST_IDLE                12
/*extern uint8 VlvAct_stExActrTst;*/

/* enum st118 */
#define VLVACT_EXACTRTST_PHASE1           1
#define VLVACT_EXACTRTST_PHASE2           2
#define VLVACT_EXACTRTST_PHASE3           3
#define VLVACT_EXACTRTST_PHASE4           4
#define VLVACT_EXACTRTST_PHASE5           5
#define VLVACT_EXACTRTST_PHASE6           6
#define VLVACT_EXACTRTST_PHASE7           7
#define VLVACT_EXACTRTST_PHASE8           8
#define VLVACT_EXACTRTST_PHASE9           9
#define VLVACT_EXACTRTST_PHASE10          10
#define VLVACT_EXACTRTST_END              11
#define VLVACT_EXACTRTST_IDLE             12
/*extern uint8 VlvAct_stExActrTstLstSt;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  VlvAct_ExActrTestSpdErrSpThd1_C;
extern const uint8  VlvAct_ExActrTestSpdErrSpThd2_C;
extern const uint8  VlvAct_ExActrTestSpdErrSpThd3_C;
extern const uint8  VlvAct_ExActrTestSpdErrSpThd4_C;
extern const uint16  VlvAct_agExActrTestMaxPosSp_C;
extern const uint16  VlvAct_agExActrTestMinPosSp_C;
extern const uint16  VlvAct_agExActrTestStaErrThd_C;
extern const uint16  VlvAct_tiExActrSpdTest1RampThd_C;
extern const uint16  VlvAct_tiExActrSpdTest2RampThd_C;
extern const uint16  VlvAct_tiExActrSpdTest3RampThd_C;
extern const uint16  VlvAct_tiExActrSpdTest4RampThd_C;
extern const uint16  VlvAct_tiExActrTest10SplSp_C;
extern const uint16  VlvAct_tiExActrTest1SplSp_C;
extern const uint16  VlvAct_tiExActrTest2SplSp_C;
extern const uint16  VlvAct_tiExActrTest3SplSp_C;
extern const uint16  VlvAct_tiExActrTest4SplSp_C;
extern const uint16  VlvAct_tiExActrTest5SplSp_C;
extern const uint16  VlvAct_tiExActrTest6SplSp_C;
extern const uint16  VlvAct_tiExActrTest7SplSp_C;
extern const uint16  VlvAct_tiExActrTest8SplSp_C;
extern const uint16  VlvAct_tiExActrTest9SplSp_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 VlvAct_stExActrTst;
extern uint8 VlvAct_stExActrTstLstSt;
extern boolean Srv_bActrTstExVVTEna;
extern boolean VlvAct_bExActrTest1RampSpdErrIdc;
extern boolean VlvAct_bExActrTest2RampSpdErrIdc;
extern boolean VlvAct_bExActrTest3RampSpdErrIdc;
extern boolean VlvAct_bExActrTest4RampSpdErrIdc;
extern boolean VlvAct_bExActrTestNotRun;
extern boolean VlvAct_bExActrTestSpEndIdc;
extern boolean VlvAct_bExActrTestStatErrMax1;
extern boolean VlvAct_bExActrTestStatErrMax2;
extern boolean VlvAct_bExActrTestStatErrRef1;
extern boolean VlvAct_bExActrTestStatErrRef2;
extern boolean VlvAct_bExActrTestStatErrRef3;
extern uint16 VlvAct_agExActrTestPosSp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveRst_ExActrTest(void);
void VlvAct_SdlFast_ExActrTest(void);


#endif /* VLVACTEXACTRTEST_H */

/*-------------------------------- end of file -------------------------------*/
