/***************************************************************************
;**
;** FILE NAME      : FTPCTL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FTPCTL.H"
#include "FTPCTL_L.H"
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
const boolean  FTPCtl_bAcvPmpStrt_C = 0;
const boolean  FTPCtl_bCfPmpOnOff_C = 0;
const boolean  FTPCtl_bMemFirstCmdFuPmpRst_C = 0;
const boolean  FTPCtl_bRstFlowFuFil_C = 0;
const uint32  FTPCtl_mFuInjX_A[FTPCTL_MFUINJX_A_COLS] = {0};
const uint32  FTPCtl_tiVehStop_C = 0;
const uint8  Ext_noCylEng_C = 0;
const uint8  FTPCtl_facConTiFlowFuFil_C = 0;
const uint8  FTPCtl_noFlowFuPerc_C = 0;
const uint8  FTPCtl_noStEngAdpNbEng_C = 0;
const uint8  FTPCtl_rIniFlowFuFil_C = 0;
const uint8  FTPCtl_rThdHysRatFlowFu_C = 0;
const uint8  FTPCtl_stEngRun_C = 0;
const uint8  FTPCtl_stFirst_C = 0;
const uint8  FTPCTL_u8Inhib = 0;
const sint16  FTPCtl_rDeltaCompHiFlowFu_C = 0;
const sint16  FTPCtl_rDeltaCompLoFlowFu_C = 0;
const uint16  FTPCtl_ctAcvPmpEngCut_C = 0;
const uint16  FTPCtl_ctAcvPmpEngrunGas_C = 0;
const uint16  FTPCtl_ctAcvPmpSTTStop_C = 0;
const uint16  FTPCtl_ctAcvShoFlowFuPmp_C = 0;
const uint16  FTPCtl_ctAcvShoStopFuPmp_C = 0;
const uint16  FTPCtl_ctEngCutStallLdMem_C = 0;
const uint16  FTPCtl_ctFirstAcvFuPmp_C = 0;
const uint16  FTPCtl_ctWaitAcvPmpCyc_C = 0;
const uint16  FTPCtl_ctWaitAcvPmpSTTStop_C = 0;
const uint16  FTPCtl_ctWaitPmpEngrunGas_C = 0;
const uint16  FTPCtl_ctWaitPmpEngrunGasFu_C = 0;
const uint16  FTPCtl_nEngY_A[FTPCTL_NENGY_A_COLS] = {0};
const uint16  FTPCtl_rFlowAcvCyc_C = 0;
const uint16  FTPCtl_rFlowAcvPrim_C = 0;
const uint16  FTPCtl_rFlowDeacCyc_C = 0;
const uint16  FTPCtl_rFlowFuEngPrep_C = 0;
const uint16  FTPCtl_rFlowFuEngRstrt_C = 0;
const uint16  FTPCtl_rFlowFuEngrunFuChgGas_C = 0;
const uint16  FTPCtl_rFlowFuEngrunGas_C = 0;
const uint16  FTPCtl_rFlowFuEngrunGasChgFu_C = 0;
const uint16  FTPCtl_rFlowFuEngrunGasWait_C = 0;
const uint16  FTPCtl_rFlowFuEngStopPmpOff_C = 0;
const uint16  FTPCtl_rFlowFuEngStopPmpStrt_C = 0;
const uint16  FTPCtl_rFlowFuEngStrt_C = 0;
const uint16  FTPCtl_rFlowFuForcGasChgFu_C = 0;
const uint16  FTPCtl_rFlowFuHiDft_C = 0;
const uint16  FTPCtl_rFlowFuLoDft_C = 0;
const uint16  FTPCtl_rFlowFuThdHi_C = 0;
const uint16  FTPCtl_rFlowFuThdLo_C = 0;
const uint16  FTPCtl_rFlowLgStop_C = 0;
const uint16  FTPCtl_rFlowNom_C = 0;
const uint16  FTPCtl_rFlowShoStop_C = 0;
const uint16  FTPCtl_rFlowWait_C = 0;
const uint16  FTPCtl_tiHldVldWin_C = 0;
const uint16  FTPCtl_tiWaitAcvFil_C = 0;
const uint16  FTPCtl_volfDynFlowFuAd_M[FTPCTL_VOLFDYNFLOWFUAD_M_LNS][FTPCTL_VOLFDYNFLOWFUAD_M_COLS] = {0};
const uint16  FTPCtl_volfFlowFuEng_M[FTPCTL_VOLFFLOWFUENG_M_LNS][FTPCTL_VOLFFLOWFUENG_M_COLS] = {0};
const uint16  FTPCtl_volfFlowFuMax_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 FTPCtl_stCaseEngAlt;
uint8 FTPCtl_stEng;
uint8 FTPCtl_stEngCutStall;
boolean Afts_bRstMemFirstFillFuEng_MP;
boolean ECU_bWkuPtEngStrtDly_MP;
boolean FTPCtl_bAcvPmpWkuPha;
boolean FTPCTL_bECUbWkuPtEngStrtPrev;
boolean FTPCtl_bEngCutStall;
boolean FTPCtl_bEngCutStallInter;
boolean FTPCTL_bEOL_inCdn;
boolean FTPCTL_bEOL_outCdn;
boolean FTPCTL_bEOLStateTimerCond;
boolean FTPCtl_bFilDec_rFlowFuNxt_MP;
boolean FTPCtl_bFilDec_rSel_MP;
boolean FTPCtl_bFirstCmdFuPmp;
boolean FTPCtl_bFirstCmdFuPmpNxt_MP;
boolean FTPCtl_bFirstCmdFuPmpTmrMax;
boolean FTPCtl_bFirstFillFuMemOut_MP;
boolean FTPCtl_bFirstFillFuNxt_MP;
boolean FTPCTL_bLogicalOrFlowFuPrev;
boolean FTPCtl_bMemFirstFillFu;
boolean FTPCTL_bMemFirstFillFuEngPrev1;
boolean FTPCTL_bMemFirstFillFuEngPrev2;
boolean FTPCtl_bVoltCtlReq;
uint32 FTPCtl_noMassFuInj_nEng_MP;
uint32 FTPCTL_u32rFilDecrFlowFuFiltMem;
uint8 FTPCtl_mfHysWide;
uint16 FTPCtl_ctAcvPmpCutStall;
uint16 FTPCtl_ctAcvPmpEngRunCaseAfu;
uint16 FTPCtl_ctCutStallLdMem;
uint16 FTPCtl_ctFirstCmdFuPmpTmr;
uint16 FTPCtl_ctFirstCmdTmrInc_MP;
uint16 FTPCtl_ctFirstCmdTmrMem_MP;
uint16 FTPCtl_ctStopPmpCutStall;
uint16 FTPCtl_ctStopPmpEngRunAfu;
uint16 FTPCtl_ctTmrAcvPmpCaseEs;
uint16 FTPCtl_ctTmrStopPmpCaseEs;
uint16 FTPCtl_ctTranForcGasChgFu;
uint16 FTPCtl_rFilDec_rFlowFu;
uint16 FTPCtl_rFilIncRat_MP;
uint16 FTPCtl_rFilIncRatFlowFu;
uint16 FTPCtl_rFilIncRatFlowFuFil_MP;
uint16 FTPCtl_rFilIncRatFlowFuNxt_MP;
uint16 FTPCtl_rFlowFuCutStall;
uint16 FTPCtl_rFlowFuDftOnOff;
uint16 FTPCtl_rFlowFuDftProp;
uint16 FTPCtl_rFlowFuEngRunEngAfu;
uint16 FTPCtl_rFlowFuEngStAfuHyb;
uint16 FTPCtl_rFlowFuTnkPmp;
uint16 FTPCtl_rNormFlowRat;
uint16 FTPCTL_u16ECUbWkuPtEngStrtCount;
uint16 FTPCTL_u16FlowFuCount;
uint16 FTPCTL_u16IniCdnOutput;
uint16 FTPCTL_u16outputcounter;
uint16 FTPCtl_volfDynFlowFuAd_MP;
uint16 FTPCtl_volfFlowFu_MP;
uint16 FTPCtl_volfSumFlowFu;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

