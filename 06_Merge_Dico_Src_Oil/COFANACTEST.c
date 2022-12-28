/***************************************************************************
;**
;** FILE NAME      : COFANACTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "COFANACTEST.H"
#include "COFANACTEST_L.H"
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
const boolean  CoFan_bCFricFan2End_C = 0;
const boolean  CoFan_bCFricFan2Idle_C = 0;
const boolean  CoFan_bCFricFan2Step1_C = 0;
const boolean  CoFan_bCFricFan2Step2_C = 0;
const boolean  CoFan_bCFricFan2Step3_C = 0;
const boolean  CoFan_bCFricFan2Step4_C = 0;
const uint8  CoFan_CFricMaxSpd_C = 0;
const uint8  CoFan_TempoB1_C = 0;
const uint8  CoFan_TempoB2HISPD_C = 0;
const uint8  CoFan_TempoB2LOSPD_C = 0;
const uint8  CoFan_TempoCprime_C = 0;
const uint8  CoFan_TiStep1_C = 0;
const uint8  CoFan_TiTstB2HiSpd1_C = 0;
const uint8  CoFan_TiTstB2HiSpd3_C = 0;
const uint8  COFANACTEST_u8Inhib = 0;
const uint16  CoFan_TiStep2_C = 0;
const uint16  CoFan_TiStep3_C = 0;
const uint16  CoFan_TiStep4_C = 0;
const uint16  CoFan_TiTstB1_C = 0;
const uint16  CoFan_TiTstB2HiSpd2_C = 0;
const uint16  CoFan_TiTstB2LoSpd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 CoFan_stBActrTst;
uint8 CoFan_stCActrTst;
boolean CoFan_bActrTstFan1BCmd;
boolean CoFan_bActrTstFan2Cmd;
boolean CoFan_bActrTstInProgs;
boolean CoFan_bB1TstCmpl;
boolean CoFan_bB2HiSpdTstCmpl;
boolean CoFan_bB2LoSpdTstCmpl;
boolean CoFan_bCTstCmpl;
uint8 CoFan_TempoB1;
uint8 CoFan_TempoB2HISPD;
uint8 CoFan_TempoB2LOSPD;
uint8 CoFan_TempoCprime;
uint16 CoFan_rActrTstFan1CCmd;
uint16 CoFan_TiCTst;
uint16 CoFan_TiTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

