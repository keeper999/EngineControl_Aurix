/***************************************************************************
;**
;** FILE NAME      : THRSFTYCPUIFINH_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSFTYCPUIFINH_L_H
#define THRSFTYCPUIFINH_L_H

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

extern const uint8  THRSFTYCPUIFINH_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bBswAuthEndTestInh;
extern boolean Thr_bRiseEdge_EndTestInh;
extern boolean Thr_bSwAuthEndTestInh;
extern boolean THRSFTYCPUIFINH_bEndTestInhPrev;
extern boolean THRSFTYCPUIFINH_bInitTimer;
extern boolean THRSFTYCPUIFINH_bInitTimerPrev;
extern boolean THRSFTYCPUIFINH_bMonRunRdCpuPrev;
extern boolean THRSFTYCPUIFINH_bResulOut1Prev;
extern boolean THRSFTYCPUIFINH_bResulOut2Prev;
extern boolean THRSFTYCPUIFINH_bResulOutput1;
extern boolean THRSFTYCPUIFINH_bResulOutput2;
extern boolean THRSFTYCPUIFINH_bTimeOut1;
extern boolean THRSFTYCPUIFINH_bTimeOut2;
extern boolean THRSFTYCPUIFINH_bTimeOut3;
extern boolean THRSFTYCPUIFINH_bTimerInit2;
extern uint8 THRSFTYCPUIFINH_u8TpacThrStPrev;
extern uint8 THRSFTYCPUIFINH_u8TpacThrStPrev2;
extern uint16 THRSFTYCPUIFINH_u16Timer1;
extern uint16 THRSFTYCPUIFINH_u16Timer2;
extern uint16 THRSFTYCPUIFINH_u16Timer3;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRSFTYCPUIFINH_vidBswAbortcount(void);
void THRSFTYCPUIFINH_vidFuncGenerator(void);
void THRSFTYCPUIFINH_vidInit(void);
void THRSFTYCPUIFINH_vidInitOutput(void);
void THRSFTYCPUIFINH_vidMcwdgInhTest1(void);
void THRSFTYCPUIFINH_vidMcwdgInhTest2(void);
void THRSFTYCPUIFINH_vidMcwdgInhThr(void);
void THRSFTYCPUIFINH_vidMcwIhBswTstEd(void);
void THRSFTYCPUIFINH_vidMcwInhApiMngt(void);
void THRSFTYCPUIFINH_vidMcwInhTstEnd(void);
void THRSFTYCPUIFINH_vidOldStructMang(void);
void THRSFTYCPUIFINH_vidReadMcwInhib(void);
void THRSFTYCPUIFINH_vidRnitBswAbtcnt(void);


#endif /* THRSFTYCPUIFINH_L_H */

/*-------------------------------- end of file -------------------------------*/
