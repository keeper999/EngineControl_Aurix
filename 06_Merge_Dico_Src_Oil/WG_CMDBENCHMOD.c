/***************************************************************************
;**
;** FILE NAME      : WG_CMDBENCHMOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "WG_CMDBENCHMOD.H"
#include "WG_CMDBENCHMOD_L.H"
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
const boolean  Wg_bWgCmdOplBenchModEna_C = 0;
const boolean  Wg_bWgCmdOplCutOffSelPres_C = 0;
const uint8  Wg_CmdBenchMod_u8Inhib = 0;
const uint8  Wg_noWgCmdOplBenchModSel_C = 0;
const uint8  Wg_rWgCmdOplBenchModFilGain_C = 0;
const uint16  Wg_nEng_A[WG_NENG_A_COLS] = {0};
const uint16  Wg_nEngX_pWgCmdOplCutOffMax_T[WG_NENGX_PWGCMDOPLCUTOFFMAX_T_COLS] = {0};
const uint16  Wg_pBoost_A[WG_PBOOST_A_COLS] = {0};
const uint16  Wg_pInMnf_A[WG_PINMNF_A_COLS] = {0};
const uint16  Wg_pWgCmdOplCutOffMaxHys_C = 0;
const uint16  Wg_rWgCmdOpl_tqIdcAirX_nEngY_M[WG_RWGCMDOPL_TQIDCAIRX_NENGY_M_LNS][WG_RWGCMDOPL_TQIDCAIRX_NENGY_M_COLS] = {0};
const uint16  Wg_rWgCmdOpl_tqIdcAirX_pBoostY_M[WG_RWGCMDOPL_TQIDCAIRX_PBOOSTY_M_LNS][WG_RWGCMDOPL_TQIDCAIRX_PBOOSTY_M_COLS] = {0};
const uint16  Wg_rWgCmdOpl_tqIdcAirX_pInMnfY_M[WG_RWGCMDOPL_TQIDCAIRX_PINMNFY_M_LNS][WG_RWGCMDOPL_TQIDCAIRX_PINMNFY_M_COLS] = {0};
const uint16  Wg_rWgCmdOplBenchModIniSp_C = 0;
const uint16  Wg_rWgCmdOplLimPres_C = 0;
const uint16  Wg_tqIdcAirReq_A[WG_TQIDCAIRREQ_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Wg_bWgCmdBenchModHystOutput;
boolean Wg_bWgCmdOplBenchModEna;
uint32 Wg_rWgCmdOplSpBenchModMem;
uint16 Wg_rWgCmdOplSpBenchMod;
uint16 Wg_rWgCmdOplSpRawBenchMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

