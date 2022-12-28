/***************************************************************************
;**
;** FILE NAME      : FTPCTL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FTPCTL_H
#define FTPCTL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define FTPCTL_MFUINJX_A_COLS                  ( 11 )
#define FTPCTL_NENGY_A_COLS                    ( 13 )
#define FTPCtl_tiRun_SC                   10
#define FTPCTL_VOLFDYNFLOWFUAD_M_LNS          ( 11 )
#define FTPCTL_VOLFDYNFLOWFUAD_M_COLS          ( 13 )
#define FTPCTL_VOLFFLOWFUENG_M_LNS            ( 11 )
#define FTPCTL_VOLFFLOWFUENG_M_COLS            ( 13 )

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

extern const boolean  FTPCtl_bAcvPmpStrt_C;
extern const boolean  FTPCtl_bCfPmpOnOff_C;
extern const boolean  FTPCtl_bMemFirstCmdFuPmpRst_C;
extern const boolean  FTPCtl_bRstFlowFuFil_C;
extern const uint32  FTPCtl_mFuInjX_A[FTPCTL_MFUINJX_A_COLS];
extern const uint32  FTPCtl_tiVehStop_C;
extern const uint8  Ext_noCylEng_C;
extern const uint8  FTPCtl_facConTiFlowFuFil_C;
extern const uint8  FTPCtl_noFlowFuPerc_C;
extern const uint8  FTPCtl_noStEngAdpNbEng_C;
extern const uint8  FTPCtl_rIniFlowFuFil_C;
extern const uint8  FTPCtl_rThdHysRatFlowFu_C;
extern const uint8  FTPCtl_stEngRun_C;
extern const uint8  FTPCtl_stFirst_C;
extern const sint16  FTPCtl_rDeltaCompHiFlowFu_C;
extern const sint16  FTPCtl_rDeltaCompLoFlowFu_C;
extern const uint16  FTPCtl_ctAcvPmpEngCut_C;
extern const uint16  FTPCtl_ctAcvPmpEngrunGas_C;
extern const uint16  FTPCtl_ctAcvPmpSTTStop_C;
extern const uint16  FTPCtl_ctAcvShoFlowFuPmp_C;
extern const uint16  FTPCtl_ctAcvShoStopFuPmp_C;
extern const uint16  FTPCtl_ctEngCutStallLdMem_C;
extern const uint16  FTPCtl_ctFirstAcvFuPmp_C;
extern const uint16  FTPCtl_ctWaitAcvPmpCyc_C;
extern const uint16  FTPCtl_ctWaitAcvPmpSTTStop_C;
extern const uint16  FTPCtl_ctWaitPmpEngrunGas_C;
extern const uint16  FTPCtl_ctWaitPmpEngrunGasFu_C;
extern const uint16  FTPCtl_nEngY_A[FTPCTL_NENGY_A_COLS];
extern const uint16  FTPCtl_rFlowAcvCyc_C;
extern const uint16  FTPCtl_rFlowAcvPrim_C;
extern const uint16  FTPCtl_rFlowDeacCyc_C;
extern const uint16  FTPCtl_rFlowFuEngPrep_C;
extern const uint16  FTPCtl_rFlowFuEngRstrt_C;
extern const uint16  FTPCtl_rFlowFuEngrunFuChgGas_C;
extern const uint16  FTPCtl_rFlowFuEngrunGas_C;
extern const uint16  FTPCtl_rFlowFuEngrunGasChgFu_C;
extern const uint16  FTPCtl_rFlowFuEngrunGasWait_C;
extern const uint16  FTPCtl_rFlowFuEngStopPmpOff_C;
extern const uint16  FTPCtl_rFlowFuEngStopPmpStrt_C;
extern const uint16  FTPCtl_rFlowFuEngStrt_C;
extern const uint16  FTPCtl_rFlowFuForcGasChgFu_C;
extern const uint16  FTPCtl_rFlowFuHiDft_C;
extern const uint16  FTPCtl_rFlowFuLoDft_C;
extern const uint16  FTPCtl_rFlowFuThdHi_C;
extern const uint16  FTPCtl_rFlowFuThdLo_C;
extern const uint16  FTPCtl_rFlowLgStop_C;
extern const uint16  FTPCtl_rFlowNom_C;
extern const uint16  FTPCtl_rFlowShoStop_C;
extern const uint16  FTPCtl_rFlowWait_C;
extern const uint16  FTPCtl_tiHldVldWin_C;
extern const uint16  FTPCtl_tiWaitAcvFil_C;
extern const uint16  FTPCtl_volfDynFlowFuAd_M[FTPCTL_VOLFDYNFLOWFUAD_M_LNS][FTPCTL_VOLFDYNFLOWFUAD_M_COLS];
extern const uint16  FTPCtl_volfFlowFuEng_M[FTPCTL_VOLFFLOWFUENG_M_LNS][FTPCTL_VOLFFLOWFUENG_M_COLS];
extern const uint16  FTPCtl_volfFlowFuMax_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean FTPCtl_bAcvPmpWkuPha;
extern boolean FTPCtl_bMemFirstFillFu;
extern boolean FTPCtl_bVoltCtlReq;
extern uint16 FTPCtl_rFlowFuTnkPmp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FTPCtl_Sdl10ms_FTPCtl(void);
void FTPCTL_vidEntryInit(void);


#endif /* FTPCTL_H */

/*-------------------------------- end of file -------------------------------*/
