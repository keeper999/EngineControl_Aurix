/***************************************************************************
;**
;** FILE NAME      : THRSFTYMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRSFTYMNG.H"
#include "THRSFTYMNG_L.H"
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
const boolean  Thr_bAcvHotRstCdn_CpuSfty = 0;
const uint8  THRSFTYMNG_u8Inhib = 0;
const uint16  Thr_posnDriftLihMeasThd1_C = 0;
const uint16  Tpac_tiDlyDetDftRetLih = 0;
const uint16  Tpac_tiDlyDiagDftRetLih = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Sfty_bDgoElDiagInhPin0_Cpu;
boolean Sfty_bDgoElDiagInhPin1_Cpu;
boolean Sfty_bDgoMcpFlashCks_Cpu;
boolean Sfty_bDgoMcpRAMTest_Cpu;
boolean Sfty_bDgoMcwCksCalc_Cpu;
boolean Sfty_bDgoMcwFctTest_Cpu;
boolean Sfty_bDgoMcwInitSftyRslt_Cpu;
boolean Sfty_bMonRunElDiagInhPin0_Cpu;
boolean Sfty_bMonRunElDiagInhPin1_Cpu;
boolean Sfty_bMonRunMcpFlashCks_Cpu;
boolean Sfty_bMonRunMcpRAMTest_Cpu;
boolean Sfty_bMonRunMcwCksCalc_Cpu;
boolean Sfty_bMonRunMcwFctTest_Cpu;
boolean Sfty_bMonRunMcwInitSftyRslt_Cpu;
boolean Thr_bCdnTestInh_CpuSfty;
boolean Thr_bDgoORngSftyDftLih;
boolean Thr_bMonRunORngSftyDftLih;
boolean Thr_bTestAbort_ThrSftyMng;
boolean Thr_bTestStart_ThrSftyMng;
boolean THRSFTYMNG_bInhMngThrServPrev;
boolean ThrSftyMng_bThrPosnLihDrift;
boolean THRSFTYMNG_bTimeOut1;
boolean THRSFTYMNG_bTimeOut2;
boolean THRSFTYMNG_bTimer2Prev;
uint16 THRSFTYMNG_u16Timer1;
uint16 THRSFTYMNG_u16Timer2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

