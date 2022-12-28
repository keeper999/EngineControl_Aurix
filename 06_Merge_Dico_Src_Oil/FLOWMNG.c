/***************************************************************************
;**
;** FILE NAME      : FLOWMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FLOWMNG.H"
#include "FLOWMNG_L.H"
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
const boolean  Cf_rBattSoCSeln_C = 0;
const boolean  FuPmp_bTypFuTnkPmp_C = 0;
const uint32  TiCt_ctSecInDay_C = 0;
const uint32  Tpsveh_seuil_bas_C = 0;
const uint32  Tpsveh_seuil_haut_C = 0;
const uint8  Ext_posnGBxLevDft_C = 0;
const uint8  Ext_pRelBrkAsiInit_C = 0;
const uint8  Ext_tPosATLevExtdInCoh_C = 0;
const uint8  Ext_tPosATLevExtdInter_C = 0;
const uint8  Ext_tPosATLevInCoh_C = 0;
const uint8  Fgigb_ti_VsctlDiagIniGb_C = 0;
const uint8  FLOWMNG_u8Inhib = 0;
const uint8  TiCt_ctTiUSec_C = 0;
const sint16  Ext_tOilDft = 0;
const sint16  TqCnvClu_tqRcvVal_C = 0;
const uint16  ElProdMgt_uElProdSp_C = 0;
const uint16  FuPmp_rLoAcvFuTnkPmp_C = 0;
const uint16  TiCt_ctDayInYr_C = 0;
const uint16  TqCnvClu_nEngNorm_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Bps_brake_pedal_can_hs;
boolean Bps_brake_pedal_can_input;
boolean CMMPropSnsrOnly_PTT;
boolean CMMPropSnsrOnly_TT;
boolean CMMSwtOnly;
boolean Cps_clutch_pedal_input;
boolean ESPPropSnsr_CMMPropSnsr;
boolean ESPPropSnsr_CMMSwt;
boolean Ext_bAcvLoFuPmp;
boolean Ext_bBrkPedPrssHs;
boolean Ext_bdftCoBatt;
boolean Ext_bMainBrkPedPrssHsMes;
boolean Ext_bMainBrkPedPrssMes;
boolean Ext_bOilPres;
boolean Ext_bPosAT_FrstCases;
boolean Ext_bPresOilEng;
boolean Ext_bPresOilWarn;
boolean Ext_bPrgChBSSDi_nEng;
boolean Ext_bRawOilPres;
boolean Ext_bTAirChk;
boolean Fgigb_b_VsctlDiagIniGb;
boolean FLOWMNG_bFgigb_T1;
boolean FLOWMNG_bFgigb_T2;
boolean FLOWMNG_bFgigb_T3;
boolean FLOWMNG_bFgigb_T4;
boolean FlowMng_bFirstTiCntMng;
boolean FLOWMNG_bTime1Out;
boolean FLOWMNG_bTime2Out;
boolean FLOWMNG_bTimeOut;
boolean FLOWMNG_bTimer_prev;
boolean FLOWMNG_bTimer1_prev;
boolean FLOWMNG_bTimer2_prev;
boolean NoCluSnsr;
boolean Oil_pres_alert;
uint32 AraMth_ctStaAcv;
uint32 Ext_ctSecEngStop;
uint32 Ext_ctSecEngStop2004;
uint32 Ext_ctSecTot;
uint32 Ext_tiCurVeh_prev;
uint32 Ext_tiCurVeh2004;
uint32 FLOWMNG_u32Ext_ctSec_Prev;
uint32 FLOWMNG_u32Ext_ctSec_Prev_2;
uint32 FLOWMNG_u32Ext_ctSecEngStop_Prev;
uint32 FLOWMNG_u32TiCtctSecStopEng_Prev;
uint32 Km_vehicle_mux;
uint32 TiCt_ctSecEng;
uint32 TiCt_ctSecStopEng;
uint32 Tict_nbSec;
uint32 TiCt_tiDelta;
uint8 Ext_rSpdFanPred;
uint8 Ext_rSpdFanReqB2;
uint8 Ext_rSpdFanReqC;
uint8 Ext_stPrgBSSCh;
uint8 Ext_stPrgChLINDi_nEng;
uint8 Ext_stPrgLINCh;
uint8 Ext_stPwt;
uint8 FLOWMNG_u8Ext_ctInt;
uint8 FLOWMNG_u8Ext_ctInt_prev;
uint8 FLOWMNG_u8Ext_ctYr;
uint8 FLOWMNG_u8Ext_ctYr_Prev;
uint8 FLOWMNG_u8Ext_ctYr_Prev_2;
uint8 FLOWMNG_u8Timer;
uint8 FLOWMNG_u8Timer1;
uint8 FLOWMNG_u8Timer2;
uint8 Tra_posnATLevExtSecu;
uint8 Tra_posnATLevExtSecu_prev;
sint16 Ext_tAirExtMesFineResl;
sint16 Ext_tAirExtMesFineResl_prev;
sint16 Ext_tAirMesFineResl;
sint16 Ext_tOil;
uint16 Bat_rBattSoC;
uint16 Ext_ctDayTot;
uint16 Ext_uAltBSSSp;
uint16 Ext_uAltLINSp;
uint16 Fgigb_ti_VsctlDiagIniGb;
uint16 FLOWMNG_u16Ext_ctDay;
uint16 FLOWMNG_u16Ext_ctDay_Prev;
uint16 FLOWMNG_u16Ext_ctDay_Prev_2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

