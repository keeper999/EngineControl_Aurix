/***************************************************************************
;**
;** FILE NAME      : VLVACTEXMON.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXMON.H"
#include "VLVACTEXMON_L.H"
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
const sint8  VlvAct_agExVlvDifThdMin_C = 0;
const sint8  VlvAct_agExVlvThdMax_C = 0;
const sint8  VlvAct_agExVlvThdMin_C = 0;
const uint8  VlvAct_agExVlvAmpThdMin_C = 0;
const uint8  VlvAct_agExVlvAmpThdMinC_C = 0;
const uint8  VlvAct_agExVlvAmpThdMinH_C = 0;
const uint8  VlvAct_agExVlvDifThdMax_C = 0;
const uint8  VlvAct_nExVlvAmpC_C = 0;
const uint8  VlvAct_nExVlvAmpH_C = 0;
const uint8  VlvAct_tiOfsExVlvC_C = 0;
const uint8  VlvAct_tiOfsExVlvH_C = 0;
const uint8  VLVACTEXMON_u8Inhib = 0;
const sint16  VlvAct_agExVlvNegDif1_C = 0;
const sint16  VlvAct_agExVlvNegDif2_C = 0;
const sint16  VlvAct_agExVlvPosDif1_C = 0;
const sint16  VlvAct_agExVlvPosDif2_C = 0;
const sint16  VlvAct_tOilMaxExVlv_C = 0;
const sint16  VlvAct_tOilMinExVlv_C = 0;
const uint16  VlvAct_nEngMinExVlv_C = 0;
const uint16  VlvAct_nExVlvPosStatThd_C = 0;
const uint16  VlvAct_tiExVlvPosStatThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvAct_bAcvExColdFctDg;
boolean VlvAct_bAcvExColdFctDg1AgRead;
boolean VlvAct_bAcvExColdFctDg2AgRead;
boolean VlvAct_bAcvExColdFctDg3AgRead;
boolean VlvAct_bAcvExHotFctDg;
boolean VlvAct_bAcvExHotFctDg1AgRead;
boolean VlvAct_bAcvExHotFctDg2AgRead;
boolean VlvAct_bAcvExHotFctDg3AgRead;
boolean VlvAct_bAcvExHotStuckFctDg;
boolean VlvAct_bAcvExHotStuckFctDgAgRead;
boolean VlvAct_bDgoCmdCVlvActEx;
boolean VlvAct_bDgoCmdHVlvActEx;
boolean VlvAct_bDgoDftCVlvActEx;
boolean VlvAct_bDgoDftHVlvActEx;
boolean VlvAct_bDgoDifNeg1VlvActEx;
boolean VlvAct_bDgoDifNeg2VlvActEx;
boolean VlvAct_bDgoDifPos1VlvActEx;
boolean VlvAct_bDgoDifPos2VlvActEx;
boolean VlvAct_bDgoORngCVlvActEx;
boolean VlvAct_bDgoORngHVlvActEx;
boolean VlvAct_bDgoSlowC1VlvActEx;
boolean VlvAct_bDgoSlowC2VlvActEx;
boolean VlvAct_bDgoSlowH1VlvActEx;
boolean VlvAct_bDgoSlowH2VlvActEx;
boolean VlvAct_bDgoStuckH1VlvActEx;
boolean VlvAct_bDgoStuckH2VlvActEx;
boolean VlvAct_bDgoStuckH3VlvActEx;
boolean VlvAct_bDgoStuckHVlvActEx;
boolean VlvAct_bEx1AgDftC;
boolean VlvAct_bEx1AgDftH;
boolean VlvAct_bEx2AgDftC;
boolean VlvAct_bEx2AgDftH;
boolean VlvAct_bEx3AgDftC;
boolean VlvAct_bEx3AgDftH;
boolean VlvAct_bExAcvDifDg;
boolean VlvAct_bExAcvDifNegDg;
boolean VlvAct_bExAgDftHStuck;
boolean VlvAct_bExVlvSpAmpVarldc;
boolean VlvAct_bMonRunDifNeg1VlvActEx;
boolean VlvAct_bMonRunDifNeg2VlvActEx;
boolean VlvAct_bMonRunDifPos1VlvActEx;
boolean VlvAct_bMonRunDifPos2VlvActEx;
boolean VlvAct_bMonRunExColdFctDg;
boolean VlvAct_bMonRunExHotFctDg;
boolean VlvAct_bMonRunExHotStuckFctDg;
boolean VLVACTEXMON_bAcvExColdFctDg;
boolean VLVACTEXMON_bAcvExColdFctDgPrev;
boolean VLVACTEXMON_bAcvExHotFctDg;
boolean VLVACTEXMON_bAcvExHotFctDgPrev;
boolean VLVACTEXMON_bAcvExHotStkFctDgPrv;
boolean VLVACTEXMON_bAcvExHotStuckFctDg;
boolean VLVACTEXMON_bAcvExServoPrev;
boolean VLVACTEXMON_bSetPointExPrev;
sint8 VlvAct_agExVlvC1;
sint8 VlvAct_agExVlvC2;
sint8 VlvAct_agExVlvC3;
sint8 VlvAct_agExVlvH;
sint8 VlvAct_agExVlvH1;
sint8 VlvAct_agExVlvH2;
sint8 VlvAct_agExVlvH3;
sint8 VlvAct_agExVlvIni;
sint8 VlvSys_agCkClsExVlvReqRef0_int;
uint8 VlvAct_agExVlvAmp;
uint8 VlvAct_agExVlvDifC1;
uint8 VlvAct_agExVlvDifC2;
uint8 VlvAct_agExVlvDifC3;
uint8 VlvAct_agExVlvDifH;
uint8 VlvAct_agExVlvDifH1;
uint8 VlvAct_agExVlvDifH2;
uint8 VlvAct_agExVlvDifH3;
uint8 VlvAct_tiDlyExVlvC1;
uint8 VlvAct_tiDlyExVlvC2;
uint8 VlvAct_tiDlyExVlvC3;
uint8 VlvAct_tiDlyExVlvH;
uint8 VlvAct_tiDlyExVlvH1;
uint8 VlvAct_tiDlyExVlvH2;
uint8 VlvAct_tiDlyExVlvH3;
uint8 VLVACTEXMON_u8CkClsExVlvRef0Prev;
uint8 VLVACTEXMON_u8Timer1;
uint8 VLVACTEXMON_u8Timer2;
uint8 VLVACTEXMON_u8Timer3;
uint8 VLVACTEXMON_u8Timer4;
uint8 VLVACTEXMON_u8Timer5;
uint8 VLVACTEXMON_u8Timer6;
uint8 VLVACTEXMON_u8Timer7;
sint16 VlvAct_agExVlvNegDif;
sint16 VlvAct_agExVlvPosDif;
uint16 VlvAct_nExSpPosSpd;
uint16 VlvAct_tiExVlvPosStat;
uint16 VLVACTEXMON_u16VxxVvtcExSpPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

