/***************************************************************************
;**
;** FILE NAME      : COFANCMDDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "COFANCMDDIAG.H"
#include "COFANCMDDIAG_L.H"
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
const boolean  CoFan_bAcvCrashCond_C = 0;
const uint8  CoFan_CFricMinSpd_C = 0;
const uint8  CoFan_HiStFan1_C = 0;
const uint8  CoFan_incCntCritScFanC_C = 0;
const uint8  CoFan_incCntDftFanC_C = 0;
const uint8  CoFan_incCntRskCritScFanC_C = 0;
const uint8  CoFan_LoStFan1_C = 0;
const uint8  CoFan_noSpdVehFanB1HiThd_C = 0;
const uint8  CoFan_noSpdVehFanB1LoThd_C = 0;
const uint8  CoFan_noSpdVehFanB2HiThd_C = 0;
const uint8  CoFan_noSpdVehFanB2LoThd_C = 0;
const uint8  CoFan_noStFanDownThd_C = 0;
const uint8  CoFan_noStFanUpThd_C = 0;
const uint8  CoFan_noThdCntCritScFanC_C = 0;
const uint8  CoFan_noThdCntRskCritScFanC_C = 0;
const uint8  CoFan_rFanB1HiThd_C = 0;
const uint8  CoFan_rFanB1LoThd_C = 0;
const uint8  CoFan_rFanB2HiSpd2HiThd_C = 0;
const uint8  CoFan_rFanB2HiSpd2LoThd_C = 0;
const uint8  CoFan_rFanB2HiSpdHiThd_C = 0;
const uint8  CoFan_rFanB2HiSpdLoThd_C = 0;
const uint8  CoFan_rFanB2LoSpdHiThd_C = 0;
const uint8  CoFan_rFanB2LoSpdLoThd_C = 0;
const uint8  CoFan_rFanCritScVal_C = 0;
const uint8  CoFan_rFanNOKVal_C = 0;
const uint8  CoFan_rFanOKVal_C = 0;
const uint8  CoFan_rFanTolRngVal_C = 0;
const uint8  CoFan_rHiSpdFan_C = 0;
const uint8  CoFan_rLoSpdFan_C = 0;
const uint8  CoFan_rSpdFanCOpRlyThd_C = 0;
const uint8  CoFan_rSpdFanCThd_C = 0;
const uint8  CoFan_tiChgDlyStFanB1_C = 0;
const uint8  CoFan_tiChgDlyStFanB2_C = 0;
const uint8  CoFan_tiChgDlyStFanC_C = 0;
const uint8  CoFan_tiInitDly_C = 0;
const uint8  CoFan_tiOnDly_C = 0;
const uint8  CoFan_tiTqDly_C = 0;
const uint8  COFANCMDDIAG_u8Inhib = 0;
const uint16  CoFan_max_voltage_diag_thresh = 0;
const uint16  CoFan_min_voltage_diag_thresh = 0;
const uint16  CoFan_noMaxThdCntDftFanC_C = 0;
const uint16  CoFan_noMinVoltThdB2_C = 0;
const uint16  CoFan_noRecThdCntDftFanC_C = 0;
const uint16  CoFan_rSpdFanCMaxSlewRate_C = 0;
const uint16  CoFan_rSpdFanCMinSlewRate_C = 0;
const uint16  CoFan_tiHldDly_C = 0;
const uint16  CoFan_tiHldDlyHiSpd_C = 0;
const uint16  CoFan_tiHldDlyLoSpd_C = 0;
const uint16  CoFan_tiOffDly_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 CoFan_stAcvCoFanCmd;
boolean CoFan_bAcvCoFan1Cmd;
boolean CoFan_bAcvCoFan1CmdAppld;
boolean CoFan_bAcvCoFan2Cmd;
boolean CoFan_bAcvCoFan2CmdAppld;
boolean CoFan_bDCDftStFanC;
boolean CoFan_bDgoClsdRly_StFanC;
boolean CoFan_bDgoCoh_StFanB1;
boolean CoFan_bDgoCoh_StFanB2HiSpd;
boolean CoFan_bDgoCoh_StFanB2LoSpd;
boolean CoFan_bDgoCoh_StFanB2NoSpd;
boolean CoFan_bDgoCritSc_StFanC;
boolean CoFan_bDgoECI_StFanC;
boolean CoFan_bDgoEl_StFanC;
boolean CoFan_bDgoHi_DrvrFan1;
boolean CoFan_bDgoHi_DrvrFan2;
boolean CoFan_bDgoLo_DrvrFan1;
boolean CoFan_bDgoLo_DrvrFan2;
boolean CoFan_bDgoOc_DrvrFan1;
boolean CoFan_bDgoOc_DrvrFan2;
boolean CoFan_bDgoUnVld_StFanC;
boolean CoFan_bFanB2HiSpd2;
boolean CoFan_bMonRunClsdRly_StFanC;
boolean CoFan_bMonRunCoh_StFanB1;
boolean CoFan_bMonRunCoh_StFanB2HiSpd;
boolean CoFan_bMonRunCoh_StFanB2LoSpd;
boolean CoFan_bMonRunCoh_StFanB2NoSpd;
boolean CoFan_bMonRunCritSc_StFanC;
boolean CoFan_bMonRunECI_StFanC;
boolean CoFan_bMonRunEl_StFanC;
boolean CoFan_bMonRunHi_DrvrFan1;
boolean CoFan_bMonRunHi_DrvrFan2;
boolean CoFan_bMonRunLo_DrvrFan1;
boolean CoFan_bMonRunLo_DrvrFan2;
boolean CoFan_bMonRunOc_DrvrFan1;
boolean CoFan_bMonRunOc_DrvrFan2;
boolean CoFan_bMonRunUnVld_StFanC;
boolean COFANCMDDIAG_bDgoEl_DrvrFan2;
boolean COFANCMDDIAG_bDgoHiDrvrFan1;
boolean COFANCMDDIAG_bDgoHiDrvrFan2;
boolean COFANCMDDIAG_bFaultGround1;
boolean COFANCMDDIAG_bFaultGround2;
boolean COFANCMDDIAG_bFaultOpen1;
boolean COFANCMDDIAG_bFaultOpen2;
boolean COFANCMDDIAG_bLocalCoFan1Cmdprev;
boolean COFANCMDDIAG_bLocalCoFan2Cmdprev;
boolean COFANCMDDIAG_bLocalInpTimer1prev;
boolean COFANCMDDIAG_bLocalInpTimer2prev;
boolean COFANCMDDIAG_bLocalInpTimer5prev;
boolean COFANCMDDIAG_bMonRunCoFan;
boolean COFANCMDDIAG_bMonRunCoh_B2NoSpd;
boolean COFANCMDDIAG_bMonRunCoh_Output;
boolean COFANCMDDIAG_bMonRunCoh_StFanB1;
boolean COFANCMDDIAG_bMonRunCoh_StFanB2;
boolean COFANCMDDIAG_bNoMaxThdPrev;
boolean COFANCMDDIAG_bNoRecThdPrev;
boolean COFANCMDDIAG_bNoThdPrev;
boolean COFANCMDDIAG_bStFanCPrev;
boolean Ext_bStFanB1Raw;
boolean Ext_bStFanB2Raw;
boolean Ext_bStFanFil;
boolean FanCtl_bReqIncVoltMin;
boolean ThMgt_bCmdHiSpdFan;
boolean ThMgt_bCmdLowSpdFan;
boolean ThMgt_bTarHiSpdFan;
boolean ThMgt_bTarLowSpdFan;
uint8 Cf_speed_for_air;
uint8 CoFan_rRCOFanC;
uint8 CoFan_rSpdFanCReqFil;
uint8 CoFan_rSpdFanPred;
uint8 COFANCMDDIAG_u8LocalCount;
uint8 COFANCMDDIAG_u8LocalcountTimer1;
uint8 COFANCMDDIAG_u8LocalcountTimer2;
uint8 COFANCMDDIAG_u8LocalcountTimer3;
uint8 COFANCMDDIAG_u8LocalcountTimer4;
uint8 COFANCMDDIAG_u8LocalcountTimer5;
uint8 COFANCMDDIAG_u8SchmitOutput1;
uint16 CoFan_ctDftStFanC;
uint16 CoFan_rAcvCoFan1Cmd;
uint16 CoFan_rAcvCoFan1CmdAppld;
uint16 CoFan_tiDlyTranActrProt;
uint16 Ext_rStFanC;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

