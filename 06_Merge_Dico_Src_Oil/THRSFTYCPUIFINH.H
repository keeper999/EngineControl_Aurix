/***************************************************************************
;**
;** FILE NAME      : THRSFTYCPUIFINH.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSFTYCPUIFINH_H
#define THRSFTYCPUIFINH_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Thr_SampleTiFast_SC               5

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

extern const boolean  Thr_bAcvAuthEndTestInh_C;
extern const boolean  Thr_bAcvBswTestEndSfty_C;
extern const boolean  Thr_bAuth_IfInhThrCpuSfty_C;
extern const uint16  Thr_tiDlyAuthMcwInhTest1_C;
extern const uint16  Thr_tiDlyAuthMcwInhTest2_C;
extern const uint16  Thr_tiDlyMaxMcwInhTest_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bAcv_TestInhThr;
extern boolean Thr_bDgoInhThr_CpuSfty;
extern boolean Thr_bDgoReadPinInhThr_Cpu;
extern boolean Thr_bMonRunInhThr_CpuSfty;
extern boolean Thr_bMonRunReadPinInhThr_Cpu;
extern boolean Tpim_filtered_inhibit_input;
extern uint8 Thr_ctAbortTestInhibitSfty;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveRst_IfInhThrCpuSfty(void);
void Thr_EveTestAbort_IfInhThrCpuSfty(void);
void Thr_EveTestEnd_IfInhThrCpuSfty(void);
void Thr_SdlFast_IfInhThrCpuSfty(void);


#endif /* THRSFTYCPUIFINH_H */

/*-------------------------------- end of file -------------------------------*/
