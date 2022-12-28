/***************************************************************************
;**
;** FILE NAME      : THRSFTYCPUIFINH.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRSFTYCPUIFINH.H"
#include "THRSFTYCPUIFINH_L.H"
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
const boolean  Thr_bAcvAuthEndTestInh_C = 0;
const boolean  Thr_bAcvBswTestEndSfty_C = 0;
const boolean  Thr_bAuth_IfInhThrCpuSfty_C = 0;
const uint8  THRSFTYCPUIFINH_u8Inhib = 0;
const uint16  Thr_tiDlyAuthMcwInhTest1_C = 0;
const uint16  Thr_tiDlyAuthMcwInhTest2_C = 0;
const uint16  Thr_tiDlyMaxMcwInhTest_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Thr_bAcv_TestInhThr;
boolean Thr_bBswAuthEndTestInh;
boolean Thr_bDgoInhThr_CpuSfty;
boolean Thr_bDgoReadPinInhThr_Cpu;
boolean Thr_bMonRunInhThr_CpuSfty;
boolean Thr_bMonRunReadPinInhThr_Cpu;
boolean Thr_bRiseEdge_EndTestInh;
boolean Thr_bSwAuthEndTestInh;
boolean THRSFTYCPUIFINH_bEndTestInhPrev;
boolean THRSFTYCPUIFINH_bInitTimer;
boolean THRSFTYCPUIFINH_bInitTimerPrev;
boolean THRSFTYCPUIFINH_bMonRunRdCpuPrev;
boolean THRSFTYCPUIFINH_bResulOut1Prev;
boolean THRSFTYCPUIFINH_bResulOut2Prev;
boolean THRSFTYCPUIFINH_bResulOutput1;
boolean THRSFTYCPUIFINH_bResulOutput2;
boolean THRSFTYCPUIFINH_bTimeOut1;
boolean THRSFTYCPUIFINH_bTimeOut2;
boolean THRSFTYCPUIFINH_bTimeOut3;
boolean THRSFTYCPUIFINH_bTimerInit2;
boolean Tpim_filtered_inhibit_input;
uint8 Thr_ctAbortTestInhibitSfty;
uint8 THRSFTYCPUIFINH_u8TpacThrStPrev;
uint8 THRSFTYCPUIFINH_u8TpacThrStPrev2;
uint16 THRSFTYCPUIFINH_u16Timer1;
uint16 THRSFTYCPUIFINH_u16Timer2;
uint16 THRSFTYCPUIFINH_u16Timer3;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

