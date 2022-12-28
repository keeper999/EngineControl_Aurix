/***************************************************************************
;**
;** FILE NAME      : VLVACTEXACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXACQ_H
#define VLVACTEXACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EVC_CYCLE_LENGHT_EX               7680

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

extern const boolean  VlvAct_bExSelTypIniCntCmTooth_C;
extern const boolean  Vta_exhaust_advance_config;
extern const boolean  Vta_exhaust_resynchro_manu_inh;
extern const boolean  Vta_exhaust_vel_calc_mod;
extern const boolean  Vta_exhaust_X_tooth_check;
extern const uint8  Vta_exhaust_def_tooth;
extern const uint8  Vta_exhaust_pmh_threshold;
extern const uint8  Vta_exhaust_tooth_nb;
extern const uint16  VlvAct_agCmExToothGap_C;
extern const uint16  VlvAct_agExMaxFrntGap_C;
extern const uint16  Vlvact_nEngAcvExMissToothThd_C;
extern const uint16  Vlvact_nEngAcvExORngShiftThd_C;
extern const uint16  Vlvact_nEngAcvExTDCThd_C;
extern const uint16  VlvAct_nEngExORngShiftThdLo_C;
extern const uint16  VlvAct_nEngExORngShiftThdLoHys_C;
extern const uint16  VlvAct_nEngExTDCDiagThdLo_C;
extern const uint16  VlvAct_nEngExTDCDiagThdLoHys_C;
extern const uint16  Vta_exhaust_camshaft_shift_def;
extern const uint16  Vta_exhaust_dyn_lim;
extern const uint16  Vta_exhaust_higher_def_limit;
extern const uint16  Vta_exhaust_lower_def_limit;
extern const uint16  Vta_exhaust_noMultPeriod;
extern const uint16  Vta_exhaust_to_1;
extern const uint16  Vta_exhaust_to_2;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bVoltSenCmEx;
extern uint8 Ext_ctEdgeCmEx;
extern uint8 Vta_exhaust_tooth_counter;
extern sint16 Vta_exhaust_filt_velocity;
extern uint16 Ext_agCmExMes;
extern uint16 Ext_nEngCmExMes;
extern uint16 Ext_tiPatCmEx;
extern uint16 VlvAct_nEngExCmFil;
extern uint16 Vta_exhaust_tooth_time;
extern uint16 Vxx_rel_ex_vvt_mes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveCkSnOn_ExAcq(void);
void VlvAct_EveExCam_ExAcq(void);
void VlvAct_EveExCmToo_ExAcq(void);
void VlvAct_EveKOn_ExAcq(void);
void VlvAct_EveTDC_ExAcq(void);
void VlvAct_SdlFast_ExAcq(void);
void VLVACTEXACQ_vidEntryInit(void);


#endif /* VLVACTEXACQ_H */

/*-------------------------------- end of file -------------------------------*/
