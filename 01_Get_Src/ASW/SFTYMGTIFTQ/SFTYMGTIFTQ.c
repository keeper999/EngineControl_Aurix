/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : SFTYMGTIFTQ                                              */
/*                                                                            */
/* !Module         : SFTYMGTIFTQ                                              */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : SFTYMGTIFTQ.C75                                          */
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
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SFTYMGTIFTQ/SFTYMGTIFTQ.c7v       $*/
/* $Revision::   1.4      $$Author::   hmelloul       $$Date::   21 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SFTYMGTIFTQ.h"
#include "SFTYMGTIFTQ_l.h"

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

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
const boolean  SftyMgt_bInhEngStopReq_C = 0;
const boolean  SftyMgt_bRstEndRcvRun_C = 0;
const boolean  SftyMgt_bRstThrReq_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_ctDftLaddDftConf_C = 0;
const uint8  SftyMgt_ctDftLaddFirstConf_C = 0;
const uint8  SftyMgt_nDecCpt_StuckAccP_C = 0;
const uint8  SftyMgt_nDownThd_StuckAccP_C = 0;
const uint8  SftyMgt_nInitCpt_StuckAccP_C = 0;
const uint8  SftyMgt_nInpChkMax_C = 0;
const uint8  SftyMgt_nInpChkMin_C = 0;
const uint8  SftyMgt_nUpThd_StuckAccP_C = 0;
const uint8  SFTYMGTIFTQ_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const uint16  SftMgt_ctWrMemDftConf_C = 0;
const uint16  Sfty_ctrMaxAccPCpu_C = 0;
const uint16  Sfty_ctrMaxAlgoCpu_C = 0;
const uint16  Sfty_ctrMaxAlgoCpuSfty_C = 0;
const uint16  Sfty_ctrMaxClkCpu_C = 0;
const uint16  Sfty_ctrMaxClkCpuSfty_C = 0;
const uint16  Sfty_ctrMaxThrCpu_C = 0;
const uint16  Sfty_decAccPCpu_C = 0;
const uint16  Sfty_decAlgoCpu_C = 0;
const uint16  Sfty_decAlgoCpuSfty_C = 0;
const uint16  Sfty_decClkCpu_C = 0;
const uint16  Sfty_decClkCpuSfty_C = 0;
const uint16  Sfty_decThrCpu_C = 0;
const uint16  Sfty_incAccPCpu_C = 0;
const uint16  Sfty_incAlgoCpu_C = 0;
const uint16  Sfty_incAlgoCpuSfty_C = 0;
const uint16  Sfty_incClkCpu_C = 0;
const uint16  Sfty_incClkCpuSfty_C = 0;
const uint16  Sfty_incThrCpu_C = 0;
const uint16  SftyMgt_ctWrMemFirstConf_C = 0;
const uint16  SftyMgt_prm_bFrfDftConf_C[SFTYMGT_PRM_BFRFDFTCONF_C_COLS] = {0};
const uint16  SftyMgt_prm_bFrfFirstConf_C[SFTYMGT_PRM_BFRFFIRSTCONF_C_COLS] = {0};
const uint16  SftyMgt_rAccPMax_C = 0;
const uint16  SftyMgt_uAccPSen1Min_C = 0;
const uint16  SftyMgt_uAccPSen2Min_C = 0;
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_32BIT
#include "MemMap.h"
const uint32  SftyMgt_prm_bDftHisDftConf_C[SFTYMGT_PRM_BDFTHISDFTCONF_C_COLS] = {0};
const uint32  SftyMgt_prm_bDftHisFirstConf_C[SFTYMGT_PRM_BDFTHISFIRSTCONF_C_COLS] = {0};
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
boolean Ext_bInhDft;
boolean Sfty3_bEndRcvRun;
boolean Sfty3_bEngStopReq;
boolean Sfty3_bRstHwReq;
boolean Sfty3_bThrReq;
boolean SftyMgt_bBrkPedPrss;
boolean SftyMgt_bCluPedPrss;
boolean SftyMgt_bDftAutChk;
boolean SftyMgt_bDftAutChkIni;
boolean SftyMgt_bDftEM;
boolean SftyMgt_bDftSftyStuckAccP;
boolean SftyMgt_bDftStuckAccP;
boolean SftyMgt_bDgoAccPChk;
boolean SftyMgt_bDgoALUChk;
boolean SftyMgt_bDgoCalChk;
boolean SftyMgt_bDgoClkChk;
boolean SftyMgt_bDgoInhChkInitSfty;
boolean SftyMgt_bDgoIrvEMPrev;
boolean SftyMgt_bDgoIrvSTTPrev;
boolean SftyMgt_bDgoIrvVSCtlPrev;
boolean SftyMgt_bDgoRAMChk;
boolean SftyMgt_bDgoRAMChk2;
boolean SftyMgt_bDgoSenPN;
boolean SftyMgt_bDgoSwChk;
boolean SftyMgt_bDgoThrChk;
boolean SftyMgt_bDrvStrtReq;
boolean SftyMgt_bEepromStatus;
boolean SftyMgt_bInhStrtAMT;
boolean SftyMgt_bInpChk;
boolean SftyMgt_bInpChkAccP;
boolean SftyMgt_bInpChkBrk;
boolean SftyMgt_bInpChkClu;
boolean SftyMgt_bInpChkF329;
boolean SftyMgt_bInpChkF349;
boolean SftyMgt_bInpChkF34D;
boolean SftyMgt_bInpChkF38D;
boolean SftyMgt_bInpChkNeutPosn;
boolean SftyMgt_bInpChkThr;
boolean SftyMgt_bInpChkVehSpd;
boolean SftyMgt_bMonRunInhChkInitSfty;
boolean SftyMgt_bNeut;
boolean SftyMgt_bRStrtAuthTra;
boolean SftyMgt_bSIPTra;
boolean SftyMgt_bTotCutOff;
boolean SftyMgt_bTqTx;
boolean SFTYMGTIFTQ_bDgoAlgo_Cpu;
boolean SFTYMGTIFTQ_bDgoAlgo_CpuSfty;
boolean SFTYMGTIFTQ_bDgoClk_Cpu;
boolean SFTYMGTIFTQ_bDgoClk_CpuSfty;
boolean SFTYMGTIFTQ_bDgoIrvEMPrev1;
boolean SFTYMGTIFTQ_bDgoIrvSTTPrev1;
boolean SFTYMGTIFTQ_bDgoIrvVSCtlPrev1;
boolean SFTYMGTIFTQ_bFilSig_1;
boolean SFTYMGTIFTQ_bRawSig;
boolean SFTYMGTIFTQ_bStuckAccP;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
sint8 SftyMgt_noEgdGearTra;
sint8 SftyMgt_noTarGearTra;
uint8 ECU_ctDftLadd;
uint8 SftyMgt_ctDftLaddPrev;
uint8 SftyMgt_F329LocalLength;
uint8 SftyMgt_F329MsgData[SFTYMGT_F329MSGDATA_COLS];
uint8 SftyMgt_F349LocalLength;
uint8 SftyMgt_F349MsgData[SFTYMGT_F349MSGDATA_COLS];
uint8 SftyMgt_F38DLocalLength;
uint8 SftyMgt_F38DMsgData[SFTYMGT_F38DMSGDATA_COLS];
uint8 SftyMgt_prm_bInjAcvCyl;
uint8 SftyMgt_prm_bInjCutOffCyl;
uint8 SftyMgt_stTqReqCha;
uint8 SFTYMGTIFTQ_CtDftSftyStuckAccP;
uint8 SFTYMGTIFTQ_u8AntiBounceCounter;
uint8 SFTYMGTIFTQ_u8CntFilt_1;
uint8 SFTYMGTIFTQ_u8ctDftLaddPrev1;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 SftyMgt_agIgAdvCur;
sint16 SftyMgt_tqMSRReqCha;
uint16 ECU_ctWrMem;
uint16 ECU_prm_bFrf[ECU_PRM_BFRF_COLS];
uint16 Ext_rOpThr;
uint16 Ext_uOpSecThrMes;
uint16 Ext_uOpThrMes;
uint16 Sfty_ctrAccPCpu;
uint16 Sfty_ctrAlgoCpu;
uint16 Sfty_ctrAlgoCpuSfty;
uint16 Sfty_ctrClkCpu;
uint16 Sfty_ctrClkCpuSfty;
uint16 Sfty_ctrThrCpu;
uint16 SftyMgt_nEng;
uint16 SftyMgt_pBrkAsi;
uint16 SftyMgt_posnThr;
uint16 SftyMgt_rAccP;
uint16 SftyMgt_rCluPedPHiFreq;
uint16 SftyMgt_rCluPedSen;
uint16 SftyMgt_rNeutSen;
uint16 SftyMgt_rOpTrbActReqTrbAct;
uint16 SftyMgt_spdVeh;
uint16 SftyMgt_uAccPSen1;
uint16 SftyMgt_uAccPSen2;
uint16 SftyMgt_uThrRef;
uint16 SftyMgt_uThrSen1;
uint16 SftyMgt_uThrSen2;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
uint32 ECU_prm_bDftHis[ECU_PRM_BDFTHIS_COLS];
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

