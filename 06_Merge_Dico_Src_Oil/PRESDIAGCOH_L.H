/***************************************************************************
;**
;** FILE NAME      : PRESDIAGCOH_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PRESDIAGCOH_L_H
#define PRESDIAGCOH_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  PRESDIAGCOH_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DgSen_bAcvCohDiagPresSen;
extern boolean DgSen_bAirPrssExtSdwn;
extern boolean DgSen_bAirPrssExtSup;
extern boolean DgSen_bDgoAirPrssExtSdwn;
extern boolean DgSen_bDgoAirPrssExtSup;
extern boolean DgSen_bDgoOilPrssSdwnORng;
extern boolean DgSen_bDgoOilPrssSupORng;
extern boolean DgSen_bDgoUsThrPrssSdwn;
extern boolean DgSen_bDgoUsThrPrssSup;
extern boolean DgSen_bMonRunAirPrssExtSdwn;
extern boolean DgSen_bMonRunAirPrssExtSup;
extern boolean DgSen_bMonRunOilPrssSdwnORng;
extern boolean DgSen_bMonRunOilPrssSupORng;
extern boolean DgSen_bMonRunUsThrPrssSdwn;
extern boolean DgSen_bMonRunUsThrPrssSup;
extern boolean DgSen_bOilPrssSdwnORng;
extern boolean DgSen_bOilPrssSupORng;
extern boolean DgSen_bUsThrPrssSdwn;
extern boolean DgSen_bUsThrPrssSup;
extern boolean Oil_bInhDiagSecondKOn;
extern boolean PRESDIAGCOH_bAtmTimer1Out;
extern boolean PRESDIAGCOH_bAtmTimerOut;
extern boolean PRESDIAGCOH_bOilTimer1Out;
extern boolean PRESDIAGCOH_bOilTimerOut;
extern boolean PRESDIAGCOH_bUpstrmTimer1Out;
extern boolean PRESDIAGCOH_bUpstrmTimerOut;
extern uint8 Oil_ctKeyOn;
extern uint8 Oil_ctKeyOn_Prev;
extern uint8 PRESDIAGCOH_u8Oil_ctKeyOn;
extern sint16 DgSen_pDelta_pAirExt_pOil;
extern sint16 DgSen_pDelta_pAirExt_pUsThrFil;
extern sint16 DgSen_pDelta_pOil_pUsThrFil;
extern uint16 PRESDIAGCOH_u16AtmTimer1Count;
extern uint16 PRESDIAGCOH_u16AtmTimerCount;
extern uint16 PRESDIAGCOH_u16OilTimer1Count;
extern uint16 PRESDIAGCOH_u16OilTimerCount;
extern uint16 PRESDIAGCOH_u16UpstrmTimer1Count;
extern uint16 PRESDIAGCOH_u16UpstrmTimerCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PRESDIAGCOH_vidAtmospherPSDrift(void);
void PRESDIAGCOH_vidCalcPresureDrifts(void);
void PRESDIAGCOH_vidCohDiagEnaCond(void);
void PRESDIAGCOH_vidCoherenciesDiag(void);
void PRESDIAGCOH_vidCounterKeyOn(void);
void PRESDIAGCOH_vidInhDiagSecKeyOn(void);
void PRESDIAGCOH_vidInitialization(void);
void PRESDIAGCOH_vidInitOutput(void);
void PRESDIAGCOH_vidOilPSDrift(void);
void PRESDIAGCOH_vidPressureDiagnosis(void);
void PRESDIAGCOH_vidUpstrmThrPSDrift(void);


#endif /* PRESDIAGCOH_L_H */

/*-------------------------------- end of file -------------------------------*/
