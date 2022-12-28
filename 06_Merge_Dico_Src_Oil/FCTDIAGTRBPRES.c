/***************************************************************************
;**
;** FILE NAME      : FCTDIAGTRBPRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FCTDIAGTRBPRES.H"
#include "FCTDIAGTRBPRES_L.H"
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
const uint8  AirPres_rClsThdThr_C = 0;
const uint8  AirPres_tiBoostPresClCtlAcv_C = 0;
const uint8  AirPres_tiDifpUsThr_T[AIRPRES_TIDIFPUSTHR_T_COLS] = {0};
const uint8  AirPres_tiUsThrPlaus_AcvIdlCtl_C = 0;
const uint8  FCTDIAGTRBPRES_u8Inhib = 0;
const sint16  AirPres_pUsThrNatOfs_C = 0;
const uint16  AirPres_agDeltaVlvPosnThd_C = 0;
const uint16  AirPres_nDifpUsThr_A[AIRPRES_NDIFPUSTHR_A_COLS] = {0};
const uint16  AirPres_nEng_pAirExtMes_T[AIRPRES_NENG_PAIREXTMES_T_COLS] = {0};
const uint16  AirPres_pAirExtMes_A[AIRPRES_PAIREXTMES_A_COLS] = {0};
const uint16  AirPres_pAirExtMes_C = 0;
const uint16  AirPres_pAirExtMes1_C = 0;
const uint16  AirPres_pAirExtMes2_C = 0;
const uint16  AirPres_pUsThrBoostPlaus_C = 0;
const uint16  AirPres_pUsThrIdlPlaus_C = 0;
const uint16  AirPres_pUsThrMaxDiag_T[AIRPRES_PUSTHRMAXDIAG_T_COLS] = {0};
const uint16  AirPres_pUsThrNegDif1_C = 0;
const uint16  AirPres_pUsThrNegDif2_C = 0;
const uint16  AirPres_pUsThrNegDifSen_C = 0;
const uint16  AirPres_pUsThrNegDifVlvPosn1_C = 0;
const uint16  AirPres_pUsThrNegDifVlvPosn2_C = 0;
const uint16  AirPres_pUsThrPosDif1_C = 0;
const uint16  AirPres_pUsThrPosDif2_C = 0;
const uint16  AirPres_pUsThrPosDifSen_C = 0;
const uint16  Ext_pAirExtMesSI_A[EXT_PAIREXTMESSI_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AirPres_bAcvNegDifFctVlvPosn;
boolean AirPres_bDgoMaxAbs_pUsThr;
boolean AirPres_bDgoNegDif_pUsThrSen;
boolean AirPres_bDgoNegDif1_pUsThr;
boolean AirPres_bDgoNegDif2_pUsThr;
boolean AirPres_bDgoPlaus_pUsThrBoost;
boolean AirPres_bDgoPlaus_pUsThrIdl;
boolean AirPres_bDgoPosDif_pUsThrSen;
boolean AirPres_bDgoPosDif1_pUsThr;
boolean AirPres_bDgoPosDif2_pUsThr;
boolean AirPres_bMonRunMaxAbs_pUsThr;
boolean AirPres_bMonRunNegDif_pUsThrSen;
boolean AirPres_bMonRunNegDif1_pUsThr;
boolean AirPres_bMonRunNegDif2_pUsThr;
boolean AirPres_bMonRunPlaus_pUsThrBoost;
boolean AirPres_bMonRunPlaus_pUsThrIdl;
boolean AirPres_bMonRunPosDif_pUsThrSen;
boolean AirPres_bMonRunPosDif1_pUsThr;
boolean AirPres_bMonRunPosDif2_pUsThr;
boolean FCtDIAGTRBPRES_bAcvIdlCtlPrev;
boolean FCTDIAGTRBPRES_bBoostPresPrev;
boolean FCTDIAGTRBPRES_bOutTimer1;
boolean FCTDIAGTRBPRES_bOutTimer2;
boolean FCTDIAGTRBPRES_bOutTimer3;
boolean FCTDIAGTRBPRES_btiDifpUsThr;
boolean FCTDIAGTRBPRES_btiDifpUsThrPrev;
uint8 AirPres_ctTiBoostPresClCtlAcv;
uint8 AirPres_ctTiUsThrPlaus;
uint8 AirPres_tiDifpUsThr;
uint8 FCTDIAGTRBPRES_u8tiDifpUsThr;
uint16 AirPres_agAbsDeltaVlvExToMin;
uint16 AirPres_agAbsDeltaVlvInToMax;
uint16 AirPres_pAirExtMes1;
uint16 AirPres_pAirExtMes2;
uint16 AirPres_pUsThrMaxDiag;
uint16 AirPres_pUsThrNegDif;
uint16 AirPres_pUsThrNegDifSen;
uint16 AirPres_pUsThrPlaus1;
uint16 AirPres_pUsThrPlaus2;
uint16 AirPres_pUsThrPosDif;
uint16 AirPres_pUsThrPosDifSen;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

