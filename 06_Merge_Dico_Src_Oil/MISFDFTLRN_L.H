/***************************************************************************
;**
;** FILE NAME      : MISFDFTLRN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDFTLRN_L_H
#define MISFDFTLRN_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_ADAP_BDC_COND_OK_UAVB1_COLS         ( 4 )
#define MF_ADAP_BDC_DELTA_UAVN1_COLS           ( 4 )
#define MF_ADAP_BDC_ERR_DIF_FILT_UAVN1_COLS    ( 4 )
#define MF_ADAP_BDC_ERR_DIF_NEG_UAVN1_COLS     ( 4 )
#define MF_ADAP_BDC_ERR_DIF_POS_UAVN1_COLS     ( 4 )
#define MF_ADAP_BDC_ERR_DIF_RAW_UAVN1_COLS     ( 4 )
#define MF_ADAP_BDC_ERR_FILT_UAVN1_COLS        ( 4 )
#define MF_ADAP_BDC_ERR_MV_I_UAVN1_COLS        ( 4 )
#define MF_ADAP_DELTA_COUNT_UAVN1_COLS         ( 4 )
#define MF_ADAP_EXP_COND_OK_UAVB1_COLS         ( 4 )
#define MF_ADAP_EXP_DELTA_UAVN1_COLS           ( 4 )
#define MF_ADAP_EXP_ERR_DIF_FILT_UAVN1_COLS    ( 4 )
#define MF_ADAP_EXP_ERR_DIF_NEG_UAVN1_COLS     ( 4 )
#define MF_ADAP_EXP_ERR_DIF_POS_UAVN1_COLS     ( 4 )
#define MF_ADAP_EXP_ERR_DIF_RAW_UAVN1_COLS     ( 4 )
#define MF_ADAP_EXP_ERR_FILT_UAVN1_COLS        ( 4 )
#define MF_ADAP_EXP_ERR_MV_I_UAVN1_COLS        ( 4 )
#define MF_ADAP_LW_COND_OK_UAVB1_COLS          ( 4 )
#define MF_ADAP_LW_DELTA_UAVN1_COLS            ( 4 )
#define MF_ADAP_LW_ERR_DIF_FILT_UAVN1_COLS     ( 4 )
#define MF_ADAP_LW_ERR_DIF_NEG_UAVN1_COLS      ( 4 )
#define MF_ADAP_LW_ERR_DIF_POS_UAVN1_COLS      ( 4 )
#define MF_ADAP_LW_ERR_DIF_RAW_UAVN1_COLS      ( 4 )
#define MF_ADAP_LW_ERR_FILT_UAVN1_COLS         ( 4 )
#define MF_ADAP_LW_ERR_MV_I_UAVN1_COLS         ( 4 )
#define MF_ADAP_LW_SAMPLE_COUNT_UAVN1_COLS     ( 4 )
#define MF_ADAP_SHRT_SAMPLE_COUNT_UAVN1_COLS   ( 4 )
#define MF_ADAP_TDC_COND_OK_UAVB1_COLS         ( 4 )
#define MF_ADAP_TDC_DELTA_UAVN1_COLS           ( 4 )
#define MF_ADAP_TDC_ERR_DIF_FILT_UAVN1_COLS    ( 4 )
#define MF_ADAP_TDC_ERR_DIF_NEG_UAVN1_COLS     ( 4 )
#define MF_ADAP_TDC_ERR_DIF_POS_UAVN1_COLS     ( 4 )
#define MF_ADAP_TDC_ERR_DIF_RAW_UAVN1_COLS     ( 4 )
#define MF_ADAP_TDC_ERR_FILT_UAVN1_COLS        ( 4 )
#define MF_ADAP_TDC_ERR_MV_I_UAVN1_COLS        ( 4 )
#define MISF_BDCWINERRRAW_COLS                 ( 4 )
#define MISF_EXPWINERRRAW_COLS                 ( 4 )
#define MISF_LONGWINERRRAW_COLS                ( 4 )
#define MISF_NOWINSAMPLE_T_COLS                ( 4 )
#define MISF_TDCWINERRRAW_COLS                 ( 4 )
#define MISFDFTLRN_u8ARRAY_LEN            4
#define MISFDFTLRN_u8ARRAY_LENGTH         9

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st98 */
#define CALC_CYL1                         1
#define CALC_INIT                         2
#define INIT_LRN                          3
#define LRN_COND                          4
#define WAIT_CYL1                         5
/*extern uint8 Misf_stDftLrn;*/

/* enum st96 */
#define LRN_CALC_INIT                     1
#define LRN_WAIT                          2
#define LRN_WAIT_CYL1                     3
#define LRN_WIN                           4
#define WIN_WAIT                          5
/*extern uint8 Misf_stLrnWin;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  MISFDFTLRN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Misf_stDftLrn;
extern uint8 Misf_stLrnWin;
extern boolean Mf_adap_auth_uavb0;
extern boolean Mf_adap_Bdc_cond_ok_uavb0;
extern boolean Mf_adap_Bdc_cond_ok_uavb1[MF_ADAP_BDC_COND_OK_UAVB1_COLS];
extern boolean Mf_adap_calc_init_uavb0;
extern boolean Mf_adap_ena_uavb0;
extern boolean Mf_adap_Exp_cond_ok_uavb0;
extern boolean Mf_adap_Exp_cond_ok_uavb1[MF_ADAP_EXP_COND_OK_UAVB1_COLS];
extern boolean Mf_adap_filt_calc_init_uavb0;
extern boolean Mf_adap_lw_cond_ok_uavb0;
extern boolean Mf_adap_lw_cond_ok_uavb1[MF_ADAP_LW_COND_OK_UAVB1_COLS];
extern boolean Mf_adap_TDC_cond_ok_uavb0;
extern boolean Mf_adap_TDC_cond_ok_uavb1[MF_ADAP_TDC_COND_OK_UAVB1_COLS];
extern boolean Misf_bDgoORng_LongWinLrn;
extern boolean Misf_bDgoORng_LongWinLrnMax;
extern boolean Misf_bDgoORng_ShrtWinLrn;
extern boolean Misf_bDgoORng_ShrtWinLrnMax;
extern boolean Misf_bMonRunORng_LongWinLrn;
extern boolean Misf_bMonRunORng_LongWinLrnMax;
extern boolean Misf_bMonRunORng_ShrtWinLrn;
extern boolean Misf_bMonRunORng_ShrtWinLrnMax;
extern boolean MISFDFTLRN_bBdcHystOut;
extern boolean MISFDFTLRN_bExpHystOut;
extern boolean MISFDFTLRN_bFRMInhWinLrnORngPrev;
extern boolean MISFDFTLRN_bLwHystOut;
extern boolean MISFDFTLRN_blwnorlzduavb0Prev;
extern boolean MISFDFTLRN_blwnorlzdUTuavb0Prev;
extern boolean MISFDFTLRN_bshrtnorlzduavb0Prev;
extern boolean MISFDFTLRN_bshrtnorlzdUTuavb0Prv;
extern boolean MISFDFTLRN_bSrvAcvPlaModPrev;
extern boolean MISFDFTLRN_bTDCHystOut;
extern uint32 Misf_tiDlyBdcWin1;
extern uint32 Misf_tiDlyExpWin1;
extern uint32 Misf_tiDlyLongWin1;
extern uint32 Misf_tiDlyTDCWin1;
extern uint32 MISFDFTLRN_u32tiDlyBdcWinPrev;
extern uint32 MISFDFTLRN_u32tiDlyExpWinPrev;
extern uint32 MISFDFTLRN_u32tiDlyLongWinPrev;
extern uint32 MISFDFTLRN_u32tiDlyTDCWinPrev;
extern uint8 Mf_adap_bkpt_ind_prev_uavn0;
extern uint8 Mf_adap_delta_count_uavn1[MF_ADAP_DELTA_COUNT_UAVN1_COLS];
extern uint8 Mf_adap_lw_corr_nxt_cnt_i_uavn0;
extern uint8 Mf_adap_lw_sample_count_uavn1[MF_ADAP_LW_SAMPLE_COUNT_UAVN1_COLS];
extern uint8 Mf_adap_n_index;
extern uint8 Mf_adap_shrt_corr_nxt_cnt_i;
extern uint8 Mf_adap_shrt_sample_count_uavn1[MF_ADAP_SHRT_SAMPLE_COUNT_UAVN1_COLS];
extern uint8 Misf_noWinSample_T[MISF_NOWINSAMPLE_T_COLS];
extern sint16 Mf_adap_Bdc_corr_precal_uavn0;
extern sint16 Mf_adap_Bdc_delta_uavn1[MF_ADAP_BDC_DELTA_UAVN1_COLS];
extern sint16 Mf_adap_Bdc_err_dif_neg_uavn1[MF_ADAP_BDC_ERR_DIF_NEG_UAVN1_COLS];
extern sint16 Mf_adap_Bdc_err_dif_pos_uavn1[MF_ADAP_BDC_ERR_DIF_POS_UAVN1_COLS];
extern sint16 Mf_adap_Bdc_err_dif_raw_uavn1[MF_ADAP_BDC_ERR_DIF_RAW_UAVN1_COLS];
extern sint16 Mf_adap_Bdc_err_filt_uavn1[MF_ADAP_BDC_ERR_FILT_UAVN1_COLS];
extern sint16 Mf_adap_Bdc_err_mv_i_uavn1[MF_ADAP_BDC_ERR_MV_I_UAVN1_COLS];
extern sint16 Mf_adap_Exp_corr_precal_uavn0;
extern sint16 Mf_adap_Exp_delta_uavn1[MF_ADAP_EXP_DELTA_UAVN1_COLS];
extern sint16 Mf_adap_Exp_err_dif_neg_uavn1[MF_ADAP_EXP_ERR_DIF_NEG_UAVN1_COLS];
extern sint16 Mf_adap_Exp_err_dif_pos_uavn1[MF_ADAP_EXP_ERR_DIF_POS_UAVN1_COLS];
extern sint16 Mf_adap_Exp_err_dif_raw_uavn1[MF_ADAP_EXP_ERR_DIF_RAW_UAVN1_COLS];
extern sint16 Mf_adap_Exp_err_filt_uavn1[MF_ADAP_EXP_ERR_FILT_UAVN1_COLS];
extern sint16 Mf_adap_Exp_err_mv_i_uavn1[MF_ADAP_EXP_ERR_MV_I_UAVN1_COLS];
extern sint16 Mf_adap_lw_corr_precal_uavn0;
extern sint16 Mf_adap_lw_delta_uavn1[MF_ADAP_LW_DELTA_UAVN1_COLS];
extern sint16 Mf_adap_lw_err_dif_neg_uavn1[MF_ADAP_LW_ERR_DIF_NEG_UAVN1_COLS];
extern sint16 Mf_adap_lw_err_dif_pos_uavn1[MF_ADAP_LW_ERR_DIF_POS_UAVN1_COLS];
extern sint16 Mf_adap_lw_err_dif_raw_uavn1[MF_ADAP_LW_ERR_DIF_RAW_UAVN1_COLS];
extern sint16 Mf_adap_lw_err_mv_i_uavn1[MF_ADAP_LW_ERR_MV_I_UAVN1_COLS];
extern sint16 Mf_adap_TDC_corr_precal_uavn0;
extern sint16 Mf_adap_TDC_delta_uavn1[MF_ADAP_TDC_DELTA_UAVN1_COLS];
extern sint16 Mf_adap_TDC_err_dif_neg_uavn1[MF_ADAP_TDC_ERR_DIF_NEG_UAVN1_COLS];
extern sint16 Mf_adap_TDC_err_dif_pos_uavn1[MF_ADAP_TDC_ERR_DIF_POS_UAVN1_COLS];
extern sint16 Mf_adap_TDC_err_dif_raw_uavn1[MF_ADAP_TDC_ERR_DIF_RAW_UAVN1_COLS];
extern sint16 Mf_adap_TDC_err_filt_uavn1[MF_ADAP_TDC_ERR_FILT_UAVN1_COLS];
extern sint16 Mf_adap_TDC_err_mv_i_uavn1[MF_ADAP_TDC_ERR_MV_I_UAVN1_COLS];
extern sint16 Misf_BdcWin1Delta;
extern sint16 Misf_BdcWinErrRaw[MISF_BDCWINERRRAW_COLS];
extern sint16 Misf_ExpWin1Delta;
extern sint16 Misf_ExpWinErrRaw[MISF_EXPWINERRRAW_COLS];
extern sint16 Misf_LongWin1Delta;
extern sint16 Misf_TDCWin1Delta;
extern sint16 Misf_TDCWinErrRaw[MISF_TDCWINERRRAW_COLS];
extern uint16 Mf_adap_Bdc_err_dif_filt_uavn1[MF_ADAP_BDC_ERR_DIF_FILT_UAVN1_COLS];
extern uint16 Mf_adap_Exp_err_dif_filt_uavn1[MF_ADAP_EXP_ERR_DIF_FILT_UAVN1_COLS];
extern uint16 Mf_adap_lw_err_dif_filt_uavn1[MF_ADAP_LW_ERR_DIF_FILT_UAVN1_COLS];
extern uint16 Mf_adap_TDC_err_dif_filt_uavn1[MF_ADAP_TDC_ERR_DIF_FILT_UAVN1_COLS];
extern uint16 Misf_Delta;
extern sint32 Mf_adap_lw_err_filt_uavn1[MF_ADAP_LW_ERR_FILT_UAVN1_COLS];
extern sint32 Misf_LongWinErrRaw[MISF_LONGWINERRRAW_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFDFTLRN_vid1stLwAdapOnBkpt(void);
void MISFDFTLRN_vid1stShrtAdapOnBkpt(void);
void MISFDFTLRN_vidAdapLwNoRlzd(void);
void MISFDFTLRN_vidAdapLwRlzdNoUt(void);
void MISFDFTLRN_vidAdapLwRlzdUt(void);
void MISFDFTLRN_vidAdapLwRstNoUt(void);
void MISFDFTLRN_vidAdapLwRstUt(void);
void MISFDFTLRN_vidAdapMesLong(void);
void MISFDFTLRN_vidAdapMesShrt(void);
void MISFDFTLRN_vidAdapPrecalLong(void);
void MISFDFTLRN_vidAdapPrecalShrt(void);
void MISFDFTLRN_vidAdapPrecalShrtBdc(void);
void MISFDFTLRN_vidAdapPrecalShrtExp(void);
void MISFDFTLRN_vidAdapPrecalShrtTDC(void);
void MISFDFTLRN_vidAdapRlzdCalc(void);
void MISFDFTLRN_vidAdapRlzdNoUt(void);
void MISFDFTLRN_vidAdapRlzdUt(void);
void MISFDFTLRN_vidAdapRstNoUt(void);
void MISFDFTLRN_vidAdapRstUt(void);
void MISFDFTLRN_vidAdapShrtNoRlzd(void);
void MISFDFTLRN_vidApplyDeltaLw(void);
void MISFDFTLRN_vidApplyDeltaPrecal(void);
void MISFDFTLRN_vidApplyDeltaShrt(void);
void MISFDFTLRN_vidAutomateMisfLrn(void);
void MISFDFTLRN_vidBdcWinVar(void);
void MISFDFTLRN_vidCalcBdcWinApp(void);
void MISFDFTLRN_vidCalcDelta(void);
void MISFDFTLRN_vidCalcDeltaBdc(void);
void MISFDFTLRN_vidCalcDeltaExp(void);
void MISFDFTLRN_vidCalcDeltaLw(void);
void MISFDFTLRN_vidCalcDeltaTdc(void);
void MISFDFTLRN_vidCalcExpWinApp(void);
void MISFDFTLRN_vidCalcIndWinApp(void);
void MISFDFTLRN_vidCalcLongWinApp(void);
void MISFDFTLRN_vidCalcLrn(void);
void MISFDFTLRN_vidCalcLrnInit(void);
void MISFDFTLRN_vidCalcSumDeltaPrecal(void);
void MISFDFTLRN_vidCalcTDCWinApp(void);
void MISFDFTLRN_vidCalcWinApp(void);
void MISFDFTLRN_vidCalcWinDelta(void);
void MISFDFTLRN_vidCondAdap(void);
void MISFDFTLRN_vidCorrBkptLw1(void);
void MISFDFTLRN_vidCorrBkptLw2(void);
void MISFDFTLRN_vidCorrBkptLw3(void);
void MISFDFTLRN_vidCorrBkptLw4(void);
void MISFDFTLRN_vidCorrBkptLw5(void);
void MISFDFTLRN_vidCorrBkptLw6(void);
void MISFDFTLRN_vidCorrBkptLw7(void);
void MISFDFTLRN_vidCorrBkptLw8(void);
void MISFDFTLRN_vidCorrBkptLw9(void);
void MISFDFTLRN_vidCorrBkptShrt1(void);
void MISFDFTLRN_vidCorrBkptShrt2(void);
void MISFDFTLRN_vidCorrBkptShrt3(void);
void MISFDFTLRN_vidCorrBkptShrt4(void);
void MISFDFTLRN_vidCorrBkptShrt5(void);
void MISFDFTLRN_vidCorrBkptShrt6(void);
void MISFDFTLRN_vidCorrBkptShrt7(void);
void MISFDFTLRN_vidCorrBkptShrt8(void);
void MISFDFTLRN_vidCorrBkptShrt9(void);
void MISFDFTLRN_vidEcuRst(void);
void MISFDFTLRN_vidExpWinVar(void);
void MISFDFTLRN_vidIniSaveLrn(void);
void MISFDFTLRN_vidInitBkptInd(void);
void MISFDFTLRN_vidInitOutput(void);
void MISFDFTLRN_vidInitSortieModeUT(void);
void MISFDFTLRN_vidLongWinVar(void);
void MISFDFTLRN_vidLwAdapRaz(void);
void MISFDFTLRN_vidLwAdapWrite(void);
void MISFDFTLRN_vidManuRst(void);
void MISFDFTLRN_vidMfAdap(void);
void MISFDFTLRN_vidNextLwAdapOnBkpt(void);
void MISFDFTLRN_vidNextShrtAdapOnBkpt(void);
void MISFDFTLRN_vidRangeControl(void);
void MISFDFTLRN_vidRstCorrDelta(void);
void MISFDFTLRN_vidSampleWin(void);
void MISFDFTLRN_vidSaveLrn(void);
void MISFDFTLRN_vidShrtAdapRaz(void);
void MISFDFTLRN_vidShrtAdapWrite(void);
void MISFDFTLRN_vidSynchroMfWindow(void);
void MISFDFTLRN_vidTDCWinVar(void);
void MISFDFTLRN_vidUpdateWinAdap(void);
void MISFDFTLRN_vidWinAdap(void);
void MISFDFTLRN_vidWinAdapSave(void);


#endif /* MISFDFTLRN_L_H */

/*-------------------------------- end of file -------------------------------*/
