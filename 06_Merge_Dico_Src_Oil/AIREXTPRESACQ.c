/***************************************************************************
;**
;** FILE NAME      : AIREXTPRESACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "AIREXTPRESACQ.H"
#include "AIREXTPRESACQ_L.H"
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
const uint8  AIREXTPRESACQ_u8Inhib = 0;
const uint16  AirExtPresAcq_upAirMes_A[AIREXTPRESACQ_UPAIRMES_A_COLS] = {0};
const uint16  AirExtPresAcq_upPairAcq_T[AIREXTPRESACQ_UPPAIRACQ_T_COLS] = {0};
const uint16  Ext_pAirExtIni_C = 0;
const uint16  Ext_uDgoScg_pAirExtMes_C = 0;
const uint16  Ext_uDgoScp_pAirExtMes_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoScg_AirExtPresAcq;
boolean Ext_bDgoScp_AirExtPresAcq;
boolean Ext_bMonRunScg_AirExtPresAcq;
boolean Ext_bMonRunScp_AirExtPresAcq;
uint16 AirExtPresAcq_upAirMes;
uint16 Ext_pAirExtAcq;
uint16 Ext_pAirExtMesPrev;
uint16 Ext_pAirExtMesSIIf;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

