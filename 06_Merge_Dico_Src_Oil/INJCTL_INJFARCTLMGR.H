/***************************************************************************
;**
;** FILE NAME      : INJCTL_INJFARCTLMGR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJCTL_INJFARCTLMGR_H
#define INJCTL_INJFARCTLMGR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COPTST_TCOMESRSTRTSTT_BKPT_MAP_COLS    ( 9 )
#define LAMBDA_ENABLE_TEMP_OFFSET_MAP_COLS     ( 9 )
#define LBDA_FDBK_ENAB_ADP_DELAY_STT_MAP_COLS  ( 16 )
#define LBDA_FDBK_ENABLE_ADAPT_DELAY_MAP_COLS  ( 16 )
#define LBDA_FDBK_ENABLE_OFFSET_MAP_COLS       ( 9 )
#define LBDA_FDBK_ENABLE_OFFSET_STT_MAP_COLS   ( 9 )
#define OBJ_RICH_TEMP_EAU_STALL_BKPT_MAP_COLS  ( 9 )
#define RICHESSE_1                        8916

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st30 */
#define FEEDBACK_FOR_SAF_ENABLED          1
#define FEEDBACK_FOR_SAF_IN_FCO           2
#define WAITING_FOR_POST_FCO_DELAY        4
#define FEEDBACK_DISABLED_IN_FCO          8
#define FEEDBACK_ENABLED                  16
#define FEEDBACK_DISABLED_NOT_IN_FCO      32
#define WAITING_SENSOR_AND_TEMP_CONDS     64
#define WAITING_TO_START_FEEDBACK         128
/*extern uint8 Monitor_feedback_conds_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  InjCtl_bAcvObjRichRegul_C;
extern const boolean  InjCtl_bInhIntrCdn_C;
extern const boolean  Lambda_rich_for_cata_diag;
extern const boolean  Manu_inh_lambda_feedback;
extern const boolean  OxC_bInhNormRunCond_C;
extern const uint8  CoPTSt_tCoMesRStrtSTT_bkpt_map[COPTST_TCOMESRSTRTSTT_BKPT_MAP_COLS];
extern const uint8  InjCtl_rMixtSenO2CalcLeanHiThd_C;
extern const uint8  InjCtl_rMixtSenO2CalcLeanLoThd_C;
extern const uint8  InjCtl_rMixtSenO2CalcRichHiThd_C;
extern const uint8  InjCtl_rMixtSenO2CalcRichLoThd_C;
extern const uint8  Lambda_adapt_cond_knk_thr_high;
extern const uint8  Lambda_adapt_cond_knk_thr_low;
extern const uint8  Lambda_adapt_cond_stt_thr_high;
extern const uint8  Lambda_adapt_cond_stt_thr_low;
extern const uint8  Lambda_adapt_cond_thresh_high;
extern const uint8  Lambda_adapt_cond_thresh_low;
extern const uint8  Lambda_enable_after_fco_tdc;
extern const uint8  Lambda_enable_temp_offset_map[LAMBDA_ENABLE_TEMP_OFFSET_MAP_COLS];
extern const uint8  Lambda_enable_thresh_temp;
extern const uint8  Lambda_saf_enable_thresh_temp;
extern const uint8  Lbda_fdbk_enab_adp_delay_stt_map[LBDA_FDBK_ENAB_ADP_DELAY_STT_MAP_COLS];
extern const uint8  Lbda_fdbk_enable_adapt_delay_map[LBDA_FDBK_ENABLE_ADAPT_DELAY_MAP_COLS];
extern const uint8  Lbda_fdbk_enable_offset_map[LBDA_FDBK_ENABLE_OFFSET_MAP_COLS];
extern const uint8  Lbda_fdbk_enable_offset_stt_map[LBDA_FDBK_ENABLE_OFFSET_STT_MAP_COLS];
extern const uint8  Obj_rich_temp_eau_stall_bkpt_map[OBJ_RICH_TEMP_EAU_STALL_BKPT_MAP_COLS];
extern const uint16  InjCtl_ctLbDiRMixtSenO2Calc_C;
extern const uint16  Lambda_disable_delay;
extern const uint16  Lambda_disable_knk_delay;
extern const uint16  Lambda_disable_stt_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Monitor_feedback_conds_state;
extern boolean Conditions_for_feedback;
extern boolean Enable_dec_obj_rich_mise_en_ac;
extern boolean Lambda_closed_loop;
extern boolean Lambda_cond_for_adaptation;
extern boolean Lambda_cond_for_feedback;
extern boolean Lambda_for_saf_diag_active;
extern boolean OxC_bMonIntrErunCdn;
extern boolean Phase_apres_depart;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void InjCtl_EveCrTR_FarCtlMgr(void);
void InjCtl_EveRst_FarCtlMgr(void);
void InjCtl_EveRTSt_FarCtlMgr(void);
void InjCtl_SdlFast_FarCtlMgr(void);
void InjCtl_SdlSlow_FarCtlMgr(void);


#endif /* INJCTL_INJFARCTLMGR_H */

/*-------------------------------- end of file -------------------------------*/
