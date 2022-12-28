/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DS_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2DS_L_H
#define HEATSENO2DS_L_H

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

extern const uint8  HEATSENO2DS_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean HEATSENO2DS_bTimeout1;
extern boolean HEATSENO2DS_bTimerInit;
extern boolean HEATSENO2DS_bUBattAcvHeatLih;
extern boolean LsSys_bAcvLsDsMainOxCHeatLo;
extern boolean LsSys_bLsDsBoostEnd;
extern boolean LsSys_bLsDsDetRTStall;
extern boolean LsSys_bLsDsMainOxCAcvHeatHi;
extern boolean LsSys_bLsDsMainOxCDewPtNOk;
extern boolean LsSys_bLsDsMainOxCDewPtOkLstStrt;
extern boolean LsSys_bLsDsMainOxCHeatEna;
extern boolean LsSys_bLsDsMainOxCHeatHiEnd;
extern boolean LsSys_bLsDsMainOxCHeatHotEna;
extern boolean LsSys_bLsDsMainOxCHeatLoEnd;
extern boolean LsSys_bLsDsMainOxCHeatProtEnd;
extern boolean LsSys_bNotrackPwrLsDsMainOxCHeat;
extern uint32 LsSys_tiLsDsDlySinceLstHeatHi;
extern uint8 HEATSENO2DS_stEngPrev;
extern uint8 HEATSENO2DS_u8MainOxCHeatPrev;
extern uint8 HEATSENO2DS_u8OxCHeatPrevslow;
extern uint8 LsSys_tiLsDsBoostProtReq;
extern uint16 LsSys_tiLsDsDlyAcvHeatLih;
extern uint16 LsSys_tiLsDsDlyDewTranNotOk;
extern uint16 LsSys_tiLsDsDlyDTrIntrOxCHt;
extern uint16 LsSys_tiLsDsDlyDTrIntrOxCHtPnt;
extern uint16 LsSys_tiLsDsDlyDTrOxCHt;
extern uint16 LsSys_tiLsDsDlyDTrOxCHtPnt;
extern uint16 LsSys_tiLsDsDlyMainOxCPhaseC;
extern uint16 LsSys_tiLsDsDlyMainOxCPhaseD;
extern uint16 LsSys_tiLsDsDlyMainOxCPhaseF;
extern uint16 LsSys_tiLsDsMainOxCDlyDewTranOk;
extern uint16 LsSys_tiLsDsMaxDlyHeatModStop;
extern uint16 LsSys_tiSumLsDsMainOxCHeatNull;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2DS_vidDetDewPt(void);
void HEATSENO2DS_vidDetDewPtRev(void);
void HEATSENO2DS_vidDlyDewPt(void);
void HEATSENO2DS_vidDlyDewTranOkStall(void);
void HEATSENO2DS_vidInitOutput(void);
void HEATSENO2DS_vidLsDsDetRTStall(void);
void HEATSENO2DS_vidLsDsDetRTStallint(void);
void HEATSENO2DS_vidLsDsDewPt(void);
void HEATSENO2DS_vidLsDsMgrHeatState(void);
void HEATSENO2DS_vidMgrFastTran(void);
void HEATSENO2DS_vidMgrMidTran(void);
void HEATSENO2DS_vidMgrSlowTran(void);
void HEATSENO2DS_vidTranAToCOrAToE(void);
void HEATSENO2DS_vidTranC1toC2(void);
void HEATSENO2DS_vidTranCToD(void);
void HEATSENO2DS_vidTranCToEOrDToE(void);
void HEATSENO2DS_vidTranEToF(void);
void HEATSENO2DS_vidTranFToA(void);


#endif /* HEATSENO2DS_L_H */

/*-------------------------------- end of file -------------------------------*/
