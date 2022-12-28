/***************************************************************************
;**
;** FILE NAME      : INMNFPRESACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INMNFPRESACQ_L_H
#define INMNFPRESACQ_L_H

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

extern const uint8  INMNFPRESACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoScg_pDsThrMes;
extern boolean Ext_bDgoScp_pDsThrMes;
extern boolean Ext_bMonRunScg_pDsThrMes;
extern boolean Ext_bMonRunScp_pDsThrMes;
extern uint32 INMNFPRESACQ_u32upDsThrFiltMEM;
extern uint16 Acq_pDsThrPresDftv_SyncEng;
extern uint16 AirPres_uDsThrMesAvr;
extern uint16 AirPres_uDsThrPresSenVoltAvrPre1;
extern uint16 AirPres_uDsThrPresSenVoltAvrPre2;
extern uint16 AirPres_uDsThrPresSenVoltAvrPre3;
extern uint16 AirPres_upDsThrFilt;
extern uint16 Ext_pDsThr;
extern uint16 Ext_upDsThrMes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INMNFPRESACQ_vidArbPressManifld(void);
void INMNFPRESACQ_vidDiagPressManifld(void);
void INMNFPRESACQ_vidFormPressManifld(void);
void INMNFPRESACQ_vidInit(void);
void INMNFPRESACQ_vidPresElectricDiag(void);


#endif /* INMNFPRESACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
