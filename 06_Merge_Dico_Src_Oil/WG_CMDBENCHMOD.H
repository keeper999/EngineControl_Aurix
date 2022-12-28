/***************************************************************************
;**
;** FILE NAME      : WG_CMDBENCHMOD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WG_CMDBENCHMOD_H
#define WG_CMDBENCHMOD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define WG_NENG_A_COLS                         ( 16 )
#define WG_NENGX_PWGCMDOPLCUTOFFMAX_T_COLS     ( 16 )
#define WG_PBOOST_A_COLS                       ( 16 )
#define WG_PINMNF_A_COLS                       ( 16 )
#define WG_RWGCMDOPL_TQIDCAIRX_NENGY_M_LNS    ( 16 )
#define WG_RWGCMDOPL_TQIDCAIRX_NENGY_M_COLS    ( 16 )
#define WG_RWGCMDOPL_TQIDCAIRX_PBOOSTY_M_LNS  ( 16 )
#define WG_RWGCMDOPL_TQIDCAIRX_PBOOSTY_M_COLS  ( 16 )
#define WG_RWGCMDOPL_TQIDCAIRX_PINMNFY_M_LNS  ( 16 )
#define WG_RWGCMDOPL_TQIDCAIRX_PINMNFY_M_COLS  ( 16 )
#define WG_TQIDCAIRREQ_A_COLS                  ( 16 )

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

extern const boolean  Wg_bWgCmdOplBenchModEna_C;
extern const boolean  Wg_bWgCmdOplCutOffSelPres_C;
extern const uint8  Wg_noWgCmdOplBenchModSel_C;
extern const uint8  Wg_rWgCmdOplBenchModFilGain_C;
extern const uint16  Wg_nEng_A[WG_NENG_A_COLS];
extern const uint16  Wg_nEngX_pWgCmdOplCutOffMax_T[WG_NENGX_PWGCMDOPLCUTOFFMAX_T_COLS];
extern const uint16  Wg_pBoost_A[WG_PBOOST_A_COLS];
extern const uint16  Wg_pInMnf_A[WG_PINMNF_A_COLS];
extern const uint16  Wg_pWgCmdOplCutOffMaxHys_C;
extern const uint16  Wg_rWgCmdOpl_tqIdcAirX_nEngY_M[WG_RWGCMDOPL_TQIDCAIRX_NENGY_M_LNS][WG_RWGCMDOPL_TQIDCAIRX_NENGY_M_COLS];
extern const uint16  Wg_rWgCmdOpl_tqIdcAirX_pBoostY_M[WG_RWGCMDOPL_TQIDCAIRX_PBOOSTY_M_LNS][WG_RWGCMDOPL_TQIDCAIRX_PBOOSTY_M_COLS];
extern const uint16  Wg_rWgCmdOpl_tqIdcAirX_pInMnfY_M[WG_RWGCMDOPL_TQIDCAIRX_PINMNFY_M_LNS][WG_RWGCMDOPL_TQIDCAIRX_PINMNFY_M_COLS];
extern const uint16  Wg_rWgCmdOplBenchModIniSp_C;
extern const uint16  Wg_rWgCmdOplLimPres_C;
extern const uint16  Wg_tqIdcAirReq_A[WG_TQIDCAIRREQ_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Wg_bWgCmdOplBenchModEna;
extern uint16 Wg_rWgCmdOplSpBenchMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Wg_EveRst_WgCmdOplBenchMod(void);
void Wg_SdlMid_WgCmdOplBenchMod(void);


#endif /* WG_CMDBENCHMOD_H */

/*-------------------------------- end of file -------------------------------*/
