/***************************************************************************
;**
;** FILE NAME      : FTPCTL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FTPCTL_L_H
#define FTPCTL_L_H

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

/* enum st122 */
#define CASEENGALT_INITIALIZATION         1
#define CASEENGALT_WAIT_FOR_WAKE_UP       2
#define CASEENGALT_ENGINE_RUNNING_PETROL  3
#define CASEENGALT_FORCED_TO_PETROL       4
#define CASEENGALT_TO_GAS                 5
#define CASEENGALT_NOMINAL_TO_PETROL      6
#define CASEENGALT_GAS_WAIT               7
#define CASEENGALT_GAS_ACTIVATION         8
/*extern uint8 FTPCtl_stCaseEngAlt;*/

/* enum st121 */
#define ENG_INITIALIZATION                0
#define ENG_CUT                           1
#define ENG_PREPARATION                   2
#define ENG_DRIVEN_START                  3
#define ENG_STOP_WAIT                     4
#define ENG_ENGINE_RUNNING                5
#define ENG_STOP_ACTIVATION               6
#define ENG_DRIVE_RESTART                 7
#define ENG_WAIT_FOR_WAKE_UP              8
#define ENG_STALLED                       9
/*extern uint8 FTPCtl_stEng;*/

/* enum st123 */
#define ENGCUTSTALL_PERIODIC_DEACT        0
#define ENGCUTSTALL_FIRST_PRIMING_MEMORY  1
#define ENGCUTSTALL_WAIT_FOR_WAKE_UP      2
#define ENGCUTSTALL_NOMINAL_PRE_REQUEST   3
#define ENGCUTSTALL_FIRST_PRIMING_STATE   4
#define ENGCUTSTALL_LONG_STOP_STATE       5
#define ENGCUTSTALL_SHORT_STOP_STATE      6
#define ENGCUTSTALL_PERIODIC_ACT          7
/*extern uint8 FTPCtl_stEngCutStall;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  FTPCTL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 FTPCtl_stCaseEngAlt;
extern uint8 FTPCtl_stEng;
extern uint8 FTPCtl_stEngCutStall;
extern boolean Afts_bRstMemFirstFillFuEng_MP;
extern boolean ECU_bWkuPtEngStrtDly_MP;
extern boolean FTPCTL_bECUbWkuPtEngStrtPrev;
extern boolean FTPCtl_bEngCutStall;
extern boolean FTPCtl_bEngCutStallInter;
extern boolean FTPCTL_bEOL_inCdn;
extern boolean FTPCTL_bEOL_outCdn;
extern boolean FTPCTL_bEOLStateTimerCond;
extern boolean FTPCtl_bFilDec_rFlowFuNxt_MP;
extern boolean FTPCtl_bFilDec_rSel_MP;
extern boolean FTPCtl_bFirstCmdFuPmp;
extern boolean FTPCtl_bFirstCmdFuPmpNxt_MP;
extern boolean FTPCtl_bFirstCmdFuPmpTmrMax;
extern boolean FTPCtl_bFirstFillFuMemOut_MP;
extern boolean FTPCtl_bFirstFillFuNxt_MP;
extern boolean FTPCTL_bLogicalOrFlowFuPrev;
extern boolean FTPCTL_bMemFirstFillFuEngPrev1;
extern boolean FTPCTL_bMemFirstFillFuEngPrev2;
extern uint32 FTPCtl_noMassFuInj_nEng_MP;
extern uint32 FTPCTL_u32rFilDecrFlowFuFiltMem;
extern uint8 FTPCtl_mfHysWide;
extern uint16 FTPCtl_ctAcvPmpCutStall;
extern uint16 FTPCtl_ctAcvPmpEngRunCaseAfu;
extern uint16 FTPCtl_ctCutStallLdMem;
extern uint16 FTPCtl_ctFirstCmdFuPmpTmr;
extern uint16 FTPCtl_ctFirstCmdTmrInc_MP;
extern uint16 FTPCtl_ctFirstCmdTmrMem_MP;
extern uint16 FTPCtl_ctStopPmpCutStall;
extern uint16 FTPCtl_ctStopPmpEngRunAfu;
extern uint16 FTPCtl_ctTmrAcvPmpCaseEs;
extern uint16 FTPCtl_ctTmrStopPmpCaseEs;
extern uint16 FTPCtl_ctTranForcGasChgFu;
extern uint16 FTPCtl_rFilDec_rFlowFu;
extern uint16 FTPCtl_rFilIncRat_MP;
extern uint16 FTPCtl_rFilIncRatFlowFu;
extern uint16 FTPCtl_rFilIncRatFlowFuFil_MP;
extern uint16 FTPCtl_rFilIncRatFlowFuNxt_MP;
extern uint16 FTPCtl_rFlowFuCutStall;
extern uint16 FTPCtl_rFlowFuDftOnOff;
extern uint16 FTPCtl_rFlowFuDftProp;
extern uint16 FTPCtl_rFlowFuEngRunEngAfu;
extern uint16 FTPCtl_rFlowFuEngStAfuHyb;
extern uint16 FTPCtl_rNormFlowRat;
extern uint16 FTPCTL_u16ECUbWkuPtEngStrtCount;
extern uint16 FTPCTL_u16FlowFuCount;
extern uint16 FTPCTL_u16IniCdnOutput;
extern uint16 FTPCTL_u16outputcounter;
extern uint16 FTPCtl_volfDynFlowFuAd_MP;
extern uint16 FTPCtl_volfFlowFu_MP;
extern uint16 FTPCtl_volfSumFlowFu;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FTPCTL_vidCorresponding_ratio(void);
void FTPCTL_vidEngine_need_calculus(void);
void FTPCTL_vidEOLMemorisation(void);
void FTPCTL_vidEOLStateTimer(void);
void FTPCTL_vidFalling_edge_filtering(void);
void FTPCTL_vidFlow_optimum(void);
void FTPCTL_vidFlowSetpointSynthesis(void);
void FTPCTL_vidHysteresis_filtering(void);
void FTPCTL_vidInitOutput(void);
void FTPCTL_vidPressHoldCaseCutStall(void);
void FTPCTL_vidPressHoldEngineActive(void);
void FTPCTL_vidPressure_hold_in_gas(void);
void FTPCTL_vidPriming_need(void);
void FTPCTL_vidRecovryModesActivation(void);
void FTPCTL_vidVolt_Control_activ(void);
void FTPCTL_vidWorking_field(void);


#endif /* FTPCTL_L_H */

/*-------------------------------- end of file -------------------------------*/
