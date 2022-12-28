/***************************************************************************
;**
;** FILE NAME      : IGNHAL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGNHAL_Cfg.h"
#include "IGNHAL_E.h"
#include "IGNHAL_GATEWAY.h"
#include "IGNHAL.H"
#include "IGNHAL_L.H"
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
const uint32  IGNHAL_ku32SCToSupplyDiagDelay = 0;
const uint8  Icd_pos_slope_1 = 0;
const uint8  Icd_pos_slope_2 = 0;
const uint8  IGNHAL_ku8CoilPhysicMode = 0;
const uint8  IGNHAL_ku8NumberOfCylinders = 0;
const sint16  IGNHAL_ks16AdaptOffsetDef = 0;
const uint16  Icd_adapt_factor_twin_phys_max = 0;
const uint16  Icd_adapt_factor_twin_phys_min = 0;
const uint16  Icd_adapt_factor_twin_phys_step = 0;
const uint16  Icd_adapt_offset_twin_phys_step = 0;
const uint16  IGNHAL_kau16AdaptDwellLimitMap[IGNHAL_KAU16ADAPTDWELLLIMITMAP_COLS] = {0};
const uint16  IGNHAL_kau16EngSpdBrkptTab[IGNHAL_KAU16ENGSPDBRKPTTAB_COLS] = {0};
const uint16  IGNHAL_kau16VbrfBrkptTab[IGNHAL_KAU16VBRFBRKPTTAB_COLS] = {0};
const uint16  IGNHAL_kau16WdgDelayLimitMap[IGNHAL_KAU16WDGDELAYLIMITMAP_LNS][IGNHAL_KAU16WDGDELAYLIMITMAP_COLS] = {0};
const uint16  IGNHAL_ku16AdaptFactorDef = 0;
const uint16  IGNHAL_ku16InhibOCDiagDwellThd = 0;
const uint16  IGNHAL_ku16OCDetectionThreshold = 0;
const uint16  IGNHAL_ku16ShuntResistor = 0;
const uint16  IGNHAL_ku16TdcToRefAngle = 0;
const uint16  Seuil_bobine_cc_bat = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
uint8 IgnHALMode;
uint8 IgnHALWantedMode;
boolean Avance_disponible;
boolean IGNHAL_bCutCylinderA;
boolean IGNHAL_bCutCylinderB;
boolean IGNHAL_bCutCylinderC;
boolean IGNHAL_bCutCylinderD;
boolean IGNHAL_bEnabled;
boolean IGNHAL_bPeriodicIgnVbrfEna;
boolean IgnHALWriteEnergy_APICalled;
boolean Interdit_trig_it_dent_ref;
boolean Trait_pmh_avance_glisse;
uint32 IGNHAL_u32AdaptDwellLimitation;
uint32 IGNHAL_u32DiagPointOffset;
uint32 IGNHAL_u32WdgDelayLimitation;
uint32 IgnHALFixedDwellTime;
sint8 IGNHAL_s8TrimGainOutput_CM_24;
sint8 IGNHAL_s8TrimGainOutput_CM_3;
sint8 IGNHAL_s8TrimGainOutput_CM_45;
sint8 IGNHAL_s8TrimGainOutput_CM_66;
uint8 IgnHALCoilToCommand;
uint16 IGNHAL_u16AppliedAdvance;
uint16 IGNHAL_u16EngineSpeed;
uint16 IGNHAL_u16IgnVbrf;
uint16 IgnHALAdvanceToApplicate;
uint16 IgnHALNextAdvanceToApplicate;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

