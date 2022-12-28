/***************************************************************************
;**
;** FILE NAME      : AIREXTPRESACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIREXTPRESACQ_L_H
#define AIREXTPRESACQ_L_H

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

extern const uint8  AIREXTPRESACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoScg_AirExtPresAcq;
extern boolean Ext_bDgoScp_AirExtPresAcq;
extern boolean Ext_bMonRunScg_AirExtPresAcq;
extern boolean Ext_bMonRunScp_AirExtPresAcq;
extern uint16 Ext_pAirExtMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AIREXTPRESACQ_vidAcquisition(void);
void AIREXTPRESACQ_vidAtmPresDiag(void);
void AIREXTPRESACQ_vidAtmPreTreat(void);
void AIREXTPRESACQ_vidCalc(void);
void AIREXTPRESACQ_vidElectDiag(void);
void AIREXTPRESACQ_vidInit(void);
void AIREXTPRESACQ_vidInterfacage(void);


#endif /* AIREXTPRESACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
