/***************************************************************************
;**
;** FILE NAME      : VLVACTEXCLN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXCLN_L_H
#define VLVACTEXCLN_L_H

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

extern const uint8  VLVACTEXCLN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bAcvExHealCln;
extern boolean VlvAct_bDgoClnErrVlvActEx;
extern boolean VlvAct_bExFrstClnStReq;
extern boolean VlvAct_bExHealClnEnd;
extern boolean VlvAct_bExHealClnStFrstReq;
extern boolean VlvAct_bExHealClnStMonGlblReq;
extern boolean VlvAct_bExHealClnStMonReq;
extern boolean VlvAct_bExManClnEnaIdc;
extern boolean VlvAct_bExNormClnEnd;
extern boolean VlvAct_bExNormClnStReq;
extern boolean VlvAct_bMonRunClnErrVlvActEx;
extern boolean VLVACTEXCLN_bFrtErrCntRst_Prev;
extern boolean VLVACTEXCLN_bInitTimer1_Prev;
extern boolean VLVACTEXCLN_bInitTimer2_Prev;
extern boolean VLVACTEXCLN_bLocalCalcPrev;
extern boolean VLVACTEXCLN_bLocalComparePrev;
extern boolean VLVACTEXCLN_bManCleanVarUpPrev;
extern boolean VLVACTEXCLN_bRctClnVarUdtPrev;
extern boolean VLVACTEXCLN_bTimeout;
extern boolean VLVACTEXCLN_bTimeout1;
extern boolean VLVACTEXCLN_bTimeout2;
extern boolean VLVACTEXCLN_bTriggerPrev;
extern boolean VLVACTEXCLN_bVlAcvExHealCln_Prev;
extern boolean VLVACTEXCLN_bVlvActClnBeEnaPrev;
extern uint32 VLVACTEXCLN_u32TimerCount2;
extern uint8 VlvAct_ctExFrstClnCyc;
extern uint8 VlvAct_ctExHealClnDone;
extern uint8 VlvAct_CtExHealClnErr;
extern uint8 VlvAct_ctExNormClnDone;
extern uint8 VlvAct_tiExClnIdc;
extern uint8 VlvAct_tiExFrstClnIdc;
extern uint8 VlvAct_tiExHealClnIdc;
extern uint8 VlvAct_tiExNormClnIdc;
extern uint16 VlvAct_tiExHealClnMonErrDly;
extern uint16 VLVACTEXCLN_u16TimerCount;
extern uint16 VLVACTEXCLN_u16TimerCount1;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXCLN_vidClnAlgCalc(void);
void VLVACTEXCLN_vidClnCnd(void);
void VLVACTEXCLN_vidClnInCnteFrstcln(void);
void VLVACTEXCLN_vidClnIndTiCnt(void);
void VLVACTEXCLN_vidClnIndTmCntPct(void);
void VLVACTEXCLN_vidClnIndTmCntRct(void);
void VLVACTEXCLN_vidCmdCalc(void);
void VLVACTEXCLN_vidCmdcmp(void);
void VLVACTEXCLN_vidErrCntRst(void);
void VLVACTEXCLN_vidErrCountRst(void);
void VLVACTEXCLN_vidFrstCleaCond(void);
void VLVACTEXCLN_vidFrstCleanVarUpdte(void);
void VLVACTEXCLN_vidhealClnMngTimeRst(void);
void VLVACTEXCLN_vidInitOutput(void);
void VLVACTEXCLN_vidManCleanVarUpdate(void);
void VLVACTEXCLN_vidPctClnVarUdt(void);
void VLVACTEXCLN_vidPctcnd(void);
void VLVACTEXCLN_vidRctClnUdt(void);
void VLVACTEXCLN_vidRctClnVarUdt(void);
void VLVACTEXCLN_vidRctCnd(void);
void VLVACTEXCLN_vidRctCndFrtcln(void);


#endif /* VLVACTEXCLN_L_H */

/*-------------------------------- end of file -------------------------------*/
