/***************************************************************************
;**
;** FILE NAME      : COFANCMDDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COFANCMDDIAG_H
#define COFANCMDDIAG_H

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

extern const boolean  CoFan_bAcvCrashCond_C;
extern const uint8  CoFan_CFricMinSpd_C;
extern const uint8  CoFan_HiStFan1_C;
extern const uint8  CoFan_incCntCritScFanC_C;
extern const uint8  CoFan_incCntDftFanC_C;
extern const uint8  CoFan_incCntRskCritScFanC_C;
extern const uint8  CoFan_LoStFan1_C;
extern const uint8  CoFan_noSpdVehFanB1HiThd_C;
extern const uint8  CoFan_noSpdVehFanB1LoThd_C;
extern const uint8  CoFan_noSpdVehFanB2HiThd_C;
extern const uint8  CoFan_noSpdVehFanB2LoThd_C;
extern const uint8  CoFan_noStFanDownThd_C;
extern const uint8  CoFan_noStFanUpThd_C;
extern const uint8  CoFan_noThdCntCritScFanC_C;
extern const uint8  CoFan_noThdCntRskCritScFanC_C;
extern const uint8  CoFan_rFanB1HiThd_C;
extern const uint8  CoFan_rFanB1LoThd_C;
extern const uint8  CoFan_rFanB2HiSpd2HiThd_C;
extern const uint8  CoFan_rFanB2HiSpd2LoThd_C;
extern const uint8  CoFan_rFanB2HiSpdHiThd_C;
extern const uint8  CoFan_rFanB2HiSpdLoThd_C;
extern const uint8  CoFan_rFanB2LoSpdHiThd_C;
extern const uint8  CoFan_rFanB2LoSpdLoThd_C;
extern const uint8  CoFan_rFanCritScVal_C;
extern const uint8  CoFan_rFanNOKVal_C;
extern const uint8  CoFan_rFanOKVal_C;
extern const uint8  CoFan_rFanTolRngVal_C;
extern const uint8  CoFan_rHiSpdFan_C;
extern const uint8  CoFan_rLoSpdFan_C;
extern const uint8  CoFan_rSpdFanCOpRlyThd_C;
extern const uint8  CoFan_rSpdFanCThd_C;
extern const uint8  CoFan_tiChgDlyStFanB1_C;
extern const uint8  CoFan_tiChgDlyStFanB2_C;
extern const uint8  CoFan_tiChgDlyStFanC_C;
extern const uint8  CoFan_tiInitDly_C;
extern const uint8  CoFan_tiOnDly_C;
extern const uint8  CoFan_tiTqDly_C;
extern const uint16  CoFan_max_voltage_diag_thresh;
extern const uint16  CoFan_min_voltage_diag_thresh;
extern const uint16  CoFan_noMaxThdCntDftFanC_C;
extern const uint16  CoFan_noMinVoltThdB2_C;
extern const uint16  CoFan_noRecThdCntDftFanC_C;
extern const uint16  CoFan_rSpdFanCMaxSlewRate_C;
extern const uint16  CoFan_rSpdFanCMinSlewRate_C;
extern const uint16  CoFan_tiHldDly_C;
extern const uint16  CoFan_tiHldDlyHiSpd_C;
extern const uint16  CoFan_tiHldDlyLoSpd_C;
extern const uint16  CoFan_tiOffDly_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoFan_bAcvCoFan1CmdAppld;
extern boolean CoFan_bAcvCoFan2CmdAppld;
extern boolean Ext_bStFanB1Raw;
extern boolean Ext_bStFanB2Raw;
extern boolean Ext_bStFanFil;
extern boolean FanCtl_bReqIncVoltMin;
extern boolean ThMgt_bCmdHiSpdFan;
extern boolean ThMgt_bCmdLowSpdFan;
extern boolean ThMgt_bTarHiSpdFan;
extern boolean ThMgt_bTarLowSpdFan;
extern uint8 Cf_speed_for_air;
extern uint16 CoFan_rAcvCoFan1CmdAppld;
extern uint16 Ext_rStFanC;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CoFan_EveRst_CmdDiagCoFan(void);
void CoFan_EveRstDft_CmdDiagCoFan(void);
void CoFan_SdlMid_CmdDiagCoFan(void);


#endif /* COFANCMDDIAG_H */

/*-------------------------------- end of file -------------------------------*/
