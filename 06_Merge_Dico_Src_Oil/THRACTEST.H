/***************************************************************************
;**
;** FILE NAME      : THRACTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRACTEST_H
#define THRACTEST_H

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

extern const uint8  ActrTstThr_DynTstMaxDiffPosn;
extern const uint8  ActrTstThr_GapTstMaxDiffPosn;
extern const uint8  ActrTstThr_GapTstMinDiffPosn;
extern const uint8  ActrTstThr_HighPosn;
extern const uint8  ActrTstThr_LowPosn;
extern const uint8  ActrTstThr_MidPosn;
extern const uint8  THRACTEST_u8Inhib;
extern const uint16  ActrTstThr_DynTstDwnTime;
extern const uint16  ActrTstThr_DynTstUpTime;
extern const uint16  ActrTstThr_GapTstTime;
extern const uint16  ActrTstThr_Phase1Time;
extern const uint16  ActrTstThr_Phase2Time;
extern const uint16  ActrTstThr_Phase3Time;
extern const uint16  ActrTstThr_Phase4Time;
extern const uint16  ActrTstThr_Phase5Time;
extern const uint16  ActrTstThr_Phase6Time;
extern const uint16  ActrTstThr_Phase7Time;
extern const uint16  ActrTstThr_Tempo_C;
extern const uint16  ActrTstThr_WaitTime;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bDynActrTst;
extern boolean Thr_bGapActrTst;
extern boolean Thr_bThrTstCmpl;
extern boolean Thr_bTstInProgs;
extern uint16 Thr_rSpPosActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveRst_ActrTstThr(void);
void Thr_SdlMid_ActrTstThr(void);


#endif /* THRACTEST_H */

/*-------------------------------- end of file -------------------------------*/
