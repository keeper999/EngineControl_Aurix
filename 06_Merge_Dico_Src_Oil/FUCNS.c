/***************************************************************************
;**
;** FILE NAME      : FUCNS.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FUCNS.H"
#include "FUCNS_L.H"
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
const boolean  FuCns_bAcvFuCnsTyp_C = 0;
const boolean  FuCns_bRstFuCnsTot_C = 0;
const uint8  Conso_carburant_filtre_gain = 0;
const uint8  Conso_carburant_inst_filtre_gain = 0;
const uint8  FUCNS_u8Inhib = 0;
const uint16  Ext_pDsThrMesSI_A[EXT_PDSTHRMESSI_A_COLS] = {0};
const uint16  FuCns_mFuReqWoutPurgeOxC_M[FUCNS_MFUREQWOUTPURGEOXC_M_LNS][FUCNS_MFUREQWOUTPURGEOXC_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean FuCns_bFuCnsTyp;
uint32 FuCns_mFuInjTot;
uint32 FuCns_mFuInjTotTemp;
uint32 FUCNS_u32InstantUsedFuelMem;
uint32 FUCNS_u32InstantUsedFuelMem1;
uint32 FUCNS_u32UsedFuelPerHourMem;
uint8 Conso_carburant_can_InjDir;
uint8 Conso_carburant_can_InjInd;
uint8 Conso_Inst_InjDir;
uint8 Conso_Inst_InjInd;
uint8 Consommation_carburant_inst;
uint8 FuCns_volFuCnsTot;
uint16 Conso_carb_entre_trame_InjDir;
uint16 Conso_carburant_entre_trame;
uint16 Consommation_carburant_horaire;
uint16 FuCns_mFuWoutPurgeOxC;
uint16 FuCns_mFuWoutPurgeOxCTemp;
uint16 Fuel_used_between_frame;
uint16 Fuel_used_between_frame_InjDir;
uint16 Fuel_used_not_counted;
uint16 Fuel_used_not_counted_InjDir;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

