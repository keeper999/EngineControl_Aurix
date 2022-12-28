/***************************************************************************
;**
;** FILE NAME      : WGACTRTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "WGACTRTEST.H"
#include "WGACTRTEST_L.H"
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
const uint8  ActrTstWg_Tempo_C = 0;
const uint8  Wg_tiDlyTestTrbActFall_C = 0;
const uint8  Wg_tiDlyTestTrbActMes1_C = 0;
const uint8  Wg_tiDlyTestTrbActMes2_C = 0;
const uint8  Wg_tiDlyTestTrbActRise_C = 0;
const uint8  Wg_tiDlyTestTrbActSp1_C = 0;
const uint8  Wg_tiDlyTestTrbActSp2_C = 0;
const uint8  Wg_tiDlyTestTrbActSp3_C = 0;
const uint8  Wg_tiDlyTestTrbActSp4_C = 0;
const uint8  Wg_tiDlyTestTrbActSp5_C = 0;
const uint8  WGACTRTEST_u8Inhib = 0;
const uint16  Wg_rErrTestTrbAct_C = 0;
const uint16  Wg_rMaxTestTrbAct_C = 0;
const uint16  Wg_rOpTestTrbActSpHi_C = 0;
const uint16  Wg_rOpTestTrbActSpLo_C = 0;
const uint16  Wg_rOpTestTrbActSpMid_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Wg_stActrTst;
boolean Wg_bActrTstInProgs;
boolean Wg_bDynActrTst;
boolean Wg_bGapActrTst;
boolean Wg_bTestTrbTstCmpl;
boolean WGACTRTEST_bTestTrbEna;
boolean WGACTRTEST_bTimeout;
boolean WGACTRTEST_bTrbDrnDynCompPrev;
boolean WGACTRTEST_bTrbDrnStabCompPrev;
uint8 ActrTstWg_Tempo;
uint8 Wg_noTrbTestChgtSp;
uint8 Wg_tiDlyTestTrbPha;
uint8 Wg_tiTrbActPhaDrn;
uint8 WGACTRTEST_u8Timer;
uint16 TrbAct_rOpTrbActTmp;
uint16 Wg_rOpTrbActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

