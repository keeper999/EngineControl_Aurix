/***************************************************************************
;**
;** FILE NAME      : COFANACTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COFANACTEST_H
#define COFANACTEST_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CODE_TEST_B1FAN                   87
#define CODE_TEST_CFAN                    90

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

extern const boolean  CoFan_bCFricFan2End_C;
extern const boolean  CoFan_bCFricFan2Idle_C;
extern const boolean  CoFan_bCFricFan2Step1_C;
extern const boolean  CoFan_bCFricFan2Step2_C;
extern const boolean  CoFan_bCFricFan2Step3_C;
extern const boolean  CoFan_bCFricFan2Step4_C;
extern const uint8  CoFan_CFricMaxSpd_C;
extern const uint8  CoFan_TempoB1_C;
extern const uint8  CoFan_TempoB2HISPD_C;
extern const uint8  CoFan_TempoB2LOSPD_C;
extern const uint8  CoFan_TempoCprime_C;
extern const uint8  CoFan_TiStep1_C;
extern const uint8  CoFan_TiTstB2HiSpd1_C;
extern const uint8  CoFan_TiTstB2HiSpd3_C;
extern const uint16  CoFan_TiStep2_C;
extern const uint16  CoFan_TiStep3_C;
extern const uint16  CoFan_TiStep4_C;
extern const uint16  CoFan_TiTstB1_C;
extern const uint16  CoFan_TiTstB2HiSpd2_C;
extern const uint16  CoFan_TiTstB2LoSpd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoFan_bActrTstFan1BCmd;
extern boolean CoFan_bActrTstFan2Cmd;
extern boolean CoFan_bActrTstInProgs;
extern boolean CoFan_bB1TstCmpl;
extern boolean CoFan_bB2HiSpdTstCmpl;
extern boolean CoFan_bB2LoSpdTstCmpl;
extern boolean CoFan_bCTstCmpl;
extern uint16 CoFan_rActrTstFan1CCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CoFan_EveRst_ActrTstGMV(void);
void CoFan_SdlMid_ActrTstGMV(void);


#endif /* COFANACTEST_H */

/*-------------------------------- end of file -------------------------------*/
