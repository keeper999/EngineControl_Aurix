/***************************************************************************
;**
;** FILE NAME      : ENGSTRTSTOP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ENGSTRTSTOP.H"
#include "ENGSTRTSTOP_L.H"
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
const boolean  Clef_off_on_sans_dem_init = 0;
const boolean  Dml_cmd_cranking_manu_inh = 0;
const boolean  EngSt_bBypInjAuthCond_C = 0;
const boolean  EngSt_bInhChangeOfMind_C = 0;
const boolean  EngSt_bInhMainEngStopReq_C = 0;
const boolean  Manu_inh_retry_emf = 0;
const uint8  ENGSTRTSTOP_u8Inhib = 0;
const uint8  Fuel_pump_eng_speed_first_crank = 0;
const uint16  Date_emf_retry_thresh_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Arret_moteur_clef;
boolean Clef_off_on_sans_dem;
boolean Cranking_retry;
boolean Dml_arret_moteur;
boolean Dml_auto_injection;
boolean Dml_auto_injection_prev;
boolean Dml_cmd_cranking;
boolean EngSt_bMemrTrans_stEng;
boolean ENGSTRTSTOP_bAcvChangeOfMindPrev;
boolean ENGSTRTSTOP_bMainEngStopReqPrev;
boolean Throttle_cranking_retry;
uint8 ENGSTRTSTOP_u8CoPTStstEngPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

