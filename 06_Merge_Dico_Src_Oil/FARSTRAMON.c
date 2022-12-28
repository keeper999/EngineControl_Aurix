/***************************************************************************
;**
;** FILE NAME      : FARSTRAMON.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FARSTRAMON.H"
#include "FARSTRAMON_L.H"
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
const boolean  CstrMgr_bAcvReqTranGasGslIp_C = 0;
const boolean  CstrMgr_bAcvReqTranGslGasIp_C = 0;
const uint8  Cstr_TiEnaPurgEngRstrtSTT_C = 0;
const uint8  Cstr_TiEnaPurgEngStrt_C = 0;
const uint8  FARSTRAMON_u8Inhib = 0;
const uint8  StraMon_tiDlyAftDiagItrsv_C = 0;
const uint16  Cstr_pHysUsDsPurgClose_C = 0;
const uint16  Cstr_pMinUsDsPurgClose_C = 0;
const uint16  Cstr_pMinUsDsPurgImdtClose_C = 0;
const uint16  Gsm_egr_relative_pos_hi_thresh = 0;
const uint16  Gsm_egr_relative_pos_low_thresh = 0;
const uint16  GSM_Misf_OBD_Down_C = 0;
const uint16  Gsm_no_effect_fast_closed_delay = 0;
const uint16  Gsm_no_effect_slow_closed_delay = 0;
const uint16  Gsm_noAdpEfcCpcThd_C = 0;
const uint16  StraMon_concFuStmEstimThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 FARSTRAMON_stEGREffect;
uint8 FARSTRAMON_stPurge;
boolean Cstr_bDmdClosePurgImdtTurbMod;
boolean Cstr_bDmdClosePurgTurbMod;
boolean Cstr_bEnaPurgEngStrtRstrt;
boolean CstrMgr_bInhCstrTranGasMod;
boolean FARSTRAMON_bCounter_On_Off;
boolean GMS_bAuthDiagEGR;
boolean GMS_bAuthDiagEGRHys;
boolean Gsm_closed_cpc_request;
boolean Gsm_closed_egr_request;
boolean Gsm_cpc_no_effect;
boolean Gsm_cpc_slow_closing_choice;
boolean Gsm_egr_no_effect;
boolean GSM_Misf_OBD_fail;
boolean Gsm_saf_diag_enable;
boolean Lambda_for_saf_diag_request;
boolean Lfbk_mon_diag_test_enable;
uint8 Cstr_ctTiEnaPurgEng;
uint8 Cstr_ctTiEnaPurgEngPrev;
uint8 StraMon_tiDlyAftDiagItrsv;
uint16 FARSTRAMON_u16AntiRebFilterCnt;
uint16 Gsm_cpc_no_effect_count;
uint16 Gsm_egr_no_effect_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

