/***************************************************************************
;**
;** FILE NAME      : INJFARCTLDSCTL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJFARCTLDSCTL_L_H
#define INJFARCTLDSCTL_L_H

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


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  INJFARCTLDSCTL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Dnstr_purge_cata_done_wo_result;
extern boolean Enable_decre_low_count;
extern boolean Enable_decre_rich_count;
extern boolean INJFARCTLDSCTL_bEnableCalcModif;
extern boolean INJFARCTLDSCTL_bHystOutputLow;
extern boolean INJFARCTLDSCTL_bHystOutputRich;
extern uint8 Dnstr_err_tension_int_gain;
extern uint8 Dnstr_err_tension_pro_gain;
extern sint16 Feedback_correction_int;
extern sint16 Feedback_correction_pro;
extern uint16 Dnstr_down_stream_ref_voltage;
extern uint16 Dnstr_entry_delay;
extern uint16 Dnstr_err_tension;
extern uint16 Dnstr_err_tension_prec;
extern uint16 Dnstr_int_gain;
extern uint16 Dnstr_pro_gain;
extern uint16 Dnstr_retard_s_purge_pauvre;
extern uint16 Dnstr_retard_s_purge_riche;
extern uint16 Dnstr_settling_delay;
extern uint16 Dnstr_time_in_high_volt_count;
extern uint16 Dnstr_time_in_low_volt_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJFARCTLDSCTL_DownStrmSenTrans(void);
void INJFARCTLDSCTL_InitCtrlTrans(void);
void INJFARCTLDSCTL_PurgeCataTrans(void);
void INJFARCTLDSCTL_vidCalcErrTenGain(void);
void INJFARCTLDSCTL_vidCalcErrTension(void);
void INJFARCTLDSCTL_vidCalcModifiers(void);
void INJFARCTLDSCTL_vidCalculationMod(void);
void INJFARCTLDSCTL_vidDecrEntryDly(void);
void INJFARCTLDSCTL_vidDecrLowCount(void);
void INJFARCTLDSCTL_vidDecrRichCount(void);
void INJFARCTLDSCTL_vidDecSettlingDly(void);
void INJFARCTLDSCTL_vidDownstreamCond(void);
void INJFARCTLDSCTL_vidFeedbackCorr(void);
void INJFARCTLDSCTL_vidInitEntryDly(void);
void INJFARCTLDSCTL_vidInitOutput(void);
void INJFARCTLDSCTL_vidInitParam(void);
void INJFARCTLDSCTL_vidInitPurgeCata(void);
void INJFARCTLDSCTL_vidInitSetlingDly(void);
void INJFARCTLDSCTL_vidManager(void);
void INJFARCTLDSCTL_vidPurgeCata(void);
void INJFARCTLDSCTL_vidPurgeCataLow(void);
void INJFARCTLDSCTL_vidPurgeCataRich(void);
void INJFARCTLDSCTL_vidResetOffset(void);
void INJFARCTLDSCTL_vidResetOffsetVal(void);
void INJFARCTLDSCTL_vidResetPurgeCata(void);
void INJFARCTLDSCTL_vidSaveFeedbackCr(void);
void INJFARCTLDSCTL_WaitCtrlCondTrans(void);
void INJFARCTLDSCTL_WaitGnrlCondTrans(void);
void INJFARCTLDSCTL_WaitOffDlyTrans(void);


#endif /* INJFARCTLDSCTL_L_H */

/*-------------------------------- end of file -------------------------------*/
