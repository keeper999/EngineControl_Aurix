/***************************************************************************
;**
;** FILE NAME      : WGCMDSP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "WGCMDSP.H"
#include "WGCMDSP_L.H"
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
const boolean  TrbAct_bInhICor_C = 0;
const boolean  Wg_bOplCmdSp_ETB_C = 0;
const boolean  Wg_bSelWgCmdSp_C = 0;
const sint8  Wg_pOfsCorrnPresAlti_C = 0;
const uint8  Wg_CoeffCorrnPresAlti_C = 0;
const uint8  Wg_nrSampleTiClcAdpv_C = 0;
const uint8  Wg_pAtmThdEnaAdpv_C = 0;
const uint8  Wg_pCoeffSpcPwmCorrnPresAlti_C = 0;
const uint8  Wg_pSpgThdEnaAdpv_C = 0;
const uint8  Wg_pSpgThdOpplCmd_C = 0;
const uint8  Wg_tCoThdOpplCmd_C = 0;
const uint8  WGCMDSP_u8Inhib = 0;
const sint16  Wg_pDbndThdEnaElmProp_C = 0;
const sint16  Wg_pSpgdervPresErrThdMax_C = 0;
const sint16  Wg_pSpgdervPresErrThdMin_C = 0;
const sint16  Wg_pSpgHiThdPresErr_C = 0;
const sint16  Wg_pSpgLoThdPresErr_C = 0;
const sint16  Wg_pSpgThdPresErr_C = 0;
const sint16  Wg_rDbndElmAdpvThdMax_C = 0;
const sint16  Wg_rDbndElmAdpvThdMin_C = 0;
const sint16  Wg_rFacFiltMidAdpv_C = 0;
const sint16  Wg_rWgCmdDeltaThdEnaAdpv_C = 0;
const sint16  Wg_rWgCmdSpIni_C = 0;
const sint16  Wg_rWgCmdTarElmIntgl_C = 0;
const sint16  Wg_rWgCmdThdMaxSp_C = 0;
const sint16  Wg_rWgCmdThdMinSp_C = 0;
const sint16  Wg_rWgServoElmAdpvCmdThdMax_C = 0;
const sint16  Wg_rWgServoElmAdpvCmdThdMin_C = 0;
const sint16  Wg_rWgServoElmIntglCmdMax_C = 0;
const sint16  Wg_rWgServoElmIntglCmdMin_C = 0;
const uint16  Wg_CmdSp_nEng_A[WG_CMDSP_NENG_A_COLS] = {0};
const uint16  Wg_CmdSp_nEngX_pInMnfReqCornY_M[WG_CMDSP_NENGX_PINMNFREQCORNY_M_LNS][WG_CMDSP_NENGX_PINMNFREQCORNY_M_COLS] = {0};
const uint16  Wg_CmdSp_pInMnfReqCorrn_A[WG_CMDSP_PINMNFREQCORRN_A_COLS] = {0};
const uint16  Wg_CmdSp_tqIdcAir_nEng_A[WG_CMDSP_TQIDCAIR_NENG_A_COLS] = {0};
const uint16  Wg_CmdSp_tqIdcAirReq_A[WG_CMDSP_TQIDCAIRREQ_A_COLS] = {0};
const uint16  Wg_CmdSp_tqIdcAirX_nEngY_M[WG_CMDSP_TQIDCAIRX_NENGY_M_LNS][WG_CMDSP_TQIDCAIRX_NENGY_M_COLS] = {0};
const uint16  Wg_facDifChStabyThdEnaAdpv_C = 0;
const uint16  Wg_facFilSpgdervPresErr_C = 0;
const uint16  Wg_nEngBkpt_A[WG_NENGBKPT_A_COLS] = {0};
const uint16  Wg_nEngThdEnaAdpv_C = 0;
const uint16  Wg_pAtmoMean_C = 0;
const uint16  Wg_pIniSpgServo_nEngX_T[WG_PINISPGSERVO_NENGX_T_COLS] = {0};
const uint16  Wg_pSpgFilPresErr_A[WG_PSPGFILPRESERR_A_COLS] = {0};
const uint16  Wg_ServoPIDCoeffDftl_M[WG_SERVOPIDCOEFFDFTL_M_LNS][WG_SERVOPIDCOEFFDFTL_M_COLS] = {0};
const uint16  Wg_ServoPIDCoeffIntgl_M[WG_SERVOPIDCOEFFINTGL_M_LNS][WG_SERVOPIDCOEFFINTGL_M_COLS] = {0};
const uint16  Wg_ServoPIDCoeffProp_M[WG_SERVOPIDCOEFFPROP_M_LNS][WG_SERVOPIDCOEFFPROP_M_COLS] = {0};
const uint16  Wg_uBattHiThdEnaAdpv_C = 0;
const uint16  Wg_uBattLoThdEnaAdpv_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TrbAct_bInhICorRaw;
boolean Wg_bEnaApplAdpv;
boolean Wg_bEnaApplOlpCmd;
boolean Wg_bEnaApplServoCmd;
boolean Wg_bServoElmAdpvCmdEnaClc;
boolean Wg_bStsTranWg;
boolean WGCMDSP_bBoostPresClCtlAcvPrev;
sint8 Wg_pOfsAltiCorrnSpgPres;
uint8 Wg_ctDownSampleTiClcAdpv;
sint16 Wg_pDervFiltSpgPresErr;
sint16 Wg_pSpgFilPresErr;
sint16 Wg_pSpgPresErr;
sint16 Wg_pSpgPresErrPrev;
sint16 Wg_pUsThrErr;
sint16 Wg_rRawInctAdpv;
sint16 Wg_rWgCmdSp;
sint16 Wg_rWgCmdSpPrev;
sint16 Wg_rWgOplCmd;
sint16 Wg_rWgServoElmAdpvCmdPrev;
sint16 Wg_rWgServoElmDftlCmd;
sint16 Wg_rWgServoElmIntglCmd;
sint16 Wg_rWgServoElmIntglCmdPrev;
sint16 Wg_rWgServoElmPropCmd;
sint16 Wg_rWgServoUpdElmAdpvIntglCmd;
sint16 WGCMDSP_s16Ext_rCtlIntTestMod;
uint16 Wg_pInMnfReqCorrn;
uint16 Wg_rEngineLoadPrev;
sint32 Wg_pDervFiltSpgPresErrMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

