/***************************************************************************
;**
;** FILE NAME      : PREDESCHG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PREDESCHG.H"
#include "PREDESCHG_L.H"
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
const boolean  PredEsChg_bDgoNFast_C = 0;
const uint8  PredEsChg_nThdAcvFct_C = 0;
const uint8  PREDESCHG_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean PredEs_bVldAgEs;
boolean PredEsChg_bAcvCalcPredEs;
boolean PredEsChg_bCalcPredEs;
boolean PredEsChg_bDirRotCk_MP;
boolean PREDESCHG_bVld;
boolean PredEsChg_bVldFastN;
uint32 PredEsChg_tiCgt_MP;
uint32 PredEsChg_tiCgtLst_MP;
uint8 PredEsChg_ctEdgeCk_MP;
uint8 PREDESCHG_u8ExtctEdgeCk;
uint8 PREDESCHG_u8ExtctEdgeCkPrev;
sint16 PredEsChg_nFast;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

