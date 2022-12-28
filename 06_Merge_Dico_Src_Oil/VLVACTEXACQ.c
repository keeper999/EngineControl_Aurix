/***************************************************************************
;**
;** FILE NAME      : VLVACTEXACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXACQ.H"
#include "VLVACTEXACQ_L.H"
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
const boolean  VlvAct_bExSelTypIniCntCmTooth_C = 0;
const boolean  Vta_exhaust_advance_config = 0;
const boolean  Vta_exhaust_resynchro_manu_inh = 0;
const boolean  Vta_exhaust_vel_calc_mod = 0;
const boolean  Vta_exhaust_X_tooth_check = 0;
const uint8  VLVACTEXACQ_u8Inhib = 0;
const uint8  Vta_exhaust_def_tooth = 0;
const uint8  Vta_exhaust_pmh_threshold = 0;
const uint8  Vta_exhaust_tooth_nb = 0;
const uint16  VlvAct_agCmExToothGap_C = 0;
const uint16  VlvAct_agExMaxFrntGap_C = 0;
const uint16  Vlvact_nEngAcvExMissToothThd_C = 0;
const uint16  Vlvact_nEngAcvExORngShiftThd_C = 0;
const uint16  Vlvact_nEngAcvExTDCThd_C = 0;
const uint16  VlvAct_nEngExORngShiftThdLo_C = 0;
const uint16  VlvAct_nEngExORngShiftThdLoHys_C = 0;
const uint16  VlvAct_nEngExTDCDiagThdLo_C = 0;
const uint16  VlvAct_nEngExTDCDiagThdLoHys_C = 0;
const uint16  Vta_exhaust_camshaft_shift_def = 0;
const uint16  Vta_exhaust_dyn_lim = 0;
const uint16  Vta_exhaust_higher_def_limit = 0;
const uint16  Vta_exhaust_lower_def_limit = 0;
const uint16  Vta_exhaust_noMultPeriod = 0;
const uint16  Vta_exhaust_to_1 = 0;
const uint16  Vta_exhaust_to_2 = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bVoltSenCmEx;
boolean VlvAct_bDgoMissToothVlvActEx;
boolean VlvAct_bDgoORngShiftVlvActEx;
boolean VlvAct_bDgoORngSpdVlvActEx;
boolean VlvAct_bDgoTDCDiagVlvActEx;
boolean VlvAct_bMonRunMissToothVlvActEx;
boolean VlvAct_bMonRunORngShiftVlvActEx;
boolean VlvAct_bMonRunORngSpdVlvActEx;
boolean VlvAct_bMonRunTDCDiagVlvActEx;
boolean VLVACTEXACQ_bnEngExORngShiftThd;
boolean VLVACTEXACQ_bnEngExTDCDiagThd;
boolean Vta_exhaust_camshaft_level;
boolean Vta_exhaust_velocity_set;
uint8 Ext_ctEdgeCmEx;
uint8 VLVACTEXACQ_u8VehActivStatePrev;
uint8 Vta_exhaust_pmh_counter;
uint8 Vta_exhaust_tooth_counter;
sint16 VLVACTEXACQ_s16VtaExhaustFilt1;
sint16 VLVACTEXACQ_s16VtaExhaustFilt2;
sint16 Vta_exhaust_camshaft_shift;
sint16 Vta_exhaust_camshaft_velocity;
sint16 Vta_exhaust_camshaft_velocity_1;
sint16 Vta_exhaust_camshaft_velocity_2;
sint16 Vta_exhaust_filt_velocity;
uint16 Ext_agCmExMes;
uint16 Ext_agCmExMesTbl[EXT_AGCMEXMESTBL_COLS];
uint16 Ext_nEngCmExMes;
uint16 Ext_tiPatCmEx;
uint16 VlvAct_nEngExCm;
uint16 VlvAct_nEngExCmAdd;
uint16 VlvAct_nEngExCmFil;
uint16 VLVACTEXACQ_u16EngInCmPrev1;
uint16 VLVACTEXACQ_u16EngInCmPrev2;
uint16 VLVACTEXACQ_u16EngInCmPrev3;
uint16 VLVACTEXACQ_u16RelInVvtMesPrev;
uint16 Vta_exhaust_tooth_time;
uint16 Vxx_rel_ex_vvt_mes;
sint32 VLVACTEXACQ_s32FrstOrderFiltMem1;
sint32 VLVACTEXACQ_s32FrstOrderFiltMem2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

