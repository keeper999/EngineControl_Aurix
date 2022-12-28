/***************************************************************************
;**
;** FILE NAME      : SPGPRESSP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SPGPRESSP.H"
#include "SPGPRESSP_L.H"
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
const boolean  SpgPresSp_bBenchModEna_C = 0;
const uint8  SpgPresSp_u8Inhib = 0;
const uint16  AirPres_pSpgSp_nEng_A[AIRPRES_PSPGSP_NENG_A_COLS] = {0};
const uint16  AirPres_pSpgSp_tqIdcAir_A[AIRPRES_PSPGSP_TQIDCAIR_A_COLS] = {0};
const uint16  AirPres_pSpgSp_tqIdcAir_nEng_M[AIRPRES_PSPGSP_TQIDCAIR_NENG_M_LNS][AIRPRES_PSPGSP_TQIDCAIR_NENG_M_COLS] = {0};
const uint16  SpgPresSp_Max_pres_slew_C = 0;
const uint16  SpgPresSp_Min_pres_slew_C = 0;
const uint16  SpgPresSp_pBenchModIniSp_C = 0;
const uint16  SpgPresSp_pDftValSp_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean SpgPresSp_bBenchModEna;
uint16 AirPres_pSpgPresRawSp;
uint16 AirPres_pSpgPresSp;
uint16 SpgPresSp_pBenchModSp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

