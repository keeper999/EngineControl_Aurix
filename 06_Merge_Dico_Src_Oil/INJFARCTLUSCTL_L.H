/***************************************************************************
;**
;** FILE NAME      : INJFARCTLUSCTL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJFARCTLUSCTL_L_H
#define INJFARCTLUSCTL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st31 */
#define WAITING_FOR_SAF_DIAG_REQUEST      1
#define SAF_DIAG_ENLEANMENT               2
#define SAF_DIAG_ENRICHMENT               4
/*extern uint8 Feedback_saf_diag_calc_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  INJFARCTLUSCTL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Feedback_saf_diag_calc_state;
extern boolean Fast_traking_ok;
extern boolean InjCtl_bUpdlamMax;
extern boolean InjCtl_bUpdlamMin;
extern boolean INJFARCTLUSCTL_bECUReset;
extern boolean INJFARCTLUSCTL_bLocalDetinitprev;
extern boolean INJFARCTLUSCTL_bMnRnORgItrPrev;
extern boolean INJFARCTLUSCTL_bMnRnORngIntrPrev;
extern boolean INJFARCTLUSCTL_bRlamAdpReqPrev;
extern boolean Lambda_feedback_max_calc;
extern boolean Lambda_feedback_min_calc;
extern boolean Lambda_waiting;
extern boolean Lbda_active_gain_attenu_rich;
extern boolean Lbda_attenuation_condition;
extern boolean Lbda_transitoire_detect;
extern boolean Lbda_transitoire_detectPrev;
extern uint32 INJFARCTLUSCTL_u32AregulFiltMem;
extern sint8 Engine_air_load_derivate;
extern uint8 Delta_PMH_gaz;
extern uint8 Dnstr_modifier_sampled;
extern uint8 InjCtl_tiDlyClcrlamAdapt;
extern uint8 Lambda_slow_mode_delay;
extern uint8 Lbda_lump_lean_gain;
extern uint8 Lbda_lump_rich_gain;
extern uint8 Lbda_step_lean_gain;
extern uint8 Lbda_step_rich_gain;
extern uint8 Transfer_count;
extern sint16 InjCtl_rlamAdaptIntery;
extern sint16 InjCtl_rlamAdaptMv;
extern sint16 INJFARCTLUSCTL_s16LamFeedCanFilt;
extern sint16 Lambda_feedback_max;
extern sint16 Lambda_feedback_mean;
extern sint16 Lambda_feedback_min;
extern sint16 Lambda_feedback_previous;
extern sint16 Moyenne_Lambda_feedback;
extern uint16 Aregulation;
extern uint16 Aregulation_filt;
extern uint16 Lambda_feedback_delta;
extern uint16 Lambda_feedback_lump;
extern uint16 Lambda_feedback_step;
extern uint16 Lbda_engine_air_load_prev;
extern uint16 Lbda_maintien_attenuation_count;
extern uint16 T_Regulation;
extern sint32 INJFARCTLUSCTL_s32lamAdaptIntMem;
extern sint32 INJFARCTLUSCTL_s32LamFeedCanMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJFARCTLUSCTL_vidAdaplambdaMean(void);
void INJFARCTLUSCTL_vidAdaplamfeebcal(void);
void INJFARCTLUSCTL_vidCalcGain(void);
void INJFARCTLUSCTL_vidCalcLFB(void);
void INJFARCTLUSCTL_vidCalcLFBFilt(void);
void INJFARCTLUSCTL_vidCalcLump(void);
void INJFARCTLUSCTL_vidCalcStep(void);
void INJFARCTLUSCTL_vidCallbdSafDiag(void);
void INJFARCTLUSCTL_vidCalLFbDelayOk(void);
void INJFARCTLUSCTL_vidCalLFBLean(void);
void INJFARCTLUSCTL_vidCalLFBRich(void);
void INJFARCTLUSCTL_vidControlEna(void);
void INJFARCTLUSCTL_vidCounter(void);
void INJFARCTLUSCTL_vidDecCounter(void);
void INJFARCTLUSCTL_vidEdSafRqToSfEnl(void);
void INJFARCTLUSCTL_vidEdSfEnlToSfEnr(void);
void INJFARCTLUSCTL_vidEdSfEnrToSfEnl(void);
void INJFARCTLUSCTL_vidFCallbdLdDerv(void);
void INJFARCTLUSCTL_vidFFastTracking(void);
void INJFARCTLUSCTL_vidFuncCalAttGain(void);
void INJFARCTLUSCTL_vidFuncCalLFbFilt(void);
void INJFARCTLUSCTL_vidFuncCtlFdInjAc(void);
void INJFARCTLUSCTL_vidIniAdap(void);
void INJFARCTLUSCTL_vidInit(void);
void INJFARCTLUSCTL_vidInitClosedLoop(void);
void INJFARCTLUSCTL_vidInitFedSaf(void);
void INJFARCTLUSCTL_vidInitFeedCalc(void);
void INJFARCTLUSCTL_vidInitFeedParam(void);
void INJFARCTLUSCTL_vidInitFeedState(void);
void INJFARCTLUSCTL_vidInitLambdaFB(void);
void INJFARCTLUSCTL_vidInitOutput(void);
void INJFARCTLUSCTL_vidIniUplamMaxMin(void);
void INJFARCTLUSCTL_vidLambdaGazDelay(void);
void INJFARCTLUSCTL_vidLamdaGazDelcal(void);
void INJFARCTLUSCTL_vidLbdaNotTrans(void);
void INJFARCTLUSCTL_vidLbdaTrans(void);
void INJFARCTLUSCTL_vidLdbTrGainAttnu(void);
void INJFARCTLUSCTL_vidLFbDelayNok(void);
void INJFARCTLUSCTL_vidLFbFilSDiagCta(void);
void INJFARCTLUSCTL_vidLumpNotOnIdle(void);
void INJFARCTLUSCTL_vidLumpOnIdle(void);
void INJFARCTLUSCTL_vidMeanCalc(void);
void INJFARCTLUSCTL_vidMeanFilt(void);
void INJFARCTLUSCTL_vidMeanLamFeedCal(void);
void INJFARCTLUSCTL_vidMgtFeedCalc(void);
void INJFARCTLUSCTL_vidMonitorFedSaf(void);
void INJFARCTLUSCTL_vidNotTrGainAttnu(void);
void INJFARCTLUSCTL_vidRangeCalc(void);
void INJFARCTLUSCTL_vidRangeFilt(void);
void INJFARCTLUSCTL_vidResetLFB(void);
void INJFARCTLUSCTL_vidSetlbdFltMdDly(void);
void INJFARCTLUSCTL_vidSetlbdSlwMdDly(void);
void INJFARCTLUSCTL_vidSetTransfCount(void);
void INJFARCTLUSCTL_vidStepNotOnIdle(void);
void INJFARCTLUSCTL_vidStepOnIdle(void);
void INJFARCTLUSCTL_vidTransDetect(void);
void INJFARCTLUSCTL_vidTrsfCtNtOnIdle(void);
void INJFARCTLUSCTL_vidTrsfCtOnIdle(void);
void INJFARCTLUSCTL_vidTrsfCttimescal(void);
void INJFARCTLUSCTL_vidUplamMaxMinIni(void);


#endif /* INJFARCTLUSCTL_L_H */

/*-------------------------------- end of file -------------------------------*/
