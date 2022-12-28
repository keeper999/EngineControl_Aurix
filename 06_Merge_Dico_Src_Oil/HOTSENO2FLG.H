/***************************************************************************
;**
;** FILE NAME      : HOTSENO2FLG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HOTSENO2FLG_H
#define HOTSENO2FLG_H

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

extern const uint8  Lshd_sensor_voltage_filter_gain;
extern const uint8  LsSys_tiLsDsDlyHeatNotOk_C;
extern const uint8  LsSys_tiLsDsDlyHeatOkColdStrt_C;
extern const uint8  LsSys_tiLsDsDlyHeatOkHotStrt_C;
extern const uint8  LsSys_tiLsUsDlyHeatNotOk_C;
extern const uint8  LsSys_tiLsUsDlyHeatOkColdStrt_C;
extern const uint8  LsSys_tiLsUsDlyHeatOkHotStrt_C;
extern const uint16  Lshd_dwn_lbda_sens_heat_delay;
extern const uint16  Lshd_dwnstr_volt_high_limit;
extern const uint16  Lshd_dwnstr_volt_high_thresh;
extern const uint16  Lshd_dwnstr_volt_low_limit;
extern const uint16  Lshd_dwnstr_volt_low_thresh;
extern const uint16  Lshd_up_lbda_sens_heat_delay;
extern const uint16  Lshd_upstr_volt_high_limit;
extern const uint16  Lshd_upstr_volt_high_thresh;
extern const uint16  Lshd_upstr_volt_low_limit;
extern const uint16  Lshd_upstr_volt_low_thresh;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Lshd_down_stream_lbda_sensor_hot;
extern boolean Lshd_up_stream_lbda_sensor_hot;
extern boolean LsSys_bLsDsMainOxCHeatOkdiag;
extern boolean LsSys_bLsUsMainOxCHeatOk;
extern boolean LsSys_bLsUsMainOxCHeatOkdiag;
extern uint16 Lshd_dwn_lbda_sens_heat_count;
extern uint16 Lshd_up_lbda_sens_heat_count;
extern uint16 Lshd_voltage_dnstr_sens_filtered;
extern uint16 Lshd_voltage_upstr_sens_filtered;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_EveCrTR_HotSenO2Flg(void);
void HeatSenO2_EveRst_HotSenO2Flg(void);
void HeatSenO2_SdlMid_HotSenO2Flg(void);


#endif /* HOTSENO2FLG_H */

/*-------------------------------- end of file -------------------------------*/
