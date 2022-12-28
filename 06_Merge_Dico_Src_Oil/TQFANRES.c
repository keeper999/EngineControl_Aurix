/***************************************************************************
;**
;** FILE NAME      : TQFANRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQFANRES.H"
#include "TQFANRES_L.H"
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
const uint8  TQFANRES_u8Inhib = 0;
const uint8  TqRes_facCmpFanRes_M[TQRES_FACCMPFANRES_M_LNS][TQRES_FACCMPFANRES_M_COLS] = {0};
const uint8  TqRes_facFilTqFanLoss_C = 0;
const uint8  TqRes_rSpdThrFanRes_C = 0;
const uint8  TqRes_tiFanRes_C = 0;
const sint16  TqRes_tqDecMaxFanRes_C = 0;
const uint16  TqRes_nEngFanRes_A[TQRES_NENGFANRES_A_COLS] = {0};
const uint16  TqRes_spdVehFanRes_A[TQRES_SPDVEHFANRES_A_COLS] = {0};
const uint16  TqRes_tqCmpB1FanLoss_C = 0;
const uint16  TqRes_tqCmpGvB2FanLoss_C = 0;
const uint16  TqRes_tqCmpPvB2FanLoss_C = 0;
const uint16  TqRes_tqCmpPvGvB2FanLoss_C = 0;
const uint16  TqRes_tqFanResB1_C = 0;
const uint16  TqRes_tqFanResB2_C = 0;
const uint16  TqRes_tqFanResC_C = 0;
const uint16  TqRes_tqIncMaxFanRes_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TQFANRES_bCdnFanResPrev;
boolean TQFANRES_bCmdHiSpdFanPrev;
boolean TQFANRES_bCmdLoSpdFanPrev;
boolean TQFANRES_bGmvTrigger;
boolean TQFANRES_bTurnOffDelayIn;
boolean TqRes_bCdnFanRes;
boolean TqRes_bCdnHiSpdFanRes_MP;
boolean TqRes_bCdnLnrSpdFanRes_MP;
boolean TqRes_bCdnLoSpdFanRes_MP;
boolean TqRes_bCmdHiSpdFan;
boolean TqRes_bCmdLoSpdFan;
boolean TqRes_bRstTqFanLoss_MP;
boolean TqRes_bTarHiSpdFan;
boolean TqRes_bTarLoSpdFan;
uint32 TQFANRES_u32FiltredFanStrtLosMem;
uint8 TqRes_rSpdFanReq;
uint8 TqRes_tiFanRes;
uint16 TQFANRES_u16tiFanResCpt1;
uint16 TQFANRES_u16tiFanResCpt2;
uint16 TQFANRES_u16tiFanResCpt3;
uint16 TqRes_facCmpFanRes;
uint16 TqRes_tqFanRes;
uint16 TqRes_tqFanResNotSat_MP;
uint16 TqRes_tqFanResSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

