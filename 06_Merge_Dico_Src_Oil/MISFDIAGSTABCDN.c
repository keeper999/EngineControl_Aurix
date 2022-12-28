/***************************************************************************
;**
;** FILE NAME      : MISFDIAGSTABCDN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFDIAGSTABCDN.H"
#include "MISFDIAGSTABCDN_L.H"
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
const boolean  Misf_bAcvTqStab_C = 0;
const uint8  Mf_engine_stable_delay_c = 0;
const uint8  Mf_gear_engaged_stability_delay = 0;
const uint8  Mf_indicated_tor_stability_delay = 0;
const uint8  Mf_torq_deduction_stab_delay = 0;
const uint8  Misf_agIgAdvStabLim_C = 0;
const uint8  Misf_tDlyNoGearStabTq_C = 0;
const uint8  Misf_tDlyStabAccrTq_C = 0;
const uint8  Misf_tDlyStabDeceTq_C = 0;
const uint8  MISFDIAGSTABCDN_u8Inhib = 0;
const sint16  Mf_indicated_tor_stability_limit = 0;
const sint16  Mf_neut_indic_tor_stab_limit = 0;
const sint16  Mf_torq_deduction_stab_limit = 0;
const uint16  Misf_ctIgAdvStabLim_C = 0;
const uint16  Misf_FilTqGain_C = 0;
const uint16  Misf_NeutFilTqGain_C = 0;
const uint16  Misf_tqAccrFilTqThd_C = 0;
const uint16  Misf_tqDeceFilTqThd_C = 0;
const uint16  Misf_tqNeutFilTqThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Gear_engaged_mf_not_stable;
boolean Indicated_torque_mf_not_stable;
boolean Mf_engine_conditions;
boolean Mf_stability_conditions;
boolean Misf_bDetAccr;
boolean Misf_bEngStabCdn;
boolean Misf_bRstFilTq;
boolean Misf_bRstFilTqIdle;
boolean MISFDIAGSTABCDN_bAcvCdIdlRawPrev;
boolean MISFDIAGSTABCDN_bAcvCdNrmRawPrev;
boolean MISFDIAGSTABCDN_bfirstiteration;
boolean MISFDIAGSTABCDN_bfirstiteration1;
boolean MISFDIAGSTABCDN_bGearEnStab_Prev;
boolean MISFDIAGSTABCDN_bMisfEngCdnPrev;
boolean MISFDIAGSTABCDN_bTorStab_Prev;
boolean MISFDIAGSTABCDN_bTrqDedct_Prev;
boolean Torque_deduction_mf_not_stable;
boolean Vehicle_not_running;
uint32 Misf_tqDifFilTq;
uint8 Gear_engaged_mf_last;
uint8 Mf_engine_stable_t_d_c;
uint8 Mf_gear_engaged_stability_count;
uint8 Mf_indicated_tor_stability_count;
uint8 Mf_torq_deduction_stab_count;
uint8 Misf_agIgSpJmp;
uint8 Misf_ctNeutStabTq;
uint8 Misf_ctStabTq;
uint8 MISFDIAGSTABCDN_u8IgSyaIgSpPrev;
sint16 Indicated_torque_mf_max;
sint16 Indicated_torque_mf_min;
sint16 MISFDIAGSTABCDN_s16OutFilterNoGr;
sint16 MISFDIAGSTABCDN_s16OutFilterStab;
sint16 Torque_deduction;
sint16 Torque_deduction_mf_max;
sint16 Torque_deduction_mf_min;
uint16 Misf_ctIgAdvStab;
uint16 Misf_tqNeutDifFilTq;
sint32 MISFDIAGSTABCDN_s32FiltNoGrMem;
sint32 MISFDIAGSTABCDN_s32FiltStabMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

