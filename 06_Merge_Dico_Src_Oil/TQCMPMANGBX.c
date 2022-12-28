/***************************************************************************
;**
;** FILE NAME      : TQCMPMANGBX.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQCMPMANGBX.H"
#include "TQCMPMANGBX_L.H"
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
const boolean  TqCmp_bInhTqManGBxLoss_C = 0;
const uint8  TqCmp_facTOilFilManGBx_C = 0;
const uint8  TqCmp_tAirManGBxLossX_A[TQCMP_TAIRMANGBXLOSSX_A_COLS] = {0};
const uint8  TqCmp_tiEngRunCluManGBxY_A[TQCMP_TIENGRUNCLUMANGBXY_A_COLS] = {0};
const uint8  TqCmp_tManGBxLoss_M[TQCMP_TMANGBXLOSS_M_LNS][TQCMP_TMANGBXLOSS_M_COLS] = {0};
const uint8  TqCmp_tManGBxX_A[TQCMP_TMANGBXX_A_COLS] = {0};
const uint8  TqCmp_tOfsOilMinManGBx_C = 0;
const uint8  TQCMPMANGBX_u8Inhib = 0;
const uint16  TqCmp_tiEngStop_C = 0;
const uint16  TqCmp_tiStopManGBxY_A[TQCMP_TISTOPMANGBXY_A_COLS] = {0};
const uint16  TqCmp_tqManGBxLoss_M[TQCMP_TQMANGBXLOSS_M_LNS][TQCMP_TQMANGBXLOSS_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TqDem_bManGBxLossClc;
uint32 TQCMPMANGBX_u32EOM_tiEngStopMem;
sint16 TqCmp_tManGBx_MP;
sint16 TqCmp_tOilFil;
uint16 TqCmp_tiEngRunClu;
uint16 TQCMPMANGBX_u16Eng_nCkFilPrev;
sint32 TQCMPMANGBX_s32TqCmptOilFilMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

