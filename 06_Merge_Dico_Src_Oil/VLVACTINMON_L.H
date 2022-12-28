/***************************************************************************
;**
;** FILE NAME      : VLVACTINMON_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINMON_L_H
#define VLVACTINMON_L_H

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

extern const uint8  VLVACTINMON_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bAcvInColdFctDg;
extern boolean VlvAct_bAcvInColdFctDg1AgRead;
extern boolean VlvAct_bAcvInColdFctDg2AgRead;
extern boolean VlvAct_bAcvInColdFctDg3AgRead;
extern boolean VlvAct_bAcvInHotFctDg;
extern boolean VlvAct_bAcvInHotFctDg1AgRead;
extern boolean VlvAct_bAcvInHotFctDg2AgRead;
extern boolean VlvAct_bAcvInHotFctDg3AgRead;
extern boolean VlvAct_bAcvInHotStuckFctDg;
extern boolean VlvAct_bAcvInHotStuckFctDgAgRead;
extern boolean VlvAct_bDgoCmdCVlvActIn;
extern boolean VlvAct_bDgoCmdHVlvActIn;
extern boolean VlvAct_bDgoDftCVlvActIn;
extern boolean VlvAct_bDgoDftHVlvActIn;
extern boolean VlvAct_bDgoDifNeg1VlvActIn;
extern boolean VlvAct_bDgoDifNeg2VlvActIn;
extern boolean VlvAct_bDgoDifPos1VlvActIn;
extern boolean VlvAct_bDgoDifPos2VlvActIn;
extern boolean VlvAct_bDgoORngCVlvActIn;
extern boolean VlvAct_bDgoORngHVlvActIn;
extern boolean VlvAct_bDgoSlowC1VlvActIn;
extern boolean VlvAct_bDgoSlowC2VlvActIn;
extern boolean VlvAct_bDgoSlowH1VlvActIn;
extern boolean VlvAct_bDgoSlowH2VlvActIn;
extern boolean VlvAct_bDgoStuckH1VlvActIn;
extern boolean VlvAct_bDgoStuckH2VlvActIn;
extern boolean VlvAct_bDgoStuckH3VlvActIn;
extern boolean VlvAct_bDgoStuckHVlvActIn;
extern boolean VlvAct_bIn1AgDftC;
extern boolean VlvAct_bIn1AgDftH;
extern boolean VlvAct_bIn2AgDftC;
extern boolean VlvAct_bIn2AgDftH;
extern boolean VlvAct_bIn3AgDftC;
extern boolean VlvAct_bIn3AgDftH;
extern boolean VlvAct_bInAcvDifDg;
extern boolean VlvAct_bInAcvDifNegDg;
extern boolean VlvAct_bInAgDftHStuck;
extern boolean VlvAct_bInVlvSpAmpVarldc;
extern boolean VlvAct_bMonRunDifNeg1VlvActIn;
extern boolean VlvAct_bMonRunDifNeg2VlvActIn;
extern boolean VlvAct_bMonRunDifPos1VlvActIn;
extern boolean VlvAct_bMonRunDifPos2VlvActIn;
extern boolean VlvAct_bMonRunInColdFctDg;
extern boolean VlvAct_bMonRunInHotFctDg;
extern boolean VlvAct_bMonRunInHotStuckFctDg;
extern boolean VLVACTINMON_bAcvInColdFctDg;
extern boolean VLVACTINMON_bAcvInColdFctDgPrev;
extern boolean VLVACTINMON_bAcvInHotFctDg;
extern boolean VLVACTINMON_bAcvInHotFctDgPrev;
extern boolean VLVACTINMON_bAcvInHotStkFctDgPrv;
extern boolean VLVACTINMON_bAcvInHotStuckFctDg;
extern boolean VLVACTINMON_bAcvInServoPrev;
extern boolean VLVACTINMON_bSetPointInPrev;
extern sint8 VlvAct_agInVlvC1;
extern sint8 VlvAct_agInVlvC2;
extern sint8 VlvAct_agInVlvC3;
extern sint8 VlvAct_agInVlvH;
extern sint8 VlvAct_agInVlvH1;
extern sint8 VlvAct_agInVlvH2;
extern sint8 VlvAct_agInVlvH3;
extern sint8 VlvAct_agInVlvIni;
extern sint8 VlvSys_agCkOpInVlvReqRef0_int;
extern uint8 VlvAct_agInVlvAmp;
extern uint8 VlvAct_agInVlvDifC1;
extern uint8 VlvAct_agInVlvDifC2;
extern uint8 VlvAct_agInVlvDifC3;
extern uint8 VlvAct_agInVlvDifH;
extern uint8 VlvAct_agInVlvDifH1;
extern uint8 VlvAct_agInVlvDifH2;
extern uint8 VlvAct_agInVlvDifH3;
extern uint8 VlvAct_tiDlyInVlvC1;
extern uint8 VlvAct_tiDlyInVlvC2;
extern uint8 VlvAct_tiDlyInVlvC3;
extern uint8 VlvAct_tiDlyInVlvH;
extern uint8 VlvAct_tiDlyInVlvH1;
extern uint8 VlvAct_tiDlyInVlvH2;
extern uint8 VlvAct_tiDlyInVlvH3;
extern uint8 VLVACTINMON_u8CkOpInVlvRef0Prev;
extern uint8 VLVACTINMON_u8Timer1;
extern uint8 VLVACTINMON_u8Timer2;
extern uint8 VLVACTINMON_u8Timer3;
extern uint8 VLVACTINMON_u8Timer4;
extern uint8 VLVACTINMON_u8Timer5;
extern uint8 VLVACTINMON_u8Timer6;
extern uint8 VLVACTINMON_u8Timer7;
extern sint16 VlvAct_agInVlvNegDif;
extern sint16 VlvAct_agInVlvPosDif;
extern uint16 VlvAct_nInSpPosSpd;
extern uint16 VlvAct_tiInVlvPosStat;
extern uint16 VLVACTINMON_u16VxxVvtcInSpPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINMON_vidColdDefServoDet(void);
void VLVACTINMON_vidColdDiagActCond(void);
void VLVACTINMON_vidColdDiagCalc(void);
void VLVACTINMON_vidColdDiagComp(void);
void VLVACTINMON_vidFstColdTempTest(void);
void VLVACTINMON_vidFstHotStkTempTest(void);
void VLVACTINMON_vidFstHotTempTest(void);
void VLVACTINMON_vidHotDefServoDet(void);
void VLVACTINMON_vidHotDiagActCond(void);
void VLVACTINMON_vidHotDiagCalc(void);
void VLVACTINMON_vidHotDiagComp(void);
void VLVACTINMON_vidHotStkDefServoDet(void);
void VLVACTINMON_vidHotStkDiagActCond(void);
void VLVACTINMON_vidHotStkDiagCalc(void);
void VLVACTINMON_vidHotStkDiagComp(void);
void VLVACTINMON_vidInitialization(void);
void VLVACTINMON_vidInitOffValComp(void);
void VLVACTINMON_vidNegStatErrorDiag(void);
void VLVACTINMON_vidOffsetSetPtComp(void);
void VLVACTINMON_vidPosStatErrorDiag(void);
void VLVACTINMON_vidSndColdTempTest(void);
void VLVACTINMON_vidSndHotTempTest(void);
void VLVACTINMON_vidThrdColdTemp(void);
void VLVACTINMON_vidThrdHotTemp(void);
void VLVACTINMON_vidTime_index_reset(void);


#endif /* VLVACTINMON_L_H */

/*-------------------------------- end of file -------------------------------*/
