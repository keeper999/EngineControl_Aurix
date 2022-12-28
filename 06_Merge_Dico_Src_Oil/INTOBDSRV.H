/***************************************************************************
;**
;** FILE NAME      : INTOBDSRV.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INTOBDSRV_H
#define INTOBDSRV_H

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

extern const boolean  Test_bed_pulse;
extern const uint8  Srv_Obd_Mode_C;
extern const uint8  Srv_Pos_SenO2_C;
extern const uint8  Srv_prmByteAPid72_C;
extern const uint8  Srv_prmPid07_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 Srv_MaxValEqRatio_Pid4F;
extern uint8 AFAStl_rSlowFuCor;
extern uint8 AFRegStl_lamFb;
extern uint8 AFRegStl_stCllRich;
extern uint8 BoostActStl_rDuCyReqCplm;
extern uint8 Srv_AccP_Pos1_Pid49;
extern uint8 Srv_AccP_Pos2_Pid4A;
extern uint8 Srv_Cstr_Pid2E;
extern uint8 Srv_Diag_trim_Pid07;
extern uint8 Srv_Engine_load_Pid04;
extern uint8 Srv_Fuel_System_Pid03;
extern uint8 Srv_IgCmd_Pid0E;
extern uint8 Srv_Lfbk_Pid06;
extern uint8 Srv_mfAirScvLimMaxCor_Pid50;
extern uint8 Srv_ObdMod_Pid1C;
extern uint8 Srv_OpThr_Pid4C;
extern uint8 Srv_pAtm_Pid33;
extern uint8 Srv_pDsThrMes_Pid0B;
extern uint8 Srv_SensO2_Pos_Pid13;
extern uint8 Srv_spdVeh_Pid0D;
extern uint8 Srv_tAirMes_Pid0F;
extern uint8 Srv_tCoMes_Pid05;
extern uint8 Srv_Thr_Pos1_Pid11;
extern uint8 Srv_Thr_Pos2_Pid47;
extern uint8 Srv_uDsLs_Pid15;
extern uint8 Srv_uUpLs_Pid14;
extern uint8 Srv_WUCDftClr_Pid30;
extern uint8 TrbActStl_rOpTrbAct;
extern uint16 FARSpStl_lamSp;
extern uint16 Srv_AstTot_Pid1F;
extern uint16 Srv_dstKmMilOn_Pid21;
extern uint16 Srv_dstKmRstDft_Pid31;
extern uint16 Srv_EngRunMilOn_Pid4D;
extern uint16 Srv_nEng_Pid0C;
extern uint16 Srv_OxCEstim_Pid3C;
extern uint16 Srv_pFuMes_Pid23;
extern uint16 Srv_tiMinsEngrunRstDft_Pid4E;
extern uint16 Srv_uBattMes_Pid42;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Srv_Eve14TDC_ObdSrvPid(void);
void Srv_EveBDC_ObdSrvPid(void);
void Srv_EveRst_ObdSrvPid(void);
void Srv_EveTDC_ObdSrvPid(void);
void Srv_SdlFast_ObdSrvPid(void);
void Srv_SdlMid_ObdSrvPid(void);


#endif /* INTOBDSRV_H */

/*-------------------------------- end of file -------------------------------*/
