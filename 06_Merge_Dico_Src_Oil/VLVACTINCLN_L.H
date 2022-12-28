/***************************************************************************
;**
;** FILE NAME      : VLVACTINCLN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINCLN_L_H
#define VLVACTINCLN_L_H

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

extern const uint8  VLVACTINCLN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bAcvInHealCln;
extern boolean VlvAct_bDgoClnErrVlvActIn;
extern boolean VlvAct_bInFrstClnStReq;
extern boolean VlvAct_bInHealClnEnd;
extern boolean VlvAct_bInHealClnStFrstReq;
extern boolean VlvAct_bInHealClnStMonGlblReq;
extern boolean VlvAct_bInHealClnStMonReq;
extern boolean VlvAct_bInManClnEnaIdc;
extern boolean VlvAct_bInNormClnEnd;
extern boolean VlvAct_bInNormClnStReq;
extern boolean VlvAct_bMonRunClnErrVlvActIn;
extern boolean VLVACTINCLN_bCompVcpiVlv_Prev;
extern boolean VLVACTINCLN_bFrtErrCntRst_Prev;
extern boolean VLVACTINCLN_bInitTimer1_Prev;
extern boolean VLVACTINCLN_bInitTimer2_Prev;
extern boolean VLVACTINCLN_bLocalCalcPrev;
extern boolean VLVACTINCLN_bLocalComparePrev;
extern boolean VLVACTINCLN_bManCleanVarUpPrev;
extern boolean VLVACTINCLN_bRctClnVarUdtPrev;
extern boolean VLVACTINCLN_bTimeout;
extern boolean VLVACTINCLN_bTimeout1;
extern boolean VLVACTINCLN_bTimeout2;
extern boolean VLVACTINCLN_bTriggerPrev;
extern boolean VLVACTINCLN_bVlAcvInHealCln_Prev;
extern boolean VLVACTINCLN_bVlvActClnBeEnaPrev;
extern uint32 VLVACTINCLN_u32TimerCount2;
extern uint8 VlvAct_ctInFrstClnCyc;
extern uint8 VlvAct_ctInHealClnDone;
extern uint8 VlvAct_CtInHealClnErr;
extern uint8 VlvAct_ctInNormClnDone;
extern uint8 VlvAct_tiInClnIdc;
extern uint8 VlvAct_tiInFrstClnIdc;
extern uint8 VlvAct_tiInHealClnIdc;
extern uint8 VlvAct_tiInNormClnIdc;
extern uint16 VlvAct_tiInHealClnMonErrDly;
extern uint16 VLVACTINCLN_u16TimerCount;
extern uint16 VLVACTINCLN_u16TimerCount1;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINCLN_vidClnAlgCalc(void);
void VLVACTINCLN_vidClnCnd(void);
void VLVACTINCLN_vidClnInCnteFrstcln(void);
void VLVACTINCLN_vidClnIndTiCnt(void);
void VLVACTINCLN_vidClnIndTmCntPct(void);
void VLVACTINCLN_vidClnIndTmCntRct(void);
void VLVACTINCLN_vidCmdCalc(void);
void VLVACTINCLN_vidCmdcmp(void);
void VLVACTINCLN_vidErrCntRst(void);
void VLVACTINCLN_vidErrCountRst(void);
void VLVACTINCLN_vidFrstCleaCond(void);
void VLVACTINCLN_vidFrstCleanVarUpdte(void);
void VLVACTINCLN_vidhealClnMngTimeRst(void);
void VLVACTINCLN_vidInitOutput(void);
void VLVACTINCLN_vidManCleanVarUpdate(void);
void VLVACTINCLN_vidPctClnVarUdt(void);
void VLVACTINCLN_vidPctcnd(void);
void VLVACTINCLN_vidRctClnUdt(void);
void VLVACTINCLN_vidRctClnVarUdt(void);
void VLVACTINCLN_vidRctCnd(void);
void VLVACTINCLN_vidRctCndFrtcln(void);


#endif /* VLVACTINCLN_L_H */

/*-------------------------------- end of file -------------------------------*/
