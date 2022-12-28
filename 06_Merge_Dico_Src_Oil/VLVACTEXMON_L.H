/***************************************************************************
;**
;** FILE NAME      : VLVACTEXMON_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXMON_L_H
#define VLVACTEXMON_L_H

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

extern const uint8  VLVACTEXMON_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bAcvExColdFctDg;
extern boolean VlvAct_bAcvExColdFctDg1AgRead;
extern boolean VlvAct_bAcvExColdFctDg2AgRead;
extern boolean VlvAct_bAcvExColdFctDg3AgRead;
extern boolean VlvAct_bAcvExHotFctDg;
extern boolean VlvAct_bAcvExHotFctDg1AgRead;
extern boolean VlvAct_bAcvExHotFctDg2AgRead;
extern boolean VlvAct_bAcvExHotFctDg3AgRead;
extern boolean VlvAct_bAcvExHotStuckFctDg;
extern boolean VlvAct_bAcvExHotStuckFctDgAgRead;
extern boolean VlvAct_bDgoCmdCVlvActEx;
extern boolean VlvAct_bDgoCmdHVlvActEx;
extern boolean VlvAct_bDgoDftCVlvActEx;
extern boolean VlvAct_bDgoDftHVlvActEx;
extern boolean VlvAct_bDgoDifNeg1VlvActEx;
extern boolean VlvAct_bDgoDifNeg2VlvActEx;
extern boolean VlvAct_bDgoDifPos1VlvActEx;
extern boolean VlvAct_bDgoDifPos2VlvActEx;
extern boolean VlvAct_bDgoORngCVlvActEx;
extern boolean VlvAct_bDgoORngHVlvActEx;
extern boolean VlvAct_bDgoSlowC1VlvActEx;
extern boolean VlvAct_bDgoSlowC2VlvActEx;
extern boolean VlvAct_bDgoSlowH1VlvActEx;
extern boolean VlvAct_bDgoSlowH2VlvActEx;
extern boolean VlvAct_bDgoStuckH1VlvActEx;
extern boolean VlvAct_bDgoStuckH2VlvActEx;
extern boolean VlvAct_bDgoStuckH3VlvActEx;
extern boolean VlvAct_bDgoStuckHVlvActEx;
extern boolean VlvAct_bEx1AgDftC;
extern boolean VlvAct_bEx1AgDftH;
extern boolean VlvAct_bEx2AgDftC;
extern boolean VlvAct_bEx2AgDftH;
extern boolean VlvAct_bEx3AgDftC;
extern boolean VlvAct_bEx3AgDftH;
extern boolean VlvAct_bExAcvDifDg;
extern boolean VlvAct_bExAcvDifNegDg;
extern boolean VlvAct_bExAgDftHStuck;
extern boolean VlvAct_bExVlvSpAmpVarldc;
extern boolean VlvAct_bMonRunDifNeg1VlvActEx;
extern boolean VlvAct_bMonRunDifNeg2VlvActEx;
extern boolean VlvAct_bMonRunDifPos1VlvActEx;
extern boolean VlvAct_bMonRunDifPos2VlvActEx;
extern boolean VlvAct_bMonRunExColdFctDg;
extern boolean VlvAct_bMonRunExHotFctDg;
extern boolean VlvAct_bMonRunExHotStuckFctDg;
extern boolean VLVACTEXMON_bAcvExColdFctDg;
extern boolean VLVACTEXMON_bAcvExColdFctDgPrev;
extern boolean VLVACTEXMON_bAcvExHotFctDg;
extern boolean VLVACTEXMON_bAcvExHotFctDgPrev;
extern boolean VLVACTEXMON_bAcvExHotStkFctDgPrv;
extern boolean VLVACTEXMON_bAcvExHotStuckFctDg;
extern boolean VLVACTEXMON_bAcvExServoPrev;
extern boolean VLVACTEXMON_bSetPointExPrev;
extern sint8 VlvAct_agExVlvC1;
extern sint8 VlvAct_agExVlvC2;
extern sint8 VlvAct_agExVlvC3;
extern sint8 VlvAct_agExVlvH;
extern sint8 VlvAct_agExVlvH1;
extern sint8 VlvAct_agExVlvH2;
extern sint8 VlvAct_agExVlvH3;
extern sint8 VlvAct_agExVlvIni;
extern sint8 VlvSys_agCkClsExVlvReqRef0_int;
extern uint8 VlvAct_agExVlvAmp;
extern uint8 VlvAct_agExVlvDifC1;
extern uint8 VlvAct_agExVlvDifC2;
extern uint8 VlvAct_agExVlvDifC3;
extern uint8 VlvAct_agExVlvDifH;
extern uint8 VlvAct_agExVlvDifH1;
extern uint8 VlvAct_agExVlvDifH2;
extern uint8 VlvAct_agExVlvDifH3;
extern uint8 VlvAct_tiDlyExVlvC1;
extern uint8 VlvAct_tiDlyExVlvC2;
extern uint8 VlvAct_tiDlyExVlvC3;
extern uint8 VlvAct_tiDlyExVlvH;
extern uint8 VlvAct_tiDlyExVlvH1;
extern uint8 VlvAct_tiDlyExVlvH2;
extern uint8 VlvAct_tiDlyExVlvH3;
extern uint8 VLVACTEXMON_u8CkClsExVlvRef0Prev;
extern uint8 VLVACTEXMON_u8Timer1;
extern uint8 VLVACTEXMON_u8Timer2;
extern uint8 VLVACTEXMON_u8Timer3;
extern uint8 VLVACTEXMON_u8Timer4;
extern uint8 VLVACTEXMON_u8Timer5;
extern uint8 VLVACTEXMON_u8Timer6;
extern uint8 VLVACTEXMON_u8Timer7;
extern sint16 VlvAct_agExVlvNegDif;
extern sint16 VlvAct_agExVlvPosDif;
extern uint16 VlvAct_nExSpPosSpd;
extern uint16 VlvAct_tiExVlvPosStat;
extern uint16 VLVACTEXMON_u16VxxVvtcExSpPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXMON_vidColdDefServoDet(void);
void VLVACTEXMON_vidColdDiagActCond(void);
void VLVACTEXMON_vidColdDiagCalc(void);
void VLVACTEXMON_vidColdDiagComp(void);
void VLVACTEXMON_vidFstColdTempTest(void);
void VLVACTEXMON_vidFstHotStkTempTest(void);
void VLVACTEXMON_vidFstHotTempTest(void);
void VLVACTEXMON_vidHotDefServoDet(void);
void VLVACTEXMON_vidHotDiagActCond(void);
void VLVACTEXMON_vidHotDiagCalc(void);
void VLVACTEXMON_vidHotDiagComp(void);
void VLVACTEXMON_vidHotStkDefServoDet(void);
void VLVACTEXMON_vidHotStkDiagActCond(void);
void VLVACTEXMON_vidHotStkDiagCalc(void);
void VLVACTEXMON_vidHotStkDiagComp(void);
void VLVACTEXMON_vidInitialization(void);
void VLVACTEXMON_vidInitOffValComp(void);
void VLVACTEXMON_vidNegStatErrorDiag(void);
void VLVACTEXMON_vidOffsetSetPtComp(void);
void VLVACTEXMON_vidPosStatErrorDiag(void);
void VLVACTEXMON_vidSndColdTempTest(void);
void VLVACTEXMON_vidSndHotTempTest(void);
void VLVACTEXMON_vidThrdColdTemp(void);
void VLVACTEXMON_vidThrdHotTemp(void);
void VLVACTEXMON_vidTime_index_reset(void);


#endif /* VLVACTEXMON_L_H */

/*-------------------------------- end of file -------------------------------*/
