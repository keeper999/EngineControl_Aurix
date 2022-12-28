/***************************************************************************
;**
;** FILE NAME      : HEATSENO2US_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2US_L_H
#define HEATSENO2US_L_H

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

extern const uint8  HEATSENO2US_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean HEATSENO2US_bTimeout1;
extern boolean HEATSENO2US_bTimerInit;
extern boolean HEATSENO2US_bUBattAcvHeatLih;
extern boolean LsSys_bAcvLsUsMainOxCHeatLo;
extern boolean LsSys_bHeatWkuLsSysDone;
extern boolean LsSys_bLsUsBoostEnd;
extern boolean LsSys_bLsUsDetRTStall;
extern boolean LsSys_bLsUsMainOxcAcvFLO;
extern boolean LsSys_bLsUsMainOxCAcvHeatHi;
extern boolean LsSys_bLsUsMainOxCDewPtNOk;
extern boolean LsSys_bLsUsMainOxCDewPtOkLstStrt;
extern boolean LsSys_bLsUsMainOxCDiFLO;
extern boolean LsSys_bLsUsMainOxCHeatEna;
extern boolean LsSys_bLsUsMainOxCHeatHiEnd;
extern boolean LsSys_bLsUsMainOxCHeatHotEna;
extern boolean LsSys_bLsUsMainOxCHeatLoEnd;
extern boolean LsSys_bLsUsMainOxCHeatProtEnd;
extern boolean LsSys_bLsUsMainOxCHeatWkuEna;
extern boolean LsSys_bLsUsMainOxCHeatWkuEnd;
extern boolean LsSys_bLsUsTAirFLOEna;
extern boolean LsSys_bLsUsTCoolFLOEna;
extern boolean LsSys_bLsUsVehDstFLOEna;
extern boolean LsSys_bNotrackPwrLsUsMainOxCHeat;
extern uint32 LsSys_tiLsUsDlySinceLstHeatHi;
extern uint8 HEATSENO2US_stEngPrev;
extern uint8 HEATSENO2US_u8MainOxCHeatPrev;
extern uint8 HEATSENO2US_u8OxCHeatPrevslow;
extern uint8 LsSys_tiLsUsBoostProtReq;
extern uint16 LsSys_tiLsUsDlyAcvHeatLih;
extern uint16 LsSys_tiLsUsDlyDewTranNotOk;
extern uint16 LsSys_tiLsUsDlyDTrIntrOxCHt;
extern uint16 LsSys_tiLsUsDlyDTrIntrOxCHtPnt;
extern uint16 LsSys_tiLsUsDlyDTrOxCHt;
extern uint16 LsSys_tiLsUsDlyDTrOxCHtPnt;
extern uint16 LsSys_tiLsUsDlyMainOxCPhaseB;
extern uint16 LsSys_tiLsUsDlyMainOxCPhaseC;
extern uint16 LsSys_tiLsUsDlyMainOxCPhaseD;
extern uint16 LsSys_tiLsUsDlyMainOxCPhaseF;
extern uint16 LsSys_tiLsUsMainOxCDlyDewTranOk;
extern uint16 LsSys_tiLsUsMaxDlyHeatModStop;
extern uint16 LsSys_tiSumLsUsMainOxCHeatNull;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2US_vidAcvHeatWku(void);
void HEATSENO2US_vidDetDewPt(void);
void HEATSENO2US_vidDetDewPtRev(void);
void HEATSENO2US_vidDisableFLO(void);
void HEATSENO2US_vidDlyDewPt(void);
void HEATSENO2US_vidDlyDewTranOkStall(void);
void HEATSENO2US_vidFastLightOff(void);
void HEATSENO2US_vidInitOutput(void);
void HEATSENO2US_vidLsUsDetRTStall(void);
void HEATSENO2US_vidLsUsDetRTStallint(void);
void HEATSENO2US_vidLsUsDewPt(void);
void HEATSENO2US_vidLsUsMgrHeatState(void);
void HEATSENO2US_vidMgrFastTran(void);
void HEATSENO2US_vidMgrMidTran(void);
void HEATSENO2US_vidMgrSlowTran(void);
void HEATSENO2US_vidOxCHeatAftStrt(void);
void HEATSENO2US_vidOxCHeatReq(void);
void HEATSENO2US_vidTCoLsHeat(void);
void HEATSENO2US_vidTDsThrLsHeat(void);
void HEATSENO2US_vidTranAtoBandBtoA(void);
void HEATSENO2US_vidTranAToCOrAToE(void);
void HEATSENO2US_vidTranC1ToC2(void);
void HEATSENO2US_vidTranCToD(void);
void HEATSENO2US_vidTranCToEOrDToE(void);
void HEATSENO2US_vidTranEToF(void);
void HEATSENO2US_vidTranFToA(void);
void HEATSENO2US_vidTReCoLsHeat(void);


#endif /* HEATSENO2US_L_H */

/*-------------------------------- end of file -------------------------------*/
