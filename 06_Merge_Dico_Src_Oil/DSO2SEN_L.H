/***************************************************************************
;**
;** FILE NAME      : DSO2SEN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DSO2SEN_L_H
#define DSO2SEN_L_H

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

extern const uint8  DSO2SEN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoOc_uDsLs;
extern boolean Ext_bDgoScg_uDsLs;
extern boolean Ext_bDgoScp_uDsLs;
extern boolean Ext_bMonRunOc_uDsLs;
extern boolean Ext_bMonRunScg_uDsLs;
extern boolean Ext_bMonRunScp_uDsLs;
extern boolean Ext_bMonWaitOc_DsO2Sen;
extern boolean Ext_bMonWaitScg_uDsLs;
extern boolean Ext_bMonWaitScp_uDsLs;
extern uint32 DSO2SEN_FiltredPositionMem;
extern uint16 Ldsd_confirm_def_so2_av_count;
extern uint16 Ldsd_destockage_so2_av_count;
extern uint16 Ldsd_sensor_dead_zone_count;
extern uint16 Plus_sonde_o2_av_result_ad_conv;
extern uint16 Tension_sonde_av_max_dc;
extern uint16 Tension_sonde_av_min_dc;
extern uint16 Tension_sonde_aval_filtre;
extern uint16 Tension_sonde_aval_int;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DSO2SEN_vidAnalogMeasurement(void);
void DSO2SEN_vidBenchModeDownStream(void);
void DSO2SEN_vidCalDownStreamSO2(void);
void DSO2SEN_vidDefaultOCSO2(void);
void DSO2SEN_vidDiagCCSO2(void);
void DSO2SEN_vidDiagOCSO2(void);
void DSO2SEN_vidDiagSCGSO2(void);
void DSO2SEN_vidFreezeDownStreamSO2(void);
void DSO2SEN_vidInitCptrAuthorizeFail(void);
void DSO2SEN_vidInitDeadZoneCount(void);
void DSO2SEN_vidInitOutput(void);
void DSO2SEN_vidInitTempoDestock(void);
void DSO2SEN_vidManageTempoDestock(void);
void DSO2SEN_vidMngDownStreamSO2(void);
void DSO2SEN_vidMngVoltSO2Extrema(void);
void DSO2SEN_vidRunClefOff(void);
void DSO2SEN_vidSO2LeanToRich(void);
void DSO2SEN_vidSO2RichToLean(void);
void DSO2SEN_vidTempoBeforeFailure(void);
void DSO2SEN_vidVoltSO2WithoutDefect(void);


#endif /* DSO2SEN_L_H */

/*-------------------------------- end of file -------------------------------*/
