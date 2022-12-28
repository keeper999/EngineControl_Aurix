/***************************************************************************
;**
;** FILE NAME      : PRESDIAGCOH.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PRESDIAGCOH.H"
#include "PRESDIAGCOH_L.H"
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
const uint8  PRESDIAGCOH_u8Inhib = 0;
const uint16  DgSen_pDifMaxAirExtOilThd_C = 0;
const uint16  DgSen_pDifMaxAirExtUsThrThd_C = 0;
const uint16  DgSen_pDifMaxOilAirExtThd_C = 0;
const uint16  DgSen_pDifMaxOilUsThrThd_C = 0;
const uint16  DgSen_pDifMaxUsThrAirExtThd_C = 0;
const uint16  DgSen_pDifMaxUsThrOilThd_C = 0;
const uint16  DgSen_tiEngModStpThd_T[DGSEN_TIENGMODSTPTHD_T_COLS] = {0};
const uint16  DgSen_tOil_A[DGSEN_TOIL_A_COLS] = {0};
const uint16  Oil_tiDlyDriftNeg_pAirExtThd_C = 0;
const uint16  Oil_tiDlyDriftNeg_pOilThd_C = 0;
const uint16  Oil_tiDlyDriftNeg_pUsThrFilThd_C = 0;
const uint16  Oil_tiDlyDriftPos_pAirExtThd_C = 0;
const uint16  Oil_tiDlyDriftPos_pOilThd_C = 0;
const uint16  Oil_tiDlyDriftPos_pUsThrFilThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean DgSen_bAcvCohDiagPresSen;
boolean DgSen_bAirPrssExtSdwn;
boolean DgSen_bAirPrssExtSup;
boolean DgSen_bDgoAirPrssExtSdwn;
boolean DgSen_bDgoAirPrssExtSup;
boolean DgSen_bDgoOilPrssSdwnORng;
boolean DgSen_bDgoOilPrssSupORng;
boolean DgSen_bDgoUsThrPrssSdwn;
boolean DgSen_bDgoUsThrPrssSup;
boolean DgSen_bMonRunAirPrssExtSdwn;
boolean DgSen_bMonRunAirPrssExtSup;
boolean DgSen_bMonRunOilPrssSdwnORng;
boolean DgSen_bMonRunOilPrssSupORng;
boolean DgSen_bMonRunUsThrPrssSdwn;
boolean DgSen_bMonRunUsThrPrssSup;
boolean DgSen_bOilPrssSdwnORng;
boolean DgSen_bOilPrssSupORng;
boolean DgSen_bUsThrPrssSdwn;
boolean DgSen_bUsThrPrssSup;
boolean Oil_bInhDiagSecondKOn;
boolean PRESDIAGCOH_bAtmTimer1Out;
boolean PRESDIAGCOH_bAtmTimerOut;
boolean PRESDIAGCOH_bOilTimer1Out;
boolean PRESDIAGCOH_bOilTimerOut;
boolean PRESDIAGCOH_bUpstrmTimer1Out;
boolean PRESDIAGCOH_bUpstrmTimerOut;
uint8 Oil_ctKeyOn;
uint8 Oil_ctKeyOn_Prev;
uint8 PRESDIAGCOH_u8Oil_ctKeyOn;
sint16 DgSen_pDelta_pAirExt_pOil;
sint16 DgSen_pDelta_pAirExt_pUsThrFil;
sint16 DgSen_pDelta_pOil_pUsThrFil;
uint16 PRESDIAGCOH_u16AtmTimer1Count;
uint16 PRESDIAGCOH_u16AtmTimerCount;
uint16 PRESDIAGCOH_u16OilTimer1Count;
uint16 PRESDIAGCOH_u16OilTimerCount;
uint16 PRESDIAGCOH_u16UpstrmTimer1Count;
uint16 PRESDIAGCOH_u16UpstrmTimerCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

