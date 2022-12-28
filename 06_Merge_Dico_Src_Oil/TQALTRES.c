/***************************************************************************
;**
;** FILE NAME      : TQALTRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQALTRES.H"
#include "TQALTRES_L.H"
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
const uint8  TQALTRES_u8Inhib = 0;
const uint8  TqRes_facFilDuCyAltRes_C = 0;
const uint8  TqRes_facFilIAltRes_C = 0;
const uint8  TqRes_iAltFil_A[TQRES_IALTFIL_A_COLS] = {0};
const uint8  TqRes_idxAltGapClas2_C = 0;
const uint8  TqRes_idxAltGapClas3_C = 0;
const uint8  TqRes_idxAltStdClas_T[TQRES_IDXALTSTDCLAS_T_COLS] = {0};
const uint8  TqRes_rAltFil_A[TQRES_RALTFIL_A_COLS] = {0};
const uint8  TqRes_tiCdnNEngAltRes_C = 0;
const sint16  TqRes_tqDecMaxAltRes_C = 0;
const uint16  TqRes_nEngOfsLoAltRes_C = 0;
const uint16  TqRes_nEngThrHiAltRes_C = 0;
const uint16  TqRes_tqAltResGapClas1_T[TQRES_TQALTRESGAPCLAS1_T_COLS] = {0};
const uint16  TqRes_tqAltResGapClas2_T[TQRES_TQALTRESGAPCLAS2_T_COLS] = {0};
const uint16  TqRes_tqAltResGapClas3_T[TQRES_TQALTRESGAPCLAS3_T_COLS] = {0};
const uint16  TqRes_tqAltResStdClas1_T[TQRES_TQALTRESSTDCLAS1_T_COLS] = {0};
const uint16  TqRes_tqAltResStdClas2_T[TQRES_TQALTRESSTDCLAS2_T_COLS] = {0};
const uint16  TqRes_tqAltResStdClas3_T[TQRES_TQALTRESSTDCLAS3_T_COLS] = {0};
const uint16  TqRes_tqDftValAltRes_C = 0;
const uint16  TqRes_tqIncMaxAltRes_C = 0;
const uint16  TqRes_tqUHAltRes_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TQALTRES_bCdnAltRes_prev;
boolean TqRes_bCdnAltRes;
boolean TqRes_bCdnNEngAltRes_MP;
uint32 TQALTRES_u32FiltredCoefFilCCPMem;
uint32 TQALTRES_u32FiltredCoefFilGapMem;
uint8 TqRes_iAltFil_MP;
uint8 TqRes_rAltFil_MP;
uint16 TQALTRES_u16tiAltCpt;
uint16 TqRes_tqAltRes;
uint16 TqRes_tqAltResGap;
uint16 TqRes_tqAltResSat_MP;
uint16 TqRes_tqAltResStd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

