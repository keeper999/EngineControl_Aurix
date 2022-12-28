/***************************************************************************
;**
;** FILE NAME      : VLVACTINACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINACQ.H"
#include "VLVACTINACQ_L.H"
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
const boolean  VlvAct_bInSelTypIniCntCmTooth_C = 0;
const boolean  Vta_intake_advance_configuration = 0;
const boolean  Vta_intake_resynchro_manu_inh = 0;
const boolean  Vta_intake_vel_calc_mod = 0;
const boolean  Vta_intake_X_tooth_check = 0;
const uint8  VLVACTINACQ_u8Inhib = 0;
const uint8  Vta_intake_def_tooth = 0;
const uint8  Vta_intake_pmh_threshold = 0;
const uint8  Vta_intake_tooth_nb = 0;
const uint16  VlvAct_agCmInToothGap_C = 0;
const uint16  VlvAct_agInMaxFrntGap_C = 0;
const uint16  VlvAct_nEngAcvInMissToothThd_C = 0;
const uint16  VlvAct_nEngAcvInOrngShiftThd_C = 0;
const uint16  VlvAct_nEngAcvInTDCThd_C = 0;
const uint16  VlvAct_nEngInORngShiftThdLo_C = 0;
const uint16  VlvAct_nEngInORngShiftThdLoHys_C = 0;
const uint16  VlvAct_nEngInTDCDiagThdLo_C = 0;
const uint16  VlvAct_nEngInTDCDiagThdLoHys_C = 0;
const uint16  Vta_intake_camshaft_shift_def = 0;
const uint16  Vta_intake_dyn_lim = 0;
const uint16  Vta_intake_higher_def_limit = 0;
const uint16  Vta_intake_lower_def_limit = 0;
const uint16  Vta_intake_noMultPeriod = 0;
const uint16  Vta_intake_to_1 = 0;
const uint16  Vta_intake_to_2 = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bVoltSenCmIn;
boolean VlvAct_bDgoMissToothVlvActIn;
boolean VlvAct_bDgoORngShiftVlvActIn;
boolean VlvAct_bDgoORngSpdVlvActIn;
boolean VlvAct_bDgoTDCDiagVlvActIn;
boolean VlvAct_bMonRunMissToothVlvActIn;
boolean VlvAct_bMonRunORngShiftVlvActIn;
boolean VlvAct_bMonRunORngSpdVlvActIn;
boolean VlvAct_bMonRunTDCDiagVlvActIn;
boolean VLVACTINACQ_bnEngInORngShiftThd;
boolean VLVACTINACQ_bnEngInTDCDiagThd;
boolean Vta_intake_camshaft_level;
boolean Vta_intake_velocity_set;
uint8 Ext_ctEdgeCmIn;
uint8 VLVACTINACQ_u8VehActvStatePrev;
uint8 Vta_intake_pmh_counter;
uint8 Vta_intake_tooth_counter;
sint16 VLVACTINACQ_s16VtaIntakeFilt1;
sint16 VLVACTINACQ_s16VtaIntakeFilt2;
sint16 Vta_intake_camshaft_shift;
sint16 Vta_intake_camshaft_velocity;
sint16 Vta_intake_camshaft_velocity_1;
sint16 Vta_intake_camshaft_velocity_2;
sint16 Vta_intake_filt_velocity;
uint16 Ext_agCmInMes;
uint16 Ext_agCmInMesTbl[EXT_AGCMINMESTBL_COLS];
uint16 Ext_agCmInMesTbl_4;
uint16 Ext_nEngCmInMes;
uint16 Ext_tiPatCmIn;
uint16 VlvAct_nEngInCm;
uint16 VlvAct_nEngInCmAdd;
uint16 VlvAct_nEngInCmFil;
uint16 VLVACTINACQ_u16EngInCmPrev1;
uint16 VLVACTINACQ_u16EngInCmPrev2;
uint16 VLVACTINACQ_u16EngInCmPrev3;
uint16 VLVACTINACQ_u16RelInVvtMesPrev;
uint16 Vta_intake_tooth_time;
uint16 Vxx_rel_in_vvt_mes;
sint32 VLVACTINACQ_s32FrstOrderFiltMem1;
sint32 VLVACTINACQ_s32FrstOrderFiltMem2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

