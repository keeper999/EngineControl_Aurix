/******************************************************************************/
/*                                                                            */
/* !Component      : SFTYMGTIFTQ                                              */
/*                                                                            */
/* !Module         : SFTYMGTIFTQ                                              */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : SFTYMGTIFTQ.H                                            */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEES                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SFTYMGTIFTQ/SFTYMGTIFTQ.H_v       $*/
/* $Revision::   1.4      $$Author::   hmelloul       $$Date::   21 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef SFTYMGTIFTQ_H
#define SFTYMGTIFTQ_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ECU_PRM_BDFTHIS_COLS                   (SFTYMGTIFTQ_u32ARRAY_LENGTH)
#define ECU_PRM_BFRF_COLS                      (SFTYMGTIFTQ_u16ARRAY_LENGTH)
#define SFTYMGT_F329MSGDATA_COLS               (8)
#define SFTYMGT_F349MSGDATA_COLS               (8)
#define SFTYMGT_F38DMSGDATA_COLS               (8)
#define SftyMgt_NVMSRV_StatusOK           1          /* 1 */
#define SFTYMGT_PRM_BDFTHISDFTCONF_C_COLS      (4)
#define SFTYMGT_PRM_BDFTHISFIRSTCONF_C_COLS    (4)
#define SFTYMGT_PRM_BFRFDFTCONF_C_COLS         (8)
#define SFTYMGT_PRM_BFRFFIRSTCONF_C_COLS       (8)
#define SFTYMGTIFTQ_u16ARRAY_LENGTH       8           /* 8 */
#define SFTYMGTIFTQ_u32ARRAY_LENGTH       4           /* 4 */
#define SFTYMGTIFTQ_u8ARRAY4_LENGTH       4           /* 4 */
#define SFTYMGTIFTQ_u8ARRAY8_LENGTH       8           /* 8 */

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
extern const boolean  SftyMgt_bInhEngStopReq_C;
extern const boolean  SftyMgt_bRstEndRcvRun_C;
extern const boolean  SftyMgt_bRstThrReq_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_ctDftLaddDftConf_C;
extern const uint8  SftyMgt_ctDftLaddFirstConf_C;
extern const uint8  SftyMgt_nDecCpt_StuckAccP_C;
extern const uint8  SftyMgt_nDownThd_StuckAccP_C;
extern const uint8  SftyMgt_nInitCpt_StuckAccP_C;
extern const uint8  SftyMgt_nInpChkMax_C;
extern const uint8  SftyMgt_nInpChkMin_C;
extern const uint8  SftyMgt_nUpThd_StuckAccP_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const uint16  SftMgt_ctWrMemDftConf_C;
extern const uint16  Sfty_ctrMaxAccPCpu_C;
extern const uint16  Sfty_ctrMaxAlgoCpu_C;
extern const uint16  Sfty_ctrMaxAlgoCpuSfty_C;
extern const uint16  Sfty_ctrMaxClkCpu_C;
extern const uint16  Sfty_ctrMaxClkCpuSfty_C;
extern const uint16  Sfty_ctrMaxThrCpu_C;
extern const uint16  Sfty_decAccPCpu_C;
extern const uint16  Sfty_decAlgoCpu_C;
extern const uint16  Sfty_decAlgoCpuSfty_C;
extern const uint16  Sfty_decClkCpu_C;
extern const uint16  Sfty_decClkCpuSfty_C;
extern const uint16  Sfty_decThrCpu_C;
extern const uint16  Sfty_incAccPCpu_C;
extern const uint16  Sfty_incAlgoCpu_C;
extern const uint16  Sfty_incAlgoCpuSfty_C;
extern const uint16  Sfty_incClkCpu_C;
extern const uint16  Sfty_incClkCpuSfty_C;
extern const uint16  Sfty_incThrCpu_C;
extern const uint16  SftyMgt_ctWrMemFirstConf_C;
extern const uint16  SftyMgt_prm_bFrfDftConf_C[SFTYMGT_PRM_BFRFDFTCONF_C_COLS];
extern const uint16  SftyMgt_prm_bFrfFirstConf_C[SFTYMGT_PRM_BFRFFIRSTCONF_C_COLS];
extern const uint16  SftyMgt_rAccPMax_C;
extern const uint16  SftyMgt_uAccPSen1Min_C;
extern const uint16  SftyMgt_uAccPSen2Min_C;
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_32BIT
#include "MemMap.h"
extern const uint32  SftyMgt_prm_bDftHisDftConf_C[SFTYMGT_PRM_BDFTHISDFTCONF_C_COLS];
extern const uint32  SftyMgt_prm_bDftHisFirstConf_C[SFTYMGT_PRM_BDFTHISFIRSTCONF_C_COLS];
#define TMS_STOP_SEC_CALIB_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean Ext_bInhDft;
extern boolean Sfty3_bEndRcvRun;
extern boolean Sfty3_bEngStopReq;
extern boolean Sfty3_bRstHwReq;
extern boolean Sfty3_bThrReq;
extern boolean SftyMgt_bBrkPedPrss;
extern boolean SftyMgt_bCluPedPrss;
extern boolean SftyMgt_bDftAutChk;
extern boolean SftyMgt_bDftAutChkIni;
extern boolean SftyMgt_bDftEM;
extern boolean SftyMgt_bDftSftyStuckAccP;
extern boolean SftyMgt_bDgoAccPChk;
extern boolean SftyMgt_bDgoALUChk;
extern boolean SftyMgt_bDgoCalChk;
extern boolean SftyMgt_bDgoClkChk;
extern boolean SftyMgt_bDgoIrvEMPrev;
extern boolean SftyMgt_bDgoIrvSTTPrev;
extern boolean SftyMgt_bDgoIrvVSCtlPrev;
extern boolean SftyMgt_bDgoRAMChk;
extern boolean SftyMgt_bDgoRAMChk2;
extern boolean SftyMgt_bDgoSenPN;
extern boolean SftyMgt_bDgoSwChk;
extern boolean SftyMgt_bDgoThrChk;
extern boolean SftyMgt_bDrvStrtReq;
extern boolean SftyMgt_bInhStrtAMT;
extern boolean SftyMgt_bInpChk;
extern boolean SftyMgt_bNeut;
extern boolean SftyMgt_bRStrtAuthTra;
extern boolean SftyMgt_bSIPTra;
extern boolean SftyMgt_bTotCutOff;
extern boolean SftyMgt_bTqTx;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
extern uint32 ECU_prm_bDftHis[ECU_PRM_BDFTHIS_COLS];
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern sint8 SftyMgt_noEgdGearTra;
extern sint8 SftyMgt_noTarGearTra;
extern uint8 ECU_ctDftLadd;
extern uint8 SftyMgt_ctDftLaddPrev;
extern uint8 SftyMgt_F329LocalLength;
extern uint8 SftyMgt_F329MsgData[SFTYMGT_F329MSGDATA_COLS];
extern uint8 SftyMgt_F349LocalLength;
extern uint8 SftyMgt_F349MsgData[SFTYMGT_F349MSGDATA_COLS];
extern uint8 SftyMgt_F38DLocalLength;
extern uint8 SftyMgt_F38DMsgData[SFTYMGT_F38DMSGDATA_COLS];
extern uint8 SftyMgt_prm_bInjAcvCyl;
extern uint8 SftyMgt_prm_bInjCutOffCyl;
extern uint8 SftyMgt_stTqReqCha;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_agIgAdvCur;
extern sint16 SftyMgt_tqMSRReqCha;
extern uint16 ECU_ctWrMem;
extern uint16 ECU_prm_bFrf[ECU_PRM_BFRF_COLS];
extern uint16 Ext_rOpThr;
extern uint16 Ext_uOpSecThrMes;
extern uint16 Ext_uOpThrMes;
extern uint16 SftyMgt_nEng;
extern uint16 SftyMgt_pBrkAsi;
extern uint16 SftyMgt_posnThr;
extern uint16 SftyMgt_rAccP;
extern uint16 SftyMgt_rCluPedPHiFreq;
extern uint16 SftyMgt_rCluPedSen;
extern uint16 SftyMgt_rNeutSen;
extern uint16 SftyMgt_rOpTrbActReqTrbAct;
extern uint16 SftyMgt_spdVeh;
extern uint16 SftyMgt_uAccPSen1;
extern uint16 SftyMgt_uAccPSen2;
extern uint16 SftyMgt_uThrRef;
extern uint16 SftyMgt_uThrSen1;
extern uint16 SftyMgt_uThrSen2;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_EveChkLih_ifTqMon(void);
void SftyMgt_EveRst_ifTqMon(void);
void SftyMgt_EveRxn329_ifTqMon(void);
void SftyMgt_EveRxn349_ifTqMon(void);
void SftyMgt_EveRxn34D_ifTqMon(void);
void SftyMgt_EveRxn38D_ifTqMon(void);
void SftyMgt_EveTDC_ifTqMon(void);
void SftyMgt_SdlFast_ifTqMon(void);
void SftyMgt_SdlMid_ifTqMon(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* SFTYMGTIFTQ_H */

/*-------------------------------- end of file -------------------------------*/
