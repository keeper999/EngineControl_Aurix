/***************************************************************************
;**
;** FILE NAME      : IGNHAL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGNHAL_L_H
#define IGNHAL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGNHAL_Cfg.h"
#include "IGNHAL_E.h"
#include "IGNHAL_GATEWAY.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGNHAL_KAU16ADAPTDWELLLIMITMAP_COLS    ( 5 )
#define IGNHAL_KAU16ENGSPDBRKPTTAB_COLS        ( 5 )
#define IGNHAL_KAU16VBRFBRKPTTAB_COLS          ( 5 )
#define IGNHAL_KAU16WDGDELAYLIMITMAP_LNS      ( 5 )
#define IGNHAL_KAU16WDGDELAYLIMITMAP_COLS      ( 5 )
#define IGNHAL_u16DWELL_TIME_RESOL        1
#define IGNHAL_u16MAX_CURRENT             16384
#define IGNHAL_u16SCDIAG_TIMER_RESOL      1
#define IGNHAL_u32TIME_150_US             1500
#define IGNHAL_u8ENG_SPD_BRKPT_NB         5
#define IGNHAL_u8EVENT_FINISHED           6
#define IGNHAL_u8EVENT_T0                 3
#define IGNHAL_u8EVENT_T0_T1              1
#define IGNHAL_u8EVENT_T0_T2              2
#define IGNHAL_u8EVENT_T1                 4
#define IGNHAL_u8EVENT_T2                 5
#define IGNHAL_u8JUMOPHYS_MODE            1
#define IGNHAL_u8MONOPHYS_MODE            2
#define IGNHAL_u8PROG_1ER_POINT           2
#define IGNHAL_u8PROG_2ND_POINT           4
#define IGNHAL_u8VBRF_BRKPT_NB            5

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st28 */
#define IGNHAL_MODE_FIXED_WANTED          1
#define IGNHAL_MODE_ADAP_WANTED           2
#define IGNHAL_MODE_TEST_WANTED           4
/*extern uint8 IgnHALWantedMode;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint32  IGNHAL_ku32SCToSupplyDiagDelay;
extern const uint8  Icd_pos_slope_1;
extern const uint8  Icd_pos_slope_2;
extern const uint8  IGNHAL_ku8CoilPhysicMode;
extern const uint8  IGNHAL_ku8NumberOfCylinders;
extern const sint16  IGNHAL_ks16AdaptOffsetDef;
extern const uint16  Icd_adapt_factor_twin_phys_max;
extern const uint16  Icd_adapt_factor_twin_phys_min;
extern const uint16  Icd_adapt_factor_twin_phys_step;
extern const uint16  Icd_adapt_offset_twin_phys_step;
extern const uint16  IGNHAL_kau16AdaptDwellLimitMap[IGNHAL_KAU16ADAPTDWELLLIMITMAP_COLS];
extern const uint16  IGNHAL_kau16EngSpdBrkptTab[IGNHAL_KAU16ENGSPDBRKPTTAB_COLS];
extern const uint16  IGNHAL_kau16VbrfBrkptTab[IGNHAL_KAU16VBRFBRKPTTAB_COLS];
extern const uint16  IGNHAL_kau16WdgDelayLimitMap[IGNHAL_KAU16WDGDELAYLIMITMAP_LNS][IGNHAL_KAU16WDGDELAYLIMITMAP_COLS];
extern const uint16  IGNHAL_ku16AdaptFactorDef;
extern const uint16  IGNHAL_ku16InhibOCDiagDwellThd;
extern const uint16  IGNHAL_ku16OCDetectionThreshold;
extern const uint16  IGNHAL_ku16ShuntResistor;
extern const uint16  IGNHAL_ku16TdcToRefAngle;
extern const uint16  Seuil_bobine_cc_bat;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern uint8 IgnHALWantedMode;
extern boolean Avance_disponible;
extern boolean IGNHAL_bCutCylinderA;
extern boolean IGNHAL_bCutCylinderB;
extern boolean IGNHAL_bCutCylinderC;
extern boolean IGNHAL_bCutCylinderD;
extern boolean IGNHAL_bEnabled;
extern boolean IGNHAL_bPeriodicIgnVbrfEna;
extern boolean IgnHALWriteEnergy_APICalled;
extern boolean Interdit_trig_it_dent_ref;
extern boolean Trait_pmh_avance_glisse;
extern uint32 IGNHAL_u32AdaptDwellLimitation;
extern uint32 IGNHAL_u32DiagPointOffset;
extern uint32 IGNHAL_u32WdgDelayLimitation;
extern uint32 IgnHALFixedDwellTime;
extern uint8 IgnHALCoilToCommand;
extern uint16 IGNHAL_u16AppliedAdvance;
extern uint16 IGNHAL_u16EngineSpeed;
extern uint16 IGNHAL_u16IgnVbrf;
extern uint16 IgnHALAdvanceToApplicate;
extern uint16 IgnHALNextAdvanceToApplicate;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* IGNHAL_L_H */

/*-------------------------------- end of file -------------------------------*/
