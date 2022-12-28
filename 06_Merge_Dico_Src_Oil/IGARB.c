/***************************************************************************
;**
;** FILE NAME      : IGARB.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGARB.H"
#include "IGARB_L.H"
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
const boolean  IgSys_bAcvBenchModCmpnIg_C = 0;
const boolean  IgSys_bIgBenchModEna_C = 0;
const boolean  IgSys_bKnkCorAdvEna_C = 0;
const uint8  IgArb_agIgTestCyl1_C = 0;
const uint8  IgArb_agIgTestCyl2_C = 0;
const uint8  IgArb_agIgTestCyl3_C = 0;
const uint8  IgArb_u8Inhib = 0;
const uint8  IgSys_agIgSp_pMnf_nEng_M[IGSYS_AGIGSP_PMNF_NENG_M_LNS][IGSYS_AGIGSP_PMNF_NENG_M_COLS] = {0};
const uint8  IgSys_agIgSp_posnThr_nEng_M[IGSYS_AGIGSP_POSNTHR_NENG_M_LNS][IGSYS_AGIGSP_POSNTHR_NENG_M_COLS] = {0};
const uint8  IgSys_agIgSp_tqIdcReq_nEng_M[IGSYS_AGIGSP_TQIDCREQ_NENG_M_LNS][IGSYS_AGIGSP_TQIDCREQ_NENG_M_COLS] = {0};
const uint8  IgSys_agIgSpBenchModIni_C = 0;
const uint8  IgSys_agIgSpNxtBenchModIni_C = 0;
const uint8  IgSys_agIgValSpBenchMod_C = 0;
const uint8  IgSys_noAglgSpSelBenchMod_C = 0;
const uint8  IgSys_noIESpSelBenchMod_C = 0;
const uint8  IgSys_noTiDwellSpSelBenchMod_C = 0;
const uint8  IgSys_NrCmpnCyl_C = 0;
const uint16  IgSys_agIgSp_nEngY_A[IGSYS_AGIGSP_NENGY_A_COLS] = {0};
const uint16  IgSys_agIgSp_pMnfX_A[IGSYS_AGIGSP_PMNFX_A_COLS] = {0};
const uint16  IgSys_agIgSp_posnThrX_A[IGSYS_AGIGSP_POSNTHRX_A_COLS] = {0};
const uint16  IgSys_agIgSp_tqIdcReqX_A[IGSYS_AGIGSP_TQIDCREQX_A_COLS] = {0};
const uint16  IgSys_iESp_nEngY_A[IGSYS_IESP_NENGY_A_COLS] = {0};
const uint16  IgSys_iESp_pMnfX_A[IGSYS_IESP_PMNFX_A_COLS] = {0};
const uint16  IgSys_iESp_pMnfX_nEng_M[IGSYS_IESP_PMNFX_NENG_M_LNS][IGSYS_IESP_PMNFX_NENG_M_COLS] = {0};
const uint16  IgSys_iESp_posnThr_nEng_M[IGSYS_IESP_POSNTHR_NENG_M_LNS][IGSYS_IESP_POSNTHR_NENG_M_COLS] = {0};
const uint16  IgSys_iESp_posnThrX_A[IGSYS_IESP_POSNTHRX_A_COLS] = {0};
const uint16  IgSys_iESp_tqIdcReq_nEng_M[IGSYS_IESP_TQIDCREQ_NENG_M_LNS][IGSYS_IESP_TQIDCREQ_NENG_M_COLS] = {0};
const uint16  IgSys_iESp_tqIdcReqX_A[IGSYS_IESP_TQIDCREQX_A_COLS] = {0};
const uint16  IgSys_iESpBenchModIni_C = 0;
const uint16  IgSys_iEValSpBenchMod_C = 0;
const uint16  IgSys_tiDwellSp_nEngY_A[IGSYS_TIDWELLSP_NENGY_A_COLS] = {0};
const uint16  IgSys_tiDwellSp_pMnfX_A[IGSYS_TIDWELLSP_PMNFX_A_COLS] = {0};
const uint16  IgSys_tiDwellSp_pMnfX_nEng_M[IGSYS_TIDWELLSP_PMNFX_NENG_M_LNS][IGSYS_TIDWELLSP_PMNFX_NENG_M_COLS] = {0};
const uint16  IgSys_tiDwellSp_posnThr_nEng_M[IGSYS_TIDWELLSP_POSNTHR_NENG_M_LNS][IGSYS_TIDWELLSP_POSNTHR_NENG_M_COLS] = {0};
const uint16  IgSys_tiDwellSp_posnThrX_A[IGSYS_TIDWELLSP_POSNTHRX_A_COLS] = {0};
const uint16  IgSys_tiDwellSp_tqIdcReq_nEng_M[IGSYS_TIDWELLSP_TQIDCREQ_NENG_M_LNS][IGSYS_TIDWELLSP_TQIDCREQ_NENG_M_COLS] = {0};
const uint16  IgSys_tiDwellSp_tqIdcReqX_A[IGSYS_TIDWELLSP_TQIDCREQX_A_COLS] = {0};
const uint16  IgSys_tiDwellSpBenchModIni_C = 0;
const uint16  IgSys_tiDwellValSpBenchMod_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IGARB_bAcvBenchModCmpnIgPrev;
uint8 IgSys_agIgSpBenchMod;
uint8 IgSys_agIgSpNxtBenchMod;
uint8 IgSys_agigTestCyl[IGSYS_AGIGTESTCYL_COLS];
uint8 IgSys_CtrCylCmpn;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

