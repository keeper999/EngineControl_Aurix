/***************************************************************************
;**
;** FILE NAME      : CRSCTLBSITREAT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CRSCTLBSITREAT_I.h"
#include "CRSCTLBSITREAT.H"
#include "CRSCTLBSITREAT_L.H"
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
const uint8  CRSCTLBSITREAT_u8Inhib = 0;
const uint8  VSCtl_ctDecEvenFrame_C = 0;
const uint8  VSCtl_ctDecZeroFrame_C = 0;
const uint8  VSCtl_ctEvenFrameThd_C = 0;
const uint8  VSCtl_ctIncEvenFrame_C = 0;
const uint8  VSCtl_ctIncMaxFrame_C = 0;
const uint8  VSCtl_ctIncMinFrame_C = 0;
const uint8  VSCtl_ctIncZeroFrame_C = 0;
const uint8  VSCtl_ctZeroFrameThd_C = 0;
const uint8  VSCtl_spdVSLimReqDeltaMax1_C = 0;
const uint8  VSCtl_spdVSLimReqDeltaMin1_C = 0;
const uint8  VSCtl_spdVSLimReqMaxThd_C = 0;
const uint8  VSCtl_spdVSLimReqMinThd_C = 0;
const uint8  VSCtl_spdVSRegReqDeltaMax1_C = 0;
const uint8  VSCtl_spdVSRegReqDeltaMax2_C = 0;
const uint8  VSCtl_spdVSRegReqDeltaMax3_C = 0;
const uint8  VSCtl_spdVSRegReqDeltaMax4_C = 0;
const uint8  VSCtl_spdVSRegReqDeltaMin1_C = 0;
const uint8  VSCtl_spdVSRegReqDeltaMin2_C = 0;
const uint8  VSCtl_spdVSRegReqDeltaMin3_C = 0;
const uint8  VSCtl_spdVSRegReqDeltaMin4_C = 0;
const uint8  VSCtl_spdVSRegReqMaxThd_C = 0;
const uint8  VSCtl_spdVSRegReqMinThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Cc_acc_regulation_type;
boolean Cc_limitation_speed_on;
boolean Cc_regulation_speed_on;
boolean CrsCtl_ACC_activated;
boolean CrsCtl_ACC_selected;
boolean CrsCtl_LVV_activated;
boolean CrsCtl_LVV_selected;
boolean CrsCtl_Off;
boolean CrsCtl_RVV_activated;
boolean CrsCtl_RVV_selected;
boolean Ext_bVSLimReq_2;
boolean Ext_bVSLimReqMem;
boolean Ext_bVSRegDVSRegReq_2;
boolean Ext_bVSRegDVSRegReqMem;
boolean VSCtl_bDftBsiFraCntInc;
boolean VSCtl_bDgoElChkConsDft;
boolean VSCtl_bDgoElConsCohVSMaxp;
boolean VSCtl_bDgoElConsDefDftVSLim;
boolean VSCtl_bDgoElConsDefDftVSMaxp;
boolean VSCtl_bDgoElConsDefDftVSReg;
boolean VSCtl_bDgoElConsInitDftVSReg;
boolean VSCtl_bDgoElConsVarDftVSLim;
boolean VSCtl_bDgoElConsVarDftVSReg;
boolean VSCtl_bDgoElCptTraBsiDft;
boolean VSCtl_bDgoElDftCrsCtl;
boolean VSCtl_bDgoElFrameCntIncDft;
boolean VSCtl_bDgoElInfBsiDft;
boolean VSCtl_bDgoEvenFrameCntDft;
boolean VSCtl_bDgoZeroFrameCntDft;
boolean VSCtl_bMonRunElDft;
boolean VSCtl_bSpdVehReqVSLimDft;
boolean VSCtl_bSpdVehReqVSRegDft;
uint8 Cc_coh_internal_checksum;
uint8 Ext_ctBSIFrameMem;
uint8 Ext_spdVehReqVSLimMem;
uint8 Ext_spdVehReqVSRegMem;
uint8 Ext_spdVehVSCtlReq_2;
uint8 Ext_stVSCtlReq_2;
uint8 VSCtl_ctEvenFrame;
uint8 VSCtl_ctEvenFramePrev;
uint8 VSCtl_ctZeroFrame;
uint8 VSCtl_ctZeroFramePrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

