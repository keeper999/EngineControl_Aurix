/***************************************************************************
;**
;** FILE NAME      : CRSCTLBSITREAT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CRSCTLBSITREAT_L_H
#define CRSCTLBSITREAT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CRSCTLBSITREAT_I.h"
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

extern const uint8  CRSCTLBSITREAT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Cc_acc_regulation_type;
extern boolean Cc_limitation_speed_on;
extern boolean Cc_regulation_speed_on;
extern boolean CrsCtl_ACC_activated;
extern boolean CrsCtl_ACC_selected;
extern boolean CrsCtl_LVV_activated;
extern boolean CrsCtl_LVV_selected;
extern boolean CrsCtl_Off;
extern boolean CrsCtl_RVV_activated;
extern boolean CrsCtl_RVV_selected;
extern boolean Ext_bVSLimReq_2;
extern boolean Ext_bVSLimReqMem;
extern boolean Ext_bVSRegDVSRegReq_2;
extern boolean Ext_bVSRegDVSRegReqMem;
extern boolean VSCtl_bDftBsiFraCntInc;
extern boolean VSCtl_bDgoElChkConsDft;
extern boolean VSCtl_bDgoElConsCohVSMaxp;
extern boolean VSCtl_bDgoElConsDefDftVSLim;
extern boolean VSCtl_bDgoElConsDefDftVSMaxp;
extern boolean VSCtl_bDgoElConsDefDftVSReg;
extern boolean VSCtl_bDgoElConsInitDftVSReg;
extern boolean VSCtl_bDgoElConsVarDftVSLim;
extern boolean VSCtl_bDgoElConsVarDftVSReg;
extern boolean VSCtl_bDgoElCptTraBsiDft;
extern boolean VSCtl_bDgoElDftCrsCtl;
extern boolean VSCtl_bDgoElFrameCntIncDft;
extern boolean VSCtl_bDgoElInfBsiDft;
extern boolean VSCtl_bDgoEvenFrameCntDft;
extern boolean VSCtl_bDgoZeroFrameCntDft;
extern boolean VSCtl_bMonRunElDft;
extern boolean VSCtl_bSpdVehReqVSLimDft;
extern boolean VSCtl_bSpdVehReqVSRegDft;
extern uint8 Cc_coh_internal_checksum;
extern uint8 Ext_ctBSIFrameMem;
extern uint8 Ext_spdVehReqVSLimMem;
extern uint8 Ext_spdVehReqVSRegMem;
extern uint8 Ext_spdVehVSCtlReq_2;
extern uint8 Ext_stVSCtlReq_2;
extern uint8 VSCtl_ctEvenFrame;
extern uint8 VSCtl_ctEvenFramePrev;
extern uint8 VSCtl_ctZeroFrame;
extern uint8 VSCtl_ctZeroFramePrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CRSCTLBSITREAT_vidBsiFraCnt(void);
void CRSCTLBSITREAT_vidBsiFraFil(void);
void CRSCTLBSITREAT_vidCksCoh(void);
void CRSCTLBSITREAT_vidCptTraBsiInc(void);
void CRSCTLBSITREAT_vidCptTrBsiNtZero(void);
void CRSCTLBSITREAT_vidDiag_1(void);
void CRSCTLBSITREAT_vidDiag_2(void);
void CRSCTLBSITREAT_vidDiagEna(void);
void CRSCTLBSITREAT_vidInfoBsiCoh(void);
void CRSCTLBSITREAT_vidInfoTreat(void);
void CRSCTLBSITREAT_vidInit(void);
void CRSCTLBSITREAT_vidInitOutput(void);
void CRSCTLBSITREAT_vidLimSpdSpCoh(void);
void CRSCTLBSITREAT_vidNVRAMmanagemnt(void);
void CRSCTLBSITREAT_vidOutAcvRgVSCtRq(void);
void CRSCTLBSITREAT_vidOutspdVehLimRq(void);
void CRSCTLBSITREAT_vidRegSpdSpCoh(void);
void CRSCTLBSITREAT_vidspdVehVSRegReq(void);


#endif /* CRSCTLBSITREAT_L_H */

/*-------------------------------- end of file -------------------------------*/
