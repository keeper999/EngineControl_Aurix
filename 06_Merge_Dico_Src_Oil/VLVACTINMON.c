/***************************************************************************
;**
;** FILE NAME      : VLVACTINMON.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINMON.H"
#include "VLVACTINMON_L.H"
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
const sint8  VlvAct_agInVlvDifThdMin_C = 0;
const sint8  VlvAct_agInVlvThdMax_C = 0;
const sint8  VlvAct_agInVlvThdMin_C = 0;
const uint8  VlvAct_agInVlvAmpThdMin_C = 0;
const uint8  VlvAct_agInVlvAmpThdMinC_C = 0;
const uint8  VlvAct_agInVlvAmpThdMinH_C = 0;
const uint8  VlvAct_agInVlvDifThdMax_C = 0;
const uint8  VlvAct_nInVlvAmpC_C = 0;
const uint8  VlvAct_nInVlvAmpH_C = 0;
const uint8  VlvAct_tiOfsInVlvC_C = 0;
const uint8  VlvAct_tiOfsInVlvH_C = 0;
const uint8  VLVACTINMON_u8Inhib = 0;
const sint16  VlvAct_agInVlvNegDif1_C = 0;
const sint16  VlvAct_agInVlvNegDif2_C = 0;
const sint16  VlvAct_agInVlvPosDif1_C = 0;
const sint16  VlvAct_agInVlvPosDif2_C = 0;
const sint16  VlvAct_tOilMaxInVlv_C = 0;
const sint16  VlvAct_tOilMinInVlv_C = 0;
const uint16  VlvAct_nEngMinInVlv_C = 0;
const uint16  VlvAct_nInVlvPosStatThd_C = 0;
const uint16  VlvAct_tiInVlvPosStatThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvAct_bAcvInColdFctDg;
boolean VlvAct_bAcvInColdFctDg1AgRead;
boolean VlvAct_bAcvInColdFctDg2AgRead;
boolean VlvAct_bAcvInColdFctDg3AgRead;
boolean VlvAct_bAcvInHotFctDg;
boolean VlvAct_bAcvInHotFctDg1AgRead;
boolean VlvAct_bAcvInHotFctDg2AgRead;
boolean VlvAct_bAcvInHotFctDg3AgRead;
boolean VlvAct_bAcvInHotStuckFctDg;
boolean VlvAct_bAcvInHotStuckFctDgAgRead;
boolean VlvAct_bDgoCmdCVlvActIn;
boolean VlvAct_bDgoCmdHVlvActIn;
boolean VlvAct_bDgoDftCVlvActIn;
boolean VlvAct_bDgoDftHVlvActIn;
boolean VlvAct_bDgoDifNeg1VlvActIn;
boolean VlvAct_bDgoDifNeg2VlvActIn;
boolean VlvAct_bDgoDifPos1VlvActIn;
boolean VlvAct_bDgoDifPos2VlvActIn;
boolean VlvAct_bDgoORngCVlvActIn;
boolean VlvAct_bDgoORngHVlvActIn;
boolean VlvAct_bDgoSlowC1VlvActIn;
boolean VlvAct_bDgoSlowC2VlvActIn;
boolean VlvAct_bDgoSlowH1VlvActIn;
boolean VlvAct_bDgoSlowH2VlvActIn;
boolean VlvAct_bDgoStuckH1VlvActIn;
boolean VlvAct_bDgoStuckH2VlvActIn;
boolean VlvAct_bDgoStuckH3VlvActIn;
boolean VlvAct_bDgoStuckHVlvActIn;
boolean VlvAct_bIn1AgDftC;
boolean VlvAct_bIn1AgDftH;
boolean VlvAct_bIn2AgDftC;
boolean VlvAct_bIn2AgDftH;
boolean VlvAct_bIn3AgDftC;
boolean VlvAct_bIn3AgDftH;
boolean VlvAct_bInAcvDifDg;
boolean VlvAct_bInAcvDifNegDg;
boolean VlvAct_bInAgDftHStuck;
boolean VlvAct_bInVlvSpAmpVarldc;
boolean VlvAct_bMonRunDifNeg1VlvActIn;
boolean VlvAct_bMonRunDifNeg2VlvActIn;
boolean VlvAct_bMonRunDifPos1VlvActIn;
boolean VlvAct_bMonRunDifPos2VlvActIn;
boolean VlvAct_bMonRunInColdFctDg;
boolean VlvAct_bMonRunInHotFctDg;
boolean VlvAct_bMonRunInHotStuckFctDg;
boolean VLVACTINMON_bAcvInColdFctDg;
boolean VLVACTINMON_bAcvInColdFctDgPrev;
boolean VLVACTINMON_bAcvInHotFctDg;
boolean VLVACTINMON_bAcvInHotFctDgPrev;
boolean VLVACTINMON_bAcvInHotStkFctDgPrv;
boolean VLVACTINMON_bAcvInHotStuckFctDg;
boolean VLVACTINMON_bAcvInServoPrev;
boolean VLVACTINMON_bSetPointInPrev;
sint8 VlvAct_agInVlvC1;
sint8 VlvAct_agInVlvC2;
sint8 VlvAct_agInVlvC3;
sint8 VlvAct_agInVlvH;
sint8 VlvAct_agInVlvH1;
sint8 VlvAct_agInVlvH2;
sint8 VlvAct_agInVlvH3;
sint8 VlvAct_agInVlvIni;
sint8 VlvSys_agCkOpInVlvReqRef0_int;
uint8 VlvAct_agInVlvAmp;
uint8 VlvAct_agInVlvDifC1;
uint8 VlvAct_agInVlvDifC2;
uint8 VlvAct_agInVlvDifC3;
uint8 VlvAct_agInVlvDifH;
uint8 VlvAct_agInVlvDifH1;
uint8 VlvAct_agInVlvDifH2;
uint8 VlvAct_agInVlvDifH3;
uint8 VlvAct_tiDlyInVlvC1;
uint8 VlvAct_tiDlyInVlvC2;
uint8 VlvAct_tiDlyInVlvC3;
uint8 VlvAct_tiDlyInVlvH;
uint8 VlvAct_tiDlyInVlvH1;
uint8 VlvAct_tiDlyInVlvH2;
uint8 VlvAct_tiDlyInVlvH3;
uint8 VLVACTINMON_u8CkOpInVlvRef0Prev;
uint8 VLVACTINMON_u8Timer1;
uint8 VLVACTINMON_u8Timer2;
uint8 VLVACTINMON_u8Timer3;
uint8 VLVACTINMON_u8Timer4;
uint8 VLVACTINMON_u8Timer5;
uint8 VLVACTINMON_u8Timer6;
uint8 VLVACTINMON_u8Timer7;
sint16 VlvAct_agInVlvNegDif;
sint16 VlvAct_agInVlvPosDif;
uint16 VlvAct_nInSpPosSpd;
uint16 VlvAct_tiInVlvPosStat;
uint16 VLVACTINMON_u16VxxVvtcInSpPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

