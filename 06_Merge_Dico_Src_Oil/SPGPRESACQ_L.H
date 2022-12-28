/***************************************************************************
;**
;** FILE NAME      : SPGPRESACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPGPRESACQ_L_H
#define SPGPRESACQ_L_H

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

extern const uint8  SpgPresAcq_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoScg_pSpgPres;
extern boolean Ext_bDgoScp_pSpgPres;
extern boolean Ext_bMonRunScg_pSpgPres;
extern boolean Ext_bMonRunScp_pSpgPres;
extern uint32 SPGPRESACQ_AcqSpgPressureMem;
extern uint16 Acq_pSpgPresDftv_SyncEng;
extern uint16 Acq_spg_pressure;
extern uint16 AirPres_uSpgPresSenVolt;
extern uint16 AirPres_uSpgPresSenVoltAvr;
extern uint16 AirPres_uSpgPresSenVoltAvrPrev1;
extern uint16 AirPres_uSpgPresSenVoltAvrPrev2;
extern uint16 AirPres_uSpgPresSenVoltAvrPrev3;
extern uint16 AirPres_uSpgPresSenVoltFilt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SpgPresAcq_vidBoost_Pressure_Acq(void);
void SpgPresAcq_vidBoost_Pressure_Arb(void);
void SpgPresAcq_vidBoostPressureDiag(void);
void SpgPresAcq_vidBoostPressureForm(void);
void SpgPresAcq_vidInitOutput(void);
void SpgPresAcq_vidPressElectDiag(void);


#endif /* SPGPRESACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
