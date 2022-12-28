/***************************************************************************
;**
;** FILE NAME      : TQLIMSFTY.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQLIMSFTY.H"
#include "TQLIMSFTY_L.H"
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
const uint8  EngLim_tqIdcSyst_Gear_A[ENGLIM_TQIDCSYST_GEAR_A_COLS] = {0};
const uint8  TQLIMSFTY_u8Inhib = 0;
const sint16  EngLim_tqGrdSftyDec_C = 0;
const uint16  EngLim_tqIdcSyst_M[ENGLIM_TQIDCSYST_M_LNS][ENGLIM_TQIDCSYST_M_COLS] = {0};
const uint16  EngLim_tqIdcSyst_nEng_A[ENGLIM_TQIDCSYST_NENG_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean EngLim_bAcvTqLim_prev;
boolean EngLim_bRiseEdgeTqLim;
boolean EngLim_bTqLimTran;
sint16 EngLim_tqSftystat;
sint16 TQLIMSFTY_s16SlewRateOutput;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

