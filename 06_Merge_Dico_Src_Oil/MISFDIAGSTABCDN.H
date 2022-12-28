/***************************************************************************
;**
;** FILE NAME      : MISFDIAGSTABCDN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDIAGSTABCDN_H
#define MISFDIAGSTABCDN_H

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

extern const boolean  Misf_bAcvTqStab_C;
extern const uint8  Mf_engine_stable_delay_c;
extern const uint8  Mf_gear_engaged_stability_delay;
extern const uint8  Mf_indicated_tor_stability_delay;
extern const uint8  Mf_torq_deduction_stab_delay;
extern const uint8  Misf_agIgAdvStabLim_C;
extern const uint8  Misf_tDlyNoGearStabTq_C;
extern const uint8  Misf_tDlyStabAccrTq_C;
extern const uint8  Misf_tDlyStabDeceTq_C;
extern const sint16  Mf_indicated_tor_stability_limit;
extern const sint16  Mf_neut_indic_tor_stab_limit;
extern const sint16  Mf_torq_deduction_stab_limit;
extern const uint16  Misf_ctIgAdvStabLim_C;
extern const uint16  Misf_FilTqGain_C;
extern const uint16  Misf_NeutFilTqGain_C;
extern const uint16  Misf_tqAccrFilTqThd_C;
extern const uint16  Misf_tqDeceFilTqThd_C;
extern const uint16  Misf_tqNeutFilTqThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Gear_engaged_mf_not_stable;
extern boolean Mf_stability_conditions;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfDiagStabCdn(void);
void Misf_EveRst_MisfDiagStabCdn(void);
void Misf_SdlMid_MisfDiagStabCdn(void);


#endif /* MISFDIAGSTABCDN_H */

/*-------------------------------- end of file -------------------------------*/
