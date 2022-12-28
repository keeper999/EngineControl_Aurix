/***************************************************************************
;**
;** FILE NAME      : INJCTL_INJFARCTLMGR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INJCTL_INJFARCTLMGR.H"
#include "INJCTL_INJFARCTLMGR_L.H"
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
const boolean  InjCtl_bAcvObjRichRegul_C = 0;
const boolean  InjCtl_bInhIntrCdn_C = 0;
const boolean  Lambda_rich_for_cata_diag = 0;
const boolean  Manu_inh_lambda_feedback = 0;
const boolean  OxC_bInhNormRunCond_C = 0;
const uint8  CoPTSt_tCoMesRStrtSTT_bkpt_map[COPTST_TCOMESRSTRTSTT_BKPT_MAP_COLS] = {0};
const uint8  INJCTL_INJFARCTLMGR_u8Inhib = 0;
const uint8  InjCtl_rMixtSenO2CalcLeanHiThd_C = 0;
const uint8  InjCtl_rMixtSenO2CalcLeanLoThd_C = 0;
const uint8  InjCtl_rMixtSenO2CalcRichHiThd_C = 0;
const uint8  InjCtl_rMixtSenO2CalcRichLoThd_C = 0;
const uint8  Lambda_adapt_cond_knk_thr_high = 0;
const uint8  Lambda_adapt_cond_knk_thr_low = 0;
const uint8  Lambda_adapt_cond_stt_thr_high = 0;
const uint8  Lambda_adapt_cond_stt_thr_low = 0;
const uint8  Lambda_adapt_cond_thresh_high = 0;
const uint8  Lambda_adapt_cond_thresh_low = 0;
const uint8  Lambda_enable_after_fco_tdc = 0;
const uint8  Lambda_enable_temp_offset_map[LAMBDA_ENABLE_TEMP_OFFSET_MAP_COLS] = {0};
const uint8  Lambda_enable_thresh_temp = 0;
const uint8  Lambda_saf_enable_thresh_temp = 0;
const uint8  Lbda_fdbk_enab_adp_delay_stt_map[LBDA_FDBK_ENAB_ADP_DELAY_STT_MAP_COLS] = {0};
const uint8  Lbda_fdbk_enable_adapt_delay_map[LBDA_FDBK_ENABLE_ADAPT_DELAY_MAP_COLS] = {0};
const uint8  Lbda_fdbk_enable_offset_map[LBDA_FDBK_ENABLE_OFFSET_MAP_COLS] = {0};
const uint8  Lbda_fdbk_enable_offset_stt_map[LBDA_FDBK_ENABLE_OFFSET_STT_MAP_COLS] = {0};
const uint8  Obj_rich_temp_eau_stall_bkpt_map[OBJ_RICH_TEMP_EAU_STALL_BKPT_MAP_COLS] = {0};
const uint16  InjCtl_ctLbDiRMixtSenO2Calc_C = 0;
const uint16  Lambda_disable_delay = 0;
const uint16  Lambda_disable_knk_delay = 0;
const uint16  Lambda_disable_stt_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Monitor_feedback_conds_state;
boolean Conditions_for_feedback;
boolean Enable_dec_obj_rich_mise_en_ac;
boolean InjCtl_bAcvLbCll;
boolean Lambda_closed_loop;
boolean Lambda_cond_for_adaptation;
boolean Lambda_cond_for_feedback;
boolean Lambda_for_saf_diag_active;
boolean OxC_bMonIntrErunCdn;
boolean Phase_apres_depart;
uint8 Lambda_enable_temp_thresh;
uint8 Lbda_fdbk_enable_adapt_count;
uint16 Initial_fco_count;
uint16 InjCtl_ctLbDiRMixtSenO2Calc;
uint16 Lambda_disable_counter;
uint16 Lambda_disable_knk_counter;
uint16 Lambda_disable_stt_counter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

