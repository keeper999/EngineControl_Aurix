/***************************************************************************
;**
;** FILE NAME      : COFANACTEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COFANACTEST_L_H
#define COFANACTEST_L_H

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

/* enum st85 */
#define COFAN_BACTRTST_IDLE               1
#define COFAN_BACTRTST_B1PRGS             2
#define COFAN_BACTRTST_B1END              3
#define COFAN_BACTRTST_B2LOSPDPRGS        4
#define COFAN_BACTRTST_B2LOSPDEND         5
#define COFAN_BACTRTST_B2HISPD1PRGS       6
#define COFAN_BACTRTST_B2HISPD2PRGS       7
#define COFAN_BACTRTST_B2HISPD3PRGS       8
#define COFAN_BACTRTST_B2HISPDEND         9
#define COFAN_BACTRTST_END                10
/*extern uint8 CoFan_stBActrTst;*/

/* enum st86 */
#define COFAN_CACTRTST_IDLE               1
#define COFAN_CACTRTST_STEP1              2
#define COFAN_CACTRTST_STEP2              3
#define COFAN_CACTRTST_STEP3              4
#define COFAN_CACTRTST_STEP4              5
#define COFAN_CACTRTST_END                6
/*extern uint8 CoFan_stCActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  COFANACTEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 CoFan_stBActrTst;
extern uint8 CoFan_stCActrTst;
extern uint8 CoFan_TempoB1;
extern uint8 CoFan_TempoB2HISPD;
extern uint8 CoFan_TempoB2LOSPD;
extern uint8 CoFan_TempoCprime;
extern uint16 CoFan_TiCTst;
extern uint16 CoFan_TiTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COFANACTEST_vidBAcTstTransToEnd(void);
void COFANACTEST_vidBAcTstTransToIdle(void);
void COFANACTEST_vidCAcTstTransToIdle(void);
void COFANACTEST_vidGMVTstB(void);
void COFANACTEST_vidGMVTstC(void);
void COFANACTEST_vidGMVTstRun(void);
void COFANACTEST_vidInitOutput(void);


#endif /* COFANACTEST_L_H */

/*-------------------------------- end of file -------------------------------*/
