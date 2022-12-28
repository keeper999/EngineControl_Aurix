/***************************************************************************
;**
;** FILE NAME      : FARSTRAMON.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FARSTRAMON_H
#define FARSTRAMON_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Ext_bPresCnstrDblePk_SC           1

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

extern const boolean  CstrMgr_bAcvReqTranGasGslIp_C;
extern const boolean  CstrMgr_bAcvReqTranGslGasIp_C;
extern const uint8  Cstr_TiEnaPurgEngRstrtSTT_C;
extern const uint8  Cstr_TiEnaPurgEngStrt_C;
extern const uint8  StraMon_tiDlyAftDiagItrsv_C;
extern const uint16  Cstr_pHysUsDsPurgClose_C;
extern const uint16  Cstr_pMinUsDsPurgClose_C;
extern const uint16  Cstr_pMinUsDsPurgImdtClose_C;
extern const uint16  Gsm_egr_relative_pos_hi_thresh;
extern const uint16  Gsm_egr_relative_pos_low_thresh;
extern const uint16  GSM_Misf_OBD_Down_C;
extern const uint16  Gsm_no_effect_fast_closed_delay;
extern const uint16  Gsm_no_effect_slow_closed_delay;
extern const uint16  Gsm_noAdpEfcCpcThd_C;
extern const uint16  StraMon_concFuStmEstimThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Gsm_closed_cpc_request;
extern boolean Gsm_closed_egr_request;
extern boolean Gsm_cpc_slow_closing_choice;
extern boolean Gsm_saf_diag_enable;
extern boolean Lambda_for_saf_diag_request;
extern boolean Lfbk_mon_diag_test_enable;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void StraMon_EveCrTR_FarStraMon(void);
void StraMon_EveRst_FarStraMon(void);
void StraMon_SdlMid_FarStraMon(void);


#endif /* FARSTRAMON_H */

/*-------------------------------- end of file -------------------------------*/
