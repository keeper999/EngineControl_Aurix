/***************************************************************************
;**
;** FILE NAME      : OILDSP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "OILDSP.H"
#include "OILDSP_L.H"
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
const uint32  OilDsp_mFuInOilEstimInit_C = 0;
const uint8  OilDsp_facAfs_C = 0;
const uint8  OilDsp_rCrcPresInPresBlbyCnd_T[OILDSP_RCRCPRESINPRESBLBYCND_T_COLS] = {0};
const uint8  OilDsp_rFuDspInBlbyCnd_T[OILDSP_RFUDSPINBLBYCND_T_COLS] = {0};
const uint8  OilDsp_rFuDspInj_C = 0;
const uint8  OilDsp_rFuDspInjThd_C = 0;
const uint8  OilDsp_rFuMassInOil_T[OILDSP_RFUMASSINOIL_T_COLS] = {0};
const uint8  OilDsp_rMassFlowInBlbyCnd_M[OILDSP_RMASSFLOWINBLBYCND_M_LNS][OILDSP_RMASSFLOWINBLBYCND_M_COLS] = {0};
const uint8  OilDsp_tCoMes_A[OILDSP_TCOMES_A_COLS] = {0};
const uint8  OILDSP_u8Inhib = 0;
const sint16  OilDsp_tAbsorbPhaMax_C = 0;
const sint16  OilDsp_tAbsorbPhaMaxThd_C = 0;
const sint16  OilDsp_tDspPhaMin_C = 0;
const sint16  OilDsp_tDspPhaMinThd_C = 0;
const uint16  OilDsp_nEng_A[OILDSP_NENG_A_COLS] = {0};
const uint16  OilDsp_rAirLd_A[OILDSP_RAIRLD_A_COLS] = {0};
const uint16  OilDsp_tOilMes_A[OILDSP_TOILMES_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean OilDsp_bDgoIdcBlbyCnd;
boolean OilDsp_bMonRunIdcBlbyCnd;
boolean OilSys_EnaOilAbs_TCdn;
boolean OilSys_EnaOilDsp_TCdn;
uint32 OilDsp_mFuInOilEstimPrev;
uint8 OilDsp_rCrcPresInPresBlbyCnd;
uint8 OilDsp_rFuDspInBlbyCnd;
uint8 OilDsp_rFuMassInOil;
uint8 OilDsp_rMassFlowInBlbyCnd;
uint16 OilDsp_mFuDspBlbyCndEstim;
uint16 OilDsp_mFuInjBurn;
uint16 OilDsp_mFuResiAfterCmb;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

