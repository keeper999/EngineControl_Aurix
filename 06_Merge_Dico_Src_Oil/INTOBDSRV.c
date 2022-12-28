/***************************************************************************
;**
;** FILE NAME      : INTOBDSRV.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INTOBDSRV.H"
#include "INTOBDSRV_L.H"
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
const boolean  Test_bed_pulse = 0;
const uint8  INTOBDSRV_u8Inhib = 0;
const uint8  Srv_Obd_Mode_C = 0;
const uint8  Srv_Pos_SenO2_C = 0;
const uint8  Srv_prmByteAPid72_C = 0;
const uint8  Srv_prmPid07_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint32 Srv_MaxValEqRatio_Pid4F;
uint8 AFAStl_rSlowFuCor;
uint8 AFRegStl_lamFb;
uint8 AFRegStl_stCllRich;
uint8 BoostActStl_rDuCyReqCplm;
uint8 Srv_AccP_Pos1_Pid49;
uint8 Srv_AccP_Pos2_Pid4A;
uint8 Srv_Cstr_Pid2E;
uint8 Srv_Diag_trim_Pid07;
uint8 Srv_Engine_load_Pid04;
uint8 Srv_Fuel_System_Pid03;
uint8 Srv_IgCmd_Pid0E;
uint8 Srv_Lfbk_Pid06;
uint8 Srv_mfAirScvLimMaxCor_Pid50;
uint8 Srv_ObdMod_Pid1C;
uint8 Srv_OpThr_Pid4C;
uint8 Srv_pAtm_Pid33;
uint8 Srv_pDsThrMes_Pid0B;
uint8 Srv_SensO2_Pos_Pid13;
uint8 Srv_spdVeh_Pid0D;
uint8 Srv_tAirMes_Pid0F;
uint8 Srv_tCoMes_Pid05;
uint8 Srv_Thr_Pos1_Pid11;
uint8 Srv_Thr_Pos2_Pid47;
uint8 Srv_uDsLs_Pid15;
uint8 Srv_uUpLs_Pid14;
uint8 Srv_WUCDftClr_Pid30;
uint8 TrbActStl_rOpTrbAct;
uint16 FARSpStl_lamSp;
uint16 Srv_AstTot_Pid1F;
uint16 Srv_dstKmMilOn_Pid21;
uint16 Srv_dstKmRstDft_Pid31;
uint16 Srv_EngRunMilOn_Pid4D;
uint16 Srv_nEng_Pid0C;
uint16 Srv_OxCEstim_Pid3C;
uint16 Srv_pFuMes_Pid23;
uint16 Srv_tiMinsEngrunRstDft_Pid4E;
uint16 Srv_uBattMes_Pid42;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

