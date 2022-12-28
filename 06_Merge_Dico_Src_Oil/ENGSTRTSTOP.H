/***************************************************************************
;**
;** FILE NAME      : ENGSTRTSTOP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGSTRTSTOP_H
#define ENGSTRTSTOP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Autonomous_Restart                8
#define Autonomous_Start                  4
#define Coupe_cale                        1
#define Driven_Restart                    7
#define Driven_Start                      3
#define Engine_Running                    5
#define Preparation                       2
#define Stop                              6

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

extern const boolean  Clef_off_on_sans_dem_init;
extern const boolean  Dml_cmd_cranking_manu_inh;
extern const boolean  EngSt_bBypInjAuthCond_C;
extern const boolean  EngSt_bInhChangeOfMind_C;
extern const boolean  EngSt_bInhMainEngStopReq_C;
extern const boolean  Manu_inh_retry_emf;
extern const uint8  Fuel_pump_eng_speed_first_crank;
extern const uint16  Date_emf_retry_thresh_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Arret_moteur_clef;
extern boolean Clef_off_on_sans_dem;
extern boolean Cranking_retry;
extern boolean Dml_arret_moteur;
extern boolean Dml_auto_injection;
extern boolean Dml_cmd_cranking;
extern boolean Throttle_cranking_retry;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void EngSt_EveCkOn_EngStrtStop(void);
void EngSt_EveCkSnOn_EngStrtStop(void);
void EngSt_EveKOf_EngStrtStop(void);
void EngSt_EveKOn_EngStrtStop(void);
void EngSt_EveRst_EngStrtStop(void);
void EngSt_EveRTSt_EngStrtStop(void);
void EngSt_EveRxn552_EngStrtStop(void);
void EngSt_EveStTR_EngStrtStop(void);
void EngSt_SdlFast_EngStrtStop(void);
void EngSt_SdlSlow_EngStrtStop(void);


#endif /* ENGSTRTSTOP_H */

/*-------------------------------- end of file -------------------------------*/
