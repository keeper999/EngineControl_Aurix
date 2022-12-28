/***************************************************************************
;**
;** FILE NAME      : SPGPRESACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SPGPRESACQ.H"
#include "SPGPRESACQ_L.H"
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
const uint8  AirPres_rFilGainSpgPres_nEng_T[AIRPRES_RFILGAINSPGPRES_NENG_T_COLS] = {0};
const uint8  SpgPresAcq_u8Inhib = 0;
const uint16  AirPres_pSpgDftv_nEng_T[AIRPRES_PSPGDFTV_NENG_T_COLS] = {0};
const uint16  AirPres_pSpgPresAcq_nEng_A[AIRPRES_PSPGPRESACQ_NENG_A_COLS] = {0};
const uint16  AirPres_pSpgPresSenVolt_T[AIRPRES_PSPGPRESSENVOLT_T_COLS] = {0};
const uint16  AirPres_pUsThrMes_nEng_A[AIRPRES_PUSTHRMES_NENG_A_COLS] = {0};
const uint16  AirPres_uDgoScg_pSpgPres_C = 0;
const uint16  AirPres_uDgoScp_pSpgPres_C = 0;
const uint16  AirPres_uSpgPresSenVolt_A[AIRPRES_USPGPRESSENVOLT_A_COLS] = {0};
const uint16  Ext_pUsThrIni_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoScg_pSpgPres;
boolean Ext_bDgoScp_pSpgPres;
boolean Ext_bMonRunScg_pSpgPres;
boolean Ext_bMonRunScp_pSpgPres;
uint32 SPGPRESACQ_AcqSpgPressureMem;
uint16 Acq_pSpgPresDftv_SyncEng;
uint16 Acq_spg_pres_measured;
uint16 Acq_spg_pressure;
uint16 Acq_spg_prs_uavn0;
uint16 AirPres_uSpgPresSenVolt;
uint16 AirPres_uSpgPresSenVoltAvr;
uint16 AirPres_uSpgPresSenVoltAvrPrev1;
uint16 AirPres_uSpgPresSenVoltAvrPrev2;
uint16 AirPres_uSpgPresSenVoltAvrPrev3;
uint16 AirPres_uSpgPresSenVoltFilt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

