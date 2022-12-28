/***************************************************************************
;**
;** FILE NAME      : CLUPEDPOSNDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CLUPEDPOSNDIAG.H"
#include "CLUPEDPOSNDIAG_L.H"
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
const boolean  StaCtl_bMonRunFctCluP_SC = 0;
const uint8  CLUPEDPOSNDIAG_u8Inhib = 0;
const uint8  StaCtl_noDecDiagCluP_C = 0;
const uint8  StaCtl_noHiThdDiagCluP_C = 0;
const uint8  StaCtl_noIncDrvCycDiagCluP_C = 0;
const uint8  StaCtl_noIncMainDiagCluP_C = 0;
const uint8  StaCtl_noLoThdDiagCluP_C = 0;
const uint8  StaCtl_noMaxDiagCluP_C = 0;
const uint8  StaCtl_tDeltaCoMes_C = 0;
const uint8  StaCtl_tiSdlDiagCluP_SC = 0;
const sint16  StaCtl_tCoMesDiagCluP_C = 0;
const uint16  StaCtl_nEngDiagCluP_C = 0;
const uint16  StaCtl_rCluPThdCalHi_C = 0;
const uint16  StaCtl_rCluPThdCalLo_C = 0;
const uint16  StaCtl_rCluPThdChg_C = 0;
const uint16  StaCtl_spdVehDiagCluP_C = 0;
const uint16  StaCtl_tiDlyNotGc_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CLUPEDPOSNDIAG_bBasculeRSOutInv;
boolean CLUPEDPOSNDIAG_bBasculeRSOutput;
boolean CLUPEDPOSNDIAG_bCluBasculeRSOut;
boolean CLUPEDPOSNDIAG_bCondIncDecCnt;
boolean CLUPEDPOSNDIAG_bDrvCycDiagCluPrv;
boolean CLUPEDPOSNDIAG_bEnaCounter_Prev;
boolean CLUPEDPOSNDIAG_bRstCntDiaCluPrev;
boolean StaCtl_bCluPDrvCycDfct;
boolean StaCtl_bCluPMainDfct;
boolean StaCtl_bDgoFctCluP;
boolean StaCtl_bDrvCycDiagCluP;
boolean StaCtl_bMonRunFctCluP;
uint32 CLUPEDPOSNDIAG_u32CounterOutput;
uint8 CLUPEDPOSNDIAG_u8CoPTStEngPrev;
uint8 CLUPEDPOSNDIAG_u8GearRatioPrev;
uint8 CLUPEDPOSNDIAG_u8ResteCounter;
uint8 StaCtl_ctDiagCluP;
sint16 CLUPEDPOSNDIAG_s16ExtCoMes;
uint16 CLUPEDPOSNDIAG_u16CounterOutput;
uint16 CLUPEDPOSNDIAG_u16Ext_PHiFreqSwt;
uint16 CLUPEDPOSNDIAG_u16VehSpdVeh;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

