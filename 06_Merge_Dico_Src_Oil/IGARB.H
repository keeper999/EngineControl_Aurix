/***************************************************************************
;**
;** FILE NAME      : IGARB.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGARB_H
#define IGARB_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_AGIGSP_NENGY_A_COLS              ( 24 )
#define IGSYS_AGIGSP_PMNF_NENG_M_LNS          ( 16 )
#define IGSYS_AGIGSP_PMNF_NENG_M_COLS          ( 24 )
#define IGSYS_AGIGSP_PMNFX_A_COLS              ( 16 )
#define IGSYS_AGIGSP_POSNTHR_NENG_M_LNS       ( 16 )
#define IGSYS_AGIGSP_POSNTHR_NENG_M_COLS       ( 24 )
#define IGSYS_AGIGSP_POSNTHRX_A_COLS           ( 16 )
#define IGSYS_AGIGSP_TQIDCREQ_NENG_M_LNS      ( 16 )
#define IGSYS_AGIGSP_TQIDCREQ_NENG_M_COLS      ( 24 )
#define IGSYS_AGIGSP_TQIDCREQX_A_COLS          ( 16 )
#define IGSYS_IESP_NENGY_A_COLS                ( 24 )
#define IGSYS_IESP_PMNFX_A_COLS                ( 16 )
#define IGSYS_IESP_PMNFX_NENG_M_LNS           ( 16 )
#define IGSYS_IESP_PMNFX_NENG_M_COLS           ( 24 )
#define IGSYS_IESP_POSNTHR_NENG_M_LNS         ( 16 )
#define IGSYS_IESP_POSNTHR_NENG_M_COLS         ( 24 )
#define IGSYS_IESP_POSNTHRX_A_COLS             ( 16 )
#define IGSYS_IESP_TQIDCREQ_NENG_M_LNS        ( 16 )
#define IGSYS_IESP_TQIDCREQ_NENG_M_COLS        ( 24 )
#define IGSYS_IESP_TQIDCREQX_A_COLS            ( 16 )
#define IGSYS_TIDWELLSP_NENGY_A_COLS           ( 24 )
#define IGSYS_TIDWELLSP_PMNFX_A_COLS           ( 16 )
#define IGSYS_TIDWELLSP_PMNFX_NENG_M_LNS      ( 16 )
#define IGSYS_TIDWELLSP_PMNFX_NENG_M_COLS      ( 24 )
#define IGSYS_TIDWELLSP_POSNTHR_NENG_M_LNS    ( 16 )
#define IGSYS_TIDWELLSP_POSNTHR_NENG_M_COLS    ( 24 )
#define IGSYS_TIDWELLSP_POSNTHRX_A_COLS        ( 16 )
#define IGSYS_TIDWELLSP_TQIDCREQ_NENG_M_LNS   ( 16 )
#define IGSYS_TIDWELLSP_TQIDCREQ_NENG_M_COLS   ( 24 )
#define IGSYS_TIDWELLSP_TQIDCREQX_A_COLS       ( 16 )

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

extern const boolean  IgSys_bAcvBenchModCmpnIg_C;
extern const boolean  IgSys_bIgBenchModEna_C;
extern const boolean  IgSys_bKnkCorAdvEna_C;
extern const uint8  IgArb_agIgTestCyl1_C;
extern const uint8  IgArb_agIgTestCyl2_C;
extern const uint8  IgArb_agIgTestCyl3_C;
extern const uint8  IgArb_u8Inhib;
extern const uint8  IgSys_agIgSp_pMnf_nEng_M[IGSYS_AGIGSP_PMNF_NENG_M_LNS][IGSYS_AGIGSP_PMNF_NENG_M_COLS];
extern const uint8  IgSys_agIgSp_posnThr_nEng_M[IGSYS_AGIGSP_POSNTHR_NENG_M_LNS][IGSYS_AGIGSP_POSNTHR_NENG_M_COLS];
extern const uint8  IgSys_agIgSp_tqIdcReq_nEng_M[IGSYS_AGIGSP_TQIDCREQ_NENG_M_LNS][IGSYS_AGIGSP_TQIDCREQ_NENG_M_COLS];
extern const uint8  IgSys_agIgSpBenchModIni_C;
extern const uint8  IgSys_agIgSpNxtBenchModIni_C;
extern const uint8  IgSys_agIgValSpBenchMod_C;
extern const uint8  IgSys_noAglgSpSelBenchMod_C;
extern const uint8  IgSys_noIESpSelBenchMod_C;
extern const uint8  IgSys_noTiDwellSpSelBenchMod_C;
extern const uint8  IgSys_NrCmpnCyl_C;
extern const uint16  IgSys_agIgSp_nEngY_A[IGSYS_AGIGSP_NENGY_A_COLS];
extern const uint16  IgSys_agIgSp_pMnfX_A[IGSYS_AGIGSP_PMNFX_A_COLS];
extern const uint16  IgSys_agIgSp_posnThrX_A[IGSYS_AGIGSP_POSNTHRX_A_COLS];
extern const uint16  IgSys_agIgSp_tqIdcReqX_A[IGSYS_AGIGSP_TQIDCREQX_A_COLS];
extern const uint16  IgSys_iESp_nEngY_A[IGSYS_IESP_NENGY_A_COLS];
extern const uint16  IgSys_iESp_pMnfX_A[IGSYS_IESP_PMNFX_A_COLS];
extern const uint16  IgSys_iESp_pMnfX_nEng_M[IGSYS_IESP_PMNFX_NENG_M_LNS][IGSYS_IESP_PMNFX_NENG_M_COLS];
extern const uint16  IgSys_iESp_posnThr_nEng_M[IGSYS_IESP_POSNTHR_NENG_M_LNS][IGSYS_IESP_POSNTHR_NENG_M_COLS];
extern const uint16  IgSys_iESp_posnThrX_A[IGSYS_IESP_POSNTHRX_A_COLS];
extern const uint16  IgSys_iESp_tqIdcReq_nEng_M[IGSYS_IESP_TQIDCREQ_NENG_M_LNS][IGSYS_IESP_TQIDCREQ_NENG_M_COLS];
extern const uint16  IgSys_iESp_tqIdcReqX_A[IGSYS_IESP_TQIDCREQX_A_COLS];
extern const uint16  IgSys_iESpBenchModIni_C;
extern const uint16  IgSys_iEValSpBenchMod_C;
extern const uint16  IgSys_tiDwellSp_nEngY_A[IGSYS_TIDWELLSP_NENGY_A_COLS];
extern const uint16  IgSys_tiDwellSp_pMnfX_A[IGSYS_TIDWELLSP_PMNFX_A_COLS];
extern const uint16  IgSys_tiDwellSp_pMnfX_nEng_M[IGSYS_TIDWELLSP_PMNFX_NENG_M_LNS][IGSYS_TIDWELLSP_PMNFX_NENG_M_COLS];
extern const uint16  IgSys_tiDwellSp_posnThr_nEng_M[IGSYS_TIDWELLSP_POSNTHR_NENG_M_LNS][IGSYS_TIDWELLSP_POSNTHR_NENG_M_COLS];
extern const uint16  IgSys_tiDwellSp_posnThrX_A[IGSYS_TIDWELLSP_POSNTHRX_A_COLS];
extern const uint16  IgSys_tiDwellSp_tqIdcReq_nEng_M[IGSYS_TIDWELLSP_TQIDCREQ_NENG_M_LNS][IGSYS_TIDWELLSP_TQIDCREQ_NENG_M_COLS];
extern const uint16  IgSys_tiDwellSp_tqIdcReqX_A[IGSYS_TIDWELLSP_TQIDCREQX_A_COLS];
extern const uint16  IgSys_tiDwellSpBenchModIni_C;
extern const uint16  IgSys_tiDwellValSpBenchMod_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgSys_EveBDC_IgArb(void);
void IgSys_EveRst_IgArb(void);
void IgSys_SdlSlow_IgArb(void);


#endif /* IGARB_H */

/*-------------------------------- end of file -------------------------------*/
