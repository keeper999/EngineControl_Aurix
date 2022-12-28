/***************************************************************************
;**
;** FILE NAME      : WGCMDSP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WGCMDSP_L_H
#define WGCMDSP_L_H

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

extern const uint8  WGCMDSP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TrbAct_bInhICorRaw;
extern boolean Wg_bEnaApplAdpv;
extern boolean Wg_bEnaApplOlpCmd;
extern boolean Wg_bEnaApplServoCmd;
extern boolean Wg_bServoElmAdpvCmdEnaClc;
extern boolean Wg_bStsTranWg;
extern boolean WGCMDSP_bBoostPresClCtlAcvPrev;
extern sint8 Wg_pOfsAltiCorrnSpgPres;
extern uint8 Wg_ctDownSampleTiClcAdpv;
extern sint16 Wg_pDervFiltSpgPresErr;
extern sint16 Wg_pSpgFilPresErr;
extern sint16 Wg_pSpgPresErr;
extern sint16 Wg_pSpgPresErrPrev;
extern sint16 Wg_pUsThrErr;
extern sint16 Wg_rRawInctAdpv;
extern sint16 Wg_rWgCmdSpPrev;
extern sint16 Wg_rWgOplCmd;
extern sint16 Wg_rWgServoElmAdpvCmdPrev;
extern sint16 Wg_rWgServoElmDftlCmd;
extern sint16 Wg_rWgServoElmIntglCmd;
extern sint16 Wg_rWgServoElmIntglCmdPrev;
extern sint16 Wg_rWgServoElmPropCmd;
extern sint16 Wg_rWgServoUpdElmAdpvIntglCmd;
extern sint16 WGCMDSP_s16Ext_rCtlIntTestMod;
extern uint16 Wg_pInMnfReqCorrn;
extern uint16 Wg_rEngineLoadPrev;
extern sint32 Wg_pDervFiltSpgPresErrMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void WgCmdSp_vidCdnApplAdpv(void);
void WgCmdSp_vidCdnOpenLoop(void);
void WgCmdSp_vidCdnServoCmd(void);
void WgCmdSp_vidClcAdpv(void);
void WgCmdSp_vidClcElm_A(void);
void WgCmdSp_vidClcElm_D(void);
void WgCmdSp_vidClcElm_I(void);
void WgCmdSp_vidClcElm_P(void);
void WgCmdSp_vidClcOfsAlti(void);
void WgCmdSp_vidClcPID(void);
void WgCmdSp_vidClcPwmOpenLoop(void);
void WgCmdSp_vidClcPwmOpenLoopCmd(void);
void WgCmdSp_vidClcPwmWg(void);
void WgCmdSp_vidFmtAdpv(void);
void WgCmdSp_vidInit(void);
void WgCmdSp_vidMemrSdl(void);
void WgCmdSp_vidSumElmPIDA(void);
void WgCmdSp_vidTranDetnClcErr(void);
void WgCmdSp_vidWgServoCdn(void);
void WgCmdSp_vidWgSysMng(void);


#endif /* WGCMDSP_L_H */

/*-------------------------------- end of file -------------------------------*/
