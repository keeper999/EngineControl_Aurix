/***************************************************************************
;**
;** FILE NAME      : ACQCOT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQCOT_H
#define ACQCOT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CTS_RANGE_CONV_BKPT_MAP_COLS           ( 33 )
#define CTS_RANGE_CONV_MAP_COLS                ( 33 )
#define CTS_RAW_RESOL                     80
#define TEMPERATURE_EAU_BKPT_MAP_COLS          ( 16 )

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

extern const uint8  Cts_default_coolant_temp;
extern const uint8  Cts_global_failure_default_temp;
extern const uint8  Temp_eau_grad_thresh;
extern const uint8  Temperature_eau_bkpt_map[TEMPERATURE_EAU_BKPT_MAP_COLS];
extern const sint16  Ext_tCoMesPwrl_C;
extern const uint16  Cts_oc_failure_thresh;
extern const uint16  Cts_range_conv_bkpt_map[CTS_RANGE_CONV_BKPT_MAP_COLS];
extern const uint16  Cts_range_conv_map[CTS_RANGE_CONV_MAP_COLS];
extern const uint16  Cts_sc0_failure_thresh;
extern const uint16  Cts_sc1_failure_thresh;
extern const uint16  Temp_eau_diag_grad_delay;
extern const uint16  Temperature_eau_mode_defaut_step;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Crank_to_run_water_temp;
extern uint8 Temperature_eau_a_stall;
extern uint8 Temperature_eau_mesuree;
extern sint16 Ext_tCoMesFineResl;
extern uint16 Cts_range_voltage;
extern uint16 Cts_raw_range_temp;
extern uint16 Temperature_eau_mode_defaut;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACQCOT_NVMSRV_vidInit(void);
void CoT_EveCrTR_AcqCoT(void);
void CoT_EvePwrl_AcqCoT(void);
void CoT_EveRst_AcqCoT(void);
void CoT_EveStTR_AcqCoT(void);
void CoT_SdlMid_AcqCoT(void);
void CoT_SdlSlow_AcqCoT(void);


#endif /* ACQCOT_H */

/*-------------------------------- end of file -------------------------------*/
