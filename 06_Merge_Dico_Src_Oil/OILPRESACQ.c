/***************************************************************************
;**
;** FILE NAME      : OILPRESACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "OILPRESACQ.H"
#include "OILPRESACQ_L.H"
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
const boolean  Hal_dio_inverse_signal_oil_pres = 0;
const boolean  Oil_pres_alertTyp_C = 0;
const uint8  Ext_noOilPresHiThd_C = 0;
const uint8  Ext_noOilPresLoThd_C = 0;
const uint8  OILPRESACQ_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bOilPresDetec;
boolean Ext_bRawOilPresDetec;
boolean Oil_pres_alert_fil;
boolean Oil_pres_alertDetec;
boolean OILPRESACQ_bRawSig;
uint8 OILPRESACQ_u8AntiBounceCounter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

