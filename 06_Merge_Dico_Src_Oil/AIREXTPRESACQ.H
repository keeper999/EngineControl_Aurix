/***************************************************************************
;**
;** FILE NAME      : AIREXTPRESACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIREXTPRESACQ_H
#define AIREXTPRESACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIREXTPRESACQ_UPAIRMES_A_COLS          ( 2 )
#define AIREXTPRESACQ_UPPAIRACQ_T_COLS         ( 2 )

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

extern const uint16  AirExtPresAcq_upAirMes_A[AIREXTPRESACQ_UPAIRMES_A_COLS];
extern const uint16  AirExtPresAcq_upPairAcq_T[AIREXTPRESACQ_UPPAIRACQ_T_COLS];
extern const uint16  Ext_pAirExtIni_C;
extern const uint16  Ext_uDgoScg_pAirExtMes_C;
extern const uint16  Ext_uDgoScp_pAirExtMes_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 AirExtPresAcq_upAirMes;
extern uint16 Ext_pAirExtAcq;
extern uint16 Ext_pAirExtMesSIIf;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirPres_EveRst_AirExtPresAcq(void);
void AirPres_SdlFast_AirExtPresAcq(void);
void AirPres_SdlMid_AirExtPresAcq(void);
void AirPres_SdlSlow_AirExtPresAcq(void);


#endif /* AIREXTPRESACQ_H */

/*-------------------------------- end of file -------------------------------*/
