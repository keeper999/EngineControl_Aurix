/***************************************************************************
;**
;** FILE NAME      : THRSFTYMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSFTYMNG_L_H
#define THRSFTYMNG_L_H

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


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  THRSFTYMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sfty_bDgoElDiagInhPin0_Cpu;
extern boolean Sfty_bDgoElDiagInhPin1_Cpu;
extern boolean Sfty_bDgoMcpFlashCks_Cpu;
extern boolean Sfty_bDgoMcpRAMTest_Cpu;
extern boolean Sfty_bDgoMcwCksCalc_Cpu;
extern boolean Sfty_bDgoMcwFctTest_Cpu;
extern boolean Sfty_bDgoMcwInitSftyRslt_Cpu;
extern boolean Sfty_bMonRunElDiagInhPin0_Cpu;
extern boolean Sfty_bMonRunElDiagInhPin1_Cpu;
extern boolean Sfty_bMonRunMcpFlashCks_Cpu;
extern boolean Sfty_bMonRunMcpRAMTest_Cpu;
extern boolean Sfty_bMonRunMcwCksCalc_Cpu;
extern boolean Sfty_bMonRunMcwFctTest_Cpu;
extern boolean Sfty_bMonRunMcwInitSftyRslt_Cpu;
extern boolean Thr_bDgoORngSftyDftLih;
extern boolean Thr_bMonRunORngSftyDftLih;
extern boolean THRSFTYMNG_bInhMngThrServPrev;
extern boolean THRSFTYMNG_bTimeOut1;
extern boolean THRSFTYMNG_bTimeOut2;
extern boolean THRSFTYMNG_bTimer2Prev;
extern uint16 THRSFTYMNG_u16Timer1;
extern uint16 THRSFTYMNG_u16Timer2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRSFTYMNG_vidDfltApplicLimpHome(void);
void THRSFTYMNG_vidDfltMCWDGFuncTest(void);
void THRSFTYMNG_vidInitOutput(void);
void THRSFTYMNG_vidMCWDGFuncTestRslt(void);
void THRSFTYMNG_vidMcwdgInhTestAbort(void);
void THRSFTYMNG_vidMcwdgInhTestCdn(void);
void THRSFTYMNG_vidMcwdgInhTestStrt(void);
void THRSFTYMNG_vidMcwdgInit(void);


#endif /* THRSFTYMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
