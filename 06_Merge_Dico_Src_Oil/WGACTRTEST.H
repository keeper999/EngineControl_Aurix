/***************************************************************************
;**
;** FILE NAME      : WGACTRTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WGACTRTEST_H
#define WGACTRTEST_H

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

/* enum st126 */
#define WG_ACTRTST_IDLE                   0
#define WG_ACTRTST_PHASE1                 1
#define WG_ACTRTST_PHASE2                 2
#define WG_ACTRTST_PHASE3                 4
#define WG_ACTRTST_PHASE4                 8
#define WG_ACTRTST_PHASE5                 16
#define WG_ACTRTST_END                    32
/*extern uint8 Wg_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  ActrTstWg_Tempo_C;
extern const uint8  Wg_tiDlyTestTrbActFall_C;
extern const uint8  Wg_tiDlyTestTrbActMes1_C;
extern const uint8  Wg_tiDlyTestTrbActMes2_C;
extern const uint8  Wg_tiDlyTestTrbActRise_C;
extern const uint8  Wg_tiDlyTestTrbActSp1_C;
extern const uint8  Wg_tiDlyTestTrbActSp2_C;
extern const uint8  Wg_tiDlyTestTrbActSp3_C;
extern const uint8  Wg_tiDlyTestTrbActSp4_C;
extern const uint8  Wg_tiDlyTestTrbActSp5_C;
extern const uint8  WGACTRTEST_u8Inhib;
extern const uint16  Wg_rErrTestTrbAct_C;
extern const uint16  Wg_rMaxTestTrbAct_C;
extern const uint16  Wg_rOpTestTrbActSpHi_C;
extern const uint16  Wg_rOpTestTrbActSpLo_C;
extern const uint16  Wg_rOpTestTrbActSpMid_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Wg_stActrTst;
extern boolean Wg_bActrTstInProgs;
extern boolean Wg_bDynActrTst;
extern boolean Wg_bGapActrTst;
extern boolean Wg_bTestTrbTstCmpl;
extern uint8 ActrTstWg_Tempo;
extern uint16 Wg_rOpTrbActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Wg_EveRst_WgActrTest(void);
void Wg_SdlSlow_WgActrTest(void);


#endif /* WGACTRTEST_H */

/*-------------------------------- end of file -------------------------------*/
