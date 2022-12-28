/***************************************************************************
;**
;** FILE NAME      : MISFDIAGSTABCDN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDIAGSTABCDN_L_H
#define MISFDIAGSTABCDN_L_H

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

extern const uint8  MISFDIAGSTABCDN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Indicated_torque_mf_not_stable;
extern boolean Mf_engine_conditions;
extern boolean Misf_bDetAccr;
extern boolean Misf_bEngStabCdn;
extern boolean Misf_bRstFilTq;
extern boolean Misf_bRstFilTqIdle;
extern boolean MISFDIAGSTABCDN_bAcvCdIdlRawPrev;
extern boolean MISFDIAGSTABCDN_bAcvCdNrmRawPrev;
extern boolean MISFDIAGSTABCDN_bfirstiteration;
extern boolean MISFDIAGSTABCDN_bfirstiteration1;
extern boolean MISFDIAGSTABCDN_bGearEnStab_Prev;
extern boolean MISFDIAGSTABCDN_bMisfEngCdnPrev;
extern boolean MISFDIAGSTABCDN_bTorStab_Prev;
extern boolean MISFDIAGSTABCDN_bTrqDedct_Prev;
extern boolean Torque_deduction_mf_not_stable;
extern boolean Vehicle_not_running;
extern uint32 Misf_tqDifFilTq;
extern uint8 Gear_engaged_mf_last;
extern uint8 Mf_engine_stable_t_d_c;
extern uint8 Mf_gear_engaged_stability_count;
extern uint8 Mf_indicated_tor_stability_count;
extern uint8 Mf_torq_deduction_stab_count;
extern uint8 Misf_agIgSpJmp;
extern uint8 Misf_ctNeutStabTq;
extern uint8 Misf_ctStabTq;
extern uint8 MISFDIAGSTABCDN_u8IgSyaIgSpPrev;
extern sint16 Indicated_torque_mf_max;
extern sint16 Indicated_torque_mf_min;
extern sint16 MISFDIAGSTABCDN_s16OutFilterNoGr;
extern sint16 MISFDIAGSTABCDN_s16OutFilterStab;
extern sint16 Torque_deduction;
extern sint16 Torque_deduction_mf_max;
extern sint16 Torque_deduction_mf_min;
extern uint16 Misf_ctIgAdvStab;
extern uint16 Misf_tqNeutDifFilTq;
extern sint32 MISFDIAGSTABCDN_s32FiltNoGrMem;
extern sint32 MISFDIAGSTABCDN_s32FiltStabMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFDIAGSTABCDN_vidChkgearstab(void);
void MISFDIAGSTABCDN_vidChkLdAlIdlStb(void);
void MISFDIAGSTABCDN_vidChkLdAlNrmStb(void);
void MISFDIAGSTABCDN_vidChkLdNotStb(void);
void MISFDIAGSTABCDN_vidChkLdStab(void);
void MISFDIAGSTABCDN_vidChkLdStabFilt(void);
void MISFDIAGSTABCDN_vidChkLoadStab(void);
void MISFDIAGSTABCDN_vidChktrqstab(void);
void MISFDIAGSTABCDN_vidDiagStabCdn(void);
void MISFDIAGSTABCDN_vidEngCdtNotStab(void);
void MISFDIAGSTABCDN_vidEngineCdtStab(void);
void MISFDIAGSTABCDN_vidEngineCndts(void);
void MISFDIAGSTABCDN_vidGearNotStable(void);
void MISFDIAGSTABCDN_vidGearSetStab(void);
void MISFDIAGSTABCDN_vidGearStable(void);
void MISFDIAGSTABCDN_vidGearWaitStab(void);
void MISFDIAGSTABCDN_vidIgnAdvNotStab(void);
void MISFDIAGSTABCDN_vidIgnAdvStable(void);
void MISFDIAGSTABCDN_vidInitEngineCnd(void);
void MISFDIAGSTABCDN_vidInitOutput(void);
void MISFDIAGSTABCDN_vidLoadNotStable(void);
void MISFDIAGSTABCDN_vidLoadSetStab(void);
void MISFDIAGSTABCDN_vidLoadStable(void);
void MISFDIAGSTABCDN_vidLoadWaitStab(void);
void MISFDIAGSTABCDN_vidMisfdvStabChk(void);
void MISFDIAGSTABCDN_vidMisfIgAdvClcn(void);
void MISFDIAGSTABCDN_vidMisfStbCdLost(void);
void MISFDIAGSTABCDN_vidMisIgAdvStNul(void);
void MISFDIAGSTABCDN_vidStabChkDly(void);
void MISFDIAGSTABCDN_vidStabSet(void);
void MISFDIAGSTABCDN_vidTimer(void);
void MISFDIAGSTABCDN_vidTimerOut(void);
void MISFDIAGSTABCDN_vidTorqNotStable(void);
void MISFDIAGSTABCDN_vidTorqSetStab(void);
void MISFDIAGSTABCDN_vidTorqStable(void);
void MISFDIAGSTABCDN_vidTorqWaitStab(void);
void MISFDIAGSTABCDN_vidVculeNotRning(void);


#endif /* MISFDIAGSTABCDN_L_H */

/*-------------------------------- end of file -------------------------------*/
