/***************************************************************************
;**
;** FILE NAME      : BRKASIACT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "BRKASIACT.H"
#include "BRKASIACT_L.H"
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
const boolean  TqSys_bAcvBrkAsi_C = 0;
const boolean  TqSys_bAcvBrkAsiImdtStra_C = 0;
const uint8  BRKASIACT_u8Inhib = 0;
const uint8  TqSys_pDeltaHysBrkAsi_C = 0;
const uint8  TqSys_spdVehThdBrkAsi_C = 0;
const uint8  TqSys_tAirBrkAsiX_A[TQSYS_TAIRBRKASIX_A_COLS] = {0};
const uint8  TqSys_tOilBrkAsiY_A[TQSYS_TOILBRKASIY_A_COLS] = {0};
const uint16  TqSys_pDeltaBrkAsi_M[TQSYS_PDELTABRKASI_M_LNS][TQSYS_PDELTABRKASI_M_COLS] = {0};
const uint16  TqSys_pDeltaReqBrkAsi_T[TQSYS_PDELTAREQBRKASI_T_COLS] = {0};
const uint16  TqSys_pExtBrkAsiX_A[TQSYS_PEXTBRKASIX_A_COLS] = {0};
const uint16  TqSys_pExtThdBrkAsi_C = 0;
const uint16  TqSys_pStgThdBrkAsi_C = 0;
const uint16  TqSys_rAccPThdBrkAsi_C = 0;
const uint16  TqSys_tiBrkAsiACMax_C = 0;
const uint16  TqSys_tiBrkAsiAltMax_C = 0;
const uint16  TqSys_tiDeceAcvBrkAsi_C = 0;
const uint16  TqSys_tiEngStrtBrkAsi_M[TQSYS_TIENGSTRTBRKASI_M_LNS][TQSYS_TIENGSTRTBRKASI_M_COLS] = {0};
const uint16  TqSys_tiInhACWaitMax_C = 0;
const uint16  TqSys_tiRlsAltWaitMax_C = 0;
const uint16  TqSys_tqLossBrkAsiY_A[TQSYS_TQLOSSBRKASIY_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean BRKASIACT_bTmrOut;
boolean BRKASIACT_bTqSysbDeceAcvPrev;
boolean TqSys_bAcvBrkAsiImdtStra;
boolean TqSys_bBrkAsiAcv;
boolean TqSys_bBrkAsiPres_MP;
boolean TqSys_bBrkAsiTq_MP;
boolean TqSys_bBrkAsiVeh;
boolean TqSys_bTqACCnd;
boolean TqSys_bTqAltCnd;
uint8 TqSys_stBrkAsi;
uint16 BRKASIACT_u16Cnt;
uint16 BRKASIACT_u16TqSumLossCmp;
uint16 TqSys_tiBrkAsiACMax;
uint16 TqSys_tiBrkAsiAltMax;
uint16 TqSys_tiInhACBrkAsi;
uint16 TqSys_tiInhACWait;
uint16 TqSys_tiInhACWaitMax;
uint16 TqSys_tiRlsAltBrkAsi;
uint16 TqSys_tiRlsAltWait;
uint16 TqSys_tiRlsAltWaitMax;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

