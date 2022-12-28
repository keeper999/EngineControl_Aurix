/***************************************************************************
;**
;** FILE NAME      : WGCMDSP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WGCMDSP_H
#define WGCMDSP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define WG_CMDSP_NENG_A_COLS                   ( 16 )
#define WG_CMDSP_NENGX_PINMNFREQCORNY_M_LNS   ( 16 )
#define WG_CMDSP_NENGX_PINMNFREQCORNY_M_COLS   ( 16 )
#define WG_CMDSP_PINMNFREQCORRN_A_COLS         ( 16 )
#define WG_CMDSP_TQIDCAIR_NENG_A_COLS          ( 16 )
#define WG_CMDSP_TQIDCAIRREQ_A_COLS            ( 16 )
#define WG_CMDSP_TQIDCAIRX_NENGY_M_LNS        ( 16 )
#define WG_CMDSP_TQIDCAIRX_NENGY_M_COLS        ( 16 )
#define WG_NENGBKPT_A_COLS                     ( 9 )
#define WG_PINISPGSERVO_NENGX_T_COLS           ( 16 )
#define WG_PSPGFILPRESERR_A_COLS               ( 9 )
#define Wg_SampleTiMid_SC                 40
#define WG_SERVOPIDCOEFFDFTL_M_LNS            ( 9 )
#define WG_SERVOPIDCOEFFDFTL_M_COLS            ( 9 )
#define WG_SERVOPIDCOEFFINTGL_M_LNS           ( 9 )
#define WG_SERVOPIDCOEFFINTGL_M_COLS           ( 9 )
#define WG_SERVOPIDCOEFFPROP_M_LNS            ( 9 )
#define WG_SERVOPIDCOEFFPROP_M_COLS            ( 9 )

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

extern const boolean  TrbAct_bInhICor_C;
extern const boolean  Wg_bOplCmdSp_ETB_C;
extern const boolean  Wg_bSelWgCmdSp_C;
extern const sint8  Wg_pOfsCorrnPresAlti_C;
extern const uint8  Wg_CoeffCorrnPresAlti_C;
extern const uint8  Wg_nrSampleTiClcAdpv_C;
extern const uint8  Wg_pAtmThdEnaAdpv_C;
extern const uint8  Wg_pCoeffSpcPwmCorrnPresAlti_C;
extern const uint8  Wg_pSpgThdEnaAdpv_C;
extern const uint8  Wg_pSpgThdOpplCmd_C;
extern const uint8  Wg_tCoThdOpplCmd_C;
extern const sint16  Wg_pDbndThdEnaElmProp_C;
extern const sint16  Wg_pSpgdervPresErrThdMax_C;
extern const sint16  Wg_pSpgdervPresErrThdMin_C;
extern const sint16  Wg_pSpgHiThdPresErr_C;
extern const sint16  Wg_pSpgLoThdPresErr_C;
extern const sint16  Wg_pSpgThdPresErr_C;
extern const sint16  Wg_rDbndElmAdpvThdMax_C;
extern const sint16  Wg_rDbndElmAdpvThdMin_C;
extern const sint16  Wg_rFacFiltMidAdpv_C;
extern const sint16  Wg_rWgCmdDeltaThdEnaAdpv_C;
extern const sint16  Wg_rWgCmdSpIni_C;
extern const sint16  Wg_rWgCmdTarElmIntgl_C;
extern const sint16  Wg_rWgCmdThdMaxSp_C;
extern const sint16  Wg_rWgCmdThdMinSp_C;
extern const sint16  Wg_rWgServoElmAdpvCmdThdMax_C;
extern const sint16  Wg_rWgServoElmAdpvCmdThdMin_C;
extern const sint16  Wg_rWgServoElmIntglCmdMax_C;
extern const sint16  Wg_rWgServoElmIntglCmdMin_C;
extern const uint16  Wg_CmdSp_nEng_A[WG_CMDSP_NENG_A_COLS];
extern const uint16  Wg_CmdSp_nEngX_pInMnfReqCornY_M[WG_CMDSP_NENGX_PINMNFREQCORNY_M_LNS][WG_CMDSP_NENGX_PINMNFREQCORNY_M_COLS];
extern const uint16  Wg_CmdSp_pInMnfReqCorrn_A[WG_CMDSP_PINMNFREQCORRN_A_COLS];
extern const uint16  Wg_CmdSp_tqIdcAir_nEng_A[WG_CMDSP_TQIDCAIR_NENG_A_COLS];
extern const uint16  Wg_CmdSp_tqIdcAirReq_A[WG_CMDSP_TQIDCAIRREQ_A_COLS];
extern const uint16  Wg_CmdSp_tqIdcAirX_nEngY_M[WG_CMDSP_TQIDCAIRX_NENGY_M_LNS][WG_CMDSP_TQIDCAIRX_NENGY_M_COLS];
extern const uint16  Wg_facDifChStabyThdEnaAdpv_C;
extern const uint16  Wg_facFilSpgdervPresErr_C;
extern const uint16  Wg_nEngBkpt_A[WG_NENGBKPT_A_COLS];
extern const uint16  Wg_nEngThdEnaAdpv_C;
extern const uint16  Wg_pAtmoMean_C;
extern const uint16  Wg_pIniSpgServo_nEngX_T[WG_PINISPGSERVO_NENGX_T_COLS];
extern const uint16  Wg_pSpgFilPresErr_A[WG_PSPGFILPRESERR_A_COLS];
extern const uint16  Wg_ServoPIDCoeffDftl_M[WG_SERVOPIDCOEFFDFTL_M_LNS][WG_SERVOPIDCOEFFDFTL_M_COLS];
extern const uint16  Wg_ServoPIDCoeffIntgl_M[WG_SERVOPIDCOEFFINTGL_M_LNS][WG_SERVOPIDCOEFFINTGL_M_COLS];
extern const uint16  Wg_ServoPIDCoeffProp_M[WG_SERVOPIDCOEFFPROP_M_LNS][WG_SERVOPIDCOEFFPROP_M_COLS];
extern const uint16  Wg_uBattHiThdEnaAdpv_C;
extern const uint16  Wg_uBattLoThdEnaAdpv_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint16 Wg_rWgCmdSp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Wg_EveRst_WgCmdSp(void);
void Wg_SdlMid_WgCmdSp(void);


#endif /* WGCMDSP_H */

/*-------------------------------- end of file -------------------------------*/
