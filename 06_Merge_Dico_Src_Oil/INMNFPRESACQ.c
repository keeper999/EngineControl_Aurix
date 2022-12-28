/***************************************************************************
;**
;** FILE NAME      : INMNFPRESACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INMNFPRESACQ.H"
#include "INMNFPRESACQ_L.H"
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
const uint8  AirPres_rFilGainDsThrPres_nEng_T[AIRPRES_RFILGAINDSTHRPRES_NENG_T_COLS] = {0};
const uint8  INMNFPRESACQ_u8Inhib = 0;
const uint16  Acq_pDsThrPresDftv_NoSync_C = 0;
const uint16  AirPres_pDsThrDftv_nEng_T[AIRPRES_PDSTHRDFTV_NENG_T_COLS] = {0};
const uint16  AirPres_pDsThrMes_nEng_A[AIRPRES_PDSTHRMES_NENG_A_COLS] = {0};
const uint16  AirPres_pDsThrPresAcq_nEng_A[AIRPRES_PDSTHRPRESACQ_NENG_A_COLS] = {0};
const uint16  AirPres_pDsThrPresSenVolt_T[AIRPRES_PDSTHRPRESSENVOLT_T_COLS] = {0};
const uint16  AirPres_uDgoScg_pDsThrMes_C = 0;
const uint16  AirPres_uDgoScp_pDsThrMes_C = 0;
const uint16  AirPres_uDsThrPresSenVolt_A[AIRPRES_UDSTHRPRESSENVOLT_A_COLS] = {0};
const uint16  Ext_pDsThrIni_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoScg_pDsThrMes;
boolean Ext_bDgoScp_pDsThrMes;
boolean Ext_bMonRunScg_pDsThrMes;
boolean Ext_bMonRunScp_pDsThrMes;
uint32 INMNFPRESACQ_u32upDsThrFiltMEM;
uint8 Ext_pDsThrMesWRV;
uint16 Acq_pDsThrPresDftv_SyncEng;
uint16 AirPres_uDsThrMesAvr;
uint16 AirPres_uDsThrPresSenVoltAvrPre1;
uint16 AirPres_uDsThrPresSenVoltAvrPre2;
uint16 AirPres_uDsThrPresSenVoltAvrPre3;
uint16 AirPres_upDsThrFilt;
uint16 Ext_pDsThr;
uint16 Ext_upDsThrMes;
uint16 Io_map_manifold_press_measured;
uint16 Pression_air_result_ad_conv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

