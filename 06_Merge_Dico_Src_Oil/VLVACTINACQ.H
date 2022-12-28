/***************************************************************************
;**
;** FILE NAME      : VLVACTINACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINACQ_H
#define VLVACTINACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EVC_CYCLE_LENGHT_IN               7680

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

extern const boolean  VlvAct_bInSelTypIniCntCmTooth_C;
extern const boolean  Vta_intake_advance_configuration;
extern const boolean  Vta_intake_resynchro_manu_inh;
extern const boolean  Vta_intake_vel_calc_mod;
extern const boolean  Vta_intake_X_tooth_check;
extern const uint8  Vta_intake_def_tooth;
extern const uint8  Vta_intake_pmh_threshold;
extern const uint8  Vta_intake_tooth_nb;
extern const uint16  VlvAct_agCmInToothGap_C;
extern const uint16  VlvAct_agInMaxFrntGap_C;
extern const uint16  VlvAct_nEngAcvInMissToothThd_C;
extern const uint16  VlvAct_nEngAcvInOrngShiftThd_C;
extern const uint16  VlvAct_nEngAcvInTDCThd_C;
extern const uint16  VlvAct_nEngInORngShiftThdLo_C;
extern const uint16  VlvAct_nEngInORngShiftThdLoHys_C;
extern const uint16  VlvAct_nEngInTDCDiagThdLo_C;
extern const uint16  VlvAct_nEngInTDCDiagThdLoHys_C;
extern const uint16  Vta_intake_camshaft_shift_def;
extern const uint16  Vta_intake_dyn_lim;
extern const uint16  Vta_intake_higher_def_limit;
extern const uint16  Vta_intake_lower_def_limit;
extern const uint16  Vta_intake_noMultPeriod;
extern const uint16  Vta_intake_to_1;
extern const uint16  Vta_intake_to_2;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bVoltSenCmIn;
extern uint8 Ext_ctEdgeCmIn;
extern uint8 Vta_intake_tooth_counter;
extern sint16 Vta_intake_filt_velocity;
extern uint16 Ext_agCmInMes;
extern uint16 Ext_nEngCmInMes;
extern uint16 Ext_tiPatCmIn;
extern uint16 VlvAct_nEngInCmFil;
extern uint16 Vta_intake_tooth_time;
extern uint16 Vxx_rel_in_vvt_mes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveCkSnOn_InAcq(void);
void VlvAct_EveInCam_InAcq(void);
void VlvAct_EveInCmToo_InAcq(void);
void VlvAct_EveKOn_InAcq(void);
void VlvAct_EveTDC_InAcq(void);
void VlvAct_SdlFast_InAcq(void);
void VLVACTINACQ_vidEntryInit(void);


#endif /* VLVACTINACQ_H */

/*-------------------------------- end of file -------------------------------*/
